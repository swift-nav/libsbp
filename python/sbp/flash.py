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


"""
Messages for reading/writing the Piksi's onboard flash memory. These
are in the implementation-defined range (0x0000-0x00FF), and largely
intended for internal-use only.

"""

from construct import *
import json
from sbp import SBP
from sbp.utils import fmt_repr, exclude_fields, walk_json_dict
import six

# Automatically generated from piksi/yaml/swiftnav/sbp/flash.yaml
# with generate.py at 2015-04-14 12:12:07.030879. Please do not hand edit!


SBP_MSG_FLASH_PROGRAM = 0x00E0
class MsgFlashProgram(SBP):
  """SBP class for message MSG_FLASH_PROGRAM (0x00E0).

  You can have MSG_FLASH_PROGRAM inherent its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  The flash program message programs a set of addresses of either
the STM or M25 flash. The Piksi replies with either a
MSG_FLASH_DONE message containing the return code FLASH_OK (0)
on success, or FLASH_INVALID_LEN (2) if the maximum write size
is exceeded. Note that the sector-containing addresses must be
erased before addresses can be programmed.


  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  target : int
    Target flags
  addr_start : array
    Starting address offset to program
  addr_len : int
    Length of set of addresses to program, counting up from
starting address

  data : array
    Data to program addresses with, sized by addr_len

  """
  _parser = Struct("MsgFlashProgram",
                   ULInt8('target'),
                   Struct('addr_start', Array(3, ULInt8('addr_start'))),
                   ULInt8('addr_len'),
                   OptionalGreedyRange(Struct('data', ULInt8('data'))),)

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      self.__dict__.update(sbp.__dict__)
      self.from_binary(sbp.payload)
    else:
      self.target = kwargs.pop('target')
      self.addr_start = kwargs.pop('addr_start')
      self.addr_len = kwargs.pop('addr_len')
      self.data = kwargs.pop('data')

  def __repr__(self):
    return fmt_repr(self)
 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgFlashProgram._parser.parse(d)
    self.__dict__.update(dict(p.viewitems()))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = Container(**exclude_fields(self))
    self.payload = MsgFlashProgram._parser.build(c)
    return self.pack()

  def to_json(self):
    """Produce a JSON-encoded SBP message.

    """
    d = super( MsgFlashProgram, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return json.dumps(d)

  @staticmethod
  def from_json(data):
    """Given a JSON-encoded message, build an object.

    """
    d = json.loads(data)
    sbp = SBP.from_json_dict(d)
    return MsgFlashProgram(sbp)
    
SBP_MSG_FLASH_DONE = 0x00E0
class MsgFlashDone(SBP):
  """SBP class for message MSG_FLASH_DONE (0x00E0).

  You can have MSG_FLASH_DONE inherent its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  This message defines success or failure codes for a variety of
flash memory requests from the host to the Piksi. Flash read and
write messages, such as MSG_FLASH_READ or MSG_FLASH_WRITE, may
return this message on failure.


  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  response : int
    Response flags

  """
  _parser = Struct("MsgFlashDone",
                   ULInt8('response'),)

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      self.__dict__.update(sbp.__dict__)
      self.from_binary(sbp.payload)
    else:
      self.response = kwargs.pop('response')

  def __repr__(self):
    return fmt_repr(self)
 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgFlashDone._parser.parse(d)
    self.__dict__.update(dict(p.viewitems()))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = Container(**exclude_fields(self))
    self.payload = MsgFlashDone._parser.build(c)
    return self.pack()

  def to_json(self):
    """Produce a JSON-encoded SBP message.

    """
    d = super( MsgFlashDone, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return json.dumps(d)

  @staticmethod
  def from_json(data):
    """Given a JSON-encoded message, build an object.

    """
    d = json.loads(data)
    sbp = SBP.from_json_dict(d)
    return MsgFlashDone(sbp)
    
SBP_MSG_FLASH_READ = 0x00E1
class MsgFlashRead(SBP):
  """SBP class for message MSG_FLASH_READ (0x00E1).

  You can have MSG_FLASH_READ inherent its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  The flash read message reads a set of addresses of either the
STM or M25 onboard flash. The Piksi replies with a
MSG_FLASH_READ message containing either the read data on
success or a MSG_FLASH_DONE message containing the return code
FLASH_INVALID_LEN (2) if the maximum read size is exceeded or
FLASH_INVALID_ADDR (3) if the address is outside of the allowed
range.


  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  target : int
    Target flags
  addr_start : array
    Starting address offset to read from
  addr_len : int
    Length of set of addresses to read, counting up from
starting address


  """
  _parser = Struct("MsgFlashRead",
                   ULInt8('target'),
                   Struct('addr_start', Array(3, ULInt8('addr_start'))),
                   ULInt8('addr_len'),)

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      self.__dict__.update(sbp.__dict__)
      self.from_binary(sbp.payload)
    else:
      self.target = kwargs.pop('target')
      self.addr_start = kwargs.pop('addr_start')
      self.addr_len = kwargs.pop('addr_len')

  def __repr__(self):
    return fmt_repr(self)
 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgFlashRead._parser.parse(d)
    self.__dict__.update(dict(p.viewitems()))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = Container(**exclude_fields(self))
    self.payload = MsgFlashRead._parser.build(c)
    return self.pack()

  def to_json(self):
    """Produce a JSON-encoded SBP message.

    """
    d = super( MsgFlashRead, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return json.dumps(d)

  @staticmethod
  def from_json(data):
    """Given a JSON-encoded message, build an object.

    """
    d = json.loads(data)
    sbp = SBP.from_json_dict(d)
    return MsgFlashRead(sbp)
    
SBP_MSG_FLASH_ERASE = 0x00E2
class MsgFlashErase(SBP):
  """SBP class for message MSG_FLASH_ERASE (0x00E2).

  You can have MSG_FLASH_ERASE inherent its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  The flash erase message from the host erases a sector of either
the STM or M25 onboard flash memory. The Piksi will reply with a
MSG_FLASH_DONE message containing the return code - FLASH_OK (0)
on success or FLASH_INVALID_FLASH (1) if the flash specified is
invalid.


  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  target : int
    Target flags
  sector_num : int
    Flash sector number to erase (0-11 for the STM, 0-15 for
the M25)


  """
  _parser = Struct("MsgFlashErase",
                   ULInt8('target'),
                   ULInt8('sector_num'),)

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      self.__dict__.update(sbp.__dict__)
      self.from_binary(sbp.payload)
    else:
      self.target = kwargs.pop('target')
      self.sector_num = kwargs.pop('sector_num')

  def __repr__(self):
    return fmt_repr(self)
 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgFlashErase._parser.parse(d)
    self.__dict__.update(dict(p.viewitems()))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = Container(**exclude_fields(self))
    self.payload = MsgFlashErase._parser.build(c)
    return self.pack()

  def to_json(self):
    """Produce a JSON-encoded SBP message.

    """
    d = super( MsgFlashErase, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return json.dumps(d)

  @staticmethod
  def from_json(data):
    """Given a JSON-encoded message, build an object.

    """
    d = json.loads(data)
    sbp = SBP.from_json_dict(d)
    return MsgFlashErase(sbp)
    
SBP_MSG_STM_FLASH_LOCK_SECTOR = 0x00E3
class MsgStmFlashLockSector(SBP):
  """SBP class for message MSG_STM_FLASH_LOCK_SECTOR (0x00E3).

  You can have MSG_STM_FLASH_LOCK_SECTOR inherent its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  The flash lock message locks a sector of the STM flash
memory. The Piksi replies with a MSG_FLASH_DONE message.


  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  sector : array
    Flash sector number to lock

  """
  _parser = Struct("MsgStmFlashLockSector",
                   Struct('sector', Array(1, ULInt8('sector'))),)

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      self.__dict__.update(sbp.__dict__)
      self.from_binary(sbp.payload)
    else:
      self.sector = kwargs.pop('sector')

  def __repr__(self):
    return fmt_repr(self)
 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgStmFlashLockSector._parser.parse(d)
    self.__dict__.update(dict(p.viewitems()))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = Container(**exclude_fields(self))
    self.payload = MsgStmFlashLockSector._parser.build(c)
    return self.pack()

  def to_json(self):
    """Produce a JSON-encoded SBP message.

    """
    d = super( MsgStmFlashLockSector, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return json.dumps(d)

  @staticmethod
  def from_json(data):
    """Given a JSON-encoded message, build an object.

    """
    d = json.loads(data)
    sbp = SBP.from_json_dict(d)
    return MsgStmFlashLockSector(sbp)
    
SBP_MSG_STM_FLASH_UNLOCK_SECTOR = 0x00E4
class MsgStmFlashUnlockSector(SBP):
  """SBP class for message MSG_STM_FLASH_UNLOCK_SECTOR (0x00E4).

  You can have MSG_STM_FLASH_UNLOCK_SECTOR inherent its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  The flash unlock message unlocks a sector of the STM flash
memory. The Piksi replies with a MSG_FLASH_DONE message.


  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  sector : array
    Flash sector number to unlock

  """
  _parser = Struct("MsgStmFlashUnlockSector",
                   Struct('sector', Array(1, ULInt8('sector'))),)

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      self.__dict__.update(sbp.__dict__)
      self.from_binary(sbp.payload)
    else:
      self.sector = kwargs.pop('sector')

  def __repr__(self):
    return fmt_repr(self)
 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgStmFlashUnlockSector._parser.parse(d)
    self.__dict__.update(dict(p.viewitems()))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = Container(**exclude_fields(self))
    self.payload = MsgStmFlashUnlockSector._parser.build(c)
    return self.pack()

  def to_json(self):
    """Produce a JSON-encoded SBP message.

    """
    d = super( MsgStmFlashUnlockSector, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return json.dumps(d)

  @staticmethod
  def from_json(data):
    """Given a JSON-encoded message, build an object.

    """
    d = json.loads(data)
    sbp = SBP.from_json_dict(d)
    return MsgStmFlashUnlockSector(sbp)
    
SBP_MSG_STM_UNIQUE_ID = 0x00E5
class MsgStmUniqueId(SBP):
  """SBP class for message MSG_STM_UNIQUE_ID (0x00E5).

  You can have MSG_STM_UNIQUE_ID inherent its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  This message reads the STM32F4's hardcoded unique ID. The Piksi
returns STM32F4 unique ID (12 bytes) back to host.


  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  stm_id : string
    STM32F4 unique ID

  """
  _parser = Struct("MsgStmUniqueId",
                   String('stm_id', 12),)

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      self.__dict__.update(sbp.__dict__)
      self.from_binary(sbp.payload)
    else:
      self.stm_id = kwargs.pop('stm_id')

  def __repr__(self):
    return fmt_repr(self)
 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgStmUniqueId._parser.parse(d)
    self.__dict__.update(dict(p.viewitems()))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = Container(**exclude_fields(self))
    self.payload = MsgStmUniqueId._parser.build(c)
    return self.pack()

  def to_json(self):
    """Produce a JSON-encoded SBP message.

    """
    d = super( MsgStmUniqueId, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return json.dumps(d)

  @staticmethod
  def from_json(data):
    """Given a JSON-encoded message, build an object.

    """
    d = json.loads(data)
    sbp = SBP.from_json_dict(d)
    return MsgStmUniqueId(sbp)
    
SBP_MSG_M25_FLASH_WRITE_STATUS = 0x00F3
class MsgM25FlashWriteStatus(SBP):
  """SBP class for message MSG_M25_FLASH_WRITE_STATUS (0x00F3).

  You can have MSG_M25_FLASH_WRITE_STATUS inherent its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  The flash status message writes to the 8-bit M25 flash status
register. The Piksi replies with a MSG_FLASH_DONE message.


  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  status : array
    Byte to write to the M25 flash status register

  """
  _parser = Struct("MsgM25FlashWriteStatus",
                   Struct('status', Array(1, ULInt8('status'))),)

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      self.__dict__.update(sbp.__dict__)
      self.from_binary(sbp.payload)
    else:
      self.status = kwargs.pop('status')

  def __repr__(self):
    return fmt_repr(self)
 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgM25FlashWriteStatus._parser.parse(d)
    self.__dict__.update(dict(p.viewitems()))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = Container(**exclude_fields(self))
    self.payload = MsgM25FlashWriteStatus._parser.build(c)
    return self.pack()

  def to_json(self):
    """Produce a JSON-encoded SBP message.

    """
    d = super( MsgM25FlashWriteStatus, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return json.dumps(d)

  @staticmethod
  def from_json(data):
    """Given a JSON-encoded message, build an object.

    """
    d = json.loads(data)
    sbp = SBP.from_json_dict(d)
    return MsgM25FlashWriteStatus(sbp)
    

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