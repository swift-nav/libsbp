#ifndef LIBSBP_VEHICLE_PACKERS_H
#define LIBSBP_VEHICLE_PACKERS_H

#include <endian.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>

#include <libsbp/common.h>
#include <libsbp/unpacked/vehicle.h>

static inline size_t sbp_packed_size_sbp_msg_odometry_t(const sbp_msg_odometry_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->tow) + sizeof(msg->velocity) + sizeof(msg->flags);
}

static inline bool sbp_pack_sbp_msg_odometry_t(u8 *buf, size_t len, const sbp_msg_odometry_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_odometry_t(msg) > len)
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
  u32 msgvelocity = htole32(*(const u32 *)&msg->velocity);
  memcpy(buf + offset, &msgvelocity, 4);
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

static inline bool sbp_unpack_sbp_msg_odometry_t(const u8 *buf, size_t len, sbp_msg_odometry_t *msg)
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
  memcpy(&msg->velocity, buf + offset, 4);
  u32 msgvelocity = *(const u32 *)&msg->velocity;
  msgvelocity = le32toh(msgvelocity);
  msg->velocity = *(const s32 *)&msgvelocity;
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

static inline size_t sbp_packed_size_sbp_msg_wheeltick_t(const sbp_msg_wheeltick_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->time) + sizeof(msg->flags) + sizeof(msg->source) + sizeof(msg->ticks);
}

static inline bool sbp_pack_sbp_msg_wheeltick_t(u8 *buf, size_t len, const sbp_msg_wheeltick_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_wheeltick_t(msg) > len)
  {
    return false;
  }

  if (offset + 8 > len)
  {
    return false;
  }
  u64 msgtime = htole64(msg->time);
  memcpy(buf + offset, &msgtime, 8);
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

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgsource = msg->source;
  memcpy(buf + offset, &msgsource, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgticks = htole32(*(const u32 *)&msg->ticks);
  memcpy(buf + offset, &msgticks, 4);
  // NOLINTNEXTLINE
  offset += 4;
  return true;
}

static inline bool sbp_unpack_sbp_msg_wheeltick_t(const u8 *buf, size_t len, sbp_msg_wheeltick_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->time, buf + offset, 8);
  msg->time = le64toh(msg->time);
  // NOLINTNEXTLINE
  offset += 8;

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
  memcpy(&msg->source, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->ticks, buf + offset, 4);
  u32 msgticks = *(const u32 *)&msg->ticks;
  msgticks = le32toh(msgticks);
  msg->ticks = *(const s32 *)&msgticks;
  // NOLINTNEXTLINE
  offset += 4;
  return true;
}

#endif