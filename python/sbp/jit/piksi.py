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
  @classmethod
  def parse_members(cls, buf, offset, length):
    ret = {}
    (__filter, offset, length) = get_u8(buf, offset, length)
    ret['filter'] = __filter
    return ret, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.filter = res['filter']
    return res, off, length

  @classmethod
  def _payload_size(self):
    ret = 0
    # filter: u8
    ret += 1
    return ret
  
SBP_MSG_INIT_BASE_DEP = 0x0023
class MsgInitBaseDep(SBP):
  """SBP class for message MSG_INIT_BASE_DEP (0x0023).

  You can have MSG_INIT_BASE_DEP inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  Deprecated

  """
  __slots__ = []
  def _unpack_members(self, buf, offset, length):
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
  @classmethod
  def parse_members(cls, buf, offset, length):
    ret = {}
    (__name, offset, length) = get_fixed_string(20)(buf, offset, length)
    ret['name'] = __name
    (__cpu, offset, length) = get_u16(buf, offset, length)
    ret['cpu'] = __cpu
    (__stack_free, offset, length) = get_u32(buf, offset, length)
    ret['stack_free'] = __stack_free
    return ret, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.name = res['name']
    self.cpu = res['cpu']
    self.stack_free = res['stack_free']
    return res, off, length

  @classmethod
  def _payload_size(self):
    ret = 0
    # name: string
    ret += 20
    # cpu: u16
    ret += 2
    # stack_free: u32
    ret += 4
    return ret
  
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
  @classmethod
  def parse_members(cls, buf, offset, length):
    ret = {}
    (__tx_throughput, offset, length) = get_f32(buf, offset, length)
    ret['tx_throughput'] = judicious_round(np.float32(__tx_throughput)) if SBP.judicious_rounding else __tx_throughput
    (__rx_throughput, offset, length) = get_f32(buf, offset, length)
    ret['rx_throughput'] = judicious_round(np.float32(__rx_throughput)) if SBP.judicious_rounding else __rx_throughput
    (__crc_error_count, offset, length) = get_u16(buf, offset, length)
    ret['crc_error_count'] = __crc_error_count
    (__io_error_count, offset, length) = get_u16(buf, offset, length)
    ret['io_error_count'] = __io_error_count
    (__tx_buffer_level, offset, length) = get_u8(buf, offset, length)
    ret['tx_buffer_level'] = __tx_buffer_level
    (__rx_buffer_level, offset, length) = get_u8(buf, offset, length)
    ret['rx_buffer_level'] = __rx_buffer_level
    return ret, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.tx_throughput = res['tx_throughput']
    self.rx_throughput = res['rx_throughput']
    self.crc_error_count = res['crc_error_count']
    self.io_error_count = res['io_error_count']
    self.tx_buffer_level = res['tx_buffer_level']
    self.rx_buffer_level = res['rx_buffer_level']
    return res, off, length

  @classmethod
  def _payload_size(self):
    ret = 0
    # tx_throughput: float
    ret += 4
    # rx_throughput: float
    ret += 4
    # crc_error_count: u16
    ret += 2
    # io_error_count: u16
    ret += 2
    # tx_buffer_level: u8
    ret += 1
    # rx_buffer_level: u8
    ret += 1
    return ret
  
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
  @classmethod
  def parse_members(cls, buf, offset, length):
    ret = {}
    (__avg, offset, length) = get_s32(buf, offset, length)
    ret['avg'] = __avg
    (__pmin, offset, length) = get_s32(buf, offset, length)
    ret['pmin'] = __pmin
    (__pmax, offset, length) = get_s32(buf, offset, length)
    ret['pmax'] = __pmax
    (__current, offset, length) = get_s32(buf, offset, length)
    ret['current'] = __current
    return ret, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.avg = res['avg']
    self.pmin = res['pmin']
    self.pmax = res['pmax']
    self.current = res['current']
    return res, off, length

  @classmethod
  def _payload_size(self):
    ret = 0
    # avg: s32
    ret += 4
    # pmin: s32
    ret += 4
    # pmax: s32
    ret += 4
    # current: s32
    ret += 4
    return ret
  
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
  @classmethod
  def parse_members(cls, buf, offset, length):
    ret = {}
    (__avg, offset, length) = get_s32(buf, offset, length)
    ret['avg'] = __avg
    (__lmin, offset, length) = get_s32(buf, offset, length)
    ret['lmin'] = __lmin
    (__lmax, offset, length) = get_s32(buf, offset, length)
    ret['lmax'] = __lmax
    (__current, offset, length) = get_s32(buf, offset, length)
    ret['current'] = __current
    return ret, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.avg = res['avg']
    self.lmin = res['lmin']
    self.lmax = res['lmax']
    self.current = res['current']
    return res, off, length

  @classmethod
  def _payload_size(self):
    ret = 0
    # avg: s32
    ret += 4
    # lmin: s32
    ret += 4
    # lmax: s32
    ret += 4
    # current: s32
    ret += 4
    return ret
  
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
  @classmethod
  def parse_members(cls, buf, offset, length):
    ret = {}
    (__uart_a, offset, length) = UARTChannel.parse_members(buf, offset, length)
    ret['uart_a'] = __uart_a
    (__uart_b, offset, length) = UARTChannel.parse_members(buf, offset, length)
    ret['uart_b'] = __uart_b
    (__uart_ftdi, offset, length) = UARTChannel.parse_members(buf, offset, length)
    ret['uart_ftdi'] = __uart_ftdi
    (__latency, offset, length) = Latency.parse_members(buf, offset, length)
    ret['latency'] = __latency
    (__obs_period, offset, length) = Period.parse_members(buf, offset, length)
    ret['obs_period'] = __obs_period
    return ret, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.uart_a = res['uart_a']
    self.uart_b = res['uart_b']
    self.uart_ftdi = res['uart_ftdi']
    self.latency = res['latency']
    self.obs_period = res['obs_period']
    return res, off, length

  @classmethod
  def _payload_size(self):
    ret = 0
    # uart_a: UARTChannel
    ret += UARTChannel._payload_size()
    # uart_b: UARTChannel
    ret += UARTChannel._payload_size()
    # uart_ftdi: UARTChannel
    ret += UARTChannel._payload_size()
    # latency: Latency
    ret += Latency._payload_size()
    # obs_period: Period
    ret += Period._payload_size()
    return ret
  
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
  @classmethod
  def parse_members(cls, buf, offset, length):
    ret = {}
    (__uart_a, offset, length) = UARTChannel.parse_members(buf, offset, length)
    ret['uart_a'] = __uart_a
    (__uart_b, offset, length) = UARTChannel.parse_members(buf, offset, length)
    ret['uart_b'] = __uart_b
    (__uart_ftdi, offset, length) = UARTChannel.parse_members(buf, offset, length)
    ret['uart_ftdi'] = __uart_ftdi
    (__latency, offset, length) = Latency.parse_members(buf, offset, length)
    ret['latency'] = __latency
    return ret, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.uart_a = res['uart_a']
    self.uart_b = res['uart_b']
    self.uart_ftdi = res['uart_ftdi']
    self.latency = res['latency']
    return res, off, length

  @classmethod
  def _payload_size(self):
    ret = 0
    # uart_a: UARTChannel
    ret += UARTChannel._payload_size()
    # uart_b: UARTChannel
    ret += UARTChannel._payload_size()
    # uart_ftdi: UARTChannel
    ret += UARTChannel._payload_size()
    # latency: Latency
    ret += Latency._payload_size()
    return ret
  
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
  @classmethod
  def parse_members(cls, buf, offset, length):
    ret = {}
    (__num_hyps, offset, length) = get_u32(buf, offset, length)
    ret['num_hyps'] = __num_hyps
    return ret, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.num_hyps = res['num_hyps']
    return res, off, length

  @classmethod
  def _payload_size(self):
    ret = 0
    # num_hyps: u32
    ret += 4
    return ret
  
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
  @classmethod
  def parse_members(cls, buf, offset, length):
    ret = {}
    (__mask, offset, length) = get_u8(buf, offset, length)
    ret['mask'] = __mask
    (__sid, offset, length) = GnssSignal.parse_members(buf, offset, length)
    ret['sid'] = __sid
    return ret, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.mask = res['mask']
    self.sid = res['sid']
    return res, off, length

  @classmethod
  def _payload_size(self):
    ret = 0
    # mask: u8
    ret += 1
    # sid: GnssSignal
    ret += GnssSignal._payload_size()
    return ret
  
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
  @classmethod
  def parse_members(cls, buf, offset, length):
    ret = {}
    (__mask, offset, length) = get_u8(buf, offset, length)
    ret['mask'] = __mask
    (__sid, offset, length) = GnssSignalDep.parse_members(buf, offset, length)
    ret['sid'] = __sid
    return ret, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.mask = res['mask']
    self.sid = res['sid']
    return res, off, length

  @classmethod
  def _payload_size(self):
    ret = 0
    # mask: u8
    ret += 1
    # sid: GnssSignalDep
    ret += GnssSignalDep._payload_size()
    return ret
  
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
  @classmethod
  def parse_members(cls, buf, offset, length):
    ret = {}
    (__dev_vin, offset, length) = get_s16(buf, offset, length)
    ret['dev_vin'] = __dev_vin
    (__cpu_vint, offset, length) = get_s16(buf, offset, length)
    ret['cpu_vint'] = __cpu_vint
    (__cpu_vaux, offset, length) = get_s16(buf, offset, length)
    ret['cpu_vaux'] = __cpu_vaux
    (__cpu_temperature, offset, length) = get_s16(buf, offset, length)
    ret['cpu_temperature'] = __cpu_temperature
    (__fe_temperature, offset, length) = get_s16(buf, offset, length)
    ret['fe_temperature'] = __fe_temperature
    return ret, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.dev_vin = res['dev_vin']
    self.cpu_vint = res['cpu_vint']
    self.cpu_vaux = res['cpu_vaux']
    self.cpu_temperature = res['cpu_temperature']
    self.fe_temperature = res['fe_temperature']
    return res, off, length

  @classmethod
  def _payload_size(self):
    ret = 0
    # dev_vin: s16
    ret += 2
    # cpu_vint: s16
    ret += 2
    # cpu_vaux: s16
    ret += 2
    # cpu_temperature: s16
    ret += 2
    # fe_temperature: s16
    ret += 2
    return ret
  
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
  @classmethod
  def parse_members(cls, buf, offset, length):
    ret = {}
    (__sequence, offset, length) = get_u32(buf, offset, length)
    ret['sequence'] = __sequence
    (__command, offset, length) = get_string(buf, offset, length)
    ret['command'] = __command
    return ret, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.sequence = res['sequence']
    self.command = res['command']
    return res, off, length

  @classmethod
  def _payload_size(self):
    ret = 0
    # sequence: u32
    ret += 4
    # command: string
    ret += 247
    return ret
  
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
  @classmethod
  def parse_members(cls, buf, offset, length):
    ret = {}
    (__sequence, offset, length) = get_u32(buf, offset, length)
    ret['sequence'] = __sequence
    (__code, offset, length) = get_s32(buf, offset, length)
    ret['code'] = __code
    return ret, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.sequence = res['sequence']
    self.code = res['code']
    return res, off, length

  @classmethod
  def _payload_size(self):
    ret = 0
    # sequence: u32
    ret += 4
    # code: s32
    ret += 4
    return ret
  
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
  @classmethod
  def parse_members(cls, buf, offset, length):
    ret = {}
    (__sequence, offset, length) = get_u32(buf, offset, length)
    ret['sequence'] = __sequence
    (__line, offset, length) = get_string(buf, offset, length)
    ret['line'] = __line
    return ret, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.sequence = res['sequence']
    self.line = res['line']
    return res, off, length

  @classmethod
  def _payload_size(self):
    ret = 0
    # sequence: u32
    ret += 4
    # line: string
    ret += 247
    return ret
  
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
  @classmethod
  def parse_members(cls, buf, offset, length):
    ret = {}
    (__ipv4_address, offset, length) = get_fixed_array(get_u8, 4, 1)(buf, offset, length)
    ret['ipv4_address'] = __ipv4_address
    (__ipv4_mask_size, offset, length) = get_u8(buf, offset, length)
    ret['ipv4_mask_size'] = __ipv4_mask_size
    (__ipv6_address, offset, length) = get_fixed_array(get_u8, 16, 1)(buf, offset, length)
    ret['ipv6_address'] = __ipv6_address
    (__ipv6_mask_size, offset, length) = get_u8(buf, offset, length)
    ret['ipv6_mask_size'] = __ipv6_mask_size
    (__rx_bytes, offset, length) = get_u32(buf, offset, length)
    ret['rx_bytes'] = __rx_bytes
    (__tx_bytes, offset, length) = get_u32(buf, offset, length)
    ret['tx_bytes'] = __tx_bytes
    (__interface_name, offset, length) = get_fixed_string(16)(buf, offset, length)
    ret['interface_name'] = __interface_name
    (__flags, offset, length) = get_u32(buf, offset, length)
    ret['flags'] = __flags
    return ret, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.ipv4_address = res['ipv4_address']
    self.ipv4_mask_size = res['ipv4_mask_size']
    self.ipv6_address = res['ipv6_address']
    self.ipv6_mask_size = res['ipv6_mask_size']
    self.rx_bytes = res['rx_bytes']
    self.tx_bytes = res['tx_bytes']
    self.interface_name = res['interface_name']
    self.flags = res['flags']
    return res, off, length

  @classmethod
  def _payload_size(self):
    ret = 0
    # ipv4_address: array of u8
    ret += 1 * 4
    # ipv4_mask_size: u8
    ret += 1
    # ipv6_address: array of u8
    ret += 1 * 16
    # ipv6_mask_size: u8
    ret += 1
    # rx_bytes: u32
    ret += 4
    # tx_bytes: u32
    ret += 4
    # interface_name: string
    ret += 16
    # flags: u32
    ret += 4
    return ret
  
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
  @classmethod
  def parse_members(cls, buf, offset, length):
    ret = {}
    (__duration, offset, length) = get_u64(buf, offset, length)
    ret['duration'] = __duration
    (__total_bytes, offset, length) = get_u64(buf, offset, length)
    ret['total_bytes'] = __total_bytes
    (__rx_bytes, offset, length) = get_u32(buf, offset, length)
    ret['rx_bytes'] = __rx_bytes
    (__tx_bytes, offset, length) = get_u32(buf, offset, length)
    ret['tx_bytes'] = __tx_bytes
    (__interface_name, offset, length) = get_fixed_string(16)(buf, offset, length)
    ret['interface_name'] = __interface_name
    return ret, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.duration = res['duration']
    self.total_bytes = res['total_bytes']
    self.rx_bytes = res['rx_bytes']
    self.tx_bytes = res['tx_bytes']
    self.interface_name = res['interface_name']
    return res, off, length

  @classmethod
  def _payload_size(self):
    ret = 0
    # duration: u64
    ret += 8
    # total_bytes: u64
    ret += 8
    # rx_bytes: u32
    ret += 4
    # tx_bytes: u32
    ret += 4
    # interface_name: string
    ret += 16
    return ret
  
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
  @classmethod
  def parse_members(cls, buf, offset, length):
    ret = {}
    (__interfaces, offset, length) = get_array(NetworkUsage.parse_members)(buf, offset, length)
    ret['interfaces'] = __interfaces
    return ret, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.interfaces = res['interfaces']
    return res, off, length

  @classmethod
  def _payload_size(self):
    ret = 0
    # interfaces: array of NetworkUsage
    ret += 247
    return ret
  
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
  @classmethod
  def parse_members(cls, buf, offset, length):
    ret = {}
    (__signal_strength, offset, length) = get_s8(buf, offset, length)
    ret['signal_strength'] = __signal_strength
    (__signal_error_rate, offset, length) = get_f32(buf, offset, length)
    ret['signal_error_rate'] = judicious_round(np.float32(__signal_error_rate)) if SBP.judicious_rounding else __signal_error_rate
    (__reserved, offset, length) = get_array(get_u8)(buf, offset, length)
    ret['reserved'] = __reserved
    return ret, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.signal_strength = res['signal_strength']
    self.signal_error_rate = res['signal_error_rate']
    self.reserved = res['reserved']
    return res, off, length

  @classmethod
  def _payload_size(self):
    ret = 0
    # signal_strength: s8
    ret += 1
    # signal_error_rate: float
    ret += 4
    # reserved: array of u8
    ret += 247
    return ret
  
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
  @classmethod
  def parse_members(cls, buf, offset, length):
    ret = {}
    (__channel_tag, offset, length) = get_u16(buf, offset, length)
    ret['channel_tag'] = __channel_tag
    (__t, offset, length) = GPSTimeDep.parse_members(buf, offset, length)
    ret['t'] = __t
    (__freq_ref, offset, length) = get_f32(buf, offset, length)
    ret['freq_ref'] = judicious_round(np.float32(__freq_ref)) if SBP.judicious_rounding else __freq_ref
    (__freq_step, offset, length) = get_f32(buf, offset, length)
    ret['freq_step'] = judicious_round(np.float32(__freq_step)) if SBP.judicious_rounding else __freq_step
    (__amplitude_ref, offset, length) = get_f32(buf, offset, length)
    ret['amplitude_ref'] = judicious_round(np.float32(__amplitude_ref)) if SBP.judicious_rounding else __amplitude_ref
    (__amplitude_unit, offset, length) = get_f32(buf, offset, length)
    ret['amplitude_unit'] = judicious_round(np.float32(__amplitude_unit)) if SBP.judicious_rounding else __amplitude_unit
    (__amplitude_value, offset, length) = get_array(get_u8)(buf, offset, length)
    ret['amplitude_value'] = __amplitude_value
    return ret, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.channel_tag = res['channel_tag']
    self.t = res['t']
    self.freq_ref = res['freq_ref']
    self.freq_step = res['freq_step']
    self.amplitude_ref = res['amplitude_ref']
    self.amplitude_unit = res['amplitude_unit']
    self.amplitude_value = res['amplitude_value']
    return res, off, length

  @classmethod
  def _payload_size(self):
    ret = 0
    # channel_tag: u16
    ret += 2
    # t: GPSTimeDep
    ret += GPSTimeDep._payload_size()
    # freq_ref: float
    ret += 4
    # freq_step: float
    ret += 4
    # amplitude_ref: float
    ret += 4
    # amplitude_unit: float
    ret += 4
    # amplitude_value: array of u8
    ret += 247
    return ret
  
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
  @classmethod
  def parse_members(cls, buf, offset, length):
    ret = {}
    (__channel_tag, offset, length) = get_u16(buf, offset, length)
    ret['channel_tag'] = __channel_tag
    (__t, offset, length) = GPSTime.parse_members(buf, offset, length)
    ret['t'] = __t
    (__freq_ref, offset, length) = get_f32(buf, offset, length)
    ret['freq_ref'] = judicious_round(np.float32(__freq_ref)) if SBP.judicious_rounding else __freq_ref
    (__freq_step, offset, length) = get_f32(buf, offset, length)
    ret['freq_step'] = judicious_round(np.float32(__freq_step)) if SBP.judicious_rounding else __freq_step
    (__amplitude_ref, offset, length) = get_f32(buf, offset, length)
    ret['amplitude_ref'] = judicious_round(np.float32(__amplitude_ref)) if SBP.judicious_rounding else __amplitude_ref
    (__amplitude_unit, offset, length) = get_f32(buf, offset, length)
    ret['amplitude_unit'] = judicious_round(np.float32(__amplitude_unit)) if SBP.judicious_rounding else __amplitude_unit
    (__amplitude_value, offset, length) = get_array(get_u8)(buf, offset, length)
    ret['amplitude_value'] = __amplitude_value
    return ret, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.channel_tag = res['channel_tag']
    self.t = res['t']
    self.freq_ref = res['freq_ref']
    self.freq_step = res['freq_step']
    self.amplitude_ref = res['amplitude_ref']
    self.amplitude_unit = res['amplitude_unit']
    self.amplitude_value = res['amplitude_value']
    return res, off, length

  @classmethod
  def _payload_size(self):
    ret = 0
    # channel_tag: u16
    ret += 2
    # t: GPSTime
    ret += GPSTime._payload_size()
    # freq_ref: float
    ret += 4
    # freq_step: float
    ret += 4
    # amplitude_ref: float
    ret += 4
    # amplitude_unit: float
    ret += 4
    # amplitude_value: array of u8
    ret += 247
    return ret
  
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
  @classmethod
  def parse_members(cls, buf, offset, length):
    ret = {}
    (__rf_gain, offset, length) = get_fixed_array(get_s8, 8, 1)(buf, offset, length)
    ret['rf_gain'] = __rf_gain
    (__if_gain, offset, length) = get_fixed_array(get_s8, 8, 1)(buf, offset, length)
    ret['if_gain'] = __if_gain
    return ret, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.rf_gain = res['rf_gain']
    self.if_gain = res['if_gain']
    return res, off, length

  @classmethod
  def _payload_size(self):
    ret = 0
    # rf_gain: array of s8
    ret += 1 * 8
    # if_gain: array of s8
    ret += 1 * 8
    return ret
  

msg_classes = {
  0x0069: MsgAlmanac,
  0x0068: MsgSetTime,
  0x00B6: MsgReset,
  0x00B2: MsgResetDep,
  0x00C0: MsgCwResults,
  0x00C1: MsgCwStart,
  0x0022: MsgResetFilters,
  0x0023: MsgInitBaseDep,
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