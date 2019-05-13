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
Magnetometer (mag) messages.
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

# Automatically generated from piksi/yaml/swiftnav/sbp/mag.yaml with generate.py.
# Please do not hand edit!
SBP_MSG_MAG_RAW = 0x0902
class MsgMagRaw(SBP):
  """SBP class for message MSG_MAG_RAW (0x0902).

  You can have MSG_MAG_RAW inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  Raw data from the magnetometer.


  """
  __slots__ = ['tow',
               'tow_f',
               'mag_x',
               'mag_y',
               'mag_z',
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
          ('mag_x', 'i2'),
          ('mag_y', 'i2'),
          ('mag_z', 'i2'),
        ])

    t = getattr(cls, 'static_dtype0', None)
    if not t:
      t = np.dtype([
          ('tow', 'u4'),
          ('tow_f', 'u1'),
          ('mag_x', 'i2'),
          ('mag_y', 'i2'),
          ('mag_z', 'i2'),
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
      'mag_x': int(res['mag_x'] if element else res['mag_x'][0]),
      'mag_y': int(res['mag_y'] if element else res['mag_y'][0]),
      'mag_z': int(res['mag_z'] if element else res['mag_z'][0]),
    }
    return d

  

msg_classes = {
  0x0902: MsgMagRaw,
}