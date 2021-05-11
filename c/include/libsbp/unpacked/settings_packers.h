#ifndef LIBSBP_SETTINGS_PACKERS_H
#define LIBSBP_SETTINGS_PACKERS_H

#include <endian.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>

#include <libsbp/common.h>
#include <libsbp/string2.h>
//#include <libsbp/unpacked/settings.h>

static inline size_t sbp_packed_size_sbp_msg_settings_save_t(const sbp_msg_settings_save_t *msg)
{
  (void)msg;
  return 0;
}

static inline bool sbp_pack_sbp_msg_settings_save_t(u8 *buf, size_t len, const sbp_msg_settings_save_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_settings_save_t(msg) > len)
  {
    return false;
  }

  return true;
}

static inline bool sbp_unpack_sbp_msg_settings_save_t(const u8 *buf, size_t len, sbp_msg_settings_save_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  return true;
}

static inline size_t sbp_packed_size_sbp_msg_settings_write_t(const sbp_msg_settings_write_t *msg)
{
  (void)msg;
  return 0 + sbp_multipart_string_packed_len(&msg->setting, 255, 3, 3);
}

static inline bool sbp_pack_sbp_msg_settings_write_t(u8 *buf, size_t len, const sbp_msg_settings_write_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_settings_write_t(msg) > len)
  {
    return false;
  }

  offset += sbp_multipart_string_pack(&msg->setting, 255, 3, 3, buf + offset, (uint8_t)(len - offset));
  return true;
}

static inline bool sbp_unpack_sbp_msg_settings_write_t(const u8 *buf, size_t len, sbp_msg_settings_write_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  offset += sbp_multipart_string_unpack(&msg->setting, 255, 3, 3, buf + offset, (uint8_t)(len - offset));
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_settings_write_resp_t(const sbp_msg_settings_write_resp_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->status) + sbp_multipart_string_packed_len(&msg->setting, 254, 3, 3);
}

static inline bool sbp_pack_sbp_msg_settings_write_resp_t(u8 *buf, size_t len, const sbp_msg_settings_write_resp_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_settings_write_resp_t(msg) > len)
  {
    return false;
  }

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgstatus = msg->status;
  memcpy(buf + offset, &msgstatus, 1);
  // NOLINTNEXTLINE
  offset += 1;
  offset += sbp_multipart_string_pack(&msg->setting, 254, 3, 3, buf + offset, (uint8_t)(len - offset));
  return true;
}

static inline bool
sbp_unpack_sbp_msg_settings_write_resp_t(const u8 *buf, size_t len, sbp_msg_settings_write_resp_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->status, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
  offset += sbp_multipart_string_unpack(&msg->setting, 254, 3, 3, buf + offset, (uint8_t)(len - offset));
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_settings_read_req_t(const sbp_msg_settings_read_req_t *msg)
{
  (void)msg;
  return 0 + sbp_multipart_string_packed_len(&msg->setting, 255, 2, 2);
}

static inline bool sbp_pack_sbp_msg_settings_read_req_t(u8 *buf, size_t len, const sbp_msg_settings_read_req_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_settings_read_req_t(msg) > len)
  {
    return false;
  }

  offset += sbp_multipart_string_pack(&msg->setting, 255, 2, 2, buf + offset, (uint8_t)(len - offset));
  return true;
}

static inline bool sbp_unpack_sbp_msg_settings_read_req_t(const u8 *buf, size_t len, sbp_msg_settings_read_req_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  offset += sbp_multipart_string_unpack(&msg->setting, 255, 2, 2, buf + offset, (uint8_t)(len - offset));
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_settings_read_resp_t(const sbp_msg_settings_read_resp_t *msg)
{
  (void)msg;
  return 0 + sbp_multipart_string_packed_len(&msg->setting, 255, 3, 3);
}

static inline bool sbp_pack_sbp_msg_settings_read_resp_t(u8 *buf, size_t len, const sbp_msg_settings_read_resp_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_settings_read_resp_t(msg) > len)
  {
    return false;
  }

  offset += sbp_multipart_string_pack(&msg->setting, 255, 3, 3, buf + offset, (uint8_t)(len - offset));
  return true;
}

static inline bool sbp_unpack_sbp_msg_settings_read_resp_t(const u8 *buf, size_t len, sbp_msg_settings_read_resp_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  offset += sbp_multipart_string_unpack(&msg->setting, 255, 3, 3, buf + offset, (uint8_t)(len - offset));
  return true;
}

static inline size_t
sbp_packed_size_sbp_msg_settings_read_by_index_req_t(const sbp_msg_settings_read_by_index_req_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->index);
}

static inline bool
sbp_pack_sbp_msg_settings_read_by_index_req_t(u8 *buf, size_t len, const sbp_msg_settings_read_by_index_req_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_settings_read_by_index_req_t(msg) > len)
  {
    return false;
  }

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgindex = htole16(msg->index);
  memcpy(buf + offset, &msgindex, 2);
  // NOLINTNEXTLINE
  offset += 2;
  return true;
}

static inline bool
sbp_unpack_sbp_msg_settings_read_by_index_req_t(const u8 *buf, size_t len, sbp_msg_settings_read_by_index_req_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->index, buf + offset, 2);
  msg->index = le16toh(msg->index);
  // NOLINTNEXTLINE
  offset += 2;
  return true;
}

static inline size_t
sbp_packed_size_sbp_msg_settings_read_by_index_resp_t(const sbp_msg_settings_read_by_index_resp_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->index) + sbp_multipart_string_packed_len(&msg->setting, 253, 3, 4);
}

static inline bool
sbp_pack_sbp_msg_settings_read_by_index_resp_t(u8 *buf, size_t len, const sbp_msg_settings_read_by_index_resp_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_settings_read_by_index_resp_t(msg) > len)
  {
    return false;
  }

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgindex = htole16(msg->index);
  memcpy(buf + offset, &msgindex, 2);
  // NOLINTNEXTLINE
  offset += 2;
  offset += sbp_multipart_string_pack(&msg->setting, 253, 3, 4, buf + offset, (uint8_t)(len - offset));
  return true;
}

static inline bool
sbp_unpack_sbp_msg_settings_read_by_index_resp_t(const u8 *buf, size_t len, sbp_msg_settings_read_by_index_resp_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->index, buf + offset, 2);
  msg->index = le16toh(msg->index);
  // NOLINTNEXTLINE
  offset += 2;
  offset += sbp_multipart_string_unpack(&msg->setting, 253, 3, 4, buf + offset, (uint8_t)(len - offset));
  return true;
}

static inline size_t
sbp_packed_size_sbp_msg_settings_read_by_index_done_t(const sbp_msg_settings_read_by_index_done_t *msg)
{
  (void)msg;
  return 0;
}

static inline bool
sbp_pack_sbp_msg_settings_read_by_index_done_t(u8 *buf, size_t len, const sbp_msg_settings_read_by_index_done_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_settings_read_by_index_done_t(msg) > len)
  {
    return false;
  }

  return true;
}

static inline bool
sbp_unpack_sbp_msg_settings_read_by_index_done_t(const u8 *buf, size_t len, sbp_msg_settings_read_by_index_done_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  return true;
}

static inline size_t sbp_packed_size_sbp_msg_settings_register_t(const sbp_msg_settings_register_t *msg)
{
  (void)msg;
  return 0 + sbp_multipart_string_packed_len(&msg->setting, 255, 3, 3);
}

static inline bool sbp_pack_sbp_msg_settings_register_t(u8 *buf, size_t len, const sbp_msg_settings_register_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_settings_register_t(msg) > len)
  {
    return false;
  }

  offset += sbp_multipart_string_pack(&msg->setting, 255, 3, 3, buf + offset, (uint8_t)(len - offset));
  return true;
}

static inline bool sbp_unpack_sbp_msg_settings_register_t(const u8 *buf, size_t len, sbp_msg_settings_register_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  offset += sbp_multipart_string_unpack(&msg->setting, 255, 3, 3, buf + offset, (uint8_t)(len - offset));
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_settings_register_resp_t(const sbp_msg_settings_register_resp_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->status) + sbp_multipart_string_packed_len(&msg->setting, 254, 3, 3);
}

static inline bool
sbp_pack_sbp_msg_settings_register_resp_t(u8 *buf, size_t len, const sbp_msg_settings_register_resp_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_settings_register_resp_t(msg) > len)
  {
    return false;
  }

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgstatus = msg->status;
  memcpy(buf + offset, &msgstatus, 1);
  // NOLINTNEXTLINE
  offset += 1;
  offset += sbp_multipart_string_pack(&msg->setting, 254, 3, 3, buf + offset, (uint8_t)(len - offset));
  return true;
}

static inline bool
sbp_unpack_sbp_msg_settings_register_resp_t(const u8 *buf, size_t len, sbp_msg_settings_register_resp_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->status, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
  offset += sbp_multipart_string_unpack(&msg->setting, 254, 3, 3, buf + offset, (uint8_t)(len - offset));
  return true;
}

#endif
