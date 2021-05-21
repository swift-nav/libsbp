#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <libsbp/sbp.h>
#include <libsbp/internal/unpacked/common.h>
#include <libsbp/unpacked/settings.h>
#include <libsbp/internal/unpacked/settings.h>
#include <libsbp/internal/unpacked/string/multipart.h>
#include <libsbp/internal/unpacked/string/null_terminated.h>
#include <libsbp/internal/unpacked/string/double_null_terminated.h>
#include <libsbp/internal/unpacked/string/unterminated.h>
#include <libsbp/internal/unpacked/string/binary.h>

size_t sbp_packed_size_sbp_msg_settings_save_t(const sbp_msg_settings_save_t *msg) {
  (void)msg;
  return 0;
}

bool pack_sbp_msg_settings_save_t(sbp_pack_ctx_t *ctx, const sbp_msg_settings_save_t *msg)
{
  (void)ctx;
  (void)msg;
  return true;
}

s8 sbp_pack_sbp_msg_settings_save_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_settings_save_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_msg_settings_save_t(&ctx, msg)) {
    return SBP_PACK_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_msg_settings_save_t(sbp_unpack_ctx_t *ctx, sbp_msg_settings_save_t *msg)
{
    (void)ctx;
  (void)msg;
  return true;
}

s8 sbp_unpack_sbp_msg_settings_save_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_settings_save_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_msg_settings_save_t(&ctx, msg)) {
    return SBP_UNPACK_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

int sbp_cmp_sbp_msg_settings_save_t(const sbp_msg_settings_save_t *a, const sbp_msg_settings_save_t *b) {
  (void)a;
  (void)b;
  int ret = 0;
  return ret;
}
static const sbp_multipart_string_params_t sbp_msg_settings_write_tsetting_params = 
{
  .max_packed_len = 255
};

  void sbp_msg_settings_write_t_setting_init(sbp_multipart_string_t *s)
{
  sbp_multipart_string_init(s, &sbp_msg_settings_write_tsetting_params);
}

  bool sbp_msg_settings_write_t_setting_valid(const sbp_multipart_string_t *s)
{
  return sbp_multipart_string_valid(s, &sbp_msg_settings_write_tsetting_params);
}

  int sbp_msg_settings_write_t_setting_strcmp(const sbp_multipart_string_t *a, const sbp_multipart_string_t *b)
{
  return sbp_multipart_string_strcmp(a, b, &sbp_msg_settings_write_tsetting_params);
}

  uint8_t sbp_msg_settings_write_t_setting_packed_len(const sbp_multipart_string_t *s)
{
  return sbp_multipart_string_packed_len(s, &sbp_msg_settings_write_tsetting_params);
}

  uint8_t sbp_msg_settings_write_t_setting_space_remaining(const sbp_multipart_string_t *s)
{
  return sbp_multipart_string_space_remaining(s, &sbp_msg_settings_write_tsetting_params);
      }
  uint8_t sbp_msg_settings_write_t_setting_count_sections(const sbp_multipart_string_t *s)
{
  return sbp_multipart_string_count_sections(s, &sbp_msg_settings_write_tsetting_params);
}

  bool sbp_msg_settings_write_t_setting_add_section(sbp_multipart_string_t *s, const char *new_str)
{
  return sbp_multipart_string_add_section(s, &sbp_msg_settings_write_tsetting_params, new_str);
}

  bool sbp_msg_settings_write_t_setting_add_section_printf(sbp_multipart_string_t *s, const char *fmt, ...) 
{
  va_list ap;
  va_start(ap, fmt);
  bool ret = sbp_multipart_string_add_section_vprintf(s, &sbp_msg_settings_write_tsetting_params, fmt, ap);
  va_end(ap);
  return ret;
}

  bool sbp_msg_settings_write_t_setting_add_section_vprintf(sbp_multipart_string_t *s, const char *fmt, va_list ap)
{
  return sbp_multipart_string_add_section_vprintf(s, &sbp_msg_settings_write_tsetting_params, fmt, ap);
}

  bool sbp_msg_settings_write_t_setting_append(sbp_multipart_string_t *s, const char *str)
{
  return sbp_multipart_string_append(s, &sbp_msg_settings_write_tsetting_params, str);
}

  bool sbp_msg_settings_write_t_setting_append_printf(sbp_multipart_string_t *s, const char *fmt, ...) 
{
  va_list ap;
  va_start(ap, fmt);
  bool ret = sbp_multipart_string_append_vprintf(s, &sbp_msg_settings_write_tsetting_params, fmt, ap);
  va_end(ap);
  return ret;
}

  bool sbp_msg_settings_write_t_setting_append_vprintf(sbp_multipart_string_t *s, const char *fmt, va_list ap)
{
  return sbp_multipart_string_append_vprintf(s, &sbp_msg_settings_write_tsetting_params, fmt, ap);
}

  const char *sbp_msg_settings_write_t_setting_get_section(const sbp_multipart_string_t *s, uint8_t section)
{
  return sbp_multipart_string_get_section(s, &sbp_msg_settings_write_tsetting_params, section);
}

  uint8_t sbp_msg_settings_write_t_setting_section_strlen(const sbp_multipart_string_t *s, uint8_t section)
{
  return sbp_multipart_string_section_strlen(s, &sbp_msg_settings_write_tsetting_params, section);
}

size_t sbp_packed_size_sbp_msg_settings_write_t(const sbp_msg_settings_write_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_multipart_string_packed_len(&msg->setting, &sbp_msg_settings_write_tsetting_params);
  return packed_size;
}

bool pack_sbp_msg_settings_write_t(sbp_pack_ctx_t *ctx, const sbp_msg_settings_write_t *msg)
{
  if (!sbp_multipart_string_pack(&msg->setting, &sbp_msg_settings_write_tsetting_params, ctx)) { return false; }
  return true;
}

s8 sbp_pack_sbp_msg_settings_write_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_settings_write_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_msg_settings_write_t(&ctx, msg)) {
    return SBP_PACK_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_msg_settings_write_t(sbp_unpack_ctx_t *ctx, sbp_msg_settings_write_t *msg)
{
  if (!sbp_multipart_string_unpack(&msg->setting, &sbp_msg_settings_write_tsetting_params, ctx)) { return false; }
  return true;
}

s8 sbp_unpack_sbp_msg_settings_write_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_settings_write_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_msg_settings_write_t(&ctx, msg)) {
    return SBP_UNPACK_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

int sbp_cmp_sbp_msg_settings_write_t(const sbp_msg_settings_write_t *a, const sbp_msg_settings_write_t *b) {
  int ret = 0;
  
  ret = sbp_multipart_string_strcmp(&a->setting, &b->setting, &sbp_msg_settings_write_tsetting_params);
  if (ret != 0) { return ret; }
  return ret;
}
static const sbp_multipart_string_params_t sbp_msg_settings_write_resp_tsetting_params = 
{
  .max_packed_len = 254
};

  void sbp_msg_settings_write_resp_t_setting_init(sbp_multipart_string_t *s)
{
  sbp_multipart_string_init(s, &sbp_msg_settings_write_resp_tsetting_params);
}

  bool sbp_msg_settings_write_resp_t_setting_valid(const sbp_multipart_string_t *s)
{
  return sbp_multipart_string_valid(s, &sbp_msg_settings_write_resp_tsetting_params);
}

  int sbp_msg_settings_write_resp_t_setting_strcmp(const sbp_multipart_string_t *a, const sbp_multipart_string_t *b)
{
  return sbp_multipart_string_strcmp(a, b, &sbp_msg_settings_write_resp_tsetting_params);
}

  uint8_t sbp_msg_settings_write_resp_t_setting_packed_len(const sbp_multipart_string_t *s)
{
  return sbp_multipart_string_packed_len(s, &sbp_msg_settings_write_resp_tsetting_params);
}

  uint8_t sbp_msg_settings_write_resp_t_setting_space_remaining(const sbp_multipart_string_t *s)
{
  return sbp_multipart_string_space_remaining(s, &sbp_msg_settings_write_resp_tsetting_params);
      }
  uint8_t sbp_msg_settings_write_resp_t_setting_count_sections(const sbp_multipart_string_t *s)
{
  return sbp_multipart_string_count_sections(s, &sbp_msg_settings_write_resp_tsetting_params);
}

  bool sbp_msg_settings_write_resp_t_setting_add_section(sbp_multipart_string_t *s, const char *new_str)
{
  return sbp_multipart_string_add_section(s, &sbp_msg_settings_write_resp_tsetting_params, new_str);
}

  bool sbp_msg_settings_write_resp_t_setting_add_section_printf(sbp_multipart_string_t *s, const char *fmt, ...) 
{
  va_list ap;
  va_start(ap, fmt);
  bool ret = sbp_multipart_string_add_section_vprintf(s, &sbp_msg_settings_write_resp_tsetting_params, fmt, ap);
  va_end(ap);
  return ret;
}

  bool sbp_msg_settings_write_resp_t_setting_add_section_vprintf(sbp_multipart_string_t *s, const char *fmt, va_list ap)
{
  return sbp_multipart_string_add_section_vprintf(s, &sbp_msg_settings_write_resp_tsetting_params, fmt, ap);
}

  bool sbp_msg_settings_write_resp_t_setting_append(sbp_multipart_string_t *s, const char *str)
{
  return sbp_multipart_string_append(s, &sbp_msg_settings_write_resp_tsetting_params, str);
}

  bool sbp_msg_settings_write_resp_t_setting_append_printf(sbp_multipart_string_t *s, const char *fmt, ...) 
{
  va_list ap;
  va_start(ap, fmt);
  bool ret = sbp_multipart_string_append_vprintf(s, &sbp_msg_settings_write_resp_tsetting_params, fmt, ap);
  va_end(ap);
  return ret;
}

  bool sbp_msg_settings_write_resp_t_setting_append_vprintf(sbp_multipart_string_t *s, const char *fmt, va_list ap)
{
  return sbp_multipart_string_append_vprintf(s, &sbp_msg_settings_write_resp_tsetting_params, fmt, ap);
}

  const char *sbp_msg_settings_write_resp_t_setting_get_section(const sbp_multipart_string_t *s, uint8_t section)
{
  return sbp_multipart_string_get_section(s, &sbp_msg_settings_write_resp_tsetting_params, section);
}

  uint8_t sbp_msg_settings_write_resp_t_setting_section_strlen(const sbp_multipart_string_t *s, uint8_t section)
{
  return sbp_multipart_string_section_strlen(s, &sbp_msg_settings_write_resp_tsetting_params, section);
}

size_t sbp_packed_size_sbp_msg_settings_write_resp_t(const sbp_msg_settings_write_resp_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u8(&msg->status);
  packed_size += sbp_multipart_string_packed_len(&msg->setting, &sbp_msg_settings_write_resp_tsetting_params);
  return packed_size;
}

bool pack_sbp_msg_settings_write_resp_t(sbp_pack_ctx_t *ctx, const sbp_msg_settings_write_resp_t *msg)
{
  if (!pack_u8(ctx, &msg->status)) { return false; }
  if (!sbp_multipart_string_pack(&msg->setting, &sbp_msg_settings_write_resp_tsetting_params, ctx)) { return false; }
  return true;
}

s8 sbp_pack_sbp_msg_settings_write_resp_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_settings_write_resp_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_msg_settings_write_resp_t(&ctx, msg)) {
    return SBP_PACK_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_msg_settings_write_resp_t(sbp_unpack_ctx_t *ctx, sbp_msg_settings_write_resp_t *msg)
{
  if (!unpack_u8(ctx, &msg->status)) { return false; }
  if (!sbp_multipart_string_unpack(&msg->setting, &sbp_msg_settings_write_resp_tsetting_params, ctx)) { return false; }
  return true;
}

s8 sbp_unpack_sbp_msg_settings_write_resp_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_settings_write_resp_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_msg_settings_write_resp_t(&ctx, msg)) {
    return SBP_UNPACK_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

int sbp_cmp_sbp_msg_settings_write_resp_t(const sbp_msg_settings_write_resp_t *a, const sbp_msg_settings_write_resp_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u8(&a->status, &b->status);
  if (ret != 0) { return ret; }
  
  ret = sbp_multipart_string_strcmp(&a->setting, &b->setting, &sbp_msg_settings_write_resp_tsetting_params);
  if (ret != 0) { return ret; }
  return ret;
}
static const sbp_multipart_string_params_t sbp_msg_settings_read_req_tsetting_params = 
{
  .max_packed_len = 255
};

  void sbp_msg_settings_read_req_t_setting_init(sbp_multipart_string_t *s)
{
  sbp_multipart_string_init(s, &sbp_msg_settings_read_req_tsetting_params);
}

  bool sbp_msg_settings_read_req_t_setting_valid(const sbp_multipart_string_t *s)
{
  return sbp_multipart_string_valid(s, &sbp_msg_settings_read_req_tsetting_params);
}

  int sbp_msg_settings_read_req_t_setting_strcmp(const sbp_multipart_string_t *a, const sbp_multipart_string_t *b)
{
  return sbp_multipart_string_strcmp(a, b, &sbp_msg_settings_read_req_tsetting_params);
}

  uint8_t sbp_msg_settings_read_req_t_setting_packed_len(const sbp_multipart_string_t *s)
{
  return sbp_multipart_string_packed_len(s, &sbp_msg_settings_read_req_tsetting_params);
}

  uint8_t sbp_msg_settings_read_req_t_setting_space_remaining(const sbp_multipart_string_t *s)
{
  return sbp_multipart_string_space_remaining(s, &sbp_msg_settings_read_req_tsetting_params);
      }
  uint8_t sbp_msg_settings_read_req_t_setting_count_sections(const sbp_multipart_string_t *s)
{
  return sbp_multipart_string_count_sections(s, &sbp_msg_settings_read_req_tsetting_params);
}

  bool sbp_msg_settings_read_req_t_setting_add_section(sbp_multipart_string_t *s, const char *new_str)
{
  return sbp_multipart_string_add_section(s, &sbp_msg_settings_read_req_tsetting_params, new_str);
}

  bool sbp_msg_settings_read_req_t_setting_add_section_printf(sbp_multipart_string_t *s, const char *fmt, ...) 
{
  va_list ap;
  va_start(ap, fmt);
  bool ret = sbp_multipart_string_add_section_vprintf(s, &sbp_msg_settings_read_req_tsetting_params, fmt, ap);
  va_end(ap);
  return ret;
}

  bool sbp_msg_settings_read_req_t_setting_add_section_vprintf(sbp_multipart_string_t *s, const char *fmt, va_list ap)
{
  return sbp_multipart_string_add_section_vprintf(s, &sbp_msg_settings_read_req_tsetting_params, fmt, ap);
}

  bool sbp_msg_settings_read_req_t_setting_append(sbp_multipart_string_t *s, const char *str)
{
  return sbp_multipart_string_append(s, &sbp_msg_settings_read_req_tsetting_params, str);
}

  bool sbp_msg_settings_read_req_t_setting_append_printf(sbp_multipart_string_t *s, const char *fmt, ...) 
{
  va_list ap;
  va_start(ap, fmt);
  bool ret = sbp_multipart_string_append_vprintf(s, &sbp_msg_settings_read_req_tsetting_params, fmt, ap);
  va_end(ap);
  return ret;
}

  bool sbp_msg_settings_read_req_t_setting_append_vprintf(sbp_multipart_string_t *s, const char *fmt, va_list ap)
{
  return sbp_multipart_string_append_vprintf(s, &sbp_msg_settings_read_req_tsetting_params, fmt, ap);
}

  const char *sbp_msg_settings_read_req_t_setting_get_section(const sbp_multipart_string_t *s, uint8_t section)
{
  return sbp_multipart_string_get_section(s, &sbp_msg_settings_read_req_tsetting_params, section);
}

  uint8_t sbp_msg_settings_read_req_t_setting_section_strlen(const sbp_multipart_string_t *s, uint8_t section)
{
  return sbp_multipart_string_section_strlen(s, &sbp_msg_settings_read_req_tsetting_params, section);
}

size_t sbp_packed_size_sbp_msg_settings_read_req_t(const sbp_msg_settings_read_req_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_multipart_string_packed_len(&msg->setting, &sbp_msg_settings_read_req_tsetting_params);
  return packed_size;
}

bool pack_sbp_msg_settings_read_req_t(sbp_pack_ctx_t *ctx, const sbp_msg_settings_read_req_t *msg)
{
  if (!sbp_multipart_string_pack(&msg->setting, &sbp_msg_settings_read_req_tsetting_params, ctx)) { return false; }
  return true;
}

s8 sbp_pack_sbp_msg_settings_read_req_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_settings_read_req_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_msg_settings_read_req_t(&ctx, msg)) {
    return SBP_PACK_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_msg_settings_read_req_t(sbp_unpack_ctx_t *ctx, sbp_msg_settings_read_req_t *msg)
{
  if (!sbp_multipart_string_unpack(&msg->setting, &sbp_msg_settings_read_req_tsetting_params, ctx)) { return false; }
  return true;
}

s8 sbp_unpack_sbp_msg_settings_read_req_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_settings_read_req_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_msg_settings_read_req_t(&ctx, msg)) {
    return SBP_UNPACK_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

int sbp_cmp_sbp_msg_settings_read_req_t(const sbp_msg_settings_read_req_t *a, const sbp_msg_settings_read_req_t *b) {
  int ret = 0;
  
  ret = sbp_multipart_string_strcmp(&a->setting, &b->setting, &sbp_msg_settings_read_req_tsetting_params);
  if (ret != 0) { return ret; }
  return ret;
}
static const sbp_multipart_string_params_t sbp_msg_settings_read_resp_tsetting_params = 
{
  .max_packed_len = 255
};

  void sbp_msg_settings_read_resp_t_setting_init(sbp_multipart_string_t *s)
{
  sbp_multipart_string_init(s, &sbp_msg_settings_read_resp_tsetting_params);
}

  bool sbp_msg_settings_read_resp_t_setting_valid(const sbp_multipart_string_t *s)
{
  return sbp_multipart_string_valid(s, &sbp_msg_settings_read_resp_tsetting_params);
}

  int sbp_msg_settings_read_resp_t_setting_strcmp(const sbp_multipart_string_t *a, const sbp_multipart_string_t *b)
{
  return sbp_multipart_string_strcmp(a, b, &sbp_msg_settings_read_resp_tsetting_params);
}

  uint8_t sbp_msg_settings_read_resp_t_setting_packed_len(const sbp_multipart_string_t *s)
{
  return sbp_multipart_string_packed_len(s, &sbp_msg_settings_read_resp_tsetting_params);
}

  uint8_t sbp_msg_settings_read_resp_t_setting_space_remaining(const sbp_multipart_string_t *s)
{
  return sbp_multipart_string_space_remaining(s, &sbp_msg_settings_read_resp_tsetting_params);
      }
  uint8_t sbp_msg_settings_read_resp_t_setting_count_sections(const sbp_multipart_string_t *s)
{
  return sbp_multipart_string_count_sections(s, &sbp_msg_settings_read_resp_tsetting_params);
}

  bool sbp_msg_settings_read_resp_t_setting_add_section(sbp_multipart_string_t *s, const char *new_str)
{
  return sbp_multipart_string_add_section(s, &sbp_msg_settings_read_resp_tsetting_params, new_str);
}

  bool sbp_msg_settings_read_resp_t_setting_add_section_printf(sbp_multipart_string_t *s, const char *fmt, ...) 
{
  va_list ap;
  va_start(ap, fmt);
  bool ret = sbp_multipart_string_add_section_vprintf(s, &sbp_msg_settings_read_resp_tsetting_params, fmt, ap);
  va_end(ap);
  return ret;
}

  bool sbp_msg_settings_read_resp_t_setting_add_section_vprintf(sbp_multipart_string_t *s, const char *fmt, va_list ap)
{
  return sbp_multipart_string_add_section_vprintf(s, &sbp_msg_settings_read_resp_tsetting_params, fmt, ap);
}

  bool sbp_msg_settings_read_resp_t_setting_append(sbp_multipart_string_t *s, const char *str)
{
  return sbp_multipart_string_append(s, &sbp_msg_settings_read_resp_tsetting_params, str);
}

  bool sbp_msg_settings_read_resp_t_setting_append_printf(sbp_multipart_string_t *s, const char *fmt, ...) 
{
  va_list ap;
  va_start(ap, fmt);
  bool ret = sbp_multipart_string_append_vprintf(s, &sbp_msg_settings_read_resp_tsetting_params, fmt, ap);
  va_end(ap);
  return ret;
}

  bool sbp_msg_settings_read_resp_t_setting_append_vprintf(sbp_multipart_string_t *s, const char *fmt, va_list ap)
{
  return sbp_multipart_string_append_vprintf(s, &sbp_msg_settings_read_resp_tsetting_params, fmt, ap);
}

  const char *sbp_msg_settings_read_resp_t_setting_get_section(const sbp_multipart_string_t *s, uint8_t section)
{
  return sbp_multipart_string_get_section(s, &sbp_msg_settings_read_resp_tsetting_params, section);
}

  uint8_t sbp_msg_settings_read_resp_t_setting_section_strlen(const sbp_multipart_string_t *s, uint8_t section)
{
  return sbp_multipart_string_section_strlen(s, &sbp_msg_settings_read_resp_tsetting_params, section);
}

size_t sbp_packed_size_sbp_msg_settings_read_resp_t(const sbp_msg_settings_read_resp_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_multipart_string_packed_len(&msg->setting, &sbp_msg_settings_read_resp_tsetting_params);
  return packed_size;
}

bool pack_sbp_msg_settings_read_resp_t(sbp_pack_ctx_t *ctx, const sbp_msg_settings_read_resp_t *msg)
{
  if (!sbp_multipart_string_pack(&msg->setting, &sbp_msg_settings_read_resp_tsetting_params, ctx)) { return false; }
  return true;
}

s8 sbp_pack_sbp_msg_settings_read_resp_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_settings_read_resp_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_msg_settings_read_resp_t(&ctx, msg)) {
    return SBP_PACK_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_msg_settings_read_resp_t(sbp_unpack_ctx_t *ctx, sbp_msg_settings_read_resp_t *msg)
{
  if (!sbp_multipart_string_unpack(&msg->setting, &sbp_msg_settings_read_resp_tsetting_params, ctx)) { return false; }
  return true;
}

s8 sbp_unpack_sbp_msg_settings_read_resp_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_settings_read_resp_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_msg_settings_read_resp_t(&ctx, msg)) {
    return SBP_UNPACK_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

int sbp_cmp_sbp_msg_settings_read_resp_t(const sbp_msg_settings_read_resp_t *a, const sbp_msg_settings_read_resp_t *b) {
  int ret = 0;
  
  ret = sbp_multipart_string_strcmp(&a->setting, &b->setting, &sbp_msg_settings_read_resp_tsetting_params);
  if (ret != 0) { return ret; }
  return ret;
}

size_t sbp_packed_size_sbp_msg_settings_read_by_index_req_t(const sbp_msg_settings_read_by_index_req_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u16(&msg->index);
  return packed_size;
}

bool pack_sbp_msg_settings_read_by_index_req_t(sbp_pack_ctx_t *ctx, const sbp_msg_settings_read_by_index_req_t *msg)
{
  if (!pack_u16(ctx, &msg->index)) { return false; }
  return true;
}

s8 sbp_pack_sbp_msg_settings_read_by_index_req_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_settings_read_by_index_req_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_msg_settings_read_by_index_req_t(&ctx, msg)) {
    return SBP_PACK_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_msg_settings_read_by_index_req_t(sbp_unpack_ctx_t *ctx, sbp_msg_settings_read_by_index_req_t *msg)
{
  if (!unpack_u16(ctx, &msg->index)) { return false; }
  return true;
}

s8 sbp_unpack_sbp_msg_settings_read_by_index_req_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_settings_read_by_index_req_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_msg_settings_read_by_index_req_t(&ctx, msg)) {
    return SBP_UNPACK_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

int sbp_cmp_sbp_msg_settings_read_by_index_req_t(const sbp_msg_settings_read_by_index_req_t *a, const sbp_msg_settings_read_by_index_req_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u16(&a->index, &b->index);
  if (ret != 0) { return ret; }
  return ret;
}
static const sbp_multipart_string_params_t sbp_msg_settings_read_by_index_resp_tsetting_params = 
{
  .max_packed_len = 253
};

  void sbp_msg_settings_read_by_index_resp_t_setting_init(sbp_multipart_string_t *s)
{
  sbp_multipart_string_init(s, &sbp_msg_settings_read_by_index_resp_tsetting_params);
}

  bool sbp_msg_settings_read_by_index_resp_t_setting_valid(const sbp_multipart_string_t *s)
{
  return sbp_multipart_string_valid(s, &sbp_msg_settings_read_by_index_resp_tsetting_params);
}

  int sbp_msg_settings_read_by_index_resp_t_setting_strcmp(const sbp_multipart_string_t *a, const sbp_multipart_string_t *b)
{
  return sbp_multipart_string_strcmp(a, b, &sbp_msg_settings_read_by_index_resp_tsetting_params);
}

  uint8_t sbp_msg_settings_read_by_index_resp_t_setting_packed_len(const sbp_multipart_string_t *s)
{
  return sbp_multipart_string_packed_len(s, &sbp_msg_settings_read_by_index_resp_tsetting_params);
}

  uint8_t sbp_msg_settings_read_by_index_resp_t_setting_space_remaining(const sbp_multipart_string_t *s)
{
  return sbp_multipart_string_space_remaining(s, &sbp_msg_settings_read_by_index_resp_tsetting_params);
      }
  uint8_t sbp_msg_settings_read_by_index_resp_t_setting_count_sections(const sbp_multipart_string_t *s)
{
  return sbp_multipart_string_count_sections(s, &sbp_msg_settings_read_by_index_resp_tsetting_params);
}

  bool sbp_msg_settings_read_by_index_resp_t_setting_add_section(sbp_multipart_string_t *s, const char *new_str)
{
  return sbp_multipart_string_add_section(s, &sbp_msg_settings_read_by_index_resp_tsetting_params, new_str);
}

  bool sbp_msg_settings_read_by_index_resp_t_setting_add_section_printf(sbp_multipart_string_t *s, const char *fmt, ...) 
{
  va_list ap;
  va_start(ap, fmt);
  bool ret = sbp_multipart_string_add_section_vprintf(s, &sbp_msg_settings_read_by_index_resp_tsetting_params, fmt, ap);
  va_end(ap);
  return ret;
}

  bool sbp_msg_settings_read_by_index_resp_t_setting_add_section_vprintf(sbp_multipart_string_t *s, const char *fmt, va_list ap)
{
  return sbp_multipart_string_add_section_vprintf(s, &sbp_msg_settings_read_by_index_resp_tsetting_params, fmt, ap);
}

  bool sbp_msg_settings_read_by_index_resp_t_setting_append(sbp_multipart_string_t *s, const char *str)
{
  return sbp_multipart_string_append(s, &sbp_msg_settings_read_by_index_resp_tsetting_params, str);
}

  bool sbp_msg_settings_read_by_index_resp_t_setting_append_printf(sbp_multipart_string_t *s, const char *fmt, ...) 
{
  va_list ap;
  va_start(ap, fmt);
  bool ret = sbp_multipart_string_append_vprintf(s, &sbp_msg_settings_read_by_index_resp_tsetting_params, fmt, ap);
  va_end(ap);
  return ret;
}

  bool sbp_msg_settings_read_by_index_resp_t_setting_append_vprintf(sbp_multipart_string_t *s, const char *fmt, va_list ap)
{
  return sbp_multipart_string_append_vprintf(s, &sbp_msg_settings_read_by_index_resp_tsetting_params, fmt, ap);
}

  const char *sbp_msg_settings_read_by_index_resp_t_setting_get_section(const sbp_multipart_string_t *s, uint8_t section)
{
  return sbp_multipart_string_get_section(s, &sbp_msg_settings_read_by_index_resp_tsetting_params, section);
}

  uint8_t sbp_msg_settings_read_by_index_resp_t_setting_section_strlen(const sbp_multipart_string_t *s, uint8_t section)
{
  return sbp_multipart_string_section_strlen(s, &sbp_msg_settings_read_by_index_resp_tsetting_params, section);
}

size_t sbp_packed_size_sbp_msg_settings_read_by_index_resp_t(const sbp_msg_settings_read_by_index_resp_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u16(&msg->index);
  packed_size += sbp_multipart_string_packed_len(&msg->setting, &sbp_msg_settings_read_by_index_resp_tsetting_params);
  return packed_size;
}

bool pack_sbp_msg_settings_read_by_index_resp_t(sbp_pack_ctx_t *ctx, const sbp_msg_settings_read_by_index_resp_t *msg)
{
  if (!pack_u16(ctx, &msg->index)) { return false; }
  if (!sbp_multipart_string_pack(&msg->setting, &sbp_msg_settings_read_by_index_resp_tsetting_params, ctx)) { return false; }
  return true;
}

s8 sbp_pack_sbp_msg_settings_read_by_index_resp_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_settings_read_by_index_resp_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_msg_settings_read_by_index_resp_t(&ctx, msg)) {
    return SBP_PACK_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_msg_settings_read_by_index_resp_t(sbp_unpack_ctx_t *ctx, sbp_msg_settings_read_by_index_resp_t *msg)
{
  if (!unpack_u16(ctx, &msg->index)) { return false; }
  if (!sbp_multipart_string_unpack(&msg->setting, &sbp_msg_settings_read_by_index_resp_tsetting_params, ctx)) { return false; }
  return true;
}

s8 sbp_unpack_sbp_msg_settings_read_by_index_resp_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_settings_read_by_index_resp_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_msg_settings_read_by_index_resp_t(&ctx, msg)) {
    return SBP_UNPACK_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

int sbp_cmp_sbp_msg_settings_read_by_index_resp_t(const sbp_msg_settings_read_by_index_resp_t *a, const sbp_msg_settings_read_by_index_resp_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u16(&a->index, &b->index);
  if (ret != 0) { return ret; }
  
  ret = sbp_multipart_string_strcmp(&a->setting, &b->setting, &sbp_msg_settings_read_by_index_resp_tsetting_params);
  if (ret != 0) { return ret; }
  return ret;
}

size_t sbp_packed_size_sbp_msg_settings_read_by_index_done_t(const sbp_msg_settings_read_by_index_done_t *msg) {
  (void)msg;
  return 0;
}

bool pack_sbp_msg_settings_read_by_index_done_t(sbp_pack_ctx_t *ctx, const sbp_msg_settings_read_by_index_done_t *msg)
{
  (void)ctx;
  (void)msg;
  return true;
}

s8 sbp_pack_sbp_msg_settings_read_by_index_done_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_settings_read_by_index_done_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_msg_settings_read_by_index_done_t(&ctx, msg)) {
    return SBP_PACK_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_msg_settings_read_by_index_done_t(sbp_unpack_ctx_t *ctx, sbp_msg_settings_read_by_index_done_t *msg)
{
    (void)ctx;
  (void)msg;
  return true;
}

s8 sbp_unpack_sbp_msg_settings_read_by_index_done_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_settings_read_by_index_done_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_msg_settings_read_by_index_done_t(&ctx, msg)) {
    return SBP_UNPACK_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

int sbp_cmp_sbp_msg_settings_read_by_index_done_t(const sbp_msg_settings_read_by_index_done_t *a, const sbp_msg_settings_read_by_index_done_t *b) {
  (void)a;
  (void)b;
  int ret = 0;
  return ret;
}
static const sbp_multipart_string_params_t sbp_msg_settings_register_tsetting_params = 
{
  .max_packed_len = 255
};

  void sbp_msg_settings_register_t_setting_init(sbp_multipart_string_t *s)
{
  sbp_multipart_string_init(s, &sbp_msg_settings_register_tsetting_params);
}

  bool sbp_msg_settings_register_t_setting_valid(const sbp_multipart_string_t *s)
{
  return sbp_multipart_string_valid(s, &sbp_msg_settings_register_tsetting_params);
}

  int sbp_msg_settings_register_t_setting_strcmp(const sbp_multipart_string_t *a, const sbp_multipart_string_t *b)
{
  return sbp_multipart_string_strcmp(a, b, &sbp_msg_settings_register_tsetting_params);
}

  uint8_t sbp_msg_settings_register_t_setting_packed_len(const sbp_multipart_string_t *s)
{
  return sbp_multipart_string_packed_len(s, &sbp_msg_settings_register_tsetting_params);
}

  uint8_t sbp_msg_settings_register_t_setting_space_remaining(const sbp_multipart_string_t *s)
{
  return sbp_multipart_string_space_remaining(s, &sbp_msg_settings_register_tsetting_params);
      }
  uint8_t sbp_msg_settings_register_t_setting_count_sections(const sbp_multipart_string_t *s)
{
  return sbp_multipart_string_count_sections(s, &sbp_msg_settings_register_tsetting_params);
}

  bool sbp_msg_settings_register_t_setting_add_section(sbp_multipart_string_t *s, const char *new_str)
{
  return sbp_multipart_string_add_section(s, &sbp_msg_settings_register_tsetting_params, new_str);
}

  bool sbp_msg_settings_register_t_setting_add_section_printf(sbp_multipart_string_t *s, const char *fmt, ...) 
{
  va_list ap;
  va_start(ap, fmt);
  bool ret = sbp_multipart_string_add_section_vprintf(s, &sbp_msg_settings_register_tsetting_params, fmt, ap);
  va_end(ap);
  return ret;
}

  bool sbp_msg_settings_register_t_setting_add_section_vprintf(sbp_multipart_string_t *s, const char *fmt, va_list ap)
{
  return sbp_multipart_string_add_section_vprintf(s, &sbp_msg_settings_register_tsetting_params, fmt, ap);
}

  bool sbp_msg_settings_register_t_setting_append(sbp_multipart_string_t *s, const char *str)
{
  return sbp_multipart_string_append(s, &sbp_msg_settings_register_tsetting_params, str);
}

  bool sbp_msg_settings_register_t_setting_append_printf(sbp_multipart_string_t *s, const char *fmt, ...) 
{
  va_list ap;
  va_start(ap, fmt);
  bool ret = sbp_multipart_string_append_vprintf(s, &sbp_msg_settings_register_tsetting_params, fmt, ap);
  va_end(ap);
  return ret;
}

  bool sbp_msg_settings_register_t_setting_append_vprintf(sbp_multipart_string_t *s, const char *fmt, va_list ap)
{
  return sbp_multipart_string_append_vprintf(s, &sbp_msg_settings_register_tsetting_params, fmt, ap);
}

  const char *sbp_msg_settings_register_t_setting_get_section(const sbp_multipart_string_t *s, uint8_t section)
{
  return sbp_multipart_string_get_section(s, &sbp_msg_settings_register_tsetting_params, section);
}

  uint8_t sbp_msg_settings_register_t_setting_section_strlen(const sbp_multipart_string_t *s, uint8_t section)
{
  return sbp_multipart_string_section_strlen(s, &sbp_msg_settings_register_tsetting_params, section);
}

size_t sbp_packed_size_sbp_msg_settings_register_t(const sbp_msg_settings_register_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_multipart_string_packed_len(&msg->setting, &sbp_msg_settings_register_tsetting_params);
  return packed_size;
}

bool pack_sbp_msg_settings_register_t(sbp_pack_ctx_t *ctx, const sbp_msg_settings_register_t *msg)
{
  if (!sbp_multipart_string_pack(&msg->setting, &sbp_msg_settings_register_tsetting_params, ctx)) { return false; }
  return true;
}

s8 sbp_pack_sbp_msg_settings_register_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_settings_register_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_msg_settings_register_t(&ctx, msg)) {
    return SBP_PACK_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_msg_settings_register_t(sbp_unpack_ctx_t *ctx, sbp_msg_settings_register_t *msg)
{
  if (!sbp_multipart_string_unpack(&msg->setting, &sbp_msg_settings_register_tsetting_params, ctx)) { return false; }
  return true;
}

s8 sbp_unpack_sbp_msg_settings_register_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_settings_register_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_msg_settings_register_t(&ctx, msg)) {
    return SBP_UNPACK_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

int sbp_cmp_sbp_msg_settings_register_t(const sbp_msg_settings_register_t *a, const sbp_msg_settings_register_t *b) {
  int ret = 0;
  
  ret = sbp_multipart_string_strcmp(&a->setting, &b->setting, &sbp_msg_settings_register_tsetting_params);
  if (ret != 0) { return ret; }
  return ret;
}
static const sbp_multipart_string_params_t sbp_msg_settings_register_resp_tsetting_params = 
{
  .max_packed_len = 254
};

  void sbp_msg_settings_register_resp_t_setting_init(sbp_multipart_string_t *s)
{
  sbp_multipart_string_init(s, &sbp_msg_settings_register_resp_tsetting_params);
}

  bool sbp_msg_settings_register_resp_t_setting_valid(const sbp_multipart_string_t *s)
{
  return sbp_multipart_string_valid(s, &sbp_msg_settings_register_resp_tsetting_params);
}

  int sbp_msg_settings_register_resp_t_setting_strcmp(const sbp_multipart_string_t *a, const sbp_multipart_string_t *b)
{
  return sbp_multipart_string_strcmp(a, b, &sbp_msg_settings_register_resp_tsetting_params);
}

  uint8_t sbp_msg_settings_register_resp_t_setting_packed_len(const sbp_multipart_string_t *s)
{
  return sbp_multipart_string_packed_len(s, &sbp_msg_settings_register_resp_tsetting_params);
}

  uint8_t sbp_msg_settings_register_resp_t_setting_space_remaining(const sbp_multipart_string_t *s)
{
  return sbp_multipart_string_space_remaining(s, &sbp_msg_settings_register_resp_tsetting_params);
      }
  uint8_t sbp_msg_settings_register_resp_t_setting_count_sections(const sbp_multipart_string_t *s)
{
  return sbp_multipart_string_count_sections(s, &sbp_msg_settings_register_resp_tsetting_params);
}

  bool sbp_msg_settings_register_resp_t_setting_add_section(sbp_multipart_string_t *s, const char *new_str)
{
  return sbp_multipart_string_add_section(s, &sbp_msg_settings_register_resp_tsetting_params, new_str);
}

  bool sbp_msg_settings_register_resp_t_setting_add_section_printf(sbp_multipart_string_t *s, const char *fmt, ...) 
{
  va_list ap;
  va_start(ap, fmt);
  bool ret = sbp_multipart_string_add_section_vprintf(s, &sbp_msg_settings_register_resp_tsetting_params, fmt, ap);
  va_end(ap);
  return ret;
}

  bool sbp_msg_settings_register_resp_t_setting_add_section_vprintf(sbp_multipart_string_t *s, const char *fmt, va_list ap)
{
  return sbp_multipart_string_add_section_vprintf(s, &sbp_msg_settings_register_resp_tsetting_params, fmt, ap);
}

  bool sbp_msg_settings_register_resp_t_setting_append(sbp_multipart_string_t *s, const char *str)
{
  return sbp_multipart_string_append(s, &sbp_msg_settings_register_resp_tsetting_params, str);
}

  bool sbp_msg_settings_register_resp_t_setting_append_printf(sbp_multipart_string_t *s, const char *fmt, ...) 
{
  va_list ap;
  va_start(ap, fmt);
  bool ret = sbp_multipart_string_append_vprintf(s, &sbp_msg_settings_register_resp_tsetting_params, fmt, ap);
  va_end(ap);
  return ret;
}

  bool sbp_msg_settings_register_resp_t_setting_append_vprintf(sbp_multipart_string_t *s, const char *fmt, va_list ap)
{
  return sbp_multipart_string_append_vprintf(s, &sbp_msg_settings_register_resp_tsetting_params, fmt, ap);
}

  const char *sbp_msg_settings_register_resp_t_setting_get_section(const sbp_multipart_string_t *s, uint8_t section)
{
  return sbp_multipart_string_get_section(s, &sbp_msg_settings_register_resp_tsetting_params, section);
}

  uint8_t sbp_msg_settings_register_resp_t_setting_section_strlen(const sbp_multipart_string_t *s, uint8_t section)
{
  return sbp_multipart_string_section_strlen(s, &sbp_msg_settings_register_resp_tsetting_params, section);
}

size_t sbp_packed_size_sbp_msg_settings_register_resp_t(const sbp_msg_settings_register_resp_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u8(&msg->status);
  packed_size += sbp_multipart_string_packed_len(&msg->setting, &sbp_msg_settings_register_resp_tsetting_params);
  return packed_size;
}

bool pack_sbp_msg_settings_register_resp_t(sbp_pack_ctx_t *ctx, const sbp_msg_settings_register_resp_t *msg)
{
  if (!pack_u8(ctx, &msg->status)) { return false; }
  if (!sbp_multipart_string_pack(&msg->setting, &sbp_msg_settings_register_resp_tsetting_params, ctx)) { return false; }
  return true;
}

s8 sbp_pack_sbp_msg_settings_register_resp_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_settings_register_resp_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_msg_settings_register_resp_t(&ctx, msg)) {
    return SBP_PACK_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_msg_settings_register_resp_t(sbp_unpack_ctx_t *ctx, sbp_msg_settings_register_resp_t *msg)
{
  if (!unpack_u8(ctx, &msg->status)) { return false; }
  if (!sbp_multipart_string_unpack(&msg->setting, &sbp_msg_settings_register_resp_tsetting_params, ctx)) { return false; }
  return true;
}

s8 sbp_unpack_sbp_msg_settings_register_resp_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_settings_register_resp_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_msg_settings_register_resp_t(&ctx, msg)) {
    return SBP_UNPACK_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

int sbp_cmp_sbp_msg_settings_register_resp_t(const sbp_msg_settings_register_resp_t *a, const sbp_msg_settings_register_resp_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u8(&a->status, &b->status);
  if (ret != 0) { return ret; }
  
  ret = sbp_multipart_string_strcmp(&a->setting, &b->setting, &sbp_msg_settings_register_resp_tsetting_params);
  if (ret != 0) { return ret; }
  return ret;
}
