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
Messages for the bootloading configuration of a Piksi 2.3.1.  This message
group does not apply to Piksi Multi.

Note that some of these messages share the same message type ID for both the
host request and the device response.

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

# Automatically generated from piksi/yaml/swiftnav/sbp/bootload.yaml with generate.py.
# Please do not hand edit!
SBP_MSG_BOOTLOADER_HANDSHAKE_REQ = 0x00B3
class MsgBootloaderHandshakeReq(SBP):
  """SBP class for message MSG_BOOTLOADER_HANDSHAKE_REQ (0x00B3).

  You can have MSG_BOOTLOADER_HANDSHAKE_REQ inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  The handshake message request from the host establishes a
handshake between the device bootloader and the host. The
response from the device is MSG_BOOTLOADER_HANDSHAKE_RESP.


  """
  __slots__ = []
  def _unpack_members(self, buf, offset, length):
    return {}, offset, length

  def parse_members(self, buf, offset, length):
    return {}, offset, length

  def _payload_size(self):
    return 0
  
SBP_MSG_BOOTLOADER_HANDSHAKE_RESP = 0x00B4
class MsgBootloaderHandshakeResp(SBP):
  """SBP class for message MSG_BOOTLOADER_HANDSHAKE_RESP (0x00B4).

  You can have MSG_BOOTLOADER_HANDSHAKE_RESP inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  The handshake message response from the device establishes a
handshake between the device bootloader and the host. The
request from the host is MSG_BOOTLOADER_HANDSHAKE_REQ.  The
payload contains the bootloader version number and the SBP
protocol version number.


  """
  __slots__ = ['flags',
               'version',
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
          ('flags', 'u4'),
          ('version', '|S{}'.format(count)),
        ])

    t = getattr(cls, 'static_dtype0', None)
    if not t:
      t = np.dtype([
          ('flags', 'u4'),
          ('version', '|S{}'.format(count)),
        ])
      cls.static_dtype0 = t
    return t

  @classmethod
  def _dynamic_dtype(cls):
    t = getattr(cls, 'dynamic_dtype', None)
    if not t:    
      t = np.dtype('u1')
      cls.dynamic_dtype = t
    return t

  @staticmethod
  def _unpack_members(res, element=False):
    d = {
      'flags': int(res['flags'] if element else res['flags'][0]),
      'version': '' if res['version'] is None else res['version'].tostring().decode('ascii'),
    }
    return d

  
SBP_MSG_BOOTLOADER_JUMP_TO_APP = 0x00B1
class MsgBootloaderJumpToApp(SBP):
  """SBP class for message MSG_BOOTLOADER_JUMP_TO_APP (0x00B1).

  You can have MSG_BOOTLOADER_JUMP_TO_APP inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  The host initiates the bootloader to jump to the application.


  """
  __slots__ = ['jump',
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
          ('jump', 'u1'),
        ])

    t = getattr(cls, 'static_dtype0', None)
    if not t:
      t = np.dtype([
          ('jump', 'u1'),
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
      'jump': int(res['jump'] if element else res['jump'][0]),
    }
    return d

  
SBP_MSG_NAP_DEVICE_DNA_REQ = 0x00DE
class MsgNapDeviceDnaReq(SBP):
  """SBP class for message MSG_NAP_DEVICE_DNA_REQ (0x00DE).

  You can have MSG_NAP_DEVICE_DNA_REQ inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  The device message from the host reads a unique device
identifier from the SwiftNAP, an FPGA. The host requests the ID
by sending a MSG_NAP_DEVICE_DNA_REQ message. The device
responds with a MSG_NAP_DEVICE_DNA_RESP message with the
device ID in the payload. Note that this ID is tied to the FPGA,
and not related to the Piksi's serial number.


  """
  __slots__ = []
  def _unpack_members(self, buf, offset, length):
    return {}, offset, length

  def parse_members(self, buf, offset, length):
    return {}, offset, length

  def _payload_size(self):
    return 0
  
SBP_MSG_NAP_DEVICE_DNA_RESP = 0x00DD
class MsgNapDeviceDnaResp(SBP):
  """SBP class for message MSG_NAP_DEVICE_DNA_RESP (0x00DD).

  You can have MSG_NAP_DEVICE_DNA_RESP inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  The device message from the host reads a unique device
identifier from the SwiftNAP, an FPGA. The host requests the ID
by sending a MSG_NAP_DEVICE_DNA_REQ message. The device
responds with a MSG_NAP_DEVICE_DNA_RESP messagage with the
device ID in the payload. Note that this ID is tied to the FPGA,
and not related to the Piksi's serial number.


  """
  __slots__ = ['dna',
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
          ('dna', ('u1', (8,))),
        ])

    t = getattr(cls, 'static_dtype0', None)
    if not t:
      t = np.dtype([
          ('dna', ('u1', (8,))),
        ])
      cls.static_dtype0 = t
    return t

  @classmethod
  def _dynamic_dtype(cls):
    t = getattr(cls, 'dynamic_dtype', None)
    if not t:    
      t = np.dtype([('dna', 'u1'),])
      cls.dynamic_dtype = t
    return t

  @staticmethod
  def _unpack_members(res, element=False):
    d = {
      'dna': [] if res['dna'] is None else [x.item() for x in res['dna'].flatten()],
    }
    return d

  
SBP_MSG_BOOTLOADER_HANDSHAKE_DEP_A = 0x00B0
class MsgBootloaderHandshakeDepA(SBP):
  """SBP class for message MSG_BOOTLOADER_HANDSHAKE_DEP_A (0x00B0).

  You can have MSG_BOOTLOADER_HANDSHAKE_DEP_A inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  Deprecated.

  """
  __slots__ = ['handshake',
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
          ('handshake', ('u1', (count,))),
        ])

    t = getattr(cls, 'static_dtype0', None)
    if not t:
      t = np.dtype([
          ('handshake', ('u1', (count,))),
        ])
      cls.static_dtype0 = t
    return t

  @classmethod
  def _dynamic_dtype(cls):
    t = getattr(cls, 'dynamic_dtype', None)
    if not t:    
      t = np.dtype([('handshake', 'u1'),])
      cls.dynamic_dtype = t
    return t

  @staticmethod
  def _unpack_members(res, element=False):
    d = {
      'handshake': [] if res['handshake'] is None else [x.item() for x in res['handshake'].flatten()],
    }
    return d

  

msg_classes = {
  0x00B3: MsgBootloaderHandshakeReq,
  0x00B4: MsgBootloaderHandshakeResp,
  0x00B1: MsgBootloaderJumpToApp,
  0x00DE: MsgNapDeviceDnaReq,
  0x00DD: MsgNapDeviceDnaResp,
  0x00B0: MsgBootloaderHandshakeDepA,
}