#ifndef LIBSBP_SBAS_PACKERS_H
#define LIBSBP_SBAS_PACKERS_H

#ifndef LIBSBP_SBAS_MESSAGES_H
#error "Do not include this file directly, include libsbp/unpacked/sbas.h instead"
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
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_sbas_raw_t(const sbp_msg_sbas_raw_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_sbp_sbp_gnss_signal_t(&msg->sid);
  packed_size += sbp_packed_size_u32(&msg->tow);
  packed_size += sbp_packed_size_u8(&msg->message_type);
  packed_size += ( 27 * sbp_packed_size_u8(&msg->data[0]));
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_sbas_raw_t(u8 *buf, size_t len, const sbp_msg_sbas_raw_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_sbas_raw_t(msg) > len) { return false; }
  offset += sbp_pack_sbp_sbp_gnss_signal_t(buf + offset, len - offset, &msg->sid);
  offset += sbp_pack_u32(buf + offset, len - offset, &msg->tow);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->message_type);
  for (uint8_t i = 0; i < 27; i++) 
  {
    offset += sbp_pack_u8(buf + offset, len - offset, &msg->data[i]);
  }
  return true;
}

static inline bool sbp_unpack_sbp_msg_sbas_raw_t(const uint8_t *buf, size_t len, sbp_msg_sbas_raw_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_sbp_sbp_gnss_signal_t(buf + offset, len - offset, &msg->sid);
  offset += sbp_unpack_u32(buf + offset, len - offset, &msg->tow);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->message_type);
  for (uint8_t i = 0; i < 27; i++)
  {
    offset += sbp_unpack_u8(buf + offset, len - offset, &msg->data[i]);
  }
  return true;
}

#endif
