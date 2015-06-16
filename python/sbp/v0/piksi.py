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

These messages are in the implementation-defined range
(0x0000-0x00FF), and largely intended for internal-use only.

"""

from construct import *
import json
from sbp.msg import SBP
from sbp.utils import fmt_repr, exclude_fields, walk_json_dict, containerize
import six

# Automatically generated from piksi/yaml/swiftnav/sbp/piksi.yaml with generate.py.
# Please do not hand edit!


class UARTChannel(object):
  """UARTChannel.
  
  Throughput, utilization, and error counts on the RX/TX buffers
of this UART channel. The reported percentage values require to
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
0 - 255)

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

  def __init__(self, payload):
    self.from_binary(payload)

  def __repr__(self):
    return fmt_repr(self)
  
  def from_binary(self, d):
    p = UARTChannel._parser.parse(d)
    self.__dict__.update(dict(p.viewitems()))

  def to_binary(self):
    return UARTChannel.build(self.__dict__)
    
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

  def __init__(self, payload):
    self.from_binary(payload)

  def __repr__(self):
    return fmt_repr(self)
  
  def from_binary(self, d):
    p = Latency._parser.parse(d)
    self.__dict__.update(dict(p.viewitems()))

  def to_binary(self):
    return Latency.build(self.__dict__)
    
SBP_MSG_ALMANAC = 0x0069
class MsgAlmanac(SBP):
  """SBP class for message MSG_ALMANAC (0x0069).

  You can have MSG_ALMANAC inherent its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  This is a legacy message for sending and loading a satellite
alamanac onto the Piksi's flash memory from the host.


  """

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      self.__dict__.update(sbp.__dict__)
      self.payload = sbp.payload
    else:
      super( MsgAlmanac, self).__init__()
      self.msg_type = SBP_MSG_ALMANAC
      self.sender = kwargs.pop('sender', 0)

  def __repr__(self):
    return fmt_repr(self)
 
    
SBP_MSG_SET_TIME = 0x0068
class MsgSetTime(SBP):
  """SBP class for message MSG_SET_TIME (0x0068).

  You can have MSG_SET_TIME inherent its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  This message sets up timing functionality using a coarse GPS
time estimate sent by the host.


  """

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      self.__dict__.update(sbp.__dict__)
      self.payload = sbp.payload
    else:
      super( MsgSetTime, self).__init__()
      self.msg_type = SBP_MSG_SET_TIME
      self.sender = kwargs.pop('sender', 0)

  def __repr__(self):
    return fmt_repr(self)
 
    
SBP_MSG_RESET = 0x00B2
class MsgReset(SBP):
  """SBP class for message MSG_RESET (0x00B2).

  You can have MSG_RESET inherent its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  This message from the host resets the Piksi back into the
bootloader.


  """

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      self.__dict__.update(sbp.__dict__)
      self.payload = sbp.payload
    else:
      super( MsgReset, self).__init__()
      self.msg_type = SBP_MSG_RESET
      self.sender = kwargs.pop('sender', 0)

  def __repr__(self):
    return fmt_repr(self)
 
    
SBP_MSG_CW_RESULTS = 0x00C0
class MsgCwResults(SBP):
  """SBP class for message MSG_CW_RESULTS (0x00C0).

  You can have MSG_CW_RESULTS inherent its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  This is an unused legacy message for result reporting from the
CW interference channel on the SwiftNAP. This message will be
removed in a future release.


  """

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      self.__dict__.update(sbp.__dict__)
      self.payload = sbp.payload
    else:
      super( MsgCwResults, self).__init__()
      self.msg_type = SBP_MSG_CW_RESULTS
      self.sender = kwargs.pop('sender', 0)

  def __repr__(self):
    return fmt_repr(self)
 
    
SBP_MSG_CW_START = 0x00C1
class MsgCwStart(SBP):
  """SBP class for message MSG_CW_START (0x00C1).

  You can have MSG_CW_START inherent its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  This is an unused legacy message from those host for starting
the CW interference channel on the SwiftNAP. This message will
be removed in a future release.


  """

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      self.__dict__.update(sbp.__dict__)
      self.payload = sbp.payload
    else:
      super( MsgCwStart, self).__init__()
      self.msg_type = SBP_MSG_CW_START
      self.sender = kwargs.pop('sender', 0)

  def __repr__(self):
    return fmt_repr(self)
 
    
SBP_MSG_RESET_FILTERS = 0x0022
class MsgResetFilters(SBP):
  """SBP class for message MSG_RESET_FILTERS (0x0022).

  You can have MSG_RESET_FILTERS inherent its fields directly
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
    Optional sender ID, defaults to 0

  """
  _parser = Struct("MsgResetFilters",
                   ULInt8('filter'),)

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      self.__dict__.update(sbp.__dict__)
      self.from_binary(sbp.payload)
    else:
      super( MsgResetFilters, self).__init__()
      self.msg_type = SBP_MSG_RESET_FILTERS
      self.sender = kwargs.pop('sender', 0)
      self.filter = kwargs.pop('filter')

  def __repr__(self):
    return fmt_repr(self)
 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgResetFilters._parser.parse(d)
    self.__dict__.update(dict(p.viewitems()))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgResetFilters._parser.build(c)
    return self.pack()

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    sbp = SBP.from_json_dict(d)
    return MsgResetFilters(sbp)

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgResetFilters, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    
SBP_MSG_INIT_BASE = 0x0023
class MsgInitBase(SBP):
  """SBP class for message MSG_INIT_BASE (0x0023).

  You can have MSG_INIT_BASE inherent its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  This message initializes the integer ambiguity resolution (IAR)
process on the Piksi to use an assumed baseline position between
the base station and rover receivers. Warns via MSG_PRINT if
there aren't a shared minimum number (4) of satellite
observations between the two.


  """

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      self.__dict__.update(sbp.__dict__)
      self.payload = sbp.payload
    else:
      super( MsgInitBase, self).__init__()
      self.msg_type = SBP_MSG_INIT_BASE
      self.sender = kwargs.pop('sender', 0)

  def __repr__(self):
    return fmt_repr(self)
 
    
SBP_MSG_THREAD_STATE = 0x0017
class MsgThreadState(SBP):
  """SBP class for message MSG_THREAD_STATE (0x0017).

  You can have MSG_THREAD_STATE inherent its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  The thread usage message from the device reports real-time
operating system (RTOS) thread usage statistics for the named
thread. The reported percentage values require to be normalized.


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
    Optional sender ID, defaults to 0

  """
  _parser = Struct("MsgThreadState",
                   String('name', 20),
                   ULInt16('cpu'),
                   ULInt32('stack_free'),)

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      self.__dict__.update(sbp.__dict__)
      self.from_binary(sbp.payload)
    else:
      super( MsgThreadState, self).__init__()
      self.msg_type = SBP_MSG_THREAD_STATE
      self.sender = kwargs.pop('sender', 0)
      self.name = kwargs.pop('name')
      self.cpu = kwargs.pop('cpu')
      self.stack_free = kwargs.pop('stack_free')

  def __repr__(self):
    return fmt_repr(self)
 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgThreadState._parser.parse(d)
    self.__dict__.update(dict(p.viewitems()))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgThreadState._parser.build(c)
    return self.pack()

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    sbp = SBP.from_json_dict(d)
    return MsgThreadState(sbp)

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgThreadState, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    
SBP_MSG_UART_STATE = 0x0018
class MsgUartState(SBP):
  """SBP class for message MSG_UART_STATE (0x0018).

  You can have MSG_UART_STATE inherent its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  The UART message reports data latency and throughput of the UART
channels providing SBP I/O. On the default Piksi configuration,
UARTs A and B are used for telemetry radios, but can also be be
host access ports for embedded hosts, or other interfaces in
future. The reported percentage values require to be normalized.


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
    Optional sender ID, defaults to 0

  """
  _parser = Struct("MsgUartState",
                   Struct('uart_a', UARTChannel._parser),
                   Struct('uart_b', UARTChannel._parser),
                   Struct('uart_ftdi', UARTChannel._parser),
                   Struct('latency', Latency._parser),)

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      self.__dict__.update(sbp.__dict__)
      self.from_binary(sbp.payload)
    else:
      super( MsgUartState, self).__init__()
      self.msg_type = SBP_MSG_UART_STATE
      self.sender = kwargs.pop('sender', 0)
      self.uart_a = kwargs.pop('uart_a')
      self.uart_b = kwargs.pop('uart_b')
      self.uart_ftdi = kwargs.pop('uart_ftdi')
      self.latency = kwargs.pop('latency')

  def __repr__(self):
    return fmt_repr(self)
 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgUartState._parser.parse(d)
    self.__dict__.update(dict(p.viewitems()))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgUartState._parser.build(c)
    return self.pack()

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    sbp = SBP.from_json_dict(d)
    return MsgUartState(sbp)

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgUartState, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    
SBP_MSG_IAR_STATE = 0x0019
class MsgIarState(SBP):
  """SBP class for message MSG_IAR_STATE (0x0019).

  You can have MSG_IAR_STATE inherent its fields directly
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
    Optional sender ID, defaults to 0

  """
  _parser = Struct("MsgIarState",
                   ULInt32('num_hyps'),)

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      self.__dict__.update(sbp.__dict__)
      self.from_binary(sbp.payload)
    else:
      super( MsgIarState, self).__init__()
      self.msg_type = SBP_MSG_IAR_STATE
      self.sender = kwargs.pop('sender', 0)
      self.num_hyps = kwargs.pop('num_hyps')

  def __repr__(self):
    return fmt_repr(self)
 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgIarState._parser.parse(d)
    self.__dict__.update(dict(p.viewitems()))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgIarState._parser.build(c)
    return self.pack()

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    sbp = SBP.from_json_dict(d)
    return MsgIarState(sbp)

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgIarState, self).to_json_dict()
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
  0x0018: MsgUartState,
  0x0019: MsgIarState,
}