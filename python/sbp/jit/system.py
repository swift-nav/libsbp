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
Standardized system messages from Swift Navigation devices.
"""

import json

import numpy as np

from sbp.jit.msg import SBP, SENDER_ID
from sbp.jit.msg import get_u8, get_u16, get_u32, get_u64
from sbp.jit.msg import get_s8, get_s16, get_s32, get_s64
from sbp.jit.msg import get_f32, get_f64, judicious_round
from sbp.jit.msg import get_string, get_fixed_string, get_setting
from sbp.jit.msg import get_array, get_fixed_array

# Automatically generated from piksi/yaml/swiftnav/sbp/system.yaml with generate.py.
# Please do not hand edit!
SBP_MSG_STARTUP = 0xFF00
class MsgStartup(SBP):
  """SBP class for message MSG_STARTUP (0xFF00).

  You can have MSG_STARTUP inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  The system start-up message is sent once on system
start-up. It notifies the host or other attached devices that
the system has started and is now ready to respond to commands
or configuration requests.


  """
  __slots__ = ['cause',
               'startup_type',
               'reserved',
               ]
  @classmethod
  def parse_members(cls, buf, offset, length):
    ret = {}
    (__cause, offset, length) = get_u8(buf, offset, length)
    ret['cause'] = __cause
    (__startup_type, offset, length) = get_u8(buf, offset, length)
    ret['startup_type'] = __startup_type
    (__reserved, offset, length) = get_u16(buf, offset, length)
    ret['reserved'] = __reserved
    return ret, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.cause = res['cause']
    self.startup_type = res['startup_type']
    self.reserved = res['reserved']
    return res, off, length

  @classmethod
  def _payload_size(self):
    ret = 0
    # cause: u8
    ret += 1
    # startup_type: u8
    ret += 1
    # reserved: u16
    ret += 2
    return ret
  
SBP_MSG_DGNSS_STATUS = 0xFF02
class MsgDgnssStatus(SBP):
  """SBP class for message MSG_DGNSS_STATUS (0xFF02).

  You can have MSG_DGNSS_STATUS inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  This message provides information about the receipt of Differential
corrections.  It is expected to be sent with each receipt of a complete
corrections packet.


  """
  __slots__ = ['flags',
               'latency',
               'num_signals',
               'source',
               ]
  @classmethod
  def parse_members(cls, buf, offset, length):
    ret = {}
    (__flags, offset, length) = get_u8(buf, offset, length)
    ret['flags'] = __flags
    (__latency, offset, length) = get_u16(buf, offset, length)
    ret['latency'] = __latency
    (__num_signals, offset, length) = get_u8(buf, offset, length)
    ret['num_signals'] = __num_signals
    (__source, offset, length) = get_string(buf, offset, length)
    ret['source'] = __source
    return ret, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.flags = res['flags']
    self.latency = res['latency']
    self.num_signals = res['num_signals']
    self.source = res['source']
    return res, off, length

  @classmethod
  def _payload_size(self):
    ret = 0
    # flags: u8
    ret += 1
    # latency: u16
    ret += 2
    # num_signals: u8
    ret += 1
    # source: string
    ret += 247
    return ret
  
SBP_MSG_HEARTBEAT = 0xFFFF
class MsgHeartbeat(SBP):
  """SBP class for message MSG_HEARTBEAT (0xFFFF).

  You can have MSG_HEARTBEAT inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  The heartbeat message is sent periodically to inform the host
or other attached devices that the system is running. It is
used to monitor system malfunctions. It also contains status
flags that indicate to the host the status of the system and
whether it is operating correctly. Currently, the expected
heartbeat interval is 1 sec.

The system error flag is used to indicate that an error has
occurred in the system. To determine the source of the error,
the remaining error flags should be inspected.


  """
  __slots__ = ['flags',
               ]
  @classmethod
  def parse_members(cls, buf, offset, length):
    ret = {}
    (__flags, offset, length) = get_u32(buf, offset, length)
    ret['flags'] = __flags
    return ret, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.flags = res['flags']
    return res, off, length

  @classmethod
  def _payload_size(self):
    ret = 0
    # flags: u32
    ret += 4
    return ret
  
SBP_MSG_INS_STATUS = 0xFF03
class MsgInsStatus(SBP):
  """SBP class for message MSG_INS_STATUS (0xFF03).

  You can have MSG_INS_STATUS inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  The INS status message describes the state of the operation
and initialization of the inertial navigation system. 


  """
  __slots__ = ['flags',
               ]
  @classmethod
  def parse_members(cls, buf, offset, length):
    ret = {}
    (__flags, offset, length) = get_u32(buf, offset, length)
    ret['flags'] = __flags
    return ret, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.flags = res['flags']
    return res, off, length

  @classmethod
  def _payload_size(self):
    ret = 0
    # flags: u32
    ret += 4
    return ret
  
SBP_MSG_CSAC_TELEMETRY = 0xFF04
class MsgCsacTelemetry(SBP):
  """SBP class for message MSG_CSAC_TELEMETRY (0xFF04).

  You can have MSG_CSAC_TELEMETRY inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  The CSAC telemetry message has an implementation defined telemetry string
from a device. It is not produced or available on general Swift Products.
It is intended to be a low rate message for status purposes.


  """
  __slots__ = ['id',
               'telemetry',
               ]
  @classmethod
  def parse_members(cls, buf, offset, length):
    ret = {}
    (__id, offset, length) = get_u8(buf, offset, length)
    ret['id'] = __id
    (__telemetry, offset, length) = get_string(buf, offset, length)
    ret['telemetry'] = __telemetry
    return ret, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.id = res['id']
    self.telemetry = res['telemetry']
    return res, off, length

  @classmethod
  def _payload_size(self):
    ret = 0
    # id: u8
    ret += 1
    # telemetry: string
    ret += 247
    return ret
  
SBP_MSG_CSAC_TELEMETRY_LABELS = 0xFF05
class MsgCsacTelemetryLabels(SBP):
  """SBP class for message MSG_CSAC_TELEMETRY_LABELS (0xFF05).

  You can have MSG_CSAC_TELEMETRY_LABELS inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  The CSAC telemetry message provides labels for each member of the string
produced by MSG_CSAC_TELEMETRY. It should be provided by a device at a lower
rate than the MSG_CSAC_TELEMETRY.


  """
  __slots__ = ['id',
               'telemetry_labels',
               ]
  @classmethod
  def parse_members(cls, buf, offset, length):
    ret = {}
    (__id, offset, length) = get_u8(buf, offset, length)
    ret['id'] = __id
    (__telemetry_labels, offset, length) = get_string(buf, offset, length)
    ret['telemetry_labels'] = __telemetry_labels
    return ret, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.id = res['id']
    self.telemetry_labels = res['telemetry_labels']
    return res, off, length

  @classmethod
  def _payload_size(self):
    ret = 0
    # id: u8
    ret += 1
    # telemetry_labels: string
    ret += 247
    return ret
  
SBP_MSG_INS_UPDATES = 0xFF06
class MsgInsUpdates(SBP):
  """SBP class for message MSG_INS_UPDATES (0xFF06).

  You can have MSG_INS_UPDATES inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  The INS update status message contains informations about executed and rejected INS updates.
This message is expected to be extended in the future as new types of measurements are being added.


  """
  __slots__ = ['tow',
               'gnsspos',
               'gnssvel',
               'wheelticks',
               'speed',
               'nhc',
               'zerovel',
               ]
  @classmethod
  def parse_members(cls, buf, offset, length):
    ret = {}
    (__tow, offset, length) = get_u32(buf, offset, length)
    ret['tow'] = __tow
    (__gnsspos, offset, length) = get_u8(buf, offset, length)
    ret['gnsspos'] = __gnsspos
    (__gnssvel, offset, length) = get_u8(buf, offset, length)
    ret['gnssvel'] = __gnssvel
    (__wheelticks, offset, length) = get_u8(buf, offset, length)
    ret['wheelticks'] = __wheelticks
    (__speed, offset, length) = get_u8(buf, offset, length)
    ret['speed'] = __speed
    (__nhc, offset, length) = get_u8(buf, offset, length)
    ret['nhc'] = __nhc
    (__zerovel, offset, length) = get_u8(buf, offset, length)
    ret['zerovel'] = __zerovel
    return ret, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.tow = res['tow']
    self.gnsspos = res['gnsspos']
    self.gnssvel = res['gnssvel']
    self.wheelticks = res['wheelticks']
    self.speed = res['speed']
    self.nhc = res['nhc']
    self.zerovel = res['zerovel']
    return res, off, length

  @classmethod
  def _payload_size(self):
    ret = 0
    # tow: u32
    ret += 4
    # gnsspos: u8
    ret += 1
    # gnssvel: u8
    ret += 1
    # wheelticks: u8
    ret += 1
    # speed: u8
    ret += 1
    # nhc: u8
    ret += 1
    # zerovel: u8
    ret += 1
    return ret
  

msg_classes = {
  0xFF00: MsgStartup,
  0xFF02: MsgDgnssStatus,
  0xFFFF: MsgHeartbeat,
  0xFF03: MsgInsStatus,
  0xFF04: MsgCsacTelemetry,
  0xFF05: MsgCsacTelemetryLabels,
  0xFF06: MsgInsUpdates,
}