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

# Automatically generated from piksi/yaml/swiftnav/sbp/bootload.yaml
# with generate.py at 2015-04-06 23:40:11.121602. Please do not hand edit!


SBP_MSG_BOOTLOADER_HANDSHAKE = 0x00B0
class MsgBootloaderHandshake(SBP):
  """SBP class for message MSG_BOOTLOADER_HANDSHAKE (0x00B0).
  
  The bootloader continually sends a handshake message to the host
for a short period of time, and then jumps to the firmware if it
doesn't receive a handshake from the host. If the host replies
with a handshake the bootloader doesn't jump to the firmware and
nwaits for flash programming messages, and the host has to send a
MSG_BOOTLOADER_JUMP_TO_APP when it's done programming. On old
versions of the bootloader (<=v0.1), hardcoded u8=0. On new
versions, return the git describe string for the bootloader
build.


  Parameters
  ----------
  handshake : int
    Handshake value

  """
  _parser = Struct("MsgBootloaderHandshake",
                   ULInt8('handshake'),)

  def __init__(self, sbp):
    self.__dict__.update(sbp.__dict__)
    self.from_binary(sbp.payload)

  def __repr__(self):
    return fmt_repr(self)
 
  def from_binary(self, d):
    p = MsgBootloaderHandshake._parser.parse(d)
    self.__dict__.update(dict(p.viewitems()))

  def to_binary(self):
    return MsgBootloaderHandshake.build(self.__dict__)
    
SBP_MSG_BOOTLOADER_JUMP_TO_APP = 0x00B1
class MsgBootloaderJumpToApp(SBP):
  """SBP class for message MSG_BOOTLOADER_JUMP_TO_APP (0x00B1).
  
  The host initiates the bootloader to jump to the application.


  Parameters
  ----------
  jump : int
    Ignored by the Piksi.

  """
  _parser = Struct("MsgBootloaderJumpToApp",
                   ULInt8('jump'),)

  def __init__(self, sbp):
    self.__dict__.update(sbp.__dict__)
    self.from_binary(sbp.payload)

  def __repr__(self):
    return fmt_repr(self)
 
  def from_binary(self, d):
    p = MsgBootloaderJumpToApp._parser.parse(d)
    self.__dict__.update(dict(p.viewitems()))

  def to_binary(self):
    return MsgBootloaderJumpToApp.build(self.__dict__)
    
SBP_MSG_NAP_DEVICE_DNA = 0x00DD
class MsgNapDeviceDna(SBP):
  """SBP class for message MSG_NAP_DEVICE_DNA (0x00DD).
  
  The device DNA message from the host reads the unique device
DNA from the Swift Navigation Acceleration Peripheral
(SwiftNAP), a Spartan 6 FPGA. By convention, the host message
buffer is empty; the Piksi returns the device DNA in a
MSG_NAP_DEVICE_DNA message.


  Parameters
  ----------
  dna : array
    57-bit SwiftNAP FPGA Device DNA

  """
  _parser = Struct("MsgNapDeviceDna",
                   Struct('dna', Array(8, ULInt8('dna'))),)

  def __init__(self, sbp):
    self.__dict__.update(sbp.__dict__)
    self.from_binary(sbp.payload)

  def __repr__(self):
    return fmt_repr(self)
 
  def from_binary(self, d):
    p = MsgNapDeviceDna._parser.parse(d)
    self.__dict__.update(dict(p.viewitems()))

  def to_binary(self):
    return MsgNapDeviceDna.build(self.__dict__)
    

msg_classes = {
  0x00B0: MsgBootloaderHandshake,
  0x00B1: MsgBootloaderJumpToApp,
  0x00DD: MsgNapDeviceDna,
}