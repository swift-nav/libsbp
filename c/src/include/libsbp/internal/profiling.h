/*
 * Copyright (C) 2015-2021 Swift Navigation Inc.
 * Contact: https://support.swiftnav.com
 *
 * This source is subject to the license found in the file 'LICENSE' which must
 * be distributed together with this source. All other rights reserved.
 *
 * THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
 * EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
 */

/*****************************************************************************
 * Automatically generated from yaml/swiftnav/sbp/profiling.yaml
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

#ifndef LIBSBP_INTERNAL_PROFILING_H
#define LIBSBP_INTERNAL_PROFILING_H

#include <stdbool.h>

#include <libsbp/internal/common.h>
#include <libsbp/profiling.h>

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
bool sbp_msg_measurement_point_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_measurement_point_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_measurement_point_decode_internal(
    sbp_decode_ctx_t *ctx, sbp_msg_measurement_point_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_profiling_system_info_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_profiling_system_info_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_profiling_system_info_decode_internal(
    sbp_decode_ctx_t *ctx, sbp_msg_profiling_system_info_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_profiling_thread_info_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_profiling_thread_info_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_profiling_thread_info_decode_internal(
    sbp_decode_ctx_t *ctx, sbp_msg_profiling_thread_info_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_resource_bucket_encode_internal(sbp_encode_ctx_t *ctx,
                                         const sbp_resource_bucket_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_resource_bucket_decode_internal(sbp_decode_ctx_t *ctx,
                                         sbp_resource_bucket_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_profiling_resource_counter_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_profiling_resource_counter_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_profiling_resource_counter_decode_internal(
    sbp_decode_ctx_t *ctx, sbp_msg_profiling_resource_counter_t *msg);

#ifdef __cplusplus
}
#endif

#endif /* LIBSBP_INTERNAL_PROFILING_H */
