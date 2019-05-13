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
The corrections are conform with typical RTCMv3 MT1059 and 1065.


  """
  __slots__ = ['code',
               'value',
               ]
  def parse_members(self, buf, offset, length):
    dtype = self._static_dtype()
    dlength = length
    if len(dtype):
      dlength -= dtype.itemsize

    if dlength:
      ddtype = self._dynamic_dtype()
      count = dlength // ddtype.itemsize
      dtype = self._static_dtype(count)

    res, offset, length = (np.frombuffer(buf, dtype, 1, offset), offset - length, 0)

    return self._unpack_members(res), offset, length

  @classmethod
  def _static_dtype(cls, count=0):
    if count:
      return np.dtype([
          ('code', 'u1'),
          ('value', 'i2'),
        ])

    t = getattr(cls, 'static_dtype0', None)
    if not t:
      t = np.dtype([
          ('code', 'u1'),
          ('value', 'i2'),
        ])
      cls.static_dtype0 = t
    return t

  @classmethod
  def _dynamic_dtype(cls):
    t = getattr(cls, 'dynamic_dtype', None)
    if not t:    
      t = None
      cls.dynamic_dtype = t
    return t

  @staticmethod
  def _unpack_members(res, element=False):
    d = {
      'code': int(res['code'] if element else res['code'][0]),
      'value': int(res['value'] if element else res['value'][0]),
    }
    return d

  
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
  def parse_members(self, buf, offset, length):
    dtype = self._static_dtype()
    dlength = length
    if len(dtype):
      dlength -= dtype.itemsize

    if dlength:
      ddtype = self._dynamic_dtype()
      count = dlength // ddtype.itemsize
      dtype = self._static_dtype(count)

    res, offset, length = (np.frombuffer(buf, dtype, 1, offset), offset - length, 0)

    return self._unpack_members(res), offset, length

  @classmethod
  def _static_dtype(cls, count=0):
    if count:
      return np.dtype([
          ('code', 'u1'),
          ('integer_indicator', 'u1'),
          ('widelane_integer_indicator', 'u1'),
          ('discontinuity_counter', 'u1'),
          ('bias', 'i4'),
        ])

    t = getattr(cls, 'static_dtype0', None)
    if not t:
      t = np.dtype([
          ('code', 'u1'),
          ('integer_indicator', 'u1'),
          ('widelane_integer_indicator', 'u1'),
          ('discontinuity_counter', 'u1'),
          ('bias', 'i4'),
        ])
      cls.static_dtype0 = t
    return t

  @classmethod
  def _dynamic_dtype(cls):
    t = getattr(cls, 'dynamic_dtype', None)
    if not t:    
      t = None
      cls.dynamic_dtype = t
    return t

  @staticmethod
  def _unpack_members(res, element=False):
    d = {
      'code': int(res['code'] if element else res['code'][0]),
      'integer_indicator': int(res['integer_indicator'] if element else res['integer_indicator'][0]),
      'widelane_integer_indicator': int(res['widelane_integer_indicator'] if element else res['widelane_integer_indicator'][0]),
      'discontinuity_counter': int(res['discontinuity_counter'] if element else res['discontinuity_counter'][0]),
      'bias': int(res['bias'] if element else res['bias'][0]),
    }
    return d

  
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
  def parse_members(self, buf, offset, length):
    dtype = self._static_dtype()
    dlength = length
    if len(dtype):
      dlength -= dtype.itemsize

    if dlength:
      ddtype = self._dynamic_dtype()
      count = dlength // ddtype.itemsize
      dtype = self._static_dtype(count)

    res, offset, length = (np.frombuffer(buf, dtype, 1, offset), offset - length, 0)

    return self._unpack_members(res), offset, length

  @classmethod
  def _static_dtype(cls, count=0):
    if count:
      return np.dtype([
          ('time', GPSTimeSec._static_dtype()),
          ('sid', GnssSignal._static_dtype()),
          ('update_interval', 'u1'),
          ('iod_ssr', 'u1'),
          ('iod', 'u4'),
          ('radial', 'i4'),
          ('along', 'i4'),
          ('cross', 'i4'),
          ('dot_radial', 'i4'),
          ('dot_along', 'i4'),
          ('dot_cross', 'i4'),
          ('c0', 'i4'),
          ('c1', 'i4'),
          ('c2', 'i4'),
        ])

    t = getattr(cls, 'static_dtype0', None)
    if not t:
      t = np.dtype([
          ('time', GPSTimeSec._static_dtype()),
          ('sid', GnssSignal._static_dtype()),
          ('update_interval', 'u1'),
          ('iod_ssr', 'u1'),
          ('iod', 'u4'),
          ('radial', 'i4'),
          ('along', 'i4'),
          ('cross', 'i4'),
          ('dot_radial', 'i4'),
          ('dot_along', 'i4'),
          ('dot_cross', 'i4'),
          ('c0', 'i4'),
          ('c1', 'i4'),
          ('c2', 'i4'),
        ])
      cls.static_dtype0 = t
    return t

  @classmethod
  def _dynamic_dtype(cls):
    t = getattr(cls, 'dynamic_dtype', None)
    if not t:    
      t = None
      cls.dynamic_dtype = t
    return t

  @staticmethod
  def _unpack_members(res, element=False):
    d = {
      'time': GPSTimeSec._unpack_members(res['time'], element=element),
      'sid': GnssSignal._unpack_members(res['sid'], element=element),
      'update_interval': int(res['update_interval'] if element else res['update_interval'][0]),
      'iod_ssr': int(res['iod_ssr'] if element else res['iod_ssr'][0]),
      'iod': int(res['iod'] if element else res['iod'][0]),
      'radial': int(res['radial'] if element else res['radial'][0]),
      'along': int(res['along'] if element else res['along'][0]),
      'cross': int(res['cross'] if element else res['cross'][0]),
      'dot_radial': int(res['dot_radial'] if element else res['dot_radial'][0]),
      'dot_along': int(res['dot_along'] if element else res['dot_along'][0]),
      'dot_cross': int(res['dot_cross'] if element else res['dot_cross'][0]),
      'c0': int(res['c0'] if element else res['c0'][0]),
      'c1': int(res['c1'] if element else res['c1'][0]),
      'c2': int(res['c2'] if element else res['c2'][0]),
    }
    return d

  
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
  def parse_members(self, buf, offset, length):
    dtype = self._static_dtype()
    dlength = length
    if len(dtype):
      dlength -= dtype.itemsize

    if dlength:
      ddtype = self._dynamic_dtype()
      count = dlength // ddtype.itemsize
      dtype = self._static_dtype(count)

    res, offset, length = (np.frombuffer(buf, dtype, 1, offset), offset - length, 0)

    return self._unpack_members(res), offset, length

  @classmethod
  def _static_dtype(cls, count=0):
    if count:
      return np.dtype([
          ('time', GPSTimeSec._static_dtype()),
          ('sid', GnssSignal._static_dtype()),
          ('update_interval', 'u1'),
          ('iod_ssr', 'u1'),
          ('iod', 'u1'),
          ('radial', 'i4'),
          ('along', 'i4'),
          ('cross', 'i4'),
          ('dot_radial', 'i4'),
          ('dot_along', 'i4'),
          ('dot_cross', 'i4'),
          ('c0', 'i4'),
          ('c1', 'i4'),
          ('c2', 'i4'),
        ])

    t = getattr(cls, 'static_dtype0', None)
    if not t:
      t = np.dtype([
          ('time', GPSTimeSec._static_dtype()),
          ('sid', GnssSignal._static_dtype()),
          ('update_interval', 'u1'),
          ('iod_ssr', 'u1'),
          ('iod', 'u1'),
          ('radial', 'i4'),
          ('along', 'i4'),
          ('cross', 'i4'),
          ('dot_radial', 'i4'),
          ('dot_along', 'i4'),
          ('dot_cross', 'i4'),
          ('c0', 'i4'),
          ('c1', 'i4'),
          ('c2', 'i4'),
        ])
      cls.static_dtype0 = t
    return t

  @classmethod
  def _dynamic_dtype(cls):
    t = getattr(cls, 'dynamic_dtype', None)
    if not t:    
      t = None
      cls.dynamic_dtype = t
    return t

  @staticmethod
  def _unpack_members(res, element=False):
    d = {
      'time': GPSTimeSec._unpack_members(res['time'], element=element),
      'sid': GnssSignal._unpack_members(res['sid'], element=element),
      'update_interval': int(res['update_interval'] if element else res['update_interval'][0]),
      'iod_ssr': int(res['iod_ssr'] if element else res['iod_ssr'][0]),
      'iod': int(res['iod'] if element else res['iod'][0]),
      'radial': int(res['radial'] if element else res['radial'][0]),
      'along': int(res['along'] if element else res['along'][0]),
      'cross': int(res['cross'] if element else res['cross'][0]),
      'dot_radial': int(res['dot_radial'] if element else res['dot_radial'][0]),
      'dot_along': int(res['dot_along'] if element else res['dot_along'][0]),
      'dot_cross': int(res['dot_cross'] if element else res['dot_cross'][0]),
      'c0': int(res['c0'] if element else res['c0'][0]),
      'c1': int(res['c1'] if element else res['c1'][0]),
      'c2': int(res['c2'] if element else res['c2'][0]),
    }
    return d

  
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
  def parse_members(self, buf, offset, length):
    dtype = self._static_dtype()
    dlength = length
    if len(dtype):
      dlength -= dtype.itemsize

    if dlength:
      ddtype = self._dynamic_dtype()
      count = dlength // ddtype.itemsize
      dtype = self._static_dtype(count)

    res, offset, length = (np.frombuffer(buf, dtype, 1, offset), offset - length, 0)

    return self._unpack_members(res), offset, length

  @classmethod
  def _static_dtype(cls, count=0):
    if count:
      return np.dtype([
          ('time', GPSTimeSec._static_dtype()),
          ('sid', GnssSignal._static_dtype()),
          ('update_interval', 'u1'),
          ('iod_ssr', 'u1'),
          ('biases', (CodeBiasesContent._static_dtype(), (count,))),
        ])

    t = getattr(cls, 'static_dtype0', None)
    if not t:
      t = np.dtype([
          ('time', GPSTimeSec._static_dtype()),
          ('sid', GnssSignal._static_dtype()),
          ('update_interval', 'u1'),
          ('iod_ssr', 'u1'),
          ('biases', (CodeBiasesContent._static_dtype(), (count,))),
        ])
      cls.static_dtype0 = t
    return t

  @classmethod
  def _dynamic_dtype(cls):
    t = getattr(cls, 'dynamic_dtype', None)
    if not t:    
      t = np.dtype([('biases', CodeBiasesContent._static_dtype()),])
      cls.dynamic_dtype = t
    return t

  @staticmethod
  def _unpack_members(res, element=False):
    d = {
      'time': GPSTimeSec._unpack_members(res['time'], element=element),
      'sid': GnssSignal._unpack_members(res['sid'], element=element),
      'update_interval': int(res['update_interval'] if element else res['update_interval'][0]),
      'iod_ssr': int(res['iod_ssr'] if element else res['iod_ssr'][0]),
      'biases': [] if res['biases'] is None else [CodeBiasesContent._unpack_members(x, element=True) for x in res['biases'].flatten()],
    }
    return d

  
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
  def parse_members(self, buf, offset, length):
    dtype = self._static_dtype()
    dlength = length
    if len(dtype):
      dlength -= dtype.itemsize

    if dlength:
      ddtype = self._dynamic_dtype()
      count = dlength // ddtype.itemsize
      dtype = self._static_dtype(count)

    res, offset, length = (np.frombuffer(buf, dtype, 1, offset), offset - length, 0)

    return self._unpack_members(res), offset, length

  @classmethod
  def _static_dtype(cls, count=0):
    if count:
      return np.dtype([
          ('time', GPSTimeSec._static_dtype()),
          ('sid', GnssSignal._static_dtype()),
          ('update_interval', 'u1'),
          ('iod_ssr', 'u1'),
          ('dispersive_bias', 'u1'),
          ('mw_consistency', 'u1'),
          ('yaw', 'u2'),
          ('yaw_rate', 'i1'),
          ('biases', (PhaseBiasesContent._static_dtype(), (count,))),
        ])

    t = getattr(cls, 'static_dtype0', None)
    if not t:
      t = np.dtype([
          ('time', GPSTimeSec._static_dtype()),
          ('sid', GnssSignal._static_dtype()),
          ('update_interval', 'u1'),
          ('iod_ssr', 'u1'),
          ('dispersive_bias', 'u1'),
          ('mw_consistency', 'u1'),
          ('yaw', 'u2'),
          ('yaw_rate', 'i1'),
          ('biases', (PhaseBiasesContent._static_dtype(), (count,))),
        ])
      cls.static_dtype0 = t
    return t

  @classmethod
  def _dynamic_dtype(cls):
    t = getattr(cls, 'dynamic_dtype', None)
    if not t:    
      t = np.dtype([('biases', PhaseBiasesContent._static_dtype()),])
      cls.dynamic_dtype = t
    return t

  @staticmethod
  def _unpack_members(res, element=False):
    d = {
      'time': GPSTimeSec._unpack_members(res['time'], element=element),
      'sid': GnssSignal._unpack_members(res['sid'], element=element),
      'update_interval': int(res['update_interval'] if element else res['update_interval'][0]),
      'iod_ssr': int(res['iod_ssr'] if element else res['iod_ssr'][0]),
      'dispersive_bias': int(res['dispersive_bias'] if element else res['dispersive_bias'][0]),
      'mw_consistency': int(res['mw_consistency'] if element else res['mw_consistency'][0]),
      'yaw': int(res['yaw'] if element else res['yaw'][0]),
      'yaw_rate': int(res['yaw_rate'] if element else res['yaw_rate'][0]),
      'biases': [] if res['biases'] is None else [PhaseBiasesContent._unpack_members(x, element=True) for x in res['biases'].flatten()],
    }
    return d

  

msg_classes = {
  0x05DD: MsgSsrOrbitClock,
  0x05DC: MsgSsrOrbitClockDepA,
  0x05E1: MsgSsrCodeBiases,
  0x05E6: MsgSsrPhaseBiases,
}