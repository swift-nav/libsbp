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
Messages from a vehicle.
"""

import json

import numpy as np

from sbp.jit.msg import SBP, SENDER_ID
from sbp.jit.msg import get_u8, get_u16, get_u32, get_u64
from sbp.jit.msg import get_s8, get_s16, get_s32, get_s64
from sbp.jit.msg import get_f32, get_f64, judicious_round
from sbp.jit.msg import get_string, get_fixed_string, get_setting
from sbp.jit.msg import get_array, get_fixed_array

# Automatically generated from piksi/yaml/swiftnav/sbp/vehicle.yaml with generate.py.
# Please do not hand edit!
SBP_MSG_ODOMETRY = 0x0903
class MsgOdometry(SBP):
  """SBP class for message MSG_ODOMETRY (0x0903).

  You can have MSG_ODOMETRY inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  Message representing the x component of vehicle velocity in the user frame at the odometry
reference point(s) specified by the user. The offset for the odometry reference point and 
the definition and origin of the user frame are defined through the device settings interface.
There are 4 possible user-defined sources of this message  which are labeled arbitrarily 
source 0 through 3.


  """
  __slots__ = ['tow',
               'velocity',
               'flags',
               ]
  @classmethod
  def parse_members(cls, buf, offset, length):
    ret = {}
    (__tow, offset, length) = get_u32(buf, offset, length)
    ret['tow'] = __tow
    (__velocity, offset, length) = get_s32(buf, offset, length)
    ret['velocity'] = __velocity
    (__flags, offset, length) = get_u8(buf, offset, length)
    ret['flags'] = __flags
    return ret, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.tow = res['tow']
    self.velocity = res['velocity']
    self.flags = res['flags']
    return res, off, length

  @classmethod
  def _payload_size(self):
    ret = 0
    # tow: u32
    ret += 4
    # velocity: s32
    ret += 4
    # flags: u8
    ret += 1
    return ret
  
SBP_MSG_WHEELTICK = 0x0904
class MsgWheeltick(SBP):
  """SBP class for message MSG_WHEELTICK (0x0904).

  You can have MSG_WHEELTICK inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  Message containing the accumulated distance travelled by a wheel located at an odometry
reference point defined by the user. The offset for the odometry reference point and the
definition and origin of the user frame are defined through the device settings interface.
The source of this message is identified by the source field, which is an integer ranging
from 0 to 255.
The timestamp associated with this message should represent the time when the accumulated
tick count reached the value given by the contents of this message as accurately as possible.


  """
  __slots__ = ['time',
               'flags',
               'source',
               'ticks',
               ]
  @classmethod
  def parse_members(cls, buf, offset, length):
    ret = {}
    (__time, offset, length) = get_u64(buf, offset, length)
    ret['time'] = __time
    (__flags, offset, length) = get_u8(buf, offset, length)
    ret['flags'] = __flags
    (__source, offset, length) = get_u8(buf, offset, length)
    ret['source'] = __source
    (__ticks, offset, length) = get_s32(buf, offset, length)
    ret['ticks'] = __ticks
    return ret, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.time = res['time']
    self.flags = res['flags']
    self.source = res['source']
    self.ticks = res['ticks']
    return res, off, length

  @classmethod
  def _payload_size(self):
    ret = 0
    # time: u64
    ret += 8
    # flags: u8
    ret += 1
    # source: u8
    ret += 1
    # ticks: s32
    ret += 4
    return ret
  

msg_classes = {
  0x0903: MsgOdometry,
  0x0904: MsgWheeltick,
}