module SwiftNav.SBP.Observation where

import Control.Monad
import Control.Monad.Loops
import Data.Binary
import Data.Binary.Get
import Data.Binary.IEEE754
import Data.Binary.Put
import Data.ByteString
import Data.ByteString.Lazy hiding ( ByteString )
import Data.Int
import Data.Word

data ObsGPSTime = ObsGPSTime
  { obsGPSTimeTow :: Word32
  , obsGPSTimeWn  :: Word16
  } deriving ( Show, Read, Eq )

instance Binary ObsGPSTime where
  get = do
    obsGPSTimeTow <- getWord32le
    obsGPSTimeWn <- getWord16le
    return ObsGPSTime {..}

  put ObsGPSTime {..} = do
    putWord32le obsGPSTimeTow
    putWord16le obsGPSTimeWn

data CarrierPhase = CarrierPhase
  { carrierPhaseI :: Int32
  , carrierPhaseF :: Word8
  } deriving ( Show, Read, Eq )

instance Binary CarrierPhase where
  get = do
    carrierPhaseI <- liftM fromIntegral getWord32le
    carrierPhaseF <- getWord8
    return CarrierPhase {..}

  put CarrierPhase {..} = do
    putWord32le $ fromIntegral carrierPhaseI
    putWord8 carrierPhaseF

data ObservationHeader = ObservationHeader
  { observationHeaderT     :: ObsGPSTime
  , observationHeaderNObs  :: Word8
  } deriving ( Show, Read, Eq )

instance Binary ObservationHeader where
  get = do
    observationHeaderT <- get
    observationHeaderNObs <- getWord8
    return ObservationHeader {..}

  put ObservationHeader {..} = do
    put observationHeaderT
    putWord8 observationHeaderNObs

data PackedObsContent = PackedObsContent
  { packedObsContentP    :: Word32
  , packedObsContentL    :: CarrierPhase
  , packedObsContentCn0  :: Word8
  , packedObsContentLock :: Word16
  , packedObsContentSid  :: Word32
  } deriving ( Show, Read, Eq )

instance Binary PackedObsContent where
  get = do
    packedObsContentP <- getWord32le
    packedObsContentL <- get
    packedObsContentCn0 <- getWord8
    packedObsContentLock <- getWord16le
    packedObsContentSid <- getWord32le
    return PackedObsContent {..}

  put PackedObsContent {..} = do
    putWord32le packedObsContentP
    put packedObsContentL
    putWord8 packedObsContentCn0
    putWord16le packedObsContentLock
    putWord32le packedObsContentSid

msgObs :: Word16
msgObs = 0x0043

data MsgObs = MsgObs
  { msgObsHeader :: ObservationHeader
  , msgObsObs    :: [PackedObsContent]
  } deriving ( Show, Read, Eq )

instance Binary MsgObs where
  get = do
    msgObsHeader <- get
    msgObsObs <- whileM (liftM not isEmpty) get
    return MsgObs {..}

  put MsgObs {..} = do
    put msgObsHeader
    put msgObsObs

msgBasePos :: Word16
msgBasePos = 0x0044

data MsgBasePos = MsgBasePos
  { msgBasePosLat    :: Double
  , msgBasePosLon    :: Double
  , msgBasePosHeight :: Double
  } deriving ( Show, Read, Eq )

instance Binary MsgBasePos where
  get = do
    msgBasePosLat <- getFloat64le
    msgBasePosLon <- getFloat64le
    msgBasePosHeight <- getFloat64le
    return MsgBasePos {..}

  put MsgBasePos {..} = do
    putFloat64le msgBasePosLat
    putFloat64le msgBasePosLon
    putFloat64le msgBasePosHeight

msgEphemeris :: Word16
msgEphemeris = 0x0047

data MsgEphemeris = MsgEphemeris
  { msgEphemerisTgd      :: Double
  , msgEphemerisCRs      :: Double
  , msgEphemerisCRc      :: Double
  , msgEphemerisCUc      :: Double
  , msgEphemerisCUs      :: Double
  , msgEphemerisCIc      :: Double
  , msgEphemerisCIs      :: Double
  , msgEphemerisDn       :: Double
  , msgEphemerisM0       :: Double
  , msgEphemerisEcc      :: Double
  , msgEphemerisSqrta    :: Double
  , msgEphemerisOmega0   :: Double
  , msgEphemerisOmegadot :: Double
  , msgEphemerisW        :: Double
  , msgEphemerisInc      :: Double
  , msgEphemerisIncDot   :: Double
  , msgEphemerisAf0      :: Double
  , msgEphemerisAf1      :: Double
  , msgEphemerisAf2      :: Double
  , msgEphemerisToeTow   :: Double
  , msgEphemerisToeWn    :: Word16
  , msgEphemerisTocTow   :: Double
  , msgEphemerisTocWn    :: Word16
  , msgEphemerisValid    :: Word8
  , msgEphemerisHealthy  :: Word8
  , msgEphemerisSid      :: Word32
  , msgEphemerisIode     :: Word8
  , msgEphemerisIodc     :: Word16
  , msgEphemerisReserved :: Word32
  } deriving ( Show, Read, Eq )

instance Binary MsgEphemeris where
  get = do
    msgEphemerisTgd <- getFloat64le
    msgEphemerisCRs <- getFloat64le
    msgEphemerisCRc <- getFloat64le
    msgEphemerisCUc <- getFloat64le
    msgEphemerisCUs <- getFloat64le
    msgEphemerisCIc <- getFloat64le
    msgEphemerisCIs <- getFloat64le
    msgEphemerisDn <- getFloat64le
    msgEphemerisM0 <- getFloat64le
    msgEphemerisEcc <- getFloat64le
    msgEphemerisSqrta <- getFloat64le
    msgEphemerisOmega0 <- getFloat64le
    msgEphemerisOmegadot <- getFloat64le
    msgEphemerisW <- getFloat64le
    msgEphemerisInc <- getFloat64le
    msgEphemerisIncDot <- getFloat64le
    msgEphemerisAf0 <- getFloat64le
    msgEphemerisAf1 <- getFloat64le
    msgEphemerisAf2 <- getFloat64le
    msgEphemerisToeTow <- getFloat64le
    msgEphemerisToeWn <- getWord16le
    msgEphemerisTocTow <- getFloat64le
    msgEphemerisTocWn <- getWord16le
    msgEphemerisValid <- getWord8
    msgEphemerisHealthy <- getWord8
    msgEphemerisSid <- getWord32le
    msgEphemerisIode <- getWord8
    msgEphemerisIodc <- getWord16le
    msgEphemerisReserved <- getWord32le
    return MsgEphemeris {..}

  put MsgEphemeris {..} = do
    putFloat64le msgEphemerisTgd
    putFloat64le msgEphemerisCRs
    putFloat64le msgEphemerisCRc
    putFloat64le msgEphemerisCUc
    putFloat64le msgEphemerisCUs
    putFloat64le msgEphemerisCIc
    putFloat64le msgEphemerisCIs
    putFloat64le msgEphemerisDn
    putFloat64le msgEphemerisM0
    putFloat64le msgEphemerisEcc
    putFloat64le msgEphemerisSqrta
    putFloat64le msgEphemerisOmega0
    putFloat64le msgEphemerisOmegadot
    putFloat64le msgEphemerisW
    putFloat64le msgEphemerisInc
    putFloat64le msgEphemerisIncDot
    putFloat64le msgEphemerisAf0
    putFloat64le msgEphemerisAf1
    putFloat64le msgEphemerisAf2
    putFloat64le msgEphemerisToeTow
    putWord16le msgEphemerisToeWn
    putFloat64le msgEphemerisTocTow
    putWord16le msgEphemerisTocWn
    putWord8 msgEphemerisValid
    putWord8 msgEphemerisHealthy
    putWord32le msgEphemerisSid
    putWord8 msgEphemerisIode
    putWord16le msgEphemerisIodc
    putWord32le msgEphemerisReserved

msgEphemerisDepA :: Word16
msgEphemerisDepA = 0x001A

data MsgEphemerisDepA = MsgEphemerisDepA
  { msgEphemerisDepATgd      :: Double
  , msgEphemerisDepACRs      :: Double
  , msgEphemerisDepACRc      :: Double
  , msgEphemerisDepACUc      :: Double
  , msgEphemerisDepACUs      :: Double
  , msgEphemerisDepACIc      :: Double
  , msgEphemerisDepACIs      :: Double
  , msgEphemerisDepADn       :: Double
  , msgEphemerisDepAM0       :: Double
  , msgEphemerisDepAEcc      :: Double
  , msgEphemerisDepASqrta    :: Double
  , msgEphemerisDepAOmega0   :: Double
  , msgEphemerisDepAOmegadot :: Double
  , msgEphemerisDepAW        :: Double
  , msgEphemerisDepAInc      :: Double
  , msgEphemerisDepAIncDot   :: Double
  , msgEphemerisDepAAf0      :: Double
  , msgEphemerisDepAAf1      :: Double
  , msgEphemerisDepAAf2      :: Double
  , msgEphemerisDepAToeTow   :: Double
  , msgEphemerisDepAToeWn    :: Word16
  , msgEphemerisDepATocTow   :: Double
  , msgEphemerisDepATocWn    :: Word16
  , msgEphemerisDepAValid    :: Word8
  , msgEphemerisDepAHealthy  :: Word8
  , msgEphemerisDepAPrn      :: Word8
  } deriving ( Show, Read, Eq )

instance Binary MsgEphemerisDepA where
  get = do
    msgEphemerisDepATgd <- getFloat64le
    msgEphemerisDepACRs <- getFloat64le
    msgEphemerisDepACRc <- getFloat64le
    msgEphemerisDepACUc <- getFloat64le
    msgEphemerisDepACUs <- getFloat64le
    msgEphemerisDepACIc <- getFloat64le
    msgEphemerisDepACIs <- getFloat64le
    msgEphemerisDepADn <- getFloat64le
    msgEphemerisDepAM0 <- getFloat64le
    msgEphemerisDepAEcc <- getFloat64le
    msgEphemerisDepASqrta <- getFloat64le
    msgEphemerisDepAOmega0 <- getFloat64le
    msgEphemerisDepAOmegadot <- getFloat64le
    msgEphemerisDepAW <- getFloat64le
    msgEphemerisDepAInc <- getFloat64le
    msgEphemerisDepAIncDot <- getFloat64le
    msgEphemerisDepAAf0 <- getFloat64le
    msgEphemerisDepAAf1 <- getFloat64le
    msgEphemerisDepAAf2 <- getFloat64le
    msgEphemerisDepAToeTow <- getFloat64le
    msgEphemerisDepAToeWn <- getWord16le
    msgEphemerisDepATocTow <- getFloat64le
    msgEphemerisDepATocWn <- getWord16le
    msgEphemerisDepAValid <- getWord8
    msgEphemerisDepAHealthy <- getWord8
    msgEphemerisDepAPrn <- getWord8
    return MsgEphemerisDepA {..}

  put MsgEphemerisDepA {..} = do
    putFloat64le msgEphemerisDepATgd
    putFloat64le msgEphemerisDepACRs
    putFloat64le msgEphemerisDepACRc
    putFloat64le msgEphemerisDepACUc
    putFloat64le msgEphemerisDepACUs
    putFloat64le msgEphemerisDepACIc
    putFloat64le msgEphemerisDepACIs
    putFloat64le msgEphemerisDepADn
    putFloat64le msgEphemerisDepAM0
    putFloat64le msgEphemerisDepAEcc
    putFloat64le msgEphemerisDepASqrta
    putFloat64le msgEphemerisDepAOmega0
    putFloat64le msgEphemerisDepAOmegadot
    putFloat64le msgEphemerisDepAW
    putFloat64le msgEphemerisDepAInc
    putFloat64le msgEphemerisDepAIncDot
    putFloat64le msgEphemerisDepAAf0
    putFloat64le msgEphemerisDepAAf1
    putFloat64le msgEphemerisDepAAf2
    putFloat64le msgEphemerisDepAToeTow
    putWord16le msgEphemerisDepAToeWn
    putFloat64le msgEphemerisDepATocTow
    putWord16le msgEphemerisDepATocWn
    putWord8 msgEphemerisDepAValid
    putWord8 msgEphemerisDepAHealthy
    putWord8 msgEphemerisDepAPrn

msgEphemerisDepB :: Word16
msgEphemerisDepB = 0x0046

data MsgEphemerisDepB = MsgEphemerisDepB
  { msgEphemerisDepBTgd      :: Double
  , msgEphemerisDepBCRs      :: Double
  , msgEphemerisDepBCRc      :: Double
  , msgEphemerisDepBCUc      :: Double
  , msgEphemerisDepBCUs      :: Double
  , msgEphemerisDepBCIc      :: Double
  , msgEphemerisDepBCIs      :: Double
  , msgEphemerisDepBDn       :: Double
  , msgEphemerisDepBM0       :: Double
  , msgEphemerisDepBEcc      :: Double
  , msgEphemerisDepBSqrta    :: Double
  , msgEphemerisDepBOmega0   :: Double
  , msgEphemerisDepBOmegadot :: Double
  , msgEphemerisDepBW        :: Double
  , msgEphemerisDepBInc      :: Double
  , msgEphemerisDepBIncDot   :: Double
  , msgEphemerisDepBAf0      :: Double
  , msgEphemerisDepBAf1      :: Double
  , msgEphemerisDepBAf2      :: Double
  , msgEphemerisDepBToeTow   :: Double
  , msgEphemerisDepBToeWn    :: Word16
  , msgEphemerisDepBTocTow   :: Double
  , msgEphemerisDepBTocWn    :: Word16
  , msgEphemerisDepBValid    :: Word8
  , msgEphemerisDepBHealthy  :: Word8
  , msgEphemerisDepBPrn      :: Word8
  , msgEphemerisDepBIode     :: Word8
  } deriving ( Show, Read, Eq )

instance Binary MsgEphemerisDepB where
  get = do
    msgEphemerisDepBTgd <- getFloat64le
    msgEphemerisDepBCRs <- getFloat64le
    msgEphemerisDepBCRc <- getFloat64le
    msgEphemerisDepBCUc <- getFloat64le
    msgEphemerisDepBCUs <- getFloat64le
    msgEphemerisDepBCIc <- getFloat64le
    msgEphemerisDepBCIs <- getFloat64le
    msgEphemerisDepBDn <- getFloat64le
    msgEphemerisDepBM0 <- getFloat64le
    msgEphemerisDepBEcc <- getFloat64le
    msgEphemerisDepBSqrta <- getFloat64le
    msgEphemerisDepBOmega0 <- getFloat64le
    msgEphemerisDepBOmegadot <- getFloat64le
    msgEphemerisDepBW <- getFloat64le
    msgEphemerisDepBInc <- getFloat64le
    msgEphemerisDepBIncDot <- getFloat64le
    msgEphemerisDepBAf0 <- getFloat64le
    msgEphemerisDepBAf1 <- getFloat64le
    msgEphemerisDepBAf2 <- getFloat64le
    msgEphemerisDepBToeTow <- getFloat64le
    msgEphemerisDepBToeWn <- getWord16le
    msgEphemerisDepBTocTow <- getFloat64le
    msgEphemerisDepBTocWn <- getWord16le
    msgEphemerisDepBValid <- getWord8
    msgEphemerisDepBHealthy <- getWord8
    msgEphemerisDepBPrn <- getWord8
    msgEphemerisDepBIode <- getWord8
    return MsgEphemerisDepB {..}

  put MsgEphemerisDepB {..} = do
    putFloat64le msgEphemerisDepBTgd
    putFloat64le msgEphemerisDepBCRs
    putFloat64le msgEphemerisDepBCRc
    putFloat64le msgEphemerisDepBCUc
    putFloat64le msgEphemerisDepBCUs
    putFloat64le msgEphemerisDepBCIc
    putFloat64le msgEphemerisDepBCIs
    putFloat64le msgEphemerisDepBDn
    putFloat64le msgEphemerisDepBM0
    putFloat64le msgEphemerisDepBEcc
    putFloat64le msgEphemerisDepBSqrta
    putFloat64le msgEphemerisDepBOmega0
    putFloat64le msgEphemerisDepBOmegadot
    putFloat64le msgEphemerisDepBW
    putFloat64le msgEphemerisDepBInc
    putFloat64le msgEphemerisDepBIncDot
    putFloat64le msgEphemerisDepBAf0
    putFloat64le msgEphemerisDepBAf1
    putFloat64le msgEphemerisDepBAf2
    putFloat64le msgEphemerisDepBToeTow
    putWord16le msgEphemerisDepBToeWn
    putFloat64le msgEphemerisDepBTocTow
    putWord16le msgEphemerisDepBTocWn
    putWord8 msgEphemerisDepBValid
    putWord8 msgEphemerisDepBHealthy
    putWord8 msgEphemerisDepBPrn
    putWord8 msgEphemerisDepBIode

data PackedObsContentDepA = PackedObsContentDepA
  { packedObsContentDepAP    :: Word32
  , packedObsContentDepAL    :: CarrierPhase
  , packedObsContentDepACn0  :: Word8
  , packedObsContentDepALock :: Word16
  , packedObsContentDepAPrn  :: Word8
  } deriving ( Show, Read, Eq )

instance Binary PackedObsContentDepA where
  get = do
    packedObsContentDepAP <- getWord32le
    packedObsContentDepAL <- get
    packedObsContentDepACn0 <- getWord8
    packedObsContentDepALock <- getWord16le
    packedObsContentDepAPrn <- getWord8
    return PackedObsContentDepA {..}

  put PackedObsContentDepA {..} = do
    putWord32le packedObsContentDepAP
    put packedObsContentDepAL
    putWord8 packedObsContentDepACn0
    putWord16le packedObsContentDepALock
    putWord8 packedObsContentDepAPrn

msgObsDepA :: Word16
msgObsDepA = 0x0045

data MsgObsDepA = MsgObsDepA
  { msgObsDepAHeader :: ObservationHeader
  , msgObsDepAObs    :: [PackedObsContentDepA]
  } deriving ( Show, Read, Eq )

instance Binary MsgObsDepA where
  get = do
    msgObsDepAHeader <- get
    msgObsDepAObs <- whileM (liftM not isEmpty) get
    return MsgObsDepA {..}

  put MsgObsDepA {..} = do
    put msgObsDepAHeader
    put msgObsDepAObs
