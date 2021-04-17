/*
 * Copyright (C) 2021 Swift Navigation Inc.
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

#ifndef LIBSBP_CPP_FLASH_MESSAGES_H
#define LIBSBP_CPP_FLASH_MESSAGES_H

#include <cstddef>
#include <libsbp/common.h>
#include <libsbp/sbp.h>

namespace sbp {
  
  /**
   * Program flash addresses
   *
   * The flash program message programs a set of addresses of either
   * the STM or M25 flash. The device replies with either a
   * MSG_FLASH_DONE message containing the return code FLASH_OK (0)
   * on success, or FLASH_INVALID_LEN (2) if the maximum write size
   * is exceeded. Note that the sector-containing addresses must be
   * erased before addresses can be programmed.
   */
  template<size_t DATA_COUNT = (SBP_MAX_PAYLOAD_LEN - (sizeof(u8) + sizeof(u8[3]) + sizeof(u8) + 0)) / sizeof(u8)>
  struct SBP_ATTR_PACKED MsgFlashProgram {
    u8 target; /** Target flags */
    u8 addr_start[3]; /** Starting address offset to program [bytes] */
    u8 addr_len; /** Length of set of addresses to program, counting up from
starting address
 [bytes] */
    u8 data[DATA_COUNT]; /** Data to program addresses with, with length N=addr_len */
  };
  
  /**
   * Flash response message (host <= device).
   *
   * This message defines success or failure codes for a variety of
   * flash memory requests from the host to the device. Flash read
   * and write messages, such as MSG_FLASH_READ_REQ, or
   * MSG_FLASH_PROGRAM, may return this message on failure.
   */
  
  struct SBP_ATTR_PACKED MsgFlashDone {
    u8 response; /** Response flags */
  };
  
  /**
   * Read STM or M25 flash address request (host => device).
   *
   * The flash read message reads a set of addresses of either the
   * STM or M25 onboard flash. The device replies with a
   * MSG_FLASH_READ_RESP message containing either the read data on
   * success or a MSG_FLASH_DONE message containing the return code
   * FLASH_INVALID_LEN (2) if the maximum read size is exceeded or
   * FLASH_INVALID_ADDR (3) if the address is outside of the allowed
   * range.
   */
  
  struct SBP_ATTR_PACKED MsgFlashReadReq {
    u8 target; /** Target flags */
    u8 addr_start[3]; /** Starting address offset to read from [bytes] */
    u8 addr_len; /** Length of set of addresses to read, counting up from
starting address
 [bytes] */
  };
  
  /**
   * Read STM or M25 flash address response (host <= device).
   *
   * The flash read message reads a set of addresses of either the
   * STM or M25 onboard flash. The device replies with a
   * MSG_FLASH_READ_RESP message containing either the read data on
   * success or a MSG_FLASH_DONE message containing the return code
   * FLASH_INVALID_LEN (2) if the maximum read size is exceeded or
   * FLASH_INVALID_ADDR (3) if the address is outside of the allowed
   * range.
   */
  
  struct SBP_ATTR_PACKED MsgFlashReadResp {
    u8 target; /** Target flags */
    u8 addr_start[3]; /** Starting address offset to read from [bytes] */
    u8 addr_len; /** Length of set of addresses to read, counting up from
starting address
 [bytes] */
  };
  
  /**
   * Erase sector of device flash memory (host => device).
   *
   * The flash erase message from the host erases a sector of either
   * the STM or M25 onboard flash memory. The device will reply with a
   * MSG_FLASH_DONE message containing the return code - FLASH_OK (0)
   * on success or FLASH_INVALID_FLASH (1) if the flash specified is
   * invalid.
   */
  
  struct SBP_ATTR_PACKED MsgFlashErase {
    u8 target; /** Target flags */
    u32 sector_num; /** Flash sector number to erase (0-11 for the STM, 0-15 for
the M25)
 */
  };
  
  /**
   * Lock sector of STM flash memory (host => device)
   *
   * The flash lock message locks a sector of the STM flash
   * memory. The device replies with a MSG_FLASH_DONE message.
   */
  
  struct SBP_ATTR_PACKED MsgStmFlashLockSector {
    u32 sector; /** Flash sector number to lock */
  };
  
  /**
   * Unlock sector of STM flash memory (host => device)
   *
   * The flash unlock message unlocks a sector of the STM flash
   * memory. The device replies with a MSG_FLASH_DONE message.
   */
  
  struct SBP_ATTR_PACKED MsgStmFlashUnlockSector {
    u32 sector; /** Flash sector number to unlock */
  };
  
  /**
   * Read device's hardcoded unique ID request (host => device)

   *
   * This message reads the device's hardcoded unique ID. The host
   * requests the ID by sending a MSG_STM_UNIQUE_ID_REQ. The device
   * responds with a MSG_STM_UNIQUE_ID_RESP with the 12-byte unique
   * ID in the payload.
   */
  
  /**
   * Read device's hardcoded unique ID response (host <= device)

   *
   * This message reads the device's hardcoded unique ID. The host
   * requests the ID by sending a MSG_STM_UNIQUE_ID_REQ. The device
   * responds with a MSG_STM_UNIQUE_ID_RESP with the 12-byte unique
   * ID in the payload..
   */
  
  struct SBP_ATTR_PACKED MsgStmUniqueIdResp {
    u8 stm_id[12]; /** Device unique ID */
  };
  
  /**
   * Write M25 flash status register (host => device)
   *
   * The flash status message writes to the 8-bit M25 flash status
   * register. The device replies with a MSG_FLASH_DONE message.
   */
  
  struct SBP_ATTR_PACKED MsgM25FlashWriteStatus {
    u8 status[1]; /** Byte to write to the M25 flash status register */
  };
  

}  // namespace sbp

#endif /* LIBSBP_CPP_FLASH_MESSAGES_H */