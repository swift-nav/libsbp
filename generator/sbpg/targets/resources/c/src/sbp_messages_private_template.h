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
 * Automatically generated from yaml/(((package.filepath)))
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

#ifndef LIBSBP_INTERNAL_V4_(((package.name|upper)))_H
#define LIBSBP_INTERNAL_V4_(((package.name|upper)))_H

#include <stdbool.h>

#include <libsbp/v4/(((package.name))).h>
#include <libsbp/internal/v4/common.h>
((*- for i in package.includes *))
#include <libsbp/internal/v4/(((i))).h>
((*- endfor *))

#ifdef __cplusplus
  extern "C" {
#endif

((*- for m in package.msgs *))

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool (((m.internal_encode_fn)))(sbp_encode_ctx_t *ctx, const (((m.type_name))) *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool (((m.internal_decode_fn)))(sbp_decode_ctx_t *ctx, (((m.type_name))) *msg);

((*- endfor *))

#ifdef __cplusplus
  }
#endif

#endif /* LIBSBP_INTERNAL_V4_(((package.name|upper)))_H */

