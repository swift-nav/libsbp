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
Messages for the bootloading configuration on the device.

These are in the implementation-defined range (0x0000-0x00FF), and
are intended for internal use only. Note that some of these messages
share the same message type ID for both the host request and the
device response.

"""

from construct import *
import json
from sbp.msg import SBP
from sbp.utils import fmt_repr, exclude_fields, walk_json_dict, containerize
import six

# Automatically generated from piksi/yaml/swiftnav/sbp/bootload.yaml with generate.py.
# Please do not hand edit!


SBP_MSG_BOOTLOADER_HANDSHAKE_HOST = 0x00B3
class MsgBootloaderHandshakeHost(SBP):
  """SBP class for message MSG_BOOTLOADER_HANDSHAKE_HOST (0x00B3).

  You can have MSG_BOOTLOADER_HANDSHAKE_HOST inherent its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  The handshake message request from the host establishes a
handshake between the device bootloader and the host. The
response from the device is MSG_BOOTLOADER_HANDSHAKE_DEVICE.


  """

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      self.__dict__.update(sbp.__dict__)
      self.payload = sbp.payload
    else:
      super( MsgBootloaderHandshakeHost, self).__init__()
      self.msg_type = SBP_MSG_BOOTLOADER_HANDSHAKE_HOST
      self.sender = kwargs.pop('sender', 0)

  def __repr__(self):
    return fmt_repr(self)
 
    
SBP_MSG_BOOTLOADER_HANDSHAKE_DEVICE = 0x00B4
class MsgBootloaderHandshakeDevice(SBP):
  """SBP class for message MSG_BOOTLOADER_HANDSHAKE_DEVICE (0x00B4).

  You can have MSG_BOOTLOADER_HANDSHAKE_DEVICE inherent its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  The handshake message response from the device establishes a
handshake between the device bootloader and the host. The
request from the host is MSG_BOOTLOADER_HANDSHAKE_HOST.  The
payload contains the bootloader version number and the SBP
protocol version number.


  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  flags : int
    Bootloader flags
  version : string
    Bootloader version number
  sender : int
    Optional sender ID, defaults to 0

  """
  _parser = Struct("MsgBootloaderHandshakeDevice",
                   ULInt32('flags'),
                   CString('version', six.b('\n')),)

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      self.__dict__.update(sbp.__dict__)
      self.from_binary(sbp.payload)
    else:
      super( MsgBootloaderHandshakeDevice, self).__init__()
      self.msg_type = SBP_MSG_BOOTLOADER_HANDSHAKE_DEVICE
      self.sender = kwargs.pop('sender', 0)
      self.flags = kwargs.pop('flags')
      self.version = kwargs.pop('version')

  def __repr__(self):
    return fmt_repr(self)
 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgBootloaderHandshakeDevice._parser.parse(d)
    self.__dict__.update(dict(p.viewitems()))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgBootloaderHandshakeDevice._parser.build(c)
    return self.pack()

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    sbp = SBP.from_json_dict(d)
    return MsgBootloaderHandshakeDevice(sbp)

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgBootloaderHandshakeDevice, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    
SBP_MSG_BOOTLOADER_JUMP_TO_APP = 0x00B1
class MsgBootloaderJumpToApp(SBP):
  """SBP class for message MSG_BOOTLOADER_JUMP_TO_APP (0x00B1).

  You can have MSG_BOOTLOADER_JUMP_TO_APP inherent its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  The host initiates the bootloader to jump to the application.


  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  jump : int
    Ignored by the device
  sender : int
    Optional sender ID, defaults to 0

  """
  _parser = Struct("MsgBootloaderJumpToApp",
                   ULInt8('jump'),)

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      self.__dict__.update(sbp.__dict__)
      self.from_binary(sbp.payload)
    else:
      super( MsgBootloaderJumpToApp, self).__init__()
      self.msg_type = SBP_MSG_BOOTLOADER_JUMP_TO_APP
      self.sender = kwargs.pop('sender', 0)
      self.jump = kwargs.pop('jump')

  def __repr__(self):
    return fmt_repr(self)
 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgBootloaderJumpToApp._parser.parse(d)
    self.__dict__.update(dict(p.viewitems()))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgBootloaderJumpToApp._parser.build(c)
    return self.pack()

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    sbp = SBP.from_json_dict(d)
    return MsgBootloaderJumpToApp(sbp)

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgBootloaderJumpToApp, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    
SBP_MSG_NAP_DEVICE_DNA_HOST = 0x00DE
class MsgNapDeviceDnaHost(SBP):
  """SBP class for message MSG_NAP_DEVICE_DNA_HOST (0x00DE).

  You can have MSG_NAP_DEVICE_DNA_HOST inherent its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  The device message from the host reads a unique device
identifier from the SwiftNAP, an FPGA. The host requests the ID
by sending a MSG_NAP_DEVICE_DNA_HOST message. The device
responds with a MSG_NAP_DEVICE_DNA_DEVICE message with the
device ID in the payload. Note that this ID is tied to the FPGA,
and not related to the Piksi's serial number.


  """

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      self.__dict__.update(sbp.__dict__)
      self.payload = sbp.payload
    else:
      super( MsgNapDeviceDnaHost, self).__init__()
      self.msg_type = SBP_MSG_NAP_DEVICE_DNA_HOST
      self.sender = kwargs.pop('sender', 0)

  def __repr__(self):
    return fmt_repr(self)
 
    
SBP_MSG_NAP_DEVICE_DNA_DEVICE = 0x00DD
class MsgNapDeviceDnaDevice(SBP):
  """SBP class for message MSG_NAP_DEVICE_DNA_DEVICE (0x00DD).

  You can have MSG_NAP_DEVICE_DNA_DEVICE inherent its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  The device message from the host reads a unique device
identifier from the SwiftNAP, an FPGA. The host requests the ID
by sending a MSG_NAP_DEVICE_DNA_HOST message. The device
responds with a MSG_NAP_DEVICE_DNA_DEVICE messagage with the
device ID in the payload. Note that this ID is tied to the FPGA,
and not related to the Piksi's serial number.


  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  dna : array
    57-bit SwiftNAP FPGA Device ID. Remaining bits are padded
on the right.

  sender : int
    Optional sender ID, defaults to 0

  """
  _parser = Struct("MsgNapDeviceDnaDevice",
                   Struct('dna', Array(8, ULInt8('dna'))),)

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      self.__dict__.update(sbp.__dict__)
      self.from_binary(sbp.payload)
    else:
      super( MsgNapDeviceDnaDevice, self).__init__()
      self.msg_type = SBP_MSG_NAP_DEVICE_DNA_DEVICE
      self.sender = kwargs.pop('sender', 0)
      self.dna = kwargs.pop('dna')

  def __repr__(self):
    return fmt_repr(self)
 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgNapDeviceDnaDevice._parser.parse(d)
    self.__dict__.update(dict(p.viewitems()))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgNapDeviceDnaDevice._parser.build(c)
    return self.pack()

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    sbp = SBP.from_json_dict(d)
    return MsgNapDeviceDnaDevice(sbp)

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgNapDeviceDnaDevice, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    

msg_classes = {
  0x00B3: MsgBootloaderHandshakeHost,
  0x00B4: MsgBootloaderHandshakeDevice,
  0x00B1: MsgBootloaderJumpToApp,
  0x00DE: MsgNapDeviceDnaHost,
  0x00DD: MsgNapDeviceDnaDevice,
}