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

import struct
from swift.sbp import SBP
from swift.sbp.utils import to_repr

# Automatically generated from sbp.yaml with generate.py, do not hand edit!



  def __repr__(self):
    return to_repr(self)
  def from_binary(self, d):
    (
      self.txThroughput,
      self.rxThroughput,
      self.crcErrorCount,
      self.txBufferLevel,
      self.rxBufferLevel,
    ) = struct.unpack('<ffHBf', d)

  def to_binary(self):
    return struct.pack('<ffHBf', (
      self.txThroughput,
      self.rxThroughput,
      self.crcErrorCount,
      self.txBufferLevel,
      self.rxBufferLevel,
    ))


  def __repr__(self):
    return to_repr(self)
  def from_binary(self, d):
    (
      self.state,
      self.prn,
      self.cn0,
    ) = struct.unpack('<BBf', d)

  def to_binary(self):
    return struct.pack('<BBf', (
      self.state,
      self.prn,
      self.cn0,
    ))


  def __repr__(self):
    return to_repr(self)
  def from_binary(self, d):
    (
      self.avg,
      self.lmin,
      self.lmax,
      self.current,
    ) = struct.unpack('<iiii', d)

  def to_binary(self):
    return struct.pack('<iiii', (
      self.avg,
      self.lmin,
      self.lmax,
      self.current,
    ))


  def __repr__(self):
    return to_repr(self)
  def from_binary(self, d):
    (
      self.tow,
      self.wn,
    ) = struct.unpack('<dH', d)

  def to_binary(self):
    return struct.pack('<dH', (
      self.tow,
      self.wn,
    ))


  def __repr__(self):
    return to_repr(self)
  def from_binary(self, d):
    (
      self.li,
      self.lf,
    ) = struct.unpack('<IB', d)

  def to_binary(self):
    return struct.pack('<IB', (
      self.li,
      self.lf,
    ))


  def __repr__(self):
    return to_repr(self)
  def from_binary(self, d):
    (
      self.P,
      self.Li,
      self.Lf,
      self.snr,
      self.lock,
      self.prn,
    ) = struct.unpack('<IiBBHB', d)

  def to_binary(self):
    return struct.pack('<IiBBHB', (
      self.P,
      self.Li,
      self.Lf,
      self.snr,
      self.lock,
      self.prn,
    ))


msg_classes = {
}

def sbp_decode(t, d):
  return msg_classes[t](d)