#!/usr/bin/env python
# Copyright (C) 2015 Swift Navigation Inc.
# Contact: Fergus Noble <fergus@swiftnav.com>
#
# This source is subject to the license found in the file 'LICENSE' which must
# be be distributed together with this source. All other rights reserved.
#
# THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
# EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
# WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.

from construct import *
from sbp import SBP
from sbp.utils import fmt_repr
import six

# Automatically generated from piksi/yaml/swiftnav/sbp/flash.yaml
# with generate.py at 2015-04-06 23:40:11.126002. Please do not hand edit!


SBP_MSG_FLASH_PROGRAM = 0x00E0
class MsgFlashProgram(SBP):
  """SBP class for message MSG_FLASH_PROGRAM (0x00E0).
  
  The flash program message programs a set of addresses of either
the STM or M25 flash. The Piksi replies with either a
MSG_FLASH_DONE message containing the return code FLASH_OK (0)
on success, or FLASH_INVALID_LEN (2) if the maximum write size
is exceeded. Note that the sector-containing addresses must be
erased before addresses can be programmed.


  Parameters
  ----------
  target : int
    Target flags
  addr_start : array
    Starting address offset to program
  addr_len : int
    Length of set of addresses to program, counting up from
starting address.

  data : array
    Data to program addresses with, sized by addr_len.

  """
  _parser = Struct("MsgFlashProgram",
                   ULInt8('target'),
                   Struct('addr_start', Array(3, ULInt8('addr_start'))),
                   ULInt8('addr_len'),
                   OptionalGreedyRange(Struct('data', ULInt8('data'))),)

  def __init__(self, sbp):
    self.__dict__.update(sbp.__dict__)
    self.from_binary(sbp.payload)

  def __repr__(self):
    return fmt_repr(self)
 
  def from_binary(self, d):
    p = MsgFlashProgram._parser.parse(d)
    self.__dict__.update(dict(p.viewitems()))

  def to_binary(self):
    return MsgFlashProgram.build(self.__dict__)
    
SBP_MSG_FLASH_DONE = 0x00E0
class MsgFlashDone(SBP):
  """SBP class for message MSG_FLASH_DONE (0x00E0).
  
  This message defines success or failure codes for a variety of
flash memory requests from the host to the Piksi. Flash read and
write messages, such as MSG_FLASH_READ or MSG_FLASH_WRITE, may
return this message on failure.


  Parameters
  ----------
  response : int
    Response flags

  """
  _parser = Struct("MsgFlashDone",
                   ULInt8('response'),)

  def __init__(self, sbp):
    self.__dict__.update(sbp.__dict__)
    self.from_binary(sbp.payload)

  def __repr__(self):
    return fmt_repr(self)
 
  def from_binary(self, d):
    p = MsgFlashDone._parser.parse(d)
    self.__dict__.update(dict(p.viewitems()))

  def to_binary(self):
    return MsgFlashDone.build(self.__dict__)
    
SBP_MSG_FLASH_READ = 0x00E1
class MsgFlashRead(SBP):
  """SBP class for message MSG_FLASH_READ (0x00E1).
  
  The flash read message reads a set of addresses of either the
STM or M25 onboard flash. The Piksi replies with a
MSG_FLASH_READ message containing either the read data on
success or a MSG_FLASH_DONE message containing the return code
FLASH_INVALID_LEN (2) if the maximum read size is exceeded or
FLASH_INVALID_ADDR (3) if the address is outside of the allowed
range.


  Parameters
  ----------
  target : int
    Target flags
  addr_start : array
    Starting address offset to read from
  addr_len : int
    Length of set of addresses to read, counting up from
starting address.


  """
  _parser = Struct("MsgFlashRead",
                   ULInt8('target'),
                   Struct('addr_start', Array(3, ULInt8('addr_start'))),
                   ULInt8('addr_len'),)

  def __init__(self, sbp):
    self.__dict__.update(sbp.__dict__)
    self.from_binary(sbp.payload)

  def __repr__(self):
    return fmt_repr(self)
 
  def from_binary(self, d):
    p = MsgFlashRead._parser.parse(d)
    self.__dict__.update(dict(p.viewitems()))

  def to_binary(self):
    return MsgFlashRead.build(self.__dict__)
    
SBP_MSG_FLASH_ERASE = 0x00E2
class MsgFlashErase(SBP):
  """SBP class for message MSG_FLASH_ERASE (0x00E2).
  
  The flash erase message from the host erases a sector of either
the STM or M25 onboard flash memory. The Piksi will reply with a
MSG_FLASH_DONE message containing the return code - FLASH_OK (0)
on success or FLASH_INVALID_FLASH (1) if the flash specified is
invalid.


  Parameters
  ----------
  target : int
    Target flags
  sector_num : int
    Flash sector number to erase (0-11 for the STM, 0-15 for
the M25).


  """
  _parser = Struct("MsgFlashErase",
                   ULInt8('target'),
                   ULInt8('sector_num'),)

  def __init__(self, sbp):
    self.__dict__.update(sbp.__dict__)
    self.from_binary(sbp.payload)

  def __repr__(self):
    return fmt_repr(self)
 
  def from_binary(self, d):
    p = MsgFlashErase._parser.parse(d)
    self.__dict__.update(dict(p.viewitems()))

  def to_binary(self):
    return MsgFlashErase.build(self.__dict__)
    
SBP_MSG_STM_FLASH_LOCK_SECTOR = 0x00E3
class MsgStmFlashLockSector(SBP):
  """SBP class for message MSG_STM_FLASH_LOCK_SECTOR (0x00E3).
  
  The flash lock message locks a sector of the STM flash
memory. The Piksi replies with a MSG_FLASH_DONE message.


  Parameters
  ----------
  sector : array
    Flash sector number to lock.

  """
  _parser = Struct("MsgStmFlashLockSector",
                   Struct('sector', Array(1, ULInt8('sector'))),)

  def __init__(self, sbp):
    self.__dict__.update(sbp.__dict__)
    self.from_binary(sbp.payload)

  def __repr__(self):
    return fmt_repr(self)
 
  def from_binary(self, d):
    p = MsgStmFlashLockSector._parser.parse(d)
    self.__dict__.update(dict(p.viewitems()))

  def to_binary(self):
    return MsgStmFlashLockSector.build(self.__dict__)
    
SBP_MSG_STM_FLASH_UNLOCK_SECTOR = 0x00E4
class MsgStmFlashUnlockSector(SBP):
  """SBP class for message MSG_STM_FLASH_UNLOCK_SECTOR (0x00E4).
  
  The flash unlock message unlocks a sector of the STM flash
memory. The Piksi replies with a MSG_FLASH_DONE message.


  Parameters
  ----------
  sector : array
    Flash sector number to unlock.

  """
  _parser = Struct("MsgStmFlashUnlockSector",
                   Struct('sector', Array(1, ULInt8('sector'))),)

  def __init__(self, sbp):
    self.__dict__.update(sbp.__dict__)
    self.from_binary(sbp.payload)

  def __repr__(self):
    return fmt_repr(self)
 
  def from_binary(self, d):
    p = MsgStmFlashUnlockSector._parser.parse(d)
    self.__dict__.update(dict(p.viewitems()))

  def to_binary(self):
    return MsgStmFlashUnlockSector.build(self.__dict__)
    
SBP_MSG_STM_UNIQUE_ID = 0x00E5
class MsgStmUniqueId(SBP):
  """SBP class for message MSG_STM_UNIQUE_ID (0x00E5).
  
  This message reads the STM32F4's hardcoded unique ID. The Piksi
returns STM32F4 unique ID (12 bytes) back to host.


  Parameters
  ----------
  stm_id : string
    STM32F4 unique ID.

  """
  _parser = Struct("MsgStmUniqueId",
                   String('stm_id', 12),)

  def __init__(self, sbp):
    self.__dict__.update(sbp.__dict__)
    self.from_binary(sbp.payload)

  def __repr__(self):
    return fmt_repr(self)
 
  def from_binary(self, d):
    p = MsgStmUniqueId._parser.parse(d)
    self.__dict__.update(dict(p.viewitems()))

  def to_binary(self):
    return MsgStmUniqueId.build(self.__dict__)
    
SBP_MSG_M25_FLASH_WRITE_STATUS = 0x00F3
class MsgM25FlashWriteStatus(SBP):
  """SBP class for message MSG_M25_FLASH_WRITE_STATUS (0x00F3).
  
  The flash status message writes to the 8-bit M25 flash status
register. The Piksi replies with a MSG_FLASH_DONE message.


  Parameters
  ----------
  status : array
    Byte to write to the M25 flash status register.

  """
  _parser = Struct("MsgM25FlashWriteStatus",
                   Struct('status', Array(1, ULInt8('status'))),)

  def __init__(self, sbp):
    self.__dict__.update(sbp.__dict__)
    self.from_binary(sbp.payload)

  def __repr__(self):
    return fmt_repr(self)
 
  def from_binary(self, d):
    p = MsgM25FlashWriteStatus._parser.parse(d)
    self.__dict__.update(dict(p.viewitems()))

  def to_binary(self):
    return MsgM25FlashWriteStatus.build(self.__dict__)
    

msg_classes = {
  0x00E0: MsgFlashProgram,
  0x00E0: MsgFlashDone,
  0x00E1: MsgFlashRead,
  0x00E2: MsgFlashErase,
  0x00E3: MsgStmFlashLockSector,
  0x00E4: MsgStmFlashUnlockSector,
  0x00E5: MsgStmUniqueId,
  0x00F3: MsgM25FlashWriteStatus,
}