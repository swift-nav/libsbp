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
Inertial Measurement Unit (IMU) messages.
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

# Automatically generated from piksi/yaml/swiftnav/sbp/imu.yaml with generate.py.
# Please do not hand edit!
SBP_MSG_IMU_RAW = 0x0900
class MsgImuRaw(SBP):
  """SBP class for message MSG_IMU_RAW (0x0900).

  You can have MSG_IMU_RAW inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  Raw data from the Inertial Measurement Unit, containing accelerometer and
gyroscope readings. The sense of the measurements are to be aligned with 
the indications on the device itself. Measurement units, which are specific to the
device hardware and settings, are communicated via the MSG_IMU_AUX message.


  """
  __slots__ = ['tow',
               'tow_f',
               'acc_x',
               'acc_y',
               'acc_z',
               'gyr_x',
               'gyr_y',
               'gyr_z',
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
          ('tow_f', 'u1'),
          ('acc_x', 'i2'),
          ('acc_y', 'i2'),
          ('acc_z', 'i2'),
          ('gyr_x', 'i2'),
          ('gyr_y', 'i2'),
          ('gyr_z', 'i2'),
        ])

    t = getattr(cls, 'static_dtype0', None)
    if not t:
      t = np.dtype([
          ('tow', 'u4'),
          ('tow_f', 'u1'),
          ('acc_x', 'i2'),
          ('acc_y', 'i2'),
          ('acc_z', 'i2'),
          ('gyr_x', 'i2'),
          ('gyr_y', 'i2'),
          ('gyr_z', 'i2'),
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
      'tow_f': int(res['tow_f'] if element else res['tow_f'][0]),
      'acc_x': int(res['acc_x'] if element else res['acc_x'][0]),
      'acc_y': int(res['acc_y'] if element else res['acc_y'][0]),
      'acc_z': int(res['acc_z'] if element else res['acc_z'][0]),
      'gyr_x': int(res['gyr_x'] if element else res['gyr_x'][0]),
      'gyr_y': int(res['gyr_y'] if element else res['gyr_y'][0]),
      'gyr_z': int(res['gyr_z'] if element else res['gyr_z'][0]),
    }
    return d

  
SBP_MSG_IMU_AUX = 0x0901
class MsgImuAux(SBP):
  """SBP class for message MSG_IMU_AUX (0x0901).

  You can have MSG_IMU_AUX inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  Auxiliary data specific to a particular IMU. The `imu_type` field will
always be consistent but the rest of the payload is device specific and
depends on the value of `imu_type`.


  """
  __slots__ = ['imu_type',
               'temp',
               'imu_conf',
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
          ('imu_type', 'u1'),
          ('temp', 'i2'),
          ('imu_conf', 'u1'),
        ])

    t = getattr(cls, 'static_dtype0', None)
    if not t:
      t = np.dtype([
          ('imu_type', 'u1'),
          ('temp', 'i2'),
          ('imu_conf', 'u1'),
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
      'imu_type': int(res['imu_type'] if element else res['imu_type'][0]),
      'temp': int(res['temp'] if element else res['temp'][0]),
      'imu_conf': int(res['imu_conf'] if element else res['imu_conf'][0]),
    }
    return d

  

msg_classes = {
  0x0900: MsgImuRaw,
  0x0901: MsgImuAux,
}