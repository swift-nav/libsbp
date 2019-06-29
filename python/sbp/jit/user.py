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
Messages reserved for use by the user.

"""

import json

import numpy as np

from sbp.jit.msg import SBP, SENDER_ID
from sbp.jit.msg import get_u8, get_u16, get_u32, get_u64
from sbp.jit.msg import get_s8, get_s16, get_s32, get_s64
from sbp.jit.msg import get_f32, get_f64, judicious_round
from sbp.jit.msg import get_string, get_fixed_string, get_setting
from sbp.jit.msg import get_array, get_fixed_array

# Automatically generated from piksi/yaml/swiftnav/sbp/user.yaml with generate.py.
# Please do not hand edit!
SBP_MSG_USER_DATA = 0x0800
class MsgUserData(SBP):
  """SBP class for message MSG_USER_DATA (0x0800).

  You can have MSG_USER_DATA inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  This message can contain any application specific user data up to a
maximum length of 255 bytes per message.


  """
  __slots__ = ['contents',
               ]
  @classmethod
  def parse_members(cls, buf, offset, length):
    ret = {}
    (__contents, offset, length) = get_array(get_u8)(buf, offset, length)
    ret['contents'] = __contents
    return ret, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.contents = res['contents']
    return res, off, length

  @classmethod
  def _payload_size(self):
    ret = 0
    # contents: array of u8
    ret += 247
    return ret
  

msg_classes = {
  0x0800: MsgUserData,
}