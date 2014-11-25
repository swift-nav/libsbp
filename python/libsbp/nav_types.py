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
from libsbp.utils import to_repr

#TODO(Buro): Check the format strings.

class Latency(object):

  _fmt = '<iiii'

  def __init__(self, d):
    self.from_binary(d)

  def __repr__(self):
    return to_repr(self)

  @staticmethod
  def size():
    return struct.Struct(Latency._fmt).size

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

  def __init__(self, sbp):
    self.from_binary(sbp.payload)

  def __repr__(self):
    return to_repr(self)

  def from_binary(self, d):
    self.tow, self.wn = struct.unpack(GPSTime._fmt, d)

  def to_binary(self):
    return struct.pack(GPSTime._fmt, (self.tow, self.wn))

class CarrierPhase(object):

  _fmt = '<Ib'

  def __init__(self, sbp):
    self.from_binary(sbp.payload)

  def __repr__(self):
    return to_repr(self)

  def from_binary(self, d):
    self.li, self.lf = struct.unpack(CarrierPhase._fmt, d)

  def to_binary(self):
    return struct.pack(CarrierPhase._fmt, (self.li, self.lf))

class UARTChannel(object):

  _fmt = '<ffHBB'

  def __init__(self, d):
    self.from_binary(d)

  def __repr__(self):
    return to_repr(self)

  @staticmethod
  def size():
    return struct.Struct(UARTChannel._fmt).size

  def from_binary(self, d):
    ( self.txThroughput,
      self.rxThroughput,
      self.crcErrorCount,
      self.txBufferLevel,
      self.rxBufferLevel
    ) = struct.unpack(UARTChannel._fmt, d)

  def to_binary(self):
    return struct.pack(UARTChannel._fmt,
                       ( self.txThroughput,
                         self.rxThroughput,
                         self.crcErrorCount,
                         self.txBufferLevel,
                         self.rxBufferLevel
                        ))

SBP_UART_STATE = 0x0018
class MsgUartState(object):

  def __init__(self, sbp):
    self.from_binary(sbp.payload)

  def __repr__(self):
    return to_repr(self)

  def from_binary(self, d):
    s = UARTChannel.size()
    offset = 0
    self.uarts0 = UARTChannel(d[offset:offset+s])
    offset += s
    self.uarts1 = UARTChannel(d[offset:offset+s])
    offset += s
    self.uarts2 = UARTChannel(d[offset:offset+s])
    offset += s
    s = Latency.size()
    self.latency = Latency(d[offset:offset+s])

  def to_binary(self):
    assert False, "Not implemented."

class TrackingChannel(object):

  def __init__(self, state = None, cn0 = None, prn = None):
    self.state = state
    self.cn0 = cn0
    self.prn = prn

  def update(self, state, prn, cn0):
    self.state = state
    self.cn0 = 0 if cn0 == -1 else cn0
    self.prn = prn

  def __repr__(self):
    return to_repr(self)

SBP_TRACKING_STATE = 0x0016
class MsgTrackingState(object):

  _TRACKING_STATE_BYTES_PER_CHANNEL = 6

  def __init__(self, sbp):
    self.from_binary(sbp.payload)

  def __repr__(self):
    return to_repr(self)

  def from_binary(self, d):
    n_channels = len(d) / MsgTrackingState._TRACKING_STATE_BYTES_PER_CHANNEL
    fmt = '<' + n_channels * 'BBf'
    munch = n_channels*6
    state_data = struct.unpack(fmt, d)
    self.states = [TrackingChannel()]*n_channels
    for n, s in enumerate(self.states):
      s.update(*state_data[3*n:3*(n+1)])

  def to_binary(self):
    assert False, "Not implemented."

msg_classes = {
  0x0018: MsgUartState,
  0x0016: MsgTrackingState
}
