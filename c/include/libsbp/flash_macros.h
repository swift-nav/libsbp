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
#define SBP_MSG_FLASH_DONE 0x00E0
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
#define SBP_MSG_FLASH_READ_REQ 0x00E7
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
#define SBP_MSG_FLASH_READ_RESP 0x00E1
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
#define SBP_MSG_FLASH_ERASE 0x00E2
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
#define SBP_MSG_STM_FLASH_LOCK_SECTOR 0x00E3
#define SBP_MSG_STM_FLASH_UNLOCK_SECTOR 0x00E4
#define SBP_MSG_STM_UNIQUE_ID_REQ 0x00E8
#define SBP_MSG_STM_UNIQUE_ID_RESP 0x00E5
#define SBP_MSG_M25_FLASH_WRITE_STATUS 0x00F3

#endif
