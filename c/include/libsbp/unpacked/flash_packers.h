#ifndef LIBSBP_FLASH_PACKERS_H
#define LIBSBP_FLASH_PACKERS_H

#ifndef LIBSBP_FLASH_MESSAGES_H
#error "Do not include this file directly, include libsbp/unpacked/flash.h instead"
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
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_flash_program_t(const sbp_msg_flash_program_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_u8(&msg->target);
  packed_size += ( 3 * sbp_packed_size_u8(&msg->addr_start[0]));
  packed_size += sbp_packed_size_u8(&msg->addr_len);
  packed_size += (msg->addr_len * sbp_packed_size_u8(&msg->data[0]));
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_flash_program_t(u8 *buf, size_t len, const sbp_msg_flash_program_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_flash_program_t(msg) > len) { return false; }
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->target);
  for (uint8_t i = 0; i < 3; i++) 
  {
    offset += sbp_pack_u8(buf + offset, len - offset, &msg->addr_start[i]);
  }
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->addr_len);
  for (uint8_t i = 0; i < msg->addr_len; i++) 
  {
    offset += sbp_pack_u8(buf + offset, len - offset, &msg->data[i]);
  }
  return true;
}

static inline bool sbp_unpack_sbp_msg_flash_program_t(const uint8_t *buf, size_t len, sbp_msg_flash_program_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->target);
  for (uint8_t i = 0; i < 3; i++)
  {
    offset += sbp_unpack_u8(buf + offset, len - offset, &msg->addr_start[i]);
  }
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->addr_len);
  msg->addr_len = (uint8_t)((len - offset) / sbp_packed_size_u8(&msg->data[0]));
  for (uint8_t i = 0; i < msg->addr_len; i++)
  {
    offset += sbp_unpack_u8(buf + offset, len - offset, &msg->data[i]);
  }
  return true;
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_flash_done_t(const sbp_msg_flash_done_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_u8(&msg->response);
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_flash_done_t(u8 *buf, size_t len, const sbp_msg_flash_done_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_flash_done_t(msg) > len) { return false; }
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->response);
  return true;
}

static inline bool sbp_unpack_sbp_msg_flash_done_t(const uint8_t *buf, size_t len, sbp_msg_flash_done_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->response);
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_flash_read_req_t(const sbp_msg_flash_read_req_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_u8(&msg->target);
  packed_size += ( 3 * sbp_packed_size_u8(&msg->addr_start[0]));
  packed_size += sbp_packed_size_u8(&msg->addr_len);
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_flash_read_req_t(u8 *buf, size_t len, const sbp_msg_flash_read_req_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_flash_read_req_t(msg) > len) { return false; }
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->target);
  for (uint8_t i = 0; i < 3; i++) 
  {
    offset += sbp_pack_u8(buf + offset, len - offset, &msg->addr_start[i]);
  }
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->addr_len);
  return true;
}

static inline bool sbp_unpack_sbp_msg_flash_read_req_t(const uint8_t *buf, size_t len, sbp_msg_flash_read_req_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->target);
  for (uint8_t i = 0; i < 3; i++)
  {
    offset += sbp_unpack_u8(buf + offset, len - offset, &msg->addr_start[i]);
  }
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->addr_len);
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_flash_read_resp_t(const sbp_msg_flash_read_resp_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_u8(&msg->target);
  packed_size += ( 3 * sbp_packed_size_u8(&msg->addr_start[0]));
  packed_size += sbp_packed_size_u8(&msg->addr_len);
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_flash_read_resp_t(u8 *buf, size_t len, const sbp_msg_flash_read_resp_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_flash_read_resp_t(msg) > len) { return false; }
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->target);
  for (uint8_t i = 0; i < 3; i++) 
  {
    offset += sbp_pack_u8(buf + offset, len - offset, &msg->addr_start[i]);
  }
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->addr_len);
  return true;
}

static inline bool sbp_unpack_sbp_msg_flash_read_resp_t(const uint8_t *buf, size_t len, sbp_msg_flash_read_resp_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->target);
  for (uint8_t i = 0; i < 3; i++)
  {
    offset += sbp_unpack_u8(buf + offset, len - offset, &msg->addr_start[i]);
  }
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->addr_len);
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_flash_erase_t(const sbp_msg_flash_erase_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_u8(&msg->target);
  packed_size += sbp_packed_size_u32(&msg->sector_num);
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_flash_erase_t(u8 *buf, size_t len, const sbp_msg_flash_erase_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_flash_erase_t(msg) > len) { return false; }
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->target);
  offset += sbp_pack_u32(buf + offset, len - offset, &msg->sector_num);
  return true;
}

static inline bool sbp_unpack_sbp_msg_flash_erase_t(const uint8_t *buf, size_t len, sbp_msg_flash_erase_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->target);
  offset += sbp_unpack_u32(buf + offset, len - offset, &msg->sector_num);
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_stm_flash_lock_sector_t(const sbp_msg_stm_flash_lock_sector_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_u32(&msg->sector);
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_stm_flash_lock_sector_t(u8 *buf, size_t len, const sbp_msg_stm_flash_lock_sector_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_stm_flash_lock_sector_t(msg) > len) { return false; }
  offset += sbp_pack_u32(buf + offset, len - offset, &msg->sector);
  return true;
}

static inline bool sbp_unpack_sbp_msg_stm_flash_lock_sector_t(const uint8_t *buf, size_t len, sbp_msg_stm_flash_lock_sector_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_u32(buf + offset, len - offset, &msg->sector);
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_stm_flash_unlock_sector_t(const sbp_msg_stm_flash_unlock_sector_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_u32(&msg->sector);
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_stm_flash_unlock_sector_t(u8 *buf, size_t len, const sbp_msg_stm_flash_unlock_sector_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_stm_flash_unlock_sector_t(msg) > len) { return false; }
  offset += sbp_pack_u32(buf + offset, len - offset, &msg->sector);
  return true;
}

static inline bool sbp_unpack_sbp_msg_stm_flash_unlock_sector_t(const uint8_t *buf, size_t len, sbp_msg_stm_flash_unlock_sector_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_u32(buf + offset, len - offset, &msg->sector);
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_stm_unique_id_req_t(const sbp_msg_stm_unique_id_req_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_stm_unique_id_req_t(u8 *buf, size_t len, const sbp_msg_stm_unique_id_req_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_stm_unique_id_req_t(msg) > len) { return false; }
  return true;
}

static inline bool sbp_unpack_sbp_msg_stm_unique_id_req_t(const uint8_t *buf, size_t len, sbp_msg_stm_unique_id_req_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_stm_unique_id_resp_t(const sbp_msg_stm_unique_id_resp_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += ( 12 * sbp_packed_size_u8(&msg->stm_id[0]));
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_stm_unique_id_resp_t(u8 *buf, size_t len, const sbp_msg_stm_unique_id_resp_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_stm_unique_id_resp_t(msg) > len) { return false; }
  for (uint8_t i = 0; i < 12; i++) 
  {
    offset += sbp_pack_u8(buf + offset, len - offset, &msg->stm_id[i]);
  }
  return true;
}

static inline bool sbp_unpack_sbp_msg_stm_unique_id_resp_t(const uint8_t *buf, size_t len, sbp_msg_stm_unique_id_resp_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  for (uint8_t i = 0; i < 12; i++)
  {
    offset += sbp_unpack_u8(buf + offset, len - offset, &msg->stm_id[i]);
  }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_m25_flash_write_status_t(const sbp_msg_m25_flash_write_status_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += ( 1 * sbp_packed_size_u8(&msg->status[0]));
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_m25_flash_write_status_t(u8 *buf, size_t len, const sbp_msg_m25_flash_write_status_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_m25_flash_write_status_t(msg) > len) { return false; }
  for (uint8_t i = 0; i < 1; i++) 
  {
    offset += sbp_pack_u8(buf + offset, len - offset, &msg->status[i]);
  }
  return true;
}

static inline bool sbp_unpack_sbp_msg_m25_flash_write_status_t(const uint8_t *buf, size_t len, sbp_msg_m25_flash_write_status_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  for (uint8_t i = 0; i < 1; i++)
  {
    offset += sbp_unpack_u8(buf + offset, len - offset, &msg->status[i]);
  }
  return true;
}

#endif
