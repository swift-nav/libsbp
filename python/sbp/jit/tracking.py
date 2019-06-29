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
Satellite code and carrier-phase tracking messages from the device.

"""

import json

import numpy as np

from sbp.jit.msg import SBP, SENDER_ID
from sbp.jit.msg import get_u8, get_u16, get_u32, get_u64
from sbp.jit.msg import get_s8, get_s16, get_s32, get_s64
from sbp.jit.msg import get_f32, get_f64, judicious_round
from sbp.jit.msg import get_string, get_fixed_string, get_setting
from sbp.jit.msg import get_array, get_fixed_array
from sbp.jit.gnss import *

# Automatically generated from piksi/yaml/swiftnav/sbp/tracking.yaml with generate.py.
# Please do not hand edit!
SBP_MSG_TRACKING_STATE_DETAILED_DEP_A = 0x0021
class MsgTrackingStateDetailedDepA(SBP):
  """SBP class for message MSG_TRACKING_STATE_DETAILED_DEP_A (0x0021).

  You can have MSG_TRACKING_STATE_DETAILED_DEP_A inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  The tracking message returns a set tracking channel parameters for a
single tracking channel useful for debugging issues.


  """
  __slots__ = ['recv_time',
               'tot',
               'P',
               'P_std',
               'L',
               'cn0',
               'lock',
               'sid',
               'doppler',
               'doppler_std',
               'uptime',
               'clock_offset',
               'clock_drift',
               'corr_spacing',
               'acceleration',
               'sync_flags',
               'tow_flags',
               'track_flags',
               'nav_flags',
               'pset_flags',
               'misc_flags',
               ]
  @classmethod
  def parse_members(cls, buf, offset, length):
    ret = {}
    (__recv_time, offset, length) = get_u64(buf, offset, length)
    ret['recv_time'] = __recv_time
    (__tot, offset, length) = GPSTime.parse_members(buf, offset, length)
    ret['tot'] = __tot
    (__P, offset, length) = get_u32(buf, offset, length)
    ret['P'] = __P
    (__P_std, offset, length) = get_u16(buf, offset, length)
    ret['P_std'] = __P_std
    (__L, offset, length) = CarrierPhase.parse_members(buf, offset, length)
    ret['L'] = __L
    (__cn0, offset, length) = get_u8(buf, offset, length)
    ret['cn0'] = __cn0
    (__lock, offset, length) = get_u16(buf, offset, length)
    ret['lock'] = __lock
    (__sid, offset, length) = GnssSignal.parse_members(buf, offset, length)
    ret['sid'] = __sid
    (__doppler, offset, length) = get_s32(buf, offset, length)
    ret['doppler'] = __doppler
    (__doppler_std, offset, length) = get_u16(buf, offset, length)
    ret['doppler_std'] = __doppler_std
    (__uptime, offset, length) = get_u32(buf, offset, length)
    ret['uptime'] = __uptime
    (__clock_offset, offset, length) = get_s16(buf, offset, length)
    ret['clock_offset'] = __clock_offset
    (__clock_drift, offset, length) = get_s16(buf, offset, length)
    ret['clock_drift'] = __clock_drift
    (__corr_spacing, offset, length) = get_u16(buf, offset, length)
    ret['corr_spacing'] = __corr_spacing
    (__acceleration, offset, length) = get_s8(buf, offset, length)
    ret['acceleration'] = __acceleration
    (__sync_flags, offset, length) = get_u8(buf, offset, length)
    ret['sync_flags'] = __sync_flags
    (__tow_flags, offset, length) = get_u8(buf, offset, length)
    ret['tow_flags'] = __tow_flags
    (__track_flags, offset, length) = get_u8(buf, offset, length)
    ret['track_flags'] = __track_flags
    (__nav_flags, offset, length) = get_u8(buf, offset, length)
    ret['nav_flags'] = __nav_flags
    (__pset_flags, offset, length) = get_u8(buf, offset, length)
    ret['pset_flags'] = __pset_flags
    (__misc_flags, offset, length) = get_u8(buf, offset, length)
    ret['misc_flags'] = __misc_flags
    return ret, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.recv_time = res['recv_time']
    self.tot = res['tot']
    self.P = res['P']
    self.P_std = res['P_std']
    self.L = res['L']
    self.cn0 = res['cn0']
    self.lock = res['lock']
    self.sid = res['sid']
    self.doppler = res['doppler']
    self.doppler_std = res['doppler_std']
    self.uptime = res['uptime']
    self.clock_offset = res['clock_offset']
    self.clock_drift = res['clock_drift']
    self.corr_spacing = res['corr_spacing']
    self.acceleration = res['acceleration']
    self.sync_flags = res['sync_flags']
    self.tow_flags = res['tow_flags']
    self.track_flags = res['track_flags']
    self.nav_flags = res['nav_flags']
    self.pset_flags = res['pset_flags']
    self.misc_flags = res['misc_flags']
    return res, off, length

  @classmethod
  def _payload_size(self):
    ret = 0
    # recv_time: u64
    ret += 8
    # tot: GPSTime
    ret += GPSTime._payload_size()
    # P: u32
    ret += 4
    # P_std: u16
    ret += 2
    # L: CarrierPhase
    ret += CarrierPhase._payload_size()
    # cn0: u8
    ret += 1
    # lock: u16
    ret += 2
    # sid: GnssSignal
    ret += GnssSignal._payload_size()
    # doppler: s32
    ret += 4
    # doppler_std: u16
    ret += 2
    # uptime: u32
    ret += 4
    # clock_offset: s16
    ret += 2
    # clock_drift: s16
    ret += 2
    # corr_spacing: u16
    ret += 2
    # acceleration: s8
    ret += 1
    # sync_flags: u8
    ret += 1
    # tow_flags: u8
    ret += 1
    # track_flags: u8
    ret += 1
    # nav_flags: u8
    ret += 1
    # pset_flags: u8
    ret += 1
    # misc_flags: u8
    ret += 1
    return ret
  
SBP_MSG_TRACKING_STATE_DETAILED_DEP = 0x0011
class MsgTrackingStateDetailedDep(SBP):
  """SBP class for message MSG_TRACKING_STATE_DETAILED_DEP (0x0011).

  You can have MSG_TRACKING_STATE_DETAILED_DEP inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  Deprecated.

  """
  __slots__ = ['recv_time',
               'tot',
               'P',
               'P_std',
               'L',
               'cn0',
               'lock',
               'sid',
               'doppler',
               'doppler_std',
               'uptime',
               'clock_offset',
               'clock_drift',
               'corr_spacing',
               'acceleration',
               'sync_flags',
               'tow_flags',
               'track_flags',
               'nav_flags',
               'pset_flags',
               'misc_flags',
               ]
  @classmethod
  def parse_members(cls, buf, offset, length):
    ret = {}
    (__recv_time, offset, length) = get_u64(buf, offset, length)
    ret['recv_time'] = __recv_time
    (__tot, offset, length) = GPSTimeDep.parse_members(buf, offset, length)
    ret['tot'] = __tot
    (__P, offset, length) = get_u32(buf, offset, length)
    ret['P'] = __P
    (__P_std, offset, length) = get_u16(buf, offset, length)
    ret['P_std'] = __P_std
    (__L, offset, length) = CarrierPhase.parse_members(buf, offset, length)
    ret['L'] = __L
    (__cn0, offset, length) = get_u8(buf, offset, length)
    ret['cn0'] = __cn0
    (__lock, offset, length) = get_u16(buf, offset, length)
    ret['lock'] = __lock
    (__sid, offset, length) = GnssSignalDep.parse_members(buf, offset, length)
    ret['sid'] = __sid
    (__doppler, offset, length) = get_s32(buf, offset, length)
    ret['doppler'] = __doppler
    (__doppler_std, offset, length) = get_u16(buf, offset, length)
    ret['doppler_std'] = __doppler_std
    (__uptime, offset, length) = get_u32(buf, offset, length)
    ret['uptime'] = __uptime
    (__clock_offset, offset, length) = get_s16(buf, offset, length)
    ret['clock_offset'] = __clock_offset
    (__clock_drift, offset, length) = get_s16(buf, offset, length)
    ret['clock_drift'] = __clock_drift
    (__corr_spacing, offset, length) = get_u16(buf, offset, length)
    ret['corr_spacing'] = __corr_spacing
    (__acceleration, offset, length) = get_s8(buf, offset, length)
    ret['acceleration'] = __acceleration
    (__sync_flags, offset, length) = get_u8(buf, offset, length)
    ret['sync_flags'] = __sync_flags
    (__tow_flags, offset, length) = get_u8(buf, offset, length)
    ret['tow_flags'] = __tow_flags
    (__track_flags, offset, length) = get_u8(buf, offset, length)
    ret['track_flags'] = __track_flags
    (__nav_flags, offset, length) = get_u8(buf, offset, length)
    ret['nav_flags'] = __nav_flags
    (__pset_flags, offset, length) = get_u8(buf, offset, length)
    ret['pset_flags'] = __pset_flags
    (__misc_flags, offset, length) = get_u8(buf, offset, length)
    ret['misc_flags'] = __misc_flags
    return ret, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.recv_time = res['recv_time']
    self.tot = res['tot']
    self.P = res['P']
    self.P_std = res['P_std']
    self.L = res['L']
    self.cn0 = res['cn0']
    self.lock = res['lock']
    self.sid = res['sid']
    self.doppler = res['doppler']
    self.doppler_std = res['doppler_std']
    self.uptime = res['uptime']
    self.clock_offset = res['clock_offset']
    self.clock_drift = res['clock_drift']
    self.corr_spacing = res['corr_spacing']
    self.acceleration = res['acceleration']
    self.sync_flags = res['sync_flags']
    self.tow_flags = res['tow_flags']
    self.track_flags = res['track_flags']
    self.nav_flags = res['nav_flags']
    self.pset_flags = res['pset_flags']
    self.misc_flags = res['misc_flags']
    return res, off, length

  @classmethod
  def _payload_size(self):
    ret = 0
    # recv_time: u64
    ret += 8
    # tot: GPSTimeDep
    ret += GPSTimeDep._payload_size()
    # P: u32
    ret += 4
    # P_std: u16
    ret += 2
    # L: CarrierPhase
    ret += CarrierPhase._payload_size()
    # cn0: u8
    ret += 1
    # lock: u16
    ret += 2
    # sid: GnssSignalDep
    ret += GnssSignalDep._payload_size()
    # doppler: s32
    ret += 4
    # doppler_std: u16
    ret += 2
    # uptime: u32
    ret += 4
    # clock_offset: s16
    ret += 2
    # clock_drift: s16
    ret += 2
    # corr_spacing: u16
    ret += 2
    # acceleration: s8
    ret += 1
    # sync_flags: u8
    ret += 1
    # tow_flags: u8
    ret += 1
    # track_flags: u8
    ret += 1
    # nav_flags: u8
    ret += 1
    # pset_flags: u8
    ret += 1
    # misc_flags: u8
    ret += 1
    return ret
  
class TrackingChannelState(object):
  """SBP class for message TrackingChannelState

  You can have TrackingChannelState inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  Tracking channel state for a specific satellite signal and
measured signal power.


  """
  __slots__ = ['sid',
               'fcn',
               'cn0',
               ]
  @classmethod
  def parse_members(cls, buf, offset, length):
    ret = {}
    (__sid, offset, length) = GnssSignal.parse_members(buf, offset, length)
    ret['sid'] = __sid
    (__fcn, offset, length) = get_u8(buf, offset, length)
    ret['fcn'] = __fcn
    (__cn0, offset, length) = get_u8(buf, offset, length)
    ret['cn0'] = __cn0
    return ret, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.sid = res['sid']
    self.fcn = res['fcn']
    self.cn0 = res['cn0']
    return res, off, length

  @classmethod
  def _payload_size(self):
    ret = 0
    # sid: GnssSignal
    ret += GnssSignal._payload_size()
    # fcn: u8
    ret += 1
    # cn0: u8
    ret += 1
    return ret
  
SBP_MSG_TRACKING_STATE = 0x0041
class MsgTrackingState(SBP):
  """SBP class for message MSG_TRACKING_STATE (0x0041).

  You can have MSG_TRACKING_STATE inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  The tracking message returns a variable-length array of tracking
channel states. It reports status and carrier-to-noise density
measurements for all tracked satellites.


  """
  __slots__ = ['states',
               ]
  @classmethod
  def parse_members(cls, buf, offset, length):
    ret = {}
    (__states, offset, length) = get_array(TrackingChannelState.parse_members)(buf, offset, length)
    ret['states'] = __states
    return ret, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.states = res['states']
    return res, off, length

  @classmethod
  def _payload_size(self):
    ret = 0
    # states: array of TrackingChannelState
    ret += 247
    return ret
  
class MeasurementState(object):
  """SBP class for message MeasurementState

  You can have MeasurementState inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  Measurement Engine tracking channel state for a specific satellite signal
and measured signal power.
The mesid field for Glonass can either
carry the FCN as 100 + FCN where FCN is in [-7, +6] or
the Slot ID (from 1 to 28)


  """
  __slots__ = ['mesid',
               'cn0',
               ]
  @classmethod
  def parse_members(cls, buf, offset, length):
    ret = {}
    (__mesid, offset, length) = GnssSignal.parse_members(buf, offset, length)
    ret['mesid'] = __mesid
    (__cn0, offset, length) = get_u8(buf, offset, length)
    ret['cn0'] = __cn0
    return ret, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.mesid = res['mesid']
    self.cn0 = res['cn0']
    return res, off, length

  @classmethod
  def _payload_size(self):
    ret = 0
    # mesid: GnssSignal
    ret += GnssSignal._payload_size()
    # cn0: u8
    ret += 1
    return ret
  
SBP_MSG_MEASUREMENT_STATE = 0x0061
class MsgMeasurementState(SBP):
  """SBP class for message MSG_MEASUREMENT_STATE (0x0061).

  You can have MSG_MEASUREMENT_STATE inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  The tracking message returns a variable-length array of tracking
channel states. It reports status and carrier-to-noise density
measurements for all tracked satellites.


  """
  __slots__ = ['states',
               ]
  @classmethod
  def parse_members(cls, buf, offset, length):
    ret = {}
    (__states, offset, length) = get_array(MeasurementState.parse_members)(buf, offset, length)
    ret['states'] = __states
    return ret, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.states = res['states']
    return res, off, length

  @classmethod
  def _payload_size(self):
    ret = 0
    # states: array of MeasurementState
    ret += 247
    return ret
  
class TrackingChannelCorrelation(object):
  """SBP class for message TrackingChannelCorrelation

  You can have TrackingChannelCorrelation inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  Structure containing in-phase and quadrature correlation components.


  """
  __slots__ = ['I',
               'Q',
               ]
  @classmethod
  def parse_members(cls, buf, offset, length):
    ret = {}
    (__I, offset, length) = get_s16(buf, offset, length)
    ret['I'] = __I
    (__Q, offset, length) = get_s16(buf, offset, length)
    ret['Q'] = __Q
    return ret, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.I = res['I']
    self.Q = res['Q']
    return res, off, length

  @classmethod
  def _payload_size(self):
    ret = 0
    # I: s16
    ret += 2
    # Q: s16
    ret += 2
    return ret
  
SBP_MSG_TRACKING_IQ = 0x002D
class MsgTrackingIq(SBP):
  """SBP class for message MSG_TRACKING_IQ (0x002D).

  You can have MSG_TRACKING_IQ inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  When enabled, a tracking channel can output the correlations at each
update interval.


  """
  __slots__ = ['channel',
               'sid',
               'corrs',
               ]
  @classmethod
  def parse_members(cls, buf, offset, length):
    ret = {}
    (__channel, offset, length) = get_u8(buf, offset, length)
    ret['channel'] = __channel
    (__sid, offset, length) = GnssSignal.parse_members(buf, offset, length)
    ret['sid'] = __sid
    (__corrs, offset, length) = get_fixed_array(TrackingChannelCorrelation._unpack_members, 3, TrackingChannelCorrelation._payload_size())(buf, offset, length)
    ret['corrs'] = __corrs
    return ret, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.channel = res['channel']
    self.sid = res['sid']
    self.corrs = res['corrs']
    return res, off, length

  @classmethod
  def _payload_size(self):
    ret = 0
    # channel: u8
    ret += 1
    # sid: GnssSignal
    ret += GnssSignal._payload_size()
    # corrs: array of TrackingChannelCorrelation
    ret += TrackingChannelCorrelation._payload_size() * 3
    return ret
  
class TrackingChannelCorrelationDep(object):
  """SBP class for message TrackingChannelCorrelationDep

  You can have TrackingChannelCorrelationDep inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  Structure containing in-phase and quadrature correlation components.


  """
  __slots__ = ['I',
               'Q',
               ]
  @classmethod
  def parse_members(cls, buf, offset, length):
    ret = {}
    (__I, offset, length) = get_s32(buf, offset, length)
    ret['I'] = __I
    (__Q, offset, length) = get_s32(buf, offset, length)
    ret['Q'] = __Q
    return ret, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.I = res['I']
    self.Q = res['Q']
    return res, off, length

  @classmethod
  def _payload_size(self):
    ret = 0
    # I: s32
    ret += 4
    # Q: s32
    ret += 4
    return ret
  
SBP_MSG_TRACKING_IQ_DEP_B = 0x002C
class MsgTrackingIqDepB(SBP):
  """SBP class for message MSG_TRACKING_IQ_DEP_B (0x002C).

  You can have MSG_TRACKING_IQ_DEP_B inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  When enabled, a tracking channel can output the correlations at each
update interval.


  """
  __slots__ = ['channel',
               'sid',
               'corrs',
               ]
  @classmethod
  def parse_members(cls, buf, offset, length):
    ret = {}
    (__channel, offset, length) = get_u8(buf, offset, length)
    ret['channel'] = __channel
    (__sid, offset, length) = GnssSignal.parse_members(buf, offset, length)
    ret['sid'] = __sid
    (__corrs, offset, length) = get_fixed_array(TrackingChannelCorrelationDep._unpack_members, 3, TrackingChannelCorrelationDep._payload_size())(buf, offset, length)
    ret['corrs'] = __corrs
    return ret, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.channel = res['channel']
    self.sid = res['sid']
    self.corrs = res['corrs']
    return res, off, length

  @classmethod
  def _payload_size(self):
    ret = 0
    # channel: u8
    ret += 1
    # sid: GnssSignal
    ret += GnssSignal._payload_size()
    # corrs: array of TrackingChannelCorrelationDep
    ret += TrackingChannelCorrelationDep._payload_size() * 3
    return ret
  
SBP_MSG_TRACKING_IQ_DEP_A = 0x001C
class MsgTrackingIqDepA(SBP):
  """SBP class for message MSG_TRACKING_IQ_DEP_A (0x001C).

  You can have MSG_TRACKING_IQ_DEP_A inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  Deprecated.

  """
  __slots__ = ['channel',
               'sid',
               'corrs',
               ]
  @classmethod
  def parse_members(cls, buf, offset, length):
    ret = {}
    (__channel, offset, length) = get_u8(buf, offset, length)
    ret['channel'] = __channel
    (__sid, offset, length) = GnssSignalDep.parse_members(buf, offset, length)
    ret['sid'] = __sid
    (__corrs, offset, length) = get_fixed_array(TrackingChannelCorrelationDep._unpack_members, 3, TrackingChannelCorrelationDep._payload_size())(buf, offset, length)
    ret['corrs'] = __corrs
    return ret, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.channel = res['channel']
    self.sid = res['sid']
    self.corrs = res['corrs']
    return res, off, length

  @classmethod
  def _payload_size(self):
    ret = 0
    # channel: u8
    ret += 1
    # sid: GnssSignalDep
    ret += GnssSignalDep._payload_size()
    # corrs: array of TrackingChannelCorrelationDep
    ret += TrackingChannelCorrelationDep._payload_size() * 3
    return ret
  
class TrackingChannelStateDepA(object):
  """SBP class for message TrackingChannelStateDepA

  You can have TrackingChannelStateDepA inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  Deprecated.

  """
  __slots__ = ['state',
               'prn',
               'cn0',
               ]
  @classmethod
  def parse_members(cls, buf, offset, length):
    ret = {}
    (__state, offset, length) = get_u8(buf, offset, length)
    ret['state'] = __state
    (__prn, offset, length) = get_u8(buf, offset, length)
    ret['prn'] = __prn
    (__cn0, offset, length) = get_f32(buf, offset, length)
    ret['cn0'] = judicious_round(np.float32(__cn0)) if SBP.judicious_rounding else __cn0
    return ret, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.state = res['state']
    self.prn = res['prn']
    self.cn0 = res['cn0']
    return res, off, length

  @classmethod
  def _payload_size(self):
    ret = 0
    # state: u8
    ret += 1
    # prn: u8
    ret += 1
    # cn0: float
    ret += 4
    return ret
  
SBP_MSG_TRACKING_STATE_DEP_A = 0x0016
class MsgTrackingStateDepA(SBP):
  """SBP class for message MSG_TRACKING_STATE_DEP_A (0x0016).

  You can have MSG_TRACKING_STATE_DEP_A inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  Deprecated.

  """
  __slots__ = ['states',
               ]
  @classmethod
  def parse_members(cls, buf, offset, length):
    ret = {}
    (__states, offset, length) = get_array(TrackingChannelStateDepA.parse_members)(buf, offset, length)
    ret['states'] = __states
    return ret, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.states = res['states']
    return res, off, length

  @classmethod
  def _payload_size(self):
    ret = 0
    # states: array of TrackingChannelStateDepA
    ret += 247
    return ret
  
class TrackingChannelStateDepB(object):
  """SBP class for message TrackingChannelStateDepB

  You can have TrackingChannelStateDepB inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  Deprecated.

  """
  __slots__ = ['state',
               'sid',
               'cn0',
               ]
  @classmethod
  def parse_members(cls, buf, offset, length):
    ret = {}
    (__state, offset, length) = get_u8(buf, offset, length)
    ret['state'] = __state
    (__sid, offset, length) = GnssSignalDep.parse_members(buf, offset, length)
    ret['sid'] = __sid
    (__cn0, offset, length) = get_f32(buf, offset, length)
    ret['cn0'] = judicious_round(np.float32(__cn0)) if SBP.judicious_rounding else __cn0
    return ret, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.state = res['state']
    self.sid = res['sid']
    self.cn0 = res['cn0']
    return res, off, length

  @classmethod
  def _payload_size(self):
    ret = 0
    # state: u8
    ret += 1
    # sid: GnssSignalDep
    ret += GnssSignalDep._payload_size()
    # cn0: float
    ret += 4
    return ret
  
SBP_MSG_TRACKING_STATE_DEP_B = 0x0013
class MsgTrackingStateDepB(SBP):
  """SBP class for message MSG_TRACKING_STATE_DEP_B (0x0013).

  You can have MSG_TRACKING_STATE_DEP_B inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  Deprecated.

  """
  __slots__ = ['states',
               ]
  @classmethod
  def parse_members(cls, buf, offset, length):
    ret = {}
    (__states, offset, length) = get_array(TrackingChannelStateDepB.parse_members)(buf, offset, length)
    ret['states'] = __states
    return ret, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.states = res['states']
    return res, off, length

  @classmethod
  def _payload_size(self):
    ret = 0
    # states: array of TrackingChannelStateDepB
    ret += 247
    return ret
  

msg_classes = {
  0x0021: MsgTrackingStateDetailedDepA,
  0x0011: MsgTrackingStateDetailedDep,
  0x0041: MsgTrackingState,
  0x0061: MsgMeasurementState,
  0x002D: MsgTrackingIq,
  0x002C: MsgTrackingIqDepB,
  0x001C: MsgTrackingIqDepA,
  0x0016: MsgTrackingStateDepA,
  0x0013: MsgTrackingStateDepB,
}