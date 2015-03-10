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



SBP_MSG_ACQ_RESULT = 0x0015
class MsgAcqResult(SBP):
  """
  SBP class for message MSG_ACQ_RESULT (0x0015)

  Parameters
  ----------
  snr : float
    SNR of best point
  cn : float
    Code phase of best point
  cf : float
    Carrier frequency of best point
  prn : int
    PRN searched for
  """

  def __init__(self, sbp):
    self.__dict__.update(sbp.__dict__)
    self.from_binary(sbp.payload)

  def __repr__(self):
    return to_repr(self)
  def from_binary(self, d):
    (
      self.snr,
      self.cn,
      self.cf,
      self.prn,
    ) = struct.unpack('<fffB', d)

  def to_binary(self):
    return struct.pack('<fffB', (
      self.snr,
      self.cn,
      self.cf,
      self.prn,
    ))


SBP_MSG_OBS_HDR = 0x0040
class MsgObsHdr(SBP):
  """
  SBP class for message MSG_OBS_HDR (0x0040)

  Parameters
  ----------
  t : GPSTime
    GPS time of observation
  count : int
    Serial count of obervation
  n_obs : int
    Number of observation records to follow
  """

  def __init__(self, sbp):
    self.__dict__.update(sbp.__dict__)
    self.from_binary(sbp.payload)

  def __repr__(self):
    return to_repr(self)
  def from_binary(self, d):
    (
      self.t,
      self.count,
      self.n_obs,
    ) = struct.unpack('NOPE', d)

  def to_binary(self):
    return struct.pack('NOPE', (
      self.t,
      self.count,
      self.n_obs,
    ))


SBP_MSG_OBS = 0x0041
class MsgObs(SBP):
  """
  SBP class for message MSG_OBS (0x0041)

  Parameters
  ----------
  P : int
    Pseudorange
  L : Latency
    Fixed point carrier phase
  snr : int
    Signal-to-Noise ratio (cn0 * 4 for 0.25 precision and
0-64 range

  lock_counter : int
    Lock counter. Increments on new lock
  prn : int
    Satellite number
  """

  def __init__(self, sbp):
    self.__dict__.update(sbp.__dict__)
    self.from_binary(sbp.payload)

  def __repr__(self):
    return to_repr(self)
  def from_binary(self, d):
    (
      self.P,
      self.L,
      self.snr,
      self.lock_counter,
      self.prn,
    ) = struct.unpack('NOPE', d)

  def to_binary(self):
    return struct.pack('NOPE', (
      self.P,
      self.L,
      self.snr,
      self.lock_counter,
      self.prn,
    ))


SBP_MSG_OLD_OBS = 0x0042
class MsgOldObs(SBP):
  """
  SBP class for message MSG_OLD_OBS (0x0042)
  """

  def __init__(self, sbp):
    self.__dict__.update(sbp.__dict__)
    self.payload = sbp.payload

  def __repr__(self):
    return to_repr(self)


SBP_MSG_PACKED_OBS = 0x0045
class MsgPackedObs(SBP):
  """
  SBP class for message MSG_PACKED_OBS (0x0045)

  Parameters
  ----------
  gps_tow : int
    Observations
  gps_week : int
    Observations
  obs : PackedObsContent
    Observations
  """

  def __init__(self, sbp):
    self.__dict__.update(sbp.__dict__)
    self.from_binary(sbp.payload)

  def __repr__(self):
    return to_repr(self)
  def from_binary(self, d):
    (
      self.gps_tow,
      self.gps_week,
      self.obs,
    ) = struct.unpack('NOPE', d)

  def to_binary(self):
    return struct.pack('NOPE', (
      self.gps_tow,
      self.gps_week,
      self.obs,
    ))


SBP_MSG_BASE_POS = 0x0044
class MsgBasePos(SBP):
  """
  SBP class for message MSG_BASE_POS (0x0044)

  Parameters
  ----------
  pos_llh_x : double
    Base station position, x
  pos_llh_y : double
    Base station position, y
  pos_llh_z : double
    Base station position, z
  """

  def __init__(self, sbp):
    self.__dict__.update(sbp.__dict__)
    self.from_binary(sbp.payload)

  def __repr__(self):
    return to_repr(self)
  def from_binary(self, d):
    (
      self.pos_llh_x,
      self.pos_llh_y,
      self.pos_llh_z,
    ) = struct.unpack('<ddd', d)

  def to_binary(self):
    return struct.pack('<ddd', (
      self.pos_llh_x,
      self.pos_llh_y,
      self.pos_llh_z,
    ))


SBP_MSG_TRACKING_STATE = 0x0016
class MsgTrackingState(SBP):
  """
  SBP class for message MSG_TRACKING_STATE (0x0016)
    MSG_TRACKING_STATE

  Parameters
  ----------
  states : array
    State of satellite tracking channel.
  """

  def __init__(self, sbp):
    self.__dict__.update(sbp.__dict__)
    self.from_binary(sbp.payload)

  def __repr__(self):
    return to_repr(self)
  def from_binary(self, d):
    (
      self.states,
    ) = struct.unpack('NOPE', d)

  def to_binary(self):
    return struct.pack('NOPE', (
      self.states,
    ))


SBP_MSG_IAR_STATE = 0x0019
class MsgIarState(SBP):
  """
  SBP class for message MSG_IAR_STATE (0x0019)

  Parameters
  ----------
  num_hyps : int
    num_hyps
  """

  def __init__(self, sbp):
    self.__dict__.update(sbp.__dict__)
    self.from_binary(sbp.payload)

  def __repr__(self):
    return to_repr(self)
  def from_binary(self, d):
    (
      self.num_hyps,
    ) = struct.unpack('<I', d)

  def to_binary(self):
    return struct.pack('<I', (
      self.num_hyps,
    ))


SBP_MSG_EPHEMERIS = 0x001A
class MsgEphemeris(SBP):
  """
  SBP class for message MSG_EPHEMERIS (0x001A)
    WGS84 satellite orbit ephemeris parameters

  Parameters
  ----------
  tgd : double
    Group delay differential between L1 and L2 (?)
  crs : double
    Amplitude of the sine harmonic correction term to the orbit radius
  crc : double
    Amplitude of the cosine harmonic correction term to the orbit radius
  cuc : double
    Amplitude of the cosine harmonic correction term to the argument of latitude
  cus : double
    Amplitude of the sine harmonic correction term to the argument of latitude
  cic : double
    Amplitude of the cosine harmonic correction term to the angle of inclination
  cis : double
    Amplitude of the sine harmonic correction term to the angle of inclination
  dn : double
    Mean motion difference
  m0 : double
    Mean anomaly at reference time
  ecc : double
    Eccentricity of satellite orbit
  sqrta : double
    Square root of the semi-major axis of orbit
  omega0 : double
    Longitude of ascending node of orbit plane at weekly epoch
  omegadot : double
    Rate of right ascension
  w : double
    Argument of perigee
  inc : double
    Inclination
  inc_dot : double
    Inclination first derivative
  af0 : double
    Polynomial clock correction coefficient (clock bias)
  af1 : double
    Polynomial clock correction coefficient (clock drift)
  af2 : double
    Polynomial clock correction coefficient (rate of clock drift)
  toe_tow : double
    Time of week
  toe_wn : int
    Week number
  toc_tow : double
    clock reference time of week
  toc_wn : int
    clock reference week number
  valid : int
    Is valid?
  healthy : int
    Satellite is healthy?
  prn : int
    PRN searched for
  """

  def __init__(self, sbp):
    self.__dict__.update(sbp.__dict__)
    self.from_binary(sbp.payload)

  def __repr__(self):
    return to_repr(self)
  def from_binary(self, d):
    (
      self.tgd,
      self.crs,
      self.crc,
      self.cuc,
      self.cus,
      self.cic,
      self.cis,
      self.dn,
      self.m0,
      self.ecc,
      self.sqrta,
      self.omega0,
      self.omegadot,
      self.w,
      self.inc,
      self.inc_dot,
      self.af0,
      self.af1,
      self.af2,
      self.toe_tow,
      self.toe_wn,
      self.toc_tow,
      self.toc_wn,
      self.valid,
      self.healthy,
      self.prn,
    ) = struct.unpack('<ddddddddddddddddddddHdHBBB', d)

  def to_binary(self):
    return struct.pack('<ddddddddddddddddddddHdHBBB', (
      self.tgd,
      self.crs,
      self.crc,
      self.cuc,
      self.cus,
      self.cic,
      self.cis,
      self.dn,
      self.m0,
      self.ecc,
      self.sqrta,
      self.omega0,
      self.omegadot,
      self.w,
      self.inc,
      self.inc_dot,
      self.af0,
      self.af1,
      self.af2,
      self.toe_tow,
      self.toe_wn,
      self.toc_tow,
      self.toc_wn,
      self.valid,
      self.healthy,
      self.prn,
    ))


msg_classes = {
  0x0015: MsgAcqResult,
  0x0040: MsgObsHdr,
  0x0041: MsgObs,
  0x0042: MsgOldObs,
  0x0045: MsgPackedObs,
  0x0044: MsgBasePos,
  0x0016: MsgTrackingState,
  0x0019: MsgIarState,
  0x001A: MsgEphemeris,
}

def sbp_decode(t, d):
  return msg_classes[t](d)