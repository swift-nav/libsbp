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
Messages for reading/writing the device's onboard flash memory. Many
of these messages target specific flash memory peripherals used in
Swift Navigation devices: the STM32 flash and the M25Pxx FPGA
configuration flash.

These are in the implementation-defined range (0x0000-0x00FF), and
are intended for internal-use only.

"""

from construct import *
import json
from sbp.msg import SBP
from sbp.utils import fmt_repr, exclude_fields, walk_json_dict, containerize
import six

# Automatically generated from piksi/yaml/swiftnav/sbp/flash.yaml with generate.py.
# Please do not hand edit!


SBP_MSG_FLASH_PROGRAM = 0x00E6
class MsgFlashProgram(SBP):
  """SBP class for message MSG_FLASH_PROGRAM (0x00E6).

  You can have MSG_FLASH_PROGRAM inherent its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  The flash program message programs a set of addresses of either
the STM or M25 flash. The device replies with either a
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
    Data to program addresses with, with length N=addr_len
  sender : int
    Optional sender ID, defaults to 0

  """
  _parser = Struct("MsgFlashProgram",
                   ULInt8('target'),
                   Struct('addr_start', Array(3, ULInt8('addr_start'))),
                   ULInt8('addr_len'),
                   OptionalGreedyRange(ULInt8('data')),)

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      self.__dict__.update(sbp.__dict__)
      self.from_binary(sbp.payload)
    else:
      super( MsgFlashProgram, self).__init__()
      self.msg_type = SBP_MSG_FLASH_PROGRAM
      self.sender = kwargs.pop('sender', 0)
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
    c = containerize(exclude_fields(self))
    self.payload = MsgFlashProgram._parser.build(c)
    return self.pack()

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    sbp = SBP.from_json_dict(d)
    return MsgFlashProgram(sbp)

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgFlashProgram, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    
SBP_MSG_FLASH_DONE = 0x00E0
class MsgFlashDone(SBP):
  """SBP class for message MSG_FLASH_DONE (0x00E0).

  You can have MSG_FLASH_DONE inherent its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  This message defines success or failure codes for a variety of
flash memory requests from the host to the device. Flash read
and write messages, such as MSG_FLASH_READ_REQUEST, or
MSG_FLASH_PROGRAM, may return this message on failure.


  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  response : int
    Response flags
  sender : int
    Optional sender ID, defaults to 0

  """
  _parser = Struct("MsgFlashDone",
                   ULInt8('response'),)

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      self.__dict__.update(sbp.__dict__)
      self.from_binary(sbp.payload)
    else:
      super( MsgFlashDone, self).__init__()
      self.msg_type = SBP_MSG_FLASH_DONE
      self.sender = kwargs.pop('sender', 0)
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
    c = containerize(exclude_fields(self))
    self.payload = MsgFlashDone._parser.build(c)
    return self.pack()

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    sbp = SBP.from_json_dict(d)
    return MsgFlashDone(sbp)

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgFlashDone, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    
SBP_MSG_FLASH_READ_REQUEST = 0x00E7
class MsgFlashReadRequest(SBP):
  """SBP class for message MSG_FLASH_READ_REQUEST (0x00E7).

  You can have MSG_FLASH_READ_REQUEST inherent its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  The flash read message reads a set of addresses of either the
STM or M25 onboard flash. The device replies with a
MSG_FLASH_READ_RESPONSE message containing either the read data on
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

  sender : int
    Optional sender ID, defaults to 0

  """
  _parser = Struct("MsgFlashReadRequest",
                   ULInt8('target'),
                   Struct('addr_start', Array(3, ULInt8('addr_start'))),
                   ULInt8('addr_len'),)

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      self.__dict__.update(sbp.__dict__)
      self.from_binary(sbp.payload)
    else:
      super( MsgFlashReadRequest, self).__init__()
      self.msg_type = SBP_MSG_FLASH_READ_REQUEST
      self.sender = kwargs.pop('sender', 0)
      self.target = kwargs.pop('target')
      self.addr_start = kwargs.pop('addr_start')
      self.addr_len = kwargs.pop('addr_len')

  def __repr__(self):
    return fmt_repr(self)
 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgFlashReadRequest._parser.parse(d)
    self.__dict__.update(dict(p.viewitems()))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgFlashReadRequest._parser.build(c)
    return self.pack()

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    sbp = SBP.from_json_dict(d)
    return MsgFlashReadRequest(sbp)

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgFlashReadRequest, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    
SBP_MSG_FLASH_READ_RESPONSE = 0x00E1
class MsgFlashReadResponse(SBP):
  """SBP class for message MSG_FLASH_READ_RESPONSE (0x00E1).

  You can have MSG_FLASH_READ_RESPONSE inherent its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  The flash read message reads a set of addresses of either the
STM or M25 onboard flash. The device replies with a
MSG_FLASH_READ_RESPONSE message containing either the read data on
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

  sender : int
    Optional sender ID, defaults to 0

  """
  _parser = Struct("MsgFlashReadResponse",
                   ULInt8('target'),
                   Struct('addr_start', Array(3, ULInt8('addr_start'))),
                   ULInt8('addr_len'),)

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      self.__dict__.update(sbp.__dict__)
      self.from_binary(sbp.payload)
    else:
      super( MsgFlashReadResponse, self).__init__()
      self.msg_type = SBP_MSG_FLASH_READ_RESPONSE
      self.sender = kwargs.pop('sender', 0)
      self.target = kwargs.pop('target')
      self.addr_start = kwargs.pop('addr_start')
      self.addr_len = kwargs.pop('addr_len')

  def __repr__(self):
    return fmt_repr(self)
 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgFlashReadResponse._parser.parse(d)
    self.__dict__.update(dict(p.viewitems()))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgFlashReadResponse._parser.build(c)
    return self.pack()

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    sbp = SBP.from_json_dict(d)
    return MsgFlashReadResponse(sbp)

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgFlashReadResponse, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    
SBP_MSG_FLASH_ERASE = 0x00E2
class MsgFlashErase(SBP):
  """SBP class for message MSG_FLASH_ERASE (0x00E2).

  You can have MSG_FLASH_ERASE inherent its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  The flash erase message from the host erases a sector of either
the STM or M25 onboard flash memory. The device will reply with a
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

  sender : int
    Optional sender ID, defaults to 0

  """
  _parser = Struct("MsgFlashErase",
                   ULInt8('target'),
                   ULInt32('sector_num'),)

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      self.__dict__.update(sbp.__dict__)
      self.from_binary(sbp.payload)
    else:
      super( MsgFlashErase, self).__init__()
      self.msg_type = SBP_MSG_FLASH_ERASE
      self.sender = kwargs.pop('sender', 0)
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
    c = containerize(exclude_fields(self))
    self.payload = MsgFlashErase._parser.build(c)
    return self.pack()

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    sbp = SBP.from_json_dict(d)
    return MsgFlashErase(sbp)

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgFlashErase, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    
SBP_MSG_STM_FLASH_LOCK_SECTOR = 0x00E3
class MsgStmFlashLockSector(SBP):
  """SBP class for message MSG_STM_FLASH_LOCK_SECTOR (0x00E3).

  You can have MSG_STM_FLASH_LOCK_SECTOR inherent its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  The flash lock message locks a sector of the STM flash
memory. The device replies with a MSG_FLASH_DONE message.


  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  sector : int
    Flash sector number to lock
  sender : int
    Optional sender ID, defaults to 0

  """
  _parser = Struct("MsgStmFlashLockSector",
                   ULInt32('sector'),)

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      self.__dict__.update(sbp.__dict__)
      self.from_binary(sbp.payload)
    else:
      super( MsgStmFlashLockSector, self).__init__()
      self.msg_type = SBP_MSG_STM_FLASH_LOCK_SECTOR
      self.sender = kwargs.pop('sender', 0)
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
    c = containerize(exclude_fields(self))
    self.payload = MsgStmFlashLockSector._parser.build(c)
    return self.pack()

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    sbp = SBP.from_json_dict(d)
    return MsgStmFlashLockSector(sbp)

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgStmFlashLockSector, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    
SBP_MSG_STM_FLASH_UNLOCK_SECTOR = 0x00E4
class MsgStmFlashUnlockSector(SBP):
  """SBP class for message MSG_STM_FLASH_UNLOCK_SECTOR (0x00E4).

  You can have MSG_STM_FLASH_UNLOCK_SECTOR inherent its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  The flash unlock message unlocks a sector of the STM flash
memory. The device replies with a MSG_FLASH_DONE message.


  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  sector : int
    Flash sector number to unlock
  sender : int
    Optional sender ID, defaults to 0

  """
  _parser = Struct("MsgStmFlashUnlockSector",
                   ULInt32('sector'),)

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      self.__dict__.update(sbp.__dict__)
      self.from_binary(sbp.payload)
    else:
      super( MsgStmFlashUnlockSector, self).__init__()
      self.msg_type = SBP_MSG_STM_FLASH_UNLOCK_SECTOR
      self.sender = kwargs.pop('sender', 0)
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
    c = containerize(exclude_fields(self))
    self.payload = MsgStmFlashUnlockSector._parser.build(c)
    return self.pack()

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    sbp = SBP.from_json_dict(d)
    return MsgStmFlashUnlockSector(sbp)

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgStmFlashUnlockSector, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    
SBP_MSG_STM_UNIQUE_ID_REQUEST = 0x00E8
class MsgStmUniqueIdRequest(SBP):
  """SBP class for message MSG_STM_UNIQUE_ID_REQUEST (0x00E8).

  You can have MSG_STM_UNIQUE_ID_REQUEST inherent its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  This message reads the device's hardcoded unique ID. The host
requests the ID by sending a MSG_STM_UNIQUE_ID_REQUEST. The device
responds with a MSG_STM_UNIQUE_ID_RESPONSE with the 12-byte unique
ID in the payload..


  """

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      self.__dict__.update(sbp.__dict__)
      self.payload = sbp.payload
    else:
      super( MsgStmUniqueIdRequest, self).__init__()
      self.msg_type = SBP_MSG_STM_UNIQUE_ID_REQUEST
      self.sender = kwargs.pop('sender', 0)

  def __repr__(self):
    return fmt_repr(self)
 
    
SBP_MSG_STM_UNIQUE_ID_RESPONSE = 0x00E5
class MsgStmUniqueIdResponse(SBP):
  """SBP class for message MSG_STM_UNIQUE_ID_RESPONSE (0x00E5).

  You can have MSG_STM_UNIQUE_ID_RESPONSE inherent its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  This message reads the device's hardcoded unique ID. The host
requests the ID by sending a MSG_STM_UNIQUE_ID_REQUEST. The device
responds with a MSG_STM_UNIQUE_ID_RESPONSE with the 12-byte unique
ID in the payload..


  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  stm_id : array
    Device unique ID
  sender : int
    Optional sender ID, defaults to 0

  """
  _parser = Struct("MsgStmUniqueIdResponse",
                   Struct('stm_id', Array(12, ULInt8('stm_id'))),)

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      self.__dict__.update(sbp.__dict__)
      self.from_binary(sbp.payload)
    else:
      super( MsgStmUniqueIdResponse, self).__init__()
      self.msg_type = SBP_MSG_STM_UNIQUE_ID_RESPONSE
      self.sender = kwargs.pop('sender', 0)
      self.stm_id = kwargs.pop('stm_id')

  def __repr__(self):
    return fmt_repr(self)
 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgStmUniqueIdResponse._parser.parse(d)
    self.__dict__.update(dict(p.viewitems()))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgStmUniqueIdResponse._parser.build(c)
    return self.pack()

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    sbp = SBP.from_json_dict(d)
    return MsgStmUniqueIdResponse(sbp)

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgStmUniqueIdResponse, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    
SBP_MSG_M25_FLASH_WRITE_STATUS = 0x00F3
class MsgM25FlashWriteStatus(SBP):
  """SBP class for message MSG_M25_FLASH_WRITE_STATUS (0x00F3).

  You can have MSG_M25_FLASH_WRITE_STATUS inherent its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  The flash status message writes to the 8-bit M25 flash status
register. The device replies with a MSG_FLASH_DONE message.


  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  status : array
    Byte to write to the M25 flash status register
  sender : int
    Optional sender ID, defaults to 0

  """
  _parser = Struct("MsgM25FlashWriteStatus",
                   Struct('status', Array(1, ULInt8('status'))),)

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      self.__dict__.update(sbp.__dict__)
      self.from_binary(sbp.payload)
    else:
      super( MsgM25FlashWriteStatus, self).__init__()
      self.msg_type = SBP_MSG_M25_FLASH_WRITE_STATUS
      self.sender = kwargs.pop('sender', 0)
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
    c = containerize(exclude_fields(self))
    self.payload = MsgM25FlashWriteStatus._parser.build(c)
    return self.pack()

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    sbp = SBP.from_json_dict(d)
    return MsgM25FlashWriteStatus(sbp)

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgM25FlashWriteStatus, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    

msg_classes = {
  0x00E6: MsgFlashProgram,
  0x00E0: MsgFlashDone,
  0x00E7: MsgFlashReadRequest,
  0x00E1: MsgFlashReadResponse,
  0x00E2: MsgFlashErase,
  0x00E3: MsgStmFlashLockSector,
  0x00E4: MsgStmFlashUnlockSector,
  0x00E8: MsgStmUniqueIdRequest,
  0x00E5: MsgStmUniqueIdResponse,
  0x00F3: MsgM25FlashWriteStatus,
}