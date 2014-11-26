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

import struct
import libsbp.sbp
import libsbp.nav_types
from libsbp.utils import to_repr

# Automatically generated from sbp.yaml with generate.py, do not hand edit!



SBP_MSG_STARTUP = 0xFF00
class MsgStartup(object):
  """
  SBP class for message MSG_STARTUP (0xFF00)

  The system start-up message is sent once on system start-up. It is
intended to be used to notify the host or other attached devices that
the system has started and is now ready to respond to commands or
configuration requests.

  """

  def __init__(self, sbp):
    self.from_binary(sbp.payload)

  def __repr__(self):
    return to_repr(self)

  def from_binary(self, d):
    (
      self.reserved,
    ) = struct.unpack('<I', d)

  def to_binary(self):
    return struct.pack('<I', (
      self.reserved,
    ))


SBP_MSG_HEARTBEAT = 0xFFFF
class MsgHeartbeat(object):
  """
  SBP class for message MSG_HEARTBEAT (0xFFFF)

  The heartbeat message is sent periodically to inform the host or
other attached devices that the system is running. It is intended to
be used to monitor for system malfunctions and also contains
status flags that indicate to the host the status of the system and
if it is operating correctly.

The system error flag is used to indicate that an error has occurred in
the system. To determine the source of the error the remaining error
flags should be inspected.

  """

  def __init__(self, sbp):
    self.from_binary(sbp.payload)

  def __repr__(self):
    return to_repr(self)

  def from_binary(self, d):
    (
      self.flags,
    ) = struct.unpack('<I', d)

  def to_binary(self):
    return struct.pack('<I', (
      self.flags,
    ))


SBP_MSG_GPS_TIME = 0x0100
class MsgGPSTime(object):
  """
  SBP class for message MSG_GPS_TIME (0x0100)

  GPS Time.

  """

  def __init__(self, sbp):
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
class MsgDops(object):
  """
  SBP class for message MSG_DOPS (0x0206)

  Dilution of Precision.

  """

  def __init__(self, sbp):
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
class MsgPosECEF(object):
  """
  SBP class for message MSG_POS_ECEF (0x0200)

  Position solution in absolute Earth Centered Earth Fixed (ECEF) coordinates.

  """

  def __init__(self, sbp):
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
class MsgPosLLH(object):
  """
  SBP class for message MSG_POS_LLH (0x0201)

  Geodetic position solution.

  """

  def __init__(self, sbp):
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
class MsgBaselineECEF(object):
  """
  SBP class for message MSG_BASELINE_ECEF (0x0202)

  Baseline in Earth Centered Earth Fixed (ECEF) coordinates.

  """

  def __init__(self, sbp):
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


SBP_BASELINE_NED = 0x0203
class BaselineNED(object):
  """
  SBP class for message BASELINE_NED (0x0203)

  Baseline in local North East Down (NED) coordinates.

  """

  def __init__(self, sbp):
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
class MsgVelECEF(object):
  """
  SBP class for message MSG_VEL_ECEF (0x0204)

  Velocity in Earth Centered Earth Fixed (ECEF) coordinates.

  """

  def __init__(self, sbp):
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
class MsgVelNED(object):
  """
  SBP class for message MSG_VEL_NED (0x0205)

  Velocity in local North East Down (NED) coordinates.

  """

  def __init__(self, sbp):
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
  0xFF00: MsgStartup,
  0xFFFF: MsgHeartbeat,
  0x0100: MsgGPSTime,
  0x0206: MsgDops,
  0x0200: MsgPosECEF,
  0x0201: MsgPosLLH,
  0x0202: MsgBaselineECEF,
  0x0203: BaselineNED,
  0x0204: MsgVelECEF,
  0x0205: MsgVelNED,
}

def sbp_decode(t, d):
  return msg_classes[t](d)