#!/usr/bin/env python
# Copyright (C) 2011-2014 Swift Navigation Inc.
# Contact: Fergus Noble <fergus@swiftnav.com>
#
# This source is subject to the license found in the file 'LICENSE' which must
# be be distributed together with this source. All other rights reserved.
#
# THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
# EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
# WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.

"""
Complex types needed in SBP messages.
"""

import struct

#TODO(Buro): Check the format strings.

class Latency(object):

  _fmt = '<iiii'

  def __init__(self, d):
    self.from_binary(d)

  def from_binary(self, d):
    ( self.avg,
      self.lmin,
      self.lmax,
      self.current
    ) = struct.unpack(Latency._fmt, d)

  def to_binary(self):
    return struct.pack(Latency._fmt,
                       ( self.avg,
                         self.lmin,
                         self.lmax,
                         self.current ))

class GPSTime(object):

  _fmt = '<dH'

  def __init__(self, d):
    self.from_binary(d)

  def from_binary(self, d):
    self.tow, self.wn = struct.unpack(GPSTime._fmt, d)

  def to_binary(self):
    return struct.pack(GPSTime._fmt, (self.tow, self.wn))

class CarrierPhase(object):

  _fmt = '<Ib'

  def __init__(self, d):
    self.from_binary(d)

  def from_binary(self, d):
    self.li, self.lf = struct.unpack(CarrierPhase._fmt, d)

  def to_binary(self):
    return struct.pack(CarrierPhase._fmt, (self.li, self.lf))

class UARTState(object):

  _fmt = '<ffHbb'

  def __init__(self, d):
    self.from_binary(d)

  def from_binary(self, d):
    ( self.txThroughput,
      self.rxThroughput,
      self.crcErrorCount,
      self.txBufferLevel,
      self.rxBufferLevel,
    ) = struct.unpack(UARTState._fmt, d)

  def to_binary(self):
    return struct.pack(UARTState._fmt,
                       ( self.txThroughput,
                         self.rxThroughput,
                         self.crcErrorCount,
                         self.txBufferLevel,
                         self.rxBufferLevel
                        ))
