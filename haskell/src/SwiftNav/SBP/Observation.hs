module SwiftNav.SBP.Observation where

import Data.Int
import Data.Text
import Data.Word



data ObsGPSTime = ObsGPSTime
  { obsGPSTimeTow :: Word32
  , obsGPSTimeWn  :: Word16
  } deriving ( Show, Read, Eq )


data CarrierPhase = CarrierPhase
  { carrierPhaseI :: Int32
  , carrierPhaseF :: Word8
  } deriving ( Show, Read, Eq )


data ObservationHeader = ObservationHeader
  { observationHeaderT     :: ObsGPSTime
  , observationHeaderNObs  :: Word8
  } deriving ( Show, Read, Eq )


data PackedObsContent = PackedObsContent
  { packedObsContentP    :: Word32
  , packedObsContentL    :: CarrierPhase
  , packedObsContentCn0  :: Word8
  , packedObsContentLock :: Word16
  , packedObsContentSid  :: Word32
  } deriving ( Show, Read, Eq )

msgObs :: Word16
msgObs = 0x0043

data MsgObs = MsgObs
  { msgObsHeader :: ObservationHeader
  , msgObsObs    :: [PackedObsContent]
  } deriving ( Show, Read, Eq )

msgBasePos :: Word16
msgBasePos = 0x0044

data MsgBasePos = MsgBasePos
  { msgBasePosLat    :: Double
  , msgBasePosLon    :: Double
  , msgBasePosHeight :: Double
  } deriving ( Show, Read, Eq )

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


data PackedObsContentDepA = PackedObsContentDepA
  { packedObsContentDepAP    :: Word32
  , packedObsContentDepAL    :: CarrierPhase
  , packedObsContentDepACn0  :: Word8
  , packedObsContentDepALock :: Word16
  , packedObsContentDepAPrn  :: Word8
  } deriving ( Show, Read, Eq )

msgObsDepA :: Word16
msgObsDepA = 0x0045

data MsgObsDepA = MsgObsDepA
  { msgObsDepAHeader :: ObservationHeader
  , msgObsDepAObs    :: [PackedObsContentDepA]
  } deriving ( Show, Read, Eq )
