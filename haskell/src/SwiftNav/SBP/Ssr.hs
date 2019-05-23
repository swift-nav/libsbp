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
-- Precise State Space Representation (SSR) corrections format

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
-- Code biases are to be added to pseudorange. The corrections are conform with
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
    _codeBiasesContent_value <- fromIntegral <$> getWord16le
    pure CodeBiasesContent {..}

  put CodeBiasesContent {..} = do
    putWord8 _codeBiasesContent_code
    (putWord16le . fromIntegral) _codeBiasesContent_value

$(makeJSON "_codeBiasesContent_" ''CodeBiasesContent)
$(makeLenses ''CodeBiasesContent)

-- | PhaseBiasesContent.
--
-- Phase biases are to be added to carrier phase measurements. The corrections
-- are conform with typical RTCMv3 MT1059 and 1065.
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
    _phaseBiasesContent_bias <- fromIntegral <$> getWord32le
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
-- A full set of STEC information will likely span multiple SBP messages, since
-- SBP message a limited to 255 bytes.  The header is used to tie multiple SBP
-- messages into a sequence.
data STECHeader = STECHeader
  { _sTECHeader_time              :: !GpsTime
    -- ^ GNSS time of the STEC data
  , _sTECHeader_num_msgs          :: !Word8
    -- ^ Number of messages in the dataset
  , _sTECHeader_seq_num           :: !Word8
    -- ^ Position of this message in the dataset
  , _sTECHeader_ssr_update_interval :: !Word16
    -- ^ update interval in seconds
  , _sTECHeader_iod_ssr           :: !Word8
    -- ^ range 0 - 15
  } deriving ( Show, Read, Eq )

instance Binary STECHeader where
  get = do
    _sTECHeader_time <- get
    _sTECHeader_num_msgs <- getWord8
    _sTECHeader_seq_num <- getWord8
    _sTECHeader_ssr_update_interval <- getWord16le
    _sTECHeader_iod_ssr <- getWord8
    pure STECHeader {..}

  put STECHeader {..} = do
    put _sTECHeader_time
    putWord8 _sTECHeader_num_msgs
    putWord8 _sTECHeader_seq_num
    putWord16le _sTECHeader_ssr_update_interval
    putWord8 _sTECHeader_iod_ssr

$(makeJSON "_sTECHeader_" ''STECHeader)
$(makeLenses ''STECHeader)

-- | GriddedCorrectionHeader.
--
-- The 3GPP message contains nested variable length arrays which are not
-- suppported in SBP, so each grid point will be identified by the index.
data GriddedCorrectionHeader = GriddedCorrectionHeader
  { _griddedCorrectionHeader_time              :: !GpsTime
    -- ^ GNSS time of the STEC data
  , _griddedCorrectionHeader_num_msgs          :: !Word16
    -- ^ Number of messages in the dataset
  , _griddedCorrectionHeader_seq_num           :: !Word16
    -- ^ Position of this message in the dataset
  , _griddedCorrectionHeader_ssr_update_interval :: !Word16
    -- ^ update interval in seconds
  , _griddedCorrectionHeader_iod_ssr           :: !Word8
    -- ^ range 0 - 15
  , _griddedCorrectionHeader_tropo_quality     :: !Word8
    -- ^ troposphere quality indicator
  } deriving ( Show, Read, Eq )

instance Binary GriddedCorrectionHeader where
  get = do
    _griddedCorrectionHeader_time <- get
    _griddedCorrectionHeader_num_msgs <- getWord16le
    _griddedCorrectionHeader_seq_num <- getWord16le
    _griddedCorrectionHeader_ssr_update_interval <- getWord16le
    _griddedCorrectionHeader_iod_ssr <- getWord8
    _griddedCorrectionHeader_tropo_quality <- getWord8
    pure GriddedCorrectionHeader {..}

  put GriddedCorrectionHeader {..} = do
    put _griddedCorrectionHeader_time
    putWord16le _griddedCorrectionHeader_num_msgs
    putWord16le _griddedCorrectionHeader_seq_num
    putWord16le _griddedCorrectionHeader_ssr_update_interval
    putWord8 _griddedCorrectionHeader_iod_ssr
    putWord8 _griddedCorrectionHeader_tropo_quality

$(makeJSON "_griddedCorrectionHeader_" ''GriddedCorrectionHeader)
$(makeLenses ''GriddedCorrectionHeader)

-- | STECSatElement.
--
-- STEC for the given satellite.
data STECSatElement = STECSatElement
  { _sTECSatElement_sv_id                :: !SvId
    -- ^ Unique space vehicle identifier
  , _sTECSatElement_stec_quality_indicator :: !Word8
    -- ^ quality of STEC data
  , _sTECSatElement_stec_coeff           :: ![Int16]
    -- ^ coefficents of the STEC polynomial
  } deriving ( Show, Read, Eq )

instance Binary STECSatElement where
  get = do
    _sTECSatElement_sv_id <- get
    _sTECSatElement_stec_quality_indicator <- getWord8
    _sTECSatElement_stec_coeff <- replicateM 4 fromIntegral <$> getWord16le
    pure STECSatElement {..}

  put STECSatElement {..} = do
    put _sTECSatElement_sv_id
    putWord8 _sTECSatElement_stec_quality_indicator
    mapM_ (putWord16le . fromIntegral) _sTECSatElement_stec_coeff

$(makeJSON "_sTECSatElement_" ''STECSatElement)
$(makeLenses ''STECSatElement)

-- | TroposphericDelayCorrection.
--
-- Contains wet vertical and hydrostatic vertical delay
data TroposphericDelayCorrection = TroposphericDelayCorrection
  { _troposphericDelayCorrection_hydro :: !Int16
    -- ^ hydrostatic vertical delay
  , _troposphericDelayCorrection_wet :: !Int8
    -- ^ wet vertical delay
  } deriving ( Show, Read, Eq )

instance Binary TroposphericDelayCorrection where
  get = do
    _troposphericDelayCorrection_hydro <- fromIntegral <$> getWord16le
    _troposphericDelayCorrection_wet <- fromIntegral <$> getWord8
    pure TroposphericDelayCorrection {..}

  put TroposphericDelayCorrection {..} = do
    (putWord16le . fromIntegral) _troposphericDelayCorrection_hydro
    (putWord8 . fromIntegral) _troposphericDelayCorrection_wet

$(makeJSON "_troposphericDelayCorrection_" ''TroposphericDelayCorrection)
$(makeLenses ''TroposphericDelayCorrection)

-- | STECResidual.
--
-- STEC residual
data STECResidual = STECResidual
  { _sTECResidual_sv_id  :: !SvId
    -- ^ space vehicle identifier
  , _sTECResidual_residual :: !Int16
    -- ^ STEC residual
  } deriving ( Show, Read, Eq )

instance Binary STECResidual where
  get = do
    _sTECResidual_sv_id <- get
    _sTECResidual_residual <- fromIntegral <$> getWord16le
    pure STECResidual {..}

  put STECResidual {..} = do
    put _sTECResidual_sv_id
    (putWord16le . fromIntegral) _sTECResidual_residual

$(makeJSON "_sTECResidual_" ''STECResidual)
$(makeLenses ''STECResidual)

-- | GridElement.
--
-- Contains one tropo datum, plus STEC residuals for each space vehicle
data GridElement = GridElement
  { _gridElement_index                :: !Word16
    -- ^ index of the grid point
  , _gridElement_tropo_delay_correction :: !TroposphericDelayCorrection
    -- ^ Wet and Hydrostatic Vertical Delay
  , _gridElement_STEC_residuals       :: ![STECResidual]
    -- ^ STEC Residual for the given space vehicle
  } deriving ( Show, Read, Eq )

instance Binary GridElement where
  get = do
    _gridElement_index <- getWord16le
    _gridElement_tropo_delay_correction <- get
    _gridElement_STEC_residuals <- whileM (not <$> isEmpty) get
    pure GridElement {..}

  put GridElement {..} = do
    putWord16le _gridElement_index
    put _gridElement_tropo_delay_correction
    mapM_ put _gridElement_STEC_residuals

$(makeJSON "_gridElement_" ''GridElement)
$(makeLenses ''GridElement)

-- | GridDefinitionHeader.
--
-- Defines the grid for STEC and tropo grid messages. Also includes an RLE
-- encoded validity list.
data GridDefinitionHeader = GridDefinitionHeader
  { _gridDefinitionHeader_region_size_inverse :: !Word8
    -- ^ inverse of region size
  , _gridDefinitionHeader_area_width        :: !Word16
    -- ^ area width; see spec for details
  , _gridDefinitionHeader_lat_nw_corner_enc :: !Word16
    -- ^ encoded latitude of the northwest corner of the grid
  , _gridDefinitionHeader_lon_nw_corner_enc :: !Word16
    -- ^ encoded longitude of the northwest corner of the grid
  , _gridDefinitionHeader_num_msgs          :: !Word8
    -- ^ Number of messages in the dataset
  , _gridDefinitionHeader_seq_num           :: !Word8
    -- ^ Postion of this message in the dataset
  } deriving ( Show, Read, Eq )

instance Binary GridDefinitionHeader where
  get = do
    _gridDefinitionHeader_region_size_inverse <- getWord8
    _gridDefinitionHeader_area_width <- getWord16le
    _gridDefinitionHeader_lat_nw_corner_enc <- getWord16le
    _gridDefinitionHeader_lon_nw_corner_enc <- getWord16le
    _gridDefinitionHeader_num_msgs <- getWord8
    _gridDefinitionHeader_seq_num <- getWord8
    pure GridDefinitionHeader {..}

  put GridDefinitionHeader {..} = do
    putWord8 _gridDefinitionHeader_region_size_inverse
    putWord16le _gridDefinitionHeader_area_width
    putWord16le _gridDefinitionHeader_lat_nw_corner_enc
    putWord16le _gridDefinitionHeader_lon_nw_corner_enc
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
    -- ^ Update interval between consecutive corrections
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
    _msgSsrOrbitClock_radial <- fromIntegral <$> getWord32le
    _msgSsrOrbitClock_along <- fromIntegral <$> getWord32le
    _msgSsrOrbitClock_cross <- fromIntegral <$> getWord32le
    _msgSsrOrbitClock_dot_radial <- fromIntegral <$> getWord32le
    _msgSsrOrbitClock_dot_along <- fromIntegral <$> getWord32le
    _msgSsrOrbitClock_dot_cross <- fromIntegral <$> getWord32le
    _msgSsrOrbitClock_c0 <- fromIntegral <$> getWord32le
    _msgSsrOrbitClock_c1 <- fromIntegral <$> getWord32le
    _msgSsrOrbitClock_c2 <- fromIntegral <$> getWord32le
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
    -- ^ Update interval between consecutive corrections
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
    _msgSsrOrbitClockDepA_radial <- fromIntegral <$> getWord32le
    _msgSsrOrbitClockDepA_along <- fromIntegral <$> getWord32le
    _msgSsrOrbitClockDepA_cross <- fromIntegral <$> getWord32le
    _msgSsrOrbitClockDepA_dot_radial <- fromIntegral <$> getWord32le
    _msgSsrOrbitClockDepA_dot_along <- fromIntegral <$> getWord32le
    _msgSsrOrbitClockDepA_dot_cross <- fromIntegral <$> getWord32le
    _msgSsrOrbitClockDepA_c0 <- fromIntegral <$> getWord32le
    _msgSsrOrbitClockDepA_c1 <- fromIntegral <$> getWord32le
    _msgSsrOrbitClockDepA_c2 <- fromIntegral <$> getWord32le
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
    -- ^ Update interval between consecutive corrections
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
    -- ^ Update interval between consecutive corrections
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
    _msgSsrPhaseBiases_yaw_rate <- fromIntegral <$> getWord8
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

msgSsrStecCorrection :: Word16
msgSsrStecCorrection = 0x05EB

-- | SBP class for message MSG_SSR_STEC_CORRECTION (0x05EB).
--
-- The STEC per space vehicle, given as polynomial approximation for a given
-- grid.  This should be combined with SSR-GriddedCorrection message to get the
-- state space representation of the atmospheric delay.
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

msgSsrGriddedCorrection :: Word16
msgSsrGriddedCorrection = 0x05F0

-- | SBP class for message MSG_SSR_GRIDDED_CORRECTION (0x05F0).
--
-- STEC residuals are per space vehicle, tropo is not.
data MsgSsrGriddedCorrection = MsgSsrGriddedCorrection
  { _msgSsrGriddedCorrection_header :: !GriddedCorrectionHeader
    -- ^ Header of a Gridded Correction message
  , _msgSsrGriddedCorrection_element :: !GridElement
    -- ^ Tropo and STEC residuals for the given grid point
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

msgSsrGridDefinition :: Word16
msgSsrGridDefinition = 0x05F5

-- | SBP class for message MSG_SSR_GRID_DEFINITION (0x05F5).
--
-- Definition of the grid for STEC and tropo messages
data MsgSsrGridDefinition = MsgSsrGridDefinition
  { _msgSsrGridDefinition_header :: !GridDefinitionHeader
    -- ^ Header of a Gridded Correction message
  , _msgSsrGridDefinition_rle_list :: ![Word8]
    -- ^ Run Length Encode list of quadrants that contain valid data. The spec
    -- describes the encoding scheme in detail, but essentially the index of
    -- the quadrants that contain transitions between valid and invalid (and
    -- vice versa) are encoded as u8 integers.
  } deriving ( Show, Read, Eq )

instance Binary MsgSsrGridDefinition where
  get = do
    _msgSsrGridDefinition_header <- get
    _msgSsrGridDefinition_rle_list <- whileM (not <$> isEmpty) getWord8
    pure MsgSsrGridDefinition {..}

  put MsgSsrGridDefinition {..} = do
    put _msgSsrGridDefinition_header
    mapM_ putWord8 _msgSsrGridDefinition_rle_list

$(makeSBP 'msgSsrGridDefinition ''MsgSsrGridDefinition)
$(makeJSON "_msgSsrGridDefinition_" ''MsgSsrGridDefinition)
$(makeLenses ''MsgSsrGridDefinition)
