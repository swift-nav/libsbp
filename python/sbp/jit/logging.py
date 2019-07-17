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
Logging and debugging messages from the device.

"""

import json

import numpy as np

from sbp.jit.msg import SBP, SENDER_ID
from sbp.jit.msg import get_u8, get_u16, get_u32, get_u64
from sbp.jit.msg import get_s8, get_s16, get_s32, get_s64
from sbp.jit.msg import get_f32, get_f64, judicious_round
from sbp.jit.msg import get_string, get_fixed_string, get_setting
from sbp.jit.msg import get_array, get_fixed_array

# Automatically generated from piksi/yaml/swiftnav/sbp/logging.yaml with generate.py.
# Please do not hand edit!
SBP_MSG_LOG = 0x0401
class MsgLog(SBP):
  """SBP class for message MSG_LOG (0x0401).

  You can have MSG_LOG inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  This message contains a human-readable payload string from the
device containing errors, warnings and informational messages at
ERROR, WARNING, DEBUG, INFO logging levels.


  """
  __slots__ = ['level',
               'text',
               ]
  @classmethod
  def parse_members(cls, buf, offset, length):
    ret = {}
    (__level, offset, length) = get_u8(buf, offset, length)
    ret['level'] = __level
    (__text, offset, length) = get_string(buf, offset, length)
    ret['text'] = __text
    return ret, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.level = res['level']
    self.text = res['text']
    return res, off, length

  @classmethod
  def _payload_size(self):
    ret = 0
    # level: u8
    ret += 1
    # text: string
    ret += 247
    return ret
  
SBP_MSG_FWD = 0x0402
class MsgFwd(SBP):
  """SBP class for message MSG_FWD (0x0402).

  You can have MSG_FWD inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  This message provides the ability to forward messages over SBP.  This may take the form
of wrapping up SBP messages received by Piksi for logging purposes or wrapping 
another protocol with SBP.

The source identifier indicates from what interface a forwarded stream derived.
The protocol identifier identifies what the expected protocol the forwarded msg contains.
Protocol 0 represents SBP and the remaining values are implementation defined.


  """
  __slots__ = ['source',
               'protocol',
               'fwd_payload',
               ]
  @classmethod
  def parse_members(cls, buf, offset, length):
    ret = {}
    (__source, offset, length) = get_u8(buf, offset, length)
    ret['source'] = __source
    (__protocol, offset, length) = get_u8(buf, offset, length)
    ret['protocol'] = __protocol
    (__fwd_payload, offset, length) = get_string(buf, offset, length)
    ret['fwd_payload'] = __fwd_payload
    return ret, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.source = res['source']
    self.protocol = res['protocol']
    self.fwd_payload = res['fwd_payload']
    return res, off, length

  @classmethod
  def _payload_size(self):
    ret = 0
    # source: u8
    ret += 1
    # protocol: u8
    ret += 1
    # fwd_payload: string
    ret += 247
    return ret
  
SBP_MSG_PRINT_DEP = 0x0010
class MsgPrintDep(SBP):
  """SBP class for message MSG_PRINT_DEP (0x0010).

  You can have MSG_PRINT_DEP inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  Deprecated.

  """
  __slots__ = ['text',
               ]
  @classmethod
  def parse_members(cls, buf, offset, length):
    ret = {}
    (__text, offset, length) = get_string(buf, offset, length)
    ret['text'] = __text
    return ret, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.text = res['text']
    return res, off, length

  @classmethod
  def _payload_size(self):
    ret = 0
    # text: string
    ret += 247
    return ret
  

msg_classes = {
  0x0401: MsgLog,
  0x0402: MsgFwd,
  0x0010: MsgPrintDep,
}