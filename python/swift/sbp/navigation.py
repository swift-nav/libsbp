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



SBP_MSG_GPS_TIME = 0x0100
class MsgGPSTime(SBP):
  """
  SBP class for message MSG_GPS_TIME (0x0100)

  GPS Time.

  """

  def __init__(self, sbp):
    self.__dict__.update(sbp.__dict__)
    self.from_binary(sbp.payload)

  def __repr__(self):
    return to_repr(self)
  def from_binary(self, d):
    (
      self.wn,
      self.tow,
      self.ns,
      self.flags,
    ) = struct.unpack('<HIiB', d)

  def to_binary(self):
    return struct.pack('<HIiB', (
      self.wn,
      self.tow,
      self.ns,
      self.flags,
    ))


SBP_MSG_DOPS = 0x0206
class MsgDops(SBP):
  """
  SBP class for message MSG_DOPS (0x0206)

  Dilution of Precision.

  """

  def __init__(self, sbp):
    self.__dict__.update(sbp.__dict__)
    self.from_binary(sbp.payload)

  def __repr__(self):
    return to_repr(self)
  def from_binary(self, d):
    (
      self.tow,
      self.gdop,
      self.pdop,
      self.tdop,
      self.hdop,
      self.vdop,
    ) = struct.unpack('<IHHHHH', d)

  def to_binary(self):
    return struct.pack('<IHHHHH', (
      self.tow,
      self.gdop,
      self.pdop,
      self.tdop,
      self.hdop,
      self.vdop,
    ))


SBP_MSG_POS_ECEF = 0x0200
class MsgPosECEF(SBP):
  """
  SBP class for message MSG_POS_ECEF (0x0200)

  Position solution in absolute Earth Centered Earth Fixed (ECEF) coordinates.

  """

  def __init__(self, sbp):
    self.__dict__.update(sbp.__dict__)
    self.from_binary(sbp.payload)

  def __repr__(self):
    return to_repr(self)
  def from_binary(self, d):
    (
      self.tow,
      self.x,
      self.y,
      self.z,
      self.accuracy,
      self.n_sats,
      self.flags,
    ) = struct.unpack('<IdddHBB', d)

  def to_binary(self):
    return struct.pack('<IdddHBB', (
      self.tow,
      self.x,
      self.y,
      self.z,
      self.accuracy,
      self.n_sats,
      self.flags,
    ))


SBP_MSG_POS_LLH = 0x0201
class MsgPosLLH(SBP):
  """
  SBP class for message MSG_POS_LLH (0x0201)

  Geodetic position solution.

  """

  def __init__(self, sbp):
    self.__dict__.update(sbp.__dict__)
    self.from_binary(sbp.payload)

  def __repr__(self):
    return to_repr(self)
  def from_binary(self, d):
    (
      self.tow,
      self.lat,
      self.lon,
      self.height,
      self.h_accuracy,
      self.v_accuracy,
      self.n_sats,
      self.flags,
    ) = struct.unpack('<IdddHHBB', d)

  def to_binary(self):
    return struct.pack('<IdddHHBB', (
      self.tow,
      self.lat,
      self.lon,
      self.height,
      self.h_accuracy,
      self.v_accuracy,
      self.n_sats,
      self.flags,
    ))


SBP_MSG_BASELINE_ECEF = 0x0202
class MsgBaselineECEF(SBP):
  """
  SBP class for message MSG_BASELINE_ECEF (0x0202)

  Baseline in Earth Centered Earth Fixed (ECEF) coordinates.

  """

  def __init__(self, sbp):
    self.__dict__.update(sbp.__dict__)
    self.from_binary(sbp.payload)

  def __repr__(self):
    return to_repr(self)
  def from_binary(self, d):
    (
      self.tow,
      self.x,
      self.y,
      self.z,
      self.accuracy,
      self.n_sats,
      self.flags,
    ) = struct.unpack('<IiiiHBB', d)

  def to_binary(self):
    return struct.pack('<IiiiHBB', (
      self.tow,
      self.x,
      self.y,
      self.z,
      self.accuracy,
      self.n_sats,
      self.flags,
    ))


SBP_MSG_BASELINE_NED = 0x0203
class MsgBaselineNED(SBP):
  """
  SBP class for message MSG_BASELINE_NED (0x0203)

  Baseline in local North East Down (NED) coordinates.

  """

  def __init__(self, sbp):
    self.__dict__.update(sbp.__dict__)
    self.from_binary(sbp.payload)

  def __repr__(self):
    return to_repr(self)
  def from_binary(self, d):
    (
      self.tow,
      self.n,
      self.e,
      self.d,
      self.h_accuracy,
      self.v_accuracy,
      self.n_sats,
      self.flags,
    ) = struct.unpack('<IiiiHHBB', d)

  def to_binary(self):
    return struct.pack('<IiiiHHBB', (
      self.tow,
      self.n,
      self.e,
      self.d,
      self.h_accuracy,
      self.v_accuracy,
      self.n_sats,
      self.flags,
    ))


SBP_MSG_VEL_ECEF = 0x0204
class MsgVelECEF(SBP):
  """
  SBP class for message MSG_VEL_ECEF (0x0204)

  Velocity in Earth Centered Earth Fixed (ECEF) coordinates.

  """

  def __init__(self, sbp):
    self.__dict__.update(sbp.__dict__)
    self.from_binary(sbp.payload)

  def __repr__(self):
    return to_repr(self)
  def from_binary(self, d):
    (
      self.tow,
      self.x,
      self.y,
      self.z,
      self.accuracy,
      self.n_sats,
      self.flags,
    ) = struct.unpack('<IiiiHBB', d)

  def to_binary(self):
    return struct.pack('<IiiiHBB', (
      self.tow,
      self.x,
      self.y,
      self.z,
      self.accuracy,
      self.n_sats,
      self.flags,
    ))


SBP_MSG_VEL_NED = 0x0205
class MsgVelNED(SBP):
  """
  SBP class for message MSG_VEL_NED (0x0205)

  Velocity in local North East Down (NED) coordinates.

  """

  def __init__(self, sbp):
    self.__dict__.update(sbp.__dict__)
    self.from_binary(sbp.payload)

  def __repr__(self):
    return to_repr(self)
  def from_binary(self, d):
    (
      self.tow,
      self.n,
      self.e,
      self.d,
      self.h_accuracy,
      self.v_accuracy,
      self.n_sats,
      self.flags,
    ) = struct.unpack('<IiiiHHBB', d)

  def to_binary(self):
    return struct.pack('<IiiiHHBB', (
      self.tow,
      self.n,
      self.e,
      self.d,
      self.h_accuracy,
      self.v_accuracy,
      self.n_sats,
      self.flags,
    ))


msg_classes = {
  0x0100: MsgGPSTime,
  0x0206: MsgDops,
  0x0200: MsgPosECEF,
  0x0201: MsgPosLLH,
  0x0202: MsgBaselineECEF,
  0x0203: MsgBaselineNED,
  0x0204: MsgVelECEF,
  0x0205: MsgVelNED,
}

def sbp_decode(t, d):
  return msg_classes[t](d)