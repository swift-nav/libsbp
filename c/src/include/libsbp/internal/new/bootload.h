#ifndef LIBSBP_UNPACKED_BOOTLOAD_PRIVATE_H
#define LIBSBP_UNPACKED_BOOTLOAD_PRIVATE_H

#include <stdbool.h>

#include <libsbp/new/bootload.h>
#include <libsbp/internal/new/common.h>

#ifdef __cplusplus
  extern "C" {
#endif

bool encode_sbp_msg_bootloader_handshake_req_t(sbp_encode_ctx_t *ctx, const sbp_msg_bootloader_handshake_req_t *msg);
bool decode_sbp_msg_bootloader_handshake_req_t(sbp_decode_ctx_t *ctx, sbp_msg_bootloader_handshake_req_t *msg);

bool encode_sbp_msg_bootloader_handshake_resp_t(sbp_encode_ctx_t *ctx, const sbp_msg_bootloader_handshake_resp_t *msg);
bool decode_sbp_msg_bootloader_handshake_resp_t(sbp_decode_ctx_t *ctx, sbp_msg_bootloader_handshake_resp_t *msg);

bool encode_sbp_msg_bootloader_jump_to_app_t(sbp_encode_ctx_t *ctx, const sbp_msg_bootloader_jump_to_app_t *msg);
bool decode_sbp_msg_bootloader_jump_to_app_t(sbp_decode_ctx_t *ctx, sbp_msg_bootloader_jump_to_app_t *msg);

bool encode_sbp_msg_nap_device_dna_req_t(sbp_encode_ctx_t *ctx, const sbp_msg_nap_device_dna_req_t *msg);
bool decode_sbp_msg_nap_device_dna_req_t(sbp_decode_ctx_t *ctx, sbp_msg_nap_device_dna_req_t *msg);

bool encode_sbp_msg_nap_device_dna_resp_t(sbp_encode_ctx_t *ctx, const sbp_msg_nap_device_dna_resp_t *msg);
bool decode_sbp_msg_nap_device_dna_resp_t(sbp_decode_ctx_t *ctx, sbp_msg_nap_device_dna_resp_t *msg);

bool encode_sbp_msg_bootloader_handshake_dep_a_t(sbp_encode_ctx_t *ctx, const sbp_msg_bootloader_handshake_dep_a_t *msg);
bool decode_sbp_msg_bootloader_handshake_dep_a_t(sbp_decode_ctx_t *ctx, sbp_msg_bootloader_handshake_dep_a_t *msg);

#ifdef __cplusplus
  }
#endif

#endif
