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

from sbp.jit.msg import SBP, SENDER_ID
from sbp.jit.msg import get_u8, get_u16, get_u32, get_u64
from sbp.jit.msg import get_s8, get_s16, get_s32, get_s64
from sbp.jit.msg import get_f32, get_f64
from sbp.jit.msg import get_string, get_fixed_string
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
    o_0 = offset
    o_1, (__tow, offset, length) = offset, get_u32(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__velocity, offset, length) = offset, get_s32(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__flags, offset, length) = offset, get_u8(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    return {
      'tow' : __tow,
      'velocity' : __velocity,
      'flags' : __flags,
    }, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.tow = res['tow']
    self.velocity = res['velocity']
    self.flags = res['flags']
    return res, off, length
  

msg_classes = {
  0x0903: MsgOdometry,
}