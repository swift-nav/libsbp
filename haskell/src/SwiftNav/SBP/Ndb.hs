{-# OPTIONS_GHC -fno-warn-unused-imports #-}
-- |
-- Module:      SwiftNav.SBP.Ndb
-- Copyright:   Copyright (C) 2015 Swift Navigation, Inc.
-- License:     LGPL-3
-- Maintainer:  Mark Fine <dev@swiftnav.com>
-- Stability:   experimental
-- Portability: portable
--
-- Messages for logging NDB events.

module SwiftNav.SBP.Ndb where

import BasicPrelude as P
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
import SwiftNav.SBP.Gnss

msgNdbEvent :: Word16
msgNdbEvent = 0x0400

-- | SBP class for message MSG_NDB_EVENT (0x0400).
--
-- This message is sent out when an object is stored into NDB. If needed
-- message could also be sent out when fetching an object from NDB.
data MsgNdbEvent = MsgNdbEvent
  { _msgNdbEvent_recv_time :: Word64
    -- ^ HW time in milliseconds.
  , _msgNdbEvent_event     :: Word8
    -- ^ Event type.
  , _msgNdbEvent_object_type :: Word8
    -- ^ Event object type.
  , _msgNdbEvent_result    :: Word8
    -- ^ Event result.
  , _msgNdbEvent_data_source :: Word8
    -- ^ Data source for STORE event, reserved for other events.
  , _msgNdbEvent_sid       :: GnssSignal16
    -- ^ GNSS signal identifier, If object_type is Ephemeris OR Almanac, sid
    -- indicates for which signal the object belongs to. If object_type is Iono
    -- OR L2C capabilities AND data_source is NDB_DS_RECEIVER sid indicates
    -- from which SV data was decoded. Reserved in other cases.
  , _msgNdbEvent_sender    :: Word16
    -- ^ A unique identifier of the sending hardware. For v1.0, set to the 2
    -- least significant bytes of the device serial number, valid only if
    -- data_source is NDB_DS_SBP. Reserved in case of other data_source.
  } deriving ( Show, Read, Eq )

instance Binary MsgNdbEvent where
  get = do
    _msgNdbEvent_recv_time <- getWord64le
    _msgNdbEvent_event <- getWord8
    _msgNdbEvent_object_type <- getWord8
    _msgNdbEvent_result <- getWord8
    _msgNdbEvent_data_source <- getWord8
    _msgNdbEvent_sid <- get
    _msgNdbEvent_sender <- getWord16le
    return MsgNdbEvent {..}

  put MsgNdbEvent {..} = do
    putWord64le _msgNdbEvent_recv_time
    putWord8 _msgNdbEvent_event
    putWord8 _msgNdbEvent_object_type
    putWord8 _msgNdbEvent_result
    putWord8 _msgNdbEvent_data_source
    put _msgNdbEvent_sid
    putWord16le _msgNdbEvent_sender

$(deriveSBP 'msgNdbEvent ''MsgNdbEvent)

$(deriveJSON defaultOptions {fieldLabelModifier = fromMaybe "_msgNdbEvent_" . P.stripPrefix "_msgNdbEvent_"}
             ''MsgNdbEvent)
$(makeLenses ''MsgNdbEvent)
