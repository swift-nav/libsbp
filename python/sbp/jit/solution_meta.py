#!/usr/bin/env python
# Copyright (C) 2015-2018 Swift Navigation Inc.
# Contact: https://support.swiftnav.com
#
# This source is subject to the license found in the file 'LICENSE' which must
# be be distributed together with this source. All other rights reserved.
#
# THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
# EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
# WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.


"""
Standardized Metadata messages for Fuzed Solution from Swift Navigation devices.
"""

import json

import numpy as np

from sbp.jit.msg import SBP, SENDER_ID
from sbp.jit.msg import get_u8, get_u16, get_u32, get_u64
from sbp.jit.msg import get_s8, get_s16, get_s32, get_s64
from sbp.jit.msg import get_f32, get_f64, judicious_round
from sbp.jit.msg import get_string, get_fixed_string, get_setting
from sbp.jit.msg import get_array, get_fixed_array

# Automatically generated from piksi/yaml/swiftnav/sbp/solution_meta.yaml with generate.py.
# Please do not hand edit!
class SolutionInputType(object):
  """SBP class for message SolutionInputType

  You can have SolutionInputType inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  Metadata describing which sensors were involved in the solution.
The structure is fixed no matter what the actual sensor type is.
The sensor_type field tells you which sensor we are talking about. It also tells you
whether the sensor data was actually used or not.
The flags field, always a u8, contains the sensor-specific data.
The content of flags, for each sensor type, is described in the relevant structures in this section.


  """
  __slots__ = ['sensor_type',
               'flags',
               ]
  @classmethod
  def parse_members(cls, buf, offset, length):
    ret = {}
    (__sensor_type, offset, length) = get_u8(buf, offset, length)
    ret['sensor_type'] = __sensor_type
    (__flags, offset, length) = get_u8(buf, offset, length)
    ret['flags'] = __flags
    return ret, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.sensor_type = res['sensor_type']
    self.flags = res['flags']
    return res, off, length

  
SBP_MSG_SOLN_META_DEP_A = 0xFF0F
class MsgSolnMetaDepA(SBP):
  """SBP class for message MSG_SOLN_META_DEP_A (0xFF0F).

  You can have MSG_SOLN_META_DEP_A inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  This message contains all metadata about the sensors received and/or used in computing the Fuzed Solution.
It focuses primarly, but not only, on GNSS metadata.


  """
  __slots__ = ['pdop',
               'hdop',
               'vdop',
               'n_sats',
               'age_corrections',
               'alignment_status',
               'last_used_gnss_pos_tow',
               'last_used_gnss_vel_tow',
               'sol_in',
               ]
  @classmethod
  def parse_members(cls, buf, offset, length):
    ret = {}
    (__pdop, offset, length) = get_u16(buf, offset, length)
    ret['pdop'] = __pdop
    (__hdop, offset, length) = get_u16(buf, offset, length)
    ret['hdop'] = __hdop
    (__vdop, offset, length) = get_u16(buf, offset, length)
    ret['vdop'] = __vdop
    (__n_sats, offset, length) = get_u8(buf, offset, length)
    ret['n_sats'] = __n_sats
    (__age_corrections, offset, length) = get_u16(buf, offset, length)
    ret['age_corrections'] = __age_corrections
    (__alignment_status, offset, length) = get_u8(buf, offset, length)
    ret['alignment_status'] = __alignment_status
    (__last_used_gnss_pos_tow, offset, length) = get_u32(buf, offset, length)
    ret['last_used_gnss_pos_tow'] = __last_used_gnss_pos_tow
    (__last_used_gnss_vel_tow, offset, length) = get_u32(buf, offset, length)
    ret['last_used_gnss_vel_tow'] = __last_used_gnss_vel_tow
    (__sol_in, offset, length) = get_array(SolutionInputType.parse_members)(buf, offset, length)
    ret['sol_in'] = __sol_in
    return ret, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.pdop = res['pdop']
    self.hdop = res['hdop']
    self.vdop = res['vdop']
    self.n_sats = res['n_sats']
    self.age_corrections = res['age_corrections']
    self.alignment_status = res['alignment_status']
    self.last_used_gnss_pos_tow = res['last_used_gnss_pos_tow']
    self.last_used_gnss_vel_tow = res['last_used_gnss_vel_tow']
    self.sol_in = res['sol_in']
    return res, off, length

  
SBP_MSG_SOLN_META = 0xFF0E
class MsgSolnMeta(SBP):
  """SBP class for message MSG_SOLN_META (0xFF0E).

  You can have MSG_SOLN_META inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  This message contains all metadata about the sensors received and/or used in computing the sensorfusion solution.
It focuses primarly, but not only, on GNSS metadata.


  """
  __slots__ = ['tow',
               'pdop',
               'hdop',
               'vdop',
               'age_corrections',
               'age_gnss',
               'sol_in',
               ]
  @classmethod
  def parse_members(cls, buf, offset, length):
    ret = {}
    (__tow, offset, length) = get_u32(buf, offset, length)
    ret['tow'] = __tow
    (__pdop, offset, length) = get_u16(buf, offset, length)
    ret['pdop'] = __pdop
    (__hdop, offset, length) = get_u16(buf, offset, length)
    ret['hdop'] = __hdop
    (__vdop, offset, length) = get_u16(buf, offset, length)
    ret['vdop'] = __vdop
    (__age_corrections, offset, length) = get_u16(buf, offset, length)
    ret['age_corrections'] = __age_corrections
    (__age_gnss, offset, length) = get_u32(buf, offset, length)
    ret['age_gnss'] = __age_gnss
    (__sol_in, offset, length) = get_array(SolutionInputType.parse_members)(buf, offset, length)
    ret['sol_in'] = __sol_in
    return ret, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.tow = res['tow']
    self.pdop = res['pdop']
    self.hdop = res['hdop']
    self.vdop = res['vdop']
    self.age_corrections = res['age_corrections']
    self.age_gnss = res['age_gnss']
    self.sol_in = res['sol_in']
    return res, off, length

  
class GNSSInputType(object):
  """SBP class for message GNSSInputType

  You can have GNSSInputType inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  Metadata around the GNSS sensors involved in the fuzed solution.
Accessible through sol_in[N].flags in a MSG_SOLN_META.


  """
  __slots__ = ['flags',
               ]
  @classmethod
  def parse_members(cls, buf, offset, length):
    ret = {}
    (__flags, offset, length) = get_u8(buf, offset, length)
    ret['flags'] = __flags
    return ret, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.flags = res['flags']
    return res, off, length

  
class IMUInputType(object):
  """SBP class for message IMUInputType

  You can have IMUInputType inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  Metadata around the IMU sensors involved in the fuzed solution.
Accessible through sol_in[N].flags in a MSG_SOLN_META.


  """
  __slots__ = ['flags',
               ]
  @classmethod
  def parse_members(cls, buf, offset, length):
    ret = {}
    (__flags, offset, length) = get_u8(buf, offset, length)
    ret['flags'] = __flags
    return ret, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.flags = res['flags']
    return res, off, length

  
class OdoInputType(object):
  """SBP class for message OdoInputType

  You can have OdoInputType inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  Metadata around the Odometry sensors involved in the fuzed solution.
Accessible through sol_in[N].flags in a MSG_SOLN_META.


  """
  __slots__ = ['flags',
               ]
  @classmethod
  def parse_members(cls, buf, offset, length):
    ret = {}
    (__flags, offset, length) = get_u8(buf, offset, length)
    ret['flags'] = __flags
    return ret, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.flags = res['flags']
    return res, off, length

  

msg_classes = {
  0xFF0F: MsgSolnMetaDepA,
  0xFF0E: MsgSolnMeta,
}