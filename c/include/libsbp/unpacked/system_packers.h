#ifndef LIBSBP_SYSTEM_PACKERS_H
#define LIBSBP_SYSTEM_PACKERS_H

#include <endian.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>

#include <libsbp/common.h>
#include <libsbp/string2.h>
//#include <libsbp/unpacked/system.h>

static inline size_t sbp_packed_size_sbp_msg_startup_t(const sbp_msg_startup_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->cause) + sizeof(msg->startup_type) + sizeof(msg->reserved);
}

static inline bool sbp_pack_sbp_msg_startup_t(u8 *buf, size_t len, const sbp_msg_startup_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_startup_t(msg) > len)
  {
    return false;
  }

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgcause = msg->cause;
  memcpy(buf + offset, &msgcause, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgstartup_type = msg->startup_type;
  memcpy(buf + offset, &msgstartup_type, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgreserved = htole16(msg->reserved);
  memcpy(buf + offset, &msgreserved, 2);
  // NOLINTNEXTLINE
  offset += 2;
  return true;
}

static inline bool sbp_unpack_sbp_msg_startup_t(const u8 *buf, size_t len, sbp_msg_startup_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->cause, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->startup_type, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->reserved, buf + offset, 2);
  msg->reserved = le16toh(msg->reserved);
  // NOLINTNEXTLINE
  offset += 2;
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_dgnss_status_t(const sbp_msg_dgnss_status_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->flags) + sizeof(msg->latency) + sizeof(msg->num_signals) +
         sbp_unterminated_string_packed_len(&msg->source, 251);
}

static inline bool sbp_pack_sbp_msg_dgnss_status_t(u8 *buf, size_t len, const sbp_msg_dgnss_status_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_dgnss_status_t(msg) > len)
  {
    return false;
  }

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgflags = msg->flags;
  memcpy(buf + offset, &msgflags, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msglatency = htole16(msg->latency);
  memcpy(buf + offset, &msglatency, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgnum_signals = msg->num_signals;
  memcpy(buf + offset, &msgnum_signals, 1);
  // NOLINTNEXTLINE
  offset += 1;
  offset += sbp_unterminated_string_pack(&msg->source, 251, buf + offset, (uint8_t)(len - offset));
  return true;
}

static inline bool sbp_unpack_sbp_msg_dgnss_status_t(const u8 *buf, size_t len, sbp_msg_dgnss_status_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->flags, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->latency, buf + offset, 2);
  msg->latency = le16toh(msg->latency);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->num_signals, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
  offset += sbp_unterminated_string_unpack(&msg->source, 251, buf + offset, (uint8_t)(len - offset));
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_heartbeat_t(const sbp_msg_heartbeat_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->flags);
}

static inline bool sbp_pack_sbp_msg_heartbeat_t(u8 *buf, size_t len, const sbp_msg_heartbeat_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_heartbeat_t(msg) > len)
  {
    return false;
  }

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgflags = htole32(msg->flags);
  memcpy(buf + offset, &msgflags, 4);
  // NOLINTNEXTLINE
  offset += 4;
  return true;
}

static inline bool sbp_unpack_sbp_msg_heartbeat_t(const u8 *buf, size_t len, sbp_msg_heartbeat_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->flags, buf + offset, 4);
  msg->flags = le32toh(msg->flags);
  // NOLINTNEXTLINE
  offset += 4;
  return true;
}

static inline size_t sbp_packed_size_sbp_sub_system_report_t(const sbp_sub_system_report_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->component) + sizeof(msg->generic) + sizeof(msg->specific);
}

static inline bool sbp_pack_sbp_sub_system_report_t(u8 *buf, size_t len, const sbp_sub_system_report_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_sub_system_report_t(msg) > len)
  {
    return false;
  }

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgcomponent = htole16(msg->component);
  memcpy(buf + offset, &msgcomponent, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msggeneric = msg->generic;
  memcpy(buf + offset, &msggeneric, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgspecific = msg->specific;
  memcpy(buf + offset, &msgspecific, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline bool sbp_unpack_sbp_sub_system_report_t(const u8 *buf, size_t len, sbp_sub_system_report_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->component, buf + offset, 2);
  msg->component = le16toh(msg->component);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->generic, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->specific, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_status_report_t(const sbp_msg_status_report_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->reporting_system) + sizeof(msg->sbp_version) + sizeof(msg->sequence) + sizeof(msg->uptime) +
         (msg->status_count *
          (0 + sizeof(msg->status[0].component) + sizeof(msg->status[0].generic) + sizeof(msg->status[0].specific)));
}

static inline bool sbp_pack_sbp_msg_status_report_t(u8 *buf, size_t len, const sbp_msg_status_report_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_status_report_t(msg) > len)
  {
    return false;
  }

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgreporting_system = htole16(msg->reporting_system);
  memcpy(buf + offset, &msgreporting_system, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgsbp_version = htole16(msg->sbp_version);
  memcpy(buf + offset, &msgsbp_version, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgsequence = htole32(msg->sequence);
  memcpy(buf + offset, &msgsequence, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msguptime = htole32(msg->uptime);
  memcpy(buf + offset, &msguptime, 4);
  // NOLINTNEXTLINE
  offset += 4;
  for (size_t msgstatus_idx = 0; msgstatus_idx < (size_t)msg->status_count; msgstatus_idx++)
  {

    if (offset + 2 > len)
    {
      return false;
    }
    u16 msgstatusmsgstatus_idxcomponent = htole16(msg->status[msgstatus_idx].component);
    memcpy(buf + offset, &msgstatusmsgstatus_idxcomponent, 2);
    // NOLINTNEXTLINE
    offset += 2;

    if (offset + 1 > len)
    {
      return false;
    }
    u8 msgstatusmsgstatus_idxgeneric = msg->status[msgstatus_idx].generic;
    memcpy(buf + offset, &msgstatusmsgstatus_idxgeneric, 1);
    // NOLINTNEXTLINE
    offset += 1;

    if (offset + 1 > len)
    {
      return false;
    }
    u8 msgstatusmsgstatus_idxspecific = msg->status[msgstatus_idx].specific;
    memcpy(buf + offset, &msgstatusmsgstatus_idxspecific, 1);
    // NOLINTNEXTLINE
    offset += 1;
  }
  return true;
}

static inline bool sbp_unpack_sbp_msg_status_report_t(const u8 *buf, size_t len, sbp_msg_status_report_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->reporting_system, buf + offset, 2);
  msg->reporting_system = le16toh(msg->reporting_system);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->sbp_version, buf + offset, 2);
  msg->sbp_version = le16toh(msg->sbp_version);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->sequence, buf + offset, 4);
  msg->sequence = le32toh(msg->sequence);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->uptime, buf + offset, 4);
  msg->uptime = le32toh(msg->uptime);
  // NOLINTNEXTLINE
  offset += 4;
  msg->status_count = (u8)((len - offset) / 4);

  for (size_t msgstatus_idx = 0; msgstatus_idx < msg->status_count; msgstatus_idx++)
  {

    if (offset + 2 > len)
    {
      return false;
    }
    memcpy(&msg->status[msgstatus_idx].component, buf + offset, 2);
    msg->status[msgstatus_idx].component = le16toh(msg->status[msgstatus_idx].component);
    // NOLINTNEXTLINE
    offset += 2;

    if (offset + 1 > len)
    {
      return false;
    }
    memcpy(&msg->status[msgstatus_idx].generic, buf + offset, 1);
    // NOLINTNEXTLINE
    offset += 1;

    if (offset + 1 > len)
    {
      return false;
    }
    memcpy(&msg->status[msgstatus_idx].specific, buf + offset, 1);
    // NOLINTNEXTLINE
    offset += 1;
  }
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_ins_status_t(const sbp_msg_ins_status_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->flags);
}

static inline bool sbp_pack_sbp_msg_ins_status_t(u8 *buf, size_t len, const sbp_msg_ins_status_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_ins_status_t(msg) > len)
  {
    return false;
  }

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgflags = htole32(msg->flags);
  memcpy(buf + offset, &msgflags, 4);
  // NOLINTNEXTLINE
  offset += 4;
  return true;
}

static inline bool sbp_unpack_sbp_msg_ins_status_t(const u8 *buf, size_t len, sbp_msg_ins_status_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->flags, buf + offset, 4);
  msg->flags = le32toh(msg->flags);
  // NOLINTNEXTLINE
  offset += 4;
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_csac_telemetry_t(const sbp_msg_csac_telemetry_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->id) + sbp_unterminated_string_packed_len(&msg->telemetry, 254);
}

static inline bool sbp_pack_sbp_msg_csac_telemetry_t(u8 *buf, size_t len, const sbp_msg_csac_telemetry_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_csac_telemetry_t(msg) > len)
  {
    return false;
  }

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgid = msg->id;
  memcpy(buf + offset, &msgid, 1);
  // NOLINTNEXTLINE
  offset += 1;
  offset += sbp_unterminated_string_pack(&msg->telemetry, 254, buf + offset, (uint8_t)(len - offset));
  return true;
}

static inline bool sbp_unpack_sbp_msg_csac_telemetry_t(const u8 *buf, size_t len, sbp_msg_csac_telemetry_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->id, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
  offset += sbp_unterminated_string_unpack(&msg->telemetry, 254, buf + offset, (uint8_t)(len - offset));
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_csac_telemetry_labels_t(const sbp_msg_csac_telemetry_labels_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->id) + sbp_unterminated_string_packed_len(&msg->telemetry_labels, 254);
}

static inline bool
sbp_pack_sbp_msg_csac_telemetry_labels_t(u8 *buf, size_t len, const sbp_msg_csac_telemetry_labels_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_csac_telemetry_labels_t(msg) > len)
  {
    return false;
  }

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgid = msg->id;
  memcpy(buf + offset, &msgid, 1);
  // NOLINTNEXTLINE
  offset += 1;
  offset += sbp_unterminated_string_pack(&msg->telemetry_labels, 254, buf + offset, (uint8_t)(len - offset));
  return true;
}

static inline bool
sbp_unpack_sbp_msg_csac_telemetry_labels_t(const u8 *buf, size_t len, sbp_msg_csac_telemetry_labels_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->id, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
  offset += sbp_unterminated_string_unpack(&msg->telemetry_labels, 254, buf + offset, (uint8_t)(len - offset));
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_ins_updates_t(const sbp_msg_ins_updates_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->tow) + sizeof(msg->gnsspos) + sizeof(msg->gnssvel) + sizeof(msg->wheelticks) +
         sizeof(msg->speed) + sizeof(msg->nhc) + sizeof(msg->zerovel);
}

static inline bool sbp_pack_sbp_msg_ins_updates_t(u8 *buf, size_t len, const sbp_msg_ins_updates_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_ins_updates_t(msg) > len)
  {
    return false;
  }

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgtow = htole32(msg->tow);
  memcpy(buf + offset, &msgtow, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msggnsspos = msg->gnsspos;
  memcpy(buf + offset, &msggnsspos, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msggnssvel = msg->gnssvel;
  memcpy(buf + offset, &msggnssvel, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgwheelticks = msg->wheelticks;
  memcpy(buf + offset, &msgwheelticks, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgspeed = msg->speed;
  memcpy(buf + offset, &msgspeed, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgnhc = msg->nhc;
  memcpy(buf + offset, &msgnhc, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgzerovel = msg->zerovel;
  memcpy(buf + offset, &msgzerovel, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline bool sbp_unpack_sbp_msg_ins_updates_t(const u8 *buf, size_t len, sbp_msg_ins_updates_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->tow, buf + offset, 4);
  msg->tow = le32toh(msg->tow);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->gnsspos, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->gnssvel, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->wheelticks, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->speed, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->nhc, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->zerovel, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_gnss_time_offset_t(const sbp_msg_gnss_time_offset_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->weeks) + sizeof(msg->milliseconds) + sizeof(msg->microseconds) + sizeof(msg->flags);
}

static inline bool sbp_pack_sbp_msg_gnss_time_offset_t(u8 *buf, size_t len, const sbp_msg_gnss_time_offset_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_gnss_time_offset_t(msg) > len)
  {
    return false;
  }

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgweeks = htole16(*(const u16 *)&msg->weeks);
  memcpy(buf + offset, &msgweeks, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgmilliseconds = htole32(*(const u32 *)&msg->milliseconds);
  memcpy(buf + offset, &msgmilliseconds, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgmicroseconds = htole16(*(const u16 *)&msg->microseconds);
  memcpy(buf + offset, &msgmicroseconds, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgflags = msg->flags;
  memcpy(buf + offset, &msgflags, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline bool sbp_unpack_sbp_msg_gnss_time_offset_t(const u8 *buf, size_t len, sbp_msg_gnss_time_offset_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->weeks, buf + offset, 2);
  u16 msgweeks = *(const u16 *)&msg->weeks;
  msgweeks = le16toh(msgweeks);
  msg->weeks = *(const s16 *)&msgweeks;
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->milliseconds, buf + offset, 4);
  u32 msgmilliseconds = *(const u32 *)&msg->milliseconds;
  msgmilliseconds = le32toh(msgmilliseconds);
  msg->milliseconds = *(const s32 *)&msgmilliseconds;
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->microseconds, buf + offset, 2);
  u16 msgmicroseconds = *(const u16 *)&msg->microseconds;
  msgmicroseconds = le16toh(msgmicroseconds);
  msg->microseconds = *(const s16 *)&msgmicroseconds;
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->flags, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_group_meta_t(const sbp_msg_group_meta_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->group_id) + sizeof(msg->flags) + sizeof(msg->n_group_msgs) +
         (msg->n_group_msgs * sizeof(msg->group_msgs[0]));
}

static inline bool sbp_pack_sbp_msg_group_meta_t(u8 *buf, size_t len, const sbp_msg_group_meta_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_group_meta_t(msg) > len)
  {
    return false;
  }

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msggroup_id = msg->group_id;
  memcpy(buf + offset, &msggroup_id, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgflags = msg->flags;
  memcpy(buf + offset, &msgflags, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgn_group_msgs = msg->n_group_msgs;
  memcpy(buf + offset, &msgn_group_msgs, 1);
  // NOLINTNEXTLINE
  offset += 1;
  for (size_t msggroup_msgs_idx = 0; msggroup_msgs_idx < (size_t)msg->n_group_msgs; msggroup_msgs_idx++)
  {

    if (offset + 2 > len)
    {
      return false;
    }
    u16 msggroup_msgsmsggroup_msgs_idx = htole16(msg->group_msgs[msggroup_msgs_idx]);
    memcpy(buf + offset, &msggroup_msgsmsggroup_msgs_idx, 2);
    // NOLINTNEXTLINE
    offset += 2;
  }
  return true;
}

static inline bool sbp_unpack_sbp_msg_group_meta_t(const u8 *buf, size_t len, sbp_msg_group_meta_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->group_id, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->flags, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->n_group_msgs, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  for (size_t msggroup_msgs_idx = 0; msggroup_msgs_idx < msg->n_group_msgs; msggroup_msgs_idx++)
  {

    if (offset + 2 > len)
    {
      return false;
    }
    memcpy(&msg->group_msgs[msggroup_msgs_idx], buf + offset, 2);
    msg->group_msgs[msggroup_msgs_idx] = le16toh(msg->group_msgs[msggroup_msgs_idx]);
    // NOLINTNEXTLINE
    offset += 2;
  }
  return true;
}

#endif
