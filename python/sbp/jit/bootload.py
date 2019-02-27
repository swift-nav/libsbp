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

from sbp.jit.msg import SBP, SENDER_ID
from sbp.jit.msg import get_u8, get_u16, get_u32, get_u64
from sbp.jit.msg import get_s8, get_s16, get_s32, get_s64
from sbp.jit.msg import get_f32, get_f64
from sbp.jit.msg import get_string, get_fixed_string
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
  @classmethod
  def parse_members(cls, buf, offset, length):
    o_0 = offset
    o_1, (__flags, offset, length) = offset, get_u32(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__version, offset, length) = offset, get_string(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    return {
      'flags' : __flags,
      'version' : __version,
    }, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.flags = res['flags']
    self.version = res['version']
    return res, off, length
  
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
  @classmethod
  def parse_members(cls, buf, offset, length):
    o_0 = offset
    o_1, (__jump, offset, length) = offset, get_u8(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    return {
      'jump' : __jump,
    }, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.jump = res['jump']
    return res, off, length
  
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
  @classmethod
  def parse_members(cls, buf, offset, length):
    o_0 = offset
    o_1, (__dna, offset, length) = offset, get_fixed_array(get_u8, 8, 1)(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    return {
      'dna' : __dna,
    }, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.dna = res['dna']
    return res, off, length
  
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
  @classmethod
  def parse_members(cls, buf, offset, length):
    o_0 = offset
    o_1, (__handshake, offset, length) = offset, get_array(get_u8)(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    return {
      'handshake' : __handshake,
    }, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.handshake = res['handshake']
    return res, off, length
  

msg_classes = {
  0x00B3: MsgBootloaderHandshakeReq,
  0x00B4: MsgBootloaderHandshakeResp,
  0x00B1: MsgBootloaderJumpToApp,
  0x00DE: MsgNapDeviceDnaReq,
  0x00DD: MsgNapDeviceDnaResp,
  0x00B0: MsgBootloaderHandshakeDepA,
}