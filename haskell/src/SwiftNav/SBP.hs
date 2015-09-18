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
  , module SwiftNav.SBP.Logging
  , module SwiftNav.SBP.Navigation
  , module SwiftNav.SBP.Observation
  , module SwiftNav.SBP.Piksi
  , module SwiftNav.SBP.Settings
  , module SwiftNav.SBP.System
  , module SwiftNav.SBP.Tracking
  ) where

import BasicPrelude hiding (lookup)
import Control.Lens hiding ((.=))
import Data.Aeson hiding (decode, decode')
import Data.Binary
import Data.Binary.Get
import Data.Binary.Put
import Data.ByteString.Lazy hiding (ByteString)
import Data.ByteString.Builder
import Data.HashMap.Strict
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
import SwiftNav.SBP.Types


-- | An SBP message ADT composed of all defined SBP messages.
--
-- Includes SBPMsgUnknown for valid SBP messages with undefined message
-- types and SBPMsgBadCRC for SBP messages with invalid CRC checksums.
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
    if preamble /= msgSBPPreamble then get else do
      sbp <- get
      return $ decode' sbp where
        decode' sbp@Msg {..}
          | checkCrc sbp /= _msgSBPCrc = SBPMsgBadCrc sbp
          | _msgSBPType == msgAcqResult = SBPMsgAcqResult (decode (fromStrict _msgSBPPayload)) sbp
          | _msgSBPType == msgAcqResultDepA = SBPMsgAcqResultDepA (decode (fromStrict _msgSBPPayload)) sbp
          | _msgSBPType == msgAlmanac = SBPMsgAlmanac (decode (fromStrict _msgSBPPayload)) sbp
          | _msgSBPType == msgBasePos = SBPMsgBasePos (decode (fromStrict _msgSBPPayload)) sbp
          | _msgSBPType == msgBaselineEcef = SBPMsgBaselineEcef (decode (fromStrict _msgSBPPayload)) sbp
          | _msgSBPType == msgBaselineNed = SBPMsgBaselineNed (decode (fromStrict _msgSBPPayload)) sbp
          | _msgSBPType == msgBootloaderHandshakeDepA = SBPMsgBootloaderHandshakeDepA (decode (fromStrict _msgSBPPayload)) sbp
          | _msgSBPType == msgBootloaderHandshakeReq = SBPMsgBootloaderHandshakeReq (decode (fromStrict _msgSBPPayload)) sbp
          | _msgSBPType == msgBootloaderHandshakeResp = SBPMsgBootloaderHandshakeResp (decode (fromStrict _msgSBPPayload)) sbp
          | _msgSBPType == msgBootloaderJumpToApp = SBPMsgBootloaderJumpToApp (decode (fromStrict _msgSBPPayload)) sbp
          | _msgSBPType == msgCwResults = SBPMsgCwResults (decode (fromStrict _msgSBPPayload)) sbp
          | _msgSBPType == msgCwStart = SBPMsgCwStart (decode (fromStrict _msgSBPPayload)) sbp
          | _msgSBPType == msgDops = SBPMsgDops (decode (fromStrict _msgSBPPayload)) sbp
          | _msgSBPType == msgEphemeris = SBPMsgEphemeris (decode (fromStrict _msgSBPPayload)) sbp
          | _msgSBPType == msgEphemerisDepA = SBPMsgEphemerisDepA (decode (fromStrict _msgSBPPayload)) sbp
          | _msgSBPType == msgEphemerisDepB = SBPMsgEphemerisDepB (decode (fromStrict _msgSBPPayload)) sbp
          | _msgSBPType == msgExtEvent = SBPMsgExtEvent (decode (fromStrict _msgSBPPayload)) sbp
          | _msgSBPType == msgFileioReadDirReq = SBPMsgFileioReadDirReq (decode (fromStrict _msgSBPPayload)) sbp
          | _msgSBPType == msgFileioReadDirResp = SBPMsgFileioReadDirResp (decode (fromStrict _msgSBPPayload)) sbp
          | _msgSBPType == msgFileioReadReq = SBPMsgFileioReadReq (decode (fromStrict _msgSBPPayload)) sbp
          | _msgSBPType == msgFileioReadResp = SBPMsgFileioReadResp (decode (fromStrict _msgSBPPayload)) sbp
          | _msgSBPType == msgFileioRemove = SBPMsgFileioRemove (decode (fromStrict _msgSBPPayload)) sbp
          | _msgSBPType == msgFileioWriteReq = SBPMsgFileioWriteReq (decode (fromStrict _msgSBPPayload)) sbp
          | _msgSBPType == msgFileioWriteResp = SBPMsgFileioWriteResp (decode (fromStrict _msgSBPPayload)) sbp
          | _msgSBPType == msgFlashDone = SBPMsgFlashDone (decode (fromStrict _msgSBPPayload)) sbp
          | _msgSBPType == msgFlashErase = SBPMsgFlashErase (decode (fromStrict _msgSBPPayload)) sbp
          | _msgSBPType == msgFlashProgram = SBPMsgFlashProgram (decode (fromStrict _msgSBPPayload)) sbp
          | _msgSBPType == msgFlashReadReq = SBPMsgFlashReadReq (decode (fromStrict _msgSBPPayload)) sbp
          | _msgSBPType == msgFlashReadResp = SBPMsgFlashReadResp (decode (fromStrict _msgSBPPayload)) sbp
          | _msgSBPType == msgGpsTime = SBPMsgGpsTime (decode (fromStrict _msgSBPPayload)) sbp
          | _msgSBPType == msgHeartbeat = SBPMsgHeartbeat (decode (fromStrict _msgSBPPayload)) sbp
          | _msgSBPType == msgIarState = SBPMsgIarState (decode (fromStrict _msgSBPPayload)) sbp
          | _msgSBPType == msgInitBase = SBPMsgInitBase (decode (fromStrict _msgSBPPayload)) sbp
          | _msgSBPType == msgLog = SBPMsgLog (decode (fromStrict _msgSBPPayload)) sbp
          | _msgSBPType == msgM25FlashWriteStatus = SBPMsgM25FlashWriteStatus (decode (fromStrict _msgSBPPayload)) sbp
          | _msgSBPType == msgMaskSatellite = SBPMsgMaskSatellite (decode (fromStrict _msgSBPPayload)) sbp
          | _msgSBPType == msgNapDeviceDnaReq = SBPMsgNapDeviceDnaReq (decode (fromStrict _msgSBPPayload)) sbp
          | _msgSBPType == msgNapDeviceDnaResp = SBPMsgNapDeviceDnaResp (decode (fromStrict _msgSBPPayload)) sbp
          | _msgSBPType == msgObs = SBPMsgObs (decode (fromStrict _msgSBPPayload)) sbp
          | _msgSBPType == msgObsDepA = SBPMsgObsDepA (decode (fromStrict _msgSBPPayload)) sbp
          | _msgSBPType == msgPosEcef = SBPMsgPosEcef (decode (fromStrict _msgSBPPayload)) sbp
          | _msgSBPType == msgPosLlh = SBPMsgPosLlh (decode (fromStrict _msgSBPPayload)) sbp
          | _msgSBPType == msgPrintDep = SBPMsgPrintDep (decode (fromStrict _msgSBPPayload)) sbp
          | _msgSBPType == msgReset = SBPMsgReset (decode (fromStrict _msgSBPPayload)) sbp
          | _msgSBPType == msgResetFilters = SBPMsgResetFilters (decode (fromStrict _msgSBPPayload)) sbp
          | _msgSBPType == msgSetTime = SBPMsgSetTime (decode (fromStrict _msgSBPPayload)) sbp
          | _msgSBPType == msgSettingsReadByIndexDone = SBPMsgSettingsReadByIndexDone (decode (fromStrict _msgSBPPayload)) sbp
          | _msgSBPType == msgSettingsReadByIndexReq = SBPMsgSettingsReadByIndexReq (decode (fromStrict _msgSBPPayload)) sbp
          | _msgSBPType == msgSettingsReadByIndexResp = SBPMsgSettingsReadByIndexResp (decode (fromStrict _msgSBPPayload)) sbp
          | _msgSBPType == msgSettingsReadReq = SBPMsgSettingsReadReq (decode (fromStrict _msgSBPPayload)) sbp
          | _msgSBPType == msgSettingsReadResp = SBPMsgSettingsReadResp (decode (fromStrict _msgSBPPayload)) sbp
          | _msgSBPType == msgSettingsSave = SBPMsgSettingsSave (decode (fromStrict _msgSBPPayload)) sbp
          | _msgSBPType == msgSettingsWrite = SBPMsgSettingsWrite (decode (fromStrict _msgSBPPayload)) sbp
          | _msgSBPType == msgStartup = SBPMsgStartup (decode (fromStrict _msgSBPPayload)) sbp
          | _msgSBPType == msgStmFlashLockSector = SBPMsgStmFlashLockSector (decode (fromStrict _msgSBPPayload)) sbp
          | _msgSBPType == msgStmFlashUnlockSector = SBPMsgStmFlashUnlockSector (decode (fromStrict _msgSBPPayload)) sbp
          | _msgSBPType == msgStmUniqueIdReq = SBPMsgStmUniqueIdReq (decode (fromStrict _msgSBPPayload)) sbp
          | _msgSBPType == msgStmUniqueIdResp = SBPMsgStmUniqueIdResp (decode (fromStrict _msgSBPPayload)) sbp
          | _msgSBPType == msgThreadState = SBPMsgThreadState (decode (fromStrict _msgSBPPayload)) sbp
          | _msgSBPType == msgTrackingIq = SBPMsgTrackingIq (decode (fromStrict _msgSBPPayload)) sbp
          | _msgSBPType == msgTrackingState = SBPMsgTrackingState (decode (fromStrict _msgSBPPayload)) sbp
          | _msgSBPType == msgTrackingStateDepA = SBPMsgTrackingStateDepA (decode (fromStrict _msgSBPPayload)) sbp
          | _msgSBPType == msgTweet = SBPMsgTweet (decode (fromStrict _msgSBPPayload)) sbp
          | _msgSBPType == msgUartState = SBPMsgUartState (decode (fromStrict _msgSBPPayload)) sbp
          | _msgSBPType == msgVelEcef = SBPMsgVelEcef (decode (fromStrict _msgSBPPayload)) sbp
          | _msgSBPType == msgVelNed = SBPMsgVelNed (decode (fromStrict _msgSBPPayload)) sbp
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
      encode' (SBPMsgBadCrc sbp) = sbp

instance FromJSON SBPMsg where
  parseJSON obj@(Object o) = do
    msgType <- o .: "msg_type"
    decode' msgType where
      decode' msgType
        | msgType == msgAcqResult = SBPMsgAcqResult <$> parseJSON obj <*> parseJSON obj
        | msgType == msgAcqResultDepA = SBPMsgAcqResultDepA <$> parseJSON obj <*> parseJSON obj
        | msgType == msgAlmanac = SBPMsgAlmanac <$> parseJSON obj <*> parseJSON obj
        | msgType == msgBasePos = SBPMsgBasePos <$> parseJSON obj <*> parseJSON obj
        | msgType == msgBaselineEcef = SBPMsgBaselineEcef <$> parseJSON obj <*> parseJSON obj
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
        | msgType == msgVelEcef = SBPMsgVelEcef <$> parseJSON obj <*> parseJSON obj
        | msgType == msgVelNed = SBPMsgVelNed <$> parseJSON obj <*> parseJSON obj
        | otherwise = SBPMsgUnknown <$> parseJSON obj
  parseJSON _ = mzero

merge :: Value -> Value -> Value
merge (Object one) (Object two) = Object (one <> two)
merge _ (Object two) = Object two
merge (Object one) _ = Object one
merge _ v = v

instance ToJSON SBPMsg where
   toJSON (SBPMsgAcqResult msg sbp) = toJSON msg `merge` toJSON sbp
   toJSON (SBPMsgAcqResultDepA msg sbp) = toJSON msg `merge` toJSON sbp
   toJSON (SBPMsgAlmanac msg sbp) = toJSON msg `merge` toJSON sbp
   toJSON (SBPMsgBasePos msg sbp) = toJSON msg `merge` toJSON sbp
   toJSON (SBPMsgBaselineEcef msg sbp) = toJSON msg `merge` toJSON sbp
   toJSON (SBPMsgBaselineNed msg sbp) = toJSON msg `merge` toJSON sbp
   toJSON (SBPMsgBootloaderHandshakeDepA msg sbp) = toJSON msg `merge` toJSON sbp
   toJSON (SBPMsgBootloaderHandshakeReq msg sbp) = toJSON msg `merge` toJSON sbp
   toJSON (SBPMsgBootloaderHandshakeResp msg sbp) = toJSON msg `merge` toJSON sbp
   toJSON (SBPMsgBootloaderJumpToApp msg sbp) = toJSON msg `merge` toJSON sbp
   toJSON (SBPMsgCwResults msg sbp) = toJSON msg `merge` toJSON sbp
   toJSON (SBPMsgCwStart msg sbp) = toJSON msg `merge` toJSON sbp
   toJSON (SBPMsgDops msg sbp) = toJSON msg `merge` toJSON sbp
   toJSON (SBPMsgEphemeris msg sbp) = toJSON msg `merge` toJSON sbp
   toJSON (SBPMsgEphemerisDepA msg sbp) = toJSON msg `merge` toJSON sbp
   toJSON (SBPMsgEphemerisDepB msg sbp) = toJSON msg `merge` toJSON sbp
   toJSON (SBPMsgExtEvent msg sbp) = toJSON msg `merge` toJSON sbp
   toJSON (SBPMsgFileioReadDirReq msg sbp) = toJSON msg `merge` toJSON sbp
   toJSON (SBPMsgFileioReadDirResp msg sbp) = toJSON msg `merge` toJSON sbp
   toJSON (SBPMsgFileioReadReq msg sbp) = toJSON msg `merge` toJSON sbp
   toJSON (SBPMsgFileioReadResp msg sbp) = toJSON msg `merge` toJSON sbp
   toJSON (SBPMsgFileioRemove msg sbp) = toJSON msg `merge` toJSON sbp
   toJSON (SBPMsgFileioWriteReq msg sbp) = toJSON msg `merge` toJSON sbp
   toJSON (SBPMsgFileioWriteResp msg sbp) = toJSON msg `merge` toJSON sbp
   toJSON (SBPMsgFlashDone msg sbp) = toJSON msg `merge` toJSON sbp
   toJSON (SBPMsgFlashErase msg sbp) = toJSON msg `merge` toJSON sbp
   toJSON (SBPMsgFlashProgram msg sbp) = toJSON msg `merge` toJSON sbp
   toJSON (SBPMsgFlashReadReq msg sbp) = toJSON msg `merge` toJSON sbp
   toJSON (SBPMsgFlashReadResp msg sbp) = toJSON msg `merge` toJSON sbp
   toJSON (SBPMsgGpsTime msg sbp) = toJSON msg `merge` toJSON sbp
   toJSON (SBPMsgHeartbeat msg sbp) = toJSON msg `merge` toJSON sbp
   toJSON (SBPMsgIarState msg sbp) = toJSON msg `merge` toJSON sbp
   toJSON (SBPMsgInitBase msg sbp) = toJSON msg `merge` toJSON sbp
   toJSON (SBPMsgLog msg sbp) = toJSON msg `merge` toJSON sbp
   toJSON (SBPMsgM25FlashWriteStatus msg sbp) = toJSON msg `merge` toJSON sbp
   toJSON (SBPMsgMaskSatellite msg sbp) = toJSON msg `merge` toJSON sbp
   toJSON (SBPMsgNapDeviceDnaReq msg sbp) = toJSON msg `merge` toJSON sbp
   toJSON (SBPMsgNapDeviceDnaResp msg sbp) = toJSON msg `merge` toJSON sbp
   toJSON (SBPMsgObs msg sbp) = toJSON msg `merge` toJSON sbp
   toJSON (SBPMsgObsDepA msg sbp) = toJSON msg `merge` toJSON sbp
   toJSON (SBPMsgPosEcef msg sbp) = toJSON msg `merge` toJSON sbp
   toJSON (SBPMsgPosLlh msg sbp) = toJSON msg `merge` toJSON sbp
   toJSON (SBPMsgPrintDep msg sbp) = toJSON msg `merge` toJSON sbp
   toJSON (SBPMsgReset msg sbp) = toJSON msg `merge` toJSON sbp
   toJSON (SBPMsgResetFilters msg sbp) = toJSON msg `merge` toJSON sbp
   toJSON (SBPMsgSetTime msg sbp) = toJSON msg `merge` toJSON sbp
   toJSON (SBPMsgSettingsReadByIndexDone msg sbp) = toJSON msg `merge` toJSON sbp
   toJSON (SBPMsgSettingsReadByIndexReq msg sbp) = toJSON msg `merge` toJSON sbp
   toJSON (SBPMsgSettingsReadByIndexResp msg sbp) = toJSON msg `merge` toJSON sbp
   toJSON (SBPMsgSettingsReadReq msg sbp) = toJSON msg `merge` toJSON sbp
   toJSON (SBPMsgSettingsReadResp msg sbp) = toJSON msg `merge` toJSON sbp
   toJSON (SBPMsgSettingsSave msg sbp) = toJSON msg `merge` toJSON sbp
   toJSON (SBPMsgSettingsWrite msg sbp) = toJSON msg `merge` toJSON sbp
   toJSON (SBPMsgStartup msg sbp) = toJSON msg `merge` toJSON sbp
   toJSON (SBPMsgStmFlashLockSector msg sbp) = toJSON msg `merge` toJSON sbp
   toJSON (SBPMsgStmFlashUnlockSector msg sbp) = toJSON msg `merge` toJSON sbp
   toJSON (SBPMsgStmUniqueIdReq msg sbp) = toJSON msg `merge` toJSON sbp
   toJSON (SBPMsgStmUniqueIdResp msg sbp) = toJSON msg `merge` toJSON sbp
   toJSON (SBPMsgThreadState msg sbp) = toJSON msg `merge` toJSON sbp
   toJSON (SBPMsgTrackingIq msg sbp) = toJSON msg `merge` toJSON sbp
   toJSON (SBPMsgTrackingState msg sbp) = toJSON msg `merge` toJSON sbp
   toJSON (SBPMsgTrackingStateDepA msg sbp) = toJSON msg `merge` toJSON sbp
   toJSON (SBPMsgTweet msg sbp) = toJSON msg `merge` toJSON sbp
   toJSON (SBPMsgUartState msg sbp) = toJSON msg `merge` toJSON sbp
   toJSON (SBPMsgVelEcef msg sbp) = toJSON msg `merge` toJSON sbp
   toJSON (SBPMsgVelNed msg sbp) = toJSON msg `merge` toJSON sbp
   toJSON (SBPMsgBadCrc sbp) = toJSON sbp
   toJSON (SBPMsgUnknown sbp) = toJSON sbp