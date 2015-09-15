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

getMsg :: Get Msg
getMsg = do
  preamble <- getWord8
  if preamble /= msgPreamble then getMsg else get

putMsg :: Msg -> Put
putMsg msg = do
  putWord8 msgPreamble
  put msg

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
    if preamble /= msgPreamble then get else do
      t <- getWord16le
      s <- getWord16le
      l <- getWord8
      p <- getByteString $ fromIntegral l
      crc <- getWord16le
      let sbp = Msg t s l p crc
      return $ decode' t p sbp where
        decode' t p sbp
          | t == msgAcqResult = SBPMsgAcqResult (decode (fromStrict p)) sbp
          | t == msgAcqResultDepA = SBPMsgAcqResultDepA (decode (fromStrict p)) sbp
          | t == msgAlmanac = SBPMsgAlmanac (decode (fromStrict p)) sbp
          | t == msgBasePos = SBPMsgBasePos (decode (fromStrict p)) sbp
          | t == msgBaselineEcef = SBPMsgBaselineEcef (decode (fromStrict p)) sbp
          | t == msgBaselineNed = SBPMsgBaselineNed (decode (fromStrict p)) sbp
          | t == msgBootloaderHandshakeDepA = SBPMsgBootloaderHandshakeDepA (decode (fromStrict p)) sbp
          | t == msgBootloaderHandshakeReq = SBPMsgBootloaderHandshakeReq (decode (fromStrict p)) sbp
          | t == msgBootloaderHandshakeResp = SBPMsgBootloaderHandshakeResp (decode (fromStrict p)) sbp
          | t == msgBootloaderJumpToApp = SBPMsgBootloaderJumpToApp (decode (fromStrict p)) sbp
          | t == msgCwResults = SBPMsgCwResults (decode (fromStrict p)) sbp
          | t == msgCwStart = SBPMsgCwStart (decode (fromStrict p)) sbp
          | t == msgDops = SBPMsgDops (decode (fromStrict p)) sbp
          | t == msgEphemeris = SBPMsgEphemeris (decode (fromStrict p)) sbp
          | t == msgEphemerisDepA = SBPMsgEphemerisDepA (decode (fromStrict p)) sbp
          | t == msgEphemerisDepB = SBPMsgEphemerisDepB (decode (fromStrict p)) sbp
          | t == msgExtEvent = SBPMsgExtEvent (decode (fromStrict p)) sbp
          | t == msgFileioReadDirReq = SBPMsgFileioReadDirReq (decode (fromStrict p)) sbp
          | t == msgFileioReadDirResp = SBPMsgFileioReadDirResp (decode (fromStrict p)) sbp
          | t == msgFileioReadReq = SBPMsgFileioReadReq (decode (fromStrict p)) sbp
          | t == msgFileioReadResp = SBPMsgFileioReadResp (decode (fromStrict p)) sbp
          | t == msgFileioRemove = SBPMsgFileioRemove (decode (fromStrict p)) sbp
          | t == msgFileioWriteReq = SBPMsgFileioWriteReq (decode (fromStrict p)) sbp
          | t == msgFileioWriteResp = SBPMsgFileioWriteResp (decode (fromStrict p)) sbp
          | t == msgFlashDone = SBPMsgFlashDone (decode (fromStrict p)) sbp
          | t == msgFlashErase = SBPMsgFlashErase (decode (fromStrict p)) sbp
          | t == msgFlashProgram = SBPMsgFlashProgram (decode (fromStrict p)) sbp
          | t == msgFlashReadReq = SBPMsgFlashReadReq (decode (fromStrict p)) sbp
          | t == msgFlashReadResp = SBPMsgFlashReadResp (decode (fromStrict p)) sbp
          | t == msgGpsTime = SBPMsgGpsTime (decode (fromStrict p)) sbp
          | t == msgHeartbeat = SBPMsgHeartbeat (decode (fromStrict p)) sbp
          | t == msgIarState = SBPMsgIarState (decode (fromStrict p)) sbp
          | t == msgInitBase = SBPMsgInitBase (decode (fromStrict p)) sbp
          | t == msgLog = SBPMsgLog (decode (fromStrict p)) sbp
          | t == msgM25FlashWriteStatus = SBPMsgM25FlashWriteStatus (decode (fromStrict p)) sbp
          | t == msgMaskSatellite = SBPMsgMaskSatellite (decode (fromStrict p)) sbp
          | t == msgNapDeviceDnaReq = SBPMsgNapDeviceDnaReq (decode (fromStrict p)) sbp
          | t == msgNapDeviceDnaResp = SBPMsgNapDeviceDnaResp (decode (fromStrict p)) sbp
          | t == msgObs = SBPMsgObs (decode (fromStrict p)) sbp
          | t == msgObsDepA = SBPMsgObsDepA (decode (fromStrict p)) sbp
          | t == msgPosEcef = SBPMsgPosEcef (decode (fromStrict p)) sbp
          | t == msgPosLlh = SBPMsgPosLlh (decode (fromStrict p)) sbp
          | t == msgPrintDep = SBPMsgPrintDep (decode (fromStrict p)) sbp
          | t == msgReset = SBPMsgReset (decode (fromStrict p)) sbp
          | t == msgResetFilters = SBPMsgResetFilters (decode (fromStrict p)) sbp
          | t == msgSetTime = SBPMsgSetTime (decode (fromStrict p)) sbp
          | t == msgSettingsReadByIndexDone = SBPMsgSettingsReadByIndexDone (decode (fromStrict p)) sbp
          | t == msgSettingsReadByIndexReq = SBPMsgSettingsReadByIndexReq (decode (fromStrict p)) sbp
          | t == msgSettingsReadByIndexResp = SBPMsgSettingsReadByIndexResp (decode (fromStrict p)) sbp
          | t == msgSettingsReadReq = SBPMsgSettingsReadReq (decode (fromStrict p)) sbp
          | t == msgSettingsReadResp = SBPMsgSettingsReadResp (decode (fromStrict p)) sbp
          | t == msgSettingsSave = SBPMsgSettingsSave (decode (fromStrict p)) sbp
          | t == msgSettingsWrite = SBPMsgSettingsWrite (decode (fromStrict p)) sbp
          | t == msgStartup = SBPMsgStartup (decode (fromStrict p)) sbp
          | t == msgStmFlashLockSector = SBPMsgStmFlashLockSector (decode (fromStrict p)) sbp
          | t == msgStmFlashUnlockSector = SBPMsgStmFlashUnlockSector (decode (fromStrict p)) sbp
          | t == msgStmUniqueIdReq = SBPMsgStmUniqueIdReq (decode (fromStrict p)) sbp
          | t == msgStmUniqueIdResp = SBPMsgStmUniqueIdResp (decode (fromStrict p)) sbp
          | t == msgThreadState = SBPMsgThreadState (decode (fromStrict p)) sbp
          | t == msgTrackingIq = SBPMsgTrackingIq (decode (fromStrict p)) sbp
          | t == msgTrackingState = SBPMsgTrackingState (decode (fromStrict p)) sbp
          | t == msgTrackingStateDepA = SBPMsgTrackingStateDepA (decode (fromStrict p)) sbp
          | t == msgTweet = SBPMsgTweet (decode (fromStrict p)) sbp
          | t == msgUartState = SBPMsgUartState (decode (fromStrict p)) sbp
          | t == msgVelEcef = SBPMsgVelEcef (decode (fromStrict p)) sbp
          | t == msgVelNed = SBPMsgVelNed (decode (fromStrict p)) sbp
          | otherwise = SBPMsgUnknown sbp

  put msg = do
    putWord8 msgPreamble
    put $ t msg
    where
      t (SBPMsgAcqResult _ sbp) = sbp
      t (SBPMsgAcqResultDepA _ sbp) = sbp
      t (SBPMsgAlmanac _ sbp) = sbp
      t (SBPMsgBasePos _ sbp) = sbp
      t (SBPMsgBaselineEcef _ sbp) = sbp
      t (SBPMsgBaselineNed _ sbp) = sbp
      t (SBPMsgBootloaderHandshakeDepA _ sbp) = sbp
      t (SBPMsgBootloaderHandshakeReq _ sbp) = sbp
      t (SBPMsgBootloaderHandshakeResp _ sbp) = sbp
      t (SBPMsgBootloaderJumpToApp _ sbp) = sbp
      t (SBPMsgCwResults _ sbp) = sbp
      t (SBPMsgCwStart _ sbp) = sbp
      t (SBPMsgDops _ sbp) = sbp
      t (SBPMsgEphemeris _ sbp) = sbp
      t (SBPMsgEphemerisDepA _ sbp) = sbp
      t (SBPMsgEphemerisDepB _ sbp) = sbp
      t (SBPMsgExtEvent _ sbp) = sbp
      t (SBPMsgFileioReadDirReq _ sbp) = sbp
      t (SBPMsgFileioReadDirResp _ sbp) = sbp
      t (SBPMsgFileioReadReq _ sbp) = sbp
      t (SBPMsgFileioReadResp _ sbp) = sbp
      t (SBPMsgFileioRemove _ sbp) = sbp
      t (SBPMsgFileioWriteReq _ sbp) = sbp
      t (SBPMsgFileioWriteResp _ sbp) = sbp
      t (SBPMsgFlashDone _ sbp) = sbp
      t (SBPMsgFlashErase _ sbp) = sbp
      t (SBPMsgFlashProgram _ sbp) = sbp
      t (SBPMsgFlashReadReq _ sbp) = sbp
      t (SBPMsgFlashReadResp _ sbp) = sbp
      t (SBPMsgGpsTime _ sbp) = sbp
      t (SBPMsgHeartbeat _ sbp) = sbp
      t (SBPMsgIarState _ sbp) = sbp
      t (SBPMsgInitBase _ sbp) = sbp
      t (SBPMsgLog _ sbp) = sbp
      t (SBPMsgM25FlashWriteStatus _ sbp) = sbp
      t (SBPMsgMaskSatellite _ sbp) = sbp
      t (SBPMsgNapDeviceDnaReq _ sbp) = sbp
      t (SBPMsgNapDeviceDnaResp _ sbp) = sbp
      t (SBPMsgObs _ sbp) = sbp
      t (SBPMsgObsDepA _ sbp) = sbp
      t (SBPMsgPosEcef _ sbp) = sbp
      t (SBPMsgPosLlh _ sbp) = sbp
      t (SBPMsgPrintDep _ sbp) = sbp
      t (SBPMsgReset _ sbp) = sbp
      t (SBPMsgResetFilters _ sbp) = sbp
      t (SBPMsgSetTime _ sbp) = sbp
      t (SBPMsgSettingsReadByIndexDone _ sbp) = sbp
      t (SBPMsgSettingsReadByIndexReq _ sbp) = sbp
      t (SBPMsgSettingsReadByIndexResp _ sbp) = sbp
      t (SBPMsgSettingsReadReq _ sbp) = sbp
      t (SBPMsgSettingsReadResp _ sbp) = sbp
      t (SBPMsgSettingsSave _ sbp) = sbp
      t (SBPMsgSettingsWrite _ sbp) = sbp
      t (SBPMsgStartup _ sbp) = sbp
      t (SBPMsgStmFlashLockSector _ sbp) = sbp
      t (SBPMsgStmFlashUnlockSector _ sbp) = sbp
      t (SBPMsgStmUniqueIdReq _ sbp) = sbp
      t (SBPMsgStmUniqueIdResp _ sbp) = sbp
      t (SBPMsgThreadState _ sbp) = sbp
      t (SBPMsgTrackingIq _ sbp) = sbp
      t (SBPMsgTrackingState _ sbp) = sbp
      t (SBPMsgTrackingStateDepA _ sbp) = sbp
      t (SBPMsgTweet _ sbp) = sbp
      t (SBPMsgUartState _ sbp) = sbp
      t (SBPMsgVelEcef _ sbp) = sbp
      t (SBPMsgVelNed _ sbp) = sbp
      t (SBPMsgUnknown sbp) = sbp