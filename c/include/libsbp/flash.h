/*
 * Copyright (C) 2015 Swift Navigation Inc.
 * Contact: Fergus Noble <fergus@swift-nav.com>
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

/** \defgroup flash Flash
 *
 *  * Messages for reading/writing the device's onboard flash memory. Many
 * of these messages target specific flash memory peripherals used in
 * Swift Navigation devices: the STM32 flash and the M25Pxx FPGA
 * configuration flash.
 * \{ */

#ifndef LIBSBP_FLASH_MESSAGES_H
#define LIBSBP_FLASH_MESSAGES_H

#include "common.h"


/** Program flash addresses
 *
 * The flash program message programs a set of addresses of either
 * the STM or M25 flash. The device replies with either a
 * MSG_FLASH_DONE message containing the return code FLASH_OK (0)
 * on success, or FLASH_INVALID_LEN (2) if the maximum write size
 * is exceeded. Note that the sector-containing addresses must be
 * erased before addresses can be programmed.
 */
#define SBP_MSG_FLASH_PROGRAM           0x00E6
typedef struct __attribute__((packed)) {
  u8 target;        /**< Target flags */
  u8 addr_start[3]; /**< Starting address offset to program [bytes] */
  u8 addr_len;      /**< Length of set of addresses to program, counting up from
starting address
 [bytes] */
  u8 data[0];       /**< Data to program addresses with, with length N=addr_len */
} msg_flash_program_t;


/** Flash response message (host <= device).
 *
 * This message defines success or failure codes for a variety of
 * flash memory requests from the host to the device. Flash read
 * and write messages, such as MSG_FLASH_READ_REQ, or
 * MSG_FLASH_PROGRAM, may return this message on failure.
 */
#define SBP_MSG_FLASH_DONE              0x00E0
typedef struct __attribute__((packed)) {
  u8 response;    /**< Response flags */
} msg_flash_done_t;


/** Read STM or M25 flash address request (host => device).
 *
 * The flash read message reads a set of addresses of either the
 * STM or M25 onboard flash. The device replies with a
 * MSG_FLASH_READ_RESP message containing either the read data on
 * success or a MSG_FLASH_DONE message containing the return code
 * FLASH_INVALID_LEN (2) if the maximum read size is exceeded or
 * FLASH_INVALID_ADDR (3) if the address is outside of the allowed
 * range.
 */
#define SBP_MSG_FLASH_READ_REQ          0x00E7
typedef struct __attribute__((packed)) {
  u8 target;        /**< Target flags */
  u8 addr_start[3]; /**< Starting address offset to read from [bytes] */
  u8 addr_len;      /**< Length of set of addresses to read, counting up from
starting address
 [bytes] */
} msg_flash_read_req_t;


/** Read STM or M25 flash address response (host <= device).
 *
 * The flash read message reads a set of addresses of either the
 * STM or M25 onboard flash. The device replies with a
 * MSG_FLASH_READ_RESP message containing either the read data on
 * success or a MSG_FLASH_DONE message containing the return code
 * FLASH_INVALID_LEN (2) if the maximum read size is exceeded or
 * FLASH_INVALID_ADDR (3) if the address is outside of the allowed
 * range.
 */
#define SBP_MSG_FLASH_READ_RESP         0x00E1
typedef struct __attribute__((packed)) {
  u8 target;        /**< Target flags */
  u8 addr_start[3]; /**< Starting address offset to read from [bytes] */
  u8 addr_len;      /**< Length of set of addresses to read, counting up from
starting address
 [bytes] */
} msg_flash_read_resp_t;


/** Erase sector of device flash memory (host => device).
 *
 * The flash erase message from the host erases a sector of either
 * the STM or M25 onboard flash memory. The device will reply with a
 * MSG_FLASH_DONE message containing the return code - FLASH_OK (0)
 * on success or FLASH_INVALID_FLASH (1) if the flash specified is
 * invalid.
 */
#define SBP_MSG_FLASH_ERASE             0x00E2
typedef struct __attribute__((packed)) {
  u8 target;        /**< Target flags */
  u32 sector_num;    /**< Flash sector number to erase (0-11 for the STM, 0-15 for
the M25)
 */
} msg_flash_erase_t;


/** Lock sector of STM flash memory (host => device)
 *
 * The flash lock message locks a sector of the STM flash
 * memory. The device replies with a MSG_FLASH_DONE message.
 */
#define SBP_MSG_STM_FLASH_LOCK_SECTOR   0x00E3
typedef struct __attribute__((packed)) {
  u32 sector;    /**< Flash sector number to lock */
} msg_stm_flash_lock_sector_t;


/** Unlock sector of STM flash memory (host => device)
 *
 * The flash unlock message unlocks a sector of the STM flash
 * memory. The device replies with a MSG_FLASH_DONE message.
 */
#define SBP_MSG_STM_FLASH_UNLOCK_SECTOR 0x00E4
typedef struct __attribute__((packed)) {
  u32 sector;    /**< Flash sector number to unlock */
} msg_stm_flash_unlock_sector_t;


/** Read device's hardcoded unique ID request (host => device)

 *
 * This message reads the device's hardcoded unique ID. The host
 * requests the ID by sending a MSG_STM_UNIQUE_ID_REQ. The device
 * responds with a MSG_STM_UNIQUE_ID_RESP with the 12-byte unique
 * ID in the payload.
 */
#define SBP_MSG_STM_UNIQUE_ID_REQ       0x00E8


/** Read device's hardcoded unique ID response (host <= device)

 *
 * This message reads the device's hardcoded unique ID. The host
 * requests the ID by sending a MSG_STM_UNIQUE_ID_REQ. The device
 * responds with a MSG_STM_UNIQUE_ID_RESP with the 12-byte unique
 * ID in the payload..
 */
#define SBP_MSG_STM_UNIQUE_ID_RESP      0x00E5
typedef struct __attribute__((packed)) {
  u8 stm_id[12]; /**< Device unique ID */
} msg_stm_unique_id_resp_t;


/** Write M25 flash status register (host => device)
 *
 * The flash status message writes to the 8-bit M25 flash status
 * register. The device replies with a MSG_FLASH_DONE message.
 */
#define SBP_MSG_M25_FLASH_WRITE_STATUS  0x00F3
typedef struct __attribute__((packed)) {
  u8 status[1]; /**< Byte to write to the M25 flash status register */
} msg_m25_flash_write_status_t;


/** \} */

#endif /* LIBSBP_FLASH_MESSAGES_H */