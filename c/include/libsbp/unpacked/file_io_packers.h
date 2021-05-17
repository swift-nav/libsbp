#ifndef LIBSBP_FILE_IO_PACKERS_H
#define LIBSBP_FILE_IO_PACKERS_H

#ifndef LIBSBP_FILE_IO_MESSAGES_H
#error "Do not include this file directly, include libsbp/unpacked/file_io.h instead"
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
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_fileio_read_req_t(const sbp_msg_fileio_read_req_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_u32(&msg->sequence);
  packed_size += sbp_packed_size_u32(&msg->offset);
  packed_size += sbp_packed_size_u8(&msg->chunk_size);
  packed_size += sbp_null_terminated_string_packed_len(&msg->filename, 246
      );
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_fileio_read_req_t(u8 *buf, size_t len, const sbp_msg_fileio_read_req_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_fileio_read_req_t(msg) > len) { return false; }
  offset += sbp_pack_u32(buf + offset, len - offset, &msg->sequence);
  offset += sbp_pack_u32(buf + offset, len - offset, &msg->offset);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->chunk_size);
  offset += sbp_null_terminated_string_pack(&msg->filename, 246,
      buf + offset, (uint8_t)(len - offset));
  return true;
}

static inline bool sbp_unpack_sbp_msg_fileio_read_req_t(const uint8_t *buf, size_t len, sbp_msg_fileio_read_req_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_u32(buf + offset, len - offset, &msg->sequence);
  offset += sbp_unpack_u32(buf + offset, len - offset, &msg->offset);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->chunk_size);
  offset += sbp_null_terminated_string_unpack(&msg->filename, 246,
      buf + offset, (uint8_t)(len - offset));
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_fileio_read_resp_t(const sbp_msg_fileio_read_resp_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_u32(&msg->sequence);
  packed_size += (msg->n_contents * sbp_packed_size_u8(&msg->contents[0]));
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_fileio_read_resp_t(u8 *buf, size_t len, const sbp_msg_fileio_read_resp_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_fileio_read_resp_t(msg) > len) { return false; }
  offset += sbp_pack_u32(buf + offset, len - offset, &msg->sequence);
  for (uint8_t i = 0; i < msg->n_contents; i++) 
  {
    offset += sbp_pack_u8(buf + offset, len - offset, &msg->contents[i]);
  }
  return true;
}

static inline bool sbp_unpack_sbp_msg_fileio_read_resp_t(const uint8_t *buf, size_t len, sbp_msg_fileio_read_resp_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_u32(buf + offset, len - offset, &msg->sequence);
  msg->n_contents = (uint8_t)((len - offset) / sbp_packed_size_u8(&msg->contents[0]));
  for (uint8_t i = 0; i < msg->n_contents; i++)
  {
    offset += sbp_unpack_u8(buf + offset, len - offset, &msg->contents[i]);
  }
  return true;
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_fileio_read_dir_req_t(const sbp_msg_fileio_read_dir_req_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_u32(&msg->sequence);
  packed_size += sbp_packed_size_u32(&msg->offset);
  packed_size += sbp_null_terminated_string_packed_len(&msg->dirname, 247
      );
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_fileio_read_dir_req_t(u8 *buf, size_t len, const sbp_msg_fileio_read_dir_req_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_fileio_read_dir_req_t(msg) > len) { return false; }
  offset += sbp_pack_u32(buf + offset, len - offset, &msg->sequence);
  offset += sbp_pack_u32(buf + offset, len - offset, &msg->offset);
  offset += sbp_null_terminated_string_pack(&msg->dirname, 247,
      buf + offset, (uint8_t)(len - offset));
  return true;
}

static inline bool sbp_unpack_sbp_msg_fileio_read_dir_req_t(const uint8_t *buf, size_t len, sbp_msg_fileio_read_dir_req_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_u32(buf + offset, len - offset, &msg->sequence);
  offset += sbp_unpack_u32(buf + offset, len - offset, &msg->offset);
  offset += sbp_null_terminated_string_unpack(&msg->dirname, 247,
      buf + offset, (uint8_t)(len - offset));
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_fileio_read_dir_resp_t(const sbp_msg_fileio_read_dir_resp_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_u32(&msg->sequence);
  packed_size += sbp_sequence_string_packed_len(&msg->contents, 251
      , 255
      );
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_fileio_read_dir_resp_t(u8 *buf, size_t len, const sbp_msg_fileio_read_dir_resp_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_fileio_read_dir_resp_t(msg) > len) { return false; }
  offset += sbp_pack_u32(buf + offset, len - offset, &msg->sequence);
  offset += sbp_sequence_string_pack(&msg->contents, 251,255,
      buf + offset, (uint8_t)(len - offset));
  return true;
}

static inline bool sbp_unpack_sbp_msg_fileio_read_dir_resp_t(const uint8_t *buf, size_t len, sbp_msg_fileio_read_dir_resp_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_u32(buf + offset, len - offset, &msg->sequence);
  offset += sbp_sequence_string_unpack(&msg->contents, 251,255,
      buf + offset, (uint8_t)(len - offset));
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_fileio_remove_t(const sbp_msg_fileio_remove_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_null_terminated_string_packed_len(&msg->filename, 255
      );
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_fileio_remove_t(u8 *buf, size_t len, const sbp_msg_fileio_remove_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_fileio_remove_t(msg) > len) { return false; }
  offset += sbp_null_terminated_string_pack(&msg->filename, 255,
      buf + offset, (uint8_t)(len - offset));
  return true;
}

static inline bool sbp_unpack_sbp_msg_fileio_remove_t(const uint8_t *buf, size_t len, sbp_msg_fileio_remove_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_null_terminated_string_unpack(&msg->filename, 255,
      buf + offset, (uint8_t)(len - offset));
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_fileio_write_req_t(const sbp_msg_fileio_write_req_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_u32(&msg->sequence);
  packed_size += sbp_packed_size_u32(&msg->offset);
  packed_size += sbp_null_terminated_string_packed_len(&msg->filename, 247
      );
  packed_size += (msg->n_data * sbp_packed_size_u8(&msg->data[0]));
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_fileio_write_req_t(u8 *buf, size_t len, const sbp_msg_fileio_write_req_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_fileio_write_req_t(msg) > len) { return false; }
  offset += sbp_pack_u32(buf + offset, len - offset, &msg->sequence);
  offset += sbp_pack_u32(buf + offset, len - offset, &msg->offset);
  offset += sbp_null_terminated_string_pack(&msg->filename, 247,
      buf + offset, (uint8_t)(len - offset));
  for (uint8_t i = 0; i < msg->n_data; i++) 
  {
    offset += sbp_pack_u8(buf + offset, len - offset, &msg->data[i]);
  }
  return true;
}

static inline bool sbp_unpack_sbp_msg_fileio_write_req_t(const uint8_t *buf, size_t len, sbp_msg_fileio_write_req_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_u32(buf + offset, len - offset, &msg->sequence);
  offset += sbp_unpack_u32(buf + offset, len - offset, &msg->offset);
  offset += sbp_null_terminated_string_unpack(&msg->filename, 247,
      buf + offset, (uint8_t)(len - offset));
  msg->n_data = (uint8_t)((len - offset) / sbp_packed_size_u8(&msg->data[0]));
  for (uint8_t i = 0; i < msg->n_data; i++)
  {
    offset += sbp_unpack_u8(buf + offset, len - offset, &msg->data[i]);
  }
  return true;
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_fileio_write_resp_t(const sbp_msg_fileio_write_resp_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_u32(&msg->sequence);
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_fileio_write_resp_t(u8 *buf, size_t len, const sbp_msg_fileio_write_resp_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_fileio_write_resp_t(msg) > len) { return false; }
  offset += sbp_pack_u32(buf + offset, len - offset, &msg->sequence);
  return true;
}

static inline bool sbp_unpack_sbp_msg_fileio_write_resp_t(const uint8_t *buf, size_t len, sbp_msg_fileio_write_resp_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_u32(buf + offset, len - offset, &msg->sequence);
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_fileio_config_req_t(const sbp_msg_fileio_config_req_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_u32(&msg->sequence);
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_fileio_config_req_t(u8 *buf, size_t len, const sbp_msg_fileio_config_req_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_fileio_config_req_t(msg) > len) { return false; }
  offset += sbp_pack_u32(buf + offset, len - offset, &msg->sequence);
  return true;
}

static inline bool sbp_unpack_sbp_msg_fileio_config_req_t(const uint8_t *buf, size_t len, sbp_msg_fileio_config_req_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_u32(buf + offset, len - offset, &msg->sequence);
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_fileio_config_resp_t(const sbp_msg_fileio_config_resp_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_u32(&msg->sequence);
  packed_size += sbp_packed_size_u32(&msg->window_size);
  packed_size += sbp_packed_size_u32(&msg->batch_size);
  packed_size += sbp_packed_size_u32(&msg->fileio_version);
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_fileio_config_resp_t(u8 *buf, size_t len, const sbp_msg_fileio_config_resp_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_fileio_config_resp_t(msg) > len) { return false; }
  offset += sbp_pack_u32(buf + offset, len - offset, &msg->sequence);
  offset += sbp_pack_u32(buf + offset, len - offset, &msg->window_size);
  offset += sbp_pack_u32(buf + offset, len - offset, &msg->batch_size);
  offset += sbp_pack_u32(buf + offset, len - offset, &msg->fileio_version);
  return true;
}

static inline bool sbp_unpack_sbp_msg_fileio_config_resp_t(const uint8_t *buf, size_t len, sbp_msg_fileio_config_resp_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_u32(buf + offset, len - offset, &msg->sequence);
  offset += sbp_unpack_u32(buf + offset, len - offset, &msg->window_size);
  offset += sbp_unpack_u32(buf + offset, len - offset, &msg->batch_size);
  offset += sbp_unpack_u32(buf + offset, len - offset, &msg->fileio_version);
  return true;
}

#endif
