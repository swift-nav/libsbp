module SwiftNav.SBP where

import Data.Binary
import Data.Binary.Get
import Data.Binary.Put
import Data.ByteString
import Data.Word
import SwiftNav.SBP.Acquisition
import SwiftNav.SBP.Bootload
import SwiftNav.SBP.ExtEvents
import SwiftNav.SBP.FileIo
import SwiftNav.SBP.Flash
import SwiftNav.SBP.Logging
import SwiftNav.SBP.Navigation
import SwiftNav.SBP.Observation
import SwiftNav.SBP.Piksi
import SwiftNav.SBP.Settings
import SwiftNav.SBP.System
import SwiftNav.SBP.Tracking

msgPreamble :: Word8
msgPreamble = 0x55

data Msg = Msg
  { msgSBPType    :: Word16
  , msgSBPSender  :: Word16
  , msgSBPLen     :: Word8
  , msgSBPPayload :: ByteString
  , msgSBPCrc     :: Word16
  } deriving ( Show, Read, Eq )

instance Binary Msg where
  get = do
    msgSBPType <- getWord16le
    msgSBPSender <- getWord16le
    msgSBPLen <- getWord8
    msgSBPPayload <- getByteString $ fromIntegral msgSBPLen
    msgSBPCrc <- getWord16le
    return Msg {..}

  put Msg {..} = do
    putWord16le msgSBPType
    putWord16le msgSBPSender
    putWord8 msgSBPLen
    putByteString msgSBPPayload
    putWord16le msgSBPCrc

getMsg :: Get Msg
getMsg = do
  preamble <- getWord8
  if preamble /= msgPreamble then getMsg else get

putMsg :: Msg -> Put
putMsg msg = do
  putWord8 msgPreamble
  put msg
  SBPMsgAcqResult
  SBPMsgAcqResultDepA
  SBPMsgAlmanac
  SBPMsgBasePos
  SBPMsgBaselineEcef
  SBPMsgBaselineNed
  SBPMsgBootloaderHandshakeDepA
  SBPMsgBootloaderHandshakeReq
  SBPMsgBootloaderHandshakeResp
  SBPMsgBootloaderJumpToApp
  SBPMsgCwResults
  SBPMsgCwStart
  SBPMsgDops
  SBPMsgEphemeris
  SBPMsgEphemerisDepA
  SBPMsgEphemerisDepB
  SBPMsgExtEvent
  SBPMsgFileioReadDirReq
  SBPMsgFileioReadDirResp
  SBPMsgFileioReadReq
  SBPMsgFileioReadResp
  SBPMsgFileioRemove
  SBPMsgFileioWriteReq
  SBPMsgFileioWriteResp
  SBPMsgFlashDone
  SBPMsgFlashErase
  SBPMsgFlashProgram
  SBPMsgFlashReadReq
  SBPMsgFlashReadResp
  SBPMsgGpsTime
  SBPMsgHeartbeat
  SBPMsgIarState
  SBPMsgInitBase
  SBPMsgM25FlashWriteStatus
  SBPMsgMaskSatellite
  SBPMsgNapDeviceDnaReq
  SBPMsgNapDeviceDnaResp
  SBPMsgObs
  SBPMsgObsDepA
  SBPMsgPosEcef
  SBPMsgPosLlh
  SBPMsgPrint
  SBPMsgReset
  SBPMsgResetFilters
  SBPMsgSetTime
  SBPMsgSettingsReadByIndexDone
  SBPMsgSettingsReadByIndexReq
  SBPMsgSettingsReadByIndexResp
  SBPMsgSettingsReadReq
  SBPMsgSettingsReadResp
  SBPMsgSettingsSave
  SBPMsgSettingsWrite
  SBPMsgStartup
  SBPMsgStmFlashLockSector
  SBPMsgStmFlashUnlockSector
  SBPMsgStmUniqueIdReq
  SBPMsgStmUniqueIdResp
  SBPMsgThreadState
  SBPMsgTrackingIq
  SBPMsgTrackingState
  SBPMsgTrackingStateDepA
  SBPMsgTweet
  SBPMsgUartState
  SBPMsgVelEcef
  SBPMsgVelNed