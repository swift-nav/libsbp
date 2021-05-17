#ifndef LIBSBP_SYSTEM_PACKERS_H
#define LIBSBP_SYSTEM_PACKERS_H

#ifndef LIBSBP_SYSTEM_MESSAGES_H
#error "Do not include this file directly, include libsbp/unpacked/system.h instead"
#endif

#include <stdbool.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>
#include <endian.h>
#include <math.h>

#include <libsbp/common.h>
#include <libsbp/unpacked/base.h>
#include <libsbp/unpacked/common.h>
#include <libsbp/string.h>
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_startup_t(const sbp_msg_startup_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u8(&msg->cause);
  packed_size += sbp_packed_size_u8(&msg->startup_type);
  packed_size += sbp_packed_size_u16(&msg->reserved);
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_startup_t(sbp_pack_ctx_t *ctx, const sbp_msg_startup_t *msg)
{
  if (!sbp_pack_u8(ctx, &msg->cause)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->startup_type)) { return false; }
  if (!sbp_pack_u16(ctx, &msg->reserved)) { return false; }
  return true;
}

static inline bool sbp_unpack_sbp_msg_startup_t(sbp_unpack_ctx_t *ctx, sbp_msg_startup_t *msg)
{
  if (!sbp_unpack_u8(ctx, &msg->cause)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->startup_type)) { return false; }
  if (!sbp_unpack_u16(ctx, &msg->reserved)) { return false; }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_dgnss_status_t(const sbp_msg_dgnss_status_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u8(&msg->flags);
  packed_size += sbp_packed_size_u16(&msg->latency);
  packed_size += sbp_packed_size_u8(&msg->num_signals);
  packed_size += sbp_unterminated_string_packed_len(&msg->source, 251
      );
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_dgnss_status_t(sbp_pack_ctx_t *ctx, const sbp_msg_dgnss_status_t *msg)
{
  if (!sbp_pack_u8(ctx, &msg->flags)) { return false; }
  if (!sbp_pack_u16(ctx, &msg->latency)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->num_signals)) { return false; }
  if (!sbp_unterminated_string_pack(&msg->source, 251,
      ctx)) { return false; }
  return true;
}

static inline bool sbp_unpack_sbp_msg_dgnss_status_t(sbp_unpack_ctx_t *ctx, sbp_msg_dgnss_status_t *msg)
{
  if (!sbp_unpack_u8(ctx, &msg->flags)) { return false; }
  if (!sbp_unpack_u16(ctx, &msg->latency)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->num_signals)) { return false; }
  if (!sbp_unterminated_string_unpack(&msg->source, 251,
      ctx)) { return false; }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_heartbeat_t(const sbp_msg_heartbeat_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u32(&msg->flags);
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_heartbeat_t(sbp_pack_ctx_t *ctx, const sbp_msg_heartbeat_t *msg)
{
  if (!sbp_pack_u32(ctx, &msg->flags)) { return false; }
  return true;
}

static inline bool sbp_unpack_sbp_msg_heartbeat_t(sbp_unpack_ctx_t *ctx, sbp_msg_heartbeat_t *msg)
{
  if (!sbp_unpack_u32(ctx, &msg->flags)) { return false; }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_sub_system_report_t(const sbp_sub_system_report_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u16(&msg->component);
  packed_size += sbp_packed_size_u8(&msg->generic);
  packed_size += sbp_packed_size_u8(&msg->specific);
  return packed_size;
}

static inline bool sbp_pack_sbp_sub_system_report_t(sbp_pack_ctx_t *ctx, const sbp_sub_system_report_t *msg)
{
  if (!sbp_pack_u16(ctx, &msg->component)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->generic)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->specific)) { return false; }
  return true;
}

static inline bool sbp_unpack_sbp_sub_system_report_t(sbp_unpack_ctx_t *ctx, sbp_sub_system_report_t *msg)
{
  if (!sbp_unpack_u16(ctx, &msg->component)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->generic)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->specific)) { return false; }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_status_report_t(const sbp_msg_status_report_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u16(&msg->reporting_system);
  packed_size += sbp_packed_size_u16(&msg->sbp_version);
  packed_size += sbp_packed_size_u32(&msg->sequence);
  packed_size += sbp_packed_size_u32(&msg->uptime);
  packed_size += (msg->n_status * sbp_packed_size_sbp_sub_system_report_t(&msg->status[0]));
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_status_report_t(sbp_pack_ctx_t *ctx, const sbp_msg_status_report_t *msg)
{
  if (!sbp_pack_u16(ctx, &msg->reporting_system)) { return false; }
  if (!sbp_pack_u16(ctx, &msg->sbp_version)) { return false; }
  if (!sbp_pack_u32(ctx, &msg->sequence)) { return false; }
  if (!sbp_pack_u32(ctx, &msg->uptime)) { return false; }
  for (uint8_t i = 0; i < msg->n_status; i++)
  {
    if (!sbp_pack_sbp_sub_system_report_t(ctx, &msg->status[i])) { return false; }
  }
  return true;
}

static inline bool sbp_unpack_sbp_msg_status_report_t(sbp_unpack_ctx_t *ctx, sbp_msg_status_report_t *msg)
{
  if (!sbp_unpack_u16(ctx, &msg->reporting_system)) { return false; }
  if (!sbp_unpack_u16(ctx, &msg->sbp_version)) { return false; }
  if (!sbp_unpack_u32(ctx, &msg->sequence)) { return false; }
  if (!sbp_unpack_u32(ctx, &msg->uptime)) { return false; }
    msg->n_status = (uint8_t)((ctx->buf_len - ctx->offset) / sbp_packed_size_sbp_sub_system_report_t(&msg->status[0]));
  for (uint8_t i = 0; i < msg->n_status; i++) {
    if (!sbp_unpack_sbp_sub_system_report_t(ctx, &msg->status[i])) { return false; }
  }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_ins_status_t(const sbp_msg_ins_status_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u32(&msg->flags);
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_ins_status_t(sbp_pack_ctx_t *ctx, const sbp_msg_ins_status_t *msg)
{
  if (!sbp_pack_u32(ctx, &msg->flags)) { return false; }
  return true;
}

static inline bool sbp_unpack_sbp_msg_ins_status_t(sbp_unpack_ctx_t *ctx, sbp_msg_ins_status_t *msg)
{
  if (!sbp_unpack_u32(ctx, &msg->flags)) { return false; }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_csac_telemetry_t(const sbp_msg_csac_telemetry_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u8(&msg->id);
  packed_size += sbp_unterminated_string_packed_len(&msg->telemetry, 254
      );
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_csac_telemetry_t(sbp_pack_ctx_t *ctx, const sbp_msg_csac_telemetry_t *msg)
{
  if (!sbp_pack_u8(ctx, &msg->id)) { return false; }
  if (!sbp_unterminated_string_pack(&msg->telemetry, 254,
      ctx)) { return false; }
  return true;
}

static inline bool sbp_unpack_sbp_msg_csac_telemetry_t(sbp_unpack_ctx_t *ctx, sbp_msg_csac_telemetry_t *msg)
{
  if (!sbp_unpack_u8(ctx, &msg->id)) { return false; }
  if (!sbp_unterminated_string_unpack(&msg->telemetry, 254,
      ctx)) { return false; }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_csac_telemetry_labels_t(const sbp_msg_csac_telemetry_labels_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u8(&msg->id);
  packed_size += sbp_unterminated_string_packed_len(&msg->telemetry_labels, 254
      );
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_csac_telemetry_labels_t(sbp_pack_ctx_t *ctx, const sbp_msg_csac_telemetry_labels_t *msg)
{
  if (!sbp_pack_u8(ctx, &msg->id)) { return false; }
  if (!sbp_unterminated_string_pack(&msg->telemetry_labels, 254,
      ctx)) { return false; }
  return true;
}

static inline bool sbp_unpack_sbp_msg_csac_telemetry_labels_t(sbp_unpack_ctx_t *ctx, sbp_msg_csac_telemetry_labels_t *msg)
{
  if (!sbp_unpack_u8(ctx, &msg->id)) { return false; }
  if (!sbp_unterminated_string_unpack(&msg->telemetry_labels, 254,
      ctx)) { return false; }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_ins_updates_t(const sbp_msg_ins_updates_t *msg) {
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

static inline bool sbp_pack_sbp_msg_ins_updates_t(sbp_pack_ctx_t *ctx, const sbp_msg_ins_updates_t *msg)
{
  if (!sbp_pack_u32(ctx, &msg->tow)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->gnsspos)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->gnssvel)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->wheelticks)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->speed)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->nhc)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->zerovel)) { return false; }
  return true;
}

static inline bool sbp_unpack_sbp_msg_ins_updates_t(sbp_unpack_ctx_t *ctx, sbp_msg_ins_updates_t *msg)
{
  if (!sbp_unpack_u32(ctx, &msg->tow)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->gnsspos)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->gnssvel)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->wheelticks)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->speed)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->nhc)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->zerovel)) { return false; }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_gnss_time_offset_t(const sbp_msg_gnss_time_offset_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_s16(&msg->weeks);
  packed_size += sbp_packed_size_s32(&msg->milliseconds);
  packed_size += sbp_packed_size_s16(&msg->microseconds);
  packed_size += sbp_packed_size_u8(&msg->flags);
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_gnss_time_offset_t(sbp_pack_ctx_t *ctx, const sbp_msg_gnss_time_offset_t *msg)
{
  if (!sbp_pack_s16(ctx, &msg->weeks)) { return false; }
  if (!sbp_pack_s32(ctx, &msg->milliseconds)) { return false; }
  if (!sbp_pack_s16(ctx, &msg->microseconds)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->flags)) { return false; }
  return true;
}

static inline bool sbp_unpack_sbp_msg_gnss_time_offset_t(sbp_unpack_ctx_t *ctx, sbp_msg_gnss_time_offset_t *msg)
{
  if (!sbp_unpack_s16(ctx, &msg->weeks)) { return false; }
  if (!sbp_unpack_s32(ctx, &msg->milliseconds)) { return false; }
  if (!sbp_unpack_s16(ctx, &msg->microseconds)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->flags)) { return false; }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_pps_time_t(const sbp_msg_pps_time_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u64(&msg->time);
  packed_size += sbp_packed_size_u8(&msg->flags);
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_pps_time_t(sbp_pack_ctx_t *ctx, const sbp_msg_pps_time_t *msg)
{
  if (!sbp_pack_u64(ctx, &msg->time)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->flags)) { return false; }
  return true;
}

static inline bool sbp_unpack_sbp_msg_pps_time_t(sbp_unpack_ctx_t *ctx, sbp_msg_pps_time_t *msg)
{
  if (!sbp_unpack_u64(ctx, &msg->time)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->flags)) { return false; }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_group_meta_t(const sbp_msg_group_meta_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u8(&msg->group_id);
  packed_size += sbp_packed_size_u8(&msg->flags);
  packed_size += sbp_packed_size_u8(&msg->n_group_msgs);
  packed_size += (msg->n_group_msgs * sbp_packed_size_u16(&msg->group_msgs[0]));
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_group_meta_t(sbp_pack_ctx_t *ctx, const sbp_msg_group_meta_t *msg)
{
  if (!sbp_pack_u8(ctx, &msg->group_id)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->flags)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->n_group_msgs)) { return false; }
  for (uint8_t i = 0; i < msg->n_group_msgs; i++)
  {
    if (!sbp_pack_u16(ctx, &msg->group_msgs[i])) { return false; }
  }
  return true;
}

static inline bool sbp_unpack_sbp_msg_group_meta_t(sbp_unpack_ctx_t *ctx, sbp_msg_group_meta_t *msg)
{
  if (!sbp_unpack_u8(ctx, &msg->group_id)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->flags)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->n_group_msgs)) { return false; }
    msg->n_group_msgs = (uint8_t)((ctx->buf_len - ctx->offset) / sbp_packed_size_u16(&msg->group_msgs[0]));
  for (uint8_t i = 0; i < msg->n_group_msgs; i++) {
    if (!sbp_unpack_u16(ctx, &msg->group_msgs[i])) { return false; }
  }
  return true;
}

#endif
