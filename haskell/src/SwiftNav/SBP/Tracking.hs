module SwiftNav.SBP.Tracking where

import Data.Int
import Data.Text
import Data.Word


data TrackingChannelState = TrackingChannelState
  { trackingChannelStateState :: Word8
  , trackingChannelStateSid   :: Word32
  , trackingChannelStateCn0   :: Float
  } deriving ( Show, Read, Eq )

msgTrackingState :: Word16
msgTrackingState = 0x0013
data MsgTrackingState = MsgTrackingState
  { msgTrackingStateStates :: [TrackingChannelState]
  } deriving ( Show, Read, Eq )

data TrackingChannelCorrelation = TrackingChannelCorrelation
  { trackingChannelCorrelationI :: Int32
  , trackingChannelCorrelationQ :: Int32
  } deriving ( Show, Read, Eq )

msgTrackingIq :: Word16
msgTrackingIq = 0x001C
data MsgTrackingIq = MsgTrackingIq
  { msgTrackingIqChannel :: Word8
  , msgTrackingIqSid     :: Word32
  , msgTrackingIqCorrs   :: [TrackingChannelCorrelation]
  } deriving ( Show, Read, Eq )

data TrackingChannelStateDepA = TrackingChannelStateDepA
  { trackingChannelStateDepAState :: Word8
  , trackingChannelStateDepAPrn   :: Word8
  , trackingChannelStateDepACn0   :: Float
  } deriving ( Show, Read, Eq )

msgTrackingStateDepA :: Word16
msgTrackingStateDepA = 0x0016
data MsgTrackingStateDepA = MsgTrackingStateDepA
  { msgTrackingStateDepAStates :: [TrackingChannelStateDepA]
  } deriving ( Show, Read, Eq )
