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
Standardized system messages from Swift Navigation devices.
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

# Automatically generated from piksi/yaml/swiftnav/sbp/system.yaml with generate.py.
# Please do not hand edit!
SBP_MSG_STARTUP = 0xFF00
class MsgStartup(SBP):
  """SBP class for message MSG_STARTUP (0xFF00).

  You can have MSG_STARTUP inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  The system start-up message is sent once on system
start-up. It notifies the host or other attached devices that
the system has started and is now ready to respond to commands
or configuration requests.


  """
  __slots__ = ['cause',
               'startup_type',
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
          ('cause', 'u1'),
          ('startup_type', 'u1'),
          ('reserved', 'u2'),
        ])

    t = getattr(cls, 'static_dtype0', None)
    if not t:
      t = np.dtype([
          ('cause', 'u1'),
          ('startup_type', 'u1'),
          ('reserved', 'u2'),
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
      'cause': int(res['cause'] if element else res['cause'][0]),
      'startup_type': int(res['startup_type'] if element else res['startup_type'][0]),
      'reserved': int(res['reserved'] if element else res['reserved'][0]),
    }
    return d

  
SBP_MSG_DGNSS_STATUS = 0xFF02
class MsgDgnssStatus(SBP):
  """SBP class for message MSG_DGNSS_STATUS (0xFF02).

  You can have MSG_DGNSS_STATUS inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  This message provides information about the receipt of Differential
corrections.  It is expected to be sent with each receipt of a complete
corrections packet.


  """
  __slots__ = ['flags',
               'latency',
               'num_signals',
               'source',
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
          ('latency', 'u2'),
          ('num_signals', 'u1'),
          ('source', '|S{}'.format(count)),
        ])

    t = getattr(cls, 'static_dtype0', None)
    if not t:
      t = np.dtype([
          ('flags', 'u1'),
          ('latency', 'u2'),
          ('num_signals', 'u1'),
          ('source', '|S{}'.format(count)),
        ])
      cls.static_dtype0 = t
    return t

  @classmethod
  def _dynamic_dtype(cls):
    t = getattr(cls, 'dynamic_dtype', None)
    if not t:    
      t = np.dtype('u1')
      cls.dynamic_dtype = t
    return t

  @staticmethod
  def _unpack_members(res, element=False):
    d = {
      'flags': int(res['flags'] if element else res['flags'][0]),
      'latency': int(res['latency'] if element else res['latency'][0]),
      'num_signals': int(res['num_signals'] if element else res['num_signals'][0]),
      'source': '' if res['source'] is None else res['source'].tostring().decode('ascii'),
    }
    return d

  
SBP_MSG_HEARTBEAT = 0xFFFF
class MsgHeartbeat(SBP):
  """SBP class for message MSG_HEARTBEAT (0xFFFF).

  You can have MSG_HEARTBEAT inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  The heartbeat message is sent periodically to inform the host
or other attached devices that the system is running. It is
used to monitor system malfunctions. It also contains status
flags that indicate to the host the status of the system and
whether it is operating correctly. Currently, the expected
heartbeat interval is 1 sec.

The system error flag is used to indicate that an error has
occurred in the system. To determine the source of the error,
the remaining error flags should be inspected.


  """
  __slots__ = ['flags',
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
          ('flags', 'u4'),
        ])

    t = getattr(cls, 'static_dtype0', None)
    if not t:
      t = np.dtype([
          ('flags', 'u4'),
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
    }
    return d

  
SBP_MSG_INS_STATUS = 0xFF03
class MsgInsStatus(SBP):
  """SBP class for message MSG_INS_STATUS (0xFF03).

  You can have MSG_INS_STATUS inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  The INS status message describes the state of the operation
and initialization of the inertial navigation system. 


  """
  __slots__ = ['flags',
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
          ('flags', 'u4'),
        ])

    t = getattr(cls, 'static_dtype0', None)
    if not t:
      t = np.dtype([
          ('flags', 'u4'),
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
    }
    return d

  
SBP_MSG_CSAC_TELEMETRY = 0xFF04
class MsgCsacTelemetry(SBP):
  """SBP class for message MSG_CSAC_TELEMETRY (0xFF04).

  You can have MSG_CSAC_TELEMETRY inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  The CSAC telemetry message has an implementation defined telemetry string
from a device. It is not produced or available on general Swift Products.
It is intended to be a low rate message for status purposes.


  """
  __slots__ = ['id',
               'telemetry',
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
          ('id', 'u1'),
          ('telemetry', '|S{}'.format(count)),
        ])

    t = getattr(cls, 'static_dtype0', None)
    if not t:
      t = np.dtype([
          ('id', 'u1'),
          ('telemetry', '|S{}'.format(count)),
        ])
      cls.static_dtype0 = t
    return t

  @classmethod
  def _dynamic_dtype(cls):
    t = getattr(cls, 'dynamic_dtype', None)
    if not t:    
      t = np.dtype('u1')
      cls.dynamic_dtype = t
    return t

  @staticmethod
  def _unpack_members(res, element=False):
    d = {
      'id': int(res['id'] if element else res['id'][0]),
      'telemetry': '' if res['telemetry'] is None else res['telemetry'].tostring().decode('ascii'),
    }
    return d

  
SBP_MSG_CSAC_TELEMETRY_LABELS = 0xFF05
class MsgCsacTelemetryLabels(SBP):
  """SBP class for message MSG_CSAC_TELEMETRY_LABELS (0xFF05).

  You can have MSG_CSAC_TELEMETRY_LABELS inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  The CSAC telemetry message provides labels for each member of the string
produced by MSG_CSAC_TELEMETRY. It should be provided by a device at a lower
rate than the MSG_CSAC_TELEMETRY.


  """
  __slots__ = ['id',
               'telemetry_labels',
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
          ('id', 'u1'),
          ('telemetry_labels', '|S{}'.format(count)),
        ])

    t = getattr(cls, 'static_dtype0', None)
    if not t:
      t = np.dtype([
          ('id', 'u1'),
          ('telemetry_labels', '|S{}'.format(count)),
        ])
      cls.static_dtype0 = t
    return t

  @classmethod
  def _dynamic_dtype(cls):
    t = getattr(cls, 'dynamic_dtype', None)
    if not t:    
      t = np.dtype('u1')
      cls.dynamic_dtype = t
    return t

  @staticmethod
  def _unpack_members(res, element=False):
    d = {
      'id': int(res['id'] if element else res['id'][0]),
      'telemetry_labels': '' if res['telemetry_labels'] is None else res['telemetry_labels'].tostring().decode('ascii'),
    }
    return d

  

msg_classes = {
  0xFF00: MsgStartup,
  0xFF02: MsgDgnssStatus,
  0xFFFF: MsgHeartbeat,
  0xFF03: MsgInsStatus,
  0xFF04: MsgCsacTelemetry,
  0xFF05: MsgCsacTelemetryLabels,
}