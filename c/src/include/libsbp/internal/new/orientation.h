/*
 * Copyright (C) 2015-2018 Swift Navigation Inc.
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
 * Automatically generated from yaml/swiftnav/sbp/orientation.yaml
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

#ifndef LIBSBP_UNPACKED_ORIENTATION_PRIVATE_H
#define LIBSBP_UNPACKED_ORIENTATION_PRIVATE_H

#include <stdbool.h>

#include <libsbp/internal/new/common.h>
#include <libsbp/new/orientation.h>

#ifdef __cplusplus
extern "C" {
#endif

bool encode_sbp_msg_baseline_heading_t(sbp_encode_ctx_t *ctx,
                                       const sbp_msg_baseline_heading_t *msg);
bool decode_sbp_msg_baseline_heading_t(sbp_decode_ctx_t *ctx,
                                       sbp_msg_baseline_heading_t *msg);

bool encode_sbp_msg_orient_quat_t(sbp_encode_ctx_t *ctx,
                                  const sbp_msg_orient_quat_t *msg);
bool decode_sbp_msg_orient_quat_t(sbp_decode_ctx_t *ctx,
                                  sbp_msg_orient_quat_t *msg);

bool encode_sbp_msg_orient_euler_t(sbp_encode_ctx_t *ctx,
                                   const sbp_msg_orient_euler_t *msg);
bool decode_sbp_msg_orient_euler_t(sbp_decode_ctx_t *ctx,
                                   sbp_msg_orient_euler_t *msg);

bool encode_sbp_msg_angular_rate_t(sbp_encode_ctx_t *ctx,
                                   const sbp_msg_angular_rate_t *msg);
bool decode_sbp_msg_angular_rate_t(sbp_decode_ctx_t *ctx,
                                   sbp_msg_angular_rate_t *msg);

#ifdef __cplusplus
}
#endif

#endif
