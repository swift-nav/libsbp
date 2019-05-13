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

import numba as nb
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
          ('recv_time', 'u8'),
          ('event', 'u1'),
          ('object_type', 'u1'),
          ('result', 'u1'),
          ('data_source', 'u1'),
          ('object_sid', GnssSignal._static_dtype()),
          ('src_sid', GnssSignal._static_dtype()),
          ('original_sender', 'u2'),
        ])

    t = getattr(cls, 'static_dtype0', None)
    if not t:
      t = np.dtype([
          ('recv_time', 'u8'),
          ('event', 'u1'),
          ('object_type', 'u1'),
          ('result', 'u1'),
          ('data_source', 'u1'),
          ('object_sid', GnssSignal._static_dtype()),
          ('src_sid', GnssSignal._static_dtype()),
          ('original_sender', 'u2'),
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
      'recv_time': int(res['recv_time'] if element else res['recv_time'][0]),
      'event': int(res['event'] if element else res['event'][0]),
      'object_type': int(res['object_type'] if element else res['object_type'][0]),
      'result': int(res['result'] if element else res['result'][0]),
      'data_source': int(res['data_source'] if element else res['data_source'][0]),
      'object_sid': GnssSignal._unpack_members(res['object_sid'], element=element),
      'src_sid': GnssSignal._unpack_members(res['src_sid'], element=element),
      'original_sender': int(res['original_sender'] if element else res['original_sender'][0]),
    }
    return d

  

msg_classes = {
  0x0400: MsgNdbEvent,
}