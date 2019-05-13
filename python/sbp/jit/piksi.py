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
System health, configuration, and diagnostic messages specific to
the Piksi L1 receiver, including a variety of legacy messages that
may no longer be used.

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
from sbp.jit.gnss import *

# Automatically generated from piksi/yaml/swiftnav/sbp/piksi.yaml with generate.py.
# Please do not hand edit!
SBP_MSG_ALMANAC = 0x0069
class MsgAlmanac(SBP):
  """SBP class for message MSG_ALMANAC (0x0069).

  You can have MSG_ALMANAC inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  This is a legacy message for sending and loading a satellite
alamanac onto the Piksi's flash memory from the host.


  """
  __slots__ = []
  def _unpack_members(self, buf, offset, length):
    return {}, offset, length

  def parse_members(self, buf, offset, length):
    return {}, offset, length

  def _payload_size(self):
    return 0
  
SBP_MSG_SET_TIME = 0x0068
class MsgSetTime(SBP):
  """SBP class for message MSG_SET_TIME (0x0068).

  You can have MSG_SET_TIME inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  This message sets up timing functionality using a coarse GPS
time estimate sent by the host.


  """
  __slots__ = []
  def _unpack_members(self, buf, offset, length):
    return {}, offset, length

  def parse_members(self, buf, offset, length):
    return {}, offset, length

  def _payload_size(self):
    return 0
  
SBP_MSG_RESET = 0x00B6
class MsgReset(SBP):
  """SBP class for message MSG_RESET (0x00B6).

  You can have MSG_RESET inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  This message from the host resets the Piksi back into the
bootloader.


  """
  __slots__ = ['flags',
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
          ('flags', 'u4'),
        ])

    t = getattr(cls, 'static_dtype0', None)
    if not t:
      t = np.dtype([
          ('flags', 'u4'),
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
      'flags': int(res['flags'] if element else res['flags'][0]),
    }
    return d

  
SBP_MSG_RESET_DEP = 0x00B2
class MsgResetDep(SBP):
  """SBP class for message MSG_RESET_DEP (0x00B2).

  You can have MSG_RESET_DEP inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  This message from the host resets the Piksi back into the
bootloader.


  """
  __slots__ = []
  def _unpack_members(self, buf, offset, length):
    return {}, offset, length

  def parse_members(self, buf, offset, length):
    return {}, offset, length

  def _payload_size(self):
    return 0
  
SBP_MSG_CW_RESULTS = 0x00C0
class MsgCwResults(SBP):
  """SBP class for message MSG_CW_RESULTS (0x00C0).

  You can have MSG_CW_RESULTS inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  This is an unused legacy message for result reporting from the
CW interference channel on the SwiftNAP. This message will be
removed in a future release.


  """
  __slots__ = []
  def _unpack_members(self, buf, offset, length):
    return {}, offset, length

  def parse_members(self, buf, offset, length):
    return {}, offset, length

  def _payload_size(self):
    return 0
  
SBP_MSG_CW_START = 0x00C1
class MsgCwStart(SBP):
  """SBP class for message MSG_CW_START (0x00C1).

  You can have MSG_CW_START inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  This is an unused legacy message from the host for starting
the CW interference channel on the SwiftNAP. This message will
be removed in a future release.


  """
  __slots__ = []
  def _unpack_members(self, buf, offset, length):
    return {}, offset, length

  def parse_members(self, buf, offset, length):
    return {}, offset, length

  def _payload_size(self):
    return 0
  
SBP_MSG_RESET_FILTERS = 0x0022
class MsgResetFilters(SBP):
  """SBP class for message MSG_RESET_FILTERS (0x0022).

  You can have MSG_RESET_FILTERS inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  This message resets either the DGNSS Kalman filters or Integer
Ambiguity Resolution (IAR) process.


  """
  __slots__ = ['filter',
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
          ('filter', 'u1'),
        ])

    t = getattr(cls, 'static_dtype0', None)
    if not t:
      t = np.dtype([
          ('filter', 'u1'),
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
      'filter': int(res['filter'] if element else res['filter'][0]),
    }
    return d

  
SBP_MSG_INIT_BASE = 0x0023
class MsgInitBase(SBP):
  """SBP class for message MSG_INIT_BASE (0x0023).

  You can have MSG_INIT_BASE inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  This message initializes the integer ambiguity resolution (IAR)
process on the Piksi to use an assumed baseline position between
the base station and rover receivers. Warns via MSG_PRINT if
there aren't a shared minimum number (4) of satellite
observations between the two.


  """
  __slots__ = []
  def _unpack_members(self, buf, offset, length):
    return {}, offset, length

  def parse_members(self, buf, offset, length):
    return {}, offset, length

  def _payload_size(self):
    return 0
  
SBP_MSG_THREAD_STATE = 0x0017
class MsgThreadState(SBP):
  """SBP class for message MSG_THREAD_STATE (0x0017).

  You can have MSG_THREAD_STATE inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  The thread usage message from the device reports real-time
operating system (RTOS) thread usage statistics for the named
thread. The reported percentage values must be normalized.


  """
  __slots__ = ['name',
               'cpu',
               'stack_free',
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
          ('name', '|S20'),
          ('cpu', 'u2'),
          ('stack_free', 'u4'),
        ])

    t = getattr(cls, 'static_dtype0', None)
    if not t:
      t = np.dtype([
          ('name', '|S20'),
          ('cpu', 'u2'),
          ('stack_free', 'u4'),
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
      'name': '' if res['name'] is None else res['name'].tostring().decode('ascii'),
      'cpu': int(res['cpu'] if element else res['cpu'][0]),
      'stack_free': int(res['stack_free'] if element else res['stack_free'][0]),
    }
    return d

  
class UARTChannel(object):
  """SBP class for message UARTChannel

  You can have UARTChannel inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  Throughput, utilization, and error counts on the RX/TX buffers
of this UART channel. The reported percentage values must
be normalized.


  """
  __slots__ = ['tx_throughput',
               'rx_throughput',
               'crc_error_count',
               'io_error_count',
               'tx_buffer_level',
               'rx_buffer_level',
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
          ('tx_throughput', 'f4'),
          ('rx_throughput', 'f4'),
          ('crc_error_count', 'u2'),
          ('io_error_count', 'u2'),
          ('tx_buffer_level', 'u1'),
          ('rx_buffer_level', 'u1'),
        ])

    t = getattr(cls, 'static_dtype0', None)
    if not t:
      t = np.dtype([
          ('tx_throughput', 'f4'),
          ('rx_throughput', 'f4'),
          ('crc_error_count', 'u2'),
          ('io_error_count', 'u2'),
          ('tx_buffer_level', 'u1'),
          ('rx_buffer_level', 'u1'),
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
      'tx_throughput': float(res['tx_throughput'] if element else res['tx_throughput'][0]),
      'rx_throughput': float(res['rx_throughput'] if element else res['rx_throughput'][0]),
      'crc_error_count': int(res['crc_error_count'] if element else res['crc_error_count'][0]),
      'io_error_count': int(res['io_error_count'] if element else res['io_error_count'][0]),
      'tx_buffer_level': int(res['tx_buffer_level'] if element else res['tx_buffer_level'][0]),
      'rx_buffer_level': int(res['rx_buffer_level'] if element else res['rx_buffer_level'][0]),
    }
    return d

  
class Period(object):
  """SBP class for message Period

  You can have Period inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  Statistics on the period of observations received from the base
station. As complete observation sets are received, their time
of reception is compared with the prior set''s time of reception.
This measurement provides a proxy for link quality as incomplete
or missing sets will increase the period.  Long periods
can cause momentary RTK solution outages.


  """
  __slots__ = ['avg',
               'pmin',
               'pmax',
               'current',
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
          ('avg', 'i4'),
          ('pmin', 'i4'),
          ('pmax', 'i4'),
          ('current', 'i4'),
        ])

    t = getattr(cls, 'static_dtype0', None)
    if not t:
      t = np.dtype([
          ('avg', 'i4'),
          ('pmin', 'i4'),
          ('pmax', 'i4'),
          ('current', 'i4'),
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
      'avg': int(res['avg'] if element else res['avg'][0]),
      'pmin': int(res['pmin'] if element else res['pmin'][0]),
      'pmax': int(res['pmax'] if element else res['pmax'][0]),
      'current': int(res['current'] if element else res['current'][0]),
    }
    return d

  
class Latency(object):
  """SBP class for message Latency

  You can have Latency inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  Statistics on the latency of observations received from the base
station. As observation packets are received their GPS time is
compared to the current GPS time calculated locally by the
receiver to give a precise measurement of the end-to-end
communication latency in the system.


  """
  __slots__ = ['avg',
               'lmin',
               'lmax',
               'current',
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
          ('avg', 'i4'),
          ('lmin', 'i4'),
          ('lmax', 'i4'),
          ('current', 'i4'),
        ])

    t = getattr(cls, 'static_dtype0', None)
    if not t:
      t = np.dtype([
          ('avg', 'i4'),
          ('lmin', 'i4'),
          ('lmax', 'i4'),
          ('current', 'i4'),
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
      'avg': int(res['avg'] if element else res['avg'][0]),
      'lmin': int(res['lmin'] if element else res['lmin'][0]),
      'lmax': int(res['lmax'] if element else res['lmax'][0]),
      'current': int(res['current'] if element else res['current'][0]),
    }
    return d

  
SBP_MSG_UART_STATE = 0x001D
class MsgUartState(SBP):
  """SBP class for message MSG_UART_STATE (0x001D).

  You can have MSG_UART_STATE inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  The UART message reports data latency and throughput of the UART
channels providing SBP I/O. On the default Piksi configuration,
UARTs A and B are used for telemetry radios, but can also be
host access ports for embedded hosts, or other interfaces in
future. The reported percentage values must be normalized.
Observations latency and period can be used to assess the
health of the differential corrections link. Latency provides
the timeliness of received base observations while the
period indicates their likelihood of transmission.


  """
  __slots__ = ['uart_a',
               'uart_b',
               'uart_ftdi',
               'latency',
               'obs_period',
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
          ('uart_a', UARTChannel._static_dtype()),
          ('uart_b', UARTChannel._static_dtype()),
          ('uart_ftdi', UARTChannel._static_dtype()),
          ('latency', Latency._static_dtype()),
          ('obs_period', Period._static_dtype()),
        ])

    t = getattr(cls, 'static_dtype0', None)
    if not t:
      t = np.dtype([
          ('uart_a', UARTChannel._static_dtype()),
          ('uart_b', UARTChannel._static_dtype()),
          ('uart_ftdi', UARTChannel._static_dtype()),
          ('latency', Latency._static_dtype()),
          ('obs_period', Period._static_dtype()),
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
      'uart_a': UARTChannel._unpack_members(res['uart_a'], element=element),
      'uart_b': UARTChannel._unpack_members(res['uart_b'], element=element),
      'uart_ftdi': UARTChannel._unpack_members(res['uart_ftdi'], element=element),
      'latency': Latency._unpack_members(res['latency'], element=element),
      'obs_period': Period._unpack_members(res['obs_period'], element=element),
    }
    return d

  
SBP_MSG_UART_STATE_DEPA = 0x0018
class MsgUartStateDepa(SBP):
  """SBP class for message MSG_UART_STATE_DEPA (0x0018).

  You can have MSG_UART_STATE_DEPA inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  Deprecated

  """
  __slots__ = ['uart_a',
               'uart_b',
               'uart_ftdi',
               'latency',
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
          ('uart_a', UARTChannel._static_dtype()),
          ('uart_b', UARTChannel._static_dtype()),
          ('uart_ftdi', UARTChannel._static_dtype()),
          ('latency', Latency._static_dtype()),
        ])

    t = getattr(cls, 'static_dtype0', None)
    if not t:
      t = np.dtype([
          ('uart_a', UARTChannel._static_dtype()),
          ('uart_b', UARTChannel._static_dtype()),
          ('uart_ftdi', UARTChannel._static_dtype()),
          ('latency', Latency._static_dtype()),
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
      'uart_a': UARTChannel._unpack_members(res['uart_a'], element=element),
      'uart_b': UARTChannel._unpack_members(res['uart_b'], element=element),
      'uart_ftdi': UARTChannel._unpack_members(res['uart_ftdi'], element=element),
      'latency': Latency._unpack_members(res['latency'], element=element),
    }
    return d

  
SBP_MSG_IAR_STATE = 0x0019
class MsgIarState(SBP):
  """SBP class for message MSG_IAR_STATE (0x0019).

  You can have MSG_IAR_STATE inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  This message reports the state of the Integer Ambiguity
Resolution (IAR) process, which resolves unknown integer
ambiguities from double-differenced carrier-phase measurements
from satellite observations.


  """
  __slots__ = ['num_hyps',
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
          ('num_hyps', 'u4'),
        ])

    t = getattr(cls, 'static_dtype0', None)
    if not t:
      t = np.dtype([
          ('num_hyps', 'u4'),
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
      'num_hyps': int(res['num_hyps'] if element else res['num_hyps'][0]),
    }
    return d

  
SBP_MSG_MASK_SATELLITE = 0x002B
class MsgMaskSatellite(SBP):
  """SBP class for message MSG_MASK_SATELLITE (0x002B).

  You can have MSG_MASK_SATELLITE inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  This message allows setting a mask to prevent a particular satellite
from being used in various Piksi subsystems.


  """
  __slots__ = ['mask',
               'sid',
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
          ('mask', 'u1'),
          ('sid', GnssSignal._static_dtype()),
        ])

    t = getattr(cls, 'static_dtype0', None)
    if not t:
      t = np.dtype([
          ('mask', 'u1'),
          ('sid', GnssSignal._static_dtype()),
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
      'mask': int(res['mask'] if element else res['mask'][0]),
      'sid': GnssSignal._unpack_members(res['sid'], element=element),
    }
    return d

  
SBP_MSG_MASK_SATELLITE_DEP = 0x001B
class MsgMaskSatelliteDep(SBP):
  """SBP class for message MSG_MASK_SATELLITE_DEP (0x001B).

  You can have MSG_MASK_SATELLITE_DEP inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  Deprecated.

  """
  __slots__ = ['mask',
               'sid',
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
          ('mask', 'u1'),
          ('sid', GnssSignalDep._static_dtype()),
        ])

    t = getattr(cls, 'static_dtype0', None)
    if not t:
      t = np.dtype([
          ('mask', 'u1'),
          ('sid', GnssSignalDep._static_dtype()),
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
      'mask': int(res['mask'] if element else res['mask'][0]),
      'sid': GnssSignalDep._unpack_members(res['sid'], element=element),
    }
    return d

  
SBP_MSG_DEVICE_MONITOR = 0x00B5
class MsgDeviceMonitor(SBP):
  """SBP class for message MSG_DEVICE_MONITOR (0x00B5).

  You can have MSG_DEVICE_MONITOR inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  This message contains temperature and voltage level measurements from the
processor's monitoring system and the RF frontend die temperature if
available.


  """
  __slots__ = ['dev_vin',
               'cpu_vint',
               'cpu_vaux',
               'cpu_temperature',
               'fe_temperature',
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
          ('dev_vin', 'i2'),
          ('cpu_vint', 'i2'),
          ('cpu_vaux', 'i2'),
          ('cpu_temperature', 'i2'),
          ('fe_temperature', 'i2'),
        ])

    t = getattr(cls, 'static_dtype0', None)
    if not t:
      t = np.dtype([
          ('dev_vin', 'i2'),
          ('cpu_vint', 'i2'),
          ('cpu_vaux', 'i2'),
          ('cpu_temperature', 'i2'),
          ('fe_temperature', 'i2'),
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
      'dev_vin': int(res['dev_vin'] if element else res['dev_vin'][0]),
      'cpu_vint': int(res['cpu_vint'] if element else res['cpu_vint'][0]),
      'cpu_vaux': int(res['cpu_vaux'] if element else res['cpu_vaux'][0]),
      'cpu_temperature': int(res['cpu_temperature'] if element else res['cpu_temperature'][0]),
      'fe_temperature': int(res['fe_temperature'] if element else res['fe_temperature'][0]),
    }
    return d

  
SBP_MSG_COMMAND_REQ = 0x00B8
class MsgCommandReq(SBP):
  """SBP class for message MSG_COMMAND_REQ (0x00B8).

  You can have MSG_COMMAND_REQ inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  Request the recipient to execute an command.
Output will be sent in MSG_LOG messages, and the exit
code will be returned with MSG_COMMAND_RESP.


  """
  __slots__ = ['sequence',
               'command',
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
          ('sequence', 'u4'),
          ('command', '|S{}'.format(count)),
        ])

    t = getattr(cls, 'static_dtype0', None)
    if not t:
      t = np.dtype([
          ('sequence', 'u4'),
          ('command', '|S{}'.format(count)),
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
      'sequence': int(res['sequence'] if element else res['sequence'][0]),
      'command': '' if res['command'] is None else res['command'].tostring().decode('ascii'),
    }
    return d

  
SBP_MSG_COMMAND_RESP = 0x00B9
class MsgCommandResp(SBP):
  """SBP class for message MSG_COMMAND_RESP (0x00B9).

  You can have MSG_COMMAND_RESP inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  The response to MSG_COMMAND_REQ with the return code of
the command.  A return code of zero indicates success.


  """
  __slots__ = ['sequence',
               'code',
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
          ('sequence', 'u4'),
          ('code', 'i4'),
        ])

    t = getattr(cls, 'static_dtype0', None)
    if not t:
      t = np.dtype([
          ('sequence', 'u4'),
          ('code', 'i4'),
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
      'sequence': int(res['sequence'] if element else res['sequence'][0]),
      'code': int(res['code'] if element else res['code'][0]),
    }
    return d

  
SBP_MSG_COMMAND_OUTPUT = 0x00BC
class MsgCommandOutput(SBP):
  """SBP class for message MSG_COMMAND_OUTPUT (0x00BC).

  You can have MSG_COMMAND_OUTPUT inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  Returns the standard output and standard error of the
command requested by MSG_COMMAND_REQ.
The sequence number can be used to filter for filtering
the correct command.


  """
  __slots__ = ['sequence',
               'line',
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
          ('sequence', 'u4'),
          ('line', '|S{}'.format(count)),
        ])

    t = getattr(cls, 'static_dtype0', None)
    if not t:
      t = np.dtype([
          ('sequence', 'u4'),
          ('line', '|S{}'.format(count)),
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
      'sequence': int(res['sequence'] if element else res['sequence'][0]),
      'line': '' if res['line'] is None else res['line'].tostring().decode('ascii'),
    }
    return d

  
SBP_MSG_NETWORK_STATE_REQ = 0x00BA
class MsgNetworkStateReq(SBP):
  """SBP class for message MSG_NETWORK_STATE_REQ (0x00BA).

  You can have MSG_NETWORK_STATE_REQ inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  Request state of Piksi network interfaces.
Output will be sent in MSG_NETWORK_STATE_RESP messages


  """
  __slots__ = []
  def _unpack_members(self, buf, offset, length):
    return {}, offset, length

  def parse_members(self, buf, offset, length):
    return {}, offset, length

  def _payload_size(self):
    return 0
  
SBP_MSG_NETWORK_STATE_RESP = 0x00BB
class MsgNetworkStateResp(SBP):
  """SBP class for message MSG_NETWORK_STATE_RESP (0x00BB).

  You can have MSG_NETWORK_STATE_RESP inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  The state of a network interface on the Piksi.
Data is made to reflect output of ifaddrs struct returned by getifaddrs
in c.


  """
  __slots__ = ['ipv4_address',
               'ipv4_mask_size',
               'ipv6_address',
               'ipv6_mask_size',
               'rx_bytes',
               'tx_bytes',
               'interface_name',
               'flags',
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
          ('ipv4_address', ('u1', (4,))),
          ('ipv4_mask_size', 'u1'),
          ('ipv6_address', ('u1', (16,))),
          ('ipv6_mask_size', 'u1'),
          ('rx_bytes', 'u4'),
          ('tx_bytes', 'u4'),
          ('interface_name', '|S16'),
          ('flags', 'u4'),
        ])

    t = getattr(cls, 'static_dtype0', None)
    if not t:
      t = np.dtype([
          ('ipv4_address', ('u1', (4,))),
          ('ipv4_mask_size', 'u1'),
          ('ipv6_address', ('u1', (16,))),
          ('ipv6_mask_size', 'u1'),
          ('rx_bytes', 'u4'),
          ('tx_bytes', 'u4'),
          ('interface_name', '|S16'),
          ('flags', 'u4'),
        ])
      cls.static_dtype0 = t
    return t

  @classmethod
  def _dynamic_dtype(cls):
    t = getattr(cls, 'dynamic_dtype', None)
    if not t:    
      t = np.dtype([('ipv4_address', 'u1'),])
      cls.dynamic_dtype = t
    return t

  @staticmethod
  def _unpack_members(res, element=False):
    d = {
      'ipv4_address': [] if res['ipv4_address'] is None else [x.item() for x in res['ipv4_address'].flatten()],
      'ipv4_mask_size': int(res['ipv4_mask_size'] if element else res['ipv4_mask_size'][0]),
      'ipv6_address': [] if res['ipv6_address'] is None else [x.item() for x in res['ipv6_address'].flatten()],
      'ipv6_mask_size': int(res['ipv6_mask_size'] if element else res['ipv6_mask_size'][0]),
      'rx_bytes': int(res['rx_bytes'] if element else res['rx_bytes'][0]),
      'tx_bytes': int(res['tx_bytes'] if element else res['tx_bytes'][0]),
      'interface_name': '' if res['interface_name'] is None else res['interface_name'].tostring().decode('ascii'),
      'flags': int(res['flags'] if element else res['flags'][0]),
    }
    return d

  
class NetworkUsage(object):
  """SBP class for message NetworkUsage

  You can have NetworkUsage inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  The bandwidth usage for each interface can be reported
within this struct and utilize multiple fields to fully
specify the type of traffic that is being tracked. As
either the interval of collection or the collection time
may vary, both a timestamp and period field is provided,
though may not necessarily be populated with a value. 


  """
  __slots__ = ['duration',
               'total_bytes',
               'rx_bytes',
               'tx_bytes',
               'interface_name',
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
          ('duration', 'u8'),
          ('total_bytes', 'u8'),
          ('rx_bytes', 'u4'),
          ('tx_bytes', 'u4'),
          ('interface_name', '|S16'),
        ])

    t = getattr(cls, 'static_dtype0', None)
    if not t:
      t = np.dtype([
          ('duration', 'u8'),
          ('total_bytes', 'u8'),
          ('rx_bytes', 'u4'),
          ('tx_bytes', 'u4'),
          ('interface_name', '|S16'),
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
      'duration': int(res['duration'] if element else res['duration'][0]),
      'total_bytes': int(res['total_bytes'] if element else res['total_bytes'][0]),
      'rx_bytes': int(res['rx_bytes'] if element else res['rx_bytes'][0]),
      'tx_bytes': int(res['tx_bytes'] if element else res['tx_bytes'][0]),
      'interface_name': '' if res['interface_name'] is None else res['interface_name'].tostring().decode('ascii'),
    }
    return d

  
SBP_MSG_NETWORK_BANDWIDTH_USAGE = 0x00BD
class MsgNetworkBandwidthUsage(SBP):
  """SBP class for message MSG_NETWORK_BANDWIDTH_USAGE (0x00BD).

  You can have MSG_NETWORK_BANDWIDTH_USAGE inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  The bandwidth usage, a list of usage by interface. 


  """
  __slots__ = ['interfaces',
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
          ('interfaces', (NetworkUsage._static_dtype(), (count,))),
        ])

    t = getattr(cls, 'static_dtype0', None)
    if not t:
      t = np.dtype([
          ('interfaces', (NetworkUsage._static_dtype(), (count,))),
        ])
      cls.static_dtype0 = t
    return t

  @classmethod
  def _dynamic_dtype(cls):
    t = getattr(cls, 'dynamic_dtype', None)
    if not t:    
      t = np.dtype([('interfaces', NetworkUsage._static_dtype()),])
      cls.dynamic_dtype = t
    return t

  @staticmethod
  def _unpack_members(res, element=False):
    d = {
      'interfaces': [] if res['interfaces'] is None else [NetworkUsage._unpack_members(x, element=True) for x in res['interfaces'].flatten()],
    }
    return d

  
SBP_MSG_CELL_MODEM_STATUS = 0x00BE
class MsgCellModemStatus(SBP):
  """SBP class for message MSG_CELL_MODEM_STATUS (0x00BE).

  You can have MSG_CELL_MODEM_STATUS inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  If a cell modem is present on a piksi device, this message
will be send periodically to update the host on the status
of the modem and its various parameters.


  """
  __slots__ = ['signal_strength',
               'signal_error_rate',
               'reserved',
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
          ('signal_strength', 'i1'),
          ('signal_error_rate', 'f4'),
          ('reserved', ('u1', (count,))),
        ])

    t = getattr(cls, 'static_dtype0', None)
    if not t:
      t = np.dtype([
          ('signal_strength', 'i1'),
          ('signal_error_rate', 'f4'),
          ('reserved', ('u1', (count,))),
        ])
      cls.static_dtype0 = t
    return t

  @classmethod
  def _dynamic_dtype(cls):
    t = getattr(cls, 'dynamic_dtype', None)
    if not t:    
      t = np.dtype([('reserved', 'u1'),])
      cls.dynamic_dtype = t
    return t

  @staticmethod
  def _unpack_members(res, element=False):
    d = {
      'signal_strength': int(res['signal_strength'] if element else res['signal_strength'][0]),
      'signal_error_rate': float(res['signal_error_rate'] if element else res['signal_error_rate'][0]),
      'reserved': [] if res['reserved'] is None else [x.item() for x in res['reserved'].flatten()],
    }
    return d

  
SBP_MSG_SPECAN_DEP = 0x0050
class MsgSpecanDep(SBP):
  """SBP class for message MSG_SPECAN_DEP (0x0050).

  You can have MSG_SPECAN_DEP inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  Deprecated.

  """
  __slots__ = ['channel_tag',
               't',
               'freq_ref',
               'freq_step',
               'amplitude_ref',
               'amplitude_unit',
               'amplitude_value',
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
          ('channel_tag', 'u2'),
          ('t', GPSTimeDep._static_dtype()),
          ('freq_ref', 'f4'),
          ('freq_step', 'f4'),
          ('amplitude_ref', 'f4'),
          ('amplitude_unit', 'f4'),
          ('amplitude_value', ('u1', (count,))),
        ])

    t = getattr(cls, 'static_dtype0', None)
    if not t:
      t = np.dtype([
          ('channel_tag', 'u2'),
          ('t', GPSTimeDep._static_dtype()),
          ('freq_ref', 'f4'),
          ('freq_step', 'f4'),
          ('amplitude_ref', 'f4'),
          ('amplitude_unit', 'f4'),
          ('amplitude_value', ('u1', (count,))),
        ])
      cls.static_dtype0 = t
    return t

  @classmethod
  def _dynamic_dtype(cls):
    t = getattr(cls, 'dynamic_dtype', None)
    if not t:    
      t = np.dtype([('amplitude_value', 'u1'),])
      cls.dynamic_dtype = t
    return t

  @staticmethod
  def _unpack_members(res, element=False):
    d = {
      'channel_tag': int(res['channel_tag'] if element else res['channel_tag'][0]),
      't': GPSTimeDep._unpack_members(res['t'], element=element),
      'freq_ref': float(res['freq_ref'] if element else res['freq_ref'][0]),
      'freq_step': float(res['freq_step'] if element else res['freq_step'][0]),
      'amplitude_ref': float(res['amplitude_ref'] if element else res['amplitude_ref'][0]),
      'amplitude_unit': float(res['amplitude_unit'] if element else res['amplitude_unit'][0]),
      'amplitude_value': [] if res['amplitude_value'] is None else [x.item() for x in res['amplitude_value'].flatten()],
    }
    return d

  
SBP_MSG_SPECAN = 0x0051
class MsgSpecan(SBP):
  """SBP class for message MSG_SPECAN (0x0051).

  You can have MSG_SPECAN inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  Spectrum analyzer packet.


  """
  __slots__ = ['channel_tag',
               't',
               'freq_ref',
               'freq_step',
               'amplitude_ref',
               'amplitude_unit',
               'amplitude_value',
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
          ('channel_tag', 'u2'),
          ('t', GPSTime._static_dtype()),
          ('freq_ref', 'f4'),
          ('freq_step', 'f4'),
          ('amplitude_ref', 'f4'),
          ('amplitude_unit', 'f4'),
          ('amplitude_value', ('u1', (count,))),
        ])

    t = getattr(cls, 'static_dtype0', None)
    if not t:
      t = np.dtype([
          ('channel_tag', 'u2'),
          ('t', GPSTime._static_dtype()),
          ('freq_ref', 'f4'),
          ('freq_step', 'f4'),
          ('amplitude_ref', 'f4'),
          ('amplitude_unit', 'f4'),
          ('amplitude_value', ('u1', (count,))),
        ])
      cls.static_dtype0 = t
    return t

  @classmethod
  def _dynamic_dtype(cls):
    t = getattr(cls, 'dynamic_dtype', None)
    if not t:    
      t = np.dtype([('amplitude_value', 'u1'),])
      cls.dynamic_dtype = t
    return t

  @staticmethod
  def _unpack_members(res, element=False):
    d = {
      'channel_tag': int(res['channel_tag'] if element else res['channel_tag'][0]),
      't': GPSTime._unpack_members(res['t'], element=element),
      'freq_ref': float(res['freq_ref'] if element else res['freq_ref'][0]),
      'freq_step': float(res['freq_step'] if element else res['freq_step'][0]),
      'amplitude_ref': float(res['amplitude_ref'] if element else res['amplitude_ref'][0]),
      'amplitude_unit': float(res['amplitude_unit'] if element else res['amplitude_unit'][0]),
      'amplitude_value': [] if res['amplitude_value'] is None else [x.item() for x in res['amplitude_value'].flatten()],
    }
    return d

  
SBP_MSG_FRONT_END_GAIN = 0x00BF
class MsgFrontEndGain(SBP):
  """SBP class for message MSG_FRONT_END_GAIN (0x00BF).

  You can have MSG_FRONT_END_GAIN inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  This message describes the gain of each channel in the receiver frontend. Each 
gain is encoded as a non-dimensional percentage relative to the maximum range  
possible for the gain stage of the frontend. By convention, each gain array 
has 8 entries and the index of the array corresponding to the index of the rf channel 
in the frontend. A gain of 127 percent encodes that rf channel is not present in the hardware.
A negative value implies an error for the particular gain stage as reported by the frontend.


  """
  __slots__ = ['rf_gain',
               'if_gain',
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
          ('rf_gain', ('i1', (8,))),
          ('if_gain', ('i1', (8,))),
        ])

    t = getattr(cls, 'static_dtype0', None)
    if not t:
      t = np.dtype([
          ('rf_gain', ('i1', (8,))),
          ('if_gain', ('i1', (8,))),
        ])
      cls.static_dtype0 = t
    return t

  @classmethod
  def _dynamic_dtype(cls):
    t = getattr(cls, 'dynamic_dtype', None)
    if not t:    
      t = np.dtype([('rf_gain', 'i1'),])
      cls.dynamic_dtype = t
    return t

  @staticmethod
  def _unpack_members(res, element=False):
    d = {
      'rf_gain': [] if res['rf_gain'] is None else [x.item() for x in res['rf_gain'].flatten()],
      'if_gain': [] if res['if_gain'] is None else [x.item() for x in res['if_gain'].flatten()],
    }
    return d

  

msg_classes = {
  0x0069: MsgAlmanac,
  0x0068: MsgSetTime,
  0x00B6: MsgReset,
  0x00B2: MsgResetDep,
  0x00C0: MsgCwResults,
  0x00C1: MsgCwStart,
  0x0022: MsgResetFilters,
  0x0023: MsgInitBase,
  0x0017: MsgThreadState,
  0x001D: MsgUartState,
  0x0018: MsgUartStateDepa,
  0x0019: MsgIarState,
  0x002B: MsgMaskSatellite,
  0x001B: MsgMaskSatelliteDep,
  0x00B5: MsgDeviceMonitor,
  0x00B8: MsgCommandReq,
  0x00B9: MsgCommandResp,
  0x00BC: MsgCommandOutput,
  0x00BA: MsgNetworkStateReq,
  0x00BB: MsgNetworkStateResp,
  0x00BD: MsgNetworkBandwidthUsage,
  0x00BE: MsgCellModemStatus,
  0x0050: MsgSpecanDep,
  0x0051: MsgSpecan,
  0x00BF: MsgFrontEndGain,
}