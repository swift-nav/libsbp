/*
 * Copyright (C) 2015-2021 Swift Navigation Inc.
 * Contact: https://support.swiftnav.com
 *
 * This source is subject to the license found in the file 'LICENSE' which must
 * be be distributed together with this source. All other rights reserved.
 *
 * THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
 * EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
 */

/*****************************************************************************
 * Automatically generated from yaml/(((filepath)))
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

#ifndef LIBSBP_INTERNAL_NEW_(((pkg_name|upper)))_H
#define LIBSBP_INTERNAL_NEW_(((pkg_name|upper)))_H

#include <stdbool.h>

#include <libsbp/v4/(((pkg_name))).h>
#include <libsbp/internal/v4/common.h>
((*- for i in include *))
#include <libsbp/internal/v4/(((i)))>
((*- endfor *))

#ifdef __cplusplus
  extern "C" {
#endif

((*- for m in msgs *))

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool encode_(((m.name|convert_unpacked)))(sbp_encode_ctx_t *ctx, const (((m.name|convert_unpacked))) *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool decode_(((m.name|convert_unpacked)))(sbp_decode_ctx_t *ctx, (((m.name|convert_unpacked))) *msg);

((*- endfor *))

#ifdef __cplusplus
  }
#endif

#endif

