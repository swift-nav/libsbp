/*****************************************************************************
 * Automatically generated from yaml/swiftnav/sbp/profiling.yaml
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#include <libsbp/internal/common.h>
#include <libsbp/internal/profiling.h>
#include <libsbp/internal/sbp_internal.h>
#include <libsbp/internal/string/double_null_terminated.h>
#include <libsbp/internal/string/multipart.h>
#include <libsbp/internal/string/null_terminated.h>
#include <libsbp/internal/string/unterminated.h>
#include <libsbp/profiling.h>
#include <libsbp/sbp.h>

void sbp_msg_measurement_point_func_init(sbp_msg_measurement_point_t *msg) {
  sbp_null_terminated_string_init(&msg->func);
}

bool sbp_msg_measurement_point_func_valid(
    const sbp_msg_measurement_point_t *msg) {
  return sbp_null_terminated_string_valid(&msg->func,
                                          SBP_MSG_MEASUREMENT_POINT_FUNC_MAX);
}

int sbp_msg_measurement_point_func_strcmp(
    const sbp_msg_measurement_point_t *a,
    const sbp_msg_measurement_point_t *b) {
  return sbp_null_terminated_string_strcmp(&a->func, &b->func,
                                           SBP_MSG_MEASUREMENT_POINT_FUNC_MAX);
}

size_t sbp_msg_measurement_point_func_encoded_len(
    const sbp_msg_measurement_point_t *msg) {
  return sbp_null_terminated_string_encoded_len(
      &msg->func, SBP_MSG_MEASUREMENT_POINT_FUNC_MAX);
}

size_t sbp_msg_measurement_point_func_space_remaining(
    const sbp_msg_measurement_point_t *msg) {
  return sbp_null_terminated_string_space_remaining(
      &msg->func, SBP_MSG_MEASUREMENT_POINT_FUNC_MAX);
}
bool sbp_msg_measurement_point_func_set(sbp_msg_measurement_point_t *msg,
                                        const char *new_str, bool should_trunc,
                                        size_t *n_written) {
  return sbp_null_terminated_string_set(&msg->func,
                                        SBP_MSG_MEASUREMENT_POINT_FUNC_MAX,
                                        should_trunc, n_written, new_str);
}

bool sbp_msg_measurement_point_func_set_raw(sbp_msg_measurement_point_t *msg,
                                            const char *new_buf,
                                            size_t new_buf_len,
                                            bool should_trunc,
                                            size_t *n_written) {
  return sbp_null_terminated_string_set_raw(
      &msg->func, SBP_MSG_MEASUREMENT_POINT_FUNC_MAX, should_trunc, n_written,
      new_buf, new_buf_len);
}

bool sbp_msg_measurement_point_func_printf(sbp_msg_measurement_point_t *msg,
                                           bool should_trunc, size_t *n_written,
                                           const char *fmt, ...) {
  va_list ap;
  va_start(ap, fmt);
  bool ret = sbp_null_terminated_string_vprintf(
      &msg->func, SBP_MSG_MEASUREMENT_POINT_FUNC_MAX, should_trunc, n_written,
      fmt, ap);
  va_end(ap);
  return ret;
}

bool sbp_msg_measurement_point_func_vprintf(sbp_msg_measurement_point_t *msg,
                                            bool should_trunc,
                                            size_t *n_written, const char *fmt,
                                            va_list ap) {
  return sbp_null_terminated_string_vprintf(&msg->func,
                                            SBP_MSG_MEASUREMENT_POINT_FUNC_MAX,
                                            should_trunc, n_written, fmt, ap);
}

bool sbp_msg_measurement_point_func_append_printf(
    sbp_msg_measurement_point_t *msg, bool should_trunc, size_t *n_written,
    const char *fmt, ...) {
  va_list ap;
  va_start(ap, fmt);
  bool ret = sbp_null_terminated_string_append_vprintf(
      &msg->func, SBP_MSG_MEASUREMENT_POINT_FUNC_MAX, should_trunc, n_written,
      fmt, ap);
  va_end(ap);
  return ret;
}

bool sbp_msg_measurement_point_func_append_vprintf(
    sbp_msg_measurement_point_t *msg, bool should_trunc, size_t *n_written,
    const char *fmt, va_list ap) {
  return sbp_null_terminated_string_append_vprintf(
      &msg->func, SBP_MSG_MEASUREMENT_POINT_FUNC_MAX, should_trunc, n_written,
      fmt, ap);
}

const char *sbp_msg_measurement_point_func_get(
    const sbp_msg_measurement_point_t *msg) {
  return sbp_null_terminated_string_get(&msg->func,
                                        SBP_MSG_MEASUREMENT_POINT_FUNC_MAX);
}

size_t sbp_msg_measurement_point_func_strlen(
    const sbp_msg_measurement_point_t *msg) {
  return sbp_null_terminated_string_strlen(&msg->func,
                                           SBP_MSG_MEASUREMENT_POINT_FUNC_MAX);
}

bool sbp_msg_measurement_point_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_measurement_point_t *msg) {
  if (!sbp_u32_encode(ctx, &msg->total_time)) {
    return false;
  }
  if (!sbp_u16_encode(ctx, &msg->num_executions)) {
    return false;
  }
  if (!sbp_u32_encode(ctx, &msg->min)) {
    return false;
  }
  if (!sbp_u32_encode(ctx, &msg->max)) {
    return false;
  }
  if (!sbp_u64_encode(ctx, &msg->return_addr)) {
    return false;
  }
  if (!sbp_u64_encode(ctx, &msg->id)) {
    return false;
  }
  if (!sbp_u64_encode(ctx, &msg->slice_time)) {
    return false;
  }
  if (!sbp_u16_encode(ctx, &msg->line)) {
    return false;
  }
  if (!sbp_null_terminated_string_encode(
          &msg->func, SBP_MSG_MEASUREMENT_POINT_FUNC_MAX, ctx)) {
    return false;
  }
  return true;
}

s8 sbp_msg_measurement_point_encode(uint8_t *buf, uint8_t len,
                                    uint8_t *n_written,
                                    const sbp_msg_measurement_point_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_measurement_point_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_measurement_point_decode_internal(
    sbp_decode_ctx_t *ctx, sbp_msg_measurement_point_t *msg) {
  if (!sbp_u32_decode(ctx, &msg->total_time)) {
    return false;
  }
  if (!sbp_u16_decode(ctx, &msg->num_executions)) {
    return false;
  }
  if (!sbp_u32_decode(ctx, &msg->min)) {
    return false;
  }
  if (!sbp_u32_decode(ctx, &msg->max)) {
    return false;
  }
  if (!sbp_u64_decode(ctx, &msg->return_addr)) {
    return false;
  }
  if (!sbp_u64_decode(ctx, &msg->id)) {
    return false;
  }
  if (!sbp_u64_decode(ctx, &msg->slice_time)) {
    return false;
  }
  if (!sbp_u16_decode(ctx, &msg->line)) {
    return false;
  }
  if (!sbp_null_terminated_string_decode(
          &msg->func, SBP_MSG_MEASUREMENT_POINT_FUNC_MAX, ctx)) {
    return false;
  }
  return true;
}

s8 sbp_msg_measurement_point_decode(const uint8_t *buf, uint8_t len,
                                    uint8_t *n_read,
                                    sbp_msg_measurement_point_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_measurement_point_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_measurement_point_send(sbp_state_t *s, u16 sender_id,
                                  const sbp_msg_measurement_point_t *msg,
                                  sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_msg_measurement_point_encode(payload, sizeof(payload),
                                            &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_internal_forward_payload(s, SBP_MSG_MEASUREMENT_POINT, sender_id,
                                      payload_len, payload, write);
}

int sbp_msg_measurement_point_cmp(const sbp_msg_measurement_point_t *a,
                                  const sbp_msg_measurement_point_t *b) {
  int ret = 0;

  ret = sbp_u32_cmp(&a->total_time, &b->total_time);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u16_cmp(&a->num_executions, &b->num_executions);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u32_cmp(&a->min, &b->min);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u32_cmp(&a->max, &b->max);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u64_cmp(&a->return_addr, &b->return_addr);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u64_cmp(&a->id, &b->id);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u64_cmp(&a->slice_time, &b->slice_time);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u16_cmp(&a->line, &b->line);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_msg_measurement_point_func_strcmp(a, b);
  return ret;
}
