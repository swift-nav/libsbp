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
 * Automatically generated from yaml/swiftnav/sbp/acquisition.yaml
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

#ifndef LIBSBP_UNPACKED_ACQUISITION_PRIVATE_H
#define LIBSBP_UNPACKED_ACQUISITION_PRIVATE_H

#include <stdbool.h>

#include <libsbp/internal/new/common.h>
#include <libsbp/internal/new/gnss.h>
#include <libsbp/new/acquisition.h>

#ifdef __cplusplus
extern "C" {
#endif

bool encode_sbp_msg_acq_result_t(sbp_encode_ctx_t *ctx,
                                 const sbp_msg_acq_result_t *msg);
bool decode_sbp_msg_acq_result_t(sbp_decode_ctx_t *ctx,
                                 sbp_msg_acq_result_t *msg);

bool encode_sbp_msg_acq_result_dep_c_t(sbp_encode_ctx_t *ctx,
                                       const sbp_msg_acq_result_dep_c_t *msg);
bool decode_sbp_msg_acq_result_dep_c_t(sbp_decode_ctx_t *ctx,
                                       sbp_msg_acq_result_dep_c_t *msg);

bool encode_sbp_msg_acq_result_dep_b_t(sbp_encode_ctx_t *ctx,
                                       const sbp_msg_acq_result_dep_b_t *msg);
bool decode_sbp_msg_acq_result_dep_b_t(sbp_decode_ctx_t *ctx,
                                       sbp_msg_acq_result_dep_b_t *msg);

bool encode_sbp_msg_acq_result_dep_a_t(sbp_encode_ctx_t *ctx,
                                       const sbp_msg_acq_result_dep_a_t *msg);
bool decode_sbp_msg_acq_result_dep_a_t(sbp_decode_ctx_t *ctx,
                                       sbp_msg_acq_result_dep_a_t *msg);

bool encode_sbp_acq_sv_profile_t(sbp_encode_ctx_t *ctx,
                                 const sbp_acq_sv_profile_t *msg);
bool decode_sbp_acq_sv_profile_t(sbp_decode_ctx_t *ctx,
                                 sbp_acq_sv_profile_t *msg);

bool encode_sbp_acq_sv_profile_dep_t(sbp_encode_ctx_t *ctx,
                                     const sbp_acq_sv_profile_dep_t *msg);
bool decode_sbp_acq_sv_profile_dep_t(sbp_decode_ctx_t *ctx,
                                     sbp_acq_sv_profile_dep_t *msg);

bool encode_sbp_msg_acq_sv_profile_t(sbp_encode_ctx_t *ctx,
                                     const sbp_msg_acq_sv_profile_t *msg);
bool decode_sbp_msg_acq_sv_profile_t(sbp_decode_ctx_t *ctx,
                                     sbp_msg_acq_sv_profile_t *msg);

bool encode_sbp_msg_acq_sv_profile_dep_t(
    sbp_encode_ctx_t *ctx, const sbp_msg_acq_sv_profile_dep_t *msg);
bool decode_sbp_msg_acq_sv_profile_dep_t(sbp_decode_ctx_t *ctx,
                                         sbp_msg_acq_sv_profile_dep_t *msg);

#ifdef __cplusplus
}
#endif

#endif
