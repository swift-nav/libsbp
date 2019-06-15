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

import construct

from sbp.msg import SBP, SENDER_ID
from sbp.utils import fmt_repr, exclude_fields, walk_json_dict, containerize

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

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      super( MsgBootloaderHandshakeReq,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.payload = sbp.payload
    else:
      super( MsgBootloaderHandshakeReq, self).__init__()
      self.msg_type = SBP_MSG_BOOTLOADER_HANDSHAKE_REQ
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.payload = b""

  def __repr__(self):
    return fmt_repr(self)

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    return MsgBootloaderHandshakeReq.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgBootloaderHandshakeReq(sbp, **d)

 
    
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


  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  flags : int
    Bootloader flags
  version : string
    Bootloader version number
  sender : int
    Optional sender ID, defaults to SENDER_ID (see sbp/msg.py).

  """
  _parser = construct.Struct(
                   'flags' / construct.Int32ul,
                   'version' / construct.GreedyBytes,)
  __slots__ = [
               'flags',
               'version',
              ]

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      super( MsgBootloaderHandshakeResp,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.from_binary(sbp.payload)
    else:
      super( MsgBootloaderHandshakeResp, self).__init__()
      self.msg_type = SBP_MSG_BOOTLOADER_HANDSHAKE_RESP
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.flags = kwargs.pop('flags')
      self.version = kwargs.pop('version')

  def __repr__(self):
    return fmt_repr(self)

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    return MsgBootloaderHandshakeResp.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgBootloaderHandshakeResp(sbp, **d)

 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgBootloaderHandshakeResp._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgBootloaderHandshakeResp._parser.build(c)
    return self.pack()

  def into_buffer(self, buf, offset):
    """Produce a framed/packed SBP message into the provided buffer and offset.

    """
    self.payload = containerize(exclude_fields(self))
    self.parser = MsgBootloaderHandshakeResp._parser
    self.stream_payload.reset(buf, offset)
    return self.pack_into(buf, offset, self._build_payload)

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgBootloaderHandshakeResp, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    
SBP_MSG_BOOTLOADER_JUMP_TO_APP = 0x00B1
class MsgBootloaderJumpToApp(SBP):
  """SBP class for message MSG_BOOTLOADER_JUMP_TO_APP (0x00B1).

  You can have MSG_BOOTLOADER_JUMP_TO_APP inherit its fields directly
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
    Optional sender ID, defaults to SENDER_ID (see sbp/msg.py).

  """
  _parser = construct.Struct(
                   'jump' / construct.Int8ul,)
  __slots__ = [
               'jump',
              ]

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      super( MsgBootloaderJumpToApp,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.from_binary(sbp.payload)
    else:
      super( MsgBootloaderJumpToApp, self).__init__()
      self.msg_type = SBP_MSG_BOOTLOADER_JUMP_TO_APP
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.jump = kwargs.pop('jump')

  def __repr__(self):
    return fmt_repr(self)

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    return MsgBootloaderJumpToApp.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgBootloaderJumpToApp(sbp, **d)

 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgBootloaderJumpToApp._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgBootloaderJumpToApp._parser.build(c)
    return self.pack()

  def into_buffer(self, buf, offset):
    """Produce a framed/packed SBP message into the provided buffer and offset.

    """
    self.payload = containerize(exclude_fields(self))
    self.parser = MsgBootloaderJumpToApp._parser
    self.stream_payload.reset(buf, offset)
    return self.pack_into(buf, offset, self._build_payload)

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgBootloaderJumpToApp, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
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

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      super( MsgNapDeviceDnaReq,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.payload = sbp.payload
    else:
      super( MsgNapDeviceDnaReq, self).__init__()
      self.msg_type = SBP_MSG_NAP_DEVICE_DNA_REQ
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.payload = b""

  def __repr__(self):
    return fmt_repr(self)

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    return MsgNapDeviceDnaReq.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgNapDeviceDnaReq(sbp, **d)

 
    
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


  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  dna : array
    57-bit SwiftNAP FPGA Device ID. Remaining bits are padded
on the right.

  sender : int
    Optional sender ID, defaults to SENDER_ID (see sbp/msg.py).

  """
  _parser = construct.Struct(
                   'dna' / construct.Array(8, construct.Int8ul),)
  __slots__ = [
               'dna',
              ]

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      super( MsgNapDeviceDnaResp,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.from_binary(sbp.payload)
    else:
      super( MsgNapDeviceDnaResp, self).__init__()
      self.msg_type = SBP_MSG_NAP_DEVICE_DNA_RESP
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.dna = kwargs.pop('dna')

  def __repr__(self):
    return fmt_repr(self)

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    return MsgNapDeviceDnaResp.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgNapDeviceDnaResp(sbp, **d)

 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgNapDeviceDnaResp._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgNapDeviceDnaResp._parser.build(c)
    return self.pack()

  def into_buffer(self, buf, offset):
    """Produce a framed/packed SBP message into the provided buffer and offset.

    """
    self.payload = containerize(exclude_fields(self))
    self.parser = MsgNapDeviceDnaResp._parser
    self.stream_payload.reset(buf, offset)
    return self.pack_into(buf, offset, self._build_payload)

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgNapDeviceDnaResp, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    
SBP_MSG_BOOTLOADER_HANDSHAKE_DEP_A = 0x00B0
class MsgBootloaderHandshakeDepA(SBP):
  """SBP class for message MSG_BOOTLOADER_HANDSHAKE_DEP_A (0x00B0).

  You can have MSG_BOOTLOADER_HANDSHAKE_DEP_A inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  Deprecated.

  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  handshake : array
    Version number string (not NULL terminated)
  sender : int
    Optional sender ID, defaults to SENDER_ID (see sbp/msg.py).

  """
  _parser = construct.Struct(
                   construct.GreedyRange('handshake' / construct.Int8ul),)
  __slots__ = [
               'handshake',
              ]

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      super( MsgBootloaderHandshakeDepA,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.from_binary(sbp.payload)
    else:
      super( MsgBootloaderHandshakeDepA, self).__init__()
      self.msg_type = SBP_MSG_BOOTLOADER_HANDSHAKE_DEP_A
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.handshake = kwargs.pop('handshake')

  def __repr__(self):
    return fmt_repr(self)

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    return MsgBootloaderHandshakeDepA.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgBootloaderHandshakeDepA(sbp, **d)

 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgBootloaderHandshakeDepA._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgBootloaderHandshakeDepA._parser.build(c)
    return self.pack()

  def into_buffer(self, buf, offset):
    """Produce a framed/packed SBP message into the provided buffer and offset.

    """
    self.payload = containerize(exclude_fields(self))
    self.parser = MsgBootloaderHandshakeDepA._parser
    self.stream_payload.reset(buf, offset)
    return self.pack_into(buf, offset, self._build_payload)

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgBootloaderHandshakeDepA, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    

msg_classes = {
  0x00B3: MsgBootloaderHandshakeReq,
  0x00B4: MsgBootloaderHandshakeResp,
  0x00B1: MsgBootloaderJumpToApp,
  0x00DE: MsgNapDeviceDnaReq,
  0x00DD: MsgNapDeviceDnaResp,
  0x00B0: MsgBootloaderHandshakeDepA,
}