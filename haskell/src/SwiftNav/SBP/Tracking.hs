{-# OPTIONS_GHC -fno-warn-unused-imports #-}
-- |
-- Module:      SwiftNav.SBP.Tracking
-- Copyright:   Copyright (C) 2015 Swift Navigation, Inc.
-- License:     LGPL-3
-- Maintainer:  Mark Fine <dev@swiftnav.com>
-- Stability:   experimental
-- Portability: portable
--
-- Satellite code and carrier-phase tracking messages from the device.

module SwiftNav.SBP.Tracking where

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

-- | TrackingChannelState.
--
-- Tracking channel state for a specific satellite signal and measured signal
-- power.
data TrackingChannelState = TrackingChannelState
  { _trackingChannelState_state :: Word8
    -- ^ Status of tracking channel
  , _trackingChannelState_sid :: GnssSignal
    -- ^ GNSS signal being tracked
  , _trackingChannelState_cn0 :: Float
    -- ^ Carrier-to-noise density
  } deriving ( Show, Read, Eq )

instance Binary TrackingChannelState where
  get = do
    _trackingChannelState_state <- getWord8
    _trackingChannelState_sid <- get
    _trackingChannelState_cn0 <- getFloat32le
    return TrackingChannelState {..}

  put TrackingChannelState {..} = do
    putWord8 _trackingChannelState_state
    put _trackingChannelState_sid
    putFloat32le _trackingChannelState_cn0
$(deriveJSON defaultOptions {fieldLabelModifier = fromMaybe "_trackingChannelState_" . stripPrefix "_trackingChannelState_"}
             ''TrackingChannelState)
$(makeLenses ''TrackingChannelState)

msgTrackingState :: Word16
msgTrackingState = 0x0013

-- | SBP class for message MSG_TRACKING_STATE (0x0013).
--
-- The tracking message returns a variable-length array of tracking channel
-- states. It reports status and carrier-to-noise density measurements for all
-- tracked satellites.
data MsgTrackingState = MsgTrackingState
  { _msgTrackingState_states :: [TrackingChannelState]
    -- ^ Satellite tracking channel state
  } deriving ( Show, Read, Eq )

instance Binary MsgTrackingState where
  get = do
    _msgTrackingState_states <- whileM (liftM not isEmpty) get
    return MsgTrackingState {..}

  put MsgTrackingState {..} = do
    mapM_ put _msgTrackingState_states

$(deriveSBP 'msgTrackingState ''MsgTrackingState)

$(deriveJSON defaultOptions {fieldLabelModifier = fromMaybe "_msgTrackingState_" . stripPrefix "_msgTrackingState_"}
             ''MsgTrackingState)
$(makeLenses ''MsgTrackingState)

-- | TrackingChannelCorrelation.
--
-- Structure containing in-phase and quadrature correlation components.
data TrackingChannelCorrelation = TrackingChannelCorrelation
  { _trackingChannelCorrelation_I :: Int32
    -- ^ In-phase correlation
  , _trackingChannelCorrelation_Q :: Int32
    -- ^ Quadrature correlation
  } deriving ( Show, Read, Eq )

instance Binary TrackingChannelCorrelation where
  get = do
    _trackingChannelCorrelation_I <- liftM fromIntegral getWord32le
    _trackingChannelCorrelation_Q <- liftM fromIntegral getWord32le
    return TrackingChannelCorrelation {..}

  put TrackingChannelCorrelation {..} = do
    putWord32le $ fromIntegral _trackingChannelCorrelation_I
    putWord32le $ fromIntegral _trackingChannelCorrelation_Q
$(deriveJSON defaultOptions {fieldLabelModifier = fromMaybe "_trackingChannelCorrelation_" . stripPrefix "_trackingChannelCorrelation_"}
             ''TrackingChannelCorrelation)
$(makeLenses ''TrackingChannelCorrelation)

msgTrackingIq :: Word16
msgTrackingIq = 0x001C

-- | SBP class for message MSG_TRACKING_IQ (0x001C).
--
-- When enabled, a tracking channel can output the correlations at each update
-- interval.
data MsgTrackingIq = MsgTrackingIq
  { _msgTrackingIq_channel :: Word8
    -- ^ Tracking channel of origin
  , _msgTrackingIq_sid   :: GnssSignal
    -- ^ GNSS signal identifier
  , _msgTrackingIq_corrs :: [TrackingChannelCorrelation]
    -- ^ Early, Prompt and Late correlations
  } deriving ( Show, Read, Eq )

instance Binary MsgTrackingIq where
  get = do
    _msgTrackingIq_channel <- getWord8
    _msgTrackingIq_sid <- get
    _msgTrackingIq_corrs <- replicateM 3 get
    return MsgTrackingIq {..}

  put MsgTrackingIq {..} = do
    putWord8 _msgTrackingIq_channel
    put _msgTrackingIq_sid
    mapM_ put _msgTrackingIq_corrs

$(deriveSBP 'msgTrackingIq ''MsgTrackingIq)

$(deriveJSON defaultOptions {fieldLabelModifier = fromMaybe "_msgTrackingIq_" . stripPrefix "_msgTrackingIq_"}
             ''MsgTrackingIq)
$(makeLenses ''MsgTrackingIq)

-- | TrackingChannelStateDepA.
--
-- Deprecated.
data TrackingChannelStateDepA = TrackingChannelStateDepA
  { _trackingChannelStateDepA_state :: Word8
    -- ^ Status of tracking channel
  , _trackingChannelStateDepA_prn :: Word8
    -- ^ PRN-1 being tracked
  , _trackingChannelStateDepA_cn0 :: Float
    -- ^ Carrier-to-noise density
  } deriving ( Show, Read, Eq )

instance Binary TrackingChannelStateDepA where
  get = do
    _trackingChannelStateDepA_state <- getWord8
    _trackingChannelStateDepA_prn <- getWord8
    _trackingChannelStateDepA_cn0 <- getFloat32le
    return TrackingChannelStateDepA {..}

  put TrackingChannelStateDepA {..} = do
    putWord8 _trackingChannelStateDepA_state
    putWord8 _trackingChannelStateDepA_prn
    putFloat32le _trackingChannelStateDepA_cn0
$(deriveJSON defaultOptions {fieldLabelModifier = fromMaybe "_trackingChannelStateDepA_" . stripPrefix "_trackingChannelStateDepA_"}
             ''TrackingChannelStateDepA)
$(makeLenses ''TrackingChannelStateDepA)

msgTrackingStateDepA :: Word16
msgTrackingStateDepA = 0x0016

-- | SBP class for message MSG_TRACKING_STATE_DEP_A (0x0016).
--
-- Deprecated.
data MsgTrackingStateDepA = MsgTrackingStateDepA
  { _msgTrackingStateDepA_states :: [TrackingChannelStateDepA]
    -- ^ Satellite tracking channel state
  } deriving ( Show, Read, Eq )

instance Binary MsgTrackingStateDepA where
  get = do
    _msgTrackingStateDepA_states <- whileM (liftM not isEmpty) get
    return MsgTrackingStateDepA {..}

  put MsgTrackingStateDepA {..} = do
    mapM_ put _msgTrackingStateDepA_states

$(deriveSBP 'msgTrackingStateDepA ''MsgTrackingStateDepA)

$(deriveJSON defaultOptions {fieldLabelModifier = fromMaybe "_msgTrackingStateDepA_" . stripPrefix "_msgTrackingStateDepA_"}
             ''MsgTrackingStateDepA)
$(makeLenses ''MsgTrackingStateDepA)
