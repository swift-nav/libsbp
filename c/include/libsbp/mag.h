#ifndef LIBSBP_MAG_MESSAGES_H
#define LIBSBP_MAG_MESSAGES_H

#include <endian.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>

#include <libsbp/common.h>
/** Raw magnetometer data
 *
 * Raw data from the magnetometer.
 */
#define SBP_MSG_MAG_RAW 0x0902

typedef struct
{

  /**
   * Milliseconds since start of GPS week. If the high bit is set, the
   * time is unknown or invalid.[ms]
   */
  u32 tow;
  /**
   * Milliseconds since start of GPS week, fractional part[ms / 256]
   */
  u8 tow_f;
  /**
   * Magnetic field in the body frame X axis[microteslas]
   */
  s16 mag_x;
  /**
   * Magnetic field in the body frame Y axis[microteslas]
   */
  s16 mag_y;
  /**
   * Magnetic field in the body frame Z axis[microteslas]
   */
  s16 mag_z;
} sbp_msg_mag_raw_t;

static inline size_t sbp_packed_size_sbp_msg_mag_raw_t(const sbp_msg_mag_raw_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->tow) + sizeof(msg->tow_f) + sizeof(msg->mag_x) + sizeof(msg->mag_y) + sizeof(msg->mag_z);
}

static inline bool sbp_pack_sbp_msg_mag_raw_t(u8 *buf, size_t len, const sbp_msg_mag_raw_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_mag_raw_t(msg) > len)
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
  u8 msgtow_f = msg->tow_f;
  memcpy(buf + offset, &msgtow_f, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgmag_x = htole16(*(const u16 *)&msg->mag_x);
  memcpy(buf + offset, &msgmag_x, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgmag_y = htole16(*(const u16 *)&msg->mag_y);
  memcpy(buf + offset, &msgmag_y, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgmag_z = htole16(*(const u16 *)&msg->mag_z);
  memcpy(buf + offset, &msgmag_z, 2);
  // NOLINTNEXTLINE
  offset += 2;
  return true;
}

static inline bool sbp_unpack_sbp_msg_mag_raw_t(const u8 *buf, size_t len, sbp_msg_mag_raw_t *msg)
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
  memcpy(&msg->tow_f, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->mag_x, buf + offset, 2);
  u16 msgmag_x = *(const u16 *)&msg->mag_x;
  msgmag_x = le16toh(msgmag_x);
  msg->mag_x = *(const s16 *)&msgmag_x;
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->mag_y, buf + offset, 2);
  u16 msgmag_y = *(const u16 *)&msg->mag_y;
  msgmag_y = le16toh(msgmag_y);
  msg->mag_y = *(const s16 *)&msgmag_y;
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->mag_z, buf + offset, 2);
  u16 msgmag_z = *(const u16 *)&msg->mag_z;
  msgmag_z = le16toh(msgmag_z);
  msg->mag_z = *(const s16 *)&msgmag_z;
  // NOLINTNEXTLINE
  offset += 2;
  return true;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_mag_raw_t &a, const sbp_msg_mag_raw_t &b)
{
  (void)a;
  (void)b;

  if (a.tow != b.tow)
  {
    return false;
  }

  if (a.tow_f != b.tow_f)
  {
    return false;
  }

  if (a.mag_x != b.mag_x)
  {
    return false;
  }

  if (a.mag_y != b.mag_y)
  {
    return false;
  }

  if (a.mag_z != b.mag_z)
  {
    return false;
  }

  return true;
}

static inline bool operator!=(const sbp_msg_mag_raw_t &a, const sbp_msg_mag_raw_t &b)
{
  return !(a == b);
}
#endif

#endif /* LIBSBP_MAG_MESSAGES_H */