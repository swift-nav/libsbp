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
Linux state monitoring.

"""

import json

import numpy as np

from sbp.jit.msg import SBP, SENDER_ID
from sbp.jit.msg import get_u8, get_u16, get_u32, get_u64
from sbp.jit.msg import get_s8, get_s16, get_s32, get_s64
from sbp.jit.msg import get_f32, get_f64, judicious_round
from sbp.jit.msg import get_string, get_fixed_string, get_setting
from sbp.jit.msg import get_array, get_fixed_array

# Automatically generated from piksi/yaml/swiftnav/sbp/linux.yaml with generate.py.
# Please do not hand edit!
SBP_MSG_LINUX_CPU_STATE = 0x7F00
class MsgLinuxCpuState(SBP):
  """SBP class for message MSG_LINUX_CPU_STATE (0x7F00).

  You can have MSG_LINUX_CPU_STATE inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  This message indicates the process state of the top 10 heaviest
consumers of CPU on the system.


  """
  __slots__ = ['index',
               'pid',
               'pcpu',
               'tname',
               'cmdline',
               ]
  @classmethod
  def parse_members(cls, buf, offset, length):
    ret = {}
    (__index, offset, length) = get_u8(buf, offset, length)
    ret['index'] = __index
    (__pid, offset, length) = get_u16(buf, offset, length)
    ret['pid'] = __pid
    (__pcpu, offset, length) = get_u8(buf, offset, length)
    ret['pcpu'] = __pcpu
    (__tname, offset, length) = get_fixed_string(15)(buf, offset, length)
    ret['tname'] = __tname
    (__cmdline, offset, length) = get_string(buf, offset, length)
    ret['cmdline'] = __cmdline
    return ret, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.index = res['index']
    self.pid = res['pid']
    self.pcpu = res['pcpu']
    self.tname = res['tname']
    self.cmdline = res['cmdline']
    return res, off, length

  @classmethod
  def _payload_size(self):
    ret = 0
    # index: u8
    ret += 1
    # pid: u16
    ret += 2
    # pcpu: u8
    ret += 1
    # tname: string
    ret += 15
    # cmdline: string
    ret += 247
    return ret
  
SBP_MSG_LINUX_MEM_STATE = 0x7F01
class MsgLinuxMemState(SBP):
  """SBP class for message MSG_LINUX_MEM_STATE (0x7F01).

  You can have MSG_LINUX_MEM_STATE inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  This message indicates the process state of the top 10 heaviest
consumers of memory on the system.


  """
  __slots__ = ['index',
               'pid',
               'pmem',
               'tname',
               'cmdline',
               ]
  @classmethod
  def parse_members(cls, buf, offset, length):
    ret = {}
    (__index, offset, length) = get_u8(buf, offset, length)
    ret['index'] = __index
    (__pid, offset, length) = get_u16(buf, offset, length)
    ret['pid'] = __pid
    (__pmem, offset, length) = get_u8(buf, offset, length)
    ret['pmem'] = __pmem
    (__tname, offset, length) = get_fixed_string(15)(buf, offset, length)
    ret['tname'] = __tname
    (__cmdline, offset, length) = get_string(buf, offset, length)
    ret['cmdline'] = __cmdline
    return ret, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.index = res['index']
    self.pid = res['pid']
    self.pmem = res['pmem']
    self.tname = res['tname']
    self.cmdline = res['cmdline']
    return res, off, length

  @classmethod
  def _payload_size(self):
    ret = 0
    # index: u8
    ret += 1
    # pid: u16
    ret += 2
    # pmem: u8
    ret += 1
    # tname: string
    ret += 15
    # cmdline: string
    ret += 247
    return ret
  
SBP_MSG_LINUX_SYS_STATE = 0x7F02
class MsgLinuxSysState(SBP):
  """SBP class for message MSG_LINUX_SYS_STATE (0x7F02).

  You can have MSG_LINUX_SYS_STATE inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  This presents a summary of CPU and memory utilization.


  """
  __slots__ = ['mem_total',
               'pcpu',
               'pmem',
               'procs_starting',
               'procs_stopping',
               'pid_count',
               ]
  @classmethod
  def parse_members(cls, buf, offset, length):
    ret = {}
    (__mem_total, offset, length) = get_u16(buf, offset, length)
    ret['mem_total'] = __mem_total
    (__pcpu, offset, length) = get_u8(buf, offset, length)
    ret['pcpu'] = __pcpu
    (__pmem, offset, length) = get_u8(buf, offset, length)
    ret['pmem'] = __pmem
    (__procs_starting, offset, length) = get_u16(buf, offset, length)
    ret['procs_starting'] = __procs_starting
    (__procs_stopping, offset, length) = get_u16(buf, offset, length)
    ret['procs_stopping'] = __procs_stopping
    (__pid_count, offset, length) = get_u16(buf, offset, length)
    ret['pid_count'] = __pid_count
    return ret, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.mem_total = res['mem_total']
    self.pcpu = res['pcpu']
    self.pmem = res['pmem']
    self.procs_starting = res['procs_starting']
    self.procs_stopping = res['procs_stopping']
    self.pid_count = res['pid_count']
    return res, off, length

  @classmethod
  def _payload_size(self):
    ret = 0
    # mem_total: u16
    ret += 2
    # pcpu: u8
    ret += 1
    # pmem: u8
    ret += 1
    # procs_starting: u16
    ret += 2
    # procs_stopping: u16
    ret += 2
    # pid_count: u16
    ret += 2
    return ret
  
SBP_MSG_LINUX_PROCESS_SOCKET_COUNTS = 0x7F03
class MsgLinuxProcessSocketCounts(SBP):
  """SBP class for message MSG_LINUX_PROCESS_SOCKET_COUNTS (0x7F03).

  You can have MSG_LINUX_PROCESS_SOCKET_COUNTS inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  Top 10 list of processes with high socket counts.


  """
  __slots__ = ['index',
               'pid',
               'socket_count',
               'socket_types',
               'socket_states',
               'cmdline',
               ]
  @classmethod
  def parse_members(cls, buf, offset, length):
    ret = {}
    (__index, offset, length) = get_u8(buf, offset, length)
    ret['index'] = __index
    (__pid, offset, length) = get_u16(buf, offset, length)
    ret['pid'] = __pid
    (__socket_count, offset, length) = get_u16(buf, offset, length)
    ret['socket_count'] = __socket_count
    (__socket_types, offset, length) = get_u16(buf, offset, length)
    ret['socket_types'] = __socket_types
    (__socket_states, offset, length) = get_u16(buf, offset, length)
    ret['socket_states'] = __socket_states
    (__cmdline, offset, length) = get_string(buf, offset, length)
    ret['cmdline'] = __cmdline
    return ret, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.index = res['index']
    self.pid = res['pid']
    self.socket_count = res['socket_count']
    self.socket_types = res['socket_types']
    self.socket_states = res['socket_states']
    self.cmdline = res['cmdline']
    return res, off, length

  @classmethod
  def _payload_size(self):
    ret = 0
    # index: u8
    ret += 1
    # pid: u16
    ret += 2
    # socket_count: u16
    ret += 2
    # socket_types: u16
    ret += 2
    # socket_states: u16
    ret += 2
    # cmdline: string
    ret += 247
    return ret
  
SBP_MSG_LINUX_PROCESS_SOCKET_QUEUES = 0x7F04
class MsgLinuxProcessSocketQueues(SBP):
  """SBP class for message MSG_LINUX_PROCESS_SOCKET_QUEUES (0x7F04).

  You can have MSG_LINUX_PROCESS_SOCKET_QUEUES inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  Top 10 list of sockets with deep queues.


  """
  __slots__ = ['index',
               'pid',
               'recv_queued',
               'send_queued',
               'socket_types',
               'socket_states',
               'address_of_largest',
               'cmdline',
               ]
  @classmethod
  def parse_members(cls, buf, offset, length):
    ret = {}
    (__index, offset, length) = get_u8(buf, offset, length)
    ret['index'] = __index
    (__pid, offset, length) = get_u16(buf, offset, length)
    ret['pid'] = __pid
    (__recv_queued, offset, length) = get_u16(buf, offset, length)
    ret['recv_queued'] = __recv_queued
    (__send_queued, offset, length) = get_u16(buf, offset, length)
    ret['send_queued'] = __send_queued
    (__socket_types, offset, length) = get_u16(buf, offset, length)
    ret['socket_types'] = __socket_types
    (__socket_states, offset, length) = get_u16(buf, offset, length)
    ret['socket_states'] = __socket_states
    (__address_of_largest, offset, length) = get_fixed_string(64)(buf, offset, length)
    ret['address_of_largest'] = __address_of_largest
    (__cmdline, offset, length) = get_string(buf, offset, length)
    ret['cmdline'] = __cmdline
    return ret, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.index = res['index']
    self.pid = res['pid']
    self.recv_queued = res['recv_queued']
    self.send_queued = res['send_queued']
    self.socket_types = res['socket_types']
    self.socket_states = res['socket_states']
    self.address_of_largest = res['address_of_largest']
    self.cmdline = res['cmdline']
    return res, off, length

  @classmethod
  def _payload_size(self):
    ret = 0
    # index: u8
    ret += 1
    # pid: u16
    ret += 2
    # recv_queued: u16
    ret += 2
    # send_queued: u16
    ret += 2
    # socket_types: u16
    ret += 2
    # socket_states: u16
    ret += 2
    # address_of_largest: string
    ret += 64
    # cmdline: string
    ret += 247
    return ret
  
SBP_MSG_LINUX_SOCKET_USAGE = 0x7F05
class MsgLinuxSocketUsage(SBP):
  """SBP class for message MSG_LINUX_SOCKET_USAGE (0x7F05).

  You can have MSG_LINUX_SOCKET_USAGE inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  Summaries the socket usage across the system.


  """
  __slots__ = ['avg_queue_depth',
               'max_queue_depth',
               'socket_state_counts',
               'socket_type_counts',
               ]
  @classmethod
  def parse_members(cls, buf, offset, length):
    ret = {}
    (__avg_queue_depth, offset, length) = get_u32(buf, offset, length)
    ret['avg_queue_depth'] = __avg_queue_depth
    (__max_queue_depth, offset, length) = get_u32(buf, offset, length)
    ret['max_queue_depth'] = __max_queue_depth
    (__socket_state_counts, offset, length) = get_fixed_array(get_u16, 16, 2)(buf, offset, length)
    ret['socket_state_counts'] = __socket_state_counts
    (__socket_type_counts, offset, length) = get_fixed_array(get_u16, 16, 2)(buf, offset, length)
    ret['socket_type_counts'] = __socket_type_counts
    return ret, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.avg_queue_depth = res['avg_queue_depth']
    self.max_queue_depth = res['max_queue_depth']
    self.socket_state_counts = res['socket_state_counts']
    self.socket_type_counts = res['socket_type_counts']
    return res, off, length

  @classmethod
  def _payload_size(self):
    ret = 0
    # avg_queue_depth: u32
    ret += 4
    # max_queue_depth: u32
    ret += 4
    # socket_state_counts: array of u16
    ret += 2 * 16
    # socket_type_counts: array of u16
    ret += 2 * 16
    return ret
  
SBP_MSG_LINUX_PROCESS_FD_COUNT = 0x7F06
class MsgLinuxProcessFdCount(SBP):
  """SBP class for message MSG_LINUX_PROCESS_FD_COUNT (0x7F06).

  You can have MSG_LINUX_PROCESS_FD_COUNT inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  Top 10 list of processes with a large number of open file descriptors.


  """
  __slots__ = ['index',
               'pid',
               'fd_count',
               'cmdline',
               ]
  @classmethod
  def parse_members(cls, buf, offset, length):
    ret = {}
    (__index, offset, length) = get_u8(buf, offset, length)
    ret['index'] = __index
    (__pid, offset, length) = get_u16(buf, offset, length)
    ret['pid'] = __pid
    (__fd_count, offset, length) = get_u16(buf, offset, length)
    ret['fd_count'] = __fd_count
    (__cmdline, offset, length) = get_string(buf, offset, length)
    ret['cmdline'] = __cmdline
    return ret, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.index = res['index']
    self.pid = res['pid']
    self.fd_count = res['fd_count']
    self.cmdline = res['cmdline']
    return res, off, length

  @classmethod
  def _payload_size(self):
    ret = 0
    # index: u8
    ret += 1
    # pid: u16
    ret += 2
    # fd_count: u16
    ret += 2
    # cmdline: string
    ret += 247
    return ret
  
SBP_MSG_LINUX_PROCESS_FD_SUMMARY = 0x7F07
class MsgLinuxProcessFdSummary(SBP):
  """SBP class for message MSG_LINUX_PROCESS_FD_SUMMARY (0x7F07).

  You can have MSG_LINUX_PROCESS_FD_SUMMARY inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  Summary of open file descriptors on the system.


  """
  __slots__ = ['sys_fd_count',
               'most_opened',
               ]
  @classmethod
  def parse_members(cls, buf, offset, length):
    ret = {}
    (__sys_fd_count, offset, length) = get_u32(buf, offset, length)
    ret['sys_fd_count'] = __sys_fd_count
    (__most_opened, offset, length) = get_string(buf, offset, length)
    ret['most_opened'] = __most_opened
    return ret, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.sys_fd_count = res['sys_fd_count']
    self.most_opened = res['most_opened']
    return res, off, length

  @classmethod
  def _payload_size(self):
    ret = 0
    # sys_fd_count: u32
    ret += 4
    # most_opened: string
    ret += 247
    return ret
  

msg_classes = {
  0x7F00: MsgLinuxCpuState,
  0x7F01: MsgLinuxMemState,
  0x7F02: MsgLinuxSysState,
  0x7F03: MsgLinuxProcessSocketCounts,
  0x7F04: MsgLinuxProcessSocketQueues,
  0x7F05: MsgLinuxSocketUsage,
  0x7F06: MsgLinuxProcessFdCount,
  0x7F07: MsgLinuxProcessFdSummary,
}