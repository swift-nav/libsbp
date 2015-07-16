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

data TrackingChannelState = TrackingChannelState
  { trackingChannelStateState :: Word8
  , trackingChannelStateSid   :: Word32
  , trackingChannelStateCn0   :: Float
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

data MsgTrackingState = MsgTrackingState
  { msgTrackingStateStates :: [TrackingChannelState]
  } deriving ( Show, Read, Eq )

instance Binary MsgTrackingState where
  get = do
    msgTrackingStateStates <- whileM (liftM not isEmpty) get
    return MsgTrackingState {..}

  put MsgTrackingState {..} = do
    put msgTrackingStateStates

data TrackingChannelCorrelation = TrackingChannelCorrelation
  { trackingChannelCorrelationI :: Int32
  , trackingChannelCorrelationQ :: Int32
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

data MsgTrackingIq = MsgTrackingIq
  { msgTrackingIqChannel :: Word8
  , msgTrackingIqSid     :: Word32
  , msgTrackingIqCorrs   :: [TrackingChannelCorrelation]
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
    put msgTrackingIqCorrs

data TrackingChannelStateDepA = TrackingChannelStateDepA
  { trackingChannelStateDepAState :: Word8
  , trackingChannelStateDepAPrn   :: Word8
  , trackingChannelStateDepACn0   :: Float
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

data MsgTrackingStateDepA = MsgTrackingStateDepA
  { msgTrackingStateDepAStates :: [TrackingChannelStateDepA]
  } deriving ( Show, Read, Eq )

instance Binary MsgTrackingStateDepA where
  get = do
    msgTrackingStateDepAStates <- whileM (liftM not isEmpty) get
    return MsgTrackingStateDepA {..}

  put MsgTrackingStateDepA {..} = do
    put msgTrackingStateDepAStates
