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
Various structs shared between modules
"""

import json

import numpy as np

from sbp.jit.msg import SBP, SENDER_ID
from sbp.jit.msg import get_u8, get_u16, get_u32, get_u64
from sbp.jit.msg import get_s8, get_s16, get_s32, get_s64
from sbp.jit.msg import get_f32, get_f64, judicious_round
from sbp.jit.msg import get_string, get_fixed_string, get_setting
from sbp.jit.msg import get_array, get_fixed_array

# Automatically generated from piksi/yaml/swiftnav/sbp/gnss.yaml with generate.py.
# Please do not hand edit!
class GnssSignal(object):
  """SBP class for message GnssSignal

  You can have GnssSignal inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  Signal identifier containing constellation, band, and satellite identifier


  """
  __slots__ = ['sat',
               'code',
               ]
  @classmethod
  def parse_members(cls, buf, offset, length):
    ret = {}
    (__sat, offset, length) = get_u8(buf, offset, length)
    ret['sat'] = __sat
    (__code, offset, length) = get_u8(buf, offset, length)
    ret['code'] = __code
    return ret, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.sat = res['sat']
    self.code = res['code']
    return res, off, length

  @classmethod
  def _payload_size(self):
    ret = 0
    # sat: u8
    ret += 1
    # code: u8
    ret += 1
    return ret
  
class SvId(object):
  """SBP class for message SvId

  You can have SvId inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  A (Constellation ID, satellite ID) tuple that uniquely identifies
a space vehicle


  """
  __slots__ = ['satId',
               'constellation',
               ]
  @classmethod
  def parse_members(cls, buf, offset, length):
    ret = {}
    (__satId, offset, length) = get_u8(buf, offset, length)
    ret['satId'] = __satId
    (__constellation, offset, length) = get_u8(buf, offset, length)
    ret['constellation'] = __constellation
    return ret, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.satId = res['satId']
    self.constellation = res['constellation']
    return res, off, length

  @classmethod
  def _payload_size(self):
    ret = 0
    # satId: u8
    ret += 1
    # constellation: u8
    ret += 1
    return ret
  
class GnssSignalDep(object):
  """SBP class for message GnssSignalDep

  You can have GnssSignalDep inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  Deprecated.

  """
  __slots__ = ['sat',
               'code',
               'reserved',
               ]
  @classmethod
  def parse_members(cls, buf, offset, length):
    ret = {}
    (__sat, offset, length) = get_u16(buf, offset, length)
    ret['sat'] = __sat
    (__code, offset, length) = get_u8(buf, offset, length)
    ret['code'] = __code
    (__reserved, offset, length) = get_u8(buf, offset, length)
    ret['reserved'] = __reserved
    return ret, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.sat = res['sat']
    self.code = res['code']
    self.reserved = res['reserved']
    return res, off, length

  @classmethod
  def _payload_size(self):
    ret = 0
    # sat: u16
    ret += 2
    # code: u8
    ret += 1
    # reserved: u8
    ret += 1
    return ret
  
class GPSTimeDep(object):
  """SBP class for message GPSTimeDep

  You can have GPSTimeDep inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  A wire-appropriate GPS time, defined as the number of
milliseconds since beginning of the week on the Saturday/Sunday
transition.


  """
  __slots__ = ['tow',
               'wn',
               ]
  @classmethod
  def parse_members(cls, buf, offset, length):
    ret = {}
    (__tow, offset, length) = get_u32(buf, offset, length)
    ret['tow'] = __tow
    (__wn, offset, length) = get_u16(buf, offset, length)
    ret['wn'] = __wn
    return ret, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.tow = res['tow']
    self.wn = res['wn']
    return res, off, length

  @classmethod
  def _payload_size(self):
    ret = 0
    # tow: u32
    ret += 4
    # wn: u16
    ret += 2
    return ret
  
class GPSTimeSec(object):
  """SBP class for message GPSTimeSec

  You can have GPSTimeSec inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  A GPS time, defined as the number of
seconds since beginning of the week on the Saturday/Sunday
transition.


  """
  __slots__ = ['tow',
               'wn',
               ]
  @classmethod
  def parse_members(cls, buf, offset, length):
    ret = {}
    (__tow, offset, length) = get_u32(buf, offset, length)
    ret['tow'] = __tow
    (__wn, offset, length) = get_u16(buf, offset, length)
    ret['wn'] = __wn
    return ret, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.tow = res['tow']
    self.wn = res['wn']
    return res, off, length

  @classmethod
  def _payload_size(self):
    ret = 0
    # tow: u32
    ret += 4
    # wn: u16
    ret += 2
    return ret
  
class GPSTime(object):
  """SBP class for message GPSTime

  You can have GPSTime inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  A wire-appropriate receiver clock time, defined as the time
since the beginning of the week on the Saturday/Sunday
transition. In most cases, observations are epoch aligned
so ns field will be 0.


  """
  __slots__ = ['tow',
               'ns_residual',
               'wn',
               ]
  @classmethod
  def parse_members(cls, buf, offset, length):
    ret = {}
    (__tow, offset, length) = get_u32(buf, offset, length)
    ret['tow'] = __tow
    (__ns_residual, offset, length) = get_s32(buf, offset, length)
    ret['ns_residual'] = __ns_residual
    (__wn, offset, length) = get_u16(buf, offset, length)
    ret['wn'] = __wn
    return ret, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.tow = res['tow']
    self.ns_residual = res['ns_residual']
    self.wn = res['wn']
    return res, off, length

  @classmethod
  def _payload_size(self):
    ret = 0
    # tow: u32
    ret += 4
    # ns_residual: s32
    ret += 4
    # wn: u16
    ret += 2
    return ret
  
class CarrierPhase(object):
  """SBP class for message CarrierPhase

  You can have CarrierPhase inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  Carrier phase measurement in cycles represented as a 40-bit
fixed point number with Q32.8 layout, i.e. 32-bits of whole
cycles and 8-bits of fractional cycles. This phase has the
same sign as the pseudorange.


  """
  __slots__ = ['i',
               'f',
               ]
  @classmethod
  def parse_members(cls, buf, offset, length):
    ret = {}
    (__i, offset, length) = get_s32(buf, offset, length)
    ret['i'] = __i
    (__f, offset, length) = get_u8(buf, offset, length)
    ret['f'] = __f
    return ret, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.i = res['i']
    self.f = res['f']
    return res, off, length

  @classmethod
  def _payload_size(self):
    ret = 0
    # i: s32
    ret += 4
    # f: u8
    ret += 1
    return ret
  

msg_classes = {
}