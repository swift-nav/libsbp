{-# OPTIONS_GHC -fno-warn-unused-imports #-}
-- |
-- Module:      SwiftNav.SBP.Observation
-- Copyright:   Copyright (C) 2015 Swift Navigation, Inc.
-- License:     LGPL-3
-- Maintainer:  Mark Fine <dev@swiftnav.com>
-- Stability:   experimental
-- Portability: portable
--
-- Satellite observation messages from the device.

module SwiftNav.SBP.Observation where

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

-- | ObservationHeader.
--
-- Header of a GNSS observation message.
data ObservationHeader = ObservationHeader
  { _observationHeader_t   :: GpsTimeNano
    -- ^ GNSS time of this observation
  , _observationHeader_n_obs :: Word8
    -- ^ Total number of observations. First nibble is the size of the sequence
    -- (n), second nibble is the zero-indexed counter (ith packet of n)
  } deriving ( Show, Read, Eq )

instance Binary ObservationHeader where
  get = do
    _observationHeader_t <- get
    _observationHeader_n_obs <- getWord8
    return ObservationHeader {..}

  put ObservationHeader {..} = do
    put _observationHeader_t
    putWord8 _observationHeader_n_obs
$(deriveJSON defaultOptions {fieldLabelModifier = fromMaybe "_observationHeader_" . P.stripPrefix "_observationHeader_"}
             ''ObservationHeader)
$(makeLenses ''ObservationHeader)

-- | Doppler.
--
-- Doppler measurement in Hz represented as a 24-bit fixed point number with
-- Q16.8 layout, i.e. 16-bits of whole doppler and 8-bits of fractional
-- doppler. This doppler is defined as positive for approaching satellites.
data Doppler = Doppler
  { _doppler_i :: Int16
    -- ^ Doppler whole Hz
  , _doppler_f :: Word8
    -- ^ Doppler fractional part
  } deriving ( Show, Read, Eq )

instance Binary Doppler where
  get = do
    _doppler_i <- fromIntegral <$> getWord16le
    _doppler_f <- getWord8
    return Doppler {..}

  put Doppler {..} = do
    putWord16le $ fromIntegral _doppler_i
    putWord8 _doppler_f
$(deriveJSON defaultOptions {fieldLabelModifier = fromMaybe "_doppler_" . P.stripPrefix "_doppler_"}
             ''Doppler)
$(makeLenses ''Doppler)

-- | PackedObsContent.
--
-- Pseudorange and carrier phase observation for a satellite being tracked. The
-- observations are interoperable with 3rd party receivers and conform with
-- typical RTCMv3 GNSS observations.
data PackedObsContent = PackedObsContent
  { _packedObsContent_P   :: Word32
    -- ^ Pseudorange observation
  , _packedObsContent_L   :: CarrierPhase
    -- ^ Carrier phase observation with typical sign convention.
  , _packedObsContent_D   :: Doppler
    -- ^ Doppler observation with typical sign convention.
  , _packedObsContent_cn0 :: Word8
    -- ^ Carrier-to-Noise density.  Zero implies invalid cn0.
  , _packedObsContent_lock :: Word8
    -- ^ Lock timer. This value gives an indication of the time for which a
    -- signal has maintained continuous phase lock. Whenever a signal has lost
    -- and regained lock, this value is reset to zero. It is encoded according
    -- to DF402 from the RTCM 10403.2 Amendment 2 specification.  Valid values
    -- range from 0 to 15 and the most significant nibble is reserved for
    -- future use.
  , _packedObsContent_flags :: Word8
    -- ^ Measurement status flags. A bit field of flags providing the status of
    -- this observation.  If this field is 0 it means only the Cn0 estimate for
    -- the signal is valid.
  , _packedObsContent_sid :: GnssSignal16
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
    return PackedObsContent {..}

  put PackedObsContent {..} = do
    putWord32le _packedObsContent_P
    put _packedObsContent_L
    put _packedObsContent_D
    putWord8 _packedObsContent_cn0
    putWord8 _packedObsContent_lock
    putWord8 _packedObsContent_flags
    put _packedObsContent_sid
$(deriveJSON defaultOptions {fieldLabelModifier = fromMaybe "_packedObsContent_" . P.stripPrefix "_packedObsContent_"}
             ''PackedObsContent)
$(makeLenses ''PackedObsContent)

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
  { _msgObs_header :: ObservationHeader
    -- ^ Header of a GPS observation message
  , _msgObs_obs  :: [PackedObsContent]
    -- ^ Pseudorange and carrier phase observation for a satellite being tracked.
  } deriving ( Show, Read, Eq )

instance Binary MsgObs where
  get = do
    _msgObs_header <- get
    _msgObs_obs <- whileM (not <$> isEmpty) get
    return MsgObs {..}

  put MsgObs {..} = do
    put _msgObs_header
    mapM_ put _msgObs_obs

$(deriveSBP 'msgObs ''MsgObs)

$(deriveJSON defaultOptions {fieldLabelModifier = fromMaybe "_msgObs_" . P.stripPrefix "_msgObs_"}
             ''MsgObs)
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
  { _msgBasePosLlh_lat  :: Double
    -- ^ Latitude
  , _msgBasePosLlh_lon  :: Double
    -- ^ Longitude
  , _msgBasePosLlh_height :: Double
    -- ^ Height
  } deriving ( Show, Read, Eq )

instance Binary MsgBasePosLlh where
  get = do
    _msgBasePosLlh_lat <- getFloat64le
    _msgBasePosLlh_lon <- getFloat64le
    _msgBasePosLlh_height <- getFloat64le
    return MsgBasePosLlh {..}

  put MsgBasePosLlh {..} = do
    putFloat64le _msgBasePosLlh_lat
    putFloat64le _msgBasePosLlh_lon
    putFloat64le _msgBasePosLlh_height

$(deriveSBP 'msgBasePosLlh ''MsgBasePosLlh)

$(deriveJSON defaultOptions {fieldLabelModifier = fromMaybe "_msgBasePosLlh_" . P.stripPrefix "_msgBasePosLlh_"}
             ''MsgBasePosLlh)
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
  { _msgBasePosEcef_x :: Double
    -- ^ ECEF X coodinate
  , _msgBasePosEcef_y :: Double
    -- ^ ECEF Y coordinate
  , _msgBasePosEcef_z :: Double
    -- ^ ECEF Z coordinate
  } deriving ( Show, Read, Eq )

instance Binary MsgBasePosEcef where
  get = do
    _msgBasePosEcef_x <- getFloat64le
    _msgBasePosEcef_y <- getFloat64le
    _msgBasePosEcef_z <- getFloat64le
    return MsgBasePosEcef {..}

  put MsgBasePosEcef {..} = do
    putFloat64le _msgBasePosEcef_x
    putFloat64le _msgBasePosEcef_y
    putFloat64le _msgBasePosEcef_z

$(deriveSBP 'msgBasePosEcef ''MsgBasePosEcef)

$(deriveJSON defaultOptions {fieldLabelModifier = fromMaybe "_msgBasePosEcef_" . P.stripPrefix "_msgBasePosEcef_"}
             ''MsgBasePosEcef)
$(makeLenses ''MsgBasePosEcef)

data EphemerisCommonContent = EphemerisCommonContent
  { _ephemerisCommonContent_sid        :: GnssSignal16
    -- ^ GNSS signal identifier (16 bit)
  , _ephemerisCommonContent_toe        :: GpsTimeSec
    -- ^ Time of Ephemerides
  , _ephemerisCommonContent_ura        :: Double
    -- ^ User Range Accuracy
  , _ephemerisCommonContent_fit_interval :: Word32
    -- ^ Curve fit interval
  , _ephemerisCommonContent_valid      :: Word8
    -- ^ Status of ephemeris, 1 = valid, 0 = invalid
  , _ephemerisCommonContent_health_bits :: Word8
    -- ^ Satellite health status. GPS: ICD-GPS-200, chapter 20.3.3.3.1.4 SBAS: 0
    -- = valid, non-zero = invalid GLO: 0 = valid, non-zero = invalid
  } deriving ( Show, Read, Eq )

instance Binary EphemerisCommonContent where
  get = do
    _ephemerisCommonContent_sid <- get
    _ephemerisCommonContent_toe <- get
    _ephemerisCommonContent_ura <- getFloat64le
    _ephemerisCommonContent_fit_interval <- getWord32le
    _ephemerisCommonContent_valid <- getWord8
    _ephemerisCommonContent_health_bits <- getWord8
    return EphemerisCommonContent {..}

  put EphemerisCommonContent {..} = do
    put _ephemerisCommonContent_sid
    put _ephemerisCommonContent_toe
    putFloat64le _ephemerisCommonContent_ura
    putWord32le _ephemerisCommonContent_fit_interval
    putWord8 _ephemerisCommonContent_valid
    putWord8 _ephemerisCommonContent_health_bits
$(deriveJSON defaultOptions {fieldLabelModifier = fromMaybe "_ephemerisCommonContent_" . P.stripPrefix "_ephemerisCommonContent_"}
             ''EphemerisCommonContent)
$(makeLenses ''EphemerisCommonContent)

data EphemerisCommonContentDepA = EphemerisCommonContentDepA
  { _ephemerisCommonContentDepA_sid        :: GnssSignal
    -- ^ GNSS signal identifier
  , _ephemerisCommonContentDepA_toe        :: GpsTime
    -- ^ Time of Ephemerides
  , _ephemerisCommonContentDepA_ura        :: Double
    -- ^ User Range Accuracy
  , _ephemerisCommonContentDepA_fit_interval :: Word32
    -- ^ Curve fit interval
  , _ephemerisCommonContentDepA_valid      :: Word8
    -- ^ Status of ephemeris, 1 = valid, 0 = invalid
  , _ephemerisCommonContentDepA_health_bits :: Word8
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
    return EphemerisCommonContentDepA {..}

  put EphemerisCommonContentDepA {..} = do
    put _ephemerisCommonContentDepA_sid
    put _ephemerisCommonContentDepA_toe
    putFloat64le _ephemerisCommonContentDepA_ura
    putWord32le _ephemerisCommonContentDepA_fit_interval
    putWord8 _ephemerisCommonContentDepA_valid
    putWord8 _ephemerisCommonContentDepA_health_bits
$(deriveJSON defaultOptions {fieldLabelModifier = fromMaybe "_ephemerisCommonContentDepA_" . P.stripPrefix "_ephemerisCommonContentDepA_"}
             ''EphemerisCommonContentDepA)
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
  { _msgEphemerisGpsDepE_common :: EphemerisCommonContentDepA
    -- ^ Values common for all ephemeris types
  , _msgEphemerisGpsDepE_tgd    :: Double
    -- ^ Group delay differential between L1 and L2
  , _msgEphemerisGpsDepE_c_rs   :: Double
    -- ^ Amplitude of the sine harmonic correction term to the orbit radius
  , _msgEphemerisGpsDepE_c_rc   :: Double
    -- ^ Amplitude of the cosine harmonic correction term to the orbit radius
  , _msgEphemerisGpsDepE_c_uc   :: Double
    -- ^ Amplitude of the cosine harmonic correction term to the argument of
    -- latitude
  , _msgEphemerisGpsDepE_c_us   :: Double
    -- ^ Amplitude of the sine harmonic correction term to the argument of
    -- latitude
  , _msgEphemerisGpsDepE_c_ic   :: Double
    -- ^ Amplitude of the cosine harmonic correction term to the angle of
    -- inclination
  , _msgEphemerisGpsDepE_c_is   :: Double
    -- ^ Amplitude of the sine harmonic correction term to the angle of
    -- inclination
  , _msgEphemerisGpsDepE_dn     :: Double
    -- ^ Mean motion difference
  , _msgEphemerisGpsDepE_m0     :: Double
    -- ^ Mean anomaly at reference time
  , _msgEphemerisGpsDepE_ecc    :: Double
    -- ^ Eccentricity of satellite orbit
  , _msgEphemerisGpsDepE_sqrta  :: Double
    -- ^ Square root of the semi-major axis of orbit
  , _msgEphemerisGpsDepE_omega0 :: Double
    -- ^ Longitude of ascending node of orbit plane at weekly epoch
  , _msgEphemerisGpsDepE_omegadot :: Double
    -- ^ Rate of right ascension
  , _msgEphemerisGpsDepE_w      :: Double
    -- ^ Argument of perigee
  , _msgEphemerisGpsDepE_inc    :: Double
    -- ^ Inclination
  , _msgEphemerisGpsDepE_inc_dot :: Double
    -- ^ Inclination first derivative
  , _msgEphemerisGpsDepE_af0    :: Double
    -- ^ Polynomial clock correction coefficient (clock bias)
  , _msgEphemerisGpsDepE_af1    :: Double
    -- ^ Polynomial clock correction coefficient (clock drift)
  , _msgEphemerisGpsDepE_af2    :: Double
    -- ^ Polynomial clock correction coefficient (rate of clock drift)
  , _msgEphemerisGpsDepE_toc    :: GpsTime
    -- ^ Clock reference
  , _msgEphemerisGpsDepE_iode   :: Word8
    -- ^ Issue of ephemeris data
  , _msgEphemerisGpsDepE_iodc   :: Word16
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
    return MsgEphemerisGpsDepE {..}

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

$(deriveSBP 'msgEphemerisGpsDepE ''MsgEphemerisGpsDepE)

$(deriveJSON defaultOptions {fieldLabelModifier = fromMaybe "_msgEphemerisGpsDepE_" . P.stripPrefix "_msgEphemerisGpsDepE_"}
             ''MsgEphemerisGpsDepE)
$(makeLenses ''MsgEphemerisGpsDepE)

msgEphemerisGps :: Word16
msgEphemerisGps = 0x0086

-- | SBP class for message MSG_EPHEMERIS_GPS (0x0086).
--
-- The ephemeris message returns a set of satellite orbit parameters that is
-- used to calculate GPS satellite position, velocity, and clock offset. Please
-- see the Navstar GPS Space Segment/Navigation user interfaces (ICD-GPS-200,
-- Table 20-III) for more details.
data MsgEphemerisGps = MsgEphemerisGps
  { _msgEphemerisGps_common :: EphemerisCommonContent
    -- ^ Values common for all ephemeris types
  , _msgEphemerisGps_tgd    :: Double
    -- ^ Group delay differential between L1 and L2
  , _msgEphemerisGps_c_rs   :: Double
    -- ^ Amplitude of the sine harmonic correction term to the orbit radius
  , _msgEphemerisGps_c_rc   :: Double
    -- ^ Amplitude of the cosine harmonic correction term to the orbit radius
  , _msgEphemerisGps_c_uc   :: Double
    -- ^ Amplitude of the cosine harmonic correction term to the argument of
    -- latitude
  , _msgEphemerisGps_c_us   :: Double
    -- ^ Amplitude of the sine harmonic correction term to the argument of
    -- latitude
  , _msgEphemerisGps_c_ic   :: Double
    -- ^ Amplitude of the cosine harmonic correction term to the angle of
    -- inclination
  , _msgEphemerisGps_c_is   :: Double
    -- ^ Amplitude of the sine harmonic correction term to the angle of
    -- inclination
  , _msgEphemerisGps_dn     :: Double
    -- ^ Mean motion difference
  , _msgEphemerisGps_m0     :: Double
    -- ^ Mean anomaly at reference time
  , _msgEphemerisGps_ecc    :: Double
    -- ^ Eccentricity of satellite orbit
  , _msgEphemerisGps_sqrta  :: Double
    -- ^ Square root of the semi-major axis of orbit
  , _msgEphemerisGps_omega0 :: Double
    -- ^ Longitude of ascending node of orbit plane at weekly epoch
  , _msgEphemerisGps_omegadot :: Double
    -- ^ Rate of right ascension
  , _msgEphemerisGps_w      :: Double
    -- ^ Argument of perigee
  , _msgEphemerisGps_inc    :: Double
    -- ^ Inclination
  , _msgEphemerisGps_inc_dot :: Double
    -- ^ Inclination first derivative
  , _msgEphemerisGps_af0    :: Double
    -- ^ Polynomial clock correction coefficient (clock bias)
  , _msgEphemerisGps_af1    :: Double
    -- ^ Polynomial clock correction coefficient (clock drift)
  , _msgEphemerisGps_af2    :: Double
    -- ^ Polynomial clock correction coefficient (rate of clock drift)
  , _msgEphemerisGps_toc    :: GpsTimeSec
    -- ^ Clock reference
  , _msgEphemerisGps_iode   :: Word8
    -- ^ Issue of ephemeris data
  , _msgEphemerisGps_iodc   :: Word16
    -- ^ Issue of clock data
  } deriving ( Show, Read, Eq )

instance Binary MsgEphemerisGps where
  get = do
    _msgEphemerisGps_common <- get
    _msgEphemerisGps_tgd <- getFloat64le
    _msgEphemerisGps_c_rs <- getFloat64le
    _msgEphemerisGps_c_rc <- getFloat64le
    _msgEphemerisGps_c_uc <- getFloat64le
    _msgEphemerisGps_c_us <- getFloat64le
    _msgEphemerisGps_c_ic <- getFloat64le
    _msgEphemerisGps_c_is <- getFloat64le
    _msgEphemerisGps_dn <- getFloat64le
    _msgEphemerisGps_m0 <- getFloat64le
    _msgEphemerisGps_ecc <- getFloat64le
    _msgEphemerisGps_sqrta <- getFloat64le
    _msgEphemerisGps_omega0 <- getFloat64le
    _msgEphemerisGps_omegadot <- getFloat64le
    _msgEphemerisGps_w <- getFloat64le
    _msgEphemerisGps_inc <- getFloat64le
    _msgEphemerisGps_inc_dot <- getFloat64le
    _msgEphemerisGps_af0 <- getFloat64le
    _msgEphemerisGps_af1 <- getFloat64le
    _msgEphemerisGps_af2 <- getFloat64le
    _msgEphemerisGps_toc <- get
    _msgEphemerisGps_iode <- getWord8
    _msgEphemerisGps_iodc <- getWord16le
    return MsgEphemerisGps {..}

  put MsgEphemerisGps {..} = do
    put _msgEphemerisGps_common
    putFloat64le _msgEphemerisGps_tgd
    putFloat64le _msgEphemerisGps_c_rs
    putFloat64le _msgEphemerisGps_c_rc
    putFloat64le _msgEphemerisGps_c_uc
    putFloat64le _msgEphemerisGps_c_us
    putFloat64le _msgEphemerisGps_c_ic
    putFloat64le _msgEphemerisGps_c_is
    putFloat64le _msgEphemerisGps_dn
    putFloat64le _msgEphemerisGps_m0
    putFloat64le _msgEphemerisGps_ecc
    putFloat64le _msgEphemerisGps_sqrta
    putFloat64le _msgEphemerisGps_omega0
    putFloat64le _msgEphemerisGps_omegadot
    putFloat64le _msgEphemerisGps_w
    putFloat64le _msgEphemerisGps_inc
    putFloat64le _msgEphemerisGps_inc_dot
    putFloat64le _msgEphemerisGps_af0
    putFloat64le _msgEphemerisGps_af1
    putFloat64le _msgEphemerisGps_af2
    put _msgEphemerisGps_toc
    putWord8 _msgEphemerisGps_iode
    putWord16le _msgEphemerisGps_iodc

$(deriveSBP 'msgEphemerisGps ''MsgEphemerisGps)

$(deriveJSON defaultOptions {fieldLabelModifier = fromMaybe "_msgEphemerisGps_" . P.stripPrefix "_msgEphemerisGps_"}
             ''MsgEphemerisGps)
$(makeLenses ''MsgEphemerisGps)

msgEphemerisSbasDepA :: Word16
msgEphemerisSbasDepA = 0x0082

data MsgEphemerisSbasDepA = MsgEphemerisSbasDepA
  { _msgEphemerisSbasDepA_common :: EphemerisCommonContentDepA
    -- ^ Values common for all ephemeris types
  , _msgEphemerisSbasDepA_pos  :: [Double]
    -- ^ Position of the GEO at time toe
  , _msgEphemerisSbasDepA_vel  :: [Double]
    -- ^ Velocity of the GEO at time toe
  , _msgEphemerisSbasDepA_acc  :: [Double]
    -- ^ Acceleration of the GEO at time toe
  , _msgEphemerisSbasDepA_a_gf0 :: Double
    -- ^ Time offset of the GEO clock w.r.t. SBAS Network Time
  , _msgEphemerisSbasDepA_a_gf1 :: Double
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
    return MsgEphemerisSbasDepA {..}

  put MsgEphemerisSbasDepA {..} = do
    put _msgEphemerisSbasDepA_common
    mapM_ putFloat64le _msgEphemerisSbasDepA_pos
    mapM_ putFloat64le _msgEphemerisSbasDepA_vel
    mapM_ putFloat64le _msgEphemerisSbasDepA_acc
    putFloat64le _msgEphemerisSbasDepA_a_gf0
    putFloat64le _msgEphemerisSbasDepA_a_gf1

$(deriveSBP 'msgEphemerisSbasDepA ''MsgEphemerisSbasDepA)

$(deriveJSON defaultOptions {fieldLabelModifier = fromMaybe "_msgEphemerisSbasDepA_" . P.stripPrefix "_msgEphemerisSbasDepA_"}
             ''MsgEphemerisSbasDepA)
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
  { _msgEphemerisGloDepA_common :: EphemerisCommonContentDepA
    -- ^ Values common for all ephemeris types
  , _msgEphemerisGloDepA_gamma :: Double
    -- ^ Relative deviation of predicted carrier frequency from nominal
  , _msgEphemerisGloDepA_tau  :: Double
    -- ^ Correction to the SV time
  , _msgEphemerisGloDepA_pos  :: [Double]
    -- ^ Position of the SV at tb in PZ-90.02 coordinates system
  , _msgEphemerisGloDepA_vel  :: [Double]
    -- ^ Velocity vector of the SV at tb in PZ-90.02 coordinates system
  , _msgEphemerisGloDepA_acc  :: [Double]
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
    return MsgEphemerisGloDepA {..}

  put MsgEphemerisGloDepA {..} = do
    put _msgEphemerisGloDepA_common
    putFloat64le _msgEphemerisGloDepA_gamma
    putFloat64le _msgEphemerisGloDepA_tau
    mapM_ putFloat64le _msgEphemerisGloDepA_pos
    mapM_ putFloat64le _msgEphemerisGloDepA_vel
    mapM_ putFloat64le _msgEphemerisGloDepA_acc

$(deriveSBP 'msgEphemerisGloDepA ''MsgEphemerisGloDepA)

$(deriveJSON defaultOptions {fieldLabelModifier = fromMaybe "_msgEphemerisGloDepA_" . P.stripPrefix "_msgEphemerisGloDepA_"}
             ''MsgEphemerisGloDepA)
$(makeLenses ''MsgEphemerisGloDepA)

msgEphemerisSbas :: Word16
msgEphemerisSbas = 0x0084

data MsgEphemerisSbas = MsgEphemerisSbas
  { _msgEphemerisSbas_common :: EphemerisCommonContent
    -- ^ Values common for all ephemeris types
  , _msgEphemerisSbas_pos  :: [Double]
    -- ^ Position of the GEO at time toe
  , _msgEphemerisSbas_vel  :: [Double]
    -- ^ Velocity of the GEO at time toe
  , _msgEphemerisSbas_acc  :: [Double]
    -- ^ Acceleration of the GEO at time toe
  , _msgEphemerisSbas_a_gf0 :: Double
    -- ^ Time offset of the GEO clock w.r.t. SBAS Network Time
  , _msgEphemerisSbas_a_gf1 :: Double
    -- ^ Drift of the GEO clock w.r.t. SBAS Network Time
  } deriving ( Show, Read, Eq )

instance Binary MsgEphemerisSbas where
  get = do
    _msgEphemerisSbas_common <- get
    _msgEphemerisSbas_pos <- replicateM 3 getFloat64le
    _msgEphemerisSbas_vel <- replicateM 3 getFloat64le
    _msgEphemerisSbas_acc <- replicateM 3 getFloat64le
    _msgEphemerisSbas_a_gf0 <- getFloat64le
    _msgEphemerisSbas_a_gf1 <- getFloat64le
    return MsgEphemerisSbas {..}

  put MsgEphemerisSbas {..} = do
    put _msgEphemerisSbas_common
    mapM_ putFloat64le _msgEphemerisSbas_pos
    mapM_ putFloat64le _msgEphemerisSbas_vel
    mapM_ putFloat64le _msgEphemerisSbas_acc
    putFloat64le _msgEphemerisSbas_a_gf0
    putFloat64le _msgEphemerisSbas_a_gf1

$(deriveSBP 'msgEphemerisSbas ''MsgEphemerisSbas)

$(deriveJSON defaultOptions {fieldLabelModifier = fromMaybe "_msgEphemerisSbas_" . P.stripPrefix "_msgEphemerisSbas_"}
             ''MsgEphemerisSbas)
$(makeLenses ''MsgEphemerisSbas)

msgEphemerisGlo :: Word16
msgEphemerisGlo = 0x0085

-- | SBP class for message MSG_EPHEMERIS_GLO (0x0085).
--
-- The ephemeris message returns a set of satellite orbit parameters that is
-- used to calculate GLO satellite position, velocity, and clock offset. Please
-- see the GLO ICD 5.1 "Table 4.5 Characteristics of words of immediate
-- information (ephemeris parameters)" for more details.
data MsgEphemerisGlo = MsgEphemerisGlo
  { _msgEphemerisGlo_common :: EphemerisCommonContent
    -- ^ Values common for all ephemeris types
  , _msgEphemerisGlo_gamma :: Double
    -- ^ Relative deviation of predicted carrier frequency from nominal
  , _msgEphemerisGlo_tau  :: Double
    -- ^ Correction to the SV time
  , _msgEphemerisGlo_pos  :: [Double]
    -- ^ Position of the SV at tb in PZ-90.02 coordinates system
  , _msgEphemerisGlo_vel  :: [Double]
    -- ^ Velocity vector of the SV at tb in PZ-90.02 coordinates system
  , _msgEphemerisGlo_acc  :: [Double]
    -- ^ Acceleration vector of the SV at tb in PZ-90.02 coordinates sys
  } deriving ( Show, Read, Eq )

instance Binary MsgEphemerisGlo where
  get = do
    _msgEphemerisGlo_common <- get
    _msgEphemerisGlo_gamma <- getFloat64le
    _msgEphemerisGlo_tau <- getFloat64le
    _msgEphemerisGlo_pos <- replicateM 3 getFloat64le
    _msgEphemerisGlo_vel <- replicateM 3 getFloat64le
    _msgEphemerisGlo_acc <- replicateM 3 getFloat64le
    return MsgEphemerisGlo {..}

  put MsgEphemerisGlo {..} = do
    put _msgEphemerisGlo_common
    putFloat64le _msgEphemerisGlo_gamma
    putFloat64le _msgEphemerisGlo_tau
    mapM_ putFloat64le _msgEphemerisGlo_pos
    mapM_ putFloat64le _msgEphemerisGlo_vel
    mapM_ putFloat64le _msgEphemerisGlo_acc

$(deriveSBP 'msgEphemerisGlo ''MsgEphemerisGlo)

$(deriveJSON defaultOptions {fieldLabelModifier = fromMaybe "_msgEphemerisGlo_" . P.stripPrefix "_msgEphemerisGlo_"}
             ''MsgEphemerisGlo)
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
  { _msgEphemerisDepD_tgd    :: Double
    -- ^ Group delay differential between L1 and L2
  , _msgEphemerisDepD_c_rs   :: Double
    -- ^ Amplitude of the sine harmonic correction term to the orbit radius
  , _msgEphemerisDepD_c_rc   :: Double
    -- ^ Amplitude of the cosine harmonic correction term to the orbit radius
  , _msgEphemerisDepD_c_uc   :: Double
    -- ^ Amplitude of the cosine harmonic correction term to the argument of
    -- latitude
  , _msgEphemerisDepD_c_us   :: Double
    -- ^ Amplitude of the sine harmonic correction term to the argument of
    -- latitude
  , _msgEphemerisDepD_c_ic   :: Double
    -- ^ Amplitude of the cosine harmonic correction term to the angle of
    -- inclination
  , _msgEphemerisDepD_c_is   :: Double
    -- ^ Amplitude of the sine harmonic correction term to the angle of
    -- inclination
  , _msgEphemerisDepD_dn     :: Double
    -- ^ Mean motion difference
  , _msgEphemerisDepD_m0     :: Double
    -- ^ Mean anomaly at reference time
  , _msgEphemerisDepD_ecc    :: Double
    -- ^ Eccentricity of satellite orbit
  , _msgEphemerisDepD_sqrta  :: Double
    -- ^ Square root of the semi-major axis of orbit
  , _msgEphemerisDepD_omega0 :: Double
    -- ^ Longitude of ascending node of orbit plane at weekly epoch
  , _msgEphemerisDepD_omegadot :: Double
    -- ^ Rate of right ascension
  , _msgEphemerisDepD_w      :: Double
    -- ^ Argument of perigee
  , _msgEphemerisDepD_inc    :: Double
    -- ^ Inclination
  , _msgEphemerisDepD_inc_dot :: Double
    -- ^ Inclination first derivative
  , _msgEphemerisDepD_af0    :: Double
    -- ^ Polynomial clock correction coefficient (clock bias)
  , _msgEphemerisDepD_af1    :: Double
    -- ^ Polynomial clock correction coefficient (clock drift)
  , _msgEphemerisDepD_af2    :: Double
    -- ^ Polynomial clock correction coefficient (rate of clock drift)
  , _msgEphemerisDepD_toe_tow :: Double
    -- ^ Time of week
  , _msgEphemerisDepD_toe_wn :: Word16
    -- ^ Week number
  , _msgEphemerisDepD_toc_tow :: Double
    -- ^ Clock reference time of week
  , _msgEphemerisDepD_toc_wn :: Word16
    -- ^ Clock reference week number
  , _msgEphemerisDepD_valid  :: Word8
    -- ^ Is valid?
  , _msgEphemerisDepD_healthy :: Word8
    -- ^ Satellite is healthy?
  , _msgEphemerisDepD_sid    :: GnssSignal
    -- ^ GNSS signal identifier
  , _msgEphemerisDepD_iode   :: Word8
    -- ^ Issue of ephemeris data
  , _msgEphemerisDepD_iodc   :: Word16
    -- ^ Issue of clock data
  , _msgEphemerisDepD_reserved :: Word32
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
    return MsgEphemerisDepD {..}

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

$(deriveSBP 'msgEphemerisDepD ''MsgEphemerisDepD)

$(deriveJSON defaultOptions {fieldLabelModifier = fromMaybe "_msgEphemerisDepD_" . P.stripPrefix "_msgEphemerisDepD_"}
             ''MsgEphemerisDepD)
$(makeLenses ''MsgEphemerisDepD)

msgEphemerisDepA :: Word16
msgEphemerisDepA = 0x001A

-- | SBP class for message MSG_EPHEMERIS_DEP_A (0x001A).
--
-- Deprecated.
data MsgEphemerisDepA = MsgEphemerisDepA
  { _msgEphemerisDepA_tgd    :: Double
    -- ^ Group delay differential between L1 and L2
  , _msgEphemerisDepA_c_rs   :: Double
    -- ^ Amplitude of the sine harmonic correction term to the orbit radius
  , _msgEphemerisDepA_c_rc   :: Double
    -- ^ Amplitude of the cosine harmonic correction term to the orbit radius
  , _msgEphemerisDepA_c_uc   :: Double
    -- ^ Amplitude of the cosine harmonic correction term to the argument of
    -- latitude
  , _msgEphemerisDepA_c_us   :: Double
    -- ^ Amplitude of the sine harmonic correction term to the argument of
    -- latitude
  , _msgEphemerisDepA_c_ic   :: Double
    -- ^ Amplitude of the cosine harmonic correction term to the angle of
    -- inclination
  , _msgEphemerisDepA_c_is   :: Double
    -- ^ Amplitude of the sine harmonic correction term to the angle of
    -- inclination
  , _msgEphemerisDepA_dn     :: Double
    -- ^ Mean motion difference
  , _msgEphemerisDepA_m0     :: Double
    -- ^ Mean anomaly at reference time
  , _msgEphemerisDepA_ecc    :: Double
    -- ^ Eccentricity of satellite orbit
  , _msgEphemerisDepA_sqrta  :: Double
    -- ^ Square root of the semi-major axis of orbit
  , _msgEphemerisDepA_omega0 :: Double
    -- ^ Longitude of ascending node of orbit plane at weekly epoch
  , _msgEphemerisDepA_omegadot :: Double
    -- ^ Rate of right ascension
  , _msgEphemerisDepA_w      :: Double
    -- ^ Argument of perigee
  , _msgEphemerisDepA_inc    :: Double
    -- ^ Inclination
  , _msgEphemerisDepA_inc_dot :: Double
    -- ^ Inclination first derivative
  , _msgEphemerisDepA_af0    :: Double
    -- ^ Polynomial clock correction coefficient (clock bias)
  , _msgEphemerisDepA_af1    :: Double
    -- ^ Polynomial clock correction coefficient (clock drift)
  , _msgEphemerisDepA_af2    :: Double
    -- ^ Polynomial clock correction coefficient (rate of clock drift)
  , _msgEphemerisDepA_toe_tow :: Double
    -- ^ Time of week
  , _msgEphemerisDepA_toe_wn :: Word16
    -- ^ Week number
  , _msgEphemerisDepA_toc_tow :: Double
    -- ^ Clock reference time of week
  , _msgEphemerisDepA_toc_wn :: Word16
    -- ^ Clock reference week number
  , _msgEphemerisDepA_valid  :: Word8
    -- ^ Is valid?
  , _msgEphemerisDepA_healthy :: Word8
    -- ^ Satellite is healthy?
  , _msgEphemerisDepA_prn    :: Word8
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
    return MsgEphemerisDepA {..}

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

$(deriveSBP 'msgEphemerisDepA ''MsgEphemerisDepA)

$(deriveJSON defaultOptions {fieldLabelModifier = fromMaybe "_msgEphemerisDepA_" . P.stripPrefix "_msgEphemerisDepA_"}
             ''MsgEphemerisDepA)
$(makeLenses ''MsgEphemerisDepA)

msgEphemerisDepB :: Word16
msgEphemerisDepB = 0x0046

-- | SBP class for message MSG_EPHEMERIS_DEP_B (0x0046).
--
-- Deprecated.
data MsgEphemerisDepB = MsgEphemerisDepB
  { _msgEphemerisDepB_tgd    :: Double
    -- ^ Group delay differential between L1 and L2
  , _msgEphemerisDepB_c_rs   :: Double
    -- ^ Amplitude of the sine harmonic correction term to the orbit radius
  , _msgEphemerisDepB_c_rc   :: Double
    -- ^ Amplitude of the cosine harmonic correction term to the orbit radius
  , _msgEphemerisDepB_c_uc   :: Double
    -- ^ Amplitude of the cosine harmonic correction term to the argument of
    -- latitude
  , _msgEphemerisDepB_c_us   :: Double
    -- ^ Amplitude of the sine harmonic correction term to the argument of
    -- latitude
  , _msgEphemerisDepB_c_ic   :: Double
    -- ^ Amplitude of the cosine harmonic correction term to the angle of
    -- inclination
  , _msgEphemerisDepB_c_is   :: Double
    -- ^ Amplitude of the sine harmonic correction term to the angle of
    -- inclination
  , _msgEphemerisDepB_dn     :: Double
    -- ^ Mean motion difference
  , _msgEphemerisDepB_m0     :: Double
    -- ^ Mean anomaly at reference time
  , _msgEphemerisDepB_ecc    :: Double
    -- ^ Eccentricity of satellite orbit
  , _msgEphemerisDepB_sqrta  :: Double
    -- ^ Square root of the semi-major axis of orbit
  , _msgEphemerisDepB_omega0 :: Double
    -- ^ Longitude of ascending node of orbit plane at weekly epoch
  , _msgEphemerisDepB_omegadot :: Double
    -- ^ Rate of right ascension
  , _msgEphemerisDepB_w      :: Double
    -- ^ Argument of perigee
  , _msgEphemerisDepB_inc    :: Double
    -- ^ Inclination
  , _msgEphemerisDepB_inc_dot :: Double
    -- ^ Inclination first derivative
  , _msgEphemerisDepB_af0    :: Double
    -- ^ Polynomial clock correction coefficient (clock bias)
  , _msgEphemerisDepB_af1    :: Double
    -- ^ Polynomial clock correction coefficient (clock drift)
  , _msgEphemerisDepB_af2    :: Double
    -- ^ Polynomial clock correction coefficient (rate of clock drift)
  , _msgEphemerisDepB_toe_tow :: Double
    -- ^ Time of week
  , _msgEphemerisDepB_toe_wn :: Word16
    -- ^ Week number
  , _msgEphemerisDepB_toc_tow :: Double
    -- ^ Clock reference time of week
  , _msgEphemerisDepB_toc_wn :: Word16
    -- ^ Clock reference week number
  , _msgEphemerisDepB_valid  :: Word8
    -- ^ Is valid?
  , _msgEphemerisDepB_healthy :: Word8
    -- ^ Satellite is healthy?
  , _msgEphemerisDepB_prn    :: Word8
    -- ^ PRN being tracked
  , _msgEphemerisDepB_iode   :: Word8
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
    return MsgEphemerisDepB {..}

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

$(deriveSBP 'msgEphemerisDepB ''MsgEphemerisDepB)

$(deriveJSON defaultOptions {fieldLabelModifier = fromMaybe "_msgEphemerisDepB_" . P.stripPrefix "_msgEphemerisDepB_"}
             ''MsgEphemerisDepB)
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
  { _msgEphemerisDepC_tgd    :: Double
    -- ^ Group delay differential between L1 and L2
  , _msgEphemerisDepC_c_rs   :: Double
    -- ^ Amplitude of the sine harmonic correction term to the orbit radius
  , _msgEphemerisDepC_c_rc   :: Double
    -- ^ Amplitude of the cosine harmonic correction term to the orbit radius
  , _msgEphemerisDepC_c_uc   :: Double
    -- ^ Amplitude of the cosine harmonic correction term to the argument of
    -- latitude
  , _msgEphemerisDepC_c_us   :: Double
    -- ^ Amplitude of the sine harmonic correction term to the argument of
    -- latitude
  , _msgEphemerisDepC_c_ic   :: Double
    -- ^ Amplitude of the cosine harmonic correction term to the angle of
    -- inclination
  , _msgEphemerisDepC_c_is   :: Double
    -- ^ Amplitude of the sine harmonic correction term to the angle of
    -- inclination
  , _msgEphemerisDepC_dn     :: Double
    -- ^ Mean motion difference
  , _msgEphemerisDepC_m0     :: Double
    -- ^ Mean anomaly at reference time
  , _msgEphemerisDepC_ecc    :: Double
    -- ^ Eccentricity of satellite orbit
  , _msgEphemerisDepC_sqrta  :: Double
    -- ^ Square root of the semi-major axis of orbit
  , _msgEphemerisDepC_omega0 :: Double
    -- ^ Longitude of ascending node of orbit plane at weekly epoch
  , _msgEphemerisDepC_omegadot :: Double
    -- ^ Rate of right ascension
  , _msgEphemerisDepC_w      :: Double
    -- ^ Argument of perigee
  , _msgEphemerisDepC_inc    :: Double
    -- ^ Inclination
  , _msgEphemerisDepC_inc_dot :: Double
    -- ^ Inclination first derivative
  , _msgEphemerisDepC_af0    :: Double
    -- ^ Polynomial clock correction coefficient (clock bias)
  , _msgEphemerisDepC_af1    :: Double
    -- ^ Polynomial clock correction coefficient (clock drift)
  , _msgEphemerisDepC_af2    :: Double
    -- ^ Polynomial clock correction coefficient (rate of clock drift)
  , _msgEphemerisDepC_toe_tow :: Double
    -- ^ Time of week
  , _msgEphemerisDepC_toe_wn :: Word16
    -- ^ Week number
  , _msgEphemerisDepC_toc_tow :: Double
    -- ^ Clock reference time of week
  , _msgEphemerisDepC_toc_wn :: Word16
    -- ^ Clock reference week number
  , _msgEphemerisDepC_valid  :: Word8
    -- ^ Is valid?
  , _msgEphemerisDepC_healthy :: Word8
    -- ^ Satellite is healthy?
  , _msgEphemerisDepC_sid    :: GnssSignal
    -- ^ GNSS signal identifier
  , _msgEphemerisDepC_iode   :: Word8
    -- ^ Issue of ephemeris data
  , _msgEphemerisDepC_iodc   :: Word16
    -- ^ Issue of clock data
  , _msgEphemerisDepC_reserved :: Word32
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
    return MsgEphemerisDepC {..}

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

$(deriveSBP 'msgEphemerisDepC ''MsgEphemerisDepC)

$(deriveJSON defaultOptions {fieldLabelModifier = fromMaybe "_msgEphemerisDepC_" . P.stripPrefix "_msgEphemerisDepC_"}
             ''MsgEphemerisDepC)
$(makeLenses ''MsgEphemerisDepC)

-- | ObservationHeaderDep.
--
-- Header of a GPS observation message.
data ObservationHeaderDep = ObservationHeaderDep
  { _observationHeaderDep_t   :: GpsTime
    -- ^ GPS time of this observation
  , _observationHeaderDep_n_obs :: Word8
    -- ^ Total number of observations. First nibble is the size of the sequence
    -- (n), second nibble is the zero-indexed counter (ith packet of n)
  } deriving ( Show, Read, Eq )

instance Binary ObservationHeaderDep where
  get = do
    _observationHeaderDep_t <- get
    _observationHeaderDep_n_obs <- getWord8
    return ObservationHeaderDep {..}

  put ObservationHeaderDep {..} = do
    put _observationHeaderDep_t
    putWord8 _observationHeaderDep_n_obs
$(deriveJSON defaultOptions {fieldLabelModifier = fromMaybe "_observationHeaderDep_" . P.stripPrefix "_observationHeaderDep_"}
             ''ObservationHeaderDep)
$(makeLenses ''ObservationHeaderDep)

-- | CarrierPhaseDepA.
--
-- Carrier phase measurement in cycles represented as a 40-bit fixed point
-- number with Q32.8 layout, i.e. 32-bits of whole cycles and 8-bits of
-- fractional cycles. This has the opposite sign convention than a typical GPS
-- receiver and the phase has the opposite sign as the pseudorange.
data CarrierPhaseDepA = CarrierPhaseDepA
  { _carrierPhaseDepA_i :: Int32
    -- ^ Carrier phase whole cycles
  , _carrierPhaseDepA_f :: Word8
    -- ^ Carrier phase fractional part
  } deriving ( Show, Read, Eq )

instance Binary CarrierPhaseDepA where
  get = do
    _carrierPhaseDepA_i <- fromIntegral <$> getWord32le
    _carrierPhaseDepA_f <- getWord8
    return CarrierPhaseDepA {..}

  put CarrierPhaseDepA {..} = do
    putWord32le $ fromIntegral _carrierPhaseDepA_i
    putWord8 _carrierPhaseDepA_f
$(deriveJSON defaultOptions {fieldLabelModifier = fromMaybe "_carrierPhaseDepA_" . P.stripPrefix "_carrierPhaseDepA_"}
             ''CarrierPhaseDepA)
$(makeLenses ''CarrierPhaseDepA)

-- | PackedObsContentDepA.
--
-- Deprecated.
data PackedObsContentDepA = PackedObsContentDepA
  { _packedObsContentDepA_P  :: Word32
    -- ^ Pseudorange observation
  , _packedObsContentDepA_L  :: CarrierPhaseDepA
    -- ^ Carrier phase observation with opposite sign from typical convention
  , _packedObsContentDepA_cn0 :: Word8
    -- ^ Carrier-to-Noise density
  , _packedObsContentDepA_lock :: Word16
    -- ^ Lock indicator. This value changes whenever a satellite signal has lost
    -- and regained lock, indicating that the carrier phase ambiguity may have
    -- changed.
  , _packedObsContentDepA_prn :: Word8
    -- ^ PRN-1 identifier of the satellite signal
  } deriving ( Show, Read, Eq )

instance Binary PackedObsContentDepA where
  get = do
    _packedObsContentDepA_P <- getWord32le
    _packedObsContentDepA_L <- get
    _packedObsContentDepA_cn0 <- getWord8
    _packedObsContentDepA_lock <- getWord16le
    _packedObsContentDepA_prn <- getWord8
    return PackedObsContentDepA {..}

  put PackedObsContentDepA {..} = do
    putWord32le _packedObsContentDepA_P
    put _packedObsContentDepA_L
    putWord8 _packedObsContentDepA_cn0
    putWord16le _packedObsContentDepA_lock
    putWord8 _packedObsContentDepA_prn
$(deriveJSON defaultOptions {fieldLabelModifier = fromMaybe "_packedObsContentDepA_" . P.stripPrefix "_packedObsContentDepA_"}
             ''PackedObsContentDepA)
$(makeLenses ''PackedObsContentDepA)

-- | PackedObsContentDepB.
--
-- Pseudorange and carrier phase observation for a satellite being tracked.
-- Pseudoranges are referenced to a nominal pseudorange.
data PackedObsContentDepB = PackedObsContentDepB
  { _packedObsContentDepB_P  :: Word32
    -- ^ Pseudorange observation
  , _packedObsContentDepB_L  :: CarrierPhaseDepA
    -- ^ Carrier phase observation with opposite sign from typical convention.
  , _packedObsContentDepB_cn0 :: Word8
    -- ^ Carrier-to-Noise density
  , _packedObsContentDepB_lock :: Word16
    -- ^ Lock indicator. This value changes whenever a satellite signal has lost
    -- and regained lock, indicating that the carrier phase ambiguity may have
    -- changed.
  , _packedObsContentDepB_sid :: GnssSignal
    -- ^ GNSS signal identifier
  } deriving ( Show, Read, Eq )

instance Binary PackedObsContentDepB where
  get = do
    _packedObsContentDepB_P <- getWord32le
    _packedObsContentDepB_L <- get
    _packedObsContentDepB_cn0 <- getWord8
    _packedObsContentDepB_lock <- getWord16le
    _packedObsContentDepB_sid <- get
    return PackedObsContentDepB {..}

  put PackedObsContentDepB {..} = do
    putWord32le _packedObsContentDepB_P
    put _packedObsContentDepB_L
    putWord8 _packedObsContentDepB_cn0
    putWord16le _packedObsContentDepB_lock
    put _packedObsContentDepB_sid
$(deriveJSON defaultOptions {fieldLabelModifier = fromMaybe "_packedObsContentDepB_" . P.stripPrefix "_packedObsContentDepB_"}
             ''PackedObsContentDepB)
$(makeLenses ''PackedObsContentDepB)

-- | PackedObsContentDepC.
--
-- Pseudorange and carrier phase observation for a satellite being tracked. The
-- observations are be interoperable with 3rd party receivers and conform with
-- typical RTCMv3 GNSS observations.
data PackedObsContentDepC = PackedObsContentDepC
  { _packedObsContentDepC_P  :: Word32
    -- ^ Pseudorange observation
  , _packedObsContentDepC_L  :: CarrierPhase
    -- ^ Carrier phase observation with typical sign convention.
  , _packedObsContentDepC_cn0 :: Word8
    -- ^ Carrier-to-Noise density
  , _packedObsContentDepC_lock :: Word16
    -- ^ Lock indicator. This value changes whenever a satellite signal has lost
    -- and regained lock, indicating that the carrier phase ambiguity may have
    -- changed.
  , _packedObsContentDepC_sid :: GnssSignal
    -- ^ GNSS signal identifier
  } deriving ( Show, Read, Eq )

instance Binary PackedObsContentDepC where
  get = do
    _packedObsContentDepC_P <- getWord32le
    _packedObsContentDepC_L <- get
    _packedObsContentDepC_cn0 <- getWord8
    _packedObsContentDepC_lock <- getWord16le
    _packedObsContentDepC_sid <- get
    return PackedObsContentDepC {..}

  put PackedObsContentDepC {..} = do
    putWord32le _packedObsContentDepC_P
    put _packedObsContentDepC_L
    putWord8 _packedObsContentDepC_cn0
    putWord16le _packedObsContentDepC_lock
    put _packedObsContentDepC_sid
$(deriveJSON defaultOptions {fieldLabelModifier = fromMaybe "_packedObsContentDepC_" . P.stripPrefix "_packedObsContentDepC_"}
             ''PackedObsContentDepC)
$(makeLenses ''PackedObsContentDepC)

msgObsDepA :: Word16
msgObsDepA = 0x0045

-- | SBP class for message MSG_OBS_DEP_A (0x0045).
--
-- Deprecated.
data MsgObsDepA = MsgObsDepA
  { _msgObsDepA_header :: ObservationHeaderDep
    -- ^ Header of a GPS observation message
  , _msgObsDepA_obs  :: [PackedObsContentDepA]
    -- ^ Pseudorange and carrier phase observation for a satellite being tracked.
  } deriving ( Show, Read, Eq )

instance Binary MsgObsDepA where
  get = do
    _msgObsDepA_header <- get
    _msgObsDepA_obs <- whileM (not <$> isEmpty) get
    return MsgObsDepA {..}

  put MsgObsDepA {..} = do
    put _msgObsDepA_header
    mapM_ put _msgObsDepA_obs

$(deriveSBP 'msgObsDepA ''MsgObsDepA)

$(deriveJSON defaultOptions {fieldLabelModifier = fromMaybe "_msgObsDepA_" . P.stripPrefix "_msgObsDepA_"}
             ''MsgObsDepA)
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
  { _msgObsDepB_header :: ObservationHeaderDep
    -- ^ Header of a GPS observation message
  , _msgObsDepB_obs  :: [PackedObsContentDepB]
    -- ^ Pseudorange and carrier phase observation for a satellite being tracked.
  } deriving ( Show, Read, Eq )

instance Binary MsgObsDepB where
  get = do
    _msgObsDepB_header <- get
    _msgObsDepB_obs <- whileM (not <$> isEmpty) get
    return MsgObsDepB {..}

  put MsgObsDepB {..} = do
    put _msgObsDepB_header
    mapM_ put _msgObsDepB_obs

$(deriveSBP 'msgObsDepB ''MsgObsDepB)

$(deriveJSON defaultOptions {fieldLabelModifier = fromMaybe "_msgObsDepB_" . P.stripPrefix "_msgObsDepB_"}
             ''MsgObsDepB)
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
  { _msgObsDepC_header :: ObservationHeaderDep
    -- ^ Header of a GPS observation message
  , _msgObsDepC_obs  :: [PackedObsContentDepC]
    -- ^ Pseudorange and carrier phase observation for a satellite being tracked.
  } deriving ( Show, Read, Eq )

instance Binary MsgObsDepC where
  get = do
    _msgObsDepC_header <- get
    _msgObsDepC_obs <- whileM (not <$> isEmpty) get
    return MsgObsDepC {..}

  put MsgObsDepC {..} = do
    put _msgObsDepC_header
    mapM_ put _msgObsDepC_obs

$(deriveSBP 'msgObsDepC ''MsgObsDepC)

$(deriveJSON defaultOptions {fieldLabelModifier = fromMaybe "_msgObsDepC_" . P.stripPrefix "_msgObsDepC_"}
             ''MsgObsDepC)
$(makeLenses ''MsgObsDepC)

msgIono :: Word16
msgIono = 0x0090

-- | SBP class for message MSG_IONO (0x0090).
--
-- The ionospheric parameters which allow the "L1 only" or "L2 only" user to
-- utilize the ionospheric model for computation of the ionospheric delay.
-- Please see ICD-GPS-200 (Chapter 20.3.3.5.1.7) for more details.
data MsgIono = MsgIono
  { _msgIono_t_nmct :: GpsTimeSec
    -- ^ Navigation Message Correction Table Valitidy Time
  , _msgIono_a0   :: Double
  , _msgIono_a1   :: Double
  , _msgIono_a2   :: Double
  , _msgIono_a3   :: Double
  , _msgIono_b0   :: Double
  , _msgIono_b1   :: Double
  , _msgIono_b2   :: Double
  , _msgIono_b3   :: Double
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
    return MsgIono {..}

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

$(deriveSBP 'msgIono ''MsgIono)

$(deriveJSON defaultOptions {fieldLabelModifier = fromMaybe "_msgIono_" . P.stripPrefix "_msgIono_"}
             ''MsgIono)
$(makeLenses ''MsgIono)

msgSvConfigurationGps :: Word16
msgSvConfigurationGps = 0x0091

-- | SBP class for message MSG_SV_CONFIGURATION_GPS (0x0091).
--
-- Please see ICD-GPS-200 (Chapter 20.3.3.5.1.4) for more details.
data MsgSvConfigurationGps = MsgSvConfigurationGps
  { _msgSvConfigurationGps_t_nmct :: GpsTimeSec
    -- ^ Navigation Message Correction Table Valitidy Time
  , _msgSvConfigurationGps_l2c_mask :: Word32
    -- ^ L2C capability mask, SV32 bit being MSB, SV1 bit being LSB
  } deriving ( Show, Read, Eq )

instance Binary MsgSvConfigurationGps where
  get = do
    _msgSvConfigurationGps_t_nmct <- get
    _msgSvConfigurationGps_l2c_mask <- getWord32le
    return MsgSvConfigurationGps {..}

  put MsgSvConfigurationGps {..} = do
    put _msgSvConfigurationGps_t_nmct
    putWord32le _msgSvConfigurationGps_l2c_mask

$(deriveSBP 'msgSvConfigurationGps ''MsgSvConfigurationGps)

$(deriveJSON defaultOptions {fieldLabelModifier = fromMaybe "_msgSvConfigurationGps_" . P.stripPrefix "_msgSvConfigurationGps_"}
             ''MsgSvConfigurationGps)
$(makeLenses ''MsgSvConfigurationGps)

msgGroupDelayDepA :: Word16
msgGroupDelayDepA = 0x0092

-- | SBP class for message MSG_GROUP_DELAY_DEP_A (0x0092).
--
-- Please see ICD-GPS-200 (30.3.3.3.1.1) for more details.
data MsgGroupDelayDepA = MsgGroupDelayDepA
  { _msgGroupDelayDepA_t_op   :: GpsTime
    -- ^ Data Predict Time of Week
  , _msgGroupDelayDepA_prn    :: Word8
    -- ^ Satellite number
  , _msgGroupDelayDepA_valid  :: Word8
    -- ^ bit-field indicating validity of the values, LSB indicating tgd validity
    -- etc. 1 = value is valid, 0 = value is not valid.
  , _msgGroupDelayDepA_tgd    :: Int16
  , _msgGroupDelayDepA_isc_l1ca :: Int16
  , _msgGroupDelayDepA_isc_l2c :: Int16
  } deriving ( Show, Read, Eq )

instance Binary MsgGroupDelayDepA where
  get = do
    _msgGroupDelayDepA_t_op <- get
    _msgGroupDelayDepA_prn <- getWord8
    _msgGroupDelayDepA_valid <- getWord8
    _msgGroupDelayDepA_tgd <- fromIntegral <$> getWord16le
    _msgGroupDelayDepA_isc_l1ca <- fromIntegral <$> getWord16le
    _msgGroupDelayDepA_isc_l2c <- fromIntegral <$> getWord16le
    return MsgGroupDelayDepA {..}

  put MsgGroupDelayDepA {..} = do
    put _msgGroupDelayDepA_t_op
    putWord8 _msgGroupDelayDepA_prn
    putWord8 _msgGroupDelayDepA_valid
    putWord16le $ fromIntegral _msgGroupDelayDepA_tgd
    putWord16le $ fromIntegral _msgGroupDelayDepA_isc_l1ca
    putWord16le $ fromIntegral _msgGroupDelayDepA_isc_l2c

$(deriveSBP 'msgGroupDelayDepA ''MsgGroupDelayDepA)

$(deriveJSON defaultOptions {fieldLabelModifier = fromMaybe "_msgGroupDelayDepA_" . P.stripPrefix "_msgGroupDelayDepA_"}
             ''MsgGroupDelayDepA)
$(makeLenses ''MsgGroupDelayDepA)

msgGroupDelay :: Word16
msgGroupDelay = 0x0093

-- | SBP class for message MSG_GROUP_DELAY (0x0093).
--
-- Please see ICD-GPS-200 (30.3.3.3.1.1) for more details.
data MsgGroupDelay = MsgGroupDelay
  { _msgGroupDelay_t_op   :: GpsTimeSec
    -- ^ Data Predict Time of Week
  , _msgGroupDelay_sid    :: GnssSignal
    -- ^ GNSS signal identifier
  , _msgGroupDelay_valid  :: Word8
    -- ^ bit-field indicating validity of the values, LSB indicating tgd validity
    -- etc. 1 = value is valid, 0 = value is not valid.
  , _msgGroupDelay_tgd    :: Int16
  , _msgGroupDelay_isc_l1ca :: Int16
  , _msgGroupDelay_isc_l2c :: Int16
  } deriving ( Show, Read, Eq )

instance Binary MsgGroupDelay where
  get = do
    _msgGroupDelay_t_op <- get
    _msgGroupDelay_sid <- get
    _msgGroupDelay_valid <- getWord8
    _msgGroupDelay_tgd <- fromIntegral <$> getWord16le
    _msgGroupDelay_isc_l1ca <- fromIntegral <$> getWord16le
    _msgGroupDelay_isc_l2c <- fromIntegral <$> getWord16le
    return MsgGroupDelay {..}

  put MsgGroupDelay {..} = do
    put _msgGroupDelay_t_op
    put _msgGroupDelay_sid
    putWord8 _msgGroupDelay_valid
    putWord16le $ fromIntegral _msgGroupDelay_tgd
    putWord16le $ fromIntegral _msgGroupDelay_isc_l1ca
    putWord16le $ fromIntegral _msgGroupDelay_isc_l2c

$(deriveSBP 'msgGroupDelay ''MsgGroupDelay)

$(deriveJSON defaultOptions {fieldLabelModifier = fromMaybe "_msgGroupDelay_" . P.stripPrefix "_msgGroupDelay_"}
             ''MsgGroupDelay)
$(makeLenses ''MsgGroupDelay)

data AlmanacCommonContent = AlmanacCommonContent
  { _almanacCommonContent_sid        :: GnssSignal
    -- ^ GNSS signal identifier
  , _almanacCommonContent_toa        :: GpsTimeSec
    -- ^ Reference time of almanac
  , _almanacCommonContent_ura        :: Double
    -- ^ User Range Accuracy
  , _almanacCommonContent_fit_interval :: Word32
    -- ^ Curve fit interval
  , _almanacCommonContent_valid      :: Word8
    -- ^ Status of almanac, 1 = valid, 0 = invalid
  , _almanacCommonContent_health_bits :: Word8
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
    return AlmanacCommonContent {..}

  put AlmanacCommonContent {..} = do
    put _almanacCommonContent_sid
    put _almanacCommonContent_toa
    putFloat64le _almanacCommonContent_ura
    putWord32le _almanacCommonContent_fit_interval
    putWord8 _almanacCommonContent_valid
    putWord8 _almanacCommonContent_health_bits
$(deriveJSON defaultOptions {fieldLabelModifier = fromMaybe "_almanacCommonContent_" . P.stripPrefix "_almanacCommonContent_"}
             ''AlmanacCommonContent)
$(makeLenses ''AlmanacCommonContent)

msgAlmanacGps :: Word16
msgAlmanacGps = 0x0070

-- | SBP class for message MSG_ALMANAC_GPS (0x0070).
--
-- The almanac message returns a set of satellite orbit parameters. Almanac
-- data is not very precise and is considered valid for up to several months.
-- Please see the Navstar GPS Space Segment/Navigation user interfaces (ICD-
-- GPS-200, Chapter 20.3.3.5.1.2 Almanac Data) for more details.
data MsgAlmanacGps = MsgAlmanacGps
  { _msgAlmanacGps_common :: AlmanacCommonContent
    -- ^ Values common for all almanac types
  , _msgAlmanacGps_m0     :: Double
    -- ^ Mean anomaly at reference time
  , _msgAlmanacGps_ecc    :: Double
    -- ^ Eccentricity of satellite orbit
  , _msgAlmanacGps_sqrta  :: Double
    -- ^ Square root of the semi-major axis of orbit
  , _msgAlmanacGps_omega0 :: Double
    -- ^ Longitude of ascending node of orbit plane at weekly epoch
  , _msgAlmanacGps_omegadot :: Double
    -- ^ Rate of right ascension
  , _msgAlmanacGps_w      :: Double
    -- ^ Argument of perigee
  , _msgAlmanacGps_inc    :: Double
    -- ^ Inclination
  , _msgAlmanacGps_af0    :: Double
    -- ^ Polynomial clock correction coefficient (clock bias)
  , _msgAlmanacGps_af1    :: Double
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
    return MsgAlmanacGps {..}

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

$(deriveSBP 'msgAlmanacGps ''MsgAlmanacGps)

$(deriveJSON defaultOptions {fieldLabelModifier = fromMaybe "_msgAlmanacGps_" . P.stripPrefix "_msgAlmanacGps_"}
             ''MsgAlmanacGps)
$(makeLenses ''MsgAlmanacGps)

msgAlmanacGlo :: Word16
msgAlmanacGlo = 0x0071

-- | SBP class for message MSG_ALMANAC_GLO (0x0071).
--
-- The almanac message returns a set of satellite orbit parameters. Almanac
-- data is not very precise and is considered valid for up to several months.
-- Please see the GLO ICD 5.1 "Chapter 4.5 Non-immediate information and
-- almanac" for details.
data MsgAlmanacGlo = MsgAlmanacGlo
  { _msgAlmanacGlo_common    :: AlmanacCommonContent
    -- ^ Values common for all almanac types
  , _msgAlmanacGlo_lambda_na :: Double
    -- ^ Longitude of the first ascending node of the orbit in PZ-90.02
    -- coordinate system
  , _msgAlmanacGlo_t_lambda_na :: Double
    -- ^ Time of the first ascending node passage
  , _msgAlmanacGlo_i         :: Double
    -- ^ Value of inclination at instant of t_lambda
  , _msgAlmanacGlo_t         :: Double
    -- ^ Value of Draconian period at instant of t_lambda
  , _msgAlmanacGlo_t_dot     :: Double
    -- ^ Rate of change of the Draconian period
  , _msgAlmanacGlo_epsilon   :: Double
    -- ^ Eccentricity at instant of t_lambda
  , _msgAlmanacGlo_omega     :: Double
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
    return MsgAlmanacGlo {..}

  put MsgAlmanacGlo {..} = do
    put _msgAlmanacGlo_common
    putFloat64le _msgAlmanacGlo_lambda_na
    putFloat64le _msgAlmanacGlo_t_lambda_na
    putFloat64le _msgAlmanacGlo_i
    putFloat64le _msgAlmanacGlo_t
    putFloat64le _msgAlmanacGlo_t_dot
    putFloat64le _msgAlmanacGlo_epsilon
    putFloat64le _msgAlmanacGlo_omega

$(deriveSBP 'msgAlmanacGlo ''MsgAlmanacGlo)

$(deriveJSON defaultOptions {fieldLabelModifier = fromMaybe "_msgAlmanacGlo_" . P.stripPrefix "_msgAlmanacGlo_"}
             ''MsgAlmanacGlo)
$(makeLenses ''MsgAlmanacGlo)

msgFcnsGlo :: Word16
msgFcnsGlo = 0x0072

-- | SBP class for message MSG_FCNS_GLO (0x0072).
--
-- The message reports mapping information regarding GLONASS SV orbital and
-- frequency slots. Mapped as follow: index (SV orbital slot)  fcns[index] 0
-- 0xFF 1                        FCN for SV orbital slot 1 ...
-- ... 28                       FCN for SV orbital slot 28 29
-- 0xFF 30                       0xFF 31                       0xFF
data MsgFcnsGlo = MsgFcnsGlo
  { _msgFcnsGlo_wn   :: Word16
    -- ^ GPS Week number
  , _msgFcnsGlo_tow_ms :: Word32
    -- ^ GPS Time of week
  , _msgFcnsGlo_fcns :: [Word8]
    -- ^ GLONASS fequency number per orbital slot
  } deriving ( Show, Read, Eq )

instance Binary MsgFcnsGlo where
  get = do
    _msgFcnsGlo_wn <- getWord16le
    _msgFcnsGlo_tow_ms <- getWord32le
    _msgFcnsGlo_fcns <- replicateM 32 getWord8
    return MsgFcnsGlo {..}

  put MsgFcnsGlo {..} = do
    putWord16le _msgFcnsGlo_wn
    putWord32le _msgFcnsGlo_tow_ms
    mapM_ putWord8 _msgFcnsGlo_fcns

$(deriveSBP 'msgFcnsGlo ''MsgFcnsGlo)

$(deriveJSON defaultOptions {fieldLabelModifier = fromMaybe "_msgFcnsGlo_" . P.stripPrefix "_msgFcnsGlo_"}
             ''MsgFcnsGlo)
$(makeLenses ''MsgFcnsGlo)
