{-# OPTIONS_GHC -fno-warn-unused-imports #-}
{-# LANGUAGE NoImplicitPrelude           #-}
{-# LANGUAGE TemplateHaskell             #-}
{-# LANGUAGE RecordWildCards             #-}

-- |
-- Module:      SwiftNav.SBP.Ssr
-- Copyright:   Copyright (C) 2015-2021 Swift Navigation, Inc.
-- License:     MIT
-- Contact:     https://support.swiftnav.com
-- Stability:   experimental
-- Portability: portable
--
-- \< Precise State Space Representation (SSR) corrections format \>

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
-- RTCMv3 MT 1059 / 1065.
data CodeBiasesContent = CodeBiasesContent
  { _codeBiasesContent_code :: !Word8
    -- ^ Signal encoded following RTCM specifications (DF380, DF381, DF382 and
    -- DF467).
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
-- Phase biases are to be added to carrier phase measurements.
data PhaseBiasesContent = PhaseBiasesContent
  { _phaseBiasesContent_code                     :: !Word8
    -- ^ Signal encoded following RTCM specifications (DF380, DF381, DF382 and
    -- DF467)
  , _phaseBiasesContent_integer_indicator        :: !Word8
    -- ^ Indicator for integer property
  , _phaseBiasesContent_widelane_integer_indicator :: !Word8
    -- ^ Indicator for two groups of Wide-Lane(s) integer property
  , _phaseBiasesContent_discontinuity_counter    :: !Word8
    -- ^ Signal phase discontinuity counter. Increased for every discontinuity
    -- in phase.
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

-- | STECHeader.
--
-- A full set of STEC information will likely span multiple SBP messages,
-- since SBP message a limited to 255 bytes.  The header is used to tie
-- multiple SBP messages into a sequence.
data STECHeader = STECHeader
  { _sTECHeader_tile_set_id   :: !Word16
    -- ^ Unique identifier of the tile set this tile belongs to.
  , _sTECHeader_tile_id       :: !Word16
    -- ^ Unique identifier of this tile in the tile set.
  , _sTECHeader_time          :: !GpsTimeSec
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
  } deriving ( Show, Read, Eq )

instance Binary STECHeader where
  get = do
    _sTECHeader_tile_set_id <- getWord16le
    _sTECHeader_tile_id <- getWord16le
    _sTECHeader_time <- get
    _sTECHeader_num_msgs <- getWord8
    _sTECHeader_seq_num <- getWord8
    _sTECHeader_update_interval <- getWord8
    _sTECHeader_iod_atmo <- getWord8
    pure STECHeader {..}

  put STECHeader {..} = do
    putWord16le _sTECHeader_tile_set_id
    putWord16le _sTECHeader_tile_id
    put _sTECHeader_time
    putWord8 _sTECHeader_num_msgs
    putWord8 _sTECHeader_seq_num
    putWord8 _sTECHeader_update_interval
    putWord8 _sTECHeader_iod_atmo

$(makeJSON "_sTECHeader_" ''STECHeader)
$(makeLenses ''STECHeader)

-- | GriddedCorrectionHeader.
--
-- The LPP message contains nested variable length arrays which are not
-- supported in SBP, so each grid point will be identified by the index.
data GriddedCorrectionHeader = GriddedCorrectionHeader
  { _griddedCorrectionHeader_tile_set_id           :: !Word16
    -- ^ Unique identifier of the tile set this tile belongs to.
  , _griddedCorrectionHeader_tile_id               :: !Word16
    -- ^ Unique identifier of this tile in the tile set.
  , _griddedCorrectionHeader_time                  :: !GpsTimeSec
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
  , _griddedCorrectionHeader_tropo_quality_indicator :: !Word8
    -- ^ Quality of the troposphere data. Encoded following RTCM DF389
    -- specification in units of m.
  } deriving ( Show, Read, Eq )

instance Binary GriddedCorrectionHeader where
  get = do
    _griddedCorrectionHeader_tile_set_id <- getWord16le
    _griddedCorrectionHeader_tile_id <- getWord16le
    _griddedCorrectionHeader_time <- get
    _griddedCorrectionHeader_num_msgs <- getWord16le
    _griddedCorrectionHeader_seq_num <- getWord16le
    _griddedCorrectionHeader_update_interval <- getWord8
    _griddedCorrectionHeader_iod_atmo <- getWord8
    _griddedCorrectionHeader_tropo_quality_indicator <- getWord8
    pure GriddedCorrectionHeader {..}

  put GriddedCorrectionHeader {..} = do
    putWord16le _griddedCorrectionHeader_tile_set_id
    putWord16le _griddedCorrectionHeader_tile_id
    put _griddedCorrectionHeader_time
    putWord16le _griddedCorrectionHeader_num_msgs
    putWord16le _griddedCorrectionHeader_seq_num
    putWord8 _griddedCorrectionHeader_update_interval
    putWord8 _griddedCorrectionHeader_iod_atmo
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
    -- ^ Quality of the STEC data. Encoded following RTCM DF389 specification
    -- but in units of TECU instead of m.
  , _sTECSatElement_stec_coeff           :: ![Int16]
    -- ^ Coefficients of the STEC polynomial in the order of C00, C01, C10, C11.
    -- C00 = 0.05 TECU, C01/C10 = 0.02 TECU/deg, C11 0.02 TECU/deg^2
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
-- Troposphere vertical delays (mean and standard deviation) at the grid
-- point.
data TroposphericDelayCorrection = TroposphericDelayCorrection
  { _troposphericDelayCorrection_hydro :: !Int16
    -- ^ Hydrostatic vertical delay. Add 2.3 m to get actual value.
  , _troposphericDelayCorrection_wet  :: !Int8
    -- ^ Wet vertical delay. Add 0.252 m to get actual value.
  , _troposphericDelayCorrection_stddev :: !Word8
    -- ^ Modified DF389. class 3 MSB, value 5 LSB. stddev = (3^class * (1 +
    -- value/16) - 1)
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
-- grid point.
data STECResidual = STECResidual
  { _sTECResidual_sv_id  :: !SvId
    -- ^ space vehicle identifier
  , _sTECResidual_residual :: !Int16
    -- ^ STEC residual
  , _sTECResidual_stddev :: !Word8
    -- ^ Modified DF389. class 3 MSB, value 5 LSB. stddev = (3^class * (1 +
    -- value/16) - 1) * 10
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

msgSsrOrbitClock :: Word16
msgSsrOrbitClock = 0x05DD

-- | SBP class for message MSG_SSR_ORBIT_CLOCK (0x05DD).
--
-- The precise orbit and clock correction message is to be applied as a delta
-- correction to broadcast ephemeris and is an equivalent to the 1060 /1066
-- RTCM message types.
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

msgSsrCodeBiases :: Word16
msgSsrCodeBiases = 0x05E1

-- | SBP class for message MSG_SSR_CODE_BIASES (0x05E1).
--
-- The precise code biases message is to be added to the pseudorange of the
-- corresponding signal to get corrected pseudorange. It is an equivalent to
-- the 1059 / 1065 RTCM message types.
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
-- measurement, as well as the satellite yaw angle to be applied to compute
-- the phase wind-up correction. It is typically an equivalent to the 1265
-- RTCM message types.
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

msgSsrStecCorrectionDep :: Word16
msgSsrStecCorrectionDep = 0x05FB

-- | SBP class for message MSG_SSR_STEC_CORRECTION_DEP (0x05FB).
--
-- The Slant Total Electron Content per space vehicle, given as polynomial
-- approximation for a given tile. This should be combined with the
-- MSG_SSR_GRIDDED_CORRECTION message to get the state space representation of
-- the atmospheric delay.
--
-- It is typically equivalent to the QZSS CLAS Sub Type 8 messages.
data MsgSsrStecCorrectionDep = MsgSsrStecCorrectionDep
  { _msgSsrStecCorrectionDep_header      :: !STECHeader
    -- ^ Header of a STEC polynomial coefficient message.
  , _msgSsrStecCorrectionDep_stec_sat_list :: ![STECSatElement]
    -- ^ Array of STEC polynomial coefficients for each space vehicle.
  } deriving ( Show, Read, Eq )

instance Binary MsgSsrStecCorrectionDep where
  get = do
    _msgSsrStecCorrectionDep_header <- get
    _msgSsrStecCorrectionDep_stec_sat_list <- whileM (not <$> isEmpty) get
    pure MsgSsrStecCorrectionDep {..}

  put MsgSsrStecCorrectionDep {..} = do
    put _msgSsrStecCorrectionDep_header
    mapM_ put _msgSsrStecCorrectionDep_stec_sat_list

$(makeSBP 'msgSsrStecCorrectionDep ''MsgSsrStecCorrectionDep)
$(makeJSON "_msgSsrStecCorrectionDep_" ''MsgSsrStecCorrectionDep)
$(makeLenses ''MsgSsrStecCorrectionDep)

data BoundsHeader = BoundsHeader
  { _boundsHeader_time          :: !GpsTimeSec
    -- ^ GNSS reference time of the bound
  , _boundsHeader_num_msgs      :: !Word8
    -- ^ Number of messages in the dataset
  , _boundsHeader_seq_num       :: !Word8
    -- ^ Position of this message in the dataset
  , _boundsHeader_update_interval :: !Word8
    -- ^ Update interval between consecutive bounds. Similar to RTCM DF391.
  , _boundsHeader_sol_id        :: !Word8
    -- ^ SSR Solution ID.
  } deriving ( Show, Read, Eq )

instance Binary BoundsHeader where
  get = do
    _boundsHeader_time <- get
    _boundsHeader_num_msgs <- getWord8
    _boundsHeader_seq_num <- getWord8
    _boundsHeader_update_interval <- getWord8
    _boundsHeader_sol_id <- getWord8
    pure BoundsHeader {..}

  put BoundsHeader {..} = do
    put _boundsHeader_time
    putWord8 _boundsHeader_num_msgs
    putWord8 _boundsHeader_seq_num
    putWord8 _boundsHeader_update_interval
    putWord8 _boundsHeader_sol_id

$(makeJSON "_boundsHeader_" ''BoundsHeader)
$(makeLenses ''BoundsHeader)

msgSsrStecCorrection :: Word16
msgSsrStecCorrection = 0x05FD

data MsgSsrStecCorrection = MsgSsrStecCorrection
  { _msgSsrStecCorrection_header      :: !BoundsHeader
    -- ^ Header of a STEC correction with bounds message.
  , _msgSsrStecCorrection_ssr_iod_atmo :: !Word8
    -- ^ IOD of the SSR atmospheric correction
  , _msgSsrStecCorrection_tile_set_id :: !Word16
    -- ^ Tile set ID
  , _msgSsrStecCorrection_tile_id     :: !Word16
    -- ^ Tile ID
  , _msgSsrStecCorrection_n_sats      :: !Word8
    -- ^ Number of satellites.
  , _msgSsrStecCorrection_stec_sat_list :: ![STECSatElement]
    -- ^ Array of STEC polynomial coefficients for each space vehicle.
  } deriving ( Show, Read, Eq )

instance Binary MsgSsrStecCorrection where
  get = do
    _msgSsrStecCorrection_header <- get
    _msgSsrStecCorrection_ssr_iod_atmo <- getWord8
    _msgSsrStecCorrection_tile_set_id <- getWord16le
    _msgSsrStecCorrection_tile_id <- getWord16le
    _msgSsrStecCorrection_n_sats <- getWord8
    _msgSsrStecCorrection_stec_sat_list <- whileM (not <$> isEmpty) get
    pure MsgSsrStecCorrection {..}

  put MsgSsrStecCorrection {..} = do
    put _msgSsrStecCorrection_header
    putWord8 _msgSsrStecCorrection_ssr_iod_atmo
    putWord16le _msgSsrStecCorrection_tile_set_id
    putWord16le _msgSsrStecCorrection_tile_id
    putWord8 _msgSsrStecCorrection_n_sats
    mapM_ put _msgSsrStecCorrection_stec_sat_list

$(makeSBP 'msgSsrStecCorrection ''MsgSsrStecCorrection)
$(makeJSON "_msgSsrStecCorrection_" ''MsgSsrStecCorrection)
$(makeLenses ''MsgSsrStecCorrection)

msgSsrGriddedCorrection :: Word16
msgSsrGriddedCorrection = 0x05FC

-- | SBP class for message MSG_SSR_GRIDDED_CORRECTION (0x05FC).
--
-- STEC residuals are per space vehicle, troposphere is not.
--
-- It is typically equivalent to the QZSS CLAS Sub Type 9 messages.
data MsgSsrGriddedCorrection = MsgSsrGriddedCorrection
  { _msgSsrGriddedCorrection_header               :: !GriddedCorrectionHeader
    -- ^ Header of a gridded correction message
  , _msgSsrGriddedCorrection_index                :: !Word16
    -- ^ Index of the grid point.
  , _msgSsrGriddedCorrection_tropo_delay_correction :: !TroposphericDelayCorrection
    -- ^ Wet and hydrostatic vertical delays (mean, stddev).
  , _msgSsrGriddedCorrection_stec_residuals       :: ![STECResidual]
    -- ^ STEC residuals for each satellite (mean, stddev).
  } deriving ( Show, Read, Eq )

instance Binary MsgSsrGriddedCorrection where
  get = do
    _msgSsrGriddedCorrection_header <- get
    _msgSsrGriddedCorrection_index <- getWord16le
    _msgSsrGriddedCorrection_tropo_delay_correction <- get
    _msgSsrGriddedCorrection_stec_residuals <- whileM (not <$> isEmpty) get
    pure MsgSsrGriddedCorrection {..}

  put MsgSsrGriddedCorrection {..} = do
    put _msgSsrGriddedCorrection_header
    putWord16le _msgSsrGriddedCorrection_index
    put _msgSsrGriddedCorrection_tropo_delay_correction
    mapM_ put _msgSsrGriddedCorrection_stec_residuals

$(makeSBP 'msgSsrGriddedCorrection ''MsgSsrGriddedCorrection)
$(makeJSON "_msgSsrGriddedCorrection_" ''MsgSsrGriddedCorrection)
$(makeLenses ''MsgSsrGriddedCorrection)

-- | STECSatElementIntegrity.
--
-- STEC polynomial and bounds for the given satellite.
data STECSatElementIntegrity = STECSatElementIntegrity
  { _sTECSatElementIntegrity_stec_residual    :: !STECResidual
    -- ^ STEC residuals (mean, stddev)
  , _sTECSatElementIntegrity_stec_bound_mu    :: !Word8
    -- ^ Error Bound Mean. See Note 1.
  , _sTECSatElementIntegrity_stec_bound_sig   :: !Word8
    -- ^ Error Bound StDev. See Note 1.
  , _sTECSatElementIntegrity_stec_bound_mu_dot :: !Word8
    -- ^ Error Bound Mean First derivative.
  , _sTECSatElementIntegrity_stec_bound_sig_dot :: !Word8
    -- ^ Error Bound StDev First derivative.
  } deriving ( Show, Read, Eq )

instance Binary STECSatElementIntegrity where
  get = do
    _sTECSatElementIntegrity_stec_residual <- get
    _sTECSatElementIntegrity_stec_bound_mu <- getWord8
    _sTECSatElementIntegrity_stec_bound_sig <- getWord8
    _sTECSatElementIntegrity_stec_bound_mu_dot <- getWord8
    _sTECSatElementIntegrity_stec_bound_sig_dot <- getWord8
    pure STECSatElementIntegrity {..}

  put STECSatElementIntegrity {..} = do
    put _sTECSatElementIntegrity_stec_residual
    putWord8 _sTECSatElementIntegrity_stec_bound_mu
    putWord8 _sTECSatElementIntegrity_stec_bound_sig
    putWord8 _sTECSatElementIntegrity_stec_bound_mu_dot
    putWord8 _sTECSatElementIntegrity_stec_bound_sig_dot

$(makeJSON "_sTECSatElementIntegrity_" ''STECSatElementIntegrity)
$(makeLenses ''STECSatElementIntegrity)

msgSsrGriddedCorrectionBounds :: Word16
msgSsrGriddedCorrectionBounds = 0x05FE

-- | SBP class for message MSG_SSR_GRIDDED_CORRECTION_BOUNDS (0x05FE).
--
-- Note 1: Range: 0-17.5 m. i<= 200, mean = 0.01i; 200<i<=230,
-- mean=2+0.1(i-200); i>230, mean=5+0.5(i-230).
data MsgSsrGriddedCorrectionBounds = MsgSsrGriddedCorrectionBounds
  { _msgSsrGriddedCorrectionBounds_header                :: !BoundsHeader
    -- ^ Header of a bounds message.
  , _msgSsrGriddedCorrectionBounds_ssr_iod_atmo          :: !Word8
    -- ^ IOD of the correction.
  , _msgSsrGriddedCorrectionBounds_tile_set_id           :: !Word16
    -- ^ Set this tile belongs to.
  , _msgSsrGriddedCorrectionBounds_tile_id               :: !Word16
    -- ^ Unique identifier of this tile in the tile set.
  , _msgSsrGriddedCorrectionBounds_tropo_qi              :: !Word8
    -- ^ Tropo Quality Indicator. Similar to RTCM DF389.
  , _msgSsrGriddedCorrectionBounds_grid_point_id         :: !Word16
    -- ^ Index of the Grid Point.
  , _msgSsrGriddedCorrectionBounds_tropo_delay_correction :: !TroposphericDelayCorrection
    -- ^ Tropospheric delay at grid point.
  , _msgSsrGriddedCorrectionBounds_tropo_v_hydro_bound_mu :: !Word8
    -- ^ Vertical Hydrostatic Error Bound Mean.
  , _msgSsrGriddedCorrectionBounds_tropo_v_hydro_bound_sig :: !Word8
    -- ^ Vertical Hydrostatic Error Bound StDev.
  , _msgSsrGriddedCorrectionBounds_tropo_v_wet_bound_mu  :: !Word8
    -- ^ Vertical Wet Error Bound Mean.
  , _msgSsrGriddedCorrectionBounds_tropo_v_wet_bound_sig :: !Word8
    -- ^ Vertical Wet Error Bound StDev.
  , _msgSsrGriddedCorrectionBounds_n_sats                :: !Word8
    -- ^ Number of satellites.
  , _msgSsrGriddedCorrectionBounds_stec_sat_list         :: ![STECSatElementIntegrity]
    -- ^ Array of STEC polynomial coefficients and its bounds for each space
    -- vehicle.
  } deriving ( Show, Read, Eq )

instance Binary MsgSsrGriddedCorrectionBounds where
  get = do
    _msgSsrGriddedCorrectionBounds_header <- get
    _msgSsrGriddedCorrectionBounds_ssr_iod_atmo <- getWord8
    _msgSsrGriddedCorrectionBounds_tile_set_id <- getWord16le
    _msgSsrGriddedCorrectionBounds_tile_id <- getWord16le
    _msgSsrGriddedCorrectionBounds_tropo_qi <- getWord8
    _msgSsrGriddedCorrectionBounds_grid_point_id <- getWord16le
    _msgSsrGriddedCorrectionBounds_tropo_delay_correction <- get
    _msgSsrGriddedCorrectionBounds_tropo_v_hydro_bound_mu <- getWord8
    _msgSsrGriddedCorrectionBounds_tropo_v_hydro_bound_sig <- getWord8
    _msgSsrGriddedCorrectionBounds_tropo_v_wet_bound_mu <- getWord8
    _msgSsrGriddedCorrectionBounds_tropo_v_wet_bound_sig <- getWord8
    _msgSsrGriddedCorrectionBounds_n_sats <- getWord8
    _msgSsrGriddedCorrectionBounds_stec_sat_list <- whileM (not <$> isEmpty) get
    pure MsgSsrGriddedCorrectionBounds {..}

  put MsgSsrGriddedCorrectionBounds {..} = do
    put _msgSsrGriddedCorrectionBounds_header
    putWord8 _msgSsrGriddedCorrectionBounds_ssr_iod_atmo
    putWord16le _msgSsrGriddedCorrectionBounds_tile_set_id
    putWord16le _msgSsrGriddedCorrectionBounds_tile_id
    putWord8 _msgSsrGriddedCorrectionBounds_tropo_qi
    putWord16le _msgSsrGriddedCorrectionBounds_grid_point_id
    put _msgSsrGriddedCorrectionBounds_tropo_delay_correction
    putWord8 _msgSsrGriddedCorrectionBounds_tropo_v_hydro_bound_mu
    putWord8 _msgSsrGriddedCorrectionBounds_tropo_v_hydro_bound_sig
    putWord8 _msgSsrGriddedCorrectionBounds_tropo_v_wet_bound_mu
    putWord8 _msgSsrGriddedCorrectionBounds_tropo_v_wet_bound_sig
    putWord8 _msgSsrGriddedCorrectionBounds_n_sats
    mapM_ put _msgSsrGriddedCorrectionBounds_stec_sat_list

$(makeSBP 'msgSsrGriddedCorrectionBounds ''MsgSsrGriddedCorrectionBounds)
$(makeJSON "_msgSsrGriddedCorrectionBounds_" ''MsgSsrGriddedCorrectionBounds)
$(makeLenses ''MsgSsrGriddedCorrectionBounds)

msgSsrTileDefinitionDep :: Word16
msgSsrTileDefinitionDep = 0x05F6

-- | SBP class for message MSG_SSR_TILE_DEFINITION_DEP (0x05F6).
--
-- Provides the correction point coordinates for the atmospheric correction
-- values in the MSG_SSR_STEC_CORRECTION_DEP and MSG_SSR_GRIDDED_CORRECTION
-- messages.
--
-- Based on ETSI TS 137 355 V16.1.0 (LTE Positioning Protocol) information
-- element GNSS-SSR-CorrectionPoints. SBP only supports gridded arrays of
-- correction points, not lists of points.
data MsgSsrTileDefinitionDep = MsgSsrTileDefinitionDep
  { _msgSsrTileDefinitionDep_tile_set_id :: !Word16
    -- ^ Unique identifier of the tile set this tile belongs to.
  , _msgSsrTileDefinitionDep_tile_id     :: !Word16
    -- ^ Unique identifier of this tile in the tile set.
    -- See GNSS-SSR-ArrayOfCorrectionPoints field correctionPointSetID.
  , _msgSsrTileDefinitionDep_corner_nw_lat :: !Int16
    -- ^ North-West corner correction point latitude.
    --
    -- The relation between the latitude X in the range [-90, 90] and the
    -- coded number N is:
    --
    -- N = floor((X / 90) * 2^14)
    --
    -- See GNSS-SSR-ArrayOfCorrectionPoints field referencePointLatitude.
  , _msgSsrTileDefinitionDep_corner_nw_lon :: !Int16
    -- ^ North-West corner correction point longitude.
    --
    -- The relation between the longitude X in the range [-180, 180] and the
    -- coded number N is:
    --
    -- N = floor((X / 180) * 2^15)
    --
    -- See GNSS-SSR-ArrayOfCorrectionPoints field referencePointLongitude.
  , _msgSsrTileDefinitionDep_spacing_lat :: !Word16
    -- ^ Spacing of the correction points in the latitude direction.
    --
    -- See GNSS-SSR-ArrayOfCorrectionPoints field stepOfLatitude.
  , _msgSsrTileDefinitionDep_spacing_lon :: !Word16
    -- ^ Spacing of the correction points in the longitude direction.
    --
    -- See GNSS-SSR-ArrayOfCorrectionPoints field stepOfLongitude.
  , _msgSsrTileDefinitionDep_rows        :: !Word16
    -- ^ Number of steps in the latitude direction.
    --
    -- See GNSS-SSR-ArrayOfCorrectionPoints field numberOfStepsLatitude.
  , _msgSsrTileDefinitionDep_cols        :: !Word16
    -- ^ Number of steps in the longitude direction.
    --
    -- See GNSS-SSR-ArrayOfCorrectionPoints field numberOfStepsLongitude.
  , _msgSsrTileDefinitionDep_bitmask     :: !Word64
    -- ^ Specifies the availability of correction data at the correction points
    -- in the array.
    --
    -- If a specific bit is enabled (set to 1), the correction is not
    -- available. Only the first rows * cols bits are used, the remainder are
    -- set to 0. If there are more then 64 correction points the remaining
    -- corrections are always available.
    --
    -- Starting with the northwest corner of the array (top left on a north
    -- oriented map) the correction points are enumerated with row precedence
    -- - first row west to east, second row west to east, until last row west
    -- to east - ending with the southeast corner of the array.
    --
    -- See GNSS-SSR-ArrayOfCorrectionPoints field bitmaskOfGrids but note the
    -- definition of the bits is inverted.
  } deriving ( Show, Read, Eq )

instance Binary MsgSsrTileDefinitionDep where
  get = do
    _msgSsrTileDefinitionDep_tile_set_id <- getWord16le
    _msgSsrTileDefinitionDep_tile_id <- getWord16le
    _msgSsrTileDefinitionDep_corner_nw_lat <- (fromIntegral <$> getWord16le)
    _msgSsrTileDefinitionDep_corner_nw_lon <- (fromIntegral <$> getWord16le)
    _msgSsrTileDefinitionDep_spacing_lat <- getWord16le
    _msgSsrTileDefinitionDep_spacing_lon <- getWord16le
    _msgSsrTileDefinitionDep_rows <- getWord16le
    _msgSsrTileDefinitionDep_cols <- getWord16le
    _msgSsrTileDefinitionDep_bitmask <- getWord64le
    pure MsgSsrTileDefinitionDep {..}

  put MsgSsrTileDefinitionDep {..} = do
    putWord16le _msgSsrTileDefinitionDep_tile_set_id
    putWord16le _msgSsrTileDefinitionDep_tile_id
    (putWord16le . fromIntegral) _msgSsrTileDefinitionDep_corner_nw_lat
    (putWord16le . fromIntegral) _msgSsrTileDefinitionDep_corner_nw_lon
    putWord16le _msgSsrTileDefinitionDep_spacing_lat
    putWord16le _msgSsrTileDefinitionDep_spacing_lon
    putWord16le _msgSsrTileDefinitionDep_rows
    putWord16le _msgSsrTileDefinitionDep_cols
    putWord64le _msgSsrTileDefinitionDep_bitmask

$(makeSBP 'msgSsrTileDefinitionDep ''MsgSsrTileDefinitionDep)
$(makeJSON "_msgSsrTileDefinitionDep_" ''MsgSsrTileDefinitionDep)
$(makeLenses ''MsgSsrTileDefinitionDep)

msgSsrTileDefinition :: Word16
msgSsrTileDefinition = 0x05F7

-- | SBP class for message MSG_SSR_TILE_DEFINITION (0x05F7).
--
-- Provides the correction point coordinates for the atmospheric correction
-- values in the MSG_SSR_STEC_CORRECTION and MSG_SSR_GRIDDED_CORRECTION
-- messages.
--
-- Based on ETSI TS 137 355 V16.1.0 (LTE Positioning Protocol) information
-- element GNSS-SSR-CorrectionPoints. SBP only supports gridded arrays of
-- correction points, not lists of points.
data MsgSsrTileDefinition = MsgSsrTileDefinition
  { _msgSsrTileDefinition_ssr_sol_id  :: !Word8
    -- ^ SSR Solution ID.
  , _msgSsrTileDefinition_tile_set_id :: !Word16
    -- ^ Unique identifier of the tile set this tile belongs to.
  , _msgSsrTileDefinition_tile_id     :: !Word16
    -- ^ Unique identifier of this tile in the tile set.
    -- See GNSS-SSR-ArrayOfCorrectionPoints field correctionPointSetID.
  , _msgSsrTileDefinition_corner_nw_lat :: !Int16
    -- ^ North-West corner correction point latitude.
    --
    -- The relation between the latitude X in the range [-90, 90] and the
    -- coded number N is:
    --
    -- N = floor((X / 90) * 2^14)
    --
    -- See GNSS-SSR-ArrayOfCorrectionPoints field referencePointLatitude.
  , _msgSsrTileDefinition_corner_nw_lon :: !Int16
    -- ^ North-West corner correction point longitude.
    --
    -- The relation between the longitude X in the range [-180, 180] and the
    -- coded number N is:
    --
    -- N = floor((X / 180) * 2^15)
    --
    -- See GNSS-SSR-ArrayOfCorrectionPoints field referencePointLongitude.
  , _msgSsrTileDefinition_spacing_lat :: !Word16
    -- ^ Spacing of the correction points in the latitude direction.
    --
    -- See GNSS-SSR-ArrayOfCorrectionPoints field stepOfLatitude.
  , _msgSsrTileDefinition_spacing_lon :: !Word16
    -- ^ Spacing of the correction points in the longitude direction.
    --
    -- See GNSS-SSR-ArrayOfCorrectionPoints field stepOfLongitude.
  , _msgSsrTileDefinition_rows        :: !Word16
    -- ^ Number of steps in the latitude direction.
    --
    -- See GNSS-SSR-ArrayOfCorrectionPoints field numberOfStepsLatitude.
  , _msgSsrTileDefinition_cols        :: !Word16
    -- ^ Number of steps in the longitude direction.
    --
    -- See GNSS-SSR-ArrayOfCorrectionPoints field numberOfStepsLongitude.
  , _msgSsrTileDefinition_bitmask     :: !Word64
    -- ^ Specifies the availability of correction data at the correction points
    -- in the array.
    --
    -- If a specific bit is enabled (set to 1), the correction is not
    -- available. Only the first rows * cols bits are used, the remainder are
    -- set to 0. If there are more then 64 correction points the remaining
    -- corrections are always available.
    --
    -- Starting with the northwest corner of the array (top left on a north
    -- oriented map) the correction points are enumerated with row precedence
    -- - first row west to east, second row west to east, until last row west
    -- to east - ending with the southeast corner of the array.
    --
    -- See GNSS-SSR-ArrayOfCorrectionPoints field bitmaskOfGrids but note the
    -- definition of the bits is inverted.
  } deriving ( Show, Read, Eq )

instance Binary MsgSsrTileDefinition where
  get = do
    _msgSsrTileDefinition_ssr_sol_id <- getWord8
    _msgSsrTileDefinition_tile_set_id <- getWord16le
    _msgSsrTileDefinition_tile_id <- getWord16le
    _msgSsrTileDefinition_corner_nw_lat <- (fromIntegral <$> getWord16le)
    _msgSsrTileDefinition_corner_nw_lon <- (fromIntegral <$> getWord16le)
    _msgSsrTileDefinition_spacing_lat <- getWord16le
    _msgSsrTileDefinition_spacing_lon <- getWord16le
    _msgSsrTileDefinition_rows <- getWord16le
    _msgSsrTileDefinition_cols <- getWord16le
    _msgSsrTileDefinition_bitmask <- getWord64le
    pure MsgSsrTileDefinition {..}

  put MsgSsrTileDefinition {..} = do
    putWord8 _msgSsrTileDefinition_ssr_sol_id
    putWord16le _msgSsrTileDefinition_tile_set_id
    putWord16le _msgSsrTileDefinition_tile_id
    (putWord16le . fromIntegral) _msgSsrTileDefinition_corner_nw_lat
    (putWord16le . fromIntegral) _msgSsrTileDefinition_corner_nw_lon
    putWord16le _msgSsrTileDefinition_spacing_lat
    putWord16le _msgSsrTileDefinition_spacing_lon
    putWord16le _msgSsrTileDefinition_rows
    putWord16le _msgSsrTileDefinition_cols
    putWord64le _msgSsrTileDefinition_bitmask

$(makeSBP 'msgSsrTileDefinition ''MsgSsrTileDefinition)
$(makeJSON "_msgSsrTileDefinition_" ''MsgSsrTileDefinition)
$(makeLenses ''MsgSsrTileDefinition)

-- | SatelliteAPC.
--
-- Contains phase center offset and elevation variation corrections for one
-- signal on a satellite.
data SatelliteAPC = SatelliteAPC
  { _satelliteAPC_sid    :: !GnssSignal
    -- ^ GNSS signal identifier (16 bit)
  , _satelliteAPC_sat_info :: !Word8
    -- ^ Additional satellite information
  , _satelliteAPC_svn    :: !Word16
    -- ^ Satellite Code, as defined by IGS. Typically the space vehicle number.
  , _satelliteAPC_pco    :: ![Int16]
    -- ^ Mean phase center offset, X Y and Z axes. See IGS ANTEX file format
    -- description for coordinate system definition.
  , _satelliteAPC_pcv    :: ![Int8]
    -- ^ Elevation dependent phase center variations. First element is 0 degrees
    -- separation from the Z axis, subsequent elements represent elevation
    -- variations in 1 degree increments.
  } deriving ( Show, Read, Eq )

instance Binary SatelliteAPC where
  get = do
    _satelliteAPC_sid <- get
    _satelliteAPC_sat_info <- getWord8
    _satelliteAPC_svn <- getWord16le
    _satelliteAPC_pco <- replicateM 3 (fromIntegral <$> getWord16le)
    _satelliteAPC_pcv <- replicateM 21 (fromIntegral <$> getWord8)
    pure SatelliteAPC {..}

  put SatelliteAPC {..} = do
    put _satelliteAPC_sid
    putWord8 _satelliteAPC_sat_info
    putWord16le _satelliteAPC_svn
    mapM_ (putWord16le . fromIntegral) _satelliteAPC_pco
    mapM_ (putWord8 . fromIntegral) _satelliteAPC_pcv

$(makeJSON "_satelliteAPC_" ''SatelliteAPC)
$(makeLenses ''SatelliteAPC)

msgSsrSatelliteApc :: Word16
msgSsrSatelliteApc = 0x0604

data MsgSsrSatelliteApc = MsgSsrSatelliteApc
  { _msgSsrSatelliteApc_apc :: ![SatelliteAPC]
    -- ^ Satellite antenna phase center corrections
  } deriving ( Show, Read, Eq )

instance Binary MsgSsrSatelliteApc where
  get = do
    _msgSsrSatelliteApc_apc <- whileM (not <$> isEmpty) get
    pure MsgSsrSatelliteApc {..}

  put MsgSsrSatelliteApc {..} = do
    mapM_ put _msgSsrSatelliteApc_apc

$(makeSBP 'msgSsrSatelliteApc ''MsgSsrSatelliteApc)
$(makeJSON "_msgSsrSatelliteApc_" ''MsgSsrSatelliteApc)
$(makeLenses ''MsgSsrSatelliteApc)

msgSsrOrbitClockDepA :: Word16
msgSsrOrbitClockDepA = 0x05DC

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

-- | STECHeaderDepA.
--
-- A full set of STEC information will likely span multiple SBP messages,
-- since SBP message a limited to 255 bytes.  The header is used to tie
-- multiple SBP messages into a sequence.
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

-- | GriddedCorrectionHeaderDepA.
--
-- The 3GPP message contains nested variable length arrays which are not
-- supported in SBP, so each grid point will be identified by the index.
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
    -- specification in units of m.
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

-- | GridDefinitionHeaderDepA.
--
-- Defines the grid for MSG_SSR_GRIDDED_CORRECTION messages. Also includes an
-- RLE encoded validity list.
data GridDefinitionHeaderDepA = GridDefinitionHeaderDepA
  { _gridDefinitionHeaderDepA_region_size_inverse :: !Word8
    -- ^ region_size (deg) = 10 / region_size_inverse 0 is an invalid value.
  , _gridDefinitionHeaderDepA_area_width        :: !Word16
    -- ^ grid height (deg) = grid width (deg) = area_width / region_size 0 is an
    -- invalid value.
  , _gridDefinitionHeaderDepA_lat_nw_corner_enc :: !Word16
    -- ^ North-West corner latitude (deg) = region_size * lat_nw_corner_enc - 90
  , _gridDefinitionHeaderDepA_lon_nw_corner_enc :: !Word16
    -- ^ North-West corner longitude (deg) = region_size * lon_nw_corner_enc -
    -- 180
  , _gridDefinitionHeaderDepA_num_msgs          :: !Word8
    -- ^ Number of messages in the dataset
  , _gridDefinitionHeaderDepA_seq_num           :: !Word8
    -- ^ Position of this message in the dataset
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

msgSsrStecCorrectionDepA :: Word16
msgSsrStecCorrectionDepA = 0x05EB

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

msgSsrGriddedCorrectionNoStdDepA :: Word16
msgSsrGriddedCorrectionNoStdDepA = 0x05F0

data MsgSsrGriddedCorrectionNoStdDepA = MsgSsrGriddedCorrectionNoStdDepA
  { _msgSsrGriddedCorrectionNoStdDepA_header               :: !GriddedCorrectionHeaderDepA
    -- ^ Header of a Gridded Correction message
  , _msgSsrGriddedCorrectionNoStdDepA_index                :: !Word16
    -- ^ Index of the grid point
  , _msgSsrGriddedCorrectionNoStdDepA_tropo_delay_correction :: !TroposphericDelayCorrectionNoStd
    -- ^ Wet and hydrostatic vertical delays
  , _msgSsrGriddedCorrectionNoStdDepA_stec_residuals       :: ![STECResidualNoStd]
    -- ^ STEC residuals for each satellite
  } deriving ( Show, Read, Eq )

instance Binary MsgSsrGriddedCorrectionNoStdDepA where
  get = do
    _msgSsrGriddedCorrectionNoStdDepA_header <- get
    _msgSsrGriddedCorrectionNoStdDepA_index <- getWord16le
    _msgSsrGriddedCorrectionNoStdDepA_tropo_delay_correction <- get
    _msgSsrGriddedCorrectionNoStdDepA_stec_residuals <- whileM (not <$> isEmpty) get
    pure MsgSsrGriddedCorrectionNoStdDepA {..}

  put MsgSsrGriddedCorrectionNoStdDepA {..} = do
    put _msgSsrGriddedCorrectionNoStdDepA_header
    putWord16le _msgSsrGriddedCorrectionNoStdDepA_index
    put _msgSsrGriddedCorrectionNoStdDepA_tropo_delay_correction
    mapM_ put _msgSsrGriddedCorrectionNoStdDepA_stec_residuals

$(makeSBP 'msgSsrGriddedCorrectionNoStdDepA ''MsgSsrGriddedCorrectionNoStdDepA)
$(makeJSON "_msgSsrGriddedCorrectionNoStdDepA_" ''MsgSsrGriddedCorrectionNoStdDepA)
$(makeLenses ''MsgSsrGriddedCorrectionNoStdDepA)

msgSsrGriddedCorrectionDepA :: Word16
msgSsrGriddedCorrectionDepA = 0x05FA

data MsgSsrGriddedCorrectionDepA = MsgSsrGriddedCorrectionDepA
  { _msgSsrGriddedCorrectionDepA_header               :: !GriddedCorrectionHeaderDepA
    -- ^ Header of a Gridded Correction message
  , _msgSsrGriddedCorrectionDepA_index                :: !Word16
    -- ^ Index of the grid point
  , _msgSsrGriddedCorrectionDepA_tropo_delay_correction :: !TroposphericDelayCorrection
    -- ^ Wet and hydrostatic vertical delays (mean, stddev)
  , _msgSsrGriddedCorrectionDepA_stec_residuals       :: ![STECResidual]
    -- ^ STEC residuals for each satellite (mean, stddev)
  } deriving ( Show, Read, Eq )

instance Binary MsgSsrGriddedCorrectionDepA where
  get = do
    _msgSsrGriddedCorrectionDepA_header <- get
    _msgSsrGriddedCorrectionDepA_index <- getWord16le
    _msgSsrGriddedCorrectionDepA_tropo_delay_correction <- get
    _msgSsrGriddedCorrectionDepA_stec_residuals <- whileM (not <$> isEmpty) get
    pure MsgSsrGriddedCorrectionDepA {..}

  put MsgSsrGriddedCorrectionDepA {..} = do
    put _msgSsrGriddedCorrectionDepA_header
    putWord16le _msgSsrGriddedCorrectionDepA_index
    put _msgSsrGriddedCorrectionDepA_tropo_delay_correction
    mapM_ put _msgSsrGriddedCorrectionDepA_stec_residuals

$(makeSBP 'msgSsrGriddedCorrectionDepA ''MsgSsrGriddedCorrectionDepA)
$(makeJSON "_msgSsrGriddedCorrectionDepA_" ''MsgSsrGriddedCorrectionDepA)
$(makeLenses ''MsgSsrGriddedCorrectionDepA)

msgSsrGridDefinitionDepA :: Word16
msgSsrGridDefinitionDepA = 0x05F5

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

-- | OrbitClockBound.
--
-- Orbit and clock bound.
data OrbitClockBound = OrbitClockBound
  { _orbitClockBound_sat_id             :: !Word8
    -- ^ Satellite ID. Similar to either RTCM DF068 (GPS), DF252 (Galileo), or
    -- DF488 (BDS) depending on the constellation.
  , _orbitClockBound_orb_radial_bound_mu :: !Word8
    -- ^ Mean Radial. See Note 1.
  , _orbitClockBound_orb_along_bound_mu :: !Word8
    -- ^ Mean Along-Track. See Note 1.
  , _orbitClockBound_orb_cross_bound_mu :: !Word8
    -- ^ Mean Cross-Track. See Note 1.
  , _orbitClockBound_orb_radial_bound_sig :: !Word8
    -- ^ Standard Deviation Radial. See Note 2.
  , _orbitClockBound_orb_along_bound_sig :: !Word8
    -- ^ Standard Deviation Along-Track. See Note 2.
  , _orbitClockBound_orb_cross_bound_sig :: !Word8
    -- ^ Standard Deviation Cross-Track. See Note 2.
  , _orbitClockBound_clock_bound_mu     :: !Word8
    -- ^ Clock Bound Mean. See Note 1.
  , _orbitClockBound_clock_bound_sig    :: !Word8
    -- ^ Clock Bound Standard Deviation. See Note 2.
  } deriving ( Show, Read, Eq )

instance Binary OrbitClockBound where
  get = do
    _orbitClockBound_sat_id <- getWord8
    _orbitClockBound_orb_radial_bound_mu <- getWord8
    _orbitClockBound_orb_along_bound_mu <- getWord8
    _orbitClockBound_orb_cross_bound_mu <- getWord8
    _orbitClockBound_orb_radial_bound_sig <- getWord8
    _orbitClockBound_orb_along_bound_sig <- getWord8
    _orbitClockBound_orb_cross_bound_sig <- getWord8
    _orbitClockBound_clock_bound_mu <- getWord8
    _orbitClockBound_clock_bound_sig <- getWord8
    pure OrbitClockBound {..}

  put OrbitClockBound {..} = do
    putWord8 _orbitClockBound_sat_id
    putWord8 _orbitClockBound_orb_radial_bound_mu
    putWord8 _orbitClockBound_orb_along_bound_mu
    putWord8 _orbitClockBound_orb_cross_bound_mu
    putWord8 _orbitClockBound_orb_radial_bound_sig
    putWord8 _orbitClockBound_orb_along_bound_sig
    putWord8 _orbitClockBound_orb_cross_bound_sig
    putWord8 _orbitClockBound_clock_bound_mu
    putWord8 _orbitClockBound_clock_bound_sig

$(makeJSON "_orbitClockBound_" ''OrbitClockBound)
$(makeLenses ''OrbitClockBound)

msgSsrOrbitClockBounds :: Word16
msgSsrOrbitClockBounds = 0x05DE

-- | SBP class for message MSG_SSR_ORBIT_CLOCK_BOUNDS (0x05DE).
--
-- Note 1: Range: 0-17.5 m. i<=200, mean=0.01i; 200<i<=230, mean=2+0.1(i-200);
-- i>230, mean=5+0.5(i-230).
--
-- Note 2: Range: 0-17.5 m. i<=200, std=0.01i; 200<i<=230, std=2+0.1(i-200)
-- i>230, std=5+0.5(i-230).
data MsgSsrOrbitClockBounds = MsgSsrOrbitClockBounds
  { _msgSsrOrbitClockBounds_header           :: !BoundsHeader
    -- ^ Header of a bounds message.
  , _msgSsrOrbitClockBounds_ssr_iod          :: !Word8
    -- ^ IOD of the SSR bound.
  , _msgSsrOrbitClockBounds_const_id         :: !Word8
    -- ^ Constellation ID to which the SVs belong.
  , _msgSsrOrbitClockBounds_n_sats           :: !Word8
    -- ^ Number of satellites.
  , _msgSsrOrbitClockBounds_orbit_clock_bounds :: ![OrbitClockBound]
    -- ^ Orbit and Clock Bounds per Satellite
  } deriving ( Show, Read, Eq )

instance Binary MsgSsrOrbitClockBounds where
  get = do
    _msgSsrOrbitClockBounds_header <- get
    _msgSsrOrbitClockBounds_ssr_iod <- getWord8
    _msgSsrOrbitClockBounds_const_id <- getWord8
    _msgSsrOrbitClockBounds_n_sats <- getWord8
    _msgSsrOrbitClockBounds_orbit_clock_bounds <- whileM (not <$> isEmpty) get
    pure MsgSsrOrbitClockBounds {..}

  put MsgSsrOrbitClockBounds {..} = do
    put _msgSsrOrbitClockBounds_header
    putWord8 _msgSsrOrbitClockBounds_ssr_iod
    putWord8 _msgSsrOrbitClockBounds_const_id
    putWord8 _msgSsrOrbitClockBounds_n_sats
    mapM_ put _msgSsrOrbitClockBounds_orbit_clock_bounds

$(makeSBP 'msgSsrOrbitClockBounds ''MsgSsrOrbitClockBounds)
$(makeJSON "_msgSsrOrbitClockBounds_" ''MsgSsrOrbitClockBounds)
$(makeLenses ''MsgSsrOrbitClockBounds)

data CodePhaseBiasesSatSig = CodePhaseBiasesSatSig
  { _codePhaseBiasesSatSig_sat_id             :: !Word8
    -- ^ Satellite ID. Similar to either RTCM DF068 (GPS), DF252 (Galileo), or
    -- DF488 (BDS) depending on the constellation.
  , _codePhaseBiasesSatSig_signal_id          :: !Word8
    -- ^ Signal and Tracking Mode Identifier. Similar to either RTCM DF380
    -- (GPS), DF382 (Galileo) or DF467 (BDS) depending on the constellation.
  , _codePhaseBiasesSatSig_code_bias_bound_mu :: !Word8
    -- ^ Code Bias Mean. Range: 0-1.275 m
  , _codePhaseBiasesSatSig_code_bias_bound_sig :: !Word8
    -- ^ Code Bias Standard Deviation.  Range: 0-1.275 m
  , _codePhaseBiasesSatSig_phase_bias_bound_mu :: !Word8
    -- ^ Phase Bias Mean. Range: 0-1.275 m
  , _codePhaseBiasesSatSig_phase_bias_bound_sig :: !Word8
    -- ^ Phase Bias Standard Deviation.  Range: 0-1.275 m
  } deriving ( Show, Read, Eq )

instance Binary CodePhaseBiasesSatSig where
  get = do
    _codePhaseBiasesSatSig_sat_id <- getWord8
    _codePhaseBiasesSatSig_signal_id <- getWord8
    _codePhaseBiasesSatSig_code_bias_bound_mu <- getWord8
    _codePhaseBiasesSatSig_code_bias_bound_sig <- getWord8
    _codePhaseBiasesSatSig_phase_bias_bound_mu <- getWord8
    _codePhaseBiasesSatSig_phase_bias_bound_sig <- getWord8
    pure CodePhaseBiasesSatSig {..}

  put CodePhaseBiasesSatSig {..} = do
    putWord8 _codePhaseBiasesSatSig_sat_id
    putWord8 _codePhaseBiasesSatSig_signal_id
    putWord8 _codePhaseBiasesSatSig_code_bias_bound_mu
    putWord8 _codePhaseBiasesSatSig_code_bias_bound_sig
    putWord8 _codePhaseBiasesSatSig_phase_bias_bound_mu
    putWord8 _codePhaseBiasesSatSig_phase_bias_bound_sig

$(makeJSON "_codePhaseBiasesSatSig_" ''CodePhaseBiasesSatSig)
$(makeLenses ''CodePhaseBiasesSatSig)

msgSsrCodePhaseBiasesBounds :: Word16
msgSsrCodePhaseBiasesBounds = 0x05EC

data MsgSsrCodePhaseBiasesBounds = MsgSsrCodePhaseBiasesBounds
  { _msgSsrCodePhaseBiasesBounds_header           :: !BoundsHeader
    -- ^ Header of a bounds message.
  , _msgSsrCodePhaseBiasesBounds_ssr_iod          :: !Word8
    -- ^ IOD of the SSR bound.
  , _msgSsrCodePhaseBiasesBounds_const_id         :: !Word8
    -- ^ Constellation ID to which the SVs belong.
  , _msgSsrCodePhaseBiasesBounds_n_sats_signals   :: !Word8
    -- ^ Number of satellite-signal couples.
  , _msgSsrCodePhaseBiasesBounds_satellites_signals :: ![CodePhaseBiasesSatSig]
    -- ^ Code and Phase Biases Bounds per Satellite-Signal couple.
  } deriving ( Show, Read, Eq )

instance Binary MsgSsrCodePhaseBiasesBounds where
  get = do
    _msgSsrCodePhaseBiasesBounds_header <- get
    _msgSsrCodePhaseBiasesBounds_ssr_iod <- getWord8
    _msgSsrCodePhaseBiasesBounds_const_id <- getWord8
    _msgSsrCodePhaseBiasesBounds_n_sats_signals <- getWord8
    _msgSsrCodePhaseBiasesBounds_satellites_signals <- whileM (not <$> isEmpty) get
    pure MsgSsrCodePhaseBiasesBounds {..}

  put MsgSsrCodePhaseBiasesBounds {..} = do
    put _msgSsrCodePhaseBiasesBounds_header
    putWord8 _msgSsrCodePhaseBiasesBounds_ssr_iod
    putWord8 _msgSsrCodePhaseBiasesBounds_const_id
    putWord8 _msgSsrCodePhaseBiasesBounds_n_sats_signals
    mapM_ put _msgSsrCodePhaseBiasesBounds_satellites_signals

$(makeSBP 'msgSsrCodePhaseBiasesBounds ''MsgSsrCodePhaseBiasesBounds)
$(makeJSON "_msgSsrCodePhaseBiasesBounds_" ''MsgSsrCodePhaseBiasesBounds)
$(makeLenses ''MsgSsrCodePhaseBiasesBounds)

-- | OrbitClockBoundDegradation.
--
-- Orbit and clock bound degradation.
data OrbitClockBoundDegradation = OrbitClockBoundDegradation
  { _orbitClockBoundDegradation_orb_radial_bound_mu_dot :: !Word8
    -- ^ Orbit Bound Mean Radial First derivative. Range: 0-0.255 m/s
  , _orbitClockBoundDegradation_orb_along_bound_mu_dot :: !Word8
    -- ^ Orbit Bound Mean Along-Track First derivative. Range: 0-0.255 m/s
  , _orbitClockBoundDegradation_orb_cross_bound_mu_dot :: !Word8
    -- ^ Orbit Bound Mean Cross-Track First derivative. Range: 0-0.255 m/s
  , _orbitClockBoundDegradation_orb_radial_bound_sig_dot :: !Word8
    -- ^ Orbit Bound Standard Deviation Radial First derivative. Range: 0-0.255
    -- m/s
  , _orbitClockBoundDegradation_orb_along_bound_sig_dot :: !Word8
    -- ^ Orbit Bound Standard Deviation Along-Track First derivative. Range:
    -- 0-0.255 m/s
  , _orbitClockBoundDegradation_orb_cross_bound_sig_dot :: !Word8
    -- ^ Orbit Bound Standard Deviation Cross-Track First derivative. Range:
    -- 0-0.255 m/s
  , _orbitClockBoundDegradation_clock_bound_mu_dot     :: !Word8
    -- ^ Clock Bound Mean First derivative. Range: 0-0.255 m/s
  , _orbitClockBoundDegradation_clock_bound_sig_dot    :: !Word8
    -- ^ Clock Bound Standard Deviation First derivative. Range: 0-0.255 m/s
  } deriving ( Show, Read, Eq )

instance Binary OrbitClockBoundDegradation where
  get = do
    _orbitClockBoundDegradation_orb_radial_bound_mu_dot <- getWord8
    _orbitClockBoundDegradation_orb_along_bound_mu_dot <- getWord8
    _orbitClockBoundDegradation_orb_cross_bound_mu_dot <- getWord8
    _orbitClockBoundDegradation_orb_radial_bound_sig_dot <- getWord8
    _orbitClockBoundDegradation_orb_along_bound_sig_dot <- getWord8
    _orbitClockBoundDegradation_orb_cross_bound_sig_dot <- getWord8
    _orbitClockBoundDegradation_clock_bound_mu_dot <- getWord8
    _orbitClockBoundDegradation_clock_bound_sig_dot <- getWord8
    pure OrbitClockBoundDegradation {..}

  put OrbitClockBoundDegradation {..} = do
    putWord8 _orbitClockBoundDegradation_orb_radial_bound_mu_dot
    putWord8 _orbitClockBoundDegradation_orb_along_bound_mu_dot
    putWord8 _orbitClockBoundDegradation_orb_cross_bound_mu_dot
    putWord8 _orbitClockBoundDegradation_orb_radial_bound_sig_dot
    putWord8 _orbitClockBoundDegradation_orb_along_bound_sig_dot
    putWord8 _orbitClockBoundDegradation_orb_cross_bound_sig_dot
    putWord8 _orbitClockBoundDegradation_clock_bound_mu_dot
    putWord8 _orbitClockBoundDegradation_clock_bound_sig_dot

$(makeJSON "_orbitClockBoundDegradation_" ''OrbitClockBoundDegradation)
$(makeLenses ''OrbitClockBoundDegradation)

msgSsrOrbitClockBoundsDegradation :: Word16
msgSsrOrbitClockBoundsDegradation = 0x05DF

data MsgSsrOrbitClockBoundsDegradation = MsgSsrOrbitClockBoundsDegradation
  { _msgSsrOrbitClockBoundsDegradation_header                       :: !BoundsHeader
    -- ^ Header of a bounds message.
  , _msgSsrOrbitClockBoundsDegradation_ssr_iod                      :: !Word8
    -- ^ IOD of the SSR bound degradation parameter.
  , _msgSsrOrbitClockBoundsDegradation_const_id                     :: !Word8
    -- ^ Constellation ID to which the SVs belong.
  , _msgSsrOrbitClockBoundsDegradation_sat_bitmask                  :: !Word64
    -- ^ Satellite Bit Mask. Put 1 for each satellite where the following
    -- degradation parameters are applicable, 0 otherwise. Encoded following
    -- RTCM DF394 specification.
  , _msgSsrOrbitClockBoundsDegradation_orbit_clock_bounds_degradation :: !OrbitClockBoundDegradation
    -- ^ Orbit and Clock Bounds Degradation Parameters
  } deriving ( Show, Read, Eq )

instance Binary MsgSsrOrbitClockBoundsDegradation where
  get = do
    _msgSsrOrbitClockBoundsDegradation_header <- get
    _msgSsrOrbitClockBoundsDegradation_ssr_iod <- getWord8
    _msgSsrOrbitClockBoundsDegradation_const_id <- getWord8
    _msgSsrOrbitClockBoundsDegradation_sat_bitmask <- getWord64le
    _msgSsrOrbitClockBoundsDegradation_orbit_clock_bounds_degradation <- get
    pure MsgSsrOrbitClockBoundsDegradation {..}

  put MsgSsrOrbitClockBoundsDegradation {..} = do
    put _msgSsrOrbitClockBoundsDegradation_header
    putWord8 _msgSsrOrbitClockBoundsDegradation_ssr_iod
    putWord8 _msgSsrOrbitClockBoundsDegradation_const_id
    putWord64le _msgSsrOrbitClockBoundsDegradation_sat_bitmask
    put _msgSsrOrbitClockBoundsDegradation_orbit_clock_bounds_degradation

$(makeSBP 'msgSsrOrbitClockBoundsDegradation ''MsgSsrOrbitClockBoundsDegradation)
$(makeJSON "_msgSsrOrbitClockBoundsDegradation_" ''MsgSsrOrbitClockBoundsDegradation)
$(makeLenses ''MsgSsrOrbitClockBoundsDegradation)
