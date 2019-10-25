{-# OPTIONS_GHC -fno-warn-unused-imports #-}
{-# LANGUAGE NoImplicitPrelude           #-}
{-# LANGUAGE TemplateHaskell             #-}
{-# LANGUAGE RecordWildCards             #-}

-- |
-- Module:      SwiftNav.SBP.Observation
-- Copyright:   Copyright (C) 2015-2018 Swift Navigation, Inc.
-- License:     LGPL-3
-- Maintainer:  Swift Navigation <dev@swiftnav.com>
-- Stability:   experimental
-- Portability: portable
--
-- \<Satellite observation messages from the device.\>

module SwiftNav.SBP.Observation
  ( module SwiftNav.SBP.Observation
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


-- | ObservationHeader.
--
-- Header of a GNSS observation message.
data ObservationHeader = ObservationHeader
  { _observationHeader_t   :: !GpsTime
    -- ^ GNSS time of this observation
  , _observationHeader_n_obs :: !Word8
    -- ^ Total number of observations. First nibble is the size of the sequence
    -- (n), second nibble is the zero-indexed counter (ith packet of n)
  } deriving ( Show, Read, Eq )

instance Binary ObservationHeader where
  get = do
    _observationHeader_t <- get
    _observationHeader_n_obs <- getWord8
    pure ObservationHeader {..}

  put ObservationHeader {..} = do
    put _observationHeader_t
    putWord8 _observationHeader_n_obs

$(makeJSON "_observationHeader_" ''ObservationHeader)
$(makeLenses ''ObservationHeader)

-- | Doppler.
--
-- Doppler measurement in Hz represented as a 24-bit fixed point number with
-- Q16.8 layout, i.e. 16-bits of whole doppler and 8-bits of fractional
-- doppler. This doppler is defined as positive for approaching satellites.
data Doppler = Doppler
  { _doppler_i :: !Int16
    -- ^ Doppler whole Hz
  , _doppler_f :: !Word8
    -- ^ Doppler fractional part
  } deriving ( Show, Read, Eq )

instance Binary Doppler where
  get = do
    _doppler_i <- fromIntegral <$> getWord16le
    _doppler_f <- getWord8
    pure Doppler {..}

  put Doppler {..} = do
    (putWord16le . fromIntegral) _doppler_i
    putWord8 _doppler_f

$(makeJSON "_doppler_" ''Doppler)
$(makeLenses ''Doppler)

-- | PackedObsContent.
--
-- Pseudorange and carrier phase observation for a satellite being tracked. The
-- observations are interoperable with 3rd party receivers and conform with
-- typical RTCM 3.1 message GPS/GLO observations.  Carrier phase observations
-- are not guaranteed to be aligned to the RINEX 3 or RTCM 3.3 MSM reference
-- signal and no 1/4 cycle adjustments are currently peformed.
data PackedObsContent = PackedObsContent
  { _packedObsContent_P   :: !Word32
    -- ^ Pseudorange observation
  , _packedObsContent_L   :: !CarrierPhase
    -- ^ Carrier phase observation with typical sign convention.
  , _packedObsContent_D   :: !Doppler
    -- ^ Doppler observation with typical sign convention.
  , _packedObsContent_cn0 :: !Word8
    -- ^ Carrier-to-Noise density.  Zero implies invalid cn0.
  , _packedObsContent_lock :: !Word8
    -- ^ Lock timer. This value gives an indication of the time for which a
    -- signal has maintained continuous phase lock. Whenever a signal has lost
    -- and regained lock, this value is reset to zero. It is encoded according
    -- to DF402 from the RTCM 10403.2 Amendment 2 specification.  Valid values
    -- range from 0 to 15 and the most significant nibble is reserved for
    -- future use.
  , _packedObsContent_flags :: !Word8
    -- ^ Measurement status flags. A bit field of flags providing the status of
    -- this observation.  If this field is 0 it means only the Cn0 estimate for
    -- the signal is valid.
  , _packedObsContent_sid :: !GnssSignal
    -- ^ GNSS signal identifier (16 bit)
  } deriving ( Show, Read, Eq )

instance Binary PackedObsContent where
  get = do
    _packedObsContent_P <- getWord32le
    _packedObsContent_L <- get
    _packedObsContent_D <- get
    _packedObsContent_cn0 <- getWord8
    _packedObsContent_lock <- getWord8
    _packedObsContent_flags <- getWord8
    _packedObsContent_sid <- get
    pure PackedObsContent {..}

  put PackedObsContent {..} = do
    putWord32le _packedObsContent_P
    put _packedObsContent_L
    put _packedObsContent_D
    putWord8 _packedObsContent_cn0
    putWord8 _packedObsContent_lock
    putWord8 _packedObsContent_flags
    put _packedObsContent_sid

$(makeJSON "_packedObsContent_" ''PackedObsContent)
$(makeLenses ''PackedObsContent)

-- | PackedOsrContent.
--
-- Pseudorange and carrier phase network corrections for a satellite signal.
data PackedOsrContent = PackedOsrContent
  { _packedOsrContent_P       :: !Word32
    -- ^ Pseudorange observation
  , _packedOsrContent_L       :: !CarrierPhase
    -- ^ Carrier phase observation with typical sign convention.
  , _packedOsrContent_lock    :: !Word8
    -- ^ Lock timer. This value gives an indication of the time for which a
    -- signal has maintained continuous phase lock. Whenever a signal has lost
    -- and regained lock, this value is reset to zero. It is encoded according
    -- to DF402 from the RTCM 10403.2 Amendment 2 specification.  Valid values
    -- range from 0 to 15 and the most significant nibble is reserved for
    -- future use.
  , _packedOsrContent_flags   :: !Word8
    -- ^ Correction flags.
  , _packedOsrContent_sid     :: !GnssSignal
    -- ^ GNSS signal identifier (16 bit)
  , _packedOsrContent_iono_std :: !Word16
    -- ^ Slant ionospheric correction standard deviation
  , _packedOsrContent_tropo_std :: !Word16
    -- ^ Slant tropospheric correction standard deviation
  , _packedOsrContent_range_std :: !Word16
    -- ^ Orbit/clock/bias correction projected on range standard deviation
  } deriving ( Show, Read, Eq )

instance Binary PackedOsrContent where
  get = do
    _packedOsrContent_P <- getWord32le
    _packedOsrContent_L <- get
    _packedOsrContent_lock <- getWord8
    _packedOsrContent_flags <- getWord8
    _packedOsrContent_sid <- get
    _packedOsrContent_iono_std <- getWord16le
    _packedOsrContent_tropo_std <- getWord16le
    _packedOsrContent_range_std <- getWord16le
    pure PackedOsrContent {..}

  put PackedOsrContent {..} = do
    putWord32le _packedOsrContent_P
    put _packedOsrContent_L
    putWord8 _packedOsrContent_lock
    putWord8 _packedOsrContent_flags
    put _packedOsrContent_sid
    putWord16le _packedOsrContent_iono_std
    putWord16le _packedOsrContent_tropo_std
    putWord16le _packedOsrContent_range_std

$(makeJSON "_packedOsrContent_" ''PackedOsrContent)
$(makeLenses ''PackedOsrContent)

msgObs :: Word16
msgObs = 0x004A

-- | SBP class for message MSG_OBS (0x004A).
--
-- The GPS observations message reports all the raw pseudorange and carrier
-- phase observations for the satellites being tracked by the device. Carrier
-- phase observation here is represented as a 40-bit fixed point number with
-- Q32.8 layout (i.e. 32-bits of whole cycles and 8-bits of fractional cycles).
-- The observations are be interoperable with 3rd party receivers and conform
-- with typical RTCMv3 GNSS observations.
data MsgObs = MsgObs
  { _msgObs_header :: !ObservationHeader
    -- ^ Header of a GPS observation message
  , _msgObs_obs  :: ![PackedObsContent]
    -- ^ Pseudorange and carrier phase observation for a satellite being tracked.
  } deriving ( Show, Read, Eq )

instance Binary MsgObs where
  get = do
    _msgObs_header <- get
    _msgObs_obs <- whileM (not <$> isEmpty) get
    pure MsgObs {..}

  put MsgObs {..} = do
    put _msgObs_header
    mapM_ put _msgObs_obs

$(makeSBP 'msgObs ''MsgObs)
$(makeJSON "_msgObs_" ''MsgObs)
$(makeLenses ''MsgObs)

msgBasePosLlh :: Word16
msgBasePosLlh = 0x0044

-- | SBP class for message MSG_BASE_POS_LLH (0x0044).
--
-- The base station position message is the position reported by the base
-- station itself. It is used for pseudo-absolute RTK positioning, and is
-- required to be a high-accuracy surveyed location of the base station. Any
-- error here will result in an error in the pseudo-absolute position output.
data MsgBasePosLlh = MsgBasePosLlh
  { _msgBasePosLlh_lat  :: !Double
    -- ^ Latitude
  , _msgBasePosLlh_lon  :: !Double
    -- ^ Longitude
  , _msgBasePosLlh_height :: !Double
    -- ^ Height
  } deriving ( Show, Read, Eq )

instance Binary MsgBasePosLlh where
  get = do
    _msgBasePosLlh_lat <- getFloat64le
    _msgBasePosLlh_lon <- getFloat64le
    _msgBasePosLlh_height <- getFloat64le
    pure MsgBasePosLlh {..}

  put MsgBasePosLlh {..} = do
    putFloat64le _msgBasePosLlh_lat
    putFloat64le _msgBasePosLlh_lon
    putFloat64le _msgBasePosLlh_height

$(makeSBP 'msgBasePosLlh ''MsgBasePosLlh)
$(makeJSON "_msgBasePosLlh_" ''MsgBasePosLlh)
$(makeLenses ''MsgBasePosLlh)

msgBasePosEcef :: Word16
msgBasePosEcef = 0x0048

-- | SBP class for message MSG_BASE_POS_ECEF (0x0048).
--
-- The base station position message is the position reported by the base
-- station itself in absolute Earth Centered Earth Fixed coordinates. It is
-- used for pseudo-absolute RTK positioning, and is required to be a high-
-- accuracy surveyed location of the base station. Any error here will result
-- in an error in the pseudo-absolute position output.
data MsgBasePosEcef = MsgBasePosEcef
  { _msgBasePosEcef_x :: !Double
    -- ^ ECEF X coodinate
  , _msgBasePosEcef_y :: !Double
    -- ^ ECEF Y coordinate
  , _msgBasePosEcef_z :: !Double
    -- ^ ECEF Z coordinate
  } deriving ( Show, Read, Eq )

instance Binary MsgBasePosEcef where
  get = do
    _msgBasePosEcef_x <- getFloat64le
    _msgBasePosEcef_y <- getFloat64le
    _msgBasePosEcef_z <- getFloat64le
    pure MsgBasePosEcef {..}

  put MsgBasePosEcef {..} = do
    putFloat64le _msgBasePosEcef_x
    putFloat64le _msgBasePosEcef_y
    putFloat64le _msgBasePosEcef_z

$(makeSBP 'msgBasePosEcef ''MsgBasePosEcef)
$(makeJSON "_msgBasePosEcef_" ''MsgBasePosEcef)
$(makeLenses ''MsgBasePosEcef)

data EphemerisCommonContent = EphemerisCommonContent
  { _ephemerisCommonContent_sid        :: !GnssSignal
    -- ^ GNSS signal identifier (16 bit)
  , _ephemerisCommonContent_toe        :: !GpsTimeSec
    -- ^ Time of Ephemerides
  , _ephemerisCommonContent_ura        :: !Float
    -- ^ User Range Accuracy
  , _ephemerisCommonContent_fit_interval :: !Word32
    -- ^ Curve fit interval
  , _ephemerisCommonContent_valid      :: !Word8
    -- ^ Status of ephemeris, 1 = valid, 0 = invalid
  , _ephemerisCommonContent_health_bits :: !Word8
    -- ^ Satellite health status. GPS: ICD-GPS-200, chapter 20.3.3.3.1.4 SBAS: 0
    -- = valid, non-zero = invalid GLO: 0 = valid, non-zero = invalid
  } deriving ( Show, Read, Eq )

instance Binary EphemerisCommonContent where
  get = do
    _ephemerisCommonContent_sid <- get
    _ephemerisCommonContent_toe <- get
    _ephemerisCommonContent_ura <- getFloat32le
    _ephemerisCommonContent_fit_interval <- getWord32le
    _ephemerisCommonContent_valid <- getWord8
    _ephemerisCommonContent_health_bits <- getWord8
    pure EphemerisCommonContent {..}

  put EphemerisCommonContent {..} = do
    put _ephemerisCommonContent_sid
    put _ephemerisCommonContent_toe
    putFloat32le _ephemerisCommonContent_ura
    putWord32le _ephemerisCommonContent_fit_interval
    putWord8 _ephemerisCommonContent_valid
    putWord8 _ephemerisCommonContent_health_bits

$(makeJSON "_ephemerisCommonContent_" ''EphemerisCommonContent)
$(makeLenses ''EphemerisCommonContent)

data EphemerisCommonContentDepB = EphemerisCommonContentDepB
  { _ephemerisCommonContentDepB_sid        :: !GnssSignal
    -- ^ GNSS signal identifier (16 bit)
  , _ephemerisCommonContentDepB_toe        :: !GpsTimeSec
    -- ^ Time of Ephemerides
  , _ephemerisCommonContentDepB_ura        :: !Double
    -- ^ User Range Accuracy
  , _ephemerisCommonContentDepB_fit_interval :: !Word32
    -- ^ Curve fit interval
  , _ephemerisCommonContentDepB_valid      :: !Word8
    -- ^ Status of ephemeris, 1 = valid, 0 = invalid
  , _ephemerisCommonContentDepB_health_bits :: !Word8
    -- ^ Satellite health status. GPS: ICD-GPS-200, chapter 20.3.3.3.1.4 Others:
    -- 0 = valid, non-zero = invalid
  } deriving ( Show, Read, Eq )

instance Binary EphemerisCommonContentDepB where
  get = do
    _ephemerisCommonContentDepB_sid <- get
    _ephemerisCommonContentDepB_toe <- get
    _ephemerisCommonContentDepB_ura <- getFloat64le
    _ephemerisCommonContentDepB_fit_interval <- getWord32le
    _ephemerisCommonContentDepB_valid <- getWord8
    _ephemerisCommonContentDepB_health_bits <- getWord8
    pure EphemerisCommonContentDepB {..}

  put EphemerisCommonContentDepB {..} = do
    put _ephemerisCommonContentDepB_sid
    put _ephemerisCommonContentDepB_toe
    putFloat64le _ephemerisCommonContentDepB_ura
    putWord32le _ephemerisCommonContentDepB_fit_interval
    putWord8 _ephemerisCommonContentDepB_valid
    putWord8 _ephemerisCommonContentDepB_health_bits

$(makeJSON "_ephemerisCommonContentDepB_" ''EphemerisCommonContentDepB)
$(makeLenses ''EphemerisCommonContentDepB)

data EphemerisCommonContentDepA = EphemerisCommonContentDepA
  { _ephemerisCommonContentDepA_sid        :: !GnssSignalDep
    -- ^ GNSS signal identifier
  , _ephemerisCommonContentDepA_toe        :: !GpsTimeDep
    -- ^ Time of Ephemerides
  , _ephemerisCommonContentDepA_ura        :: !Double
    -- ^ User Range Accuracy
  , _ephemerisCommonContentDepA_fit_interval :: !Word32
    -- ^ Curve fit interval
  , _ephemerisCommonContentDepA_valid      :: !Word8
    -- ^ Status of ephemeris, 1 = valid, 0 = invalid
  , _ephemerisCommonContentDepA_health_bits :: !Word8
    -- ^ Satellite health status. GPS: ICD-GPS-200, chapter 20.3.3.3.1.4 SBAS: 0
    -- = valid, non-zero = invalid GLO: 0 = valid, non-zero = invalid
  } deriving ( Show, Read, Eq )

instance Binary EphemerisCommonContentDepA where
  get = do
    _ephemerisCommonContentDepA_sid <- get
    _ephemerisCommonContentDepA_toe <- get
    _ephemerisCommonContentDepA_ura <- getFloat64le
    _ephemerisCommonContentDepA_fit_interval <- getWord32le
    _ephemerisCommonContentDepA_valid <- getWord8
    _ephemerisCommonContentDepA_health_bits <- getWord8
    pure EphemerisCommonContentDepA {..}

  put EphemerisCommonContentDepA {..} = do
    put _ephemerisCommonContentDepA_sid
    put _ephemerisCommonContentDepA_toe
    putFloat64le _ephemerisCommonContentDepA_ura
    putWord32le _ephemerisCommonContentDepA_fit_interval
    putWord8 _ephemerisCommonContentDepA_valid
    putWord8 _ephemerisCommonContentDepA_health_bits

$(makeJSON "_ephemerisCommonContentDepA_" ''EphemerisCommonContentDepA)
$(makeLenses ''EphemerisCommonContentDepA)

msgEphemerisGpsDepE :: Word16
msgEphemerisGpsDepE = 0x0081

-- | SBP class for message MSG_EPHEMERIS_GPS_DEP_E (0x0081).
--
-- The ephemeris message returns a set of satellite orbit parameters that is
-- used to calculate GPS satellite position, velocity, and clock offset. Please
-- see the Navstar GPS Space Segment/Navigation user interfaces (ICD-GPS-200,
-- Table 20-III) for more details.
data MsgEphemerisGpsDepE = MsgEphemerisGpsDepE
  { _msgEphemerisGpsDepE_common :: !EphemerisCommonContentDepA
    -- ^ Values common for all ephemeris types
  , _msgEphemerisGpsDepE_tgd    :: !Double
    -- ^ Group delay differential between L1 and L2
  , _msgEphemerisGpsDepE_c_rs   :: !Double
    -- ^ Amplitude of the sine harmonic correction term to the orbit radius
  , _msgEphemerisGpsDepE_c_rc   :: !Double
    -- ^ Amplitude of the cosine harmonic correction term to the orbit radius
  , _msgEphemerisGpsDepE_c_uc   :: !Double
    -- ^ Amplitude of the cosine harmonic correction term to the argument of
    -- latitude
  , _msgEphemerisGpsDepE_c_us   :: !Double
    -- ^ Amplitude of the sine harmonic correction term to the argument of
    -- latitude
  , _msgEphemerisGpsDepE_c_ic   :: !Double
    -- ^ Amplitude of the cosine harmonic correction term to the angle of
    -- inclination
  , _msgEphemerisGpsDepE_c_is   :: !Double
    -- ^ Amplitude of the sine harmonic correction term to the angle of
    -- inclination
  , _msgEphemerisGpsDepE_dn     :: !Double
    -- ^ Mean motion difference
  , _msgEphemerisGpsDepE_m0     :: !Double
    -- ^ Mean anomaly at reference time
  , _msgEphemerisGpsDepE_ecc    :: !Double
    -- ^ Eccentricity of satellite orbit
  , _msgEphemerisGpsDepE_sqrta  :: !Double
    -- ^ Square root of the semi-major axis of orbit
  , _msgEphemerisGpsDepE_omega0 :: !Double
    -- ^ Longitude of ascending node of orbit plane at weekly epoch
  , _msgEphemerisGpsDepE_omegadot :: !Double
    -- ^ Rate of right ascension
  , _msgEphemerisGpsDepE_w      :: !Double
    -- ^ Argument of perigee
  , _msgEphemerisGpsDepE_inc    :: !Double
    -- ^ Inclination
  , _msgEphemerisGpsDepE_inc_dot :: !Double
    -- ^ Inclination first derivative
  , _msgEphemerisGpsDepE_af0    :: !Double
    -- ^ Polynomial clock correction coefficient (clock bias)
  , _msgEphemerisGpsDepE_af1    :: !Double
    -- ^ Polynomial clock correction coefficient (clock drift)
  , _msgEphemerisGpsDepE_af2    :: !Double
    -- ^ Polynomial clock correction coefficient (rate of clock drift)
  , _msgEphemerisGpsDepE_toc    :: !GpsTimeDep
    -- ^ Clock reference
  , _msgEphemerisGpsDepE_iode   :: !Word8
    -- ^ Issue of ephemeris data
  , _msgEphemerisGpsDepE_iodc   :: !Word16
    -- ^ Issue of clock data
  } deriving ( Show, Read, Eq )

instance Binary MsgEphemerisGpsDepE where
  get = do
    _msgEphemerisGpsDepE_common <- get
    _msgEphemerisGpsDepE_tgd <- getFloat64le
    _msgEphemerisGpsDepE_c_rs <- getFloat64le
    _msgEphemerisGpsDepE_c_rc <- getFloat64le
    _msgEphemerisGpsDepE_c_uc <- getFloat64le
    _msgEphemerisGpsDepE_c_us <- getFloat64le
    _msgEphemerisGpsDepE_c_ic <- getFloat64le
    _msgEphemerisGpsDepE_c_is <- getFloat64le
    _msgEphemerisGpsDepE_dn <- getFloat64le
    _msgEphemerisGpsDepE_m0 <- getFloat64le
    _msgEphemerisGpsDepE_ecc <- getFloat64le
    _msgEphemerisGpsDepE_sqrta <- getFloat64le
    _msgEphemerisGpsDepE_omega0 <- getFloat64le
    _msgEphemerisGpsDepE_omegadot <- getFloat64le
    _msgEphemerisGpsDepE_w <- getFloat64le
    _msgEphemerisGpsDepE_inc <- getFloat64le
    _msgEphemerisGpsDepE_inc_dot <- getFloat64le
    _msgEphemerisGpsDepE_af0 <- getFloat64le
    _msgEphemerisGpsDepE_af1 <- getFloat64le
    _msgEphemerisGpsDepE_af2 <- getFloat64le
    _msgEphemerisGpsDepE_toc <- get
    _msgEphemerisGpsDepE_iode <- getWord8
    _msgEphemerisGpsDepE_iodc <- getWord16le
    pure MsgEphemerisGpsDepE {..}

  put MsgEphemerisGpsDepE {..} = do
    put _msgEphemerisGpsDepE_common
    putFloat64le _msgEphemerisGpsDepE_tgd
    putFloat64le _msgEphemerisGpsDepE_c_rs
    putFloat64le _msgEphemerisGpsDepE_c_rc
    putFloat64le _msgEphemerisGpsDepE_c_uc
    putFloat64le _msgEphemerisGpsDepE_c_us
    putFloat64le _msgEphemerisGpsDepE_c_ic
    putFloat64le _msgEphemerisGpsDepE_c_is
    putFloat64le _msgEphemerisGpsDepE_dn
    putFloat64le _msgEphemerisGpsDepE_m0
    putFloat64le _msgEphemerisGpsDepE_ecc
    putFloat64le _msgEphemerisGpsDepE_sqrta
    putFloat64le _msgEphemerisGpsDepE_omega0
    putFloat64le _msgEphemerisGpsDepE_omegadot
    putFloat64le _msgEphemerisGpsDepE_w
    putFloat64le _msgEphemerisGpsDepE_inc
    putFloat64le _msgEphemerisGpsDepE_inc_dot
    putFloat64le _msgEphemerisGpsDepE_af0
    putFloat64le _msgEphemerisGpsDepE_af1
    putFloat64le _msgEphemerisGpsDepE_af2
    put _msgEphemerisGpsDepE_toc
    putWord8 _msgEphemerisGpsDepE_iode
    putWord16le _msgEphemerisGpsDepE_iodc

$(makeSBP 'msgEphemerisGpsDepE ''MsgEphemerisGpsDepE)
$(makeJSON "_msgEphemerisGpsDepE_" ''MsgEphemerisGpsDepE)
$(makeLenses ''MsgEphemerisGpsDepE)

msgEphemerisGpsDepF :: Word16
msgEphemerisGpsDepF = 0x0086

-- | SBP class for message MSG_EPHEMERIS_GPS_DEP_F (0x0086).
--
-- This observation message has been deprecated in favor of ephemeris message
-- using floats for size reduction.
data MsgEphemerisGpsDepF = MsgEphemerisGpsDepF
  { _msgEphemerisGpsDepF_common :: !EphemerisCommonContentDepB
    -- ^ Values common for all ephemeris types
  , _msgEphemerisGpsDepF_tgd    :: !Double
    -- ^ Group delay differential between L1 and L2
  , _msgEphemerisGpsDepF_c_rs   :: !Double
    -- ^ Amplitude of the sine harmonic correction term to the orbit radius
  , _msgEphemerisGpsDepF_c_rc   :: !Double
    -- ^ Amplitude of the cosine harmonic correction term to the orbit radius
  , _msgEphemerisGpsDepF_c_uc   :: !Double
    -- ^ Amplitude of the cosine harmonic correction term to the argument of
    -- latitude
  , _msgEphemerisGpsDepF_c_us   :: !Double
    -- ^ Amplitude of the sine harmonic correction term to the argument of
    -- latitude
  , _msgEphemerisGpsDepF_c_ic   :: !Double
    -- ^ Amplitude of the cosine harmonic correction term to the angle of
    -- inclination
  , _msgEphemerisGpsDepF_c_is   :: !Double
    -- ^ Amplitude of the sine harmonic correction term to the angle of
    -- inclination
  , _msgEphemerisGpsDepF_dn     :: !Double
    -- ^ Mean motion difference
  , _msgEphemerisGpsDepF_m0     :: !Double
    -- ^ Mean anomaly at reference time
  , _msgEphemerisGpsDepF_ecc    :: !Double
    -- ^ Eccentricity of satellite orbit
  , _msgEphemerisGpsDepF_sqrta  :: !Double
    -- ^ Square root of the semi-major axis of orbit
  , _msgEphemerisGpsDepF_omega0 :: !Double
    -- ^ Longitude of ascending node of orbit plane at weekly epoch
  , _msgEphemerisGpsDepF_omegadot :: !Double
    -- ^ Rate of right ascension
  , _msgEphemerisGpsDepF_w      :: !Double
    -- ^ Argument of perigee
  , _msgEphemerisGpsDepF_inc    :: !Double
    -- ^ Inclination
  , _msgEphemerisGpsDepF_inc_dot :: !Double
    -- ^ Inclination first derivative
  , _msgEphemerisGpsDepF_af0    :: !Double
    -- ^ Polynomial clock correction coefficient (clock bias)
  , _msgEphemerisGpsDepF_af1    :: !Double
    -- ^ Polynomial clock correction coefficient (clock drift)
  , _msgEphemerisGpsDepF_af2    :: !Double
    -- ^ Polynomial clock correction coefficient (rate of clock drift)
  , _msgEphemerisGpsDepF_toc    :: !GpsTimeSec
    -- ^ Clock reference
  , _msgEphemerisGpsDepF_iode   :: !Word8
    -- ^ Issue of ephemeris data
  , _msgEphemerisGpsDepF_iodc   :: !Word16
    -- ^ Issue of clock data
  } deriving ( Show, Read, Eq )

instance Binary MsgEphemerisGpsDepF where
  get = do
    _msgEphemerisGpsDepF_common <- get
    _msgEphemerisGpsDepF_tgd <- getFloat64le
    _msgEphemerisGpsDepF_c_rs <- getFloat64le
    _msgEphemerisGpsDepF_c_rc <- getFloat64le
    _msgEphemerisGpsDepF_c_uc <- getFloat64le
    _msgEphemerisGpsDepF_c_us <- getFloat64le
    _msgEphemerisGpsDepF_c_ic <- getFloat64le
    _msgEphemerisGpsDepF_c_is <- getFloat64le
    _msgEphemerisGpsDepF_dn <- getFloat64le
    _msgEphemerisGpsDepF_m0 <- getFloat64le
    _msgEphemerisGpsDepF_ecc <- getFloat64le
    _msgEphemerisGpsDepF_sqrta <- getFloat64le
    _msgEphemerisGpsDepF_omega0 <- getFloat64le
    _msgEphemerisGpsDepF_omegadot <- getFloat64le
    _msgEphemerisGpsDepF_w <- getFloat64le
    _msgEphemerisGpsDepF_inc <- getFloat64le
    _msgEphemerisGpsDepF_inc_dot <- getFloat64le
    _msgEphemerisGpsDepF_af0 <- getFloat64le
    _msgEphemerisGpsDepF_af1 <- getFloat64le
    _msgEphemerisGpsDepF_af2 <- getFloat64le
    _msgEphemerisGpsDepF_toc <- get
    _msgEphemerisGpsDepF_iode <- getWord8
    _msgEphemerisGpsDepF_iodc <- getWord16le
    pure MsgEphemerisGpsDepF {..}

  put MsgEphemerisGpsDepF {..} = do
    put _msgEphemerisGpsDepF_common
    putFloat64le _msgEphemerisGpsDepF_tgd
    putFloat64le _msgEphemerisGpsDepF_c_rs
    putFloat64le _msgEphemerisGpsDepF_c_rc
    putFloat64le _msgEphemerisGpsDepF_c_uc
    putFloat64le _msgEphemerisGpsDepF_c_us
    putFloat64le _msgEphemerisGpsDepF_c_ic
    putFloat64le _msgEphemerisGpsDepF_c_is
    putFloat64le _msgEphemerisGpsDepF_dn
    putFloat64le _msgEphemerisGpsDepF_m0
    putFloat64le _msgEphemerisGpsDepF_ecc
    putFloat64le _msgEphemerisGpsDepF_sqrta
    putFloat64le _msgEphemerisGpsDepF_omega0
    putFloat64le _msgEphemerisGpsDepF_omegadot
    putFloat64le _msgEphemerisGpsDepF_w
    putFloat64le _msgEphemerisGpsDepF_inc
    putFloat64le _msgEphemerisGpsDepF_inc_dot
    putFloat64le _msgEphemerisGpsDepF_af0
    putFloat64le _msgEphemerisGpsDepF_af1
    putFloat64le _msgEphemerisGpsDepF_af2
    put _msgEphemerisGpsDepF_toc
    putWord8 _msgEphemerisGpsDepF_iode
    putWord16le _msgEphemerisGpsDepF_iodc

$(makeSBP 'msgEphemerisGpsDepF ''MsgEphemerisGpsDepF)
$(makeJSON "_msgEphemerisGpsDepF_" ''MsgEphemerisGpsDepF)
$(makeLenses ''MsgEphemerisGpsDepF)

msgEphemerisGps :: Word16
msgEphemerisGps = 0x008A

-- | SBP class for message MSG_EPHEMERIS_GPS (0x008A).
--
-- The ephemeris message returns a set of satellite orbit parameters that is
-- used to calculate GPS satellite position, velocity, and clock offset. Please
-- see the Navstar GPS Space Segment/Navigation user interfaces (ICD-GPS-200,
-- Table 20-III) for more details.
data MsgEphemerisGps = MsgEphemerisGps
  { _msgEphemerisGps_common :: !EphemerisCommonContent
    -- ^ Values common for all ephemeris types
  , _msgEphemerisGps_tgd    :: !Float
    -- ^ Group delay differential between L1 and L2
  , _msgEphemerisGps_c_rs   :: !Float
    -- ^ Amplitude of the sine harmonic correction term to the orbit radius
  , _msgEphemerisGps_c_rc   :: !Float
    -- ^ Amplitude of the cosine harmonic correction term to the orbit radius
  , _msgEphemerisGps_c_uc   :: !Float
    -- ^ Amplitude of the cosine harmonic correction term to the argument of
    -- latitude
  , _msgEphemerisGps_c_us   :: !Float
    -- ^ Amplitude of the sine harmonic correction term to the argument of
    -- latitude
  , _msgEphemerisGps_c_ic   :: !Float
    -- ^ Amplitude of the cosine harmonic correction term to the angle of
    -- inclination
  , _msgEphemerisGps_c_is   :: !Float
    -- ^ Amplitude of the sine harmonic correction term to the angle of
    -- inclination
  , _msgEphemerisGps_dn     :: !Double
    -- ^ Mean motion difference
  , _msgEphemerisGps_m0     :: !Double
    -- ^ Mean anomaly at reference time
  , _msgEphemerisGps_ecc    :: !Double
    -- ^ Eccentricity of satellite orbit
  , _msgEphemerisGps_sqrta  :: !Double
    -- ^ Square root of the semi-major axis of orbit
  , _msgEphemerisGps_omega0 :: !Double
    -- ^ Longitude of ascending node of orbit plane at weekly epoch
  , _msgEphemerisGps_omegadot :: !Double
    -- ^ Rate of right ascension
  , _msgEphemerisGps_w      :: !Double
    -- ^ Argument of perigee
  , _msgEphemerisGps_inc    :: !Double
    -- ^ Inclination
  , _msgEphemerisGps_inc_dot :: !Double
    -- ^ Inclination first derivative
  , _msgEphemerisGps_af0    :: !Float
    -- ^ Polynomial clock correction coefficient (clock bias)
  , _msgEphemerisGps_af1    :: !Float
    -- ^ Polynomial clock correction coefficient (clock drift)
  , _msgEphemerisGps_af2    :: !Float
    -- ^ Polynomial clock correction coefficient (rate of clock drift)
  , _msgEphemerisGps_toc    :: !GpsTimeSec
    -- ^ Clock reference
  , _msgEphemerisGps_iode   :: !Word8
    -- ^ Issue of ephemeris data
  , _msgEphemerisGps_iodc   :: !Word16
    -- ^ Issue of clock data
  } deriving ( Show, Read, Eq )

instance Binary MsgEphemerisGps where
  get = do
    _msgEphemerisGps_common <- get
    _msgEphemerisGps_tgd <- getFloat32le
    _msgEphemerisGps_c_rs <- getFloat32le
    _msgEphemerisGps_c_rc <- getFloat32le
    _msgEphemerisGps_c_uc <- getFloat32le
    _msgEphemerisGps_c_us <- getFloat32le
    _msgEphemerisGps_c_ic <- getFloat32le
    _msgEphemerisGps_c_is <- getFloat32le
    _msgEphemerisGps_dn <- getFloat64le
    _msgEphemerisGps_m0 <- getFloat64le
    _msgEphemerisGps_ecc <- getFloat64le
    _msgEphemerisGps_sqrta <- getFloat64le
    _msgEphemerisGps_omega0 <- getFloat64le
    _msgEphemerisGps_omegadot <- getFloat64le
    _msgEphemerisGps_w <- getFloat64le
    _msgEphemerisGps_inc <- getFloat64le
    _msgEphemerisGps_inc_dot <- getFloat64le
    _msgEphemerisGps_af0 <- getFloat32le
    _msgEphemerisGps_af1 <- getFloat32le
    _msgEphemerisGps_af2 <- getFloat32le
    _msgEphemerisGps_toc <- get
    _msgEphemerisGps_iode <- getWord8
    _msgEphemerisGps_iodc <- getWord16le
    pure MsgEphemerisGps {..}

  put MsgEphemerisGps {..} = do
    put _msgEphemerisGps_common
    putFloat32le _msgEphemerisGps_tgd
    putFloat32le _msgEphemerisGps_c_rs
    putFloat32le _msgEphemerisGps_c_rc
    putFloat32le _msgEphemerisGps_c_uc
    putFloat32le _msgEphemerisGps_c_us
    putFloat32le _msgEphemerisGps_c_ic
    putFloat32le _msgEphemerisGps_c_is
    putFloat64le _msgEphemerisGps_dn
    putFloat64le _msgEphemerisGps_m0
    putFloat64le _msgEphemerisGps_ecc
    putFloat64le _msgEphemerisGps_sqrta
    putFloat64le _msgEphemerisGps_omega0
    putFloat64le _msgEphemerisGps_omegadot
    putFloat64le _msgEphemerisGps_w
    putFloat64le _msgEphemerisGps_inc
    putFloat64le _msgEphemerisGps_inc_dot
    putFloat32le _msgEphemerisGps_af0
    putFloat32le _msgEphemerisGps_af1
    putFloat32le _msgEphemerisGps_af2
    put _msgEphemerisGps_toc
    putWord8 _msgEphemerisGps_iode
    putWord16le _msgEphemerisGps_iodc

$(makeSBP 'msgEphemerisGps ''MsgEphemerisGps)
$(makeJSON "_msgEphemerisGps_" ''MsgEphemerisGps)
$(makeLenses ''MsgEphemerisGps)

msgEphemerisQzss :: Word16
msgEphemerisQzss = 0x008E

-- | SBP class for message MSG_EPHEMERIS_QZSS (0x008E).
--
-- The ephemeris message returns a set of satellite orbit parameters that is
-- used to calculate QZSS satellite position, velocity, and clock offset.
data MsgEphemerisQzss = MsgEphemerisQzss
  { _msgEphemerisQzss_common :: !EphemerisCommonContent
    -- ^ Values common for all ephemeris types
  , _msgEphemerisQzss_tgd    :: !Float
    -- ^ Group delay differential between L1 and L2
  , _msgEphemerisQzss_c_rs   :: !Float
    -- ^ Amplitude of the sine harmonic correction term to the orbit radius
  , _msgEphemerisQzss_c_rc   :: !Float
    -- ^ Amplitude of the cosine harmonic correction term to the orbit radius
  , _msgEphemerisQzss_c_uc   :: !Float
    -- ^ Amplitude of the cosine harmonic correction term to the argument of
    -- latitude
  , _msgEphemerisQzss_c_us   :: !Float
    -- ^ Amplitude of the sine harmonic correction term to the argument of
    -- latitude
  , _msgEphemerisQzss_c_ic   :: !Float
    -- ^ Amplitude of the cosine harmonic correction term to the angle of
    -- inclination
  , _msgEphemerisQzss_c_is   :: !Float
    -- ^ Amplitude of the sine harmonic correction term to the angle of
    -- inclination
  , _msgEphemerisQzss_dn     :: !Double
    -- ^ Mean motion difference
  , _msgEphemerisQzss_m0     :: !Double
    -- ^ Mean anomaly at reference time
  , _msgEphemerisQzss_ecc    :: !Double
    -- ^ Eccentricity of satellite orbit
  , _msgEphemerisQzss_sqrta  :: !Double
    -- ^ Square root of the semi-major axis of orbit
  , _msgEphemerisQzss_omega0 :: !Double
    -- ^ Longitude of ascending node of orbit plane at weekly epoch
  , _msgEphemerisQzss_omegadot :: !Double
    -- ^ Rate of right ascension
  , _msgEphemerisQzss_w      :: !Double
    -- ^ Argument of perigee
  , _msgEphemerisQzss_inc    :: !Double
    -- ^ Inclination
  , _msgEphemerisQzss_inc_dot :: !Double
    -- ^ Inclination first derivative
  , _msgEphemerisQzss_af0    :: !Float
    -- ^ Polynomial clock correction coefficient (clock bias)
  , _msgEphemerisQzss_af1    :: !Float
    -- ^ Polynomial clock correction coefficient (clock drift)
  , _msgEphemerisQzss_af2    :: !Float
    -- ^ Polynomial clock correction coefficient (rate of clock drift)
  , _msgEphemerisQzss_toc    :: !GpsTimeSec
    -- ^ Clock reference
  , _msgEphemerisQzss_iode   :: !Word8
    -- ^ Issue of ephemeris data
  , _msgEphemerisQzss_iodc   :: !Word16
    -- ^ Issue of clock data
  } deriving ( Show, Read, Eq )

instance Binary MsgEphemerisQzss where
  get = do
    _msgEphemerisQzss_common <- get
    _msgEphemerisQzss_tgd <- getFloat32le
    _msgEphemerisQzss_c_rs <- getFloat32le
    _msgEphemerisQzss_c_rc <- getFloat32le
    _msgEphemerisQzss_c_uc <- getFloat32le
    _msgEphemerisQzss_c_us <- getFloat32le
    _msgEphemerisQzss_c_ic <- getFloat32le
    _msgEphemerisQzss_c_is <- getFloat32le
    _msgEphemerisQzss_dn <- getFloat64le
    _msgEphemerisQzss_m0 <- getFloat64le
    _msgEphemerisQzss_ecc <- getFloat64le
    _msgEphemerisQzss_sqrta <- getFloat64le
    _msgEphemerisQzss_omega0 <- getFloat64le
    _msgEphemerisQzss_omegadot <- getFloat64le
    _msgEphemerisQzss_w <- getFloat64le
    _msgEphemerisQzss_inc <- getFloat64le
    _msgEphemerisQzss_inc_dot <- getFloat64le
    _msgEphemerisQzss_af0 <- getFloat32le
    _msgEphemerisQzss_af1 <- getFloat32le
    _msgEphemerisQzss_af2 <- getFloat32le
    _msgEphemerisQzss_toc <- get
    _msgEphemerisQzss_iode <- getWord8
    _msgEphemerisQzss_iodc <- getWord16le
    pure MsgEphemerisQzss {..}

  put MsgEphemerisQzss {..} = do
    put _msgEphemerisQzss_common
    putFloat32le _msgEphemerisQzss_tgd
    putFloat32le _msgEphemerisQzss_c_rs
    putFloat32le _msgEphemerisQzss_c_rc
    putFloat32le _msgEphemerisQzss_c_uc
    putFloat32le _msgEphemerisQzss_c_us
    putFloat32le _msgEphemerisQzss_c_ic
    putFloat32le _msgEphemerisQzss_c_is
    putFloat64le _msgEphemerisQzss_dn
    putFloat64le _msgEphemerisQzss_m0
    putFloat64le _msgEphemerisQzss_ecc
    putFloat64le _msgEphemerisQzss_sqrta
    putFloat64le _msgEphemerisQzss_omega0
    putFloat64le _msgEphemerisQzss_omegadot
    putFloat64le _msgEphemerisQzss_w
    putFloat64le _msgEphemerisQzss_inc
    putFloat64le _msgEphemerisQzss_inc_dot
    putFloat32le _msgEphemerisQzss_af0
    putFloat32le _msgEphemerisQzss_af1
    putFloat32le _msgEphemerisQzss_af2
    put _msgEphemerisQzss_toc
    putWord8 _msgEphemerisQzss_iode
    putWord16le _msgEphemerisQzss_iodc

$(makeSBP 'msgEphemerisQzss ''MsgEphemerisQzss)
$(makeJSON "_msgEphemerisQzss_" ''MsgEphemerisQzss)
$(makeLenses ''MsgEphemerisQzss)

msgEphemerisBds :: Word16
msgEphemerisBds = 0x0089

-- | SBP class for message MSG_EPHEMERIS_BDS (0x0089).
--
-- The ephemeris message returns a set of satellite orbit parameters that is
-- used to calculate BDS satellite position, velocity, and clock offset. Please
-- see the BeiDou Navigation Satellite System SIS-ICD Version 2.1, Table 5-9
-- for more details.
data MsgEphemerisBds = MsgEphemerisBds
  { _msgEphemerisBds_common :: !EphemerisCommonContent
    -- ^ Values common for all ephemeris types
  , _msgEphemerisBds_tgd1   :: !Float
    -- ^ Group delay differential for B1
  , _msgEphemerisBds_tgd2   :: !Float
    -- ^ Group delay differential for B2
  , _msgEphemerisBds_c_rs   :: !Float
    -- ^ Amplitude of the sine harmonic correction term to the orbit radius
  , _msgEphemerisBds_c_rc   :: !Float
    -- ^ Amplitude of the cosine harmonic correction term to the orbit radius
  , _msgEphemerisBds_c_uc   :: !Float
    -- ^ Amplitude of the cosine harmonic correction term to the argument of
    -- latitude
  , _msgEphemerisBds_c_us   :: !Float
    -- ^ Amplitude of the sine harmonic correction term to the argument of
    -- latitude
  , _msgEphemerisBds_c_ic   :: !Float
    -- ^ Amplitude of the cosine harmonic correction term to the angle of
    -- inclination
  , _msgEphemerisBds_c_is   :: !Float
    -- ^ Amplitude of the sine harmonic correction term to the angle of
    -- inclination
  , _msgEphemerisBds_dn     :: !Double
    -- ^ Mean motion difference
  , _msgEphemerisBds_m0     :: !Double
    -- ^ Mean anomaly at reference time
  , _msgEphemerisBds_ecc    :: !Double
    -- ^ Eccentricity of satellite orbit
  , _msgEphemerisBds_sqrta  :: !Double
    -- ^ Square root of the semi-major axis of orbit
  , _msgEphemerisBds_omega0 :: !Double
    -- ^ Longitude of ascending node of orbit plane at weekly epoch
  , _msgEphemerisBds_omegadot :: !Double
    -- ^ Rate of right ascension
  , _msgEphemerisBds_w      :: !Double
    -- ^ Argument of perigee
  , _msgEphemerisBds_inc    :: !Double
    -- ^ Inclination
  , _msgEphemerisBds_inc_dot :: !Double
    -- ^ Inclination first derivative
  , _msgEphemerisBds_af0    :: !Double
    -- ^ Polynomial clock correction coefficient (clock bias)
  , _msgEphemerisBds_af1    :: !Float
    -- ^ Polynomial clock correction coefficient (clock drift)
  , _msgEphemerisBds_af2    :: !Float
    -- ^ Polynomial clock correction coefficient (rate of clock drift)
  , _msgEphemerisBds_toc    :: !GpsTimeSec
    -- ^ Clock reference
  , _msgEphemerisBds_iode   :: !Word8
    -- ^ Issue of ephemeris data
  , _msgEphemerisBds_iodc   :: !Word16
    -- ^ Issue of clock data
  } deriving ( Show, Read, Eq )

instance Binary MsgEphemerisBds where
  get = do
    _msgEphemerisBds_common <- get
    _msgEphemerisBds_tgd1 <- getFloat32le
    _msgEphemerisBds_tgd2 <- getFloat32le
    _msgEphemerisBds_c_rs <- getFloat32le
    _msgEphemerisBds_c_rc <- getFloat32le
    _msgEphemerisBds_c_uc <- getFloat32le
    _msgEphemerisBds_c_us <- getFloat32le
    _msgEphemerisBds_c_ic <- getFloat32le
    _msgEphemerisBds_c_is <- getFloat32le
    _msgEphemerisBds_dn <- getFloat64le
    _msgEphemerisBds_m0 <- getFloat64le
    _msgEphemerisBds_ecc <- getFloat64le
    _msgEphemerisBds_sqrta <- getFloat64le
    _msgEphemerisBds_omega0 <- getFloat64le
    _msgEphemerisBds_omegadot <- getFloat64le
    _msgEphemerisBds_w <- getFloat64le
    _msgEphemerisBds_inc <- getFloat64le
    _msgEphemerisBds_inc_dot <- getFloat64le
    _msgEphemerisBds_af0 <- getFloat64le
    _msgEphemerisBds_af1 <- getFloat32le
    _msgEphemerisBds_af2 <- getFloat32le
    _msgEphemerisBds_toc <- get
    _msgEphemerisBds_iode <- getWord8
    _msgEphemerisBds_iodc <- getWord16le
    pure MsgEphemerisBds {..}

  put MsgEphemerisBds {..} = do
    put _msgEphemerisBds_common
    putFloat32le _msgEphemerisBds_tgd1
    putFloat32le _msgEphemerisBds_tgd2
    putFloat32le _msgEphemerisBds_c_rs
    putFloat32le _msgEphemerisBds_c_rc
    putFloat32le _msgEphemerisBds_c_uc
    putFloat32le _msgEphemerisBds_c_us
    putFloat32le _msgEphemerisBds_c_ic
    putFloat32le _msgEphemerisBds_c_is
    putFloat64le _msgEphemerisBds_dn
    putFloat64le _msgEphemerisBds_m0
    putFloat64le _msgEphemerisBds_ecc
    putFloat64le _msgEphemerisBds_sqrta
    putFloat64le _msgEphemerisBds_omega0
    putFloat64le _msgEphemerisBds_omegadot
    putFloat64le _msgEphemerisBds_w
    putFloat64le _msgEphemerisBds_inc
    putFloat64le _msgEphemerisBds_inc_dot
    putFloat64le _msgEphemerisBds_af0
    putFloat32le _msgEphemerisBds_af1
    putFloat32le _msgEphemerisBds_af2
    put _msgEphemerisBds_toc
    putWord8 _msgEphemerisBds_iode
    putWord16le _msgEphemerisBds_iodc

$(makeSBP 'msgEphemerisBds ''MsgEphemerisBds)
$(makeJSON "_msgEphemerisBds_" ''MsgEphemerisBds)
$(makeLenses ''MsgEphemerisBds)

msgEphemerisGalDepA :: Word16
msgEphemerisGalDepA = 0x0095

-- | SBP class for message MSG_EPHEMERIS_GAL_DEP_A (0x0095).
--
-- This observation message has been deprecated in favor of an ephemeris
-- message with explicit source of NAV data.
data MsgEphemerisGalDepA = MsgEphemerisGalDepA
  { _msgEphemerisGalDepA_common  :: !EphemerisCommonContent
    -- ^ Values common for all ephemeris types
  , _msgEphemerisGalDepA_bgd_e1e5a :: !Float
    -- ^ E1-E5a Broadcast Group Delay
  , _msgEphemerisGalDepA_bgd_e1e5b :: !Float
    -- ^ E1-E5b Broadcast Group Delay
  , _msgEphemerisGalDepA_c_rs    :: !Float
    -- ^ Amplitude of the sine harmonic correction term to the orbit radius
  , _msgEphemerisGalDepA_c_rc    :: !Float
    -- ^ Amplitude of the cosine harmonic correction term to the orbit radius
  , _msgEphemerisGalDepA_c_uc    :: !Float
    -- ^ Amplitude of the cosine harmonic correction term to the argument of
    -- latitude
  , _msgEphemerisGalDepA_c_us    :: !Float
    -- ^ Amplitude of the sine harmonic correction term to the argument of
    -- latitude
  , _msgEphemerisGalDepA_c_ic    :: !Float
    -- ^ Amplitude of the cosine harmonic correction term to the angle of
    -- inclination
  , _msgEphemerisGalDepA_c_is    :: !Float
    -- ^ Amplitude of the sine harmonic correction term to the angle of
    -- inclination
  , _msgEphemerisGalDepA_dn      :: !Double
    -- ^ Mean motion difference
  , _msgEphemerisGalDepA_m0      :: !Double
    -- ^ Mean anomaly at reference time
  , _msgEphemerisGalDepA_ecc     :: !Double
    -- ^ Eccentricity of satellite orbit
  , _msgEphemerisGalDepA_sqrta   :: !Double
    -- ^ Square root of the semi-major axis of orbit
  , _msgEphemerisGalDepA_omega0  :: !Double
    -- ^ Longitude of ascending node of orbit plane at weekly epoch
  , _msgEphemerisGalDepA_omegadot :: !Double
    -- ^ Rate of right ascension
  , _msgEphemerisGalDepA_w       :: !Double
    -- ^ Argument of perigee
  , _msgEphemerisGalDepA_inc     :: !Double
    -- ^ Inclination
  , _msgEphemerisGalDepA_inc_dot :: !Double
    -- ^ Inclination first derivative
  , _msgEphemerisGalDepA_af0     :: !Double
    -- ^ Polynomial clock correction coefficient (clock bias)
  , _msgEphemerisGalDepA_af1     :: !Double
    -- ^ Polynomial clock correction coefficient (clock drift)
  , _msgEphemerisGalDepA_af2     :: !Float
    -- ^ Polynomial clock correction coefficient (rate of clock drift)
  , _msgEphemerisGalDepA_toc     :: !GpsTimeSec
    -- ^ Clock reference
  , _msgEphemerisGalDepA_iode    :: !Word16
    -- ^ Issue of ephemeris data
  , _msgEphemerisGalDepA_iodc    :: !Word16
    -- ^ Issue of clock data
  } deriving ( Show, Read, Eq )

instance Binary MsgEphemerisGalDepA where
  get = do
    _msgEphemerisGalDepA_common <- get
    _msgEphemerisGalDepA_bgd_e1e5a <- getFloat32le
    _msgEphemerisGalDepA_bgd_e1e5b <- getFloat32le
    _msgEphemerisGalDepA_c_rs <- getFloat32le
    _msgEphemerisGalDepA_c_rc <- getFloat32le
    _msgEphemerisGalDepA_c_uc <- getFloat32le
    _msgEphemerisGalDepA_c_us <- getFloat32le
    _msgEphemerisGalDepA_c_ic <- getFloat32le
    _msgEphemerisGalDepA_c_is <- getFloat32le
    _msgEphemerisGalDepA_dn <- getFloat64le
    _msgEphemerisGalDepA_m0 <- getFloat64le
    _msgEphemerisGalDepA_ecc <- getFloat64le
    _msgEphemerisGalDepA_sqrta <- getFloat64le
    _msgEphemerisGalDepA_omega0 <- getFloat64le
    _msgEphemerisGalDepA_omegadot <- getFloat64le
    _msgEphemerisGalDepA_w <- getFloat64le
    _msgEphemerisGalDepA_inc <- getFloat64le
    _msgEphemerisGalDepA_inc_dot <- getFloat64le
    _msgEphemerisGalDepA_af0 <- getFloat64le
    _msgEphemerisGalDepA_af1 <- getFloat64le
    _msgEphemerisGalDepA_af2 <- getFloat32le
    _msgEphemerisGalDepA_toc <- get
    _msgEphemerisGalDepA_iode <- getWord16le
    _msgEphemerisGalDepA_iodc <- getWord16le
    pure MsgEphemerisGalDepA {..}

  put MsgEphemerisGalDepA {..} = do
    put _msgEphemerisGalDepA_common
    putFloat32le _msgEphemerisGalDepA_bgd_e1e5a
    putFloat32le _msgEphemerisGalDepA_bgd_e1e5b
    putFloat32le _msgEphemerisGalDepA_c_rs
    putFloat32le _msgEphemerisGalDepA_c_rc
    putFloat32le _msgEphemerisGalDepA_c_uc
    putFloat32le _msgEphemerisGalDepA_c_us
    putFloat32le _msgEphemerisGalDepA_c_ic
    putFloat32le _msgEphemerisGalDepA_c_is
    putFloat64le _msgEphemerisGalDepA_dn
    putFloat64le _msgEphemerisGalDepA_m0
    putFloat64le _msgEphemerisGalDepA_ecc
    putFloat64le _msgEphemerisGalDepA_sqrta
    putFloat64le _msgEphemerisGalDepA_omega0
    putFloat64le _msgEphemerisGalDepA_omegadot
    putFloat64le _msgEphemerisGalDepA_w
    putFloat64le _msgEphemerisGalDepA_inc
    putFloat64le _msgEphemerisGalDepA_inc_dot
    putFloat64le _msgEphemerisGalDepA_af0
    putFloat64le _msgEphemerisGalDepA_af1
    putFloat32le _msgEphemerisGalDepA_af2
    put _msgEphemerisGalDepA_toc
    putWord16le _msgEphemerisGalDepA_iode
    putWord16le _msgEphemerisGalDepA_iodc

$(makeSBP 'msgEphemerisGalDepA ''MsgEphemerisGalDepA)
$(makeJSON "_msgEphemerisGalDepA_" ''MsgEphemerisGalDepA)
$(makeLenses ''MsgEphemerisGalDepA)

msgEphemerisGal :: Word16
msgEphemerisGal = 0x008D

-- | SBP class for message MSG_EPHEMERIS_GAL (0x008D).
--
-- The ephemeris message returns a set of satellite orbit parameters that is
-- used to calculate Galileo satellite position, velocity, and clock offset.
-- Please see the Signal In Space ICD OS SIS ICD, Issue 1.3, December 2016 for
-- more details.
data MsgEphemerisGal = MsgEphemerisGal
  { _msgEphemerisGal_common  :: !EphemerisCommonContent
    -- ^ Values common for all ephemeris types
  , _msgEphemerisGal_bgd_e1e5a :: !Float
    -- ^ E1-E5a Broadcast Group Delay
  , _msgEphemerisGal_bgd_e1e5b :: !Float
    -- ^ E1-E5b Broadcast Group Delay
  , _msgEphemerisGal_c_rs    :: !Float
    -- ^ Amplitude of the sine harmonic correction term to the orbit radius
  , _msgEphemerisGal_c_rc    :: !Float
    -- ^ Amplitude of the cosine harmonic correction term to the orbit radius
  , _msgEphemerisGal_c_uc    :: !Float
    -- ^ Amplitude of the cosine harmonic correction term to the argument of
    -- latitude
  , _msgEphemerisGal_c_us    :: !Float
    -- ^ Amplitude of the sine harmonic correction term to the argument of
    -- latitude
  , _msgEphemerisGal_c_ic    :: !Float
    -- ^ Amplitude of the cosine harmonic correction term to the angle of
    -- inclination
  , _msgEphemerisGal_c_is    :: !Float
    -- ^ Amplitude of the sine harmonic correction term to the angle of
    -- inclination
  , _msgEphemerisGal_dn      :: !Double
    -- ^ Mean motion difference
  , _msgEphemerisGal_m0      :: !Double
    -- ^ Mean anomaly at reference time
  , _msgEphemerisGal_ecc     :: !Double
    -- ^ Eccentricity of satellite orbit
  , _msgEphemerisGal_sqrta   :: !Double
    -- ^ Square root of the semi-major axis of orbit
  , _msgEphemerisGal_omega0  :: !Double
    -- ^ Longitude of ascending node of orbit plane at weekly epoch
  , _msgEphemerisGal_omegadot :: !Double
    -- ^ Rate of right ascension
  , _msgEphemerisGal_w       :: !Double
    -- ^ Argument of perigee
  , _msgEphemerisGal_inc     :: !Double
    -- ^ Inclination
  , _msgEphemerisGal_inc_dot :: !Double
    -- ^ Inclination first derivative
  , _msgEphemerisGal_af0     :: !Double
    -- ^ Polynomial clock correction coefficient (clock bias)
  , _msgEphemerisGal_af1     :: !Double
    -- ^ Polynomial clock correction coefficient (clock drift)
  , _msgEphemerisGal_af2     :: !Float
    -- ^ Polynomial clock correction coefficient (rate of clock drift)
  , _msgEphemerisGal_toc     :: !GpsTimeSec
    -- ^ Clock reference
  , _msgEphemerisGal_iode    :: !Word16
    -- ^ Issue of ephemeris data
  , _msgEphemerisGal_iodc    :: !Word16
    -- ^ Issue of clock data
  , _msgEphemerisGal_source  :: !Word8
    -- ^ 0=I/NAV, 1=F/NAV, ...
  } deriving ( Show, Read, Eq )

instance Binary MsgEphemerisGal where
  get = do
    _msgEphemerisGal_common <- get
    _msgEphemerisGal_bgd_e1e5a <- getFloat32le
    _msgEphemerisGal_bgd_e1e5b <- getFloat32le
    _msgEphemerisGal_c_rs <- getFloat32le
    _msgEphemerisGal_c_rc <- getFloat32le
    _msgEphemerisGal_c_uc <- getFloat32le
    _msgEphemerisGal_c_us <- getFloat32le
    _msgEphemerisGal_c_ic <- getFloat32le
    _msgEphemerisGal_c_is <- getFloat32le
    _msgEphemerisGal_dn <- getFloat64le
    _msgEphemerisGal_m0 <- getFloat64le
    _msgEphemerisGal_ecc <- getFloat64le
    _msgEphemerisGal_sqrta <- getFloat64le
    _msgEphemerisGal_omega0 <- getFloat64le
    _msgEphemerisGal_omegadot <- getFloat64le
    _msgEphemerisGal_w <- getFloat64le
    _msgEphemerisGal_inc <- getFloat64le
    _msgEphemerisGal_inc_dot <- getFloat64le
    _msgEphemerisGal_af0 <- getFloat64le
    _msgEphemerisGal_af1 <- getFloat64le
    _msgEphemerisGal_af2 <- getFloat32le
    _msgEphemerisGal_toc <- get
    _msgEphemerisGal_iode <- getWord16le
    _msgEphemerisGal_iodc <- getWord16le
    _msgEphemerisGal_source <- getWord8
    pure MsgEphemerisGal {..}

  put MsgEphemerisGal {..} = do
    put _msgEphemerisGal_common
    putFloat32le _msgEphemerisGal_bgd_e1e5a
    putFloat32le _msgEphemerisGal_bgd_e1e5b
    putFloat32le _msgEphemerisGal_c_rs
    putFloat32le _msgEphemerisGal_c_rc
    putFloat32le _msgEphemerisGal_c_uc
    putFloat32le _msgEphemerisGal_c_us
    putFloat32le _msgEphemerisGal_c_ic
    putFloat32le _msgEphemerisGal_c_is
    putFloat64le _msgEphemerisGal_dn
    putFloat64le _msgEphemerisGal_m0
    putFloat64le _msgEphemerisGal_ecc
    putFloat64le _msgEphemerisGal_sqrta
    putFloat64le _msgEphemerisGal_omega0
    putFloat64le _msgEphemerisGal_omegadot
    putFloat64le _msgEphemerisGal_w
    putFloat64le _msgEphemerisGal_inc
    putFloat64le _msgEphemerisGal_inc_dot
    putFloat64le _msgEphemerisGal_af0
    putFloat64le _msgEphemerisGal_af1
    putFloat32le _msgEphemerisGal_af2
    put _msgEphemerisGal_toc
    putWord16le _msgEphemerisGal_iode
    putWord16le _msgEphemerisGal_iodc
    putWord8 _msgEphemerisGal_source

$(makeSBP 'msgEphemerisGal ''MsgEphemerisGal)
$(makeJSON "_msgEphemerisGal_" ''MsgEphemerisGal)
$(makeLenses ''MsgEphemerisGal)

msgEphemerisSbasDepA :: Word16
msgEphemerisSbasDepA = 0x0082

data MsgEphemerisSbasDepA = MsgEphemerisSbasDepA
  { _msgEphemerisSbasDepA_common :: !EphemerisCommonContentDepA
    -- ^ Values common for all ephemeris types
  , _msgEphemerisSbasDepA_pos  :: ![Double]
    -- ^ Position of the GEO at time toe
  , _msgEphemerisSbasDepA_vel  :: ![Double]
    -- ^ Velocity of the GEO at time toe
  , _msgEphemerisSbasDepA_acc  :: ![Double]
    -- ^ Acceleration of the GEO at time toe
  , _msgEphemerisSbasDepA_a_gf0 :: !Double
    -- ^ Time offset of the GEO clock w.r.t. SBAS Network Time
  , _msgEphemerisSbasDepA_a_gf1 :: !Double
    -- ^ Drift of the GEO clock w.r.t. SBAS Network Time
  } deriving ( Show, Read, Eq )

instance Binary MsgEphemerisSbasDepA where
  get = do
    _msgEphemerisSbasDepA_common <- get
    _msgEphemerisSbasDepA_pos <- replicateM 3 getFloat64le
    _msgEphemerisSbasDepA_vel <- replicateM 3 getFloat64le
    _msgEphemerisSbasDepA_acc <- replicateM 3 getFloat64le
    _msgEphemerisSbasDepA_a_gf0 <- getFloat64le
    _msgEphemerisSbasDepA_a_gf1 <- getFloat64le
    pure MsgEphemerisSbasDepA {..}

  put MsgEphemerisSbasDepA {..} = do
    put _msgEphemerisSbasDepA_common
    mapM_ putFloat64le _msgEphemerisSbasDepA_pos
    mapM_ putFloat64le _msgEphemerisSbasDepA_vel
    mapM_ putFloat64le _msgEphemerisSbasDepA_acc
    putFloat64le _msgEphemerisSbasDepA_a_gf0
    putFloat64le _msgEphemerisSbasDepA_a_gf1

$(makeSBP 'msgEphemerisSbasDepA ''MsgEphemerisSbasDepA)
$(makeJSON "_msgEphemerisSbasDepA_" ''MsgEphemerisSbasDepA)
$(makeLenses ''MsgEphemerisSbasDepA)

msgEphemerisGloDepA :: Word16
msgEphemerisGloDepA = 0x0083

-- | SBP class for message MSG_EPHEMERIS_GLO_DEP_A (0x0083).
--
-- The ephemeris message returns a set of satellite orbit parameters that is
-- used to calculate GLO satellite position, velocity, and clock offset. Please
-- see the GLO ICD 5.1 "Table 4.5 Characteristics of words of immediate
-- information (ephemeris parameters)" for more details.
data MsgEphemerisGloDepA = MsgEphemerisGloDepA
  { _msgEphemerisGloDepA_common :: !EphemerisCommonContentDepA
    -- ^ Values common for all ephemeris types
  , _msgEphemerisGloDepA_gamma :: !Double
    -- ^ Relative deviation of predicted carrier frequency from nominal
  , _msgEphemerisGloDepA_tau  :: !Double
    -- ^ Correction to the SV time
  , _msgEphemerisGloDepA_pos  :: ![Double]
    -- ^ Position of the SV at tb in PZ-90.02 coordinates system
  , _msgEphemerisGloDepA_vel  :: ![Double]
    -- ^ Velocity vector of the SV at tb in PZ-90.02 coordinates system
  , _msgEphemerisGloDepA_acc  :: ![Double]
    -- ^ Acceleration vector of the SV at tb in PZ-90.02 coordinates sys
  } deriving ( Show, Read, Eq )

instance Binary MsgEphemerisGloDepA where
  get = do
    _msgEphemerisGloDepA_common <- get
    _msgEphemerisGloDepA_gamma <- getFloat64le
    _msgEphemerisGloDepA_tau <- getFloat64le
    _msgEphemerisGloDepA_pos <- replicateM 3 getFloat64le
    _msgEphemerisGloDepA_vel <- replicateM 3 getFloat64le
    _msgEphemerisGloDepA_acc <- replicateM 3 getFloat64le
    pure MsgEphemerisGloDepA {..}

  put MsgEphemerisGloDepA {..} = do
    put _msgEphemerisGloDepA_common
    putFloat64le _msgEphemerisGloDepA_gamma
    putFloat64le _msgEphemerisGloDepA_tau
    mapM_ putFloat64le _msgEphemerisGloDepA_pos
    mapM_ putFloat64le _msgEphemerisGloDepA_vel
    mapM_ putFloat64le _msgEphemerisGloDepA_acc

$(makeSBP 'msgEphemerisGloDepA ''MsgEphemerisGloDepA)
$(makeJSON "_msgEphemerisGloDepA_" ''MsgEphemerisGloDepA)
$(makeLenses ''MsgEphemerisGloDepA)

msgEphemerisSbasDepB :: Word16
msgEphemerisSbasDepB = 0x0084

-- | SBP class for message MSG_EPHEMERIS_SBAS_DEP_B (0x0084).
--
-- This observation message has been deprecated in favor of ephemeris message
-- using floats for size reduction.
data MsgEphemerisSbasDepB = MsgEphemerisSbasDepB
  { _msgEphemerisSbasDepB_common :: !EphemerisCommonContentDepB
    -- ^ Values common for all ephemeris types
  , _msgEphemerisSbasDepB_pos  :: ![Double]
    -- ^ Position of the GEO at time toe
  , _msgEphemerisSbasDepB_vel  :: ![Double]
    -- ^ Velocity of the GEO at time toe
  , _msgEphemerisSbasDepB_acc  :: ![Double]
    -- ^ Acceleration of the GEO at time toe
  , _msgEphemerisSbasDepB_a_gf0 :: !Double
    -- ^ Time offset of the GEO clock w.r.t. SBAS Network Time
  , _msgEphemerisSbasDepB_a_gf1 :: !Double
    -- ^ Drift of the GEO clock w.r.t. SBAS Network Time
  } deriving ( Show, Read, Eq )

instance Binary MsgEphemerisSbasDepB where
  get = do
    _msgEphemerisSbasDepB_common <- get
    _msgEphemerisSbasDepB_pos <- replicateM 3 getFloat64le
    _msgEphemerisSbasDepB_vel <- replicateM 3 getFloat64le
    _msgEphemerisSbasDepB_acc <- replicateM 3 getFloat64le
    _msgEphemerisSbasDepB_a_gf0 <- getFloat64le
    _msgEphemerisSbasDepB_a_gf1 <- getFloat64le
    pure MsgEphemerisSbasDepB {..}

  put MsgEphemerisSbasDepB {..} = do
    put _msgEphemerisSbasDepB_common
    mapM_ putFloat64le _msgEphemerisSbasDepB_pos
    mapM_ putFloat64le _msgEphemerisSbasDepB_vel
    mapM_ putFloat64le _msgEphemerisSbasDepB_acc
    putFloat64le _msgEphemerisSbasDepB_a_gf0
    putFloat64le _msgEphemerisSbasDepB_a_gf1

$(makeSBP 'msgEphemerisSbasDepB ''MsgEphemerisSbasDepB)
$(makeJSON "_msgEphemerisSbasDepB_" ''MsgEphemerisSbasDepB)
$(makeLenses ''MsgEphemerisSbasDepB)

msgEphemerisSbas :: Word16
msgEphemerisSbas = 0x008C

data MsgEphemerisSbas = MsgEphemerisSbas
  { _msgEphemerisSbas_common :: !EphemerisCommonContent
    -- ^ Values common for all ephemeris types
  , _msgEphemerisSbas_pos  :: ![Double]
    -- ^ Position of the GEO at time toe
  , _msgEphemerisSbas_vel  :: ![Float]
    -- ^ Velocity of the GEO at time toe
  , _msgEphemerisSbas_acc  :: ![Float]
    -- ^ Acceleration of the GEO at time toe
  , _msgEphemerisSbas_a_gf0 :: !Float
    -- ^ Time offset of the GEO clock w.r.t. SBAS Network Time
  , _msgEphemerisSbas_a_gf1 :: !Float
    -- ^ Drift of the GEO clock w.r.t. SBAS Network Time
  } deriving ( Show, Read, Eq )

instance Binary MsgEphemerisSbas where
  get = do
    _msgEphemerisSbas_common <- get
    _msgEphemerisSbas_pos <- replicateM 3 getFloat64le
    _msgEphemerisSbas_vel <- replicateM 3 getFloat32le
    _msgEphemerisSbas_acc <- replicateM 3 getFloat32le
    _msgEphemerisSbas_a_gf0 <- getFloat32le
    _msgEphemerisSbas_a_gf1 <- getFloat32le
    pure MsgEphemerisSbas {..}

  put MsgEphemerisSbas {..} = do
    put _msgEphemerisSbas_common
    mapM_ putFloat64le _msgEphemerisSbas_pos
    mapM_ putFloat32le _msgEphemerisSbas_vel
    mapM_ putFloat32le _msgEphemerisSbas_acc
    putFloat32le _msgEphemerisSbas_a_gf0
    putFloat32le _msgEphemerisSbas_a_gf1

$(makeSBP 'msgEphemerisSbas ''MsgEphemerisSbas)
$(makeJSON "_msgEphemerisSbas_" ''MsgEphemerisSbas)
$(makeLenses ''MsgEphemerisSbas)

msgEphemerisGloDepB :: Word16
msgEphemerisGloDepB = 0x0085

-- | SBP class for message MSG_EPHEMERIS_GLO_DEP_B (0x0085).
--
-- The ephemeris message returns a set of satellite orbit parameters that is
-- used to calculate GLO satellite position, velocity, and clock offset. Please
-- see the GLO ICD 5.1 "Table 4.5 Characteristics of words of immediate
-- information (ephemeris parameters)" for more details.
data MsgEphemerisGloDepB = MsgEphemerisGloDepB
  { _msgEphemerisGloDepB_common :: !EphemerisCommonContentDepB
    -- ^ Values common for all ephemeris types
  , _msgEphemerisGloDepB_gamma :: !Double
    -- ^ Relative deviation of predicted carrier frequency from nominal
  , _msgEphemerisGloDepB_tau  :: !Double
    -- ^ Correction to the SV time
  , _msgEphemerisGloDepB_pos  :: ![Double]
    -- ^ Position of the SV at tb in PZ-90.02 coordinates system
  , _msgEphemerisGloDepB_vel  :: ![Double]
    -- ^ Velocity vector of the SV at tb in PZ-90.02 coordinates system
  , _msgEphemerisGloDepB_acc  :: ![Double]
    -- ^ Acceleration vector of the SV at tb in PZ-90.02 coordinates sys
  } deriving ( Show, Read, Eq )

instance Binary MsgEphemerisGloDepB where
  get = do
    _msgEphemerisGloDepB_common <- get
    _msgEphemerisGloDepB_gamma <- getFloat64le
    _msgEphemerisGloDepB_tau <- getFloat64le
    _msgEphemerisGloDepB_pos <- replicateM 3 getFloat64le
    _msgEphemerisGloDepB_vel <- replicateM 3 getFloat64le
    _msgEphemerisGloDepB_acc <- replicateM 3 getFloat64le
    pure MsgEphemerisGloDepB {..}

  put MsgEphemerisGloDepB {..} = do
    put _msgEphemerisGloDepB_common
    putFloat64le _msgEphemerisGloDepB_gamma
    putFloat64le _msgEphemerisGloDepB_tau
    mapM_ putFloat64le _msgEphemerisGloDepB_pos
    mapM_ putFloat64le _msgEphemerisGloDepB_vel
    mapM_ putFloat64le _msgEphemerisGloDepB_acc

$(makeSBP 'msgEphemerisGloDepB ''MsgEphemerisGloDepB)
$(makeJSON "_msgEphemerisGloDepB_" ''MsgEphemerisGloDepB)
$(makeLenses ''MsgEphemerisGloDepB)

msgEphemerisGloDepC :: Word16
msgEphemerisGloDepC = 0x0087

-- | SBP class for message MSG_EPHEMERIS_GLO_DEP_C (0x0087).
--
-- The ephemeris message returns a set of satellite orbit parameters that is
-- used to calculate GLO satellite position, velocity, and clock offset. Please
-- see the GLO ICD 5.1 "Table 4.5 Characteristics of words of immediate
-- information (ephemeris parameters)" for more details.
data MsgEphemerisGloDepC = MsgEphemerisGloDepC
  { _msgEphemerisGloDepC_common :: !EphemerisCommonContentDepB
    -- ^ Values common for all ephemeris types
  , _msgEphemerisGloDepC_gamma :: !Double
    -- ^ Relative deviation of predicted carrier frequency from nominal
  , _msgEphemerisGloDepC_tau  :: !Double
    -- ^ Correction to the SV time
  , _msgEphemerisGloDepC_d_tau :: !Double
    -- ^ Equipment delay between L1 and L2
  , _msgEphemerisGloDepC_pos  :: ![Double]
    -- ^ Position of the SV at tb in PZ-90.02 coordinates system
  , _msgEphemerisGloDepC_vel  :: ![Double]
    -- ^ Velocity vector of the SV at tb in PZ-90.02 coordinates system
  , _msgEphemerisGloDepC_acc  :: ![Double]
    -- ^ Acceleration vector of the SV at tb in PZ-90.02 coordinates sys
  , _msgEphemerisGloDepC_fcn  :: !Word8
    -- ^ Frequency slot. FCN+8 (that is [1..14]). 0 or 0xFF for invalid
  } deriving ( Show, Read, Eq )

instance Binary MsgEphemerisGloDepC where
  get = do
    _msgEphemerisGloDepC_common <- get
    _msgEphemerisGloDepC_gamma <- getFloat64le
    _msgEphemerisGloDepC_tau <- getFloat64le
    _msgEphemerisGloDepC_d_tau <- getFloat64le
    _msgEphemerisGloDepC_pos <- replicateM 3 getFloat64le
    _msgEphemerisGloDepC_vel <- replicateM 3 getFloat64le
    _msgEphemerisGloDepC_acc <- replicateM 3 getFloat64le
    _msgEphemerisGloDepC_fcn <- getWord8
    pure MsgEphemerisGloDepC {..}

  put MsgEphemerisGloDepC {..} = do
    put _msgEphemerisGloDepC_common
    putFloat64le _msgEphemerisGloDepC_gamma
    putFloat64le _msgEphemerisGloDepC_tau
    putFloat64le _msgEphemerisGloDepC_d_tau
    mapM_ putFloat64le _msgEphemerisGloDepC_pos
    mapM_ putFloat64le _msgEphemerisGloDepC_vel
    mapM_ putFloat64le _msgEphemerisGloDepC_acc
    putWord8 _msgEphemerisGloDepC_fcn

$(makeSBP 'msgEphemerisGloDepC ''MsgEphemerisGloDepC)
$(makeJSON "_msgEphemerisGloDepC_" ''MsgEphemerisGloDepC)
$(makeLenses ''MsgEphemerisGloDepC)

msgEphemerisGloDepD :: Word16
msgEphemerisGloDepD = 0x0088

-- | SBP class for message MSG_EPHEMERIS_GLO_DEP_D (0x0088).
--
-- This observation message has been deprecated in favor of ephemeris message
-- using floats for size reduction.
data MsgEphemerisGloDepD = MsgEphemerisGloDepD
  { _msgEphemerisGloDepD_common :: !EphemerisCommonContentDepB
    -- ^ Values common for all ephemeris types
  , _msgEphemerisGloDepD_gamma :: !Double
    -- ^ Relative deviation of predicted carrier frequency from nominal
  , _msgEphemerisGloDepD_tau  :: !Double
    -- ^ Correction to the SV time
  , _msgEphemerisGloDepD_d_tau :: !Double
    -- ^ Equipment delay between L1 and L2
  , _msgEphemerisGloDepD_pos  :: ![Double]
    -- ^ Position of the SV at tb in PZ-90.02 coordinates system
  , _msgEphemerisGloDepD_vel  :: ![Double]
    -- ^ Velocity vector of the SV at tb in PZ-90.02 coordinates system
  , _msgEphemerisGloDepD_acc  :: ![Double]
    -- ^ Acceleration vector of the SV at tb in PZ-90.02 coordinates sys
  , _msgEphemerisGloDepD_fcn  :: !Word8
    -- ^ Frequency slot. FCN+8 (that is [1..14]). 0 or 0xFF for invalid
  , _msgEphemerisGloDepD_iod  :: !Word8
    -- ^ Issue of ephemeris data
  } deriving ( Show, Read, Eq )

instance Binary MsgEphemerisGloDepD where
  get = do
    _msgEphemerisGloDepD_common <- get
    _msgEphemerisGloDepD_gamma <- getFloat64le
    _msgEphemerisGloDepD_tau <- getFloat64le
    _msgEphemerisGloDepD_d_tau <- getFloat64le
    _msgEphemerisGloDepD_pos <- replicateM 3 getFloat64le
    _msgEphemerisGloDepD_vel <- replicateM 3 getFloat64le
    _msgEphemerisGloDepD_acc <- replicateM 3 getFloat64le
    _msgEphemerisGloDepD_fcn <- getWord8
    _msgEphemerisGloDepD_iod <- getWord8
    pure MsgEphemerisGloDepD {..}

  put MsgEphemerisGloDepD {..} = do
    put _msgEphemerisGloDepD_common
    putFloat64le _msgEphemerisGloDepD_gamma
    putFloat64le _msgEphemerisGloDepD_tau
    putFloat64le _msgEphemerisGloDepD_d_tau
    mapM_ putFloat64le _msgEphemerisGloDepD_pos
    mapM_ putFloat64le _msgEphemerisGloDepD_vel
    mapM_ putFloat64le _msgEphemerisGloDepD_acc
    putWord8 _msgEphemerisGloDepD_fcn
    putWord8 _msgEphemerisGloDepD_iod

$(makeSBP 'msgEphemerisGloDepD ''MsgEphemerisGloDepD)
$(makeJSON "_msgEphemerisGloDepD_" ''MsgEphemerisGloDepD)
$(makeLenses ''MsgEphemerisGloDepD)

msgEphemerisGlo :: Word16
msgEphemerisGlo = 0x008B

-- | SBP class for message MSG_EPHEMERIS_GLO (0x008B).
--
-- The ephemeris message returns a set of satellite orbit parameters that is
-- used to calculate GLO satellite position, velocity, and clock offset. Please
-- see the GLO ICD 5.1 "Table 4.5 Characteristics of words of immediate
-- information (ephemeris parameters)" for more details.
data MsgEphemerisGlo = MsgEphemerisGlo
  { _msgEphemerisGlo_common :: !EphemerisCommonContent
    -- ^ Values common for all ephemeris types
  , _msgEphemerisGlo_gamma :: !Float
    -- ^ Relative deviation of predicted carrier frequency from nominal
  , _msgEphemerisGlo_tau  :: !Float
    -- ^ Correction to the SV time
  , _msgEphemerisGlo_d_tau :: !Float
    -- ^ Equipment delay between L1 and L2
  , _msgEphemerisGlo_pos  :: ![Double]
    -- ^ Position of the SV at tb in PZ-90.02 coordinates system
  , _msgEphemerisGlo_vel  :: ![Double]
    -- ^ Velocity vector of the SV at tb in PZ-90.02 coordinates system
  , _msgEphemerisGlo_acc  :: ![Float]
    -- ^ Acceleration vector of the SV at tb in PZ-90.02 coordinates sys
  , _msgEphemerisGlo_fcn  :: !Word8
    -- ^ Frequency slot. FCN+8 (that is [1..14]). 0 or 0xFF for invalid
  , _msgEphemerisGlo_iod  :: !Word8
    -- ^ Issue of ephemeris data
  } deriving ( Show, Read, Eq )

instance Binary MsgEphemerisGlo where
  get = do
    _msgEphemerisGlo_common <- get
    _msgEphemerisGlo_gamma <- getFloat32le
    _msgEphemerisGlo_tau <- getFloat32le
    _msgEphemerisGlo_d_tau <- getFloat32le
    _msgEphemerisGlo_pos <- replicateM 3 getFloat64le
    _msgEphemerisGlo_vel <- replicateM 3 getFloat64le
    _msgEphemerisGlo_acc <- replicateM 3 getFloat32le
    _msgEphemerisGlo_fcn <- getWord8
    _msgEphemerisGlo_iod <- getWord8
    pure MsgEphemerisGlo {..}

  put MsgEphemerisGlo {..} = do
    put _msgEphemerisGlo_common
    putFloat32le _msgEphemerisGlo_gamma
    putFloat32le _msgEphemerisGlo_tau
    putFloat32le _msgEphemerisGlo_d_tau
    mapM_ putFloat64le _msgEphemerisGlo_pos
    mapM_ putFloat64le _msgEphemerisGlo_vel
    mapM_ putFloat32le _msgEphemerisGlo_acc
    putWord8 _msgEphemerisGlo_fcn
    putWord8 _msgEphemerisGlo_iod

$(makeSBP 'msgEphemerisGlo ''MsgEphemerisGlo)
$(makeJSON "_msgEphemerisGlo_" ''MsgEphemerisGlo)
$(makeLenses ''MsgEphemerisGlo)

msgEphemerisDepD :: Word16
msgEphemerisDepD = 0x0080

-- | SBP class for message MSG_EPHEMERIS_DEP_D (0x0080).
--
-- The ephemeris message returns a set of satellite orbit parameters that is
-- used to calculate GPS satellite position, velocity, and clock offset. Please
-- see the Navstar GPS Space Segment/Navigation user interfaces (ICD-GPS-200,
-- Table 20-III) for more details.
data MsgEphemerisDepD = MsgEphemerisDepD
  { _msgEphemerisDepD_tgd    :: !Double
    -- ^ Group delay differential between L1 and L2
  , _msgEphemerisDepD_c_rs   :: !Double
    -- ^ Amplitude of the sine harmonic correction term to the orbit radius
  , _msgEphemerisDepD_c_rc   :: !Double
    -- ^ Amplitude of the cosine harmonic correction term to the orbit radius
  , _msgEphemerisDepD_c_uc   :: !Double
    -- ^ Amplitude of the cosine harmonic correction term to the argument of
    -- latitude
  , _msgEphemerisDepD_c_us   :: !Double
    -- ^ Amplitude of the sine harmonic correction term to the argument of
    -- latitude
  , _msgEphemerisDepD_c_ic   :: !Double
    -- ^ Amplitude of the cosine harmonic correction term to the angle of
    -- inclination
  , _msgEphemerisDepD_c_is   :: !Double
    -- ^ Amplitude of the sine harmonic correction term to the angle of
    -- inclination
  , _msgEphemerisDepD_dn     :: !Double
    -- ^ Mean motion difference
  , _msgEphemerisDepD_m0     :: !Double
    -- ^ Mean anomaly at reference time
  , _msgEphemerisDepD_ecc    :: !Double
    -- ^ Eccentricity of satellite orbit
  , _msgEphemerisDepD_sqrta  :: !Double
    -- ^ Square root of the semi-major axis of orbit
  , _msgEphemerisDepD_omega0 :: !Double
    -- ^ Longitude of ascending node of orbit plane at weekly epoch
  , _msgEphemerisDepD_omegadot :: !Double
    -- ^ Rate of right ascension
  , _msgEphemerisDepD_w      :: !Double
    -- ^ Argument of perigee
  , _msgEphemerisDepD_inc    :: !Double
    -- ^ Inclination
  , _msgEphemerisDepD_inc_dot :: !Double
    -- ^ Inclination first derivative
  , _msgEphemerisDepD_af0    :: !Double
    -- ^ Polynomial clock correction coefficient (clock bias)
  , _msgEphemerisDepD_af1    :: !Double
    -- ^ Polynomial clock correction coefficient (clock drift)
  , _msgEphemerisDepD_af2    :: !Double
    -- ^ Polynomial clock correction coefficient (rate of clock drift)
  , _msgEphemerisDepD_toe_tow :: !Double
    -- ^ Time of week
  , _msgEphemerisDepD_toe_wn :: !Word16
    -- ^ Week number
  , _msgEphemerisDepD_toc_tow :: !Double
    -- ^ Clock reference time of week
  , _msgEphemerisDepD_toc_wn :: !Word16
    -- ^ Clock reference week number
  , _msgEphemerisDepD_valid  :: !Word8
    -- ^ Is valid?
  , _msgEphemerisDepD_healthy :: !Word8
    -- ^ Satellite is healthy?
  , _msgEphemerisDepD_sid    :: !GnssSignalDep
    -- ^ GNSS signal identifier
  , _msgEphemerisDepD_iode   :: !Word8
    -- ^ Issue of ephemeris data
  , _msgEphemerisDepD_iodc   :: !Word16
    -- ^ Issue of clock data
  , _msgEphemerisDepD_reserved :: !Word32
    -- ^ Reserved field
  } deriving ( Show, Read, Eq )

instance Binary MsgEphemerisDepD where
  get = do
    _msgEphemerisDepD_tgd <- getFloat64le
    _msgEphemerisDepD_c_rs <- getFloat64le
    _msgEphemerisDepD_c_rc <- getFloat64le
    _msgEphemerisDepD_c_uc <- getFloat64le
    _msgEphemerisDepD_c_us <- getFloat64le
    _msgEphemerisDepD_c_ic <- getFloat64le
    _msgEphemerisDepD_c_is <- getFloat64le
    _msgEphemerisDepD_dn <- getFloat64le
    _msgEphemerisDepD_m0 <- getFloat64le
    _msgEphemerisDepD_ecc <- getFloat64le
    _msgEphemerisDepD_sqrta <- getFloat64le
    _msgEphemerisDepD_omega0 <- getFloat64le
    _msgEphemerisDepD_omegadot <- getFloat64le
    _msgEphemerisDepD_w <- getFloat64le
    _msgEphemerisDepD_inc <- getFloat64le
    _msgEphemerisDepD_inc_dot <- getFloat64le
    _msgEphemerisDepD_af0 <- getFloat64le
    _msgEphemerisDepD_af1 <- getFloat64le
    _msgEphemerisDepD_af2 <- getFloat64le
    _msgEphemerisDepD_toe_tow <- getFloat64le
    _msgEphemerisDepD_toe_wn <- getWord16le
    _msgEphemerisDepD_toc_tow <- getFloat64le
    _msgEphemerisDepD_toc_wn <- getWord16le
    _msgEphemerisDepD_valid <- getWord8
    _msgEphemerisDepD_healthy <- getWord8
    _msgEphemerisDepD_sid <- get
    _msgEphemerisDepD_iode <- getWord8
    _msgEphemerisDepD_iodc <- getWord16le
    _msgEphemerisDepD_reserved <- getWord32le
    pure MsgEphemerisDepD {..}

  put MsgEphemerisDepD {..} = do
    putFloat64le _msgEphemerisDepD_tgd
    putFloat64le _msgEphemerisDepD_c_rs
    putFloat64le _msgEphemerisDepD_c_rc
    putFloat64le _msgEphemerisDepD_c_uc
    putFloat64le _msgEphemerisDepD_c_us
    putFloat64le _msgEphemerisDepD_c_ic
    putFloat64le _msgEphemerisDepD_c_is
    putFloat64le _msgEphemerisDepD_dn
    putFloat64le _msgEphemerisDepD_m0
    putFloat64le _msgEphemerisDepD_ecc
    putFloat64le _msgEphemerisDepD_sqrta
    putFloat64le _msgEphemerisDepD_omega0
    putFloat64le _msgEphemerisDepD_omegadot
    putFloat64le _msgEphemerisDepD_w
    putFloat64le _msgEphemerisDepD_inc
    putFloat64le _msgEphemerisDepD_inc_dot
    putFloat64le _msgEphemerisDepD_af0
    putFloat64le _msgEphemerisDepD_af1
    putFloat64le _msgEphemerisDepD_af2
    putFloat64le _msgEphemerisDepD_toe_tow
    putWord16le _msgEphemerisDepD_toe_wn
    putFloat64le _msgEphemerisDepD_toc_tow
    putWord16le _msgEphemerisDepD_toc_wn
    putWord8 _msgEphemerisDepD_valid
    putWord8 _msgEphemerisDepD_healthy
    put _msgEphemerisDepD_sid
    putWord8 _msgEphemerisDepD_iode
    putWord16le _msgEphemerisDepD_iodc
    putWord32le _msgEphemerisDepD_reserved

$(makeSBP 'msgEphemerisDepD ''MsgEphemerisDepD)
$(makeJSON "_msgEphemerisDepD_" ''MsgEphemerisDepD)
$(makeLenses ''MsgEphemerisDepD)

msgEphemerisDepA :: Word16
msgEphemerisDepA = 0x001A

-- | SBP class for message MSG_EPHEMERIS_DEP_A (0x001A).
--
-- Deprecated.
data MsgEphemerisDepA = MsgEphemerisDepA
  { _msgEphemerisDepA_tgd    :: !Double
    -- ^ Group delay differential between L1 and L2
  , _msgEphemerisDepA_c_rs   :: !Double
    -- ^ Amplitude of the sine harmonic correction term to the orbit radius
  , _msgEphemerisDepA_c_rc   :: !Double
    -- ^ Amplitude of the cosine harmonic correction term to the orbit radius
  , _msgEphemerisDepA_c_uc   :: !Double
    -- ^ Amplitude of the cosine harmonic correction term to the argument of
    -- latitude
  , _msgEphemerisDepA_c_us   :: !Double
    -- ^ Amplitude of the sine harmonic correction term to the argument of
    -- latitude
  , _msgEphemerisDepA_c_ic   :: !Double
    -- ^ Amplitude of the cosine harmonic correction term to the angle of
    -- inclination
  , _msgEphemerisDepA_c_is   :: !Double
    -- ^ Amplitude of the sine harmonic correction term to the angle of
    -- inclination
  , _msgEphemerisDepA_dn     :: !Double
    -- ^ Mean motion difference
  , _msgEphemerisDepA_m0     :: !Double
    -- ^ Mean anomaly at reference time
  , _msgEphemerisDepA_ecc    :: !Double
    -- ^ Eccentricity of satellite orbit
  , _msgEphemerisDepA_sqrta  :: !Double
    -- ^ Square root of the semi-major axis of orbit
  , _msgEphemerisDepA_omega0 :: !Double
    -- ^ Longitude of ascending node of orbit plane at weekly epoch
  , _msgEphemerisDepA_omegadot :: !Double
    -- ^ Rate of right ascension
  , _msgEphemerisDepA_w      :: !Double
    -- ^ Argument of perigee
  , _msgEphemerisDepA_inc    :: !Double
    -- ^ Inclination
  , _msgEphemerisDepA_inc_dot :: !Double
    -- ^ Inclination first derivative
  , _msgEphemerisDepA_af0    :: !Double
    -- ^ Polynomial clock correction coefficient (clock bias)
  , _msgEphemerisDepA_af1    :: !Double
    -- ^ Polynomial clock correction coefficient (clock drift)
  , _msgEphemerisDepA_af2    :: !Double
    -- ^ Polynomial clock correction coefficient (rate of clock drift)
  , _msgEphemerisDepA_toe_tow :: !Double
    -- ^ Time of week
  , _msgEphemerisDepA_toe_wn :: !Word16
    -- ^ Week number
  , _msgEphemerisDepA_toc_tow :: !Double
    -- ^ Clock reference time of week
  , _msgEphemerisDepA_toc_wn :: !Word16
    -- ^ Clock reference week number
  , _msgEphemerisDepA_valid  :: !Word8
    -- ^ Is valid?
  , _msgEphemerisDepA_healthy :: !Word8
    -- ^ Satellite is healthy?
  , _msgEphemerisDepA_prn    :: !Word8
    -- ^ PRN being tracked
  } deriving ( Show, Read, Eq )

instance Binary MsgEphemerisDepA where
  get = do
    _msgEphemerisDepA_tgd <- getFloat64le
    _msgEphemerisDepA_c_rs <- getFloat64le
    _msgEphemerisDepA_c_rc <- getFloat64le
    _msgEphemerisDepA_c_uc <- getFloat64le
    _msgEphemerisDepA_c_us <- getFloat64le
    _msgEphemerisDepA_c_ic <- getFloat64le
    _msgEphemerisDepA_c_is <- getFloat64le
    _msgEphemerisDepA_dn <- getFloat64le
    _msgEphemerisDepA_m0 <- getFloat64le
    _msgEphemerisDepA_ecc <- getFloat64le
    _msgEphemerisDepA_sqrta <- getFloat64le
    _msgEphemerisDepA_omega0 <- getFloat64le
    _msgEphemerisDepA_omegadot <- getFloat64le
    _msgEphemerisDepA_w <- getFloat64le
    _msgEphemerisDepA_inc <- getFloat64le
    _msgEphemerisDepA_inc_dot <- getFloat64le
    _msgEphemerisDepA_af0 <- getFloat64le
    _msgEphemerisDepA_af1 <- getFloat64le
    _msgEphemerisDepA_af2 <- getFloat64le
    _msgEphemerisDepA_toe_tow <- getFloat64le
    _msgEphemerisDepA_toe_wn <- getWord16le
    _msgEphemerisDepA_toc_tow <- getFloat64le
    _msgEphemerisDepA_toc_wn <- getWord16le
    _msgEphemerisDepA_valid <- getWord8
    _msgEphemerisDepA_healthy <- getWord8
    _msgEphemerisDepA_prn <- getWord8
    pure MsgEphemerisDepA {..}

  put MsgEphemerisDepA {..} = do
    putFloat64le _msgEphemerisDepA_tgd
    putFloat64le _msgEphemerisDepA_c_rs
    putFloat64le _msgEphemerisDepA_c_rc
    putFloat64le _msgEphemerisDepA_c_uc
    putFloat64le _msgEphemerisDepA_c_us
    putFloat64le _msgEphemerisDepA_c_ic
    putFloat64le _msgEphemerisDepA_c_is
    putFloat64le _msgEphemerisDepA_dn
    putFloat64le _msgEphemerisDepA_m0
    putFloat64le _msgEphemerisDepA_ecc
    putFloat64le _msgEphemerisDepA_sqrta
    putFloat64le _msgEphemerisDepA_omega0
    putFloat64le _msgEphemerisDepA_omegadot
    putFloat64le _msgEphemerisDepA_w
    putFloat64le _msgEphemerisDepA_inc
    putFloat64le _msgEphemerisDepA_inc_dot
    putFloat64le _msgEphemerisDepA_af0
    putFloat64le _msgEphemerisDepA_af1
    putFloat64le _msgEphemerisDepA_af2
    putFloat64le _msgEphemerisDepA_toe_tow
    putWord16le _msgEphemerisDepA_toe_wn
    putFloat64le _msgEphemerisDepA_toc_tow
    putWord16le _msgEphemerisDepA_toc_wn
    putWord8 _msgEphemerisDepA_valid
    putWord8 _msgEphemerisDepA_healthy
    putWord8 _msgEphemerisDepA_prn

$(makeSBP 'msgEphemerisDepA ''MsgEphemerisDepA)
$(makeJSON "_msgEphemerisDepA_" ''MsgEphemerisDepA)
$(makeLenses ''MsgEphemerisDepA)

msgEphemerisDepB :: Word16
msgEphemerisDepB = 0x0046

-- | SBP class for message MSG_EPHEMERIS_DEP_B (0x0046).
--
-- Deprecated.
data MsgEphemerisDepB = MsgEphemerisDepB
  { _msgEphemerisDepB_tgd    :: !Double
    -- ^ Group delay differential between L1 and L2
  , _msgEphemerisDepB_c_rs   :: !Double
    -- ^ Amplitude of the sine harmonic correction term to the orbit radius
  , _msgEphemerisDepB_c_rc   :: !Double
    -- ^ Amplitude of the cosine harmonic correction term to the orbit radius
  , _msgEphemerisDepB_c_uc   :: !Double
    -- ^ Amplitude of the cosine harmonic correction term to the argument of
    -- latitude
  , _msgEphemerisDepB_c_us   :: !Double
    -- ^ Amplitude of the sine harmonic correction term to the argument of
    -- latitude
  , _msgEphemerisDepB_c_ic   :: !Double
    -- ^ Amplitude of the cosine harmonic correction term to the angle of
    -- inclination
  , _msgEphemerisDepB_c_is   :: !Double
    -- ^ Amplitude of the sine harmonic correction term to the angle of
    -- inclination
  , _msgEphemerisDepB_dn     :: !Double
    -- ^ Mean motion difference
  , _msgEphemerisDepB_m0     :: !Double
    -- ^ Mean anomaly at reference time
  , _msgEphemerisDepB_ecc    :: !Double
    -- ^ Eccentricity of satellite orbit
  , _msgEphemerisDepB_sqrta  :: !Double
    -- ^ Square root of the semi-major axis of orbit
  , _msgEphemerisDepB_omega0 :: !Double
    -- ^ Longitude of ascending node of orbit plane at weekly epoch
  , _msgEphemerisDepB_omegadot :: !Double
    -- ^ Rate of right ascension
  , _msgEphemerisDepB_w      :: !Double
    -- ^ Argument of perigee
  , _msgEphemerisDepB_inc    :: !Double
    -- ^ Inclination
  , _msgEphemerisDepB_inc_dot :: !Double
    -- ^ Inclination first derivative
  , _msgEphemerisDepB_af0    :: !Double
    -- ^ Polynomial clock correction coefficient (clock bias)
  , _msgEphemerisDepB_af1    :: !Double
    -- ^ Polynomial clock correction coefficient (clock drift)
  , _msgEphemerisDepB_af2    :: !Double
    -- ^ Polynomial clock correction coefficient (rate of clock drift)
  , _msgEphemerisDepB_toe_tow :: !Double
    -- ^ Time of week
  , _msgEphemerisDepB_toe_wn :: !Word16
    -- ^ Week number
  , _msgEphemerisDepB_toc_tow :: !Double
    -- ^ Clock reference time of week
  , _msgEphemerisDepB_toc_wn :: !Word16
    -- ^ Clock reference week number
  , _msgEphemerisDepB_valid  :: !Word8
    -- ^ Is valid?
  , _msgEphemerisDepB_healthy :: !Word8
    -- ^ Satellite is healthy?
  , _msgEphemerisDepB_prn    :: !Word8
    -- ^ PRN being tracked
  , _msgEphemerisDepB_iode   :: !Word8
    -- ^ Issue of ephemeris data
  } deriving ( Show, Read, Eq )

instance Binary MsgEphemerisDepB where
  get = do
    _msgEphemerisDepB_tgd <- getFloat64le
    _msgEphemerisDepB_c_rs <- getFloat64le
    _msgEphemerisDepB_c_rc <- getFloat64le
    _msgEphemerisDepB_c_uc <- getFloat64le
    _msgEphemerisDepB_c_us <- getFloat64le
    _msgEphemerisDepB_c_ic <- getFloat64le
    _msgEphemerisDepB_c_is <- getFloat64le
    _msgEphemerisDepB_dn <- getFloat64le
    _msgEphemerisDepB_m0 <- getFloat64le
    _msgEphemerisDepB_ecc <- getFloat64le
    _msgEphemerisDepB_sqrta <- getFloat64le
    _msgEphemerisDepB_omega0 <- getFloat64le
    _msgEphemerisDepB_omegadot <- getFloat64le
    _msgEphemerisDepB_w <- getFloat64le
    _msgEphemerisDepB_inc <- getFloat64le
    _msgEphemerisDepB_inc_dot <- getFloat64le
    _msgEphemerisDepB_af0 <- getFloat64le
    _msgEphemerisDepB_af1 <- getFloat64le
    _msgEphemerisDepB_af2 <- getFloat64le
    _msgEphemerisDepB_toe_tow <- getFloat64le
    _msgEphemerisDepB_toe_wn <- getWord16le
    _msgEphemerisDepB_toc_tow <- getFloat64le
    _msgEphemerisDepB_toc_wn <- getWord16le
    _msgEphemerisDepB_valid <- getWord8
    _msgEphemerisDepB_healthy <- getWord8
    _msgEphemerisDepB_prn <- getWord8
    _msgEphemerisDepB_iode <- getWord8
    pure MsgEphemerisDepB {..}

  put MsgEphemerisDepB {..} = do
    putFloat64le _msgEphemerisDepB_tgd
    putFloat64le _msgEphemerisDepB_c_rs
    putFloat64le _msgEphemerisDepB_c_rc
    putFloat64le _msgEphemerisDepB_c_uc
    putFloat64le _msgEphemerisDepB_c_us
    putFloat64le _msgEphemerisDepB_c_ic
    putFloat64le _msgEphemerisDepB_c_is
    putFloat64le _msgEphemerisDepB_dn
    putFloat64le _msgEphemerisDepB_m0
    putFloat64le _msgEphemerisDepB_ecc
    putFloat64le _msgEphemerisDepB_sqrta
    putFloat64le _msgEphemerisDepB_omega0
    putFloat64le _msgEphemerisDepB_omegadot
    putFloat64le _msgEphemerisDepB_w
    putFloat64le _msgEphemerisDepB_inc
    putFloat64le _msgEphemerisDepB_inc_dot
    putFloat64le _msgEphemerisDepB_af0
    putFloat64le _msgEphemerisDepB_af1
    putFloat64le _msgEphemerisDepB_af2
    putFloat64le _msgEphemerisDepB_toe_tow
    putWord16le _msgEphemerisDepB_toe_wn
    putFloat64le _msgEphemerisDepB_toc_tow
    putWord16le _msgEphemerisDepB_toc_wn
    putWord8 _msgEphemerisDepB_valid
    putWord8 _msgEphemerisDepB_healthy
    putWord8 _msgEphemerisDepB_prn
    putWord8 _msgEphemerisDepB_iode

$(makeSBP 'msgEphemerisDepB ''MsgEphemerisDepB)
$(makeJSON "_msgEphemerisDepB_" ''MsgEphemerisDepB)
$(makeLenses ''MsgEphemerisDepB)

msgEphemerisDepC :: Word16
msgEphemerisDepC = 0x0047

-- | SBP class for message MSG_EPHEMERIS_DEP_C (0x0047).
--
-- The ephemeris message returns a set of satellite orbit parameters that is
-- used to calculate GPS satellite position, velocity, and clock offset. Please
-- see the Navstar GPS Space Segment/Navigation user interfaces (ICD-GPS-200,
-- Table 20-III) for more details.
data MsgEphemerisDepC = MsgEphemerisDepC
  { _msgEphemerisDepC_tgd    :: !Double
    -- ^ Group delay differential between L1 and L2
  , _msgEphemerisDepC_c_rs   :: !Double
    -- ^ Amplitude of the sine harmonic correction term to the orbit radius
  , _msgEphemerisDepC_c_rc   :: !Double
    -- ^ Amplitude of the cosine harmonic correction term to the orbit radius
  , _msgEphemerisDepC_c_uc   :: !Double
    -- ^ Amplitude of the cosine harmonic correction term to the argument of
    -- latitude
  , _msgEphemerisDepC_c_us   :: !Double
    -- ^ Amplitude of the sine harmonic correction term to the argument of
    -- latitude
  , _msgEphemerisDepC_c_ic   :: !Double
    -- ^ Amplitude of the cosine harmonic correction term to the angle of
    -- inclination
  , _msgEphemerisDepC_c_is   :: !Double
    -- ^ Amplitude of the sine harmonic correction term to the angle of
    -- inclination
  , _msgEphemerisDepC_dn     :: !Double
    -- ^ Mean motion difference
  , _msgEphemerisDepC_m0     :: !Double
    -- ^ Mean anomaly at reference time
  , _msgEphemerisDepC_ecc    :: !Double
    -- ^ Eccentricity of satellite orbit
  , _msgEphemerisDepC_sqrta  :: !Double
    -- ^ Square root of the semi-major axis of orbit
  , _msgEphemerisDepC_omega0 :: !Double
    -- ^ Longitude of ascending node of orbit plane at weekly epoch
  , _msgEphemerisDepC_omegadot :: !Double
    -- ^ Rate of right ascension
  , _msgEphemerisDepC_w      :: !Double
    -- ^ Argument of perigee
  , _msgEphemerisDepC_inc    :: !Double
    -- ^ Inclination
  , _msgEphemerisDepC_inc_dot :: !Double
    -- ^ Inclination first derivative
  , _msgEphemerisDepC_af0    :: !Double
    -- ^ Polynomial clock correction coefficient (clock bias)
  , _msgEphemerisDepC_af1    :: !Double
    -- ^ Polynomial clock correction coefficient (clock drift)
  , _msgEphemerisDepC_af2    :: !Double
    -- ^ Polynomial clock correction coefficient (rate of clock drift)
  , _msgEphemerisDepC_toe_tow :: !Double
    -- ^ Time of week
  , _msgEphemerisDepC_toe_wn :: !Word16
    -- ^ Week number
  , _msgEphemerisDepC_toc_tow :: !Double
    -- ^ Clock reference time of week
  , _msgEphemerisDepC_toc_wn :: !Word16
    -- ^ Clock reference week number
  , _msgEphemerisDepC_valid  :: !Word8
    -- ^ Is valid?
  , _msgEphemerisDepC_healthy :: !Word8
    -- ^ Satellite is healthy?
  , _msgEphemerisDepC_sid    :: !GnssSignalDep
    -- ^ GNSS signal identifier
  , _msgEphemerisDepC_iode   :: !Word8
    -- ^ Issue of ephemeris data
  , _msgEphemerisDepC_iodc   :: !Word16
    -- ^ Issue of clock data
  , _msgEphemerisDepC_reserved :: !Word32
    -- ^ Reserved field
  } deriving ( Show, Read, Eq )

instance Binary MsgEphemerisDepC where
  get = do
    _msgEphemerisDepC_tgd <- getFloat64le
    _msgEphemerisDepC_c_rs <- getFloat64le
    _msgEphemerisDepC_c_rc <- getFloat64le
    _msgEphemerisDepC_c_uc <- getFloat64le
    _msgEphemerisDepC_c_us <- getFloat64le
    _msgEphemerisDepC_c_ic <- getFloat64le
    _msgEphemerisDepC_c_is <- getFloat64le
    _msgEphemerisDepC_dn <- getFloat64le
    _msgEphemerisDepC_m0 <- getFloat64le
    _msgEphemerisDepC_ecc <- getFloat64le
    _msgEphemerisDepC_sqrta <- getFloat64le
    _msgEphemerisDepC_omega0 <- getFloat64le
    _msgEphemerisDepC_omegadot <- getFloat64le
    _msgEphemerisDepC_w <- getFloat64le
    _msgEphemerisDepC_inc <- getFloat64le
    _msgEphemerisDepC_inc_dot <- getFloat64le
    _msgEphemerisDepC_af0 <- getFloat64le
    _msgEphemerisDepC_af1 <- getFloat64le
    _msgEphemerisDepC_af2 <- getFloat64le
    _msgEphemerisDepC_toe_tow <- getFloat64le
    _msgEphemerisDepC_toe_wn <- getWord16le
    _msgEphemerisDepC_toc_tow <- getFloat64le
    _msgEphemerisDepC_toc_wn <- getWord16le
    _msgEphemerisDepC_valid <- getWord8
    _msgEphemerisDepC_healthy <- getWord8
    _msgEphemerisDepC_sid <- get
    _msgEphemerisDepC_iode <- getWord8
    _msgEphemerisDepC_iodc <- getWord16le
    _msgEphemerisDepC_reserved <- getWord32le
    pure MsgEphemerisDepC {..}

  put MsgEphemerisDepC {..} = do
    putFloat64le _msgEphemerisDepC_tgd
    putFloat64le _msgEphemerisDepC_c_rs
    putFloat64le _msgEphemerisDepC_c_rc
    putFloat64le _msgEphemerisDepC_c_uc
    putFloat64le _msgEphemerisDepC_c_us
    putFloat64le _msgEphemerisDepC_c_ic
    putFloat64le _msgEphemerisDepC_c_is
    putFloat64le _msgEphemerisDepC_dn
    putFloat64le _msgEphemerisDepC_m0
    putFloat64le _msgEphemerisDepC_ecc
    putFloat64le _msgEphemerisDepC_sqrta
    putFloat64le _msgEphemerisDepC_omega0
    putFloat64le _msgEphemerisDepC_omegadot
    putFloat64le _msgEphemerisDepC_w
    putFloat64le _msgEphemerisDepC_inc
    putFloat64le _msgEphemerisDepC_inc_dot
    putFloat64le _msgEphemerisDepC_af0
    putFloat64le _msgEphemerisDepC_af1
    putFloat64le _msgEphemerisDepC_af2
    putFloat64le _msgEphemerisDepC_toe_tow
    putWord16le _msgEphemerisDepC_toe_wn
    putFloat64le _msgEphemerisDepC_toc_tow
    putWord16le _msgEphemerisDepC_toc_wn
    putWord8 _msgEphemerisDepC_valid
    putWord8 _msgEphemerisDepC_healthy
    put _msgEphemerisDepC_sid
    putWord8 _msgEphemerisDepC_iode
    putWord16le _msgEphemerisDepC_iodc
    putWord32le _msgEphemerisDepC_reserved

$(makeSBP 'msgEphemerisDepC ''MsgEphemerisDepC)
$(makeJSON "_msgEphemerisDepC_" ''MsgEphemerisDepC)
$(makeLenses ''MsgEphemerisDepC)

-- | ObservationHeaderDep.
--
-- Header of a GPS observation message.
data ObservationHeaderDep = ObservationHeaderDep
  { _observationHeaderDep_t   :: !GpsTimeDep
    -- ^ GPS time of this observation
  , _observationHeaderDep_n_obs :: !Word8
    -- ^ Total number of observations. First nibble is the size of the sequence
    -- (n), second nibble is the zero-indexed counter (ith packet of n)
  } deriving ( Show, Read, Eq )

instance Binary ObservationHeaderDep where
  get = do
    _observationHeaderDep_t <- get
    _observationHeaderDep_n_obs <- getWord8
    pure ObservationHeaderDep {..}

  put ObservationHeaderDep {..} = do
    put _observationHeaderDep_t
    putWord8 _observationHeaderDep_n_obs

$(makeJSON "_observationHeaderDep_" ''ObservationHeaderDep)
$(makeLenses ''ObservationHeaderDep)

-- | CarrierPhaseDepA.
--
-- Carrier phase measurement in cycles represented as a 40-bit fixed point
-- number with Q32.8 layout, i.e. 32-bits of whole cycles and 8-bits of
-- fractional cycles. This has the opposite sign convention than a typical GPS
-- receiver and the phase has the opposite sign as the pseudorange.
data CarrierPhaseDepA = CarrierPhaseDepA
  { _carrierPhaseDepA_i :: !Int32
    -- ^ Carrier phase whole cycles
  , _carrierPhaseDepA_f :: !Word8
    -- ^ Carrier phase fractional part
  } deriving ( Show, Read, Eq )

instance Binary CarrierPhaseDepA where
  get = do
    _carrierPhaseDepA_i <- fromIntegral <$> getWord32le
    _carrierPhaseDepA_f <- getWord8
    pure CarrierPhaseDepA {..}

  put CarrierPhaseDepA {..} = do
    (putWord32le . fromIntegral) _carrierPhaseDepA_i
    putWord8 _carrierPhaseDepA_f

$(makeJSON "_carrierPhaseDepA_" ''CarrierPhaseDepA)
$(makeLenses ''CarrierPhaseDepA)

-- | PackedObsContentDepA.
--
-- Deprecated.
data PackedObsContentDepA = PackedObsContentDepA
  { _packedObsContentDepA_P  :: !Word32
    -- ^ Pseudorange observation
  , _packedObsContentDepA_L  :: !CarrierPhaseDepA
    -- ^ Carrier phase observation with opposite sign from typical convention
  , _packedObsContentDepA_cn0 :: !Word8
    -- ^ Carrier-to-Noise density
  , _packedObsContentDepA_lock :: !Word16
    -- ^ Lock indicator. This value changes whenever a satellite signal has lost
    -- and regained lock, indicating that the carrier phase ambiguity may have
    -- changed.
  , _packedObsContentDepA_prn :: !Word8
    -- ^ PRN-1 identifier of the satellite signal
  } deriving ( Show, Read, Eq )

instance Binary PackedObsContentDepA where
  get = do
    _packedObsContentDepA_P <- getWord32le
    _packedObsContentDepA_L <- get
    _packedObsContentDepA_cn0 <- getWord8
    _packedObsContentDepA_lock <- getWord16le
    _packedObsContentDepA_prn <- getWord8
    pure PackedObsContentDepA {..}

  put PackedObsContentDepA {..} = do
    putWord32le _packedObsContentDepA_P
    put _packedObsContentDepA_L
    putWord8 _packedObsContentDepA_cn0
    putWord16le _packedObsContentDepA_lock
    putWord8 _packedObsContentDepA_prn

$(makeJSON "_packedObsContentDepA_" ''PackedObsContentDepA)
$(makeLenses ''PackedObsContentDepA)

-- | PackedObsContentDepB.
--
-- Pseudorange and carrier phase observation for a satellite being tracked.
-- Pseudoranges are referenced to a nominal pseudorange.
data PackedObsContentDepB = PackedObsContentDepB
  { _packedObsContentDepB_P  :: !Word32
    -- ^ Pseudorange observation
  , _packedObsContentDepB_L  :: !CarrierPhaseDepA
    -- ^ Carrier phase observation with opposite sign from typical convention.
  , _packedObsContentDepB_cn0 :: !Word8
    -- ^ Carrier-to-Noise density
  , _packedObsContentDepB_lock :: !Word16
    -- ^ Lock indicator. This value changes whenever a satellite signal has lost
    -- and regained lock, indicating that the carrier phase ambiguity may have
    -- changed.
  , _packedObsContentDepB_sid :: !GnssSignalDep
    -- ^ GNSS signal identifier
  } deriving ( Show, Read, Eq )

instance Binary PackedObsContentDepB where
  get = do
    _packedObsContentDepB_P <- getWord32le
    _packedObsContentDepB_L <- get
    _packedObsContentDepB_cn0 <- getWord8
    _packedObsContentDepB_lock <- getWord16le
    _packedObsContentDepB_sid <- get
    pure PackedObsContentDepB {..}

  put PackedObsContentDepB {..} = do
    putWord32le _packedObsContentDepB_P
    put _packedObsContentDepB_L
    putWord8 _packedObsContentDepB_cn0
    putWord16le _packedObsContentDepB_lock
    put _packedObsContentDepB_sid

$(makeJSON "_packedObsContentDepB_" ''PackedObsContentDepB)
$(makeLenses ''PackedObsContentDepB)

-- | PackedObsContentDepC.
--
-- Pseudorange and carrier phase observation for a satellite being tracked. The
-- observations are be interoperable with 3rd party receivers and conform with
-- typical RTCMv3 GNSS observations.
data PackedObsContentDepC = PackedObsContentDepC
  { _packedObsContentDepC_P  :: !Word32
    -- ^ Pseudorange observation
  , _packedObsContentDepC_L  :: !CarrierPhase
    -- ^ Carrier phase observation with typical sign convention.
  , _packedObsContentDepC_cn0 :: !Word8
    -- ^ Carrier-to-Noise density
  , _packedObsContentDepC_lock :: !Word16
    -- ^ Lock indicator. This value changes whenever a satellite signal has lost
    -- and regained lock, indicating that the carrier phase ambiguity may have
    -- changed.
  , _packedObsContentDepC_sid :: !GnssSignalDep
    -- ^ GNSS signal identifier
  } deriving ( Show, Read, Eq )

instance Binary PackedObsContentDepC where
  get = do
    _packedObsContentDepC_P <- getWord32le
    _packedObsContentDepC_L <- get
    _packedObsContentDepC_cn0 <- getWord8
    _packedObsContentDepC_lock <- getWord16le
    _packedObsContentDepC_sid <- get
    pure PackedObsContentDepC {..}

  put PackedObsContentDepC {..} = do
    putWord32le _packedObsContentDepC_P
    put _packedObsContentDepC_L
    putWord8 _packedObsContentDepC_cn0
    putWord16le _packedObsContentDepC_lock
    put _packedObsContentDepC_sid

$(makeJSON "_packedObsContentDepC_" ''PackedObsContentDepC)
$(makeLenses ''PackedObsContentDepC)

msgObsDepA :: Word16
msgObsDepA = 0x0045

-- | SBP class for message MSG_OBS_DEP_A (0x0045).
--
-- Deprecated.
data MsgObsDepA = MsgObsDepA
  { _msgObsDepA_header :: !ObservationHeaderDep
    -- ^ Header of a GPS observation message
  , _msgObsDepA_obs  :: ![PackedObsContentDepA]
    -- ^ Pseudorange and carrier phase observation for a satellite being tracked.
  } deriving ( Show, Read, Eq )

instance Binary MsgObsDepA where
  get = do
    _msgObsDepA_header <- get
    _msgObsDepA_obs <- whileM (not <$> isEmpty) get
    pure MsgObsDepA {..}

  put MsgObsDepA {..} = do
    put _msgObsDepA_header
    mapM_ put _msgObsDepA_obs

$(makeSBP 'msgObsDepA ''MsgObsDepA)
$(makeJSON "_msgObsDepA_" ''MsgObsDepA)
$(makeLenses ''MsgObsDepA)

msgObsDepB :: Word16
msgObsDepB = 0x0043

-- | SBP class for message MSG_OBS_DEP_B (0x0043).
--
-- This observation message has been deprecated in favor of observations that
-- are more interoperable. This message should be used for observations
-- referenced to a nominal pseudorange which are not interoperable with most
-- 3rd party GNSS receievers or typical RTCMv3 observations.
data MsgObsDepB = MsgObsDepB
  { _msgObsDepB_header :: !ObservationHeaderDep
    -- ^ Header of a GPS observation message
  , _msgObsDepB_obs  :: ![PackedObsContentDepB]
    -- ^ Pseudorange and carrier phase observation for a satellite being tracked.
  } deriving ( Show, Read, Eq )

instance Binary MsgObsDepB where
  get = do
    _msgObsDepB_header <- get
    _msgObsDepB_obs <- whileM (not <$> isEmpty) get
    pure MsgObsDepB {..}

  put MsgObsDepB {..} = do
    put _msgObsDepB_header
    mapM_ put _msgObsDepB_obs

$(makeSBP 'msgObsDepB ''MsgObsDepB)
$(makeJSON "_msgObsDepB_" ''MsgObsDepB)
$(makeLenses ''MsgObsDepB)

msgObsDepC :: Word16
msgObsDepC = 0x0049

-- | SBP class for message MSG_OBS_DEP_C (0x0049).
--
-- The GPS observations message reports all the raw pseudorange and carrier
-- phase observations for the satellites being tracked by the device. Carrier
-- phase observation here is represented as a 40-bit fixed point number with
-- Q32.8 layout (i.e. 32-bits of whole cycles and 8-bits of fractional cycles).
-- The observations are interoperable with 3rd party receivers and conform with
-- typical RTCMv3 GNSS observations.
data MsgObsDepC = MsgObsDepC
  { _msgObsDepC_header :: !ObservationHeaderDep
    -- ^ Header of a GPS observation message
  , _msgObsDepC_obs  :: ![PackedObsContentDepC]
    -- ^ Pseudorange and carrier phase observation for a satellite being tracked.
  } deriving ( Show, Read, Eq )

instance Binary MsgObsDepC where
  get = do
    _msgObsDepC_header <- get
    _msgObsDepC_obs <- whileM (not <$> isEmpty) get
    pure MsgObsDepC {..}

  put MsgObsDepC {..} = do
    put _msgObsDepC_header
    mapM_ put _msgObsDepC_obs

$(makeSBP 'msgObsDepC ''MsgObsDepC)
$(makeJSON "_msgObsDepC_" ''MsgObsDepC)
$(makeLenses ''MsgObsDepC)

msgIono :: Word16
msgIono = 0x0090

-- | SBP class for message MSG_IONO (0x0090).
--
-- The ionospheric parameters which allow the "L1 only" or "L2 only" user to
-- utilize the ionospheric model for computation of the ionospheric delay.
-- Please see ICD-GPS-200 (Chapter 20.3.3.5.1.7) for more details.
data MsgIono = MsgIono
  { _msgIono_t_nmct :: !GpsTimeSec
    -- ^ Navigation Message Correction Table Valitidy Time
  , _msgIono_a0   :: !Double
  , _msgIono_a1   :: !Double
  , _msgIono_a2   :: !Double
  , _msgIono_a3   :: !Double
  , _msgIono_b0   :: !Double
  , _msgIono_b1   :: !Double
  , _msgIono_b2   :: !Double
  , _msgIono_b3   :: !Double
  } deriving ( Show, Read, Eq )

instance Binary MsgIono where
  get = do
    _msgIono_t_nmct <- get
    _msgIono_a0 <- getFloat64le
    _msgIono_a1 <- getFloat64le
    _msgIono_a2 <- getFloat64le
    _msgIono_a3 <- getFloat64le
    _msgIono_b0 <- getFloat64le
    _msgIono_b1 <- getFloat64le
    _msgIono_b2 <- getFloat64le
    _msgIono_b3 <- getFloat64le
    pure MsgIono {..}

  put MsgIono {..} = do
    put _msgIono_t_nmct
    putFloat64le _msgIono_a0
    putFloat64le _msgIono_a1
    putFloat64le _msgIono_a2
    putFloat64le _msgIono_a3
    putFloat64le _msgIono_b0
    putFloat64le _msgIono_b1
    putFloat64le _msgIono_b2
    putFloat64le _msgIono_b3

$(makeSBP 'msgIono ''MsgIono)
$(makeJSON "_msgIono_" ''MsgIono)
$(makeLenses ''MsgIono)

msgSvConfigurationGpsDep :: Word16
msgSvConfigurationGpsDep = 0x0091

-- | SBP class for message MSG_SV_CONFIGURATION_GPS_DEP (0x0091).
--
-- Please see ICD-GPS-200 (Chapter 20.3.3.5.1.4) for more details.
data MsgSvConfigurationGpsDep = MsgSvConfigurationGpsDep
  { _msgSvConfigurationGpsDep_t_nmct :: !GpsTimeSec
    -- ^ Navigation Message Correction Table Valitidy Time
  , _msgSvConfigurationGpsDep_l2c_mask :: !Word32
    -- ^ L2C capability mask, SV32 bit being MSB, SV1 bit being LSB
  } deriving ( Show, Read, Eq )

instance Binary MsgSvConfigurationGpsDep where
  get = do
    _msgSvConfigurationGpsDep_t_nmct <- get
    _msgSvConfigurationGpsDep_l2c_mask <- getWord32le
    pure MsgSvConfigurationGpsDep {..}

  put MsgSvConfigurationGpsDep {..} = do
    put _msgSvConfigurationGpsDep_t_nmct
    putWord32le _msgSvConfigurationGpsDep_l2c_mask

$(makeSBP 'msgSvConfigurationGpsDep ''MsgSvConfigurationGpsDep)
$(makeJSON "_msgSvConfigurationGpsDep_" ''MsgSvConfigurationGpsDep)
$(makeLenses ''MsgSvConfigurationGpsDep)

data GnssCapb = GnssCapb
  { _gnssCapb_gps_active :: !Word64
    -- ^ GPS SV active mask
  , _gnssCapb_gps_l2c   :: !Word64
    -- ^ GPS L2C active mask
  , _gnssCapb_gps_l5    :: !Word64
    -- ^ GPS L5 active mask
  , _gnssCapb_glo_active :: !Word32
    -- ^ GLO active mask
  , _gnssCapb_glo_l2of  :: !Word32
    -- ^ GLO L2OF active mask
  , _gnssCapb_glo_l3    :: !Word32
    -- ^ GLO L3 active mask
  , _gnssCapb_sbas_active :: !Word64
    -- ^ SBAS active mask (PRNs 120..158, AN 7/62.2.2-18/18 Table B-23,
    -- https://www.caat.or.th/wp-content/uploads/2018/03/SL-2018.18.E-1.pdf)
  , _gnssCapb_sbas_l5   :: !Word64
    -- ^ SBAS L5 active mask (PRNs 120..158, AN 7/62.2.2-18/18 Table B-23,
    -- https://www.caat.or.th/wp-content/uploads/2018/03/SL-2018.18.E-1.pdf)
  , _gnssCapb_bds_active :: !Word64
    -- ^ BDS active mask
  , _gnssCapb_bds_d2nav :: !Word64
    -- ^ BDS D2NAV active mask
  , _gnssCapb_bds_b2    :: !Word64
    -- ^ BDS B2 active mask
  , _gnssCapb_bds_b2a   :: !Word64
    -- ^ BDS B2A active mask
  , _gnssCapb_qzss_active :: !Word32
    -- ^ QZSS active mask
  , _gnssCapb_gal_active :: !Word64
    -- ^ GAL active mask
  , _gnssCapb_gal_e5    :: !Word64
    -- ^ GAL E5 active mask
  } deriving ( Show, Read, Eq )

instance Binary GnssCapb where
  get = do
    _gnssCapb_gps_active <- getWord64le
    _gnssCapb_gps_l2c <- getWord64le
    _gnssCapb_gps_l5 <- getWord64le
    _gnssCapb_glo_active <- getWord32le
    _gnssCapb_glo_l2of <- getWord32le
    _gnssCapb_glo_l3 <- getWord32le
    _gnssCapb_sbas_active <- getWord64le
    _gnssCapb_sbas_l5 <- getWord64le
    _gnssCapb_bds_active <- getWord64le
    _gnssCapb_bds_d2nav <- getWord64le
    _gnssCapb_bds_b2 <- getWord64le
    _gnssCapb_bds_b2a <- getWord64le
    _gnssCapb_qzss_active <- getWord32le
    _gnssCapb_gal_active <- getWord64le
    _gnssCapb_gal_e5 <- getWord64le
    pure GnssCapb {..}

  put GnssCapb {..} = do
    putWord64le _gnssCapb_gps_active
    putWord64le _gnssCapb_gps_l2c
    putWord64le _gnssCapb_gps_l5
    putWord32le _gnssCapb_glo_active
    putWord32le _gnssCapb_glo_l2of
    putWord32le _gnssCapb_glo_l3
    putWord64le _gnssCapb_sbas_active
    putWord64le _gnssCapb_sbas_l5
    putWord64le _gnssCapb_bds_active
    putWord64le _gnssCapb_bds_d2nav
    putWord64le _gnssCapb_bds_b2
    putWord64le _gnssCapb_bds_b2a
    putWord32le _gnssCapb_qzss_active
    putWord64le _gnssCapb_gal_active
    putWord64le _gnssCapb_gal_e5

$(makeJSON "_gnssCapb_" ''GnssCapb)
$(makeLenses ''GnssCapb)

msgGnssCapb :: Word16
msgGnssCapb = 0x0096

data MsgGnssCapb = MsgGnssCapb
  { _msgGnssCapb_t_nmct :: !GpsTimeSec
    -- ^ Navigation Message Correction Table Validity Time
  , _msgGnssCapb_gc   :: !GnssCapb
    -- ^ GNSS capabilities masks
  } deriving ( Show, Read, Eq )

instance Binary MsgGnssCapb where
  get = do
    _msgGnssCapb_t_nmct <- get
    _msgGnssCapb_gc <- get
    pure MsgGnssCapb {..}

  put MsgGnssCapb {..} = do
    put _msgGnssCapb_t_nmct
    put _msgGnssCapb_gc

$(makeSBP 'msgGnssCapb ''MsgGnssCapb)
$(makeJSON "_msgGnssCapb_" ''MsgGnssCapb)
$(makeLenses ''MsgGnssCapb)

msgGroupDelayDepA :: Word16
msgGroupDelayDepA = 0x0092

-- | SBP class for message MSG_GROUP_DELAY_DEP_A (0x0092).
--
-- Please see ICD-GPS-200 (30.3.3.3.1.1) for more details.
data MsgGroupDelayDepA = MsgGroupDelayDepA
  { _msgGroupDelayDepA_t_op   :: !GpsTimeDep
    -- ^ Data Predict Time of Week
  , _msgGroupDelayDepA_prn    :: !Word8
    -- ^ Satellite number
  , _msgGroupDelayDepA_valid  :: !Word8
    -- ^ bit-field indicating validity of the values, LSB indicating tgd validity
    -- etc. 1 = value is valid, 0 = value is not valid.
  , _msgGroupDelayDepA_tgd    :: !Int16
  , _msgGroupDelayDepA_isc_l1ca :: !Int16
  , _msgGroupDelayDepA_isc_l2c :: !Int16
  } deriving ( Show, Read, Eq )

instance Binary MsgGroupDelayDepA where
  get = do
    _msgGroupDelayDepA_t_op <- get
    _msgGroupDelayDepA_prn <- getWord8
    _msgGroupDelayDepA_valid <- getWord8
    _msgGroupDelayDepA_tgd <- fromIntegral <$> getWord16le
    _msgGroupDelayDepA_isc_l1ca <- fromIntegral <$> getWord16le
    _msgGroupDelayDepA_isc_l2c <- fromIntegral <$> getWord16le
    pure MsgGroupDelayDepA {..}

  put MsgGroupDelayDepA {..} = do
    put _msgGroupDelayDepA_t_op
    putWord8 _msgGroupDelayDepA_prn
    putWord8 _msgGroupDelayDepA_valid
    (putWord16le . fromIntegral) _msgGroupDelayDepA_tgd
    (putWord16le . fromIntegral) _msgGroupDelayDepA_isc_l1ca
    (putWord16le . fromIntegral) _msgGroupDelayDepA_isc_l2c

$(makeSBP 'msgGroupDelayDepA ''MsgGroupDelayDepA)
$(makeJSON "_msgGroupDelayDepA_" ''MsgGroupDelayDepA)
$(makeLenses ''MsgGroupDelayDepA)

msgGroupDelayDepB :: Word16
msgGroupDelayDepB = 0x0093

-- | SBP class for message MSG_GROUP_DELAY_DEP_B (0x0093).
--
-- Please see ICD-GPS-200 (30.3.3.3.1.1) for more details.
data MsgGroupDelayDepB = MsgGroupDelayDepB
  { _msgGroupDelayDepB_t_op   :: !GpsTimeSec
    -- ^ Data Predict Time of Week
  , _msgGroupDelayDepB_sid    :: !GnssSignalDep
    -- ^ GNSS signal identifier
  , _msgGroupDelayDepB_valid  :: !Word8
    -- ^ bit-field indicating validity of the values, LSB indicating tgd validity
    -- etc. 1 = value is valid, 0 = value is not valid.
  , _msgGroupDelayDepB_tgd    :: !Int16
  , _msgGroupDelayDepB_isc_l1ca :: !Int16
  , _msgGroupDelayDepB_isc_l2c :: !Int16
  } deriving ( Show, Read, Eq )

instance Binary MsgGroupDelayDepB where
  get = do
    _msgGroupDelayDepB_t_op <- get
    _msgGroupDelayDepB_sid <- get
    _msgGroupDelayDepB_valid <- getWord8
    _msgGroupDelayDepB_tgd <- fromIntegral <$> getWord16le
    _msgGroupDelayDepB_isc_l1ca <- fromIntegral <$> getWord16le
    _msgGroupDelayDepB_isc_l2c <- fromIntegral <$> getWord16le
    pure MsgGroupDelayDepB {..}

  put MsgGroupDelayDepB {..} = do
    put _msgGroupDelayDepB_t_op
    put _msgGroupDelayDepB_sid
    putWord8 _msgGroupDelayDepB_valid
    (putWord16le . fromIntegral) _msgGroupDelayDepB_tgd
    (putWord16le . fromIntegral) _msgGroupDelayDepB_isc_l1ca
    (putWord16le . fromIntegral) _msgGroupDelayDepB_isc_l2c

$(makeSBP 'msgGroupDelayDepB ''MsgGroupDelayDepB)
$(makeJSON "_msgGroupDelayDepB_" ''MsgGroupDelayDepB)
$(makeLenses ''MsgGroupDelayDepB)

msgGroupDelay :: Word16
msgGroupDelay = 0x0094

-- | SBP class for message MSG_GROUP_DELAY (0x0094).
--
-- Please see ICD-GPS-200 (30.3.3.3.1.1) for more details.
data MsgGroupDelay = MsgGroupDelay
  { _msgGroupDelay_t_op   :: !GpsTimeSec
    -- ^ Data Predict Time of Week
  , _msgGroupDelay_sid    :: !GnssSignal
    -- ^ GNSS signal identifier
  , _msgGroupDelay_valid  :: !Word8
    -- ^ bit-field indicating validity of the values, LSB indicating tgd validity
    -- etc. 1 = value is valid, 0 = value is not valid.
  , _msgGroupDelay_tgd    :: !Int16
  , _msgGroupDelay_isc_l1ca :: !Int16
  , _msgGroupDelay_isc_l2c :: !Int16
  } deriving ( Show, Read, Eq )

instance Binary MsgGroupDelay where
  get = do
    _msgGroupDelay_t_op <- get
    _msgGroupDelay_sid <- get
    _msgGroupDelay_valid <- getWord8
    _msgGroupDelay_tgd <- fromIntegral <$> getWord16le
    _msgGroupDelay_isc_l1ca <- fromIntegral <$> getWord16le
    _msgGroupDelay_isc_l2c <- fromIntegral <$> getWord16le
    pure MsgGroupDelay {..}

  put MsgGroupDelay {..} = do
    put _msgGroupDelay_t_op
    put _msgGroupDelay_sid
    putWord8 _msgGroupDelay_valid
    (putWord16le . fromIntegral) _msgGroupDelay_tgd
    (putWord16le . fromIntegral) _msgGroupDelay_isc_l1ca
    (putWord16le . fromIntegral) _msgGroupDelay_isc_l2c

$(makeSBP 'msgGroupDelay ''MsgGroupDelay)
$(makeJSON "_msgGroupDelay_" ''MsgGroupDelay)
$(makeLenses ''MsgGroupDelay)

data AlmanacCommonContent = AlmanacCommonContent
  { _almanacCommonContent_sid        :: !GnssSignal
    -- ^ GNSS signal identifier
  , _almanacCommonContent_toa        :: !GpsTimeSec
    -- ^ Reference time of almanac
  , _almanacCommonContent_ura        :: !Double
    -- ^ User Range Accuracy
  , _almanacCommonContent_fit_interval :: !Word32
    -- ^ Curve fit interval
  , _almanacCommonContent_valid      :: !Word8
    -- ^ Status of almanac, 1 = valid, 0 = invalid
  , _almanacCommonContent_health_bits :: !Word8
    -- ^ Satellite health status for GPS:   - bits 5-7: NAV data health status.
    -- See IS-GPS-200H     Table 20-VII: NAV Data Health Indications.   - bits
    -- 0-4: Signal health status. See IS-GPS-200H     Table 20-VIII. Codes for
    -- Health of SV Signal     Components. Satellite health status for GLO:
    -- See GLO ICD 5.1 table 5.1 for details   - bit 0: C(n), "unhealthy" flag
    -- that is transmitted within     non-immediate data and indicates overall
    -- constellation status     at the moment of almanac uploading.     '0'
    -- indicates malfunction of n-satellite.     '1' indicates that n-satellite
    -- is operational.   - bit 1: Bn(ln), '0' indicates the satellite is
    -- operational     and suitable for navigation.
  } deriving ( Show, Read, Eq )

instance Binary AlmanacCommonContent where
  get = do
    _almanacCommonContent_sid <- get
    _almanacCommonContent_toa <- get
    _almanacCommonContent_ura <- getFloat64le
    _almanacCommonContent_fit_interval <- getWord32le
    _almanacCommonContent_valid <- getWord8
    _almanacCommonContent_health_bits <- getWord8
    pure AlmanacCommonContent {..}

  put AlmanacCommonContent {..} = do
    put _almanacCommonContent_sid
    put _almanacCommonContent_toa
    putFloat64le _almanacCommonContent_ura
    putWord32le _almanacCommonContent_fit_interval
    putWord8 _almanacCommonContent_valid
    putWord8 _almanacCommonContent_health_bits

$(makeJSON "_almanacCommonContent_" ''AlmanacCommonContent)
$(makeLenses ''AlmanacCommonContent)

data AlmanacCommonContentDep = AlmanacCommonContentDep
  { _almanacCommonContentDep_sid        :: !GnssSignalDep
    -- ^ GNSS signal identifier
  , _almanacCommonContentDep_toa        :: !GpsTimeSec
    -- ^ Reference time of almanac
  , _almanacCommonContentDep_ura        :: !Double
    -- ^ User Range Accuracy
  , _almanacCommonContentDep_fit_interval :: !Word32
    -- ^ Curve fit interval
  , _almanacCommonContentDep_valid      :: !Word8
    -- ^ Status of almanac, 1 = valid, 0 = invalid
  , _almanacCommonContentDep_health_bits :: !Word8
    -- ^ Satellite health status for GPS:   - bits 5-7: NAV data health status.
    -- See IS-GPS-200H     Table 20-VII: NAV Data Health Indications.   - bits
    -- 0-4: Signal health status. See IS-GPS-200H     Table 20-VIII. Codes for
    -- Health of SV Signal     Components. Satellite health status for GLO:
    -- See GLO ICD 5.1 table 5.1 for details   - bit 0: C(n), "unhealthy" flag
    -- that is transmitted within     non-immediate data and indicates overall
    -- constellation status     at the moment of almanac uploading.     '0'
    -- indicates malfunction of n-satellite.     '1' indicates that n-satellite
    -- is operational.   - bit 1: Bn(ln), '0' indicates the satellite is
    -- operational     and suitable for navigation.
  } deriving ( Show, Read, Eq )

instance Binary AlmanacCommonContentDep where
  get = do
    _almanacCommonContentDep_sid <- get
    _almanacCommonContentDep_toa <- get
    _almanacCommonContentDep_ura <- getFloat64le
    _almanacCommonContentDep_fit_interval <- getWord32le
    _almanacCommonContentDep_valid <- getWord8
    _almanacCommonContentDep_health_bits <- getWord8
    pure AlmanacCommonContentDep {..}

  put AlmanacCommonContentDep {..} = do
    put _almanacCommonContentDep_sid
    put _almanacCommonContentDep_toa
    putFloat64le _almanacCommonContentDep_ura
    putWord32le _almanacCommonContentDep_fit_interval
    putWord8 _almanacCommonContentDep_valid
    putWord8 _almanacCommonContentDep_health_bits

$(makeJSON "_almanacCommonContentDep_" ''AlmanacCommonContentDep)
$(makeLenses ''AlmanacCommonContentDep)

msgAlmanacGpsDep :: Word16
msgAlmanacGpsDep = 0x0070

-- | SBP class for message MSG_ALMANAC_GPS_DEP (0x0070).
--
-- The almanac message returns a set of satellite orbit parameters. Almanac
-- data is not very precise and is considered valid for up to several months.
-- Please see the Navstar GPS Space Segment/Navigation user interfaces (ICD-
-- GPS-200, Chapter 20.3.3.5.1.2 Almanac Data) for more details.
data MsgAlmanacGpsDep = MsgAlmanacGpsDep
  { _msgAlmanacGpsDep_common :: !AlmanacCommonContentDep
    -- ^ Values common for all almanac types
  , _msgAlmanacGpsDep_m0     :: !Double
    -- ^ Mean anomaly at reference time
  , _msgAlmanacGpsDep_ecc    :: !Double
    -- ^ Eccentricity of satellite orbit
  , _msgAlmanacGpsDep_sqrta  :: !Double
    -- ^ Square root of the semi-major axis of orbit
  , _msgAlmanacGpsDep_omega0 :: !Double
    -- ^ Longitude of ascending node of orbit plane at weekly epoch
  , _msgAlmanacGpsDep_omegadot :: !Double
    -- ^ Rate of right ascension
  , _msgAlmanacGpsDep_w      :: !Double
    -- ^ Argument of perigee
  , _msgAlmanacGpsDep_inc    :: !Double
    -- ^ Inclination
  , _msgAlmanacGpsDep_af0    :: !Double
    -- ^ Polynomial clock correction coefficient (clock bias)
  , _msgAlmanacGpsDep_af1    :: !Double
    -- ^ Polynomial clock correction coefficient (clock drift)
  } deriving ( Show, Read, Eq )

instance Binary MsgAlmanacGpsDep where
  get = do
    _msgAlmanacGpsDep_common <- get
    _msgAlmanacGpsDep_m0 <- getFloat64le
    _msgAlmanacGpsDep_ecc <- getFloat64le
    _msgAlmanacGpsDep_sqrta <- getFloat64le
    _msgAlmanacGpsDep_omega0 <- getFloat64le
    _msgAlmanacGpsDep_omegadot <- getFloat64le
    _msgAlmanacGpsDep_w <- getFloat64le
    _msgAlmanacGpsDep_inc <- getFloat64le
    _msgAlmanacGpsDep_af0 <- getFloat64le
    _msgAlmanacGpsDep_af1 <- getFloat64le
    pure MsgAlmanacGpsDep {..}

  put MsgAlmanacGpsDep {..} = do
    put _msgAlmanacGpsDep_common
    putFloat64le _msgAlmanacGpsDep_m0
    putFloat64le _msgAlmanacGpsDep_ecc
    putFloat64le _msgAlmanacGpsDep_sqrta
    putFloat64le _msgAlmanacGpsDep_omega0
    putFloat64le _msgAlmanacGpsDep_omegadot
    putFloat64le _msgAlmanacGpsDep_w
    putFloat64le _msgAlmanacGpsDep_inc
    putFloat64le _msgAlmanacGpsDep_af0
    putFloat64le _msgAlmanacGpsDep_af1

$(makeSBP 'msgAlmanacGpsDep ''MsgAlmanacGpsDep)
$(makeJSON "_msgAlmanacGpsDep_" ''MsgAlmanacGpsDep)
$(makeLenses ''MsgAlmanacGpsDep)

msgAlmanacGps :: Word16
msgAlmanacGps = 0x0072

-- | SBP class for message MSG_ALMANAC_GPS (0x0072).
--
-- The almanac message returns a set of satellite orbit parameters. Almanac
-- data is not very precise and is considered valid for up to several months.
-- Please see the Navstar GPS Space Segment/Navigation user interfaces (ICD-
-- GPS-200, Chapter 20.3.3.5.1.2 Almanac Data) for more details.
data MsgAlmanacGps = MsgAlmanacGps
  { _msgAlmanacGps_common :: !AlmanacCommonContent
    -- ^ Values common for all almanac types
  , _msgAlmanacGps_m0     :: !Double
    -- ^ Mean anomaly at reference time
  , _msgAlmanacGps_ecc    :: !Double
    -- ^ Eccentricity of satellite orbit
  , _msgAlmanacGps_sqrta  :: !Double
    -- ^ Square root of the semi-major axis of orbit
  , _msgAlmanacGps_omega0 :: !Double
    -- ^ Longitude of ascending node of orbit plane at weekly epoch
  , _msgAlmanacGps_omegadot :: !Double
    -- ^ Rate of right ascension
  , _msgAlmanacGps_w      :: !Double
    -- ^ Argument of perigee
  , _msgAlmanacGps_inc    :: !Double
    -- ^ Inclination
  , _msgAlmanacGps_af0    :: !Double
    -- ^ Polynomial clock correction coefficient (clock bias)
  , _msgAlmanacGps_af1    :: !Double
    -- ^ Polynomial clock correction coefficient (clock drift)
  } deriving ( Show, Read, Eq )

instance Binary MsgAlmanacGps where
  get = do
    _msgAlmanacGps_common <- get
    _msgAlmanacGps_m0 <- getFloat64le
    _msgAlmanacGps_ecc <- getFloat64le
    _msgAlmanacGps_sqrta <- getFloat64le
    _msgAlmanacGps_omega0 <- getFloat64le
    _msgAlmanacGps_omegadot <- getFloat64le
    _msgAlmanacGps_w <- getFloat64le
    _msgAlmanacGps_inc <- getFloat64le
    _msgAlmanacGps_af0 <- getFloat64le
    _msgAlmanacGps_af1 <- getFloat64le
    pure MsgAlmanacGps {..}

  put MsgAlmanacGps {..} = do
    put _msgAlmanacGps_common
    putFloat64le _msgAlmanacGps_m0
    putFloat64le _msgAlmanacGps_ecc
    putFloat64le _msgAlmanacGps_sqrta
    putFloat64le _msgAlmanacGps_omega0
    putFloat64le _msgAlmanacGps_omegadot
    putFloat64le _msgAlmanacGps_w
    putFloat64le _msgAlmanacGps_inc
    putFloat64le _msgAlmanacGps_af0
    putFloat64le _msgAlmanacGps_af1

$(makeSBP 'msgAlmanacGps ''MsgAlmanacGps)
$(makeJSON "_msgAlmanacGps_" ''MsgAlmanacGps)
$(makeLenses ''MsgAlmanacGps)

msgAlmanacGloDep :: Word16
msgAlmanacGloDep = 0x0071

-- | SBP class for message MSG_ALMANAC_GLO_DEP (0x0071).
--
-- The almanac message returns a set of satellite orbit parameters. Almanac
-- data is not very precise and is considered valid for up to several months.
-- Please see the GLO ICD 5.1 "Chapter 4.5 Non-immediate information and
-- almanac" for details.
data MsgAlmanacGloDep = MsgAlmanacGloDep
  { _msgAlmanacGloDep_common    :: !AlmanacCommonContentDep
    -- ^ Values common for all almanac types
  , _msgAlmanacGloDep_lambda_na :: !Double
    -- ^ Longitude of the first ascending node of the orbit in PZ-90.02
    -- coordinate system
  , _msgAlmanacGloDep_t_lambda_na :: !Double
    -- ^ Time of the first ascending node passage
  , _msgAlmanacGloDep_i         :: !Double
    -- ^ Value of inclination at instant of t_lambda
  , _msgAlmanacGloDep_t         :: !Double
    -- ^ Value of Draconian period at instant of t_lambda
  , _msgAlmanacGloDep_t_dot     :: !Double
    -- ^ Rate of change of the Draconian period
  , _msgAlmanacGloDep_epsilon   :: !Double
    -- ^ Eccentricity at instant of t_lambda
  , _msgAlmanacGloDep_omega     :: !Double
    -- ^ Argument of perigee at instant of t_lambda
  } deriving ( Show, Read, Eq )

instance Binary MsgAlmanacGloDep where
  get = do
    _msgAlmanacGloDep_common <- get
    _msgAlmanacGloDep_lambda_na <- getFloat64le
    _msgAlmanacGloDep_t_lambda_na <- getFloat64le
    _msgAlmanacGloDep_i <- getFloat64le
    _msgAlmanacGloDep_t <- getFloat64le
    _msgAlmanacGloDep_t_dot <- getFloat64le
    _msgAlmanacGloDep_epsilon <- getFloat64le
    _msgAlmanacGloDep_omega <- getFloat64le
    pure MsgAlmanacGloDep {..}

  put MsgAlmanacGloDep {..} = do
    put _msgAlmanacGloDep_common
    putFloat64le _msgAlmanacGloDep_lambda_na
    putFloat64le _msgAlmanacGloDep_t_lambda_na
    putFloat64le _msgAlmanacGloDep_i
    putFloat64le _msgAlmanacGloDep_t
    putFloat64le _msgAlmanacGloDep_t_dot
    putFloat64le _msgAlmanacGloDep_epsilon
    putFloat64le _msgAlmanacGloDep_omega

$(makeSBP 'msgAlmanacGloDep ''MsgAlmanacGloDep)
$(makeJSON "_msgAlmanacGloDep_" ''MsgAlmanacGloDep)
$(makeLenses ''MsgAlmanacGloDep)

msgAlmanacGlo :: Word16
msgAlmanacGlo = 0x0073

-- | SBP class for message MSG_ALMANAC_GLO (0x0073).
--
-- The almanac message returns a set of satellite orbit parameters. Almanac
-- data is not very precise and is considered valid for up to several months.
-- Please see the GLO ICD 5.1 "Chapter 4.5 Non-immediate information and
-- almanac" for details.
data MsgAlmanacGlo = MsgAlmanacGlo
  { _msgAlmanacGlo_common    :: !AlmanacCommonContent
    -- ^ Values common for all almanac types
  , _msgAlmanacGlo_lambda_na :: !Double
    -- ^ Longitude of the first ascending node of the orbit in PZ-90.02
    -- coordinate system
  , _msgAlmanacGlo_t_lambda_na :: !Double
    -- ^ Time of the first ascending node passage
  , _msgAlmanacGlo_i         :: !Double
    -- ^ Value of inclination at instant of t_lambda
  , _msgAlmanacGlo_t         :: !Double
    -- ^ Value of Draconian period at instant of t_lambda
  , _msgAlmanacGlo_t_dot     :: !Double
    -- ^ Rate of change of the Draconian period
  , _msgAlmanacGlo_epsilon   :: !Double
    -- ^ Eccentricity at instant of t_lambda
  , _msgAlmanacGlo_omega     :: !Double
    -- ^ Argument of perigee at instant of t_lambda
  } deriving ( Show, Read, Eq )

instance Binary MsgAlmanacGlo where
  get = do
    _msgAlmanacGlo_common <- get
    _msgAlmanacGlo_lambda_na <- getFloat64le
    _msgAlmanacGlo_t_lambda_na <- getFloat64le
    _msgAlmanacGlo_i <- getFloat64le
    _msgAlmanacGlo_t <- getFloat64le
    _msgAlmanacGlo_t_dot <- getFloat64le
    _msgAlmanacGlo_epsilon <- getFloat64le
    _msgAlmanacGlo_omega <- getFloat64le
    pure MsgAlmanacGlo {..}

  put MsgAlmanacGlo {..} = do
    put _msgAlmanacGlo_common
    putFloat64le _msgAlmanacGlo_lambda_na
    putFloat64le _msgAlmanacGlo_t_lambda_na
    putFloat64le _msgAlmanacGlo_i
    putFloat64le _msgAlmanacGlo_t
    putFloat64le _msgAlmanacGlo_t_dot
    putFloat64le _msgAlmanacGlo_epsilon
    putFloat64le _msgAlmanacGlo_omega

$(makeSBP 'msgAlmanacGlo ''MsgAlmanacGlo)
$(makeJSON "_msgAlmanacGlo_" ''MsgAlmanacGlo)
$(makeLenses ''MsgAlmanacGlo)

msgGloBiases :: Word16
msgGloBiases = 0x0075

-- | SBP class for message MSG_GLO_BIASES (0x0075).
--
-- The GLONASS L1/L2 Code-Phase biases allows to perform GPS+GLONASS integer
-- ambiguity resolution for baselines with mixed receiver types (e.g. receiver
-- of different manufacturers)
data MsgGloBiases = MsgGloBiases
  { _msgGloBiases_mask    :: !Word8
    -- ^ GLONASS FDMA signals mask
  , _msgGloBiases_l1ca_bias :: !Int16
    -- ^ GLONASS L1 C/A Code-Phase Bias
  , _msgGloBiases_l1p_bias :: !Int16
    -- ^ GLONASS L1 P Code-Phase Bias
  , _msgGloBiases_l2ca_bias :: !Int16
    -- ^ GLONASS L2 C/A Code-Phase Bias
  , _msgGloBiases_l2p_bias :: !Int16
    -- ^ GLONASS L2 P Code-Phase Bias
  } deriving ( Show, Read, Eq )

instance Binary MsgGloBiases where
  get = do
    _msgGloBiases_mask <- getWord8
    _msgGloBiases_l1ca_bias <- fromIntegral <$> getWord16le
    _msgGloBiases_l1p_bias <- fromIntegral <$> getWord16le
    _msgGloBiases_l2ca_bias <- fromIntegral <$> getWord16le
    _msgGloBiases_l2p_bias <- fromIntegral <$> getWord16le
    pure MsgGloBiases {..}

  put MsgGloBiases {..} = do
    putWord8 _msgGloBiases_mask
    (putWord16le . fromIntegral) _msgGloBiases_l1ca_bias
    (putWord16le . fromIntegral) _msgGloBiases_l1p_bias
    (putWord16le . fromIntegral) _msgGloBiases_l2ca_bias
    (putWord16le . fromIntegral) _msgGloBiases_l2p_bias

$(makeSBP 'msgGloBiases ''MsgGloBiases)
$(makeJSON "_msgGloBiases_" ''MsgGloBiases)
$(makeLenses ''MsgGloBiases)

-- | SvAzEl.
--
-- Satellite azimuth and elevation.
data SvAzEl = SvAzEl
  { _svAzEl_sid :: !GnssSignal
    -- ^ GNSS signal identifier
  , _svAzEl_az :: !Word8
    -- ^ Azimuth angle (range 0..179)
  , _svAzEl_el :: !Int8
    -- ^ Elevation angle (range -90..90)
  } deriving ( Show, Read, Eq )

instance Binary SvAzEl where
  get = do
    _svAzEl_sid <- get
    _svAzEl_az <- getWord8
    _svAzEl_el <- fromIntegral <$> getWord8
    pure SvAzEl {..}

  put SvAzEl {..} = do
    put _svAzEl_sid
    putWord8 _svAzEl_az
    (putWord8 . fromIntegral) _svAzEl_el

$(makeJSON "_svAzEl_" ''SvAzEl)
$(makeLenses ''SvAzEl)

msgSvAzEl :: Word16
msgSvAzEl = 0x0097

-- | SBP class for message MSG_SV_AZ_EL (0x0097).
--
-- Azimuth and elevation angles of all the visible satellites that the device
-- does have ephemeris or almanac for.
data MsgSvAzEl = MsgSvAzEl
  { _msgSvAzEl_azel :: ![SvAzEl]
    -- ^ Azimuth and elevation per satellite
  } deriving ( Show, Read, Eq )

instance Binary MsgSvAzEl where
  get = do
    _msgSvAzEl_azel <- whileM (not <$> isEmpty) get
    pure MsgSvAzEl {..}

  put MsgSvAzEl {..} = do
    mapM_ put _msgSvAzEl_azel

$(makeSBP 'msgSvAzEl ''MsgSvAzEl)
$(makeJSON "_msgSvAzEl_" ''MsgSvAzEl)
$(makeLenses ''MsgSvAzEl)

msgOsr :: Word16
msgOsr = 0x0640

-- | SBP class for message MSG_OSR (0x0640).
--
-- The OSR message contains network corrections in an observation-like format
data MsgOsr = MsgOsr
  { _msgOsr_header :: !ObservationHeader
    -- ^ Header of a GPS observation message
  , _msgOsr_obs  :: ![PackedOsrContent]
    -- ^ Network correction for a satellite signal.
  } deriving ( Show, Read, Eq )

instance Binary MsgOsr where
  get = do
    _msgOsr_header <- get
    _msgOsr_obs <- whileM (not <$> isEmpty) get
    pure MsgOsr {..}

  put MsgOsr {..} = do
    put _msgOsr_header
    mapM_ put _msgOsr_obs

$(makeSBP 'msgOsr ''MsgOsr)
$(makeJSON "_msgOsr_" ''MsgOsr)
$(makeLenses ''MsgOsr)
