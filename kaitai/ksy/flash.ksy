# Copyright (C) 2015-2023 Swift Navigation Inc.
# Contact: https://support.swiftnav.com
#
# This source is subject to the license found in the file 'LICENSE' which must
# be distributed together with this source. All other rights reserved.
#
# THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
# EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
# WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
#
# Messages for reading/writing the device's onboard flash memory. Many of these
# messages target specific flash memory peripherals used in Swift Navigation
# devices: the STM32 flash and the M25Pxx FPGA configuration flash from Piksi
# 2.3.1.  This module does not apply to Piksi Multi.
#
# Automatically generated from spec/yaml/swiftnav/sbp/flash.yaml with generate.py.
# Do not modify by hand!

meta:
  id: flash
  endian: le
  imports: [  ]

types:

  msg_flash_program:
    doc: |
      The flash program message programs a set of addresses of either the STM
      or M25 flash. The device replies with either a MSG_FLASH_DONE message
      containing the return code FLASH_OK (0) on success, or FLASH_INVALID_LEN
      (2) if the maximum write size is exceeded. Note that the sector-
      containing addresses must be erased before addresses can be programmed.
    seq:
      - id: target
        doc: |
          Target flags
        type: u1
      - id: addr_start
        doc: |
          Starting address offset to program
        type: u1
        repeat: expr
        repeat-expr: 3
      - id: addr_len
        doc: |
          Length of set of addresses to program, counting up from starting
          address
        type: u1
      - id: data
        doc: |
          Data to program addresses with, with length N=addr_len
        type: u1
        repeat: eos
  
  msg_flash_done:
    doc: |
      This message defines success or failure codes for a variety of flash
      memory requests from the host to the device. Flash read and write
      messages, such as MSG_FLASH_READ_REQ, or MSG_FLASH_PROGRAM, may return
      this message on failure.
    seq:
      - id: response
        doc: |
          Response flags
        type: u1
  
  msg_flash_read_req:
    doc: |
      The flash read message reads a set of addresses of either the STM or M25
      onboard flash. The device replies with a MSG_FLASH_READ_RESP message
      containing either the read data on success or a MSG_FLASH_DONE message
      containing the return code FLASH_INVALID_LEN (2) if the maximum read
      size is exceeded or FLASH_INVALID_ADDR (3) if the address is outside of
      the allowed range.
    seq:
      - id: target
        doc: |
          Target flags
        type: u1
      - id: addr_start
        doc: |
          Starting address offset to read from
        type: u1
        repeat: expr
        repeat-expr: 3
      - id: addr_len
        doc: |
          Length of set of addresses to read, counting up from starting
          address
        type: u1
  
  msg_flash_read_resp:
    doc: |
      The flash read message reads a set of addresses of either the STM or M25
      onboard flash. The device replies with a MSG_FLASH_READ_RESP message
      containing either the read data on success or a MSG_FLASH_DONE message
      containing the return code FLASH_INVALID_LEN (2) if the maximum read
      size is exceeded or FLASH_INVALID_ADDR (3) if the address is outside of
      the allowed range.
    seq:
      - id: target
        doc: |
          Target flags
        type: u1
      - id: addr_start
        doc: |
          Starting address offset to read from
        type: u1
        repeat: expr
        repeat-expr: 3
      - id: addr_len
        doc: |
          Length of set of addresses to read, counting up from starting
          address
        type: u1
  
  msg_flash_erase:
    doc: |
      The flash erase message from the host erases a sector of either the STM
      or M25 onboard flash memory. The device will reply with a MSG_FLASH_DONE
      message containing the return code - FLASH_OK (0) on success or
      FLASH_INVALID_FLASH (1) if the flash specified is invalid.
    seq:
      - id: target
        doc: |
          Target flags
        type: u1
      - id: sector_num
        doc: |
          Flash sector number to erase (0-11 for the STM, 0-15 for the M25)
        type: u4
  
  msg_stm_flash_lock_sector:
    doc: |
      The flash lock message locks a sector of the STM flash memory. The
      device replies with a MSG_FLASH_DONE message.
    seq:
      - id: sector
        doc: |
          Flash sector number to lock
        type: u4
  
  msg_stm_flash_unlock_sector:
    doc: |
      The flash unlock message unlocks a sector of the STM flash memory. The
      device replies with a MSG_FLASH_DONE message.
    seq:
      - id: sector
        doc: |
          Flash sector number to unlock
        type: u4
  
  msg_stm_unique_id_req:
    doc: |
      This message reads the device's hard-coded unique ID. The host requests
      the ID by sending a MSG_STM_UNIQUE_ID_REQ. The device responds with a
      MSG_STM_UNIQUE_ID_RESP with the 12-byte unique ID in the payload.
    seq: []
  
  msg_stm_unique_id_resp:
    doc: |
      This message reads the device's hard-coded unique ID. The host requests
      the ID by sending a MSG_STM_UNIQUE_ID_REQ. The device responds with a
      MSG_STM_UNIQUE_ID_RESP with the 12-byte unique ID in the payload.
    seq:
      - id: stm_id
        doc: |
          Device unique ID
        type: u1
        repeat: expr
        repeat-expr: 12
  
  msg_m25_flash_write_status:
    doc: |
      The flash status message writes to the 8-bit M25 flash status register.
      The device replies with a MSG_FLASH_DONE message.
    seq:
      - id: status
        doc: |
          Byte to write to the M25 flash status register
        type: u1
        repeat: expr
        repeat-expr: 1
  
