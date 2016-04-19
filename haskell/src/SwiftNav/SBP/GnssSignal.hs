{-# OPTIONS_GHC -fno-warn-unused-imports #-}
-- |
-- Module:      SwiftNav.SBP.GnssSignal
-- Copyright:   Copyright (C) 2015 Swift Navigation, Inc.
-- License:     LGPL-3
-- Maintainer:  Mark Fine <dev@swiftnav.com>
-- Stability:   experimental
-- Portability: portable
--
-- Struct to represent a signal (constellation, band, satellite identifier)

module SwiftNav.SBP.GnssSignal where

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

-- | GnssSignal.
--
-- Signal identifier containing constellation, band, and satellite identifier
data GnssSignal = GnssSignal
  { _gnssSignal_sat    :: Word16
    -- ^ Constellation-specific satellite identifier
  , _gnssSignal_code   :: Word8
    -- ^ Signal constellation, band and code
  , _gnssSignal_reserved :: Word8
    -- ^ Reserved
  } deriving ( Show, Read, Eq )

instance Binary GnssSignal where
  get = do
    _gnssSignal_sat <- getWord16le
    _gnssSignal_code <- getWord8
    _gnssSignal_reserved <- getWord8
    return GnssSignal {..}

  put GnssSignal {..} = do
    putWord16le _gnssSignal_sat
    putWord8 _gnssSignal_code
    putWord8 _gnssSignal_reserved
$(deriveJSON defaultOptions {fieldLabelModifier = fromMaybe "_gnssSignal_" . stripPrefix "_gnssSignal_"}
             ''GnssSignal)
$(makeLenses ''GnssSignal)
