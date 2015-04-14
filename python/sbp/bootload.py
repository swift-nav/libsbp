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
Messages for the bootloading configuration on the Piksi. These are
in the implementation-defined range (0x0000-0x00FF), and intended
for internal-use only. Note that some of these messages taking a
request from a host and a response from the Piksi share the same
message type ID.

"""

from construct import *
import json
from sbp import SBP
from sbp.utils import fmt_repr, exclude_fields, walk_json_dict
import six

# Automatically generated from piksi/yaml/swiftnav/sbp/bootload.yaml
# with generate.py at 2015-04-14 12:12:07.029893. Please do not hand edit!


SBP_MSG_BOOTLOADER_HANDSHAKE = 0x00B0
class MsgBootloaderHandshake(SBP):
  """SBP class for message MSG_BOOTLOADER_HANDSHAKE (0x00B0).

  You can have MSG_BOOTLOADER_HANDSHAKE inherent its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  The bootloader continually sends a handshake message to the host
for a short period of time, and then jumps to the firmware if it
doesn't receive a handshake from the host. If the host replies
with a handshake the bootloader doesn't jump to the firmware and
nwaits for flash programming messages, and the host has to send
a MSG_BOOTLOADER_JUMP_TO_APP when it's done programming. On old
versions of the bootloader (less than v0.1), hardcoded to 0. On
new versions, return the git describe string for the bootloader
build.


  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  handshake : int
    Handshake value

  """
  _parser = Struct("MsgBootloaderHandshake",
                   ULInt8('handshake'),)

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      self.__dict__.update(sbp.__dict__)
      self.from_binary(sbp.payload)
    else:
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
    c = Container(**exclude_fields(self))
    self.payload = MsgBootloaderHandshake._parser.build(c)
    return self.pack()

  def to_json(self):
    """Produce a JSON-encoded SBP message.

    """
    d = super( MsgBootloaderHandshake, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return json.dumps(d)

  @staticmethod
  def from_json(data):
    """Given a JSON-encoded message, build an object.

    """
    d = json.loads(data)
    sbp = SBP.from_json_dict(d)
    return MsgBootloaderHandshake(sbp)
    
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
    Ignored by the Piksi

  """
  _parser = Struct("MsgBootloaderJumpToApp",
                   ULInt8('jump'),)

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      self.__dict__.update(sbp.__dict__)
      self.from_binary(sbp.payload)
    else:
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
    c = Container(**exclude_fields(self))
    self.payload = MsgBootloaderJumpToApp._parser.build(c)
    return self.pack()

  def to_json(self):
    """Produce a JSON-encoded SBP message.

    """
    d = super( MsgBootloaderJumpToApp, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return json.dumps(d)

  @staticmethod
  def from_json(data):
    """Given a JSON-encoded message, build an object.

    """
    d = json.loads(data)
    sbp = SBP.from_json_dict(d)
    return MsgBootloaderJumpToApp(sbp)
    
SBP_MSG_NAP_DEVICE_DNA = 0x00DD
class MsgNapDeviceDna(SBP):
  """SBP class for message MSG_NAP_DEVICE_DNA (0x00DD).

  You can have MSG_NAP_DEVICE_DNA inherent its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  The device DNA message from the host reads the unique device
DNA from the Swift Navigation Acceleration Peripheral
(SwiftNAP), a Spartan 6 FPGA. By convention, the host message
buffer is empty; the Piksi returns the device DNA in a
MSG_NAP_DEVICE_DNA message.


  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  dna : array
    57-bit SwiftNAP FPGA Device DNA

  """
  _parser = Struct("MsgNapDeviceDna",
                   Struct('dna', Array(8, ULInt8('dna'))),)

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      self.__dict__.update(sbp.__dict__)
      self.from_binary(sbp.payload)
    else:
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
    c = Container(**exclude_fields(self))
    self.payload = MsgNapDeviceDna._parser.build(c)
    return self.pack()

  def to_json(self):
    """Produce a JSON-encoded SBP message.

    """
    d = super( MsgNapDeviceDna, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return json.dumps(d)

  @staticmethod
  def from_json(data):
    """Given a JSON-encoded message, build an object.

    """
    d = json.loads(data)
    sbp = SBP.from_json_dict(d)
    return MsgNapDeviceDna(sbp)
    

msg_classes = {
  0x00B0: MsgBootloaderHandshake,
  0x00B1: MsgBootloaderJumpToApp,
  0x00DD: MsgNapDeviceDna,
}