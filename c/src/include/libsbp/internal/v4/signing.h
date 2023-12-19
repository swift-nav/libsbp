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
 * Automatically generated from yaml/swiftnav/sbp/signing.yaml
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

#ifndef LIBSBP_INTERNAL_V4_SIGNING_H
#define LIBSBP_INTERNAL_V4_SIGNING_H

#include <stdbool.h>

#include <libsbp/internal/v4/common.h>
#include <libsbp/signing.h>

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
bool sbp_utc_time_encode_internal(sbp_encode_ctx_t *ctx,
                                  const sbp_utc_time_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_utc_time_decode_internal(sbp_decode_ctx_t *ctx, sbp_utc_time_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_ecdsa_signature_encode_internal(sbp_encode_ctx_t *ctx,
                                         const sbp_ecdsa_signature_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_ecdsa_signature_decode_internal(sbp_decode_ctx_t *ctx,
                                         sbp_ecdsa_signature_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_ecdsa_certificate_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_ecdsa_certificate_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_ecdsa_certificate_decode_internal(
    sbp_decode_ctx_t *ctx, sbp_msg_ecdsa_certificate_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_certificate_chain_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_certificate_chain_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_certificate_chain_decode_internal(
    sbp_decode_ctx_t *ctx, sbp_msg_certificate_chain_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_certificate_chain_dep_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_certificate_chain_dep_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_certificate_chain_dep_decode_internal(
    sbp_decode_ctx_t *ctx, sbp_msg_certificate_chain_dep_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_ecdsa_signature_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_ecdsa_signature_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_ecdsa_signature_decode_internal(sbp_decode_ctx_t *ctx,
                                             sbp_msg_ecdsa_signature_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_ecdsa_signature_dep_b_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_ecdsa_signature_dep_b_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_ecdsa_signature_dep_b_decode_internal(
    sbp_decode_ctx_t *ctx, sbp_msg_ecdsa_signature_dep_b_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_ecdsa_signature_dep_a_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_ecdsa_signature_dep_a_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_ecdsa_signature_dep_a_decode_internal(
    sbp_decode_ctx_t *ctx, sbp_msg_ecdsa_signature_dep_a_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_ed25519_certificate_dep_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_ed25519_certificate_dep_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_ed25519_certificate_dep_decode_internal(
    sbp_decode_ctx_t *ctx, sbp_msg_ed25519_certificate_dep_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_ed25519_signature_dep_a_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_ed25519_signature_dep_a_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_ed25519_signature_dep_a_decode_internal(
    sbp_decode_ctx_t *ctx, sbp_msg_ed25519_signature_dep_a_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_ed25519_signature_dep_b_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_ed25519_signature_dep_b_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_ed25519_signature_dep_b_decode_internal(
    sbp_decode_ctx_t *ctx, sbp_msg_ed25519_signature_dep_b_t *msg);

#ifdef __cplusplus
}
#endif

#endif /* LIBSBP_INTERNAL_V4_SIGNING_H */
