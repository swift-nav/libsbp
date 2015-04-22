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
from sbp import SBP
from sbp.utils import fmt_repr, exclude_fields, walk_json_dict, containerize
import six

# Automatically generated from piksi/yaml/swiftnav/sbp/bootload.yaml with generate.py.
# Please do not hand edit!


SBP_MSG_BOOTLOADER_HANDSHAKE = 0x00B0
class MsgBootloaderHandshake(SBP):
  """SBP class for message MSG_BOOTLOADER_HANDSHAKE (0x00B0).

  You can have MSG_BOOTLOADER_HANDSHAKE inherent its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  The handshake message establishes a handshake between the device
bootloader and the host.  The payload string contains the
bootloader version number, but returns an empty string for
earlier versions.


  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  handshake : array
    Version number string (not NULL terminated)
  sender : int
    Optional sender ID, defaults to 0

  """
  _parser = Struct("MsgBootloaderHandshake",
                   OptionalGreedyRange(ULInt8('handshake')),)

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      self.__dict__.update(sbp.__dict__)
      self.from_binary(sbp.payload)
    else:
      super( MsgBootloaderHandshake, self).__init__()
      self.msg_type = SBP_MSG_BOOTLOADER_HANDSHAKE
      self.sender = kwargs.pop('sender', 0)
      self.handshake = kwargs.pop('handshake')

  def __repr__(self):
    return fmt_repr(self)
 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgBootloaderHandshake._parser.parse(d)
    self.__dict__.update(dict(p.viewitems()))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgBootloaderHandshake._parser.build(c)
    return self.pack()

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    sbp = SBP.from_json_dict(d)
    return MsgBootloaderHandshake(sbp)

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgBootloaderHandshake, self).to_json_dict()
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
    
SBP_MSG_NAP_DEVICE_DNA = 0x00DD
class MsgNapDeviceDna(SBP):
  """SBP class for message MSG_NAP_DEVICE_DNA (0x00DD).

  You can have MSG_NAP_DEVICE_DNA inherent its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  The device message from the host reads a unique device
identifier from the SwiftNAP, an FPGA. The host requests the ID
by sending a MSG_NAP_DEVICE_DNA with an empty payload. The
device responds with the same message with the device ID in the
payload. Note that this ID is tied to the FPGA, and not related
to the Piksi's serial number.


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
  _parser = Struct("MsgNapDeviceDna",
                   Struct('dna', Array(8, ULInt8('dna'))),)

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      self.__dict__.update(sbp.__dict__)
      self.from_binary(sbp.payload)
    else:
      super( MsgNapDeviceDna, self).__init__()
      self.msg_type = SBP_MSG_NAP_DEVICE_DNA
      self.sender = kwargs.pop('sender', 0)
      self.dna = kwargs.pop('dna')

  def __repr__(self):
    return fmt_repr(self)
 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgNapDeviceDna._parser.parse(d)
    self.__dict__.update(dict(p.viewitems()))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgNapDeviceDna._parser.build(c)
    return self.pack()

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    sbp = SBP.from_json_dict(d)
    return MsgNapDeviceDna(sbp)

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgNapDeviceDna, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    

msg_classes = {
  0x00B0: MsgBootloaderHandshake,
  0x00B1: MsgBootloaderJumpToApp,
  0x00DD: MsgNapDeviceDna,
}