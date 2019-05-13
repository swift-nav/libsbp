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

import numba as nb
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
          ('recv_time', 'u8'),
          ('tot', GPSTime._static_dtype()),
          ('P', 'u4'),
          ('P_std', 'u2'),
          ('L', CarrierPhase._static_dtype()),
          ('cn0', 'u1'),
          ('lock', 'u2'),
          ('sid', GnssSignal._static_dtype()),
          ('doppler', 'i4'),
          ('doppler_std', 'u2'),
          ('uptime', 'u4'),
          ('clock_offset', 'i2'),
          ('clock_drift', 'i2'),
          ('corr_spacing', 'u2'),
          ('acceleration', 'i1'),
          ('sync_flags', 'u1'),
          ('tow_flags', 'u1'),
          ('track_flags', 'u1'),
          ('nav_flags', 'u1'),
          ('pset_flags', 'u1'),
          ('misc_flags', 'u1'),
        ])

    t = getattr(cls, 'static_dtype0', None)
    if not t:
      t = np.dtype([
          ('recv_time', 'u8'),
          ('tot', GPSTime._static_dtype()),
          ('P', 'u4'),
          ('P_std', 'u2'),
          ('L', CarrierPhase._static_dtype()),
          ('cn0', 'u1'),
          ('lock', 'u2'),
          ('sid', GnssSignal._static_dtype()),
          ('doppler', 'i4'),
          ('doppler_std', 'u2'),
          ('uptime', 'u4'),
          ('clock_offset', 'i2'),
          ('clock_drift', 'i2'),
          ('corr_spacing', 'u2'),
          ('acceleration', 'i1'),
          ('sync_flags', 'u1'),
          ('tow_flags', 'u1'),
          ('track_flags', 'u1'),
          ('nav_flags', 'u1'),
          ('pset_flags', 'u1'),
          ('misc_flags', 'u1'),
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
      'recv_time': int(res['recv_time'] if element else res['recv_time'][0]),
      'tot': GPSTime._unpack_members(res['tot'], element=element),
      'P': int(res['P'] if element else res['P'][0]),
      'P_std': int(res['P_std'] if element else res['P_std'][0]),
      'L': CarrierPhase._unpack_members(res['L'], element=element),
      'cn0': int(res['cn0'] if element else res['cn0'][0]),
      'lock': int(res['lock'] if element else res['lock'][0]),
      'sid': GnssSignal._unpack_members(res['sid'], element=element),
      'doppler': int(res['doppler'] if element else res['doppler'][0]),
      'doppler_std': int(res['doppler_std'] if element else res['doppler_std'][0]),
      'uptime': int(res['uptime'] if element else res['uptime'][0]),
      'clock_offset': int(res['clock_offset'] if element else res['clock_offset'][0]),
      'clock_drift': int(res['clock_drift'] if element else res['clock_drift'][0]),
      'corr_spacing': int(res['corr_spacing'] if element else res['corr_spacing'][0]),
      'acceleration': int(res['acceleration'] if element else res['acceleration'][0]),
      'sync_flags': int(res['sync_flags'] if element else res['sync_flags'][0]),
      'tow_flags': int(res['tow_flags'] if element else res['tow_flags'][0]),
      'track_flags': int(res['track_flags'] if element else res['track_flags'][0]),
      'nav_flags': int(res['nav_flags'] if element else res['nav_flags'][0]),
      'pset_flags': int(res['pset_flags'] if element else res['pset_flags'][0]),
      'misc_flags': int(res['misc_flags'] if element else res['misc_flags'][0]),
    }
    return d

  
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
          ('recv_time', 'u8'),
          ('tot', GPSTimeDep._static_dtype()),
          ('P', 'u4'),
          ('P_std', 'u2'),
          ('L', CarrierPhase._static_dtype()),
          ('cn0', 'u1'),
          ('lock', 'u2'),
          ('sid', GnssSignalDep._static_dtype()),
          ('doppler', 'i4'),
          ('doppler_std', 'u2'),
          ('uptime', 'u4'),
          ('clock_offset', 'i2'),
          ('clock_drift', 'i2'),
          ('corr_spacing', 'u2'),
          ('acceleration', 'i1'),
          ('sync_flags', 'u1'),
          ('tow_flags', 'u1'),
          ('track_flags', 'u1'),
          ('nav_flags', 'u1'),
          ('pset_flags', 'u1'),
          ('misc_flags', 'u1'),
        ])

    t = getattr(cls, 'static_dtype0', None)
    if not t:
      t = np.dtype([
          ('recv_time', 'u8'),
          ('tot', GPSTimeDep._static_dtype()),
          ('P', 'u4'),
          ('P_std', 'u2'),
          ('L', CarrierPhase._static_dtype()),
          ('cn0', 'u1'),
          ('lock', 'u2'),
          ('sid', GnssSignalDep._static_dtype()),
          ('doppler', 'i4'),
          ('doppler_std', 'u2'),
          ('uptime', 'u4'),
          ('clock_offset', 'i2'),
          ('clock_drift', 'i2'),
          ('corr_spacing', 'u2'),
          ('acceleration', 'i1'),
          ('sync_flags', 'u1'),
          ('tow_flags', 'u1'),
          ('track_flags', 'u1'),
          ('nav_flags', 'u1'),
          ('pset_flags', 'u1'),
          ('misc_flags', 'u1'),
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
      'recv_time': int(res['recv_time'] if element else res['recv_time'][0]),
      'tot': GPSTimeDep._unpack_members(res['tot'], element=element),
      'P': int(res['P'] if element else res['P'][0]),
      'P_std': int(res['P_std'] if element else res['P_std'][0]),
      'L': CarrierPhase._unpack_members(res['L'], element=element),
      'cn0': int(res['cn0'] if element else res['cn0'][0]),
      'lock': int(res['lock'] if element else res['lock'][0]),
      'sid': GnssSignalDep._unpack_members(res['sid'], element=element),
      'doppler': int(res['doppler'] if element else res['doppler'][0]),
      'doppler_std': int(res['doppler_std'] if element else res['doppler_std'][0]),
      'uptime': int(res['uptime'] if element else res['uptime'][0]),
      'clock_offset': int(res['clock_offset'] if element else res['clock_offset'][0]),
      'clock_drift': int(res['clock_drift'] if element else res['clock_drift'][0]),
      'corr_spacing': int(res['corr_spacing'] if element else res['corr_spacing'][0]),
      'acceleration': int(res['acceleration'] if element else res['acceleration'][0]),
      'sync_flags': int(res['sync_flags'] if element else res['sync_flags'][0]),
      'tow_flags': int(res['tow_flags'] if element else res['tow_flags'][0]),
      'track_flags': int(res['track_flags'] if element else res['track_flags'][0]),
      'nav_flags': int(res['nav_flags'] if element else res['nav_flags'][0]),
      'pset_flags': int(res['pset_flags'] if element else res['pset_flags'][0]),
      'misc_flags': int(res['misc_flags'] if element else res['misc_flags'][0]),
    }
    return d

  
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
          ('fcn', 'u1'),
          ('cn0', 'u1'),
        ])

    t = getattr(cls, 'static_dtype0', None)
    if not t:
      t = np.dtype([
          ('sid', GnssSignal._static_dtype()),
          ('fcn', 'u1'),
          ('cn0', 'u1'),
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
      'fcn': int(res['fcn'] if element else res['fcn'][0]),
      'cn0': int(res['cn0'] if element else res['cn0'][0]),
    }
    return d

  
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
          ('states', (TrackingChannelState._static_dtype(), (count,))),
        ])

    t = getattr(cls, 'static_dtype0', None)
    if not t:
      t = np.dtype([
          ('states', (TrackingChannelState._static_dtype(), (count,))),
        ])
      cls.static_dtype0 = t
    return t

  @classmethod
  def _dynamic_dtype(cls):
    t = getattr(cls, 'dynamic_dtype', None)
    if not t:    
      t = np.dtype([('states', TrackingChannelState._static_dtype()),])
      cls.dynamic_dtype = t
    return t

  @staticmethod
  def _unpack_members(res, element=False):
    d = {
      'states': [] if res['states'] is None else [TrackingChannelState._unpack_members(x, element=True) for x in res['states'].flatten()],
    }
    return d

  
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
          ('mesid', GnssSignal._static_dtype()),
          ('cn0', 'u1'),
        ])

    t = getattr(cls, 'static_dtype0', None)
    if not t:
      t = np.dtype([
          ('mesid', GnssSignal._static_dtype()),
          ('cn0', 'u1'),
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
      'mesid': GnssSignal._unpack_members(res['mesid'], element=element),
      'cn0': int(res['cn0'] if element else res['cn0'][0]),
    }
    return d

  
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
          ('states', (MeasurementState._static_dtype(), (count,))),
        ])

    t = getattr(cls, 'static_dtype0', None)
    if not t:
      t = np.dtype([
          ('states', (MeasurementState._static_dtype(), (count,))),
        ])
      cls.static_dtype0 = t
    return t

  @classmethod
  def _dynamic_dtype(cls):
    t = getattr(cls, 'dynamic_dtype', None)
    if not t:    
      t = np.dtype([('states', MeasurementState._static_dtype()),])
      cls.dynamic_dtype = t
    return t

  @staticmethod
  def _unpack_members(res, element=False):
    d = {
      'states': [] if res['states'] is None else [MeasurementState._unpack_members(x, element=True) for x in res['states'].flatten()],
    }
    return d

  
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
          ('I', 'i2'),
          ('Q', 'i2'),
        ])

    t = getattr(cls, 'static_dtype0', None)
    if not t:
      t = np.dtype([
          ('I', 'i2'),
          ('Q', 'i2'),
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
      'I': int(res['I'] if element else res['I'][0]),
      'Q': int(res['Q'] if element else res['Q'][0]),
    }
    return d

  
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
          ('channel', 'u1'),
          ('sid', GnssSignal._static_dtype()),
          ('corrs', (TrackingChannelCorrelation._static_dtype(), (3,))),
        ])

    t = getattr(cls, 'static_dtype0', None)
    if not t:
      t = np.dtype([
          ('channel', 'u1'),
          ('sid', GnssSignal._static_dtype()),
          ('corrs', (TrackingChannelCorrelation._static_dtype(), (3,))),
        ])
      cls.static_dtype0 = t
    return t

  @classmethod
  def _dynamic_dtype(cls):
    t = getattr(cls, 'dynamic_dtype', None)
    if not t:    
      t = np.dtype([('corrs', TrackingChannelCorrelation._static_dtype()),])
      cls.dynamic_dtype = t
    return t

  @staticmethod
  def _unpack_members(res, element=False):
    d = {
      'channel': int(res['channel'] if element else res['channel'][0]),
      'sid': GnssSignal._unpack_members(res['sid'], element=element),
      'corrs': [] if res['corrs'] is None else [TrackingChannelCorrelation._unpack_members(x, element=True) for x in res['corrs'].flatten()],
    }
    return d

  
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
          ('I', 'i4'),
          ('Q', 'i4'),
        ])

    t = getattr(cls, 'static_dtype0', None)
    if not t:
      t = np.dtype([
          ('I', 'i4'),
          ('Q', 'i4'),
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
      'I': int(res['I'] if element else res['I'][0]),
      'Q': int(res['Q'] if element else res['Q'][0]),
    }
    return d

  
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
          ('channel', 'u1'),
          ('sid', GnssSignal._static_dtype()),
          ('corrs', (TrackingChannelCorrelationDep._static_dtype(), (3,))),
        ])

    t = getattr(cls, 'static_dtype0', None)
    if not t:
      t = np.dtype([
          ('channel', 'u1'),
          ('sid', GnssSignal._static_dtype()),
          ('corrs', (TrackingChannelCorrelationDep._static_dtype(), (3,))),
        ])
      cls.static_dtype0 = t
    return t

  @classmethod
  def _dynamic_dtype(cls):
    t = getattr(cls, 'dynamic_dtype', None)
    if not t:    
      t = np.dtype([('corrs', TrackingChannelCorrelationDep._static_dtype()),])
      cls.dynamic_dtype = t
    return t

  @staticmethod
  def _unpack_members(res, element=False):
    d = {
      'channel': int(res['channel'] if element else res['channel'][0]),
      'sid': GnssSignal._unpack_members(res['sid'], element=element),
      'corrs': [] if res['corrs'] is None else [TrackingChannelCorrelationDep._unpack_members(x, element=True) for x in res['corrs'].flatten()],
    }
    return d

  
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
          ('channel', 'u1'),
          ('sid', GnssSignalDep._static_dtype()),
          ('corrs', (TrackingChannelCorrelationDep._static_dtype(), (3,))),
        ])

    t = getattr(cls, 'static_dtype0', None)
    if not t:
      t = np.dtype([
          ('channel', 'u1'),
          ('sid', GnssSignalDep._static_dtype()),
          ('corrs', (TrackingChannelCorrelationDep._static_dtype(), (3,))),
        ])
      cls.static_dtype0 = t
    return t

  @classmethod
  def _dynamic_dtype(cls):
    t = getattr(cls, 'dynamic_dtype', None)
    if not t:    
      t = np.dtype([('corrs', TrackingChannelCorrelationDep._static_dtype()),])
      cls.dynamic_dtype = t
    return t

  @staticmethod
  def _unpack_members(res, element=False):
    d = {
      'channel': int(res['channel'] if element else res['channel'][0]),
      'sid': GnssSignalDep._unpack_members(res['sid'], element=element),
      'corrs': [] if res['corrs'] is None else [TrackingChannelCorrelationDep._unpack_members(x, element=True) for x in res['corrs'].flatten()],
    }
    return d

  
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
          ('state', 'u1'),
          ('prn', 'u1'),
          ('cn0', 'f4'),
        ])

    t = getattr(cls, 'static_dtype0', None)
    if not t:
      t = np.dtype([
          ('state', 'u1'),
          ('prn', 'u1'),
          ('cn0', 'f4'),
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
      'state': int(res['state'] if element else res['state'][0]),
      'prn': int(res['prn'] if element else res['prn'][0]),
      'cn0': float(res['cn0'] if element else res['cn0'][0]),
    }
    return d

  
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
          ('states', (TrackingChannelStateDepA._static_dtype(), (count,))),
        ])

    t = getattr(cls, 'static_dtype0', None)
    if not t:
      t = np.dtype([
          ('states', (TrackingChannelStateDepA._static_dtype(), (count,))),
        ])
      cls.static_dtype0 = t
    return t

  @classmethod
  def _dynamic_dtype(cls):
    t = getattr(cls, 'dynamic_dtype', None)
    if not t:    
      t = np.dtype([('states', TrackingChannelStateDepA._static_dtype()),])
      cls.dynamic_dtype = t
    return t

  @staticmethod
  def _unpack_members(res, element=False):
    d = {
      'states': [] if res['states'] is None else [TrackingChannelStateDepA._unpack_members(x, element=True) for x in res['states'].flatten()],
    }
    return d

  
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
          ('state', 'u1'),
          ('sid', GnssSignalDep._static_dtype()),
          ('cn0', 'f4'),
        ])

    t = getattr(cls, 'static_dtype0', None)
    if not t:
      t = np.dtype([
          ('state', 'u1'),
          ('sid', GnssSignalDep._static_dtype()),
          ('cn0', 'f4'),
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
      'state': int(res['state'] if element else res['state'][0]),
      'sid': GnssSignalDep._unpack_members(res['sid'], element=element),
      'cn0': float(res['cn0'] if element else res['cn0'][0]),
    }
    return d

  
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
          ('states', (TrackingChannelStateDepB._static_dtype(), (count,))),
        ])

    t = getattr(cls, 'static_dtype0', None)
    if not t:
      t = np.dtype([
          ('states', (TrackingChannelStateDepB._static_dtype(), (count,))),
        ])
      cls.static_dtype0 = t
    return t

  @classmethod
  def _dynamic_dtype(cls):
    t = getattr(cls, 'dynamic_dtype', None)
    if not t:    
      t = np.dtype([('states', TrackingChannelStateDepB._static_dtype()),])
      cls.dynamic_dtype = t
    return t

  @staticmethod
  def _unpack_members(res, element=False):
    d = {
      'states': [] if res['states'] is None else [TrackingChannelStateDepB._unpack_members(x, element=True) for x in res['states'].flatten()],
    }
    return d

  

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