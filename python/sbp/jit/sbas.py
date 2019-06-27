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
SBAS data
"""

import json

import numpy as np

from sbp.jit.msg import SBP, SENDER_ID
from sbp.jit.msg import get_u8, get_u16, get_u32, get_u64
from sbp.jit.msg import get_s8, get_s16, get_s32, get_s64
from sbp.jit.msg import get_f32, get_f64, judicious_round
from sbp.jit.msg import get_string, get_fixed_string, get_setting
from sbp.jit.msg import get_array, get_fixed_array
from sbp.jit.gnss import *

# Automatically generated from piksi/yaml/swiftnav/sbp/sbas.yaml with generate.py.
# Please do not hand edit!
SBP_MSG_SBAS_RAW = 0x7777
class MsgSbasRaw(SBP):
  """SBP class for message MSG_SBAS_RAW (0x7777).

  You can have MSG_SBAS_RAW inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  This message is sent once per second per SBAS satellite. ME checks the
parity of the data block and sends only blocks that pass the check.


  """
  __slots__ = ['sid',
               'tow',
               'message_type',
               'data',
               ]
  @classmethod
  def parse_members(cls, buf, offset, length):
    ret = {}
    (__sid, offset, length) = GnssSignal.parse_members(buf, offset, length)
    ret['sid'] = __sid
    (__tow, offset, length) = get_u32(buf, offset, length)
    ret['tow'] = __tow
    (__message_type, offset, length) = get_u8(buf, offset, length)
    ret['message_type'] = __message_type
    (__data, offset, length) = get_fixed_array(get_u8, 27, 1)(buf, offset, length)
    ret['data'] = __data
    return ret, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.sid = res['sid']
    self.tow = res['tow']
    self.message_type = res['message_type']
    self.data = res['data']
    return res, off, length

  @classmethod
  def _payload_size(self):
    ret = 0
    # sid: GnssSignal
    ret += GnssSignal._payload_size()
    # tow: u32
    ret += 4
    # message_type: u8
    ret += 1
    # data: array of u8
    ret += 1 * 27
    return ret
  

msg_classes = {
  0x7777: MsgSbasRaw,
}