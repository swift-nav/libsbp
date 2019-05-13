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
Geodetic navigation messages reporting GPS time, position, velocity,
and baseline position solutions. For position solutions, these
messages define several different position solutions: single-point
(SPP), RTK, and pseudo-absolute position solutions.

The SPP is the standalone, absolute GPS position solution using only
a single receiver. The RTK solution is the differential GPS
solution, which can use either a fixed/integer or floating carrier
phase ambiguity. The pseudo-absolute position solution uses a
user-provided, well-surveyed base station position (if available)
and the RTK solution in tandem.

When the inertial navigation mode indicates that the IMU is used,
all messages are reported in the vehicle body frame as defined by
device settings.  By default, the vehicle body frame is configured to be
coincident with the antenna phase center.  When there is no inertial
navigation, the solution will be reported at the phase center of the antenna.
There is no inertial navigation capability on Piksi Multi or Duro. 

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

# Automatically generated from piksi/yaml/swiftnav/sbp/navigation.yaml with generate.py.
# Please do not hand edit!
SBP_MSG_GPS_TIME = 0x0102
class MsgGPSTime(SBP):
  """SBP class for message MSG_GPS_TIME (0x0102).

  You can have MSG_GPS_TIME inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  This message reports the GPS time, representing the time since
the GPS epoch began on midnight January 6, 1980 UTC. GPS time
counts the weeks and seconds of the week. The weeks begin at the
Saturday/Sunday transition. GPS week 0 began at the beginning of
the GPS time scale.

Within each week number, the GPS time of the week is between
between 0 and 604800 seconds (=60*60*24*7). Note that GPS time
does not accumulate leap seconds, and as of now, has a small
offset from UTC. In a message stream, this message precedes a
set of other navigation messages referenced to the same time
(but lacking the ns field) and indicates a more precise time of
these messages.


  """
  __slots__ = ['wn',
               'tow',
               'ns_residual',
               'flags',
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
          ('wn', 'u2'),
          ('tow', 'u4'),
          ('ns_residual', 'i4'),
          ('flags', 'u1'),
        ])

    t = getattr(cls, 'static_dtype0', None)
    if not t:
      t = np.dtype([
          ('wn', 'u2'),
          ('tow', 'u4'),
          ('ns_residual', 'i4'),
          ('flags', 'u1'),
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
      'wn': int(res['wn'] if element else res['wn'][0]),
      'tow': int(res['tow'] if element else res['tow'][0]),
      'ns_residual': int(res['ns_residual'] if element else res['ns_residual'][0]),
      'flags': int(res['flags'] if element else res['flags'][0]),
    }
    return d

  
SBP_MSG_UTC_TIME = 0x0103
class MsgUtcTime(SBP):
  """SBP class for message MSG_UTC_TIME (0x0103).

  You can have MSG_UTC_TIME inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  This message reports the Universal Coordinated Time (UTC).  Note the flags
which indicate the source of the UTC offset value and source of the time fix.


  """
  __slots__ = ['flags',
               'tow',
               'year',
               'month',
               'day',
               'hours',
               'minutes',
               'seconds',
               'ns',
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
          ('flags', 'u1'),
          ('tow', 'u4'),
          ('year', 'u2'),
          ('month', 'u1'),
          ('day', 'u1'),
          ('hours', 'u1'),
          ('minutes', 'u1'),
          ('seconds', 'u1'),
          ('ns', 'u4'),
        ])

    t = getattr(cls, 'static_dtype0', None)
    if not t:
      t = np.dtype([
          ('flags', 'u1'),
          ('tow', 'u4'),
          ('year', 'u2'),
          ('month', 'u1'),
          ('day', 'u1'),
          ('hours', 'u1'),
          ('minutes', 'u1'),
          ('seconds', 'u1'),
          ('ns', 'u4'),
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
      'flags': int(res['flags'] if element else res['flags'][0]),
      'tow': int(res['tow'] if element else res['tow'][0]),
      'year': int(res['year'] if element else res['year'][0]),
      'month': int(res['month'] if element else res['month'][0]),
      'day': int(res['day'] if element else res['day'][0]),
      'hours': int(res['hours'] if element else res['hours'][0]),
      'minutes': int(res['minutes'] if element else res['minutes'][0]),
      'seconds': int(res['seconds'] if element else res['seconds'][0]),
      'ns': int(res['ns'] if element else res['ns'][0]),
    }
    return d

  
SBP_MSG_DOPS = 0x0208
class MsgDops(SBP):
  """SBP class for message MSG_DOPS (0x0208).

  You can have MSG_DOPS inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  This dilution of precision (DOP) message describes the effect of
navigation satellite geometry on positional measurement
precision.  The flags field indicated whether the DOP reported
corresponds to differential or SPP solution.


  """
  __slots__ = ['tow',
               'gdop',
               'pdop',
               'tdop',
               'hdop',
               'vdop',
               'flags',
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
          ('tow', 'u4'),
          ('gdop', 'u2'),
          ('pdop', 'u2'),
          ('tdop', 'u2'),
          ('hdop', 'u2'),
          ('vdop', 'u2'),
          ('flags', 'u1'),
        ])

    t = getattr(cls, 'static_dtype0', None)
    if not t:
      t = np.dtype([
          ('tow', 'u4'),
          ('gdop', 'u2'),
          ('pdop', 'u2'),
          ('tdop', 'u2'),
          ('hdop', 'u2'),
          ('vdop', 'u2'),
          ('flags', 'u1'),
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
      'tow': int(res['tow'] if element else res['tow'][0]),
      'gdop': int(res['gdop'] if element else res['gdop'][0]),
      'pdop': int(res['pdop'] if element else res['pdop'][0]),
      'tdop': int(res['tdop'] if element else res['tdop'][0]),
      'hdop': int(res['hdop'] if element else res['hdop'][0]),
      'vdop': int(res['vdop'] if element else res['vdop'][0]),
      'flags': int(res['flags'] if element else res['flags'][0]),
    }
    return d

  
SBP_MSG_POS_ECEF = 0x0209
class MsgPosECEF(SBP):
  """SBP class for message MSG_POS_ECEF (0x0209).

  You can have MSG_POS_ECEF inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  The position solution message reports absolute Earth Centered
Earth Fixed (ECEF) coordinates and the status (single point vs
pseudo-absolute RTK) of the position solution. If the rover
receiver knows the surveyed position of the base station and has
an RTK solution, this reports a pseudo-absolute position
solution using the base station position and the rover's RTK
baseline vector. The full GPS time is given by the preceding
MSG_GPS_TIME with the matching time-of-week (tow).


  """
  __slots__ = ['tow',
               'x',
               'y',
               'z',
               'accuracy',
               'n_sats',
               'flags',
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
          ('tow', 'u4'),
          ('x', 'f8'),
          ('y', 'f8'),
          ('z', 'f8'),
          ('accuracy', 'u2'),
          ('n_sats', 'u1'),
          ('flags', 'u1'),
        ])

    t = getattr(cls, 'static_dtype0', None)
    if not t:
      t = np.dtype([
          ('tow', 'u4'),
          ('x', 'f8'),
          ('y', 'f8'),
          ('z', 'f8'),
          ('accuracy', 'u2'),
          ('n_sats', 'u1'),
          ('flags', 'u1'),
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
      'tow': int(res['tow'] if element else res['tow'][0]),
      'x': float(res['x'] if element else res['x'][0]),
      'y': float(res['y'] if element else res['y'][0]),
      'z': float(res['z'] if element else res['z'][0]),
      'accuracy': int(res['accuracy'] if element else res['accuracy'][0]),
      'n_sats': int(res['n_sats'] if element else res['n_sats'][0]),
      'flags': int(res['flags'] if element else res['flags'][0]),
    }
    return d

  
SBP_MSG_POS_ECEF_COV = 0x0214
class MsgPosECEFCov(SBP):
  """SBP class for message MSG_POS_ECEF_COV (0x0214).

  You can have MSG_POS_ECEF_COV inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  The position solution message reports absolute Earth Centered
Earth Fixed (ECEF) coordinates and the status (single point vs
pseudo-absolute RTK) of the position solution. The message also
reports the upper triangular portion of the 3x3 covariance matrix.
If the receiver knows the surveyed position of the base station and has
an RTK solution, this reports a pseudo-absolute position
solution using the base station position and the rover's RTK
baseline vector. The full GPS time is given by the preceding
MSG_GPS_TIME with the matching time-of-week (tow).


  """
  __slots__ = ['tow',
               'x',
               'y',
               'z',
               'cov_x_x',
               'cov_x_y',
               'cov_x_z',
               'cov_y_y',
               'cov_y_z',
               'cov_z_z',
               'n_sats',
               'flags',
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
          ('tow', 'u4'),
          ('x', 'f8'),
          ('y', 'f8'),
          ('z', 'f8'),
          ('cov_x_x', 'f4'),
          ('cov_x_y', 'f4'),
          ('cov_x_z', 'f4'),
          ('cov_y_y', 'f4'),
          ('cov_y_z', 'f4'),
          ('cov_z_z', 'f4'),
          ('n_sats', 'u1'),
          ('flags', 'u1'),
        ])

    t = getattr(cls, 'static_dtype0', None)
    if not t:
      t = np.dtype([
          ('tow', 'u4'),
          ('x', 'f8'),
          ('y', 'f8'),
          ('z', 'f8'),
          ('cov_x_x', 'f4'),
          ('cov_x_y', 'f4'),
          ('cov_x_z', 'f4'),
          ('cov_y_y', 'f4'),
          ('cov_y_z', 'f4'),
          ('cov_z_z', 'f4'),
          ('n_sats', 'u1'),
          ('flags', 'u1'),
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
      'tow': int(res['tow'] if element else res['tow'][0]),
      'x': float(res['x'] if element else res['x'][0]),
      'y': float(res['y'] if element else res['y'][0]),
      'z': float(res['z'] if element else res['z'][0]),
      'cov_x_x': float(res['cov_x_x'] if element else res['cov_x_x'][0]),
      'cov_x_y': float(res['cov_x_y'] if element else res['cov_x_y'][0]),
      'cov_x_z': float(res['cov_x_z'] if element else res['cov_x_z'][0]),
      'cov_y_y': float(res['cov_y_y'] if element else res['cov_y_y'][0]),
      'cov_y_z': float(res['cov_y_z'] if element else res['cov_y_z'][0]),
      'cov_z_z': float(res['cov_z_z'] if element else res['cov_z_z'][0]),
      'n_sats': int(res['n_sats'] if element else res['n_sats'][0]),
      'flags': int(res['flags'] if element else res['flags'][0]),
    }
    return d

  
SBP_MSG_POS_LLH = 0x020A
class MsgPosLLH(SBP):
  """SBP class for message MSG_POS_LLH (0x020A).

  You can have MSG_POS_LLH inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  This position solution message reports the absolute geodetic
coordinates and the status (single point vs pseudo-absolute RTK)
of the position solution. If the rover receiver knows the
surveyed position of the base station and has an RTK solution,
this reports a pseudo-absolute position solution using the base
station position and the rover's RTK baseline vector. The full
GPS time is given by the preceding MSG_GPS_TIME with the
matching time-of-week (tow).


  """
  __slots__ = ['tow',
               'lat',
               'lon',
               'height',
               'h_accuracy',
               'v_accuracy',
               'n_sats',
               'flags',
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
          ('tow', 'u4'),
          ('lat', 'f8'),
          ('lon', 'f8'),
          ('height', 'f8'),
          ('h_accuracy', 'u2'),
          ('v_accuracy', 'u2'),
          ('n_sats', 'u1'),
          ('flags', 'u1'),
        ])

    t = getattr(cls, 'static_dtype0', None)
    if not t:
      t = np.dtype([
          ('tow', 'u4'),
          ('lat', 'f8'),
          ('lon', 'f8'),
          ('height', 'f8'),
          ('h_accuracy', 'u2'),
          ('v_accuracy', 'u2'),
          ('n_sats', 'u1'),
          ('flags', 'u1'),
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
      'tow': int(res['tow'] if element else res['tow'][0]),
      'lat': float(res['lat'] if element else res['lat'][0]),
      'lon': float(res['lon'] if element else res['lon'][0]),
      'height': float(res['height'] if element else res['height'][0]),
      'h_accuracy': int(res['h_accuracy'] if element else res['h_accuracy'][0]),
      'v_accuracy': int(res['v_accuracy'] if element else res['v_accuracy'][0]),
      'n_sats': int(res['n_sats'] if element else res['n_sats'][0]),
      'flags': int(res['flags'] if element else res['flags'][0]),
    }
    return d

  
SBP_MSG_POS_LLH_COV = 0x0211
class MsgPosLLHCov(SBP):
  """SBP class for message MSG_POS_LLH_COV (0x0211).

  You can have MSG_POS_LLH_COV inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  This position solution message reports the absolute geodetic
coordinates and the status (single point vs pseudo-absolute RTK)
of the position solution as well as the upper triangle of the 3x3
covariance matrix.  The position information and Fix Mode flags should
follow the MSG_POS_LLH message.  Since the covariance matrix is computed
in the local-level North, East, Down frame, the covariance terms follow
with that convention. Thus, covariances are reported against the "downward"
measurement and care should be taken with the sign convention.


  """
  __slots__ = ['tow',
               'lat',
               'lon',
               'height',
               'cov_n_n',
               'cov_n_e',
               'cov_n_d',
               'cov_e_e',
               'cov_e_d',
               'cov_d_d',
               'n_sats',
               'flags',
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
          ('tow', 'u4'),
          ('lat', 'f8'),
          ('lon', 'f8'),
          ('height', 'f8'),
          ('cov_n_n', 'f4'),
          ('cov_n_e', 'f4'),
          ('cov_n_d', 'f4'),
          ('cov_e_e', 'f4'),
          ('cov_e_d', 'f4'),
          ('cov_d_d', 'f4'),
          ('n_sats', 'u1'),
          ('flags', 'u1'),
        ])

    t = getattr(cls, 'static_dtype0', None)
    if not t:
      t = np.dtype([
          ('tow', 'u4'),
          ('lat', 'f8'),
          ('lon', 'f8'),
          ('height', 'f8'),
          ('cov_n_n', 'f4'),
          ('cov_n_e', 'f4'),
          ('cov_n_d', 'f4'),
          ('cov_e_e', 'f4'),
          ('cov_e_d', 'f4'),
          ('cov_d_d', 'f4'),
          ('n_sats', 'u1'),
          ('flags', 'u1'),
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
      'tow': int(res['tow'] if element else res['tow'][0]),
      'lat': float(res['lat'] if element else res['lat'][0]),
      'lon': float(res['lon'] if element else res['lon'][0]),
      'height': float(res['height'] if element else res['height'][0]),
      'cov_n_n': float(res['cov_n_n'] if element else res['cov_n_n'][0]),
      'cov_n_e': float(res['cov_n_e'] if element else res['cov_n_e'][0]),
      'cov_n_d': float(res['cov_n_d'] if element else res['cov_n_d'][0]),
      'cov_e_e': float(res['cov_e_e'] if element else res['cov_e_e'][0]),
      'cov_e_d': float(res['cov_e_d'] if element else res['cov_e_d'][0]),
      'cov_d_d': float(res['cov_d_d'] if element else res['cov_d_d'][0]),
      'n_sats': int(res['n_sats'] if element else res['n_sats'][0]),
      'flags': int(res['flags'] if element else res['flags'][0]),
    }
    return d

  
SBP_MSG_BASELINE_ECEF = 0x020B
class MsgBaselineECEF(SBP):
  """SBP class for message MSG_BASELINE_ECEF (0x020B).

  You can have MSG_BASELINE_ECEF inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  This message reports the baseline solution in Earth Centered
Earth Fixed (ECEF) coordinates. This baseline is the relative
vector distance from the base station to the rover receiver. The
full GPS time is given by the preceding MSG_GPS_TIME with the
matching time-of-week (tow).


  """
  __slots__ = ['tow',
               'x',
               'y',
               'z',
               'accuracy',
               'n_sats',
               'flags',
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
          ('tow', 'u4'),
          ('x', 'i4'),
          ('y', 'i4'),
          ('z', 'i4'),
          ('accuracy', 'u2'),
          ('n_sats', 'u1'),
          ('flags', 'u1'),
        ])

    t = getattr(cls, 'static_dtype0', None)
    if not t:
      t = np.dtype([
          ('tow', 'u4'),
          ('x', 'i4'),
          ('y', 'i4'),
          ('z', 'i4'),
          ('accuracy', 'u2'),
          ('n_sats', 'u1'),
          ('flags', 'u1'),
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
      'tow': int(res['tow'] if element else res['tow'][0]),
      'x': int(res['x'] if element else res['x'][0]),
      'y': int(res['y'] if element else res['y'][0]),
      'z': int(res['z'] if element else res['z'][0]),
      'accuracy': int(res['accuracy'] if element else res['accuracy'][0]),
      'n_sats': int(res['n_sats'] if element else res['n_sats'][0]),
      'flags': int(res['flags'] if element else res['flags'][0]),
    }
    return d

  
SBP_MSG_BASELINE_NED = 0x020C
class MsgBaselineNED(SBP):
  """SBP class for message MSG_BASELINE_NED (0x020C).

  You can have MSG_BASELINE_NED inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  This message reports the baseline solution in North East Down
(NED) coordinates. This baseline is the relative vector distance
from the base station to the rover receiver, and NED coordinate
system is defined at the local WGS84 tangent plane centered at the
base station position.  The full GPS time is given by the
preceding MSG_GPS_TIME with the matching time-of-week (tow).


  """
  __slots__ = ['tow',
               'n',
               'e',
               'd',
               'h_accuracy',
               'v_accuracy',
               'n_sats',
               'flags',
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
          ('tow', 'u4'),
          ('n', 'i4'),
          ('e', 'i4'),
          ('d', 'i4'),
          ('h_accuracy', 'u2'),
          ('v_accuracy', 'u2'),
          ('n_sats', 'u1'),
          ('flags', 'u1'),
        ])

    t = getattr(cls, 'static_dtype0', None)
    if not t:
      t = np.dtype([
          ('tow', 'u4'),
          ('n', 'i4'),
          ('e', 'i4'),
          ('d', 'i4'),
          ('h_accuracy', 'u2'),
          ('v_accuracy', 'u2'),
          ('n_sats', 'u1'),
          ('flags', 'u1'),
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
      'tow': int(res['tow'] if element else res['tow'][0]),
      'n': int(res['n'] if element else res['n'][0]),
      'e': int(res['e'] if element else res['e'][0]),
      'd': int(res['d'] if element else res['d'][0]),
      'h_accuracy': int(res['h_accuracy'] if element else res['h_accuracy'][0]),
      'v_accuracy': int(res['v_accuracy'] if element else res['v_accuracy'][0]),
      'n_sats': int(res['n_sats'] if element else res['n_sats'][0]),
      'flags': int(res['flags'] if element else res['flags'][0]),
    }
    return d

  
SBP_MSG_VEL_ECEF = 0x020D
class MsgVelECEF(SBP):
  """SBP class for message MSG_VEL_ECEF (0x020D).

  You can have MSG_VEL_ECEF inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  This message reports the velocity in Earth Centered Earth Fixed
(ECEF) coordinates. The full GPS time is given by the preceding
MSG_GPS_TIME with the matching time-of-week (tow).


  """
  __slots__ = ['tow',
               'x',
               'y',
               'z',
               'accuracy',
               'n_sats',
               'flags',
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
          ('tow', 'u4'),
          ('x', 'i4'),
          ('y', 'i4'),
          ('z', 'i4'),
          ('accuracy', 'u2'),
          ('n_sats', 'u1'),
          ('flags', 'u1'),
        ])

    t = getattr(cls, 'static_dtype0', None)
    if not t:
      t = np.dtype([
          ('tow', 'u4'),
          ('x', 'i4'),
          ('y', 'i4'),
          ('z', 'i4'),
          ('accuracy', 'u2'),
          ('n_sats', 'u1'),
          ('flags', 'u1'),
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
      'tow': int(res['tow'] if element else res['tow'][0]),
      'x': int(res['x'] if element else res['x'][0]),
      'y': int(res['y'] if element else res['y'][0]),
      'z': int(res['z'] if element else res['z'][0]),
      'accuracy': int(res['accuracy'] if element else res['accuracy'][0]),
      'n_sats': int(res['n_sats'] if element else res['n_sats'][0]),
      'flags': int(res['flags'] if element else res['flags'][0]),
    }
    return d

  
SBP_MSG_VEL_ECEF_COV = 0x0215
class MsgVelECEFCov(SBP):
  """SBP class for message MSG_VEL_ECEF_COV (0x0215).

  You can have MSG_VEL_ECEF_COV inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  This message reports the velocity in Earth Centered Earth Fixed
(ECEF) coordinates. The full GPS time is given by the preceding
MSG_GPS_TIME with the matching time-of-week (tow).


  """
  __slots__ = ['tow',
               'x',
               'y',
               'z',
               'cov_x_x',
               'cov_x_y',
               'cov_x_z',
               'cov_y_y',
               'cov_y_z',
               'cov_z_z',
               'n_sats',
               'flags',
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
          ('tow', 'u4'),
          ('x', 'i4'),
          ('y', 'i4'),
          ('z', 'i4'),
          ('cov_x_x', 'f4'),
          ('cov_x_y', 'f4'),
          ('cov_x_z', 'f4'),
          ('cov_y_y', 'f4'),
          ('cov_y_z', 'f4'),
          ('cov_z_z', 'f4'),
          ('n_sats', 'u1'),
          ('flags', 'u1'),
        ])

    t = getattr(cls, 'static_dtype0', None)
    if not t:
      t = np.dtype([
          ('tow', 'u4'),
          ('x', 'i4'),
          ('y', 'i4'),
          ('z', 'i4'),
          ('cov_x_x', 'f4'),
          ('cov_x_y', 'f4'),
          ('cov_x_z', 'f4'),
          ('cov_y_y', 'f4'),
          ('cov_y_z', 'f4'),
          ('cov_z_z', 'f4'),
          ('n_sats', 'u1'),
          ('flags', 'u1'),
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
      'tow': int(res['tow'] if element else res['tow'][0]),
      'x': int(res['x'] if element else res['x'][0]),
      'y': int(res['y'] if element else res['y'][0]),
      'z': int(res['z'] if element else res['z'][0]),
      'cov_x_x': float(res['cov_x_x'] if element else res['cov_x_x'][0]),
      'cov_x_y': float(res['cov_x_y'] if element else res['cov_x_y'][0]),
      'cov_x_z': float(res['cov_x_z'] if element else res['cov_x_z'][0]),
      'cov_y_y': float(res['cov_y_y'] if element else res['cov_y_y'][0]),
      'cov_y_z': float(res['cov_y_z'] if element else res['cov_y_z'][0]),
      'cov_z_z': float(res['cov_z_z'] if element else res['cov_z_z'][0]),
      'n_sats': int(res['n_sats'] if element else res['n_sats'][0]),
      'flags': int(res['flags'] if element else res['flags'][0]),
    }
    return d

  
SBP_MSG_VEL_NED = 0x020E
class MsgVelNED(SBP):
  """SBP class for message MSG_VEL_NED (0x020E).

  You can have MSG_VEL_NED inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  This message reports the velocity in local North East Down (NED)
coordinates. The NED coordinate system is defined as the local WGS84
tangent plane centered at the current position. The full GPS time is
given by the preceding MSG_GPS_TIME with the matching time-of-week (tow).


  """
  __slots__ = ['tow',
               'n',
               'e',
               'd',
               'h_accuracy',
               'v_accuracy',
               'n_sats',
               'flags',
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
          ('tow', 'u4'),
          ('n', 'i4'),
          ('e', 'i4'),
          ('d', 'i4'),
          ('h_accuracy', 'u2'),
          ('v_accuracy', 'u2'),
          ('n_sats', 'u1'),
          ('flags', 'u1'),
        ])

    t = getattr(cls, 'static_dtype0', None)
    if not t:
      t = np.dtype([
          ('tow', 'u4'),
          ('n', 'i4'),
          ('e', 'i4'),
          ('d', 'i4'),
          ('h_accuracy', 'u2'),
          ('v_accuracy', 'u2'),
          ('n_sats', 'u1'),
          ('flags', 'u1'),
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
      'tow': int(res['tow'] if element else res['tow'][0]),
      'n': int(res['n'] if element else res['n'][0]),
      'e': int(res['e'] if element else res['e'][0]),
      'd': int(res['d'] if element else res['d'][0]),
      'h_accuracy': int(res['h_accuracy'] if element else res['h_accuracy'][0]),
      'v_accuracy': int(res['v_accuracy'] if element else res['v_accuracy'][0]),
      'n_sats': int(res['n_sats'] if element else res['n_sats'][0]),
      'flags': int(res['flags'] if element else res['flags'][0]),
    }
    return d

  
SBP_MSG_VEL_NED_COV = 0x0212
class MsgVelNEDCov(SBP):
  """SBP class for message MSG_VEL_NED_COV (0x0212).

  You can have MSG_VEL_NED_COV inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  This message reports the velocity in local North East Down (NED)
coordinates. The NED coordinate system is defined as the local WGS84
tangent plane centered at the current position. The full GPS time is
given by the preceding MSG_GPS_TIME with the matching time-of-week (tow).
This message is similar to the MSG_VEL_NED, but it includes the upper triangular
portion of the 3x3 covariance matrix.


  """
  __slots__ = ['tow',
               'n',
               'e',
               'd',
               'cov_n_n',
               'cov_n_e',
               'cov_n_d',
               'cov_e_e',
               'cov_e_d',
               'cov_d_d',
               'n_sats',
               'flags',
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
          ('tow', 'u4'),
          ('n', 'i4'),
          ('e', 'i4'),
          ('d', 'i4'),
          ('cov_n_n', 'f4'),
          ('cov_n_e', 'f4'),
          ('cov_n_d', 'f4'),
          ('cov_e_e', 'f4'),
          ('cov_e_d', 'f4'),
          ('cov_d_d', 'f4'),
          ('n_sats', 'u1'),
          ('flags', 'u1'),
        ])

    t = getattr(cls, 'static_dtype0', None)
    if not t:
      t = np.dtype([
          ('tow', 'u4'),
          ('n', 'i4'),
          ('e', 'i4'),
          ('d', 'i4'),
          ('cov_n_n', 'f4'),
          ('cov_n_e', 'f4'),
          ('cov_n_d', 'f4'),
          ('cov_e_e', 'f4'),
          ('cov_e_d', 'f4'),
          ('cov_d_d', 'f4'),
          ('n_sats', 'u1'),
          ('flags', 'u1'),
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
      'tow': int(res['tow'] if element else res['tow'][0]),
      'n': int(res['n'] if element else res['n'][0]),
      'e': int(res['e'] if element else res['e'][0]),
      'd': int(res['d'] if element else res['d'][0]),
      'cov_n_n': float(res['cov_n_n'] if element else res['cov_n_n'][0]),
      'cov_n_e': float(res['cov_n_e'] if element else res['cov_n_e'][0]),
      'cov_n_d': float(res['cov_n_d'] if element else res['cov_n_d'][0]),
      'cov_e_e': float(res['cov_e_e'] if element else res['cov_e_e'][0]),
      'cov_e_d': float(res['cov_e_d'] if element else res['cov_e_d'][0]),
      'cov_d_d': float(res['cov_d_d'] if element else res['cov_d_d'][0]),
      'n_sats': int(res['n_sats'] if element else res['n_sats'][0]),
      'flags': int(res['flags'] if element else res['flags'][0]),
    }
    return d

  
SBP_MSG_VEL_BODY = 0x0213
class MsgVelBody(SBP):
  """SBP class for message MSG_VEL_BODY (0x0213).

  You can have MSG_VEL_BODY inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  This message reports the velocity in the Vehicle Body Frame. By convention,
the x-axis should point out the nose of the vehicle and represent the forward
direction, while as the y-axis should point out the right hand side of the vehicle.
Since this is a right handed system, z should point out the bottom of the vehicle.
The orientation and origin of the Vehicle Body Frame are specified via the device settings.
The full GPS time is given by the preceding MSG_GPS_TIME with the
matching time-of-week (tow). This message is only produced by inertial versions of Swift
products and is not available from Piksi Multi or Duro.


  """
  __slots__ = ['tow',
               'x',
               'y',
               'z',
               'cov_x_x',
               'cov_x_y',
               'cov_x_z',
               'cov_y_y',
               'cov_y_z',
               'cov_z_z',
               'n_sats',
               'flags',
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
          ('tow', 'u4'),
          ('x', 'i4'),
          ('y', 'i4'),
          ('z', 'i4'),
          ('cov_x_x', 'f4'),
          ('cov_x_y', 'f4'),
          ('cov_x_z', 'f4'),
          ('cov_y_y', 'f4'),
          ('cov_y_z', 'f4'),
          ('cov_z_z', 'f4'),
          ('n_sats', 'u1'),
          ('flags', 'u1'),
        ])

    t = getattr(cls, 'static_dtype0', None)
    if not t:
      t = np.dtype([
          ('tow', 'u4'),
          ('x', 'i4'),
          ('y', 'i4'),
          ('z', 'i4'),
          ('cov_x_x', 'f4'),
          ('cov_x_y', 'f4'),
          ('cov_x_z', 'f4'),
          ('cov_y_y', 'f4'),
          ('cov_y_z', 'f4'),
          ('cov_z_z', 'f4'),
          ('n_sats', 'u1'),
          ('flags', 'u1'),
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
      'tow': int(res['tow'] if element else res['tow'][0]),
      'x': int(res['x'] if element else res['x'][0]),
      'y': int(res['y'] if element else res['y'][0]),
      'z': int(res['z'] if element else res['z'][0]),
      'cov_x_x': float(res['cov_x_x'] if element else res['cov_x_x'][0]),
      'cov_x_y': float(res['cov_x_y'] if element else res['cov_x_y'][0]),
      'cov_x_z': float(res['cov_x_z'] if element else res['cov_x_z'][0]),
      'cov_y_y': float(res['cov_y_y'] if element else res['cov_y_y'][0]),
      'cov_y_z': float(res['cov_y_z'] if element else res['cov_y_z'][0]),
      'cov_z_z': float(res['cov_z_z'] if element else res['cov_z_z'][0]),
      'n_sats': int(res['n_sats'] if element else res['n_sats'][0]),
      'flags': int(res['flags'] if element else res['flags'][0]),
    }
    return d

  
SBP_MSG_AGE_CORRECTIONS = 0x0210
class MsgAgeCorrections(SBP):
  """SBP class for message MSG_AGE_CORRECTIONS (0x0210).

  You can have MSG_AGE_CORRECTIONS inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  This message reports the Age of the corrections used for the current
Differential solution


  """
  __slots__ = ['tow',
               'age',
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
          ('tow', 'u4'),
          ('age', 'u2'),
        ])

    t = getattr(cls, 'static_dtype0', None)
    if not t:
      t = np.dtype([
          ('tow', 'u4'),
          ('age', 'u2'),
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
      'tow': int(res['tow'] if element else res['tow'][0]),
      'age': int(res['age'] if element else res['age'][0]),
    }
    return d

  
SBP_MSG_GPS_TIME_DEP_A = 0x0100
class MsgGPSTimeDepA(SBP):
  """SBP class for message MSG_GPS_TIME_DEP_A (0x0100).

  You can have MSG_GPS_TIME_DEP_A inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  This message reports the GPS time, representing the time since
the GPS epoch began on midnight January 6, 1980 UTC. GPS time
counts the weeks and seconds of the week. The weeks begin at the
Saturday/Sunday transition. GPS week 0 began at the beginning of
the GPS time scale.

Within each week number, the GPS time of the week is between
between 0 and 604800 seconds (=60*60*24*7). Note that GPS time
does not accumulate leap seconds, and as of now, has a small
offset from UTC. In a message stream, this message precedes a
set of other navigation messages referenced to the same time
(but lacking the ns field) and indicates a more precise time of
these messages.


  """
  __slots__ = ['wn',
               'tow',
               'ns_residual',
               'flags',
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
          ('wn', 'u2'),
          ('tow', 'u4'),
          ('ns_residual', 'i4'),
          ('flags', 'u1'),
        ])

    t = getattr(cls, 'static_dtype0', None)
    if not t:
      t = np.dtype([
          ('wn', 'u2'),
          ('tow', 'u4'),
          ('ns_residual', 'i4'),
          ('flags', 'u1'),
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
      'wn': int(res['wn'] if element else res['wn'][0]),
      'tow': int(res['tow'] if element else res['tow'][0]),
      'ns_residual': int(res['ns_residual'] if element else res['ns_residual'][0]),
      'flags': int(res['flags'] if element else res['flags'][0]),
    }
    return d

  
SBP_MSG_DOPS_DEP_A = 0x0206
class MsgDopsDepA(SBP):
  """SBP class for message MSG_DOPS_DEP_A (0x0206).

  You can have MSG_DOPS_DEP_A inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  This dilution of precision (DOP) message describes the effect of
navigation satellite geometry on positional measurement
precision.


  """
  __slots__ = ['tow',
               'gdop',
               'pdop',
               'tdop',
               'hdop',
               'vdop',
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
          ('tow', 'u4'),
          ('gdop', 'u2'),
          ('pdop', 'u2'),
          ('tdop', 'u2'),
          ('hdop', 'u2'),
          ('vdop', 'u2'),
        ])

    t = getattr(cls, 'static_dtype0', None)
    if not t:
      t = np.dtype([
          ('tow', 'u4'),
          ('gdop', 'u2'),
          ('pdop', 'u2'),
          ('tdop', 'u2'),
          ('hdop', 'u2'),
          ('vdop', 'u2'),
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
      'tow': int(res['tow'] if element else res['tow'][0]),
      'gdop': int(res['gdop'] if element else res['gdop'][0]),
      'pdop': int(res['pdop'] if element else res['pdop'][0]),
      'tdop': int(res['tdop'] if element else res['tdop'][0]),
      'hdop': int(res['hdop'] if element else res['hdop'][0]),
      'vdop': int(res['vdop'] if element else res['vdop'][0]),
    }
    return d

  
SBP_MSG_POS_ECEF_DEP_A = 0x0200
class MsgPosECEFDepA(SBP):
  """SBP class for message MSG_POS_ECEF_DEP_A (0x0200).

  You can have MSG_POS_ECEF_DEP_A inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  The position solution message reports absolute Earth Centered
Earth Fixed (ECEF) coordinates and the status (single point vs
pseudo-absolute RTK) of the position solution. If the rover
receiver knows the surveyed position of the base station and has
an RTK solution, this reports a pseudo-absolute position
solution using the base station position and the rover's RTK
baseline vector. The full GPS time is given by the preceding
MSG_GPS_TIME with the matching time-of-week (tow).


  """
  __slots__ = ['tow',
               'x',
               'y',
               'z',
               'accuracy',
               'n_sats',
               'flags',
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
          ('tow', 'u4'),
          ('x', 'f8'),
          ('y', 'f8'),
          ('z', 'f8'),
          ('accuracy', 'u2'),
          ('n_sats', 'u1'),
          ('flags', 'u1'),
        ])

    t = getattr(cls, 'static_dtype0', None)
    if not t:
      t = np.dtype([
          ('tow', 'u4'),
          ('x', 'f8'),
          ('y', 'f8'),
          ('z', 'f8'),
          ('accuracy', 'u2'),
          ('n_sats', 'u1'),
          ('flags', 'u1'),
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
      'tow': int(res['tow'] if element else res['tow'][0]),
      'x': float(res['x'] if element else res['x'][0]),
      'y': float(res['y'] if element else res['y'][0]),
      'z': float(res['z'] if element else res['z'][0]),
      'accuracy': int(res['accuracy'] if element else res['accuracy'][0]),
      'n_sats': int(res['n_sats'] if element else res['n_sats'][0]),
      'flags': int(res['flags'] if element else res['flags'][0]),
    }
    return d

  
SBP_MSG_POS_LLH_DEP_A = 0x0201
class MsgPosLLHDepA(SBP):
  """SBP class for message MSG_POS_LLH_DEP_A (0x0201).

  You can have MSG_POS_LLH_DEP_A inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  This position solution message reports the absolute geodetic
coordinates and the status (single point vs pseudo-absolute RTK)
of the position solution. If the rover receiver knows the
surveyed position of the base station and has an RTK solution,
this reports a pseudo-absolute position solution using the base
station position and the rover's RTK baseline vector. The full
GPS time is given by the preceding MSG_GPS_TIME with the
matching time-of-week (tow).


  """
  __slots__ = ['tow',
               'lat',
               'lon',
               'height',
               'h_accuracy',
               'v_accuracy',
               'n_sats',
               'flags',
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
          ('tow', 'u4'),
          ('lat', 'f8'),
          ('lon', 'f8'),
          ('height', 'f8'),
          ('h_accuracy', 'u2'),
          ('v_accuracy', 'u2'),
          ('n_sats', 'u1'),
          ('flags', 'u1'),
        ])

    t = getattr(cls, 'static_dtype0', None)
    if not t:
      t = np.dtype([
          ('tow', 'u4'),
          ('lat', 'f8'),
          ('lon', 'f8'),
          ('height', 'f8'),
          ('h_accuracy', 'u2'),
          ('v_accuracy', 'u2'),
          ('n_sats', 'u1'),
          ('flags', 'u1'),
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
      'tow': int(res['tow'] if element else res['tow'][0]),
      'lat': float(res['lat'] if element else res['lat'][0]),
      'lon': float(res['lon'] if element else res['lon'][0]),
      'height': float(res['height'] if element else res['height'][0]),
      'h_accuracy': int(res['h_accuracy'] if element else res['h_accuracy'][0]),
      'v_accuracy': int(res['v_accuracy'] if element else res['v_accuracy'][0]),
      'n_sats': int(res['n_sats'] if element else res['n_sats'][0]),
      'flags': int(res['flags'] if element else res['flags'][0]),
    }
    return d

  
SBP_MSG_BASELINE_ECEF_DEP_A = 0x0202
class MsgBaselineECEFDepA(SBP):
  """SBP class for message MSG_BASELINE_ECEF_DEP_A (0x0202).

  You can have MSG_BASELINE_ECEF_DEP_A inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  This message reports the baseline solution in Earth Centered
Earth Fixed (ECEF) coordinates. This baseline is the relative
vector distance from the base station to the rover receiver. The
full GPS time is given by the preceding MSG_GPS_TIME with the
matching time-of-week (tow).


  """
  __slots__ = ['tow',
               'x',
               'y',
               'z',
               'accuracy',
               'n_sats',
               'flags',
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
          ('tow', 'u4'),
          ('x', 'i4'),
          ('y', 'i4'),
          ('z', 'i4'),
          ('accuracy', 'u2'),
          ('n_sats', 'u1'),
          ('flags', 'u1'),
        ])

    t = getattr(cls, 'static_dtype0', None)
    if not t:
      t = np.dtype([
          ('tow', 'u4'),
          ('x', 'i4'),
          ('y', 'i4'),
          ('z', 'i4'),
          ('accuracy', 'u2'),
          ('n_sats', 'u1'),
          ('flags', 'u1'),
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
      'tow': int(res['tow'] if element else res['tow'][0]),
      'x': int(res['x'] if element else res['x'][0]),
      'y': int(res['y'] if element else res['y'][0]),
      'z': int(res['z'] if element else res['z'][0]),
      'accuracy': int(res['accuracy'] if element else res['accuracy'][0]),
      'n_sats': int(res['n_sats'] if element else res['n_sats'][0]),
      'flags': int(res['flags'] if element else res['flags'][0]),
    }
    return d

  
SBP_MSG_BASELINE_NED_DEP_A = 0x0203
class MsgBaselineNEDDepA(SBP):
  """SBP class for message MSG_BASELINE_NED_DEP_A (0x0203).

  You can have MSG_BASELINE_NED_DEP_A inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  This message reports the baseline solution in North East Down
(NED) coordinates. This baseline is the relative vector distance
from the base station to the rover receiver, and NED coordinate
system is defined at the local WGS84 tangent plane centered at the
base station position.  The full GPS time is given by the
preceding MSG_GPS_TIME with the matching time-of-week (tow).


  """
  __slots__ = ['tow',
               'n',
               'e',
               'd',
               'h_accuracy',
               'v_accuracy',
               'n_sats',
               'flags',
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
          ('tow', 'u4'),
          ('n', 'i4'),
          ('e', 'i4'),
          ('d', 'i4'),
          ('h_accuracy', 'u2'),
          ('v_accuracy', 'u2'),
          ('n_sats', 'u1'),
          ('flags', 'u1'),
        ])

    t = getattr(cls, 'static_dtype0', None)
    if not t:
      t = np.dtype([
          ('tow', 'u4'),
          ('n', 'i4'),
          ('e', 'i4'),
          ('d', 'i4'),
          ('h_accuracy', 'u2'),
          ('v_accuracy', 'u2'),
          ('n_sats', 'u1'),
          ('flags', 'u1'),
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
      'tow': int(res['tow'] if element else res['tow'][0]),
      'n': int(res['n'] if element else res['n'][0]),
      'e': int(res['e'] if element else res['e'][0]),
      'd': int(res['d'] if element else res['d'][0]),
      'h_accuracy': int(res['h_accuracy'] if element else res['h_accuracy'][0]),
      'v_accuracy': int(res['v_accuracy'] if element else res['v_accuracy'][0]),
      'n_sats': int(res['n_sats'] if element else res['n_sats'][0]),
      'flags': int(res['flags'] if element else res['flags'][0]),
    }
    return d

  
SBP_MSG_VEL_ECEF_DEP_A = 0x0204
class MsgVelECEFDepA(SBP):
  """SBP class for message MSG_VEL_ECEF_DEP_A (0x0204).

  You can have MSG_VEL_ECEF_DEP_A inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  This message reports the velocity in Earth Centered Earth Fixed
(ECEF) coordinates. The full GPS time is given by the preceding
MSG_GPS_TIME with the matching time-of-week (tow).


  """
  __slots__ = ['tow',
               'x',
               'y',
               'z',
               'accuracy',
               'n_sats',
               'flags',
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
          ('tow', 'u4'),
          ('x', 'i4'),
          ('y', 'i4'),
          ('z', 'i4'),
          ('accuracy', 'u2'),
          ('n_sats', 'u1'),
          ('flags', 'u1'),
        ])

    t = getattr(cls, 'static_dtype0', None)
    if not t:
      t = np.dtype([
          ('tow', 'u4'),
          ('x', 'i4'),
          ('y', 'i4'),
          ('z', 'i4'),
          ('accuracy', 'u2'),
          ('n_sats', 'u1'),
          ('flags', 'u1'),
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
      'tow': int(res['tow'] if element else res['tow'][0]),
      'x': int(res['x'] if element else res['x'][0]),
      'y': int(res['y'] if element else res['y'][0]),
      'z': int(res['z'] if element else res['z'][0]),
      'accuracy': int(res['accuracy'] if element else res['accuracy'][0]),
      'n_sats': int(res['n_sats'] if element else res['n_sats'][0]),
      'flags': int(res['flags'] if element else res['flags'][0]),
    }
    return d

  
SBP_MSG_VEL_NED_DEP_A = 0x0205
class MsgVelNEDDepA(SBP):
  """SBP class for message MSG_VEL_NED_DEP_A (0x0205).

  You can have MSG_VEL_NED_DEP_A inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  This message reports the velocity in local North East Down (NED)
coordinates. The NED coordinate system is defined as the local WGS84
tangent plane centered at the current position. The full GPS time is
given by the preceding MSG_GPS_TIME with the matching time-of-week (tow).


  """
  __slots__ = ['tow',
               'n',
               'e',
               'd',
               'h_accuracy',
               'v_accuracy',
               'n_sats',
               'flags',
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
          ('tow', 'u4'),
          ('n', 'i4'),
          ('e', 'i4'),
          ('d', 'i4'),
          ('h_accuracy', 'u2'),
          ('v_accuracy', 'u2'),
          ('n_sats', 'u1'),
          ('flags', 'u1'),
        ])

    t = getattr(cls, 'static_dtype0', None)
    if not t:
      t = np.dtype([
          ('tow', 'u4'),
          ('n', 'i4'),
          ('e', 'i4'),
          ('d', 'i4'),
          ('h_accuracy', 'u2'),
          ('v_accuracy', 'u2'),
          ('n_sats', 'u1'),
          ('flags', 'u1'),
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
      'tow': int(res['tow'] if element else res['tow'][0]),
      'n': int(res['n'] if element else res['n'][0]),
      'e': int(res['e'] if element else res['e'][0]),
      'd': int(res['d'] if element else res['d'][0]),
      'h_accuracy': int(res['h_accuracy'] if element else res['h_accuracy'][0]),
      'v_accuracy': int(res['v_accuracy'] if element else res['v_accuracy'][0]),
      'n_sats': int(res['n_sats'] if element else res['n_sats'][0]),
      'flags': int(res['flags'] if element else res['flags'][0]),
    }
    return d

  
SBP_MSG_BASELINE_HEADING_DEP_A = 0x0207
class MsgBaselineHeadingDepA(SBP):
  """SBP class for message MSG_BASELINE_HEADING_DEP_A (0x0207).

  You can have MSG_BASELINE_HEADING_DEP_A inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  This message reports the baseline heading pointing from the base station
to the rover relative to True North. The full GPS time is given by the
preceding MSG_GPS_TIME with the matching time-of-week (tow).


  """
  __slots__ = ['tow',
               'heading',
               'n_sats',
               'flags',
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
          ('tow', 'u4'),
          ('heading', 'u4'),
          ('n_sats', 'u1'),
          ('flags', 'u1'),
        ])

    t = getattr(cls, 'static_dtype0', None)
    if not t:
      t = np.dtype([
          ('tow', 'u4'),
          ('heading', 'u4'),
          ('n_sats', 'u1'),
          ('flags', 'u1'),
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
      'tow': int(res['tow'] if element else res['tow'][0]),
      'heading': int(res['heading'] if element else res['heading'][0]),
      'n_sats': int(res['n_sats'] if element else res['n_sats'][0]),
      'flags': int(res['flags'] if element else res['flags'][0]),
    }
    return d

  

msg_classes = {
  0x0102: MsgGPSTime,
  0x0103: MsgUtcTime,
  0x0208: MsgDops,
  0x0209: MsgPosECEF,
  0x0214: MsgPosECEFCov,
  0x020A: MsgPosLLH,
  0x0211: MsgPosLLHCov,
  0x020B: MsgBaselineECEF,
  0x020C: MsgBaselineNED,
  0x020D: MsgVelECEF,
  0x0215: MsgVelECEFCov,
  0x020E: MsgVelNED,
  0x0212: MsgVelNEDCov,
  0x0213: MsgVelBody,
  0x0210: MsgAgeCorrections,
  0x0100: MsgGPSTimeDepA,
  0x0206: MsgDopsDepA,
  0x0200: MsgPosECEFDepA,
  0x0201: MsgPosLLHDepA,
  0x0202: MsgBaselineECEFDepA,
  0x0203: MsgBaselineNEDDepA,
  0x0204: MsgVelECEFDepA,
  0x0205: MsgVelNEDDepA,
  0x0207: MsgBaselineHeadingDepA,
}