#ifndef LIBSBP_FLASH_OPERATORS_H
#define LIBSBP_FLASH_OPERATORS_H

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
#include <libsbp/string.h>
#include <libsbp/unpacked/base.h>
static inline int sbp_cmp_sbp_msg_flash_program_t(const sbp_msg_flash_program_t *a, const sbp_msg_flash_program_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u8(&a->target, &b->target);
  if (ret != 0) { return ret; }
  
  for (uint8_t i = 0; i < 3 && ret == 0; i++)
  {
    ret = sbp_cmp_u8(&a->addr_start[i], &b->addr_start[i]);
  }
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->addr_len, &b->addr_len);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->addr_len, &b->addr_len);
  for (uint8_t i = 0; i < a->addr_len && ret == 0; i++)
  {
    ret = sbp_cmp_u8(&a->data[i], &b->data[i]);
  }
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_flash_program_t &a, const sbp_msg_flash_program_t &b) {
  return sbp_cmp_sbp_msg_flash_program_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_flash_program_t &a, const sbp_msg_flash_program_t &b) {
  return sbp_cmp_sbp_msg_flash_program_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_flash_program_t &a, const sbp_msg_flash_program_t &b) {
  return sbp_cmp_sbp_msg_flash_program_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_flash_program_t &a, const sbp_msg_flash_program_t &b) {
  return sbp_cmp_sbp_msg_flash_program_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_flash_program_t &a, const sbp_msg_flash_program_t &b) {
  return sbp_cmp_sbp_msg_flash_program_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_flash_program_t &a, const sbp_msg_flash_program_t &b) {
  return sbp_cmp_sbp_msg_flash_program_t(&a, &b) >= 0;
}
#endif
static inline int sbp_cmp_sbp_msg_flash_done_t(const sbp_msg_flash_done_t *a, const sbp_msg_flash_done_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u8(&a->response, &b->response);
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_flash_done_t &a, const sbp_msg_flash_done_t &b) {
  return sbp_cmp_sbp_msg_flash_done_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_flash_done_t &a, const sbp_msg_flash_done_t &b) {
  return sbp_cmp_sbp_msg_flash_done_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_flash_done_t &a, const sbp_msg_flash_done_t &b) {
  return sbp_cmp_sbp_msg_flash_done_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_flash_done_t &a, const sbp_msg_flash_done_t &b) {
  return sbp_cmp_sbp_msg_flash_done_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_flash_done_t &a, const sbp_msg_flash_done_t &b) {
  return sbp_cmp_sbp_msg_flash_done_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_flash_done_t &a, const sbp_msg_flash_done_t &b) {
  return sbp_cmp_sbp_msg_flash_done_t(&a, &b) >= 0;
}
#endif
static inline int sbp_cmp_sbp_msg_flash_read_req_t(const sbp_msg_flash_read_req_t *a, const sbp_msg_flash_read_req_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u8(&a->target, &b->target);
  if (ret != 0) { return ret; }
  
  for (uint8_t i = 0; i < 3 && ret == 0; i++)
  {
    ret = sbp_cmp_u8(&a->addr_start[i], &b->addr_start[i]);
  }
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->addr_len, &b->addr_len);
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_flash_read_req_t &a, const sbp_msg_flash_read_req_t &b) {
  return sbp_cmp_sbp_msg_flash_read_req_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_flash_read_req_t &a, const sbp_msg_flash_read_req_t &b) {
  return sbp_cmp_sbp_msg_flash_read_req_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_flash_read_req_t &a, const sbp_msg_flash_read_req_t &b) {
  return sbp_cmp_sbp_msg_flash_read_req_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_flash_read_req_t &a, const sbp_msg_flash_read_req_t &b) {
  return sbp_cmp_sbp_msg_flash_read_req_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_flash_read_req_t &a, const sbp_msg_flash_read_req_t &b) {
  return sbp_cmp_sbp_msg_flash_read_req_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_flash_read_req_t &a, const sbp_msg_flash_read_req_t &b) {
  return sbp_cmp_sbp_msg_flash_read_req_t(&a, &b) >= 0;
}
#endif
static inline int sbp_cmp_sbp_msg_flash_read_resp_t(const sbp_msg_flash_read_resp_t *a, const sbp_msg_flash_read_resp_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u8(&a->target, &b->target);
  if (ret != 0) { return ret; }
  
  for (uint8_t i = 0; i < 3 && ret == 0; i++)
  {
    ret = sbp_cmp_u8(&a->addr_start[i], &b->addr_start[i]);
  }
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->addr_len, &b->addr_len);
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_flash_read_resp_t &a, const sbp_msg_flash_read_resp_t &b) {
  return sbp_cmp_sbp_msg_flash_read_resp_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_flash_read_resp_t &a, const sbp_msg_flash_read_resp_t &b) {
  return sbp_cmp_sbp_msg_flash_read_resp_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_flash_read_resp_t &a, const sbp_msg_flash_read_resp_t &b) {
  return sbp_cmp_sbp_msg_flash_read_resp_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_flash_read_resp_t &a, const sbp_msg_flash_read_resp_t &b) {
  return sbp_cmp_sbp_msg_flash_read_resp_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_flash_read_resp_t &a, const sbp_msg_flash_read_resp_t &b) {
  return sbp_cmp_sbp_msg_flash_read_resp_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_flash_read_resp_t &a, const sbp_msg_flash_read_resp_t &b) {
  return sbp_cmp_sbp_msg_flash_read_resp_t(&a, &b) >= 0;
}
#endif
static inline int sbp_cmp_sbp_msg_flash_erase_t(const sbp_msg_flash_erase_t *a, const sbp_msg_flash_erase_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u8(&a->target, &b->target);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u32(&a->sector_num, &b->sector_num);
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_flash_erase_t &a, const sbp_msg_flash_erase_t &b) {
  return sbp_cmp_sbp_msg_flash_erase_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_flash_erase_t &a, const sbp_msg_flash_erase_t &b) {
  return sbp_cmp_sbp_msg_flash_erase_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_flash_erase_t &a, const sbp_msg_flash_erase_t &b) {
  return sbp_cmp_sbp_msg_flash_erase_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_flash_erase_t &a, const sbp_msg_flash_erase_t &b) {
  return sbp_cmp_sbp_msg_flash_erase_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_flash_erase_t &a, const sbp_msg_flash_erase_t &b) {
  return sbp_cmp_sbp_msg_flash_erase_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_flash_erase_t &a, const sbp_msg_flash_erase_t &b) {
  return sbp_cmp_sbp_msg_flash_erase_t(&a, &b) >= 0;
}
#endif
static inline int sbp_cmp_sbp_msg_stm_flash_lock_sector_t(const sbp_msg_stm_flash_lock_sector_t *a, const sbp_msg_stm_flash_lock_sector_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u32(&a->sector, &b->sector);
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_stm_flash_lock_sector_t &a, const sbp_msg_stm_flash_lock_sector_t &b) {
  return sbp_cmp_sbp_msg_stm_flash_lock_sector_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_stm_flash_lock_sector_t &a, const sbp_msg_stm_flash_lock_sector_t &b) {
  return sbp_cmp_sbp_msg_stm_flash_lock_sector_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_stm_flash_lock_sector_t &a, const sbp_msg_stm_flash_lock_sector_t &b) {
  return sbp_cmp_sbp_msg_stm_flash_lock_sector_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_stm_flash_lock_sector_t &a, const sbp_msg_stm_flash_lock_sector_t &b) {
  return sbp_cmp_sbp_msg_stm_flash_lock_sector_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_stm_flash_lock_sector_t &a, const sbp_msg_stm_flash_lock_sector_t &b) {
  return sbp_cmp_sbp_msg_stm_flash_lock_sector_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_stm_flash_lock_sector_t &a, const sbp_msg_stm_flash_lock_sector_t &b) {
  return sbp_cmp_sbp_msg_stm_flash_lock_sector_t(&a, &b) >= 0;
}
#endif
static inline int sbp_cmp_sbp_msg_stm_flash_unlock_sector_t(const sbp_msg_stm_flash_unlock_sector_t *a, const sbp_msg_stm_flash_unlock_sector_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u32(&a->sector, &b->sector);
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_stm_flash_unlock_sector_t &a, const sbp_msg_stm_flash_unlock_sector_t &b) {
  return sbp_cmp_sbp_msg_stm_flash_unlock_sector_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_stm_flash_unlock_sector_t &a, const sbp_msg_stm_flash_unlock_sector_t &b) {
  return sbp_cmp_sbp_msg_stm_flash_unlock_sector_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_stm_flash_unlock_sector_t &a, const sbp_msg_stm_flash_unlock_sector_t &b) {
  return sbp_cmp_sbp_msg_stm_flash_unlock_sector_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_stm_flash_unlock_sector_t &a, const sbp_msg_stm_flash_unlock_sector_t &b) {
  return sbp_cmp_sbp_msg_stm_flash_unlock_sector_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_stm_flash_unlock_sector_t &a, const sbp_msg_stm_flash_unlock_sector_t &b) {
  return sbp_cmp_sbp_msg_stm_flash_unlock_sector_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_stm_flash_unlock_sector_t &a, const sbp_msg_stm_flash_unlock_sector_t &b) {
  return sbp_cmp_sbp_msg_stm_flash_unlock_sector_t(&a, &b) >= 0;
}
#endif
static inline int sbp_cmp_sbp_msg_stm_unique_id_req_t(const sbp_msg_stm_unique_id_req_t *a, const sbp_msg_stm_unique_id_req_t *b) {
  (void)a;
  (void)b;
  int ret = 0;
  return ret;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_stm_unique_id_req_t &a, const sbp_msg_stm_unique_id_req_t &b) {
  return sbp_cmp_sbp_msg_stm_unique_id_req_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_stm_unique_id_req_t &a, const sbp_msg_stm_unique_id_req_t &b) {
  return sbp_cmp_sbp_msg_stm_unique_id_req_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_stm_unique_id_req_t &a, const sbp_msg_stm_unique_id_req_t &b) {
  return sbp_cmp_sbp_msg_stm_unique_id_req_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_stm_unique_id_req_t &a, const sbp_msg_stm_unique_id_req_t &b) {
  return sbp_cmp_sbp_msg_stm_unique_id_req_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_stm_unique_id_req_t &a, const sbp_msg_stm_unique_id_req_t &b) {
  return sbp_cmp_sbp_msg_stm_unique_id_req_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_stm_unique_id_req_t &a, const sbp_msg_stm_unique_id_req_t &b) {
  return sbp_cmp_sbp_msg_stm_unique_id_req_t(&a, &b) >= 0;
}
#endif
static inline int sbp_cmp_sbp_msg_stm_unique_id_resp_t(const sbp_msg_stm_unique_id_resp_t *a, const sbp_msg_stm_unique_id_resp_t *b) {
  int ret = 0;
  
  for (uint8_t i = 0; i < 12 && ret == 0; i++)
  {
    ret = sbp_cmp_u8(&a->stm_id[i], &b->stm_id[i]);
  }
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_stm_unique_id_resp_t &a, const sbp_msg_stm_unique_id_resp_t &b) {
  return sbp_cmp_sbp_msg_stm_unique_id_resp_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_stm_unique_id_resp_t &a, const sbp_msg_stm_unique_id_resp_t &b) {
  return sbp_cmp_sbp_msg_stm_unique_id_resp_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_stm_unique_id_resp_t &a, const sbp_msg_stm_unique_id_resp_t &b) {
  return sbp_cmp_sbp_msg_stm_unique_id_resp_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_stm_unique_id_resp_t &a, const sbp_msg_stm_unique_id_resp_t &b) {
  return sbp_cmp_sbp_msg_stm_unique_id_resp_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_stm_unique_id_resp_t &a, const sbp_msg_stm_unique_id_resp_t &b) {
  return sbp_cmp_sbp_msg_stm_unique_id_resp_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_stm_unique_id_resp_t &a, const sbp_msg_stm_unique_id_resp_t &b) {
  return sbp_cmp_sbp_msg_stm_unique_id_resp_t(&a, &b) >= 0;
}
#endif
static inline int sbp_cmp_sbp_msg_m25_flash_write_status_t(const sbp_msg_m25_flash_write_status_t *a, const sbp_msg_m25_flash_write_status_t *b) {
  int ret = 0;
  
  for (uint8_t i = 0; i < 1 && ret == 0; i++)
  {
    ret = sbp_cmp_u8(&a->status[i], &b->status[i]);
  }
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_m25_flash_write_status_t &a, const sbp_msg_m25_flash_write_status_t &b) {
  return sbp_cmp_sbp_msg_m25_flash_write_status_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_m25_flash_write_status_t &a, const sbp_msg_m25_flash_write_status_t &b) {
  return sbp_cmp_sbp_msg_m25_flash_write_status_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_m25_flash_write_status_t &a, const sbp_msg_m25_flash_write_status_t &b) {
  return sbp_cmp_sbp_msg_m25_flash_write_status_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_m25_flash_write_status_t &a, const sbp_msg_m25_flash_write_status_t &b) {
  return sbp_cmp_sbp_msg_m25_flash_write_status_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_m25_flash_write_status_t &a, const sbp_msg_m25_flash_write_status_t &b) {
  return sbp_cmp_sbp_msg_m25_flash_write_status_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_m25_flash_write_status_t &a, const sbp_msg_m25_flash_write_status_t &b) {
  return sbp_cmp_sbp_msg_m25_flash_write_status_t(&a, &b) >= 0;
}
#endif

#endif
