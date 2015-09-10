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

-- | TrackingChannelState.
--
-- Tracking channel state for a specific satellite PRN and measured signal
-- power.
data TrackingChannelState = TrackingChannelState
  { trackingChannelStateState :: Word8
    -- ^ Status of tracking channel
  , trackingChannelStateSid   :: Word32
    -- ^ Signal identifier being tracked - values 0x00 through 0x1F represent GPS
    -- PRNs 1 through 32 respectively (PRN-1 notation); other values reserved
    -- for future use
  , trackingChannelStateCn0   :: Float
    -- ^ Carrier-to-noise density
  } deriving ( Show, Read, Eq )

instance Binary TrackingChannelState where
  get = do
    trackingChannelStateState <- getWord8
    trackingChannelStateSid <- getWord32le
    trackingChannelStateCn0 <- getFloat32le
    return TrackingChannelState {..}

  put TrackingChannelState {..} = do
    putWord8 trackingChannelStateState
    putWord32le trackingChannelStateSid
    putFloat32le trackingChannelStateCn0

msgTrackingState :: Word16
msgTrackingState = 0x0013

-- | SBP class for message MSG_TRACKING_STATE (0x0013).
--
-- The tracking message returns a variable-length array of tracking channel
-- states. It reports status and snr power measurements for all tracked
-- satellites.
data MsgTrackingState = MsgTrackingState
  { msgTrackingStateStates :: [TrackingChannelState]
    -- ^ Satellite tracking channel state
  } deriving ( Show, Read, Eq )

instance Binary MsgTrackingState where
  get = do
    msgTrackingStateStates <- whileM (liftM not isEmpty) get
    return MsgTrackingState {..}

  put MsgTrackingState {..} = do
    mapM_ put msgTrackingStateStates

-- | TrackingChannelCorrelation.
--
-- Structure containing in-phase and quadrature correlation components.
data TrackingChannelCorrelation = TrackingChannelCorrelation
  { trackingChannelCorrelationI :: Int32
    -- ^ In-phase correlation
  , trackingChannelCorrelationQ :: Int32
    -- ^ Quadrature correlation
  } deriving ( Show, Read, Eq )

instance Binary TrackingChannelCorrelation where
  get = do
    trackingChannelCorrelationI <- liftM fromIntegral getWord32le
    trackingChannelCorrelationQ <- liftM fromIntegral getWord32le
    return TrackingChannelCorrelation {..}

  put TrackingChannelCorrelation {..} = do
    putWord32le $ fromIntegral trackingChannelCorrelationI
    putWord32le $ fromIntegral trackingChannelCorrelationQ

msgTrackingIq :: Word16
msgTrackingIq = 0x001C

-- | SBP class for message MSG_TRACKING_IQ (0x001C).
--
-- When enabled, a tracking channel can output the correlations at each update
-- interval.
data MsgTrackingIq = MsgTrackingIq
  { msgTrackingIqChannel :: Word8
    -- ^ Tracking channel of origin
  , msgTrackingIqSid     :: Word32
    -- ^ Signal identifier being tracked - values 0x00 through 0x1F represent GPS
    -- PRNs 1 through 32 respectively (PRN-1 notation); other values reserved
    -- for future use
  , msgTrackingIqCorrs   :: [TrackingChannelCorrelation]
    -- ^ Early, Prompt and Late correlations
  } deriving ( Show, Read, Eq )

instance Binary MsgTrackingIq where
  get = do
    msgTrackingIqChannel <- getWord8
    msgTrackingIqSid <- getWord32le
    msgTrackingIqCorrs <- replicateM 3 get
    return MsgTrackingIq {..}

  put MsgTrackingIq {..} = do
    putWord8 msgTrackingIqChannel
    putWord32le msgTrackingIqSid
    mapM_ put msgTrackingIqCorrs

-- | TrackingChannelStateDepA.
--
-- Deprecated.
data TrackingChannelStateDepA = TrackingChannelStateDepA
  { trackingChannelStateDepAState :: Word8
    -- ^ Status of tracking channel
  , trackingChannelStateDepAPrn   :: Word8
    -- ^ PRN-1 being tracked
  , trackingChannelStateDepACn0   :: Float
    -- ^ Carrier-to-noise density
  } deriving ( Show, Read, Eq )

instance Binary TrackingChannelStateDepA where
  get = do
    trackingChannelStateDepAState <- getWord8
    trackingChannelStateDepAPrn <- getWord8
    trackingChannelStateDepACn0 <- getFloat32le
    return TrackingChannelStateDepA {..}

  put TrackingChannelStateDepA {..} = do
    putWord8 trackingChannelStateDepAState
    putWord8 trackingChannelStateDepAPrn
    putFloat32le trackingChannelStateDepACn0

msgTrackingStateDepA :: Word16
msgTrackingStateDepA = 0x0016

-- | SBP class for message MSG_TRACKING_STATE_DEP_A (0x0016).
--
-- Deprecated.
data MsgTrackingStateDepA = MsgTrackingStateDepA
  { msgTrackingStateDepAStates :: [TrackingChannelStateDepA]
    -- ^ Satellite tracking channel state
  } deriving ( Show, Read, Eq )

instance Binary MsgTrackingStateDepA where
  get = do
    msgTrackingStateDepAStates <- whileM (liftM not isEmpty) get
    return MsgTrackingStateDepA {..}

  put MsgTrackingStateDepA {..} = do
    mapM_ put msgTrackingStateDepAStates
