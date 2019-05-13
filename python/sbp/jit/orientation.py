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
Orientation Messages
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

# Automatically generated from piksi/yaml/swiftnav/sbp/orientation.yaml with generate.py.
# Please do not hand edit!
SBP_MSG_BASELINE_HEADING = 0x020F
class MsgBaselineHeading(SBP):
  """SBP class for message MSG_BASELINE_HEADING (0x020F).

  You can have MSG_BASELINE_HEADING inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  This message reports the baseline heading pointing from the base station
to the rover relative to True North. The full GPS time is given by the
preceding MSG_GPS_TIME with the matching time-of-week (tow). It is intended
that time-matched RTK mode is used when the base station is moving.


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

  
SBP_MSG_ORIENT_QUAT = 0x0220
class MsgOrientQuat(SBP):
  """SBP class for message MSG_ORIENT_QUAT (0x0220).

  You can have MSG_ORIENT_QUAT inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  This message reports the quaternion vector describing the vehicle body frame's orientation
with respect to a local-level NED frame. The components of the vector should sum to a unit
vector assuming that the LSB of each component as a value of 2^-31. This message will only
be available in future INS versions of Swift Products and is not produced by Piksi Multi 
or Duro.


  """
  __slots__ = ['tow',
               'w',
               'x',
               'y',
               'z',
               'w_accuracy',
               'x_accuracy',
               'y_accuracy',
               'z_accuracy',
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
          ('w', 'i4'),
          ('x', 'i4'),
          ('y', 'i4'),
          ('z', 'i4'),
          ('w_accuracy', 'f4'),
          ('x_accuracy', 'f4'),
          ('y_accuracy', 'f4'),
          ('z_accuracy', 'f4'),
          ('flags', 'u1'),
        ])

    t = getattr(cls, 'static_dtype0', None)
    if not t:
      t = np.dtype([
          ('tow', 'u4'),
          ('w', 'i4'),
          ('x', 'i4'),
          ('y', 'i4'),
          ('z', 'i4'),
          ('w_accuracy', 'f4'),
          ('x_accuracy', 'f4'),
          ('y_accuracy', 'f4'),
          ('z_accuracy', 'f4'),
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
      'w': int(res['w'] if element else res['w'][0]),
      'x': int(res['x'] if element else res['x'][0]),
      'y': int(res['y'] if element else res['y'][0]),
      'z': int(res['z'] if element else res['z'][0]),
      'w_accuracy': float(res['w_accuracy'] if element else res['w_accuracy'][0]),
      'x_accuracy': float(res['x_accuracy'] if element else res['x_accuracy'][0]),
      'y_accuracy': float(res['y_accuracy'] if element else res['y_accuracy'][0]),
      'z_accuracy': float(res['z_accuracy'] if element else res['z_accuracy'][0]),
      'flags': int(res['flags'] if element else res['flags'][0]),
    }
    return d

  
SBP_MSG_ORIENT_EULER = 0x0221
class MsgOrientEuler(SBP):
  """SBP class for message MSG_ORIENT_EULER (0x0221).

  You can have MSG_ORIENT_EULER inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  This message reports the yaw, pitch, and roll angles of the vehicle body frame.
The rotations should applied intrinsically in the order yaw, pitch, and roll 
in order to rotate the from a frame aligned with the local-level NED frame 
to the vehicle body frame.  This message will only be available in future 
INS versions of Swift Products and is not produced by Piksi Multi or Duro.


  """
  __slots__ = ['tow',
               'roll',
               'pitch',
               'yaw',
               'roll_accuracy',
               'pitch_accuracy',
               'yaw_accuracy',
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
          ('roll', 'i4'),
          ('pitch', 'i4'),
          ('yaw', 'i4'),
          ('roll_accuracy', 'f4'),
          ('pitch_accuracy', 'f4'),
          ('yaw_accuracy', 'f4'),
          ('flags', 'u1'),
        ])

    t = getattr(cls, 'static_dtype0', None)
    if not t:
      t = np.dtype([
          ('tow', 'u4'),
          ('roll', 'i4'),
          ('pitch', 'i4'),
          ('yaw', 'i4'),
          ('roll_accuracy', 'f4'),
          ('pitch_accuracy', 'f4'),
          ('yaw_accuracy', 'f4'),
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
      'roll': int(res['roll'] if element else res['roll'][0]),
      'pitch': int(res['pitch'] if element else res['pitch'][0]),
      'yaw': int(res['yaw'] if element else res['yaw'][0]),
      'roll_accuracy': float(res['roll_accuracy'] if element else res['roll_accuracy'][0]),
      'pitch_accuracy': float(res['pitch_accuracy'] if element else res['pitch_accuracy'][0]),
      'yaw_accuracy': float(res['yaw_accuracy'] if element else res['yaw_accuracy'][0]),
      'flags': int(res['flags'] if element else res['flags'][0]),
    }
    return d

  
SBP_MSG_ANGULAR_RATE = 0x0222
class MsgAngularRate(SBP):
  """SBP class for message MSG_ANGULAR_RATE (0x0222).

  You can have MSG_ANGULAR_RATE inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  This message reports the orientation rates in the vehicle body frame. 
The values represent the measurements a strapped down gyroscope would 
make and are not equivalent to the time derivative of the Euler angles.
The orientation and origin of the user frame is specified via device settings.
By convention, the vehicle x-axis is expected to be aligned with the forward
direction, while the vehicle y-axis is expected to be aligned with the right
direction, and the vehicle z-axis should be aligned with the down direction.
This message will only be available in future INS versions of Swift Products 
and is not produced by Piksi Multi or Duro.


  """
  __slots__ = ['tow',
               'x',
               'y',
               'z',
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
          ('flags', 'u1'),
        ])

    t = getattr(cls, 'static_dtype0', None)
    if not t:
      t = np.dtype([
          ('tow', 'u4'),
          ('x', 'i4'),
          ('y', 'i4'),
          ('z', 'i4'),
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
      'flags': int(res['flags'] if element else res['flags'][0]),
    }
    return d

  

msg_classes = {
  0x020F: MsgBaselineHeading,
  0x0220: MsgOrientQuat,
  0x0221: MsgOrientEuler,
  0x0222: MsgAngularRate,
}