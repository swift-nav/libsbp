#!/usr/bin/env python
# Copyright (C) 2015-2018 Swift Navigation Inc.
# Contact: https://support.swiftnav.com
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

import numpy as np

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
The corrections conform with typical RTCMv3 MT1059 and 1065.


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

  
class PhaseBiasesContent(object):
  """SBP class for message PhaseBiasesContent

  You can have PhaseBiasesContent inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  Phase biases are to be added to carrier phase measurements.
The corrections conform with typical RTCMv3 MT1059 and 1065.


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

  
class STECHeader(object):
  """SBP class for message STECHeader

  You can have STECHeader inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  A full set of STEC information will likely span multiple SBP
messages, since SBP message a limited to 255 bytes.  The header
is used to tie multiple SBP messages into a sequence.


  """
  __slots__ = ['tile_set_id',
               'tile_id',
               'time',
               'num_msgs',
               'seq_num',
               'update_interval',
               'iod_atmo',
               ]
  @classmethod
  def parse_members(cls, buf, offset, length):
    ret = {}
    (__tile_set_id, offset, length) = get_u16(buf, offset, length)
    ret['tile_set_id'] = __tile_set_id
    (__tile_id, offset, length) = get_u16(buf, offset, length)
    ret['tile_id'] = __tile_id
    (__time, offset, length) = GPSTimeSec.parse_members(buf, offset, length)
    ret['time'] = __time
    (__num_msgs, offset, length) = get_u8(buf, offset, length)
    ret['num_msgs'] = __num_msgs
    (__seq_num, offset, length) = get_u8(buf, offset, length)
    ret['seq_num'] = __seq_num
    (__update_interval, offset, length) = get_u8(buf, offset, length)
    ret['update_interval'] = __update_interval
    (__iod_atmo, offset, length) = get_u8(buf, offset, length)
    ret['iod_atmo'] = __iod_atmo
    return ret, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.tile_set_id = res['tile_set_id']
    self.tile_id = res['tile_id']
    self.time = res['time']
    self.num_msgs = res['num_msgs']
    self.seq_num = res['seq_num']
    self.update_interval = res['update_interval']
    self.iod_atmo = res['iod_atmo']
    return res, off, length

  
class GriddedCorrectionHeader(object):
  """SBP class for message GriddedCorrectionHeader

  You can have GriddedCorrectionHeader inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  The LPP message contains nested variable length arrays
which are not suppported in SBP, so each grid point will
be identified by the index.


  """
  __slots__ = ['tile_set_id',
               'tile_id',
               'time',
               'num_msgs',
               'seq_num',
               'update_interval',
               'iod_atmo',
               'tropo_quality_indicator',
               ]
  @classmethod
  def parse_members(cls, buf, offset, length):
    ret = {}
    (__tile_set_id, offset, length) = get_u16(buf, offset, length)
    ret['tile_set_id'] = __tile_set_id
    (__tile_id, offset, length) = get_u16(buf, offset, length)
    ret['tile_id'] = __tile_id
    (__time, offset, length) = GPSTimeSec.parse_members(buf, offset, length)
    ret['time'] = __time
    (__num_msgs, offset, length) = get_u16(buf, offset, length)
    ret['num_msgs'] = __num_msgs
    (__seq_num, offset, length) = get_u16(buf, offset, length)
    ret['seq_num'] = __seq_num
    (__update_interval, offset, length) = get_u8(buf, offset, length)
    ret['update_interval'] = __update_interval
    (__iod_atmo, offset, length) = get_u8(buf, offset, length)
    ret['iod_atmo'] = __iod_atmo
    (__tropo_quality_indicator, offset, length) = get_u8(buf, offset, length)
    ret['tropo_quality_indicator'] = __tropo_quality_indicator
    return ret, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.tile_set_id = res['tile_set_id']
    self.tile_id = res['tile_id']
    self.time = res['time']
    self.num_msgs = res['num_msgs']
    self.seq_num = res['seq_num']
    self.update_interval = res['update_interval']
    self.iod_atmo = res['iod_atmo']
    self.tropo_quality_indicator = res['tropo_quality_indicator']
    return res, off, length

  
class STECSatElement(object):
  """SBP class for message STECSatElement

  You can have STECSatElement inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  STEC polynomial for the given satellite.

  """
  __slots__ = ['sv_id',
               'stec_quality_indicator',
               'stec_coeff',
               ]
  @classmethod
  def parse_members(cls, buf, offset, length):
    ret = {}
    (__sv_id, offset, length) = SvId.parse_members(buf, offset, length)
    ret['sv_id'] = __sv_id
    (__stec_quality_indicator, offset, length) = get_u8(buf, offset, length)
    ret['stec_quality_indicator'] = __stec_quality_indicator
    (__stec_coeff, offset, length) = get_fixed_array(get_s16, 4, 2)(buf, offset, length)
    ret['stec_coeff'] = __stec_coeff
    return ret, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.sv_id = res['sv_id']
    self.stec_quality_indicator = res['stec_quality_indicator']
    self.stec_coeff = res['stec_coeff']
    return res, off, length

  
class TroposphericDelayCorrectionNoStd(object):
  """SBP class for message TroposphericDelayCorrectionNoStd

  You can have TroposphericDelayCorrectionNoStd inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  Troposphere vertical delays at the grid point.


  """
  __slots__ = ['hydro',
               'wet',
               ]
  @classmethod
  def parse_members(cls, buf, offset, length):
    ret = {}
    (__hydro, offset, length) = get_s16(buf, offset, length)
    ret['hydro'] = __hydro
    (__wet, offset, length) = get_s8(buf, offset, length)
    ret['wet'] = __wet
    return ret, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.hydro = res['hydro']
    self.wet = res['wet']
    return res, off, length

  
class TroposphericDelayCorrection(object):
  """SBP class for message TroposphericDelayCorrection

  You can have TroposphericDelayCorrection inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  Troposphere vertical delays (mean and standard deviation) at the grid
point.


  """
  __slots__ = ['hydro',
               'wet',
               'stddev',
               ]
  @classmethod
  def parse_members(cls, buf, offset, length):
    ret = {}
    (__hydro, offset, length) = get_s16(buf, offset, length)
    ret['hydro'] = __hydro
    (__wet, offset, length) = get_s8(buf, offset, length)
    ret['wet'] = __wet
    (__stddev, offset, length) = get_u8(buf, offset, length)
    ret['stddev'] = __stddev
    return ret, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.hydro = res['hydro']
    self.wet = res['wet']
    self.stddev = res['stddev']
    return res, off, length

  
class STECResidualNoStd(object):
  """SBP class for message STECResidualNoStd

  You can have STECResidualNoStd inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  STEC residual for the given satellite at the grid point.

  """
  __slots__ = ['sv_id',
               'residual',
               ]
  @classmethod
  def parse_members(cls, buf, offset, length):
    ret = {}
    (__sv_id, offset, length) = SvId.parse_members(buf, offset, length)
    ret['sv_id'] = __sv_id
    (__residual, offset, length) = get_s16(buf, offset, length)
    ret['residual'] = __residual
    return ret, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.sv_id = res['sv_id']
    self.residual = res['residual']
    return res, off, length

  
class STECResidual(object):
  """SBP class for message STECResidual

  You can have STECResidual inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  STEC residual (mean and standard deviation) for the given satellite
at the grid point,


  """
  __slots__ = ['sv_id',
               'residual',
               'stddev',
               ]
  @classmethod
  def parse_members(cls, buf, offset, length):
    ret = {}
    (__sv_id, offset, length) = SvId.parse_members(buf, offset, length)
    ret['sv_id'] = __sv_id
    (__residual, offset, length) = get_s16(buf, offset, length)
    ret['residual'] = __residual
    (__stddev, offset, length) = get_u8(buf, offset, length)
    ret['stddev'] = __stddev
    return ret, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.sv_id = res['sv_id']
    self.residual = res['residual']
    self.stddev = res['stddev']
    return res, off, length

  
class GridElementNoStd(object):
  """SBP class for message GridElementNoStd

  You can have GridElementNoStd inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  Contains one tropo delay, plus STEC residuals for each satellite at the
grid point.


  """
  __slots__ = ['index',
               'tropo_delay_correction',
               'stec_residuals',
               ]
  @classmethod
  def parse_members(cls, buf, offset, length):
    ret = {}
    (__index, offset, length) = get_u16(buf, offset, length)
    ret['index'] = __index
    (__tropo_delay_correction, offset, length) = TroposphericDelayCorrectionNoStd.parse_members(buf, offset, length)
    ret['tropo_delay_correction'] = __tropo_delay_correction
    (__stec_residuals, offset, length) = get_array(STECResidualNoStd.parse_members)(buf, offset, length)
    ret['stec_residuals'] = __stec_residuals
    return ret, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.index = res['index']
    self.tropo_delay_correction = res['tropo_delay_correction']
    self.stec_residuals = res['stec_residuals']
    return res, off, length

  
class GridElement(object):
  """SBP class for message GridElement

  You can have GridElement inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  Contains one tropo delay (mean and stddev), plus STEC residuals (mean and
stddev) for each satellite at the grid point.


  """
  __slots__ = ['index',
               'tropo_delay_correction',
               'stec_residuals',
               ]
  @classmethod
  def parse_members(cls, buf, offset, length):
    ret = {}
    (__index, offset, length) = get_u16(buf, offset, length)
    ret['index'] = __index
    (__tropo_delay_correction, offset, length) = TroposphericDelayCorrection.parse_members(buf, offset, length)
    ret['tropo_delay_correction'] = __tropo_delay_correction
    (__stec_residuals, offset, length) = get_array(STECResidual.parse_members)(buf, offset, length)
    ret['stec_residuals'] = __stec_residuals
    return ret, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.index = res['index']
    self.tropo_delay_correction = res['tropo_delay_correction']
    self.stec_residuals = res['stec_residuals']
    return res, off, length

  
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

  
SBP_MSG_SSR_STEC_CORRECTION = 0x05FB
class MsgSsrStecCorrection(SBP):
  """SBP class for message MSG_SSR_STEC_CORRECTION (0x05FB).

  You can have MSG_SSR_STEC_CORRECTION inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  The Slant Total Electron Content per space vehicle, given as polynomial
approximation for a given tile. This should be combined with the
MSG_SSR_GRIDDED_CORRECTION message to get the state space representation
of the atmospheric delay.

It is typically equivalent to the QZSS CLAS Sub Type 8 messages.


  """
  __slots__ = ['header',
               'stec_sat_list',
               ]
  @classmethod
  def parse_members(cls, buf, offset, length):
    ret = {}
    (__header, offset, length) = STECHeader.parse_members(buf, offset, length)
    ret['header'] = __header
    (__stec_sat_list, offset, length) = get_array(STECSatElement.parse_members)(buf, offset, length)
    ret['stec_sat_list'] = __stec_sat_list
    return ret, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.header = res['header']
    self.stec_sat_list = res['stec_sat_list']
    return res, off, length

  
SBP_MSG_SSR_GRIDDED_CORRECTION = 0x05FC
class MsgSsrGriddedCorrection(SBP):
  """SBP class for message MSG_SSR_GRIDDED_CORRECTION (0x05FC).

  You can have MSG_SSR_GRIDDED_CORRECTION inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  STEC residuals are per space vehicle, troposphere is not.

It is typically equivalent to the QZSS CLAS Sub Type 9 messages


  """
  __slots__ = ['header',
               'element',
               ]
  @classmethod
  def parse_members(cls, buf, offset, length):
    ret = {}
    (__header, offset, length) = GriddedCorrectionHeader.parse_members(buf, offset, length)
    ret['header'] = __header
    (__element, offset, length) = GridElement.parse_members(buf, offset, length)
    ret['element'] = __element
    return ret, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.header = res['header']
    self.element = res['element']
    return res, off, length

  
SBP_MSG_SSR_TILE_DEFINITION = 0x05F6
class MsgSsrTileDefinition(SBP):
  """SBP class for message MSG_SSR_TILE_DEFINITION (0x05F6).

  You can have MSG_SSR_TILE_DEFINITION inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  Provides the correction point coordinates for the atmospheric correction
values in the MSG_SSR_STEC_CORRECTION and MSG_SSR_GRIDDED_CORRECTION
messages.

Based on ETSI TS 137 355 V16.1.0 (LTE Positioning Protocol) information
element GNSS-SSR-CorrectionPoints. SBP only supports gridded arrays of
correction points, not lists of points.


  """
  __slots__ = ['tile_set_id',
               'tile_id',
               'corner_nw_lat',
               'corner_nw_lon',
               'spacing_lat',
               'spacing_lon',
               'rows',
               'cols',
               'bitmask',
               ]
  @classmethod
  def parse_members(cls, buf, offset, length):
    ret = {}
    (__tile_set_id, offset, length) = get_u16(buf, offset, length)
    ret['tile_set_id'] = __tile_set_id
    (__tile_id, offset, length) = get_u16(buf, offset, length)
    ret['tile_id'] = __tile_id
    (__corner_nw_lat, offset, length) = get_s16(buf, offset, length)
    ret['corner_nw_lat'] = __corner_nw_lat
    (__corner_nw_lon, offset, length) = get_s16(buf, offset, length)
    ret['corner_nw_lon'] = __corner_nw_lon
    (__spacing_lat, offset, length) = get_u16(buf, offset, length)
    ret['spacing_lat'] = __spacing_lat
    (__spacing_lon, offset, length) = get_u16(buf, offset, length)
    ret['spacing_lon'] = __spacing_lon
    (__rows, offset, length) = get_u16(buf, offset, length)
    ret['rows'] = __rows
    (__cols, offset, length) = get_u16(buf, offset, length)
    ret['cols'] = __cols
    (__bitmask, offset, length) = get_u64(buf, offset, length)
    ret['bitmask'] = __bitmask
    return ret, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.tile_set_id = res['tile_set_id']
    self.tile_id = res['tile_id']
    self.corner_nw_lat = res['corner_nw_lat']
    self.corner_nw_lon = res['corner_nw_lon']
    self.spacing_lat = res['spacing_lat']
    self.spacing_lon = res['spacing_lon']
    self.rows = res['rows']
    self.cols = res['cols']
    self.bitmask = res['bitmask']
    return res, off, length

  
SBP_MSG_SSR_ORBIT_CLOCK_DEP_A = 0x05DC
class MsgSsrOrbitClockDepA(SBP):
  """SBP class for message MSG_SSR_ORBIT_CLOCK_DEP_A (0x05DC).

  You can have MSG_SSR_ORBIT_CLOCK_DEP_A inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  

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

  
class STECHeaderDepA(object):
  """SBP class for message STECHeaderDepA

  You can have STECHeaderDepA inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  A full set of STEC information will likely span multiple SBP
messages, since SBP message a limited to 255 bytes.  The header
is used to tie multiple SBP messages into a sequence.


  """
  __slots__ = ['time',
               'num_msgs',
               'seq_num',
               'update_interval',
               'iod_atmo',
               ]
  @classmethod
  def parse_members(cls, buf, offset, length):
    ret = {}
    (__time, offset, length) = GPSTimeSec.parse_members(buf, offset, length)
    ret['time'] = __time
    (__num_msgs, offset, length) = get_u8(buf, offset, length)
    ret['num_msgs'] = __num_msgs
    (__seq_num, offset, length) = get_u8(buf, offset, length)
    ret['seq_num'] = __seq_num
    (__update_interval, offset, length) = get_u8(buf, offset, length)
    ret['update_interval'] = __update_interval
    (__iod_atmo, offset, length) = get_u8(buf, offset, length)
    ret['iod_atmo'] = __iod_atmo
    return ret, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.time = res['time']
    self.num_msgs = res['num_msgs']
    self.seq_num = res['seq_num']
    self.update_interval = res['update_interval']
    self.iod_atmo = res['iod_atmo']
    return res, off, length

  
class GriddedCorrectionHeaderDepA(object):
  """SBP class for message GriddedCorrectionHeaderDepA

  You can have GriddedCorrectionHeaderDepA inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  The 3GPP message contains nested variable length arrays
which are not suppported in SBP, so each grid point will
be identified by the index.


  """
  __slots__ = ['time',
               'num_msgs',
               'seq_num',
               'update_interval',
               'iod_atmo',
               'tropo_quality_indicator',
               ]
  @classmethod
  def parse_members(cls, buf, offset, length):
    ret = {}
    (__time, offset, length) = GPSTimeSec.parse_members(buf, offset, length)
    ret['time'] = __time
    (__num_msgs, offset, length) = get_u16(buf, offset, length)
    ret['num_msgs'] = __num_msgs
    (__seq_num, offset, length) = get_u16(buf, offset, length)
    ret['seq_num'] = __seq_num
    (__update_interval, offset, length) = get_u8(buf, offset, length)
    ret['update_interval'] = __update_interval
    (__iod_atmo, offset, length) = get_u8(buf, offset, length)
    ret['iod_atmo'] = __iod_atmo
    (__tropo_quality_indicator, offset, length) = get_u8(buf, offset, length)
    ret['tropo_quality_indicator'] = __tropo_quality_indicator
    return ret, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.time = res['time']
    self.num_msgs = res['num_msgs']
    self.seq_num = res['seq_num']
    self.update_interval = res['update_interval']
    self.iod_atmo = res['iod_atmo']
    self.tropo_quality_indicator = res['tropo_quality_indicator']
    return res, off, length

  
class GridDefinitionHeaderDepA(object):
  """SBP class for message GridDefinitionHeaderDepA

  You can have GridDefinitionHeaderDepA inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  Defines the grid for MSG_SSR_GRIDDED_CORRECTION messages.
Also includes an RLE encoded validity list.


  """
  __slots__ = ['region_size_inverse',
               'area_width',
               'lat_nw_corner_enc',
               'lon_nw_corner_enc',
               'num_msgs',
               'seq_num',
               ]
  @classmethod
  def parse_members(cls, buf, offset, length):
    ret = {}
    (__region_size_inverse, offset, length) = get_u8(buf, offset, length)
    ret['region_size_inverse'] = __region_size_inverse
    (__area_width, offset, length) = get_u16(buf, offset, length)
    ret['area_width'] = __area_width
    (__lat_nw_corner_enc, offset, length) = get_u16(buf, offset, length)
    ret['lat_nw_corner_enc'] = __lat_nw_corner_enc
    (__lon_nw_corner_enc, offset, length) = get_u16(buf, offset, length)
    ret['lon_nw_corner_enc'] = __lon_nw_corner_enc
    (__num_msgs, offset, length) = get_u8(buf, offset, length)
    ret['num_msgs'] = __num_msgs
    (__seq_num, offset, length) = get_u8(buf, offset, length)
    ret['seq_num'] = __seq_num
    return ret, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.region_size_inverse = res['region_size_inverse']
    self.area_width = res['area_width']
    self.lat_nw_corner_enc = res['lat_nw_corner_enc']
    self.lon_nw_corner_enc = res['lon_nw_corner_enc']
    self.num_msgs = res['num_msgs']
    self.seq_num = res['seq_num']
    return res, off, length

  
SBP_MSG_SSR_STEC_CORRECTION_DEP_A = 0x05EB
class MsgSsrStecCorrectionDepA(SBP):
  """SBP class for message MSG_SSR_STEC_CORRECTION_DEP_A (0x05EB).

  You can have MSG_SSR_STEC_CORRECTION_DEP_A inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  

  """
  __slots__ = ['header',
               'stec_sat_list',
               ]
  @classmethod
  def parse_members(cls, buf, offset, length):
    ret = {}
    (__header, offset, length) = STECHeaderDepA.parse_members(buf, offset, length)
    ret['header'] = __header
    (__stec_sat_list, offset, length) = get_array(STECSatElement.parse_members)(buf, offset, length)
    ret['stec_sat_list'] = __stec_sat_list
    return ret, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.header = res['header']
    self.stec_sat_list = res['stec_sat_list']
    return res, off, length

  
SBP_MSG_SSR_GRIDDED_CORRECTION_NO_STD_DEP_A = 0x05F0
class MsgSsrGriddedCorrectionNoStdDepA(SBP):
  """SBP class for message MSG_SSR_GRIDDED_CORRECTION_NO_STD_DEP_A (0x05F0).

  You can have MSG_SSR_GRIDDED_CORRECTION_NO_STD_DEP_A inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  

  """
  __slots__ = ['header',
               'element',
               ]
  @classmethod
  def parse_members(cls, buf, offset, length):
    ret = {}
    (__header, offset, length) = GriddedCorrectionHeaderDepA.parse_members(buf, offset, length)
    ret['header'] = __header
    (__element, offset, length) = GridElementNoStd.parse_members(buf, offset, length)
    ret['element'] = __element
    return ret, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.header = res['header']
    self.element = res['element']
    return res, off, length

  
SBP_MSG_SSR_GRIDDED_CORRECTION_DEP_A = 0x05FA
class MsgSsrGriddedCorrectionDepA(SBP):
  """SBP class for message MSG_SSR_GRIDDED_CORRECTION_DEP_A (0x05FA).

  You can have MSG_SSR_GRIDDED_CORRECTION_DEP_A inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  

  """
  __slots__ = ['header',
               'element',
               ]
  @classmethod
  def parse_members(cls, buf, offset, length):
    ret = {}
    (__header, offset, length) = GriddedCorrectionHeaderDepA.parse_members(buf, offset, length)
    ret['header'] = __header
    (__element, offset, length) = GridElement.parse_members(buf, offset, length)
    ret['element'] = __element
    return ret, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.header = res['header']
    self.element = res['element']
    return res, off, length

  
SBP_MSG_SSR_GRID_DEFINITION_DEP_A = 0x05F5
class MsgSsrGridDefinitionDepA(SBP):
  """SBP class for message MSG_SSR_GRID_DEFINITION_DEP_A (0x05F5).

  You can have MSG_SSR_GRID_DEFINITION_DEP_A inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  

  """
  __slots__ = ['header',
               'rle_list',
               ]
  @classmethod
  def parse_members(cls, buf, offset, length):
    ret = {}
    (__header, offset, length) = GridDefinitionHeaderDepA.parse_members(buf, offset, length)
    ret['header'] = __header
    (__rle_list, offset, length) = get_array(get_u8)(buf, offset, length)
    ret['rle_list'] = __rle_list
    return ret, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.header = res['header']
    self.rle_list = res['rle_list']
    return res, off, length

  

msg_classes = {
  0x05DD: MsgSsrOrbitClock,
  0x05E1: MsgSsrCodeBiases,
  0x05E6: MsgSsrPhaseBiases,
  0x05FB: MsgSsrStecCorrection,
  0x05FC: MsgSsrGriddedCorrection,
  0x05F6: MsgSsrTileDefinition,
  0x05DC: MsgSsrOrbitClockDepA,
  0x05EB: MsgSsrStecCorrectionDepA,
  0x05F0: MsgSsrGriddedCorrectionNoStdDepA,
  0x05FA: MsgSsrGriddedCorrectionDepA,
  0x05F5: MsgSsrGridDefinitionDepA,
}