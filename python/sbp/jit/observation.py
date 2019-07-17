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
Satellite observation messages from the device.
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

# Automatically generated from piksi/yaml/swiftnav/sbp/observation.yaml with generate.py.
# Please do not hand edit!
class ObservationHeader(object):
  """SBP class for message ObservationHeader

  You can have ObservationHeader inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  Header of a GNSS observation message.

  """
  __slots__ = ['t',
               'n_obs',
               ]
  @classmethod
  def parse_members(cls, buf, offset, length):
    ret = {}
    (__t, offset, length) = GPSTime.parse_members(buf, offset, length)
    ret['t'] = __t
    (__n_obs, offset, length) = get_u8(buf, offset, length)
    ret['n_obs'] = __n_obs
    return ret, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.t = res['t']
    self.n_obs = res['n_obs']
    return res, off, length

  @classmethod
  def _payload_size(self):
    ret = 0
    # t: GPSTime
    ret += GPSTime._payload_size()
    # n_obs: u8
    ret += 1
    return ret
  
class Doppler(object):
  """SBP class for message Doppler

  You can have Doppler inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  Doppler measurement in Hz represented as a 24-bit
fixed point number with Q16.8 layout, i.e. 16-bits of whole
doppler and 8-bits of fractional doppler. This doppler is defined
as positive for approaching satellites.


  """
  __slots__ = ['i',
               'f',
               ]
  @classmethod
  def parse_members(cls, buf, offset, length):
    ret = {}
    (__i, offset, length) = get_s16(buf, offset, length)
    ret['i'] = __i
    (__f, offset, length) = get_u8(buf, offset, length)
    ret['f'] = __f
    return ret, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.i = res['i']
    self.f = res['f']
    return res, off, length

  @classmethod
  def _payload_size(self):
    ret = 0
    # i: s16
    ret += 2
    # f: u8
    ret += 1
    return ret
  
class PackedObsContent(object):
  """SBP class for message PackedObsContent

  You can have PackedObsContent inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  Pseudorange and carrier phase observation for a satellite being tracked.
The observations are interoperable with 3rd party receivers and conform with
typical RTCM 3.1 message GPS/GLO observations.

Carrier phase observations are not guaranteed to be aligned to the RINEX 3
or RTCM 3.3 MSM reference signal and no 1/4 cycle adjustments are currently
peformed.


  """
  __slots__ = ['P',
               'L',
               'D',
               'cn0',
               'lock',
               'flags',
               'sid',
               ]
  @classmethod
  def parse_members(cls, buf, offset, length):
    ret = {}
    (__P, offset, length) = get_u32(buf, offset, length)
    ret['P'] = __P
    (__L, offset, length) = CarrierPhase.parse_members(buf, offset, length)
    ret['L'] = __L
    (__D, offset, length) = Doppler.parse_members(buf, offset, length)
    ret['D'] = __D
    (__cn0, offset, length) = get_u8(buf, offset, length)
    ret['cn0'] = __cn0
    (__lock, offset, length) = get_u8(buf, offset, length)
    ret['lock'] = __lock
    (__flags, offset, length) = get_u8(buf, offset, length)
    ret['flags'] = __flags
    (__sid, offset, length) = GnssSignal.parse_members(buf, offset, length)
    ret['sid'] = __sid
    return ret, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.P = res['P']
    self.L = res['L']
    self.D = res['D']
    self.cn0 = res['cn0']
    self.lock = res['lock']
    self.flags = res['flags']
    self.sid = res['sid']
    return res, off, length

  @classmethod
  def _payload_size(self):
    ret = 0
    # P: u32
    ret += 4
    # L: CarrierPhase
    ret += CarrierPhase._payload_size()
    # D: Doppler
    ret += Doppler._payload_size()
    # cn0: u8
    ret += 1
    # lock: u8
    ret += 1
    # flags: u8
    ret += 1
    # sid: GnssSignal
    ret += GnssSignal._payload_size()
    return ret
  
class PackedOsrContent(object):
  """SBP class for message PackedOsrContent

  You can have PackedOsrContent inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  Pseudorange and carrier phase network corrections for a satellite signal.


  """
  __slots__ = ['P',
               'L',
               'lock',
               'flags',
               'sid',
               'iono_std',
               'tropo_std',
               'range_std',
               ]
  @classmethod
  def parse_members(cls, buf, offset, length):
    ret = {}
    (__P, offset, length) = get_u32(buf, offset, length)
    ret['P'] = __P
    (__L, offset, length) = CarrierPhase.parse_members(buf, offset, length)
    ret['L'] = __L
    (__lock, offset, length) = get_u8(buf, offset, length)
    ret['lock'] = __lock
    (__flags, offset, length) = get_u8(buf, offset, length)
    ret['flags'] = __flags
    (__sid, offset, length) = GnssSignal.parse_members(buf, offset, length)
    ret['sid'] = __sid
    (__iono_std, offset, length) = get_u16(buf, offset, length)
    ret['iono_std'] = __iono_std
    (__tropo_std, offset, length) = get_u16(buf, offset, length)
    ret['tropo_std'] = __tropo_std
    (__range_std, offset, length) = get_u16(buf, offset, length)
    ret['range_std'] = __range_std
    return ret, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.P = res['P']
    self.L = res['L']
    self.lock = res['lock']
    self.flags = res['flags']
    self.sid = res['sid']
    self.iono_std = res['iono_std']
    self.tropo_std = res['tropo_std']
    self.range_std = res['range_std']
    return res, off, length

  @classmethod
  def _payload_size(self):
    ret = 0
    # P: u32
    ret += 4
    # L: CarrierPhase
    ret += CarrierPhase._payload_size()
    # lock: u8
    ret += 1
    # flags: u8
    ret += 1
    # sid: GnssSignal
    ret += GnssSignal._payload_size()
    # iono_std: u16
    ret += 2
    # tropo_std: u16
    ret += 2
    # range_std: u16
    ret += 2
    return ret
  
SBP_MSG_OBS = 0x004A
class MsgObs(SBP):
  """SBP class for message MSG_OBS (0x004A).

  You can have MSG_OBS inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  The GPS observations message reports all the raw pseudorange and
carrier phase observations for the satellites being tracked by
the device. Carrier phase observation here is represented as a
40-bit fixed point number with Q32.8 layout (i.e. 32-bits of
whole cycles and 8-bits of fractional cycles). The observations
are be interoperable with 3rd party receivers and conform
with typical RTCMv3 GNSS observations.


  """
  __slots__ = ['header',
               'obs',
               ]
  @classmethod
  def parse_members(cls, buf, offset, length):
    ret = {}
    (__header, offset, length) = ObservationHeader.parse_members(buf, offset, length)
    ret['header'] = __header
    (__obs, offset, length) = get_array(PackedObsContent.parse_members)(buf, offset, length)
    ret['obs'] = __obs
    return ret, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.header = res['header']
    self.obs = res['obs']
    return res, off, length

  @classmethod
  def _payload_size(self):
    ret = 0
    # header: ObservationHeader
    ret += ObservationHeader._payload_size()
    # obs: array of PackedObsContent
    ret += 247
    return ret
  
SBP_MSG_BASE_POS_LLH = 0x0044
class MsgBasePosLLH(SBP):
  """SBP class for message MSG_BASE_POS_LLH (0x0044).

  You can have MSG_BASE_POS_LLH inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  The base station position message is the position reported by
the base station itself. It is used for pseudo-absolute RTK
positioning, and is required to be a high-accuracy surveyed
location of the base station. Any error here will result in an
error in the pseudo-absolute position output.


  """
  __slots__ = ['lat',
               'lon',
               'height',
               ]
  @classmethod
  def parse_members(cls, buf, offset, length):
    ret = {}
    (__lat, offset, length) = get_f64(buf, offset, length)
    ret['lat'] = __lat
    (__lon, offset, length) = get_f64(buf, offset, length)
    ret['lon'] = __lon
    (__height, offset, length) = get_f64(buf, offset, length)
    ret['height'] = __height
    return ret, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.lat = res['lat']
    self.lon = res['lon']
    self.height = res['height']
    return res, off, length

  @classmethod
  def _payload_size(self):
    ret = 0
    # lat: double
    ret += 8
    # lon: double
    ret += 8
    # height: double
    ret += 8
    return ret
  
SBP_MSG_BASE_POS_ECEF = 0x0048
class MsgBasePosECEF(SBP):
  """SBP class for message MSG_BASE_POS_ECEF (0x0048).

  You can have MSG_BASE_POS_ECEF inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  The base station position message is the position reported by
the base station itself in absolute Earth Centered Earth Fixed
coordinates. It is used for pseudo-absolute RTK positioning, and
is required to be a high-accuracy surveyed location of the base
station. Any error here will result in an error in the
pseudo-absolute position output.


  """
  __slots__ = ['x',
               'y',
               'z',
               ]
  @classmethod
  def parse_members(cls, buf, offset, length):
    ret = {}
    (__x, offset, length) = get_f64(buf, offset, length)
    ret['x'] = __x
    (__y, offset, length) = get_f64(buf, offset, length)
    ret['y'] = __y
    (__z, offset, length) = get_f64(buf, offset, length)
    ret['z'] = __z
    return ret, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.x = res['x']
    self.y = res['y']
    self.z = res['z']
    return res, off, length

  @classmethod
  def _payload_size(self):
    ret = 0
    # x: double
    ret += 8
    # y: double
    ret += 8
    # z: double
    ret += 8
    return ret
  
class EphemerisCommonContent(object):
  """SBP class for message EphemerisCommonContent

  You can have EphemerisCommonContent inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  

  """
  __slots__ = ['sid',
               'toe',
               'ura',
               'fit_interval',
               'valid',
               'health_bits',
               ]
  @classmethod
  def parse_members(cls, buf, offset, length):
    ret = {}
    (__sid, offset, length) = GnssSignal.parse_members(buf, offset, length)
    ret['sid'] = __sid
    (__toe, offset, length) = GPSTimeSec.parse_members(buf, offset, length)
    ret['toe'] = __toe
    (__ura, offset, length) = get_f32(buf, offset, length)
    ret['ura'] = judicious_round(np.float32(__ura)) if SBP.judicious_rounding else __ura
    (__fit_interval, offset, length) = get_u32(buf, offset, length)
    ret['fit_interval'] = __fit_interval
    (__valid, offset, length) = get_u8(buf, offset, length)
    ret['valid'] = __valid
    (__health_bits, offset, length) = get_u8(buf, offset, length)
    ret['health_bits'] = __health_bits
    return ret, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.sid = res['sid']
    self.toe = res['toe']
    self.ura = res['ura']
    self.fit_interval = res['fit_interval']
    self.valid = res['valid']
    self.health_bits = res['health_bits']
    return res, off, length

  @classmethod
  def _payload_size(self):
    ret = 0
    # sid: GnssSignal
    ret += GnssSignal._payload_size()
    # toe: GPSTimeSec
    ret += GPSTimeSec._payload_size()
    # ura: float
    ret += 4
    # fit_interval: u32
    ret += 4
    # valid: u8
    ret += 1
    # health_bits: u8
    ret += 1
    return ret
  
class EphemerisCommonContentDepB(object):
  """SBP class for message EphemerisCommonContentDepB

  You can have EphemerisCommonContentDepB inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  

  """
  __slots__ = ['sid',
               'toe',
               'ura',
               'fit_interval',
               'valid',
               'health_bits',
               ]
  @classmethod
  def parse_members(cls, buf, offset, length):
    ret = {}
    (__sid, offset, length) = GnssSignal.parse_members(buf, offset, length)
    ret['sid'] = __sid
    (__toe, offset, length) = GPSTimeSec.parse_members(buf, offset, length)
    ret['toe'] = __toe
    (__ura, offset, length) = get_f64(buf, offset, length)
    ret['ura'] = __ura
    (__fit_interval, offset, length) = get_u32(buf, offset, length)
    ret['fit_interval'] = __fit_interval
    (__valid, offset, length) = get_u8(buf, offset, length)
    ret['valid'] = __valid
    (__health_bits, offset, length) = get_u8(buf, offset, length)
    ret['health_bits'] = __health_bits
    return ret, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.sid = res['sid']
    self.toe = res['toe']
    self.ura = res['ura']
    self.fit_interval = res['fit_interval']
    self.valid = res['valid']
    self.health_bits = res['health_bits']
    return res, off, length

  @classmethod
  def _payload_size(self):
    ret = 0
    # sid: GnssSignal
    ret += GnssSignal._payload_size()
    # toe: GPSTimeSec
    ret += GPSTimeSec._payload_size()
    # ura: double
    ret += 8
    # fit_interval: u32
    ret += 4
    # valid: u8
    ret += 1
    # health_bits: u8
    ret += 1
    return ret
  
class EphemerisCommonContentDepA(object):
  """SBP class for message EphemerisCommonContentDepA

  You can have EphemerisCommonContentDepA inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  

  """
  __slots__ = ['sid',
               'toe',
               'ura',
               'fit_interval',
               'valid',
               'health_bits',
               ]
  @classmethod
  def parse_members(cls, buf, offset, length):
    ret = {}
    (__sid, offset, length) = GnssSignalDep.parse_members(buf, offset, length)
    ret['sid'] = __sid
    (__toe, offset, length) = GPSTimeDep.parse_members(buf, offset, length)
    ret['toe'] = __toe
    (__ura, offset, length) = get_f64(buf, offset, length)
    ret['ura'] = __ura
    (__fit_interval, offset, length) = get_u32(buf, offset, length)
    ret['fit_interval'] = __fit_interval
    (__valid, offset, length) = get_u8(buf, offset, length)
    ret['valid'] = __valid
    (__health_bits, offset, length) = get_u8(buf, offset, length)
    ret['health_bits'] = __health_bits
    return ret, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.sid = res['sid']
    self.toe = res['toe']
    self.ura = res['ura']
    self.fit_interval = res['fit_interval']
    self.valid = res['valid']
    self.health_bits = res['health_bits']
    return res, off, length

  @classmethod
  def _payload_size(self):
    ret = 0
    # sid: GnssSignalDep
    ret += GnssSignalDep._payload_size()
    # toe: GPSTimeDep
    ret += GPSTimeDep._payload_size()
    # ura: double
    ret += 8
    # fit_interval: u32
    ret += 4
    # valid: u8
    ret += 1
    # health_bits: u8
    ret += 1
    return ret
  
SBP_MSG_EPHEMERIS_GPS_DEP_E = 0x0081
class MsgEphemerisGPSDepE(SBP):
  """SBP class for message MSG_EPHEMERIS_GPS_DEP_E (0x0081).

  You can have MSG_EPHEMERIS_GPS_DEP_E inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  The ephemeris message returns a set of satellite orbit
parameters that is used to calculate GPS satellite position,
velocity, and clock offset. Please see the Navstar GPS
Space Segment/Navigation user interfaces (ICD-GPS-200, Table
20-III) for more details.


  """
  __slots__ = ['common',
               'tgd',
               'c_rs',
               'c_rc',
               'c_uc',
               'c_us',
               'c_ic',
               'c_is',
               'dn',
               'm0',
               'ecc',
               'sqrta',
               'omega0',
               'omegadot',
               'w',
               'inc',
               'inc_dot',
               'af0',
               'af1',
               'af2',
               'toc',
               'iode',
               'iodc',
               ]
  @classmethod
  def parse_members(cls, buf, offset, length):
    ret = {}
    (__common, offset, length) = EphemerisCommonContentDepA.parse_members(buf, offset, length)
    ret['common'] = __common
    (__tgd, offset, length) = get_f64(buf, offset, length)
    ret['tgd'] = __tgd
    (__c_rs, offset, length) = get_f64(buf, offset, length)
    ret['c_rs'] = __c_rs
    (__c_rc, offset, length) = get_f64(buf, offset, length)
    ret['c_rc'] = __c_rc
    (__c_uc, offset, length) = get_f64(buf, offset, length)
    ret['c_uc'] = __c_uc
    (__c_us, offset, length) = get_f64(buf, offset, length)
    ret['c_us'] = __c_us
    (__c_ic, offset, length) = get_f64(buf, offset, length)
    ret['c_ic'] = __c_ic
    (__c_is, offset, length) = get_f64(buf, offset, length)
    ret['c_is'] = __c_is
    (__dn, offset, length) = get_f64(buf, offset, length)
    ret['dn'] = __dn
    (__m0, offset, length) = get_f64(buf, offset, length)
    ret['m0'] = __m0
    (__ecc, offset, length) = get_f64(buf, offset, length)
    ret['ecc'] = __ecc
    (__sqrta, offset, length) = get_f64(buf, offset, length)
    ret['sqrta'] = __sqrta
    (__omega0, offset, length) = get_f64(buf, offset, length)
    ret['omega0'] = __omega0
    (__omegadot, offset, length) = get_f64(buf, offset, length)
    ret['omegadot'] = __omegadot
    (__w, offset, length) = get_f64(buf, offset, length)
    ret['w'] = __w
    (__inc, offset, length) = get_f64(buf, offset, length)
    ret['inc'] = __inc
    (__inc_dot, offset, length) = get_f64(buf, offset, length)
    ret['inc_dot'] = __inc_dot
    (__af0, offset, length) = get_f64(buf, offset, length)
    ret['af0'] = __af0
    (__af1, offset, length) = get_f64(buf, offset, length)
    ret['af1'] = __af1
    (__af2, offset, length) = get_f64(buf, offset, length)
    ret['af2'] = __af2
    (__toc, offset, length) = GPSTimeDep.parse_members(buf, offset, length)
    ret['toc'] = __toc
    (__iode, offset, length) = get_u8(buf, offset, length)
    ret['iode'] = __iode
    (__iodc, offset, length) = get_u16(buf, offset, length)
    ret['iodc'] = __iodc
    return ret, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.common = res['common']
    self.tgd = res['tgd']
    self.c_rs = res['c_rs']
    self.c_rc = res['c_rc']
    self.c_uc = res['c_uc']
    self.c_us = res['c_us']
    self.c_ic = res['c_ic']
    self.c_is = res['c_is']
    self.dn = res['dn']
    self.m0 = res['m0']
    self.ecc = res['ecc']
    self.sqrta = res['sqrta']
    self.omega0 = res['omega0']
    self.omegadot = res['omegadot']
    self.w = res['w']
    self.inc = res['inc']
    self.inc_dot = res['inc_dot']
    self.af0 = res['af0']
    self.af1 = res['af1']
    self.af2 = res['af2']
    self.toc = res['toc']
    self.iode = res['iode']
    self.iodc = res['iodc']
    return res, off, length

  @classmethod
  def _payload_size(self):
    ret = 0
    # common: EphemerisCommonContentDepA
    ret += EphemerisCommonContentDepA._payload_size()
    # tgd: double
    ret += 8
    # c_rs: double
    ret += 8
    # c_rc: double
    ret += 8
    # c_uc: double
    ret += 8
    # c_us: double
    ret += 8
    # c_ic: double
    ret += 8
    # c_is: double
    ret += 8
    # dn: double
    ret += 8
    # m0: double
    ret += 8
    # ecc: double
    ret += 8
    # sqrta: double
    ret += 8
    # omega0: double
    ret += 8
    # omegadot: double
    ret += 8
    # w: double
    ret += 8
    # inc: double
    ret += 8
    # inc_dot: double
    ret += 8
    # af0: double
    ret += 8
    # af1: double
    ret += 8
    # af2: double
    ret += 8
    # toc: GPSTimeDep
    ret += GPSTimeDep._payload_size()
    # iode: u8
    ret += 1
    # iodc: u16
    ret += 2
    return ret
  
SBP_MSG_EPHEMERIS_GPS_DEP_F = 0x0086
class MsgEphemerisGPSDepF(SBP):
  """SBP class for message MSG_EPHEMERIS_GPS_DEP_F (0x0086).

  You can have MSG_EPHEMERIS_GPS_DEP_F inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  This observation message has been deprecated in favor of
ephemeris message using floats for size reduction.


  """
  __slots__ = ['common',
               'tgd',
               'c_rs',
               'c_rc',
               'c_uc',
               'c_us',
               'c_ic',
               'c_is',
               'dn',
               'm0',
               'ecc',
               'sqrta',
               'omega0',
               'omegadot',
               'w',
               'inc',
               'inc_dot',
               'af0',
               'af1',
               'af2',
               'toc',
               'iode',
               'iodc',
               ]
  @classmethod
  def parse_members(cls, buf, offset, length):
    ret = {}
    (__common, offset, length) = EphemerisCommonContentDepB.parse_members(buf, offset, length)
    ret['common'] = __common
    (__tgd, offset, length) = get_f64(buf, offset, length)
    ret['tgd'] = __tgd
    (__c_rs, offset, length) = get_f64(buf, offset, length)
    ret['c_rs'] = __c_rs
    (__c_rc, offset, length) = get_f64(buf, offset, length)
    ret['c_rc'] = __c_rc
    (__c_uc, offset, length) = get_f64(buf, offset, length)
    ret['c_uc'] = __c_uc
    (__c_us, offset, length) = get_f64(buf, offset, length)
    ret['c_us'] = __c_us
    (__c_ic, offset, length) = get_f64(buf, offset, length)
    ret['c_ic'] = __c_ic
    (__c_is, offset, length) = get_f64(buf, offset, length)
    ret['c_is'] = __c_is
    (__dn, offset, length) = get_f64(buf, offset, length)
    ret['dn'] = __dn
    (__m0, offset, length) = get_f64(buf, offset, length)
    ret['m0'] = __m0
    (__ecc, offset, length) = get_f64(buf, offset, length)
    ret['ecc'] = __ecc
    (__sqrta, offset, length) = get_f64(buf, offset, length)
    ret['sqrta'] = __sqrta
    (__omega0, offset, length) = get_f64(buf, offset, length)
    ret['omega0'] = __omega0
    (__omegadot, offset, length) = get_f64(buf, offset, length)
    ret['omegadot'] = __omegadot
    (__w, offset, length) = get_f64(buf, offset, length)
    ret['w'] = __w
    (__inc, offset, length) = get_f64(buf, offset, length)
    ret['inc'] = __inc
    (__inc_dot, offset, length) = get_f64(buf, offset, length)
    ret['inc_dot'] = __inc_dot
    (__af0, offset, length) = get_f64(buf, offset, length)
    ret['af0'] = __af0
    (__af1, offset, length) = get_f64(buf, offset, length)
    ret['af1'] = __af1
    (__af2, offset, length) = get_f64(buf, offset, length)
    ret['af2'] = __af2
    (__toc, offset, length) = GPSTimeSec.parse_members(buf, offset, length)
    ret['toc'] = __toc
    (__iode, offset, length) = get_u8(buf, offset, length)
    ret['iode'] = __iode
    (__iodc, offset, length) = get_u16(buf, offset, length)
    ret['iodc'] = __iodc
    return ret, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.common = res['common']
    self.tgd = res['tgd']
    self.c_rs = res['c_rs']
    self.c_rc = res['c_rc']
    self.c_uc = res['c_uc']
    self.c_us = res['c_us']
    self.c_ic = res['c_ic']
    self.c_is = res['c_is']
    self.dn = res['dn']
    self.m0 = res['m0']
    self.ecc = res['ecc']
    self.sqrta = res['sqrta']
    self.omega0 = res['omega0']
    self.omegadot = res['omegadot']
    self.w = res['w']
    self.inc = res['inc']
    self.inc_dot = res['inc_dot']
    self.af0 = res['af0']
    self.af1 = res['af1']
    self.af2 = res['af2']
    self.toc = res['toc']
    self.iode = res['iode']
    self.iodc = res['iodc']
    return res, off, length

  @classmethod
  def _payload_size(self):
    ret = 0
    # common: EphemerisCommonContentDepB
    ret += EphemerisCommonContentDepB._payload_size()
    # tgd: double
    ret += 8
    # c_rs: double
    ret += 8
    # c_rc: double
    ret += 8
    # c_uc: double
    ret += 8
    # c_us: double
    ret += 8
    # c_ic: double
    ret += 8
    # c_is: double
    ret += 8
    # dn: double
    ret += 8
    # m0: double
    ret += 8
    # ecc: double
    ret += 8
    # sqrta: double
    ret += 8
    # omega0: double
    ret += 8
    # omegadot: double
    ret += 8
    # w: double
    ret += 8
    # inc: double
    ret += 8
    # inc_dot: double
    ret += 8
    # af0: double
    ret += 8
    # af1: double
    ret += 8
    # af2: double
    ret += 8
    # toc: GPSTimeSec
    ret += GPSTimeSec._payload_size()
    # iode: u8
    ret += 1
    # iodc: u16
    ret += 2
    return ret
  
SBP_MSG_EPHEMERIS_GPS = 0x008A
class MsgEphemerisGPS(SBP):
  """SBP class for message MSG_EPHEMERIS_GPS (0x008A).

  You can have MSG_EPHEMERIS_GPS inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  The ephemeris message returns a set of satellite orbit
parameters that is used to calculate GPS satellite position,
velocity, and clock offset. Please see the Navstar GPS
Space Segment/Navigation user interfaces (ICD-GPS-200, Table
20-III) for more details.


  """
  __slots__ = ['common',
               'tgd',
               'c_rs',
               'c_rc',
               'c_uc',
               'c_us',
               'c_ic',
               'c_is',
               'dn',
               'm0',
               'ecc',
               'sqrta',
               'omega0',
               'omegadot',
               'w',
               'inc',
               'inc_dot',
               'af0',
               'af1',
               'af2',
               'toc',
               'iode',
               'iodc',
               ]
  @classmethod
  def parse_members(cls, buf, offset, length):
    ret = {}
    (__common, offset, length) = EphemerisCommonContent.parse_members(buf, offset, length)
    ret['common'] = __common
    (__tgd, offset, length) = get_f32(buf, offset, length)
    ret['tgd'] = judicious_round(np.float32(__tgd)) if SBP.judicious_rounding else __tgd
    (__c_rs, offset, length) = get_f32(buf, offset, length)
    ret['c_rs'] = judicious_round(np.float32(__c_rs)) if SBP.judicious_rounding else __c_rs
    (__c_rc, offset, length) = get_f32(buf, offset, length)
    ret['c_rc'] = judicious_round(np.float32(__c_rc)) if SBP.judicious_rounding else __c_rc
    (__c_uc, offset, length) = get_f32(buf, offset, length)
    ret['c_uc'] = judicious_round(np.float32(__c_uc)) if SBP.judicious_rounding else __c_uc
    (__c_us, offset, length) = get_f32(buf, offset, length)
    ret['c_us'] = judicious_round(np.float32(__c_us)) if SBP.judicious_rounding else __c_us
    (__c_ic, offset, length) = get_f32(buf, offset, length)
    ret['c_ic'] = judicious_round(np.float32(__c_ic)) if SBP.judicious_rounding else __c_ic
    (__c_is, offset, length) = get_f32(buf, offset, length)
    ret['c_is'] = judicious_round(np.float32(__c_is)) if SBP.judicious_rounding else __c_is
    (__dn, offset, length) = get_f64(buf, offset, length)
    ret['dn'] = __dn
    (__m0, offset, length) = get_f64(buf, offset, length)
    ret['m0'] = __m0
    (__ecc, offset, length) = get_f64(buf, offset, length)
    ret['ecc'] = __ecc
    (__sqrta, offset, length) = get_f64(buf, offset, length)
    ret['sqrta'] = __sqrta
    (__omega0, offset, length) = get_f64(buf, offset, length)
    ret['omega0'] = __omega0
    (__omegadot, offset, length) = get_f64(buf, offset, length)
    ret['omegadot'] = __omegadot
    (__w, offset, length) = get_f64(buf, offset, length)
    ret['w'] = __w
    (__inc, offset, length) = get_f64(buf, offset, length)
    ret['inc'] = __inc
    (__inc_dot, offset, length) = get_f64(buf, offset, length)
    ret['inc_dot'] = __inc_dot
    (__af0, offset, length) = get_f32(buf, offset, length)
    ret['af0'] = judicious_round(np.float32(__af0)) if SBP.judicious_rounding else __af0
    (__af1, offset, length) = get_f32(buf, offset, length)
    ret['af1'] = judicious_round(np.float32(__af1)) if SBP.judicious_rounding else __af1
    (__af2, offset, length) = get_f32(buf, offset, length)
    ret['af2'] = judicious_round(np.float32(__af2)) if SBP.judicious_rounding else __af2
    (__toc, offset, length) = GPSTimeSec.parse_members(buf, offset, length)
    ret['toc'] = __toc
    (__iode, offset, length) = get_u8(buf, offset, length)
    ret['iode'] = __iode
    (__iodc, offset, length) = get_u16(buf, offset, length)
    ret['iodc'] = __iodc
    return ret, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.common = res['common']
    self.tgd = res['tgd']
    self.c_rs = res['c_rs']
    self.c_rc = res['c_rc']
    self.c_uc = res['c_uc']
    self.c_us = res['c_us']
    self.c_ic = res['c_ic']
    self.c_is = res['c_is']
    self.dn = res['dn']
    self.m0 = res['m0']
    self.ecc = res['ecc']
    self.sqrta = res['sqrta']
    self.omega0 = res['omega0']
    self.omegadot = res['omegadot']
    self.w = res['w']
    self.inc = res['inc']
    self.inc_dot = res['inc_dot']
    self.af0 = res['af0']
    self.af1 = res['af1']
    self.af2 = res['af2']
    self.toc = res['toc']
    self.iode = res['iode']
    self.iodc = res['iodc']
    return res, off, length

  @classmethod
  def _payload_size(self):
    ret = 0
    # common: EphemerisCommonContent
    ret += EphemerisCommonContent._payload_size()
    # tgd: float
    ret += 4
    # c_rs: float
    ret += 4
    # c_rc: float
    ret += 4
    # c_uc: float
    ret += 4
    # c_us: float
    ret += 4
    # c_ic: float
    ret += 4
    # c_is: float
    ret += 4
    # dn: double
    ret += 8
    # m0: double
    ret += 8
    # ecc: double
    ret += 8
    # sqrta: double
    ret += 8
    # omega0: double
    ret += 8
    # omegadot: double
    ret += 8
    # w: double
    ret += 8
    # inc: double
    ret += 8
    # inc_dot: double
    ret += 8
    # af0: float
    ret += 4
    # af1: float
    ret += 4
    # af2: float
    ret += 4
    # toc: GPSTimeSec
    ret += GPSTimeSec._payload_size()
    # iode: u8
    ret += 1
    # iodc: u16
    ret += 2
    return ret
  
SBP_MSG_EPHEMERIS_QZSS = 0x008E
class MsgEphemerisQzss(SBP):
  """SBP class for message MSG_EPHEMERIS_QZSS (0x008E).

  You can have MSG_EPHEMERIS_QZSS inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  The ephemeris message returns a set of satellite orbit
parameters that is used to calculate QZSS satellite position,
velocity, and clock offset.


  """
  __slots__ = ['common',
               'tgd',
               'c_rs',
               'c_rc',
               'c_uc',
               'c_us',
               'c_ic',
               'c_is',
               'dn',
               'm0',
               'ecc',
               'sqrta',
               'omega0',
               'omegadot',
               'w',
               'inc',
               'inc_dot',
               'af0',
               'af1',
               'af2',
               'toc',
               'iode',
               'iodc',
               ]
  @classmethod
  def parse_members(cls, buf, offset, length):
    ret = {}
    (__common, offset, length) = EphemerisCommonContent.parse_members(buf, offset, length)
    ret['common'] = __common
    (__tgd, offset, length) = get_f32(buf, offset, length)
    ret['tgd'] = judicious_round(np.float32(__tgd)) if SBP.judicious_rounding else __tgd
    (__c_rs, offset, length) = get_f32(buf, offset, length)
    ret['c_rs'] = judicious_round(np.float32(__c_rs)) if SBP.judicious_rounding else __c_rs
    (__c_rc, offset, length) = get_f32(buf, offset, length)
    ret['c_rc'] = judicious_round(np.float32(__c_rc)) if SBP.judicious_rounding else __c_rc
    (__c_uc, offset, length) = get_f32(buf, offset, length)
    ret['c_uc'] = judicious_round(np.float32(__c_uc)) if SBP.judicious_rounding else __c_uc
    (__c_us, offset, length) = get_f32(buf, offset, length)
    ret['c_us'] = judicious_round(np.float32(__c_us)) if SBP.judicious_rounding else __c_us
    (__c_ic, offset, length) = get_f32(buf, offset, length)
    ret['c_ic'] = judicious_round(np.float32(__c_ic)) if SBP.judicious_rounding else __c_ic
    (__c_is, offset, length) = get_f32(buf, offset, length)
    ret['c_is'] = judicious_round(np.float32(__c_is)) if SBP.judicious_rounding else __c_is
    (__dn, offset, length) = get_f64(buf, offset, length)
    ret['dn'] = __dn
    (__m0, offset, length) = get_f64(buf, offset, length)
    ret['m0'] = __m0
    (__ecc, offset, length) = get_f64(buf, offset, length)
    ret['ecc'] = __ecc
    (__sqrta, offset, length) = get_f64(buf, offset, length)
    ret['sqrta'] = __sqrta
    (__omega0, offset, length) = get_f64(buf, offset, length)
    ret['omega0'] = __omega0
    (__omegadot, offset, length) = get_f64(buf, offset, length)
    ret['omegadot'] = __omegadot
    (__w, offset, length) = get_f64(buf, offset, length)
    ret['w'] = __w
    (__inc, offset, length) = get_f64(buf, offset, length)
    ret['inc'] = __inc
    (__inc_dot, offset, length) = get_f64(buf, offset, length)
    ret['inc_dot'] = __inc_dot
    (__af0, offset, length) = get_f32(buf, offset, length)
    ret['af0'] = judicious_round(np.float32(__af0)) if SBP.judicious_rounding else __af0
    (__af1, offset, length) = get_f32(buf, offset, length)
    ret['af1'] = judicious_round(np.float32(__af1)) if SBP.judicious_rounding else __af1
    (__af2, offset, length) = get_f32(buf, offset, length)
    ret['af2'] = judicious_round(np.float32(__af2)) if SBP.judicious_rounding else __af2
    (__toc, offset, length) = GPSTimeSec.parse_members(buf, offset, length)
    ret['toc'] = __toc
    (__iode, offset, length) = get_u8(buf, offset, length)
    ret['iode'] = __iode
    (__iodc, offset, length) = get_u16(buf, offset, length)
    ret['iodc'] = __iodc
    return ret, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.common = res['common']
    self.tgd = res['tgd']
    self.c_rs = res['c_rs']
    self.c_rc = res['c_rc']
    self.c_uc = res['c_uc']
    self.c_us = res['c_us']
    self.c_ic = res['c_ic']
    self.c_is = res['c_is']
    self.dn = res['dn']
    self.m0 = res['m0']
    self.ecc = res['ecc']
    self.sqrta = res['sqrta']
    self.omega0 = res['omega0']
    self.omegadot = res['omegadot']
    self.w = res['w']
    self.inc = res['inc']
    self.inc_dot = res['inc_dot']
    self.af0 = res['af0']
    self.af1 = res['af1']
    self.af2 = res['af2']
    self.toc = res['toc']
    self.iode = res['iode']
    self.iodc = res['iodc']
    return res, off, length

  @classmethod
  def _payload_size(self):
    ret = 0
    # common: EphemerisCommonContent
    ret += EphemerisCommonContent._payload_size()
    # tgd: float
    ret += 4
    # c_rs: float
    ret += 4
    # c_rc: float
    ret += 4
    # c_uc: float
    ret += 4
    # c_us: float
    ret += 4
    # c_ic: float
    ret += 4
    # c_is: float
    ret += 4
    # dn: double
    ret += 8
    # m0: double
    ret += 8
    # ecc: double
    ret += 8
    # sqrta: double
    ret += 8
    # omega0: double
    ret += 8
    # omegadot: double
    ret += 8
    # w: double
    ret += 8
    # inc: double
    ret += 8
    # inc_dot: double
    ret += 8
    # af0: float
    ret += 4
    # af1: float
    ret += 4
    # af2: float
    ret += 4
    # toc: GPSTimeSec
    ret += GPSTimeSec._payload_size()
    # iode: u8
    ret += 1
    # iodc: u16
    ret += 2
    return ret
  
SBP_MSG_EPHEMERIS_BDS = 0x0089
class MsgEphemerisBds(SBP):
  """SBP class for message MSG_EPHEMERIS_BDS (0x0089).

  You can have MSG_EPHEMERIS_BDS inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  The ephemeris message returns a set of satellite orbit
parameters that is used to calculate BDS satellite position,
velocity, and clock offset. Please see the BeiDou Navigation
Satellite System SIS-ICD Version 2.1, Table 5-9 for more details.


  """
  __slots__ = ['common',
               'tgd1',
               'tgd2',
               'c_rs',
               'c_rc',
               'c_uc',
               'c_us',
               'c_ic',
               'c_is',
               'dn',
               'm0',
               'ecc',
               'sqrta',
               'omega0',
               'omegadot',
               'w',
               'inc',
               'inc_dot',
               'af0',
               'af1',
               'af2',
               'toc',
               'iode',
               'iodc',
               ]
  @classmethod
  def parse_members(cls, buf, offset, length):
    ret = {}
    (__common, offset, length) = EphemerisCommonContent.parse_members(buf, offset, length)
    ret['common'] = __common
    (__tgd1, offset, length) = get_f32(buf, offset, length)
    ret['tgd1'] = judicious_round(np.float32(__tgd1)) if SBP.judicious_rounding else __tgd1
    (__tgd2, offset, length) = get_f32(buf, offset, length)
    ret['tgd2'] = judicious_round(np.float32(__tgd2)) if SBP.judicious_rounding else __tgd2
    (__c_rs, offset, length) = get_f32(buf, offset, length)
    ret['c_rs'] = judicious_round(np.float32(__c_rs)) if SBP.judicious_rounding else __c_rs
    (__c_rc, offset, length) = get_f32(buf, offset, length)
    ret['c_rc'] = judicious_round(np.float32(__c_rc)) if SBP.judicious_rounding else __c_rc
    (__c_uc, offset, length) = get_f32(buf, offset, length)
    ret['c_uc'] = judicious_round(np.float32(__c_uc)) if SBP.judicious_rounding else __c_uc
    (__c_us, offset, length) = get_f32(buf, offset, length)
    ret['c_us'] = judicious_round(np.float32(__c_us)) if SBP.judicious_rounding else __c_us
    (__c_ic, offset, length) = get_f32(buf, offset, length)
    ret['c_ic'] = judicious_round(np.float32(__c_ic)) if SBP.judicious_rounding else __c_ic
    (__c_is, offset, length) = get_f32(buf, offset, length)
    ret['c_is'] = judicious_round(np.float32(__c_is)) if SBP.judicious_rounding else __c_is
    (__dn, offset, length) = get_f64(buf, offset, length)
    ret['dn'] = __dn
    (__m0, offset, length) = get_f64(buf, offset, length)
    ret['m0'] = __m0
    (__ecc, offset, length) = get_f64(buf, offset, length)
    ret['ecc'] = __ecc
    (__sqrta, offset, length) = get_f64(buf, offset, length)
    ret['sqrta'] = __sqrta
    (__omega0, offset, length) = get_f64(buf, offset, length)
    ret['omega0'] = __omega0
    (__omegadot, offset, length) = get_f64(buf, offset, length)
    ret['omegadot'] = __omegadot
    (__w, offset, length) = get_f64(buf, offset, length)
    ret['w'] = __w
    (__inc, offset, length) = get_f64(buf, offset, length)
    ret['inc'] = __inc
    (__inc_dot, offset, length) = get_f64(buf, offset, length)
    ret['inc_dot'] = __inc_dot
    (__af0, offset, length) = get_f64(buf, offset, length)
    ret['af0'] = __af0
    (__af1, offset, length) = get_f32(buf, offset, length)
    ret['af1'] = judicious_round(np.float32(__af1)) if SBP.judicious_rounding else __af1
    (__af2, offset, length) = get_f32(buf, offset, length)
    ret['af2'] = judicious_round(np.float32(__af2)) if SBP.judicious_rounding else __af2
    (__toc, offset, length) = GPSTimeSec.parse_members(buf, offset, length)
    ret['toc'] = __toc
    (__iode, offset, length) = get_u8(buf, offset, length)
    ret['iode'] = __iode
    (__iodc, offset, length) = get_u16(buf, offset, length)
    ret['iodc'] = __iodc
    return ret, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.common = res['common']
    self.tgd1 = res['tgd1']
    self.tgd2 = res['tgd2']
    self.c_rs = res['c_rs']
    self.c_rc = res['c_rc']
    self.c_uc = res['c_uc']
    self.c_us = res['c_us']
    self.c_ic = res['c_ic']
    self.c_is = res['c_is']
    self.dn = res['dn']
    self.m0 = res['m0']
    self.ecc = res['ecc']
    self.sqrta = res['sqrta']
    self.omega0 = res['omega0']
    self.omegadot = res['omegadot']
    self.w = res['w']
    self.inc = res['inc']
    self.inc_dot = res['inc_dot']
    self.af0 = res['af0']
    self.af1 = res['af1']
    self.af2 = res['af2']
    self.toc = res['toc']
    self.iode = res['iode']
    self.iodc = res['iodc']
    return res, off, length

  @classmethod
  def _payload_size(self):
    ret = 0
    # common: EphemerisCommonContent
    ret += EphemerisCommonContent._payload_size()
    # tgd1: float
    ret += 4
    # tgd2: float
    ret += 4
    # c_rs: float
    ret += 4
    # c_rc: float
    ret += 4
    # c_uc: float
    ret += 4
    # c_us: float
    ret += 4
    # c_ic: float
    ret += 4
    # c_is: float
    ret += 4
    # dn: double
    ret += 8
    # m0: double
    ret += 8
    # ecc: double
    ret += 8
    # sqrta: double
    ret += 8
    # omega0: double
    ret += 8
    # omegadot: double
    ret += 8
    # w: double
    ret += 8
    # inc: double
    ret += 8
    # inc_dot: double
    ret += 8
    # af0: double
    ret += 8
    # af1: float
    ret += 4
    # af2: float
    ret += 4
    # toc: GPSTimeSec
    ret += GPSTimeSec._payload_size()
    # iode: u8
    ret += 1
    # iodc: u16
    ret += 2
    return ret
  
SBP_MSG_EPHEMERIS_GAL_DEP_A = 0x0095
class MsgEphemerisGalDepA(SBP):
  """SBP class for message MSG_EPHEMERIS_GAL_DEP_A (0x0095).

  You can have MSG_EPHEMERIS_GAL_DEP_A inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  This observation message has been deprecated in favor of
an ephemeris message with explicit source of NAV data.


  """
  __slots__ = ['common',
               'bgd_e1e5a',
               'bgd_e1e5b',
               'c_rs',
               'c_rc',
               'c_uc',
               'c_us',
               'c_ic',
               'c_is',
               'dn',
               'm0',
               'ecc',
               'sqrta',
               'omega0',
               'omegadot',
               'w',
               'inc',
               'inc_dot',
               'af0',
               'af1',
               'af2',
               'toc',
               'iode',
               'iodc',
               ]
  @classmethod
  def parse_members(cls, buf, offset, length):
    ret = {}
    (__common, offset, length) = EphemerisCommonContent.parse_members(buf, offset, length)
    ret['common'] = __common
    (__bgd_e1e5a, offset, length) = get_f32(buf, offset, length)
    ret['bgd_e1e5a'] = judicious_round(np.float32(__bgd_e1e5a)) if SBP.judicious_rounding else __bgd_e1e5a
    (__bgd_e1e5b, offset, length) = get_f32(buf, offset, length)
    ret['bgd_e1e5b'] = judicious_round(np.float32(__bgd_e1e5b)) if SBP.judicious_rounding else __bgd_e1e5b
    (__c_rs, offset, length) = get_f32(buf, offset, length)
    ret['c_rs'] = judicious_round(np.float32(__c_rs)) if SBP.judicious_rounding else __c_rs
    (__c_rc, offset, length) = get_f32(buf, offset, length)
    ret['c_rc'] = judicious_round(np.float32(__c_rc)) if SBP.judicious_rounding else __c_rc
    (__c_uc, offset, length) = get_f32(buf, offset, length)
    ret['c_uc'] = judicious_round(np.float32(__c_uc)) if SBP.judicious_rounding else __c_uc
    (__c_us, offset, length) = get_f32(buf, offset, length)
    ret['c_us'] = judicious_round(np.float32(__c_us)) if SBP.judicious_rounding else __c_us
    (__c_ic, offset, length) = get_f32(buf, offset, length)
    ret['c_ic'] = judicious_round(np.float32(__c_ic)) if SBP.judicious_rounding else __c_ic
    (__c_is, offset, length) = get_f32(buf, offset, length)
    ret['c_is'] = judicious_round(np.float32(__c_is)) if SBP.judicious_rounding else __c_is
    (__dn, offset, length) = get_f64(buf, offset, length)
    ret['dn'] = __dn
    (__m0, offset, length) = get_f64(buf, offset, length)
    ret['m0'] = __m0
    (__ecc, offset, length) = get_f64(buf, offset, length)
    ret['ecc'] = __ecc
    (__sqrta, offset, length) = get_f64(buf, offset, length)
    ret['sqrta'] = __sqrta
    (__omega0, offset, length) = get_f64(buf, offset, length)
    ret['omega0'] = __omega0
    (__omegadot, offset, length) = get_f64(buf, offset, length)
    ret['omegadot'] = __omegadot
    (__w, offset, length) = get_f64(buf, offset, length)
    ret['w'] = __w
    (__inc, offset, length) = get_f64(buf, offset, length)
    ret['inc'] = __inc
    (__inc_dot, offset, length) = get_f64(buf, offset, length)
    ret['inc_dot'] = __inc_dot
    (__af0, offset, length) = get_f64(buf, offset, length)
    ret['af0'] = __af0
    (__af1, offset, length) = get_f64(buf, offset, length)
    ret['af1'] = __af1
    (__af2, offset, length) = get_f32(buf, offset, length)
    ret['af2'] = judicious_round(np.float32(__af2)) if SBP.judicious_rounding else __af2
    (__toc, offset, length) = GPSTimeSec.parse_members(buf, offset, length)
    ret['toc'] = __toc
    (__iode, offset, length) = get_u16(buf, offset, length)
    ret['iode'] = __iode
    (__iodc, offset, length) = get_u16(buf, offset, length)
    ret['iodc'] = __iodc
    return ret, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.common = res['common']
    self.bgd_e1e5a = res['bgd_e1e5a']
    self.bgd_e1e5b = res['bgd_e1e5b']
    self.c_rs = res['c_rs']
    self.c_rc = res['c_rc']
    self.c_uc = res['c_uc']
    self.c_us = res['c_us']
    self.c_ic = res['c_ic']
    self.c_is = res['c_is']
    self.dn = res['dn']
    self.m0 = res['m0']
    self.ecc = res['ecc']
    self.sqrta = res['sqrta']
    self.omega0 = res['omega0']
    self.omegadot = res['omegadot']
    self.w = res['w']
    self.inc = res['inc']
    self.inc_dot = res['inc_dot']
    self.af0 = res['af0']
    self.af1 = res['af1']
    self.af2 = res['af2']
    self.toc = res['toc']
    self.iode = res['iode']
    self.iodc = res['iodc']
    return res, off, length

  @classmethod
  def _payload_size(self):
    ret = 0
    # common: EphemerisCommonContent
    ret += EphemerisCommonContent._payload_size()
    # bgd_e1e5a: float
    ret += 4
    # bgd_e1e5b: float
    ret += 4
    # c_rs: float
    ret += 4
    # c_rc: float
    ret += 4
    # c_uc: float
    ret += 4
    # c_us: float
    ret += 4
    # c_ic: float
    ret += 4
    # c_is: float
    ret += 4
    # dn: double
    ret += 8
    # m0: double
    ret += 8
    # ecc: double
    ret += 8
    # sqrta: double
    ret += 8
    # omega0: double
    ret += 8
    # omegadot: double
    ret += 8
    # w: double
    ret += 8
    # inc: double
    ret += 8
    # inc_dot: double
    ret += 8
    # af0: double
    ret += 8
    # af1: double
    ret += 8
    # af2: float
    ret += 4
    # toc: GPSTimeSec
    ret += GPSTimeSec._payload_size()
    # iode: u16
    ret += 2
    # iodc: u16
    ret += 2
    return ret
  
SBP_MSG_EPHEMERIS_GAL = 0x008D
class MsgEphemerisGal(SBP):
  """SBP class for message MSG_EPHEMERIS_GAL (0x008D).

  You can have MSG_EPHEMERIS_GAL inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  The ephemeris message returns a set of satellite orbit
parameters that is used to calculate Galileo satellite position,
velocity, and clock offset. Please see the Signal In Space ICD
OS SIS ICD, Issue 1.3, December 2016 for more details.


  """
  __slots__ = ['common',
               'bgd_e1e5a',
               'bgd_e1e5b',
               'c_rs',
               'c_rc',
               'c_uc',
               'c_us',
               'c_ic',
               'c_is',
               'dn',
               'm0',
               'ecc',
               'sqrta',
               'omega0',
               'omegadot',
               'w',
               'inc',
               'inc_dot',
               'af0',
               'af1',
               'af2',
               'toc',
               'iode',
               'iodc',
               'source',
               ]
  @classmethod
  def parse_members(cls, buf, offset, length):
    ret = {}
    (__common, offset, length) = EphemerisCommonContent.parse_members(buf, offset, length)
    ret['common'] = __common
    (__bgd_e1e5a, offset, length) = get_f32(buf, offset, length)
    ret['bgd_e1e5a'] = judicious_round(np.float32(__bgd_e1e5a)) if SBP.judicious_rounding else __bgd_e1e5a
    (__bgd_e1e5b, offset, length) = get_f32(buf, offset, length)
    ret['bgd_e1e5b'] = judicious_round(np.float32(__bgd_e1e5b)) if SBP.judicious_rounding else __bgd_e1e5b
    (__c_rs, offset, length) = get_f32(buf, offset, length)
    ret['c_rs'] = judicious_round(np.float32(__c_rs)) if SBP.judicious_rounding else __c_rs
    (__c_rc, offset, length) = get_f32(buf, offset, length)
    ret['c_rc'] = judicious_round(np.float32(__c_rc)) if SBP.judicious_rounding else __c_rc
    (__c_uc, offset, length) = get_f32(buf, offset, length)
    ret['c_uc'] = judicious_round(np.float32(__c_uc)) if SBP.judicious_rounding else __c_uc
    (__c_us, offset, length) = get_f32(buf, offset, length)
    ret['c_us'] = judicious_round(np.float32(__c_us)) if SBP.judicious_rounding else __c_us
    (__c_ic, offset, length) = get_f32(buf, offset, length)
    ret['c_ic'] = judicious_round(np.float32(__c_ic)) if SBP.judicious_rounding else __c_ic
    (__c_is, offset, length) = get_f32(buf, offset, length)
    ret['c_is'] = judicious_round(np.float32(__c_is)) if SBP.judicious_rounding else __c_is
    (__dn, offset, length) = get_f64(buf, offset, length)
    ret['dn'] = __dn
    (__m0, offset, length) = get_f64(buf, offset, length)
    ret['m0'] = __m0
    (__ecc, offset, length) = get_f64(buf, offset, length)
    ret['ecc'] = __ecc
    (__sqrta, offset, length) = get_f64(buf, offset, length)
    ret['sqrta'] = __sqrta
    (__omega0, offset, length) = get_f64(buf, offset, length)
    ret['omega0'] = __omega0
    (__omegadot, offset, length) = get_f64(buf, offset, length)
    ret['omegadot'] = __omegadot
    (__w, offset, length) = get_f64(buf, offset, length)
    ret['w'] = __w
    (__inc, offset, length) = get_f64(buf, offset, length)
    ret['inc'] = __inc
    (__inc_dot, offset, length) = get_f64(buf, offset, length)
    ret['inc_dot'] = __inc_dot
    (__af0, offset, length) = get_f64(buf, offset, length)
    ret['af0'] = __af0
    (__af1, offset, length) = get_f64(buf, offset, length)
    ret['af1'] = __af1
    (__af2, offset, length) = get_f32(buf, offset, length)
    ret['af2'] = judicious_round(np.float32(__af2)) if SBP.judicious_rounding else __af2
    (__toc, offset, length) = GPSTimeSec.parse_members(buf, offset, length)
    ret['toc'] = __toc
    (__iode, offset, length) = get_u16(buf, offset, length)
    ret['iode'] = __iode
    (__iodc, offset, length) = get_u16(buf, offset, length)
    ret['iodc'] = __iodc
    (__source, offset, length) = get_u8(buf, offset, length)
    ret['source'] = __source
    return ret, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.common = res['common']
    self.bgd_e1e5a = res['bgd_e1e5a']
    self.bgd_e1e5b = res['bgd_e1e5b']
    self.c_rs = res['c_rs']
    self.c_rc = res['c_rc']
    self.c_uc = res['c_uc']
    self.c_us = res['c_us']
    self.c_ic = res['c_ic']
    self.c_is = res['c_is']
    self.dn = res['dn']
    self.m0 = res['m0']
    self.ecc = res['ecc']
    self.sqrta = res['sqrta']
    self.omega0 = res['omega0']
    self.omegadot = res['omegadot']
    self.w = res['w']
    self.inc = res['inc']
    self.inc_dot = res['inc_dot']
    self.af0 = res['af0']
    self.af1 = res['af1']
    self.af2 = res['af2']
    self.toc = res['toc']
    self.iode = res['iode']
    self.iodc = res['iodc']
    self.source = res['source']
    return res, off, length

  @classmethod
  def _payload_size(self):
    ret = 0
    # common: EphemerisCommonContent
    ret += EphemerisCommonContent._payload_size()
    # bgd_e1e5a: float
    ret += 4
    # bgd_e1e5b: float
    ret += 4
    # c_rs: float
    ret += 4
    # c_rc: float
    ret += 4
    # c_uc: float
    ret += 4
    # c_us: float
    ret += 4
    # c_ic: float
    ret += 4
    # c_is: float
    ret += 4
    # dn: double
    ret += 8
    # m0: double
    ret += 8
    # ecc: double
    ret += 8
    # sqrta: double
    ret += 8
    # omega0: double
    ret += 8
    # omegadot: double
    ret += 8
    # w: double
    ret += 8
    # inc: double
    ret += 8
    # inc_dot: double
    ret += 8
    # af0: double
    ret += 8
    # af1: double
    ret += 8
    # af2: float
    ret += 4
    # toc: GPSTimeSec
    ret += GPSTimeSec._payload_size()
    # iode: u16
    ret += 2
    # iodc: u16
    ret += 2
    # source: u8
    ret += 1
    return ret
  
SBP_MSG_EPHEMERIS_SBAS_DEP_A = 0x0082
class MsgEphemerisSbasDepA(SBP):
  """SBP class for message MSG_EPHEMERIS_SBAS_DEP_A (0x0082).

  You can have MSG_EPHEMERIS_SBAS_DEP_A inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  

  """
  __slots__ = ['common',
               'pos',
               'vel',
               'acc',
               'a_gf0',
               'a_gf1',
               ]
  @classmethod
  def parse_members(cls, buf, offset, length):
    ret = {}
    (__common, offset, length) = EphemerisCommonContentDepA.parse_members(buf, offset, length)
    ret['common'] = __common
    (__pos, offset, length) = get_fixed_array(get_f64, 3, 8)(buf, offset, length)
    ret['pos'] = __pos
    (__vel, offset, length) = get_fixed_array(get_f64, 3, 8)(buf, offset, length)
    ret['vel'] = __vel
    (__acc, offset, length) = get_fixed_array(get_f64, 3, 8)(buf, offset, length)
    ret['acc'] = __acc
    (__a_gf0, offset, length) = get_f64(buf, offset, length)
    ret['a_gf0'] = __a_gf0
    (__a_gf1, offset, length) = get_f64(buf, offset, length)
    ret['a_gf1'] = __a_gf1
    return ret, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.common = res['common']
    self.pos = res['pos']
    self.vel = res['vel']
    self.acc = res['acc']
    self.a_gf0 = res['a_gf0']
    self.a_gf1 = res['a_gf1']
    return res, off, length

  @classmethod
  def _payload_size(self):
    ret = 0
    # common: EphemerisCommonContentDepA
    ret += EphemerisCommonContentDepA._payload_size()
    # pos: array of double
    ret += 8 * 3
    # vel: array of double
    ret += 8 * 3
    # acc: array of double
    ret += 8 * 3
    # a_gf0: double
    ret += 8
    # a_gf1: double
    ret += 8
    return ret
  
SBP_MSG_EPHEMERIS_GLO_DEP_A = 0x0083
class MsgEphemerisGloDepA(SBP):
  """SBP class for message MSG_EPHEMERIS_GLO_DEP_A (0x0083).

  You can have MSG_EPHEMERIS_GLO_DEP_A inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  The ephemeris message returns a set of satellite orbit
parameters that is used to calculate GLO satellite position,
velocity, and clock offset. Please see the GLO ICD 5.1 "Table 4.5
Characteristics of words of immediate information (ephemeris parameters)"
for more details.


  """
  __slots__ = ['common',
               'gamma',
               'tau',
               'pos',
               'vel',
               'acc',
               ]
  @classmethod
  def parse_members(cls, buf, offset, length):
    ret = {}
    (__common, offset, length) = EphemerisCommonContentDepA.parse_members(buf, offset, length)
    ret['common'] = __common
    (__gamma, offset, length) = get_f64(buf, offset, length)
    ret['gamma'] = __gamma
    (__tau, offset, length) = get_f64(buf, offset, length)
    ret['tau'] = __tau
    (__pos, offset, length) = get_fixed_array(get_f64, 3, 8)(buf, offset, length)
    ret['pos'] = __pos
    (__vel, offset, length) = get_fixed_array(get_f64, 3, 8)(buf, offset, length)
    ret['vel'] = __vel
    (__acc, offset, length) = get_fixed_array(get_f64, 3, 8)(buf, offset, length)
    ret['acc'] = __acc
    return ret, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.common = res['common']
    self.gamma = res['gamma']
    self.tau = res['tau']
    self.pos = res['pos']
    self.vel = res['vel']
    self.acc = res['acc']
    return res, off, length

  @classmethod
  def _payload_size(self):
    ret = 0
    # common: EphemerisCommonContentDepA
    ret += EphemerisCommonContentDepA._payload_size()
    # gamma: double
    ret += 8
    # tau: double
    ret += 8
    # pos: array of double
    ret += 8 * 3
    # vel: array of double
    ret += 8 * 3
    # acc: array of double
    ret += 8 * 3
    return ret
  
SBP_MSG_EPHEMERIS_SBAS_DEP_B = 0x0084
class MsgEphemerisSbasDepB(SBP):
  """SBP class for message MSG_EPHEMERIS_SBAS_DEP_B (0x0084).

  You can have MSG_EPHEMERIS_SBAS_DEP_B inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  This observation message has been deprecated in favor of
ephemeris message using floats for size reduction.


  """
  __slots__ = ['common',
               'pos',
               'vel',
               'acc',
               'a_gf0',
               'a_gf1',
               ]
  @classmethod
  def parse_members(cls, buf, offset, length):
    ret = {}
    (__common, offset, length) = EphemerisCommonContentDepB.parse_members(buf, offset, length)
    ret['common'] = __common
    (__pos, offset, length) = get_fixed_array(get_f64, 3, 8)(buf, offset, length)
    ret['pos'] = __pos
    (__vel, offset, length) = get_fixed_array(get_f64, 3, 8)(buf, offset, length)
    ret['vel'] = __vel
    (__acc, offset, length) = get_fixed_array(get_f64, 3, 8)(buf, offset, length)
    ret['acc'] = __acc
    (__a_gf0, offset, length) = get_f64(buf, offset, length)
    ret['a_gf0'] = __a_gf0
    (__a_gf1, offset, length) = get_f64(buf, offset, length)
    ret['a_gf1'] = __a_gf1
    return ret, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.common = res['common']
    self.pos = res['pos']
    self.vel = res['vel']
    self.acc = res['acc']
    self.a_gf0 = res['a_gf0']
    self.a_gf1 = res['a_gf1']
    return res, off, length

  @classmethod
  def _payload_size(self):
    ret = 0
    # common: EphemerisCommonContentDepB
    ret += EphemerisCommonContentDepB._payload_size()
    # pos: array of double
    ret += 8 * 3
    # vel: array of double
    ret += 8 * 3
    # acc: array of double
    ret += 8 * 3
    # a_gf0: double
    ret += 8
    # a_gf1: double
    ret += 8
    return ret
  
SBP_MSG_EPHEMERIS_SBAS = 0x008C
class MsgEphemerisSbas(SBP):
  """SBP class for message MSG_EPHEMERIS_SBAS (0x008C).

  You can have MSG_EPHEMERIS_SBAS inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  

  """
  __slots__ = ['common',
               'pos',
               'vel',
               'acc',
               'a_gf0',
               'a_gf1',
               ]
  @classmethod
  def parse_members(cls, buf, offset, length):
    ret = {}
    (__common, offset, length) = EphemerisCommonContent.parse_members(buf, offset, length)
    ret['common'] = __common
    (__pos, offset, length) = get_fixed_array(get_f64, 3, 8)(buf, offset, length)
    ret['pos'] = __pos
    (__vel, offset, length) = get_fixed_array(get_f32, 3, 4, np.float32 if SBP.judicious_rounding else None)(buf, offset, length)
    ret['vel'] = __vel
    (__acc, offset, length) = get_fixed_array(get_f32, 3, 4, np.float32 if SBP.judicious_rounding else None)(buf, offset, length)
    ret['acc'] = __acc
    (__a_gf0, offset, length) = get_f32(buf, offset, length)
    ret['a_gf0'] = judicious_round(np.float32(__a_gf0)) if SBP.judicious_rounding else __a_gf0
    (__a_gf1, offset, length) = get_f32(buf, offset, length)
    ret['a_gf1'] = judicious_round(np.float32(__a_gf1)) if SBP.judicious_rounding else __a_gf1
    return ret, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.common = res['common']
    self.pos = res['pos']
    self.vel = res['vel']
    self.acc = res['acc']
    self.a_gf0 = res['a_gf0']
    self.a_gf1 = res['a_gf1']
    return res, off, length

  @classmethod
  def _payload_size(self):
    ret = 0
    # common: EphemerisCommonContent
    ret += EphemerisCommonContent._payload_size()
    # pos: array of double
    ret += 8 * 3
    # vel: array of float
    ret += 4 * 3
    # acc: array of float
    ret += 4 * 3
    # a_gf0: float
    ret += 4
    # a_gf1: float
    ret += 4
    return ret
  
SBP_MSG_EPHEMERIS_GLO_DEP_B = 0x0085
class MsgEphemerisGloDepB(SBP):
  """SBP class for message MSG_EPHEMERIS_GLO_DEP_B (0x0085).

  You can have MSG_EPHEMERIS_GLO_DEP_B inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  The ephemeris message returns a set of satellite orbit
parameters that is used to calculate GLO satellite position,
velocity, and clock offset. Please see the GLO ICD 5.1 "Table 4.5
Characteristics of words of immediate information (ephemeris parameters)"
for more details.


  """
  __slots__ = ['common',
               'gamma',
               'tau',
               'pos',
               'vel',
               'acc',
               ]
  @classmethod
  def parse_members(cls, buf, offset, length):
    ret = {}
    (__common, offset, length) = EphemerisCommonContentDepB.parse_members(buf, offset, length)
    ret['common'] = __common
    (__gamma, offset, length) = get_f64(buf, offset, length)
    ret['gamma'] = __gamma
    (__tau, offset, length) = get_f64(buf, offset, length)
    ret['tau'] = __tau
    (__pos, offset, length) = get_fixed_array(get_f64, 3, 8)(buf, offset, length)
    ret['pos'] = __pos
    (__vel, offset, length) = get_fixed_array(get_f64, 3, 8)(buf, offset, length)
    ret['vel'] = __vel
    (__acc, offset, length) = get_fixed_array(get_f64, 3, 8)(buf, offset, length)
    ret['acc'] = __acc
    return ret, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.common = res['common']
    self.gamma = res['gamma']
    self.tau = res['tau']
    self.pos = res['pos']
    self.vel = res['vel']
    self.acc = res['acc']
    return res, off, length

  @classmethod
  def _payload_size(self):
    ret = 0
    # common: EphemerisCommonContentDepB
    ret += EphemerisCommonContentDepB._payload_size()
    # gamma: double
    ret += 8
    # tau: double
    ret += 8
    # pos: array of double
    ret += 8 * 3
    # vel: array of double
    ret += 8 * 3
    # acc: array of double
    ret += 8 * 3
    return ret
  
SBP_MSG_EPHEMERIS_GLO_DEP_C = 0x0087
class MsgEphemerisGloDepC(SBP):
  """SBP class for message MSG_EPHEMERIS_GLO_DEP_C (0x0087).

  You can have MSG_EPHEMERIS_GLO_DEP_C inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  The ephemeris message returns a set of satellite orbit
parameters that is used to calculate GLO satellite position,
velocity, and clock offset. Please see the GLO ICD 5.1 "Table 4.5
Characteristics of words of immediate information (ephemeris parameters)"
for more details.


  """
  __slots__ = ['common',
               'gamma',
               'tau',
               'd_tau',
               'pos',
               'vel',
               'acc',
               'fcn',
               ]
  @classmethod
  def parse_members(cls, buf, offset, length):
    ret = {}
    (__common, offset, length) = EphemerisCommonContentDepB.parse_members(buf, offset, length)
    ret['common'] = __common
    (__gamma, offset, length) = get_f64(buf, offset, length)
    ret['gamma'] = __gamma
    (__tau, offset, length) = get_f64(buf, offset, length)
    ret['tau'] = __tau
    (__d_tau, offset, length) = get_f64(buf, offset, length)
    ret['d_tau'] = __d_tau
    (__pos, offset, length) = get_fixed_array(get_f64, 3, 8)(buf, offset, length)
    ret['pos'] = __pos
    (__vel, offset, length) = get_fixed_array(get_f64, 3, 8)(buf, offset, length)
    ret['vel'] = __vel
    (__acc, offset, length) = get_fixed_array(get_f64, 3, 8)(buf, offset, length)
    ret['acc'] = __acc
    (__fcn, offset, length) = get_u8(buf, offset, length)
    ret['fcn'] = __fcn
    return ret, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.common = res['common']
    self.gamma = res['gamma']
    self.tau = res['tau']
    self.d_tau = res['d_tau']
    self.pos = res['pos']
    self.vel = res['vel']
    self.acc = res['acc']
    self.fcn = res['fcn']
    return res, off, length

  @classmethod
  def _payload_size(self):
    ret = 0
    # common: EphemerisCommonContentDepB
    ret += EphemerisCommonContentDepB._payload_size()
    # gamma: double
    ret += 8
    # tau: double
    ret += 8
    # d_tau: double
    ret += 8
    # pos: array of double
    ret += 8 * 3
    # vel: array of double
    ret += 8 * 3
    # acc: array of double
    ret += 8 * 3
    # fcn: u8
    ret += 1
    return ret
  
SBP_MSG_EPHEMERIS_GLO_DEP_D = 0x0088
class MsgEphemerisGloDepD(SBP):
  """SBP class for message MSG_EPHEMERIS_GLO_DEP_D (0x0088).

  You can have MSG_EPHEMERIS_GLO_DEP_D inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  This observation message has been deprecated in favor of
ephemeris message using floats for size reduction.


  """
  __slots__ = ['common',
               'gamma',
               'tau',
               'd_tau',
               'pos',
               'vel',
               'acc',
               'fcn',
               'iod',
               ]
  @classmethod
  def parse_members(cls, buf, offset, length):
    ret = {}
    (__common, offset, length) = EphemerisCommonContentDepB.parse_members(buf, offset, length)
    ret['common'] = __common
    (__gamma, offset, length) = get_f64(buf, offset, length)
    ret['gamma'] = __gamma
    (__tau, offset, length) = get_f64(buf, offset, length)
    ret['tau'] = __tau
    (__d_tau, offset, length) = get_f64(buf, offset, length)
    ret['d_tau'] = __d_tau
    (__pos, offset, length) = get_fixed_array(get_f64, 3, 8)(buf, offset, length)
    ret['pos'] = __pos
    (__vel, offset, length) = get_fixed_array(get_f64, 3, 8)(buf, offset, length)
    ret['vel'] = __vel
    (__acc, offset, length) = get_fixed_array(get_f64, 3, 8)(buf, offset, length)
    ret['acc'] = __acc
    (__fcn, offset, length) = get_u8(buf, offset, length)
    ret['fcn'] = __fcn
    (__iod, offset, length) = get_u8(buf, offset, length)
    ret['iod'] = __iod
    return ret, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.common = res['common']
    self.gamma = res['gamma']
    self.tau = res['tau']
    self.d_tau = res['d_tau']
    self.pos = res['pos']
    self.vel = res['vel']
    self.acc = res['acc']
    self.fcn = res['fcn']
    self.iod = res['iod']
    return res, off, length

  @classmethod
  def _payload_size(self):
    ret = 0
    # common: EphemerisCommonContentDepB
    ret += EphemerisCommonContentDepB._payload_size()
    # gamma: double
    ret += 8
    # tau: double
    ret += 8
    # d_tau: double
    ret += 8
    # pos: array of double
    ret += 8 * 3
    # vel: array of double
    ret += 8 * 3
    # acc: array of double
    ret += 8 * 3
    # fcn: u8
    ret += 1
    # iod: u8
    ret += 1
    return ret
  
SBP_MSG_EPHEMERIS_GLO = 0x008B
class MsgEphemerisGlo(SBP):
  """SBP class for message MSG_EPHEMERIS_GLO (0x008B).

  You can have MSG_EPHEMERIS_GLO inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  The ephemeris message returns a set of satellite orbit
parameters that is used to calculate GLO satellite position,
velocity, and clock offset. Please see the GLO ICD 5.1 "Table 4.5
Characteristics of words of immediate information (ephemeris parameters)"
for more details.


  """
  __slots__ = ['common',
               'gamma',
               'tau',
               'd_tau',
               'pos',
               'vel',
               'acc',
               'fcn',
               'iod',
               ]
  @classmethod
  def parse_members(cls, buf, offset, length):
    ret = {}
    (__common, offset, length) = EphemerisCommonContent.parse_members(buf, offset, length)
    ret['common'] = __common
    (__gamma, offset, length) = get_f32(buf, offset, length)
    ret['gamma'] = judicious_round(np.float32(__gamma)) if SBP.judicious_rounding else __gamma
    (__tau, offset, length) = get_f32(buf, offset, length)
    ret['tau'] = judicious_round(np.float32(__tau)) if SBP.judicious_rounding else __tau
    (__d_tau, offset, length) = get_f32(buf, offset, length)
    ret['d_tau'] = judicious_round(np.float32(__d_tau)) if SBP.judicious_rounding else __d_tau
    (__pos, offset, length) = get_fixed_array(get_f64, 3, 8)(buf, offset, length)
    ret['pos'] = __pos
    (__vel, offset, length) = get_fixed_array(get_f64, 3, 8)(buf, offset, length)
    ret['vel'] = __vel
    (__acc, offset, length) = get_fixed_array(get_f32, 3, 4, np.float32 if SBP.judicious_rounding else None)(buf, offset, length)
    ret['acc'] = __acc
    (__fcn, offset, length) = get_u8(buf, offset, length)
    ret['fcn'] = __fcn
    (__iod, offset, length) = get_u8(buf, offset, length)
    ret['iod'] = __iod
    return ret, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.common = res['common']
    self.gamma = res['gamma']
    self.tau = res['tau']
    self.d_tau = res['d_tau']
    self.pos = res['pos']
    self.vel = res['vel']
    self.acc = res['acc']
    self.fcn = res['fcn']
    self.iod = res['iod']
    return res, off, length

  @classmethod
  def _payload_size(self):
    ret = 0
    # common: EphemerisCommonContent
    ret += EphemerisCommonContent._payload_size()
    # gamma: float
    ret += 4
    # tau: float
    ret += 4
    # d_tau: float
    ret += 4
    # pos: array of double
    ret += 8 * 3
    # vel: array of double
    ret += 8 * 3
    # acc: array of float
    ret += 4 * 3
    # fcn: u8
    ret += 1
    # iod: u8
    ret += 1
    return ret
  
SBP_MSG_EPHEMERIS_DEP_D = 0x0080
class MsgEphemerisDepD(SBP):
  """SBP class for message MSG_EPHEMERIS_DEP_D (0x0080).

  You can have MSG_EPHEMERIS_DEP_D inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  The ephemeris message returns a set of satellite orbit
parameters that is used to calculate GPS satellite position,
velocity, and clock offset. Please see the Navstar GPS
Space Segment/Navigation user interfaces (ICD-GPS-200, Table
20-III) for more details.


  """
  __slots__ = ['tgd',
               'c_rs',
               'c_rc',
               'c_uc',
               'c_us',
               'c_ic',
               'c_is',
               'dn',
               'm0',
               'ecc',
               'sqrta',
               'omega0',
               'omegadot',
               'w',
               'inc',
               'inc_dot',
               'af0',
               'af1',
               'af2',
               'toe_tow',
               'toe_wn',
               'toc_tow',
               'toc_wn',
               'valid',
               'healthy',
               'sid',
               'iode',
               'iodc',
               'reserved',
               ]
  @classmethod
  def parse_members(cls, buf, offset, length):
    ret = {}
    (__tgd, offset, length) = get_f64(buf, offset, length)
    ret['tgd'] = __tgd
    (__c_rs, offset, length) = get_f64(buf, offset, length)
    ret['c_rs'] = __c_rs
    (__c_rc, offset, length) = get_f64(buf, offset, length)
    ret['c_rc'] = __c_rc
    (__c_uc, offset, length) = get_f64(buf, offset, length)
    ret['c_uc'] = __c_uc
    (__c_us, offset, length) = get_f64(buf, offset, length)
    ret['c_us'] = __c_us
    (__c_ic, offset, length) = get_f64(buf, offset, length)
    ret['c_ic'] = __c_ic
    (__c_is, offset, length) = get_f64(buf, offset, length)
    ret['c_is'] = __c_is
    (__dn, offset, length) = get_f64(buf, offset, length)
    ret['dn'] = __dn
    (__m0, offset, length) = get_f64(buf, offset, length)
    ret['m0'] = __m0
    (__ecc, offset, length) = get_f64(buf, offset, length)
    ret['ecc'] = __ecc
    (__sqrta, offset, length) = get_f64(buf, offset, length)
    ret['sqrta'] = __sqrta
    (__omega0, offset, length) = get_f64(buf, offset, length)
    ret['omega0'] = __omega0
    (__omegadot, offset, length) = get_f64(buf, offset, length)
    ret['omegadot'] = __omegadot
    (__w, offset, length) = get_f64(buf, offset, length)
    ret['w'] = __w
    (__inc, offset, length) = get_f64(buf, offset, length)
    ret['inc'] = __inc
    (__inc_dot, offset, length) = get_f64(buf, offset, length)
    ret['inc_dot'] = __inc_dot
    (__af0, offset, length) = get_f64(buf, offset, length)
    ret['af0'] = __af0
    (__af1, offset, length) = get_f64(buf, offset, length)
    ret['af1'] = __af1
    (__af2, offset, length) = get_f64(buf, offset, length)
    ret['af2'] = __af2
    (__toe_tow, offset, length) = get_f64(buf, offset, length)
    ret['toe_tow'] = __toe_tow
    (__toe_wn, offset, length) = get_u16(buf, offset, length)
    ret['toe_wn'] = __toe_wn
    (__toc_tow, offset, length) = get_f64(buf, offset, length)
    ret['toc_tow'] = __toc_tow
    (__toc_wn, offset, length) = get_u16(buf, offset, length)
    ret['toc_wn'] = __toc_wn
    (__valid, offset, length) = get_u8(buf, offset, length)
    ret['valid'] = __valid
    (__healthy, offset, length) = get_u8(buf, offset, length)
    ret['healthy'] = __healthy
    (__sid, offset, length) = GnssSignalDep.parse_members(buf, offset, length)
    ret['sid'] = __sid
    (__iode, offset, length) = get_u8(buf, offset, length)
    ret['iode'] = __iode
    (__iodc, offset, length) = get_u16(buf, offset, length)
    ret['iodc'] = __iodc
    (__reserved, offset, length) = get_u32(buf, offset, length)
    ret['reserved'] = __reserved
    return ret, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.tgd = res['tgd']
    self.c_rs = res['c_rs']
    self.c_rc = res['c_rc']
    self.c_uc = res['c_uc']
    self.c_us = res['c_us']
    self.c_ic = res['c_ic']
    self.c_is = res['c_is']
    self.dn = res['dn']
    self.m0 = res['m0']
    self.ecc = res['ecc']
    self.sqrta = res['sqrta']
    self.omega0 = res['omega0']
    self.omegadot = res['omegadot']
    self.w = res['w']
    self.inc = res['inc']
    self.inc_dot = res['inc_dot']
    self.af0 = res['af0']
    self.af1 = res['af1']
    self.af2 = res['af2']
    self.toe_tow = res['toe_tow']
    self.toe_wn = res['toe_wn']
    self.toc_tow = res['toc_tow']
    self.toc_wn = res['toc_wn']
    self.valid = res['valid']
    self.healthy = res['healthy']
    self.sid = res['sid']
    self.iode = res['iode']
    self.iodc = res['iodc']
    self.reserved = res['reserved']
    return res, off, length

  @classmethod
  def _payload_size(self):
    ret = 0
    # tgd: double
    ret += 8
    # c_rs: double
    ret += 8
    # c_rc: double
    ret += 8
    # c_uc: double
    ret += 8
    # c_us: double
    ret += 8
    # c_ic: double
    ret += 8
    # c_is: double
    ret += 8
    # dn: double
    ret += 8
    # m0: double
    ret += 8
    # ecc: double
    ret += 8
    # sqrta: double
    ret += 8
    # omega0: double
    ret += 8
    # omegadot: double
    ret += 8
    # w: double
    ret += 8
    # inc: double
    ret += 8
    # inc_dot: double
    ret += 8
    # af0: double
    ret += 8
    # af1: double
    ret += 8
    # af2: double
    ret += 8
    # toe_tow: double
    ret += 8
    # toe_wn: u16
    ret += 2
    # toc_tow: double
    ret += 8
    # toc_wn: u16
    ret += 2
    # valid: u8
    ret += 1
    # healthy: u8
    ret += 1
    # sid: GnssSignalDep
    ret += GnssSignalDep._payload_size()
    # iode: u8
    ret += 1
    # iodc: u16
    ret += 2
    # reserved: u32
    ret += 4
    return ret
  
SBP_MSG_EPHEMERIS_DEP_A = 0x001A
class MsgEphemerisDepA(SBP):
  """SBP class for message MSG_EPHEMERIS_DEP_A (0x001A).

  You can have MSG_EPHEMERIS_DEP_A inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  Deprecated.

  """
  __slots__ = ['tgd',
               'c_rs',
               'c_rc',
               'c_uc',
               'c_us',
               'c_ic',
               'c_is',
               'dn',
               'm0',
               'ecc',
               'sqrta',
               'omega0',
               'omegadot',
               'w',
               'inc',
               'inc_dot',
               'af0',
               'af1',
               'af2',
               'toe_tow',
               'toe_wn',
               'toc_tow',
               'toc_wn',
               'valid',
               'healthy',
               'prn',
               ]
  @classmethod
  def parse_members(cls, buf, offset, length):
    ret = {}
    (__tgd, offset, length) = get_f64(buf, offset, length)
    ret['tgd'] = __tgd
    (__c_rs, offset, length) = get_f64(buf, offset, length)
    ret['c_rs'] = __c_rs
    (__c_rc, offset, length) = get_f64(buf, offset, length)
    ret['c_rc'] = __c_rc
    (__c_uc, offset, length) = get_f64(buf, offset, length)
    ret['c_uc'] = __c_uc
    (__c_us, offset, length) = get_f64(buf, offset, length)
    ret['c_us'] = __c_us
    (__c_ic, offset, length) = get_f64(buf, offset, length)
    ret['c_ic'] = __c_ic
    (__c_is, offset, length) = get_f64(buf, offset, length)
    ret['c_is'] = __c_is
    (__dn, offset, length) = get_f64(buf, offset, length)
    ret['dn'] = __dn
    (__m0, offset, length) = get_f64(buf, offset, length)
    ret['m0'] = __m0
    (__ecc, offset, length) = get_f64(buf, offset, length)
    ret['ecc'] = __ecc
    (__sqrta, offset, length) = get_f64(buf, offset, length)
    ret['sqrta'] = __sqrta
    (__omega0, offset, length) = get_f64(buf, offset, length)
    ret['omega0'] = __omega0
    (__omegadot, offset, length) = get_f64(buf, offset, length)
    ret['omegadot'] = __omegadot
    (__w, offset, length) = get_f64(buf, offset, length)
    ret['w'] = __w
    (__inc, offset, length) = get_f64(buf, offset, length)
    ret['inc'] = __inc
    (__inc_dot, offset, length) = get_f64(buf, offset, length)
    ret['inc_dot'] = __inc_dot
    (__af0, offset, length) = get_f64(buf, offset, length)
    ret['af0'] = __af0
    (__af1, offset, length) = get_f64(buf, offset, length)
    ret['af1'] = __af1
    (__af2, offset, length) = get_f64(buf, offset, length)
    ret['af2'] = __af2
    (__toe_tow, offset, length) = get_f64(buf, offset, length)
    ret['toe_tow'] = __toe_tow
    (__toe_wn, offset, length) = get_u16(buf, offset, length)
    ret['toe_wn'] = __toe_wn
    (__toc_tow, offset, length) = get_f64(buf, offset, length)
    ret['toc_tow'] = __toc_tow
    (__toc_wn, offset, length) = get_u16(buf, offset, length)
    ret['toc_wn'] = __toc_wn
    (__valid, offset, length) = get_u8(buf, offset, length)
    ret['valid'] = __valid
    (__healthy, offset, length) = get_u8(buf, offset, length)
    ret['healthy'] = __healthy
    (__prn, offset, length) = get_u8(buf, offset, length)
    ret['prn'] = __prn
    return ret, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.tgd = res['tgd']
    self.c_rs = res['c_rs']
    self.c_rc = res['c_rc']
    self.c_uc = res['c_uc']
    self.c_us = res['c_us']
    self.c_ic = res['c_ic']
    self.c_is = res['c_is']
    self.dn = res['dn']
    self.m0 = res['m0']
    self.ecc = res['ecc']
    self.sqrta = res['sqrta']
    self.omega0 = res['omega0']
    self.omegadot = res['omegadot']
    self.w = res['w']
    self.inc = res['inc']
    self.inc_dot = res['inc_dot']
    self.af0 = res['af0']
    self.af1 = res['af1']
    self.af2 = res['af2']
    self.toe_tow = res['toe_tow']
    self.toe_wn = res['toe_wn']
    self.toc_tow = res['toc_tow']
    self.toc_wn = res['toc_wn']
    self.valid = res['valid']
    self.healthy = res['healthy']
    self.prn = res['prn']
    return res, off, length

  @classmethod
  def _payload_size(self):
    ret = 0
    # tgd: double
    ret += 8
    # c_rs: double
    ret += 8
    # c_rc: double
    ret += 8
    # c_uc: double
    ret += 8
    # c_us: double
    ret += 8
    # c_ic: double
    ret += 8
    # c_is: double
    ret += 8
    # dn: double
    ret += 8
    # m0: double
    ret += 8
    # ecc: double
    ret += 8
    # sqrta: double
    ret += 8
    # omega0: double
    ret += 8
    # omegadot: double
    ret += 8
    # w: double
    ret += 8
    # inc: double
    ret += 8
    # inc_dot: double
    ret += 8
    # af0: double
    ret += 8
    # af1: double
    ret += 8
    # af2: double
    ret += 8
    # toe_tow: double
    ret += 8
    # toe_wn: u16
    ret += 2
    # toc_tow: double
    ret += 8
    # toc_wn: u16
    ret += 2
    # valid: u8
    ret += 1
    # healthy: u8
    ret += 1
    # prn: u8
    ret += 1
    return ret
  
SBP_MSG_EPHEMERIS_DEP_B = 0x0046
class MsgEphemerisDepB(SBP):
  """SBP class for message MSG_EPHEMERIS_DEP_B (0x0046).

  You can have MSG_EPHEMERIS_DEP_B inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  Deprecated.

  """
  __slots__ = ['tgd',
               'c_rs',
               'c_rc',
               'c_uc',
               'c_us',
               'c_ic',
               'c_is',
               'dn',
               'm0',
               'ecc',
               'sqrta',
               'omega0',
               'omegadot',
               'w',
               'inc',
               'inc_dot',
               'af0',
               'af1',
               'af2',
               'toe_tow',
               'toe_wn',
               'toc_tow',
               'toc_wn',
               'valid',
               'healthy',
               'prn',
               'iode',
               ]
  @classmethod
  def parse_members(cls, buf, offset, length):
    ret = {}
    (__tgd, offset, length) = get_f64(buf, offset, length)
    ret['tgd'] = __tgd
    (__c_rs, offset, length) = get_f64(buf, offset, length)
    ret['c_rs'] = __c_rs
    (__c_rc, offset, length) = get_f64(buf, offset, length)
    ret['c_rc'] = __c_rc
    (__c_uc, offset, length) = get_f64(buf, offset, length)
    ret['c_uc'] = __c_uc
    (__c_us, offset, length) = get_f64(buf, offset, length)
    ret['c_us'] = __c_us
    (__c_ic, offset, length) = get_f64(buf, offset, length)
    ret['c_ic'] = __c_ic
    (__c_is, offset, length) = get_f64(buf, offset, length)
    ret['c_is'] = __c_is
    (__dn, offset, length) = get_f64(buf, offset, length)
    ret['dn'] = __dn
    (__m0, offset, length) = get_f64(buf, offset, length)
    ret['m0'] = __m0
    (__ecc, offset, length) = get_f64(buf, offset, length)
    ret['ecc'] = __ecc
    (__sqrta, offset, length) = get_f64(buf, offset, length)
    ret['sqrta'] = __sqrta
    (__omega0, offset, length) = get_f64(buf, offset, length)
    ret['omega0'] = __omega0
    (__omegadot, offset, length) = get_f64(buf, offset, length)
    ret['omegadot'] = __omegadot
    (__w, offset, length) = get_f64(buf, offset, length)
    ret['w'] = __w
    (__inc, offset, length) = get_f64(buf, offset, length)
    ret['inc'] = __inc
    (__inc_dot, offset, length) = get_f64(buf, offset, length)
    ret['inc_dot'] = __inc_dot
    (__af0, offset, length) = get_f64(buf, offset, length)
    ret['af0'] = __af0
    (__af1, offset, length) = get_f64(buf, offset, length)
    ret['af1'] = __af1
    (__af2, offset, length) = get_f64(buf, offset, length)
    ret['af2'] = __af2
    (__toe_tow, offset, length) = get_f64(buf, offset, length)
    ret['toe_tow'] = __toe_tow
    (__toe_wn, offset, length) = get_u16(buf, offset, length)
    ret['toe_wn'] = __toe_wn
    (__toc_tow, offset, length) = get_f64(buf, offset, length)
    ret['toc_tow'] = __toc_tow
    (__toc_wn, offset, length) = get_u16(buf, offset, length)
    ret['toc_wn'] = __toc_wn
    (__valid, offset, length) = get_u8(buf, offset, length)
    ret['valid'] = __valid
    (__healthy, offset, length) = get_u8(buf, offset, length)
    ret['healthy'] = __healthy
    (__prn, offset, length) = get_u8(buf, offset, length)
    ret['prn'] = __prn
    (__iode, offset, length) = get_u8(buf, offset, length)
    ret['iode'] = __iode
    return ret, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.tgd = res['tgd']
    self.c_rs = res['c_rs']
    self.c_rc = res['c_rc']
    self.c_uc = res['c_uc']
    self.c_us = res['c_us']
    self.c_ic = res['c_ic']
    self.c_is = res['c_is']
    self.dn = res['dn']
    self.m0 = res['m0']
    self.ecc = res['ecc']
    self.sqrta = res['sqrta']
    self.omega0 = res['omega0']
    self.omegadot = res['omegadot']
    self.w = res['w']
    self.inc = res['inc']
    self.inc_dot = res['inc_dot']
    self.af0 = res['af0']
    self.af1 = res['af1']
    self.af2 = res['af2']
    self.toe_tow = res['toe_tow']
    self.toe_wn = res['toe_wn']
    self.toc_tow = res['toc_tow']
    self.toc_wn = res['toc_wn']
    self.valid = res['valid']
    self.healthy = res['healthy']
    self.prn = res['prn']
    self.iode = res['iode']
    return res, off, length

  @classmethod
  def _payload_size(self):
    ret = 0
    # tgd: double
    ret += 8
    # c_rs: double
    ret += 8
    # c_rc: double
    ret += 8
    # c_uc: double
    ret += 8
    # c_us: double
    ret += 8
    # c_ic: double
    ret += 8
    # c_is: double
    ret += 8
    # dn: double
    ret += 8
    # m0: double
    ret += 8
    # ecc: double
    ret += 8
    # sqrta: double
    ret += 8
    # omega0: double
    ret += 8
    # omegadot: double
    ret += 8
    # w: double
    ret += 8
    # inc: double
    ret += 8
    # inc_dot: double
    ret += 8
    # af0: double
    ret += 8
    # af1: double
    ret += 8
    # af2: double
    ret += 8
    # toe_tow: double
    ret += 8
    # toe_wn: u16
    ret += 2
    # toc_tow: double
    ret += 8
    # toc_wn: u16
    ret += 2
    # valid: u8
    ret += 1
    # healthy: u8
    ret += 1
    # prn: u8
    ret += 1
    # iode: u8
    ret += 1
    return ret
  
SBP_MSG_EPHEMERIS_DEP_C = 0x0047
class MsgEphemerisDepC(SBP):
  """SBP class for message MSG_EPHEMERIS_DEP_C (0x0047).

  You can have MSG_EPHEMERIS_DEP_C inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  The ephemeris message returns a set of satellite orbit
parameters that is used to calculate GPS satellite position,
velocity, and clock offset. Please see the Navstar GPS
Space Segment/Navigation user interfaces (ICD-GPS-200, Table
20-III) for more details.


  """
  __slots__ = ['tgd',
               'c_rs',
               'c_rc',
               'c_uc',
               'c_us',
               'c_ic',
               'c_is',
               'dn',
               'm0',
               'ecc',
               'sqrta',
               'omega0',
               'omegadot',
               'w',
               'inc',
               'inc_dot',
               'af0',
               'af1',
               'af2',
               'toe_tow',
               'toe_wn',
               'toc_tow',
               'toc_wn',
               'valid',
               'healthy',
               'sid',
               'iode',
               'iodc',
               'reserved',
               ]
  @classmethod
  def parse_members(cls, buf, offset, length):
    ret = {}
    (__tgd, offset, length) = get_f64(buf, offset, length)
    ret['tgd'] = __tgd
    (__c_rs, offset, length) = get_f64(buf, offset, length)
    ret['c_rs'] = __c_rs
    (__c_rc, offset, length) = get_f64(buf, offset, length)
    ret['c_rc'] = __c_rc
    (__c_uc, offset, length) = get_f64(buf, offset, length)
    ret['c_uc'] = __c_uc
    (__c_us, offset, length) = get_f64(buf, offset, length)
    ret['c_us'] = __c_us
    (__c_ic, offset, length) = get_f64(buf, offset, length)
    ret['c_ic'] = __c_ic
    (__c_is, offset, length) = get_f64(buf, offset, length)
    ret['c_is'] = __c_is
    (__dn, offset, length) = get_f64(buf, offset, length)
    ret['dn'] = __dn
    (__m0, offset, length) = get_f64(buf, offset, length)
    ret['m0'] = __m0
    (__ecc, offset, length) = get_f64(buf, offset, length)
    ret['ecc'] = __ecc
    (__sqrta, offset, length) = get_f64(buf, offset, length)
    ret['sqrta'] = __sqrta
    (__omega0, offset, length) = get_f64(buf, offset, length)
    ret['omega0'] = __omega0
    (__omegadot, offset, length) = get_f64(buf, offset, length)
    ret['omegadot'] = __omegadot
    (__w, offset, length) = get_f64(buf, offset, length)
    ret['w'] = __w
    (__inc, offset, length) = get_f64(buf, offset, length)
    ret['inc'] = __inc
    (__inc_dot, offset, length) = get_f64(buf, offset, length)
    ret['inc_dot'] = __inc_dot
    (__af0, offset, length) = get_f64(buf, offset, length)
    ret['af0'] = __af0
    (__af1, offset, length) = get_f64(buf, offset, length)
    ret['af1'] = __af1
    (__af2, offset, length) = get_f64(buf, offset, length)
    ret['af2'] = __af2
    (__toe_tow, offset, length) = get_f64(buf, offset, length)
    ret['toe_tow'] = __toe_tow
    (__toe_wn, offset, length) = get_u16(buf, offset, length)
    ret['toe_wn'] = __toe_wn
    (__toc_tow, offset, length) = get_f64(buf, offset, length)
    ret['toc_tow'] = __toc_tow
    (__toc_wn, offset, length) = get_u16(buf, offset, length)
    ret['toc_wn'] = __toc_wn
    (__valid, offset, length) = get_u8(buf, offset, length)
    ret['valid'] = __valid
    (__healthy, offset, length) = get_u8(buf, offset, length)
    ret['healthy'] = __healthy
    (__sid, offset, length) = GnssSignalDep.parse_members(buf, offset, length)
    ret['sid'] = __sid
    (__iode, offset, length) = get_u8(buf, offset, length)
    ret['iode'] = __iode
    (__iodc, offset, length) = get_u16(buf, offset, length)
    ret['iodc'] = __iodc
    (__reserved, offset, length) = get_u32(buf, offset, length)
    ret['reserved'] = __reserved
    return ret, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.tgd = res['tgd']
    self.c_rs = res['c_rs']
    self.c_rc = res['c_rc']
    self.c_uc = res['c_uc']
    self.c_us = res['c_us']
    self.c_ic = res['c_ic']
    self.c_is = res['c_is']
    self.dn = res['dn']
    self.m0 = res['m0']
    self.ecc = res['ecc']
    self.sqrta = res['sqrta']
    self.omega0 = res['omega0']
    self.omegadot = res['omegadot']
    self.w = res['w']
    self.inc = res['inc']
    self.inc_dot = res['inc_dot']
    self.af0 = res['af0']
    self.af1 = res['af1']
    self.af2 = res['af2']
    self.toe_tow = res['toe_tow']
    self.toe_wn = res['toe_wn']
    self.toc_tow = res['toc_tow']
    self.toc_wn = res['toc_wn']
    self.valid = res['valid']
    self.healthy = res['healthy']
    self.sid = res['sid']
    self.iode = res['iode']
    self.iodc = res['iodc']
    self.reserved = res['reserved']
    return res, off, length

  @classmethod
  def _payload_size(self):
    ret = 0
    # tgd: double
    ret += 8
    # c_rs: double
    ret += 8
    # c_rc: double
    ret += 8
    # c_uc: double
    ret += 8
    # c_us: double
    ret += 8
    # c_ic: double
    ret += 8
    # c_is: double
    ret += 8
    # dn: double
    ret += 8
    # m0: double
    ret += 8
    # ecc: double
    ret += 8
    # sqrta: double
    ret += 8
    # omega0: double
    ret += 8
    # omegadot: double
    ret += 8
    # w: double
    ret += 8
    # inc: double
    ret += 8
    # inc_dot: double
    ret += 8
    # af0: double
    ret += 8
    # af1: double
    ret += 8
    # af2: double
    ret += 8
    # toe_tow: double
    ret += 8
    # toe_wn: u16
    ret += 2
    # toc_tow: double
    ret += 8
    # toc_wn: u16
    ret += 2
    # valid: u8
    ret += 1
    # healthy: u8
    ret += 1
    # sid: GnssSignalDep
    ret += GnssSignalDep._payload_size()
    # iode: u8
    ret += 1
    # iodc: u16
    ret += 2
    # reserved: u32
    ret += 4
    return ret
  
class ObservationHeaderDep(object):
  """SBP class for message ObservationHeaderDep

  You can have ObservationHeaderDep inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  Header of a GPS observation message.

  """
  __slots__ = ['t',
               'n_obs',
               ]
  @classmethod
  def parse_members(cls, buf, offset, length):
    ret = {}
    (__t, offset, length) = GPSTimeDep.parse_members(buf, offset, length)
    ret['t'] = __t
    (__n_obs, offset, length) = get_u8(buf, offset, length)
    ret['n_obs'] = __n_obs
    return ret, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.t = res['t']
    self.n_obs = res['n_obs']
    return res, off, length

  @classmethod
  def _payload_size(self):
    ret = 0
    # t: GPSTimeDep
    ret += GPSTimeDep._payload_size()
    # n_obs: u8
    ret += 1
    return ret
  
class CarrierPhaseDepA(object):
  """SBP class for message CarrierPhaseDepA

  You can have CarrierPhaseDepA inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  Carrier phase measurement in cycles represented as a 40-bit
fixed point number with Q32.8 layout, i.e. 32-bits of whole
cycles and 8-bits of fractional cycles. This has the opposite
sign convention than a typical GPS receiver and the phase has
the opposite sign as the pseudorange.


  """
  __slots__ = ['i',
               'f',
               ]
  @classmethod
  def parse_members(cls, buf, offset, length):
    ret = {}
    (__i, offset, length) = get_s32(buf, offset, length)
    ret['i'] = __i
    (__f, offset, length) = get_u8(buf, offset, length)
    ret['f'] = __f
    return ret, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.i = res['i']
    self.f = res['f']
    return res, off, length

  @classmethod
  def _payload_size(self):
    ret = 0
    # i: s32
    ret += 4
    # f: u8
    ret += 1
    return ret
  
class PackedObsContentDepA(object):
  """SBP class for message PackedObsContentDepA

  You can have PackedObsContentDepA inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  Deprecated.

  """
  __slots__ = ['P',
               'L',
               'cn0',
               'lock',
               'prn',
               ]
  @classmethod
  def parse_members(cls, buf, offset, length):
    ret = {}
    (__P, offset, length) = get_u32(buf, offset, length)
    ret['P'] = __P
    (__L, offset, length) = CarrierPhaseDepA.parse_members(buf, offset, length)
    ret['L'] = __L
    (__cn0, offset, length) = get_u8(buf, offset, length)
    ret['cn0'] = __cn0
    (__lock, offset, length) = get_u16(buf, offset, length)
    ret['lock'] = __lock
    (__prn, offset, length) = get_u8(buf, offset, length)
    ret['prn'] = __prn
    return ret, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.P = res['P']
    self.L = res['L']
    self.cn0 = res['cn0']
    self.lock = res['lock']
    self.prn = res['prn']
    return res, off, length

  @classmethod
  def _payload_size(self):
    ret = 0
    # P: u32
    ret += 4
    # L: CarrierPhaseDepA
    ret += CarrierPhaseDepA._payload_size()
    # cn0: u8
    ret += 1
    # lock: u16
    ret += 2
    # prn: u8
    ret += 1
    return ret
  
class PackedObsContentDepB(object):
  """SBP class for message PackedObsContentDepB

  You can have PackedObsContentDepB inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  Pseudorange and carrier phase observation for a satellite being
tracked.  Pseudoranges are referenced to a nominal pseudorange.


  """
  __slots__ = ['P',
               'L',
               'cn0',
               'lock',
               'sid',
               ]
  @classmethod
  def parse_members(cls, buf, offset, length):
    ret = {}
    (__P, offset, length) = get_u32(buf, offset, length)
    ret['P'] = __P
    (__L, offset, length) = CarrierPhaseDepA.parse_members(buf, offset, length)
    ret['L'] = __L
    (__cn0, offset, length) = get_u8(buf, offset, length)
    ret['cn0'] = __cn0
    (__lock, offset, length) = get_u16(buf, offset, length)
    ret['lock'] = __lock
    (__sid, offset, length) = GnssSignalDep.parse_members(buf, offset, length)
    ret['sid'] = __sid
    return ret, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.P = res['P']
    self.L = res['L']
    self.cn0 = res['cn0']
    self.lock = res['lock']
    self.sid = res['sid']
    return res, off, length

  @classmethod
  def _payload_size(self):
    ret = 0
    # P: u32
    ret += 4
    # L: CarrierPhaseDepA
    ret += CarrierPhaseDepA._payload_size()
    # cn0: u8
    ret += 1
    # lock: u16
    ret += 2
    # sid: GnssSignalDep
    ret += GnssSignalDep._payload_size()
    return ret
  
class PackedObsContentDepC(object):
  """SBP class for message PackedObsContentDepC

  You can have PackedObsContentDepC inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  Pseudorange and carrier phase observation for a satellite being
tracked. The observations are be interoperable with 3rd party
receivers and conform with typical RTCMv3 GNSS observations.


  """
  __slots__ = ['P',
               'L',
               'cn0',
               'lock',
               'sid',
               ]
  @classmethod
  def parse_members(cls, buf, offset, length):
    ret = {}
    (__P, offset, length) = get_u32(buf, offset, length)
    ret['P'] = __P
    (__L, offset, length) = CarrierPhase.parse_members(buf, offset, length)
    ret['L'] = __L
    (__cn0, offset, length) = get_u8(buf, offset, length)
    ret['cn0'] = __cn0
    (__lock, offset, length) = get_u16(buf, offset, length)
    ret['lock'] = __lock
    (__sid, offset, length) = GnssSignalDep.parse_members(buf, offset, length)
    ret['sid'] = __sid
    return ret, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.P = res['P']
    self.L = res['L']
    self.cn0 = res['cn0']
    self.lock = res['lock']
    self.sid = res['sid']
    return res, off, length

  @classmethod
  def _payload_size(self):
    ret = 0
    # P: u32
    ret += 4
    # L: CarrierPhase
    ret += CarrierPhase._payload_size()
    # cn0: u8
    ret += 1
    # lock: u16
    ret += 2
    # sid: GnssSignalDep
    ret += GnssSignalDep._payload_size()
    return ret
  
SBP_MSG_OBS_DEP_A = 0x0045
class MsgObsDepA(SBP):
  """SBP class for message MSG_OBS_DEP_A (0x0045).

  You can have MSG_OBS_DEP_A inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  Deprecated.

  """
  __slots__ = ['header',
               'obs',
               ]
  @classmethod
  def parse_members(cls, buf, offset, length):
    ret = {}
    (__header, offset, length) = ObservationHeaderDep.parse_members(buf, offset, length)
    ret['header'] = __header
    (__obs, offset, length) = get_array(PackedObsContentDepA.parse_members)(buf, offset, length)
    ret['obs'] = __obs
    return ret, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.header = res['header']
    self.obs = res['obs']
    return res, off, length

  @classmethod
  def _payload_size(self):
    ret = 0
    # header: ObservationHeaderDep
    ret += ObservationHeaderDep._payload_size()
    # obs: array of PackedObsContentDepA
    ret += 247
    return ret
  
SBP_MSG_OBS_DEP_B = 0x0043
class MsgObsDepB(SBP):
  """SBP class for message MSG_OBS_DEP_B (0x0043).

  You can have MSG_OBS_DEP_B inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  This observation message has been deprecated in favor of
observations that are more interoperable. This message
should be used for observations referenced to
a nominal pseudorange which are not interoperable with
most 3rd party GNSS receievers or typical RTCMv3
observations.


  """
  __slots__ = ['header',
               'obs',
               ]
  @classmethod
  def parse_members(cls, buf, offset, length):
    ret = {}
    (__header, offset, length) = ObservationHeaderDep.parse_members(buf, offset, length)
    ret['header'] = __header
    (__obs, offset, length) = get_array(PackedObsContentDepB.parse_members)(buf, offset, length)
    ret['obs'] = __obs
    return ret, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.header = res['header']
    self.obs = res['obs']
    return res, off, length

  @classmethod
  def _payload_size(self):
    ret = 0
    # header: ObservationHeaderDep
    ret += ObservationHeaderDep._payload_size()
    # obs: array of PackedObsContentDepB
    ret += 247
    return ret
  
SBP_MSG_OBS_DEP_C = 0x0049
class MsgObsDepC(SBP):
  """SBP class for message MSG_OBS_DEP_C (0x0049).

  You can have MSG_OBS_DEP_C inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  The GPS observations message reports all the raw pseudorange and
carrier phase observations for the satellites being tracked by
the device. Carrier phase observation here is represented as a
40-bit fixed point number with Q32.8 layout (i.e. 32-bits of
whole cycles and 8-bits of fractional cycles). The observations
are interoperable with 3rd party receivers and conform
with typical RTCMv3 GNSS observations.


  """
  __slots__ = ['header',
               'obs',
               ]
  @classmethod
  def parse_members(cls, buf, offset, length):
    ret = {}
    (__header, offset, length) = ObservationHeaderDep.parse_members(buf, offset, length)
    ret['header'] = __header
    (__obs, offset, length) = get_array(PackedObsContentDepC.parse_members)(buf, offset, length)
    ret['obs'] = __obs
    return ret, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.header = res['header']
    self.obs = res['obs']
    return res, off, length

  @classmethod
  def _payload_size(self):
    ret = 0
    # header: ObservationHeaderDep
    ret += ObservationHeaderDep._payload_size()
    # obs: array of PackedObsContentDepC
    ret += 247
    return ret
  
SBP_MSG_IONO = 0x0090
class MsgIono(SBP):
  """SBP class for message MSG_IONO (0x0090).

  You can have MSG_IONO inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  The ionospheric parameters which allow the "L1 only" or "L2 only" user to
utilize the ionospheric model for computation of the ionospheric delay.
Please see ICD-GPS-200 (Chapter 20.3.3.5.1.7) for more details.


  """
  __slots__ = ['t_nmct',
               'a0',
               'a1',
               'a2',
               'a3',
               'b0',
               'b1',
               'b2',
               'b3',
               ]
  @classmethod
  def parse_members(cls, buf, offset, length):
    ret = {}
    (__t_nmct, offset, length) = GPSTimeSec.parse_members(buf, offset, length)
    ret['t_nmct'] = __t_nmct
    (__a0, offset, length) = get_f64(buf, offset, length)
    ret['a0'] = __a0
    (__a1, offset, length) = get_f64(buf, offset, length)
    ret['a1'] = __a1
    (__a2, offset, length) = get_f64(buf, offset, length)
    ret['a2'] = __a2
    (__a3, offset, length) = get_f64(buf, offset, length)
    ret['a3'] = __a3
    (__b0, offset, length) = get_f64(buf, offset, length)
    ret['b0'] = __b0
    (__b1, offset, length) = get_f64(buf, offset, length)
    ret['b1'] = __b1
    (__b2, offset, length) = get_f64(buf, offset, length)
    ret['b2'] = __b2
    (__b3, offset, length) = get_f64(buf, offset, length)
    ret['b3'] = __b3
    return ret, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.t_nmct = res['t_nmct']
    self.a0 = res['a0']
    self.a1 = res['a1']
    self.a2 = res['a2']
    self.a3 = res['a3']
    self.b0 = res['b0']
    self.b1 = res['b1']
    self.b2 = res['b2']
    self.b3 = res['b3']
    return res, off, length

  @classmethod
  def _payload_size(self):
    ret = 0
    # t_nmct: GPSTimeSec
    ret += GPSTimeSec._payload_size()
    # a0: double
    ret += 8
    # a1: double
    ret += 8
    # a2: double
    ret += 8
    # a3: double
    ret += 8
    # b0: double
    ret += 8
    # b1: double
    ret += 8
    # b2: double
    ret += 8
    # b3: double
    ret += 8
    return ret
  
SBP_MSG_SV_CONFIGURATION_GPS_DEP = 0x0091
class MsgSvConfigurationGPSDep(SBP):
  """SBP class for message MSG_SV_CONFIGURATION_GPS_DEP (0x0091).

  You can have MSG_SV_CONFIGURATION_GPS_DEP inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  Please see ICD-GPS-200 (Chapter 20.3.3.5.1.4) for more details.


  """
  __slots__ = ['t_nmct',
               'l2c_mask',
               ]
  @classmethod
  def parse_members(cls, buf, offset, length):
    ret = {}
    (__t_nmct, offset, length) = GPSTimeSec.parse_members(buf, offset, length)
    ret['t_nmct'] = __t_nmct
    (__l2c_mask, offset, length) = get_u32(buf, offset, length)
    ret['l2c_mask'] = __l2c_mask
    return ret, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.t_nmct = res['t_nmct']
    self.l2c_mask = res['l2c_mask']
    return res, off, length

  @classmethod
  def _payload_size(self):
    ret = 0
    # t_nmct: GPSTimeSec
    ret += GPSTimeSec._payload_size()
    # l2c_mask: u32
    ret += 4
    return ret
  
class GnssCapb(object):
  """SBP class for message GnssCapb

  You can have GnssCapb inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  

  """
  __slots__ = ['gps_active',
               'gps_l2c',
               'gps_l5',
               'glo_active',
               'glo_l2of',
               'glo_l3',
               'sbas_active',
               'sbas_l5',
               'bds_active',
               'bds_d2nav',
               'bds_b2',
               'bds_b2a',
               'qzss_active',
               'gal_active',
               'gal_e5',
               ]
  @classmethod
  def parse_members(cls, buf, offset, length):
    ret = {}
    (__gps_active, offset, length) = get_u64(buf, offset, length)
    ret['gps_active'] = __gps_active
    (__gps_l2c, offset, length) = get_u64(buf, offset, length)
    ret['gps_l2c'] = __gps_l2c
    (__gps_l5, offset, length) = get_u64(buf, offset, length)
    ret['gps_l5'] = __gps_l5
    (__glo_active, offset, length) = get_u32(buf, offset, length)
    ret['glo_active'] = __glo_active
    (__glo_l2of, offset, length) = get_u32(buf, offset, length)
    ret['glo_l2of'] = __glo_l2of
    (__glo_l3, offset, length) = get_u32(buf, offset, length)
    ret['glo_l3'] = __glo_l3
    (__sbas_active, offset, length) = get_u64(buf, offset, length)
    ret['sbas_active'] = __sbas_active
    (__sbas_l5, offset, length) = get_u64(buf, offset, length)
    ret['sbas_l5'] = __sbas_l5
    (__bds_active, offset, length) = get_u64(buf, offset, length)
    ret['bds_active'] = __bds_active
    (__bds_d2nav, offset, length) = get_u64(buf, offset, length)
    ret['bds_d2nav'] = __bds_d2nav
    (__bds_b2, offset, length) = get_u64(buf, offset, length)
    ret['bds_b2'] = __bds_b2
    (__bds_b2a, offset, length) = get_u64(buf, offset, length)
    ret['bds_b2a'] = __bds_b2a
    (__qzss_active, offset, length) = get_u32(buf, offset, length)
    ret['qzss_active'] = __qzss_active
    (__gal_active, offset, length) = get_u64(buf, offset, length)
    ret['gal_active'] = __gal_active
    (__gal_e5, offset, length) = get_u64(buf, offset, length)
    ret['gal_e5'] = __gal_e5
    return ret, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.gps_active = res['gps_active']
    self.gps_l2c = res['gps_l2c']
    self.gps_l5 = res['gps_l5']
    self.glo_active = res['glo_active']
    self.glo_l2of = res['glo_l2of']
    self.glo_l3 = res['glo_l3']
    self.sbas_active = res['sbas_active']
    self.sbas_l5 = res['sbas_l5']
    self.bds_active = res['bds_active']
    self.bds_d2nav = res['bds_d2nav']
    self.bds_b2 = res['bds_b2']
    self.bds_b2a = res['bds_b2a']
    self.qzss_active = res['qzss_active']
    self.gal_active = res['gal_active']
    self.gal_e5 = res['gal_e5']
    return res, off, length

  @classmethod
  def _payload_size(self):
    ret = 0
    # gps_active: u64
    ret += 8
    # gps_l2c: u64
    ret += 8
    # gps_l5: u64
    ret += 8
    # glo_active: u32
    ret += 4
    # glo_l2of: u32
    ret += 4
    # glo_l3: u32
    ret += 4
    # sbas_active: u64
    ret += 8
    # sbas_l5: u64
    ret += 8
    # bds_active: u64
    ret += 8
    # bds_d2nav: u64
    ret += 8
    # bds_b2: u64
    ret += 8
    # bds_b2a: u64
    ret += 8
    # qzss_active: u32
    ret += 4
    # gal_active: u64
    ret += 8
    # gal_e5: u64
    ret += 8
    return ret
  
SBP_MSG_GNSS_CAPB = 0x0096
class MsgGnssCapb(SBP):
  """SBP class for message MSG_GNSS_CAPB (0x0096).

  You can have MSG_GNSS_CAPB inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  

  """
  __slots__ = ['t_nmct',
               'gc',
               ]
  @classmethod
  def parse_members(cls, buf, offset, length):
    ret = {}
    (__t_nmct, offset, length) = GPSTimeSec.parse_members(buf, offset, length)
    ret['t_nmct'] = __t_nmct
    (__gc, offset, length) = GnssCapb.parse_members(buf, offset, length)
    ret['gc'] = __gc
    return ret, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.t_nmct = res['t_nmct']
    self.gc = res['gc']
    return res, off, length

  @classmethod
  def _payload_size(self):
    ret = 0
    # t_nmct: GPSTimeSec
    ret += GPSTimeSec._payload_size()
    # gc: GnssCapb
    ret += GnssCapb._payload_size()
    return ret
  
SBP_MSG_GROUP_DELAY_DEP_A = 0x0092
class MsgGroupDelayDepA(SBP):
  """SBP class for message MSG_GROUP_DELAY_DEP_A (0x0092).

  You can have MSG_GROUP_DELAY_DEP_A inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  Please see ICD-GPS-200 (30.3.3.3.1.1) for more details.

  """
  __slots__ = ['t_op',
               'prn',
               'valid',
               'tgd',
               'isc_l1ca',
               'isc_l2c',
               ]
  @classmethod
  def parse_members(cls, buf, offset, length):
    ret = {}
    (__t_op, offset, length) = GPSTimeDep.parse_members(buf, offset, length)
    ret['t_op'] = __t_op
    (__prn, offset, length) = get_u8(buf, offset, length)
    ret['prn'] = __prn
    (__valid, offset, length) = get_u8(buf, offset, length)
    ret['valid'] = __valid
    (__tgd, offset, length) = get_s16(buf, offset, length)
    ret['tgd'] = __tgd
    (__isc_l1ca, offset, length) = get_s16(buf, offset, length)
    ret['isc_l1ca'] = __isc_l1ca
    (__isc_l2c, offset, length) = get_s16(buf, offset, length)
    ret['isc_l2c'] = __isc_l2c
    return ret, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.t_op = res['t_op']
    self.prn = res['prn']
    self.valid = res['valid']
    self.tgd = res['tgd']
    self.isc_l1ca = res['isc_l1ca']
    self.isc_l2c = res['isc_l2c']
    return res, off, length

  @classmethod
  def _payload_size(self):
    ret = 0
    # t_op: GPSTimeDep
    ret += GPSTimeDep._payload_size()
    # prn: u8
    ret += 1
    # valid: u8
    ret += 1
    # tgd: s16
    ret += 2
    # isc_l1ca: s16
    ret += 2
    # isc_l2c: s16
    ret += 2
    return ret
  
SBP_MSG_GROUP_DELAY_DEP_B = 0x0093
class MsgGroupDelayDepB(SBP):
  """SBP class for message MSG_GROUP_DELAY_DEP_B (0x0093).

  You can have MSG_GROUP_DELAY_DEP_B inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  Please see ICD-GPS-200 (30.3.3.3.1.1) for more details.

  """
  __slots__ = ['t_op',
               'sid',
               'valid',
               'tgd',
               'isc_l1ca',
               'isc_l2c',
               ]
  @classmethod
  def parse_members(cls, buf, offset, length):
    ret = {}
    (__t_op, offset, length) = GPSTimeSec.parse_members(buf, offset, length)
    ret['t_op'] = __t_op
    (__sid, offset, length) = GnssSignalDep.parse_members(buf, offset, length)
    ret['sid'] = __sid
    (__valid, offset, length) = get_u8(buf, offset, length)
    ret['valid'] = __valid
    (__tgd, offset, length) = get_s16(buf, offset, length)
    ret['tgd'] = __tgd
    (__isc_l1ca, offset, length) = get_s16(buf, offset, length)
    ret['isc_l1ca'] = __isc_l1ca
    (__isc_l2c, offset, length) = get_s16(buf, offset, length)
    ret['isc_l2c'] = __isc_l2c
    return ret, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.t_op = res['t_op']
    self.sid = res['sid']
    self.valid = res['valid']
    self.tgd = res['tgd']
    self.isc_l1ca = res['isc_l1ca']
    self.isc_l2c = res['isc_l2c']
    return res, off, length

  @classmethod
  def _payload_size(self):
    ret = 0
    # t_op: GPSTimeSec
    ret += GPSTimeSec._payload_size()
    # sid: GnssSignalDep
    ret += GnssSignalDep._payload_size()
    # valid: u8
    ret += 1
    # tgd: s16
    ret += 2
    # isc_l1ca: s16
    ret += 2
    # isc_l2c: s16
    ret += 2
    return ret
  
SBP_MSG_GROUP_DELAY = 0x0094
class MsgGroupDelay(SBP):
  """SBP class for message MSG_GROUP_DELAY (0x0094).

  You can have MSG_GROUP_DELAY inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  Please see ICD-GPS-200 (30.3.3.3.1.1) for more details.

  """
  __slots__ = ['t_op',
               'sid',
               'valid',
               'tgd',
               'isc_l1ca',
               'isc_l2c',
               ]
  @classmethod
  def parse_members(cls, buf, offset, length):
    ret = {}
    (__t_op, offset, length) = GPSTimeSec.parse_members(buf, offset, length)
    ret['t_op'] = __t_op
    (__sid, offset, length) = GnssSignal.parse_members(buf, offset, length)
    ret['sid'] = __sid
    (__valid, offset, length) = get_u8(buf, offset, length)
    ret['valid'] = __valid
    (__tgd, offset, length) = get_s16(buf, offset, length)
    ret['tgd'] = __tgd
    (__isc_l1ca, offset, length) = get_s16(buf, offset, length)
    ret['isc_l1ca'] = __isc_l1ca
    (__isc_l2c, offset, length) = get_s16(buf, offset, length)
    ret['isc_l2c'] = __isc_l2c
    return ret, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.t_op = res['t_op']
    self.sid = res['sid']
    self.valid = res['valid']
    self.tgd = res['tgd']
    self.isc_l1ca = res['isc_l1ca']
    self.isc_l2c = res['isc_l2c']
    return res, off, length

  @classmethod
  def _payload_size(self):
    ret = 0
    # t_op: GPSTimeSec
    ret += GPSTimeSec._payload_size()
    # sid: GnssSignal
    ret += GnssSignal._payload_size()
    # valid: u8
    ret += 1
    # tgd: s16
    ret += 2
    # isc_l1ca: s16
    ret += 2
    # isc_l2c: s16
    ret += 2
    return ret
  
class AlmanacCommonContent(object):
  """SBP class for message AlmanacCommonContent

  You can have AlmanacCommonContent inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  

  """
  __slots__ = ['sid',
               'toa',
               'ura',
               'fit_interval',
               'valid',
               'health_bits',
               ]
  @classmethod
  def parse_members(cls, buf, offset, length):
    ret = {}
    (__sid, offset, length) = GnssSignal.parse_members(buf, offset, length)
    ret['sid'] = __sid
    (__toa, offset, length) = GPSTimeSec.parse_members(buf, offset, length)
    ret['toa'] = __toa
    (__ura, offset, length) = get_f64(buf, offset, length)
    ret['ura'] = __ura
    (__fit_interval, offset, length) = get_u32(buf, offset, length)
    ret['fit_interval'] = __fit_interval
    (__valid, offset, length) = get_u8(buf, offset, length)
    ret['valid'] = __valid
    (__health_bits, offset, length) = get_u8(buf, offset, length)
    ret['health_bits'] = __health_bits
    return ret, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.sid = res['sid']
    self.toa = res['toa']
    self.ura = res['ura']
    self.fit_interval = res['fit_interval']
    self.valid = res['valid']
    self.health_bits = res['health_bits']
    return res, off, length

  @classmethod
  def _payload_size(self):
    ret = 0
    # sid: GnssSignal
    ret += GnssSignal._payload_size()
    # toa: GPSTimeSec
    ret += GPSTimeSec._payload_size()
    # ura: double
    ret += 8
    # fit_interval: u32
    ret += 4
    # valid: u8
    ret += 1
    # health_bits: u8
    ret += 1
    return ret
  
class AlmanacCommonContentDep(object):
  """SBP class for message AlmanacCommonContentDep

  You can have AlmanacCommonContentDep inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  

  """
  __slots__ = ['sid',
               'toa',
               'ura',
               'fit_interval',
               'valid',
               'health_bits',
               ]
  @classmethod
  def parse_members(cls, buf, offset, length):
    ret = {}
    (__sid, offset, length) = GnssSignalDep.parse_members(buf, offset, length)
    ret['sid'] = __sid
    (__toa, offset, length) = GPSTimeSec.parse_members(buf, offset, length)
    ret['toa'] = __toa
    (__ura, offset, length) = get_f64(buf, offset, length)
    ret['ura'] = __ura
    (__fit_interval, offset, length) = get_u32(buf, offset, length)
    ret['fit_interval'] = __fit_interval
    (__valid, offset, length) = get_u8(buf, offset, length)
    ret['valid'] = __valid
    (__health_bits, offset, length) = get_u8(buf, offset, length)
    ret['health_bits'] = __health_bits
    return ret, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.sid = res['sid']
    self.toa = res['toa']
    self.ura = res['ura']
    self.fit_interval = res['fit_interval']
    self.valid = res['valid']
    self.health_bits = res['health_bits']
    return res, off, length

  @classmethod
  def _payload_size(self):
    ret = 0
    # sid: GnssSignalDep
    ret += GnssSignalDep._payload_size()
    # toa: GPSTimeSec
    ret += GPSTimeSec._payload_size()
    # ura: double
    ret += 8
    # fit_interval: u32
    ret += 4
    # valid: u8
    ret += 1
    # health_bits: u8
    ret += 1
    return ret
  
SBP_MSG_ALMANAC_GPS_DEP = 0x0070
class MsgAlmanacGPSDep(SBP):
  """SBP class for message MSG_ALMANAC_GPS_DEP (0x0070).

  You can have MSG_ALMANAC_GPS_DEP inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  The almanac message returns a set of satellite orbit parameters. Almanac
data is not very precise and is considered valid for up to several months.
Please see the Navstar GPS Space Segment/Navigation user interfaces
(ICD-GPS-200, Chapter 20.3.3.5.1.2 Almanac Data) for more details.


  """
  __slots__ = ['common',
               'm0',
               'ecc',
               'sqrta',
               'omega0',
               'omegadot',
               'w',
               'inc',
               'af0',
               'af1',
               ]
  @classmethod
  def parse_members(cls, buf, offset, length):
    ret = {}
    (__common, offset, length) = AlmanacCommonContentDep.parse_members(buf, offset, length)
    ret['common'] = __common
    (__m0, offset, length) = get_f64(buf, offset, length)
    ret['m0'] = __m0
    (__ecc, offset, length) = get_f64(buf, offset, length)
    ret['ecc'] = __ecc
    (__sqrta, offset, length) = get_f64(buf, offset, length)
    ret['sqrta'] = __sqrta
    (__omega0, offset, length) = get_f64(buf, offset, length)
    ret['omega0'] = __omega0
    (__omegadot, offset, length) = get_f64(buf, offset, length)
    ret['omegadot'] = __omegadot
    (__w, offset, length) = get_f64(buf, offset, length)
    ret['w'] = __w
    (__inc, offset, length) = get_f64(buf, offset, length)
    ret['inc'] = __inc
    (__af0, offset, length) = get_f64(buf, offset, length)
    ret['af0'] = __af0
    (__af1, offset, length) = get_f64(buf, offset, length)
    ret['af1'] = __af1
    return ret, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.common = res['common']
    self.m0 = res['m0']
    self.ecc = res['ecc']
    self.sqrta = res['sqrta']
    self.omega0 = res['omega0']
    self.omegadot = res['omegadot']
    self.w = res['w']
    self.inc = res['inc']
    self.af0 = res['af0']
    self.af1 = res['af1']
    return res, off, length

  @classmethod
  def _payload_size(self):
    ret = 0
    # common: AlmanacCommonContentDep
    ret += AlmanacCommonContentDep._payload_size()
    # m0: double
    ret += 8
    # ecc: double
    ret += 8
    # sqrta: double
    ret += 8
    # omega0: double
    ret += 8
    # omegadot: double
    ret += 8
    # w: double
    ret += 8
    # inc: double
    ret += 8
    # af0: double
    ret += 8
    # af1: double
    ret += 8
    return ret
  
SBP_MSG_ALMANAC_GPS = 0x0072
class MsgAlmanacGPS(SBP):
  """SBP class for message MSG_ALMANAC_GPS (0x0072).

  You can have MSG_ALMANAC_GPS inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  The almanac message returns a set of satellite orbit parameters. Almanac
data is not very precise and is considered valid for up to several months.
Please see the Navstar GPS Space Segment/Navigation user interfaces
(ICD-GPS-200, Chapter 20.3.3.5.1.2 Almanac Data) for more details.


  """
  __slots__ = ['common',
               'm0',
               'ecc',
               'sqrta',
               'omega0',
               'omegadot',
               'w',
               'inc',
               'af0',
               'af1',
               ]
  @classmethod
  def parse_members(cls, buf, offset, length):
    ret = {}
    (__common, offset, length) = AlmanacCommonContent.parse_members(buf, offset, length)
    ret['common'] = __common
    (__m0, offset, length) = get_f64(buf, offset, length)
    ret['m0'] = __m0
    (__ecc, offset, length) = get_f64(buf, offset, length)
    ret['ecc'] = __ecc
    (__sqrta, offset, length) = get_f64(buf, offset, length)
    ret['sqrta'] = __sqrta
    (__omega0, offset, length) = get_f64(buf, offset, length)
    ret['omega0'] = __omega0
    (__omegadot, offset, length) = get_f64(buf, offset, length)
    ret['omegadot'] = __omegadot
    (__w, offset, length) = get_f64(buf, offset, length)
    ret['w'] = __w
    (__inc, offset, length) = get_f64(buf, offset, length)
    ret['inc'] = __inc
    (__af0, offset, length) = get_f64(buf, offset, length)
    ret['af0'] = __af0
    (__af1, offset, length) = get_f64(buf, offset, length)
    ret['af1'] = __af1
    return ret, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.common = res['common']
    self.m0 = res['m0']
    self.ecc = res['ecc']
    self.sqrta = res['sqrta']
    self.omega0 = res['omega0']
    self.omegadot = res['omegadot']
    self.w = res['w']
    self.inc = res['inc']
    self.af0 = res['af0']
    self.af1 = res['af1']
    return res, off, length

  @classmethod
  def _payload_size(self):
    ret = 0
    # common: AlmanacCommonContent
    ret += AlmanacCommonContent._payload_size()
    # m0: double
    ret += 8
    # ecc: double
    ret += 8
    # sqrta: double
    ret += 8
    # omega0: double
    ret += 8
    # omegadot: double
    ret += 8
    # w: double
    ret += 8
    # inc: double
    ret += 8
    # af0: double
    ret += 8
    # af1: double
    ret += 8
    return ret
  
SBP_MSG_ALMANAC_GLO_DEP = 0x0071
class MsgAlmanacGloDep(SBP):
  """SBP class for message MSG_ALMANAC_GLO_DEP (0x0071).

  You can have MSG_ALMANAC_GLO_DEP inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  The almanac message returns a set of satellite orbit parameters. Almanac
data is not very precise and is considered valid for up to several months.
Please see the GLO ICD 5.1 "Chapter 4.5 Non-immediate information and
almanac" for details.


  """
  __slots__ = ['common',
               'lambda_na',
               't_lambda_na',
               'i',
               't',
               't_dot',
               'epsilon',
               'omega',
               ]
  @classmethod
  def parse_members(cls, buf, offset, length):
    ret = {}
    (__common, offset, length) = AlmanacCommonContentDep.parse_members(buf, offset, length)
    ret['common'] = __common
    (__lambda_na, offset, length) = get_f64(buf, offset, length)
    ret['lambda_na'] = __lambda_na
    (__t_lambda_na, offset, length) = get_f64(buf, offset, length)
    ret['t_lambda_na'] = __t_lambda_na
    (__i, offset, length) = get_f64(buf, offset, length)
    ret['i'] = __i
    (__t, offset, length) = get_f64(buf, offset, length)
    ret['t'] = __t
    (__t_dot, offset, length) = get_f64(buf, offset, length)
    ret['t_dot'] = __t_dot
    (__epsilon, offset, length) = get_f64(buf, offset, length)
    ret['epsilon'] = __epsilon
    (__omega, offset, length) = get_f64(buf, offset, length)
    ret['omega'] = __omega
    return ret, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.common = res['common']
    self.lambda_na = res['lambda_na']
    self.t_lambda_na = res['t_lambda_na']
    self.i = res['i']
    self.t = res['t']
    self.t_dot = res['t_dot']
    self.epsilon = res['epsilon']
    self.omega = res['omega']
    return res, off, length

  @classmethod
  def _payload_size(self):
    ret = 0
    # common: AlmanacCommonContentDep
    ret += AlmanacCommonContentDep._payload_size()
    # lambda_na: double
    ret += 8
    # t_lambda_na: double
    ret += 8
    # i: double
    ret += 8
    # t: double
    ret += 8
    # t_dot: double
    ret += 8
    # epsilon: double
    ret += 8
    # omega: double
    ret += 8
    return ret
  
SBP_MSG_ALMANAC_GLO = 0x0073
class MsgAlmanacGlo(SBP):
  """SBP class for message MSG_ALMANAC_GLO (0x0073).

  You can have MSG_ALMANAC_GLO inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  The almanac message returns a set of satellite orbit parameters. Almanac
data is not very precise and is considered valid for up to several months.
Please see the GLO ICD 5.1 "Chapter 4.5 Non-immediate information and
almanac" for details.


  """
  __slots__ = ['common',
               'lambda_na',
               't_lambda_na',
               'i',
               't',
               't_dot',
               'epsilon',
               'omega',
               ]
  @classmethod
  def parse_members(cls, buf, offset, length):
    ret = {}
    (__common, offset, length) = AlmanacCommonContent.parse_members(buf, offset, length)
    ret['common'] = __common
    (__lambda_na, offset, length) = get_f64(buf, offset, length)
    ret['lambda_na'] = __lambda_na
    (__t_lambda_na, offset, length) = get_f64(buf, offset, length)
    ret['t_lambda_na'] = __t_lambda_na
    (__i, offset, length) = get_f64(buf, offset, length)
    ret['i'] = __i
    (__t, offset, length) = get_f64(buf, offset, length)
    ret['t'] = __t
    (__t_dot, offset, length) = get_f64(buf, offset, length)
    ret['t_dot'] = __t_dot
    (__epsilon, offset, length) = get_f64(buf, offset, length)
    ret['epsilon'] = __epsilon
    (__omega, offset, length) = get_f64(buf, offset, length)
    ret['omega'] = __omega
    return ret, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.common = res['common']
    self.lambda_na = res['lambda_na']
    self.t_lambda_na = res['t_lambda_na']
    self.i = res['i']
    self.t = res['t']
    self.t_dot = res['t_dot']
    self.epsilon = res['epsilon']
    self.omega = res['omega']
    return res, off, length

  @classmethod
  def _payload_size(self):
    ret = 0
    # common: AlmanacCommonContent
    ret += AlmanacCommonContent._payload_size()
    # lambda_na: double
    ret += 8
    # t_lambda_na: double
    ret += 8
    # i: double
    ret += 8
    # t: double
    ret += 8
    # t_dot: double
    ret += 8
    # epsilon: double
    ret += 8
    # omega: double
    ret += 8
    return ret
  
SBP_MSG_GLO_BIASES = 0x0075
class MsgGloBiases(SBP):
  """SBP class for message MSG_GLO_BIASES (0x0075).

  You can have MSG_GLO_BIASES inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  The GLONASS L1/L2 Code-Phase biases allows to perform
GPS+GLONASS integer ambiguity resolution for baselines
with mixed receiver types (e.g. receiver of different
manufacturers)


  """
  __slots__ = ['mask',
               'l1ca_bias',
               'l1p_bias',
               'l2ca_bias',
               'l2p_bias',
               ]
  @classmethod
  def parse_members(cls, buf, offset, length):
    ret = {}
    (__mask, offset, length) = get_u8(buf, offset, length)
    ret['mask'] = __mask
    (__l1ca_bias, offset, length) = get_s16(buf, offset, length)
    ret['l1ca_bias'] = __l1ca_bias
    (__l1p_bias, offset, length) = get_s16(buf, offset, length)
    ret['l1p_bias'] = __l1p_bias
    (__l2ca_bias, offset, length) = get_s16(buf, offset, length)
    ret['l2ca_bias'] = __l2ca_bias
    (__l2p_bias, offset, length) = get_s16(buf, offset, length)
    ret['l2p_bias'] = __l2p_bias
    return ret, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.mask = res['mask']
    self.l1ca_bias = res['l1ca_bias']
    self.l1p_bias = res['l1p_bias']
    self.l2ca_bias = res['l2ca_bias']
    self.l2p_bias = res['l2p_bias']
    return res, off, length

  @classmethod
  def _payload_size(self):
    ret = 0
    # mask: u8
    ret += 1
    # l1ca_bias: s16
    ret += 2
    # l1p_bias: s16
    ret += 2
    # l2ca_bias: s16
    ret += 2
    # l2p_bias: s16
    ret += 2
    return ret
  
class SvAzEl(object):
  """SBP class for message SvAzEl

  You can have SvAzEl inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  Satellite azimuth and elevation.

  """
  __slots__ = ['sid',
               'az',
               'el',
               ]
  @classmethod
  def parse_members(cls, buf, offset, length):
    ret = {}
    (__sid, offset, length) = GnssSignal.parse_members(buf, offset, length)
    ret['sid'] = __sid
    (__az, offset, length) = get_u8(buf, offset, length)
    ret['az'] = __az
    (__el, offset, length) = get_s8(buf, offset, length)
    ret['el'] = __el
    return ret, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.sid = res['sid']
    self.az = res['az']
    self.el = res['el']
    return res, off, length

  @classmethod
  def _payload_size(self):
    ret = 0
    # sid: GnssSignal
    ret += GnssSignal._payload_size()
    # az: u8
    ret += 1
    # el: s8
    ret += 1
    return ret
  
SBP_MSG_SV_AZ_EL = 0x0097
class MsgSvAzEl(SBP):
  """SBP class for message MSG_SV_AZ_EL (0x0097).

  You can have MSG_SV_AZ_EL inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  Azimuth and elevation angles of all the visible satellites
that the device does have ephemeris or almanac for.


  """
  __slots__ = ['azel',
               ]
  @classmethod
  def parse_members(cls, buf, offset, length):
    ret = {}
    (__azel, offset, length) = get_array(SvAzEl.parse_members)(buf, offset, length)
    ret['azel'] = __azel
    return ret, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.azel = res['azel']
    return res, off, length

  @classmethod
  def _payload_size(self):
    ret = 0
    # azel: array of SvAzEl
    ret += 247
    return ret
  
SBP_MSG_OSR = 0x0640
class MsgOsr(SBP):
  """SBP class for message MSG_OSR (0x0640).

  You can have MSG_OSR inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  The OSR message contains network corrections in an observation-like format


  """
  __slots__ = ['header',
               'obs',
               ]
  @classmethod
  def parse_members(cls, buf, offset, length):
    ret = {}
    (__header, offset, length) = ObservationHeader.parse_members(buf, offset, length)
    ret['header'] = __header
    (__obs, offset, length) = get_array(PackedOsrContent.parse_members)(buf, offset, length)
    ret['obs'] = __obs
    return ret, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.header = res['header']
    self.obs = res['obs']
    return res, off, length

  @classmethod
  def _payload_size(self):
    ret = 0
    # header: ObservationHeader
    ret += ObservationHeader._payload_size()
    # obs: array of PackedOsrContent
    ret += 247
    return ret
  

msg_classes = {
  0x004A: MsgObs,
  0x0044: MsgBasePosLLH,
  0x0048: MsgBasePosECEF,
  0x0081: MsgEphemerisGPSDepE,
  0x0086: MsgEphemerisGPSDepF,
  0x008A: MsgEphemerisGPS,
  0x008E: MsgEphemerisQzss,
  0x0089: MsgEphemerisBds,
  0x0095: MsgEphemerisGalDepA,
  0x008D: MsgEphemerisGal,
  0x0082: MsgEphemerisSbasDepA,
  0x0083: MsgEphemerisGloDepA,
  0x0084: MsgEphemerisSbasDepB,
  0x008C: MsgEphemerisSbas,
  0x0085: MsgEphemerisGloDepB,
  0x0087: MsgEphemerisGloDepC,
  0x0088: MsgEphemerisGloDepD,
  0x008B: MsgEphemerisGlo,
  0x0080: MsgEphemerisDepD,
  0x001A: MsgEphemerisDepA,
  0x0046: MsgEphemerisDepB,
  0x0047: MsgEphemerisDepC,
  0x0045: MsgObsDepA,
  0x0043: MsgObsDepB,
  0x0049: MsgObsDepC,
  0x0090: MsgIono,
  0x0091: MsgSvConfigurationGPSDep,
  0x0096: MsgGnssCapb,
  0x0092: MsgGroupDelayDepA,
  0x0093: MsgGroupDelayDepB,
  0x0094: MsgGroupDelay,
  0x0070: MsgAlmanacGPSDep,
  0x0072: MsgAlmanacGPS,
  0x0071: MsgAlmanacGloDep,
  0x0073: MsgAlmanacGlo,
  0x0075: MsgGloBiases,
  0x0097: MsgSvAzEl,
  0x0640: MsgOsr,
}