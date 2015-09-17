-- |
-- Module:      SwiftNav.SBP.ExtEvents
-- Copyright:   Copyright (C) 2015 Swift Navigation, Inc.
-- License:     LGPL-3
-- Maintainer:  Mark Fine <dev@swiftnav.com>
-- Stability:   experimental
-- Portability: portable
--
-- Messages reporting accurately-timestamped external events, e.g. camera
-- shutter time.

module SwiftNav.SBP.ExtEvents where

import BasicPrelude
import Control.Lens
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
import SwiftNav.SBP.TH
import SwiftNav.SBP.Types

msgExtEvent :: Word16
msgExtEvent = 0x0101

-- | SBP class for message MSG_EXT_EVENT (0x0101).
--
-- Reports detection of an external event, the GPS time it occurred, which pin
-- it was and whether it was rising or falling.
data MsgExtEvent = MsgExtEvent
  { _msgExtEvent_wn  :: Word16
    -- ^ GPS week number
  , _msgExtEvent_tow :: Word32
    -- ^ GPS time of week rounded to the nearest millisecond
  , _msgExtEvent_ns  :: Int32
    -- ^ Nanosecond residual of millisecond-rounded TOW (ranges from -500000 to
    -- 500000)
  , _msgExtEvent_flags :: Word8
    -- ^ Flags
  , _msgExtEvent_pin :: Word8
    -- ^ Pin number.  0..9 = DEBUG0..9.
  } deriving ( Show, Read, Eq )

instance Binary MsgExtEvent where
  get = do
    _msgExtEvent_wn <- getWord16le
    _msgExtEvent_tow <- getWord32le
    _msgExtEvent_ns <- liftM fromIntegral getWord32le
    _msgExtEvent_flags <- getWord8
    _msgExtEvent_pin <- getWord8
    return MsgExtEvent {..}

  put MsgExtEvent {..} = do
    putWord16le _msgExtEvent_wn
    putWord32le _msgExtEvent_tow
    putWord32le $ fromIntegral _msgExtEvent_ns
    putWord8 _msgExtEvent_flags
    putWord8 _msgExtEvent_pin

$(deriveSBP 'msgExtEvent ''MsgExtEvent)

$(deriveJSON defaultOptions {fieldLabelModifier = fromMaybe "_msgExtEvent_" . stripPrefix "_msgExtEvent_"}
             ''MsgExtEvent)
$(makeLenses ''MsgExtEvent)
