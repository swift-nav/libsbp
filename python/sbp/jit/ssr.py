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
Precise State Space Representation (SSR) corrections format
"""

import json

import numba as nb

from sbp.jit.msg import SBP, SENDER_ID
from sbp.jit.msg import get_u8, get_u16, get_u32, get_u64
from sbp.jit.msg import get_s8, get_s16, get_s32, get_s64
from sbp.jit.msg import get_f32, get_f64, judicious_round
from sbp.jit.msg import get_string, get_fixed_string, get_setting
from sbp.jit.msg import get_array, get_fixed_array
from sbp.jit.gnss import *

# Automatically generated from piksi/yaml/swiftnav/sbp/ssr.yaml with generate.py.
# Please do not hand edit!
class CodeBiasesContent(object):
  """SBP class for message CodeBiasesContent

  You can have CodeBiasesContent inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  Code biases are to be added to pseudorange.
The corrections are conform with typical RTCMv3 MT1059 and 1065.


  """
  __slots__ = ['code',
               'value',
               ]
  @classmethod
  def parse_members(cls, buf, offset, length):
    ret = {}
    (__code, offset, length) = get_u8(buf, offset, length)
    ret['code'] = __code
    (__value, offset, length) = get_s16(buf, offset, length)
    ret['value'] = __value
    return ret, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.code = res['code']
    self.value = res['value']
    return res, off, length

  @classmethod
  def _payload_size(self):
    ret = 0
    # code: u8
    ret += 1
    # value: s16
    ret += 2
    return ret
  
class PhaseBiasesContent(object):
  """SBP class for message PhaseBiasesContent

  You can have PhaseBiasesContent inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  Phase biases are to be added to carrier phase measurements.
The corrections are conform with typical RTCMv3 MT1059 and 1065.


  """
  __slots__ = ['code',
               'integer_indicator',
               'widelane_integer_indicator',
               'discontinuity_counter',
               'bias',
               ]
  @classmethod
  def parse_members(cls, buf, offset, length):
    ret = {}
    (__code, offset, length) = get_u8(buf, offset, length)
    ret['code'] = __code
    (__integer_indicator, offset, length) = get_u8(buf, offset, length)
    ret['integer_indicator'] = __integer_indicator
    (__widelane_integer_indicator, offset, length) = get_u8(buf, offset, length)
    ret['widelane_integer_indicator'] = __widelane_integer_indicator
    (__discontinuity_counter, offset, length) = get_u8(buf, offset, length)
    ret['discontinuity_counter'] = __discontinuity_counter
    (__bias, offset, length) = get_s32(buf, offset, length)
    ret['bias'] = __bias
    return ret, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.code = res['code']
    self.integer_indicator = res['integer_indicator']
    self.widelane_integer_indicator = res['widelane_integer_indicator']
    self.discontinuity_counter = res['discontinuity_counter']
    self.bias = res['bias']
    return res, off, length

  @classmethod
  def _payload_size(self):
    ret = 0
    # code: u8
    ret += 1
    # integer_indicator: u8
    ret += 1
    # widelane_integer_indicator: u8
    ret += 1
    # discontinuity_counter: u8
    ret += 1
    # bias: s32
    ret += 4
    return ret
  
SBP_MSG_SSR_ORBIT_CLOCK = 0x05DD
class MsgSsrOrbitClock(SBP):
  """SBP class for message MSG_SSR_ORBIT_CLOCK (0x05DD).

  You can have MSG_SSR_ORBIT_CLOCK inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  The precise orbit and clock correction message is 
to be applied as a delta correction to broadcast 
ephemeris and is typically an equivalent to the 1060
and 1066 RTCM message types


  """
  __slots__ = ['time',
               'sid',
               'update_interval',
               'iod_ssr',
               'iod',
               'radial',
               'along',
               'cross',
               'dot_radial',
               'dot_along',
               'dot_cross',
               'c0',
               'c1',
               'c2',
               ]
  @classmethod
  def parse_members(cls, buf, offset, length):
    ret = {}
    (__time, offset, length) = GPSTimeSec.parse_members(buf, offset, length)
    ret['time'] = __time
    (__sid, offset, length) = GnssSignal.parse_members(buf, offset, length)
    ret['sid'] = __sid
    (__update_interval, offset, length) = get_u8(buf, offset, length)
    ret['update_interval'] = __update_interval
    (__iod_ssr, offset, length) = get_u8(buf, offset, length)
    ret['iod_ssr'] = __iod_ssr
    (__iod, offset, length) = get_u32(buf, offset, length)
    ret['iod'] = __iod
    (__radial, offset, length) = get_s32(buf, offset, length)
    ret['radial'] = __radial
    (__along, offset, length) = get_s32(buf, offset, length)
    ret['along'] = __along
    (__cross, offset, length) = get_s32(buf, offset, length)
    ret['cross'] = __cross
    (__dot_radial, offset, length) = get_s32(buf, offset, length)
    ret['dot_radial'] = __dot_radial
    (__dot_along, offset, length) = get_s32(buf, offset, length)
    ret['dot_along'] = __dot_along
    (__dot_cross, offset, length) = get_s32(buf, offset, length)
    ret['dot_cross'] = __dot_cross
    (__c0, offset, length) = get_s32(buf, offset, length)
    ret['c0'] = __c0
    (__c1, offset, length) = get_s32(buf, offset, length)
    ret['c1'] = __c1
    (__c2, offset, length) = get_s32(buf, offset, length)
    ret['c2'] = __c2
    return ret, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.time = res['time']
    self.sid = res['sid']
    self.update_interval = res['update_interval']
    self.iod_ssr = res['iod_ssr']
    self.iod = res['iod']
    self.radial = res['radial']
    self.along = res['along']
    self.cross = res['cross']
    self.dot_radial = res['dot_radial']
    self.dot_along = res['dot_along']
    self.dot_cross = res['dot_cross']
    self.c0 = res['c0']
    self.c1 = res['c1']
    self.c2 = res['c2']
    return res, off, length

  @classmethod
  def _payload_size(self):
    ret = 0
    # time: GPSTimeSec
    ret += GPSTimeSec._payload_size()
    # sid: GnssSignal
    ret += GnssSignal._payload_size()
    # update_interval: u8
    ret += 1
    # iod_ssr: u8
    ret += 1
    # iod: u32
    ret += 4
    # radial: s32
    ret += 4
    # along: s32
    ret += 4
    # cross: s32
    ret += 4
    # dot_radial: s32
    ret += 4
    # dot_along: s32
    ret += 4
    # dot_cross: s32
    ret += 4
    # c0: s32
    ret += 4
    # c1: s32
    ret += 4
    # c2: s32
    ret += 4
    return ret
  
SBP_MSG_SSR_ORBIT_CLOCK_DEP_A = 0x05DC
class MsgSsrOrbitClockDepA(SBP):
  """SBP class for message MSG_SSR_ORBIT_CLOCK_DEP_A (0x05DC).

  You can have MSG_SSR_ORBIT_CLOCK_DEP_A inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  The precise orbit and clock correction message is 
to be applied as a delta correction to broadcast 
ephemeris and is typically an equivalent to the 1060
and 1066 RTCM message types


  """
  __slots__ = ['time',
               'sid',
               'update_interval',
               'iod_ssr',
               'iod',
               'radial',
               'along',
               'cross',
               'dot_radial',
               'dot_along',
               'dot_cross',
               'c0',
               'c1',
               'c2',
               ]
  @classmethod
  def parse_members(cls, buf, offset, length):
    ret = {}
    (__time, offset, length) = GPSTimeSec.parse_members(buf, offset, length)
    ret['time'] = __time
    (__sid, offset, length) = GnssSignal.parse_members(buf, offset, length)
    ret['sid'] = __sid
    (__update_interval, offset, length) = get_u8(buf, offset, length)
    ret['update_interval'] = __update_interval
    (__iod_ssr, offset, length) = get_u8(buf, offset, length)
    ret['iod_ssr'] = __iod_ssr
    (__iod, offset, length) = get_u8(buf, offset, length)
    ret['iod'] = __iod
    (__radial, offset, length) = get_s32(buf, offset, length)
    ret['radial'] = __radial
    (__along, offset, length) = get_s32(buf, offset, length)
    ret['along'] = __along
    (__cross, offset, length) = get_s32(buf, offset, length)
    ret['cross'] = __cross
    (__dot_radial, offset, length) = get_s32(buf, offset, length)
    ret['dot_radial'] = __dot_radial
    (__dot_along, offset, length) = get_s32(buf, offset, length)
    ret['dot_along'] = __dot_along
    (__dot_cross, offset, length) = get_s32(buf, offset, length)
    ret['dot_cross'] = __dot_cross
    (__c0, offset, length) = get_s32(buf, offset, length)
    ret['c0'] = __c0
    (__c1, offset, length) = get_s32(buf, offset, length)
    ret['c1'] = __c1
    (__c2, offset, length) = get_s32(buf, offset, length)
    ret['c2'] = __c2
    return ret, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.time = res['time']
    self.sid = res['sid']
    self.update_interval = res['update_interval']
    self.iod_ssr = res['iod_ssr']
    self.iod = res['iod']
    self.radial = res['radial']
    self.along = res['along']
    self.cross = res['cross']
    self.dot_radial = res['dot_radial']
    self.dot_along = res['dot_along']
    self.dot_cross = res['dot_cross']
    self.c0 = res['c0']
    self.c1 = res['c1']
    self.c2 = res['c2']
    return res, off, length

  @classmethod
  def _payload_size(self):
    ret = 0
    # time: GPSTimeSec
    ret += GPSTimeSec._payload_size()
    # sid: GnssSignal
    ret += GnssSignal._payload_size()
    # update_interval: u8
    ret += 1
    # iod_ssr: u8
    ret += 1
    # iod: u8
    ret += 1
    # radial: s32
    ret += 4
    # along: s32
    ret += 4
    # cross: s32
    ret += 4
    # dot_radial: s32
    ret += 4
    # dot_along: s32
    ret += 4
    # dot_cross: s32
    ret += 4
    # c0: s32
    ret += 4
    # c1: s32
    ret += 4
    # c2: s32
    ret += 4
    return ret
  
SBP_MSG_SSR_CODE_BIASES = 0x05E1
class MsgSsrCodeBiases(SBP):
  """SBP class for message MSG_SSR_CODE_BIASES (0x05E1).

  You can have MSG_SSR_CODE_BIASES inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  The precise code biases message is to be added
to the pseudorange of the corresponding signal
to get corrected pseudorange. It is typically 
an equivalent to the 1059 and 1065 RTCM message types


  """
  __slots__ = ['time',
               'sid',
               'update_interval',
               'iod_ssr',
               'biases',
               ]
  @classmethod
  def parse_members(cls, buf, offset, length):
    ret = {}
    (__time, offset, length) = GPSTimeSec.parse_members(buf, offset, length)
    ret['time'] = __time
    (__sid, offset, length) = GnssSignal.parse_members(buf, offset, length)
    ret['sid'] = __sid
    (__update_interval, offset, length) = get_u8(buf, offset, length)
    ret['update_interval'] = __update_interval
    (__iod_ssr, offset, length) = get_u8(buf, offset, length)
    ret['iod_ssr'] = __iod_ssr
    (__biases, offset, length) = get_array(CodeBiasesContent.parse_members)(buf, offset, length)
    ret['biases'] = __biases
    return ret, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.time = res['time']
    self.sid = res['sid']
    self.update_interval = res['update_interval']
    self.iod_ssr = res['iod_ssr']
    self.biases = res['biases']
    return res, off, length

  @classmethod
  def _payload_size(self):
    ret = 0
    # time: GPSTimeSec
    ret += GPSTimeSec._payload_size()
    # sid: GnssSignal
    ret += GnssSignal._payload_size()
    # update_interval: u8
    ret += 1
    # iod_ssr: u8
    ret += 1
    # biases: array of CodeBiasesContent
    ret += 247
    return ret
  
SBP_MSG_SSR_PHASE_BIASES = 0x05E6
class MsgSsrPhaseBiases(SBP):
  """SBP class for message MSG_SSR_PHASE_BIASES (0x05E6).

  You can have MSG_SSR_PHASE_BIASES inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  The precise phase biases message contains the biases
to be added to the carrier phase of the corresponding
signal to get corrected carrier phase measurement, as 
well as the satellite yaw angle to be applied to compute 
the phase wind-up correction. 
It is typically an equivalent to the 1265 RTCM message types


  """
  __slots__ = ['time',
               'sid',
               'update_interval',
               'iod_ssr',
               'dispersive_bias',
               'mw_consistency',
               'yaw',
               'yaw_rate',
               'biases',
               ]
  @classmethod
  def parse_members(cls, buf, offset, length):
    ret = {}
    (__time, offset, length) = GPSTimeSec.parse_members(buf, offset, length)
    ret['time'] = __time
    (__sid, offset, length) = GnssSignal.parse_members(buf, offset, length)
    ret['sid'] = __sid
    (__update_interval, offset, length) = get_u8(buf, offset, length)
    ret['update_interval'] = __update_interval
    (__iod_ssr, offset, length) = get_u8(buf, offset, length)
    ret['iod_ssr'] = __iod_ssr
    (__dispersive_bias, offset, length) = get_u8(buf, offset, length)
    ret['dispersive_bias'] = __dispersive_bias
    (__mw_consistency, offset, length) = get_u8(buf, offset, length)
    ret['mw_consistency'] = __mw_consistency
    (__yaw, offset, length) = get_u16(buf, offset, length)
    ret['yaw'] = __yaw
    (__yaw_rate, offset, length) = get_s8(buf, offset, length)
    ret['yaw_rate'] = __yaw_rate
    (__biases, offset, length) = get_array(PhaseBiasesContent.parse_members)(buf, offset, length)
    ret['biases'] = __biases
    return ret, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.time = res['time']
    self.sid = res['sid']
    self.update_interval = res['update_interval']
    self.iod_ssr = res['iod_ssr']
    self.dispersive_bias = res['dispersive_bias']
    self.mw_consistency = res['mw_consistency']
    self.yaw = res['yaw']
    self.yaw_rate = res['yaw_rate']
    self.biases = res['biases']
    return res, off, length

  @classmethod
  def _payload_size(self):
    ret = 0
    # time: GPSTimeSec
    ret += GPSTimeSec._payload_size()
    # sid: GnssSignal
    ret += GnssSignal._payload_size()
    # update_interval: u8
    ret += 1
    # iod_ssr: u8
    ret += 1
    # dispersive_bias: u8
    ret += 1
    # mw_consistency: u8
    ret += 1
    # yaw: u16
    ret += 2
    # yaw_rate: s8
    ret += 1
    # biases: array of PhaseBiasesContent
    ret += 247
    return ret
  

msg_classes = {
  0x05DD: MsgSsrOrbitClock,
  0x05DC: MsgSsrOrbitClockDepA,
  0x05E1: MsgSsrCodeBiases,
  0x05E6: MsgSsrPhaseBiases,
}