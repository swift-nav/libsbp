{-# OPTIONS_GHC -fno-warn-unused-imports #-}
{-# LANGUAGE NoImplicitPrelude           #-}
{-# LANGUAGE TemplateHaskell             #-}
{-# LANGUAGE RecordWildCards             #-}

-- |
-- Module:      SwiftNav.SBP.System
-- Copyright:   Copyright (C) 2015-2018 Swift Navigation, Inc.
-- License:     LGPL-3
-- Maintainer:  Swift Navigation <dev@swiftnav.com>
-- Stability:   experimental
-- Portability: portable
--
-- \<Standardized system messages from Swift Navigation devices.\>

module SwiftNav.SBP.System
  ( module SwiftNav.SBP.System
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

{-# ANN module ("HLint: ignore Use camelCase"::String) #-}
{-# ANN module ("HLint: ignore Redundant do"::String) #-}
{-# ANN module ("HLint: ignore Use newtype instead of data"::String) #-}


msgStartup :: Word16
msgStartup = 0xFF00

-- | SBP class for message MSG_STARTUP (0xFF00).
--
-- The system start-up message is sent once on system start-up. It notifies the
-- host or other attached devices that the system has started and is now ready
-- to respond to commands or configuration requests.
data MsgStartup = MsgStartup
  { _msgStartup_cause      :: !Word8
    -- ^ Cause of startup
  , _msgStartup_startup_type :: !Word8
    -- ^ Startup type
  , _msgStartup_reserved   :: !Word16
    -- ^ Reserved
  } deriving ( Show, Read, Eq )

instance Binary MsgStartup where
  get = do
    _msgStartup_cause <- getWord8
    _msgStartup_startup_type <- getWord8
    _msgStartup_reserved <- getWord16le
    pure MsgStartup {..}

  put MsgStartup {..} = do
    putWord8 _msgStartup_cause
    putWord8 _msgStartup_startup_type
    putWord16le _msgStartup_reserved

$(makeSBP 'msgStartup ''MsgStartup)
$(makeJSON "_msgStartup_" ''MsgStartup)
$(makeLenses ''MsgStartup)

msgDgnssStatus :: Word16
msgDgnssStatus = 0xFF02

-- | SBP class for message MSG_DGNSS_STATUS (0xFF02).
--
-- This message provides information about the receipt of Differential
-- corrections.  It is expected to be sent with each receipt of a complete
-- corrections packet.
data MsgDgnssStatus = MsgDgnssStatus
  { _msgDgnssStatus_flags     :: !Word8
    -- ^ Status flags
  , _msgDgnssStatus_latency   :: !Word16
    -- ^ Latency of observation receipt
  , _msgDgnssStatus_num_signals :: !Word8
    -- ^ Number of signals from base station
  , _msgDgnssStatus_source    :: !Text
    -- ^ Corrections source string
  } deriving ( Show, Read, Eq )

instance Binary MsgDgnssStatus where
  get = do
    _msgDgnssStatus_flags <- getWord8
    _msgDgnssStatus_latency <- getWord16le
    _msgDgnssStatus_num_signals <- getWord8
    _msgDgnssStatus_source <- decodeUtf8 . toStrict <$> getRemainingLazyByteString
    pure MsgDgnssStatus {..}

  put MsgDgnssStatus {..} = do
    putWord8 _msgDgnssStatus_flags
    putWord16le _msgDgnssStatus_latency
    putWord8 _msgDgnssStatus_num_signals
    putByteString $ encodeUtf8 _msgDgnssStatus_source

$(makeSBP 'msgDgnssStatus ''MsgDgnssStatus)
$(makeJSON "_msgDgnssStatus_" ''MsgDgnssStatus)
$(makeLenses ''MsgDgnssStatus)

msgHeartbeat :: Word16
msgHeartbeat = 0xFFFF

-- | SBP class for message MSG_HEARTBEAT (0xFFFF).
--
-- The heartbeat message is sent periodically to inform the host or other
-- attached devices that the system is running. It is used to monitor system
-- malfunctions. It also contains status flags that indicate to the host the
-- status of the system and whether it is operating correctly. Currently, the
-- expected heartbeat interval is 1 sec.  The system error flag is used to
-- indicate that an error has occurred in the system. To determine the source
-- of the error, the remaining error flags should be inspected.
data MsgHeartbeat = MsgHeartbeat
  { _msgHeartbeat_flags :: !Word32
    -- ^ Status flags
  } deriving ( Show, Read, Eq )

instance Binary MsgHeartbeat where
  get = do
    _msgHeartbeat_flags <- getWord32le
    pure MsgHeartbeat {..}

  put MsgHeartbeat {..} = do
    putWord32le _msgHeartbeat_flags

$(makeSBP 'msgHeartbeat ''MsgHeartbeat)
$(makeJSON "_msgHeartbeat_" ''MsgHeartbeat)
$(makeLenses ''MsgHeartbeat)

msgInsStatus :: Word16
msgInsStatus = 0xFF03

-- | SBP class for message MSG_INS_STATUS (0xFF03).
--
-- The INS status message describes the state of the operation and
-- initialization of the inertial navigation system.
data MsgInsStatus = MsgInsStatus
  { _msgInsStatus_flags :: !Word32
    -- ^ Status flags
  } deriving ( Show, Read, Eq )

instance Binary MsgInsStatus where
  get = do
    _msgInsStatus_flags <- getWord32le
    pure MsgInsStatus {..}

  put MsgInsStatus {..} = do
    putWord32le _msgInsStatus_flags

$(makeSBP 'msgInsStatus ''MsgInsStatus)
$(makeJSON "_msgInsStatus_" ''MsgInsStatus)
$(makeLenses ''MsgInsStatus)

msgCsacTelemetry :: Word16
msgCsacTelemetry = 0xFF04

-- | SBP class for message MSG_CSAC_TELEMETRY (0xFF04).
--
-- The CSAC telemetry message has an implementation defined telemetry string
-- from a device. It is not produced or available on general Swift Products. It
-- is intended to be a low rate message for status purposes.
data MsgCsacTelemetry = MsgCsacTelemetry
  { _msgCsacTelemetry_id      :: !Word8
    -- ^ Index representing the type of telemetry in use.  It is implemention
    -- defined.
  , _msgCsacTelemetry_telemetry :: !Text
    -- ^ Comma separated list of values as defined by the index
  } deriving ( Show, Read, Eq )

instance Binary MsgCsacTelemetry where
  get = do
    _msgCsacTelemetry_id <- getWord8
    _msgCsacTelemetry_telemetry <- decodeUtf8 . toStrict <$> getRemainingLazyByteString
    pure MsgCsacTelemetry {..}

  put MsgCsacTelemetry {..} = do
    putWord8 _msgCsacTelemetry_id
    putByteString $ encodeUtf8 _msgCsacTelemetry_telemetry

$(makeSBP 'msgCsacTelemetry ''MsgCsacTelemetry)
$(makeJSON "_msgCsacTelemetry_" ''MsgCsacTelemetry)
$(makeLenses ''MsgCsacTelemetry)

msgCsacTelemetryLabels :: Word16
msgCsacTelemetryLabels = 0xFF05

-- | SBP class for message MSG_CSAC_TELEMETRY_LABELS (0xFF05).
--
-- The CSAC telemetry message provides labels for each member of the string
-- produced by MSG_CSAC_TELEMETRY. It should be provided by a device at a lower
-- rate than the MSG_CSAC_TELEMETRY.
data MsgCsacTelemetryLabels = MsgCsacTelemetryLabels
  { _msgCsacTelemetryLabels_id             :: !Word8
    -- ^ Index representing the type of telemetry in use.  It is implemention
    -- defined.
  , _msgCsacTelemetryLabels_telemetry_labels :: !Text
    -- ^ Comma separated list of telemetry field values
  } deriving ( Show, Read, Eq )

instance Binary MsgCsacTelemetryLabels where
  get = do
    _msgCsacTelemetryLabels_id <- getWord8
    _msgCsacTelemetryLabels_telemetry_labels <- decodeUtf8 . toStrict <$> getRemainingLazyByteString
    pure MsgCsacTelemetryLabels {..}

  put MsgCsacTelemetryLabels {..} = do
    putWord8 _msgCsacTelemetryLabels_id
    putByteString $ encodeUtf8 _msgCsacTelemetryLabels_telemetry_labels

$(makeSBP 'msgCsacTelemetryLabels ''MsgCsacTelemetryLabels)
$(makeJSON "_msgCsacTelemetryLabels_" ''MsgCsacTelemetryLabels)
$(makeLenses ''MsgCsacTelemetryLabels)

msgInsUpdates :: Word16
msgInsUpdates = 0xFF06

-- | SBP class for message MSG_INS_UPDATES (0xFF06).
--
-- The INS update status message contains informations about executed and
-- rejected INS updates. This message is expected to be extended in the future
-- as new types of measurements are being added.
data MsgInsUpdates = MsgInsUpdates
  { _msgInsUpdates_tow      :: !Word32
    -- ^ GPS Time of Week
  , _msgInsUpdates_gnsspos  :: !Word8
    -- ^ GNSS position update status flags
  , _msgInsUpdates_gnssvel  :: !Word8
    -- ^ GNSS velocity update status flags
  , _msgInsUpdates_wheelticks :: !Word8
    -- ^ Wheelticks update status flags
  , _msgInsUpdates_speed    :: !Word8
    -- ^ Wheelticks update status flags
  , _msgInsUpdates_nhc      :: !Word8
    -- ^ NHC update status flags
  , _msgInsUpdates_zerovel  :: !Word8
    -- ^ Zero velocity update status flags
  } deriving ( Show, Read, Eq )

instance Binary MsgInsUpdates where
  get = do
    _msgInsUpdates_tow <- getWord32le
    _msgInsUpdates_gnsspos <- getWord8
    _msgInsUpdates_gnssvel <- getWord8
    _msgInsUpdates_wheelticks <- getWord8
    _msgInsUpdates_speed <- getWord8
    _msgInsUpdates_nhc <- getWord8
    _msgInsUpdates_zerovel <- getWord8
    pure MsgInsUpdates {..}

  put MsgInsUpdates {..} = do
    putWord32le _msgInsUpdates_tow
    putWord8 _msgInsUpdates_gnsspos
    putWord8 _msgInsUpdates_gnssvel
    putWord8 _msgInsUpdates_wheelticks
    putWord8 _msgInsUpdates_speed
    putWord8 _msgInsUpdates_nhc
    putWord8 _msgInsUpdates_zerovel

$(makeSBP 'msgInsUpdates ''MsgInsUpdates)
$(makeJSON "_msgInsUpdates_" ''MsgInsUpdates)
$(makeLenses ''MsgInsUpdates)

msgGnssTimeOffset :: Word16
msgGnssTimeOffset = 0xFF07

-- | SBP class for message MSG_GNSS_TIME_OFFSET (0xFF07).
--
-- The GNSS time offset message contains the information that is needed to
-- translate messages tagged with a local timestamp (e.g. IMU or wheeltick
-- messages) to GNSS time for the sender producing this message.
data MsgGnssTimeOffset = MsgGnssTimeOffset
  { _msgGnssTimeOffset_weeks      :: !Int16
    -- ^ Weeks portion of the time offset
  , _msgGnssTimeOffset_milliseconds :: !Int32
    -- ^ Milliseconds portion of the time offset
  , _msgGnssTimeOffset_microseconds :: !Int16
    -- ^ Microseconds portion of the time offset
  , _msgGnssTimeOffset_flags      :: !Word8
    -- ^ Status flags (reserved)
  } deriving ( Show, Read, Eq )

instance Binary MsgGnssTimeOffset where
  get = do
    _msgGnssTimeOffset_weeks <- (fromIntegral <$> getWord16le)
    _msgGnssTimeOffset_milliseconds <- (fromIntegral <$> getWord32le)
    _msgGnssTimeOffset_microseconds <- (fromIntegral <$> getWord16le)
    _msgGnssTimeOffset_flags <- getWord8
    pure MsgGnssTimeOffset {..}

  put MsgGnssTimeOffset {..} = do
    (putWord16le . fromIntegral) _msgGnssTimeOffset_weeks
    (putWord32le . fromIntegral) _msgGnssTimeOffset_milliseconds
    (putWord16le . fromIntegral) _msgGnssTimeOffset_microseconds
    putWord8 _msgGnssTimeOffset_flags

$(makeSBP 'msgGnssTimeOffset ''MsgGnssTimeOffset)
$(makeJSON "_msgGnssTimeOffset_" ''MsgGnssTimeOffset)
$(makeLenses ''MsgGnssTimeOffset)
