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

from sbp.jit.msg import SBP, SENDER_ID
from sbp.jit.msg import get_u8, get_u16, get_u32, get_u64
from sbp.jit.msg import get_s8, get_s16, get_s32, get_s64
from sbp.jit.msg import get_f32, get_f64
from sbp.jit.msg import get_string, get_fixed_string
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
    o_0 = offset
    o_1, (__t, offset, length) = offset, GPSTime.parse_members(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__n_obs, offset, length) = offset, get_u8(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    return {
      't' : __t,
      'n_obs' : __n_obs,
    }, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.t = res['t']
    self.n_obs = res['n_obs']
    return res, off, length
  
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
    o_0 = offset
    o_1, (__i, offset, length) = offset, get_s16(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__f, offset, length) = offset, get_u8(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    return {
      'i' : __i,
      'f' : __f,
    }, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.i = res['i']
    self.f = res['f']
    return res, off, length
  
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
    o_0 = offset
    o_1, (__P, offset, length) = offset, get_u32(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__L, offset, length) = offset, CarrierPhase.parse_members(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__D, offset, length) = offset, Doppler.parse_members(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__cn0, offset, length) = offset, get_u8(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__lock, offset, length) = offset, get_u8(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__flags, offset, length) = offset, get_u8(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__sid, offset, length) = offset, GnssSignal.parse_members(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    return {
      'P' : __P,
      'L' : __L,
      'D' : __D,
      'cn0' : __cn0,
      'lock' : __lock,
      'flags' : __flags,
      'sid' : __sid,
    }, offset, length

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
    o_0 = offset
    o_1, (__header, offset, length) = offset, ObservationHeader.parse_members(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__obs, offset, length) = offset, get_array(PackedObsContent.parse_members)(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    return {
      'header' : __header,
      'obs' : __obs,
    }, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.header = res['header']
    self.obs = res['obs']
    return res, off, length
  
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
    o_0 = offset
    o_1, (__lat, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__lon, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__height, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    return {
      'lat' : __lat,
      'lon' : __lon,
      'height' : __height,
    }, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.lat = res['lat']
    self.lon = res['lon']
    self.height = res['height']
    return res, off, length
  
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
    o_0 = offset
    o_1, (__x, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__y, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__z, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    return {
      'x' : __x,
      'y' : __y,
      'z' : __z,
    }, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.x = res['x']
    self.y = res['y']
    self.z = res['z']
    return res, off, length
  
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
    o_0 = offset
    o_1, (__sid, offset, length) = offset, GnssSignal.parse_members(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__toe, offset, length) = offset, GPSTimeSec.parse_members(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__ura, offset, length) = offset, get_f32(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__fit_interval, offset, length) = offset, get_u32(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__valid, offset, length) = offset, get_u8(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__health_bits, offset, length) = offset, get_u8(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    return {
      'sid' : __sid,
      'toe' : __toe,
      'ura' : __ura,
      'fit_interval' : __fit_interval,
      'valid' : __valid,
      'health_bits' : __health_bits,
    }, offset, length

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
    o_0 = offset
    o_1, (__sid, offset, length) = offset, GnssSignal.parse_members(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__toe, offset, length) = offset, GPSTimeSec.parse_members(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__ura, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__fit_interval, offset, length) = offset, get_u32(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__valid, offset, length) = offset, get_u8(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__health_bits, offset, length) = offset, get_u8(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    return {
      'sid' : __sid,
      'toe' : __toe,
      'ura' : __ura,
      'fit_interval' : __fit_interval,
      'valid' : __valid,
      'health_bits' : __health_bits,
    }, offset, length

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
    o_0 = offset
    o_1, (__sid, offset, length) = offset, GnssSignalDep.parse_members(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__toe, offset, length) = offset, GPSTimeDep.parse_members(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__ura, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__fit_interval, offset, length) = offset, get_u32(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__valid, offset, length) = offset, get_u8(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__health_bits, offset, length) = offset, get_u8(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    return {
      'sid' : __sid,
      'toe' : __toe,
      'ura' : __ura,
      'fit_interval' : __fit_interval,
      'valid' : __valid,
      'health_bits' : __health_bits,
    }, offset, length

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
    o_0 = offset
    o_1, (__common, offset, length) = offset, EphemerisCommonContentDepA.parse_members(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__tgd, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__c_rs, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__c_rc, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__c_uc, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__c_us, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__c_ic, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__c_is, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__dn, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__m0, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__ecc, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__sqrta, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__omega0, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__omegadot, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__w, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__inc, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__inc_dot, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__af0, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__af1, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__af2, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__toc, offset, length) = offset, GPSTimeDep.parse_members(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__iode, offset, length) = offset, get_u8(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__iodc, offset, length) = offset, get_u16(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    return {
      'common' : __common,
      'tgd' : __tgd,
      'c_rs' : __c_rs,
      'c_rc' : __c_rc,
      'c_uc' : __c_uc,
      'c_us' : __c_us,
      'c_ic' : __c_ic,
      'c_is' : __c_is,
      'dn' : __dn,
      'm0' : __m0,
      'ecc' : __ecc,
      'sqrta' : __sqrta,
      'omega0' : __omega0,
      'omegadot' : __omegadot,
      'w' : __w,
      'inc' : __inc,
      'inc_dot' : __inc_dot,
      'af0' : __af0,
      'af1' : __af1,
      'af2' : __af2,
      'toc' : __toc,
      'iode' : __iode,
      'iodc' : __iodc,
    }, offset, length

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
    o_0 = offset
    o_1, (__common, offset, length) = offset, EphemerisCommonContentDepB.parse_members(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__tgd, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__c_rs, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__c_rc, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__c_uc, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__c_us, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__c_ic, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__c_is, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__dn, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__m0, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__ecc, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__sqrta, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__omega0, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__omegadot, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__w, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__inc, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__inc_dot, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__af0, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__af1, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__af2, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__toc, offset, length) = offset, GPSTimeSec.parse_members(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__iode, offset, length) = offset, get_u8(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__iodc, offset, length) = offset, get_u16(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    return {
      'common' : __common,
      'tgd' : __tgd,
      'c_rs' : __c_rs,
      'c_rc' : __c_rc,
      'c_uc' : __c_uc,
      'c_us' : __c_us,
      'c_ic' : __c_ic,
      'c_is' : __c_is,
      'dn' : __dn,
      'm0' : __m0,
      'ecc' : __ecc,
      'sqrta' : __sqrta,
      'omega0' : __omega0,
      'omegadot' : __omegadot,
      'w' : __w,
      'inc' : __inc,
      'inc_dot' : __inc_dot,
      'af0' : __af0,
      'af1' : __af1,
      'af2' : __af2,
      'toc' : __toc,
      'iode' : __iode,
      'iodc' : __iodc,
    }, offset, length

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
    o_0 = offset
    o_1, (__common, offset, length) = offset, EphemerisCommonContent.parse_members(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__tgd, offset, length) = offset, get_f32(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__c_rs, offset, length) = offset, get_f32(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__c_rc, offset, length) = offset, get_f32(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__c_uc, offset, length) = offset, get_f32(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__c_us, offset, length) = offset, get_f32(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__c_ic, offset, length) = offset, get_f32(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__c_is, offset, length) = offset, get_f32(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__dn, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__m0, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__ecc, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__sqrta, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__omega0, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__omegadot, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__w, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__inc, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__inc_dot, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__af0, offset, length) = offset, get_f32(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__af1, offset, length) = offset, get_f32(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__af2, offset, length) = offset, get_f32(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__toc, offset, length) = offset, GPSTimeSec.parse_members(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__iode, offset, length) = offset, get_u8(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__iodc, offset, length) = offset, get_u16(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    return {
      'common' : __common,
      'tgd' : __tgd,
      'c_rs' : __c_rs,
      'c_rc' : __c_rc,
      'c_uc' : __c_uc,
      'c_us' : __c_us,
      'c_ic' : __c_ic,
      'c_is' : __c_is,
      'dn' : __dn,
      'm0' : __m0,
      'ecc' : __ecc,
      'sqrta' : __sqrta,
      'omega0' : __omega0,
      'omegadot' : __omegadot,
      'w' : __w,
      'inc' : __inc,
      'inc_dot' : __inc_dot,
      'af0' : __af0,
      'af1' : __af1,
      'af2' : __af2,
      'toc' : __toc,
      'iode' : __iode,
      'iodc' : __iodc,
    }, offset, length

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
    o_0 = offset
    o_1, (__common, offset, length) = offset, EphemerisCommonContent.parse_members(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__tgd1, offset, length) = offset, get_f32(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__tgd2, offset, length) = offset, get_f32(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__c_rs, offset, length) = offset, get_f32(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__c_rc, offset, length) = offset, get_f32(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__c_uc, offset, length) = offset, get_f32(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__c_us, offset, length) = offset, get_f32(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__c_ic, offset, length) = offset, get_f32(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__c_is, offset, length) = offset, get_f32(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__dn, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__m0, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__ecc, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__sqrta, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__omega0, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__omegadot, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__w, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__inc, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__inc_dot, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__af0, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__af1, offset, length) = offset, get_f32(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__af2, offset, length) = offset, get_f32(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__toc, offset, length) = offset, GPSTimeSec.parse_members(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__iode, offset, length) = offset, get_u8(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__iodc, offset, length) = offset, get_u16(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    return {
      'common' : __common,
      'tgd1' : __tgd1,
      'tgd2' : __tgd2,
      'c_rs' : __c_rs,
      'c_rc' : __c_rc,
      'c_uc' : __c_uc,
      'c_us' : __c_us,
      'c_ic' : __c_ic,
      'c_is' : __c_is,
      'dn' : __dn,
      'm0' : __m0,
      'ecc' : __ecc,
      'sqrta' : __sqrta,
      'omega0' : __omega0,
      'omegadot' : __omegadot,
      'w' : __w,
      'inc' : __inc,
      'inc_dot' : __inc_dot,
      'af0' : __af0,
      'af1' : __af1,
      'af2' : __af2,
      'toc' : __toc,
      'iode' : __iode,
      'iodc' : __iodc,
    }, offset, length

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
  
SBP_MSG_EPHEMERIS_GAL = 0x0095
class MsgEphemerisGal(SBP):
  """SBP class for message MSG_EPHEMERIS_GAL (0x0095).

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
               ]
  @classmethod
  def parse_members(cls, buf, offset, length):
    o_0 = offset
    o_1, (__common, offset, length) = offset, EphemerisCommonContent.parse_members(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__bgd_e1e5a, offset, length) = offset, get_f32(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__bgd_e1e5b, offset, length) = offset, get_f32(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__c_rs, offset, length) = offset, get_f32(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__c_rc, offset, length) = offset, get_f32(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__c_uc, offset, length) = offset, get_f32(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__c_us, offset, length) = offset, get_f32(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__c_ic, offset, length) = offset, get_f32(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__c_is, offset, length) = offset, get_f32(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__dn, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__m0, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__ecc, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__sqrta, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__omega0, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__omegadot, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__w, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__inc, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__inc_dot, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__af0, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__af1, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__af2, offset, length) = offset, get_f32(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__toc, offset, length) = offset, GPSTimeSec.parse_members(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__iode, offset, length) = offset, get_u16(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__iodc, offset, length) = offset, get_u16(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    return {
      'common' : __common,
      'bgd_e1e5a' : __bgd_e1e5a,
      'bgd_e1e5b' : __bgd_e1e5b,
      'c_rs' : __c_rs,
      'c_rc' : __c_rc,
      'c_uc' : __c_uc,
      'c_us' : __c_us,
      'c_ic' : __c_ic,
      'c_is' : __c_is,
      'dn' : __dn,
      'm0' : __m0,
      'ecc' : __ecc,
      'sqrta' : __sqrta,
      'omega0' : __omega0,
      'omegadot' : __omegadot,
      'w' : __w,
      'inc' : __inc,
      'inc_dot' : __inc_dot,
      'af0' : __af0,
      'af1' : __af1,
      'af2' : __af2,
      'toc' : __toc,
      'iode' : __iode,
      'iodc' : __iodc,
    }, offset, length

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
    o_0 = offset
    o_1, (__common, offset, length) = offset, EphemerisCommonContentDepA.parse_members(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__pos, offset, length) = offset, get_fixed_array(get_u8, 3, 1)(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__vel, offset, length) = offset, get_fixed_array(get_u8, 3, 1)(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__acc, offset, length) = offset, get_fixed_array(get_u8, 3, 1)(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__a_gf0, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__a_gf1, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    return {
      'common' : __common,
      'pos' : __pos,
      'vel' : __vel,
      'acc' : __acc,
      'a_gf0' : __a_gf0,
      'a_gf1' : __a_gf1,
    }, offset, length

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
    o_0 = offset
    o_1, (__common, offset, length) = offset, EphemerisCommonContentDepA.parse_members(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__gamma, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__tau, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__pos, offset, length) = offset, get_fixed_array(get_u8, 3, 1)(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__vel, offset, length) = offset, get_fixed_array(get_u8, 3, 1)(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__acc, offset, length) = offset, get_fixed_array(get_u8, 3, 1)(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    return {
      'common' : __common,
      'gamma' : __gamma,
      'tau' : __tau,
      'pos' : __pos,
      'vel' : __vel,
      'acc' : __acc,
    }, offset, length

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
    o_0 = offset
    o_1, (__common, offset, length) = offset, EphemerisCommonContentDepB.parse_members(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__pos, offset, length) = offset, get_fixed_array(get_u8, 3, 1)(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__vel, offset, length) = offset, get_fixed_array(get_u8, 3, 1)(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__acc, offset, length) = offset, get_fixed_array(get_u8, 3, 1)(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__a_gf0, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__a_gf1, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    return {
      'common' : __common,
      'pos' : __pos,
      'vel' : __vel,
      'acc' : __acc,
      'a_gf0' : __a_gf0,
      'a_gf1' : __a_gf1,
    }, offset, length

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
    o_0 = offset
    o_1, (__common, offset, length) = offset, EphemerisCommonContent.parse_members(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__pos, offset, length) = offset, get_fixed_array(get_u8, 3, 1)(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__vel, offset, length) = offset, get_fixed_array(get_u8, 3, 1)(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__acc, offset, length) = offset, get_fixed_array(get_u8, 3, 1)(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__a_gf0, offset, length) = offset, get_f32(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__a_gf1, offset, length) = offset, get_f32(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    return {
      'common' : __common,
      'pos' : __pos,
      'vel' : __vel,
      'acc' : __acc,
      'a_gf0' : __a_gf0,
      'a_gf1' : __a_gf1,
    }, offset, length

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
    o_0 = offset
    o_1, (__common, offset, length) = offset, EphemerisCommonContentDepB.parse_members(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__gamma, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__tau, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__pos, offset, length) = offset, get_fixed_array(get_u8, 3, 1)(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__vel, offset, length) = offset, get_fixed_array(get_u8, 3, 1)(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__acc, offset, length) = offset, get_fixed_array(get_u8, 3, 1)(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    return {
      'common' : __common,
      'gamma' : __gamma,
      'tau' : __tau,
      'pos' : __pos,
      'vel' : __vel,
      'acc' : __acc,
    }, offset, length

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
    o_0 = offset
    o_1, (__common, offset, length) = offset, EphemerisCommonContentDepB.parse_members(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__gamma, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__tau, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__d_tau, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__pos, offset, length) = offset, get_fixed_array(get_u8, 3, 1)(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__vel, offset, length) = offset, get_fixed_array(get_u8, 3, 1)(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__acc, offset, length) = offset, get_fixed_array(get_u8, 3, 1)(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__fcn, offset, length) = offset, get_u8(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    return {
      'common' : __common,
      'gamma' : __gamma,
      'tau' : __tau,
      'd_tau' : __d_tau,
      'pos' : __pos,
      'vel' : __vel,
      'acc' : __acc,
      'fcn' : __fcn,
    }, offset, length

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
    o_0 = offset
    o_1, (__common, offset, length) = offset, EphemerisCommonContentDepB.parse_members(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__gamma, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__tau, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__d_tau, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__pos, offset, length) = offset, get_fixed_array(get_u8, 3, 1)(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__vel, offset, length) = offset, get_fixed_array(get_u8, 3, 1)(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__acc, offset, length) = offset, get_fixed_array(get_u8, 3, 1)(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__fcn, offset, length) = offset, get_u8(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__iod, offset, length) = offset, get_u8(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    return {
      'common' : __common,
      'gamma' : __gamma,
      'tau' : __tau,
      'd_tau' : __d_tau,
      'pos' : __pos,
      'vel' : __vel,
      'acc' : __acc,
      'fcn' : __fcn,
      'iod' : __iod,
    }, offset, length

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
    o_0 = offset
    o_1, (__common, offset, length) = offset, EphemerisCommonContent.parse_members(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__gamma, offset, length) = offset, get_f32(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__tau, offset, length) = offset, get_f32(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__d_tau, offset, length) = offset, get_f32(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__pos, offset, length) = offset, get_fixed_array(get_u8, 3, 1)(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__vel, offset, length) = offset, get_fixed_array(get_u8, 3, 1)(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__acc, offset, length) = offset, get_fixed_array(get_u8, 3, 1)(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__fcn, offset, length) = offset, get_u8(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__iod, offset, length) = offset, get_u8(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    return {
      'common' : __common,
      'gamma' : __gamma,
      'tau' : __tau,
      'd_tau' : __d_tau,
      'pos' : __pos,
      'vel' : __vel,
      'acc' : __acc,
      'fcn' : __fcn,
      'iod' : __iod,
    }, offset, length

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
    o_0 = offset
    o_1, (__tgd, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__c_rs, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__c_rc, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__c_uc, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__c_us, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__c_ic, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__c_is, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__dn, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__m0, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__ecc, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__sqrta, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__omega0, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__omegadot, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__w, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__inc, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__inc_dot, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__af0, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__af1, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__af2, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__toe_tow, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__toe_wn, offset, length) = offset, get_u16(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__toc_tow, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__toc_wn, offset, length) = offset, get_u16(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__valid, offset, length) = offset, get_u8(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__healthy, offset, length) = offset, get_u8(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__sid, offset, length) = offset, GnssSignalDep.parse_members(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__iode, offset, length) = offset, get_u8(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__iodc, offset, length) = offset, get_u16(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__reserved, offset, length) = offset, get_u32(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    return {
      'tgd' : __tgd,
      'c_rs' : __c_rs,
      'c_rc' : __c_rc,
      'c_uc' : __c_uc,
      'c_us' : __c_us,
      'c_ic' : __c_ic,
      'c_is' : __c_is,
      'dn' : __dn,
      'm0' : __m0,
      'ecc' : __ecc,
      'sqrta' : __sqrta,
      'omega0' : __omega0,
      'omegadot' : __omegadot,
      'w' : __w,
      'inc' : __inc,
      'inc_dot' : __inc_dot,
      'af0' : __af0,
      'af1' : __af1,
      'af2' : __af2,
      'toe_tow' : __toe_tow,
      'toe_wn' : __toe_wn,
      'toc_tow' : __toc_tow,
      'toc_wn' : __toc_wn,
      'valid' : __valid,
      'healthy' : __healthy,
      'sid' : __sid,
      'iode' : __iode,
      'iodc' : __iodc,
      'reserved' : __reserved,
    }, offset, length

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
    o_0 = offset
    o_1, (__tgd, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__c_rs, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__c_rc, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__c_uc, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__c_us, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__c_ic, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__c_is, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__dn, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__m0, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__ecc, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__sqrta, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__omega0, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__omegadot, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__w, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__inc, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__inc_dot, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__af0, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__af1, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__af2, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__toe_tow, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__toe_wn, offset, length) = offset, get_u16(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__toc_tow, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__toc_wn, offset, length) = offset, get_u16(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__valid, offset, length) = offset, get_u8(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__healthy, offset, length) = offset, get_u8(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__prn, offset, length) = offset, get_u8(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    return {
      'tgd' : __tgd,
      'c_rs' : __c_rs,
      'c_rc' : __c_rc,
      'c_uc' : __c_uc,
      'c_us' : __c_us,
      'c_ic' : __c_ic,
      'c_is' : __c_is,
      'dn' : __dn,
      'm0' : __m0,
      'ecc' : __ecc,
      'sqrta' : __sqrta,
      'omega0' : __omega0,
      'omegadot' : __omegadot,
      'w' : __w,
      'inc' : __inc,
      'inc_dot' : __inc_dot,
      'af0' : __af0,
      'af1' : __af1,
      'af2' : __af2,
      'toe_tow' : __toe_tow,
      'toe_wn' : __toe_wn,
      'toc_tow' : __toc_tow,
      'toc_wn' : __toc_wn,
      'valid' : __valid,
      'healthy' : __healthy,
      'prn' : __prn,
    }, offset, length

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
    o_0 = offset
    o_1, (__tgd, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__c_rs, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__c_rc, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__c_uc, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__c_us, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__c_ic, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__c_is, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__dn, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__m0, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__ecc, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__sqrta, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__omega0, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__omegadot, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__w, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__inc, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__inc_dot, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__af0, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__af1, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__af2, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__toe_tow, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__toe_wn, offset, length) = offset, get_u16(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__toc_tow, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__toc_wn, offset, length) = offset, get_u16(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__valid, offset, length) = offset, get_u8(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__healthy, offset, length) = offset, get_u8(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__prn, offset, length) = offset, get_u8(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__iode, offset, length) = offset, get_u8(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    return {
      'tgd' : __tgd,
      'c_rs' : __c_rs,
      'c_rc' : __c_rc,
      'c_uc' : __c_uc,
      'c_us' : __c_us,
      'c_ic' : __c_ic,
      'c_is' : __c_is,
      'dn' : __dn,
      'm0' : __m0,
      'ecc' : __ecc,
      'sqrta' : __sqrta,
      'omega0' : __omega0,
      'omegadot' : __omegadot,
      'w' : __w,
      'inc' : __inc,
      'inc_dot' : __inc_dot,
      'af0' : __af0,
      'af1' : __af1,
      'af2' : __af2,
      'toe_tow' : __toe_tow,
      'toe_wn' : __toe_wn,
      'toc_tow' : __toc_tow,
      'toc_wn' : __toc_wn,
      'valid' : __valid,
      'healthy' : __healthy,
      'prn' : __prn,
      'iode' : __iode,
    }, offset, length

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
    o_0 = offset
    o_1, (__tgd, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__c_rs, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__c_rc, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__c_uc, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__c_us, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__c_ic, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__c_is, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__dn, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__m0, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__ecc, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__sqrta, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__omega0, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__omegadot, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__w, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__inc, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__inc_dot, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__af0, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__af1, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__af2, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__toe_tow, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__toe_wn, offset, length) = offset, get_u16(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__toc_tow, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__toc_wn, offset, length) = offset, get_u16(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__valid, offset, length) = offset, get_u8(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__healthy, offset, length) = offset, get_u8(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__sid, offset, length) = offset, GnssSignalDep.parse_members(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__iode, offset, length) = offset, get_u8(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__iodc, offset, length) = offset, get_u16(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__reserved, offset, length) = offset, get_u32(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    return {
      'tgd' : __tgd,
      'c_rs' : __c_rs,
      'c_rc' : __c_rc,
      'c_uc' : __c_uc,
      'c_us' : __c_us,
      'c_ic' : __c_ic,
      'c_is' : __c_is,
      'dn' : __dn,
      'm0' : __m0,
      'ecc' : __ecc,
      'sqrta' : __sqrta,
      'omega0' : __omega0,
      'omegadot' : __omegadot,
      'w' : __w,
      'inc' : __inc,
      'inc_dot' : __inc_dot,
      'af0' : __af0,
      'af1' : __af1,
      'af2' : __af2,
      'toe_tow' : __toe_tow,
      'toe_wn' : __toe_wn,
      'toc_tow' : __toc_tow,
      'toc_wn' : __toc_wn,
      'valid' : __valid,
      'healthy' : __healthy,
      'sid' : __sid,
      'iode' : __iode,
      'iodc' : __iodc,
      'reserved' : __reserved,
    }, offset, length

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
    o_0 = offset
    o_1, (__t, offset, length) = offset, GPSTimeDep.parse_members(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__n_obs, offset, length) = offset, get_u8(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    return {
      't' : __t,
      'n_obs' : __n_obs,
    }, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.t = res['t']
    self.n_obs = res['n_obs']
    return res, off, length
  
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
    o_0 = offset
    o_1, (__i, offset, length) = offset, get_s32(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__f, offset, length) = offset, get_u8(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    return {
      'i' : __i,
      'f' : __f,
    }, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.i = res['i']
    self.f = res['f']
    return res, off, length
  
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
    o_0 = offset
    o_1, (__P, offset, length) = offset, get_u32(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__L, offset, length) = offset, CarrierPhaseDepA.parse_members(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__cn0, offset, length) = offset, get_u8(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__lock, offset, length) = offset, get_u16(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__prn, offset, length) = offset, get_u8(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    return {
      'P' : __P,
      'L' : __L,
      'cn0' : __cn0,
      'lock' : __lock,
      'prn' : __prn,
    }, offset, length

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
    o_0 = offset
    o_1, (__P, offset, length) = offset, get_u32(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__L, offset, length) = offset, CarrierPhaseDepA.parse_members(buf, offset, length)
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
    return {
      'P' : __P,
      'L' : __L,
      'cn0' : __cn0,
      'lock' : __lock,
      'sid' : __sid,
    }, offset, length

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
    o_0 = offset
    o_1, (__P, offset, length) = offset, get_u32(buf, offset, length)
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
    return {
      'P' : __P,
      'L' : __L,
      'cn0' : __cn0,
      'lock' : __lock,
      'sid' : __sid,
    }, offset, length

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
    o_0 = offset
    o_1, (__header, offset, length) = offset, ObservationHeaderDep.parse_members(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__obs, offset, length) = offset, get_array(PackedObsContentDepA.parse_members)(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    return {
      'header' : __header,
      'obs' : __obs,
    }, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.header = res['header']
    self.obs = res['obs']
    return res, off, length
  
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
    o_0 = offset
    o_1, (__header, offset, length) = offset, ObservationHeaderDep.parse_members(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__obs, offset, length) = offset, get_array(PackedObsContentDepB.parse_members)(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    return {
      'header' : __header,
      'obs' : __obs,
    }, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.header = res['header']
    self.obs = res['obs']
    return res, off, length
  
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
    o_0 = offset
    o_1, (__header, offset, length) = offset, ObservationHeaderDep.parse_members(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__obs, offset, length) = offset, get_array(PackedObsContentDepC.parse_members)(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    return {
      'header' : __header,
      'obs' : __obs,
    }, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.header = res['header']
    self.obs = res['obs']
    return res, off, length
  
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
    o_0 = offset
    o_1, (__t_nmct, offset, length) = offset, GPSTimeSec.parse_members(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__a0, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__a1, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__a2, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__a3, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__b0, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__b1, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__b2, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__b3, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    return {
      't_nmct' : __t_nmct,
      'a0' : __a0,
      'a1' : __a1,
      'a2' : __a2,
      'a3' : __a3,
      'b0' : __b0,
      'b1' : __b1,
      'b2' : __b2,
      'b3' : __b3,
    }, offset, length

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
    o_0 = offset
    o_1, (__t_nmct, offset, length) = offset, GPSTimeSec.parse_members(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__l2c_mask, offset, length) = offset, get_u32(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    return {
      't_nmct' : __t_nmct,
      'l2c_mask' : __l2c_mask,
    }, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.t_nmct = res['t_nmct']
    self.l2c_mask = res['l2c_mask']
    return res, off, length
  
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
    o_0 = offset
    o_1, (__gps_active, offset, length) = offset, get_u64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__gps_l2c, offset, length) = offset, get_u64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__gps_l5, offset, length) = offset, get_u64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__glo_active, offset, length) = offset, get_u32(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__glo_l2of, offset, length) = offset, get_u32(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__glo_l3, offset, length) = offset, get_u32(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__sbas_active, offset, length) = offset, get_u64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__sbas_l5, offset, length) = offset, get_u64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__bds_active, offset, length) = offset, get_u64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__bds_d2nav, offset, length) = offset, get_u64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__bds_b2, offset, length) = offset, get_u64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__bds_b2a, offset, length) = offset, get_u64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__qzss_active, offset, length) = offset, get_u32(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__gal_active, offset, length) = offset, get_u64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__gal_e5, offset, length) = offset, get_u64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    return {
      'gps_active' : __gps_active,
      'gps_l2c' : __gps_l2c,
      'gps_l5' : __gps_l5,
      'glo_active' : __glo_active,
      'glo_l2of' : __glo_l2of,
      'glo_l3' : __glo_l3,
      'sbas_active' : __sbas_active,
      'sbas_l5' : __sbas_l5,
      'bds_active' : __bds_active,
      'bds_d2nav' : __bds_d2nav,
      'bds_b2' : __bds_b2,
      'bds_b2a' : __bds_b2a,
      'qzss_active' : __qzss_active,
      'gal_active' : __gal_active,
      'gal_e5' : __gal_e5,
    }, offset, length

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
    o_0 = offset
    o_1, (__t_nmct, offset, length) = offset, GPSTimeSec.parse_members(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__gc, offset, length) = offset, GnssCapb.parse_members(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    return {
      't_nmct' : __t_nmct,
      'gc' : __gc,
    }, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.t_nmct = res['t_nmct']
    self.gc = res['gc']
    return res, off, length
  
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
    o_0 = offset
    o_1, (__t_op, offset, length) = offset, GPSTimeDep.parse_members(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__prn, offset, length) = offset, get_u8(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__valid, offset, length) = offset, get_u8(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__tgd, offset, length) = offset, get_s16(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__isc_l1ca, offset, length) = offset, get_s16(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__isc_l2c, offset, length) = offset, get_s16(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    return {
      't_op' : __t_op,
      'prn' : __prn,
      'valid' : __valid,
      'tgd' : __tgd,
      'isc_l1ca' : __isc_l1ca,
      'isc_l2c' : __isc_l2c,
    }, offset, length

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
    o_0 = offset
    o_1, (__t_op, offset, length) = offset, GPSTimeSec.parse_members(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__sid, offset, length) = offset, GnssSignalDep.parse_members(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__valid, offset, length) = offset, get_u8(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__tgd, offset, length) = offset, get_s16(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__isc_l1ca, offset, length) = offset, get_s16(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__isc_l2c, offset, length) = offset, get_s16(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    return {
      't_op' : __t_op,
      'sid' : __sid,
      'valid' : __valid,
      'tgd' : __tgd,
      'isc_l1ca' : __isc_l1ca,
      'isc_l2c' : __isc_l2c,
    }, offset, length

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
    o_0 = offset
    o_1, (__t_op, offset, length) = offset, GPSTimeSec.parse_members(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__sid, offset, length) = offset, GnssSignal.parse_members(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__valid, offset, length) = offset, get_u8(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__tgd, offset, length) = offset, get_s16(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__isc_l1ca, offset, length) = offset, get_s16(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__isc_l2c, offset, length) = offset, get_s16(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    return {
      't_op' : __t_op,
      'sid' : __sid,
      'valid' : __valid,
      'tgd' : __tgd,
      'isc_l1ca' : __isc_l1ca,
      'isc_l2c' : __isc_l2c,
    }, offset, length

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
    o_0 = offset
    o_1, (__sid, offset, length) = offset, GnssSignal.parse_members(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__toa, offset, length) = offset, GPSTimeSec.parse_members(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__ura, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__fit_interval, offset, length) = offset, get_u32(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__valid, offset, length) = offset, get_u8(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__health_bits, offset, length) = offset, get_u8(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    return {
      'sid' : __sid,
      'toa' : __toa,
      'ura' : __ura,
      'fit_interval' : __fit_interval,
      'valid' : __valid,
      'health_bits' : __health_bits,
    }, offset, length

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
    o_0 = offset
    o_1, (__sid, offset, length) = offset, GnssSignalDep.parse_members(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__toa, offset, length) = offset, GPSTimeSec.parse_members(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__ura, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__fit_interval, offset, length) = offset, get_u32(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__valid, offset, length) = offset, get_u8(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__health_bits, offset, length) = offset, get_u8(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    return {
      'sid' : __sid,
      'toa' : __toa,
      'ura' : __ura,
      'fit_interval' : __fit_interval,
      'valid' : __valid,
      'health_bits' : __health_bits,
    }, offset, length

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
    o_0 = offset
    o_1, (__common, offset, length) = offset, AlmanacCommonContentDep.parse_members(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__m0, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__ecc, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__sqrta, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__omega0, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__omegadot, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__w, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__inc, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__af0, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__af1, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    return {
      'common' : __common,
      'm0' : __m0,
      'ecc' : __ecc,
      'sqrta' : __sqrta,
      'omega0' : __omega0,
      'omegadot' : __omegadot,
      'w' : __w,
      'inc' : __inc,
      'af0' : __af0,
      'af1' : __af1,
    }, offset, length

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
    o_0 = offset
    o_1, (__common, offset, length) = offset, AlmanacCommonContent.parse_members(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__m0, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__ecc, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__sqrta, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__omega0, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__omegadot, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__w, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__inc, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__af0, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__af1, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    return {
      'common' : __common,
      'm0' : __m0,
      'ecc' : __ecc,
      'sqrta' : __sqrta,
      'omega0' : __omega0,
      'omegadot' : __omegadot,
      'w' : __w,
      'inc' : __inc,
      'af0' : __af0,
      'af1' : __af1,
    }, offset, length

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
    o_0 = offset
    o_1, (__common, offset, length) = offset, AlmanacCommonContentDep.parse_members(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__lambda_na, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__t_lambda_na, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__i, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__t, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__t_dot, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__epsilon, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__omega, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    return {
      'common' : __common,
      'lambda_na' : __lambda_na,
      't_lambda_na' : __t_lambda_na,
      'i' : __i,
      't' : __t,
      't_dot' : __t_dot,
      'epsilon' : __epsilon,
      'omega' : __omega,
    }, offset, length

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
    o_0 = offset
    o_1, (__common, offset, length) = offset, AlmanacCommonContent.parse_members(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__lambda_na, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__t_lambda_na, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__i, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__t, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__t_dot, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__epsilon, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__omega, offset, length) = offset, get_f64(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    return {
      'common' : __common,
      'lambda_na' : __lambda_na,
      't_lambda_na' : __t_lambda_na,
      'i' : __i,
      't' : __t,
      't_dot' : __t_dot,
      'epsilon' : __epsilon,
      'omega' : __omega,
    }, offset, length

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
    o_0 = offset
    o_1, (__mask, offset, length) = offset, get_u8(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__l1ca_bias, offset, length) = offset, get_s16(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__l1p_bias, offset, length) = offset, get_s16(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__l2ca_bias, offset, length) = offset, get_s16(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__l2p_bias, offset, length) = offset, get_s16(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    return {
      'mask' : __mask,
      'l1ca_bias' : __l1ca_bias,
      'l1p_bias' : __l1p_bias,
      'l2ca_bias' : __l2ca_bias,
      'l2p_bias' : __l2p_bias,
    }, offset, length

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
  

msg_classes = {
  0x004A: MsgObs,
  0x0044: MsgBasePosLLH,
  0x0048: MsgBasePosECEF,
  0x0081: MsgEphemerisGPSDepE,
  0x0086: MsgEphemerisGPSDepF,
  0x008A: MsgEphemerisGPS,
  0x0089: MsgEphemerisBds,
  0x0095: MsgEphemerisGal,
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
}