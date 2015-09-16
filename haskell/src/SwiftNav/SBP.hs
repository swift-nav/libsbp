-- |
-- Module:      SwiftNav.SBP
-- Copyright:   Copyright (C) 2015 Swift Navigation, Inc.
-- License:     LGPL-3
-- Maintainer:  Mark Fine <dev@swiftnav.com>
-- Stability:   experimental
-- Portability: portable
--
-- SBP message containers and serialization utilities.

module SwiftNav.SBP where

import BasicPrelude hiding (lookup)
import Data.Aeson hiding (decode)
import Data.Binary
import Data.Binary.Get
import Data.Binary.Put
import Data.ByteString
import Data.ByteString.Lazy hiding (ByteString)
import Data.ByteString.Builder
import Data.HashMap.Strict
import Data.Scientific
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

msgPreamble :: Word8
msgPreamble = 0x55

-- | Default sender ID. Intended for messages sent from the host to
-- the device.
defaultSenderID :: Word16
defaultSenderID = 0x42

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

instance FromJSON Msg where
  parseJSON (Object v) = do
    Msg <$> v .: "msg_type"
        <*> v .: "sender"
        <*> v .: "length"
        <*> v .: "payload"
        <*> v .: "crc"
  parseJSON _ = mzero

instance ToJSON Msg where
  toJSON Msg {..} = object [ "preamble" .= msgPreamble
                           , "msg_type" .= msgSBPType
                           , "sender" .= msgSBPSender
                           , "length" .= msgSBPLen
                           , "payload" .= msgSBPPayload
                           , "crc" .= msgSBPCrc
                           ]

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
   | SBPMsgBadCrc Msg
   | SBPMsgUnknown Msg
  deriving ( Show, Read, Eq )

instance Binary SBPMsg where
  get = do
    preamble <- getWord8
    if preamble /= msgPreamble then get else do
      sbp <- get
      return $ decode' sbp where
        decode' sbp@Msg {..}
          | checkCrc sbp /= msgSBPCrc = SBPMsgBadCrc sbp
          | msgSBPType == msgAcqResult = SBPMsgAcqResult (decode (fromStrict msgSBPPayload)) sbp
          | msgSBPType == msgAcqResultDepA = SBPMsgAcqResultDepA (decode (fromStrict msgSBPPayload)) sbp
          | msgSBPType == msgAlmanac = SBPMsgAlmanac (decode (fromStrict msgSBPPayload)) sbp
          | msgSBPType == msgBasePos = SBPMsgBasePos (decode (fromStrict msgSBPPayload)) sbp
          | msgSBPType == msgBaselineEcef = SBPMsgBaselineEcef (decode (fromStrict msgSBPPayload)) sbp
          | msgSBPType == msgBaselineNed = SBPMsgBaselineNed (decode (fromStrict msgSBPPayload)) sbp
          | msgSBPType == msgBootloaderHandshakeDepA = SBPMsgBootloaderHandshakeDepA (decode (fromStrict msgSBPPayload)) sbp
          | msgSBPType == msgBootloaderHandshakeReq = SBPMsgBootloaderHandshakeReq (decode (fromStrict msgSBPPayload)) sbp
          | msgSBPType == msgBootloaderHandshakeResp = SBPMsgBootloaderHandshakeResp (decode (fromStrict msgSBPPayload)) sbp
          | msgSBPType == msgBootloaderJumpToApp = SBPMsgBootloaderJumpToApp (decode (fromStrict msgSBPPayload)) sbp
          | msgSBPType == msgCwResults = SBPMsgCwResults (decode (fromStrict msgSBPPayload)) sbp
          | msgSBPType == msgCwStart = SBPMsgCwStart (decode (fromStrict msgSBPPayload)) sbp
          | msgSBPType == msgDops = SBPMsgDops (decode (fromStrict msgSBPPayload)) sbp
          | msgSBPType == msgEphemeris = SBPMsgEphemeris (decode (fromStrict msgSBPPayload)) sbp
          | msgSBPType == msgEphemerisDepA = SBPMsgEphemerisDepA (decode (fromStrict msgSBPPayload)) sbp
          | msgSBPType == msgEphemerisDepB = SBPMsgEphemerisDepB (decode (fromStrict msgSBPPayload)) sbp
          | msgSBPType == msgExtEvent = SBPMsgExtEvent (decode (fromStrict msgSBPPayload)) sbp
          | msgSBPType == msgFileioReadDirReq = SBPMsgFileioReadDirReq (decode (fromStrict msgSBPPayload)) sbp
          | msgSBPType == msgFileioReadDirResp = SBPMsgFileioReadDirResp (decode (fromStrict msgSBPPayload)) sbp
          | msgSBPType == msgFileioReadReq = SBPMsgFileioReadReq (decode (fromStrict msgSBPPayload)) sbp
          | msgSBPType == msgFileioReadResp = SBPMsgFileioReadResp (decode (fromStrict msgSBPPayload)) sbp
          | msgSBPType == msgFileioRemove = SBPMsgFileioRemove (decode (fromStrict msgSBPPayload)) sbp
          | msgSBPType == msgFileioWriteReq = SBPMsgFileioWriteReq (decode (fromStrict msgSBPPayload)) sbp
          | msgSBPType == msgFileioWriteResp = SBPMsgFileioWriteResp (decode (fromStrict msgSBPPayload)) sbp
          | msgSBPType == msgFlashDone = SBPMsgFlashDone (decode (fromStrict msgSBPPayload)) sbp
          | msgSBPType == msgFlashErase = SBPMsgFlashErase (decode (fromStrict msgSBPPayload)) sbp
          | msgSBPType == msgFlashProgram = SBPMsgFlashProgram (decode (fromStrict msgSBPPayload)) sbp
          | msgSBPType == msgFlashReadReq = SBPMsgFlashReadReq (decode (fromStrict msgSBPPayload)) sbp
          | msgSBPType == msgFlashReadResp = SBPMsgFlashReadResp (decode (fromStrict msgSBPPayload)) sbp
          | msgSBPType == msgGpsTime = SBPMsgGpsTime (decode (fromStrict msgSBPPayload)) sbp
          | msgSBPType == msgHeartbeat = SBPMsgHeartbeat (decode (fromStrict msgSBPPayload)) sbp
          | msgSBPType == msgIarState = SBPMsgIarState (decode (fromStrict msgSBPPayload)) sbp
          | msgSBPType == msgInitBase = SBPMsgInitBase (decode (fromStrict msgSBPPayload)) sbp
          | msgSBPType == msgLog = SBPMsgLog (decode (fromStrict msgSBPPayload)) sbp
          | msgSBPType == msgM25FlashWriteStatus = SBPMsgM25FlashWriteStatus (decode (fromStrict msgSBPPayload)) sbp
          | msgSBPType == msgMaskSatellite = SBPMsgMaskSatellite (decode (fromStrict msgSBPPayload)) sbp
          | msgSBPType == msgNapDeviceDnaReq = SBPMsgNapDeviceDnaReq (decode (fromStrict msgSBPPayload)) sbp
          | msgSBPType == msgNapDeviceDnaResp = SBPMsgNapDeviceDnaResp (decode (fromStrict msgSBPPayload)) sbp
          | msgSBPType == msgObs = SBPMsgObs (decode (fromStrict msgSBPPayload)) sbp
          | msgSBPType == msgObsDepA = SBPMsgObsDepA (decode (fromStrict msgSBPPayload)) sbp
          | msgSBPType == msgPosEcef = SBPMsgPosEcef (decode (fromStrict msgSBPPayload)) sbp
          | msgSBPType == msgPosLlh = SBPMsgPosLlh (decode (fromStrict msgSBPPayload)) sbp
          | msgSBPType == msgPrintDep = SBPMsgPrintDep (decode (fromStrict msgSBPPayload)) sbp
          | msgSBPType == msgReset = SBPMsgReset (decode (fromStrict msgSBPPayload)) sbp
          | msgSBPType == msgResetFilters = SBPMsgResetFilters (decode (fromStrict msgSBPPayload)) sbp
          | msgSBPType == msgSetTime = SBPMsgSetTime (decode (fromStrict msgSBPPayload)) sbp
          | msgSBPType == msgSettingsReadByIndexDone = SBPMsgSettingsReadByIndexDone (decode (fromStrict msgSBPPayload)) sbp
          | msgSBPType == msgSettingsReadByIndexReq = SBPMsgSettingsReadByIndexReq (decode (fromStrict msgSBPPayload)) sbp
          | msgSBPType == msgSettingsReadByIndexResp = SBPMsgSettingsReadByIndexResp (decode (fromStrict msgSBPPayload)) sbp
          | msgSBPType == msgSettingsReadReq = SBPMsgSettingsReadReq (decode (fromStrict msgSBPPayload)) sbp
          | msgSBPType == msgSettingsReadResp = SBPMsgSettingsReadResp (decode (fromStrict msgSBPPayload)) sbp
          | msgSBPType == msgSettingsSave = SBPMsgSettingsSave (decode (fromStrict msgSBPPayload)) sbp
          | msgSBPType == msgSettingsWrite = SBPMsgSettingsWrite (decode (fromStrict msgSBPPayload)) sbp
          | msgSBPType == msgStartup = SBPMsgStartup (decode (fromStrict msgSBPPayload)) sbp
          | msgSBPType == msgStmFlashLockSector = SBPMsgStmFlashLockSector (decode (fromStrict msgSBPPayload)) sbp
          | msgSBPType == msgStmFlashUnlockSector = SBPMsgStmFlashUnlockSector (decode (fromStrict msgSBPPayload)) sbp
          | msgSBPType == msgStmUniqueIdReq = SBPMsgStmUniqueIdReq (decode (fromStrict msgSBPPayload)) sbp
          | msgSBPType == msgStmUniqueIdResp = SBPMsgStmUniqueIdResp (decode (fromStrict msgSBPPayload)) sbp
          | msgSBPType == msgThreadState = SBPMsgThreadState (decode (fromStrict msgSBPPayload)) sbp
          | msgSBPType == msgTrackingIq = SBPMsgTrackingIq (decode (fromStrict msgSBPPayload)) sbp
          | msgSBPType == msgTrackingState = SBPMsgTrackingState (decode (fromStrict msgSBPPayload)) sbp
          | msgSBPType == msgTrackingStateDepA = SBPMsgTrackingStateDepA (decode (fromStrict msgSBPPayload)) sbp
          | msgSBPType == msgTweet = SBPMsgTweet (decode (fromStrict msgSBPPayload)) sbp
          | msgSBPType == msgUartState = SBPMsgUartState (decode (fromStrict msgSBPPayload)) sbp
          | msgSBPType == msgVelEcef = SBPMsgVelEcef (decode (fromStrict msgSBPPayload)) sbp
          | msgSBPType == msgVelNed = SBPMsgVelNed (decode (fromStrict msgSBPPayload)) sbp
          | otherwise = SBPMsgUnknown sbp

  put msg = do
    putWord8 msgPreamble
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
      encode' (SBPMsgBadCrc  sbp) = sbp

instance FromJSON SBPMsg where
  parseJSON (Object o) = case lookup "msg_type" o of
    Nothing         -> mzero
    Just (Number msgType) -> decode' (toBoundedInteger msgType) where
                               decode' Nothing = mzero
                               decode' (Just t)
                                 | t == msgAcqResult = SBPMsgAcqResult <$> parseJSON (Object o) <*> parseJSON (Object o)
                                 | t == msgAcqResultDepA = SBPMsgAcqResultDepA <$> parseJSON (Object o) <*> parseJSON (Object o)
                                 | t == msgAlmanac = SBPMsgAlmanac <$> parseJSON (Object o) <*> parseJSON (Object o)
                                 | t == msgBasePos = SBPMsgBasePos <$> parseJSON (Object o) <*> parseJSON (Object o)
                                 | t == msgBaselineEcef = SBPMsgBaselineEcef <$> parseJSON (Object o) <*> parseJSON (Object o)
                                 | t == msgBaselineNed = SBPMsgBaselineNed <$> parseJSON (Object o) <*> parseJSON (Object o)
                                 | t == msgBootloaderHandshakeDepA = SBPMsgBootloaderHandshakeDepA <$> parseJSON (Object o) <*> parseJSON (Object o)
                                 | t == msgBootloaderHandshakeReq = SBPMsgBootloaderHandshakeReq <$> parseJSON (Object o) <*> parseJSON (Object o)
                                 | t == msgBootloaderHandshakeResp = SBPMsgBootloaderHandshakeResp <$> parseJSON (Object o) <*> parseJSON (Object o)
                                 | t == msgBootloaderJumpToApp = SBPMsgBootloaderJumpToApp <$> parseJSON (Object o) <*> parseJSON (Object o)
                                 | t == msgCwResults = SBPMsgCwResults <$> parseJSON (Object o) <*> parseJSON (Object o)
                                 | t == msgCwStart = SBPMsgCwStart <$> parseJSON (Object o) <*> parseJSON (Object o)
                                 | t == msgDops = SBPMsgDops <$> parseJSON (Object o) <*> parseJSON (Object o)
                                 | t == msgEphemeris = SBPMsgEphemeris <$> parseJSON (Object o) <*> parseJSON (Object o)
                                 | t == msgEphemerisDepA = SBPMsgEphemerisDepA <$> parseJSON (Object o) <*> parseJSON (Object o)
                                 | t == msgEphemerisDepB = SBPMsgEphemerisDepB <$> parseJSON (Object o) <*> parseJSON (Object o)
                                 | t == msgExtEvent = SBPMsgExtEvent <$> parseJSON (Object o) <*> parseJSON (Object o)
                                 | t == msgFileioReadDirReq = SBPMsgFileioReadDirReq <$> parseJSON (Object o) <*> parseJSON (Object o)
                                 | t == msgFileioReadDirResp = SBPMsgFileioReadDirResp <$> parseJSON (Object o) <*> parseJSON (Object o)
                                 | t == msgFileioReadReq = SBPMsgFileioReadReq <$> parseJSON (Object o) <*> parseJSON (Object o)
                                 | t == msgFileioReadResp = SBPMsgFileioReadResp <$> parseJSON (Object o) <*> parseJSON (Object o)
                                 | t == msgFileioRemove = SBPMsgFileioRemove <$> parseJSON (Object o) <*> parseJSON (Object o)
                                 | t == msgFileioWriteReq = SBPMsgFileioWriteReq <$> parseJSON (Object o) <*> parseJSON (Object o)
                                 | t == msgFileioWriteResp = SBPMsgFileioWriteResp <$> parseJSON (Object o) <*> parseJSON (Object o)
                                 | t == msgFlashDone = SBPMsgFlashDone <$> parseJSON (Object o) <*> parseJSON (Object o)
                                 | t == msgFlashErase = SBPMsgFlashErase <$> parseJSON (Object o) <*> parseJSON (Object o)
                                 | t == msgFlashProgram = SBPMsgFlashProgram <$> parseJSON (Object o) <*> parseJSON (Object o)
                                 | t == msgFlashReadReq = SBPMsgFlashReadReq <$> parseJSON (Object o) <*> parseJSON (Object o)
                                 | t == msgFlashReadResp = SBPMsgFlashReadResp <$> parseJSON (Object o) <*> parseJSON (Object o)
                                 | t == msgGpsTime = SBPMsgGpsTime <$> parseJSON (Object o) <*> parseJSON (Object o)
                                 | t == msgHeartbeat = SBPMsgHeartbeat <$> parseJSON (Object o) <*> parseJSON (Object o)
                                 | t == msgIarState = SBPMsgIarState <$> parseJSON (Object o) <*> parseJSON (Object o)
                                 | t == msgInitBase = SBPMsgInitBase <$> parseJSON (Object o) <*> parseJSON (Object o)
                                 | t == msgLog = SBPMsgLog <$> parseJSON (Object o) <*> parseJSON (Object o)
                                 | t == msgM25FlashWriteStatus = SBPMsgM25FlashWriteStatus <$> parseJSON (Object o) <*> parseJSON (Object o)
                                 | t == msgMaskSatellite = SBPMsgMaskSatellite <$> parseJSON (Object o) <*> parseJSON (Object o)
                                 | t == msgNapDeviceDnaReq = SBPMsgNapDeviceDnaReq <$> parseJSON (Object o) <*> parseJSON (Object o)
                                 | t == msgNapDeviceDnaResp = SBPMsgNapDeviceDnaResp <$> parseJSON (Object o) <*> parseJSON (Object o)
                                 | t == msgObs = SBPMsgObs <$> parseJSON (Object o) <*> parseJSON (Object o)
                                 | t == msgObsDepA = SBPMsgObsDepA <$> parseJSON (Object o) <*> parseJSON (Object o)
                                 | t == msgPosEcef = SBPMsgPosEcef <$> parseJSON (Object o) <*> parseJSON (Object o)
                                 | t == msgPosLlh = SBPMsgPosLlh <$> parseJSON (Object o) <*> parseJSON (Object o)
                                 | t == msgPrintDep = SBPMsgPrintDep <$> parseJSON (Object o) <*> parseJSON (Object o)
                                 | t == msgReset = SBPMsgReset <$> parseJSON (Object o) <*> parseJSON (Object o)
                                 | t == msgResetFilters = SBPMsgResetFilters <$> parseJSON (Object o) <*> parseJSON (Object o)
                                 | t == msgSetTime = SBPMsgSetTime <$> parseJSON (Object o) <*> parseJSON (Object o)
                                 | t == msgSettingsReadByIndexDone = SBPMsgSettingsReadByIndexDone <$> parseJSON (Object o) <*> parseJSON (Object o)
                                 | t == msgSettingsReadByIndexReq = SBPMsgSettingsReadByIndexReq <$> parseJSON (Object o) <*> parseJSON (Object o)
                                 | t == msgSettingsReadByIndexResp = SBPMsgSettingsReadByIndexResp <$> parseJSON (Object o) <*> parseJSON (Object o)
                                 | t == msgSettingsReadReq = SBPMsgSettingsReadReq <$> parseJSON (Object o) <*> parseJSON (Object o)
                                 | t == msgSettingsReadResp = SBPMsgSettingsReadResp <$> parseJSON (Object o) <*> parseJSON (Object o)
                                 | t == msgSettingsSave = SBPMsgSettingsSave <$> parseJSON (Object o) <*> parseJSON (Object o)
                                 | t == msgSettingsWrite = SBPMsgSettingsWrite <$> parseJSON (Object o) <*> parseJSON (Object o)
                                 | t == msgStartup = SBPMsgStartup <$> parseJSON (Object o) <*> parseJSON (Object o)
                                 | t == msgStmFlashLockSector = SBPMsgStmFlashLockSector <$> parseJSON (Object o) <*> parseJSON (Object o)
                                 | t == msgStmFlashUnlockSector = SBPMsgStmFlashUnlockSector <$> parseJSON (Object o) <*> parseJSON (Object o)
                                 | t == msgStmUniqueIdReq = SBPMsgStmUniqueIdReq <$> parseJSON (Object o) <*> parseJSON (Object o)
                                 | t == msgStmUniqueIdResp = SBPMsgStmUniqueIdResp <$> parseJSON (Object o) <*> parseJSON (Object o)
                                 | t == msgThreadState = SBPMsgThreadState <$> parseJSON (Object o) <*> parseJSON (Object o)
                                 | t == msgTrackingIq = SBPMsgTrackingIq <$> parseJSON (Object o) <*> parseJSON (Object o)
                                 | t == msgTrackingState = SBPMsgTrackingState <$> parseJSON (Object o) <*> parseJSON (Object o)
                                 | t == msgTrackingStateDepA = SBPMsgTrackingStateDepA <$> parseJSON (Object o) <*> parseJSON (Object o)
                                 | t == msgTweet = SBPMsgTweet <$> parseJSON (Object o) <*> parseJSON (Object o)
                                 | t == msgUartState = SBPMsgUartState <$> parseJSON (Object o) <*> parseJSON (Object o)
                                 | t == msgVelEcef = SBPMsgVelEcef <$> parseJSON (Object o) <*> parseJSON (Object o)
                                 | t == msgVelNed = SBPMsgVelNed <$> parseJSON (Object o) <*> parseJSON (Object o)
                                 | otherwise = SBPMsgUnknown <$> parseJSON (Object o)
    Just _ -> mzero
  parseJSON (_) = mzero

merge :: Value -> Value -> Value
merge (Object one) (Object two) = Object $ one <> two
merge _ _ = undefined

instance ToJSON SBPMsg where
   toJSON (SBPMsgAcqResult msg sbp) = merge (toJSON msg) (toJSON sbp)
   toJSON (SBPMsgAcqResultDepA msg sbp) = merge (toJSON msg) (toJSON sbp)
   toJSON (SBPMsgAlmanac msg sbp) = merge (toJSON msg) (toJSON sbp)
   toJSON (SBPMsgBasePos msg sbp) = merge (toJSON msg) (toJSON sbp)
   toJSON (SBPMsgBaselineEcef msg sbp) = merge (toJSON msg) (toJSON sbp)
   toJSON (SBPMsgBaselineNed msg sbp) = merge (toJSON msg) (toJSON sbp)
   toJSON (SBPMsgBootloaderHandshakeDepA msg sbp) = merge (toJSON msg) (toJSON sbp)
   toJSON (SBPMsgBootloaderHandshakeReq msg sbp) = merge (toJSON msg) (toJSON sbp)
   toJSON (SBPMsgBootloaderHandshakeResp msg sbp) = merge (toJSON msg) (toJSON sbp)
   toJSON (SBPMsgBootloaderJumpToApp msg sbp) = merge (toJSON msg) (toJSON sbp)
   toJSON (SBPMsgCwResults msg sbp) = merge (toJSON msg) (toJSON sbp)
   toJSON (SBPMsgCwStart msg sbp) = merge (toJSON msg) (toJSON sbp)
   toJSON (SBPMsgDops msg sbp) = merge (toJSON msg) (toJSON sbp)
   toJSON (SBPMsgEphemeris msg sbp) = merge (toJSON msg) (toJSON sbp)
   toJSON (SBPMsgEphemerisDepA msg sbp) = merge (toJSON msg) (toJSON sbp)
   toJSON (SBPMsgEphemerisDepB msg sbp) = merge (toJSON msg) (toJSON sbp)
   toJSON (SBPMsgExtEvent msg sbp) = merge (toJSON msg) (toJSON sbp)
   toJSON (SBPMsgFileioReadDirReq msg sbp) = merge (toJSON msg) (toJSON sbp)
   toJSON (SBPMsgFileioReadDirResp msg sbp) = merge (toJSON msg) (toJSON sbp)
   toJSON (SBPMsgFileioReadReq msg sbp) = merge (toJSON msg) (toJSON sbp)
   toJSON (SBPMsgFileioReadResp msg sbp) = merge (toJSON msg) (toJSON sbp)
   toJSON (SBPMsgFileioRemove msg sbp) = merge (toJSON msg) (toJSON sbp)
   toJSON (SBPMsgFileioWriteReq msg sbp) = merge (toJSON msg) (toJSON sbp)
   toJSON (SBPMsgFileioWriteResp msg sbp) = merge (toJSON msg) (toJSON sbp)
   toJSON (SBPMsgFlashDone msg sbp) = merge (toJSON msg) (toJSON sbp)
   toJSON (SBPMsgFlashErase msg sbp) = merge (toJSON msg) (toJSON sbp)
   toJSON (SBPMsgFlashProgram msg sbp) = merge (toJSON msg) (toJSON sbp)
   toJSON (SBPMsgFlashReadReq msg sbp) = merge (toJSON msg) (toJSON sbp)
   toJSON (SBPMsgFlashReadResp msg sbp) = merge (toJSON msg) (toJSON sbp)
   toJSON (SBPMsgGpsTime msg sbp) = merge (toJSON msg) (toJSON sbp)
   toJSON (SBPMsgHeartbeat msg sbp) = merge (toJSON msg) (toJSON sbp)
   toJSON (SBPMsgIarState msg sbp) = merge (toJSON msg) (toJSON sbp)
   toJSON (SBPMsgInitBase msg sbp) = merge (toJSON msg) (toJSON sbp)
   toJSON (SBPMsgLog msg sbp) = merge (toJSON msg) (toJSON sbp)
   toJSON (SBPMsgM25FlashWriteStatus msg sbp) = merge (toJSON msg) (toJSON sbp)
   toJSON (SBPMsgMaskSatellite msg sbp) = merge (toJSON msg) (toJSON sbp)
   toJSON (SBPMsgNapDeviceDnaReq msg sbp) = merge (toJSON msg) (toJSON sbp)
   toJSON (SBPMsgNapDeviceDnaResp msg sbp) = merge (toJSON msg) (toJSON sbp)
   toJSON (SBPMsgObs msg sbp) = merge (toJSON msg) (toJSON sbp)
   toJSON (SBPMsgObsDepA msg sbp) = merge (toJSON msg) (toJSON sbp)
   toJSON (SBPMsgPosEcef msg sbp) = merge (toJSON msg) (toJSON sbp)
   toJSON (SBPMsgPosLlh msg sbp) = merge (toJSON msg) (toJSON sbp)
   toJSON (SBPMsgPrintDep msg sbp) = merge (toJSON msg) (toJSON sbp)
   toJSON (SBPMsgReset msg sbp) = merge (toJSON msg) (toJSON sbp)
   toJSON (SBPMsgResetFilters msg sbp) = merge (toJSON msg) (toJSON sbp)
   toJSON (SBPMsgSetTime msg sbp) = merge (toJSON msg) (toJSON sbp)
   toJSON (SBPMsgSettingsReadByIndexDone msg sbp) = merge (toJSON msg) (toJSON sbp)
   toJSON (SBPMsgSettingsReadByIndexReq msg sbp) = merge (toJSON msg) (toJSON sbp)
   toJSON (SBPMsgSettingsReadByIndexResp msg sbp) = merge (toJSON msg) (toJSON sbp)
   toJSON (SBPMsgSettingsReadReq msg sbp) = merge (toJSON msg) (toJSON sbp)
   toJSON (SBPMsgSettingsReadResp msg sbp) = merge (toJSON msg) (toJSON sbp)
   toJSON (SBPMsgSettingsSave msg sbp) = merge (toJSON msg) (toJSON sbp)
   toJSON (SBPMsgSettingsWrite msg sbp) = merge (toJSON msg) (toJSON sbp)
   toJSON (SBPMsgStartup msg sbp) = merge (toJSON msg) (toJSON sbp)
   toJSON (SBPMsgStmFlashLockSector msg sbp) = merge (toJSON msg) (toJSON sbp)
   toJSON (SBPMsgStmFlashUnlockSector msg sbp) = merge (toJSON msg) (toJSON sbp)
   toJSON (SBPMsgStmUniqueIdReq msg sbp) = merge (toJSON msg) (toJSON sbp)
   toJSON (SBPMsgStmUniqueIdResp msg sbp) = merge (toJSON msg) (toJSON sbp)
   toJSON (SBPMsgThreadState msg sbp) = merge (toJSON msg) (toJSON sbp)
   toJSON (SBPMsgTrackingIq msg sbp) = merge (toJSON msg) (toJSON sbp)
   toJSON (SBPMsgTrackingState msg sbp) = merge (toJSON msg) (toJSON sbp)
   toJSON (SBPMsgTrackingStateDepA msg sbp) = merge (toJSON msg) (toJSON sbp)
   toJSON (SBPMsgTweet msg sbp) = merge (toJSON msg) (toJSON sbp)
   toJSON (SBPMsgUartState msg sbp) = merge (toJSON msg) (toJSON sbp)
   toJSON (SBPMsgVelEcef msg sbp) = merge (toJSON msg) (toJSON sbp)
   toJSON (SBPMsgVelNed msg sbp) = merge (toJSON msg) (toJSON sbp)
   toJSON (SBPMsgBadCrc sbp) = toJSON sbp
   toJSON (SBPMsgUnknown sbp) = toJSON sbp