#!/usr/bin/env python
# Copyright (C) 2015-2021 Swift Navigation Inc.
# Contact: https://support.swiftnav.com
#
# This source is subject to the license found in the file 'LICENSE' which must
# be distributed together with this source. All other rights reserved.
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


class ResourceBucket(object):
  """ResourceBucket.
  
  Information about allocation of various resources grouped by buckets. Refer
  to product documentation to understand the meaning and values in this
  message.
  
  Parameters
  ----------
  name : string
    Bucket name
  thread : int
    Number of threads
  mutex : int
    Number of mutexes
  cv : int
    Number of condition variables
  io : int
    Number of IO handles
  heap_bytes_alloc : int
    Number of bytes allocated on the heap
  heap_bytes_free : int
    Number of bytes freed on the heap
  io_write : int
    Number of bytes written to IO handles
  io_read : int
    Number of bytes read from IO handles

  """
  _parser = construct.Struct(
                     'name'/ construct.Bytes(21),
                     'thread' / construct.Int8ul,
                     'mutex' / construct.Int8ul,
                     'cv' / construct.Int8ul,
                     'io' / construct.Int8ul,
                     'heap_bytes_alloc' / construct.Int32ul,
                     'heap_bytes_free' / construct.Int32ul,
                     'io_write' / construct.Int32ul,
                     'io_read' / construct.Int32ul,)
  __slots__ = [
               'name',
               'thread',
               'mutex',
               'cv',
               'io',
               'heap_bytes_alloc',
               'heap_bytes_free',
               'io_write',
               'io_read',
              ]

  def __init__(self, payload=None, **kwargs):
    if payload:
      self.from_binary(payload)
    else:
      self.name = kwargs.pop('name')
      self.thread = kwargs.pop('thread')
      self.mutex = kwargs.pop('mutex')
      self.cv = kwargs.pop('cv')
      self.io = kwargs.pop('io')
      self.heap_bytes_alloc = kwargs.pop('heap_bytes_alloc')
      self.heap_bytes_free = kwargs.pop('heap_bytes_free')
      self.io_write = kwargs.pop('io_write')
      self.io_read = kwargs.pop('io_read')

  def __repr__(self):
    return fmt_repr(self)
  
  def from_binary(self, d):
    p = ResourceBucket._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))
    
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
    
SBP_MSG_PROFILING_SYSTEM_INFO = 0xCF01
class MsgProfilingSystemInfo(SBP):
  """SBP class for message MSG_PROFILING_SYSTEM_INFO (0xCF01).

  You can have MSG_PROFILING_SYSTEM_INFO inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  Contains basic information about system resource usage. System is defined in
  terms of the source of this message and may vary from  sender to sender.
  Refer to product documentation to understand the exact scope and meaning of
  this message.

  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  total_cpu_time : int
    Total cpu time in microseconds consumed by this system
  age : int
    Age of the producing system in microseconds
  n_threads : int
    Number of threads being tracked by this system
  heap_usage : int
    Number of bytes allocated on the heap
  sender : int
    Optional sender ID, defaults to SENDER_ID (see sbp/msg.py).

  """
  _parser = construct.Struct(
                   'total_cpu_time' / construct.Int64ul,
                   'age' / construct.Int64ul,
                   'n_threads' / construct.Int8ul,
                   'heap_usage' / construct.Int32ul,)
  __slots__ = [
               'total_cpu_time',
               'age',
               'n_threads',
               'heap_usage',
              ]

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      super( MsgProfilingSystemInfo,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.from_binary(sbp.payload)
    else:
      super( MsgProfilingSystemInfo, self).__init__()
      self.msg_type = SBP_MSG_PROFILING_SYSTEM_INFO
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.total_cpu_time = kwargs.pop('total_cpu_time')
      self.age = kwargs.pop('age')
      self.n_threads = kwargs.pop('n_threads')
      self.heap_usage = kwargs.pop('heap_usage')

  def __repr__(self):
    return fmt_repr(self)

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    return MsgProfilingSystemInfo.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgProfilingSystemInfo(sbp, **d)

 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgProfilingSystemInfo._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgProfilingSystemInfo._parser.build(c)
    return self.pack()

  def friendly_name(self):
    """Produces friendly human-readable name for this message

    """
    return "PROFILING SYSTEM INFO"

  def into_buffer(self, buf, offset):
    """Produce a framed/packed SBP message into the provided buffer and offset.

    """
    self.payload = containerize(exclude_fields(self))
    self.parser = MsgProfilingSystemInfo._parser
    self.stream_payload.reset(buf, offset)
    return self.pack_into(buf, offset, self._build_payload)

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgProfilingSystemInfo, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    
SBP_MSG_PROFILING_THREAD_INFO = 0xCF02
class MsgProfilingThreadInfo(SBP):
  """SBP class for message MSG_PROFILING_THREAD_INFO (0xCF02).

  You can have MSG_PROFILING_THREAD_INFO inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  Contains profiling information related to a single thread being tracked by
  the producing system. Refer to product documentation to understand the exact
  scope and meaning of this message.

  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  total_cpu_time : int
    Total cpu time in microseconds consumed by this thread
  age : int
    Age of the thread in microseconds
  state : int
    Thread state
  stack_size : int
    Stack size in bytes
  stack_usage : int
    Stack high water usage in bytes
  name : string
    Thread name
  sender : int
    Optional sender ID, defaults to SENDER_ID (see sbp/msg.py).

  """
  _parser = construct.Struct(
                   'total_cpu_time' / construct.Int64ul,
                   'age' / construct.Int64ul,
                   'state' / construct.Int8ul,
                   'stack_size' / construct.Int32ul,
                   'stack_usage' / construct.Int32ul,
                   'name' / construct.GreedyBytes,)
  __slots__ = [
               'total_cpu_time',
               'age',
               'state',
               'stack_size',
               'stack_usage',
               'name',
              ]

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      super( MsgProfilingThreadInfo,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.from_binary(sbp.payload)
    else:
      super( MsgProfilingThreadInfo, self).__init__()
      self.msg_type = SBP_MSG_PROFILING_THREAD_INFO
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.total_cpu_time = kwargs.pop('total_cpu_time')
      self.age = kwargs.pop('age')
      self.state = kwargs.pop('state')
      self.stack_size = kwargs.pop('stack_size')
      self.stack_usage = kwargs.pop('stack_usage')
      self.name = kwargs.pop('name')

  def __repr__(self):
    return fmt_repr(self)

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    return MsgProfilingThreadInfo.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgProfilingThreadInfo(sbp, **d)

 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgProfilingThreadInfo._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgProfilingThreadInfo._parser.build(c)
    return self.pack()

  def friendly_name(self):
    """Produces friendly human-readable name for this message

    """
    return "PROFILING THREAD INFO"

  def into_buffer(self, buf, offset):
    """Produce a framed/packed SBP message into the provided buffer and offset.

    """
    self.payload = containerize(exclude_fields(self))
    self.parser = MsgProfilingThreadInfo._parser
    self.stream_payload.reset(buf, offset)
    return self.pack_into(buf, offset, self._build_payload)

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgProfilingThreadInfo, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    
SBP_MSG_PROFILING_RESOURCE_COUNTER = 0xCF03
class MsgProfilingResourceCounter(SBP):
  """SBP class for message MSG_PROFILING_RESOURCE_COUNTER (0xCF03).

  You can have MSG_PROFILING_RESOURCE_COUNTER inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  Information about resource buckets. Refer to product documentation to
  understand the meaning and values in this message.

  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  seq_no : int
    Message number in complete sequence
  seq_len : int
    Length of message sequence
  buckets : array
    List of resource buckets
  sender : int
    Optional sender ID, defaults to SENDER_ID (see sbp/msg.py).

  """
  _parser = construct.Struct(
                   'seq_no' / construct.Int8ul,
                   'seq_len' / construct.Int8ul,
                   'buckets' / construct.GreedyRange(ResourceBucket._parser),)
  __slots__ = [
               'seq_no',
               'seq_len',
               'buckets',
              ]

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      super( MsgProfilingResourceCounter,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.from_binary(sbp.payload)
    else:
      super( MsgProfilingResourceCounter, self).__init__()
      self.msg_type = SBP_MSG_PROFILING_RESOURCE_COUNTER
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.seq_no = kwargs.pop('seq_no')
      self.seq_len = kwargs.pop('seq_len')
      self.buckets = kwargs.pop('buckets')

  def __repr__(self):
    return fmt_repr(self)

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    return MsgProfilingResourceCounter.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgProfilingResourceCounter(sbp, **d)

 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgProfilingResourceCounter._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgProfilingResourceCounter._parser.build(c)
    return self.pack()

  def friendly_name(self):
    """Produces friendly human-readable name for this message

    """
    return "PROFILING RESOURCE COUNTER"

  def into_buffer(self, buf, offset):
    """Produce a framed/packed SBP message into the provided buffer and offset.

    """
    self.payload = containerize(exclude_fields(self))
    self.parser = MsgProfilingResourceCounter._parser
    self.stream_payload.reset(buf, offset)
    return self.pack_into(buf, offset, self._build_payload)

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgProfilingResourceCounter, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    

msg_classes = {
  0xCF00: MsgMeasurementPoint,
  0xCF01: MsgProfilingSystemInfo,
  0xCF02: MsgProfilingThreadInfo,
  0xCF03: MsgProfilingResourceCounter,
}