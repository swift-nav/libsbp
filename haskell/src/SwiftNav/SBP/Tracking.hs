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

-- | TrackingChannelState.
--
-- Tracking channel state for a specific satellite PRN and measured signal
-- power.
data TrackingChannelState = TrackingChannelState
  { trackingChannelState_state :: Word8
    -- ^ Status of tracking channel
  , trackingChannelState_sid  :: Word32
    -- ^ Signal identifier being tracked - values 0x00 through 0x1F represent GPS
    -- PRNs 1 through 32 respectively (PRN-1 notation); other values reserved
    -- for future use
  , trackingChannelState_cn0  :: Float
    -- ^ Carrier-to-noise density
  } deriving ( Show, Read, Eq )

instance Binary TrackingChannelState where
  get = do
    trackingChannelState_state <- getWord8
    trackingChannelState_sid <- getWord32le
    trackingChannelState_cn0 <- getFloat32le
    return TrackingChannelState {..}

  put TrackingChannelState {..} = do
    putWord8 trackingChannelState_state
    putWord32le trackingChannelState_sid
    putFloat32le trackingChannelState_cn0

$(deriveJSON defaultOptions {fieldLabelModifier = fromMaybe "trackingChannelState_" . stripPrefix "trackingChannelState_"}
             ''TrackingChannelState)

msgTrackingState :: Word16
msgTrackingState = 0x0013

-- | SBP class for message MSG_TRACKING_STATE (0x0013).
--
-- The tracking message returns a variable-length array of tracking channel
-- states. It reports status and snr power measurements for all tracked
-- satellites.
data MsgTrackingState = MsgTrackingState
  { msgTrackingState_states :: [TrackingChannelState]
    -- ^ Satellite tracking channel state
  } deriving ( Show, Read, Eq )

instance Binary MsgTrackingState where
  get = do
    msgTrackingState_states <- whileM (liftM not isEmpty) get
    return MsgTrackingState {..}

  put MsgTrackingState {..} = do
    mapM_ put msgTrackingState_states

$(deriveJSON defaultOptions {fieldLabelModifier = fromMaybe "msgTrackingState_" . stripPrefix "msgTrackingState_"}
             ''MsgTrackingState)

-- | TrackingChannelCorrelation.
--
-- Structure containing in-phase and quadrature correlation components.
data TrackingChannelCorrelation = TrackingChannelCorrelation
  { trackingChannelCorrelation_I :: Int32
    -- ^ In-phase correlation
  , trackingChannelCorrelation_Q :: Int32
    -- ^ Quadrature correlation
  } deriving ( Show, Read, Eq )

instance Binary TrackingChannelCorrelation where
  get = do
    trackingChannelCorrelation_I <- liftM fromIntegral getWord32le
    trackingChannelCorrelation_Q <- liftM fromIntegral getWord32le
    return TrackingChannelCorrelation {..}

  put TrackingChannelCorrelation {..} = do
    putWord32le $ fromIntegral trackingChannelCorrelation_I
    putWord32le $ fromIntegral trackingChannelCorrelation_Q

$(deriveJSON defaultOptions {fieldLabelModifier = fromMaybe "trackingChannelCorrelation_" . stripPrefix "trackingChannelCorrelation_"}
             ''TrackingChannelCorrelation)

msgTrackingIq :: Word16
msgTrackingIq = 0x001C

-- | SBP class for message MSG_TRACKING_IQ (0x001C).
--
-- When enabled, a tracking channel can output the correlations at each update
-- interval.
data MsgTrackingIq = MsgTrackingIq
  { msgTrackingIq_channel :: Word8
    -- ^ Tracking channel of origin
  , msgTrackingIq_sid    :: Word32
    -- ^ Signal identifier being tracked - values 0x00 through 0x1F represent GPS
    -- PRNs 1 through 32 respectively (PRN-1 notation); other values reserved
    -- for future use
  , msgTrackingIq_corrs  :: [TrackingChannelCorrelation]
    -- ^ Early, Prompt and Late correlations
  } deriving ( Show, Read, Eq )

instance Binary MsgTrackingIq where
  get = do
    msgTrackingIq_channel <- getWord8
    msgTrackingIq_sid <- getWord32le
    msgTrackingIq_corrs <- replicateM 3 get
    return MsgTrackingIq {..}

  put MsgTrackingIq {..} = do
    putWord8 msgTrackingIq_channel
    putWord32le msgTrackingIq_sid
    mapM_ put msgTrackingIq_corrs

$(deriveJSON defaultOptions {fieldLabelModifier = fromMaybe "msgTrackingIq_" . stripPrefix "msgTrackingIq_"}
             ''MsgTrackingIq)

-- | TrackingChannelStateDepA.
--
-- Deprecated.
data TrackingChannelStateDepA = TrackingChannelStateDepA
  { trackingChannelStateDepA_state :: Word8
    -- ^ Status of tracking channel
  , trackingChannelStateDepA_prn  :: Word8
    -- ^ PRN-1 being tracked
  , trackingChannelStateDepA_cn0  :: Float
    -- ^ Carrier-to-noise density
  } deriving ( Show, Read, Eq )

instance Binary TrackingChannelStateDepA where
  get = do
    trackingChannelStateDepA_state <- getWord8
    trackingChannelStateDepA_prn <- getWord8
    trackingChannelStateDepA_cn0 <- getFloat32le
    return TrackingChannelStateDepA {..}

  put TrackingChannelStateDepA {..} = do
    putWord8 trackingChannelStateDepA_state
    putWord8 trackingChannelStateDepA_prn
    putFloat32le trackingChannelStateDepA_cn0

$(deriveJSON defaultOptions {fieldLabelModifier = fromMaybe "trackingChannelStateDepA_" . stripPrefix "trackingChannelStateDepA_"}
             ''TrackingChannelStateDepA)

msgTrackingStateDepA :: Word16
msgTrackingStateDepA = 0x0016

-- | SBP class for message MSG_TRACKING_STATE_DEP_A (0x0016).
--
-- Deprecated.
data MsgTrackingStateDepA = MsgTrackingStateDepA
  { msgTrackingStateDepA_states :: [TrackingChannelStateDepA]
    -- ^ Satellite tracking channel state
  } deriving ( Show, Read, Eq )

instance Binary MsgTrackingStateDepA where
  get = do
    msgTrackingStateDepA_states <- whileM (liftM not isEmpty) get
    return MsgTrackingStateDepA {..}

  put MsgTrackingStateDepA {..} = do
    mapM_ put msgTrackingStateDepA_states

$(deriveJSON defaultOptions {fieldLabelModifier = fromMaybe "msgTrackingStateDepA_" . stripPrefix "msgTrackingStateDepA_"}
             ''MsgTrackingStateDepA)
