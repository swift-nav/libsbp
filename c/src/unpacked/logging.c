#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <libsbp/sbp.h>
#include <libsbp/internal/unpacked/common.h>
#include <libsbp/unpacked/logging.h>
#include <libsbp/internal/unpacked/logging.h>
#include <libsbp/internal/unpacked/string/multipart.h>
#include <libsbp/internal/unpacked/string/null_terminated.h>
#include <libsbp/internal/unpacked/string/double_null_terminated.h>
#include <libsbp/internal/unpacked/string/unterminated.h>
#include <libsbp/internal/unpacked/string/binary.h>
static const sbp_unterminated_string_params_t sbp_msg_log_ttext_params = 
{
  .max_packed_len = 254
};

  void sbp_msg_log_t_text_init(sbp_unterminated_string_t *s)
{
  sbp_unterminated_string_init(s, &sbp_msg_log_ttext_params);
}

  bool sbp_msg_log_t_text_valid(const sbp_unterminated_string_t *s)
{
  return sbp_unterminated_string_valid(s, &sbp_msg_log_ttext_params);
}

  int sbp_msg_log_t_text_strcmp(const sbp_unterminated_string_t *a, const sbp_unterminated_string_t *b)
{
  return sbp_unterminated_string_strcmp(a, b, &sbp_msg_log_ttext_params);
}

  uint8_t sbp_msg_log_t_text_packed_len(const sbp_unterminated_string_t *s)
{
  return sbp_unterminated_string_packed_len(s, &sbp_msg_log_ttext_params);
}

  uint8_t sbp_msg_log_t_text_space_remaining(const sbp_unterminated_string_t *s)
{
  return sbp_unterminated_string_space_remaining(s, &sbp_msg_log_ttext_params);
      }
  bool sbp_msg_log_t_text_set(sbp_unterminated_string_t *s, const char *new_str)
  {
  return sbp_unterminated_string_set(s, &sbp_msg_log_ttext_params, new_str);
  }

  bool sbp_msg_log_t_text_printf(sbp_unterminated_string_t *s, const char *fmt, ...) 
  {
  va_list ap;
  va_start(ap, fmt);
  bool ret = sbp_unterminated_string_vprintf(s, &sbp_msg_log_ttext_params, fmt, ap);
  va_end(ap);
  return ret;
  }

  bool sbp_msg_log_t_text_vprintf(sbp_unterminated_string_t *s, const char *fmt, va_list ap)
  {
  return sbp_unterminated_string_vprintf(s, &sbp_msg_log_ttext_params, fmt, ap);
  }

  bool sbp_msg_log_t_text_append_printf(sbp_unterminated_string_t *s, const char *fmt, ...) 
{
  va_list ap;
  va_start(ap, fmt);
  bool ret = sbp_unterminated_string_append_vprintf(s, &sbp_msg_log_ttext_params, fmt, ap);
  va_end(ap);
  return ret;
}

  bool sbp_msg_log_t_text_append_vprintf(sbp_unterminated_string_t *s, const char *fmt, va_list ap)
{
  return sbp_unterminated_string_append_vprintf(s, &sbp_msg_log_ttext_params, fmt, ap);
}

  const char *sbp_msg_log_t_text_get(const sbp_unterminated_string_t *s)
{
  return sbp_unterminated_string_get(s, &sbp_msg_log_ttext_params);
}

size_t sbp_packed_size_sbp_msg_log_t(const sbp_msg_log_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u8(&msg->level);
  packed_size += sbp_unterminated_string_packed_len(&msg->text, &sbp_msg_log_ttext_params);
  return packed_size;
}

bool pack_sbp_msg_log_t(sbp_pack_ctx_t *ctx, const sbp_msg_log_t *msg)
{
  if (!pack_u8(ctx, &msg->level)) { return false; }
  if (!sbp_unterminated_string_pack(&msg->text, &sbp_msg_log_ttext_params, ctx)) { return false; }
  return true;
}

s8 sbp_pack_sbp_msg_log_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_log_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_msg_log_t(&ctx, msg)) {
    return SBP_PACK_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_msg_log_t(sbp_unpack_ctx_t *ctx, sbp_msg_log_t *msg)
{
  if (!unpack_u8(ctx, &msg->level)) { return false; }
  if (!sbp_unterminated_string_unpack(&msg->text, &sbp_msg_log_ttext_params, ctx)) { return false; }
  return true;
}

s8 sbp_unpack_sbp_msg_log_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_log_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_msg_log_t(&ctx, msg)) {
    return SBP_UNPACK_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

int sbp_cmp_sbp_msg_log_t(const sbp_msg_log_t *a, const sbp_msg_log_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u8(&a->level, &b->level);
  if (ret != 0) { return ret; }
  
  ret = sbp_unterminated_string_strcmp(&a->text, &b->text, &sbp_msg_log_ttext_params);
  if (ret != 0) { return ret; }
  return ret;
}
static const sbp_binary_string_params_t sbp_msg_fwd_tfwd_payload_params = 
{
  .max_packed_len = 253
};

  void sbp_msg_fwd_t_fwd_payload_init(sbp_binary_string_t *s)
{
  sbp_binary_string_init(s, &sbp_msg_fwd_tfwd_payload_params);
}

  bool sbp_msg_fwd_t_fwd_payload_valid(const sbp_binary_string_t *s)
{
  return sbp_binary_string_valid(s, &sbp_msg_fwd_tfwd_payload_params);
}

  int sbp_msg_fwd_t_fwd_payload_strcmp(const sbp_binary_string_t *a, const sbp_binary_string_t *b)
{
  return sbp_binary_string_strcmp(a, b, &sbp_msg_fwd_tfwd_payload_params);
}

  uint8_t sbp_msg_fwd_t_fwd_payload_packed_len(const sbp_binary_string_t *s)
{
  return sbp_binary_string_packed_len(s, &sbp_msg_fwd_tfwd_payload_params);
}

  uint8_t sbp_msg_fwd_t_fwd_payload_space_remaining(const sbp_binary_string_t *s)
{
  return sbp_binary_string_space_remaining(s, &sbp_msg_fwd_tfwd_payload_params);
      }
  bool sbp_msg_fwd_t_fwd_payload_set(sbp_binary_string_t *s, const char *new_str, uint8_t new_str_len)
{
  return sbp_binary_string_set(s, &sbp_msg_fwd_tfwd_payload_params, new_str, new_str_len);
}

  bool sbp_msg_fwd_t_fwd_payload_get(const sbp_binary_string_t *s, uint8_t *str_len)
{
  return sbp_binary_string_get(s, &sbp_msg_fwd_tfwd_payload_params, str_len);
}

size_t sbp_packed_size_sbp_msg_fwd_t(const sbp_msg_fwd_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u8(&msg->source);
  packed_size += sbp_packed_size_u8(&msg->protocol);
  packed_size += sbp_binary_string_packed_len(&msg->fwd_payload, &sbp_msg_fwd_tfwd_payload_params);
  return packed_size;
}

bool pack_sbp_msg_fwd_t(sbp_pack_ctx_t *ctx, const sbp_msg_fwd_t *msg)
{
  if (!pack_u8(ctx, &msg->source)) { return false; }
  if (!pack_u8(ctx, &msg->protocol)) { return false; }
  if (!sbp_binary_string_pack(&msg->fwd_payload, &sbp_msg_fwd_tfwd_payload_params, ctx)) { return false; }
  return true;
}

s8 sbp_pack_sbp_msg_fwd_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_fwd_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_msg_fwd_t(&ctx, msg)) {
    return SBP_PACK_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_msg_fwd_t(sbp_unpack_ctx_t *ctx, sbp_msg_fwd_t *msg)
{
  if (!unpack_u8(ctx, &msg->source)) { return false; }
  if (!unpack_u8(ctx, &msg->protocol)) { return false; }
  if (!sbp_binary_string_unpack(&msg->fwd_payload, &sbp_msg_fwd_tfwd_payload_params, ctx)) { return false; }
  return true;
}

s8 sbp_unpack_sbp_msg_fwd_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_fwd_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_msg_fwd_t(&ctx, msg)) {
    return SBP_UNPACK_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

int sbp_cmp_sbp_msg_fwd_t(const sbp_msg_fwd_t *a, const sbp_msg_fwd_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u8(&a->source, &b->source);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->protocol, &b->protocol);
  if (ret != 0) { return ret; }
  
  ret = sbp_binary_string_strcmp(&a->fwd_payload, &b->fwd_payload, &sbp_msg_fwd_tfwd_payload_params);
  if (ret != 0) { return ret; }
  return ret;
}
static const sbp_unterminated_string_params_t sbp_msg_print_dep_ttext_params = 
{
  .max_packed_len = 255
};

  void sbp_msg_print_dep_t_text_init(sbp_unterminated_string_t *s)
{
  sbp_unterminated_string_init(s, &sbp_msg_print_dep_ttext_params);
}

  bool sbp_msg_print_dep_t_text_valid(const sbp_unterminated_string_t *s)
{
  return sbp_unterminated_string_valid(s, &sbp_msg_print_dep_ttext_params);
}

  int sbp_msg_print_dep_t_text_strcmp(const sbp_unterminated_string_t *a, const sbp_unterminated_string_t *b)
{
  return sbp_unterminated_string_strcmp(a, b, &sbp_msg_print_dep_ttext_params);
}

  uint8_t sbp_msg_print_dep_t_text_packed_len(const sbp_unterminated_string_t *s)
{
  return sbp_unterminated_string_packed_len(s, &sbp_msg_print_dep_ttext_params);
}

  uint8_t sbp_msg_print_dep_t_text_space_remaining(const sbp_unterminated_string_t *s)
{
  return sbp_unterminated_string_space_remaining(s, &sbp_msg_print_dep_ttext_params);
      }
  bool sbp_msg_print_dep_t_text_set(sbp_unterminated_string_t *s, const char *new_str)
  {
  return sbp_unterminated_string_set(s, &sbp_msg_print_dep_ttext_params, new_str);
  }

  bool sbp_msg_print_dep_t_text_printf(sbp_unterminated_string_t *s, const char *fmt, ...) 
  {
  va_list ap;
  va_start(ap, fmt);
  bool ret = sbp_unterminated_string_vprintf(s, &sbp_msg_print_dep_ttext_params, fmt, ap);
  va_end(ap);
  return ret;
  }

  bool sbp_msg_print_dep_t_text_vprintf(sbp_unterminated_string_t *s, const char *fmt, va_list ap)
  {
  return sbp_unterminated_string_vprintf(s, &sbp_msg_print_dep_ttext_params, fmt, ap);
  }

  bool sbp_msg_print_dep_t_text_append_printf(sbp_unterminated_string_t *s, const char *fmt, ...) 
{
  va_list ap;
  va_start(ap, fmt);
  bool ret = sbp_unterminated_string_append_vprintf(s, &sbp_msg_print_dep_ttext_params, fmt, ap);
  va_end(ap);
  return ret;
}

  bool sbp_msg_print_dep_t_text_append_vprintf(sbp_unterminated_string_t *s, const char *fmt, va_list ap)
{
  return sbp_unterminated_string_append_vprintf(s, &sbp_msg_print_dep_ttext_params, fmt, ap);
}

  const char *sbp_msg_print_dep_t_text_get(const sbp_unterminated_string_t *s)
{
  return sbp_unterminated_string_get(s, &sbp_msg_print_dep_ttext_params);
}

size_t sbp_packed_size_sbp_msg_print_dep_t(const sbp_msg_print_dep_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_unterminated_string_packed_len(&msg->text, &sbp_msg_print_dep_ttext_params);
  return packed_size;
}

bool pack_sbp_msg_print_dep_t(sbp_pack_ctx_t *ctx, const sbp_msg_print_dep_t *msg)
{
  if (!sbp_unterminated_string_pack(&msg->text, &sbp_msg_print_dep_ttext_params, ctx)) { return false; }
  return true;
}

s8 sbp_pack_sbp_msg_print_dep_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_print_dep_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_msg_print_dep_t(&ctx, msg)) {
    return SBP_PACK_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_msg_print_dep_t(sbp_unpack_ctx_t *ctx, sbp_msg_print_dep_t *msg)
{
  if (!sbp_unterminated_string_unpack(&msg->text, &sbp_msg_print_dep_ttext_params, ctx)) { return false; }
  return true;
}

s8 sbp_unpack_sbp_msg_print_dep_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_print_dep_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_msg_print_dep_t(&ctx, msg)) {
    return SBP_UNPACK_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

int sbp_cmp_sbp_msg_print_dep_t(const sbp_msg_print_dep_t *a, const sbp_msg_print_dep_t *b) {
  int ret = 0;
  
  ret = sbp_unterminated_string_strcmp(&a->text, &b->text, &sbp_msg_print_dep_ttext_params);
  if (ret != 0) { return ret; }
  return ret;
}
