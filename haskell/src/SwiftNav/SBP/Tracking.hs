{-# OPTIONS_GHC -fno-warn-unused-imports #-}
{-# LANGUAGE NoImplicitPrelude           #-}
{-# LANGUAGE TemplateHaskell             #-}
{-# LANGUAGE RecordWildCards             #-}

-- |
-- Module:      SwiftNav.SBP.Tracking
-- Copyright:   Copyright (C) 2015-2018 Swift Navigation, Inc.
-- License:     LGPL-3
-- Maintainer:  Swift Navigation <dev@swiftnav.com>
-- Stability:   experimental
-- Portability: portable
--
-- \<Satellite code and carrier-phase tracking messages from the device. \>

module SwiftNav.SBP.Tracking
  ( module SwiftNav.SBP.Tracking
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


msgTrackingStateDetailedDepA :: Word16
msgTrackingStateDetailedDepA = 0x0021

-- | SBP class for message MSG_TRACKING_STATE_DETAILED_DEP_A (0x0021).
--
-- The tracking message returns a set tracking channel parameters for a single
-- tracking channel useful for debugging issues.
data MsgTrackingStateDetailedDepA = MsgTrackingStateDetailedDepA
  { _msgTrackingStateDetailedDepA_recv_time  :: !Word64
    -- ^ Receiver clock time.
  , _msgTrackingStateDetailedDepA_tot        :: !GpsTime
    -- ^ Time of transmission of signal from satellite. TOW only valid when TOW
    -- status is decoded or propagated. WN only valid when week number valid
    -- flag is set.
  , _msgTrackingStateDetailedDepA_P          :: !Word32
    -- ^ Pseudorange observation. Valid only when pseudorange valid flag is set.
  , _msgTrackingStateDetailedDepA_P_std      :: !Word16
    -- ^ Pseudorange observation standard deviation. Valid only when pseudorange
    -- valid flag is set.
  , _msgTrackingStateDetailedDepA_L          :: !CarrierPhase
    -- ^ Carrier phase observation with typical sign convention. Valid only when
    -- PLL pessimistic lock is achieved.
  , _msgTrackingStateDetailedDepA_cn0        :: !Word8
    -- ^ Carrier-to-Noise density
  , _msgTrackingStateDetailedDepA_lock       :: !Word16
    -- ^ Lock time. It is encoded according to DF402 from the RTCM 10403.2
    -- Amendment 2 specification. Valid values range from 0 to 15.
  , _msgTrackingStateDetailedDepA_sid        :: !GnssSignal
    -- ^ GNSS signal identifier.
  , _msgTrackingStateDetailedDepA_doppler    :: !Int32
    -- ^ Carrier Doppler frequency.
  , _msgTrackingStateDetailedDepA_doppler_std :: !Word16
    -- ^ Carrier Doppler frequency standard deviation.
  , _msgTrackingStateDetailedDepA_uptime     :: !Word32
    -- ^ Number of seconds of continuous tracking. Specifies how much time signal
    -- is in continuous track.
  , _msgTrackingStateDetailedDepA_clock_offset :: !Int16
    -- ^ TCXO clock offset. Valid only when valid clock valid flag is set.
  , _msgTrackingStateDetailedDepA_clock_drift :: !Int16
    -- ^ TCXO clock drift. Valid only when valid clock valid flag is set.
  , _msgTrackingStateDetailedDepA_corr_spacing :: !Word16
    -- ^ Early-Prompt (EP) and Prompt-Late (PL) correlators spacing.
  , _msgTrackingStateDetailedDepA_acceleration :: !Int8
    -- ^ Acceleration. Valid only when acceleration valid flag is set.
  , _msgTrackingStateDetailedDepA_sync_flags :: !Word8
    -- ^ Synchronization status flags.
  , _msgTrackingStateDetailedDepA_tow_flags  :: !Word8
    -- ^ TOW status flags.
  , _msgTrackingStateDetailedDepA_track_flags :: !Word8
    -- ^ Tracking loop status flags.
  , _msgTrackingStateDetailedDepA_nav_flags  :: !Word8
    -- ^ Navigation data status flags.
  , _msgTrackingStateDetailedDepA_pset_flags :: !Word8
    -- ^ Parameters sets flags.
  , _msgTrackingStateDetailedDepA_misc_flags :: !Word8
    -- ^ Miscellaneous flags.
  } deriving ( Show, Read, Eq )

instance Binary MsgTrackingStateDetailedDepA where
  get = do
    _msgTrackingStateDetailedDepA_recv_time <- getWord64le
    _msgTrackingStateDetailedDepA_tot <- get
    _msgTrackingStateDetailedDepA_P <- getWord32le
    _msgTrackingStateDetailedDepA_P_std <- getWord16le
    _msgTrackingStateDetailedDepA_L <- get
    _msgTrackingStateDetailedDepA_cn0 <- getWord8
    _msgTrackingStateDetailedDepA_lock <- getWord16le
    _msgTrackingStateDetailedDepA_sid <- get
    _msgTrackingStateDetailedDepA_doppler <- fromIntegral <$> getWord32le
    _msgTrackingStateDetailedDepA_doppler_std <- getWord16le
    _msgTrackingStateDetailedDepA_uptime <- getWord32le
    _msgTrackingStateDetailedDepA_clock_offset <- fromIntegral <$> getWord16le
    _msgTrackingStateDetailedDepA_clock_drift <- fromIntegral <$> getWord16le
    _msgTrackingStateDetailedDepA_corr_spacing <- getWord16le
    _msgTrackingStateDetailedDepA_acceleration <- fromIntegral <$> getWord8
    _msgTrackingStateDetailedDepA_sync_flags <- getWord8
    _msgTrackingStateDetailedDepA_tow_flags <- getWord8
    _msgTrackingStateDetailedDepA_track_flags <- getWord8
    _msgTrackingStateDetailedDepA_nav_flags <- getWord8
    _msgTrackingStateDetailedDepA_pset_flags <- getWord8
    _msgTrackingStateDetailedDepA_misc_flags <- getWord8
    pure MsgTrackingStateDetailedDepA {..}

  put MsgTrackingStateDetailedDepA {..} = do
    putWord64le _msgTrackingStateDetailedDepA_recv_time
    put _msgTrackingStateDetailedDepA_tot
    putWord32le _msgTrackingStateDetailedDepA_P
    putWord16le _msgTrackingStateDetailedDepA_P_std
    put _msgTrackingStateDetailedDepA_L
    putWord8 _msgTrackingStateDetailedDepA_cn0
    putWord16le _msgTrackingStateDetailedDepA_lock
    put _msgTrackingStateDetailedDepA_sid
    (putWord32le . fromIntegral) _msgTrackingStateDetailedDepA_doppler
    putWord16le _msgTrackingStateDetailedDepA_doppler_std
    putWord32le _msgTrackingStateDetailedDepA_uptime
    (putWord16le . fromIntegral) _msgTrackingStateDetailedDepA_clock_offset
    (putWord16le . fromIntegral) _msgTrackingStateDetailedDepA_clock_drift
    putWord16le _msgTrackingStateDetailedDepA_corr_spacing
    (putWord8 . fromIntegral) _msgTrackingStateDetailedDepA_acceleration
    putWord8 _msgTrackingStateDetailedDepA_sync_flags
    putWord8 _msgTrackingStateDetailedDepA_tow_flags
    putWord8 _msgTrackingStateDetailedDepA_track_flags
    putWord8 _msgTrackingStateDetailedDepA_nav_flags
    putWord8 _msgTrackingStateDetailedDepA_pset_flags
    putWord8 _msgTrackingStateDetailedDepA_misc_flags

$(makeSBP 'msgTrackingStateDetailedDepA ''MsgTrackingStateDetailedDepA)
$(makeJSON "_msgTrackingStateDetailedDepA_" ''MsgTrackingStateDetailedDepA)
$(makeLenses ''MsgTrackingStateDetailedDepA)

msgTrackingStateDetailedDep :: Word16
msgTrackingStateDetailedDep = 0x0011

-- | SBP class for message MSG_TRACKING_STATE_DETAILED_DEP (0x0011).
--
-- Deprecated.
data MsgTrackingStateDetailedDep = MsgTrackingStateDetailedDep
  { _msgTrackingStateDetailedDep_recv_time  :: !Word64
    -- ^ Receiver clock time.
  , _msgTrackingStateDetailedDep_tot        :: !GpsTimeDep
    -- ^ Time of transmission of signal from satellite. TOW only valid when TOW
    -- status is decoded or propagated. WN only valid when week number valid
    -- flag is set.
  , _msgTrackingStateDetailedDep_P          :: !Word32
    -- ^ Pseudorange observation. Valid only when pseudorange valid flag is set.
  , _msgTrackingStateDetailedDep_P_std      :: !Word16
    -- ^ Pseudorange observation standard deviation. Valid only when pseudorange
    -- valid flag is set.
  , _msgTrackingStateDetailedDep_L          :: !CarrierPhase
    -- ^ Carrier phase observation with typical sign convention. Valid only when
    -- PLL pessimistic lock is achieved.
  , _msgTrackingStateDetailedDep_cn0        :: !Word8
    -- ^ Carrier-to-Noise density
  , _msgTrackingStateDetailedDep_lock       :: !Word16
    -- ^ Lock time. It is encoded according to DF402 from the RTCM 10403.2
    -- Amendment 2 specification. Valid values range from 0 to 15.
  , _msgTrackingStateDetailedDep_sid        :: !GnssSignalDep
    -- ^ GNSS signal identifier.
  , _msgTrackingStateDetailedDep_doppler    :: !Int32
    -- ^ Carrier Doppler frequency.
  , _msgTrackingStateDetailedDep_doppler_std :: !Word16
    -- ^ Carrier Doppler frequency standard deviation.
  , _msgTrackingStateDetailedDep_uptime     :: !Word32
    -- ^ Number of seconds of continuous tracking. Specifies how much time signal
    -- is in continuous track.
  , _msgTrackingStateDetailedDep_clock_offset :: !Int16
    -- ^ TCXO clock offset. Valid only when valid clock valid flag is set.
  , _msgTrackingStateDetailedDep_clock_drift :: !Int16
    -- ^ TCXO clock drift. Valid only when valid clock valid flag is set.
  , _msgTrackingStateDetailedDep_corr_spacing :: !Word16
    -- ^ Early-Prompt (EP) and Prompt-Late (PL) correlators spacing.
  , _msgTrackingStateDetailedDep_acceleration :: !Int8
    -- ^ Acceleration. Valid only when acceleration valid flag is set.
  , _msgTrackingStateDetailedDep_sync_flags :: !Word8
    -- ^ Synchronization status flags.
  , _msgTrackingStateDetailedDep_tow_flags  :: !Word8
    -- ^ TOW status flags.
  , _msgTrackingStateDetailedDep_track_flags :: !Word8
    -- ^ Tracking loop status flags.
  , _msgTrackingStateDetailedDep_nav_flags  :: !Word8
    -- ^ Navigation data status flags.
  , _msgTrackingStateDetailedDep_pset_flags :: !Word8
    -- ^ Parameters sets flags.
  , _msgTrackingStateDetailedDep_misc_flags :: !Word8
    -- ^ Miscellaneous flags.
  } deriving ( Show, Read, Eq )

instance Binary MsgTrackingStateDetailedDep where
  get = do
    _msgTrackingStateDetailedDep_recv_time <- getWord64le
    _msgTrackingStateDetailedDep_tot <- get
    _msgTrackingStateDetailedDep_P <- getWord32le
    _msgTrackingStateDetailedDep_P_std <- getWord16le
    _msgTrackingStateDetailedDep_L <- get
    _msgTrackingStateDetailedDep_cn0 <- getWord8
    _msgTrackingStateDetailedDep_lock <- getWord16le
    _msgTrackingStateDetailedDep_sid <- get
    _msgTrackingStateDetailedDep_doppler <- fromIntegral <$> getWord32le
    _msgTrackingStateDetailedDep_doppler_std <- getWord16le
    _msgTrackingStateDetailedDep_uptime <- getWord32le
    _msgTrackingStateDetailedDep_clock_offset <- fromIntegral <$> getWord16le
    _msgTrackingStateDetailedDep_clock_drift <- fromIntegral <$> getWord16le
    _msgTrackingStateDetailedDep_corr_spacing <- getWord16le
    _msgTrackingStateDetailedDep_acceleration <- fromIntegral <$> getWord8
    _msgTrackingStateDetailedDep_sync_flags <- getWord8
    _msgTrackingStateDetailedDep_tow_flags <- getWord8
    _msgTrackingStateDetailedDep_track_flags <- getWord8
    _msgTrackingStateDetailedDep_nav_flags <- getWord8
    _msgTrackingStateDetailedDep_pset_flags <- getWord8
    _msgTrackingStateDetailedDep_misc_flags <- getWord8
    pure MsgTrackingStateDetailedDep {..}

  put MsgTrackingStateDetailedDep {..} = do
    putWord64le _msgTrackingStateDetailedDep_recv_time
    put _msgTrackingStateDetailedDep_tot
    putWord32le _msgTrackingStateDetailedDep_P
    putWord16le _msgTrackingStateDetailedDep_P_std
    put _msgTrackingStateDetailedDep_L
    putWord8 _msgTrackingStateDetailedDep_cn0
    putWord16le _msgTrackingStateDetailedDep_lock
    put _msgTrackingStateDetailedDep_sid
    (putWord32le . fromIntegral) _msgTrackingStateDetailedDep_doppler
    putWord16le _msgTrackingStateDetailedDep_doppler_std
    putWord32le _msgTrackingStateDetailedDep_uptime
    (putWord16le . fromIntegral) _msgTrackingStateDetailedDep_clock_offset
    (putWord16le . fromIntegral) _msgTrackingStateDetailedDep_clock_drift
    putWord16le _msgTrackingStateDetailedDep_corr_spacing
    (putWord8 . fromIntegral) _msgTrackingStateDetailedDep_acceleration
    putWord8 _msgTrackingStateDetailedDep_sync_flags
    putWord8 _msgTrackingStateDetailedDep_tow_flags
    putWord8 _msgTrackingStateDetailedDep_track_flags
    putWord8 _msgTrackingStateDetailedDep_nav_flags
    putWord8 _msgTrackingStateDetailedDep_pset_flags
    putWord8 _msgTrackingStateDetailedDep_misc_flags

$(makeSBP 'msgTrackingStateDetailedDep ''MsgTrackingStateDetailedDep)
$(makeJSON "_msgTrackingStateDetailedDep_" ''MsgTrackingStateDetailedDep)
$(makeLenses ''MsgTrackingStateDetailedDep)

-- | TrackingChannelState.
--
-- Tracking channel state for a specific satellite signal and measured signal
-- power.
data TrackingChannelState = TrackingChannelState
  { _trackingChannelState_sid :: !GnssSignal
    -- ^ GNSS signal being tracked
  , _trackingChannelState_fcn :: !Word8
    -- ^ Frequency channel number (GLONASS only)
  , _trackingChannelState_cn0 :: !Word8
    -- ^ Carrier-to-Noise density.  Zero implies invalid cn0.
  } deriving ( Show, Read, Eq )

instance Binary TrackingChannelState where
  get = do
    _trackingChannelState_sid <- get
    _trackingChannelState_fcn <- getWord8
    _trackingChannelState_cn0 <- getWord8
    pure TrackingChannelState {..}

  put TrackingChannelState {..} = do
    put _trackingChannelState_sid
    putWord8 _trackingChannelState_fcn
    putWord8 _trackingChannelState_cn0

$(makeJSON "_trackingChannelState_" ''TrackingChannelState)
$(makeLenses ''TrackingChannelState)

msgTrackingState :: Word16
msgTrackingState = 0x0041

-- | SBP class for message MSG_TRACKING_STATE (0x0041).
--
-- The tracking message returns a variable-length array of tracking channel
-- states. It reports status and carrier-to-noise density measurements for all
-- tracked satellites.
data MsgTrackingState = MsgTrackingState
  { _msgTrackingState_states :: ![TrackingChannelState]
    -- ^ Signal tracking channel state
  } deriving ( Show, Read, Eq )

instance Binary MsgTrackingState where
  get = do
    _msgTrackingState_states <- whileM (not <$> isEmpty) get
    pure MsgTrackingState {..}

  put MsgTrackingState {..} = do
    mapM_ put _msgTrackingState_states

$(makeSBP 'msgTrackingState ''MsgTrackingState)
$(makeJSON "_msgTrackingState_" ''MsgTrackingState)
$(makeLenses ''MsgTrackingState)

-- | MeasurementState.
--
-- Measurement Engine tracking channel state for a specific satellite signal
-- and measured signal power. The mesid field for Glonass can either carry the
-- FCN as 100 + FCN where FCN is in [-7, +6] or the Slot ID (from 1 to 28)
data MeasurementState = MeasurementState
  { _measurementState_mesid :: !GnssSignal
    -- ^ Measurement Engine GNSS signal being tracked (carries either Glonass FCN
    -- or SLOT)
  , _measurementState_cn0 :: !Word8
    -- ^ Carrier-to-Noise density.  Zero implies invalid cn0.
  } deriving ( Show, Read, Eq )

instance Binary MeasurementState where
  get = do
    _measurementState_mesid <- get
    _measurementState_cn0 <- getWord8
    pure MeasurementState {..}

  put MeasurementState {..} = do
    put _measurementState_mesid
    putWord8 _measurementState_cn0

$(makeJSON "_measurementState_" ''MeasurementState)
$(makeLenses ''MeasurementState)

msgMeasurementState :: Word16
msgMeasurementState = 0x0061

-- | SBP class for message MSG_MEASUREMENT_STATE (0x0061).
--
-- The tracking message returns a variable-length array of tracking channel
-- states. It reports status and carrier-to-noise density measurements for all
-- tracked satellites.
data MsgMeasurementState = MsgMeasurementState
  { _msgMeasurementState_states :: ![MeasurementState]
    -- ^ ME signal tracking channel state
  } deriving ( Show, Read, Eq )

instance Binary MsgMeasurementState where
  get = do
    _msgMeasurementState_states <- whileM (not <$> isEmpty) get
    pure MsgMeasurementState {..}

  put MsgMeasurementState {..} = do
    mapM_ put _msgMeasurementState_states

$(makeSBP 'msgMeasurementState ''MsgMeasurementState)
$(makeJSON "_msgMeasurementState_" ''MsgMeasurementState)
$(makeLenses ''MsgMeasurementState)

-- | TrackingChannelCorrelation.
--
-- Structure containing in-phase and quadrature correlation components.
data TrackingChannelCorrelation = TrackingChannelCorrelation
  { _trackingChannelCorrelation_I :: !Int16
    -- ^ In-phase correlation
  , _trackingChannelCorrelation_Q :: !Int16
    -- ^ Quadrature correlation
  } deriving ( Show, Read, Eq )

instance Binary TrackingChannelCorrelation where
  get = do
    _trackingChannelCorrelation_I <- fromIntegral <$> getWord16le
    _trackingChannelCorrelation_Q <- fromIntegral <$> getWord16le
    pure TrackingChannelCorrelation {..}

  put TrackingChannelCorrelation {..} = do
    (putWord16le . fromIntegral) _trackingChannelCorrelation_I
    (putWord16le . fromIntegral) _trackingChannelCorrelation_Q

$(makeJSON "_trackingChannelCorrelation_" ''TrackingChannelCorrelation)
$(makeLenses ''TrackingChannelCorrelation)

msgTrackingIq :: Word16
msgTrackingIq = 0x002D

-- | SBP class for message MSG_TRACKING_IQ (0x002D).
--
-- When enabled, a tracking channel can output the correlations at each update
-- interval.
data MsgTrackingIq = MsgTrackingIq
  { _msgTrackingIq_channel :: !Word8
    -- ^ Tracking channel of origin
  , _msgTrackingIq_sid   :: !GnssSignal
    -- ^ GNSS signal identifier
  , _msgTrackingIq_corrs :: ![TrackingChannelCorrelation]
    -- ^ Early, Prompt and Late correlations
  } deriving ( Show, Read, Eq )

instance Binary MsgTrackingIq where
  get = do
    _msgTrackingIq_channel <- getWord8
    _msgTrackingIq_sid <- get
    _msgTrackingIq_corrs <- replicateM 3 get
    pure MsgTrackingIq {..}

  put MsgTrackingIq {..} = do
    putWord8 _msgTrackingIq_channel
    put _msgTrackingIq_sid
    mapM_ put _msgTrackingIq_corrs

$(makeSBP 'msgTrackingIq ''MsgTrackingIq)
$(makeJSON "_msgTrackingIq_" ''MsgTrackingIq)
$(makeLenses ''MsgTrackingIq)

-- | TrackingChannelCorrelationDep.
--
-- Structure containing in-phase and quadrature correlation components.
data TrackingChannelCorrelationDep = TrackingChannelCorrelationDep
  { _trackingChannelCorrelationDep_I :: !Int32
    -- ^ In-phase correlation
  , _trackingChannelCorrelationDep_Q :: !Int32
    -- ^ Quadrature correlation
  } deriving ( Show, Read, Eq )

instance Binary TrackingChannelCorrelationDep where
  get = do
    _trackingChannelCorrelationDep_I <- fromIntegral <$> getWord32le
    _trackingChannelCorrelationDep_Q <- fromIntegral <$> getWord32le
    pure TrackingChannelCorrelationDep {..}

  put TrackingChannelCorrelationDep {..} = do
    (putWord32le . fromIntegral) _trackingChannelCorrelationDep_I
    (putWord32le . fromIntegral) _trackingChannelCorrelationDep_Q

$(makeJSON "_trackingChannelCorrelationDep_" ''TrackingChannelCorrelationDep)
$(makeLenses ''TrackingChannelCorrelationDep)

msgTrackingIqDepB :: Word16
msgTrackingIqDepB = 0x002C

-- | SBP class for message MSG_TRACKING_IQ_DEP_B (0x002C).
--
-- When enabled, a tracking channel can output the correlations at each update
-- interval.
data MsgTrackingIqDepB = MsgTrackingIqDepB
  { _msgTrackingIqDepB_channel :: !Word8
    -- ^ Tracking channel of origin
  , _msgTrackingIqDepB_sid   :: !GnssSignal
    -- ^ GNSS signal identifier
  , _msgTrackingIqDepB_corrs :: ![TrackingChannelCorrelationDep]
    -- ^ Early, Prompt and Late correlations
  } deriving ( Show, Read, Eq )

instance Binary MsgTrackingIqDepB where
  get = do
    _msgTrackingIqDepB_channel <- getWord8
    _msgTrackingIqDepB_sid <- get
    _msgTrackingIqDepB_corrs <- replicateM 3 get
    pure MsgTrackingIqDepB {..}

  put MsgTrackingIqDepB {..} = do
    putWord8 _msgTrackingIqDepB_channel
    put _msgTrackingIqDepB_sid
    mapM_ put _msgTrackingIqDepB_corrs

$(makeSBP 'msgTrackingIqDepB ''MsgTrackingIqDepB)
$(makeJSON "_msgTrackingIqDepB_" ''MsgTrackingIqDepB)
$(makeLenses ''MsgTrackingIqDepB)

msgTrackingIqDepA :: Word16
msgTrackingIqDepA = 0x001C

-- | SBP class for message MSG_TRACKING_IQ_DEP_A (0x001C).
--
-- Deprecated.
data MsgTrackingIqDepA = MsgTrackingIqDepA
  { _msgTrackingIqDepA_channel :: !Word8
    -- ^ Tracking channel of origin
  , _msgTrackingIqDepA_sid   :: !GnssSignalDep
    -- ^ GNSS signal identifier
  , _msgTrackingIqDepA_corrs :: ![TrackingChannelCorrelationDep]
    -- ^ Early, Prompt and Late correlations
  } deriving ( Show, Read, Eq )

instance Binary MsgTrackingIqDepA where
  get = do
    _msgTrackingIqDepA_channel <- getWord8
    _msgTrackingIqDepA_sid <- get
    _msgTrackingIqDepA_corrs <- replicateM 3 get
    pure MsgTrackingIqDepA {..}

  put MsgTrackingIqDepA {..} = do
    putWord8 _msgTrackingIqDepA_channel
    put _msgTrackingIqDepA_sid
    mapM_ put _msgTrackingIqDepA_corrs

$(makeSBP 'msgTrackingIqDepA ''MsgTrackingIqDepA)
$(makeJSON "_msgTrackingIqDepA_" ''MsgTrackingIqDepA)
$(makeLenses ''MsgTrackingIqDepA)

-- | TrackingChannelStateDepA.
--
-- Deprecated.
data TrackingChannelStateDepA = TrackingChannelStateDepA
  { _trackingChannelStateDepA_state :: !Word8
    -- ^ Status of tracking channel
  , _trackingChannelStateDepA_prn :: !Word8
    -- ^ PRN-1 being tracked
  , _trackingChannelStateDepA_cn0 :: !Float
    -- ^ Carrier-to-noise density
  } deriving ( Show, Read, Eq )

instance Binary TrackingChannelStateDepA where
  get = do
    _trackingChannelStateDepA_state <- getWord8
    _trackingChannelStateDepA_prn <- getWord8
    _trackingChannelStateDepA_cn0 <- getFloat32le
    pure TrackingChannelStateDepA {..}

  put TrackingChannelStateDepA {..} = do
    putWord8 _trackingChannelStateDepA_state
    putWord8 _trackingChannelStateDepA_prn
    putFloat32le _trackingChannelStateDepA_cn0

$(makeJSON "_trackingChannelStateDepA_" ''TrackingChannelStateDepA)
$(makeLenses ''TrackingChannelStateDepA)

msgTrackingStateDepA :: Word16
msgTrackingStateDepA = 0x0016

-- | SBP class for message MSG_TRACKING_STATE_DEP_A (0x0016).
--
-- Deprecated.
data MsgTrackingStateDepA = MsgTrackingStateDepA
  { _msgTrackingStateDepA_states :: ![TrackingChannelStateDepA]
    -- ^ Satellite tracking channel state
  } deriving ( Show, Read, Eq )

instance Binary MsgTrackingStateDepA where
  get = do
    _msgTrackingStateDepA_states <- whileM (not <$> isEmpty) get
    pure MsgTrackingStateDepA {..}

  put MsgTrackingStateDepA {..} = do
    mapM_ put _msgTrackingStateDepA_states

$(makeSBP 'msgTrackingStateDepA ''MsgTrackingStateDepA)
$(makeJSON "_msgTrackingStateDepA_" ''MsgTrackingStateDepA)
$(makeLenses ''MsgTrackingStateDepA)

-- | TrackingChannelStateDepB.
--
-- Deprecated.
data TrackingChannelStateDepB = TrackingChannelStateDepB
  { _trackingChannelStateDepB_state :: !Word8
    -- ^ Status of tracking channel
  , _trackingChannelStateDepB_sid :: !GnssSignalDep
    -- ^ GNSS signal being tracked
  , _trackingChannelStateDepB_cn0 :: !Float
    -- ^ Carrier-to-noise density
  } deriving ( Show, Read, Eq )

instance Binary TrackingChannelStateDepB where
  get = do
    _trackingChannelStateDepB_state <- getWord8
    _trackingChannelStateDepB_sid <- get
    _trackingChannelStateDepB_cn0 <- getFloat32le
    pure TrackingChannelStateDepB {..}

  put TrackingChannelStateDepB {..} = do
    putWord8 _trackingChannelStateDepB_state
    put _trackingChannelStateDepB_sid
    putFloat32le _trackingChannelStateDepB_cn0

$(makeJSON "_trackingChannelStateDepB_" ''TrackingChannelStateDepB)
$(makeLenses ''TrackingChannelStateDepB)

msgTrackingStateDepB :: Word16
msgTrackingStateDepB = 0x0013

-- | SBP class for message MSG_TRACKING_STATE_DEP_B (0x0013).
--
-- Deprecated.
data MsgTrackingStateDepB = MsgTrackingStateDepB
  { _msgTrackingStateDepB_states :: ![TrackingChannelStateDepB]
    -- ^ Signal tracking channel state
  } deriving ( Show, Read, Eq )

instance Binary MsgTrackingStateDepB where
  get = do
    _msgTrackingStateDepB_states <- whileM (not <$> isEmpty) get
    pure MsgTrackingStateDepB {..}

  put MsgTrackingStateDepB {..} = do
    mapM_ put _msgTrackingStateDepB_states

$(makeSBP 'msgTrackingStateDepB ''MsgTrackingStateDepB)
$(makeJSON "_msgTrackingStateDepB_" ''MsgTrackingStateDepB)
$(makeLenses ''MsgTrackingStateDepB)
