/**
  ******************************************************************************
  * @file    app.c
  * @author  MDG Application Team
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */

/*TODO: DECLARE MODELS 
//LL_ATON_DECLARE_NAMED_NN_INSTANCE_AND_INTERFACE(yolo_detector);
//static roi_t rois[YOLO_MAX_NB];
//LL_ATON_DECLARE_NAMED_NN_INSTANCE_AND_INTERFACE(face_landmark);
//static ld_point_t fl_landmarks[1[FL_LANDMARK_NB]; // Use new constants
*/
/*TODO: REMOVE ROTATION LOGICS AS DMS WILL NOT USE IT
 * NOTE THAT ROTATION LOGIC IS USED FOR N6 BOARD 
*/
#include "app.h"

#include <stdint.h>
#include <stdio.h>

#include "app_cam.h"
#include "app_config.h"
#include "IPL_resize.h"
#include "app_postprocess.h"
#include "isp_api.h"
#include "ld.h"
#include "ll_aton_runtime.h"
#include "cmw_camera.h"
#include "scrl.h"
#ifdef STM32N6570_DK_REV
#include "stm32n6570_discovery.h"
#else
#include "stm32n6xx_nucleo.h"
#endif
#include "stm32_lcd.h"
#include "stm32_lcd_ex.h"
#include "stm32n6xx_hal.h"
#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"
#include "utils.h"

#define FREERTOS_PRIORITY(p) ((UBaseType_t)((int)tskIDLE_PRIORITY + configMAX_PRIORITIES / 2 + (p)))

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

#include "nema_core.h"
#include "nema_error.h"
void nema_enable_tiling(int);

#define LCD_FG_WIDTH LCD_BG_WIDTH
#define LCD_FG_HEIGHT LCD_BG_HEIGHT

#define CACHE_OP(__op__) do { \
  if (is_cache_enable()) { \
    __op__; \
  } \
} while (0)

#define DBG_INFO 0
#define USE_FILTERED_TS 1

#define BQUEUE_MAX_BUFFERS 2
#define CPU_LOAD_HISTORY_DEPTH 8

#define DISPLAY_BUFFER_NB (DISPLAY_DELAY + 2)

/* palm detector */
#define PD_MAX_HAND_NB 1
#define YOLO_MAX_NB 20

typedef float app_v3_t[3];

/**
 * @brief Defines a Region Of Interest (ROI).
 * @details This is a key structure used to pass the location of a detected object
 * (like a hand or face) to the next stage of the pipeline.
 */
typedef struct {
  float cx;
  float cy;
  float w;
  float h;
  float rotation;
} roi_t;

#define UTIL_LCD_COLOR_TRANSPARENT 0

#ifdef STM32N6570_DK_REV
#define LCD_FONT Font20
#define DISK_RADIUS 2
#else
#define LCD_FONT Font12
#define DISK_RADIUS 1
#endif

/**
 * @brief A simple rectangle definition using top-left corner and size.
 */
typedef struct
{
  uint32_t X0;
  uint32_t Y0;
  uint32_t XSize;
  uint32_t YSize;
} Rectangle_TypeDef;

/**
 * @brief A thread-safe buffer queue for passing data between tasks (e.g., camera and NN).
 * @details Implements a classic producer-consumer model using semaphores.
 */
typedef struct {
  SemaphoreHandle_t free;         /* Signals that a buffer is free for writing. */
  StaticSemaphore_t free_buffer;
  SemaphoreHandle_t ready;        /* Signals that a buffer is ready for reading. */
  StaticSemaphore_t ready_buffer; 
  int buffer_nb;                  /* Total number of buffers in the queue. */
  uint8_t *buffers[BQUEUE_MAX_BUFFERS];
  int free_idx;          /* Index of the next free buffer. */ 
  int ready_idx;        /* Index of the next ready buffer. */
} bqueue_t;

/**
 * @brief Holds data for calculating CPU load.
 */

typedef struct {
  uint64_t current_total;
  uint64_t current_thread_total;
  uint64_t prev_total;
  uint64_t prev_thread_total;
  struct {
    uint64_t total;
    uint64_t thread;
    uint32_t tick;
  } history[CPU_LOAD_HISTORY_DEPTH];
} cpuload_info_t;

/**
 * @brief Holds all information for a single detected hand/face instance.
 * @details This is the main data structure linking the output of the first model
 * to the input of the second, and finally to the display.
 */
typedef struct {
  int is_valid;             /* Flag to check if the detection in this struct is current. */
  pd_pp_box_t pd_hands;     /* Palm Detector raw output. */
  roi_t roi;            /* Region of Interest for the detected hand. */
  ld_point_t ld_landmarks[LD_LANDMARK_NB];        /* Final output from the landmark model */
} hand_info_t;

/**
 * @brief Holds all information for a single detected hand/face instance.
 * @details This is the main data structure linking the output of the first model
 * to the input of the second, and finally to the display.
 */
typedef struct {
  int is_valid;             /* Flag to check if the detection in this struct is current. */
  pd_pp_box_t pd_hands;     /* Palm Detector raw output. */
  roi_t roi;            /* Region of Interest for the detected hand. */
  ld_point_t ld_landmarks[LD_LANDMARK_NB];        /* Final output from the landmark model */
} face_info_t;


/**
 * @brief Aggregates all information needed by the display thread to render one frame.
 */
typedef struct {
  float nn_period_ms;
  uint32_t pd_ms;
  uint32_t yolo_ms;
  uint32_t hl_ms;
  uint32_t pp_ms;
  uint32_t disp_ms;
  int is_ld_displayed;    /* Toggle for showing landmarks. */
  int is_pd_displayed;    /* Toggle for showing palm detector boxes. */
  int pd_hand_nb;       /* Number of valid hands detected by the palm detector. */
  int nb_faces;
  float pd_max_prob;      /* Maximum confidence score of the detected hands. */
  hand_info_t hands[PD_MAX_HAND_NB];  /* Array of detected hands. */
  face_info_t faces[YOLO_MAX_NB];
} display_info_t;

/**
 * @brief A wrapper for the display_info_t struct to make it thread-safe.
 */
typedef struct {
  SemaphoreHandle_t update;         /* Semaphore to signal that new info is ready. */
  StaticSemaphore_t update_buffer;  
  SemaphoreHandle_t lock;           /* Mutex to protect access to the 'info' struct. */
  StaticSemaphore_t lock_buffer;
  display_info_t info;
} display_t;

/**
 * @brief Encapsulates all data related to the Palm Detector (PD) model.
 * @details This will be adapted for our Face Detector (FD) model.
 */
typedef struct {
  uint32_t nn_in_len;       /* Size of the model's input tensor. */
  float *prob_out;          /* Output probabilities for each detected hand. */
  uint32_t prob_out_len;
  float *boxes_out;         /* Pointer to the bounding box output tensor. */
  uint32_t boxes_out_len;
  pd_model_pp_static_param_t static_param;    /* Parameters for post-processing. */
  pd_postprocess_out_t pd_out;    /* Struct to hold post-processing results. */
} pd_model_info_t;

/**
 * @brief Encapsulates all data related to the YOLO model.
 * @details This struct holds pointers to the model's raw output and contains the
 * necessary parameters and buffers for the YOLOv8 post-processing library.
 */
typedef struct {
  void* nn_in;                  // Pointer to the input tensor buffer (the image)
  size_t nn_in_len;             // Length of the input tensor buffer in bytes

  int8_t* raw_output_tensor;    // Pointer to the raw output from the NPU
  size_t raw_output_len;        // Length of the raw output buffer in bytes

  od_pp_out_t pp_output;        // Struct to hold the final, processed output (bounding boxes)
  yolov8_pp_static_param_t pp_params; // Static parameters for the YOLOv8 post-processing

} yolo_model_info_t;


/**
 * @brief Encapsulates all data related to the Hand Landmark (HL) model.
 * @details This will be adapted for our Face Landmark model.
 */
typedef struct {
  uint8_t *nn_in;       /* Pointer to the model's input tensor. */
  uint32_t nn_in_len;
  float *prob_out;      /* Pointer to the landmark presence probability output. */
  uint32_t prob_out_len;
  float *landmarks_out; /* Pointer to the landmark coordinates output tensor. */
  uint32_t landmarks_out_len;
} hl_model_info_t;

/**
 * @brief Encapsulates all data related to the Face Landmark model.
 */
typedef struct {
  uint8_t *nn_in;       /* Pointer to the model's input tensor. */
  uint32_t nn_in_len;
  float *prob_out;      /* Pointer to the landmark presence probability output. */
  uint32_t prob_out_len;
  float *landmarks_out; /* Pointer to the landmark coordinates output tensor. */
  uint32_t landmarks_out_len;
} fl_model_info_t;


/**
 * @brief A simple structure to manage a UI button's state and callback.
 */
typedef struct {
  Button_TypeDef button_id;
  int prev_state;
  void (*on_click_handler)(void *cb_args);
  void *cb_args;
} button_t;

/* Globals */

/* Rectangle definitions for the full background and foreground layers. */
static Rectangle_TypeDef lcd_bg_area = {
  .X0 = 0,
  .Y0 = 0,
  .XSize = LCD_BG_WIDTH,
  .YSize = LCD_BG_HEIGHT,
};

static Rectangle_TypeDef lcd_fg_area = {
  .X0 = 0,
  .Y0 = 0,
  .XSize = LCD_FG_WIDTH,
  .YSize = LCD_FG_HEIGHT,
};

/* The main display buffers. This is a set of 3+ full-frame buffers for smooth video.
   ALIGN_32 ensures 32-byte alignment for performance (DMA/cache).
   IN_PSRAM places this large buffer in external PSRAM. */
/* Lcd Background Buffer */
static uint8_t lcd_bg_buffer[DISPLAY_BUFFER_NB][LCD_BG_WIDTH * LCD_BG_HEIGHT * DISPLAY_BPP] ALIGN_32 IN_PSRAM;
static int lcd_bg_buffer_disp_idx = 1;
static int lcd_bg_buffer_capt_idx = 0;
/* Lcd Foreground Buffer */
static uint8_t lcd_fg_buffer[2][LCD_FG_WIDTH * LCD_FG_HEIGHT* 2] ALIGN_32 IN_PSRAM;
static int lcd_fg_buffer_rd_idx;
static display_t disp = {
  .info.is_ld_displayed = 1,
  .info.is_pd_displayed = 0,
};
static cpuload_info_t cpu_load;
/* screen buffer */
static uint8_t screen_buffer[LCD_BG_WIDTH * LCD_BG_HEIGHT * 2] ALIGN_32 IN_PSRAM;

/* model */
LL_ATON_DECLARE_NAMED_NN_INSTANCE_AND_INTERFACE(palm_detector);
 /* Declare the necessary runtime instances and global buffers to hold outputs */
 /* palm detector */
static roi_t rois[PD_MAX_HAND_NB];
 /* hand landmark */
LL_ATON_DECLARE_NAMED_NN_INSTANCE_AND_INTERFACE(hand_landmark);
static ld_point_t ld_landmarks[PD_MAX_HAND_NB][LD_LANDMARK_NB];
LL_ATON_DECLARE_NAMED_NN_INSTANCE_AND_INTERFACE(yolo_detector);
LL_ATON_DECLARE_NAMED_NN_INSTANCE_AND_INTERFACE(face_landmark);
static roi_t rois_yolo[YOLO_MAX_NB];
static ld_point_t fl_landmarks[1][FL_LANDMARK_NB]; // Use new constants
/* Counters for frame synchronization. */
static uint32_t frame_event_nb;
static volatile uint32_t frame_event_nb_for_resize;

/*TODO: UPDATE THE DEFINED MACROS UNDER app.h
* OR postprocess_conf.h which defines the postprocessing type, we should be able to define it to YOLOV8
*/
 /* nn input buffers */
static uint8_t nn_input_buffers[2][NN_WIDTH * NN_HEIGHT * NN_BPP] ALIGN_32 IN_PSRAM;
static bqueue_t nn_input_queue;

/* --- RTOS Task (Thread) Declarations --- */
/* Statically allocates the memory for the three main application tasks and their stacks. */static StaticTask_t nn_thread;
static StackType_t nn_thread_stack[2 * configMINIMAL_STACK_SIZE];
static StaticTask_t dp_thread;
static StackType_t dp_thread_stack[2 *configMINIMAL_STACK_SIZE];
static StaticTask_t isp_thread;
static StackType_t isp_thread_stack[2 *configMINIMAL_STACK_SIZE];
static SemaphoreHandle_t isp_sem;
static StaticSemaphore_t isp_sem_buffer;

static GFXMMU_HandleTypeDef hgfxmmu;
static nema_cmdlist_t cl;

static int is_cache_enable()
{
#if defined(USE_DCACHE)
  return 1;
#else
  return 0;
#endif
}

/* THESE FUNCTIONS ARE TO BE DEPRECIATED*/

/** HELPER FUNCTIONS
 * @brief Normalizes an angle to the range [-PI, PI].
 * @param angle The input angle in radians.
 * @return The equivalent angle within the range [-PI, PI].
 */
static float pd_normalize_angle(float angle)
{
  return angle - 2 * M_PI * floorf((angle - (-M_PI)) / (2 * M_PI));
}

static float pd_cook_rotation(float angle)
{
  return angle;
}

static float pd_compute_rotation(pd_pp_box_t *box)
{
  float x0, y0, x1, y1;
  float rotation;

  x0 = box->pKps[0].x;
  y0 = box->pKps[0].y;
  x1 = box->pKps[2].x;
  y1 = box->pKps[2].y;

  rotation = M_PI * 0.5 - atan2f(-(y1 - y0), x1 - x0);

  return pd_cook_rotation(pd_normalize_angle(rotation));
}
/* END OF DEPRECIATED FUNCTIONS */

/* TO WRITE EQUIVALENT FOR YOLO FACE DETECTOR*/

/**
 * @brief Converts normalized AI model coordinates (0.0 to 1.0) to screen pixel coordinates.
 * @details The AI model outputs coordinates relative to its square input buffer. This
 * function scales them to match the final display resolution.
 * @param box Pointer to the detection box with normalized coordinates.
 */
static void cvt_pd_coord_to_screen_coord(pd_pp_box_t *box)
{
  int i;

  /* This is not a typo. Since screen aspect ratio was conserved. We really want to use LCD_BG_WIDTH for
   * y positions.
   */

  box->x_center *= LCD_BG_WIDTH;
  box->y_center *= LCD_BG_WIDTH;
  box->width *= LCD_BG_WIDTH;
  box->height *= LCD_BG_WIDTH;
  for (i = 0; i < AI_PD_MODEL_PP_NB_KEYPOINTS; i++) {
    box->pKps[i].x *= LCD_BG_WIDTH;
    box->pKps[i].y *= LCD_BG_WIDTH;
  }
}

/**
 * @brief Adjusts a Region of Interest (ROI) by shifting its center and scaling its size.
 * @details This is used to create the final input for the second model. It takes the
 * initial detection, shifts it, and scales it up to ensure the full object (e.g.,
 * the whole hand, not just the palm) is included. It also makes the ROI a square.
 */
static void roi_shift_and_scale(roi_t *roi, float shift_x, float shift_y, float scale_x, float scale_y)
{
  float long_side;
  float sx, sy;

  sx = (roi->w * shift_x * cos(roi->rotation) - roi->h * shift_y * sin(roi->rotation));
  sy = (roi->w * shift_x * sin(roi->rotation) + roi->h * shift_y * cos(roi->rotation));

  roi->cx += sx;
  roi->cy += sy;

  long_side = MAX(roi->w, roi->h);
  roi->w = long_side;
  roi->h = long_side;

  roi->w *= scale_x;
  roi->h *= scale_y;
}

/* TO WRITE EQUIVALENT FUNCTION FOR YOLO FACE DETECTOR
 * WHICH HANDLES THE MULTI-CLASS OUTPUT OF THE YOLO DETECTOR
 * AND CONVERTS IT INTO A PROPER FACE ROI FOR THE LANDMARK MODEL.
*/
/**
 * @brief Converts the output of the first model (detector) into an ROI for the second model.
 * @details This is the core "glue" function between the two AI models. It takes the raw
 * palm/face detection and transforms it into a properly scaled, rotated, and positioned
 * ROI that the second (landmark) model can use.
 * @param box The raw output from the palm/face detector.
 * @param roi The ROI structure to be filled for the landmark model.
 */
static void pd_box_to_roi(pd_pp_box_t *box,  roi_t *roi)
{
  const float shift_x = 0;
  const float shift_y = -0.5;
  const float scale = 2.6;

  roi->cx = box->x_center;
  roi->cy = box->y_center;
  roi->w = box->width;
  roi->h = box->height;
  roi->rotation = pd_compute_rotation(box);

  roi_shift_and_scale(roi, shift_x, shift_y, scale, scale);

}

/**
 * @brief A utility function to copy data from one detection box struct to another.
 * TODO: ADAPT INTO COPYING FD BOXES
 */
static void copy_pd_box(pd_pp_box_t *dst, pd_pp_box_t *src)
{
  int i;

  dst->prob = src->prob;
  dst->x_center = src->x_center;
  dst->y_center = src->y_center;
  dst->width = src->width;
  dst->height = src->height;
  for (i = 0 ; i < AI_PD_MODEL_PP_NB_KEYPOINTS; i++)
    dst->pKps[i] = src->pKps[i];
}

/**
 * @brief Initializes a hardware button using the Board Support Package (BSP).
 * @param on_click_handler Function pointer to call when the button is pressed.
 */
static void button_init(button_t *b, Button_TypeDef id, void (*on_click_handler)(void *), void *cb_args)
{
  int ret;

  ret = BSP_PB_Init(id, BUTTON_MODE_GPIO);
  assert(ret == BSP_ERROR_NONE);

  b->button_id = id;
  b->on_click_handler = on_click_handler;
  b->prev_state = 0;
  b->cb_args = cb_args;
}

/**
 * @brief Polls a button's state and triggers its callback on a press event.
 * @details This should be called periodically in a UI or main task.
 */
static void button_process(button_t *b)
{
  int state = BSP_PB_GetState(b->button_id);

  if (state != b->prev_state && state && b->on_click_handler)
    b->on_click_handler(b->cb_args);

  b->prev_state = state;
}

/**
 * @brief Initializes the CPU load tracking structure.
 */
static void cpuload_init(cpuload_info_t *cpu_load)
{
  memset(cpu_load, 0, sizeof(cpuload_info_t));
}

/**
 * @brief Updates the CPU load history with a new data point.
 * @details Uses FreeRTOS's runtime counters to get total time and idle time.
 */
static void cpuload_update(cpuload_info_t *cpu_load)
{
  int i;

  cpu_load->history[1] = cpu_load->history[0];
  cpu_load->history[0].total = portGET_RUN_TIME_COUNTER_VALUE();
  cpu_load->history[0].thread = cpu_load->history[0].total - ulTaskGetIdleRunTimeCounter();
  cpu_load->history[0].tick = HAL_GetTick();

  if (cpu_load->history[1].tick - cpu_load->history[2].tick < 1000)
    return ;

  for (i = 0; i < CPU_LOAD_HISTORY_DEPTH - 2; i++)
    cpu_load->history[CPU_LOAD_HISTORY_DEPTH - 1 - i] = cpu_load->history[CPU_LOAD_HISTORY_DEPTH - 1 - i - 1];
}

/**
 * @brief Calculates CPU load percentages over different time windows.
 */
static void cpuload_get_info(cpuload_info_t *cpu_load, float *cpu_load_last, float *cpu_load_last_second,
                             float *cpu_load_last_five_seconds)
{
  if (cpu_load_last)
    *cpu_load_last = 100.0 * (cpu_load->history[0].thread - cpu_load->history[1].thread) /
                     (cpu_load->history[0].total - cpu_load->history[1].total);
  if (cpu_load_last_second)
    *cpu_load_last_second = 100.0 * (cpu_load->history[2].thread - cpu_load->history[3].thread) /
                     (cpu_load->history[2].total - cpu_load->history[3].total);
  if (cpu_load_last_five_seconds)
    *cpu_load_last_five_seconds = 100.0 * (cpu_load->history[2].thread - cpu_load->history[7].thread) /
                     (cpu_load->history[2].total - cpu_load->history[7].total);
}

/**
 * @brief Initializes a thread-safe buffer queue (bqueue).
 * @details Creates the FreeRTOS semaphores needed for producer-consumer synchronization.
 * @return 0 on success, -1 on failure.
 */
static int bqueue_init(bqueue_t *bq, int buffer_nb, uint8_t **buffers)
{
  int i;

  if (buffer_nb > BQUEUE_MAX_BUFFERS)
    return -1;

  bq->free = xSemaphoreCreateCountingStatic(buffer_nb, buffer_nb, &bq->free_buffer);
  if (!bq->free)
    goto free_sem_error;
  bq->ready = xSemaphoreCreateCountingStatic(buffer_nb, 0, &bq->ready_buffer);
  if (!bq->ready)
    goto ready_sem_error;

  bq->buffer_nb = buffer_nb;
  for (i = 0; i < buffer_nb; i++) {
    assert(buffers[i]);
    bq->buffers[i] = buffers[i];
  }
  bq->free_idx = 0;
  bq->ready_idx = 0;

  return 0;

ready_sem_error:
  vSemaphoreDelete(bq->free);
free_sem_error:
  return -1;
}

/**
 * @brief Gets a free buffer from the queue for a producer to write to.
 * @param is_blocking If true, will wait indefinitely for a free buffer.
 * @return Pointer to a free buffer, or NULL if non-blocking and none are available.
 */
static uint8_t *bqueue_get_free(bqueue_t *bq, int is_blocking)
{
  uint8_t *res;
  int ret;

  ret = xSemaphoreTake(bq->free, is_blocking ? portMAX_DELAY : 0);
  if (ret == pdFALSE)
    return NULL;

  res = bq->buffers[bq->free_idx];
  bq->free_idx = (bq->free_idx + 1) % bq->buffer_nb;

  return res;
}

/**
 * @brief Returns a buffer to the free pool (used by a consumer).
 */
static void bqueue_put_free(bqueue_t *bq)
{
  int ret;

  ret = xSemaphoreGive(bq->free);
  assert(ret == pdTRUE);
}

/**
 * @brief Gets a ready buffer from the queue for a consumer to read from.
 * @details This function will block until a buffer is ready.
 * @return Pointer to a ready buffer.
 */
static uint8_t *bqueue_get_ready(bqueue_t *bq)
{
  uint8_t *res;
  int ret;

  ret = xSemaphoreTake(bq->ready, portMAX_DELAY);
  assert(ret == pdTRUE);

  res = bq->buffers[bq->ready_idx];
  bq->ready_idx = (bq->ready_idx + 1) % bq->buffer_nb;

  return res;
}

/**
 * @brief Puts a buffer into the ready pool (used by a producer).
 * @details Handles being called from an Interrupt Service Routine (ISR).
 */
static void bqueue_put_ready(bqueue_t *bq)
{
  BaseType_t xHigherPriorityTaskWoken = pdFALSE;
  int ret;

  if (xPortIsInsideInterrupt()) {
    ret = xSemaphoreGiveFromISR(bq->ready, &xHigherPriorityTaskWoken);
    assert(ret == pdTRUE);
    portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
  } else {
    ret = xSemaphoreGive(bq->ready);
    assert(ret == pdTRUE);
  }
}

/**
 * @brief Updates the display controller to show a new background buffer.
 * @details This function directly interacts with the screen layer driver to perform
 * a "flip," making the newly rendered frame visible.
 * @param next_disp_idx The index of the buffer in lcd_bg_buffer to display.
 */
static void reload_bg_layer(int next_disp_idx)
{
  int ret;

  ret = SCRL_SetAddress_NoReload(lcd_bg_buffer[next_disp_idx], SCRL_LAYER_0);
  assert(ret == 0);
  ret = SCRL_ReloadLayer(SCRL_LAYER_0);
  assert(ret == 0);

  ret = SRCL_Update();
  assert(ret == 0);
}

/**
 * @brief Frame event callback for the main display pipe (Pipe 1).
 * @details This function is triggered by a hardware interrupt every time the DCMIPP
 * has finished writing a new video frame for the display. It implements
 * a triple-buffering scheme for smooth, tear-free video.
 */
static void app_main_pipe_frame_event()
{
  /* Calculate the indices for the next display buffer and next capture buffer in a circular manner. */
  int next_disp_idx = (lcd_bg_buffer_disp_idx + 1) % DISPLAY_BUFFER_NB;
  int next_capt_idx = (lcd_bg_buffer_capt_idx + 1) % DISPLAY_BUFFER_NB;
  int ret;

  /* Tell the DCMIPP hardware where to write the *next* frame it captures. */
  ret = HAL_DCMIPP_PIPE_SetMemoryAddress(CMW_CAMERA_GetDCMIPPHandle(), DCMIPP_PIPE1,
                                         DCMIPP_MEMORY_ADDRESS_0, (uint32_t) lcd_bg_buffer[next_capt_idx]);
  assert(ret == HAL_OK);

  /* Update the global indices to track the buffers. */
  reload_bg_layer(next_disp_idx);
  lcd_bg_buffer_disp_idx = next_disp_idx;
  lcd_bg_buffer_capt_idx = next_capt_idx;

  frame_event_nb++;
}

/**
 * @brief Frame event callback for the ancillary NN pipe (Pipe 2).
 * @details This function is triggered by a hardware interrupt every time the DCMIPP
 * has finished writing a new, smaller frame for the AI model.
 */
static void app_ancillary_pipe_frame_event()
{
  uint8_t *next_buffer;
  int ret;

  next_buffer = bqueue_get_free(&nn_input_queue, 0);
  if (next_buffer) {
    ret = HAL_DCMIPP_PIPE_SetMemoryAddress(CMW_CAMERA_GetDCMIPPHandle(), DCMIPP_PIPE2,
                                           DCMIPP_MEMORY_ADDRESS_0, (uint32_t) next_buffer);
    assert(ret == HAL_OK);
    /* minus 1 since app_main_pipe_frame_event occur before app_ancillary_pipe_frame_event() */
    frame_event_nb_for_resize = frame_event_nb - 1;
    bqueue_put_ready(&nn_input_queue);     /* Put the buffer into the 'ready' queue so the NN task can process it. */
  }
}

/**
 * @brief VSYNC event callback for the display.
 * @details This is triggered by a hardware interrupt at the start of each vertical
 * blanking interval of the display. It's used to synchronize the camera's
 * Image Signal Processing (ISP) task with the display refresh rate.
 */
static void app_main_pipe_vsync_event()
{
  BaseType_t xHigherPriorityTaskWoken = pdFALSE;
  int ret;

  ret = xSemaphoreGiveFromISR(isp_sem, &xHigherPriorityTaskWoken);
  if (ret == pdTRUE)
    portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
}

/**
 * @brief Clamps a 2D point to ensure it's within the screen boundaries.
 * @return 1 if the point was moved, 0 otherwise.
 */
static int clamp_point(int *x, int *y)
{
  int xi = *x;
  int yi = *y;

  if (*x < 0)
    *x = 0;
  if (*y < 0)
    *y = 0;
  if (*x >= lcd_bg_area.XSize)
    *x = lcd_bg_area.XSize - 1;
  if (*y >= lcd_bg_area.YSize)
    *y = lcd_bg_area.YSize - 1;

  return (xi != *x) || (yi != *y);
}

/**
 * @brief Clamps a 2D point, keeping a minimum margin from the screen edges.
 * @return 1 if the point was moved, 0 otherwise.
 */
static int clamp_point_with_margin(int *x, int *y, int margin)
{
  int xi = *x;
  int yi = *y;

  if (*x < margin)
    *x = margin;
  if (*y < margin)
    *y = margin;
  if (*x >= lcd_bg_area.XSize - margin)
    *x = lcd_bg_area.XSize - margin - 1;
  if (*y >= lcd_bg_area.YSize - margin)
    *y = lcd_bg_area.YSize - margin - 1;

  return (xi != *x) || (yi != *y);
}

/**
 * @brief Draws the output of the first model (palm/face detector).
 * @param hand Pointer to the raw detection box data.
 */
static void display_pd_hand(pd_pp_box_t *hand)
{
  int xc, yc;
  int x0, y0;
  int x1, y1;
  int w, h;
  int i;

  /* display box around palm */
  xc = (int)hand->x_center;
  yc = (int)hand->y_center;
  w = (int)hand->width;
  h = (int)hand->height;
  x0 = xc - (w + 1) / 2;
  y0 = yc - (h + 1) / 2;
  x1 = xc + (w + 1) / 2;
  y1 = yc + (h + 1) / 2;
  clamp_point(&x0, &y0);
  clamp_point(&x1, &y1);
  UTIL_LCD_DrawRect(x0, y0, x1 - x0, y1 - y0, UTIL_LCD_COLOR_GREEN);

  /* display palm key points */
  for (i = 0; i < 7; i++) {
    uint32_t color = (i != 0 && i != 2) ? UTIL_LCD_COLOR_RED : UTIL_LCD_COLOR_BLUE;

    x0 = (int)hand->pKps[i].x;
    y0 = (int)hand->pKps[i].y;
    clamp_point(&x0, &y0);
    UTIL_LCD_FillCircle(x0, y0, 2, color);
  }
}

/**
 * @brief Rotates a 2D point around the origin.
 */
static void rotate_point(float pt[2], float rotation)
{
  float x = pt[0];
  float y = pt[1];

  pt[0] = cos(rotation) * x - sin(rotation) * y;
  pt[1] = sin(rotation) * x + cos(rotation) * y;
}

/**
 * @brief Calculates the four corner coordinates of a rotated ROI rectangle.
 */
static void roi_to_corners(roi_t *roi, float corners[4][2])
{
  const float corners_init[4][2] = {
    {-roi->w / 2, -roi->h / 2},
    { roi->w / 2, -roi->h / 2},
    { roi->w / 2,  roi->h / 2},
    {-roi->w / 2,  roi->h / 2},
  };
  int i;

  memcpy(corners, corners_init, sizeof(corners_init));
  /* rotate */
  for (i = 0; i < 4; i++)
    rotate_point(corners[i], roi->rotation);

  /* shift */
  for (i = 0; i < 4; i++) {
    corners[i][0] += roi->cx;
    corners[i][1] += roi->cy;
  }
}

/**
 * @brief Clamps all four corners of a rectangle to the screen boundaries.
 */
static int clamp_corners(float corners_in[4][2], int corners_out[4][2])
{
  int is_clamp = 0;
  int i;

  for (i = 0; i < 4; i++) {
    corners_out[i][0] = (int)corners_in[i][0];
    corners_out[i][1] = (int)corners_in[i][1];
    is_clamp |= clamp_point(&corners_out[i][0], &corners_out[i][1]);
  }

  return is_clamp;
}

/**
 * @brief Draws the rotated red ROI box for debugging purposes.
 * @details This shows the exact region that was cropped and sent to the second model.
 */
static void display_roi(roi_t *roi)
{
  float corners_f[4][2];
  int corners[4][2];
  int is_clamp;
  int i;

  /* compute box corners */
  roi_to_corners(roi, corners_f);

  /* clamp */
  is_clamp = clamp_corners(corners_f, corners);
  if (is_clamp)
    return ;

  /* display */
  for (i = 0; i < 4; i++)
    UTIL_LCD_DrawLine(corners[i][0], corners[i][1], corners[(i + 1) % 4][0], corners[(i + 1) % 4][1],
                      UTIL_LCD_COLOR_RED);
}

/**
 * @brief Decodes a landmark's relative coordinates into absolute screen coordinates.
 * @details The landmark model outputs coordinates relative to the ROI (0.0 to 1.0).
 * This function transforms them back into the main screen's coordinate space by
 * applying the ROI's translation, scaling, and rotation.
 * @param roi The Region of Interest that was used as input for the landmark model.
 * @param lm The landmark point with relative coordinates.
 * @param decoded The landmark point with absolute screen coordinates (output).
 */
static void decode_ld_landmark(roi_t *roi, ld_point_t *lm, ld_point_t *decoded)
{
  float rotation = roi->rotation;
  float w = roi->w;
  float h = roi->h;

  decoded->x = roi->cx + (lm->x - 0.5) * w * cos(rotation) - (lm->y - 0.5) * h * sin(rotation);
  decoded->y = roi->cy + (lm->x - 0.5) * w * sin(rotation) + (lm->y - 0.5) * h * cos(rotation);
}

/**
 * @brief Draws the output of the second model (hand/face landmarks).
 */
static void display_ld_hand(hand_info_t *hand)
{
  const int disk_radius = DISK_RADIUS;
  roi_t *roi = &hand->roi;
  int x[LD_LANDMARK_NB];
  int y[LD_LANDMARK_NB];
  int is_clamped[LD_LANDMARK_NB];
  ld_point_t decoded;
  int i;

  for (i = 0; i < LD_LANDMARK_NB; i++) {
    decode_ld_landmark(roi, &hand->ld_landmarks[i], &decoded);
    x[i] = (int)decoded.x;
    y[i] = (int)decoded.y;
    is_clamped[i] = clamp_point_with_margin(&x[i], &y[i], disk_radius);
  }

  for (i = 0; i < LD_LANDMARK_NB; i++) {
    if (is_clamped[i])
      continue;
    UTIL_LCD_FillCircle(x[i], y[i], disk_radius, UTIL_LCD_COLOR_YELLOW);
  }

  for (i = 0; i < LD_BINDING_NB; i++) {
    if (is_clamped[ld_bindings_idx[i][0]] || is_clamped[ld_bindings_idx[i][1]])
      continue;
    UTIL_LCD_DrawLine(x[ld_bindings_idx[i][0]], y[ld_bindings_idx[i][0]],
                      x[ld_bindings_idx[i][1]], y[ld_bindings_idx[i][1]],
                      UTIL_LCD_COLOR_BLACK);
  }
}

/**
 * @brief Main drawing wrapper to display all info for a single detected hand/face.
 * @details Checks UI toggles to decide whether to draw the bounding box and/or the landmarks.
 */
void display_hand(display_info_t *info, hand_info_t *hand)
{
  if (info->is_pd_displayed) {
    display_pd_hand(&hand->pd_hands);
    display_roi(&hand->roi);
  }
  if (info->is_ld_displayed)
    display_ld_hand(hand);
}

/**
 * @brief Renders the entire UI overlay for one frame.
 * @details This is the main function called by the display task. It clears the
 * overlay, draws performance stats, and then draws the AI model results.
 * @param info The main display structure containing all data to be rendered.
 */
static void Display_NetworkOutput(display_info_t *info)
{
  float cpu_load_one_second;
  int line_nb = 0;
  float nn_fps;
  int i;

  /* clear previous ui */
  UTIL_LCD_FillRect(lcd_fg_area.X0, lcd_fg_area.Y0, lcd_fg_area.XSize, lcd_fg_area.YSize, 0x00000000); /* Clear previous boxes */

  /* cpu load */
  cpuload_update(&cpu_load);
  cpuload_get_info(&cpu_load, NULL, &cpu_load_one_second, NULL);

  /* draw metrics */
  nn_fps = 1000.0 / info->nn_period_ms;
  UTIL_LCDEx_PrintfAt(0, LINE(line_nb),  RIGHT_MODE, "Cpu load");
  line_nb += 1;
  UTIL_LCDEx_PrintfAt(0, LINE(line_nb),  RIGHT_MODE, "   %.1f%%", cpu_load_one_second);
  line_nb += 2;
  UTIL_LCDEx_PrintfAt(0, LINE(line_nb), RIGHT_MODE, "Inferences");
  line_nb += 1;
  UTIL_LCDEx_PrintfAt(0, LINE(line_nb), RIGHT_MODE, " pd %2ums", info->pd_ms);
  line_nb += 1;
  UTIL_LCDEx_PrintfAt(0, LINE(line_nb), RIGHT_MODE, " hl %2ums", info->hl_ms);
  line_nb += 2;
  UTIL_LCDEx_PrintfAt(0, LINE(line_nb), RIGHT_MODE, "  %.1f FPS", nn_fps);
  line_nb += 2;
  if (DBG_INFO) {
    UTIL_LCDEx_PrintfAt(0, LINE(line_nb), RIGHT_MODE, "Display");
    line_nb += 1;
    UTIL_LCDEx_PrintfAt(0, LINE(line_nb), RIGHT_MODE, "   %ums", info->disp_ms);
    line_nb += 1;
  }

  /* display palm detector output */
  for (i = 0; i < info->pd_hand_nb; i++) {
    if (info->hands[i].is_valid)
      display_hand(info, &info->hands[i]);
  }

  if (DBG_INFO)
    UTIL_LCDEx_PrintfAt(0, LINE(line_nb),  RIGHT_MODE, "pd : %5.1f %%", info->pd_max_prob * 100);
}

/**
 * @brief Initializes the Palm Detector model and its post-processor.
 * @details This function gets memory addresses for the model's output tensors
 * (where the NPU writes its results) and prepares the software-based
 * post-processing library. This is for the FIRST model in the sequence.
 * @param info Pointer to the palm detector model info structure to be filled.
 */
static void palm_detector_init(pd_model_info_t *info)
{
  /* Get pointers to the model's output and input buffer information from the AI library. */
  const LL_Buffer_InfoTypeDef *nn_out_info = LL_ATON_Output_Buffers_Info_palm_detector();
  const LL_Buffer_InfoTypeDef *nn_in_info = LL_ATON_Input_Buffers_Info_palm_detector();
  int ret;

  /* Store pointers and sizes for the model's input and output tensors. */
  info->nn_in_len = LL_Buffer_len(&nn_in_info[0]);
  info->prob_out = (float *) LL_Buffer_addr_start(&nn_out_info[0]);
  info->prob_out_len = LL_Buffer_len(&nn_out_info[0]);
  assert(info->prob_out_len == AI_PD_MODEL_PP_TOTAL_DETECTIONS * sizeof(float));
  info->boxes_out = (float *) LL_Buffer_addr_start(&nn_out_info[1]);
  info->boxes_out_len = LL_Buffer_len(&nn_out_info[1]);
  assert(info->boxes_out_len == AI_PD_MODEL_PP_TOTAL_DETECTIONS * sizeof(float) * 18);

  /* Initialize the post-processing library with model-specific parameters (e.g., anchor boxes). */
  ret = app_postprocess_init(&info->static_param);
  assert(ret == AI_PD_POSTPROCESS_ERROR_NO);
}

/**
 * @brief Initializes the YOLOv8 Detector model and its post-processor parameters.
 * @details This function gets the memory address for the model's single raw output
 * tensor and configures the parameters for the YOLOv8 post-processing library.
 * @param info Pointer to the yolo_detector_info_t structure to be filled.
 */
static void yolo_detector_init(yolo_model_info_t *info)
{
  /* Get pointers to the info structures for the model's I/O buffers. */
  const LL_Buffer_InfoTypeDef *nn_out_info = LL_ATON_Output_Buffers_Info_yolo_detector();
  const LL_Buffer_InfoTypeDef *nn_in_info = LL_ATON_Input_Buffers_Info_yolo_detector();

  /* --- Get I/O Buffer Addresses --- */
  info->nn_in = LL_Buffer_addr_start(&nn_in_info[0]);
  info->nn_in_len = LL_Buffer_len(&nn_in_info[0]);
  info->raw_output_tensor = (int8_t *) LL_Buffer_addr_start(&nn_out_info[0]);
  info->raw_output_len = LL_Buffer_len(&nn_out_info[0]);

  /* --- Initialize the Post-Processing Parameters --- */
  /* Call the generic init function. It will populate the pp_params struct
     with the correct default values from the pre-processor defines. */
  app_postprocess_init(&info->pp_params);
}

/**
 * @brief Runs one inference of the YOLOv8 Detector model.
 * @details This function runs the NPU inference, calls the YOLOv8 post-processing
 * library, filters the results for faces (class ID 2), and prepares the
 * Regions of Interest (ROIs) for the next stage.
 * @param buffer Pointer to the input image from the camera.
 * @param info Pointer to the initialized yolo_detector_info_t structure.
 * @param yolo_exec_time Pointer to store the execution time of this stage.
 * @return The number of *faces* detected.
 */
static int yolo_detector_run(uint8_t *buffer, yolo_model_info_t *info, uint32_t *yolo_exec_time)
{
  uint32_t start_ts;
  int total_detections;
  int face_nb = 0; /* This will count only the faces we find. */
  int ret;

  start_ts = HAL_GetTick();

  /* --- 1. Run Inference --- */
  ret = LL_ATON_Set_User_Input_Buffer_yolo_detector(0, buffer, info->nn_in_len);
  assert(ret == LL_ATON_User_IO_NOERROR);

  LL_ATON_RT_Main(&NN_Instance_yolo_detector);

  CACHE_OP(SCB_InvalidateDCache_by_Addr(info->raw_output_tensor, info->raw_output_len));

  /* --- 2. Run Post-Processing via Wrapper --- */
  /* Call the generic post-processing wrapper. It will internally call the correct INT8 function. */
  ret = app_postprocess_run((void * []){info->raw_output_tensor}, 1, &info->pp_output, &info->pp_params);
  assert(ret == AI_OD_POSTPROCESS_ERROR_NO);
  total_detections = info->pp_output.nb_detect;

  /* --- 3. Filter for Faces & Prepare ROIs --- */
  for (int i = 0; i < total_detections; i++)
  {
    /* Check if the detected object is a face (class ID 2). */
    if (info->pp_output.pOutBuff[i].class_index == 2)
    {
      pd_pp_box_t temp_box = {0};
      temp_box.x_center = info->pp_output.pOutBuff[i].x_center;
      temp_box.y_center = info->pp_output.pOutBuff[i].y_center;
      temp_box.width    = info->pp_output.pOutBuff[i].width;
      temp_box.height   = info->pp_output.pOutBuff[i].height;
      temp_box.prob     = info->pp_output.pOutBuff[i].conf;

      cvt_pd_coord_to_screen_coord(&temp_box);
      pd_box_to_roi(&temp_box, &rois[face_nb]);

      face_nb++; /* Increment the count of found faces. */
      if (face_nb >= YOLO_MAX_NB) { break; } /* Stop if we've reached our limit. */
    }
  }

  *yolo_exec_time = HAL_GetTick() - start_ts;
  return face_nb; /* Return the count of faces, not total objects. */
}
 
/**
 * @brief Initializes the Face Landmark model.
 * @details This function gets memory addresses for the model's input and output
 * tensors. It is configured based on analysis of the Python post-processing script.
 * @param info Pointer to the face landmark model info structure to be filled.
 * @note The indices for nn_out_info have been updated to match the model's
 * actual output order: [0] for score, [1] for landmarks.
 */
static void face_landmark_init(fl_model_info_t *info)
{
  // Get pointers to the info structures for the model's input/output buffers
  const LL_Buffer_InfoTypeDef *nn_out_info = LL_ATON_Output_Buffers_Info_face_landmark();
  const LL_Buffer_InfoTypeDef *nn_in_info = LL_ATON_Input_Buffers_Info_face_landmark();

  // --- INPUT TENSOR ---
  // The input is the image buffer for the model to process.
  info->nn_in = LL_Buffer_addr_start(&nn_in_info[0]);
  info->nn_in_len = LL_Buffer_len(&nn_in_info[0]);

  // --- OUTPUT TENSORS (Order corrected based on Python analysis) ---

  // Output 0: Presence Score
  // This buffer will contain a single float indicating the confidence that a face was detected.
  info->prob_out = (float *) LL_Buffer_addr_start(&nn_out_info[0]);
  info->prob_out_len = LL_Buffer_len(&nn_out_info[0]);

  // Output 1: Landmarks
  // This buffer contains the raw coordinates for all 468 facial landmarks.
  // Even if post-processing only uses x and y, we must map the full 3D output buffer.
  info->landmarks_out = (float *) LL_Buffer_addr_start(&nn_out_info[1]);
  info->landmarks_out_len = LL_Buffer_len(&nn_out_info[1]);
}


/**
 * @brief Runs one inference of the Palm Detector model.
 * @param buffer Pointer to the input image from the camera.
 * @param info Pointer to the initialized model info structure.
 * @param pd_exec_time Pointer to store the execution time of this stage.
 * @return The number of hands/faces detected.
 */
static int palm_detector_run(uint8_t *buffer, pd_model_info_t *info, uint32_t *pd_exec_time)
{
  uint32_t start_ts;
  int hand_nb;
  int ret;
  int i;

  start_ts = HAL_GetTick();
  /* Set the input buffer for the NPU. */
  /* Note that we don't need to clean/invalidate those input buffers since they are only access in hardware */
  ret = LL_ATON_Set_User_Input_Buffer_palm_detector(0, buffer, info->nn_in_len);
  assert(ret == LL_ATON_User_IO_NOERROR);

  /* Trigger the NPU to run the inference. This is a blocking call. */
  LL_ATON_RT_Main(&NN_Instance_palm_detector);

  /* Run software post-processing to decode the raw NPU output into human-readable boxes and scores. */
  ret = app_postprocess_run((void * []){info->prob_out, info->boxes_out}, 2, &info->pd_out, &info->static_param);
  assert(ret == AI_PD_POSTPROCESS_ERROR_NO);
  hand_nb = MIN(info->pd_out.box_nb, PD_MAX_HAND_NB);

  /* For each detected hand/face, convert its coordinates and generate an ROI for the next model. */
  for (i = 0; i < hand_nb; i++) {
    cvt_pd_coord_to_screen_coord(&info->pd_out.pOutData[i]);
    pd_box_to_roi(&info->pd_out.pOutData[i], &rois[i]);
  }

  /* Discard nn_out region (used by pp_outputs variables) to avoid Dcache evictions during nn inference */
  CACHE_OP(SCB_InvalidateDCache_by_Addr(info->prob_out, info->prob_out_len));
  CACHE_OP(SCB_InvalidateDCache_by_Addr(info->boxes_out, info->boxes_out_len));

  *pd_exec_time = HAL_GetTick() - start_ts;

  return hand_nb;
}

/**
 * @brief Initializes the Hand Landmark model.
 * @details This function gets memory addresses for the SECOND model's input and output
 * tensors, allowing the application to prepare the input and read the results.
 * @param info Pointer to the hand landmark model info structure to be filled.
 */
static void hand_landmark_init(hl_model_info_t *info)
{
  const LL_Buffer_InfoTypeDef *nn_out_info = LL_ATON_Output_Buffers_Info_hand_landmark();
  const LL_Buffer_InfoTypeDef *nn_in_info = LL_ATON_Input_Buffers_Info_hand_landmark();

  info->nn_in = LL_Buffer_addr_start(&nn_in_info[0]);
  info->nn_in_len = LL_Buffer_len(&nn_in_info[0]);
  info->prob_out = (float *) LL_Buffer_addr_start(&nn_out_info[2]);
  info->prob_out_len = LL_Buffer_len(&nn_out_info[2]);
  assert(info->prob_out_len == sizeof(float));
  info->landmarks_out = (float *) LL_Buffer_addr_start(&nn_out_info[3]);
  info->landmarks_out_len = LL_Buffer_len(&nn_out_info[3]);
  assert(info->landmarks_out_len == sizeof(float) * 63);
}


static void app_transform(nema_matrix3x3_t t, app_v3_t v)
{
  app_v3_t r;
  int i;

  for (i = 0; i < 3; i++)
    r[i] = t[i][0] * v[0] + t[i][1] * v[1] + t[i][2] * v[2];

  for (i = 0; i < 3; i++)
    v[i] = r[i];
}
/**
 * @brief Prepares the landmark model's input using the NEMA GPU.
 * @details This function offloads the entire crop, rotate, and resize operation to
 * the hardware accelerator. It builds a transformation matrix and submits it
 * to the GPU, which is much faster than the CPU-based version.
 * @return 0 on success.
 */
static int hand_landmark_prepare_input(uint8_t *buffer, roi_t *roi, hl_model_info_t *info)
{
  app_v3_t vertex[] = {
    {           0,             0, 1},
    {LCD_BG_WIDTH,             0, 1},
    {LCD_BG_WIDTH, LCD_BG_HEIGHT, 1},
    {           0, LCD_BG_HEIGHT, 1},
  };
  GFXMMU_BuffersTypeDef buffers = { 0 };
  nema_matrix3x3_t t;
  int ret;
  int i;

  buffers.Buf0Address = (uint32_t) info->nn_in;
  ret = HAL_GFXMMU_ModifyBuffers(&hgfxmmu, &buffers);
  assert(ret == HAL_OK);

  /* bind destination texture */
  nema_bind_dst_tex(GFXMMU_VIRTUAL_BUFFER0_BASE, LD_WIDTH, LD_HEIGHT, NEMA_RGBA8888, -1);
  nema_set_clip(0, 0, LD_WIDTH, LD_HEIGHT);
  nema_clear(0);
  /* bind source texture */
  nema_bind_src_tex((uintptr_t) buffer, LCD_BG_WIDTH, LCD_BG_HEIGHT, NEMA_RGBA8888, -1, NEMA_FILTER_BL);
  nema_enable_tiling(1);
  nema_set_blend_blit(NEMA_BL_SRC);

  /* let's go */
  nema_mat3x3_load_identity(t);
  nema_mat3x3_translate(t, -roi->cx, -roi->cy);
  nema_mat3x3_rotate(t, nema_rad_to_deg(-roi->rotation));
  nema_mat3x3_scale(t, LD_WIDTH / roi->w, LD_HEIGHT / roi->h);
  nema_mat3x3_translate(t, LD_WIDTH / 2, LD_HEIGHT / 2);
  for (i = 0 ; i < 4; i++)
    app_transform(t, vertex[i]);
  nema_blit_quad_fit(vertex[0][0], vertex[0][1], vertex[1][0], vertex[1][1],
                     vertex[2][0], vertex[2][1], vertex[3][0], vertex[3][1]);

  nema_cl_submit(&cl);
  nema_cl_wait(&cl);
  HAL_ICACHE_Invalidate();

  assert(!nema_get_error());

  return 0;
}

/**
 * @brief Runs one inference of the Hand Landmark model.
 * @param buffer Pointer to the source display buffer (for cropping).
 * @param info Pointer to the initialized landmark model info.
 * @param roi The Region of Interest to process.
 * @param ld_landmarks Output array to store the final landmark coordinates.
 * @return 1 if a hand was found and landmarks are valid, 0 otherwise.
 */
static int hand_landmark_run(uint8_t *buffer, hl_model_info_t *info, roi_t *roi,
                             ld_point_t ld_landmarks[LD_LANDMARK_NB])
{
  int is_clamped;
  int is_valid;

  is_clamped = hand_landmark_prepare_input(buffer, roi, info);
  CACHE_OP(SCB_CleanInvalidateDCache_by_Addr(info->nn_in, info->nn_in_len));
  if (is_clamped)
    return 0;

  LL_ATON_RT_Main(&NN_Instance_hand_landmark);

  is_valid = ld_post_process(info->prob_out, info->landmarks_out, ld_landmarks);

  /* Discard nn_out region (used by pp_input and pp_outputs variables) to avoid Dcache evictions during nn inference */
  CACHE_OP(SCB_InvalidateDCache_by_Addr(info->prob_out, info->prob_out_len));
  CACHE_OP(SCB_InvalidateDCache_by_Addr(info->landmarks_out, info->landmarks_out_len));

  return is_valid;
}


/**
 * @brief Initializes the NEMA GPU and its associated drivers.
 */
static void app_rot_init(hl_model_info_t *info)
{
  GFXMMU_PackingTypeDef packing = { 0 };
  int ret;

  printf("init nema\n");
  nema_init();
  assert(!nema_get_error());
  nema_ext_hold_enable(2);
  nema_ext_hold_irq_enable(2);
  nema_ext_hold_enable(3);
  nema_ext_hold_irq_enable(3);
  printf("init nema DONE %s\n", nema_get_sw_device_name());

  hgfxmmu.Instance = GFXMMU;
  hgfxmmu.Init.BlockSize = GFXMMU_12BYTE_BLOCKS;
  hgfxmmu.Init.AddressTranslation = DISABLE;
  ret = HAL_GFXMMU_Init(&hgfxmmu);
  assert(ret == HAL_OK);

  packing.Buffer0Activation = ENABLE;
  packing.Buffer0Mode       = GFXMMU_PACKING_MSB_REMOVE;
  packing.DefaultAlpha      = 0xff;
  ret = HAL_GFXMMU_ConfigPacking(&hgfxmmu, &packing);
  assert(ret == HAL_OK);

  cl = nema_cl_create_sized(8192);
  nema_cl_bind_circular(&cl);
}

/**
 * @brief Computes the rotation based on the final landmark points.
 * @details Uses landmark points 0 and 9 (e.g., wrist and middle finger base)
 * for a potentially more stable rotation estimate than the first model.
 */
static float ld_compute_rotation(ld_point_t lm[LD_LANDMARK_NB])
{
  float x0, y0, x1, y1;
  float rotation;

  x0 = lm[0].x;
  y0 = lm[0].y;
  x1 = lm[9].x;
  y1 = lm[9].y;

  rotation = M_PI * 0.5 - atan2f(-(y1 - y0), x1 - x0);

  return pd_cook_rotation(pd_normalize_angle(rotation));
}

/**
 * @brief Creates a new, tighter ROI based on the detected landmarks.
 * @details This is used to update the ROI for tracking in the next frame.
 */
static void ld_to_roi(ld_point_t lm[LD_LANDMARK_NB], roi_t *roi, pd_pp_box_t *next_pd)
{
  const int pd_to_ld_idx[AI_PD_MODEL_PP_NB_KEYPOINTS] = {0, 5, 9, 13, 17, 1, 2};
  const int indices[] = {0, 1, 2, 3, 5, 6, 9, 10, 13, 14, 17, 18};
  float max_x, max_y, min_x, min_y;
  int i;

  max_x = max_y = -10000;
  min_x = min_y =  10000;

  roi->rotation = ld_compute_rotation(lm);

  for (i = 0; i < ARRAY_NB(indices); i++) {
    max_x = MAX(max_x, lm[indices[i]].x);
    max_y = MAX(max_y, lm[indices[i]].y);
    min_x = MIN(min_x, lm[indices[i]].x);
    min_y = MIN(min_y, lm[indices[i]].y);
  }

  roi->cx = (max_x + min_x) / 2;
  roi->cy = (max_y + min_y) / 2;
  roi->w = (max_x - min_x);
  roi->h = (max_y - min_y);

  next_pd->x_center = roi->cx;
  next_pd->y_center = roi->cy;
  next_pd->width = roi->w;
  next_pd->height = roi->h;
  for (i = 0; i < AI_PD_MODEL_PP_NB_KEYPOINTS; i++) {
    next_pd->pKps[i].x = lm[pd_to_ld_idx[i]].x;
    next_pd->pKps[i].y = lm[pd_to_ld_idx[i]].y;
  }
}

/**
 * @brief Computes the predicted ROI for the next frame to enable tracking.
 * @details This is the core of the tracking logic. Instead of running the slow
 * detector on every frame, we use the landmarks from the current frame to predict
 * where the hand/face will be in the next frame. We then only need to run the
 * fast landmark model on that small predicted ROI.
 */
static void compute_next_roi(roi_t *src, ld_point_t lm_in[LD_LANDMARK_NB], roi_t *next, pd_pp_box_t *next_pd)
{
  const float shift_x = 0;
  const float shift_y = -0.1;
  const float scale = 2.0;
  ld_point_t lm[LD_LANDMARK_NB];
  roi_t roi;
  int i;

  for (i = 0; i < LD_LANDMARK_NB; i++)
    decode_ld_landmark(src, &lm_in[i], &lm[i]);

  ld_to_roi(lm, &roi, next_pd);
  roi_shift_and_scale(&roi, shift_x, shift_y, scale, scale);

  *next = roi;
}

/**
 * @brief The main function for the Neural Network processing thread.
 * @details This is the entry point for the FreeRTOS task that handles all AI inference.
 * It will contain a `while(1)` loop to process frames as they become available.
 */
static void nn_thread_fct_backup(void *arg)
{
  /* Variables for filtering/smoothing performance metrics. */
  float nn_period_filtered_ms = 0;
  float pd_filtered_ms = 0;
  float ld_filtered_ms = 0;

  /* Model-specific info structures. */
  hl_model_info_t hl_info;
  pd_model_info_t pd_info;
  yolo_model_info_t yolo_info;

  /* Timing variables. */
  uint32_t nn_period_ms;
  uint32_t nn_period[2];
  uint8_t *nn_pipe_dst;

  /* Structs for holding tracking information between frames. */
  pd_pp_point_t box_next_keypoints[AI_PD_MODEL_PP_NB_KEYPOINTS];
  pd_pp_box_t box_next;
  od_pp_out_t boxes_next[YOLO_MAX_NB];


  int is_tracking = 0;
  roi_t roi_next;
  uint32_t pd_ms;
  uint32_t hl_ms;
  uint32_t yolo_ms;
  uint32_t fl_ms;
  int ret;
  int j;
  int temp = 0;

  /* Current tracking algo only support single hand */
  assert(PD_MAX_HAND_NB == 1);

  /* setup models buffer info */
  palm_detector_init(&pd_info);
  box_next.pKps = box_next_keypoints;
  hand_landmark_init(&hl_info);
  app_rot_init(&hl_info);
  yolo_detector_init(&yolo_info);
  /*** Application Main Loop ***************************************************************/
  nn_period[1] = HAL_GetTick();

  /* Get an initial free buffer and start the camera's NN pipe. */
  nn_pipe_dst = bqueue_get_free(&nn_input_queue, 0);
  assert(nn_pipe_dst);
  CAM_NNPipe_Start(nn_pipe_dst, CMW_MODE_CONTINUOUS);
  while (1)
  {
    uint8_t *capture_buffer;
    int idx_for_resize;
    /* Measure and filter the time between loop iterations. */
    nn_period[0] = nn_period[1];
    nn_period[1] = HAL_GetTick();
    nn_period_ms = nn_period[1] - nn_period[0];
    nn_period_filtered_ms = USE_FILTERED_TS ? (15 * nn_period_filtered_ms + nn_period_ms) / 16 : nn_period_ms;
    
    /* Block and wait for a new NN frame to be ready from the camera. */
    capture_buffer = bqueue_get_ready(&nn_input_queue);
    assert(capture_buffer);
    idx_for_resize = frame_event_nb_for_resize % DISPLAY_BUFFER_NB;

    /* --- Core Tracking Logic --- */
    /* If we are NOT currently tracking an object, run the full-frame detector. */
    if (!is_tracking) {
      is_tracking = palm_detector_run(capture_buffer, &pd_info, &pd_ms);
      box_next.prob = pd_info.pd_out.pOutData[0].prob;
    } else {
      rois[0] = roi_next;
      copy_pd_box(&pd_info.pd_out.pOutData[0], &box_next);
      pd_ms = 0;
    }
    pd_filtered_ms = USE_FILTERED_TS ? (7 * pd_filtered_ms + pd_ms) / 8 : pd_ms;
    bqueue_put_free(&nn_input_queue);

    /* then run hand landmark detector if needed */
    if (is_tracking) {
      hl_ms = HAL_GetTick();
      /* Run the landmark model. Note it uses the main display buffer for cropping. */
      is_tracking = hand_landmark_run(lcd_bg_buffer[idx_for_resize], &hl_info, &rois[0], ld_landmarks[0]);
      /* Invalidate this buffer region as the CPU/GPU may have read from it. */
      CACHE_OP(SCB_InvalidateDCache_by_Addr(lcd_bg_buffer[idx_for_resize], sizeof(lcd_bg_buffer[idx_for_resize])));

      /* If landmarks were successfully found, predict the ROI for the NEXT frame. */
      if (is_tracking)
        compute_next_roi(&rois[0], ld_landmarks[0], &roi_next, &box_next);
      hl_ms = HAL_GetTick() - hl_ms;
    } else {
      /* If no object is being tracked, skip landmarking. */
      hl_ms = 0;
    }
    ld_filtered_ms = USE_FILTERED_TS ? (7 * ld_filtered_ms + hl_ms) / 8 : hl_ms;

    /* update display stats */
    ret = xSemaphoreTake(disp.lock, portMAX_DELAY);
    assert(ret == pdTRUE);
    disp.info.pd_ms = is_tracking ? 0 : (int)pd_filtered_ms;
    disp.info.hl_ms = is_tracking ? (int)ld_filtered_ms : 0;
    disp.info.nn_period_ms = nn_period_filtered_ms;
    disp.info.pd_hand_nb = is_tracking;
    disp.info.pd_max_prob = pd_info.pd_out.pOutData[0].prob;
    disp.info.hands[0].is_valid = is_tracking;
    copy_pd_box(&disp.info.hands[0].pd_hands, &pd_info.pd_out.pOutData[0]);
    disp.info.hands[0].roi = rois[0];
    for (j = 0; j < LD_LANDMARK_NB; j++)
      disp.info.hands[0].ld_landmarks[j] = ld_landmarks[0][j];
    ret = xSemaphoreGive(disp.lock);
    assert(ret == pdTRUE);

    /* It's possible xqueue is empty if display is slow. So don't check error code that may by pdFALSE in that case */
    xSemaphoreGive(disp.update);
  }
}

static void nn_thread_fct(void *arg)
{
  /* Variables for filtering/smoothing performance metrics. */
  float nn_period_filtered_ms = 0;
  float pd_filtered_ms = 0;
  float ld_filtered_ms = 0;

  /* Model-specific info structures. */
  //hl_model_info_t hl_info; // Disabled
  // pd_model_info_t pd_info; // Disabled
  yolo_model_info_t yolo_info; // Disabled
  fl_model_info_t fl_info;
  /* Timing variables. */
  uint32_t nn_period_ms;
  uint32_t nn_period[2];
  uint8_t *nn_pipe_dst;

  /* Structs for holding tracking information between frames. */
  pd_pp_point_t box_next_keypoints[AI_PD_MODEL_PP_NB_KEYPOINTS];
  pd_pp_box_t box_next;
  od_pp_out_t boxes_next[YOLO_MAX_NB]; // Unused for now


  int is_tracking = 0;
  roi_t roi_next;
  uint32_t pd_ms;
  uint32_t hl_ms;
  uint32_t yolo_ms;
  // uint32_t fl_ms; // Unused for now
  int ret;
  int j;
  // int temp = 0; // Unused for now

  /* Current tracking algo only support single hand */
  assert(PD_MAX_HAND_NB == 1);

  /* setup models buffer info */
  // palm_detector_init(&pd_info); // Disabled
  box_next.pKps = box_next_keypoints;
  // hand_landmark_init(&hl_info); // Disabled
  //app_rot_init(&hl_info);       // Disabled
  yolo_detector_init(&yolo_info); // Disabled
  face_landmark_init(&fl_info);
  /*** Application Main Loop ***************************************************************/
  nn_period[1] = HAL_GetTick();

  /* Get an initial free buffer and start the camera's NN pipe. */
  nn_pipe_dst = bqueue_get_free(&nn_input_queue, 0);
  assert(nn_pipe_dst);
  CAM_NNPipe_Start(nn_pipe_dst, CMW_MODE_CONTINUOUS);
  while (1)
  {
    uint8_t *capture_buffer;
    int idx_for_resize;
    /* Measure and filter the time between loop iterations. */
    nn_period[0] = nn_period[1];
    nn_period[1] = HAL_GetTick();
    nn_period_ms = nn_period[1] - nn_period[0];
    nn_period_filtered_ms = USE_FILTERED_TS ? (15 * nn_period_filtered_ms + nn_period_ms) / 16 : nn_period_ms;
    
    /* Block and wait for a new NN frame to be ready from the camera. */
    capture_buffer = bqueue_get_ready(&nn_input_queue);
    assert(capture_buffer);
    idx_for_resize = frame_event_nb_for_resize % DISPLAY_BUFFER_NB;

    /* --- Core Tracking Logic --- */
    /* If we are NOT currently tracking an object, run the full-frame detector. */
    if (!is_tracking) {
      /* --- ALL MODEL CALLS ARE REMOVED FOR THIS TEST --- */
      int nb_faces = yolo_detector_run(capture_buffer, &yolo_info, &yolo_ms);
      LL_ATON_RT_Main(&NN_Instance_face_landmark);
      /* --- Force tracking to be ON and create a dummy box --- */
      is_tracking = 0;
      pd_ms = 0; // Set dummy timing
    } else {
      rois[0] = roi_next;
      // copy_pd_box(&pd_info.pd_out.pOutData[0], &box_next); // Disabled
      pd_ms = 0;
    }
    pd_filtered_ms = USE_FILTERED_TS ? (7 * pd_filtered_ms + pd_ms) / 8 : pd_ms;
    bqueue_put_free(&nn_input_queue);

    /* then run hand landmark detector if needed */
    if (is_tracking) {
      /* --- Hand landmarking is disabled for this test --- */
      hl_ms = 0; // Set to 0 since it's disabled
    } else {
      /* If no object is being tracked, skip landmarking. */
      hl_ms = 0;
    }
    ld_filtered_ms = USE_FILTERED_TS ? (7 * ld_filtered_ms + hl_ms) / 8 : hl_ms;

    /* update display stats */
    ret = xSemaphoreTake(disp.lock, portMAX_DELAY);
    assert(ret == pdTRUE);
    disp.info.pd_ms = is_tracking ? 0 : (int)pd_filtered_ms; /* This will now show 0 */
    disp.info.hl_ms = (int)ld_filtered_ms; /* This will be 0 */
    disp.info.nn_period_ms = nn_period_filtered_ms;
    disp.info.pd_hand_nb = is_tracking; /* This will show 1 */
    disp.info.pd_max_prob = 0.0f; /* Dummy data */
    disp.info.hands[0].is_valid = is_tracking;
    // copy_pd_box(&disp.info.hands[0].pd_hands, &pd_info.pd_out.pOutData[0]); // Disabled
    if (is_tracking)
    {
      disp.info.hands[0].roi = rois[0]; /* Show the dummy ROI */
    }
    /* Landmark drawing is disabled */
    // for (j = 0; j < LD_LANDMARK_NB; j++)
    //   disp.info.hands[0].ld_landmarks[j] = ld_landmarks[0][j];
    ret = xSemaphoreGive(disp.lock);
    assert(ret == pdTRUE);

    /* It's possible xqueue is empty if display is slow. So don't check error code that may by pdFALSE in that case */
    xSemaphoreGive(disp.update);
  }
}

/**
 * @brief Sets the memory address for the foreground layer for the next draw operation.
 * @details Part of a double-buffering scheme for the UI overlay. This function prepares
 * the off-screen buffer for drawing.
 */
static void dp_update_drawing_area()
{
  int ret;

  __disable_irq();
  ret = SCRL_SetAddress_NoReload(lcd_fg_buffer[lcd_fg_buffer_rd_idx], SCRL_LAYER_1);
  assert(ret == HAL_OK);
  __enable_irq();
}

/**
 * @brief Commits the newly drawn foreground buffer to the display.
 * @details This "flips" the foreground buffers, making the newly drawn UI visible.
 */
static void dp_commit_drawing_area()
{
  int ret;

  __disable_irq();
  ret = SCRL_ReloadLayer(SCRL_LAYER_1);
  assert(ret == HAL_OK);
  __enable_irq();
  lcd_fg_buffer_rd_idx = 1 - lcd_fg_buffer_rd_idx;
}

/**
 * @brief Callback function to toggle the landmark display.
 */
static void on_ld_toggle_button_click(void *args)
{
  display_t *disp = (display_t *) args;
  int ret;

  ret = xSemaphoreTake(disp->lock, portMAX_DELAY);
  assert(ret == pdTRUE);
  disp->info.is_ld_displayed = !disp->info.is_ld_displayed;
  ret = xSemaphoreGive(disp->lock);
  assert(ret == pdTRUE);
}

/**
 * @brief Callback function to toggle the bounding box display.
 */
static void on_pd_toggle_button_click(void *args)
{
  display_t *disp = (display_t *) args;
  int ret;

  ret = xSemaphoreTake(disp->lock, portMAX_DELAY);
  assert(ret == pdTRUE);
  disp->info.is_pd_displayed = !disp->info.is_pd_displayed;
  ret = xSemaphoreGive(disp->lock);
  assert(ret == pdTRUE);
}

/**
 * @brief The main function for the Display Processor (DP) thread.
 * @details This task waits for a signal from the NN thread, then wakes up to
 * draw the entire UI overlay for one frame.
 */
static void dp_thread_fct(void *arg)
{
  button_t ld_toggle_button;
  button_t hd_toggle_button;
  uint32_t disp_ms = 0;
  display_info_t info;
  uint32_t ts;
  int ret;

#ifdef STM32N6570_DK_REV
  button_init(&ld_toggle_button, BUTTON_USER1, on_ld_toggle_button_click, &disp);
  button_init(&hd_toggle_button, BUTTON_TAMP, on_pd_toggle_button_click, &disp);
#else
  button_init(&ld_toggle_button, BUTTON_USER, on_ld_toggle_button_click, &disp);
  button_init(&hd_toggle_button, BUTTON_USER, on_pd_toggle_button_click, &disp);
#endif
  while (1)
  {
    ret = xSemaphoreTake(disp.update, portMAX_DELAY);
    assert(ret == pdTRUE);

    button_process(&ld_toggle_button);
    button_process(&hd_toggle_button);

    ret = xSemaphoreTake(disp.lock, portMAX_DELAY);
    assert(ret == pdTRUE);
    info = disp.info;
    ret = xSemaphoreGive(disp.lock);
    assert(ret == pdTRUE);
    info.disp_ms = disp_ms;

    ts = HAL_GetTick();
    dp_update_drawing_area();
    Display_NetworkOutput(&info);
    SCB_CleanDCache_by_Addr(lcd_fg_buffer[lcd_fg_buffer_rd_idx], LCD_FG_WIDTH * LCD_FG_HEIGHT* 2);
    dp_commit_drawing_area();
    disp_ms = HAL_GetTick() - ts;
  }
}

/**
 * @brief The main function for the Image Signal Processor (ISP) thread.
 * @details This task waits for the VSYNC signal and then runs the camera's
 * periodic processing functions (e.g., auto-exposure, auto-white-balance).
 */
static void isp_thread_fct(void *arg)
{
  int ret;

  while (1) {
    ret = xSemaphoreTake(isp_sem, portMAX_DELAY);
    assert(ret == pdTRUE);

    CAM_IspUpdate();
  }
}

/**
 * @brief Initializes the display controller (SCRL) and graphics library (UTIL_LCD).
 * @details Configures the two screen layers: Layer 0 for the background video and
 * Layer 1 for the transparent UI overlay.
 */
static void Display_init()
{
  SCRL_LayerConfig layers_config[2] = {
    {
      .origin = {lcd_bg_area.X0, lcd_bg_area.Y0},
      .size = {lcd_bg_area.XSize, lcd_bg_area.YSize},
      .format = SCRL_ARGB8888,
      .address = lcd_bg_buffer[lcd_bg_buffer_disp_idx],
    },
    {
      .origin = {lcd_fg_area.X0, lcd_fg_area.Y0},
      .size = {lcd_fg_area.XSize, lcd_fg_area.YSize},
      .format = SCRL_ARGB4444,
      .address = lcd_fg_buffer[1],
    },
  };
  SCRL_ScreenConfig screen_config = {
    .size = {lcd_bg_area.XSize, lcd_bg_area.YSize},
#ifdef SCR_LIB_USE_SPI
    .format = SCRL_RGB565,
#else
     .format = SCRL_YUV422, /* Use SCRL_RGB565 if host support this format to reduce cpu load */
#endif
    .address = screen_buffer,
    .fps = CAMERA_FPS,
  };
  int ret;

  ret = SCRL_Init((SCRL_LayerConfig *[2]){&layers_config[0], &layers_config[1]}, &screen_config);
  assert(ret == 0);

  UTIL_LCD_SetLayer(SCRL_LAYER_1);
  UTIL_LCD_Clear(UTIL_LCD_COLOR_TRANSPARENT);
  UTIL_LCD_SetFont(&LCD_FONT);
  UTIL_LCD_SetTextColor(UTIL_LCD_COLOR_WHITE);
}

/**
 * @brief Main application entry point.
 * @details Initializes all hardware, software modules, and RTOS components,
 * then creates the three main application threads.
 */
void app_run()
{
  UBaseType_t isp_priority = FREERTOS_PRIORITY(2);
  UBaseType_t dp_priority = FREERTOS_PRIORITY(-2);
  UBaseType_t nn_priority = FREERTOS_PRIORITY(1);
  TaskHandle_t hdl;
  int ret;

  printf("Init application\n");
  /* Enable DWT so DWT_CYCCNT works when debugger not attached */
  CoreDebug->DEMCR |= CoreDebug_DEMCR_TRCENA_Msk;

  /* screen init */
  memset(lcd_bg_buffer, 0, sizeof(lcd_bg_buffer));
  CACHE_OP(SCB_CleanInvalidateDCache_by_Addr(lcd_bg_buffer, sizeof(lcd_bg_buffer)));
  memset(lcd_fg_buffer, 0, sizeof(lcd_fg_buffer));
  CACHE_OP(SCB_CleanInvalidateDCache_by_Addr(lcd_fg_buffer, sizeof(lcd_fg_buffer)));
  Display_init();

  /* create buffer queues */
  ret = bqueue_init(&nn_input_queue, 2, (uint8_t *[2]){nn_input_buffers[0], nn_input_buffers[1]});
  assert(ret == 0);

  cpuload_init(&cpu_load);

  /*** Camera Init ************************************************************/  
  CAM_Init();

  /* sems + mutex init */
  isp_sem = xSemaphoreCreateCountingStatic(1, 0, &isp_sem_buffer);
  assert(isp_sem);
  disp.update = xSemaphoreCreateCountingStatic(1, 0, &disp.update_buffer);
  assert(disp.update);
  disp.lock = xSemaphoreCreateMutexStatic(&disp.lock_buffer);
  assert(disp.lock);

  /* Start LCD Display camera pipe stream */
  CAM_DisplayPipe_Start(lcd_bg_buffer[0], CMW_MODE_CONTINUOUS);

  /* threads init */
  hdl = xTaskCreateStatic(nn_thread_fct, "nn", configMINIMAL_STACK_SIZE * 2, NULL, nn_priority, nn_thread_stack,
                          &nn_thread);
  assert(hdl != NULL);
  hdl = xTaskCreateStatic(dp_thread_fct, "dp", configMINIMAL_STACK_SIZE * 2, NULL, dp_priority, dp_thread_stack,
                          &dp_thread);
  assert(hdl != NULL);
  hdl = xTaskCreateStatic(isp_thread_fct, "isp", configMINIMAL_STACK_SIZE * 2, NULL, isp_priority, isp_thread_stack,
                          &isp_thread);
  assert(hdl != NULL);
}

/**
 * @brief System-level callback registered with the camera driver for frame events.
 * @details This function is called from an Interrupt Service Routine (ISR) and
 * routes the event to the appropriate application-level handler.
 */
int CMW_CAMERA_PIPE_FrameEventCallback(uint32_t pipe)
{
  if (pipe == DCMIPP_PIPE1)
    app_main_pipe_frame_event();
  else if (pipe == DCMIPP_PIPE2)
    app_ancillary_pipe_frame_event();

  return HAL_OK;
}

/**
 * @brief System-level callback for VSYNC events.
 */
int CMW_CAMERA_PIPE_VsyncEventCallback(uint32_t pipe)
{
  if (pipe == DCMIPP_PIPE1)
    app_main_pipe_vsync_event();

  return HAL_OK;
}
