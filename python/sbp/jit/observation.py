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

import numba as nb
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
          ('t', GPSTime._static_dtype()),
          ('n_obs', 'u1'),
        ])

    t = getattr(cls, 'static_dtype0', None)
    if not t:
      t = np.dtype([
          ('t', GPSTime._static_dtype()),
          ('n_obs', 'u1'),
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
      't': GPSTime._unpack_members(res['t'], element=element),
      'n_obs': int(res['n_obs'] if element else res['n_obs'][0]),
    }
    return d

  
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
          ('i', 'i2'),
          ('f', 'u1'),
        ])

    t = getattr(cls, 'static_dtype0', None)
    if not t:
      t = np.dtype([
          ('i', 'i2'),
          ('f', 'u1'),
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
      'i': int(res['i'] if element else res['i'][0]),
      'f': int(res['f'] if element else res['f'][0]),
    }
    return d

  
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
          ('P', 'u4'),
          ('L', CarrierPhase._static_dtype()),
          ('D', Doppler._static_dtype()),
          ('cn0', 'u1'),
          ('lock', 'u1'),
          ('flags', 'u1'),
          ('sid', GnssSignal._static_dtype()),
        ])

    t = getattr(cls, 'static_dtype0', None)
    if not t:
      t = np.dtype([
          ('P', 'u4'),
          ('L', CarrierPhase._static_dtype()),
          ('D', Doppler._static_dtype()),
          ('cn0', 'u1'),
          ('lock', 'u1'),
          ('flags', 'u1'),
          ('sid', GnssSignal._static_dtype()),
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
      'P': int(res['P'] if element else res['P'][0]),
      'L': CarrierPhase._unpack_members(res['L'], element=element),
      'D': Doppler._unpack_members(res['D'], element=element),
      'cn0': int(res['cn0'] if element else res['cn0'][0]),
      'lock': int(res['lock'] if element else res['lock'][0]),
      'flags': int(res['flags'] if element else res['flags'][0]),
      'sid': GnssSignal._unpack_members(res['sid'], element=element),
    }
    return d

  
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
          ('P', 'u4'),
          ('L', CarrierPhase._static_dtype()),
          ('lock', 'u1'),
          ('flags', 'u1'),
          ('sid', GnssSignal._static_dtype()),
          ('iono_std', 'u2'),
          ('tropo_std', 'u2'),
          ('range_std', 'u2'),
        ])

    t = getattr(cls, 'static_dtype0', None)
    if not t:
      t = np.dtype([
          ('P', 'u4'),
          ('L', CarrierPhase._static_dtype()),
          ('lock', 'u1'),
          ('flags', 'u1'),
          ('sid', GnssSignal._static_dtype()),
          ('iono_std', 'u2'),
          ('tropo_std', 'u2'),
          ('range_std', 'u2'),
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
      'P': int(res['P'] if element else res['P'][0]),
      'L': CarrierPhase._unpack_members(res['L'], element=element),
      'lock': int(res['lock'] if element else res['lock'][0]),
      'flags': int(res['flags'] if element else res['flags'][0]),
      'sid': GnssSignal._unpack_members(res['sid'], element=element),
      'iono_std': int(res['iono_std'] if element else res['iono_std'][0]),
      'tropo_std': int(res['tropo_std'] if element else res['tropo_std'][0]),
      'range_std': int(res['range_std'] if element else res['range_std'][0]),
    }
    return d

  
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
          ('header', ObservationHeader._static_dtype()),
          ('obs', (PackedObsContent._static_dtype(), (count,))),
        ])

    t = getattr(cls, 'static_dtype0', None)
    if not t:
      t = np.dtype([
          ('header', ObservationHeader._static_dtype()),
          ('obs', (PackedObsContent._static_dtype(), (count,))),
        ])
      cls.static_dtype0 = t
    return t

  @classmethod
  def _dynamic_dtype(cls):
    t = getattr(cls, 'dynamic_dtype', None)
    if not t:    
      t = np.dtype([('obs', PackedObsContent._static_dtype()),])
      cls.dynamic_dtype = t
    return t

  @staticmethod
  def _unpack_members(res, element=False):
    d = {
      'header': ObservationHeader._unpack_members(res['header'], element=element),
      'obs': [] if res['obs'] is None else [PackedObsContent._unpack_members(x, element=True) for x in res['obs'].flatten()],
    }
    return d

  
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
          ('lat', 'f8'),
          ('lon', 'f8'),
          ('height', 'f8'),
        ])

    t = getattr(cls, 'static_dtype0', None)
    if not t:
      t = np.dtype([
          ('lat', 'f8'),
          ('lon', 'f8'),
          ('height', 'f8'),
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
      'lat': float(res['lat'] if element else res['lat'][0]),
      'lon': float(res['lon'] if element else res['lon'][0]),
      'height': float(res['height'] if element else res['height'][0]),
    }
    return d

  
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
          ('x', 'f8'),
          ('y', 'f8'),
          ('z', 'f8'),
        ])

    t = getattr(cls, 'static_dtype0', None)
    if not t:
      t = np.dtype([
          ('x', 'f8'),
          ('y', 'f8'),
          ('z', 'f8'),
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
      'x': float(res['x'] if element else res['x'][0]),
      'y': float(res['y'] if element else res['y'][0]),
      'z': float(res['z'] if element else res['z'][0]),
    }
    return d

  
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
          ('sid', GnssSignal._static_dtype()),
          ('toe', GPSTimeSec._static_dtype()),
          ('ura', 'f4'),
          ('fit_interval', 'u4'),
          ('valid', 'u1'),
          ('health_bits', 'u1'),
        ])

    t = getattr(cls, 'static_dtype0', None)
    if not t:
      t = np.dtype([
          ('sid', GnssSignal._static_dtype()),
          ('toe', GPSTimeSec._static_dtype()),
          ('ura', 'f4'),
          ('fit_interval', 'u4'),
          ('valid', 'u1'),
          ('health_bits', 'u1'),
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
      'sid': GnssSignal._unpack_members(res['sid'], element=element),
      'toe': GPSTimeSec._unpack_members(res['toe'], element=element),
      'ura': float(res['ura'] if element else res['ura'][0]),
      'fit_interval': int(res['fit_interval'] if element else res['fit_interval'][0]),
      'valid': int(res['valid'] if element else res['valid'][0]),
      'health_bits': int(res['health_bits'] if element else res['health_bits'][0]),
    }
    return d

  
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
          ('sid', GnssSignal._static_dtype()),
          ('toe', GPSTimeSec._static_dtype()),
          ('ura', 'f8'),
          ('fit_interval', 'u4'),
          ('valid', 'u1'),
          ('health_bits', 'u1'),
        ])

    t = getattr(cls, 'static_dtype0', None)
    if not t:
      t = np.dtype([
          ('sid', GnssSignal._static_dtype()),
          ('toe', GPSTimeSec._static_dtype()),
          ('ura', 'f8'),
          ('fit_interval', 'u4'),
          ('valid', 'u1'),
          ('health_bits', 'u1'),
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
      'sid': GnssSignal._unpack_members(res['sid'], element=element),
      'toe': GPSTimeSec._unpack_members(res['toe'], element=element),
      'ura': float(res['ura'] if element else res['ura'][0]),
      'fit_interval': int(res['fit_interval'] if element else res['fit_interval'][0]),
      'valid': int(res['valid'] if element else res['valid'][0]),
      'health_bits': int(res['health_bits'] if element else res['health_bits'][0]),
    }
    return d

  
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
          ('sid', GnssSignalDep._static_dtype()),
          ('toe', GPSTimeDep._static_dtype()),
          ('ura', 'f8'),
          ('fit_interval', 'u4'),
          ('valid', 'u1'),
          ('health_bits', 'u1'),
        ])

    t = getattr(cls, 'static_dtype0', None)
    if not t:
      t = np.dtype([
          ('sid', GnssSignalDep._static_dtype()),
          ('toe', GPSTimeDep._static_dtype()),
          ('ura', 'f8'),
          ('fit_interval', 'u4'),
          ('valid', 'u1'),
          ('health_bits', 'u1'),
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
      'sid': GnssSignalDep._unpack_members(res['sid'], element=element),
      'toe': GPSTimeDep._unpack_members(res['toe'], element=element),
      'ura': float(res['ura'] if element else res['ura'][0]),
      'fit_interval': int(res['fit_interval'] if element else res['fit_interval'][0]),
      'valid': int(res['valid'] if element else res['valid'][0]),
      'health_bits': int(res['health_bits'] if element else res['health_bits'][0]),
    }
    return d

  
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
          ('common', EphemerisCommonContentDepA._static_dtype()),
          ('tgd', 'f8'),
          ('c_rs', 'f8'),
          ('c_rc', 'f8'),
          ('c_uc', 'f8'),
          ('c_us', 'f8'),
          ('c_ic', 'f8'),
          ('c_is', 'f8'),
          ('dn', 'f8'),
          ('m0', 'f8'),
          ('ecc', 'f8'),
          ('sqrta', 'f8'),
          ('omega0', 'f8'),
          ('omegadot', 'f8'),
          ('w', 'f8'),
          ('inc', 'f8'),
          ('inc_dot', 'f8'),
          ('af0', 'f8'),
          ('af1', 'f8'),
          ('af2', 'f8'),
          ('toc', GPSTimeDep._static_dtype()),
          ('iode', 'u1'),
          ('iodc', 'u2'),
        ])

    t = getattr(cls, 'static_dtype0', None)
    if not t:
      t = np.dtype([
          ('common', EphemerisCommonContentDepA._static_dtype()),
          ('tgd', 'f8'),
          ('c_rs', 'f8'),
          ('c_rc', 'f8'),
          ('c_uc', 'f8'),
          ('c_us', 'f8'),
          ('c_ic', 'f8'),
          ('c_is', 'f8'),
          ('dn', 'f8'),
          ('m0', 'f8'),
          ('ecc', 'f8'),
          ('sqrta', 'f8'),
          ('omega0', 'f8'),
          ('omegadot', 'f8'),
          ('w', 'f8'),
          ('inc', 'f8'),
          ('inc_dot', 'f8'),
          ('af0', 'f8'),
          ('af1', 'f8'),
          ('af2', 'f8'),
          ('toc', GPSTimeDep._static_dtype()),
          ('iode', 'u1'),
          ('iodc', 'u2'),
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
      'common': EphemerisCommonContentDepA._unpack_members(res['common'], element=element),
      'tgd': float(res['tgd'] if element else res['tgd'][0]),
      'c_rs': float(res['c_rs'] if element else res['c_rs'][0]),
      'c_rc': float(res['c_rc'] if element else res['c_rc'][0]),
      'c_uc': float(res['c_uc'] if element else res['c_uc'][0]),
      'c_us': float(res['c_us'] if element else res['c_us'][0]),
      'c_ic': float(res['c_ic'] if element else res['c_ic'][0]),
      'c_is': float(res['c_is'] if element else res['c_is'][0]),
      'dn': float(res['dn'] if element else res['dn'][0]),
      'm0': float(res['m0'] if element else res['m0'][0]),
      'ecc': float(res['ecc'] if element else res['ecc'][0]),
      'sqrta': float(res['sqrta'] if element else res['sqrta'][0]),
      'omega0': float(res['omega0'] if element else res['omega0'][0]),
      'omegadot': float(res['omegadot'] if element else res['omegadot'][0]),
      'w': float(res['w'] if element else res['w'][0]),
      'inc': float(res['inc'] if element else res['inc'][0]),
      'inc_dot': float(res['inc_dot'] if element else res['inc_dot'][0]),
      'af0': float(res['af0'] if element else res['af0'][0]),
      'af1': float(res['af1'] if element else res['af1'][0]),
      'af2': float(res['af2'] if element else res['af2'][0]),
      'toc': GPSTimeDep._unpack_members(res['toc'], element=element),
      'iode': int(res['iode'] if element else res['iode'][0]),
      'iodc': int(res['iodc'] if element else res['iodc'][0]),
    }
    return d

  
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
          ('common', EphemerisCommonContentDepB._static_dtype()),
          ('tgd', 'f8'),
          ('c_rs', 'f8'),
          ('c_rc', 'f8'),
          ('c_uc', 'f8'),
          ('c_us', 'f8'),
          ('c_ic', 'f8'),
          ('c_is', 'f8'),
          ('dn', 'f8'),
          ('m0', 'f8'),
          ('ecc', 'f8'),
          ('sqrta', 'f8'),
          ('omega0', 'f8'),
          ('omegadot', 'f8'),
          ('w', 'f8'),
          ('inc', 'f8'),
          ('inc_dot', 'f8'),
          ('af0', 'f8'),
          ('af1', 'f8'),
          ('af2', 'f8'),
          ('toc', GPSTimeSec._static_dtype()),
          ('iode', 'u1'),
          ('iodc', 'u2'),
        ])

    t = getattr(cls, 'static_dtype0', None)
    if not t:
      t = np.dtype([
          ('common', EphemerisCommonContentDepB._static_dtype()),
          ('tgd', 'f8'),
          ('c_rs', 'f8'),
          ('c_rc', 'f8'),
          ('c_uc', 'f8'),
          ('c_us', 'f8'),
          ('c_ic', 'f8'),
          ('c_is', 'f8'),
          ('dn', 'f8'),
          ('m0', 'f8'),
          ('ecc', 'f8'),
          ('sqrta', 'f8'),
          ('omega0', 'f8'),
          ('omegadot', 'f8'),
          ('w', 'f8'),
          ('inc', 'f8'),
          ('inc_dot', 'f8'),
          ('af0', 'f8'),
          ('af1', 'f8'),
          ('af2', 'f8'),
          ('toc', GPSTimeSec._static_dtype()),
          ('iode', 'u1'),
          ('iodc', 'u2'),
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
      'common': EphemerisCommonContentDepB._unpack_members(res['common'], element=element),
      'tgd': float(res['tgd'] if element else res['tgd'][0]),
      'c_rs': float(res['c_rs'] if element else res['c_rs'][0]),
      'c_rc': float(res['c_rc'] if element else res['c_rc'][0]),
      'c_uc': float(res['c_uc'] if element else res['c_uc'][0]),
      'c_us': float(res['c_us'] if element else res['c_us'][0]),
      'c_ic': float(res['c_ic'] if element else res['c_ic'][0]),
      'c_is': float(res['c_is'] if element else res['c_is'][0]),
      'dn': float(res['dn'] if element else res['dn'][0]),
      'm0': float(res['m0'] if element else res['m0'][0]),
      'ecc': float(res['ecc'] if element else res['ecc'][0]),
      'sqrta': float(res['sqrta'] if element else res['sqrta'][0]),
      'omega0': float(res['omega0'] if element else res['omega0'][0]),
      'omegadot': float(res['omegadot'] if element else res['omegadot'][0]),
      'w': float(res['w'] if element else res['w'][0]),
      'inc': float(res['inc'] if element else res['inc'][0]),
      'inc_dot': float(res['inc_dot'] if element else res['inc_dot'][0]),
      'af0': float(res['af0'] if element else res['af0'][0]),
      'af1': float(res['af1'] if element else res['af1'][0]),
      'af2': float(res['af2'] if element else res['af2'][0]),
      'toc': GPSTimeSec._unpack_members(res['toc'], element=element),
      'iode': int(res['iode'] if element else res['iode'][0]),
      'iodc': int(res['iodc'] if element else res['iodc'][0]),
    }
    return d

  
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
          ('common', EphemerisCommonContent._static_dtype()),
          ('tgd', 'f4'),
          ('c_rs', 'f4'),
          ('c_rc', 'f4'),
          ('c_uc', 'f4'),
          ('c_us', 'f4'),
          ('c_ic', 'f4'),
          ('c_is', 'f4'),
          ('dn', 'f8'),
          ('m0', 'f8'),
          ('ecc', 'f8'),
          ('sqrta', 'f8'),
          ('omega0', 'f8'),
          ('omegadot', 'f8'),
          ('w', 'f8'),
          ('inc', 'f8'),
          ('inc_dot', 'f8'),
          ('af0', 'f4'),
          ('af1', 'f4'),
          ('af2', 'f4'),
          ('toc', GPSTimeSec._static_dtype()),
          ('iode', 'u1'),
          ('iodc', 'u2'),
        ])

    t = getattr(cls, 'static_dtype0', None)
    if not t:
      t = np.dtype([
          ('common', EphemerisCommonContent._static_dtype()),
          ('tgd', 'f4'),
          ('c_rs', 'f4'),
          ('c_rc', 'f4'),
          ('c_uc', 'f4'),
          ('c_us', 'f4'),
          ('c_ic', 'f4'),
          ('c_is', 'f4'),
          ('dn', 'f8'),
          ('m0', 'f8'),
          ('ecc', 'f8'),
          ('sqrta', 'f8'),
          ('omega0', 'f8'),
          ('omegadot', 'f8'),
          ('w', 'f8'),
          ('inc', 'f8'),
          ('inc_dot', 'f8'),
          ('af0', 'f4'),
          ('af1', 'f4'),
          ('af2', 'f4'),
          ('toc', GPSTimeSec._static_dtype()),
          ('iode', 'u1'),
          ('iodc', 'u2'),
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
      'common': EphemerisCommonContent._unpack_members(res['common'], element=element),
      'tgd': float(res['tgd'] if element else res['tgd'][0]),
      'c_rs': float(res['c_rs'] if element else res['c_rs'][0]),
      'c_rc': float(res['c_rc'] if element else res['c_rc'][0]),
      'c_uc': float(res['c_uc'] if element else res['c_uc'][0]),
      'c_us': float(res['c_us'] if element else res['c_us'][0]),
      'c_ic': float(res['c_ic'] if element else res['c_ic'][0]),
      'c_is': float(res['c_is'] if element else res['c_is'][0]),
      'dn': float(res['dn'] if element else res['dn'][0]),
      'm0': float(res['m0'] if element else res['m0'][0]),
      'ecc': float(res['ecc'] if element else res['ecc'][0]),
      'sqrta': float(res['sqrta'] if element else res['sqrta'][0]),
      'omega0': float(res['omega0'] if element else res['omega0'][0]),
      'omegadot': float(res['omegadot'] if element else res['omegadot'][0]),
      'w': float(res['w'] if element else res['w'][0]),
      'inc': float(res['inc'] if element else res['inc'][0]),
      'inc_dot': float(res['inc_dot'] if element else res['inc_dot'][0]),
      'af0': float(res['af0'] if element else res['af0'][0]),
      'af1': float(res['af1'] if element else res['af1'][0]),
      'af2': float(res['af2'] if element else res['af2'][0]),
      'toc': GPSTimeSec._unpack_members(res['toc'], element=element),
      'iode': int(res['iode'] if element else res['iode'][0]),
      'iodc': int(res['iodc'] if element else res['iodc'][0]),
    }
    return d

  
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
          ('common', EphemerisCommonContent._static_dtype()),
          ('tgd1', 'f4'),
          ('tgd2', 'f4'),
          ('c_rs', 'f4'),
          ('c_rc', 'f4'),
          ('c_uc', 'f4'),
          ('c_us', 'f4'),
          ('c_ic', 'f4'),
          ('c_is', 'f4'),
          ('dn', 'f8'),
          ('m0', 'f8'),
          ('ecc', 'f8'),
          ('sqrta', 'f8'),
          ('omega0', 'f8'),
          ('omegadot', 'f8'),
          ('w', 'f8'),
          ('inc', 'f8'),
          ('inc_dot', 'f8'),
          ('af0', 'f8'),
          ('af1', 'f4'),
          ('af2', 'f4'),
          ('toc', GPSTimeSec._static_dtype()),
          ('iode', 'u1'),
          ('iodc', 'u2'),
        ])

    t = getattr(cls, 'static_dtype0', None)
    if not t:
      t = np.dtype([
          ('common', EphemerisCommonContent._static_dtype()),
          ('tgd1', 'f4'),
          ('tgd2', 'f4'),
          ('c_rs', 'f4'),
          ('c_rc', 'f4'),
          ('c_uc', 'f4'),
          ('c_us', 'f4'),
          ('c_ic', 'f4'),
          ('c_is', 'f4'),
          ('dn', 'f8'),
          ('m0', 'f8'),
          ('ecc', 'f8'),
          ('sqrta', 'f8'),
          ('omega0', 'f8'),
          ('omegadot', 'f8'),
          ('w', 'f8'),
          ('inc', 'f8'),
          ('inc_dot', 'f8'),
          ('af0', 'f8'),
          ('af1', 'f4'),
          ('af2', 'f4'),
          ('toc', GPSTimeSec._static_dtype()),
          ('iode', 'u1'),
          ('iodc', 'u2'),
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
      'common': EphemerisCommonContent._unpack_members(res['common'], element=element),
      'tgd1': float(res['tgd1'] if element else res['tgd1'][0]),
      'tgd2': float(res['tgd2'] if element else res['tgd2'][0]),
      'c_rs': float(res['c_rs'] if element else res['c_rs'][0]),
      'c_rc': float(res['c_rc'] if element else res['c_rc'][0]),
      'c_uc': float(res['c_uc'] if element else res['c_uc'][0]),
      'c_us': float(res['c_us'] if element else res['c_us'][0]),
      'c_ic': float(res['c_ic'] if element else res['c_ic'][0]),
      'c_is': float(res['c_is'] if element else res['c_is'][0]),
      'dn': float(res['dn'] if element else res['dn'][0]),
      'm0': float(res['m0'] if element else res['m0'][0]),
      'ecc': float(res['ecc'] if element else res['ecc'][0]),
      'sqrta': float(res['sqrta'] if element else res['sqrta'][0]),
      'omega0': float(res['omega0'] if element else res['omega0'][0]),
      'omegadot': float(res['omegadot'] if element else res['omegadot'][0]),
      'w': float(res['w'] if element else res['w'][0]),
      'inc': float(res['inc'] if element else res['inc'][0]),
      'inc_dot': float(res['inc_dot'] if element else res['inc_dot'][0]),
      'af0': float(res['af0'] if element else res['af0'][0]),
      'af1': float(res['af1'] if element else res['af1'][0]),
      'af2': float(res['af2'] if element else res['af2'][0]),
      'toc': GPSTimeSec._unpack_members(res['toc'], element=element),
      'iode': int(res['iode'] if element else res['iode'][0]),
      'iodc': int(res['iodc'] if element else res['iodc'][0]),
    }
    return d

  
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
          ('common', EphemerisCommonContent._static_dtype()),
          ('bgd_e1e5a', 'f4'),
          ('bgd_e1e5b', 'f4'),
          ('c_rs', 'f4'),
          ('c_rc', 'f4'),
          ('c_uc', 'f4'),
          ('c_us', 'f4'),
          ('c_ic', 'f4'),
          ('c_is', 'f4'),
          ('dn', 'f8'),
          ('m0', 'f8'),
          ('ecc', 'f8'),
          ('sqrta', 'f8'),
          ('omega0', 'f8'),
          ('omegadot', 'f8'),
          ('w', 'f8'),
          ('inc', 'f8'),
          ('inc_dot', 'f8'),
          ('af0', 'f8'),
          ('af1', 'f8'),
          ('af2', 'f4'),
          ('toc', GPSTimeSec._static_dtype()),
          ('iode', 'u2'),
          ('iodc', 'u2'),
        ])

    t = getattr(cls, 'static_dtype0', None)
    if not t:
      t = np.dtype([
          ('common', EphemerisCommonContent._static_dtype()),
          ('bgd_e1e5a', 'f4'),
          ('bgd_e1e5b', 'f4'),
          ('c_rs', 'f4'),
          ('c_rc', 'f4'),
          ('c_uc', 'f4'),
          ('c_us', 'f4'),
          ('c_ic', 'f4'),
          ('c_is', 'f4'),
          ('dn', 'f8'),
          ('m0', 'f8'),
          ('ecc', 'f8'),
          ('sqrta', 'f8'),
          ('omega0', 'f8'),
          ('omegadot', 'f8'),
          ('w', 'f8'),
          ('inc', 'f8'),
          ('inc_dot', 'f8'),
          ('af0', 'f8'),
          ('af1', 'f8'),
          ('af2', 'f4'),
          ('toc', GPSTimeSec._static_dtype()),
          ('iode', 'u2'),
          ('iodc', 'u2'),
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
      'common': EphemerisCommonContent._unpack_members(res['common'], element=element),
      'bgd_e1e5a': float(res['bgd_e1e5a'] if element else res['bgd_e1e5a'][0]),
      'bgd_e1e5b': float(res['bgd_e1e5b'] if element else res['bgd_e1e5b'][0]),
      'c_rs': float(res['c_rs'] if element else res['c_rs'][0]),
      'c_rc': float(res['c_rc'] if element else res['c_rc'][0]),
      'c_uc': float(res['c_uc'] if element else res['c_uc'][0]),
      'c_us': float(res['c_us'] if element else res['c_us'][0]),
      'c_ic': float(res['c_ic'] if element else res['c_ic'][0]),
      'c_is': float(res['c_is'] if element else res['c_is'][0]),
      'dn': float(res['dn'] if element else res['dn'][0]),
      'm0': float(res['m0'] if element else res['m0'][0]),
      'ecc': float(res['ecc'] if element else res['ecc'][0]),
      'sqrta': float(res['sqrta'] if element else res['sqrta'][0]),
      'omega0': float(res['omega0'] if element else res['omega0'][0]),
      'omegadot': float(res['omegadot'] if element else res['omegadot'][0]),
      'w': float(res['w'] if element else res['w'][0]),
      'inc': float(res['inc'] if element else res['inc'][0]),
      'inc_dot': float(res['inc_dot'] if element else res['inc_dot'][0]),
      'af0': float(res['af0'] if element else res['af0'][0]),
      'af1': float(res['af1'] if element else res['af1'][0]),
      'af2': float(res['af2'] if element else res['af2'][0]),
      'toc': GPSTimeSec._unpack_members(res['toc'], element=element),
      'iode': int(res['iode'] if element else res['iode'][0]),
      'iodc': int(res['iodc'] if element else res['iodc'][0]),
    }
    return d

  
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
          ('common', EphemerisCommonContentDepA._static_dtype()),
          ('pos', ('f8', (3,))),
          ('vel', ('f8', (3,))),
          ('acc', ('f8', (3,))),
          ('a_gf0', 'f8'),
          ('a_gf1', 'f8'),
        ])

    t = getattr(cls, 'static_dtype0', None)
    if not t:
      t = np.dtype([
          ('common', EphemerisCommonContentDepA._static_dtype()),
          ('pos', ('f8', (3,))),
          ('vel', ('f8', (3,))),
          ('acc', ('f8', (3,))),
          ('a_gf0', 'f8'),
          ('a_gf1', 'f8'),
        ])
      cls.static_dtype0 = t
    return t

  @classmethod
  def _dynamic_dtype(cls):
    t = getattr(cls, 'dynamic_dtype', None)
    if not t:    
      t = np.dtype([('pos', 'f8'),])
      cls.dynamic_dtype = t
    return t

  @staticmethod
  def _unpack_members(res, element=False):
    d = {
      'common': EphemerisCommonContentDepA._unpack_members(res['common'], element=element),
      'pos': [] if res['pos'] is None else [x.item() for x in res['pos'].flatten()],
      'vel': [] if res['vel'] is None else [x.item() for x in res['vel'].flatten()],
      'acc': [] if res['acc'] is None else [x.item() for x in res['acc'].flatten()],
      'a_gf0': float(res['a_gf0'] if element else res['a_gf0'][0]),
      'a_gf1': float(res['a_gf1'] if element else res['a_gf1'][0]),
    }
    return d

  
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
          ('common', EphemerisCommonContentDepA._static_dtype()),
          ('gamma', 'f8'),
          ('tau', 'f8'),
          ('pos', ('f8', (3,))),
          ('vel', ('f8', (3,))),
          ('acc', ('f8', (3,))),
        ])

    t = getattr(cls, 'static_dtype0', None)
    if not t:
      t = np.dtype([
          ('common', EphemerisCommonContentDepA._static_dtype()),
          ('gamma', 'f8'),
          ('tau', 'f8'),
          ('pos', ('f8', (3,))),
          ('vel', ('f8', (3,))),
          ('acc', ('f8', (3,))),
        ])
      cls.static_dtype0 = t
    return t

  @classmethod
  def _dynamic_dtype(cls):
    t = getattr(cls, 'dynamic_dtype', None)
    if not t:    
      t = np.dtype([('pos', 'f8'),])
      cls.dynamic_dtype = t
    return t

  @staticmethod
  def _unpack_members(res, element=False):
    d = {
      'common': EphemerisCommonContentDepA._unpack_members(res['common'], element=element),
      'gamma': float(res['gamma'] if element else res['gamma'][0]),
      'tau': float(res['tau'] if element else res['tau'][0]),
      'pos': [] if res['pos'] is None else [x.item() for x in res['pos'].flatten()],
      'vel': [] if res['vel'] is None else [x.item() for x in res['vel'].flatten()],
      'acc': [] if res['acc'] is None else [x.item() for x in res['acc'].flatten()],
    }
    return d

  
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
          ('common', EphemerisCommonContentDepB._static_dtype()),
          ('pos', ('f8', (3,))),
          ('vel', ('f8', (3,))),
          ('acc', ('f8', (3,))),
          ('a_gf0', 'f8'),
          ('a_gf1', 'f8'),
        ])

    t = getattr(cls, 'static_dtype0', None)
    if not t:
      t = np.dtype([
          ('common', EphemerisCommonContentDepB._static_dtype()),
          ('pos', ('f8', (3,))),
          ('vel', ('f8', (3,))),
          ('acc', ('f8', (3,))),
          ('a_gf0', 'f8'),
          ('a_gf1', 'f8'),
        ])
      cls.static_dtype0 = t
    return t

  @classmethod
  def _dynamic_dtype(cls):
    t = getattr(cls, 'dynamic_dtype', None)
    if not t:    
      t = np.dtype([('pos', 'f8'),])
      cls.dynamic_dtype = t
    return t

  @staticmethod
  def _unpack_members(res, element=False):
    d = {
      'common': EphemerisCommonContentDepB._unpack_members(res['common'], element=element),
      'pos': [] if res['pos'] is None else [x.item() for x in res['pos'].flatten()],
      'vel': [] if res['vel'] is None else [x.item() for x in res['vel'].flatten()],
      'acc': [] if res['acc'] is None else [x.item() for x in res['acc'].flatten()],
      'a_gf0': float(res['a_gf0'] if element else res['a_gf0'][0]),
      'a_gf1': float(res['a_gf1'] if element else res['a_gf1'][0]),
    }
    return d

  
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
          ('common', EphemerisCommonContent._static_dtype()),
          ('pos', ('f8', (3,))),
          ('vel', ('f4', (3,))),
          ('acc', ('f4', (3,))),
          ('a_gf0', 'f4'),
          ('a_gf1', 'f4'),
        ])

    t = getattr(cls, 'static_dtype0', None)
    if not t:
      t = np.dtype([
          ('common', EphemerisCommonContent._static_dtype()),
          ('pos', ('f8', (3,))),
          ('vel', ('f4', (3,))),
          ('acc', ('f4', (3,))),
          ('a_gf0', 'f4'),
          ('a_gf1', 'f4'),
        ])
      cls.static_dtype0 = t
    return t

  @classmethod
  def _dynamic_dtype(cls):
    t = getattr(cls, 'dynamic_dtype', None)
    if not t:    
      t = np.dtype([('pos', 'f8'),])
      cls.dynamic_dtype = t
    return t

  @staticmethod
  def _unpack_members(res, element=False):
    d = {
      'common': EphemerisCommonContent._unpack_members(res['common'], element=element),
      'pos': [] if res['pos'] is None else [x.item() for x in res['pos'].flatten()],
      'vel': [] if res['vel'] is None else [x.item() for x in res['vel'].flatten()],
      'acc': [] if res['acc'] is None else [x.item() for x in res['acc'].flatten()],
      'a_gf0': float(res['a_gf0'] if element else res['a_gf0'][0]),
      'a_gf1': float(res['a_gf1'] if element else res['a_gf1'][0]),
    }
    return d

  
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
          ('common', EphemerisCommonContentDepB._static_dtype()),
          ('gamma', 'f8'),
          ('tau', 'f8'),
          ('pos', ('f8', (3,))),
          ('vel', ('f8', (3,))),
          ('acc', ('f8', (3,))),
        ])

    t = getattr(cls, 'static_dtype0', None)
    if not t:
      t = np.dtype([
          ('common', EphemerisCommonContentDepB._static_dtype()),
          ('gamma', 'f8'),
          ('tau', 'f8'),
          ('pos', ('f8', (3,))),
          ('vel', ('f8', (3,))),
          ('acc', ('f8', (3,))),
        ])
      cls.static_dtype0 = t
    return t

  @classmethod
  def _dynamic_dtype(cls):
    t = getattr(cls, 'dynamic_dtype', None)
    if not t:    
      t = np.dtype([('pos', 'f8'),])
      cls.dynamic_dtype = t
    return t

  @staticmethod
  def _unpack_members(res, element=False):
    d = {
      'common': EphemerisCommonContentDepB._unpack_members(res['common'], element=element),
      'gamma': float(res['gamma'] if element else res['gamma'][0]),
      'tau': float(res['tau'] if element else res['tau'][0]),
      'pos': [] if res['pos'] is None else [x.item() for x in res['pos'].flatten()],
      'vel': [] if res['vel'] is None else [x.item() for x in res['vel'].flatten()],
      'acc': [] if res['acc'] is None else [x.item() for x in res['acc'].flatten()],
    }
    return d

  
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
          ('common', EphemerisCommonContentDepB._static_dtype()),
          ('gamma', 'f8'),
          ('tau', 'f8'),
          ('d_tau', 'f8'),
          ('pos', ('f8', (3,))),
          ('vel', ('f8', (3,))),
          ('acc', ('f8', (3,))),
          ('fcn', 'u1'),
        ])

    t = getattr(cls, 'static_dtype0', None)
    if not t:
      t = np.dtype([
          ('common', EphemerisCommonContentDepB._static_dtype()),
          ('gamma', 'f8'),
          ('tau', 'f8'),
          ('d_tau', 'f8'),
          ('pos', ('f8', (3,))),
          ('vel', ('f8', (3,))),
          ('acc', ('f8', (3,))),
          ('fcn', 'u1'),
        ])
      cls.static_dtype0 = t
    return t

  @classmethod
  def _dynamic_dtype(cls):
    t = getattr(cls, 'dynamic_dtype', None)
    if not t:    
      t = np.dtype([('pos', 'f8'),])
      cls.dynamic_dtype = t
    return t

  @staticmethod
  def _unpack_members(res, element=False):
    d = {
      'common': EphemerisCommonContentDepB._unpack_members(res['common'], element=element),
      'gamma': float(res['gamma'] if element else res['gamma'][0]),
      'tau': float(res['tau'] if element else res['tau'][0]),
      'd_tau': float(res['d_tau'] if element else res['d_tau'][0]),
      'pos': [] if res['pos'] is None else [x.item() for x in res['pos'].flatten()],
      'vel': [] if res['vel'] is None else [x.item() for x in res['vel'].flatten()],
      'acc': [] if res['acc'] is None else [x.item() for x in res['acc'].flatten()],
      'fcn': int(res['fcn'] if element else res['fcn'][0]),
    }
    return d

  
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
          ('common', EphemerisCommonContentDepB._static_dtype()),
          ('gamma', 'f8'),
          ('tau', 'f8'),
          ('d_tau', 'f8'),
          ('pos', ('f8', (3,))),
          ('vel', ('f8', (3,))),
          ('acc', ('f8', (3,))),
          ('fcn', 'u1'),
          ('iod', 'u1'),
        ])

    t = getattr(cls, 'static_dtype0', None)
    if not t:
      t = np.dtype([
          ('common', EphemerisCommonContentDepB._static_dtype()),
          ('gamma', 'f8'),
          ('tau', 'f8'),
          ('d_tau', 'f8'),
          ('pos', ('f8', (3,))),
          ('vel', ('f8', (3,))),
          ('acc', ('f8', (3,))),
          ('fcn', 'u1'),
          ('iod', 'u1'),
        ])
      cls.static_dtype0 = t
    return t

  @classmethod
  def _dynamic_dtype(cls):
    t = getattr(cls, 'dynamic_dtype', None)
    if not t:    
      t = np.dtype([('pos', 'f8'),])
      cls.dynamic_dtype = t
    return t

  @staticmethod
  def _unpack_members(res, element=False):
    d = {
      'common': EphemerisCommonContentDepB._unpack_members(res['common'], element=element),
      'gamma': float(res['gamma'] if element else res['gamma'][0]),
      'tau': float(res['tau'] if element else res['tau'][0]),
      'd_tau': float(res['d_tau'] if element else res['d_tau'][0]),
      'pos': [] if res['pos'] is None else [x.item() for x in res['pos'].flatten()],
      'vel': [] if res['vel'] is None else [x.item() for x in res['vel'].flatten()],
      'acc': [] if res['acc'] is None else [x.item() for x in res['acc'].flatten()],
      'fcn': int(res['fcn'] if element else res['fcn'][0]),
      'iod': int(res['iod'] if element else res['iod'][0]),
    }
    return d

  
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
          ('common', EphemerisCommonContent._static_dtype()),
          ('gamma', 'f4'),
          ('tau', 'f4'),
          ('d_tau', 'f4'),
          ('pos', ('f8', (3,))),
          ('vel', ('f8', (3,))),
          ('acc', ('f4', (3,))),
          ('fcn', 'u1'),
          ('iod', 'u1'),
        ])

    t = getattr(cls, 'static_dtype0', None)
    if not t:
      t = np.dtype([
          ('common', EphemerisCommonContent._static_dtype()),
          ('gamma', 'f4'),
          ('tau', 'f4'),
          ('d_tau', 'f4'),
          ('pos', ('f8', (3,))),
          ('vel', ('f8', (3,))),
          ('acc', ('f4', (3,))),
          ('fcn', 'u1'),
          ('iod', 'u1'),
        ])
      cls.static_dtype0 = t
    return t

  @classmethod
  def _dynamic_dtype(cls):
    t = getattr(cls, 'dynamic_dtype', None)
    if not t:    
      t = np.dtype([('pos', 'f8'),])
      cls.dynamic_dtype = t
    return t

  @staticmethod
  def _unpack_members(res, element=False):
    d = {
      'common': EphemerisCommonContent._unpack_members(res['common'], element=element),
      'gamma': float(res['gamma'] if element else res['gamma'][0]),
      'tau': float(res['tau'] if element else res['tau'][0]),
      'd_tau': float(res['d_tau'] if element else res['d_tau'][0]),
      'pos': [] if res['pos'] is None else [x.item() for x in res['pos'].flatten()],
      'vel': [] if res['vel'] is None else [x.item() for x in res['vel'].flatten()],
      'acc': [] if res['acc'] is None else [x.item() for x in res['acc'].flatten()],
      'fcn': int(res['fcn'] if element else res['fcn'][0]),
      'iod': int(res['iod'] if element else res['iod'][0]),
    }
    return d

  
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
          ('tgd', 'f8'),
          ('c_rs', 'f8'),
          ('c_rc', 'f8'),
          ('c_uc', 'f8'),
          ('c_us', 'f8'),
          ('c_ic', 'f8'),
          ('c_is', 'f8'),
          ('dn', 'f8'),
          ('m0', 'f8'),
          ('ecc', 'f8'),
          ('sqrta', 'f8'),
          ('omega0', 'f8'),
          ('omegadot', 'f8'),
          ('w', 'f8'),
          ('inc', 'f8'),
          ('inc_dot', 'f8'),
          ('af0', 'f8'),
          ('af1', 'f8'),
          ('af2', 'f8'),
          ('toe_tow', 'f8'),
          ('toe_wn', 'u2'),
          ('toc_tow', 'f8'),
          ('toc_wn', 'u2'),
          ('valid', 'u1'),
          ('healthy', 'u1'),
          ('sid', GnssSignalDep._static_dtype()),
          ('iode', 'u1'),
          ('iodc', 'u2'),
          ('reserved', 'u4'),
        ])

    t = getattr(cls, 'static_dtype0', None)
    if not t:
      t = np.dtype([
          ('tgd', 'f8'),
          ('c_rs', 'f8'),
          ('c_rc', 'f8'),
          ('c_uc', 'f8'),
          ('c_us', 'f8'),
          ('c_ic', 'f8'),
          ('c_is', 'f8'),
          ('dn', 'f8'),
          ('m0', 'f8'),
          ('ecc', 'f8'),
          ('sqrta', 'f8'),
          ('omega0', 'f8'),
          ('omegadot', 'f8'),
          ('w', 'f8'),
          ('inc', 'f8'),
          ('inc_dot', 'f8'),
          ('af0', 'f8'),
          ('af1', 'f8'),
          ('af2', 'f8'),
          ('toe_tow', 'f8'),
          ('toe_wn', 'u2'),
          ('toc_tow', 'f8'),
          ('toc_wn', 'u2'),
          ('valid', 'u1'),
          ('healthy', 'u1'),
          ('sid', GnssSignalDep._static_dtype()),
          ('iode', 'u1'),
          ('iodc', 'u2'),
          ('reserved', 'u4'),
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
      'tgd': float(res['tgd'] if element else res['tgd'][0]),
      'c_rs': float(res['c_rs'] if element else res['c_rs'][0]),
      'c_rc': float(res['c_rc'] if element else res['c_rc'][0]),
      'c_uc': float(res['c_uc'] if element else res['c_uc'][0]),
      'c_us': float(res['c_us'] if element else res['c_us'][0]),
      'c_ic': float(res['c_ic'] if element else res['c_ic'][0]),
      'c_is': float(res['c_is'] if element else res['c_is'][0]),
      'dn': float(res['dn'] if element else res['dn'][0]),
      'm0': float(res['m0'] if element else res['m0'][0]),
      'ecc': float(res['ecc'] if element else res['ecc'][0]),
      'sqrta': float(res['sqrta'] if element else res['sqrta'][0]),
      'omega0': float(res['omega0'] if element else res['omega0'][0]),
      'omegadot': float(res['omegadot'] if element else res['omegadot'][0]),
      'w': float(res['w'] if element else res['w'][0]),
      'inc': float(res['inc'] if element else res['inc'][0]),
      'inc_dot': float(res['inc_dot'] if element else res['inc_dot'][0]),
      'af0': float(res['af0'] if element else res['af0'][0]),
      'af1': float(res['af1'] if element else res['af1'][0]),
      'af2': float(res['af2'] if element else res['af2'][0]),
      'toe_tow': float(res['toe_tow'] if element else res['toe_tow'][0]),
      'toe_wn': int(res['toe_wn'] if element else res['toe_wn'][0]),
      'toc_tow': float(res['toc_tow'] if element else res['toc_tow'][0]),
      'toc_wn': int(res['toc_wn'] if element else res['toc_wn'][0]),
      'valid': int(res['valid'] if element else res['valid'][0]),
      'healthy': int(res['healthy'] if element else res['healthy'][0]),
      'sid': GnssSignalDep._unpack_members(res['sid'], element=element),
      'iode': int(res['iode'] if element else res['iode'][0]),
      'iodc': int(res['iodc'] if element else res['iodc'][0]),
      'reserved': int(res['reserved'] if element else res['reserved'][0]),
    }
    return d

  
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
          ('tgd', 'f8'),
          ('c_rs', 'f8'),
          ('c_rc', 'f8'),
          ('c_uc', 'f8'),
          ('c_us', 'f8'),
          ('c_ic', 'f8'),
          ('c_is', 'f8'),
          ('dn', 'f8'),
          ('m0', 'f8'),
          ('ecc', 'f8'),
          ('sqrta', 'f8'),
          ('omega0', 'f8'),
          ('omegadot', 'f8'),
          ('w', 'f8'),
          ('inc', 'f8'),
          ('inc_dot', 'f8'),
          ('af0', 'f8'),
          ('af1', 'f8'),
          ('af2', 'f8'),
          ('toe_tow', 'f8'),
          ('toe_wn', 'u2'),
          ('toc_tow', 'f8'),
          ('toc_wn', 'u2'),
          ('valid', 'u1'),
          ('healthy', 'u1'),
          ('prn', 'u1'),
        ])

    t = getattr(cls, 'static_dtype0', None)
    if not t:
      t = np.dtype([
          ('tgd', 'f8'),
          ('c_rs', 'f8'),
          ('c_rc', 'f8'),
          ('c_uc', 'f8'),
          ('c_us', 'f8'),
          ('c_ic', 'f8'),
          ('c_is', 'f8'),
          ('dn', 'f8'),
          ('m0', 'f8'),
          ('ecc', 'f8'),
          ('sqrta', 'f8'),
          ('omega0', 'f8'),
          ('omegadot', 'f8'),
          ('w', 'f8'),
          ('inc', 'f8'),
          ('inc_dot', 'f8'),
          ('af0', 'f8'),
          ('af1', 'f8'),
          ('af2', 'f8'),
          ('toe_tow', 'f8'),
          ('toe_wn', 'u2'),
          ('toc_tow', 'f8'),
          ('toc_wn', 'u2'),
          ('valid', 'u1'),
          ('healthy', 'u1'),
          ('prn', 'u1'),
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
      'tgd': float(res['tgd'] if element else res['tgd'][0]),
      'c_rs': float(res['c_rs'] if element else res['c_rs'][0]),
      'c_rc': float(res['c_rc'] if element else res['c_rc'][0]),
      'c_uc': float(res['c_uc'] if element else res['c_uc'][0]),
      'c_us': float(res['c_us'] if element else res['c_us'][0]),
      'c_ic': float(res['c_ic'] if element else res['c_ic'][0]),
      'c_is': float(res['c_is'] if element else res['c_is'][0]),
      'dn': float(res['dn'] if element else res['dn'][0]),
      'm0': float(res['m0'] if element else res['m0'][0]),
      'ecc': float(res['ecc'] if element else res['ecc'][0]),
      'sqrta': float(res['sqrta'] if element else res['sqrta'][0]),
      'omega0': float(res['omega0'] if element else res['omega0'][0]),
      'omegadot': float(res['omegadot'] if element else res['omegadot'][0]),
      'w': float(res['w'] if element else res['w'][0]),
      'inc': float(res['inc'] if element else res['inc'][0]),
      'inc_dot': float(res['inc_dot'] if element else res['inc_dot'][0]),
      'af0': float(res['af0'] if element else res['af0'][0]),
      'af1': float(res['af1'] if element else res['af1'][0]),
      'af2': float(res['af2'] if element else res['af2'][0]),
      'toe_tow': float(res['toe_tow'] if element else res['toe_tow'][0]),
      'toe_wn': int(res['toe_wn'] if element else res['toe_wn'][0]),
      'toc_tow': float(res['toc_tow'] if element else res['toc_tow'][0]),
      'toc_wn': int(res['toc_wn'] if element else res['toc_wn'][0]),
      'valid': int(res['valid'] if element else res['valid'][0]),
      'healthy': int(res['healthy'] if element else res['healthy'][0]),
      'prn': int(res['prn'] if element else res['prn'][0]),
    }
    return d

  
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
          ('tgd', 'f8'),
          ('c_rs', 'f8'),
          ('c_rc', 'f8'),
          ('c_uc', 'f8'),
          ('c_us', 'f8'),
          ('c_ic', 'f8'),
          ('c_is', 'f8'),
          ('dn', 'f8'),
          ('m0', 'f8'),
          ('ecc', 'f8'),
          ('sqrta', 'f8'),
          ('omega0', 'f8'),
          ('omegadot', 'f8'),
          ('w', 'f8'),
          ('inc', 'f8'),
          ('inc_dot', 'f8'),
          ('af0', 'f8'),
          ('af1', 'f8'),
          ('af2', 'f8'),
          ('toe_tow', 'f8'),
          ('toe_wn', 'u2'),
          ('toc_tow', 'f8'),
          ('toc_wn', 'u2'),
          ('valid', 'u1'),
          ('healthy', 'u1'),
          ('prn', 'u1'),
          ('iode', 'u1'),
        ])

    t = getattr(cls, 'static_dtype0', None)
    if not t:
      t = np.dtype([
          ('tgd', 'f8'),
          ('c_rs', 'f8'),
          ('c_rc', 'f8'),
          ('c_uc', 'f8'),
          ('c_us', 'f8'),
          ('c_ic', 'f8'),
          ('c_is', 'f8'),
          ('dn', 'f8'),
          ('m0', 'f8'),
          ('ecc', 'f8'),
          ('sqrta', 'f8'),
          ('omega0', 'f8'),
          ('omegadot', 'f8'),
          ('w', 'f8'),
          ('inc', 'f8'),
          ('inc_dot', 'f8'),
          ('af0', 'f8'),
          ('af1', 'f8'),
          ('af2', 'f8'),
          ('toe_tow', 'f8'),
          ('toe_wn', 'u2'),
          ('toc_tow', 'f8'),
          ('toc_wn', 'u2'),
          ('valid', 'u1'),
          ('healthy', 'u1'),
          ('prn', 'u1'),
          ('iode', 'u1'),
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
      'tgd': float(res['tgd'] if element else res['tgd'][0]),
      'c_rs': float(res['c_rs'] if element else res['c_rs'][0]),
      'c_rc': float(res['c_rc'] if element else res['c_rc'][0]),
      'c_uc': float(res['c_uc'] if element else res['c_uc'][0]),
      'c_us': float(res['c_us'] if element else res['c_us'][0]),
      'c_ic': float(res['c_ic'] if element else res['c_ic'][0]),
      'c_is': float(res['c_is'] if element else res['c_is'][0]),
      'dn': float(res['dn'] if element else res['dn'][0]),
      'm0': float(res['m0'] if element else res['m0'][0]),
      'ecc': float(res['ecc'] if element else res['ecc'][0]),
      'sqrta': float(res['sqrta'] if element else res['sqrta'][0]),
      'omega0': float(res['omega0'] if element else res['omega0'][0]),
      'omegadot': float(res['omegadot'] if element else res['omegadot'][0]),
      'w': float(res['w'] if element else res['w'][0]),
      'inc': float(res['inc'] if element else res['inc'][0]),
      'inc_dot': float(res['inc_dot'] if element else res['inc_dot'][0]),
      'af0': float(res['af0'] if element else res['af0'][0]),
      'af1': float(res['af1'] if element else res['af1'][0]),
      'af2': float(res['af2'] if element else res['af2'][0]),
      'toe_tow': float(res['toe_tow'] if element else res['toe_tow'][0]),
      'toe_wn': int(res['toe_wn'] if element else res['toe_wn'][0]),
      'toc_tow': float(res['toc_tow'] if element else res['toc_tow'][0]),
      'toc_wn': int(res['toc_wn'] if element else res['toc_wn'][0]),
      'valid': int(res['valid'] if element else res['valid'][0]),
      'healthy': int(res['healthy'] if element else res['healthy'][0]),
      'prn': int(res['prn'] if element else res['prn'][0]),
      'iode': int(res['iode'] if element else res['iode'][0]),
    }
    return d

  
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
          ('tgd', 'f8'),
          ('c_rs', 'f8'),
          ('c_rc', 'f8'),
          ('c_uc', 'f8'),
          ('c_us', 'f8'),
          ('c_ic', 'f8'),
          ('c_is', 'f8'),
          ('dn', 'f8'),
          ('m0', 'f8'),
          ('ecc', 'f8'),
          ('sqrta', 'f8'),
          ('omega0', 'f8'),
          ('omegadot', 'f8'),
          ('w', 'f8'),
          ('inc', 'f8'),
          ('inc_dot', 'f8'),
          ('af0', 'f8'),
          ('af1', 'f8'),
          ('af2', 'f8'),
          ('toe_tow', 'f8'),
          ('toe_wn', 'u2'),
          ('toc_tow', 'f8'),
          ('toc_wn', 'u2'),
          ('valid', 'u1'),
          ('healthy', 'u1'),
          ('sid', GnssSignalDep._static_dtype()),
          ('iode', 'u1'),
          ('iodc', 'u2'),
          ('reserved', 'u4'),
        ])

    t = getattr(cls, 'static_dtype0', None)
    if not t:
      t = np.dtype([
          ('tgd', 'f8'),
          ('c_rs', 'f8'),
          ('c_rc', 'f8'),
          ('c_uc', 'f8'),
          ('c_us', 'f8'),
          ('c_ic', 'f8'),
          ('c_is', 'f8'),
          ('dn', 'f8'),
          ('m0', 'f8'),
          ('ecc', 'f8'),
          ('sqrta', 'f8'),
          ('omega0', 'f8'),
          ('omegadot', 'f8'),
          ('w', 'f8'),
          ('inc', 'f8'),
          ('inc_dot', 'f8'),
          ('af0', 'f8'),
          ('af1', 'f8'),
          ('af2', 'f8'),
          ('toe_tow', 'f8'),
          ('toe_wn', 'u2'),
          ('toc_tow', 'f8'),
          ('toc_wn', 'u2'),
          ('valid', 'u1'),
          ('healthy', 'u1'),
          ('sid', GnssSignalDep._static_dtype()),
          ('iode', 'u1'),
          ('iodc', 'u2'),
          ('reserved', 'u4'),
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
      'tgd': float(res['tgd'] if element else res['tgd'][0]),
      'c_rs': float(res['c_rs'] if element else res['c_rs'][0]),
      'c_rc': float(res['c_rc'] if element else res['c_rc'][0]),
      'c_uc': float(res['c_uc'] if element else res['c_uc'][0]),
      'c_us': float(res['c_us'] if element else res['c_us'][0]),
      'c_ic': float(res['c_ic'] if element else res['c_ic'][0]),
      'c_is': float(res['c_is'] if element else res['c_is'][0]),
      'dn': float(res['dn'] if element else res['dn'][0]),
      'm0': float(res['m0'] if element else res['m0'][0]),
      'ecc': float(res['ecc'] if element else res['ecc'][0]),
      'sqrta': float(res['sqrta'] if element else res['sqrta'][0]),
      'omega0': float(res['omega0'] if element else res['omega0'][0]),
      'omegadot': float(res['omegadot'] if element else res['omegadot'][0]),
      'w': float(res['w'] if element else res['w'][0]),
      'inc': float(res['inc'] if element else res['inc'][0]),
      'inc_dot': float(res['inc_dot'] if element else res['inc_dot'][0]),
      'af0': float(res['af0'] if element else res['af0'][0]),
      'af1': float(res['af1'] if element else res['af1'][0]),
      'af2': float(res['af2'] if element else res['af2'][0]),
      'toe_tow': float(res['toe_tow'] if element else res['toe_tow'][0]),
      'toe_wn': int(res['toe_wn'] if element else res['toe_wn'][0]),
      'toc_tow': float(res['toc_tow'] if element else res['toc_tow'][0]),
      'toc_wn': int(res['toc_wn'] if element else res['toc_wn'][0]),
      'valid': int(res['valid'] if element else res['valid'][0]),
      'healthy': int(res['healthy'] if element else res['healthy'][0]),
      'sid': GnssSignalDep._unpack_members(res['sid'], element=element),
      'iode': int(res['iode'] if element else res['iode'][0]),
      'iodc': int(res['iodc'] if element else res['iodc'][0]),
      'reserved': int(res['reserved'] if element else res['reserved'][0]),
    }
    return d

  
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
          ('t', GPSTimeDep._static_dtype()),
          ('n_obs', 'u1'),
        ])

    t = getattr(cls, 'static_dtype0', None)
    if not t:
      t = np.dtype([
          ('t', GPSTimeDep._static_dtype()),
          ('n_obs', 'u1'),
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
      't': GPSTimeDep._unpack_members(res['t'], element=element),
      'n_obs': int(res['n_obs'] if element else res['n_obs'][0]),
    }
    return d

  
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
          ('i', 'i4'),
          ('f', 'u1'),
        ])

    t = getattr(cls, 'static_dtype0', None)
    if not t:
      t = np.dtype([
          ('i', 'i4'),
          ('f', 'u1'),
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
      'i': int(res['i'] if element else res['i'][0]),
      'f': int(res['f'] if element else res['f'][0]),
    }
    return d

  
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
          ('P', 'u4'),
          ('L', CarrierPhaseDepA._static_dtype()),
          ('cn0', 'u1'),
          ('lock', 'u2'),
          ('prn', 'u1'),
        ])

    t = getattr(cls, 'static_dtype0', None)
    if not t:
      t = np.dtype([
          ('P', 'u4'),
          ('L', CarrierPhaseDepA._static_dtype()),
          ('cn0', 'u1'),
          ('lock', 'u2'),
          ('prn', 'u1'),
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
      'P': int(res['P'] if element else res['P'][0]),
      'L': CarrierPhaseDepA._unpack_members(res['L'], element=element),
      'cn0': int(res['cn0'] if element else res['cn0'][0]),
      'lock': int(res['lock'] if element else res['lock'][0]),
      'prn': int(res['prn'] if element else res['prn'][0]),
    }
    return d

  
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
          ('P', 'u4'),
          ('L', CarrierPhaseDepA._static_dtype()),
          ('cn0', 'u1'),
          ('lock', 'u2'),
          ('sid', GnssSignalDep._static_dtype()),
        ])

    t = getattr(cls, 'static_dtype0', None)
    if not t:
      t = np.dtype([
          ('P', 'u4'),
          ('L', CarrierPhaseDepA._static_dtype()),
          ('cn0', 'u1'),
          ('lock', 'u2'),
          ('sid', GnssSignalDep._static_dtype()),
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
      'P': int(res['P'] if element else res['P'][0]),
      'L': CarrierPhaseDepA._unpack_members(res['L'], element=element),
      'cn0': int(res['cn0'] if element else res['cn0'][0]),
      'lock': int(res['lock'] if element else res['lock'][0]),
      'sid': GnssSignalDep._unpack_members(res['sid'], element=element),
    }
    return d

  
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
          ('P', 'u4'),
          ('L', CarrierPhase._static_dtype()),
          ('cn0', 'u1'),
          ('lock', 'u2'),
          ('sid', GnssSignalDep._static_dtype()),
        ])

    t = getattr(cls, 'static_dtype0', None)
    if not t:
      t = np.dtype([
          ('P', 'u4'),
          ('L', CarrierPhase._static_dtype()),
          ('cn0', 'u1'),
          ('lock', 'u2'),
          ('sid', GnssSignalDep._static_dtype()),
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
      'P': int(res['P'] if element else res['P'][0]),
      'L': CarrierPhase._unpack_members(res['L'], element=element),
      'cn0': int(res['cn0'] if element else res['cn0'][0]),
      'lock': int(res['lock'] if element else res['lock'][0]),
      'sid': GnssSignalDep._unpack_members(res['sid'], element=element),
    }
    return d

  
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
          ('header', ObservationHeaderDep._static_dtype()),
          ('obs', (PackedObsContentDepA._static_dtype(), (count,))),
        ])

    t = getattr(cls, 'static_dtype0', None)
    if not t:
      t = np.dtype([
          ('header', ObservationHeaderDep._static_dtype()),
          ('obs', (PackedObsContentDepA._static_dtype(), (count,))),
        ])
      cls.static_dtype0 = t
    return t

  @classmethod
  def _dynamic_dtype(cls):
    t = getattr(cls, 'dynamic_dtype', None)
    if not t:    
      t = np.dtype([('obs', PackedObsContentDepA._static_dtype()),])
      cls.dynamic_dtype = t
    return t

  @staticmethod
  def _unpack_members(res, element=False):
    d = {
      'header': ObservationHeaderDep._unpack_members(res['header'], element=element),
      'obs': [] if res['obs'] is None else [PackedObsContentDepA._unpack_members(x, element=True) for x in res['obs'].flatten()],
    }
    return d

  
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
          ('header', ObservationHeaderDep._static_dtype()),
          ('obs', (PackedObsContentDepB._static_dtype(), (count,))),
        ])

    t = getattr(cls, 'static_dtype0', None)
    if not t:
      t = np.dtype([
          ('header', ObservationHeaderDep._static_dtype()),
          ('obs', (PackedObsContentDepB._static_dtype(), (count,))),
        ])
      cls.static_dtype0 = t
    return t

  @classmethod
  def _dynamic_dtype(cls):
    t = getattr(cls, 'dynamic_dtype', None)
    if not t:    
      t = np.dtype([('obs', PackedObsContentDepB._static_dtype()),])
      cls.dynamic_dtype = t
    return t

  @staticmethod
  def _unpack_members(res, element=False):
    d = {
      'header': ObservationHeaderDep._unpack_members(res['header'], element=element),
      'obs': [] if res['obs'] is None else [PackedObsContentDepB._unpack_members(x, element=True) for x in res['obs'].flatten()],
    }
    return d

  
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
          ('header', ObservationHeaderDep._static_dtype()),
          ('obs', (PackedObsContentDepC._static_dtype(), (count,))),
        ])

    t = getattr(cls, 'static_dtype0', None)
    if not t:
      t = np.dtype([
          ('header', ObservationHeaderDep._static_dtype()),
          ('obs', (PackedObsContentDepC._static_dtype(), (count,))),
        ])
      cls.static_dtype0 = t
    return t

  @classmethod
  def _dynamic_dtype(cls):
    t = getattr(cls, 'dynamic_dtype', None)
    if not t:    
      t = np.dtype([('obs', PackedObsContentDepC._static_dtype()),])
      cls.dynamic_dtype = t
    return t

  @staticmethod
  def _unpack_members(res, element=False):
    d = {
      'header': ObservationHeaderDep._unpack_members(res['header'], element=element),
      'obs': [] if res['obs'] is None else [PackedObsContentDepC._unpack_members(x, element=True) for x in res['obs'].flatten()],
    }
    return d

  
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
          ('t_nmct', GPSTimeSec._static_dtype()),
          ('a0', 'f8'),
          ('a1', 'f8'),
          ('a2', 'f8'),
          ('a3', 'f8'),
          ('b0', 'f8'),
          ('b1', 'f8'),
          ('b2', 'f8'),
          ('b3', 'f8'),
        ])

    t = getattr(cls, 'static_dtype0', None)
    if not t:
      t = np.dtype([
          ('t_nmct', GPSTimeSec._static_dtype()),
          ('a0', 'f8'),
          ('a1', 'f8'),
          ('a2', 'f8'),
          ('a3', 'f8'),
          ('b0', 'f8'),
          ('b1', 'f8'),
          ('b2', 'f8'),
          ('b3', 'f8'),
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
      't_nmct': GPSTimeSec._unpack_members(res['t_nmct'], element=element),
      'a0': float(res['a0'] if element else res['a0'][0]),
      'a1': float(res['a1'] if element else res['a1'][0]),
      'a2': float(res['a2'] if element else res['a2'][0]),
      'a3': float(res['a3'] if element else res['a3'][0]),
      'b0': float(res['b0'] if element else res['b0'][0]),
      'b1': float(res['b1'] if element else res['b1'][0]),
      'b2': float(res['b2'] if element else res['b2'][0]),
      'b3': float(res['b3'] if element else res['b3'][0]),
    }
    return d

  
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
          ('t_nmct', GPSTimeSec._static_dtype()),
          ('l2c_mask', 'u4'),
        ])

    t = getattr(cls, 'static_dtype0', None)
    if not t:
      t = np.dtype([
          ('t_nmct', GPSTimeSec._static_dtype()),
          ('l2c_mask', 'u4'),
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
      't_nmct': GPSTimeSec._unpack_members(res['t_nmct'], element=element),
      'l2c_mask': int(res['l2c_mask'] if element else res['l2c_mask'][0]),
    }
    return d

  
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
          ('gps_active', 'u8'),
          ('gps_l2c', 'u8'),
          ('gps_l5', 'u8'),
          ('glo_active', 'u4'),
          ('glo_l2of', 'u4'),
          ('glo_l3', 'u4'),
          ('sbas_active', 'u8'),
          ('sbas_l5', 'u8'),
          ('bds_active', 'u8'),
          ('bds_d2nav', 'u8'),
          ('bds_b2', 'u8'),
          ('bds_b2a', 'u8'),
          ('qzss_active', 'u4'),
          ('gal_active', 'u8'),
          ('gal_e5', 'u8'),
        ])

    t = getattr(cls, 'static_dtype0', None)
    if not t:
      t = np.dtype([
          ('gps_active', 'u8'),
          ('gps_l2c', 'u8'),
          ('gps_l5', 'u8'),
          ('glo_active', 'u4'),
          ('glo_l2of', 'u4'),
          ('glo_l3', 'u4'),
          ('sbas_active', 'u8'),
          ('sbas_l5', 'u8'),
          ('bds_active', 'u8'),
          ('bds_d2nav', 'u8'),
          ('bds_b2', 'u8'),
          ('bds_b2a', 'u8'),
          ('qzss_active', 'u4'),
          ('gal_active', 'u8'),
          ('gal_e5', 'u8'),
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
      'gps_active': int(res['gps_active'] if element else res['gps_active'][0]),
      'gps_l2c': int(res['gps_l2c'] if element else res['gps_l2c'][0]),
      'gps_l5': int(res['gps_l5'] if element else res['gps_l5'][0]),
      'glo_active': int(res['glo_active'] if element else res['glo_active'][0]),
      'glo_l2of': int(res['glo_l2of'] if element else res['glo_l2of'][0]),
      'glo_l3': int(res['glo_l3'] if element else res['glo_l3'][0]),
      'sbas_active': int(res['sbas_active'] if element else res['sbas_active'][0]),
      'sbas_l5': int(res['sbas_l5'] if element else res['sbas_l5'][0]),
      'bds_active': int(res['bds_active'] if element else res['bds_active'][0]),
      'bds_d2nav': int(res['bds_d2nav'] if element else res['bds_d2nav'][0]),
      'bds_b2': int(res['bds_b2'] if element else res['bds_b2'][0]),
      'bds_b2a': int(res['bds_b2a'] if element else res['bds_b2a'][0]),
      'qzss_active': int(res['qzss_active'] if element else res['qzss_active'][0]),
      'gal_active': int(res['gal_active'] if element else res['gal_active'][0]),
      'gal_e5': int(res['gal_e5'] if element else res['gal_e5'][0]),
    }
    return d

  
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
          ('t_nmct', GPSTimeSec._static_dtype()),
          ('gc', GnssCapb._static_dtype()),
        ])

    t = getattr(cls, 'static_dtype0', None)
    if not t:
      t = np.dtype([
          ('t_nmct', GPSTimeSec._static_dtype()),
          ('gc', GnssCapb._static_dtype()),
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
      't_nmct': GPSTimeSec._unpack_members(res['t_nmct'], element=element),
      'gc': GnssCapb._unpack_members(res['gc'], element=element),
    }
    return d

  
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
          ('t_op', GPSTimeDep._static_dtype()),
          ('prn', 'u1'),
          ('valid', 'u1'),
          ('tgd', 'i2'),
          ('isc_l1ca', 'i2'),
          ('isc_l2c', 'i2'),
        ])

    t = getattr(cls, 'static_dtype0', None)
    if not t:
      t = np.dtype([
          ('t_op', GPSTimeDep._static_dtype()),
          ('prn', 'u1'),
          ('valid', 'u1'),
          ('tgd', 'i2'),
          ('isc_l1ca', 'i2'),
          ('isc_l2c', 'i2'),
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
      't_op': GPSTimeDep._unpack_members(res['t_op'], element=element),
      'prn': int(res['prn'] if element else res['prn'][0]),
      'valid': int(res['valid'] if element else res['valid'][0]),
      'tgd': int(res['tgd'] if element else res['tgd'][0]),
      'isc_l1ca': int(res['isc_l1ca'] if element else res['isc_l1ca'][0]),
      'isc_l2c': int(res['isc_l2c'] if element else res['isc_l2c'][0]),
    }
    return d

  
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
          ('t_op', GPSTimeSec._static_dtype()),
          ('sid', GnssSignalDep._static_dtype()),
          ('valid', 'u1'),
          ('tgd', 'i2'),
          ('isc_l1ca', 'i2'),
          ('isc_l2c', 'i2'),
        ])

    t = getattr(cls, 'static_dtype0', None)
    if not t:
      t = np.dtype([
          ('t_op', GPSTimeSec._static_dtype()),
          ('sid', GnssSignalDep._static_dtype()),
          ('valid', 'u1'),
          ('tgd', 'i2'),
          ('isc_l1ca', 'i2'),
          ('isc_l2c', 'i2'),
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
      't_op': GPSTimeSec._unpack_members(res['t_op'], element=element),
      'sid': GnssSignalDep._unpack_members(res['sid'], element=element),
      'valid': int(res['valid'] if element else res['valid'][0]),
      'tgd': int(res['tgd'] if element else res['tgd'][0]),
      'isc_l1ca': int(res['isc_l1ca'] if element else res['isc_l1ca'][0]),
      'isc_l2c': int(res['isc_l2c'] if element else res['isc_l2c'][0]),
    }
    return d

  
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
          ('t_op', GPSTimeSec._static_dtype()),
          ('sid', GnssSignal._static_dtype()),
          ('valid', 'u1'),
          ('tgd', 'i2'),
          ('isc_l1ca', 'i2'),
          ('isc_l2c', 'i2'),
        ])

    t = getattr(cls, 'static_dtype0', None)
    if not t:
      t = np.dtype([
          ('t_op', GPSTimeSec._static_dtype()),
          ('sid', GnssSignal._static_dtype()),
          ('valid', 'u1'),
          ('tgd', 'i2'),
          ('isc_l1ca', 'i2'),
          ('isc_l2c', 'i2'),
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
      't_op': GPSTimeSec._unpack_members(res['t_op'], element=element),
      'sid': GnssSignal._unpack_members(res['sid'], element=element),
      'valid': int(res['valid'] if element else res['valid'][0]),
      'tgd': int(res['tgd'] if element else res['tgd'][0]),
      'isc_l1ca': int(res['isc_l1ca'] if element else res['isc_l1ca'][0]),
      'isc_l2c': int(res['isc_l2c'] if element else res['isc_l2c'][0]),
    }
    return d

  
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
          ('sid', GnssSignal._static_dtype()),
          ('toa', GPSTimeSec._static_dtype()),
          ('ura', 'f8'),
          ('fit_interval', 'u4'),
          ('valid', 'u1'),
          ('health_bits', 'u1'),
        ])

    t = getattr(cls, 'static_dtype0', None)
    if not t:
      t = np.dtype([
          ('sid', GnssSignal._static_dtype()),
          ('toa', GPSTimeSec._static_dtype()),
          ('ura', 'f8'),
          ('fit_interval', 'u4'),
          ('valid', 'u1'),
          ('health_bits', 'u1'),
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
      'sid': GnssSignal._unpack_members(res['sid'], element=element),
      'toa': GPSTimeSec._unpack_members(res['toa'], element=element),
      'ura': float(res['ura'] if element else res['ura'][0]),
      'fit_interval': int(res['fit_interval'] if element else res['fit_interval'][0]),
      'valid': int(res['valid'] if element else res['valid'][0]),
      'health_bits': int(res['health_bits'] if element else res['health_bits'][0]),
    }
    return d

  
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
          ('sid', GnssSignalDep._static_dtype()),
          ('toa', GPSTimeSec._static_dtype()),
          ('ura', 'f8'),
          ('fit_interval', 'u4'),
          ('valid', 'u1'),
          ('health_bits', 'u1'),
        ])

    t = getattr(cls, 'static_dtype0', None)
    if not t:
      t = np.dtype([
          ('sid', GnssSignalDep._static_dtype()),
          ('toa', GPSTimeSec._static_dtype()),
          ('ura', 'f8'),
          ('fit_interval', 'u4'),
          ('valid', 'u1'),
          ('health_bits', 'u1'),
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
      'sid': GnssSignalDep._unpack_members(res['sid'], element=element),
      'toa': GPSTimeSec._unpack_members(res['toa'], element=element),
      'ura': float(res['ura'] if element else res['ura'][0]),
      'fit_interval': int(res['fit_interval'] if element else res['fit_interval'][0]),
      'valid': int(res['valid'] if element else res['valid'][0]),
      'health_bits': int(res['health_bits'] if element else res['health_bits'][0]),
    }
    return d

  
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
          ('common', AlmanacCommonContentDep._static_dtype()),
          ('m0', 'f8'),
          ('ecc', 'f8'),
          ('sqrta', 'f8'),
          ('omega0', 'f8'),
          ('omegadot', 'f8'),
          ('w', 'f8'),
          ('inc', 'f8'),
          ('af0', 'f8'),
          ('af1', 'f8'),
        ])

    t = getattr(cls, 'static_dtype0', None)
    if not t:
      t = np.dtype([
          ('common', AlmanacCommonContentDep._static_dtype()),
          ('m0', 'f8'),
          ('ecc', 'f8'),
          ('sqrta', 'f8'),
          ('omega0', 'f8'),
          ('omegadot', 'f8'),
          ('w', 'f8'),
          ('inc', 'f8'),
          ('af0', 'f8'),
          ('af1', 'f8'),
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
      'common': AlmanacCommonContentDep._unpack_members(res['common'], element=element),
      'm0': float(res['m0'] if element else res['m0'][0]),
      'ecc': float(res['ecc'] if element else res['ecc'][0]),
      'sqrta': float(res['sqrta'] if element else res['sqrta'][0]),
      'omega0': float(res['omega0'] if element else res['omega0'][0]),
      'omegadot': float(res['omegadot'] if element else res['omegadot'][0]),
      'w': float(res['w'] if element else res['w'][0]),
      'inc': float(res['inc'] if element else res['inc'][0]),
      'af0': float(res['af0'] if element else res['af0'][0]),
      'af1': float(res['af1'] if element else res['af1'][0]),
    }
    return d

  
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
          ('common', AlmanacCommonContent._static_dtype()),
          ('m0', 'f8'),
          ('ecc', 'f8'),
          ('sqrta', 'f8'),
          ('omega0', 'f8'),
          ('omegadot', 'f8'),
          ('w', 'f8'),
          ('inc', 'f8'),
          ('af0', 'f8'),
          ('af1', 'f8'),
        ])

    t = getattr(cls, 'static_dtype0', None)
    if not t:
      t = np.dtype([
          ('common', AlmanacCommonContent._static_dtype()),
          ('m0', 'f8'),
          ('ecc', 'f8'),
          ('sqrta', 'f8'),
          ('omega0', 'f8'),
          ('omegadot', 'f8'),
          ('w', 'f8'),
          ('inc', 'f8'),
          ('af0', 'f8'),
          ('af1', 'f8'),
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
      'common': AlmanacCommonContent._unpack_members(res['common'], element=element),
      'm0': float(res['m0'] if element else res['m0'][0]),
      'ecc': float(res['ecc'] if element else res['ecc'][0]),
      'sqrta': float(res['sqrta'] if element else res['sqrta'][0]),
      'omega0': float(res['omega0'] if element else res['omega0'][0]),
      'omegadot': float(res['omegadot'] if element else res['omegadot'][0]),
      'w': float(res['w'] if element else res['w'][0]),
      'inc': float(res['inc'] if element else res['inc'][0]),
      'af0': float(res['af0'] if element else res['af0'][0]),
      'af1': float(res['af1'] if element else res['af1'][0]),
    }
    return d

  
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
          ('common', AlmanacCommonContentDep._static_dtype()),
          ('lambda_na', 'f8'),
          ('t_lambda_na', 'f8'),
          ('i', 'f8'),
          ('t', 'f8'),
          ('t_dot', 'f8'),
          ('epsilon', 'f8'),
          ('omega', 'f8'),
        ])

    t = getattr(cls, 'static_dtype0', None)
    if not t:
      t = np.dtype([
          ('common', AlmanacCommonContentDep._static_dtype()),
          ('lambda_na', 'f8'),
          ('t_lambda_na', 'f8'),
          ('i', 'f8'),
          ('t', 'f8'),
          ('t_dot', 'f8'),
          ('epsilon', 'f8'),
          ('omega', 'f8'),
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
      'common': AlmanacCommonContentDep._unpack_members(res['common'], element=element),
      'lambda_na': float(res['lambda_na'] if element else res['lambda_na'][0]),
      't_lambda_na': float(res['t_lambda_na'] if element else res['t_lambda_na'][0]),
      'i': float(res['i'] if element else res['i'][0]),
      't': float(res['t'] if element else res['t'][0]),
      't_dot': float(res['t_dot'] if element else res['t_dot'][0]),
      'epsilon': float(res['epsilon'] if element else res['epsilon'][0]),
      'omega': float(res['omega'] if element else res['omega'][0]),
    }
    return d

  
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
          ('common', AlmanacCommonContent._static_dtype()),
          ('lambda_na', 'f8'),
          ('t_lambda_na', 'f8'),
          ('i', 'f8'),
          ('t', 'f8'),
          ('t_dot', 'f8'),
          ('epsilon', 'f8'),
          ('omega', 'f8'),
        ])

    t = getattr(cls, 'static_dtype0', None)
    if not t:
      t = np.dtype([
          ('common', AlmanacCommonContent._static_dtype()),
          ('lambda_na', 'f8'),
          ('t_lambda_na', 'f8'),
          ('i', 'f8'),
          ('t', 'f8'),
          ('t_dot', 'f8'),
          ('epsilon', 'f8'),
          ('omega', 'f8'),
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
      'common': AlmanacCommonContent._unpack_members(res['common'], element=element),
      'lambda_na': float(res['lambda_na'] if element else res['lambda_na'][0]),
      't_lambda_na': float(res['t_lambda_na'] if element else res['t_lambda_na'][0]),
      'i': float(res['i'] if element else res['i'][0]),
      't': float(res['t'] if element else res['t'][0]),
      't_dot': float(res['t_dot'] if element else res['t_dot'][0]),
      'epsilon': float(res['epsilon'] if element else res['epsilon'][0]),
      'omega': float(res['omega'] if element else res['omega'][0]),
    }
    return d

  
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
          ('mask', 'u1'),
          ('l1ca_bias', 'i2'),
          ('l1p_bias', 'i2'),
          ('l2ca_bias', 'i2'),
          ('l2p_bias', 'i2'),
        ])

    t = getattr(cls, 'static_dtype0', None)
    if not t:
      t = np.dtype([
          ('mask', 'u1'),
          ('l1ca_bias', 'i2'),
          ('l1p_bias', 'i2'),
          ('l2ca_bias', 'i2'),
          ('l2p_bias', 'i2'),
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
      'mask': int(res['mask'] if element else res['mask'][0]),
      'l1ca_bias': int(res['l1ca_bias'] if element else res['l1ca_bias'][0]),
      'l1p_bias': int(res['l1p_bias'] if element else res['l1p_bias'][0]),
      'l2ca_bias': int(res['l2ca_bias'] if element else res['l2ca_bias'][0]),
      'l2p_bias': int(res['l2p_bias'] if element else res['l2p_bias'][0]),
    }
    return d

  
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
          ('sid', GnssSignal._static_dtype()),
          ('az', 'u1'),
          ('el', 'i1'),
        ])

    t = getattr(cls, 'static_dtype0', None)
    if not t:
      t = np.dtype([
          ('sid', GnssSignal._static_dtype()),
          ('az', 'u1'),
          ('el', 'i1'),
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
      'sid': GnssSignal._unpack_members(res['sid'], element=element),
      'az': int(res['az'] if element else res['az'][0]),
      'el': int(res['el'] if element else res['el'][0]),
    }
    return d

  
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
          ('azel', (SvAzEl._static_dtype(), (count,))),
        ])

    t = getattr(cls, 'static_dtype0', None)
    if not t:
      t = np.dtype([
          ('azel', (SvAzEl._static_dtype(), (count,))),
        ])
      cls.static_dtype0 = t
    return t

  @classmethod
  def _dynamic_dtype(cls):
    t = getattr(cls, 'dynamic_dtype', None)
    if not t:    
      t = np.dtype([('azel', SvAzEl._static_dtype()),])
      cls.dynamic_dtype = t
    return t

  @staticmethod
  def _unpack_members(res, element=False):
    d = {
      'azel': [] if res['azel'] is None else [SvAzEl._unpack_members(x, element=True) for x in res['azel'].flatten()],
    }
    return d

  
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
          ('header', ObservationHeader._static_dtype()),
          ('obs', (PackedOsrContent._static_dtype(), (count,))),
        ])

    t = getattr(cls, 'static_dtype0', None)
    if not t:
      t = np.dtype([
          ('header', ObservationHeader._static_dtype()),
          ('obs', (PackedOsrContent._static_dtype(), (count,))),
        ])
      cls.static_dtype0 = t
    return t

  @classmethod
  def _dynamic_dtype(cls):
    t = getattr(cls, 'dynamic_dtype', None)
    if not t:    
      t = np.dtype([('obs', PackedOsrContent._static_dtype()),])
      cls.dynamic_dtype = t
    return t

  @staticmethod
  def _unpack_members(res, element=False):
    d = {
      'header': ObservationHeader._unpack_members(res['header'], element=element),
      'obs': [] if res['obs'] is None else [PackedOsrContent._unpack_members(x, element=True) for x in res['obs'].flatten()],
    }
    return d

  

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
  0x0097: MsgSvAzEl,
  0x0640: MsgOsr,
}