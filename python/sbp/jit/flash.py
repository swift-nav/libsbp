#!/usr/bin/env python
# Copyright (C) 2015-2018 Swift Navigation Inc.
# Contact: Swift Navigation <dev@swiftnav.com>
#
# This source is subject to the license found in the file 'LICENSE' which must
# be be distributed together with this source. All other rights reserved.
#
# THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
# EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
# WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.


"""
Messages for reading/writing the device's onboard flash memory. Many
of these messages target specific flash memory peripherals used in
Swift Navigation devices: the STM32 flash and the M25Pxx FPGA
configuration flash from Piksi 2.3.1.  This module does not apply 
to Piksi Multi.

"""

import json

import numpy as np

from sbp.jit.msg import SBP, SENDER_ID
from sbp.jit.msg import get_u8, get_u16, get_u32, get_u64
from sbp.jit.msg import get_s8, get_s16, get_s32, get_s64
from sbp.jit.msg import get_f32, get_f64, judicious_round
from sbp.jit.msg import get_string, get_fixed_string, get_setting
from sbp.jit.msg import get_array, get_fixed_array

# Automatically generated from piksi/yaml/swiftnav/sbp/flash.yaml with generate.py.
# Please do not hand edit!
SBP_MSG_FLASH_PROGRAM = 0x00E6
class MsgFlashProgram(SBP):
  """SBP class for message MSG_FLASH_PROGRAM (0x00E6).

  You can have MSG_FLASH_PROGRAM inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  The flash program message programs a set of addresses of either
the STM or M25 flash. The device replies with either a
MSG_FLASH_DONE message containing the return code FLASH_OK (0)
on success, or FLASH_INVALID_LEN (2) if the maximum write size
is exceeded. Note that the sector-containing addresses must be
erased before addresses can be programmed.


  """
  __slots__ = ['target',
               'addr_start',
               'addr_len',
               'data',
               ]
  @classmethod
  def parse_members(cls, buf, offset, length):
    ret = {}
    (__target, offset, length) = get_u8(buf, offset, length)
    ret['target'] = __target
    (__addr_start, offset, length) = get_fixed_array(get_u8, 3, 1)(buf, offset, length)
    ret['addr_start'] = __addr_start
    (__addr_len, offset, length) = get_u8(buf, offset, length)
    ret['addr_len'] = __addr_len
    (__data, offset, length) = get_array(get_u8)(buf, offset, length)
    ret['data'] = __data
    return ret, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.target = res['target']
    self.addr_start = res['addr_start']
    self.addr_len = res['addr_len']
    self.data = res['data']
    return res, off, length

  @classmethod
  def _payload_size(self):
    ret = 0
    # target: u8
    ret += 1
    # addr_start: array of u8
    ret += 1 * 3
    # addr_len: u8
    ret += 1
    # data: array of u8
    ret += 247
    return ret
  
SBP_MSG_FLASH_DONE = 0x00E0
class MsgFlashDone(SBP):
  """SBP class for message MSG_FLASH_DONE (0x00E0).

  You can have MSG_FLASH_DONE inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  This message defines success or failure codes for a variety of
flash memory requests from the host to the device. Flash read
and write messages, such as MSG_FLASH_READ_REQ, or
MSG_FLASH_PROGRAM, may return this message on failure.


  """
  __slots__ = ['response',
               ]
  @classmethod
  def parse_members(cls, buf, offset, length):
    ret = {}
    (__response, offset, length) = get_u8(buf, offset, length)
    ret['response'] = __response
    return ret, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.response = res['response']
    return res, off, length

  @classmethod
  def _payload_size(self):
    ret = 0
    # response: u8
    ret += 1
    return ret
  
SBP_MSG_FLASH_READ_REQ = 0x00E7
class MsgFlashReadReq(SBP):
  """SBP class for message MSG_FLASH_READ_REQ (0x00E7).

  You can have MSG_FLASH_READ_REQ inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  The flash read message reads a set of addresses of either the
STM or M25 onboard flash. The device replies with a
MSG_FLASH_READ_RESP message containing either the read data on
success or a MSG_FLASH_DONE message containing the return code
FLASH_INVALID_LEN (2) if the maximum read size is exceeded or
FLASH_INVALID_ADDR (3) if the address is outside of the allowed
range.


  """
  __slots__ = ['target',
               'addr_start',
               'addr_len',
               ]
  @classmethod
  def parse_members(cls, buf, offset, length):
    ret = {}
    (__target, offset, length) = get_u8(buf, offset, length)
    ret['target'] = __target
    (__addr_start, offset, length) = get_fixed_array(get_u8, 3, 1)(buf, offset, length)
    ret['addr_start'] = __addr_start
    (__addr_len, offset, length) = get_u8(buf, offset, length)
    ret['addr_len'] = __addr_len
    return ret, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.target = res['target']
    self.addr_start = res['addr_start']
    self.addr_len = res['addr_len']
    return res, off, length

  @classmethod
  def _payload_size(self):
    ret = 0
    # target: u8
    ret += 1
    # addr_start: array of u8
    ret += 1 * 3
    # addr_len: u8
    ret += 1
    return ret
  
SBP_MSG_FLASH_READ_RESP = 0x00E1
class MsgFlashReadResp(SBP):
  """SBP class for message MSG_FLASH_READ_RESP (0x00E1).

  You can have MSG_FLASH_READ_RESP inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  The flash read message reads a set of addresses of either the
STM or M25 onboard flash. The device replies with a
MSG_FLASH_READ_RESP message containing either the read data on
success or a MSG_FLASH_DONE message containing the return code
FLASH_INVALID_LEN (2) if the maximum read size is exceeded or
FLASH_INVALID_ADDR (3) if the address is outside of the allowed
range.


  """
  __slots__ = ['target',
               'addr_start',
               'addr_len',
               ]
  @classmethod
  def parse_members(cls, buf, offset, length):
    ret = {}
    (__target, offset, length) = get_u8(buf, offset, length)
    ret['target'] = __target
    (__addr_start, offset, length) = get_fixed_array(get_u8, 3, 1)(buf, offset, length)
    ret['addr_start'] = __addr_start
    (__addr_len, offset, length) = get_u8(buf, offset, length)
    ret['addr_len'] = __addr_len
    return ret, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.target = res['target']
    self.addr_start = res['addr_start']
    self.addr_len = res['addr_len']
    return res, off, length

  @classmethod
  def _payload_size(self):
    ret = 0
    # target: u8
    ret += 1
    # addr_start: array of u8
    ret += 1 * 3
    # addr_len: u8
    ret += 1
    return ret
  
SBP_MSG_FLASH_ERASE = 0x00E2
class MsgFlashErase(SBP):
  """SBP class for message MSG_FLASH_ERASE (0x00E2).

  You can have MSG_FLASH_ERASE inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  The flash erase message from the host erases a sector of either
the STM or M25 onboard flash memory. The device will reply with a
MSG_FLASH_DONE message containing the return code - FLASH_OK (0)
on success or FLASH_INVALID_FLASH (1) if the flash specified is
invalid.


  """
  __slots__ = ['target',
               'sector_num',
               ]
  @classmethod
  def parse_members(cls, buf, offset, length):
    ret = {}
    (__target, offset, length) = get_u8(buf, offset, length)
    ret['target'] = __target
    (__sector_num, offset, length) = get_u32(buf, offset, length)
    ret['sector_num'] = __sector_num
    return ret, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.target = res['target']
    self.sector_num = res['sector_num']
    return res, off, length

  @classmethod
  def _payload_size(self):
    ret = 0
    # target: u8
    ret += 1
    # sector_num: u32
    ret += 4
    return ret
  
SBP_MSG_STM_FLASH_LOCK_SECTOR = 0x00E3
class MsgStmFlashLockSector(SBP):
  """SBP class for message MSG_STM_FLASH_LOCK_SECTOR (0x00E3).

  You can have MSG_STM_FLASH_LOCK_SECTOR inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  The flash lock message locks a sector of the STM flash
memory. The device replies with a MSG_FLASH_DONE message.


  """
  __slots__ = ['sector',
               ]
  @classmethod
  def parse_members(cls, buf, offset, length):
    ret = {}
    (__sector, offset, length) = get_u32(buf, offset, length)
    ret['sector'] = __sector
    return ret, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.sector = res['sector']
    return res, off, length

  @classmethod
  def _payload_size(self):
    ret = 0
    # sector: u32
    ret += 4
    return ret
  
SBP_MSG_STM_FLASH_UNLOCK_SECTOR = 0x00E4
class MsgStmFlashUnlockSector(SBP):
  """SBP class for message MSG_STM_FLASH_UNLOCK_SECTOR (0x00E4).

  You can have MSG_STM_FLASH_UNLOCK_SECTOR inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  The flash unlock message unlocks a sector of the STM flash
memory. The device replies with a MSG_FLASH_DONE message.


  """
  __slots__ = ['sector',
               ]
  @classmethod
  def parse_members(cls, buf, offset, length):
    ret = {}
    (__sector, offset, length) = get_u32(buf, offset, length)
    ret['sector'] = __sector
    return ret, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.sector = res['sector']
    return res, off, length

  @classmethod
  def _payload_size(self):
    ret = 0
    # sector: u32
    ret += 4
    return ret
  
SBP_MSG_STM_UNIQUE_ID_REQ = 0x00E8
class MsgStmUniqueIdReq(SBP):
  """SBP class for message MSG_STM_UNIQUE_ID_REQ (0x00E8).

  You can have MSG_STM_UNIQUE_ID_REQ inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  This message reads the device's hardcoded unique ID. The host
requests the ID by sending a MSG_STM_UNIQUE_ID_REQ. The device
responds with a MSG_STM_UNIQUE_ID_RESP with the 12-byte unique
ID in the payload.


  """
  __slots__ = []
  def _unpack_members(self, buf, offset, length):
    return {}, offset, length

  def _payload_size(self):
    return 0
  
SBP_MSG_STM_UNIQUE_ID_RESP = 0x00E5
class MsgStmUniqueIdResp(SBP):
  """SBP class for message MSG_STM_UNIQUE_ID_RESP (0x00E5).

  You can have MSG_STM_UNIQUE_ID_RESP inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  This message reads the device's hardcoded unique ID. The host
requests the ID by sending a MSG_STM_UNIQUE_ID_REQ. The device
responds with a MSG_STM_UNIQUE_ID_RESP with the 12-byte unique
ID in the payload..


  """
  __slots__ = ['stm_id',
               ]
  @classmethod
  def parse_members(cls, buf, offset, length):
    ret = {}
    (__stm_id, offset, length) = get_fixed_array(get_u8, 12, 1)(buf, offset, length)
    ret['stm_id'] = __stm_id
    return ret, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.stm_id = res['stm_id']
    return res, off, length

  @classmethod
  def _payload_size(self):
    ret = 0
    # stm_id: array of u8
    ret += 1 * 12
    return ret
  
SBP_MSG_M25_FLASH_WRITE_STATUS = 0x00F3
class MsgM25FlashWriteStatus(SBP):
  """SBP class for message MSG_M25_FLASH_WRITE_STATUS (0x00F3).

  You can have MSG_M25_FLASH_WRITE_STATUS inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  The flash status message writes to the 8-bit M25 flash status
register. The device replies with a MSG_FLASH_DONE message.


  """
  __slots__ = ['status',
               ]
  @classmethod
  def parse_members(cls, buf, offset, length):
    ret = {}
    (__status, offset, length) = get_fixed_array(get_u8, 1, 1)(buf, offset, length)
    ret['status'] = __status
    return ret, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.status = res['status']
    return res, off, length

  @classmethod
  def _payload_size(self):
    ret = 0
    # status: array of u8
    ret += 1 * 1
    return ret
  

msg_classes = {
  0x00E6: MsgFlashProgram,
  0x00E0: MsgFlashDone,
  0x00E7: MsgFlashReadReq,
  0x00E1: MsgFlashReadResp,
  0x00E2: MsgFlashErase,
  0x00E3: MsgStmFlashLockSector,
  0x00E4: MsgStmFlashUnlockSector,
  0x00E8: MsgStmUniqueIdReq,
  0x00E5: MsgStmUniqueIdResp,
  0x00F3: MsgM25FlashWriteStatus,
}