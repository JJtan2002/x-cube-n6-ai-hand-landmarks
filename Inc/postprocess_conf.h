/*---------------------------------------------------------------------------------------------
#  * Copyright (c) 2023 STMicroelectronics.
#  * All rights reserved.
#  *
#  * This software is licensed under terms that can be found in the LICENSE file in
#  * the root directory of this software component.
#  * If no LICENSE file comes with this software, it is provided AS-IS.
#  *--------------------------------------------------------------------------------------------*/

/* ---------------    Generated code    ----------------- */
#ifndef __POSTPROCESS_CONF_H__
#define __POSTPROCESS_CONF_H__


#ifdef __cplusplus
  extern "C" {
#endif

#include "arm_math.h"

/* Select palm detector postprocess */
#define POSTPROCESS_TYPE POSTPROCESS_OD_YOLO_V8_UF

/* I/O configuration */
#define AI_PD_MODEL_PP_WIDTH                      (192)
#define AI_PD_MODEL_PP_HEIGHT                     (192)
#define AI_PD_MODEL_PP_TOTAL_DETECTIONS           (2016)
#define AI_PD_MODEL_PP_NB_KEYPOINTS               (7)

/* --------  Tuning below can be modified by the application --------- */
#define AI_PD_MODEL_PP_CONF_THRESHOLD              (0.5f)
#define AI_PD_MODEL_PP_IOU_THRESHOLD               (0.4f)
#define AI_PD_MODEL_PP_MAX_BOXES_LIMIT             (20)


#define AI_OD_YOLOV8_PP_NB_CLASSES              (3)      /* E.g., 0:hand, 1:person, 2:face */
#define AI_OD_YOLOV8_PP_TOTAL_BOXES             (2100)   /* Total number of bounding boxes the model outputs (e.g., for YOLOv8n) */

/* --- Post-Processing Tuning --- */
/* These values can be tuned to adjust detection sensitivity and filtering. */
#define AI_OD_YOLOV8_PP_MAX_BOXES_LIMIT         (20)     /* The maximum number of objects to detect after NMS. */
#define AI_OD_YOLOV8_PP_CONF_THRESHOLD          (0.5f)   /* Minimum confidence score for a detection to be considered valid. */
#define AI_OD_YOLOV8_PP_IOU_THRESHOLD           (0.45f)  /* Intersection over Union threshold for Non-Maximal Suppression (NMS). */

/* --- Dequantization Parameters --- */
/* IMPORTANT: These values MUST match the quantization parameters of your specific .tflite model. */
/* You can find these values using a tool like Netron. */
#define AI_OD_YOLOV8_PP_SCALE                   (0.004235264845192432f) /* Example value: Replace with your model's output tensor scale. */
#define AI_OD_YOLOV8_PP_ZERO_POINT              (-128)      /* Example value: Replace with your model's output tensor zero-point. */

#endif      /* __POSTPROCESS_CONF_H__  */

