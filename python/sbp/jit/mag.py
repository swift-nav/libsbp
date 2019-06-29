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
  @classmethod
  def parse_members(cls, buf, offset, length):
    ret = {}
    (__tow, offset, length) = get_u32(buf, offset, length)
    ret['tow'] = __tow
    (__tow_f, offset, length) = get_u8(buf, offset, length)
    ret['tow_f'] = __tow_f
    (__mag_x, offset, length) = get_s16(buf, offset, length)
    ret['mag_x'] = __mag_x
    (__mag_y, offset, length) = get_s16(buf, offset, length)
    ret['mag_y'] = __mag_y
    (__mag_z, offset, length) = get_s16(buf, offset, length)
    ret['mag_z'] = __mag_z
    return ret, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.tow = res['tow']
    self.tow_f = res['tow_f']
    self.mag_x = res['mag_x']
    self.mag_y = res['mag_y']
    self.mag_z = res['mag_z']
    return res, off, length

  @classmethod
  def _payload_size(self):
    ret = 0
    # tow: u32
    ret += 4
    # tow_f: u8
    ret += 1
    # mag_x: s16
    ret += 2
    # mag_y: s16
    ret += 2
    # mag_z: s16
    ret += 2
    return ret
  

msg_classes = {
  0x0902: MsgMagRaw,
}