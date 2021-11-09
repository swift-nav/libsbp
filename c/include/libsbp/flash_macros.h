/*
 * Copyright (C) 2015-2021 Swift Navigation Inc.
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

#ifndef LIBSBP_FLASH_MACROS_H
#define LIBSBP_FLASH_MACROS_H

#define SBP_MSG_FLASH_PROGRAM 0x00E6
#define SBP_FLASH_PROGRAM_FLASH_TARGET_TO_READ_MASK (0x1)
#define SBP_FLASH_PROGRAM_FLASH_TARGET_TO_READ_SHIFT (0u)
#define SBP_FLASH_PROGRAM_FLASH_TARGET_TO_READ_GET(flags)           \
  ((u8)(((flags) >> SBP_FLASH_PROGRAM_FLASH_TARGET_TO_READ_SHIFT) & \
        SBP_FLASH_PROGRAM_FLASH_TARGET_TO_READ_MASK))
#define SBP_FLASH_PROGRAM_FLASH_TARGET_TO_READ_SET(flags, val)              \
  do {                                                                      \
    (flags) = (u8)((flags) |                                                \
                   (((val) & (SBP_FLASH_PROGRAM_FLASH_TARGET_TO_READ_MASK)) \
                    << (SBP_FLASH_PROGRAM_FLASH_TARGET_TO_READ_SHIFT)));    \
  } while (0)

#define SBP_FLASH_PROGRAM_FLASH_TARGET_TO_READ_FLASH_STM (0)
#define SBP_FLASH_PROGRAM_FLASH_TARGET_TO_READ_FLASH_M25 (1)
/**
 * The maximum number of items that can be stored in
 * sbp_msg_flash_program_t::addr_start (V4 API) or
 * msg_flash_program_t::addr_start (legacy API) before the maximum SBP message
 * size is exceeded
 */
#define SBP_MSG_FLASH_PROGRAM_ADDR_START_MAX 3u

/**
 * The maximum number of items that can be stored in
 * sbp_msg_flash_program_t::data (V4 API) or msg_flash_program_t::data (legacy
 * API) before the maximum SBP message size is exceeded
 */
#define SBP_MSG_FLASH_PROGRAM_DATA_MAX 250u

/**
 * Encoded length of sbp_msg_flash_program_t (V4 API) and
 * msg_flash_program_t (legacy API)
 *
 * This type is not fixed size and an instance of this message may be longer
 * than the value indicated by this symbol. Users of the V4 API should call
 * #sbp_msg_flash_program_encoded_len to determine the actual size of an
 * instance of this message. Users of the legacy API are required to track the
 * encoded message length when interacting with the legacy type.
 *
 * See the documentation for libsbp for more details regarding the message
 * structure and its variable length component(s)
 */
#define SBP_MSG_FLASH_PROGRAM_ENCODED_OVERHEAD 5u

#define SBP_MSG_FLASH_DONE 0x00E0
#define SBP_FLASH_DONE_RESPONSE_CODE_MASK (0x7)
#define SBP_FLASH_DONE_RESPONSE_CODE_SHIFT (0u)
#define SBP_FLASH_DONE_RESPONSE_CODE_GET(flags)           \
  ((u8)(((flags) >> SBP_FLASH_DONE_RESPONSE_CODE_SHIFT) & \
        SBP_FLASH_DONE_RESPONSE_CODE_MASK))
#define SBP_FLASH_DONE_RESPONSE_CODE_SET(flags, val)                        \
  do {                                                                      \
    (flags) = (u8)((flags) | (((val) & (SBP_FLASH_DONE_RESPONSE_CODE_MASK)) \
                              << (SBP_FLASH_DONE_RESPONSE_CODE_SHIFT)));    \
  } while (0)

#define SBP_FLASH_DONE_RESPONSE_CODE_FLASH_OK (0)
#define SBP_FLASH_DONE_RESPONSE_CODE_FLASH_INVALID_FLASH (1)
#define SBP_FLASH_DONE_RESPONSE_CODE_FLASH_INVALID_LEN (2)
#define SBP_FLASH_DONE_RESPONSE_CODE_FLASH_INVALID_ADDR (3)
#define SBP_FLASH_DONE_RESPONSE_CODE_FLASH_INVALID_RANGE (4)
#define SBP_FLASH_DONE_RESPONSE_CODE_FLASH_INVALID_SECTOR (5)
/**
 * Encoded length of sbp_msg_flash_done_t (V4 API) and
 * msg_flash_done_t (legacy API)
 */
#define SBP_MSG_FLASH_DONE_ENCODED_LEN 1u

#define SBP_MSG_FLASH_READ_REQ 0x00E7
#define SBP_FLASH_READ_REQ_FLASH_TARGET_TO_READ_MASK (0x1)
#define SBP_FLASH_READ_REQ_FLASH_TARGET_TO_READ_SHIFT (0u)
#define SBP_FLASH_READ_REQ_FLASH_TARGET_TO_READ_GET(flags)           \
  ((u8)(((flags) >> SBP_FLASH_READ_REQ_FLASH_TARGET_TO_READ_SHIFT) & \
        SBP_FLASH_READ_REQ_FLASH_TARGET_TO_READ_MASK))
#define SBP_FLASH_READ_REQ_FLASH_TARGET_TO_READ_SET(flags, val)              \
  do {                                                                       \
    (flags) = (u8)((flags) |                                                 \
                   (((val) & (SBP_FLASH_READ_REQ_FLASH_TARGET_TO_READ_MASK)) \
                    << (SBP_FLASH_READ_REQ_FLASH_TARGET_TO_READ_SHIFT)));    \
  } while (0)

#define SBP_FLASH_READ_REQ_FLASH_TARGET_TO_READ_FLASH_STM (0)
#define SBP_FLASH_READ_REQ_FLASH_TARGET_TO_READ_FLASH_M25 (1)
/**
 * The maximum number of items that can be stored in
 * sbp_msg_flash_read_req_t::addr_start (V4 API) or
 * msg_flash_read_req_t::addr_start (legacy API) before the maximum SBP message
 * size is exceeded
 */
#define SBP_MSG_FLASH_READ_REQ_ADDR_START_MAX 3u

/**
 * Encoded length of sbp_msg_flash_read_req_t (V4 API) and
 * msg_flash_read_req_t (legacy API)
 */
#define SBP_MSG_FLASH_READ_REQ_ENCODED_LEN 5u

#define SBP_MSG_FLASH_READ_RESP 0x00E1
#define SBP_FLASH_READ_RESP_FLASH_TARGET_TO_READ_MASK (0x1)
#define SBP_FLASH_READ_RESP_FLASH_TARGET_TO_READ_SHIFT (0u)
#define SBP_FLASH_READ_RESP_FLASH_TARGET_TO_READ_GET(flags)           \
  ((u8)(((flags) >> SBP_FLASH_READ_RESP_FLASH_TARGET_TO_READ_SHIFT) & \
        SBP_FLASH_READ_RESP_FLASH_TARGET_TO_READ_MASK))
#define SBP_FLASH_READ_RESP_FLASH_TARGET_TO_READ_SET(flags, val)              \
  do {                                                                        \
    (flags) = (u8)((flags) |                                                  \
                   (((val) & (SBP_FLASH_READ_RESP_FLASH_TARGET_TO_READ_MASK)) \
                    << (SBP_FLASH_READ_RESP_FLASH_TARGET_TO_READ_SHIFT)));    \
  } while (0)

#define SBP_FLASH_READ_RESP_FLASH_TARGET_TO_READ_FLASH_STM (0)
#define SBP_FLASH_READ_RESP_FLASH_TARGET_TO_READ_FLASH_M25 (1)
/**
 * The maximum number of items that can be stored in
 * sbp_msg_flash_read_resp_t::addr_start (V4 API) or
 * msg_flash_read_resp_t::addr_start (legacy API) before the maximum SBP message
 * size is exceeded
 */
#define SBP_MSG_FLASH_READ_RESP_ADDR_START_MAX 3u

/**
 * Encoded length of sbp_msg_flash_read_resp_t (V4 API) and
 * msg_flash_read_resp_t (legacy API)
 */
#define SBP_MSG_FLASH_READ_RESP_ENCODED_LEN 5u

#define SBP_MSG_FLASH_ERASE 0x00E2
#define SBP_FLASH_ERASE_FLASH_TARGET_TO_READ_MASK (0x1)
#define SBP_FLASH_ERASE_FLASH_TARGET_TO_READ_SHIFT (0u)
#define SBP_FLASH_ERASE_FLASH_TARGET_TO_READ_GET(flags)           \
  ((u8)(((flags) >> SBP_FLASH_ERASE_FLASH_TARGET_TO_READ_SHIFT) & \
        SBP_FLASH_ERASE_FLASH_TARGET_TO_READ_MASK))
#define SBP_FLASH_ERASE_FLASH_TARGET_TO_READ_SET(flags, val)                  \
  do {                                                                        \
    (flags) =                                                                 \
        (u8)((flags) | (((val) & (SBP_FLASH_ERASE_FLASH_TARGET_TO_READ_MASK)) \
                        << (SBP_FLASH_ERASE_FLASH_TARGET_TO_READ_SHIFT)));    \
  } while (0)

#define SBP_FLASH_ERASE_FLASH_TARGET_TO_READ_FLASH_STM (0)
#define SBP_FLASH_ERASE_FLASH_TARGET_TO_READ_FLASH_M25 (1)
/**
 * Encoded length of sbp_msg_flash_erase_t (V4 API) and
 * msg_flash_erase_t (legacy API)
 */
#define SBP_MSG_FLASH_ERASE_ENCODED_LEN 5u

#define SBP_MSG_STM_FLASH_LOCK_SECTOR 0x00E3
/**
 * Encoded length of sbp_msg_stm_flash_lock_sector_t (V4 API) and
 * msg_stm_flash_lock_sector_t (legacy API)
 */
#define SBP_MSG_STM_FLASH_LOCK_SECTOR_ENCODED_LEN 4u

#define SBP_MSG_STM_FLASH_UNLOCK_SECTOR 0x00E4
/**
 * Encoded length of sbp_msg_stm_flash_unlock_sector_t (V4 API) and
 * msg_stm_flash_unlock_sector_t (legacy API)
 */
#define SBP_MSG_STM_FLASH_UNLOCK_SECTOR_ENCODED_LEN 4u

#define SBP_MSG_STM_UNIQUE_ID_REQ 0x00E8
/**
 * Encoded length of sbp_msg_stm_unique_id_req_t (V4 API) and
 * msg_stm_unique_id_req_t (legacy API)
 */
#define SBP_MSG_STM_UNIQUE_ID_REQ_ENCODED_LEN 0u

#define SBP_MSG_STM_UNIQUE_ID_RESP 0x00E5
/**
 * The maximum number of items that can be stored in
 * sbp_msg_stm_unique_id_resp_t::stm_id (V4 API) or
 * msg_stm_unique_id_resp_t::stm_id (legacy API) before the maximum SBP message
 * size is exceeded
 */
#define SBP_MSG_STM_UNIQUE_ID_RESP_STM_ID_MAX 12u

/**
 * Encoded length of sbp_msg_stm_unique_id_resp_t (V4 API) and
 * msg_stm_unique_id_resp_t (legacy API)
 */
#define SBP_MSG_STM_UNIQUE_ID_RESP_ENCODED_LEN 12u

#define SBP_MSG_M25_FLASH_WRITE_STATUS 0x00F3
/**
 * The maximum number of items that can be stored in
 * sbp_msg_m25_flash_write_status_t::status (V4 API) or
 * msg_m25_flash_write_status_t::status (legacy API) before the maximum SBP
 * message size is exceeded
 */
#define SBP_MSG_M25_FLASH_WRITE_STATUS_STATUS_MAX 1u

/**
 * Encoded length of sbp_msg_m25_flash_write_status_t (V4 API) and
 * msg_m25_flash_write_status_t (legacy API)
 */
#define SBP_MSG_M25_FLASH_WRITE_STATUS_ENCODED_LEN 1u

#endif /* LIBSBP_FLASH_MACROS_H */
