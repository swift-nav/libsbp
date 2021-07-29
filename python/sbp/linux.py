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
Linux state monitoring.
"""

import json

import construct

from sbp.msg import SBP, SENDER_ID
from sbp.utils import fmt_repr, exclude_fields, walk_json_dict, containerize

# Automatically generated from piksi/yaml/swiftnav/sbp/linux.yaml with generate.py.
# Please do not hand edit!


SBP_MSG_LINUX_CPU_STATE_DEP_A = 0x7F00
class MsgLinuxCpuStateDepA(SBP):
  """SBP class for message MSG_LINUX_CPU_STATE_DEP_A (0x7F00).

  You can have MSG_LINUX_CPU_STATE_DEP_A inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  This message indicates the process state of the top 10 heaviest consumers of
  CPU on the system.

  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  index : int
    sequence of this status message, values from 0-9
  pid : int
    the PID of the process
  pcpu : int
    percent of cpu used, expressed as a fraction of 256
  tname : string
    fixed length string representing the thread name
  cmdline : string
    the command line (as much as it fits in the remaining packet)
  sender : int
    Optional sender ID, defaults to SENDER_ID (see sbp/msg.py).

  """
  _parser = construct.Struct(
                   'index' / construct.Int8ul,
                   'pid' / construct.Int16ul,
                   'pcpu' / construct.Int8ul,
                   'tname'/ construct.Bytes(15),
                   'cmdline' / construct.GreedyBytes,)
  __slots__ = [
               'index',
               'pid',
               'pcpu',
               'tname',
               'cmdline',
              ]

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      super( MsgLinuxCpuStateDepA,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.from_binary(sbp.payload)
    else:
      super( MsgLinuxCpuStateDepA, self).__init__()
      self.msg_type = SBP_MSG_LINUX_CPU_STATE_DEP_A
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.index = kwargs.pop('index')
      self.pid = kwargs.pop('pid')
      self.pcpu = kwargs.pop('pcpu')
      self.tname = kwargs.pop('tname')
      self.cmdline = kwargs.pop('cmdline')

  def __repr__(self):
    return fmt_repr(self)

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    return MsgLinuxCpuStateDepA.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgLinuxCpuStateDepA(sbp, **d)

 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgLinuxCpuStateDepA._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgLinuxCpuStateDepA._parser.build(c)
    return self.pack()

  def into_buffer(self, buf, offset):
    """Produce a framed/packed SBP message into the provided buffer and offset.

    """
    self.payload = containerize(exclude_fields(self))
    self.parser = MsgLinuxCpuStateDepA._parser
    self.stream_payload.reset(buf, offset)
    return self.pack_into(buf, offset, self._build_payload)

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgLinuxCpuStateDepA, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    
SBP_MSG_LINUX_MEM_STATE_DEP_A = 0x7F01
class MsgLinuxMemStateDepA(SBP):
  """SBP class for message MSG_LINUX_MEM_STATE_DEP_A (0x7F01).

  You can have MSG_LINUX_MEM_STATE_DEP_A inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  This message indicates the process state of the top 10 heaviest consumers of
  memory on the system.

  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  index : int
    sequence of this status message, values from 0-9
  pid : int
    the PID of the process
  pmem : int
    percent of memory used, expressed as a fraction of 256
  tname : string
    fixed length string representing the thread name
  cmdline : string
    the command line (as much as it fits in the remaining packet)
  sender : int
    Optional sender ID, defaults to SENDER_ID (see sbp/msg.py).

  """
  _parser = construct.Struct(
                   'index' / construct.Int8ul,
                   'pid' / construct.Int16ul,
                   'pmem' / construct.Int8ul,
                   'tname'/ construct.Bytes(15),
                   'cmdline' / construct.GreedyBytes,)
  __slots__ = [
               'index',
               'pid',
               'pmem',
               'tname',
               'cmdline',
              ]

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      super( MsgLinuxMemStateDepA,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.from_binary(sbp.payload)
    else:
      super( MsgLinuxMemStateDepA, self).__init__()
      self.msg_type = SBP_MSG_LINUX_MEM_STATE_DEP_A
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.index = kwargs.pop('index')
      self.pid = kwargs.pop('pid')
      self.pmem = kwargs.pop('pmem')
      self.tname = kwargs.pop('tname')
      self.cmdline = kwargs.pop('cmdline')

  def __repr__(self):
    return fmt_repr(self)

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    return MsgLinuxMemStateDepA.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgLinuxMemStateDepA(sbp, **d)

 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgLinuxMemStateDepA._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgLinuxMemStateDepA._parser.build(c)
    return self.pack()

  def into_buffer(self, buf, offset):
    """Produce a framed/packed SBP message into the provided buffer and offset.

    """
    self.payload = containerize(exclude_fields(self))
    self.parser = MsgLinuxMemStateDepA._parser
    self.stream_payload.reset(buf, offset)
    return self.pack_into(buf, offset, self._build_payload)

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgLinuxMemStateDepA, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    
SBP_MSG_LINUX_SYS_STATE_DEP_A = 0x7F02
class MsgLinuxSysStateDepA(SBP):
  """SBP class for message MSG_LINUX_SYS_STATE_DEP_A (0x7F02).

  You can have MSG_LINUX_SYS_STATE_DEP_A inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  This presents a summary of CPU and memory utilization.

  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  mem_total : int
    total system memory
  pcpu : int
    percent of total cpu currently utilized
  pmem : int
    percent of total memory currently utilized
  procs_starting : int
    number of processes that started during collection phase
  procs_stopping : int
    number of processes that stopped during collection phase
  pid_count : int
    the count of processes on the system
  sender : int
    Optional sender ID, defaults to SENDER_ID (see sbp/msg.py).

  """
  _parser = construct.Struct(
                   'mem_total' / construct.Int16ul,
                   'pcpu' / construct.Int8ul,
                   'pmem' / construct.Int8ul,
                   'procs_starting' / construct.Int16ul,
                   'procs_stopping' / construct.Int16ul,
                   'pid_count' / construct.Int16ul,)
  __slots__ = [
               'mem_total',
               'pcpu',
               'pmem',
               'procs_starting',
               'procs_stopping',
               'pid_count',
              ]

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      super( MsgLinuxSysStateDepA,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.from_binary(sbp.payload)
    else:
      super( MsgLinuxSysStateDepA, self).__init__()
      self.msg_type = SBP_MSG_LINUX_SYS_STATE_DEP_A
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.mem_total = kwargs.pop('mem_total')
      self.pcpu = kwargs.pop('pcpu')
      self.pmem = kwargs.pop('pmem')
      self.procs_starting = kwargs.pop('procs_starting')
      self.procs_stopping = kwargs.pop('procs_stopping')
      self.pid_count = kwargs.pop('pid_count')

  def __repr__(self):
    return fmt_repr(self)

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    return MsgLinuxSysStateDepA.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgLinuxSysStateDepA(sbp, **d)

 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgLinuxSysStateDepA._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgLinuxSysStateDepA._parser.build(c)
    return self.pack()

  def into_buffer(self, buf, offset):
    """Produce a framed/packed SBP message into the provided buffer and offset.

    """
    self.payload = containerize(exclude_fields(self))
    self.parser = MsgLinuxSysStateDepA._parser
    self.stream_payload.reset(buf, offset)
    return self.pack_into(buf, offset, self._build_payload)

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgLinuxSysStateDepA, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    
SBP_MSG_LINUX_PROCESS_SOCKET_COUNTS = 0x7F03
class MsgLinuxProcessSocketCounts(SBP):
  """SBP class for message MSG_LINUX_PROCESS_SOCKET_COUNTS (0x7F03).

  You can have MSG_LINUX_PROCESS_SOCKET_COUNTS inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  Top 10 list of processes with high socket counts.

  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  index : int
    sequence of this status message, values from 0-9
  pid : int
    the PID of the process in question
  socket_count : int
    the number of sockets the process is using
  socket_types : int
    A bitfield indicating the socket types used: 0x1 (tcp), 0x2 (udp), 0x4
    (unix stream), 0x8 (unix dgram), 0x10 (netlink), and 0x8000 (unknown)
  socket_states : int
    A bitfield indicating the socket states: 0x1 (established), 0x2 (syn-
    sent), 0x4 (syn-recv), 0x8 (fin-wait-1), 0x10 (fin-wait-2), 0x20 (time-
    wait), 0x40 (closed), 0x80 (close-wait), 0x100 (last-ack), 0x200 (listen),
    0x400 (closing), 0x800 (unconnected), and 0x8000 (unknown)
  cmdline : string
    the command line of the process in question
  sender : int
    Optional sender ID, defaults to SENDER_ID (see sbp/msg.py).

  """
  _parser = construct.Struct(
                   'index' / construct.Int8ul,
                   'pid' / construct.Int16ul,
                   'socket_count' / construct.Int16ul,
                   'socket_types' / construct.Int16ul,
                   'socket_states' / construct.Int16ul,
                   'cmdline' / construct.GreedyBytes,)
  __slots__ = [
               'index',
               'pid',
               'socket_count',
               'socket_types',
               'socket_states',
               'cmdline',
              ]

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      super( MsgLinuxProcessSocketCounts,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.from_binary(sbp.payload)
    else:
      super( MsgLinuxProcessSocketCounts, self).__init__()
      self.msg_type = SBP_MSG_LINUX_PROCESS_SOCKET_COUNTS
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.index = kwargs.pop('index')
      self.pid = kwargs.pop('pid')
      self.socket_count = kwargs.pop('socket_count')
      self.socket_types = kwargs.pop('socket_types')
      self.socket_states = kwargs.pop('socket_states')
      self.cmdline = kwargs.pop('cmdline')

  def __repr__(self):
    return fmt_repr(self)

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    return MsgLinuxProcessSocketCounts.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgLinuxProcessSocketCounts(sbp, **d)

 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgLinuxProcessSocketCounts._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgLinuxProcessSocketCounts._parser.build(c)
    return self.pack()

  def into_buffer(self, buf, offset):
    """Produce a framed/packed SBP message into the provided buffer and offset.

    """
    self.payload = containerize(exclude_fields(self))
    self.parser = MsgLinuxProcessSocketCounts._parser
    self.stream_payload.reset(buf, offset)
    return self.pack_into(buf, offset, self._build_payload)

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgLinuxProcessSocketCounts, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    
SBP_MSG_LINUX_PROCESS_SOCKET_QUEUES = 0x7F04
class MsgLinuxProcessSocketQueues(SBP):
  """SBP class for message MSG_LINUX_PROCESS_SOCKET_QUEUES (0x7F04).

  You can have MSG_LINUX_PROCESS_SOCKET_QUEUES inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  Top 10 list of sockets with deep queues.

  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  index : int
    sequence of this status message, values from 0-9
  pid : int
    the PID of the process in question
  recv_queued : int
    the total amount of receive data queued for this process
  send_queued : int
    the total amount of send data queued for this process
  socket_types : int
    A bitfield indicating the socket types used: 0x1 (tcp), 0x2 (udp), 0x4
    (unix stream), 0x8 (unix dgram), 0x10 (netlink), and 0x8000 (unknown)
  socket_states : int
    A bitfield indicating the socket states: 0x1 (established), 0x2 (syn-
    sent), 0x4 (syn-recv), 0x8 (fin-wait-1), 0x10 (fin-wait-2), 0x20 (time-
    wait), 0x40 (closed), 0x80 (close-wait), 0x100 (last-ack), 0x200 (listen),
    0x400 (closing), 0x800 (unconnected), and 0x8000 (unknown)
  address_of_largest : string
    Address of the largest queue, remote or local depending on the
    directionality of the connection.
  cmdline : string
    the command line of the process in question
  sender : int
    Optional sender ID, defaults to SENDER_ID (see sbp/msg.py).

  """
  _parser = construct.Struct(
                   'index' / construct.Int8ul,
                   'pid' / construct.Int16ul,
                   'recv_queued' / construct.Int16ul,
                   'send_queued' / construct.Int16ul,
                   'socket_types' / construct.Int16ul,
                   'socket_states' / construct.Int16ul,
                   'address_of_largest'/ construct.Bytes(64),
                   'cmdline' / construct.GreedyBytes,)
  __slots__ = [
               'index',
               'pid',
               'recv_queued',
               'send_queued',
               'socket_types',
               'socket_states',
               'address_of_largest',
               'cmdline',
              ]

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      super( MsgLinuxProcessSocketQueues,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.from_binary(sbp.payload)
    else:
      super( MsgLinuxProcessSocketQueues, self).__init__()
      self.msg_type = SBP_MSG_LINUX_PROCESS_SOCKET_QUEUES
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.index = kwargs.pop('index')
      self.pid = kwargs.pop('pid')
      self.recv_queued = kwargs.pop('recv_queued')
      self.send_queued = kwargs.pop('send_queued')
      self.socket_types = kwargs.pop('socket_types')
      self.socket_states = kwargs.pop('socket_states')
      self.address_of_largest = kwargs.pop('address_of_largest')
      self.cmdline = kwargs.pop('cmdline')

  def __repr__(self):
    return fmt_repr(self)

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    return MsgLinuxProcessSocketQueues.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgLinuxProcessSocketQueues(sbp, **d)

 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgLinuxProcessSocketQueues._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgLinuxProcessSocketQueues._parser.build(c)
    return self.pack()

  def into_buffer(self, buf, offset):
    """Produce a framed/packed SBP message into the provided buffer and offset.

    """
    self.payload = containerize(exclude_fields(self))
    self.parser = MsgLinuxProcessSocketQueues._parser
    self.stream_payload.reset(buf, offset)
    return self.pack_into(buf, offset, self._build_payload)

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgLinuxProcessSocketQueues, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    
SBP_MSG_LINUX_SOCKET_USAGE = 0x7F05
class MsgLinuxSocketUsage(SBP):
  """SBP class for message MSG_LINUX_SOCKET_USAGE (0x7F05).

  You can have MSG_LINUX_SOCKET_USAGE inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  Summaries the socket usage across the system.

  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  avg_queue_depth : int
    average socket queue depths across all sockets on the system
  max_queue_depth : int
    the max queue depth seen within the reporting period
  socket_state_counts : array
    A count for each socket type reported in the `socket_types_reported`
    field, the first entry corresponds to the first enabled bit in
    `types_reported`.
  socket_type_counts : array
    A count for each socket type reported in the `socket_types_reported`
    field, the first entry corresponds to the first enabled bit in
    `types_reported`.
  sender : int
    Optional sender ID, defaults to SENDER_ID (see sbp/msg.py).

  """
  _parser = construct.Struct(
                   'avg_queue_depth' / construct.Int32ul,
                   'max_queue_depth' / construct.Int32ul,
                   'socket_state_counts' / construct.Array(16, construct.Int16ul),
                   'socket_type_counts' / construct.Array(16, construct.Int16ul),)
  __slots__ = [
               'avg_queue_depth',
               'max_queue_depth',
               'socket_state_counts',
               'socket_type_counts',
              ]

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      super( MsgLinuxSocketUsage,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.from_binary(sbp.payload)
    else:
      super( MsgLinuxSocketUsage, self).__init__()
      self.msg_type = SBP_MSG_LINUX_SOCKET_USAGE
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.avg_queue_depth = kwargs.pop('avg_queue_depth')
      self.max_queue_depth = kwargs.pop('max_queue_depth')
      self.socket_state_counts = kwargs.pop('socket_state_counts')
      self.socket_type_counts = kwargs.pop('socket_type_counts')

  def __repr__(self):
    return fmt_repr(self)

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    return MsgLinuxSocketUsage.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgLinuxSocketUsage(sbp, **d)

 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgLinuxSocketUsage._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgLinuxSocketUsage._parser.build(c)
    return self.pack()

  def into_buffer(self, buf, offset):
    """Produce a framed/packed SBP message into the provided buffer and offset.

    """
    self.payload = containerize(exclude_fields(self))
    self.parser = MsgLinuxSocketUsage._parser
    self.stream_payload.reset(buf, offset)
    return self.pack_into(buf, offset, self._build_payload)

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgLinuxSocketUsage, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    
SBP_MSG_LINUX_PROCESS_FD_COUNT = 0x7F06
class MsgLinuxProcessFdCount(SBP):
  """SBP class for message MSG_LINUX_PROCESS_FD_COUNT (0x7F06).

  You can have MSG_LINUX_PROCESS_FD_COUNT inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  Top 10 list of processes with a large number of open file descriptors.

  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  index : int
    sequence of this status message, values from 0-9
  pid : int
    the PID of the process in question
  fd_count : int
    a count of the number of file descriptors opened by the process
  cmdline : string
    the command line of the process in question
  sender : int
    Optional sender ID, defaults to SENDER_ID (see sbp/msg.py).

  """
  _parser = construct.Struct(
                   'index' / construct.Int8ul,
                   'pid' / construct.Int16ul,
                   'fd_count' / construct.Int16ul,
                   'cmdline' / construct.GreedyBytes,)
  __slots__ = [
               'index',
               'pid',
               'fd_count',
               'cmdline',
              ]

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      super( MsgLinuxProcessFdCount,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.from_binary(sbp.payload)
    else:
      super( MsgLinuxProcessFdCount, self).__init__()
      self.msg_type = SBP_MSG_LINUX_PROCESS_FD_COUNT
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.index = kwargs.pop('index')
      self.pid = kwargs.pop('pid')
      self.fd_count = kwargs.pop('fd_count')
      self.cmdline = kwargs.pop('cmdline')

  def __repr__(self):
    return fmt_repr(self)

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    return MsgLinuxProcessFdCount.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgLinuxProcessFdCount(sbp, **d)

 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgLinuxProcessFdCount._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgLinuxProcessFdCount._parser.build(c)
    return self.pack()

  def into_buffer(self, buf, offset):
    """Produce a framed/packed SBP message into the provided buffer and offset.

    """
    self.payload = containerize(exclude_fields(self))
    self.parser = MsgLinuxProcessFdCount._parser
    self.stream_payload.reset(buf, offset)
    return self.pack_into(buf, offset, self._build_payload)

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgLinuxProcessFdCount, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    
SBP_MSG_LINUX_PROCESS_FD_SUMMARY = 0x7F07
class MsgLinuxProcessFdSummary(SBP):
  r"""SBP class for message MSG_LINUX_PROCESS_FD_SUMMARY (0x7F07).

  You can have MSG_LINUX_PROCESS_FD_SUMMARY inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  Summary of open file descriptors on the system.

  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  sys_fd_count : int
    count of total FDs open on the system
  most_opened : string
    A null delimited list of strings which alternates between a string
    representation of the process count and the file name whose count it being
    reported.  That is, in C string syntax
    "32\0/var/log/syslog\012\0/tmp/foo\0" with the end of the list being 2
    NULL terminators in a row.
  sender : int
    Optional sender ID, defaults to SENDER_ID (see sbp/msg.py).

  """
  _parser = construct.Struct(
                   'sys_fd_count' / construct.Int32ul,
                   'most_opened' / construct.GreedyBytes,)
  __slots__ = [
               'sys_fd_count',
               'most_opened',
              ]

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      super( MsgLinuxProcessFdSummary,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.from_binary(sbp.payload)
    else:
      super( MsgLinuxProcessFdSummary, self).__init__()
      self.msg_type = SBP_MSG_LINUX_PROCESS_FD_SUMMARY
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.sys_fd_count = kwargs.pop('sys_fd_count')
      self.most_opened = kwargs.pop('most_opened')

  def __repr__(self):
    return fmt_repr(self)

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    return MsgLinuxProcessFdSummary.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgLinuxProcessFdSummary(sbp, **d)

 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgLinuxProcessFdSummary._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgLinuxProcessFdSummary._parser.build(c)
    return self.pack()

  def into_buffer(self, buf, offset):
    """Produce a framed/packed SBP message into the provided buffer and offset.

    """
    self.payload = containerize(exclude_fields(self))
    self.parser = MsgLinuxProcessFdSummary._parser
    self.stream_payload.reset(buf, offset)
    return self.pack_into(buf, offset, self._build_payload)

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgLinuxProcessFdSummary, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    
SBP_MSG_LINUX_CPU_STATE = 0x7F08
class MsgLinuxCpuState(SBP):
  """SBP class for message MSG_LINUX_CPU_STATE (0x7F08).

  You can have MSG_LINUX_CPU_STATE inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  This message indicates the process state of the top 10 heaviest consumers of
  CPU on the system, including a timestamp.

  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  index : int
    sequence of this status message, values from 0-9
  pid : int
    the PID of the process
  pcpu : int
    percent of CPU used, expressed as a fraction of 256
  time : int
    timestamp of message, refer to flags field for how to interpret
  flags : int
    flags
  tname : string
    fixed length string representing the thread name
  cmdline : string
    the command line (as much as it fits in the remaining packet)
  sender : int
    Optional sender ID, defaults to SENDER_ID (see sbp/msg.py).

  """
  _parser = construct.Struct(
                   'index' / construct.Int8ul,
                   'pid' / construct.Int16ul,
                   'pcpu' / construct.Int8ul,
                   'time' / construct.Int32ul,
                   'flags' / construct.Int8ul,
                   'tname'/ construct.Bytes(15),
                   'cmdline' / construct.GreedyBytes,)
  __slots__ = [
               'index',
               'pid',
               'pcpu',
               'time',
               'flags',
               'tname',
               'cmdline',
              ]

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      super( MsgLinuxCpuState,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.from_binary(sbp.payload)
    else:
      super( MsgLinuxCpuState, self).__init__()
      self.msg_type = SBP_MSG_LINUX_CPU_STATE
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.index = kwargs.pop('index')
      self.pid = kwargs.pop('pid')
      self.pcpu = kwargs.pop('pcpu')
      self.time = kwargs.pop('time')
      self.flags = kwargs.pop('flags')
      self.tname = kwargs.pop('tname')
      self.cmdline = kwargs.pop('cmdline')

  def __repr__(self):
    return fmt_repr(self)

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    return MsgLinuxCpuState.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgLinuxCpuState(sbp, **d)

 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgLinuxCpuState._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgLinuxCpuState._parser.build(c)
    return self.pack()

  def into_buffer(self, buf, offset):
    """Produce a framed/packed SBP message into the provided buffer and offset.

    """
    self.payload = containerize(exclude_fields(self))
    self.parser = MsgLinuxCpuState._parser
    self.stream_payload.reset(buf, offset)
    return self.pack_into(buf, offset, self._build_payload)

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgLinuxCpuState, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    
SBP_MSG_LINUX_MEM_STATE = 0x7F09
class MsgLinuxMemState(SBP):
  """SBP class for message MSG_LINUX_MEM_STATE (0x7F09).

  You can have MSG_LINUX_MEM_STATE inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  This message indicates the process state of the top 10 heaviest consumers of
  memory on the system, including a timestamp.

  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  index : int
    sequence of this status message, values from 0-9
  pid : int
    the PID of the process
  pmem : int
    percent of memory used, expressed as a fraction of 256
  time : int
    timestamp of message, refer to flags field for how to interpret
  flags : int
    flags
  tname : string
    fixed length string representing the thread name
  cmdline : string
    the command line (as much as it fits in the remaining packet)
  sender : int
    Optional sender ID, defaults to SENDER_ID (see sbp/msg.py).

  """
  _parser = construct.Struct(
                   'index' / construct.Int8ul,
                   'pid' / construct.Int16ul,
                   'pmem' / construct.Int8ul,
                   'time' / construct.Int32ul,
                   'flags' / construct.Int8ul,
                   'tname'/ construct.Bytes(15),
                   'cmdline' / construct.GreedyBytes,)
  __slots__ = [
               'index',
               'pid',
               'pmem',
               'time',
               'flags',
               'tname',
               'cmdline',
              ]

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      super( MsgLinuxMemState,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.from_binary(sbp.payload)
    else:
      super( MsgLinuxMemState, self).__init__()
      self.msg_type = SBP_MSG_LINUX_MEM_STATE
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.index = kwargs.pop('index')
      self.pid = kwargs.pop('pid')
      self.pmem = kwargs.pop('pmem')
      self.time = kwargs.pop('time')
      self.flags = kwargs.pop('flags')
      self.tname = kwargs.pop('tname')
      self.cmdline = kwargs.pop('cmdline')

  def __repr__(self):
    return fmt_repr(self)

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    return MsgLinuxMemState.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgLinuxMemState(sbp, **d)

 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgLinuxMemState._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgLinuxMemState._parser.build(c)
    return self.pack()

  def into_buffer(self, buf, offset):
    """Produce a framed/packed SBP message into the provided buffer and offset.

    """
    self.payload = containerize(exclude_fields(self))
    self.parser = MsgLinuxMemState._parser
    self.stream_payload.reset(buf, offset)
    return self.pack_into(buf, offset, self._build_payload)

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgLinuxMemState, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    
SBP_MSG_LINUX_SYS_STATE = 0x7F0A
class MsgLinuxSysState(SBP):
  """SBP class for message MSG_LINUX_SYS_STATE (0x7F0A).

  You can have MSG_LINUX_SYS_STATE inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  This presents a summary of CPU and memory utilization, including a
  timestamp.

  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  mem_total : int
    total system memory, in MiB
  pcpu : int
    percent of CPU used, expressed as a fraction of 256
  pmem : int
    percent of memory used, expressed as a fraction of 256
  procs_starting : int
    number of processes that started during collection phase
  procs_stopping : int
    number of processes that stopped during collection phase
  pid_count : int
    the count of processes on the system
  time : int
    timestamp of message, refer to flags field for how to interpret
  flags : int
    flags
  sender : int
    Optional sender ID, defaults to SENDER_ID (see sbp/msg.py).

  """
  _parser = construct.Struct(
                   'mem_total' / construct.Int16ul,
                   'pcpu' / construct.Int8ul,
                   'pmem' / construct.Int8ul,
                   'procs_starting' / construct.Int16ul,
                   'procs_stopping' / construct.Int16ul,
                   'pid_count' / construct.Int16ul,
                   'time' / construct.Int32ul,
                   'flags' / construct.Int8ul,)
  __slots__ = [
               'mem_total',
               'pcpu',
               'pmem',
               'procs_starting',
               'procs_stopping',
               'pid_count',
               'time',
               'flags',
              ]

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      super( MsgLinuxSysState,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.from_binary(sbp.payload)
    else:
      super( MsgLinuxSysState, self).__init__()
      self.msg_type = SBP_MSG_LINUX_SYS_STATE
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.mem_total = kwargs.pop('mem_total')
      self.pcpu = kwargs.pop('pcpu')
      self.pmem = kwargs.pop('pmem')
      self.procs_starting = kwargs.pop('procs_starting')
      self.procs_stopping = kwargs.pop('procs_stopping')
      self.pid_count = kwargs.pop('pid_count')
      self.time = kwargs.pop('time')
      self.flags = kwargs.pop('flags')

  def __repr__(self):
    return fmt_repr(self)

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    return MsgLinuxSysState.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgLinuxSysState(sbp, **d)

 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgLinuxSysState._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgLinuxSysState._parser.build(c)
    return self.pack()

  def into_buffer(self, buf, offset):
    """Produce a framed/packed SBP message into the provided buffer and offset.

    """
    self.payload = containerize(exclude_fields(self))
    self.parser = MsgLinuxSysState._parser
    self.stream_payload.reset(buf, offset)
    return self.pack_into(buf, offset, self._build_payload)

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgLinuxSysState, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    

msg_classes = {
  0x7F00: MsgLinuxCpuStateDepA,
  0x7F01: MsgLinuxMemStateDepA,
  0x7F02: MsgLinuxSysStateDepA,
  0x7F03: MsgLinuxProcessSocketCounts,
  0x7F04: MsgLinuxProcessSocketQueues,
  0x7F05: MsgLinuxSocketUsage,
  0x7F06: MsgLinuxProcessFdCount,
  0x7F07: MsgLinuxProcessFdSummary,
  0x7F08: MsgLinuxCpuState,
  0x7F09: MsgLinuxMemState,
  0x7F0A: MsgLinuxSysState,
}