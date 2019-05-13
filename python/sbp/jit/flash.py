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

import numba as nb
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
  def parse_members(self, buf, offset, length):
    dtype = self._static_dtype()
    dlength = length
    if len(dtype):
      dlength -= dtype.itemsize

    if dlength:
      ddtype = self._dynamic_dtype()
      count = dlength // ddtype.itemsize
      dtype = self._static_dtype(count)

    res, offset, length = (np.frombuffer(buf, dtype, 1, offset), offset - length, 0)

    return self._unpack_members(res), offset, length

  @classmethod
  def _static_dtype(cls, count=0):
    if count:
      return np.dtype([
          ('target', 'u1'),
          ('addr_start', ('u1', (3,))),
          ('addr_len', 'u1'),
          ('data', ('u1', (count,))),
        ])

    t = getattr(cls, 'static_dtype0', None)
    if not t:
      t = np.dtype([
          ('target', 'u1'),
          ('addr_start', ('u1', (3,))),
          ('addr_len', 'u1'),
          ('data', ('u1', (count,))),
        ])
      cls.static_dtype0 = t
    return t

  @classmethod
  def _dynamic_dtype(cls):
    t = getattr(cls, 'dynamic_dtype', None)
    if not t:    
      t = np.dtype([('addr_start', 'u1'),])
      cls.dynamic_dtype = t
    return t

  @staticmethod
  def _unpack_members(res, element=False):
    d = {
      'target': int(res['target'] if element else res['target'][0]),
      'addr_start': [] if res['addr_start'] is None else [x.item() for x in res['addr_start'].flatten()],
      'addr_len': int(res['addr_len'] if element else res['addr_len'][0]),
      'data': [] if res['data'] is None else [x.item() for x in res['data'].flatten()],
    }
    return d

  
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
  def parse_members(self, buf, offset, length):
    dtype = self._static_dtype()
    dlength = length
    if len(dtype):
      dlength -= dtype.itemsize

    if dlength:
      ddtype = self._dynamic_dtype()
      count = dlength // ddtype.itemsize
      dtype = self._static_dtype(count)

    res, offset, length = (np.frombuffer(buf, dtype, 1, offset), offset - length, 0)

    return self._unpack_members(res), offset, length

  @classmethod
  def _static_dtype(cls, count=0):
    if count:
      return np.dtype([
          ('response', 'u1'),
        ])

    t = getattr(cls, 'static_dtype0', None)
    if not t:
      t = np.dtype([
          ('response', 'u1'),
        ])
      cls.static_dtype0 = t
    return t

  @classmethod
  def _dynamic_dtype(cls):
    t = getattr(cls, 'dynamic_dtype', None)
    if not t:    
      t = None
      cls.dynamic_dtype = t
    return t

  @staticmethod
  def _unpack_members(res, element=False):
    d = {
      'response': int(res['response'] if element else res['response'][0]),
    }
    return d

  
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
  def parse_members(self, buf, offset, length):
    dtype = self._static_dtype()
    dlength = length
    if len(dtype):
      dlength -= dtype.itemsize

    if dlength:
      ddtype = self._dynamic_dtype()
      count = dlength // ddtype.itemsize
      dtype = self._static_dtype(count)

    res, offset, length = (np.frombuffer(buf, dtype, 1, offset), offset - length, 0)

    return self._unpack_members(res), offset, length

  @classmethod
  def _static_dtype(cls, count=0):
    if count:
      return np.dtype([
          ('target', 'u1'),
          ('addr_start', ('u1', (3,))),
          ('addr_len', 'u1'),
        ])

    t = getattr(cls, 'static_dtype0', None)
    if not t:
      t = np.dtype([
          ('target', 'u1'),
          ('addr_start', ('u1', (3,))),
          ('addr_len', 'u1'),
        ])
      cls.static_dtype0 = t
    return t

  @classmethod
  def _dynamic_dtype(cls):
    t = getattr(cls, 'dynamic_dtype', None)
    if not t:    
      t = np.dtype([('addr_start', 'u1'),])
      cls.dynamic_dtype = t
    return t

  @staticmethod
  def _unpack_members(res, element=False):
    d = {
      'target': int(res['target'] if element else res['target'][0]),
      'addr_start': [] if res['addr_start'] is None else [x.item() for x in res['addr_start'].flatten()],
      'addr_len': int(res['addr_len'] if element else res['addr_len'][0]),
    }
    return d

  
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
  def parse_members(self, buf, offset, length):
    dtype = self._static_dtype()
    dlength = length
    if len(dtype):
      dlength -= dtype.itemsize

    if dlength:
      ddtype = self._dynamic_dtype()
      count = dlength // ddtype.itemsize
      dtype = self._static_dtype(count)

    res, offset, length = (np.frombuffer(buf, dtype, 1, offset), offset - length, 0)

    return self._unpack_members(res), offset, length

  @classmethod
  def _static_dtype(cls, count=0):
    if count:
      return np.dtype([
          ('target', 'u1'),
          ('addr_start', ('u1', (3,))),
          ('addr_len', 'u1'),
        ])

    t = getattr(cls, 'static_dtype0', None)
    if not t:
      t = np.dtype([
          ('target', 'u1'),
          ('addr_start', ('u1', (3,))),
          ('addr_len', 'u1'),
        ])
      cls.static_dtype0 = t
    return t

  @classmethod
  def _dynamic_dtype(cls):
    t = getattr(cls, 'dynamic_dtype', None)
    if not t:    
      t = np.dtype([('addr_start', 'u1'),])
      cls.dynamic_dtype = t
    return t

  @staticmethod
  def _unpack_members(res, element=False):
    d = {
      'target': int(res['target'] if element else res['target'][0]),
      'addr_start': [] if res['addr_start'] is None else [x.item() for x in res['addr_start'].flatten()],
      'addr_len': int(res['addr_len'] if element else res['addr_len'][0]),
    }
    return d

  
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
  def parse_members(self, buf, offset, length):
    dtype = self._static_dtype()
    dlength = length
    if len(dtype):
      dlength -= dtype.itemsize

    if dlength:
      ddtype = self._dynamic_dtype()
      count = dlength // ddtype.itemsize
      dtype = self._static_dtype(count)

    res, offset, length = (np.frombuffer(buf, dtype, 1, offset), offset - length, 0)

    return self._unpack_members(res), offset, length

  @classmethod
  def _static_dtype(cls, count=0):
    if count:
      return np.dtype([
          ('target', 'u1'),
          ('sector_num', 'u4'),
        ])

    t = getattr(cls, 'static_dtype0', None)
    if not t:
      t = np.dtype([
          ('target', 'u1'),
          ('sector_num', 'u4'),
        ])
      cls.static_dtype0 = t
    return t

  @classmethod
  def _dynamic_dtype(cls):
    t = getattr(cls, 'dynamic_dtype', None)
    if not t:    
      t = None
      cls.dynamic_dtype = t
    return t

  @staticmethod
  def _unpack_members(res, element=False):
    d = {
      'target': int(res['target'] if element else res['target'][0]),
      'sector_num': int(res['sector_num'] if element else res['sector_num'][0]),
    }
    return d

  
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
  def parse_members(self, buf, offset, length):
    dtype = self._static_dtype()
    dlength = length
    if len(dtype):
      dlength -= dtype.itemsize

    if dlength:
      ddtype = self._dynamic_dtype()
      count = dlength // ddtype.itemsize
      dtype = self._static_dtype(count)

    res, offset, length = (np.frombuffer(buf, dtype, 1, offset), offset - length, 0)

    return self._unpack_members(res), offset, length

  @classmethod
  def _static_dtype(cls, count=0):
    if count:
      return np.dtype([
          ('sector', 'u4'),
        ])

    t = getattr(cls, 'static_dtype0', None)
    if not t:
      t = np.dtype([
          ('sector', 'u4'),
        ])
      cls.static_dtype0 = t
    return t

  @classmethod
  def _dynamic_dtype(cls):
    t = getattr(cls, 'dynamic_dtype', None)
    if not t:    
      t = None
      cls.dynamic_dtype = t
    return t

  @staticmethod
  def _unpack_members(res, element=False):
    d = {
      'sector': int(res['sector'] if element else res['sector'][0]),
    }
    return d

  
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
  def parse_members(self, buf, offset, length):
    dtype = self._static_dtype()
    dlength = length
    if len(dtype):
      dlength -= dtype.itemsize

    if dlength:
      ddtype = self._dynamic_dtype()
      count = dlength // ddtype.itemsize
      dtype = self._static_dtype(count)

    res, offset, length = (np.frombuffer(buf, dtype, 1, offset), offset - length, 0)

    return self._unpack_members(res), offset, length

  @classmethod
  def _static_dtype(cls, count=0):
    if count:
      return np.dtype([
          ('sector', 'u4'),
        ])

    t = getattr(cls, 'static_dtype0', None)
    if not t:
      t = np.dtype([
          ('sector', 'u4'),
        ])
      cls.static_dtype0 = t
    return t

  @classmethod
  def _dynamic_dtype(cls):
    t = getattr(cls, 'dynamic_dtype', None)
    if not t:    
      t = None
      cls.dynamic_dtype = t
    return t

  @staticmethod
  def _unpack_members(res, element=False):
    d = {
      'sector': int(res['sector'] if element else res['sector'][0]),
    }
    return d

  
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

  def parse_members(self, buf, offset, length):
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
  def parse_members(self, buf, offset, length):
    dtype = self._static_dtype()
    dlength = length
    if len(dtype):
      dlength -= dtype.itemsize

    if dlength:
      ddtype = self._dynamic_dtype()
      count = dlength // ddtype.itemsize
      dtype = self._static_dtype(count)

    res, offset, length = (np.frombuffer(buf, dtype, 1, offset), offset - length, 0)

    return self._unpack_members(res), offset, length

  @classmethod
  def _static_dtype(cls, count=0):
    if count:
      return np.dtype([
          ('stm_id', ('u1', (12,))),
        ])

    t = getattr(cls, 'static_dtype0', None)
    if not t:
      t = np.dtype([
          ('stm_id', ('u1', (12,))),
        ])
      cls.static_dtype0 = t
    return t

  @classmethod
  def _dynamic_dtype(cls):
    t = getattr(cls, 'dynamic_dtype', None)
    if not t:    
      t = np.dtype([('stm_id', 'u1'),])
      cls.dynamic_dtype = t
    return t

  @staticmethod
  def _unpack_members(res, element=False):
    d = {
      'stm_id': [] if res['stm_id'] is None else [x.item() for x in res['stm_id'].flatten()],
    }
    return d

  
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
  def parse_members(self, buf, offset, length):
    dtype = self._static_dtype()
    dlength = length
    if len(dtype):
      dlength -= dtype.itemsize

    if dlength:
      ddtype = self._dynamic_dtype()
      count = dlength // ddtype.itemsize
      dtype = self._static_dtype(count)

    res, offset, length = (np.frombuffer(buf, dtype, 1, offset), offset - length, 0)

    return self._unpack_members(res), offset, length

  @classmethod
  def _static_dtype(cls, count=0):
    if count:
      return np.dtype([
          ('status', ('u1', (1,))),
        ])

    t = getattr(cls, 'static_dtype0', None)
    if not t:
      t = np.dtype([
          ('status', ('u1', (1,))),
        ])
      cls.static_dtype0 = t
    return t

  @classmethod
  def _dynamic_dtype(cls):
    t = getattr(cls, 'dynamic_dtype', None)
    if not t:    
      t = np.dtype([('status', 'u1'),])
      cls.dynamic_dtype = t
    return t

  @staticmethod
  def _unpack_members(res, element=False):
    d = {
      'status': [] if res['status'] is None else [x.item() for x in res['status'].flatten()],
    }
    return d

  

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