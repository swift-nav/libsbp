#ifndef LIBSBP_FLASH_OPERATORS_H
#define LIBSBP_FLASH_OPERATORS_H

#include <endian.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>

#include <libsbp/common.h>
#include <libsbp/unpacked/flash.h>
#ifdef __cplusplus
static inline bool operator==(const sbp_msg_flash_program_t &a, const sbp_msg_flash_program_t &b)
{
  (void)a;
  (void)b;

  if (a.target != b.target)
  {
    return false;
  }
  for (size_t addr_start_idx = 0; addr_start_idx < 3; addr_start_idx++)
  {

    if (a.addr_start[addr_start_idx] != b.addr_start[addr_start_idx])
    {
      return false;
    }
  }

  if (a.addr_len != b.addr_len)
  {
    return false;
  }
  if (a.n_data != b.n_data)
  {
    return false;
  }
  for (size_t data_idx = 0; data_idx < (size_t)a.n_data; data_idx++)
  {

    if (a.data[data_idx] != b.data[data_idx])
    {
      return false;
    }
  }

  return true;
}

static inline bool operator!=(const sbp_msg_flash_program_t &a, const sbp_msg_flash_program_t &b)
{
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator==(const sbp_msg_flash_done_t &a, const sbp_msg_flash_done_t &b)
{
  (void)a;
  (void)b;

  if (a.response != b.response)
  {
    return false;
  }

  return true;
}

static inline bool operator!=(const sbp_msg_flash_done_t &a, const sbp_msg_flash_done_t &b)
{
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator==(const sbp_msg_flash_read_req_t &a, const sbp_msg_flash_read_req_t &b)
{
  (void)a;
  (void)b;

  if (a.target != b.target)
  {
    return false;
  }
  for (size_t addr_start_idx = 0; addr_start_idx < 3; addr_start_idx++)
  {

    if (a.addr_start[addr_start_idx] != b.addr_start[addr_start_idx])
    {
      return false;
    }
  }

  if (a.addr_len != b.addr_len)
  {
    return false;
  }

  return true;
}

static inline bool operator!=(const sbp_msg_flash_read_req_t &a, const sbp_msg_flash_read_req_t &b)
{
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator==(const sbp_msg_flash_read_resp_t &a, const sbp_msg_flash_read_resp_t &b)
{
  (void)a;
  (void)b;

  if (a.target != b.target)
  {
    return false;
  }
  for (size_t addr_start_idx = 0; addr_start_idx < 3; addr_start_idx++)
  {

    if (a.addr_start[addr_start_idx] != b.addr_start[addr_start_idx])
    {
      return false;
    }
  }

  if (a.addr_len != b.addr_len)
  {
    return false;
  }

  return true;
}

static inline bool operator!=(const sbp_msg_flash_read_resp_t &a, const sbp_msg_flash_read_resp_t &b)
{
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator==(const sbp_msg_flash_erase_t &a, const sbp_msg_flash_erase_t &b)
{
  (void)a;
  (void)b;

  if (a.target != b.target)
  {
    return false;
  }

  if (a.sector_num != b.sector_num)
  {
    return false;
  }

  return true;
}

static inline bool operator!=(const sbp_msg_flash_erase_t &a, const sbp_msg_flash_erase_t &b)
{
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator==(const sbp_msg_stm_flash_lock_sector_t &a, const sbp_msg_stm_flash_lock_sector_t &b)
{
  (void)a;
  (void)b;

  if (a.sector != b.sector)
  {
    return false;
  }

  return true;
}

static inline bool operator!=(const sbp_msg_stm_flash_lock_sector_t &a, const sbp_msg_stm_flash_lock_sector_t &b)
{
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator==(const sbp_msg_stm_flash_unlock_sector_t &a, const sbp_msg_stm_flash_unlock_sector_t &b)
{
  (void)a;
  (void)b;

  if (a.sector != b.sector)
  {
    return false;
  }

  return true;
}

static inline bool operator!=(const sbp_msg_stm_flash_unlock_sector_t &a, const sbp_msg_stm_flash_unlock_sector_t &b)
{
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator==(const sbp_msg_stm_unique_id_req_t &a, const sbp_msg_stm_unique_id_req_t &b)
{
  (void)a;
  (void)b;

  return true;
}

static inline bool operator!=(const sbp_msg_stm_unique_id_req_t &a, const sbp_msg_stm_unique_id_req_t &b)
{
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator==(const sbp_msg_stm_unique_id_resp_t &a, const sbp_msg_stm_unique_id_resp_t &b)
{
  (void)a;
  (void)b;

  for (size_t stm_id_idx = 0; stm_id_idx < 12; stm_id_idx++)
  {

    if (a.stm_id[stm_id_idx] != b.stm_id[stm_id_idx])
    {
      return false;
    }
  }

  return true;
}

static inline bool operator!=(const sbp_msg_stm_unique_id_resp_t &a, const sbp_msg_stm_unique_id_resp_t &b)
{
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator==(const sbp_msg_m25_flash_write_status_t &a, const sbp_msg_m25_flash_write_status_t &b)
{
  (void)a;
  (void)b;

  for (size_t status_idx = 0; status_idx < 1; status_idx++)
  {

    if (a.status[status_idx] != b.status[status_idx])
    {
      return false;
    }
  }

  return true;
}

static inline bool operator!=(const sbp_msg_m25_flash_write_status_t &a, const sbp_msg_m25_flash_write_status_t &b)
{
  return !(a == b);
}
#endif

#endif
