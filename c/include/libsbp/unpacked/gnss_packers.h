#ifndef LIBSBP_GNSS_PACKERS_H
#define LIBSBP_GNSS_PACKERS_H

#include <endian.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>

#include <libsbp/common.h>
#include <libsbp/string2.h>
//#include <libsbp/unpacked/gnss.h>

static inline size_t sbp_packed_size_sbp_sbp_gnss_signal_t(const sbp_sbp_gnss_signal_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->sat) + sizeof(msg->code);
}

static inline bool sbp_pack_sbp_sbp_gnss_signal_t(u8 *buf, size_t len, const sbp_sbp_gnss_signal_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_sbp_gnss_signal_t(msg) > len)
  {
    return false;
  }

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgsat = msg->sat;
  memcpy(buf + offset, &msgsat, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgcode = msg->code;
  memcpy(buf + offset, &msgcode, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline bool sbp_unpack_sbp_sbp_gnss_signal_t(const u8 *buf, size_t len, sbp_sbp_gnss_signal_t *msg)
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
  memcpy(&msg->sat, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->code, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline size_t sbp_packed_size_sbp_sv_id_t(const sbp_sv_id_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->satId) + sizeof(msg->constellation);
}

static inline bool sbp_pack_sbp_sv_id_t(u8 *buf, size_t len, const sbp_sv_id_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_sv_id_t(msg) > len)
  {
    return false;
  }

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgsatId = msg->satId;
  memcpy(buf + offset, &msgsatId, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgconstellation = msg->constellation;
  memcpy(buf + offset, &msgconstellation, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline bool sbp_unpack_sbp_sv_id_t(const u8 *buf, size_t len, sbp_sv_id_t *msg)
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
  memcpy(&msg->satId, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->constellation, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline size_t sbp_packed_size_sbp_gnss_signal_dep_t(const sbp_gnss_signal_dep_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->sat) + sizeof(msg->code) + sizeof(msg->reserved);
}

static inline bool sbp_pack_sbp_gnss_signal_dep_t(u8 *buf, size_t len, const sbp_gnss_signal_dep_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_gnss_signal_dep_t(msg) > len)
  {
    return false;
  }

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgsat = htole16(msg->sat);
  memcpy(buf + offset, &msgsat, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgcode = msg->code;
  memcpy(buf + offset, &msgcode, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgreserved = msg->reserved;
  memcpy(buf + offset, &msgreserved, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline bool sbp_unpack_sbp_gnss_signal_dep_t(const u8 *buf, size_t len, sbp_gnss_signal_dep_t *msg)
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
  memcpy(&msg->sat, buf + offset, 2);
  msg->sat = le16toh(msg->sat);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->code, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->reserved, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline size_t sbp_packed_size_sbp_gps_time_dep_t(const sbp_gps_time_dep_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->tow) + sizeof(msg->wn);
}

static inline bool sbp_pack_sbp_gps_time_dep_t(u8 *buf, size_t len, const sbp_gps_time_dep_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_gps_time_dep_t(msg) > len)
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

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgwn = htole16(msg->wn);
  memcpy(buf + offset, &msgwn, 2);
  // NOLINTNEXTLINE
  offset += 2;
  return true;
}

static inline bool sbp_unpack_sbp_gps_time_dep_t(const u8 *buf, size_t len, sbp_gps_time_dep_t *msg)
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

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->wn, buf + offset, 2);
  msg->wn = le16toh(msg->wn);
  // NOLINTNEXTLINE
  offset += 2;
  return true;
}

static inline size_t sbp_packed_size_sbp_gps_time_sec_t(const sbp_gps_time_sec_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->tow) + sizeof(msg->wn);
}

static inline bool sbp_pack_sbp_gps_time_sec_t(u8 *buf, size_t len, const sbp_gps_time_sec_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_gps_time_sec_t(msg) > len)
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

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgwn = htole16(msg->wn);
  memcpy(buf + offset, &msgwn, 2);
  // NOLINTNEXTLINE
  offset += 2;
  return true;
}

static inline bool sbp_unpack_sbp_gps_time_sec_t(const u8 *buf, size_t len, sbp_gps_time_sec_t *msg)
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

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->wn, buf + offset, 2);
  msg->wn = le16toh(msg->wn);
  // NOLINTNEXTLINE
  offset += 2;
  return true;
}

static inline size_t sbp_packed_size_sbp_sbp_gps_time_t(const sbp_sbp_gps_time_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->tow) + sizeof(msg->ns_residual) + sizeof(msg->wn);
}

static inline bool sbp_pack_sbp_sbp_gps_time_t(u8 *buf, size_t len, const sbp_sbp_gps_time_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_sbp_gps_time_t(msg) > len)
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

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgns_residual = htole32(*(const u32 *)&msg->ns_residual);
  memcpy(buf + offset, &msgns_residual, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgwn = htole16(msg->wn);
  memcpy(buf + offset, &msgwn, 2);
  // NOLINTNEXTLINE
  offset += 2;
  return true;
}

static inline bool sbp_unpack_sbp_sbp_gps_time_t(const u8 *buf, size_t len, sbp_sbp_gps_time_t *msg)
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

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->ns_residual, buf + offset, 4);
  u32 msgns_residual = *(const u32 *)&msg->ns_residual;
  msgns_residual = le32toh(msgns_residual);
  msg->ns_residual = *(const s32 *)&msgns_residual;
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->wn, buf + offset, 2);
  msg->wn = le16toh(msg->wn);
  // NOLINTNEXTLINE
  offset += 2;
  return true;
}

static inline size_t sbp_packed_size_sbp_carrier_phase_t(const sbp_carrier_phase_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->i) + sizeof(msg->f);
}

static inline bool sbp_pack_sbp_carrier_phase_t(u8 *buf, size_t len, const sbp_carrier_phase_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_carrier_phase_t(msg) > len)
  {
    return false;
  }

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgi = htole32(*(const u32 *)&msg->i);
  memcpy(buf + offset, &msgi, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgf = msg->f;
  memcpy(buf + offset, &msgf, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline bool sbp_unpack_sbp_carrier_phase_t(const u8 *buf, size_t len, sbp_carrier_phase_t *msg)
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
  memcpy(&msg->i, buf + offset, 4);
  u32 msgi = *(const u32 *)&msg->i;
  msgi = le32toh(msgi);
  msg->i = *(const s32 *)&msgi;
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->f, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

#endif
