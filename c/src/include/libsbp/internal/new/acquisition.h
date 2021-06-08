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
 * Automatically generated from yaml/swiftnav/sbp/acquisition.yaml
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

#ifndef LIBSBP_INTERNAL_NEW_ACQUISITION_H
#define LIBSBP_INTERNAL_NEW_ACQUISITION_H

#include <stdbool.h>

#include <libsbp/internal/new/common.h>
#include <libsbp/internal/new/gnss.h>
#include <libsbp/new/acquisition.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool encode_sbp_msg_acq_result_t(sbp_encode_ctx_t *ctx,
                                 const sbp_msg_acq_result_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool decode_sbp_msg_acq_result_t(sbp_decode_ctx_t *ctx,
                                 sbp_msg_acq_result_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool encode_sbp_msg_acq_result_dep_c_t(sbp_encode_ctx_t *ctx,
                                       const sbp_msg_acq_result_dep_c_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool decode_sbp_msg_acq_result_dep_c_t(sbp_decode_ctx_t *ctx,
                                       sbp_msg_acq_result_dep_c_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool encode_sbp_msg_acq_result_dep_b_t(sbp_encode_ctx_t *ctx,
                                       const sbp_msg_acq_result_dep_b_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool decode_sbp_msg_acq_result_dep_b_t(sbp_decode_ctx_t *ctx,
                                       sbp_msg_acq_result_dep_b_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool encode_sbp_msg_acq_result_dep_a_t(sbp_encode_ctx_t *ctx,
                                       const sbp_msg_acq_result_dep_a_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool decode_sbp_msg_acq_result_dep_a_t(sbp_decode_ctx_t *ctx,
                                       sbp_msg_acq_result_dep_a_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool encode_sbp_acq_sv_profile_t(sbp_encode_ctx_t *ctx,
                                 const sbp_acq_sv_profile_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool decode_sbp_acq_sv_profile_t(sbp_decode_ctx_t *ctx,
                                 sbp_acq_sv_profile_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool encode_sbp_acq_sv_profile_dep_t(sbp_encode_ctx_t *ctx,
                                     const sbp_acq_sv_profile_dep_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool decode_sbp_acq_sv_profile_dep_t(sbp_decode_ctx_t *ctx,
                                     sbp_acq_sv_profile_dep_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool encode_sbp_msg_acq_sv_profile_t(sbp_encode_ctx_t *ctx,
                                     const sbp_msg_acq_sv_profile_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool decode_sbp_msg_acq_sv_profile_t(sbp_decode_ctx_t *ctx,
                                     sbp_msg_acq_sv_profile_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool encode_sbp_msg_acq_sv_profile_dep_t(
    sbp_encode_ctx_t *ctx, const sbp_msg_acq_sv_profile_dep_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool decode_sbp_msg_acq_sv_profile_dep_t(sbp_decode_ctx_t *ctx,
                                         sbp_msg_acq_sv_profile_dep_t *msg);

#ifdef __cplusplus
}
#endif

#endif
