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
#include <libsbp/string.h>
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_startup_t(const sbp_msg_startup_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_u8(&msg->cause);
  packed_size += sbp_packed_size_u8(&msg->startup_type);
  packed_size += sbp_packed_size_u16(&msg->reserved);
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_startup_t(u8 *buf, size_t len, const sbp_msg_startup_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_startup_t(msg) > len) { return false; }
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->cause);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->startup_type);
  offset += sbp_pack_u16(buf + offset, len - offset, &msg->reserved);
  return true;
}

static inline bool sbp_unpack_sbp_msg_startup_t(const uint8_t *buf, size_t len, sbp_msg_startup_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->cause);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->startup_type);
  offset += sbp_unpack_u16(buf + offset, len - offset, &msg->reserved);
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_dgnss_status_t(const sbp_msg_dgnss_status_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_u8(&msg->flags);
  packed_size += sbp_packed_size_u16(&msg->latency);
  packed_size += sbp_packed_size_u8(&msg->num_signals);
  packed_size += sbp_unterminated_string_packed_len(&msg->source, 251
      );
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_dgnss_status_t(u8 *buf, size_t len, const sbp_msg_dgnss_status_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_dgnss_status_t(msg) > len) { return false; }
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->flags);
  offset += sbp_pack_u16(buf + offset, len - offset, &msg->latency);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->num_signals);
  offset += sbp_unterminated_string_pack(&msg->source, 251,
      buf + offset, (uint8_t)(len - offset));
  return true;
}

static inline bool sbp_unpack_sbp_msg_dgnss_status_t(const uint8_t *buf, size_t len, sbp_msg_dgnss_status_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->flags);
  offset += sbp_unpack_u16(buf + offset, len - offset, &msg->latency);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->num_signals);
  offset += sbp_unterminated_string_unpack(&msg->source, 251,
      buf + offset, (uint8_t)(len - offset));
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_heartbeat_t(const sbp_msg_heartbeat_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_u32(&msg->flags);
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_heartbeat_t(u8 *buf, size_t len, const sbp_msg_heartbeat_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_heartbeat_t(msg) > len) { return false; }
  offset += sbp_pack_u32(buf + offset, len - offset, &msg->flags);
  return true;
}

static inline bool sbp_unpack_sbp_msg_heartbeat_t(const uint8_t *buf, size_t len, sbp_msg_heartbeat_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_u32(buf + offset, len - offset, &msg->flags);
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_sub_system_report_t(const sbp_sub_system_report_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_u16(&msg->component);
  packed_size += sbp_packed_size_u8(&msg->generic);
  packed_size += sbp_packed_size_u8(&msg->specific);
  return packed_size;
}

static inline size_t sbp_pack_sbp_sub_system_report_t(u8 *buf, size_t len, const sbp_sub_system_report_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_sub_system_report_t(msg) > len) { return false; }
  offset += sbp_pack_u16(buf + offset, len - offset, &msg->component);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->generic);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->specific);
  return offset;
}

static inline size_t sbp_unpack_sbp_sub_system_report_t(const uint8_t *buf, size_t len, sbp_sub_system_report_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_u16(buf + offset, len - offset, &msg->component);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->generic);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->specific);
  return offset;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_status_report_t(const sbp_msg_status_report_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_u16(&msg->reporting_system);
  packed_size += sbp_packed_size_u16(&msg->sbp_version);
  packed_size += sbp_packed_size_u32(&msg->sequence);
  packed_size += sbp_packed_size_u32(&msg->uptime);
  packed_size += (msg->n_status * sbp_packed_size_sbp_sub_system_report_t(&msg->status[0]));
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_status_report_t(u8 *buf, size_t len, const sbp_msg_status_report_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_status_report_t(msg) > len) { return false; }
  offset += sbp_pack_u16(buf + offset, len - offset, &msg->reporting_system);
  offset += sbp_pack_u16(buf + offset, len - offset, &msg->sbp_version);
  offset += sbp_pack_u32(buf + offset, len - offset, &msg->sequence);
  offset += sbp_pack_u32(buf + offset, len - offset, &msg->uptime);
  for (uint8_t i = 0; i < msg->n_status; i++) 
  {
    offset += sbp_pack_sbp_sub_system_report_t(buf + offset, len - offset, &msg->status[i]);
  }
  return true;
}

static inline bool sbp_unpack_sbp_msg_status_report_t(const uint8_t *buf, size_t len, sbp_msg_status_report_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_u16(buf + offset, len - offset, &msg->reporting_system);
  offset += sbp_unpack_u16(buf + offset, len - offset, &msg->sbp_version);
  offset += sbp_unpack_u32(buf + offset, len - offset, &msg->sequence);
  offset += sbp_unpack_u32(buf + offset, len - offset, &msg->uptime);
  msg->n_status = (uint8_t)((len - offset) / sbp_packed_size_sbp_sub_system_report_t(&msg->status[0]));
  for (uint8_t i = 0; i < msg->n_status; i++)
  {
    offset += sbp_unpack_sbp_sub_system_report_t(buf + offset, len - offset, &msg->status[i]);
  }
  return true;
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_ins_status_t(const sbp_msg_ins_status_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_u32(&msg->flags);
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_ins_status_t(u8 *buf, size_t len, const sbp_msg_ins_status_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_ins_status_t(msg) > len) { return false; }
  offset += sbp_pack_u32(buf + offset, len - offset, &msg->flags);
  return true;
}

static inline bool sbp_unpack_sbp_msg_ins_status_t(const uint8_t *buf, size_t len, sbp_msg_ins_status_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_u32(buf + offset, len - offset, &msg->flags);
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_csac_telemetry_t(const sbp_msg_csac_telemetry_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_u8(&msg->id);
  packed_size += sbp_unterminated_string_packed_len(&msg->telemetry, 254
      );
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_csac_telemetry_t(u8 *buf, size_t len, const sbp_msg_csac_telemetry_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_csac_telemetry_t(msg) > len) { return false; }
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->id);
  offset += sbp_unterminated_string_pack(&msg->telemetry, 254,
      buf + offset, (uint8_t)(len - offset));
  return true;
}

static inline bool sbp_unpack_sbp_msg_csac_telemetry_t(const uint8_t *buf, size_t len, sbp_msg_csac_telemetry_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->id);
  offset += sbp_unterminated_string_unpack(&msg->telemetry, 254,
      buf + offset, (uint8_t)(len - offset));
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_csac_telemetry_labels_t(const sbp_msg_csac_telemetry_labels_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_u8(&msg->id);
  packed_size += sbp_unterminated_string_packed_len(&msg->telemetry_labels, 254
      );
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_csac_telemetry_labels_t(u8 *buf, size_t len, const sbp_msg_csac_telemetry_labels_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_csac_telemetry_labels_t(msg) > len) { return false; }
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->id);
  offset += sbp_unterminated_string_pack(&msg->telemetry_labels, 254,
      buf + offset, (uint8_t)(len - offset));
  return true;
}

static inline bool sbp_unpack_sbp_msg_csac_telemetry_labels_t(const uint8_t *buf, size_t len, sbp_msg_csac_telemetry_labels_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->id);
  offset += sbp_unterminated_string_unpack(&msg->telemetry_labels, 254,
      buf + offset, (uint8_t)(len - offset));
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_ins_updates_t(const sbp_msg_ins_updates_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_u32(&msg->tow);
  packed_size += sbp_packed_size_u8(&msg->gnsspos);
  packed_size += sbp_packed_size_u8(&msg->gnssvel);
  packed_size += sbp_packed_size_u8(&msg->wheelticks);
  packed_size += sbp_packed_size_u8(&msg->speed);
  packed_size += sbp_packed_size_u8(&msg->nhc);
  packed_size += sbp_packed_size_u8(&msg->zerovel);
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_ins_updates_t(u8 *buf, size_t len, const sbp_msg_ins_updates_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_ins_updates_t(msg) > len) { return false; }
  offset += sbp_pack_u32(buf + offset, len - offset, &msg->tow);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->gnsspos);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->gnssvel);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->wheelticks);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->speed);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->nhc);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->zerovel);
  return true;
}

static inline bool sbp_unpack_sbp_msg_ins_updates_t(const uint8_t *buf, size_t len, sbp_msg_ins_updates_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_u32(buf + offset, len - offset, &msg->tow);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->gnsspos);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->gnssvel);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->wheelticks);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->speed);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->nhc);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->zerovel);
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_gnss_time_offset_t(const sbp_msg_gnss_time_offset_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_s16(&msg->weeks);
  packed_size += sbp_packed_size_s32(&msg->milliseconds);
  packed_size += sbp_packed_size_s16(&msg->microseconds);
  packed_size += sbp_packed_size_u8(&msg->flags);
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_gnss_time_offset_t(u8 *buf, size_t len, const sbp_msg_gnss_time_offset_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_gnss_time_offset_t(msg) > len) { return false; }
  offset += sbp_pack_s16(buf + offset, len - offset, &msg->weeks);
  offset += sbp_pack_s32(buf + offset, len - offset, &msg->milliseconds);
  offset += sbp_pack_s16(buf + offset, len - offset, &msg->microseconds);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->flags);
  return true;
}

static inline bool sbp_unpack_sbp_msg_gnss_time_offset_t(const uint8_t *buf, size_t len, sbp_msg_gnss_time_offset_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_s16(buf + offset, len - offset, &msg->weeks);
  offset += sbp_unpack_s32(buf + offset, len - offset, &msg->milliseconds);
  offset += sbp_unpack_s16(buf + offset, len - offset, &msg->microseconds);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->flags);
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_pps_time_t(const sbp_msg_pps_time_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_u64(&msg->time);
  packed_size += sbp_packed_size_u8(&msg->flags);
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_pps_time_t(u8 *buf, size_t len, const sbp_msg_pps_time_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_pps_time_t(msg) > len) { return false; }
  offset += sbp_pack_u64(buf + offset, len - offset, &msg->time);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->flags);
  return true;
}

static inline bool sbp_unpack_sbp_msg_pps_time_t(const uint8_t *buf, size_t len, sbp_msg_pps_time_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_u64(buf + offset, len - offset, &msg->time);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->flags);
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_group_meta_t(const sbp_msg_group_meta_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_u8(&msg->group_id);
  packed_size += sbp_packed_size_u8(&msg->flags);
  packed_size += sbp_packed_size_u8(&msg->n_group_msgs);
  packed_size += (msg->n_group_msgs * sbp_packed_size_u16(&msg->group_msgs[0]));
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_group_meta_t(u8 *buf, size_t len, const sbp_msg_group_meta_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_group_meta_t(msg) > len) { return false; }
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->group_id);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->flags);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->n_group_msgs);
  for (uint8_t i = 0; i < msg->n_group_msgs; i++) 
  {
    offset += sbp_pack_u16(buf + offset, len - offset, &msg->group_msgs[i]);
  }
  return true;
}

static inline bool sbp_unpack_sbp_msg_group_meta_t(const uint8_t *buf, size_t len, sbp_msg_group_meta_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->group_id);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->flags);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->n_group_msgs);
  msg->n_group_msgs = (uint8_t)((len - offset) / sbp_packed_size_u16(&msg->group_msgs[0]));
  for (uint8_t i = 0; i < msg->n_group_msgs; i++)
  {
    offset += sbp_unpack_u16(buf + offset, len - offset, &msg->group_msgs[i]);
  }
  return true;
  return true;
}

#endif
