#ifndef LIBSBP_BOOTLOAD_PACKERS_H
#define LIBSBP_BOOTLOAD_PACKERS_H

#ifndef LIBSBP_BOOTLOAD_MESSAGES_H
#error "Do not include this file directly, include libsbp/unpacked/bootload.h instead"
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
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_bootloader_handshake_req_t(const sbp_msg_bootloader_handshake_req_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_bootloader_handshake_req_t(u8 *buf, size_t len, const sbp_msg_bootloader_handshake_req_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_bootloader_handshake_req_t(msg) > len) { return false; }
  return true;
}

static inline bool sbp_unpack_sbp_msg_bootloader_handshake_req_t(const uint8_t *buf, size_t len, sbp_msg_bootloader_handshake_req_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_bootloader_handshake_resp_t(const sbp_msg_bootloader_handshake_resp_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_u32(&msg->flags);
  packed_size += sbp_unterminated_string_packed_len(&msg->version, 251
      );
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_bootloader_handshake_resp_t(u8 *buf, size_t len, const sbp_msg_bootloader_handshake_resp_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_bootloader_handshake_resp_t(msg) > len) { return false; }
  offset += sbp_pack_u32(buf + offset, len - offset, &msg->flags);
  offset += sbp_unterminated_string_pack(&msg->version, 251,
      buf + offset, (uint8_t)(len - offset));
  return true;
}

static inline bool sbp_unpack_sbp_msg_bootloader_handshake_resp_t(const uint8_t *buf, size_t len, sbp_msg_bootloader_handshake_resp_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_u32(buf + offset, len - offset, &msg->flags);
  offset += sbp_unterminated_string_unpack(&msg->version, 251,
      buf + offset, (uint8_t)(len - offset));
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_bootloader_jump_to_app_t(const sbp_msg_bootloader_jump_to_app_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_u8(&msg->jump);
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_bootloader_jump_to_app_t(u8 *buf, size_t len, const sbp_msg_bootloader_jump_to_app_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_bootloader_jump_to_app_t(msg) > len) { return false; }
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->jump);
  return true;
}

static inline bool sbp_unpack_sbp_msg_bootloader_jump_to_app_t(const uint8_t *buf, size_t len, sbp_msg_bootloader_jump_to_app_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->jump);
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_nap_device_dna_req_t(const sbp_msg_nap_device_dna_req_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_nap_device_dna_req_t(u8 *buf, size_t len, const sbp_msg_nap_device_dna_req_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_nap_device_dna_req_t(msg) > len) { return false; }
  return true;
}

static inline bool sbp_unpack_sbp_msg_nap_device_dna_req_t(const uint8_t *buf, size_t len, sbp_msg_nap_device_dna_req_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_nap_device_dna_resp_t(const sbp_msg_nap_device_dna_resp_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += ( 8 * sbp_packed_size_u8(&msg->dna[0]));
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_nap_device_dna_resp_t(u8 *buf, size_t len, const sbp_msg_nap_device_dna_resp_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_nap_device_dna_resp_t(msg) > len) { return false; }
  for (uint8_t i = 0; i < 8; i++) 
  {
    offset += sbp_pack_u8(buf + offset, len - offset, &msg->dna[i]);
  }
  return true;
}

static inline bool sbp_unpack_sbp_msg_nap_device_dna_resp_t(const uint8_t *buf, size_t len, sbp_msg_nap_device_dna_resp_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  for (uint8_t i = 0; i < 8; i++)
  {
    offset += sbp_unpack_u8(buf + offset, len - offset, &msg->dna[i]);
  }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_bootloader_handshake_dep_a_t(const sbp_msg_bootloader_handshake_dep_a_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_unterminated_string_packed_len(&msg->handshake, 255
      );
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_bootloader_handshake_dep_a_t(u8 *buf, size_t len, const sbp_msg_bootloader_handshake_dep_a_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_bootloader_handshake_dep_a_t(msg) > len) { return false; }
  offset += sbp_unterminated_string_pack(&msg->handshake, 255,
      buf + offset, (uint8_t)(len - offset));
  return true;
}

static inline bool sbp_unpack_sbp_msg_bootloader_handshake_dep_a_t(const uint8_t *buf, size_t len, sbp_msg_bootloader_handshake_dep_a_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unterminated_string_unpack(&msg->handshake, 255,
      buf + offset, (uint8_t)(len - offset));
  return true;
}

#endif
