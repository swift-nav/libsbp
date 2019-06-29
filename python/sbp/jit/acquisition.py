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

import numpy as np

from sbp.jit.msg import SBP, SENDER_ID
from sbp.jit.msg import get_u8, get_u16, get_u32, get_u64
from sbp.jit.msg import get_s8, get_s16, get_s32, get_s64
from sbp.jit.msg import get_f32, get_f64, judicious_round
from sbp.jit.msg import get_string, get_fixed_string, get_setting
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
    ret = {}
    (__cn0, offset, length) = get_f32(buf, offset, length)
    ret['cn0'] = judicious_round(np.float32(__cn0)) if SBP.judicious_rounding else __cn0
    (__cp, offset, length) = get_f32(buf, offset, length)
    ret['cp'] = judicious_round(np.float32(__cp)) if SBP.judicious_rounding else __cp
    (__cf, offset, length) = get_f32(buf, offset, length)
    ret['cf'] = judicious_round(np.float32(__cf)) if SBP.judicious_rounding else __cf
    (__sid, offset, length) = GnssSignal.parse_members(buf, offset, length)
    ret['sid'] = __sid
    return ret, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.cn0 = res['cn0']
    self.cp = res['cp']
    self.cf = res['cf']
    self.sid = res['sid']
    return res, off, length

  @classmethod
  def _payload_size(self):
    ret = 0
    # cn0: float
    ret += 4
    # cp: float
    ret += 4
    # cf: float
    ret += 4
    # sid: GnssSignal
    ret += GnssSignal._payload_size()
    return ret
  
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
    ret = {}
    (__cn0, offset, length) = get_f32(buf, offset, length)
    ret['cn0'] = judicious_round(np.float32(__cn0)) if SBP.judicious_rounding else __cn0
    (__cp, offset, length) = get_f32(buf, offset, length)
    ret['cp'] = judicious_round(np.float32(__cp)) if SBP.judicious_rounding else __cp
    (__cf, offset, length) = get_f32(buf, offset, length)
    ret['cf'] = judicious_round(np.float32(__cf)) if SBP.judicious_rounding else __cf
    (__sid, offset, length) = GnssSignalDep.parse_members(buf, offset, length)
    ret['sid'] = __sid
    return ret, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.cn0 = res['cn0']
    self.cp = res['cp']
    self.cf = res['cf']
    self.sid = res['sid']
    return res, off, length

  @classmethod
  def _payload_size(self):
    ret = 0
    # cn0: float
    ret += 4
    # cp: float
    ret += 4
    # cf: float
    ret += 4
    # sid: GnssSignalDep
    ret += GnssSignalDep._payload_size()
    return ret
  
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
    ret = {}
    (__snr, offset, length) = get_f32(buf, offset, length)
    ret['snr'] = judicious_round(np.float32(__snr)) if SBP.judicious_rounding else __snr
    (__cp, offset, length) = get_f32(buf, offset, length)
    ret['cp'] = judicious_round(np.float32(__cp)) if SBP.judicious_rounding else __cp
    (__cf, offset, length) = get_f32(buf, offset, length)
    ret['cf'] = judicious_round(np.float32(__cf)) if SBP.judicious_rounding else __cf
    (__sid, offset, length) = GnssSignalDep.parse_members(buf, offset, length)
    ret['sid'] = __sid
    return ret, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.snr = res['snr']
    self.cp = res['cp']
    self.cf = res['cf']
    self.sid = res['sid']
    return res, off, length

  @classmethod
  def _payload_size(self):
    ret = 0
    # snr: float
    ret += 4
    # cp: float
    ret += 4
    # cf: float
    ret += 4
    # sid: GnssSignalDep
    ret += GnssSignalDep._payload_size()
    return ret
  
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
    ret = {}
    (__snr, offset, length) = get_f32(buf, offset, length)
    ret['snr'] = judicious_round(np.float32(__snr)) if SBP.judicious_rounding else __snr
    (__cp, offset, length) = get_f32(buf, offset, length)
    ret['cp'] = judicious_round(np.float32(__cp)) if SBP.judicious_rounding else __cp
    (__cf, offset, length) = get_f32(buf, offset, length)
    ret['cf'] = judicious_round(np.float32(__cf)) if SBP.judicious_rounding else __cf
    (__prn, offset, length) = get_u8(buf, offset, length)
    ret['prn'] = __prn
    return ret, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.snr = res['snr']
    self.cp = res['cp']
    self.cf = res['cf']
    self.prn = res['prn']
    return res, off, length

  @classmethod
  def _payload_size(self):
    ret = 0
    # snr: float
    ret += 4
    # cp: float
    ret += 4
    # cf: float
    ret += 4
    # prn: u8
    ret += 1
    return ret
  
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
    ret = {}
    (__job_type, offset, length) = get_u8(buf, offset, length)
    ret['job_type'] = __job_type
    (__status, offset, length) = get_u8(buf, offset, length)
    ret['status'] = __status
    (__cn0, offset, length) = get_u16(buf, offset, length)
    ret['cn0'] = __cn0
    (__int_time, offset, length) = get_u8(buf, offset, length)
    ret['int_time'] = __int_time
    (__sid, offset, length) = GnssSignal.parse_members(buf, offset, length)
    ret['sid'] = __sid
    (__bin_width, offset, length) = get_u16(buf, offset, length)
    ret['bin_width'] = __bin_width
    (__timestamp, offset, length) = get_u32(buf, offset, length)
    ret['timestamp'] = __timestamp
    (__time_spent, offset, length) = get_u32(buf, offset, length)
    ret['time_spent'] = __time_spent
    (__cf_min, offset, length) = get_s32(buf, offset, length)
    ret['cf_min'] = __cf_min
    (__cf_max, offset, length) = get_s32(buf, offset, length)
    ret['cf_max'] = __cf_max
    (__cf, offset, length) = get_s32(buf, offset, length)
    ret['cf'] = __cf
    (__cp, offset, length) = get_u32(buf, offset, length)
    ret['cp'] = __cp
    return ret, offset, length

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

  @classmethod
  def _payload_size(self):
    ret = 0
    # job_type: u8
    ret += 1
    # status: u8
    ret += 1
    # cn0: u16
    ret += 2
    # int_time: u8
    ret += 1
    # sid: GnssSignal
    ret += GnssSignal._payload_size()
    # bin_width: u16
    ret += 2
    # timestamp: u32
    ret += 4
    # time_spent: u32
    ret += 4
    # cf_min: s32
    ret += 4
    # cf_max: s32
    ret += 4
    # cf: s32
    ret += 4
    # cp: u32
    ret += 4
    return ret
  
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
    ret = {}
    (__job_type, offset, length) = get_u8(buf, offset, length)
    ret['job_type'] = __job_type
    (__status, offset, length) = get_u8(buf, offset, length)
    ret['status'] = __status
    (__cn0, offset, length) = get_u16(buf, offset, length)
    ret['cn0'] = __cn0
    (__int_time, offset, length) = get_u8(buf, offset, length)
    ret['int_time'] = __int_time
    (__sid, offset, length) = GnssSignalDep.parse_members(buf, offset, length)
    ret['sid'] = __sid
    (__bin_width, offset, length) = get_u16(buf, offset, length)
    ret['bin_width'] = __bin_width
    (__timestamp, offset, length) = get_u32(buf, offset, length)
    ret['timestamp'] = __timestamp
    (__time_spent, offset, length) = get_u32(buf, offset, length)
    ret['time_spent'] = __time_spent
    (__cf_min, offset, length) = get_s32(buf, offset, length)
    ret['cf_min'] = __cf_min
    (__cf_max, offset, length) = get_s32(buf, offset, length)
    ret['cf_max'] = __cf_max
    (__cf, offset, length) = get_s32(buf, offset, length)
    ret['cf'] = __cf
    (__cp, offset, length) = get_u32(buf, offset, length)
    ret['cp'] = __cp
    return ret, offset, length

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

  @classmethod
  def _payload_size(self):
    ret = 0
    # job_type: u8
    ret += 1
    # status: u8
    ret += 1
    # cn0: u16
    ret += 2
    # int_time: u8
    ret += 1
    # sid: GnssSignalDep
    ret += GnssSignalDep._payload_size()
    # bin_width: u16
    ret += 2
    # timestamp: u32
    ret += 4
    # time_spent: u32
    ret += 4
    # cf_min: s32
    ret += 4
    # cf_max: s32
    ret += 4
    # cf: s32
    ret += 4
    # cp: u32
    ret += 4
    return ret
  
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
    ret = {}
    (__acq_sv_profile, offset, length) = get_array(AcqSvProfile.parse_members)(buf, offset, length)
    ret['acq_sv_profile'] = __acq_sv_profile
    return ret, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.acq_sv_profile = res['acq_sv_profile']
    return res, off, length

  @classmethod
  def _payload_size(self):
    ret = 0
    # acq_sv_profile: array of AcqSvProfile
    ret += 247
    return ret
  
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
    ret = {}
    (__acq_sv_profile, offset, length) = get_array(AcqSvProfileDep.parse_members)(buf, offset, length)
    ret['acq_sv_profile'] = __acq_sv_profile
    return ret, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.acq_sv_profile = res['acq_sv_profile']
    return res, off, length

  @classmethod
  def _payload_size(self):
    ret = 0
    # acq_sv_profile: array of AcqSvProfileDep
    ret += 247
    return ret
  

msg_classes = {
  0x002F: MsgAcqResult,
  0x001F: MsgAcqResultDepC,
  0x0014: MsgAcqResultDepB,
  0x0015: MsgAcqResultDepA,
  0x002E: MsgAcqSvProfile,
  0x001E: MsgAcqSvProfileDep,
}