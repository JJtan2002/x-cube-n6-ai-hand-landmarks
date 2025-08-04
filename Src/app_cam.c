 /**
 ******************************************************************************
 * @file    app_cam.c
 * @author  GPM Application Team
 *
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2023 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */
#include <assert.h>
#include "app.h"
#include "cmw_camera.h"
#include "app_cam.h"
#include "app_config.h"
#include "utils.h"

/**
 * @brief Calculates the correct crop window to maintain aspect ratio.
 * @details This function takes the raw sensor dimensions and the target output dimensions.
 * It calculates a centered crop region on the sensor that matches the
 * target's aspect ratio. This prevents the final image from looking
 * stretched or squashed.
 * @param roi Pointer to the region-of-interest structure to be filled.
 * @param sensor_width The full width of the camera sensor.
 * @param sensor_height The full height of the camera sensor.
 */
static void CAM_InitCropConfig(CMW_Manual_roi_area_t *roi, int sensor_width, int sensor_height)
{
  const float ratiox = (float)sensor_width / LCD_BG_WIDTH;
  const float ratioy = (float)sensor_height / LCD_BG_HEIGHT;
  const float ratio = MIN(ratiox, ratioy);

  assert(ratio >= 1);
  assert(ratio < 64);

  roi->width = (uint32_t) MIN(LCD_BG_WIDTH * ratio, sensor_width);
  roi->height = (uint32_t) MIN(LCD_BG_HEIGHT * ratio, sensor_height);
  roi->offset_x = (sensor_width - roi->width + 1) / 2;
  roi->offset_y = (sensor_height - roi->height + 1) / 2;
}

/**
 * @brief Configures the DCMIPP's main pipe for the display.
 * @details This sets up the hardware pipeline (Pipe 1) that takes the camera
 * data, resizes it to match the LCD resolution (e.g., 800x480),
 * and prepares it for display.
 * @param sensor_width The full width of the camera sensor.
 * @param sensor_height The full height of the camera sensor.
 */
static void DCMIPP_PipeInitDisplay(int sensor_width, int sensor_height)
{
  CMW_DCMIPP_Conf_t dcmipp_conf;
  uint32_t hw_pitch;
  int ret;

  assert(LCD_BG_WIDTH >= LCD_BG_HEIGHT);

  dcmipp_conf.output_width = LCD_BG_WIDTH;
  dcmipp_conf.output_height = LCD_BG_HEIGHT;
  dcmipp_conf.output_format = DISPLAY_FORMAT;
  dcmipp_conf.output_bpp = DISPLAY_BPP;
  dcmipp_conf.mode = CMW_Aspect_ratio_manual_roi;
  dcmipp_conf.enable_swap = 1;
  dcmipp_conf.enable_gamma_conversion = 0;

  /* Calculate the sensor crop window to maintain the display's aspect ratio. */
  CAM_InitCropConfig(&dcmipp_conf.manual_conf, sensor_width, sensor_height);
  
  /* Send the final configuration to the hardware driver for Pipe 1. */
  ret = CMW_CAMERA_SetPipeConfig(DCMIPP_PIPE1, &dcmipp_conf, &hw_pitch);
  assert(ret == HAL_OK);
  assert(hw_pitch == dcmipp_conf.output_width * dcmipp_conf.output_bpp);
}

/**
 * @brief Configures the DCMIPP's ancillary pipe for the Neural Network.
 * @details This sets up the hardware pipeline (Pipe 2) that creates a smaller,
 * dedicated video stream to be used as input for the first AI model.
 * *** FUNCTION TO MODIFY FOR DMS ***
 * @param sensor_width The full width of the camera sensor.
 * @param sensor_height The full height of the camera sensor.
 */
static void DCMIPP_PipeInitNn(int sensor_width, int sensor_height)
{
  CMW_DCMIPP_Conf_t dcmipp_conf;
  uint32_t hw_pitch;
  int ret;

  assert(LCD_BG_HEIGHT <= LCD_BG_WIDTH);
  /* Define the properties for the NN input image. Change NN_WIDTH, NN_HEIGHT, etc.,
    in app_config.h to match your face detector's requirements (e.g., 224x224). */
  dcmipp_conf.output_width = NN_WIDTH;

  /* This line adjusts the height to match the screen's aspect ratio. This prevents
    distortion and ensures AI coordinates map correctly to the display. If your model
    needs a perfect square input, this may result in black bars (padding). */
  dcmipp_conf.output_height = (int) (NN_HEIGHT * ((float)LCD_BG_HEIGHT / LCD_BG_WIDTH));
  dcmipp_conf.output_format = NN_FORMAT;
  dcmipp_conf.output_bpp = NN_BPP;
  dcmipp_conf.mode = CMW_Aspect_ratio_manual_roi;
  dcmipp_conf.enable_swap = 1;
  dcmipp_conf.enable_gamma_conversion = 0;
  
  /* Calculate the sensor crop window to maintain the NN input's aspect ratio. */
  CAM_InitCropConfig(&dcmipp_conf.manual_conf, sensor_width, sensor_height);

  /* Send the final configuration to the hardware driver for Pipe 2. */
  ret = CMW_CAMERA_SetPipeConfig(DCMIPP_PIPE2, &dcmipp_conf, &hw_pitch);
  assert(ret == HAL_OK);
  assert(hw_pitch == dcmipp_conf.output_width * dcmipp_conf.output_bpp);
}

/**
 * @brief Initializes the entire camera system.
 * @details This is the main entry point. It powers up the camera sensor and then
 * configures both the display and NN hardware pipelines.
 */
void CAM_Init(void)
{
  CMW_CameraInit_t cam_conf;
  int ret;

  /* Let sensor driver choose which width/height to use */
  cam_conf.width = 0;
  cam_conf.height = 0;
  cam_conf.fps = CAMERA_FPS;
  cam_conf.pixel_format = 0; /* Default; Not implemented yet */
  cam_conf.anti_flicker = 0;
  cam_conf.mirror_flip = CAMERA_FLIP;
  ret = CMW_CAMERA_Init(&cam_conf);
  assert(ret == CMW_ERROR_NONE);

  /* Now that we have the actual sensor resolution, configure the two DCMIPP pipelines. */
  DCMIPP_PipeInitDisplay(cam_conf.width, cam_conf.height);
  DCMIPP_PipeInitNn(cam_conf.width, cam_conf.height);
}

/**
 * @brief Starts the video stream for the display pipe.
 * @param display_pipe_dst Pointer to the destination buffer for the display frames.
 * @param cam_mode The camera mode (e.g., continuous streaming).
 */
void CAM_DisplayPipe_Start(uint8_t *display_pipe_dst, uint32_t cam_mode)
{
  int ret;

  ret = CMW_CAMERA_Start(DCMIPP_PIPE1, display_pipe_dst, cam_mode);
  assert(ret == CMW_ERROR_NONE);
}

/**
 * @brief Starts the video stream for the NN input pipe.
 * @param nn_pipe_dst Pointer to the destination buffer for the AI model's input frames.
 * @param cam_mode The camera mode (e.g., continuous streaming).
 */
void CAM_NNPipe_Start(uint8_t *nn_pipe_dst, uint32_t cam_mode)
{
  int ret;

  ret = CMW_CAMERA_Start(DCMIPP_PIPE2, nn_pipe_dst, cam_mode);
  assert(ret == CMW_ERROR_NONE);
}

/**
 * @brief Main processing loop function for the camera.
 * @details This function should be called periodically (e.g., in your main while loop).
 * It runs the camera's internal Image Signal Processing (ISP) tasks,
 * such as auto-white-balance and auto-exposure.
 */
void CAM_IspUpdate(void)
{
  int ret;

  ret = CMW_CAMERA_Run();
  assert(ret == CMW_ERROR_NONE);
}
