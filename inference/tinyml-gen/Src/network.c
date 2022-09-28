/**
  ******************************************************************************
  * @file    network.c
  * @author  AST Embedded Analytics Research Platform
  * @date    Tue Sep 27 21:46:39 2022
  * @brief   AI Tool Automatic Code Generator for Embedded NN computing
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2017 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  ******************************************************************************
  */


#include "network.h"
#include "network_data.h"

#include "ai_platform.h"
#include "ai_platform_interface.h"
#include "ai_math_helpers.h"

#include "core_common.h"
#include "core_convert.h"

#include "layers.h"




#undef AI_NET_OBJ_INSTANCE
#define AI_NET_OBJ_INSTANCE g_network
 
#undef AI_NETWORK_MODEL_SIGNATURE
#define AI_NETWORK_MODEL_SIGNATURE     "9d1587c92ad2486d88b8534cf64b3200"

#ifndef AI_TOOLS_REVISION_ID
#define AI_TOOLS_REVISION_ID     ""
#endif

#undef AI_TOOLS_DATE_TIME
#define AI_TOOLS_DATE_TIME   "Tue Sep 27 21:46:39 2022"

#undef AI_TOOLS_COMPILE_TIME
#define AI_TOOLS_COMPILE_TIME    __DATE__ " " __TIME__

#undef AI_NETWORK_N_BATCHES
#define AI_NETWORK_N_BATCHES         (1)




/**  Array declarations section  **********************************************/
/* Array#0 */
AI_ARRAY_OBJ_DECLARE(
  input_1_output_array, AI_ARRAY_FORMAT_FLOAT|AI_FMT_FLAG_IS_IO,
  NULL, NULL, 1250, AI_STATIC)

/* Array#1 */
AI_ARRAY_OBJ_DECLARE(
  node_40_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 1869, AI_STATIC)

/* Array#2 */
AI_ARRAY_OBJ_DECLARE(
  node_42_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 1869, AI_STATIC)

/* Array#3 */
AI_ARRAY_OBJ_DECLARE(
  node_43_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 1550, AI_STATIC)

/* Array#4 */
AI_ARRAY_OBJ_DECLARE(
  node_45_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 1550, AI_STATIC)

/* Array#5 */
AI_ARRAY_OBJ_DECLARE(
  node_46_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 1540, AI_STATIC)

/* Array#6 */
AI_ARRAY_OBJ_DECLARE(
  node_48_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 1540, AI_STATIC)

/* Array#7 */
AI_ARRAY_OBJ_DECLARE(
  node_49_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 1520, AI_STATIC)

/* Array#8 */
AI_ARRAY_OBJ_DECLARE(
  node_51_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 1520, AI_STATIC)

/* Array#9 */
AI_ARRAY_OBJ_DECLARE(
  node_52_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 740, AI_STATIC)

/* Array#10 */
AI_ARRAY_OBJ_DECLARE(
  node_54_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 740, AI_STATIC)

/* Array#11 */
AI_ARRAY_OBJ_DECLARE(
  node_57_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 10, AI_STATIC)

/* Array#12 */
AI_ARRAY_OBJ_DECLARE(
  node_58_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 10, AI_STATIC)

/* Array#13 */
AI_ARRAY_OBJ_DECLARE(
  node_59_output_array, AI_ARRAY_FORMAT_FLOAT|AI_FMT_FLAG_IS_IO,
  NULL, NULL, 2, AI_STATIC)

/* Array#14 */
AI_ARRAY_OBJ_DECLARE(
  node_40_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 18, AI_STATIC)

/* Array#15 */
AI_ARRAY_OBJ_DECLARE(
  node_40_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3, AI_STATIC)

/* Array#16 */
AI_ARRAY_OBJ_DECLARE(
  node_42_scale_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3, AI_STATIC)

/* Array#17 */
AI_ARRAY_OBJ_DECLARE(
  node_42_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3, AI_STATIC)

/* Array#18 */
AI_ARRAY_OBJ_DECLARE(
  node_43_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 75, AI_STATIC)

/* Array#19 */
AI_ARRAY_OBJ_DECLARE(
  node_43_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 5, AI_STATIC)

/* Array#20 */
AI_ARRAY_OBJ_DECLARE(
  node_45_scale_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 5, AI_STATIC)

/* Array#21 */
AI_ARRAY_OBJ_DECLARE(
  node_45_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 5, AI_STATIC)

/* Array#22 */
AI_ARRAY_OBJ_DECLARE(
  node_46_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 200, AI_STATIC)

/* Array#23 */
AI_ARRAY_OBJ_DECLARE(
  node_46_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 10, AI_STATIC)

/* Array#24 */
AI_ARRAY_OBJ_DECLARE(
  node_48_scale_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 10, AI_STATIC)

/* Array#25 */
AI_ARRAY_OBJ_DECLARE(
  node_48_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 10, AI_STATIC)

/* Array#26 */
AI_ARRAY_OBJ_DECLARE(
  node_49_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 800, AI_STATIC)

/* Array#27 */
AI_ARRAY_OBJ_DECLARE(
  node_49_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 20, AI_STATIC)

/* Array#28 */
AI_ARRAY_OBJ_DECLARE(
  node_51_scale_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 20, AI_STATIC)

/* Array#29 */
AI_ARRAY_OBJ_DECLARE(
  node_51_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 20, AI_STATIC)

/* Array#30 */
AI_ARRAY_OBJ_DECLARE(
  node_52_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 1600, AI_STATIC)

/* Array#31 */
AI_ARRAY_OBJ_DECLARE(
  node_52_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 20, AI_STATIC)

/* Array#32 */
AI_ARRAY_OBJ_DECLARE(
  node_54_scale_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 20, AI_STATIC)

/* Array#33 */
AI_ARRAY_OBJ_DECLARE(
  node_54_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 20, AI_STATIC)

/* Array#34 */
AI_ARRAY_OBJ_DECLARE(
  fc2_0_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 2, AI_STATIC)

/* Array#35 */
AI_ARRAY_OBJ_DECLARE(
  fc2_0_weight_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 20, AI_STATIC)

/* Array#36 */
AI_ARRAY_OBJ_DECLARE(
  fc1_1_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 10, AI_STATIC)

/* Array#37 */
AI_ARRAY_OBJ_DECLARE(
  fc1_1_weight_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 7400, AI_STATIC)

/**  Tensor declarations section  *********************************************/
/* Tensor #0 */
AI_TENSOR_OBJ_DECLARE(
  input_1_output, AI_STATIC,
  0, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 1, 1250), AI_STRIDE_INIT(4, 4, 4, 4, 4),
  1, &input_1_output_array, NULL)

/* Tensor #1 */
AI_TENSOR_OBJ_DECLARE(
  node_40_output, AI_STATIC,
  1, 0x0,
  AI_SHAPE_INIT(4, 1, 3, 1, 623), AI_STRIDE_INIT(4, 4, 4, 12, 12),
  1, &node_40_output_array, NULL)

/* Tensor #2 */
AI_TENSOR_OBJ_DECLARE(
  node_42_output, AI_STATIC,
  2, 0x0,
  AI_SHAPE_INIT(4, 1, 3, 1, 623), AI_STRIDE_INIT(4, 4, 4, 12, 12),
  1, &node_42_output_array, NULL)

/* Tensor #3 */
AI_TENSOR_OBJ_DECLARE(
  node_43_output, AI_STATIC,
  3, 0x0,
  AI_SHAPE_INIT(4, 1, 5, 1, 310), AI_STRIDE_INIT(4, 4, 4, 20, 20),
  1, &node_43_output_array, NULL)

/* Tensor #4 */
AI_TENSOR_OBJ_DECLARE(
  node_45_output, AI_STATIC,
  4, 0x0,
  AI_SHAPE_INIT(4, 1, 5, 1, 310), AI_STRIDE_INIT(4, 4, 4, 20, 20),
  1, &node_45_output_array, NULL)

/* Tensor #5 */
AI_TENSOR_OBJ_DECLARE(
  node_46_output, AI_STATIC,
  5, 0x0,
  AI_SHAPE_INIT(4, 1, 10, 1, 154), AI_STRIDE_INIT(4, 4, 4, 40, 40),
  1, &node_46_output_array, NULL)

/* Tensor #6 */
AI_TENSOR_OBJ_DECLARE(
  node_48_output, AI_STATIC,
  6, 0x0,
  AI_SHAPE_INIT(4, 1, 10, 1, 154), AI_STRIDE_INIT(4, 4, 4, 40, 40),
  1, &node_48_output_array, NULL)

/* Tensor #7 */
AI_TENSOR_OBJ_DECLARE(
  node_49_output, AI_STATIC,
  7, 0x0,
  AI_SHAPE_INIT(4, 1, 20, 1, 76), AI_STRIDE_INIT(4, 4, 4, 80, 80),
  1, &node_49_output_array, NULL)

/* Tensor #8 */
AI_TENSOR_OBJ_DECLARE(
  node_51_output, AI_STATIC,
  8, 0x0,
  AI_SHAPE_INIT(4, 1, 20, 1, 76), AI_STRIDE_INIT(4, 4, 4, 80, 80),
  1, &node_51_output_array, NULL)

/* Tensor #9 */
AI_TENSOR_OBJ_DECLARE(
  node_52_output, AI_STATIC,
  9, 0x0,
  AI_SHAPE_INIT(4, 1, 20, 1, 37), AI_STRIDE_INIT(4, 4, 4, 80, 80),
  1, &node_52_output_array, NULL)

/* Tensor #10 */
AI_TENSOR_OBJ_DECLARE(
  node_54_output, AI_STATIC,
  10, 0x0,
  AI_SHAPE_INIT(4, 1, 20, 1, 37), AI_STRIDE_INIT(4, 4, 4, 80, 80),
  1, &node_54_output_array, NULL)

/* Tensor #11 */
AI_TENSOR_OBJ_DECLARE(
  node_54_output0, AI_STATIC,
  11, 0x0,
  AI_SHAPE_INIT(4, 1, 740, 1, 1), AI_STRIDE_INIT(4, 4, 4, 2960, 2960),
  1, &node_54_output_array, NULL)

/* Tensor #12 */
AI_TENSOR_OBJ_DECLARE(
  node_57_output, AI_STATIC,
  12, 0x0,
  AI_SHAPE_INIT(4, 1, 10, 1, 1), AI_STRIDE_INIT(4, 4, 4, 40, 40),
  1, &node_57_output_array, NULL)

/* Tensor #13 */
AI_TENSOR_OBJ_DECLARE(
  node_58_output, AI_STATIC,
  13, 0x0,
  AI_SHAPE_INIT(4, 1, 10, 1, 1), AI_STRIDE_INIT(4, 4, 4, 40, 40),
  1, &node_58_output_array, NULL)

/* Tensor #14 */
AI_TENSOR_OBJ_DECLARE(
  node_59_output, AI_STATIC,
  14, 0x0,
  AI_SHAPE_INIT(4, 1, 2, 1, 1), AI_STRIDE_INIT(4, 4, 4, 8, 8),
  1, &node_59_output_array, NULL)

/* Tensor #15 */
AI_TENSOR_OBJ_DECLARE(
  node_40_weights, AI_STATIC,
  15, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 6, 3), AI_STRIDE_INIT(4, 4, 4, 4, 24),
  1, &node_40_weights_array, NULL)

/* Tensor #16 */
AI_TENSOR_OBJ_DECLARE(
  node_40_bias, AI_STATIC,
  16, 0x0,
  AI_SHAPE_INIT(4, 1, 3, 1, 1), AI_STRIDE_INIT(4, 4, 4, 12, 12),
  1, &node_40_bias_array, NULL)

/* Tensor #17 */
AI_TENSOR_OBJ_DECLARE(
  node_42_scale, AI_STATIC,
  17, 0x0,
  AI_SHAPE_INIT(4, 1, 3, 1, 1), AI_STRIDE_INIT(4, 4, 4, 12, 12),
  1, &node_42_scale_array, NULL)

/* Tensor #18 */
AI_TENSOR_OBJ_DECLARE(
  node_42_bias, AI_STATIC,
  18, 0x0,
  AI_SHAPE_INIT(4, 1, 3, 1, 1), AI_STRIDE_INIT(4, 4, 4, 12, 12),
  1, &node_42_bias_array, NULL)

/* Tensor #19 */
AI_TENSOR_OBJ_DECLARE(
  node_43_weights, AI_STATIC,
  19, 0x0,
  AI_SHAPE_INIT(4, 3, 1, 5, 5), AI_STRIDE_INIT(4, 4, 12, 12, 60),
  1, &node_43_weights_array, NULL)

/* Tensor #20 */
AI_TENSOR_OBJ_DECLARE(
  node_43_bias, AI_STATIC,
  20, 0x0,
  AI_SHAPE_INIT(4, 1, 5, 1, 1), AI_STRIDE_INIT(4, 4, 4, 20, 20),
  1, &node_43_bias_array, NULL)

/* Tensor #21 */
AI_TENSOR_OBJ_DECLARE(
  node_45_scale, AI_STATIC,
  21, 0x0,
  AI_SHAPE_INIT(4, 1, 5, 1, 1), AI_STRIDE_INIT(4, 4, 4, 20, 20),
  1, &node_45_scale_array, NULL)

/* Tensor #22 */
AI_TENSOR_OBJ_DECLARE(
  node_45_bias, AI_STATIC,
  22, 0x0,
  AI_SHAPE_INIT(4, 1, 5, 1, 1), AI_STRIDE_INIT(4, 4, 4, 20, 20),
  1, &node_45_bias_array, NULL)

/* Tensor #23 */
AI_TENSOR_OBJ_DECLARE(
  node_46_weights, AI_STATIC,
  23, 0x0,
  AI_SHAPE_INIT(4, 5, 1, 4, 10), AI_STRIDE_INIT(4, 4, 20, 20, 80),
  1, &node_46_weights_array, NULL)

/* Tensor #24 */
AI_TENSOR_OBJ_DECLARE(
  node_46_bias, AI_STATIC,
  24, 0x0,
  AI_SHAPE_INIT(4, 1, 10, 1, 1), AI_STRIDE_INIT(4, 4, 4, 40, 40),
  1, &node_46_bias_array, NULL)

/* Tensor #25 */
AI_TENSOR_OBJ_DECLARE(
  node_48_scale, AI_STATIC,
  25, 0x0,
  AI_SHAPE_INIT(4, 1, 10, 1, 1), AI_STRIDE_INIT(4, 4, 4, 40, 40),
  1, &node_48_scale_array, NULL)

/* Tensor #26 */
AI_TENSOR_OBJ_DECLARE(
  node_48_bias, AI_STATIC,
  26, 0x0,
  AI_SHAPE_INIT(4, 1, 10, 1, 1), AI_STRIDE_INIT(4, 4, 4, 40, 40),
  1, &node_48_bias_array, NULL)

/* Tensor #27 */
AI_TENSOR_OBJ_DECLARE(
  node_49_weights, AI_STATIC,
  27, 0x0,
  AI_SHAPE_INIT(4, 10, 1, 4, 20), AI_STRIDE_INIT(4, 4, 40, 40, 160),
  1, &node_49_weights_array, NULL)

/* Tensor #28 */
AI_TENSOR_OBJ_DECLARE(
  node_49_bias, AI_STATIC,
  28, 0x0,
  AI_SHAPE_INIT(4, 1, 20, 1, 1), AI_STRIDE_INIT(4, 4, 4, 80, 80),
  1, &node_49_bias_array, NULL)

/* Tensor #29 */
AI_TENSOR_OBJ_DECLARE(
  node_51_scale, AI_STATIC,
  29, 0x0,
  AI_SHAPE_INIT(4, 1, 20, 1, 1), AI_STRIDE_INIT(4, 4, 4, 80, 80),
  1, &node_51_scale_array, NULL)

/* Tensor #30 */
AI_TENSOR_OBJ_DECLARE(
  node_51_bias, AI_STATIC,
  30, 0x0,
  AI_SHAPE_INIT(4, 1, 20, 1, 1), AI_STRIDE_INIT(4, 4, 4, 80, 80),
  1, &node_51_bias_array, NULL)

/* Tensor #31 */
AI_TENSOR_OBJ_DECLARE(
  node_52_weights, AI_STATIC,
  31, 0x0,
  AI_SHAPE_INIT(4, 20, 1, 4, 20), AI_STRIDE_INIT(4, 4, 80, 80, 320),
  1, &node_52_weights_array, NULL)

/* Tensor #32 */
AI_TENSOR_OBJ_DECLARE(
  node_52_bias, AI_STATIC,
  32, 0x0,
  AI_SHAPE_INIT(4, 1, 20, 1, 1), AI_STRIDE_INIT(4, 4, 4, 80, 80),
  1, &node_52_bias_array, NULL)

/* Tensor #33 */
AI_TENSOR_OBJ_DECLARE(
  node_54_scale, AI_STATIC,
  33, 0x0,
  AI_SHAPE_INIT(4, 1, 20, 1, 1), AI_STRIDE_INIT(4, 4, 4, 80, 80),
  1, &node_54_scale_array, NULL)

/* Tensor #34 */
AI_TENSOR_OBJ_DECLARE(
  node_54_bias, AI_STATIC,
  34, 0x0,
  AI_SHAPE_INIT(4, 1, 20, 1, 1), AI_STRIDE_INIT(4, 4, 4, 80, 80),
  1, &node_54_bias_array, NULL)

/* Tensor #35 */
AI_TENSOR_OBJ_DECLARE(
  fc2_0_bias, AI_STATIC,
  35, 0x0,
  AI_SHAPE_INIT(4, 1, 2, 1, 1), AI_STRIDE_INIT(4, 4, 4, 8, 8),
  1, &fc2_0_bias_array, NULL)

/* Tensor #36 */
AI_TENSOR_OBJ_DECLARE(
  fc2_0_weight, AI_STATIC,
  36, 0x0,
  AI_SHAPE_INIT(4, 1, 10, 1, 2), AI_STRIDE_INIT(4, 4, 40, 80, 80),
  1, &fc2_0_weight_array, NULL)

/* Tensor #37 */
AI_TENSOR_OBJ_DECLARE(
  fc1_1_bias, AI_STATIC,
  37, 0x0,
  AI_SHAPE_INIT(4, 1, 10, 1, 1), AI_STRIDE_INIT(4, 4, 4, 40, 40),
  1, &fc1_1_bias_array, NULL)

/* Tensor #38 */
AI_TENSOR_OBJ_DECLARE(
  fc1_1_weight, AI_STATIC,
  38, 0x0,
  AI_SHAPE_INIT(4, 1, 740, 1, 10), AI_STRIDE_INIT(4, 4, 2960, 29600, 29600),
  1, &fc1_1_weight_array, NULL)



/**  Layer declarations section  **********************************************/


AI_TENSOR_CHAIN_OBJ_DECLARE(
  node_59_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &node_58_output, &fc2_0_weight, &fc2_0_bias),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &node_59_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  node_59_layer, 18,
  GEMM_TYPE, 0x0, NULL,
  gemm, forward_gemm,
  &node_59_chain,
  NULL, &node_59_layer, AI_STATIC, 
  .alpha = 1.0, 
  .beta = 1.0, 
  .tA = 0, 
  .tB = 1, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  node_58_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &node_57_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &node_58_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  node_58_layer, 17,
  NL_TYPE, 0x0, NULL,
  nl, forward_relu,
  &node_58_chain,
  NULL, &node_59_layer, AI_STATIC, 
  .nl_params = NULL, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  node_57_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &node_54_output0, &fc1_1_weight, &fc1_1_bias),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &node_57_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  node_57_layer, 16,
  GEMM_TYPE, 0x0, NULL,
  gemm, forward_gemm,
  &node_57_chain,
  NULL, &node_58_layer, AI_STATIC, 
  .alpha = 1.0, 
  .beta = 1.0, 
  .tA = 0, 
  .tB = 1, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  node_54_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &node_52_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &node_54_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &node_54_scale, &node_54_bias),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  node_54_layer, 14,
  BN_TYPE, 0x0, NULL,
  bn, forward_bn,
  &node_54_chain,
  NULL, &node_57_layer, AI_STATIC, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  node_52_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &node_51_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &node_52_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &node_52_weights, &node_52_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  node_52_layer, 13,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d,
  &node_52_chain,
  NULL, &node_54_layer, AI_STATIC, 
  .groups = 1, 
  .nl_params = NULL, 
  .nl_func = nl_func_relu_array_f32, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 2), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  node_51_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &node_49_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &node_51_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &node_51_scale, &node_51_bias),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  node_51_layer, 11,
  BN_TYPE, 0x0, NULL,
  bn, forward_bn,
  &node_51_chain,
  NULL, &node_52_layer, AI_STATIC, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  node_49_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &node_48_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &node_49_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &node_49_weights, &node_49_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  node_49_layer, 10,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d,
  &node_49_chain,
  NULL, &node_51_layer, AI_STATIC, 
  .groups = 1, 
  .nl_params = NULL, 
  .nl_func = nl_func_relu_array_f32, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 2), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  node_48_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &node_46_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &node_48_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &node_48_scale, &node_48_bias),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  node_48_layer, 8,
  BN_TYPE, 0x0, NULL,
  bn, forward_bn,
  &node_48_chain,
  NULL, &node_49_layer, AI_STATIC, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  node_46_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &node_45_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &node_46_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &node_46_weights, &node_46_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  node_46_layer, 7,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d,
  &node_46_chain,
  NULL, &node_48_layer, AI_STATIC, 
  .groups = 1, 
  .nl_params = NULL, 
  .nl_func = nl_func_relu_array_f32, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 2), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  node_45_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &node_43_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &node_45_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &node_45_scale, &node_45_bias),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  node_45_layer, 5,
  BN_TYPE, 0x0, NULL,
  bn, forward_bn,
  &node_45_chain,
  NULL, &node_46_layer, AI_STATIC, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  node_43_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &node_42_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &node_43_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &node_43_weights, &node_43_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  node_43_layer, 4,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d,
  &node_43_chain,
  NULL, &node_45_layer, AI_STATIC, 
  .groups = 1, 
  .nl_params = NULL, 
  .nl_func = nl_func_relu_array_f32, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 2), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  node_42_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &node_40_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &node_42_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &node_42_scale, &node_42_bias),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  node_42_layer, 2,
  BN_TYPE, 0x0, NULL,
  bn, forward_bn,
  &node_42_chain,
  NULL, &node_43_layer, AI_STATIC, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  node_40_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &input_1_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &node_40_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &node_40_weights, &node_40_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  node_40_layer, 1,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d,
  &node_40_chain,
  NULL, &node_42_layer, AI_STATIC, 
  .groups = 1, 
  .nl_params = NULL, 
  .nl_func = nl_func_relu_array_f32, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 2), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)


#if (AI_TOOLS_API_VERSION < AI_TOOLS_API_VERSION_1_5)

AI_NETWORK_OBJ_DECLARE(
  AI_NET_OBJ_INSTANCE, AI_STATIC,
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 41196, 1, 1),
    41196, NULL, NULL),
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 7984, 1, 1),
    7984, NULL, NULL),
  AI_TENSOR_LIST_IO_OBJ_INIT(AI_FLAG_NONE, AI_NETWORK_IN_NUM, &input_1_output),
  AI_TENSOR_LIST_IO_OBJ_INIT(AI_FLAG_NONE, AI_NETWORK_OUT_NUM, &node_59_output),
  &node_40_layer, 0, NULL)

#else

AI_NETWORK_OBJ_DECLARE(
  AI_NET_OBJ_INSTANCE, AI_STATIC,
  AI_BUFFER_ARRAY_OBJ_INIT_STATIC(
  	AI_FLAG_NONE, 1,
    AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
      AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 41196, 1, 1),
      41196, NULL, NULL)
  ),
  AI_BUFFER_ARRAY_OBJ_INIT_STATIC(
  	AI_FLAG_NONE, 1,
    AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
      AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 7984, 1, 1),
      7984, NULL, NULL)
  ),
  AI_TENSOR_LIST_IO_OBJ_INIT(AI_FLAG_NONE, AI_NETWORK_IN_NUM, &input_1_output),
  AI_TENSOR_LIST_IO_OBJ_INIT(AI_FLAG_NONE, AI_NETWORK_OUT_NUM, &node_59_output),
  &node_40_layer, 0, NULL)

#endif	/*(AI_TOOLS_API_VERSION < AI_TOOLS_API_VERSION_1_5)*/


/******************************************************************************/
AI_DECLARE_STATIC
ai_bool network_configure_activations(
  ai_network* net_ctx, const ai_network_params* params)
{
  AI_ASSERT(net_ctx)

  ai_ptr activations_map[1] = AI_C_ARRAY_INIT;

  if (ai_platform_get_activations_map(activations_map, 1, params)) {
    /* Updating activations (byte) offsets */
    node_40_output_array.data = AI_PTR(activations_map[0] + 508);
    node_40_output_array.data_start = AI_PTR(activations_map[0] + 508);
    node_42_output_array.data = AI_PTR(activations_map[0] + 508);
    node_42_output_array.data_start = AI_PTR(activations_map[0] + 508);
    node_43_output_array.data = AI_PTR(activations_map[0] + 460);
    node_43_output_array.data_start = AI_PTR(activations_map[0] + 460);
    node_45_output_array.data = AI_PTR(activations_map[0] + 460);
    node_45_output_array.data_start = AI_PTR(activations_map[0] + 460);
    node_46_output_array.data = AI_PTR(activations_map[0] + 360);
    node_46_output_array.data_start = AI_PTR(activations_map[0] + 360);
    node_48_output_array.data = AI_PTR(activations_map[0] + 360);
    node_48_output_array.data_start = AI_PTR(activations_map[0] + 360);
    node_49_output_array.data = AI_PTR(activations_map[0] + 160);
    node_49_output_array.data_start = AI_PTR(activations_map[0] + 160);
    node_51_output_array.data = AI_PTR(activations_map[0] + 160);
    node_51_output_array.data_start = AI_PTR(activations_map[0] + 160);
    node_52_output_array.data = AI_PTR(activations_map[0] + 0);
    node_52_output_array.data_start = AI_PTR(activations_map[0] + 0);
    node_54_output_array.data = AI_PTR(activations_map[0] + 2960);
    node_54_output_array.data_start = AI_PTR(activations_map[0] + 2960);
    node_57_output_array.data = AI_PTR(activations_map[0] + 0);
    node_57_output_array.data_start = AI_PTR(activations_map[0] + 0);
    node_58_output_array.data = AI_PTR(activations_map[0] + 40);
    node_58_output_array.data_start = AI_PTR(activations_map[0] + 40);
    
    return true;
  }
  AI_ERROR_TRAP(net_ctx, INIT_FAILED, NETWORK_ACTIVATIONS);
  return false;
}



/******************************************************************************/
AI_DECLARE_STATIC
ai_bool network_configure_weights(
  ai_network* net_ctx, const ai_network_params* params)
{
  AI_ASSERT(net_ctx)

  ai_ptr weights_map[1] = AI_C_ARRAY_INIT;

  if (ai_platform_get_weights_map(weights_map, 1, params)) {
    /* Updating weights (byte) offsets */
    
    node_40_weights_array.format |= AI_FMT_FLAG_CONST;
    node_40_weights_array.data = AI_PTR(weights_map[0] + 0);
    node_40_weights_array.data_start = AI_PTR(weights_map[0] + 0);
    node_40_bias_array.format |= AI_FMT_FLAG_CONST;
    node_40_bias_array.data = AI_PTR(weights_map[0] + 72);
    node_40_bias_array.data_start = AI_PTR(weights_map[0] + 72);
    node_42_scale_array.format |= AI_FMT_FLAG_CONST;
    node_42_scale_array.data = AI_PTR(weights_map[0] + 84);
    node_42_scale_array.data_start = AI_PTR(weights_map[0] + 84);
    node_42_bias_array.format |= AI_FMT_FLAG_CONST;
    node_42_bias_array.data = AI_PTR(weights_map[0] + 96);
    node_42_bias_array.data_start = AI_PTR(weights_map[0] + 96);
    node_43_weights_array.format |= AI_FMT_FLAG_CONST;
    node_43_weights_array.data = AI_PTR(weights_map[0] + 108);
    node_43_weights_array.data_start = AI_PTR(weights_map[0] + 108);
    node_43_bias_array.format |= AI_FMT_FLAG_CONST;
    node_43_bias_array.data = AI_PTR(weights_map[0] + 408);
    node_43_bias_array.data_start = AI_PTR(weights_map[0] + 408);
    node_45_scale_array.format |= AI_FMT_FLAG_CONST;
    node_45_scale_array.data = AI_PTR(weights_map[0] + 428);
    node_45_scale_array.data_start = AI_PTR(weights_map[0] + 428);
    node_45_bias_array.format |= AI_FMT_FLAG_CONST;
    node_45_bias_array.data = AI_PTR(weights_map[0] + 448);
    node_45_bias_array.data_start = AI_PTR(weights_map[0] + 448);
    node_46_weights_array.format |= AI_FMT_FLAG_CONST;
    node_46_weights_array.data = AI_PTR(weights_map[0] + 468);
    node_46_weights_array.data_start = AI_PTR(weights_map[0] + 468);
    node_46_bias_array.format |= AI_FMT_FLAG_CONST;
    node_46_bias_array.data = AI_PTR(weights_map[0] + 1268);
    node_46_bias_array.data_start = AI_PTR(weights_map[0] + 1268);
    node_48_scale_array.format |= AI_FMT_FLAG_CONST;
    node_48_scale_array.data = AI_PTR(weights_map[0] + 1308);
    node_48_scale_array.data_start = AI_PTR(weights_map[0] + 1308);
    node_48_bias_array.format |= AI_FMT_FLAG_CONST;
    node_48_bias_array.data = AI_PTR(weights_map[0] + 1348);
    node_48_bias_array.data_start = AI_PTR(weights_map[0] + 1348);
    node_49_weights_array.format |= AI_FMT_FLAG_CONST;
    node_49_weights_array.data = AI_PTR(weights_map[0] + 1388);
    node_49_weights_array.data_start = AI_PTR(weights_map[0] + 1388);
    node_49_bias_array.format |= AI_FMT_FLAG_CONST;
    node_49_bias_array.data = AI_PTR(weights_map[0] + 4588);
    node_49_bias_array.data_start = AI_PTR(weights_map[0] + 4588);
    node_51_scale_array.format |= AI_FMT_FLAG_CONST;
    node_51_scale_array.data = AI_PTR(weights_map[0] + 4668);
    node_51_scale_array.data_start = AI_PTR(weights_map[0] + 4668);
    node_51_bias_array.format |= AI_FMT_FLAG_CONST;
    node_51_bias_array.data = AI_PTR(weights_map[0] + 4748);
    node_51_bias_array.data_start = AI_PTR(weights_map[0] + 4748);
    node_52_weights_array.format |= AI_FMT_FLAG_CONST;
    node_52_weights_array.data = AI_PTR(weights_map[0] + 4828);
    node_52_weights_array.data_start = AI_PTR(weights_map[0] + 4828);
    node_52_bias_array.format |= AI_FMT_FLAG_CONST;
    node_52_bias_array.data = AI_PTR(weights_map[0] + 11228);
    node_52_bias_array.data_start = AI_PTR(weights_map[0] + 11228);
    node_54_scale_array.format |= AI_FMT_FLAG_CONST;
    node_54_scale_array.data = AI_PTR(weights_map[0] + 11308);
    node_54_scale_array.data_start = AI_PTR(weights_map[0] + 11308);
    node_54_bias_array.format |= AI_FMT_FLAG_CONST;
    node_54_bias_array.data = AI_PTR(weights_map[0] + 11388);
    node_54_bias_array.data_start = AI_PTR(weights_map[0] + 11388);
    fc2_0_bias_array.format |= AI_FMT_FLAG_CONST;
    fc2_0_bias_array.data = AI_PTR(weights_map[0] + 11468);
    fc2_0_bias_array.data_start = AI_PTR(weights_map[0] + 11468);
    fc2_0_weight_array.format |= AI_FMT_FLAG_CONST;
    fc2_0_weight_array.data = AI_PTR(weights_map[0] + 11476);
    fc2_0_weight_array.data_start = AI_PTR(weights_map[0] + 11476);
    fc1_1_bias_array.format |= AI_FMT_FLAG_CONST;
    fc1_1_bias_array.data = AI_PTR(weights_map[0] + 11556);
    fc1_1_bias_array.data_start = AI_PTR(weights_map[0] + 11556);
    fc1_1_weight_array.format |= AI_FMT_FLAG_CONST;
    fc1_1_weight_array.data = AI_PTR(weights_map[0] + 11596);
    fc1_1_weight_array.data_start = AI_PTR(weights_map[0] + 11596);
    return true;
  }
  AI_ERROR_TRAP(net_ctx, INIT_FAILED, NETWORK_WEIGHTS);
  return false;
}


/**  PUBLIC APIs SECTION  *****************************************************/

AI_DEPRECATED
AI_API_ENTRY
ai_bool ai_network_get_info(
  ai_handle network, ai_network_report* report)
{
  ai_network* net_ctx = AI_NETWORK_ACQUIRE_CTX(network);

  if (report && net_ctx)
  {
    ai_network_report r = {
      .model_name        = AI_NETWORK_MODEL_NAME,
      .model_signature   = AI_NETWORK_MODEL_SIGNATURE,
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
      
      .n_macc            = 214421,
      .n_inputs          = 0,
      .inputs            = NULL,
      .n_outputs         = 0,
      .outputs           = NULL,
      .params            = AI_STRUCT_INIT,
      .activations       = AI_STRUCT_INIT,
      .n_nodes           = 0,
      .signature         = 0x0,
    };

    if (!ai_platform_api_get_network_report(network, &r)) return false;

    *report = r;
    return true;
  }
  return false;
}


AI_API_ENTRY
ai_bool ai_network_get_report(
  ai_handle network, ai_network_report* report)
{
  ai_network* net_ctx = AI_NETWORK_ACQUIRE_CTX(network);

  if (report && net_ctx)
  {
    ai_network_report r = {
      .model_name        = AI_NETWORK_MODEL_NAME,
      .model_signature   = AI_NETWORK_MODEL_SIGNATURE,
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
      
      .n_macc            = 214421,
      .n_inputs          = 0,
      .inputs            = NULL,
      .n_outputs         = 0,
      .outputs           = NULL,
      .map_signature     = AI_MAGIC_SIGNATURE,
      .map_weights       = AI_STRUCT_INIT,
      .map_activations   = AI_STRUCT_INIT,
      .n_nodes           = 0,
      .signature         = 0x0,
    };

    if (!ai_platform_api_get_network_report(network, &r)) return false;

    *report = r;
    return true;
  }
  return false;
}

AI_API_ENTRY
ai_error ai_network_get_error(ai_handle network)
{
  return ai_platform_network_get_error(network);
}

AI_API_ENTRY
ai_error ai_network_create(
  ai_handle* network, const ai_buffer* network_config)
{
  return ai_platform_network_create(
    network, network_config, 
    &AI_NET_OBJ_INSTANCE,
    AI_TOOLS_API_VERSION_MAJOR, AI_TOOLS_API_VERSION_MINOR, AI_TOOLS_API_VERSION_MICRO);
}

AI_API_ENTRY
ai_error ai_network_create_and_init(
  ai_handle* network, const ai_handle activations[], const ai_handle weights[])
{
    ai_error err;
    ai_network_params params;

    err = ai_network_create(network, AI_NETWORK_DATA_CONFIG);
    if (err.type != AI_ERROR_NONE)
        return err;
    if (ai_network_data_params_get(&params) != true) {
        err = ai_network_get_error(*network);
        return err;
    }
#if defined(AI_NETWORK_DATA_ACTIVATIONS_COUNT)
    if (activations) {
        /* set the addresses of the activations buffers */
        for (int idx=0;idx<params.map_activations.size;idx++)
            AI_BUFFER_ARRAY_ITEM_SET_ADDRESS(&params.map_activations, idx, activations[idx]);
    }
#endif
#if defined(AI_NETWORK_DATA_WEIGHTS_COUNT)
    if (weights) {
        /* set the addresses of the weight buffers */
        for (int idx=0;idx<params.map_weights.size;idx++)
            AI_BUFFER_ARRAY_ITEM_SET_ADDRESS(&params.map_weights, idx, weights[idx]);
    }
#endif
    if (ai_network_init(*network, &params) != true) {
        err = ai_network_get_error(*network);
    }
    return err;
}

AI_API_ENTRY
ai_buffer* ai_network_inputs_get(ai_handle network, ai_u16 *n_buffer)
{
  if (network == AI_HANDLE_NULL) {
    network = (ai_handle)&AI_NET_OBJ_INSTANCE;
    ((ai_network *)network)->magic = AI_MAGIC_CONTEXT_TOKEN;
  }
  return ai_platform_inputs_get(network, n_buffer);
}

AI_API_ENTRY
ai_buffer* ai_network_outputs_get(ai_handle network, ai_u16 *n_buffer)
{
  if (network == AI_HANDLE_NULL) {
    network = (ai_handle)&AI_NET_OBJ_INSTANCE;
    ((ai_network *)network)->magic = AI_MAGIC_CONTEXT_TOKEN;
  }
  return ai_platform_outputs_get(network, n_buffer);
}

AI_API_ENTRY
ai_handle ai_network_destroy(ai_handle network)
{
  return ai_platform_network_destroy(network);
}

AI_API_ENTRY
ai_bool ai_network_init(
  ai_handle network, const ai_network_params* params)
{
  ai_network* net_ctx = ai_platform_network_init(network, params);
  if (!net_ctx) return false;

  ai_bool ok = true;
  ok &= network_configure_weights(net_ctx, params);
  ok &= network_configure_activations(net_ctx, params);

  ok &= ai_platform_network_post_init(network);

  return ok;
}


AI_API_ENTRY
ai_i32 ai_network_run(
  ai_handle network, const ai_buffer* input, ai_buffer* output)
{
  return ai_platform_network_process(network, input, output);
}

AI_API_ENTRY
ai_i32 ai_network_forward(ai_handle network, const ai_buffer* input)
{
  return ai_platform_network_process(network, input, NULL);
}



#undef AI_NETWORK_MODEL_SIGNATURE
#undef AI_NET_OBJ_INSTANCE
#undef AI_TOOLS_DATE_TIME
#undef AI_TOOLS_COMPILE_TIME

