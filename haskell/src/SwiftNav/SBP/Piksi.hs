{-# OPTIONS_GHC -fno-warn-unused-imports #-}
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
-- used.

module SwiftNav.SBP.Piksi where

import BasicPrelude
import Control.Lens
import Control.Monad.Loops
import Data.Aeson.TH           (defaultOptions, deriveJSON, fieldLabelModifier)
import Data.Binary
import Data.Binary.Get
import Data.Binary.IEEE754
import Data.Binary.Put
import Data.ByteString
import Data.ByteString.Lazy    hiding (ByteString)
import Data.Int
import Data.Word
import SwiftNav.SBP.Encoding
import SwiftNav.SBP.TH
import SwiftNav.SBP.Types
import SwiftNav.SBP.GnssSignal

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

$(deriveSBP 'msgAlmanac ''MsgAlmanac)

$(deriveJSON defaultOptions {fieldLabelModifier = fromMaybe "_msgAlmanac_" . stripPrefix "_msgAlmanac_"}
             ''MsgAlmanac)
$(makeLenses ''MsgAlmanac)

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

$(deriveSBP 'msgSetTime ''MsgSetTime)

$(deriveJSON defaultOptions {fieldLabelModifier = fromMaybe "_msgSetTime_" . stripPrefix "_msgSetTime_"}
             ''MsgSetTime)
$(makeLenses ''MsgSetTime)

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

$(deriveSBP 'msgReset ''MsgReset)

$(deriveJSON defaultOptions {fieldLabelModifier = fromMaybe "_msgReset_" . stripPrefix "_msgReset_"}
             ''MsgReset)
$(makeLenses ''MsgReset)

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

$(deriveSBP 'msgCwResults ''MsgCwResults)

$(deriveJSON defaultOptions {fieldLabelModifier = fromMaybe "_msgCwResults_" . stripPrefix "_msgCwResults_"}
             ''MsgCwResults)
$(makeLenses ''MsgCwResults)

msgCwStart :: Word16
msgCwStart = 0x00C1

-- | SBP class for message MSG_CW_START (0x00C1).
--
-- This is an unused legacy message from the host for starting the CW
-- interference channel on the SwiftNAP. This message will be removed in a
-- future release.
data MsgCwStart = MsgCwStart
  deriving ( Show, Read, Eq )

instance Binary MsgCwStart where
  get =
    return MsgCwStart

  put MsgCwStart =
    return ()

$(deriveSBP 'msgCwStart ''MsgCwStart)

$(deriveJSON defaultOptions {fieldLabelModifier = fromMaybe "_msgCwStart_" . stripPrefix "_msgCwStart_"}
             ''MsgCwStart)
$(makeLenses ''MsgCwStart)

msgResetFilters :: Word16
msgResetFilters = 0x0022

-- | SBP class for message MSG_RESET_FILTERS (0x0022).
--
-- This message resets either the DGNSS Kalman filters or Integer Ambiguity
-- Resolution (IAR) process.
data MsgResetFilters = MsgResetFilters
  { _msgResetFilters_filter :: Word8
    -- ^ Filter flags
  } deriving ( Show, Read, Eq )

instance Binary MsgResetFilters where
  get = do
    _msgResetFilters_filter <- getWord8
    return MsgResetFilters {..}

  put MsgResetFilters {..} = do
    putWord8 _msgResetFilters_filter

$(deriveSBP 'msgResetFilters ''MsgResetFilters)

$(deriveJSON defaultOptions {fieldLabelModifier = fromMaybe "_msgResetFilters_" . stripPrefix "_msgResetFilters_"}
             ''MsgResetFilters)
$(makeLenses ''MsgResetFilters)

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

$(deriveSBP 'msgInitBase ''MsgInitBase)

$(deriveJSON defaultOptions {fieldLabelModifier = fromMaybe "_msgInitBase_" . stripPrefix "_msgInitBase_"}
             ''MsgInitBase)
$(makeLenses ''MsgInitBase)

msgThreadState :: Word16
msgThreadState = 0x0017

-- | SBP class for message MSG_THREAD_STATE (0x0017).
--
-- The thread usage message from the device reports real-time operating system
-- (RTOS) thread usage statistics for the named thread. The reported percentage
-- values must be normalized.
data MsgThreadState = MsgThreadState
  { _msgThreadState_name     :: ByteString
    -- ^ Thread name (NULL terminated)
  , _msgThreadState_cpu      :: Word16
    -- ^ Percentage cpu use for this thread. Values range from 0 - 1000 and needs
    -- to be renormalized to 100
  , _msgThreadState_stack_free :: Word32
    -- ^ Free stack space for this thread
  } deriving ( Show, Read, Eq )

instance Binary MsgThreadState where
  get = do
    _msgThreadState_name <- getByteString 20
    _msgThreadState_cpu <- getWord16le
    _msgThreadState_stack_free <- getWord32le
    return MsgThreadState {..}

  put MsgThreadState {..} = do
    putByteString _msgThreadState_name
    putWord16le _msgThreadState_cpu
    putWord32le _msgThreadState_stack_free

$(deriveSBP 'msgThreadState ''MsgThreadState)

$(deriveJSON defaultOptions {fieldLabelModifier = fromMaybe "_msgThreadState_" . stripPrefix "_msgThreadState_"}
             ''MsgThreadState)
$(makeLenses ''MsgThreadState)

-- | UARTChannel.
--
-- Throughput, utilization, and error counts on the RX/TX buffers of this UART
-- channel. The reported percentage values must be normalized.
data UARTChannel = UARTChannel
  { _uARTChannel_tx_throughput :: Float
    -- ^ UART transmit throughput
  , _uARTChannel_rx_throughput :: Float
    -- ^ UART receive throughput
  , _uARTChannel_crc_error_count :: Word16
    -- ^ UART CRC error count
  , _uARTChannel_io_error_count :: Word16
    -- ^ UART IO error count
  , _uARTChannel_tx_buffer_level :: Word8
    -- ^ UART transmit buffer percentage utilization (ranges from 0 to 255)
  , _uARTChannel_rx_buffer_level :: Word8
    -- ^ UART receive buffer percentage utilization (ranges from 0 to 255)
  } deriving ( Show, Read, Eq )

instance Binary UARTChannel where
  get = do
    _uARTChannel_tx_throughput <- getFloat32le
    _uARTChannel_rx_throughput <- getFloat32le
    _uARTChannel_crc_error_count <- getWord16le
    _uARTChannel_io_error_count <- getWord16le
    _uARTChannel_tx_buffer_level <- getWord8
    _uARTChannel_rx_buffer_level <- getWord8
    return UARTChannel {..}

  put UARTChannel {..} = do
    putFloat32le _uARTChannel_tx_throughput
    putFloat32le _uARTChannel_rx_throughput
    putWord16le _uARTChannel_crc_error_count
    putWord16le _uARTChannel_io_error_count
    putWord8 _uARTChannel_tx_buffer_level
    putWord8 _uARTChannel_rx_buffer_level
$(deriveJSON defaultOptions {fieldLabelModifier = fromMaybe "_uARTChannel_" . stripPrefix "_uARTChannel_"}
             ''UARTChannel)
$(makeLenses ''UARTChannel)

-- | Period.
--
-- Statistics on the period of observations received from the base station. As
-- complete observation sets are received, their time of reception is compared
-- with the prior set''s time of reception. This measurement provides a proxy
-- for link quality as incomplete or missing sets will increase the period.
-- Long periods can cause momentary RTK solution outages.
data Period = Period
  { _period_avg   :: Int32
    -- ^ Average period
  , _period_pmin  :: Int32
    -- ^ Minimum period
  , _period_pmax  :: Int32
    -- ^ Maximum period
  , _period_current :: Int32
    -- ^ Smoothed estimate of the current period
  } deriving ( Show, Read, Eq )

instance Binary Period where
  get = do
    _period_avg <- liftM fromIntegral getWord32le
    _period_pmin <- liftM fromIntegral getWord32le
    _period_pmax <- liftM fromIntegral getWord32le
    _period_current <- liftM fromIntegral getWord32le
    return Period {..}

  put Period {..} = do
    putWord32le $ fromIntegral _period_avg
    putWord32le $ fromIntegral _period_pmin
    putWord32le $ fromIntegral _period_pmax
    putWord32le $ fromIntegral _period_current
$(deriveJSON defaultOptions {fieldLabelModifier = fromMaybe "_period_" . stripPrefix "_period_"}
             ''Period)
$(makeLenses ''Period)

-- | Latency.
--
-- Statistics on the latency of observations received from the base station. As
-- observation packets are received their GPS time is compared to the current
-- GPS time calculated locally by the receiver to give a precise measurement of
-- the end-to-end communication latency in the system.
data Latency = Latency
  { _latency_avg   :: Int32
    -- ^ Average latency
  , _latency_lmin  :: Int32
    -- ^ Minimum latency
  , _latency_lmax  :: Int32
    -- ^ Maximum latency
  , _latency_current :: Int32
    -- ^ Smoothed estimate of the current latency
  } deriving ( Show, Read, Eq )

instance Binary Latency where
  get = do
    _latency_avg <- liftM fromIntegral getWord32le
    _latency_lmin <- liftM fromIntegral getWord32le
    _latency_lmax <- liftM fromIntegral getWord32le
    _latency_current <- liftM fromIntegral getWord32le
    return Latency {..}

  put Latency {..} = do
    putWord32le $ fromIntegral _latency_avg
    putWord32le $ fromIntegral _latency_lmin
    putWord32le $ fromIntegral _latency_lmax
    putWord32le $ fromIntegral _latency_current
$(deriveJSON defaultOptions {fieldLabelModifier = fromMaybe "_latency_" . stripPrefix "_latency_"}
             ''Latency)
$(makeLenses ''Latency)

msgUartState :: Word16
msgUartState = 0x001D

-- | SBP class for message MSG_UART_STATE (0x001D).
--
-- The UART message reports data latency and throughput of the UART channels
-- providing SBP I/O. On the default Piksi configuration, UARTs A and B are
-- used for telemetry radios, but can also be host access ports for embedded
-- hosts, or other interfaces in future. The reported percentage values must be
-- normalized. Observations latency and period can be used to assess the
-- health of the differential corrections link. Latency provides the timeliness
-- of received base observations while the  period indicates their likelihood
-- of transmission.
data MsgUartState = MsgUartState
  { _msgUartState_uart_a   :: UARTChannel
    -- ^ State of UART A
  , _msgUartState_uart_b   :: UARTChannel
    -- ^ State of UART B
  , _msgUartState_uart_ftdi :: UARTChannel
    -- ^ State of UART FTDI (USB logger)
  , _msgUartState_latency  :: Latency
    -- ^ UART communication latency
  , _msgUartState_obs_period :: Period
    -- ^ Observation receipt period
  } deriving ( Show, Read, Eq )

instance Binary MsgUartState where
  get = do
    _msgUartState_uart_a <- get
    _msgUartState_uart_b <- get
    _msgUartState_uart_ftdi <- get
    _msgUartState_latency <- get
    _msgUartState_obs_period <- get
    return MsgUartState {..}

  put MsgUartState {..} = do
    put _msgUartState_uart_a
    put _msgUartState_uart_b
    put _msgUartState_uart_ftdi
    put _msgUartState_latency
    put _msgUartState_obs_period

$(deriveSBP 'msgUartState ''MsgUartState)

$(deriveJSON defaultOptions {fieldLabelModifier = fromMaybe "_msgUartState_" . stripPrefix "_msgUartState_"}
             ''MsgUartState)
$(makeLenses ''MsgUartState)

msgUartStateDepa :: Word16
msgUartStateDepa = 0x0018

-- | SBP class for message MSG_UART_STATE_DEPA (0x0018).
--
-- Deprecated
data MsgUartStateDepa = MsgUartStateDepa
  { _msgUartStateDepa_uart_a  :: UARTChannel
    -- ^ State of UART A
  , _msgUartStateDepa_uart_b  :: UARTChannel
    -- ^ State of UART B
  , _msgUartStateDepa_uart_ftdi :: UARTChannel
    -- ^ State of UART FTDI (USB logger)
  , _msgUartStateDepa_latency :: Latency
    -- ^ UART communication latency
  } deriving ( Show, Read, Eq )

instance Binary MsgUartStateDepa where
  get = do
    _msgUartStateDepa_uart_a <- get
    _msgUartStateDepa_uart_b <- get
    _msgUartStateDepa_uart_ftdi <- get
    _msgUartStateDepa_latency <- get
    return MsgUartStateDepa {..}

  put MsgUartStateDepa {..} = do
    put _msgUartStateDepa_uart_a
    put _msgUartStateDepa_uart_b
    put _msgUartStateDepa_uart_ftdi
    put _msgUartStateDepa_latency

$(deriveSBP 'msgUartStateDepa ''MsgUartStateDepa)

$(deriveJSON defaultOptions {fieldLabelModifier = fromMaybe "_msgUartStateDepa_" . stripPrefix "_msgUartStateDepa_"}
             ''MsgUartStateDepa)
$(makeLenses ''MsgUartStateDepa)

msgIarState :: Word16
msgIarState = 0x0019

-- | SBP class for message MSG_IAR_STATE (0x0019).
--
-- This message reports the state of the Integer Ambiguity Resolution (IAR)
-- process, which resolves unknown integer ambiguities from double-differenced
-- carrier-phase measurements from satellite observations.
data MsgIarState = MsgIarState
  { _msgIarState_num_hyps :: Word32
    -- ^ Number of integer ambiguity hypotheses remaining
  } deriving ( Show, Read, Eq )

instance Binary MsgIarState where
  get = do
    _msgIarState_num_hyps <- getWord32le
    return MsgIarState {..}

  put MsgIarState {..} = do
    putWord32le _msgIarState_num_hyps

$(deriveSBP 'msgIarState ''MsgIarState)

$(deriveJSON defaultOptions {fieldLabelModifier = fromMaybe "_msgIarState_" . stripPrefix "_msgIarState_"}
             ''MsgIarState)
$(makeLenses ''MsgIarState)

msgMaskSatellite :: Word16
msgMaskSatellite = 0x001B

-- | SBP class for message MSG_MASK_SATELLITE (0x001B).
--
-- This message allows setting a mask to prevent a particular satellite from
-- being used in various Piksi subsystems.
data MsgMaskSatellite = MsgMaskSatellite
  { _msgMaskSatellite_mask :: Word8
    -- ^ Mask of systems that should ignore this satellite.
  , _msgMaskSatellite_sid :: GnssSignal
    -- ^ GNSS signal for which the mask is applied
  } deriving ( Show, Read, Eq )

instance Binary MsgMaskSatellite where
  get = do
    _msgMaskSatellite_mask <- getWord8
    _msgMaskSatellite_sid <- get
    return MsgMaskSatellite {..}

  put MsgMaskSatellite {..} = do
    putWord8 _msgMaskSatellite_mask
    put _msgMaskSatellite_sid

$(deriveSBP 'msgMaskSatellite ''MsgMaskSatellite)

$(deriveJSON defaultOptions {fieldLabelModifier = fromMaybe "_msgMaskSatellite_" . stripPrefix "_msgMaskSatellite_"}
             ''MsgMaskSatellite)
$(makeLenses ''MsgMaskSatellite)
