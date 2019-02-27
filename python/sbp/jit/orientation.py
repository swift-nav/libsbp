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

from sbp.jit.msg import SBP, SENDER_ID
from sbp.jit.msg import get_u8, get_u16, get_u32, get_u64
from sbp.jit.msg import get_s8, get_s16, get_s32, get_s64
from sbp.jit.msg import get_f32, get_f64
from sbp.jit.msg import get_string, get_fixed_string
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
    o_0 = offset
    o_1, (__tow, offset, length) = offset, get_u32(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__heading, offset, length) = offset, get_u32(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__n_sats, offset, length) = offset, get_u8(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__flags, offset, length) = offset, get_u8(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    return {
      'tow' : __tow,
      'heading' : __heading,
      'n_sats' : __n_sats,
      'flags' : __flags,
    }, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.tow = res['tow']
    self.heading = res['heading']
    self.n_sats = res['n_sats']
    self.flags = res['flags']
    return res, off, length
  
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
    o_0 = offset
    o_1, (__tow, offset, length) = offset, get_u32(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__w, offset, length) = offset, get_s32(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__x, offset, length) = offset, get_s32(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__y, offset, length) = offset, get_s32(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__z, offset, length) = offset, get_s32(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__w_accuracy, offset, length) = offset, get_f32(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__x_accuracy, offset, length) = offset, get_f32(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__y_accuracy, offset, length) = offset, get_f32(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__z_accuracy, offset, length) = offset, get_f32(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__flags, offset, length) = offset, get_u8(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    return {
      'tow' : __tow,
      'w' : __w,
      'x' : __x,
      'y' : __y,
      'z' : __z,
      'w_accuracy' : __w_accuracy,
      'x_accuracy' : __x_accuracy,
      'y_accuracy' : __y_accuracy,
      'z_accuracy' : __z_accuracy,
      'flags' : __flags,
    }, offset, length

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
    o_0 = offset
    o_1, (__tow, offset, length) = offset, get_u32(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__roll, offset, length) = offset, get_s32(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__pitch, offset, length) = offset, get_s32(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__yaw, offset, length) = offset, get_s32(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__roll_accuracy, offset, length) = offset, get_f32(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__pitch_accuracy, offset, length) = offset, get_f32(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__yaw_accuracy, offset, length) = offset, get_f32(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__flags, offset, length) = offset, get_u8(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    return {
      'tow' : __tow,
      'roll' : __roll,
      'pitch' : __pitch,
      'yaw' : __yaw,
      'roll_accuracy' : __roll_accuracy,
      'pitch_accuracy' : __pitch_accuracy,
      'yaw_accuracy' : __yaw_accuracy,
      'flags' : __flags,
    }, offset, length

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
    o_0 = offset
    o_1, (__tow, offset, length) = offset, get_u32(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__x, offset, length) = offset, get_s32(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__y, offset, length) = offset, get_s32(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__z, offset, length) = offset, get_s32(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__flags, offset, length) = offset, get_u8(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    return {
      'tow' : __tow,
      'x' : __x,
      'y' : __y,
      'z' : __z,
      'flags' : __flags,
    }, offset, length

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
  

msg_classes = {
  0x020F: MsgBaselineHeading,
  0x0220: MsgOrientQuat,
  0x0221: MsgOrientEuler,
  0x0222: MsgAngularRate,
}