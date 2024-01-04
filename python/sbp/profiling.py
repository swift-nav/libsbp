#!/usr/bin/env python
# Copyright (C) 2015-2021 Swift Navigation Inc.
# Contact: https://support.swiftnav.com
#
# This source is subject to the license found in the file 'LICENSE' which must
# be be distributed together with this source. All other rights reserved.
#
# THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
# EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
# WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.


"""
Standardized profiling messages from Swift Navigation devices.
"""

import json

import construct

from sbp.msg import SBP, SENDER_ID
from sbp.utils import fmt_repr, exclude_fields, walk_json_dict, containerize

# Automatically generated from piksi/yaml/swiftnav/sbp/profiling.yaml with generate.py.
# Please do not hand edit!


SBP_MSG_MEASUREMENT_POINT = 0xCF00
class MsgMeasurementPoint(SBP):
  """SBP class for message MSG_MEASUREMENT_POINT (0xCF00).

  You can have MSG_MEASUREMENT_POINT inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  Tracks execution time of certain code paths in specially built products.
  This message should only be expected and processed on the direction of
  Swift's engineering teams.

  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  total_time : int
    Total time spent in measurement point (microseconds)
  num_executions : int
    Number of times measurement point has executed
  min : int
    Minimum execution time (microseconds)
  max : int
    Maximum execution time (microseconds)
  return_addr : int
    Return address
  id : int
    Unique ID
  slice_time : int
    CPU slice time (milliseconds)
  line : int
    Line number
  func : string
    Function name
  sender : int
    Optional sender ID, defaults to SENDER_ID (see sbp/msg.py).

  """
  _parser = construct.Struct(
                   'total_time' / construct.Int32ul,
                   'num_executions' / construct.Int16ul,
                   'min' / construct.Int32ul,
                   'max' / construct.Int32ul,
                   'return_addr' / construct.Int64ul,
                   'id' / construct.Int64ul,
                   'slice_time' / construct.Int64ul,
                   'line' / construct.Int16ul,
                   'func' / construct.GreedyBytes,)
  __slots__ = [
               'total_time',
               'num_executions',
               'min',
               'max',
               'return_addr',
               'id',
               'slice_time',
               'line',
               'func',
              ]

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      super( MsgMeasurementPoint,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.from_binary(sbp.payload)
    else:
      super( MsgMeasurementPoint, self).__init__()
      self.msg_type = SBP_MSG_MEASUREMENT_POINT
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.total_time = kwargs.pop('total_time')
      self.num_executions = kwargs.pop('num_executions')
      self.min = kwargs.pop('min')
      self.max = kwargs.pop('max')
      self.return_addr = kwargs.pop('return_addr')
      self.id = kwargs.pop('id')
      self.slice_time = kwargs.pop('slice_time')
      self.line = kwargs.pop('line')
      self.func = kwargs.pop('func')

  def __repr__(self):
    return fmt_repr(self)

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    return MsgMeasurementPoint.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgMeasurementPoint(sbp, **d)

 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgMeasurementPoint._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgMeasurementPoint._parser.build(c)
    return self.pack()

  def friendly_name(self):
    """Produces friendly human-readable name for this message

    """
    return "MEAS POINT"

  def into_buffer(self, buf, offset):
    """Produce a framed/packed SBP message into the provided buffer and offset.

    """
    self.payload = containerize(exclude_fields(self))
    self.parser = MsgMeasurementPoint._parser
    self.stream_payload.reset(buf, offset)
    return self.pack_into(buf, offset, self._build_payload)

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgMeasurementPoint, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    

msg_classes = {
  0xCF00: MsgMeasurementPoint,
}