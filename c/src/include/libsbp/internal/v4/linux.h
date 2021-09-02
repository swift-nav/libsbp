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
 * Automatically generated from yaml/swiftnav/sbp/linux.yaml
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

#ifndef LIBSBP_INTERNAL_V4_LINUX_H
#define LIBSBP_INTERNAL_V4_LINUX_H

#include <stdbool.h>

#include <libsbp/internal/v4/common.h>
#include <libsbp/v4/linux.h>

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
bool sbp_msg_linux_cpu_state_dep_a_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_linux_cpu_state_dep_a_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_linux_cpu_state_dep_a_decode_internal(
    sbp_decode_ctx_t *ctx, sbp_msg_linux_cpu_state_dep_a_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_linux_mem_state_dep_a_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_linux_mem_state_dep_a_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_linux_mem_state_dep_a_decode_internal(
    sbp_decode_ctx_t *ctx, sbp_msg_linux_mem_state_dep_a_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_linux_sys_state_dep_a_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_linux_sys_state_dep_a_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_linux_sys_state_dep_a_decode_internal(
    sbp_decode_ctx_t *ctx, sbp_msg_linux_sys_state_dep_a_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_linux_process_socket_counts_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_linux_process_socket_counts_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_linux_process_socket_counts_decode_internal(
    sbp_decode_ctx_t *ctx, sbp_msg_linux_process_socket_counts_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_linux_process_socket_queues_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_linux_process_socket_queues_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_linux_process_socket_queues_decode_internal(
    sbp_decode_ctx_t *ctx, sbp_msg_linux_process_socket_queues_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_linux_socket_usage_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_linux_socket_usage_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_linux_socket_usage_decode_internal(
    sbp_decode_ctx_t *ctx, sbp_msg_linux_socket_usage_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_linux_process_fd_count_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_linux_process_fd_count_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_linux_process_fd_count_decode_internal(
    sbp_decode_ctx_t *ctx, sbp_msg_linux_process_fd_count_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_linux_process_fd_summary_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_linux_process_fd_summary_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_linux_process_fd_summary_decode_internal(
    sbp_decode_ctx_t *ctx, sbp_msg_linux_process_fd_summary_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_linux_cpu_state_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_linux_cpu_state_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_linux_cpu_state_decode_internal(sbp_decode_ctx_t *ctx,
                                             sbp_msg_linux_cpu_state_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_linux_mem_state_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_linux_mem_state_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_linux_mem_state_decode_internal(sbp_decode_ctx_t *ctx,
                                             sbp_msg_linux_mem_state_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_linux_sys_state_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_linux_sys_state_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_linux_sys_state_decode_internal(sbp_decode_ctx_t *ctx,
                                             sbp_msg_linux_sys_state_t *msg);

#ifdef __cplusplus
}
#endif

#endif /* LIBSBP_INTERNAL_V4_LINUX_H */
