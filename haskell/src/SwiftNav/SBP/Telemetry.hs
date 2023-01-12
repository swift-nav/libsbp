{-# OPTIONS_GHC -fno-warn-unused-imports #-}
{-# LANGUAGE NoImplicitPrelude           #-}
{-# LANGUAGE TemplateHaskell             #-}
{-# LANGUAGE RecordWildCards             #-}

-- |
-- Module:      SwiftNav.SBP.Telemetry
-- Copyright:   Copyright (C) 2015-2021 Swift Navigation, Inc.
-- License:     MIT
-- Contact:     https://support.swiftnav.com
-- Stability:   experimental
-- Portability: portable
--
-- \< Telemetry messages reported by Starling engine. The messages include
-- various byproducts of state estimation and other logic across Starling and
-- are aimed at efficient issue diagnostics. \>

module SwiftNav.SBP.Telemetry
  ( module SwiftNav.SBP.Telemetry
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


data TelemetrySV = TelemetrySV
  { _telemetrySV_az                 :: !Word8
    -- ^ Azimuth angle (range 0..179)
  , _telemetrySV_el                 :: !Int8
    -- ^ Elevation angle (range -90..90)
  , _telemetrySV_pseudorange_residual :: !Int16
    -- ^ Pseudorange observation residual
  , _telemetrySV_phase_residual     :: !Int16
    -- ^ Carrier-phase or carrier-phase-derived observation residual
  , _telemetrySV_outlier_flags      :: !Word8
    -- ^ Reports if observation is marked as an outlier and is excluded from the
    -- update.
  , _telemetrySV_ephemeris_flags    :: !Word8
    -- ^ Ephemeris metadata
  , _telemetrySV_correction_flags   :: !Word8
    -- ^ Reserved
  , _telemetrySV_sid                :: !GnssSignal
    -- ^ GNSS signal identifier (16 bit)
  } deriving ( Show, Read, Eq )

instance Binary TelemetrySV where
  get = do
    _telemetrySV_az <- getWord8
    _telemetrySV_el <- (fromIntegral <$> getWord8)
    _telemetrySV_pseudorange_residual <- (fromIntegral <$> getWord16le)
    _telemetrySV_phase_residual <- (fromIntegral <$> getWord16le)
    _telemetrySV_outlier_flags <- getWord8
    _telemetrySV_ephemeris_flags <- getWord8
    _telemetrySV_correction_flags <- getWord8
    _telemetrySV_sid <- get
    pure TelemetrySV {..}

  put TelemetrySV {..} = do
    putWord8 _telemetrySV_az
    (putWord8 . fromIntegral) _telemetrySV_el
    (putWord16le . fromIntegral) _telemetrySV_pseudorange_residual
    (putWord16le . fromIntegral) _telemetrySV_phase_residual
    putWord8 _telemetrySV_outlier_flags
    putWord8 _telemetrySV_ephemeris_flags
    putWord8 _telemetrySV_correction_flags
    put _telemetrySV_sid

$(makeJSON "_telemetrySV_" ''TelemetrySV)
$(makeLenses ''TelemetrySV)

msgTelSv :: Word16
msgTelSv = 0x0120

-- | SBP class for message MSG_TEL_SV (0x0120).
--
-- This message includes telemetry pertinent to satellite signals available to
-- Starling.
data MsgTelSv = MsgTelSv
  { _msgTelSv_wn         :: !Word16
    -- ^ GPS week number
  , _msgTelSv_tow        :: !Word32
    -- ^ GPS Time of Week
  , _msgTelSv_n_obs      :: !Word8
    -- ^ Total number of observations. First nibble is the size of the sequence
    -- (n), second nibble is the zero-indexed counter (ith packet of n)
  , _msgTelSv_origin_flags :: !Word8
    -- ^ Flags to identify Starling component the telemetry is reported from.
  , _msgTelSv_sv_tel     :: ![TelemetrySV]
    -- ^ Array of per-signal telemetry entries
  } deriving ( Show, Read, Eq )

instance Binary MsgTelSv where
  get = do
    _msgTelSv_wn <- getWord16le
    _msgTelSv_tow <- getWord32le
    _msgTelSv_n_obs <- getWord8
    _msgTelSv_origin_flags <- getWord8
    _msgTelSv_sv_tel <- whileM (not <$> isEmpty) get
    pure MsgTelSv {..}

  put MsgTelSv {..} = do
    putWord16le _msgTelSv_wn
    putWord32le _msgTelSv_tow
    putWord8 _msgTelSv_n_obs
    putWord8 _msgTelSv_origin_flags
    mapM_ put _msgTelSv_sv_tel

$(makeSBP 'msgTelSv ''MsgTelSv)
$(makeJSON "_msgTelSv_" ''MsgTelSv)
$(makeLenses ''MsgTelSv)
