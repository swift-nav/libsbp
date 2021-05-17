#ifndef LIBSBP_SETTINGS_PACKERS_H
#define LIBSBP_SETTINGS_PACKERS_H

#ifndef LIBSBP_SETTINGS_MESSAGES_H
#error "Do not include this file directly, include libsbp/unpacked/settings.h instead"
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
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_settings_save_t(const sbp_msg_settings_save_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_settings_save_t(u8 *buf, size_t len, const sbp_msg_settings_save_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_settings_save_t(msg) > len) { return false; }
  return true;
}

static inline bool sbp_unpack_sbp_msg_settings_save_t(const uint8_t *buf, size_t len, sbp_msg_settings_save_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_settings_write_t(const sbp_msg_settings_write_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_multipart_string_packed_len(&msg->setting, 255
      , 3, 3
      );
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_settings_write_t(u8 *buf, size_t len, const sbp_msg_settings_write_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_settings_write_t(msg) > len) { return false; }
  offset += sbp_multipart_string_pack(&msg->setting, 255,3, 3,
      buf + offset, (uint8_t)(len - offset));
  return true;
}

static inline bool sbp_unpack_sbp_msg_settings_write_t(const uint8_t *buf, size_t len, sbp_msg_settings_write_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_multipart_string_unpack(&msg->setting, 255,3, 3,
      buf + offset, (uint8_t)(len - offset));
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_settings_write_resp_t(const sbp_msg_settings_write_resp_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_u8(&msg->status);
  packed_size += sbp_multipart_string_packed_len(&msg->setting, 254
      , 3, 3
      );
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_settings_write_resp_t(u8 *buf, size_t len, const sbp_msg_settings_write_resp_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_settings_write_resp_t(msg) > len) { return false; }
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->status);
  offset += sbp_multipart_string_pack(&msg->setting, 254,3, 3,
      buf + offset, (uint8_t)(len - offset));
  return true;
}

static inline bool sbp_unpack_sbp_msg_settings_write_resp_t(const uint8_t *buf, size_t len, sbp_msg_settings_write_resp_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->status);
  offset += sbp_multipart_string_unpack(&msg->setting, 254,3, 3,
      buf + offset, (uint8_t)(len - offset));
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_settings_read_req_t(const sbp_msg_settings_read_req_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_multipart_string_packed_len(&msg->setting, 255
      , 2, 2
      );
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_settings_read_req_t(u8 *buf, size_t len, const sbp_msg_settings_read_req_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_settings_read_req_t(msg) > len) { return false; }
  offset += sbp_multipart_string_pack(&msg->setting, 255,2, 2,
      buf + offset, (uint8_t)(len - offset));
  return true;
}

static inline bool sbp_unpack_sbp_msg_settings_read_req_t(const uint8_t *buf, size_t len, sbp_msg_settings_read_req_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_multipart_string_unpack(&msg->setting, 255,2, 2,
      buf + offset, (uint8_t)(len - offset));
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_settings_read_resp_t(const sbp_msg_settings_read_resp_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_multipart_string_packed_len(&msg->setting, 255
      , 3, 3
      );
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_settings_read_resp_t(u8 *buf, size_t len, const sbp_msg_settings_read_resp_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_settings_read_resp_t(msg) > len) { return false; }
  offset += sbp_multipart_string_pack(&msg->setting, 255,3, 3,
      buf + offset, (uint8_t)(len - offset));
  return true;
}

static inline bool sbp_unpack_sbp_msg_settings_read_resp_t(const uint8_t *buf, size_t len, sbp_msg_settings_read_resp_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_multipart_string_unpack(&msg->setting, 255,3, 3,
      buf + offset, (uint8_t)(len - offset));
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_settings_read_by_index_req_t(const sbp_msg_settings_read_by_index_req_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_u16(&msg->index);
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_settings_read_by_index_req_t(u8 *buf, size_t len, const sbp_msg_settings_read_by_index_req_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_settings_read_by_index_req_t(msg) > len) { return false; }
  offset += sbp_pack_u16(buf + offset, len - offset, &msg->index);
  return true;
}

static inline bool sbp_unpack_sbp_msg_settings_read_by_index_req_t(const uint8_t *buf, size_t len, sbp_msg_settings_read_by_index_req_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_u16(buf + offset, len - offset, &msg->index);
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_settings_read_by_index_resp_t(const sbp_msg_settings_read_by_index_resp_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_u16(&msg->index);
  packed_size += sbp_multipart_string_packed_len(&msg->setting, 253
      , 3, 4
      );
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_settings_read_by_index_resp_t(u8 *buf, size_t len, const sbp_msg_settings_read_by_index_resp_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_settings_read_by_index_resp_t(msg) > len) { return false; }
  offset += sbp_pack_u16(buf + offset, len - offset, &msg->index);
  offset += sbp_multipart_string_pack(&msg->setting, 253,3, 4,
      buf + offset, (uint8_t)(len - offset));
  return true;
}

static inline bool sbp_unpack_sbp_msg_settings_read_by_index_resp_t(const uint8_t *buf, size_t len, sbp_msg_settings_read_by_index_resp_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_u16(buf + offset, len - offset, &msg->index);
  offset += sbp_multipart_string_unpack(&msg->setting, 253,3, 4,
      buf + offset, (uint8_t)(len - offset));
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_settings_read_by_index_done_t(const sbp_msg_settings_read_by_index_done_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_settings_read_by_index_done_t(u8 *buf, size_t len, const sbp_msg_settings_read_by_index_done_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_settings_read_by_index_done_t(msg) > len) { return false; }
  return true;
}

static inline bool sbp_unpack_sbp_msg_settings_read_by_index_done_t(const uint8_t *buf, size_t len, sbp_msg_settings_read_by_index_done_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_settings_register_t(const sbp_msg_settings_register_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_multipart_string_packed_len(&msg->setting, 255
      , 3, 3
      );
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_settings_register_t(u8 *buf, size_t len, const sbp_msg_settings_register_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_settings_register_t(msg) > len) { return false; }
  offset += sbp_multipart_string_pack(&msg->setting, 255,3, 3,
      buf + offset, (uint8_t)(len - offset));
  return true;
}

static inline bool sbp_unpack_sbp_msg_settings_register_t(const uint8_t *buf, size_t len, sbp_msg_settings_register_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_multipart_string_unpack(&msg->setting, 255,3, 3,
      buf + offset, (uint8_t)(len - offset));
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_settings_register_resp_t(const sbp_msg_settings_register_resp_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_u8(&msg->status);
  packed_size += sbp_multipart_string_packed_len(&msg->setting, 254
      , 3, 3
      );
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_settings_register_resp_t(u8 *buf, size_t len, const sbp_msg_settings_register_resp_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_settings_register_resp_t(msg) > len) { return false; }
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->status);
  offset += sbp_multipart_string_pack(&msg->setting, 254,3, 3,
      buf + offset, (uint8_t)(len - offset));
  return true;
}

static inline bool sbp_unpack_sbp_msg_settings_register_resp_t(const uint8_t *buf, size_t len, sbp_msg_settings_register_resp_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->status);
  offset += sbp_multipart_string_unpack(&msg->setting, 254,3, 3,
      buf + offset, (uint8_t)(len - offset));
  return true;
}

#endif
