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

from sbp.jit.msg import SBP, SENDER_ID
from sbp.jit.msg import get_u8, get_u16, get_u32, get_u64
from sbp.jit.msg import get_s8, get_s16, get_s32, get_s64
from sbp.jit.msg import get_f32, get_f64
from sbp.jit.msg import get_string, get_fixed_string
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
    o_0 = offset
    o_1, (__cause, offset, length) = offset, get_u8(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__startup_type, offset, length) = offset, get_u8(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__reserved, offset, length) = offset, get_u16(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    return {
      'cause' : __cause,
      'startup_type' : __startup_type,
      'reserved' : __reserved,
    }, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.cause = res['cause']
    self.startup_type = res['startup_type']
    self.reserved = res['reserved']
    return res, off, length
  
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
    o_0 = offset
    o_1, (__flags, offset, length) = offset, get_u8(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__latency, offset, length) = offset, get_u16(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__num_signals, offset, length) = offset, get_u8(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__source, offset, length) = offset, get_string(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    return {
      'flags' : __flags,
      'latency' : __latency,
      'num_signals' : __num_signals,
      'source' : __source,
    }, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.flags = res['flags']
    self.latency = res['latency']
    self.num_signals = res['num_signals']
    self.source = res['source']
    return res, off, length
  
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
    o_0 = offset
    o_1, (__flags, offset, length) = offset, get_u32(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    return {
      'flags' : __flags,
    }, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.flags = res['flags']
    return res, off, length
  
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
    o_0 = offset
    o_1, (__flags, offset, length) = offset, get_u32(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    return {
      'flags' : __flags,
    }, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.flags = res['flags']
    return res, off, length
  
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
    o_0 = offset
    o_1, (__id, offset, length) = offset, get_u8(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__telemetry, offset, length) = offset, get_string(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    return {
      'id' : __id,
      'telemetry' : __telemetry,
    }, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.id = res['id']
    self.telemetry = res['telemetry']
    return res, off, length
  
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
    o_0 = offset
    o_1, (__id, offset, length) = offset, get_u8(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__telemetry_labels, offset, length) = offset, get_string(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    return {
      'id' : __id,
      'telemetry_labels' : __telemetry_labels,
    }, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.id = res['id']
    self.telemetry_labels = res['telemetry_labels']
    return res, off, length
  

msg_classes = {
  0xFF00: MsgStartup,
  0xFF02: MsgDgnssStatus,
  0xFFFF: MsgHeartbeat,
  0xFF03: MsgInsStatus,
  0xFF04: MsgCsacTelemetry,
  0xFF05: MsgCsacTelemetryLabels,
}