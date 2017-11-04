{-# OPTIONS_GHC -fno-warn-unused-imports #-}
{-# LANGUAGE NoImplicitPrelude #-}
{-# LANGUAGE RecordWildCards   #-}
{-# LANGUAGE TemplateHaskell   #-}

-- |
-- Module:      SwiftNav.SBP.Tracking
-- Copyright:   Copyright (C) 2015 Swift Navigation, Inc.
-- License:     LGPL-3
-- Maintainer:  Mark Fine <dev@swiftnav.com>
-- Stability:   experimental
-- Portability: portable
--
-- Satellite code and carrier-phase tracking messages from the device.

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
import Data.ByteString.Lazy hiding (ByteString)
import Data.Int
import Data.Word
import SwiftNav.SBP.Gnss
import SwiftNav.SBP.TH
import SwiftNav.SBP.Types

{-# ANN module ("HLint: ignore Use camelCase"::String) #-}
{-# ANN module ("HLint: ignore Redundant do"::String) #-}
{-# ANN module ("HLint: ignore Use newtype instead of data"::String) #-}


msgTrackingStateDetailed :: Word16
msgTrackingStateDetailed = 0x0011

-- | SBP class for message MSG_TRACKING_STATE_DETAILED (0x0011).
--
-- The tracking message returns a set tracking channel parameters for a single
-- tracking channel useful for debugging issues.
data MsgTrackingStateDetailed = MsgTrackingStateDetailed
  { _msgTrackingStateDetailed_recv_time  :: !Word64
    -- ^ Receiver clock time.
  , _msgTrackingStateDetailed_tot        :: !GpsTime
    -- ^ Time of transmission of signal from satellite. TOW only valid when TOW
    -- status is decoded or propagated. WN only valid when week number valid
    -- flag is set.
  , _msgTrackingStateDetailed_P          :: !Word32
    -- ^ Pseudorange observation. Valid only when pseudorange valid flag is set.
  , _msgTrackingStateDetailed_P_std      :: !Word16
    -- ^ Pseudorange observation standard deviation. Valid only when pseudorange
    -- valid flag is set.
  , _msgTrackingStateDetailed_L          :: !CarrierPhase
    -- ^ Carrier phase observation with typical sign convention. Valid only when
    -- PLL pessimistic lock is achieved.
  , _msgTrackingStateDetailed_cn0        :: !Word8
    -- ^ Carrier-to-Noise density
  , _msgTrackingStateDetailed_lock       :: !Word16
    -- ^ Lock time. It is encoded according to DF402 from the RTCM 10403.2
    -- Amendment 2 specification. Valid values range from 0 to 15.
  , _msgTrackingStateDetailed_sid        :: !GnssSignal
    -- ^ GNSS signal identifier.
  , _msgTrackingStateDetailed_doppler    :: !Int32
    -- ^ Carrier Doppler frequency.
  , _msgTrackingStateDetailed_doppler_std :: !Word16
    -- ^ Carrier Doppler frequency standard deviation.
  , _msgTrackingStateDetailed_uptime     :: !Word32
    -- ^ Number of seconds of continuous tracking. Specifies how much time signal
    -- is in continuous track.
  , _msgTrackingStateDetailed_clock_offset :: !Int16
    -- ^ TCXO clock offset. Valid only when valid clock valid flag is set.
  , _msgTrackingStateDetailed_clock_drift :: !Int16
    -- ^ TCXO clock drift. Valid only when valid clock valid flag is set.
  , _msgTrackingStateDetailed_corr_spacing :: !Word16
    -- ^ Early-Prompt (EP) and Prompt-Late (PL) correlators spacing.
  , _msgTrackingStateDetailed_acceleration :: !Int8
    -- ^ Acceleration. Valid only when acceleration valid flag is set.
  , _msgTrackingStateDetailed_sync_flags :: !Word8
    -- ^ Synchronization status flags.
  , _msgTrackingStateDetailed_tow_flags  :: !Word8
    -- ^ TOW status flags.
  , _msgTrackingStateDetailed_track_flags :: !Word8
    -- ^ Tracking loop status flags.
  , _msgTrackingStateDetailed_nav_flags  :: !Word8
    -- ^ Navigation data status flags.
  , _msgTrackingStateDetailed_pset_flags :: !Word8
    -- ^ Parameters sets flags.
  , _msgTrackingStateDetailed_misc_flags :: !Word8
    -- ^ Miscellaneous flags.
  } deriving ( Show, Read, Eq )

instance Binary MsgTrackingStateDetailed where
  get = do
    _msgTrackingStateDetailed_recv_time <- getWord64le
    _msgTrackingStateDetailed_tot <- get
    _msgTrackingStateDetailed_P <- getWord32le
    _msgTrackingStateDetailed_P_std <- getWord16le
    _msgTrackingStateDetailed_L <- get
    _msgTrackingStateDetailed_cn0 <- getWord8
    _msgTrackingStateDetailed_lock <- getWord16le
    _msgTrackingStateDetailed_sid <- get
    _msgTrackingStateDetailed_doppler <- fromIntegral <$> getWord32le
    _msgTrackingStateDetailed_doppler_std <- getWord16le
    _msgTrackingStateDetailed_uptime <- getWord32le
    _msgTrackingStateDetailed_clock_offset <- fromIntegral <$> getWord16le
    _msgTrackingStateDetailed_clock_drift <- fromIntegral <$> getWord16le
    _msgTrackingStateDetailed_corr_spacing <- getWord16le
    _msgTrackingStateDetailed_acceleration <- fromIntegral <$> getWord8
    _msgTrackingStateDetailed_sync_flags <- getWord8
    _msgTrackingStateDetailed_tow_flags <- getWord8
    _msgTrackingStateDetailed_track_flags <- getWord8
    _msgTrackingStateDetailed_nav_flags <- getWord8
    _msgTrackingStateDetailed_pset_flags <- getWord8
    _msgTrackingStateDetailed_misc_flags <- getWord8
    pure MsgTrackingStateDetailed {..}

  put MsgTrackingStateDetailed {..} = do
    putWord64le _msgTrackingStateDetailed_recv_time
    put _msgTrackingStateDetailed_tot
    putWord32le _msgTrackingStateDetailed_P
    putWord16le _msgTrackingStateDetailed_P_std
    put _msgTrackingStateDetailed_L
    putWord8 _msgTrackingStateDetailed_cn0
    putWord16le _msgTrackingStateDetailed_lock
    put _msgTrackingStateDetailed_sid
    putWord32le $ fromIntegral _msgTrackingStateDetailed_doppler
    putWord16le _msgTrackingStateDetailed_doppler_std
    putWord32le _msgTrackingStateDetailed_uptime
    putWord16le $ fromIntegral _msgTrackingStateDetailed_clock_offset
    putWord16le $ fromIntegral _msgTrackingStateDetailed_clock_drift
    putWord16le _msgTrackingStateDetailed_corr_spacing
    putWord8 $ fromIntegral _msgTrackingStateDetailed_acceleration
    putWord8 _msgTrackingStateDetailed_sync_flags
    putWord8 _msgTrackingStateDetailed_tow_flags
    putWord8 _msgTrackingStateDetailed_track_flags
    putWord8 _msgTrackingStateDetailed_nav_flags
    putWord8 _msgTrackingStateDetailed_pset_flags
    putWord8 _msgTrackingStateDetailed_misc_flags

$(makeSBP 'msgTrackingStateDetailed ''MsgTrackingStateDetailed)
$(makeJSON "_msgTrackingStateDetailed_" ''MsgTrackingStateDetailed)
$(makeLenses ''MsgTrackingStateDetailed)

-- | TrackingChannelState.
--
-- Tracking channel state for a specific satellite signal and measured signal
-- power.
data TrackingChannelState = TrackingChannelState
  { _trackingChannelState_sid :: !GnssSignal16
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

-- | TrackingChannelCorrelation.
--
-- Structure containing in-phase and quadrature correlation components.
data TrackingChannelCorrelation = TrackingChannelCorrelation
  { _trackingChannelCorrelation_I :: !Int32
    -- ^ In-phase correlation
  , _trackingChannelCorrelation_Q :: !Int32
    -- ^ Quadrature correlation
  } deriving ( Show, Read, Eq )

instance Binary TrackingChannelCorrelation where
  get = do
    _trackingChannelCorrelation_I <- fromIntegral <$> getWord32le
    _trackingChannelCorrelation_Q <- fromIntegral <$> getWord32le
    pure TrackingChannelCorrelation {..}

  put TrackingChannelCorrelation {..} = do
    putWord32le $ fromIntegral _trackingChannelCorrelation_I
    putWord32le $ fromIntegral _trackingChannelCorrelation_Q

$(makeJSON "_trackingChannelCorrelation_" ''TrackingChannelCorrelation)
$(makeLenses ''TrackingChannelCorrelation)

msgTrackingIq :: Word16
msgTrackingIq = 0x001C

-- | SBP class for message MSG_TRACKING_IQ (0x001C).
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
  , _trackingChannelStateDepB_sid :: !GnssSignal
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
