#ifndef LIBSBP_FLASH_PACKERS_H
#define LIBSBP_FLASH_PACKERS_H

#ifndef LIBSBP_FLASH_MESSAGES_H
#error "Do not include this file directly, include libsbp/unpacked/flash.h instead"
#endif

#include <endian.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>

#include <libsbp/common.h>
#include <libsbp/string2.h>

static inline size_t sbp_packed_size_sbp_msg_flash_program_t(const sbp_msg_flash_program_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->target) + (3 * sizeof(msg->addr_start[0])) + sizeof(msg->addr_len) +
         (msg->addr_len * sizeof(msg->data[0]));
}

static inline bool sbp_pack_sbp_msg_flash_program_t(u8 *buf, size_t len, const sbp_msg_flash_program_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_flash_program_t(msg) > len)
  {
    return false;
  }

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgtarget = msg->target;
  memcpy(buf + offset, &msgtarget, 1);
  // NOLINTNEXTLINE
  offset += 1;
  for (size_t msgaddr_start_idx = 0; msgaddr_start_idx < 3; msgaddr_start_idx++)
  {

    if (offset + 1 > len)
    {
      return false;
    }
    u8 msgaddr_startmsgaddr_start_idx = msg->addr_start[msgaddr_start_idx];
    memcpy(buf + offset, &msgaddr_startmsgaddr_start_idx, 1);
    // NOLINTNEXTLINE
    offset += 1;
  }

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgaddr_len = msg->addr_len;
  memcpy(buf + offset, &msgaddr_len, 1);
  // NOLINTNEXTLINE
  offset += 1;
  for (size_t msgdata_idx = 0; msgdata_idx < (size_t)msg->addr_len; msgdata_idx++)
  {

    if (offset + 1 > len)
    {
      return false;
    }
    u8 msgdatamsgdata_idx = msg->data[msgdata_idx];
    memcpy(buf + offset, &msgdatamsgdata_idx, 1);
    // NOLINTNEXTLINE
    offset += 1;
  }
  return true;
}

static inline bool sbp_unpack_sbp_msg_flash_program_t(const u8 *buf, size_t len, sbp_msg_flash_program_t *msg)
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
  memcpy(&msg->target, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
  for (size_t msgaddr_start_idx = 0; msgaddr_start_idx < 3; msgaddr_start_idx++)
  {

    if (offset + 1 > len)
    {
      return false;
    }
    memcpy(&msg->addr_start[msgaddr_start_idx], buf + offset, 1);
    // NOLINTNEXTLINE
    offset += 1;
  }

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->addr_len, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  for (size_t msgdata_idx = 0; msgdata_idx < msg->addr_len; msgdata_idx++)
  {

    if (offset + 1 > len)
    {
      return false;
    }
    memcpy(&msg->data[msgdata_idx], buf + offset, 1);
    // NOLINTNEXTLINE
    offset += 1;
  }
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_flash_done_t(const sbp_msg_flash_done_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->response);
}

static inline bool sbp_pack_sbp_msg_flash_done_t(u8 *buf, size_t len, const sbp_msg_flash_done_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_flash_done_t(msg) > len)
  {
    return false;
  }

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgresponse = msg->response;
  memcpy(buf + offset, &msgresponse, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline bool sbp_unpack_sbp_msg_flash_done_t(const u8 *buf, size_t len, sbp_msg_flash_done_t *msg)
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
  memcpy(&msg->response, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_flash_read_req_t(const sbp_msg_flash_read_req_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->target) + (3 * sizeof(msg->addr_start[0])) + sizeof(msg->addr_len);
}

static inline bool sbp_pack_sbp_msg_flash_read_req_t(u8 *buf, size_t len, const sbp_msg_flash_read_req_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_flash_read_req_t(msg) > len)
  {
    return false;
  }

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgtarget = msg->target;
  memcpy(buf + offset, &msgtarget, 1);
  // NOLINTNEXTLINE
  offset += 1;
  for (size_t msgaddr_start_idx = 0; msgaddr_start_idx < 3; msgaddr_start_idx++)
  {

    if (offset + 1 > len)
    {
      return false;
    }
    u8 msgaddr_startmsgaddr_start_idx = msg->addr_start[msgaddr_start_idx];
    memcpy(buf + offset, &msgaddr_startmsgaddr_start_idx, 1);
    // NOLINTNEXTLINE
    offset += 1;
  }

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgaddr_len = msg->addr_len;
  memcpy(buf + offset, &msgaddr_len, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline bool sbp_unpack_sbp_msg_flash_read_req_t(const u8 *buf, size_t len, sbp_msg_flash_read_req_t *msg)
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
  memcpy(&msg->target, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
  for (size_t msgaddr_start_idx = 0; msgaddr_start_idx < 3; msgaddr_start_idx++)
  {

    if (offset + 1 > len)
    {
      return false;
    }
    memcpy(&msg->addr_start[msgaddr_start_idx], buf + offset, 1);
    // NOLINTNEXTLINE
    offset += 1;
  }

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->addr_len, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_flash_read_resp_t(const sbp_msg_flash_read_resp_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->target) + (3 * sizeof(msg->addr_start[0])) + sizeof(msg->addr_len);
}

static inline bool sbp_pack_sbp_msg_flash_read_resp_t(u8 *buf, size_t len, const sbp_msg_flash_read_resp_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_flash_read_resp_t(msg) > len)
  {
    return false;
  }

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgtarget = msg->target;
  memcpy(buf + offset, &msgtarget, 1);
  // NOLINTNEXTLINE
  offset += 1;
  for (size_t msgaddr_start_idx = 0; msgaddr_start_idx < 3; msgaddr_start_idx++)
  {

    if (offset + 1 > len)
    {
      return false;
    }
    u8 msgaddr_startmsgaddr_start_idx = msg->addr_start[msgaddr_start_idx];
    memcpy(buf + offset, &msgaddr_startmsgaddr_start_idx, 1);
    // NOLINTNEXTLINE
    offset += 1;
  }

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgaddr_len = msg->addr_len;
  memcpy(buf + offset, &msgaddr_len, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline bool sbp_unpack_sbp_msg_flash_read_resp_t(const u8 *buf, size_t len, sbp_msg_flash_read_resp_t *msg)
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
  memcpy(&msg->target, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
  for (size_t msgaddr_start_idx = 0; msgaddr_start_idx < 3; msgaddr_start_idx++)
  {

    if (offset + 1 > len)
    {
      return false;
    }
    memcpy(&msg->addr_start[msgaddr_start_idx], buf + offset, 1);
    // NOLINTNEXTLINE
    offset += 1;
  }

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->addr_len, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_flash_erase_t(const sbp_msg_flash_erase_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->target) + sizeof(msg->sector_num);
}

static inline bool sbp_pack_sbp_msg_flash_erase_t(u8 *buf, size_t len, const sbp_msg_flash_erase_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_flash_erase_t(msg) > len)
  {
    return false;
  }

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgtarget = msg->target;
  memcpy(buf + offset, &msgtarget, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgsector_num = htole32(msg->sector_num);
  memcpy(buf + offset, &msgsector_num, 4);
  // NOLINTNEXTLINE
  offset += 4;
  return true;
}

static inline bool sbp_unpack_sbp_msg_flash_erase_t(const u8 *buf, size_t len, sbp_msg_flash_erase_t *msg)
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
  memcpy(&msg->target, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->sector_num, buf + offset, 4);
  msg->sector_num = le32toh(msg->sector_num);
  // NOLINTNEXTLINE
  offset += 4;
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_stm_flash_lock_sector_t(const sbp_msg_stm_flash_lock_sector_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->sector);
}

static inline bool
sbp_pack_sbp_msg_stm_flash_lock_sector_t(u8 *buf, size_t len, const sbp_msg_stm_flash_lock_sector_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_stm_flash_lock_sector_t(msg) > len)
  {
    return false;
  }

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgsector = htole32(msg->sector);
  memcpy(buf + offset, &msgsector, 4);
  // NOLINTNEXTLINE
  offset += 4;
  return true;
}

static inline bool
sbp_unpack_sbp_msg_stm_flash_lock_sector_t(const u8 *buf, size_t len, sbp_msg_stm_flash_lock_sector_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->sector, buf + offset, 4);
  msg->sector = le32toh(msg->sector);
  // NOLINTNEXTLINE
  offset += 4;
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_stm_flash_unlock_sector_t(const sbp_msg_stm_flash_unlock_sector_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->sector);
}

static inline bool
sbp_pack_sbp_msg_stm_flash_unlock_sector_t(u8 *buf, size_t len, const sbp_msg_stm_flash_unlock_sector_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_stm_flash_unlock_sector_t(msg) > len)
  {
    return false;
  }

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgsector = htole32(msg->sector);
  memcpy(buf + offset, &msgsector, 4);
  // NOLINTNEXTLINE
  offset += 4;
  return true;
}

static inline bool
sbp_unpack_sbp_msg_stm_flash_unlock_sector_t(const u8 *buf, size_t len, sbp_msg_stm_flash_unlock_sector_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->sector, buf + offset, 4);
  msg->sector = le32toh(msg->sector);
  // NOLINTNEXTLINE
  offset += 4;
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_stm_unique_id_req_t(const sbp_msg_stm_unique_id_req_t *msg)
{
  (void)msg;
  return 0;
}

static inline bool sbp_pack_sbp_msg_stm_unique_id_req_t(u8 *buf, size_t len, const sbp_msg_stm_unique_id_req_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_stm_unique_id_req_t(msg) > len)
  {
    return false;
  }

  return true;
}

static inline bool sbp_unpack_sbp_msg_stm_unique_id_req_t(const u8 *buf, size_t len, sbp_msg_stm_unique_id_req_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  return true;
}

static inline size_t sbp_packed_size_sbp_msg_stm_unique_id_resp_t(const sbp_msg_stm_unique_id_resp_t *msg)
{
  (void)msg;
  return 0 + (12 * sizeof(msg->stm_id[0]));
}

static inline bool sbp_pack_sbp_msg_stm_unique_id_resp_t(u8 *buf, size_t len, const sbp_msg_stm_unique_id_resp_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_stm_unique_id_resp_t(msg) > len)
  {
    return false;
  }

  for (size_t msgstm_id_idx = 0; msgstm_id_idx < 12; msgstm_id_idx++)
  {

    if (offset + 1 > len)
    {
      return false;
    }
    u8 msgstm_idmsgstm_id_idx = msg->stm_id[msgstm_id_idx];
    memcpy(buf + offset, &msgstm_idmsgstm_id_idx, 1);
    // NOLINTNEXTLINE
    offset += 1;
  }
  return true;
}

static inline bool sbp_unpack_sbp_msg_stm_unique_id_resp_t(const u8 *buf, size_t len, sbp_msg_stm_unique_id_resp_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  for (size_t msgstm_id_idx = 0; msgstm_id_idx < 12; msgstm_id_idx++)
  {

    if (offset + 1 > len)
    {
      return false;
    }
    memcpy(&msg->stm_id[msgstm_id_idx], buf + offset, 1);
    // NOLINTNEXTLINE
    offset += 1;
  }
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_m25_flash_write_status_t(const sbp_msg_m25_flash_write_status_t *msg)
{
  (void)msg;
  return 0 + (1 * sizeof(msg->status[0]));
}

static inline bool
sbp_pack_sbp_msg_m25_flash_write_status_t(u8 *buf, size_t len, const sbp_msg_m25_flash_write_status_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_m25_flash_write_status_t(msg) > len)
  {
    return false;
  }

  for (size_t msgstatus_idx = 0; msgstatus_idx < 1; msgstatus_idx++)
  {

    if (offset + 1 > len)
    {
      return false;
    }
    u8 msgstatusmsgstatus_idx = msg->status[msgstatus_idx];
    memcpy(buf + offset, &msgstatusmsgstatus_idx, 1);
    // NOLINTNEXTLINE
    offset += 1;
  }
  return true;
}

static inline bool
sbp_unpack_sbp_msg_m25_flash_write_status_t(const u8 *buf, size_t len, sbp_msg_m25_flash_write_status_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  for (size_t msgstatus_idx = 0; msgstatus_idx < 1; msgstatus_idx++)
  {

    if (offset + 1 > len)
    {
      return false;
    }
    memcpy(&msg->status[msgstatus_idx], buf + offset, 1);
    // NOLINTNEXTLINE
    offset += 1;
  }
  return true;
}

#endif
