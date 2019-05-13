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

import numba as nb
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
          ('index', 'u1'),
          ('pid', 'u2'),
          ('pcpu', 'u1'),
          ('tname', '|S15'),
          ('cmdline', '|S{}'.format(count)),
        ])

    t = getattr(cls, 'static_dtype0', None)
    if not t:
      t = np.dtype([
          ('index', 'u1'),
          ('pid', 'u2'),
          ('pcpu', 'u1'),
          ('tname', '|S15'),
          ('cmdline', '|S{}'.format(count)),
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
      'index': int(res['index'] if element else res['index'][0]),
      'pid': int(res['pid'] if element else res['pid'][0]),
      'pcpu': int(res['pcpu'] if element else res['pcpu'][0]),
      'tname': '' if res['tname'] is None else res['tname'].tostring().decode('ascii'),
      'cmdline': '' if res['cmdline'] is None else res['cmdline'].tostring().decode('ascii'),
    }
    return d

  
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
          ('index', 'u1'),
          ('pid', 'u2'),
          ('pmem', 'u1'),
          ('tname', '|S15'),
          ('cmdline', '|S{}'.format(count)),
        ])

    t = getattr(cls, 'static_dtype0', None)
    if not t:
      t = np.dtype([
          ('index', 'u1'),
          ('pid', 'u2'),
          ('pmem', 'u1'),
          ('tname', '|S15'),
          ('cmdline', '|S{}'.format(count)),
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
      'index': int(res['index'] if element else res['index'][0]),
      'pid': int(res['pid'] if element else res['pid'][0]),
      'pmem': int(res['pmem'] if element else res['pmem'][0]),
      'tname': '' if res['tname'] is None else res['tname'].tostring().decode('ascii'),
      'cmdline': '' if res['cmdline'] is None else res['cmdline'].tostring().decode('ascii'),
    }
    return d

  
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
          ('mem_total', 'u2'),
          ('pcpu', 'u1'),
          ('pmem', 'u1'),
          ('procs_starting', 'u2'),
          ('procs_stopping', 'u2'),
          ('pid_count', 'u2'),
        ])

    t = getattr(cls, 'static_dtype0', None)
    if not t:
      t = np.dtype([
          ('mem_total', 'u2'),
          ('pcpu', 'u1'),
          ('pmem', 'u1'),
          ('procs_starting', 'u2'),
          ('procs_stopping', 'u2'),
          ('pid_count', 'u2'),
        ])
      cls.static_dtype0 = t
    return t

  @classmethod
  def _dynamic_dtype(cls):
    t = getattr(cls, 'dynamic_dtype', None)
    if not t:    
      t = None
      cls.dynamic_dtype = t
    return t

  @staticmethod
  def _unpack_members(res, element=False):
    d = {
      'mem_total': int(res['mem_total'] if element else res['mem_total'][0]),
      'pcpu': int(res['pcpu'] if element else res['pcpu'][0]),
      'pmem': int(res['pmem'] if element else res['pmem'][0]),
      'procs_starting': int(res['procs_starting'] if element else res['procs_starting'][0]),
      'procs_stopping': int(res['procs_stopping'] if element else res['procs_stopping'][0]),
      'pid_count': int(res['pid_count'] if element else res['pid_count'][0]),
    }
    return d

  
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
          ('index', 'u1'),
          ('pid', 'u2'),
          ('socket_count', 'u2'),
          ('socket_types', 'u2'),
          ('socket_states', 'u2'),
          ('cmdline', '|S{}'.format(count)),
        ])

    t = getattr(cls, 'static_dtype0', None)
    if not t:
      t = np.dtype([
          ('index', 'u1'),
          ('pid', 'u2'),
          ('socket_count', 'u2'),
          ('socket_types', 'u2'),
          ('socket_states', 'u2'),
          ('cmdline', '|S{}'.format(count)),
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
      'index': int(res['index'] if element else res['index'][0]),
      'pid': int(res['pid'] if element else res['pid'][0]),
      'socket_count': int(res['socket_count'] if element else res['socket_count'][0]),
      'socket_types': int(res['socket_types'] if element else res['socket_types'][0]),
      'socket_states': int(res['socket_states'] if element else res['socket_states'][0]),
      'cmdline': '' if res['cmdline'] is None else res['cmdline'].tostring().decode('ascii'),
    }
    return d

  
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
          ('index', 'u1'),
          ('pid', 'u2'),
          ('recv_queued', 'u2'),
          ('send_queued', 'u2'),
          ('socket_types', 'u2'),
          ('socket_states', 'u2'),
          ('address_of_largest', '|S64'),
          ('cmdline', '|S{}'.format(count)),
        ])

    t = getattr(cls, 'static_dtype0', None)
    if not t:
      t = np.dtype([
          ('index', 'u1'),
          ('pid', 'u2'),
          ('recv_queued', 'u2'),
          ('send_queued', 'u2'),
          ('socket_types', 'u2'),
          ('socket_states', 'u2'),
          ('address_of_largest', '|S64'),
          ('cmdline', '|S{}'.format(count)),
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
      'index': int(res['index'] if element else res['index'][0]),
      'pid': int(res['pid'] if element else res['pid'][0]),
      'recv_queued': int(res['recv_queued'] if element else res['recv_queued'][0]),
      'send_queued': int(res['send_queued'] if element else res['send_queued'][0]),
      'socket_types': int(res['socket_types'] if element else res['socket_types'][0]),
      'socket_states': int(res['socket_states'] if element else res['socket_states'][0]),
      'address_of_largest': '' if res['address_of_largest'] is None else res['address_of_largest'].tostring().decode('ascii'),
      'cmdline': '' if res['cmdline'] is None else res['cmdline'].tostring().decode('ascii'),
    }
    return d

  
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
          ('avg_queue_depth', 'u4'),
          ('max_queue_depth', 'u4'),
          ('socket_state_counts', ('u2', (16,))),
          ('socket_type_counts', ('u2', (16,))),
        ])

    t = getattr(cls, 'static_dtype0', None)
    if not t:
      t = np.dtype([
          ('avg_queue_depth', 'u4'),
          ('max_queue_depth', 'u4'),
          ('socket_state_counts', ('u2', (16,))),
          ('socket_type_counts', ('u2', (16,))),
        ])
      cls.static_dtype0 = t
    return t

  @classmethod
  def _dynamic_dtype(cls):
    t = getattr(cls, 'dynamic_dtype', None)
    if not t:    
      t = np.dtype([('socket_state_counts', 'u2'),])
      cls.dynamic_dtype = t
    return t

  @staticmethod
  def _unpack_members(res, element=False):
    d = {
      'avg_queue_depth': int(res['avg_queue_depth'] if element else res['avg_queue_depth'][0]),
      'max_queue_depth': int(res['max_queue_depth'] if element else res['max_queue_depth'][0]),
      'socket_state_counts': [] if res['socket_state_counts'] is None else [x.item() for x in res['socket_state_counts'].flatten()],
      'socket_type_counts': [] if res['socket_type_counts'] is None else [x.item() for x in res['socket_type_counts'].flatten()],
    }
    return d

  
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
          ('index', 'u1'),
          ('pid', 'u2'),
          ('fd_count', 'u2'),
          ('cmdline', '|S{}'.format(count)),
        ])

    t = getattr(cls, 'static_dtype0', None)
    if not t:
      t = np.dtype([
          ('index', 'u1'),
          ('pid', 'u2'),
          ('fd_count', 'u2'),
          ('cmdline', '|S{}'.format(count)),
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
      'index': int(res['index'] if element else res['index'][0]),
      'pid': int(res['pid'] if element else res['pid'][0]),
      'fd_count': int(res['fd_count'] if element else res['fd_count'][0]),
      'cmdline': '' if res['cmdline'] is None else res['cmdline'].tostring().decode('ascii'),
    }
    return d

  
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
          ('sys_fd_count', 'u4'),
          ('most_opened', '|S{}'.format(count)),
        ])

    t = getattr(cls, 'static_dtype0', None)
    if not t:
      t = np.dtype([
          ('sys_fd_count', 'u4'),
          ('most_opened', '|S{}'.format(count)),
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
      'sys_fd_count': int(res['sys_fd_count'] if element else res['sys_fd_count'][0]),
      'most_opened': '' if res['most_opened'] is None else res['most_opened'].tostring().decode('ascii'),
    }
    return d

  

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