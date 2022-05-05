/*****************************************************************************
 * Automatically generated from yaml/swiftnav/sbp/logging.yaml
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#include <libsbp/internal/v4/common.h>
#include <libsbp/internal/v4/logging.h>
#include <libsbp/internal/v4/string/double_null_terminated.h>
#include <libsbp/internal/v4/string/multipart.h>
#include <libsbp/internal/v4/string/null_terminated.h>
#include <libsbp/internal/v4/string/unterminated.h>
#include <libsbp/sbp.h>
#include <libsbp/v4/logging.h>

void sbp_msg_log_text_init(sbp_msg_log_t *msg) {
  sbp_unterminated_string_init(&msg->text);
}

bool sbp_msg_log_text_valid(const sbp_msg_log_t *msg) {
  return sbp_unterminated_string_valid(&msg->text, SBP_MSG_LOG_TEXT_MAX);
}

int sbp_msg_log_text_strcmp(const sbp_msg_log_t *a, const sbp_msg_log_t *b) {
  return sbp_unterminated_string_strcmp(&a->text, &b->text,
                                        SBP_MSG_LOG_TEXT_MAX);
}

size_t sbp_msg_log_text_encoded_len(const sbp_msg_log_t *msg) {
  return sbp_unterminated_string_encoded_len(&msg->text, SBP_MSG_LOG_TEXT_MAX);
}

size_t sbp_msg_log_text_space_remaining(const sbp_msg_log_t *msg) {
  return sbp_unterminated_string_space_remaining(&msg->text,
                                                 SBP_MSG_LOG_TEXT_MAX);
}
bool sbp_msg_log_text_set(sbp_msg_log_t *msg, const char *new_str,
                          bool should_trunc, size_t *n_written) {
  return sbp_unterminated_string_set(&msg->text, SBP_MSG_LOG_TEXT_MAX,
                                     should_trunc, n_written, new_str);
}

bool sbp_msg_log_text_set_raw(sbp_msg_log_t *msg, const char *new_buf,
                              size_t new_buf_len, bool should_trunc,
                              size_t *n_written) {
  return sbp_unterminated_string_set_raw(&msg->text, SBP_MSG_LOG_TEXT_MAX,
                                         should_trunc, n_written, new_buf,
                                         new_buf_len);
}

bool sbp_msg_log_text_printf(sbp_msg_log_t *msg, bool should_trunc,
                             size_t *n_written, const char *fmt, ...) {
  va_list ap;
  va_start(ap, fmt);
  bool ret = sbp_unterminated_string_vprintf(&msg->text, SBP_MSG_LOG_TEXT_MAX,
                                             should_trunc, n_written, fmt, ap);
  va_end(ap);
  return ret;
}

bool sbp_msg_log_text_vprintf(sbp_msg_log_t *msg, bool should_trunc,
                              size_t *n_written, const char *fmt, va_list ap) {
  return sbp_unterminated_string_vprintf(&msg->text, SBP_MSG_LOG_TEXT_MAX,
                                         should_trunc, n_written, fmt, ap);
}

bool sbp_msg_log_text_append_printf(sbp_msg_log_t *msg, bool should_trunc,
                                    size_t *n_written, const char *fmt, ...) {
  va_list ap;
  va_start(ap, fmt);
  bool ret = sbp_unterminated_string_append_vprintf(
      &msg->text, SBP_MSG_LOG_TEXT_MAX, should_trunc, n_written, fmt, ap);
  va_end(ap);
  return ret;
}

bool sbp_msg_log_text_append_vprintf(sbp_msg_log_t *msg, bool should_trunc,
                                     size_t *n_written, const char *fmt,
                                     va_list ap) {
  return sbp_unterminated_string_append_vprintf(
      &msg->text, SBP_MSG_LOG_TEXT_MAX, should_trunc, n_written, fmt, ap);
}

const char *sbp_msg_log_text_get(const sbp_msg_log_t *msg) {
  return sbp_unterminated_string_get(&msg->text, SBP_MSG_LOG_TEXT_MAX);
}

size_t sbp_msg_log_text_strlen(const sbp_msg_log_t *msg) {
  return sbp_unterminated_string_strlen(&msg->text, SBP_MSG_LOG_TEXT_MAX);
}

bool sbp_msg_log_encode_internal(sbp_encode_ctx_t *ctx,
                                 const sbp_msg_log_t *msg) {
  if (!sbp_u8_encode(ctx, &msg->level)) {
    return false;
  }
  if (!sbp_unterminated_string_encode(&msg->text, SBP_MSG_LOG_TEXT_MAX, ctx)) {
    return false;
  }
  return true;
}

s8 sbp_msg_log_encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                      const sbp_msg_log_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_log_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_log_decode_internal(sbp_decode_ctx_t *ctx, sbp_msg_log_t *msg) {
  if (!sbp_u8_decode(ctx, &msg->level)) {
    return false;
  }
  if (!sbp_unterminated_string_decode(&msg->text, SBP_MSG_LOG_TEXT_MAX, ctx)) {
    return false;
  }
  return true;
}

s8 sbp_msg_log_decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                      sbp_msg_log_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_log_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_log_send(sbp_state_t *s, u16 sender_id, const sbp_msg_log_t *msg,
                    sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_msg_log_encode(payload, sizeof(payload), &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_LOG, sender_id, payload_len, payload,
                          write);
}

int sbp_msg_log_cmp(const sbp_msg_log_t *a, const sbp_msg_log_t *b) {
  int ret = 0;

  ret = sbp_u8_cmp(&a->level, &b->level);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_msg_log_text_strcmp(a, b);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

bool sbp_msg_fwd_encode_internal(sbp_encode_ctx_t *ctx,
                                 const sbp_msg_fwd_t *msg) {
  if (!sbp_u8_encode(ctx, &msg->source)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->protocol)) {
    return false;
  }
  for (size_t i = 0; i < msg->n_fwd_payload; i++) {
    if (!sbp_u8_encode(ctx, &msg->fwd_payload[i])) {
      return false;
    }
  }
  return true;
}

s8 sbp_msg_fwd_encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                      const sbp_msg_fwd_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_fwd_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_fwd_decode_internal(sbp_decode_ctx_t *ctx, sbp_msg_fwd_t *msg) {
  if (!sbp_u8_decode(ctx, &msg->source)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->protocol)) {
    return false;
  }
  msg->n_fwd_payload =
      (uint8_t)((ctx->buf_len - ctx->offset) / SBP_ENCODED_LEN_U8);
  for (uint8_t i = 0; i < msg->n_fwd_payload; i++) {
    if (!sbp_u8_decode(ctx, &msg->fwd_payload[i])) {
      return false;
    }
  }
  return true;
}

s8 sbp_msg_fwd_decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                      sbp_msg_fwd_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_fwd_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_fwd_send(sbp_state_t *s, u16 sender_id, const sbp_msg_fwd_t *msg,
                    sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_msg_fwd_encode(payload, sizeof(payload), &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_FWD, sender_id, payload_len, payload,
                          write);
}

int sbp_msg_fwd_cmp(const sbp_msg_fwd_t *a, const sbp_msg_fwd_t *b) {
  int ret = 0;

  ret = sbp_u8_cmp(&a->source, &b->source);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->protocol, &b->protocol);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->n_fwd_payload, &b->n_fwd_payload);
  for (uint8_t i = 0; ret == 0 && i < a->n_fwd_payload; i++) {
    ret = sbp_u8_cmp(&a->fwd_payload[i], &b->fwd_payload[i]);
  }
  if (ret != 0) {
    return ret;
  }
  return ret;
}

void sbp_msg_print_dep_text_init(sbp_msg_print_dep_t *msg) {
  sbp_unterminated_string_init(&msg->text);
}

bool sbp_msg_print_dep_text_valid(const sbp_msg_print_dep_t *msg) {
  return sbp_unterminated_string_valid(&msg->text, SBP_MSG_PRINT_DEP_TEXT_MAX);
}

int sbp_msg_print_dep_text_strcmp(const sbp_msg_print_dep_t *a,
                                  const sbp_msg_print_dep_t *b) {
  return sbp_unterminated_string_strcmp(&a->text, &b->text,
                                        SBP_MSG_PRINT_DEP_TEXT_MAX);
}

size_t sbp_msg_print_dep_text_encoded_len(const sbp_msg_print_dep_t *msg) {
  return sbp_unterminated_string_encoded_len(&msg->text,
                                             SBP_MSG_PRINT_DEP_TEXT_MAX);
}

size_t sbp_msg_print_dep_text_space_remaining(const sbp_msg_print_dep_t *msg) {
  return sbp_unterminated_string_space_remaining(&msg->text,
                                                 SBP_MSG_PRINT_DEP_TEXT_MAX);
}
bool sbp_msg_print_dep_text_set(sbp_msg_print_dep_t *msg, const char *new_str,
                                bool should_trunc, size_t *n_written) {
  return sbp_unterminated_string_set(&msg->text, SBP_MSG_PRINT_DEP_TEXT_MAX,
                                     should_trunc, n_written, new_str);
}

bool sbp_msg_print_dep_text_set_raw(sbp_msg_print_dep_t *msg,
                                    const char *new_buf, size_t new_buf_len,
                                    bool should_trunc, size_t *n_written) {
  return sbp_unterminated_string_set_raw(&msg->text, SBP_MSG_PRINT_DEP_TEXT_MAX,
                                         should_trunc, n_written, new_buf,
                                         new_buf_len);
}

bool sbp_msg_print_dep_text_printf(sbp_msg_print_dep_t *msg, bool should_trunc,
                                   size_t *n_written, const char *fmt, ...) {
  va_list ap;
  va_start(ap, fmt);
  bool ret = sbp_unterminated_string_vprintf(
      &msg->text, SBP_MSG_PRINT_DEP_TEXT_MAX, should_trunc, n_written, fmt, ap);
  va_end(ap);
  return ret;
}

bool sbp_msg_print_dep_text_vprintf(sbp_msg_print_dep_t *msg, bool should_trunc,
                                    size_t *n_written, const char *fmt,
                                    va_list ap) {
  return sbp_unterminated_string_vprintf(&msg->text, SBP_MSG_PRINT_DEP_TEXT_MAX,
                                         should_trunc, n_written, fmt, ap);
}

bool sbp_msg_print_dep_text_append_printf(sbp_msg_print_dep_t *msg,
                                          bool should_trunc, size_t *n_written,
                                          const char *fmt, ...) {
  va_list ap;
  va_start(ap, fmt);
  bool ret = sbp_unterminated_string_append_vprintf(
      &msg->text, SBP_MSG_PRINT_DEP_TEXT_MAX, should_trunc, n_written, fmt, ap);
  va_end(ap);
  return ret;
}

bool sbp_msg_print_dep_text_append_vprintf(sbp_msg_print_dep_t *msg,
                                           bool should_trunc, size_t *n_written,
                                           const char *fmt, va_list ap) {
  return sbp_unterminated_string_append_vprintf(
      &msg->text, SBP_MSG_PRINT_DEP_TEXT_MAX, should_trunc, n_written, fmt, ap);
}

const char *sbp_msg_print_dep_text_get(const sbp_msg_print_dep_t *msg) {
  return sbp_unterminated_string_get(&msg->text, SBP_MSG_PRINT_DEP_TEXT_MAX);
}

size_t sbp_msg_print_dep_text_strlen(const sbp_msg_print_dep_t *msg) {
  return sbp_unterminated_string_strlen(&msg->text, SBP_MSG_PRINT_DEP_TEXT_MAX);
}

bool sbp_msg_print_dep_encode_internal(sbp_encode_ctx_t *ctx,
                                       const sbp_msg_print_dep_t *msg) {
  if (!sbp_unterminated_string_encode(&msg->text, SBP_MSG_PRINT_DEP_TEXT_MAX,
                                      ctx)) {
    return false;
  }
  return true;
}

s8 sbp_msg_print_dep_encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                            const sbp_msg_print_dep_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_print_dep_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_print_dep_decode_internal(sbp_decode_ctx_t *ctx,
                                       sbp_msg_print_dep_t *msg) {
  if (!sbp_unterminated_string_decode(&msg->text, SBP_MSG_PRINT_DEP_TEXT_MAX,
                                      ctx)) {
    return false;
  }
  return true;
}

s8 sbp_msg_print_dep_decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                            sbp_msg_print_dep_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_print_dep_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_print_dep_send(sbp_state_t *s, u16 sender_id,
                          const sbp_msg_print_dep_t *msg,
                          sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret =
      sbp_msg_print_dep_encode(payload, sizeof(payload), &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_PRINT_DEP, sender_id, payload_len, payload,
                          write);
}

int sbp_msg_print_dep_cmp(const sbp_msg_print_dep_t *a,
                          const sbp_msg_print_dep_t *b) {
  int ret = 0;

  ret = sbp_msg_print_dep_text_strcmp(a, b);
  if (ret != 0) {
    return ret;
  }
  return ret;
}
