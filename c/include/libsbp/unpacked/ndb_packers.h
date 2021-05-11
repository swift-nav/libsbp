#ifndef LIBSBP_NDB_PACKERS_H
#define LIBSBP_NDB_PACKERS_H

#ifndef LIBSBP_NDB_MESSAGES_H
#error "Do not include this file directly, include libsbp/unpacked/ndb.h instead"
#endif

#include <endian.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>

#include <libsbp/common.h>
#include <libsbp/string2.h>

static inline size_t sbp_packed_size_sbp_msg_ndb_event_t(const sbp_msg_ndb_event_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->recv_time) + sizeof(msg->event) + sizeof(msg->object_type) + sizeof(msg->result) +
         sizeof(msg->data_source) + (0 + sizeof(msg->object_sid.sat) + sizeof(msg->object_sid.code)) +
         (0 + sizeof(msg->src_sid.sat) + sizeof(msg->src_sid.code)) + sizeof(msg->original_sender);
}

static inline bool sbp_pack_sbp_msg_ndb_event_t(u8 *buf, size_t len, const sbp_msg_ndb_event_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_ndb_event_t(msg) > len)
  {
    return false;
  }

  if (offset + 8 > len)
  {
    return false;
  }
  u64 msgrecv_time = htole64(msg->recv_time);
  memcpy(buf + offset, &msgrecv_time, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgevent = msg->event;
  memcpy(buf + offset, &msgevent, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgobject_type = msg->object_type;
  memcpy(buf + offset, &msgobject_type, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgresult = msg->result;
  memcpy(buf + offset, &msgresult, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgdata_source = msg->data_source;
  memcpy(buf + offset, &msgdata_source, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgobject_sidsat = msg->object_sid.sat;
  memcpy(buf + offset, &msgobject_sidsat, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgobject_sidcode = msg->object_sid.code;
  memcpy(buf + offset, &msgobject_sidcode, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgsrc_sidsat = msg->src_sid.sat;
  memcpy(buf + offset, &msgsrc_sidsat, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgsrc_sidcode = msg->src_sid.code;
  memcpy(buf + offset, &msgsrc_sidcode, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgoriginal_sender = htole16(msg->original_sender);
  memcpy(buf + offset, &msgoriginal_sender, 2);
  // NOLINTNEXTLINE
  offset += 2;
  return true;
}

static inline bool sbp_unpack_sbp_msg_ndb_event_t(const u8 *buf, size_t len, sbp_msg_ndb_event_t *msg)
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
  memcpy(&msg->recv_time, buf + offset, 8);
  msg->recv_time = le64toh(msg->recv_time);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->event, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->object_type, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->result, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->data_source, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->object_sid.sat, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->object_sid.code, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->src_sid.sat, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->src_sid.code, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->original_sender, buf + offset, 2);
  msg->original_sender = le16toh(msg->original_sender);
  // NOLINTNEXTLINE
  offset += 2;
  return true;
}

#endif
