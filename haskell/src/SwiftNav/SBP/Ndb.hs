{-# OPTIONS_GHC -fno-warn-unused-imports #-}
{-# LANGUAGE NoImplicitPrelude           #-}
{-# LANGUAGE TemplateHaskell             #-}
{-# LANGUAGE RecordWildCards             #-}

-- |
-- Module:      SwiftNav.SBP.Ndb
-- Copyright:   Copyright (C) 2015-2018 Swift Navigation, Inc.
-- License:     LGPL-3
-- Maintainer:  Swift Navigation <dev@swiftnav.com>
-- Stability:   experimental
-- Portability: portable
--
-- \<Messages for logging NDB events. \>

module SwiftNav.SBP.Ndb
  ( module SwiftNav.SBP.Ndb
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


msgNdbEvent :: Word16
msgNdbEvent = 0x0400

-- | SBP class for message MSG_NDB_EVENT (0x0400).
--
-- This message is sent out when an object is stored into NDB. If needed
-- message could also be sent out when fetching an object from NDB.
data MsgNdbEvent = MsgNdbEvent
  { _msgNdbEvent_recv_time     :: !Word64
    -- ^ HW time in milliseconds.
  , _msgNdbEvent_event         :: !Word8
    -- ^ Event type.
  , _msgNdbEvent_object_type   :: !Word8
    -- ^ Event object type.
  , _msgNdbEvent_result        :: !Word8
    -- ^ Event result.
  , _msgNdbEvent_data_source   :: !Word8
    -- ^ Data source for STORE event, reserved for other events.
  , _msgNdbEvent_object_sid    :: !GnssSignal
    -- ^ GNSS signal identifier, If object_type is Ephemeris OR Almanac, sid
    -- indicates for which signal the object belongs to. Reserved in other
    -- cases.
  , _msgNdbEvent_src_sid       :: !GnssSignal
    -- ^ GNSS signal identifier, If object_type is Almanac, Almanac WN, Iono OR
    -- L2C capabilities AND data_source is NDB_DS_RECEIVER sid indicates from
    -- which SV data was decoded. Reserved in other cases.
  , _msgNdbEvent_original_sender :: !Word16
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
    _msgNdbEvent_object_sid <- get
    _msgNdbEvent_src_sid <- get
    _msgNdbEvent_original_sender <- getWord16le
    pure MsgNdbEvent {..}

  put MsgNdbEvent {..} = do
    putWord64le _msgNdbEvent_recv_time
    putWord8 _msgNdbEvent_event
    putWord8 _msgNdbEvent_object_type
    putWord8 _msgNdbEvent_result
    putWord8 _msgNdbEvent_data_source
    put _msgNdbEvent_object_sid
    put _msgNdbEvent_src_sid
    putWord16le _msgNdbEvent_original_sender

$(makeSBP 'msgNdbEvent ''MsgNdbEvent)
$(makeJSON "_msgNdbEvent_" ''MsgNdbEvent)
$(makeLenses ''MsgNdbEvent)
