{-# OPTIONS_GHC -fno-warn-unused-imports #-}
{-# LANGUAGE NoImplicitPrelude           #-}
{-# LANGUAGE TemplateHaskell             #-}
{-# LANGUAGE RecordWildCards             #-}

-- |
-- Module:      SwiftNav.SBP.Sbas
-- Copyright:   Copyright (C) 2015-2018 Swift Navigation, Inc.
-- License:     LGPL-3
-- Maintainer:  Swift Navigation <dev@swiftnav.com>
-- Stability:   experimental
-- Portability: portable
--
-- \<SBAS data\>

module SwiftNav.SBP.Sbas
  ( module SwiftNav.SBP.Sbas
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


msgSbasRaw :: Word16
msgSbasRaw = 0x7777

-- | SBP class for message MSG_SBAS_RAW (0x7777).
--
-- This message is sent once per second per SBAS satellite. ME checks the
-- parity of the data block and sends only blocks that pass the check.
data MsgSbasRaw = MsgSbasRaw
  { _msgSbasRaw_sid        :: !GnssSignal
    -- ^ GNSS signal identifier.
  , _msgSbasRaw_tow        :: !Word32
    -- ^ GPS time-of-week at the start of the data block.
  , _msgSbasRaw_message_type :: !Word8
    -- ^ SBAS message type (0-63)
  , _msgSbasRaw_data       :: ![Word8]
    -- ^ Raw SBAS data field of 212 bits (last byte padded with zeros).
  } deriving ( Show, Read, Eq )

instance Binary MsgSbasRaw where
  get = do
    _msgSbasRaw_sid <- get
    _msgSbasRaw_tow <- getWord32le
    _msgSbasRaw_message_type <- getWord8
    _msgSbasRaw_data <- replicateM 27 getWord8
    pure MsgSbasRaw {..}

  put MsgSbasRaw {..} = do
    put _msgSbasRaw_sid
    putWord32le _msgSbasRaw_tow
    putWord8 _msgSbasRaw_message_type
    mapM_ putWord8 _msgSbasRaw_data

$(makeSBP 'msgSbasRaw ''MsgSbasRaw)
$(makeJSON "_msgSbasRaw_" ''MsgSbasRaw)
$(makeLenses ''MsgSbasRaw)
