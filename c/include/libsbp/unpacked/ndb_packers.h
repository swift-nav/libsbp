#ifndef LIBSBP_NDB_PACKERS_H
#define LIBSBP_NDB_PACKERS_H

#ifndef LIBSBP_NDB_MESSAGES_H
#error "Do not include this file directly, include libsbp/unpacked/ndb.h instead"
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
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_ndb_event_t(const sbp_msg_ndb_event_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_u64(&msg->recv_time);
  packed_size += sbp_packed_size_u8(&msg->event);
  packed_size += sbp_packed_size_u8(&msg->object_type);
  packed_size += sbp_packed_size_u8(&msg->result);
  packed_size += sbp_packed_size_u8(&msg->data_source);
  packed_size += sbp_packed_size_sbp_sbp_gnss_signal_t(&msg->object_sid);
  packed_size += sbp_packed_size_sbp_sbp_gnss_signal_t(&msg->src_sid);
  packed_size += sbp_packed_size_u16(&msg->original_sender);
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_ndb_event_t(u8 *buf, size_t len, const sbp_msg_ndb_event_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_ndb_event_t(msg) > len) { return false; }
  offset += sbp_pack_u64(buf + offset, len - offset, &msg->recv_time);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->event);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->object_type);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->result);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->data_source);
  offset += sbp_pack_sbp_sbp_gnss_signal_t(buf + offset, len - offset, &msg->object_sid);
  offset += sbp_pack_sbp_sbp_gnss_signal_t(buf + offset, len - offset, &msg->src_sid);
  offset += sbp_pack_u16(buf + offset, len - offset, &msg->original_sender);
  return true;
}

static inline bool sbp_unpack_sbp_msg_ndb_event_t(const uint8_t *buf, size_t len, sbp_msg_ndb_event_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_u64(buf + offset, len - offset, &msg->recv_time);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->event);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->object_type);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->result);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->data_source);
  offset += sbp_unpack_sbp_sbp_gnss_signal_t(buf + offset, len - offset, &msg->object_sid);
  offset += sbp_unpack_sbp_sbp_gnss_signal_t(buf + offset, len - offset, &msg->src_sid);
  offset += sbp_unpack_u16(buf + offset, len - offset, &msg->original_sender);
  return true;
}

#endif
