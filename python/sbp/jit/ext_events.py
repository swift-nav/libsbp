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
Messages reporting accurately-timestamped external events,
e.g. camera shutter time.

"""

import json

from sbp.jit.msg import SBP, SENDER_ID
from sbp.jit.msg import get_u8, get_u16, get_u32, get_u64
from sbp.jit.msg import get_s8, get_s16, get_s32, get_s64
from sbp.jit.msg import get_f32, get_f64
from sbp.jit.msg import get_string, get_fixed_string
from sbp.jit.msg import get_array, get_fixed_array

# Automatically generated from piksi/yaml/swiftnav/sbp/ext_events.yaml with generate.py.
# Please do not hand edit!
SBP_MSG_EXT_EVENT = 0x0101
class MsgExtEvent(SBP):
  """SBP class for message MSG_EXT_EVENT (0x0101).

  You can have MSG_EXT_EVENT inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  Reports detection of an external event, the GPS time it occurred,
which pin it was and whether it was rising or falling.


  """
  __slots__ = ['wn',
               'tow',
               'ns_residual',
               'flags',
               'pin',
               ]
  @classmethod
  def parse_members(cls, buf, offset, length):
    o_0 = offset
    o_1, (__wn, offset, length) = offset, get_u16(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__tow, offset, length) = offset, get_u32(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__ns_residual, offset, length) = offset, get_s32(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__flags, offset, length) = offset, get_u8(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__pin, offset, length) = offset, get_u8(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    return {
      'wn' : __wn,
      'tow' : __tow,
      'ns_residual' : __ns_residual,
      'flags' : __flags,
      'pin' : __pin,
    }, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.wn = res['wn']
    self.tow = res['tow']
    self.ns_residual = res['ns_residual']
    self.flags = res['flags']
    self.pin = res['pin']
    return res, off, length
  

msg_classes = {
  0x0101: MsgExtEvent,
}