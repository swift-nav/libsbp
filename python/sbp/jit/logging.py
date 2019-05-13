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

import numba as nb
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
          ('level', 'u1'),
          ('text', '|S{}'.format(count)),
        ])

    t = getattr(cls, 'static_dtype0', None)
    if not t:
      t = np.dtype([
          ('level', 'u1'),
          ('text', '|S{}'.format(count)),
        ])
      cls.static_dtype0 = t
    return t

  @classmethod
  def _dynamic_dtype(cls):
    t = getattr(cls, 'dynamic_dtype', None)
    if not t:    
      t = np.dtype('u1')
      cls.dynamic_dtype = t
    return t

  @staticmethod
  def _unpack_members(res, element=False):
    d = {
      'level': int(res['level'] if element else res['level'][0]),
      'text': '' if res['text'] is None else res['text'].tostring().decode('ascii'),
    }
    return d

  
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
          ('source', 'u1'),
          ('protocol', 'u1'),
          ('fwd_payload', '|S{}'.format(count)),
        ])

    t = getattr(cls, 'static_dtype0', None)
    if not t:
      t = np.dtype([
          ('source', 'u1'),
          ('protocol', 'u1'),
          ('fwd_payload', '|S{}'.format(count)),
        ])
      cls.static_dtype0 = t
    return t

  @classmethod
  def _dynamic_dtype(cls):
    t = getattr(cls, 'dynamic_dtype', None)
    if not t:    
      t = np.dtype('u1')
      cls.dynamic_dtype = t
    return t

  @staticmethod
  def _unpack_members(res, element=False):
    d = {
      'source': int(res['source'] if element else res['source'][0]),
      'protocol': int(res['protocol'] if element else res['protocol'][0]),
      'fwd_payload': '' if res['fwd_payload'] is None else res['fwd_payload'].tostring().decode('ascii'),
    }
    return d

  
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
          ('text', '|S{}'.format(count)),
        ])

    t = getattr(cls, 'static_dtype0', None)
    if not t:
      t = np.dtype([
          ('text', '|S{}'.format(count)),
        ])
      cls.static_dtype0 = t
    return t

  @classmethod
  def _dynamic_dtype(cls):
    t = getattr(cls, 'dynamic_dtype', None)
    if not t:    
      t = np.dtype('u1')
      cls.dynamic_dtype = t
    return t

  @staticmethod
  def _unpack_members(res, element=False):
    d = {
      'text': '' if res['text'] is None else res['text'].tostring().decode('ascii'),
    }
    return d

  

msg_classes = {
  0x0401: MsgLog,
  0x0402: MsgFwd,
  0x0010: MsgPrintDep,
}