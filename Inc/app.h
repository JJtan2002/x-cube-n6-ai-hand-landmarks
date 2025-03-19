/**
  ******************************************************************************
  * @file    app.h
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

#ifndef APP_H
#define APP_H

#include "postprocess_conf.h"

/* Model Related Info */
#define NN_WIDTH AI_PD_MODEL_PP_WIDTH
#define NN_HEIGHT AI_PD_MODEL_PP_HEIGHT
#define NN_FORMAT DCMIPP_PIXEL_PACKER_FORMAT_RGB888_YUV444_1
#define NN_BPP 3

/* Display config */
#define DISPLAY_FORMAT NN_FORMAT
#define DISPLAY_BPP NN_BPP

void app_run(void);

#endif