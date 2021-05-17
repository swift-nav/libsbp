#ifndef LIBSBP_EXT_EVENTS_PACKERS_H
#define LIBSBP_EXT_EVENTS_PACKERS_H

#ifndef LIBSBP_EXT_EVENTS_MESSAGES_H
#error "Do not include this file directly, include libsbp/unpacked/ext_events.h instead"
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
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_ext_event_t(const sbp_msg_ext_event_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_u16(&msg->wn);
  packed_size += sbp_packed_size_u32(&msg->tow);
  packed_size += sbp_packed_size_s32(&msg->ns_residual);
  packed_size += sbp_packed_size_u8(&msg->flags);
  packed_size += sbp_packed_size_u8(&msg->pin);
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_ext_event_t(u8 *buf, size_t len, const sbp_msg_ext_event_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_ext_event_t(msg) > len) { return false; }
  offset += sbp_pack_u16(buf + offset, len - offset, &msg->wn);
  offset += sbp_pack_u32(buf + offset, len - offset, &msg->tow);
  offset += sbp_pack_s32(buf + offset, len - offset, &msg->ns_residual);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->flags);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->pin);
  return true;
}

static inline bool sbp_unpack_sbp_msg_ext_event_t(const uint8_t *buf, size_t len, sbp_msg_ext_event_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_u16(buf + offset, len - offset, &msg->wn);
  offset += sbp_unpack_u32(buf + offset, len - offset, &msg->tow);
  offset += sbp_unpack_s32(buf + offset, len - offset, &msg->ns_residual);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->flags);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->pin);
  return true;
}

#endif
