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

import construct

from sbp.msg import SBP, SENDER_ID
from sbp.utils import fmt_repr, exclude_fields, walk_json_dict, containerize
from sbp.gnss import *

# Automatically generated from piksi/yaml/swiftnav/sbp/piksi.yaml with generate.py.
# Please do not hand edit!


class UARTChannel(object):
  """UARTChannel.
  
  Throughput, utilization, and error counts on the RX/TX buffers
of this UART channel. The reported percentage values must
be normalized.

  
  Parameters
  ----------
  tx_throughput : float
    UART transmit throughput
  rx_throughput : float
    UART receive throughput
  crc_error_count : int
    UART CRC error count
  io_error_count : int
    UART IO error count
  tx_buffer_level : int
    UART transmit buffer percentage utilization (ranges from
0 to 255)

  rx_buffer_level : int
    UART receive buffer percentage utilization (ranges from
0 to 255)


  """
  _parser = construct.Embedded(construct.Struct(
                     'tx_throughput' / construct.Float32l,
                     'rx_throughput' / construct.Float32l,
                     'crc_error_count' / construct.Int16ul,
                     'io_error_count' / construct.Int16ul,
                     'tx_buffer_level' / construct.Int8ul,
                     'rx_buffer_level' / construct.Int8ul,))
  __slots__ = [
               'tx_throughput',
               'rx_throughput',
               'crc_error_count',
               'io_error_count',
               'tx_buffer_level',
               'rx_buffer_level',
              ]

  def __init__(self, payload=None, **kwargs):
    if payload:
      self.from_binary(payload)
    else:
      self.tx_throughput = kwargs.pop('tx_throughput')
      self.rx_throughput = kwargs.pop('rx_throughput')
      self.crc_error_count = kwargs.pop('crc_error_count')
      self.io_error_count = kwargs.pop('io_error_count')
      self.tx_buffer_level = kwargs.pop('tx_buffer_level')
      self.rx_buffer_level = kwargs.pop('rx_buffer_level')

  def __repr__(self):
    return fmt_repr(self)
  
  def from_binary(self, d):
    p = UARTChannel._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    d = dict([(k, getattr(obj, k)) for k in self.__slots__])
    return UARTChannel.build(d)
    
class Period(object):
  """Period.
  
  Statistics on the period of observations received from the base
station. As complete observation sets are received, their time
of reception is compared with the prior set''s time of reception.
This measurement provides a proxy for link quality as incomplete
or missing sets will increase the period.  Long periods
can cause momentary RTK solution outages.

  
  Parameters
  ----------
  avg : int
    Average period
  pmin : int
    Minimum period
  pmax : int
    Maximum period
  current : int
    Smoothed estimate of the current period

  """
  _parser = construct.Embedded(construct.Struct(
                     'avg' / construct.Int32sl,
                     'pmin' / construct.Int32sl,
                     'pmax' / construct.Int32sl,
                     'current' / construct.Int32sl,))
  __slots__ = [
               'avg',
               'pmin',
               'pmax',
               'current',
              ]

  def __init__(self, payload=None, **kwargs):
    if payload:
      self.from_binary(payload)
    else:
      self.avg = kwargs.pop('avg')
      self.pmin = kwargs.pop('pmin')
      self.pmax = kwargs.pop('pmax')
      self.current = kwargs.pop('current')

  def __repr__(self):
    return fmt_repr(self)
  
  def from_binary(self, d):
    p = Period._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    d = dict([(k, getattr(obj, k)) for k in self.__slots__])
    return Period.build(d)
    
class Latency(object):
  """Latency.
  
  Statistics on the latency of observations received from the base
station. As observation packets are received their GPS time is
compared to the current GPS time calculated locally by the
receiver to give a precise measurement of the end-to-end
communication latency in the system.

  
  Parameters
  ----------
  avg : int
    Average latency
  lmin : int
    Minimum latency
  lmax : int
    Maximum latency
  current : int
    Smoothed estimate of the current latency

  """
  _parser = construct.Embedded(construct.Struct(
                     'avg' / construct.Int32sl,
                     'lmin' / construct.Int32sl,
                     'lmax' / construct.Int32sl,
                     'current' / construct.Int32sl,))
  __slots__ = [
               'avg',
               'lmin',
               'lmax',
               'current',
              ]

  def __init__(self, payload=None, **kwargs):
    if payload:
      self.from_binary(payload)
    else:
      self.avg = kwargs.pop('avg')
      self.lmin = kwargs.pop('lmin')
      self.lmax = kwargs.pop('lmax')
      self.current = kwargs.pop('current')

  def __repr__(self):
    return fmt_repr(self)
  
  def from_binary(self, d):
    p = Latency._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    d = dict([(k, getattr(obj, k)) for k in self.__slots__])
    return Latency.build(d)
    
class NetworkUsage(object):
  """NetworkUsage.
  
  The bandwidth usage for each interface can be reported
within this struct and utilize multiple fields to fully
specify the type of traffic that is being tracked. As
either the interval of collection or the collection time
may vary, both a timestamp and period field is provided,
though may not necessarily be populated with a value. 

  
  Parameters
  ----------
  duration : int
    Duration over which the measurement was collected
  total_bytes : int
    Number of bytes handled in total within period
  rx_bytes : int
    Number of bytes transmitted within period
  tx_bytes : int
    Number of bytes received within period
  interface_name : string
    Interface Name

  """
  _parser = construct.Embedded(construct.Struct(
                     'duration' / construct.Int64ul,
                     'total_bytes' / construct.Int64ul,
                     'rx_bytes' / construct.Int32ul,
                     'tx_bytes' / construct.Int32ul,
                     'interface_name'/ construct.Bytes(16),))
  __slots__ = [
               'duration',
               'total_bytes',
               'rx_bytes',
               'tx_bytes',
               'interface_name',
              ]

  def __init__(self, payload=None, **kwargs):
    if payload:
      self.from_binary(payload)
    else:
      self.duration = kwargs.pop('duration')
      self.total_bytes = kwargs.pop('total_bytes')
      self.rx_bytes = kwargs.pop('rx_bytes')
      self.tx_bytes = kwargs.pop('tx_bytes')
      self.interface_name = kwargs.pop('interface_name')

  def __repr__(self):
    return fmt_repr(self)
  
  def from_binary(self, d):
    p = NetworkUsage._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    d = dict([(k, getattr(obj, k)) for k in self.__slots__])
    return NetworkUsage.build(d)
    
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

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      super( MsgAlmanac,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.payload = sbp.payload
    else:
      super( MsgAlmanac, self).__init__()
      self.msg_type = SBP_MSG_ALMANAC
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.payload = ""

  def __repr__(self):
    return fmt_repr(self)

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    return MsgAlmanac.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgAlmanac(sbp, **d)

 
    
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

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      super( MsgSetTime,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.payload = sbp.payload
    else:
      super( MsgSetTime, self).__init__()
      self.msg_type = SBP_MSG_SET_TIME
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.payload = ""

  def __repr__(self):
    return fmt_repr(self)

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    return MsgSetTime.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgSetTime(sbp, **d)

 
    
SBP_MSG_RESET = 0x00B6
class MsgReset(SBP):
  """SBP class for message MSG_RESET (0x00B6).

  You can have MSG_RESET inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  This message from the host resets the Piksi back into the
bootloader.


  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  flags : int
    Reset flags
  sender : int
    Optional sender ID, defaults to SENDER_ID (see sbp/msg.py).

  """
  _parser = construct.Struct(
                   'flags' / construct.Int32ul,)
  __slots__ = [
               'flags',
              ]

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      super( MsgReset,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.from_binary(sbp.payload)
    else:
      super( MsgReset, self).__init__()
      self.msg_type = SBP_MSG_RESET
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.flags = kwargs.pop('flags')

  def __repr__(self):
    return fmt_repr(self)

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    return MsgReset.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgReset(sbp, **d)

 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgReset._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgReset._parser.build(c)
    return self.pack()

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgReset, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
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

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      super( MsgResetDep,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.payload = sbp.payload
    else:
      super( MsgResetDep, self).__init__()
      self.msg_type = SBP_MSG_RESET_DEP
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.payload = ""

  def __repr__(self):
    return fmt_repr(self)

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    return MsgResetDep.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgResetDep(sbp, **d)

 
    
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

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      super( MsgCwResults,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.payload = sbp.payload
    else:
      super( MsgCwResults, self).__init__()
      self.msg_type = SBP_MSG_CW_RESULTS
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.payload = ""

  def __repr__(self):
    return fmt_repr(self)

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    return MsgCwResults.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgCwResults(sbp, **d)

 
    
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

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      super( MsgCwStart,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.payload = sbp.payload
    else:
      super( MsgCwStart, self).__init__()
      self.msg_type = SBP_MSG_CW_START
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.payload = ""

  def __repr__(self):
    return fmt_repr(self)

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    return MsgCwStart.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgCwStart(sbp, **d)

 
    
SBP_MSG_RESET_FILTERS = 0x0022
class MsgResetFilters(SBP):
  """SBP class for message MSG_RESET_FILTERS (0x0022).

  You can have MSG_RESET_FILTERS inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  This message resets either the DGNSS Kalman filters or Integer
Ambiguity Resolution (IAR) process.


  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  filter : int
    Filter flags
  sender : int
    Optional sender ID, defaults to SENDER_ID (see sbp/msg.py).

  """
  _parser = construct.Struct(
                   'filter' / construct.Int8ul,)
  __slots__ = [
               'filter',
              ]

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      super( MsgResetFilters,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.from_binary(sbp.payload)
    else:
      super( MsgResetFilters, self).__init__()
      self.msg_type = SBP_MSG_RESET_FILTERS
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.filter = kwargs.pop('filter')

  def __repr__(self):
    return fmt_repr(self)

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    return MsgResetFilters.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgResetFilters(sbp, **d)

 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgResetFilters._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgResetFilters._parser.build(c)
    return self.pack()

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgResetFilters, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
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

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      super( MsgInitBase,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.payload = sbp.payload
    else:
      super( MsgInitBase, self).__init__()
      self.msg_type = SBP_MSG_INIT_BASE
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.payload = ""

  def __repr__(self):
    return fmt_repr(self)

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    return MsgInitBase.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgInitBase(sbp, **d)

 
    
SBP_MSG_THREAD_STATE = 0x0017
class MsgThreadState(SBP):
  """SBP class for message MSG_THREAD_STATE (0x0017).

  You can have MSG_THREAD_STATE inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  The thread usage message from the device reports real-time
operating system (RTOS) thread usage statistics for the named
thread. The reported percentage values must be normalized.


  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  name : string
    Thread name (NULL terminated)
  cpu : int
    Percentage cpu use for this thread. Values range from 0
- 1000 and needs to be renormalized to 100

  stack_free : int
    Free stack space for this thread
  sender : int
    Optional sender ID, defaults to SENDER_ID (see sbp/msg.py).

  """
  _parser = construct.Struct(
                   'name'/ construct.Bytes(20),
                   'cpu' / construct.Int16ul,
                   'stack_free' / construct.Int32ul,)
  __slots__ = [
               'name',
               'cpu',
               'stack_free',
              ]

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      super( MsgThreadState,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.from_binary(sbp.payload)
    else:
      super( MsgThreadState, self).__init__()
      self.msg_type = SBP_MSG_THREAD_STATE
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.name = kwargs.pop('name')
      self.cpu = kwargs.pop('cpu')
      self.stack_free = kwargs.pop('stack_free')

  def __repr__(self):
    return fmt_repr(self)

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    return MsgThreadState.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgThreadState(sbp, **d)

 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgThreadState._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgThreadState._parser.build(c)
    return self.pack()

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgThreadState, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
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


  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  uart_a : UARTChannel
    State of UART A
  uart_b : UARTChannel
    State of UART B
  uart_ftdi : UARTChannel
    State of UART FTDI (USB logger)
  latency : Latency
    UART communication latency
  obs_period : Period
    Observation receipt period
  sender : int
    Optional sender ID, defaults to SENDER_ID (see sbp/msg.py).

  """
  _parser = construct.Struct(
                   'uart_a' / construct.Struct(UARTChannel._parser),
                   'uart_b' / construct.Struct(UARTChannel._parser),
                   'uart_ftdi' / construct.Struct(UARTChannel._parser),
                   'latency' / construct.Struct(Latency._parser),
                   'obs_period' / construct.Struct(Period._parser),)
  __slots__ = [
               'uart_a',
               'uart_b',
               'uart_ftdi',
               'latency',
               'obs_period',
              ]

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      super( MsgUartState,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.from_binary(sbp.payload)
    else:
      super( MsgUartState, self).__init__()
      self.msg_type = SBP_MSG_UART_STATE
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.uart_a = kwargs.pop('uart_a')
      self.uart_b = kwargs.pop('uart_b')
      self.uart_ftdi = kwargs.pop('uart_ftdi')
      self.latency = kwargs.pop('latency')
      self.obs_period = kwargs.pop('obs_period')

  def __repr__(self):
    return fmt_repr(self)

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    return MsgUartState.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgUartState(sbp, **d)

 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgUartState._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgUartState._parser.build(c)
    return self.pack()

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgUartState, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    
SBP_MSG_UART_STATE_DEPA = 0x0018
class MsgUartStateDepa(SBP):
  """SBP class for message MSG_UART_STATE_DEPA (0x0018).

  You can have MSG_UART_STATE_DEPA inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  Deprecated

  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  uart_a : UARTChannel
    State of UART A
  uart_b : UARTChannel
    State of UART B
  uart_ftdi : UARTChannel
    State of UART FTDI (USB logger)
  latency : Latency
    UART communication latency
  sender : int
    Optional sender ID, defaults to SENDER_ID (see sbp/msg.py).

  """
  _parser = construct.Struct(
                   'uart_a' / construct.Struct(UARTChannel._parser),
                   'uart_b' / construct.Struct(UARTChannel._parser),
                   'uart_ftdi' / construct.Struct(UARTChannel._parser),
                   'latency' / construct.Struct(Latency._parser),)
  __slots__ = [
               'uart_a',
               'uart_b',
               'uart_ftdi',
               'latency',
              ]

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      super( MsgUartStateDepa,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.from_binary(sbp.payload)
    else:
      super( MsgUartStateDepa, self).__init__()
      self.msg_type = SBP_MSG_UART_STATE_DEPA
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.uart_a = kwargs.pop('uart_a')
      self.uart_b = kwargs.pop('uart_b')
      self.uart_ftdi = kwargs.pop('uart_ftdi')
      self.latency = kwargs.pop('latency')

  def __repr__(self):
    return fmt_repr(self)

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    return MsgUartStateDepa.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgUartStateDepa(sbp, **d)

 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgUartStateDepa._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgUartStateDepa._parser.build(c)
    return self.pack()

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgUartStateDepa, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
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


  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  num_hyps : int
    Number of integer ambiguity hypotheses remaining
  sender : int
    Optional sender ID, defaults to SENDER_ID (see sbp/msg.py).

  """
  _parser = construct.Struct(
                   'num_hyps' / construct.Int32ul,)
  __slots__ = [
               'num_hyps',
              ]

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      super( MsgIarState,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.from_binary(sbp.payload)
    else:
      super( MsgIarState, self).__init__()
      self.msg_type = SBP_MSG_IAR_STATE
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.num_hyps = kwargs.pop('num_hyps')

  def __repr__(self):
    return fmt_repr(self)

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    return MsgIarState.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgIarState(sbp, **d)

 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgIarState._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgIarState._parser.build(c)
    return self.pack()

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgIarState, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    
SBP_MSG_MASK_SATELLITE = 0x002B
class MsgMaskSatellite(SBP):
  """SBP class for message MSG_MASK_SATELLITE (0x002B).

  You can have MSG_MASK_SATELLITE inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  This message allows setting a mask to prevent a particular satellite
from being used in various Piksi subsystems.


  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  mask : int
    Mask of systems that should ignore this satellite.
  sid : GnssSignal
    GNSS signal for which the mask is applied
  sender : int
    Optional sender ID, defaults to SENDER_ID (see sbp/msg.py).

  """
  _parser = construct.Struct(
                   'mask' / construct.Int8ul,
                   'sid' / construct.Struct(GnssSignal._parser),)
  __slots__ = [
               'mask',
               'sid',
              ]

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      super( MsgMaskSatellite,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.from_binary(sbp.payload)
    else:
      super( MsgMaskSatellite, self).__init__()
      self.msg_type = SBP_MSG_MASK_SATELLITE
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.mask = kwargs.pop('mask')
      self.sid = kwargs.pop('sid')

  def __repr__(self):
    return fmt_repr(self)

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    return MsgMaskSatellite.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgMaskSatellite(sbp, **d)

 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgMaskSatellite._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgMaskSatellite._parser.build(c)
    return self.pack()

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgMaskSatellite, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    
SBP_MSG_MASK_SATELLITE_DEP = 0x001B
class MsgMaskSatelliteDep(SBP):
  """SBP class for message MSG_MASK_SATELLITE_DEP (0x001B).

  You can have MSG_MASK_SATELLITE_DEP inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  Deprecated.

  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  mask : int
    Mask of systems that should ignore this satellite.
  sid : GnssSignalDep
    GNSS signal for which the mask is applied
  sender : int
    Optional sender ID, defaults to SENDER_ID (see sbp/msg.py).

  """
  _parser = construct.Struct(
                   'mask' / construct.Int8ul,
                   'sid' / construct.Struct(GnssSignalDep._parser),)
  __slots__ = [
               'mask',
               'sid',
              ]

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      super( MsgMaskSatelliteDep,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.from_binary(sbp.payload)
    else:
      super( MsgMaskSatelliteDep, self).__init__()
      self.msg_type = SBP_MSG_MASK_SATELLITE_DEP
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.mask = kwargs.pop('mask')
      self.sid = kwargs.pop('sid')

  def __repr__(self):
    return fmt_repr(self)

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    return MsgMaskSatelliteDep.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgMaskSatelliteDep(sbp, **d)

 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgMaskSatelliteDep._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgMaskSatelliteDep._parser.build(c)
    return self.pack()

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgMaskSatelliteDep, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
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


  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  dev_vin : int
    Device V_in
  cpu_vint : int
    Processor V_int
  cpu_vaux : int
    Processor V_aux
  cpu_temperature : int
    Processor temperature
  fe_temperature : int
    Frontend temperature (if available)
  sender : int
    Optional sender ID, defaults to SENDER_ID (see sbp/msg.py).

  """
  _parser = construct.Struct(
                   'dev_vin' / construct.Int16sl,
                   'cpu_vint' / construct.Int16sl,
                   'cpu_vaux' / construct.Int16sl,
                   'cpu_temperature' / construct.Int16sl,
                   'fe_temperature' / construct.Int16sl,)
  __slots__ = [
               'dev_vin',
               'cpu_vint',
               'cpu_vaux',
               'cpu_temperature',
               'fe_temperature',
              ]

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      super( MsgDeviceMonitor,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.from_binary(sbp.payload)
    else:
      super( MsgDeviceMonitor, self).__init__()
      self.msg_type = SBP_MSG_DEVICE_MONITOR
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.dev_vin = kwargs.pop('dev_vin')
      self.cpu_vint = kwargs.pop('cpu_vint')
      self.cpu_vaux = kwargs.pop('cpu_vaux')
      self.cpu_temperature = kwargs.pop('cpu_temperature')
      self.fe_temperature = kwargs.pop('fe_temperature')

  def __repr__(self):
    return fmt_repr(self)

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    return MsgDeviceMonitor.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgDeviceMonitor(sbp, **d)

 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgDeviceMonitor._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgDeviceMonitor._parser.build(c)
    return self.pack()

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgDeviceMonitor, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
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


  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  sequence : int
    Sequence number
  command : string
    Command line to execute
  sender : int
    Optional sender ID, defaults to SENDER_ID (see sbp/msg.py).

  """
  _parser = construct.Struct(
                   'sequence' / construct.Int32ul,
                   'command' / construct.GreedyBytes,)
  __slots__ = [
               'sequence',
               'command',
              ]

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      super( MsgCommandReq,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.from_binary(sbp.payload)
    else:
      super( MsgCommandReq, self).__init__()
      self.msg_type = SBP_MSG_COMMAND_REQ
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.sequence = kwargs.pop('sequence')
      self.command = kwargs.pop('command')

  def __repr__(self):
    return fmt_repr(self)

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    return MsgCommandReq.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgCommandReq(sbp, **d)

 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgCommandReq._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgCommandReq._parser.build(c)
    return self.pack()

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgCommandReq, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    
SBP_MSG_COMMAND_RESP = 0x00B9
class MsgCommandResp(SBP):
  """SBP class for message MSG_COMMAND_RESP (0x00B9).

  You can have MSG_COMMAND_RESP inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  The response to MSG_COMMAND_REQ with the return code of
the command.  A return code of zero indicates success.


  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  sequence : int
    Sequence number
  code : int
    Exit code
  sender : int
    Optional sender ID, defaults to SENDER_ID (see sbp/msg.py).

  """
  _parser = construct.Struct(
                   'sequence' / construct.Int32ul,
                   'code' / construct.Int32sl,)
  __slots__ = [
               'sequence',
               'code',
              ]

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      super( MsgCommandResp,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.from_binary(sbp.payload)
    else:
      super( MsgCommandResp, self).__init__()
      self.msg_type = SBP_MSG_COMMAND_RESP
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.sequence = kwargs.pop('sequence')
      self.code = kwargs.pop('code')

  def __repr__(self):
    return fmt_repr(self)

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    return MsgCommandResp.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgCommandResp(sbp, **d)

 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgCommandResp._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgCommandResp._parser.build(c)
    return self.pack()

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgCommandResp, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
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


  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  sequence : int
    Sequence number
  line : string
    Line of standard output or standard error
  sender : int
    Optional sender ID, defaults to SENDER_ID (see sbp/msg.py).

  """
  _parser = construct.Struct(
                   'sequence' / construct.Int32ul,
                   'line' / construct.GreedyBytes,)
  __slots__ = [
               'sequence',
               'line',
              ]

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      super( MsgCommandOutput,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.from_binary(sbp.payload)
    else:
      super( MsgCommandOutput, self).__init__()
      self.msg_type = SBP_MSG_COMMAND_OUTPUT
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.sequence = kwargs.pop('sequence')
      self.line = kwargs.pop('line')

  def __repr__(self):
    return fmt_repr(self)

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    return MsgCommandOutput.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgCommandOutput(sbp, **d)

 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgCommandOutput._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgCommandOutput._parser.build(c)
    return self.pack()

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgCommandOutput, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
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

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      super( MsgNetworkStateReq,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.payload = sbp.payload
    else:
      super( MsgNetworkStateReq, self).__init__()
      self.msg_type = SBP_MSG_NETWORK_STATE_REQ
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.payload = ""

  def __repr__(self):
    return fmt_repr(self)

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    return MsgNetworkStateReq.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgNetworkStateReq(sbp, **d)

 
    
SBP_MSG_NETWORK_STATE_RESP = 0x00BB
class MsgNetworkStateResp(SBP):
  """SBP class for message MSG_NETWORK_STATE_RESP (0x00BB).

  You can have MSG_NETWORK_STATE_RESP inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  The state of a network interface on the Piksi.
Data is made to reflect output of ifaddrs struct returned by getifaddrs
in c.


  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  ipv4_address : array
    IPv4 address (all zero when unavailable)
  ipv4_mask_size : int
    IPv4 netmask CIDR notation
  ipv6_address : array
    IPv6 address (all zero when unavailable)
  ipv6_mask_size : int
    IPv6 netmask CIDR notation
  rx_bytes : int
    Number of Rx bytes
  tx_bytes : int
    Number of Tx bytes
  interface_name : string
    Interface Name
  flags : int
    Interface flags from SIOCGIFFLAGS
  sender : int
    Optional sender ID, defaults to SENDER_ID (see sbp/msg.py).

  """
  _parser = construct.Struct(
                   'ipv4_address' / construct.Array(4, construct.Int8ul),
                   'ipv4_mask_size' / construct.Int8ul,
                   'ipv6_address' / construct.Array(16, construct.Int8ul),
                   'ipv6_mask_size' / construct.Int8ul,
                   'rx_bytes' / construct.Int32ul,
                   'tx_bytes' / construct.Int32ul,
                   'interface_name'/ construct.Bytes(16),
                   'flags' / construct.Int32ul,)
  __slots__ = [
               'ipv4_address',
               'ipv4_mask_size',
               'ipv6_address',
               'ipv6_mask_size',
               'rx_bytes',
               'tx_bytes',
               'interface_name',
               'flags',
              ]

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      super( MsgNetworkStateResp,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.from_binary(sbp.payload)
    else:
      super( MsgNetworkStateResp, self).__init__()
      self.msg_type = SBP_MSG_NETWORK_STATE_RESP
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.ipv4_address = kwargs.pop('ipv4_address')
      self.ipv4_mask_size = kwargs.pop('ipv4_mask_size')
      self.ipv6_address = kwargs.pop('ipv6_address')
      self.ipv6_mask_size = kwargs.pop('ipv6_mask_size')
      self.rx_bytes = kwargs.pop('rx_bytes')
      self.tx_bytes = kwargs.pop('tx_bytes')
      self.interface_name = kwargs.pop('interface_name')
      self.flags = kwargs.pop('flags')

  def __repr__(self):
    return fmt_repr(self)

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    return MsgNetworkStateResp.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgNetworkStateResp(sbp, **d)

 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgNetworkStateResp._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgNetworkStateResp._parser.build(c)
    return self.pack()

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgNetworkStateResp, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    
SBP_MSG_NETWORK_BANDWIDTH_USAGE = 0x00BD
class MsgNetworkBandwidthUsage(SBP):
  """SBP class for message MSG_NETWORK_BANDWIDTH_USAGE (0x00BD).

  You can have MSG_NETWORK_BANDWIDTH_USAGE inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  The bandwidth usage, a list of usage by interface. 


  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  interfaces : array
    Usage measurement array
  sender : int
    Optional sender ID, defaults to SENDER_ID (see sbp/msg.py).

  """
  _parser = construct.Struct(
                   construct.GreedyRange('interfaces' / construct.Struct(NetworkUsage._parser)),)
  __slots__ = [
               'interfaces',
              ]

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      super( MsgNetworkBandwidthUsage,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.from_binary(sbp.payload)
    else:
      super( MsgNetworkBandwidthUsage, self).__init__()
      self.msg_type = SBP_MSG_NETWORK_BANDWIDTH_USAGE
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.interfaces = kwargs.pop('interfaces')

  def __repr__(self):
    return fmt_repr(self)

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    return MsgNetworkBandwidthUsage.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgNetworkBandwidthUsage(sbp, **d)

 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgNetworkBandwidthUsage._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgNetworkBandwidthUsage._parser.build(c)
    return self.pack()

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgNetworkBandwidthUsage, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    
SBP_MSG_SPECAN_DEP = 0x0050
class MsgSpecanDep(SBP):
  """SBP class for message MSG_SPECAN_DEP (0x0050).

  You can have MSG_SPECAN_DEP inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  Deprecated.

  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  channel_tag : int
    Channel ID
  t : GPSTimeDep
    Receiver time of this observation
  freq_ref : float
    Reference frequency of this packet

  freq_step : float
    Frequency step of points in this packet

  amplitude_ref : float
    Reference amplitude of this packet

  amplitude_unit : float
    Amplitude unit value of points in this packet

  amplitude_value : array
    Amplitude values (in the above units) of points in this packet

  sender : int
    Optional sender ID, defaults to SENDER_ID (see sbp/msg.py).

  """
  _parser = construct.Struct(
                   'channel_tag' / construct.Int16ul,
                   't' / construct.Struct(GPSTimeDep._parser),
                   'freq_ref' / construct.Float32l,
                   'freq_step' / construct.Float32l,
                   'amplitude_ref' / construct.Float32l,
                   'amplitude_unit' / construct.Float32l,
                   construct.GreedyRange('amplitude_value' / construct.Int8ul),)
  __slots__ = [
               'channel_tag',
               't',
               'freq_ref',
               'freq_step',
               'amplitude_ref',
               'amplitude_unit',
               'amplitude_value',
              ]

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      super( MsgSpecanDep,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.from_binary(sbp.payload)
    else:
      super( MsgSpecanDep, self).__init__()
      self.msg_type = SBP_MSG_SPECAN_DEP
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.channel_tag = kwargs.pop('channel_tag')
      self.t = kwargs.pop('t')
      self.freq_ref = kwargs.pop('freq_ref')
      self.freq_step = kwargs.pop('freq_step')
      self.amplitude_ref = kwargs.pop('amplitude_ref')
      self.amplitude_unit = kwargs.pop('amplitude_unit')
      self.amplitude_value = kwargs.pop('amplitude_value')

  def __repr__(self):
    return fmt_repr(self)

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    return MsgSpecanDep.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgSpecanDep(sbp, **d)

 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgSpecanDep._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgSpecanDep._parser.build(c)
    return self.pack()

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgSpecanDep, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    
SBP_MSG_SPECAN = 0x0051
class MsgSpecan(SBP):
  """SBP class for message MSG_SPECAN (0x0051).

  You can have MSG_SPECAN inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  Spectrum analyzer packet.


  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  channel_tag : int
    Channel ID
  t : GPSTime
    Receiver time of this observation
  freq_ref : float
    Reference frequency of this packet

  freq_step : float
    Frequency step of points in this packet

  amplitude_ref : float
    Reference amplitude of this packet

  amplitude_unit : float
    Amplitude unit value of points in this packet

  amplitude_value : array
    Amplitude values (in the above units) of points in this packet

  sender : int
    Optional sender ID, defaults to SENDER_ID (see sbp/msg.py).

  """
  _parser = construct.Struct(
                   'channel_tag' / construct.Int16ul,
                   't' / construct.Struct(GPSTime._parser),
                   'freq_ref' / construct.Float32l,
                   'freq_step' / construct.Float32l,
                   'amplitude_ref' / construct.Float32l,
                   'amplitude_unit' / construct.Float32l,
                   construct.GreedyRange('amplitude_value' / construct.Int8ul),)
  __slots__ = [
               'channel_tag',
               't',
               'freq_ref',
               'freq_step',
               'amplitude_ref',
               'amplitude_unit',
               'amplitude_value',
              ]

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      super( MsgSpecan,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.from_binary(sbp.payload)
    else:
      super( MsgSpecan, self).__init__()
      self.msg_type = SBP_MSG_SPECAN
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.channel_tag = kwargs.pop('channel_tag')
      self.t = kwargs.pop('t')
      self.freq_ref = kwargs.pop('freq_ref')
      self.freq_step = kwargs.pop('freq_step')
      self.amplitude_ref = kwargs.pop('amplitude_ref')
      self.amplitude_unit = kwargs.pop('amplitude_unit')
      self.amplitude_value = kwargs.pop('amplitude_value')

  def __repr__(self):
    return fmt_repr(self)

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    return MsgSpecan.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgSpecan(sbp, **d)

 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgSpecan._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgSpecan._parser.build(c)
    return self.pack()

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgSpecan, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
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
  0x0050: MsgSpecanDep,
  0x0051: MsgSpecan,
}