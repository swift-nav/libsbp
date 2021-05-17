#ifndef LIBSBP_USER_PACKERS_H
#define LIBSBP_USER_PACKERS_H

#ifndef LIBSBP_USER_MESSAGES_H
#error "Do not include this file directly, include libsbp/unpacked/user.h instead"
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
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_user_data_t(const sbp_msg_user_data_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += (msg->n_contents * sbp_packed_size_u8(&msg->contents[0]));
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_user_data_t(u8 *buf, size_t len, const sbp_msg_user_data_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_user_data_t(msg) > len) { return false; }
  for (uint8_t i = 0; i < msg->n_contents; i++) 
  {
    offset += sbp_pack_u8(buf + offset, len - offset, &msg->contents[i]);
  }
  return true;
}

static inline bool sbp_unpack_sbp_msg_user_data_t(const uint8_t *buf, size_t len, sbp_msg_user_data_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  msg->n_contents = (uint8_t)((len - offset) / sbp_packed_size_u8(&msg->contents[0]));
  for (uint8_t i = 0; i < msg->n_contents; i++)
  {
    offset += sbp_unpack_u8(buf + offset, len - offset, &msg->contents[i]);
  }
  return true;
  return true;
}

#endif
