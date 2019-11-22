{-# OPTIONS_GHC -fno-warn-unused-imports #-}
{-# LANGUAGE NoImplicitPrelude           #-}
{-# LANGUAGE TemplateHaskell             #-}
{-# LANGUAGE RecordWildCards             #-}
{-# LANGUAGE OverloadedStrings           #-}

-- |
-- Module:      SwiftNav.SBP.Msg
-- Copyright:   Copyright (C) 2015-2018 Swift Navigation, Inc.
-- License:     LGPL-3
-- Maintainer:  Swift Navigation <dev@swiftnav.com>
-- Stability:   experimental
-- Portability: portable
--
-- SBP message containers.

module SwiftNav.SBP.Msg
  ( module SwiftNav.SBP.Msg
  ) where

import BasicPrelude
import Control.Lens
import Data.Aeson               hiding (decode)
import Data.Aeson.Lens
import Data.Binary
import Data.ByteString.Lazy     hiding (ByteString)
import SwiftNav.SBP.Acquisition
import SwiftNav.SBP.Bootload
import SwiftNav.SBP.ExtEvents
import SwiftNav.SBP.FileIo
import SwiftNav.SBP.Flash
import SwiftNav.SBP.Gnss
import SwiftNav.SBP.Imu
import SwiftNav.SBP.Linux
import SwiftNav.SBP.Logging
import SwiftNav.SBP.Mag
import SwiftNav.SBP.Navigation
import SwiftNav.SBP.Ndb
import SwiftNav.SBP.Observation
import SwiftNav.SBP.Orientation
import SwiftNav.SBP.Piksi
import SwiftNav.SBP.Sbas
import SwiftNav.SBP.Settings
import SwiftNav.SBP.Ssr
import SwiftNav.SBP.System
import SwiftNav.SBP.Tracking
import SwiftNav.SBP.User
import SwiftNav.SBP.Vehicle
import SwiftNav.SBP.Types


-- | An SBP message ADT composed of all defined SBP messages.
--
-- Includes SBPMsgUnknown for valid SBP messages with undefined message
-- types and SBPMsgBadCRC for SBP messages with invalid CRC checksums.
data SBPMsg =
     SBPMsgAcqResult MsgAcqResult Msg
   | SBPMsgAcqResultDepA MsgAcqResultDepA Msg
   | SBPMsgAcqResultDepB MsgAcqResultDepB Msg
   | SBPMsgAcqResultDepC MsgAcqResultDepC Msg
   | SBPMsgAcqSvProfile MsgAcqSvProfile Msg
   | SBPMsgAcqSvProfileDep MsgAcqSvProfileDep Msg
   | SBPMsgAgeCorrections MsgAgeCorrections Msg
   | SBPMsgAlmanac MsgAlmanac Msg
   | SBPMsgAlmanacGlo MsgAlmanacGlo Msg
   | SBPMsgAlmanacGloDep MsgAlmanacGloDep Msg
   | SBPMsgAlmanacGps MsgAlmanacGps Msg
   | SBPMsgAlmanacGpsDep MsgAlmanacGpsDep Msg
   | SBPMsgAngularRate MsgAngularRate Msg
   | SBPMsgBasePosEcef MsgBasePosEcef Msg
   | SBPMsgBasePosLlh MsgBasePosLlh Msg
   | SBPMsgBaselineEcef MsgBaselineEcef Msg
   | SBPMsgBaselineEcefDepA MsgBaselineEcefDepA Msg
   | SBPMsgBaselineHeading MsgBaselineHeading Msg
   | SBPMsgBaselineHeadingDepA MsgBaselineHeadingDepA Msg
   | SBPMsgBaselineNed MsgBaselineNed Msg
   | SBPMsgBaselineNedDepA MsgBaselineNedDepA Msg
   | SBPMsgBootloaderHandshakeDepA MsgBootloaderHandshakeDepA Msg
   | SBPMsgBootloaderHandshakeReq MsgBootloaderHandshakeReq Msg
   | SBPMsgBootloaderHandshakeResp MsgBootloaderHandshakeResp Msg
   | SBPMsgBootloaderJumpToApp MsgBootloaderJumpToApp Msg
   | SBPMsgCellModemStatus MsgCellModemStatus Msg
   | SBPMsgCommandOutput MsgCommandOutput Msg
   | SBPMsgCommandReq MsgCommandReq Msg
   | SBPMsgCommandResp MsgCommandResp Msg
   | SBPMsgCsacTelemetry MsgCsacTelemetry Msg
   | SBPMsgCsacTelemetryLabels MsgCsacTelemetryLabels Msg
   | SBPMsgCwResults MsgCwResults Msg
   | SBPMsgCwStart MsgCwStart Msg
   | SBPMsgDeviceMonitor MsgDeviceMonitor Msg
   | SBPMsgDgnssStatus MsgDgnssStatus Msg
   | SBPMsgDops MsgDops Msg
   | SBPMsgDopsDepA MsgDopsDepA Msg
   | SBPMsgEphemerisBds MsgEphemerisBds Msg
   | SBPMsgEphemerisDepA MsgEphemerisDepA Msg
   | SBPMsgEphemerisDepB MsgEphemerisDepB Msg
   | SBPMsgEphemerisDepC MsgEphemerisDepC Msg
   | SBPMsgEphemerisDepD MsgEphemerisDepD Msg
   | SBPMsgEphemerisGal MsgEphemerisGal Msg
   | SBPMsgEphemerisGalDepA MsgEphemerisGalDepA Msg
   | SBPMsgEphemerisGlo MsgEphemerisGlo Msg
   | SBPMsgEphemerisGloDepA MsgEphemerisGloDepA Msg
   | SBPMsgEphemerisGloDepB MsgEphemerisGloDepB Msg
   | SBPMsgEphemerisGloDepC MsgEphemerisGloDepC Msg
   | SBPMsgEphemerisGloDepD MsgEphemerisGloDepD Msg
   | SBPMsgEphemerisGps MsgEphemerisGps Msg
   | SBPMsgEphemerisGpsDepE MsgEphemerisGpsDepE Msg
   | SBPMsgEphemerisGpsDepF MsgEphemerisGpsDepF Msg
   | SBPMsgEphemerisQzss MsgEphemerisQzss Msg
   | SBPMsgEphemerisSbas MsgEphemerisSbas Msg
   | SBPMsgEphemerisSbasDepA MsgEphemerisSbasDepA Msg
   | SBPMsgEphemerisSbasDepB MsgEphemerisSbasDepB Msg
   | SBPMsgExtEvent MsgExtEvent Msg
   | SBPMsgFileioConfigReq MsgFileioConfigReq Msg
   | SBPMsgFileioConfigResp MsgFileioConfigResp Msg
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
   | SBPMsgFrontEndGain MsgFrontEndGain Msg
   | SBPMsgFwd MsgFwd Msg
   | SBPMsgGloBiases MsgGloBiases Msg
   | SBPMsgGnssCapb MsgGnssCapb Msg
   | SBPMsgGpsTime MsgGpsTime Msg
   | SBPMsgGpsTimeDepA MsgGpsTimeDepA Msg
   | SBPMsgGroupDelay MsgGroupDelay Msg
   | SBPMsgGroupDelayDepA MsgGroupDelayDepA Msg
   | SBPMsgGroupDelayDepB MsgGroupDelayDepB Msg
   | SBPMsgHeartbeat MsgHeartbeat Msg
   | SBPMsgIarState MsgIarState Msg
   | SBPMsgImuAux MsgImuAux Msg
   | SBPMsgImuRaw MsgImuRaw Msg
   | SBPMsgInitBaseDep MsgInitBaseDep Msg
   | SBPMsgInsStatus MsgInsStatus Msg
   | SBPMsgIono MsgIono Msg
   | SBPMsgLinuxCpuState MsgLinuxCpuState Msg
   | SBPMsgLinuxMemState MsgLinuxMemState Msg
   | SBPMsgLinuxProcessFdCount MsgLinuxProcessFdCount Msg
   | SBPMsgLinuxProcessFdSummary MsgLinuxProcessFdSummary Msg
   | SBPMsgLinuxProcessSocketCounts MsgLinuxProcessSocketCounts Msg
   | SBPMsgLinuxProcessSocketQueues MsgLinuxProcessSocketQueues Msg
   | SBPMsgLinuxSocketUsage MsgLinuxSocketUsage Msg
   | SBPMsgLinuxSysState MsgLinuxSysState Msg
   | SBPMsgLog MsgLog Msg
   | SBPMsgM25FlashWriteStatus MsgM25FlashWriteStatus Msg
   | SBPMsgMagRaw MsgMagRaw Msg
   | SBPMsgMaskSatellite MsgMaskSatellite Msg
   | SBPMsgMaskSatelliteDep MsgMaskSatelliteDep Msg
   | SBPMsgMeasurementState MsgMeasurementState Msg
   | SBPMsgNapDeviceDnaReq MsgNapDeviceDnaReq Msg
   | SBPMsgNapDeviceDnaResp MsgNapDeviceDnaResp Msg
   | SBPMsgNdbEvent MsgNdbEvent Msg
   | SBPMsgNetworkBandwidthUsage MsgNetworkBandwidthUsage Msg
   | SBPMsgNetworkStateReq MsgNetworkStateReq Msg
   | SBPMsgNetworkStateResp MsgNetworkStateResp Msg
   | SBPMsgObs MsgObs Msg
   | SBPMsgObsDepA MsgObsDepA Msg
   | SBPMsgObsDepB MsgObsDepB Msg
   | SBPMsgObsDepC MsgObsDepC Msg
   | SBPMsgOdometry MsgOdometry Msg
   | SBPMsgOrientEuler MsgOrientEuler Msg
   | SBPMsgOrientQuat MsgOrientQuat Msg
   | SBPMsgOsr MsgOsr Msg
   | SBPMsgPosEcef MsgPosEcef Msg
   | SBPMsgPosEcefCov MsgPosEcefCov Msg
   | SBPMsgPosEcefDepA MsgPosEcefDepA Msg
   | SBPMsgPosLlh MsgPosLlh Msg
   | SBPMsgPosLlhCov MsgPosLlhCov Msg
   | SBPMsgPosLlhDepA MsgPosLlhDepA Msg
   | SBPMsgPrintDep MsgPrintDep Msg
   | SBPMsgProtectionLevel MsgProtectionLevel Msg
   | SBPMsgReset MsgReset Msg
   | SBPMsgResetDep MsgResetDep Msg
   | SBPMsgResetFilters MsgResetFilters Msg
   | SBPMsgSbasRaw MsgSbasRaw Msg
   | SBPMsgSetTime MsgSetTime Msg
   | SBPMsgSettingsReadByIndexDone MsgSettingsReadByIndexDone Msg
   | SBPMsgSettingsReadByIndexReq MsgSettingsReadByIndexReq Msg
   | SBPMsgSettingsReadByIndexResp MsgSettingsReadByIndexResp Msg
   | SBPMsgSettingsReadReq MsgSettingsReadReq Msg
   | SBPMsgSettingsReadResp MsgSettingsReadResp Msg
   | SBPMsgSettingsRegister MsgSettingsRegister Msg
   | SBPMsgSettingsRegisterResp MsgSettingsRegisterResp Msg
   | SBPMsgSettingsSave MsgSettingsSave Msg
   | SBPMsgSettingsWrite MsgSettingsWrite Msg
   | SBPMsgSettingsWriteResp MsgSettingsWriteResp Msg
   | SBPMsgSpecan MsgSpecan Msg
   | SBPMsgSpecanDep MsgSpecanDep Msg
   | SBPMsgSsrCodeBiases MsgSsrCodeBiases Msg
   | SBPMsgSsrGridDefinition MsgSsrGridDefinition Msg
   | SBPMsgSsrGriddedCorrection MsgSsrGriddedCorrection Msg
   | SBPMsgSsrOrbitClock MsgSsrOrbitClock Msg
   | SBPMsgSsrOrbitClockDepA MsgSsrOrbitClockDepA Msg
   | SBPMsgSsrPhaseBiases MsgSsrPhaseBiases Msg
   | SBPMsgSsrStecCorrection MsgSsrStecCorrection Msg
   | SBPMsgStartup MsgStartup Msg
   | SBPMsgStmFlashLockSector MsgStmFlashLockSector Msg
   | SBPMsgStmFlashUnlockSector MsgStmFlashUnlockSector Msg
   | SBPMsgStmUniqueIdReq MsgStmUniqueIdReq Msg
   | SBPMsgStmUniqueIdResp MsgStmUniqueIdResp Msg
   | SBPMsgSvAzEl MsgSvAzEl Msg
   | SBPMsgSvConfigurationGpsDep MsgSvConfigurationGpsDep Msg
   | SBPMsgThreadState MsgThreadState Msg
   | SBPMsgTrackingIq MsgTrackingIq Msg
   | SBPMsgTrackingIqDepA MsgTrackingIqDepA Msg
   | SBPMsgTrackingIqDepB MsgTrackingIqDepB Msg
   | SBPMsgTrackingState MsgTrackingState Msg
   | SBPMsgTrackingStateDepA MsgTrackingStateDepA Msg
   | SBPMsgTrackingStateDepB MsgTrackingStateDepB Msg
   | SBPMsgTrackingStateDetailedDep MsgTrackingStateDetailedDep Msg
   | SBPMsgTrackingStateDetailedDepA MsgTrackingStateDetailedDepA Msg
   | SBPMsgUartState MsgUartState Msg
   | SBPMsgUartStateDepa MsgUartStateDepa Msg
   | SBPMsgUserData MsgUserData Msg
   | SBPMsgUtcTime MsgUtcTime Msg
   | SBPMsgVelBody MsgVelBody Msg
   | SBPMsgVelEcef MsgVelEcef Msg
   | SBPMsgVelEcefCov MsgVelEcefCov Msg
   | SBPMsgVelEcefDepA MsgVelEcefDepA Msg
   | SBPMsgVelNed MsgVelNed Msg
   | SBPMsgVelNedCov MsgVelNedCov Msg
   | SBPMsgVelNedDepA MsgVelNedDepA Msg
   | SBPMsgBadCrc Msg
   | SBPMsgUnknown Msg
  deriving ( Show, Read, Eq )

$(makePrisms ''SBPMsg)

instance Binary SBPMsg where
  get = do
    preamble <- getWord8
    if preamble /= msgSBPPreamble then get else
      decoder <$> get where
        decoder m@Msg {..}
          | checkCrc m /= _msgSBPCrc = SBPMsgBadCrc m
          | _msgSBPType == msgAcqResult = SBPMsgAcqResult (decode (fromStrict (unBytes _msgSBPPayload))) m
          | _msgSBPType == msgAcqResultDepA = SBPMsgAcqResultDepA (decode (fromStrict (unBytes _msgSBPPayload))) m
          | _msgSBPType == msgAcqResultDepB = SBPMsgAcqResultDepB (decode (fromStrict (unBytes _msgSBPPayload))) m
          | _msgSBPType == msgAcqResultDepC = SBPMsgAcqResultDepC (decode (fromStrict (unBytes _msgSBPPayload))) m
          | _msgSBPType == msgAcqSvProfile = SBPMsgAcqSvProfile (decode (fromStrict (unBytes _msgSBPPayload))) m
          | _msgSBPType == msgAcqSvProfileDep = SBPMsgAcqSvProfileDep (decode (fromStrict (unBytes _msgSBPPayload))) m
          | _msgSBPType == msgAgeCorrections = SBPMsgAgeCorrections (decode (fromStrict (unBytes _msgSBPPayload))) m
          | _msgSBPType == msgAlmanac = SBPMsgAlmanac (decode (fromStrict (unBytes _msgSBPPayload))) m
          | _msgSBPType == msgAlmanacGlo = SBPMsgAlmanacGlo (decode (fromStrict (unBytes _msgSBPPayload))) m
          | _msgSBPType == msgAlmanacGloDep = SBPMsgAlmanacGloDep (decode (fromStrict (unBytes _msgSBPPayload))) m
          | _msgSBPType == msgAlmanacGps = SBPMsgAlmanacGps (decode (fromStrict (unBytes _msgSBPPayload))) m
          | _msgSBPType == msgAlmanacGpsDep = SBPMsgAlmanacGpsDep (decode (fromStrict (unBytes _msgSBPPayload))) m
          | _msgSBPType == msgAngularRate = SBPMsgAngularRate (decode (fromStrict (unBytes _msgSBPPayload))) m
          | _msgSBPType == msgBasePosEcef = SBPMsgBasePosEcef (decode (fromStrict (unBytes _msgSBPPayload))) m
          | _msgSBPType == msgBasePosLlh = SBPMsgBasePosLlh (decode (fromStrict (unBytes _msgSBPPayload))) m
          | _msgSBPType == msgBaselineEcef = SBPMsgBaselineEcef (decode (fromStrict (unBytes _msgSBPPayload))) m
          | _msgSBPType == msgBaselineEcefDepA = SBPMsgBaselineEcefDepA (decode (fromStrict (unBytes _msgSBPPayload))) m
          | _msgSBPType == msgBaselineHeading = SBPMsgBaselineHeading (decode (fromStrict (unBytes _msgSBPPayload))) m
          | _msgSBPType == msgBaselineHeadingDepA = SBPMsgBaselineHeadingDepA (decode (fromStrict (unBytes _msgSBPPayload))) m
          | _msgSBPType == msgBaselineNed = SBPMsgBaselineNed (decode (fromStrict (unBytes _msgSBPPayload))) m
          | _msgSBPType == msgBaselineNedDepA = SBPMsgBaselineNedDepA (decode (fromStrict (unBytes _msgSBPPayload))) m
          | _msgSBPType == msgBootloaderHandshakeDepA = SBPMsgBootloaderHandshakeDepA (decode (fromStrict (unBytes _msgSBPPayload))) m
          | _msgSBPType == msgBootloaderHandshakeReq = SBPMsgBootloaderHandshakeReq (decode (fromStrict (unBytes _msgSBPPayload))) m
          | _msgSBPType == msgBootloaderHandshakeResp = SBPMsgBootloaderHandshakeResp (decode (fromStrict (unBytes _msgSBPPayload))) m
          | _msgSBPType == msgBootloaderJumpToApp = SBPMsgBootloaderJumpToApp (decode (fromStrict (unBytes _msgSBPPayload))) m
          | _msgSBPType == msgCellModemStatus = SBPMsgCellModemStatus (decode (fromStrict (unBytes _msgSBPPayload))) m
          | _msgSBPType == msgCommandOutput = SBPMsgCommandOutput (decode (fromStrict (unBytes _msgSBPPayload))) m
          | _msgSBPType == msgCommandReq = SBPMsgCommandReq (decode (fromStrict (unBytes _msgSBPPayload))) m
          | _msgSBPType == msgCommandResp = SBPMsgCommandResp (decode (fromStrict (unBytes _msgSBPPayload))) m
          | _msgSBPType == msgCsacTelemetry = SBPMsgCsacTelemetry (decode (fromStrict (unBytes _msgSBPPayload))) m
          | _msgSBPType == msgCsacTelemetryLabels = SBPMsgCsacTelemetryLabels (decode (fromStrict (unBytes _msgSBPPayload))) m
          | _msgSBPType == msgCwResults = SBPMsgCwResults (decode (fromStrict (unBytes _msgSBPPayload))) m
          | _msgSBPType == msgCwStart = SBPMsgCwStart (decode (fromStrict (unBytes _msgSBPPayload))) m
          | _msgSBPType == msgDeviceMonitor = SBPMsgDeviceMonitor (decode (fromStrict (unBytes _msgSBPPayload))) m
          | _msgSBPType == msgDgnssStatus = SBPMsgDgnssStatus (decode (fromStrict (unBytes _msgSBPPayload))) m
          | _msgSBPType == msgDops = SBPMsgDops (decode (fromStrict (unBytes _msgSBPPayload))) m
          | _msgSBPType == msgDopsDepA = SBPMsgDopsDepA (decode (fromStrict (unBytes _msgSBPPayload))) m
          | _msgSBPType == msgEphemerisBds = SBPMsgEphemerisBds (decode (fromStrict (unBytes _msgSBPPayload))) m
          | _msgSBPType == msgEphemerisDepA = SBPMsgEphemerisDepA (decode (fromStrict (unBytes _msgSBPPayload))) m
          | _msgSBPType == msgEphemerisDepB = SBPMsgEphemerisDepB (decode (fromStrict (unBytes _msgSBPPayload))) m
          | _msgSBPType == msgEphemerisDepC = SBPMsgEphemerisDepC (decode (fromStrict (unBytes _msgSBPPayload))) m
          | _msgSBPType == msgEphemerisDepD = SBPMsgEphemerisDepD (decode (fromStrict (unBytes _msgSBPPayload))) m
          | _msgSBPType == msgEphemerisGal = SBPMsgEphemerisGal (decode (fromStrict (unBytes _msgSBPPayload))) m
          | _msgSBPType == msgEphemerisGalDepA = SBPMsgEphemerisGalDepA (decode (fromStrict (unBytes _msgSBPPayload))) m
          | _msgSBPType == msgEphemerisGlo = SBPMsgEphemerisGlo (decode (fromStrict (unBytes _msgSBPPayload))) m
          | _msgSBPType == msgEphemerisGloDepA = SBPMsgEphemerisGloDepA (decode (fromStrict (unBytes _msgSBPPayload))) m
          | _msgSBPType == msgEphemerisGloDepB = SBPMsgEphemerisGloDepB (decode (fromStrict (unBytes _msgSBPPayload))) m
          | _msgSBPType == msgEphemerisGloDepC = SBPMsgEphemerisGloDepC (decode (fromStrict (unBytes _msgSBPPayload))) m
          | _msgSBPType == msgEphemerisGloDepD = SBPMsgEphemerisGloDepD (decode (fromStrict (unBytes _msgSBPPayload))) m
          | _msgSBPType == msgEphemerisGps = SBPMsgEphemerisGps (decode (fromStrict (unBytes _msgSBPPayload))) m
          | _msgSBPType == msgEphemerisGpsDepE = SBPMsgEphemerisGpsDepE (decode (fromStrict (unBytes _msgSBPPayload))) m
          | _msgSBPType == msgEphemerisGpsDepF = SBPMsgEphemerisGpsDepF (decode (fromStrict (unBytes _msgSBPPayload))) m
          | _msgSBPType == msgEphemerisQzss = SBPMsgEphemerisQzss (decode (fromStrict (unBytes _msgSBPPayload))) m
          | _msgSBPType == msgEphemerisSbas = SBPMsgEphemerisSbas (decode (fromStrict (unBytes _msgSBPPayload))) m
          | _msgSBPType == msgEphemerisSbasDepA = SBPMsgEphemerisSbasDepA (decode (fromStrict (unBytes _msgSBPPayload))) m
          | _msgSBPType == msgEphemerisSbasDepB = SBPMsgEphemerisSbasDepB (decode (fromStrict (unBytes _msgSBPPayload))) m
          | _msgSBPType == msgExtEvent = SBPMsgExtEvent (decode (fromStrict (unBytes _msgSBPPayload))) m
          | _msgSBPType == msgFileioConfigReq = SBPMsgFileioConfigReq (decode (fromStrict (unBytes _msgSBPPayload))) m
          | _msgSBPType == msgFileioConfigResp = SBPMsgFileioConfigResp (decode (fromStrict (unBytes _msgSBPPayload))) m
          | _msgSBPType == msgFileioReadDirReq = SBPMsgFileioReadDirReq (decode (fromStrict (unBytes _msgSBPPayload))) m
          | _msgSBPType == msgFileioReadDirResp = SBPMsgFileioReadDirResp (decode (fromStrict (unBytes _msgSBPPayload))) m
          | _msgSBPType == msgFileioReadReq = SBPMsgFileioReadReq (decode (fromStrict (unBytes _msgSBPPayload))) m
          | _msgSBPType == msgFileioReadResp = SBPMsgFileioReadResp (decode (fromStrict (unBytes _msgSBPPayload))) m
          | _msgSBPType == msgFileioRemove = SBPMsgFileioRemove (decode (fromStrict (unBytes _msgSBPPayload))) m
          | _msgSBPType == msgFileioWriteReq = SBPMsgFileioWriteReq (decode (fromStrict (unBytes _msgSBPPayload))) m
          | _msgSBPType == msgFileioWriteResp = SBPMsgFileioWriteResp (decode (fromStrict (unBytes _msgSBPPayload))) m
          | _msgSBPType == msgFlashDone = SBPMsgFlashDone (decode (fromStrict (unBytes _msgSBPPayload))) m
          | _msgSBPType == msgFlashErase = SBPMsgFlashErase (decode (fromStrict (unBytes _msgSBPPayload))) m
          | _msgSBPType == msgFlashProgram = SBPMsgFlashProgram (decode (fromStrict (unBytes _msgSBPPayload))) m
          | _msgSBPType == msgFlashReadReq = SBPMsgFlashReadReq (decode (fromStrict (unBytes _msgSBPPayload))) m
          | _msgSBPType == msgFlashReadResp = SBPMsgFlashReadResp (decode (fromStrict (unBytes _msgSBPPayload))) m
          | _msgSBPType == msgFrontEndGain = SBPMsgFrontEndGain (decode (fromStrict (unBytes _msgSBPPayload))) m
          | _msgSBPType == msgFwd = SBPMsgFwd (decode (fromStrict (unBytes _msgSBPPayload))) m
          | _msgSBPType == msgGloBiases = SBPMsgGloBiases (decode (fromStrict (unBytes _msgSBPPayload))) m
          | _msgSBPType == msgGnssCapb = SBPMsgGnssCapb (decode (fromStrict (unBytes _msgSBPPayload))) m
          | _msgSBPType == msgGpsTime = SBPMsgGpsTime (decode (fromStrict (unBytes _msgSBPPayload))) m
          | _msgSBPType == msgGpsTimeDepA = SBPMsgGpsTimeDepA (decode (fromStrict (unBytes _msgSBPPayload))) m
          | _msgSBPType == msgGroupDelay = SBPMsgGroupDelay (decode (fromStrict (unBytes _msgSBPPayload))) m
          | _msgSBPType == msgGroupDelayDepA = SBPMsgGroupDelayDepA (decode (fromStrict (unBytes _msgSBPPayload))) m
          | _msgSBPType == msgGroupDelayDepB = SBPMsgGroupDelayDepB (decode (fromStrict (unBytes _msgSBPPayload))) m
          | _msgSBPType == msgHeartbeat = SBPMsgHeartbeat (decode (fromStrict (unBytes _msgSBPPayload))) m
          | _msgSBPType == msgIarState = SBPMsgIarState (decode (fromStrict (unBytes _msgSBPPayload))) m
          | _msgSBPType == msgImuAux = SBPMsgImuAux (decode (fromStrict (unBytes _msgSBPPayload))) m
          | _msgSBPType == msgImuRaw = SBPMsgImuRaw (decode (fromStrict (unBytes _msgSBPPayload))) m
          | _msgSBPType == msgInitBaseDep = SBPMsgInitBaseDep (decode (fromStrict (unBytes _msgSBPPayload))) m
          | _msgSBPType == msgInsStatus = SBPMsgInsStatus (decode (fromStrict (unBytes _msgSBPPayload))) m
          | _msgSBPType == msgIono = SBPMsgIono (decode (fromStrict (unBytes _msgSBPPayload))) m
          | _msgSBPType == msgLinuxCpuState = SBPMsgLinuxCpuState (decode (fromStrict (unBytes _msgSBPPayload))) m
          | _msgSBPType == msgLinuxMemState = SBPMsgLinuxMemState (decode (fromStrict (unBytes _msgSBPPayload))) m
          | _msgSBPType == msgLinuxProcessFdCount = SBPMsgLinuxProcessFdCount (decode (fromStrict (unBytes _msgSBPPayload))) m
          | _msgSBPType == msgLinuxProcessFdSummary = SBPMsgLinuxProcessFdSummary (decode (fromStrict (unBytes _msgSBPPayload))) m
          | _msgSBPType == msgLinuxProcessSocketCounts = SBPMsgLinuxProcessSocketCounts (decode (fromStrict (unBytes _msgSBPPayload))) m
          | _msgSBPType == msgLinuxProcessSocketQueues = SBPMsgLinuxProcessSocketQueues (decode (fromStrict (unBytes _msgSBPPayload))) m
          | _msgSBPType == msgLinuxSocketUsage = SBPMsgLinuxSocketUsage (decode (fromStrict (unBytes _msgSBPPayload))) m
          | _msgSBPType == msgLinuxSysState = SBPMsgLinuxSysState (decode (fromStrict (unBytes _msgSBPPayload))) m
          | _msgSBPType == msgLog = SBPMsgLog (decode (fromStrict (unBytes _msgSBPPayload))) m
          | _msgSBPType == msgM25FlashWriteStatus = SBPMsgM25FlashWriteStatus (decode (fromStrict (unBytes _msgSBPPayload))) m
          | _msgSBPType == msgMagRaw = SBPMsgMagRaw (decode (fromStrict (unBytes _msgSBPPayload))) m
          | _msgSBPType == msgMaskSatellite = SBPMsgMaskSatellite (decode (fromStrict (unBytes _msgSBPPayload))) m
          | _msgSBPType == msgMaskSatelliteDep = SBPMsgMaskSatelliteDep (decode (fromStrict (unBytes _msgSBPPayload))) m
          | _msgSBPType == msgMeasurementState = SBPMsgMeasurementState (decode (fromStrict (unBytes _msgSBPPayload))) m
          | _msgSBPType == msgNapDeviceDnaReq = SBPMsgNapDeviceDnaReq (decode (fromStrict (unBytes _msgSBPPayload))) m
          | _msgSBPType == msgNapDeviceDnaResp = SBPMsgNapDeviceDnaResp (decode (fromStrict (unBytes _msgSBPPayload))) m
          | _msgSBPType == msgNdbEvent = SBPMsgNdbEvent (decode (fromStrict (unBytes _msgSBPPayload))) m
          | _msgSBPType == msgNetworkBandwidthUsage = SBPMsgNetworkBandwidthUsage (decode (fromStrict (unBytes _msgSBPPayload))) m
          | _msgSBPType == msgNetworkStateReq = SBPMsgNetworkStateReq (decode (fromStrict (unBytes _msgSBPPayload))) m
          | _msgSBPType == msgNetworkStateResp = SBPMsgNetworkStateResp (decode (fromStrict (unBytes _msgSBPPayload))) m
          | _msgSBPType == msgObs = SBPMsgObs (decode (fromStrict (unBytes _msgSBPPayload))) m
          | _msgSBPType == msgObsDepA = SBPMsgObsDepA (decode (fromStrict (unBytes _msgSBPPayload))) m
          | _msgSBPType == msgObsDepB = SBPMsgObsDepB (decode (fromStrict (unBytes _msgSBPPayload))) m
          | _msgSBPType == msgObsDepC = SBPMsgObsDepC (decode (fromStrict (unBytes _msgSBPPayload))) m
          | _msgSBPType == msgOdometry = SBPMsgOdometry (decode (fromStrict (unBytes _msgSBPPayload))) m
          | _msgSBPType == msgOrientEuler = SBPMsgOrientEuler (decode (fromStrict (unBytes _msgSBPPayload))) m
          | _msgSBPType == msgOrientQuat = SBPMsgOrientQuat (decode (fromStrict (unBytes _msgSBPPayload))) m
          | _msgSBPType == msgOsr = SBPMsgOsr (decode (fromStrict (unBytes _msgSBPPayload))) m
          | _msgSBPType == msgPosEcef = SBPMsgPosEcef (decode (fromStrict (unBytes _msgSBPPayload))) m
          | _msgSBPType == msgPosEcefCov = SBPMsgPosEcefCov (decode (fromStrict (unBytes _msgSBPPayload))) m
          | _msgSBPType == msgPosEcefDepA = SBPMsgPosEcefDepA (decode (fromStrict (unBytes _msgSBPPayload))) m
          | _msgSBPType == msgPosLlh = SBPMsgPosLlh (decode (fromStrict (unBytes _msgSBPPayload))) m
          | _msgSBPType == msgPosLlhCov = SBPMsgPosLlhCov (decode (fromStrict (unBytes _msgSBPPayload))) m
          | _msgSBPType == msgPosLlhDepA = SBPMsgPosLlhDepA (decode (fromStrict (unBytes _msgSBPPayload))) m
          | _msgSBPType == msgPrintDep = SBPMsgPrintDep (decode (fromStrict (unBytes _msgSBPPayload))) m
          | _msgSBPType == msgProtectionLevel = SBPMsgProtectionLevel (decode (fromStrict (unBytes _msgSBPPayload))) m
          | _msgSBPType == msgReset = SBPMsgReset (decode (fromStrict (unBytes _msgSBPPayload))) m
          | _msgSBPType == msgResetDep = SBPMsgResetDep (decode (fromStrict (unBytes _msgSBPPayload))) m
          | _msgSBPType == msgResetFilters = SBPMsgResetFilters (decode (fromStrict (unBytes _msgSBPPayload))) m
          | _msgSBPType == msgSbasRaw = SBPMsgSbasRaw (decode (fromStrict (unBytes _msgSBPPayload))) m
          | _msgSBPType == msgSetTime = SBPMsgSetTime (decode (fromStrict (unBytes _msgSBPPayload))) m
          | _msgSBPType == msgSettingsReadByIndexDone = SBPMsgSettingsReadByIndexDone (decode (fromStrict (unBytes _msgSBPPayload))) m
          | _msgSBPType == msgSettingsReadByIndexReq = SBPMsgSettingsReadByIndexReq (decode (fromStrict (unBytes _msgSBPPayload))) m
          | _msgSBPType == msgSettingsReadByIndexResp = SBPMsgSettingsReadByIndexResp (decode (fromStrict (unBytes _msgSBPPayload))) m
          | _msgSBPType == msgSettingsReadReq = SBPMsgSettingsReadReq (decode (fromStrict (unBytes _msgSBPPayload))) m
          | _msgSBPType == msgSettingsReadResp = SBPMsgSettingsReadResp (decode (fromStrict (unBytes _msgSBPPayload))) m
          | _msgSBPType == msgSettingsRegister = SBPMsgSettingsRegister (decode (fromStrict (unBytes _msgSBPPayload))) m
          | _msgSBPType == msgSettingsRegisterResp = SBPMsgSettingsRegisterResp (decode (fromStrict (unBytes _msgSBPPayload))) m
          | _msgSBPType == msgSettingsSave = SBPMsgSettingsSave (decode (fromStrict (unBytes _msgSBPPayload))) m
          | _msgSBPType == msgSettingsWrite = SBPMsgSettingsWrite (decode (fromStrict (unBytes _msgSBPPayload))) m
          | _msgSBPType == msgSettingsWriteResp = SBPMsgSettingsWriteResp (decode (fromStrict (unBytes _msgSBPPayload))) m
          | _msgSBPType == msgSpecan = SBPMsgSpecan (decode (fromStrict (unBytes _msgSBPPayload))) m
          | _msgSBPType == msgSpecanDep = SBPMsgSpecanDep (decode (fromStrict (unBytes _msgSBPPayload))) m
          | _msgSBPType == msgSsrCodeBiases = SBPMsgSsrCodeBiases (decode (fromStrict (unBytes _msgSBPPayload))) m
          | _msgSBPType == msgSsrGridDefinition = SBPMsgSsrGridDefinition (decode (fromStrict (unBytes _msgSBPPayload))) m
          | _msgSBPType == msgSsrGriddedCorrection = SBPMsgSsrGriddedCorrection (decode (fromStrict (unBytes _msgSBPPayload))) m
          | _msgSBPType == msgSsrOrbitClock = SBPMsgSsrOrbitClock (decode (fromStrict (unBytes _msgSBPPayload))) m
          | _msgSBPType == msgSsrOrbitClockDepA = SBPMsgSsrOrbitClockDepA (decode (fromStrict (unBytes _msgSBPPayload))) m
          | _msgSBPType == msgSsrPhaseBiases = SBPMsgSsrPhaseBiases (decode (fromStrict (unBytes _msgSBPPayload))) m
          | _msgSBPType == msgSsrStecCorrection = SBPMsgSsrStecCorrection (decode (fromStrict (unBytes _msgSBPPayload))) m
          | _msgSBPType == msgStartup = SBPMsgStartup (decode (fromStrict (unBytes _msgSBPPayload))) m
          | _msgSBPType == msgStmFlashLockSector = SBPMsgStmFlashLockSector (decode (fromStrict (unBytes _msgSBPPayload))) m
          | _msgSBPType == msgStmFlashUnlockSector = SBPMsgStmFlashUnlockSector (decode (fromStrict (unBytes _msgSBPPayload))) m
          | _msgSBPType == msgStmUniqueIdReq = SBPMsgStmUniqueIdReq (decode (fromStrict (unBytes _msgSBPPayload))) m
          | _msgSBPType == msgStmUniqueIdResp = SBPMsgStmUniqueIdResp (decode (fromStrict (unBytes _msgSBPPayload))) m
          | _msgSBPType == msgSvAzEl = SBPMsgSvAzEl (decode (fromStrict (unBytes _msgSBPPayload))) m
          | _msgSBPType == msgSvConfigurationGpsDep = SBPMsgSvConfigurationGpsDep (decode (fromStrict (unBytes _msgSBPPayload))) m
          | _msgSBPType == msgThreadState = SBPMsgThreadState (decode (fromStrict (unBytes _msgSBPPayload))) m
          | _msgSBPType == msgTrackingIq = SBPMsgTrackingIq (decode (fromStrict (unBytes _msgSBPPayload))) m
          | _msgSBPType == msgTrackingIqDepA = SBPMsgTrackingIqDepA (decode (fromStrict (unBytes _msgSBPPayload))) m
          | _msgSBPType == msgTrackingIqDepB = SBPMsgTrackingIqDepB (decode (fromStrict (unBytes _msgSBPPayload))) m
          | _msgSBPType == msgTrackingState = SBPMsgTrackingState (decode (fromStrict (unBytes _msgSBPPayload))) m
          | _msgSBPType == msgTrackingStateDepA = SBPMsgTrackingStateDepA (decode (fromStrict (unBytes _msgSBPPayload))) m
          | _msgSBPType == msgTrackingStateDepB = SBPMsgTrackingStateDepB (decode (fromStrict (unBytes _msgSBPPayload))) m
          | _msgSBPType == msgTrackingStateDetailedDep = SBPMsgTrackingStateDetailedDep (decode (fromStrict (unBytes _msgSBPPayload))) m
          | _msgSBPType == msgTrackingStateDetailedDepA = SBPMsgTrackingStateDetailedDepA (decode (fromStrict (unBytes _msgSBPPayload))) m
          | _msgSBPType == msgUartState = SBPMsgUartState (decode (fromStrict (unBytes _msgSBPPayload))) m
          | _msgSBPType == msgUartStateDepa = SBPMsgUartStateDepa (decode (fromStrict (unBytes _msgSBPPayload))) m
          | _msgSBPType == msgUserData = SBPMsgUserData (decode (fromStrict (unBytes _msgSBPPayload))) m
          | _msgSBPType == msgUtcTime = SBPMsgUtcTime (decode (fromStrict (unBytes _msgSBPPayload))) m
          | _msgSBPType == msgVelBody = SBPMsgVelBody (decode (fromStrict (unBytes _msgSBPPayload))) m
          | _msgSBPType == msgVelEcef = SBPMsgVelEcef (decode (fromStrict (unBytes _msgSBPPayload))) m
          | _msgSBPType == msgVelEcefCov = SBPMsgVelEcefCov (decode (fromStrict (unBytes _msgSBPPayload))) m
          | _msgSBPType == msgVelEcefDepA = SBPMsgVelEcefDepA (decode (fromStrict (unBytes _msgSBPPayload))) m
          | _msgSBPType == msgVelNed = SBPMsgVelNed (decode (fromStrict (unBytes _msgSBPPayload))) m
          | _msgSBPType == msgVelNedCov = SBPMsgVelNedCov (decode (fromStrict (unBytes _msgSBPPayload))) m
          | _msgSBPType == msgVelNedDepA = SBPMsgVelNedDepA (decode (fromStrict (unBytes _msgSBPPayload))) m
          | otherwise = SBPMsgUnknown m

  put sm = do
    putWord8 msgSBPPreamble
    encoder sm where
      encoder (SBPMsgAcqResult _ m) = put m
      encoder (SBPMsgAcqResultDepA _ m) = put m
      encoder (SBPMsgAcqResultDepB _ m) = put m
      encoder (SBPMsgAcqResultDepC _ m) = put m
      encoder (SBPMsgAcqSvProfile _ m) = put m
      encoder (SBPMsgAcqSvProfileDep _ m) = put m
      encoder (SBPMsgAgeCorrections _ m) = put m
      encoder (SBPMsgAlmanac _ m) = put m
      encoder (SBPMsgAlmanacGlo _ m) = put m
      encoder (SBPMsgAlmanacGloDep _ m) = put m
      encoder (SBPMsgAlmanacGps _ m) = put m
      encoder (SBPMsgAlmanacGpsDep _ m) = put m
      encoder (SBPMsgAngularRate _ m) = put m
      encoder (SBPMsgBasePosEcef _ m) = put m
      encoder (SBPMsgBasePosLlh _ m) = put m
      encoder (SBPMsgBaselineEcef _ m) = put m
      encoder (SBPMsgBaselineEcefDepA _ m) = put m
      encoder (SBPMsgBaselineHeading _ m) = put m
      encoder (SBPMsgBaselineHeadingDepA _ m) = put m
      encoder (SBPMsgBaselineNed _ m) = put m
      encoder (SBPMsgBaselineNedDepA _ m) = put m
      encoder (SBPMsgBootloaderHandshakeDepA _ m) = put m
      encoder (SBPMsgBootloaderHandshakeReq _ m) = put m
      encoder (SBPMsgBootloaderHandshakeResp _ m) = put m
      encoder (SBPMsgBootloaderJumpToApp _ m) = put m
      encoder (SBPMsgCellModemStatus _ m) = put m
      encoder (SBPMsgCommandOutput _ m) = put m
      encoder (SBPMsgCommandReq _ m) = put m
      encoder (SBPMsgCommandResp _ m) = put m
      encoder (SBPMsgCsacTelemetry _ m) = put m
      encoder (SBPMsgCsacTelemetryLabels _ m) = put m
      encoder (SBPMsgCwResults _ m) = put m
      encoder (SBPMsgCwStart _ m) = put m
      encoder (SBPMsgDeviceMonitor _ m) = put m
      encoder (SBPMsgDgnssStatus _ m) = put m
      encoder (SBPMsgDops _ m) = put m
      encoder (SBPMsgDopsDepA _ m) = put m
      encoder (SBPMsgEphemerisBds _ m) = put m
      encoder (SBPMsgEphemerisDepA _ m) = put m
      encoder (SBPMsgEphemerisDepB _ m) = put m
      encoder (SBPMsgEphemerisDepC _ m) = put m
      encoder (SBPMsgEphemerisDepD _ m) = put m
      encoder (SBPMsgEphemerisGal _ m) = put m
      encoder (SBPMsgEphemerisGalDepA _ m) = put m
      encoder (SBPMsgEphemerisGlo _ m) = put m
      encoder (SBPMsgEphemerisGloDepA _ m) = put m
      encoder (SBPMsgEphemerisGloDepB _ m) = put m
      encoder (SBPMsgEphemerisGloDepC _ m) = put m
      encoder (SBPMsgEphemerisGloDepD _ m) = put m
      encoder (SBPMsgEphemerisGps _ m) = put m
      encoder (SBPMsgEphemerisGpsDepE _ m) = put m
      encoder (SBPMsgEphemerisGpsDepF _ m) = put m
      encoder (SBPMsgEphemerisQzss _ m) = put m
      encoder (SBPMsgEphemerisSbas _ m) = put m
      encoder (SBPMsgEphemerisSbasDepA _ m) = put m
      encoder (SBPMsgEphemerisSbasDepB _ m) = put m
      encoder (SBPMsgExtEvent _ m) = put m
      encoder (SBPMsgFileioConfigReq _ m) = put m
      encoder (SBPMsgFileioConfigResp _ m) = put m
      encoder (SBPMsgFileioReadDirReq _ m) = put m
      encoder (SBPMsgFileioReadDirResp _ m) = put m
      encoder (SBPMsgFileioReadReq _ m) = put m
      encoder (SBPMsgFileioReadResp _ m) = put m
      encoder (SBPMsgFileioRemove _ m) = put m
      encoder (SBPMsgFileioWriteReq _ m) = put m
      encoder (SBPMsgFileioWriteResp _ m) = put m
      encoder (SBPMsgFlashDone _ m) = put m
      encoder (SBPMsgFlashErase _ m) = put m
      encoder (SBPMsgFlashProgram _ m) = put m
      encoder (SBPMsgFlashReadReq _ m) = put m
      encoder (SBPMsgFlashReadResp _ m) = put m
      encoder (SBPMsgFrontEndGain _ m) = put m
      encoder (SBPMsgFwd _ m) = put m
      encoder (SBPMsgGloBiases _ m) = put m
      encoder (SBPMsgGnssCapb _ m) = put m
      encoder (SBPMsgGpsTime _ m) = put m
      encoder (SBPMsgGpsTimeDepA _ m) = put m
      encoder (SBPMsgGroupDelay _ m) = put m
      encoder (SBPMsgGroupDelayDepA _ m) = put m
      encoder (SBPMsgGroupDelayDepB _ m) = put m
      encoder (SBPMsgHeartbeat _ m) = put m
      encoder (SBPMsgIarState _ m) = put m
      encoder (SBPMsgImuAux _ m) = put m
      encoder (SBPMsgImuRaw _ m) = put m
      encoder (SBPMsgInitBaseDep _ m) = put m
      encoder (SBPMsgInsStatus _ m) = put m
      encoder (SBPMsgIono _ m) = put m
      encoder (SBPMsgLinuxCpuState _ m) = put m
      encoder (SBPMsgLinuxMemState _ m) = put m
      encoder (SBPMsgLinuxProcessFdCount _ m) = put m
      encoder (SBPMsgLinuxProcessFdSummary _ m) = put m
      encoder (SBPMsgLinuxProcessSocketCounts _ m) = put m
      encoder (SBPMsgLinuxProcessSocketQueues _ m) = put m
      encoder (SBPMsgLinuxSocketUsage _ m) = put m
      encoder (SBPMsgLinuxSysState _ m) = put m
      encoder (SBPMsgLog _ m) = put m
      encoder (SBPMsgM25FlashWriteStatus _ m) = put m
      encoder (SBPMsgMagRaw _ m) = put m
      encoder (SBPMsgMaskSatellite _ m) = put m
      encoder (SBPMsgMaskSatelliteDep _ m) = put m
      encoder (SBPMsgMeasurementState _ m) = put m
      encoder (SBPMsgNapDeviceDnaReq _ m) = put m
      encoder (SBPMsgNapDeviceDnaResp _ m) = put m
      encoder (SBPMsgNdbEvent _ m) = put m
      encoder (SBPMsgNetworkBandwidthUsage _ m) = put m
      encoder (SBPMsgNetworkStateReq _ m) = put m
      encoder (SBPMsgNetworkStateResp _ m) = put m
      encoder (SBPMsgObs _ m) = put m
      encoder (SBPMsgObsDepA _ m) = put m
      encoder (SBPMsgObsDepB _ m) = put m
      encoder (SBPMsgObsDepC _ m) = put m
      encoder (SBPMsgOdometry _ m) = put m
      encoder (SBPMsgOrientEuler _ m) = put m
      encoder (SBPMsgOrientQuat _ m) = put m
      encoder (SBPMsgOsr _ m) = put m
      encoder (SBPMsgPosEcef _ m) = put m
      encoder (SBPMsgPosEcefCov _ m) = put m
      encoder (SBPMsgPosEcefDepA _ m) = put m
      encoder (SBPMsgPosLlh _ m) = put m
      encoder (SBPMsgPosLlhCov _ m) = put m
      encoder (SBPMsgPosLlhDepA _ m) = put m
      encoder (SBPMsgPrintDep _ m) = put m
      encoder (SBPMsgProtectionLevel _ m) = put m
      encoder (SBPMsgReset _ m) = put m
      encoder (SBPMsgResetDep _ m) = put m
      encoder (SBPMsgResetFilters _ m) = put m
      encoder (SBPMsgSbasRaw _ m) = put m
      encoder (SBPMsgSetTime _ m) = put m
      encoder (SBPMsgSettingsReadByIndexDone _ m) = put m
      encoder (SBPMsgSettingsReadByIndexReq _ m) = put m
      encoder (SBPMsgSettingsReadByIndexResp _ m) = put m
      encoder (SBPMsgSettingsReadReq _ m) = put m
      encoder (SBPMsgSettingsReadResp _ m) = put m
      encoder (SBPMsgSettingsRegister _ m) = put m
      encoder (SBPMsgSettingsRegisterResp _ m) = put m
      encoder (SBPMsgSettingsSave _ m) = put m
      encoder (SBPMsgSettingsWrite _ m) = put m
      encoder (SBPMsgSettingsWriteResp _ m) = put m
      encoder (SBPMsgSpecan _ m) = put m
      encoder (SBPMsgSpecanDep _ m) = put m
      encoder (SBPMsgSsrCodeBiases _ m) = put m
      encoder (SBPMsgSsrGridDefinition _ m) = put m
      encoder (SBPMsgSsrGriddedCorrection _ m) = put m
      encoder (SBPMsgSsrOrbitClock _ m) = put m
      encoder (SBPMsgSsrOrbitClockDepA _ m) = put m
      encoder (SBPMsgSsrPhaseBiases _ m) = put m
      encoder (SBPMsgSsrStecCorrection _ m) = put m
      encoder (SBPMsgStartup _ m) = put m
      encoder (SBPMsgStmFlashLockSector _ m) = put m
      encoder (SBPMsgStmFlashUnlockSector _ m) = put m
      encoder (SBPMsgStmUniqueIdReq _ m) = put m
      encoder (SBPMsgStmUniqueIdResp _ m) = put m
      encoder (SBPMsgSvAzEl _ m) = put m
      encoder (SBPMsgSvConfigurationGpsDep _ m) = put m
      encoder (SBPMsgThreadState _ m) = put m
      encoder (SBPMsgTrackingIq _ m) = put m
      encoder (SBPMsgTrackingIqDepA _ m) = put m
      encoder (SBPMsgTrackingIqDepB _ m) = put m
      encoder (SBPMsgTrackingState _ m) = put m
      encoder (SBPMsgTrackingStateDepA _ m) = put m
      encoder (SBPMsgTrackingStateDepB _ m) = put m
      encoder (SBPMsgTrackingStateDetailedDep _ m) = put m
      encoder (SBPMsgTrackingStateDetailedDepA _ m) = put m
      encoder (SBPMsgUartState _ m) = put m
      encoder (SBPMsgUartStateDepa _ m) = put m
      encoder (SBPMsgUserData _ m) = put m
      encoder (SBPMsgUtcTime _ m) = put m
      encoder (SBPMsgVelBody _ m) = put m
      encoder (SBPMsgVelEcef _ m) = put m
      encoder (SBPMsgVelEcefCov _ m) = put m
      encoder (SBPMsgVelEcefDepA _ m) = put m
      encoder (SBPMsgVelNed _ m) = put m
      encoder (SBPMsgVelNedCov _ m) = put m
      encoder (SBPMsgVelNedDepA _ m) = put m
      encoder (SBPMsgUnknown m) = put m
      encoder (SBPMsgBadCrc m) = put m

instance FromJSON SBPMsg where
  parseJSON obj@(Object o) = do
    msgType <- o .: "msg_type"
    payload <- o .: "payload"
    decoder msgType payload where
      decoder msgType payload
        | msgType == msgAcqResult = SBPMsgAcqResult <$> pure (decode (fromStrict (unBytes payload))) <*> parseJSON obj
        | msgType == msgAcqResultDepA = SBPMsgAcqResultDepA <$> pure (decode (fromStrict (unBytes payload))) <*> parseJSON obj
        | msgType == msgAcqResultDepB = SBPMsgAcqResultDepB <$> pure (decode (fromStrict (unBytes payload))) <*> parseJSON obj
        | msgType == msgAcqResultDepC = SBPMsgAcqResultDepC <$> pure (decode (fromStrict (unBytes payload))) <*> parseJSON obj
        | msgType == msgAcqSvProfile = SBPMsgAcqSvProfile <$> pure (decode (fromStrict (unBytes payload))) <*> parseJSON obj
        | msgType == msgAcqSvProfileDep = SBPMsgAcqSvProfileDep <$> pure (decode (fromStrict (unBytes payload))) <*> parseJSON obj
        | msgType == msgAgeCorrections = SBPMsgAgeCorrections <$> pure (decode (fromStrict (unBytes payload))) <*> parseJSON obj
        | msgType == msgAlmanac = SBPMsgAlmanac <$> pure (decode (fromStrict (unBytes payload))) <*> parseJSON obj
        | msgType == msgAlmanacGlo = SBPMsgAlmanacGlo <$> pure (decode (fromStrict (unBytes payload))) <*> parseJSON obj
        | msgType == msgAlmanacGloDep = SBPMsgAlmanacGloDep <$> pure (decode (fromStrict (unBytes payload))) <*> parseJSON obj
        | msgType == msgAlmanacGps = SBPMsgAlmanacGps <$> pure (decode (fromStrict (unBytes payload))) <*> parseJSON obj
        | msgType == msgAlmanacGpsDep = SBPMsgAlmanacGpsDep <$> pure (decode (fromStrict (unBytes payload))) <*> parseJSON obj
        | msgType == msgAngularRate = SBPMsgAngularRate <$> pure (decode (fromStrict (unBytes payload))) <*> parseJSON obj
        | msgType == msgBasePosEcef = SBPMsgBasePosEcef <$> pure (decode (fromStrict (unBytes payload))) <*> parseJSON obj
        | msgType == msgBasePosLlh = SBPMsgBasePosLlh <$> pure (decode (fromStrict (unBytes payload))) <*> parseJSON obj
        | msgType == msgBaselineEcef = SBPMsgBaselineEcef <$> pure (decode (fromStrict (unBytes payload))) <*> parseJSON obj
        | msgType == msgBaselineEcefDepA = SBPMsgBaselineEcefDepA <$> pure (decode (fromStrict (unBytes payload))) <*> parseJSON obj
        | msgType == msgBaselineHeading = SBPMsgBaselineHeading <$> pure (decode (fromStrict (unBytes payload))) <*> parseJSON obj
        | msgType == msgBaselineHeadingDepA = SBPMsgBaselineHeadingDepA <$> pure (decode (fromStrict (unBytes payload))) <*> parseJSON obj
        | msgType == msgBaselineNed = SBPMsgBaselineNed <$> pure (decode (fromStrict (unBytes payload))) <*> parseJSON obj
        | msgType == msgBaselineNedDepA = SBPMsgBaselineNedDepA <$> pure (decode (fromStrict (unBytes payload))) <*> parseJSON obj
        | msgType == msgBootloaderHandshakeDepA = SBPMsgBootloaderHandshakeDepA <$> pure (decode (fromStrict (unBytes payload))) <*> parseJSON obj
        | msgType == msgBootloaderHandshakeReq = SBPMsgBootloaderHandshakeReq <$> pure (decode (fromStrict (unBytes payload))) <*> parseJSON obj
        | msgType == msgBootloaderHandshakeResp = SBPMsgBootloaderHandshakeResp <$> pure (decode (fromStrict (unBytes payload))) <*> parseJSON obj
        | msgType == msgBootloaderJumpToApp = SBPMsgBootloaderJumpToApp <$> pure (decode (fromStrict (unBytes payload))) <*> parseJSON obj
        | msgType == msgCellModemStatus = SBPMsgCellModemStatus <$> pure (decode (fromStrict (unBytes payload))) <*> parseJSON obj
        | msgType == msgCommandOutput = SBPMsgCommandOutput <$> pure (decode (fromStrict (unBytes payload))) <*> parseJSON obj
        | msgType == msgCommandReq = SBPMsgCommandReq <$> pure (decode (fromStrict (unBytes payload))) <*> parseJSON obj
        | msgType == msgCommandResp = SBPMsgCommandResp <$> pure (decode (fromStrict (unBytes payload))) <*> parseJSON obj
        | msgType == msgCsacTelemetry = SBPMsgCsacTelemetry <$> pure (decode (fromStrict (unBytes payload))) <*> parseJSON obj
        | msgType == msgCsacTelemetryLabels = SBPMsgCsacTelemetryLabels <$> pure (decode (fromStrict (unBytes payload))) <*> parseJSON obj
        | msgType == msgCwResults = SBPMsgCwResults <$> pure (decode (fromStrict (unBytes payload))) <*> parseJSON obj
        | msgType == msgCwStart = SBPMsgCwStart <$> pure (decode (fromStrict (unBytes payload))) <*> parseJSON obj
        | msgType == msgDeviceMonitor = SBPMsgDeviceMonitor <$> pure (decode (fromStrict (unBytes payload))) <*> parseJSON obj
        | msgType == msgDgnssStatus = SBPMsgDgnssStatus <$> pure (decode (fromStrict (unBytes payload))) <*> parseJSON obj
        | msgType == msgDops = SBPMsgDops <$> pure (decode (fromStrict (unBytes payload))) <*> parseJSON obj
        | msgType == msgDopsDepA = SBPMsgDopsDepA <$> pure (decode (fromStrict (unBytes payload))) <*> parseJSON obj
        | msgType == msgEphemerisBds = SBPMsgEphemerisBds <$> pure (decode (fromStrict (unBytes payload))) <*> parseJSON obj
        | msgType == msgEphemerisDepA = SBPMsgEphemerisDepA <$> pure (decode (fromStrict (unBytes payload))) <*> parseJSON obj
        | msgType == msgEphemerisDepB = SBPMsgEphemerisDepB <$> pure (decode (fromStrict (unBytes payload))) <*> parseJSON obj
        | msgType == msgEphemerisDepC = SBPMsgEphemerisDepC <$> pure (decode (fromStrict (unBytes payload))) <*> parseJSON obj
        | msgType == msgEphemerisDepD = SBPMsgEphemerisDepD <$> pure (decode (fromStrict (unBytes payload))) <*> parseJSON obj
        | msgType == msgEphemerisGal = SBPMsgEphemerisGal <$> pure (decode (fromStrict (unBytes payload))) <*> parseJSON obj
        | msgType == msgEphemerisGalDepA = SBPMsgEphemerisGalDepA <$> pure (decode (fromStrict (unBytes payload))) <*> parseJSON obj
        | msgType == msgEphemerisGlo = SBPMsgEphemerisGlo <$> pure (decode (fromStrict (unBytes payload))) <*> parseJSON obj
        | msgType == msgEphemerisGloDepA = SBPMsgEphemerisGloDepA <$> pure (decode (fromStrict (unBytes payload))) <*> parseJSON obj
        | msgType == msgEphemerisGloDepB = SBPMsgEphemerisGloDepB <$> pure (decode (fromStrict (unBytes payload))) <*> parseJSON obj
        | msgType == msgEphemerisGloDepC = SBPMsgEphemerisGloDepC <$> pure (decode (fromStrict (unBytes payload))) <*> parseJSON obj
        | msgType == msgEphemerisGloDepD = SBPMsgEphemerisGloDepD <$> pure (decode (fromStrict (unBytes payload))) <*> parseJSON obj
        | msgType == msgEphemerisGps = SBPMsgEphemerisGps <$> pure (decode (fromStrict (unBytes payload))) <*> parseJSON obj
        | msgType == msgEphemerisGpsDepE = SBPMsgEphemerisGpsDepE <$> pure (decode (fromStrict (unBytes payload))) <*> parseJSON obj
        | msgType == msgEphemerisGpsDepF = SBPMsgEphemerisGpsDepF <$> pure (decode (fromStrict (unBytes payload))) <*> parseJSON obj
        | msgType == msgEphemerisQzss = SBPMsgEphemerisQzss <$> pure (decode (fromStrict (unBytes payload))) <*> parseJSON obj
        | msgType == msgEphemerisSbas = SBPMsgEphemerisSbas <$> pure (decode (fromStrict (unBytes payload))) <*> parseJSON obj
        | msgType == msgEphemerisSbasDepA = SBPMsgEphemerisSbasDepA <$> pure (decode (fromStrict (unBytes payload))) <*> parseJSON obj
        | msgType == msgEphemerisSbasDepB = SBPMsgEphemerisSbasDepB <$> pure (decode (fromStrict (unBytes payload))) <*> parseJSON obj
        | msgType == msgExtEvent = SBPMsgExtEvent <$> pure (decode (fromStrict (unBytes payload))) <*> parseJSON obj
        | msgType == msgFileioConfigReq = SBPMsgFileioConfigReq <$> pure (decode (fromStrict (unBytes payload))) <*> parseJSON obj
        | msgType == msgFileioConfigResp = SBPMsgFileioConfigResp <$> pure (decode (fromStrict (unBytes payload))) <*> parseJSON obj
        | msgType == msgFileioReadDirReq = SBPMsgFileioReadDirReq <$> pure (decode (fromStrict (unBytes payload))) <*> parseJSON obj
        | msgType == msgFileioReadDirResp = SBPMsgFileioReadDirResp <$> pure (decode (fromStrict (unBytes payload))) <*> parseJSON obj
        | msgType == msgFileioReadReq = SBPMsgFileioReadReq <$> pure (decode (fromStrict (unBytes payload))) <*> parseJSON obj
        | msgType == msgFileioReadResp = SBPMsgFileioReadResp <$> pure (decode (fromStrict (unBytes payload))) <*> parseJSON obj
        | msgType == msgFileioRemove = SBPMsgFileioRemove <$> pure (decode (fromStrict (unBytes payload))) <*> parseJSON obj
        | msgType == msgFileioWriteReq = SBPMsgFileioWriteReq <$> pure (decode (fromStrict (unBytes payload))) <*> parseJSON obj
        | msgType == msgFileioWriteResp = SBPMsgFileioWriteResp <$> pure (decode (fromStrict (unBytes payload))) <*> parseJSON obj
        | msgType == msgFlashDone = SBPMsgFlashDone <$> pure (decode (fromStrict (unBytes payload))) <*> parseJSON obj
        | msgType == msgFlashErase = SBPMsgFlashErase <$> pure (decode (fromStrict (unBytes payload))) <*> parseJSON obj
        | msgType == msgFlashProgram = SBPMsgFlashProgram <$> pure (decode (fromStrict (unBytes payload))) <*> parseJSON obj
        | msgType == msgFlashReadReq = SBPMsgFlashReadReq <$> pure (decode (fromStrict (unBytes payload))) <*> parseJSON obj
        | msgType == msgFlashReadResp = SBPMsgFlashReadResp <$> pure (decode (fromStrict (unBytes payload))) <*> parseJSON obj
        | msgType == msgFrontEndGain = SBPMsgFrontEndGain <$> pure (decode (fromStrict (unBytes payload))) <*> parseJSON obj
        | msgType == msgFwd = SBPMsgFwd <$> pure (decode (fromStrict (unBytes payload))) <*> parseJSON obj
        | msgType == msgGloBiases = SBPMsgGloBiases <$> pure (decode (fromStrict (unBytes payload))) <*> parseJSON obj
        | msgType == msgGnssCapb = SBPMsgGnssCapb <$> pure (decode (fromStrict (unBytes payload))) <*> parseJSON obj
        | msgType == msgGpsTime = SBPMsgGpsTime <$> pure (decode (fromStrict (unBytes payload))) <*> parseJSON obj
        | msgType == msgGpsTimeDepA = SBPMsgGpsTimeDepA <$> pure (decode (fromStrict (unBytes payload))) <*> parseJSON obj
        | msgType == msgGroupDelay = SBPMsgGroupDelay <$> pure (decode (fromStrict (unBytes payload))) <*> parseJSON obj
        | msgType == msgGroupDelayDepA = SBPMsgGroupDelayDepA <$> pure (decode (fromStrict (unBytes payload))) <*> parseJSON obj
        | msgType == msgGroupDelayDepB = SBPMsgGroupDelayDepB <$> pure (decode (fromStrict (unBytes payload))) <*> parseJSON obj
        | msgType == msgHeartbeat = SBPMsgHeartbeat <$> pure (decode (fromStrict (unBytes payload))) <*> parseJSON obj
        | msgType == msgIarState = SBPMsgIarState <$> pure (decode (fromStrict (unBytes payload))) <*> parseJSON obj
        | msgType == msgImuAux = SBPMsgImuAux <$> pure (decode (fromStrict (unBytes payload))) <*> parseJSON obj
        | msgType == msgImuRaw = SBPMsgImuRaw <$> pure (decode (fromStrict (unBytes payload))) <*> parseJSON obj
        | msgType == msgInitBaseDep = SBPMsgInitBaseDep <$> pure (decode (fromStrict (unBytes payload))) <*> parseJSON obj
        | msgType == msgInsStatus = SBPMsgInsStatus <$> pure (decode (fromStrict (unBytes payload))) <*> parseJSON obj
        | msgType == msgIono = SBPMsgIono <$> pure (decode (fromStrict (unBytes payload))) <*> parseJSON obj
        | msgType == msgLinuxCpuState = SBPMsgLinuxCpuState <$> pure (decode (fromStrict (unBytes payload))) <*> parseJSON obj
        | msgType == msgLinuxMemState = SBPMsgLinuxMemState <$> pure (decode (fromStrict (unBytes payload))) <*> parseJSON obj
        | msgType == msgLinuxProcessFdCount = SBPMsgLinuxProcessFdCount <$> pure (decode (fromStrict (unBytes payload))) <*> parseJSON obj
        | msgType == msgLinuxProcessFdSummary = SBPMsgLinuxProcessFdSummary <$> pure (decode (fromStrict (unBytes payload))) <*> parseJSON obj
        | msgType == msgLinuxProcessSocketCounts = SBPMsgLinuxProcessSocketCounts <$> pure (decode (fromStrict (unBytes payload))) <*> parseJSON obj
        | msgType == msgLinuxProcessSocketQueues = SBPMsgLinuxProcessSocketQueues <$> pure (decode (fromStrict (unBytes payload))) <*> parseJSON obj
        | msgType == msgLinuxSocketUsage = SBPMsgLinuxSocketUsage <$> pure (decode (fromStrict (unBytes payload))) <*> parseJSON obj
        | msgType == msgLinuxSysState = SBPMsgLinuxSysState <$> pure (decode (fromStrict (unBytes payload))) <*> parseJSON obj
        | msgType == msgLog = SBPMsgLog <$> pure (decode (fromStrict (unBytes payload))) <*> parseJSON obj
        | msgType == msgM25FlashWriteStatus = SBPMsgM25FlashWriteStatus <$> pure (decode (fromStrict (unBytes payload))) <*> parseJSON obj
        | msgType == msgMagRaw = SBPMsgMagRaw <$> pure (decode (fromStrict (unBytes payload))) <*> parseJSON obj
        | msgType == msgMaskSatellite = SBPMsgMaskSatellite <$> pure (decode (fromStrict (unBytes payload))) <*> parseJSON obj
        | msgType == msgMaskSatelliteDep = SBPMsgMaskSatelliteDep <$> pure (decode (fromStrict (unBytes payload))) <*> parseJSON obj
        | msgType == msgMeasurementState = SBPMsgMeasurementState <$> pure (decode (fromStrict (unBytes payload))) <*> parseJSON obj
        | msgType == msgNapDeviceDnaReq = SBPMsgNapDeviceDnaReq <$> pure (decode (fromStrict (unBytes payload))) <*> parseJSON obj
        | msgType == msgNapDeviceDnaResp = SBPMsgNapDeviceDnaResp <$> pure (decode (fromStrict (unBytes payload))) <*> parseJSON obj
        | msgType == msgNdbEvent = SBPMsgNdbEvent <$> pure (decode (fromStrict (unBytes payload))) <*> parseJSON obj
        | msgType == msgNetworkBandwidthUsage = SBPMsgNetworkBandwidthUsage <$> pure (decode (fromStrict (unBytes payload))) <*> parseJSON obj
        | msgType == msgNetworkStateReq = SBPMsgNetworkStateReq <$> pure (decode (fromStrict (unBytes payload))) <*> parseJSON obj
        | msgType == msgNetworkStateResp = SBPMsgNetworkStateResp <$> pure (decode (fromStrict (unBytes payload))) <*> parseJSON obj
        | msgType == msgObs = SBPMsgObs <$> pure (decode (fromStrict (unBytes payload))) <*> parseJSON obj
        | msgType == msgObsDepA = SBPMsgObsDepA <$> pure (decode (fromStrict (unBytes payload))) <*> parseJSON obj
        | msgType == msgObsDepB = SBPMsgObsDepB <$> pure (decode (fromStrict (unBytes payload))) <*> parseJSON obj
        | msgType == msgObsDepC = SBPMsgObsDepC <$> pure (decode (fromStrict (unBytes payload))) <*> parseJSON obj
        | msgType == msgOdometry = SBPMsgOdometry <$> pure (decode (fromStrict (unBytes payload))) <*> parseJSON obj
        | msgType == msgOrientEuler = SBPMsgOrientEuler <$> pure (decode (fromStrict (unBytes payload))) <*> parseJSON obj
        | msgType == msgOrientQuat = SBPMsgOrientQuat <$> pure (decode (fromStrict (unBytes payload))) <*> parseJSON obj
        | msgType == msgOsr = SBPMsgOsr <$> pure (decode (fromStrict (unBytes payload))) <*> parseJSON obj
        | msgType == msgPosEcef = SBPMsgPosEcef <$> pure (decode (fromStrict (unBytes payload))) <*> parseJSON obj
        | msgType == msgPosEcefCov = SBPMsgPosEcefCov <$> pure (decode (fromStrict (unBytes payload))) <*> parseJSON obj
        | msgType == msgPosEcefDepA = SBPMsgPosEcefDepA <$> pure (decode (fromStrict (unBytes payload))) <*> parseJSON obj
        | msgType == msgPosLlh = SBPMsgPosLlh <$> pure (decode (fromStrict (unBytes payload))) <*> parseJSON obj
        | msgType == msgPosLlhCov = SBPMsgPosLlhCov <$> pure (decode (fromStrict (unBytes payload))) <*> parseJSON obj
        | msgType == msgPosLlhDepA = SBPMsgPosLlhDepA <$> pure (decode (fromStrict (unBytes payload))) <*> parseJSON obj
        | msgType == msgPrintDep = SBPMsgPrintDep <$> pure (decode (fromStrict (unBytes payload))) <*> parseJSON obj
        | msgType == msgProtectionLevel = SBPMsgProtectionLevel <$> pure (decode (fromStrict (unBytes payload))) <*> parseJSON obj
        | msgType == msgReset = SBPMsgReset <$> pure (decode (fromStrict (unBytes payload))) <*> parseJSON obj
        | msgType == msgResetDep = SBPMsgResetDep <$> pure (decode (fromStrict (unBytes payload))) <*> parseJSON obj
        | msgType == msgResetFilters = SBPMsgResetFilters <$> pure (decode (fromStrict (unBytes payload))) <*> parseJSON obj
        | msgType == msgSbasRaw = SBPMsgSbasRaw <$> pure (decode (fromStrict (unBytes payload))) <*> parseJSON obj
        | msgType == msgSetTime = SBPMsgSetTime <$> pure (decode (fromStrict (unBytes payload))) <*> parseJSON obj
        | msgType == msgSettingsReadByIndexDone = SBPMsgSettingsReadByIndexDone <$> pure (decode (fromStrict (unBytes payload))) <*> parseJSON obj
        | msgType == msgSettingsReadByIndexReq = SBPMsgSettingsReadByIndexReq <$> pure (decode (fromStrict (unBytes payload))) <*> parseJSON obj
        | msgType == msgSettingsReadByIndexResp = SBPMsgSettingsReadByIndexResp <$> pure (decode (fromStrict (unBytes payload))) <*> parseJSON obj
        | msgType == msgSettingsReadReq = SBPMsgSettingsReadReq <$> pure (decode (fromStrict (unBytes payload))) <*> parseJSON obj
        | msgType == msgSettingsReadResp = SBPMsgSettingsReadResp <$> pure (decode (fromStrict (unBytes payload))) <*> parseJSON obj
        | msgType == msgSettingsRegister = SBPMsgSettingsRegister <$> pure (decode (fromStrict (unBytes payload))) <*> parseJSON obj
        | msgType == msgSettingsRegisterResp = SBPMsgSettingsRegisterResp <$> pure (decode (fromStrict (unBytes payload))) <*> parseJSON obj
        | msgType == msgSettingsSave = SBPMsgSettingsSave <$> pure (decode (fromStrict (unBytes payload))) <*> parseJSON obj
        | msgType == msgSettingsWrite = SBPMsgSettingsWrite <$> pure (decode (fromStrict (unBytes payload))) <*> parseJSON obj
        | msgType == msgSettingsWriteResp = SBPMsgSettingsWriteResp <$> pure (decode (fromStrict (unBytes payload))) <*> parseJSON obj
        | msgType == msgSpecan = SBPMsgSpecan <$> pure (decode (fromStrict (unBytes payload))) <*> parseJSON obj
        | msgType == msgSpecanDep = SBPMsgSpecanDep <$> pure (decode (fromStrict (unBytes payload))) <*> parseJSON obj
        | msgType == msgSsrCodeBiases = SBPMsgSsrCodeBiases <$> pure (decode (fromStrict (unBytes payload))) <*> parseJSON obj
        | msgType == msgSsrGridDefinition = SBPMsgSsrGridDefinition <$> pure (decode (fromStrict (unBytes payload))) <*> parseJSON obj
        | msgType == msgSsrGriddedCorrection = SBPMsgSsrGriddedCorrection <$> pure (decode (fromStrict (unBytes payload))) <*> parseJSON obj
        | msgType == msgSsrOrbitClock = SBPMsgSsrOrbitClock <$> pure (decode (fromStrict (unBytes payload))) <*> parseJSON obj
        | msgType == msgSsrOrbitClockDepA = SBPMsgSsrOrbitClockDepA <$> pure (decode (fromStrict (unBytes payload))) <*> parseJSON obj
        | msgType == msgSsrPhaseBiases = SBPMsgSsrPhaseBiases <$> pure (decode (fromStrict (unBytes payload))) <*> parseJSON obj
        | msgType == msgSsrStecCorrection = SBPMsgSsrStecCorrection <$> pure (decode (fromStrict (unBytes payload))) <*> parseJSON obj
        | msgType == msgStartup = SBPMsgStartup <$> pure (decode (fromStrict (unBytes payload))) <*> parseJSON obj
        | msgType == msgStmFlashLockSector = SBPMsgStmFlashLockSector <$> pure (decode (fromStrict (unBytes payload))) <*> parseJSON obj
        | msgType == msgStmFlashUnlockSector = SBPMsgStmFlashUnlockSector <$> pure (decode (fromStrict (unBytes payload))) <*> parseJSON obj
        | msgType == msgStmUniqueIdReq = SBPMsgStmUniqueIdReq <$> pure (decode (fromStrict (unBytes payload))) <*> parseJSON obj
        | msgType == msgStmUniqueIdResp = SBPMsgStmUniqueIdResp <$> pure (decode (fromStrict (unBytes payload))) <*> parseJSON obj
        | msgType == msgSvAzEl = SBPMsgSvAzEl <$> pure (decode (fromStrict (unBytes payload))) <*> parseJSON obj
        | msgType == msgSvConfigurationGpsDep = SBPMsgSvConfigurationGpsDep <$> pure (decode (fromStrict (unBytes payload))) <*> parseJSON obj
        | msgType == msgThreadState = SBPMsgThreadState <$> pure (decode (fromStrict (unBytes payload))) <*> parseJSON obj
        | msgType == msgTrackingIq = SBPMsgTrackingIq <$> pure (decode (fromStrict (unBytes payload))) <*> parseJSON obj
        | msgType == msgTrackingIqDepA = SBPMsgTrackingIqDepA <$> pure (decode (fromStrict (unBytes payload))) <*> parseJSON obj
        | msgType == msgTrackingIqDepB = SBPMsgTrackingIqDepB <$> pure (decode (fromStrict (unBytes payload))) <*> parseJSON obj
        | msgType == msgTrackingState = SBPMsgTrackingState <$> pure (decode (fromStrict (unBytes payload))) <*> parseJSON obj
        | msgType == msgTrackingStateDepA = SBPMsgTrackingStateDepA <$> pure (decode (fromStrict (unBytes payload))) <*> parseJSON obj
        | msgType == msgTrackingStateDepB = SBPMsgTrackingStateDepB <$> pure (decode (fromStrict (unBytes payload))) <*> parseJSON obj
        | msgType == msgTrackingStateDetailedDep = SBPMsgTrackingStateDetailedDep <$> pure (decode (fromStrict (unBytes payload))) <*> parseJSON obj
        | msgType == msgTrackingStateDetailedDepA = SBPMsgTrackingStateDetailedDepA <$> pure (decode (fromStrict (unBytes payload))) <*> parseJSON obj
        | msgType == msgUartState = SBPMsgUartState <$> pure (decode (fromStrict (unBytes payload))) <*> parseJSON obj
        | msgType == msgUartStateDepa = SBPMsgUartStateDepa <$> pure (decode (fromStrict (unBytes payload))) <*> parseJSON obj
        | msgType == msgUserData = SBPMsgUserData <$> pure (decode (fromStrict (unBytes payload))) <*> parseJSON obj
        | msgType == msgUtcTime = SBPMsgUtcTime <$> pure (decode (fromStrict (unBytes payload))) <*> parseJSON obj
        | msgType == msgVelBody = SBPMsgVelBody <$> pure (decode (fromStrict (unBytes payload))) <*> parseJSON obj
        | msgType == msgVelEcef = SBPMsgVelEcef <$> pure (decode (fromStrict (unBytes payload))) <*> parseJSON obj
        | msgType == msgVelEcefCov = SBPMsgVelEcefCov <$> pure (decode (fromStrict (unBytes payload))) <*> parseJSON obj
        | msgType == msgVelEcefDepA = SBPMsgVelEcefDepA <$> pure (decode (fromStrict (unBytes payload))) <*> parseJSON obj
        | msgType == msgVelNed = SBPMsgVelNed <$> pure (decode (fromStrict (unBytes payload))) <*> parseJSON obj
        | msgType == msgVelNedCov = SBPMsgVelNedCov <$> pure (decode (fromStrict (unBytes payload))) <*> parseJSON obj
        | msgType == msgVelNedDepA = SBPMsgVelNedDepA <$> pure (decode (fromStrict (unBytes payload))) <*> parseJSON obj
        | otherwise = SBPMsgUnknown <$> parseJSON obj
  parseJSON _ = mzero

(<<>>) :: Value -> Value -> Value
(<<>>) a b = fromMaybe Null $ do
  a' <- preview _Object a
  b' <- preview _Object b
  pure $ review _Object $ a' <> b'

instance ToJSON SBPMsg where
  toJSON (SBPMsgAcqResult n m) = toJSON n <<>> toJSON m
  toJSON (SBPMsgAcqResultDepA n m) = toJSON n <<>> toJSON m
  toJSON (SBPMsgAcqResultDepB n m) = toJSON n <<>> toJSON m
  toJSON (SBPMsgAcqResultDepC n m) = toJSON n <<>> toJSON m
  toJSON (SBPMsgAcqSvProfile n m) = toJSON n <<>> toJSON m
  toJSON (SBPMsgAcqSvProfileDep n m) = toJSON n <<>> toJSON m
  toJSON (SBPMsgAgeCorrections n m) = toJSON n <<>> toJSON m
  toJSON (SBPMsgAlmanac _ m) = toJSON m
  toJSON (SBPMsgAlmanacGlo n m) = toJSON n <<>> toJSON m
  toJSON (SBPMsgAlmanacGloDep n m) = toJSON n <<>> toJSON m
  toJSON (SBPMsgAlmanacGps n m) = toJSON n <<>> toJSON m
  toJSON (SBPMsgAlmanacGpsDep n m) = toJSON n <<>> toJSON m
  toJSON (SBPMsgAngularRate n m) = toJSON n <<>> toJSON m
  toJSON (SBPMsgBasePosEcef n m) = toJSON n <<>> toJSON m
  toJSON (SBPMsgBasePosLlh n m) = toJSON n <<>> toJSON m
  toJSON (SBPMsgBaselineEcef n m) = toJSON n <<>> toJSON m
  toJSON (SBPMsgBaselineEcefDepA n m) = toJSON n <<>> toJSON m
  toJSON (SBPMsgBaselineHeading n m) = toJSON n <<>> toJSON m
  toJSON (SBPMsgBaselineHeadingDepA n m) = toJSON n <<>> toJSON m
  toJSON (SBPMsgBaselineNed n m) = toJSON n <<>> toJSON m
  toJSON (SBPMsgBaselineNedDepA n m) = toJSON n <<>> toJSON m
  toJSON (SBPMsgBootloaderHandshakeDepA n m) = toJSON n <<>> toJSON m
  toJSON (SBPMsgBootloaderHandshakeReq _ m) = toJSON m
  toJSON (SBPMsgBootloaderHandshakeResp n m) = toJSON n <<>> toJSON m
  toJSON (SBPMsgBootloaderJumpToApp n m) = toJSON n <<>> toJSON m
  toJSON (SBPMsgCellModemStatus n m) = toJSON n <<>> toJSON m
  toJSON (SBPMsgCommandOutput n m) = toJSON n <<>> toJSON m
  toJSON (SBPMsgCommandReq n m) = toJSON n <<>> toJSON m
  toJSON (SBPMsgCommandResp n m) = toJSON n <<>> toJSON m
  toJSON (SBPMsgCsacTelemetry n m) = toJSON n <<>> toJSON m
  toJSON (SBPMsgCsacTelemetryLabels n m) = toJSON n <<>> toJSON m
  toJSON (SBPMsgCwResults _ m) = toJSON m
  toJSON (SBPMsgCwStart _ m) = toJSON m
  toJSON (SBPMsgDeviceMonitor n m) = toJSON n <<>> toJSON m
  toJSON (SBPMsgDgnssStatus n m) = toJSON n <<>> toJSON m
  toJSON (SBPMsgDops n m) = toJSON n <<>> toJSON m
  toJSON (SBPMsgDopsDepA n m) = toJSON n <<>> toJSON m
  toJSON (SBPMsgEphemerisBds n m) = toJSON n <<>> toJSON m
  toJSON (SBPMsgEphemerisDepA n m) = toJSON n <<>> toJSON m
  toJSON (SBPMsgEphemerisDepB n m) = toJSON n <<>> toJSON m
  toJSON (SBPMsgEphemerisDepC n m) = toJSON n <<>> toJSON m
  toJSON (SBPMsgEphemerisDepD n m) = toJSON n <<>> toJSON m
  toJSON (SBPMsgEphemerisGal n m) = toJSON n <<>> toJSON m
  toJSON (SBPMsgEphemerisGalDepA n m) = toJSON n <<>> toJSON m
  toJSON (SBPMsgEphemerisGlo n m) = toJSON n <<>> toJSON m
  toJSON (SBPMsgEphemerisGloDepA n m) = toJSON n <<>> toJSON m
  toJSON (SBPMsgEphemerisGloDepB n m) = toJSON n <<>> toJSON m
  toJSON (SBPMsgEphemerisGloDepC n m) = toJSON n <<>> toJSON m
  toJSON (SBPMsgEphemerisGloDepD n m) = toJSON n <<>> toJSON m
  toJSON (SBPMsgEphemerisGps n m) = toJSON n <<>> toJSON m
  toJSON (SBPMsgEphemerisGpsDepE n m) = toJSON n <<>> toJSON m
  toJSON (SBPMsgEphemerisGpsDepF n m) = toJSON n <<>> toJSON m
  toJSON (SBPMsgEphemerisQzss n m) = toJSON n <<>> toJSON m
  toJSON (SBPMsgEphemerisSbas n m) = toJSON n <<>> toJSON m
  toJSON (SBPMsgEphemerisSbasDepA n m) = toJSON n <<>> toJSON m
  toJSON (SBPMsgEphemerisSbasDepB n m) = toJSON n <<>> toJSON m
  toJSON (SBPMsgExtEvent n m) = toJSON n <<>> toJSON m
  toJSON (SBPMsgFileioConfigReq n m) = toJSON n <<>> toJSON m
  toJSON (SBPMsgFileioConfigResp n m) = toJSON n <<>> toJSON m
  toJSON (SBPMsgFileioReadDirReq n m) = toJSON n <<>> toJSON m
  toJSON (SBPMsgFileioReadDirResp n m) = toJSON n <<>> toJSON m
  toJSON (SBPMsgFileioReadReq n m) = toJSON n <<>> toJSON m
  toJSON (SBPMsgFileioReadResp n m) = toJSON n <<>> toJSON m
  toJSON (SBPMsgFileioRemove n m) = toJSON n <<>> toJSON m
  toJSON (SBPMsgFileioWriteReq n m) = toJSON n <<>> toJSON m
  toJSON (SBPMsgFileioWriteResp n m) = toJSON n <<>> toJSON m
  toJSON (SBPMsgFlashDone n m) = toJSON n <<>> toJSON m
  toJSON (SBPMsgFlashErase n m) = toJSON n <<>> toJSON m
  toJSON (SBPMsgFlashProgram n m) = toJSON n <<>> toJSON m
  toJSON (SBPMsgFlashReadReq n m) = toJSON n <<>> toJSON m
  toJSON (SBPMsgFlashReadResp n m) = toJSON n <<>> toJSON m
  toJSON (SBPMsgFrontEndGain n m) = toJSON n <<>> toJSON m
  toJSON (SBPMsgFwd n m) = toJSON n <<>> toJSON m
  toJSON (SBPMsgGloBiases n m) = toJSON n <<>> toJSON m
  toJSON (SBPMsgGnssCapb n m) = toJSON n <<>> toJSON m
  toJSON (SBPMsgGpsTime n m) = toJSON n <<>> toJSON m
  toJSON (SBPMsgGpsTimeDepA n m) = toJSON n <<>> toJSON m
  toJSON (SBPMsgGroupDelay n m) = toJSON n <<>> toJSON m
  toJSON (SBPMsgGroupDelayDepA n m) = toJSON n <<>> toJSON m
  toJSON (SBPMsgGroupDelayDepB n m) = toJSON n <<>> toJSON m
  toJSON (SBPMsgHeartbeat n m) = toJSON n <<>> toJSON m
  toJSON (SBPMsgIarState n m) = toJSON n <<>> toJSON m
  toJSON (SBPMsgImuAux n m) = toJSON n <<>> toJSON m
  toJSON (SBPMsgImuRaw n m) = toJSON n <<>> toJSON m
  toJSON (SBPMsgInitBaseDep _ m) = toJSON m
  toJSON (SBPMsgInsStatus n m) = toJSON n <<>> toJSON m
  toJSON (SBPMsgIono n m) = toJSON n <<>> toJSON m
  toJSON (SBPMsgLinuxCpuState n m) = toJSON n <<>> toJSON m
  toJSON (SBPMsgLinuxMemState n m) = toJSON n <<>> toJSON m
  toJSON (SBPMsgLinuxProcessFdCount n m) = toJSON n <<>> toJSON m
  toJSON (SBPMsgLinuxProcessFdSummary n m) = toJSON n <<>> toJSON m
  toJSON (SBPMsgLinuxProcessSocketCounts n m) = toJSON n <<>> toJSON m
  toJSON (SBPMsgLinuxProcessSocketQueues n m) = toJSON n <<>> toJSON m
  toJSON (SBPMsgLinuxSocketUsage n m) = toJSON n <<>> toJSON m
  toJSON (SBPMsgLinuxSysState n m) = toJSON n <<>> toJSON m
  toJSON (SBPMsgLog n m) = toJSON n <<>> toJSON m
  toJSON (SBPMsgM25FlashWriteStatus n m) = toJSON n <<>> toJSON m
  toJSON (SBPMsgMagRaw n m) = toJSON n <<>> toJSON m
  toJSON (SBPMsgMaskSatellite n m) = toJSON n <<>> toJSON m
  toJSON (SBPMsgMaskSatelliteDep n m) = toJSON n <<>> toJSON m
  toJSON (SBPMsgMeasurementState n m) = toJSON n <<>> toJSON m
  toJSON (SBPMsgNapDeviceDnaReq _ m) = toJSON m
  toJSON (SBPMsgNapDeviceDnaResp n m) = toJSON n <<>> toJSON m
  toJSON (SBPMsgNdbEvent n m) = toJSON n <<>> toJSON m
  toJSON (SBPMsgNetworkBandwidthUsage n m) = toJSON n <<>> toJSON m
  toJSON (SBPMsgNetworkStateReq _ m) = toJSON m
  toJSON (SBPMsgNetworkStateResp n m) = toJSON n <<>> toJSON m
  toJSON (SBPMsgObs n m) = toJSON n <<>> toJSON m
  toJSON (SBPMsgObsDepA n m) = toJSON n <<>> toJSON m
  toJSON (SBPMsgObsDepB n m) = toJSON n <<>> toJSON m
  toJSON (SBPMsgObsDepC n m) = toJSON n <<>> toJSON m
  toJSON (SBPMsgOdometry n m) = toJSON n <<>> toJSON m
  toJSON (SBPMsgOrientEuler n m) = toJSON n <<>> toJSON m
  toJSON (SBPMsgOrientQuat n m) = toJSON n <<>> toJSON m
  toJSON (SBPMsgOsr n m) = toJSON n <<>> toJSON m
  toJSON (SBPMsgPosEcef n m) = toJSON n <<>> toJSON m
  toJSON (SBPMsgPosEcefCov n m) = toJSON n <<>> toJSON m
  toJSON (SBPMsgPosEcefDepA n m) = toJSON n <<>> toJSON m
  toJSON (SBPMsgPosLlh n m) = toJSON n <<>> toJSON m
  toJSON (SBPMsgPosLlhCov n m) = toJSON n <<>> toJSON m
  toJSON (SBPMsgPosLlhDepA n m) = toJSON n <<>> toJSON m
  toJSON (SBPMsgPrintDep n m) = toJSON n <<>> toJSON m
  toJSON (SBPMsgProtectionLevel n m) = toJSON n <<>> toJSON m
  toJSON (SBPMsgReset n m) = toJSON n <<>> toJSON m
  toJSON (SBPMsgResetDep _ m) = toJSON m
  toJSON (SBPMsgResetFilters n m) = toJSON n <<>> toJSON m
  toJSON (SBPMsgSbasRaw n m) = toJSON n <<>> toJSON m
  toJSON (SBPMsgSetTime _ m) = toJSON m
  toJSON (SBPMsgSettingsReadByIndexDone _ m) = toJSON m
  toJSON (SBPMsgSettingsReadByIndexReq n m) = toJSON n <<>> toJSON m
  toJSON (SBPMsgSettingsReadByIndexResp n m) = toJSON n <<>> toJSON m
  toJSON (SBPMsgSettingsReadReq n m) = toJSON n <<>> toJSON m
  toJSON (SBPMsgSettingsReadResp n m) = toJSON n <<>> toJSON m
  toJSON (SBPMsgSettingsRegister n m) = toJSON n <<>> toJSON m
  toJSON (SBPMsgSettingsRegisterResp n m) = toJSON n <<>> toJSON m
  toJSON (SBPMsgSettingsSave _ m) = toJSON m
  toJSON (SBPMsgSettingsWrite n m) = toJSON n <<>> toJSON m
  toJSON (SBPMsgSettingsWriteResp n m) = toJSON n <<>> toJSON m
  toJSON (SBPMsgSpecan n m) = toJSON n <<>> toJSON m
  toJSON (SBPMsgSpecanDep n m) = toJSON n <<>> toJSON m
  toJSON (SBPMsgSsrCodeBiases n m) = toJSON n <<>> toJSON m
  toJSON (SBPMsgSsrGridDefinition n m) = toJSON n <<>> toJSON m
  toJSON (SBPMsgSsrGriddedCorrection n m) = toJSON n <<>> toJSON m
  toJSON (SBPMsgSsrOrbitClock n m) = toJSON n <<>> toJSON m
  toJSON (SBPMsgSsrOrbitClockDepA n m) = toJSON n <<>> toJSON m
  toJSON (SBPMsgSsrPhaseBiases n m) = toJSON n <<>> toJSON m
  toJSON (SBPMsgSsrStecCorrection n m) = toJSON n <<>> toJSON m
  toJSON (SBPMsgStartup n m) = toJSON n <<>> toJSON m
  toJSON (SBPMsgStmFlashLockSector n m) = toJSON n <<>> toJSON m
  toJSON (SBPMsgStmFlashUnlockSector n m) = toJSON n <<>> toJSON m
  toJSON (SBPMsgStmUniqueIdReq _ m) = toJSON m
  toJSON (SBPMsgStmUniqueIdResp n m) = toJSON n <<>> toJSON m
  toJSON (SBPMsgSvAzEl n m) = toJSON n <<>> toJSON m
  toJSON (SBPMsgSvConfigurationGpsDep n m) = toJSON n <<>> toJSON m
  toJSON (SBPMsgThreadState n m) = toJSON n <<>> toJSON m
  toJSON (SBPMsgTrackingIq n m) = toJSON n <<>> toJSON m
  toJSON (SBPMsgTrackingIqDepA n m) = toJSON n <<>> toJSON m
  toJSON (SBPMsgTrackingIqDepB n m) = toJSON n <<>> toJSON m
  toJSON (SBPMsgTrackingState n m) = toJSON n <<>> toJSON m
  toJSON (SBPMsgTrackingStateDepA n m) = toJSON n <<>> toJSON m
  toJSON (SBPMsgTrackingStateDepB n m) = toJSON n <<>> toJSON m
  toJSON (SBPMsgTrackingStateDetailedDep n m) = toJSON n <<>> toJSON m
  toJSON (SBPMsgTrackingStateDetailedDepA n m) = toJSON n <<>> toJSON m
  toJSON (SBPMsgUartState n m) = toJSON n <<>> toJSON m
  toJSON (SBPMsgUartStateDepa n m) = toJSON n <<>> toJSON m
  toJSON (SBPMsgUserData n m) = toJSON n <<>> toJSON m
  toJSON (SBPMsgUtcTime n m) = toJSON n <<>> toJSON m
  toJSON (SBPMsgVelBody n m) = toJSON n <<>> toJSON m
  toJSON (SBPMsgVelEcef n m) = toJSON n <<>> toJSON m
  toJSON (SBPMsgVelEcefCov n m) = toJSON n <<>> toJSON m
  toJSON (SBPMsgVelEcefDepA n m) = toJSON n <<>> toJSON m
  toJSON (SBPMsgVelNed n m) = toJSON n <<>> toJSON m
  toJSON (SBPMsgVelNedCov n m) = toJSON n <<>> toJSON m
  toJSON (SBPMsgVelNedDepA n m) = toJSON n <<>> toJSON m
  toJSON (SBPMsgBadCrc m) = toJSON m
  toJSON (SBPMsgUnknown m) = toJSON m

instance HasMsg SBPMsg where
  msg f (SBPMsgAcqResult n m) = SBPMsgAcqResult n <$> f m
  msg f (SBPMsgAcqResultDepA n m) = SBPMsgAcqResultDepA n <$> f m
  msg f (SBPMsgAcqResultDepB n m) = SBPMsgAcqResultDepB n <$> f m
  msg f (SBPMsgAcqResultDepC n m) = SBPMsgAcqResultDepC n <$> f m
  msg f (SBPMsgAcqSvProfile n m) = SBPMsgAcqSvProfile n <$> f m
  msg f (SBPMsgAcqSvProfileDep n m) = SBPMsgAcqSvProfileDep n <$> f m
  msg f (SBPMsgAgeCorrections n m) = SBPMsgAgeCorrections n <$> f m
  msg f (SBPMsgAlmanac n m) = SBPMsgAlmanac n <$> f m
  msg f (SBPMsgAlmanacGlo n m) = SBPMsgAlmanacGlo n <$> f m
  msg f (SBPMsgAlmanacGloDep n m) = SBPMsgAlmanacGloDep n <$> f m
  msg f (SBPMsgAlmanacGps n m) = SBPMsgAlmanacGps n <$> f m
  msg f (SBPMsgAlmanacGpsDep n m) = SBPMsgAlmanacGpsDep n <$> f m
  msg f (SBPMsgAngularRate n m) = SBPMsgAngularRate n <$> f m
  msg f (SBPMsgBasePosEcef n m) = SBPMsgBasePosEcef n <$> f m
  msg f (SBPMsgBasePosLlh n m) = SBPMsgBasePosLlh n <$> f m
  msg f (SBPMsgBaselineEcef n m) = SBPMsgBaselineEcef n <$> f m
  msg f (SBPMsgBaselineEcefDepA n m) = SBPMsgBaselineEcefDepA n <$> f m
  msg f (SBPMsgBaselineHeading n m) = SBPMsgBaselineHeading n <$> f m
  msg f (SBPMsgBaselineHeadingDepA n m) = SBPMsgBaselineHeadingDepA n <$> f m
  msg f (SBPMsgBaselineNed n m) = SBPMsgBaselineNed n <$> f m
  msg f (SBPMsgBaselineNedDepA n m) = SBPMsgBaselineNedDepA n <$> f m
  msg f (SBPMsgBootloaderHandshakeDepA n m) = SBPMsgBootloaderHandshakeDepA n <$> f m
  msg f (SBPMsgBootloaderHandshakeReq n m) = SBPMsgBootloaderHandshakeReq n <$> f m
  msg f (SBPMsgBootloaderHandshakeResp n m) = SBPMsgBootloaderHandshakeResp n <$> f m
  msg f (SBPMsgBootloaderJumpToApp n m) = SBPMsgBootloaderJumpToApp n <$> f m
  msg f (SBPMsgCellModemStatus n m) = SBPMsgCellModemStatus n <$> f m
  msg f (SBPMsgCommandOutput n m) = SBPMsgCommandOutput n <$> f m
  msg f (SBPMsgCommandReq n m) = SBPMsgCommandReq n <$> f m
  msg f (SBPMsgCommandResp n m) = SBPMsgCommandResp n <$> f m
  msg f (SBPMsgCsacTelemetry n m) = SBPMsgCsacTelemetry n <$> f m
  msg f (SBPMsgCsacTelemetryLabels n m) = SBPMsgCsacTelemetryLabels n <$> f m
  msg f (SBPMsgCwResults n m) = SBPMsgCwResults n <$> f m
  msg f (SBPMsgCwStart n m) = SBPMsgCwStart n <$> f m
  msg f (SBPMsgDeviceMonitor n m) = SBPMsgDeviceMonitor n <$> f m
  msg f (SBPMsgDgnssStatus n m) = SBPMsgDgnssStatus n <$> f m
  msg f (SBPMsgDops n m) = SBPMsgDops n <$> f m
  msg f (SBPMsgDopsDepA n m) = SBPMsgDopsDepA n <$> f m
  msg f (SBPMsgEphemerisBds n m) = SBPMsgEphemerisBds n <$> f m
  msg f (SBPMsgEphemerisDepA n m) = SBPMsgEphemerisDepA n <$> f m
  msg f (SBPMsgEphemerisDepB n m) = SBPMsgEphemerisDepB n <$> f m
  msg f (SBPMsgEphemerisDepC n m) = SBPMsgEphemerisDepC n <$> f m
  msg f (SBPMsgEphemerisDepD n m) = SBPMsgEphemerisDepD n <$> f m
  msg f (SBPMsgEphemerisGal n m) = SBPMsgEphemerisGal n <$> f m
  msg f (SBPMsgEphemerisGalDepA n m) = SBPMsgEphemerisGalDepA n <$> f m
  msg f (SBPMsgEphemerisGlo n m) = SBPMsgEphemerisGlo n <$> f m
  msg f (SBPMsgEphemerisGloDepA n m) = SBPMsgEphemerisGloDepA n <$> f m
  msg f (SBPMsgEphemerisGloDepB n m) = SBPMsgEphemerisGloDepB n <$> f m
  msg f (SBPMsgEphemerisGloDepC n m) = SBPMsgEphemerisGloDepC n <$> f m
  msg f (SBPMsgEphemerisGloDepD n m) = SBPMsgEphemerisGloDepD n <$> f m
  msg f (SBPMsgEphemerisGps n m) = SBPMsgEphemerisGps n <$> f m
  msg f (SBPMsgEphemerisGpsDepE n m) = SBPMsgEphemerisGpsDepE n <$> f m
  msg f (SBPMsgEphemerisGpsDepF n m) = SBPMsgEphemerisGpsDepF n <$> f m
  msg f (SBPMsgEphemerisQzss n m) = SBPMsgEphemerisQzss n <$> f m
  msg f (SBPMsgEphemerisSbas n m) = SBPMsgEphemerisSbas n <$> f m
  msg f (SBPMsgEphemerisSbasDepA n m) = SBPMsgEphemerisSbasDepA n <$> f m
  msg f (SBPMsgEphemerisSbasDepB n m) = SBPMsgEphemerisSbasDepB n <$> f m
  msg f (SBPMsgExtEvent n m) = SBPMsgExtEvent n <$> f m
  msg f (SBPMsgFileioConfigReq n m) = SBPMsgFileioConfigReq n <$> f m
  msg f (SBPMsgFileioConfigResp n m) = SBPMsgFileioConfigResp n <$> f m
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
  msg f (SBPMsgFrontEndGain n m) = SBPMsgFrontEndGain n <$> f m
  msg f (SBPMsgFwd n m) = SBPMsgFwd n <$> f m
  msg f (SBPMsgGloBiases n m) = SBPMsgGloBiases n <$> f m
  msg f (SBPMsgGnssCapb n m) = SBPMsgGnssCapb n <$> f m
  msg f (SBPMsgGpsTime n m) = SBPMsgGpsTime n <$> f m
  msg f (SBPMsgGpsTimeDepA n m) = SBPMsgGpsTimeDepA n <$> f m
  msg f (SBPMsgGroupDelay n m) = SBPMsgGroupDelay n <$> f m
  msg f (SBPMsgGroupDelayDepA n m) = SBPMsgGroupDelayDepA n <$> f m
  msg f (SBPMsgGroupDelayDepB n m) = SBPMsgGroupDelayDepB n <$> f m
  msg f (SBPMsgHeartbeat n m) = SBPMsgHeartbeat n <$> f m
  msg f (SBPMsgIarState n m) = SBPMsgIarState n <$> f m
  msg f (SBPMsgImuAux n m) = SBPMsgImuAux n <$> f m
  msg f (SBPMsgImuRaw n m) = SBPMsgImuRaw n <$> f m
  msg f (SBPMsgInitBaseDep n m) = SBPMsgInitBaseDep n <$> f m
  msg f (SBPMsgInsStatus n m) = SBPMsgInsStatus n <$> f m
  msg f (SBPMsgIono n m) = SBPMsgIono n <$> f m
  msg f (SBPMsgLinuxCpuState n m) = SBPMsgLinuxCpuState n <$> f m
  msg f (SBPMsgLinuxMemState n m) = SBPMsgLinuxMemState n <$> f m
  msg f (SBPMsgLinuxProcessFdCount n m) = SBPMsgLinuxProcessFdCount n <$> f m
  msg f (SBPMsgLinuxProcessFdSummary n m) = SBPMsgLinuxProcessFdSummary n <$> f m
  msg f (SBPMsgLinuxProcessSocketCounts n m) = SBPMsgLinuxProcessSocketCounts n <$> f m
  msg f (SBPMsgLinuxProcessSocketQueues n m) = SBPMsgLinuxProcessSocketQueues n <$> f m
  msg f (SBPMsgLinuxSocketUsage n m) = SBPMsgLinuxSocketUsage n <$> f m
  msg f (SBPMsgLinuxSysState n m) = SBPMsgLinuxSysState n <$> f m
  msg f (SBPMsgLog n m) = SBPMsgLog n <$> f m
  msg f (SBPMsgM25FlashWriteStatus n m) = SBPMsgM25FlashWriteStatus n <$> f m
  msg f (SBPMsgMagRaw n m) = SBPMsgMagRaw n <$> f m
  msg f (SBPMsgMaskSatellite n m) = SBPMsgMaskSatellite n <$> f m
  msg f (SBPMsgMaskSatelliteDep n m) = SBPMsgMaskSatelliteDep n <$> f m
  msg f (SBPMsgMeasurementState n m) = SBPMsgMeasurementState n <$> f m
  msg f (SBPMsgNapDeviceDnaReq n m) = SBPMsgNapDeviceDnaReq n <$> f m
  msg f (SBPMsgNapDeviceDnaResp n m) = SBPMsgNapDeviceDnaResp n <$> f m
  msg f (SBPMsgNdbEvent n m) = SBPMsgNdbEvent n <$> f m
  msg f (SBPMsgNetworkBandwidthUsage n m) = SBPMsgNetworkBandwidthUsage n <$> f m
  msg f (SBPMsgNetworkStateReq n m) = SBPMsgNetworkStateReq n <$> f m
  msg f (SBPMsgNetworkStateResp n m) = SBPMsgNetworkStateResp n <$> f m
  msg f (SBPMsgObs n m) = SBPMsgObs n <$> f m
  msg f (SBPMsgObsDepA n m) = SBPMsgObsDepA n <$> f m
  msg f (SBPMsgObsDepB n m) = SBPMsgObsDepB n <$> f m
  msg f (SBPMsgObsDepC n m) = SBPMsgObsDepC n <$> f m
  msg f (SBPMsgOdometry n m) = SBPMsgOdometry n <$> f m
  msg f (SBPMsgOrientEuler n m) = SBPMsgOrientEuler n <$> f m
  msg f (SBPMsgOrientQuat n m) = SBPMsgOrientQuat n <$> f m
  msg f (SBPMsgOsr n m) = SBPMsgOsr n <$> f m
  msg f (SBPMsgPosEcef n m) = SBPMsgPosEcef n <$> f m
  msg f (SBPMsgPosEcefCov n m) = SBPMsgPosEcefCov n <$> f m
  msg f (SBPMsgPosEcefDepA n m) = SBPMsgPosEcefDepA n <$> f m
  msg f (SBPMsgPosLlh n m) = SBPMsgPosLlh n <$> f m
  msg f (SBPMsgPosLlhCov n m) = SBPMsgPosLlhCov n <$> f m
  msg f (SBPMsgPosLlhDepA n m) = SBPMsgPosLlhDepA n <$> f m
  msg f (SBPMsgPrintDep n m) = SBPMsgPrintDep n <$> f m
  msg f (SBPMsgProtectionLevel n m) = SBPMsgProtectionLevel n <$> f m
  msg f (SBPMsgReset n m) = SBPMsgReset n <$> f m
  msg f (SBPMsgResetDep n m) = SBPMsgResetDep n <$> f m
  msg f (SBPMsgResetFilters n m) = SBPMsgResetFilters n <$> f m
  msg f (SBPMsgSbasRaw n m) = SBPMsgSbasRaw n <$> f m
  msg f (SBPMsgSetTime n m) = SBPMsgSetTime n <$> f m
  msg f (SBPMsgSettingsReadByIndexDone n m) = SBPMsgSettingsReadByIndexDone n <$> f m
  msg f (SBPMsgSettingsReadByIndexReq n m) = SBPMsgSettingsReadByIndexReq n <$> f m
  msg f (SBPMsgSettingsReadByIndexResp n m) = SBPMsgSettingsReadByIndexResp n <$> f m
  msg f (SBPMsgSettingsReadReq n m) = SBPMsgSettingsReadReq n <$> f m
  msg f (SBPMsgSettingsReadResp n m) = SBPMsgSettingsReadResp n <$> f m
  msg f (SBPMsgSettingsRegister n m) = SBPMsgSettingsRegister n <$> f m
  msg f (SBPMsgSettingsRegisterResp n m) = SBPMsgSettingsRegisterResp n <$> f m
  msg f (SBPMsgSettingsSave n m) = SBPMsgSettingsSave n <$> f m
  msg f (SBPMsgSettingsWrite n m) = SBPMsgSettingsWrite n <$> f m
  msg f (SBPMsgSettingsWriteResp n m) = SBPMsgSettingsWriteResp n <$> f m
  msg f (SBPMsgSpecan n m) = SBPMsgSpecan n <$> f m
  msg f (SBPMsgSpecanDep n m) = SBPMsgSpecanDep n <$> f m
  msg f (SBPMsgSsrCodeBiases n m) = SBPMsgSsrCodeBiases n <$> f m
  msg f (SBPMsgSsrGridDefinition n m) = SBPMsgSsrGridDefinition n <$> f m
  msg f (SBPMsgSsrGriddedCorrection n m) = SBPMsgSsrGriddedCorrection n <$> f m
  msg f (SBPMsgSsrOrbitClock n m) = SBPMsgSsrOrbitClock n <$> f m
  msg f (SBPMsgSsrOrbitClockDepA n m) = SBPMsgSsrOrbitClockDepA n <$> f m
  msg f (SBPMsgSsrPhaseBiases n m) = SBPMsgSsrPhaseBiases n <$> f m
  msg f (SBPMsgSsrStecCorrection n m) = SBPMsgSsrStecCorrection n <$> f m
  msg f (SBPMsgStartup n m) = SBPMsgStartup n <$> f m
  msg f (SBPMsgStmFlashLockSector n m) = SBPMsgStmFlashLockSector n <$> f m
  msg f (SBPMsgStmFlashUnlockSector n m) = SBPMsgStmFlashUnlockSector n <$> f m
  msg f (SBPMsgStmUniqueIdReq n m) = SBPMsgStmUniqueIdReq n <$> f m
  msg f (SBPMsgStmUniqueIdResp n m) = SBPMsgStmUniqueIdResp n <$> f m
  msg f (SBPMsgSvAzEl n m) = SBPMsgSvAzEl n <$> f m
  msg f (SBPMsgSvConfigurationGpsDep n m) = SBPMsgSvConfigurationGpsDep n <$> f m
  msg f (SBPMsgThreadState n m) = SBPMsgThreadState n <$> f m
  msg f (SBPMsgTrackingIq n m) = SBPMsgTrackingIq n <$> f m
  msg f (SBPMsgTrackingIqDepA n m) = SBPMsgTrackingIqDepA n <$> f m
  msg f (SBPMsgTrackingIqDepB n m) = SBPMsgTrackingIqDepB n <$> f m
  msg f (SBPMsgTrackingState n m) = SBPMsgTrackingState n <$> f m
  msg f (SBPMsgTrackingStateDepA n m) = SBPMsgTrackingStateDepA n <$> f m
  msg f (SBPMsgTrackingStateDepB n m) = SBPMsgTrackingStateDepB n <$> f m
  msg f (SBPMsgTrackingStateDetailedDep n m) = SBPMsgTrackingStateDetailedDep n <$> f m
  msg f (SBPMsgTrackingStateDetailedDepA n m) = SBPMsgTrackingStateDetailedDepA n <$> f m
  msg f (SBPMsgUartState n m) = SBPMsgUartState n <$> f m
  msg f (SBPMsgUartStateDepa n m) = SBPMsgUartStateDepa n <$> f m
  msg f (SBPMsgUserData n m) = SBPMsgUserData n <$> f m
  msg f (SBPMsgUtcTime n m) = SBPMsgUtcTime n <$> f m
  msg f (SBPMsgVelBody n m) = SBPMsgVelBody n <$> f m
  msg f (SBPMsgVelEcef n m) = SBPMsgVelEcef n <$> f m
  msg f (SBPMsgVelEcefCov n m) = SBPMsgVelEcefCov n <$> f m
  msg f (SBPMsgVelEcefDepA n m) = SBPMsgVelEcefDepA n <$> f m
  msg f (SBPMsgVelNed n m) = SBPMsgVelNed n <$> f m
  msg f (SBPMsgVelNedCov n m) = SBPMsgVelNedCov n <$> f m
  msg f (SBPMsgVelNedDepA n m) = SBPMsgVelNedDepA n <$> f m
  msg f (SBPMsgUnknown m) = SBPMsgUnknown <$> f m
  msg f (SBPMsgBadCrc m) = SBPMsgBadCrc <$> f m