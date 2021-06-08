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
 * Automatically generated from yaml/swiftnav/sbp/bootload.yaml
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

#ifndef LIBSBP_UNPACKED_BOOTLOAD_PRIVATE_H
#define LIBSBP_UNPACKED_BOOTLOAD_PRIVATE_H

#include <stdbool.h>

#include <libsbp/internal/new/common.h>
#include <libsbp/new/bootload.h>

#ifdef __cplusplus
extern "C" {
#endif

bool encode_sbp_msg_bootloader_handshake_req_t(
    sbp_encode_ctx_t *ctx, const sbp_msg_bootloader_handshake_req_t *msg);
bool decode_sbp_msg_bootloader_handshake_req_t(
    sbp_decode_ctx_t *ctx, sbp_msg_bootloader_handshake_req_t *msg);

bool encode_sbp_msg_bootloader_handshake_resp_t(
    sbp_encode_ctx_t *ctx, const sbp_msg_bootloader_handshake_resp_t *msg);
bool decode_sbp_msg_bootloader_handshake_resp_t(
    sbp_decode_ctx_t *ctx, sbp_msg_bootloader_handshake_resp_t *msg);

bool encode_sbp_msg_bootloader_jump_to_app_t(
    sbp_encode_ctx_t *ctx, const sbp_msg_bootloader_jump_to_app_t *msg);
bool decode_sbp_msg_bootloader_jump_to_app_t(
    sbp_decode_ctx_t *ctx, sbp_msg_bootloader_jump_to_app_t *msg);

bool encode_sbp_msg_nap_device_dna_req_t(
    sbp_encode_ctx_t *ctx, const sbp_msg_nap_device_dna_req_t *msg);
bool decode_sbp_msg_nap_device_dna_req_t(sbp_decode_ctx_t *ctx,
                                         sbp_msg_nap_device_dna_req_t *msg);

bool encode_sbp_msg_nap_device_dna_resp_t(
    sbp_encode_ctx_t *ctx, const sbp_msg_nap_device_dna_resp_t *msg);
bool decode_sbp_msg_nap_device_dna_resp_t(sbp_decode_ctx_t *ctx,
                                          sbp_msg_nap_device_dna_resp_t *msg);

bool encode_sbp_msg_bootloader_handshake_dep_a_t(
    sbp_encode_ctx_t *ctx, const sbp_msg_bootloader_handshake_dep_a_t *msg);
bool decode_sbp_msg_bootloader_handshake_dep_a_t(
    sbp_decode_ctx_t *ctx, sbp_msg_bootloader_handshake_dep_a_t *msg);

#ifdef __cplusplus
}
#endif

#endif
