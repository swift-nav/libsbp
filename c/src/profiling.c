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

bool sbp_msg_profiling_system_info_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_profiling_system_info_t *msg) {
  if (!sbp_u64_encode(ctx, &msg->total_cpu_time)) {
    return false;
  }
  if (!sbp_u64_encode(ctx, &msg->age)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->n_threads)) {
    return false;
  }
  if (!sbp_u32_encode(ctx, &msg->heap_usage)) {
    return false;
  }
  return true;
}

s8 sbp_msg_profiling_system_info_encode(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_msg_profiling_system_info_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_profiling_system_info_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_profiling_system_info_decode_internal(
    sbp_decode_ctx_t *ctx, sbp_msg_profiling_system_info_t *msg) {
  if (!sbp_u64_decode(ctx, &msg->total_cpu_time)) {
    return false;
  }
  if (!sbp_u64_decode(ctx, &msg->age)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->n_threads)) {
    return false;
  }
  if (!sbp_u32_decode(ctx, &msg->heap_usage)) {
    return false;
  }
  return true;
}

s8 sbp_msg_profiling_system_info_decode(const uint8_t *buf, uint8_t len,
                                        uint8_t *n_read,
                                        sbp_msg_profiling_system_info_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_profiling_system_info_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_profiling_system_info_send(
    sbp_state_t *s, u16 sender_id, const sbp_msg_profiling_system_info_t *msg,
    sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_msg_profiling_system_info_encode(payload, sizeof(payload),
                                                &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_internal_forward_payload(s, SBP_MSG_PROFILING_SYSTEM_INFO,
                                      sender_id, payload_len, payload, write);
}

int sbp_msg_profiling_system_info_cmp(
    const sbp_msg_profiling_system_info_t *a,
    const sbp_msg_profiling_system_info_t *b) {
  int ret = 0;

  ret = sbp_u64_cmp(&a->total_cpu_time, &b->total_cpu_time);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u64_cmp(&a->age, &b->age);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->n_threads, &b->n_threads);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u32_cmp(&a->heap_usage, &b->heap_usage);
  return ret;
}

void sbp_msg_profiling_thread_info_name_init(
    sbp_msg_profiling_thread_info_t *msg) {
  sbp_null_terminated_string_init(&msg->name);
}

bool sbp_msg_profiling_thread_info_name_valid(
    const sbp_msg_profiling_thread_info_t *msg) {
  return sbp_null_terminated_string_valid(
      &msg->name, SBP_MSG_PROFILING_THREAD_INFO_NAME_MAX);
}

int sbp_msg_profiling_thread_info_name_strcmp(
    const sbp_msg_profiling_thread_info_t *a,
    const sbp_msg_profiling_thread_info_t *b) {
  return sbp_null_terminated_string_strcmp(
      &a->name, &b->name, SBP_MSG_PROFILING_THREAD_INFO_NAME_MAX);
}

size_t sbp_msg_profiling_thread_info_name_encoded_len(
    const sbp_msg_profiling_thread_info_t *msg) {
  return sbp_null_terminated_string_encoded_len(
      &msg->name, SBP_MSG_PROFILING_THREAD_INFO_NAME_MAX);
}

size_t sbp_msg_profiling_thread_info_name_space_remaining(
    const sbp_msg_profiling_thread_info_t *msg) {
  return sbp_null_terminated_string_space_remaining(
      &msg->name, SBP_MSG_PROFILING_THREAD_INFO_NAME_MAX);
}
bool sbp_msg_profiling_thread_info_name_set(
    sbp_msg_profiling_thread_info_t *msg, const char *new_str,
    bool should_trunc, size_t *n_written) {
  return sbp_null_terminated_string_set(&msg->name,
                                        SBP_MSG_PROFILING_THREAD_INFO_NAME_MAX,
                                        should_trunc, n_written, new_str);
}

bool sbp_msg_profiling_thread_info_name_set_raw(
    sbp_msg_profiling_thread_info_t *msg, const char *new_buf,
    size_t new_buf_len, bool should_trunc, size_t *n_written) {
  return sbp_null_terminated_string_set_raw(
      &msg->name, SBP_MSG_PROFILING_THREAD_INFO_NAME_MAX, should_trunc,
      n_written, new_buf, new_buf_len);
}

bool sbp_msg_profiling_thread_info_name_printf(
    sbp_msg_profiling_thread_info_t *msg, bool should_trunc, size_t *n_written,
    const char *fmt, ...) {
  va_list ap;
  va_start(ap, fmt);
  bool ret = sbp_null_terminated_string_vprintf(
      &msg->name, SBP_MSG_PROFILING_THREAD_INFO_NAME_MAX, should_trunc,
      n_written, fmt, ap);
  va_end(ap);
  return ret;
}

bool sbp_msg_profiling_thread_info_name_vprintf(
    sbp_msg_profiling_thread_info_t *msg, bool should_trunc, size_t *n_written,
    const char *fmt, va_list ap) {
  return sbp_null_terminated_string_vprintf(
      &msg->name, SBP_MSG_PROFILING_THREAD_INFO_NAME_MAX, should_trunc,
      n_written, fmt, ap);
}

bool sbp_msg_profiling_thread_info_name_append_printf(
    sbp_msg_profiling_thread_info_t *msg, bool should_trunc, size_t *n_written,
    const char *fmt, ...) {
  va_list ap;
  va_start(ap, fmt);
  bool ret = sbp_null_terminated_string_append_vprintf(
      &msg->name, SBP_MSG_PROFILING_THREAD_INFO_NAME_MAX, should_trunc,
      n_written, fmt, ap);
  va_end(ap);
  return ret;
}

bool sbp_msg_profiling_thread_info_name_append_vprintf(
    sbp_msg_profiling_thread_info_t *msg, bool should_trunc, size_t *n_written,
    const char *fmt, va_list ap) {
  return sbp_null_terminated_string_append_vprintf(
      &msg->name, SBP_MSG_PROFILING_THREAD_INFO_NAME_MAX, should_trunc,
      n_written, fmt, ap);
}

const char *sbp_msg_profiling_thread_info_name_get(
    const sbp_msg_profiling_thread_info_t *msg) {
  return sbp_null_terminated_string_get(&msg->name,
                                        SBP_MSG_PROFILING_THREAD_INFO_NAME_MAX);
}

size_t sbp_msg_profiling_thread_info_name_strlen(
    const sbp_msg_profiling_thread_info_t *msg) {
  return sbp_null_terminated_string_strlen(
      &msg->name, SBP_MSG_PROFILING_THREAD_INFO_NAME_MAX);
}

bool sbp_msg_profiling_thread_info_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_profiling_thread_info_t *msg) {
  if (!sbp_u64_encode(ctx, &msg->total_cpu_time)) {
    return false;
  }
  if (!sbp_u64_encode(ctx, &msg->age)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->state)) {
    return false;
  }
  if (!sbp_u32_encode(ctx, &msg->stack_size)) {
    return false;
  }
  if (!sbp_u32_encode(ctx, &msg->stack_usage)) {
    return false;
  }
  if (!sbp_null_terminated_string_encode(
          &msg->name, SBP_MSG_PROFILING_THREAD_INFO_NAME_MAX, ctx)) {
    return false;
  }
  return true;
}

s8 sbp_msg_profiling_thread_info_encode(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_msg_profiling_thread_info_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_profiling_thread_info_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_profiling_thread_info_decode_internal(
    sbp_decode_ctx_t *ctx, sbp_msg_profiling_thread_info_t *msg) {
  if (!sbp_u64_decode(ctx, &msg->total_cpu_time)) {
    return false;
  }
  if (!sbp_u64_decode(ctx, &msg->age)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->state)) {
    return false;
  }
  if (!sbp_u32_decode(ctx, &msg->stack_size)) {
    return false;
  }
  if (!sbp_u32_decode(ctx, &msg->stack_usage)) {
    return false;
  }
  if (!sbp_null_terminated_string_decode(
          &msg->name, SBP_MSG_PROFILING_THREAD_INFO_NAME_MAX, ctx)) {
    return false;
  }
  return true;
}

s8 sbp_msg_profiling_thread_info_decode(const uint8_t *buf, uint8_t len,
                                        uint8_t *n_read,
                                        sbp_msg_profiling_thread_info_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_profiling_thread_info_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_profiling_thread_info_send(
    sbp_state_t *s, u16 sender_id, const sbp_msg_profiling_thread_info_t *msg,
    sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_msg_profiling_thread_info_encode(payload, sizeof(payload),
                                                &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_internal_forward_payload(s, SBP_MSG_PROFILING_THREAD_INFO,
                                      sender_id, payload_len, payload, write);
}

int sbp_msg_profiling_thread_info_cmp(
    const sbp_msg_profiling_thread_info_t *a,
    const sbp_msg_profiling_thread_info_t *b) {
  int ret = 0;

  ret = sbp_u64_cmp(&a->total_cpu_time, &b->total_cpu_time);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u64_cmp(&a->age, &b->age);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->state, &b->state);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u32_cmp(&a->stack_size, &b->stack_size);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u32_cmp(&a->stack_usage, &b->stack_usage);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_msg_profiling_thread_info_name_strcmp(a, b);
  return ret;
}

bool sbp_resource_bucket_encode_internal(sbp_encode_ctx_t *ctx,
                                         const sbp_resource_bucket_t *msg) {
  for (size_t i = 0; i < SBP_RESOURCE_BUCKET_NAME_MAX; i++) {
    if (!sbp_char_encode(ctx, &msg->name[i])) {
      return false;
    }
  }
  if (!sbp_u8_encode(ctx, &msg->thread)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->mutex)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->cv)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->io)) {
    return false;
  }
  if (!sbp_u32_encode(ctx, &msg->heap)) {
    return false;
  }
  if (!sbp_u32_encode(ctx, &msg->io_write)) {
    return false;
  }
  if (!sbp_u32_encode(ctx, &msg->io_read)) {
    return false;
  }
  return true;
}

s8 sbp_resource_bucket_encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                              const sbp_resource_bucket_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_resource_bucket_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_resource_bucket_decode_internal(sbp_decode_ctx_t *ctx,
                                         sbp_resource_bucket_t *msg) {
  for (uint8_t i = 0; i < SBP_RESOURCE_BUCKET_NAME_MAX; i++) {
    if (!sbp_char_decode(ctx, &msg->name[i])) {
      return false;
    }
  }
  if (!sbp_u8_decode(ctx, &msg->thread)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->mutex)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->cv)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->io)) {
    return false;
  }
  if (!sbp_u32_decode(ctx, &msg->heap)) {
    return false;
  }
  if (!sbp_u32_decode(ctx, &msg->io_write)) {
    return false;
  }
  if (!sbp_u32_decode(ctx, &msg->io_read)) {
    return false;
  }
  return true;
}

s8 sbp_resource_bucket_decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                              sbp_resource_bucket_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_resource_bucket_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

int sbp_resource_bucket_cmp(const sbp_resource_bucket_t *a,
                            const sbp_resource_bucket_t *b) {
  int ret = 0;

  for (uint8_t i = 0; i < SBP_RESOURCE_BUCKET_NAME_MAX; i++) {
    ret = sbp_char_cmp(&a->name[i], &b->name[i]);
    if (ret != 0) {
      return ret;
    }
  }
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->thread, &b->thread);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->mutex, &b->mutex);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->cv, &b->cv);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->io, &b->io);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u32_cmp(&a->heap, &b->heap);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u32_cmp(&a->io_write, &b->io_write);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u32_cmp(&a->io_read, &b->io_read);
  return ret;
}

bool sbp_msg_profiling_resource_counter_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_profiling_resource_counter_t *msg) {
  if (!sbp_u8_encode(ctx, &msg->seq_no)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->seq_len)) {
    return false;
  }
  for (size_t i = 0; i < msg->n_buckets; i++) {
    if (!sbp_resource_bucket_encode_internal(ctx, &msg->buckets[i])) {
      return false;
    }
  }
  return true;
}

s8 sbp_msg_profiling_resource_counter_encode(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_msg_profiling_resource_counter_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_profiling_resource_counter_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_profiling_resource_counter_decode_internal(
    sbp_decode_ctx_t *ctx, sbp_msg_profiling_resource_counter_t *msg) {
  if (!sbp_u8_decode(ctx, &msg->seq_no)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->seq_len)) {
    return false;
  }
  if (((ctx->buf_len - ctx->offset) % SBP_RESOURCE_BUCKET_ENCODED_LEN) != 0) {
    return false;
  }
  msg->n_buckets =
      (uint8_t)((ctx->buf_len - ctx->offset) / SBP_RESOURCE_BUCKET_ENCODED_LEN);
  for (uint8_t i = 0; i < msg->n_buckets; i++) {
    if (!sbp_resource_bucket_decode_internal(ctx, &msg->buckets[i])) {
      return false;
    }
  }
  return true;
}

s8 sbp_msg_profiling_resource_counter_decode(
    const uint8_t *buf, uint8_t len, uint8_t *n_read,
    sbp_msg_profiling_resource_counter_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_profiling_resource_counter_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_profiling_resource_counter_send(
    sbp_state_t *s, u16 sender_id,
    const sbp_msg_profiling_resource_counter_t *msg, sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_msg_profiling_resource_counter_encode(payload, sizeof(payload),
                                                     &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_internal_forward_payload(s, SBP_MSG_PROFILING_RESOURCE_COUNTER,
                                      sender_id, payload_len, payload, write);
}

int sbp_msg_profiling_resource_counter_cmp(
    const sbp_msg_profiling_resource_counter_t *a,
    const sbp_msg_profiling_resource_counter_t *b) {
  int ret = 0;

  ret = sbp_u8_cmp(&a->seq_no, &b->seq_no);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->seq_len, &b->seq_len);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->n_buckets, &b->n_buckets);
  if (ret != 0) {
    return ret;
  }
  for (uint8_t i = 0; i < a->n_buckets; i++) {
    ret = sbp_resource_bucket_cmp(&a->buckets[i], &b->buckets[i]);
    if (ret != 0) {
      return ret;
    }
  }
  return ret;
}
