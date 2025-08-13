/**
  ******************************************************************************
  * @file    yolo_detector.h
  * @author  STEdgeAI
  * @date    2025-08-13 10:00:35
  * @brief   Minimal description of the generated c-implemention of the network
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  ******************************************************************************
  */
#ifndef LL_ATON_YOLO_DETECTOR_H
#define LL_ATON_YOLO_DETECTOR_H

/******************************************************************************/
#define LL_ATON_YOLO_DETECTOR_C_MODEL_NAME        "yolo_detector"
#define LL_ATON_YOLO_DETECTOR_ORIGIN_MODEL_NAME   "yolov8_face_call_smk_integer_quant"

/************************** USER ALLOCATED IOs ********************************/
#define LL_ATON_YOLO_DETECTOR_USER_ALLOCATED_INPUTS   (1)  // Number of input buffers not allocated by the compiler
#define LL_ATON_YOLO_DETECTOR_USER_ALLOCATED_OUTPUTS  (1)  // Number of output buffers not allocated by the compiler

/************************** INPUTS ********************************************/
#define LL_ATON_YOLO_DETECTOR_IN_NUM        (1)    // Total number of input buffers
// Input buffer 1 -- Input_4_out_0
#define LL_ATON_YOLO_DETECTOR_IN_1_ALIGNMENT   (32)
#define LL_ATON_YOLO_DETECTOR_IN_1_SIZE_BYTES  (1228800)

/************************** OUTPUTS *******************************************/
#define LL_ATON_YOLO_DETECTOR_OUT_NUM        (1)    // Total number of output buffers
// Output buffer 1 -- Transpose_1228_out_0
#define LL_ATON_YOLO_DETECTOR_OUT_1_ALIGNMENT   (32)
#define LL_ATON_YOLO_DETECTOR_OUT_1_SIZE_BYTES  (58800)

#endif /* LL_ATON_YOLO_DETECTOR_H */
