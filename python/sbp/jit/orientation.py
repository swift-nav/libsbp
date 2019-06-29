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
  @classmethod
  def parse_members(cls, buf, offset, length):
    ret = {}
    (__tow, offset, length) = get_u32(buf, offset, length)
    ret['tow'] = __tow
    (__heading, offset, length) = get_u32(buf, offset, length)
    ret['heading'] = __heading
    (__n_sats, offset, length) = get_u8(buf, offset, length)
    ret['n_sats'] = __n_sats
    (__flags, offset, length) = get_u8(buf, offset, length)
    ret['flags'] = __flags
    return ret, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.tow = res['tow']
    self.heading = res['heading']
    self.n_sats = res['n_sats']
    self.flags = res['flags']
    return res, off, length

  @classmethod
  def _payload_size(self):
    ret = 0
    # tow: u32
    ret += 4
    # heading: u32
    ret += 4
    # n_sats: u8
    ret += 1
    # flags: u8
    ret += 1
    return ret
  
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
  @classmethod
  def parse_members(cls, buf, offset, length):
    ret = {}
    (__tow, offset, length) = get_u32(buf, offset, length)
    ret['tow'] = __tow
    (__w, offset, length) = get_s32(buf, offset, length)
    ret['w'] = __w
    (__x, offset, length) = get_s32(buf, offset, length)
    ret['x'] = __x
    (__y, offset, length) = get_s32(buf, offset, length)
    ret['y'] = __y
    (__z, offset, length) = get_s32(buf, offset, length)
    ret['z'] = __z
    (__w_accuracy, offset, length) = get_f32(buf, offset, length)
    ret['w_accuracy'] = judicious_round(np.float32(__w_accuracy)) if SBP.judicious_rounding else __w_accuracy
    (__x_accuracy, offset, length) = get_f32(buf, offset, length)
    ret['x_accuracy'] = judicious_round(np.float32(__x_accuracy)) if SBP.judicious_rounding else __x_accuracy
    (__y_accuracy, offset, length) = get_f32(buf, offset, length)
    ret['y_accuracy'] = judicious_round(np.float32(__y_accuracy)) if SBP.judicious_rounding else __y_accuracy
    (__z_accuracy, offset, length) = get_f32(buf, offset, length)
    ret['z_accuracy'] = judicious_round(np.float32(__z_accuracy)) if SBP.judicious_rounding else __z_accuracy
    (__flags, offset, length) = get_u8(buf, offset, length)
    ret['flags'] = __flags
    return ret, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.tow = res['tow']
    self.w = res['w']
    self.x = res['x']
    self.y = res['y']
    self.z = res['z']
    self.w_accuracy = res['w_accuracy']
    self.x_accuracy = res['x_accuracy']
    self.y_accuracy = res['y_accuracy']
    self.z_accuracy = res['z_accuracy']
    self.flags = res['flags']
    return res, off, length

  @classmethod
  def _payload_size(self):
    ret = 0
    # tow: u32
    ret += 4
    # w: s32
    ret += 4
    # x: s32
    ret += 4
    # y: s32
    ret += 4
    # z: s32
    ret += 4
    # w_accuracy: float
    ret += 4
    # x_accuracy: float
    ret += 4
    # y_accuracy: float
    ret += 4
    # z_accuracy: float
    ret += 4
    # flags: u8
    ret += 1
    return ret
  
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
  @classmethod
  def parse_members(cls, buf, offset, length):
    ret = {}
    (__tow, offset, length) = get_u32(buf, offset, length)
    ret['tow'] = __tow
    (__roll, offset, length) = get_s32(buf, offset, length)
    ret['roll'] = __roll
    (__pitch, offset, length) = get_s32(buf, offset, length)
    ret['pitch'] = __pitch
    (__yaw, offset, length) = get_s32(buf, offset, length)
    ret['yaw'] = __yaw
    (__roll_accuracy, offset, length) = get_f32(buf, offset, length)
    ret['roll_accuracy'] = judicious_round(np.float32(__roll_accuracy)) if SBP.judicious_rounding else __roll_accuracy
    (__pitch_accuracy, offset, length) = get_f32(buf, offset, length)
    ret['pitch_accuracy'] = judicious_round(np.float32(__pitch_accuracy)) if SBP.judicious_rounding else __pitch_accuracy
    (__yaw_accuracy, offset, length) = get_f32(buf, offset, length)
    ret['yaw_accuracy'] = judicious_round(np.float32(__yaw_accuracy)) if SBP.judicious_rounding else __yaw_accuracy
    (__flags, offset, length) = get_u8(buf, offset, length)
    ret['flags'] = __flags
    return ret, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.tow = res['tow']
    self.roll = res['roll']
    self.pitch = res['pitch']
    self.yaw = res['yaw']
    self.roll_accuracy = res['roll_accuracy']
    self.pitch_accuracy = res['pitch_accuracy']
    self.yaw_accuracy = res['yaw_accuracy']
    self.flags = res['flags']
    return res, off, length

  @classmethod
  def _payload_size(self):
    ret = 0
    # tow: u32
    ret += 4
    # roll: s32
    ret += 4
    # pitch: s32
    ret += 4
    # yaw: s32
    ret += 4
    # roll_accuracy: float
    ret += 4
    # pitch_accuracy: float
    ret += 4
    # yaw_accuracy: float
    ret += 4
    # flags: u8
    ret += 1
    return ret
  
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
  @classmethod
  def parse_members(cls, buf, offset, length):
    ret = {}
    (__tow, offset, length) = get_u32(buf, offset, length)
    ret['tow'] = __tow
    (__x, offset, length) = get_s32(buf, offset, length)
    ret['x'] = __x
    (__y, offset, length) = get_s32(buf, offset, length)
    ret['y'] = __y
    (__z, offset, length) = get_s32(buf, offset, length)
    ret['z'] = __z
    (__flags, offset, length) = get_u8(buf, offset, length)
    ret['flags'] = __flags
    return ret, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.tow = res['tow']
    self.x = res['x']
    self.y = res['y']
    self.z = res['z']
    self.flags = res['flags']
    return res, off, length

  @classmethod
  def _payload_size(self):
    ret = 0
    # tow: u32
    ret += 4
    # x: s32
    ret += 4
    # y: s32
    ret += 4
    # z: s32
    ret += 4
    # flags: u8
    ret += 1
    return ret
  

msg_classes = {
  0x020F: MsgBaselineHeading,
  0x0220: MsgOrientQuat,
  0x0221: MsgOrientEuler,
  0x0222: MsgAngularRate,
}