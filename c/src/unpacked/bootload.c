#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <libsbp/internal/unpacked/common.h>
#include <libsbp/unpacked/bootload.h>
#include <libsbp/internal/unpacked/bootload.h>
#include <libsbp/internal/unpacked/string/multipart.h>
#include <libsbp/internal/unpacked/string/null_terminated.h>
#include <libsbp/internal/unpacked/string/sequence.h>
#include <libsbp/internal/unpacked/string/unterminated.h>
                                                                                                              
size_t sbp_packed_size_sbp_msg_bootloader_handshake_req_t(const sbp_msg_bootloader_handshake_req_t *msg) {
  (void)msg;
  return 0;
}

bool pack_sbp_msg_bootloader_handshake_req_t(sbp_pack_ctx_t *ctx, const sbp_msg_bootloader_handshake_req_t *msg)
{
  (void)ctx;
  (void)msg;
  return true;
  return true;
}

s8 sbp_pack_sbp_msg_bootloader_handshake_req_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_bootloader_handshake_req_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_msg_bootloader_handshake_req_t(&ctx, msg)) {
    return SBP_WRITE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_msg_bootloader_handshake_req_t(sbp_unpack_ctx_t *ctx, sbp_msg_bootloader_handshake_req_t *msg)
{
    (void)ctx;
  (void)msg;
  return true;
}

s8 sbp_unpack_sbp_msg_bootloader_handshake_req_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_bootloader_handshake_req_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_msg_bootloader_handshake_req_t(&ctx, msg)) {
    return SBP_READ_ERROR;
  }
  if (n_read != NULL) {
    *n_read = ctx.offset;
  }
  return SBP_OK;
}

int sbp_cmp_sbp_msg_bootloader_handshake_req_t(const sbp_msg_bootloader_handshake_req_t *a, const sbp_msg_bootloader_handshake_req_t *b) {
  (void)a;
  (void)b;
  int ret = 0;
  return ret;
}
                                                                                                              
size_t sbp_packed_size_sbp_msg_bootloader_handshake_resp_t(const sbp_msg_bootloader_handshake_resp_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u32(&msg->flags);
  packed_size += sbp_unterminated_string_packed_len(&msg->version, 251
      );
  return packed_size;
}

bool pack_sbp_msg_bootloader_handshake_resp_t(sbp_pack_ctx_t *ctx, const sbp_msg_bootloader_handshake_resp_t *msg)
{
  if (!sbp_pack_u32(ctx, &msg->flags)) { return false; }
  if (!sbp_unterminated_string_pack(&msg->version, 251,
      ctx)) { return false; }
  return true;
}

s8 sbp_pack_sbp_msg_bootloader_handshake_resp_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_bootloader_handshake_resp_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_msg_bootloader_handshake_resp_t(&ctx, msg)) {
    return SBP_WRITE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_msg_bootloader_handshake_resp_t(sbp_unpack_ctx_t *ctx, sbp_msg_bootloader_handshake_resp_t *msg)
{
  if (!sbp_unpack_u32(ctx, &msg->flags)) { return false; }
  if (!sbp_unterminated_string_unpack(&msg->version, 251,
      ctx)) { return false; }
  return true;
}

s8 sbp_unpack_sbp_msg_bootloader_handshake_resp_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_bootloader_handshake_resp_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_msg_bootloader_handshake_resp_t(&ctx, msg)) {
    return SBP_READ_ERROR;
  }
  if (n_read != NULL) {
    *n_read = ctx.offset;
  }
  return SBP_OK;
}

int sbp_cmp_sbp_msg_bootloader_handshake_resp_t(const sbp_msg_bootloader_handshake_resp_t *a, const sbp_msg_bootloader_handshake_resp_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u32(&a->flags, &b->flags);
  if (ret != 0) { return ret; }
  
  ret = sbp_unterminated_string_strcmp(&a->version, &b->version, 251
    );
  if (ret != 0) { return ret; }
  return ret;
}
                                                                                                              
size_t sbp_packed_size_sbp_msg_bootloader_jump_to_app_t(const sbp_msg_bootloader_jump_to_app_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u8(&msg->jump);
  return packed_size;
}

bool pack_sbp_msg_bootloader_jump_to_app_t(sbp_pack_ctx_t *ctx, const sbp_msg_bootloader_jump_to_app_t *msg)
{
  if (!sbp_pack_u8(ctx, &msg->jump)) { return false; }
  return true;
}

s8 sbp_pack_sbp_msg_bootloader_jump_to_app_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_bootloader_jump_to_app_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_msg_bootloader_jump_to_app_t(&ctx, msg)) {
    return SBP_WRITE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_msg_bootloader_jump_to_app_t(sbp_unpack_ctx_t *ctx, sbp_msg_bootloader_jump_to_app_t *msg)
{
  if (!sbp_unpack_u8(ctx, &msg->jump)) { return false; }
  return true;
}

s8 sbp_unpack_sbp_msg_bootloader_jump_to_app_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_bootloader_jump_to_app_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_msg_bootloader_jump_to_app_t(&ctx, msg)) {
    return SBP_READ_ERROR;
  }
  if (n_read != NULL) {
    *n_read = ctx.offset;
  }
  return SBP_OK;
}

int sbp_cmp_sbp_msg_bootloader_jump_to_app_t(const sbp_msg_bootloader_jump_to_app_t *a, const sbp_msg_bootloader_jump_to_app_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u8(&a->jump, &b->jump);
  if (ret != 0) { return ret; }
  return ret;
}
                                                                                                              
size_t sbp_packed_size_sbp_msg_nap_device_dna_req_t(const sbp_msg_nap_device_dna_req_t *msg) {
  (void)msg;
  return 0;
}

bool pack_sbp_msg_nap_device_dna_req_t(sbp_pack_ctx_t *ctx, const sbp_msg_nap_device_dna_req_t *msg)
{
  (void)ctx;
  (void)msg;
  return true;
  return true;
}

s8 sbp_pack_sbp_msg_nap_device_dna_req_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_nap_device_dna_req_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_msg_nap_device_dna_req_t(&ctx, msg)) {
    return SBP_WRITE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_msg_nap_device_dna_req_t(sbp_unpack_ctx_t *ctx, sbp_msg_nap_device_dna_req_t *msg)
{
    (void)ctx;
  (void)msg;
  return true;
}

s8 sbp_unpack_sbp_msg_nap_device_dna_req_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_nap_device_dna_req_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_msg_nap_device_dna_req_t(&ctx, msg)) {
    return SBP_READ_ERROR;
  }
  if (n_read != NULL) {
    *n_read = ctx.offset;
  }
  return SBP_OK;
}

int sbp_cmp_sbp_msg_nap_device_dna_req_t(const sbp_msg_nap_device_dna_req_t *a, const sbp_msg_nap_device_dna_req_t *b) {
  (void)a;
  (void)b;
  int ret = 0;
  return ret;
}
                                                                                                              
size_t sbp_packed_size_sbp_msg_nap_device_dna_resp_t(const sbp_msg_nap_device_dna_resp_t *msg) {
  size_t packed_size = 0;
  packed_size += ( 8 * sbp_packed_size_u8(&msg->dna[0]));
  return packed_size;
}

bool pack_sbp_msg_nap_device_dna_resp_t(sbp_pack_ctx_t *ctx, const sbp_msg_nap_device_dna_resp_t *msg)
{
  for (uint8_t i = 0; i < 8; i++)
  {
    if (!sbp_pack_u8(ctx, &msg->dna[i])) { return false; }
  }
  return true;
}

s8 sbp_pack_sbp_msg_nap_device_dna_resp_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_nap_device_dna_resp_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_msg_nap_device_dna_resp_t(&ctx, msg)) {
    return SBP_WRITE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_msg_nap_device_dna_resp_t(sbp_unpack_ctx_t *ctx, sbp_msg_nap_device_dna_resp_t *msg)
{
  for (uint8_t i = 0; i < 8; i++) {
    if (!sbp_unpack_u8(ctx, &msg->dna[i])) { return false; }
  }
  return true;
}

s8 sbp_unpack_sbp_msg_nap_device_dna_resp_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_nap_device_dna_resp_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_msg_nap_device_dna_resp_t(&ctx, msg)) {
    return SBP_READ_ERROR;
  }
  if (n_read != NULL) {
    *n_read = ctx.offset;
  }
  return SBP_OK;
}

int sbp_cmp_sbp_msg_nap_device_dna_resp_t(const sbp_msg_nap_device_dna_resp_t *a, const sbp_msg_nap_device_dna_resp_t *b) {
  int ret = 0;
  
  for (uint8_t i = 0; i < 8 && ret == 0; i++)
  {
    ret = sbp_cmp_u8(&a->dna[i], &b->dna[i]);
  }
  if (ret != 0) { return ret; }
  return ret;
}
                                                                                                              
size_t sbp_packed_size_sbp_msg_bootloader_handshake_dep_a_t(const sbp_msg_bootloader_handshake_dep_a_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_unterminated_string_packed_len(&msg->handshake, 255
      );
  return packed_size;
}

bool pack_sbp_msg_bootloader_handshake_dep_a_t(sbp_pack_ctx_t *ctx, const sbp_msg_bootloader_handshake_dep_a_t *msg)
{
  if (!sbp_unterminated_string_pack(&msg->handshake, 255,
      ctx)) { return false; }
  return true;
}

s8 sbp_pack_sbp_msg_bootloader_handshake_dep_a_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_bootloader_handshake_dep_a_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_msg_bootloader_handshake_dep_a_t(&ctx, msg)) {
    return SBP_WRITE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_msg_bootloader_handshake_dep_a_t(sbp_unpack_ctx_t *ctx, sbp_msg_bootloader_handshake_dep_a_t *msg)
{
  if (!sbp_unterminated_string_unpack(&msg->handshake, 255,
      ctx)) { return false; }
  return true;
}

s8 sbp_unpack_sbp_msg_bootloader_handshake_dep_a_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_bootloader_handshake_dep_a_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_msg_bootloader_handshake_dep_a_t(&ctx, msg)) {
    return SBP_READ_ERROR;
  }
  if (n_read != NULL) {
    *n_read = ctx.offset;
  }
  return SBP_OK;
}

int sbp_cmp_sbp_msg_bootloader_handshake_dep_a_t(const sbp_msg_bootloader_handshake_dep_a_t *a, const sbp_msg_bootloader_handshake_dep_a_t *b) {
  int ret = 0;
  
  ret = sbp_unterminated_string_strcmp(&a->handshake, &b->handshake, 255
    );
  if (ret != 0) { return ret; }
  return ret;
}
