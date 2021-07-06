/*****************************************************************************
 * Automatically generated from yaml/swiftnav/sbp/settings.yaml
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#include <libsbp/internal/v4/common.h>
#include <libsbp/internal/v4/settings.h>
#include <libsbp/internal/v4/string/double_null_terminated.h>
#include <libsbp/internal/v4/string/multipart.h>
#include <libsbp/internal/v4/string/null_terminated.h>
#include <libsbp/internal/v4/string/unterminated.h>
#include <libsbp/sbp.h>
#include <libsbp/v4/settings.h>

bool sbp_msg_settings_save_encode_internal(sbp_encode_ctx_t *ctx,
                                           const sbp_msg_settings_save_t *msg) {
  (void)ctx;
  (void)msg;
  return true;
}

s8 sbp_msg_settings_save_encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                                const sbp_msg_settings_save_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_settings_save_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_settings_save_decode_internal(sbp_decode_ctx_t *ctx,
                                           sbp_msg_settings_save_t *msg) {
  (void)ctx;
  (void)msg;
  return true;
}

s8 sbp_msg_settings_save_decode(const uint8_t *buf, uint8_t len,
                                uint8_t *n_read, sbp_msg_settings_save_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_settings_save_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_settings_save_send(sbp_state_t *s, u16 sender_id,
                              const sbp_msg_settings_save_t *msg,
                              sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret =
      sbp_msg_settings_save_encode(payload, sizeof(payload), &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_SETTINGS_SAVE, sender_id, payload_len,
                          payload, write);
}

int sbp_msg_settings_save_cmp(const sbp_msg_settings_save_t *a,
                              const sbp_msg_settings_save_t *b) {
  (void)a;
  (void)b;
  int ret = 0;
  return ret;
}

void sbp_msg_settings_write_setting_init(sbp_msg_settings_write_t *msg) {
  sbp_multipart_string_init(&msg->setting);
}

bool sbp_msg_settings_write_setting_valid(const sbp_msg_settings_write_t *msg) {
  return sbp_multipart_string_valid(&msg->setting,
                                    SBP_MSG_SETTINGS_WRITE_SETTING_MAX);
}

int sbp_msg_settings_write_setting_strcmp(const sbp_msg_settings_write_t *a,
                                          const sbp_msg_settings_write_t *b) {
  return sbp_multipart_string_strcmp(&a->setting, &b->setting,
                                     SBP_MSG_SETTINGS_WRITE_SETTING_MAX);
}

size_t sbp_msg_settings_write_setting_encoded_len(
    const sbp_msg_settings_write_t *msg) {
  return sbp_multipart_string_encoded_len(&msg->setting,
                                          SBP_MSG_SETTINGS_WRITE_SETTING_MAX);
}

size_t sbp_msg_settings_write_setting_space_remaining(
    const sbp_msg_settings_write_t *msg) {
  return sbp_multipart_string_space_remaining(
      &msg->setting, SBP_MSG_SETTINGS_WRITE_SETTING_MAX);
}
size_t sbp_msg_settings_write_setting_count_sections(
    const sbp_msg_settings_write_t *msg) {
  return sbp_multipart_string_count_sections(
      &msg->setting, SBP_MSG_SETTINGS_WRITE_SETTING_MAX);
}

bool sbp_msg_settings_write_setting_add_section(sbp_msg_settings_write_t *msg,
                                                const char *new_str) {
  return sbp_multipart_string_add_section(
      &msg->setting, SBP_MSG_SETTINGS_WRITE_SETTING_MAX, new_str);
}

bool sbp_msg_settings_write_setting_add_section_printf(
    sbp_msg_settings_write_t *msg, const char *fmt, ...) {
  va_list ap;
  va_start(ap, fmt);
  bool ret = sbp_multipart_string_add_section_vprintf(
      &msg->setting, SBP_MSG_SETTINGS_WRITE_SETTING_MAX, fmt, ap);
  va_end(ap);
  return ret;
}

bool sbp_msg_settings_write_setting_add_section_vprintf(
    sbp_msg_settings_write_t *msg, const char *fmt, va_list ap) {
  return sbp_multipart_string_add_section_vprintf(
      &msg->setting, SBP_MSG_SETTINGS_WRITE_SETTING_MAX, fmt, ap);
}

bool sbp_msg_settings_write_setting_append(sbp_msg_settings_write_t *msg,
                                           const char *str) {
  return sbp_multipart_string_append(&msg->setting,
                                     SBP_MSG_SETTINGS_WRITE_SETTING_MAX, str);
}

bool sbp_msg_settings_write_setting_append_printf(sbp_msg_settings_write_t *msg,
                                                  const char *fmt, ...) {
  va_list ap;
  va_start(ap, fmt);
  bool ret = sbp_multipart_string_append_vprintf(
      &msg->setting, SBP_MSG_SETTINGS_WRITE_SETTING_MAX, fmt, ap);
  va_end(ap);
  return ret;
}

bool sbp_msg_settings_write_setting_append_vprintf(
    sbp_msg_settings_write_t *msg, const char *fmt, va_list ap) {
  return sbp_multipart_string_append_vprintf(
      &msg->setting, SBP_MSG_SETTINGS_WRITE_SETTING_MAX, fmt, ap);
}

const char *sbp_msg_settings_write_setting_get_section(
    const sbp_msg_settings_write_t *msg, size_t section) {
  return sbp_multipart_string_get_section(
      &msg->setting, SBP_MSG_SETTINGS_WRITE_SETTING_MAX, section);
}

size_t sbp_msg_settings_write_setting_section_strlen(
    const sbp_msg_settings_write_t *msg, size_t section) {
  return sbp_multipart_string_section_strlen(
      &msg->setting, SBP_MSG_SETTINGS_WRITE_SETTING_MAX, section);
}

bool sbp_msg_settings_write_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_settings_write_t *msg) {
  if (!sbp_multipart_string_encode(&msg->setting,
                                   SBP_MSG_SETTINGS_WRITE_SETTING_MAX, ctx)) {
    return false;
  }
  return true;
}

s8 sbp_msg_settings_write_encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                                 const sbp_msg_settings_write_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_settings_write_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_settings_write_decode_internal(sbp_decode_ctx_t *ctx,
                                            sbp_msg_settings_write_t *msg) {
  if (!sbp_multipart_string_decode(&msg->setting,
                                   SBP_MSG_SETTINGS_WRITE_SETTING_MAX, ctx)) {
    return false;
  }
  return true;
}

s8 sbp_msg_settings_write_decode(const uint8_t *buf, uint8_t len,
                                 uint8_t *n_read,
                                 sbp_msg_settings_write_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_settings_write_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_settings_write_send(sbp_state_t *s, u16 sender_id,
                               const sbp_msg_settings_write_t *msg,
                               sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_msg_settings_write_encode(payload, sizeof(payload), &payload_len,
                                         msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_SETTINGS_WRITE, sender_id, payload_len,
                          payload, write);
}

int sbp_msg_settings_write_cmp(const sbp_msg_settings_write_t *a,
                               const sbp_msg_settings_write_t *b) {
  int ret = 0;

  ret = sbp_msg_settings_write_setting_strcmp(a, b);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

void sbp_msg_settings_write_resp_setting_init(
    sbp_msg_settings_write_resp_t *msg) {
  sbp_multipart_string_init(&msg->setting);
}

bool sbp_msg_settings_write_resp_setting_valid(
    const sbp_msg_settings_write_resp_t *msg) {
  return sbp_multipart_string_valid(&msg->setting,
                                    SBP_MSG_SETTINGS_WRITE_RESP_SETTING_MAX);
}

int sbp_msg_settings_write_resp_setting_strcmp(
    const sbp_msg_settings_write_resp_t *a,
    const sbp_msg_settings_write_resp_t *b) {
  return sbp_multipart_string_strcmp(&a->setting, &b->setting,
                                     SBP_MSG_SETTINGS_WRITE_RESP_SETTING_MAX);
}

size_t sbp_msg_settings_write_resp_setting_encoded_len(
    const sbp_msg_settings_write_resp_t *msg) {
  return sbp_multipart_string_encoded_len(
      &msg->setting, SBP_MSG_SETTINGS_WRITE_RESP_SETTING_MAX);
}

size_t sbp_msg_settings_write_resp_setting_space_remaining(
    const sbp_msg_settings_write_resp_t *msg) {
  return sbp_multipart_string_space_remaining(
      &msg->setting, SBP_MSG_SETTINGS_WRITE_RESP_SETTING_MAX);
}
size_t sbp_msg_settings_write_resp_setting_count_sections(
    const sbp_msg_settings_write_resp_t *msg) {
  return sbp_multipart_string_count_sections(
      &msg->setting, SBP_MSG_SETTINGS_WRITE_RESP_SETTING_MAX);
}

bool sbp_msg_settings_write_resp_setting_add_section(
    sbp_msg_settings_write_resp_t *msg, const char *new_str) {
  return sbp_multipart_string_add_section(
      &msg->setting, SBP_MSG_SETTINGS_WRITE_RESP_SETTING_MAX, new_str);
}

bool sbp_msg_settings_write_resp_setting_add_section_printf(
    sbp_msg_settings_write_resp_t *msg, const char *fmt, ...) {
  va_list ap;
  va_start(ap, fmt);
  bool ret = sbp_multipart_string_add_section_vprintf(
      &msg->setting, SBP_MSG_SETTINGS_WRITE_RESP_SETTING_MAX, fmt, ap);
  va_end(ap);
  return ret;
}

bool sbp_msg_settings_write_resp_setting_add_section_vprintf(
    sbp_msg_settings_write_resp_t *msg, const char *fmt, va_list ap) {
  return sbp_multipart_string_add_section_vprintf(
      &msg->setting, SBP_MSG_SETTINGS_WRITE_RESP_SETTING_MAX, fmt, ap);
}

bool sbp_msg_settings_write_resp_setting_append(
    sbp_msg_settings_write_resp_t *msg, const char *str) {
  return sbp_multipart_string_append(
      &msg->setting, SBP_MSG_SETTINGS_WRITE_RESP_SETTING_MAX, str);
}

bool sbp_msg_settings_write_resp_setting_append_printf(
    sbp_msg_settings_write_resp_t *msg, const char *fmt, ...) {
  va_list ap;
  va_start(ap, fmt);
  bool ret = sbp_multipart_string_append_vprintf(
      &msg->setting, SBP_MSG_SETTINGS_WRITE_RESP_SETTING_MAX, fmt, ap);
  va_end(ap);
  return ret;
}

bool sbp_msg_settings_write_resp_setting_append_vprintf(
    sbp_msg_settings_write_resp_t *msg, const char *fmt, va_list ap) {
  return sbp_multipart_string_append_vprintf(
      &msg->setting, SBP_MSG_SETTINGS_WRITE_RESP_SETTING_MAX, fmt, ap);
}

const char *sbp_msg_settings_write_resp_setting_get_section(
    const sbp_msg_settings_write_resp_t *msg, size_t section) {
  return sbp_multipart_string_get_section(
      &msg->setting, SBP_MSG_SETTINGS_WRITE_RESP_SETTING_MAX, section);
}

size_t sbp_msg_settings_write_resp_setting_section_strlen(
    const sbp_msg_settings_write_resp_t *msg, size_t section) {
  return sbp_multipart_string_section_strlen(
      &msg->setting, SBP_MSG_SETTINGS_WRITE_RESP_SETTING_MAX, section);
}

bool sbp_msg_settings_write_resp_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_settings_write_resp_t *msg) {
  if (!sbp_u8_encode(ctx, &msg->status)) {
    return false;
  }
  if (!sbp_multipart_string_encode(
          &msg->setting, SBP_MSG_SETTINGS_WRITE_RESP_SETTING_MAX, ctx)) {
    return false;
  }
  return true;
}

s8 sbp_msg_settings_write_resp_encode(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_msg_settings_write_resp_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_settings_write_resp_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_settings_write_resp_decode_internal(
    sbp_decode_ctx_t *ctx, sbp_msg_settings_write_resp_t *msg) {
  if (!sbp_u8_decode(ctx, &msg->status)) {
    return false;
  }
  if (!sbp_multipart_string_decode(
          &msg->setting, SBP_MSG_SETTINGS_WRITE_RESP_SETTING_MAX, ctx)) {
    return false;
  }
  return true;
}

s8 sbp_msg_settings_write_resp_decode(const uint8_t *buf, uint8_t len,
                                      uint8_t *n_read,
                                      sbp_msg_settings_write_resp_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_settings_write_resp_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_settings_write_resp_send(sbp_state_t *s, u16 sender_id,
                                    const sbp_msg_settings_write_resp_t *msg,
                                    sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_msg_settings_write_resp_encode(payload, sizeof(payload),
                                              &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_SETTINGS_WRITE_RESP, sender_id,
                          payload_len, payload, write);
}

int sbp_msg_settings_write_resp_cmp(const sbp_msg_settings_write_resp_t *a,
                                    const sbp_msg_settings_write_resp_t *b) {
  int ret = 0;

  ret = sbp_u8_cmp(&a->status, &b->status);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_msg_settings_write_resp_setting_strcmp(a, b);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

void sbp_msg_settings_read_req_setting_init(sbp_msg_settings_read_req_t *msg) {
  sbp_multipart_string_init(&msg->setting);
}

bool sbp_msg_settings_read_req_setting_valid(
    const sbp_msg_settings_read_req_t *msg) {
  return sbp_multipart_string_valid(&msg->setting,
                                    SBP_MSG_SETTINGS_READ_REQ_SETTING_MAX);
}

int sbp_msg_settings_read_req_setting_strcmp(
    const sbp_msg_settings_read_req_t *a,
    const sbp_msg_settings_read_req_t *b) {
  return sbp_multipart_string_strcmp(&a->setting, &b->setting,
                                     SBP_MSG_SETTINGS_READ_REQ_SETTING_MAX);
}

size_t sbp_msg_settings_read_req_setting_encoded_len(
    const sbp_msg_settings_read_req_t *msg) {
  return sbp_multipart_string_encoded_len(
      &msg->setting, SBP_MSG_SETTINGS_READ_REQ_SETTING_MAX);
}

size_t sbp_msg_settings_read_req_setting_space_remaining(
    const sbp_msg_settings_read_req_t *msg) {
  return sbp_multipart_string_space_remaining(
      &msg->setting, SBP_MSG_SETTINGS_READ_REQ_SETTING_MAX);
}
size_t sbp_msg_settings_read_req_setting_count_sections(
    const sbp_msg_settings_read_req_t *msg) {
  return sbp_multipart_string_count_sections(
      &msg->setting, SBP_MSG_SETTINGS_READ_REQ_SETTING_MAX);
}

bool sbp_msg_settings_read_req_setting_add_section(
    sbp_msg_settings_read_req_t *msg, const char *new_str) {
  return sbp_multipart_string_add_section(
      &msg->setting, SBP_MSG_SETTINGS_READ_REQ_SETTING_MAX, new_str);
}

bool sbp_msg_settings_read_req_setting_add_section_printf(
    sbp_msg_settings_read_req_t *msg, const char *fmt, ...) {
  va_list ap;
  va_start(ap, fmt);
  bool ret = sbp_multipart_string_add_section_vprintf(
      &msg->setting, SBP_MSG_SETTINGS_READ_REQ_SETTING_MAX, fmt, ap);
  va_end(ap);
  return ret;
}

bool sbp_msg_settings_read_req_setting_add_section_vprintf(
    sbp_msg_settings_read_req_t *msg, const char *fmt, va_list ap) {
  return sbp_multipart_string_add_section_vprintf(
      &msg->setting, SBP_MSG_SETTINGS_READ_REQ_SETTING_MAX, fmt, ap);
}

bool sbp_msg_settings_read_req_setting_append(sbp_msg_settings_read_req_t *msg,
                                              const char *str) {
  return sbp_multipart_string_append(
      &msg->setting, SBP_MSG_SETTINGS_READ_REQ_SETTING_MAX, str);
}

bool sbp_msg_settings_read_req_setting_append_printf(
    sbp_msg_settings_read_req_t *msg, const char *fmt, ...) {
  va_list ap;
  va_start(ap, fmt);
  bool ret = sbp_multipart_string_append_vprintf(
      &msg->setting, SBP_MSG_SETTINGS_READ_REQ_SETTING_MAX, fmt, ap);
  va_end(ap);
  return ret;
}

bool sbp_msg_settings_read_req_setting_append_vprintf(
    sbp_msg_settings_read_req_t *msg, const char *fmt, va_list ap) {
  return sbp_multipart_string_append_vprintf(
      &msg->setting, SBP_MSG_SETTINGS_READ_REQ_SETTING_MAX, fmt, ap);
}

const char *sbp_msg_settings_read_req_setting_get_section(
    const sbp_msg_settings_read_req_t *msg, size_t section) {
  return sbp_multipart_string_get_section(
      &msg->setting, SBP_MSG_SETTINGS_READ_REQ_SETTING_MAX, section);
}

size_t sbp_msg_settings_read_req_setting_section_strlen(
    const sbp_msg_settings_read_req_t *msg, size_t section) {
  return sbp_multipart_string_section_strlen(
      &msg->setting, SBP_MSG_SETTINGS_READ_REQ_SETTING_MAX, section);
}

bool sbp_msg_settings_read_req_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_settings_read_req_t *msg) {
  if (!sbp_multipart_string_encode(
          &msg->setting, SBP_MSG_SETTINGS_READ_REQ_SETTING_MAX, ctx)) {
    return false;
  }
  return true;
}

s8 sbp_msg_settings_read_req_encode(uint8_t *buf, uint8_t len,
                                    uint8_t *n_written,
                                    const sbp_msg_settings_read_req_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_settings_read_req_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_settings_read_req_decode_internal(
    sbp_decode_ctx_t *ctx, sbp_msg_settings_read_req_t *msg) {
  if (!sbp_multipart_string_decode(
          &msg->setting, SBP_MSG_SETTINGS_READ_REQ_SETTING_MAX, ctx)) {
    return false;
  }
  return true;
}

s8 sbp_msg_settings_read_req_decode(const uint8_t *buf, uint8_t len,
                                    uint8_t *n_read,
                                    sbp_msg_settings_read_req_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_settings_read_req_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_settings_read_req_send(sbp_state_t *s, u16 sender_id,
                                  const sbp_msg_settings_read_req_t *msg,
                                  sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_msg_settings_read_req_encode(payload, sizeof(payload),
                                            &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_SETTINGS_READ_REQ, sender_id, payload_len,
                          payload, write);
}

int sbp_msg_settings_read_req_cmp(const sbp_msg_settings_read_req_t *a,
                                  const sbp_msg_settings_read_req_t *b) {
  int ret = 0;

  ret = sbp_msg_settings_read_req_setting_strcmp(a, b);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

void sbp_msg_settings_read_resp_setting_init(
    sbp_msg_settings_read_resp_t *msg) {
  sbp_multipart_string_init(&msg->setting);
}

bool sbp_msg_settings_read_resp_setting_valid(
    const sbp_msg_settings_read_resp_t *msg) {
  return sbp_multipart_string_valid(&msg->setting,
                                    SBP_MSG_SETTINGS_READ_RESP_SETTING_MAX);
}

int sbp_msg_settings_read_resp_setting_strcmp(
    const sbp_msg_settings_read_resp_t *a,
    const sbp_msg_settings_read_resp_t *b) {
  return sbp_multipart_string_strcmp(&a->setting, &b->setting,
                                     SBP_MSG_SETTINGS_READ_RESP_SETTING_MAX);
}

size_t sbp_msg_settings_read_resp_setting_encoded_len(
    const sbp_msg_settings_read_resp_t *msg) {
  return sbp_multipart_string_encoded_len(
      &msg->setting, SBP_MSG_SETTINGS_READ_RESP_SETTING_MAX);
}

size_t sbp_msg_settings_read_resp_setting_space_remaining(
    const sbp_msg_settings_read_resp_t *msg) {
  return sbp_multipart_string_space_remaining(
      &msg->setting, SBP_MSG_SETTINGS_READ_RESP_SETTING_MAX);
}
size_t sbp_msg_settings_read_resp_setting_count_sections(
    const sbp_msg_settings_read_resp_t *msg) {
  return sbp_multipart_string_count_sections(
      &msg->setting, SBP_MSG_SETTINGS_READ_RESP_SETTING_MAX);
}

bool sbp_msg_settings_read_resp_setting_add_section(
    sbp_msg_settings_read_resp_t *msg, const char *new_str) {
  return sbp_multipart_string_add_section(
      &msg->setting, SBP_MSG_SETTINGS_READ_RESP_SETTING_MAX, new_str);
}

bool sbp_msg_settings_read_resp_setting_add_section_printf(
    sbp_msg_settings_read_resp_t *msg, const char *fmt, ...) {
  va_list ap;
  va_start(ap, fmt);
  bool ret = sbp_multipart_string_add_section_vprintf(
      &msg->setting, SBP_MSG_SETTINGS_READ_RESP_SETTING_MAX, fmt, ap);
  va_end(ap);
  return ret;
}

bool sbp_msg_settings_read_resp_setting_add_section_vprintf(
    sbp_msg_settings_read_resp_t *msg, const char *fmt, va_list ap) {
  return sbp_multipart_string_add_section_vprintf(
      &msg->setting, SBP_MSG_SETTINGS_READ_RESP_SETTING_MAX, fmt, ap);
}

bool sbp_msg_settings_read_resp_setting_append(
    sbp_msg_settings_read_resp_t *msg, const char *str) {
  return sbp_multipart_string_append(
      &msg->setting, SBP_MSG_SETTINGS_READ_RESP_SETTING_MAX, str);
}

bool sbp_msg_settings_read_resp_setting_append_printf(
    sbp_msg_settings_read_resp_t *msg, const char *fmt, ...) {
  va_list ap;
  va_start(ap, fmt);
  bool ret = sbp_multipart_string_append_vprintf(
      &msg->setting, SBP_MSG_SETTINGS_READ_RESP_SETTING_MAX, fmt, ap);
  va_end(ap);
  return ret;
}

bool sbp_msg_settings_read_resp_setting_append_vprintf(
    sbp_msg_settings_read_resp_t *msg, const char *fmt, va_list ap) {
  return sbp_multipart_string_append_vprintf(
      &msg->setting, SBP_MSG_SETTINGS_READ_RESP_SETTING_MAX, fmt, ap);
}

const char *sbp_msg_settings_read_resp_setting_get_section(
    const sbp_msg_settings_read_resp_t *msg, size_t section) {
  return sbp_multipart_string_get_section(
      &msg->setting, SBP_MSG_SETTINGS_READ_RESP_SETTING_MAX, section);
}

size_t sbp_msg_settings_read_resp_setting_section_strlen(
    const sbp_msg_settings_read_resp_t *msg, size_t section) {
  return sbp_multipart_string_section_strlen(
      &msg->setting, SBP_MSG_SETTINGS_READ_RESP_SETTING_MAX, section);
}

bool sbp_msg_settings_read_resp_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_settings_read_resp_t *msg) {
  if (!sbp_multipart_string_encode(
          &msg->setting, SBP_MSG_SETTINGS_READ_RESP_SETTING_MAX, ctx)) {
    return false;
  }
  return true;
}

s8 sbp_msg_settings_read_resp_encode(uint8_t *buf, uint8_t len,
                                     uint8_t *n_written,
                                     const sbp_msg_settings_read_resp_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_settings_read_resp_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_settings_read_resp_decode_internal(
    sbp_decode_ctx_t *ctx, sbp_msg_settings_read_resp_t *msg) {
  if (!sbp_multipart_string_decode(
          &msg->setting, SBP_MSG_SETTINGS_READ_RESP_SETTING_MAX, ctx)) {
    return false;
  }
  return true;
}

s8 sbp_msg_settings_read_resp_decode(const uint8_t *buf, uint8_t len,
                                     uint8_t *n_read,
                                     sbp_msg_settings_read_resp_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_settings_read_resp_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_settings_read_resp_send(sbp_state_t *s, u16 sender_id,
                                   const sbp_msg_settings_read_resp_t *msg,
                                   sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_msg_settings_read_resp_encode(payload, sizeof(payload),
                                             &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_SETTINGS_READ_RESP, sender_id, payload_len,
                          payload, write);
}

int sbp_msg_settings_read_resp_cmp(const sbp_msg_settings_read_resp_t *a,
                                   const sbp_msg_settings_read_resp_t *b) {
  int ret = 0;

  ret = sbp_msg_settings_read_resp_setting_strcmp(a, b);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

bool sbp_msg_settings_read_by_index_req_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_settings_read_by_index_req_t *msg) {
  if (!sbp_u16_encode(ctx, &msg->index)) {
    return false;
  }
  return true;
}

s8 sbp_msg_settings_read_by_index_req_encode(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_msg_settings_read_by_index_req_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_settings_read_by_index_req_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_settings_read_by_index_req_decode_internal(
    sbp_decode_ctx_t *ctx, sbp_msg_settings_read_by_index_req_t *msg) {
  if (!sbp_u16_decode(ctx, &msg->index)) {
    return false;
  }
  return true;
}

s8 sbp_msg_settings_read_by_index_req_decode(
    const uint8_t *buf, uint8_t len, uint8_t *n_read,
    sbp_msg_settings_read_by_index_req_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_settings_read_by_index_req_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_settings_read_by_index_req_send(
    sbp_state_t *s, u16 sender_id,
    const sbp_msg_settings_read_by_index_req_t *msg, sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_msg_settings_read_by_index_req_encode(payload, sizeof(payload),
                                                     &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_SETTINGS_READ_BY_INDEX_REQ, sender_id,
                          payload_len, payload, write);
}

int sbp_msg_settings_read_by_index_req_cmp(
    const sbp_msg_settings_read_by_index_req_t *a,
    const sbp_msg_settings_read_by_index_req_t *b) {
  int ret = 0;

  ret = sbp_u16_cmp(&a->index, &b->index);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

void sbp_msg_settings_read_by_index_resp_setting_init(
    sbp_msg_settings_read_by_index_resp_t *msg) {
  sbp_multipart_string_init(&msg->setting);
}

bool sbp_msg_settings_read_by_index_resp_setting_valid(
    const sbp_msg_settings_read_by_index_resp_t *msg) {
  return sbp_multipart_string_valid(
      &msg->setting, SBP_MSG_SETTINGS_READ_BY_INDEX_RESP_SETTING_MAX);
}

int sbp_msg_settings_read_by_index_resp_setting_strcmp(
    const sbp_msg_settings_read_by_index_resp_t *a,
    const sbp_msg_settings_read_by_index_resp_t *b) {
  return sbp_multipart_string_strcmp(
      &a->setting, &b->setting,
      SBP_MSG_SETTINGS_READ_BY_INDEX_RESP_SETTING_MAX);
}

size_t sbp_msg_settings_read_by_index_resp_setting_encoded_len(
    const sbp_msg_settings_read_by_index_resp_t *msg) {
  return sbp_multipart_string_encoded_len(
      &msg->setting, SBP_MSG_SETTINGS_READ_BY_INDEX_RESP_SETTING_MAX);
}

size_t sbp_msg_settings_read_by_index_resp_setting_space_remaining(
    const sbp_msg_settings_read_by_index_resp_t *msg) {
  return sbp_multipart_string_space_remaining(
      &msg->setting, SBP_MSG_SETTINGS_READ_BY_INDEX_RESP_SETTING_MAX);
}
size_t sbp_msg_settings_read_by_index_resp_setting_count_sections(
    const sbp_msg_settings_read_by_index_resp_t *msg) {
  return sbp_multipart_string_count_sections(
      &msg->setting, SBP_MSG_SETTINGS_READ_BY_INDEX_RESP_SETTING_MAX);
}

bool sbp_msg_settings_read_by_index_resp_setting_add_section(
    sbp_msg_settings_read_by_index_resp_t *msg, const char *new_str) {
  return sbp_multipart_string_add_section(
      &msg->setting, SBP_MSG_SETTINGS_READ_BY_INDEX_RESP_SETTING_MAX, new_str);
}

bool sbp_msg_settings_read_by_index_resp_setting_add_section_printf(
    sbp_msg_settings_read_by_index_resp_t *msg, const char *fmt, ...) {
  va_list ap;
  va_start(ap, fmt);
  bool ret = sbp_multipart_string_add_section_vprintf(
      &msg->setting, SBP_MSG_SETTINGS_READ_BY_INDEX_RESP_SETTING_MAX, fmt, ap);
  va_end(ap);
  return ret;
}

bool sbp_msg_settings_read_by_index_resp_setting_add_section_vprintf(
    sbp_msg_settings_read_by_index_resp_t *msg, const char *fmt, va_list ap) {
  return sbp_multipart_string_add_section_vprintf(
      &msg->setting, SBP_MSG_SETTINGS_READ_BY_INDEX_RESP_SETTING_MAX, fmt, ap);
}

bool sbp_msg_settings_read_by_index_resp_setting_append(
    sbp_msg_settings_read_by_index_resp_t *msg, const char *str) {
  return sbp_multipart_string_append(
      &msg->setting, SBP_MSG_SETTINGS_READ_BY_INDEX_RESP_SETTING_MAX, str);
}

bool sbp_msg_settings_read_by_index_resp_setting_append_printf(
    sbp_msg_settings_read_by_index_resp_t *msg, const char *fmt, ...) {
  va_list ap;
  va_start(ap, fmt);
  bool ret = sbp_multipart_string_append_vprintf(
      &msg->setting, SBP_MSG_SETTINGS_READ_BY_INDEX_RESP_SETTING_MAX, fmt, ap);
  va_end(ap);
  return ret;
}

bool sbp_msg_settings_read_by_index_resp_setting_append_vprintf(
    sbp_msg_settings_read_by_index_resp_t *msg, const char *fmt, va_list ap) {
  return sbp_multipart_string_append_vprintf(
      &msg->setting, SBP_MSG_SETTINGS_READ_BY_INDEX_RESP_SETTING_MAX, fmt, ap);
}

const char *sbp_msg_settings_read_by_index_resp_setting_get_section(
    const sbp_msg_settings_read_by_index_resp_t *msg, size_t section) {
  return sbp_multipart_string_get_section(
      &msg->setting, SBP_MSG_SETTINGS_READ_BY_INDEX_RESP_SETTING_MAX, section);
}

size_t sbp_msg_settings_read_by_index_resp_setting_section_strlen(
    const sbp_msg_settings_read_by_index_resp_t *msg, size_t section) {
  return sbp_multipart_string_section_strlen(
      &msg->setting, SBP_MSG_SETTINGS_READ_BY_INDEX_RESP_SETTING_MAX, section);
}

bool sbp_msg_settings_read_by_index_resp_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_settings_read_by_index_resp_t *msg) {
  if (!sbp_u16_encode(ctx, &msg->index)) {
    return false;
  }
  if (!sbp_multipart_string_encode(
          &msg->setting, SBP_MSG_SETTINGS_READ_BY_INDEX_RESP_SETTING_MAX,
          ctx)) {
    return false;
  }
  return true;
}

s8 sbp_msg_settings_read_by_index_resp_encode(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_msg_settings_read_by_index_resp_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_settings_read_by_index_resp_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_settings_read_by_index_resp_decode_internal(
    sbp_decode_ctx_t *ctx, sbp_msg_settings_read_by_index_resp_t *msg) {
  if (!sbp_u16_decode(ctx, &msg->index)) {
    return false;
  }
  if (!sbp_multipart_string_decode(
          &msg->setting, SBP_MSG_SETTINGS_READ_BY_INDEX_RESP_SETTING_MAX,
          ctx)) {
    return false;
  }
  return true;
}

s8 sbp_msg_settings_read_by_index_resp_decode(
    const uint8_t *buf, uint8_t len, uint8_t *n_read,
    sbp_msg_settings_read_by_index_resp_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_settings_read_by_index_resp_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_settings_read_by_index_resp_send(
    sbp_state_t *s, u16 sender_id,
    const sbp_msg_settings_read_by_index_resp_t *msg, sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_msg_settings_read_by_index_resp_encode(payload, sizeof(payload),
                                                      &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_SETTINGS_READ_BY_INDEX_RESP, sender_id,
                          payload_len, payload, write);
}

int sbp_msg_settings_read_by_index_resp_cmp(
    const sbp_msg_settings_read_by_index_resp_t *a,
    const sbp_msg_settings_read_by_index_resp_t *b) {
  int ret = 0;

  ret = sbp_u16_cmp(&a->index, &b->index);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_msg_settings_read_by_index_resp_setting_strcmp(a, b);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

bool sbp_msg_settings_read_by_index_done_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_settings_read_by_index_done_t *msg) {
  (void)ctx;
  (void)msg;
  return true;
}

s8 sbp_msg_settings_read_by_index_done_encode(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_msg_settings_read_by_index_done_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_settings_read_by_index_done_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_settings_read_by_index_done_decode_internal(
    sbp_decode_ctx_t *ctx, sbp_msg_settings_read_by_index_done_t *msg) {
  (void)ctx;
  (void)msg;
  return true;
}

s8 sbp_msg_settings_read_by_index_done_decode(
    const uint8_t *buf, uint8_t len, uint8_t *n_read,
    sbp_msg_settings_read_by_index_done_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_settings_read_by_index_done_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_settings_read_by_index_done_send(
    sbp_state_t *s, u16 sender_id,
    const sbp_msg_settings_read_by_index_done_t *msg, sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_msg_settings_read_by_index_done_encode(payload, sizeof(payload),
                                                      &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_SETTINGS_READ_BY_INDEX_DONE, sender_id,
                          payload_len, payload, write);
}

int sbp_msg_settings_read_by_index_done_cmp(
    const sbp_msg_settings_read_by_index_done_t *a,
    const sbp_msg_settings_read_by_index_done_t *b) {
  (void)a;
  (void)b;
  int ret = 0;
  return ret;
}

void sbp_msg_settings_register_setting_init(sbp_msg_settings_register_t *msg) {
  sbp_multipart_string_init(&msg->setting);
}

bool sbp_msg_settings_register_setting_valid(
    const sbp_msg_settings_register_t *msg) {
  return sbp_multipart_string_valid(&msg->setting,
                                    SBP_MSG_SETTINGS_REGISTER_SETTING_MAX);
}

int sbp_msg_settings_register_setting_strcmp(
    const sbp_msg_settings_register_t *a,
    const sbp_msg_settings_register_t *b) {
  return sbp_multipart_string_strcmp(&a->setting, &b->setting,
                                     SBP_MSG_SETTINGS_REGISTER_SETTING_MAX);
}

size_t sbp_msg_settings_register_setting_encoded_len(
    const sbp_msg_settings_register_t *msg) {
  return sbp_multipart_string_encoded_len(
      &msg->setting, SBP_MSG_SETTINGS_REGISTER_SETTING_MAX);
}

size_t sbp_msg_settings_register_setting_space_remaining(
    const sbp_msg_settings_register_t *msg) {
  return sbp_multipart_string_space_remaining(
      &msg->setting, SBP_MSG_SETTINGS_REGISTER_SETTING_MAX);
}
size_t sbp_msg_settings_register_setting_count_sections(
    const sbp_msg_settings_register_t *msg) {
  return sbp_multipart_string_count_sections(
      &msg->setting, SBP_MSG_SETTINGS_REGISTER_SETTING_MAX);
}

bool sbp_msg_settings_register_setting_add_section(
    sbp_msg_settings_register_t *msg, const char *new_str) {
  return sbp_multipart_string_add_section(
      &msg->setting, SBP_MSG_SETTINGS_REGISTER_SETTING_MAX, new_str);
}

bool sbp_msg_settings_register_setting_add_section_printf(
    sbp_msg_settings_register_t *msg, const char *fmt, ...) {
  va_list ap;
  va_start(ap, fmt);
  bool ret = sbp_multipart_string_add_section_vprintf(
      &msg->setting, SBP_MSG_SETTINGS_REGISTER_SETTING_MAX, fmt, ap);
  va_end(ap);
  return ret;
}

bool sbp_msg_settings_register_setting_add_section_vprintf(
    sbp_msg_settings_register_t *msg, const char *fmt, va_list ap) {
  return sbp_multipart_string_add_section_vprintf(
      &msg->setting, SBP_MSG_SETTINGS_REGISTER_SETTING_MAX, fmt, ap);
}

bool sbp_msg_settings_register_setting_append(sbp_msg_settings_register_t *msg,
                                              const char *str) {
  return sbp_multipart_string_append(
      &msg->setting, SBP_MSG_SETTINGS_REGISTER_SETTING_MAX, str);
}

bool sbp_msg_settings_register_setting_append_printf(
    sbp_msg_settings_register_t *msg, const char *fmt, ...) {
  va_list ap;
  va_start(ap, fmt);
  bool ret = sbp_multipart_string_append_vprintf(
      &msg->setting, SBP_MSG_SETTINGS_REGISTER_SETTING_MAX, fmt, ap);
  va_end(ap);
  return ret;
}

bool sbp_msg_settings_register_setting_append_vprintf(
    sbp_msg_settings_register_t *msg, const char *fmt, va_list ap) {
  return sbp_multipart_string_append_vprintf(
      &msg->setting, SBP_MSG_SETTINGS_REGISTER_SETTING_MAX, fmt, ap);
}

const char *sbp_msg_settings_register_setting_get_section(
    const sbp_msg_settings_register_t *msg, size_t section) {
  return sbp_multipart_string_get_section(
      &msg->setting, SBP_MSG_SETTINGS_REGISTER_SETTING_MAX, section);
}

size_t sbp_msg_settings_register_setting_section_strlen(
    const sbp_msg_settings_register_t *msg, size_t section) {
  return sbp_multipart_string_section_strlen(
      &msg->setting, SBP_MSG_SETTINGS_REGISTER_SETTING_MAX, section);
}

bool sbp_msg_settings_register_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_settings_register_t *msg) {
  if (!sbp_multipart_string_encode(
          &msg->setting, SBP_MSG_SETTINGS_REGISTER_SETTING_MAX, ctx)) {
    return false;
  }
  return true;
}

s8 sbp_msg_settings_register_encode(uint8_t *buf, uint8_t len,
                                    uint8_t *n_written,
                                    const sbp_msg_settings_register_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_settings_register_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_settings_register_decode_internal(
    sbp_decode_ctx_t *ctx, sbp_msg_settings_register_t *msg) {
  if (!sbp_multipart_string_decode(
          &msg->setting, SBP_MSG_SETTINGS_REGISTER_SETTING_MAX, ctx)) {
    return false;
  }
  return true;
}

s8 sbp_msg_settings_register_decode(const uint8_t *buf, uint8_t len,
                                    uint8_t *n_read,
                                    sbp_msg_settings_register_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_settings_register_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_settings_register_send(sbp_state_t *s, u16 sender_id,
                                  const sbp_msg_settings_register_t *msg,
                                  sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_msg_settings_register_encode(payload, sizeof(payload),
                                            &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_SETTINGS_REGISTER, sender_id, payload_len,
                          payload, write);
}

int sbp_msg_settings_register_cmp(const sbp_msg_settings_register_t *a,
                                  const sbp_msg_settings_register_t *b) {
  int ret = 0;

  ret = sbp_msg_settings_register_setting_strcmp(a, b);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

void sbp_msg_settings_register_resp_setting_init(
    sbp_msg_settings_register_resp_t *msg) {
  sbp_multipart_string_init(&msg->setting);
}

bool sbp_msg_settings_register_resp_setting_valid(
    const sbp_msg_settings_register_resp_t *msg) {
  return sbp_multipart_string_valid(&msg->setting,
                                    SBP_MSG_SETTINGS_REGISTER_RESP_SETTING_MAX);
}

int sbp_msg_settings_register_resp_setting_strcmp(
    const sbp_msg_settings_register_resp_t *a,
    const sbp_msg_settings_register_resp_t *b) {
  return sbp_multipart_string_strcmp(
      &a->setting, &b->setting, SBP_MSG_SETTINGS_REGISTER_RESP_SETTING_MAX);
}

size_t sbp_msg_settings_register_resp_setting_encoded_len(
    const sbp_msg_settings_register_resp_t *msg) {
  return sbp_multipart_string_encoded_len(
      &msg->setting, SBP_MSG_SETTINGS_REGISTER_RESP_SETTING_MAX);
}

size_t sbp_msg_settings_register_resp_setting_space_remaining(
    const sbp_msg_settings_register_resp_t *msg) {
  return sbp_multipart_string_space_remaining(
      &msg->setting, SBP_MSG_SETTINGS_REGISTER_RESP_SETTING_MAX);
}
size_t sbp_msg_settings_register_resp_setting_count_sections(
    const sbp_msg_settings_register_resp_t *msg) {
  return sbp_multipart_string_count_sections(
      &msg->setting, SBP_MSG_SETTINGS_REGISTER_RESP_SETTING_MAX);
}

bool sbp_msg_settings_register_resp_setting_add_section(
    sbp_msg_settings_register_resp_t *msg, const char *new_str) {
  return sbp_multipart_string_add_section(
      &msg->setting, SBP_MSG_SETTINGS_REGISTER_RESP_SETTING_MAX, new_str);
}

bool sbp_msg_settings_register_resp_setting_add_section_printf(
    sbp_msg_settings_register_resp_t *msg, const char *fmt, ...) {
  va_list ap;
  va_start(ap, fmt);
  bool ret = sbp_multipart_string_add_section_vprintf(
      &msg->setting, SBP_MSG_SETTINGS_REGISTER_RESP_SETTING_MAX, fmt, ap);
  va_end(ap);
  return ret;
}

bool sbp_msg_settings_register_resp_setting_add_section_vprintf(
    sbp_msg_settings_register_resp_t *msg, const char *fmt, va_list ap) {
  return sbp_multipart_string_add_section_vprintf(
      &msg->setting, SBP_MSG_SETTINGS_REGISTER_RESP_SETTING_MAX, fmt, ap);
}

bool sbp_msg_settings_register_resp_setting_append(
    sbp_msg_settings_register_resp_t *msg, const char *str) {
  return sbp_multipart_string_append(
      &msg->setting, SBP_MSG_SETTINGS_REGISTER_RESP_SETTING_MAX, str);
}

bool sbp_msg_settings_register_resp_setting_append_printf(
    sbp_msg_settings_register_resp_t *msg, const char *fmt, ...) {
  va_list ap;
  va_start(ap, fmt);
  bool ret = sbp_multipart_string_append_vprintf(
      &msg->setting, SBP_MSG_SETTINGS_REGISTER_RESP_SETTING_MAX, fmt, ap);
  va_end(ap);
  return ret;
}

bool sbp_msg_settings_register_resp_setting_append_vprintf(
    sbp_msg_settings_register_resp_t *msg, const char *fmt, va_list ap) {
  return sbp_multipart_string_append_vprintf(
      &msg->setting, SBP_MSG_SETTINGS_REGISTER_RESP_SETTING_MAX, fmt, ap);
}

const char *sbp_msg_settings_register_resp_setting_get_section(
    const sbp_msg_settings_register_resp_t *msg, size_t section) {
  return sbp_multipart_string_get_section(
      &msg->setting, SBP_MSG_SETTINGS_REGISTER_RESP_SETTING_MAX, section);
}

size_t sbp_msg_settings_register_resp_setting_section_strlen(
    const sbp_msg_settings_register_resp_t *msg, size_t section) {
  return sbp_multipart_string_section_strlen(
      &msg->setting, SBP_MSG_SETTINGS_REGISTER_RESP_SETTING_MAX, section);
}

bool sbp_msg_settings_register_resp_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_settings_register_resp_t *msg) {
  if (!sbp_u8_encode(ctx, &msg->status)) {
    return false;
  }
  if (!sbp_multipart_string_encode(
          &msg->setting, SBP_MSG_SETTINGS_REGISTER_RESP_SETTING_MAX, ctx)) {
    return false;
  }
  return true;
}

s8 sbp_msg_settings_register_resp_encode(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_msg_settings_register_resp_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_settings_register_resp_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_settings_register_resp_decode_internal(
    sbp_decode_ctx_t *ctx, sbp_msg_settings_register_resp_t *msg) {
  if (!sbp_u8_decode(ctx, &msg->status)) {
    return false;
  }
  if (!sbp_multipart_string_decode(
          &msg->setting, SBP_MSG_SETTINGS_REGISTER_RESP_SETTING_MAX, ctx)) {
    return false;
  }
  return true;
}

s8 sbp_msg_settings_register_resp_decode(
    const uint8_t *buf, uint8_t len, uint8_t *n_read,
    sbp_msg_settings_register_resp_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_settings_register_resp_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_settings_register_resp_send(
    sbp_state_t *s, u16 sender_id, const sbp_msg_settings_register_resp_t *msg,
    sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_msg_settings_register_resp_encode(payload, sizeof(payload),
                                                 &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_SETTINGS_REGISTER_RESP, sender_id,
                          payload_len, payload, write);
}

int sbp_msg_settings_register_resp_cmp(
    const sbp_msg_settings_register_resp_t *a,
    const sbp_msg_settings_register_resp_t *b) {
  int ret = 0;

  ret = sbp_u8_cmp(&a->status, &b->status);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_msg_settings_register_resp_setting_strcmp(a, b);
  if (ret != 0) {
    return ret;
  }
  return ret;
}
