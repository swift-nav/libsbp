#ifndef LIBSBP_NAVIGATION_PACKERS_H
#define LIBSBP_NAVIGATION_PACKERS_H

#include <endian.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>

#include <libsbp/common.h>
#include <libsbp/unpacked/navigation.h>

static inline size_t sbp_packed_size_sbp_msg_gps_time_t(const sbp_msg_gps_time_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->wn) + sizeof(msg->tow) + sizeof(msg->ns_residual) + sizeof(msg->flags);
}

static inline bool sbp_pack_sbp_msg_gps_time_t(u8 *buf, size_t len, const sbp_msg_gps_time_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_gps_time_t(msg) > len)
  {
    return false;
  }

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgwn = htole16(msg->wn);
  memcpy(buf + offset, &msgwn, 2);
  // NOLINTNEXTLINE
  offset += 2;

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

static inline bool sbp_unpack_sbp_msg_gps_time_t(const u8 *buf, size_t len, sbp_msg_gps_time_t *msg)
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
  memcpy(&msg->wn, buf + offset, 2);
  msg->wn = le16toh(msg->wn);
  // NOLINTNEXTLINE
  offset += 2;

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

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->flags, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_gps_time_gnss_t(const sbp_msg_gps_time_gnss_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->wn) + sizeof(msg->tow) + sizeof(msg->ns_residual) + sizeof(msg->flags);
}

static inline bool sbp_pack_sbp_msg_gps_time_gnss_t(u8 *buf, size_t len, const sbp_msg_gps_time_gnss_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_gps_time_gnss_t(msg) > len)
  {
    return false;
  }

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgwn = htole16(msg->wn);
  memcpy(buf + offset, &msgwn, 2);
  // NOLINTNEXTLINE
  offset += 2;

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

static inline bool sbp_unpack_sbp_msg_gps_time_gnss_t(const u8 *buf, size_t len, sbp_msg_gps_time_gnss_t *msg)
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
  memcpy(&msg->wn, buf + offset, 2);
  msg->wn = le16toh(msg->wn);
  // NOLINTNEXTLINE
  offset += 2;

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

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->flags, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_utc_time_t(const sbp_msg_utc_time_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->flags) + sizeof(msg->tow) + sizeof(msg->year) + sizeof(msg->month) + sizeof(msg->day) +
         sizeof(msg->hours) + sizeof(msg->minutes) + sizeof(msg->seconds) + sizeof(msg->ns);
}

static inline bool sbp_pack_sbp_msg_utc_time_t(u8 *buf, size_t len, const sbp_msg_utc_time_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_utc_time_t(msg) > len)
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
  u16 msgyear = htole16(msg->year);
  memcpy(buf + offset, &msgyear, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgmonth = msg->month;
  memcpy(buf + offset, &msgmonth, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgday = msg->day;
  memcpy(buf + offset, &msgday, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msghours = msg->hours;
  memcpy(buf + offset, &msghours, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgminutes = msg->minutes;
  memcpy(buf + offset, &msgminutes, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgseconds = msg->seconds;
  memcpy(buf + offset, &msgseconds, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgns = htole32(msg->ns);
  memcpy(buf + offset, &msgns, 4);
  // NOLINTNEXTLINE
  offset += 4;
  return true;
}

static inline bool sbp_unpack_sbp_msg_utc_time_t(const u8 *buf, size_t len, sbp_msg_utc_time_t *msg)
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
  memcpy(&msg->year, buf + offset, 2);
  msg->year = le16toh(msg->year);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->month, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->day, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->hours, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->minutes, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->seconds, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->ns, buf + offset, 4);
  msg->ns = le32toh(msg->ns);
  // NOLINTNEXTLINE
  offset += 4;
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_utc_time_gnss_t(const sbp_msg_utc_time_gnss_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->flags) + sizeof(msg->tow) + sizeof(msg->year) + sizeof(msg->month) + sizeof(msg->day) +
         sizeof(msg->hours) + sizeof(msg->minutes) + sizeof(msg->seconds) + sizeof(msg->ns);
}

static inline bool sbp_pack_sbp_msg_utc_time_gnss_t(u8 *buf, size_t len, const sbp_msg_utc_time_gnss_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_utc_time_gnss_t(msg) > len)
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
  u16 msgyear = htole16(msg->year);
  memcpy(buf + offset, &msgyear, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgmonth = msg->month;
  memcpy(buf + offset, &msgmonth, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgday = msg->day;
  memcpy(buf + offset, &msgday, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msghours = msg->hours;
  memcpy(buf + offset, &msghours, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgminutes = msg->minutes;
  memcpy(buf + offset, &msgminutes, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgseconds = msg->seconds;
  memcpy(buf + offset, &msgseconds, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgns = htole32(msg->ns);
  memcpy(buf + offset, &msgns, 4);
  // NOLINTNEXTLINE
  offset += 4;
  return true;
}

static inline bool sbp_unpack_sbp_msg_utc_time_gnss_t(const u8 *buf, size_t len, sbp_msg_utc_time_gnss_t *msg)
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
  memcpy(&msg->year, buf + offset, 2);
  msg->year = le16toh(msg->year);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->month, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->day, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->hours, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->minutes, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->seconds, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->ns, buf + offset, 4);
  msg->ns = le32toh(msg->ns);
  // NOLINTNEXTLINE
  offset += 4;
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_dops_t(const sbp_msg_dops_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->tow) + sizeof(msg->gdop) + sizeof(msg->pdop) + sizeof(msg->tdop) + sizeof(msg->hdop) +
         sizeof(msg->vdop) + sizeof(msg->flags);
}

static inline bool sbp_pack_sbp_msg_dops_t(u8 *buf, size_t len, const sbp_msg_dops_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_dops_t(msg) > len)
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
  u16 msggdop = htole16(msg->gdop);
  memcpy(buf + offset, &msggdop, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgpdop = htole16(msg->pdop);
  memcpy(buf + offset, &msgpdop, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgtdop = htole16(msg->tdop);
  memcpy(buf + offset, &msgtdop, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msghdop = htole16(msg->hdop);
  memcpy(buf + offset, &msghdop, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgvdop = htole16(msg->vdop);
  memcpy(buf + offset, &msgvdop, 2);
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

static inline bool sbp_unpack_sbp_msg_dops_t(const u8 *buf, size_t len, sbp_msg_dops_t *msg)
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
  memcpy(&msg->gdop, buf + offset, 2);
  msg->gdop = le16toh(msg->gdop);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->pdop, buf + offset, 2);
  msg->pdop = le16toh(msg->pdop);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->tdop, buf + offset, 2);
  msg->tdop = le16toh(msg->tdop);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->hdop, buf + offset, 2);
  msg->hdop = le16toh(msg->hdop);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->vdop, buf + offset, 2);
  msg->vdop = le16toh(msg->vdop);
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

static inline size_t sbp_packed_size_sbp_msg_pos_ecef_t(const sbp_msg_pos_ecef_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->tow) + sizeof(msg->x) + sizeof(msg->y) + sizeof(msg->z) + sizeof(msg->accuracy) +
         sizeof(msg->n_sats) + sizeof(msg->flags);
}

static inline bool sbp_pack_sbp_msg_pos_ecef_t(u8 *buf, size_t len, const sbp_msg_pos_ecef_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_pos_ecef_t(msg) > len)
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

  if (offset + 8 > len)
  {
    return false;
  }
  double msgx = msg->x;
  memcpy(buf + offset, &msgx, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgy = msg->y;
  memcpy(buf + offset, &msgy, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgz = msg->z;
  memcpy(buf + offset, &msgz, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgaccuracy = htole16(msg->accuracy);
  memcpy(buf + offset, &msgaccuracy, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgn_sats = msg->n_sats;
  memcpy(buf + offset, &msgn_sats, 1);
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
  return true;
}

static inline bool sbp_unpack_sbp_msg_pos_ecef_t(const u8 *buf, size_t len, sbp_msg_pos_ecef_t *msg)
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

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->x, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->y, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->z, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->accuracy, buf + offset, 2);
  msg->accuracy = le16toh(msg->accuracy);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->n_sats, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->flags, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_pos_ecef_cov_t(const sbp_msg_pos_ecef_cov_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->tow) + sizeof(msg->x) + sizeof(msg->y) + sizeof(msg->z) + sizeof(msg->cov_x_x) +
         sizeof(msg->cov_x_y) + sizeof(msg->cov_x_z) + sizeof(msg->cov_y_y) + sizeof(msg->cov_y_z) +
         sizeof(msg->cov_z_z) + sizeof(msg->n_sats) + sizeof(msg->flags);
}

static inline bool sbp_pack_sbp_msg_pos_ecef_cov_t(u8 *buf, size_t len, const sbp_msg_pos_ecef_cov_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_pos_ecef_cov_t(msg) > len)
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

  if (offset + 8 > len)
  {
    return false;
  }
  double msgx = msg->x;
  memcpy(buf + offset, &msgx, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgy = msg->y;
  memcpy(buf + offset, &msgy, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgz = msg->z;
  memcpy(buf + offset, &msgz, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 4 > len)
  {
    return false;
  }
  float msgcov_x_x = msg->cov_x_x;
  memcpy(buf + offset, &msgcov_x_x, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  float msgcov_x_y = msg->cov_x_y;
  memcpy(buf + offset, &msgcov_x_y, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  float msgcov_x_z = msg->cov_x_z;
  memcpy(buf + offset, &msgcov_x_z, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  float msgcov_y_y = msg->cov_y_y;
  memcpy(buf + offset, &msgcov_y_y, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  float msgcov_y_z = msg->cov_y_z;
  memcpy(buf + offset, &msgcov_y_z, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  float msgcov_z_z = msg->cov_z_z;
  memcpy(buf + offset, &msgcov_z_z, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgn_sats = msg->n_sats;
  memcpy(buf + offset, &msgn_sats, 1);
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
  return true;
}

static inline bool sbp_unpack_sbp_msg_pos_ecef_cov_t(const u8 *buf, size_t len, sbp_msg_pos_ecef_cov_t *msg)
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

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->x, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->y, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->z, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->cov_x_x, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->cov_x_y, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->cov_x_z, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->cov_y_y, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->cov_y_z, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->cov_z_z, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->n_sats, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->flags, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_pos_llh_t(const sbp_msg_pos_llh_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->tow) + sizeof(msg->lat) + sizeof(msg->lon) + sizeof(msg->height) + sizeof(msg->h_accuracy) +
         sizeof(msg->v_accuracy) + sizeof(msg->n_sats) + sizeof(msg->flags);
}

static inline bool sbp_pack_sbp_msg_pos_llh_t(u8 *buf, size_t len, const sbp_msg_pos_llh_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_pos_llh_t(msg) > len)
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

  if (offset + 8 > len)
  {
    return false;
  }
  double msglat = msg->lat;
  memcpy(buf + offset, &msglat, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msglon = msg->lon;
  memcpy(buf + offset, &msglon, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgheight = msg->height;
  memcpy(buf + offset, &msgheight, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgh_accuracy = htole16(msg->h_accuracy);
  memcpy(buf + offset, &msgh_accuracy, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgv_accuracy = htole16(msg->v_accuracy);
  memcpy(buf + offset, &msgv_accuracy, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgn_sats = msg->n_sats;
  memcpy(buf + offset, &msgn_sats, 1);
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
  return true;
}

static inline bool sbp_unpack_sbp_msg_pos_llh_t(const u8 *buf, size_t len, sbp_msg_pos_llh_t *msg)
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

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->lat, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->lon, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->height, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->h_accuracy, buf + offset, 2);
  msg->h_accuracy = le16toh(msg->h_accuracy);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->v_accuracy, buf + offset, 2);
  msg->v_accuracy = le16toh(msg->v_accuracy);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->n_sats, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->flags, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_pos_llh_cov_t(const sbp_msg_pos_llh_cov_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->tow) + sizeof(msg->lat) + sizeof(msg->lon) + sizeof(msg->height) + sizeof(msg->cov_n_n) +
         sizeof(msg->cov_n_e) + sizeof(msg->cov_n_d) + sizeof(msg->cov_e_e) + sizeof(msg->cov_e_d) +
         sizeof(msg->cov_d_d) + sizeof(msg->n_sats) + sizeof(msg->flags);
}

static inline bool sbp_pack_sbp_msg_pos_llh_cov_t(u8 *buf, size_t len, const sbp_msg_pos_llh_cov_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_pos_llh_cov_t(msg) > len)
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

  if (offset + 8 > len)
  {
    return false;
  }
  double msglat = msg->lat;
  memcpy(buf + offset, &msglat, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msglon = msg->lon;
  memcpy(buf + offset, &msglon, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgheight = msg->height;
  memcpy(buf + offset, &msgheight, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 4 > len)
  {
    return false;
  }
  float msgcov_n_n = msg->cov_n_n;
  memcpy(buf + offset, &msgcov_n_n, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  float msgcov_n_e = msg->cov_n_e;
  memcpy(buf + offset, &msgcov_n_e, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  float msgcov_n_d = msg->cov_n_d;
  memcpy(buf + offset, &msgcov_n_d, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  float msgcov_e_e = msg->cov_e_e;
  memcpy(buf + offset, &msgcov_e_e, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  float msgcov_e_d = msg->cov_e_d;
  memcpy(buf + offset, &msgcov_e_d, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  float msgcov_d_d = msg->cov_d_d;
  memcpy(buf + offset, &msgcov_d_d, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgn_sats = msg->n_sats;
  memcpy(buf + offset, &msgn_sats, 1);
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
  return true;
}

static inline bool sbp_unpack_sbp_msg_pos_llh_cov_t(const u8 *buf, size_t len, sbp_msg_pos_llh_cov_t *msg)
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

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->lat, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->lon, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->height, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->cov_n_n, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->cov_n_e, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->cov_n_d, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->cov_e_e, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->cov_e_d, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->cov_d_d, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->n_sats, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->flags, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_baseline_ecef_t(const sbp_msg_baseline_ecef_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->tow) + sizeof(msg->x) + sizeof(msg->y) + sizeof(msg->z) + sizeof(msg->accuracy) +
         sizeof(msg->n_sats) + sizeof(msg->flags);
}

static inline bool sbp_pack_sbp_msg_baseline_ecef_t(u8 *buf, size_t len, const sbp_msg_baseline_ecef_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_baseline_ecef_t(msg) > len)
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
  u32 msgx = htole32(*(const u32 *)&msg->x);
  memcpy(buf + offset, &msgx, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgy = htole32(*(const u32 *)&msg->y);
  memcpy(buf + offset, &msgy, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgz = htole32(*(const u32 *)&msg->z);
  memcpy(buf + offset, &msgz, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgaccuracy = htole16(msg->accuracy);
  memcpy(buf + offset, &msgaccuracy, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgn_sats = msg->n_sats;
  memcpy(buf + offset, &msgn_sats, 1);
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
  return true;
}

static inline bool sbp_unpack_sbp_msg_baseline_ecef_t(const u8 *buf, size_t len, sbp_msg_baseline_ecef_t *msg)
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
  memcpy(&msg->x, buf + offset, 4);
  u32 msgx = *(const u32 *)&msg->x;
  msgx = le32toh(msgx);
  msg->x = *(const s32 *)&msgx;
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->y, buf + offset, 4);
  u32 msgy = *(const u32 *)&msg->y;
  msgy = le32toh(msgy);
  msg->y = *(const s32 *)&msgy;
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->z, buf + offset, 4);
  u32 msgz = *(const u32 *)&msg->z;
  msgz = le32toh(msgz);
  msg->z = *(const s32 *)&msgz;
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->accuracy, buf + offset, 2);
  msg->accuracy = le16toh(msg->accuracy);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->n_sats, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->flags, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_baseline_ned_t(const sbp_msg_baseline_ned_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->tow) + sizeof(msg->n) + sizeof(msg->e) + sizeof(msg->d) + sizeof(msg->h_accuracy) +
         sizeof(msg->v_accuracy) + sizeof(msg->n_sats) + sizeof(msg->flags);
}

static inline bool sbp_pack_sbp_msg_baseline_ned_t(u8 *buf, size_t len, const sbp_msg_baseline_ned_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_baseline_ned_t(msg) > len)
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
  u32 msgn = htole32(*(const u32 *)&msg->n);
  memcpy(buf + offset, &msgn, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msge = htole32(*(const u32 *)&msg->e);
  memcpy(buf + offset, &msge, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgd = htole32(*(const u32 *)&msg->d);
  memcpy(buf + offset, &msgd, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgh_accuracy = htole16(msg->h_accuracy);
  memcpy(buf + offset, &msgh_accuracy, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgv_accuracy = htole16(msg->v_accuracy);
  memcpy(buf + offset, &msgv_accuracy, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgn_sats = msg->n_sats;
  memcpy(buf + offset, &msgn_sats, 1);
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
  return true;
}

static inline bool sbp_unpack_sbp_msg_baseline_ned_t(const u8 *buf, size_t len, sbp_msg_baseline_ned_t *msg)
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
  memcpy(&msg->n, buf + offset, 4);
  u32 msgn = *(const u32 *)&msg->n;
  msgn = le32toh(msgn);
  msg->n = *(const s32 *)&msgn;
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->e, buf + offset, 4);
  u32 msge = *(const u32 *)&msg->e;
  msge = le32toh(msge);
  msg->e = *(const s32 *)&msge;
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->d, buf + offset, 4);
  u32 msgd = *(const u32 *)&msg->d;
  msgd = le32toh(msgd);
  msg->d = *(const s32 *)&msgd;
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->h_accuracy, buf + offset, 2);
  msg->h_accuracy = le16toh(msg->h_accuracy);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->v_accuracy, buf + offset, 2);
  msg->v_accuracy = le16toh(msg->v_accuracy);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->n_sats, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->flags, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_vel_ecef_t(const sbp_msg_vel_ecef_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->tow) + sizeof(msg->x) + sizeof(msg->y) + sizeof(msg->z) + sizeof(msg->accuracy) +
         sizeof(msg->n_sats) + sizeof(msg->flags);
}

static inline bool sbp_pack_sbp_msg_vel_ecef_t(u8 *buf, size_t len, const sbp_msg_vel_ecef_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_vel_ecef_t(msg) > len)
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
  u32 msgx = htole32(*(const u32 *)&msg->x);
  memcpy(buf + offset, &msgx, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgy = htole32(*(const u32 *)&msg->y);
  memcpy(buf + offset, &msgy, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgz = htole32(*(const u32 *)&msg->z);
  memcpy(buf + offset, &msgz, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgaccuracy = htole16(msg->accuracy);
  memcpy(buf + offset, &msgaccuracy, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgn_sats = msg->n_sats;
  memcpy(buf + offset, &msgn_sats, 1);
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
  return true;
}

static inline bool sbp_unpack_sbp_msg_vel_ecef_t(const u8 *buf, size_t len, sbp_msg_vel_ecef_t *msg)
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
  memcpy(&msg->x, buf + offset, 4);
  u32 msgx = *(const u32 *)&msg->x;
  msgx = le32toh(msgx);
  msg->x = *(const s32 *)&msgx;
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->y, buf + offset, 4);
  u32 msgy = *(const u32 *)&msg->y;
  msgy = le32toh(msgy);
  msg->y = *(const s32 *)&msgy;
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->z, buf + offset, 4);
  u32 msgz = *(const u32 *)&msg->z;
  msgz = le32toh(msgz);
  msg->z = *(const s32 *)&msgz;
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->accuracy, buf + offset, 2);
  msg->accuracy = le16toh(msg->accuracy);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->n_sats, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->flags, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_vel_ecef_cov_t(const sbp_msg_vel_ecef_cov_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->tow) + sizeof(msg->x) + sizeof(msg->y) + sizeof(msg->z) + sizeof(msg->cov_x_x) +
         sizeof(msg->cov_x_y) + sizeof(msg->cov_x_z) + sizeof(msg->cov_y_y) + sizeof(msg->cov_y_z) +
         sizeof(msg->cov_z_z) + sizeof(msg->n_sats) + sizeof(msg->flags);
}

static inline bool sbp_pack_sbp_msg_vel_ecef_cov_t(u8 *buf, size_t len, const sbp_msg_vel_ecef_cov_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_vel_ecef_cov_t(msg) > len)
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
  u32 msgx = htole32(*(const u32 *)&msg->x);
  memcpy(buf + offset, &msgx, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgy = htole32(*(const u32 *)&msg->y);
  memcpy(buf + offset, &msgy, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgz = htole32(*(const u32 *)&msg->z);
  memcpy(buf + offset, &msgz, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  float msgcov_x_x = msg->cov_x_x;
  memcpy(buf + offset, &msgcov_x_x, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  float msgcov_x_y = msg->cov_x_y;
  memcpy(buf + offset, &msgcov_x_y, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  float msgcov_x_z = msg->cov_x_z;
  memcpy(buf + offset, &msgcov_x_z, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  float msgcov_y_y = msg->cov_y_y;
  memcpy(buf + offset, &msgcov_y_y, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  float msgcov_y_z = msg->cov_y_z;
  memcpy(buf + offset, &msgcov_y_z, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  float msgcov_z_z = msg->cov_z_z;
  memcpy(buf + offset, &msgcov_z_z, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgn_sats = msg->n_sats;
  memcpy(buf + offset, &msgn_sats, 1);
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
  return true;
}

static inline bool sbp_unpack_sbp_msg_vel_ecef_cov_t(const u8 *buf, size_t len, sbp_msg_vel_ecef_cov_t *msg)
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
  memcpy(&msg->x, buf + offset, 4);
  u32 msgx = *(const u32 *)&msg->x;
  msgx = le32toh(msgx);
  msg->x = *(const s32 *)&msgx;
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->y, buf + offset, 4);
  u32 msgy = *(const u32 *)&msg->y;
  msgy = le32toh(msgy);
  msg->y = *(const s32 *)&msgy;
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->z, buf + offset, 4);
  u32 msgz = *(const u32 *)&msg->z;
  msgz = le32toh(msgz);
  msg->z = *(const s32 *)&msgz;
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->cov_x_x, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->cov_x_y, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->cov_x_z, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->cov_y_y, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->cov_y_z, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->cov_z_z, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->n_sats, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->flags, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_vel_ned_t(const sbp_msg_vel_ned_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->tow) + sizeof(msg->n) + sizeof(msg->e) + sizeof(msg->d) + sizeof(msg->h_accuracy) +
         sizeof(msg->v_accuracy) + sizeof(msg->n_sats) + sizeof(msg->flags);
}

static inline bool sbp_pack_sbp_msg_vel_ned_t(u8 *buf, size_t len, const sbp_msg_vel_ned_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_vel_ned_t(msg) > len)
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
  u32 msgn = htole32(*(const u32 *)&msg->n);
  memcpy(buf + offset, &msgn, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msge = htole32(*(const u32 *)&msg->e);
  memcpy(buf + offset, &msge, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgd = htole32(*(const u32 *)&msg->d);
  memcpy(buf + offset, &msgd, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgh_accuracy = htole16(msg->h_accuracy);
  memcpy(buf + offset, &msgh_accuracy, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgv_accuracy = htole16(msg->v_accuracy);
  memcpy(buf + offset, &msgv_accuracy, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgn_sats = msg->n_sats;
  memcpy(buf + offset, &msgn_sats, 1);
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
  return true;
}

static inline bool sbp_unpack_sbp_msg_vel_ned_t(const u8 *buf, size_t len, sbp_msg_vel_ned_t *msg)
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
  memcpy(&msg->n, buf + offset, 4);
  u32 msgn = *(const u32 *)&msg->n;
  msgn = le32toh(msgn);
  msg->n = *(const s32 *)&msgn;
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->e, buf + offset, 4);
  u32 msge = *(const u32 *)&msg->e;
  msge = le32toh(msge);
  msg->e = *(const s32 *)&msge;
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->d, buf + offset, 4);
  u32 msgd = *(const u32 *)&msg->d;
  msgd = le32toh(msgd);
  msg->d = *(const s32 *)&msgd;
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->h_accuracy, buf + offset, 2);
  msg->h_accuracy = le16toh(msg->h_accuracy);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->v_accuracy, buf + offset, 2);
  msg->v_accuracy = le16toh(msg->v_accuracy);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->n_sats, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->flags, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_vel_ned_cov_t(const sbp_msg_vel_ned_cov_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->tow) + sizeof(msg->n) + sizeof(msg->e) + sizeof(msg->d) + sizeof(msg->cov_n_n) +
         sizeof(msg->cov_n_e) + sizeof(msg->cov_n_d) + sizeof(msg->cov_e_e) + sizeof(msg->cov_e_d) +
         sizeof(msg->cov_d_d) + sizeof(msg->n_sats) + sizeof(msg->flags);
}

static inline bool sbp_pack_sbp_msg_vel_ned_cov_t(u8 *buf, size_t len, const sbp_msg_vel_ned_cov_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_vel_ned_cov_t(msg) > len)
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
  u32 msgn = htole32(*(const u32 *)&msg->n);
  memcpy(buf + offset, &msgn, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msge = htole32(*(const u32 *)&msg->e);
  memcpy(buf + offset, &msge, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgd = htole32(*(const u32 *)&msg->d);
  memcpy(buf + offset, &msgd, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  float msgcov_n_n = msg->cov_n_n;
  memcpy(buf + offset, &msgcov_n_n, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  float msgcov_n_e = msg->cov_n_e;
  memcpy(buf + offset, &msgcov_n_e, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  float msgcov_n_d = msg->cov_n_d;
  memcpy(buf + offset, &msgcov_n_d, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  float msgcov_e_e = msg->cov_e_e;
  memcpy(buf + offset, &msgcov_e_e, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  float msgcov_e_d = msg->cov_e_d;
  memcpy(buf + offset, &msgcov_e_d, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  float msgcov_d_d = msg->cov_d_d;
  memcpy(buf + offset, &msgcov_d_d, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgn_sats = msg->n_sats;
  memcpy(buf + offset, &msgn_sats, 1);
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
  return true;
}

static inline bool sbp_unpack_sbp_msg_vel_ned_cov_t(const u8 *buf, size_t len, sbp_msg_vel_ned_cov_t *msg)
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
  memcpy(&msg->n, buf + offset, 4);
  u32 msgn = *(const u32 *)&msg->n;
  msgn = le32toh(msgn);
  msg->n = *(const s32 *)&msgn;
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->e, buf + offset, 4);
  u32 msge = *(const u32 *)&msg->e;
  msge = le32toh(msge);
  msg->e = *(const s32 *)&msge;
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->d, buf + offset, 4);
  u32 msgd = *(const u32 *)&msg->d;
  msgd = le32toh(msgd);
  msg->d = *(const s32 *)&msgd;
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->cov_n_n, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->cov_n_e, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->cov_n_d, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->cov_e_e, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->cov_e_d, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->cov_d_d, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->n_sats, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->flags, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_pos_ecef_gnss_t(const sbp_msg_pos_ecef_gnss_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->tow) + sizeof(msg->x) + sizeof(msg->y) + sizeof(msg->z) + sizeof(msg->accuracy) +
         sizeof(msg->n_sats) + sizeof(msg->flags);
}

static inline bool sbp_pack_sbp_msg_pos_ecef_gnss_t(u8 *buf, size_t len, const sbp_msg_pos_ecef_gnss_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_pos_ecef_gnss_t(msg) > len)
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

  if (offset + 8 > len)
  {
    return false;
  }
  double msgx = msg->x;
  memcpy(buf + offset, &msgx, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgy = msg->y;
  memcpy(buf + offset, &msgy, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgz = msg->z;
  memcpy(buf + offset, &msgz, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgaccuracy = htole16(msg->accuracy);
  memcpy(buf + offset, &msgaccuracy, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgn_sats = msg->n_sats;
  memcpy(buf + offset, &msgn_sats, 1);
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
  return true;
}

static inline bool sbp_unpack_sbp_msg_pos_ecef_gnss_t(const u8 *buf, size_t len, sbp_msg_pos_ecef_gnss_t *msg)
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

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->x, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->y, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->z, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->accuracy, buf + offset, 2);
  msg->accuracy = le16toh(msg->accuracy);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->n_sats, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->flags, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_pos_ecef_cov_gnss_t(const sbp_msg_pos_ecef_cov_gnss_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->tow) + sizeof(msg->x) + sizeof(msg->y) + sizeof(msg->z) + sizeof(msg->cov_x_x) +
         sizeof(msg->cov_x_y) + sizeof(msg->cov_x_z) + sizeof(msg->cov_y_y) + sizeof(msg->cov_y_z) +
         sizeof(msg->cov_z_z) + sizeof(msg->n_sats) + sizeof(msg->flags);
}

static inline bool sbp_pack_sbp_msg_pos_ecef_cov_gnss_t(u8 *buf, size_t len, const sbp_msg_pos_ecef_cov_gnss_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_pos_ecef_cov_gnss_t(msg) > len)
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

  if (offset + 8 > len)
  {
    return false;
  }
  double msgx = msg->x;
  memcpy(buf + offset, &msgx, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgy = msg->y;
  memcpy(buf + offset, &msgy, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgz = msg->z;
  memcpy(buf + offset, &msgz, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 4 > len)
  {
    return false;
  }
  float msgcov_x_x = msg->cov_x_x;
  memcpy(buf + offset, &msgcov_x_x, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  float msgcov_x_y = msg->cov_x_y;
  memcpy(buf + offset, &msgcov_x_y, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  float msgcov_x_z = msg->cov_x_z;
  memcpy(buf + offset, &msgcov_x_z, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  float msgcov_y_y = msg->cov_y_y;
  memcpy(buf + offset, &msgcov_y_y, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  float msgcov_y_z = msg->cov_y_z;
  memcpy(buf + offset, &msgcov_y_z, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  float msgcov_z_z = msg->cov_z_z;
  memcpy(buf + offset, &msgcov_z_z, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgn_sats = msg->n_sats;
  memcpy(buf + offset, &msgn_sats, 1);
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
  return true;
}

static inline bool sbp_unpack_sbp_msg_pos_ecef_cov_gnss_t(const u8 *buf, size_t len, sbp_msg_pos_ecef_cov_gnss_t *msg)
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

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->x, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->y, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->z, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->cov_x_x, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->cov_x_y, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->cov_x_z, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->cov_y_y, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->cov_y_z, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->cov_z_z, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->n_sats, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->flags, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_pos_llh_gnss_t(const sbp_msg_pos_llh_gnss_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->tow) + sizeof(msg->lat) + sizeof(msg->lon) + sizeof(msg->height) + sizeof(msg->h_accuracy) +
         sizeof(msg->v_accuracy) + sizeof(msg->n_sats) + sizeof(msg->flags);
}

static inline bool sbp_pack_sbp_msg_pos_llh_gnss_t(u8 *buf, size_t len, const sbp_msg_pos_llh_gnss_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_pos_llh_gnss_t(msg) > len)
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

  if (offset + 8 > len)
  {
    return false;
  }
  double msglat = msg->lat;
  memcpy(buf + offset, &msglat, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msglon = msg->lon;
  memcpy(buf + offset, &msglon, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgheight = msg->height;
  memcpy(buf + offset, &msgheight, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgh_accuracy = htole16(msg->h_accuracy);
  memcpy(buf + offset, &msgh_accuracy, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgv_accuracy = htole16(msg->v_accuracy);
  memcpy(buf + offset, &msgv_accuracy, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgn_sats = msg->n_sats;
  memcpy(buf + offset, &msgn_sats, 1);
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
  return true;
}

static inline bool sbp_unpack_sbp_msg_pos_llh_gnss_t(const u8 *buf, size_t len, sbp_msg_pos_llh_gnss_t *msg)
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

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->lat, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->lon, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->height, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->h_accuracy, buf + offset, 2);
  msg->h_accuracy = le16toh(msg->h_accuracy);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->v_accuracy, buf + offset, 2);
  msg->v_accuracy = le16toh(msg->v_accuracy);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->n_sats, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->flags, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_pos_llh_cov_gnss_t(const sbp_msg_pos_llh_cov_gnss_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->tow) + sizeof(msg->lat) + sizeof(msg->lon) + sizeof(msg->height) + sizeof(msg->cov_n_n) +
         sizeof(msg->cov_n_e) + sizeof(msg->cov_n_d) + sizeof(msg->cov_e_e) + sizeof(msg->cov_e_d) +
         sizeof(msg->cov_d_d) + sizeof(msg->n_sats) + sizeof(msg->flags);
}

static inline bool sbp_pack_sbp_msg_pos_llh_cov_gnss_t(u8 *buf, size_t len, const sbp_msg_pos_llh_cov_gnss_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_pos_llh_cov_gnss_t(msg) > len)
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

  if (offset + 8 > len)
  {
    return false;
  }
  double msglat = msg->lat;
  memcpy(buf + offset, &msglat, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msglon = msg->lon;
  memcpy(buf + offset, &msglon, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgheight = msg->height;
  memcpy(buf + offset, &msgheight, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 4 > len)
  {
    return false;
  }
  float msgcov_n_n = msg->cov_n_n;
  memcpy(buf + offset, &msgcov_n_n, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  float msgcov_n_e = msg->cov_n_e;
  memcpy(buf + offset, &msgcov_n_e, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  float msgcov_n_d = msg->cov_n_d;
  memcpy(buf + offset, &msgcov_n_d, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  float msgcov_e_e = msg->cov_e_e;
  memcpy(buf + offset, &msgcov_e_e, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  float msgcov_e_d = msg->cov_e_d;
  memcpy(buf + offset, &msgcov_e_d, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  float msgcov_d_d = msg->cov_d_d;
  memcpy(buf + offset, &msgcov_d_d, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgn_sats = msg->n_sats;
  memcpy(buf + offset, &msgn_sats, 1);
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
  return true;
}

static inline bool sbp_unpack_sbp_msg_pos_llh_cov_gnss_t(const u8 *buf, size_t len, sbp_msg_pos_llh_cov_gnss_t *msg)
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

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->lat, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->lon, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->height, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->cov_n_n, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->cov_n_e, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->cov_n_d, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->cov_e_e, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->cov_e_d, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->cov_d_d, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->n_sats, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->flags, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_vel_ecef_gnss_t(const sbp_msg_vel_ecef_gnss_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->tow) + sizeof(msg->x) + sizeof(msg->y) + sizeof(msg->z) + sizeof(msg->accuracy) +
         sizeof(msg->n_sats) + sizeof(msg->flags);
}

static inline bool sbp_pack_sbp_msg_vel_ecef_gnss_t(u8 *buf, size_t len, const sbp_msg_vel_ecef_gnss_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_vel_ecef_gnss_t(msg) > len)
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
  u32 msgx = htole32(*(const u32 *)&msg->x);
  memcpy(buf + offset, &msgx, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgy = htole32(*(const u32 *)&msg->y);
  memcpy(buf + offset, &msgy, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgz = htole32(*(const u32 *)&msg->z);
  memcpy(buf + offset, &msgz, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgaccuracy = htole16(msg->accuracy);
  memcpy(buf + offset, &msgaccuracy, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgn_sats = msg->n_sats;
  memcpy(buf + offset, &msgn_sats, 1);
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
  return true;
}

static inline bool sbp_unpack_sbp_msg_vel_ecef_gnss_t(const u8 *buf, size_t len, sbp_msg_vel_ecef_gnss_t *msg)
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
  memcpy(&msg->x, buf + offset, 4);
  u32 msgx = *(const u32 *)&msg->x;
  msgx = le32toh(msgx);
  msg->x = *(const s32 *)&msgx;
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->y, buf + offset, 4);
  u32 msgy = *(const u32 *)&msg->y;
  msgy = le32toh(msgy);
  msg->y = *(const s32 *)&msgy;
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->z, buf + offset, 4);
  u32 msgz = *(const u32 *)&msg->z;
  msgz = le32toh(msgz);
  msg->z = *(const s32 *)&msgz;
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->accuracy, buf + offset, 2);
  msg->accuracy = le16toh(msg->accuracy);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->n_sats, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->flags, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_vel_ecef_cov_gnss_t(const sbp_msg_vel_ecef_cov_gnss_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->tow) + sizeof(msg->x) + sizeof(msg->y) + sizeof(msg->z) + sizeof(msg->cov_x_x) +
         sizeof(msg->cov_x_y) + sizeof(msg->cov_x_z) + sizeof(msg->cov_y_y) + sizeof(msg->cov_y_z) +
         sizeof(msg->cov_z_z) + sizeof(msg->n_sats) + sizeof(msg->flags);
}

static inline bool sbp_pack_sbp_msg_vel_ecef_cov_gnss_t(u8 *buf, size_t len, const sbp_msg_vel_ecef_cov_gnss_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_vel_ecef_cov_gnss_t(msg) > len)
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
  u32 msgx = htole32(*(const u32 *)&msg->x);
  memcpy(buf + offset, &msgx, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgy = htole32(*(const u32 *)&msg->y);
  memcpy(buf + offset, &msgy, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgz = htole32(*(const u32 *)&msg->z);
  memcpy(buf + offset, &msgz, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  float msgcov_x_x = msg->cov_x_x;
  memcpy(buf + offset, &msgcov_x_x, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  float msgcov_x_y = msg->cov_x_y;
  memcpy(buf + offset, &msgcov_x_y, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  float msgcov_x_z = msg->cov_x_z;
  memcpy(buf + offset, &msgcov_x_z, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  float msgcov_y_y = msg->cov_y_y;
  memcpy(buf + offset, &msgcov_y_y, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  float msgcov_y_z = msg->cov_y_z;
  memcpy(buf + offset, &msgcov_y_z, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  float msgcov_z_z = msg->cov_z_z;
  memcpy(buf + offset, &msgcov_z_z, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgn_sats = msg->n_sats;
  memcpy(buf + offset, &msgn_sats, 1);
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
  return true;
}

static inline bool sbp_unpack_sbp_msg_vel_ecef_cov_gnss_t(const u8 *buf, size_t len, sbp_msg_vel_ecef_cov_gnss_t *msg)
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
  memcpy(&msg->x, buf + offset, 4);
  u32 msgx = *(const u32 *)&msg->x;
  msgx = le32toh(msgx);
  msg->x = *(const s32 *)&msgx;
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->y, buf + offset, 4);
  u32 msgy = *(const u32 *)&msg->y;
  msgy = le32toh(msgy);
  msg->y = *(const s32 *)&msgy;
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->z, buf + offset, 4);
  u32 msgz = *(const u32 *)&msg->z;
  msgz = le32toh(msgz);
  msg->z = *(const s32 *)&msgz;
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->cov_x_x, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->cov_x_y, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->cov_x_z, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->cov_y_y, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->cov_y_z, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->cov_z_z, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->n_sats, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->flags, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_vel_ned_gnss_t(const sbp_msg_vel_ned_gnss_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->tow) + sizeof(msg->n) + sizeof(msg->e) + sizeof(msg->d) + sizeof(msg->h_accuracy) +
         sizeof(msg->v_accuracy) + sizeof(msg->n_sats) + sizeof(msg->flags);
}

static inline bool sbp_pack_sbp_msg_vel_ned_gnss_t(u8 *buf, size_t len, const sbp_msg_vel_ned_gnss_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_vel_ned_gnss_t(msg) > len)
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
  u32 msgn = htole32(*(const u32 *)&msg->n);
  memcpy(buf + offset, &msgn, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msge = htole32(*(const u32 *)&msg->e);
  memcpy(buf + offset, &msge, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgd = htole32(*(const u32 *)&msg->d);
  memcpy(buf + offset, &msgd, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgh_accuracy = htole16(msg->h_accuracy);
  memcpy(buf + offset, &msgh_accuracy, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgv_accuracy = htole16(msg->v_accuracy);
  memcpy(buf + offset, &msgv_accuracy, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgn_sats = msg->n_sats;
  memcpy(buf + offset, &msgn_sats, 1);
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
  return true;
}

static inline bool sbp_unpack_sbp_msg_vel_ned_gnss_t(const u8 *buf, size_t len, sbp_msg_vel_ned_gnss_t *msg)
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
  memcpy(&msg->n, buf + offset, 4);
  u32 msgn = *(const u32 *)&msg->n;
  msgn = le32toh(msgn);
  msg->n = *(const s32 *)&msgn;
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->e, buf + offset, 4);
  u32 msge = *(const u32 *)&msg->e;
  msge = le32toh(msge);
  msg->e = *(const s32 *)&msge;
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->d, buf + offset, 4);
  u32 msgd = *(const u32 *)&msg->d;
  msgd = le32toh(msgd);
  msg->d = *(const s32 *)&msgd;
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->h_accuracy, buf + offset, 2);
  msg->h_accuracy = le16toh(msg->h_accuracy);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->v_accuracy, buf + offset, 2);
  msg->v_accuracy = le16toh(msg->v_accuracy);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->n_sats, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->flags, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_vel_ned_cov_gnss_t(const sbp_msg_vel_ned_cov_gnss_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->tow) + sizeof(msg->n) + sizeof(msg->e) + sizeof(msg->d) + sizeof(msg->cov_n_n) +
         sizeof(msg->cov_n_e) + sizeof(msg->cov_n_d) + sizeof(msg->cov_e_e) + sizeof(msg->cov_e_d) +
         sizeof(msg->cov_d_d) + sizeof(msg->n_sats) + sizeof(msg->flags);
}

static inline bool sbp_pack_sbp_msg_vel_ned_cov_gnss_t(u8 *buf, size_t len, const sbp_msg_vel_ned_cov_gnss_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_vel_ned_cov_gnss_t(msg) > len)
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
  u32 msgn = htole32(*(const u32 *)&msg->n);
  memcpy(buf + offset, &msgn, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msge = htole32(*(const u32 *)&msg->e);
  memcpy(buf + offset, &msge, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgd = htole32(*(const u32 *)&msg->d);
  memcpy(buf + offset, &msgd, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  float msgcov_n_n = msg->cov_n_n;
  memcpy(buf + offset, &msgcov_n_n, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  float msgcov_n_e = msg->cov_n_e;
  memcpy(buf + offset, &msgcov_n_e, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  float msgcov_n_d = msg->cov_n_d;
  memcpy(buf + offset, &msgcov_n_d, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  float msgcov_e_e = msg->cov_e_e;
  memcpy(buf + offset, &msgcov_e_e, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  float msgcov_e_d = msg->cov_e_d;
  memcpy(buf + offset, &msgcov_e_d, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  float msgcov_d_d = msg->cov_d_d;
  memcpy(buf + offset, &msgcov_d_d, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgn_sats = msg->n_sats;
  memcpy(buf + offset, &msgn_sats, 1);
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
  return true;
}

static inline bool sbp_unpack_sbp_msg_vel_ned_cov_gnss_t(const u8 *buf, size_t len, sbp_msg_vel_ned_cov_gnss_t *msg)
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
  memcpy(&msg->n, buf + offset, 4);
  u32 msgn = *(const u32 *)&msg->n;
  msgn = le32toh(msgn);
  msg->n = *(const s32 *)&msgn;
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->e, buf + offset, 4);
  u32 msge = *(const u32 *)&msg->e;
  msge = le32toh(msge);
  msg->e = *(const s32 *)&msge;
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->d, buf + offset, 4);
  u32 msgd = *(const u32 *)&msg->d;
  msgd = le32toh(msgd);
  msg->d = *(const s32 *)&msgd;
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->cov_n_n, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->cov_n_e, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->cov_n_d, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->cov_e_e, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->cov_e_d, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->cov_d_d, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->n_sats, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->flags, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_vel_body_t(const sbp_msg_vel_body_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->tow) + sizeof(msg->x) + sizeof(msg->y) + sizeof(msg->z) + sizeof(msg->cov_x_x) +
         sizeof(msg->cov_x_y) + sizeof(msg->cov_x_z) + sizeof(msg->cov_y_y) + sizeof(msg->cov_y_z) +
         sizeof(msg->cov_z_z) + sizeof(msg->n_sats) + sizeof(msg->flags);
}

static inline bool sbp_pack_sbp_msg_vel_body_t(u8 *buf, size_t len, const sbp_msg_vel_body_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_vel_body_t(msg) > len)
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
  u32 msgx = htole32(*(const u32 *)&msg->x);
  memcpy(buf + offset, &msgx, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgy = htole32(*(const u32 *)&msg->y);
  memcpy(buf + offset, &msgy, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgz = htole32(*(const u32 *)&msg->z);
  memcpy(buf + offset, &msgz, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  float msgcov_x_x = msg->cov_x_x;
  memcpy(buf + offset, &msgcov_x_x, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  float msgcov_x_y = msg->cov_x_y;
  memcpy(buf + offset, &msgcov_x_y, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  float msgcov_x_z = msg->cov_x_z;
  memcpy(buf + offset, &msgcov_x_z, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  float msgcov_y_y = msg->cov_y_y;
  memcpy(buf + offset, &msgcov_y_y, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  float msgcov_y_z = msg->cov_y_z;
  memcpy(buf + offset, &msgcov_y_z, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  float msgcov_z_z = msg->cov_z_z;
  memcpy(buf + offset, &msgcov_z_z, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgn_sats = msg->n_sats;
  memcpy(buf + offset, &msgn_sats, 1);
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
  return true;
}

static inline bool sbp_unpack_sbp_msg_vel_body_t(const u8 *buf, size_t len, sbp_msg_vel_body_t *msg)
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
  memcpy(&msg->x, buf + offset, 4);
  u32 msgx = *(const u32 *)&msg->x;
  msgx = le32toh(msgx);
  msg->x = *(const s32 *)&msgx;
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->y, buf + offset, 4);
  u32 msgy = *(const u32 *)&msg->y;
  msgy = le32toh(msgy);
  msg->y = *(const s32 *)&msgy;
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->z, buf + offset, 4);
  u32 msgz = *(const u32 *)&msg->z;
  msgz = le32toh(msgz);
  msg->z = *(const s32 *)&msgz;
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->cov_x_x, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->cov_x_y, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->cov_x_z, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->cov_y_y, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->cov_y_z, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->cov_z_z, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->n_sats, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->flags, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_age_corrections_t(const sbp_msg_age_corrections_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->tow) + sizeof(msg->age);
}

static inline bool sbp_pack_sbp_msg_age_corrections_t(u8 *buf, size_t len, const sbp_msg_age_corrections_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_age_corrections_t(msg) > len)
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
  u16 msgage = htole16(msg->age);
  memcpy(buf + offset, &msgage, 2);
  // NOLINTNEXTLINE
  offset += 2;
  return true;
}

static inline bool sbp_unpack_sbp_msg_age_corrections_t(const u8 *buf, size_t len, sbp_msg_age_corrections_t *msg)
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
  memcpy(&msg->age, buf + offset, 2);
  msg->age = le16toh(msg->age);
  // NOLINTNEXTLINE
  offset += 2;
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_gps_time_dep_a_t(const sbp_msg_gps_time_dep_a_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->wn) + sizeof(msg->tow) + sizeof(msg->ns_residual) + sizeof(msg->flags);
}

static inline bool sbp_pack_sbp_msg_gps_time_dep_a_t(u8 *buf, size_t len, const sbp_msg_gps_time_dep_a_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_gps_time_dep_a_t(msg) > len)
  {
    return false;
  }

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgwn = htole16(msg->wn);
  memcpy(buf + offset, &msgwn, 2);
  // NOLINTNEXTLINE
  offset += 2;

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

static inline bool sbp_unpack_sbp_msg_gps_time_dep_a_t(const u8 *buf, size_t len, sbp_msg_gps_time_dep_a_t *msg)
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
  memcpy(&msg->wn, buf + offset, 2);
  msg->wn = le16toh(msg->wn);
  // NOLINTNEXTLINE
  offset += 2;

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

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->flags, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_dops_dep_a_t(const sbp_msg_dops_dep_a_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->tow) + sizeof(msg->gdop) + sizeof(msg->pdop) + sizeof(msg->tdop) + sizeof(msg->hdop) +
         sizeof(msg->vdop);
}

static inline bool sbp_pack_sbp_msg_dops_dep_a_t(u8 *buf, size_t len, const sbp_msg_dops_dep_a_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_dops_dep_a_t(msg) > len)
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
  u16 msggdop = htole16(msg->gdop);
  memcpy(buf + offset, &msggdop, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgpdop = htole16(msg->pdop);
  memcpy(buf + offset, &msgpdop, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgtdop = htole16(msg->tdop);
  memcpy(buf + offset, &msgtdop, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msghdop = htole16(msg->hdop);
  memcpy(buf + offset, &msghdop, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgvdop = htole16(msg->vdop);
  memcpy(buf + offset, &msgvdop, 2);
  // NOLINTNEXTLINE
  offset += 2;
  return true;
}

static inline bool sbp_unpack_sbp_msg_dops_dep_a_t(const u8 *buf, size_t len, sbp_msg_dops_dep_a_t *msg)
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
  memcpy(&msg->gdop, buf + offset, 2);
  msg->gdop = le16toh(msg->gdop);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->pdop, buf + offset, 2);
  msg->pdop = le16toh(msg->pdop);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->tdop, buf + offset, 2);
  msg->tdop = le16toh(msg->tdop);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->hdop, buf + offset, 2);
  msg->hdop = le16toh(msg->hdop);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->vdop, buf + offset, 2);
  msg->vdop = le16toh(msg->vdop);
  // NOLINTNEXTLINE
  offset += 2;
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_pos_ecef_dep_a_t(const sbp_msg_pos_ecef_dep_a_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->tow) + sizeof(msg->x) + sizeof(msg->y) + sizeof(msg->z) + sizeof(msg->accuracy) +
         sizeof(msg->n_sats) + sizeof(msg->flags);
}

static inline bool sbp_pack_sbp_msg_pos_ecef_dep_a_t(u8 *buf, size_t len, const sbp_msg_pos_ecef_dep_a_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_pos_ecef_dep_a_t(msg) > len)
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

  if (offset + 8 > len)
  {
    return false;
  }
  double msgx = msg->x;
  memcpy(buf + offset, &msgx, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgy = msg->y;
  memcpy(buf + offset, &msgy, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgz = msg->z;
  memcpy(buf + offset, &msgz, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgaccuracy = htole16(msg->accuracy);
  memcpy(buf + offset, &msgaccuracy, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgn_sats = msg->n_sats;
  memcpy(buf + offset, &msgn_sats, 1);
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
  return true;
}

static inline bool sbp_unpack_sbp_msg_pos_ecef_dep_a_t(const u8 *buf, size_t len, sbp_msg_pos_ecef_dep_a_t *msg)
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

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->x, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->y, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->z, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->accuracy, buf + offset, 2);
  msg->accuracy = le16toh(msg->accuracy);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->n_sats, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->flags, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_pos_llh_dep_a_t(const sbp_msg_pos_llh_dep_a_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->tow) + sizeof(msg->lat) + sizeof(msg->lon) + sizeof(msg->height) + sizeof(msg->h_accuracy) +
         sizeof(msg->v_accuracy) + sizeof(msg->n_sats) + sizeof(msg->flags);
}

static inline bool sbp_pack_sbp_msg_pos_llh_dep_a_t(u8 *buf, size_t len, const sbp_msg_pos_llh_dep_a_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_pos_llh_dep_a_t(msg) > len)
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

  if (offset + 8 > len)
  {
    return false;
  }
  double msglat = msg->lat;
  memcpy(buf + offset, &msglat, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msglon = msg->lon;
  memcpy(buf + offset, &msglon, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgheight = msg->height;
  memcpy(buf + offset, &msgheight, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgh_accuracy = htole16(msg->h_accuracy);
  memcpy(buf + offset, &msgh_accuracy, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgv_accuracy = htole16(msg->v_accuracy);
  memcpy(buf + offset, &msgv_accuracy, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgn_sats = msg->n_sats;
  memcpy(buf + offset, &msgn_sats, 1);
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
  return true;
}

static inline bool sbp_unpack_sbp_msg_pos_llh_dep_a_t(const u8 *buf, size_t len, sbp_msg_pos_llh_dep_a_t *msg)
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

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->lat, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->lon, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->height, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->h_accuracy, buf + offset, 2);
  msg->h_accuracy = le16toh(msg->h_accuracy);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->v_accuracy, buf + offset, 2);
  msg->v_accuracy = le16toh(msg->v_accuracy);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->n_sats, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->flags, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_baseline_ecef_dep_a_t(const sbp_msg_baseline_ecef_dep_a_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->tow) + sizeof(msg->x) + sizeof(msg->y) + sizeof(msg->z) + sizeof(msg->accuracy) +
         sizeof(msg->n_sats) + sizeof(msg->flags);
}

static inline bool sbp_pack_sbp_msg_baseline_ecef_dep_a_t(u8 *buf, size_t len, const sbp_msg_baseline_ecef_dep_a_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_baseline_ecef_dep_a_t(msg) > len)
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
  u32 msgx = htole32(*(const u32 *)&msg->x);
  memcpy(buf + offset, &msgx, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgy = htole32(*(const u32 *)&msg->y);
  memcpy(buf + offset, &msgy, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgz = htole32(*(const u32 *)&msg->z);
  memcpy(buf + offset, &msgz, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgaccuracy = htole16(msg->accuracy);
  memcpy(buf + offset, &msgaccuracy, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgn_sats = msg->n_sats;
  memcpy(buf + offset, &msgn_sats, 1);
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
  return true;
}

static inline bool
sbp_unpack_sbp_msg_baseline_ecef_dep_a_t(const u8 *buf, size_t len, sbp_msg_baseline_ecef_dep_a_t *msg)
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
  memcpy(&msg->x, buf + offset, 4);
  u32 msgx = *(const u32 *)&msg->x;
  msgx = le32toh(msgx);
  msg->x = *(const s32 *)&msgx;
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->y, buf + offset, 4);
  u32 msgy = *(const u32 *)&msg->y;
  msgy = le32toh(msgy);
  msg->y = *(const s32 *)&msgy;
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->z, buf + offset, 4);
  u32 msgz = *(const u32 *)&msg->z;
  msgz = le32toh(msgz);
  msg->z = *(const s32 *)&msgz;
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->accuracy, buf + offset, 2);
  msg->accuracy = le16toh(msg->accuracy);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->n_sats, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->flags, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_baseline_ned_dep_a_t(const sbp_msg_baseline_ned_dep_a_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->tow) + sizeof(msg->n) + sizeof(msg->e) + sizeof(msg->d) + sizeof(msg->h_accuracy) +
         sizeof(msg->v_accuracy) + sizeof(msg->n_sats) + sizeof(msg->flags);
}

static inline bool sbp_pack_sbp_msg_baseline_ned_dep_a_t(u8 *buf, size_t len, const sbp_msg_baseline_ned_dep_a_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_baseline_ned_dep_a_t(msg) > len)
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
  u32 msgn = htole32(*(const u32 *)&msg->n);
  memcpy(buf + offset, &msgn, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msge = htole32(*(const u32 *)&msg->e);
  memcpy(buf + offset, &msge, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgd = htole32(*(const u32 *)&msg->d);
  memcpy(buf + offset, &msgd, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgh_accuracy = htole16(msg->h_accuracy);
  memcpy(buf + offset, &msgh_accuracy, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgv_accuracy = htole16(msg->v_accuracy);
  memcpy(buf + offset, &msgv_accuracy, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgn_sats = msg->n_sats;
  memcpy(buf + offset, &msgn_sats, 1);
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
  return true;
}

static inline bool sbp_unpack_sbp_msg_baseline_ned_dep_a_t(const u8 *buf, size_t len, sbp_msg_baseline_ned_dep_a_t *msg)
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
  memcpy(&msg->n, buf + offset, 4);
  u32 msgn = *(const u32 *)&msg->n;
  msgn = le32toh(msgn);
  msg->n = *(const s32 *)&msgn;
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->e, buf + offset, 4);
  u32 msge = *(const u32 *)&msg->e;
  msge = le32toh(msge);
  msg->e = *(const s32 *)&msge;
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->d, buf + offset, 4);
  u32 msgd = *(const u32 *)&msg->d;
  msgd = le32toh(msgd);
  msg->d = *(const s32 *)&msgd;
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->h_accuracy, buf + offset, 2);
  msg->h_accuracy = le16toh(msg->h_accuracy);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->v_accuracy, buf + offset, 2);
  msg->v_accuracy = le16toh(msg->v_accuracy);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->n_sats, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->flags, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_vel_ecef_dep_a_t(const sbp_msg_vel_ecef_dep_a_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->tow) + sizeof(msg->x) + sizeof(msg->y) + sizeof(msg->z) + sizeof(msg->accuracy) +
         sizeof(msg->n_sats) + sizeof(msg->flags);
}

static inline bool sbp_pack_sbp_msg_vel_ecef_dep_a_t(u8 *buf, size_t len, const sbp_msg_vel_ecef_dep_a_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_vel_ecef_dep_a_t(msg) > len)
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
  u32 msgx = htole32(*(const u32 *)&msg->x);
  memcpy(buf + offset, &msgx, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgy = htole32(*(const u32 *)&msg->y);
  memcpy(buf + offset, &msgy, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgz = htole32(*(const u32 *)&msg->z);
  memcpy(buf + offset, &msgz, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgaccuracy = htole16(msg->accuracy);
  memcpy(buf + offset, &msgaccuracy, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgn_sats = msg->n_sats;
  memcpy(buf + offset, &msgn_sats, 1);
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
  return true;
}

static inline bool sbp_unpack_sbp_msg_vel_ecef_dep_a_t(const u8 *buf, size_t len, sbp_msg_vel_ecef_dep_a_t *msg)
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
  memcpy(&msg->x, buf + offset, 4);
  u32 msgx = *(const u32 *)&msg->x;
  msgx = le32toh(msgx);
  msg->x = *(const s32 *)&msgx;
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->y, buf + offset, 4);
  u32 msgy = *(const u32 *)&msg->y;
  msgy = le32toh(msgy);
  msg->y = *(const s32 *)&msgy;
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->z, buf + offset, 4);
  u32 msgz = *(const u32 *)&msg->z;
  msgz = le32toh(msgz);
  msg->z = *(const s32 *)&msgz;
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->accuracy, buf + offset, 2);
  msg->accuracy = le16toh(msg->accuracy);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->n_sats, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->flags, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_vel_ned_dep_a_t(const sbp_msg_vel_ned_dep_a_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->tow) + sizeof(msg->n) + sizeof(msg->e) + sizeof(msg->d) + sizeof(msg->h_accuracy) +
         sizeof(msg->v_accuracy) + sizeof(msg->n_sats) + sizeof(msg->flags);
}

static inline bool sbp_pack_sbp_msg_vel_ned_dep_a_t(u8 *buf, size_t len, const sbp_msg_vel_ned_dep_a_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_vel_ned_dep_a_t(msg) > len)
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
  u32 msgn = htole32(*(const u32 *)&msg->n);
  memcpy(buf + offset, &msgn, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msge = htole32(*(const u32 *)&msg->e);
  memcpy(buf + offset, &msge, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgd = htole32(*(const u32 *)&msg->d);
  memcpy(buf + offset, &msgd, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgh_accuracy = htole16(msg->h_accuracy);
  memcpy(buf + offset, &msgh_accuracy, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgv_accuracy = htole16(msg->v_accuracy);
  memcpy(buf + offset, &msgv_accuracy, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgn_sats = msg->n_sats;
  memcpy(buf + offset, &msgn_sats, 1);
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
  return true;
}

static inline bool sbp_unpack_sbp_msg_vel_ned_dep_a_t(const u8 *buf, size_t len, sbp_msg_vel_ned_dep_a_t *msg)
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
  memcpy(&msg->n, buf + offset, 4);
  u32 msgn = *(const u32 *)&msg->n;
  msgn = le32toh(msgn);
  msg->n = *(const s32 *)&msgn;
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->e, buf + offset, 4);
  u32 msge = *(const u32 *)&msg->e;
  msge = le32toh(msge);
  msg->e = *(const s32 *)&msge;
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->d, buf + offset, 4);
  u32 msgd = *(const u32 *)&msg->d;
  msgd = le32toh(msgd);
  msg->d = *(const s32 *)&msgd;
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->h_accuracy, buf + offset, 2);
  msg->h_accuracy = le16toh(msg->h_accuracy);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->v_accuracy, buf + offset, 2);
  msg->v_accuracy = le16toh(msg->v_accuracy);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->n_sats, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->flags, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_baseline_heading_dep_a_t(const sbp_msg_baseline_heading_dep_a_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->tow) + sizeof(msg->heading) + sizeof(msg->n_sats) + sizeof(msg->flags);
}

static inline bool
sbp_pack_sbp_msg_baseline_heading_dep_a_t(u8 *buf, size_t len, const sbp_msg_baseline_heading_dep_a_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_baseline_heading_dep_a_t(msg) > len)
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
  u32 msgheading = htole32(msg->heading);
  memcpy(buf + offset, &msgheading, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgn_sats = msg->n_sats;
  memcpy(buf + offset, &msgn_sats, 1);
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
  return true;
}

static inline bool
sbp_unpack_sbp_msg_baseline_heading_dep_a_t(const u8 *buf, size_t len, sbp_msg_baseline_heading_dep_a_t *msg)
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
  memcpy(&msg->heading, buf + offset, 4);
  msg->heading = le32toh(msg->heading);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->n_sats, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->flags, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_protection_level_t(const sbp_msg_protection_level_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->tow) + sizeof(msg->vpl) + sizeof(msg->hpl) + sizeof(msg->lat) + sizeof(msg->lon) +
         sizeof(msg->height) + sizeof(msg->flags);
}

static inline bool sbp_pack_sbp_msg_protection_level_t(u8 *buf, size_t len, const sbp_msg_protection_level_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_protection_level_t(msg) > len)
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
  u16 msgvpl = htole16(msg->vpl);
  memcpy(buf + offset, &msgvpl, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msghpl = htole16(msg->hpl);
  memcpy(buf + offset, &msghpl, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 8 > len)
  {
    return false;
  }
  double msglat = msg->lat;
  memcpy(buf + offset, &msglat, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msglon = msg->lon;
  memcpy(buf + offset, &msglon, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgheight = msg->height;
  memcpy(buf + offset, &msgheight, 8);
  // NOLINTNEXTLINE
  offset += 8;

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

static inline bool sbp_unpack_sbp_msg_protection_level_t(const u8 *buf, size_t len, sbp_msg_protection_level_t *msg)
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
  memcpy(&msg->vpl, buf + offset, 2);
  msg->vpl = le16toh(msg->vpl);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->hpl, buf + offset, 2);
  msg->hpl = le16toh(msg->hpl);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->lat, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->lon, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->height, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->flags, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

#endif