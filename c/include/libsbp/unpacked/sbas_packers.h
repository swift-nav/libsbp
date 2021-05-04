#ifndef LIBSBP_SBAS_PACKERS_H
#define LIBSBP_SBAS_PACKERS_H

#include <endian.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>

#include <libsbp/common.h>
#include <libsbp/unpacked/gnss.h>
#include <libsbp/unpacked/sbas.h>

static inline size_t sbp_packed_size_sbp_msg_sbas_raw_t(const sbp_msg_sbas_raw_t *msg)
{
  (void)msg;
  return 0 + (0 + sizeof(msg->sid.sat) + sizeof(msg->sid.code)) + sizeof(msg->tow) + sizeof(msg->message_type) +
         (27 * sizeof(msg->data[0]));
}

static inline bool sbp_pack_sbp_msg_sbas_raw_t(u8 *buf, size_t len, const sbp_msg_sbas_raw_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_sbas_raw_t(msg) > len)
  {
    return false;
  }

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgsidsat = msg->sid.sat;
  memcpy(buf + offset, &msgsidsat, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgsidcode = msg->sid.code;
  memcpy(buf + offset, &msgsidcode, 1);
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

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgmessage_type = msg->message_type;
  memcpy(buf + offset, &msgmessage_type, 1);
  // NOLINTNEXTLINE
  offset += 1;
  for (size_t msgdata_idx = 0; msgdata_idx < 27; msgdata_idx++)
  {

    if (offset + 1 > len)
    {
      return false;
    }
    u8 msgdatamsgdata_idx = msg->data[msgdata_idx];
    memcpy(buf + offset, &msgdatamsgdata_idx, 1);
    // NOLINTNEXTLINE
    offset += 1;
  }
  return true;
}

static inline bool sbp_unpack_sbp_msg_sbas_raw_t(const u8 *buf, size_t len, sbp_msg_sbas_raw_t *msg)
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
  memcpy(&msg->sid.sat, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->sid.code, buf + offset, 1);
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

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->message_type, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
  for (size_t msgdata_idx = 0; msgdata_idx < 27; msgdata_idx++)
  {

    if (offset + 1 > len)
    {
      return false;
    }
    memcpy(&msg->data[msgdata_idx], buf + offset, 1);
    // NOLINTNEXTLINE
    offset += 1;
  }
  return true;
}

#endif