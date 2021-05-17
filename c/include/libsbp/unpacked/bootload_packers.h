#ifndef LIBSBP_BOOTLOAD_PACKERS_H
#define LIBSBP_BOOTLOAD_PACKERS_H

#ifndef LIBSBP_BOOTLOAD_MESSAGES_H
#error "Do not include this file directly, include libsbp/unpacked/bootload.h instead"
#endif

#include <stdbool.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>
#include <endian.h>
#include <math.h>

#include <libsbp/common.h>
#include <libsbp/unpacked/base.h>
#include <libsbp/unpacked/common.h>
#include <libsbp/unpacked/string/unterminated.h>
#include <libsbp/unpacked/string/multipart.h>
#include <libsbp/unpacked/string/sequence.h>
#include <libsbp/unpacked/string/null_terminated.h>
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_bootloader_handshake_req_t(const sbp_msg_bootloader_handshake_req_t *msg) {
  (void)msg;
  return 0;
}

static inline bool sbp_pack_sbp_msg_bootloader_handshake_req_t(sbp_pack_ctx_t *ctx, const sbp_msg_bootloader_handshake_req_t *msg)
{
  (void)ctx;
  (void)msg;
  return true;
  return true;
}

static inline bool sbp_unpack_sbp_msg_bootloader_handshake_req_t(sbp_unpack_ctx_t *ctx, sbp_msg_bootloader_handshake_req_t *msg)
{
    (void)ctx;
  (void)msg;
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_bootloader_handshake_resp_t(const sbp_msg_bootloader_handshake_resp_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u32(&msg->flags);
  packed_size += sbp_unterminated_string_packed_len(&msg->version, 251
      );
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_bootloader_handshake_resp_t(sbp_pack_ctx_t *ctx, const sbp_msg_bootloader_handshake_resp_t *msg)
{
  if (!sbp_pack_u32(ctx, &msg->flags)) { return false; }
  if (!sbp_unterminated_string_pack(&msg->version, 251,
      ctx)) { return false; }
  return true;
}

static inline bool sbp_unpack_sbp_msg_bootloader_handshake_resp_t(sbp_unpack_ctx_t *ctx, sbp_msg_bootloader_handshake_resp_t *msg)
{
  if (!sbp_unpack_u32(ctx, &msg->flags)) { return false; }
  if (!sbp_unterminated_string_unpack(&msg->version, 251,
      ctx)) { return false; }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_bootloader_jump_to_app_t(const sbp_msg_bootloader_jump_to_app_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u8(&msg->jump);
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_bootloader_jump_to_app_t(sbp_pack_ctx_t *ctx, const sbp_msg_bootloader_jump_to_app_t *msg)
{
  if (!sbp_pack_u8(ctx, &msg->jump)) { return false; }
  return true;
}

static inline bool sbp_unpack_sbp_msg_bootloader_jump_to_app_t(sbp_unpack_ctx_t *ctx, sbp_msg_bootloader_jump_to_app_t *msg)
{
  if (!sbp_unpack_u8(ctx, &msg->jump)) { return false; }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_nap_device_dna_req_t(const sbp_msg_nap_device_dna_req_t *msg) {
  (void)msg;
  return 0;
}

static inline bool sbp_pack_sbp_msg_nap_device_dna_req_t(sbp_pack_ctx_t *ctx, const sbp_msg_nap_device_dna_req_t *msg)
{
  (void)ctx;
  (void)msg;
  return true;
  return true;
}

static inline bool sbp_unpack_sbp_msg_nap_device_dna_req_t(sbp_unpack_ctx_t *ctx, sbp_msg_nap_device_dna_req_t *msg)
{
    (void)ctx;
  (void)msg;
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_nap_device_dna_resp_t(const sbp_msg_nap_device_dna_resp_t *msg) {
  size_t packed_size = 0;
  packed_size += ( 8 * sbp_packed_size_u8(&msg->dna[0]));
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_nap_device_dna_resp_t(sbp_pack_ctx_t *ctx, const sbp_msg_nap_device_dna_resp_t *msg)
{
  for (uint8_t i = 0; i < 8; i++)
  {
    if (!sbp_pack_u8(ctx, &msg->dna[i])) { return false; }
  }
  return true;
}

static inline bool sbp_unpack_sbp_msg_nap_device_dna_resp_t(sbp_unpack_ctx_t *ctx, sbp_msg_nap_device_dna_resp_t *msg)
{
  for (uint8_t i = 0; i < 8; i++) {
    if (!sbp_unpack_u8(ctx, &msg->dna[i])) { return false; }
  }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_bootloader_handshake_dep_a_t(const sbp_msg_bootloader_handshake_dep_a_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_unterminated_string_packed_len(&msg->handshake, 255
      );
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_bootloader_handshake_dep_a_t(sbp_pack_ctx_t *ctx, const sbp_msg_bootloader_handshake_dep_a_t *msg)
{
  if (!sbp_unterminated_string_pack(&msg->handshake, 255,
      ctx)) { return false; }
  return true;
}

static inline bool sbp_unpack_sbp_msg_bootloader_handshake_dep_a_t(sbp_unpack_ctx_t *ctx, sbp_msg_bootloader_handshake_dep_a_t *msg)
{
  if (!sbp_unterminated_string_unpack(&msg->handshake, 255,
      ctx)) { return false; }
  return true;
}

#endif
