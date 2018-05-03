{-# OPTIONS_GHC -fno-warn-unused-imports #-}
{-# LANGUAGE NoImplicitPrelude           #-}
{-# LANGUAGE TemplateHaskell             #-}
{-# LANGUAGE RecordWildCards             #-}

-- |
-- Module:      SwiftNav.SBP.Raw
-- Copyright:   Copyright (C) 2015-2018 Swift Navigation, Inc.
-- License:     LGPL-3
-- Maintainer:  Swift Navigation <dev@swiftnav.com>
-- Stability:   experimental
-- Portability: portable
--
-- Raw GNSS navigation data

module SwiftNav.SBP.Raw
  ( module SwiftNav.SBP.Raw
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
import SwiftNav.SBP.Gnss

{-# ANN module ("HLint: ignore Use camelCase"::String) #-}
{-# ANN module ("HLint: ignore Redundant do"::String) #-}
{-# ANN module ("HLint: ignore Use newtype instead of data"::String) #-}


msgGpsL1caRaw :: Word16
msgGpsL1caRaw = 0x7778

-- | SBP class for message MSG_GPS_L1CA_RAW (0x7778).
--
-- This message is sent once per 6 seconds per GPS satellite. ME checks the
-- parity of the data block and sends only blocks that pass the check.
data MsgGpsL1caRaw = MsgGpsL1caRaw
  { _msgGpsL1caRaw_sid       :: !GnssSignal
    -- ^ GNSS signal identifier.
  , _msgGpsL1caRaw_tow       :: !Word32
    -- ^ GPS time-of-week at the start of the subframe.
  , _msgGpsL1caRaw_subframe_id :: !Word8
    -- ^ Subframe ID (1-5).
  , _msgGpsL1caRaw_data      :: ![Word8]
    -- ^ Raw subframe data field of 300 bits (last byte padded with zeros).
  } deriving ( Show, Read, Eq )

instance Binary MsgGpsL1caRaw where
  get = do
    _msgGpsL1caRaw_sid <- get
    _msgGpsL1caRaw_tow <- getWord32le
    _msgGpsL1caRaw_subframe_id <- getWord8
    _msgGpsL1caRaw_data <- replicateM 38 getWord8
    pure MsgGpsL1caRaw {..}

  put MsgGpsL1caRaw {..} = do
    put _msgGpsL1caRaw_sid
    putWord32le _msgGpsL1caRaw_tow
    putWord8 _msgGpsL1caRaw_subframe_id
    mapM_ putWord8 _msgGpsL1caRaw_data

$(makeSBP 'msgGpsL1caRaw ''MsgGpsL1caRaw)
$(makeJSON "_msgGpsL1caRaw_" ''MsgGpsL1caRaw)
$(makeLenses ''MsgGpsL1caRaw)

msgGloL1ofRaw :: Word16
msgGloL1ofRaw = 0x7779

-- | SBP class for message MSG_GLO_L1OF_RAW (0x7779).
--
-- This message is sent once per 2 seconds per GLONASS satellite. ME checks the
-- parity of the data block and sends only blocks that pass the check.
data MsgGloL1ofRaw = MsgGloL1ofRaw
  { _msgGloL1ofRaw_sid         :: !GnssSignal
    -- ^ GNSS signal identifier.
  , _msgGloL1ofRaw_tow         :: !Word32
    -- ^ GPS time-of-week at the start of the subframe.
  , _msgGloL1ofRaw_string_number :: !Word8
    -- ^ String number (1-15).
  , _msgGloL1ofRaw_data        :: ![Word8]
    -- ^ Raw string data field of 85 bits (last byte padded with zeros).
  } deriving ( Show, Read, Eq )

instance Binary MsgGloL1ofRaw where
  get = do
    _msgGloL1ofRaw_sid <- get
    _msgGloL1ofRaw_tow <- getWord32le
    _msgGloL1ofRaw_string_number <- getWord8
    _msgGloL1ofRaw_data <- replicateM 11 getWord8
    pure MsgGloL1ofRaw {..}

  put MsgGloL1ofRaw {..} = do
    put _msgGloL1ofRaw_sid
    putWord32le _msgGloL1ofRaw_tow
    putWord8 _msgGloL1ofRaw_string_number
    mapM_ putWord8 _msgGloL1ofRaw_data

$(makeSBP 'msgGloL1ofRaw ''MsgGloL1ofRaw)
$(makeJSON "_msgGloL1ofRaw_" ''MsgGloL1ofRaw)
$(makeLenses ''MsgGloL1ofRaw)
