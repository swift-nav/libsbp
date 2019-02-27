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

from sbp.jit.msg import SBP, SENDER_ID
from sbp.jit.msg import get_u8, get_u16, get_u32, get_u64
from sbp.jit.msg import get_s8, get_s16, get_s32, get_s64
from sbp.jit.msg import get_f32, get_f64
from sbp.jit.msg import get_string, get_fixed_string
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
    o_0 = offset
    o_1, (__recv_time, offset, length) = offset, get_u64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__tot, offset, length) = offset, GPSTime.parse_members(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__P, offset, length) = offset, get_u32(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__P_std, offset, length) = offset, get_u16(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__L, offset, length) = offset, CarrierPhase.parse_members(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__cn0, offset, length) = offset, get_u8(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__lock, offset, length) = offset, get_u16(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__sid, offset, length) = offset, GnssSignal.parse_members(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__doppler, offset, length) = offset, get_s32(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__doppler_std, offset, length) = offset, get_u16(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__uptime, offset, length) = offset, get_u32(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__clock_offset, offset, length) = offset, get_s16(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__clock_drift, offset, length) = offset, get_s16(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__corr_spacing, offset, length) = offset, get_u16(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__acceleration, offset, length) = offset, get_s8(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__sync_flags, offset, length) = offset, get_u8(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__tow_flags, offset, length) = offset, get_u8(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__track_flags, offset, length) = offset, get_u8(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__nav_flags, offset, length) = offset, get_u8(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__pset_flags, offset, length) = offset, get_u8(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__misc_flags, offset, length) = offset, get_u8(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    return {
      'recv_time' : __recv_time,
      'tot' : __tot,
      'P' : __P,
      'P_std' : __P_std,
      'L' : __L,
      'cn0' : __cn0,
      'lock' : __lock,
      'sid' : __sid,
      'doppler' : __doppler,
      'doppler_std' : __doppler_std,
      'uptime' : __uptime,
      'clock_offset' : __clock_offset,
      'clock_drift' : __clock_drift,
      'corr_spacing' : __corr_spacing,
      'acceleration' : __acceleration,
      'sync_flags' : __sync_flags,
      'tow_flags' : __tow_flags,
      'track_flags' : __track_flags,
      'nav_flags' : __nav_flags,
      'pset_flags' : __pset_flags,
      'misc_flags' : __misc_flags,
    }, offset, length

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
    o_0 = offset
    o_1, (__recv_time, offset, length) = offset, get_u64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__tot, offset, length) = offset, GPSTimeDep.parse_members(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__P, offset, length) = offset, get_u32(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__P_std, offset, length) = offset, get_u16(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__L, offset, length) = offset, CarrierPhase.parse_members(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__cn0, offset, length) = offset, get_u8(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__lock, offset, length) = offset, get_u16(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__sid, offset, length) = offset, GnssSignalDep.parse_members(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__doppler, offset, length) = offset, get_s32(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__doppler_std, offset, length) = offset, get_u16(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__uptime, offset, length) = offset, get_u32(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__clock_offset, offset, length) = offset, get_s16(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__clock_drift, offset, length) = offset, get_s16(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__corr_spacing, offset, length) = offset, get_u16(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__acceleration, offset, length) = offset, get_s8(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__sync_flags, offset, length) = offset, get_u8(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__tow_flags, offset, length) = offset, get_u8(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__track_flags, offset, length) = offset, get_u8(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__nav_flags, offset, length) = offset, get_u8(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__pset_flags, offset, length) = offset, get_u8(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__misc_flags, offset, length) = offset, get_u8(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    return {
      'recv_time' : __recv_time,
      'tot' : __tot,
      'P' : __P,
      'P_std' : __P_std,
      'L' : __L,
      'cn0' : __cn0,
      'lock' : __lock,
      'sid' : __sid,
      'doppler' : __doppler,
      'doppler_std' : __doppler_std,
      'uptime' : __uptime,
      'clock_offset' : __clock_offset,
      'clock_drift' : __clock_drift,
      'corr_spacing' : __corr_spacing,
      'acceleration' : __acceleration,
      'sync_flags' : __sync_flags,
      'tow_flags' : __tow_flags,
      'track_flags' : __track_flags,
      'nav_flags' : __nav_flags,
      'pset_flags' : __pset_flags,
      'misc_flags' : __misc_flags,
    }, offset, length

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
    o_0 = offset
    o_1, (__sid, offset, length) = offset, GnssSignal.parse_members(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__fcn, offset, length) = offset, get_u8(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__cn0, offset, length) = offset, get_u8(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    return {
      'sid' : __sid,
      'fcn' : __fcn,
      'cn0' : __cn0,
    }, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.sid = res['sid']
    self.fcn = res['fcn']
    self.cn0 = res['cn0']
    return res, off, length
  
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
    o_0 = offset
    o_1, (__states, offset, length) = offset, get_array(TrackingChannelState.parse_members)(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    return {
      'states' : __states,
    }, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.states = res['states']
    return res, off, length
  
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
    o_0 = offset
    o_1, (__mesid, offset, length) = offset, GnssSignal.parse_members(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__cn0, offset, length) = offset, get_u8(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    return {
      'mesid' : __mesid,
      'cn0' : __cn0,
    }, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.mesid = res['mesid']
    self.cn0 = res['cn0']
    return res, off, length
  
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
    o_0 = offset
    o_1, (__states, offset, length) = offset, get_array(MeasurementState.parse_members)(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    return {
      'states' : __states,
    }, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.states = res['states']
    return res, off, length
  
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
    o_0 = offset
    o_1, (__I, offset, length) = offset, get_s32(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__Q, offset, length) = offset, get_s32(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    return {
      'I' : __I,
      'Q' : __Q,
    }, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.I = res['I']
    self.Q = res['Q']
    return res, off, length
  
SBP_MSG_TRACKING_IQ = 0x002C
class MsgTrackingIq(SBP):
  """SBP class for message MSG_TRACKING_IQ (0x002C).

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
    o_0 = offset
    o_1, (__channel, offset, length) = offset, get_u8(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__sid, offset, length) = offset, GnssSignal.parse_members(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__corrs, offset, length) = offset, get_fixed_array(get_u8, 3, 1)(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    return {
      'channel' : __channel,
      'sid' : __sid,
      'corrs' : __corrs,
    }, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.channel = res['channel']
    self.sid = res['sid']
    self.corrs = res['corrs']
    return res, off, length
  
SBP_MSG_TRACKING_IQ_DEP = 0x001C
class MsgTrackingIqDep(SBP):
  """SBP class for message MSG_TRACKING_IQ_DEP (0x001C).

  You can have MSG_TRACKING_IQ_DEP inherit its fields directly
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
    o_0 = offset
    o_1, (__channel, offset, length) = offset, get_u8(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__sid, offset, length) = offset, GnssSignalDep.parse_members(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__corrs, offset, length) = offset, get_fixed_array(get_u8, 3, 1)(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    return {
      'channel' : __channel,
      'sid' : __sid,
      'corrs' : __corrs,
    }, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.channel = res['channel']
    self.sid = res['sid']
    self.corrs = res['corrs']
    return res, off, length
  
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
    o_0 = offset
    o_1, (__state, offset, length) = offset, get_u8(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__prn, offset, length) = offset, get_u8(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__cn0, offset, length) = offset, get_f32(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    return {
      'state' : __state,
      'prn' : __prn,
      'cn0' : __cn0,
    }, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.state = res['state']
    self.prn = res['prn']
    self.cn0 = res['cn0']
    return res, off, length
  
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
    o_0 = offset
    o_1, (__states, offset, length) = offset, get_array(TrackingChannelStateDepA.parse_members)(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    return {
      'states' : __states,
    }, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.states = res['states']
    return res, off, length
  
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
    o_0 = offset
    o_1, (__state, offset, length) = offset, get_u8(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__sid, offset, length) = offset, GnssSignalDep.parse_members(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__cn0, offset, length) = offset, get_f32(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    return {
      'state' : __state,
      'sid' : __sid,
      'cn0' : __cn0,
    }, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.state = res['state']
    self.sid = res['sid']
    self.cn0 = res['cn0']
    return res, off, length
  
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
    o_0 = offset
    o_1, (__states, offset, length) = offset, get_array(TrackingChannelStateDepB.parse_members)(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    return {
      'states' : __states,
    }, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.states = res['states']
    return res, off, length
  

msg_classes = {
  0x0021: MsgTrackingStateDetailedDepA,
  0x0011: MsgTrackingStateDetailedDep,
  0x0041: MsgTrackingState,
  0x0061: MsgMeasurementState,
  0x002C: MsgTrackingIq,
  0x001C: MsgTrackingIqDep,
  0x0016: MsgTrackingStateDepA,
  0x0013: MsgTrackingStateDepB,
}