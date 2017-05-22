{-# OPTIONS_GHC -fno-warn-unused-imports #-}
-- |
-- Module:      SwiftNav.SBP.Specan
-- Copyright:   Copyright (C) 2015 Swift Navigation, Inc.
-- License:     LGPL-3
-- Maintainer:  Mark Fine <dev@swiftnav.com>
-- Stability:   experimental
-- Portability: portable
--
-- Spectrum analyzer and related interference messages

module SwiftNav.SBP.Specan where

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

msgSpecan :: Word16
msgSpecan = 0x0050

-- | SBP class for message MSG_SPECAN (0x0050).
--
-- Spectrum analyzer packet.
data MsgSpecan = MsgSpecan
  { _msgSpecan_t             :: GpsTime
    -- ^ Receiver time of this observation
  , _msgSpecan_freq_ref      :: Float
    -- ^ Reference frequency of this packet
  , _msgSpecan_freq_step     :: Float
    -- ^ Frequency step of points in this packet
  , _msgSpecan_amplitude_ref :: Float
    -- ^ Reference amplitude of this packet
  , _msgSpecan_amplitude_unit :: Float
    -- ^ Amplitude unit value of points in this packet
  , _msgSpecan_amplitude_value :: [Word8]
    -- ^ Amplitude values (in the above units) of points in this packet
  } deriving ( Show, Read, Eq )

instance Binary MsgSpecan where
  get = do
    _msgSpecan_t <- get
    _msgSpecan_freq_ref <- getFloat32le
    _msgSpecan_freq_step <- getFloat32le
    _msgSpecan_amplitude_ref <- getFloat32le
    _msgSpecan_amplitude_unit <- getFloat32le
    _msgSpecan_amplitude_value <- whileM (not <$> isEmpty) getWord8
    return MsgSpecan {..}

  put MsgSpecan {..} = do
    put _msgSpecan_t
    putFloat32le _msgSpecan_freq_ref
    putFloat32le _msgSpecan_freq_step
    putFloat32le _msgSpecan_amplitude_ref
    putFloat32le _msgSpecan_amplitude_unit
    mapM_ putWord8 _msgSpecan_amplitude_value

$(deriveSBP 'msgSpecan ''MsgSpecan)

$(deriveJSON defaultOptions {fieldLabelModifier = fromMaybe "_msgSpecan_" . P.stripPrefix "_msgSpecan_"}
             ''MsgSpecan)
$(makeLenses ''MsgSpecan)
