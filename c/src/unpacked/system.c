#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <libsbp/sbp.h>
#include <libsbp/internal/unpacked/common.h>
#include <libsbp/unpacked/system.h>
#include <libsbp/internal/unpacked/system.h>
#include <libsbp/internal/unpacked/string/multipart.h>
#include <libsbp/internal/unpacked/string/null_terminated.h>
#include <libsbp/internal/unpacked/string/sequence.h>
#include <libsbp/internal/unpacked/string/unterminated.h>
#include <libsbp/internal/unpacked/string/binary.h>
                                                                                                              
size_t sbp_packed_size_sbp_msg_startup_t(const sbp_msg_startup_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u8(&msg->cause);
  packed_size += sbp_packed_size_u8(&msg->startup_type);
  packed_size += sbp_packed_size_u16(&msg->reserved);
  return packed_size;
}

bool pack_sbp_msg_startup_t(sbp_pack_ctx_t *ctx, const sbp_msg_startup_t *msg)
{
  if (!pack_u8(ctx, &msg->cause)) { return false; }
  if (!pack_u8(ctx, &msg->startup_type)) { return false; }
  if (!pack_u16(ctx, &msg->reserved)) { return false; }
  return true;
}

s8 sbp_pack_sbp_msg_startup_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_startup_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_msg_startup_t(&ctx, msg)) {
    return SBP_PACK_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_msg_startup_t(sbp_unpack_ctx_t *ctx, sbp_msg_startup_t *msg)
{
  if (!unpack_u8(ctx, &msg->cause)) { return false; }
  if (!unpack_u8(ctx, &msg->startup_type)) { return false; }
  if (!unpack_u16(ctx, &msg->reserved)) { return false; }
  return true;
}

s8 sbp_unpack_sbp_msg_startup_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_startup_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_msg_startup_t(&ctx, msg)) {
    return SBP_UNPACK_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
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
                                                                                                              
size_t sbp_packed_size_sbp_msg_dgnss_status_t(const sbp_msg_dgnss_status_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u8(&msg->flags);
  packed_size += sbp_packed_size_u16(&msg->latency);
  packed_size += sbp_packed_size_u8(&msg->num_signals);
  packed_size += sbp_unterminated_string_packed_len(&msg->source, 251
      );
  return packed_size;
}

bool pack_sbp_msg_dgnss_status_t(sbp_pack_ctx_t *ctx, const sbp_msg_dgnss_status_t *msg)
{
  if (!pack_u8(ctx, &msg->flags)) { return false; }
  if (!pack_u16(ctx, &msg->latency)) { return false; }
  if (!pack_u8(ctx, &msg->num_signals)) { return false; }
  if (!sbp_unterminated_string_pack(&msg->source, 251,
      ctx)) { return false; }
  return true;
}

s8 sbp_pack_sbp_msg_dgnss_status_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_dgnss_status_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_msg_dgnss_status_t(&ctx, msg)) {
    return SBP_PACK_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_msg_dgnss_status_t(sbp_unpack_ctx_t *ctx, sbp_msg_dgnss_status_t *msg)
{
  if (!unpack_u8(ctx, &msg->flags)) { return false; }
  if (!unpack_u16(ctx, &msg->latency)) { return false; }
  if (!unpack_u8(ctx, &msg->num_signals)) { return false; }
  if (!sbp_unterminated_string_unpack(&msg->source, 251,
      ctx)) { return false; }
  return true;
}

s8 sbp_unpack_sbp_msg_dgnss_status_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_dgnss_status_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_msg_dgnss_status_t(&ctx, msg)) {
    return SBP_UNPACK_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

int sbp_cmp_sbp_msg_dgnss_status_t(const sbp_msg_dgnss_status_t *a, const sbp_msg_dgnss_status_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u8(&a->flags, &b->flags);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->latency, &b->latency);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->num_signals, &b->num_signals);
  if (ret != 0) { return ret; }
  
  ret = sbp_unterminated_string_strcmp(&a->source, &b->source, 251
    );
  if (ret != 0) { return ret; }
  return ret;
}
                                                                                                              
size_t sbp_packed_size_sbp_msg_heartbeat_t(const sbp_msg_heartbeat_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u32(&msg->flags);
  return packed_size;
}

bool pack_sbp_msg_heartbeat_t(sbp_pack_ctx_t *ctx, const sbp_msg_heartbeat_t *msg)
{
  if (!pack_u32(ctx, &msg->flags)) { return false; }
  return true;
}

s8 sbp_pack_sbp_msg_heartbeat_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_heartbeat_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_msg_heartbeat_t(&ctx, msg)) {
    return SBP_PACK_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_msg_heartbeat_t(sbp_unpack_ctx_t *ctx, sbp_msg_heartbeat_t *msg)
{
  if (!unpack_u32(ctx, &msg->flags)) { return false; }
  return true;
}

s8 sbp_unpack_sbp_msg_heartbeat_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_heartbeat_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_msg_heartbeat_t(&ctx, msg)) {
    return SBP_UNPACK_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
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

bool pack_sbp_sub_system_report_t(sbp_pack_ctx_t *ctx, const sbp_sub_system_report_t *msg)
{
  if (!pack_u16(ctx, &msg->component)) { return false; }
  if (!pack_u8(ctx, &msg->generic)) { return false; }
  if (!pack_u8(ctx, &msg->specific)) { return false; }
  return true;
}

s8 sbp_pack_sbp_sub_system_report_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_sub_system_report_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_sub_system_report_t(&ctx, msg)) {
    return SBP_PACK_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_sub_system_report_t(sbp_unpack_ctx_t *ctx, sbp_sub_system_report_t *msg)
{
  if (!unpack_u16(ctx, &msg->component)) { return false; }
  if (!unpack_u8(ctx, &msg->generic)) { return false; }
  if (!unpack_u8(ctx, &msg->specific)) { return false; }
  return true;
}

s8 sbp_unpack_sbp_sub_system_report_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_sub_system_report_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_sub_system_report_t(&ctx, msg)) {
    return SBP_UNPACK_ERROR;
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

bool pack_sbp_msg_status_report_t(sbp_pack_ctx_t *ctx, const sbp_msg_status_report_t *msg)
{
  if (!pack_u16(ctx, &msg->reporting_system)) { return false; }
  if (!pack_u16(ctx, &msg->sbp_version)) { return false; }
  if (!pack_u32(ctx, &msg->sequence)) { return false; }
  if (!pack_u32(ctx, &msg->uptime)) { return false; }
  for (uint8_t i = 0; i < msg->n_status; i++)
  {
    if (!pack_sbp_sub_system_report_t(ctx, &msg->status[i])) { return false; }
  }
  return true;
}

s8 sbp_pack_sbp_msg_status_report_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_status_report_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_msg_status_report_t(&ctx, msg)) {
    return SBP_PACK_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_msg_status_report_t(sbp_unpack_ctx_t *ctx, sbp_msg_status_report_t *msg)
{
  if (!unpack_u16(ctx, &msg->reporting_system)) { return false; }
  if (!unpack_u16(ctx, &msg->sbp_version)) { return false; }
  if (!unpack_u32(ctx, &msg->sequence)) { return false; }
  if (!unpack_u32(ctx, &msg->uptime)) { return false; }
    msg->n_status = (uint8_t)((ctx->buf_len - ctx->offset) / sbp_packed_size_sbp_sub_system_report_t(&msg->status[0]));
  for (uint8_t i = 0; i < msg->n_status; i++) {
    if (!unpack_sbp_sub_system_report_t(ctx, &msg->status[i])) { return false; }
  }
  return true;
}

s8 sbp_unpack_sbp_msg_status_report_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_status_report_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_msg_status_report_t(&ctx, msg)) {
    return SBP_UNPACK_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
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

bool pack_sbp_msg_ins_status_t(sbp_pack_ctx_t *ctx, const sbp_msg_ins_status_t *msg)
{
  if (!pack_u32(ctx, &msg->flags)) { return false; }
  return true;
}

s8 sbp_pack_sbp_msg_ins_status_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_ins_status_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_msg_ins_status_t(&ctx, msg)) {
    return SBP_PACK_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_msg_ins_status_t(sbp_unpack_ctx_t *ctx, sbp_msg_ins_status_t *msg)
{
  if (!unpack_u32(ctx, &msg->flags)) { return false; }
  return true;
}

s8 sbp_unpack_sbp_msg_ins_status_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_ins_status_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_msg_ins_status_t(&ctx, msg)) {
    return SBP_UNPACK_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

int sbp_cmp_sbp_msg_ins_status_t(const sbp_msg_ins_status_t *a, const sbp_msg_ins_status_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u32(&a->flags, &b->flags);
  if (ret != 0) { return ret; }
  return ret;
}
                                                                                                              
size_t sbp_packed_size_sbp_msg_csac_telemetry_t(const sbp_msg_csac_telemetry_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u8(&msg->id);
  packed_size += sbp_unterminated_string_packed_len(&msg->telemetry, 254
      );
  return packed_size;
}

bool pack_sbp_msg_csac_telemetry_t(sbp_pack_ctx_t *ctx, const sbp_msg_csac_telemetry_t *msg)
{
  if (!pack_u8(ctx, &msg->id)) { return false; }
  if (!sbp_unterminated_string_pack(&msg->telemetry, 254,
      ctx)) { return false; }
  return true;
}

s8 sbp_pack_sbp_msg_csac_telemetry_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_csac_telemetry_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_msg_csac_telemetry_t(&ctx, msg)) {
    return SBP_PACK_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_msg_csac_telemetry_t(sbp_unpack_ctx_t *ctx, sbp_msg_csac_telemetry_t *msg)
{
  if (!unpack_u8(ctx, &msg->id)) { return false; }
  if (!sbp_unterminated_string_unpack(&msg->telemetry, 254,
      ctx)) { return false; }
  return true;
}

s8 sbp_unpack_sbp_msg_csac_telemetry_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_csac_telemetry_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_msg_csac_telemetry_t(&ctx, msg)) {
    return SBP_UNPACK_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

int sbp_cmp_sbp_msg_csac_telemetry_t(const sbp_msg_csac_telemetry_t *a, const sbp_msg_csac_telemetry_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u8(&a->id, &b->id);
  if (ret != 0) { return ret; }
  
  ret = sbp_unterminated_string_strcmp(&a->telemetry, &b->telemetry, 254
    );
  if (ret != 0) { return ret; }
  return ret;
}
                                                                                                              
size_t sbp_packed_size_sbp_msg_csac_telemetry_labels_t(const sbp_msg_csac_telemetry_labels_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u8(&msg->id);
  packed_size += sbp_unterminated_string_packed_len(&msg->telemetry_labels, 254
      );
  return packed_size;
}

bool pack_sbp_msg_csac_telemetry_labels_t(sbp_pack_ctx_t *ctx, const sbp_msg_csac_telemetry_labels_t *msg)
{
  if (!pack_u8(ctx, &msg->id)) { return false; }
  if (!sbp_unterminated_string_pack(&msg->telemetry_labels, 254,
      ctx)) { return false; }
  return true;
}

s8 sbp_pack_sbp_msg_csac_telemetry_labels_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_csac_telemetry_labels_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_msg_csac_telemetry_labels_t(&ctx, msg)) {
    return SBP_PACK_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_msg_csac_telemetry_labels_t(sbp_unpack_ctx_t *ctx, sbp_msg_csac_telemetry_labels_t *msg)
{
  if (!unpack_u8(ctx, &msg->id)) { return false; }
  if (!sbp_unterminated_string_unpack(&msg->telemetry_labels, 254,
      ctx)) { return false; }
  return true;
}

s8 sbp_unpack_sbp_msg_csac_telemetry_labels_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_csac_telemetry_labels_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_msg_csac_telemetry_labels_t(&ctx, msg)) {
    return SBP_UNPACK_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

int sbp_cmp_sbp_msg_csac_telemetry_labels_t(const sbp_msg_csac_telemetry_labels_t *a, const sbp_msg_csac_telemetry_labels_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u8(&a->id, &b->id);
  if (ret != 0) { return ret; }
  
  ret = sbp_unterminated_string_strcmp(&a->telemetry_labels, &b->telemetry_labels, 254
    );
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

bool pack_sbp_msg_ins_updates_t(sbp_pack_ctx_t *ctx, const sbp_msg_ins_updates_t *msg)
{
  if (!pack_u32(ctx, &msg->tow)) { return false; }
  if (!pack_u8(ctx, &msg->gnsspos)) { return false; }
  if (!pack_u8(ctx, &msg->gnssvel)) { return false; }
  if (!pack_u8(ctx, &msg->wheelticks)) { return false; }
  if (!pack_u8(ctx, &msg->speed)) { return false; }
  if (!pack_u8(ctx, &msg->nhc)) { return false; }
  if (!pack_u8(ctx, &msg->zerovel)) { return false; }
  return true;
}

s8 sbp_pack_sbp_msg_ins_updates_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_ins_updates_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_msg_ins_updates_t(&ctx, msg)) {
    return SBP_PACK_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_msg_ins_updates_t(sbp_unpack_ctx_t *ctx, sbp_msg_ins_updates_t *msg)
{
  if (!unpack_u32(ctx, &msg->tow)) { return false; }
  if (!unpack_u8(ctx, &msg->gnsspos)) { return false; }
  if (!unpack_u8(ctx, &msg->gnssvel)) { return false; }
  if (!unpack_u8(ctx, &msg->wheelticks)) { return false; }
  if (!unpack_u8(ctx, &msg->speed)) { return false; }
  if (!unpack_u8(ctx, &msg->nhc)) { return false; }
  if (!unpack_u8(ctx, &msg->zerovel)) { return false; }
  return true;
}

s8 sbp_unpack_sbp_msg_ins_updates_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_ins_updates_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_msg_ins_updates_t(&ctx, msg)) {
    return SBP_UNPACK_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
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

bool pack_sbp_msg_gnss_time_offset_t(sbp_pack_ctx_t *ctx, const sbp_msg_gnss_time_offset_t *msg)
{
  if (!pack_s16(ctx, &msg->weeks)) { return false; }
  if (!pack_s32(ctx, &msg->milliseconds)) { return false; }
  if (!pack_s16(ctx, &msg->microseconds)) { return false; }
  if (!pack_u8(ctx, &msg->flags)) { return false; }
  return true;
}

s8 sbp_pack_sbp_msg_gnss_time_offset_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_gnss_time_offset_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_msg_gnss_time_offset_t(&ctx, msg)) {
    return SBP_PACK_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_msg_gnss_time_offset_t(sbp_unpack_ctx_t *ctx, sbp_msg_gnss_time_offset_t *msg)
{
  if (!unpack_s16(ctx, &msg->weeks)) { return false; }
  if (!unpack_s32(ctx, &msg->milliseconds)) { return false; }
  if (!unpack_s16(ctx, &msg->microseconds)) { return false; }
  if (!unpack_u8(ctx, &msg->flags)) { return false; }
  return true;
}

s8 sbp_unpack_sbp_msg_gnss_time_offset_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_gnss_time_offset_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_msg_gnss_time_offset_t(&ctx, msg)) {
    return SBP_UNPACK_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
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

bool pack_sbp_msg_pps_time_t(sbp_pack_ctx_t *ctx, const sbp_msg_pps_time_t *msg)
{
  if (!pack_u64(ctx, &msg->time)) { return false; }
  if (!pack_u8(ctx, &msg->flags)) { return false; }
  return true;
}

s8 sbp_pack_sbp_msg_pps_time_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_pps_time_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_msg_pps_time_t(&ctx, msg)) {
    return SBP_PACK_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_msg_pps_time_t(sbp_unpack_ctx_t *ctx, sbp_msg_pps_time_t *msg)
{
  if (!unpack_u64(ctx, &msg->time)) { return false; }
  if (!unpack_u8(ctx, &msg->flags)) { return false; }
  return true;
}

s8 sbp_unpack_sbp_msg_pps_time_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_pps_time_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_msg_pps_time_t(&ctx, msg)) {
    return SBP_UNPACK_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
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

bool pack_sbp_msg_group_meta_t(sbp_pack_ctx_t *ctx, const sbp_msg_group_meta_t *msg)
{
  if (!pack_u8(ctx, &msg->group_id)) { return false; }
  if (!pack_u8(ctx, &msg->flags)) { return false; }
  if (!pack_u8(ctx, &msg->n_group_msgs)) { return false; }
  for (uint8_t i = 0; i < msg->n_group_msgs; i++)
  {
    if (!pack_u16(ctx, &msg->group_msgs[i])) { return false; }
  }
  return true;
}

s8 sbp_pack_sbp_msg_group_meta_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_group_meta_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_msg_group_meta_t(&ctx, msg)) {
    return SBP_PACK_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_msg_group_meta_t(sbp_unpack_ctx_t *ctx, sbp_msg_group_meta_t *msg)
{
  if (!unpack_u8(ctx, &msg->group_id)) { return false; }
  if (!unpack_u8(ctx, &msg->flags)) { return false; }
  if (!unpack_u8(ctx, &msg->n_group_msgs)) { return false; }
    msg->n_group_msgs = (uint8_t)((ctx->buf_len - ctx->offset) / sbp_packed_size_u16(&msg->group_msgs[0]));
  for (uint8_t i = 0; i < msg->n_group_msgs; i++) {
    if (!unpack_u16(ctx, &msg->group_msgs[i])) { return false; }
  }
  return true;
}

s8 sbp_unpack_sbp_msg_group_meta_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_group_meta_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_msg_group_meta_t(&ctx, msg)) {
    return SBP_UNPACK_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
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
