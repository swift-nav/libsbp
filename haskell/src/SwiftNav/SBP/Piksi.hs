-- |
-- Module:      SwiftNav.SBP.Piksi
-- Copyright:   Copyright (C) 2015 Swift Navigation, Inc.
-- License:     LGPL-3
-- Maintainer:  Mark Fine <dev@swiftnav.com>
-- Stability:   experimental
-- Portability: portable
--
-- System health, configuration, and diagnostic messages specific to the Piksi
-- L1 receiver, including a variety of legacy messages that may no longer be
-- used.  These messages are in the implementation-defined range
-- (0x0000-0x00FF), and largely intended for internal-use only.

module SwiftNav.SBP.Piksi where

import Control.Monad
import Control.Monad.Loops
import Data.Binary
import Data.Binary.Get
import Data.Binary.IEEE754
import Data.Binary.Put
import Data.ByteString
import Data.ByteString.Lazy hiding ( ByteString )
import Data.Int
import Data.Word

msgAlmanac :: Word16
msgAlmanac = 0x0069

-- | SBP class for message MSG_ALMANAC (0x0069).
--
-- This is a legacy message for sending and loading a satellite alamanac onto
-- the Piksi's flash memory from the host.
data MsgAlmanac = MsgAlmanac
  deriving ( Show, Read, Eq )

instance Binary MsgAlmanac where
  get =
    return MsgAlmanac

  put MsgAlmanac =
    return ()

msgSetTime :: Word16
msgSetTime = 0x0068

-- | SBP class for message MSG_SET_TIME (0x0068).
--
-- This message sets up timing functionality using a coarse GPS time estimate
-- sent by the host.
data MsgSetTime = MsgSetTime
  deriving ( Show, Read, Eq )

instance Binary MsgSetTime where
  get =
    return MsgSetTime

  put MsgSetTime =
    return ()

msgReset :: Word16
msgReset = 0x00B2

-- | SBP class for message MSG_RESET (0x00B2).
--
-- This message from the host resets the Piksi back into the bootloader.
data MsgReset = MsgReset
  deriving ( Show, Read, Eq )

instance Binary MsgReset where
  get =
    return MsgReset

  put MsgReset =
    return ()

msgCwResults :: Word16
msgCwResults = 0x00C0

-- | SBP class for message MSG_CW_RESULTS (0x00C0).
--
-- This is an unused legacy message for result reporting from the CW
-- interference channel on the SwiftNAP. This message will be removed in a
-- future release.
data MsgCwResults = MsgCwResults
  deriving ( Show, Read, Eq )

instance Binary MsgCwResults where
  get =
    return MsgCwResults

  put MsgCwResults =
    return ()

msgCwStart :: Word16
msgCwStart = 0x00C1

-- | SBP class for message MSG_CW_START (0x00C1).
--
-- This is an unused legacy message from those host for starting the CW
-- interference channel on the SwiftNAP. This message will be removed in a
-- future release.
data MsgCwStart = MsgCwStart
  deriving ( Show, Read, Eq )

instance Binary MsgCwStart where
  get =
    return MsgCwStart

  put MsgCwStart =
    return ()

msgResetFilters :: Word16
msgResetFilters = 0x0022

-- | SBP class for message MSG_RESET_FILTERS (0x0022).
--
-- This message resets either the DGNSS Kalman filters or Integer Ambiguity
-- Resolution (IAR) process.
data MsgResetFilters = MsgResetFilters
  { msgResetFiltersFilter :: Word8
    -- ^ Filter flags
  } deriving ( Show, Read, Eq )

instance Binary MsgResetFilters where
  get = do
    msgResetFiltersFilter <- getWord8
    return MsgResetFilters {..}

  put MsgResetFilters {..} = do
    putWord8 msgResetFiltersFilter

msgInitBase :: Word16
msgInitBase = 0x0023

-- | SBP class for message MSG_INIT_BASE (0x0023).
--
-- This message initializes the integer ambiguity resolution (IAR) process on
-- the Piksi to use an assumed baseline position between the base station and
-- rover receivers. Warns via MSG_PRINT if there aren't a shared minimum number
-- (4) of satellite observations between the two.
data MsgInitBase = MsgInitBase
  deriving ( Show, Read, Eq )

instance Binary MsgInitBase where
  get =
    return MsgInitBase

  put MsgInitBase =
    return ()

msgThreadState :: Word16
msgThreadState = 0x0017

-- | SBP class for message MSG_THREAD_STATE (0x0017).
--
-- The thread usage message from the device reports real-time operating system
-- (RTOS) thread usage statistics for the named thread. The reported percentage
-- values require to be normalized.
data MsgThreadState = MsgThreadState
  { msgThreadStateName       :: ByteString
    -- ^ Thread name (NULL terminated)
  , msgThreadStateCpu        :: Word16
    -- ^ Percentage cpu use for this thread. Values range from 0 - 1000 and needs
    -- to be renormalized to 100
  , msgThreadStateStackFree  :: Word32
    -- ^ Free stack space for this thread
  } deriving ( Show, Read, Eq )

instance Binary MsgThreadState where
  get = do
    msgThreadStateName <- getByteString 20
    msgThreadStateCpu <- getWord16le
    msgThreadStateStackFree <- getWord32le
    return MsgThreadState {..}

  put MsgThreadState {..} = do
    putByteString msgThreadStateName
    putWord16le msgThreadStateCpu
    putWord32le msgThreadStateStackFree

-- | UARTChannel.
--
-- Throughput, utilization, and error counts on the RX/TX buffers of this UART
-- channel. The reported percentage values require to be normalized.
data UARTChannel = UARTChannel
  { uARTChannelTxThroughput    :: Float
    -- ^ UART transmit throughput
  , uARTChannelRxThroughput    :: Float
    -- ^ UART receive throughput
  , uARTChannelCrcErrorCount   :: Word16
    -- ^ UART CRC error count
  , uARTChannelIoErrorCount    :: Word16
    -- ^ UART IO error count
  , uARTChannelTxBufferLevel   :: Word8
    -- ^ UART transmit buffer percentage utilization (ranges from 0 - 255)
  , uARTChannelRxBufferLevel   :: Word8
    -- ^ UART receive buffer percentage utilization (ranges from 0 to 255)
  } deriving ( Show, Read, Eq )

instance Binary UARTChannel where
  get = do
    uARTChannelTxThroughput <- getFloat32le
    uARTChannelRxThroughput <- getFloat32le
    uARTChannelCrcErrorCount <- getWord16le
    uARTChannelIoErrorCount <- getWord16le
    uARTChannelTxBufferLevel <- getWord8
    uARTChannelRxBufferLevel <- getWord8
    return UARTChannel {..}

  put UARTChannel {..} = do
    putFloat32le uARTChannelTxThroughput
    putFloat32le uARTChannelRxThroughput
    putWord16le uARTChannelCrcErrorCount
    putWord16le uARTChannelIoErrorCount
    putWord8 uARTChannelTxBufferLevel
    putWord8 uARTChannelRxBufferLevel

-- | Latency.
--
-- Statistics on the latency of observations received from the base station. As
-- observation packets are received their GPS time is compared to the current
-- GPS time calculated locally by the receiver to give a precise measurement of
-- the end-to-end communication latency in the system.
data Latency = Latency
  { latencyAvg     :: Int32
    -- ^ Average latency
  , latencyLmin    :: Int32
    -- ^ Minimum latency
  , latencyLmax    :: Int32
    -- ^ Maximum latency
  , latencyCurrent :: Int32
    -- ^ Smoothed estimate of the current latency
  } deriving ( Show, Read, Eq )

instance Binary Latency where
  get = do
    latencyAvg <- liftM fromIntegral getWord32le
    latencyLmin <- liftM fromIntegral getWord32le
    latencyLmax <- liftM fromIntegral getWord32le
    latencyCurrent <- liftM fromIntegral getWord32le
    return Latency {..}

  put Latency {..} = do
    putWord32le $ fromIntegral latencyAvg
    putWord32le $ fromIntegral latencyLmin
    putWord32le $ fromIntegral latencyLmax
    putWord32le $ fromIntegral latencyCurrent

msgUartState :: Word16
msgUartState = 0x0018

-- | SBP class for message MSG_UART_STATE (0x0018).
--
-- The UART message reports data latency and throughput of the UART channels
-- providing SBP I/O. On the default Piksi configuration, UARTs A and B are
-- used for telemetry radios, but can also be host access ports for embedded
-- hosts, or other interfaces in future. The reported percentage values require
-- to be normalized.
data MsgUartState = MsgUartState
  { msgUartStateUartA     :: UARTChannel
    -- ^ State of UART A
  , msgUartStateUartB     :: UARTChannel
    -- ^ State of UART B
  , msgUartStateUartFtdi  :: UARTChannel
    -- ^ State of UART FTDI (USB logger)
  , msgUartStateLatency   :: Latency
    -- ^ UART communication latency
  } deriving ( Show, Read, Eq )

instance Binary MsgUartState where
  get = do
    msgUartStateUartA <- get
    msgUartStateUartB <- get
    msgUartStateUartFtdi <- get
    msgUartStateLatency <- get
    return MsgUartState {..}

  put MsgUartState {..} = do
    put msgUartStateUartA
    put msgUartStateUartB
    put msgUartStateUartFtdi
    put msgUartStateLatency

msgIarState :: Word16
msgIarState = 0x0019

-- | SBP class for message MSG_IAR_STATE (0x0019).
--
-- This message reports the state of the Integer Ambiguity Resolution (IAR)
-- process, which resolves unknown integer ambiguities from double-differenced
-- carrier-phase measurements from satellite observations.
data MsgIarState = MsgIarState
  { msgIarStateNumHyps  :: Word32
    -- ^ Number of integer ambiguity hypotheses remaining
  } deriving ( Show, Read, Eq )

instance Binary MsgIarState where
  get = do
    msgIarStateNumHyps <- getWord32le
    return MsgIarState {..}

  put MsgIarState {..} = do
    putWord32le msgIarStateNumHyps

msgMaskSatellite :: Word16
msgMaskSatellite = 0x001B

-- | SBP class for message MSG_MASK_SATELLITE (0x001B).
--
-- This message allows setting a mask to prevent a particular satellite from
-- being used in various Piksi subsystems.
data MsgMaskSatellite = MsgMaskSatellite
  { msgMaskSatelliteMask :: Word8
    -- ^ Mask of systems that should ignore this satellite.
  , msgMaskSatelliteSid  :: Word32
    -- ^ Signal identifier for which the mask is applied
  } deriving ( Show, Read, Eq )

instance Binary MsgMaskSatellite where
  get = do
    msgMaskSatelliteMask <- getWord8
    msgMaskSatelliteSid <- getWord32le
    return MsgMaskSatellite {..}

  put MsgMaskSatellite {..} = do
    putWord8 msgMaskSatelliteMask
    putWord32le msgMaskSatelliteSid
