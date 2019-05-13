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

import numba as nb
import numpy as np

from sbp.jit.msg import SBP, SENDER_ID
from sbp.jit.msg import get_u8, get_u16, get_u32, get_u64
from sbp.jit.msg import get_s8, get_s16, get_s32, get_s64
from sbp.jit.msg import get_f32, get_f64, judicious_round
from sbp.jit.msg import get_string, get_fixed_string, get_setting
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
          ('wn', 'u2'),
          ('tow', 'u4'),
          ('ns_residual', 'i4'),
          ('flags', 'u1'),
          ('pin', 'u1'),
        ])

    t = getattr(cls, 'static_dtype0', None)
    if not t:
      t = np.dtype([
          ('wn', 'u2'),
          ('tow', 'u4'),
          ('ns_residual', 'i4'),
          ('flags', 'u1'),
          ('pin', 'u1'),
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
      'wn': int(res['wn'] if element else res['wn'][0]),
      'tow': int(res['tow'] if element else res['tow'][0]),
      'ns_residual': int(res['ns_residual'] if element else res['ns_residual'][0]),
      'flags': int(res['flags'] if element else res['flags'][0]),
      'pin': int(res['pin'] if element else res['pin'][0]),
    }
    return d

  

msg_classes = {
  0x0101: MsgExtEvent,
}