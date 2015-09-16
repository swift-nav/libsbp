-- |
-- Module:      SwiftNav.SBP
-- Copyright:   Copyright (C) 2015 Swift Navigation, Inc.
-- License:     LGPL-3
-- Maintainer:  Mark Fine <dev@swiftnav.com>
-- Stability:   experimental
-- Portability: portable

module SwiftNav.SBP where

import BasicPrelude
import Data.Binary
import Data.Binary.Get
import Data.Binary.Put
import Data.ByteString
import Data.ByteString.Lazy hiding (ByteString)
import Data.ByteString.Builder
import Data.Word
import SwiftNav.CRC16
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

msgSBPPreamble :: Word8
msgSBPPreamble = 0x55

data Msg = Msg
  { msgSBPType    :: Word16
  , msgSBPSender  :: Word16
  , msgSBPLen     :: Word8
  , msgSBPPayload :: !ByteString
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

checkCrc :: Msg -> Word16
checkCrc Msg {..} =
  crc16 $ toLazyByteString $
    word16LE msgSBPType   <>
    word16LE msgSBPSender <>
    word8 msgSBPLen       <>
    byteString msgSBPPayload


data SBPMsg =
     SBPMsgAcqResult MsgAcqResult Msg
   | SBPMsgAcqResultDepA MsgAcqResultDepA Msg
   | SBPMsgAlmanac MsgAlmanac Msg
   | SBPMsgBasePos MsgBasePos Msg
   | SBPMsgBaselineEcef MsgBaselineEcef Msg
   | SBPMsgBaselineNed MsgBaselineNed Msg
   | SBPMsgBootloaderHandshakeDepA MsgBootloaderHandshakeDepA Msg
   | SBPMsgBootloaderHandshakeReq MsgBootloaderHandshakeReq Msg
   | SBPMsgBootloaderHandshakeResp MsgBootloaderHandshakeResp Msg
   | SBPMsgBootloaderJumpToApp MsgBootloaderJumpToApp Msg
   | SBPMsgCwResults MsgCwResults Msg
   | SBPMsgCwStart MsgCwStart Msg
   | SBPMsgDops MsgDops Msg
   | SBPMsgEphemeris MsgEphemeris Msg
   | SBPMsgEphemerisDepA MsgEphemerisDepA Msg
   | SBPMsgEphemerisDepB MsgEphemerisDepB Msg
   | SBPMsgExtEvent MsgExtEvent Msg
   | SBPMsgFileioReadDirReq MsgFileioReadDirReq Msg
   | SBPMsgFileioReadDirResp MsgFileioReadDirResp Msg
   | SBPMsgFileioReadReq MsgFileioReadReq Msg
   | SBPMsgFileioReadResp MsgFileioReadResp Msg
   | SBPMsgFileioRemove MsgFileioRemove Msg
   | SBPMsgFileioWriteReq MsgFileioWriteReq Msg
   | SBPMsgFileioWriteResp MsgFileioWriteResp Msg
   | SBPMsgFlashDone MsgFlashDone Msg
   | SBPMsgFlashErase MsgFlashErase Msg
   | SBPMsgFlashProgram MsgFlashProgram Msg
   | SBPMsgFlashReadReq MsgFlashReadReq Msg
   | SBPMsgFlashReadResp MsgFlashReadResp Msg
   | SBPMsgGpsTime MsgGpsTime Msg
   | SBPMsgHeartbeat MsgHeartbeat Msg
   | SBPMsgIarState MsgIarState Msg
   | SBPMsgInitBase MsgInitBase Msg
   | SBPMsgLog MsgLog Msg
   | SBPMsgM25FlashWriteStatus MsgM25FlashWriteStatus Msg
   | SBPMsgMaskSatellite MsgMaskSatellite Msg
   | SBPMsgNapDeviceDnaReq MsgNapDeviceDnaReq Msg
   | SBPMsgNapDeviceDnaResp MsgNapDeviceDnaResp Msg
   | SBPMsgObs MsgObs Msg
   | SBPMsgObsDepA MsgObsDepA Msg
   | SBPMsgPosEcef MsgPosEcef Msg
   | SBPMsgPosLlh MsgPosLlh Msg
   | SBPMsgPrintDep MsgPrintDep Msg
   | SBPMsgReset MsgReset Msg
   | SBPMsgResetFilters MsgResetFilters Msg
   | SBPMsgSetTime MsgSetTime Msg
   | SBPMsgSettingsReadByIndexDone MsgSettingsReadByIndexDone Msg
   | SBPMsgSettingsReadByIndexReq MsgSettingsReadByIndexReq Msg
   | SBPMsgSettingsReadByIndexResp MsgSettingsReadByIndexResp Msg
   | SBPMsgSettingsReadReq MsgSettingsReadReq Msg
   | SBPMsgSettingsReadResp MsgSettingsReadResp Msg
   | SBPMsgSettingsSave MsgSettingsSave Msg
   | SBPMsgSettingsWrite MsgSettingsWrite Msg
   | SBPMsgStartup MsgStartup Msg
   | SBPMsgStmFlashLockSector MsgStmFlashLockSector Msg
   | SBPMsgStmFlashUnlockSector MsgStmFlashUnlockSector Msg
   | SBPMsgStmUniqueIdReq MsgStmUniqueIdReq Msg
   | SBPMsgStmUniqueIdResp MsgStmUniqueIdResp Msg
   | SBPMsgThreadState MsgThreadState Msg
   | SBPMsgTrackingIq MsgTrackingIq Msg
   | SBPMsgTrackingState MsgTrackingState Msg
   | SBPMsgTrackingStateDepA MsgTrackingStateDepA Msg
   | SBPMsgTweet MsgTweet Msg
   | SBPMsgUartState MsgUartState Msg
   | SBPMsgVelEcef MsgVelEcef Msg
   | SBPMsgVelNed MsgVelNed Msg
   | SBPMsgUnknown Msg
  deriving ( Show, Read, Eq )

instance Binary SBPMsg where
  get = do
    preamble <- getWord8
    if preamble /= msgSBPPreamble then get else do
      sbp <- get
      if checkCrc sbp /= msgSBPCrc sbp then get else
        return $ decode' sbp where
          decode' sbp
            | msgSBPType sbp == msgAcqResult = SBPMsgAcqResult (decode (fromStrict (msgSBPPayload sbp))) sbp
            | msgSBPType sbp == msgAcqResultDepA = SBPMsgAcqResultDepA (decode (fromStrict (msgSBPPayload sbp))) sbp
            | msgSBPType sbp == msgAlmanac = SBPMsgAlmanac (decode (fromStrict (msgSBPPayload sbp))) sbp
            | msgSBPType sbp == msgBasePos = SBPMsgBasePos (decode (fromStrict (msgSBPPayload sbp))) sbp
            | msgSBPType sbp == msgBaselineEcef = SBPMsgBaselineEcef (decode (fromStrict (msgSBPPayload sbp))) sbp
            | msgSBPType sbp == msgBaselineNed = SBPMsgBaselineNed (decode (fromStrict (msgSBPPayload sbp))) sbp
            | msgSBPType sbp == msgBootloaderHandshakeDepA = SBPMsgBootloaderHandshakeDepA (decode (fromStrict (msgSBPPayload sbp))) sbp
            | msgSBPType sbp == msgBootloaderHandshakeReq = SBPMsgBootloaderHandshakeReq (decode (fromStrict (msgSBPPayload sbp))) sbp
            | msgSBPType sbp == msgBootloaderHandshakeResp = SBPMsgBootloaderHandshakeResp (decode (fromStrict (msgSBPPayload sbp))) sbp
            | msgSBPType sbp == msgBootloaderJumpToApp = SBPMsgBootloaderJumpToApp (decode (fromStrict (msgSBPPayload sbp))) sbp
            | msgSBPType sbp == msgCwResults = SBPMsgCwResults (decode (fromStrict (msgSBPPayload sbp))) sbp
            | msgSBPType sbp == msgCwStart = SBPMsgCwStart (decode (fromStrict (msgSBPPayload sbp))) sbp
            | msgSBPType sbp == msgDops = SBPMsgDops (decode (fromStrict (msgSBPPayload sbp))) sbp
            | msgSBPType sbp == msgEphemeris = SBPMsgEphemeris (decode (fromStrict (msgSBPPayload sbp))) sbp
            | msgSBPType sbp == msgEphemerisDepA = SBPMsgEphemerisDepA (decode (fromStrict (msgSBPPayload sbp))) sbp
            | msgSBPType sbp == msgEphemerisDepB = SBPMsgEphemerisDepB (decode (fromStrict (msgSBPPayload sbp))) sbp
            | msgSBPType sbp == msgExtEvent = SBPMsgExtEvent (decode (fromStrict (msgSBPPayload sbp))) sbp
            | msgSBPType sbp == msgFileioReadDirReq = SBPMsgFileioReadDirReq (decode (fromStrict (msgSBPPayload sbp))) sbp
            | msgSBPType sbp == msgFileioReadDirResp = SBPMsgFileioReadDirResp (decode (fromStrict (msgSBPPayload sbp))) sbp
            | msgSBPType sbp == msgFileioReadReq = SBPMsgFileioReadReq (decode (fromStrict (msgSBPPayload sbp))) sbp
            | msgSBPType sbp == msgFileioReadResp = SBPMsgFileioReadResp (decode (fromStrict (msgSBPPayload sbp))) sbp
            | msgSBPType sbp == msgFileioRemove = SBPMsgFileioRemove (decode (fromStrict (msgSBPPayload sbp))) sbp
            | msgSBPType sbp == msgFileioWriteReq = SBPMsgFileioWriteReq (decode (fromStrict (msgSBPPayload sbp))) sbp
            | msgSBPType sbp == msgFileioWriteResp = SBPMsgFileioWriteResp (decode (fromStrict (msgSBPPayload sbp))) sbp
            | msgSBPType sbp == msgFlashDone = SBPMsgFlashDone (decode (fromStrict (msgSBPPayload sbp))) sbp
            | msgSBPType sbp == msgFlashErase = SBPMsgFlashErase (decode (fromStrict (msgSBPPayload sbp))) sbp
            | msgSBPType sbp == msgFlashProgram = SBPMsgFlashProgram (decode (fromStrict (msgSBPPayload sbp))) sbp
            | msgSBPType sbp == msgFlashReadReq = SBPMsgFlashReadReq (decode (fromStrict (msgSBPPayload sbp))) sbp
            | msgSBPType sbp == msgFlashReadResp = SBPMsgFlashReadResp (decode (fromStrict (msgSBPPayload sbp))) sbp
            | msgSBPType sbp == msgGpsTime = SBPMsgGpsTime (decode (fromStrict (msgSBPPayload sbp))) sbp
            | msgSBPType sbp == msgHeartbeat = SBPMsgHeartbeat (decode (fromStrict (msgSBPPayload sbp))) sbp
            | msgSBPType sbp == msgIarState = SBPMsgIarState (decode (fromStrict (msgSBPPayload sbp))) sbp
            | msgSBPType sbp == msgInitBase = SBPMsgInitBase (decode (fromStrict (msgSBPPayload sbp))) sbp
            | msgSBPType sbp == msgLog = SBPMsgLog (decode (fromStrict (msgSBPPayload sbp))) sbp
            | msgSBPType sbp == msgM25FlashWriteStatus = SBPMsgM25FlashWriteStatus (decode (fromStrict (msgSBPPayload sbp))) sbp
            | msgSBPType sbp == msgMaskSatellite = SBPMsgMaskSatellite (decode (fromStrict (msgSBPPayload sbp))) sbp
            | msgSBPType sbp == msgNapDeviceDnaReq = SBPMsgNapDeviceDnaReq (decode (fromStrict (msgSBPPayload sbp))) sbp
            | msgSBPType sbp == msgNapDeviceDnaResp = SBPMsgNapDeviceDnaResp (decode (fromStrict (msgSBPPayload sbp))) sbp
            | msgSBPType sbp == msgObs = SBPMsgObs (decode (fromStrict (msgSBPPayload sbp))) sbp
            | msgSBPType sbp == msgObsDepA = SBPMsgObsDepA (decode (fromStrict (msgSBPPayload sbp))) sbp
            | msgSBPType sbp == msgPosEcef = SBPMsgPosEcef (decode (fromStrict (msgSBPPayload sbp))) sbp
            | msgSBPType sbp == msgPosLlh = SBPMsgPosLlh (decode (fromStrict (msgSBPPayload sbp))) sbp
            | msgSBPType sbp == msgPrintDep = SBPMsgPrintDep (decode (fromStrict (msgSBPPayload sbp))) sbp
            | msgSBPType sbp == msgReset = SBPMsgReset (decode (fromStrict (msgSBPPayload sbp))) sbp
            | msgSBPType sbp == msgResetFilters = SBPMsgResetFilters (decode (fromStrict (msgSBPPayload sbp))) sbp
            | msgSBPType sbp == msgSetTime = SBPMsgSetTime (decode (fromStrict (msgSBPPayload sbp))) sbp
            | msgSBPType sbp == msgSettingsReadByIndexDone = SBPMsgSettingsReadByIndexDone (decode (fromStrict (msgSBPPayload sbp))) sbp
            | msgSBPType sbp == msgSettingsReadByIndexReq = SBPMsgSettingsReadByIndexReq (decode (fromStrict (msgSBPPayload sbp))) sbp
            | msgSBPType sbp == msgSettingsReadByIndexResp = SBPMsgSettingsReadByIndexResp (decode (fromStrict (msgSBPPayload sbp))) sbp
            | msgSBPType sbp == msgSettingsReadReq = SBPMsgSettingsReadReq (decode (fromStrict (msgSBPPayload sbp))) sbp
            | msgSBPType sbp == msgSettingsReadResp = SBPMsgSettingsReadResp (decode (fromStrict (msgSBPPayload sbp))) sbp
            | msgSBPType sbp == msgSettingsSave = SBPMsgSettingsSave (decode (fromStrict (msgSBPPayload sbp))) sbp
            | msgSBPType sbp == msgSettingsWrite = SBPMsgSettingsWrite (decode (fromStrict (msgSBPPayload sbp))) sbp
            | msgSBPType sbp == msgStartup = SBPMsgStartup (decode (fromStrict (msgSBPPayload sbp))) sbp
            | msgSBPType sbp == msgStmFlashLockSector = SBPMsgStmFlashLockSector (decode (fromStrict (msgSBPPayload sbp))) sbp
            | msgSBPType sbp == msgStmFlashUnlockSector = SBPMsgStmFlashUnlockSector (decode (fromStrict (msgSBPPayload sbp))) sbp
            | msgSBPType sbp == msgStmUniqueIdReq = SBPMsgStmUniqueIdReq (decode (fromStrict (msgSBPPayload sbp))) sbp
            | msgSBPType sbp == msgStmUniqueIdResp = SBPMsgStmUniqueIdResp (decode (fromStrict (msgSBPPayload sbp))) sbp
            | msgSBPType sbp == msgThreadState = SBPMsgThreadState (decode (fromStrict (msgSBPPayload sbp))) sbp
            | msgSBPType sbp == msgTrackingIq = SBPMsgTrackingIq (decode (fromStrict (msgSBPPayload sbp))) sbp
            | msgSBPType sbp == msgTrackingState = SBPMsgTrackingState (decode (fromStrict (msgSBPPayload sbp))) sbp
            | msgSBPType sbp == msgTrackingStateDepA = SBPMsgTrackingStateDepA (decode (fromStrict (msgSBPPayload sbp))) sbp
            | msgSBPType sbp == msgTweet = SBPMsgTweet (decode (fromStrict (msgSBPPayload sbp))) sbp
            | msgSBPType sbp == msgUartState = SBPMsgUartState (decode (fromStrict (msgSBPPayload sbp))) sbp
            | msgSBPType sbp == msgVelEcef = SBPMsgVelEcef (decode (fromStrict (msgSBPPayload sbp))) sbp
            | msgSBPType sbp == msgVelNed = SBPMsgVelNed (decode (fromStrict (msgSBPPayload sbp))) sbp
            | otherwise = SBPMsgUnknown sbp

  put msg = do
    putWord8 msgSBPPreamble
    put $ encode' msg
    where
      encode' (SBPMsgAcqResult _ sbp) = sbp
      encode' (SBPMsgAcqResultDepA _ sbp) = sbp
      encode' (SBPMsgAlmanac _ sbp) = sbp
      encode' (SBPMsgBasePos _ sbp) = sbp
      encode' (SBPMsgBaselineEcef _ sbp) = sbp
      encode' (SBPMsgBaselineNed _ sbp) = sbp
      encode' (SBPMsgBootloaderHandshakeDepA _ sbp) = sbp
      encode' (SBPMsgBootloaderHandshakeReq _ sbp) = sbp
      encode' (SBPMsgBootloaderHandshakeResp _ sbp) = sbp
      encode' (SBPMsgBootloaderJumpToApp _ sbp) = sbp
      encode' (SBPMsgCwResults _ sbp) = sbp
      encode' (SBPMsgCwStart _ sbp) = sbp
      encode' (SBPMsgDops _ sbp) = sbp
      encode' (SBPMsgEphemeris _ sbp) = sbp
      encode' (SBPMsgEphemerisDepA _ sbp) = sbp
      encode' (SBPMsgEphemerisDepB _ sbp) = sbp
      encode' (SBPMsgExtEvent _ sbp) = sbp
      encode' (SBPMsgFileioReadDirReq _ sbp) = sbp
      encode' (SBPMsgFileioReadDirResp _ sbp) = sbp
      encode' (SBPMsgFileioReadReq _ sbp) = sbp
      encode' (SBPMsgFileioReadResp _ sbp) = sbp
      encode' (SBPMsgFileioRemove _ sbp) = sbp
      encode' (SBPMsgFileioWriteReq _ sbp) = sbp
      encode' (SBPMsgFileioWriteResp _ sbp) = sbp
      encode' (SBPMsgFlashDone _ sbp) = sbp
      encode' (SBPMsgFlashErase _ sbp) = sbp
      encode' (SBPMsgFlashProgram _ sbp) = sbp
      encode' (SBPMsgFlashReadReq _ sbp) = sbp
      encode' (SBPMsgFlashReadResp _ sbp) = sbp
      encode' (SBPMsgGpsTime _ sbp) = sbp
      encode' (SBPMsgHeartbeat _ sbp) = sbp
      encode' (SBPMsgIarState _ sbp) = sbp
      encode' (SBPMsgInitBase _ sbp) = sbp
      encode' (SBPMsgLog _ sbp) = sbp
      encode' (SBPMsgM25FlashWriteStatus _ sbp) = sbp
      encode' (SBPMsgMaskSatellite _ sbp) = sbp
      encode' (SBPMsgNapDeviceDnaReq _ sbp) = sbp
      encode' (SBPMsgNapDeviceDnaResp _ sbp) = sbp
      encode' (SBPMsgObs _ sbp) = sbp
      encode' (SBPMsgObsDepA _ sbp) = sbp
      encode' (SBPMsgPosEcef _ sbp) = sbp
      encode' (SBPMsgPosLlh _ sbp) = sbp
      encode' (SBPMsgPrintDep _ sbp) = sbp
      encode' (SBPMsgReset _ sbp) = sbp
      encode' (SBPMsgResetFilters _ sbp) = sbp
      encode' (SBPMsgSetTime _ sbp) = sbp
      encode' (SBPMsgSettingsReadByIndexDone _ sbp) = sbp
      encode' (SBPMsgSettingsReadByIndexReq _ sbp) = sbp
      encode' (SBPMsgSettingsReadByIndexResp _ sbp) = sbp
      encode' (SBPMsgSettingsReadReq _ sbp) = sbp
      encode' (SBPMsgSettingsReadResp _ sbp) = sbp
      encode' (SBPMsgSettingsSave _ sbp) = sbp
      encode' (SBPMsgSettingsWrite _ sbp) = sbp
      encode' (SBPMsgStartup _ sbp) = sbp
      encode' (SBPMsgStmFlashLockSector _ sbp) = sbp
      encode' (SBPMsgStmFlashUnlockSector _ sbp) = sbp
      encode' (SBPMsgStmUniqueIdReq _ sbp) = sbp
      encode' (SBPMsgStmUniqueIdResp _ sbp) = sbp
      encode' (SBPMsgThreadState _ sbp) = sbp
      encode' (SBPMsgTrackingIq _ sbp) = sbp
      encode' (SBPMsgTrackingState _ sbp) = sbp
      encode' (SBPMsgTrackingStateDepA _ sbp) = sbp
      encode' (SBPMsgTweet _ sbp) = sbp
      encode' (SBPMsgUartState _ sbp) = sbp
      encode' (SBPMsgVelEcef _ sbp) = sbp
      encode' (SBPMsgVelNed _ sbp) = sbp
      encode' (SBPMsgUnknown sbp) = sbp