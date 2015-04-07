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

from construct import *
from sbp import SBP
from sbp.utils import fmt_repr
import six

# Automatically generated from piksi/yaml/swiftnav/sbp/piksi.yaml
# with generate.py at 2015-04-06 23:40:11.127759. Please do not hand edit!


class UARTChannel(object):
  """UARTChannel.
  
  Throughput, utilization, and error counts on the RX/TX buffers
of this UART channel. Values require renormalization.

  
  Parameters
  ----------
  tx_throughput : float
    UART transmit throughput.
  rx_throughput : float
    UART receive throughput.
  crc_error_count : int
    UART CRC error count.
  io_error_count : int
    UART IO error count.
  tx_buffer_level : int
    UART transmit buffer percentage utilization. Ranges from
0 - 255 and needs to be renormalized to 100.

  rx_buffer_level : int
    UART receive buffer percentage utilization. Ranges from
0 - 255 and needs to be renormalized to 100.


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
    Average latency.
  lmin : int
    Minimum latency.
  lmax : int
    Maximum latency.
  current : int
    Smoothed estimate of the current latency.

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
  
  This is a legacy message for sending and loading a satellite
alamanac onto the Piksi's flash memory from the host.


  """

  def __init__(self, sbp):
    self.__dict__.update(sbp.__dict__)
    self.payload = sbp.payload

  def __repr__(self):
    return fmt_repr(self)
 
    
SBP_MSG_SET_TIME = 0x0068
class MsgSetTime(SBP):
  """SBP class for message MSG_SET_TIME (0x0068).
  
  This message sets up timing functionality using a coarse GPS
time estimate sent by the host.


  """

  def __init__(self, sbp):
    self.__dict__.update(sbp.__dict__)
    self.payload = sbp.payload

  def __repr__(self):
    return fmt_repr(self)
 
    
SBP_MSG_RESET = 0x00B2
class MsgReset(SBP):
  """SBP class for message MSG_RESET (0x00B2).
  
  This message from the host resets the Piksi back into the
bootloader. It ensures that all outstanding memory accesses
including buffered writes are completed before reset begins.


  """

  def __init__(self, sbp):
    self.__dict__.update(sbp.__dict__)
    self.payload = sbp.payload

  def __repr__(self):
    return fmt_repr(self)
 
    
SBP_MSG_CW_RESULTS = 0x00C0
class MsgCwResults(SBP):
  """SBP class for message MSG_CW_RESULTS (0x00C0).
  
  This is an unused legacy message for result reporting from the
CW interference channel on the SwiftNAP. This message will be
removed in a future release.


  """

  def __init__(self, sbp):
    self.__dict__.update(sbp.__dict__)
    self.payload = sbp.payload

  def __repr__(self):
    return fmt_repr(self)
 
    
SBP_MSG_CW_START = 0x00C1
class MsgCwStart(SBP):
  """SBP class for message MSG_CW_START (0x00C1).
  
  This is an unused legacy message from those host for starting
the CW interference channel on the SwiftNAP. This message will
be removed in a future release.


  """

  def __init__(self, sbp):
    self.__dict__.update(sbp.__dict__)
    self.payload = sbp.payload

  def __repr__(self):
    return fmt_repr(self)
 
    
SBP_MSG_RESET_FILTERS = 0x0022
class MsgResetFilters(SBP):
  """SBP class for message MSG_RESET_FILTERS (0x0022).
  
  This message resets either the DGNSS Kalman filters or Integer
Ambiguity Resolution (IAR) process.


  Parameters
  ----------
  filter : int
    Filter flags

  """
  _parser = Struct("MsgResetFilters",
                   ULInt8('filter'),)

  def __init__(self, sbp):
    self.__dict__.update(sbp.__dict__)
    self.from_binary(sbp.payload)

  def __repr__(self):
    return fmt_repr(self)
 
  def from_binary(self, d):
    p = MsgResetFilters._parser.parse(d)
    self.__dict__.update(dict(p.viewitems()))

  def to_binary(self):
    return MsgResetFilters.build(self.__dict__)
    
SBP_MSG_INIT_BASE = 0x0023
class MsgInitBase(SBP):
  """SBP class for message MSG_INIT_BASE (0x0023).
  
  This message initializes the Integer Ambiguity Resolution (IAR)
process on the Piksi to use an assumed baseline position between
the base station and rover receivers. Warns via MsgPrint if
there aren't a shared minimum number (4) of satellite
observations between the two.


  """

  def __init__(self, sbp):
    self.__dict__.update(sbp.__dict__)
    self.payload = sbp.payload

  def __repr__(self):
    return fmt_repr(self)
 
    
SBP_MSG_THREAD_STATE = 0x0017
class MsgThreadState(SBP):
  """SBP class for message MSG_THREAD_STATE (0x0017).
  
  The thread usage message from the Piksi reports RTOS thread
usage statistics for the named thread. The reported values
require renormalization.


  Parameters
  ----------
  name : string
    Thread name (NULL terminated)
  cpu : int
    Percentage cpu use for this thread. Ranges from 0 - 1000
and needs to be renormalized to 100.

  stack_free : int
    Free stack space for this thread.

  """
  _parser = Struct("MsgThreadState",
                   String('name', 20),
                   ULInt16('cpu'),
                   ULInt32('stack_free'),)

  def __init__(self, sbp):
    self.__dict__.update(sbp.__dict__)
    self.from_binary(sbp.payload)

  def __repr__(self):
    return fmt_repr(self)
 
  def from_binary(self, d):
    p = MsgThreadState._parser.parse(d)
    self.__dict__.update(dict(p.viewitems()))

  def to_binary(self):
    return MsgThreadState.build(self.__dict__)
    
SBP_MSG_UART_STATE = 0x0018
class MsgUartState(SBP):
  """SBP class for message MSG_UART_STATE (0x0018).
  
  The UART message reports data latency and throughput of the UART
channels providing SBP I/O. On the default Piksi configuration,
UARTs A and B are used for telemetry radios, but can also be be
host access ports for embedded hosts, or other interfaces in
future.


  Parameters
  ----------
  uart_a : UARTChannel
    State of UART A
  uart_b : UARTChannel
    State of UART B
  uart_ftdi : UARTChannel
    State of UART FTDI (USB logger)
  latency : Latency
    UART communication latency

  """
  _parser = Struct("MsgUartState",
                   Struct('uart_a', UARTChannel._parser),
                   Struct('uart_b', UARTChannel._parser),
                   Struct('uart_ftdi', UARTChannel._parser),
                   Struct('latency', Latency._parser),)

  def __init__(self, sbp):
    self.__dict__.update(sbp.__dict__)
    self.from_binary(sbp.payload)

  def __repr__(self):
    return fmt_repr(self)
 
  def from_binary(self, d):
    p = MsgUartState._parser.parse(d)
    self.__dict__.update(dict(p.viewitems()))

  def to_binary(self):
    return MsgUartState.build(self.__dict__)
    
SBP_MSG_IAR_STATE = 0x0019
class MsgIarState(SBP):
  """SBP class for message MSG_IAR_STATE (0x0019).
  
  This message reports the state of the Integer Ambiguity
Resolution (IAR) process, which resolves unknown integer
ambiguities from double-differenced carrier-phase measurements
from satellite observations.


  Parameters
  ----------
  num_hyps : int
    Number of integer ambiguity hypotheses remaining.

  """
  _parser = Struct("MsgIarState",
                   ULInt32('num_hyps'),)

  def __init__(self, sbp):
    self.__dict__.update(sbp.__dict__)
    self.from_binary(sbp.payload)

  def __repr__(self):
    return fmt_repr(self)
 
  def from_binary(self, d):
    p = MsgIarState._parser.parse(d)
    self.__dict__.update(dict(p.viewitems()))

  def to_binary(self):
    return MsgIarState.build(self.__dict__)
    

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