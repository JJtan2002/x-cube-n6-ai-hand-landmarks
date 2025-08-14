/**
  ******************************************************************************
  * @file    face_landmark.h
  * @author  STEdgeAI
  * @date    2025-08-14 16:48:09
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
#ifndef LL_ATON_FACE_LANDMARK_H
#define LL_ATON_FACE_LANDMARK_H

/******************************************************************************/
#define LL_ATON_FACE_LANDMARK_C_MODEL_NAME        "face_landmark"
#define LL_ATON_FACE_LANDMARK_ORIGIN_MODEL_NAME   "face_landmark_ptq"

/************************** USER ALLOCATED IOs ********************************/
// No user allocated inputs
// No user allocated outputs

/************************** INPUTS ********************************************/
#define LL_ATON_FACE_LANDMARK_IN_NUM        (1)    // Total number of input buffers
// Input buffer 1 -- Input_0_out_0
#define LL_ATON_FACE_LANDMARK_IN_1_ALIGNMENT   (32)
#define LL_ATON_FACE_LANDMARK_IN_1_SIZE_BYTES  (110592)

/************************** OUTPUTS *******************************************/
#define LL_ATON_FACE_LANDMARK_OUT_NUM        (2)    // Total number of output buffers
// Output buffer 1 -- Transpose_191_out_0
#define LL_ATON_FACE_LANDMARK_OUT_1_ALIGNMENT   (32)
#define LL_ATON_FACE_LANDMARK_OUT_1_SIZE_BYTES  (1)
// Output buffer 2 -- Transpose_238_out_0
#define LL_ATON_FACE_LANDMARK_OUT_2_ALIGNMENT   (32)
#define LL_ATON_FACE_LANDMARK_OUT_2_SIZE_BYTES  (1404)

#endif /* LL_ATON_FACE_LANDMARK_H */
