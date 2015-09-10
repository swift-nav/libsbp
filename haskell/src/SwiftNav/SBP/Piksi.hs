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

import BasicPrelude
import Control.Monad
import Control.Monad.Loops
import Data.Aeson.TH (deriveJSON, defaultOptions, fieldLabelModifier)
import Data.Binary
import Data.Binary.Get
import Data.Binary.IEEE754
import Data.Binary.Put
import Data.ByteString
import Data.ByteString.Lazy hiding ( ByteString )
import Data.Int
import Data.Word
import SwiftNav.SBP.Encoding

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
  { msgResetFilters_filter :: Word8
    -- ^ Filter flags
  } deriving ( Show, Read, Eq )

instance Binary MsgResetFilters where
  get = do
    msgResetFilters_filter <- getWord8
    return MsgResetFilters {..}

  put MsgResetFilters {..} = do
    putWord8 msgResetFilters_filter

$(deriveJSON defaultOptions {fieldLabelModifier = fromMaybe "msgResetFilters_" . stripPrefix "msgResetFilters_"}
             ''MsgResetFilters)

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
  { msgThreadState_name      :: ByteString
    -- ^ Thread name (NULL terminated)
  , msgThreadState_cpu       :: Word16
    -- ^ Percentage cpu use for this thread. Values range from 0 - 1000 and needs
    -- to be renormalized to 100
  , msgThreadState_stack_free :: Word32
    -- ^ Free stack space for this thread
  } deriving ( Show, Read, Eq )

instance Binary MsgThreadState where
  get = do
    msgThreadState_name <- getByteString 20
    msgThreadState_cpu <- getWord16le
    msgThreadState_stack_free <- getWord32le
    return MsgThreadState {..}

  put MsgThreadState {..} = do
    putByteString msgThreadState_name
    putWord16le msgThreadState_cpu
    putWord32le msgThreadState_stack_free

$(deriveJSON defaultOptions {fieldLabelModifier = fromMaybe "msgThreadState_" . stripPrefix "msgThreadState_"}
             ''MsgThreadState)

-- | UARTChannel.
--
-- Throughput, utilization, and error counts on the RX/TX buffers of this UART
-- channel. The reported percentage values require to be normalized.
data UARTChannel = UARTChannel
  { uARTChannel_tx_throughput  :: Float
    -- ^ UART transmit throughput
  , uARTChannel_rx_throughput  :: Float
    -- ^ UART receive throughput
  , uARTChannel_crc_error_count :: Word16
    -- ^ UART CRC error count
  , uARTChannel_io_error_count :: Word16
    -- ^ UART IO error count
  , uARTChannel_tx_buffer_level :: Word8
    -- ^ UART transmit buffer percentage utilization (ranges from 0 - 255)
  , uARTChannel_rx_buffer_level :: Word8
    -- ^ UART receive buffer percentage utilization (ranges from 0 to 255)
  } deriving ( Show, Read, Eq )

instance Binary UARTChannel where
  get = do
    uARTChannel_tx_throughput <- getFloat32le
    uARTChannel_rx_throughput <- getFloat32le
    uARTChannel_crc_error_count <- getWord16le
    uARTChannel_io_error_count <- getWord16le
    uARTChannel_tx_buffer_level <- getWord8
    uARTChannel_rx_buffer_level <- getWord8
    return UARTChannel {..}

  put UARTChannel {..} = do
    putFloat32le uARTChannel_tx_throughput
    putFloat32le uARTChannel_rx_throughput
    putWord16le uARTChannel_crc_error_count
    putWord16le uARTChannel_io_error_count
    putWord8 uARTChannel_tx_buffer_level
    putWord8 uARTChannel_rx_buffer_level

$(deriveJSON defaultOptions {fieldLabelModifier = fromMaybe "uARTChannel_" . stripPrefix "uARTChannel_"}
             ''UARTChannel)

-- | Latency.
--
-- Statistics on the latency of observations received from the base station. As
-- observation packets are received their GPS time is compared to the current
-- GPS time calculated locally by the receiver to give a precise measurement of
-- the end-to-end communication latency in the system.
data Latency = Latency
  { latency_avg    :: Int32
    -- ^ Average latency
  , latency_lmin   :: Int32
    -- ^ Minimum latency
  , latency_lmax   :: Int32
    -- ^ Maximum latency
  , latency_current :: Int32
    -- ^ Smoothed estimate of the current latency
  } deriving ( Show, Read, Eq )

instance Binary Latency where
  get = do
    latency_avg <- liftM fromIntegral getWord32le
    latency_lmin <- liftM fromIntegral getWord32le
    latency_lmax <- liftM fromIntegral getWord32le
    latency_current <- liftM fromIntegral getWord32le
    return Latency {..}

  put Latency {..} = do
    putWord32le $ fromIntegral latency_avg
    putWord32le $ fromIntegral latency_lmin
    putWord32le $ fromIntegral latency_lmax
    putWord32le $ fromIntegral latency_current

$(deriveJSON defaultOptions {fieldLabelModifier = fromMaybe "latency_" . stripPrefix "latency_"}
             ''Latency)

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
  { msgUartState_uart_a   :: UARTChannel
    -- ^ State of UART A
  , msgUartState_uart_b   :: UARTChannel
    -- ^ State of UART B
  , msgUartState_uart_ftdi :: UARTChannel
    -- ^ State of UART FTDI (USB logger)
  , msgUartState_latency  :: Latency
    -- ^ UART communication latency
  } deriving ( Show, Read, Eq )

instance Binary MsgUartState where
  get = do
    msgUartState_uart_a <- get
    msgUartState_uart_b <- get
    msgUartState_uart_ftdi <- get
    msgUartState_latency <- get
    return MsgUartState {..}

  put MsgUartState {..} = do
    put msgUartState_uart_a
    put msgUartState_uart_b
    put msgUartState_uart_ftdi
    put msgUartState_latency

$(deriveJSON defaultOptions {fieldLabelModifier = fromMaybe "msgUartState_" . stripPrefix "msgUartState_"}
             ''MsgUartState)

msgIarState :: Word16
msgIarState = 0x0019

-- | SBP class for message MSG_IAR_STATE (0x0019).
--
-- This message reports the state of the Integer Ambiguity Resolution (IAR)
-- process, which resolves unknown integer ambiguities from double-differenced
-- carrier-phase measurements from satellite observations.
data MsgIarState = MsgIarState
  { msgIarState_num_hyps :: Word32
    -- ^ Number of integer ambiguity hypotheses remaining
  } deriving ( Show, Read, Eq )

instance Binary MsgIarState where
  get = do
    msgIarState_num_hyps <- getWord32le
    return MsgIarState {..}

  put MsgIarState {..} = do
    putWord32le msgIarState_num_hyps

$(deriveJSON defaultOptions {fieldLabelModifier = fromMaybe "msgIarState_" . stripPrefix "msgIarState_"}
             ''MsgIarState)

msgMaskSatellite :: Word16
msgMaskSatellite = 0x001B

-- | SBP class for message MSG_MASK_SATELLITE (0x001B).
--
-- This message allows setting a mask to prevent a particular satellite from
-- being used in various Piksi subsystems.
data MsgMaskSatellite = MsgMaskSatellite
  { msgMaskSatellite_mask :: Word8
    -- ^ Mask of systems that should ignore this satellite.
  , msgMaskSatellite_sid :: Word32
    -- ^ Signal identifier for which the mask is applied
  } deriving ( Show, Read, Eq )

instance Binary MsgMaskSatellite where
  get = do
    msgMaskSatellite_mask <- getWord8
    msgMaskSatellite_sid <- getWord32le
    return MsgMaskSatellite {..}

  put MsgMaskSatellite {..} = do
    putWord8 msgMaskSatellite_mask
    putWord32le msgMaskSatellite_sid

$(deriveJSON defaultOptions {fieldLabelModifier = fromMaybe "msgMaskSatellite_" . stripPrefix "msgMaskSatellite_"}
             ''MsgMaskSatellite)
