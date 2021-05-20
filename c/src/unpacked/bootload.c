#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <libsbp/sbp.h>
#include <libsbp/internal/unpacked/common.h>
#include <libsbp/unpacked/bootload.h>
#include <libsbp/internal/unpacked/bootload.h>
#include <libsbp/internal/unpacked/string/multipart.h>
#include <libsbp/internal/unpacked/string/null_terminated.h>
#include <libsbp/internal/unpacked/string/sequence.h>
#include <libsbp/internal/unpacked/string/unterminated.h>
#include <libsbp/internal/unpacked/string/binary.h>

size_t sbp_packed_size_sbp_msg_bootloader_handshake_req_t(const sbp_msg_bootloader_handshake_req_t *msg) {
  (void)msg;
  return 0;
}

bool pack_sbp_msg_bootloader_handshake_req_t(sbp_pack_ctx_t *ctx, const sbp_msg_bootloader_handshake_req_t *msg)
{
  (void)ctx;
  (void)msg;
  return true;
}

s8 sbp_pack_sbp_msg_bootloader_handshake_req_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_bootloader_handshake_req_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_msg_bootloader_handshake_req_t(&ctx, msg)) {
    return SBP_PACK_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
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
    return SBP_UNPACK_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

int sbp_cmp_sbp_msg_bootloader_handshake_req_t(const sbp_msg_bootloader_handshake_req_t *a, const sbp_msg_bootloader_handshake_req_t *b) {
  (void)a;
  (void)b;
  int ret = 0;
  return ret;
}
static const sbp_unterminated_string_params_t sbp_msg_bootloader_handshake_resp_tversion_params = 
{
  .max_packed_len = 251
};

  void sbp_msg_bootloader_handshake_resp_t_version_init(sbp_unterminated_string_t *s)
{
  sbp_unterminated_string_init(s, &sbp_msg_bootloader_handshake_resp_tversion_params);
}

  bool sbp_msg_bootloader_handshake_resp_t_version_valid(const sbp_unterminated_string_t *s)
{
  return sbp_unterminated_string_valid(s, &sbp_msg_bootloader_handshake_resp_tversion_params);
}

  int sbp_msg_bootloader_handshake_resp_t_version_strcmp(const sbp_unterminated_string_t *a, const sbp_unterminated_string_t *b)
{
  return sbp_unterminated_string_strcmp(a, b, &sbp_msg_bootloader_handshake_resp_tversion_params);
}

  uint8_t sbp_msg_bootloader_handshake_resp_t_version_packed_len(const sbp_unterminated_string_t *s)
{
  return sbp_unterminated_string_packed_len(s, &sbp_msg_bootloader_handshake_resp_tversion_params);
}

  uint8_t sbp_msg_bootloader_handshake_resp_t_version_space_remaining(const sbp_unterminated_string_t *s)
{
  return sbp_unterminated_string_space_remaining(s, &sbp_msg_bootloader_handshake_resp_tversion_params);
      }
  bool sbp_msg_bootloader_handshake_resp_t_version_set(sbp_unterminated_string_t *s, const char *new_str)
  {
  return sbp_unterminated_string_set(s, &sbp_msg_bootloader_handshake_resp_tversion_params, new_str);
  }

  bool sbp_msg_bootloader_handshake_resp_t_version_printf(sbp_unterminated_string_t *s, const char *fmt, ...) 
  {
  va_list ap;
  va_start(ap, fmt);
  bool ret = sbp_unterminated_string_vprintf(s, &sbp_msg_bootloader_handshake_resp_tversion_params, fmt, ap);
  va_end(ap);
  return ret;
  }

  bool sbp_msg_bootloader_handshake_resp_t_version_vprintf(sbp_unterminated_string_t *s, const char *fmt, va_list ap)
  {
  return sbp_unterminated_string_vprintf(s, &sbp_msg_bootloader_handshake_resp_tversion_params, fmt, ap);
  }

  bool sbp_msg_bootloader_handshake_resp_t_version_append_printf(sbp_unterminated_string_t *s, const char *fmt, ...) 
{
  va_list ap;
  va_start(ap, fmt);
  bool ret = sbp_unterminated_string_append_vprintf(s, &sbp_msg_bootloader_handshake_resp_tversion_params, fmt, ap);
  va_end(ap);
  return ret;
}

  bool sbp_msg_bootloader_handshake_resp_t_version_append_vprintf(sbp_unterminated_string_t *s, const char *fmt, va_list ap)
{
  return sbp_unterminated_string_append_vprintf(s, &sbp_msg_bootloader_handshake_resp_tversion_params, fmt, ap);
}

  const char *sbp_msg_bootloader_handshake_resp_t_version_get(const sbp_unterminated_string_t *s)
{
  return sbp_unterminated_string_get(s, &sbp_msg_bootloader_handshake_resp_tversion_params);
}

size_t sbp_packed_size_sbp_msg_bootloader_handshake_resp_t(const sbp_msg_bootloader_handshake_resp_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u32(&msg->flags);
  packed_size += sbp_unterminated_string_packed_len(&msg->version, &sbp_msg_bootloader_handshake_resp_tversion_params);
  return packed_size;
}

bool pack_sbp_msg_bootloader_handshake_resp_t(sbp_pack_ctx_t *ctx, const sbp_msg_bootloader_handshake_resp_t *msg)
{
  if (!pack_u32(ctx, &msg->flags)) { return false; }
  if (!sbp_unterminated_string_pack(&msg->version, &sbp_msg_bootloader_handshake_resp_tversion_params, ctx)) { return false; }
  return true;
}

s8 sbp_pack_sbp_msg_bootloader_handshake_resp_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_bootloader_handshake_resp_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_msg_bootloader_handshake_resp_t(&ctx, msg)) {
    return SBP_PACK_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_msg_bootloader_handshake_resp_t(sbp_unpack_ctx_t *ctx, sbp_msg_bootloader_handshake_resp_t *msg)
{
  if (!unpack_u32(ctx, &msg->flags)) { return false; }
  if (!sbp_unterminated_string_unpack(&msg->version, &sbp_msg_bootloader_handshake_resp_tversion_params, ctx)) { return false; }
  return true;
}

s8 sbp_unpack_sbp_msg_bootloader_handshake_resp_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_bootloader_handshake_resp_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_msg_bootloader_handshake_resp_t(&ctx, msg)) {
    return SBP_UNPACK_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

int sbp_cmp_sbp_msg_bootloader_handshake_resp_t(const sbp_msg_bootloader_handshake_resp_t *a, const sbp_msg_bootloader_handshake_resp_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u32(&a->flags, &b->flags);
  if (ret != 0) { return ret; }
  
  ret = sbp_unterminated_string_strcmp(&a->version, &b->version, &sbp_msg_bootloader_handshake_resp_tversion_params);
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
  if (!pack_u8(ctx, &msg->jump)) { return false; }
  return true;
}

s8 sbp_pack_sbp_msg_bootloader_jump_to_app_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_bootloader_jump_to_app_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_msg_bootloader_jump_to_app_t(&ctx, msg)) {
    return SBP_PACK_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_msg_bootloader_jump_to_app_t(sbp_unpack_ctx_t *ctx, sbp_msg_bootloader_jump_to_app_t *msg)
{
  if (!unpack_u8(ctx, &msg->jump)) { return false; }
  return true;
}

s8 sbp_unpack_sbp_msg_bootloader_jump_to_app_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_bootloader_jump_to_app_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_msg_bootloader_jump_to_app_t(&ctx, msg)) {
    return SBP_UNPACK_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
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
}

s8 sbp_pack_sbp_msg_nap_device_dna_req_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_nap_device_dna_req_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_msg_nap_device_dna_req_t(&ctx, msg)) {
    return SBP_PACK_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
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
    return SBP_UNPACK_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
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
    if (!pack_u8(ctx, &msg->dna[i])) { return false; }
  }
  return true;
}

s8 sbp_pack_sbp_msg_nap_device_dna_resp_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_nap_device_dna_resp_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_msg_nap_device_dna_resp_t(&ctx, msg)) {
    return SBP_PACK_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_msg_nap_device_dna_resp_t(sbp_unpack_ctx_t *ctx, sbp_msg_nap_device_dna_resp_t *msg)
{
  for (uint8_t i = 0; i < 8; i++) {
    if (!unpack_u8(ctx, &msg->dna[i])) { return false; }
  }
  return true;
}

s8 sbp_unpack_sbp_msg_nap_device_dna_resp_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_nap_device_dna_resp_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_msg_nap_device_dna_resp_t(&ctx, msg)) {
    return SBP_UNPACK_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
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
static const sbp_unterminated_string_params_t sbp_msg_bootloader_handshake_dep_a_thandshake_params = 
{
  .max_packed_len = 255
};

  void sbp_msg_bootloader_handshake_dep_a_t_handshake_init(sbp_unterminated_string_t *s)
{
  sbp_unterminated_string_init(s, &sbp_msg_bootloader_handshake_dep_a_thandshake_params);
}

  bool sbp_msg_bootloader_handshake_dep_a_t_handshake_valid(const sbp_unterminated_string_t *s)
{
  return sbp_unterminated_string_valid(s, &sbp_msg_bootloader_handshake_dep_a_thandshake_params);
}

  int sbp_msg_bootloader_handshake_dep_a_t_handshake_strcmp(const sbp_unterminated_string_t *a, const sbp_unterminated_string_t *b)
{
  return sbp_unterminated_string_strcmp(a, b, &sbp_msg_bootloader_handshake_dep_a_thandshake_params);
}

  uint8_t sbp_msg_bootloader_handshake_dep_a_t_handshake_packed_len(const sbp_unterminated_string_t *s)
{
  return sbp_unterminated_string_packed_len(s, &sbp_msg_bootloader_handshake_dep_a_thandshake_params);
}

  uint8_t sbp_msg_bootloader_handshake_dep_a_t_handshake_space_remaining(const sbp_unterminated_string_t *s)
{
  return sbp_unterminated_string_space_remaining(s, &sbp_msg_bootloader_handshake_dep_a_thandshake_params);
      }
  bool sbp_msg_bootloader_handshake_dep_a_t_handshake_set(sbp_unterminated_string_t *s, const char *new_str)
  {
  return sbp_unterminated_string_set(s, &sbp_msg_bootloader_handshake_dep_a_thandshake_params, new_str);
  }

  bool sbp_msg_bootloader_handshake_dep_a_t_handshake_printf(sbp_unterminated_string_t *s, const char *fmt, ...) 
  {
  va_list ap;
  va_start(ap, fmt);
  bool ret = sbp_unterminated_string_vprintf(s, &sbp_msg_bootloader_handshake_dep_a_thandshake_params, fmt, ap);
  va_end(ap);
  return ret;
  }

  bool sbp_msg_bootloader_handshake_dep_a_t_handshake_vprintf(sbp_unterminated_string_t *s, const char *fmt, va_list ap)
  {
  return sbp_unterminated_string_vprintf(s, &sbp_msg_bootloader_handshake_dep_a_thandshake_params, fmt, ap);
  }

  bool sbp_msg_bootloader_handshake_dep_a_t_handshake_append_printf(sbp_unterminated_string_t *s, const char *fmt, ...) 
{
  va_list ap;
  va_start(ap, fmt);
  bool ret = sbp_unterminated_string_append_vprintf(s, &sbp_msg_bootloader_handshake_dep_a_thandshake_params, fmt, ap);
  va_end(ap);
  return ret;
}

  bool sbp_msg_bootloader_handshake_dep_a_t_handshake_append_vprintf(sbp_unterminated_string_t *s, const char *fmt, va_list ap)
{
  return sbp_unterminated_string_append_vprintf(s, &sbp_msg_bootloader_handshake_dep_a_thandshake_params, fmt, ap);
}

  const char *sbp_msg_bootloader_handshake_dep_a_t_handshake_get(const sbp_unterminated_string_t *s)
{
  return sbp_unterminated_string_get(s, &sbp_msg_bootloader_handshake_dep_a_thandshake_params);
}

size_t sbp_packed_size_sbp_msg_bootloader_handshake_dep_a_t(const sbp_msg_bootloader_handshake_dep_a_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_unterminated_string_packed_len(&msg->handshake, &sbp_msg_bootloader_handshake_dep_a_thandshake_params);
  return packed_size;
}

bool pack_sbp_msg_bootloader_handshake_dep_a_t(sbp_pack_ctx_t *ctx, const sbp_msg_bootloader_handshake_dep_a_t *msg)
{
  if (!sbp_unterminated_string_pack(&msg->handshake, &sbp_msg_bootloader_handshake_dep_a_thandshake_params, ctx)) { return false; }
  return true;
}

s8 sbp_pack_sbp_msg_bootloader_handshake_dep_a_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_bootloader_handshake_dep_a_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_msg_bootloader_handshake_dep_a_t(&ctx, msg)) {
    return SBP_PACK_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_msg_bootloader_handshake_dep_a_t(sbp_unpack_ctx_t *ctx, sbp_msg_bootloader_handshake_dep_a_t *msg)
{
  if (!sbp_unterminated_string_unpack(&msg->handshake, &sbp_msg_bootloader_handshake_dep_a_thandshake_params, ctx)) { return false; }
  return true;
}

s8 sbp_unpack_sbp_msg_bootloader_handshake_dep_a_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_bootloader_handshake_dep_a_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_msg_bootloader_handshake_dep_a_t(&ctx, msg)) {
    return SBP_UNPACK_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

int sbp_cmp_sbp_msg_bootloader_handshake_dep_a_t(const sbp_msg_bootloader_handshake_dep_a_t *a, const sbp_msg_bootloader_handshake_dep_a_t *b) {
  int ret = 0;
  
  ret = sbp_unterminated_string_strcmp(&a->handshake, &b->handshake, &sbp_msg_bootloader_handshake_dep_a_thandshake_params);
  if (ret != 0) { return ret; }
  return ret;
}
