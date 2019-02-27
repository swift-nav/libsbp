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
Satellite acquisition messages from the device.
"""

import json

from sbp.jit.msg import SBP, SENDER_ID
from sbp.jit.msg import get_u8, get_u16, get_u32, get_u64
from sbp.jit.msg import get_s8, get_s16, get_s32, get_s64
from sbp.jit.msg import get_f32, get_f64
from sbp.jit.msg import get_string, get_fixed_string
from sbp.jit.msg import get_array, get_fixed_array
from sbp.jit.gnss import *

# Automatically generated from piksi/yaml/swiftnav/sbp/acquisition.yaml with generate.py.
# Please do not hand edit!
SBP_MSG_ACQ_RESULT = 0x002F
class MsgAcqResult(SBP):
  """SBP class for message MSG_ACQ_RESULT (0x002F).

  You can have MSG_ACQ_RESULT inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  This message describes the results from an attempted GPS signal
acquisition search for a satellite PRN over a code phase/carrier
frequency range. It contains the parameters of the point in the
acquisition search space with the best carrier-to-noise (CN/0)
ratio.


  """
  __slots__ = ['cn0',
               'cp',
               'cf',
               'sid',
               ]
  @classmethod
  def parse_members(cls, buf, offset, length):
    o_0 = offset
    o_1, (__cn0, offset, length) = offset, get_f32(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__cp, offset, length) = offset, get_f32(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__cf, offset, length) = offset, get_f32(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__sid, offset, length) = offset, GnssSignal.parse_members(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    return {
      'cn0' : __cn0,
      'cp' : __cp,
      'cf' : __cf,
      'sid' : __sid,
    }, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.cn0 = res['cn0']
    self.cp = res['cp']
    self.cf = res['cf']
    self.sid = res['sid']
    return res, off, length
  
SBP_MSG_ACQ_RESULT_DEP_C = 0x001F
class MsgAcqResultDepC(SBP):
  """SBP class for message MSG_ACQ_RESULT_DEP_C (0x001F).

  You can have MSG_ACQ_RESULT_DEP_C inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  Deprecated.

  """
  __slots__ = ['cn0',
               'cp',
               'cf',
               'sid',
               ]
  @classmethod
  def parse_members(cls, buf, offset, length):
    o_0 = offset
    o_1, (__cn0, offset, length) = offset, get_f32(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__cp, offset, length) = offset, get_f32(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__cf, offset, length) = offset, get_f32(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__sid, offset, length) = offset, GnssSignalDep.parse_members(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    return {
      'cn0' : __cn0,
      'cp' : __cp,
      'cf' : __cf,
      'sid' : __sid,
    }, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.cn0 = res['cn0']
    self.cp = res['cp']
    self.cf = res['cf']
    self.sid = res['sid']
    return res, off, length
  
SBP_MSG_ACQ_RESULT_DEP_B = 0x0014
class MsgAcqResultDepB(SBP):
  """SBP class for message MSG_ACQ_RESULT_DEP_B (0x0014).

  You can have MSG_ACQ_RESULT_DEP_B inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  Deprecated.

  """
  __slots__ = ['snr',
               'cp',
               'cf',
               'sid',
               ]
  @classmethod
  def parse_members(cls, buf, offset, length):
    o_0 = offset
    o_1, (__snr, offset, length) = offset, get_f32(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__cp, offset, length) = offset, get_f32(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__cf, offset, length) = offset, get_f32(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__sid, offset, length) = offset, GnssSignalDep.parse_members(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    return {
      'snr' : __snr,
      'cp' : __cp,
      'cf' : __cf,
      'sid' : __sid,
    }, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.snr = res['snr']
    self.cp = res['cp']
    self.cf = res['cf']
    self.sid = res['sid']
    return res, off, length
  
SBP_MSG_ACQ_RESULT_DEP_A = 0x0015
class MsgAcqResultDepA(SBP):
  """SBP class for message MSG_ACQ_RESULT_DEP_A (0x0015).

  You can have MSG_ACQ_RESULT_DEP_A inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  Deprecated.

  """
  __slots__ = ['snr',
               'cp',
               'cf',
               'prn',
               ]
  @classmethod
  def parse_members(cls, buf, offset, length):
    o_0 = offset
    o_1, (__snr, offset, length) = offset, get_f32(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__cp, offset, length) = offset, get_f32(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__cf, offset, length) = offset, get_f32(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__prn, offset, length) = offset, get_u8(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    return {
      'snr' : __snr,
      'cp' : __cp,
      'cf' : __cf,
      'prn' : __prn,
    }, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.snr = res['snr']
    self.cp = res['cp']
    self.cf = res['cf']
    self.prn = res['prn']
    return res, off, length
  
class AcqSvProfile(object):
  """SBP class for message AcqSvProfile

  You can have AcqSvProfile inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  Profile for a specific SV for debugging purposes
The message describes SV profile during acquisition time.
The message is used to debug and measure the performance.


  """
  __slots__ = ['job_type',
               'status',
               'cn0',
               'int_time',
               'sid',
               'bin_width',
               'timestamp',
               'time_spent',
               'cf_min',
               'cf_max',
               'cf',
               'cp',
               ]
  @classmethod
  def parse_members(cls, buf, offset, length):
    o_0 = offset
    o_1, (__job_type, offset, length) = offset, get_u8(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__status, offset, length) = offset, get_u8(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__cn0, offset, length) = offset, get_u16(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__int_time, offset, length) = offset, get_u8(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__sid, offset, length) = offset, GnssSignal.parse_members(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__bin_width, offset, length) = offset, get_u16(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__timestamp, offset, length) = offset, get_u32(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__time_spent, offset, length) = offset, get_u32(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__cf_min, offset, length) = offset, get_s32(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__cf_max, offset, length) = offset, get_s32(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__cf, offset, length) = offset, get_s32(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__cp, offset, length) = offset, get_u32(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    return {
      'job_type' : __job_type,
      'status' : __status,
      'cn0' : __cn0,
      'int_time' : __int_time,
      'sid' : __sid,
      'bin_width' : __bin_width,
      'timestamp' : __timestamp,
      'time_spent' : __time_spent,
      'cf_min' : __cf_min,
      'cf_max' : __cf_max,
      'cf' : __cf,
      'cp' : __cp,
    }, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.job_type = res['job_type']
    self.status = res['status']
    self.cn0 = res['cn0']
    self.int_time = res['int_time']
    self.sid = res['sid']
    self.bin_width = res['bin_width']
    self.timestamp = res['timestamp']
    self.time_spent = res['time_spent']
    self.cf_min = res['cf_min']
    self.cf_max = res['cf_max']
    self.cf = res['cf']
    self.cp = res['cp']
    return res, off, length
  
class AcqSvProfileDep(object):
  """SBP class for message AcqSvProfileDep

  You can have AcqSvProfileDep inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  Deprecated.

  """
  __slots__ = ['job_type',
               'status',
               'cn0',
               'int_time',
               'sid',
               'bin_width',
               'timestamp',
               'time_spent',
               'cf_min',
               'cf_max',
               'cf',
               'cp',
               ]
  @classmethod
  def parse_members(cls, buf, offset, length):
    o_0 = offset
    o_1, (__job_type, offset, length) = offset, get_u8(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__status, offset, length) = offset, get_u8(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__cn0, offset, length) = offset, get_u16(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__int_time, offset, length) = offset, get_u8(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__sid, offset, length) = offset, GnssSignalDep.parse_members(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__bin_width, offset, length) = offset, get_u16(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__timestamp, offset, length) = offset, get_u32(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__time_spent, offset, length) = offset, get_u32(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__cf_min, offset, length) = offset, get_s32(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__cf_max, offset, length) = offset, get_s32(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__cf, offset, length) = offset, get_s32(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__cp, offset, length) = offset, get_u32(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    return {
      'job_type' : __job_type,
      'status' : __status,
      'cn0' : __cn0,
      'int_time' : __int_time,
      'sid' : __sid,
      'bin_width' : __bin_width,
      'timestamp' : __timestamp,
      'time_spent' : __time_spent,
      'cf_min' : __cf_min,
      'cf_max' : __cf_max,
      'cf' : __cf,
      'cp' : __cp,
    }, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.job_type = res['job_type']
    self.status = res['status']
    self.cn0 = res['cn0']
    self.int_time = res['int_time']
    self.sid = res['sid']
    self.bin_width = res['bin_width']
    self.timestamp = res['timestamp']
    self.time_spent = res['time_spent']
    self.cf_min = res['cf_min']
    self.cf_max = res['cf_max']
    self.cf = res['cf']
    self.cp = res['cp']
    return res, off, length
  
SBP_MSG_ACQ_SV_PROFILE = 0x002E
class MsgAcqSvProfile(SBP):
  """SBP class for message MSG_ACQ_SV_PROFILE (0x002E).

  You can have MSG_ACQ_SV_PROFILE inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  The message describes all SV profiles during acquisition time.
The message is used to debug and measure the performance.


  """
  __slots__ = ['acq_sv_profile',
               ]
  @classmethod
  def parse_members(cls, buf, offset, length):
    o_0 = offset
    o_1, (__acq_sv_profile, offset, length) = offset, get_array(AcqSvProfile.parse_members)(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    return {
      'acq_sv_profile' : __acq_sv_profile,
    }, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.acq_sv_profile = res['acq_sv_profile']
    return res, off, length
  
SBP_MSG_ACQ_SV_PROFILE_DEP = 0x001E
class MsgAcqSvProfileDep(SBP):
  """SBP class for message MSG_ACQ_SV_PROFILE_DEP (0x001E).

  You can have MSG_ACQ_SV_PROFILE_DEP inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  Deprecated.

  """
  __slots__ = ['acq_sv_profile',
               ]
  @classmethod
  def parse_members(cls, buf, offset, length):
    o_0 = offset
    o_1, (__acq_sv_profile, offset, length) = offset, get_array(AcqSvProfileDep.parse_members)(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    return {
      'acq_sv_profile' : __acq_sv_profile,
    }, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.acq_sv_profile = res['acq_sv_profile']
    return res, off, length
  

msg_classes = {
  0x002F: MsgAcqResult,
  0x001F: MsgAcqResultDepC,
  0x0014: MsgAcqResultDepB,
  0x0015: MsgAcqResultDepA,
  0x002E: MsgAcqSvProfile,
  0x001E: MsgAcqSvProfileDep,
}