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
Messages for logging NDB events.

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

# Automatically generated from piksi/yaml/swiftnav/sbp/ndb.yaml with generate.py.
# Please do not hand edit!
SBP_MSG_NDB_EVENT = 0x0400
class MsgNdbEvent(SBP):
  """SBP class for message MSG_NDB_EVENT (0x0400).

  You can have MSG_NDB_EVENT inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  This message is sent out when an object is stored into NDB. If needed
message could also be sent out when fetching an object from NDB.


  """
  __slots__ = ['recv_time',
               'event',
               'object_type',
               'result',
               'data_source',
               'object_sid',
               'src_sid',
               'original_sender',
               ]
  @classmethod
  def parse_members(cls, buf, offset, length):
    ret = {}
    (__recv_time, offset, length) = get_u64(buf, offset, length)
    ret['recv_time'] = __recv_time
    (__event, offset, length) = get_u8(buf, offset, length)
    ret['event'] = __event
    (__object_type, offset, length) = get_u8(buf, offset, length)
    ret['object_type'] = __object_type
    (__result, offset, length) = get_u8(buf, offset, length)
    ret['result'] = __result
    (__data_source, offset, length) = get_u8(buf, offset, length)
    ret['data_source'] = __data_source
    (__object_sid, offset, length) = GnssSignal.parse_members(buf, offset, length)
    ret['object_sid'] = __object_sid
    (__src_sid, offset, length) = GnssSignal.parse_members(buf, offset, length)
    ret['src_sid'] = __src_sid
    (__original_sender, offset, length) = get_u16(buf, offset, length)
    ret['original_sender'] = __original_sender
    return ret, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.recv_time = res['recv_time']
    self.event = res['event']
    self.object_type = res['object_type']
    self.result = res['result']
    self.data_source = res['data_source']
    self.object_sid = res['object_sid']
    self.src_sid = res['src_sid']
    self.original_sender = res['original_sender']
    return res, off, length

  @classmethod
  def _payload_size(self):
    ret = 0
    # recv_time: u64
    ret += 8
    # event: u8
    ret += 1
    # object_type: u8
    ret += 1
    # result: u8
    ret += 1
    # data_source: u8
    ret += 1
    # object_sid: GnssSignal
    ret += GnssSignal._payload_size()
    # src_sid: GnssSignal
    ret += GnssSignal._payload_size()
    # original_sender: u16
    ret += 2
    return ret
  

msg_classes = {
  0x0400: MsgNdbEvent,
}