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
 * Automatically generated from yaml/swiftnav/sbp/tracking.yaml
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

#ifndef LIBSBP_UNPACKED_TRACKING_PRIVATE_H
#define LIBSBP_UNPACKED_TRACKING_PRIVATE_H

#include <stdbool.h>

#include <libsbp/internal/new/common.h>
#include <libsbp/internal/new/gnss.h>
#include <libsbp/new/tracking.h>

#ifdef __cplusplus
extern "C" {
#endif

bool encode_sbp_msg_tracking_state_detailed_dep_a_t(
    sbp_encode_ctx_t *ctx, const sbp_msg_tracking_state_detailed_dep_a_t *msg);
bool decode_sbp_msg_tracking_state_detailed_dep_a_t(
    sbp_decode_ctx_t *ctx, sbp_msg_tracking_state_detailed_dep_a_t *msg);

bool encode_sbp_msg_tracking_state_detailed_dep_t(
    sbp_encode_ctx_t *ctx, const sbp_msg_tracking_state_detailed_dep_t *msg);
bool decode_sbp_msg_tracking_state_detailed_dep_t(
    sbp_decode_ctx_t *ctx, sbp_msg_tracking_state_detailed_dep_t *msg);

bool encode_sbp_tracking_channel_state_t(
    sbp_encode_ctx_t *ctx, const sbp_tracking_channel_state_t *msg);
bool decode_sbp_tracking_channel_state_t(sbp_decode_ctx_t *ctx,
                                         sbp_tracking_channel_state_t *msg);

bool encode_sbp_msg_tracking_state_t(sbp_encode_ctx_t *ctx,
                                     const sbp_msg_tracking_state_t *msg);
bool decode_sbp_msg_tracking_state_t(sbp_decode_ctx_t *ctx,
                                     sbp_msg_tracking_state_t *msg);

bool encode_sbp_measurement_state_t(sbp_encode_ctx_t *ctx,
                                    const sbp_measurement_state_t *msg);
bool decode_sbp_measurement_state_t(sbp_decode_ctx_t *ctx,
                                    sbp_measurement_state_t *msg);

bool encode_sbp_msg_measurement_state_t(sbp_encode_ctx_t *ctx,
                                        const sbp_msg_measurement_state_t *msg);
bool decode_sbp_msg_measurement_state_t(sbp_decode_ctx_t *ctx,
                                        sbp_msg_measurement_state_t *msg);

bool encode_sbp_tracking_channel_correlation_t(
    sbp_encode_ctx_t *ctx, const sbp_tracking_channel_correlation_t *msg);
bool decode_sbp_tracking_channel_correlation_t(
    sbp_decode_ctx_t *ctx, sbp_tracking_channel_correlation_t *msg);

bool encode_sbp_msg_tracking_iq_t(sbp_encode_ctx_t *ctx,
                                  const sbp_msg_tracking_iq_t *msg);
bool decode_sbp_msg_tracking_iq_t(sbp_decode_ctx_t *ctx,
                                  sbp_msg_tracking_iq_t *msg);

bool encode_sbp_tracking_channel_correlation_dep_t(
    sbp_encode_ctx_t *ctx, const sbp_tracking_channel_correlation_dep_t *msg);
bool decode_sbp_tracking_channel_correlation_dep_t(
    sbp_decode_ctx_t *ctx, sbp_tracking_channel_correlation_dep_t *msg);

bool encode_sbp_msg_tracking_iq_dep_b_t(sbp_encode_ctx_t *ctx,
                                        const sbp_msg_tracking_iq_dep_b_t *msg);
bool decode_sbp_msg_tracking_iq_dep_b_t(sbp_decode_ctx_t *ctx,
                                        sbp_msg_tracking_iq_dep_b_t *msg);

bool encode_sbp_msg_tracking_iq_dep_a_t(sbp_encode_ctx_t *ctx,
                                        const sbp_msg_tracking_iq_dep_a_t *msg);
bool decode_sbp_msg_tracking_iq_dep_a_t(sbp_decode_ctx_t *ctx,
                                        sbp_msg_tracking_iq_dep_a_t *msg);

bool encode_sbp_tracking_channel_state_dep_a_t(
    sbp_encode_ctx_t *ctx, const sbp_tracking_channel_state_dep_a_t *msg);
bool decode_sbp_tracking_channel_state_dep_a_t(
    sbp_decode_ctx_t *ctx, sbp_tracking_channel_state_dep_a_t *msg);

bool encode_sbp_msg_tracking_state_dep_a_t(
    sbp_encode_ctx_t *ctx, const sbp_msg_tracking_state_dep_a_t *msg);
bool decode_sbp_msg_tracking_state_dep_a_t(sbp_decode_ctx_t *ctx,
                                           sbp_msg_tracking_state_dep_a_t *msg);

bool encode_sbp_tracking_channel_state_dep_b_t(
    sbp_encode_ctx_t *ctx, const sbp_tracking_channel_state_dep_b_t *msg);
bool decode_sbp_tracking_channel_state_dep_b_t(
    sbp_decode_ctx_t *ctx, sbp_tracking_channel_state_dep_b_t *msg);

bool encode_sbp_msg_tracking_state_dep_b_t(
    sbp_encode_ctx_t *ctx, const sbp_msg_tracking_state_dep_b_t *msg);
bool decode_sbp_msg_tracking_state_dep_b_t(sbp_decode_ctx_t *ctx,
                                           sbp_msg_tracking_state_dep_b_t *msg);

#ifdef __cplusplus
}
#endif

#endif
