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

import BasicPrelude
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

-- | ObsGPSTime.
--
-- A wire-appropriate GPS time, defined as the number of milliseconds since
-- beginning of the week on the Saturday/Sunday transition.
data ObsGPSTime = ObsGPSTime
  { obsGPSTime_tow :: Word32
    -- ^ Milliseconds since start of GPS week
  , obsGPSTime_wn :: Word16
    -- ^ GPS week number
  } deriving ( Show, Read, Eq )

instance Binary ObsGPSTime where
  get = do
    obsGPSTime_tow <- getWord32le
    obsGPSTime_wn <- getWord16le
    return ObsGPSTime {..}

  put ObsGPSTime {..} = do
    putWord32le obsGPSTime_tow
    putWord16le obsGPSTime_wn

$(deriveJSON defaultOptions {fieldLabelModifier = fromMaybe "obsGPSTime_" . stripPrefix "obsGPSTime_"}
             ''ObsGPSTime)

-- | CarrierPhase.
--
-- Carrier phase measurement in cycles represented as a 40-bit fixed point
-- number with Q32.8 layout, i.e. 32-bits of whole cycles and 8-bits of
-- fractional cycles.
data CarrierPhase = CarrierPhase
  { carrierPhase_i :: Int32
    -- ^ Carrier phase whole cycles
  , carrierPhase_f :: Word8
    -- ^ Carrier phase fractional part
  } deriving ( Show, Read, Eq )

instance Binary CarrierPhase where
  get = do
    carrierPhase_i <- liftM fromIntegral getWord32le
    carrierPhase_f <- getWord8
    return CarrierPhase {..}

  put CarrierPhase {..} = do
    putWord32le $ fromIntegral carrierPhase_i
    putWord8 carrierPhase_f

$(deriveJSON defaultOptions {fieldLabelModifier = fromMaybe "carrierPhase_" . stripPrefix "carrierPhase_"}
             ''CarrierPhase)

-- | ObservationHeader.
--
-- Header of a GPS observation message.
data ObservationHeader = ObservationHeader
  { observationHeader_t    :: ObsGPSTime
    -- ^ GPS time of this observation
  , observationHeader_n_obs :: Word8
    -- ^ Total number of observations. First nibble is the size of the sequence
    -- (n), second nibble is the zero-indexed counter (ith packet of n)
  } deriving ( Show, Read, Eq )

instance Binary ObservationHeader where
  get = do
    observationHeader_t <- get
    observationHeader_n_obs <- getWord8
    return ObservationHeader {..}

  put ObservationHeader {..} = do
    put observationHeader_t
    putWord8 observationHeader_n_obs

$(deriveJSON defaultOptions {fieldLabelModifier = fromMaybe "observationHeader_" . stripPrefix "observationHeader_"}
             ''ObservationHeader)

-- | PackedObsContent.
--
-- Pseudorange and carrier phase observation for a satellite being tracked.
data PackedObsContent = PackedObsContent
  { packedObsContent_P   :: Word32
    -- ^ Pseudorange observation
  , packedObsContent_L   :: CarrierPhase
    -- ^ Carrier phase observation
  , packedObsContent_cn0 :: Word8
    -- ^ Carrier-to-Noise density
  , packedObsContent_lock :: Word16
    -- ^ Lock indicator. This value changes whenever a satellite signal has lost
    -- and regained lock, indicating that the carrier phase ambiguity may have
    -- changed.
  , packedObsContent_sid :: Word32
    -- ^ Signal identifier of the satellite signal - values 0x00 through 0x1F
    -- represent GPS PRNs 1 through 32 respectively (PRN-1 notation); other
    -- values reserved for future use.
  } deriving ( Show, Read, Eq )

instance Binary PackedObsContent where
  get = do
    packedObsContent_P <- getWord32le
    packedObsContent_L <- get
    packedObsContent_cn0 <- getWord8
    packedObsContent_lock <- getWord16le
    packedObsContent_sid <- getWord32le
    return PackedObsContent {..}

  put PackedObsContent {..} = do
    putWord32le packedObsContent_P
    put packedObsContent_L
    putWord8 packedObsContent_cn0
    putWord16le packedObsContent_lock
    putWord32le packedObsContent_sid

$(deriveJSON defaultOptions {fieldLabelModifier = fromMaybe "packedObsContent_" . stripPrefix "packedObsContent_"}
             ''PackedObsContent)

msgObs :: Word16
msgObs = 0x0043

-- | SBP class for message MSG_OBS (0x0043).
--
-- The GPS observations message reports all the raw pseudorange and carrier
-- phase observations for the satellites being tracked by the device. Carrier
-- phase observation here is represented as a 40-bit fixed point number with
-- Q32.8 layout (i.e. 32-bits of whole cycles and 8-bits of fractional cycles).
data MsgObs = MsgObs
  { msgObs_header :: ObservationHeader
    -- ^ Header of a GPS observation message
  , msgObs_obs   :: [PackedObsContent]
    -- ^ Pseudorange and carrier phase observation for a satellite being tracked.
  } deriving ( Show, Read, Eq )

instance Binary MsgObs where
  get = do
    msgObs_header <- get
    msgObs_obs <- whileM (liftM not isEmpty) get
    return MsgObs {..}

  put MsgObs {..} = do
    put msgObs_header
    mapM_ put msgObs_obs

$(deriveJSON defaultOptions {fieldLabelModifier = fromMaybe "msgObs_" . stripPrefix "msgObs_"}
             ''MsgObs)

msgBasePos :: Word16
msgBasePos = 0x0044

-- | SBP class for message MSG_BASE_POS (0x0044).
--
-- The base station position message is the position reported by the base
-- station itself. It is used for pseudo-absolute RTK positioning, and is
-- required to be a high-accuracy surveyed location of the base station. Any
-- error here will result in an error in the pseudo-absolute position output.
data MsgBasePos = MsgBasePos
  { msgBasePos_lat   :: Double
    -- ^ Latitude
  , msgBasePos_lon   :: Double
    -- ^ Longitude
  , msgBasePos_height :: Double
    -- ^ Height
  } deriving ( Show, Read, Eq )

instance Binary MsgBasePos where
  get = do
    msgBasePos_lat <- getFloat64le
    msgBasePos_lon <- getFloat64le
    msgBasePos_height <- getFloat64le
    return MsgBasePos {..}

  put MsgBasePos {..} = do
    putFloat64le msgBasePos_lat
    putFloat64le msgBasePos_lon
    putFloat64le msgBasePos_height

$(deriveJSON defaultOptions {fieldLabelModifier = fromMaybe "msgBasePos_" . stripPrefix "msgBasePos_"}
             ''MsgBasePos)

msgEphemeris :: Word16
msgEphemeris = 0x0047

-- | SBP class for message MSG_EPHEMERIS (0x0047).
--
-- The ephemeris message returns a set of satellite orbit parameters that is
-- used to calculate GPS satellite position, velocity, and clock offset. Please
-- see the Navstar GPS Space Segment/Navigation user interfaces (ICD-GPS-200,
-- Table 20-III) for more details.
data MsgEphemeris = MsgEphemeris
  { msgEphemeris_tgd     :: Double
    -- ^ Group delay differential between L1 and L2
  , msgEphemeris_c_rs    :: Double
    -- ^ Amplitude of the sine harmonic correction term to the orbit radius
  , msgEphemeris_c_rc    :: Double
    -- ^ Amplitude of the cosine harmonic correction term to the orbit radius
  , msgEphemeris_c_uc    :: Double
    -- ^ Amplitude of the cosine harmonic correction term to the argument of
    -- latitude
  , msgEphemeris_c_us    :: Double
    -- ^ Amplitude of the sine harmonic correction term to the argument of
    -- latitude
  , msgEphemeris_c_ic    :: Double
    -- ^ Amplitude of the cosine harmonic correction term to the angle of
    -- inclination
  , msgEphemeris_c_is    :: Double
    -- ^ Amplitude of the sine harmonic correction term to the angle of
    -- inclination
  , msgEphemeris_dn      :: Double
    -- ^ Mean motion difference
  , msgEphemeris_m0      :: Double
    -- ^ Mean anomaly at reference time
  , msgEphemeris_ecc     :: Double
    -- ^ Eccentricity of satellite orbit
  , msgEphemeris_sqrta   :: Double
    -- ^ Square root of the semi-major axis of orbit
  , msgEphemeris_omega0  :: Double
    -- ^ Longitude of ascending node of orbit plane at weekly epoch
  , msgEphemeris_omegadot :: Double
    -- ^ Rate of right ascension
  , msgEphemeris_w       :: Double
    -- ^ Argument of perigee
  , msgEphemeris_inc     :: Double
    -- ^ Inclination
  , msgEphemeris_inc_dot :: Double
    -- ^ Inclination first derivative
  , msgEphemeris_af0     :: Double
    -- ^ Polynomial clock correction coefficient (clock bias)
  , msgEphemeris_af1     :: Double
    -- ^ Polynomial clock correction coefficient (clock drift)
  , msgEphemeris_af2     :: Double
    -- ^ Polynomial clock correction coefficient (rate of clock drift)
  , msgEphemeris_toe_tow :: Double
    -- ^ Time of week
  , msgEphemeris_toe_wn  :: Word16
    -- ^ Week number
  , msgEphemeris_toc_tow :: Double
    -- ^ Clock reference time of week
  , msgEphemeris_toc_wn  :: Word16
    -- ^ Clock reference week number
  , msgEphemeris_valid   :: Word8
    -- ^ Is valid?
  , msgEphemeris_healthy :: Word8
    -- ^ Satellite is healthy?
  , msgEphemeris_sid     :: Word32
    -- ^ Signal identifier being tracked - values 0x00 through 0x1F represent GPS
    -- PRNs 1 through 32 respectively (PRN-1 notation); other values reserved
    -- for future use
  , msgEphemeris_iode    :: Word8
    -- ^ Issue of ephemeris data
  , msgEphemeris_iodc    :: Word16
    -- ^ Issue of clock data
  , msgEphemeris_reserved :: Word32
    -- ^ Reserved field
  } deriving ( Show, Read, Eq )

instance Binary MsgEphemeris where
  get = do
    msgEphemeris_tgd <- getFloat64le
    msgEphemeris_c_rs <- getFloat64le
    msgEphemeris_c_rc <- getFloat64le
    msgEphemeris_c_uc <- getFloat64le
    msgEphemeris_c_us <- getFloat64le
    msgEphemeris_c_ic <- getFloat64le
    msgEphemeris_c_is <- getFloat64le
    msgEphemeris_dn <- getFloat64le
    msgEphemeris_m0 <- getFloat64le
    msgEphemeris_ecc <- getFloat64le
    msgEphemeris_sqrta <- getFloat64le
    msgEphemeris_omega0 <- getFloat64le
    msgEphemeris_omegadot <- getFloat64le
    msgEphemeris_w <- getFloat64le
    msgEphemeris_inc <- getFloat64le
    msgEphemeris_inc_dot <- getFloat64le
    msgEphemeris_af0 <- getFloat64le
    msgEphemeris_af1 <- getFloat64le
    msgEphemeris_af2 <- getFloat64le
    msgEphemeris_toe_tow <- getFloat64le
    msgEphemeris_toe_wn <- getWord16le
    msgEphemeris_toc_tow <- getFloat64le
    msgEphemeris_toc_wn <- getWord16le
    msgEphemeris_valid <- getWord8
    msgEphemeris_healthy <- getWord8
    msgEphemeris_sid <- getWord32le
    msgEphemeris_iode <- getWord8
    msgEphemeris_iodc <- getWord16le
    msgEphemeris_reserved <- getWord32le
    return MsgEphemeris {..}

  put MsgEphemeris {..} = do
    putFloat64le msgEphemeris_tgd
    putFloat64le msgEphemeris_c_rs
    putFloat64le msgEphemeris_c_rc
    putFloat64le msgEphemeris_c_uc
    putFloat64le msgEphemeris_c_us
    putFloat64le msgEphemeris_c_ic
    putFloat64le msgEphemeris_c_is
    putFloat64le msgEphemeris_dn
    putFloat64le msgEphemeris_m0
    putFloat64le msgEphemeris_ecc
    putFloat64le msgEphemeris_sqrta
    putFloat64le msgEphemeris_omega0
    putFloat64le msgEphemeris_omegadot
    putFloat64le msgEphemeris_w
    putFloat64le msgEphemeris_inc
    putFloat64le msgEphemeris_inc_dot
    putFloat64le msgEphemeris_af0
    putFloat64le msgEphemeris_af1
    putFloat64le msgEphemeris_af2
    putFloat64le msgEphemeris_toe_tow
    putWord16le msgEphemeris_toe_wn
    putFloat64le msgEphemeris_toc_tow
    putWord16le msgEphemeris_toc_wn
    putWord8 msgEphemeris_valid
    putWord8 msgEphemeris_healthy
    putWord32le msgEphemeris_sid
    putWord8 msgEphemeris_iode
    putWord16le msgEphemeris_iodc
    putWord32le msgEphemeris_reserved

$(deriveJSON defaultOptions {fieldLabelModifier = fromMaybe "msgEphemeris_" . stripPrefix "msgEphemeris_"}
             ''MsgEphemeris)

msgEphemerisDepA :: Word16
msgEphemerisDepA = 0x001A

-- | SBP class for message MSG_EPHEMERIS_DEP_A (0x001A).
--
-- Deprecated.
data MsgEphemerisDepA = MsgEphemerisDepA
  { msgEphemerisDepA_tgd     :: Double
    -- ^ Group delay differential between L1 and L2
  , msgEphemerisDepA_c_rs    :: Double
    -- ^ Amplitude of the sine harmonic correction term to the orbit radius
  , msgEphemerisDepA_c_rc    :: Double
    -- ^ Amplitude of the cosine harmonic correction term to the orbit radius
  , msgEphemerisDepA_c_uc    :: Double
    -- ^ Amplitude of the cosine harmonic correction term to the argument of
    -- latitude
  , msgEphemerisDepA_c_us    :: Double
    -- ^ Amplitude of the sine harmonic correction term to the argument of
    -- latitude
  , msgEphemerisDepA_c_ic    :: Double
    -- ^ Amplitude of the cosine harmonic correction term to the angle of
    -- inclination
  , msgEphemerisDepA_c_is    :: Double
    -- ^ Amplitude of the sine harmonic correction term to the angle of
    -- inclination
  , msgEphemerisDepA_dn      :: Double
    -- ^ Mean motion difference
  , msgEphemerisDepA_m0      :: Double
    -- ^ Mean anomaly at reference time
  , msgEphemerisDepA_ecc     :: Double
    -- ^ Eccentricity of satellite orbit
  , msgEphemerisDepA_sqrta   :: Double
    -- ^ Square root of the semi-major axis of orbit
  , msgEphemerisDepA_omega0  :: Double
    -- ^ Longitude of ascending node of orbit plane at weekly epoch
  , msgEphemerisDepA_omegadot :: Double
    -- ^ Rate of right ascension
  , msgEphemerisDepA_w       :: Double
    -- ^ Argument of perigee
  , msgEphemerisDepA_inc     :: Double
    -- ^ Inclination
  , msgEphemerisDepA_inc_dot :: Double
    -- ^ Inclination first derivative
  , msgEphemerisDepA_af0     :: Double
    -- ^ Polynomial clock correction coefficient (clock bias)
  , msgEphemerisDepA_af1     :: Double
    -- ^ Polynomial clock correction coefficient (clock drift)
  , msgEphemerisDepA_af2     :: Double
    -- ^ Polynomial clock correction coefficient (rate of clock drift)
  , msgEphemerisDepA_toe_tow :: Double
    -- ^ Time of week
  , msgEphemerisDepA_toe_wn  :: Word16
    -- ^ Week number
  , msgEphemerisDepA_toc_tow :: Double
    -- ^ Clock reference time of week
  , msgEphemerisDepA_toc_wn  :: Word16
    -- ^ Clock reference week number
  , msgEphemerisDepA_valid   :: Word8
    -- ^ Is valid?
  , msgEphemerisDepA_healthy :: Word8
    -- ^ Satellite is healthy?
  , msgEphemerisDepA_prn     :: Word8
    -- ^ PRN being tracked
  } deriving ( Show, Read, Eq )

instance Binary MsgEphemerisDepA where
  get = do
    msgEphemerisDepA_tgd <- getFloat64le
    msgEphemerisDepA_c_rs <- getFloat64le
    msgEphemerisDepA_c_rc <- getFloat64le
    msgEphemerisDepA_c_uc <- getFloat64le
    msgEphemerisDepA_c_us <- getFloat64le
    msgEphemerisDepA_c_ic <- getFloat64le
    msgEphemerisDepA_c_is <- getFloat64le
    msgEphemerisDepA_dn <- getFloat64le
    msgEphemerisDepA_m0 <- getFloat64le
    msgEphemerisDepA_ecc <- getFloat64le
    msgEphemerisDepA_sqrta <- getFloat64le
    msgEphemerisDepA_omega0 <- getFloat64le
    msgEphemerisDepA_omegadot <- getFloat64le
    msgEphemerisDepA_w <- getFloat64le
    msgEphemerisDepA_inc <- getFloat64le
    msgEphemerisDepA_inc_dot <- getFloat64le
    msgEphemerisDepA_af0 <- getFloat64le
    msgEphemerisDepA_af1 <- getFloat64le
    msgEphemerisDepA_af2 <- getFloat64le
    msgEphemerisDepA_toe_tow <- getFloat64le
    msgEphemerisDepA_toe_wn <- getWord16le
    msgEphemerisDepA_toc_tow <- getFloat64le
    msgEphemerisDepA_toc_wn <- getWord16le
    msgEphemerisDepA_valid <- getWord8
    msgEphemerisDepA_healthy <- getWord8
    msgEphemerisDepA_prn <- getWord8
    return MsgEphemerisDepA {..}

  put MsgEphemerisDepA {..} = do
    putFloat64le msgEphemerisDepA_tgd
    putFloat64le msgEphemerisDepA_c_rs
    putFloat64le msgEphemerisDepA_c_rc
    putFloat64le msgEphemerisDepA_c_uc
    putFloat64le msgEphemerisDepA_c_us
    putFloat64le msgEphemerisDepA_c_ic
    putFloat64le msgEphemerisDepA_c_is
    putFloat64le msgEphemerisDepA_dn
    putFloat64le msgEphemerisDepA_m0
    putFloat64le msgEphemerisDepA_ecc
    putFloat64le msgEphemerisDepA_sqrta
    putFloat64le msgEphemerisDepA_omega0
    putFloat64le msgEphemerisDepA_omegadot
    putFloat64le msgEphemerisDepA_w
    putFloat64le msgEphemerisDepA_inc
    putFloat64le msgEphemerisDepA_inc_dot
    putFloat64le msgEphemerisDepA_af0
    putFloat64le msgEphemerisDepA_af1
    putFloat64le msgEphemerisDepA_af2
    putFloat64le msgEphemerisDepA_toe_tow
    putWord16le msgEphemerisDepA_toe_wn
    putFloat64le msgEphemerisDepA_toc_tow
    putWord16le msgEphemerisDepA_toc_wn
    putWord8 msgEphemerisDepA_valid
    putWord8 msgEphemerisDepA_healthy
    putWord8 msgEphemerisDepA_prn

$(deriveJSON defaultOptions {fieldLabelModifier = fromMaybe "msgEphemerisDepA_" . stripPrefix "msgEphemerisDepA_"}
             ''MsgEphemerisDepA)

msgEphemerisDepB :: Word16
msgEphemerisDepB = 0x0046

-- | SBP class for message MSG_EPHEMERIS_DEP_B (0x0046).
--
-- Deprecated.
data MsgEphemerisDepB = MsgEphemerisDepB
  { msgEphemerisDepB_tgd     :: Double
    -- ^ Group delay differential between L1 and L2
  , msgEphemerisDepB_c_rs    :: Double
    -- ^ Amplitude of the sine harmonic correction term to the orbit radius
  , msgEphemerisDepB_c_rc    :: Double
    -- ^ Amplitude of the cosine harmonic correction term to the orbit radius
  , msgEphemerisDepB_c_uc    :: Double
    -- ^ Amplitude of the cosine harmonic correction term to the argument of
    -- latitude
  , msgEphemerisDepB_c_us    :: Double
    -- ^ Amplitude of the sine harmonic correction term to the argument of
    -- latitude
  , msgEphemerisDepB_c_ic    :: Double
    -- ^ Amplitude of the cosine harmonic correction term to the angle of
    -- inclination
  , msgEphemerisDepB_c_is    :: Double
    -- ^ Amplitude of the sine harmonic correction term to the angle of
    -- inclination
  , msgEphemerisDepB_dn      :: Double
    -- ^ Mean motion difference
  , msgEphemerisDepB_m0      :: Double
    -- ^ Mean anomaly at reference time
  , msgEphemerisDepB_ecc     :: Double
    -- ^ Eccentricity of satellite orbit
  , msgEphemerisDepB_sqrta   :: Double
    -- ^ Square root of the semi-major axis of orbit
  , msgEphemerisDepB_omega0  :: Double
    -- ^ Longitude of ascending node of orbit plane at weekly epoch
  , msgEphemerisDepB_omegadot :: Double
    -- ^ Rate of right ascension
  , msgEphemerisDepB_w       :: Double
    -- ^ Argument of perigee
  , msgEphemerisDepB_inc     :: Double
    -- ^ Inclination
  , msgEphemerisDepB_inc_dot :: Double
    -- ^ Inclination first derivative
  , msgEphemerisDepB_af0     :: Double
    -- ^ Polynomial clock correction coefficient (clock bias)
  , msgEphemerisDepB_af1     :: Double
    -- ^ Polynomial clock correction coefficient (clock drift)
  , msgEphemerisDepB_af2     :: Double
    -- ^ Polynomial clock correction coefficient (rate of clock drift)
  , msgEphemerisDepB_toe_tow :: Double
    -- ^ Time of week
  , msgEphemerisDepB_toe_wn  :: Word16
    -- ^ Week number
  , msgEphemerisDepB_toc_tow :: Double
    -- ^ Clock reference time of week
  , msgEphemerisDepB_toc_wn  :: Word16
    -- ^ Clock reference week number
  , msgEphemerisDepB_valid   :: Word8
    -- ^ Is valid?
  , msgEphemerisDepB_healthy :: Word8
    -- ^ Satellite is healthy?
  , msgEphemerisDepB_prn     :: Word8
    -- ^ PRN being tracked
  , msgEphemerisDepB_iode    :: Word8
    -- ^ Issue of ephemeris data
  } deriving ( Show, Read, Eq )

instance Binary MsgEphemerisDepB where
  get = do
    msgEphemerisDepB_tgd <- getFloat64le
    msgEphemerisDepB_c_rs <- getFloat64le
    msgEphemerisDepB_c_rc <- getFloat64le
    msgEphemerisDepB_c_uc <- getFloat64le
    msgEphemerisDepB_c_us <- getFloat64le
    msgEphemerisDepB_c_ic <- getFloat64le
    msgEphemerisDepB_c_is <- getFloat64le
    msgEphemerisDepB_dn <- getFloat64le
    msgEphemerisDepB_m0 <- getFloat64le
    msgEphemerisDepB_ecc <- getFloat64le
    msgEphemerisDepB_sqrta <- getFloat64le
    msgEphemerisDepB_omega0 <- getFloat64le
    msgEphemerisDepB_omegadot <- getFloat64le
    msgEphemerisDepB_w <- getFloat64le
    msgEphemerisDepB_inc <- getFloat64le
    msgEphemerisDepB_inc_dot <- getFloat64le
    msgEphemerisDepB_af0 <- getFloat64le
    msgEphemerisDepB_af1 <- getFloat64le
    msgEphemerisDepB_af2 <- getFloat64le
    msgEphemerisDepB_toe_tow <- getFloat64le
    msgEphemerisDepB_toe_wn <- getWord16le
    msgEphemerisDepB_toc_tow <- getFloat64le
    msgEphemerisDepB_toc_wn <- getWord16le
    msgEphemerisDepB_valid <- getWord8
    msgEphemerisDepB_healthy <- getWord8
    msgEphemerisDepB_prn <- getWord8
    msgEphemerisDepB_iode <- getWord8
    return MsgEphemerisDepB {..}

  put MsgEphemerisDepB {..} = do
    putFloat64le msgEphemerisDepB_tgd
    putFloat64le msgEphemerisDepB_c_rs
    putFloat64le msgEphemerisDepB_c_rc
    putFloat64le msgEphemerisDepB_c_uc
    putFloat64le msgEphemerisDepB_c_us
    putFloat64le msgEphemerisDepB_c_ic
    putFloat64le msgEphemerisDepB_c_is
    putFloat64le msgEphemerisDepB_dn
    putFloat64le msgEphemerisDepB_m0
    putFloat64le msgEphemerisDepB_ecc
    putFloat64le msgEphemerisDepB_sqrta
    putFloat64le msgEphemerisDepB_omega0
    putFloat64le msgEphemerisDepB_omegadot
    putFloat64le msgEphemerisDepB_w
    putFloat64le msgEphemerisDepB_inc
    putFloat64le msgEphemerisDepB_inc_dot
    putFloat64le msgEphemerisDepB_af0
    putFloat64le msgEphemerisDepB_af1
    putFloat64le msgEphemerisDepB_af2
    putFloat64le msgEphemerisDepB_toe_tow
    putWord16le msgEphemerisDepB_toe_wn
    putFloat64le msgEphemerisDepB_toc_tow
    putWord16le msgEphemerisDepB_toc_wn
    putWord8 msgEphemerisDepB_valid
    putWord8 msgEphemerisDepB_healthy
    putWord8 msgEphemerisDepB_prn
    putWord8 msgEphemerisDepB_iode

$(deriveJSON defaultOptions {fieldLabelModifier = fromMaybe "msgEphemerisDepB_" . stripPrefix "msgEphemerisDepB_"}
             ''MsgEphemerisDepB)

-- | PackedObsContentDepA.
--
-- Deprecated.
data PackedObsContentDepA = PackedObsContentDepA
  { packedObsContentDepA_P   :: Word32
    -- ^ Pseudorange observation
  , packedObsContentDepA_L   :: CarrierPhase
    -- ^ Carrier phase observation
  , packedObsContentDepA_cn0 :: Word8
    -- ^ Carrier-to-Noise density
  , packedObsContentDepA_lock :: Word16
    -- ^ Lock indicator. This value changes whenever a satellite signal has lost
    -- and regained lock, indicating that the carrier phase ambiguity may have
    -- changed.
  , packedObsContentDepA_prn :: Word8
    -- ^ PRN-1 identifier of the satellite signal
  } deriving ( Show, Read, Eq )

instance Binary PackedObsContentDepA where
  get = do
    packedObsContentDepA_P <- getWord32le
    packedObsContentDepA_L <- get
    packedObsContentDepA_cn0 <- getWord8
    packedObsContentDepA_lock <- getWord16le
    packedObsContentDepA_prn <- getWord8
    return PackedObsContentDepA {..}

  put PackedObsContentDepA {..} = do
    putWord32le packedObsContentDepA_P
    put packedObsContentDepA_L
    putWord8 packedObsContentDepA_cn0
    putWord16le packedObsContentDepA_lock
    putWord8 packedObsContentDepA_prn

$(deriveJSON defaultOptions {fieldLabelModifier = fromMaybe "packedObsContentDepA_" . stripPrefix "packedObsContentDepA_"}
             ''PackedObsContentDepA)

msgObsDepA :: Word16
msgObsDepA = 0x0045

-- | SBP class for message MSG_OBS_DEP_A (0x0045).
--
-- Deprecated.
data MsgObsDepA = MsgObsDepA
  { msgObsDepA_header :: ObservationHeader
    -- ^ Header of a GPS observation message
  , msgObsDepA_obs   :: [PackedObsContentDepA]
    -- ^ Pseudorange and carrier phase observation for a satellite being tracked.
  } deriving ( Show, Read, Eq )

instance Binary MsgObsDepA where
  get = do
    msgObsDepA_header <- get
    msgObsDepA_obs <- whileM (liftM not isEmpty) get
    return MsgObsDepA {..}

  put MsgObsDepA {..} = do
    put msgObsDepA_header
    mapM_ put msgObsDepA_obs

$(deriveJSON defaultOptions {fieldLabelModifier = fromMaybe "msgObsDepA_" . stripPrefix "msgObsDepA_"}
             ''MsgObsDepA)
