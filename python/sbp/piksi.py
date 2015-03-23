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

# Automatically generated from piksi/yaml/swiftnav/sbp/piksi.yaml
# with generate.py at 2015-03-24 09:47:48.702701. Please do not hand edit!


class UARTChannel(object):
  """UARTChannel.
  
  State of the UART channel.
  
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
    UART transmit usage percentage.
  rx_buffer_level : int
    UART receive usage percentage.

  """
  _parser = Struct("UARTChannel",
                   LFloat32('tx_throughput'),
                   LFloat32('rx_throughput'),
                   ULInt16('crc_error_count'),
                   ULInt16('io_error_count'),
                   ULInt8('tx_buffer_level'),
                   ULInt8('rx_buffer_level'),)

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
  _parser = Struct("Latency",
                   SLInt32('avg'),
                   SLInt32('lmin'),
                   SLInt32('lmax'),
                   SLInt32('current'),)

  def __init__(self, payload):
    self.from_binary(payload)

  def __repr__(self):
    return fmt_repr(self)
  
  def from_binary(self, d):
    p = Latency._parser.parse(d)
    self.__dict__.update(dict(p.viewitems()))

  def to_binary(self):
    return Latency.build(self.__dict__)
    
SBP_MSG_PRINT = 0x0010
class MsgPrint(SBP):
  """SBP class for message MSG_PRINT (0x0010).
  
  Information and debugging information.

  """

  def __init__(self, sbp):
    self.__dict__.update(sbp.__dict__)
    self.payload = sbp.payload

  def __repr__(self):
    return fmt_repr(self)
 
    
SBP_MSG_DEBUG_VAR = 0x0011
class MsgDebugVar(SBP):
  """SBP class for message MSG_DEBUG_VAR (0x0011).
  
  Legacy message for tracing variable values.

  """

  def __init__(self, sbp):
    self.__dict__.update(sbp.__dict__)
    self.payload = sbp.payload

  def __repr__(self):
    return fmt_repr(self)
 
    
SBP_MSG_ALMANAC = 0x0069
class MsgAlmanac(SBP):
  """SBP class for message MSG_ALMANAC (0x0069).
  
  MSG_ALMANAC

  """

  def __init__(self, sbp):
    self.__dict__.update(sbp.__dict__)
    self.payload = sbp.payload

  def __repr__(self):
    return fmt_repr(self)
 
    
SBP_MSG_SET_TIME = 0x0068
class MsgSetTime(SBP):
  """SBP class for message MSG_SET_TIME (0x0068).
  
  MSG_SET_TIME

  """

  def __init__(self, sbp):
    self.__dict__.update(sbp.__dict__)
    self.payload = sbp.payload

  def __repr__(self):
    return fmt_repr(self)
 
    
SBP_MSG_BOOTLOADER_HANDSHAKE = 0x00B0
class MsgBootloaderHandshake(SBP):
  """SBP class for message MSG_BOOTLOADER_HANDSHAKE (0x00B0).
  
  MSG_BOOTLOADER_HANDSHAKE

  """

  def __init__(self, sbp):
    self.__dict__.update(sbp.__dict__)
    self.payload = sbp.payload

  def __repr__(self):
    return fmt_repr(self)
 
    
SBP_MSG_BOOTLOADER_JUMP_TO_APP = 0x00B1
class MsgBootloaderJumpToApp(SBP):
  """SBP class for message MSG_BOOTLOADER_JUMP_TO_APP (0x00B1).
  
  MSG_BOOTLOADER_JUMP_TO_APP

  """

  def __init__(self, sbp):
    self.__dict__.update(sbp.__dict__)
    self.payload = sbp.payload

  def __repr__(self):
    return fmt_repr(self)
 
    
SBP_MSG_RESET = 0x00B2
class MsgReset(SBP):
  """SBP class for message MSG_RESET (0x00B2).
  
  Reset the devices.

  """

  def __init__(self, sbp):
    self.__dict__.update(sbp.__dict__)
    self.payload = sbp.payload

  def __repr__(self):
    return fmt_repr(self)
 
    
SBP_MSG_CW_RESULTS = 0x00C0
class MsgCwResults(SBP):
  """SBP class for message MSG_CW_RESULTS (0x00C0).
  
  MSG_CW_RESULTS

  """

  def __init__(self, sbp):
    self.__dict__.update(sbp.__dict__)
    self.payload = sbp.payload

  def __repr__(self):
    return fmt_repr(self)
 
    
SBP_MSG_CW_START = 0x00C1
class MsgCwStart(SBP):
  """SBP class for message MSG_CW_START (0x00C1).
  
  MSG_CW_START

  """

  def __init__(self, sbp):
    self.__dict__.update(sbp.__dict__)
    self.payload = sbp.payload

  def __repr__(self):
    return fmt_repr(self)
 
    
SBP_MSG_NAP_DEVICE_DNA = 0x00DD
class MsgNapDeviceDna(SBP):
  """SBP class for message MSG_NAP_DEVICE_DNA (0x00DD).
  
  MSG_NAP_DEVICE_DNA

  """

  def __init__(self, sbp):
    self.__dict__.update(sbp.__dict__)
    self.payload = sbp.payload

  def __repr__(self):
    return fmt_repr(self)
 
    
SBP_MSG_FLASH_PROGRAM = 0x00E0
class MsgFlashProgram(SBP):
  """SBP class for message MSG_FLASH_PROGRAM (0x00E0).
  
  MSG_FLASH_PROGRAM

  """

  def __init__(self, sbp):
    self.__dict__.update(sbp.__dict__)
    self.payload = sbp.payload

  def __repr__(self):
    return fmt_repr(self)
 
    
SBP_MSG_FLASH_DONE = 0x00E0
class MsgFlashDone(SBP):
  """SBP class for message MSG_FLASH_DONE (0x00E0).
  
  MSG_FLASH_DONE

  """

  def __init__(self, sbp):
    self.__dict__.update(sbp.__dict__)
    self.payload = sbp.payload

  def __repr__(self):
    return fmt_repr(self)
 
    
SBP_MSG_FLASH_READ = 0x00E1
class MsgFlashRead(SBP):
  """SBP class for message MSG_FLASH_READ (0x00E1).
  
  MSG_FLASH_READ

  """

  def __init__(self, sbp):
    self.__dict__.update(sbp.__dict__)
    self.payload = sbp.payload

  def __repr__(self):
    return fmt_repr(self)
 
    
SBP_MSG_FLASH_ERASE = 0x00E2
class MsgFlashErase(SBP):
  """SBP class for message MSG_FLASH_ERASE (0x00E2).
  
  MSG_FLASH_ERASE

  """

  def __init__(self, sbp):
    self.__dict__.update(sbp.__dict__)
    self.payload = sbp.payload

  def __repr__(self):
    return fmt_repr(self)
 
    
SBP_MSG_STM_FLASH_LOCK_SECTOR = 0x00E3
class MsgStmFlashLockSector(SBP):
  """SBP class for message MSG_STM_FLASH_LOCK_SECTOR (0x00E3).
  
  MSG_STM_FLASH_LOCK_SECTOR

  """

  def __init__(self, sbp):
    self.__dict__.update(sbp.__dict__)
    self.payload = sbp.payload

  def __repr__(self):
    return fmt_repr(self)
 
    
SBP_MSG_STM_FLASH_UNLOCK_SECTOR = 0x00E4
class MsgStmFlashUnlockSector(SBP):
  """SBP class for message MSG_STM_FLASH_UNLOCK_SECTOR (0x00E4).
  
  MSG_STM_FLASH_UNLOCK_SECTOR

  """

  def __init__(self, sbp):
    self.__dict__.update(sbp.__dict__)
    self.payload = sbp.payload

  def __repr__(self):
    return fmt_repr(self)
 
    
SBP_MSG_STM_UNIQUE_ID = 0x00E5
class MsgStmUniqueId(SBP):
  """SBP class for message MSG_STM_UNIQUE_ID (0x00E5).
  
  MSG_STM_UNIQUE_ID

  """

  def __init__(self, sbp):
    self.__dict__.update(sbp.__dict__)
    self.payload = sbp.payload

  def __repr__(self):
    return fmt_repr(self)
 
    
SBP_MSG_M25_FLASH_WRITE_STATUS = 0x00F3
class MsgM25FlashWriteStatus(SBP):
  """SBP class for message MSG_M25_FLASH_WRITE_STATUS (0x00F3).
  
  MSG_M25_FLASH_WRITE_STATUS

  """

  def __init__(self, sbp):
    self.__dict__.update(sbp.__dict__)
    self.payload = sbp.payload

  def __repr__(self):
    return fmt_repr(self)
 
    
SBP_MSG_RESET_FILTERS = 0x0022
class MsgResetFilters(SBP):
  """SBP class for message MSG_RESET_FILTERS (0x0022).
  
  MSG_RESET_FILTERS

  """

  def __init__(self, sbp):
    self.__dict__.update(sbp.__dict__)
    self.payload = sbp.payload

  def __repr__(self):
    return fmt_repr(self)
 
    
SBP_MSG_INIT_BASE = 0x0023
class MsgInitBase(SBP):
  """SBP class for message MSG_INIT_BASE (0x0023).
  
  MSG_INIT_BASE

  """

  def __init__(self, sbp):
    self.__dict__.update(sbp.__dict__)
    self.payload = sbp.payload

  def __repr__(self):
    return fmt_repr(self)
 
    
SBP_MSG_SETTINGS = 0x00A0
class MsgSettings(SBP):
  """SBP class for message MSG_SETTINGS (0x00A0).
  
  MSG_SETTINGS

  """

  def __init__(self, sbp):
    self.__dict__.update(sbp.__dict__)
    self.payload = sbp.payload

  def __repr__(self):
    return fmt_repr(self)
 
    
SBP_MSG_SETTINGS_SAVE = 0x00A1
class MsgSettingsSave(SBP):
  """SBP class for message MSG_SETTINGS_SAVE (0x00A1).
  
  MSG_SETTINGS_SAVE

  """

  def __init__(self, sbp):
    self.__dict__.update(sbp.__dict__)
    self.payload = sbp.payload

  def __repr__(self):
    return fmt_repr(self)
 
    
SBP_MSG_SETTINGS_READ_BY_INDEX = 0x00A2
class MsgSettingsReadByIndex(SBP):
  """SBP class for message MSG_SETTINGS_READ_BY_INDEX (0x00A2).
  
  MSG_SETTINGS_READ_BY_INDEX

  """

  def __init__(self, sbp):
    self.__dict__.update(sbp.__dict__)
    self.payload = sbp.payload

  def __repr__(self):
    return fmt_repr(self)
 
    
SBP_MSG_FILEIO_READ = 0x00A8
class MsgFileioRead(SBP):
  """SBP class for message MSG_FILEIO_READ (0x00A8).
  
  MSG_FILEIO_READ

  """

  def __init__(self, sbp):
    self.__dict__.update(sbp.__dict__)
    self.payload = sbp.payload

  def __repr__(self):
    return fmt_repr(self)
 
    
SBP_MSG_FILEIO_READ_DIR = 0x00A9
class MsgFileioReadDir(SBP):
  """SBP class for message MSG_FILEIO_READ_DIR (0x00A9).
  
  MSG_FILEIO_READ_DIR

  """

  def __init__(self, sbp):
    self.__dict__.update(sbp.__dict__)
    self.payload = sbp.payload

  def __repr__(self):
    return fmt_repr(self)
 
    
SBP_MSG_FILEIO_REMOVE = 0x00AC
class MsgFileioRemove(SBP):
  """SBP class for message MSG_FILEIO_REMOVE (0x00AC).
  
  MSG_FILEIO_REMOVE

  """

  def __init__(self, sbp):
    self.__dict__.update(sbp.__dict__)
    self.payload = sbp.payload

  def __repr__(self):
    return fmt_repr(self)
 
    
SBP_MSG_FILEIO_WRITE = 0x00AD
class MsgFileioWrite(SBP):
  """SBP class for message MSG_FILEIO_WRITE (0x00AD).
  
  MSG_FILEIO_WRITE

  """

  def __init__(self, sbp):
    self.__dict__.update(sbp.__dict__)
    self.payload = sbp.payload

  def __repr__(self):
    return fmt_repr(self)
 
    
SBP_MSG_THREAD_STATE = 0x0017
class MsgThreadState(SBP):
  """SBP class for message MSG_THREAD_STATE (0x0017).
  
  State of the CPU threads.

  Parameters
  ----------
  name : string
    Thread name
  cpu : int
    cpu
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
  
  State of the UART channels.

  Parameters
  ----------
  uart_a : UARTChannel
    State of UART A.
  uart_b : UARTChannel
    State of UART B.
  uart_ftdi : UARTChannel
    State of UART FTDI.
  latency : Latency
    UART communication latency.

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
  
  State of the Integer Ambiguity Resolution (IAR) process.

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
  0x0010: MsgPrint,
  0x0011: MsgDebugVar,
  0x0069: MsgAlmanac,
  0x0068: MsgSetTime,
  0x00B0: MsgBootloaderHandshake,
  0x00B1: MsgBootloaderJumpToApp,
  0x00B2: MsgReset,
  0x00C0: MsgCwResults,
  0x00C1: MsgCwStart,
  0x00DD: MsgNapDeviceDna,
  0x00E0: MsgFlashProgram,
  0x00E0: MsgFlashDone,
  0x00E1: MsgFlashRead,
  0x00E2: MsgFlashErase,
  0x00E3: MsgStmFlashLockSector,
  0x00E4: MsgStmFlashUnlockSector,
  0x00E5: MsgStmUniqueId,
  0x00F3: MsgM25FlashWriteStatus,
  0x0022: MsgResetFilters,
  0x0023: MsgInitBase,
  0x00A0: MsgSettings,
  0x00A1: MsgSettingsSave,
  0x00A2: MsgSettingsReadByIndex,
  0x00A8: MsgFileioRead,
  0x00A9: MsgFileioReadDir,
  0x00AC: MsgFileioRemove,
  0x00AD: MsgFileioWrite,
  0x0017: MsgThreadState,
  0x0018: MsgUartState,
  0x0019: MsgIarState,
}

def sbp_decode(t, d):
  return msg_classes[t](d)