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
 * Automatically generated from yaml/swiftnav/sbp/bootload.yaml
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

#ifndef LIBSBP_INTERNAL_V4_BOOTLOAD_H
#define LIBSBP_INTERNAL_V4_BOOTLOAD_H

#include <stdbool.h>

#include <libsbp/internal/v4/common.h>
#include <libsbp/v4/bootload.h>

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
bool sbp_msg_bootloader_handshake_req_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_bootloader_handshake_req_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_bootloader_handshake_req_decode_internal(
    sbp_decode_ctx_t *ctx, sbp_msg_bootloader_handshake_req_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_bootloader_handshake_resp_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_bootloader_handshake_resp_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_bootloader_handshake_resp_decode_internal(
    sbp_decode_ctx_t *ctx, sbp_msg_bootloader_handshake_resp_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_bootloader_jump_to_app_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_bootloader_jump_to_app_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_bootloader_jump_to_app_decode_internal(
    sbp_decode_ctx_t *ctx, sbp_msg_bootloader_jump_to_app_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_nap_device_dna_req_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_nap_device_dna_req_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_nap_device_dna_req_decode_internal(
    sbp_decode_ctx_t *ctx, sbp_msg_nap_device_dna_req_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_nap_device_dna_resp_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_nap_device_dna_resp_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_nap_device_dna_resp_decode_internal(
    sbp_decode_ctx_t *ctx, sbp_msg_nap_device_dna_resp_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_bootloader_handshake_dep_a_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_bootloader_handshake_dep_a_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_bootloader_handshake_dep_a_decode_internal(
    sbp_decode_ctx_t *ctx, sbp_msg_bootloader_handshake_dep_a_t *msg);

#ifdef __cplusplus
}
#endif

#endif /* LIBSBP_INTERNAL_V4_BOOTLOAD_H */
