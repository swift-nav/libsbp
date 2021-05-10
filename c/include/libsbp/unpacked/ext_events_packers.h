#ifndef LIBSBP_EXT_EVENTS_PACKERS_H
#define LIBSBP_EXT_EVENTS_PACKERS_H

#include <endian.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>

#include <libsbp/common.h>
#include <libsbp/string2.h>
//#include <libsbp/unpacked/ext_events.h>

static inline size_t sbp_packed_size_sbp_msg_ext_event_t(const sbp_msg_ext_event_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->wn) + sizeof(msg->tow) + sizeof(msg->ns_residual) + sizeof(msg->flags) + sizeof(msg->pin);
}

static inline bool sbp_pack_sbp_msg_ext_event_t(u8 *buf, size_t len, const sbp_msg_ext_event_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_ext_event_t(msg) > len)
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

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgpin = msg->pin;
  memcpy(buf + offset, &msgpin, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline bool sbp_unpack_sbp_msg_ext_event_t(const u8 *buf, size_t len, sbp_msg_ext_event_t *msg)
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

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->pin, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

#endif
