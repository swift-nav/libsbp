/*****************************************************************************
 * Automatically generated from yaml/swiftnav/sbp/system.yaml
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#include <libsbp/internal/v4/common.h>
#include <libsbp/internal/v4/string/double_null_terminated.h>
#include <libsbp/internal/v4/string/multipart.h>
#include <libsbp/internal/v4/string/null_terminated.h>
#include <libsbp/internal/v4/string/unterminated.h>
#include <libsbp/internal/v4/system.h>
#include <libsbp/sbp.h>
#include <libsbp/v4/system.h>

bool sbp_msg_startup_encode_internal(sbp_encode_ctx_t *ctx,
                                     const sbp_msg_startup_t *msg) {
  if (!sbp_u8_encode(ctx, &msg->cause)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->startup_type)) {
    return false;
  }
  if (!sbp_u16_encode(ctx, &msg->reserved)) {
    return false;
  }
  return true;
}

s8 sbp_msg_startup_encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                          const sbp_msg_startup_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_startup_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_startup_decode_internal(sbp_decode_ctx_t *ctx,
                                     sbp_msg_startup_t *msg) {
  if (!sbp_u8_decode(ctx, &msg->cause)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->startup_type)) {
    return false;
  }
  if (!sbp_u16_decode(ctx, &msg->reserved)) {
    return false;
  }
  return true;
}

s8 sbp_msg_startup_decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                          sbp_msg_startup_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_startup_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_startup_send(sbp_state_t *s, u16 sender_id,
                        const sbp_msg_startup_t *msg, sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_msg_startup_encode(payload, sizeof(payload), &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_STARTUP, sender_id, payload_len, payload,
                          write);
}

int sbp_msg_startup_cmp(const sbp_msg_startup_t *a,
                        const sbp_msg_startup_t *b) {
  int ret = 0;

  ret = sbp_u8_cmp(&a->cause, &b->cause);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->startup_type, &b->startup_type);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u16_cmp(&a->reserved, &b->reserved);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

void sbp_msg_dgnss_status_source_init(sbp_msg_dgnss_status_t *msg) {
  sbp_unterminated_string_init(&msg->source);
}

bool sbp_msg_dgnss_status_source_valid(const sbp_msg_dgnss_status_t *msg) {
  return sbp_unterminated_string_valid(&msg->source,
                                       SBP_MSG_DGNSS_STATUS_SOURCE_MAX);
}

int sbp_msg_dgnss_status_source_strcmp(const sbp_msg_dgnss_status_t *a,
                                       const sbp_msg_dgnss_status_t *b) {
  return sbp_unterminated_string_strcmp(&a->source, &b->source,
                                        SBP_MSG_DGNSS_STATUS_SOURCE_MAX);
}

size_t sbp_msg_dgnss_status_source_encoded_len(
    const sbp_msg_dgnss_status_t *msg) {
  return sbp_unterminated_string_encoded_len(&msg->source,
                                             SBP_MSG_DGNSS_STATUS_SOURCE_MAX);
}

size_t sbp_msg_dgnss_status_source_space_remaining(
    const sbp_msg_dgnss_status_t *msg) {
  return sbp_unterminated_string_space_remaining(
      &msg->source, SBP_MSG_DGNSS_STATUS_SOURCE_MAX);
}
bool sbp_msg_dgnss_status_source_set(sbp_msg_dgnss_status_t *msg,
                                     const char *new_str, bool should_trunc,
                                     size_t *n_written) {
  return sbp_unterminated_string_set(&msg->source,
                                     SBP_MSG_DGNSS_STATUS_SOURCE_MAX,
                                     should_trunc, n_written, new_str);
}

bool sbp_msg_dgnss_status_source_set_raw(sbp_msg_dgnss_status_t *msg,
                                         const char *new_buf,
                                         size_t new_buf_len, bool should_trunc,
                                         size_t *n_written) {
  return sbp_unterminated_string_set_raw(
      &msg->source, SBP_MSG_DGNSS_STATUS_SOURCE_MAX, should_trunc, n_written,
      new_buf, new_buf_len);
}

bool sbp_msg_dgnss_status_source_printf(sbp_msg_dgnss_status_t *msg,
                                        bool should_trunc, size_t *n_written,
                                        const char *fmt, ...) {
  va_list ap;
  va_start(ap, fmt);
  bool ret = sbp_unterminated_string_vprintf(&msg->source,
                                             SBP_MSG_DGNSS_STATUS_SOURCE_MAX,
                                             should_trunc, n_written, fmt, ap);
  va_end(ap);
  return ret;
}

bool sbp_msg_dgnss_status_source_vprintf(sbp_msg_dgnss_status_t *msg,
                                         bool should_trunc, size_t *n_written,
                                         const char *fmt, va_list ap) {
  return sbp_unterminated_string_vprintf(&msg->source,
                                         SBP_MSG_DGNSS_STATUS_SOURCE_MAX,
                                         should_trunc, n_written, fmt, ap);
}

bool sbp_msg_dgnss_status_source_append_printf(sbp_msg_dgnss_status_t *msg,
                                               bool should_trunc,
                                               size_t *n_written,
                                               const char *fmt, ...) {
  va_list ap;
  va_start(ap, fmt);
  bool ret = sbp_unterminated_string_append_vprintf(
      &msg->source, SBP_MSG_DGNSS_STATUS_SOURCE_MAX, should_trunc, n_written,
      fmt, ap);
  va_end(ap);
  return ret;
}

bool sbp_msg_dgnss_status_source_append_vprintf(sbp_msg_dgnss_status_t *msg,
                                                bool should_trunc,
                                                size_t *n_written,
                                                const char *fmt, va_list ap) {
  return sbp_unterminated_string_append_vprintf(
      &msg->source, SBP_MSG_DGNSS_STATUS_SOURCE_MAX, should_trunc, n_written,
      fmt, ap);
}

const char *sbp_msg_dgnss_status_source_get(const sbp_msg_dgnss_status_t *msg) {
  return sbp_unterminated_string_get(&msg->source,
                                     SBP_MSG_DGNSS_STATUS_SOURCE_MAX);
}

size_t sbp_msg_dgnss_status_source_strlen(const sbp_msg_dgnss_status_t *msg) {
  return sbp_unterminated_string_strlen(&msg->source,
                                        SBP_MSG_DGNSS_STATUS_SOURCE_MAX);
}

bool sbp_msg_dgnss_status_encode_internal(sbp_encode_ctx_t *ctx,
                                          const sbp_msg_dgnss_status_t *msg) {
  if (!sbp_u8_encode(ctx, &msg->flags)) {
    return false;
  }
  if (!sbp_u16_encode(ctx, &msg->latency)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->num_signals)) {
    return false;
  }
  if (!sbp_unterminated_string_encode(&msg->source,
                                      SBP_MSG_DGNSS_STATUS_SOURCE_MAX, ctx)) {
    return false;
  }
  return true;
}

s8 sbp_msg_dgnss_status_encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                               const sbp_msg_dgnss_status_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_dgnss_status_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_dgnss_status_decode_internal(sbp_decode_ctx_t *ctx,
                                          sbp_msg_dgnss_status_t *msg) {
  if (!sbp_u8_decode(ctx, &msg->flags)) {
    return false;
  }
  if (!sbp_u16_decode(ctx, &msg->latency)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->num_signals)) {
    return false;
  }
  if (!sbp_unterminated_string_decode(&msg->source,
                                      SBP_MSG_DGNSS_STATUS_SOURCE_MAX, ctx)) {
    return false;
  }
  return true;
}

s8 sbp_msg_dgnss_status_decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                               sbp_msg_dgnss_status_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_dgnss_status_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_dgnss_status_send(sbp_state_t *s, u16 sender_id,
                             const sbp_msg_dgnss_status_t *msg,
                             sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret =
      sbp_msg_dgnss_status_encode(payload, sizeof(payload), &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_DGNSS_STATUS, sender_id, payload_len,
                          payload, write);
}

int sbp_msg_dgnss_status_cmp(const sbp_msg_dgnss_status_t *a,
                             const sbp_msg_dgnss_status_t *b) {
  int ret = 0;

  ret = sbp_u8_cmp(&a->flags, &b->flags);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u16_cmp(&a->latency, &b->latency);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->num_signals, &b->num_signals);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_msg_dgnss_status_source_strcmp(a, b);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

bool sbp_msg_heartbeat_encode_internal(sbp_encode_ctx_t *ctx,
                                       const sbp_msg_heartbeat_t *msg) {
  if (!sbp_u32_encode(ctx, &msg->flags)) {
    return false;
  }
  return true;
}

s8 sbp_msg_heartbeat_encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                            const sbp_msg_heartbeat_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_heartbeat_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_heartbeat_decode_internal(sbp_decode_ctx_t *ctx,
                                       sbp_msg_heartbeat_t *msg) {
  if (!sbp_u32_decode(ctx, &msg->flags)) {
    return false;
  }
  return true;
}

s8 sbp_msg_heartbeat_decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                            sbp_msg_heartbeat_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_heartbeat_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_heartbeat_send(sbp_state_t *s, u16 sender_id,
                          const sbp_msg_heartbeat_t *msg,
                          sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret =
      sbp_msg_heartbeat_encode(payload, sizeof(payload), &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_HEARTBEAT, sender_id, payload_len, payload,
                          write);
}

int sbp_msg_heartbeat_cmp(const sbp_msg_heartbeat_t *a,
                          const sbp_msg_heartbeat_t *b) {
  int ret = 0;

  ret = sbp_u32_cmp(&a->flags, &b->flags);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

bool sbp_sub_system_report_encode_internal(sbp_encode_ctx_t *ctx,
                                           const sbp_sub_system_report_t *msg) {
  if (!sbp_u16_encode(ctx, &msg->component)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->generic)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->specific)) {
    return false;
  }
  return true;
}

s8 sbp_sub_system_report_encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                                const sbp_sub_system_report_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_sub_system_report_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_sub_system_report_decode_internal(sbp_decode_ctx_t *ctx,
                                           sbp_sub_system_report_t *msg) {
  if (!sbp_u16_decode(ctx, &msg->component)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->generic)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->specific)) {
    return false;
  }
  return true;
}

s8 sbp_sub_system_report_decode(const uint8_t *buf, uint8_t len,
                                uint8_t *n_read, sbp_sub_system_report_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_sub_system_report_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

int sbp_sub_system_report_cmp(const sbp_sub_system_report_t *a,
                              const sbp_sub_system_report_t *b) {
  int ret = 0;

  ret = sbp_u16_cmp(&a->component, &b->component);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->generic, &b->generic);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->specific, &b->specific);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

bool sbp_msg_status_report_encode_internal(sbp_encode_ctx_t *ctx,
                                           const sbp_msg_status_report_t *msg) {
  if (!sbp_u16_encode(ctx, &msg->reporting_system)) {
    return false;
  }
  if (!sbp_u16_encode(ctx, &msg->sbp_version)) {
    return false;
  }
  if (!sbp_u32_encode(ctx, &msg->sequence)) {
    return false;
  }
  if (!sbp_u32_encode(ctx, &msg->uptime)) {
    return false;
  }
  for (size_t i = 0; i < msg->n_status; i++) {
    if (!sbp_sub_system_report_encode_internal(ctx, &msg->status[i])) {
      return false;
    }
  }
  return true;
}

s8 sbp_msg_status_report_encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                                const sbp_msg_status_report_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_status_report_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_status_report_decode_internal(sbp_decode_ctx_t *ctx,
                                           sbp_msg_status_report_t *msg) {
  if (!sbp_u16_decode(ctx, &msg->reporting_system)) {
    return false;
  }
  if (!sbp_u16_decode(ctx, &msg->sbp_version)) {
    return false;
  }
  if (!sbp_u32_decode(ctx, &msg->sequence)) {
    return false;
  }
  if (!sbp_u32_decode(ctx, &msg->uptime)) {
    return false;
  }
  msg->n_status = (uint8_t)((ctx->buf_len - ctx->offset) /
                            SBP_SUB_SYSTEM_REPORT_ENCODED_LEN);
  for (uint8_t i = 0; i < msg->n_status; i++) {
    if (!sbp_sub_system_report_decode_internal(ctx, &msg->status[i])) {
      return false;
    }
  }
  return true;
}

s8 sbp_msg_status_report_decode(const uint8_t *buf, uint8_t len,
                                uint8_t *n_read, sbp_msg_status_report_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_status_report_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_status_report_send(sbp_state_t *s, u16 sender_id,
                              const sbp_msg_status_report_t *msg,
                              sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret =
      sbp_msg_status_report_encode(payload, sizeof(payload), &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_STATUS_REPORT, sender_id, payload_len,
                          payload, write);
}

int sbp_msg_status_report_cmp(const sbp_msg_status_report_t *a,
                              const sbp_msg_status_report_t *b) {
  int ret = 0;

  ret = sbp_u16_cmp(&a->reporting_system, &b->reporting_system);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u16_cmp(&a->sbp_version, &b->sbp_version);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u32_cmp(&a->sequence, &b->sequence);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u32_cmp(&a->uptime, &b->uptime);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->n_status, &b->n_status);
  for (uint8_t i = 0; ret == 0 && i < a->n_status; i++) {
    ret = sbp_sub_system_report_cmp(&a->status[i], &b->status[i]);
  }
  if (ret != 0) {
    return ret;
  }
  return ret;
}

bool sbp_msg_ins_status_encode_internal(sbp_encode_ctx_t *ctx,
                                        const sbp_msg_ins_status_t *msg) {
  if (!sbp_u32_encode(ctx, &msg->flags)) {
    return false;
  }
  return true;
}

s8 sbp_msg_ins_status_encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                             const sbp_msg_ins_status_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_ins_status_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_ins_status_decode_internal(sbp_decode_ctx_t *ctx,
                                        sbp_msg_ins_status_t *msg) {
  if (!sbp_u32_decode(ctx, &msg->flags)) {
    return false;
  }
  return true;
}

s8 sbp_msg_ins_status_decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                             sbp_msg_ins_status_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_ins_status_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_ins_status_send(sbp_state_t *s, u16 sender_id,
                           const sbp_msg_ins_status_t *msg,
                           sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret =
      sbp_msg_ins_status_encode(payload, sizeof(payload), &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_INS_STATUS, sender_id, payload_len,
                          payload, write);
}

int sbp_msg_ins_status_cmp(const sbp_msg_ins_status_t *a,
                           const sbp_msg_ins_status_t *b) {
  int ret = 0;

  ret = sbp_u32_cmp(&a->flags, &b->flags);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

void sbp_msg_csac_telemetry_telemetry_init(sbp_msg_csac_telemetry_t *msg) {
  sbp_unterminated_string_init(&msg->telemetry);
}

bool sbp_msg_csac_telemetry_telemetry_valid(
    const sbp_msg_csac_telemetry_t *msg) {
  return sbp_unterminated_string_valid(&msg->telemetry,
                                       SBP_MSG_CSAC_TELEMETRY_TELEMETRY_MAX);
}

int sbp_msg_csac_telemetry_telemetry_strcmp(const sbp_msg_csac_telemetry_t *a,
                                            const sbp_msg_csac_telemetry_t *b) {
  return sbp_unterminated_string_strcmp(&a->telemetry, &b->telemetry,
                                        SBP_MSG_CSAC_TELEMETRY_TELEMETRY_MAX);
}

size_t sbp_msg_csac_telemetry_telemetry_encoded_len(
    const sbp_msg_csac_telemetry_t *msg) {
  return sbp_unterminated_string_encoded_len(
      &msg->telemetry, SBP_MSG_CSAC_TELEMETRY_TELEMETRY_MAX);
}

size_t sbp_msg_csac_telemetry_telemetry_space_remaining(
    const sbp_msg_csac_telemetry_t *msg) {
  return sbp_unterminated_string_space_remaining(
      &msg->telemetry, SBP_MSG_CSAC_TELEMETRY_TELEMETRY_MAX);
}
bool sbp_msg_csac_telemetry_telemetry_set(sbp_msg_csac_telemetry_t *msg,
                                          const char *new_str,
                                          bool should_trunc,
                                          size_t *n_written) {
  return sbp_unterminated_string_set(&msg->telemetry,
                                     SBP_MSG_CSAC_TELEMETRY_TELEMETRY_MAX,
                                     should_trunc, n_written, new_str);
}

bool sbp_msg_csac_telemetry_telemetry_set_raw(sbp_msg_csac_telemetry_t *msg,
                                              const char *new_buf,
                                              size_t new_buf_len,
                                              bool should_trunc,
                                              size_t *n_written) {
  return sbp_unterminated_string_set_raw(
      &msg->telemetry, SBP_MSG_CSAC_TELEMETRY_TELEMETRY_MAX, should_trunc,
      n_written, new_buf, new_buf_len);
}

bool sbp_msg_csac_telemetry_telemetry_printf(sbp_msg_csac_telemetry_t *msg,
                                             bool should_trunc,
                                             size_t *n_written, const char *fmt,
                                             ...) {
  va_list ap;
  va_start(ap, fmt);
  bool ret = sbp_unterminated_string_vprintf(
      &msg->telemetry, SBP_MSG_CSAC_TELEMETRY_TELEMETRY_MAX, should_trunc,
      n_written, fmt, ap);
  va_end(ap);
  return ret;
}

bool sbp_msg_csac_telemetry_telemetry_vprintf(sbp_msg_csac_telemetry_t *msg,
                                              bool should_trunc,
                                              size_t *n_written,
                                              const char *fmt, va_list ap) {
  return sbp_unterminated_string_vprintf(&msg->telemetry,
                                         SBP_MSG_CSAC_TELEMETRY_TELEMETRY_MAX,
                                         should_trunc, n_written, fmt, ap);
}

bool sbp_msg_csac_telemetry_telemetry_append_printf(
    sbp_msg_csac_telemetry_t *msg, bool should_trunc, size_t *n_written,
    const char *fmt, ...) {
  va_list ap;
  va_start(ap, fmt);
  bool ret = sbp_unterminated_string_append_vprintf(
      &msg->telemetry, SBP_MSG_CSAC_TELEMETRY_TELEMETRY_MAX, should_trunc,
      n_written, fmt, ap);
  va_end(ap);
  return ret;
}

bool sbp_msg_csac_telemetry_telemetry_append_vprintf(
    sbp_msg_csac_telemetry_t *msg, bool should_trunc, size_t *n_written,
    const char *fmt, va_list ap) {
  return sbp_unterminated_string_append_vprintf(
      &msg->telemetry, SBP_MSG_CSAC_TELEMETRY_TELEMETRY_MAX, should_trunc,
      n_written, fmt, ap);
}

const char *sbp_msg_csac_telemetry_telemetry_get(
    const sbp_msg_csac_telemetry_t *msg) {
  return sbp_unterminated_string_get(&msg->telemetry,
                                     SBP_MSG_CSAC_TELEMETRY_TELEMETRY_MAX);
}

size_t sbp_msg_csac_telemetry_telemetry_strlen(
    const sbp_msg_csac_telemetry_t *msg) {
  return sbp_unterminated_string_strlen(&msg->telemetry,
                                        SBP_MSG_CSAC_TELEMETRY_TELEMETRY_MAX);
}

bool sbp_msg_csac_telemetry_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_csac_telemetry_t *msg) {
  if (!sbp_u8_encode(ctx, &msg->id)) {
    return false;
  }
  if (!sbp_unterminated_string_encode(
          &msg->telemetry, SBP_MSG_CSAC_TELEMETRY_TELEMETRY_MAX, ctx)) {
    return false;
  }
  return true;
}

s8 sbp_msg_csac_telemetry_encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                                 const sbp_msg_csac_telemetry_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_csac_telemetry_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_csac_telemetry_decode_internal(sbp_decode_ctx_t *ctx,
                                            sbp_msg_csac_telemetry_t *msg) {
  if (!sbp_u8_decode(ctx, &msg->id)) {
    return false;
  }
  if (!sbp_unterminated_string_decode(
          &msg->telemetry, SBP_MSG_CSAC_TELEMETRY_TELEMETRY_MAX, ctx)) {
    return false;
  }
  return true;
}

s8 sbp_msg_csac_telemetry_decode(const uint8_t *buf, uint8_t len,
                                 uint8_t *n_read,
                                 sbp_msg_csac_telemetry_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_csac_telemetry_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_csac_telemetry_send(sbp_state_t *s, u16 sender_id,
                               const sbp_msg_csac_telemetry_t *msg,
                               sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_msg_csac_telemetry_encode(payload, sizeof(payload), &payload_len,
                                         msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_CSAC_TELEMETRY, sender_id, payload_len,
                          payload, write);
}

int sbp_msg_csac_telemetry_cmp(const sbp_msg_csac_telemetry_t *a,
                               const sbp_msg_csac_telemetry_t *b) {
  int ret = 0;

  ret = sbp_u8_cmp(&a->id, &b->id);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_msg_csac_telemetry_telemetry_strcmp(a, b);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

void sbp_msg_csac_telemetry_labels_telemetry_labels_init(
    sbp_msg_csac_telemetry_labels_t *msg) {
  sbp_unterminated_string_init(&msg->telemetry_labels);
}

bool sbp_msg_csac_telemetry_labels_telemetry_labels_valid(
    const sbp_msg_csac_telemetry_labels_t *msg) {
  return sbp_unterminated_string_valid(
      &msg->telemetry_labels,
      SBP_MSG_CSAC_TELEMETRY_LABELS_TELEMETRY_LABELS_MAX);
}

int sbp_msg_csac_telemetry_labels_telemetry_labels_strcmp(
    const sbp_msg_csac_telemetry_labels_t *a,
    const sbp_msg_csac_telemetry_labels_t *b) {
  return sbp_unterminated_string_strcmp(
      &a->telemetry_labels, &b->telemetry_labels,
      SBP_MSG_CSAC_TELEMETRY_LABELS_TELEMETRY_LABELS_MAX);
}

size_t sbp_msg_csac_telemetry_labels_telemetry_labels_encoded_len(
    const sbp_msg_csac_telemetry_labels_t *msg) {
  return sbp_unterminated_string_encoded_len(
      &msg->telemetry_labels,
      SBP_MSG_CSAC_TELEMETRY_LABELS_TELEMETRY_LABELS_MAX);
}

size_t sbp_msg_csac_telemetry_labels_telemetry_labels_space_remaining(
    const sbp_msg_csac_telemetry_labels_t *msg) {
  return sbp_unterminated_string_space_remaining(
      &msg->telemetry_labels,
      SBP_MSG_CSAC_TELEMETRY_LABELS_TELEMETRY_LABELS_MAX);
}
bool sbp_msg_csac_telemetry_labels_telemetry_labels_set(
    sbp_msg_csac_telemetry_labels_t *msg, const char *new_str,
    bool should_trunc, size_t *n_written) {
  return sbp_unterminated_string_set(
      &msg->telemetry_labels,
      SBP_MSG_CSAC_TELEMETRY_LABELS_TELEMETRY_LABELS_MAX, should_trunc,
      n_written, new_str);
}

bool sbp_msg_csac_telemetry_labels_telemetry_labels_set_raw(
    sbp_msg_csac_telemetry_labels_t *msg, const char *new_buf,
    size_t new_buf_len, bool should_trunc, size_t *n_written) {
  return sbp_unterminated_string_set_raw(
      &msg->telemetry_labels,
      SBP_MSG_CSAC_TELEMETRY_LABELS_TELEMETRY_LABELS_MAX, should_trunc,
      n_written, new_buf, new_buf_len);
}

bool sbp_msg_csac_telemetry_labels_telemetry_labels_printf(
    sbp_msg_csac_telemetry_labels_t *msg, bool should_trunc, size_t *n_written,
    const char *fmt, ...) {
  va_list ap;
  va_start(ap, fmt);
  bool ret = sbp_unterminated_string_vprintf(
      &msg->telemetry_labels,
      SBP_MSG_CSAC_TELEMETRY_LABELS_TELEMETRY_LABELS_MAX, should_trunc,
      n_written, fmt, ap);
  va_end(ap);
  return ret;
}

bool sbp_msg_csac_telemetry_labels_telemetry_labels_vprintf(
    sbp_msg_csac_telemetry_labels_t *msg, bool should_trunc, size_t *n_written,
    const char *fmt, va_list ap) {
  return sbp_unterminated_string_vprintf(
      &msg->telemetry_labels,
      SBP_MSG_CSAC_TELEMETRY_LABELS_TELEMETRY_LABELS_MAX, should_trunc,
      n_written, fmt, ap);
}

bool sbp_msg_csac_telemetry_labels_telemetry_labels_append_printf(
    sbp_msg_csac_telemetry_labels_t *msg, bool should_trunc, size_t *n_written,
    const char *fmt, ...) {
  va_list ap;
  va_start(ap, fmt);
  bool ret = sbp_unterminated_string_append_vprintf(
      &msg->telemetry_labels,
      SBP_MSG_CSAC_TELEMETRY_LABELS_TELEMETRY_LABELS_MAX, should_trunc,
      n_written, fmt, ap);
  va_end(ap);
  return ret;
}

bool sbp_msg_csac_telemetry_labels_telemetry_labels_append_vprintf(
    sbp_msg_csac_telemetry_labels_t *msg, bool should_trunc, size_t *n_written,
    const char *fmt, va_list ap) {
  return sbp_unterminated_string_append_vprintf(
      &msg->telemetry_labels,
      SBP_MSG_CSAC_TELEMETRY_LABELS_TELEMETRY_LABELS_MAX, should_trunc,
      n_written, fmt, ap);
}

const char *sbp_msg_csac_telemetry_labels_telemetry_labels_get(
    const sbp_msg_csac_telemetry_labels_t *msg) {
  return sbp_unterminated_string_get(
      &msg->telemetry_labels,
      SBP_MSG_CSAC_TELEMETRY_LABELS_TELEMETRY_LABELS_MAX);
}

size_t sbp_msg_csac_telemetry_labels_telemetry_labels_strlen(
    const sbp_msg_csac_telemetry_labels_t *msg) {
  return sbp_unterminated_string_strlen(
      &msg->telemetry_labels,
      SBP_MSG_CSAC_TELEMETRY_LABELS_TELEMETRY_LABELS_MAX);
}

bool sbp_msg_csac_telemetry_labels_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_csac_telemetry_labels_t *msg) {
  if (!sbp_u8_encode(ctx, &msg->id)) {
    return false;
  }
  if (!sbp_unterminated_string_encode(
          &msg->telemetry_labels,
          SBP_MSG_CSAC_TELEMETRY_LABELS_TELEMETRY_LABELS_MAX, ctx)) {
    return false;
  }
  return true;
}

s8 sbp_msg_csac_telemetry_labels_encode(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_msg_csac_telemetry_labels_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_csac_telemetry_labels_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_csac_telemetry_labels_decode_internal(
    sbp_decode_ctx_t *ctx, sbp_msg_csac_telemetry_labels_t *msg) {
  if (!sbp_u8_decode(ctx, &msg->id)) {
    return false;
  }
  if (!sbp_unterminated_string_decode(
          &msg->telemetry_labels,
          SBP_MSG_CSAC_TELEMETRY_LABELS_TELEMETRY_LABELS_MAX, ctx)) {
    return false;
  }
  return true;
}

s8 sbp_msg_csac_telemetry_labels_decode(const uint8_t *buf, uint8_t len,
                                        uint8_t *n_read,
                                        sbp_msg_csac_telemetry_labels_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_csac_telemetry_labels_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_csac_telemetry_labels_send(
    sbp_state_t *s, u16 sender_id, const sbp_msg_csac_telemetry_labels_t *msg,
    sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_msg_csac_telemetry_labels_encode(payload, sizeof(payload),
                                                &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_CSAC_TELEMETRY_LABELS, sender_id,
                          payload_len, payload, write);
}

int sbp_msg_csac_telemetry_labels_cmp(
    const sbp_msg_csac_telemetry_labels_t *a,
    const sbp_msg_csac_telemetry_labels_t *b) {
  int ret = 0;

  ret = sbp_u8_cmp(&a->id, &b->id);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_msg_csac_telemetry_labels_telemetry_labels_strcmp(a, b);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

bool sbp_msg_ins_updates_encode_internal(sbp_encode_ctx_t *ctx,
                                         const sbp_msg_ins_updates_t *msg) {
  if (!sbp_u32_encode(ctx, &msg->tow)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->gnsspos)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->gnssvel)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->wheelticks)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->speed)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->nhc)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->zerovel)) {
    return false;
  }
  return true;
}

s8 sbp_msg_ins_updates_encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                              const sbp_msg_ins_updates_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_ins_updates_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_ins_updates_decode_internal(sbp_decode_ctx_t *ctx,
                                         sbp_msg_ins_updates_t *msg) {
  if (!sbp_u32_decode(ctx, &msg->tow)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->gnsspos)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->gnssvel)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->wheelticks)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->speed)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->nhc)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->zerovel)) {
    return false;
  }
  return true;
}

s8 sbp_msg_ins_updates_decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                              sbp_msg_ins_updates_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_ins_updates_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_ins_updates_send(sbp_state_t *s, u16 sender_id,
                            const sbp_msg_ins_updates_t *msg,
                            sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret =
      sbp_msg_ins_updates_encode(payload, sizeof(payload), &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_INS_UPDATES, sender_id, payload_len,
                          payload, write);
}

int sbp_msg_ins_updates_cmp(const sbp_msg_ins_updates_t *a,
                            const sbp_msg_ins_updates_t *b) {
  int ret = 0;

  ret = sbp_u32_cmp(&a->tow, &b->tow);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->gnsspos, &b->gnsspos);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->gnssvel, &b->gnssvel);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->wheelticks, &b->wheelticks);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->speed, &b->speed);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->nhc, &b->nhc);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->zerovel, &b->zerovel);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

bool sbp_msg_gnss_time_offset_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_gnss_time_offset_t *msg) {
  if (!sbp_s16_encode(ctx, &msg->weeks)) {
    return false;
  }
  if (!sbp_s32_encode(ctx, &msg->milliseconds)) {
    return false;
  }
  if (!sbp_s16_encode(ctx, &msg->microseconds)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->flags)) {
    return false;
  }
  return true;
}

s8 sbp_msg_gnss_time_offset_encode(uint8_t *buf, uint8_t len,
                                   uint8_t *n_written,
                                   const sbp_msg_gnss_time_offset_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_gnss_time_offset_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_gnss_time_offset_decode_internal(sbp_decode_ctx_t *ctx,
                                              sbp_msg_gnss_time_offset_t *msg) {
  if (!sbp_s16_decode(ctx, &msg->weeks)) {
    return false;
  }
  if (!sbp_s32_decode(ctx, &msg->milliseconds)) {
    return false;
  }
  if (!sbp_s16_decode(ctx, &msg->microseconds)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->flags)) {
    return false;
  }
  return true;
}

s8 sbp_msg_gnss_time_offset_decode(const uint8_t *buf, uint8_t len,
                                   uint8_t *n_read,
                                   sbp_msg_gnss_time_offset_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_gnss_time_offset_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_gnss_time_offset_send(sbp_state_t *s, u16 sender_id,
                                 const sbp_msg_gnss_time_offset_t *msg,
                                 sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_msg_gnss_time_offset_encode(payload, sizeof(payload),
                                           &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_GNSS_TIME_OFFSET, sender_id, payload_len,
                          payload, write);
}

int sbp_msg_gnss_time_offset_cmp(const sbp_msg_gnss_time_offset_t *a,
                                 const sbp_msg_gnss_time_offset_t *b) {
  int ret = 0;

  ret = sbp_s16_cmp(&a->weeks, &b->weeks);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_s32_cmp(&a->milliseconds, &b->milliseconds);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_s16_cmp(&a->microseconds, &b->microseconds);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->flags, &b->flags);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

bool sbp_msg_pps_time_encode_internal(sbp_encode_ctx_t *ctx,
                                      const sbp_msg_pps_time_t *msg) {
  if (!sbp_u64_encode(ctx, &msg->time)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->flags)) {
    return false;
  }
  return true;
}

s8 sbp_msg_pps_time_encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                           const sbp_msg_pps_time_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_pps_time_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_pps_time_decode_internal(sbp_decode_ctx_t *ctx,
                                      sbp_msg_pps_time_t *msg) {
  if (!sbp_u64_decode(ctx, &msg->time)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->flags)) {
    return false;
  }
  return true;
}

s8 sbp_msg_pps_time_decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                           sbp_msg_pps_time_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_pps_time_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_pps_time_send(sbp_state_t *s, u16 sender_id,
                         const sbp_msg_pps_time_t *msg, sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_msg_pps_time_encode(payload, sizeof(payload), &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_PPS_TIME, sender_id, payload_len, payload,
                          write);
}

int sbp_msg_pps_time_cmp(const sbp_msg_pps_time_t *a,
                         const sbp_msg_pps_time_t *b) {
  int ret = 0;

  ret = sbp_u64_cmp(&a->time, &b->time);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->flags, &b->flags);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

bool sbp_msg_group_meta_encode_internal(sbp_encode_ctx_t *ctx,
                                        const sbp_msg_group_meta_t *msg) {
  if (!sbp_u8_encode(ctx, &msg->group_id)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->flags)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->n_group_msgs)) {
    return false;
  }
  for (size_t i = 0; i < msg->n_group_msgs; i++) {
    if (!sbp_u16_encode(ctx, &msg->group_msgs[i])) {
      return false;
    }
  }
  return true;
}

s8 sbp_msg_group_meta_encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                             const sbp_msg_group_meta_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_group_meta_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_group_meta_decode_internal(sbp_decode_ctx_t *ctx,
                                        sbp_msg_group_meta_t *msg) {
  if (!sbp_u8_decode(ctx, &msg->group_id)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->flags)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->n_group_msgs)) {
    return false;
  }
  msg->n_group_msgs =
      (uint8_t)((ctx->buf_len - ctx->offset) / SBP_ENCODED_LEN_U16);
  for (uint8_t i = 0; i < msg->n_group_msgs; i++) {
    if (!sbp_u16_decode(ctx, &msg->group_msgs[i])) {
      return false;
    }
  }
  return true;
}

s8 sbp_msg_group_meta_decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                             sbp_msg_group_meta_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_group_meta_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_group_meta_send(sbp_state_t *s, u16 sender_id,
                           const sbp_msg_group_meta_t *msg,
                           sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret =
      sbp_msg_group_meta_encode(payload, sizeof(payload), &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_GROUP_META, sender_id, payload_len,
                          payload, write);
}

int sbp_msg_group_meta_cmp(const sbp_msg_group_meta_t *a,
                           const sbp_msg_group_meta_t *b) {
  int ret = 0;

  ret = sbp_u8_cmp(&a->group_id, &b->group_id);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->flags, &b->flags);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->n_group_msgs, &b->n_group_msgs);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->n_group_msgs, &b->n_group_msgs);
  for (uint8_t i = 0; ret == 0 && i < a->n_group_msgs; i++) {
    ret = sbp_u16_cmp(&a->group_msgs[i], &b->group_msgs[i]);
  }
  if (ret != 0) {
    return ret;
  }
  return ret;
}
