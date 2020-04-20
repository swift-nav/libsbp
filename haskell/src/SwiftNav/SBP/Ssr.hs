{-# OPTIONS_GHC -fno-warn-unused-imports #-}
{-# LANGUAGE NoImplicitPrelude           #-}
{-# LANGUAGE TemplateHaskell             #-}
{-# LANGUAGE RecordWildCards             #-}

-- |
-- Module:      SwiftNav.SBP.Ssr
-- Copyright:   Copyright (C) 2015-2018 Swift Navigation, Inc.
-- License:     LGPL-3
-- Maintainer:  Swift Navigation <dev@swiftnav.com>
-- Stability:   experimental
-- Portability: portable
--
-- \<Precise State Space Representation (SSR) corrections format\>

module SwiftNav.SBP.Ssr
  ( module SwiftNav.SBP.Ssr
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


-- | CodeBiasesContent.
--
-- Code biases are to be added to pseudorange. The corrections conform with
-- typical RTCMv3 MT1059 and 1065.
data CodeBiasesContent = CodeBiasesContent
  { _codeBiasesContent_code :: !Word8
    -- ^ Signal constellation, band and code
  , _codeBiasesContent_value :: !Int16
    -- ^ Code bias value
  } deriving ( Show, Read, Eq )

instance Binary CodeBiasesContent where
  get = do
    _codeBiasesContent_code <- getWord8
    _codeBiasesContent_value <- (fromIntegral <$> getWord16le)
    pure CodeBiasesContent {..}

  put CodeBiasesContent {..} = do
    putWord8 _codeBiasesContent_code
    (putWord16le . fromIntegral) _codeBiasesContent_value

$(makeJSON "_codeBiasesContent_" ''CodeBiasesContent)
$(makeLenses ''CodeBiasesContent)

-- | PhaseBiasesContent.
--
-- Phase biases are to be added to carrier phase measurements. The corrections
-- conform with typical RTCMv3 MT1059 and 1065.
data PhaseBiasesContent = PhaseBiasesContent
  { _phaseBiasesContent_code                     :: !Word8
    -- ^ Signal constellation, band and code
  , _phaseBiasesContent_integer_indicator        :: !Word8
    -- ^ Indicator for integer property
  , _phaseBiasesContent_widelane_integer_indicator :: !Word8
    -- ^ Indicator for two groups of Wide-Lane(s) integer property
  , _phaseBiasesContent_discontinuity_counter    :: !Word8
    -- ^ Signal phase discontinuity counter. Increased for every discontinuity in
    -- phase.
  , _phaseBiasesContent_bias                     :: !Int32
    -- ^ Phase bias for specified signal
  } deriving ( Show, Read, Eq )

instance Binary PhaseBiasesContent where
  get = do
    _phaseBiasesContent_code <- getWord8
    _phaseBiasesContent_integer_indicator <- getWord8
    _phaseBiasesContent_widelane_integer_indicator <- getWord8
    _phaseBiasesContent_discontinuity_counter <- getWord8
    _phaseBiasesContent_bias <- (fromIntegral <$> getWord32le)
    pure PhaseBiasesContent {..}

  put PhaseBiasesContent {..} = do
    putWord8 _phaseBiasesContent_code
    putWord8 _phaseBiasesContent_integer_indicator
    putWord8 _phaseBiasesContent_widelane_integer_indicator
    putWord8 _phaseBiasesContent_discontinuity_counter
    (putWord32le . fromIntegral) _phaseBiasesContent_bias

$(makeJSON "_phaseBiasesContent_" ''PhaseBiasesContent)
$(makeLenses ''PhaseBiasesContent)

-- | STECHeaderDepA.
--
-- A full set of STEC information will likely span multiple SBP messages, since
-- SBP message a limited to 255 bytes.  The header is used to tie multiple SBP
-- messages into a sequence.
data STECHeaderDepA = STECHeaderDepA
  { _sTECHeaderDepA_time          :: !GpsTimeSec
    -- ^ GNSS reference time of the correction
  , _sTECHeaderDepA_num_msgs      :: !Word8
    -- ^ Number of messages in the dataset
  , _sTECHeaderDepA_seq_num       :: !Word8
    -- ^ Position of this message in the dataset
  , _sTECHeaderDepA_update_interval :: !Word8
    -- ^ Update interval between consecutive corrections. Encoded following RTCM
    -- DF391 specification.
  , _sTECHeaderDepA_iod_atmo      :: !Word8
    -- ^ IOD of the SSR atmospheric correction
  } deriving ( Show, Read, Eq )

instance Binary STECHeaderDepA where
  get = do
    _sTECHeaderDepA_time <- get
    _sTECHeaderDepA_num_msgs <- getWord8
    _sTECHeaderDepA_seq_num <- getWord8
    _sTECHeaderDepA_update_interval <- getWord8
    _sTECHeaderDepA_iod_atmo <- getWord8
    pure STECHeaderDepA {..}

  put STECHeaderDepA {..} = do
    put _sTECHeaderDepA_time
    putWord8 _sTECHeaderDepA_num_msgs
    putWord8 _sTECHeaderDepA_seq_num
    putWord8 _sTECHeaderDepA_update_interval
    putWord8 _sTECHeaderDepA_iod_atmo

$(makeJSON "_sTECHeaderDepA_" ''STECHeaderDepA)
$(makeLenses ''STECHeaderDepA)

-- | STECHeader.
--
-- A full set of STEC information will likely span multiple SBP messages, since
-- SBP message a limited to 255 bytes.  The header is used to tie multiple SBP
-- messages into a sequence.
data STECHeader = STECHeader
  { _sTECHeader_time          :: !GpsTimeSec
    -- ^ GNSS reference time of the correction
  , _sTECHeader_num_msgs      :: !Word8
    -- ^ Number of messages in the dataset
  , _sTECHeader_seq_num       :: !Word8
    -- ^ Position of this message in the dataset
  , _sTECHeader_update_interval :: !Word8
    -- ^ Update interval between consecutive corrections. Encoded following RTCM
    -- DF391 specification.
  , _sTECHeader_iod_atmo      :: !Word8
    -- ^ IOD of the SSR atmospheric correction
  , _sTECHeader_tile_set_id   :: !Word8
    -- ^ Indicates grid IDs are part of the same generation set
  , _sTECHeader_tile_id       :: !Word16
    -- ^ Unique (within a network) identifer for the tile/grid
  } deriving ( Show, Read, Eq )

instance Binary STECHeader where
  get = do
    _sTECHeader_time <- get
    _sTECHeader_num_msgs <- getWord8
    _sTECHeader_seq_num <- getWord8
    _sTECHeader_update_interval <- getWord8
    _sTECHeader_iod_atmo <- getWord8
    _sTECHeader_tile_set_id <- getWord8
    _sTECHeader_tile_id <- getWord16le
    pure STECHeader {..}

  put STECHeader {..} = do
    put _sTECHeader_time
    putWord8 _sTECHeader_num_msgs
    putWord8 _sTECHeader_seq_num
    putWord8 _sTECHeader_update_interval
    putWord8 _sTECHeader_iod_atmo
    putWord8 _sTECHeader_tile_set_id
    putWord16le _sTECHeader_tile_id

$(makeJSON "_sTECHeader_" ''STECHeader)
$(makeLenses ''STECHeader)

-- | GriddedCorrectionHeaderDepA.
--
-- The 3GPP message contains nested variable length arrays which are not
-- suppported in SBP, so each grid point will be identified by the index.
data GriddedCorrectionHeaderDepA = GriddedCorrectionHeaderDepA
  { _griddedCorrectionHeaderDepA_time                  :: !GpsTimeSec
    -- ^ GNSS reference time of the correction
  , _griddedCorrectionHeaderDepA_num_msgs              :: !Word16
    -- ^ Number of messages in the dataset
  , _griddedCorrectionHeaderDepA_seq_num               :: !Word16
    -- ^ Position of this message in the dataset
  , _griddedCorrectionHeaderDepA_update_interval       :: !Word8
    -- ^ Update interval between consecutive corrections. Encoded following RTCM
    -- DF391 specification.
  , _griddedCorrectionHeaderDepA_iod_atmo              :: !Word8
    -- ^ IOD of the SSR atmospheric correction
  , _griddedCorrectionHeaderDepA_tropo_quality_indicator :: !Word8
    -- ^ Quality of the troposphere data. Encoded following RTCM DF389
    -- specifcation in units of m.
  } deriving ( Show, Read, Eq )

instance Binary GriddedCorrectionHeaderDepA where
  get = do
    _griddedCorrectionHeaderDepA_time <- get
    _griddedCorrectionHeaderDepA_num_msgs <- getWord16le
    _griddedCorrectionHeaderDepA_seq_num <- getWord16le
    _griddedCorrectionHeaderDepA_update_interval <- getWord8
    _griddedCorrectionHeaderDepA_iod_atmo <- getWord8
    _griddedCorrectionHeaderDepA_tropo_quality_indicator <- getWord8
    pure GriddedCorrectionHeaderDepA {..}

  put GriddedCorrectionHeaderDepA {..} = do
    put _griddedCorrectionHeaderDepA_time
    putWord16le _griddedCorrectionHeaderDepA_num_msgs
    putWord16le _griddedCorrectionHeaderDepA_seq_num
    putWord8 _griddedCorrectionHeaderDepA_update_interval
    putWord8 _griddedCorrectionHeaderDepA_iod_atmo
    putWord8 _griddedCorrectionHeaderDepA_tropo_quality_indicator

$(makeJSON "_griddedCorrectionHeaderDepA_" ''GriddedCorrectionHeaderDepA)
$(makeLenses ''GriddedCorrectionHeaderDepA)

-- | GriddedCorrectionHeader.
--
-- The 3GPP message contains nested variable length arrays which are not
-- suppported in SBP, so each grid point will be identified by the index.
data GriddedCorrectionHeader = GriddedCorrectionHeader
  { _griddedCorrectionHeader_time                  :: !GpsTimeSec
    -- ^ GNSS reference time of the correction
  , _griddedCorrectionHeader_num_msgs              :: !Word16
    -- ^ Number of messages in the dataset
  , _griddedCorrectionHeader_seq_num               :: !Word16
    -- ^ Position of this message in the dataset
  , _griddedCorrectionHeader_update_interval       :: !Word8
    -- ^ Update interval between consecutive corrections. Encoded following RTCM
    -- DF391 specification.
  , _griddedCorrectionHeader_iod_atmo              :: !Word8
    -- ^ IOD of the SSR atmospheric correction
  , _griddedCorrectionHeader_tile_set_id           :: !Word8
    -- ^ Indicates grid IDs are part of the same generation set
  , _griddedCorrectionHeader_tile_id               :: !Word16
    -- ^ Unique (within a network) identifer for the tile/grid
  , _griddedCorrectionHeader_tropo_quality_indicator :: !Word8
    -- ^ Quality of the troposphere data. Encoded following RTCM DF389
    -- specifcation in units of m.
  } deriving ( Show, Read, Eq )

instance Binary GriddedCorrectionHeader where
  get = do
    _griddedCorrectionHeader_time <- get
    _griddedCorrectionHeader_num_msgs <- getWord16le
    _griddedCorrectionHeader_seq_num <- getWord16le
    _griddedCorrectionHeader_update_interval <- getWord8
    _griddedCorrectionHeader_iod_atmo <- getWord8
    _griddedCorrectionHeader_tile_set_id <- getWord8
    _griddedCorrectionHeader_tile_id <- getWord16le
    _griddedCorrectionHeader_tropo_quality_indicator <- getWord8
    pure GriddedCorrectionHeader {..}

  put GriddedCorrectionHeader {..} = do
    put _griddedCorrectionHeader_time
    putWord16le _griddedCorrectionHeader_num_msgs
    putWord16le _griddedCorrectionHeader_seq_num
    putWord8 _griddedCorrectionHeader_update_interval
    putWord8 _griddedCorrectionHeader_iod_atmo
    putWord8 _griddedCorrectionHeader_tile_set_id
    putWord16le _griddedCorrectionHeader_tile_id
    putWord8 _griddedCorrectionHeader_tropo_quality_indicator

$(makeJSON "_griddedCorrectionHeader_" ''GriddedCorrectionHeader)
$(makeLenses ''GriddedCorrectionHeader)

-- | STECSatElement.
--
-- STEC polynomial for the given satellite.
data STECSatElement = STECSatElement
  { _sTECSatElement_sv_id                :: !SvId
    -- ^ Unique space vehicle identifier
  , _sTECSatElement_stec_quality_indicator :: !Word8
    -- ^ Quality of the STEC data. Encoded following RTCM DF389 specifcation but
    -- in units of TECU instead of m.
  , _sTECSatElement_stec_coeff           :: ![Int16]
    -- ^ Coefficents of the STEC polynomial in the order of C00, C01, C10, C11
  } deriving ( Show, Read, Eq )

instance Binary STECSatElement where
  get = do
    _sTECSatElement_sv_id <- get
    _sTECSatElement_stec_quality_indicator <- getWord8
    _sTECSatElement_stec_coeff <- replicateM 4 (fromIntegral <$> getWord16le)
    pure STECSatElement {..}

  put STECSatElement {..} = do
    put _sTECSatElement_sv_id
    putWord8 _sTECSatElement_stec_quality_indicator
    mapM_ (putWord16le . fromIntegral) _sTECSatElement_stec_coeff

$(makeJSON "_sTECSatElement_" ''STECSatElement)
$(makeLenses ''STECSatElement)

-- | TroposphericDelayCorrectionNoStd.
--
-- Troposphere vertical delays at the grid point.
data TroposphericDelayCorrectionNoStd = TroposphericDelayCorrectionNoStd
  { _troposphericDelayCorrectionNoStd_hydro :: !Int16
    -- ^ Hydrostatic vertical delay
  , _troposphericDelayCorrectionNoStd_wet :: !Int8
    -- ^ Wet vertical delay
  } deriving ( Show, Read, Eq )

instance Binary TroposphericDelayCorrectionNoStd where
  get = do
    _troposphericDelayCorrectionNoStd_hydro <- (fromIntegral <$> getWord16le)
    _troposphericDelayCorrectionNoStd_wet <- (fromIntegral <$> getWord8)
    pure TroposphericDelayCorrectionNoStd {..}

  put TroposphericDelayCorrectionNoStd {..} = do
    (putWord16le . fromIntegral) _troposphericDelayCorrectionNoStd_hydro
    (putWord8 . fromIntegral) _troposphericDelayCorrectionNoStd_wet

$(makeJSON "_troposphericDelayCorrectionNoStd_" ''TroposphericDelayCorrectionNoStd)
$(makeLenses ''TroposphericDelayCorrectionNoStd)

-- | TroposphericDelayCorrection.
--
-- Troposphere vertical delays (mean and standard deviation) at the grid point.
data TroposphericDelayCorrection = TroposphericDelayCorrection
  { _troposphericDelayCorrection_hydro :: !Int16
    -- ^ Hydrostatic vertical delay
  , _troposphericDelayCorrection_wet  :: !Int8
    -- ^ Wet vertical delay
  , _troposphericDelayCorrection_stddev :: !Word8
    -- ^ stddev
  } deriving ( Show, Read, Eq )

instance Binary TroposphericDelayCorrection where
  get = do
    _troposphericDelayCorrection_hydro <- (fromIntegral <$> getWord16le)
    _troposphericDelayCorrection_wet <- (fromIntegral <$> getWord8)
    _troposphericDelayCorrection_stddev <- getWord8
    pure TroposphericDelayCorrection {..}

  put TroposphericDelayCorrection {..} = do
    (putWord16le . fromIntegral) _troposphericDelayCorrection_hydro
    (putWord8 . fromIntegral) _troposphericDelayCorrection_wet
    putWord8 _troposphericDelayCorrection_stddev

$(makeJSON "_troposphericDelayCorrection_" ''TroposphericDelayCorrection)
$(makeLenses ''TroposphericDelayCorrection)

-- | STECResidualNoStd.
--
-- STEC residual for the given satellite at the grid point.
data STECResidualNoStd = STECResidualNoStd
  { _sTECResidualNoStd_sv_id  :: !SvId
    -- ^ space vehicle identifier
  , _sTECResidualNoStd_residual :: !Int16
    -- ^ STEC residual
  } deriving ( Show, Read, Eq )

instance Binary STECResidualNoStd where
  get = do
    _sTECResidualNoStd_sv_id <- get
    _sTECResidualNoStd_residual <- (fromIntegral <$> getWord16le)
    pure STECResidualNoStd {..}

  put STECResidualNoStd {..} = do
    put _sTECResidualNoStd_sv_id
    (putWord16le . fromIntegral) _sTECResidualNoStd_residual

$(makeJSON "_sTECResidualNoStd_" ''STECResidualNoStd)
$(makeLenses ''STECResidualNoStd)

-- | STECResidual.
--
-- STEC residual (mean and standard deviation) for the given satellite at the
-- grid point,
data STECResidual = STECResidual
  { _sTECResidual_sv_id  :: !SvId
    -- ^ space vehicle identifier
  , _sTECResidual_residual :: !Int16
    -- ^ STEC residual
  , _sTECResidual_stddev :: !Word8
    -- ^ stddev
  } deriving ( Show, Read, Eq )

instance Binary STECResidual where
  get = do
    _sTECResidual_sv_id <- get
    _sTECResidual_residual <- (fromIntegral <$> getWord16le)
    _sTECResidual_stddev <- getWord8
    pure STECResidual {..}

  put STECResidual {..} = do
    put _sTECResidual_sv_id
    (putWord16le . fromIntegral) _sTECResidual_residual
    putWord8 _sTECResidual_stddev

$(makeJSON "_sTECResidual_" ''STECResidual)
$(makeLenses ''STECResidual)

-- | GridElementNoStd.
--
-- Contains one tropo delay, plus STEC residuals for each satellite at the grid
-- point.
data GridElementNoStd = GridElementNoStd
  { _gridElementNoStd_index                :: !Word16
    -- ^ Index of the grid point
  , _gridElementNoStd_tropo_delay_correction :: !TroposphericDelayCorrectionNoStd
    -- ^ Wet and hydrostatic vertical delays
  , _gridElementNoStd_stec_residuals       :: ![STECResidualNoStd]
    -- ^ STEC residuals for each satellite
  } deriving ( Show, Read, Eq )

instance Binary GridElementNoStd where
  get = do
    _gridElementNoStd_index <- getWord16le
    _gridElementNoStd_tropo_delay_correction <- get
    _gridElementNoStd_stec_residuals <- whileM (not <$> isEmpty) get
    pure GridElementNoStd {..}

  put GridElementNoStd {..} = do
    putWord16le _gridElementNoStd_index
    put _gridElementNoStd_tropo_delay_correction
    mapM_ put _gridElementNoStd_stec_residuals

$(makeJSON "_gridElementNoStd_" ''GridElementNoStd)
$(makeLenses ''GridElementNoStd)

-- | GridElement.
--
-- Contains one tropo delay (mean and stddev), plus STEC residuals (mean and
-- stddev) for each satellite at the grid point.
data GridElement = GridElement
  { _gridElement_index                :: !Word16
    -- ^ Index of the grid point
  , _gridElement_tropo_delay_correction :: !TroposphericDelayCorrection
    -- ^ Wet and hydrostatic vertical delays (mean, stddev)
  , _gridElement_stec_residuals       :: ![STECResidual]
    -- ^ STEC residuals for each satellite (mean, stddev)
  } deriving ( Show, Read, Eq )

instance Binary GridElement where
  get = do
    _gridElement_index <- getWord16le
    _gridElement_tropo_delay_correction <- get
    _gridElement_stec_residuals <- whileM (not <$> isEmpty) get
    pure GridElement {..}

  put GridElement {..} = do
    putWord16le _gridElement_index
    put _gridElement_tropo_delay_correction
    mapM_ put _gridElement_stec_residuals

$(makeJSON "_gridElement_" ''GridElement)
$(makeLenses ''GridElement)

-- | GridDefinitionHeaderDepA.
--
-- Defines the grid for MSG_SSR_GRIDDED_CORRECTION messages. Also includes an
-- RLE encoded validity list.
data GridDefinitionHeaderDepA = GridDefinitionHeaderDepA
  { _gridDefinitionHeaderDepA_region_size_inverse :: !Word8
    -- ^ region_size (deg) = 10 / region_size_inverse 0 is an invalid value.
  , _gridDefinitionHeaderDepA_area_width        :: !Word16
    -- ^ grid height (deg) = grid idth (deg) = area_width / region_size 0 is an
    -- invalid value.
  , _gridDefinitionHeaderDepA_lat_nw_corner_enc :: !Word16
    -- ^ North-West corner latitdue (deg) = region_size * lat_nw_corner_enc - 90
  , _gridDefinitionHeaderDepA_lon_nw_corner_enc :: !Word16
    -- ^ North-West corner longtitude (deg) = region_size * lon_nw_corner_enc -
    -- 180
  , _gridDefinitionHeaderDepA_num_msgs          :: !Word8
    -- ^ Number of messages in the dataset
  , _gridDefinitionHeaderDepA_seq_num           :: !Word8
    -- ^ Postion of this message in the dataset
  } deriving ( Show, Read, Eq )

instance Binary GridDefinitionHeaderDepA where
  get = do
    _gridDefinitionHeaderDepA_region_size_inverse <- getWord8
    _gridDefinitionHeaderDepA_area_width <- getWord16le
    _gridDefinitionHeaderDepA_lat_nw_corner_enc <- getWord16le
    _gridDefinitionHeaderDepA_lon_nw_corner_enc <- getWord16le
    _gridDefinitionHeaderDepA_num_msgs <- getWord8
    _gridDefinitionHeaderDepA_seq_num <- getWord8
    pure GridDefinitionHeaderDepA {..}

  put GridDefinitionHeaderDepA {..} = do
    putWord8 _gridDefinitionHeaderDepA_region_size_inverse
    putWord16le _gridDefinitionHeaderDepA_area_width
    putWord16le _gridDefinitionHeaderDepA_lat_nw_corner_enc
    putWord16le _gridDefinitionHeaderDepA_lon_nw_corner_enc
    putWord8 _gridDefinitionHeaderDepA_num_msgs
    putWord8 _gridDefinitionHeaderDepA_seq_num

$(makeJSON "_gridDefinitionHeaderDepA_" ''GridDefinitionHeaderDepA)
$(makeLenses ''GridDefinitionHeaderDepA)

-- | GridDefinitionHeader.
--
-- Defines the grid for MSG_SSR_GRIDDED_CORRECTION messages. Also includes an
-- RLE encoded validity list.
data GridDefinitionHeader = GridDefinitionHeader
  { _gridDefinitionHeader_rows        :: !Word16
    -- ^ number of rows of points (lattitude)
  , _gridDefinitionHeader_cols        :: !Word16
    -- ^ number of columns of points (longitude)
  , _gridDefinitionHeader_spacing_lat :: !Int32
    -- ^ spacing between lat corrction points
  , _gridDefinitionHeader_spacing_lon :: !Int32
    -- ^ spacing between lon correction points
  , _gridDefinitionHeader_corner_nw_lat :: !Int32
    -- ^ northwest corner lattidue
  , _gridDefinitionHeader_corner_nw_lon :: !Int32
    -- ^ northwest corner longtitude
  , _gridDefinitionHeader_tile_set_id :: !Word8
    -- ^ Indicates grid IDs are part of the same generation set
  , _gridDefinitionHeader_tile_id     :: !Word16
    -- ^ Unique (within a network) identifer for the tile/grid
  , _gridDefinitionHeader_num_msgs    :: !Word8
    -- ^ Number of messages in the dataset
  , _gridDefinitionHeader_seq_num     :: !Word8
    -- ^ Postion of this message in the dataset
  } deriving ( Show, Read, Eq )

instance Binary GridDefinitionHeader where
  get = do
    _gridDefinitionHeader_rows <- getWord16le
    _gridDefinitionHeader_cols <- getWord16le
    _gridDefinitionHeader_spacing_lat <- (fromIntegral <$> getWord32le)
    _gridDefinitionHeader_spacing_lon <- (fromIntegral <$> getWord32le)
    _gridDefinitionHeader_corner_nw_lat <- (fromIntegral <$> getWord32le)
    _gridDefinitionHeader_corner_nw_lon <- (fromIntegral <$> getWord32le)
    _gridDefinitionHeader_tile_set_id <- getWord8
    _gridDefinitionHeader_tile_id <- getWord16le
    _gridDefinitionHeader_num_msgs <- getWord8
    _gridDefinitionHeader_seq_num <- getWord8
    pure GridDefinitionHeader {..}

  put GridDefinitionHeader {..} = do
    putWord16le _gridDefinitionHeader_rows
    putWord16le _gridDefinitionHeader_cols
    (putWord32le . fromIntegral) _gridDefinitionHeader_spacing_lat
    (putWord32le . fromIntegral) _gridDefinitionHeader_spacing_lon
    (putWord32le . fromIntegral) _gridDefinitionHeader_corner_nw_lat
    (putWord32le . fromIntegral) _gridDefinitionHeader_corner_nw_lon
    putWord8 _gridDefinitionHeader_tile_set_id
    putWord16le _gridDefinitionHeader_tile_id
    putWord8 _gridDefinitionHeader_num_msgs
    putWord8 _gridDefinitionHeader_seq_num

$(makeJSON "_gridDefinitionHeader_" ''GridDefinitionHeader)
$(makeLenses ''GridDefinitionHeader)

msgSsrOrbitClock :: Word16
msgSsrOrbitClock = 0x05DD

-- | SBP class for message MSG_SSR_ORBIT_CLOCK (0x05DD).
--
-- The precise orbit and clock correction message is to be applied as a delta
-- correction to broadcast ephemeris and is typically an equivalent to the 1060
-- and 1066 RTCM message types
data MsgSsrOrbitClock = MsgSsrOrbitClock
  { _msgSsrOrbitClock_time          :: !GpsTimeSec
    -- ^ GNSS reference time of the correction
  , _msgSsrOrbitClock_sid           :: !GnssSignal
    -- ^ GNSS signal identifier (16 bit)
  , _msgSsrOrbitClock_update_interval :: !Word8
    -- ^ Update interval between consecutive corrections. Encoded following RTCM
    -- DF391 specification.
  , _msgSsrOrbitClock_iod_ssr       :: !Word8
    -- ^ IOD of the SSR correction. A change of Issue Of Data SSR is used to
    -- indicate a change in the SSR generating configuration
  , _msgSsrOrbitClock_iod           :: !Word32
    -- ^ Issue of broadcast ephemeris data or IODCRC (Beidou)
  , _msgSsrOrbitClock_radial        :: !Int32
    -- ^ Orbit radial delta correction
  , _msgSsrOrbitClock_along         :: !Int32
    -- ^ Orbit along delta correction
  , _msgSsrOrbitClock_cross         :: !Int32
    -- ^ Orbit along delta correction
  , _msgSsrOrbitClock_dot_radial    :: !Int32
    -- ^ Velocity of orbit radial delta correction
  , _msgSsrOrbitClock_dot_along     :: !Int32
    -- ^ Velocity of orbit along delta correction
  , _msgSsrOrbitClock_dot_cross     :: !Int32
    -- ^ Velocity of orbit cross delta correction
  , _msgSsrOrbitClock_c0            :: !Int32
    -- ^ C0 polynomial coefficient for correction of broadcast satellite clock
  , _msgSsrOrbitClock_c1            :: !Int32
    -- ^ C1 polynomial coefficient for correction of broadcast satellite clock
  , _msgSsrOrbitClock_c2            :: !Int32
    -- ^ C2 polynomial coefficient for correction of broadcast satellite clock
  } deriving ( Show, Read, Eq )

instance Binary MsgSsrOrbitClock where
  get = do
    _msgSsrOrbitClock_time <- get
    _msgSsrOrbitClock_sid <- get
    _msgSsrOrbitClock_update_interval <- getWord8
    _msgSsrOrbitClock_iod_ssr <- getWord8
    _msgSsrOrbitClock_iod <- getWord32le
    _msgSsrOrbitClock_radial <- (fromIntegral <$> getWord32le)
    _msgSsrOrbitClock_along <- (fromIntegral <$> getWord32le)
    _msgSsrOrbitClock_cross <- (fromIntegral <$> getWord32le)
    _msgSsrOrbitClock_dot_radial <- (fromIntegral <$> getWord32le)
    _msgSsrOrbitClock_dot_along <- (fromIntegral <$> getWord32le)
    _msgSsrOrbitClock_dot_cross <- (fromIntegral <$> getWord32le)
    _msgSsrOrbitClock_c0 <- (fromIntegral <$> getWord32le)
    _msgSsrOrbitClock_c1 <- (fromIntegral <$> getWord32le)
    _msgSsrOrbitClock_c2 <- (fromIntegral <$> getWord32le)
    pure MsgSsrOrbitClock {..}

  put MsgSsrOrbitClock {..} = do
    put _msgSsrOrbitClock_time
    put _msgSsrOrbitClock_sid
    putWord8 _msgSsrOrbitClock_update_interval
    putWord8 _msgSsrOrbitClock_iod_ssr
    putWord32le _msgSsrOrbitClock_iod
    (putWord32le . fromIntegral) _msgSsrOrbitClock_radial
    (putWord32le . fromIntegral) _msgSsrOrbitClock_along
    (putWord32le . fromIntegral) _msgSsrOrbitClock_cross
    (putWord32le . fromIntegral) _msgSsrOrbitClock_dot_radial
    (putWord32le . fromIntegral) _msgSsrOrbitClock_dot_along
    (putWord32le . fromIntegral) _msgSsrOrbitClock_dot_cross
    (putWord32le . fromIntegral) _msgSsrOrbitClock_c0
    (putWord32le . fromIntegral) _msgSsrOrbitClock_c1
    (putWord32le . fromIntegral) _msgSsrOrbitClock_c2

$(makeSBP 'msgSsrOrbitClock ''MsgSsrOrbitClock)
$(makeJSON "_msgSsrOrbitClock_" ''MsgSsrOrbitClock)
$(makeLenses ''MsgSsrOrbitClock)

msgSsrOrbitClockDepA :: Word16
msgSsrOrbitClockDepA = 0x05DC

-- | SBP class for message MSG_SSR_ORBIT_CLOCK_DEP_A (0x05DC).
--
-- The precise orbit and clock correction message is to be applied as a delta
-- correction to broadcast ephemeris and is typically an equivalent to the 1060
-- and 1066 RTCM message types
data MsgSsrOrbitClockDepA = MsgSsrOrbitClockDepA
  { _msgSsrOrbitClockDepA_time          :: !GpsTimeSec
    -- ^ GNSS reference time of the correction
  , _msgSsrOrbitClockDepA_sid           :: !GnssSignal
    -- ^ GNSS signal identifier (16 bit)
  , _msgSsrOrbitClockDepA_update_interval :: !Word8
    -- ^ Update interval between consecutive corrections. Encoded following RTCM
    -- DF391 specification.
  , _msgSsrOrbitClockDepA_iod_ssr       :: !Word8
    -- ^ IOD of the SSR correction. A change of Issue Of Data SSR is used to
    -- indicate a change in the SSR generating configuration
  , _msgSsrOrbitClockDepA_iod           :: !Word8
    -- ^ Issue of broadcast ephemeris data
  , _msgSsrOrbitClockDepA_radial        :: !Int32
    -- ^ Orbit radial delta correction
  , _msgSsrOrbitClockDepA_along         :: !Int32
    -- ^ Orbit along delta correction
  , _msgSsrOrbitClockDepA_cross         :: !Int32
    -- ^ Orbit along delta correction
  , _msgSsrOrbitClockDepA_dot_radial    :: !Int32
    -- ^ Velocity of orbit radial delta correction
  , _msgSsrOrbitClockDepA_dot_along     :: !Int32
    -- ^ Velocity of orbit along delta correction
  , _msgSsrOrbitClockDepA_dot_cross     :: !Int32
    -- ^ Velocity of orbit cross delta correction
  , _msgSsrOrbitClockDepA_c0            :: !Int32
    -- ^ C0 polynomial coefficient for correction of broadcast satellite clock
  , _msgSsrOrbitClockDepA_c1            :: !Int32
    -- ^ C1 polynomial coefficient for correction of broadcast satellite clock
  , _msgSsrOrbitClockDepA_c2            :: !Int32
    -- ^ C2 polynomial coefficient for correction of broadcast satellite clock
  } deriving ( Show, Read, Eq )

instance Binary MsgSsrOrbitClockDepA where
  get = do
    _msgSsrOrbitClockDepA_time <- get
    _msgSsrOrbitClockDepA_sid <- get
    _msgSsrOrbitClockDepA_update_interval <- getWord8
    _msgSsrOrbitClockDepA_iod_ssr <- getWord8
    _msgSsrOrbitClockDepA_iod <- getWord8
    _msgSsrOrbitClockDepA_radial <- (fromIntegral <$> getWord32le)
    _msgSsrOrbitClockDepA_along <- (fromIntegral <$> getWord32le)
    _msgSsrOrbitClockDepA_cross <- (fromIntegral <$> getWord32le)
    _msgSsrOrbitClockDepA_dot_radial <- (fromIntegral <$> getWord32le)
    _msgSsrOrbitClockDepA_dot_along <- (fromIntegral <$> getWord32le)
    _msgSsrOrbitClockDepA_dot_cross <- (fromIntegral <$> getWord32le)
    _msgSsrOrbitClockDepA_c0 <- (fromIntegral <$> getWord32le)
    _msgSsrOrbitClockDepA_c1 <- (fromIntegral <$> getWord32le)
    _msgSsrOrbitClockDepA_c2 <- (fromIntegral <$> getWord32le)
    pure MsgSsrOrbitClockDepA {..}

  put MsgSsrOrbitClockDepA {..} = do
    put _msgSsrOrbitClockDepA_time
    put _msgSsrOrbitClockDepA_sid
    putWord8 _msgSsrOrbitClockDepA_update_interval
    putWord8 _msgSsrOrbitClockDepA_iod_ssr
    putWord8 _msgSsrOrbitClockDepA_iod
    (putWord32le . fromIntegral) _msgSsrOrbitClockDepA_radial
    (putWord32le . fromIntegral) _msgSsrOrbitClockDepA_along
    (putWord32le . fromIntegral) _msgSsrOrbitClockDepA_cross
    (putWord32le . fromIntegral) _msgSsrOrbitClockDepA_dot_radial
    (putWord32le . fromIntegral) _msgSsrOrbitClockDepA_dot_along
    (putWord32le . fromIntegral) _msgSsrOrbitClockDepA_dot_cross
    (putWord32le . fromIntegral) _msgSsrOrbitClockDepA_c0
    (putWord32le . fromIntegral) _msgSsrOrbitClockDepA_c1
    (putWord32le . fromIntegral) _msgSsrOrbitClockDepA_c2

$(makeSBP 'msgSsrOrbitClockDepA ''MsgSsrOrbitClockDepA)
$(makeJSON "_msgSsrOrbitClockDepA_" ''MsgSsrOrbitClockDepA)
$(makeLenses ''MsgSsrOrbitClockDepA)

msgSsrCodeBiases :: Word16
msgSsrCodeBiases = 0x05E1

-- | SBP class for message MSG_SSR_CODE_BIASES (0x05E1).
--
-- The precise code biases message is to be added to the pseudorange of the
-- corresponding signal to get corrected pseudorange. It is typically an
-- equivalent to the 1059 and 1065 RTCM message types
data MsgSsrCodeBiases = MsgSsrCodeBiases
  { _msgSsrCodeBiases_time          :: !GpsTimeSec
    -- ^ GNSS reference time of the correction
  , _msgSsrCodeBiases_sid           :: !GnssSignal
    -- ^ GNSS signal identifier (16 bit)
  , _msgSsrCodeBiases_update_interval :: !Word8
    -- ^ Update interval between consecutive corrections. Encoded following RTCM
    -- DF391 specification.
  , _msgSsrCodeBiases_iod_ssr       :: !Word8
    -- ^ IOD of the SSR correction. A change of Issue Of Data SSR is used to
    -- indicate a change in the SSR generating configuration
  , _msgSsrCodeBiases_biases        :: ![CodeBiasesContent]
    -- ^ Code biases for the different satellite signals
  } deriving ( Show, Read, Eq )

instance Binary MsgSsrCodeBiases where
  get = do
    _msgSsrCodeBiases_time <- get
    _msgSsrCodeBiases_sid <- get
    _msgSsrCodeBiases_update_interval <- getWord8
    _msgSsrCodeBiases_iod_ssr <- getWord8
    _msgSsrCodeBiases_biases <- whileM (not <$> isEmpty) get
    pure MsgSsrCodeBiases {..}

  put MsgSsrCodeBiases {..} = do
    put _msgSsrCodeBiases_time
    put _msgSsrCodeBiases_sid
    putWord8 _msgSsrCodeBiases_update_interval
    putWord8 _msgSsrCodeBiases_iod_ssr
    mapM_ put _msgSsrCodeBiases_biases

$(makeSBP 'msgSsrCodeBiases ''MsgSsrCodeBiases)
$(makeJSON "_msgSsrCodeBiases_" ''MsgSsrCodeBiases)
$(makeLenses ''MsgSsrCodeBiases)

msgSsrPhaseBiases :: Word16
msgSsrPhaseBiases = 0x05E6

-- | SBP class for message MSG_SSR_PHASE_BIASES (0x05E6).
--
-- The precise phase biases message contains the biases to be added to the
-- carrier phase of the corresponding signal to get corrected carrier phase
-- measurement, as well as the satellite yaw angle to be applied to compute the
-- phase wind-up correction. It is typically an equivalent to the 1265 RTCM
-- message types
data MsgSsrPhaseBiases = MsgSsrPhaseBiases
  { _msgSsrPhaseBiases_time          :: !GpsTimeSec
    -- ^ GNSS reference time of the correction
  , _msgSsrPhaseBiases_sid           :: !GnssSignal
    -- ^ GNSS signal identifier (16 bit)
  , _msgSsrPhaseBiases_update_interval :: !Word8
    -- ^ Update interval between consecutive corrections. Encoded following RTCM
    -- DF391 specification.
  , _msgSsrPhaseBiases_iod_ssr       :: !Word8
    -- ^ IOD of the SSR correction. A change of Issue Of Data SSR is used to
    -- indicate a change in the SSR generating configuration
  , _msgSsrPhaseBiases_dispersive_bias :: !Word8
    -- ^ Indicator for the dispersive phase biases property.
  , _msgSsrPhaseBiases_mw_consistency :: !Word8
    -- ^ Consistency indicator for Melbourne-Wubbena linear combinations
  , _msgSsrPhaseBiases_yaw           :: !Word16
    -- ^ Satellite yaw angle
  , _msgSsrPhaseBiases_yaw_rate      :: !Int8
    -- ^ Satellite yaw angle rate
  , _msgSsrPhaseBiases_biases        :: ![PhaseBiasesContent]
    -- ^ Phase biases corrections for a satellite being tracked.
  } deriving ( Show, Read, Eq )

instance Binary MsgSsrPhaseBiases where
  get = do
    _msgSsrPhaseBiases_time <- get
    _msgSsrPhaseBiases_sid <- get
    _msgSsrPhaseBiases_update_interval <- getWord8
    _msgSsrPhaseBiases_iod_ssr <- getWord8
    _msgSsrPhaseBiases_dispersive_bias <- getWord8
    _msgSsrPhaseBiases_mw_consistency <- getWord8
    _msgSsrPhaseBiases_yaw <- getWord16le
    _msgSsrPhaseBiases_yaw_rate <- (fromIntegral <$> getWord8)
    _msgSsrPhaseBiases_biases <- whileM (not <$> isEmpty) get
    pure MsgSsrPhaseBiases {..}

  put MsgSsrPhaseBiases {..} = do
    put _msgSsrPhaseBiases_time
    put _msgSsrPhaseBiases_sid
    putWord8 _msgSsrPhaseBiases_update_interval
    putWord8 _msgSsrPhaseBiases_iod_ssr
    putWord8 _msgSsrPhaseBiases_dispersive_bias
    putWord8 _msgSsrPhaseBiases_mw_consistency
    putWord16le _msgSsrPhaseBiases_yaw
    (putWord8 . fromIntegral) _msgSsrPhaseBiases_yaw_rate
    mapM_ put _msgSsrPhaseBiases_biases

$(makeSBP 'msgSsrPhaseBiases ''MsgSsrPhaseBiases)
$(makeJSON "_msgSsrPhaseBiases_" ''MsgSsrPhaseBiases)
$(makeLenses ''MsgSsrPhaseBiases)

msgSsrStecCorrectionDepA :: Word16
msgSsrStecCorrectionDepA = 0x05EB

-- | SBP class for message MSG_SSR_STEC_CORRECTION_DEP_A (0x05EB).
--
-- The STEC per space vehicle, given as polynomial approximation for a given
-- grid.  This should be combined with MSG_SSR_GRIDDED_CORRECTION message to
-- get the state space representation of the atmospheric delay. It is typically
-- equivalent to the QZSS CLAS Sub Type 8 messages
data MsgSsrStecCorrectionDepA = MsgSsrStecCorrectionDepA
  { _msgSsrStecCorrectionDepA_header      :: !STECHeaderDepA
    -- ^ Header of a STEC message
  , _msgSsrStecCorrectionDepA_stec_sat_list :: ![STECSatElement]
    -- ^ Array of STEC information for each space vehicle
  } deriving ( Show, Read, Eq )

instance Binary MsgSsrStecCorrectionDepA where
  get = do
    _msgSsrStecCorrectionDepA_header <- get
    _msgSsrStecCorrectionDepA_stec_sat_list <- whileM (not <$> isEmpty) get
    pure MsgSsrStecCorrectionDepA {..}

  put MsgSsrStecCorrectionDepA {..} = do
    put _msgSsrStecCorrectionDepA_header
    mapM_ put _msgSsrStecCorrectionDepA_stec_sat_list

$(makeSBP 'msgSsrStecCorrectionDepA ''MsgSsrStecCorrectionDepA)
$(makeJSON "_msgSsrStecCorrectionDepA_" ''MsgSsrStecCorrectionDepA)
$(makeLenses ''MsgSsrStecCorrectionDepA)

msgSsrStecCorrection :: Word16
msgSsrStecCorrection = 0x05EC

-- | SBP class for message MSG_SSR_STEC_CORRECTION (0x05EC).
--
-- The STEC per space vehicle, given as polynomial approximation for a given
-- grid.  This should be combined with MSG_SSR_GRIDDED_CORRECTION message to
-- get the state space representation of the atmospheric delay. It is typically
-- equivalent to the QZSS CLAS Sub Type 8 messages
data MsgSsrStecCorrection = MsgSsrStecCorrection
  { _msgSsrStecCorrection_header      :: !STECHeader
    -- ^ Header of a STEC message
  , _msgSsrStecCorrection_stec_sat_list :: ![STECSatElement]
    -- ^ Array of STEC information for each space vehicle
  } deriving ( Show, Read, Eq )

instance Binary MsgSsrStecCorrection where
  get = do
    _msgSsrStecCorrection_header <- get
    _msgSsrStecCorrection_stec_sat_list <- whileM (not <$> isEmpty) get
    pure MsgSsrStecCorrection {..}

  put MsgSsrStecCorrection {..} = do
    put _msgSsrStecCorrection_header
    mapM_ put _msgSsrStecCorrection_stec_sat_list

$(makeSBP 'msgSsrStecCorrection ''MsgSsrStecCorrection)
$(makeJSON "_msgSsrStecCorrection_" ''MsgSsrStecCorrection)
$(makeLenses ''MsgSsrStecCorrection)

msgSsrGriddedCorrectionNoStd :: Word16
msgSsrGriddedCorrectionNoStd = 0x05F0

-- | SBP class for message MSG_SSR_GRIDDED_CORRECTION_NO_STD (0x05F0).
--
-- This message was deprecated when variances (stddev) were added.
data MsgSsrGriddedCorrectionNoStd = MsgSsrGriddedCorrectionNoStd
  { _msgSsrGriddedCorrectionNoStd_header :: !GriddedCorrectionHeader
    -- ^ Header of a Gridded Correction message
  , _msgSsrGriddedCorrectionNoStd_element :: !GridElementNoStd
    -- ^ Tropo and STEC residuals for the given grid point
  } deriving ( Show, Read, Eq )

instance Binary MsgSsrGriddedCorrectionNoStd where
  get = do
    _msgSsrGriddedCorrectionNoStd_header <- get
    _msgSsrGriddedCorrectionNoStd_element <- get
    pure MsgSsrGriddedCorrectionNoStd {..}

  put MsgSsrGriddedCorrectionNoStd {..} = do
    put _msgSsrGriddedCorrectionNoStd_header
    put _msgSsrGriddedCorrectionNoStd_element

$(makeSBP 'msgSsrGriddedCorrectionNoStd ''MsgSsrGriddedCorrectionNoStd)
$(makeJSON "_msgSsrGriddedCorrectionNoStd_" ''MsgSsrGriddedCorrectionNoStd)
$(makeLenses ''MsgSsrGriddedCorrectionNoStd)

msgSsrGriddedCorrectionDepA :: Word16
msgSsrGriddedCorrectionDepA = 0x05FA

-- | SBP class for message MSG_SSR_GRIDDED_CORRECTION_DEP_A (0x05FA).
--
-- STEC residuals are per space vehicle, tropo is not. It is typically
-- equivalent to the QZSS CLAS Sub Type 9 messages
data MsgSsrGriddedCorrectionDepA = MsgSsrGriddedCorrectionDepA
  { _msgSsrGriddedCorrectionDepA_header :: !GriddedCorrectionHeaderDepA
    -- ^ Header of a Gridded Correction message
  , _msgSsrGriddedCorrectionDepA_element :: !GridElement
    -- ^ Tropo and STEC residuals for the given grid point (mean and standard
    -- deviation)
  } deriving ( Show, Read, Eq )

instance Binary MsgSsrGriddedCorrectionDepA where
  get = do
    _msgSsrGriddedCorrectionDepA_header <- get
    _msgSsrGriddedCorrectionDepA_element <- get
    pure MsgSsrGriddedCorrectionDepA {..}

  put MsgSsrGriddedCorrectionDepA {..} = do
    put _msgSsrGriddedCorrectionDepA_header
    put _msgSsrGriddedCorrectionDepA_element

$(makeSBP 'msgSsrGriddedCorrectionDepA ''MsgSsrGriddedCorrectionDepA)
$(makeJSON "_msgSsrGriddedCorrectionDepA_" ''MsgSsrGriddedCorrectionDepA)
$(makeLenses ''MsgSsrGriddedCorrectionDepA)

msgSsrGriddedCorrection :: Word16
msgSsrGriddedCorrection = 0x05FB

-- | SBP class for message MSG_SSR_GRIDDED_CORRECTION (0x05FB).
--
-- STEC residuals are per space vehicle, tropo is not. It is typically
-- equivalent to the QZSS CLAS Sub Type 9 messages
data MsgSsrGriddedCorrection = MsgSsrGriddedCorrection
  { _msgSsrGriddedCorrection_header :: !GriddedCorrectionHeader
    -- ^ Header of a Gridded Correction message
  , _msgSsrGriddedCorrection_element :: !GridElement
    -- ^ Tropo and STEC residuals for the given grid point (mean and standard
    -- deviation)
  } deriving ( Show, Read, Eq )

instance Binary MsgSsrGriddedCorrection where
  get = do
    _msgSsrGriddedCorrection_header <- get
    _msgSsrGriddedCorrection_element <- get
    pure MsgSsrGriddedCorrection {..}

  put MsgSsrGriddedCorrection {..} = do
    put _msgSsrGriddedCorrection_header
    put _msgSsrGriddedCorrection_element

$(makeSBP 'msgSsrGriddedCorrection ''MsgSsrGriddedCorrection)
$(makeJSON "_msgSsrGriddedCorrection_" ''MsgSsrGriddedCorrection)
$(makeLenses ''MsgSsrGriddedCorrection)

msgSsrGridDefinitionDepA :: Word16
msgSsrGridDefinitionDepA = 0x05F5

-- | SBP class for message MSG_SSR_GRID_DEFINITION_DEP_A (0x05F5).
--
-- Based on the 3GPP proposal R2-1906781 which is in turn based on OMA-LPPe-
-- ValidityArea from OMA-TS-LPPe-V2_0-20141202-C
data MsgSsrGridDefinitionDepA = MsgSsrGridDefinitionDepA
  { _msgSsrGridDefinitionDepA_header :: !GridDefinitionHeaderDepA
    -- ^ Header of a Gridded Correction message
  , _msgSsrGridDefinitionDepA_rle_list :: ![Word8]
    -- ^ Run Length Encode list of quadrants that contain valid data. The spec
    -- describes the encoding scheme in detail, but essentially the index of
    -- the quadrants that contain transitions between valid and invalid (and
    -- vice versa) are encoded as u8 integers.
  } deriving ( Show, Read, Eq )

instance Binary MsgSsrGridDefinitionDepA where
  get = do
    _msgSsrGridDefinitionDepA_header <- get
    _msgSsrGridDefinitionDepA_rle_list <- whileM (not <$> isEmpty) getWord8
    pure MsgSsrGridDefinitionDepA {..}

  put MsgSsrGridDefinitionDepA {..} = do
    put _msgSsrGridDefinitionDepA_header
    mapM_ putWord8 _msgSsrGridDefinitionDepA_rle_list

$(makeSBP 'msgSsrGridDefinitionDepA ''MsgSsrGridDefinitionDepA)
$(makeJSON "_msgSsrGridDefinitionDepA_" ''MsgSsrGridDefinitionDepA)
$(makeLenses ''MsgSsrGridDefinitionDepA)

msgSsrGridDefinition :: Word16
msgSsrGridDefinition = 0x05F6

-- | SBP class for message MSG_SSR_GRID_DEFINITION (0x05F6).
--
-- Based on the 3GPP proposal R2-1906781 which is in turn based on OMA-LPPe-
-- ValidityArea from OMA-TS-LPPe-V2_0-20141202-C
data MsgSsrGridDefinition = MsgSsrGridDefinition
  { _msgSsrGridDefinition_header        :: !GridDefinitionHeader
    -- ^ Header of a Gridded Correction message
  , _msgSsrGridDefinition_validity_vector :: ![Word8]
    -- ^ Bit mask of valid grid points; see 3GPP draft.  If not present, all grid
    -- points are valid.
  } deriving ( Show, Read, Eq )

instance Binary MsgSsrGridDefinition where
  get = do
    _msgSsrGridDefinition_header <- get
    _msgSsrGridDefinition_validity_vector <- whileM (not <$> isEmpty) getWord8
    pure MsgSsrGridDefinition {..}

  put MsgSsrGridDefinition {..} = do
    put _msgSsrGridDefinition_header
    mapM_ putWord8 _msgSsrGridDefinition_validity_vector

$(makeSBP 'msgSsrGridDefinition ''MsgSsrGridDefinition)
$(makeJSON "_msgSsrGridDefinition_" ''MsgSsrGridDefinition)
$(makeLenses ''MsgSsrGridDefinition)
