#ifndef LIBSBP_LOGGING_PACKERS_H
#define LIBSBP_LOGGING_PACKERS_H

#ifndef LIBSBP_LOGGING_MESSAGES_H
#error "Do not include this file directly, include libsbp/unpacked/logging.h instead"
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
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_log_t(const sbp_msg_log_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_u8(&msg->level);
  packed_size += sbp_unterminated_string_packed_len(&msg->text, 254
      );
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_log_t(u8 *buf, size_t len, const sbp_msg_log_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_log_t(msg) > len) { return false; }
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->level);
  offset += sbp_unterminated_string_pack(&msg->text, 254,
      buf + offset, (uint8_t)(len - offset));
  return true;
}

static inline bool sbp_unpack_sbp_msg_log_t(const uint8_t *buf, size_t len, sbp_msg_log_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->level);
  offset += sbp_unterminated_string_unpack(&msg->text, 254,
      buf + offset, (uint8_t)(len - offset));
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_fwd_t(const sbp_msg_fwd_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_u8(&msg->source);
  packed_size += sbp_packed_size_u8(&msg->protocol);
  packed_size += (msg->n_fwd_payload * sbp_packed_size_char(&msg->fwd_payload[0]));
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_fwd_t(u8 *buf, size_t len, const sbp_msg_fwd_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_fwd_t(msg) > len) { return false; }
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->source);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->protocol);
  for (uint8_t i = 0; i < msg->n_fwd_payload; i++) 
  {
    offset += sbp_pack_char(buf + offset, len - offset, &msg->fwd_payload[i]);
  }
  return true;
}

static inline bool sbp_unpack_sbp_msg_fwd_t(const uint8_t *buf, size_t len, sbp_msg_fwd_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->source);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->protocol);
  msg->n_fwd_payload = (uint8_t)((len - offset) / sbp_packed_size_char(&msg->fwd_payload[0]));
  for (uint8_t i = 0; i < msg->n_fwd_payload; i++)
  {
    offset += sbp_unpack_char(buf + offset, len - offset, &msg->fwd_payload[i]);
  }
  return true;
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_print_dep_t(const sbp_msg_print_dep_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_unterminated_string_packed_len(&msg->text, 255
      );
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_print_dep_t(u8 *buf, size_t len, const sbp_msg_print_dep_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_print_dep_t(msg) > len) { return false; }
  offset += sbp_unterminated_string_pack(&msg->text, 255,
      buf + offset, (uint8_t)(len - offset));
  return true;
}

static inline bool sbp_unpack_sbp_msg_print_dep_t(const uint8_t *buf, size_t len, sbp_msg_print_dep_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unterminated_string_unpack(&msg->text, 255,
      buf + offset, (uint8_t)(len - offset));
  return true;
}

#endif
