-- |
-- Module:      SwiftNav.SBP.Signal
-- Copyright:   Copyright (C) 2015 Swift Navigation, Inc.
-- License:     LGPL-3
-- Maintainer:  Mark Fine <dev@swiftnav.com>
-- Stability:   experimental
-- Portability: portable
--
-- Struct to represent the signal (constellation, band, satellite identifier).

module SwiftNav.SBP.Signal where

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

-- | SBPSignal.
--
-- Signal identifier containing constellation, band, and satellite identifier
data SBPSignal = SBPSignal
  { _sBPSignal_sat         :: Word16
    -- ^ Constellation-specific satellite identifier
  , _sBPSignal_band        :: Word8
    -- ^ Signal band
  , _sBPSignal_constellation :: Word8
    -- ^ Constellation to which the satellite belongs
  } deriving ( Show, Read, Eq )

instance Binary SBPSignal where
  get = do
    _sBPSignal_sat <- getWord16le
    _sBPSignal_band <- getWord8
    _sBPSignal_constellation <- getWord8
    return SBPSignal {..}

  put SBPSignal {..} = do
    putWord16le _sBPSignal_sat
    putWord8 _sBPSignal_band
    putWord8 _sBPSignal_constellation
$(deriveJSON defaultOptions {fieldLabelModifier = fromMaybe "_sBPSignal_" . stripPrefix "_sBPSignal_"}
             ''SBPSignal)
$(makeLenses ''SBPSignal)
