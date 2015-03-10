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

import struct
from swift.sbp import SBP
from swift.sbp.utils import to_repr

# Automatically generated from sbp.yaml with generate.py, do not hand edit!



SBP_MSG_PRINT = 0x0010
class MsgPrint(SBP):
  """
  SBP class for message MSG_PRINT (0x0010)
  """

  def __init__(self, sbp):
    self.__dict__.update(sbp.__dict__)
    self.payload = sbp.payload

  def __repr__(self):
    return to_repr(self)


SBP_MSG_DEBUG_VAR = 0x0011
class MsgDebugVar(SBP):
  """
  SBP class for message MSG_DEBUG_VAR (0x0011)
  """

  def __init__(self, sbp):
    self.__dict__.update(sbp.__dict__)
    self.payload = sbp.payload

  def __repr__(self):
    return to_repr(self)


SBP_MSG_ALMANAC = 0x0069
class MsgAlmanac(SBP):
  """
  SBP class for message MSG_ALMANAC (0x0069)
  """

  def __init__(self, sbp):
    self.__dict__.update(sbp.__dict__)
    self.payload = sbp.payload

  def __repr__(self):
    return to_repr(self)


SBP_MSG_SET_TIME = 0x0068
class MsgSetTime(SBP):
  """
  SBP class for message MSG_SET_TIME (0x0068)
  """

  def __init__(self, sbp):
    self.__dict__.update(sbp.__dict__)
    self.payload = sbp.payload

  def __repr__(self):
    return to_repr(self)


SBP_MSG_BOOTLOADER_HANDSHAKE = 0x00B0
class MsgBootloaderHandshake(SBP):
  """
  SBP class for message MSG_BOOTLOADER_HANDSHAKE (0x00B0)
  """

  def __init__(self, sbp):
    self.__dict__.update(sbp.__dict__)
    self.payload = sbp.payload

  def __repr__(self):
    return to_repr(self)


SBP_MSG_BOOTLOADER_JUMP_TO_APP = 0x00B1
class MsgBootloaderJumpToApp(SBP):
  """
  SBP class for message MSG_BOOTLOADER_JUMP_TO_APP (0x00B1)
  """

  def __init__(self, sbp):
    self.__dict__.update(sbp.__dict__)
    self.payload = sbp.payload

  def __repr__(self):
    return to_repr(self)


SBP_MSG_RESET = 0x00B2
class MsgReset(SBP):
  """
  SBP class for message MSG_RESET (0x00B2)
  """

  def __init__(self, sbp):
    self.__dict__.update(sbp.__dict__)
    self.payload = sbp.payload

  def __repr__(self):
    return to_repr(self)


SBP_MSG_CW_RESULTS = 0x00C0
class MsgCwResults(SBP):
  """
  SBP class for message MSG_CW_RESULTS (0x00C0)
  """

  def __init__(self, sbp):
    self.__dict__.update(sbp.__dict__)
    self.payload = sbp.payload

  def __repr__(self):
    return to_repr(self)


SBP_MSG_CW_START = 0x00C1
class MsgCwStart(SBP):
  """
  SBP class for message MSG_CW_START (0x00C1)
  """

  def __init__(self, sbp):
    self.__dict__.update(sbp.__dict__)
    self.payload = sbp.payload

  def __repr__(self):
    return to_repr(self)


SBP_MSG_NAP_DEVICE_DNA = 0x00DD
class MsgNapDeviceDna(SBP):
  """
  SBP class for message MSG_NAP_DEVICE_DNA (0x00DD)
  """

  def __init__(self, sbp):
    self.__dict__.update(sbp.__dict__)
    self.payload = sbp.payload

  def __repr__(self):
    return to_repr(self)


SBP_MSG_FLASH_PROGRAM = 0x00E0
class MsgFlashProgram(SBP):
  """
  SBP class for message MSG_FLASH_PROGRAM (0x00E0)
  """

  def __init__(self, sbp):
    self.__dict__.update(sbp.__dict__)
    self.payload = sbp.payload

  def __repr__(self):
    return to_repr(self)


SBP_MSG_FLASH_DONE = 0x00E0
class MsgFlashDone(SBP):
  """
  SBP class for message MSG_FLASH_DONE (0x00E0)
  """

  def __init__(self, sbp):
    self.__dict__.update(sbp.__dict__)
    self.payload = sbp.payload

  def __repr__(self):
    return to_repr(self)


SBP_MSG_FLASH_READ = 0x00E1
class MsgFlashRead(SBP):
  """
  SBP class for message MSG_FLASH_READ (0x00E1)
  """

  def __init__(self, sbp):
    self.__dict__.update(sbp.__dict__)
    self.payload = sbp.payload

  def __repr__(self):
    return to_repr(self)


SBP_MSG_FLASH_ERASE = 0x00E2
class MsgFlashErase(SBP):
  """
  SBP class for message MSG_FLASH_ERASE (0x00E2)
  """

  def __init__(self, sbp):
    self.__dict__.update(sbp.__dict__)
    self.payload = sbp.payload

  def __repr__(self):
    return to_repr(self)


SBP_MSG_STM_FLASH_LOCK_SECTOR = 0x00E3
class MsgStmFlashLockSector(SBP):
  """
  SBP class for message MSG_STM_FLASH_LOCK_SECTOR (0x00E3)
  """

  def __init__(self, sbp):
    self.__dict__.update(sbp.__dict__)
    self.payload = sbp.payload

  def __repr__(self):
    return to_repr(self)


SBP_MSG_STM_FLASH_UNLOCK_SECTOR = 0x00E4
class MsgStmFlashUnlockSector(SBP):
  """
  SBP class for message MSG_STM_FLASH_UNLOCK_SECTOR (0x00E4)
  """

  def __init__(self, sbp):
    self.__dict__.update(sbp.__dict__)
    self.payload = sbp.payload

  def __repr__(self):
    return to_repr(self)


SBP_MSG_STM_UNIQUE_ID = 0x00E5
class MsgStmUniqueId(SBP):
  """
  SBP class for message MSG_STM_UNIQUE_ID (0x00E5)
  """

  def __init__(self, sbp):
    self.__dict__.update(sbp.__dict__)
    self.payload = sbp.payload

  def __repr__(self):
    return to_repr(self)


SBP_MSG_M25_FLASH_WRITE_STATUS = 0x00F3
class MsgM25FlashWriteStatus(SBP):
  """
  SBP class for message MSG_M25_FLASH_WRITE_STATUS (0x00F3)
  """

  def __init__(self, sbp):
    self.__dict__.update(sbp.__dict__)
    self.payload = sbp.payload

  def __repr__(self):
    return to_repr(self)


SBP_MSG_RESET_FILTERS = 0x0022
class MsgResetFilters(SBP):
  """
  SBP class for message MSG_RESET_FILTERS (0x0022)
  """

  def __init__(self, sbp):
    self.__dict__.update(sbp.__dict__)
    self.payload = sbp.payload

  def __repr__(self):
    return to_repr(self)


SBP_MSG_INIT_BASE = 0x0023
class MsgInitBase(SBP):
  """
  SBP class for message MSG_INIT_BASE (0x0023)
  """

  def __init__(self, sbp):
    self.__dict__.update(sbp.__dict__)
    self.payload = sbp.payload

  def __repr__(self):
    return to_repr(self)


SBP_MSG_SETTINGS = 0x00A0
class MsgSettings(SBP):
  """
  SBP class for message MSG_SETTINGS (0x00A0)
  """

  def __init__(self, sbp):
    self.__dict__.update(sbp.__dict__)
    self.payload = sbp.payload

  def __repr__(self):
    return to_repr(self)


SBP_MSG_SETTINGS_SAVE = 0x00A1
class MsgSettingsSave(SBP):
  """
  SBP class for message MSG_SETTINGS_SAVE (0x00A1)
  """

  def __init__(self, sbp):
    self.__dict__.update(sbp.__dict__)
    self.payload = sbp.payload

  def __repr__(self):
    return to_repr(self)


SBP_MSG_SETTINGS_READ_BY_INDEX = 0x00A2
class MsgSettingsReadByIndex(SBP):
  """
  SBP class for message MSG_SETTINGS_READ_BY_INDEX (0x00A2)
  """

  def __init__(self, sbp):
    self.__dict__.update(sbp.__dict__)
    self.payload = sbp.payload

  def __repr__(self):
    return to_repr(self)


SBP_MSG_FILEIO_READ = 0x00A8
class MsgFileioRead(SBP):
  """
  SBP class for message MSG_FILEIO_READ (0x00A8)
  """

  def __init__(self, sbp):
    self.__dict__.update(sbp.__dict__)
    self.payload = sbp.payload

  def __repr__(self):
    return to_repr(self)


SBP_MSG_FILEIO_READ_DIR = 0x00A9
class MsgFileioReadDir(SBP):
  """
  SBP class for message MSG_FILEIO_READ_DIR (0x00A9)
  """

  def __init__(self, sbp):
    self.__dict__.update(sbp.__dict__)
    self.payload = sbp.payload

  def __repr__(self):
    return to_repr(self)


SBP_MSG_FILEIO_REMOVE = 0x00AC
class MsgFileioRemove(SBP):
  """
  SBP class for message MSG_FILEIO_REMOVE (0x00AC)
  """

  def __init__(self, sbp):
    self.__dict__.update(sbp.__dict__)
    self.payload = sbp.payload

  def __repr__(self):
    return to_repr(self)


SBP_MSG_FILEIO_WRITE = 0x00AD
class MsgFileioWrite(SBP):
  """
  SBP class for message MSG_FILEIO_WRITE (0x00AD)
  """

  def __init__(self, sbp):
    self.__dict__.update(sbp.__dict__)
    self.payload = sbp.payload

  def __repr__(self):
    return to_repr(self)


SBP_MSG_THREAD_STATE = 0x0017
class MsgThreadState(SBP):
  """
  SBP class for message MSG_THREAD_STATE (0x0017)
    MSG_THREAD_STATE

  Parameters
  ----------
  name : string
    name
  cpu : int
    cpu
  stack_free : int
    stack_free
  """

  def __init__(self, sbp):
    self.__dict__.update(sbp.__dict__)
    self.from_binary(sbp.payload)

  def __repr__(self):
    return to_repr(self)
  def from_binary(self, d):
    (
      self.name,
      self.cpu,
      self.stack_free,
    ) = struct.unpack('NOPE', d)

  def to_binary(self):
    return struct.pack('NOPE', (
      self.name,
      self.cpu,
      self.stack_free,
    ))


SBP_MSG_UART_STATE = 0x0018
class MsgUartState(SBP):
  """
  SBP class for message MSG_UART_STATE (0x0018)
    MSG_THREAD_STATE

  Parameters
  ----------
  uarts0 : UARTChannel
    latency
  uarts1 : UARTChannel
    latency
  uarts2 : UARTChannel
    latency
  latency : Latency
    latency
  """

  def __init__(self, sbp):
    self.__dict__.update(sbp.__dict__)
    self.from_binary(sbp.payload)

  def __repr__(self):
    return to_repr(self)
  def from_binary(self, d):
    (
      self.uarts0,
      self.uarts1,
      self.uarts2,
      self.latency,
    ) = struct.unpack('NOPE', d)

  def to_binary(self):
    return struct.pack('NOPE', (
      self.uarts0,
      self.uarts1,
      self.uarts2,
      self.latency,
    ))


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
}

def sbp_decode(t, d):
  return msg_classes[t](d)