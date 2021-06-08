/*
 * Copyright (C) 2015-2018 Swift Navigation Inc.
 * Contact: https://support.swiftnav.com
 *
 * This source is subject to the license found in the file 'LICENSE' which must
 * be be distributed together with this source. All other rights reserved.
 *
 * THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
 * EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
 */

/*****************************************************************************
 * Automatically generated from yaml/swiftnav/sbp/flash.yaml
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

#ifndef LIBSBP_NEW_FLASH_MESSAGES_H
#define LIBSBP_NEW_FLASH_MESSAGES_H

#include <endian.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>

#include <libsbp/common.h>
#include <libsbp/new/string/double_null_terminated.h>
#include <libsbp/new/string/multipart.h>
#include <libsbp/new/string/null_terminated.h>
#include <libsbp/new/string/unterminated.h>

#ifdef __cplusplus
extern "C" {
#endif

struct sbp_state;
#ifndef LIBSBP_LEGACY_FLASH_MESSAGES_H
#define SBP_FLASH_PROGRAM_FLASH_TARGET_TO_READ_MASK (0x1)
#define SBP_FLASH_PROGRAM_FLASH_TARGET_TO_READ_SHIFT (0u)
#define SBP_FLASH_PROGRAM_FLASH_TARGET_TO_READ_GET(flags)      \
  (((flags) >> SBP_FLASH_PROGRAM_FLASH_TARGET_TO_READ_SHIFT) & \
   SBP_FLASH_PROGRAM_FLASH_TARGET_TO_READ_MASK)
#define SBP_FLASH_PROGRAM_FLASH_TARGET_TO_READ_SET(flags, val)           \
  do {                                                                   \
    ((flags) |= (((val) & (SBP_FLASH_PROGRAM_FLASH_TARGET_TO_READ_MASK)) \
                 << (SBP_FLASH_PROGRAM_FLASH_TARGET_TO_READ_SHIFT)));    \
  } while (0)

#define SBP_FLASH_PROGRAM_FLASH_TARGET_TO_READ_FLASH_STM (0)
#define SBP_FLASH_PROGRAM_FLASH_TARGET_TO_READ_FLASH_M25 (1)
#endif
/** Program flash addresses
 *
((m.desc|commentify)))
 */
#ifndef LIBSBP_LEGACY_FLASH_MESSAGES_H
#define SBP_MSG_FLASH_PROGRAM 0x00E6
#endif
typedef struct {
  u8 target;
  u8 addr_start[3];
  u8 addr_len;
  u8 data[250];
} sbp_msg_flash_program_t;

size_t sbp_packed_size_sbp_msg_flash_program_t(
    const sbp_msg_flash_program_t *msg);
s8 sbp_encode_sbp_msg_flash_program_t(uint8_t *buf, uint8_t len,
                                      uint8_t *n_written,
                                      const sbp_msg_flash_program_t *msg);
s8 sbp_decode_sbp_msg_flash_program_t(const uint8_t *buf, uint8_t len,
                                      uint8_t *n_read,
                                      sbp_msg_flash_program_t *msg);
s8 sbp_send_sbp_msg_flash_program_t(struct sbp_state *s, u16 sender_id,
                                    const sbp_msg_flash_program_t *msg,
                                    s32 (*write)(u8 *buff, u32 n,
                                                 void *context));

int sbp_cmp_sbp_msg_flash_program_t(const sbp_msg_flash_program_t *a,
                                    const sbp_msg_flash_program_t *b);

#ifndef LIBSBP_LEGACY_FLASH_MESSAGES_H
#define SBP_FLASH_DONE_RESPONSE_CODE_MASK (0x7)
#define SBP_FLASH_DONE_RESPONSE_CODE_SHIFT (0u)
#define SBP_FLASH_DONE_RESPONSE_CODE_GET(flags)      \
  (((flags) >> SBP_FLASH_DONE_RESPONSE_CODE_SHIFT) & \
   SBP_FLASH_DONE_RESPONSE_CODE_MASK)
#define SBP_FLASH_DONE_RESPONSE_CODE_SET(flags, val)           \
  do {                                                         \
    ((flags) |= (((val) & (SBP_FLASH_DONE_RESPONSE_CODE_MASK)) \
                 << (SBP_FLASH_DONE_RESPONSE_CODE_SHIFT)));    \
  } while (0)

#define SBP_FLASH_DONE_RESPONSE_CODE_FLASH_OK (0)
#define SBP_FLASH_DONE_RESPONSE_CODE_FLASH_INVALID_FLASH (1)
#define SBP_FLASH_DONE_RESPONSE_CODE_FLASH_INVALID_LEN (2)
#define SBP_FLASH_DONE_RESPONSE_CODE_FLASH_INVALID_ADDR (3)
#define SBP_FLASH_DONE_RESPONSE_CODE_FLASH_INVALID_RANGE (4)
#define SBP_FLASH_DONE_RESPONSE_CODE_FLASH_INVALID_SECTOR (5)
#endif
/** Flash response message (host <= device)
 *
((m.desc|commentify)))
 */
#ifndef LIBSBP_LEGACY_FLASH_MESSAGES_H
#define SBP_MSG_FLASH_DONE 0x00E0
#endif
typedef struct {
  u8 response;
} sbp_msg_flash_done_t;

size_t sbp_packed_size_sbp_msg_flash_done_t(const sbp_msg_flash_done_t *msg);
s8 sbp_encode_sbp_msg_flash_done_t(uint8_t *buf, uint8_t len,
                                   uint8_t *n_written,
                                   const sbp_msg_flash_done_t *msg);
s8 sbp_decode_sbp_msg_flash_done_t(const uint8_t *buf, uint8_t len,
                                   uint8_t *n_read, sbp_msg_flash_done_t *msg);
s8 sbp_send_sbp_msg_flash_done_t(struct sbp_state *s, u16 sender_id,
                                 const sbp_msg_flash_done_t *msg,
                                 s32 (*write)(u8 *buff, u32 n, void *context));

int sbp_cmp_sbp_msg_flash_done_t(const sbp_msg_flash_done_t *a,
                                 const sbp_msg_flash_done_t *b);

#ifndef LIBSBP_LEGACY_FLASH_MESSAGES_H
#define SBP_FLASH_READ_REQ_FLASH_TARGET_TO_READ_MASK (0x1)
#define SBP_FLASH_READ_REQ_FLASH_TARGET_TO_READ_SHIFT (0u)
#define SBP_FLASH_READ_REQ_FLASH_TARGET_TO_READ_GET(flags)      \
  (((flags) >> SBP_FLASH_READ_REQ_FLASH_TARGET_TO_READ_SHIFT) & \
   SBP_FLASH_READ_REQ_FLASH_TARGET_TO_READ_MASK)
#define SBP_FLASH_READ_REQ_FLASH_TARGET_TO_READ_SET(flags, val)           \
  do {                                                                    \
    ((flags) |= (((val) & (SBP_FLASH_READ_REQ_FLASH_TARGET_TO_READ_MASK)) \
                 << (SBP_FLASH_READ_REQ_FLASH_TARGET_TO_READ_SHIFT)));    \
  } while (0)

#define SBP_FLASH_READ_REQ_FLASH_TARGET_TO_READ_FLASH_STM (0)
#define SBP_FLASH_READ_REQ_FLASH_TARGET_TO_READ_FLASH_M25 (1)
#endif
/** Read STM or M25 flash address request (host => device)
 *
((m.desc|commentify)))
 */
#ifndef LIBSBP_LEGACY_FLASH_MESSAGES_H
#define SBP_MSG_FLASH_READ_REQ 0x00E7
#endif
typedef struct {
  u8 target;
  u8 addr_start[3];
  u8 addr_len;
} sbp_msg_flash_read_req_t;

size_t sbp_packed_size_sbp_msg_flash_read_req_t(
    const sbp_msg_flash_read_req_t *msg);
s8 sbp_encode_sbp_msg_flash_read_req_t(uint8_t *buf, uint8_t len,
                                       uint8_t *n_written,
                                       const sbp_msg_flash_read_req_t *msg);
s8 sbp_decode_sbp_msg_flash_read_req_t(const uint8_t *buf, uint8_t len,
                                       uint8_t *n_read,
                                       sbp_msg_flash_read_req_t *msg);
s8 sbp_send_sbp_msg_flash_read_req_t(struct sbp_state *s, u16 sender_id,
                                     const sbp_msg_flash_read_req_t *msg,
                                     s32 (*write)(u8 *buff, u32 n,
                                                  void *context));

int sbp_cmp_sbp_msg_flash_read_req_t(const sbp_msg_flash_read_req_t *a,
                                     const sbp_msg_flash_read_req_t *b);

#ifndef LIBSBP_LEGACY_FLASH_MESSAGES_H
#define SBP_FLASH_READ_RESP_FLASH_TARGET_TO_READ_MASK (0x1)
#define SBP_FLASH_READ_RESP_FLASH_TARGET_TO_READ_SHIFT (0u)
#define SBP_FLASH_READ_RESP_FLASH_TARGET_TO_READ_GET(flags)      \
  (((flags) >> SBP_FLASH_READ_RESP_FLASH_TARGET_TO_READ_SHIFT) & \
   SBP_FLASH_READ_RESP_FLASH_TARGET_TO_READ_MASK)
#define SBP_FLASH_READ_RESP_FLASH_TARGET_TO_READ_SET(flags, val)           \
  do {                                                                     \
    ((flags) |= (((val) & (SBP_FLASH_READ_RESP_FLASH_TARGET_TO_READ_MASK)) \
                 << (SBP_FLASH_READ_RESP_FLASH_TARGET_TO_READ_SHIFT)));    \
  } while (0)

#define SBP_FLASH_READ_RESP_FLASH_TARGET_TO_READ_FLASH_STM (0)
#define SBP_FLASH_READ_RESP_FLASH_TARGET_TO_READ_FLASH_M25 (1)
#endif
/** Read STM or M25 flash address response (host <= device)
 *
((m.desc|commentify)))
 */
#ifndef LIBSBP_LEGACY_FLASH_MESSAGES_H
#define SBP_MSG_FLASH_READ_RESP 0x00E1
#endif
typedef struct {
  u8 target;
  u8 addr_start[3];
  u8 addr_len;
} sbp_msg_flash_read_resp_t;

size_t sbp_packed_size_sbp_msg_flash_read_resp_t(
    const sbp_msg_flash_read_resp_t *msg);
s8 sbp_encode_sbp_msg_flash_read_resp_t(uint8_t *buf, uint8_t len,
                                        uint8_t *n_written,
                                        const sbp_msg_flash_read_resp_t *msg);
s8 sbp_decode_sbp_msg_flash_read_resp_t(const uint8_t *buf, uint8_t len,
                                        uint8_t *n_read,
                                        sbp_msg_flash_read_resp_t *msg);
s8 sbp_send_sbp_msg_flash_read_resp_t(struct sbp_state *s, u16 sender_id,
                                      const sbp_msg_flash_read_resp_t *msg,
                                      s32 (*write)(u8 *buff, u32 n,
                                                   void *context));

int sbp_cmp_sbp_msg_flash_read_resp_t(const sbp_msg_flash_read_resp_t *a,
                                      const sbp_msg_flash_read_resp_t *b);

#ifndef LIBSBP_LEGACY_FLASH_MESSAGES_H
#define SBP_FLASH_ERASE_FLASH_TARGET_TO_READ_MASK (0x1)
#define SBP_FLASH_ERASE_FLASH_TARGET_TO_READ_SHIFT (0u)
#define SBP_FLASH_ERASE_FLASH_TARGET_TO_READ_GET(flags)      \
  (((flags) >> SBP_FLASH_ERASE_FLASH_TARGET_TO_READ_SHIFT) & \
   SBP_FLASH_ERASE_FLASH_TARGET_TO_READ_MASK)
#define SBP_FLASH_ERASE_FLASH_TARGET_TO_READ_SET(flags, val)           \
  do {                                                                 \
    ((flags) |= (((val) & (SBP_FLASH_ERASE_FLASH_TARGET_TO_READ_MASK)) \
                 << (SBP_FLASH_ERASE_FLASH_TARGET_TO_READ_SHIFT)));    \
  } while (0)

#define SBP_FLASH_ERASE_FLASH_TARGET_TO_READ_FLASH_STM (0)
#define SBP_FLASH_ERASE_FLASH_TARGET_TO_READ_FLASH_M25 (1)
#endif
/** Erase sector of device flash memory (host => device)
 *
((m.desc|commentify)))
 */
#ifndef LIBSBP_LEGACY_FLASH_MESSAGES_H
#define SBP_MSG_FLASH_ERASE 0x00E2
#endif
typedef struct {
  u8 target;
  u32 sector_num;
} sbp_msg_flash_erase_t;

size_t sbp_packed_size_sbp_msg_flash_erase_t(const sbp_msg_flash_erase_t *msg);
s8 sbp_encode_sbp_msg_flash_erase_t(uint8_t *buf, uint8_t len,
                                    uint8_t *n_written,
                                    const sbp_msg_flash_erase_t *msg);
s8 sbp_decode_sbp_msg_flash_erase_t(const uint8_t *buf, uint8_t len,
                                    uint8_t *n_read,
                                    sbp_msg_flash_erase_t *msg);
s8 sbp_send_sbp_msg_flash_erase_t(struct sbp_state *s, u16 sender_id,
                                  const sbp_msg_flash_erase_t *msg,
                                  s32 (*write)(u8 *buff, u32 n, void *context));

int sbp_cmp_sbp_msg_flash_erase_t(const sbp_msg_flash_erase_t *a,
                                  const sbp_msg_flash_erase_t *b);

/** Lock sector of STM flash memory (host => device)
 *
((m.desc|commentify)))
 */
#ifndef LIBSBP_LEGACY_FLASH_MESSAGES_H
#define SBP_MSG_STM_FLASH_LOCK_SECTOR 0x00E3
#endif
typedef struct {
  u32 sector;
} sbp_msg_stm_flash_lock_sector_t;

size_t sbp_packed_size_sbp_msg_stm_flash_lock_sector_t(
    const sbp_msg_stm_flash_lock_sector_t *msg);
s8 sbp_encode_sbp_msg_stm_flash_lock_sector_t(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_msg_stm_flash_lock_sector_t *msg);
s8 sbp_decode_sbp_msg_stm_flash_lock_sector_t(
    const uint8_t *buf, uint8_t len, uint8_t *n_read,
    sbp_msg_stm_flash_lock_sector_t *msg);
s8 sbp_send_sbp_msg_stm_flash_lock_sector_t(
    struct sbp_state *s, u16 sender_id,
    const sbp_msg_stm_flash_lock_sector_t *msg,
    s32 (*write)(u8 *buff, u32 n, void *context));

int sbp_cmp_sbp_msg_stm_flash_lock_sector_t(
    const sbp_msg_stm_flash_lock_sector_t *a,
    const sbp_msg_stm_flash_lock_sector_t *b);

/** Unlock sector of STM flash memory (host => device)
 *
((m.desc|commentify)))
 */
#ifndef LIBSBP_LEGACY_FLASH_MESSAGES_H
#define SBP_MSG_STM_FLASH_UNLOCK_SECTOR 0x00E4
#endif
typedef struct {
  u32 sector;
} sbp_msg_stm_flash_unlock_sector_t;

size_t sbp_packed_size_sbp_msg_stm_flash_unlock_sector_t(
    const sbp_msg_stm_flash_unlock_sector_t *msg);
s8 sbp_encode_sbp_msg_stm_flash_unlock_sector_t(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_msg_stm_flash_unlock_sector_t *msg);
s8 sbp_decode_sbp_msg_stm_flash_unlock_sector_t(
    const uint8_t *buf, uint8_t len, uint8_t *n_read,
    sbp_msg_stm_flash_unlock_sector_t *msg);
s8 sbp_send_sbp_msg_stm_flash_unlock_sector_t(
    struct sbp_state *s, u16 sender_id,
    const sbp_msg_stm_flash_unlock_sector_t *msg,
    s32 (*write)(u8 *buff, u32 n, void *context));

int sbp_cmp_sbp_msg_stm_flash_unlock_sector_t(
    const sbp_msg_stm_flash_unlock_sector_t *a,
    const sbp_msg_stm_flash_unlock_sector_t *b);

/** Read device's hardcoded unique ID request (host => device)

 *
((m.desc|commentify)))
 */
#ifndef LIBSBP_LEGACY_FLASH_MESSAGES_H
#define SBP_MSG_STM_UNIQUE_ID_REQ 0x00E8
#endif
typedef struct {
  char DO_NOT_USE_dummy_field_to_prevent_empty_struct;
} sbp_msg_stm_unique_id_req_t;

size_t sbp_packed_size_sbp_msg_stm_unique_id_req_t(
    const sbp_msg_stm_unique_id_req_t *msg);
s8 sbp_encode_sbp_msg_stm_unique_id_req_t(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_msg_stm_unique_id_req_t *msg);
s8 sbp_decode_sbp_msg_stm_unique_id_req_t(const uint8_t *buf, uint8_t len,
                                          uint8_t *n_read,
                                          sbp_msg_stm_unique_id_req_t *msg);
s8 sbp_send_sbp_msg_stm_unique_id_req_t(struct sbp_state *s, u16 sender_id,
                                        const sbp_msg_stm_unique_id_req_t *msg,
                                        s32 (*write)(u8 *buff, u32 n,
                                                     void *context));

int sbp_cmp_sbp_msg_stm_unique_id_req_t(const sbp_msg_stm_unique_id_req_t *a,
                                        const sbp_msg_stm_unique_id_req_t *b);

/** Read device's hardcoded unique ID response (host <= device)

 *
((m.desc|commentify)))
 */
#ifndef LIBSBP_LEGACY_FLASH_MESSAGES_H
#define SBP_MSG_STM_UNIQUE_ID_RESP 0x00E5
#endif
typedef struct {
  u8 stm_id[12];
} sbp_msg_stm_unique_id_resp_t;

size_t sbp_packed_size_sbp_msg_stm_unique_id_resp_t(
    const sbp_msg_stm_unique_id_resp_t *msg);
s8 sbp_encode_sbp_msg_stm_unique_id_resp_t(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_msg_stm_unique_id_resp_t *msg);
s8 sbp_decode_sbp_msg_stm_unique_id_resp_t(const uint8_t *buf, uint8_t len,
                                           uint8_t *n_read,
                                           sbp_msg_stm_unique_id_resp_t *msg);
s8 sbp_send_sbp_msg_stm_unique_id_resp_t(
    struct sbp_state *s, u16 sender_id, const sbp_msg_stm_unique_id_resp_t *msg,
    s32 (*write)(u8 *buff, u32 n, void *context));

int sbp_cmp_sbp_msg_stm_unique_id_resp_t(const sbp_msg_stm_unique_id_resp_t *a,
                                         const sbp_msg_stm_unique_id_resp_t *b);

/** Write M25 flash status register (host => device)
 *
((m.desc|commentify)))
 */
#ifndef LIBSBP_LEGACY_FLASH_MESSAGES_H
#define SBP_MSG_M25_FLASH_WRITE_STATUS 0x00F3
#endif
typedef struct {
  u8 status[1];
} sbp_msg_m25_flash_write_status_t;

size_t sbp_packed_size_sbp_msg_m25_flash_write_status_t(
    const sbp_msg_m25_flash_write_status_t *msg);
s8 sbp_encode_sbp_msg_m25_flash_write_status_t(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_msg_m25_flash_write_status_t *msg);
s8 sbp_decode_sbp_msg_m25_flash_write_status_t(
    const uint8_t *buf, uint8_t len, uint8_t *n_read,
    sbp_msg_m25_flash_write_status_t *msg);
s8 sbp_send_sbp_msg_m25_flash_write_status_t(
    struct sbp_state *s, u16 sender_id,
    const sbp_msg_m25_flash_write_status_t *msg,
    s32 (*write)(u8 *buff, u32 n, void *context));

int sbp_cmp_sbp_msg_m25_flash_write_status_t(
    const sbp_msg_m25_flash_write_status_t *a,
    const sbp_msg_m25_flash_write_status_t *b);

#ifdef __cplusplus
}
static inline bool operator==(const sbp_msg_flash_program_t &a,
                              const sbp_msg_flash_program_t &b) {
  return sbp_cmp_sbp_msg_flash_program_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_flash_program_t &a,
                              const sbp_msg_flash_program_t &b) {
  return sbp_cmp_sbp_msg_flash_program_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_flash_program_t &a,
                             const sbp_msg_flash_program_t &b) {
  return sbp_cmp_sbp_msg_flash_program_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_flash_program_t &a,
                              const sbp_msg_flash_program_t &b) {
  return sbp_cmp_sbp_msg_flash_program_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_flash_program_t &a,
                             const sbp_msg_flash_program_t &b) {
  return sbp_cmp_sbp_msg_flash_program_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_flash_program_t &a,
                              const sbp_msg_flash_program_t &b) {
  return sbp_cmp_sbp_msg_flash_program_t(&a, &b) >= 0;
}
static inline bool operator==(const sbp_msg_flash_done_t &a,
                              const sbp_msg_flash_done_t &b) {
  return sbp_cmp_sbp_msg_flash_done_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_flash_done_t &a,
                              const sbp_msg_flash_done_t &b) {
  return sbp_cmp_sbp_msg_flash_done_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_flash_done_t &a,
                             const sbp_msg_flash_done_t &b) {
  return sbp_cmp_sbp_msg_flash_done_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_flash_done_t &a,
                              const sbp_msg_flash_done_t &b) {
  return sbp_cmp_sbp_msg_flash_done_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_flash_done_t &a,
                             const sbp_msg_flash_done_t &b) {
  return sbp_cmp_sbp_msg_flash_done_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_flash_done_t &a,
                              const sbp_msg_flash_done_t &b) {
  return sbp_cmp_sbp_msg_flash_done_t(&a, &b) >= 0;
}
static inline bool operator==(const sbp_msg_flash_read_req_t &a,
                              const sbp_msg_flash_read_req_t &b) {
  return sbp_cmp_sbp_msg_flash_read_req_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_flash_read_req_t &a,
                              const sbp_msg_flash_read_req_t &b) {
  return sbp_cmp_sbp_msg_flash_read_req_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_flash_read_req_t &a,
                             const sbp_msg_flash_read_req_t &b) {
  return sbp_cmp_sbp_msg_flash_read_req_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_flash_read_req_t &a,
                              const sbp_msg_flash_read_req_t &b) {
  return sbp_cmp_sbp_msg_flash_read_req_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_flash_read_req_t &a,
                             const sbp_msg_flash_read_req_t &b) {
  return sbp_cmp_sbp_msg_flash_read_req_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_flash_read_req_t &a,
                              const sbp_msg_flash_read_req_t &b) {
  return sbp_cmp_sbp_msg_flash_read_req_t(&a, &b) >= 0;
}
static inline bool operator==(const sbp_msg_flash_read_resp_t &a,
                              const sbp_msg_flash_read_resp_t &b) {
  return sbp_cmp_sbp_msg_flash_read_resp_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_flash_read_resp_t &a,
                              const sbp_msg_flash_read_resp_t &b) {
  return sbp_cmp_sbp_msg_flash_read_resp_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_flash_read_resp_t &a,
                             const sbp_msg_flash_read_resp_t &b) {
  return sbp_cmp_sbp_msg_flash_read_resp_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_flash_read_resp_t &a,
                              const sbp_msg_flash_read_resp_t &b) {
  return sbp_cmp_sbp_msg_flash_read_resp_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_flash_read_resp_t &a,
                             const sbp_msg_flash_read_resp_t &b) {
  return sbp_cmp_sbp_msg_flash_read_resp_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_flash_read_resp_t &a,
                              const sbp_msg_flash_read_resp_t &b) {
  return sbp_cmp_sbp_msg_flash_read_resp_t(&a, &b) >= 0;
}
static inline bool operator==(const sbp_msg_flash_erase_t &a,
                              const sbp_msg_flash_erase_t &b) {
  return sbp_cmp_sbp_msg_flash_erase_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_flash_erase_t &a,
                              const sbp_msg_flash_erase_t &b) {
  return sbp_cmp_sbp_msg_flash_erase_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_flash_erase_t &a,
                             const sbp_msg_flash_erase_t &b) {
  return sbp_cmp_sbp_msg_flash_erase_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_flash_erase_t &a,
                              const sbp_msg_flash_erase_t &b) {
  return sbp_cmp_sbp_msg_flash_erase_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_flash_erase_t &a,
                             const sbp_msg_flash_erase_t &b) {
  return sbp_cmp_sbp_msg_flash_erase_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_flash_erase_t &a,
                              const sbp_msg_flash_erase_t &b) {
  return sbp_cmp_sbp_msg_flash_erase_t(&a, &b) >= 0;
}
static inline bool operator==(const sbp_msg_stm_flash_lock_sector_t &a,
                              const sbp_msg_stm_flash_lock_sector_t &b) {
  return sbp_cmp_sbp_msg_stm_flash_lock_sector_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_stm_flash_lock_sector_t &a,
                              const sbp_msg_stm_flash_lock_sector_t &b) {
  return sbp_cmp_sbp_msg_stm_flash_lock_sector_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_stm_flash_lock_sector_t &a,
                             const sbp_msg_stm_flash_lock_sector_t &b) {
  return sbp_cmp_sbp_msg_stm_flash_lock_sector_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_stm_flash_lock_sector_t &a,
                              const sbp_msg_stm_flash_lock_sector_t &b) {
  return sbp_cmp_sbp_msg_stm_flash_lock_sector_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_stm_flash_lock_sector_t &a,
                             const sbp_msg_stm_flash_lock_sector_t &b) {
  return sbp_cmp_sbp_msg_stm_flash_lock_sector_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_stm_flash_lock_sector_t &a,
                              const sbp_msg_stm_flash_lock_sector_t &b) {
  return sbp_cmp_sbp_msg_stm_flash_lock_sector_t(&a, &b) >= 0;
}
static inline bool operator==(const sbp_msg_stm_flash_unlock_sector_t &a,
                              const sbp_msg_stm_flash_unlock_sector_t &b) {
  return sbp_cmp_sbp_msg_stm_flash_unlock_sector_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_stm_flash_unlock_sector_t &a,
                              const sbp_msg_stm_flash_unlock_sector_t &b) {
  return sbp_cmp_sbp_msg_stm_flash_unlock_sector_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_stm_flash_unlock_sector_t &a,
                             const sbp_msg_stm_flash_unlock_sector_t &b) {
  return sbp_cmp_sbp_msg_stm_flash_unlock_sector_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_stm_flash_unlock_sector_t &a,
                              const sbp_msg_stm_flash_unlock_sector_t &b) {
  return sbp_cmp_sbp_msg_stm_flash_unlock_sector_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_stm_flash_unlock_sector_t &a,
                             const sbp_msg_stm_flash_unlock_sector_t &b) {
  return sbp_cmp_sbp_msg_stm_flash_unlock_sector_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_stm_flash_unlock_sector_t &a,
                              const sbp_msg_stm_flash_unlock_sector_t &b) {
  return sbp_cmp_sbp_msg_stm_flash_unlock_sector_t(&a, &b) >= 0;
}
static inline bool operator==(const sbp_msg_stm_unique_id_req_t &a,
                              const sbp_msg_stm_unique_id_req_t &b) {
  return sbp_cmp_sbp_msg_stm_unique_id_req_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_stm_unique_id_req_t &a,
                              const sbp_msg_stm_unique_id_req_t &b) {
  return sbp_cmp_sbp_msg_stm_unique_id_req_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_stm_unique_id_req_t &a,
                             const sbp_msg_stm_unique_id_req_t &b) {
  return sbp_cmp_sbp_msg_stm_unique_id_req_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_stm_unique_id_req_t &a,
                              const sbp_msg_stm_unique_id_req_t &b) {
  return sbp_cmp_sbp_msg_stm_unique_id_req_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_stm_unique_id_req_t &a,
                             const sbp_msg_stm_unique_id_req_t &b) {
  return sbp_cmp_sbp_msg_stm_unique_id_req_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_stm_unique_id_req_t &a,
                              const sbp_msg_stm_unique_id_req_t &b) {
  return sbp_cmp_sbp_msg_stm_unique_id_req_t(&a, &b) >= 0;
}
static inline bool operator==(const sbp_msg_stm_unique_id_resp_t &a,
                              const sbp_msg_stm_unique_id_resp_t &b) {
  return sbp_cmp_sbp_msg_stm_unique_id_resp_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_stm_unique_id_resp_t &a,
                              const sbp_msg_stm_unique_id_resp_t &b) {
  return sbp_cmp_sbp_msg_stm_unique_id_resp_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_stm_unique_id_resp_t &a,
                             const sbp_msg_stm_unique_id_resp_t &b) {
  return sbp_cmp_sbp_msg_stm_unique_id_resp_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_stm_unique_id_resp_t &a,
                              const sbp_msg_stm_unique_id_resp_t &b) {
  return sbp_cmp_sbp_msg_stm_unique_id_resp_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_stm_unique_id_resp_t &a,
                             const sbp_msg_stm_unique_id_resp_t &b) {
  return sbp_cmp_sbp_msg_stm_unique_id_resp_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_stm_unique_id_resp_t &a,
                              const sbp_msg_stm_unique_id_resp_t &b) {
  return sbp_cmp_sbp_msg_stm_unique_id_resp_t(&a, &b) >= 0;
}
static inline bool operator==(const sbp_msg_m25_flash_write_status_t &a,
                              const sbp_msg_m25_flash_write_status_t &b) {
  return sbp_cmp_sbp_msg_m25_flash_write_status_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_m25_flash_write_status_t &a,
                              const sbp_msg_m25_flash_write_status_t &b) {
  return sbp_cmp_sbp_msg_m25_flash_write_status_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_m25_flash_write_status_t &a,
                             const sbp_msg_m25_flash_write_status_t &b) {
  return sbp_cmp_sbp_msg_m25_flash_write_status_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_m25_flash_write_status_t &a,
                              const sbp_msg_m25_flash_write_status_t &b) {
  return sbp_cmp_sbp_msg_m25_flash_write_status_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_m25_flash_write_status_t &a,
                             const sbp_msg_m25_flash_write_status_t &b) {
  return sbp_cmp_sbp_msg_m25_flash_write_status_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_m25_flash_write_status_t &a,
                              const sbp_msg_m25_flash_write_status_t &b) {
  return sbp_cmp_sbp_msg_m25_flash_write_status_t(&a, &b) >= 0;
}

#endif

#endif /* LIBSBP_NEW_FLASH_MESSAGES_H */
