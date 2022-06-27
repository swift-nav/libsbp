/* Copyright (C) 2015-2022 Swift Navigation Inc.
 * Contact: https://support.swiftnav.com
 *
 * This source is subject to the license found in the file 'LICENSE' which must
 * be be distributed together with this source. All other rights reserved.
 *
 * THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
 * EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
 */
package com.swiftnav.sbp.client;


import com.swiftnav.sbp.SBPBinaryException;
import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.acquisition.MsgAcqResult;
import com.swiftnav.sbp.acquisition.MsgAcqResultDepA;
import com.swiftnav.sbp.acquisition.MsgAcqResultDepB;
import com.swiftnav.sbp.acquisition.MsgAcqResultDepC;
import com.swiftnav.sbp.acquisition.MsgAcqSvProfile;
import com.swiftnav.sbp.acquisition.MsgAcqSvProfileDep;
import com.swiftnav.sbp.bootload.MsgBootloaderHandshakeDepA;
import com.swiftnav.sbp.bootload.MsgBootloaderHandshakeReq;
import com.swiftnav.sbp.bootload.MsgBootloaderHandshakeResp;
import com.swiftnav.sbp.bootload.MsgBootloaderJumpToApp;
import com.swiftnav.sbp.bootload.MsgNapDeviceDnaReq;
import com.swiftnav.sbp.bootload.MsgNapDeviceDnaResp;
import com.swiftnav.sbp.ext_events.MsgExtEvent;
import com.swiftnav.sbp.file_io.MsgFileioConfigReq;
import com.swiftnav.sbp.file_io.MsgFileioConfigResp;
import com.swiftnav.sbp.file_io.MsgFileioReadDirReq;
import com.swiftnav.sbp.file_io.MsgFileioReadDirResp;
import com.swiftnav.sbp.file_io.MsgFileioReadReq;
import com.swiftnav.sbp.file_io.MsgFileioReadResp;
import com.swiftnav.sbp.file_io.MsgFileioRemove;
import com.swiftnav.sbp.file_io.MsgFileioWriteReq;
import com.swiftnav.sbp.file_io.MsgFileioWriteResp;
import com.swiftnav.sbp.flash.MsgFlashDone;
import com.swiftnav.sbp.flash.MsgFlashErase;
import com.swiftnav.sbp.flash.MsgFlashProgram;
import com.swiftnav.sbp.flash.MsgFlashReadReq;
import com.swiftnav.sbp.flash.MsgFlashReadResp;
import com.swiftnav.sbp.flash.MsgM25FlashWriteStatus;
import com.swiftnav.sbp.flash.MsgStmFlashLockSector;
import com.swiftnav.sbp.flash.MsgStmFlashUnlockSector;
import com.swiftnav.sbp.flash.MsgStmUniqueIdReq;
import com.swiftnav.sbp.flash.MsgStmUniqueIdResp;
import com.swiftnav.sbp.imu.MsgImuAux;
import com.swiftnav.sbp.imu.MsgImuRaw;
import com.swiftnav.sbp.integrity.MsgSsrFlagHighLevel;
import com.swiftnav.sbp.integrity.MsgSsrFlagIonoGridPointSatLos;
import com.swiftnav.sbp.integrity.MsgSsrFlagIonoGridPoints;
import com.swiftnav.sbp.integrity.MsgSsrFlagIonoTileSatLos;
import com.swiftnav.sbp.integrity.MsgSsrFlagSatellites;
import com.swiftnav.sbp.integrity.MsgSsrFlagTropoGridPoints;
import com.swiftnav.sbp.linux.MsgLinuxCpuState;
import com.swiftnav.sbp.linux.MsgLinuxCpuStateDepA;
import com.swiftnav.sbp.linux.MsgLinuxMemState;
import com.swiftnav.sbp.linux.MsgLinuxMemStateDepA;
import com.swiftnav.sbp.linux.MsgLinuxProcessFdCount;
import com.swiftnav.sbp.linux.MsgLinuxProcessFdSummary;
import com.swiftnav.sbp.linux.MsgLinuxProcessSocketCounts;
import com.swiftnav.sbp.linux.MsgLinuxProcessSocketQueues;
import com.swiftnav.sbp.linux.MsgLinuxSocketUsage;
import com.swiftnav.sbp.linux.MsgLinuxSysState;
import com.swiftnav.sbp.linux.MsgLinuxSysStateDepA;
import com.swiftnav.sbp.logging.MsgFwd;
import com.swiftnav.sbp.logging.MsgLog;
import com.swiftnav.sbp.logging.MsgPrintDep;
import com.swiftnav.sbp.mag.MsgMagRaw;
import com.swiftnav.sbp.navigation.MsgAgeCorrections;
import com.swiftnav.sbp.navigation.MsgBaselineECEF;
import com.swiftnav.sbp.navigation.MsgBaselineECEFDepA;
import com.swiftnav.sbp.navigation.MsgBaselineHeadingDepA;
import com.swiftnav.sbp.navigation.MsgBaselineNED;
import com.swiftnav.sbp.navigation.MsgBaselineNEDDepA;
import com.swiftnav.sbp.navigation.MsgDops;
import com.swiftnav.sbp.navigation.MsgDopsDepA;
import com.swiftnav.sbp.navigation.MsgGPSTime;
import com.swiftnav.sbp.navigation.MsgGPSTimeDepA;
import com.swiftnav.sbp.navigation.MsgGPSTimeGnss;
import com.swiftnav.sbp.navigation.MsgPosECEF;
import com.swiftnav.sbp.navigation.MsgPosECEFCov;
import com.swiftnav.sbp.navigation.MsgPosECEFCovGnss;
import com.swiftnav.sbp.navigation.MsgPosECEFDepA;
import com.swiftnav.sbp.navigation.MsgPosECEFGnss;
import com.swiftnav.sbp.navigation.MsgPosLLH;
import com.swiftnav.sbp.navigation.MsgPosLLHAcc;
import com.swiftnav.sbp.navigation.MsgPosLLHCov;
import com.swiftnav.sbp.navigation.MsgPosLLHCovGnss;
import com.swiftnav.sbp.navigation.MsgPosLLHDepA;
import com.swiftnav.sbp.navigation.MsgPosLLHGnss;
import com.swiftnav.sbp.navigation.MsgProtectionLevel;
import com.swiftnav.sbp.navigation.MsgProtectionLevelDepA;
import com.swiftnav.sbp.navigation.MsgReferenceFrameParam;
import com.swiftnav.sbp.navigation.MsgUtcLeapSecond;
import com.swiftnav.sbp.navigation.MsgUtcTime;
import com.swiftnav.sbp.navigation.MsgUtcTimeGnss;
import com.swiftnav.sbp.navigation.MsgVelBody;
import com.swiftnav.sbp.navigation.MsgVelCog;
import com.swiftnav.sbp.navigation.MsgVelECEF;
import com.swiftnav.sbp.navigation.MsgVelECEFCov;
import com.swiftnav.sbp.navigation.MsgVelECEFCovGnss;
import com.swiftnav.sbp.navigation.MsgVelECEFDepA;
import com.swiftnav.sbp.navigation.MsgVelECEFGnss;
import com.swiftnav.sbp.navigation.MsgVelNED;
import com.swiftnav.sbp.navigation.MsgVelNEDCov;
import com.swiftnav.sbp.navigation.MsgVelNEDCovGnss;
import com.swiftnav.sbp.navigation.MsgVelNEDDepA;
import com.swiftnav.sbp.navigation.MsgVelNEDGnss;
import com.swiftnav.sbp.ndb.MsgNdbEvent;
import com.swiftnav.sbp.observation.MsgAlmanacGPS;
import com.swiftnav.sbp.observation.MsgAlmanacGPSDep;
import com.swiftnav.sbp.observation.MsgAlmanacGlo;
import com.swiftnav.sbp.observation.MsgAlmanacGloDep;
import com.swiftnav.sbp.observation.MsgBasePosECEF;
import com.swiftnav.sbp.observation.MsgBasePosLLH;
import com.swiftnav.sbp.observation.MsgEphemerisBds;
import com.swiftnav.sbp.observation.MsgEphemerisDepA;
import com.swiftnav.sbp.observation.MsgEphemerisDepB;
import com.swiftnav.sbp.observation.MsgEphemerisDepC;
import com.swiftnav.sbp.observation.MsgEphemerisDepD;
import com.swiftnav.sbp.observation.MsgEphemerisGPS;
import com.swiftnav.sbp.observation.MsgEphemerisGPSDepE;
import com.swiftnav.sbp.observation.MsgEphemerisGPSDepF;
import com.swiftnav.sbp.observation.MsgEphemerisGal;
import com.swiftnav.sbp.observation.MsgEphemerisGalDepA;
import com.swiftnav.sbp.observation.MsgEphemerisGlo;
import com.swiftnav.sbp.observation.MsgEphemerisGloDepA;
import com.swiftnav.sbp.observation.MsgEphemerisGloDepB;
import com.swiftnav.sbp.observation.MsgEphemerisGloDepC;
import com.swiftnav.sbp.observation.MsgEphemerisGloDepD;
import com.swiftnav.sbp.observation.MsgEphemerisQzss;
import com.swiftnav.sbp.observation.MsgEphemerisSbas;
import com.swiftnav.sbp.observation.MsgEphemerisSbasDepA;
import com.swiftnav.sbp.observation.MsgEphemerisSbasDepB;
import com.swiftnav.sbp.observation.MsgGloBiases;
import com.swiftnav.sbp.observation.MsgGnssCapb;
import com.swiftnav.sbp.observation.MsgGroupDelay;
import com.swiftnav.sbp.observation.MsgGroupDelayDepA;
import com.swiftnav.sbp.observation.MsgGroupDelayDepB;
import com.swiftnav.sbp.observation.MsgIono;
import com.swiftnav.sbp.observation.MsgObs;
import com.swiftnav.sbp.observation.MsgObsDepA;
import com.swiftnav.sbp.observation.MsgObsDepB;
import com.swiftnav.sbp.observation.MsgObsDepC;
import com.swiftnav.sbp.observation.MsgOsr;
import com.swiftnav.sbp.observation.MsgSvAzEl;
import com.swiftnav.sbp.observation.MsgSvConfigurationGPSDep;
import com.swiftnav.sbp.orientation.MsgAngularRate;
import com.swiftnav.sbp.orientation.MsgBaselineHeading;
import com.swiftnav.sbp.orientation.MsgOrientEuler;
import com.swiftnav.sbp.orientation.MsgOrientQuat;
import com.swiftnav.sbp.piksi.MsgAlmanac;
import com.swiftnav.sbp.piksi.MsgCellModemStatus;
import com.swiftnav.sbp.piksi.MsgCommandOutput;
import com.swiftnav.sbp.piksi.MsgCommandReq;
import com.swiftnav.sbp.piksi.MsgCommandResp;
import com.swiftnav.sbp.piksi.MsgCwResults;
import com.swiftnav.sbp.piksi.MsgCwStart;
import com.swiftnav.sbp.piksi.MsgDeviceMonitor;
import com.swiftnav.sbp.piksi.MsgFrontEndGain;
import com.swiftnav.sbp.piksi.MsgIarState;
import com.swiftnav.sbp.piksi.MsgInitBaseDep;
import com.swiftnav.sbp.piksi.MsgMaskSatellite;
import com.swiftnav.sbp.piksi.MsgMaskSatelliteDep;
import com.swiftnav.sbp.piksi.MsgNetworkBandwidthUsage;
import com.swiftnav.sbp.piksi.MsgNetworkStateReq;
import com.swiftnav.sbp.piksi.MsgNetworkStateResp;
import com.swiftnav.sbp.piksi.MsgReset;
import com.swiftnav.sbp.piksi.MsgResetDep;
import com.swiftnav.sbp.piksi.MsgResetFilters;
import com.swiftnav.sbp.piksi.MsgSetTime;
import com.swiftnav.sbp.piksi.MsgSpecan;
import com.swiftnav.sbp.piksi.MsgSpecanDep;
import com.swiftnav.sbp.piksi.MsgThreadState;
import com.swiftnav.sbp.piksi.MsgUartState;
import com.swiftnav.sbp.piksi.MsgUartStateDepa;
import com.swiftnav.sbp.sbas.MsgSbasRaw;
import com.swiftnav.sbp.settings.MsgSettingsReadByIndexDone;
import com.swiftnav.sbp.settings.MsgSettingsReadByIndexReq;
import com.swiftnav.sbp.settings.MsgSettingsReadByIndexResp;
import com.swiftnav.sbp.settings.MsgSettingsReadReq;
import com.swiftnav.sbp.settings.MsgSettingsReadResp;
import com.swiftnav.sbp.settings.MsgSettingsRegister;
import com.swiftnav.sbp.settings.MsgSettingsRegisterResp;
import com.swiftnav.sbp.settings.MsgSettingsSave;
import com.swiftnav.sbp.settings.MsgSettingsWrite;
import com.swiftnav.sbp.settings.MsgSettingsWriteResp;
import com.swiftnav.sbp.signing.MsgEd25519Certificate;
import com.swiftnav.sbp.signing.MsgEd25519Signature;
import com.swiftnav.sbp.solution_meta.MsgSolnMeta;
import com.swiftnav.sbp.solution_meta.MsgSolnMetaDepA;
import com.swiftnav.sbp.ssr.MsgSsrCodeBiases;
import com.swiftnav.sbp.ssr.MsgSsrCodePhaseBiasesBounds;
import com.swiftnav.sbp.ssr.MsgSsrGridDefinitionDepA;
import com.swiftnav.sbp.ssr.MsgSsrGriddedCorrection;
import com.swiftnav.sbp.ssr.MsgSsrGriddedCorrectionBounds;
import com.swiftnav.sbp.ssr.MsgSsrGriddedCorrectionDepA;
import com.swiftnav.sbp.ssr.MsgSsrGriddedCorrectionNoStdDepA;
import com.swiftnav.sbp.ssr.MsgSsrOrbitClock;
import com.swiftnav.sbp.ssr.MsgSsrOrbitClockBounds;
import com.swiftnav.sbp.ssr.MsgSsrOrbitClockBoundsDegradation;
import com.swiftnav.sbp.ssr.MsgSsrOrbitClockDepA;
import com.swiftnav.sbp.ssr.MsgSsrPhaseBiases;
import com.swiftnav.sbp.ssr.MsgSsrSatelliteApc;
import com.swiftnav.sbp.ssr.MsgSsrStecCorrection;
import com.swiftnav.sbp.ssr.MsgSsrStecCorrectionDep;
import com.swiftnav.sbp.ssr.MsgSsrStecCorrectionDepA;
import com.swiftnav.sbp.ssr.MsgSsrTileDefinition;
import com.swiftnav.sbp.ssr.MsgSsrTileDefinitionDep;
import com.swiftnav.sbp.system.MsgCsacTelemetry;
import com.swiftnav.sbp.system.MsgCsacTelemetryLabels;
import com.swiftnav.sbp.system.MsgDgnssStatus;
import com.swiftnav.sbp.system.MsgGnssTimeOffset;
import com.swiftnav.sbp.system.MsgGroupMeta;
import com.swiftnav.sbp.system.MsgHeartbeat;
import com.swiftnav.sbp.system.MsgInsStatus;
import com.swiftnav.sbp.system.MsgInsUpdates;
import com.swiftnav.sbp.system.MsgPpsTime;
import com.swiftnav.sbp.system.MsgSensorAidEvent;
import com.swiftnav.sbp.system.MsgStartup;
import com.swiftnav.sbp.system.MsgStatusJournal;
import com.swiftnav.sbp.system.MsgStatusReport;
import com.swiftnav.sbp.tracking.MsgMeasurementState;
import com.swiftnav.sbp.tracking.MsgTrackingIq;
import com.swiftnav.sbp.tracking.MsgTrackingIqDepA;
import com.swiftnav.sbp.tracking.MsgTrackingIqDepB;
import com.swiftnav.sbp.tracking.MsgTrackingState;
import com.swiftnav.sbp.tracking.MsgTrackingStateDepA;
import com.swiftnav.sbp.tracking.MsgTrackingStateDepB;
import com.swiftnav.sbp.tracking.MsgTrackingStateDetailedDep;
import com.swiftnav.sbp.tracking.MsgTrackingStateDetailedDepA;
import com.swiftnav.sbp.user.MsgUserData;
import com.swiftnav.sbp.vehicle.MsgOdometry;
import com.swiftnav.sbp.vehicle.MsgWheeltick;

final class MessageTable {
    static SBPMessage dispatch(SBPMessage msg) throws SBPBinaryException {
        switch (msg.type) {
            case MsgAcqResult.TYPE:
                return new MsgAcqResult(msg);
            case MsgAcqResultDepC.TYPE:
                return new MsgAcqResultDepC(msg);
            case MsgAcqResultDepB.TYPE:
                return new MsgAcqResultDepB(msg);
            case MsgAcqResultDepA.TYPE:
                return new MsgAcqResultDepA(msg);
            case MsgAcqSvProfile.TYPE:
                return new MsgAcqSvProfile(msg);
            case MsgAcqSvProfileDep.TYPE:
                return new MsgAcqSvProfileDep(msg);
            case MsgBootloaderHandshakeReq.TYPE:
                return new MsgBootloaderHandshakeReq(msg);
            case MsgBootloaderHandshakeResp.TYPE:
                return new MsgBootloaderHandshakeResp(msg);
            case MsgBootloaderJumpToApp.TYPE:
                return new MsgBootloaderJumpToApp(msg);
            case MsgNapDeviceDnaReq.TYPE:
                return new MsgNapDeviceDnaReq(msg);
            case MsgNapDeviceDnaResp.TYPE:
                return new MsgNapDeviceDnaResp(msg);
            case MsgBootloaderHandshakeDepA.TYPE:
                return new MsgBootloaderHandshakeDepA(msg);
            case MsgExtEvent.TYPE:
                return new MsgExtEvent(msg);
            case MsgFileioReadReq.TYPE:
                return new MsgFileioReadReq(msg);
            case MsgFileioReadResp.TYPE:
                return new MsgFileioReadResp(msg);
            case MsgFileioReadDirReq.TYPE:
                return new MsgFileioReadDirReq(msg);
            case MsgFileioReadDirResp.TYPE:
                return new MsgFileioReadDirResp(msg);
            case MsgFileioRemove.TYPE:
                return new MsgFileioRemove(msg);
            case MsgFileioWriteReq.TYPE:
                return new MsgFileioWriteReq(msg);
            case MsgFileioWriteResp.TYPE:
                return new MsgFileioWriteResp(msg);
            case MsgFileioConfigReq.TYPE:
                return new MsgFileioConfigReq(msg);
            case MsgFileioConfigResp.TYPE:
                return new MsgFileioConfigResp(msg);
            case MsgFlashProgram.TYPE:
                return new MsgFlashProgram(msg);
            case MsgFlashDone.TYPE:
                return new MsgFlashDone(msg);
            case MsgFlashReadReq.TYPE:
                return new MsgFlashReadReq(msg);
            case MsgFlashReadResp.TYPE:
                return new MsgFlashReadResp(msg);
            case MsgFlashErase.TYPE:
                return new MsgFlashErase(msg);
            case MsgStmFlashLockSector.TYPE:
                return new MsgStmFlashLockSector(msg);
            case MsgStmFlashUnlockSector.TYPE:
                return new MsgStmFlashUnlockSector(msg);
            case MsgStmUniqueIdReq.TYPE:
                return new MsgStmUniqueIdReq(msg);
            case MsgStmUniqueIdResp.TYPE:
                return new MsgStmUniqueIdResp(msg);
            case MsgM25FlashWriteStatus.TYPE:
                return new MsgM25FlashWriteStatus(msg);
            case MsgImuRaw.TYPE:
                return new MsgImuRaw(msg);
            case MsgImuAux.TYPE:
                return new MsgImuAux(msg);
            case MsgSsrFlagHighLevel.TYPE:
                return new MsgSsrFlagHighLevel(msg);
            case MsgSsrFlagSatellites.TYPE:
                return new MsgSsrFlagSatellites(msg);
            case MsgSsrFlagTropoGridPoints.TYPE:
                return new MsgSsrFlagTropoGridPoints(msg);
            case MsgSsrFlagIonoGridPoints.TYPE:
                return new MsgSsrFlagIonoGridPoints(msg);
            case MsgSsrFlagIonoTileSatLos.TYPE:
                return new MsgSsrFlagIonoTileSatLos(msg);
            case MsgSsrFlagIonoGridPointSatLos.TYPE:
                return new MsgSsrFlagIonoGridPointSatLos(msg);
            case MsgLinuxCpuStateDepA.TYPE:
                return new MsgLinuxCpuStateDepA(msg);
            case MsgLinuxMemStateDepA.TYPE:
                return new MsgLinuxMemStateDepA(msg);
            case MsgLinuxSysStateDepA.TYPE:
                return new MsgLinuxSysStateDepA(msg);
            case MsgLinuxProcessSocketCounts.TYPE:
                return new MsgLinuxProcessSocketCounts(msg);
            case MsgLinuxProcessSocketQueues.TYPE:
                return new MsgLinuxProcessSocketQueues(msg);
            case MsgLinuxSocketUsage.TYPE:
                return new MsgLinuxSocketUsage(msg);
            case MsgLinuxProcessFdCount.TYPE:
                return new MsgLinuxProcessFdCount(msg);
            case MsgLinuxProcessFdSummary.TYPE:
                return new MsgLinuxProcessFdSummary(msg);
            case MsgLinuxCpuState.TYPE:
                return new MsgLinuxCpuState(msg);
            case MsgLinuxMemState.TYPE:
                return new MsgLinuxMemState(msg);
            case MsgLinuxSysState.TYPE:
                return new MsgLinuxSysState(msg);
            case MsgLog.TYPE:
                return new MsgLog(msg);
            case MsgFwd.TYPE:
                return new MsgFwd(msg);
            case MsgPrintDep.TYPE:
                return new MsgPrintDep(msg);
            case MsgMagRaw.TYPE:
                return new MsgMagRaw(msg);
            case MsgGPSTime.TYPE:
                return new MsgGPSTime(msg);
            case MsgGPSTimeGnss.TYPE:
                return new MsgGPSTimeGnss(msg);
            case MsgUtcTime.TYPE:
                return new MsgUtcTime(msg);
            case MsgUtcTimeGnss.TYPE:
                return new MsgUtcTimeGnss(msg);
            case MsgDops.TYPE:
                return new MsgDops(msg);
            case MsgPosECEF.TYPE:
                return new MsgPosECEF(msg);
            case MsgPosECEFCov.TYPE:
                return new MsgPosECEFCov(msg);
            case MsgPosLLH.TYPE:
                return new MsgPosLLH(msg);
            case MsgPosLLHCov.TYPE:
                return new MsgPosLLHCov(msg);
            case MsgPosLLHAcc.TYPE:
                return new MsgPosLLHAcc(msg);
            case MsgBaselineECEF.TYPE:
                return new MsgBaselineECEF(msg);
            case MsgBaselineNED.TYPE:
                return new MsgBaselineNED(msg);
            case MsgVelECEF.TYPE:
                return new MsgVelECEF(msg);
            case MsgVelECEFCov.TYPE:
                return new MsgVelECEFCov(msg);
            case MsgVelNED.TYPE:
                return new MsgVelNED(msg);
            case MsgVelNEDCov.TYPE:
                return new MsgVelNEDCov(msg);
            case MsgPosECEFGnss.TYPE:
                return new MsgPosECEFGnss(msg);
            case MsgPosECEFCovGnss.TYPE:
                return new MsgPosECEFCovGnss(msg);
            case MsgPosLLHGnss.TYPE:
                return new MsgPosLLHGnss(msg);
            case MsgPosLLHCovGnss.TYPE:
                return new MsgPosLLHCovGnss(msg);
            case MsgVelECEFGnss.TYPE:
                return new MsgVelECEFGnss(msg);
            case MsgVelECEFCovGnss.TYPE:
                return new MsgVelECEFCovGnss(msg);
            case MsgVelNEDGnss.TYPE:
                return new MsgVelNEDGnss(msg);
            case MsgVelNEDCovGnss.TYPE:
                return new MsgVelNEDCovGnss(msg);
            case MsgVelBody.TYPE:
                return new MsgVelBody(msg);
            case MsgVelCog.TYPE:
                return new MsgVelCog(msg);
            case MsgAgeCorrections.TYPE:
                return new MsgAgeCorrections(msg);
            case MsgGPSTimeDepA.TYPE:
                return new MsgGPSTimeDepA(msg);
            case MsgDopsDepA.TYPE:
                return new MsgDopsDepA(msg);
            case MsgPosECEFDepA.TYPE:
                return new MsgPosECEFDepA(msg);
            case MsgPosLLHDepA.TYPE:
                return new MsgPosLLHDepA(msg);
            case MsgBaselineECEFDepA.TYPE:
                return new MsgBaselineECEFDepA(msg);
            case MsgBaselineNEDDepA.TYPE:
                return new MsgBaselineNEDDepA(msg);
            case MsgVelECEFDepA.TYPE:
                return new MsgVelECEFDepA(msg);
            case MsgVelNEDDepA.TYPE:
                return new MsgVelNEDDepA(msg);
            case MsgBaselineHeadingDepA.TYPE:
                return new MsgBaselineHeadingDepA(msg);
            case MsgProtectionLevelDepA.TYPE:
                return new MsgProtectionLevelDepA(msg);
            case MsgProtectionLevel.TYPE:
                return new MsgProtectionLevel(msg);
            case MsgUtcLeapSecond.TYPE:
                return new MsgUtcLeapSecond(msg);
            case MsgReferenceFrameParam.TYPE:
                return new MsgReferenceFrameParam(msg);
            case MsgNdbEvent.TYPE:
                return new MsgNdbEvent(msg);
            case MsgObs.TYPE:
                return new MsgObs(msg);
            case MsgBasePosLLH.TYPE:
                return new MsgBasePosLLH(msg);
            case MsgBasePosECEF.TYPE:
                return new MsgBasePosECEF(msg);
            case MsgEphemerisGPSDepE.TYPE:
                return new MsgEphemerisGPSDepE(msg);
            case MsgEphemerisGPSDepF.TYPE:
                return new MsgEphemerisGPSDepF(msg);
            case MsgEphemerisGPS.TYPE:
                return new MsgEphemerisGPS(msg);
            case MsgEphemerisQzss.TYPE:
                return new MsgEphemerisQzss(msg);
            case MsgEphemerisBds.TYPE:
                return new MsgEphemerisBds(msg);
            case MsgEphemerisGalDepA.TYPE:
                return new MsgEphemerisGalDepA(msg);
            case MsgEphemerisGal.TYPE:
                return new MsgEphemerisGal(msg);
            case MsgEphemerisSbasDepA.TYPE:
                return new MsgEphemerisSbasDepA(msg);
            case MsgEphemerisGloDepA.TYPE:
                return new MsgEphemerisGloDepA(msg);
            case MsgEphemerisSbasDepB.TYPE:
                return new MsgEphemerisSbasDepB(msg);
            case MsgEphemerisSbas.TYPE:
                return new MsgEphemerisSbas(msg);
            case MsgEphemerisGloDepB.TYPE:
                return new MsgEphemerisGloDepB(msg);
            case MsgEphemerisGloDepC.TYPE:
                return new MsgEphemerisGloDepC(msg);
            case MsgEphemerisGloDepD.TYPE:
                return new MsgEphemerisGloDepD(msg);
            case MsgEphemerisGlo.TYPE:
                return new MsgEphemerisGlo(msg);
            case MsgEphemerisDepD.TYPE:
                return new MsgEphemerisDepD(msg);
            case MsgEphemerisDepA.TYPE:
                return new MsgEphemerisDepA(msg);
            case MsgEphemerisDepB.TYPE:
                return new MsgEphemerisDepB(msg);
            case MsgEphemerisDepC.TYPE:
                return new MsgEphemerisDepC(msg);
            case MsgObsDepA.TYPE:
                return new MsgObsDepA(msg);
            case MsgObsDepB.TYPE:
                return new MsgObsDepB(msg);
            case MsgObsDepC.TYPE:
                return new MsgObsDepC(msg);
            case MsgIono.TYPE:
                return new MsgIono(msg);
            case MsgSvConfigurationGPSDep.TYPE:
                return new MsgSvConfigurationGPSDep(msg);
            case MsgGnssCapb.TYPE:
                return new MsgGnssCapb(msg);
            case MsgGroupDelayDepA.TYPE:
                return new MsgGroupDelayDepA(msg);
            case MsgGroupDelayDepB.TYPE:
                return new MsgGroupDelayDepB(msg);
            case MsgGroupDelay.TYPE:
                return new MsgGroupDelay(msg);
            case MsgAlmanacGPSDep.TYPE:
                return new MsgAlmanacGPSDep(msg);
            case MsgAlmanacGPS.TYPE:
                return new MsgAlmanacGPS(msg);
            case MsgAlmanacGloDep.TYPE:
                return new MsgAlmanacGloDep(msg);
            case MsgAlmanacGlo.TYPE:
                return new MsgAlmanacGlo(msg);
            case MsgGloBiases.TYPE:
                return new MsgGloBiases(msg);
            case MsgSvAzEl.TYPE:
                return new MsgSvAzEl(msg);
            case MsgOsr.TYPE:
                return new MsgOsr(msg);
            case MsgBaselineHeading.TYPE:
                return new MsgBaselineHeading(msg);
            case MsgOrientQuat.TYPE:
                return new MsgOrientQuat(msg);
            case MsgOrientEuler.TYPE:
                return new MsgOrientEuler(msg);
            case MsgAngularRate.TYPE:
                return new MsgAngularRate(msg);
            case MsgAlmanac.TYPE:
                return new MsgAlmanac(msg);
            case MsgSetTime.TYPE:
                return new MsgSetTime(msg);
            case MsgReset.TYPE:
                return new MsgReset(msg);
            case MsgResetDep.TYPE:
                return new MsgResetDep(msg);
            case MsgCwResults.TYPE:
                return new MsgCwResults(msg);
            case MsgCwStart.TYPE:
                return new MsgCwStart(msg);
            case MsgResetFilters.TYPE:
                return new MsgResetFilters(msg);
            case MsgInitBaseDep.TYPE:
                return new MsgInitBaseDep(msg);
            case MsgThreadState.TYPE:
                return new MsgThreadState(msg);
            case MsgUartState.TYPE:
                return new MsgUartState(msg);
            case MsgUartStateDepa.TYPE:
                return new MsgUartStateDepa(msg);
            case MsgIarState.TYPE:
                return new MsgIarState(msg);
            case MsgMaskSatellite.TYPE:
                return new MsgMaskSatellite(msg);
            case MsgMaskSatelliteDep.TYPE:
                return new MsgMaskSatelliteDep(msg);
            case MsgDeviceMonitor.TYPE:
                return new MsgDeviceMonitor(msg);
            case MsgCommandReq.TYPE:
                return new MsgCommandReq(msg);
            case MsgCommandResp.TYPE:
                return new MsgCommandResp(msg);
            case MsgCommandOutput.TYPE:
                return new MsgCommandOutput(msg);
            case MsgNetworkStateReq.TYPE:
                return new MsgNetworkStateReq(msg);
            case MsgNetworkStateResp.TYPE:
                return new MsgNetworkStateResp(msg);
            case MsgNetworkBandwidthUsage.TYPE:
                return new MsgNetworkBandwidthUsage(msg);
            case MsgCellModemStatus.TYPE:
                return new MsgCellModemStatus(msg);
            case MsgSpecanDep.TYPE:
                return new MsgSpecanDep(msg);
            case MsgSpecan.TYPE:
                return new MsgSpecan(msg);
            case MsgFrontEndGain.TYPE:
                return new MsgFrontEndGain(msg);
            case MsgSbasRaw.TYPE:
                return new MsgSbasRaw(msg);
            case MsgSettingsSave.TYPE:
                return new MsgSettingsSave(msg);
            case MsgSettingsWrite.TYPE:
                return new MsgSettingsWrite(msg);
            case MsgSettingsWriteResp.TYPE:
                return new MsgSettingsWriteResp(msg);
            case MsgSettingsReadReq.TYPE:
                return new MsgSettingsReadReq(msg);
            case MsgSettingsReadResp.TYPE:
                return new MsgSettingsReadResp(msg);
            case MsgSettingsReadByIndexReq.TYPE:
                return new MsgSettingsReadByIndexReq(msg);
            case MsgSettingsReadByIndexResp.TYPE:
                return new MsgSettingsReadByIndexResp(msg);
            case MsgSettingsReadByIndexDone.TYPE:
                return new MsgSettingsReadByIndexDone(msg);
            case MsgSettingsRegister.TYPE:
                return new MsgSettingsRegister(msg);
            case MsgSettingsRegisterResp.TYPE:
                return new MsgSettingsRegisterResp(msg);
            case MsgEd25519Signature.TYPE:
                return new MsgEd25519Signature(msg);
            case MsgEd25519Certificate.TYPE:
                return new MsgEd25519Certificate(msg);
            case MsgSolnMetaDepA.TYPE:
                return new MsgSolnMetaDepA(msg);
            case MsgSolnMeta.TYPE:
                return new MsgSolnMeta(msg);
            case MsgSsrOrbitClock.TYPE:
                return new MsgSsrOrbitClock(msg);
            case MsgSsrCodeBiases.TYPE:
                return new MsgSsrCodeBiases(msg);
            case MsgSsrPhaseBiases.TYPE:
                return new MsgSsrPhaseBiases(msg);
            case MsgSsrStecCorrectionDep.TYPE:
                return new MsgSsrStecCorrectionDep(msg);
            case MsgSsrStecCorrection.TYPE:
                return new MsgSsrStecCorrection(msg);
            case MsgSsrGriddedCorrection.TYPE:
                return new MsgSsrGriddedCorrection(msg);
            case MsgSsrGriddedCorrectionBounds.TYPE:
                return new MsgSsrGriddedCorrectionBounds(msg);
            case MsgSsrTileDefinitionDep.TYPE:
                return new MsgSsrTileDefinitionDep(msg);
            case MsgSsrTileDefinition.TYPE:
                return new MsgSsrTileDefinition(msg);
            case MsgSsrSatelliteApc.TYPE:
                return new MsgSsrSatelliteApc(msg);
            case MsgSsrOrbitClockDepA.TYPE:
                return new MsgSsrOrbitClockDepA(msg);
            case MsgSsrStecCorrectionDepA.TYPE:
                return new MsgSsrStecCorrectionDepA(msg);
            case MsgSsrGriddedCorrectionNoStdDepA.TYPE:
                return new MsgSsrGriddedCorrectionNoStdDepA(msg);
            case MsgSsrGriddedCorrectionDepA.TYPE:
                return new MsgSsrGriddedCorrectionDepA(msg);
            case MsgSsrGridDefinitionDepA.TYPE:
                return new MsgSsrGridDefinitionDepA(msg);
            case MsgSsrOrbitClockBounds.TYPE:
                return new MsgSsrOrbitClockBounds(msg);
            case MsgSsrCodePhaseBiasesBounds.TYPE:
                return new MsgSsrCodePhaseBiasesBounds(msg);
            case MsgSsrOrbitClockBoundsDegradation.TYPE:
                return new MsgSsrOrbitClockBoundsDegradation(msg);
            case MsgStartup.TYPE:
                return new MsgStartup(msg);
            case MsgDgnssStatus.TYPE:
                return new MsgDgnssStatus(msg);
            case MsgHeartbeat.TYPE:
                return new MsgHeartbeat(msg);
            case MsgStatusReport.TYPE:
                return new MsgStatusReport(msg);
            case MsgStatusJournal.TYPE:
                return new MsgStatusJournal(msg);
            case MsgInsStatus.TYPE:
                return new MsgInsStatus(msg);
            case MsgCsacTelemetry.TYPE:
                return new MsgCsacTelemetry(msg);
            case MsgCsacTelemetryLabels.TYPE:
                return new MsgCsacTelemetryLabels(msg);
            case MsgInsUpdates.TYPE:
                return new MsgInsUpdates(msg);
            case MsgGnssTimeOffset.TYPE:
                return new MsgGnssTimeOffset(msg);
            case MsgPpsTime.TYPE:
                return new MsgPpsTime(msg);
            case MsgSensorAidEvent.TYPE:
                return new MsgSensorAidEvent(msg);
            case MsgGroupMeta.TYPE:
                return new MsgGroupMeta(msg);
            case MsgTrackingStateDetailedDepA.TYPE:
                return new MsgTrackingStateDetailedDepA(msg);
            case MsgTrackingStateDetailedDep.TYPE:
                return new MsgTrackingStateDetailedDep(msg);
            case MsgTrackingState.TYPE:
                return new MsgTrackingState(msg);
            case MsgMeasurementState.TYPE:
                return new MsgMeasurementState(msg);
            case MsgTrackingIq.TYPE:
                return new MsgTrackingIq(msg);
            case MsgTrackingIqDepB.TYPE:
                return new MsgTrackingIqDepB(msg);
            case MsgTrackingIqDepA.TYPE:
                return new MsgTrackingIqDepA(msg);
            case MsgTrackingStateDepA.TYPE:
                return new MsgTrackingStateDepA(msg);
            case MsgTrackingStateDepB.TYPE:
                return new MsgTrackingStateDepB(msg);
            case MsgUserData.TYPE:
                return new MsgUserData(msg);
            case MsgOdometry.TYPE:
                return new MsgOdometry(msg);
            case MsgWheeltick.TYPE:
                return new MsgWheeltick(msg);
        }
        return msg;
    }
}
