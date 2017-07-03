{-# OPTIONS_GHC -fno-warn-unused-imports #-}
{-# LANGUAGE NoImplicitPrelude           #-}
{-# LANGUAGE TemplateHaskell             #-}
{-# LANGUAGE RecordWildCards             #-}

-- |
-- Module:      SwiftNav.SBP.Gnss
-- Copyright:   Copyright (C) 2015 Swift Navigation, Inc.
-- License:     LGPL-3
-- Maintainer:  Mark Fine <dev@swiftnav.com>
-- Stability:   experimental
-- Portability: portable
--
-- Various structs shared between modules

module SwiftNav.SBP.Gnss where

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

-- | GnssSignal16.
--
-- Signal identifier containing constellation, band, and satellite identifier
data GnssSignal16 = GnssSignal16
  { _gnssSignal16_sat :: !Word8
    -- ^ Constellation-specific satellite identifier
  , _gnssSignal16_code :: !Word8
    -- ^ Signal constellation, band and code
  } deriving ( Show, Read, Eq )

instance Binary GnssSignal16 where
  get = do
    _gnssSignal16_sat <- getWord8
    _gnssSignal16_code <- getWord8
    return GnssSignal16 {..}

  put GnssSignal16 {..} = do
    putWord8 _gnssSignal16_sat
    putWord8 _gnssSignal16_code
$(deriveJSON defaultOptions {fieldLabelModifier = fromMaybe "_gnssSignal16_" . P.stripPrefix "_gnssSignal16_"}
             ''GnssSignal16)
$(makeLenses ''GnssSignal16)

-- | GnssSignal.
--
-- Signal identifier containing constellation, band, and satellite identifier
data GnssSignal = GnssSignal
  { _gnssSignal_sat    :: !Word16
    -- ^ Constellation-specific satellite identifier.  Note: unlike GnssSignal16,
    -- GPS satellites are encoded as (PRN - 1). Other constellations do not
    -- have this offset.
  , _gnssSignal_code   :: !Word8
    -- ^ Signal constellation, band and code
  , _gnssSignal_reserved :: !Word8
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
$(deriveJSON defaultOptions {fieldLabelModifier = fromMaybe "_gnssSignal_" . P.stripPrefix "_gnssSignal_"}
             ''GnssSignal)
$(makeLenses ''GnssSignal)

-- | GPSTime.
--
-- A wire-appropriate GPS time, defined as the number of milliseconds since
-- beginning of the week on the Saturday/Sunday transition.
data GpsTime = GpsTime
  { _gpsTime_tow :: !Word32
    -- ^ Milliseconds since start of GPS week
  , _gpsTime_wn :: !Word16
    -- ^ GPS week number
  } deriving ( Show, Read, Eq )

instance Binary GpsTime where
  get = do
    _gpsTime_tow <- getWord32le
    _gpsTime_wn <- getWord16le
    return GpsTime {..}

  put GpsTime {..} = do
    putWord32le _gpsTime_tow
    putWord16le _gpsTime_wn
$(deriveJSON defaultOptions {fieldLabelModifier = fromMaybe "_gpsTime_" . P.stripPrefix "_gpsTime_"}
             ''GpsTime)
$(makeLenses ''GpsTime)

-- | GPSTimeSec.
--
-- A GPS time, defined as the number of seconds since beginning of the week on
-- the Saturday/Sunday transition.
data GpsTimeSec = GpsTimeSec
  { _gpsTimeSec_tow :: !Word32
    -- ^ Seconds since start of GPS week
  , _gpsTimeSec_wn :: !Word16
    -- ^ GPS week number
  } deriving ( Show, Read, Eq )

instance Binary GpsTimeSec where
  get = do
    _gpsTimeSec_tow <- getWord32le
    _gpsTimeSec_wn <- getWord16le
    return GpsTimeSec {..}

  put GpsTimeSec {..} = do
    putWord32le _gpsTimeSec_tow
    putWord16le _gpsTimeSec_wn
$(deriveJSON defaultOptions {fieldLabelModifier = fromMaybe "_gpsTimeSec_" . P.stripPrefix "_gpsTimeSec_"}
             ''GpsTimeSec)
$(makeLenses ''GpsTimeSec)

-- | GPSTimeNano.
--
-- A wire-appropriate receiver clock time, defined as the time since the
-- beginning of the week on the Saturday/Sunday transition. In most cases,
-- observations are epoch aligned so ns field will be 0.
data GpsTimeNano = GpsTimeNano
  { _gpsTimeNano_tow       :: !Word32
    -- ^ Milliseconds since start of GPS week
  , _gpsTimeNano_ns_residual :: !Int32
    -- ^ Nanosecond residual of millisecond-rounded TOW (ranges from -500000 to
    -- 500000)
  , _gpsTimeNano_wn        :: !Word16
    -- ^ GPS week number
  } deriving ( Show, Read, Eq )

instance Binary GpsTimeNano where
  get = do
    _gpsTimeNano_tow <- getWord32le
    _gpsTimeNano_ns_residual <- fromIntegral <$> getWord32le
    _gpsTimeNano_wn <- getWord16le
    return GpsTimeNano {..}

  put GpsTimeNano {..} = do
    putWord32le _gpsTimeNano_tow
    putWord32le $ fromIntegral _gpsTimeNano_ns_residual
    putWord16le _gpsTimeNano_wn
$(deriveJSON defaultOptions {fieldLabelModifier = fromMaybe "_gpsTimeNano_" . P.stripPrefix "_gpsTimeNano_"}
             ''GpsTimeNano)
$(makeLenses ''GpsTimeNano)

-- | CarrierPhase.
--
-- Carrier phase measurement in cycles represented as a 40-bit fixed point
-- number with Q32.8 layout, i.e. 32-bits of whole cycles and 8-bits of
-- fractional cycles. This phase has the same sign as the pseudorange.
data CarrierPhase = CarrierPhase
  { _carrierPhase_i :: !Int32
    -- ^ Carrier phase whole cycles
  , _carrierPhase_f :: !Word8
    -- ^ Carrier phase fractional part
  } deriving ( Show, Read, Eq )

instance Binary CarrierPhase where
  get = do
    _carrierPhase_i <- fromIntegral <$> getWord32le
    _carrierPhase_f <- getWord8
    return CarrierPhase {..}

  put CarrierPhase {..} = do
    putWord32le $ fromIntegral _carrierPhase_i
    putWord8 _carrierPhase_f
$(deriveJSON defaultOptions {fieldLabelModifier = fromMaybe "_carrierPhase_" . P.stripPrefix "_carrierPhase_"}
             ''CarrierPhase)
$(makeLenses ''CarrierPhase)
