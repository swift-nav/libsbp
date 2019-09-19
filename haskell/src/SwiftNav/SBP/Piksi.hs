{-# OPTIONS_GHC -fno-warn-unused-imports #-}
{-# LANGUAGE NoImplicitPrelude           #-}
{-# LANGUAGE TemplateHaskell             #-}
{-# LANGUAGE RecordWildCards             #-}

-- |
-- Module:      SwiftNav.SBP.Piksi
-- Copyright:   Copyright (C) 2015-2018 Swift Navigation, Inc.
-- License:     LGPL-3
-- Maintainer:  Swift Navigation <dev@swiftnav.com>
-- Stability:   experimental
-- Portability: portable
--
-- \<System health, configuration, and diagnostic messages specific to the
-- Piksi L1 receiver, including a variety of legacy messages that may no longer
-- be used. \>

module SwiftNav.SBP.Piksi
  ( module SwiftNav.SBP.Piksi
  ) where

import BasicPrelude
import Control.Lens
import Control.Monad.Loops
import Data.Binary
import Data.Binary.Get
import Data.Binary.IEEE754
import Data.Binary.Put
import Data.ByteString.Lazy    hiding (ByteString)
import Data.Int
import Data.Word
import SwiftNav.SBP.TH
import SwiftNav.SBP.Types
import SwiftNav.SBP.Gnss

{-# ANN module ("HLint: ignore Use camelCase"::String) #-}
{-# ANN module ("HLint: ignore Redundant do"::String) #-}
{-# ANN module ("HLint: ignore Use newtype instead of data"::String) #-}


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
    pure MsgAlmanac

  put MsgAlmanac =
    pure ()
$(makeSBP 'msgAlmanac ''MsgAlmanac)
$(makeJSON "_msgAlmanac_" ''MsgAlmanac)
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
    pure MsgSetTime

  put MsgSetTime =
    pure ()
$(makeSBP 'msgSetTime ''MsgSetTime)
$(makeJSON "_msgSetTime_" ''MsgSetTime)
$(makeLenses ''MsgSetTime)

msgReset :: Word16
msgReset = 0x00B6

-- | SBP class for message MSG_RESET (0x00B6).
--
-- This message from the host resets the Piksi back into the bootloader.
data MsgReset = MsgReset
  { _msgReset_flags :: !Word32
    -- ^ Reset flags
  } deriving ( Show, Read, Eq )

instance Binary MsgReset where
  get = do
    _msgReset_flags <- getWord32le
    pure MsgReset {..}

  put MsgReset {..} = do
    putWord32le _msgReset_flags

$(makeSBP 'msgReset ''MsgReset)
$(makeJSON "_msgReset_" ''MsgReset)
$(makeLenses ''MsgReset)

msgResetDep :: Word16
msgResetDep = 0x00B2

-- | SBP class for message MSG_RESET_DEP (0x00B2).
--
-- This message from the host resets the Piksi back into the bootloader.
data MsgResetDep = MsgResetDep
  deriving ( Show, Read, Eq )

instance Binary MsgResetDep where
  get =
    pure MsgResetDep

  put MsgResetDep =
    pure ()
$(makeSBP 'msgResetDep ''MsgResetDep)
$(makeJSON "_msgResetDep_" ''MsgResetDep)
$(makeLenses ''MsgResetDep)

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
    pure MsgCwResults

  put MsgCwResults =
    pure ()
$(makeSBP 'msgCwResults ''MsgCwResults)
$(makeJSON "_msgCwResults_" ''MsgCwResults)
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
    pure MsgCwStart

  put MsgCwStart =
    pure ()
$(makeSBP 'msgCwStart ''MsgCwStart)
$(makeJSON "_msgCwStart_" ''MsgCwStart)
$(makeLenses ''MsgCwStart)

msgResetFilters :: Word16
msgResetFilters = 0x0022

-- | SBP class for message MSG_RESET_FILTERS (0x0022).
--
-- This message resets either the DGNSS Kalman filters or Integer Ambiguity
-- Resolution (IAR) process.
data MsgResetFilters = MsgResetFilters
  { _msgResetFilters_filter :: !Word8
    -- ^ Filter flags
  } deriving ( Show, Read, Eq )

instance Binary MsgResetFilters where
  get = do
    _msgResetFilters_filter <- getWord8
    pure MsgResetFilters {..}

  put MsgResetFilters {..} = do
    putWord8 _msgResetFilters_filter

$(makeSBP 'msgResetFilters ''MsgResetFilters)
$(makeJSON "_msgResetFilters_" ''MsgResetFilters)
$(makeLenses ''MsgResetFilters)

msgInitBaseDep :: Word16
msgInitBaseDep = 0x0023

-- | SBP class for message MSG_INIT_BASE_DEP (0x0023).
--
-- Deprecated
data MsgInitBaseDep = MsgInitBaseDep
  deriving ( Show, Read, Eq )

instance Binary MsgInitBaseDep where
  get =
    pure MsgInitBaseDep

  put MsgInitBaseDep =
    pure ()
$(makeSBP 'msgInitBaseDep ''MsgInitBaseDep)
$(makeJSON "_msgInitBaseDep_" ''MsgInitBaseDep)
$(makeLenses ''MsgInitBaseDep)

msgThreadState :: Word16
msgThreadState = 0x0017

-- | SBP class for message MSG_THREAD_STATE (0x0017).
--
-- The thread usage message from the device reports real-time operating system
-- (RTOS) thread usage statistics for the named thread. The reported percentage
-- values must be normalized.
data MsgThreadState = MsgThreadState
  { _msgThreadState_name     :: !Text
    -- ^ Thread name (NULL terminated)
  , _msgThreadState_cpu      :: !Word16
    -- ^ Percentage cpu use for this thread. Values range from 0 - 1000 and needs
    -- to be renormalized to 100
  , _msgThreadState_stack_free :: !Word32
    -- ^ Free stack space for this thread
  } deriving ( Show, Read, Eq )

instance Binary MsgThreadState where
  get = do
    _msgThreadState_name <- decodeUtf8 <$> getByteString 20
    _msgThreadState_cpu <- getWord16le
    _msgThreadState_stack_free <- getWord32le
    pure MsgThreadState {..}

  put MsgThreadState {..} = do
    putByteString $ encodeUtf8 _msgThreadState_name
    putWord16le _msgThreadState_cpu
    putWord32le _msgThreadState_stack_free

$(makeSBP 'msgThreadState ''MsgThreadState)
$(makeJSON "_msgThreadState_" ''MsgThreadState)
$(makeLenses ''MsgThreadState)

-- | UARTChannel.
--
-- Throughput, utilization, and error counts on the RX/TX buffers of this UART
-- channel. The reported percentage values must be normalized.
data UARTChannel = UARTChannel
  { _uARTChannel_tx_throughput :: !Float
    -- ^ UART transmit throughput
  , _uARTChannel_rx_throughput :: !Float
    -- ^ UART receive throughput
  , _uARTChannel_crc_error_count :: !Word16
    -- ^ UART CRC error count
  , _uARTChannel_io_error_count :: !Word16
    -- ^ UART IO error count
  , _uARTChannel_tx_buffer_level :: !Word8
    -- ^ UART transmit buffer percentage utilization (ranges from 0 to 255)
  , _uARTChannel_rx_buffer_level :: !Word8
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
    pure UARTChannel {..}

  put UARTChannel {..} = do
    putFloat32le _uARTChannel_tx_throughput
    putFloat32le _uARTChannel_rx_throughput
    putWord16le _uARTChannel_crc_error_count
    putWord16le _uARTChannel_io_error_count
    putWord8 _uARTChannel_tx_buffer_level
    putWord8 _uARTChannel_rx_buffer_level

$(makeJSON "_uARTChannel_" ''UARTChannel)
$(makeLenses ''UARTChannel)

-- | Period.
--
-- Statistics on the period of observations received from the base station. As
-- complete observation sets are received, their time of reception is compared
-- with the prior set''s time of reception. This measurement provides a proxy
-- for link quality as incomplete or missing sets will increase the period.
-- Long periods can cause momentary RTK solution outages.
data Period = Period
  { _period_avg   :: !Int32
    -- ^ Average period
  , _period_pmin  :: !Int32
    -- ^ Minimum period
  , _period_pmax  :: !Int32
    -- ^ Maximum period
  , _period_current :: !Int32
    -- ^ Smoothed estimate of the current period
  } deriving ( Show, Read, Eq )

instance Binary Period where
  get = do
    _period_avg <- fromIntegral <$> getWord32le
    _period_pmin <- fromIntegral <$> getWord32le
    _period_pmax <- fromIntegral <$> getWord32le
    _period_current <- fromIntegral <$> getWord32le
    pure Period {..}

  put Period {..} = do
    (putWord32le . fromIntegral) _period_avg
    (putWord32le . fromIntegral) _period_pmin
    (putWord32le . fromIntegral) _period_pmax
    (putWord32le . fromIntegral) _period_current

$(makeJSON "_period_" ''Period)
$(makeLenses ''Period)

-- | Latency.
--
-- Statistics on the latency of observations received from the base station. As
-- observation packets are received their GPS time is compared to the current
-- GPS time calculated locally by the receiver to give a precise measurement of
-- the end-to-end communication latency in the system.
data Latency = Latency
  { _latency_avg   :: !Int32
    -- ^ Average latency
  , _latency_lmin  :: !Int32
    -- ^ Minimum latency
  , _latency_lmax  :: !Int32
    -- ^ Maximum latency
  , _latency_current :: !Int32
    -- ^ Smoothed estimate of the current latency
  } deriving ( Show, Read, Eq )

instance Binary Latency where
  get = do
    _latency_avg <- fromIntegral <$> getWord32le
    _latency_lmin <- fromIntegral <$> getWord32le
    _latency_lmax <- fromIntegral <$> getWord32le
    _latency_current <- fromIntegral <$> getWord32le
    pure Latency {..}

  put Latency {..} = do
    (putWord32le . fromIntegral) _latency_avg
    (putWord32le . fromIntegral) _latency_lmin
    (putWord32le . fromIntegral) _latency_lmax
    (putWord32le . fromIntegral) _latency_current

$(makeJSON "_latency_" ''Latency)
$(makeLenses ''Latency)

msgUartState :: Word16
msgUartState = 0x001D

-- | SBP class for message MSG_UART_STATE (0x001D).
--
-- The UART message reports data latency and throughput of the UART channels
-- providing SBP I/O. On the default Piksi configuration, UARTs A and B are
-- used for telemetry radios, but can also be host access ports for embedded
-- hosts, or other interfaces in future. The reported percentage values must be
-- normalized. Observations latency and period can be used to assess the health
-- of the differential corrections link. Latency provides the timeliness of
-- received base observations while the period indicates their likelihood of
-- transmission.
data MsgUartState = MsgUartState
  { _msgUartState_uart_a   :: !UARTChannel
    -- ^ State of UART A
  , _msgUartState_uart_b   :: !UARTChannel
    -- ^ State of UART B
  , _msgUartState_uart_ftdi :: !UARTChannel
    -- ^ State of UART FTDI (USB logger)
  , _msgUartState_latency  :: !Latency
    -- ^ UART communication latency
  , _msgUartState_obs_period :: !Period
    -- ^ Observation receipt period
  } deriving ( Show, Read, Eq )

instance Binary MsgUartState where
  get = do
    _msgUartState_uart_a <- get
    _msgUartState_uart_b <- get
    _msgUartState_uart_ftdi <- get
    _msgUartState_latency <- get
    _msgUartState_obs_period <- get
    pure MsgUartState {..}

  put MsgUartState {..} = do
    put _msgUartState_uart_a
    put _msgUartState_uart_b
    put _msgUartState_uart_ftdi
    put _msgUartState_latency
    put _msgUartState_obs_period

$(makeSBP 'msgUartState ''MsgUartState)
$(makeJSON "_msgUartState_" ''MsgUartState)
$(makeLenses ''MsgUartState)

msgUartStateDepa :: Word16
msgUartStateDepa = 0x0018

-- | SBP class for message MSG_UART_STATE_DEPA (0x0018).
--
-- Deprecated
data MsgUartStateDepa = MsgUartStateDepa
  { _msgUartStateDepa_uart_a  :: !UARTChannel
    -- ^ State of UART A
  , _msgUartStateDepa_uart_b  :: !UARTChannel
    -- ^ State of UART B
  , _msgUartStateDepa_uart_ftdi :: !UARTChannel
    -- ^ State of UART FTDI (USB logger)
  , _msgUartStateDepa_latency :: !Latency
    -- ^ UART communication latency
  } deriving ( Show, Read, Eq )

instance Binary MsgUartStateDepa where
  get = do
    _msgUartStateDepa_uart_a <- get
    _msgUartStateDepa_uart_b <- get
    _msgUartStateDepa_uart_ftdi <- get
    _msgUartStateDepa_latency <- get
    pure MsgUartStateDepa {..}

  put MsgUartStateDepa {..} = do
    put _msgUartStateDepa_uart_a
    put _msgUartStateDepa_uart_b
    put _msgUartStateDepa_uart_ftdi
    put _msgUartStateDepa_latency

$(makeSBP 'msgUartStateDepa ''MsgUartStateDepa)
$(makeJSON "_msgUartStateDepa_" ''MsgUartStateDepa)
$(makeLenses ''MsgUartStateDepa)

msgIarState :: Word16
msgIarState = 0x0019

-- | SBP class for message MSG_IAR_STATE (0x0019).
--
-- This message reports the state of the Integer Ambiguity Resolution (IAR)
-- process, which resolves unknown integer ambiguities from double-differenced
-- carrier-phase measurements from satellite observations.
data MsgIarState = MsgIarState
  { _msgIarState_num_hyps :: !Word32
    -- ^ Number of integer ambiguity hypotheses remaining
  } deriving ( Show, Read, Eq )

instance Binary MsgIarState where
  get = do
    _msgIarState_num_hyps <- getWord32le
    pure MsgIarState {..}

  put MsgIarState {..} = do
    putWord32le _msgIarState_num_hyps

$(makeSBP 'msgIarState ''MsgIarState)
$(makeJSON "_msgIarState_" ''MsgIarState)
$(makeLenses ''MsgIarState)

msgMaskSatellite :: Word16
msgMaskSatellite = 0x002B

-- | SBP class for message MSG_MASK_SATELLITE (0x002B).
--
-- This message allows setting a mask to prevent a particular satellite from
-- being used in various Piksi subsystems.
data MsgMaskSatellite = MsgMaskSatellite
  { _msgMaskSatellite_mask :: !Word8
    -- ^ Mask of systems that should ignore this satellite.
  , _msgMaskSatellite_sid :: !GnssSignal
    -- ^ GNSS signal for which the mask is applied
  } deriving ( Show, Read, Eq )

instance Binary MsgMaskSatellite where
  get = do
    _msgMaskSatellite_mask <- getWord8
    _msgMaskSatellite_sid <- get
    pure MsgMaskSatellite {..}

  put MsgMaskSatellite {..} = do
    putWord8 _msgMaskSatellite_mask
    put _msgMaskSatellite_sid

$(makeSBP 'msgMaskSatellite ''MsgMaskSatellite)
$(makeJSON "_msgMaskSatellite_" ''MsgMaskSatellite)
$(makeLenses ''MsgMaskSatellite)

msgMaskSatelliteDep :: Word16
msgMaskSatelliteDep = 0x001B

-- | SBP class for message MSG_MASK_SATELLITE_DEP (0x001B).
--
-- Deprecated.
data MsgMaskSatelliteDep = MsgMaskSatelliteDep
  { _msgMaskSatelliteDep_mask :: !Word8
    -- ^ Mask of systems that should ignore this satellite.
  , _msgMaskSatelliteDep_sid :: !GnssSignalDep
    -- ^ GNSS signal for which the mask is applied
  } deriving ( Show, Read, Eq )

instance Binary MsgMaskSatelliteDep where
  get = do
    _msgMaskSatelliteDep_mask <- getWord8
    _msgMaskSatelliteDep_sid <- get
    pure MsgMaskSatelliteDep {..}

  put MsgMaskSatelliteDep {..} = do
    putWord8 _msgMaskSatelliteDep_mask
    put _msgMaskSatelliteDep_sid

$(makeSBP 'msgMaskSatelliteDep ''MsgMaskSatelliteDep)
$(makeJSON "_msgMaskSatelliteDep_" ''MsgMaskSatelliteDep)
$(makeLenses ''MsgMaskSatelliteDep)

msgDeviceMonitor :: Word16
msgDeviceMonitor = 0x00B5

-- | SBP class for message MSG_DEVICE_MONITOR (0x00B5).
--
-- This message contains temperature and voltage level measurements from the
-- processor's monitoring system and the RF frontend die temperature if
-- available.
data MsgDeviceMonitor = MsgDeviceMonitor
  { _msgDeviceMonitor_dev_vin       :: !Int16
    -- ^ Device V_in
  , _msgDeviceMonitor_cpu_vint      :: !Int16
    -- ^ Processor V_int
  , _msgDeviceMonitor_cpu_vaux      :: !Int16
    -- ^ Processor V_aux
  , _msgDeviceMonitor_cpu_temperature :: !Int16
    -- ^ Processor temperature
  , _msgDeviceMonitor_fe_temperature :: !Int16
    -- ^ Frontend temperature (if available)
  } deriving ( Show, Read, Eq )

instance Binary MsgDeviceMonitor where
  get = do
    _msgDeviceMonitor_dev_vin <- fromIntegral <$> getWord16le
    _msgDeviceMonitor_cpu_vint <- fromIntegral <$> getWord16le
    _msgDeviceMonitor_cpu_vaux <- fromIntegral <$> getWord16le
    _msgDeviceMonitor_cpu_temperature <- fromIntegral <$> getWord16le
    _msgDeviceMonitor_fe_temperature <- fromIntegral <$> getWord16le
    pure MsgDeviceMonitor {..}

  put MsgDeviceMonitor {..} = do
    (putWord16le . fromIntegral) _msgDeviceMonitor_dev_vin
    (putWord16le . fromIntegral) _msgDeviceMonitor_cpu_vint
    (putWord16le . fromIntegral) _msgDeviceMonitor_cpu_vaux
    (putWord16le . fromIntegral) _msgDeviceMonitor_cpu_temperature
    (putWord16le . fromIntegral) _msgDeviceMonitor_fe_temperature

$(makeSBP 'msgDeviceMonitor ''MsgDeviceMonitor)
$(makeJSON "_msgDeviceMonitor_" ''MsgDeviceMonitor)
$(makeLenses ''MsgDeviceMonitor)

msgCommandReq :: Word16
msgCommandReq = 0x00B8

-- | SBP class for message MSG_COMMAND_REQ (0x00B8).
--
-- Request the recipient to execute an command. Output will be sent in MSG_LOG
-- messages, and the exit code will be returned with MSG_COMMAND_RESP.
data MsgCommandReq = MsgCommandReq
  { _msgCommandReq_sequence :: !Word32
    -- ^ Sequence number
  , _msgCommandReq_command :: !Text
    -- ^ Command line to execute
  } deriving ( Show, Read, Eq )

instance Binary MsgCommandReq where
  get = do
    _msgCommandReq_sequence <- getWord32le
    _msgCommandReq_command <- decodeUtf8 . toStrict <$> getRemainingLazyByteString
    pure MsgCommandReq {..}

  put MsgCommandReq {..} = do
    putWord32le _msgCommandReq_sequence
    putByteString $ encodeUtf8 _msgCommandReq_command

$(makeSBP 'msgCommandReq ''MsgCommandReq)
$(makeJSON "_msgCommandReq_" ''MsgCommandReq)
$(makeLenses ''MsgCommandReq)

msgCommandResp :: Word16
msgCommandResp = 0x00B9

-- | SBP class for message MSG_COMMAND_RESP (0x00B9).
--
-- The response to MSG_COMMAND_REQ with the return code of the command.  A
-- return code of zero indicates success.
data MsgCommandResp = MsgCommandResp
  { _msgCommandResp_sequence :: !Word32
    -- ^ Sequence number
  , _msgCommandResp_code   :: !Int32
    -- ^ Exit code
  } deriving ( Show, Read, Eq )

instance Binary MsgCommandResp where
  get = do
    _msgCommandResp_sequence <- getWord32le
    _msgCommandResp_code <- fromIntegral <$> getWord32le
    pure MsgCommandResp {..}

  put MsgCommandResp {..} = do
    putWord32le _msgCommandResp_sequence
    (putWord32le . fromIntegral) _msgCommandResp_code

$(makeSBP 'msgCommandResp ''MsgCommandResp)
$(makeJSON "_msgCommandResp_" ''MsgCommandResp)
$(makeLenses ''MsgCommandResp)

msgCommandOutput :: Word16
msgCommandOutput = 0x00BC

-- | SBP class for message MSG_COMMAND_OUTPUT (0x00BC).
--
-- Returns the standard output and standard error of the command requested by
-- MSG_COMMAND_REQ. The sequence number can be used to filter for filtering the
-- correct command.
data MsgCommandOutput = MsgCommandOutput
  { _msgCommandOutput_sequence :: !Word32
    -- ^ Sequence number
  , _msgCommandOutput_line   :: !Text
    -- ^ Line of standard output or standard error
  } deriving ( Show, Read, Eq )

instance Binary MsgCommandOutput where
  get = do
    _msgCommandOutput_sequence <- getWord32le
    _msgCommandOutput_line <- decodeUtf8 . toStrict <$> getRemainingLazyByteString
    pure MsgCommandOutput {..}

  put MsgCommandOutput {..} = do
    putWord32le _msgCommandOutput_sequence
    putByteString $ encodeUtf8 _msgCommandOutput_line

$(makeSBP 'msgCommandOutput ''MsgCommandOutput)
$(makeJSON "_msgCommandOutput_" ''MsgCommandOutput)
$(makeLenses ''MsgCommandOutput)

msgNetworkStateReq :: Word16
msgNetworkStateReq = 0x00BA

-- | SBP class for message MSG_NETWORK_STATE_REQ (0x00BA).
--
-- Request state of Piksi network interfaces. Output will be sent in
-- MSG_NETWORK_STATE_RESP messages
data MsgNetworkStateReq = MsgNetworkStateReq
  deriving ( Show, Read, Eq )

instance Binary MsgNetworkStateReq where
  get =
    pure MsgNetworkStateReq

  put MsgNetworkStateReq =
    pure ()
$(makeSBP 'msgNetworkStateReq ''MsgNetworkStateReq)
$(makeJSON "_msgNetworkStateReq_" ''MsgNetworkStateReq)
$(makeLenses ''MsgNetworkStateReq)

msgNetworkStateResp :: Word16
msgNetworkStateResp = 0x00BB

-- | SBP class for message MSG_NETWORK_STATE_RESP (0x00BB).
--
-- The state of a network interface on the Piksi. Data is made to reflect
-- output of ifaddrs struct returned by getifaddrs in c.
data MsgNetworkStateResp = MsgNetworkStateResp
  { _msgNetworkStateResp_ipv4_address :: ![Word8]
    -- ^ IPv4 address (all zero when unavailable)
  , _msgNetworkStateResp_ipv4_mask_size :: !Word8
    -- ^ IPv4 netmask CIDR notation
  , _msgNetworkStateResp_ipv6_address :: ![Word8]
    -- ^ IPv6 address (all zero when unavailable)
  , _msgNetworkStateResp_ipv6_mask_size :: !Word8
    -- ^ IPv6 netmask CIDR notation
  , _msgNetworkStateResp_rx_bytes     :: !Word32
    -- ^ Number of Rx bytes
  , _msgNetworkStateResp_tx_bytes     :: !Word32
    -- ^ Number of Tx bytes
  , _msgNetworkStateResp_interface_name :: !Text
    -- ^ Interface Name
  , _msgNetworkStateResp_flags        :: !Word32
    -- ^ Interface flags from SIOCGIFFLAGS
  } deriving ( Show, Read, Eq )

instance Binary MsgNetworkStateResp where
  get = do
    _msgNetworkStateResp_ipv4_address <- replicateM 4 getWord8
    _msgNetworkStateResp_ipv4_mask_size <- getWord8
    _msgNetworkStateResp_ipv6_address <- replicateM 16 getWord8
    _msgNetworkStateResp_ipv6_mask_size <- getWord8
    _msgNetworkStateResp_rx_bytes <- getWord32le
    _msgNetworkStateResp_tx_bytes <- getWord32le
    _msgNetworkStateResp_interface_name <- decodeUtf8 <$> getByteString 16
    _msgNetworkStateResp_flags <- getWord32le
    pure MsgNetworkStateResp {..}

  put MsgNetworkStateResp {..} = do
    mapM_ putWord8 _msgNetworkStateResp_ipv4_address
    putWord8 _msgNetworkStateResp_ipv4_mask_size
    mapM_ putWord8 _msgNetworkStateResp_ipv6_address
    putWord8 _msgNetworkStateResp_ipv6_mask_size
    putWord32le _msgNetworkStateResp_rx_bytes
    putWord32le _msgNetworkStateResp_tx_bytes
    putByteString $ encodeUtf8 _msgNetworkStateResp_interface_name
    putWord32le _msgNetworkStateResp_flags

$(makeSBP 'msgNetworkStateResp ''MsgNetworkStateResp)
$(makeJSON "_msgNetworkStateResp_" ''MsgNetworkStateResp)
$(makeLenses ''MsgNetworkStateResp)

-- | NetworkUsage.
--
-- The bandwidth usage for each interface can be reported within this struct
-- and utilize multiple fields to fully specify the type of traffic that is
-- being tracked. As either the interval of collection or the collection time
-- may vary, both a timestamp and period field is provided, though may not
-- necessarily be populated with a value.
data NetworkUsage = NetworkUsage
  { _networkUsage_duration     :: !Word64
    -- ^ Duration over which the measurement was collected
  , _networkUsage_total_bytes  :: !Word64
    -- ^ Number of bytes handled in total within period
  , _networkUsage_rx_bytes     :: !Word32
    -- ^ Number of bytes transmitted within period
  , _networkUsage_tx_bytes     :: !Word32
    -- ^ Number of bytes received within period
  , _networkUsage_interface_name :: !Text
    -- ^ Interface Name
  } deriving ( Show, Read, Eq )

instance Binary NetworkUsage where
  get = do
    _networkUsage_duration <- getWord64le
    _networkUsage_total_bytes <- getWord64le
    _networkUsage_rx_bytes <- getWord32le
    _networkUsage_tx_bytes <- getWord32le
    _networkUsage_interface_name <- decodeUtf8 <$> getByteString 16
    pure NetworkUsage {..}

  put NetworkUsage {..} = do
    putWord64le _networkUsage_duration
    putWord64le _networkUsage_total_bytes
    putWord32le _networkUsage_rx_bytes
    putWord32le _networkUsage_tx_bytes
    putByteString $ encodeUtf8 _networkUsage_interface_name

$(makeJSON "_networkUsage_" ''NetworkUsage)
$(makeLenses ''NetworkUsage)

msgNetworkBandwidthUsage :: Word16
msgNetworkBandwidthUsage = 0x00BD

-- | SBP class for message MSG_NETWORK_BANDWIDTH_USAGE (0x00BD).
--
-- The bandwidth usage, a list of usage by interface.
data MsgNetworkBandwidthUsage = MsgNetworkBandwidthUsage
  { _msgNetworkBandwidthUsage_interfaces :: ![NetworkUsage]
    -- ^ Usage measurement array
  } deriving ( Show, Read, Eq )

instance Binary MsgNetworkBandwidthUsage where
  get = do
    _msgNetworkBandwidthUsage_interfaces <- whileM (not <$> isEmpty) get
    pure MsgNetworkBandwidthUsage {..}

  put MsgNetworkBandwidthUsage {..} = do
    mapM_ put _msgNetworkBandwidthUsage_interfaces

$(makeSBP 'msgNetworkBandwidthUsage ''MsgNetworkBandwidthUsage)
$(makeJSON "_msgNetworkBandwidthUsage_" ''MsgNetworkBandwidthUsage)
$(makeLenses ''MsgNetworkBandwidthUsage)

msgCellModemStatus :: Word16
msgCellModemStatus = 0x00BE

-- | SBP class for message MSG_CELL_MODEM_STATUS (0x00BE).
--
-- If a cell modem is present on a piksi device, this message will be send
-- periodically to update the host on the status of the modem and its various
-- parameters.
data MsgCellModemStatus = MsgCellModemStatus
  { _msgCellModemStatus_signal_strength :: !Int8
    -- ^ Received cell signal strength in dBm, zero translates to unknown
  , _msgCellModemStatus_signal_error_rate :: !Float
    -- ^ BER as reported by the modem, zero translates to unknown
  , _msgCellModemStatus_reserved        :: ![Word8]
    -- ^ Unspecified data TBD for this schema
  } deriving ( Show, Read, Eq )

instance Binary MsgCellModemStatus where
  get = do
    _msgCellModemStatus_signal_strength <- fromIntegral <$> getWord8
    _msgCellModemStatus_signal_error_rate <- getFloat32le
    _msgCellModemStatus_reserved <- whileM (not <$> isEmpty) getWord8
    pure MsgCellModemStatus {..}

  put MsgCellModemStatus {..} = do
    (putWord8 . fromIntegral) _msgCellModemStatus_signal_strength
    putFloat32le _msgCellModemStatus_signal_error_rate
    mapM_ putWord8 _msgCellModemStatus_reserved

$(makeSBP 'msgCellModemStatus ''MsgCellModemStatus)
$(makeJSON "_msgCellModemStatus_" ''MsgCellModemStatus)
$(makeLenses ''MsgCellModemStatus)

msgSpecanDep :: Word16
msgSpecanDep = 0x0050

-- | SBP class for message MSG_SPECAN_DEP (0x0050).
--
-- Deprecated.
data MsgSpecanDep = MsgSpecanDep
  { _msgSpecanDep_channel_tag   :: !Word16
    -- ^ Channel ID
  , _msgSpecanDep_t             :: !GpsTimeDep
    -- ^ Receiver time of this observation
  , _msgSpecanDep_freq_ref      :: !Float
    -- ^ Reference frequency of this packet
  , _msgSpecanDep_freq_step     :: !Float
    -- ^ Frequency step of points in this packet
  , _msgSpecanDep_amplitude_ref :: !Float
    -- ^ Reference amplitude of this packet
  , _msgSpecanDep_amplitude_unit :: !Float
    -- ^ Amplitude unit value of points in this packet
  , _msgSpecanDep_amplitude_value :: ![Word8]
    -- ^ Amplitude values (in the above units) of points in this packet
  } deriving ( Show, Read, Eq )

instance Binary MsgSpecanDep where
  get = do
    _msgSpecanDep_channel_tag <- getWord16le
    _msgSpecanDep_t <- get
    _msgSpecanDep_freq_ref <- getFloat32le
    _msgSpecanDep_freq_step <- getFloat32le
    _msgSpecanDep_amplitude_ref <- getFloat32le
    _msgSpecanDep_amplitude_unit <- getFloat32le
    _msgSpecanDep_amplitude_value <- whileM (not <$> isEmpty) getWord8
    pure MsgSpecanDep {..}

  put MsgSpecanDep {..} = do
    putWord16le _msgSpecanDep_channel_tag
    put _msgSpecanDep_t
    putFloat32le _msgSpecanDep_freq_ref
    putFloat32le _msgSpecanDep_freq_step
    putFloat32le _msgSpecanDep_amplitude_ref
    putFloat32le _msgSpecanDep_amplitude_unit
    mapM_ putWord8 _msgSpecanDep_amplitude_value

$(makeSBP 'msgSpecanDep ''MsgSpecanDep)
$(makeJSON "_msgSpecanDep_" ''MsgSpecanDep)
$(makeLenses ''MsgSpecanDep)

msgSpecan :: Word16
msgSpecan = 0x0051

-- | SBP class for message MSG_SPECAN (0x0051).
--
-- Spectrum analyzer packet.
data MsgSpecan = MsgSpecan
  { _msgSpecan_channel_tag   :: !Word16
    -- ^ Channel ID
  , _msgSpecan_t             :: !GpsTime
    -- ^ Receiver time of this observation
  , _msgSpecan_freq_ref      :: !Float
    -- ^ Reference frequency of this packet
  , _msgSpecan_freq_step     :: !Float
    -- ^ Frequency step of points in this packet
  , _msgSpecan_amplitude_ref :: !Float
    -- ^ Reference amplitude of this packet
  , _msgSpecan_amplitude_unit :: !Float
    -- ^ Amplitude unit value of points in this packet
  , _msgSpecan_amplitude_value :: ![Word8]
    -- ^ Amplitude values (in the above units) of points in this packet
  } deriving ( Show, Read, Eq )

instance Binary MsgSpecan where
  get = do
    _msgSpecan_channel_tag <- getWord16le
    _msgSpecan_t <- get
    _msgSpecan_freq_ref <- getFloat32le
    _msgSpecan_freq_step <- getFloat32le
    _msgSpecan_amplitude_ref <- getFloat32le
    _msgSpecan_amplitude_unit <- getFloat32le
    _msgSpecan_amplitude_value <- whileM (not <$> isEmpty) getWord8
    pure MsgSpecan {..}

  put MsgSpecan {..} = do
    putWord16le _msgSpecan_channel_tag
    put _msgSpecan_t
    putFloat32le _msgSpecan_freq_ref
    putFloat32le _msgSpecan_freq_step
    putFloat32le _msgSpecan_amplitude_ref
    putFloat32le _msgSpecan_amplitude_unit
    mapM_ putWord8 _msgSpecan_amplitude_value

$(makeSBP 'msgSpecan ''MsgSpecan)
$(makeJSON "_msgSpecan_" ''MsgSpecan)
$(makeLenses ''MsgSpecan)

msgFrontEndGain :: Word16
msgFrontEndGain = 0x00BF

-- | SBP class for message MSG_FRONT_END_GAIN (0x00BF).
--
-- This message describes the gain of each channel in the receiver frontend.
-- Each  gain is encoded as a non-dimensional percentage relative to the
-- maximum range   possible for the gain stage of the frontend. By convention,
-- each gain array  has 8 entries and the index of the array corresponding to
-- the index of the rf channel  in the frontend. A gain of 127 percent encodes
-- that rf channel is not present in the hardware. A negative value implies an
-- error for the particular gain stage as reported by the frontend.
data MsgFrontEndGain = MsgFrontEndGain
  { _msgFrontEndGain_rf_gain :: ![Int8]
    -- ^ RF gain for each frontend channel
  , _msgFrontEndGain_if_gain :: ![Int8]
    -- ^ Intermediate frequency gain for each frontend channel
  } deriving ( Show, Read, Eq )

instance Binary MsgFrontEndGain where
  get = do
    _msgFrontEndGain_rf_gain <- replicateM 8 fromIntegral <$> getWord8
    _msgFrontEndGain_if_gain <- replicateM 8 fromIntegral <$> getWord8
    pure MsgFrontEndGain {..}

  put MsgFrontEndGain {..} = do
    mapM_ (putWord8 . fromIntegral) _msgFrontEndGain_rf_gain
    mapM_ (putWord8 . fromIntegral) _msgFrontEndGain_if_gain

$(makeSBP 'msgFrontEndGain ''MsgFrontEndGain)
$(makeJSON "_msgFrontEndGain_" ''MsgFrontEndGain)
$(makeLenses ''MsgFrontEndGain)
