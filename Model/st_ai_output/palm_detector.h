/**
  ******************************************************************************
  * @file    palm_detector.h
  * @author  STEdgeAI
  * @date    2025-08-13 10:10:13
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
#ifndef LL_ATON_PALM_DETECTOR_H
#define LL_ATON_PALM_DETECTOR_H

/******************************************************************************/
#define LL_ATON_PALM_DETECTOR_C_MODEL_NAME        "palm_detector"
#define LL_ATON_PALM_DETECTOR_ORIGIN_MODEL_NAME   "node_033_palm_detection_full_quant_pc_uf_od"

/************************** USER ALLOCATED IOs ********************************/
#define LL_ATON_PALM_DETECTOR_USER_ALLOCATED_INPUTS   (1)  // Number of input buffers not allocated by the compiler
// No user allocated outputs

/************************** INPUTS ********************************************/
#define LL_ATON_PALM_DETECTOR_IN_NUM        (1)    // Total number of input buffers
// Input buffer 1 -- Input_0_out_0
#define LL_ATON_PALM_DETECTOR_IN_1_ALIGNMENT   (32)
#define LL_ATON_PALM_DETECTOR_IN_1_SIZE_BYTES  (110592)

/************************** OUTPUTS *******************************************/
#define LL_ATON_PALM_DETECTOR_OUT_NUM        (2)    // Total number of output buffers
// Output buffer 1 -- Transpose_351_out_0
#define LL_ATON_PALM_DETECTOR_OUT_1_ALIGNMENT   (32)
#define LL_ATON_PALM_DETECTOR_OUT_1_SIZE_BYTES  (8064)
// Output buffer 2 -- Transpose_341_out_0
#define LL_ATON_PALM_DETECTOR_OUT_2_ALIGNMENT   (32)
#define LL_ATON_PALM_DETECTOR_OUT_2_SIZE_BYTES  (145152)

#endif /* LL_ATON_PALM_DETECTOR_H */
