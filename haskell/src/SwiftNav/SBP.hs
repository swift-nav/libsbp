-- |
-- Module:      SwiftNav.SBP
-- Copyright:   Copyright (C) 2015 Swift Navigation, Inc.
-- License:     LGPL-3
-- Maintainer:  Mark Fine <dev@swiftnav.com>
-- Stability:   experimental
-- Portability: portable
--
-- SBP message containers.

module SwiftNav.SBP
  ( SBPMsg (..)
  , module SwiftNav.SBP.Types
  , module SwiftNav.SBP.Acquisition
  , module SwiftNav.SBP.Bootload
  , module SwiftNav.SBP.ExtEvents
  , module SwiftNav.SBP.FileIo
  , module SwiftNav.SBP.Flash
  , module SwiftNav.SBP.GnssSignal
  , module SwiftNav.SBP.Logging
  , module SwiftNav.SBP.Navigation
  , module SwiftNav.SBP.Observation
  , module SwiftNav.SBP.Piksi
  , module SwiftNav.SBP.Settings
  , module SwiftNav.SBP.System
  , module SwiftNav.SBP.Tracking
  , module SwiftNav.SBP.User
  ) where

import BasicPrelude             hiding (lookup)
import Control.Lens             hiding ((.=))
import Data.Aeson               hiding (decode, decode')
import Data.Binary
import Data.ByteString.Lazy     hiding (ByteString)
import SwiftNav.SBP.Acquisition
import SwiftNav.SBP.Bootload
import SwiftNav.SBP.ExtEvents
import SwiftNav.SBP.FileIo
import SwiftNav.SBP.Flash
import SwiftNav.SBP.GnssSignal
import SwiftNav.SBP.Logging
import SwiftNav.SBP.Navigation
import SwiftNav.SBP.Observation
import SwiftNav.SBP.Piksi
import SwiftNav.SBP.Settings
import SwiftNav.SBP.System
import SwiftNav.SBP.Tracking
import SwiftNav.SBP.User
import SwiftNav.SBP.Types


-- | An SBP message ADT composed of all defined SBP messages.
--
-- Includes SBPMsgUnknown for valid SBP messages with undefined message
-- types and SBPMsgBadCRC for SBP messages with invalid CRC checksums.
data SBPMsg =
     SBPMsgAcqResult MsgAcqResult Msg
   | SBPMsgAcqResultDepA MsgAcqResultDepA Msg
   | SBPMsgAlmanac MsgAlmanac Msg
   | SBPMsgBasePosEcef MsgBasePosEcef Msg
   | SBPMsgBasePosLlh MsgBasePosLlh Msg
   | SBPMsgBaselineEcef MsgBaselineEcef Msg
   | SBPMsgBaselineHeading MsgBaselineHeading Msg
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
   | SBPMsgEphemerisDepC MsgEphemerisDepC Msg
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
   | SBPMsgObsDepB MsgObsDepB Msg
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
   | SBPMsgSettingsRegister MsgSettingsRegister Msg
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
   | SBPMsgUartStateDepa MsgUartStateDepa Msg
   | SBPMsgUserData MsgUserData Msg
   | SBPMsgVelEcef MsgVelEcef Msg
   | SBPMsgVelNed MsgVelNed Msg
   | SBPMsgBadCrc Msg
   | SBPMsgUnknown Msg
  deriving ( Show, Read, Eq )

$(makePrisms ''SBPMsg)

instance Binary SBPMsg where
  get = do
    preamble <- getWord8
    if preamble /= msgSBPPreamble then get else do
      decode' <$> get where
        decode' m@Msg {..}
          | checkCrc m /= _msgSBPCrc = SBPMsgBadCrc m
          | _msgSBPType == msgAcqResult = SBPMsgAcqResult (decode (fromStrict _msgSBPPayload)) m
          | _msgSBPType == msgAcqResultDepA = SBPMsgAcqResultDepA (decode (fromStrict _msgSBPPayload)) m
          | _msgSBPType == msgAlmanac = SBPMsgAlmanac (decode (fromStrict _msgSBPPayload)) m
          | _msgSBPType == msgBasePosEcef = SBPMsgBasePosEcef (decode (fromStrict _msgSBPPayload)) m
          | _msgSBPType == msgBasePosLlh = SBPMsgBasePosLlh (decode (fromStrict _msgSBPPayload)) m
          | _msgSBPType == msgBaselineEcef = SBPMsgBaselineEcef (decode (fromStrict _msgSBPPayload)) m
          | _msgSBPType == msgBaselineHeading = SBPMsgBaselineHeading (decode (fromStrict _msgSBPPayload)) m
          | _msgSBPType == msgBaselineNed = SBPMsgBaselineNed (decode (fromStrict _msgSBPPayload)) m
          | _msgSBPType == msgBootloaderHandshakeDepA = SBPMsgBootloaderHandshakeDepA (decode (fromStrict _msgSBPPayload)) m
          | _msgSBPType == msgBootloaderHandshakeReq = SBPMsgBootloaderHandshakeReq (decode (fromStrict _msgSBPPayload)) m
          | _msgSBPType == msgBootloaderHandshakeResp = SBPMsgBootloaderHandshakeResp (decode (fromStrict _msgSBPPayload)) m
          | _msgSBPType == msgBootloaderJumpToApp = SBPMsgBootloaderJumpToApp (decode (fromStrict _msgSBPPayload)) m
          | _msgSBPType == msgCwResults = SBPMsgCwResults (decode (fromStrict _msgSBPPayload)) m
          | _msgSBPType == msgCwStart = SBPMsgCwStart (decode (fromStrict _msgSBPPayload)) m
          | _msgSBPType == msgDops = SBPMsgDops (decode (fromStrict _msgSBPPayload)) m
          | _msgSBPType == msgEphemeris = SBPMsgEphemeris (decode (fromStrict _msgSBPPayload)) m
          | _msgSBPType == msgEphemerisDepA = SBPMsgEphemerisDepA (decode (fromStrict _msgSBPPayload)) m
          | _msgSBPType == msgEphemerisDepB = SBPMsgEphemerisDepB (decode (fromStrict _msgSBPPayload)) m
          | _msgSBPType == msgEphemerisDepC = SBPMsgEphemerisDepC (decode (fromStrict _msgSBPPayload)) m
          | _msgSBPType == msgExtEvent = SBPMsgExtEvent (decode (fromStrict _msgSBPPayload)) m
          | _msgSBPType == msgFileioReadDirReq = SBPMsgFileioReadDirReq (decode (fromStrict _msgSBPPayload)) m
          | _msgSBPType == msgFileioReadDirResp = SBPMsgFileioReadDirResp (decode (fromStrict _msgSBPPayload)) m
          | _msgSBPType == msgFileioReadReq = SBPMsgFileioReadReq (decode (fromStrict _msgSBPPayload)) m
          | _msgSBPType == msgFileioReadResp = SBPMsgFileioReadResp (decode (fromStrict _msgSBPPayload)) m
          | _msgSBPType == msgFileioRemove = SBPMsgFileioRemove (decode (fromStrict _msgSBPPayload)) m
          | _msgSBPType == msgFileioWriteReq = SBPMsgFileioWriteReq (decode (fromStrict _msgSBPPayload)) m
          | _msgSBPType == msgFileioWriteResp = SBPMsgFileioWriteResp (decode (fromStrict _msgSBPPayload)) m
          | _msgSBPType == msgFlashDone = SBPMsgFlashDone (decode (fromStrict _msgSBPPayload)) m
          | _msgSBPType == msgFlashErase = SBPMsgFlashErase (decode (fromStrict _msgSBPPayload)) m
          | _msgSBPType == msgFlashProgram = SBPMsgFlashProgram (decode (fromStrict _msgSBPPayload)) m
          | _msgSBPType == msgFlashReadReq = SBPMsgFlashReadReq (decode (fromStrict _msgSBPPayload)) m
          | _msgSBPType == msgFlashReadResp = SBPMsgFlashReadResp (decode (fromStrict _msgSBPPayload)) m
          | _msgSBPType == msgGpsTime = SBPMsgGpsTime (decode (fromStrict _msgSBPPayload)) m
          | _msgSBPType == msgHeartbeat = SBPMsgHeartbeat (decode (fromStrict _msgSBPPayload)) m
          | _msgSBPType == msgIarState = SBPMsgIarState (decode (fromStrict _msgSBPPayload)) m
          | _msgSBPType == msgInitBase = SBPMsgInitBase (decode (fromStrict _msgSBPPayload)) m
          | _msgSBPType == msgLog = SBPMsgLog (decode (fromStrict _msgSBPPayload)) m
          | _msgSBPType == msgM25FlashWriteStatus = SBPMsgM25FlashWriteStatus (decode (fromStrict _msgSBPPayload)) m
          | _msgSBPType == msgMaskSatellite = SBPMsgMaskSatellite (decode (fromStrict _msgSBPPayload)) m
          | _msgSBPType == msgNapDeviceDnaReq = SBPMsgNapDeviceDnaReq (decode (fromStrict _msgSBPPayload)) m
          | _msgSBPType == msgNapDeviceDnaResp = SBPMsgNapDeviceDnaResp (decode (fromStrict _msgSBPPayload)) m
          | _msgSBPType == msgObs = SBPMsgObs (decode (fromStrict _msgSBPPayload)) m
          | _msgSBPType == msgObsDepA = SBPMsgObsDepA (decode (fromStrict _msgSBPPayload)) m
          | _msgSBPType == msgObsDepB = SBPMsgObsDepB (decode (fromStrict _msgSBPPayload)) m
          | _msgSBPType == msgPosEcef = SBPMsgPosEcef (decode (fromStrict _msgSBPPayload)) m
          | _msgSBPType == msgPosLlh = SBPMsgPosLlh (decode (fromStrict _msgSBPPayload)) m
          | _msgSBPType == msgPrintDep = SBPMsgPrintDep (decode (fromStrict _msgSBPPayload)) m
          | _msgSBPType == msgReset = SBPMsgReset (decode (fromStrict _msgSBPPayload)) m
          | _msgSBPType == msgResetFilters = SBPMsgResetFilters (decode (fromStrict _msgSBPPayload)) m
          | _msgSBPType == msgSetTime = SBPMsgSetTime (decode (fromStrict _msgSBPPayload)) m
          | _msgSBPType == msgSettingsReadByIndexDone = SBPMsgSettingsReadByIndexDone (decode (fromStrict _msgSBPPayload)) m
          | _msgSBPType == msgSettingsReadByIndexReq = SBPMsgSettingsReadByIndexReq (decode (fromStrict _msgSBPPayload)) m
          | _msgSBPType == msgSettingsReadByIndexResp = SBPMsgSettingsReadByIndexResp (decode (fromStrict _msgSBPPayload)) m
          | _msgSBPType == msgSettingsReadReq = SBPMsgSettingsReadReq (decode (fromStrict _msgSBPPayload)) m
          | _msgSBPType == msgSettingsReadResp = SBPMsgSettingsReadResp (decode (fromStrict _msgSBPPayload)) m
          | _msgSBPType == msgSettingsRegister = SBPMsgSettingsRegister (decode (fromStrict _msgSBPPayload)) m
          | _msgSBPType == msgSettingsSave = SBPMsgSettingsSave (decode (fromStrict _msgSBPPayload)) m
          | _msgSBPType == msgSettingsWrite = SBPMsgSettingsWrite (decode (fromStrict _msgSBPPayload)) m
          | _msgSBPType == msgStartup = SBPMsgStartup (decode (fromStrict _msgSBPPayload)) m
          | _msgSBPType == msgStmFlashLockSector = SBPMsgStmFlashLockSector (decode (fromStrict _msgSBPPayload)) m
          | _msgSBPType == msgStmFlashUnlockSector = SBPMsgStmFlashUnlockSector (decode (fromStrict _msgSBPPayload)) m
          | _msgSBPType == msgStmUniqueIdReq = SBPMsgStmUniqueIdReq (decode (fromStrict _msgSBPPayload)) m
          | _msgSBPType == msgStmUniqueIdResp = SBPMsgStmUniqueIdResp (decode (fromStrict _msgSBPPayload)) m
          | _msgSBPType == msgThreadState = SBPMsgThreadState (decode (fromStrict _msgSBPPayload)) m
          | _msgSBPType == msgTrackingIq = SBPMsgTrackingIq (decode (fromStrict _msgSBPPayload)) m
          | _msgSBPType == msgTrackingState = SBPMsgTrackingState (decode (fromStrict _msgSBPPayload)) m
          | _msgSBPType == msgTrackingStateDepA = SBPMsgTrackingStateDepA (decode (fromStrict _msgSBPPayload)) m
          | _msgSBPType == msgTweet = SBPMsgTweet (decode (fromStrict _msgSBPPayload)) m
          | _msgSBPType == msgUartState = SBPMsgUartState (decode (fromStrict _msgSBPPayload)) m
          | _msgSBPType == msgUartStateDepa = SBPMsgUartStateDepa (decode (fromStrict _msgSBPPayload)) m
          | _msgSBPType == msgUserData = SBPMsgUserData (decode (fromStrict _msgSBPPayload)) m
          | _msgSBPType == msgVelEcef = SBPMsgVelEcef (decode (fromStrict _msgSBPPayload)) m
          | _msgSBPType == msgVelNed = SBPMsgVelNed (decode (fromStrict _msgSBPPayload)) m
          | otherwise = SBPMsgUnknown m

  put sm = do
    putWord8 msgSBPPreamble
    encode' sm where
      encode' (SBPMsgAcqResult _ m) = put m
      encode' (SBPMsgAcqResultDepA _ m) = put m
      encode' (SBPMsgAlmanac _ m) = put m
      encode' (SBPMsgBasePosEcef _ m) = put m
      encode' (SBPMsgBasePosLlh _ m) = put m
      encode' (SBPMsgBaselineEcef _ m) = put m
      encode' (SBPMsgBaselineHeading _ m) = put m
      encode' (SBPMsgBaselineNed _ m) = put m
      encode' (SBPMsgBootloaderHandshakeDepA _ m) = put m
      encode' (SBPMsgBootloaderHandshakeReq _ m) = put m
      encode' (SBPMsgBootloaderHandshakeResp _ m) = put m
      encode' (SBPMsgBootloaderJumpToApp _ m) = put m
      encode' (SBPMsgCwResults _ m) = put m
      encode' (SBPMsgCwStart _ m) = put m
      encode' (SBPMsgDops _ m) = put m
      encode' (SBPMsgEphemeris _ m) = put m
      encode' (SBPMsgEphemerisDepA _ m) = put m
      encode' (SBPMsgEphemerisDepB _ m) = put m
      encode' (SBPMsgEphemerisDepC _ m) = put m
      encode' (SBPMsgExtEvent _ m) = put m
      encode' (SBPMsgFileioReadDirReq _ m) = put m
      encode' (SBPMsgFileioReadDirResp _ m) = put m
      encode' (SBPMsgFileioReadReq _ m) = put m
      encode' (SBPMsgFileioReadResp _ m) = put m
      encode' (SBPMsgFileioRemove _ m) = put m
      encode' (SBPMsgFileioWriteReq _ m) = put m
      encode' (SBPMsgFileioWriteResp _ m) = put m
      encode' (SBPMsgFlashDone _ m) = put m
      encode' (SBPMsgFlashErase _ m) = put m
      encode' (SBPMsgFlashProgram _ m) = put m
      encode' (SBPMsgFlashReadReq _ m) = put m
      encode' (SBPMsgFlashReadResp _ m) = put m
      encode' (SBPMsgGpsTime _ m) = put m
      encode' (SBPMsgHeartbeat _ m) = put m
      encode' (SBPMsgIarState _ m) = put m
      encode' (SBPMsgInitBase _ m) = put m
      encode' (SBPMsgLog _ m) = put m
      encode' (SBPMsgM25FlashWriteStatus _ m) = put m
      encode' (SBPMsgMaskSatellite _ m) = put m
      encode' (SBPMsgNapDeviceDnaReq _ m) = put m
      encode' (SBPMsgNapDeviceDnaResp _ m) = put m
      encode' (SBPMsgObs _ m) = put m
      encode' (SBPMsgObsDepA _ m) = put m
      encode' (SBPMsgObsDepB _ m) = put m
      encode' (SBPMsgPosEcef _ m) = put m
      encode' (SBPMsgPosLlh _ m) = put m
      encode' (SBPMsgPrintDep _ m) = put m
      encode' (SBPMsgReset _ m) = put m
      encode' (SBPMsgResetFilters _ m) = put m
      encode' (SBPMsgSetTime _ m) = put m
      encode' (SBPMsgSettingsReadByIndexDone _ m) = put m
      encode' (SBPMsgSettingsReadByIndexReq _ m) = put m
      encode' (SBPMsgSettingsReadByIndexResp _ m) = put m
      encode' (SBPMsgSettingsReadReq _ m) = put m
      encode' (SBPMsgSettingsReadResp _ m) = put m
      encode' (SBPMsgSettingsRegister _ m) = put m
      encode' (SBPMsgSettingsSave _ m) = put m
      encode' (SBPMsgSettingsWrite _ m) = put m
      encode' (SBPMsgStartup _ m) = put m
      encode' (SBPMsgStmFlashLockSector _ m) = put m
      encode' (SBPMsgStmFlashUnlockSector _ m) = put m
      encode' (SBPMsgStmUniqueIdReq _ m) = put m
      encode' (SBPMsgStmUniqueIdResp _ m) = put m
      encode' (SBPMsgThreadState _ m) = put m
      encode' (SBPMsgTrackingIq _ m) = put m
      encode' (SBPMsgTrackingState _ m) = put m
      encode' (SBPMsgTrackingStateDepA _ m) = put m
      encode' (SBPMsgTweet _ m) = put m
      encode' (SBPMsgUartState _ m) = put m
      encode' (SBPMsgUartStateDepa _ m) = put m
      encode' (SBPMsgUserData _ m) = put m
      encode' (SBPMsgVelEcef _ m) = put m
      encode' (SBPMsgVelNed _ m) = put m
      encode' (SBPMsgUnknown m) = put m
      encode' (SBPMsgBadCrc m) = put m

instance FromJSON SBPMsg where
  parseJSON obj@(Object o) = do
    msgType <- o .: "msg_type"
    decode' msgType where
      decode' msgType
        | msgType == msgAcqResult = SBPMsgAcqResult <$> parseJSON obj <*> parseJSON obj
        | msgType == msgAcqResultDepA = SBPMsgAcqResultDepA <$> parseJSON obj <*> parseJSON obj
        | msgType == msgAlmanac = SBPMsgAlmanac <$> parseJSON obj <*> parseJSON obj
        | msgType == msgBasePosEcef = SBPMsgBasePosEcef <$> parseJSON obj <*> parseJSON obj
        | msgType == msgBasePosLlh = SBPMsgBasePosLlh <$> parseJSON obj <*> parseJSON obj
        | msgType == msgBaselineEcef = SBPMsgBaselineEcef <$> parseJSON obj <*> parseJSON obj
        | msgType == msgBaselineHeading = SBPMsgBaselineHeading <$> parseJSON obj <*> parseJSON obj
        | msgType == msgBaselineNed = SBPMsgBaselineNed <$> parseJSON obj <*> parseJSON obj
        | msgType == msgBootloaderHandshakeDepA = SBPMsgBootloaderHandshakeDepA <$> parseJSON obj <*> parseJSON obj
        | msgType == msgBootloaderHandshakeReq = SBPMsgBootloaderHandshakeReq <$> parseJSON obj <*> parseJSON obj
        | msgType == msgBootloaderHandshakeResp = SBPMsgBootloaderHandshakeResp <$> parseJSON obj <*> parseJSON obj
        | msgType == msgBootloaderJumpToApp = SBPMsgBootloaderJumpToApp <$> parseJSON obj <*> parseJSON obj
        | msgType == msgCwResults = SBPMsgCwResults <$> parseJSON obj <*> parseJSON obj
        | msgType == msgCwStart = SBPMsgCwStart <$> parseJSON obj <*> parseJSON obj
        | msgType == msgDops = SBPMsgDops <$> parseJSON obj <*> parseJSON obj
        | msgType == msgEphemeris = SBPMsgEphemeris <$> parseJSON obj <*> parseJSON obj
        | msgType == msgEphemerisDepA = SBPMsgEphemerisDepA <$> parseJSON obj <*> parseJSON obj
        | msgType == msgEphemerisDepB = SBPMsgEphemerisDepB <$> parseJSON obj <*> parseJSON obj
        | msgType == msgEphemerisDepC = SBPMsgEphemerisDepC <$> parseJSON obj <*> parseJSON obj
        | msgType == msgExtEvent = SBPMsgExtEvent <$> parseJSON obj <*> parseJSON obj
        | msgType == msgFileioReadDirReq = SBPMsgFileioReadDirReq <$> parseJSON obj <*> parseJSON obj
        | msgType == msgFileioReadDirResp = SBPMsgFileioReadDirResp <$> parseJSON obj <*> parseJSON obj
        | msgType == msgFileioReadReq = SBPMsgFileioReadReq <$> parseJSON obj <*> parseJSON obj
        | msgType == msgFileioReadResp = SBPMsgFileioReadResp <$> parseJSON obj <*> parseJSON obj
        | msgType == msgFileioRemove = SBPMsgFileioRemove <$> parseJSON obj <*> parseJSON obj
        | msgType == msgFileioWriteReq = SBPMsgFileioWriteReq <$> parseJSON obj <*> parseJSON obj
        | msgType == msgFileioWriteResp = SBPMsgFileioWriteResp <$> parseJSON obj <*> parseJSON obj
        | msgType == msgFlashDone = SBPMsgFlashDone <$> parseJSON obj <*> parseJSON obj
        | msgType == msgFlashErase = SBPMsgFlashErase <$> parseJSON obj <*> parseJSON obj
        | msgType == msgFlashProgram = SBPMsgFlashProgram <$> parseJSON obj <*> parseJSON obj
        | msgType == msgFlashReadReq = SBPMsgFlashReadReq <$> parseJSON obj <*> parseJSON obj
        | msgType == msgFlashReadResp = SBPMsgFlashReadResp <$> parseJSON obj <*> parseJSON obj
        | msgType == msgGpsTime = SBPMsgGpsTime <$> parseJSON obj <*> parseJSON obj
        | msgType == msgHeartbeat = SBPMsgHeartbeat <$> parseJSON obj <*> parseJSON obj
        | msgType == msgIarState = SBPMsgIarState <$> parseJSON obj <*> parseJSON obj
        | msgType == msgInitBase = SBPMsgInitBase <$> parseJSON obj <*> parseJSON obj
        | msgType == msgLog = SBPMsgLog <$> parseJSON obj <*> parseJSON obj
        | msgType == msgM25FlashWriteStatus = SBPMsgM25FlashWriteStatus <$> parseJSON obj <*> parseJSON obj
        | msgType == msgMaskSatellite = SBPMsgMaskSatellite <$> parseJSON obj <*> parseJSON obj
        | msgType == msgNapDeviceDnaReq = SBPMsgNapDeviceDnaReq <$> parseJSON obj <*> parseJSON obj
        | msgType == msgNapDeviceDnaResp = SBPMsgNapDeviceDnaResp <$> parseJSON obj <*> parseJSON obj
        | msgType == msgObs = SBPMsgObs <$> parseJSON obj <*> parseJSON obj
        | msgType == msgObsDepA = SBPMsgObsDepA <$> parseJSON obj <*> parseJSON obj
        | msgType == msgObsDepB = SBPMsgObsDepB <$> parseJSON obj <*> parseJSON obj
        | msgType == msgPosEcef = SBPMsgPosEcef <$> parseJSON obj <*> parseJSON obj
        | msgType == msgPosLlh = SBPMsgPosLlh <$> parseJSON obj <*> parseJSON obj
        | msgType == msgPrintDep = SBPMsgPrintDep <$> parseJSON obj <*> parseJSON obj
        | msgType == msgReset = SBPMsgReset <$> parseJSON obj <*> parseJSON obj
        | msgType == msgResetFilters = SBPMsgResetFilters <$> parseJSON obj <*> parseJSON obj
        | msgType == msgSetTime = SBPMsgSetTime <$> parseJSON obj <*> parseJSON obj
        | msgType == msgSettingsReadByIndexDone = SBPMsgSettingsReadByIndexDone <$> parseJSON obj <*> parseJSON obj
        | msgType == msgSettingsReadByIndexReq = SBPMsgSettingsReadByIndexReq <$> parseJSON obj <*> parseJSON obj
        | msgType == msgSettingsReadByIndexResp = SBPMsgSettingsReadByIndexResp <$> parseJSON obj <*> parseJSON obj
        | msgType == msgSettingsReadReq = SBPMsgSettingsReadReq <$> parseJSON obj <*> parseJSON obj
        | msgType == msgSettingsReadResp = SBPMsgSettingsReadResp <$> parseJSON obj <*> parseJSON obj
        | msgType == msgSettingsRegister = SBPMsgSettingsRegister <$> parseJSON obj <*> parseJSON obj
        | msgType == msgSettingsSave = SBPMsgSettingsSave <$> parseJSON obj <*> parseJSON obj
        | msgType == msgSettingsWrite = SBPMsgSettingsWrite <$> parseJSON obj <*> parseJSON obj
        | msgType == msgStartup = SBPMsgStartup <$> parseJSON obj <*> parseJSON obj
        | msgType == msgStmFlashLockSector = SBPMsgStmFlashLockSector <$> parseJSON obj <*> parseJSON obj
        | msgType == msgStmFlashUnlockSector = SBPMsgStmFlashUnlockSector <$> parseJSON obj <*> parseJSON obj
        | msgType == msgStmUniqueIdReq = SBPMsgStmUniqueIdReq <$> parseJSON obj <*> parseJSON obj
        | msgType == msgStmUniqueIdResp = SBPMsgStmUniqueIdResp <$> parseJSON obj <*> parseJSON obj
        | msgType == msgThreadState = SBPMsgThreadState <$> parseJSON obj <*> parseJSON obj
        | msgType == msgTrackingIq = SBPMsgTrackingIq <$> parseJSON obj <*> parseJSON obj
        | msgType == msgTrackingState = SBPMsgTrackingState <$> parseJSON obj <*> parseJSON obj
        | msgType == msgTrackingStateDepA = SBPMsgTrackingStateDepA <$> parseJSON obj <*> parseJSON obj
        | msgType == msgTweet = SBPMsgTweet <$> parseJSON obj <*> parseJSON obj
        | msgType == msgUartState = SBPMsgUartState <$> parseJSON obj <*> parseJSON obj
        | msgType == msgUartStateDepa = SBPMsgUartStateDepa <$> parseJSON obj <*> parseJSON obj
        | msgType == msgUserData = SBPMsgUserData <$> parseJSON obj <*> parseJSON obj
        | msgType == msgVelEcef = SBPMsgVelEcef <$> parseJSON obj <*> parseJSON obj
        | msgType == msgVelNed = SBPMsgVelNed <$> parseJSON obj <*> parseJSON obj
        | otherwise = SBPMsgUnknown <$> parseJSON obj
  parseJSON _ = mzero

mergeValues :: Value -> Value -> Value
mergeValues (Object a) (Object b) = Object (a <> b)
mergeValues (Object a) _          = Object a
mergeValues _          (Object b) = Object b
mergeValues _          v          = v

instance ToJSON SBPMsg where
  toJSON (SBPMsgAcqResult n m) = toJSON n `mergeValues` toJSON m
  toJSON (SBPMsgAcqResultDepA n m) = toJSON n `mergeValues` toJSON m
  toJSON (SBPMsgAlmanac n m) = toJSON n `mergeValues` toJSON m
  toJSON (SBPMsgBasePosEcef n m) = toJSON n `mergeValues` toJSON m
  toJSON (SBPMsgBasePosLlh n m) = toJSON n `mergeValues` toJSON m
  toJSON (SBPMsgBaselineEcef n m) = toJSON n `mergeValues` toJSON m
  toJSON (SBPMsgBaselineHeading n m) = toJSON n `mergeValues` toJSON m
  toJSON (SBPMsgBaselineNed n m) = toJSON n `mergeValues` toJSON m
  toJSON (SBPMsgBootloaderHandshakeDepA n m) = toJSON n `mergeValues` toJSON m
  toJSON (SBPMsgBootloaderHandshakeReq n m) = toJSON n `mergeValues` toJSON m
  toJSON (SBPMsgBootloaderHandshakeResp n m) = toJSON n `mergeValues` toJSON m
  toJSON (SBPMsgBootloaderJumpToApp n m) = toJSON n `mergeValues` toJSON m
  toJSON (SBPMsgCwResults n m) = toJSON n `mergeValues` toJSON m
  toJSON (SBPMsgCwStart n m) = toJSON n `mergeValues` toJSON m
  toJSON (SBPMsgDops n m) = toJSON n `mergeValues` toJSON m
  toJSON (SBPMsgEphemeris n m) = toJSON n `mergeValues` toJSON m
  toJSON (SBPMsgEphemerisDepA n m) = toJSON n `mergeValues` toJSON m
  toJSON (SBPMsgEphemerisDepB n m) = toJSON n `mergeValues` toJSON m
  toJSON (SBPMsgEphemerisDepC n m) = toJSON n `mergeValues` toJSON m
  toJSON (SBPMsgExtEvent n m) = toJSON n `mergeValues` toJSON m
  toJSON (SBPMsgFileioReadDirReq n m) = toJSON n `mergeValues` toJSON m
  toJSON (SBPMsgFileioReadDirResp n m) = toJSON n `mergeValues` toJSON m
  toJSON (SBPMsgFileioReadReq n m) = toJSON n `mergeValues` toJSON m
  toJSON (SBPMsgFileioReadResp n m) = toJSON n `mergeValues` toJSON m
  toJSON (SBPMsgFileioRemove n m) = toJSON n `mergeValues` toJSON m
  toJSON (SBPMsgFileioWriteReq n m) = toJSON n `mergeValues` toJSON m
  toJSON (SBPMsgFileioWriteResp n m) = toJSON n `mergeValues` toJSON m
  toJSON (SBPMsgFlashDone n m) = toJSON n `mergeValues` toJSON m
  toJSON (SBPMsgFlashErase n m) = toJSON n `mergeValues` toJSON m
  toJSON (SBPMsgFlashProgram n m) = toJSON n `mergeValues` toJSON m
  toJSON (SBPMsgFlashReadReq n m) = toJSON n `mergeValues` toJSON m
  toJSON (SBPMsgFlashReadResp n m) = toJSON n `mergeValues` toJSON m
  toJSON (SBPMsgGpsTime n m) = toJSON n `mergeValues` toJSON m
  toJSON (SBPMsgHeartbeat n m) = toJSON n `mergeValues` toJSON m
  toJSON (SBPMsgIarState n m) = toJSON n `mergeValues` toJSON m
  toJSON (SBPMsgInitBase n m) = toJSON n `mergeValues` toJSON m
  toJSON (SBPMsgLog n m) = toJSON n `mergeValues` toJSON m
  toJSON (SBPMsgM25FlashWriteStatus n m) = toJSON n `mergeValues` toJSON m
  toJSON (SBPMsgMaskSatellite n m) = toJSON n `mergeValues` toJSON m
  toJSON (SBPMsgNapDeviceDnaReq n m) = toJSON n `mergeValues` toJSON m
  toJSON (SBPMsgNapDeviceDnaResp n m) = toJSON n `mergeValues` toJSON m
  toJSON (SBPMsgObs n m) = toJSON n `mergeValues` toJSON m
  toJSON (SBPMsgObsDepA n m) = toJSON n `mergeValues` toJSON m
  toJSON (SBPMsgObsDepB n m) = toJSON n `mergeValues` toJSON m
  toJSON (SBPMsgPosEcef n m) = toJSON n `mergeValues` toJSON m
  toJSON (SBPMsgPosLlh n m) = toJSON n `mergeValues` toJSON m
  toJSON (SBPMsgPrintDep n m) = toJSON n `mergeValues` toJSON m
  toJSON (SBPMsgReset n m) = toJSON n `mergeValues` toJSON m
  toJSON (SBPMsgResetFilters n m) = toJSON n `mergeValues` toJSON m
  toJSON (SBPMsgSetTime n m) = toJSON n `mergeValues` toJSON m
  toJSON (SBPMsgSettingsReadByIndexDone n m) = toJSON n `mergeValues` toJSON m
  toJSON (SBPMsgSettingsReadByIndexReq n m) = toJSON n `mergeValues` toJSON m
  toJSON (SBPMsgSettingsReadByIndexResp n m) = toJSON n `mergeValues` toJSON m
  toJSON (SBPMsgSettingsReadReq n m) = toJSON n `mergeValues` toJSON m
  toJSON (SBPMsgSettingsReadResp n m) = toJSON n `mergeValues` toJSON m
  toJSON (SBPMsgSettingsRegister n m) = toJSON n `mergeValues` toJSON m
  toJSON (SBPMsgSettingsSave n m) = toJSON n `mergeValues` toJSON m
  toJSON (SBPMsgSettingsWrite n m) = toJSON n `mergeValues` toJSON m
  toJSON (SBPMsgStartup n m) = toJSON n `mergeValues` toJSON m
  toJSON (SBPMsgStmFlashLockSector n m) = toJSON n `mergeValues` toJSON m
  toJSON (SBPMsgStmFlashUnlockSector n m) = toJSON n `mergeValues` toJSON m
  toJSON (SBPMsgStmUniqueIdReq n m) = toJSON n `mergeValues` toJSON m
  toJSON (SBPMsgStmUniqueIdResp n m) = toJSON n `mergeValues` toJSON m
  toJSON (SBPMsgThreadState n m) = toJSON n `mergeValues` toJSON m
  toJSON (SBPMsgTrackingIq n m) = toJSON n `mergeValues` toJSON m
  toJSON (SBPMsgTrackingState n m) = toJSON n `mergeValues` toJSON m
  toJSON (SBPMsgTrackingStateDepA n m) = toJSON n `mergeValues` toJSON m
  toJSON (SBPMsgTweet n m) = toJSON n `mergeValues` toJSON m
  toJSON (SBPMsgUartState n m) = toJSON n `mergeValues` toJSON m
  toJSON (SBPMsgUartStateDepa n m) = toJSON n `mergeValues` toJSON m
  toJSON (SBPMsgUserData n m) = toJSON n `mergeValues` toJSON m
  toJSON (SBPMsgVelEcef n m) = toJSON n `mergeValues` toJSON m
  toJSON (SBPMsgVelNed n m) = toJSON n `mergeValues` toJSON m
  toJSON (SBPMsgBadCrc m) = toJSON m
  toJSON (SBPMsgUnknown m) = toJSON m

instance HasMsg SBPMsg where
  msg f (SBPMsgAcqResult n m) = SBPMsgAcqResult n <$> f m
  msg f (SBPMsgAcqResultDepA n m) = SBPMsgAcqResultDepA n <$> f m
  msg f (SBPMsgAlmanac n m) = SBPMsgAlmanac n <$> f m
  msg f (SBPMsgBasePosEcef n m) = SBPMsgBasePosEcef n <$> f m
  msg f (SBPMsgBasePosLlh n m) = SBPMsgBasePosLlh n <$> f m
  msg f (SBPMsgBaselineEcef n m) = SBPMsgBaselineEcef n <$> f m
  msg f (SBPMsgBaselineHeading n m) = SBPMsgBaselineHeading n <$> f m
  msg f (SBPMsgBaselineNed n m) = SBPMsgBaselineNed n <$> f m
  msg f (SBPMsgBootloaderHandshakeDepA n m) = SBPMsgBootloaderHandshakeDepA n <$> f m
  msg f (SBPMsgBootloaderHandshakeReq n m) = SBPMsgBootloaderHandshakeReq n <$> f m
  msg f (SBPMsgBootloaderHandshakeResp n m) = SBPMsgBootloaderHandshakeResp n <$> f m
  msg f (SBPMsgBootloaderJumpToApp n m) = SBPMsgBootloaderJumpToApp n <$> f m
  msg f (SBPMsgCwResults n m) = SBPMsgCwResults n <$> f m
  msg f (SBPMsgCwStart n m) = SBPMsgCwStart n <$> f m
  msg f (SBPMsgDops n m) = SBPMsgDops n <$> f m
  msg f (SBPMsgEphemeris n m) = SBPMsgEphemeris n <$> f m
  msg f (SBPMsgEphemerisDepA n m) = SBPMsgEphemerisDepA n <$> f m
  msg f (SBPMsgEphemerisDepB n m) = SBPMsgEphemerisDepB n <$> f m
  msg f (SBPMsgEphemerisDepC n m) = SBPMsgEphemerisDepC n <$> f m
  msg f (SBPMsgExtEvent n m) = SBPMsgExtEvent n <$> f m
  msg f (SBPMsgFileioReadDirReq n m) = SBPMsgFileioReadDirReq n <$> f m
  msg f (SBPMsgFileioReadDirResp n m) = SBPMsgFileioReadDirResp n <$> f m
  msg f (SBPMsgFileioReadReq n m) = SBPMsgFileioReadReq n <$> f m
  msg f (SBPMsgFileioReadResp n m) = SBPMsgFileioReadResp n <$> f m
  msg f (SBPMsgFileioRemove n m) = SBPMsgFileioRemove n <$> f m
  msg f (SBPMsgFileioWriteReq n m) = SBPMsgFileioWriteReq n <$> f m
  msg f (SBPMsgFileioWriteResp n m) = SBPMsgFileioWriteResp n <$> f m
  msg f (SBPMsgFlashDone n m) = SBPMsgFlashDone n <$> f m
  msg f (SBPMsgFlashErase n m) = SBPMsgFlashErase n <$> f m
  msg f (SBPMsgFlashProgram n m) = SBPMsgFlashProgram n <$> f m
  msg f (SBPMsgFlashReadReq n m) = SBPMsgFlashReadReq n <$> f m
  msg f (SBPMsgFlashReadResp n m) = SBPMsgFlashReadResp n <$> f m
  msg f (SBPMsgGpsTime n m) = SBPMsgGpsTime n <$> f m
  msg f (SBPMsgHeartbeat n m) = SBPMsgHeartbeat n <$> f m
  msg f (SBPMsgIarState n m) = SBPMsgIarState n <$> f m
  msg f (SBPMsgInitBase n m) = SBPMsgInitBase n <$> f m
  msg f (SBPMsgLog n m) = SBPMsgLog n <$> f m
  msg f (SBPMsgM25FlashWriteStatus n m) = SBPMsgM25FlashWriteStatus n <$> f m
  msg f (SBPMsgMaskSatellite n m) = SBPMsgMaskSatellite n <$> f m
  msg f (SBPMsgNapDeviceDnaReq n m) = SBPMsgNapDeviceDnaReq n <$> f m
  msg f (SBPMsgNapDeviceDnaResp n m) = SBPMsgNapDeviceDnaResp n <$> f m
  msg f (SBPMsgObs n m) = SBPMsgObs n <$> f m
  msg f (SBPMsgObsDepA n m) = SBPMsgObsDepA n <$> f m
  msg f (SBPMsgObsDepB n m) = SBPMsgObsDepB n <$> f m
  msg f (SBPMsgPosEcef n m) = SBPMsgPosEcef n <$> f m
  msg f (SBPMsgPosLlh n m) = SBPMsgPosLlh n <$> f m
  msg f (SBPMsgPrintDep n m) = SBPMsgPrintDep n <$> f m
  msg f (SBPMsgReset n m) = SBPMsgReset n <$> f m
  msg f (SBPMsgResetFilters n m) = SBPMsgResetFilters n <$> f m
  msg f (SBPMsgSetTime n m) = SBPMsgSetTime n <$> f m
  msg f (SBPMsgSettingsReadByIndexDone n m) = SBPMsgSettingsReadByIndexDone n <$> f m
  msg f (SBPMsgSettingsReadByIndexReq n m) = SBPMsgSettingsReadByIndexReq n <$> f m
  msg f (SBPMsgSettingsReadByIndexResp n m) = SBPMsgSettingsReadByIndexResp n <$> f m
  msg f (SBPMsgSettingsReadReq n m) = SBPMsgSettingsReadReq n <$> f m
  msg f (SBPMsgSettingsReadResp n m) = SBPMsgSettingsReadResp n <$> f m
  msg f (SBPMsgSettingsRegister n m) = SBPMsgSettingsRegister n <$> f m
  msg f (SBPMsgSettingsSave n m) = SBPMsgSettingsSave n <$> f m
  msg f (SBPMsgSettingsWrite n m) = SBPMsgSettingsWrite n <$> f m
  msg f (SBPMsgStartup n m) = SBPMsgStartup n <$> f m
  msg f (SBPMsgStmFlashLockSector n m) = SBPMsgStmFlashLockSector n <$> f m
  msg f (SBPMsgStmFlashUnlockSector n m) = SBPMsgStmFlashUnlockSector n <$> f m
  msg f (SBPMsgStmUniqueIdReq n m) = SBPMsgStmUniqueIdReq n <$> f m
  msg f (SBPMsgStmUniqueIdResp n m) = SBPMsgStmUniqueIdResp n <$> f m
  msg f (SBPMsgThreadState n m) = SBPMsgThreadState n <$> f m
  msg f (SBPMsgTrackingIq n m) = SBPMsgTrackingIq n <$> f m
  msg f (SBPMsgTrackingState n m) = SBPMsgTrackingState n <$> f m
  msg f (SBPMsgTrackingStateDepA n m) = SBPMsgTrackingStateDepA n <$> f m
  msg f (SBPMsgTweet n m) = SBPMsgTweet n <$> f m
  msg f (SBPMsgUartState n m) = SBPMsgUartState n <$> f m
  msg f (SBPMsgUartStateDepa n m) = SBPMsgUartStateDepa n <$> f m
  msg f (SBPMsgUserData n m) = SBPMsgUserData n <$> f m
  msg f (SBPMsgVelEcef n m) = SBPMsgVelEcef n <$> f m
  msg f (SBPMsgVelNed n m) = SBPMsgVelNed n <$> f m
  msg f (SBPMsgUnknown m) = SBPMsgUnknown <$> f m
  msg f (SBPMsgBadCrc m) = SBPMsgBadCrc <$> f m