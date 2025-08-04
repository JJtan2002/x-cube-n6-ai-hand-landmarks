/**
  ******************************************************************************
  * @file    yolov8_detector.c
  * @author  AST Embedded Analytics Research Platform
  * @date    2025-07-30T14:28:46+0800
  * @brief   AI Tool Automatic Code Generator for Embedded NN computing
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


#include "yolov8_detector.h"
#include "yolov8_detector_data.h"

#include "ai_platform.h"
#include "ai_platform_interface.h"
#include "ai_math_helpers.h"

#include "core_common.h"
#include "core_convert.h"

#include "layers.h"



#undef AI_NET_OBJ_INSTANCE
#define AI_NET_OBJ_INSTANCE g_yolov8_detector
 
#undef AI_YOLOV8_DETECTOR_MODEL_SIGNATURE
#define AI_YOLOV8_DETECTOR_MODEL_SIGNATURE     "0x1da2d34a7e9356effc72431a4dcbd743"

#ifndef AI_TOOLS_REVISION_ID
#define AI_TOOLS_REVISION_ID     ""
#endif

#undef AI_TOOLS_DATE_TIME
#define AI_TOOLS_DATE_TIME   "2025-07-30T14:28:46+0800"

#undef AI_TOOLS_COMPILE_TIME
#define AI_TOOLS_COMPILE_TIME    __DATE__ " " __TIME__

#undef AI_YOLOV8_DETECTOR_N_BATCHES
#define AI_YOLOV8_DETECTOR_N_BATCHES         (1)

static ai_ptr g_yolov8_detector_activations_map[1] = AI_C_ARRAY_INIT;
static ai_ptr g_yolov8_detector_weights_map[1] = AI_C_ARRAY_INIT;



/**  Array declarations section  **********************************************/
/* Array#0 */
AI_ARRAY_OBJ_DECLARE(
  serving_default_images0_output_array, AI_ARRAY_FORMAT_S8|AI_FMT_FLAG_IS_IO,
  NULL, NULL, 307201, AI_STATIC)

/* Array#1 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_1_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 409600, AI_STATIC)

/* Array#2 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_5_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 409600, AI_STATIC)

/* Array#3 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_6_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 409600, AI_STATIC)

/* Array#4 */
AI_ARRAY_OBJ_DECLARE(
  nl_2_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 409600, AI_STATIC)

/* Array#5 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_3_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 409600, AI_STATIC)

/* Array#6 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_4_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 409600, AI_STATIC)

/* Array#7 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_7_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 409600, AI_STATIC)

/* Array#8 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_9_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 204800, AI_STATIC)

/* Array#9 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_13_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 204800, AI_STATIC)

/* Array#10 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_14_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 204800, AI_STATIC)

/* Array#11 */
AI_ARRAY_OBJ_DECLARE(
  nl_10_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 204800, AI_STATIC)

/* Array#12 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_11_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 204800, AI_STATIC)

/* Array#13 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_12_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 204800, AI_STATIC)

/* Array#14 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_15_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 204800, AI_STATIC)

/* Array#15 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_16_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 204800, AI_STATIC)

/* Array#16 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_20_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 204800, AI_STATIC)

/* Array#17 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_21_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 204800, AI_STATIC)

/* Array#18 */
AI_ARRAY_OBJ_DECLARE(
  nl_17_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 204800, AI_STATIC)

/* Array#19 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_18_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 204800, AI_STATIC)

/* Array#20 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_19_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 204800, AI_STATIC)

/* Array#21 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_22_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 204800, AI_STATIC)

/* Array#22 */
AI_ARRAY_OBJ_DECLARE(
  slice_39_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 102400, AI_STATIC)

/* Array#23 */
AI_ARRAY_OBJ_DECLARE(
  slice_23_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 102400, AI_STATIC)

/* Array#24 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_24_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 102400, AI_STATIC)

/* Array#25 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_28_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 102400, AI_STATIC)

/* Array#26 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_29_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 102400, AI_STATIC)

/* Array#27 */
AI_ARRAY_OBJ_DECLARE(
  nl_25_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 102400, AI_STATIC)

/* Array#28 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_26_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 102400, AI_STATIC)

/* Array#29 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_27_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 102400, AI_STATIC)

/* Array#30 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_30_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 102400, AI_STATIC)

/* Array#31 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_31_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 102400, AI_STATIC)

/* Array#32 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_35_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 102400, AI_STATIC)

/* Array#33 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_36_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 102400, AI_STATIC)

/* Array#34 */
AI_ARRAY_OBJ_DECLARE(
  nl_32_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 102400, AI_STATIC)

/* Array#35 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_33_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 102400, AI_STATIC)

/* Array#36 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_34_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 102400, AI_STATIC)

/* Array#37 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_37_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 102400, AI_STATIC)

/* Array#38 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_38_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 102400, AI_STATIC)

/* Array#39 */
AI_ARRAY_OBJ_DECLARE(
  concat_40_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 307200, AI_STATIC)

/* Array#40 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_41_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 204800, AI_STATIC)

/* Array#41 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_45_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 204800, AI_STATIC)

/* Array#42 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_46_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 204800, AI_STATIC)

/* Array#43 */
AI_ARRAY_OBJ_DECLARE(
  nl_42_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 204800, AI_STATIC)

/* Array#44 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_43_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 204800, AI_STATIC)

/* Array#45 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_44_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 204800, AI_STATIC)

/* Array#46 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_47_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 204800, AI_STATIC)

/* Array#47 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_49_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 102400, AI_STATIC)

/* Array#48 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_53_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 102400, AI_STATIC)

/* Array#49 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_54_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 102400, AI_STATIC)

/* Array#50 */
AI_ARRAY_OBJ_DECLARE(
  nl_50_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 102400, AI_STATIC)

/* Array#51 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_51_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 102400, AI_STATIC)

/* Array#52 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_52_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 102400, AI_STATIC)

/* Array#53 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_55_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 102400, AI_STATIC)

/* Array#54 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_56_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 102400, AI_STATIC)

/* Array#55 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_60_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 102400, AI_STATIC)

/* Array#56 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_61_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 102400, AI_STATIC)

/* Array#57 */
AI_ARRAY_OBJ_DECLARE(
  nl_57_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 102400, AI_STATIC)

/* Array#58 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_58_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 102400, AI_STATIC)

/* Array#59 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_59_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 102400, AI_STATIC)

/* Array#60 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_62_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 102400, AI_STATIC)

/* Array#61 */
AI_ARRAY_OBJ_DECLARE(
  slice_64_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 51200, AI_STATIC)

/* Array#62 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_65_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 51200, AI_STATIC)

/* Array#63 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_69_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 51200, AI_STATIC)

/* Array#64 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_70_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 51200, AI_STATIC)

/* Array#65 */
AI_ARRAY_OBJ_DECLARE(
  nl_66_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 51200, AI_STATIC)

/* Array#66 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_67_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 51200, AI_STATIC)

/* Array#67 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_68_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 51200, AI_STATIC)

/* Array#68 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_71_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 51200, AI_STATIC)

/* Array#69 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_72_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 51200, AI_STATIC)

/* Array#70 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_76_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 51200, AI_STATIC)

/* Array#71 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_77_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 51200, AI_STATIC)

/* Array#72 */
AI_ARRAY_OBJ_DECLARE(
  nl_73_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 51200, AI_STATIC)

/* Array#73 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_74_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 51200, AI_STATIC)

/* Array#74 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_75_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 51200, AI_STATIC)

/* Array#75 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_78_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 51200, AI_STATIC)

/* Array#76 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_79_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 51200, AI_STATIC)

/* Array#77 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_80_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 51200, AI_STATIC)

/* Array#78 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_84_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 51200, AI_STATIC)

/* Array#79 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_85_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 51200, AI_STATIC)

/* Array#80 */
AI_ARRAY_OBJ_DECLARE(
  nl_81_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 51200, AI_STATIC)

/* Array#81 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_82_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 51200, AI_STATIC)

/* Array#82 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_83_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 51200, AI_STATIC)

/* Array#83 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_86_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 51200, AI_STATIC)

/* Array#84 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_87_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 51200, AI_STATIC)

/* Array#85 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_91_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 51200, AI_STATIC)

/* Array#86 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_92_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 51200, AI_STATIC)

/* Array#87 */
AI_ARRAY_OBJ_DECLARE(
  nl_88_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 51200, AI_STATIC)

/* Array#88 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_89_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 51200, AI_STATIC)

/* Array#89 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_90_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 51200, AI_STATIC)

/* Array#90 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_93_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 51200, AI_STATIC)

/* Array#91 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_94_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 51200, AI_STATIC)

/* Array#92 */
AI_ARRAY_OBJ_DECLARE(
  slice_63_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 51200, AI_STATIC)

/* Array#93 */
AI_ARRAY_OBJ_DECLARE(
  concat_95_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 204800, AI_STATIC)

/* Array#94 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_96_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 102400, AI_STATIC)

/* Array#95 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_100_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 102400, AI_STATIC)

/* Array#96 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_101_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 102400, AI_STATIC)

/* Array#97 */
AI_ARRAY_OBJ_DECLARE(
  nl_97_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 102400, AI_STATIC)

/* Array#98 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_98_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 102400, AI_STATIC)

/* Array#99 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_99_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 102400, AI_STATIC)

/* Array#100 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_102_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 102400, AI_STATIC)

/* Array#101 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_104_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 51200, AI_STATIC)

/* Array#102 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_108_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 51200, AI_STATIC)

/* Array#103 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_109_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 51200, AI_STATIC)

/* Array#104 */
AI_ARRAY_OBJ_DECLARE(
  nl_105_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 51200, AI_STATIC)

/* Array#105 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_106_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 51200, AI_STATIC)

/* Array#106 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_107_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 51200, AI_STATIC)

/* Array#107 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_110_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 51200, AI_STATIC)

/* Array#108 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_111_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 51200, AI_STATIC)

/* Array#109 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_115_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 51200, AI_STATIC)

/* Array#110 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_116_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 51200, AI_STATIC)

/* Array#111 */
AI_ARRAY_OBJ_DECLARE(
  nl_112_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 51200, AI_STATIC)

/* Array#112 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_113_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 51200, AI_STATIC)

/* Array#113 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_114_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 51200, AI_STATIC)

/* Array#114 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_117_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 51200, AI_STATIC)

/* Array#115 */
AI_ARRAY_OBJ_DECLARE(
  slice_119_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 25600, AI_STATIC)

/* Array#116 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_120_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 25600, AI_STATIC)

/* Array#117 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_124_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 25600, AI_STATIC)

/* Array#118 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_125_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 25600, AI_STATIC)

/* Array#119 */
AI_ARRAY_OBJ_DECLARE(
  nl_121_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 25600, AI_STATIC)

/* Array#120 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_122_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 25600, AI_STATIC)

/* Array#121 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_123_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 25600, AI_STATIC)

/* Array#122 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_126_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 25600, AI_STATIC)

/* Array#123 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_127_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 25600, AI_STATIC)

/* Array#124 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_131_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 25600, AI_STATIC)

/* Array#125 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_132_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 25600, AI_STATIC)

/* Array#126 */
AI_ARRAY_OBJ_DECLARE(
  nl_128_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 25600, AI_STATIC)

/* Array#127 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_129_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 25600, AI_STATIC)

/* Array#128 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_130_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 25600, AI_STATIC)

/* Array#129 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_133_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 25600, AI_STATIC)

/* Array#130 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_134_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 25600, AI_STATIC)

/* Array#131 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_135_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 25600, AI_STATIC)

/* Array#132 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_139_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 25600, AI_STATIC)

/* Array#133 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_140_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 25600, AI_STATIC)

/* Array#134 */
AI_ARRAY_OBJ_DECLARE(
  nl_136_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 25600, AI_STATIC)

/* Array#135 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_137_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 25600, AI_STATIC)

/* Array#136 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_138_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 25600, AI_STATIC)

/* Array#137 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_141_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 25600, AI_STATIC)

/* Array#138 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_142_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 25600, AI_STATIC)

/* Array#139 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_146_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 25600, AI_STATIC)

/* Array#140 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_147_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 25600, AI_STATIC)

/* Array#141 */
AI_ARRAY_OBJ_DECLARE(
  nl_143_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 25600, AI_STATIC)

/* Array#142 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_144_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 25600, AI_STATIC)

/* Array#143 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_145_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 25600, AI_STATIC)

/* Array#144 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_148_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 25600, AI_STATIC)

/* Array#145 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_149_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 25600, AI_STATIC)

/* Array#146 */
AI_ARRAY_OBJ_DECLARE(
  slice_118_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 25600, AI_STATIC)

/* Array#147 */
AI_ARRAY_OBJ_DECLARE(
  concat_150_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 102400, AI_STATIC)

/* Array#148 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_151_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 51200, AI_STATIC)

/* Array#149 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_155_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 51200, AI_STATIC)

/* Array#150 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_156_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 51200, AI_STATIC)

/* Array#151 */
AI_ARRAY_OBJ_DECLARE(
  nl_152_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 51200, AI_STATIC)

/* Array#152 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_153_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 51200, AI_STATIC)

/* Array#153 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_154_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 51200, AI_STATIC)

/* Array#154 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_157_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 51200, AI_STATIC)

/* Array#155 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_159_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 25600, AI_STATIC)

/* Array#156 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_163_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 25600, AI_STATIC)

/* Array#157 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_164_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 25600, AI_STATIC)

/* Array#158 */
AI_ARRAY_OBJ_DECLARE(
  nl_160_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 25600, AI_STATIC)

/* Array#159 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_161_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 25600, AI_STATIC)

/* Array#160 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_162_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 25600, AI_STATIC)

/* Array#161 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_165_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 25600, AI_STATIC)

/* Array#162 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_166_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 25600, AI_STATIC)

/* Array#163 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_170_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 25600, AI_STATIC)

/* Array#164 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_171_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 25600, AI_STATIC)

/* Array#165 */
AI_ARRAY_OBJ_DECLARE(
  nl_167_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 25600, AI_STATIC)

/* Array#166 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_168_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 25600, AI_STATIC)

/* Array#167 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_169_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 25600, AI_STATIC)

/* Array#168 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_172_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 25600, AI_STATIC)

/* Array#169 */
AI_ARRAY_OBJ_DECLARE(
  slice_174_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 12800, AI_STATIC)

/* Array#170 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_175_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 12800, AI_STATIC)

/* Array#171 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_179_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 12800, AI_STATIC)

/* Array#172 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_180_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 12800, AI_STATIC)

/* Array#173 */
AI_ARRAY_OBJ_DECLARE(
  nl_176_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 12800, AI_STATIC)

/* Array#174 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_177_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 12800, AI_STATIC)

/* Array#175 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_178_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 12800, AI_STATIC)

/* Array#176 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_181_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 12800, AI_STATIC)

/* Array#177 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_182_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 12800, AI_STATIC)

/* Array#178 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_186_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 12800, AI_STATIC)

/* Array#179 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_187_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 12800, AI_STATIC)

/* Array#180 */
AI_ARRAY_OBJ_DECLARE(
  nl_183_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 12800, AI_STATIC)

/* Array#181 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_184_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 12800, AI_STATIC)

/* Array#182 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_185_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 12800, AI_STATIC)

/* Array#183 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_188_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 12800, AI_STATIC)

/* Array#184 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_189_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 12800, AI_STATIC)

/* Array#185 */
AI_ARRAY_OBJ_DECLARE(
  slice_173_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 12800, AI_STATIC)

/* Array#186 */
AI_ARRAY_OBJ_DECLARE(
  concat_190_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 38400, AI_STATIC)

/* Array#187 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_191_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 25600, AI_STATIC)

/* Array#188 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_195_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 25600, AI_STATIC)

/* Array#189 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_196_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 25600, AI_STATIC)

/* Array#190 */
AI_ARRAY_OBJ_DECLARE(
  nl_192_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 25600, AI_STATIC)

/* Array#191 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_193_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 25600, AI_STATIC)

/* Array#192 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_194_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 25600, AI_STATIC)

/* Array#193 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_197_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 25600, AI_STATIC)

/* Array#194 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_198_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 12800, AI_STATIC)

/* Array#195 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_202_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 12800, AI_STATIC)

/* Array#196 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_203_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 12800, AI_STATIC)

/* Array#197 */
AI_ARRAY_OBJ_DECLARE(
  nl_199_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 12800, AI_STATIC)

/* Array#198 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_200_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 12800, AI_STATIC)

/* Array#199 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_201_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 12800, AI_STATIC)

/* Array#200 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_204_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 12800, AI_STATIC)

/* Array#201 */
AI_ARRAY_OBJ_DECLARE(
  pool_205_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 12800, AI_STATIC)

/* Array#202 */
AI_ARRAY_OBJ_DECLARE(
  pool_206_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 12800, AI_STATIC)

/* Array#203 */
AI_ARRAY_OBJ_DECLARE(
  pool_207_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 12800, AI_STATIC)

/* Array#204 */
AI_ARRAY_OBJ_DECLARE(
  concat_208_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 51200, AI_STATIC)

/* Array#205 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_209_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 25600, AI_STATIC)

/* Array#206 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_213_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 25600, AI_STATIC)

/* Array#207 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_214_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 25600, AI_STATIC)

/* Array#208 */
AI_ARRAY_OBJ_DECLARE(
  nl_210_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 25600, AI_STATIC)

/* Array#209 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_211_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 25600, AI_STATIC)

/* Array#210 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_212_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 25600, AI_STATIC)

/* Array#211 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_215_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 25600, AI_STATIC)

/* Array#212 */
AI_ARRAY_OBJ_DECLARE(
  conversion_216_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 25600, AI_STATIC)

/* Array#213 */
AI_ARRAY_OBJ_DECLARE(
  resize_217_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 102400, AI_STATIC)

/* Array#214 */
AI_ARRAY_OBJ_DECLARE(
  concat_218_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 153600, AI_STATIC)

/* Array#215 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_219_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 51200, AI_STATIC)

/* Array#216 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_223_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 51200, AI_STATIC)

/* Array#217 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_224_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 51200, AI_STATIC)

/* Array#218 */
AI_ARRAY_OBJ_DECLARE(
  nl_220_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 51200, AI_STATIC)

/* Array#219 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_221_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 51200, AI_STATIC)

/* Array#220 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_222_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 51200, AI_STATIC)

/* Array#221 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_225_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 51200, AI_STATIC)

/* Array#222 */
AI_ARRAY_OBJ_DECLARE(
  slice_227_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 25600, AI_STATIC)

/* Array#223 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_228_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 25600, AI_STATIC)

/* Array#224 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_232_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 25600, AI_STATIC)

/* Array#225 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_233_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 25600, AI_STATIC)

/* Array#226 */
AI_ARRAY_OBJ_DECLARE(
  nl_229_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 25600, AI_STATIC)

/* Array#227 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_230_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 25600, AI_STATIC)

/* Array#228 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_231_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 25600, AI_STATIC)

/* Array#229 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_234_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 25600, AI_STATIC)

/* Array#230 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_235_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 25600, AI_STATIC)

/* Array#231 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_239_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 25600, AI_STATIC)

/* Array#232 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_240_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 25600, AI_STATIC)

/* Array#233 */
AI_ARRAY_OBJ_DECLARE(
  nl_236_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 25600, AI_STATIC)

/* Array#234 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_237_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 25600, AI_STATIC)

/* Array#235 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_238_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 25600, AI_STATIC)

/* Array#236 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_241_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 25600, AI_STATIC)

/* Array#237 */
AI_ARRAY_OBJ_DECLARE(
  slice_226_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 25600, AI_STATIC)

/* Array#238 */
AI_ARRAY_OBJ_DECLARE(
  concat_242_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 76800, AI_STATIC)

/* Array#239 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_243_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 51200, AI_STATIC)

/* Array#240 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_247_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 51200, AI_STATIC)

/* Array#241 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_248_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 51200, AI_STATIC)

/* Array#242 */
AI_ARRAY_OBJ_DECLARE(
  nl_244_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 51200, AI_STATIC)

/* Array#243 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_245_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 51200, AI_STATIC)

/* Array#244 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_246_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 51200, AI_STATIC)

/* Array#245 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_249_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 51200, AI_STATIC)

/* Array#246 */
AI_ARRAY_OBJ_DECLARE(
  conversion_250_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 51200, AI_STATIC)

/* Array#247 */
AI_ARRAY_OBJ_DECLARE(
  resize_251_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 204800, AI_STATIC)

/* Array#248 */
AI_ARRAY_OBJ_DECLARE(
  concat_252_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 307200, AI_STATIC)

/* Array#249 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_253_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 102400, AI_STATIC)

/* Array#250 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_257_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 102400, AI_STATIC)

/* Array#251 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_258_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 102400, AI_STATIC)

/* Array#252 */
AI_ARRAY_OBJ_DECLARE(
  nl_254_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 102400, AI_STATIC)

/* Array#253 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_255_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 102400, AI_STATIC)

/* Array#254 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_256_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 102400, AI_STATIC)

/* Array#255 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_259_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 102400, AI_STATIC)

/* Array#256 */
AI_ARRAY_OBJ_DECLARE(
  slice_261_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 51200, AI_STATIC)

/* Array#257 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_262_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 51200, AI_STATIC)

/* Array#258 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_266_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 51200, AI_STATIC)

/* Array#259 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_267_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 51200, AI_STATIC)

/* Array#260 */
AI_ARRAY_OBJ_DECLARE(
  nl_263_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 51200, AI_STATIC)

/* Array#261 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_264_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 51200, AI_STATIC)

/* Array#262 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_265_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 51200, AI_STATIC)

/* Array#263 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_268_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 51200, AI_STATIC)

/* Array#264 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_269_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 51200, AI_STATIC)

/* Array#265 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_273_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 51200, AI_STATIC)

/* Array#266 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_274_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 51200, AI_STATIC)

/* Array#267 */
AI_ARRAY_OBJ_DECLARE(
  nl_270_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 51200, AI_STATIC)

/* Array#268 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_271_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 51200, AI_STATIC)

/* Array#269 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_272_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 51200, AI_STATIC)

/* Array#270 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_275_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 51200, AI_STATIC)

/* Array#271 */
AI_ARRAY_OBJ_DECLARE(
  slice_260_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 51200, AI_STATIC)

/* Array#272 */
AI_ARRAY_OBJ_DECLARE(
  concat_276_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 153600, AI_STATIC)

/* Array#273 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_277_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 102400, AI_STATIC)

/* Array#274 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_281_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 102400, AI_STATIC)

/* Array#275 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_282_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 102400, AI_STATIC)

/* Array#276 */
AI_ARRAY_OBJ_DECLARE(
  nl_278_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 102400, AI_STATIC)

/* Array#277 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_279_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 102400, AI_STATIC)

/* Array#278 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_280_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 102400, AI_STATIC)

/* Array#279 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_283_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 102400, AI_STATIC)

/* Array#280 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_285_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 25600, AI_STATIC)

/* Array#281 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_289_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 25600, AI_STATIC)

/* Array#282 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_290_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 25600, AI_STATIC)

/* Array#283 */
AI_ARRAY_OBJ_DECLARE(
  nl_286_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 25600, AI_STATIC)

/* Array#284 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_287_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 25600, AI_STATIC)

/* Array#285 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_288_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 25600, AI_STATIC)

/* Array#286 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_291_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 25600, AI_STATIC)

/* Array#287 */
AI_ARRAY_OBJ_DECLARE(
  concat_292_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 76800, AI_STATIC)

/* Array#288 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_293_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 51200, AI_STATIC)

/* Array#289 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_297_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 51200, AI_STATIC)

/* Array#290 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_298_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 51200, AI_STATIC)

/* Array#291 */
AI_ARRAY_OBJ_DECLARE(
  nl_294_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 51200, AI_STATIC)

/* Array#292 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_295_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 51200, AI_STATIC)

/* Array#293 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_296_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 51200, AI_STATIC)

/* Array#294 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_299_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 51200, AI_STATIC)

/* Array#295 */
AI_ARRAY_OBJ_DECLARE(
  slice_301_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 25600, AI_STATIC)

/* Array#296 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_302_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 25600, AI_STATIC)

/* Array#297 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_306_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 25600, AI_STATIC)

/* Array#298 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_307_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 25600, AI_STATIC)

/* Array#299 */
AI_ARRAY_OBJ_DECLARE(
  nl_303_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 25600, AI_STATIC)

/* Array#300 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_304_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 25600, AI_STATIC)

/* Array#301 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_305_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 25600, AI_STATIC)

/* Array#302 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_308_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 25600, AI_STATIC)

/* Array#303 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_309_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 25600, AI_STATIC)

/* Array#304 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_313_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 25600, AI_STATIC)

/* Array#305 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_314_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 25600, AI_STATIC)

/* Array#306 */
AI_ARRAY_OBJ_DECLARE(
  nl_310_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 25600, AI_STATIC)

/* Array#307 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_311_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 25600, AI_STATIC)

/* Array#308 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_312_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 25600, AI_STATIC)

/* Array#309 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_315_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 25600, AI_STATIC)

/* Array#310 */
AI_ARRAY_OBJ_DECLARE(
  slice_300_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 25600, AI_STATIC)

/* Array#311 */
AI_ARRAY_OBJ_DECLARE(
  concat_316_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 76800, AI_STATIC)

/* Array#312 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_317_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 51200, AI_STATIC)

/* Array#313 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_321_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 51200, AI_STATIC)

/* Array#314 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_322_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 51200, AI_STATIC)

/* Array#315 */
AI_ARRAY_OBJ_DECLARE(
  nl_318_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 51200, AI_STATIC)

/* Array#316 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_319_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 51200, AI_STATIC)

/* Array#317 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_320_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 51200, AI_STATIC)

/* Array#318 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_323_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 51200, AI_STATIC)

/* Array#319 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_325_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 12800, AI_STATIC)

/* Array#320 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_329_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 12800, AI_STATIC)

/* Array#321 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_330_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 12800, AI_STATIC)

/* Array#322 */
AI_ARRAY_OBJ_DECLARE(
  nl_326_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 12800, AI_STATIC)

/* Array#323 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_327_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 12800, AI_STATIC)

/* Array#324 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_328_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 12800, AI_STATIC)

/* Array#325 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_331_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 12800, AI_STATIC)

/* Array#326 */
AI_ARRAY_OBJ_DECLARE(
  concat_332_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 38400, AI_STATIC)

/* Array#327 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_333_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 25600, AI_STATIC)

/* Array#328 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_337_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 25600, AI_STATIC)

/* Array#329 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_338_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 25600, AI_STATIC)

/* Array#330 */
AI_ARRAY_OBJ_DECLARE(
  nl_334_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 25600, AI_STATIC)

/* Array#331 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_335_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 25600, AI_STATIC)

/* Array#332 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_336_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 25600, AI_STATIC)

/* Array#333 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_339_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 25600, AI_STATIC)

/* Array#334 */
AI_ARRAY_OBJ_DECLARE(
  slice_341_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 12800, AI_STATIC)

/* Array#335 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_342_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 12800, AI_STATIC)

/* Array#336 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_346_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 12800, AI_STATIC)

/* Array#337 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_347_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 12800, AI_STATIC)

/* Array#338 */
AI_ARRAY_OBJ_DECLARE(
  nl_343_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 12800, AI_STATIC)

/* Array#339 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_344_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 12800, AI_STATIC)

/* Array#340 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_345_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 12800, AI_STATIC)

/* Array#341 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_348_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 12800, AI_STATIC)

/* Array#342 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_349_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 12800, AI_STATIC)

/* Array#343 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_353_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 12800, AI_STATIC)

/* Array#344 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_354_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 12800, AI_STATIC)

/* Array#345 */
AI_ARRAY_OBJ_DECLARE(
  nl_350_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 12800, AI_STATIC)

/* Array#346 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_351_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 12800, AI_STATIC)

/* Array#347 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_352_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 12800, AI_STATIC)

/* Array#348 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_355_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 12800, AI_STATIC)

/* Array#349 */
AI_ARRAY_OBJ_DECLARE(
  slice_340_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 12800, AI_STATIC)

/* Array#350 */
AI_ARRAY_OBJ_DECLARE(
  concat_356_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 38400, AI_STATIC)

/* Array#351 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_357_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 25600, AI_STATIC)

/* Array#352 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_361_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 25600, AI_STATIC)

/* Array#353 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_362_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 25600, AI_STATIC)

/* Array#354 */
AI_ARRAY_OBJ_DECLARE(
  nl_358_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 25600, AI_STATIC)

/* Array#355 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_359_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 25600, AI_STATIC)

/* Array#356 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_360_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 25600, AI_STATIC)

/* Array#357 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_363_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 25600, AI_STATIC)

/* Array#358 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_379_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 6400, AI_STATIC)

/* Array#359 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_383_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 6400, AI_STATIC)

/* Array#360 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_384_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 6400, AI_STATIC)

/* Array#361 */
AI_ARRAY_OBJ_DECLARE(
  nl_380_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 6400, AI_STATIC)

/* Array#362 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_381_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 6400, AI_STATIC)

/* Array#363 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_382_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 6400, AI_STATIC)

/* Array#364 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_385_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 6400, AI_STATIC)

/* Array#365 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_386_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 6400, AI_STATIC)

/* Array#366 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_390_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 6400, AI_STATIC)

/* Array#367 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_391_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 6400, AI_STATIC)

/* Array#368 */
AI_ARRAY_OBJ_DECLARE(
  nl_387_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 6400, AI_STATIC)

/* Array#369 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_388_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 6400, AI_STATIC)

/* Array#370 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_389_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 6400, AI_STATIC)

/* Array#371 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_392_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 6400, AI_STATIC)

/* Array#372 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_393_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 300, AI_STATIC)

/* Array#373 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_364_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 6400, AI_STATIC)

/* Array#374 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_368_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 6400, AI_STATIC)

/* Array#375 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_369_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 6400, AI_STATIC)

/* Array#376 */
AI_ARRAY_OBJ_DECLARE(
  nl_365_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 6400, AI_STATIC)

/* Array#377 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_366_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 6400, AI_STATIC)

/* Array#378 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_367_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 6400, AI_STATIC)

/* Array#379 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_370_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 6400, AI_STATIC)

/* Array#380 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_371_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 6400, AI_STATIC)

/* Array#381 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_375_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 6400, AI_STATIC)

/* Array#382 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_376_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 6400, AI_STATIC)

/* Array#383 */
AI_ARRAY_OBJ_DECLARE(
  nl_372_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 6400, AI_STATIC)

/* Array#384 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_373_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 6400, AI_STATIC)

/* Array#385 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_374_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 6400, AI_STATIC)

/* Array#386 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_377_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 6400, AI_STATIC)

/* Array#387 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_378_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 6400, AI_STATIC)

/* Array#388 */
AI_ARRAY_OBJ_DECLARE(
  concat_394_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 6700, AI_STATIC)

/* Array#389 */
AI_ARRAY_OBJ_DECLARE(
  transpose_395_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 6700, AI_STATIC)

/* Array#390 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_412_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 25600, AI_STATIC)

/* Array#391 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_416_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 25600, AI_STATIC)

/* Array#392 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_417_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 25600, AI_STATIC)

/* Array#393 */
AI_ARRAY_OBJ_DECLARE(
  nl_413_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 25600, AI_STATIC)

/* Array#394 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_414_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 25600, AI_STATIC)

/* Array#395 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_415_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 25600, AI_STATIC)

/* Array#396 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_418_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 25600, AI_STATIC)

/* Array#397 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_419_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 25600, AI_STATIC)

/* Array#398 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_423_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 25600, AI_STATIC)

/* Array#399 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_424_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 25600, AI_STATIC)

/* Array#400 */
AI_ARRAY_OBJ_DECLARE(
  nl_420_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 25600, AI_STATIC)

/* Array#401 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_421_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 25600, AI_STATIC)

/* Array#402 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_422_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 25600, AI_STATIC)

/* Array#403 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_425_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 25600, AI_STATIC)

/* Array#404 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_426_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1200, AI_STATIC)

/* Array#405 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_397_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 25600, AI_STATIC)

/* Array#406 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_401_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 25600, AI_STATIC)

/* Array#407 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_402_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 25600, AI_STATIC)

/* Array#408 */
AI_ARRAY_OBJ_DECLARE(
  nl_398_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 25600, AI_STATIC)

/* Array#409 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_399_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 25600, AI_STATIC)

/* Array#410 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_400_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 25600, AI_STATIC)

/* Array#411 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_403_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 25600, AI_STATIC)

/* Array#412 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_404_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 25600, AI_STATIC)

/* Array#413 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_408_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 25600, AI_STATIC)

/* Array#414 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_409_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 25600, AI_STATIC)

/* Array#415 */
AI_ARRAY_OBJ_DECLARE(
  nl_405_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 25600, AI_STATIC)

/* Array#416 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_406_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 25600, AI_STATIC)

/* Array#417 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_407_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 25600, AI_STATIC)

/* Array#418 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_410_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 25600, AI_STATIC)

/* Array#419 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_411_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 25600, AI_STATIC)

/* Array#420 */
AI_ARRAY_OBJ_DECLARE(
  concat_427_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 26800, AI_STATIC)

/* Array#421 */
AI_ARRAY_OBJ_DECLARE(
  transpose_428_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 26800, AI_STATIC)

/* Array#422 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_445_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 102400, AI_STATIC)

/* Array#423 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_449_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 102400, AI_STATIC)

/* Array#424 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_450_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 102400, AI_STATIC)

/* Array#425 */
AI_ARRAY_OBJ_DECLARE(
  nl_446_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 102400, AI_STATIC)

/* Array#426 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_447_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 102400, AI_STATIC)

/* Array#427 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_448_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 102400, AI_STATIC)

/* Array#428 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_451_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 102400, AI_STATIC)

/* Array#429 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_452_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 102400, AI_STATIC)

/* Array#430 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_456_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 102400, AI_STATIC)

/* Array#431 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_457_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 102400, AI_STATIC)

/* Array#432 */
AI_ARRAY_OBJ_DECLARE(
  nl_453_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 102400, AI_STATIC)

/* Array#433 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_454_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 102400, AI_STATIC)

/* Array#434 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_455_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 102400, AI_STATIC)

/* Array#435 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_458_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 102400, AI_STATIC)

/* Array#436 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_459_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 4800, AI_STATIC)

/* Array#437 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_430_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 102400, AI_STATIC)

/* Array#438 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_434_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 102400, AI_STATIC)

/* Array#439 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_435_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 102400, AI_STATIC)

/* Array#440 */
AI_ARRAY_OBJ_DECLARE(
  nl_431_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 102400, AI_STATIC)

/* Array#441 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_432_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 102400, AI_STATIC)

/* Array#442 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_433_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 102400, AI_STATIC)

/* Array#443 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_436_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 102400, AI_STATIC)

/* Array#444 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_437_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 102400, AI_STATIC)

/* Array#445 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_441_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 102400, AI_STATIC)

/* Array#446 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_442_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 102400, AI_STATIC)

/* Array#447 */
AI_ARRAY_OBJ_DECLARE(
  nl_438_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 102400, AI_STATIC)

/* Array#448 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_439_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 102400, AI_STATIC)

/* Array#449 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_440_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 102400, AI_STATIC)

/* Array#450 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_443_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 102400, AI_STATIC)

/* Array#451 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_444_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 102400, AI_STATIC)

/* Array#452 */
AI_ARRAY_OBJ_DECLARE(
  concat_460_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 107200, AI_STATIC)

/* Array#453 */
AI_ARRAY_OBJ_DECLARE(
  transpose_461_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 107200, AI_STATIC)

/* Array#454 */
AI_ARRAY_OBJ_DECLARE(
  concat_463_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 140700, AI_STATIC)

/* Array#455 */
AI_ARRAY_OBJ_DECLARE(
  slice_479_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 6300, AI_STATIC)

/* Array#456 */
AI_ARRAY_OBJ_DECLARE(
  nl_480_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 6300, AI_STATIC)

/* Array#457 */
AI_ARRAY_OBJ_DECLARE(
  slice_464_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 134400, AI_STATIC)

/* Array#458 */
AI_ARRAY_OBJ_DECLARE(
  transpose_466_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 134400, AI_STATIC)

/* Array#459 */
AI_ARRAY_OBJ_DECLARE(
  nl_467_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 134400, AI_STATIC)

/* Array#460 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_468_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 8400, AI_STATIC)

/* Array#461 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_470_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 8400, AI_STATIC)

/* Array#462 */
AI_ARRAY_OBJ_DECLARE(
  slice_474_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 4200, AI_STATIC)

/* Array#463 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_475_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 4200, AI_STATIC)

/* Array#464 */
AI_ARRAY_OBJ_DECLARE(
  slice_472_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 4200, AI_STATIC)

/* Array#465 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_473_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 4200, AI_STATIC)

/* Array#466 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_478_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 4200, AI_STATIC)

/* Array#467 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_476_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 4200, AI_STATIC)

/* Array#468 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_477_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 4200, AI_STATIC)

/* Array#469 */
AI_ARRAY_OBJ_DECLARE(
  concat_482_output_array, AI_ARRAY_FORMAT_S8|AI_FMT_FLAG_IS_IO,
  NULL, NULL, 14700, AI_STATIC)

/* Array#470 */
AI_ARRAY_OBJ_DECLARE(
  tfl_pseudo_qconst129_4D_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1, AI_STATIC)

/* Array#471 */
AI_ARRAY_OBJ_DECLARE(
  tfl_pseudo_qconst2_4D_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 8400, AI_STATIC)

/* Array#472 */
AI_ARRAY_OBJ_DECLARE(
  tfl_pseudo_qconst_3D_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1, AI_STATIC)

/* Array#473 */
AI_ARRAY_OBJ_DECLARE(
  tfl_pseudo_qconst1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 4200, AI_STATIC)

/* Array#474 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_1_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 432, AI_STATIC)

/* Array#475 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_1_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 16, AI_STATIC)

/* Array#476 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_9_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 4608, AI_STATIC)

/* Array#477 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_9_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 32, AI_STATIC)

/* Array#478 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_16_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1024, AI_STATIC)

/* Array#479 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_16_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 32, AI_STATIC)

/* Array#480 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_24_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2304, AI_STATIC)

/* Array#481 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_24_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 16, AI_STATIC)

/* Array#482 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_31_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2304, AI_STATIC)

/* Array#483 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_31_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 16, AI_STATIC)

/* Array#484 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_41_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1536, AI_STATIC)

/* Array#485 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_41_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 32, AI_STATIC)

/* Array#486 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_49_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 18432, AI_STATIC)

/* Array#487 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_49_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 64, AI_STATIC)

/* Array#488 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_56_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 4096, AI_STATIC)

/* Array#489 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_56_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 64, AI_STATIC)

/* Array#490 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_65_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 9216, AI_STATIC)

/* Array#491 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_65_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 32, AI_STATIC)

/* Array#492 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_72_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 9216, AI_STATIC)

/* Array#493 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_72_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 32, AI_STATIC)

/* Array#494 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_80_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 9216, AI_STATIC)

/* Array#495 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_80_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 32, AI_STATIC)

/* Array#496 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_87_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 9216, AI_STATIC)

/* Array#497 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_87_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 32, AI_STATIC)

/* Array#498 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_96_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 8192, AI_STATIC)

/* Array#499 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_96_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 64, AI_STATIC)

/* Array#500 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_104_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 73728, AI_STATIC)

/* Array#501 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_104_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 128, AI_STATIC)

/* Array#502 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_111_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 16384, AI_STATIC)

/* Array#503 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_111_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 128, AI_STATIC)

/* Array#504 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_120_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 36864, AI_STATIC)

/* Array#505 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_120_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 64, AI_STATIC)

/* Array#506 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_127_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 36864, AI_STATIC)

/* Array#507 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_127_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 64, AI_STATIC)

/* Array#508 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_135_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 36864, AI_STATIC)

/* Array#509 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_135_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 64, AI_STATIC)

/* Array#510 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_142_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 36864, AI_STATIC)

/* Array#511 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_142_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 64, AI_STATIC)

/* Array#512 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_151_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 32768, AI_STATIC)

/* Array#513 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_151_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 128, AI_STATIC)

/* Array#514 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_159_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 294912, AI_STATIC)

/* Array#515 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_159_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 256, AI_STATIC)

/* Array#516 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_166_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 65536, AI_STATIC)

/* Array#517 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_166_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 256, AI_STATIC)

/* Array#518 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_175_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 147456, AI_STATIC)

/* Array#519 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_175_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 128, AI_STATIC)

/* Array#520 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_182_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 147456, AI_STATIC)

/* Array#521 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_182_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 128, AI_STATIC)

/* Array#522 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_191_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 98304, AI_STATIC)

/* Array#523 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_191_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 256, AI_STATIC)

/* Array#524 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_198_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 32768, AI_STATIC)

/* Array#525 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_198_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 128, AI_STATIC)

/* Array#526 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_209_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 131072, AI_STATIC)

/* Array#527 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_209_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 256, AI_STATIC)

/* Array#528 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_219_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 49152, AI_STATIC)

/* Array#529 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_219_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 128, AI_STATIC)

/* Array#530 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_228_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 36864, AI_STATIC)

/* Array#531 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_228_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 64, AI_STATIC)

/* Array#532 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_235_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 36864, AI_STATIC)

/* Array#533 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_235_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 64, AI_STATIC)

/* Array#534 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_243_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 24576, AI_STATIC)

/* Array#535 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_243_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 128, AI_STATIC)

/* Array#536 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_253_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 12288, AI_STATIC)

/* Array#537 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_253_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 64, AI_STATIC)

/* Array#538 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_262_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 9216, AI_STATIC)

/* Array#539 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_262_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 32, AI_STATIC)

/* Array#540 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_269_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 9216, AI_STATIC)

/* Array#541 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_269_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 32, AI_STATIC)

/* Array#542 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_277_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 6144, AI_STATIC)

/* Array#543 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_277_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 64, AI_STATIC)

/* Array#544 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_285_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 36864, AI_STATIC)

/* Array#545 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_285_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 64, AI_STATIC)

/* Array#546 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_293_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 24576, AI_STATIC)

/* Array#547 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_293_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 128, AI_STATIC)

/* Array#548 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_302_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 36864, AI_STATIC)

/* Array#549 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_302_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 64, AI_STATIC)

/* Array#550 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_309_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 36864, AI_STATIC)

/* Array#551 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_309_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 64, AI_STATIC)

/* Array#552 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_317_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 24576, AI_STATIC)

/* Array#553 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_317_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 128, AI_STATIC)

/* Array#554 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_325_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 147456, AI_STATIC)

/* Array#555 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_325_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 128, AI_STATIC)

/* Array#556 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_333_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 98304, AI_STATIC)

/* Array#557 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_333_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 256, AI_STATIC)

/* Array#558 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_342_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 147456, AI_STATIC)

/* Array#559 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_342_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 128, AI_STATIC)

/* Array#560 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_349_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 147456, AI_STATIC)

/* Array#561 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_349_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 128, AI_STATIC)

/* Array#562 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_357_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 98304, AI_STATIC)

/* Array#563 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_357_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 256, AI_STATIC)

/* Array#564 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_379_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 147456, AI_STATIC)

/* Array#565 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_379_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 64, AI_STATIC)

/* Array#566 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_386_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 36864, AI_STATIC)

/* Array#567 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_386_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 64, AI_STATIC)

/* Array#568 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_393_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 192, AI_STATIC)

/* Array#569 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_393_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 3, AI_STATIC)

/* Array#570 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_364_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 147456, AI_STATIC)

/* Array#571 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_364_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 64, AI_STATIC)

/* Array#572 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_371_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 36864, AI_STATIC)

/* Array#573 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_371_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 64, AI_STATIC)

/* Array#574 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_378_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 4096, AI_STATIC)

/* Array#575 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_378_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 64, AI_STATIC)

/* Array#576 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_412_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 73728, AI_STATIC)

/* Array#577 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_412_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 64, AI_STATIC)

/* Array#578 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_419_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 36864, AI_STATIC)

/* Array#579 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_419_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 64, AI_STATIC)

/* Array#580 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_426_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 192, AI_STATIC)

/* Array#581 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_426_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 3, AI_STATIC)

/* Array#582 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_397_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 73728, AI_STATIC)

/* Array#583 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_397_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 64, AI_STATIC)

/* Array#584 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_404_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 36864, AI_STATIC)

/* Array#585 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_404_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 64, AI_STATIC)

/* Array#586 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_411_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 4096, AI_STATIC)

/* Array#587 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_411_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 64, AI_STATIC)

/* Array#588 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_445_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 36864, AI_STATIC)

/* Array#589 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_445_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 64, AI_STATIC)

/* Array#590 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_452_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 36864, AI_STATIC)

/* Array#591 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_452_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 64, AI_STATIC)

/* Array#592 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_459_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 192, AI_STATIC)

/* Array#593 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_459_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 3, AI_STATIC)

/* Array#594 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_430_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 36864, AI_STATIC)

/* Array#595 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_430_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 64, AI_STATIC)

/* Array#596 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_437_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 36864, AI_STATIC)

/* Array#597 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_437_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 64, AI_STATIC)

/* Array#598 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_444_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 4096, AI_STATIC)

/* Array#599 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_444_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 64, AI_STATIC)

/* Array#600 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_468_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 16, AI_STATIC)

/* Array#601 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_468_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 1, AI_STATIC)

/* Array#602 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_1_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1036, AI_STATIC)

/* Array#603 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_9_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 5824, AI_STATIC)

/* Array#604 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_16_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 128, AI_STATIC)

/* Array#605 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_24_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 5248, AI_STATIC)

/* Array#606 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_31_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 5248, AI_STATIC)

/* Array#607 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_41_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 192, AI_STATIC)

/* Array#608 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_49_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 6528, AI_STATIC)

/* Array#609 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_56_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 256, AI_STATIC)

/* Array#610 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_65_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 6400, AI_STATIC)

/* Array#611 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_72_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 6400, AI_STATIC)

/* Array#612 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_80_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 6400, AI_STATIC)

/* Array#613 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_87_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 6400, AI_STATIC)

/* Array#614 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_96_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 512, AI_STATIC)

/* Array#615 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_104_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 7936, AI_STATIC)

/* Array#616 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_111_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 512, AI_STATIC)

/* Array#617 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_120_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 7680, AI_STATIC)

/* Array#618 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_127_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 7680, AI_STATIC)

/* Array#619 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_135_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 7680, AI_STATIC)

/* Array#620 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_142_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 7680, AI_STATIC)

/* Array#621 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_151_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1024, AI_STATIC)

/* Array#622 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_159_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 10752, AI_STATIC)

/* Array#623 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_166_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1024, AI_STATIC)

/* Array#624 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_175_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 10240, AI_STATIC)

/* Array#625 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_182_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 10240, AI_STATIC)

/* Array#626 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_191_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1536, AI_STATIC)

/* Array#627 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_198_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1024, AI_STATIC)

/* Array#628 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_209_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2048, AI_STATIC)

/* Array#629 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_219_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1536, AI_STATIC)

/* Array#630 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_228_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 7680, AI_STATIC)

/* Array#631 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_235_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 7680, AI_STATIC)

/* Array#632 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_243_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 768, AI_STATIC)

/* Array#633 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_253_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 768, AI_STATIC)

/* Array#634 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_262_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 6400, AI_STATIC)

/* Array#635 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_269_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 6400, AI_STATIC)

/* Array#636 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_277_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 384, AI_STATIC)

/* Array#637 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_285_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 7680, AI_STATIC)

/* Array#638 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_293_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 768, AI_STATIC)

/* Array#639 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_302_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 7680, AI_STATIC)

/* Array#640 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_309_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 7680, AI_STATIC)

/* Array#641 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_317_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 768, AI_STATIC)

/* Array#642 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_325_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 10240, AI_STATIC)

/* Array#643 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_333_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1536, AI_STATIC)

/* Array#644 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_342_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 10240, AI_STATIC)

/* Array#645 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_349_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 10240, AI_STATIC)

/* Array#646 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_357_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1536, AI_STATIC)

/* Array#647 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_379_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 14592, AI_STATIC)

/* Array#648 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_386_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 7680, AI_STATIC)

/* Array#649 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_393_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 256, AI_STATIC)

/* Array#650 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_364_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 14592, AI_STATIC)

/* Array#651 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_371_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 7680, AI_STATIC)

/* Array#652 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_378_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 256, AI_STATIC)

/* Array#653 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_412_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 9984, AI_STATIC)

/* Array#654 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_419_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 7680, AI_STATIC)

/* Array#655 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_426_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 256, AI_STATIC)

/* Array#656 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_397_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 9984, AI_STATIC)

/* Array#657 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_404_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 7680, AI_STATIC)

/* Array#658 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_411_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 256, AI_STATIC)

/* Array#659 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_445_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 7680, AI_STATIC)

/* Array#660 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_452_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 7680, AI_STATIC)

/* Array#661 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_459_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 256, AI_STATIC)

/* Array#662 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_430_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 7680, AI_STATIC)

/* Array#663 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_437_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 7680, AI_STATIC)

/* Array#664 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_444_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 256, AI_STATIC)

/* Array#665 */
AI_ARRAY_OBJ_DECLARE(
  nl_467_scratch0_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 31, AI_STATIC)

/* Array#666 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_468_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 64, AI_STATIC)

/**  Array metadata declarations section  *************************************/
/* Int quant #0 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(concat_150_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.06855183839797974f),
    AI_PACK_INTQ_ZP(-116)))

/* Int quant #1 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(concat_190_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.08901643753051758f),
    AI_PACK_INTQ_ZP(-122)))

/* Int quant #2 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(concat_208_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.05740991607308388f),
    AI_PACK_INTQ_ZP(-123)))

/* Int quant #3 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(concat_218_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0498603992164135f),
    AI_PACK_INTQ_ZP(-122)))

/* Int quant #4 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(concat_242_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.053553905338048935f),
    AI_PACK_INTQ_ZP(-123)))

/* Int quant #5 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(concat_252_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.05415775254368782f),
    AI_PACK_INTQ_ZP(-123)))

/* Int quant #6 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(concat_276_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.05578995496034622f),
    AI_PACK_INTQ_ZP(-123)))

/* Int quant #7 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(concat_292_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.05797247961163521f),
    AI_PACK_INTQ_ZP(-123)))

/* Int quant #8 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(concat_316_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.08479750156402588f),
    AI_PACK_INTQ_ZP(-125)))

/* Int quant #9 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(concat_332_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.06318599730730057f),
    AI_PACK_INTQ_ZP(-124)))

/* Int quant #10 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(concat_356_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.09351727366447449f),
    AI_PACK_INTQ_ZP(-125)))

/* Int quant #11 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(concat_394_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.8081459403038025f),
    AI_PACK_INTQ_ZP(-16)))

/* Int quant #12 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(concat_40_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.16015248000621796f),
    AI_PACK_INTQ_ZP(-125)))

/* Int quant #13 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(concat_427_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.8081459403038025f),
    AI_PACK_INTQ_ZP(-16)))

/* Int quant #14 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(concat_460_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.8081459403038025f),
    AI_PACK_INTQ_ZP(-16)))

/* Int quant #15 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(concat_463_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.8081459403038025f),
    AI_PACK_INTQ_ZP(-16)))

/* Int quant #16 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(concat_482_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.004235264845192432f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #17 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(concat_95_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.06768429279327393f),
    AI_PACK_INTQ_ZP(-116)))

/* Int quant #18 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_104_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.08141069859266281f),
    AI_PACK_INTQ_ZP(4)))

/* Int quant #19 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_104_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0026634796522557735f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #20 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_111_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.16380026936531067f),
    AI_PACK_INTQ_ZP(25)))

/* Int quant #21 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_111_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.009307855740189552f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #22 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_120_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.08017363399267197f),
    AI_PACK_INTQ_ZP(-2)))

/* Int quant #23 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_120_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.004322149325162172f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #24 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_127_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0826624259352684f),
    AI_PACK_INTQ_ZP(12)))

/* Int quant #25 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_127_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.006253720261156559f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #26 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_135_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0893167182803154f),
    AI_PACK_INTQ_ZP(-4)))

/* Int quant #27 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_135_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0032738875597715378f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #28 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_142_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.1311865746974945f),
    AI_PACK_INTQ_ZP(1)))

/* Int quant #29 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_142_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.01610599458217621f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #30 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_151_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.09093216806650162f),
    AI_PACK_INTQ_ZP(-10)))

/* Int quant #31 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_151_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.002665415871888399f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #32 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_159_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.08046691119670868f),
    AI_PACK_INTQ_ZP(11)))

/* Int quant #33 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_159_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0036357995122671127f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #34 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_166_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.11005696654319763f),
    AI_PACK_INTQ_ZP(-14)))

/* Int quant #35 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_166_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00614271080121398f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #36 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_16_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.5657886862754822f),
    AI_PACK_INTQ_ZP(56)))

/* Int quant #37 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_16_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.007561185397207737f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #38 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_175_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.10177198797464371f),
    AI_PACK_INTQ_ZP(-24)))

/* Int quant #39 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_175_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00604076124727726f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #40 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_182_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.17974503338336945f),
    AI_PACK_INTQ_ZP(2)))

/* Int quant #41 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_182_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.006513423752039671f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #42 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_191_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.1192486584186554f),
    AI_PACK_INTQ_ZP(8)))

/* Int quant #43 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_191_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0024499481078237295f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #44 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_198_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.09822265803813934f),
    AI_PACK_INTQ_ZP(-19)))

/* Int quant #45 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_198_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.004418157506734133f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #46 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_1_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.5219366550445557f),
    AI_PACK_INTQ_ZP(1)))

/* Int quant #47 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_1_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.12150784581899643f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #48 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_209_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.08788120001554489f),
    AI_PACK_INTQ_ZP(50)))

/* Int quant #49 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_209_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.001650908961892128f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #50 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_219_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.092446468770504f),
    AI_PACK_INTQ_ZP(11)))

/* Int quant #51 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_219_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.011250244453549385f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #52 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_228_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.09133733063936234f),
    AI_PACK_INTQ_ZP(2)))

/* Int quant #53 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_228_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0035339181777089834f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #54 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_235_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.10737717896699905f),
    AI_PACK_INTQ_ZP(2)))

/* Int quant #55 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_235_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.006579972337931395f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #56 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_243_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.09717833250761032f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #57 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_243_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.005768281407654285f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #58 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_24_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.28010857105255127f),
    AI_PACK_INTQ_ZP(12)))

/* Int quant #59 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_24_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.01200611051172018f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #60 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_253_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.08915843069553375f),
    AI_PACK_INTQ_ZP(2)))

/* Int quant #61 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_253_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0050485762767493725f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #62 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_262_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.06294285506010056f),
    AI_PACK_INTQ_ZP(3)))

/* Int quant #63 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_262_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.003991228062659502f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #64 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_269_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.11118334531784058f),
    AI_PACK_INTQ_ZP(2)))

/* Int quant #65 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_269_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.007835743017494678f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #66 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_277_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.1193377822637558f),
    AI_PACK_INTQ_ZP(-12)))

/* Int quant #67 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_277_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.007335321046411991f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #68 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_285_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.1047167181968689f),
    AI_PACK_INTQ_ZP(-12)))

/* Int quant #69 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_285_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0037667076103389263f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #70 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_293_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.1412927210330963f),
    AI_PACK_INTQ_ZP(-17)))

/* Int quant #71 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_293_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.006392344832420349f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #72 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_302_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.10296504944562912f),
    AI_PACK_INTQ_ZP(1)))

/* Int quant #73 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_302_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.003578667063266039f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #74 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_309_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.16467826068401337f),
    AI_PACK_INTQ_ZP(-3)))

/* Int quant #75 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_309_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.009898621588945389f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #76 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_317_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.16047991812229156f),
    AI_PACK_INTQ_ZP(56)))

/* Int quant #77 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_317_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.009418009780347347f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #78 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_31_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.2769908308982849f),
    AI_PACK_INTQ_ZP(26)))

/* Int quant #79 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_31_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.005683000199496746f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #80 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_325_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.1168360561132431f),
    AI_PACK_INTQ_ZP(-9)))

/* Int quant #81 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_325_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0035919491201639175f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #82 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_333_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.16562919318675995f),
    AI_PACK_INTQ_ZP(-12)))

/* Int quant #83 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_333_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.007651174906641245f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #84 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_342_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.11714307963848114f),
    AI_PACK_INTQ_ZP(12)))

/* Int quant #85 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_342_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0038788351230323315f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #86 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_349_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.16953903436660767f),
    AI_PACK_INTQ_ZP(-12)))

/* Int quant #87 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_349_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.006514511536806822f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #88 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_357_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.19821466505527496f),
    AI_PACK_INTQ_ZP(33)))

/* Int quant #89 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_357_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.007958429865539074f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #90 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_364_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.2520398795604706f),
    AI_PACK_INTQ_ZP(-51)))

/* Int quant #91 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_364_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.003578874049708247f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #92 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_371_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.49280235171318054f),
    AI_PACK_INTQ_ZP(-26)))

/* Int quant #93 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_371_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.005254116374999285f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #94 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_378_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.8081459403038025f),
    AI_PACK_INTQ_ZP(-16)))

/* Int quant #95 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_378_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0036467304453253746f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #96 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_379_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.13768339157104492f),
    AI_PACK_INTQ_ZP(-41)))

/* Int quant #97 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_379_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.002943868050351739f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #98 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_386_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.16819581389427185f),
    AI_PACK_INTQ_ZP(24)))

/* Int quant #99 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_386_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.002119665499776602f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #100 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_393_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.8081459403038025f),
    AI_PACK_INTQ_ZP(-16)))

/* Int quant #101 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_393_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.003531388472765684f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #102 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_397_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.18041980266571045f),
    AI_PACK_INTQ_ZP(-13)))

/* Int quant #103 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_397_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.006084934342652559f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #104 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_404_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.3353253901004791f),
    AI_PACK_INTQ_ZP(-15)))

/* Int quant #105 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_404_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00823782104998827f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #106 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_411_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.8081459403038025f),
    AI_PACK_INTQ_ZP(-16)))

/* Int quant #107 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_411_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.01033464539796114f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #108 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_412_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.1545264720916748f),
    AI_PACK_INTQ_ZP(-2)))

/* Int quant #109 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_412_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.008313649334013462f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #110 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_419_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.2674485146999359f),
    AI_PACK_INTQ_ZP(-9)))

/* Int quant #111 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_419_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.006011317018419504f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #112 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_41_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.14654122292995453f),
    AI_PACK_INTQ_ZP(14)))

/* Int quant #113 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_41_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.005665036849677563f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #114 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_426_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.8081459403038025f),
    AI_PACK_INTQ_ZP(-16)))

/* Int quant #115 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_426_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.008097010664641857f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #116 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_430_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.13699516654014587f),
    AI_PACK_INTQ_ZP(44)))

/* Int quant #117 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_430_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.004952824674546719f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #118 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_437_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.24583429098129272f),
    AI_PACK_INTQ_ZP(-1)))

/* Int quant #119 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_437_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.01580393686890602f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #120 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_444_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.8081459403038025f),
    AI_PACK_INTQ_ZP(-16)))

/* Int quant #121 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_444_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.007566437125205994f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #122 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_445_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.11527961492538452f),
    AI_PACK_INTQ_ZP(18)))

/* Int quant #123 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_445_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.004761568736284971f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #124 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_452_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.1947060376405716f),
    AI_PACK_INTQ_ZP(-4)))

/* Int quant #125 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_452_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.009623409248888493f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #126 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_459_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.8081459403038025f),
    AI_PACK_INTQ_ZP(-16)))

/* Int quant #127 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_459_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.007674089632928371f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #128 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_468_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.049250729382038116f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #129 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_468_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.11811023950576782f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #130 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_49_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.09303751587867737f),
    AI_PACK_INTQ_ZP(5)))

/* Int quant #131 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_49_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.002561402041465044f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #132 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_56_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.09846821427345276f),
    AI_PACK_INTQ_ZP(2)))

/* Int quant #133 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_56_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.01080375537276268f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #134 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_65_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.07349041849374771f),
    AI_PACK_INTQ_ZP(26)))

/* Int quant #135 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_65_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.003956887871026993f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #136 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_72_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.07637752592563629f),
    AI_PACK_INTQ_ZP(21)))

/* Int quant #137 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_72_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.006067154463380575f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #138 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_80_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.06741999089717865f),
    AI_PACK_INTQ_ZP(9)))

/* Int quant #139 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_80_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0028184428811073303f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #140 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_87_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.11090601980686188f),
    AI_PACK_INTQ_ZP(-16)))

/* Int quant #141 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_87_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0088935736566782f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #142 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_96_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.09703822433948517f),
    AI_PACK_INTQ_ZP(-12)))

/* Int quant #143 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_96_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.003700427943840623f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #144 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_9_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(1.2350810766220093f),
    AI_PACK_INTQ_ZP(-2)))

/* Int quant #145 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_9_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.016119299456477165f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #146 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conversion_216_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0498603992164135f),
    AI_PACK_INTQ_ZP(-122)))

/* Int quant #147 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conversion_250_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.05415775254368782f),
    AI_PACK_INTQ_ZP(-123)))

/* Int quant #148 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_100_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.10613161325454712f),
    AI_PACK_INTQ_ZP(-1)))

/* Int quant #149 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_101_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.09703822433948517f),
    AI_PACK_INTQ_ZP(-12)))

/* Int quant #150 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_102_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.05415775254368782f),
    AI_PACK_INTQ_ZP(-123)))

/* Int quant #151 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_106_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.007842793129384518f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #152 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_107_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.003921396564692259f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #153 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_108_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.08411892503499985f),
    AI_PACK_INTQ_ZP(-1)))

/* Int quant #154 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_109_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.08141069859266281f),
    AI_PACK_INTQ_ZP(4)))

/* Int quant #155 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_110_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.04044152796268463f),
    AI_PACK_INTQ_ZP(-121)))

/* Int quant #156 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_113_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.007843137718737125f),
    AI_PACK_INTQ_ZP(-1)))

/* Int quant #157 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_114_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.003921568859368563f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #158 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_115_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.1970488727092743f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #159 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_116_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.16380026936531067f),
    AI_PACK_INTQ_ZP(25)))

/* Int quant #160 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_117_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.06855183839797974f),
    AI_PACK_INTQ_ZP(-116)))

/* Int quant #161 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_11_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.007843137718737125f),
    AI_PACK_INTQ_ZP(-1)))

/* Int quant #162 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_122_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.007842876948416233f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #163 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_123_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0039214384742081165f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #164 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_124_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.08090196549892426f),
    AI_PACK_INTQ_ZP(-1)))

/* Int quant #165 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_125_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.08017363399267197f),
    AI_PACK_INTQ_ZP(-2)))

/* Int quant #166 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_126_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.04154166206717491f),
    AI_PACK_INTQ_ZP(-121)))

/* Int quant #167 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_129_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.007842536084353924f),
    AI_PACK_INTQ_ZP(-1)))

/* Int quant #168 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_12_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.003921568859368563f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #169 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_130_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.003921268042176962f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #170 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_131_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.09100321680307388f),
    AI_PACK_INTQ_ZP(-1)))

/* Int quant #171 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_132_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0826624259352684f),
    AI_PACK_INTQ_ZP(12)))

/* Int quant #172 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_133_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.05647860839962959f),
    AI_PACK_INTQ_ZP(-118)))

/* Int quant #173 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_134_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.06855183839797974f),
    AI_PACK_INTQ_ZP(-116)))

/* Int quant #174 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_137_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.007843071594834328f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #175 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_138_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.003921535797417164f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #176 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_139_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.09169914573431015f),
    AI_PACK_INTQ_ZP(-1)))

/* Int quant #177 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_13_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(1.2457950115203857f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #178 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_140_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0893167182803154f),
    AI_PACK_INTQ_ZP(-4)))

/* Int quant #179 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_141_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.046941205859184265f),
    AI_PACK_INTQ_ZP(-122)))

/* Int quant #180 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_144_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00784313678741455f),
    AI_PACK_INTQ_ZP(-1)))

/* Int quant #181 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_145_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.003921568393707275f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #182 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_146_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.1327071636915207f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #183 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_147_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.1311865746974945f),
    AI_PACK_INTQ_ZP(1)))

/* Int quant #184 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_148_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.06842818111181259f),
    AI_PACK_INTQ_ZP(-116)))

/* Int quant #185 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_149_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.06855183839797974f),
    AI_PACK_INTQ_ZP(-116)))

/* Int quant #186 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_14_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(1.2350810766220093f),
    AI_PACK_INTQ_ZP(-2)))

/* Int quant #187 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_153_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.007843106053769588f),
    AI_PACK_INTQ_ZP(-1)))

/* Int quant #188 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_154_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.003921553026884794f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #189 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_155_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.09753715991973877f),
    AI_PACK_INTQ_ZP(-1)))

/* Int quant #190 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_156_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.09093216806650162f),
    AI_PACK_INTQ_ZP(-10)))

/* Int quant #191 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_157_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0498603992164135f),
    AI_PACK_INTQ_ZP(-122)))

/* Int quant #192 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_15_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.6239895224571228f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #193 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_161_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00784244854003191f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #194 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_162_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.003921224270015955f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #195 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_163_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.08767674118280411f),
    AI_PACK_INTQ_ZP(-1)))

/* Int quant #196 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_164_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.08046691119670868f),
    AI_PACK_INTQ_ZP(11)))

/* Int quant #197 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_165_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.037717338651418686f),
    AI_PACK_INTQ_ZP(-121)))

/* Int quant #198 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_168_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.007843135856091976f),
    AI_PACK_INTQ_ZP(-1)))

/* Int quant #199 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_169_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.003921567928045988f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #200 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_170_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.12138929963111877f),
    AI_PACK_INTQ_ZP(-1)))

/* Int quant #201 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_171_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.11005696654319763f),
    AI_PACK_INTQ_ZP(-14)))

/* Int quant #202 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_172_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.08901643753051758f),
    AI_PACK_INTQ_ZP(-122)))

/* Int quant #203 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_177_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.007843134924769402f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #204 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_178_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.003921567462384701f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #205 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_179_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.12041206657886505f),
    AI_PACK_INTQ_ZP(-1)))

/* Int quant #206 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_180_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.10177198797464371f),
    AI_PACK_INTQ_ZP(-24)))

/* Int quant #207 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_181_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.06129803508520126f),
    AI_PACK_INTQ_ZP(-123)))

/* Int quant #208 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_184_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.007843137718737125f),
    AI_PACK_INTQ_ZP(-1)))

/* Int quant #209 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_185_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.003921568859368563f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #210 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_186_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.18393833935260773f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #211 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_187_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.17974503338336945f),
    AI_PACK_INTQ_ZP(2)))

/* Int quant #212 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_188_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.08995989710092545f),
    AI_PACK_INTQ_ZP(-122)))

/* Int quant #213 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_189_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.08901643753051758f),
    AI_PACK_INTQ_ZP(-122)))

/* Int quant #214 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_18_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.007843137718737125f),
    AI_PACK_INTQ_ZP(-1)))

/* Int quant #215 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_193_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.007843131199479103f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #216 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_194_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0039215655997395515f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #217 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_195_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.12747426331043243f),
    AI_PACK_INTQ_ZP(-1)))

/* Int quant #218 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_196_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.1192486584186554f),
    AI_PACK_INTQ_ZP(8)))

/* Int quant #219 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_197_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.05660350248217583f),
    AI_PACK_INTQ_ZP(-123)))

/* Int quant #220 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_19_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.003921568859368563f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #221 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_200_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.007843132130801678f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #222 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_201_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.003921566065400839f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #223 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_202_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.11263586580753326f),
    AI_PACK_INTQ_ZP(-1)))

/* Int quant #224 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_203_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.09822265803813934f),
    AI_PACK_INTQ_ZP(-19)))

/* Int quant #225 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_204_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.05740991607308388f),
    AI_PACK_INTQ_ZP(-123)))

/* Int quant #226 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_20_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.8156404495239258f),
    AI_PACK_INTQ_ZP(-1)))

/* Int quant #227 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_211_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.007834449410438538f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #228 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_212_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.003917224705219269f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #229 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_213_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.12239479273557663f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #230 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_214_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.08788120001554489f),
    AI_PACK_INTQ_ZP(50)))

/* Int quant #231 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_215_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.06318599730730057f),
    AI_PACK_INTQ_ZP(-124)))

/* Int quant #232 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_21_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.5657886862754822f),
    AI_PACK_INTQ_ZP(56)))

/* Int quant #233 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_221_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00784296728670597f),
    AI_PACK_INTQ_ZP(-1)))

/* Int quant #234 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_222_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.003921483643352985f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #235 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_223_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.10067825764417648f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #236 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_224_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.092446468770504f),
    AI_PACK_INTQ_ZP(11)))

/* Int quant #237 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_225_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.053553905338048935f),
    AI_PACK_INTQ_ZP(-123)))

/* Int quant #238 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_22_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.16015248000621796f),
    AI_PACK_INTQ_ZP(-125)))

/* Int quant #239 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_230_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.007843052968382835f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #240 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_231_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.003921526484191418f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #241 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_232_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.09291800111532211f),
    AI_PACK_INTQ_ZP(-1)))

/* Int quant #242 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_233_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.09133733063936234f),
    AI_PACK_INTQ_ZP(2)))

/* Int quant #243 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_234_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.04596986994147301f),
    AI_PACK_INTQ_ZP(-122)))

/* Int quant #244 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_237_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00784312468022108f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #245 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_238_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00392156234011054f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #246 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_239_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.10983041673898697f),
    AI_PACK_INTQ_ZP(-1)))

/* Int quant #247 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_240_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.10737717896699905f),
    AI_PACK_INTQ_ZP(2)))

/* Int quant #248 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_241_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.053553905338048935f),
    AI_PACK_INTQ_ZP(-123)))

/* Int quant #249 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_245_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00784310232847929f),
    AI_PACK_INTQ_ZP(-1)))

/* Int quant #250 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_246_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.003921551164239645f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #251 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_247_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.09779009222984314f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #252 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_248_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.09717833250761032f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #253 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_249_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.05797247961163521f),
    AI_PACK_INTQ_ZP(-123)))

/* Int quant #254 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_255_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.007843028753995895f),
    AI_PACK_INTQ_ZP(-1)))

/* Int quant #255 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_256_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.003921514376997948f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #256 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_257_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.09058341383934021f),
    AI_PACK_INTQ_ZP(-1)))

/* Int quant #257 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_258_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.08915843069553375f),
    AI_PACK_INTQ_ZP(2)))

/* Int quant #258 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_259_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.05578995496034622f),
    AI_PACK_INTQ_ZP(-123)))

/* Int quant #259 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_264_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.007840032689273357f),
    AI_PACK_INTQ_ZP(-1)))

/* Int quant #260 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_265_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.003920016344636679f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #261 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_266_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.06444112956523895f),
    AI_PACK_INTQ_ZP(-1)))

/* Int quant #262 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_267_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.06294285506010056f),
    AI_PACK_INTQ_ZP(3)))

/* Int quant #263 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_268_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.03180215135216713f),
    AI_PACK_INTQ_ZP(-119)))

/* Int quant #264 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_26_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.007843137718737125f),
    AI_PACK_INTQ_ZP(-1)))

/* Int quant #265 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_271_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.007843130268156528f),
    AI_PACK_INTQ_ZP(-1)))

/* Int quant #266 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_272_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.003921565134078264f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #267 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_273_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.11297070980072021f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #268 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_274_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.11118334531784058f),
    AI_PACK_INTQ_ZP(2)))

/* Int quant #269 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_275_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.05578995496034622f),
    AI_PACK_INTQ_ZP(-123)))

/* Int quant #270 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_279_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00784313678741455f),
    AI_PACK_INTQ_ZP(-1)))

/* Int quant #271 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_27_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.003921568859368563f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #272 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_280_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.003921568393707275f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #273 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_281_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.13024306297302246f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #274 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_282_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.1193377822637558f),
    AI_PACK_INTQ_ZP(-12)))

/* Int quant #275 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_283_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.06621354818344116f),
    AI_PACK_INTQ_ZP(-124)))

/* Int quant #276 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_287_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.007843133062124252f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #277 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_288_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.003921566531062126f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #278 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_289_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.11376097798347473f),
    AI_PACK_INTQ_ZP(-1)))

/* Int quant #279 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_28_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.3075443208217621f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #280 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_290_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.1047167181968689f),
    AI_PACK_INTQ_ZP(-12)))

/* Int quant #281 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_291_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.05797247961163521f),
    AI_PACK_INTQ_ZP(-123)))

/* Int quant #282 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_295_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.007843137718737125f),
    AI_PACK_INTQ_ZP(-1)))

/* Int quant #283 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_296_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.003921568859368563f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #284 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_297_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.15958954393863678f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #285 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_298_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.1412927210330963f),
    AI_PACK_INTQ_ZP(-17)))

/* Int quant #286 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_299_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.08479750156402588f),
    AI_PACK_INTQ_ZP(-125)))

/* Int quant #287 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_29_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.28010857105255127f),
    AI_PACK_INTQ_ZP(12)))

/* Int quant #288 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_304_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.007843118160963058f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #289 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_305_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.003921559080481529f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #290 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_306_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.10430991649627686f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #291 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_307_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.10296504944562912f),
    AI_PACK_INTQ_ZP(1)))

/* Int quant #292 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_308_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.05190199241042137f),
    AI_PACK_INTQ_ZP(-123)))

/* Int quant #293 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_30_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.12742842733860016f),
    AI_PACK_INTQ_ZP(-126)))

/* Int quant #294 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_311_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.007843137718737125f),
    AI_PACK_INTQ_ZP(-1)))

/* Int quant #295 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_312_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.003921568859368563f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #296 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_313_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.1674109697341919f),
    AI_PACK_INTQ_ZP(-1)))

/* Int quant #297 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_314_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.16467826068401337f),
    AI_PACK_INTQ_ZP(-3)))

/* Int quant #298 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_315_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.08479750156402588f),
    AI_PACK_INTQ_ZP(-125)))

/* Int quant #299 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_319_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.007843044586479664f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #300 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_320_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.003921522293239832f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #301 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_321_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.23194311559200287f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #302 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_322_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.16047991812229156f),
    AI_PACK_INTQ_ZP(56)))

/* Int quant #303 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_323_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.04559985175728798f),
    AI_PACK_INTQ_ZP(-122)))

/* Int quant #304 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_327_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.007843135856091976f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #305 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_328_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.003921567928045988f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #306 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_329_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.12418796867132187f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #307 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_330_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.1168360561132431f),
    AI_PACK_INTQ_ZP(-9)))

/* Int quant #308 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_331_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.06318599730730057f),
    AI_PACK_INTQ_ZP(-124)))

/* Int quant #309 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_335_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.007843137718737125f),
    AI_PACK_INTQ_ZP(-1)))

/* Int quant #310 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_336_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.003921568859368563f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #311 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_337_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.18063543736934662f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #312 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_338_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.16562919318675995f),
    AI_PACK_INTQ_ZP(-12)))

/* Int quant #313 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_339_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.09351727366447449f),
    AI_PACK_INTQ_ZP(-125)))

/* Int quant #314 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_33_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.007843137718737125f),
    AI_PACK_INTQ_ZP(-1)))

/* Int quant #315 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_344_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00784312654286623f),
    AI_PACK_INTQ_ZP(-1)))

/* Int quant #316 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_345_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.003921563271433115f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #317 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_346_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.12842094898223877f),
    AI_PACK_INTQ_ZP(-1)))

/* Int quant #318 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_347_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.11714307963848114f),
    AI_PACK_INTQ_ZP(12)))

/* Int quant #319 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_348_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.054024551063776016f),
    AI_PACK_INTQ_ZP(-123)))

/* Int quant #320 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_34_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.003921568859368563f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #321 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_351_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.007843137718737125f),
    AI_PACK_INTQ_ZP(-1)))

/* Int quant #322 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_352_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.003921568859368563f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #323 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_353_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.18485049903392792f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #324 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_354_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.16953903436660767f),
    AI_PACK_INTQ_ZP(-12)))

/* Int quant #325 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_355_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.09351727366447449f),
    AI_PACK_INTQ_ZP(-125)))

/* Int quant #326 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_359_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.007843137718737125f),
    AI_PACK_INTQ_ZP(-1)))

/* Int quant #327 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_35_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.3350314497947693f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #328 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_360_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.003921568859368563f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #329 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_361_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.25009456276893616f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #330 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_362_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.19821466505527496f),
    AI_PACK_INTQ_ZP(33)))

/* Int quant #331 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_363_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.07425938546657562f),
    AI_PACK_INTQ_ZP(-124)))

/* Int quant #332 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_366_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.007843137718737125f),
    AI_PACK_INTQ_ZP(-1)))

/* Int quant #333 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_367_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.003921568859368563f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #334 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_368_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.3511773645877838f),
    AI_PACK_INTQ_ZP(-1)))

/* Int quant #335 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_369_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.2520398795604706f),
    AI_PACK_INTQ_ZP(-51)))

/* Int quant #336 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_36_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.2769908308982849f),
    AI_PACK_INTQ_ZP(26)))

/* Int quant #337 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_370_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.17668069899082184f),
    AI_PACK_INTQ_ZP(-126)))

/* Int quant #338 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_373_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.007843137718737125f),
    AI_PACK_INTQ_ZP(-1)))

/* Int quant #339 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_374_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.003921568859368563f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #340 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_375_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.5909105539321899f),
    AI_PACK_INTQ_ZP(-1)))

/* Int quant #341 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_376_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.49280235171318054f),
    AI_PACK_INTQ_ZP(-26)))

/* Int quant #342 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_377_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.2965472936630249f),
    AI_PACK_INTQ_ZP(-127)))

/* Int quant #343 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_37_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.1343773901462555f),
    AI_PACK_INTQ_ZP(-124)))

/* Int quant #344 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_381_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.007843137718737125f),
    AI_PACK_INTQ_ZP(-1)))

/* Int quant #345 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_382_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.003921568859368563f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #346 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_383_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.18190236389636993f),
    AI_PACK_INTQ_ZP(-1)))

/* Int quant #347 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_384_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.13768339157104492f),
    AI_PACK_INTQ_ZP(-41)))

/* Int quant #348 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_385_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0920431986451149f),
    AI_PACK_INTQ_ZP(-125)))

/* Int quant #349 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_388_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.007843137718737125f),
    AI_PACK_INTQ_ZP(-1)))

/* Int quant #350 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_389_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.003921568859368563f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #351 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_38_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.16015248000621796f),
    AI_PACK_INTQ_ZP(-125)))

/* Int quant #352 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_390_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.20038969814777374f),
    AI_PACK_INTQ_ZP(-1)))

/* Int quant #353 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_391_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.16819581389427185f),
    AI_PACK_INTQ_ZP(24)))

/* Int quant #354 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_392_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.06909297406673431f),
    AI_PACK_INTQ_ZP(-124)))

/* Int quant #355 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_399_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.007843137718737125f),
    AI_PACK_INTQ_ZP(-1)))

/* Int quant #356 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_3_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.007843137718737125f),
    AI_PACK_INTQ_ZP(-1)))

/* Int quant #357 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_400_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.003921568859368563f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #358 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_401_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.19857701659202576f),
    AI_PACK_INTQ_ZP(-1)))

/* Int quant #359 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_402_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.18041980266571045f),
    AI_PACK_INTQ_ZP(-13)))

/* Int quant #360 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_403_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.10038052499294281f),
    AI_PACK_INTQ_ZP(-125)))

/* Int quant #361 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_406_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.007843137718737125f),
    AI_PACK_INTQ_ZP(-1)))

/* Int quant #362 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_407_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.003921568859368563f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #363 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_408_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.37335026264190674f),
    AI_PACK_INTQ_ZP(-1)))

/* Int quant #364 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_409_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.3353253901004791f),
    AI_PACK_INTQ_ZP(-15)))

/* Int quant #365 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_410_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.1877671480178833f),
    AI_PACK_INTQ_ZP(-127)))

/* Int quant #366 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_414_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.007843137718737125f),
    AI_PACK_INTQ_ZP(-1)))

/* Int quant #367 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_415_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.003921568859368563f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #368 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_416_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.15652041137218475f),
    AI_PACK_INTQ_ZP(-1)))

/* Int quant #369 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_417_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.1545264720916748f),
    AI_PACK_INTQ_ZP(-2)))

/* Int quant #370 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_418_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.07935222238302231f),
    AI_PACK_INTQ_ZP(-124)))

/* Int quant #371 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_421_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.007843137718737125f),
    AI_PACK_INTQ_ZP(-1)))

/* Int quant #372 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_422_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.003921568859368563f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #373 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_423_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.2856038212776184f),
    AI_PACK_INTQ_ZP(-1)))

/* Int quant #374 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_424_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.2674485146999359f),
    AI_PACK_INTQ_ZP(-9)))

/* Int quant #375 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_425_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.14389392733573914f),
    AI_PACK_INTQ_ZP(-126)))

/* Int quant #376 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_432_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.007843050174415112f),
    AI_PACK_INTQ_ZP(-1)))

/* Int quant #377 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_433_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.003921525087207556f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #378 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_434_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.1845443993806839f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #379 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_435_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.13699516654014587f),
    AI_PACK_INTQ_ZP(44)))

/* Int quant #380 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_436_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.04581448808312416f),
    AI_PACK_INTQ_ZP(-122)))

/* Int quant #381 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_439_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.007843137718737125f),
    AI_PACK_INTQ_ZP(-1)))

/* Int quant #382 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_43_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00784313678741455f),
    AI_PACK_INTQ_ZP(-1)))

/* Int quant #383 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_440_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.003921568859368563f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #384 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_441_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.24592477083206177f),
    AI_PACK_INTQ_ZP(-1)))

/* Int quant #385 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_442_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.24583429098129272f),
    AI_PACK_INTQ_ZP(-1)))

/* Int quant #386 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_443_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.12405440211296082f),
    AI_PACK_INTQ_ZP(-126)))

/* Int quant #387 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_447_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.007843109779059887f),
    AI_PACK_INTQ_ZP(-1)))

/* Int quant #388 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_448_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0039215548895299435f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #389 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_449_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.13205036520957947f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #390 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_44_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.003921568393707275f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #391 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_450_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.11527961492538452f),
    AI_PACK_INTQ_ZP(18)))

/* Int quant #392 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_451_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.05034627392888069f),
    AI_PACK_INTQ_ZP(-122)))

/* Int quant #393 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_454_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.007843137718737125f),
    AI_PACK_INTQ_ZP(-1)))

/* Int quant #394 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_455_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.003921568859368563f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #395 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_456_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.2007354348897934f),
    AI_PACK_INTQ_ZP(-1)))

/* Int quant #396 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_457_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.1947060376405716f),
    AI_PACK_INTQ_ZP(-4)))

/* Int quant #397 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_458_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.10145973414182663f),
    AI_PACK_INTQ_ZP(-125)))

/* Int quant #398 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_45_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.1630837321281433f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #399 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_46_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.14654122292995453f),
    AI_PACK_INTQ_ZP(14)))

/* Int quant #400 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_470_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0026553096249699593f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #401 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_473_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.004839626140892506f),
    AI_PACK_INTQ_ZP(-77)))

/* Int quant #402 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_475_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00490355771034956f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #403 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_476_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.007876715622842312f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #404 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_477_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.004235264845192432f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #405 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_478_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.004235264845192432f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #406 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_47_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.06609135866165161f),
    AI_PACK_INTQ_ZP(-124)))

/* Int quant #407 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_4_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.003921568859368563f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #408 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_51_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.007843042723834515f),
    AI_PACK_INTQ_ZP(-1)))

/* Int quant #409 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_52_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.003921521361917257f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #410 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_53_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.09727724641561508f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #411 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_54_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.09303751587867737f),
    AI_PACK_INTQ_ZP(5)))

/* Int quant #412 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_55_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.04549037292599678f),
    AI_PACK_INTQ_ZP(-122)))

/* Int quant #413 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_58_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00784310046583414f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #414 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_59_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00392155023291707f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #415 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_5_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.5283021330833435f),
    AI_PACK_INTQ_ZP(-1)))

/* Int quant #416 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_60_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.10064035654067993f),
    AI_PACK_INTQ_ZP(-1)))

/* Int quant #417 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_61_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.09846821427345276f),
    AI_PACK_INTQ_ZP(2)))

/* Int quant #418 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_62_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.06768429279327393f),
    AI_PACK_INTQ_ZP(-116)))

/* Int quant #419 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_67_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.007838526740670204f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #420 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_68_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.003919263370335102f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #421 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_69_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.08864003419876099f),
    AI_PACK_INTQ_ZP(-1)))

/* Int quant #422 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_6_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.5219366550445557f),
    AI_PACK_INTQ_ZP(1)))

/* Int quant #423 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_70_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.07349041849374771f),
    AI_PACK_INTQ_ZP(26)))

/* Int quant #424 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_71_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.030245276167988777f),
    AI_PACK_INTQ_ZP(-119)))

/* Int quant #425 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_74_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.007840670645236969f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #426 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_75_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0039203353226184845f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #427 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_76_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.08950553089380264f),
    AI_PACK_INTQ_ZP(-1)))

/* Int quant #428 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_77_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.07637752592563629f),
    AI_PACK_INTQ_ZP(21)))

/* Int quant #429 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_78_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.036727044731378555f),
    AI_PACK_INTQ_ZP(-113)))

/* Int quant #430 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_79_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.06768429279327393f),
    AI_PACK_INTQ_ZP(-116)))

/* Int quant #431 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_7_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.25887757539749146f),
    AI_PACK_INTQ_ZP(-127)))

/* Int quant #432 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_82_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.007840345613658428f),
    AI_PACK_INTQ_ZP(-1)))

/* Int quant #433 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_83_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.003920172806829214f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #434 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_84_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.07256283611059189f),
    AI_PACK_INTQ_ZP(-1)))

/* Int quant #435 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_85_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.06741999089717865f),
    AI_PACK_INTQ_ZP(9)))

/* Int quant #436 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_86_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.03221951425075531f),
    AI_PACK_INTQ_ZP(-119)))

/* Int quant #437 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_89_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.007843135856091976f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #438 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_90_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.003921567928045988f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #439 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_91_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.12445595115423203f),
    AI_PACK_INTQ_ZP(-1)))

/* Int quant #440 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_92_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.11090601980686188f),
    AI_PACK_INTQ_ZP(-16)))

/* Int quant #441 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_93_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.06768429279327393f),
    AI_PACK_INTQ_ZP(-116)))

/* Int quant #442 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_94_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.06768429279327393f),
    AI_PACK_INTQ_ZP(-116)))

/* Int quant #443 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_98_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00784312654286623f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #444 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_99_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.003921563271433115f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #445 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(nl_105_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00390625f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #446 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(nl_10_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00390625f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #447 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(nl_112_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00390625f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #448 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(nl_121_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00390625f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #449 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(nl_128_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00390625f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #450 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(nl_136_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00390625f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #451 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(nl_143_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00390625f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #452 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(nl_152_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00390625f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #453 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(nl_160_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00390625f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #454 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(nl_167_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00390625f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #455 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(nl_176_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00390625f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #456 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(nl_17_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00390625f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #457 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(nl_183_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00390625f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #458 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(nl_192_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00390625f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #459 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(nl_199_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00390625f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #460 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(nl_210_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00390625f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #461 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(nl_220_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00390625f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #462 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(nl_229_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00390625f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #463 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(nl_236_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00390625f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #464 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(nl_244_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00390625f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #465 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(nl_254_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00390625f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #466 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(nl_25_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00390625f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #467 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(nl_263_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00390625f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #468 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(nl_270_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00390625f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #469 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(nl_278_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00390625f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #470 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(nl_286_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00390625f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #471 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(nl_294_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00390625f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #472 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(nl_2_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00390625f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #473 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(nl_303_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00390625f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #474 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(nl_310_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00390625f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #475 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(nl_318_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00390625f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #476 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(nl_326_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00390625f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #477 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(nl_32_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00390625f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #478 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(nl_334_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00390625f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #479 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(nl_343_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00390625f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #480 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(nl_350_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00390625f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #481 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(nl_358_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00390625f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #482 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(nl_365_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00390625f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #483 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(nl_372_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00390625f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #484 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(nl_380_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00390625f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #485 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(nl_387_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00390625f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #486 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(nl_398_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00390625f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #487 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(nl_405_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00390625f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #488 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(nl_413_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00390625f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #489 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(nl_420_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00390625f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #490 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(nl_42_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00390625f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #491 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(nl_431_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00390625f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #492 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(nl_438_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00390625f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #493 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(nl_446_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00390625f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #494 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(nl_453_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00390625f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #495 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(nl_467_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00390625f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #496 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(nl_480_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00390625f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #497 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(nl_50_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00390625f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #498 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(nl_57_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00390625f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #499 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(nl_66_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00390625f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #500 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(nl_73_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00390625f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #501 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(nl_81_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00390625f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #502 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(nl_88_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00390625f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #503 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(nl_97_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00390625f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #504 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(pool_205_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.05740991607308388f),
    AI_PACK_INTQ_ZP(-123)))

/* Int quant #505 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(pool_206_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.05740991607308388f),
    AI_PACK_INTQ_ZP(-123)))

/* Int quant #506 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(pool_207_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.05740991607308388f),
    AI_PACK_INTQ_ZP(-123)))

/* Int quant #507 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(resize_217_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0498603992164135f),
    AI_PACK_INTQ_ZP(-122)))

/* Int quant #508 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(resize_251_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.05415775254368782f),
    AI_PACK_INTQ_ZP(-123)))

/* Int quant #509 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(serving_default_images0_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.003921568859368563f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #510 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(slice_118_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.06855183839797974f),
    AI_PACK_INTQ_ZP(-116)))

/* Int quant #511 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(slice_119_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.06855183839797974f),
    AI_PACK_INTQ_ZP(-116)))

/* Int quant #512 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(slice_173_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.08901643753051758f),
    AI_PACK_INTQ_ZP(-122)))

/* Int quant #513 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(slice_174_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.08901643753051758f),
    AI_PACK_INTQ_ZP(-122)))

/* Int quant #514 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(slice_226_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.053553905338048935f),
    AI_PACK_INTQ_ZP(-123)))

/* Int quant #515 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(slice_227_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.053553905338048935f),
    AI_PACK_INTQ_ZP(-123)))

/* Int quant #516 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(slice_23_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.16015248000621796f),
    AI_PACK_INTQ_ZP(-125)))

/* Int quant #517 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(slice_260_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.05578995496034622f),
    AI_PACK_INTQ_ZP(-123)))

/* Int quant #518 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(slice_261_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.05578995496034622f),
    AI_PACK_INTQ_ZP(-123)))

/* Int quant #519 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(slice_300_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.08479750156402588f),
    AI_PACK_INTQ_ZP(-125)))

/* Int quant #520 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(slice_301_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.08479750156402588f),
    AI_PACK_INTQ_ZP(-125)))

/* Int quant #521 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(slice_340_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.09351727366447449f),
    AI_PACK_INTQ_ZP(-125)))

/* Int quant #522 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(slice_341_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.09351727366447449f),
    AI_PACK_INTQ_ZP(-125)))

/* Int quant #523 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(slice_39_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.16015248000621796f),
    AI_PACK_INTQ_ZP(-125)))

/* Int quant #524 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(slice_464_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.8081459403038025f),
    AI_PACK_INTQ_ZP(-16)))

/* Int quant #525 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(slice_472_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0026553096249699593f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #526 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(slice_474_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0026553096249699593f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #527 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(slice_479_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.8081459403038025f),
    AI_PACK_INTQ_ZP(-16)))

/* Int quant #528 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(slice_63_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.06768429279327393f),
    AI_PACK_INTQ_ZP(-116)))

/* Int quant #529 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(slice_64_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.06768429279327393f),
    AI_PACK_INTQ_ZP(-116)))

/* Int quant #530 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(tfl_pseudo_qconst1_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0038725491613149643f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #531 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(tfl_pseudo_qconst129_4D_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.003921568859368563f),
    AI_PACK_INTQ_ZP(127)))

/* Int quant #532 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(tfl_pseudo_qconst2_4D_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0003921568568330258f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #533 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(tfl_pseudo_qconst_3D_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0019607844296842813f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #534 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(transpose_395_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.8081459403038025f),
    AI_PACK_INTQ_ZP(-16)))

/* Int quant #535 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(transpose_428_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.8081459403038025f),
    AI_PACK_INTQ_ZP(-16)))

/* Int quant #536 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(transpose_461_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.8081459403038025f),
    AI_PACK_INTQ_ZP(-16)))

/* Int quant #537 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(transpose_466_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.8081459403038025f),
    AI_PACK_INTQ_ZP(-16)))

/**  Tensor declarations section  *********************************************/
/* Tensor #0 */
AI_TENSOR_OBJ_DECLARE(
  concat_150_output, AI_STATIC,
  0, 0x1,
  AI_SHAPE_INIT(4, 1, 256, 20, 20), AI_STRIDE_INIT(4, 1, 1, 256, 5120),
  1, &concat_150_output_array, &concat_150_output_array_intq)

/* Tensor #1 */
AI_TENSOR_OBJ_DECLARE(
  concat_190_output, AI_STATIC,
  1, 0x1,
  AI_SHAPE_INIT(4, 1, 384, 10, 10), AI_STRIDE_INIT(4, 1, 1, 384, 3840),
  1, &concat_190_output_array, &concat_190_output_array_intq)

/* Tensor #2 */
AI_TENSOR_OBJ_DECLARE(
  concat_208_output, AI_STATIC,
  2, 0x1,
  AI_SHAPE_INIT(4, 1, 512, 10, 10), AI_STRIDE_INIT(4, 1, 1, 512, 5120),
  1, &concat_208_output_array, &concat_208_output_array_intq)

/* Tensor #3 */
AI_TENSOR_OBJ_DECLARE(
  concat_218_output, AI_STATIC,
  3, 0x1,
  AI_SHAPE_INIT(4, 1, 384, 20, 20), AI_STRIDE_INIT(4, 1, 1, 384, 7680),
  1, &concat_218_output_array, &concat_218_output_array_intq)

/* Tensor #4 */
AI_TENSOR_OBJ_DECLARE(
  concat_242_output, AI_STATIC,
  4, 0x1,
  AI_SHAPE_INIT(4, 1, 192, 20, 20), AI_STRIDE_INIT(4, 1, 1, 192, 3840),
  1, &concat_242_output_array, &concat_242_output_array_intq)

/* Tensor #5 */
AI_TENSOR_OBJ_DECLARE(
  concat_252_output, AI_STATIC,
  5, 0x1,
  AI_SHAPE_INIT(4, 1, 192, 40, 40), AI_STRIDE_INIT(4, 1, 1, 192, 7680),
  1, &concat_252_output_array, &concat_252_output_array_intq)

/* Tensor #6 */
AI_TENSOR_OBJ_DECLARE(
  concat_276_output, AI_STATIC,
  6, 0x1,
  AI_SHAPE_INIT(4, 1, 96, 40, 40), AI_STRIDE_INIT(4, 1, 1, 96, 3840),
  1, &concat_276_output_array, &concat_276_output_array_intq)

/* Tensor #7 */
AI_TENSOR_OBJ_DECLARE(
  concat_292_output, AI_STATIC,
  7, 0x1,
  AI_SHAPE_INIT(4, 1, 192, 20, 20), AI_STRIDE_INIT(4, 1, 1, 192, 3840),
  1, &concat_292_output_array, &concat_292_output_array_intq)

/* Tensor #8 */
AI_TENSOR_OBJ_DECLARE(
  concat_316_output, AI_STATIC,
  8, 0x1,
  AI_SHAPE_INIT(4, 1, 192, 20, 20), AI_STRIDE_INIT(4, 1, 1, 192, 3840),
  1, &concat_316_output_array, &concat_316_output_array_intq)

/* Tensor #9 */
AI_TENSOR_OBJ_DECLARE(
  concat_332_output, AI_STATIC,
  9, 0x1,
  AI_SHAPE_INIT(4, 1, 384, 10, 10), AI_STRIDE_INIT(4, 1, 1, 384, 3840),
  1, &concat_332_output_array, &concat_332_output_array_intq)

/* Tensor #10 */
AI_TENSOR_OBJ_DECLARE(
  concat_356_output, AI_STATIC,
  10, 0x1,
  AI_SHAPE_INIT(4, 1, 384, 10, 10), AI_STRIDE_INIT(4, 1, 1, 384, 3840),
  1, &concat_356_output_array, &concat_356_output_array_intq)

/* Tensor #11 */
AI_TENSOR_OBJ_DECLARE(
  concat_394_output, AI_STATIC,
  11, 0x1,
  AI_SHAPE_INIT(4, 1, 67, 10, 10), AI_STRIDE_INIT(4, 1, 1, 67, 670),
  1, &concat_394_output_array, &concat_394_output_array_intq)

/* Tensor #12 */
AI_TENSOR_OBJ_DECLARE(
  concat_40_output, AI_STATIC,
  12, 0x1,
  AI_SHAPE_INIT(4, 1, 48, 80, 80), AI_STRIDE_INIT(4, 1, 1, 48, 3840),
  1, &concat_40_output_array, &concat_40_output_array_intq)

/* Tensor #13 */
AI_TENSOR_OBJ_DECLARE(
  concat_427_output, AI_STATIC,
  13, 0x1,
  AI_SHAPE_INIT(4, 1, 67, 20, 20), AI_STRIDE_INIT(4, 1, 1, 67, 1340),
  1, &concat_427_output_array, &concat_427_output_array_intq)

/* Tensor #14 */
AI_TENSOR_OBJ_DECLARE(
  concat_460_output, AI_STATIC,
  14, 0x1,
  AI_SHAPE_INIT(4, 1, 67, 40, 40), AI_STRIDE_INIT(4, 1, 1, 67, 2680),
  1, &concat_460_output_array, &concat_460_output_array_intq)

/* Tensor #15 */
AI_TENSOR_OBJ_DECLARE(
  concat_463_output, AI_STATIC,
  15, 0x1,
  AI_SHAPE_INIT(4, 1, 2100, 1, 67), AI_STRIDE_INIT(4, 1, 1, 2100, 2100),
  1, &concat_463_output_array, &concat_463_output_array_intq)

/* Tensor #16 */
AI_TENSOR_OBJ_DECLARE(
  concat_482_output, AI_STATIC,
  16, 0x1,
  AI_SHAPE_INIT(4, 1, 2100, 1, 7), AI_STRIDE_INIT(4, 1, 1, 2100, 2100),
  1, &concat_482_output_array, &concat_482_output_array_intq)

/* Tensor #17 */
AI_TENSOR_OBJ_DECLARE(
  concat_95_output, AI_STATIC,
  17, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 40, 40), AI_STRIDE_INIT(4, 1, 1, 128, 5120),
  1, &concat_95_output_array, &concat_95_output_array_intq)

/* Tensor #18 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_104_bias, AI_STATIC,
  18, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &conv2d_104_bias_array, NULL)

/* Tensor #19 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_104_output, AI_STATIC,
  19, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 20, 20), AI_STRIDE_INIT(4, 1, 1, 128, 2560),
  1, &conv2d_104_output_array, &conv2d_104_output_array_intq)

/* Tensor #20 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_104_scratch0, AI_STATIC,
  20, 0x0,
  AI_SHAPE_INIT(4, 1, 7936, 1, 1), AI_STRIDE_INIT(4, 1, 1, 7936, 7936),
  1, &conv2d_104_scratch0_array, NULL)

/* Tensor #21 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_104_weights, AI_STATIC,
  21, 0x1,
  AI_SHAPE_INIT(4, 64, 3, 3, 128), AI_STRIDE_INIT(4, 1, 64, 8192, 24576),
  1, &conv2d_104_weights_array, &conv2d_104_weights_array_intq)

/* Tensor #22 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_111_bias, AI_STATIC,
  22, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &conv2d_111_bias_array, NULL)

/* Tensor #23 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_111_output, AI_STATIC,
  23, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 20, 20), AI_STRIDE_INIT(4, 1, 1, 128, 2560),
  1, &conv2d_111_output_array, &conv2d_111_output_array_intq)

/* Tensor #24 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_111_scratch0, AI_STATIC,
  24, 0x0,
  AI_SHAPE_INIT(4, 1, 512, 1, 1), AI_STRIDE_INIT(4, 1, 1, 512, 512),
  1, &conv2d_111_scratch0_array, NULL)

/* Tensor #25 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_111_weights, AI_STATIC,
  25, 0x1,
  AI_SHAPE_INIT(4, 128, 1, 1, 128), AI_STRIDE_INIT(4, 1, 128, 16384, 16384),
  1, &conv2d_111_weights_array, &conv2d_111_weights_array_intq)

/* Tensor #26 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_120_bias, AI_STATIC,
  26, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 1, 1), AI_STRIDE_INIT(4, 4, 4, 256, 256),
  1, &conv2d_120_bias_array, NULL)

/* Tensor #27 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_120_output, AI_STATIC,
  27, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 20, 20), AI_STRIDE_INIT(4, 1, 1, 64, 1280),
  1, &conv2d_120_output_array, &conv2d_120_output_array_intq)

/* Tensor #28 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_120_scratch0, AI_STATIC,
  28, 0x0,
  AI_SHAPE_INIT(4, 1, 7680, 1, 1), AI_STRIDE_INIT(4, 1, 1, 7680, 7680),
  1, &conv2d_120_scratch0_array, NULL)

/* Tensor #29 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_120_weights, AI_STATIC,
  29, 0x1,
  AI_SHAPE_INIT(4, 64, 3, 3, 64), AI_STRIDE_INIT(4, 1, 64, 4096, 12288),
  1, &conv2d_120_weights_array, &conv2d_120_weights_array_intq)

/* Tensor #30 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_127_bias, AI_STATIC,
  30, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 1, 1), AI_STRIDE_INIT(4, 4, 4, 256, 256),
  1, &conv2d_127_bias_array, NULL)

/* Tensor #31 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_127_output, AI_STATIC,
  31, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 20, 20), AI_STRIDE_INIT(4, 1, 1, 64, 1280),
  1, &conv2d_127_output_array, &conv2d_127_output_array_intq)

/* Tensor #32 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_127_scratch0, AI_STATIC,
  32, 0x0,
  AI_SHAPE_INIT(4, 1, 7680, 1, 1), AI_STRIDE_INIT(4, 1, 1, 7680, 7680),
  1, &conv2d_127_scratch0_array, NULL)

/* Tensor #33 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_127_weights, AI_STATIC,
  33, 0x1,
  AI_SHAPE_INIT(4, 64, 3, 3, 64), AI_STRIDE_INIT(4, 1, 64, 4096, 12288),
  1, &conv2d_127_weights_array, &conv2d_127_weights_array_intq)

/* Tensor #34 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_135_bias, AI_STATIC,
  34, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 1, 1), AI_STRIDE_INIT(4, 4, 4, 256, 256),
  1, &conv2d_135_bias_array, NULL)

/* Tensor #35 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_135_output, AI_STATIC,
  35, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 20, 20), AI_STRIDE_INIT(4, 1, 1, 64, 1280),
  1, &conv2d_135_output_array, &conv2d_135_output_array_intq)

/* Tensor #36 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_135_scratch0, AI_STATIC,
  36, 0x0,
  AI_SHAPE_INIT(4, 1, 7680, 1, 1), AI_STRIDE_INIT(4, 1, 1, 7680, 7680),
  1, &conv2d_135_scratch0_array, NULL)

/* Tensor #37 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_135_weights, AI_STATIC,
  37, 0x1,
  AI_SHAPE_INIT(4, 64, 3, 3, 64), AI_STRIDE_INIT(4, 1, 64, 4096, 12288),
  1, &conv2d_135_weights_array, &conv2d_135_weights_array_intq)

/* Tensor #38 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_142_bias, AI_STATIC,
  38, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 1, 1), AI_STRIDE_INIT(4, 4, 4, 256, 256),
  1, &conv2d_142_bias_array, NULL)

/* Tensor #39 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_142_output, AI_STATIC,
  39, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 20, 20), AI_STRIDE_INIT(4, 1, 1, 64, 1280),
  1, &conv2d_142_output_array, &conv2d_142_output_array_intq)

/* Tensor #40 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_142_scratch0, AI_STATIC,
  40, 0x0,
  AI_SHAPE_INIT(4, 1, 7680, 1, 1), AI_STRIDE_INIT(4, 1, 1, 7680, 7680),
  1, &conv2d_142_scratch0_array, NULL)

/* Tensor #41 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_142_weights, AI_STATIC,
  41, 0x1,
  AI_SHAPE_INIT(4, 64, 3, 3, 64), AI_STRIDE_INIT(4, 1, 64, 4096, 12288),
  1, &conv2d_142_weights_array, &conv2d_142_weights_array_intq)

/* Tensor #42 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_151_bias, AI_STATIC,
  42, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &conv2d_151_bias_array, NULL)

/* Tensor #43 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_151_output, AI_STATIC,
  43, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 20, 20), AI_STRIDE_INIT(4, 1, 1, 128, 2560),
  1, &conv2d_151_output_array, &conv2d_151_output_array_intq)

/* Tensor #44 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_151_scratch0, AI_STATIC,
  44, 0x0,
  AI_SHAPE_INIT(4, 1, 1024, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1024, 1024),
  1, &conv2d_151_scratch0_array, NULL)

/* Tensor #45 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_151_weights, AI_STATIC,
  45, 0x1,
  AI_SHAPE_INIT(4, 256, 1, 1, 128), AI_STRIDE_INIT(4, 1, 256, 32768, 32768),
  1, &conv2d_151_weights_array, &conv2d_151_weights_array_intq)

/* Tensor #46 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_159_bias, AI_STATIC,
  46, 0x0,
  AI_SHAPE_INIT(4, 1, 256, 1, 1), AI_STRIDE_INIT(4, 4, 4, 1024, 1024),
  1, &conv2d_159_bias_array, NULL)

/* Tensor #47 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_159_output, AI_STATIC,
  47, 0x1,
  AI_SHAPE_INIT(4, 1, 256, 10, 10), AI_STRIDE_INIT(4, 1, 1, 256, 2560),
  1, &conv2d_159_output_array, &conv2d_159_output_array_intq)

/* Tensor #48 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_159_scratch0, AI_STATIC,
  48, 0x0,
  AI_SHAPE_INIT(4, 1, 10752, 1, 1), AI_STRIDE_INIT(4, 1, 1, 10752, 10752),
  1, &conv2d_159_scratch0_array, NULL)

/* Tensor #49 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_159_weights, AI_STATIC,
  49, 0x1,
  AI_SHAPE_INIT(4, 128, 3, 3, 256), AI_STRIDE_INIT(4, 1, 128, 32768, 98304),
  1, &conv2d_159_weights_array, &conv2d_159_weights_array_intq)

/* Tensor #50 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_166_bias, AI_STATIC,
  50, 0x0,
  AI_SHAPE_INIT(4, 1, 256, 1, 1), AI_STRIDE_INIT(4, 4, 4, 1024, 1024),
  1, &conv2d_166_bias_array, NULL)

/* Tensor #51 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_166_output, AI_STATIC,
  51, 0x1,
  AI_SHAPE_INIT(4, 1, 256, 10, 10), AI_STRIDE_INIT(4, 1, 1, 256, 2560),
  1, &conv2d_166_output_array, &conv2d_166_output_array_intq)

/* Tensor #52 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_166_scratch0, AI_STATIC,
  52, 0x0,
  AI_SHAPE_INIT(4, 1, 1024, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1024, 1024),
  1, &conv2d_166_scratch0_array, NULL)

/* Tensor #53 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_166_weights, AI_STATIC,
  53, 0x1,
  AI_SHAPE_INIT(4, 256, 1, 1, 256), AI_STRIDE_INIT(4, 1, 256, 65536, 65536),
  1, &conv2d_166_weights_array, &conv2d_166_weights_array_intq)

/* Tensor #54 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_16_bias, AI_STATIC,
  54, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &conv2d_16_bias_array, NULL)

/* Tensor #55 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_16_output, AI_STATIC,
  55, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 80, 80), AI_STRIDE_INIT(4, 1, 1, 32, 2560),
  1, &conv2d_16_output_array, &conv2d_16_output_array_intq)

/* Tensor #56 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_16_scratch0, AI_STATIC,
  56, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 1, 1, 128, 128),
  1, &conv2d_16_scratch0_array, NULL)

/* Tensor #57 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_16_weights, AI_STATIC,
  57, 0x1,
  AI_SHAPE_INIT(4, 32, 1, 1, 32), AI_STRIDE_INIT(4, 1, 32, 1024, 1024),
  1, &conv2d_16_weights_array, &conv2d_16_weights_array_intq)

/* Tensor #58 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_175_bias, AI_STATIC,
  58, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &conv2d_175_bias_array, NULL)

/* Tensor #59 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_175_output, AI_STATIC,
  59, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 10, 10), AI_STRIDE_INIT(4, 1, 1, 128, 1280),
  1, &conv2d_175_output_array, &conv2d_175_output_array_intq)

/* Tensor #60 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_175_scratch0, AI_STATIC,
  60, 0x0,
  AI_SHAPE_INIT(4, 1, 10240, 1, 1), AI_STRIDE_INIT(4, 1, 1, 10240, 10240),
  1, &conv2d_175_scratch0_array, NULL)

/* Tensor #61 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_175_weights, AI_STATIC,
  61, 0x1,
  AI_SHAPE_INIT(4, 128, 3, 3, 128), AI_STRIDE_INIT(4, 1, 128, 16384, 49152),
  1, &conv2d_175_weights_array, &conv2d_175_weights_array_intq)

/* Tensor #62 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_182_bias, AI_STATIC,
  62, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &conv2d_182_bias_array, NULL)

/* Tensor #63 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_182_output, AI_STATIC,
  63, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 10, 10), AI_STRIDE_INIT(4, 1, 1, 128, 1280),
  1, &conv2d_182_output_array, &conv2d_182_output_array_intq)

/* Tensor #64 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_182_scratch0, AI_STATIC,
  64, 0x0,
  AI_SHAPE_INIT(4, 1, 10240, 1, 1), AI_STRIDE_INIT(4, 1, 1, 10240, 10240),
  1, &conv2d_182_scratch0_array, NULL)

/* Tensor #65 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_182_weights, AI_STATIC,
  65, 0x1,
  AI_SHAPE_INIT(4, 128, 3, 3, 128), AI_STRIDE_INIT(4, 1, 128, 16384, 49152),
  1, &conv2d_182_weights_array, &conv2d_182_weights_array_intq)

/* Tensor #66 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_191_bias, AI_STATIC,
  66, 0x0,
  AI_SHAPE_INIT(4, 1, 256, 1, 1), AI_STRIDE_INIT(4, 4, 4, 1024, 1024),
  1, &conv2d_191_bias_array, NULL)

/* Tensor #67 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_191_output, AI_STATIC,
  67, 0x1,
  AI_SHAPE_INIT(4, 1, 256, 10, 10), AI_STRIDE_INIT(4, 1, 1, 256, 2560),
  1, &conv2d_191_output_array, &conv2d_191_output_array_intq)

/* Tensor #68 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_191_scratch0, AI_STATIC,
  68, 0x0,
  AI_SHAPE_INIT(4, 1, 1536, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1536, 1536),
  1, &conv2d_191_scratch0_array, NULL)

/* Tensor #69 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_191_weights, AI_STATIC,
  69, 0x1,
  AI_SHAPE_INIT(4, 384, 1, 1, 256), AI_STRIDE_INIT(4, 1, 384, 98304, 98304),
  1, &conv2d_191_weights_array, &conv2d_191_weights_array_intq)

/* Tensor #70 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_198_bias, AI_STATIC,
  70, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &conv2d_198_bias_array, NULL)

/* Tensor #71 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_198_output, AI_STATIC,
  71, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 10, 10), AI_STRIDE_INIT(4, 1, 1, 128, 1280),
  1, &conv2d_198_output_array, &conv2d_198_output_array_intq)

/* Tensor #72 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_198_scratch0, AI_STATIC,
  72, 0x0,
  AI_SHAPE_INIT(4, 1, 1024, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1024, 1024),
  1, &conv2d_198_scratch0_array, NULL)

/* Tensor #73 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_198_weights, AI_STATIC,
  73, 0x1,
  AI_SHAPE_INIT(4, 256, 1, 1, 128), AI_STRIDE_INIT(4, 1, 256, 32768, 32768),
  1, &conv2d_198_weights_array, &conv2d_198_weights_array_intq)

/* Tensor #74 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_1_bias, AI_STATIC,
  74, 0x0,
  AI_SHAPE_INIT(4, 1, 16, 1, 1), AI_STRIDE_INIT(4, 4, 4, 64, 64),
  1, &conv2d_1_bias_array, NULL)

/* Tensor #75 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_1_output, AI_STATIC,
  75, 0x1,
  AI_SHAPE_INIT(4, 1, 16, 160, 160), AI_STRIDE_INIT(4, 1, 1, 16, 2560),
  1, &conv2d_1_output_array, &conv2d_1_output_array_intq)

/* Tensor #76 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_1_scratch0, AI_STATIC,
  76, 0x0,
  AI_SHAPE_INIT(4, 1, 1036, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1036, 1036),
  1, &conv2d_1_scratch0_array, NULL)

/* Tensor #77 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_1_weights, AI_STATIC,
  77, 0x1,
  AI_SHAPE_INIT(4, 3, 3, 3, 16), AI_STRIDE_INIT(4, 1, 3, 48, 144),
  1, &conv2d_1_weights_array, &conv2d_1_weights_array_intq)

/* Tensor #78 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_209_bias, AI_STATIC,
  78, 0x0,
  AI_SHAPE_INIT(4, 1, 256, 1, 1), AI_STRIDE_INIT(4, 4, 4, 1024, 1024),
  1, &conv2d_209_bias_array, NULL)

/* Tensor #79 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_209_output, AI_STATIC,
  79, 0x1,
  AI_SHAPE_INIT(4, 1, 256, 10, 10), AI_STRIDE_INIT(4, 1, 1, 256, 2560),
  1, &conv2d_209_output_array, &conv2d_209_output_array_intq)

/* Tensor #80 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_209_scratch0, AI_STATIC,
  80, 0x0,
  AI_SHAPE_INIT(4, 1, 2048, 1, 1), AI_STRIDE_INIT(4, 1, 1, 2048, 2048),
  1, &conv2d_209_scratch0_array, NULL)

/* Tensor #81 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_209_weights, AI_STATIC,
  81, 0x1,
  AI_SHAPE_INIT(4, 512, 1, 1, 256), AI_STRIDE_INIT(4, 1, 512, 131072, 131072),
  1, &conv2d_209_weights_array, &conv2d_209_weights_array_intq)

/* Tensor #82 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_219_bias, AI_STATIC,
  82, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &conv2d_219_bias_array, NULL)

/* Tensor #83 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_219_output, AI_STATIC,
  83, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 20, 20), AI_STRIDE_INIT(4, 1, 1, 128, 2560),
  1, &conv2d_219_output_array, &conv2d_219_output_array_intq)

/* Tensor #84 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_219_scratch0, AI_STATIC,
  84, 0x0,
  AI_SHAPE_INIT(4, 1, 1536, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1536, 1536),
  1, &conv2d_219_scratch0_array, NULL)

/* Tensor #85 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_219_weights, AI_STATIC,
  85, 0x1,
  AI_SHAPE_INIT(4, 384, 1, 1, 128), AI_STRIDE_INIT(4, 1, 384, 49152, 49152),
  1, &conv2d_219_weights_array, &conv2d_219_weights_array_intq)

/* Tensor #86 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_228_bias, AI_STATIC,
  86, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 1, 1), AI_STRIDE_INIT(4, 4, 4, 256, 256),
  1, &conv2d_228_bias_array, NULL)

/* Tensor #87 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_228_output, AI_STATIC,
  87, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 20, 20), AI_STRIDE_INIT(4, 1, 1, 64, 1280),
  1, &conv2d_228_output_array, &conv2d_228_output_array_intq)

/* Tensor #88 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_228_scratch0, AI_STATIC,
  88, 0x0,
  AI_SHAPE_INIT(4, 1, 7680, 1, 1), AI_STRIDE_INIT(4, 1, 1, 7680, 7680),
  1, &conv2d_228_scratch0_array, NULL)

/* Tensor #89 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_228_weights, AI_STATIC,
  89, 0x1,
  AI_SHAPE_INIT(4, 64, 3, 3, 64), AI_STRIDE_INIT(4, 1, 64, 4096, 12288),
  1, &conv2d_228_weights_array, &conv2d_228_weights_array_intq)

/* Tensor #90 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_235_bias, AI_STATIC,
  90, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 1, 1), AI_STRIDE_INIT(4, 4, 4, 256, 256),
  1, &conv2d_235_bias_array, NULL)

/* Tensor #91 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_235_output, AI_STATIC,
  91, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 20, 20), AI_STRIDE_INIT(4, 1, 1, 64, 1280),
  1, &conv2d_235_output_array, &conv2d_235_output_array_intq)

/* Tensor #92 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_235_scratch0, AI_STATIC,
  92, 0x0,
  AI_SHAPE_INIT(4, 1, 7680, 1, 1), AI_STRIDE_INIT(4, 1, 1, 7680, 7680),
  1, &conv2d_235_scratch0_array, NULL)

/* Tensor #93 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_235_weights, AI_STATIC,
  93, 0x1,
  AI_SHAPE_INIT(4, 64, 3, 3, 64), AI_STRIDE_INIT(4, 1, 64, 4096, 12288),
  1, &conv2d_235_weights_array, &conv2d_235_weights_array_intq)

/* Tensor #94 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_243_bias, AI_STATIC,
  94, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &conv2d_243_bias_array, NULL)

/* Tensor #95 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_243_output, AI_STATIC,
  95, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 20, 20), AI_STRIDE_INIT(4, 1, 1, 128, 2560),
  1, &conv2d_243_output_array, &conv2d_243_output_array_intq)

/* Tensor #96 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_243_scratch0, AI_STATIC,
  96, 0x0,
  AI_SHAPE_INIT(4, 1, 768, 1, 1), AI_STRIDE_INIT(4, 1, 1, 768, 768),
  1, &conv2d_243_scratch0_array, NULL)

/* Tensor #97 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_243_weights, AI_STATIC,
  97, 0x1,
  AI_SHAPE_INIT(4, 192, 1, 1, 128), AI_STRIDE_INIT(4, 1, 192, 24576, 24576),
  1, &conv2d_243_weights_array, &conv2d_243_weights_array_intq)

/* Tensor #98 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_24_bias, AI_STATIC,
  98, 0x0,
  AI_SHAPE_INIT(4, 1, 16, 1, 1), AI_STRIDE_INIT(4, 4, 4, 64, 64),
  1, &conv2d_24_bias_array, NULL)

/* Tensor #99 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_24_output, AI_STATIC,
  99, 0x1,
  AI_SHAPE_INIT(4, 1, 16, 80, 80), AI_STRIDE_INIT(4, 1, 1, 16, 1280),
  1, &conv2d_24_output_array, &conv2d_24_output_array_intq)

/* Tensor #100 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_24_scratch0, AI_STATIC,
  100, 0x0,
  AI_SHAPE_INIT(4, 1, 5248, 1, 1), AI_STRIDE_INIT(4, 1, 1, 5248, 5248),
  1, &conv2d_24_scratch0_array, NULL)

/* Tensor #101 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_24_weights, AI_STATIC,
  101, 0x1,
  AI_SHAPE_INIT(4, 16, 3, 3, 16), AI_STRIDE_INIT(4, 1, 16, 256, 768),
  1, &conv2d_24_weights_array, &conv2d_24_weights_array_intq)

/* Tensor #102 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_253_bias, AI_STATIC,
  102, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 1, 1), AI_STRIDE_INIT(4, 4, 4, 256, 256),
  1, &conv2d_253_bias_array, NULL)

/* Tensor #103 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_253_output, AI_STATIC,
  103, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 40, 40), AI_STRIDE_INIT(4, 1, 1, 64, 2560),
  1, &conv2d_253_output_array, &conv2d_253_output_array_intq)

/* Tensor #104 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_253_scratch0, AI_STATIC,
  104, 0x0,
  AI_SHAPE_INIT(4, 1, 768, 1, 1), AI_STRIDE_INIT(4, 1, 1, 768, 768),
  1, &conv2d_253_scratch0_array, NULL)

/* Tensor #105 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_253_weights, AI_STATIC,
  105, 0x1,
  AI_SHAPE_INIT(4, 192, 1, 1, 64), AI_STRIDE_INIT(4, 1, 192, 12288, 12288),
  1, &conv2d_253_weights_array, &conv2d_253_weights_array_intq)

/* Tensor #106 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_262_bias, AI_STATIC,
  106, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &conv2d_262_bias_array, NULL)

/* Tensor #107 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_262_output, AI_STATIC,
  107, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 40, 40), AI_STRIDE_INIT(4, 1, 1, 32, 1280),
  1, &conv2d_262_output_array, &conv2d_262_output_array_intq)

/* Tensor #108 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_262_scratch0, AI_STATIC,
  108, 0x0,
  AI_SHAPE_INIT(4, 1, 6400, 1, 1), AI_STRIDE_INIT(4, 1, 1, 6400, 6400),
  1, &conv2d_262_scratch0_array, NULL)

/* Tensor #109 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_262_weights, AI_STATIC,
  109, 0x1,
  AI_SHAPE_INIT(4, 32, 3, 3, 32), AI_STRIDE_INIT(4, 1, 32, 1024, 3072),
  1, &conv2d_262_weights_array, &conv2d_262_weights_array_intq)

/* Tensor #110 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_269_bias, AI_STATIC,
  110, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &conv2d_269_bias_array, NULL)

/* Tensor #111 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_269_output, AI_STATIC,
  111, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 40, 40), AI_STRIDE_INIT(4, 1, 1, 32, 1280),
  1, &conv2d_269_output_array, &conv2d_269_output_array_intq)

/* Tensor #112 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_269_scratch0, AI_STATIC,
  112, 0x0,
  AI_SHAPE_INIT(4, 1, 6400, 1, 1), AI_STRIDE_INIT(4, 1, 1, 6400, 6400),
  1, &conv2d_269_scratch0_array, NULL)

/* Tensor #113 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_269_weights, AI_STATIC,
  113, 0x1,
  AI_SHAPE_INIT(4, 32, 3, 3, 32), AI_STRIDE_INIT(4, 1, 32, 1024, 3072),
  1, &conv2d_269_weights_array, &conv2d_269_weights_array_intq)

/* Tensor #114 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_277_bias, AI_STATIC,
  114, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 1, 1), AI_STRIDE_INIT(4, 4, 4, 256, 256),
  1, &conv2d_277_bias_array, NULL)

/* Tensor #115 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_277_output, AI_STATIC,
  115, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 40, 40), AI_STRIDE_INIT(4, 1, 1, 64, 2560),
  1, &conv2d_277_output_array, &conv2d_277_output_array_intq)

/* Tensor #116 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_277_scratch0, AI_STATIC,
  116, 0x0,
  AI_SHAPE_INIT(4, 1, 384, 1, 1), AI_STRIDE_INIT(4, 1, 1, 384, 384),
  1, &conv2d_277_scratch0_array, NULL)

/* Tensor #117 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_277_weights, AI_STATIC,
  117, 0x1,
  AI_SHAPE_INIT(4, 96, 1, 1, 64), AI_STRIDE_INIT(4, 1, 96, 6144, 6144),
  1, &conv2d_277_weights_array, &conv2d_277_weights_array_intq)

/* Tensor #118 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_285_bias, AI_STATIC,
  118, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 1, 1), AI_STRIDE_INIT(4, 4, 4, 256, 256),
  1, &conv2d_285_bias_array, NULL)

/* Tensor #119 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_285_output, AI_STATIC,
  119, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 20, 20), AI_STRIDE_INIT(4, 1, 1, 64, 1280),
  1, &conv2d_285_output_array, &conv2d_285_output_array_intq)

/* Tensor #120 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_285_scratch0, AI_STATIC,
  120, 0x0,
  AI_SHAPE_INIT(4, 1, 7680, 1, 1), AI_STRIDE_INIT(4, 1, 1, 7680, 7680),
  1, &conv2d_285_scratch0_array, NULL)

/* Tensor #121 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_285_weights, AI_STATIC,
  121, 0x1,
  AI_SHAPE_INIT(4, 64, 3, 3, 64), AI_STRIDE_INIT(4, 1, 64, 4096, 12288),
  1, &conv2d_285_weights_array, &conv2d_285_weights_array_intq)

/* Tensor #122 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_293_bias, AI_STATIC,
  122, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &conv2d_293_bias_array, NULL)

/* Tensor #123 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_293_output, AI_STATIC,
  123, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 20, 20), AI_STRIDE_INIT(4, 1, 1, 128, 2560),
  1, &conv2d_293_output_array, &conv2d_293_output_array_intq)

/* Tensor #124 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_293_scratch0, AI_STATIC,
  124, 0x0,
  AI_SHAPE_INIT(4, 1, 768, 1, 1), AI_STRIDE_INIT(4, 1, 1, 768, 768),
  1, &conv2d_293_scratch0_array, NULL)

/* Tensor #125 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_293_weights, AI_STATIC,
  125, 0x1,
  AI_SHAPE_INIT(4, 192, 1, 1, 128), AI_STRIDE_INIT(4, 1, 192, 24576, 24576),
  1, &conv2d_293_weights_array, &conv2d_293_weights_array_intq)

/* Tensor #126 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_302_bias, AI_STATIC,
  126, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 1, 1), AI_STRIDE_INIT(4, 4, 4, 256, 256),
  1, &conv2d_302_bias_array, NULL)

/* Tensor #127 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_302_output, AI_STATIC,
  127, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 20, 20), AI_STRIDE_INIT(4, 1, 1, 64, 1280),
  1, &conv2d_302_output_array, &conv2d_302_output_array_intq)

/* Tensor #128 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_302_scratch0, AI_STATIC,
  128, 0x0,
  AI_SHAPE_INIT(4, 1, 7680, 1, 1), AI_STRIDE_INIT(4, 1, 1, 7680, 7680),
  1, &conv2d_302_scratch0_array, NULL)

/* Tensor #129 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_302_weights, AI_STATIC,
  129, 0x1,
  AI_SHAPE_INIT(4, 64, 3, 3, 64), AI_STRIDE_INIT(4, 1, 64, 4096, 12288),
  1, &conv2d_302_weights_array, &conv2d_302_weights_array_intq)

/* Tensor #130 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_309_bias, AI_STATIC,
  130, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 1, 1), AI_STRIDE_INIT(4, 4, 4, 256, 256),
  1, &conv2d_309_bias_array, NULL)

/* Tensor #131 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_309_output, AI_STATIC,
  131, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 20, 20), AI_STRIDE_INIT(4, 1, 1, 64, 1280),
  1, &conv2d_309_output_array, &conv2d_309_output_array_intq)

/* Tensor #132 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_309_scratch0, AI_STATIC,
  132, 0x0,
  AI_SHAPE_INIT(4, 1, 7680, 1, 1), AI_STRIDE_INIT(4, 1, 1, 7680, 7680),
  1, &conv2d_309_scratch0_array, NULL)

/* Tensor #133 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_309_weights, AI_STATIC,
  133, 0x1,
  AI_SHAPE_INIT(4, 64, 3, 3, 64), AI_STRIDE_INIT(4, 1, 64, 4096, 12288),
  1, &conv2d_309_weights_array, &conv2d_309_weights_array_intq)

/* Tensor #134 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_317_bias, AI_STATIC,
  134, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &conv2d_317_bias_array, NULL)

/* Tensor #135 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_317_output, AI_STATIC,
  135, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 20, 20), AI_STRIDE_INIT(4, 1, 1, 128, 2560),
  1, &conv2d_317_output_array, &conv2d_317_output_array_intq)

/* Tensor #136 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_317_scratch0, AI_STATIC,
  136, 0x0,
  AI_SHAPE_INIT(4, 1, 768, 1, 1), AI_STRIDE_INIT(4, 1, 1, 768, 768),
  1, &conv2d_317_scratch0_array, NULL)

/* Tensor #137 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_317_weights, AI_STATIC,
  137, 0x1,
  AI_SHAPE_INIT(4, 192, 1, 1, 128), AI_STRIDE_INIT(4, 1, 192, 24576, 24576),
  1, &conv2d_317_weights_array, &conv2d_317_weights_array_intq)

/* Tensor #138 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_31_bias, AI_STATIC,
  138, 0x0,
  AI_SHAPE_INIT(4, 1, 16, 1, 1), AI_STRIDE_INIT(4, 4, 4, 64, 64),
  1, &conv2d_31_bias_array, NULL)

/* Tensor #139 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_31_output, AI_STATIC,
  139, 0x1,
  AI_SHAPE_INIT(4, 1, 16, 80, 80), AI_STRIDE_INIT(4, 1, 1, 16, 1280),
  1, &conv2d_31_output_array, &conv2d_31_output_array_intq)

/* Tensor #140 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_31_scratch0, AI_STATIC,
  140, 0x0,
  AI_SHAPE_INIT(4, 1, 5248, 1, 1), AI_STRIDE_INIT(4, 1, 1, 5248, 5248),
  1, &conv2d_31_scratch0_array, NULL)

/* Tensor #141 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_31_weights, AI_STATIC,
  141, 0x1,
  AI_SHAPE_INIT(4, 16, 3, 3, 16), AI_STRIDE_INIT(4, 1, 16, 256, 768),
  1, &conv2d_31_weights_array, &conv2d_31_weights_array_intq)

/* Tensor #142 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_325_bias, AI_STATIC,
  142, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &conv2d_325_bias_array, NULL)

/* Tensor #143 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_325_output, AI_STATIC,
  143, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 10, 10), AI_STRIDE_INIT(4, 1, 1, 128, 1280),
  1, &conv2d_325_output_array, &conv2d_325_output_array_intq)

/* Tensor #144 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_325_scratch0, AI_STATIC,
  144, 0x0,
  AI_SHAPE_INIT(4, 1, 10240, 1, 1), AI_STRIDE_INIT(4, 1, 1, 10240, 10240),
  1, &conv2d_325_scratch0_array, NULL)

/* Tensor #145 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_325_weights, AI_STATIC,
  145, 0x1,
  AI_SHAPE_INIT(4, 128, 3, 3, 128), AI_STRIDE_INIT(4, 1, 128, 16384, 49152),
  1, &conv2d_325_weights_array, &conv2d_325_weights_array_intq)

/* Tensor #146 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_333_bias, AI_STATIC,
  146, 0x0,
  AI_SHAPE_INIT(4, 1, 256, 1, 1), AI_STRIDE_INIT(4, 4, 4, 1024, 1024),
  1, &conv2d_333_bias_array, NULL)

/* Tensor #147 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_333_output, AI_STATIC,
  147, 0x1,
  AI_SHAPE_INIT(4, 1, 256, 10, 10), AI_STRIDE_INIT(4, 1, 1, 256, 2560),
  1, &conv2d_333_output_array, &conv2d_333_output_array_intq)

/* Tensor #148 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_333_scratch0, AI_STATIC,
  148, 0x0,
  AI_SHAPE_INIT(4, 1, 1536, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1536, 1536),
  1, &conv2d_333_scratch0_array, NULL)

/* Tensor #149 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_333_weights, AI_STATIC,
  149, 0x1,
  AI_SHAPE_INIT(4, 384, 1, 1, 256), AI_STRIDE_INIT(4, 1, 384, 98304, 98304),
  1, &conv2d_333_weights_array, &conv2d_333_weights_array_intq)

/* Tensor #150 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_342_bias, AI_STATIC,
  150, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &conv2d_342_bias_array, NULL)

/* Tensor #151 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_342_output, AI_STATIC,
  151, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 10, 10), AI_STRIDE_INIT(4, 1, 1, 128, 1280),
  1, &conv2d_342_output_array, &conv2d_342_output_array_intq)

/* Tensor #152 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_342_scratch0, AI_STATIC,
  152, 0x0,
  AI_SHAPE_INIT(4, 1, 10240, 1, 1), AI_STRIDE_INIT(4, 1, 1, 10240, 10240),
  1, &conv2d_342_scratch0_array, NULL)

/* Tensor #153 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_342_weights, AI_STATIC,
  153, 0x1,
  AI_SHAPE_INIT(4, 128, 3, 3, 128), AI_STRIDE_INIT(4, 1, 128, 16384, 49152),
  1, &conv2d_342_weights_array, &conv2d_342_weights_array_intq)

/* Tensor #154 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_349_bias, AI_STATIC,
  154, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &conv2d_349_bias_array, NULL)

/* Tensor #155 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_349_output, AI_STATIC,
  155, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 10, 10), AI_STRIDE_INIT(4, 1, 1, 128, 1280),
  1, &conv2d_349_output_array, &conv2d_349_output_array_intq)

/* Tensor #156 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_349_scratch0, AI_STATIC,
  156, 0x0,
  AI_SHAPE_INIT(4, 1, 10240, 1, 1), AI_STRIDE_INIT(4, 1, 1, 10240, 10240),
  1, &conv2d_349_scratch0_array, NULL)

/* Tensor #157 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_349_weights, AI_STATIC,
  157, 0x1,
  AI_SHAPE_INIT(4, 128, 3, 3, 128), AI_STRIDE_INIT(4, 1, 128, 16384, 49152),
  1, &conv2d_349_weights_array, &conv2d_349_weights_array_intq)

/* Tensor #158 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_357_bias, AI_STATIC,
  158, 0x0,
  AI_SHAPE_INIT(4, 1, 256, 1, 1), AI_STRIDE_INIT(4, 4, 4, 1024, 1024),
  1, &conv2d_357_bias_array, NULL)

/* Tensor #159 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_357_output, AI_STATIC,
  159, 0x1,
  AI_SHAPE_INIT(4, 1, 256, 10, 10), AI_STRIDE_INIT(4, 1, 1, 256, 2560),
  1, &conv2d_357_output_array, &conv2d_357_output_array_intq)

/* Tensor #160 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_357_scratch0, AI_STATIC,
  160, 0x0,
  AI_SHAPE_INIT(4, 1, 1536, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1536, 1536),
  1, &conv2d_357_scratch0_array, NULL)

/* Tensor #161 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_357_weights, AI_STATIC,
  161, 0x1,
  AI_SHAPE_INIT(4, 384, 1, 1, 256), AI_STRIDE_INIT(4, 1, 384, 98304, 98304),
  1, &conv2d_357_weights_array, &conv2d_357_weights_array_intq)

/* Tensor #162 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_364_bias, AI_STATIC,
  162, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 1, 1), AI_STRIDE_INIT(4, 4, 4, 256, 256),
  1, &conv2d_364_bias_array, NULL)

/* Tensor #163 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_364_output, AI_STATIC,
  163, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 10, 10), AI_STRIDE_INIT(4, 1, 1, 64, 640),
  1, &conv2d_364_output_array, &conv2d_364_output_array_intq)

/* Tensor #164 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_364_scratch0, AI_STATIC,
  164, 0x0,
  AI_SHAPE_INIT(4, 1, 14592, 1, 1), AI_STRIDE_INIT(4, 1, 1, 14592, 14592),
  1, &conv2d_364_scratch0_array, NULL)

/* Tensor #165 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_364_weights, AI_STATIC,
  165, 0x1,
  AI_SHAPE_INIT(4, 256, 3, 3, 64), AI_STRIDE_INIT(4, 1, 256, 16384, 49152),
  1, &conv2d_364_weights_array, &conv2d_364_weights_array_intq)

/* Tensor #166 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_371_bias, AI_STATIC,
  166, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 1, 1), AI_STRIDE_INIT(4, 4, 4, 256, 256),
  1, &conv2d_371_bias_array, NULL)

/* Tensor #167 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_371_output, AI_STATIC,
  167, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 10, 10), AI_STRIDE_INIT(4, 1, 1, 64, 640),
  1, &conv2d_371_output_array, &conv2d_371_output_array_intq)

/* Tensor #168 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_371_scratch0, AI_STATIC,
  168, 0x0,
  AI_SHAPE_INIT(4, 1, 7680, 1, 1), AI_STRIDE_INIT(4, 1, 1, 7680, 7680),
  1, &conv2d_371_scratch0_array, NULL)

/* Tensor #169 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_371_weights, AI_STATIC,
  169, 0x1,
  AI_SHAPE_INIT(4, 64, 3, 3, 64), AI_STRIDE_INIT(4, 1, 64, 4096, 12288),
  1, &conv2d_371_weights_array, &conv2d_371_weights_array_intq)

/* Tensor #170 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_378_bias, AI_STATIC,
  170, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 1, 1), AI_STRIDE_INIT(4, 4, 4, 256, 256),
  1, &conv2d_378_bias_array, NULL)

/* Tensor #171 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_378_output, AI_STATIC,
  171, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 10, 10), AI_STRIDE_INIT(4, 1, 1, 64, 640),
  1, &conv2d_378_output_array, &conv2d_378_output_array_intq)

/* Tensor #172 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_378_scratch0, AI_STATIC,
  172, 0x0,
  AI_SHAPE_INIT(4, 1, 256, 1, 1), AI_STRIDE_INIT(4, 1, 1, 256, 256),
  1, &conv2d_378_scratch0_array, NULL)

/* Tensor #173 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_378_weights, AI_STATIC,
  173, 0x1,
  AI_SHAPE_INIT(4, 64, 1, 1, 64), AI_STRIDE_INIT(4, 1, 64, 4096, 4096),
  1, &conv2d_378_weights_array, &conv2d_378_weights_array_intq)

/* Tensor #174 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_379_bias, AI_STATIC,
  174, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 1, 1), AI_STRIDE_INIT(4, 4, 4, 256, 256),
  1, &conv2d_379_bias_array, NULL)

/* Tensor #175 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_379_output, AI_STATIC,
  175, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 10, 10), AI_STRIDE_INIT(4, 1, 1, 64, 640),
  1, &conv2d_379_output_array, &conv2d_379_output_array_intq)

/* Tensor #176 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_379_scratch0, AI_STATIC,
  176, 0x0,
  AI_SHAPE_INIT(4, 1, 14592, 1, 1), AI_STRIDE_INIT(4, 1, 1, 14592, 14592),
  1, &conv2d_379_scratch0_array, NULL)

/* Tensor #177 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_379_weights, AI_STATIC,
  177, 0x1,
  AI_SHAPE_INIT(4, 256, 3, 3, 64), AI_STRIDE_INIT(4, 1, 256, 16384, 49152),
  1, &conv2d_379_weights_array, &conv2d_379_weights_array_intq)

/* Tensor #178 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_386_bias, AI_STATIC,
  178, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 1, 1), AI_STRIDE_INIT(4, 4, 4, 256, 256),
  1, &conv2d_386_bias_array, NULL)

/* Tensor #179 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_386_output, AI_STATIC,
  179, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 10, 10), AI_STRIDE_INIT(4, 1, 1, 64, 640),
  1, &conv2d_386_output_array, &conv2d_386_output_array_intq)

/* Tensor #180 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_386_scratch0, AI_STATIC,
  180, 0x0,
  AI_SHAPE_INIT(4, 1, 7680, 1, 1), AI_STRIDE_INIT(4, 1, 1, 7680, 7680),
  1, &conv2d_386_scratch0_array, NULL)

/* Tensor #181 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_386_weights, AI_STATIC,
  181, 0x1,
  AI_SHAPE_INIT(4, 64, 3, 3, 64), AI_STRIDE_INIT(4, 1, 64, 4096, 12288),
  1, &conv2d_386_weights_array, &conv2d_386_weights_array_intq)

/* Tensor #182 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_393_bias, AI_STATIC,
  182, 0x0,
  AI_SHAPE_INIT(4, 1, 3, 1, 1), AI_STRIDE_INIT(4, 4, 4, 12, 12),
  1, &conv2d_393_bias_array, NULL)

/* Tensor #183 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_393_output, AI_STATIC,
  183, 0x1,
  AI_SHAPE_INIT(4, 1, 3, 10, 10), AI_STRIDE_INIT(4, 1, 1, 3, 30),
  1, &conv2d_393_output_array, &conv2d_393_output_array_intq)

/* Tensor #184 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_393_scratch0, AI_STATIC,
  184, 0x0,
  AI_SHAPE_INIT(4, 1, 256, 1, 1), AI_STRIDE_INIT(4, 1, 1, 256, 256),
  1, &conv2d_393_scratch0_array, NULL)

/* Tensor #185 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_393_weights, AI_STATIC,
  185, 0x1,
  AI_SHAPE_INIT(4, 64, 1, 1, 3), AI_STRIDE_INIT(4, 1, 64, 192, 192),
  1, &conv2d_393_weights_array, &conv2d_393_weights_array_intq)

/* Tensor #186 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_397_bias, AI_STATIC,
  186, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 1, 1), AI_STRIDE_INIT(4, 4, 4, 256, 256),
  1, &conv2d_397_bias_array, NULL)

/* Tensor #187 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_397_output, AI_STATIC,
  187, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 20, 20), AI_STRIDE_INIT(4, 1, 1, 64, 1280),
  1, &conv2d_397_output_array, &conv2d_397_output_array_intq)

/* Tensor #188 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_397_scratch0, AI_STATIC,
  188, 0x0,
  AI_SHAPE_INIT(4, 1, 9984, 1, 1), AI_STRIDE_INIT(4, 1, 1, 9984, 9984),
  1, &conv2d_397_scratch0_array, NULL)

/* Tensor #189 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_397_weights, AI_STATIC,
  189, 0x1,
  AI_SHAPE_INIT(4, 128, 3, 3, 64), AI_STRIDE_INIT(4, 1, 128, 8192, 24576),
  1, &conv2d_397_weights_array, &conv2d_397_weights_array_intq)

/* Tensor #190 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_404_bias, AI_STATIC,
  190, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 1, 1), AI_STRIDE_INIT(4, 4, 4, 256, 256),
  1, &conv2d_404_bias_array, NULL)

/* Tensor #191 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_404_output, AI_STATIC,
  191, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 20, 20), AI_STRIDE_INIT(4, 1, 1, 64, 1280),
  1, &conv2d_404_output_array, &conv2d_404_output_array_intq)

/* Tensor #192 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_404_scratch0, AI_STATIC,
  192, 0x0,
  AI_SHAPE_INIT(4, 1, 7680, 1, 1), AI_STRIDE_INIT(4, 1, 1, 7680, 7680),
  1, &conv2d_404_scratch0_array, NULL)

/* Tensor #193 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_404_weights, AI_STATIC,
  193, 0x1,
  AI_SHAPE_INIT(4, 64, 3, 3, 64), AI_STRIDE_INIT(4, 1, 64, 4096, 12288),
  1, &conv2d_404_weights_array, &conv2d_404_weights_array_intq)

/* Tensor #194 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_411_bias, AI_STATIC,
  194, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 1, 1), AI_STRIDE_INIT(4, 4, 4, 256, 256),
  1, &conv2d_411_bias_array, NULL)

/* Tensor #195 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_411_output, AI_STATIC,
  195, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 20, 20), AI_STRIDE_INIT(4, 1, 1, 64, 1280),
  1, &conv2d_411_output_array, &conv2d_411_output_array_intq)

/* Tensor #196 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_411_scratch0, AI_STATIC,
  196, 0x0,
  AI_SHAPE_INIT(4, 1, 256, 1, 1), AI_STRIDE_INIT(4, 1, 1, 256, 256),
  1, &conv2d_411_scratch0_array, NULL)

/* Tensor #197 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_411_weights, AI_STATIC,
  197, 0x1,
  AI_SHAPE_INIT(4, 64, 1, 1, 64), AI_STRIDE_INIT(4, 1, 64, 4096, 4096),
  1, &conv2d_411_weights_array, &conv2d_411_weights_array_intq)

/* Tensor #198 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_412_bias, AI_STATIC,
  198, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 1, 1), AI_STRIDE_INIT(4, 4, 4, 256, 256),
  1, &conv2d_412_bias_array, NULL)

/* Tensor #199 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_412_output, AI_STATIC,
  199, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 20, 20), AI_STRIDE_INIT(4, 1, 1, 64, 1280),
  1, &conv2d_412_output_array, &conv2d_412_output_array_intq)

/* Tensor #200 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_412_scratch0, AI_STATIC,
  200, 0x0,
  AI_SHAPE_INIT(4, 1, 9984, 1, 1), AI_STRIDE_INIT(4, 1, 1, 9984, 9984),
  1, &conv2d_412_scratch0_array, NULL)

/* Tensor #201 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_412_weights, AI_STATIC,
  201, 0x1,
  AI_SHAPE_INIT(4, 128, 3, 3, 64), AI_STRIDE_INIT(4, 1, 128, 8192, 24576),
  1, &conv2d_412_weights_array, &conv2d_412_weights_array_intq)

/* Tensor #202 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_419_bias, AI_STATIC,
  202, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 1, 1), AI_STRIDE_INIT(4, 4, 4, 256, 256),
  1, &conv2d_419_bias_array, NULL)

/* Tensor #203 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_419_output, AI_STATIC,
  203, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 20, 20), AI_STRIDE_INIT(4, 1, 1, 64, 1280),
  1, &conv2d_419_output_array, &conv2d_419_output_array_intq)

/* Tensor #204 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_419_scratch0, AI_STATIC,
  204, 0x0,
  AI_SHAPE_INIT(4, 1, 7680, 1, 1), AI_STRIDE_INIT(4, 1, 1, 7680, 7680),
  1, &conv2d_419_scratch0_array, NULL)

/* Tensor #205 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_419_weights, AI_STATIC,
  205, 0x1,
  AI_SHAPE_INIT(4, 64, 3, 3, 64), AI_STRIDE_INIT(4, 1, 64, 4096, 12288),
  1, &conv2d_419_weights_array, &conv2d_419_weights_array_intq)

/* Tensor #206 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_41_bias, AI_STATIC,
  206, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &conv2d_41_bias_array, NULL)

/* Tensor #207 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_41_output, AI_STATIC,
  207, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 80, 80), AI_STRIDE_INIT(4, 1, 1, 32, 2560),
  1, &conv2d_41_output_array, &conv2d_41_output_array_intq)

/* Tensor #208 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_41_scratch0, AI_STATIC,
  208, 0x0,
  AI_SHAPE_INIT(4, 1, 192, 1, 1), AI_STRIDE_INIT(4, 1, 1, 192, 192),
  1, &conv2d_41_scratch0_array, NULL)

/* Tensor #209 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_41_weights, AI_STATIC,
  209, 0x1,
  AI_SHAPE_INIT(4, 48, 1, 1, 32), AI_STRIDE_INIT(4, 1, 48, 1536, 1536),
  1, &conv2d_41_weights_array, &conv2d_41_weights_array_intq)

/* Tensor #210 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_426_bias, AI_STATIC,
  210, 0x0,
  AI_SHAPE_INIT(4, 1, 3, 1, 1), AI_STRIDE_INIT(4, 4, 4, 12, 12),
  1, &conv2d_426_bias_array, NULL)

/* Tensor #211 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_426_output, AI_STATIC,
  211, 0x1,
  AI_SHAPE_INIT(4, 1, 3, 20, 20), AI_STRIDE_INIT(4, 1, 1, 3, 60),
  1, &conv2d_426_output_array, &conv2d_426_output_array_intq)

/* Tensor #212 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_426_scratch0, AI_STATIC,
  212, 0x0,
  AI_SHAPE_INIT(4, 1, 256, 1, 1), AI_STRIDE_INIT(4, 1, 1, 256, 256),
  1, &conv2d_426_scratch0_array, NULL)

/* Tensor #213 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_426_weights, AI_STATIC,
  213, 0x1,
  AI_SHAPE_INIT(4, 64, 1, 1, 3), AI_STRIDE_INIT(4, 1, 64, 192, 192),
  1, &conv2d_426_weights_array, &conv2d_426_weights_array_intq)

/* Tensor #214 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_430_bias, AI_STATIC,
  214, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 1, 1), AI_STRIDE_INIT(4, 4, 4, 256, 256),
  1, &conv2d_430_bias_array, NULL)

/* Tensor #215 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_430_output, AI_STATIC,
  215, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 40, 40), AI_STRIDE_INIT(4, 1, 1, 64, 2560),
  1, &conv2d_430_output_array, &conv2d_430_output_array_intq)

/* Tensor #216 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_430_scratch0, AI_STATIC,
  216, 0x0,
  AI_SHAPE_INIT(4, 1, 7680, 1, 1), AI_STRIDE_INIT(4, 1, 1, 7680, 7680),
  1, &conv2d_430_scratch0_array, NULL)

/* Tensor #217 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_430_weights, AI_STATIC,
  217, 0x1,
  AI_SHAPE_INIT(4, 64, 3, 3, 64), AI_STRIDE_INIT(4, 1, 64, 4096, 12288),
  1, &conv2d_430_weights_array, &conv2d_430_weights_array_intq)

/* Tensor #218 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_437_bias, AI_STATIC,
  218, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 1, 1), AI_STRIDE_INIT(4, 4, 4, 256, 256),
  1, &conv2d_437_bias_array, NULL)

/* Tensor #219 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_437_output, AI_STATIC,
  219, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 40, 40), AI_STRIDE_INIT(4, 1, 1, 64, 2560),
  1, &conv2d_437_output_array, &conv2d_437_output_array_intq)

/* Tensor #220 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_437_scratch0, AI_STATIC,
  220, 0x0,
  AI_SHAPE_INIT(4, 1, 7680, 1, 1), AI_STRIDE_INIT(4, 1, 1, 7680, 7680),
  1, &conv2d_437_scratch0_array, NULL)

/* Tensor #221 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_437_weights, AI_STATIC,
  221, 0x1,
  AI_SHAPE_INIT(4, 64, 3, 3, 64), AI_STRIDE_INIT(4, 1, 64, 4096, 12288),
  1, &conv2d_437_weights_array, &conv2d_437_weights_array_intq)

/* Tensor #222 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_444_bias, AI_STATIC,
  222, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 1, 1), AI_STRIDE_INIT(4, 4, 4, 256, 256),
  1, &conv2d_444_bias_array, NULL)

/* Tensor #223 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_444_output, AI_STATIC,
  223, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 40, 40), AI_STRIDE_INIT(4, 1, 1, 64, 2560),
  1, &conv2d_444_output_array, &conv2d_444_output_array_intq)

/* Tensor #224 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_444_scratch0, AI_STATIC,
  224, 0x0,
  AI_SHAPE_INIT(4, 1, 256, 1, 1), AI_STRIDE_INIT(4, 1, 1, 256, 256),
  1, &conv2d_444_scratch0_array, NULL)

/* Tensor #225 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_444_weights, AI_STATIC,
  225, 0x1,
  AI_SHAPE_INIT(4, 64, 1, 1, 64), AI_STRIDE_INIT(4, 1, 64, 4096, 4096),
  1, &conv2d_444_weights_array, &conv2d_444_weights_array_intq)

/* Tensor #226 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_445_bias, AI_STATIC,
  226, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 1, 1), AI_STRIDE_INIT(4, 4, 4, 256, 256),
  1, &conv2d_445_bias_array, NULL)

/* Tensor #227 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_445_output, AI_STATIC,
  227, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 40, 40), AI_STRIDE_INIT(4, 1, 1, 64, 2560),
  1, &conv2d_445_output_array, &conv2d_445_output_array_intq)

/* Tensor #228 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_445_scratch0, AI_STATIC,
  228, 0x0,
  AI_SHAPE_INIT(4, 1, 7680, 1, 1), AI_STRIDE_INIT(4, 1, 1, 7680, 7680),
  1, &conv2d_445_scratch0_array, NULL)

/* Tensor #229 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_445_weights, AI_STATIC,
  229, 0x1,
  AI_SHAPE_INIT(4, 64, 3, 3, 64), AI_STRIDE_INIT(4, 1, 64, 4096, 12288),
  1, &conv2d_445_weights_array, &conv2d_445_weights_array_intq)

/* Tensor #230 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_452_bias, AI_STATIC,
  230, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 1, 1), AI_STRIDE_INIT(4, 4, 4, 256, 256),
  1, &conv2d_452_bias_array, NULL)

/* Tensor #231 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_452_output, AI_STATIC,
  231, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 40, 40), AI_STRIDE_INIT(4, 1, 1, 64, 2560),
  1, &conv2d_452_output_array, &conv2d_452_output_array_intq)

/* Tensor #232 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_452_scratch0, AI_STATIC,
  232, 0x0,
  AI_SHAPE_INIT(4, 1, 7680, 1, 1), AI_STRIDE_INIT(4, 1, 1, 7680, 7680),
  1, &conv2d_452_scratch0_array, NULL)

/* Tensor #233 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_452_weights, AI_STATIC,
  233, 0x1,
  AI_SHAPE_INIT(4, 64, 3, 3, 64), AI_STRIDE_INIT(4, 1, 64, 4096, 12288),
  1, &conv2d_452_weights_array, &conv2d_452_weights_array_intq)

/* Tensor #234 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_459_bias, AI_STATIC,
  234, 0x0,
  AI_SHAPE_INIT(4, 1, 3, 1, 1), AI_STRIDE_INIT(4, 4, 4, 12, 12),
  1, &conv2d_459_bias_array, NULL)

/* Tensor #235 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_459_output, AI_STATIC,
  235, 0x1,
  AI_SHAPE_INIT(4, 1, 3, 40, 40), AI_STRIDE_INIT(4, 1, 1, 3, 120),
  1, &conv2d_459_output_array, &conv2d_459_output_array_intq)

/* Tensor #236 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_459_scratch0, AI_STATIC,
  236, 0x0,
  AI_SHAPE_INIT(4, 1, 256, 1, 1), AI_STRIDE_INIT(4, 1, 1, 256, 256),
  1, &conv2d_459_scratch0_array, NULL)

/* Tensor #237 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_459_weights, AI_STATIC,
  237, 0x1,
  AI_SHAPE_INIT(4, 64, 1, 1, 3), AI_STRIDE_INIT(4, 1, 64, 192, 192),
  1, &conv2d_459_weights_array, &conv2d_459_weights_array_intq)

/* Tensor #238 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_468_bias, AI_STATIC,
  238, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 1, 1), AI_STRIDE_INIT(4, 4, 4, 4, 4),
  1, &conv2d_468_bias_array, NULL)

/* Tensor #239 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_468_output, AI_STATIC,
  239, 0x1,
  AI_SHAPE_INIT(4, 1, 1, 2100, 4), AI_STRIDE_INIT(4, 1, 1, 1, 2100),
  1, &conv2d_468_output_array, &conv2d_468_output_array_intq)

/* Tensor #240 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_468_output0, AI_STATIC,
  240, 0x1,
  AI_SHAPE_INIT(4, 1, 2100, 4, 1), AI_STRIDE_INIT(4, 1, 1, 2100, 8400),
  1, &conv2d_468_output_array, &conv2d_468_output_array_intq)

/* Tensor #241 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_468_scratch0, AI_STATIC,
  241, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 1, 1), AI_STRIDE_INIT(4, 1, 1, 64, 64),
  1, &conv2d_468_scratch0_array, NULL)

/* Tensor #242 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_468_weights, AI_STATIC,
  242, 0x1,
  AI_SHAPE_INIT(4, 16, 1, 1, 1), AI_STRIDE_INIT(4, 1, 16, 16, 16),
  1, &conv2d_468_weights_array, &conv2d_468_weights_array_intq)

/* Tensor #243 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_49_bias, AI_STATIC,
  243, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 1, 1), AI_STRIDE_INIT(4, 4, 4, 256, 256),
  1, &conv2d_49_bias_array, NULL)

/* Tensor #244 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_49_output, AI_STATIC,
  244, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 40, 40), AI_STRIDE_INIT(4, 1, 1, 64, 2560),
  1, &conv2d_49_output_array, &conv2d_49_output_array_intq)

/* Tensor #245 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_49_scratch0, AI_STATIC,
  245, 0x0,
  AI_SHAPE_INIT(4, 1, 6528, 1, 1), AI_STRIDE_INIT(4, 1, 1, 6528, 6528),
  1, &conv2d_49_scratch0_array, NULL)

/* Tensor #246 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_49_weights, AI_STATIC,
  246, 0x1,
  AI_SHAPE_INIT(4, 32, 3, 3, 64), AI_STRIDE_INIT(4, 1, 32, 2048, 6144),
  1, &conv2d_49_weights_array, &conv2d_49_weights_array_intq)

/* Tensor #247 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_56_bias, AI_STATIC,
  247, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 1, 1), AI_STRIDE_INIT(4, 4, 4, 256, 256),
  1, &conv2d_56_bias_array, NULL)

/* Tensor #248 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_56_output, AI_STATIC,
  248, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 40, 40), AI_STRIDE_INIT(4, 1, 1, 64, 2560),
  1, &conv2d_56_output_array, &conv2d_56_output_array_intq)

/* Tensor #249 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_56_scratch0, AI_STATIC,
  249, 0x0,
  AI_SHAPE_INIT(4, 1, 256, 1, 1), AI_STRIDE_INIT(4, 1, 1, 256, 256),
  1, &conv2d_56_scratch0_array, NULL)

/* Tensor #250 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_56_weights, AI_STATIC,
  250, 0x1,
  AI_SHAPE_INIT(4, 64, 1, 1, 64), AI_STRIDE_INIT(4, 1, 64, 4096, 4096),
  1, &conv2d_56_weights_array, &conv2d_56_weights_array_intq)

/* Tensor #251 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_65_bias, AI_STATIC,
  251, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &conv2d_65_bias_array, NULL)

/* Tensor #252 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_65_output, AI_STATIC,
  252, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 40, 40), AI_STRIDE_INIT(4, 1, 1, 32, 1280),
  1, &conv2d_65_output_array, &conv2d_65_output_array_intq)

/* Tensor #253 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_65_scratch0, AI_STATIC,
  253, 0x0,
  AI_SHAPE_INIT(4, 1, 6400, 1, 1), AI_STRIDE_INIT(4, 1, 1, 6400, 6400),
  1, &conv2d_65_scratch0_array, NULL)

/* Tensor #254 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_65_weights, AI_STATIC,
  254, 0x1,
  AI_SHAPE_INIT(4, 32, 3, 3, 32), AI_STRIDE_INIT(4, 1, 32, 1024, 3072),
  1, &conv2d_65_weights_array, &conv2d_65_weights_array_intq)

/* Tensor #255 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_72_bias, AI_STATIC,
  255, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &conv2d_72_bias_array, NULL)

/* Tensor #256 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_72_output, AI_STATIC,
  256, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 40, 40), AI_STRIDE_INIT(4, 1, 1, 32, 1280),
  1, &conv2d_72_output_array, &conv2d_72_output_array_intq)

/* Tensor #257 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_72_scratch0, AI_STATIC,
  257, 0x0,
  AI_SHAPE_INIT(4, 1, 6400, 1, 1), AI_STRIDE_INIT(4, 1, 1, 6400, 6400),
  1, &conv2d_72_scratch0_array, NULL)

/* Tensor #258 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_72_weights, AI_STATIC,
  258, 0x1,
  AI_SHAPE_INIT(4, 32, 3, 3, 32), AI_STRIDE_INIT(4, 1, 32, 1024, 3072),
  1, &conv2d_72_weights_array, &conv2d_72_weights_array_intq)

/* Tensor #259 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_80_bias, AI_STATIC,
  259, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &conv2d_80_bias_array, NULL)

/* Tensor #260 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_80_output, AI_STATIC,
  260, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 40, 40), AI_STRIDE_INIT(4, 1, 1, 32, 1280),
  1, &conv2d_80_output_array, &conv2d_80_output_array_intq)

/* Tensor #261 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_80_scratch0, AI_STATIC,
  261, 0x0,
  AI_SHAPE_INIT(4, 1, 6400, 1, 1), AI_STRIDE_INIT(4, 1, 1, 6400, 6400),
  1, &conv2d_80_scratch0_array, NULL)

/* Tensor #262 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_80_weights, AI_STATIC,
  262, 0x1,
  AI_SHAPE_INIT(4, 32, 3, 3, 32), AI_STRIDE_INIT(4, 1, 32, 1024, 3072),
  1, &conv2d_80_weights_array, &conv2d_80_weights_array_intq)

/* Tensor #263 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_87_bias, AI_STATIC,
  263, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &conv2d_87_bias_array, NULL)

/* Tensor #264 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_87_output, AI_STATIC,
  264, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 40, 40), AI_STRIDE_INIT(4, 1, 1, 32, 1280),
  1, &conv2d_87_output_array, &conv2d_87_output_array_intq)

/* Tensor #265 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_87_scratch0, AI_STATIC,
  265, 0x0,
  AI_SHAPE_INIT(4, 1, 6400, 1, 1), AI_STRIDE_INIT(4, 1, 1, 6400, 6400),
  1, &conv2d_87_scratch0_array, NULL)

/* Tensor #266 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_87_weights, AI_STATIC,
  266, 0x1,
  AI_SHAPE_INIT(4, 32, 3, 3, 32), AI_STRIDE_INIT(4, 1, 32, 1024, 3072),
  1, &conv2d_87_weights_array, &conv2d_87_weights_array_intq)

/* Tensor #267 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_96_bias, AI_STATIC,
  267, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 1, 1), AI_STRIDE_INIT(4, 4, 4, 256, 256),
  1, &conv2d_96_bias_array, NULL)

/* Tensor #268 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_96_output, AI_STATIC,
  268, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 40, 40), AI_STRIDE_INIT(4, 1, 1, 64, 2560),
  1, &conv2d_96_output_array, &conv2d_96_output_array_intq)

/* Tensor #269 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_96_scratch0, AI_STATIC,
  269, 0x0,
  AI_SHAPE_INIT(4, 1, 512, 1, 1), AI_STRIDE_INIT(4, 1, 1, 512, 512),
  1, &conv2d_96_scratch0_array, NULL)

/* Tensor #270 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_96_weights, AI_STATIC,
  270, 0x1,
  AI_SHAPE_INIT(4, 128, 1, 1, 64), AI_STRIDE_INIT(4, 1, 128, 8192, 8192),
  1, &conv2d_96_weights_array, &conv2d_96_weights_array_intq)

/* Tensor #271 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_9_bias, AI_STATIC,
  271, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &conv2d_9_bias_array, NULL)

/* Tensor #272 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_9_output, AI_STATIC,
  272, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 80, 80), AI_STRIDE_INIT(4, 1, 1, 32, 2560),
  1, &conv2d_9_output_array, &conv2d_9_output_array_intq)

/* Tensor #273 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_9_scratch0, AI_STATIC,
  273, 0x0,
  AI_SHAPE_INIT(4, 1, 5824, 1, 1), AI_STRIDE_INIT(4, 1, 1, 5824, 5824),
  1, &conv2d_9_scratch0_array, NULL)

/* Tensor #274 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_9_weights, AI_STATIC,
  274, 0x1,
  AI_SHAPE_INIT(4, 16, 3, 3, 32), AI_STRIDE_INIT(4, 1, 16, 512, 1536),
  1, &conv2d_9_weights_array, &conv2d_9_weights_array_intq)

/* Tensor #275 */
AI_TENSOR_OBJ_DECLARE(
  conversion_216_output, AI_STATIC,
  275, 0x1,
  AI_SHAPE_INIT(4, 1, 256, 10, 10), AI_STRIDE_INIT(4, 1, 1, 256, 2560),
  1, &conversion_216_output_array, &conversion_216_output_array_intq)

/* Tensor #276 */
AI_TENSOR_OBJ_DECLARE(
  conversion_250_output, AI_STATIC,
  276, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 20, 20), AI_STRIDE_INIT(4, 1, 1, 128, 2560),
  1, &conversion_250_output_array, &conversion_250_output_array_intq)

/* Tensor #277 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_100_output, AI_STATIC,
  277, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 40, 40), AI_STRIDE_INIT(4, 1, 1, 64, 2560),
  1, &eltwise_100_output_array, &eltwise_100_output_array_intq)

/* Tensor #278 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_101_output, AI_STATIC,
  278, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 40, 40), AI_STRIDE_INIT(4, 1, 1, 64, 2560),
  1, &eltwise_101_output_array, &eltwise_101_output_array_intq)

/* Tensor #279 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_102_output, AI_STATIC,
  279, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 40, 40), AI_STRIDE_INIT(4, 1, 1, 64, 2560),
  1, &eltwise_102_output_array, &eltwise_102_output_array_intq)

/* Tensor #280 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_106_output, AI_STATIC,
  280, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 20, 20), AI_STRIDE_INIT(4, 1, 1, 128, 2560),
  1, &eltwise_106_output_array, &eltwise_106_output_array_intq)

/* Tensor #281 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_107_output, AI_STATIC,
  281, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 20, 20), AI_STRIDE_INIT(4, 1, 1, 128, 2560),
  1, &eltwise_107_output_array, &eltwise_107_output_array_intq)

/* Tensor #282 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_108_output, AI_STATIC,
  282, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 20, 20), AI_STRIDE_INIT(4, 1, 1, 128, 2560),
  1, &eltwise_108_output_array, &eltwise_108_output_array_intq)

/* Tensor #283 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_109_output, AI_STATIC,
  283, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 20, 20), AI_STRIDE_INIT(4, 1, 1, 128, 2560),
  1, &eltwise_109_output_array, &eltwise_109_output_array_intq)

/* Tensor #284 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_110_output, AI_STATIC,
  284, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 20, 20), AI_STRIDE_INIT(4, 1, 1, 128, 2560),
  1, &eltwise_110_output_array, &eltwise_110_output_array_intq)

/* Tensor #285 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_113_output, AI_STATIC,
  285, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 20, 20), AI_STRIDE_INIT(4, 1, 1, 128, 2560),
  1, &eltwise_113_output_array, &eltwise_113_output_array_intq)

/* Tensor #286 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_114_output, AI_STATIC,
  286, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 20, 20), AI_STRIDE_INIT(4, 1, 1, 128, 2560),
  1, &eltwise_114_output_array, &eltwise_114_output_array_intq)

/* Tensor #287 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_115_output, AI_STATIC,
  287, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 20, 20), AI_STRIDE_INIT(4, 1, 1, 128, 2560),
  1, &eltwise_115_output_array, &eltwise_115_output_array_intq)

/* Tensor #288 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_116_output, AI_STATIC,
  288, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 20, 20), AI_STRIDE_INIT(4, 1, 1, 128, 2560),
  1, &eltwise_116_output_array, &eltwise_116_output_array_intq)

/* Tensor #289 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_117_output, AI_STATIC,
  289, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 20, 20), AI_STRIDE_INIT(4, 1, 1, 128, 2560),
  1, &eltwise_117_output_array, &eltwise_117_output_array_intq)

/* Tensor #290 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_11_output, AI_STATIC,
  290, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 80, 80), AI_STRIDE_INIT(4, 1, 1, 32, 2560),
  1, &eltwise_11_output_array, &eltwise_11_output_array_intq)

/* Tensor #291 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_122_output, AI_STATIC,
  291, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 20, 20), AI_STRIDE_INIT(4, 1, 1, 64, 1280),
  1, &eltwise_122_output_array, &eltwise_122_output_array_intq)

/* Tensor #292 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_123_output, AI_STATIC,
  292, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 20, 20), AI_STRIDE_INIT(4, 1, 1, 64, 1280),
  1, &eltwise_123_output_array, &eltwise_123_output_array_intq)

/* Tensor #293 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_124_output, AI_STATIC,
  293, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 20, 20), AI_STRIDE_INIT(4, 1, 1, 64, 1280),
  1, &eltwise_124_output_array, &eltwise_124_output_array_intq)

/* Tensor #294 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_125_output, AI_STATIC,
  294, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 20, 20), AI_STRIDE_INIT(4, 1, 1, 64, 1280),
  1, &eltwise_125_output_array, &eltwise_125_output_array_intq)

/* Tensor #295 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_126_output, AI_STATIC,
  295, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 20, 20), AI_STRIDE_INIT(4, 1, 1, 64, 1280),
  1, &eltwise_126_output_array, &eltwise_126_output_array_intq)

/* Tensor #296 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_129_output, AI_STATIC,
  296, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 20, 20), AI_STRIDE_INIT(4, 1, 1, 64, 1280),
  1, &eltwise_129_output_array, &eltwise_129_output_array_intq)

/* Tensor #297 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_12_output, AI_STATIC,
  297, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 80, 80), AI_STRIDE_INIT(4, 1, 1, 32, 2560),
  1, &eltwise_12_output_array, &eltwise_12_output_array_intq)

/* Tensor #298 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_130_output, AI_STATIC,
  298, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 20, 20), AI_STRIDE_INIT(4, 1, 1, 64, 1280),
  1, &eltwise_130_output_array, &eltwise_130_output_array_intq)

/* Tensor #299 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_131_output, AI_STATIC,
  299, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 20, 20), AI_STRIDE_INIT(4, 1, 1, 64, 1280),
  1, &eltwise_131_output_array, &eltwise_131_output_array_intq)

/* Tensor #300 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_132_output, AI_STATIC,
  300, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 20, 20), AI_STRIDE_INIT(4, 1, 1, 64, 1280),
  1, &eltwise_132_output_array, &eltwise_132_output_array_intq)

/* Tensor #301 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_133_output, AI_STATIC,
  301, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 20, 20), AI_STRIDE_INIT(4, 1, 1, 64, 1280),
  1, &eltwise_133_output_array, &eltwise_133_output_array_intq)

/* Tensor #302 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_134_output, AI_STATIC,
  302, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 20, 20), AI_STRIDE_INIT(4, 1, 1, 64, 1280),
  1, &eltwise_134_output_array, &eltwise_134_output_array_intq)

/* Tensor #303 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_137_output, AI_STATIC,
  303, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 20, 20), AI_STRIDE_INIT(4, 1, 1, 64, 1280),
  1, &eltwise_137_output_array, &eltwise_137_output_array_intq)

/* Tensor #304 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_138_output, AI_STATIC,
  304, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 20, 20), AI_STRIDE_INIT(4, 1, 1, 64, 1280),
  1, &eltwise_138_output_array, &eltwise_138_output_array_intq)

/* Tensor #305 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_139_output, AI_STATIC,
  305, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 20, 20), AI_STRIDE_INIT(4, 1, 1, 64, 1280),
  1, &eltwise_139_output_array, &eltwise_139_output_array_intq)

/* Tensor #306 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_13_output, AI_STATIC,
  306, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 80, 80), AI_STRIDE_INIT(4, 1, 1, 32, 2560),
  1, &eltwise_13_output_array, &eltwise_13_output_array_intq)

/* Tensor #307 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_140_output, AI_STATIC,
  307, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 20, 20), AI_STRIDE_INIT(4, 1, 1, 64, 1280),
  1, &eltwise_140_output_array, &eltwise_140_output_array_intq)

/* Tensor #308 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_141_output, AI_STATIC,
  308, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 20, 20), AI_STRIDE_INIT(4, 1, 1, 64, 1280),
  1, &eltwise_141_output_array, &eltwise_141_output_array_intq)

/* Tensor #309 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_144_output, AI_STATIC,
  309, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 20, 20), AI_STRIDE_INIT(4, 1, 1, 64, 1280),
  1, &eltwise_144_output_array, &eltwise_144_output_array_intq)

/* Tensor #310 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_145_output, AI_STATIC,
  310, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 20, 20), AI_STRIDE_INIT(4, 1, 1, 64, 1280),
  1, &eltwise_145_output_array, &eltwise_145_output_array_intq)

/* Tensor #311 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_146_output, AI_STATIC,
  311, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 20, 20), AI_STRIDE_INIT(4, 1, 1, 64, 1280),
  1, &eltwise_146_output_array, &eltwise_146_output_array_intq)

/* Tensor #312 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_147_output, AI_STATIC,
  312, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 20, 20), AI_STRIDE_INIT(4, 1, 1, 64, 1280),
  1, &eltwise_147_output_array, &eltwise_147_output_array_intq)

/* Tensor #313 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_148_output, AI_STATIC,
  313, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 20, 20), AI_STRIDE_INIT(4, 1, 1, 64, 1280),
  1, &eltwise_148_output_array, &eltwise_148_output_array_intq)

/* Tensor #314 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_149_output, AI_STATIC,
  314, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 20, 20), AI_STRIDE_INIT(4, 1, 1, 64, 1280),
  1, &eltwise_149_output_array, &eltwise_149_output_array_intq)

/* Tensor #315 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_14_output, AI_STATIC,
  315, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 80, 80), AI_STRIDE_INIT(4, 1, 1, 32, 2560),
  1, &eltwise_14_output_array, &eltwise_14_output_array_intq)

/* Tensor #316 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_153_output, AI_STATIC,
  316, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 20, 20), AI_STRIDE_INIT(4, 1, 1, 128, 2560),
  1, &eltwise_153_output_array, &eltwise_153_output_array_intq)

/* Tensor #317 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_154_output, AI_STATIC,
  317, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 20, 20), AI_STRIDE_INIT(4, 1, 1, 128, 2560),
  1, &eltwise_154_output_array, &eltwise_154_output_array_intq)

/* Tensor #318 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_155_output, AI_STATIC,
  318, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 20, 20), AI_STRIDE_INIT(4, 1, 1, 128, 2560),
  1, &eltwise_155_output_array, &eltwise_155_output_array_intq)

/* Tensor #319 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_156_output, AI_STATIC,
  319, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 20, 20), AI_STRIDE_INIT(4, 1, 1, 128, 2560),
  1, &eltwise_156_output_array, &eltwise_156_output_array_intq)

/* Tensor #320 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_157_output, AI_STATIC,
  320, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 20, 20), AI_STRIDE_INIT(4, 1, 1, 128, 2560),
  1, &eltwise_157_output_array, &eltwise_157_output_array_intq)

/* Tensor #321 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_15_output, AI_STATIC,
  321, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 80, 80), AI_STRIDE_INIT(4, 1, 1, 32, 2560),
  1, &eltwise_15_output_array, &eltwise_15_output_array_intq)

/* Tensor #322 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_161_output, AI_STATIC,
  322, 0x1,
  AI_SHAPE_INIT(4, 1, 256, 10, 10), AI_STRIDE_INIT(4, 1, 1, 256, 2560),
  1, &eltwise_161_output_array, &eltwise_161_output_array_intq)

/* Tensor #323 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_162_output, AI_STATIC,
  323, 0x1,
  AI_SHAPE_INIT(4, 1, 256, 10, 10), AI_STRIDE_INIT(4, 1, 1, 256, 2560),
  1, &eltwise_162_output_array, &eltwise_162_output_array_intq)

/* Tensor #324 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_163_output, AI_STATIC,
  324, 0x1,
  AI_SHAPE_INIT(4, 1, 256, 10, 10), AI_STRIDE_INIT(4, 1, 1, 256, 2560),
  1, &eltwise_163_output_array, &eltwise_163_output_array_intq)

/* Tensor #325 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_164_output, AI_STATIC,
  325, 0x1,
  AI_SHAPE_INIT(4, 1, 256, 10, 10), AI_STRIDE_INIT(4, 1, 1, 256, 2560),
  1, &eltwise_164_output_array, &eltwise_164_output_array_intq)

/* Tensor #326 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_165_output, AI_STATIC,
  326, 0x1,
  AI_SHAPE_INIT(4, 1, 256, 10, 10), AI_STRIDE_INIT(4, 1, 1, 256, 2560),
  1, &eltwise_165_output_array, &eltwise_165_output_array_intq)

/* Tensor #327 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_168_output, AI_STATIC,
  327, 0x1,
  AI_SHAPE_INIT(4, 1, 256, 10, 10), AI_STRIDE_INIT(4, 1, 1, 256, 2560),
  1, &eltwise_168_output_array, &eltwise_168_output_array_intq)

/* Tensor #328 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_169_output, AI_STATIC,
  328, 0x1,
  AI_SHAPE_INIT(4, 1, 256, 10, 10), AI_STRIDE_INIT(4, 1, 1, 256, 2560),
  1, &eltwise_169_output_array, &eltwise_169_output_array_intq)

/* Tensor #329 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_170_output, AI_STATIC,
  329, 0x1,
  AI_SHAPE_INIT(4, 1, 256, 10, 10), AI_STRIDE_INIT(4, 1, 1, 256, 2560),
  1, &eltwise_170_output_array, &eltwise_170_output_array_intq)

/* Tensor #330 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_171_output, AI_STATIC,
  330, 0x1,
  AI_SHAPE_INIT(4, 1, 256, 10, 10), AI_STRIDE_INIT(4, 1, 1, 256, 2560),
  1, &eltwise_171_output_array, &eltwise_171_output_array_intq)

/* Tensor #331 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_172_output, AI_STATIC,
  331, 0x1,
  AI_SHAPE_INIT(4, 1, 256, 10, 10), AI_STRIDE_INIT(4, 1, 1, 256, 2560),
  1, &eltwise_172_output_array, &eltwise_172_output_array_intq)

/* Tensor #332 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_177_output, AI_STATIC,
  332, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 10, 10), AI_STRIDE_INIT(4, 1, 1, 128, 1280),
  1, &eltwise_177_output_array, &eltwise_177_output_array_intq)

/* Tensor #333 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_178_output, AI_STATIC,
  333, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 10, 10), AI_STRIDE_INIT(4, 1, 1, 128, 1280),
  1, &eltwise_178_output_array, &eltwise_178_output_array_intq)

/* Tensor #334 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_179_output, AI_STATIC,
  334, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 10, 10), AI_STRIDE_INIT(4, 1, 1, 128, 1280),
  1, &eltwise_179_output_array, &eltwise_179_output_array_intq)

/* Tensor #335 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_180_output, AI_STATIC,
  335, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 10, 10), AI_STRIDE_INIT(4, 1, 1, 128, 1280),
  1, &eltwise_180_output_array, &eltwise_180_output_array_intq)

/* Tensor #336 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_181_output, AI_STATIC,
  336, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 10, 10), AI_STRIDE_INIT(4, 1, 1, 128, 1280),
  1, &eltwise_181_output_array, &eltwise_181_output_array_intq)

/* Tensor #337 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_184_output, AI_STATIC,
  337, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 10, 10), AI_STRIDE_INIT(4, 1, 1, 128, 1280),
  1, &eltwise_184_output_array, &eltwise_184_output_array_intq)

/* Tensor #338 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_185_output, AI_STATIC,
  338, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 10, 10), AI_STRIDE_INIT(4, 1, 1, 128, 1280),
  1, &eltwise_185_output_array, &eltwise_185_output_array_intq)

/* Tensor #339 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_186_output, AI_STATIC,
  339, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 10, 10), AI_STRIDE_INIT(4, 1, 1, 128, 1280),
  1, &eltwise_186_output_array, &eltwise_186_output_array_intq)

/* Tensor #340 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_187_output, AI_STATIC,
  340, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 10, 10), AI_STRIDE_INIT(4, 1, 1, 128, 1280),
  1, &eltwise_187_output_array, &eltwise_187_output_array_intq)

/* Tensor #341 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_188_output, AI_STATIC,
  341, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 10, 10), AI_STRIDE_INIT(4, 1, 1, 128, 1280),
  1, &eltwise_188_output_array, &eltwise_188_output_array_intq)

/* Tensor #342 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_189_output, AI_STATIC,
  342, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 10, 10), AI_STRIDE_INIT(4, 1, 1, 128, 1280),
  1, &eltwise_189_output_array, &eltwise_189_output_array_intq)

/* Tensor #343 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_18_output, AI_STATIC,
  343, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 80, 80), AI_STRIDE_INIT(4, 1, 1, 32, 2560),
  1, &eltwise_18_output_array, &eltwise_18_output_array_intq)

/* Tensor #344 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_193_output, AI_STATIC,
  344, 0x1,
  AI_SHAPE_INIT(4, 1, 256, 10, 10), AI_STRIDE_INIT(4, 1, 1, 256, 2560),
  1, &eltwise_193_output_array, &eltwise_193_output_array_intq)

/* Tensor #345 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_194_output, AI_STATIC,
  345, 0x1,
  AI_SHAPE_INIT(4, 1, 256, 10, 10), AI_STRIDE_INIT(4, 1, 1, 256, 2560),
  1, &eltwise_194_output_array, &eltwise_194_output_array_intq)

/* Tensor #346 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_195_output, AI_STATIC,
  346, 0x1,
  AI_SHAPE_INIT(4, 1, 256, 10, 10), AI_STRIDE_INIT(4, 1, 1, 256, 2560),
  1, &eltwise_195_output_array, &eltwise_195_output_array_intq)

/* Tensor #347 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_196_output, AI_STATIC,
  347, 0x1,
  AI_SHAPE_INIT(4, 1, 256, 10, 10), AI_STRIDE_INIT(4, 1, 1, 256, 2560),
  1, &eltwise_196_output_array, &eltwise_196_output_array_intq)

/* Tensor #348 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_197_output, AI_STATIC,
  348, 0x1,
  AI_SHAPE_INIT(4, 1, 256, 10, 10), AI_STRIDE_INIT(4, 1, 1, 256, 2560),
  1, &eltwise_197_output_array, &eltwise_197_output_array_intq)

/* Tensor #349 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_19_output, AI_STATIC,
  349, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 80, 80), AI_STRIDE_INIT(4, 1, 1, 32, 2560),
  1, &eltwise_19_output_array, &eltwise_19_output_array_intq)

/* Tensor #350 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_200_output, AI_STATIC,
  350, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 10, 10), AI_STRIDE_INIT(4, 1, 1, 128, 1280),
  1, &eltwise_200_output_array, &eltwise_200_output_array_intq)

/* Tensor #351 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_201_output, AI_STATIC,
  351, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 10, 10), AI_STRIDE_INIT(4, 1, 1, 128, 1280),
  1, &eltwise_201_output_array, &eltwise_201_output_array_intq)

/* Tensor #352 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_202_output, AI_STATIC,
  352, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 10, 10), AI_STRIDE_INIT(4, 1, 1, 128, 1280),
  1, &eltwise_202_output_array, &eltwise_202_output_array_intq)

/* Tensor #353 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_203_output, AI_STATIC,
  353, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 10, 10), AI_STRIDE_INIT(4, 1, 1, 128, 1280),
  1, &eltwise_203_output_array, &eltwise_203_output_array_intq)

/* Tensor #354 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_204_output, AI_STATIC,
  354, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 10, 10), AI_STRIDE_INIT(4, 1, 1, 128, 1280),
  1, &eltwise_204_output_array, &eltwise_204_output_array_intq)

/* Tensor #355 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_20_output, AI_STATIC,
  355, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 80, 80), AI_STRIDE_INIT(4, 1, 1, 32, 2560),
  1, &eltwise_20_output_array, &eltwise_20_output_array_intq)

/* Tensor #356 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_211_output, AI_STATIC,
  356, 0x1,
  AI_SHAPE_INIT(4, 1, 256, 10, 10), AI_STRIDE_INIT(4, 1, 1, 256, 2560),
  1, &eltwise_211_output_array, &eltwise_211_output_array_intq)

/* Tensor #357 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_212_output, AI_STATIC,
  357, 0x1,
  AI_SHAPE_INIT(4, 1, 256, 10, 10), AI_STRIDE_INIT(4, 1, 1, 256, 2560),
  1, &eltwise_212_output_array, &eltwise_212_output_array_intq)

/* Tensor #358 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_213_output, AI_STATIC,
  358, 0x1,
  AI_SHAPE_INIT(4, 1, 256, 10, 10), AI_STRIDE_INIT(4, 1, 1, 256, 2560),
  1, &eltwise_213_output_array, &eltwise_213_output_array_intq)

/* Tensor #359 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_214_output, AI_STATIC,
  359, 0x1,
  AI_SHAPE_INIT(4, 1, 256, 10, 10), AI_STRIDE_INIT(4, 1, 1, 256, 2560),
  1, &eltwise_214_output_array, &eltwise_214_output_array_intq)

/* Tensor #360 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_215_output, AI_STATIC,
  360, 0x1,
  AI_SHAPE_INIT(4, 1, 256, 10, 10), AI_STRIDE_INIT(4, 1, 1, 256, 2560),
  1, &eltwise_215_output_array, &eltwise_215_output_array_intq)

/* Tensor #361 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_21_output, AI_STATIC,
  361, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 80, 80), AI_STRIDE_INIT(4, 1, 1, 32, 2560),
  1, &eltwise_21_output_array, &eltwise_21_output_array_intq)

/* Tensor #362 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_221_output, AI_STATIC,
  362, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 20, 20), AI_STRIDE_INIT(4, 1, 1, 128, 2560),
  1, &eltwise_221_output_array, &eltwise_221_output_array_intq)

/* Tensor #363 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_222_output, AI_STATIC,
  363, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 20, 20), AI_STRIDE_INIT(4, 1, 1, 128, 2560),
  1, &eltwise_222_output_array, &eltwise_222_output_array_intq)

/* Tensor #364 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_223_output, AI_STATIC,
  364, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 20, 20), AI_STRIDE_INIT(4, 1, 1, 128, 2560),
  1, &eltwise_223_output_array, &eltwise_223_output_array_intq)

/* Tensor #365 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_224_output, AI_STATIC,
  365, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 20, 20), AI_STRIDE_INIT(4, 1, 1, 128, 2560),
  1, &eltwise_224_output_array, &eltwise_224_output_array_intq)

/* Tensor #366 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_225_output, AI_STATIC,
  366, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 20, 20), AI_STRIDE_INIT(4, 1, 1, 128, 2560),
  1, &eltwise_225_output_array, &eltwise_225_output_array_intq)

/* Tensor #367 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_22_output, AI_STATIC,
  367, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 80, 80), AI_STRIDE_INIT(4, 1, 1, 32, 2560),
  1, &eltwise_22_output_array, &eltwise_22_output_array_intq)

/* Tensor #368 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_230_output, AI_STATIC,
  368, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 20, 20), AI_STRIDE_INIT(4, 1, 1, 64, 1280),
  1, &eltwise_230_output_array, &eltwise_230_output_array_intq)

/* Tensor #369 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_231_output, AI_STATIC,
  369, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 20, 20), AI_STRIDE_INIT(4, 1, 1, 64, 1280),
  1, &eltwise_231_output_array, &eltwise_231_output_array_intq)

/* Tensor #370 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_232_output, AI_STATIC,
  370, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 20, 20), AI_STRIDE_INIT(4, 1, 1, 64, 1280),
  1, &eltwise_232_output_array, &eltwise_232_output_array_intq)

/* Tensor #371 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_233_output, AI_STATIC,
  371, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 20, 20), AI_STRIDE_INIT(4, 1, 1, 64, 1280),
  1, &eltwise_233_output_array, &eltwise_233_output_array_intq)

/* Tensor #372 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_234_output, AI_STATIC,
  372, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 20, 20), AI_STRIDE_INIT(4, 1, 1, 64, 1280),
  1, &eltwise_234_output_array, &eltwise_234_output_array_intq)

/* Tensor #373 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_237_output, AI_STATIC,
  373, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 20, 20), AI_STRIDE_INIT(4, 1, 1, 64, 1280),
  1, &eltwise_237_output_array, &eltwise_237_output_array_intq)

/* Tensor #374 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_238_output, AI_STATIC,
  374, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 20, 20), AI_STRIDE_INIT(4, 1, 1, 64, 1280),
  1, &eltwise_238_output_array, &eltwise_238_output_array_intq)

/* Tensor #375 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_239_output, AI_STATIC,
  375, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 20, 20), AI_STRIDE_INIT(4, 1, 1, 64, 1280),
  1, &eltwise_239_output_array, &eltwise_239_output_array_intq)

/* Tensor #376 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_240_output, AI_STATIC,
  376, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 20, 20), AI_STRIDE_INIT(4, 1, 1, 64, 1280),
  1, &eltwise_240_output_array, &eltwise_240_output_array_intq)

/* Tensor #377 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_241_output, AI_STATIC,
  377, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 20, 20), AI_STRIDE_INIT(4, 1, 1, 64, 1280),
  1, &eltwise_241_output_array, &eltwise_241_output_array_intq)

/* Tensor #378 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_245_output, AI_STATIC,
  378, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 20, 20), AI_STRIDE_INIT(4, 1, 1, 128, 2560),
  1, &eltwise_245_output_array, &eltwise_245_output_array_intq)

/* Tensor #379 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_246_output, AI_STATIC,
  379, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 20, 20), AI_STRIDE_INIT(4, 1, 1, 128, 2560),
  1, &eltwise_246_output_array, &eltwise_246_output_array_intq)

/* Tensor #380 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_247_output, AI_STATIC,
  380, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 20, 20), AI_STRIDE_INIT(4, 1, 1, 128, 2560),
  1, &eltwise_247_output_array, &eltwise_247_output_array_intq)

/* Tensor #381 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_248_output, AI_STATIC,
  381, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 20, 20), AI_STRIDE_INIT(4, 1, 1, 128, 2560),
  1, &eltwise_248_output_array, &eltwise_248_output_array_intq)

/* Tensor #382 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_249_output, AI_STATIC,
  382, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 20, 20), AI_STRIDE_INIT(4, 1, 1, 128, 2560),
  1, &eltwise_249_output_array, &eltwise_249_output_array_intq)

/* Tensor #383 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_255_output, AI_STATIC,
  383, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 40, 40), AI_STRIDE_INIT(4, 1, 1, 64, 2560),
  1, &eltwise_255_output_array, &eltwise_255_output_array_intq)

/* Tensor #384 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_256_output, AI_STATIC,
  384, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 40, 40), AI_STRIDE_INIT(4, 1, 1, 64, 2560),
  1, &eltwise_256_output_array, &eltwise_256_output_array_intq)

/* Tensor #385 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_257_output, AI_STATIC,
  385, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 40, 40), AI_STRIDE_INIT(4, 1, 1, 64, 2560),
  1, &eltwise_257_output_array, &eltwise_257_output_array_intq)

/* Tensor #386 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_258_output, AI_STATIC,
  386, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 40, 40), AI_STRIDE_INIT(4, 1, 1, 64, 2560),
  1, &eltwise_258_output_array, &eltwise_258_output_array_intq)

/* Tensor #387 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_259_output, AI_STATIC,
  387, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 40, 40), AI_STRIDE_INIT(4, 1, 1, 64, 2560),
  1, &eltwise_259_output_array, &eltwise_259_output_array_intq)

/* Tensor #388 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_264_output, AI_STATIC,
  388, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 40, 40), AI_STRIDE_INIT(4, 1, 1, 32, 1280),
  1, &eltwise_264_output_array, &eltwise_264_output_array_intq)

/* Tensor #389 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_265_output, AI_STATIC,
  389, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 40, 40), AI_STRIDE_INIT(4, 1, 1, 32, 1280),
  1, &eltwise_265_output_array, &eltwise_265_output_array_intq)

/* Tensor #390 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_266_output, AI_STATIC,
  390, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 40, 40), AI_STRIDE_INIT(4, 1, 1, 32, 1280),
  1, &eltwise_266_output_array, &eltwise_266_output_array_intq)

/* Tensor #391 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_267_output, AI_STATIC,
  391, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 40, 40), AI_STRIDE_INIT(4, 1, 1, 32, 1280),
  1, &eltwise_267_output_array, &eltwise_267_output_array_intq)

/* Tensor #392 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_268_output, AI_STATIC,
  392, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 40, 40), AI_STRIDE_INIT(4, 1, 1, 32, 1280),
  1, &eltwise_268_output_array, &eltwise_268_output_array_intq)

/* Tensor #393 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_26_output, AI_STATIC,
  393, 0x1,
  AI_SHAPE_INIT(4, 1, 16, 80, 80), AI_STRIDE_INIT(4, 1, 1, 16, 1280),
  1, &eltwise_26_output_array, &eltwise_26_output_array_intq)

/* Tensor #394 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_271_output, AI_STATIC,
  394, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 40, 40), AI_STRIDE_INIT(4, 1, 1, 32, 1280),
  1, &eltwise_271_output_array, &eltwise_271_output_array_intq)

/* Tensor #395 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_272_output, AI_STATIC,
  395, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 40, 40), AI_STRIDE_INIT(4, 1, 1, 32, 1280),
  1, &eltwise_272_output_array, &eltwise_272_output_array_intq)

/* Tensor #396 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_273_output, AI_STATIC,
  396, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 40, 40), AI_STRIDE_INIT(4, 1, 1, 32, 1280),
  1, &eltwise_273_output_array, &eltwise_273_output_array_intq)

/* Tensor #397 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_274_output, AI_STATIC,
  397, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 40, 40), AI_STRIDE_INIT(4, 1, 1, 32, 1280),
  1, &eltwise_274_output_array, &eltwise_274_output_array_intq)

/* Tensor #398 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_275_output, AI_STATIC,
  398, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 40, 40), AI_STRIDE_INIT(4, 1, 1, 32, 1280),
  1, &eltwise_275_output_array, &eltwise_275_output_array_intq)

/* Tensor #399 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_279_output, AI_STATIC,
  399, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 40, 40), AI_STRIDE_INIT(4, 1, 1, 64, 2560),
  1, &eltwise_279_output_array, &eltwise_279_output_array_intq)

/* Tensor #400 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_27_output, AI_STATIC,
  400, 0x1,
  AI_SHAPE_INIT(4, 1, 16, 80, 80), AI_STRIDE_INIT(4, 1, 1, 16, 1280),
  1, &eltwise_27_output_array, &eltwise_27_output_array_intq)

/* Tensor #401 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_280_output, AI_STATIC,
  401, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 40, 40), AI_STRIDE_INIT(4, 1, 1, 64, 2560),
  1, &eltwise_280_output_array, &eltwise_280_output_array_intq)

/* Tensor #402 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_281_output, AI_STATIC,
  402, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 40, 40), AI_STRIDE_INIT(4, 1, 1, 64, 2560),
  1, &eltwise_281_output_array, &eltwise_281_output_array_intq)

/* Tensor #403 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_282_output, AI_STATIC,
  403, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 40, 40), AI_STRIDE_INIT(4, 1, 1, 64, 2560),
  1, &eltwise_282_output_array, &eltwise_282_output_array_intq)

/* Tensor #404 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_283_output, AI_STATIC,
  404, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 40, 40), AI_STRIDE_INIT(4, 1, 1, 64, 2560),
  1, &eltwise_283_output_array, &eltwise_283_output_array_intq)

/* Tensor #405 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_287_output, AI_STATIC,
  405, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 20, 20), AI_STRIDE_INIT(4, 1, 1, 64, 1280),
  1, &eltwise_287_output_array, &eltwise_287_output_array_intq)

/* Tensor #406 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_288_output, AI_STATIC,
  406, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 20, 20), AI_STRIDE_INIT(4, 1, 1, 64, 1280),
  1, &eltwise_288_output_array, &eltwise_288_output_array_intq)

/* Tensor #407 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_289_output, AI_STATIC,
  407, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 20, 20), AI_STRIDE_INIT(4, 1, 1, 64, 1280),
  1, &eltwise_289_output_array, &eltwise_289_output_array_intq)

/* Tensor #408 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_28_output, AI_STATIC,
  408, 0x1,
  AI_SHAPE_INIT(4, 1, 16, 80, 80), AI_STRIDE_INIT(4, 1, 1, 16, 1280),
  1, &eltwise_28_output_array, &eltwise_28_output_array_intq)

/* Tensor #409 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_290_output, AI_STATIC,
  409, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 20, 20), AI_STRIDE_INIT(4, 1, 1, 64, 1280),
  1, &eltwise_290_output_array, &eltwise_290_output_array_intq)

/* Tensor #410 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_291_output, AI_STATIC,
  410, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 20, 20), AI_STRIDE_INIT(4, 1, 1, 64, 1280),
  1, &eltwise_291_output_array, &eltwise_291_output_array_intq)

/* Tensor #411 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_295_output, AI_STATIC,
  411, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 20, 20), AI_STRIDE_INIT(4, 1, 1, 128, 2560),
  1, &eltwise_295_output_array, &eltwise_295_output_array_intq)

/* Tensor #412 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_296_output, AI_STATIC,
  412, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 20, 20), AI_STRIDE_INIT(4, 1, 1, 128, 2560),
  1, &eltwise_296_output_array, &eltwise_296_output_array_intq)

/* Tensor #413 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_297_output, AI_STATIC,
  413, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 20, 20), AI_STRIDE_INIT(4, 1, 1, 128, 2560),
  1, &eltwise_297_output_array, &eltwise_297_output_array_intq)

/* Tensor #414 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_298_output, AI_STATIC,
  414, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 20, 20), AI_STRIDE_INIT(4, 1, 1, 128, 2560),
  1, &eltwise_298_output_array, &eltwise_298_output_array_intq)

/* Tensor #415 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_299_output, AI_STATIC,
  415, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 20, 20), AI_STRIDE_INIT(4, 1, 1, 128, 2560),
  1, &eltwise_299_output_array, &eltwise_299_output_array_intq)

/* Tensor #416 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_29_output, AI_STATIC,
  416, 0x1,
  AI_SHAPE_INIT(4, 1, 16, 80, 80), AI_STRIDE_INIT(4, 1, 1, 16, 1280),
  1, &eltwise_29_output_array, &eltwise_29_output_array_intq)

/* Tensor #417 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_304_output, AI_STATIC,
  417, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 20, 20), AI_STRIDE_INIT(4, 1, 1, 64, 1280),
  1, &eltwise_304_output_array, &eltwise_304_output_array_intq)

/* Tensor #418 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_305_output, AI_STATIC,
  418, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 20, 20), AI_STRIDE_INIT(4, 1, 1, 64, 1280),
  1, &eltwise_305_output_array, &eltwise_305_output_array_intq)

/* Tensor #419 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_306_output, AI_STATIC,
  419, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 20, 20), AI_STRIDE_INIT(4, 1, 1, 64, 1280),
  1, &eltwise_306_output_array, &eltwise_306_output_array_intq)

/* Tensor #420 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_307_output, AI_STATIC,
  420, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 20, 20), AI_STRIDE_INIT(4, 1, 1, 64, 1280),
  1, &eltwise_307_output_array, &eltwise_307_output_array_intq)

/* Tensor #421 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_308_output, AI_STATIC,
  421, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 20, 20), AI_STRIDE_INIT(4, 1, 1, 64, 1280),
  1, &eltwise_308_output_array, &eltwise_308_output_array_intq)

/* Tensor #422 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_30_output, AI_STATIC,
  422, 0x1,
  AI_SHAPE_INIT(4, 1, 16, 80, 80), AI_STRIDE_INIT(4, 1, 1, 16, 1280),
  1, &eltwise_30_output_array, &eltwise_30_output_array_intq)

/* Tensor #423 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_311_output, AI_STATIC,
  423, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 20, 20), AI_STRIDE_INIT(4, 1, 1, 64, 1280),
  1, &eltwise_311_output_array, &eltwise_311_output_array_intq)

/* Tensor #424 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_312_output, AI_STATIC,
  424, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 20, 20), AI_STRIDE_INIT(4, 1, 1, 64, 1280),
  1, &eltwise_312_output_array, &eltwise_312_output_array_intq)

/* Tensor #425 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_313_output, AI_STATIC,
  425, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 20, 20), AI_STRIDE_INIT(4, 1, 1, 64, 1280),
  1, &eltwise_313_output_array, &eltwise_313_output_array_intq)

/* Tensor #426 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_314_output, AI_STATIC,
  426, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 20, 20), AI_STRIDE_INIT(4, 1, 1, 64, 1280),
  1, &eltwise_314_output_array, &eltwise_314_output_array_intq)

/* Tensor #427 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_315_output, AI_STATIC,
  427, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 20, 20), AI_STRIDE_INIT(4, 1, 1, 64, 1280),
  1, &eltwise_315_output_array, &eltwise_315_output_array_intq)

/* Tensor #428 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_319_output, AI_STATIC,
  428, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 20, 20), AI_STRIDE_INIT(4, 1, 1, 128, 2560),
  1, &eltwise_319_output_array, &eltwise_319_output_array_intq)

/* Tensor #429 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_320_output, AI_STATIC,
  429, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 20, 20), AI_STRIDE_INIT(4, 1, 1, 128, 2560),
  1, &eltwise_320_output_array, &eltwise_320_output_array_intq)

/* Tensor #430 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_321_output, AI_STATIC,
  430, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 20, 20), AI_STRIDE_INIT(4, 1, 1, 128, 2560),
  1, &eltwise_321_output_array, &eltwise_321_output_array_intq)

/* Tensor #431 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_322_output, AI_STATIC,
  431, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 20, 20), AI_STRIDE_INIT(4, 1, 1, 128, 2560),
  1, &eltwise_322_output_array, &eltwise_322_output_array_intq)

/* Tensor #432 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_323_output, AI_STATIC,
  432, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 20, 20), AI_STRIDE_INIT(4, 1, 1, 128, 2560),
  1, &eltwise_323_output_array, &eltwise_323_output_array_intq)

/* Tensor #433 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_327_output, AI_STATIC,
  433, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 10, 10), AI_STRIDE_INIT(4, 1, 1, 128, 1280),
  1, &eltwise_327_output_array, &eltwise_327_output_array_intq)

/* Tensor #434 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_328_output, AI_STATIC,
  434, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 10, 10), AI_STRIDE_INIT(4, 1, 1, 128, 1280),
  1, &eltwise_328_output_array, &eltwise_328_output_array_intq)

/* Tensor #435 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_329_output, AI_STATIC,
  435, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 10, 10), AI_STRIDE_INIT(4, 1, 1, 128, 1280),
  1, &eltwise_329_output_array, &eltwise_329_output_array_intq)

/* Tensor #436 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_330_output, AI_STATIC,
  436, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 10, 10), AI_STRIDE_INIT(4, 1, 1, 128, 1280),
  1, &eltwise_330_output_array, &eltwise_330_output_array_intq)

/* Tensor #437 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_331_output, AI_STATIC,
  437, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 10, 10), AI_STRIDE_INIT(4, 1, 1, 128, 1280),
  1, &eltwise_331_output_array, &eltwise_331_output_array_intq)

/* Tensor #438 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_335_output, AI_STATIC,
  438, 0x1,
  AI_SHAPE_INIT(4, 1, 256, 10, 10), AI_STRIDE_INIT(4, 1, 1, 256, 2560),
  1, &eltwise_335_output_array, &eltwise_335_output_array_intq)

/* Tensor #439 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_336_output, AI_STATIC,
  439, 0x1,
  AI_SHAPE_INIT(4, 1, 256, 10, 10), AI_STRIDE_INIT(4, 1, 1, 256, 2560),
  1, &eltwise_336_output_array, &eltwise_336_output_array_intq)

/* Tensor #440 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_337_output, AI_STATIC,
  440, 0x1,
  AI_SHAPE_INIT(4, 1, 256, 10, 10), AI_STRIDE_INIT(4, 1, 1, 256, 2560),
  1, &eltwise_337_output_array, &eltwise_337_output_array_intq)

/* Tensor #441 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_338_output, AI_STATIC,
  441, 0x1,
  AI_SHAPE_INIT(4, 1, 256, 10, 10), AI_STRIDE_INIT(4, 1, 1, 256, 2560),
  1, &eltwise_338_output_array, &eltwise_338_output_array_intq)

/* Tensor #442 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_339_output, AI_STATIC,
  442, 0x1,
  AI_SHAPE_INIT(4, 1, 256, 10, 10), AI_STRIDE_INIT(4, 1, 1, 256, 2560),
  1, &eltwise_339_output_array, &eltwise_339_output_array_intq)

/* Tensor #443 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_33_output, AI_STATIC,
  443, 0x1,
  AI_SHAPE_INIT(4, 1, 16, 80, 80), AI_STRIDE_INIT(4, 1, 1, 16, 1280),
  1, &eltwise_33_output_array, &eltwise_33_output_array_intq)

/* Tensor #444 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_344_output, AI_STATIC,
  444, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 10, 10), AI_STRIDE_INIT(4, 1, 1, 128, 1280),
  1, &eltwise_344_output_array, &eltwise_344_output_array_intq)

/* Tensor #445 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_345_output, AI_STATIC,
  445, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 10, 10), AI_STRIDE_INIT(4, 1, 1, 128, 1280),
  1, &eltwise_345_output_array, &eltwise_345_output_array_intq)

/* Tensor #446 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_346_output, AI_STATIC,
  446, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 10, 10), AI_STRIDE_INIT(4, 1, 1, 128, 1280),
  1, &eltwise_346_output_array, &eltwise_346_output_array_intq)

/* Tensor #447 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_347_output, AI_STATIC,
  447, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 10, 10), AI_STRIDE_INIT(4, 1, 1, 128, 1280),
  1, &eltwise_347_output_array, &eltwise_347_output_array_intq)

/* Tensor #448 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_348_output, AI_STATIC,
  448, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 10, 10), AI_STRIDE_INIT(4, 1, 1, 128, 1280),
  1, &eltwise_348_output_array, &eltwise_348_output_array_intq)

/* Tensor #449 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_34_output, AI_STATIC,
  449, 0x1,
  AI_SHAPE_INIT(4, 1, 16, 80, 80), AI_STRIDE_INIT(4, 1, 1, 16, 1280),
  1, &eltwise_34_output_array, &eltwise_34_output_array_intq)

/* Tensor #450 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_351_output, AI_STATIC,
  450, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 10, 10), AI_STRIDE_INIT(4, 1, 1, 128, 1280),
  1, &eltwise_351_output_array, &eltwise_351_output_array_intq)

/* Tensor #451 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_352_output, AI_STATIC,
  451, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 10, 10), AI_STRIDE_INIT(4, 1, 1, 128, 1280),
  1, &eltwise_352_output_array, &eltwise_352_output_array_intq)

/* Tensor #452 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_353_output, AI_STATIC,
  452, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 10, 10), AI_STRIDE_INIT(4, 1, 1, 128, 1280),
  1, &eltwise_353_output_array, &eltwise_353_output_array_intq)

/* Tensor #453 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_354_output, AI_STATIC,
  453, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 10, 10), AI_STRIDE_INIT(4, 1, 1, 128, 1280),
  1, &eltwise_354_output_array, &eltwise_354_output_array_intq)

/* Tensor #454 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_355_output, AI_STATIC,
  454, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 10, 10), AI_STRIDE_INIT(4, 1, 1, 128, 1280),
  1, &eltwise_355_output_array, &eltwise_355_output_array_intq)

/* Tensor #455 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_359_output, AI_STATIC,
  455, 0x1,
  AI_SHAPE_INIT(4, 1, 256, 10, 10), AI_STRIDE_INIT(4, 1, 1, 256, 2560),
  1, &eltwise_359_output_array, &eltwise_359_output_array_intq)

/* Tensor #456 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_35_output, AI_STATIC,
  456, 0x1,
  AI_SHAPE_INIT(4, 1, 16, 80, 80), AI_STRIDE_INIT(4, 1, 1, 16, 1280),
  1, &eltwise_35_output_array, &eltwise_35_output_array_intq)

/* Tensor #457 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_360_output, AI_STATIC,
  457, 0x1,
  AI_SHAPE_INIT(4, 1, 256, 10, 10), AI_STRIDE_INIT(4, 1, 1, 256, 2560),
  1, &eltwise_360_output_array, &eltwise_360_output_array_intq)

/* Tensor #458 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_361_output, AI_STATIC,
  458, 0x1,
  AI_SHAPE_INIT(4, 1, 256, 10, 10), AI_STRIDE_INIT(4, 1, 1, 256, 2560),
  1, &eltwise_361_output_array, &eltwise_361_output_array_intq)

/* Tensor #459 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_362_output, AI_STATIC,
  459, 0x1,
  AI_SHAPE_INIT(4, 1, 256, 10, 10), AI_STRIDE_INIT(4, 1, 1, 256, 2560),
  1, &eltwise_362_output_array, &eltwise_362_output_array_intq)

/* Tensor #460 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_363_output, AI_STATIC,
  460, 0x1,
  AI_SHAPE_INIT(4, 1, 256, 10, 10), AI_STRIDE_INIT(4, 1, 1, 256, 2560),
  1, &eltwise_363_output_array, &eltwise_363_output_array_intq)

/* Tensor #461 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_366_output, AI_STATIC,
  461, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 10, 10), AI_STRIDE_INIT(4, 1, 1, 64, 640),
  1, &eltwise_366_output_array, &eltwise_366_output_array_intq)

/* Tensor #462 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_367_output, AI_STATIC,
  462, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 10, 10), AI_STRIDE_INIT(4, 1, 1, 64, 640),
  1, &eltwise_367_output_array, &eltwise_367_output_array_intq)

/* Tensor #463 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_368_output, AI_STATIC,
  463, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 10, 10), AI_STRIDE_INIT(4, 1, 1, 64, 640),
  1, &eltwise_368_output_array, &eltwise_368_output_array_intq)

/* Tensor #464 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_369_output, AI_STATIC,
  464, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 10, 10), AI_STRIDE_INIT(4, 1, 1, 64, 640),
  1, &eltwise_369_output_array, &eltwise_369_output_array_intq)

/* Tensor #465 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_36_output, AI_STATIC,
  465, 0x1,
  AI_SHAPE_INIT(4, 1, 16, 80, 80), AI_STRIDE_INIT(4, 1, 1, 16, 1280),
  1, &eltwise_36_output_array, &eltwise_36_output_array_intq)

/* Tensor #466 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_370_output, AI_STATIC,
  466, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 10, 10), AI_STRIDE_INIT(4, 1, 1, 64, 640),
  1, &eltwise_370_output_array, &eltwise_370_output_array_intq)

/* Tensor #467 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_373_output, AI_STATIC,
  467, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 10, 10), AI_STRIDE_INIT(4, 1, 1, 64, 640),
  1, &eltwise_373_output_array, &eltwise_373_output_array_intq)

/* Tensor #468 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_374_output, AI_STATIC,
  468, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 10, 10), AI_STRIDE_INIT(4, 1, 1, 64, 640),
  1, &eltwise_374_output_array, &eltwise_374_output_array_intq)

/* Tensor #469 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_375_output, AI_STATIC,
  469, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 10, 10), AI_STRIDE_INIT(4, 1, 1, 64, 640),
  1, &eltwise_375_output_array, &eltwise_375_output_array_intq)

/* Tensor #470 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_376_output, AI_STATIC,
  470, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 10, 10), AI_STRIDE_INIT(4, 1, 1, 64, 640),
  1, &eltwise_376_output_array, &eltwise_376_output_array_intq)

/* Tensor #471 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_377_output, AI_STATIC,
  471, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 10, 10), AI_STRIDE_INIT(4, 1, 1, 64, 640),
  1, &eltwise_377_output_array, &eltwise_377_output_array_intq)

/* Tensor #472 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_37_output, AI_STATIC,
  472, 0x1,
  AI_SHAPE_INIT(4, 1, 16, 80, 80), AI_STRIDE_INIT(4, 1, 1, 16, 1280),
  1, &eltwise_37_output_array, &eltwise_37_output_array_intq)

/* Tensor #473 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_381_output, AI_STATIC,
  473, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 10, 10), AI_STRIDE_INIT(4, 1, 1, 64, 640),
  1, &eltwise_381_output_array, &eltwise_381_output_array_intq)

/* Tensor #474 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_382_output, AI_STATIC,
  474, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 10, 10), AI_STRIDE_INIT(4, 1, 1, 64, 640),
  1, &eltwise_382_output_array, &eltwise_382_output_array_intq)

/* Tensor #475 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_383_output, AI_STATIC,
  475, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 10, 10), AI_STRIDE_INIT(4, 1, 1, 64, 640),
  1, &eltwise_383_output_array, &eltwise_383_output_array_intq)

/* Tensor #476 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_384_output, AI_STATIC,
  476, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 10, 10), AI_STRIDE_INIT(4, 1, 1, 64, 640),
  1, &eltwise_384_output_array, &eltwise_384_output_array_intq)

/* Tensor #477 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_385_output, AI_STATIC,
  477, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 10, 10), AI_STRIDE_INIT(4, 1, 1, 64, 640),
  1, &eltwise_385_output_array, &eltwise_385_output_array_intq)

/* Tensor #478 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_388_output, AI_STATIC,
  478, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 10, 10), AI_STRIDE_INIT(4, 1, 1, 64, 640),
  1, &eltwise_388_output_array, &eltwise_388_output_array_intq)

/* Tensor #479 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_389_output, AI_STATIC,
  479, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 10, 10), AI_STRIDE_INIT(4, 1, 1, 64, 640),
  1, &eltwise_389_output_array, &eltwise_389_output_array_intq)

/* Tensor #480 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_38_output, AI_STATIC,
  480, 0x1,
  AI_SHAPE_INIT(4, 1, 16, 80, 80), AI_STRIDE_INIT(4, 1, 1, 16, 1280),
  1, &eltwise_38_output_array, &eltwise_38_output_array_intq)

/* Tensor #481 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_390_output, AI_STATIC,
  481, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 10, 10), AI_STRIDE_INIT(4, 1, 1, 64, 640),
  1, &eltwise_390_output_array, &eltwise_390_output_array_intq)

/* Tensor #482 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_391_output, AI_STATIC,
  482, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 10, 10), AI_STRIDE_INIT(4, 1, 1, 64, 640),
  1, &eltwise_391_output_array, &eltwise_391_output_array_intq)

/* Tensor #483 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_392_output, AI_STATIC,
  483, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 10, 10), AI_STRIDE_INIT(4, 1, 1, 64, 640),
  1, &eltwise_392_output_array, &eltwise_392_output_array_intq)

/* Tensor #484 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_399_output, AI_STATIC,
  484, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 20, 20), AI_STRIDE_INIT(4, 1, 1, 64, 1280),
  1, &eltwise_399_output_array, &eltwise_399_output_array_intq)

/* Tensor #485 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_3_output, AI_STATIC,
  485, 0x1,
  AI_SHAPE_INIT(4, 1, 16, 160, 160), AI_STRIDE_INIT(4, 1, 1, 16, 2560),
  1, &eltwise_3_output_array, &eltwise_3_output_array_intq)

/* Tensor #486 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_400_output, AI_STATIC,
  486, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 20, 20), AI_STRIDE_INIT(4, 1, 1, 64, 1280),
  1, &eltwise_400_output_array, &eltwise_400_output_array_intq)

/* Tensor #487 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_401_output, AI_STATIC,
  487, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 20, 20), AI_STRIDE_INIT(4, 1, 1, 64, 1280),
  1, &eltwise_401_output_array, &eltwise_401_output_array_intq)

/* Tensor #488 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_402_output, AI_STATIC,
  488, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 20, 20), AI_STRIDE_INIT(4, 1, 1, 64, 1280),
  1, &eltwise_402_output_array, &eltwise_402_output_array_intq)

/* Tensor #489 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_403_output, AI_STATIC,
  489, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 20, 20), AI_STRIDE_INIT(4, 1, 1, 64, 1280),
  1, &eltwise_403_output_array, &eltwise_403_output_array_intq)

/* Tensor #490 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_406_output, AI_STATIC,
  490, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 20, 20), AI_STRIDE_INIT(4, 1, 1, 64, 1280),
  1, &eltwise_406_output_array, &eltwise_406_output_array_intq)

/* Tensor #491 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_407_output, AI_STATIC,
  491, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 20, 20), AI_STRIDE_INIT(4, 1, 1, 64, 1280),
  1, &eltwise_407_output_array, &eltwise_407_output_array_intq)

/* Tensor #492 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_408_output, AI_STATIC,
  492, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 20, 20), AI_STRIDE_INIT(4, 1, 1, 64, 1280),
  1, &eltwise_408_output_array, &eltwise_408_output_array_intq)

/* Tensor #493 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_409_output, AI_STATIC,
  493, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 20, 20), AI_STRIDE_INIT(4, 1, 1, 64, 1280),
  1, &eltwise_409_output_array, &eltwise_409_output_array_intq)

/* Tensor #494 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_410_output, AI_STATIC,
  494, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 20, 20), AI_STRIDE_INIT(4, 1, 1, 64, 1280),
  1, &eltwise_410_output_array, &eltwise_410_output_array_intq)

/* Tensor #495 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_414_output, AI_STATIC,
  495, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 20, 20), AI_STRIDE_INIT(4, 1, 1, 64, 1280),
  1, &eltwise_414_output_array, &eltwise_414_output_array_intq)

/* Tensor #496 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_415_output, AI_STATIC,
  496, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 20, 20), AI_STRIDE_INIT(4, 1, 1, 64, 1280),
  1, &eltwise_415_output_array, &eltwise_415_output_array_intq)

/* Tensor #497 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_416_output, AI_STATIC,
  497, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 20, 20), AI_STRIDE_INIT(4, 1, 1, 64, 1280),
  1, &eltwise_416_output_array, &eltwise_416_output_array_intq)

/* Tensor #498 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_417_output, AI_STATIC,
  498, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 20, 20), AI_STRIDE_INIT(4, 1, 1, 64, 1280),
  1, &eltwise_417_output_array, &eltwise_417_output_array_intq)

/* Tensor #499 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_418_output, AI_STATIC,
  499, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 20, 20), AI_STRIDE_INIT(4, 1, 1, 64, 1280),
  1, &eltwise_418_output_array, &eltwise_418_output_array_intq)

/* Tensor #500 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_421_output, AI_STATIC,
  500, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 20, 20), AI_STRIDE_INIT(4, 1, 1, 64, 1280),
  1, &eltwise_421_output_array, &eltwise_421_output_array_intq)

/* Tensor #501 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_422_output, AI_STATIC,
  501, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 20, 20), AI_STRIDE_INIT(4, 1, 1, 64, 1280),
  1, &eltwise_422_output_array, &eltwise_422_output_array_intq)

/* Tensor #502 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_423_output, AI_STATIC,
  502, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 20, 20), AI_STRIDE_INIT(4, 1, 1, 64, 1280),
  1, &eltwise_423_output_array, &eltwise_423_output_array_intq)

/* Tensor #503 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_424_output, AI_STATIC,
  503, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 20, 20), AI_STRIDE_INIT(4, 1, 1, 64, 1280),
  1, &eltwise_424_output_array, &eltwise_424_output_array_intq)

/* Tensor #504 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_425_output, AI_STATIC,
  504, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 20, 20), AI_STRIDE_INIT(4, 1, 1, 64, 1280),
  1, &eltwise_425_output_array, &eltwise_425_output_array_intq)

/* Tensor #505 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_432_output, AI_STATIC,
  505, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 40, 40), AI_STRIDE_INIT(4, 1, 1, 64, 2560),
  1, &eltwise_432_output_array, &eltwise_432_output_array_intq)

/* Tensor #506 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_433_output, AI_STATIC,
  506, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 40, 40), AI_STRIDE_INIT(4, 1, 1, 64, 2560),
  1, &eltwise_433_output_array, &eltwise_433_output_array_intq)

/* Tensor #507 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_434_output, AI_STATIC,
  507, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 40, 40), AI_STRIDE_INIT(4, 1, 1, 64, 2560),
  1, &eltwise_434_output_array, &eltwise_434_output_array_intq)

/* Tensor #508 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_435_output, AI_STATIC,
  508, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 40, 40), AI_STRIDE_INIT(4, 1, 1, 64, 2560),
  1, &eltwise_435_output_array, &eltwise_435_output_array_intq)

/* Tensor #509 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_436_output, AI_STATIC,
  509, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 40, 40), AI_STRIDE_INIT(4, 1, 1, 64, 2560),
  1, &eltwise_436_output_array, &eltwise_436_output_array_intq)

/* Tensor #510 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_439_output, AI_STATIC,
  510, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 40, 40), AI_STRIDE_INIT(4, 1, 1, 64, 2560),
  1, &eltwise_439_output_array, &eltwise_439_output_array_intq)

/* Tensor #511 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_43_output, AI_STATIC,
  511, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 80, 80), AI_STRIDE_INIT(4, 1, 1, 32, 2560),
  1, &eltwise_43_output_array, &eltwise_43_output_array_intq)

/* Tensor #512 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_440_output, AI_STATIC,
  512, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 40, 40), AI_STRIDE_INIT(4, 1, 1, 64, 2560),
  1, &eltwise_440_output_array, &eltwise_440_output_array_intq)

/* Tensor #513 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_441_output, AI_STATIC,
  513, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 40, 40), AI_STRIDE_INIT(4, 1, 1, 64, 2560),
  1, &eltwise_441_output_array, &eltwise_441_output_array_intq)

/* Tensor #514 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_442_output, AI_STATIC,
  514, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 40, 40), AI_STRIDE_INIT(4, 1, 1, 64, 2560),
  1, &eltwise_442_output_array, &eltwise_442_output_array_intq)

/* Tensor #515 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_443_output, AI_STATIC,
  515, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 40, 40), AI_STRIDE_INIT(4, 1, 1, 64, 2560),
  1, &eltwise_443_output_array, &eltwise_443_output_array_intq)

/* Tensor #516 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_447_output, AI_STATIC,
  516, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 40, 40), AI_STRIDE_INIT(4, 1, 1, 64, 2560),
  1, &eltwise_447_output_array, &eltwise_447_output_array_intq)

/* Tensor #517 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_448_output, AI_STATIC,
  517, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 40, 40), AI_STRIDE_INIT(4, 1, 1, 64, 2560),
  1, &eltwise_448_output_array, &eltwise_448_output_array_intq)

/* Tensor #518 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_449_output, AI_STATIC,
  518, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 40, 40), AI_STRIDE_INIT(4, 1, 1, 64, 2560),
  1, &eltwise_449_output_array, &eltwise_449_output_array_intq)

/* Tensor #519 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_44_output, AI_STATIC,
  519, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 80, 80), AI_STRIDE_INIT(4, 1, 1, 32, 2560),
  1, &eltwise_44_output_array, &eltwise_44_output_array_intq)

/* Tensor #520 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_450_output, AI_STATIC,
  520, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 40, 40), AI_STRIDE_INIT(4, 1, 1, 64, 2560),
  1, &eltwise_450_output_array, &eltwise_450_output_array_intq)

/* Tensor #521 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_451_output, AI_STATIC,
  521, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 40, 40), AI_STRIDE_INIT(4, 1, 1, 64, 2560),
  1, &eltwise_451_output_array, &eltwise_451_output_array_intq)

/* Tensor #522 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_454_output, AI_STATIC,
  522, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 40, 40), AI_STRIDE_INIT(4, 1, 1, 64, 2560),
  1, &eltwise_454_output_array, &eltwise_454_output_array_intq)

/* Tensor #523 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_455_output, AI_STATIC,
  523, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 40, 40), AI_STRIDE_INIT(4, 1, 1, 64, 2560),
  1, &eltwise_455_output_array, &eltwise_455_output_array_intq)

/* Tensor #524 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_456_output, AI_STATIC,
  524, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 40, 40), AI_STRIDE_INIT(4, 1, 1, 64, 2560),
  1, &eltwise_456_output_array, &eltwise_456_output_array_intq)

/* Tensor #525 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_457_output, AI_STATIC,
  525, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 40, 40), AI_STRIDE_INIT(4, 1, 1, 64, 2560),
  1, &eltwise_457_output_array, &eltwise_457_output_array_intq)

/* Tensor #526 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_458_output, AI_STATIC,
  526, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 40, 40), AI_STRIDE_INIT(4, 1, 1, 64, 2560),
  1, &eltwise_458_output_array, &eltwise_458_output_array_intq)

/* Tensor #527 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_45_output, AI_STATIC,
  527, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 80, 80), AI_STRIDE_INIT(4, 1, 1, 32, 2560),
  1, &eltwise_45_output_array, &eltwise_45_output_array_intq)

/* Tensor #528 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_46_output, AI_STATIC,
  528, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 80, 80), AI_STRIDE_INIT(4, 1, 1, 32, 2560),
  1, &eltwise_46_output_array, &eltwise_46_output_array_intq)

/* Tensor #529 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_470_output, AI_STATIC,
  529, 0x1,
  AI_SHAPE_INIT(4, 1, 2100, 4, 1), AI_STRIDE_INIT(4, 1, 1, 2100, 8400),
  1, &eltwise_470_output_array, &eltwise_470_output_array_intq)

/* Tensor #530 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_470_output0, AI_STATIC,
  530, 0x1,
  AI_SHAPE_INIT(4, 1, 2100, 1, 4), AI_STRIDE_INIT(4, 1, 1, 2100, 2100),
  1, &eltwise_470_output_array, &eltwise_470_output_array_intq)

/* Tensor #531 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_473_output, AI_STATIC,
  531, 0x1,
  AI_SHAPE_INIT(4, 1, 2100, 1, 2), AI_STRIDE_INIT(4, 1, 1, 2100, 2100),
  1, &eltwise_473_output_array, &eltwise_473_output_array_intq)

/* Tensor #532 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_475_output, AI_STATIC,
  532, 0x1,
  AI_SHAPE_INIT(4, 1, 2100, 1, 2), AI_STRIDE_INIT(4, 1, 1, 2100, 2100),
  1, &eltwise_475_output_array, &eltwise_475_output_array_intq)

/* Tensor #533 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_476_output, AI_STATIC,
  533, 0x1,
  AI_SHAPE_INIT(4, 1, 2100, 1, 2), AI_STRIDE_INIT(4, 1, 1, 2100, 2100),
  1, &eltwise_476_output_array, &eltwise_476_output_array_intq)

/* Tensor #534 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_477_output, AI_STATIC,
  534, 0x1,
  AI_SHAPE_INIT(4, 1, 2100, 1, 2), AI_STRIDE_INIT(4, 1, 1, 2100, 2100),
  1, &eltwise_477_output_array, &eltwise_477_output_array_intq)

/* Tensor #535 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_478_output, AI_STATIC,
  535, 0x1,
  AI_SHAPE_INIT(4, 1, 2100, 1, 2), AI_STRIDE_INIT(4, 1, 1, 2100, 2100),
  1, &eltwise_478_output_array, &eltwise_478_output_array_intq)

/* Tensor #536 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_47_output, AI_STATIC,
  536, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 80, 80), AI_STRIDE_INIT(4, 1, 1, 32, 2560),
  1, &eltwise_47_output_array, &eltwise_47_output_array_intq)

/* Tensor #537 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_4_output, AI_STATIC,
  537, 0x1,
  AI_SHAPE_INIT(4, 1, 16, 160, 160), AI_STRIDE_INIT(4, 1, 1, 16, 2560),
  1, &eltwise_4_output_array, &eltwise_4_output_array_intq)

/* Tensor #538 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_51_output, AI_STATIC,
  538, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 40, 40), AI_STRIDE_INIT(4, 1, 1, 64, 2560),
  1, &eltwise_51_output_array, &eltwise_51_output_array_intq)

/* Tensor #539 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_52_output, AI_STATIC,
  539, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 40, 40), AI_STRIDE_INIT(4, 1, 1, 64, 2560),
  1, &eltwise_52_output_array, &eltwise_52_output_array_intq)

/* Tensor #540 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_53_output, AI_STATIC,
  540, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 40, 40), AI_STRIDE_INIT(4, 1, 1, 64, 2560),
  1, &eltwise_53_output_array, &eltwise_53_output_array_intq)

/* Tensor #541 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_54_output, AI_STATIC,
  541, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 40, 40), AI_STRIDE_INIT(4, 1, 1, 64, 2560),
  1, &eltwise_54_output_array, &eltwise_54_output_array_intq)

/* Tensor #542 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_55_output, AI_STATIC,
  542, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 40, 40), AI_STRIDE_INIT(4, 1, 1, 64, 2560),
  1, &eltwise_55_output_array, &eltwise_55_output_array_intq)

/* Tensor #543 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_58_output, AI_STATIC,
  543, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 40, 40), AI_STRIDE_INIT(4, 1, 1, 64, 2560),
  1, &eltwise_58_output_array, &eltwise_58_output_array_intq)

/* Tensor #544 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_59_output, AI_STATIC,
  544, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 40, 40), AI_STRIDE_INIT(4, 1, 1, 64, 2560),
  1, &eltwise_59_output_array, &eltwise_59_output_array_intq)

/* Tensor #545 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_5_output, AI_STATIC,
  545, 0x1,
  AI_SHAPE_INIT(4, 1, 16, 160, 160), AI_STRIDE_INIT(4, 1, 1, 16, 2560),
  1, &eltwise_5_output_array, &eltwise_5_output_array_intq)

/* Tensor #546 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_60_output, AI_STATIC,
  546, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 40, 40), AI_STRIDE_INIT(4, 1, 1, 64, 2560),
  1, &eltwise_60_output_array, &eltwise_60_output_array_intq)

/* Tensor #547 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_61_output, AI_STATIC,
  547, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 40, 40), AI_STRIDE_INIT(4, 1, 1, 64, 2560),
  1, &eltwise_61_output_array, &eltwise_61_output_array_intq)

/* Tensor #548 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_62_output, AI_STATIC,
  548, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 40, 40), AI_STRIDE_INIT(4, 1, 1, 64, 2560),
  1, &eltwise_62_output_array, &eltwise_62_output_array_intq)

/* Tensor #549 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_67_output, AI_STATIC,
  549, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 40, 40), AI_STRIDE_INIT(4, 1, 1, 32, 1280),
  1, &eltwise_67_output_array, &eltwise_67_output_array_intq)

/* Tensor #550 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_68_output, AI_STATIC,
  550, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 40, 40), AI_STRIDE_INIT(4, 1, 1, 32, 1280),
  1, &eltwise_68_output_array, &eltwise_68_output_array_intq)

/* Tensor #551 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_69_output, AI_STATIC,
  551, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 40, 40), AI_STRIDE_INIT(4, 1, 1, 32, 1280),
  1, &eltwise_69_output_array, &eltwise_69_output_array_intq)

/* Tensor #552 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_6_output, AI_STATIC,
  552, 0x1,
  AI_SHAPE_INIT(4, 1, 16, 160, 160), AI_STRIDE_INIT(4, 1, 1, 16, 2560),
  1, &eltwise_6_output_array, &eltwise_6_output_array_intq)

/* Tensor #553 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_70_output, AI_STATIC,
  553, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 40, 40), AI_STRIDE_INIT(4, 1, 1, 32, 1280),
  1, &eltwise_70_output_array, &eltwise_70_output_array_intq)

/* Tensor #554 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_71_output, AI_STATIC,
  554, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 40, 40), AI_STRIDE_INIT(4, 1, 1, 32, 1280),
  1, &eltwise_71_output_array, &eltwise_71_output_array_intq)

/* Tensor #555 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_74_output, AI_STATIC,
  555, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 40, 40), AI_STRIDE_INIT(4, 1, 1, 32, 1280),
  1, &eltwise_74_output_array, &eltwise_74_output_array_intq)

/* Tensor #556 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_75_output, AI_STATIC,
  556, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 40, 40), AI_STRIDE_INIT(4, 1, 1, 32, 1280),
  1, &eltwise_75_output_array, &eltwise_75_output_array_intq)

/* Tensor #557 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_76_output, AI_STATIC,
  557, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 40, 40), AI_STRIDE_INIT(4, 1, 1, 32, 1280),
  1, &eltwise_76_output_array, &eltwise_76_output_array_intq)

/* Tensor #558 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_77_output, AI_STATIC,
  558, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 40, 40), AI_STRIDE_INIT(4, 1, 1, 32, 1280),
  1, &eltwise_77_output_array, &eltwise_77_output_array_intq)

/* Tensor #559 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_78_output, AI_STATIC,
  559, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 40, 40), AI_STRIDE_INIT(4, 1, 1, 32, 1280),
  1, &eltwise_78_output_array, &eltwise_78_output_array_intq)

/* Tensor #560 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_79_output, AI_STATIC,
  560, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 40, 40), AI_STRIDE_INIT(4, 1, 1, 32, 1280),
  1, &eltwise_79_output_array, &eltwise_79_output_array_intq)

/* Tensor #561 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_7_output, AI_STATIC,
  561, 0x1,
  AI_SHAPE_INIT(4, 1, 16, 160, 160), AI_STRIDE_INIT(4, 1, 1, 16, 2560),
  1, &eltwise_7_output_array, &eltwise_7_output_array_intq)

/* Tensor #562 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_82_output, AI_STATIC,
  562, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 40, 40), AI_STRIDE_INIT(4, 1, 1, 32, 1280),
  1, &eltwise_82_output_array, &eltwise_82_output_array_intq)

/* Tensor #563 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_83_output, AI_STATIC,
  563, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 40, 40), AI_STRIDE_INIT(4, 1, 1, 32, 1280),
  1, &eltwise_83_output_array, &eltwise_83_output_array_intq)

/* Tensor #564 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_84_output, AI_STATIC,
  564, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 40, 40), AI_STRIDE_INIT(4, 1, 1, 32, 1280),
  1, &eltwise_84_output_array, &eltwise_84_output_array_intq)

/* Tensor #565 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_85_output, AI_STATIC,
  565, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 40, 40), AI_STRIDE_INIT(4, 1, 1, 32, 1280),
  1, &eltwise_85_output_array, &eltwise_85_output_array_intq)

/* Tensor #566 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_86_output, AI_STATIC,
  566, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 40, 40), AI_STRIDE_INIT(4, 1, 1, 32, 1280),
  1, &eltwise_86_output_array, &eltwise_86_output_array_intq)

/* Tensor #567 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_89_output, AI_STATIC,
  567, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 40, 40), AI_STRIDE_INIT(4, 1, 1, 32, 1280),
  1, &eltwise_89_output_array, &eltwise_89_output_array_intq)

/* Tensor #568 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_90_output, AI_STATIC,
  568, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 40, 40), AI_STRIDE_INIT(4, 1, 1, 32, 1280),
  1, &eltwise_90_output_array, &eltwise_90_output_array_intq)

/* Tensor #569 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_91_output, AI_STATIC,
  569, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 40, 40), AI_STRIDE_INIT(4, 1, 1, 32, 1280),
  1, &eltwise_91_output_array, &eltwise_91_output_array_intq)

/* Tensor #570 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_92_output, AI_STATIC,
  570, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 40, 40), AI_STRIDE_INIT(4, 1, 1, 32, 1280),
  1, &eltwise_92_output_array, &eltwise_92_output_array_intq)

/* Tensor #571 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_93_output, AI_STATIC,
  571, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 40, 40), AI_STRIDE_INIT(4, 1, 1, 32, 1280),
  1, &eltwise_93_output_array, &eltwise_93_output_array_intq)

/* Tensor #572 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_94_output, AI_STATIC,
  572, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 40, 40), AI_STRIDE_INIT(4, 1, 1, 32, 1280),
  1, &eltwise_94_output_array, &eltwise_94_output_array_intq)

/* Tensor #573 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_98_output, AI_STATIC,
  573, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 40, 40), AI_STRIDE_INIT(4, 1, 1, 64, 2560),
  1, &eltwise_98_output_array, &eltwise_98_output_array_intq)

/* Tensor #574 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_99_output, AI_STATIC,
  574, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 40, 40), AI_STRIDE_INIT(4, 1, 1, 64, 2560),
  1, &eltwise_99_output_array, &eltwise_99_output_array_intq)

/* Tensor #575 */
AI_TENSOR_OBJ_DECLARE(
  nl_105_output, AI_STATIC,
  575, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 20, 20), AI_STRIDE_INIT(4, 1, 1, 128, 2560),
  1, &nl_105_output_array, &nl_105_output_array_intq)

/* Tensor #576 */
AI_TENSOR_OBJ_DECLARE(
  nl_10_output, AI_STATIC,
  576, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 80, 80), AI_STRIDE_INIT(4, 1, 1, 32, 2560),
  1, &nl_10_output_array, &nl_10_output_array_intq)

/* Tensor #577 */
AI_TENSOR_OBJ_DECLARE(
  nl_112_output, AI_STATIC,
  577, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 20, 20), AI_STRIDE_INIT(4, 1, 1, 128, 2560),
  1, &nl_112_output_array, &nl_112_output_array_intq)

/* Tensor #578 */
AI_TENSOR_OBJ_DECLARE(
  nl_121_output, AI_STATIC,
  578, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 20, 20), AI_STRIDE_INIT(4, 1, 1, 64, 1280),
  1, &nl_121_output_array, &nl_121_output_array_intq)

/* Tensor #579 */
AI_TENSOR_OBJ_DECLARE(
  nl_128_output, AI_STATIC,
  579, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 20, 20), AI_STRIDE_INIT(4, 1, 1, 64, 1280),
  1, &nl_128_output_array, &nl_128_output_array_intq)

/* Tensor #580 */
AI_TENSOR_OBJ_DECLARE(
  nl_136_output, AI_STATIC,
  580, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 20, 20), AI_STRIDE_INIT(4, 1, 1, 64, 1280),
  1, &nl_136_output_array, &nl_136_output_array_intq)

/* Tensor #581 */
AI_TENSOR_OBJ_DECLARE(
  nl_143_output, AI_STATIC,
  581, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 20, 20), AI_STRIDE_INIT(4, 1, 1, 64, 1280),
  1, &nl_143_output_array, &nl_143_output_array_intq)

/* Tensor #582 */
AI_TENSOR_OBJ_DECLARE(
  nl_152_output, AI_STATIC,
  582, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 20, 20), AI_STRIDE_INIT(4, 1, 1, 128, 2560),
  1, &nl_152_output_array, &nl_152_output_array_intq)

/* Tensor #583 */
AI_TENSOR_OBJ_DECLARE(
  nl_160_output, AI_STATIC,
  583, 0x1,
  AI_SHAPE_INIT(4, 1, 256, 10, 10), AI_STRIDE_INIT(4, 1, 1, 256, 2560),
  1, &nl_160_output_array, &nl_160_output_array_intq)

/* Tensor #584 */
AI_TENSOR_OBJ_DECLARE(
  nl_167_output, AI_STATIC,
  584, 0x1,
  AI_SHAPE_INIT(4, 1, 256, 10, 10), AI_STRIDE_INIT(4, 1, 1, 256, 2560),
  1, &nl_167_output_array, &nl_167_output_array_intq)

/* Tensor #585 */
AI_TENSOR_OBJ_DECLARE(
  nl_176_output, AI_STATIC,
  585, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 10, 10), AI_STRIDE_INIT(4, 1, 1, 128, 1280),
  1, &nl_176_output_array, &nl_176_output_array_intq)

/* Tensor #586 */
AI_TENSOR_OBJ_DECLARE(
  nl_17_output, AI_STATIC,
  586, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 80, 80), AI_STRIDE_INIT(4, 1, 1, 32, 2560),
  1, &nl_17_output_array, &nl_17_output_array_intq)

/* Tensor #587 */
AI_TENSOR_OBJ_DECLARE(
  nl_183_output, AI_STATIC,
  587, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 10, 10), AI_STRIDE_INIT(4, 1, 1, 128, 1280),
  1, &nl_183_output_array, &nl_183_output_array_intq)

/* Tensor #588 */
AI_TENSOR_OBJ_DECLARE(
  nl_192_output, AI_STATIC,
  588, 0x1,
  AI_SHAPE_INIT(4, 1, 256, 10, 10), AI_STRIDE_INIT(4, 1, 1, 256, 2560),
  1, &nl_192_output_array, &nl_192_output_array_intq)

/* Tensor #589 */
AI_TENSOR_OBJ_DECLARE(
  nl_199_output, AI_STATIC,
  589, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 10, 10), AI_STRIDE_INIT(4, 1, 1, 128, 1280),
  1, &nl_199_output_array, &nl_199_output_array_intq)

/* Tensor #590 */
AI_TENSOR_OBJ_DECLARE(
  nl_210_output, AI_STATIC,
  590, 0x1,
  AI_SHAPE_INIT(4, 1, 256, 10, 10), AI_STRIDE_INIT(4, 1, 1, 256, 2560),
  1, &nl_210_output_array, &nl_210_output_array_intq)

/* Tensor #591 */
AI_TENSOR_OBJ_DECLARE(
  nl_220_output, AI_STATIC,
  591, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 20, 20), AI_STRIDE_INIT(4, 1, 1, 128, 2560),
  1, &nl_220_output_array, &nl_220_output_array_intq)

/* Tensor #592 */
AI_TENSOR_OBJ_DECLARE(
  nl_229_output, AI_STATIC,
  592, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 20, 20), AI_STRIDE_INIT(4, 1, 1, 64, 1280),
  1, &nl_229_output_array, &nl_229_output_array_intq)

/* Tensor #593 */
AI_TENSOR_OBJ_DECLARE(
  nl_236_output, AI_STATIC,
  593, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 20, 20), AI_STRIDE_INIT(4, 1, 1, 64, 1280),
  1, &nl_236_output_array, &nl_236_output_array_intq)

/* Tensor #594 */
AI_TENSOR_OBJ_DECLARE(
  nl_244_output, AI_STATIC,
  594, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 20, 20), AI_STRIDE_INIT(4, 1, 1, 128, 2560),
  1, &nl_244_output_array, &nl_244_output_array_intq)

/* Tensor #595 */
AI_TENSOR_OBJ_DECLARE(
  nl_254_output, AI_STATIC,
  595, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 40, 40), AI_STRIDE_INIT(4, 1, 1, 64, 2560),
  1, &nl_254_output_array, &nl_254_output_array_intq)

/* Tensor #596 */
AI_TENSOR_OBJ_DECLARE(
  nl_25_output, AI_STATIC,
  596, 0x1,
  AI_SHAPE_INIT(4, 1, 16, 80, 80), AI_STRIDE_INIT(4, 1, 1, 16, 1280),
  1, &nl_25_output_array, &nl_25_output_array_intq)

/* Tensor #597 */
AI_TENSOR_OBJ_DECLARE(
  nl_263_output, AI_STATIC,
  597, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 40, 40), AI_STRIDE_INIT(4, 1, 1, 32, 1280),
  1, &nl_263_output_array, &nl_263_output_array_intq)

/* Tensor #598 */
AI_TENSOR_OBJ_DECLARE(
  nl_270_output, AI_STATIC,
  598, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 40, 40), AI_STRIDE_INIT(4, 1, 1, 32, 1280),
  1, &nl_270_output_array, &nl_270_output_array_intq)

/* Tensor #599 */
AI_TENSOR_OBJ_DECLARE(
  nl_278_output, AI_STATIC,
  599, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 40, 40), AI_STRIDE_INIT(4, 1, 1, 64, 2560),
  1, &nl_278_output_array, &nl_278_output_array_intq)

/* Tensor #600 */
AI_TENSOR_OBJ_DECLARE(
  nl_286_output, AI_STATIC,
  600, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 20, 20), AI_STRIDE_INIT(4, 1, 1, 64, 1280),
  1, &nl_286_output_array, &nl_286_output_array_intq)

/* Tensor #601 */
AI_TENSOR_OBJ_DECLARE(
  nl_294_output, AI_STATIC,
  601, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 20, 20), AI_STRIDE_INIT(4, 1, 1, 128, 2560),
  1, &nl_294_output_array, &nl_294_output_array_intq)

/* Tensor #602 */
AI_TENSOR_OBJ_DECLARE(
  nl_2_output, AI_STATIC,
  602, 0x1,
  AI_SHAPE_INIT(4, 1, 16, 160, 160), AI_STRIDE_INIT(4, 1, 1, 16, 2560),
  1, &nl_2_output_array, &nl_2_output_array_intq)

/* Tensor #603 */
AI_TENSOR_OBJ_DECLARE(
  nl_303_output, AI_STATIC,
  603, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 20, 20), AI_STRIDE_INIT(4, 1, 1, 64, 1280),
  1, &nl_303_output_array, &nl_303_output_array_intq)

/* Tensor #604 */
AI_TENSOR_OBJ_DECLARE(
  nl_310_output, AI_STATIC,
  604, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 20, 20), AI_STRIDE_INIT(4, 1, 1, 64, 1280),
  1, &nl_310_output_array, &nl_310_output_array_intq)

/* Tensor #605 */
AI_TENSOR_OBJ_DECLARE(
  nl_318_output, AI_STATIC,
  605, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 20, 20), AI_STRIDE_INIT(4, 1, 1, 128, 2560),
  1, &nl_318_output_array, &nl_318_output_array_intq)

/* Tensor #606 */
AI_TENSOR_OBJ_DECLARE(
  nl_326_output, AI_STATIC,
  606, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 10, 10), AI_STRIDE_INIT(4, 1, 1, 128, 1280),
  1, &nl_326_output_array, &nl_326_output_array_intq)

/* Tensor #607 */
AI_TENSOR_OBJ_DECLARE(
  nl_32_output, AI_STATIC,
  607, 0x1,
  AI_SHAPE_INIT(4, 1, 16, 80, 80), AI_STRIDE_INIT(4, 1, 1, 16, 1280),
  1, &nl_32_output_array, &nl_32_output_array_intq)

/* Tensor #608 */
AI_TENSOR_OBJ_DECLARE(
  nl_334_output, AI_STATIC,
  608, 0x1,
  AI_SHAPE_INIT(4, 1, 256, 10, 10), AI_STRIDE_INIT(4, 1, 1, 256, 2560),
  1, &nl_334_output_array, &nl_334_output_array_intq)

/* Tensor #609 */
AI_TENSOR_OBJ_DECLARE(
  nl_343_output, AI_STATIC,
  609, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 10, 10), AI_STRIDE_INIT(4, 1, 1, 128, 1280),
  1, &nl_343_output_array, &nl_343_output_array_intq)

/* Tensor #610 */
AI_TENSOR_OBJ_DECLARE(
  nl_350_output, AI_STATIC,
  610, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 10, 10), AI_STRIDE_INIT(4, 1, 1, 128, 1280),
  1, &nl_350_output_array, &nl_350_output_array_intq)

/* Tensor #611 */
AI_TENSOR_OBJ_DECLARE(
  nl_358_output, AI_STATIC,
  611, 0x1,
  AI_SHAPE_INIT(4, 1, 256, 10, 10), AI_STRIDE_INIT(4, 1, 1, 256, 2560),
  1, &nl_358_output_array, &nl_358_output_array_intq)

/* Tensor #612 */
AI_TENSOR_OBJ_DECLARE(
  nl_365_output, AI_STATIC,
  612, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 10, 10), AI_STRIDE_INIT(4, 1, 1, 64, 640),
  1, &nl_365_output_array, &nl_365_output_array_intq)

/* Tensor #613 */
AI_TENSOR_OBJ_DECLARE(
  nl_372_output, AI_STATIC,
  613, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 10, 10), AI_STRIDE_INIT(4, 1, 1, 64, 640),
  1, &nl_372_output_array, &nl_372_output_array_intq)

/* Tensor #614 */
AI_TENSOR_OBJ_DECLARE(
  nl_380_output, AI_STATIC,
  614, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 10, 10), AI_STRIDE_INIT(4, 1, 1, 64, 640),
  1, &nl_380_output_array, &nl_380_output_array_intq)

/* Tensor #615 */
AI_TENSOR_OBJ_DECLARE(
  nl_387_output, AI_STATIC,
  615, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 10, 10), AI_STRIDE_INIT(4, 1, 1, 64, 640),
  1, &nl_387_output_array, &nl_387_output_array_intq)

/* Tensor #616 */
AI_TENSOR_OBJ_DECLARE(
  nl_398_output, AI_STATIC,
  616, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 20, 20), AI_STRIDE_INIT(4, 1, 1, 64, 1280),
  1, &nl_398_output_array, &nl_398_output_array_intq)

/* Tensor #617 */
AI_TENSOR_OBJ_DECLARE(
  nl_405_output, AI_STATIC,
  617, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 20, 20), AI_STRIDE_INIT(4, 1, 1, 64, 1280),
  1, &nl_405_output_array, &nl_405_output_array_intq)

/* Tensor #618 */
AI_TENSOR_OBJ_DECLARE(
  nl_413_output, AI_STATIC,
  618, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 20, 20), AI_STRIDE_INIT(4, 1, 1, 64, 1280),
  1, &nl_413_output_array, &nl_413_output_array_intq)

/* Tensor #619 */
AI_TENSOR_OBJ_DECLARE(
  nl_420_output, AI_STATIC,
  619, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 20, 20), AI_STRIDE_INIT(4, 1, 1, 64, 1280),
  1, &nl_420_output_array, &nl_420_output_array_intq)

/* Tensor #620 */
AI_TENSOR_OBJ_DECLARE(
  nl_42_output, AI_STATIC,
  620, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 80, 80), AI_STRIDE_INIT(4, 1, 1, 32, 2560),
  1, &nl_42_output_array, &nl_42_output_array_intq)

/* Tensor #621 */
AI_TENSOR_OBJ_DECLARE(
  nl_431_output, AI_STATIC,
  621, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 40, 40), AI_STRIDE_INIT(4, 1, 1, 64, 2560),
  1, &nl_431_output_array, &nl_431_output_array_intq)

/* Tensor #622 */
AI_TENSOR_OBJ_DECLARE(
  nl_438_output, AI_STATIC,
  622, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 40, 40), AI_STRIDE_INIT(4, 1, 1, 64, 2560),
  1, &nl_438_output_array, &nl_438_output_array_intq)

/* Tensor #623 */
AI_TENSOR_OBJ_DECLARE(
  nl_446_output, AI_STATIC,
  623, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 40, 40), AI_STRIDE_INIT(4, 1, 1, 64, 2560),
  1, &nl_446_output_array, &nl_446_output_array_intq)

/* Tensor #624 */
AI_TENSOR_OBJ_DECLARE(
  nl_453_output, AI_STATIC,
  624, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 40, 40), AI_STRIDE_INIT(4, 1, 1, 64, 2560),
  1, &nl_453_output_array, &nl_453_output_array_intq)

/* Tensor #625 */
AI_TENSOR_OBJ_DECLARE(
  nl_467_output, AI_STATIC,
  625, 0x1,
  AI_SHAPE_INIT(4, 1, 16, 2100, 4), AI_STRIDE_INIT(4, 1, 1, 16, 33600),
  1, &nl_467_output_array, &nl_467_output_array_intq)

/* Tensor #626 */
AI_TENSOR_OBJ_DECLARE(
  nl_467_scratch0, AI_STATIC,
  626, 0x0,
  AI_SHAPE_INIT(4, 1, 31, 1, 1), AI_STRIDE_INIT(4, 4, 4, 124, 124),
  1, &nl_467_scratch0_array, NULL)

/* Tensor #627 */
AI_TENSOR_OBJ_DECLARE(
  nl_480_output, AI_STATIC,
  627, 0x1,
  AI_SHAPE_INIT(4, 1, 2100, 1, 3), AI_STRIDE_INIT(4, 1, 1, 2100, 2100),
  1, &nl_480_output_array, &nl_480_output_array_intq)

/* Tensor #628 */
AI_TENSOR_OBJ_DECLARE(
  nl_50_output, AI_STATIC,
  628, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 40, 40), AI_STRIDE_INIT(4, 1, 1, 64, 2560),
  1, &nl_50_output_array, &nl_50_output_array_intq)

/* Tensor #629 */
AI_TENSOR_OBJ_DECLARE(
  nl_57_output, AI_STATIC,
  629, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 40, 40), AI_STRIDE_INIT(4, 1, 1, 64, 2560),
  1, &nl_57_output_array, &nl_57_output_array_intq)

/* Tensor #630 */
AI_TENSOR_OBJ_DECLARE(
  nl_66_output, AI_STATIC,
  630, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 40, 40), AI_STRIDE_INIT(4, 1, 1, 32, 1280),
  1, &nl_66_output_array, &nl_66_output_array_intq)

/* Tensor #631 */
AI_TENSOR_OBJ_DECLARE(
  nl_73_output, AI_STATIC,
  631, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 40, 40), AI_STRIDE_INIT(4, 1, 1, 32, 1280),
  1, &nl_73_output_array, &nl_73_output_array_intq)

/* Tensor #632 */
AI_TENSOR_OBJ_DECLARE(
  nl_81_output, AI_STATIC,
  632, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 40, 40), AI_STRIDE_INIT(4, 1, 1, 32, 1280),
  1, &nl_81_output_array, &nl_81_output_array_intq)

/* Tensor #633 */
AI_TENSOR_OBJ_DECLARE(
  nl_88_output, AI_STATIC,
  633, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 40, 40), AI_STRIDE_INIT(4, 1, 1, 32, 1280),
  1, &nl_88_output_array, &nl_88_output_array_intq)

/* Tensor #634 */
AI_TENSOR_OBJ_DECLARE(
  nl_97_output, AI_STATIC,
  634, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 40, 40), AI_STRIDE_INIT(4, 1, 1, 64, 2560),
  1, &nl_97_output_array, &nl_97_output_array_intq)

/* Tensor #635 */
AI_TENSOR_OBJ_DECLARE(
  pool_205_output, AI_STATIC,
  635, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 10, 10), AI_STRIDE_INIT(4, 1, 1, 128, 1280),
  1, &pool_205_output_array, &pool_205_output_array_intq)

/* Tensor #636 */
AI_TENSOR_OBJ_DECLARE(
  pool_206_output, AI_STATIC,
  636, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 10, 10), AI_STRIDE_INIT(4, 1, 1, 128, 1280),
  1, &pool_206_output_array, &pool_206_output_array_intq)

/* Tensor #637 */
AI_TENSOR_OBJ_DECLARE(
  pool_207_output, AI_STATIC,
  637, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 10, 10), AI_STRIDE_INIT(4, 1, 1, 128, 1280),
  1, &pool_207_output_array, &pool_207_output_array_intq)

/* Tensor #638 */
AI_TENSOR_OBJ_DECLARE(
  resize_217_output, AI_STATIC,
  638, 0x1,
  AI_SHAPE_INIT(4, 1, 256, 20, 20), AI_STRIDE_INIT(4, 1, 1, 256, 5120),
  1, &resize_217_output_array, &resize_217_output_array_intq)

/* Tensor #639 */
AI_TENSOR_OBJ_DECLARE(
  resize_251_output, AI_STATIC,
  639, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 40, 40), AI_STRIDE_INIT(4, 1, 1, 128, 5120),
  1, &resize_251_output_array, &resize_251_output_array_intq)

/* Tensor #640 */
AI_TENSOR_OBJ_DECLARE(
  serving_default_images0_output, AI_STATIC,
  640, 0x1,
  AI_SHAPE_INIT(4, 1, 3, 320, 320), AI_STRIDE_INIT(4, 1, 1, 3, 960),
  1, &serving_default_images0_output_array, &serving_default_images0_output_array_intq)

/* Tensor #641 */
AI_TENSOR_OBJ_DECLARE(
  slice_118_output, AI_STATIC,
  641, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 20, 20), AI_STRIDE_INIT(4, 1, 1, 64, 1280),
  1, &slice_118_output_array, &slice_118_output_array_intq)

/* Tensor #642 */
AI_TENSOR_OBJ_DECLARE(
  slice_119_output, AI_STATIC,
  642, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 20, 20), AI_STRIDE_INIT(4, 1, 1, 64, 1280),
  1, &slice_119_output_array, &slice_119_output_array_intq)

/* Tensor #643 */
AI_TENSOR_OBJ_DECLARE(
  slice_173_output, AI_STATIC,
  643, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 10, 10), AI_STRIDE_INIT(4, 1, 1, 128, 1280),
  1, &slice_173_output_array, &slice_173_output_array_intq)

/* Tensor #644 */
AI_TENSOR_OBJ_DECLARE(
  slice_174_output, AI_STATIC,
  644, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 10, 10), AI_STRIDE_INIT(4, 1, 1, 128, 1280),
  1, &slice_174_output_array, &slice_174_output_array_intq)

/* Tensor #645 */
AI_TENSOR_OBJ_DECLARE(
  slice_226_output, AI_STATIC,
  645, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 20, 20), AI_STRIDE_INIT(4, 1, 1, 64, 1280),
  1, &slice_226_output_array, &slice_226_output_array_intq)

/* Tensor #646 */
AI_TENSOR_OBJ_DECLARE(
  slice_227_output, AI_STATIC,
  646, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 20, 20), AI_STRIDE_INIT(4, 1, 1, 64, 1280),
  1, &slice_227_output_array, &slice_227_output_array_intq)

/* Tensor #647 */
AI_TENSOR_OBJ_DECLARE(
  slice_23_output, AI_STATIC,
  647, 0x1,
  AI_SHAPE_INIT(4, 1, 16, 80, 80), AI_STRIDE_INIT(4, 1, 1, 16, 1280),
  1, &slice_23_output_array, &slice_23_output_array_intq)

/* Tensor #648 */
AI_TENSOR_OBJ_DECLARE(
  slice_260_output, AI_STATIC,
  648, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 40, 40), AI_STRIDE_INIT(4, 1, 1, 32, 1280),
  1, &slice_260_output_array, &slice_260_output_array_intq)

/* Tensor #649 */
AI_TENSOR_OBJ_DECLARE(
  slice_261_output, AI_STATIC,
  649, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 40, 40), AI_STRIDE_INIT(4, 1, 1, 32, 1280),
  1, &slice_261_output_array, &slice_261_output_array_intq)

/* Tensor #650 */
AI_TENSOR_OBJ_DECLARE(
  slice_300_output, AI_STATIC,
  650, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 20, 20), AI_STRIDE_INIT(4, 1, 1, 64, 1280),
  1, &slice_300_output_array, &slice_300_output_array_intq)

/* Tensor #651 */
AI_TENSOR_OBJ_DECLARE(
  slice_301_output, AI_STATIC,
  651, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 20, 20), AI_STRIDE_INIT(4, 1, 1, 64, 1280),
  1, &slice_301_output_array, &slice_301_output_array_intq)

/* Tensor #652 */
AI_TENSOR_OBJ_DECLARE(
  slice_340_output, AI_STATIC,
  652, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 10, 10), AI_STRIDE_INIT(4, 1, 1, 128, 1280),
  1, &slice_340_output_array, &slice_340_output_array_intq)

/* Tensor #653 */
AI_TENSOR_OBJ_DECLARE(
  slice_341_output, AI_STATIC,
  653, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 10, 10), AI_STRIDE_INIT(4, 1, 1, 128, 1280),
  1, &slice_341_output_array, &slice_341_output_array_intq)

/* Tensor #654 */
AI_TENSOR_OBJ_DECLARE(
  slice_39_output, AI_STATIC,
  654, 0x1,
  AI_SHAPE_INIT(4, 1, 16, 80, 80), AI_STRIDE_INIT(4, 1, 1, 16, 1280),
  1, &slice_39_output_array, &slice_39_output_array_intq)

/* Tensor #655 */
AI_TENSOR_OBJ_DECLARE(
  slice_464_output, AI_STATIC,
  655, 0x1,
  AI_SHAPE_INIT(4, 1, 2100, 1, 64), AI_STRIDE_INIT(4, 1, 1, 2100, 2100),
  1, &slice_464_output_array, &slice_464_output_array_intq)

/* Tensor #656 */
AI_TENSOR_OBJ_DECLARE(
  slice_464_output0, AI_STATIC,
  656, 0x1,
  AI_SHAPE_INIT(4, 1, 2100, 16, 4), AI_STRIDE_INIT(4, 1, 1, 2100, 33600),
  1, &slice_464_output_array, &slice_464_output_array_intq)

/* Tensor #657 */
AI_TENSOR_OBJ_DECLARE(
  slice_472_output, AI_STATIC,
  657, 0x1,
  AI_SHAPE_INIT(4, 1, 2100, 1, 2), AI_STRIDE_INIT(4, 1, 1, 2100, 2100),
  1, &slice_472_output_array, &slice_472_output_array_intq)

/* Tensor #658 */
AI_TENSOR_OBJ_DECLARE(
  slice_474_output, AI_STATIC,
  658, 0x1,
  AI_SHAPE_INIT(4, 1, 2100, 1, 2), AI_STRIDE_INIT(4, 1, 1, 2100, 2100),
  1, &slice_474_output_array, &slice_474_output_array_intq)

/* Tensor #659 */
AI_TENSOR_OBJ_DECLARE(
  slice_479_output, AI_STATIC,
  659, 0x1,
  AI_SHAPE_INIT(4, 1, 2100, 1, 3), AI_STRIDE_INIT(4, 1, 1, 2100, 2100),
  1, &slice_479_output_array, &slice_479_output_array_intq)

/* Tensor #660 */
AI_TENSOR_OBJ_DECLARE(
  slice_63_output, AI_STATIC,
  660, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 40, 40), AI_STRIDE_INIT(4, 1, 1, 32, 1280),
  1, &slice_63_output_array, &slice_63_output_array_intq)

/* Tensor #661 */
AI_TENSOR_OBJ_DECLARE(
  slice_64_output, AI_STATIC,
  661, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 40, 40), AI_STRIDE_INIT(4, 1, 1, 32, 1280),
  1, &slice_64_output_array, &slice_64_output_array_intq)

/* Tensor #662 */
AI_TENSOR_OBJ_DECLARE(
  tfl_pseudo_qconst1, AI_STATIC,
  662, 0x1,
  AI_SHAPE_INIT(4, 1, 2100, 1, 2), AI_STRIDE_INIT(4, 1, 1, 2100, 2100),
  1, &tfl_pseudo_qconst1_array, &tfl_pseudo_qconst1_array_intq)

/* Tensor #663 */
AI_TENSOR_OBJ_DECLARE(
  tfl_pseudo_qconst129_4D, AI_STATIC,
  663, 0x1,
  AI_SHAPE_INIT(4, 1, 1, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1, 1),
  1, &tfl_pseudo_qconst129_4D_array, &tfl_pseudo_qconst129_4D_array_intq)

/* Tensor #664 */
AI_TENSOR_OBJ_DECLARE(
  tfl_pseudo_qconst2_4D, AI_STATIC,
  664, 0x1,
  AI_SHAPE_INIT(4, 1, 2100, 4, 1), AI_STRIDE_INIT(4, 1, 1, 2100, 8400),
  1, &tfl_pseudo_qconst2_4D_array, &tfl_pseudo_qconst2_4D_array_intq)

/* Tensor #665 */
AI_TENSOR_OBJ_DECLARE(
  tfl_pseudo_qconst_3D, AI_STATIC,
  665, 0x1,
  AI_SHAPE_INIT(4, 1, 1, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1, 1),
  1, &tfl_pseudo_qconst_3D_array, &tfl_pseudo_qconst_3D_array_intq)

/* Tensor #666 */
AI_TENSOR_OBJ_DECLARE(
  transpose_395_output, AI_STATIC,
  666, 0x1,
  AI_SHAPE_INIT(4, 1, 10, 10, 67), AI_STRIDE_INIT(4, 1, 1, 10, 100),
  1, &transpose_395_output_array, &transpose_395_output_array_intq)

/* Tensor #667 */
AI_TENSOR_OBJ_DECLARE(
  transpose_395_output0, AI_STATIC,
  667, 0x1,
  AI_SHAPE_INIT(4, 1, 100, 1, 67), AI_STRIDE_INIT(4, 1, 1, 100, 100),
  1, &transpose_395_output_array, &transpose_395_output_array_intq)

/* Tensor #668 */
AI_TENSOR_OBJ_DECLARE(
  transpose_428_output, AI_STATIC,
  668, 0x1,
  AI_SHAPE_INIT(4, 1, 20, 20, 67), AI_STRIDE_INIT(4, 1, 1, 20, 400),
  1, &transpose_428_output_array, &transpose_428_output_array_intq)

/* Tensor #669 */
AI_TENSOR_OBJ_DECLARE(
  transpose_428_output0, AI_STATIC,
  669, 0x1,
  AI_SHAPE_INIT(4, 1, 400, 1, 67), AI_STRIDE_INIT(4, 1, 1, 400, 400),
  1, &transpose_428_output_array, &transpose_428_output_array_intq)

/* Tensor #670 */
AI_TENSOR_OBJ_DECLARE(
  transpose_461_output, AI_STATIC,
  670, 0x1,
  AI_SHAPE_INIT(4, 1, 40, 40, 67), AI_STRIDE_INIT(4, 1, 1, 40, 1600),
  1, &transpose_461_output_array, &transpose_461_output_array_intq)

/* Tensor #671 */
AI_TENSOR_OBJ_DECLARE(
  transpose_461_output0, AI_STATIC,
  671, 0x1,
  AI_SHAPE_INIT(4, 1, 1600, 1, 67), AI_STRIDE_INIT(4, 1, 1, 1600, 1600),
  1, &transpose_461_output_array, &transpose_461_output_array_intq)

/* Tensor #672 */
AI_TENSOR_OBJ_DECLARE(
  transpose_466_output, AI_STATIC,
  672, 0x1,
  AI_SHAPE_INIT(4, 1, 16, 2100, 4), AI_STRIDE_INIT(4, 1, 1, 16, 33600),
  1, &transpose_466_output_array, &transpose_466_output_array_intq)



/**  Layer declarations section  **********************************************/


AI_TENSOR_CHAIN_OBJ_DECLARE(
  concat_482_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &eltwise_477_output, &eltwise_478_output, &nl_480_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &concat_482_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  concat_482_layer, 482,
  CONCAT_TYPE, 0x0, NULL,
  concat, forward_concat,
  &concat_482_chain,
  NULL, &concat_482_layer, AI_STATIC, 
  .axis = AI_SHAPE_HEIGHT, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_477_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_476_output, &tfl_pseudo_qconst_3D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_477_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_477_layer, 477,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_477_chain,
  NULL, &concat_482_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_476_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_473_output, &eltwise_475_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_476_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_476_layer, 476,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_476_chain,
  NULL, &eltwise_477_layer, AI_STATIC, 
  .operation = ai_sum_f32, 
  .buffer_operation = ai_sum_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_478_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_475_output, &eltwise_473_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_478_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_478_layer, 478,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_478_chain,
  NULL, &eltwise_476_layer, AI_STATIC, 
  .operation = ai_sub_f32, 
  .buffer_operation = ai_sub_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_473_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &tfl_pseudo_qconst1, &slice_472_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_473_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_473_layer, 473,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_473_chain,
  NULL, &eltwise_478_layer, AI_STATIC, 
  .operation = ai_sub_f32, 
  .buffer_operation = ai_sub_buffer_INT8, 
)


AI_STATIC_CONST ai_u8 slice_472_axes_data[] = { 0 };
AI_ARRAY_OBJ_DECLARE(
    slice_472_axes, AI_ARRAY_FORMAT_U8,
    slice_472_axes_data, slice_472_axes_data, 1, AI_STATIC_CONST)

AI_STATIC_CONST ai_i16 slice_472_starts_data[] = { 0 };
AI_ARRAY_OBJ_DECLARE(
    slice_472_starts, AI_ARRAY_FORMAT_S16,
    slice_472_starts_data, slice_472_starts_data, 1, AI_STATIC_CONST)

AI_STATIC_CONST ai_i16 slice_472_ends_data[] = { 2 };
AI_ARRAY_OBJ_DECLARE(
    slice_472_ends, AI_ARRAY_FORMAT_S16,
    slice_472_ends_data, slice_472_ends_data, 1, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  slice_472_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_470_output0),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &slice_472_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  slice_472_layer, 472,
  SLICE_TYPE, 0x0, NULL,
  slice, forward_slice,
  &slice_472_chain,
  NULL, &eltwise_473_layer, AI_STATIC, 
  .axes = &slice_472_axes, 
  .starts = &slice_472_starts, 
  .ends = &slice_472_ends, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_475_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &slice_474_output, &tfl_pseudo_qconst1),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_475_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_475_layer, 475,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_475_chain,
  NULL, &slice_472_layer, AI_STATIC, 
  .operation = ai_sum_f32, 
  .buffer_operation = ai_sum_buffer_INT8, 
)


AI_STATIC_CONST ai_u8 slice_474_axes_data[] = { 0 };
AI_ARRAY_OBJ_DECLARE(
    slice_474_axes, AI_ARRAY_FORMAT_U8,
    slice_474_axes_data, slice_474_axes_data, 1, AI_STATIC_CONST)

AI_STATIC_CONST ai_i16 slice_474_starts_data[] = { 2 };
AI_ARRAY_OBJ_DECLARE(
    slice_474_starts, AI_ARRAY_FORMAT_S16,
    slice_474_starts_data, slice_474_starts_data, 1, AI_STATIC_CONST)

AI_STATIC_CONST ai_i16 slice_474_ends_data[] = { 4 };
AI_ARRAY_OBJ_DECLARE(
    slice_474_ends, AI_ARRAY_FORMAT_S16,
    slice_474_ends_data, slice_474_ends_data, 1, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  slice_474_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_470_output0),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &slice_474_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  slice_474_layer, 474,
  SLICE_TYPE, 0x0, NULL,
  slice, forward_slice,
  &slice_474_chain,
  NULL, &eltwise_475_layer, AI_STATIC, 
  .axes = &slice_474_axes, 
  .starts = &slice_474_starts, 
  .ends = &slice_474_ends, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_470_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_468_output0, &tfl_pseudo_qconst2_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_470_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_470_layer, 470,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_470_chain,
  NULL, &slice_474_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_468_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_467_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_468_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_468_weights, &conv2d_468_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_468_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_468_layer, 468,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA,
  &conv2d_468_chain,
  NULL, &eltwise_470_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)


AI_STATIC_CONST ai_i32 nl_467_nl_params_data[] = { 1735480192, 26, -31 };
AI_ARRAY_OBJ_DECLARE(
    nl_467_nl_params, AI_ARRAY_FORMAT_S32,
    nl_467_nl_params_data, nl_467_nl_params_data, 3, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  nl_467_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &transpose_466_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_467_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_467_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  nl_467_layer, 467,
  SM_TYPE, 0x0, NULL,
  sm, forward_sm_integer,
  &nl_467_chain,
  NULL, &conv2d_468_layer, AI_STATIC, 
  .nl_params = &nl_467_nl_params, 
  .axis = AI_SHAPE_CHANNEL, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  transpose_466_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &slice_464_output0),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &transpose_466_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  transpose_466_layer, 466,
  TRANSPOSE_TYPE, 0x0, NULL,
  transpose, forward_transpose,
  &transpose_466_chain,
  NULL, &nl_467_layer, AI_STATIC, 
  .out_mapping = AI_SHAPE_INIT(6, AI_SHAPE_IN_CHANNEL, AI_SHAPE_WIDTH, AI_SHAPE_CHANNEL, AI_SHAPE_HEIGHT, AI_SHAPE_DEPTH, AI_SHAPE_EXTENSION), 
)


AI_STATIC_CONST ai_u8 slice_464_axes_data[] = { 0 };
AI_ARRAY_OBJ_DECLARE(
    slice_464_axes, AI_ARRAY_FORMAT_U8,
    slice_464_axes_data, slice_464_axes_data, 1, AI_STATIC_CONST)

AI_STATIC_CONST ai_i16 slice_464_starts_data[] = { 0 };
AI_ARRAY_OBJ_DECLARE(
    slice_464_starts, AI_ARRAY_FORMAT_S16,
    slice_464_starts_data, slice_464_starts_data, 1, AI_STATIC_CONST)

AI_STATIC_CONST ai_i16 slice_464_ends_data[] = { 64 };
AI_ARRAY_OBJ_DECLARE(
    slice_464_ends, AI_ARRAY_FORMAT_S16,
    slice_464_ends_data, slice_464_ends_data, 1, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  slice_464_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &concat_463_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &slice_464_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  slice_464_layer, 464,
  SLICE_TYPE, 0x0, NULL,
  slice, forward_slice,
  &slice_464_chain,
  NULL, &transpose_466_layer, AI_STATIC, 
  .axes = &slice_464_axes, 
  .starts = &slice_464_starts, 
  .ends = &slice_464_ends, 
)


AI_STATIC_CONST ai_i8 nl_480_nl_params_data[] = { -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -127, -126, -124, -118, -107, -86, -49, 0, 49, 86, 107, 118, 124, 126, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127 };
AI_ARRAY_OBJ_DECLARE(
    nl_480_nl_params, AI_ARRAY_FORMAT_S8,
    nl_480_nl_params_data, nl_480_nl_params_data, 256, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  nl_480_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &slice_479_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_480_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  nl_480_layer, 480,
  NL_TYPE, 0x0, NULL,
  nl, forward_nl_integer,
  &nl_480_chain,
  NULL, &slice_464_layer, AI_STATIC, 
  .nl_params = &nl_480_nl_params, 
)


AI_STATIC_CONST ai_u8 slice_479_axes_data[] = { 0 };
AI_ARRAY_OBJ_DECLARE(
    slice_479_axes, AI_ARRAY_FORMAT_U8,
    slice_479_axes_data, slice_479_axes_data, 1, AI_STATIC_CONST)

AI_STATIC_CONST ai_i16 slice_479_starts_data[] = { 64 };
AI_ARRAY_OBJ_DECLARE(
    slice_479_starts, AI_ARRAY_FORMAT_S16,
    slice_479_starts_data, slice_479_starts_data, 1, AI_STATIC_CONST)

AI_STATIC_CONST ai_i16 slice_479_ends_data[] = { 67 };
AI_ARRAY_OBJ_DECLARE(
    slice_479_ends, AI_ARRAY_FORMAT_S16,
    slice_479_ends_data, slice_479_ends_data, 1, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  slice_479_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &concat_463_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &slice_479_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  slice_479_layer, 479,
  SLICE_TYPE, 0x0, NULL,
  slice, forward_slice,
  &slice_479_chain,
  NULL, &nl_480_layer, AI_STATIC, 
  .axes = &slice_479_axes, 
  .starts = &slice_479_starts, 
  .ends = &slice_479_ends, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  concat_463_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &transpose_461_output0, &transpose_428_output0, &transpose_395_output0),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &concat_463_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  concat_463_layer, 463,
  CONCAT_TYPE, 0x0, NULL,
  concat, forward_concat,
  &concat_463_chain,
  NULL, &slice_479_layer, AI_STATIC, 
  .axis = AI_SHAPE_CHANNEL, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  transpose_461_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &concat_460_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &transpose_461_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  transpose_461_layer, 461,
  TRANSPOSE_TYPE, 0x0, NULL,
  transpose, forward_transpose,
  &transpose_461_chain,
  NULL, &concat_463_layer, AI_STATIC, 
  .out_mapping = AI_SHAPE_INIT(6, AI_SHAPE_IN_CHANNEL, AI_SHAPE_WIDTH, AI_SHAPE_HEIGHT, AI_SHAPE_CHANNEL, AI_SHAPE_DEPTH, AI_SHAPE_EXTENSION), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  concat_460_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_444_output, &conv2d_459_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &concat_460_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  concat_460_layer, 460,
  CONCAT_TYPE, 0x0, NULL,
  concat, forward_concat,
  &concat_460_chain,
  NULL, &transpose_461_layer, AI_STATIC, 
  .axis = AI_SHAPE_CHANNEL, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_444_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_443_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_444_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_444_weights, &conv2d_444_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_444_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_444_layer, 444,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA,
  &conv2d_444_chain,
  NULL, &concat_460_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_443_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_442_output, &eltwise_440_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_443_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_443_layer, 443,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_443_chain,
  NULL, &conv2d_444_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_440_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_439_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_440_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_440_layer, 440,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_440_chain,
  NULL, &eltwise_443_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_439_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &nl_438_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_439_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_439_layer, 439,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_439_chain,
  NULL, &eltwise_440_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)


AI_STATIC_CONST ai_i8 nl_438_nl_params_data[] = { -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -127, -127, -127, -127, -127, -126, -126, -125, -124, -123, -122, -120, -118, -115, -112, -108, -103, -97, -89, -80, -70, -58, -45, -31, -16, 0, 16, 31, 45, 58, 70, 80, 89, 97, 103, 108, 112, 115, 118, 120, 122, 123, 124, 125, 126, 126, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127 };
AI_ARRAY_OBJ_DECLARE(
    nl_438_nl_params, AI_ARRAY_FORMAT_S8,
    nl_438_nl_params_data, nl_438_nl_params_data, 256, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  nl_438_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_437_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_438_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  nl_438_layer, 438,
  NL_TYPE, 0x0, NULL,
  nl, forward_nl_integer,
  &nl_438_chain,
  NULL, &eltwise_439_layer, AI_STATIC, 
  .nl_params = &nl_438_nl_params, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_442_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_441_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_442_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_442_layer, 442,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_442_chain,
  NULL, &nl_438_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_441_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_437_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_441_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_441_layer, 441,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_441_chain,
  NULL, &eltwise_442_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_437_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_436_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_437_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_437_weights, &conv2d_437_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_437_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_437_layer, 437,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA,
  &conv2d_437_chain,
  NULL, &eltwise_441_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_SAME, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_436_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_435_output, &eltwise_433_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_436_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_436_layer, 436,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_436_chain,
  NULL, &conv2d_437_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_433_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_432_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_433_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_433_layer, 433,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_433_chain,
  NULL, &eltwise_436_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_432_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &nl_431_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_432_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_432_layer, 432,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_432_chain,
  NULL, &eltwise_433_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)


AI_STATIC_CONST ai_i8 nl_431_nl_params_data[] = { -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -127, -127, -127, -127, -127, -127, -127, -127, -126, -126, -126, -126, -125, -125, -124, -124, -123, -123, -122, -121, -120, -119, -117, -116, -114, -112, -110, -108, -105, -102, -99, -95, -91, -87, -82, -76, -70, -64, -57, -50, -42, -34, -26, -17, -9, 0, 9, 17, 26, 34, 42, 50, 57, 64, 70, 76, 82, 87, 91, 95, 99, 102, 105, 108, 110, 112, 114, 116, 117, 119, 120, 121, 122, 123, 123, 124, 124, 125, 125, 126, 126, 126, 126, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127 };
AI_ARRAY_OBJ_DECLARE(
    nl_431_nl_params, AI_ARRAY_FORMAT_S8,
    nl_431_nl_params_data, nl_431_nl_params_data, 256, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  nl_431_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_430_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_431_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  nl_431_layer, 431,
  NL_TYPE, 0x0, NULL,
  nl, forward_nl_integer,
  &nl_431_chain,
  NULL, &eltwise_432_layer, AI_STATIC, 
  .nl_params = &nl_431_nl_params, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_435_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_434_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_435_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_435_layer, 435,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_435_chain,
  NULL, &nl_431_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_434_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_430_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_434_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_434_layer, 434,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_434_chain,
  NULL, &eltwise_435_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_430_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_283_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_430_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_430_weights, &conv2d_430_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_430_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_430_layer, 430,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA,
  &conv2d_430_chain,
  NULL, &eltwise_434_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_SAME, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_459_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_458_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_459_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_459_weights, &conv2d_459_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_459_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_459_layer, 459,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA,
  &conv2d_459_chain,
  NULL, &conv2d_430_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_458_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_457_output, &eltwise_455_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_458_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_458_layer, 458,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_458_chain,
  NULL, &conv2d_459_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_455_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_454_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_455_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_455_layer, 455,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_455_chain,
  NULL, &eltwise_458_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_454_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &nl_453_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_454_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_454_layer, 454,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_454_chain,
  NULL, &eltwise_455_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)


AI_STATIC_CONST ai_i8 nl_453_nl_params_data[] = { -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -127, -127, -127, -127, -127, -127, -126, -126, -126, -125, -125, -124, -123, -122, -121, -119, -117, -115, -112, -109, -105, -101, -96, -90, -83, -76, -67, -58, -47, -36, -25, -12, 0, 12, 25, 36, 47, 58, 67, 76, 83, 90, 96, 101, 105, 109, 112, 115, 117, 119, 121, 122, 123, 124, 125, 125, 126, 126, 126, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127 };
AI_ARRAY_OBJ_DECLARE(
    nl_453_nl_params, AI_ARRAY_FORMAT_S8,
    nl_453_nl_params_data, nl_453_nl_params_data, 256, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  nl_453_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_452_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_453_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  nl_453_layer, 453,
  NL_TYPE, 0x0, NULL,
  nl, forward_nl_integer,
  &nl_453_chain,
  NULL, &eltwise_454_layer, AI_STATIC, 
  .nl_params = &nl_453_nl_params, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_457_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_456_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_457_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_457_layer, 457,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_457_chain,
  NULL, &nl_453_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_456_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_452_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_456_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_456_layer, 456,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_456_chain,
  NULL, &eltwise_457_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_452_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_451_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_452_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_452_weights, &conv2d_452_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_452_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_452_layer, 452,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA,
  &conv2d_452_chain,
  NULL, &eltwise_456_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_SAME, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_451_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_450_output, &eltwise_448_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_451_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_451_layer, 451,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_451_chain,
  NULL, &conv2d_452_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_448_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_447_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_448_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_448_layer, 448,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_448_chain,
  NULL, &eltwise_451_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_447_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &nl_446_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_447_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_447_layer, 447,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_447_chain,
  NULL, &eltwise_448_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)


AI_STATIC_CONST ai_i8 nl_446_nl_params_data[] = { -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -127, -127, -127, -127, -127, -127, -127, -127, -127, -127, -126, -126, -126, -126, -125, -125, -125, -124, -124, -124, -123, -122, -122, -121, -120, -119, -118, -117, -116, -114, -113, -111, -109, -107, -105, -102, -99, -96, -93, -89, -85, -81, -77, -72, -67, -61, -55, -49, -43, -36, -29, -22, -15, -7, 0, 7, 15, 22, 29, 36, 43, 49, 55, 61, 67, 72, 77, 81, 85, 89, 93, 96, 99, 102, 105, 107, 109, 111, 113, 114, 116, 117, 118, 119, 120, 121, 122, 122, 123, 124, 124, 124, 125, 125, 125, 126, 126, 126, 126, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127 };
AI_ARRAY_OBJ_DECLARE(
    nl_446_nl_params, AI_ARRAY_FORMAT_S8,
    nl_446_nl_params_data, nl_446_nl_params_data, 256, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  nl_446_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_445_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_446_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  nl_446_layer, 446,
  NL_TYPE, 0x0, NULL,
  nl, forward_nl_integer,
  &nl_446_chain,
  NULL, &eltwise_447_layer, AI_STATIC, 
  .nl_params = &nl_446_nl_params, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_450_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_449_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_450_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_450_layer, 450,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_450_chain,
  NULL, &nl_446_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_449_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_445_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_449_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_449_layer, 449,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_449_chain,
  NULL, &eltwise_450_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_445_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_283_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_445_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_445_weights, &conv2d_445_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_445_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_445_layer, 445,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA,
  &conv2d_445_chain,
  NULL, &eltwise_449_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_SAME, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  transpose_428_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &concat_427_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &transpose_428_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  transpose_428_layer, 428,
  TRANSPOSE_TYPE, 0x0, NULL,
  transpose, forward_transpose,
  &transpose_428_chain,
  NULL, &conv2d_445_layer, AI_STATIC, 
  .out_mapping = AI_SHAPE_INIT(6, AI_SHAPE_IN_CHANNEL, AI_SHAPE_WIDTH, AI_SHAPE_HEIGHT, AI_SHAPE_CHANNEL, AI_SHAPE_DEPTH, AI_SHAPE_EXTENSION), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  concat_427_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_411_output, &conv2d_426_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &concat_427_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  concat_427_layer, 427,
  CONCAT_TYPE, 0x0, NULL,
  concat, forward_concat,
  &concat_427_chain,
  NULL, &transpose_428_layer, AI_STATIC, 
  .axis = AI_SHAPE_CHANNEL, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_411_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_410_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_411_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_411_weights, &conv2d_411_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_411_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_411_layer, 411,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA,
  &conv2d_411_chain,
  NULL, &concat_427_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_410_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_409_output, &eltwise_407_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_410_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_410_layer, 410,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_410_chain,
  NULL, &conv2d_411_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_407_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_406_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_407_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_407_layer, 407,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_407_chain,
  NULL, &eltwise_410_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_406_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &nl_405_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_406_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_406_layer, 406,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_406_chain,
  NULL, &eltwise_407_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)


AI_STATIC_CONST ai_i8 nl_405_nl_params_data[] = { -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -127, -127, -127, -126, -126, -125, -124, -122, -119, -116, -112, -106, -98, -88, -75, -59, -41, -21, 0, 21, 41, 59, 75, 88, 98, 106, 112, 116, 119, 122, 124, 125, 126, 126, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127 };
AI_ARRAY_OBJ_DECLARE(
    nl_405_nl_params, AI_ARRAY_FORMAT_S8,
    nl_405_nl_params_data, nl_405_nl_params_data, 256, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  nl_405_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_404_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_405_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  nl_405_layer, 405,
  NL_TYPE, 0x0, NULL,
  nl, forward_nl_integer,
  &nl_405_chain,
  NULL, &eltwise_406_layer, AI_STATIC, 
  .nl_params = &nl_405_nl_params, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_409_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_408_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_409_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_409_layer, 409,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_409_chain,
  NULL, &nl_405_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_408_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_404_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_408_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_408_layer, 408,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_408_chain,
  NULL, &eltwise_409_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_404_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_403_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_404_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_404_weights, &conv2d_404_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_404_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_404_layer, 404,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA,
  &conv2d_404_chain,
  NULL, &eltwise_408_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_SAME, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_403_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_402_output, &eltwise_400_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_403_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_403_layer, 403,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_403_chain,
  NULL, &conv2d_404_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_400_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_399_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_400_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_400_layer, 400,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_400_chain,
  NULL, &eltwise_403_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_399_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &nl_398_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_399_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_399_layer, 399,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_399_chain,
  NULL, &eltwise_400_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)


AI_STATIC_CONST ai_i8 nl_398_nl_params_data[] = { -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -127, -127, -127, -127, -127, -127, -126, -126, -126, -125, -125, -124, -123, -122, -121, -120, -118, -117, -114, -112, -109, -106, -102, -97, -92, -86, -79, -72, -63, -54, -44, -34, -23, -12, 0, 12, 23, 34, 44, 54, 63, 72, 79, 86, 92, 97, 102, 106, 109, 112, 114, 117, 118, 120, 121, 122, 123, 124, 125, 125, 126, 126, 126, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127 };
AI_ARRAY_OBJ_DECLARE(
    nl_398_nl_params, AI_ARRAY_FORMAT_S8,
    nl_398_nl_params_data, nl_398_nl_params_data, 256, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  nl_398_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_397_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_398_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  nl_398_layer, 398,
  NL_TYPE, 0x0, NULL,
  nl, forward_nl_integer,
  &nl_398_chain,
  NULL, &eltwise_399_layer, AI_STATIC, 
  .nl_params = &nl_398_nl_params, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_402_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_401_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_402_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_402_layer, 402,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_402_chain,
  NULL, &nl_398_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_401_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_397_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_401_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_401_layer, 401,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_401_chain,
  NULL, &eltwise_402_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_397_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_323_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_397_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_397_weights, &conv2d_397_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_397_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_397_layer, 397,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA,
  &conv2d_397_chain,
  NULL, &eltwise_401_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_SAME, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_426_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_425_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_426_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_426_weights, &conv2d_426_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_426_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_426_layer, 426,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA,
  &conv2d_426_chain,
  NULL, &conv2d_397_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_425_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_424_output, &eltwise_422_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_425_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_425_layer, 425,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_425_chain,
  NULL, &conv2d_426_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_422_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_421_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_422_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_422_layer, 422,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_422_chain,
  NULL, &eltwise_425_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_421_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &nl_420_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_421_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_421_layer, 421,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_421_chain,
  NULL, &eltwise_422_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)


AI_STATIC_CONST ai_i8 nl_420_nl_params_data[] = { -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -127, -127, -127, -127, -126, -126, -125, -125, -123, -122, -120, -118, -115, -111, -107, -101, -94, -85, -75, -63, -49, -33, -17, 0, 17, 33, 49, 63, 75, 85, 94, 101, 107, 111, 115, 118, 120, 122, 123, 125, 125, 126, 126, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127 };
AI_ARRAY_OBJ_DECLARE(
    nl_420_nl_params, AI_ARRAY_FORMAT_S8,
    nl_420_nl_params_data, nl_420_nl_params_data, 256, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  nl_420_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_419_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_420_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  nl_420_layer, 420,
  NL_TYPE, 0x0, NULL,
  nl, forward_nl_integer,
  &nl_420_chain,
  NULL, &eltwise_421_layer, AI_STATIC, 
  .nl_params = &nl_420_nl_params, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_424_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_423_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_424_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_424_layer, 424,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_424_chain,
  NULL, &nl_420_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_423_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_419_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_423_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_423_layer, 423,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_423_chain,
  NULL, &eltwise_424_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_419_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_418_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_419_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_419_weights, &conv2d_419_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_419_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_419_layer, 419,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA,
  &conv2d_419_chain,
  NULL, &eltwise_423_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_SAME, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_418_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_417_output, &eltwise_415_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_418_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_418_layer, 418,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_418_chain,
  NULL, &conv2d_419_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_415_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_414_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_415_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_415_layer, 415,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_415_chain,
  NULL, &eltwise_418_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_414_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &nl_413_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_414_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_414_layer, 414,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_414_chain,
  NULL, &eltwise_415_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)


AI_STATIC_CONST ai_i8 nl_413_nl_params_data[] = { -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -127, -127, -127, -127, -127, -127, -127, -126, -126, -126, -126, -125, -125, -124, -123, -123, -122, -121, -120, -118, -117, -115, -113, -111, -108, -105, -102, -98, -93, -88, -83, -77, -70, -63, -55, -47, -38, -29, -20, -10, 0, 10, 20, 29, 38, 47, 55, 63, 70, 77, 83, 88, 93, 98, 102, 105, 108, 111, 113, 115, 117, 118, 120, 121, 122, 123, 123, 124, 125, 125, 126, 126, 126, 126, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127 };
AI_ARRAY_OBJ_DECLARE(
    nl_413_nl_params, AI_ARRAY_FORMAT_S8,
    nl_413_nl_params_data, nl_413_nl_params_data, 256, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  nl_413_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_412_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_413_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  nl_413_layer, 413,
  NL_TYPE, 0x0, NULL,
  nl, forward_nl_integer,
  &nl_413_chain,
  NULL, &eltwise_414_layer, AI_STATIC, 
  .nl_params = &nl_413_nl_params, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_417_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_416_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_417_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_417_layer, 417,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_417_chain,
  NULL, &nl_413_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_416_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_412_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_416_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_416_layer, 416,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_416_chain,
  NULL, &eltwise_417_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_412_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_323_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_412_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_412_weights, &conv2d_412_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_412_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_412_layer, 412,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA,
  &conv2d_412_chain,
  NULL, &eltwise_416_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_SAME, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  transpose_395_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &concat_394_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &transpose_395_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  transpose_395_layer, 395,
  TRANSPOSE_TYPE, 0x0, NULL,
  transpose, forward_transpose,
  &transpose_395_chain,
  NULL, &conv2d_412_layer, AI_STATIC, 
  .out_mapping = AI_SHAPE_INIT(6, AI_SHAPE_IN_CHANNEL, AI_SHAPE_WIDTH, AI_SHAPE_HEIGHT, AI_SHAPE_CHANNEL, AI_SHAPE_DEPTH, AI_SHAPE_EXTENSION), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  concat_394_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_378_output, &conv2d_393_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &concat_394_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  concat_394_layer, 394,
  CONCAT_TYPE, 0x0, NULL,
  concat, forward_concat,
  &concat_394_chain,
  NULL, &transpose_395_layer, AI_STATIC, 
  .axis = AI_SHAPE_CHANNEL, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_378_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_377_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_378_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_378_weights, &conv2d_378_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_378_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_378_layer, 378,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA,
  &conv2d_378_chain,
  NULL, &concat_394_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_377_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_376_output, &eltwise_374_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_377_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_377_layer, 377,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_377_chain,
  NULL, &conv2d_378_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_374_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_373_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_374_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_374_layer, 374,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_374_chain,
  NULL, &eltwise_377_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_373_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &nl_372_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_373_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_373_layer, 373,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_373_chain,
  NULL, &eltwise_374_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)


AI_STATIC_CONST ai_i8 nl_372_nl_params_data[] = { -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -127, -127, -126, -125, -123, -120, -115, -108, -97, -80, -58, -31, 0, 31, 58, 80, 97, 108, 115, 120, 123, 125, 126, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127 };
AI_ARRAY_OBJ_DECLARE(
    nl_372_nl_params, AI_ARRAY_FORMAT_S8,
    nl_372_nl_params_data, nl_372_nl_params_data, 256, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  nl_372_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_371_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_372_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  nl_372_layer, 372,
  NL_TYPE, 0x0, NULL,
  nl, forward_nl_integer,
  &nl_372_chain,
  NULL, &eltwise_373_layer, AI_STATIC, 
  .nl_params = &nl_372_nl_params, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_376_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_375_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_376_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_376_layer, 376,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_376_chain,
  NULL, &nl_372_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_375_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_371_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_375_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_375_layer, 375,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_375_chain,
  NULL, &eltwise_376_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_371_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_370_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_371_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_371_weights, &conv2d_371_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_371_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_371_layer, 371,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA,
  &conv2d_371_chain,
  NULL, &eltwise_375_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_SAME, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_370_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_369_output, &eltwise_367_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_370_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_370_layer, 370,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_370_chain,
  NULL, &conv2d_371_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_367_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_366_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_367_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_367_layer, 367,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_367_chain,
  NULL, &eltwise_370_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_366_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &nl_365_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_366_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_366_layer, 366,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_366_chain,
  NULL, &eltwise_367_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)


AI_STATIC_CONST ai_i8 nl_365_nl_params_data[] = { -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -127, -127, -127, -127, -126, -126, -125, -125, -124, -122, -121, -119, -116, -113, -109, -104, -98, -91, -82, -71, -60, -46, -32, -16, 0, 16, 32, 46, 60, 71, 82, 91, 98, 104, 109, 113, 116, 119, 121, 122, 124, 125, 125, 126, 126, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127 };
AI_ARRAY_OBJ_DECLARE(
    nl_365_nl_params, AI_ARRAY_FORMAT_S8,
    nl_365_nl_params_data, nl_365_nl_params_data, 256, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  nl_365_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_364_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_365_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  nl_365_layer, 365,
  NL_TYPE, 0x0, NULL,
  nl, forward_nl_integer,
  &nl_365_chain,
  NULL, &eltwise_366_layer, AI_STATIC, 
  .nl_params = &nl_365_nl_params, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_369_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_368_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_369_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_369_layer, 369,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_369_chain,
  NULL, &nl_365_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_368_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_364_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_368_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_368_layer, 368,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_368_chain,
  NULL, &eltwise_369_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_364_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_363_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_364_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_364_weights, &conv2d_364_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_364_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_364_layer, 364,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA,
  &conv2d_364_chain,
  NULL, &eltwise_368_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_SAME, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_393_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_392_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_393_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_393_weights, &conv2d_393_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_393_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_393_layer, 393,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA,
  &conv2d_393_chain,
  NULL, &conv2d_364_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_392_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_391_output, &eltwise_389_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_392_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_392_layer, 392,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_392_chain,
  NULL, &conv2d_393_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_389_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_388_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_389_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_389_layer, 389,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_389_chain,
  NULL, &eltwise_392_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_388_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &nl_387_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_388_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_388_layer, 388,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_388_chain,
  NULL, &eltwise_389_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)


AI_STATIC_CONST ai_i8 nl_387_nl_params_data[] = { -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -127, -127, -127, -127, -127, -127, -127, -126, -126, -126, -125, -125, -124, -124, -123, -122, -121, -119, -118, -116, -114, -112, -109, -106, -102, -98, -93, -88, -82, -75, -68, -60, -51, -42, -32, -21, -11, 0, 11, 21, 32, 42, 51, 60, 68, 75, 82, 88, 93, 98, 102, 106, 109, 112, 114, 116, 118, 119, 121, 122, 123, 124, 124, 125, 125, 126, 126, 126, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127 };
AI_ARRAY_OBJ_DECLARE(
    nl_387_nl_params, AI_ARRAY_FORMAT_S8,
    nl_387_nl_params_data, nl_387_nl_params_data, 256, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  nl_387_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_386_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_387_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  nl_387_layer, 387,
  NL_TYPE, 0x0, NULL,
  nl, forward_nl_integer,
  &nl_387_chain,
  NULL, &eltwise_388_layer, AI_STATIC, 
  .nl_params = &nl_387_nl_params, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_391_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_390_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_391_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_391_layer, 391,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_391_chain,
  NULL, &nl_387_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_390_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_386_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_390_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_390_layer, 390,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_390_chain,
  NULL, &eltwise_391_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_386_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_385_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_386_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_386_weights, &conv2d_386_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_386_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_386_layer, 386,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA,
  &conv2d_386_chain,
  NULL, &eltwise_390_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_SAME, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_385_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_384_output, &eltwise_382_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_385_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_385_layer, 385,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_385_chain,
  NULL, &conv2d_386_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_382_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_381_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_382_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_382_layer, 382,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_382_chain,
  NULL, &eltwise_385_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_381_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &nl_380_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_381_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_381_layer, 381,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_381_chain,
  NULL, &eltwise_382_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)


AI_STATIC_CONST ai_i8 nl_380_nl_params_data[] = { -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -127, -127, -127, -127, -127, -127, -127, -127, -126, -126, -126, -126, -125, -125, -124, -124, -123, -123, -122, -121, -120, -119, -118, -116, -115, -113, -111, -108, -106, -103, -99, -95, -91, -87, -82, -76, -71, -64, -57, -50, -42, -34, -26, -18, -9, 0, 9, 18, 26, 34, 42, 50, 57, 64, 71, 76, 82, 87, 91, 95, 99, 103, 106, 108, 111, 113, 115, 116, 118, 119, 120, 121, 122, 123, 123, 124, 124, 125, 125, 126, 126, 126, 126, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127 };
AI_ARRAY_OBJ_DECLARE(
    nl_380_nl_params, AI_ARRAY_FORMAT_S8,
    nl_380_nl_params_data, nl_380_nl_params_data, 256, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  nl_380_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_379_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_380_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  nl_380_layer, 380,
  NL_TYPE, 0x0, NULL,
  nl, forward_nl_integer,
  &nl_380_chain,
  NULL, &eltwise_381_layer, AI_STATIC, 
  .nl_params = &nl_380_nl_params, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_384_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_383_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_384_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_384_layer, 384,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_384_chain,
  NULL, &nl_380_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_383_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_379_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_383_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_383_layer, 383,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_383_chain,
  NULL, &eltwise_384_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_379_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_363_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_379_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_379_weights, &conv2d_379_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_379_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_379_layer, 379,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA,
  &conv2d_379_chain,
  NULL, &eltwise_383_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_SAME, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_363_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_362_output, &eltwise_360_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_363_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_363_layer, 363,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_363_chain,
  NULL, &conv2d_379_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_360_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_359_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_360_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_360_layer, 360,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_360_chain,
  NULL, &eltwise_363_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_359_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &nl_358_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_359_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_359_layer, 359,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_359_chain,
  NULL, &eltwise_360_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)


AI_STATIC_CONST ai_i8 nl_358_nl_params_data[] = { -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -127, -127, -127, -127, -127, -127, -126, -126, -125, -125, -124, -123, -122, -121, -119, -118, -116, -113, -110, -106, -102, -97, -91, -84, -77, -68, -59, -48, -37, -25, -13, 0, 13, 25, 37, 48, 59, 68, 77, 84, 91, 97, 102, 106, 110, 113, 116, 118, 119, 121, 122, 123, 124, 125, 125, 126, 126, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127 };
AI_ARRAY_OBJ_DECLARE(
    nl_358_nl_params, AI_ARRAY_FORMAT_S8,
    nl_358_nl_params_data, nl_358_nl_params_data, 256, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  nl_358_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_357_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_358_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  nl_358_layer, 358,
  NL_TYPE, 0x0, NULL,
  nl, forward_nl_integer,
  &nl_358_chain,
  NULL, &eltwise_359_layer, AI_STATIC, 
  .nl_params = &nl_358_nl_params, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_362_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_361_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_362_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_362_layer, 362,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_362_chain,
  NULL, &nl_358_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_361_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_357_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_361_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_361_layer, 361,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_361_chain,
  NULL, &eltwise_362_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_357_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &concat_356_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_357_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_357_weights, &conv2d_357_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_357_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_357_layer, 357,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA,
  &conv2d_357_chain,
  NULL, &eltwise_361_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  concat_356_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &slice_340_output, &slice_341_output, &eltwise_355_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &concat_356_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  concat_356_layer, 356,
  CONCAT_TYPE, 0x0, NULL,
  concat, forward_concat,
  &concat_356_chain,
  NULL, &conv2d_357_layer, AI_STATIC, 
  .axis = AI_SHAPE_CHANNEL, 
)


AI_STATIC_CONST ai_u8 slice_340_axes_data[] = { 2 };
AI_ARRAY_OBJ_DECLARE(
    slice_340_axes, AI_ARRAY_FORMAT_U8,
    slice_340_axes_data, slice_340_axes_data, 1, AI_STATIC_CONST)

AI_STATIC_CONST ai_i16 slice_340_starts_data[] = { 0 };
AI_ARRAY_OBJ_DECLARE(
    slice_340_starts, AI_ARRAY_FORMAT_S16,
    slice_340_starts_data, slice_340_starts_data, 1, AI_STATIC_CONST)

AI_STATIC_CONST ai_i16 slice_340_ends_data[] = { 128 };
AI_ARRAY_OBJ_DECLARE(
    slice_340_ends, AI_ARRAY_FORMAT_S16,
    slice_340_ends_data, slice_340_ends_data, 1, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  slice_340_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_339_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &slice_340_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  slice_340_layer, 340,
  SLICE_TYPE, 0x0, NULL,
  slice, forward_slice,
  &slice_340_chain,
  NULL, &concat_356_layer, AI_STATIC, 
  .axes = &slice_340_axes, 
  .starts = &slice_340_starts, 
  .ends = &slice_340_ends, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_355_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_354_output, &eltwise_352_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_355_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_355_layer, 355,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_355_chain,
  NULL, &slice_340_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_352_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_351_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_352_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_352_layer, 352,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_352_chain,
  NULL, &eltwise_355_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_351_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &nl_350_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_351_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_351_layer, 351,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_351_chain,
  NULL, &eltwise_352_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)


AI_STATIC_CONST ai_i8 nl_350_nl_params_data[] = { -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -127, -127, -127, -127, -127, -127, -126, -126, -126, -125, -125, -124, -124, -123, -122, -121, -120, -118, -116, -114, -112, -109, -106, -103, -98, -94, -88, -82, -76, -68, -60, -51, -42, -32, -21, -11, 0, 11, 21, 32, 42, 51, 60, 68, 76, 82, 88, 94, 98, 103, 106, 109, 112, 114, 116, 118, 120, 121, 122, 123, 124, 124, 125, 125, 126, 126, 126, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127 };
AI_ARRAY_OBJ_DECLARE(
    nl_350_nl_params, AI_ARRAY_FORMAT_S8,
    nl_350_nl_params_data, nl_350_nl_params_data, 256, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  nl_350_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_349_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_350_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  nl_350_layer, 350,
  NL_TYPE, 0x0, NULL,
  nl, forward_nl_integer,
  &nl_350_chain,
  NULL, &eltwise_351_layer, AI_STATIC, 
  .nl_params = &nl_350_nl_params, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_354_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_353_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_354_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_354_layer, 354,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_354_chain,
  NULL, &nl_350_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_353_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_349_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_353_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_353_layer, 353,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_353_chain,
  NULL, &eltwise_354_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_349_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_348_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_349_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_349_weights, &conv2d_349_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_349_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_349_layer, 349,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA,
  &conv2d_349_chain,
  NULL, &eltwise_353_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_SAME, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_348_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_347_output, &eltwise_345_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_348_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_348_layer, 348,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_348_chain,
  NULL, &conv2d_349_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_345_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_344_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_345_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_345_layer, 345,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_345_chain,
  NULL, &eltwise_348_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_344_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &nl_343_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_344_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_344_layer, 344,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_344_chain,
  NULL, &eltwise_345_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)


AI_STATIC_CONST ai_i8 nl_343_nl_params_data[] = { -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -127, -127, -127, -127, -127, -127, -127, -127, -127, -127, -126, -126, -126, -126, -125, -125, -125, -124, -124, -123, -123, -122, -121, -121, -120, -119, -118, -116, -115, -113, -112, -110, -108, -106, -103, -100, -97, -94, -90, -86, -82, -78, -73, -67, -62, -56, -50, -43, -36, -29, -22, -15, -7, 0, 7, 15, 22, 29, 36, 43, 50, 56, 62, 67, 73, 78, 82, 86, 90, 94, 97, 100, 103, 106, 108, 110, 112, 113, 115, 116, 118, 119, 120, 121, 121, 122, 123, 123, 124, 124, 125, 125, 125, 126, 126, 126, 126, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127 };
AI_ARRAY_OBJ_DECLARE(
    nl_343_nl_params, AI_ARRAY_FORMAT_S8,
    nl_343_nl_params_data, nl_343_nl_params_data, 256, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  nl_343_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_342_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_343_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  nl_343_layer, 343,
  NL_TYPE, 0x0, NULL,
  nl, forward_nl_integer,
  &nl_343_chain,
  NULL, &eltwise_344_layer, AI_STATIC, 
  .nl_params = &nl_343_nl_params, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_347_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_346_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_347_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_347_layer, 347,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_347_chain,
  NULL, &nl_343_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_346_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_342_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_346_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_346_layer, 346,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_346_chain,
  NULL, &eltwise_347_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_342_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &slice_341_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_342_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_342_weights, &conv2d_342_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_342_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_342_layer, 342,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA,
  &conv2d_342_chain,
  NULL, &eltwise_346_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_SAME, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)


AI_STATIC_CONST ai_u8 slice_341_axes_data[] = { 2 };
AI_ARRAY_OBJ_DECLARE(
    slice_341_axes, AI_ARRAY_FORMAT_U8,
    slice_341_axes_data, slice_341_axes_data, 1, AI_STATIC_CONST)

AI_STATIC_CONST ai_i16 slice_341_starts_data[] = { 128 };
AI_ARRAY_OBJ_DECLARE(
    slice_341_starts, AI_ARRAY_FORMAT_S16,
    slice_341_starts_data, slice_341_starts_data, 1, AI_STATIC_CONST)

AI_STATIC_CONST ai_i16 slice_341_ends_data[] = { 256 };
AI_ARRAY_OBJ_DECLARE(
    slice_341_ends, AI_ARRAY_FORMAT_S16,
    slice_341_ends_data, slice_341_ends_data, 1, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  slice_341_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_339_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &slice_341_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  slice_341_layer, 341,
  SLICE_TYPE, 0x0, NULL,
  slice, forward_slice,
  &slice_341_chain,
  NULL, &conv2d_342_layer, AI_STATIC, 
  .axes = &slice_341_axes, 
  .starts = &slice_341_starts, 
  .ends = &slice_341_ends, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_339_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_338_output, &eltwise_336_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_339_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_339_layer, 339,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_339_chain,
  NULL, &slice_341_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_336_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_335_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_336_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_336_layer, 336,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_336_chain,
  NULL, &eltwise_339_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_335_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &nl_334_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_335_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_335_layer, 335,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_335_chain,
  NULL, &eltwise_336_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)


AI_STATIC_CONST ai_i8 nl_334_nl_params_data[] = { -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -127, -127, -127, -127, -127, -127, -127, -126, -126, -126, -125, -125, -124, -123, -122, -121, -120, -119, -117, -116, -114, -111, -108, -105, -101, -97, -92, -87, -81, -74, -67, -59, -50, -41, -31, -21, -11, 0, 11, 21, 31, 41, 50, 59, 67, 74, 81, 87, 92, 97, 101, 105, 108, 111, 114, 116, 117, 119, 120, 121, 122, 123, 124, 125, 125, 126, 126, 126, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127 };
AI_ARRAY_OBJ_DECLARE(
    nl_334_nl_params, AI_ARRAY_FORMAT_S8,
    nl_334_nl_params_data, nl_334_nl_params_data, 256, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  nl_334_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_333_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_334_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  nl_334_layer, 334,
  NL_TYPE, 0x0, NULL,
  nl, forward_nl_integer,
  &nl_334_chain,
  NULL, &eltwise_335_layer, AI_STATIC, 
  .nl_params = &nl_334_nl_params, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_338_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_337_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_338_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_338_layer, 338,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_338_chain,
  NULL, &nl_334_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_337_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_333_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_337_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_337_layer, 337,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_337_chain,
  NULL, &eltwise_338_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_333_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &concat_332_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_333_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_333_weights, &conv2d_333_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_333_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_333_layer, 333,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA,
  &conv2d_333_chain,
  NULL, &eltwise_337_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  concat_332_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_331_output, &eltwise_215_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &concat_332_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  concat_332_layer, 332,
  CONCAT_TYPE, 0x0, NULL,
  concat, forward_concat,
  &concat_332_chain,
  NULL, &conv2d_333_layer, AI_STATIC, 
  .axis = AI_SHAPE_CHANNEL, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_331_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_330_output, &eltwise_328_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_331_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_331_layer, 331,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_331_chain,
  NULL, &concat_332_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_328_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_327_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_328_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_328_layer, 328,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_328_chain,
  NULL, &eltwise_331_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_327_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &nl_326_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_327_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_327_layer, 327,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_327_chain,
  NULL, &eltwise_328_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)


AI_STATIC_CONST ai_i8 nl_326_nl_params_data[] = { -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -127, -127, -127, -127, -127, -127, -127, -127, -127, -127, -126, -126, -126, -126, -125, -125, -125, -124, -124, -123, -123, -122, -121, -121, -120, -119, -118, -116, -115, -113, -112, -110, -108, -105, -103, -100, -97, -94, -90, -86, -82, -77, -73, -67, -62, -56, -50, -43, -36, -29, -22, -15, -7, 0, 7, 15, 22, 29, 36, 43, 50, 56, 62, 67, 73, 77, 82, 86, 90, 94, 97, 100, 103, 105, 108, 110, 112, 113, 115, 116, 118, 119, 120, 121, 121, 122, 123, 123, 124, 124, 125, 125, 125, 126, 126, 126, 126, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127 };
AI_ARRAY_OBJ_DECLARE(
    nl_326_nl_params, AI_ARRAY_FORMAT_S8,
    nl_326_nl_params_data, nl_326_nl_params_data, 256, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  nl_326_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_325_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_326_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  nl_326_layer, 326,
  NL_TYPE, 0x0, NULL,
  nl, forward_nl_integer,
  &nl_326_chain,
  NULL, &eltwise_327_layer, AI_STATIC, 
  .nl_params = &nl_326_nl_params, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_330_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_329_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_330_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_330_layer, 330,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_330_chain,
  NULL, &nl_326_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_329_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_325_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_329_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_329_layer, 329,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_329_chain,
  NULL, &eltwise_330_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_325_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_323_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_325_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_325_weights, &conv2d_325_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_325_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_325_layer, 324,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA,
  &conv2d_325_chain,
  NULL, &eltwise_329_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(2, 2), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_SAME, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_323_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_322_output, &eltwise_320_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_323_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_323_layer, 323,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_323_chain,
  NULL, &conv2d_325_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_320_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_319_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_320_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_320_layer, 320,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_320_chain,
  NULL, &eltwise_323_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_319_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &nl_318_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_319_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_319_layer, 319,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_319_chain,
  NULL, &eltwise_320_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)


AI_STATIC_CONST ai_i8 nl_318_nl_params_data[] = { -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -127, -127, -127, -127, -127, -127, -127, -126, -126, -126, -125, -125, -124, -123, -123, -122, -121, -119, -118, -116, -115, -112, -110, -107, -104, -100, -95, -91, -85, -79, -72, -65, -57, -49, -40, -30, -20, -10, 0, 10, 20, 30, 40, 49, 57, 65, 72, 79, 85, 91, 95, 100, 104, 107, 110, 112, 115, 116, 118, 119, 121, 122, 123, 123, 124, 125, 125, 126, 126, 126, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127 };
AI_ARRAY_OBJ_DECLARE(
    nl_318_nl_params, AI_ARRAY_FORMAT_S8,
    nl_318_nl_params_data, nl_318_nl_params_data, 256, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  nl_318_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_317_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_318_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  nl_318_layer, 318,
  NL_TYPE, 0x0, NULL,
  nl, forward_nl_integer,
  &nl_318_chain,
  NULL, &eltwise_319_layer, AI_STATIC, 
  .nl_params = &nl_318_nl_params, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_322_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_321_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_322_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_322_layer, 322,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_322_chain,
  NULL, &nl_318_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_321_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_317_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_321_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_321_layer, 321,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_321_chain,
  NULL, &eltwise_322_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_317_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &concat_316_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_317_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_317_weights, &conv2d_317_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_317_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_317_layer, 317,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA,
  &conv2d_317_chain,
  NULL, &eltwise_321_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  concat_316_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &slice_300_output, &slice_301_output, &eltwise_315_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &concat_316_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  concat_316_layer, 316,
  CONCAT_TYPE, 0x0, NULL,
  concat, forward_concat,
  &concat_316_chain,
  NULL, &conv2d_317_layer, AI_STATIC, 
  .axis = AI_SHAPE_CHANNEL, 
)


AI_STATIC_CONST ai_u8 slice_300_axes_data[] = { 2 };
AI_ARRAY_OBJ_DECLARE(
    slice_300_axes, AI_ARRAY_FORMAT_U8,
    slice_300_axes_data, slice_300_axes_data, 1, AI_STATIC_CONST)

AI_STATIC_CONST ai_i16 slice_300_starts_data[] = { 0 };
AI_ARRAY_OBJ_DECLARE(
    slice_300_starts, AI_ARRAY_FORMAT_S16,
    slice_300_starts_data, slice_300_starts_data, 1, AI_STATIC_CONST)

AI_STATIC_CONST ai_i16 slice_300_ends_data[] = { 64 };
AI_ARRAY_OBJ_DECLARE(
    slice_300_ends, AI_ARRAY_FORMAT_S16,
    slice_300_ends_data, slice_300_ends_data, 1, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  slice_300_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_299_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &slice_300_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  slice_300_layer, 300,
  SLICE_TYPE, 0x0, NULL,
  slice, forward_slice,
  &slice_300_chain,
  NULL, &concat_316_layer, AI_STATIC, 
  .axes = &slice_300_axes, 
  .starts = &slice_300_starts, 
  .ends = &slice_300_ends, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_315_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_314_output, &eltwise_312_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_315_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_315_layer, 315,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_315_chain,
  NULL, &slice_300_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_312_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_311_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_312_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_312_layer, 312,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_312_chain,
  NULL, &eltwise_315_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_311_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &nl_310_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_311_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_311_layer, 311,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_311_chain,
  NULL, &eltwise_312_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)


AI_STATIC_CONST ai_i8 nl_310_nl_params_data[] = { -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -127, -127, -127, -127, -127, -127, -126, -126, -126, -125, -125, -125, -124, -123, -122, -121, -120, -119, -117, -115, -113, -111, -108, -105, -101, -97, -92, -87, -81, -74, -67, -59, -50, -41, -31, -21, -11, 0, 11, 21, 31, 41, 50, 59, 67, 74, 81, 87, 92, 97, 101, 105, 108, 111, 113, 115, 117, 119, 120, 121, 122, 123, 124, 125, 125, 125, 126, 126, 126, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127 };
AI_ARRAY_OBJ_DECLARE(
    nl_310_nl_params, AI_ARRAY_FORMAT_S8,
    nl_310_nl_params_data, nl_310_nl_params_data, 256, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  nl_310_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_309_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_310_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  nl_310_layer, 310,
  NL_TYPE, 0x0, NULL,
  nl, forward_nl_integer,
  &nl_310_chain,
  NULL, &eltwise_311_layer, AI_STATIC, 
  .nl_params = &nl_310_nl_params, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_314_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_313_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_314_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_314_layer, 314,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_314_chain,
  NULL, &nl_310_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_313_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_309_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_313_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_313_layer, 313,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_313_chain,
  NULL, &eltwise_314_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_309_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_308_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_309_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_309_weights, &conv2d_309_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_309_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_309_layer, 309,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA,
  &conv2d_309_chain,
  NULL, &eltwise_313_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_SAME, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_308_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_307_output, &eltwise_305_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_308_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_308_layer, 308,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_308_chain,
  NULL, &conv2d_309_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_305_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_304_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_305_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_305_layer, 305,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_305_chain,
  NULL, &eltwise_308_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_304_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &nl_303_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_304_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_304_layer, 304,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_304_chain,
  NULL, &eltwise_305_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)


AI_STATIC_CONST ai_i8 nl_303_nl_params_data[] = { -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -127, -127, -127, -127, -127, -127, -127, -127, -127, -127, -127, -126, -126, -126, -126, -126, -125, -125, -125, -124, -124, -123, -123, -122, -122, -121, -121, -120, -119, -118, -117, -116, -114, -113, -112, -110, -108, -106, -104, -102, -99, -96, -93, -90, -87, -83, -79, -75, -70, -66, -61, -55, -50, -44, -38, -32, -26, -20, -13, -7, 0, 7, 13, 20, 26, 32, 38, 44, 50, 55, 61, 66, 70, 75, 79, 83, 87, 90, 93, 96, 99, 102, 104, 106, 108, 110, 112, 113, 114, 116, 117, 118, 119, 120, 121, 121, 122, 122, 123, 123, 124, 124, 125, 125, 125, 126, 126, 126, 126, 126, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127 };
AI_ARRAY_OBJ_DECLARE(
    nl_303_nl_params, AI_ARRAY_FORMAT_S8,
    nl_303_nl_params_data, nl_303_nl_params_data, 256, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  nl_303_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_302_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_303_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  nl_303_layer, 303,
  NL_TYPE, 0x0, NULL,
  nl, forward_nl_integer,
  &nl_303_chain,
  NULL, &eltwise_304_layer, AI_STATIC, 
  .nl_params = &nl_303_nl_params, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_307_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_306_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_307_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_307_layer, 307,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_307_chain,
  NULL, &nl_303_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_306_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_302_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_306_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_306_layer, 306,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_306_chain,
  NULL, &eltwise_307_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_302_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &slice_301_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_302_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_302_weights, &conv2d_302_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_302_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_302_layer, 302,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA,
  &conv2d_302_chain,
  NULL, &eltwise_306_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_SAME, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)


AI_STATIC_CONST ai_u8 slice_301_axes_data[] = { 2 };
AI_ARRAY_OBJ_DECLARE(
    slice_301_axes, AI_ARRAY_FORMAT_U8,
    slice_301_axes_data, slice_301_axes_data, 1, AI_STATIC_CONST)

AI_STATIC_CONST ai_i16 slice_301_starts_data[] = { 64 };
AI_ARRAY_OBJ_DECLARE(
    slice_301_starts, AI_ARRAY_FORMAT_S16,
    slice_301_starts_data, slice_301_starts_data, 1, AI_STATIC_CONST)

AI_STATIC_CONST ai_i16 slice_301_ends_data[] = { 128 };
AI_ARRAY_OBJ_DECLARE(
    slice_301_ends, AI_ARRAY_FORMAT_S16,
    slice_301_ends_data, slice_301_ends_data, 1, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  slice_301_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_299_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &slice_301_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  slice_301_layer, 301,
  SLICE_TYPE, 0x0, NULL,
  slice, forward_slice,
  &slice_301_chain,
  NULL, &conv2d_302_layer, AI_STATIC, 
  .axes = &slice_301_axes, 
  .starts = &slice_301_starts, 
  .ends = &slice_301_ends, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_299_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_298_output, &eltwise_296_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_299_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_299_layer, 299,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_299_chain,
  NULL, &slice_301_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_296_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_295_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_296_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_296_layer, 296,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_296_chain,
  NULL, &eltwise_299_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_295_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &nl_294_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_295_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_295_layer, 295,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_295_chain,
  NULL, &eltwise_296_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)


AI_STATIC_CONST ai_i8 nl_294_nl_params_data[] = { -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -127, -127, -127, -127, -127, -127, -127, -127, -126, -126, -126, -126, -125, -125, -124, -124, -123, -122, -122, -121, -120, -118, -117, -115, -114, -112, -109, -107, -104, -101, -97, -93, -88, -83, -78, -72, -66, -59, -51, -43, -35, -27, -18, -9, 0, 9, 18, 27, 35, 43, 51, 59, 66, 72, 78, 83, 88, 93, 97, 101, 104, 107, 109, 112, 114, 115, 117, 118, 120, 121, 122, 122, 123, 124, 124, 125, 125, 126, 126, 126, 126, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127 };
AI_ARRAY_OBJ_DECLARE(
    nl_294_nl_params, AI_ARRAY_FORMAT_S8,
    nl_294_nl_params_data, nl_294_nl_params_data, 256, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  nl_294_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_293_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_294_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  nl_294_layer, 294,
  NL_TYPE, 0x0, NULL,
  nl, forward_nl_integer,
  &nl_294_chain,
  NULL, &eltwise_295_layer, AI_STATIC, 
  .nl_params = &nl_294_nl_params, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_298_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_297_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_298_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_298_layer, 298,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_298_chain,
  NULL, &nl_294_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_297_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_293_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_297_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_297_layer, 297,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_297_chain,
  NULL, &eltwise_298_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_293_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &concat_292_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_293_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_293_weights, &conv2d_293_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_293_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_293_layer, 293,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA,
  &conv2d_293_chain,
  NULL, &eltwise_297_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  concat_292_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_291_output, &eltwise_249_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &concat_292_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  concat_292_layer, 292,
  CONCAT_TYPE, 0x0, NULL,
  concat, forward_concat,
  &concat_292_chain,
  NULL, &conv2d_293_layer, AI_STATIC, 
  .axis = AI_SHAPE_CHANNEL, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_291_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_290_output, &eltwise_288_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_291_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_291_layer, 291,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_291_chain,
  NULL, &concat_292_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_288_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_287_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_288_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_288_layer, 288,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_288_chain,
  NULL, &eltwise_291_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_287_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &nl_286_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_287_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_287_layer, 287,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_287_chain,
  NULL, &eltwise_288_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)


AI_STATIC_CONST ai_i8 nl_286_nl_params_data[] = { -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -127, -127, -127, -127, -127, -127, -127, -127, -127, -127, -126, -126, -126, -126, -126, -125, -125, -125, -125, -124, -124, -123, -123, -122, -122, -121, -120, -119, -118, -117, -116, -115, -114, -112, -111, -109, -107, -105, -102, -100, -97, -94, -91, -88, -84, -80, -76, -71, -67, -61, -56, -51, -45, -39, -33, -26, -20, -13, -7, 0, 7, 13, 20, 26, 33, 39, 45, 51, 56, 61, 67, 71, 76, 80, 84, 88, 91, 94, 97, 100, 102, 105, 107, 109, 111, 112, 114, 115, 116, 117, 118, 119, 120, 121, 122, 122, 123, 123, 124, 124, 125, 125, 125, 125, 126, 126, 126, 126, 126, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127 };
AI_ARRAY_OBJ_DECLARE(
    nl_286_nl_params, AI_ARRAY_FORMAT_S8,
    nl_286_nl_params_data, nl_286_nl_params_data, 256, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  nl_286_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_285_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_286_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  nl_286_layer, 286,
  NL_TYPE, 0x0, NULL,
  nl, forward_nl_integer,
  &nl_286_chain,
  NULL, &eltwise_287_layer, AI_STATIC, 
  .nl_params = &nl_286_nl_params, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_290_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_289_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_290_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_290_layer, 290,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_290_chain,
  NULL, &nl_286_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_289_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_285_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_289_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_289_layer, 289,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_289_chain,
  NULL, &eltwise_290_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_285_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_283_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_285_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_285_weights, &conv2d_285_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_285_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_285_layer, 284,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA,
  &conv2d_285_chain,
  NULL, &eltwise_289_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(2, 2), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_SAME, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_283_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_282_output, &eltwise_280_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_283_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_283_layer, 283,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_283_chain,
  NULL, &conv2d_285_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_280_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_279_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_280_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_280_layer, 280,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_280_chain,
  NULL, &eltwise_283_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_279_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &nl_278_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_279_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_279_layer, 279,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_279_chain,
  NULL, &eltwise_280_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)


AI_STATIC_CONST ai_i8 nl_278_nl_params_data[] = { -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -127, -127, -127, -127, -127, -127, -127, -127, -127, -126, -126, -126, -126, -126, -125, -125, -125, -124, -124, -123, -123, -122, -121, -120, -119, -118, -117, -116, -114, -113, -111, -109, -106, -104, -101, -98, -95, -91, -87, -83, -79, -74, -68, -63, -57, -51, -44, -37, -30, -23, -15, -8, 0, 8, 15, 23, 30, 37, 44, 51, 57, 63, 68, 74, 79, 83, 87, 91, 95, 98, 101, 104, 106, 109, 111, 113, 114, 116, 117, 118, 119, 120, 121, 122, 123, 123, 124, 124, 125, 125, 125, 126, 126, 126, 126, 126, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127 };
AI_ARRAY_OBJ_DECLARE(
    nl_278_nl_params, AI_ARRAY_FORMAT_S8,
    nl_278_nl_params_data, nl_278_nl_params_data, 256, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  nl_278_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_277_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_278_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  nl_278_layer, 278,
  NL_TYPE, 0x0, NULL,
  nl, forward_nl_integer,
  &nl_278_chain,
  NULL, &eltwise_279_layer, AI_STATIC, 
  .nl_params = &nl_278_nl_params, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_282_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_281_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_282_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_282_layer, 282,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_282_chain,
  NULL, &nl_278_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_281_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_277_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_281_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_281_layer, 281,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_281_chain,
  NULL, &eltwise_282_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_277_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &concat_276_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_277_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_277_weights, &conv2d_277_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_277_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_277_layer, 277,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA,
  &conv2d_277_chain,
  NULL, &eltwise_281_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  concat_276_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &slice_260_output, &slice_261_output, &eltwise_275_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &concat_276_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  concat_276_layer, 276,
  CONCAT_TYPE, 0x0, NULL,
  concat, forward_concat,
  &concat_276_chain,
  NULL, &conv2d_277_layer, AI_STATIC, 
  .axis = AI_SHAPE_CHANNEL, 
)


AI_STATIC_CONST ai_u8 slice_260_axes_data[] = { 2 };
AI_ARRAY_OBJ_DECLARE(
    slice_260_axes, AI_ARRAY_FORMAT_U8,
    slice_260_axes_data, slice_260_axes_data, 1, AI_STATIC_CONST)

AI_STATIC_CONST ai_i16 slice_260_starts_data[] = { 0 };
AI_ARRAY_OBJ_DECLARE(
    slice_260_starts, AI_ARRAY_FORMAT_S16,
    slice_260_starts_data, slice_260_starts_data, 1, AI_STATIC_CONST)

AI_STATIC_CONST ai_i16 slice_260_ends_data[] = { 32 };
AI_ARRAY_OBJ_DECLARE(
    slice_260_ends, AI_ARRAY_FORMAT_S16,
    slice_260_ends_data, slice_260_ends_data, 1, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  slice_260_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_259_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &slice_260_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  slice_260_layer, 260,
  SLICE_TYPE, 0x0, NULL,
  slice, forward_slice,
  &slice_260_chain,
  NULL, &concat_276_layer, AI_STATIC, 
  .axes = &slice_260_axes, 
  .starts = &slice_260_starts, 
  .ends = &slice_260_ends, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_275_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_274_output, &eltwise_272_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_275_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_275_layer, 275,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_275_chain,
  NULL, &slice_260_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_272_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_271_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_272_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_272_layer, 272,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_272_chain,
  NULL, &eltwise_275_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_271_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &nl_270_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_271_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_271_layer, 271,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_271_chain,
  NULL, &eltwise_272_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)


AI_STATIC_CONST ai_i8 nl_270_nl_params_data[] = { -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -127, -127, -127, -127, -127, -127, -127, -127, -127, -127, -126, -126, -126, -126, -126, -125, -125, -125, -124, -124, -123, -123, -122, -122, -121, -120, -119, -118, -117, -116, -115, -113, -111, -110, -108, -105, -103, -100, -98, -94, -91, -87, -83, -79, -75, -70, -65, -59, -53, -47, -41, -35, -28, -21, -14, -7, 0, 7, 14, 21, 28, 35, 41, 47, 53, 59, 65, 70, 75, 79, 83, 87, 91, 94, 98, 100, 103, 105, 108, 110, 111, 113, 115, 116, 117, 118, 119, 120, 121, 122, 122, 123, 123, 124, 124, 125, 125, 125, 126, 126, 126, 126, 126, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127 };
AI_ARRAY_OBJ_DECLARE(
    nl_270_nl_params, AI_ARRAY_FORMAT_S8,
    nl_270_nl_params_data, nl_270_nl_params_data, 256, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  nl_270_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_269_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_270_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  nl_270_layer, 270,
  NL_TYPE, 0x0, NULL,
  nl, forward_nl_integer,
  &nl_270_chain,
  NULL, &eltwise_271_layer, AI_STATIC, 
  .nl_params = &nl_270_nl_params, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_274_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_273_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_274_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_274_layer, 274,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_274_chain,
  NULL, &nl_270_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_273_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_269_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_273_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_273_layer, 273,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_273_chain,
  NULL, &eltwise_274_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_269_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_268_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_269_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_269_weights, &conv2d_269_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_269_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_269_layer, 269,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA,
  &conv2d_269_chain,
  NULL, &eltwise_273_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_SAME, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_268_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_267_output, &eltwise_265_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_268_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_268_layer, 268,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_268_chain,
  NULL, &conv2d_269_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_265_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_264_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_265_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_265_layer, 265,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_265_chain,
  NULL, &eltwise_268_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_264_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &nl_263_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_264_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_264_layer, 264,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_264_chain,
  NULL, &eltwise_265_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)


AI_STATIC_CONST ai_i8 nl_263_nl_params_data[] = { -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -127, -127, -127, -127, -127, -127, -127, -127, -127, -127, -127, -127, -127, -127, -127, -127, -127, -127, -126, -126, -126, -126, -126, -126, -126, -126, -125, -125, -125, -125, -125, -125, -124, -124, -124, -124, -123, -123, -123, -122, -122, -122, -121, -121, -120, -120, -119, -119, -118, -117, -117, -116, -115, -115, -114, -113, -112, -111, -110, -109, -108, -107, -105, -104, -103, -101, -99, -98, -96, -94, -92, -90, -88, -86, -84, -82, -79, -77, -74, -71, -69, -66, -63, -60, -56, -53, -50, -46, -43, -39, -35, -32, -28, -24, -20, -16, -12, -8, -4, 0, 4, 8, 12, 16, 20, 24, 28, 32, 35, 39, 43, 46, 50, 53, 56, 60, 63, 66, 69, 71, 74, 77, 79, 82, 84, 86, 88, 90, 92, 94, 96, 98, 99, 101, 103, 104, 105, 107, 108, 109, 110, 111, 112, 113, 114, 115, 115, 116, 117, 117, 118, 119, 119, 120, 120, 121, 121, 122, 122, 122, 123, 123, 123, 124, 124, 124, 124, 125, 125, 125, 125, 125, 125, 126, 126, 126, 126, 126, 126, 126, 126, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127 };
AI_ARRAY_OBJ_DECLARE(
    nl_263_nl_params, AI_ARRAY_FORMAT_S8,
    nl_263_nl_params_data, nl_263_nl_params_data, 256, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  nl_263_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_262_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_263_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  nl_263_layer, 263,
  NL_TYPE, 0x0, NULL,
  nl, forward_nl_integer,
  &nl_263_chain,
  NULL, &eltwise_264_layer, AI_STATIC, 
  .nl_params = &nl_263_nl_params, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_267_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_266_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_267_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_267_layer, 267,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_267_chain,
  NULL, &nl_263_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_266_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_262_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_266_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_266_layer, 266,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_266_chain,
  NULL, &eltwise_267_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_262_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &slice_261_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_262_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_262_weights, &conv2d_262_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_262_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_262_layer, 262,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA,
  &conv2d_262_chain,
  NULL, &eltwise_266_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_SAME, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)


AI_STATIC_CONST ai_u8 slice_261_axes_data[] = { 2 };
AI_ARRAY_OBJ_DECLARE(
    slice_261_axes, AI_ARRAY_FORMAT_U8,
    slice_261_axes_data, slice_261_axes_data, 1, AI_STATIC_CONST)

AI_STATIC_CONST ai_i16 slice_261_starts_data[] = { 32 };
AI_ARRAY_OBJ_DECLARE(
    slice_261_starts, AI_ARRAY_FORMAT_S16,
    slice_261_starts_data, slice_261_starts_data, 1, AI_STATIC_CONST)

AI_STATIC_CONST ai_i16 slice_261_ends_data[] = { 64 };
AI_ARRAY_OBJ_DECLARE(
    slice_261_ends, AI_ARRAY_FORMAT_S16,
    slice_261_ends_data, slice_261_ends_data, 1, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  slice_261_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_259_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &slice_261_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  slice_261_layer, 261,
  SLICE_TYPE, 0x0, NULL,
  slice, forward_slice,
  &slice_261_chain,
  NULL, &conv2d_262_layer, AI_STATIC, 
  .axes = &slice_261_axes, 
  .starts = &slice_261_starts, 
  .ends = &slice_261_ends, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_259_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_258_output, &eltwise_256_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_259_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_259_layer, 259,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_259_chain,
  NULL, &slice_261_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_256_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_255_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_256_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_256_layer, 256,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_256_chain,
  NULL, &eltwise_259_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_255_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &nl_254_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_255_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_255_layer, 255,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_255_chain,
  NULL, &eltwise_256_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)


AI_STATIC_CONST ai_i8 nl_254_nl_params_data[] = { -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -127, -127, -127, -127, -127, -127, -127, -127, -127, -127, -127, -127, -126, -126, -126, -126, -126, -126, -125, -125, -125, -125, -124, -124, -123, -123, -123, -122, -122, -121, -120, -120, -119, -118, -117, -116, -115, -114, -113, -111, -110, -109, -107, -105, -103, -101, -99, -96, -94, -91, -88, -85, -82, -78, -75, -71, -67, -63, -58, -54, -49, -44, -39, -33, -28, -23, -17, -11, -6, 0, 6, 11, 17, 23, 28, 33, 39, 44, 49, 54, 58, 63, 67, 71, 75, 78, 82, 85, 88, 91, 94, 96, 99, 101, 103, 105, 107, 109, 110, 111, 113, 114, 115, 116, 117, 118, 119, 120, 120, 121, 122, 122, 123, 123, 123, 124, 124, 125, 125, 125, 125, 126, 126, 126, 126, 126, 126, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127 };
AI_ARRAY_OBJ_DECLARE(
    nl_254_nl_params, AI_ARRAY_FORMAT_S8,
    nl_254_nl_params_data, nl_254_nl_params_data, 256, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  nl_254_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_253_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_254_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  nl_254_layer, 254,
  NL_TYPE, 0x0, NULL,
  nl, forward_nl_integer,
  &nl_254_chain,
  NULL, &eltwise_255_layer, AI_STATIC, 
  .nl_params = &nl_254_nl_params, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_258_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_257_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_258_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_258_layer, 258,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_258_chain,
  NULL, &nl_254_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_257_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_253_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_257_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_257_layer, 257,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_257_chain,
  NULL, &eltwise_258_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_253_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &concat_252_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_253_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_253_weights, &conv2d_253_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_253_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_253_layer, 253,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA,
  &conv2d_253_chain,
  NULL, &eltwise_257_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  concat_252_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &resize_251_output, &eltwise_102_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &concat_252_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  concat_252_layer, 252,
  CONCAT_TYPE, 0x0, NULL,
  concat, forward_concat,
  &concat_252_chain,
  NULL, &conv2d_253_layer, AI_STATIC, 
  .axis = AI_SHAPE_CHANNEL, 
)


AI_STATIC_CONST ai_float resize_251_scales_data[] = { 2.0, 2.0, 1.0, 1.0 };
AI_ARRAY_OBJ_DECLARE(
    resize_251_scales, AI_ARRAY_FORMAT_FLOAT,
    resize_251_scales_data, resize_251_scales_data, 4, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  resize_251_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conversion_250_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &resize_251_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  resize_251_layer, 251,
  UPSAMPLE_TYPE, 0x0, NULL,
  upsample, forward_upsample_nearest,
  &resize_251_chain,
  NULL, &concat_252_layer, AI_STATIC, 
  .scales = &resize_251_scales, 
  .center = false, 
  .mode = AI_UPSAMPLE_NEAREST, 
  .nearest_mode = AI_ROUND_FLOOR, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conversion_250_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_249_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conversion_250_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conversion_250_layer, 250,
  NL_TYPE, 0x0, NULL,
  nl, node_convert_integer,
  &conversion_250_chain,
  NULL, &resize_251_layer, AI_STATIC, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_249_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_248_output, &eltwise_246_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_249_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_249_layer, 249,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_249_chain,
  NULL, &conversion_250_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_246_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_245_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_246_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_246_layer, 246,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_246_chain,
  NULL, &eltwise_249_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_245_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &nl_244_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_245_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_245_layer, 245,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_245_chain,
  NULL, &eltwise_246_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)


AI_STATIC_CONST ai_i8 nl_244_nl_params_data[] = { -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -127, -127, -127, -127, -127, -127, -127, -127, -127, -127, -127, -127, -126, -126, -126, -126, -126, -125, -125, -125, -124, -124, -124, -123, -123, -122, -122, -121, -120, -120, -119, -118, -117, -116, -115, -114, -112, -111, -109, -107, -105, -103, -101, -99, -96, -93, -90, -87, -83, -80, -76, -72, -67, -63, -58, -53, -47, -42, -36, -30, -25, -19, -12, -6, 0, 6, 12, 19, 25, 30, 36, 42, 47, 53, 58, 63, 67, 72, 76, 80, 83, 87, 90, 93, 96, 99, 101, 103, 105, 107, 109, 111, 112, 114, 115, 116, 117, 118, 119, 120, 120, 121, 122, 122, 123, 123, 124, 124, 124, 125, 125, 125, 126, 126, 126, 126, 126, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127 };
AI_ARRAY_OBJ_DECLARE(
    nl_244_nl_params, AI_ARRAY_FORMAT_S8,
    nl_244_nl_params_data, nl_244_nl_params_data, 256, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  nl_244_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_243_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_244_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  nl_244_layer, 244,
  NL_TYPE, 0x0, NULL,
  nl, forward_nl_integer,
  &nl_244_chain,
  NULL, &eltwise_245_layer, AI_STATIC, 
  .nl_params = &nl_244_nl_params, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_248_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_247_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_248_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_248_layer, 248,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_248_chain,
  NULL, &nl_244_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_247_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_243_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_247_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_247_layer, 247,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_247_chain,
  NULL, &eltwise_248_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_243_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &concat_242_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_243_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_243_weights, &conv2d_243_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_243_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_243_layer, 243,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA,
  &conv2d_243_chain,
  NULL, &eltwise_247_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  concat_242_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &slice_226_output, &slice_227_output, &eltwise_241_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &concat_242_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  concat_242_layer, 242,
  CONCAT_TYPE, 0x0, NULL,
  concat, forward_concat,
  &concat_242_chain,
  NULL, &conv2d_243_layer, AI_STATIC, 
  .axis = AI_SHAPE_CHANNEL, 
)


AI_STATIC_CONST ai_u8 slice_226_axes_data[] = { 2 };
AI_ARRAY_OBJ_DECLARE(
    slice_226_axes, AI_ARRAY_FORMAT_U8,
    slice_226_axes_data, slice_226_axes_data, 1, AI_STATIC_CONST)

AI_STATIC_CONST ai_i16 slice_226_starts_data[] = { 0 };
AI_ARRAY_OBJ_DECLARE(
    slice_226_starts, AI_ARRAY_FORMAT_S16,
    slice_226_starts_data, slice_226_starts_data, 1, AI_STATIC_CONST)

AI_STATIC_CONST ai_i16 slice_226_ends_data[] = { 64 };
AI_ARRAY_OBJ_DECLARE(
    slice_226_ends, AI_ARRAY_FORMAT_S16,
    slice_226_ends_data, slice_226_ends_data, 1, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  slice_226_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_225_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &slice_226_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  slice_226_layer, 226,
  SLICE_TYPE, 0x0, NULL,
  slice, forward_slice,
  &slice_226_chain,
  NULL, &concat_242_layer, AI_STATIC, 
  .axes = &slice_226_axes, 
  .starts = &slice_226_starts, 
  .ends = &slice_226_ends, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_241_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_240_output, &eltwise_238_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_241_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_241_layer, 241,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_241_chain,
  NULL, &slice_226_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_238_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_237_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_238_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_238_layer, 238,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_238_chain,
  NULL, &eltwise_241_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_237_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &nl_236_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_237_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_237_layer, 237,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_237_chain,
  NULL, &eltwise_238_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)


AI_STATIC_CONST ai_i8 nl_236_nl_params_data[] = { -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -127, -127, -127, -127, -127, -127, -127, -127, -127, -127, -127, -126, -126, -126, -126, -125, -125, -125, -125, -124, -124, -123, -123, -122, -122, -121, -120, -119, -118, -117, -116, -115, -113, -112, -110, -108, -106, -104, -101, -99, -96, -92, -89, -85, -81, -77, -73, -68, -63, -57, -52, -46, -40, -34, -27, -20, -14, -7, 0, 7, 14, 20, 27, 34, 40, 46, 52, 57, 63, 68, 73, 77, 81, 85, 89, 92, 96, 99, 101, 104, 106, 108, 110, 112, 113, 115, 116, 117, 118, 119, 120, 121, 122, 122, 123, 123, 124, 124, 125, 125, 125, 125, 126, 126, 126, 126, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127 };
AI_ARRAY_OBJ_DECLARE(
    nl_236_nl_params, AI_ARRAY_FORMAT_S8,
    nl_236_nl_params_data, nl_236_nl_params_data, 256, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  nl_236_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_235_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_236_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  nl_236_layer, 236,
  NL_TYPE, 0x0, NULL,
  nl, forward_nl_integer,
  &nl_236_chain,
  NULL, &eltwise_237_layer, AI_STATIC, 
  .nl_params = &nl_236_nl_params, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_240_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_239_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_240_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_240_layer, 240,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_240_chain,
  NULL, &nl_236_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_239_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_235_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_239_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_239_layer, 239,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_239_chain,
  NULL, &eltwise_240_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_235_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_234_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_235_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_235_weights, &conv2d_235_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_235_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_235_layer, 235,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA,
  &conv2d_235_chain,
  NULL, &eltwise_239_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_SAME, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_234_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_233_output, &eltwise_231_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_234_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_234_layer, 234,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_234_chain,
  NULL, &conv2d_235_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_231_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_230_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_231_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_231_layer, 231,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_231_chain,
  NULL, &eltwise_234_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_230_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &nl_229_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_230_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_230_layer, 230,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_230_chain,
  NULL, &eltwise_231_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)


AI_STATIC_CONST ai_i8 nl_229_nl_params_data[] = { -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -127, -127, -127, -127, -127, -127, -127, -127, -127, -127, -127, -127, -126, -126, -126, -126, -126, -126, -125, -125, -125, -125, -124, -124, -123, -123, -123, -122, -122, -121, -120, -120, -119, -118, -117, -116, -115, -114, -112, -111, -110, -108, -106, -104, -102, -100, -98, -95, -93, -90, -87, -83, -80, -76, -72, -68, -64, -59, -55, -50, -45, -40, -34, -29, -23, -17, -12, -6, 0, 6, 12, 17, 23, 29, 34, 40, 45, 50, 55, 59, 64, 68, 72, 76, 80, 83, 87, 90, 93, 95, 98, 100, 102, 104, 106, 108, 110, 111, 112, 114, 115, 116, 117, 118, 119, 120, 120, 121, 122, 122, 123, 123, 123, 124, 124, 125, 125, 125, 125, 126, 126, 126, 126, 126, 126, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127 };
AI_ARRAY_OBJ_DECLARE(
    nl_229_nl_params, AI_ARRAY_FORMAT_S8,
    nl_229_nl_params_data, nl_229_nl_params_data, 256, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  nl_229_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_228_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_229_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  nl_229_layer, 229,
  NL_TYPE, 0x0, NULL,
  nl, forward_nl_integer,
  &nl_229_chain,
  NULL, &eltwise_230_layer, AI_STATIC, 
  .nl_params = &nl_229_nl_params, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_233_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_232_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_233_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_233_layer, 233,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_233_chain,
  NULL, &nl_229_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_232_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_228_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_232_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_232_layer, 232,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_232_chain,
  NULL, &eltwise_233_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_228_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &slice_227_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_228_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_228_weights, &conv2d_228_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_228_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_228_layer, 228,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA,
  &conv2d_228_chain,
  NULL, &eltwise_232_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_SAME, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)


AI_STATIC_CONST ai_u8 slice_227_axes_data[] = { 2 };
AI_ARRAY_OBJ_DECLARE(
    slice_227_axes, AI_ARRAY_FORMAT_U8,
    slice_227_axes_data, slice_227_axes_data, 1, AI_STATIC_CONST)

AI_STATIC_CONST ai_i16 slice_227_starts_data[] = { 64 };
AI_ARRAY_OBJ_DECLARE(
    slice_227_starts, AI_ARRAY_FORMAT_S16,
    slice_227_starts_data, slice_227_starts_data, 1, AI_STATIC_CONST)

AI_STATIC_CONST ai_i16 slice_227_ends_data[] = { 128 };
AI_ARRAY_OBJ_DECLARE(
    slice_227_ends, AI_ARRAY_FORMAT_S16,
    slice_227_ends_data, slice_227_ends_data, 1, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  slice_227_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_225_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &slice_227_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  slice_227_layer, 227,
  SLICE_TYPE, 0x0, NULL,
  slice, forward_slice,
  &slice_227_chain,
  NULL, &conv2d_228_layer, AI_STATIC, 
  .axes = &slice_227_axes, 
  .starts = &slice_227_starts, 
  .ends = &slice_227_ends, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_225_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_224_output, &eltwise_222_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_225_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_225_layer, 225,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_225_chain,
  NULL, &slice_227_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_222_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_221_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_222_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_222_layer, 222,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_222_chain,
  NULL, &eltwise_225_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_221_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &nl_220_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_221_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_221_layer, 221,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_221_chain,
  NULL, &eltwise_222_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)


AI_STATIC_CONST ai_i8 nl_220_nl_params_data[] = { -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -127, -127, -127, -127, -127, -127, -127, -127, -127, -127, -127, -127, -126, -126, -126, -126, -126, -126, -125, -125, -125, -124, -124, -124, -123, -123, -122, -122, -121, -121, -120, -119, -118, -117, -116, -115, -114, -113, -112, -110, -109, -107, -105, -103, -101, -98, -96, -93, -90, -87, -84, -80, -77, -73, -69, -65, -60, -55, -50, -45, -40, -35, -29, -23, -18, -12, -6, 0, 6, 12, 18, 23, 29, 35, 40, 45, 50, 55, 60, 65, 69, 73, 77, 80, 84, 87, 90, 93, 96, 98, 101, 103, 105, 107, 109, 110, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 121, 122, 122, 123, 123, 124, 124, 124, 125, 125, 125, 126, 126, 126, 126, 126, 126, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127 };
AI_ARRAY_OBJ_DECLARE(
    nl_220_nl_params, AI_ARRAY_FORMAT_S8,
    nl_220_nl_params_data, nl_220_nl_params_data, 256, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  nl_220_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_219_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_220_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  nl_220_layer, 220,
  NL_TYPE, 0x0, NULL,
  nl, forward_nl_integer,
  &nl_220_chain,
  NULL, &eltwise_221_layer, AI_STATIC, 
  .nl_params = &nl_220_nl_params, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_224_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_223_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_224_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_224_layer, 224,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_224_chain,
  NULL, &nl_220_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_223_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_219_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_223_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_223_layer, 223,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_223_chain,
  NULL, &eltwise_224_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_219_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &concat_218_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_219_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_219_weights, &conv2d_219_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_219_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_219_layer, 219,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA,
  &conv2d_219_chain,
  NULL, &eltwise_223_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  concat_218_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &resize_217_output, &eltwise_157_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &concat_218_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  concat_218_layer, 218,
  CONCAT_TYPE, 0x0, NULL,
  concat, forward_concat,
  &concat_218_chain,
  NULL, &conv2d_219_layer, AI_STATIC, 
  .axis = AI_SHAPE_CHANNEL, 
)


AI_STATIC_CONST ai_float resize_217_scales_data[] = { 2.0, 2.0, 1.0, 1.0 };
AI_ARRAY_OBJ_DECLARE(
    resize_217_scales, AI_ARRAY_FORMAT_FLOAT,
    resize_217_scales_data, resize_217_scales_data, 4, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  resize_217_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conversion_216_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &resize_217_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  resize_217_layer, 217,
  UPSAMPLE_TYPE, 0x0, NULL,
  upsample, forward_upsample_nearest,
  &resize_217_chain,
  NULL, &concat_218_layer, AI_STATIC, 
  .scales = &resize_217_scales, 
  .center = false, 
  .mode = AI_UPSAMPLE_NEAREST, 
  .nearest_mode = AI_ROUND_FLOOR, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conversion_216_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_215_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conversion_216_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conversion_216_layer, 216,
  NL_TYPE, 0x0, NULL,
  nl, node_convert_integer,
  &conversion_216_chain,
  NULL, &resize_217_layer, AI_STATIC, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_215_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_214_output, &eltwise_212_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_215_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_215_layer, 215,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_215_chain,
  NULL, &conversion_216_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_212_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_211_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_212_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_212_layer, 212,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_212_chain,
  NULL, &eltwise_215_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_211_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &nl_210_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_211_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_211_layer, 211,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_211_chain,
  NULL, &eltwise_212_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)


AI_STATIC_CONST ai_i8 nl_210_nl_params_data[] = { -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -127, -127, -127, -127, -127, -127, -127, -127, -127, -127, -127, -127, -126, -126, -126, -126, -126, -126, -125, -125, -125, -125, -124, -124, -124, -123, -123, -122, -122, -121, -121, -120, -119, -118, -118, -117, -116, -115, -113, -112, -111, -109, -108, -106, -104, -102, -100, -98, -96, -93, -90, -87, -84, -81, -78, -74, -70, -66, -62, -57, -53, -48, -43, -38, -33, -28, -22, -17, -11, -6, 0, 6, 11, 17, 22, 28, 33, 38, 43, 48, 53, 57, 62, 66, 70, 74, 78, 81, 84, 87, 90, 93, 96, 98, 100, 102, 104, 106, 108, 109, 111, 112, 113, 115, 116, 117, 118, 118, 119, 120, 121, 121, 122, 122, 123, 123, 124, 124, 124, 125, 125, 125, 125, 126, 126, 126, 126, 126, 126, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127 };
AI_ARRAY_OBJ_DECLARE(
    nl_210_nl_params, AI_ARRAY_FORMAT_S8,
    nl_210_nl_params_data, nl_210_nl_params_data, 256, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  nl_210_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_209_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_210_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  nl_210_layer, 210,
  NL_TYPE, 0x0, NULL,
  nl, forward_nl_integer,
  &nl_210_chain,
  NULL, &eltwise_211_layer, AI_STATIC, 
  .nl_params = &nl_210_nl_params, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_214_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_213_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_214_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_214_layer, 214,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_214_chain,
  NULL, &nl_210_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_213_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_209_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_213_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_213_layer, 213,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_213_chain,
  NULL, &eltwise_214_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_209_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &concat_208_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_209_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_209_weights, &conv2d_209_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_209_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_209_layer, 209,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA,
  &conv2d_209_chain,
  NULL, &eltwise_213_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  concat_208_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 4, &eltwise_204_output, &pool_205_output, &pool_206_output, &pool_207_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &concat_208_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  concat_208_layer, 208,
  CONCAT_TYPE, 0x0, NULL,
  concat, forward_concat,
  &concat_208_chain,
  NULL, &conv2d_209_layer, AI_STATIC, 
  .axis = AI_SHAPE_CHANNEL, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  pool_207_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &pool_206_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &pool_207_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  pool_207_layer, 207,
  POOL_TYPE, 0x0, NULL,
  pool, forward_mp_integer_INT8,
  &pool_207_chain,
  NULL, &concat_208_layer, AI_STATIC, 
  .pool_size = AI_SHAPE_2D_INIT(5, 5), 
  .pool_stride = AI_SHAPE_2D_INIT(1, 1), 
  .pool_pad = AI_SHAPE_INIT(4, 2, 2, 2, 2), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  pool_206_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &pool_205_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &pool_206_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  pool_206_layer, 206,
  POOL_TYPE, 0x0, NULL,
  pool, forward_mp_integer_INT8,
  &pool_206_chain,
  NULL, &pool_207_layer, AI_STATIC, 
  .pool_size = AI_SHAPE_2D_INIT(5, 5), 
  .pool_stride = AI_SHAPE_2D_INIT(1, 1), 
  .pool_pad = AI_SHAPE_INIT(4, 2, 2, 2, 2), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  pool_205_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_204_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &pool_205_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  pool_205_layer, 205,
  POOL_TYPE, 0x0, NULL,
  pool, forward_mp_integer_INT8,
  &pool_205_chain,
  NULL, &pool_206_layer, AI_STATIC, 
  .pool_size = AI_SHAPE_2D_INIT(5, 5), 
  .pool_stride = AI_SHAPE_2D_INIT(1, 1), 
  .pool_pad = AI_SHAPE_INIT(4, 2, 2, 2, 2), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_204_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_203_output, &eltwise_201_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_204_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_204_layer, 204,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_204_chain,
  NULL, &pool_205_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_201_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_200_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_201_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_201_layer, 201,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_201_chain,
  NULL, &eltwise_204_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_200_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &nl_199_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_200_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_200_layer, 200,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_200_chain,
  NULL, &eltwise_201_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)


AI_STATIC_CONST ai_i8 nl_199_nl_params_data[] = { -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -127, -127, -127, -127, -127, -127, -127, -127, -127, -127, -127, -126, -126, -126, -126, -126, -125, -125, -125, -125, -124, -124, -124, -123, -123, -122, -121, -121, -120, -119, -118, -117, -116, -115, -114, -113, -111, -110, -108, -106, -104, -102, -99, -97, -94, -91, -87, -84, -80, -76, -72, -68, -63, -58, -53, -48, -42, -37, -31, -25, -19, -13, -6, 0, 6, 13, 19, 25, 31, 37, 42, 48, 53, 58, 63, 68, 72, 76, 80, 84, 87, 91, 94, 97, 99, 102, 104, 106, 108, 110, 111, 113, 114, 115, 116, 117, 118, 119, 120, 121, 121, 122, 123, 123, 124, 124, 124, 125, 125, 125, 125, 126, 126, 126, 126, 126, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127 };
AI_ARRAY_OBJ_DECLARE(
    nl_199_nl_params, AI_ARRAY_FORMAT_S8,
    nl_199_nl_params_data, nl_199_nl_params_data, 256, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  nl_199_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_198_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_199_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  nl_199_layer, 199,
  NL_TYPE, 0x0, NULL,
  nl, forward_nl_integer,
  &nl_199_chain,
  NULL, &eltwise_200_layer, AI_STATIC, 
  .nl_params = &nl_199_nl_params, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_203_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_202_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_203_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_203_layer, 203,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_203_chain,
  NULL, &nl_199_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_202_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_198_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_202_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_202_layer, 202,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_202_chain,
  NULL, &eltwise_203_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_198_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_197_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_198_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_198_weights, &conv2d_198_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_198_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_198_layer, 198,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA,
  &conv2d_198_chain,
  NULL, &eltwise_202_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_197_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_196_output, &eltwise_194_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_197_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_197_layer, 197,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_197_chain,
  NULL, &conv2d_198_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_194_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_193_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_194_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_194_layer, 194,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_194_chain,
  NULL, &eltwise_197_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_193_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &nl_192_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_193_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_193_layer, 193,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_193_chain,
  NULL, &eltwise_194_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)


AI_STATIC_CONST ai_i8 nl_192_nl_params_data[] = { -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -127, -127, -127, -127, -127, -127, -127, -127, -127, -126, -126, -126, -126, -126, -125, -125, -125, -124, -124, -123, -122, -122, -121, -120, -119, -118, -117, -116, -114, -113, -111, -109, -106, -104, -101, -98, -95, -91, -87, -83, -79, -74, -68, -63, -57, -51, -44, -37, -30, -23, -15, -8, 0, 8, 15, 23, 30, 37, 44, 51, 57, 63, 68, 74, 79, 83, 87, 91, 95, 98, 101, 104, 106, 109, 111, 113, 114, 116, 117, 118, 119, 120, 121, 122, 122, 123, 124, 124, 125, 125, 125, 126, 126, 126, 126, 126, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127 };
AI_ARRAY_OBJ_DECLARE(
    nl_192_nl_params, AI_ARRAY_FORMAT_S8,
    nl_192_nl_params_data, nl_192_nl_params_data, 256, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  nl_192_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_191_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_192_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  nl_192_layer, 192,
  NL_TYPE, 0x0, NULL,
  nl, forward_nl_integer,
  &nl_192_chain,
  NULL, &eltwise_193_layer, AI_STATIC, 
  .nl_params = &nl_192_nl_params, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_196_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_195_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_196_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_196_layer, 196,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_196_chain,
  NULL, &nl_192_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_195_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_191_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_195_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_195_layer, 195,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_195_chain,
  NULL, &eltwise_196_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_191_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &concat_190_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_191_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_191_weights, &conv2d_191_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_191_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_191_layer, 191,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA,
  &conv2d_191_chain,
  NULL, &eltwise_195_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  concat_190_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &slice_173_output, &slice_174_output, &eltwise_189_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &concat_190_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  concat_190_layer, 190,
  CONCAT_TYPE, 0x0, NULL,
  concat, forward_concat,
  &concat_190_chain,
  NULL, &conv2d_191_layer, AI_STATIC, 
  .axis = AI_SHAPE_CHANNEL, 
)


AI_STATIC_CONST ai_u8 slice_173_axes_data[] = { 2 };
AI_ARRAY_OBJ_DECLARE(
    slice_173_axes, AI_ARRAY_FORMAT_U8,
    slice_173_axes_data, slice_173_axes_data, 1, AI_STATIC_CONST)

AI_STATIC_CONST ai_i16 slice_173_starts_data[] = { 0 };
AI_ARRAY_OBJ_DECLARE(
    slice_173_starts, AI_ARRAY_FORMAT_S16,
    slice_173_starts_data, slice_173_starts_data, 1, AI_STATIC_CONST)

AI_STATIC_CONST ai_i16 slice_173_ends_data[] = { 128 };
AI_ARRAY_OBJ_DECLARE(
    slice_173_ends, AI_ARRAY_FORMAT_S16,
    slice_173_ends_data, slice_173_ends_data, 1, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  slice_173_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_172_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &slice_173_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  slice_173_layer, 173,
  SLICE_TYPE, 0x0, NULL,
  slice, forward_slice,
  &slice_173_chain,
  NULL, &concat_190_layer, AI_STATIC, 
  .axes = &slice_173_axes, 
  .starts = &slice_173_starts, 
  .ends = &slice_173_ends, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_189_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &slice_174_output, &eltwise_188_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_189_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_189_layer, 189,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_189_chain,
  NULL, &slice_173_layer, AI_STATIC, 
  .operation = ai_sum_f32, 
  .buffer_operation = ai_sum_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_188_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_187_output, &eltwise_185_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_188_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_188_layer, 188,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_188_chain,
  NULL, &eltwise_189_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_185_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_184_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_185_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_185_layer, 185,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_185_chain,
  NULL, &eltwise_188_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_184_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &nl_183_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_184_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_184_layer, 184,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_184_chain,
  NULL, &eltwise_185_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)


AI_STATIC_CONST ai_i8 nl_183_nl_params_data[] = { -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -127, -127, -127, -127, -127, -127, -126, -126, -126, -125, -125, -124, -123, -122, -121, -120, -118, -116, -114, -112, -109, -105, -101, -97, -92, -86, -79, -71, -63, -54, -44, -34, -23, -11, 0, 11, 23, 34, 44, 54, 63, 71, 79, 86, 92, 97, 101, 105, 109, 112, 114, 116, 118, 120, 121, 122, 123, 124, 125, 125, 126, 126, 126, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127 };
AI_ARRAY_OBJ_DECLARE(
    nl_183_nl_params, AI_ARRAY_FORMAT_S8,
    nl_183_nl_params_data, nl_183_nl_params_data, 256, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  nl_183_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_182_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_183_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  nl_183_layer, 183,
  NL_TYPE, 0x0, NULL,
  nl, forward_nl_integer,
  &nl_183_chain,
  NULL, &eltwise_184_layer, AI_STATIC, 
  .nl_params = &nl_183_nl_params, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_187_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_186_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_187_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_187_layer, 187,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_187_chain,
  NULL, &nl_183_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_186_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_182_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_186_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_186_layer, 186,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_186_chain,
  NULL, &eltwise_187_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_182_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_181_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_182_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_182_weights, &conv2d_182_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_182_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_182_layer, 182,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA,
  &conv2d_182_chain,
  NULL, &eltwise_186_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_SAME, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_181_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_180_output, &eltwise_178_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_181_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_181_layer, 181,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_181_chain,
  NULL, &conv2d_182_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_178_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_177_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_178_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_178_layer, 178,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_178_chain,
  NULL, &eltwise_181_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_177_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &nl_176_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_177_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_177_layer, 177,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_177_chain,
  NULL, &eltwise_178_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)


AI_STATIC_CONST ai_i8 nl_176_nl_params_data[] = { -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -127, -127, -127, -127, -127, -127, -127, -127, -127, -127, -127, -126, -126, -126, -126, -126, -125, -125, -125, -124, -124, -124, -123, -123, -122, -122, -121, -120, -119, -119, -118, -116, -115, -114, -113, -111, -109, -108, -106, -103, -101, -98, -96, -93, -89, -86, -82, -78, -74, -70, -65, -60, -55, -49, -44, -38, -32, -26, -19, -13, -7, 0, 7, 13, 19, 26, 32, 38, 44, 49, 55, 60, 65, 70, 74, 78, 82, 86, 89, 93, 96, 98, 101, 103, 106, 108, 109, 111, 113, 114, 115, 116, 118, 119, 119, 120, 121, 122, 122, 123, 123, 124, 124, 124, 125, 125, 125, 126, 126, 126, 126, 126, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127 };
AI_ARRAY_OBJ_DECLARE(
    nl_176_nl_params, AI_ARRAY_FORMAT_S8,
    nl_176_nl_params_data, nl_176_nl_params_data, 256, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  nl_176_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_175_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_176_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  nl_176_layer, 176,
  NL_TYPE, 0x0, NULL,
  nl, forward_nl_integer,
  &nl_176_chain,
  NULL, &eltwise_177_layer, AI_STATIC, 
  .nl_params = &nl_176_nl_params, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_180_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_179_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_180_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_180_layer, 180,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_180_chain,
  NULL, &nl_176_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_179_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_175_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_179_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_179_layer, 179,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_179_chain,
  NULL, &eltwise_180_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_175_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &slice_174_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_175_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_175_weights, &conv2d_175_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_175_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_175_layer, 175,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA,
  &conv2d_175_chain,
  NULL, &eltwise_179_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_SAME, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)


AI_STATIC_CONST ai_u8 slice_174_axes_data[] = { 2 };
AI_ARRAY_OBJ_DECLARE(
    slice_174_axes, AI_ARRAY_FORMAT_U8,
    slice_174_axes_data, slice_174_axes_data, 1, AI_STATIC_CONST)

AI_STATIC_CONST ai_i16 slice_174_starts_data[] = { 128 };
AI_ARRAY_OBJ_DECLARE(
    slice_174_starts, AI_ARRAY_FORMAT_S16,
    slice_174_starts_data, slice_174_starts_data, 1, AI_STATIC_CONST)

AI_STATIC_CONST ai_i16 slice_174_ends_data[] = { 256 };
AI_ARRAY_OBJ_DECLARE(
    slice_174_ends, AI_ARRAY_FORMAT_S16,
    slice_174_ends_data, slice_174_ends_data, 1, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  slice_174_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_172_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &slice_174_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  slice_174_layer, 174,
  SLICE_TYPE, 0x0, NULL,
  slice, forward_slice,
  &slice_174_chain,
  NULL, &conv2d_175_layer, AI_STATIC, 
  .axes = &slice_174_axes, 
  .starts = &slice_174_starts, 
  .ends = &slice_174_ends, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_172_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_171_output, &eltwise_169_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_172_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_172_layer, 172,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_172_chain,
  NULL, &slice_174_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_169_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_168_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_169_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_169_layer, 169,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_169_chain,
  NULL, &eltwise_172_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_168_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &nl_167_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_168_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_168_layer, 168,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_168_chain,
  NULL, &eltwise_169_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)


AI_STATIC_CONST ai_i8 nl_167_nl_params_data[] = { -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -127, -127, -127, -127, -127, -127, -127, -127, -127, -127, -126, -126, -126, -126, -126, -125, -125, -125, -124, -124, -123, -123, -122, -121, -121, -120, -119, -118, -117, -116, -114, -113, -111, -109, -107, -105, -102, -100, -97, -94, -90, -87, -83, -79, -74, -69, -64, -59, -53, -47, -41, -34, -28, -21, -14, -7, 0, 7, 14, 21, 28, 34, 41, 47, 53, 59, 64, 69, 74, 79, 83, 87, 90, 94, 97, 100, 102, 105, 107, 109, 111, 113, 114, 116, 117, 118, 119, 120, 121, 121, 122, 123, 123, 124, 124, 125, 125, 125, 126, 126, 126, 126, 126, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127 };
AI_ARRAY_OBJ_DECLARE(
    nl_167_nl_params, AI_ARRAY_FORMAT_S8,
    nl_167_nl_params_data, nl_167_nl_params_data, 256, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  nl_167_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_166_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_167_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  nl_167_layer, 167,
  NL_TYPE, 0x0, NULL,
  nl, forward_nl_integer,
  &nl_167_chain,
  NULL, &eltwise_168_layer, AI_STATIC, 
  .nl_params = &nl_167_nl_params, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_171_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_170_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_171_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_171_layer, 171,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_171_chain,
  NULL, &nl_167_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_170_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_166_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_170_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_170_layer, 170,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_170_chain,
  NULL, &eltwise_171_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_166_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_165_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_166_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_166_weights, &conv2d_166_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_166_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_166_layer, 166,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA,
  &conv2d_166_chain,
  NULL, &eltwise_170_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_165_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_164_output, &eltwise_162_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_165_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_165_layer, 165,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_165_chain,
  NULL, &conv2d_166_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_162_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_161_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_162_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_162_layer, 162,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_162_chain,
  NULL, &eltwise_165_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_161_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &nl_160_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_161_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_161_layer, 161,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_161_chain,
  NULL, &eltwise_162_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)


AI_STATIC_CONST ai_i8 nl_160_nl_params_data[] = { -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -127, -127, -127, -127, -127, -127, -127, -127, -127, -127, -127, -127, -127, -127, -126, -126, -126, -126, -126, -126, -125, -125, -125, -125, -124, -124, -124, -123, -123, -123, -122, -122, -121, -121, -120, -120, -119, -118, -117, -117, -116, -115, -114, -112, -111, -110, -108, -107, -105, -104, -102, -100, -98, -96, -93, -91, -88, -85, -82, -79, -76, -73, -69, -65, -61, -57, -53, -49, -44, -40, -35, -30, -25, -20, -15, -10, -5, 0, 5, 10, 15, 20, 25, 30, 35, 40, 44, 49, 53, 57, 61, 65, 69, 73, 76, 79, 82, 85, 88, 91, 93, 96, 98, 100, 102, 104, 105, 107, 108, 110, 111, 112, 114, 115, 116, 117, 117, 118, 119, 120, 120, 121, 121, 122, 122, 123, 123, 123, 124, 124, 124, 125, 125, 125, 125, 126, 126, 126, 126, 126, 126, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127 };
AI_ARRAY_OBJ_DECLARE(
    nl_160_nl_params, AI_ARRAY_FORMAT_S8,
    nl_160_nl_params_data, nl_160_nl_params_data, 256, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  nl_160_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_159_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_160_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  nl_160_layer, 160,
  NL_TYPE, 0x0, NULL,
  nl, forward_nl_integer,
  &nl_160_chain,
  NULL, &eltwise_161_layer, AI_STATIC, 
  .nl_params = &nl_160_nl_params, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_164_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_163_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_164_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_164_layer, 164,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_164_chain,
  NULL, &nl_160_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_163_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_159_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_163_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_163_layer, 163,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_163_chain,
  NULL, &eltwise_164_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_159_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_157_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_159_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_159_weights, &conv2d_159_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_159_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_159_layer, 158,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA,
  &conv2d_159_chain,
  NULL, &eltwise_163_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(2, 2), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_SAME, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_157_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_156_output, &eltwise_154_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_157_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_157_layer, 157,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_157_chain,
  NULL, &conv2d_159_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_154_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_153_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_154_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_154_layer, 154,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_154_chain,
  NULL, &eltwise_157_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_153_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &nl_152_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_153_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_153_layer, 153,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_153_chain,
  NULL, &eltwise_154_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)


AI_STATIC_CONST ai_i8 nl_152_nl_params_data[] = { -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -127, -127, -127, -127, -127, -127, -127, -127, -127, -127, -127, -127, -126, -126, -126, -126, -126, -126, -125, -125, -125, -124, -124, -124, -123, -123, -123, -122, -121, -121, -120, -119, -119, -118, -117, -116, -115, -114, -112, -111, -109, -108, -106, -104, -102, -100, -97, -95, -92, -89, -86, -83, -80, -76, -72, -68, -64, -59, -54, -50, -45, -39, -34, -29, -23, -17, -12, -6, 0, 6, 12, 17, 23, 29, 34, 39, 45, 50, 54, 59, 64, 68, 72, 76, 80, 83, 86, 89, 92, 95, 97, 100, 102, 104, 106, 108, 109, 111, 112, 114, 115, 116, 117, 118, 119, 119, 120, 121, 121, 122, 123, 123, 123, 124, 124, 124, 125, 125, 125, 126, 126, 126, 126, 126, 126, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127 };
AI_ARRAY_OBJ_DECLARE(
    nl_152_nl_params, AI_ARRAY_FORMAT_S8,
    nl_152_nl_params_data, nl_152_nl_params_data, 256, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  nl_152_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_151_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_152_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  nl_152_layer, 152,
  NL_TYPE, 0x0, NULL,
  nl, forward_nl_integer,
  &nl_152_chain,
  NULL, &eltwise_153_layer, AI_STATIC, 
  .nl_params = &nl_152_nl_params, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_156_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_155_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_156_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_156_layer, 156,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_156_chain,
  NULL, &nl_152_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_155_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_151_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_155_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_155_layer, 155,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_155_chain,
  NULL, &eltwise_156_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_151_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &concat_150_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_151_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_151_weights, &conv2d_151_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_151_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_151_layer, 151,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA,
  &conv2d_151_chain,
  NULL, &eltwise_155_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  concat_150_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 4, &slice_118_output, &slice_119_output, &eltwise_134_output, &eltwise_149_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &concat_150_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  concat_150_layer, 150,
  CONCAT_TYPE, 0x0, NULL,
  concat, forward_concat,
  &concat_150_chain,
  NULL, &conv2d_151_layer, AI_STATIC, 
  .axis = AI_SHAPE_CHANNEL, 
)


AI_STATIC_CONST ai_u8 slice_118_axes_data[] = { 2 };
AI_ARRAY_OBJ_DECLARE(
    slice_118_axes, AI_ARRAY_FORMAT_U8,
    slice_118_axes_data, slice_118_axes_data, 1, AI_STATIC_CONST)

AI_STATIC_CONST ai_i16 slice_118_starts_data[] = { 0 };
AI_ARRAY_OBJ_DECLARE(
    slice_118_starts, AI_ARRAY_FORMAT_S16,
    slice_118_starts_data, slice_118_starts_data, 1, AI_STATIC_CONST)

AI_STATIC_CONST ai_i16 slice_118_ends_data[] = { 64 };
AI_ARRAY_OBJ_DECLARE(
    slice_118_ends, AI_ARRAY_FORMAT_S16,
    slice_118_ends_data, slice_118_ends_data, 1, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  slice_118_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_117_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &slice_118_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  slice_118_layer, 118,
  SLICE_TYPE, 0x0, NULL,
  slice, forward_slice,
  &slice_118_chain,
  NULL, &concat_150_layer, AI_STATIC, 
  .axes = &slice_118_axes, 
  .starts = &slice_118_starts, 
  .ends = &slice_118_ends, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_149_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_134_output, &eltwise_148_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_149_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_149_layer, 149,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_149_chain,
  NULL, &slice_118_layer, AI_STATIC, 
  .operation = ai_sum_f32, 
  .buffer_operation = ai_sum_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_148_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_147_output, &eltwise_145_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_148_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_148_layer, 148,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_148_chain,
  NULL, &eltwise_149_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_145_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_144_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_145_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_145_layer, 145,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_145_chain,
  NULL, &eltwise_148_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_144_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &nl_143_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_144_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_144_layer, 144,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_144_chain,
  NULL, &eltwise_145_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)


AI_STATIC_CONST ai_i8 nl_143_nl_params_data[] = { -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -127, -127, -127, -127, -127, -127, -127, -127, -126, -126, -126, -126, -125, -125, -125, -124, -124, -123, -122, -122, -121, -120, -119, -117, -116, -114, -113, -111, -108, -106, -103, -100, -97, -93, -89, -84, -79, -74, -68, -62, -55, -48, -41, -33, -25, -17, -8, 0, 8, 17, 25, 33, 41, 48, 55, 62, 68, 74, 79, 84, 89, 93, 97, 100, 103, 106, 108, 111, 113, 114, 116, 117, 119, 120, 121, 122, 122, 123, 124, 124, 125, 125, 125, 126, 126, 126, 126, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127 };
AI_ARRAY_OBJ_DECLARE(
    nl_143_nl_params, AI_ARRAY_FORMAT_S8,
    nl_143_nl_params_data, nl_143_nl_params_data, 256, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  nl_143_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_142_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_143_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  nl_143_layer, 143,
  NL_TYPE, 0x0, NULL,
  nl, forward_nl_integer,
  &nl_143_chain,
  NULL, &eltwise_144_layer, AI_STATIC, 
  .nl_params = &nl_143_nl_params, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_147_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_146_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_147_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_147_layer, 147,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_147_chain,
  NULL, &nl_143_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_146_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_142_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_146_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_146_layer, 146,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_146_chain,
  NULL, &eltwise_147_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_142_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_141_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_142_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_142_weights, &conv2d_142_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_142_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_142_layer, 142,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA,
  &conv2d_142_chain,
  NULL, &eltwise_146_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_SAME, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_141_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_140_output, &eltwise_138_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_141_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_141_layer, 141,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_141_chain,
  NULL, &conv2d_142_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_138_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_137_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_138_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_138_layer, 138,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_138_chain,
  NULL, &eltwise_141_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_137_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &nl_136_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_137_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_137_layer, 137,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_137_chain,
  NULL, &eltwise_138_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)


AI_STATIC_CONST ai_i8 nl_136_nl_params_data[] = { -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -127, -127, -127, -127, -127, -127, -127, -127, -127, -127, -127, -127, -126, -126, -126, -126, -126, -126, -125, -125, -125, -125, -124, -124, -123, -123, -123, -122, -122, -121, -120, -120, -119, -118, -117, -116, -115, -114, -113, -112, -110, -109, -107, -105, -103, -101, -99, -97, -94, -91, -88, -85, -82, -79, -75, -71, -67, -63, -58, -54, -49, -44, -39, -33, -28, -23, -17, -11, -6, 0, 6, 11, 17, 23, 28, 33, 39, 44, 49, 54, 58, 63, 67, 71, 75, 79, 82, 85, 88, 91, 94, 97, 99, 101, 103, 105, 107, 109, 110, 112, 113, 114, 115, 116, 117, 118, 119, 120, 120, 121, 122, 122, 123, 123, 123, 124, 124, 125, 125, 125, 125, 126, 126, 126, 126, 126, 126, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127 };
AI_ARRAY_OBJ_DECLARE(
    nl_136_nl_params, AI_ARRAY_FORMAT_S8,
    nl_136_nl_params_data, nl_136_nl_params_data, 256, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  nl_136_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_135_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_136_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  nl_136_layer, 136,
  NL_TYPE, 0x0, NULL,
  nl, forward_nl_integer,
  &nl_136_chain,
  NULL, &eltwise_137_layer, AI_STATIC, 
  .nl_params = &nl_136_nl_params, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_140_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_139_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_140_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_140_layer, 140,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_140_chain,
  NULL, &nl_136_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_139_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_135_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_139_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_139_layer, 139,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_139_chain,
  NULL, &eltwise_140_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_135_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_134_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_135_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_135_weights, &conv2d_135_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_135_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_135_layer, 135,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA,
  &conv2d_135_chain,
  NULL, &eltwise_139_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_SAME, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_134_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &slice_119_output, &eltwise_133_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_134_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_134_layer, 134,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_134_chain,
  NULL, &conv2d_135_layer, AI_STATIC, 
  .operation = ai_sum_f32, 
  .buffer_operation = ai_sum_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_133_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_132_output, &eltwise_130_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_133_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_133_layer, 133,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_133_chain,
  NULL, &eltwise_134_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_130_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_129_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_130_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_130_layer, 130,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_130_chain,
  NULL, &eltwise_133_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_129_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &nl_128_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_129_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_129_layer, 129,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_129_chain,
  NULL, &eltwise_130_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)


AI_STATIC_CONST ai_i8 nl_128_nl_params_data[] = { -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -127, -127, -127, -127, -127, -127, -127, -127, -127, -127, -127, -127, -127, -126, -126, -126, -126, -126, -126, -126, -125, -125, -125, -125, -124, -124, -124, -123, -123, -122, -122, -121, -121, -120, -120, -119, -118, -117, -117, -116, -115, -113, -112, -111, -110, -108, -107, -105, -103, -101, -99, -97, -95, -92, -90, -87, -84, -81, -78, -74, -71, -67, -63, -59, -54, -50, -46, -41, -36, -31, -26, -21, -16, -11, -5, 0, 5, 11, 16, 21, 26, 31, 36, 41, 46, 50, 54, 59, 63, 67, 71, 74, 78, 81, 84, 87, 90, 92, 95, 97, 99, 101, 103, 105, 107, 108, 110, 111, 112, 113, 115, 116, 117, 117, 118, 119, 120, 120, 121, 121, 122, 122, 123, 123, 124, 124, 124, 125, 125, 125, 125, 126, 126, 126, 126, 126, 126, 126, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127 };
AI_ARRAY_OBJ_DECLARE(
    nl_128_nl_params, AI_ARRAY_FORMAT_S8,
    nl_128_nl_params_data, nl_128_nl_params_data, 256, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  nl_128_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_127_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_128_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  nl_128_layer, 128,
  NL_TYPE, 0x0, NULL,
  nl, forward_nl_integer,
  &nl_128_chain,
  NULL, &eltwise_129_layer, AI_STATIC, 
  .nl_params = &nl_128_nl_params, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_132_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_131_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_132_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_132_layer, 132,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_132_chain,
  NULL, &nl_128_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_131_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_127_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_131_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_131_layer, 131,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_131_chain,
  NULL, &eltwise_132_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_127_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_126_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_127_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_127_weights, &conv2d_127_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_127_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_127_layer, 127,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA,
  &conv2d_127_chain,
  NULL, &eltwise_131_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_SAME, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_126_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_125_output, &eltwise_123_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_126_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_126_layer, 126,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_126_chain,
  NULL, &conv2d_127_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_123_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_122_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_123_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_123_layer, 123,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_123_chain,
  NULL, &eltwise_126_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_122_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &nl_121_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_122_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_122_layer, 122,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_122_chain,
  NULL, &eltwise_123_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)


AI_STATIC_CONST ai_i8 nl_121_nl_params_data[] = { -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -127, -127, -127, -127, -127, -127, -127, -127, -127, -127, -127, -127, -127, -126, -126, -126, -126, -126, -126, -126, -125, -125, -125, -125, -124, -124, -124, -123, -123, -123, -122, -122, -121, -121, -120, -119, -119, -118, -117, -116, -115, -114, -113, -112, -111, -110, -108, -107, -105, -103, -102, -100, -98, -95, -93, -91, -88, -85, -82, -79, -76, -72, -69, -65, -61, -57, -53, -49, -44, -40, -35, -30, -25, -20, -15, -10, -5, 0, 5, 10, 15, 20, 25, 30, 35, 40, 44, 49, 53, 57, 61, 65, 69, 72, 76, 79, 82, 85, 88, 91, 93, 95, 98, 100, 102, 103, 105, 107, 108, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 119, 120, 121, 121, 122, 122, 123, 123, 123, 124, 124, 124, 125, 125, 125, 125, 126, 126, 126, 126, 126, 126, 126, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127 };
AI_ARRAY_OBJ_DECLARE(
    nl_121_nl_params, AI_ARRAY_FORMAT_S8,
    nl_121_nl_params_data, nl_121_nl_params_data, 256, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  nl_121_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_120_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_121_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  nl_121_layer, 121,
  NL_TYPE, 0x0, NULL,
  nl, forward_nl_integer,
  &nl_121_chain,
  NULL, &eltwise_122_layer, AI_STATIC, 
  .nl_params = &nl_121_nl_params, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_125_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_124_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_125_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_125_layer, 125,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_125_chain,
  NULL, &nl_121_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_124_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_120_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_124_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_124_layer, 124,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_124_chain,
  NULL, &eltwise_125_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_120_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &slice_119_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_120_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_120_weights, &conv2d_120_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_120_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_120_layer, 120,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA,
  &conv2d_120_chain,
  NULL, &eltwise_124_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_SAME, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)


AI_STATIC_CONST ai_u8 slice_119_axes_data[] = { 2 };
AI_ARRAY_OBJ_DECLARE(
    slice_119_axes, AI_ARRAY_FORMAT_U8,
    slice_119_axes_data, slice_119_axes_data, 1, AI_STATIC_CONST)

AI_STATIC_CONST ai_i16 slice_119_starts_data[] = { 64 };
AI_ARRAY_OBJ_DECLARE(
    slice_119_starts, AI_ARRAY_FORMAT_S16,
    slice_119_starts_data, slice_119_starts_data, 1, AI_STATIC_CONST)

AI_STATIC_CONST ai_i16 slice_119_ends_data[] = { 128 };
AI_ARRAY_OBJ_DECLARE(
    slice_119_ends, AI_ARRAY_FORMAT_S16,
    slice_119_ends_data, slice_119_ends_data, 1, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  slice_119_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_117_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &slice_119_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  slice_119_layer, 119,
  SLICE_TYPE, 0x0, NULL,
  slice, forward_slice,
  &slice_119_chain,
  NULL, &conv2d_120_layer, AI_STATIC, 
  .axes = &slice_119_axes, 
  .starts = &slice_119_starts, 
  .ends = &slice_119_ends, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_117_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_116_output, &eltwise_114_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_117_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_117_layer, 117,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_117_chain,
  NULL, &slice_119_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_114_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_113_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_114_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_114_layer, 114,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_114_chain,
  NULL, &eltwise_117_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_113_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &nl_112_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_113_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_113_layer, 113,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_113_chain,
  NULL, &eltwise_114_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)


AI_STATIC_CONST ai_i8 nl_112_nl_params_data[] = { -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -127, -127, -127, -127, -127, -127, -127, -126, -126, -126, -125, -125, -124, -124, -123, -122, -121, -120, -119, -117, -115, -113, -111, -108, -105, -101, -97, -92, -86, -80, -74, -66, -58, -50, -40, -31, -21, -10, 0, 10, 21, 31, 40, 50, 58, 66, 74, 80, 86, 92, 97, 101, 105, 108, 111, 113, 115, 117, 119, 120, 121, 122, 123, 124, 124, 125, 125, 126, 126, 126, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127 };
AI_ARRAY_OBJ_DECLARE(
    nl_112_nl_params, AI_ARRAY_FORMAT_S8,
    nl_112_nl_params_data, nl_112_nl_params_data, 256, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  nl_112_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_111_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_112_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  nl_112_layer, 112,
  NL_TYPE, 0x0, NULL,
  nl, forward_nl_integer,
  &nl_112_chain,
  NULL, &eltwise_113_layer, AI_STATIC, 
  .nl_params = &nl_112_nl_params, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_116_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_115_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_116_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_116_layer, 116,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_116_chain,
  NULL, &nl_112_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_115_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_111_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_115_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_115_layer, 115,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_115_chain,
  NULL, &eltwise_116_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_111_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_110_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_111_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_111_weights, &conv2d_111_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_111_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_111_layer, 111,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA,
  &conv2d_111_chain,
  NULL, &eltwise_115_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_110_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_109_output, &eltwise_107_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_110_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_110_layer, 110,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_110_chain,
  NULL, &conv2d_111_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_107_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_106_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_107_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_107_layer, 107,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_107_chain,
  NULL, &eltwise_110_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_106_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &nl_105_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_106_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_106_layer, 106,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_106_chain,
  NULL, &eltwise_107_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)


AI_STATIC_CONST ai_i8 nl_105_nl_params_data[] = { -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -127, -127, -127, -127, -127, -127, -127, -127, -127, -127, -127, -127, -127, -126, -126, -126, -126, -126, -126, -126, -125, -125, -125, -125, -124, -124, -124, -123, -123, -123, -122, -122, -121, -121, -120, -119, -119, -118, -117, -116, -115, -114, -113, -112, -110, -109, -108, -106, -104, -102, -100, -98, -96, -94, -91, -89, -86, -83, -80, -77, -73, -70, -66, -62, -58, -54, -49, -45, -40, -36, -31, -26, -21, -16, -10, -5, 0, 5, 10, 16, 21, 26, 31, 36, 40, 45, 49, 54, 58, 62, 66, 70, 73, 77, 80, 83, 86, 89, 91, 94, 96, 98, 100, 102, 104, 106, 108, 109, 110, 112, 113, 114, 115, 116, 117, 118, 119, 119, 120, 121, 121, 122, 122, 123, 123, 123, 124, 124, 124, 125, 125, 125, 125, 126, 126, 126, 126, 126, 126, 126, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127 };
AI_ARRAY_OBJ_DECLARE(
    nl_105_nl_params, AI_ARRAY_FORMAT_S8,
    nl_105_nl_params_data, nl_105_nl_params_data, 256, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  nl_105_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_104_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_105_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  nl_105_layer, 105,
  NL_TYPE, 0x0, NULL,
  nl, forward_nl_integer,
  &nl_105_chain,
  NULL, &eltwise_106_layer, AI_STATIC, 
  .nl_params = &nl_105_nl_params, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_109_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_108_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_109_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_109_layer, 109,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_109_chain,
  NULL, &nl_105_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_108_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_104_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_108_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_108_layer, 108,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_108_chain,
  NULL, &eltwise_109_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_104_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_102_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_104_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_104_weights, &conv2d_104_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_104_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_104_layer, 103,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA,
  &conv2d_104_chain,
  NULL, &eltwise_108_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(2, 2), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_SAME, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_102_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_101_output, &eltwise_99_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_102_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_102_layer, 102,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_102_chain,
  NULL, &conv2d_104_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_99_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_98_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_99_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_99_layer, 99,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_99_chain,
  NULL, &eltwise_102_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_98_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &nl_97_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_98_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_98_layer, 98,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_98_chain,
  NULL, &eltwise_99_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)


AI_STATIC_CONST ai_i8 nl_97_nl_params_data[] = { -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -127, -127, -127, -127, -127, -127, -127, -127, -127, -127, -127, -127, -126, -126, -126, -126, -126, -125, -125, -125, -124, -124, -124, -123, -123, -122, -122, -121, -120, -120, -119, -118, -117, -116, -115, -114, -112, -111, -109, -107, -105, -103, -101, -98, -96, -93, -90, -87, -83, -80, -76, -71, -67, -62, -58, -53, -47, -42, -36, -30, -25, -19, -12, -6, 0, 6, 12, 19, 25, 30, 36, 42, 47, 53, 58, 62, 67, 71, 76, 80, 83, 87, 90, 93, 96, 98, 101, 103, 105, 107, 109, 111, 112, 114, 115, 116, 117, 118, 119, 120, 120, 121, 122, 122, 123, 123, 124, 124, 124, 125, 125, 125, 126, 126, 126, 126, 126, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127 };
AI_ARRAY_OBJ_DECLARE(
    nl_97_nl_params, AI_ARRAY_FORMAT_S8,
    nl_97_nl_params_data, nl_97_nl_params_data, 256, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  nl_97_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_96_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_97_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  nl_97_layer, 97,
  NL_TYPE, 0x0, NULL,
  nl, forward_nl_integer,
  &nl_97_chain,
  NULL, &eltwise_98_layer, AI_STATIC, 
  .nl_params = &nl_97_nl_params, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_101_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_100_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_101_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_101_layer, 101,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_101_chain,
  NULL, &nl_97_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_100_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_96_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_100_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_100_layer, 100,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_100_chain,
  NULL, &eltwise_101_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_96_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &concat_95_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_96_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_96_weights, &conv2d_96_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_96_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_96_layer, 96,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA,
  &conv2d_96_chain,
  NULL, &eltwise_100_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  concat_95_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 4, &slice_63_output, &slice_64_output, &eltwise_79_output, &eltwise_94_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &concat_95_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  concat_95_layer, 95,
  CONCAT_TYPE, 0x0, NULL,
  concat, forward_concat,
  &concat_95_chain,
  NULL, &conv2d_96_layer, AI_STATIC, 
  .axis = AI_SHAPE_CHANNEL, 
)


AI_STATIC_CONST ai_u8 slice_63_axes_data[] = { 2 };
AI_ARRAY_OBJ_DECLARE(
    slice_63_axes, AI_ARRAY_FORMAT_U8,
    slice_63_axes_data, slice_63_axes_data, 1, AI_STATIC_CONST)

AI_STATIC_CONST ai_i16 slice_63_starts_data[] = { 0 };
AI_ARRAY_OBJ_DECLARE(
    slice_63_starts, AI_ARRAY_FORMAT_S16,
    slice_63_starts_data, slice_63_starts_data, 1, AI_STATIC_CONST)

AI_STATIC_CONST ai_i16 slice_63_ends_data[] = { 32 };
AI_ARRAY_OBJ_DECLARE(
    slice_63_ends, AI_ARRAY_FORMAT_S16,
    slice_63_ends_data, slice_63_ends_data, 1, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  slice_63_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_62_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &slice_63_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  slice_63_layer, 63,
  SLICE_TYPE, 0x0, NULL,
  slice, forward_slice,
  &slice_63_chain,
  NULL, &concat_95_layer, AI_STATIC, 
  .axes = &slice_63_axes, 
  .starts = &slice_63_starts, 
  .ends = &slice_63_ends, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_94_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_79_output, &eltwise_93_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_94_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_94_layer, 94,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_94_chain,
  NULL, &slice_63_layer, AI_STATIC, 
  .operation = ai_sum_f32, 
  .buffer_operation = ai_sum_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_93_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_92_output, &eltwise_90_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_93_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_93_layer, 93,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_93_chain,
  NULL, &eltwise_94_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_90_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_89_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_90_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_90_layer, 90,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_90_chain,
  NULL, &eltwise_93_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_89_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &nl_88_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_89_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_89_layer, 89,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_89_chain,
  NULL, &eltwise_90_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)


AI_STATIC_CONST ai_i8 nl_88_nl_params_data[] = { -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -127, -127, -127, -127, -127, -127, -127, -127, -127, -127, -126, -126, -126, -126, -126, -125, -125, -125, -124, -124, -123, -123, -122, -122, -121, -120, -119, -118, -117, -116, -114, -113, -111, -109, -107, -105, -103, -100, -97, -94, -91, -87, -83, -79, -74, -70, -65, -59, -53, -47, -41, -35, -28, -21, -14, -7, 0, 7, 14, 21, 28, 35, 41, 47, 53, 59, 65, 70, 74, 79, 83, 87, 91, 94, 97, 100, 103, 105, 107, 109, 111, 113, 114, 116, 117, 118, 119, 120, 121, 122, 122, 123, 123, 124, 124, 125, 125, 125, 126, 126, 126, 126, 126, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127 };
AI_ARRAY_OBJ_DECLARE(
    nl_88_nl_params, AI_ARRAY_FORMAT_S8,
    nl_88_nl_params_data, nl_88_nl_params_data, 256, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  nl_88_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_87_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_88_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  nl_88_layer, 88,
  NL_TYPE, 0x0, NULL,
  nl, forward_nl_integer,
  &nl_88_chain,
  NULL, &eltwise_89_layer, AI_STATIC, 
  .nl_params = &nl_88_nl_params, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_92_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_91_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_92_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_92_layer, 92,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_92_chain,
  NULL, &nl_88_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_91_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_87_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_91_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_91_layer, 91,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_91_chain,
  NULL, &eltwise_92_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_87_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_86_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_87_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_87_weights, &conv2d_87_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_87_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_87_layer, 87,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA,
  &conv2d_87_chain,
  NULL, &eltwise_91_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_SAME, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_86_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_85_output, &eltwise_83_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_86_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_86_layer, 86,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_86_chain,
  NULL, &conv2d_87_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_83_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_82_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_83_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_83_layer, 83,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_83_chain,
  NULL, &eltwise_86_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_82_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &nl_81_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_82_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_82_layer, 82,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_82_chain,
  NULL, &eltwise_83_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)


AI_STATIC_CONST ai_i8 nl_81_nl_params_data[] = { -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -127, -127, -127, -127, -127, -127, -127, -127, -127, -127, -127, -127, -127, -127, -127, -127, -126, -126, -126, -126, -126, -126, -126, -126, -125, -125, -125, -125, -125, -124, -124, -124, -124, -123, -123, -123, -122, -122, -121, -121, -121, -120, -119, -119, -118, -118, -117, -116, -115, -115, -114, -113, -112, -111, -110, -108, -107, -106, -105, -103, -101, -100, -98, -96, -94, -92, -90, -88, -86, -83, -81, -78, -75, -72, -69, -66, -63, -60, -56, -53, -49, -45, -42, -38, -34, -30, -26, -21, -17, -13, -9, -4, 0, 4, 9, 13, 17, 21, 26, 30, 34, 38, 42, 45, 49, 53, 56, 60, 63, 66, 69, 72, 75, 78, 81, 83, 86, 88, 90, 92, 94, 96, 98, 100, 101, 103, 105, 106, 107, 108, 110, 111, 112, 113, 114, 115, 115, 116, 117, 118, 118, 119, 119, 120, 121, 121, 121, 122, 122, 123, 123, 123, 124, 124, 124, 124, 125, 125, 125, 125, 125, 126, 126, 126, 126, 126, 126, 126, 126, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127 };
AI_ARRAY_OBJ_DECLARE(
    nl_81_nl_params, AI_ARRAY_FORMAT_S8,
    nl_81_nl_params_data, nl_81_nl_params_data, 256, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  nl_81_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_80_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_81_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  nl_81_layer, 81,
  NL_TYPE, 0x0, NULL,
  nl, forward_nl_integer,
  &nl_81_chain,
  NULL, &eltwise_82_layer, AI_STATIC, 
  .nl_params = &nl_81_nl_params, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_85_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_84_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_85_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_85_layer, 85,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_85_chain,
  NULL, &nl_81_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_84_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_80_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_84_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_84_layer, 84,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_84_chain,
  NULL, &eltwise_85_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_80_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_79_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_80_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_80_weights, &conv2d_80_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_80_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_80_layer, 80,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA,
  &conv2d_80_chain,
  NULL, &eltwise_84_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_SAME, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_79_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &slice_64_output, &eltwise_78_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_79_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_79_layer, 79,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_79_chain,
  NULL, &conv2d_80_layer, AI_STATIC, 
  .operation = ai_sum_f32, 
  .buffer_operation = ai_sum_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_78_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_77_output, &eltwise_75_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_78_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_78_layer, 78,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_78_chain,
  NULL, &eltwise_79_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_75_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_74_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_75_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_75_layer, 75,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_75_chain,
  NULL, &eltwise_78_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_74_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &nl_73_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_74_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_74_layer, 74,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_74_chain,
  NULL, &eltwise_75_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)


AI_STATIC_CONST ai_i8 nl_73_nl_params_data[] = { -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -127, -127, -127, -127, -127, -127, -127, -127, -127, -127, -127, -127, -127, -127, -126, -126, -126, -126, -126, -126, -126, -125, -125, -125, -125, -124, -124, -124, -124, -123, -123, -123, -122, -122, -121, -121, -120, -119, -119, -118, -117, -116, -116, -115, -114, -113, -111, -110, -109, -108, -106, -104, -103, -101, -99, -97, -95, -93, -90, -88, -85, -82, -79, -76, -73, -70, -66, -63, -59, -55, -51, -47, -42, -38, -33, -29, -24, -19, -15, -10, -5, 0, 5, 10, 15, 19, 24, 29, 33, 38, 42, 47, 51, 55, 59, 63, 66, 70, 73, 76, 79, 82, 85, 88, 90, 93, 95, 97, 99, 101, 103, 104, 106, 108, 109, 110, 111, 113, 114, 115, 116, 116, 117, 118, 119, 119, 120, 121, 121, 122, 122, 123, 123, 123, 124, 124, 124, 124, 125, 125, 125, 125, 126, 126, 126, 126, 126, 126, 126, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127 };
AI_ARRAY_OBJ_DECLARE(
    nl_73_nl_params, AI_ARRAY_FORMAT_S8,
    nl_73_nl_params_data, nl_73_nl_params_data, 256, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  nl_73_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_72_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_73_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  nl_73_layer, 73,
  NL_TYPE, 0x0, NULL,
  nl, forward_nl_integer,
  &nl_73_chain,
  NULL, &eltwise_74_layer, AI_STATIC, 
  .nl_params = &nl_73_nl_params, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_77_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_76_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_77_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_77_layer, 77,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_77_chain,
  NULL, &nl_73_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_76_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_72_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_76_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_76_layer, 76,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_76_chain,
  NULL, &eltwise_77_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_72_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_71_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_72_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_72_weights, &conv2d_72_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_72_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_72_layer, 72,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA,
  &conv2d_72_chain,
  NULL, &eltwise_76_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_SAME, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_71_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_70_output, &eltwise_68_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_71_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_71_layer, 71,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_71_chain,
  NULL, &conv2d_72_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_68_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_67_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_68_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_68_layer, 68,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_68_chain,
  NULL, &eltwise_71_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_67_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &nl_66_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_67_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_67_layer, 67,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_67_chain,
  NULL, &eltwise_68_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)


AI_STATIC_CONST ai_i8 nl_66_nl_params_data[] = { -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -127, -127, -127, -127, -127, -127, -127, -127, -127, -127, -127, -127, -127, -127, -127, -126, -126, -126, -126, -126, -126, -126, -125, -125, -125, -125, -124, -124, -124, -124, -123, -123, -123, -122, -122, -121, -121, -120, -120, -119, -118, -118, -117, -116, -115, -114, -113, -112, -111, -110, -109, -107, -106, -104, -103, -101, -99, -97, -95, -93, -91, -88, -86, -83, -80, -77, -74, -71, -68, -64, -61, -57, -53, -49, -45, -41, -37, -32, -28, -23, -19, -14, -9, -5, 0, 5, 9, 14, 19, 23, 28, 32, 37, 41, 45, 49, 53, 57, 61, 64, 68, 71, 74, 77, 80, 83, 86, 88, 91, 93, 95, 97, 99, 101, 103, 104, 106, 107, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 118, 119, 120, 120, 121, 121, 122, 122, 123, 123, 123, 124, 124, 124, 124, 125, 125, 125, 125, 126, 126, 126, 126, 126, 126, 126, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127 };
AI_ARRAY_OBJ_DECLARE(
    nl_66_nl_params, AI_ARRAY_FORMAT_S8,
    nl_66_nl_params_data, nl_66_nl_params_data, 256, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  nl_66_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_65_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_66_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  nl_66_layer, 66,
  NL_TYPE, 0x0, NULL,
  nl, forward_nl_integer,
  &nl_66_chain,
  NULL, &eltwise_67_layer, AI_STATIC, 
  .nl_params = &nl_66_nl_params, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_70_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_69_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_70_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_70_layer, 70,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_70_chain,
  NULL, &nl_66_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_69_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_65_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_69_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_69_layer, 69,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_69_chain,
  NULL, &eltwise_70_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_65_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &slice_64_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_65_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_65_weights, &conv2d_65_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_65_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_65_layer, 65,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA,
  &conv2d_65_chain,
  NULL, &eltwise_69_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_SAME, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)


AI_STATIC_CONST ai_u8 slice_64_axes_data[] = { 2 };
AI_ARRAY_OBJ_DECLARE(
    slice_64_axes, AI_ARRAY_FORMAT_U8,
    slice_64_axes_data, slice_64_axes_data, 1, AI_STATIC_CONST)

AI_STATIC_CONST ai_i16 slice_64_starts_data[] = { 32 };
AI_ARRAY_OBJ_DECLARE(
    slice_64_starts, AI_ARRAY_FORMAT_S16,
    slice_64_starts_data, slice_64_starts_data, 1, AI_STATIC_CONST)

AI_STATIC_CONST ai_i16 slice_64_ends_data[] = { 64 };
AI_ARRAY_OBJ_DECLARE(
    slice_64_ends, AI_ARRAY_FORMAT_S16,
    slice_64_ends_data, slice_64_ends_data, 1, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  slice_64_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_62_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &slice_64_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  slice_64_layer, 64,
  SLICE_TYPE, 0x0, NULL,
  slice, forward_slice,
  &slice_64_chain,
  NULL, &conv2d_65_layer, AI_STATIC, 
  .axes = &slice_64_axes, 
  .starts = &slice_64_starts, 
  .ends = &slice_64_ends, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_62_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_61_output, &eltwise_59_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_62_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_62_layer, 62,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_62_chain,
  NULL, &slice_64_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_59_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_58_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_59_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_59_layer, 59,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_59_chain,
  NULL, &eltwise_62_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_58_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &nl_57_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_58_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_58_layer, 58,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_58_chain,
  NULL, &eltwise_59_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)


AI_STATIC_CONST ai_i8 nl_57_nl_params_data[] = { -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -127, -127, -127, -127, -127, -127, -127, -127, -127, -127, -127, -126, -126, -126, -126, -126, -126, -125, -125, -125, -124, -124, -124, -123, -123, -122, -121, -121, -120, -119, -118, -117, -116, -115, -114, -113, -111, -110, -108, -106, -104, -102, -99, -97, -94, -91, -88, -84, -80, -76, -72, -68, -63, -58, -53, -48, -42, -37, -31, -25, -19, -13, -6, 0, 6, 13, 19, 25, 31, 37, 42, 48, 53, 58, 63, 68, 72, 76, 80, 84, 88, 91, 94, 97, 99, 102, 104, 106, 108, 110, 111, 113, 114, 115, 116, 117, 118, 119, 120, 121, 121, 122, 123, 123, 124, 124, 124, 125, 125, 125, 126, 126, 126, 126, 126, 126, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127 };
AI_ARRAY_OBJ_DECLARE(
    nl_57_nl_params, AI_ARRAY_FORMAT_S8,
    nl_57_nl_params_data, nl_57_nl_params_data, 256, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  nl_57_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_56_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_57_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  nl_57_layer, 57,
  NL_TYPE, 0x0, NULL,
  nl, forward_nl_integer,
  &nl_57_chain,
  NULL, &eltwise_58_layer, AI_STATIC, 
  .nl_params = &nl_57_nl_params, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_61_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_60_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_61_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_61_layer, 61,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_61_chain,
  NULL, &nl_57_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_60_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_56_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_60_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_60_layer, 60,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_60_chain,
  NULL, &eltwise_61_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_56_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_55_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_56_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_56_weights, &conv2d_56_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_56_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_56_layer, 56,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA,
  &conv2d_56_chain,
  NULL, &eltwise_60_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_55_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_54_output, &eltwise_52_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_55_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_55_layer, 55,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_55_chain,
  NULL, &conv2d_56_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_52_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_51_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_52_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_52_layer, 52,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_52_chain,
  NULL, &eltwise_55_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_51_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &nl_50_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_51_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_51_layer, 51,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_51_chain,
  NULL, &eltwise_52_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)


AI_STATIC_CONST ai_i8 nl_50_nl_params_data[] = { -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -127, -127, -127, -127, -127, -127, -127, -127, -127, -127, -127, -127, -126, -126, -126, -126, -126, -126, -125, -125, -125, -125, -124, -124, -123, -123, -122, -122, -121, -121, -120, -119, -119, -118, -117, -116, -114, -113, -112, -110, -109, -107, -105, -103, -101, -99, -96, -94, -91, -88, -84, -81, -77, -73, -69, -65, -60, -56, -51, -46, -40, -35, -29, -24, -18, -12, -6, 0, 6, 12, 18, 24, 29, 35, 40, 46, 51, 56, 60, 65, 69, 73, 77, 81, 84, 88, 91, 94, 96, 99, 101, 103, 105, 107, 109, 110, 112, 113, 114, 116, 117, 118, 119, 119, 120, 121, 121, 122, 122, 123, 123, 124, 124, 125, 125, 125, 125, 126, 126, 126, 126, 126, 126, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127 };
AI_ARRAY_OBJ_DECLARE(
    nl_50_nl_params, AI_ARRAY_FORMAT_S8,
    nl_50_nl_params_data, nl_50_nl_params_data, 256, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  nl_50_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_49_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_50_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  nl_50_layer, 50,
  NL_TYPE, 0x0, NULL,
  nl, forward_nl_integer,
  &nl_50_chain,
  NULL, &eltwise_51_layer, AI_STATIC, 
  .nl_params = &nl_50_nl_params, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_54_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_53_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_54_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_54_layer, 54,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_54_chain,
  NULL, &nl_50_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_53_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_49_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_53_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_53_layer, 53,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_53_chain,
  NULL, &eltwise_54_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_49_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_47_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_49_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_49_weights, &conv2d_49_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_49_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_49_layer, 48,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA,
  &conv2d_49_chain,
  NULL, &eltwise_53_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(2, 2), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_SAME, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_47_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_46_output, &eltwise_44_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_47_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_47_layer, 47,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_47_chain,
  NULL, &conv2d_49_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_44_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_43_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_44_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_44_layer, 44,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_44_chain,
  NULL, &eltwise_47_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_43_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &nl_42_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_43_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_43_layer, 43,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_43_chain,
  NULL, &eltwise_44_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)


AI_STATIC_CONST ai_i8 nl_42_nl_params_data[] = { -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -127, -127, -127, -127, -127, -127, -127, -126, -126, -126, -126, -125, -125, -124, -124, -123, -122, -122, -121, -119, -118, -117, -115, -113, -111, -108, -106, -102, -99, -95, -90, -85, -80, -74, -67, -60, -53, -45, -36, -28, -19, -9, 0, 9, 19, 28, 36, 45, 53, 60, 67, 74, 80, 85, 90, 95, 99, 102, 106, 108, 111, 113, 115, 117, 118, 119, 121, 122, 122, 123, 124, 124, 125, 125, 126, 126, 126, 126, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127 };
AI_ARRAY_OBJ_DECLARE(
    nl_42_nl_params, AI_ARRAY_FORMAT_S8,
    nl_42_nl_params_data, nl_42_nl_params_data, 256, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  nl_42_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_41_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_42_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  nl_42_layer, 42,
  NL_TYPE, 0x0, NULL,
  nl, forward_nl_integer,
  &nl_42_chain,
  NULL, &eltwise_43_layer, AI_STATIC, 
  .nl_params = &nl_42_nl_params, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_46_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_45_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_46_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_46_layer, 46,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_46_chain,
  NULL, &nl_42_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_45_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_41_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_45_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_45_layer, 45,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_45_chain,
  NULL, &eltwise_46_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_41_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &concat_40_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_41_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_41_weights, &conv2d_41_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_41_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_41_layer, 41,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA,
  &conv2d_41_chain,
  NULL, &eltwise_45_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  concat_40_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &slice_39_output, &slice_23_output, &eltwise_38_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &concat_40_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  concat_40_layer, 40,
  CONCAT_TYPE, 0x0, NULL,
  concat, forward_concat,
  &concat_40_chain,
  NULL, &conv2d_41_layer, AI_STATIC, 
  .axis = AI_SHAPE_CHANNEL, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_38_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &slice_23_output, &eltwise_37_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_38_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_38_layer, 38,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_38_chain,
  NULL, &concat_40_layer, AI_STATIC, 
  .operation = ai_sum_f32, 
  .buffer_operation = ai_sum_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_37_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_36_output, &eltwise_34_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_37_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_37_layer, 37,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_37_chain,
  NULL, &eltwise_38_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_34_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_33_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_34_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_34_layer, 34,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_34_chain,
  NULL, &eltwise_37_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_33_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &nl_32_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_33_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_33_layer, 33,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_33_chain,
  NULL, &eltwise_34_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)


AI_STATIC_CONST ai_i8 nl_32_nl_params_data[] = { -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -127, -127, -127, -127, -126, -126, -125, -124, -123, -121, -119, -116, -113, -108, -103, -96, -87, -77, -64, -50, -35, -18, 0, 18, 35, 50, 64, 77, 87, 96, 103, 108, 113, 116, 119, 121, 123, 124, 125, 126, 126, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127 };
AI_ARRAY_OBJ_DECLARE(
    nl_32_nl_params, AI_ARRAY_FORMAT_S8,
    nl_32_nl_params_data, nl_32_nl_params_data, 256, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  nl_32_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_31_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_32_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  nl_32_layer, 32,
  NL_TYPE, 0x0, NULL,
  nl, forward_nl_integer,
  &nl_32_chain,
  NULL, &eltwise_33_layer, AI_STATIC, 
  .nl_params = &nl_32_nl_params, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_36_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_35_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_36_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_36_layer, 36,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_36_chain,
  NULL, &nl_32_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_35_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_31_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_35_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_35_layer, 35,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_35_chain,
  NULL, &eltwise_36_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_31_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_30_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_31_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_31_weights, &conv2d_31_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_31_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_31_layer, 31,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA,
  &conv2d_31_chain,
  NULL, &eltwise_35_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_SAME, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_30_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_29_output, &eltwise_27_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_30_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_30_layer, 30,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_30_chain,
  NULL, &conv2d_31_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_27_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_26_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_27_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_27_layer, 27,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_27_chain,
  NULL, &eltwise_30_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_26_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &nl_25_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_26_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_26_layer, 26,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_26_chain,
  NULL, &eltwise_27_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)


AI_STATIC_CONST ai_i8 nl_25_nl_params_data[] = { -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -127, -127, -127, -127, -126, -126, -125, -124, -123, -121, -119, -117, -113, -109, -103, -96, -88, -77, -65, -51, -35, -18, 0, 18, 35, 51, 65, 77, 88, 96, 103, 109, 113, 117, 119, 121, 123, 124, 125, 126, 126, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127 };
AI_ARRAY_OBJ_DECLARE(
    nl_25_nl_params, AI_ARRAY_FORMAT_S8,
    nl_25_nl_params_data, nl_25_nl_params_data, 256, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  nl_25_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_24_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_25_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  nl_25_layer, 25,
  NL_TYPE, 0x0, NULL,
  nl, forward_nl_integer,
  &nl_25_chain,
  NULL, &eltwise_26_layer, AI_STATIC, 
  .nl_params = &nl_25_nl_params, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_29_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_28_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_29_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_29_layer, 29,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_29_chain,
  NULL, &nl_25_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_28_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_24_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_28_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_28_layer, 28,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_28_chain,
  NULL, &eltwise_29_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_24_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &slice_23_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_24_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_24_weights, &conv2d_24_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_24_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_24_layer, 24,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA,
  &conv2d_24_chain,
  NULL, &eltwise_28_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_SAME, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)


AI_STATIC_CONST ai_u8 slice_23_axes_data[] = { 2 };
AI_ARRAY_OBJ_DECLARE(
    slice_23_axes, AI_ARRAY_FORMAT_U8,
    slice_23_axes_data, slice_23_axes_data, 1, AI_STATIC_CONST)

AI_STATIC_CONST ai_i16 slice_23_starts_data[] = { 16 };
AI_ARRAY_OBJ_DECLARE(
    slice_23_starts, AI_ARRAY_FORMAT_S16,
    slice_23_starts_data, slice_23_starts_data, 1, AI_STATIC_CONST)

AI_STATIC_CONST ai_i16 slice_23_ends_data[] = { 32 };
AI_ARRAY_OBJ_DECLARE(
    slice_23_ends, AI_ARRAY_FORMAT_S16,
    slice_23_ends_data, slice_23_ends_data, 1, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  slice_23_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_22_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &slice_23_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  slice_23_layer, 23,
  SLICE_TYPE, 0x0, NULL,
  slice, forward_slice,
  &slice_23_chain,
  NULL, &conv2d_24_layer, AI_STATIC, 
  .axes = &slice_23_axes, 
  .starts = &slice_23_starts, 
  .ends = &slice_23_ends, 
)


AI_STATIC_CONST ai_u8 slice_39_axes_data[] = { 2 };
AI_ARRAY_OBJ_DECLARE(
    slice_39_axes, AI_ARRAY_FORMAT_U8,
    slice_39_axes_data, slice_39_axes_data, 1, AI_STATIC_CONST)

AI_STATIC_CONST ai_i16 slice_39_starts_data[] = { 0 };
AI_ARRAY_OBJ_DECLARE(
    slice_39_starts, AI_ARRAY_FORMAT_S16,
    slice_39_starts_data, slice_39_starts_data, 1, AI_STATIC_CONST)

AI_STATIC_CONST ai_i16 slice_39_ends_data[] = { 16 };
AI_ARRAY_OBJ_DECLARE(
    slice_39_ends, AI_ARRAY_FORMAT_S16,
    slice_39_ends_data, slice_39_ends_data, 1, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  slice_39_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_22_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &slice_39_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  slice_39_layer, 39,
  SLICE_TYPE, 0x0, NULL,
  slice, forward_slice,
  &slice_39_chain,
  NULL, &slice_23_layer, AI_STATIC, 
  .axes = &slice_39_axes, 
  .starts = &slice_39_starts, 
  .ends = &slice_39_ends, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_22_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_21_output, &eltwise_19_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_22_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_22_layer, 22,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_22_chain,
  NULL, &slice_39_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_19_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_18_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_19_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_19_layer, 19,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_19_chain,
  NULL, &eltwise_22_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_18_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &nl_17_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_18_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_18_layer, 18,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_18_chain,
  NULL, &eltwise_19_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)


AI_STATIC_CONST ai_i8 nl_17_nl_params_data[] = { -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -127, -127, -126, -125, -123, -120, -114, -104, -88, -66, -35, 0, 35, 66, 88, 104, 114, 120, 123, 125, 126, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127 };
AI_ARRAY_OBJ_DECLARE(
    nl_17_nl_params, AI_ARRAY_FORMAT_S8,
    nl_17_nl_params_data, nl_17_nl_params_data, 256, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  nl_17_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_16_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_17_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  nl_17_layer, 17,
  NL_TYPE, 0x0, NULL,
  nl, forward_nl_integer,
  &nl_17_chain,
  NULL, &eltwise_18_layer, AI_STATIC, 
  .nl_params = &nl_17_nl_params, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_21_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_20_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_21_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_21_layer, 21,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_21_chain,
  NULL, &nl_17_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_20_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_16_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_20_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_20_layer, 20,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_20_chain,
  NULL, &eltwise_21_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_16_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_15_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_16_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_16_weights, &conv2d_16_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_16_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_16_layer, 16,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA,
  &conv2d_16_chain,
  NULL, &eltwise_20_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_15_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_14_output, &eltwise_12_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_15_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_15_layer, 15,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_15_chain,
  NULL, &conv2d_16_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_12_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_11_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_12_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_12_layer, 12,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_12_chain,
  NULL, &eltwise_15_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_11_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &nl_10_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_11_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_11_layer, 11,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_11_chain,
  NULL, &eltwise_12_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)


AI_STATIC_CONST ai_i8 nl_10_nl_params_data[] = { -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -127, -126, -122, -108, -70, 0, 70, 108, 122, 126, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127 };
AI_ARRAY_OBJ_DECLARE(
    nl_10_nl_params, AI_ARRAY_FORMAT_S8,
    nl_10_nl_params_data, nl_10_nl_params_data, 256, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  nl_10_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_9_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_10_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  nl_10_layer, 10,
  NL_TYPE, 0x0, NULL,
  nl, forward_nl_integer,
  &nl_10_chain,
  NULL, &eltwise_11_layer, AI_STATIC, 
  .nl_params = &nl_10_nl_params, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_14_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_13_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_14_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_14_layer, 14,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_14_chain,
  NULL, &nl_10_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_13_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_9_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_13_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_13_layer, 13,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_13_chain,
  NULL, &eltwise_14_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_9_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_7_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_9_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_9_weights, &conv2d_9_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_9_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_9_layer, 8,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA,
  &conv2d_9_chain,
  NULL, &eltwise_13_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(2, 2), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_SAME, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_7_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_6_output, &eltwise_4_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_7_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_7_layer, 7,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_7_chain,
  NULL, &conv2d_9_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_4_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_3_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_4_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_4_layer, 4,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_4_chain,
  NULL, &eltwise_7_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_3_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &nl_2_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_3_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_3_layer, 3,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_3_chain,
  NULL, &eltwise_4_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)


AI_STATIC_CONST ai_i8 nl_2_nl_params_data[] = { -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -127, -127, -126, -124, -122, -117, -110, -100, -84, -61, -33, 0, 33, 61, 84, 100, 110, 117, 122, 124, 126, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127 };
AI_ARRAY_OBJ_DECLARE(
    nl_2_nl_params, AI_ARRAY_FORMAT_S8,
    nl_2_nl_params_data, nl_2_nl_params_data, 256, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  nl_2_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_1_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_2_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  nl_2_layer, 2,
  NL_TYPE, 0x0, NULL,
  nl, forward_nl_integer,
  &nl_2_chain,
  NULL, &eltwise_3_layer, AI_STATIC, 
  .nl_params = &nl_2_nl_params, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_6_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_5_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_6_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_6_layer, 6,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_6_chain,
  NULL, &nl_2_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_5_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_1_output, &tfl_pseudo_qconst129_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_5_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_5_layer, 5,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_5_chain,
  NULL, &eltwise_6_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_1_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &serving_default_images0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_1_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_1_weights, &conv2d_1_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_1_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_1_layer, 0,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA,
  &conv2d_1_chain,
  NULL, &eltwise_5_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(2, 2), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_SAME, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)


#if (AI_TOOLS_API_VERSION < AI_TOOLS_API_VERSION_1_5)

AI_NETWORK_OBJ_DECLARE(
  AI_NET_OBJ_INSTANCE, AI_STATIC,
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 3035048, 1, 1),
    3035048, NULL, NULL),
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 819200, 1, 1),
    819200, NULL, NULL),
  AI_TENSOR_LIST_IO_OBJ_INIT(AI_FLAG_NONE, AI_YOLOV8_DETECTOR_IN_NUM, &serving_default_images0_output),
  AI_TENSOR_LIST_IO_OBJ_INIT(AI_FLAG_NONE, AI_YOLOV8_DETECTOR_OUT_NUM, &concat_482_output),
  &conv2d_1_layer, 0x0b5d00dc, NULL)

#else

AI_NETWORK_OBJ_DECLARE(
  AI_NET_OBJ_INSTANCE, AI_STATIC,
  AI_BUFFER_ARRAY_OBJ_INIT_STATIC(
  	AI_FLAG_NONE, 1,
    AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
      AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 3035048, 1, 1),
      3035048, NULL, NULL)
  ),
  AI_BUFFER_ARRAY_OBJ_INIT_STATIC(
  	AI_FLAG_NONE, 1,
    AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
      AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 819200, 1, 1),
      819200, NULL, NULL)
  ),
  AI_TENSOR_LIST_IO_OBJ_INIT(AI_FLAG_NONE, AI_YOLOV8_DETECTOR_IN_NUM, &serving_default_images0_output),
  AI_TENSOR_LIST_IO_OBJ_INIT(AI_FLAG_NONE, AI_YOLOV8_DETECTOR_OUT_NUM, &concat_482_output),
  &conv2d_1_layer, 0x0b5d00dc, NULL)

#endif	/*(AI_TOOLS_API_VERSION < AI_TOOLS_API_VERSION_1_5)*/



/******************************************************************************/
AI_DECLARE_STATIC
ai_bool yolov8_detector_configure_activations(
  ai_network* net_ctx, const ai_network_params* params)
{
  AI_ASSERT(net_ctx)

  if (ai_platform_get_activations_map(g_yolov8_detector_activations_map, 1, params)) {
    /* Updating activations (byte) offsets */
    
    serving_default_images0_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 410636);
    serving_default_images0_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 410636);
    conv2d_1_scratch0_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 409600);
    conv2d_1_scratch0_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 409600);
    conv2d_1_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 0);
    conv2d_1_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 0);
    eltwise_5_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 409600);
    eltwise_5_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 409600);
    eltwise_6_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 409600);
    eltwise_6_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 409600);
    nl_2_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 0);
    nl_2_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 0);
    eltwise_3_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 0);
    eltwise_3_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 0);
    eltwise_4_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 0);
    eltwise_4_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 0);
    eltwise_7_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 409600);
    eltwise_7_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 409600);
    conv2d_9_scratch0_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 0);
    conv2d_9_scratch0_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 0);
    conv2d_9_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 5824);
    conv2d_9_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 5824);
    eltwise_13_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 210624);
    eltwise_13_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 210624);
    eltwise_14_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 415424);
    eltwise_14_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 415424);
    nl_10_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 210624);
    nl_10_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 210624);
    eltwise_11_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 0);
    eltwise_11_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 0);
    eltwise_12_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 204800);
    eltwise_12_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 204800);
    eltwise_15_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 0);
    eltwise_15_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 0);
    conv2d_16_scratch0_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 204800);
    conv2d_16_scratch0_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 204800);
    conv2d_16_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 204928);
    conv2d_16_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 204928);
    eltwise_20_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 0);
    eltwise_20_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 0);
    eltwise_21_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 409728);
    eltwise_21_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 409728);
    nl_17_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 0);
    nl_17_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 0);
    eltwise_18_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 204800);
    eltwise_18_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 204800);
    eltwise_19_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 0);
    eltwise_19_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 0);
    eltwise_22_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 204800);
    eltwise_22_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 204800);
    slice_39_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 0);
    slice_39_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 0);
    slice_23_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 102400);
    slice_23_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 102400);
    conv2d_24_scratch0_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 204800);
    conv2d_24_scratch0_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 204800);
    conv2d_24_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 210048);
    conv2d_24_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 210048);
    eltwise_28_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 312448);
    eltwise_28_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 312448);
    eltwise_29_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 414848);
    eltwise_29_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 414848);
    nl_25_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 312448);
    nl_25_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 312448);
    eltwise_26_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 204800);
    eltwise_26_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 204800);
    eltwise_27_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 307200);
    eltwise_27_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 307200);
    eltwise_30_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 204800);
    eltwise_30_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 204800);
    conv2d_31_scratch0_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 307200);
    conv2d_31_scratch0_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 307200);
    conv2d_31_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 312448);
    conv2d_31_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 312448);
    eltwise_35_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 204800);
    eltwise_35_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 204800);
    eltwise_36_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 414848);
    eltwise_36_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 414848);
    nl_32_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 204800);
    nl_32_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 204800);
    eltwise_33_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 307200);
    eltwise_33_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 307200);
    eltwise_34_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 204800);
    eltwise_34_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 204800);
    eltwise_37_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 307200);
    eltwise_37_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 307200);
    eltwise_38_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 204800);
    eltwise_38_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 204800);
    concat_40_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 307200);
    concat_40_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 307200);
    conv2d_41_scratch0_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 0);
    conv2d_41_scratch0_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 0);
    conv2d_41_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 192);
    conv2d_41_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 192);
    eltwise_45_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 204992);
    eltwise_45_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 204992);
    eltwise_46_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 409792);
    eltwise_46_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 409792);
    nl_42_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 204992);
    nl_42_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 204992);
    eltwise_43_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 0);
    eltwise_43_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 0);
    eltwise_44_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 204800);
    eltwise_44_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 204800);
    eltwise_47_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 0);
    eltwise_47_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 0);
    conv2d_49_scratch0_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 204800);
    conv2d_49_scratch0_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 204800);
    conv2d_49_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 211328);
    conv2d_49_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 211328);
    eltwise_53_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 0);
    eltwise_53_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 0);
    eltwise_54_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 102400);
    eltwise_54_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 102400);
    nl_50_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 0);
    nl_50_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 0);
    eltwise_51_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 204800);
    eltwise_51_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 204800);
    eltwise_52_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 0);
    eltwise_52_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 0);
    eltwise_55_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 204800);
    eltwise_55_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 204800);
    conv2d_56_scratch0_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 0);
    conv2d_56_scratch0_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 0);
    conv2d_56_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 256);
    conv2d_56_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 256);
    eltwise_60_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 102656);
    eltwise_60_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 102656);
    eltwise_61_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 205056);
    eltwise_61_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 205056);
    nl_57_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 102656);
    nl_57_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 102656);
    eltwise_58_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 0);
    eltwise_58_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 0);
    eltwise_59_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 102400);
    eltwise_59_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 102400);
    eltwise_62_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 0);
    eltwise_62_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 0);
    slice_64_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 102400);
    slice_64_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 102400);
    conv2d_65_scratch0_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 153600);
    conv2d_65_scratch0_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 153600);
    conv2d_65_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 160000);
    conv2d_65_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 160000);
    eltwise_69_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 211200);
    eltwise_69_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 211200);
    eltwise_70_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 262400);
    eltwise_70_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 262400);
    nl_66_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 211200);
    nl_66_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 211200);
    eltwise_67_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 153600);
    eltwise_67_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 153600);
    eltwise_68_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 204800);
    eltwise_68_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 204800);
    eltwise_71_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 153600);
    eltwise_71_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 153600);
    conv2d_72_scratch0_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 204800);
    conv2d_72_scratch0_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 204800);
    conv2d_72_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 211200);
    conv2d_72_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 211200);
    eltwise_76_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 153600);
    eltwise_76_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 153600);
    eltwise_77_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 262400);
    eltwise_77_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 262400);
    nl_73_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 153600);
    nl_73_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 153600);
    eltwise_74_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 204800);
    eltwise_74_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 204800);
    eltwise_75_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 153600);
    eltwise_75_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 153600);
    eltwise_78_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 204800);
    eltwise_78_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 204800);
    eltwise_79_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 153600);
    eltwise_79_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 153600);
    conv2d_80_scratch0_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 204800);
    conv2d_80_scratch0_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 204800);
    conv2d_80_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 211200);
    conv2d_80_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 211200);
    eltwise_84_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 262400);
    eltwise_84_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 262400);
    eltwise_85_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 313600);
    eltwise_85_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 313600);
    nl_81_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 262400);
    nl_81_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 262400);
    eltwise_82_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 204800);
    eltwise_82_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 204800);
    eltwise_83_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 256000);
    eltwise_83_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 256000);
    eltwise_86_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 204800);
    eltwise_86_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 204800);
    conv2d_87_scratch0_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 256000);
    conv2d_87_scratch0_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 256000);
    conv2d_87_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 262400);
    conv2d_87_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 262400);
    eltwise_91_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 204800);
    eltwise_91_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 204800);
    eltwise_92_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 313600);
    eltwise_92_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 313600);
    nl_88_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 204800);
    nl_88_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 204800);
    eltwise_89_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 256000);
    eltwise_89_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 256000);
    eltwise_90_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 204800);
    eltwise_90_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 204800);
    eltwise_93_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 256000);
    eltwise_93_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 256000);
    eltwise_94_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 204800);
    eltwise_94_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 204800);
    slice_63_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 256000);
    slice_63_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 256000);
    concat_95_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 307200);
    concat_95_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 307200);
    conv2d_96_scratch0_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 0);
    conv2d_96_scratch0_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 0);
    conv2d_96_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 512);
    conv2d_96_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 512);
    eltwise_100_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 102912);
    eltwise_100_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 102912);
    eltwise_101_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 205312);
    eltwise_101_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 205312);
    nl_97_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 102912);
    nl_97_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 102912);
    eltwise_98_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 0);
    eltwise_98_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 0);
    eltwise_99_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 102400);
    eltwise_99_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 102400);
    eltwise_102_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 0);
    eltwise_102_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 0);
    conv2d_104_scratch0_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 102400);
    conv2d_104_scratch0_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 102400);
    conv2d_104_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 110336);
    conv2d_104_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 110336);
    eltwise_108_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 161536);
    eltwise_108_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 161536);
    eltwise_109_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 212736);
    eltwise_109_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 212736);
    nl_105_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 161536);
    nl_105_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 161536);
    eltwise_106_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 102400);
    eltwise_106_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 102400);
    eltwise_107_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 153600);
    eltwise_107_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 153600);
    eltwise_110_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 102400);
    eltwise_110_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 102400);
    conv2d_111_scratch0_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 153600);
    conv2d_111_scratch0_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 153600);
    conv2d_111_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 154112);
    conv2d_111_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 154112);
    eltwise_115_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 102400);
    eltwise_115_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 102400);
    eltwise_116_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 205312);
    eltwise_116_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 205312);
    nl_112_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 102400);
    nl_112_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 102400);
    eltwise_113_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 153600);
    eltwise_113_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 153600);
    eltwise_114_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 102400);
    eltwise_114_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 102400);
    eltwise_117_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 153600);
    eltwise_117_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 153600);
    slice_119_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 102400);
    slice_119_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 102400);
    conv2d_120_scratch0_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 128000);
    conv2d_120_scratch0_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 128000);
    conv2d_120_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 204800);
    conv2d_120_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 204800);
    eltwise_124_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 128000);
    eltwise_124_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 128000);
    eltwise_125_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 230400);
    eltwise_125_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 230400);
    nl_121_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 128000);
    nl_121_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 128000);
    eltwise_122_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 204800);
    eltwise_122_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 204800);
    eltwise_123_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 128000);
    eltwise_123_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 128000);
    eltwise_126_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 204800);
    eltwise_126_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 204800);
    conv2d_127_scratch0_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 128000);
    conv2d_127_scratch0_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 128000);
    conv2d_127_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 230400);
    conv2d_127_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 230400);
    eltwise_131_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 128000);
    eltwise_131_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 128000);
    eltwise_132_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 204800);
    eltwise_132_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 204800);
    nl_128_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 128000);
    nl_128_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 128000);
    eltwise_129_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 230400);
    eltwise_129_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 230400);
    eltwise_130_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 128000);
    eltwise_130_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 128000);
    eltwise_133_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 230400);
    eltwise_133_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 230400);
    eltwise_134_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 128000);
    eltwise_134_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 128000);
    conv2d_135_scratch0_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 204800);
    conv2d_135_scratch0_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 204800);
    conv2d_135_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 212480);
    conv2d_135_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 212480);
    eltwise_139_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 238080);
    eltwise_139_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 238080);
    eltwise_140_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 263680);
    eltwise_140_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 263680);
    nl_136_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 238080);
    nl_136_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 238080);
    eltwise_137_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 204800);
    eltwise_137_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 204800);
    eltwise_138_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 230400);
    eltwise_138_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 230400);
    eltwise_141_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 204800);
    eltwise_141_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 204800);
    conv2d_142_scratch0_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 230400);
    conv2d_142_scratch0_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 230400);
    conv2d_142_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 238080);
    conv2d_142_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 238080);
    eltwise_146_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 204800);
    eltwise_146_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 204800);
    eltwise_147_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 263680);
    eltwise_147_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 263680);
    nl_143_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 204800);
    nl_143_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 204800);
    eltwise_144_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 230400);
    eltwise_144_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 230400);
    eltwise_145_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 204800);
    eltwise_145_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 204800);
    eltwise_148_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 230400);
    eltwise_148_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 230400);
    eltwise_149_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 204800);
    eltwise_149_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 204800);
    slice_118_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 230400);
    slice_118_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 230400);
    concat_150_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 256000);
    concat_150_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 256000);
    conv2d_151_scratch0_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 102400);
    conv2d_151_scratch0_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 102400);
    conv2d_151_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 103424);
    conv2d_151_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 103424);
    eltwise_155_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 154624);
    eltwise_155_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 154624);
    eltwise_156_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 205824);
    eltwise_156_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 205824);
    nl_152_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 154624);
    nl_152_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 154624);
    eltwise_153_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 102400);
    eltwise_153_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 102400);
    eltwise_154_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 153600);
    eltwise_154_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 153600);
    eltwise_157_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 102400);
    eltwise_157_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 102400);
    conv2d_159_scratch0_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 153600);
    conv2d_159_scratch0_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 153600);
    conv2d_159_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 164352);
    conv2d_159_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 164352);
    eltwise_163_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 189952);
    eltwise_163_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 189952);
    eltwise_164_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 215552);
    eltwise_164_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 215552);
    nl_160_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 189952);
    nl_160_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 189952);
    eltwise_161_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 153600);
    eltwise_161_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 153600);
    eltwise_162_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 179200);
    eltwise_162_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 179200);
    eltwise_165_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 153600);
    eltwise_165_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 153600);
    conv2d_166_scratch0_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 179200);
    conv2d_166_scratch0_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 179200);
    conv2d_166_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 180224);
    conv2d_166_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 180224);
    eltwise_170_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 153600);
    eltwise_170_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 153600);
    eltwise_171_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 205824);
    eltwise_171_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 205824);
    nl_167_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 153600);
    nl_167_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 153600);
    eltwise_168_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 179200);
    eltwise_168_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 179200);
    eltwise_169_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 153600);
    eltwise_169_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 153600);
    eltwise_172_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 179200);
    eltwise_172_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 179200);
    slice_174_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 153600);
    slice_174_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 153600);
    conv2d_175_scratch0_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 166400);
    conv2d_175_scratch0_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 166400);
    conv2d_175_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 204800);
    conv2d_175_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 204800);
    eltwise_179_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 166400);
    eltwise_179_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 166400);
    eltwise_180_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 217600);
    eltwise_180_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 217600);
    nl_176_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 166400);
    nl_176_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 166400);
    eltwise_177_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 204800);
    eltwise_177_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 204800);
    eltwise_178_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 166400);
    eltwise_178_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 166400);
    eltwise_181_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 204800);
    eltwise_181_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 204800);
    conv2d_182_scratch0_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 166400);
    conv2d_182_scratch0_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 166400);
    conv2d_182_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 217600);
    conv2d_182_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 217600);
    eltwise_186_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 166400);
    eltwise_186_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 166400);
    eltwise_187_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 204800);
    eltwise_187_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 204800);
    nl_183_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 166400);
    nl_183_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 166400);
    eltwise_184_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 217600);
    eltwise_184_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 217600);
    eltwise_185_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 166400);
    eltwise_185_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 166400);
    eltwise_188_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 217600);
    eltwise_188_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 217600);
    eltwise_189_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 166400);
    eltwise_189_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 166400);
    slice_173_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 204800);
    slice_173_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 204800);
    concat_190_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 217600);
    concat_190_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 217600);
    conv2d_191_scratch0_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 153600);
    conv2d_191_scratch0_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 153600);
    conv2d_191_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 155136);
    conv2d_191_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 155136);
    eltwise_195_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 180736);
    eltwise_195_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 180736);
    eltwise_196_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 206336);
    eltwise_196_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 206336);
    nl_192_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 180736);
    nl_192_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 180736);
    eltwise_193_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 153600);
    eltwise_193_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 153600);
    eltwise_194_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 179200);
    eltwise_194_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 179200);
    eltwise_197_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 153600);
    eltwise_197_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 153600);
    conv2d_198_scratch0_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 179200);
    conv2d_198_scratch0_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 179200);
    conv2d_198_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 180224);
    conv2d_198_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 180224);
    eltwise_202_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 153600);
    eltwise_202_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 153600);
    eltwise_203_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 166400);
    eltwise_203_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 166400);
    nl_199_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 153600);
    nl_199_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 153600);
    eltwise_200_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 179200);
    eltwise_200_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 179200);
    eltwise_201_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 153600);
    eltwise_201_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 153600);
    eltwise_204_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 179200);
    eltwise_204_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 179200);
    pool_205_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 153600);
    pool_205_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 153600);
    pool_206_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 166400);
    pool_206_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 166400);
    pool_207_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 192000);
    pool_207_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 192000);
    concat_208_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 204800);
    concat_208_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 204800);
    conv2d_209_scratch0_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 153600);
    conv2d_209_scratch0_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 153600);
    conv2d_209_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 155648);
    conv2d_209_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 155648);
    eltwise_213_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 181248);
    eltwise_213_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 181248);
    eltwise_214_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 206848);
    eltwise_214_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 206848);
    nl_210_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 181248);
    nl_210_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 181248);
    eltwise_211_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 153600);
    eltwise_211_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 153600);
    eltwise_212_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 179200);
    eltwise_212_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 179200);
    eltwise_215_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 153600);
    eltwise_215_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 153600);
    conversion_216_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 179200);
    conversion_216_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 179200);
    resize_217_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 204800);
    resize_217_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 204800);
    concat_218_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 307200);
    concat_218_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 307200);
    conv2d_219_scratch0_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 102400);
    conv2d_219_scratch0_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 102400);
    conv2d_219_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 179200);
    conv2d_219_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 179200);
    eltwise_223_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 102400);
    eltwise_223_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 102400);
    eltwise_224_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 230400);
    eltwise_224_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 230400);
    nl_220_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 102400);
    nl_220_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 102400);
    eltwise_221_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 179200);
    eltwise_221_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 179200);
    eltwise_222_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 102400);
    eltwise_222_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 102400);
    eltwise_225_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 179200);
    eltwise_225_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 179200);
    slice_227_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 102400);
    slice_227_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 102400);
    conv2d_228_scratch0_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 128000);
    conv2d_228_scratch0_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 128000);
    conv2d_228_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 230400);
    conv2d_228_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 230400);
    eltwise_232_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 128000);
    eltwise_232_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 128000);
    eltwise_233_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 256000);
    eltwise_233_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 256000);
    nl_229_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 128000);
    nl_229_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 128000);
    eltwise_230_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 230400);
    eltwise_230_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 230400);
    eltwise_231_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 128000);
    eltwise_231_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 128000);
    eltwise_234_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 230400);
    eltwise_234_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 230400);
    conv2d_235_scratch0_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 128000);
    conv2d_235_scratch0_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 128000);
    conv2d_235_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 256000);
    conv2d_235_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 256000);
    eltwise_239_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 128000);
    eltwise_239_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 128000);
    eltwise_240_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 230400);
    eltwise_240_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 230400);
    nl_236_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 128000);
    nl_236_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 128000);
    eltwise_237_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 256000);
    eltwise_237_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 256000);
    eltwise_238_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 128000);
    eltwise_238_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 128000);
    eltwise_241_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 256000);
    eltwise_241_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 256000);
    slice_226_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 128000);
    slice_226_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 128000);
    concat_242_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 179200);
    concat_242_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 179200);
    conv2d_243_scratch0_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 102400);
    conv2d_243_scratch0_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 102400);
    conv2d_243_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 256000);
    conv2d_243_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 256000);
    eltwise_247_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 102400);
    eltwise_247_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 102400);
    eltwise_248_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 179200);
    eltwise_248_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 179200);
    nl_244_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 102400);
    nl_244_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 102400);
    eltwise_245_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 230400);
    eltwise_245_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 230400);
    eltwise_246_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 102400);
    eltwise_246_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 102400);
    eltwise_249_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 230400);
    eltwise_249_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 230400);
    conversion_250_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 102400);
    conversion_250_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 102400);
    resize_251_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 281600);
    resize_251_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 281600);
    concat_252_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 486400);
    concat_252_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 486400);
    conv2d_253_scratch0_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 0);
    conv2d_253_scratch0_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 0);
    conv2d_253_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 768);
    conv2d_253_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 768);
    eltwise_257_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 281600);
    eltwise_257_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 281600);
    eltwise_258_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 384000);
    eltwise_258_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 384000);
    nl_254_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 281600);
    nl_254_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 281600);
    eltwise_255_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 0);
    eltwise_255_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 0);
    eltwise_256_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 281600);
    eltwise_256_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 281600);
    eltwise_259_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 0);
    eltwise_259_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 0);
    slice_261_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 102400);
    slice_261_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 102400);
    conv2d_262_scratch0_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 179200);
    conv2d_262_scratch0_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 179200);
    conv2d_262_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 281600);
    conv2d_262_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 281600);
    eltwise_266_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 179200);
    eltwise_266_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 179200);
    eltwise_267_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 332800);
    eltwise_267_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 332800);
    nl_263_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 179200);
    nl_263_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 179200);
    eltwise_264_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 281600);
    eltwise_264_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 281600);
    eltwise_265_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 179200);
    eltwise_265_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 179200);
    eltwise_268_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 281600);
    eltwise_268_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 281600);
    conv2d_269_scratch0_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 179200);
    conv2d_269_scratch0_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 179200);
    conv2d_269_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 332800);
    conv2d_269_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 332800);
    eltwise_273_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 179200);
    eltwise_273_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 179200);
    eltwise_274_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 281600);
    eltwise_274_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 281600);
    nl_270_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 179200);
    nl_270_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 179200);
    eltwise_271_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 332800);
    eltwise_271_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 332800);
    eltwise_272_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 179200);
    eltwise_272_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 179200);
    eltwise_275_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 332800);
    eltwise_275_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 332800);
    slice_260_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 179200);
    slice_260_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 179200);
    concat_276_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 384000);
    concat_276_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 384000);
    conv2d_277_scratch0_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 0);
    conv2d_277_scratch0_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 0);
    conv2d_277_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 384);
    conv2d_277_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 384);
    eltwise_281_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 281600);
    eltwise_281_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 281600);
    eltwise_282_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 384000);
    eltwise_282_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 384000);
    nl_278_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 281600);
    nl_278_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 281600);
    eltwise_279_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 0);
    eltwise_279_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 0);
    eltwise_280_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 281600);
    eltwise_280_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 281600);
    eltwise_283_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 0);
    eltwise_283_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 0);
    conv2d_285_scratch0_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 102400);
    conv2d_285_scratch0_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 102400);
    conv2d_285_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 110080);
    conv2d_285_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 110080);
    eltwise_289_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 179200);
    eltwise_289_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 179200);
    eltwise_290_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 204800);
    eltwise_290_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 204800);
    nl_286_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 179200);
    nl_286_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 179200);
    eltwise_287_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 102400);
    eltwise_287_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 102400);
    eltwise_288_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 128000);
    eltwise_288_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 128000);
    eltwise_291_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 102400);
    eltwise_291_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 102400);
    concat_292_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 281600);
    concat_292_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 281600);
    conv2d_293_scratch0_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 102400);
    conv2d_293_scratch0_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 102400);
    conv2d_293_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 179200);
    conv2d_293_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 179200);
    eltwise_297_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 102400);
    eltwise_297_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 102400);
    eltwise_298_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 230400);
    eltwise_298_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 230400);
    nl_294_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 102400);
    nl_294_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 102400);
    eltwise_295_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 179200);
    eltwise_295_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 179200);
    eltwise_296_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 102400);
    eltwise_296_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 102400);
    eltwise_299_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 179200);
    eltwise_299_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 179200);
    slice_301_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 102400);
    slice_301_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 102400);
    conv2d_302_scratch0_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 128000);
    conv2d_302_scratch0_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 128000);
    conv2d_302_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 230400);
    conv2d_302_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 230400);
    eltwise_306_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 128000);
    eltwise_306_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 128000);
    eltwise_307_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 256000);
    eltwise_307_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 256000);
    nl_303_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 128000);
    nl_303_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 128000);
    eltwise_304_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 230400);
    eltwise_304_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 230400);
    eltwise_305_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 128000);
    eltwise_305_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 128000);
    eltwise_308_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 230400);
    eltwise_308_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 230400);
    conv2d_309_scratch0_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 128000);
    conv2d_309_scratch0_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 128000);
    conv2d_309_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 256000);
    conv2d_309_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 256000);
    eltwise_313_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 128000);
    eltwise_313_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 128000);
    eltwise_314_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 230400);
    eltwise_314_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 230400);
    nl_310_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 128000);
    nl_310_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 128000);
    eltwise_311_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 256000);
    eltwise_311_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 256000);
    eltwise_312_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 128000);
    eltwise_312_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 128000);
    eltwise_315_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 256000);
    eltwise_315_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 256000);
    slice_300_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 128000);
    slice_300_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 128000);
    concat_316_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 179200);
    concat_316_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 179200);
    conv2d_317_scratch0_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 102400);
    conv2d_317_scratch0_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 102400);
    conv2d_317_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 256000);
    conv2d_317_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 256000);
    eltwise_321_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 102400);
    eltwise_321_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 102400);
    eltwise_322_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 179200);
    eltwise_322_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 179200);
    nl_318_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 102400);
    nl_318_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 102400);
    eltwise_319_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 230400);
    eltwise_319_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 230400);
    eltwise_320_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 102400);
    eltwise_320_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 102400);
    eltwise_323_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 230400);
    eltwise_323_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 230400);
    conv2d_325_scratch0_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 102400);
    conv2d_325_scratch0_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 102400);
    conv2d_325_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 112640);
    conv2d_325_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 112640);
    eltwise_329_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 125440);
    eltwise_329_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 125440);
    eltwise_330_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 138240);
    eltwise_330_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 138240);
    nl_326_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 125440);
    nl_326_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 125440);
    eltwise_327_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 102400);
    eltwise_327_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 102400);
    eltwise_328_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 115200);
    eltwise_328_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 115200);
    eltwise_331_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 102400);
    eltwise_331_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 102400);
    concat_332_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 115200);
    concat_332_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 115200);
    conv2d_333_scratch0_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 102400);
    conv2d_333_scratch0_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 102400);
    conv2d_333_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 153600);
    conv2d_333_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 153600);
    eltwise_337_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 102400);
    eltwise_337_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 102400);
    eltwise_338_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 128000);
    eltwise_338_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 128000);
    nl_334_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 102400);
    nl_334_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 102400);
    eltwise_335_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 153600);
    eltwise_335_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 153600);
    eltwise_336_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 102400);
    eltwise_336_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 102400);
    eltwise_339_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 153600);
    eltwise_339_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 153600);
    slice_341_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 102400);
    slice_341_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 102400);
    conv2d_342_scratch0_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 115200);
    conv2d_342_scratch0_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 115200);
    conv2d_342_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 125440);
    conv2d_342_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 125440);
    eltwise_346_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 138240);
    eltwise_346_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 138240);
    eltwise_347_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 179200);
    eltwise_347_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 179200);
    nl_343_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 138240);
    nl_343_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 138240);
    eltwise_344_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 115200);
    eltwise_344_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 115200);
    eltwise_345_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 128000);
    eltwise_345_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 128000);
    eltwise_348_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 115200);
    eltwise_348_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 115200);
    conv2d_349_scratch0_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 128000);
    conv2d_349_scratch0_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 128000);
    conv2d_349_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 138240);
    conv2d_349_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 138240);
    eltwise_353_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 115200);
    eltwise_353_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 115200);
    eltwise_354_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 179200);
    eltwise_354_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 179200);
    nl_350_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 115200);
    nl_350_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 115200);
    eltwise_351_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 128000);
    eltwise_351_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 128000);
    eltwise_352_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 115200);
    eltwise_352_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 115200);
    eltwise_355_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 128000);
    eltwise_355_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 128000);
    slice_340_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 115200);
    slice_340_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 115200);
    concat_356_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 140800);
    concat_356_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 140800);
    conv2d_357_scratch0_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 102400);
    conv2d_357_scratch0_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 102400);
    conv2d_357_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 103936);
    conv2d_357_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 103936);
    eltwise_361_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 129536);
    eltwise_361_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 129536);
    eltwise_362_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 155136);
    eltwise_362_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 155136);
    nl_358_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 129536);
    nl_358_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 129536);
    eltwise_359_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 102400);
    eltwise_359_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 102400);
    eltwise_360_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 128000);
    eltwise_360_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 128000);
    eltwise_363_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 102400);
    eltwise_363_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 102400);
    conv2d_379_scratch0_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 128000);
    conv2d_379_scratch0_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 128000);
    conv2d_379_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 142592);
    conv2d_379_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 142592);
    eltwise_383_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 128000);
    eltwise_383_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 128000);
    eltwise_384_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 134400);
    eltwise_384_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 134400);
    nl_380_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 128000);
    nl_380_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 128000);
    eltwise_381_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 140800);
    eltwise_381_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 140800);
    eltwise_382_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 128000);
    eltwise_382_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 128000);
    eltwise_385_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 140800);
    eltwise_385_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 140800);
    conv2d_386_scratch0_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 128000);
    conv2d_386_scratch0_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 128000);
    conv2d_386_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 147200);
    conv2d_386_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 147200);
    eltwise_390_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 128000);
    eltwise_390_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 128000);
    eltwise_391_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 134400);
    eltwise_391_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 134400);
    nl_387_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 128000);
    nl_387_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 128000);
    eltwise_388_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 140800);
    eltwise_388_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 140800);
    eltwise_389_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 128000);
    eltwise_389_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 128000);
    eltwise_392_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 140800);
    eltwise_392_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 140800);
    conv2d_393_scratch0_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 128000);
    conv2d_393_scratch0_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 128000);
    conv2d_393_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 128256);
    conv2d_393_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 128256);
    conv2d_364_scratch0_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 128556);
    conv2d_364_scratch0_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 128556);
    conv2d_364_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 143148);
    conv2d_364_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 143148);
    eltwise_368_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 102400);
    eltwise_368_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 102400);
    eltwise_369_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 108800);
    eltwise_369_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 108800);
    nl_365_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 102400);
    nl_365_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 102400);
    eltwise_366_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 115200);
    eltwise_366_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 115200);
    eltwise_367_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 102400);
    eltwise_367_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 102400);
    eltwise_370_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 115200);
    eltwise_370_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 115200);
    conv2d_371_scratch0_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 102400);
    conv2d_371_scratch0_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 102400);
    conv2d_371_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 121600);
    conv2d_371_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 121600);
    eltwise_375_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 102400);
    eltwise_375_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 102400);
    eltwise_376_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 108800);
    eltwise_376_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 108800);
    nl_372_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 102400);
    nl_372_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 102400);
    eltwise_373_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 115200);
    eltwise_373_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 115200);
    eltwise_374_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 102400);
    eltwise_374_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 102400);
    eltwise_377_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 115200);
    eltwise_377_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 115200);
    conv2d_378_scratch0_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 102400);
    conv2d_378_scratch0_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 102400);
    conv2d_378_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 102656);
    conv2d_378_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 102656);
    concat_394_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 109056);
    concat_394_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 109056);
    transpose_395_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 115756);
    transpose_395_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 115756);
    conv2d_412_scratch0_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 102400);
    conv2d_412_scratch0_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 102400);
    conv2d_412_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 122456);
    conv2d_412_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 122456);
    eltwise_416_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 148056);
    eltwise_416_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 148056);
    eltwise_417_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 173656);
    eltwise_417_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 173656);
    nl_413_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 148056);
    nl_413_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 148056);
    eltwise_414_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 122456);
    eltwise_414_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 122456);
    eltwise_415_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 148056);
    eltwise_415_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 148056);
    eltwise_418_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 122456);
    eltwise_418_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 122456);
    conv2d_419_scratch0_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 102400);
    conv2d_419_scratch0_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 102400);
    conv2d_419_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 148056);
    conv2d_419_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 148056);
    eltwise_423_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 122456);
    eltwise_423_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 122456);
    eltwise_424_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 173656);
    eltwise_424_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 173656);
    nl_420_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 122456);
    nl_420_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 122456);
    eltwise_421_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 148056);
    eltwise_421_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 148056);
    eltwise_422_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 122456);
    eltwise_422_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 122456);
    eltwise_425_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 148056);
    eltwise_425_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 148056);
    conv2d_426_scratch0_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 102400);
    conv2d_426_scratch0_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 102400);
    conv2d_426_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 102656);
    conv2d_426_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 102656);
    conv2d_397_scratch0_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 103856);
    conv2d_397_scratch0_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 103856);
    conv2d_397_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 122456);
    conv2d_397_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 122456);
    eltwise_401_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 148056);
    eltwise_401_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 148056);
    eltwise_402_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 173656);
    eltwise_402_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 173656);
    nl_398_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 148056);
    nl_398_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 148056);
    eltwise_399_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 122456);
    eltwise_399_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 122456);
    eltwise_400_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 148056);
    eltwise_400_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 148056);
    eltwise_403_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 122456);
    eltwise_403_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 122456);
    conv2d_404_scratch0_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 103856);
    conv2d_404_scratch0_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 103856);
    conv2d_404_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 148056);
    conv2d_404_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 148056);
    eltwise_408_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 122456);
    eltwise_408_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 122456);
    eltwise_409_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 173656);
    eltwise_409_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 173656);
    nl_405_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 122456);
    nl_405_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 122456);
    eltwise_406_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 148056);
    eltwise_406_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 148056);
    eltwise_407_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 122456);
    eltwise_407_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 122456);
    eltwise_410_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 148056);
    eltwise_410_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 148056);
    conv2d_411_scratch0_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 102400);
    conv2d_411_scratch0_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 102400);
    conv2d_411_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 122456);
    conv2d_411_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 122456);
    concat_427_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 148056);
    concat_427_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 148056);
    transpose_428_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 174856);
    transpose_428_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 174856);
    conv2d_445_scratch0_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 102400);
    conv2d_445_scratch0_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 102400);
    conv2d_445_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 201656);
    conv2d_445_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 201656);
    eltwise_449_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 304056);
    eltwise_449_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 304056);
    eltwise_450_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 406456);
    eltwise_450_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 406456);
    nl_446_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 304056);
    nl_446_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 304056);
    eltwise_447_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 201656);
    eltwise_447_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 201656);
    eltwise_448_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 304056);
    eltwise_448_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 304056);
    eltwise_451_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 201656);
    eltwise_451_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 201656);
    conv2d_452_scratch0_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 102400);
    conv2d_452_scratch0_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 102400);
    conv2d_452_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 304056);
    conv2d_452_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 304056);
    eltwise_456_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 201656);
    eltwise_456_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 201656);
    eltwise_457_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 406456);
    eltwise_457_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 406456);
    nl_453_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 201656);
    nl_453_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 201656);
    eltwise_454_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 304056);
    eltwise_454_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 304056);
    eltwise_455_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 201656);
    eltwise_455_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 201656);
    eltwise_458_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 304056);
    eltwise_458_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 304056);
    conv2d_459_scratch0_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 102400);
    conv2d_459_scratch0_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 102400);
    conv2d_459_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 102656);
    conv2d_459_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 102656);
    conv2d_430_scratch0_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 107456);
    conv2d_430_scratch0_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 107456);
    conv2d_430_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 201656);
    conv2d_430_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 201656);
    eltwise_434_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 0);
    eltwise_434_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 0);
    eltwise_435_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 304056);
    eltwise_435_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 304056);
    nl_431_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 0);
    nl_431_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 0);
    eltwise_432_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 201656);
    eltwise_432_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 201656);
    eltwise_433_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 0);
    eltwise_433_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 0);
    eltwise_436_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 201656);
    eltwise_436_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 201656);
    conv2d_437_scratch0_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 0);
    conv2d_437_scratch0_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 0);
    conv2d_437_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 304056);
    conv2d_437_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 304056);
    eltwise_441_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 0);
    eltwise_441_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 0);
    eltwise_442_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 201656);
    eltwise_442_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 201656);
    nl_438_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 0);
    nl_438_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 0);
    eltwise_439_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 304056);
    eltwise_439_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 304056);
    eltwise_440_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 0);
    eltwise_440_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 0);
    eltwise_443_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 304056);
    eltwise_443_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 304056);
    conv2d_444_scratch0_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 0);
    conv2d_444_scratch0_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 0);
    conv2d_444_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 256);
    conv2d_444_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 256);
    concat_460_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 201656);
    concat_460_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 201656);
    transpose_461_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 0);
    transpose_461_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 0);
    concat_463_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 201656);
    concat_463_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 201656);
    slice_479_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 0);
    slice_479_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 0);
    nl_480_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 6300);
    nl_480_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 6300);
    slice_464_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 12600);
    slice_464_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 12600);
    transpose_466_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 147000);
    transpose_466_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 147000);
    nl_467_scratch0_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 0);
    nl_467_scratch0_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 0);
    nl_467_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 12600);
    nl_467_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 12600);
    conv2d_468_scratch0_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 0);
    conv2d_468_scratch0_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 0);
    conv2d_468_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 147000);
    conv2d_468_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 147000);
    eltwise_470_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 12600);
    eltwise_470_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 12600);
    slice_474_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 0);
    slice_474_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 0);
    eltwise_475_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 21000);
    eltwise_475_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 21000);
    slice_472_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 0);
    slice_472_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 0);
    eltwise_473_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 12600);
    eltwise_473_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 12600);
    eltwise_478_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 0);
    eltwise_478_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 0);
    eltwise_476_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 16800);
    eltwise_476_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 16800);
    eltwise_477_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 12600);
    eltwise_477_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 12600);
    concat_482_output_array.data = AI_PTR(g_yolov8_detector_activations_map[0] + 16800);
    concat_482_output_array.data_start = AI_PTR(g_yolov8_detector_activations_map[0] + 16800);
    return true;
  }
  AI_ERROR_TRAP(net_ctx, INIT_FAILED, NETWORK_ACTIVATIONS);
  return false;
}




/******************************************************************************/
AI_DECLARE_STATIC
ai_bool yolov8_detector_configure_weights(
  ai_network* net_ctx, const ai_network_params* params)
{
  AI_ASSERT(net_ctx)

  if (ai_platform_get_weights_map(g_yolov8_detector_weights_map, 1, params)) {
    /* Updating weights (byte) offsets */
    
    tfl_pseudo_qconst129_4D_array.format |= AI_FMT_FLAG_CONST;
    tfl_pseudo_qconst129_4D_array.data = AI_PTR(g_yolov8_detector_weights_map[0] + 0);
    tfl_pseudo_qconst129_4D_array.data_start = AI_PTR(g_yolov8_detector_weights_map[0] + 0);
    tfl_pseudo_qconst2_4D_array.format |= AI_FMT_FLAG_CONST;
    tfl_pseudo_qconst2_4D_array.data = AI_PTR(g_yolov8_detector_weights_map[0] + 4);
    tfl_pseudo_qconst2_4D_array.data_start = AI_PTR(g_yolov8_detector_weights_map[0] + 4);
    tfl_pseudo_qconst_3D_array.format |= AI_FMT_FLAG_CONST;
    tfl_pseudo_qconst_3D_array.data = AI_PTR(g_yolov8_detector_weights_map[0] + 8404);
    tfl_pseudo_qconst_3D_array.data_start = AI_PTR(g_yolov8_detector_weights_map[0] + 8404);
    tfl_pseudo_qconst1_array.format |= AI_FMT_FLAG_CONST;
    tfl_pseudo_qconst1_array.data = AI_PTR(g_yolov8_detector_weights_map[0] + 8408);
    tfl_pseudo_qconst1_array.data_start = AI_PTR(g_yolov8_detector_weights_map[0] + 8408);
    conv2d_1_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_1_weights_array.data = AI_PTR(g_yolov8_detector_weights_map[0] + 12608);
    conv2d_1_weights_array.data_start = AI_PTR(g_yolov8_detector_weights_map[0] + 12608);
    conv2d_1_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_1_bias_array.data = AI_PTR(g_yolov8_detector_weights_map[0] + 13040);
    conv2d_1_bias_array.data_start = AI_PTR(g_yolov8_detector_weights_map[0] + 13040);
    conv2d_9_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_9_weights_array.data = AI_PTR(g_yolov8_detector_weights_map[0] + 13104);
    conv2d_9_weights_array.data_start = AI_PTR(g_yolov8_detector_weights_map[0] + 13104);
    conv2d_9_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_9_bias_array.data = AI_PTR(g_yolov8_detector_weights_map[0] + 17712);
    conv2d_9_bias_array.data_start = AI_PTR(g_yolov8_detector_weights_map[0] + 17712);
    conv2d_16_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_16_weights_array.data = AI_PTR(g_yolov8_detector_weights_map[0] + 17840);
    conv2d_16_weights_array.data_start = AI_PTR(g_yolov8_detector_weights_map[0] + 17840);
    conv2d_16_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_16_bias_array.data = AI_PTR(g_yolov8_detector_weights_map[0] + 18864);
    conv2d_16_bias_array.data_start = AI_PTR(g_yolov8_detector_weights_map[0] + 18864);
    conv2d_24_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_24_weights_array.data = AI_PTR(g_yolov8_detector_weights_map[0] + 18992);
    conv2d_24_weights_array.data_start = AI_PTR(g_yolov8_detector_weights_map[0] + 18992);
    conv2d_24_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_24_bias_array.data = AI_PTR(g_yolov8_detector_weights_map[0] + 21296);
    conv2d_24_bias_array.data_start = AI_PTR(g_yolov8_detector_weights_map[0] + 21296);
    conv2d_31_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_31_weights_array.data = AI_PTR(g_yolov8_detector_weights_map[0] + 21360);
    conv2d_31_weights_array.data_start = AI_PTR(g_yolov8_detector_weights_map[0] + 21360);
    conv2d_31_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_31_bias_array.data = AI_PTR(g_yolov8_detector_weights_map[0] + 23664);
    conv2d_31_bias_array.data_start = AI_PTR(g_yolov8_detector_weights_map[0] + 23664);
    conv2d_41_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_41_weights_array.data = AI_PTR(g_yolov8_detector_weights_map[0] + 23728);
    conv2d_41_weights_array.data_start = AI_PTR(g_yolov8_detector_weights_map[0] + 23728);
    conv2d_41_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_41_bias_array.data = AI_PTR(g_yolov8_detector_weights_map[0] + 25264);
    conv2d_41_bias_array.data_start = AI_PTR(g_yolov8_detector_weights_map[0] + 25264);
    conv2d_49_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_49_weights_array.data = AI_PTR(g_yolov8_detector_weights_map[0] + 25392);
    conv2d_49_weights_array.data_start = AI_PTR(g_yolov8_detector_weights_map[0] + 25392);
    conv2d_49_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_49_bias_array.data = AI_PTR(g_yolov8_detector_weights_map[0] + 43824);
    conv2d_49_bias_array.data_start = AI_PTR(g_yolov8_detector_weights_map[0] + 43824);
    conv2d_56_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_56_weights_array.data = AI_PTR(g_yolov8_detector_weights_map[0] + 44080);
    conv2d_56_weights_array.data_start = AI_PTR(g_yolov8_detector_weights_map[0] + 44080);
    conv2d_56_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_56_bias_array.data = AI_PTR(g_yolov8_detector_weights_map[0] + 48176);
    conv2d_56_bias_array.data_start = AI_PTR(g_yolov8_detector_weights_map[0] + 48176);
    conv2d_65_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_65_weights_array.data = AI_PTR(g_yolov8_detector_weights_map[0] + 48432);
    conv2d_65_weights_array.data_start = AI_PTR(g_yolov8_detector_weights_map[0] + 48432);
    conv2d_65_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_65_bias_array.data = AI_PTR(g_yolov8_detector_weights_map[0] + 57648);
    conv2d_65_bias_array.data_start = AI_PTR(g_yolov8_detector_weights_map[0] + 57648);
    conv2d_72_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_72_weights_array.data = AI_PTR(g_yolov8_detector_weights_map[0] + 57776);
    conv2d_72_weights_array.data_start = AI_PTR(g_yolov8_detector_weights_map[0] + 57776);
    conv2d_72_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_72_bias_array.data = AI_PTR(g_yolov8_detector_weights_map[0] + 66992);
    conv2d_72_bias_array.data_start = AI_PTR(g_yolov8_detector_weights_map[0] + 66992);
    conv2d_80_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_80_weights_array.data = AI_PTR(g_yolov8_detector_weights_map[0] + 67120);
    conv2d_80_weights_array.data_start = AI_PTR(g_yolov8_detector_weights_map[0] + 67120);
    conv2d_80_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_80_bias_array.data = AI_PTR(g_yolov8_detector_weights_map[0] + 76336);
    conv2d_80_bias_array.data_start = AI_PTR(g_yolov8_detector_weights_map[0] + 76336);
    conv2d_87_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_87_weights_array.data = AI_PTR(g_yolov8_detector_weights_map[0] + 76464);
    conv2d_87_weights_array.data_start = AI_PTR(g_yolov8_detector_weights_map[0] + 76464);
    conv2d_87_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_87_bias_array.data = AI_PTR(g_yolov8_detector_weights_map[0] + 85680);
    conv2d_87_bias_array.data_start = AI_PTR(g_yolov8_detector_weights_map[0] + 85680);
    conv2d_96_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_96_weights_array.data = AI_PTR(g_yolov8_detector_weights_map[0] + 85808);
    conv2d_96_weights_array.data_start = AI_PTR(g_yolov8_detector_weights_map[0] + 85808);
    conv2d_96_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_96_bias_array.data = AI_PTR(g_yolov8_detector_weights_map[0] + 94000);
    conv2d_96_bias_array.data_start = AI_PTR(g_yolov8_detector_weights_map[0] + 94000);
    conv2d_104_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_104_weights_array.data = AI_PTR(g_yolov8_detector_weights_map[0] + 94256);
    conv2d_104_weights_array.data_start = AI_PTR(g_yolov8_detector_weights_map[0] + 94256);
    conv2d_104_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_104_bias_array.data = AI_PTR(g_yolov8_detector_weights_map[0] + 167984);
    conv2d_104_bias_array.data_start = AI_PTR(g_yolov8_detector_weights_map[0] + 167984);
    conv2d_111_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_111_weights_array.data = AI_PTR(g_yolov8_detector_weights_map[0] + 168496);
    conv2d_111_weights_array.data_start = AI_PTR(g_yolov8_detector_weights_map[0] + 168496);
    conv2d_111_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_111_bias_array.data = AI_PTR(g_yolov8_detector_weights_map[0] + 184880);
    conv2d_111_bias_array.data_start = AI_PTR(g_yolov8_detector_weights_map[0] + 184880);
    conv2d_120_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_120_weights_array.data = AI_PTR(g_yolov8_detector_weights_map[0] + 185392);
    conv2d_120_weights_array.data_start = AI_PTR(g_yolov8_detector_weights_map[0] + 185392);
    conv2d_120_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_120_bias_array.data = AI_PTR(g_yolov8_detector_weights_map[0] + 222256);
    conv2d_120_bias_array.data_start = AI_PTR(g_yolov8_detector_weights_map[0] + 222256);
    conv2d_127_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_127_weights_array.data = AI_PTR(g_yolov8_detector_weights_map[0] + 222512);
    conv2d_127_weights_array.data_start = AI_PTR(g_yolov8_detector_weights_map[0] + 222512);
    conv2d_127_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_127_bias_array.data = AI_PTR(g_yolov8_detector_weights_map[0] + 259376);
    conv2d_127_bias_array.data_start = AI_PTR(g_yolov8_detector_weights_map[0] + 259376);
    conv2d_135_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_135_weights_array.data = AI_PTR(g_yolov8_detector_weights_map[0] + 259632);
    conv2d_135_weights_array.data_start = AI_PTR(g_yolov8_detector_weights_map[0] + 259632);
    conv2d_135_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_135_bias_array.data = AI_PTR(g_yolov8_detector_weights_map[0] + 296496);
    conv2d_135_bias_array.data_start = AI_PTR(g_yolov8_detector_weights_map[0] + 296496);
    conv2d_142_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_142_weights_array.data = AI_PTR(g_yolov8_detector_weights_map[0] + 296752);
    conv2d_142_weights_array.data_start = AI_PTR(g_yolov8_detector_weights_map[0] + 296752);
    conv2d_142_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_142_bias_array.data = AI_PTR(g_yolov8_detector_weights_map[0] + 333616);
    conv2d_142_bias_array.data_start = AI_PTR(g_yolov8_detector_weights_map[0] + 333616);
    conv2d_151_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_151_weights_array.data = AI_PTR(g_yolov8_detector_weights_map[0] + 333872);
    conv2d_151_weights_array.data_start = AI_PTR(g_yolov8_detector_weights_map[0] + 333872);
    conv2d_151_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_151_bias_array.data = AI_PTR(g_yolov8_detector_weights_map[0] + 366640);
    conv2d_151_bias_array.data_start = AI_PTR(g_yolov8_detector_weights_map[0] + 366640);
    conv2d_159_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_159_weights_array.data = AI_PTR(g_yolov8_detector_weights_map[0] + 367152);
    conv2d_159_weights_array.data_start = AI_PTR(g_yolov8_detector_weights_map[0] + 367152);
    conv2d_159_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_159_bias_array.data = AI_PTR(g_yolov8_detector_weights_map[0] + 662064);
    conv2d_159_bias_array.data_start = AI_PTR(g_yolov8_detector_weights_map[0] + 662064);
    conv2d_166_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_166_weights_array.data = AI_PTR(g_yolov8_detector_weights_map[0] + 663088);
    conv2d_166_weights_array.data_start = AI_PTR(g_yolov8_detector_weights_map[0] + 663088);
    conv2d_166_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_166_bias_array.data = AI_PTR(g_yolov8_detector_weights_map[0] + 728624);
    conv2d_166_bias_array.data_start = AI_PTR(g_yolov8_detector_weights_map[0] + 728624);
    conv2d_175_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_175_weights_array.data = AI_PTR(g_yolov8_detector_weights_map[0] + 729648);
    conv2d_175_weights_array.data_start = AI_PTR(g_yolov8_detector_weights_map[0] + 729648);
    conv2d_175_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_175_bias_array.data = AI_PTR(g_yolov8_detector_weights_map[0] + 877104);
    conv2d_175_bias_array.data_start = AI_PTR(g_yolov8_detector_weights_map[0] + 877104);
    conv2d_182_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_182_weights_array.data = AI_PTR(g_yolov8_detector_weights_map[0] + 877616);
    conv2d_182_weights_array.data_start = AI_PTR(g_yolov8_detector_weights_map[0] + 877616);
    conv2d_182_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_182_bias_array.data = AI_PTR(g_yolov8_detector_weights_map[0] + 1025072);
    conv2d_182_bias_array.data_start = AI_PTR(g_yolov8_detector_weights_map[0] + 1025072);
    conv2d_191_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_191_weights_array.data = AI_PTR(g_yolov8_detector_weights_map[0] + 1025584);
    conv2d_191_weights_array.data_start = AI_PTR(g_yolov8_detector_weights_map[0] + 1025584);
    conv2d_191_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_191_bias_array.data = AI_PTR(g_yolov8_detector_weights_map[0] + 1123888);
    conv2d_191_bias_array.data_start = AI_PTR(g_yolov8_detector_weights_map[0] + 1123888);
    conv2d_198_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_198_weights_array.data = AI_PTR(g_yolov8_detector_weights_map[0] + 1124912);
    conv2d_198_weights_array.data_start = AI_PTR(g_yolov8_detector_weights_map[0] + 1124912);
    conv2d_198_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_198_bias_array.data = AI_PTR(g_yolov8_detector_weights_map[0] + 1157680);
    conv2d_198_bias_array.data_start = AI_PTR(g_yolov8_detector_weights_map[0] + 1157680);
    conv2d_209_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_209_weights_array.data = AI_PTR(g_yolov8_detector_weights_map[0] + 1158192);
    conv2d_209_weights_array.data_start = AI_PTR(g_yolov8_detector_weights_map[0] + 1158192);
    conv2d_209_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_209_bias_array.data = AI_PTR(g_yolov8_detector_weights_map[0] + 1289264);
    conv2d_209_bias_array.data_start = AI_PTR(g_yolov8_detector_weights_map[0] + 1289264);
    conv2d_219_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_219_weights_array.data = AI_PTR(g_yolov8_detector_weights_map[0] + 1290288);
    conv2d_219_weights_array.data_start = AI_PTR(g_yolov8_detector_weights_map[0] + 1290288);
    conv2d_219_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_219_bias_array.data = AI_PTR(g_yolov8_detector_weights_map[0] + 1339440);
    conv2d_219_bias_array.data_start = AI_PTR(g_yolov8_detector_weights_map[0] + 1339440);
    conv2d_228_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_228_weights_array.data = AI_PTR(g_yolov8_detector_weights_map[0] + 1339952);
    conv2d_228_weights_array.data_start = AI_PTR(g_yolov8_detector_weights_map[0] + 1339952);
    conv2d_228_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_228_bias_array.data = AI_PTR(g_yolov8_detector_weights_map[0] + 1376816);
    conv2d_228_bias_array.data_start = AI_PTR(g_yolov8_detector_weights_map[0] + 1376816);
    conv2d_235_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_235_weights_array.data = AI_PTR(g_yolov8_detector_weights_map[0] + 1377072);
    conv2d_235_weights_array.data_start = AI_PTR(g_yolov8_detector_weights_map[0] + 1377072);
    conv2d_235_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_235_bias_array.data = AI_PTR(g_yolov8_detector_weights_map[0] + 1413936);
    conv2d_235_bias_array.data_start = AI_PTR(g_yolov8_detector_weights_map[0] + 1413936);
    conv2d_243_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_243_weights_array.data = AI_PTR(g_yolov8_detector_weights_map[0] + 1414192);
    conv2d_243_weights_array.data_start = AI_PTR(g_yolov8_detector_weights_map[0] + 1414192);
    conv2d_243_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_243_bias_array.data = AI_PTR(g_yolov8_detector_weights_map[0] + 1438768);
    conv2d_243_bias_array.data_start = AI_PTR(g_yolov8_detector_weights_map[0] + 1438768);
    conv2d_253_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_253_weights_array.data = AI_PTR(g_yolov8_detector_weights_map[0] + 1439280);
    conv2d_253_weights_array.data_start = AI_PTR(g_yolov8_detector_weights_map[0] + 1439280);
    conv2d_253_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_253_bias_array.data = AI_PTR(g_yolov8_detector_weights_map[0] + 1451568);
    conv2d_253_bias_array.data_start = AI_PTR(g_yolov8_detector_weights_map[0] + 1451568);
    conv2d_262_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_262_weights_array.data = AI_PTR(g_yolov8_detector_weights_map[0] + 1451824);
    conv2d_262_weights_array.data_start = AI_PTR(g_yolov8_detector_weights_map[0] + 1451824);
    conv2d_262_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_262_bias_array.data = AI_PTR(g_yolov8_detector_weights_map[0] + 1461040);
    conv2d_262_bias_array.data_start = AI_PTR(g_yolov8_detector_weights_map[0] + 1461040);
    conv2d_269_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_269_weights_array.data = AI_PTR(g_yolov8_detector_weights_map[0] + 1461168);
    conv2d_269_weights_array.data_start = AI_PTR(g_yolov8_detector_weights_map[0] + 1461168);
    conv2d_269_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_269_bias_array.data = AI_PTR(g_yolov8_detector_weights_map[0] + 1470384);
    conv2d_269_bias_array.data_start = AI_PTR(g_yolov8_detector_weights_map[0] + 1470384);
    conv2d_277_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_277_weights_array.data = AI_PTR(g_yolov8_detector_weights_map[0] + 1470512);
    conv2d_277_weights_array.data_start = AI_PTR(g_yolov8_detector_weights_map[0] + 1470512);
    conv2d_277_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_277_bias_array.data = AI_PTR(g_yolov8_detector_weights_map[0] + 1476656);
    conv2d_277_bias_array.data_start = AI_PTR(g_yolov8_detector_weights_map[0] + 1476656);
    conv2d_285_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_285_weights_array.data = AI_PTR(g_yolov8_detector_weights_map[0] + 1476912);
    conv2d_285_weights_array.data_start = AI_PTR(g_yolov8_detector_weights_map[0] + 1476912);
    conv2d_285_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_285_bias_array.data = AI_PTR(g_yolov8_detector_weights_map[0] + 1513776);
    conv2d_285_bias_array.data_start = AI_PTR(g_yolov8_detector_weights_map[0] + 1513776);
    conv2d_293_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_293_weights_array.data = AI_PTR(g_yolov8_detector_weights_map[0] + 1514032);
    conv2d_293_weights_array.data_start = AI_PTR(g_yolov8_detector_weights_map[0] + 1514032);
    conv2d_293_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_293_bias_array.data = AI_PTR(g_yolov8_detector_weights_map[0] + 1538608);
    conv2d_293_bias_array.data_start = AI_PTR(g_yolov8_detector_weights_map[0] + 1538608);
    conv2d_302_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_302_weights_array.data = AI_PTR(g_yolov8_detector_weights_map[0] + 1539120);
    conv2d_302_weights_array.data_start = AI_PTR(g_yolov8_detector_weights_map[0] + 1539120);
    conv2d_302_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_302_bias_array.data = AI_PTR(g_yolov8_detector_weights_map[0] + 1575984);
    conv2d_302_bias_array.data_start = AI_PTR(g_yolov8_detector_weights_map[0] + 1575984);
    conv2d_309_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_309_weights_array.data = AI_PTR(g_yolov8_detector_weights_map[0] + 1576240);
    conv2d_309_weights_array.data_start = AI_PTR(g_yolov8_detector_weights_map[0] + 1576240);
    conv2d_309_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_309_bias_array.data = AI_PTR(g_yolov8_detector_weights_map[0] + 1613104);
    conv2d_309_bias_array.data_start = AI_PTR(g_yolov8_detector_weights_map[0] + 1613104);
    conv2d_317_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_317_weights_array.data = AI_PTR(g_yolov8_detector_weights_map[0] + 1613360);
    conv2d_317_weights_array.data_start = AI_PTR(g_yolov8_detector_weights_map[0] + 1613360);
    conv2d_317_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_317_bias_array.data = AI_PTR(g_yolov8_detector_weights_map[0] + 1637936);
    conv2d_317_bias_array.data_start = AI_PTR(g_yolov8_detector_weights_map[0] + 1637936);
    conv2d_325_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_325_weights_array.data = AI_PTR(g_yolov8_detector_weights_map[0] + 1638448);
    conv2d_325_weights_array.data_start = AI_PTR(g_yolov8_detector_weights_map[0] + 1638448);
    conv2d_325_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_325_bias_array.data = AI_PTR(g_yolov8_detector_weights_map[0] + 1785904);
    conv2d_325_bias_array.data_start = AI_PTR(g_yolov8_detector_weights_map[0] + 1785904);
    conv2d_333_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_333_weights_array.data = AI_PTR(g_yolov8_detector_weights_map[0] + 1786416);
    conv2d_333_weights_array.data_start = AI_PTR(g_yolov8_detector_weights_map[0] + 1786416);
    conv2d_333_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_333_bias_array.data = AI_PTR(g_yolov8_detector_weights_map[0] + 1884720);
    conv2d_333_bias_array.data_start = AI_PTR(g_yolov8_detector_weights_map[0] + 1884720);
    conv2d_342_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_342_weights_array.data = AI_PTR(g_yolov8_detector_weights_map[0] + 1885744);
    conv2d_342_weights_array.data_start = AI_PTR(g_yolov8_detector_weights_map[0] + 1885744);
    conv2d_342_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_342_bias_array.data = AI_PTR(g_yolov8_detector_weights_map[0] + 2033200);
    conv2d_342_bias_array.data_start = AI_PTR(g_yolov8_detector_weights_map[0] + 2033200);
    conv2d_349_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_349_weights_array.data = AI_PTR(g_yolov8_detector_weights_map[0] + 2033712);
    conv2d_349_weights_array.data_start = AI_PTR(g_yolov8_detector_weights_map[0] + 2033712);
    conv2d_349_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_349_bias_array.data = AI_PTR(g_yolov8_detector_weights_map[0] + 2181168);
    conv2d_349_bias_array.data_start = AI_PTR(g_yolov8_detector_weights_map[0] + 2181168);
    conv2d_357_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_357_weights_array.data = AI_PTR(g_yolov8_detector_weights_map[0] + 2181680);
    conv2d_357_weights_array.data_start = AI_PTR(g_yolov8_detector_weights_map[0] + 2181680);
    conv2d_357_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_357_bias_array.data = AI_PTR(g_yolov8_detector_weights_map[0] + 2279984);
    conv2d_357_bias_array.data_start = AI_PTR(g_yolov8_detector_weights_map[0] + 2279984);
    conv2d_379_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_379_weights_array.data = AI_PTR(g_yolov8_detector_weights_map[0] + 2281008);
    conv2d_379_weights_array.data_start = AI_PTR(g_yolov8_detector_weights_map[0] + 2281008);
    conv2d_379_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_379_bias_array.data = AI_PTR(g_yolov8_detector_weights_map[0] + 2428464);
    conv2d_379_bias_array.data_start = AI_PTR(g_yolov8_detector_weights_map[0] + 2428464);
    conv2d_386_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_386_weights_array.data = AI_PTR(g_yolov8_detector_weights_map[0] + 2428720);
    conv2d_386_weights_array.data_start = AI_PTR(g_yolov8_detector_weights_map[0] + 2428720);
    conv2d_386_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_386_bias_array.data = AI_PTR(g_yolov8_detector_weights_map[0] + 2465584);
    conv2d_386_bias_array.data_start = AI_PTR(g_yolov8_detector_weights_map[0] + 2465584);
    conv2d_393_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_393_weights_array.data = AI_PTR(g_yolov8_detector_weights_map[0] + 2465840);
    conv2d_393_weights_array.data_start = AI_PTR(g_yolov8_detector_weights_map[0] + 2465840);
    conv2d_393_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_393_bias_array.data = AI_PTR(g_yolov8_detector_weights_map[0] + 2466032);
    conv2d_393_bias_array.data_start = AI_PTR(g_yolov8_detector_weights_map[0] + 2466032);
    conv2d_364_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_364_weights_array.data = AI_PTR(g_yolov8_detector_weights_map[0] + 2466044);
    conv2d_364_weights_array.data_start = AI_PTR(g_yolov8_detector_weights_map[0] + 2466044);
    conv2d_364_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_364_bias_array.data = AI_PTR(g_yolov8_detector_weights_map[0] + 2613500);
    conv2d_364_bias_array.data_start = AI_PTR(g_yolov8_detector_weights_map[0] + 2613500);
    conv2d_371_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_371_weights_array.data = AI_PTR(g_yolov8_detector_weights_map[0] + 2613756);
    conv2d_371_weights_array.data_start = AI_PTR(g_yolov8_detector_weights_map[0] + 2613756);
    conv2d_371_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_371_bias_array.data = AI_PTR(g_yolov8_detector_weights_map[0] + 2650620);
    conv2d_371_bias_array.data_start = AI_PTR(g_yolov8_detector_weights_map[0] + 2650620);
    conv2d_378_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_378_weights_array.data = AI_PTR(g_yolov8_detector_weights_map[0] + 2650876);
    conv2d_378_weights_array.data_start = AI_PTR(g_yolov8_detector_weights_map[0] + 2650876);
    conv2d_378_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_378_bias_array.data = AI_PTR(g_yolov8_detector_weights_map[0] + 2654972);
    conv2d_378_bias_array.data_start = AI_PTR(g_yolov8_detector_weights_map[0] + 2654972);
    conv2d_412_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_412_weights_array.data = AI_PTR(g_yolov8_detector_weights_map[0] + 2655228);
    conv2d_412_weights_array.data_start = AI_PTR(g_yolov8_detector_weights_map[0] + 2655228);
    conv2d_412_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_412_bias_array.data = AI_PTR(g_yolov8_detector_weights_map[0] + 2728956);
    conv2d_412_bias_array.data_start = AI_PTR(g_yolov8_detector_weights_map[0] + 2728956);
    conv2d_419_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_419_weights_array.data = AI_PTR(g_yolov8_detector_weights_map[0] + 2729212);
    conv2d_419_weights_array.data_start = AI_PTR(g_yolov8_detector_weights_map[0] + 2729212);
    conv2d_419_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_419_bias_array.data = AI_PTR(g_yolov8_detector_weights_map[0] + 2766076);
    conv2d_419_bias_array.data_start = AI_PTR(g_yolov8_detector_weights_map[0] + 2766076);
    conv2d_426_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_426_weights_array.data = AI_PTR(g_yolov8_detector_weights_map[0] + 2766332);
    conv2d_426_weights_array.data_start = AI_PTR(g_yolov8_detector_weights_map[0] + 2766332);
    conv2d_426_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_426_bias_array.data = AI_PTR(g_yolov8_detector_weights_map[0] + 2766524);
    conv2d_426_bias_array.data_start = AI_PTR(g_yolov8_detector_weights_map[0] + 2766524);
    conv2d_397_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_397_weights_array.data = AI_PTR(g_yolov8_detector_weights_map[0] + 2766536);
    conv2d_397_weights_array.data_start = AI_PTR(g_yolov8_detector_weights_map[0] + 2766536);
    conv2d_397_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_397_bias_array.data = AI_PTR(g_yolov8_detector_weights_map[0] + 2840264);
    conv2d_397_bias_array.data_start = AI_PTR(g_yolov8_detector_weights_map[0] + 2840264);
    conv2d_404_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_404_weights_array.data = AI_PTR(g_yolov8_detector_weights_map[0] + 2840520);
    conv2d_404_weights_array.data_start = AI_PTR(g_yolov8_detector_weights_map[0] + 2840520);
    conv2d_404_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_404_bias_array.data = AI_PTR(g_yolov8_detector_weights_map[0] + 2877384);
    conv2d_404_bias_array.data_start = AI_PTR(g_yolov8_detector_weights_map[0] + 2877384);
    conv2d_411_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_411_weights_array.data = AI_PTR(g_yolov8_detector_weights_map[0] + 2877640);
    conv2d_411_weights_array.data_start = AI_PTR(g_yolov8_detector_weights_map[0] + 2877640);
    conv2d_411_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_411_bias_array.data = AI_PTR(g_yolov8_detector_weights_map[0] + 2881736);
    conv2d_411_bias_array.data_start = AI_PTR(g_yolov8_detector_weights_map[0] + 2881736);
    conv2d_445_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_445_weights_array.data = AI_PTR(g_yolov8_detector_weights_map[0] + 2881992);
    conv2d_445_weights_array.data_start = AI_PTR(g_yolov8_detector_weights_map[0] + 2881992);
    conv2d_445_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_445_bias_array.data = AI_PTR(g_yolov8_detector_weights_map[0] + 2918856);
    conv2d_445_bias_array.data_start = AI_PTR(g_yolov8_detector_weights_map[0] + 2918856);
    conv2d_452_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_452_weights_array.data = AI_PTR(g_yolov8_detector_weights_map[0] + 2919112);
    conv2d_452_weights_array.data_start = AI_PTR(g_yolov8_detector_weights_map[0] + 2919112);
    conv2d_452_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_452_bias_array.data = AI_PTR(g_yolov8_detector_weights_map[0] + 2955976);
    conv2d_452_bias_array.data_start = AI_PTR(g_yolov8_detector_weights_map[0] + 2955976);
    conv2d_459_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_459_weights_array.data = AI_PTR(g_yolov8_detector_weights_map[0] + 2956232);
    conv2d_459_weights_array.data_start = AI_PTR(g_yolov8_detector_weights_map[0] + 2956232);
    conv2d_459_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_459_bias_array.data = AI_PTR(g_yolov8_detector_weights_map[0] + 2956424);
    conv2d_459_bias_array.data_start = AI_PTR(g_yolov8_detector_weights_map[0] + 2956424);
    conv2d_430_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_430_weights_array.data = AI_PTR(g_yolov8_detector_weights_map[0] + 2956436);
    conv2d_430_weights_array.data_start = AI_PTR(g_yolov8_detector_weights_map[0] + 2956436);
    conv2d_430_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_430_bias_array.data = AI_PTR(g_yolov8_detector_weights_map[0] + 2993300);
    conv2d_430_bias_array.data_start = AI_PTR(g_yolov8_detector_weights_map[0] + 2993300);
    conv2d_437_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_437_weights_array.data = AI_PTR(g_yolov8_detector_weights_map[0] + 2993556);
    conv2d_437_weights_array.data_start = AI_PTR(g_yolov8_detector_weights_map[0] + 2993556);
    conv2d_437_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_437_bias_array.data = AI_PTR(g_yolov8_detector_weights_map[0] + 3030420);
    conv2d_437_bias_array.data_start = AI_PTR(g_yolov8_detector_weights_map[0] + 3030420);
    conv2d_444_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_444_weights_array.data = AI_PTR(g_yolov8_detector_weights_map[0] + 3030676);
    conv2d_444_weights_array.data_start = AI_PTR(g_yolov8_detector_weights_map[0] + 3030676);
    conv2d_444_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_444_bias_array.data = AI_PTR(g_yolov8_detector_weights_map[0] + 3034772);
    conv2d_444_bias_array.data_start = AI_PTR(g_yolov8_detector_weights_map[0] + 3034772);
    conv2d_468_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_468_weights_array.data = AI_PTR(g_yolov8_detector_weights_map[0] + 3035028);
    conv2d_468_weights_array.data_start = AI_PTR(g_yolov8_detector_weights_map[0] + 3035028);
    conv2d_468_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_468_bias_array.data = AI_PTR(g_yolov8_detector_weights_map[0] + 3035044);
    conv2d_468_bias_array.data_start = AI_PTR(g_yolov8_detector_weights_map[0] + 3035044);
    return true;
  }
  AI_ERROR_TRAP(net_ctx, INIT_FAILED, NETWORK_WEIGHTS);
  return false;
}


/**  PUBLIC APIs SECTION  *****************************************************/



AI_DEPRECATED
AI_API_ENTRY
ai_bool ai_yolov8_detector_get_info(
  ai_handle network, ai_network_report* report)
{
  ai_network* net_ctx = AI_NETWORK_ACQUIRE_CTX(network);

  if (report && net_ctx)
  {
    ai_network_report r = {
      .model_name        = AI_YOLOV8_DETECTOR_MODEL_NAME,
      .model_signature   = AI_YOLOV8_DETECTOR_MODEL_SIGNATURE,
      .model_datetime    = AI_TOOLS_DATE_TIME,
      
      .compile_datetime  = AI_TOOLS_COMPILE_TIME,
      
      .runtime_revision  = ai_platform_runtime_get_revision(),
      .runtime_version   = ai_platform_runtime_get_version(),

      .tool_revision     = AI_TOOLS_REVISION_ID,
      .tool_version      = {AI_TOOLS_VERSION_MAJOR, AI_TOOLS_VERSION_MINOR,
                            AI_TOOLS_VERSION_MICRO, 0x0},
      .tool_api_version  = AI_STRUCT_INIT,

      .api_version            = ai_platform_api_get_version(),
      .interface_api_version  = ai_platform_interface_api_get_version(),
      
      .n_macc            = 1034617052,
      .n_inputs          = 0,
      .inputs            = NULL,
      .n_outputs         = 0,
      .outputs           = NULL,
      .params            = AI_STRUCT_INIT,
      .activations       = AI_STRUCT_INIT,
      .n_nodes           = 0,
      .signature         = 0x0b5d00dc,
    };

    if (!ai_platform_api_get_network_report(network, &r)) return false;

    *report = r;
    return true;
  }
  return false;
}



AI_API_ENTRY
ai_bool ai_yolov8_detector_get_report(
  ai_handle network, ai_network_report* report)
{
  ai_network* net_ctx = AI_NETWORK_ACQUIRE_CTX(network);

  if (report && net_ctx)
  {
    ai_network_report r = {
      .model_name        = AI_YOLOV8_DETECTOR_MODEL_NAME,
      .model_signature   = AI_YOLOV8_DETECTOR_MODEL_SIGNATURE,
      .model_datetime    = AI_TOOLS_DATE_TIME,
      
      .compile_datetime  = AI_TOOLS_COMPILE_TIME,
      
      .runtime_revision  = ai_platform_runtime_get_revision(),
      .runtime_version   = ai_platform_runtime_get_version(),

      .tool_revision     = AI_TOOLS_REVISION_ID,
      .tool_version      = {AI_TOOLS_VERSION_MAJOR, AI_TOOLS_VERSION_MINOR,
                            AI_TOOLS_VERSION_MICRO, 0x0},
      .tool_api_version  = AI_STRUCT_INIT,

      .api_version            = ai_platform_api_get_version(),
      .interface_api_version  = ai_platform_interface_api_get_version(),
      
      .n_macc            = 1034617052,
      .n_inputs          = 0,
      .inputs            = NULL,
      .n_outputs         = 0,
      .outputs           = NULL,
      .map_signature     = AI_MAGIC_SIGNATURE,
      .map_weights       = AI_STRUCT_INIT,
      .map_activations   = AI_STRUCT_INIT,
      .n_nodes           = 0,
      .signature         = 0x0b5d00dc,
    };

    if (!ai_platform_api_get_network_report(network, &r)) return false;

    *report = r;
    return true;
  }
  return false;
}


AI_API_ENTRY
ai_error ai_yolov8_detector_get_error(ai_handle network)
{
  return ai_platform_network_get_error(network);
}


AI_API_ENTRY
ai_error ai_yolov8_detector_create(
  ai_handle* network, const ai_buffer* network_config)
{
  return ai_platform_network_create(
    network, network_config, 
    AI_CONTEXT_OBJ(&AI_NET_OBJ_INSTANCE),
    AI_TOOLS_API_VERSION_MAJOR, AI_TOOLS_API_VERSION_MINOR, AI_TOOLS_API_VERSION_MICRO);
}


AI_API_ENTRY
ai_error ai_yolov8_detector_create_and_init(
  ai_handle* network, const ai_handle activations[], const ai_handle weights[])
{
  ai_error err;
  ai_network_params params;

  err = ai_yolov8_detector_create(network, AI_YOLOV8_DETECTOR_DATA_CONFIG);
  if (err.type != AI_ERROR_NONE) {
    return err;
  }
  
  if (ai_yolov8_detector_data_params_get(&params) != true) {
    err = ai_yolov8_detector_get_error(*network);
    return err;
  }
#if defined(AI_YOLOV8_DETECTOR_DATA_ACTIVATIONS_COUNT)
  /* set the addresses of the activations buffers */
  for (ai_u16 idx=0; activations && idx<params.map_activations.size; idx++) {
    AI_BUFFER_ARRAY_ITEM_SET_ADDRESS(&params.map_activations, idx, activations[idx]);
  }
#endif
#if defined(AI_YOLOV8_DETECTOR_DATA_WEIGHTS_COUNT)
  /* set the addresses of the weight buffers */
  for (ai_u16 idx=0; weights && idx<params.map_weights.size; idx++) {
    AI_BUFFER_ARRAY_ITEM_SET_ADDRESS(&params.map_weights, idx, weights[idx]);
  }
#endif
  if (ai_yolov8_detector_init(*network, &params) != true) {
    err = ai_yolov8_detector_get_error(*network);
  }
  return err;
}


AI_API_ENTRY
ai_buffer* ai_yolov8_detector_inputs_get(ai_handle network, ai_u16 *n_buffer)
{
  if (network == AI_HANDLE_NULL) {
    network = (ai_handle)&AI_NET_OBJ_INSTANCE;
    AI_NETWORK_OBJ(network)->magic = AI_MAGIC_CONTEXT_TOKEN;
  }
  return ai_platform_inputs_get(network, n_buffer);
}


AI_API_ENTRY
ai_buffer* ai_yolov8_detector_outputs_get(ai_handle network, ai_u16 *n_buffer)
{
  if (network == AI_HANDLE_NULL) {
    network = (ai_handle)&AI_NET_OBJ_INSTANCE;
    AI_NETWORK_OBJ(network)->magic = AI_MAGIC_CONTEXT_TOKEN;
  }
  return ai_platform_outputs_get(network, n_buffer);
}


AI_API_ENTRY
ai_handle ai_yolov8_detector_destroy(ai_handle network)
{
  return ai_platform_network_destroy(network);
}


AI_API_ENTRY
ai_bool ai_yolov8_detector_init(
  ai_handle network, const ai_network_params* params)
{
  ai_network* net_ctx = AI_NETWORK_OBJ(ai_platform_network_init(network, params));
  ai_bool ok = true;

  if (!net_ctx) return false;
  ok &= yolov8_detector_configure_weights(net_ctx, params);
  ok &= yolov8_detector_configure_activations(net_ctx, params);

  ok &= ai_platform_network_post_init(network);

  return ok;
}


AI_API_ENTRY
ai_i32 ai_yolov8_detector_run(
  ai_handle network, const ai_buffer* input, ai_buffer* output)
{
  return ai_platform_network_process(network, input, output);
}


AI_API_ENTRY
ai_i32 ai_yolov8_detector_forward(ai_handle network, const ai_buffer* input)
{
  return ai_platform_network_process(network, input, NULL);
}



#undef AI_YOLOV8_DETECTOR_MODEL_SIGNATURE
#undef AI_NET_OBJ_INSTANCE
#undef AI_TOOLS_DATE_TIME
#undef AI_TOOLS_COMPILE_TIME

