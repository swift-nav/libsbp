#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <libsbp/sbp.h>
#include <libsbp/internal/new/common.h>
#include <libsbp/new/system.h>
#include <libsbp/internal/new/system.h>
#include <libsbp/internal/new/string/multipart.h>
#include <libsbp/internal/new/string/null_terminated.h>
#include <libsbp/internal/new/string/double_null_terminated.h>
#include <libsbp/internal/new/string/unterminated.h>

size_t sbp_packed_size_sbp_msg_startup_t(const sbp_msg_startup_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u8(&msg->cause);
  packed_size += sbp_packed_size_u8(&msg->startup_type);
  packed_size += sbp_packed_size_u16(&msg->reserved);
  return packed_size;
}

bool encode_sbp_msg_startup_t(sbp_encode_ctx_t *ctx, const sbp_msg_startup_t *msg)
{
  if (!encode_u8(ctx, &msg->cause)) { return false; }
  if (!encode_u8(ctx, &msg->startup_type)) { return false; }
  if (!encode_u16(ctx, &msg->reserved)) { return false; }
  return true;
}

s8 sbp_encode_sbp_msg_startup_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_startup_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!encode_sbp_msg_startup_t(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool decode_sbp_msg_startup_t(sbp_decode_ctx_t *ctx, sbp_msg_startup_t *msg)
{
  if (!decode_u8(ctx, &msg->cause)) { return false; }
  if (!decode_u8(ctx, &msg->startup_type)) { return false; }
  if (!decode_u16(ctx, &msg->reserved)) { return false; }
  return true;
}

s8 sbp_decode_sbp_msg_startup_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_startup_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!decode_sbp_msg_startup_t(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}
s8 sbp_send_sbp_msg_startup_t(struct sbp_state *s, u16 sender_id, const sbp_msg_startup_t *msg, s32 (*write)(u8 *buff, u32 n, void *context))
{
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_encode_sbp_msg_startup_t(payload, sizeof(payload), &payload_len, msg);
  if (ret != SBP_OK) { return ret; }
  return sbp_payload_send(s, SBP_MSG_STARTUP, sender_id, payload_len, payload, write);
}

int sbp_cmp_sbp_msg_startup_t(const sbp_msg_startup_t *a, const sbp_msg_startup_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u8(&a->cause, &b->cause);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->startup_type, &b->startup_type);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->reserved, &b->reserved);
  if (ret != 0) { return ret; }
  return ret;
}
static const sbp_unterminated_string_params_t sbp_msg_dgnss_status_tsource_params = 
{
  .max_packed_len = 251
};

  void sbp_msg_dgnss_status_t_source_init(sbp_unterminated_string_t *s)
{
  sbp_unterminated_string_init(s, &sbp_msg_dgnss_status_tsource_params);
}

  bool sbp_msg_dgnss_status_t_source_valid(const sbp_unterminated_string_t *s)
{
  return sbp_unterminated_string_valid(s, &sbp_msg_dgnss_status_tsource_params);
}

  int sbp_msg_dgnss_status_t_source_strcmp(const sbp_unterminated_string_t *a, const sbp_unterminated_string_t *b)
{
  return sbp_unterminated_string_strcmp(a, b, &sbp_msg_dgnss_status_tsource_params);
}

  uint8_t sbp_msg_dgnss_status_t_source_packed_len(const sbp_unterminated_string_t *s)
{
  return sbp_unterminated_string_packed_len(s, &sbp_msg_dgnss_status_tsource_params);
}

  uint8_t sbp_msg_dgnss_status_t_source_space_remaining(const sbp_unterminated_string_t *s)
{
  return sbp_unterminated_string_space_remaining(s, &sbp_msg_dgnss_status_tsource_params);
      }
  bool sbp_msg_dgnss_status_t_source_set(sbp_unterminated_string_t *s, const char *new_str)
  {
  return sbp_unterminated_string_set(s, &sbp_msg_dgnss_status_tsource_params, new_str);
  }

  bool sbp_msg_dgnss_status_t_source_printf(sbp_unterminated_string_t *s, const char *fmt, ...) 
  {
  va_list ap;
  va_start(ap, fmt);
  bool ret = sbp_unterminated_string_vprintf(s, &sbp_msg_dgnss_status_tsource_params, fmt, ap);
  va_end(ap);
  return ret;
  }

  bool sbp_msg_dgnss_status_t_source_vprintf(sbp_unterminated_string_t *s, const char *fmt, va_list ap)
  {
  return sbp_unterminated_string_vprintf(s, &sbp_msg_dgnss_status_tsource_params, fmt, ap);
  }

  bool sbp_msg_dgnss_status_t_source_append_printf(sbp_unterminated_string_t *s, const char *fmt, ...) 
{
  va_list ap;
  va_start(ap, fmt);
  bool ret = sbp_unterminated_string_append_vprintf(s, &sbp_msg_dgnss_status_tsource_params, fmt, ap);
  va_end(ap);
  return ret;
}

  bool sbp_msg_dgnss_status_t_source_append_vprintf(sbp_unterminated_string_t *s, const char *fmt, va_list ap)
{
  return sbp_unterminated_string_append_vprintf(s, &sbp_msg_dgnss_status_tsource_params, fmt, ap);
}

  const char *sbp_msg_dgnss_status_t_source_get(const sbp_unterminated_string_t *s)
{
  return sbp_unterminated_string_get(s, &sbp_msg_dgnss_status_tsource_params);
}

size_t sbp_packed_size_sbp_msg_dgnss_status_t(const sbp_msg_dgnss_status_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u8(&msg->flags);
  packed_size += sbp_packed_size_u16(&msg->latency);
  packed_size += sbp_packed_size_u8(&msg->num_signals);
  packed_size += sbp_unterminated_string_packed_len(&msg->source, &sbp_msg_dgnss_status_tsource_params);
  return packed_size;
}

bool encode_sbp_msg_dgnss_status_t(sbp_encode_ctx_t *ctx, const sbp_msg_dgnss_status_t *msg)
{
  if (!encode_u8(ctx, &msg->flags)) { return false; }
  if (!encode_u16(ctx, &msg->latency)) { return false; }
  if (!encode_u8(ctx, &msg->num_signals)) { return false; }
  if (!sbp_unterminated_string_pack(&msg->source, &sbp_msg_dgnss_status_tsource_params, ctx)) { return false; }
  return true;
}

s8 sbp_encode_sbp_msg_dgnss_status_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_dgnss_status_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!encode_sbp_msg_dgnss_status_t(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool decode_sbp_msg_dgnss_status_t(sbp_decode_ctx_t *ctx, sbp_msg_dgnss_status_t *msg)
{
  if (!decode_u8(ctx, &msg->flags)) { return false; }
  if (!decode_u16(ctx, &msg->latency)) { return false; }
  if (!decode_u8(ctx, &msg->num_signals)) { return false; }
  if (!sbp_unterminated_string_unpack(&msg->source, &sbp_msg_dgnss_status_tsource_params, ctx)) { return false; }
  return true;
}

s8 sbp_decode_sbp_msg_dgnss_status_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_dgnss_status_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!decode_sbp_msg_dgnss_status_t(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}
s8 sbp_send_sbp_msg_dgnss_status_t(struct sbp_state *s, u16 sender_id, const sbp_msg_dgnss_status_t *msg, s32 (*write)(u8 *buff, u32 n, void *context))
{
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_encode_sbp_msg_dgnss_status_t(payload, sizeof(payload), &payload_len, msg);
  if (ret != SBP_OK) { return ret; }
  return sbp_payload_send(s, SBP_MSG_DGNSS_STATUS, sender_id, payload_len, payload, write);
}

int sbp_cmp_sbp_msg_dgnss_status_t(const sbp_msg_dgnss_status_t *a, const sbp_msg_dgnss_status_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u8(&a->flags, &b->flags);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->latency, &b->latency);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->num_signals, &b->num_signals);
  if (ret != 0) { return ret; }
  
  ret = sbp_unterminated_string_strcmp(&a->source, &b->source, &sbp_msg_dgnss_status_tsource_params);
  if (ret != 0) { return ret; }
  return ret;
}

size_t sbp_packed_size_sbp_msg_heartbeat_t(const sbp_msg_heartbeat_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u32(&msg->flags);
  return packed_size;
}

bool encode_sbp_msg_heartbeat_t(sbp_encode_ctx_t *ctx, const sbp_msg_heartbeat_t *msg)
{
  if (!encode_u32(ctx, &msg->flags)) { return false; }
  return true;
}

s8 sbp_encode_sbp_msg_heartbeat_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_heartbeat_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!encode_sbp_msg_heartbeat_t(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool decode_sbp_msg_heartbeat_t(sbp_decode_ctx_t *ctx, sbp_msg_heartbeat_t *msg)
{
  if (!decode_u32(ctx, &msg->flags)) { return false; }
  return true;
}

s8 sbp_decode_sbp_msg_heartbeat_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_heartbeat_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!decode_sbp_msg_heartbeat_t(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}
s8 sbp_send_sbp_msg_heartbeat_t(struct sbp_state *s, u16 sender_id, const sbp_msg_heartbeat_t *msg, s32 (*write)(u8 *buff, u32 n, void *context))
{
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_encode_sbp_msg_heartbeat_t(payload, sizeof(payload), &payload_len, msg);
  if (ret != SBP_OK) { return ret; }
  return sbp_payload_send(s, SBP_MSG_HEARTBEAT, sender_id, payload_len, payload, write);
}

int sbp_cmp_sbp_msg_heartbeat_t(const sbp_msg_heartbeat_t *a, const sbp_msg_heartbeat_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u32(&a->flags, &b->flags);
  if (ret != 0) { return ret; }
  return ret;
}

size_t sbp_packed_size_sbp_sub_system_report_t(const sbp_sub_system_report_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u16(&msg->component);
  packed_size += sbp_packed_size_u8(&msg->generic);
  packed_size += sbp_packed_size_u8(&msg->specific);
  return packed_size;
}

bool encode_sbp_sub_system_report_t(sbp_encode_ctx_t *ctx, const sbp_sub_system_report_t *msg)
{
  if (!encode_u16(ctx, &msg->component)) { return false; }
  if (!encode_u8(ctx, &msg->generic)) { return false; }
  if (!encode_u8(ctx, &msg->specific)) { return false; }
  return true;
}

s8 sbp_encode_sbp_sub_system_report_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_sub_system_report_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!encode_sbp_sub_system_report_t(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool decode_sbp_sub_system_report_t(sbp_decode_ctx_t *ctx, sbp_sub_system_report_t *msg)
{
  if (!decode_u16(ctx, &msg->component)) { return false; }
  if (!decode_u8(ctx, &msg->generic)) { return false; }
  if (!decode_u8(ctx, &msg->specific)) { return false; }
  return true;
}

s8 sbp_decode_sbp_sub_system_report_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_sub_system_report_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!decode_sbp_sub_system_report_t(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

int sbp_cmp_sbp_sub_system_report_t(const sbp_sub_system_report_t *a, const sbp_sub_system_report_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u16(&a->component, &b->component);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->generic, &b->generic);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->specific, &b->specific);
  if (ret != 0) { return ret; }
  return ret;
}

size_t sbp_packed_size_sbp_msg_status_report_t(const sbp_msg_status_report_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u16(&msg->reporting_system);
  packed_size += sbp_packed_size_u16(&msg->sbp_version);
  packed_size += sbp_packed_size_u32(&msg->sequence);
  packed_size += sbp_packed_size_u32(&msg->uptime);
  packed_size += (msg->n_status * sbp_packed_size_sbp_sub_system_report_t(&msg->status[0]));
  return packed_size;
}

bool encode_sbp_msg_status_report_t(sbp_encode_ctx_t *ctx, const sbp_msg_status_report_t *msg)
{
  if (!encode_u16(ctx, &msg->reporting_system)) { return false; }
  if (!encode_u16(ctx, &msg->sbp_version)) { return false; }
  if (!encode_u32(ctx, &msg->sequence)) { return false; }
  if (!encode_u32(ctx, &msg->uptime)) { return false; }
  for (uint8_t i = 0; i < msg->n_status; i++)
  {
    if (!encode_sbp_sub_system_report_t(ctx, &msg->status[i])) { return false; }
  }
  return true;
}

s8 sbp_encode_sbp_msg_status_report_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_status_report_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!encode_sbp_msg_status_report_t(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool decode_sbp_msg_status_report_t(sbp_decode_ctx_t *ctx, sbp_msg_status_report_t *msg)
{
  if (!decode_u16(ctx, &msg->reporting_system)) { return false; }
  if (!decode_u16(ctx, &msg->sbp_version)) { return false; }
  if (!decode_u32(ctx, &msg->sequence)) { return false; }
  if (!decode_u32(ctx, &msg->uptime)) { return false; }
    msg->n_status = (uint8_t)((ctx->buf_len - ctx->offset) / sbp_packed_size_sbp_sub_system_report_t(&msg->status[0]));
  for (uint8_t i = 0; i < msg->n_status; i++) {
    if (!decode_sbp_sub_system_report_t(ctx, &msg->status[i])) { return false; }
  }
  return true;
}

s8 sbp_decode_sbp_msg_status_report_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_status_report_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!decode_sbp_msg_status_report_t(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}
s8 sbp_send_sbp_msg_status_report_t(struct sbp_state *s, u16 sender_id, const sbp_msg_status_report_t *msg, s32 (*write)(u8 *buff, u32 n, void *context))
{
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_encode_sbp_msg_status_report_t(payload, sizeof(payload), &payload_len, msg);
  if (ret != SBP_OK) { return ret; }
  return sbp_payload_send(s, SBP_MSG_STATUS_REPORT, sender_id, payload_len, payload, write);
}

int sbp_cmp_sbp_msg_status_report_t(const sbp_msg_status_report_t *a, const sbp_msg_status_report_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u16(&a->reporting_system, &b->reporting_system);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->sbp_version, &b->sbp_version);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u32(&a->sequence, &b->sequence);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u32(&a->uptime, &b->uptime);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->n_status, &b->n_status);
  for (uint8_t i = 0; i < a->n_status && ret == 0; i++)
  {
    ret = sbp_cmp_sbp_sub_system_report_t(&a->status[i], &b->status[i]);
  }
  if (ret != 0) { return ret; }
  return ret;
}

size_t sbp_packed_size_sbp_msg_ins_status_t(const sbp_msg_ins_status_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u32(&msg->flags);
  return packed_size;
}

bool encode_sbp_msg_ins_status_t(sbp_encode_ctx_t *ctx, const sbp_msg_ins_status_t *msg)
{
  if (!encode_u32(ctx, &msg->flags)) { return false; }
  return true;
}

s8 sbp_encode_sbp_msg_ins_status_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_ins_status_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!encode_sbp_msg_ins_status_t(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool decode_sbp_msg_ins_status_t(sbp_decode_ctx_t *ctx, sbp_msg_ins_status_t *msg)
{
  if (!decode_u32(ctx, &msg->flags)) { return false; }
  return true;
}

s8 sbp_decode_sbp_msg_ins_status_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_ins_status_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!decode_sbp_msg_ins_status_t(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}
s8 sbp_send_sbp_msg_ins_status_t(struct sbp_state *s, u16 sender_id, const sbp_msg_ins_status_t *msg, s32 (*write)(u8 *buff, u32 n, void *context))
{
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_encode_sbp_msg_ins_status_t(payload, sizeof(payload), &payload_len, msg);
  if (ret != SBP_OK) { return ret; }
  return sbp_payload_send(s, SBP_MSG_INS_STATUS, sender_id, payload_len, payload, write);
}

int sbp_cmp_sbp_msg_ins_status_t(const sbp_msg_ins_status_t *a, const sbp_msg_ins_status_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u32(&a->flags, &b->flags);
  if (ret != 0) { return ret; }
  return ret;
}
static const sbp_unterminated_string_params_t sbp_msg_csac_telemetry_ttelemetry_params = 
{
  .max_packed_len = 254
};

  void sbp_msg_csac_telemetry_t_telemetry_init(sbp_unterminated_string_t *s)
{
  sbp_unterminated_string_init(s, &sbp_msg_csac_telemetry_ttelemetry_params);
}

  bool sbp_msg_csac_telemetry_t_telemetry_valid(const sbp_unterminated_string_t *s)
{
  return sbp_unterminated_string_valid(s, &sbp_msg_csac_telemetry_ttelemetry_params);
}

  int sbp_msg_csac_telemetry_t_telemetry_strcmp(const sbp_unterminated_string_t *a, const sbp_unterminated_string_t *b)
{
  return sbp_unterminated_string_strcmp(a, b, &sbp_msg_csac_telemetry_ttelemetry_params);
}

  uint8_t sbp_msg_csac_telemetry_t_telemetry_packed_len(const sbp_unterminated_string_t *s)
{
  return sbp_unterminated_string_packed_len(s, &sbp_msg_csac_telemetry_ttelemetry_params);
}

  uint8_t sbp_msg_csac_telemetry_t_telemetry_space_remaining(const sbp_unterminated_string_t *s)
{
  return sbp_unterminated_string_space_remaining(s, &sbp_msg_csac_telemetry_ttelemetry_params);
      }
  bool sbp_msg_csac_telemetry_t_telemetry_set(sbp_unterminated_string_t *s, const char *new_str)
  {
  return sbp_unterminated_string_set(s, &sbp_msg_csac_telemetry_ttelemetry_params, new_str);
  }

  bool sbp_msg_csac_telemetry_t_telemetry_printf(sbp_unterminated_string_t *s, const char *fmt, ...) 
  {
  va_list ap;
  va_start(ap, fmt);
  bool ret = sbp_unterminated_string_vprintf(s, &sbp_msg_csac_telemetry_ttelemetry_params, fmt, ap);
  va_end(ap);
  return ret;
  }

  bool sbp_msg_csac_telemetry_t_telemetry_vprintf(sbp_unterminated_string_t *s, const char *fmt, va_list ap)
  {
  return sbp_unterminated_string_vprintf(s, &sbp_msg_csac_telemetry_ttelemetry_params, fmt, ap);
  }

  bool sbp_msg_csac_telemetry_t_telemetry_append_printf(sbp_unterminated_string_t *s, const char *fmt, ...) 
{
  va_list ap;
  va_start(ap, fmt);
  bool ret = sbp_unterminated_string_append_vprintf(s, &sbp_msg_csac_telemetry_ttelemetry_params, fmt, ap);
  va_end(ap);
  return ret;
}

  bool sbp_msg_csac_telemetry_t_telemetry_append_vprintf(sbp_unterminated_string_t *s, const char *fmt, va_list ap)
{
  return sbp_unterminated_string_append_vprintf(s, &sbp_msg_csac_telemetry_ttelemetry_params, fmt, ap);
}

  const char *sbp_msg_csac_telemetry_t_telemetry_get(const sbp_unterminated_string_t *s)
{
  return sbp_unterminated_string_get(s, &sbp_msg_csac_telemetry_ttelemetry_params);
}

size_t sbp_packed_size_sbp_msg_csac_telemetry_t(const sbp_msg_csac_telemetry_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u8(&msg->id);
  packed_size += sbp_unterminated_string_packed_len(&msg->telemetry, &sbp_msg_csac_telemetry_ttelemetry_params);
  return packed_size;
}

bool encode_sbp_msg_csac_telemetry_t(sbp_encode_ctx_t *ctx, const sbp_msg_csac_telemetry_t *msg)
{
  if (!encode_u8(ctx, &msg->id)) { return false; }
  if (!sbp_unterminated_string_pack(&msg->telemetry, &sbp_msg_csac_telemetry_ttelemetry_params, ctx)) { return false; }
  return true;
}

s8 sbp_encode_sbp_msg_csac_telemetry_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_csac_telemetry_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!encode_sbp_msg_csac_telemetry_t(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool decode_sbp_msg_csac_telemetry_t(sbp_decode_ctx_t *ctx, sbp_msg_csac_telemetry_t *msg)
{
  if (!decode_u8(ctx, &msg->id)) { return false; }
  if (!sbp_unterminated_string_unpack(&msg->telemetry, &sbp_msg_csac_telemetry_ttelemetry_params, ctx)) { return false; }
  return true;
}

s8 sbp_decode_sbp_msg_csac_telemetry_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_csac_telemetry_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!decode_sbp_msg_csac_telemetry_t(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}
s8 sbp_send_sbp_msg_csac_telemetry_t(struct sbp_state *s, u16 sender_id, const sbp_msg_csac_telemetry_t *msg, s32 (*write)(u8 *buff, u32 n, void *context))
{
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_encode_sbp_msg_csac_telemetry_t(payload, sizeof(payload), &payload_len, msg);
  if (ret != SBP_OK) { return ret; }
  return sbp_payload_send(s, SBP_MSG_CSAC_TELEMETRY, sender_id, payload_len, payload, write);
}

int sbp_cmp_sbp_msg_csac_telemetry_t(const sbp_msg_csac_telemetry_t *a, const sbp_msg_csac_telemetry_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u8(&a->id, &b->id);
  if (ret != 0) { return ret; }
  
  ret = sbp_unterminated_string_strcmp(&a->telemetry, &b->telemetry, &sbp_msg_csac_telemetry_ttelemetry_params);
  if (ret != 0) { return ret; }
  return ret;
}
static const sbp_unterminated_string_params_t sbp_msg_csac_telemetry_labels_ttelemetry_labels_params = 
{
  .max_packed_len = 254
};

  void sbp_msg_csac_telemetry_labels_t_telemetry_labels_init(sbp_unterminated_string_t *s)
{
  sbp_unterminated_string_init(s, &sbp_msg_csac_telemetry_labels_ttelemetry_labels_params);
}

  bool sbp_msg_csac_telemetry_labels_t_telemetry_labels_valid(const sbp_unterminated_string_t *s)
{
  return sbp_unterminated_string_valid(s, &sbp_msg_csac_telemetry_labels_ttelemetry_labels_params);
}

  int sbp_msg_csac_telemetry_labels_t_telemetry_labels_strcmp(const sbp_unterminated_string_t *a, const sbp_unterminated_string_t *b)
{
  return sbp_unterminated_string_strcmp(a, b, &sbp_msg_csac_telemetry_labels_ttelemetry_labels_params);
}

  uint8_t sbp_msg_csac_telemetry_labels_t_telemetry_labels_packed_len(const sbp_unterminated_string_t *s)
{
  return sbp_unterminated_string_packed_len(s, &sbp_msg_csac_telemetry_labels_ttelemetry_labels_params);
}

  uint8_t sbp_msg_csac_telemetry_labels_t_telemetry_labels_space_remaining(const sbp_unterminated_string_t *s)
{
  return sbp_unterminated_string_space_remaining(s, &sbp_msg_csac_telemetry_labels_ttelemetry_labels_params);
      }
  bool sbp_msg_csac_telemetry_labels_t_telemetry_labels_set(sbp_unterminated_string_t *s, const char *new_str)
  {
  return sbp_unterminated_string_set(s, &sbp_msg_csac_telemetry_labels_ttelemetry_labels_params, new_str);
  }

  bool sbp_msg_csac_telemetry_labels_t_telemetry_labels_printf(sbp_unterminated_string_t *s, const char *fmt, ...) 
  {
  va_list ap;
  va_start(ap, fmt);
  bool ret = sbp_unterminated_string_vprintf(s, &sbp_msg_csac_telemetry_labels_ttelemetry_labels_params, fmt, ap);
  va_end(ap);
  return ret;
  }

  bool sbp_msg_csac_telemetry_labels_t_telemetry_labels_vprintf(sbp_unterminated_string_t *s, const char *fmt, va_list ap)
  {
  return sbp_unterminated_string_vprintf(s, &sbp_msg_csac_telemetry_labels_ttelemetry_labels_params, fmt, ap);
  }

  bool sbp_msg_csac_telemetry_labels_t_telemetry_labels_append_printf(sbp_unterminated_string_t *s, const char *fmt, ...) 
{
  va_list ap;
  va_start(ap, fmt);
  bool ret = sbp_unterminated_string_append_vprintf(s, &sbp_msg_csac_telemetry_labels_ttelemetry_labels_params, fmt, ap);
  va_end(ap);
  return ret;
}

  bool sbp_msg_csac_telemetry_labels_t_telemetry_labels_append_vprintf(sbp_unterminated_string_t *s, const char *fmt, va_list ap)
{
  return sbp_unterminated_string_append_vprintf(s, &sbp_msg_csac_telemetry_labels_ttelemetry_labels_params, fmt, ap);
}

  const char *sbp_msg_csac_telemetry_labels_t_telemetry_labels_get(const sbp_unterminated_string_t *s)
{
  return sbp_unterminated_string_get(s, &sbp_msg_csac_telemetry_labels_ttelemetry_labels_params);
}

size_t sbp_packed_size_sbp_msg_csac_telemetry_labels_t(const sbp_msg_csac_telemetry_labels_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u8(&msg->id);
  packed_size += sbp_unterminated_string_packed_len(&msg->telemetry_labels, &sbp_msg_csac_telemetry_labels_ttelemetry_labels_params);
  return packed_size;
}

bool encode_sbp_msg_csac_telemetry_labels_t(sbp_encode_ctx_t *ctx, const sbp_msg_csac_telemetry_labels_t *msg)
{
  if (!encode_u8(ctx, &msg->id)) { return false; }
  if (!sbp_unterminated_string_pack(&msg->telemetry_labels, &sbp_msg_csac_telemetry_labels_ttelemetry_labels_params, ctx)) { return false; }
  return true;
}

s8 sbp_encode_sbp_msg_csac_telemetry_labels_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_csac_telemetry_labels_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!encode_sbp_msg_csac_telemetry_labels_t(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool decode_sbp_msg_csac_telemetry_labels_t(sbp_decode_ctx_t *ctx, sbp_msg_csac_telemetry_labels_t *msg)
{
  if (!decode_u8(ctx, &msg->id)) { return false; }
  if (!sbp_unterminated_string_unpack(&msg->telemetry_labels, &sbp_msg_csac_telemetry_labels_ttelemetry_labels_params, ctx)) { return false; }
  return true;
}

s8 sbp_decode_sbp_msg_csac_telemetry_labels_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_csac_telemetry_labels_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!decode_sbp_msg_csac_telemetry_labels_t(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}
s8 sbp_send_sbp_msg_csac_telemetry_labels_t(struct sbp_state *s, u16 sender_id, const sbp_msg_csac_telemetry_labels_t *msg, s32 (*write)(u8 *buff, u32 n, void *context))
{
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_encode_sbp_msg_csac_telemetry_labels_t(payload, sizeof(payload), &payload_len, msg);
  if (ret != SBP_OK) { return ret; }
  return sbp_payload_send(s, SBP_MSG_CSAC_TELEMETRY_LABELS, sender_id, payload_len, payload, write);
}

int sbp_cmp_sbp_msg_csac_telemetry_labels_t(const sbp_msg_csac_telemetry_labels_t *a, const sbp_msg_csac_telemetry_labels_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u8(&a->id, &b->id);
  if (ret != 0) { return ret; }
  
  ret = sbp_unterminated_string_strcmp(&a->telemetry_labels, &b->telemetry_labels, &sbp_msg_csac_telemetry_labels_ttelemetry_labels_params);
  if (ret != 0) { return ret; }
  return ret;
}

size_t sbp_packed_size_sbp_msg_ins_updates_t(const sbp_msg_ins_updates_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u32(&msg->tow);
  packed_size += sbp_packed_size_u8(&msg->gnsspos);
  packed_size += sbp_packed_size_u8(&msg->gnssvel);
  packed_size += sbp_packed_size_u8(&msg->wheelticks);
  packed_size += sbp_packed_size_u8(&msg->speed);
  packed_size += sbp_packed_size_u8(&msg->nhc);
  packed_size += sbp_packed_size_u8(&msg->zerovel);
  return packed_size;
}

bool encode_sbp_msg_ins_updates_t(sbp_encode_ctx_t *ctx, const sbp_msg_ins_updates_t *msg)
{
  if (!encode_u32(ctx, &msg->tow)) { return false; }
  if (!encode_u8(ctx, &msg->gnsspos)) { return false; }
  if (!encode_u8(ctx, &msg->gnssvel)) { return false; }
  if (!encode_u8(ctx, &msg->wheelticks)) { return false; }
  if (!encode_u8(ctx, &msg->speed)) { return false; }
  if (!encode_u8(ctx, &msg->nhc)) { return false; }
  if (!encode_u8(ctx, &msg->zerovel)) { return false; }
  return true;
}

s8 sbp_encode_sbp_msg_ins_updates_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_ins_updates_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!encode_sbp_msg_ins_updates_t(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool decode_sbp_msg_ins_updates_t(sbp_decode_ctx_t *ctx, sbp_msg_ins_updates_t *msg)
{
  if (!decode_u32(ctx, &msg->tow)) { return false; }
  if (!decode_u8(ctx, &msg->gnsspos)) { return false; }
  if (!decode_u8(ctx, &msg->gnssvel)) { return false; }
  if (!decode_u8(ctx, &msg->wheelticks)) { return false; }
  if (!decode_u8(ctx, &msg->speed)) { return false; }
  if (!decode_u8(ctx, &msg->nhc)) { return false; }
  if (!decode_u8(ctx, &msg->zerovel)) { return false; }
  return true;
}

s8 sbp_decode_sbp_msg_ins_updates_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_ins_updates_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!decode_sbp_msg_ins_updates_t(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}
s8 sbp_send_sbp_msg_ins_updates_t(struct sbp_state *s, u16 sender_id, const sbp_msg_ins_updates_t *msg, s32 (*write)(u8 *buff, u32 n, void *context))
{
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_encode_sbp_msg_ins_updates_t(payload, sizeof(payload), &payload_len, msg);
  if (ret != SBP_OK) { return ret; }
  return sbp_payload_send(s, SBP_MSG_INS_UPDATES, sender_id, payload_len, payload, write);
}

int sbp_cmp_sbp_msg_ins_updates_t(const sbp_msg_ins_updates_t *a, const sbp_msg_ins_updates_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u32(&a->tow, &b->tow);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->gnsspos, &b->gnsspos);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->gnssvel, &b->gnssvel);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->wheelticks, &b->wheelticks);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->speed, &b->speed);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->nhc, &b->nhc);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->zerovel, &b->zerovel);
  if (ret != 0) { return ret; }
  return ret;
}

size_t sbp_packed_size_sbp_msg_gnss_time_offset_t(const sbp_msg_gnss_time_offset_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_s16(&msg->weeks);
  packed_size += sbp_packed_size_s32(&msg->milliseconds);
  packed_size += sbp_packed_size_s16(&msg->microseconds);
  packed_size += sbp_packed_size_u8(&msg->flags);
  return packed_size;
}

bool encode_sbp_msg_gnss_time_offset_t(sbp_encode_ctx_t *ctx, const sbp_msg_gnss_time_offset_t *msg)
{
  if (!encode_s16(ctx, &msg->weeks)) { return false; }
  if (!encode_s32(ctx, &msg->milliseconds)) { return false; }
  if (!encode_s16(ctx, &msg->microseconds)) { return false; }
  if (!encode_u8(ctx, &msg->flags)) { return false; }
  return true;
}

s8 sbp_encode_sbp_msg_gnss_time_offset_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_gnss_time_offset_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!encode_sbp_msg_gnss_time_offset_t(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool decode_sbp_msg_gnss_time_offset_t(sbp_decode_ctx_t *ctx, sbp_msg_gnss_time_offset_t *msg)
{
  if (!decode_s16(ctx, &msg->weeks)) { return false; }
  if (!decode_s32(ctx, &msg->milliseconds)) { return false; }
  if (!decode_s16(ctx, &msg->microseconds)) { return false; }
  if (!decode_u8(ctx, &msg->flags)) { return false; }
  return true;
}

s8 sbp_decode_sbp_msg_gnss_time_offset_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_gnss_time_offset_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!decode_sbp_msg_gnss_time_offset_t(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}
s8 sbp_send_sbp_msg_gnss_time_offset_t(struct sbp_state *s, u16 sender_id, const sbp_msg_gnss_time_offset_t *msg, s32 (*write)(u8 *buff, u32 n, void *context))
{
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_encode_sbp_msg_gnss_time_offset_t(payload, sizeof(payload), &payload_len, msg);
  if (ret != SBP_OK) { return ret; }
  return sbp_payload_send(s, SBP_MSG_GNSS_TIME_OFFSET, sender_id, payload_len, payload, write);
}

int sbp_cmp_sbp_msg_gnss_time_offset_t(const sbp_msg_gnss_time_offset_t *a, const sbp_msg_gnss_time_offset_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_s16(&a->weeks, &b->weeks);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s32(&a->milliseconds, &b->milliseconds);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s16(&a->microseconds, &b->microseconds);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->flags, &b->flags);
  if (ret != 0) { return ret; }
  return ret;
}

size_t sbp_packed_size_sbp_msg_pps_time_t(const sbp_msg_pps_time_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u64(&msg->time);
  packed_size += sbp_packed_size_u8(&msg->flags);
  return packed_size;
}

bool encode_sbp_msg_pps_time_t(sbp_encode_ctx_t *ctx, const sbp_msg_pps_time_t *msg)
{
  if (!encode_u64(ctx, &msg->time)) { return false; }
  if (!encode_u8(ctx, &msg->flags)) { return false; }
  return true;
}

s8 sbp_encode_sbp_msg_pps_time_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_pps_time_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!encode_sbp_msg_pps_time_t(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool decode_sbp_msg_pps_time_t(sbp_decode_ctx_t *ctx, sbp_msg_pps_time_t *msg)
{
  if (!decode_u64(ctx, &msg->time)) { return false; }
  if (!decode_u8(ctx, &msg->flags)) { return false; }
  return true;
}

s8 sbp_decode_sbp_msg_pps_time_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_pps_time_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!decode_sbp_msg_pps_time_t(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}
s8 sbp_send_sbp_msg_pps_time_t(struct sbp_state *s, u16 sender_id, const sbp_msg_pps_time_t *msg, s32 (*write)(u8 *buff, u32 n, void *context))
{
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_encode_sbp_msg_pps_time_t(payload, sizeof(payload), &payload_len, msg);
  if (ret != SBP_OK) { return ret; }
  return sbp_payload_send(s, SBP_MSG_PPS_TIME, sender_id, payload_len, payload, write);
}

int sbp_cmp_sbp_msg_pps_time_t(const sbp_msg_pps_time_t *a, const sbp_msg_pps_time_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u64(&a->time, &b->time);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->flags, &b->flags);
  if (ret != 0) { return ret; }
  return ret;
}

size_t sbp_packed_size_sbp_msg_group_meta_t(const sbp_msg_group_meta_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u8(&msg->group_id);
  packed_size += sbp_packed_size_u8(&msg->flags);
  packed_size += sbp_packed_size_u8(&msg->n_group_msgs);
  packed_size += (msg->n_group_msgs * sbp_packed_size_u16(&msg->group_msgs[0]));
  return packed_size;
}

bool encode_sbp_msg_group_meta_t(sbp_encode_ctx_t *ctx, const sbp_msg_group_meta_t *msg)
{
  if (!encode_u8(ctx, &msg->group_id)) { return false; }
  if (!encode_u8(ctx, &msg->flags)) { return false; }
  if (!encode_u8(ctx, &msg->n_group_msgs)) { return false; }
  for (uint8_t i = 0; i < msg->n_group_msgs; i++)
  {
    if (!encode_u16(ctx, &msg->group_msgs[i])) { return false; }
  }
  return true;
}

s8 sbp_encode_sbp_msg_group_meta_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_group_meta_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!encode_sbp_msg_group_meta_t(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool decode_sbp_msg_group_meta_t(sbp_decode_ctx_t *ctx, sbp_msg_group_meta_t *msg)
{
  if (!decode_u8(ctx, &msg->group_id)) { return false; }
  if (!decode_u8(ctx, &msg->flags)) { return false; }
  if (!decode_u8(ctx, &msg->n_group_msgs)) { return false; }
    msg->n_group_msgs = (uint8_t)((ctx->buf_len - ctx->offset) / sbp_packed_size_u16(&msg->group_msgs[0]));
  for (uint8_t i = 0; i < msg->n_group_msgs; i++) {
    if (!decode_u16(ctx, &msg->group_msgs[i])) { return false; }
  }
  return true;
}

s8 sbp_decode_sbp_msg_group_meta_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_group_meta_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!decode_sbp_msg_group_meta_t(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}
s8 sbp_send_sbp_msg_group_meta_t(struct sbp_state *s, u16 sender_id, const sbp_msg_group_meta_t *msg, s32 (*write)(u8 *buff, u32 n, void *context))
{
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_encode_sbp_msg_group_meta_t(payload, sizeof(payload), &payload_len, msg);
  if (ret != SBP_OK) { return ret; }
  return sbp_payload_send(s, SBP_MSG_GROUP_META, sender_id, payload_len, payload, write);
}

int sbp_cmp_sbp_msg_group_meta_t(const sbp_msg_group_meta_t *a, const sbp_msg_group_meta_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u8(&a->group_id, &b->group_id);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->flags, &b->flags);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->n_group_msgs, &b->n_group_msgs);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->n_group_msgs, &b->n_group_msgs);
  for (uint8_t i = 0; i < a->n_group_msgs && ret == 0; i++)
  {
    ret = sbp_cmp_u16(&a->group_msgs[i], &b->group_msgs[i]);
  }
  if (ret != 0) { return ret; }
  return ret;
}
