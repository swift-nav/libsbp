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
Satellite acquisition messages from the device.
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

# Automatically generated from piksi/yaml/swiftnav/sbp/acquisition.yaml with generate.py.
# Please do not hand edit!
SBP_MSG_ACQ_RESULT = 0x002F
class MsgAcqResult(SBP):
  """SBP class for message MSG_ACQ_RESULT (0x002F).

  You can have MSG_ACQ_RESULT inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  This message describes the results from an attempted GPS signal
acquisition search for a satellite PRN over a code phase/carrier
frequency range. It contains the parameters of the point in the
acquisition search space with the best carrier-to-noise (CN/0)
ratio.


  """
  __slots__ = ['cn0',
               'cp',
               'cf',
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
          ('cn0', 'f4'),
          ('cp', 'f4'),
          ('cf', 'f4'),
          ('sid', GnssSignal._static_dtype()),
        ])

    t = getattr(cls, 'static_dtype0', None)
    if not t:
      t = np.dtype([
          ('cn0', 'f4'),
          ('cp', 'f4'),
          ('cf', 'f4'),
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
      'cn0': float(res['cn0'] if element else res['cn0'][0]),
      'cp': float(res['cp'] if element else res['cp'][0]),
      'cf': float(res['cf'] if element else res['cf'][0]),
      'sid': GnssSignal._unpack_members(res['sid'], element=element),
    }
    return d

  
SBP_MSG_ACQ_RESULT_DEP_C = 0x001F
class MsgAcqResultDepC(SBP):
  """SBP class for message MSG_ACQ_RESULT_DEP_C (0x001F).

  You can have MSG_ACQ_RESULT_DEP_C inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  Deprecated.

  """
  __slots__ = ['cn0',
               'cp',
               'cf',
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
          ('cn0', 'f4'),
          ('cp', 'f4'),
          ('cf', 'f4'),
          ('sid', GnssSignalDep._static_dtype()),
        ])

    t = getattr(cls, 'static_dtype0', None)
    if not t:
      t = np.dtype([
          ('cn0', 'f4'),
          ('cp', 'f4'),
          ('cf', 'f4'),
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
      'cn0': float(res['cn0'] if element else res['cn0'][0]),
      'cp': float(res['cp'] if element else res['cp'][0]),
      'cf': float(res['cf'] if element else res['cf'][0]),
      'sid': GnssSignalDep._unpack_members(res['sid'], element=element),
    }
    return d

  
SBP_MSG_ACQ_RESULT_DEP_B = 0x0014
class MsgAcqResultDepB(SBP):
  """SBP class for message MSG_ACQ_RESULT_DEP_B (0x0014).

  You can have MSG_ACQ_RESULT_DEP_B inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  Deprecated.

  """
  __slots__ = ['snr',
               'cp',
               'cf',
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
          ('snr', 'f4'),
          ('cp', 'f4'),
          ('cf', 'f4'),
          ('sid', GnssSignalDep._static_dtype()),
        ])

    t = getattr(cls, 'static_dtype0', None)
    if not t:
      t = np.dtype([
          ('snr', 'f4'),
          ('cp', 'f4'),
          ('cf', 'f4'),
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
      'snr': float(res['snr'] if element else res['snr'][0]),
      'cp': float(res['cp'] if element else res['cp'][0]),
      'cf': float(res['cf'] if element else res['cf'][0]),
      'sid': GnssSignalDep._unpack_members(res['sid'], element=element),
    }
    return d

  
SBP_MSG_ACQ_RESULT_DEP_A = 0x0015
class MsgAcqResultDepA(SBP):
  """SBP class for message MSG_ACQ_RESULT_DEP_A (0x0015).

  You can have MSG_ACQ_RESULT_DEP_A inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  Deprecated.

  """
  __slots__ = ['snr',
               'cp',
               'cf',
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
          ('snr', 'f4'),
          ('cp', 'f4'),
          ('cf', 'f4'),
          ('prn', 'u1'),
        ])

    t = getattr(cls, 'static_dtype0', None)
    if not t:
      t = np.dtype([
          ('snr', 'f4'),
          ('cp', 'f4'),
          ('cf', 'f4'),
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
      'snr': float(res['snr'] if element else res['snr'][0]),
      'cp': float(res['cp'] if element else res['cp'][0]),
      'cf': float(res['cf'] if element else res['cf'][0]),
      'prn': int(res['prn'] if element else res['prn'][0]),
    }
    return d

  
class AcqSvProfile(object):
  """SBP class for message AcqSvProfile

  You can have AcqSvProfile inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  Profile for a specific SV for debugging purposes
The message describes SV profile during acquisition time.
The message is used to debug and measure the performance.


  """
  __slots__ = ['job_type',
               'status',
               'cn0',
               'int_time',
               'sid',
               'bin_width',
               'timestamp',
               'time_spent',
               'cf_min',
               'cf_max',
               'cf',
               'cp',
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
          ('job_type', 'u1'),
          ('status', 'u1'),
          ('cn0', 'u2'),
          ('int_time', 'u1'),
          ('sid', GnssSignal._static_dtype()),
          ('bin_width', 'u2'),
          ('timestamp', 'u4'),
          ('time_spent', 'u4'),
          ('cf_min', 'i4'),
          ('cf_max', 'i4'),
          ('cf', 'i4'),
          ('cp', 'u4'),
        ])

    t = getattr(cls, 'static_dtype0', None)
    if not t:
      t = np.dtype([
          ('job_type', 'u1'),
          ('status', 'u1'),
          ('cn0', 'u2'),
          ('int_time', 'u1'),
          ('sid', GnssSignal._static_dtype()),
          ('bin_width', 'u2'),
          ('timestamp', 'u4'),
          ('time_spent', 'u4'),
          ('cf_min', 'i4'),
          ('cf_max', 'i4'),
          ('cf', 'i4'),
          ('cp', 'u4'),
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
      'job_type': int(res['job_type'] if element else res['job_type'][0]),
      'status': int(res['status'] if element else res['status'][0]),
      'cn0': int(res['cn0'] if element else res['cn0'][0]),
      'int_time': int(res['int_time'] if element else res['int_time'][0]),
      'sid': GnssSignal._unpack_members(res['sid'], element=element),
      'bin_width': int(res['bin_width'] if element else res['bin_width'][0]),
      'timestamp': int(res['timestamp'] if element else res['timestamp'][0]),
      'time_spent': int(res['time_spent'] if element else res['time_spent'][0]),
      'cf_min': int(res['cf_min'] if element else res['cf_min'][0]),
      'cf_max': int(res['cf_max'] if element else res['cf_max'][0]),
      'cf': int(res['cf'] if element else res['cf'][0]),
      'cp': int(res['cp'] if element else res['cp'][0]),
    }
    return d

  
class AcqSvProfileDep(object):
  """SBP class for message AcqSvProfileDep

  You can have AcqSvProfileDep inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  Deprecated.

  """
  __slots__ = ['job_type',
               'status',
               'cn0',
               'int_time',
               'sid',
               'bin_width',
               'timestamp',
               'time_spent',
               'cf_min',
               'cf_max',
               'cf',
               'cp',
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
          ('job_type', 'u1'),
          ('status', 'u1'),
          ('cn0', 'u2'),
          ('int_time', 'u1'),
          ('sid', GnssSignalDep._static_dtype()),
          ('bin_width', 'u2'),
          ('timestamp', 'u4'),
          ('time_spent', 'u4'),
          ('cf_min', 'i4'),
          ('cf_max', 'i4'),
          ('cf', 'i4'),
          ('cp', 'u4'),
        ])

    t = getattr(cls, 'static_dtype0', None)
    if not t:
      t = np.dtype([
          ('job_type', 'u1'),
          ('status', 'u1'),
          ('cn0', 'u2'),
          ('int_time', 'u1'),
          ('sid', GnssSignalDep._static_dtype()),
          ('bin_width', 'u2'),
          ('timestamp', 'u4'),
          ('time_spent', 'u4'),
          ('cf_min', 'i4'),
          ('cf_max', 'i4'),
          ('cf', 'i4'),
          ('cp', 'u4'),
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
      'job_type': int(res['job_type'] if element else res['job_type'][0]),
      'status': int(res['status'] if element else res['status'][0]),
      'cn0': int(res['cn0'] if element else res['cn0'][0]),
      'int_time': int(res['int_time'] if element else res['int_time'][0]),
      'sid': GnssSignalDep._unpack_members(res['sid'], element=element),
      'bin_width': int(res['bin_width'] if element else res['bin_width'][0]),
      'timestamp': int(res['timestamp'] if element else res['timestamp'][0]),
      'time_spent': int(res['time_spent'] if element else res['time_spent'][0]),
      'cf_min': int(res['cf_min'] if element else res['cf_min'][0]),
      'cf_max': int(res['cf_max'] if element else res['cf_max'][0]),
      'cf': int(res['cf'] if element else res['cf'][0]),
      'cp': int(res['cp'] if element else res['cp'][0]),
    }
    return d

  
SBP_MSG_ACQ_SV_PROFILE = 0x002E
class MsgAcqSvProfile(SBP):
  """SBP class for message MSG_ACQ_SV_PROFILE (0x002E).

  You can have MSG_ACQ_SV_PROFILE inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  The message describes all SV profiles during acquisition time.
The message is used to debug and measure the performance.


  """
  __slots__ = ['acq_sv_profile',
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
          ('acq_sv_profile', (AcqSvProfile._static_dtype(), (count,))),
        ])

    t = getattr(cls, 'static_dtype0', None)
    if not t:
      t = np.dtype([
          ('acq_sv_profile', (AcqSvProfile._static_dtype(), (count,))),
        ])
      cls.static_dtype0 = t
    return t

  @classmethod
  def _dynamic_dtype(cls):
    t = getattr(cls, 'dynamic_dtype', None)
    if not t:    
      t = np.dtype([('acq_sv_profile', AcqSvProfile._static_dtype()),])
      cls.dynamic_dtype = t
    return t

  @staticmethod
  def _unpack_members(res, element=False):
    d = {
      'acq_sv_profile': [] if res['acq_sv_profile'] is None else [AcqSvProfile._unpack_members(x, element=True) for x in res['acq_sv_profile'].flatten()],
    }
    return d

  
SBP_MSG_ACQ_SV_PROFILE_DEP = 0x001E
class MsgAcqSvProfileDep(SBP):
  """SBP class for message MSG_ACQ_SV_PROFILE_DEP (0x001E).

  You can have MSG_ACQ_SV_PROFILE_DEP inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  Deprecated.

  """
  __slots__ = ['acq_sv_profile',
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
          ('acq_sv_profile', (AcqSvProfileDep._static_dtype(), (count,))),
        ])

    t = getattr(cls, 'static_dtype0', None)
    if not t:
      t = np.dtype([
          ('acq_sv_profile', (AcqSvProfileDep._static_dtype(), (count,))),
        ])
      cls.static_dtype0 = t
    return t

  @classmethod
  def _dynamic_dtype(cls):
    t = getattr(cls, 'dynamic_dtype', None)
    if not t:    
      t = np.dtype([('acq_sv_profile', AcqSvProfileDep._static_dtype()),])
      cls.dynamic_dtype = t
    return t

  @staticmethod
  def _unpack_members(res, element=False):
    d = {
      'acq_sv_profile': [] if res['acq_sv_profile'] is None else [AcqSvProfileDep._unpack_members(x, element=True) for x in res['acq_sv_profile'].flatten()],
    }
    return d

  

msg_classes = {
  0x002F: MsgAcqResult,
  0x001F: MsgAcqResultDepC,
  0x0014: MsgAcqResultDepB,
  0x0015: MsgAcqResultDepA,
  0x002E: MsgAcqSvProfile,
  0x001E: MsgAcqSvProfileDep,
}