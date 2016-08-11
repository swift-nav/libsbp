#!/usr/bin/env python
# Copyright (C) 2015 Swift Navigation Inc.
# Contact: Fergus Noble <fergus@swiftnav.com>
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

from construct import *
import json
from sbp.msg import SBP, SENDER_ID
from sbp.utils import fmt_repr, exclude_fields, walk_json_dict, containerize, greedy_string
from sbp.gnss_signal import *

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
  _parser = Embedded(Struct("UARTChannel",
                     LFloat32('tx_throughput'),
                     LFloat32('rx_throughput'),
                     ULInt16('crc_error_count'),
                     ULInt16('io_error_count'),
                     ULInt8('tx_buffer_level'),
                     ULInt8('rx_buffer_level'),))
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
  _parser = Embedded(Struct("Period",
                     SLInt32('avg'),
                     SLInt32('pmin'),
                     SLInt32('pmax'),
                     SLInt32('current'),))
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
  _parser = Embedded(Struct("Latency",
                     SLInt32('avg'),
                     SLInt32('lmin'),
                     SLInt32('lmax'),
                     SLInt32('current'),))
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

 
    
SBP_MSG_RESET = 0x00B2
class MsgReset(SBP):
  """SBP class for message MSG_RESET (0x00B2).

  You can have MSG_RESET inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  This message from the host resets the Piksi back into the
bootloader.


  """
  __slots__ = []

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      super( MsgReset,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.payload = sbp.payload
    else:
      super( MsgReset, self).__init__()
      self.msg_type = SBP_MSG_RESET
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.payload = ""

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
  _parser = Struct("MsgResetFilters",
                   ULInt8('filter'),)
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
  _parser = Struct("MsgThreadState",
                   String('name', 20),
                   ULInt16('cpu'),
                   ULInt32('stack_free'),)
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
  _parser = Struct("MsgUartState",
                   Struct('uart_a', UARTChannel._parser),
                   Struct('uart_b', UARTChannel._parser),
                   Struct('uart_ftdi', UARTChannel._parser),
                   Struct('latency', Latency._parser),
                   Struct('obs_period', Period._parser),)
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
  _parser = Struct("MsgUartStateDepa",
                   Struct('uart_a', UARTChannel._parser),
                   Struct('uart_b', UARTChannel._parser),
                   Struct('uart_ftdi', UARTChannel._parser),
                   Struct('latency', Latency._parser),)
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
  _parser = Struct("MsgIarState",
                   ULInt32('num_hyps'),)
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
    
SBP_MSG_MASK_SATELLITE = 0x001B
class MsgMaskSatellite(SBP):
  """SBP class for message MSG_MASK_SATELLITE (0x001B).

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
  _parser = Struct("MsgMaskSatellite",
                   ULInt8('mask'),
                   Struct('sid', GnssSignal._parser),)
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
  _parser = Struct("MsgDeviceMonitor",
                   SLInt16('dev_vin'),
                   SLInt16('cpu_vint'),
                   SLInt16('cpu_vaux'),
                   SLInt16('cpu_temperature'),
                   SLInt16('fe_temperature'),)
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
    

msg_classes = {
  0x0069: MsgAlmanac,
  0x0068: MsgSetTime,
  0x00B2: MsgReset,
  0x00C0: MsgCwResults,
  0x00C1: MsgCwStart,
  0x0022: MsgResetFilters,
  0x0023: MsgInitBase,
  0x0017: MsgThreadState,
  0x001D: MsgUartState,
  0x0018: MsgUartStateDepa,
  0x0019: MsgIarState,
  0x001B: MsgMaskSatellite,
  0x00B5: MsgDeviceMonitor,
}