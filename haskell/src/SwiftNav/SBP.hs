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

data SBPMsg =
     SBPMsgAcqResult MsgAcqResult
   | SBPMsgAcqResultDepA MsgAcqResultDepA
   | SBPMsgAlmanac MsgAlmanac
   | SBPMsgBasePos MsgBasePos
   | SBPMsgBaselineEcef MsgBaselineEcef
   | SBPMsgBaselineNed MsgBaselineNed
   | SBPMsgBootloaderHandshakeDepA MsgBootloaderHandshakeDepA
   | SBPMsgBootloaderHandshakeReq MsgBootloaderHandshakeReq
   | SBPMsgBootloaderHandshakeResp MsgBootloaderHandshakeResp
   | SBPMsgBootloaderJumpToApp MsgBootloaderJumpToApp
   | SBPMsgCwResults MsgCwResults
   | SBPMsgCwStart MsgCwStart
   | SBPMsgDops MsgDops
   | SBPMsgEphemeris MsgEphemeris
   | SBPMsgEphemerisDepA MsgEphemerisDepA
   | SBPMsgEphemerisDepB MsgEphemerisDepB
   | SBPMsgExtEvent MsgExtEvent
   | SBPMsgFileioReadDirReq MsgFileioReadDirReq
   | SBPMsgFileioReadDirResp MsgFileioReadDirResp
   | SBPMsgFileioReadReq MsgFileioReadReq
   | SBPMsgFileioReadResp MsgFileioReadResp
   | SBPMsgFileioRemove MsgFileioRemove
   | SBPMsgFileioWriteReq MsgFileioWriteReq
   | SBPMsgFileioWriteResp MsgFileioWriteResp
   | SBPMsgFlashDone MsgFlashDone
   | SBPMsgFlashErase MsgFlashErase
   | SBPMsgFlashProgram MsgFlashProgram
   | SBPMsgFlashReadReq MsgFlashReadReq
   | SBPMsgFlashReadResp MsgFlashReadResp
   | SBPMsgGpsTime MsgGpsTime
   | SBPMsgHeartbeat MsgHeartbeat
   | SBPMsgIarState MsgIarState
   | SBPMsgInitBase MsgInitBase
   | SBPMsgLog MsgLog
   | SBPMsgM25FlashWriteStatus MsgM25FlashWriteStatus
   | SBPMsgMaskSatellite MsgMaskSatellite
   | SBPMsgNapDeviceDnaReq MsgNapDeviceDnaReq
   | SBPMsgNapDeviceDnaResp MsgNapDeviceDnaResp
   | SBPMsgObs MsgObs
   | SBPMsgObsDepA MsgObsDepA
   | SBPMsgPosEcef MsgPosEcef
   | SBPMsgPosLlh MsgPosLlh
   | SBPMsgPrintDep MsgPrintDep
   | SBPMsgReset MsgReset
   | SBPMsgResetFilters MsgResetFilters
   | SBPMsgSetTime MsgSetTime
   | SBPMsgSettingsReadByIndexDone MsgSettingsReadByIndexDone
   | SBPMsgSettingsReadByIndexReq MsgSettingsReadByIndexReq
   | SBPMsgSettingsReadByIndexResp MsgSettingsReadByIndexResp
   | SBPMsgSettingsReadReq MsgSettingsReadReq
   | SBPMsgSettingsReadResp MsgSettingsReadResp
   | SBPMsgSettingsSave MsgSettingsSave
   | SBPMsgSettingsWrite MsgSettingsWrite
   | SBPMsgStartup MsgStartup
   | SBPMsgStmFlashLockSector MsgStmFlashLockSector
   | SBPMsgStmFlashUnlockSector MsgStmFlashUnlockSector
   | SBPMsgStmUniqueIdReq MsgStmUniqueIdReq
   | SBPMsgStmUniqueIdResp MsgStmUniqueIdResp
   | SBPMsgThreadState MsgThreadState
   | SBPMsgTrackingIq MsgTrackingIq
   | SBPMsgTrackingState MsgTrackingState
   | SBPMsgTrackingStateDepA MsgTrackingStateDepA
   | SBPMsgTweet MsgTweet
   | SBPMsgUartState MsgUartState
   | SBPMsgVelEcef MsgVelEcef
   | SBPMsgVelNed MsgVelNed
  deriving ( Show, Read, Eq )