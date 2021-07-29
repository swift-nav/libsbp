// Copyright (C) 2015-2021 Swift Navigation Inc.
// Contact: https://support.swiftnav.com
//
// This source is subject to the license found in the file 'LICENSE' which must
// be be distributed together with this source. All other rights reserved.
//
// THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
// EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
// WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
pub mod acquisition;
pub mod bootload;
pub mod ext_events;
pub mod file_io;
pub mod flash;
pub mod gnss;
pub mod imu;
pub mod linux;
pub mod logging;
pub mod mag;
pub mod navigation;
pub mod ndb;
pub mod observation;
pub mod orientation;
pub mod piksi;
pub mod sbas;
pub mod settings;
pub mod solution_meta;
pub mod ssr;
pub mod system;
pub mod tracking;
pub mod unknown;
pub mod user;
pub mod vehicle;
use self::acquisition::MsgAcqResult;
use self::acquisition::MsgAcqResultDepA;
use self::acquisition::MsgAcqResultDepB;
use self::acquisition::MsgAcqResultDepC;
use self::acquisition::MsgAcqSvProfile;
use self::acquisition::MsgAcqSvProfileDep;
use self::bootload::MsgBootloaderHandshakeDepA;
use self::bootload::MsgBootloaderHandshakeReq;
use self::bootload::MsgBootloaderHandshakeResp;
use self::bootload::MsgBootloaderJumpToApp;
use self::bootload::MsgNapDeviceDnaReq;
use self::bootload::MsgNapDeviceDnaResp;
use self::ext_events::MsgExtEvent;
use self::file_io::MsgFileioConfigReq;
use self::file_io::MsgFileioConfigResp;
use self::file_io::MsgFileioReadDirReq;
use self::file_io::MsgFileioReadDirResp;
use self::file_io::MsgFileioReadReq;
use self::file_io::MsgFileioReadResp;
use self::file_io::MsgFileioRemove;
use self::file_io::MsgFileioWriteReq;
use self::file_io::MsgFileioWriteResp;
use self::flash::MsgFlashDone;
use self::flash::MsgFlashErase;
use self::flash::MsgFlashProgram;
use self::flash::MsgFlashReadReq;
use self::flash::MsgFlashReadResp;
use self::flash::MsgM25FlashWriteStatus;
use self::flash::MsgStmFlashLockSector;
use self::flash::MsgStmFlashUnlockSector;
use self::flash::MsgStmUniqueIdReq;
use self::flash::MsgStmUniqueIdResp;
use self::imu::MsgImuAux;
use self::imu::MsgImuRaw;
use self::linux::MsgLinuxCpuState;
use self::linux::MsgLinuxCpuStateDepA;
use self::linux::MsgLinuxMemState;
use self::linux::MsgLinuxMemStateDepA;
use self::linux::MsgLinuxProcessFdCount;
use self::linux::MsgLinuxProcessFdSummary;
use self::linux::MsgLinuxProcessSocketCounts;
use self::linux::MsgLinuxProcessSocketQueues;
use self::linux::MsgLinuxSocketUsage;
use self::linux::MsgLinuxSysState;
use self::linux::MsgLinuxSysStateDepA;
use self::logging::MsgFwd;
use self::logging::MsgLog;
use self::logging::MsgPrintDep;
use self::mag::MsgMagRaw;
use self::navigation::MsgAgeCorrections;
use self::navigation::MsgBaselineECEF;
use self::navigation::MsgBaselineECEFDepA;
use self::navigation::MsgBaselineHeadingDepA;
use self::navigation::MsgBaselineNED;
use self::navigation::MsgBaselineNEDDepA;
use self::navigation::MsgDops;
use self::navigation::MsgDopsDepA;
use self::navigation::MsgGPSTime;
use self::navigation::MsgGPSTimeDepA;
use self::navigation::MsgGPSTimeGnss;
use self::navigation::MsgPosECEF;
use self::navigation::MsgPosECEFCov;
use self::navigation::MsgPosECEFCovGnss;
use self::navigation::MsgPosECEFDepA;
use self::navigation::MsgPosECEFGnss;
use self::navigation::MsgPosLLH;
use self::navigation::MsgPosLLHAcc;
use self::navigation::MsgPosLLHCov;
use self::navigation::MsgPosLLHCovGnss;
use self::navigation::MsgPosLLHDepA;
use self::navigation::MsgPosLLHGnss;
use self::navigation::MsgProtectionLevel;
use self::navigation::MsgProtectionLevelDepA;
use self::navigation::MsgUtcTime;
use self::navigation::MsgUtcTimeGnss;
use self::navigation::MsgVelBody;
use self::navigation::MsgVelECEF;
use self::navigation::MsgVelECEFCov;
use self::navigation::MsgVelECEFCovGnss;
use self::navigation::MsgVelECEFDepA;
use self::navigation::MsgVelECEFGnss;
use self::navigation::MsgVelNED;
use self::navigation::MsgVelNEDCov;
use self::navigation::MsgVelNEDCovGnss;
use self::navigation::MsgVelNEDDepA;
use self::navigation::MsgVelNEDGnss;
use self::ndb::MsgNdbEvent;
use self::observation::MsgAlmanacGPS;
use self::observation::MsgAlmanacGPSDep;
use self::observation::MsgAlmanacGlo;
use self::observation::MsgAlmanacGloDep;
use self::observation::MsgBasePosECEF;
use self::observation::MsgBasePosLLH;
use self::observation::MsgEphemerisBds;
use self::observation::MsgEphemerisDepA;
use self::observation::MsgEphemerisDepB;
use self::observation::MsgEphemerisDepC;
use self::observation::MsgEphemerisDepD;
use self::observation::MsgEphemerisGPS;
use self::observation::MsgEphemerisGPSDepE;
use self::observation::MsgEphemerisGPSDepF;
use self::observation::MsgEphemerisGal;
use self::observation::MsgEphemerisGalDepA;
use self::observation::MsgEphemerisGlo;
use self::observation::MsgEphemerisGloDepA;
use self::observation::MsgEphemerisGloDepB;
use self::observation::MsgEphemerisGloDepC;
use self::observation::MsgEphemerisGloDepD;
use self::observation::MsgEphemerisQzss;
use self::observation::MsgEphemerisSbas;
use self::observation::MsgEphemerisSbasDepA;
use self::observation::MsgEphemerisSbasDepB;
use self::observation::MsgGloBiases;
use self::observation::MsgGnssCapb;
use self::observation::MsgGroupDelay;
use self::observation::MsgGroupDelayDepA;
use self::observation::MsgGroupDelayDepB;
use self::observation::MsgIono;
use self::observation::MsgObs;
use self::observation::MsgObsDepA;
use self::observation::MsgObsDepB;
use self::observation::MsgObsDepC;
use self::observation::MsgOsr;
use self::observation::MsgSvAzEl;
use self::observation::MsgSvConfigurationGPSDep;
use self::orientation::MsgAngularRate;
use self::orientation::MsgBaselineHeading;
use self::orientation::MsgOrientEuler;
use self::orientation::MsgOrientQuat;
use self::piksi::MsgAlmanac;
use self::piksi::MsgCellModemStatus;
use self::piksi::MsgCommandOutput;
use self::piksi::MsgCommandReq;
use self::piksi::MsgCommandResp;
use self::piksi::MsgCwResults;
use self::piksi::MsgCwStart;
use self::piksi::MsgDeviceMonitor;
use self::piksi::MsgFrontEndGain;
use self::piksi::MsgIarState;
use self::piksi::MsgInitBaseDep;
use self::piksi::MsgMaskSatellite;
use self::piksi::MsgMaskSatelliteDep;
use self::piksi::MsgNetworkBandwidthUsage;
use self::piksi::MsgNetworkStateReq;
use self::piksi::MsgNetworkStateResp;
use self::piksi::MsgReset;
use self::piksi::MsgResetDep;
use self::piksi::MsgResetFilters;
use self::piksi::MsgSetTime;
use self::piksi::MsgSpecan;
use self::piksi::MsgSpecanDep;
use self::piksi::MsgThreadState;
use self::piksi::MsgUartState;
use self::piksi::MsgUartStateDepa;
use self::sbas::MsgSbasRaw;
use self::settings::MsgSettingsReadByIndexDone;
use self::settings::MsgSettingsReadByIndexReq;
use self::settings::MsgSettingsReadByIndexResp;
use self::settings::MsgSettingsReadReq;
use self::settings::MsgSettingsReadResp;
use self::settings::MsgSettingsRegister;
use self::settings::MsgSettingsRegisterResp;
use self::settings::MsgSettingsSave;
use self::settings::MsgSettingsWrite;
use self::settings::MsgSettingsWriteResp;
use self::solution_meta::MsgSolnMeta;
use self::solution_meta::MsgSolnMetaDepA;
use self::ssr::MsgSsrCodeBiases;
use self::ssr::MsgSsrGridDefinitionDepA;
use self::ssr::MsgSsrGriddedCorrection;
use self::ssr::MsgSsrGriddedCorrectionDepA;
use self::ssr::MsgSsrGriddedCorrectionNoStdDepA;
use self::ssr::MsgSsrOrbitClock;
use self::ssr::MsgSsrOrbitClockDepA;
use self::ssr::MsgSsrPhaseBiases;
use self::ssr::MsgSsrSatelliteApc;
use self::ssr::MsgSsrStecCorrection;
use self::ssr::MsgSsrStecCorrectionDepA;
use self::ssr::MsgSsrTileDefinition;
use self::system::MsgCsacTelemetry;
use self::system::MsgCsacTelemetryLabels;
use self::system::MsgDgnssStatus;
use self::system::MsgGnssTimeOffset;
use self::system::MsgGroupMeta;
use self::system::MsgHeartbeat;
use self::system::MsgInsStatus;
use self::system::MsgInsUpdates;
use self::system::MsgPpsTime;
use self::system::MsgStartup;
use self::system::MsgStatusReport;
use self::tracking::MsgMeasurementState;
use self::tracking::MsgTrackingIq;
use self::tracking::MsgTrackingIqDepA;
use self::tracking::MsgTrackingIqDepB;
use self::tracking::MsgTrackingState;
use self::tracking::MsgTrackingStateDepA;
use self::tracking::MsgTrackingStateDepB;
use self::tracking::MsgTrackingStateDetailedDep;
use self::tracking::MsgTrackingStateDetailedDepA;
use self::unknown::Unknown;
use self::user::MsgUserData;
use self::vehicle::MsgOdometry;
use self::vehicle::MsgWheeltick;

use crate::serialize::SbpSerialize;

pub trait SBPMessage: SbpSerialize {
    fn get_message_name(&self) -> &'static str;
    fn get_message_type(&self) -> u16;
    fn get_sender_id(&self) -> Option<u16>;
    fn set_sender_id(&mut self, new_id: u16);
    fn to_frame(&self) -> std::result::Result<Vec<u8>, crate::FramerError>;
    fn write_frame(&self, buf: &mut Vec<u8>) -> std::result::Result<(), crate::FramerError>;
    #[cfg(feature = "swiftnav-rs")]
    fn gps_time(
        &self,
    ) -> Option<std::result::Result<crate::time::MessageTime, crate::time::GpsTimeError>> {
        None
    }
}

pub trait ConcreteMessage:
    SBPMessage + std::convert::TryFrom<SBP, Error = TryFromSBPError> + Clone + Sized
{
    const MESSAGE_TYPE: u16;
    const MESSAGE_NAME: &'static str;
}

#[derive(Debug, Clone)]
pub struct TryFromSBPError;

impl std::fmt::Display for TryFromSBPError {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        write!(f, "invalid message type for conversion")
    }
}

impl std::error::Error for TryFromSBPError {}

#[cfg_attr(feature = "sbp_serde", derive(serde::Serialize), serde(untagged))]
#[derive(Debug, Clone)]
pub enum SBP {
    MsgPrintDep(MsgPrintDep),
    MsgTrackingStateDetailedDep(MsgTrackingStateDetailedDep),
    MsgTrackingStateDepB(MsgTrackingStateDepB),
    MsgAcqResultDepB(MsgAcqResultDepB),
    MsgAcqResultDepA(MsgAcqResultDepA),
    MsgTrackingStateDepA(MsgTrackingStateDepA),
    MsgThreadState(MsgThreadState),
    MsgUartStateDepa(MsgUartStateDepa),
    MsgIarState(MsgIarState),
    MsgEphemerisDepA(MsgEphemerisDepA),
    MsgMaskSatelliteDep(MsgMaskSatelliteDep),
    MsgTrackingIqDepA(MsgTrackingIqDepA),
    MsgUartState(MsgUartState),
    MsgAcqSvProfileDep(MsgAcqSvProfileDep),
    MsgAcqResultDepC(MsgAcqResultDepC),
    MsgTrackingStateDetailedDepA(MsgTrackingStateDetailedDepA),
    MsgResetFilters(MsgResetFilters),
    MsgInitBaseDep(MsgInitBaseDep),
    MsgMaskSatellite(MsgMaskSatellite),
    MsgTrackingIqDepB(MsgTrackingIqDepB),
    MsgTrackingIq(MsgTrackingIq),
    MsgAcqSvProfile(MsgAcqSvProfile),
    MsgAcqResult(MsgAcqResult),
    MsgTrackingState(MsgTrackingState),
    MsgObsDepB(MsgObsDepB),
    MsgBasePosLLH(MsgBasePosLLH),
    MsgObsDepA(MsgObsDepA),
    MsgEphemerisDepB(MsgEphemerisDepB),
    MsgEphemerisDepC(MsgEphemerisDepC),
    MsgBasePosECEF(MsgBasePosECEF),
    MsgObsDepC(MsgObsDepC),
    MsgObs(MsgObs),
    MsgSpecanDep(MsgSpecanDep),
    MsgSpecan(MsgSpecan),
    MsgMeasurementState(MsgMeasurementState),
    MsgSetTime(MsgSetTime),
    MsgAlmanac(MsgAlmanac),
    MsgAlmanacGPSDep(MsgAlmanacGPSDep),
    MsgAlmanacGloDep(MsgAlmanacGloDep),
    MsgAlmanacGPS(MsgAlmanacGPS),
    MsgAlmanacGlo(MsgAlmanacGlo),
    MsgGloBiases(MsgGloBiases),
    MsgEphemerisDepD(MsgEphemerisDepD),
    MsgEphemerisGPSDepE(MsgEphemerisGPSDepE),
    MsgEphemerisSbasDepA(MsgEphemerisSbasDepA),
    MsgEphemerisGloDepA(MsgEphemerisGloDepA),
    MsgEphemerisSbasDepB(MsgEphemerisSbasDepB),
    MsgEphemerisGloDepB(MsgEphemerisGloDepB),
    MsgEphemerisGPSDepF(MsgEphemerisGPSDepF),
    MsgEphemerisGloDepC(MsgEphemerisGloDepC),
    MsgEphemerisGloDepD(MsgEphemerisGloDepD),
    MsgEphemerisBds(MsgEphemerisBds),
    MsgEphemerisGPS(MsgEphemerisGPS),
    MsgEphemerisGlo(MsgEphemerisGlo),
    MsgEphemerisSbas(MsgEphemerisSbas),
    MsgEphemerisGal(MsgEphemerisGal),
    MsgEphemerisQzss(MsgEphemerisQzss),
    MsgIono(MsgIono),
    MsgSvConfigurationGPSDep(MsgSvConfigurationGPSDep),
    MsgGroupDelayDepA(MsgGroupDelayDepA),
    MsgGroupDelayDepB(MsgGroupDelayDepB),
    MsgGroupDelay(MsgGroupDelay),
    MsgEphemerisGalDepA(MsgEphemerisGalDepA),
    MsgGnssCapb(MsgGnssCapb),
    MsgSvAzEl(MsgSvAzEl),
    MsgSettingsWrite(MsgSettingsWrite),
    MsgSettingsSave(MsgSettingsSave),
    MsgSettingsReadByIndexReq(MsgSettingsReadByIndexReq),
    MsgFileioReadResp(MsgFileioReadResp),
    MsgSettingsReadReq(MsgSettingsReadReq),
    MsgSettingsReadResp(MsgSettingsReadResp),
    MsgSettingsReadByIndexDone(MsgSettingsReadByIndexDone),
    MsgSettingsReadByIndexResp(MsgSettingsReadByIndexResp),
    MsgFileioReadReq(MsgFileioReadReq),
    MsgFileioReadDirReq(MsgFileioReadDirReq),
    MsgFileioReadDirResp(MsgFileioReadDirResp),
    MsgFileioWriteResp(MsgFileioWriteResp),
    MsgFileioRemove(MsgFileioRemove),
    MsgFileioWriteReq(MsgFileioWriteReq),
    MsgSettingsRegister(MsgSettingsRegister),
    MsgSettingsWriteResp(MsgSettingsWriteResp),
    MsgBootloaderHandshakeDepA(MsgBootloaderHandshakeDepA),
    MsgBootloaderJumpToApp(MsgBootloaderJumpToApp),
    MsgResetDep(MsgResetDep),
    MsgBootloaderHandshakeReq(MsgBootloaderHandshakeReq),
    MsgBootloaderHandshakeResp(MsgBootloaderHandshakeResp),
    MsgDeviceMonitor(MsgDeviceMonitor),
    MsgReset(MsgReset),
    MsgCommandReq(MsgCommandReq),
    MsgCommandResp(MsgCommandResp),
    MsgNetworkStateReq(MsgNetworkStateReq),
    MsgNetworkStateResp(MsgNetworkStateResp),
    MsgCommandOutput(MsgCommandOutput),
    MsgNetworkBandwidthUsage(MsgNetworkBandwidthUsage),
    MsgCellModemStatus(MsgCellModemStatus),
    MsgFrontEndGain(MsgFrontEndGain),
    MsgCwResults(MsgCwResults),
    MsgCwStart(MsgCwStart),
    MsgNapDeviceDnaResp(MsgNapDeviceDnaResp),
    MsgNapDeviceDnaReq(MsgNapDeviceDnaReq),
    MsgFlashDone(MsgFlashDone),
    MsgFlashReadResp(MsgFlashReadResp),
    MsgFlashErase(MsgFlashErase),
    MsgStmFlashLockSector(MsgStmFlashLockSector),
    MsgStmFlashUnlockSector(MsgStmFlashUnlockSector),
    MsgStmUniqueIdResp(MsgStmUniqueIdResp),
    MsgFlashProgram(MsgFlashProgram),
    MsgFlashReadReq(MsgFlashReadReq),
    MsgStmUniqueIdReq(MsgStmUniqueIdReq),
    MsgM25FlashWriteStatus(MsgM25FlashWriteStatus),
    MsgGPSTimeDepA(MsgGPSTimeDepA),
    MsgExtEvent(MsgExtEvent),
    MsgGPSTime(MsgGPSTime),
    MsgUtcTime(MsgUtcTime),
    MsgGPSTimeGnss(MsgGPSTimeGnss),
    MsgUtcTimeGnss(MsgUtcTimeGnss),
    MsgSettingsRegisterResp(MsgSettingsRegisterResp),
    MsgPosECEFDepA(MsgPosECEFDepA),
    MsgPosLLHDepA(MsgPosLLHDepA),
    MsgBaselineECEFDepA(MsgBaselineECEFDepA),
    MsgBaselineNEDDepA(MsgBaselineNEDDepA),
    MsgVelECEFDepA(MsgVelECEFDepA),
    MsgVelNEDDepA(MsgVelNEDDepA),
    MsgDopsDepA(MsgDopsDepA),
    MsgBaselineHeadingDepA(MsgBaselineHeadingDepA),
    MsgDops(MsgDops),
    MsgPosECEF(MsgPosECEF),
    MsgPosLLH(MsgPosLLH),
    MsgBaselineECEF(MsgBaselineECEF),
    MsgBaselineNED(MsgBaselineNED),
    MsgVelECEF(MsgVelECEF),
    MsgVelNED(MsgVelNED),
    MsgBaselineHeading(MsgBaselineHeading),
    MsgAgeCorrections(MsgAgeCorrections),
    MsgPosLLHCov(MsgPosLLHCov),
    MsgVelNEDCov(MsgVelNEDCov),
    MsgVelBody(MsgVelBody),
    MsgPosECEFCov(MsgPosECEFCov),
    MsgVelECEFCov(MsgVelECEFCov),
    MsgProtectionLevelDepA(MsgProtectionLevelDepA),
    MsgProtectionLevel(MsgProtectionLevel),
    MsgPosLLHAcc(MsgPosLLHAcc),
    MsgOrientQuat(MsgOrientQuat),
    MsgOrientEuler(MsgOrientEuler),
    MsgAngularRate(MsgAngularRate),
    MsgPosECEFGnss(MsgPosECEFGnss),
    MsgPosLLHGnss(MsgPosLLHGnss),
    MsgVelECEFGnss(MsgVelECEFGnss),
    MsgVelNEDGnss(MsgVelNEDGnss),
    MsgPosLLHCovGnss(MsgPosLLHCovGnss),
    MsgVelNEDCovGnss(MsgVelNEDCovGnss),
    MsgPosECEFCovGnss(MsgPosECEFCovGnss),
    MsgVelECEFCovGnss(MsgVelECEFCovGnss),
    MsgNdbEvent(MsgNdbEvent),
    MsgLog(MsgLog),
    MsgFwd(MsgFwd),
    MsgSsrOrbitClockDepA(MsgSsrOrbitClockDepA),
    MsgSsrOrbitClock(MsgSsrOrbitClock),
    MsgSsrCodeBiases(MsgSsrCodeBiases),
    MsgSsrPhaseBiases(MsgSsrPhaseBiases),
    MsgSsrStecCorrectionDepA(MsgSsrStecCorrectionDepA),
    MsgSsrGriddedCorrectionNoStdDepA(MsgSsrGriddedCorrectionNoStdDepA),
    MsgSsrGridDefinitionDepA(MsgSsrGridDefinitionDepA),
    MsgSsrTileDefinition(MsgSsrTileDefinition),
    MsgSsrGriddedCorrectionDepA(MsgSsrGriddedCorrectionDepA),
    MsgSsrStecCorrection(MsgSsrStecCorrection),
    MsgSsrGriddedCorrection(MsgSsrGriddedCorrection),
    MsgSsrSatelliteApc(MsgSsrSatelliteApc),
    MsgOsr(MsgOsr),
    MsgUserData(MsgUserData),
    MsgImuRaw(MsgImuRaw),
    MsgImuAux(MsgImuAux),
    MsgMagRaw(MsgMagRaw),
    MsgOdometry(MsgOdometry),
    MsgWheeltick(MsgWheeltick),
    MsgFileioConfigReq(MsgFileioConfigReq),
    MsgFileioConfigResp(MsgFileioConfigResp),
    MsgSbasRaw(MsgSbasRaw),
    MsgLinuxCpuStateDepA(MsgLinuxCpuStateDepA),
    MsgLinuxMemStateDepA(MsgLinuxMemStateDepA),
    MsgLinuxSysStateDepA(MsgLinuxSysStateDepA),
    MsgLinuxProcessSocketCounts(MsgLinuxProcessSocketCounts),
    MsgLinuxProcessSocketQueues(MsgLinuxProcessSocketQueues),
    MsgLinuxSocketUsage(MsgLinuxSocketUsage),
    MsgLinuxProcessFdCount(MsgLinuxProcessFdCount),
    MsgLinuxProcessFdSummary(MsgLinuxProcessFdSummary),
    MsgLinuxCpuState(MsgLinuxCpuState),
    MsgLinuxMemState(MsgLinuxMemState),
    MsgLinuxSysState(MsgLinuxSysState),
    MsgStartup(MsgStartup),
    MsgDgnssStatus(MsgDgnssStatus),
    MsgInsStatus(MsgInsStatus),
    MsgCsacTelemetry(MsgCsacTelemetry),
    MsgCsacTelemetryLabels(MsgCsacTelemetryLabels),
    MsgInsUpdates(MsgInsUpdates),
    MsgGnssTimeOffset(MsgGnssTimeOffset),
    MsgPpsTime(MsgPpsTime),
    MsgGroupMeta(MsgGroupMeta),
    MsgSolnMeta(MsgSolnMeta),
    MsgSolnMetaDepA(MsgSolnMetaDepA),
    MsgStatusReport(MsgStatusReport),
    MsgHeartbeat(MsgHeartbeat),
    Unknown(Unknown),
}

impl SBP {
    pub fn parse(msg_id: u16, sender_id: u16, payload: &mut &[u8]) -> Result<SBP, crate::Error> {
        match msg_id {
            16 => {
                let mut msg = MsgPrintDep::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgPrintDep(msg))
            }
            17 => {
                let mut msg = MsgTrackingStateDetailedDep::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgTrackingStateDetailedDep(msg))
            }
            19 => {
                let mut msg = MsgTrackingStateDepB::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgTrackingStateDepB(msg))
            }
            20 => {
                let mut msg = MsgAcqResultDepB::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgAcqResultDepB(msg))
            }
            21 => {
                let mut msg = MsgAcqResultDepA::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgAcqResultDepA(msg))
            }
            22 => {
                let mut msg = MsgTrackingStateDepA::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgTrackingStateDepA(msg))
            }
            23 => {
                let mut msg = MsgThreadState::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgThreadState(msg))
            }
            24 => {
                let mut msg = MsgUartStateDepa::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgUartStateDepa(msg))
            }
            25 => {
                let mut msg = MsgIarState::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgIarState(msg))
            }
            26 => {
                let mut msg = MsgEphemerisDepA::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgEphemerisDepA(msg))
            }
            27 => {
                let mut msg = MsgMaskSatelliteDep::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgMaskSatelliteDep(msg))
            }
            28 => {
                let mut msg = MsgTrackingIqDepA::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgTrackingIqDepA(msg))
            }
            29 => {
                let mut msg = MsgUartState::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgUartState(msg))
            }
            30 => {
                let mut msg = MsgAcqSvProfileDep::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgAcqSvProfileDep(msg))
            }
            31 => {
                let mut msg = MsgAcqResultDepC::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgAcqResultDepC(msg))
            }
            33 => {
                let mut msg = MsgTrackingStateDetailedDepA::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgTrackingStateDetailedDepA(msg))
            }
            34 => {
                let mut msg = MsgResetFilters::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgResetFilters(msg))
            }
            35 => {
                let mut msg = MsgInitBaseDep::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgInitBaseDep(msg))
            }
            43 => {
                let mut msg = MsgMaskSatellite::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgMaskSatellite(msg))
            }
            44 => {
                let mut msg = MsgTrackingIqDepB::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgTrackingIqDepB(msg))
            }
            45 => {
                let mut msg = MsgTrackingIq::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgTrackingIq(msg))
            }
            46 => {
                let mut msg = MsgAcqSvProfile::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgAcqSvProfile(msg))
            }
            47 => {
                let mut msg = MsgAcqResult::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgAcqResult(msg))
            }
            65 => {
                let mut msg = MsgTrackingState::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgTrackingState(msg))
            }
            67 => {
                let mut msg = MsgObsDepB::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgObsDepB(msg))
            }
            68 => {
                let mut msg = MsgBasePosLLH::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgBasePosLLH(msg))
            }
            69 => {
                let mut msg = MsgObsDepA::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgObsDepA(msg))
            }
            70 => {
                let mut msg = MsgEphemerisDepB::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgEphemerisDepB(msg))
            }
            71 => {
                let mut msg = MsgEphemerisDepC::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgEphemerisDepC(msg))
            }
            72 => {
                let mut msg = MsgBasePosECEF::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgBasePosECEF(msg))
            }
            73 => {
                let mut msg = MsgObsDepC::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgObsDepC(msg))
            }
            74 => {
                let mut msg = MsgObs::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgObs(msg))
            }
            80 => {
                let mut msg = MsgSpecanDep::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgSpecanDep(msg))
            }
            81 => {
                let mut msg = MsgSpecan::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgSpecan(msg))
            }
            97 => {
                let mut msg = MsgMeasurementState::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgMeasurementState(msg))
            }
            104 => {
                let mut msg = MsgSetTime::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgSetTime(msg))
            }
            105 => {
                let mut msg = MsgAlmanac::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgAlmanac(msg))
            }
            112 => {
                let mut msg = MsgAlmanacGPSDep::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgAlmanacGPSDep(msg))
            }
            113 => {
                let mut msg = MsgAlmanacGloDep::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgAlmanacGloDep(msg))
            }
            114 => {
                let mut msg = MsgAlmanacGPS::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgAlmanacGPS(msg))
            }
            115 => {
                let mut msg = MsgAlmanacGlo::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgAlmanacGlo(msg))
            }
            117 => {
                let mut msg = MsgGloBiases::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgGloBiases(msg))
            }
            128 => {
                let mut msg = MsgEphemerisDepD::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgEphemerisDepD(msg))
            }
            129 => {
                let mut msg = MsgEphemerisGPSDepE::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgEphemerisGPSDepE(msg))
            }
            130 => {
                let mut msg = MsgEphemerisSbasDepA::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgEphemerisSbasDepA(msg))
            }
            131 => {
                let mut msg = MsgEphemerisGloDepA::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgEphemerisGloDepA(msg))
            }
            132 => {
                let mut msg = MsgEphemerisSbasDepB::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgEphemerisSbasDepB(msg))
            }
            133 => {
                let mut msg = MsgEphemerisGloDepB::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgEphemerisGloDepB(msg))
            }
            134 => {
                let mut msg = MsgEphemerisGPSDepF::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgEphemerisGPSDepF(msg))
            }
            135 => {
                let mut msg = MsgEphemerisGloDepC::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgEphemerisGloDepC(msg))
            }
            136 => {
                let mut msg = MsgEphemerisGloDepD::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgEphemerisGloDepD(msg))
            }
            137 => {
                let mut msg = MsgEphemerisBds::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgEphemerisBds(msg))
            }
            138 => {
                let mut msg = MsgEphemerisGPS::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgEphemerisGPS(msg))
            }
            139 => {
                let mut msg = MsgEphemerisGlo::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgEphemerisGlo(msg))
            }
            140 => {
                let mut msg = MsgEphemerisSbas::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgEphemerisSbas(msg))
            }
            141 => {
                let mut msg = MsgEphemerisGal::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgEphemerisGal(msg))
            }
            142 => {
                let mut msg = MsgEphemerisQzss::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgEphemerisQzss(msg))
            }
            144 => {
                let mut msg = MsgIono::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgIono(msg))
            }
            145 => {
                let mut msg = MsgSvConfigurationGPSDep::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgSvConfigurationGPSDep(msg))
            }
            146 => {
                let mut msg = MsgGroupDelayDepA::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgGroupDelayDepA(msg))
            }
            147 => {
                let mut msg = MsgGroupDelayDepB::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgGroupDelayDepB(msg))
            }
            148 => {
                let mut msg = MsgGroupDelay::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgGroupDelay(msg))
            }
            149 => {
                let mut msg = MsgEphemerisGalDepA::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgEphemerisGalDepA(msg))
            }
            150 => {
                let mut msg = MsgGnssCapb::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgGnssCapb(msg))
            }
            151 => {
                let mut msg = MsgSvAzEl::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgSvAzEl(msg))
            }
            160 => {
                let mut msg = MsgSettingsWrite::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgSettingsWrite(msg))
            }
            161 => {
                let mut msg = MsgSettingsSave::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgSettingsSave(msg))
            }
            162 => {
                let mut msg = MsgSettingsReadByIndexReq::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgSettingsReadByIndexReq(msg))
            }
            163 => {
                let mut msg = MsgFileioReadResp::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgFileioReadResp(msg))
            }
            164 => {
                let mut msg = MsgSettingsReadReq::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgSettingsReadReq(msg))
            }
            165 => {
                let mut msg = MsgSettingsReadResp::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgSettingsReadResp(msg))
            }
            166 => {
                let mut msg = MsgSettingsReadByIndexDone::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgSettingsReadByIndexDone(msg))
            }
            167 => {
                let mut msg = MsgSettingsReadByIndexResp::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgSettingsReadByIndexResp(msg))
            }
            168 => {
                let mut msg = MsgFileioReadReq::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgFileioReadReq(msg))
            }
            169 => {
                let mut msg = MsgFileioReadDirReq::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgFileioReadDirReq(msg))
            }
            170 => {
                let mut msg = MsgFileioReadDirResp::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgFileioReadDirResp(msg))
            }
            171 => {
                let mut msg = MsgFileioWriteResp::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgFileioWriteResp(msg))
            }
            172 => {
                let mut msg = MsgFileioRemove::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgFileioRemove(msg))
            }
            173 => {
                let mut msg = MsgFileioWriteReq::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgFileioWriteReq(msg))
            }
            174 => {
                let mut msg = MsgSettingsRegister::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgSettingsRegister(msg))
            }
            175 => {
                let mut msg = MsgSettingsWriteResp::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgSettingsWriteResp(msg))
            }
            176 => {
                let mut msg = MsgBootloaderHandshakeDepA::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgBootloaderHandshakeDepA(msg))
            }
            177 => {
                let mut msg = MsgBootloaderJumpToApp::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgBootloaderJumpToApp(msg))
            }
            178 => {
                let mut msg = MsgResetDep::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgResetDep(msg))
            }
            179 => {
                let mut msg = MsgBootloaderHandshakeReq::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgBootloaderHandshakeReq(msg))
            }
            180 => {
                let mut msg = MsgBootloaderHandshakeResp::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgBootloaderHandshakeResp(msg))
            }
            181 => {
                let mut msg = MsgDeviceMonitor::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgDeviceMonitor(msg))
            }
            182 => {
                let mut msg = MsgReset::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgReset(msg))
            }
            184 => {
                let mut msg = MsgCommandReq::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgCommandReq(msg))
            }
            185 => {
                let mut msg = MsgCommandResp::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgCommandResp(msg))
            }
            186 => {
                let mut msg = MsgNetworkStateReq::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgNetworkStateReq(msg))
            }
            187 => {
                let mut msg = MsgNetworkStateResp::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgNetworkStateResp(msg))
            }
            188 => {
                let mut msg = MsgCommandOutput::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgCommandOutput(msg))
            }
            189 => {
                let mut msg = MsgNetworkBandwidthUsage::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgNetworkBandwidthUsage(msg))
            }
            190 => {
                let mut msg = MsgCellModemStatus::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgCellModemStatus(msg))
            }
            191 => {
                let mut msg = MsgFrontEndGain::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgFrontEndGain(msg))
            }
            192 => {
                let mut msg = MsgCwResults::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgCwResults(msg))
            }
            193 => {
                let mut msg = MsgCwStart::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgCwStart(msg))
            }
            221 => {
                let mut msg = MsgNapDeviceDnaResp::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgNapDeviceDnaResp(msg))
            }
            222 => {
                let mut msg = MsgNapDeviceDnaReq::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgNapDeviceDnaReq(msg))
            }
            224 => {
                let mut msg = MsgFlashDone::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgFlashDone(msg))
            }
            225 => {
                let mut msg = MsgFlashReadResp::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgFlashReadResp(msg))
            }
            226 => {
                let mut msg = MsgFlashErase::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgFlashErase(msg))
            }
            227 => {
                let mut msg = MsgStmFlashLockSector::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgStmFlashLockSector(msg))
            }
            228 => {
                let mut msg = MsgStmFlashUnlockSector::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgStmFlashUnlockSector(msg))
            }
            229 => {
                let mut msg = MsgStmUniqueIdResp::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgStmUniqueIdResp(msg))
            }
            230 => {
                let mut msg = MsgFlashProgram::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgFlashProgram(msg))
            }
            231 => {
                let mut msg = MsgFlashReadReq::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgFlashReadReq(msg))
            }
            232 => {
                let mut msg = MsgStmUniqueIdReq::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgStmUniqueIdReq(msg))
            }
            243 => {
                let mut msg = MsgM25FlashWriteStatus::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgM25FlashWriteStatus(msg))
            }
            256 => {
                let mut msg = MsgGPSTimeDepA::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgGPSTimeDepA(msg))
            }
            257 => {
                let mut msg = MsgExtEvent::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgExtEvent(msg))
            }
            258 => {
                let mut msg = MsgGPSTime::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgGPSTime(msg))
            }
            259 => {
                let mut msg = MsgUtcTime::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgUtcTime(msg))
            }
            260 => {
                let mut msg = MsgGPSTimeGnss::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgGPSTimeGnss(msg))
            }
            261 => {
                let mut msg = MsgUtcTimeGnss::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgUtcTimeGnss(msg))
            }
            431 => {
                let mut msg = MsgSettingsRegisterResp::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgSettingsRegisterResp(msg))
            }
            512 => {
                let mut msg = MsgPosECEFDepA::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgPosECEFDepA(msg))
            }
            513 => {
                let mut msg = MsgPosLLHDepA::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgPosLLHDepA(msg))
            }
            514 => {
                let mut msg = MsgBaselineECEFDepA::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgBaselineECEFDepA(msg))
            }
            515 => {
                let mut msg = MsgBaselineNEDDepA::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgBaselineNEDDepA(msg))
            }
            516 => {
                let mut msg = MsgVelECEFDepA::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgVelECEFDepA(msg))
            }
            517 => {
                let mut msg = MsgVelNEDDepA::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgVelNEDDepA(msg))
            }
            518 => {
                let mut msg = MsgDopsDepA::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgDopsDepA(msg))
            }
            519 => {
                let mut msg = MsgBaselineHeadingDepA::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgBaselineHeadingDepA(msg))
            }
            520 => {
                let mut msg = MsgDops::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgDops(msg))
            }
            521 => {
                let mut msg = MsgPosECEF::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgPosECEF(msg))
            }
            522 => {
                let mut msg = MsgPosLLH::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgPosLLH(msg))
            }
            523 => {
                let mut msg = MsgBaselineECEF::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgBaselineECEF(msg))
            }
            524 => {
                let mut msg = MsgBaselineNED::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgBaselineNED(msg))
            }
            525 => {
                let mut msg = MsgVelECEF::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgVelECEF(msg))
            }
            526 => {
                let mut msg = MsgVelNED::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgVelNED(msg))
            }
            527 => {
                let mut msg = MsgBaselineHeading::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgBaselineHeading(msg))
            }
            528 => {
                let mut msg = MsgAgeCorrections::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgAgeCorrections(msg))
            }
            529 => {
                let mut msg = MsgPosLLHCov::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgPosLLHCov(msg))
            }
            530 => {
                let mut msg = MsgVelNEDCov::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgVelNEDCov(msg))
            }
            531 => {
                let mut msg = MsgVelBody::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgVelBody(msg))
            }
            532 => {
                let mut msg = MsgPosECEFCov::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgPosECEFCov(msg))
            }
            533 => {
                let mut msg = MsgVelECEFCov::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgVelECEFCov(msg))
            }
            534 => {
                let mut msg = MsgProtectionLevelDepA::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgProtectionLevelDepA(msg))
            }
            535 => {
                let mut msg = MsgProtectionLevel::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgProtectionLevel(msg))
            }
            536 => {
                let mut msg = MsgPosLLHAcc::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgPosLLHAcc(msg))
            }
            544 => {
                let mut msg = MsgOrientQuat::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgOrientQuat(msg))
            }
            545 => {
                let mut msg = MsgOrientEuler::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgOrientEuler(msg))
            }
            546 => {
                let mut msg = MsgAngularRate::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgAngularRate(msg))
            }
            553 => {
                let mut msg = MsgPosECEFGnss::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgPosECEFGnss(msg))
            }
            554 => {
                let mut msg = MsgPosLLHGnss::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgPosLLHGnss(msg))
            }
            557 => {
                let mut msg = MsgVelECEFGnss::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgVelECEFGnss(msg))
            }
            558 => {
                let mut msg = MsgVelNEDGnss::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgVelNEDGnss(msg))
            }
            561 => {
                let mut msg = MsgPosLLHCovGnss::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgPosLLHCovGnss(msg))
            }
            562 => {
                let mut msg = MsgVelNEDCovGnss::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgVelNEDCovGnss(msg))
            }
            564 => {
                let mut msg = MsgPosECEFCovGnss::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgPosECEFCovGnss(msg))
            }
            565 => {
                let mut msg = MsgVelECEFCovGnss::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgVelECEFCovGnss(msg))
            }
            1024 => {
                let mut msg = MsgNdbEvent::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgNdbEvent(msg))
            }
            1025 => {
                let mut msg = MsgLog::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgLog(msg))
            }
            1026 => {
                let mut msg = MsgFwd::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgFwd(msg))
            }
            1500 => {
                let mut msg = MsgSsrOrbitClockDepA::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgSsrOrbitClockDepA(msg))
            }
            1501 => {
                let mut msg = MsgSsrOrbitClock::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgSsrOrbitClock(msg))
            }
            1505 => {
                let mut msg = MsgSsrCodeBiases::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgSsrCodeBiases(msg))
            }
            1510 => {
                let mut msg = MsgSsrPhaseBiases::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgSsrPhaseBiases(msg))
            }
            1515 => {
                let mut msg = MsgSsrStecCorrectionDepA::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgSsrStecCorrectionDepA(msg))
            }
            1520 => {
                let mut msg = MsgSsrGriddedCorrectionNoStdDepA::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgSsrGriddedCorrectionNoStdDepA(msg))
            }
            1525 => {
                let mut msg = MsgSsrGridDefinitionDepA::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgSsrGridDefinitionDepA(msg))
            }
            1526 => {
                let mut msg = MsgSsrTileDefinition::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgSsrTileDefinition(msg))
            }
            1530 => {
                let mut msg = MsgSsrGriddedCorrectionDepA::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgSsrGriddedCorrectionDepA(msg))
            }
            1531 => {
                let mut msg = MsgSsrStecCorrection::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgSsrStecCorrection(msg))
            }
            1532 => {
                let mut msg = MsgSsrGriddedCorrection::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgSsrGriddedCorrection(msg))
            }
            1540 => {
                let mut msg = MsgSsrSatelliteApc::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgSsrSatelliteApc(msg))
            }
            1600 => {
                let mut msg = MsgOsr::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgOsr(msg))
            }
            2048 => {
                let mut msg = MsgUserData::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgUserData(msg))
            }
            2304 => {
                let mut msg = MsgImuRaw::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgImuRaw(msg))
            }
            2305 => {
                let mut msg = MsgImuAux::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgImuAux(msg))
            }
            2306 => {
                let mut msg = MsgMagRaw::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgMagRaw(msg))
            }
            2307 => {
                let mut msg = MsgOdometry::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgOdometry(msg))
            }
            2308 => {
                let mut msg = MsgWheeltick::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgWheeltick(msg))
            }
            4097 => {
                let mut msg = MsgFileioConfigReq::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgFileioConfigReq(msg))
            }
            4098 => {
                let mut msg = MsgFileioConfigResp::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgFileioConfigResp(msg))
            }
            30583 => {
                let mut msg = MsgSbasRaw::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgSbasRaw(msg))
            }
            32512 => {
                let mut msg = MsgLinuxCpuStateDepA::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgLinuxCpuStateDepA(msg))
            }
            32513 => {
                let mut msg = MsgLinuxMemStateDepA::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgLinuxMemStateDepA(msg))
            }
            32514 => {
                let mut msg = MsgLinuxSysStateDepA::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgLinuxSysStateDepA(msg))
            }
            32515 => {
                let mut msg = MsgLinuxProcessSocketCounts::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgLinuxProcessSocketCounts(msg))
            }
            32516 => {
                let mut msg = MsgLinuxProcessSocketQueues::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgLinuxProcessSocketQueues(msg))
            }
            32517 => {
                let mut msg = MsgLinuxSocketUsage::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgLinuxSocketUsage(msg))
            }
            32518 => {
                let mut msg = MsgLinuxProcessFdCount::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgLinuxProcessFdCount(msg))
            }
            32519 => {
                let mut msg = MsgLinuxProcessFdSummary::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgLinuxProcessFdSummary(msg))
            }
            32520 => {
                let mut msg = MsgLinuxCpuState::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgLinuxCpuState(msg))
            }
            32521 => {
                let mut msg = MsgLinuxMemState::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgLinuxMemState(msg))
            }
            32522 => {
                let mut msg = MsgLinuxSysState::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgLinuxSysState(msg))
            }
            65280 => {
                let mut msg = MsgStartup::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgStartup(msg))
            }
            65282 => {
                let mut msg = MsgDgnssStatus::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgDgnssStatus(msg))
            }
            65283 => {
                let mut msg = MsgInsStatus::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgInsStatus(msg))
            }
            65284 => {
                let mut msg = MsgCsacTelemetry::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgCsacTelemetry(msg))
            }
            65285 => {
                let mut msg = MsgCsacTelemetryLabels::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgCsacTelemetryLabels(msg))
            }
            65286 => {
                let mut msg = MsgInsUpdates::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgInsUpdates(msg))
            }
            65287 => {
                let mut msg = MsgGnssTimeOffset::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgGnssTimeOffset(msg))
            }
            65288 => {
                let mut msg = MsgPpsTime::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgPpsTime(msg))
            }
            65290 => {
                let mut msg = MsgGroupMeta::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgGroupMeta(msg))
            }
            65294 => {
                let mut msg = MsgSolnMeta::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgSolnMeta(msg))
            }
            65295 => {
                let mut msg = MsgSolnMetaDepA::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgSolnMetaDepA(msg))
            }
            65534 => {
                let mut msg = MsgStatusReport::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgStatusReport(msg))
            }
            65535 => {
                let mut msg = MsgHeartbeat::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgHeartbeat(msg))
            }
            _ => Ok(SBP::Unknown(Unknown {
                msg_id: msg_id,
                sender_id: sender_id,
                payload: payload.to_vec(),
            })),
        }
    }
}

impl crate::SBPMessage for SBP {
    fn get_message_name(&self) -> &'static str {
        match self {
            SBP::MsgPrintDep(msg) => msg.get_message_name(),
            SBP::MsgTrackingStateDetailedDep(msg) => msg.get_message_name(),
            SBP::MsgTrackingStateDepB(msg) => msg.get_message_name(),
            SBP::MsgAcqResultDepB(msg) => msg.get_message_name(),
            SBP::MsgAcqResultDepA(msg) => msg.get_message_name(),
            SBP::MsgTrackingStateDepA(msg) => msg.get_message_name(),
            SBP::MsgThreadState(msg) => msg.get_message_name(),
            SBP::MsgUartStateDepa(msg) => msg.get_message_name(),
            SBP::MsgIarState(msg) => msg.get_message_name(),
            SBP::MsgEphemerisDepA(msg) => msg.get_message_name(),
            SBP::MsgMaskSatelliteDep(msg) => msg.get_message_name(),
            SBP::MsgTrackingIqDepA(msg) => msg.get_message_name(),
            SBP::MsgUartState(msg) => msg.get_message_name(),
            SBP::MsgAcqSvProfileDep(msg) => msg.get_message_name(),
            SBP::MsgAcqResultDepC(msg) => msg.get_message_name(),
            SBP::MsgTrackingStateDetailedDepA(msg) => msg.get_message_name(),
            SBP::MsgResetFilters(msg) => msg.get_message_name(),
            SBP::MsgInitBaseDep(msg) => msg.get_message_name(),
            SBP::MsgMaskSatellite(msg) => msg.get_message_name(),
            SBP::MsgTrackingIqDepB(msg) => msg.get_message_name(),
            SBP::MsgTrackingIq(msg) => msg.get_message_name(),
            SBP::MsgAcqSvProfile(msg) => msg.get_message_name(),
            SBP::MsgAcqResult(msg) => msg.get_message_name(),
            SBP::MsgTrackingState(msg) => msg.get_message_name(),
            SBP::MsgObsDepB(msg) => msg.get_message_name(),
            SBP::MsgBasePosLLH(msg) => msg.get_message_name(),
            SBP::MsgObsDepA(msg) => msg.get_message_name(),
            SBP::MsgEphemerisDepB(msg) => msg.get_message_name(),
            SBP::MsgEphemerisDepC(msg) => msg.get_message_name(),
            SBP::MsgBasePosECEF(msg) => msg.get_message_name(),
            SBP::MsgObsDepC(msg) => msg.get_message_name(),
            SBP::MsgObs(msg) => msg.get_message_name(),
            SBP::MsgSpecanDep(msg) => msg.get_message_name(),
            SBP::MsgSpecan(msg) => msg.get_message_name(),
            SBP::MsgMeasurementState(msg) => msg.get_message_name(),
            SBP::MsgSetTime(msg) => msg.get_message_name(),
            SBP::MsgAlmanac(msg) => msg.get_message_name(),
            SBP::MsgAlmanacGPSDep(msg) => msg.get_message_name(),
            SBP::MsgAlmanacGloDep(msg) => msg.get_message_name(),
            SBP::MsgAlmanacGPS(msg) => msg.get_message_name(),
            SBP::MsgAlmanacGlo(msg) => msg.get_message_name(),
            SBP::MsgGloBiases(msg) => msg.get_message_name(),
            SBP::MsgEphemerisDepD(msg) => msg.get_message_name(),
            SBP::MsgEphemerisGPSDepE(msg) => msg.get_message_name(),
            SBP::MsgEphemerisSbasDepA(msg) => msg.get_message_name(),
            SBP::MsgEphemerisGloDepA(msg) => msg.get_message_name(),
            SBP::MsgEphemerisSbasDepB(msg) => msg.get_message_name(),
            SBP::MsgEphemerisGloDepB(msg) => msg.get_message_name(),
            SBP::MsgEphemerisGPSDepF(msg) => msg.get_message_name(),
            SBP::MsgEphemerisGloDepC(msg) => msg.get_message_name(),
            SBP::MsgEphemerisGloDepD(msg) => msg.get_message_name(),
            SBP::MsgEphemerisBds(msg) => msg.get_message_name(),
            SBP::MsgEphemerisGPS(msg) => msg.get_message_name(),
            SBP::MsgEphemerisGlo(msg) => msg.get_message_name(),
            SBP::MsgEphemerisSbas(msg) => msg.get_message_name(),
            SBP::MsgEphemerisGal(msg) => msg.get_message_name(),
            SBP::MsgEphemerisQzss(msg) => msg.get_message_name(),
            SBP::MsgIono(msg) => msg.get_message_name(),
            SBP::MsgSvConfigurationGPSDep(msg) => msg.get_message_name(),
            SBP::MsgGroupDelayDepA(msg) => msg.get_message_name(),
            SBP::MsgGroupDelayDepB(msg) => msg.get_message_name(),
            SBP::MsgGroupDelay(msg) => msg.get_message_name(),
            SBP::MsgEphemerisGalDepA(msg) => msg.get_message_name(),
            SBP::MsgGnssCapb(msg) => msg.get_message_name(),
            SBP::MsgSvAzEl(msg) => msg.get_message_name(),
            SBP::MsgSettingsWrite(msg) => msg.get_message_name(),
            SBP::MsgSettingsSave(msg) => msg.get_message_name(),
            SBP::MsgSettingsReadByIndexReq(msg) => msg.get_message_name(),
            SBP::MsgFileioReadResp(msg) => msg.get_message_name(),
            SBP::MsgSettingsReadReq(msg) => msg.get_message_name(),
            SBP::MsgSettingsReadResp(msg) => msg.get_message_name(),
            SBP::MsgSettingsReadByIndexDone(msg) => msg.get_message_name(),
            SBP::MsgSettingsReadByIndexResp(msg) => msg.get_message_name(),
            SBP::MsgFileioReadReq(msg) => msg.get_message_name(),
            SBP::MsgFileioReadDirReq(msg) => msg.get_message_name(),
            SBP::MsgFileioReadDirResp(msg) => msg.get_message_name(),
            SBP::MsgFileioWriteResp(msg) => msg.get_message_name(),
            SBP::MsgFileioRemove(msg) => msg.get_message_name(),
            SBP::MsgFileioWriteReq(msg) => msg.get_message_name(),
            SBP::MsgSettingsRegister(msg) => msg.get_message_name(),
            SBP::MsgSettingsWriteResp(msg) => msg.get_message_name(),
            SBP::MsgBootloaderHandshakeDepA(msg) => msg.get_message_name(),
            SBP::MsgBootloaderJumpToApp(msg) => msg.get_message_name(),
            SBP::MsgResetDep(msg) => msg.get_message_name(),
            SBP::MsgBootloaderHandshakeReq(msg) => msg.get_message_name(),
            SBP::MsgBootloaderHandshakeResp(msg) => msg.get_message_name(),
            SBP::MsgDeviceMonitor(msg) => msg.get_message_name(),
            SBP::MsgReset(msg) => msg.get_message_name(),
            SBP::MsgCommandReq(msg) => msg.get_message_name(),
            SBP::MsgCommandResp(msg) => msg.get_message_name(),
            SBP::MsgNetworkStateReq(msg) => msg.get_message_name(),
            SBP::MsgNetworkStateResp(msg) => msg.get_message_name(),
            SBP::MsgCommandOutput(msg) => msg.get_message_name(),
            SBP::MsgNetworkBandwidthUsage(msg) => msg.get_message_name(),
            SBP::MsgCellModemStatus(msg) => msg.get_message_name(),
            SBP::MsgFrontEndGain(msg) => msg.get_message_name(),
            SBP::MsgCwResults(msg) => msg.get_message_name(),
            SBP::MsgCwStart(msg) => msg.get_message_name(),
            SBP::MsgNapDeviceDnaResp(msg) => msg.get_message_name(),
            SBP::MsgNapDeviceDnaReq(msg) => msg.get_message_name(),
            SBP::MsgFlashDone(msg) => msg.get_message_name(),
            SBP::MsgFlashReadResp(msg) => msg.get_message_name(),
            SBP::MsgFlashErase(msg) => msg.get_message_name(),
            SBP::MsgStmFlashLockSector(msg) => msg.get_message_name(),
            SBP::MsgStmFlashUnlockSector(msg) => msg.get_message_name(),
            SBP::MsgStmUniqueIdResp(msg) => msg.get_message_name(),
            SBP::MsgFlashProgram(msg) => msg.get_message_name(),
            SBP::MsgFlashReadReq(msg) => msg.get_message_name(),
            SBP::MsgStmUniqueIdReq(msg) => msg.get_message_name(),
            SBP::MsgM25FlashWriteStatus(msg) => msg.get_message_name(),
            SBP::MsgGPSTimeDepA(msg) => msg.get_message_name(),
            SBP::MsgExtEvent(msg) => msg.get_message_name(),
            SBP::MsgGPSTime(msg) => msg.get_message_name(),
            SBP::MsgUtcTime(msg) => msg.get_message_name(),
            SBP::MsgGPSTimeGnss(msg) => msg.get_message_name(),
            SBP::MsgUtcTimeGnss(msg) => msg.get_message_name(),
            SBP::MsgSettingsRegisterResp(msg) => msg.get_message_name(),
            SBP::MsgPosECEFDepA(msg) => msg.get_message_name(),
            SBP::MsgPosLLHDepA(msg) => msg.get_message_name(),
            SBP::MsgBaselineECEFDepA(msg) => msg.get_message_name(),
            SBP::MsgBaselineNEDDepA(msg) => msg.get_message_name(),
            SBP::MsgVelECEFDepA(msg) => msg.get_message_name(),
            SBP::MsgVelNEDDepA(msg) => msg.get_message_name(),
            SBP::MsgDopsDepA(msg) => msg.get_message_name(),
            SBP::MsgBaselineHeadingDepA(msg) => msg.get_message_name(),
            SBP::MsgDops(msg) => msg.get_message_name(),
            SBP::MsgPosECEF(msg) => msg.get_message_name(),
            SBP::MsgPosLLH(msg) => msg.get_message_name(),
            SBP::MsgBaselineECEF(msg) => msg.get_message_name(),
            SBP::MsgBaselineNED(msg) => msg.get_message_name(),
            SBP::MsgVelECEF(msg) => msg.get_message_name(),
            SBP::MsgVelNED(msg) => msg.get_message_name(),
            SBP::MsgBaselineHeading(msg) => msg.get_message_name(),
            SBP::MsgAgeCorrections(msg) => msg.get_message_name(),
            SBP::MsgPosLLHCov(msg) => msg.get_message_name(),
            SBP::MsgVelNEDCov(msg) => msg.get_message_name(),
            SBP::MsgVelBody(msg) => msg.get_message_name(),
            SBP::MsgPosECEFCov(msg) => msg.get_message_name(),
            SBP::MsgVelECEFCov(msg) => msg.get_message_name(),
            SBP::MsgProtectionLevelDepA(msg) => msg.get_message_name(),
            SBP::MsgProtectionLevel(msg) => msg.get_message_name(),
            SBP::MsgPosLLHAcc(msg) => msg.get_message_name(),
            SBP::MsgOrientQuat(msg) => msg.get_message_name(),
            SBP::MsgOrientEuler(msg) => msg.get_message_name(),
            SBP::MsgAngularRate(msg) => msg.get_message_name(),
            SBP::MsgPosECEFGnss(msg) => msg.get_message_name(),
            SBP::MsgPosLLHGnss(msg) => msg.get_message_name(),
            SBP::MsgVelECEFGnss(msg) => msg.get_message_name(),
            SBP::MsgVelNEDGnss(msg) => msg.get_message_name(),
            SBP::MsgPosLLHCovGnss(msg) => msg.get_message_name(),
            SBP::MsgVelNEDCovGnss(msg) => msg.get_message_name(),
            SBP::MsgPosECEFCovGnss(msg) => msg.get_message_name(),
            SBP::MsgVelECEFCovGnss(msg) => msg.get_message_name(),
            SBP::MsgNdbEvent(msg) => msg.get_message_name(),
            SBP::MsgLog(msg) => msg.get_message_name(),
            SBP::MsgFwd(msg) => msg.get_message_name(),
            SBP::MsgSsrOrbitClockDepA(msg) => msg.get_message_name(),
            SBP::MsgSsrOrbitClock(msg) => msg.get_message_name(),
            SBP::MsgSsrCodeBiases(msg) => msg.get_message_name(),
            SBP::MsgSsrPhaseBiases(msg) => msg.get_message_name(),
            SBP::MsgSsrStecCorrectionDepA(msg) => msg.get_message_name(),
            SBP::MsgSsrGriddedCorrectionNoStdDepA(msg) => msg.get_message_name(),
            SBP::MsgSsrGridDefinitionDepA(msg) => msg.get_message_name(),
            SBP::MsgSsrTileDefinition(msg) => msg.get_message_name(),
            SBP::MsgSsrGriddedCorrectionDepA(msg) => msg.get_message_name(),
            SBP::MsgSsrStecCorrection(msg) => msg.get_message_name(),
            SBP::MsgSsrGriddedCorrection(msg) => msg.get_message_name(),
            SBP::MsgSsrSatelliteApc(msg) => msg.get_message_name(),
            SBP::MsgOsr(msg) => msg.get_message_name(),
            SBP::MsgUserData(msg) => msg.get_message_name(),
            SBP::MsgImuRaw(msg) => msg.get_message_name(),
            SBP::MsgImuAux(msg) => msg.get_message_name(),
            SBP::MsgMagRaw(msg) => msg.get_message_name(),
            SBP::MsgOdometry(msg) => msg.get_message_name(),
            SBP::MsgWheeltick(msg) => msg.get_message_name(),
            SBP::MsgFileioConfigReq(msg) => msg.get_message_name(),
            SBP::MsgFileioConfigResp(msg) => msg.get_message_name(),
            SBP::MsgSbasRaw(msg) => msg.get_message_name(),
            SBP::MsgLinuxCpuStateDepA(msg) => msg.get_message_name(),
            SBP::MsgLinuxMemStateDepA(msg) => msg.get_message_name(),
            SBP::MsgLinuxSysStateDepA(msg) => msg.get_message_name(),
            SBP::MsgLinuxProcessSocketCounts(msg) => msg.get_message_name(),
            SBP::MsgLinuxProcessSocketQueues(msg) => msg.get_message_name(),
            SBP::MsgLinuxSocketUsage(msg) => msg.get_message_name(),
            SBP::MsgLinuxProcessFdCount(msg) => msg.get_message_name(),
            SBP::MsgLinuxProcessFdSummary(msg) => msg.get_message_name(),
            SBP::MsgLinuxCpuState(msg) => msg.get_message_name(),
            SBP::MsgLinuxMemState(msg) => msg.get_message_name(),
            SBP::MsgLinuxSysState(msg) => msg.get_message_name(),
            SBP::MsgStartup(msg) => msg.get_message_name(),
            SBP::MsgDgnssStatus(msg) => msg.get_message_name(),
            SBP::MsgInsStatus(msg) => msg.get_message_name(),
            SBP::MsgCsacTelemetry(msg) => msg.get_message_name(),
            SBP::MsgCsacTelemetryLabels(msg) => msg.get_message_name(),
            SBP::MsgInsUpdates(msg) => msg.get_message_name(),
            SBP::MsgGnssTimeOffset(msg) => msg.get_message_name(),
            SBP::MsgPpsTime(msg) => msg.get_message_name(),
            SBP::MsgGroupMeta(msg) => msg.get_message_name(),
            SBP::MsgSolnMeta(msg) => msg.get_message_name(),
            SBP::MsgSolnMetaDepA(msg) => msg.get_message_name(),
            SBP::MsgStatusReport(msg) => msg.get_message_name(),
            SBP::MsgHeartbeat(msg) => msg.get_message_name(),
            SBP::Unknown(msg) => msg.get_message_name(),
        }
    }

    fn get_message_type(&self) -> u16 {
        match self {
            SBP::MsgPrintDep(msg) => msg.get_message_type(),
            SBP::MsgTrackingStateDetailedDep(msg) => msg.get_message_type(),
            SBP::MsgTrackingStateDepB(msg) => msg.get_message_type(),
            SBP::MsgAcqResultDepB(msg) => msg.get_message_type(),
            SBP::MsgAcqResultDepA(msg) => msg.get_message_type(),
            SBP::MsgTrackingStateDepA(msg) => msg.get_message_type(),
            SBP::MsgThreadState(msg) => msg.get_message_type(),
            SBP::MsgUartStateDepa(msg) => msg.get_message_type(),
            SBP::MsgIarState(msg) => msg.get_message_type(),
            SBP::MsgEphemerisDepA(msg) => msg.get_message_type(),
            SBP::MsgMaskSatelliteDep(msg) => msg.get_message_type(),
            SBP::MsgTrackingIqDepA(msg) => msg.get_message_type(),
            SBP::MsgUartState(msg) => msg.get_message_type(),
            SBP::MsgAcqSvProfileDep(msg) => msg.get_message_type(),
            SBP::MsgAcqResultDepC(msg) => msg.get_message_type(),
            SBP::MsgTrackingStateDetailedDepA(msg) => msg.get_message_type(),
            SBP::MsgResetFilters(msg) => msg.get_message_type(),
            SBP::MsgInitBaseDep(msg) => msg.get_message_type(),
            SBP::MsgMaskSatellite(msg) => msg.get_message_type(),
            SBP::MsgTrackingIqDepB(msg) => msg.get_message_type(),
            SBP::MsgTrackingIq(msg) => msg.get_message_type(),
            SBP::MsgAcqSvProfile(msg) => msg.get_message_type(),
            SBP::MsgAcqResult(msg) => msg.get_message_type(),
            SBP::MsgTrackingState(msg) => msg.get_message_type(),
            SBP::MsgObsDepB(msg) => msg.get_message_type(),
            SBP::MsgBasePosLLH(msg) => msg.get_message_type(),
            SBP::MsgObsDepA(msg) => msg.get_message_type(),
            SBP::MsgEphemerisDepB(msg) => msg.get_message_type(),
            SBP::MsgEphemerisDepC(msg) => msg.get_message_type(),
            SBP::MsgBasePosECEF(msg) => msg.get_message_type(),
            SBP::MsgObsDepC(msg) => msg.get_message_type(),
            SBP::MsgObs(msg) => msg.get_message_type(),
            SBP::MsgSpecanDep(msg) => msg.get_message_type(),
            SBP::MsgSpecan(msg) => msg.get_message_type(),
            SBP::MsgMeasurementState(msg) => msg.get_message_type(),
            SBP::MsgSetTime(msg) => msg.get_message_type(),
            SBP::MsgAlmanac(msg) => msg.get_message_type(),
            SBP::MsgAlmanacGPSDep(msg) => msg.get_message_type(),
            SBP::MsgAlmanacGloDep(msg) => msg.get_message_type(),
            SBP::MsgAlmanacGPS(msg) => msg.get_message_type(),
            SBP::MsgAlmanacGlo(msg) => msg.get_message_type(),
            SBP::MsgGloBiases(msg) => msg.get_message_type(),
            SBP::MsgEphemerisDepD(msg) => msg.get_message_type(),
            SBP::MsgEphemerisGPSDepE(msg) => msg.get_message_type(),
            SBP::MsgEphemerisSbasDepA(msg) => msg.get_message_type(),
            SBP::MsgEphemerisGloDepA(msg) => msg.get_message_type(),
            SBP::MsgEphemerisSbasDepB(msg) => msg.get_message_type(),
            SBP::MsgEphemerisGloDepB(msg) => msg.get_message_type(),
            SBP::MsgEphemerisGPSDepF(msg) => msg.get_message_type(),
            SBP::MsgEphemerisGloDepC(msg) => msg.get_message_type(),
            SBP::MsgEphemerisGloDepD(msg) => msg.get_message_type(),
            SBP::MsgEphemerisBds(msg) => msg.get_message_type(),
            SBP::MsgEphemerisGPS(msg) => msg.get_message_type(),
            SBP::MsgEphemerisGlo(msg) => msg.get_message_type(),
            SBP::MsgEphemerisSbas(msg) => msg.get_message_type(),
            SBP::MsgEphemerisGal(msg) => msg.get_message_type(),
            SBP::MsgEphemerisQzss(msg) => msg.get_message_type(),
            SBP::MsgIono(msg) => msg.get_message_type(),
            SBP::MsgSvConfigurationGPSDep(msg) => msg.get_message_type(),
            SBP::MsgGroupDelayDepA(msg) => msg.get_message_type(),
            SBP::MsgGroupDelayDepB(msg) => msg.get_message_type(),
            SBP::MsgGroupDelay(msg) => msg.get_message_type(),
            SBP::MsgEphemerisGalDepA(msg) => msg.get_message_type(),
            SBP::MsgGnssCapb(msg) => msg.get_message_type(),
            SBP::MsgSvAzEl(msg) => msg.get_message_type(),
            SBP::MsgSettingsWrite(msg) => msg.get_message_type(),
            SBP::MsgSettingsSave(msg) => msg.get_message_type(),
            SBP::MsgSettingsReadByIndexReq(msg) => msg.get_message_type(),
            SBP::MsgFileioReadResp(msg) => msg.get_message_type(),
            SBP::MsgSettingsReadReq(msg) => msg.get_message_type(),
            SBP::MsgSettingsReadResp(msg) => msg.get_message_type(),
            SBP::MsgSettingsReadByIndexDone(msg) => msg.get_message_type(),
            SBP::MsgSettingsReadByIndexResp(msg) => msg.get_message_type(),
            SBP::MsgFileioReadReq(msg) => msg.get_message_type(),
            SBP::MsgFileioReadDirReq(msg) => msg.get_message_type(),
            SBP::MsgFileioReadDirResp(msg) => msg.get_message_type(),
            SBP::MsgFileioWriteResp(msg) => msg.get_message_type(),
            SBP::MsgFileioRemove(msg) => msg.get_message_type(),
            SBP::MsgFileioWriteReq(msg) => msg.get_message_type(),
            SBP::MsgSettingsRegister(msg) => msg.get_message_type(),
            SBP::MsgSettingsWriteResp(msg) => msg.get_message_type(),
            SBP::MsgBootloaderHandshakeDepA(msg) => msg.get_message_type(),
            SBP::MsgBootloaderJumpToApp(msg) => msg.get_message_type(),
            SBP::MsgResetDep(msg) => msg.get_message_type(),
            SBP::MsgBootloaderHandshakeReq(msg) => msg.get_message_type(),
            SBP::MsgBootloaderHandshakeResp(msg) => msg.get_message_type(),
            SBP::MsgDeviceMonitor(msg) => msg.get_message_type(),
            SBP::MsgReset(msg) => msg.get_message_type(),
            SBP::MsgCommandReq(msg) => msg.get_message_type(),
            SBP::MsgCommandResp(msg) => msg.get_message_type(),
            SBP::MsgNetworkStateReq(msg) => msg.get_message_type(),
            SBP::MsgNetworkStateResp(msg) => msg.get_message_type(),
            SBP::MsgCommandOutput(msg) => msg.get_message_type(),
            SBP::MsgNetworkBandwidthUsage(msg) => msg.get_message_type(),
            SBP::MsgCellModemStatus(msg) => msg.get_message_type(),
            SBP::MsgFrontEndGain(msg) => msg.get_message_type(),
            SBP::MsgCwResults(msg) => msg.get_message_type(),
            SBP::MsgCwStart(msg) => msg.get_message_type(),
            SBP::MsgNapDeviceDnaResp(msg) => msg.get_message_type(),
            SBP::MsgNapDeviceDnaReq(msg) => msg.get_message_type(),
            SBP::MsgFlashDone(msg) => msg.get_message_type(),
            SBP::MsgFlashReadResp(msg) => msg.get_message_type(),
            SBP::MsgFlashErase(msg) => msg.get_message_type(),
            SBP::MsgStmFlashLockSector(msg) => msg.get_message_type(),
            SBP::MsgStmFlashUnlockSector(msg) => msg.get_message_type(),
            SBP::MsgStmUniqueIdResp(msg) => msg.get_message_type(),
            SBP::MsgFlashProgram(msg) => msg.get_message_type(),
            SBP::MsgFlashReadReq(msg) => msg.get_message_type(),
            SBP::MsgStmUniqueIdReq(msg) => msg.get_message_type(),
            SBP::MsgM25FlashWriteStatus(msg) => msg.get_message_type(),
            SBP::MsgGPSTimeDepA(msg) => msg.get_message_type(),
            SBP::MsgExtEvent(msg) => msg.get_message_type(),
            SBP::MsgGPSTime(msg) => msg.get_message_type(),
            SBP::MsgUtcTime(msg) => msg.get_message_type(),
            SBP::MsgGPSTimeGnss(msg) => msg.get_message_type(),
            SBP::MsgUtcTimeGnss(msg) => msg.get_message_type(),
            SBP::MsgSettingsRegisterResp(msg) => msg.get_message_type(),
            SBP::MsgPosECEFDepA(msg) => msg.get_message_type(),
            SBP::MsgPosLLHDepA(msg) => msg.get_message_type(),
            SBP::MsgBaselineECEFDepA(msg) => msg.get_message_type(),
            SBP::MsgBaselineNEDDepA(msg) => msg.get_message_type(),
            SBP::MsgVelECEFDepA(msg) => msg.get_message_type(),
            SBP::MsgVelNEDDepA(msg) => msg.get_message_type(),
            SBP::MsgDopsDepA(msg) => msg.get_message_type(),
            SBP::MsgBaselineHeadingDepA(msg) => msg.get_message_type(),
            SBP::MsgDops(msg) => msg.get_message_type(),
            SBP::MsgPosECEF(msg) => msg.get_message_type(),
            SBP::MsgPosLLH(msg) => msg.get_message_type(),
            SBP::MsgBaselineECEF(msg) => msg.get_message_type(),
            SBP::MsgBaselineNED(msg) => msg.get_message_type(),
            SBP::MsgVelECEF(msg) => msg.get_message_type(),
            SBP::MsgVelNED(msg) => msg.get_message_type(),
            SBP::MsgBaselineHeading(msg) => msg.get_message_type(),
            SBP::MsgAgeCorrections(msg) => msg.get_message_type(),
            SBP::MsgPosLLHCov(msg) => msg.get_message_type(),
            SBP::MsgVelNEDCov(msg) => msg.get_message_type(),
            SBP::MsgVelBody(msg) => msg.get_message_type(),
            SBP::MsgPosECEFCov(msg) => msg.get_message_type(),
            SBP::MsgVelECEFCov(msg) => msg.get_message_type(),
            SBP::MsgProtectionLevelDepA(msg) => msg.get_message_type(),
            SBP::MsgProtectionLevel(msg) => msg.get_message_type(),
            SBP::MsgPosLLHAcc(msg) => msg.get_message_type(),
            SBP::MsgOrientQuat(msg) => msg.get_message_type(),
            SBP::MsgOrientEuler(msg) => msg.get_message_type(),
            SBP::MsgAngularRate(msg) => msg.get_message_type(),
            SBP::MsgPosECEFGnss(msg) => msg.get_message_type(),
            SBP::MsgPosLLHGnss(msg) => msg.get_message_type(),
            SBP::MsgVelECEFGnss(msg) => msg.get_message_type(),
            SBP::MsgVelNEDGnss(msg) => msg.get_message_type(),
            SBP::MsgPosLLHCovGnss(msg) => msg.get_message_type(),
            SBP::MsgVelNEDCovGnss(msg) => msg.get_message_type(),
            SBP::MsgPosECEFCovGnss(msg) => msg.get_message_type(),
            SBP::MsgVelECEFCovGnss(msg) => msg.get_message_type(),
            SBP::MsgNdbEvent(msg) => msg.get_message_type(),
            SBP::MsgLog(msg) => msg.get_message_type(),
            SBP::MsgFwd(msg) => msg.get_message_type(),
            SBP::MsgSsrOrbitClockDepA(msg) => msg.get_message_type(),
            SBP::MsgSsrOrbitClock(msg) => msg.get_message_type(),
            SBP::MsgSsrCodeBiases(msg) => msg.get_message_type(),
            SBP::MsgSsrPhaseBiases(msg) => msg.get_message_type(),
            SBP::MsgSsrStecCorrectionDepA(msg) => msg.get_message_type(),
            SBP::MsgSsrGriddedCorrectionNoStdDepA(msg) => msg.get_message_type(),
            SBP::MsgSsrGridDefinitionDepA(msg) => msg.get_message_type(),
            SBP::MsgSsrTileDefinition(msg) => msg.get_message_type(),
            SBP::MsgSsrGriddedCorrectionDepA(msg) => msg.get_message_type(),
            SBP::MsgSsrStecCorrection(msg) => msg.get_message_type(),
            SBP::MsgSsrGriddedCorrection(msg) => msg.get_message_type(),
            SBP::MsgSsrSatelliteApc(msg) => msg.get_message_type(),
            SBP::MsgOsr(msg) => msg.get_message_type(),
            SBP::MsgUserData(msg) => msg.get_message_type(),
            SBP::MsgImuRaw(msg) => msg.get_message_type(),
            SBP::MsgImuAux(msg) => msg.get_message_type(),
            SBP::MsgMagRaw(msg) => msg.get_message_type(),
            SBP::MsgOdometry(msg) => msg.get_message_type(),
            SBP::MsgWheeltick(msg) => msg.get_message_type(),
            SBP::MsgFileioConfigReq(msg) => msg.get_message_type(),
            SBP::MsgFileioConfigResp(msg) => msg.get_message_type(),
            SBP::MsgSbasRaw(msg) => msg.get_message_type(),
            SBP::MsgLinuxCpuStateDepA(msg) => msg.get_message_type(),
            SBP::MsgLinuxMemStateDepA(msg) => msg.get_message_type(),
            SBP::MsgLinuxSysStateDepA(msg) => msg.get_message_type(),
            SBP::MsgLinuxProcessSocketCounts(msg) => msg.get_message_type(),
            SBP::MsgLinuxProcessSocketQueues(msg) => msg.get_message_type(),
            SBP::MsgLinuxSocketUsage(msg) => msg.get_message_type(),
            SBP::MsgLinuxProcessFdCount(msg) => msg.get_message_type(),
            SBP::MsgLinuxProcessFdSummary(msg) => msg.get_message_type(),
            SBP::MsgLinuxCpuState(msg) => msg.get_message_type(),
            SBP::MsgLinuxMemState(msg) => msg.get_message_type(),
            SBP::MsgLinuxSysState(msg) => msg.get_message_type(),
            SBP::MsgStartup(msg) => msg.get_message_type(),
            SBP::MsgDgnssStatus(msg) => msg.get_message_type(),
            SBP::MsgInsStatus(msg) => msg.get_message_type(),
            SBP::MsgCsacTelemetry(msg) => msg.get_message_type(),
            SBP::MsgCsacTelemetryLabels(msg) => msg.get_message_type(),
            SBP::MsgInsUpdates(msg) => msg.get_message_type(),
            SBP::MsgGnssTimeOffset(msg) => msg.get_message_type(),
            SBP::MsgPpsTime(msg) => msg.get_message_type(),
            SBP::MsgGroupMeta(msg) => msg.get_message_type(),
            SBP::MsgSolnMeta(msg) => msg.get_message_type(),
            SBP::MsgSolnMetaDepA(msg) => msg.get_message_type(),
            SBP::MsgStatusReport(msg) => msg.get_message_type(),
            SBP::MsgHeartbeat(msg) => msg.get_message_type(),
            SBP::Unknown(msg) => msg.get_message_type(),
        }
    }

    fn get_sender_id(&self) -> Option<u16> {
        match self {
            SBP::MsgPrintDep(msg) => msg.get_sender_id(),
            SBP::MsgTrackingStateDetailedDep(msg) => msg.get_sender_id(),
            SBP::MsgTrackingStateDepB(msg) => msg.get_sender_id(),
            SBP::MsgAcqResultDepB(msg) => msg.get_sender_id(),
            SBP::MsgAcqResultDepA(msg) => msg.get_sender_id(),
            SBP::MsgTrackingStateDepA(msg) => msg.get_sender_id(),
            SBP::MsgThreadState(msg) => msg.get_sender_id(),
            SBP::MsgUartStateDepa(msg) => msg.get_sender_id(),
            SBP::MsgIarState(msg) => msg.get_sender_id(),
            SBP::MsgEphemerisDepA(msg) => msg.get_sender_id(),
            SBP::MsgMaskSatelliteDep(msg) => msg.get_sender_id(),
            SBP::MsgTrackingIqDepA(msg) => msg.get_sender_id(),
            SBP::MsgUartState(msg) => msg.get_sender_id(),
            SBP::MsgAcqSvProfileDep(msg) => msg.get_sender_id(),
            SBP::MsgAcqResultDepC(msg) => msg.get_sender_id(),
            SBP::MsgTrackingStateDetailedDepA(msg) => msg.get_sender_id(),
            SBP::MsgResetFilters(msg) => msg.get_sender_id(),
            SBP::MsgInitBaseDep(msg) => msg.get_sender_id(),
            SBP::MsgMaskSatellite(msg) => msg.get_sender_id(),
            SBP::MsgTrackingIqDepB(msg) => msg.get_sender_id(),
            SBP::MsgTrackingIq(msg) => msg.get_sender_id(),
            SBP::MsgAcqSvProfile(msg) => msg.get_sender_id(),
            SBP::MsgAcqResult(msg) => msg.get_sender_id(),
            SBP::MsgTrackingState(msg) => msg.get_sender_id(),
            SBP::MsgObsDepB(msg) => msg.get_sender_id(),
            SBP::MsgBasePosLLH(msg) => msg.get_sender_id(),
            SBP::MsgObsDepA(msg) => msg.get_sender_id(),
            SBP::MsgEphemerisDepB(msg) => msg.get_sender_id(),
            SBP::MsgEphemerisDepC(msg) => msg.get_sender_id(),
            SBP::MsgBasePosECEF(msg) => msg.get_sender_id(),
            SBP::MsgObsDepC(msg) => msg.get_sender_id(),
            SBP::MsgObs(msg) => msg.get_sender_id(),
            SBP::MsgSpecanDep(msg) => msg.get_sender_id(),
            SBP::MsgSpecan(msg) => msg.get_sender_id(),
            SBP::MsgMeasurementState(msg) => msg.get_sender_id(),
            SBP::MsgSetTime(msg) => msg.get_sender_id(),
            SBP::MsgAlmanac(msg) => msg.get_sender_id(),
            SBP::MsgAlmanacGPSDep(msg) => msg.get_sender_id(),
            SBP::MsgAlmanacGloDep(msg) => msg.get_sender_id(),
            SBP::MsgAlmanacGPS(msg) => msg.get_sender_id(),
            SBP::MsgAlmanacGlo(msg) => msg.get_sender_id(),
            SBP::MsgGloBiases(msg) => msg.get_sender_id(),
            SBP::MsgEphemerisDepD(msg) => msg.get_sender_id(),
            SBP::MsgEphemerisGPSDepE(msg) => msg.get_sender_id(),
            SBP::MsgEphemerisSbasDepA(msg) => msg.get_sender_id(),
            SBP::MsgEphemerisGloDepA(msg) => msg.get_sender_id(),
            SBP::MsgEphemerisSbasDepB(msg) => msg.get_sender_id(),
            SBP::MsgEphemerisGloDepB(msg) => msg.get_sender_id(),
            SBP::MsgEphemerisGPSDepF(msg) => msg.get_sender_id(),
            SBP::MsgEphemerisGloDepC(msg) => msg.get_sender_id(),
            SBP::MsgEphemerisGloDepD(msg) => msg.get_sender_id(),
            SBP::MsgEphemerisBds(msg) => msg.get_sender_id(),
            SBP::MsgEphemerisGPS(msg) => msg.get_sender_id(),
            SBP::MsgEphemerisGlo(msg) => msg.get_sender_id(),
            SBP::MsgEphemerisSbas(msg) => msg.get_sender_id(),
            SBP::MsgEphemerisGal(msg) => msg.get_sender_id(),
            SBP::MsgEphemerisQzss(msg) => msg.get_sender_id(),
            SBP::MsgIono(msg) => msg.get_sender_id(),
            SBP::MsgSvConfigurationGPSDep(msg) => msg.get_sender_id(),
            SBP::MsgGroupDelayDepA(msg) => msg.get_sender_id(),
            SBP::MsgGroupDelayDepB(msg) => msg.get_sender_id(),
            SBP::MsgGroupDelay(msg) => msg.get_sender_id(),
            SBP::MsgEphemerisGalDepA(msg) => msg.get_sender_id(),
            SBP::MsgGnssCapb(msg) => msg.get_sender_id(),
            SBP::MsgSvAzEl(msg) => msg.get_sender_id(),
            SBP::MsgSettingsWrite(msg) => msg.get_sender_id(),
            SBP::MsgSettingsSave(msg) => msg.get_sender_id(),
            SBP::MsgSettingsReadByIndexReq(msg) => msg.get_sender_id(),
            SBP::MsgFileioReadResp(msg) => msg.get_sender_id(),
            SBP::MsgSettingsReadReq(msg) => msg.get_sender_id(),
            SBP::MsgSettingsReadResp(msg) => msg.get_sender_id(),
            SBP::MsgSettingsReadByIndexDone(msg) => msg.get_sender_id(),
            SBP::MsgSettingsReadByIndexResp(msg) => msg.get_sender_id(),
            SBP::MsgFileioReadReq(msg) => msg.get_sender_id(),
            SBP::MsgFileioReadDirReq(msg) => msg.get_sender_id(),
            SBP::MsgFileioReadDirResp(msg) => msg.get_sender_id(),
            SBP::MsgFileioWriteResp(msg) => msg.get_sender_id(),
            SBP::MsgFileioRemove(msg) => msg.get_sender_id(),
            SBP::MsgFileioWriteReq(msg) => msg.get_sender_id(),
            SBP::MsgSettingsRegister(msg) => msg.get_sender_id(),
            SBP::MsgSettingsWriteResp(msg) => msg.get_sender_id(),
            SBP::MsgBootloaderHandshakeDepA(msg) => msg.get_sender_id(),
            SBP::MsgBootloaderJumpToApp(msg) => msg.get_sender_id(),
            SBP::MsgResetDep(msg) => msg.get_sender_id(),
            SBP::MsgBootloaderHandshakeReq(msg) => msg.get_sender_id(),
            SBP::MsgBootloaderHandshakeResp(msg) => msg.get_sender_id(),
            SBP::MsgDeviceMonitor(msg) => msg.get_sender_id(),
            SBP::MsgReset(msg) => msg.get_sender_id(),
            SBP::MsgCommandReq(msg) => msg.get_sender_id(),
            SBP::MsgCommandResp(msg) => msg.get_sender_id(),
            SBP::MsgNetworkStateReq(msg) => msg.get_sender_id(),
            SBP::MsgNetworkStateResp(msg) => msg.get_sender_id(),
            SBP::MsgCommandOutput(msg) => msg.get_sender_id(),
            SBP::MsgNetworkBandwidthUsage(msg) => msg.get_sender_id(),
            SBP::MsgCellModemStatus(msg) => msg.get_sender_id(),
            SBP::MsgFrontEndGain(msg) => msg.get_sender_id(),
            SBP::MsgCwResults(msg) => msg.get_sender_id(),
            SBP::MsgCwStart(msg) => msg.get_sender_id(),
            SBP::MsgNapDeviceDnaResp(msg) => msg.get_sender_id(),
            SBP::MsgNapDeviceDnaReq(msg) => msg.get_sender_id(),
            SBP::MsgFlashDone(msg) => msg.get_sender_id(),
            SBP::MsgFlashReadResp(msg) => msg.get_sender_id(),
            SBP::MsgFlashErase(msg) => msg.get_sender_id(),
            SBP::MsgStmFlashLockSector(msg) => msg.get_sender_id(),
            SBP::MsgStmFlashUnlockSector(msg) => msg.get_sender_id(),
            SBP::MsgStmUniqueIdResp(msg) => msg.get_sender_id(),
            SBP::MsgFlashProgram(msg) => msg.get_sender_id(),
            SBP::MsgFlashReadReq(msg) => msg.get_sender_id(),
            SBP::MsgStmUniqueIdReq(msg) => msg.get_sender_id(),
            SBP::MsgM25FlashWriteStatus(msg) => msg.get_sender_id(),
            SBP::MsgGPSTimeDepA(msg) => msg.get_sender_id(),
            SBP::MsgExtEvent(msg) => msg.get_sender_id(),
            SBP::MsgGPSTime(msg) => msg.get_sender_id(),
            SBP::MsgUtcTime(msg) => msg.get_sender_id(),
            SBP::MsgGPSTimeGnss(msg) => msg.get_sender_id(),
            SBP::MsgUtcTimeGnss(msg) => msg.get_sender_id(),
            SBP::MsgSettingsRegisterResp(msg) => msg.get_sender_id(),
            SBP::MsgPosECEFDepA(msg) => msg.get_sender_id(),
            SBP::MsgPosLLHDepA(msg) => msg.get_sender_id(),
            SBP::MsgBaselineECEFDepA(msg) => msg.get_sender_id(),
            SBP::MsgBaselineNEDDepA(msg) => msg.get_sender_id(),
            SBP::MsgVelECEFDepA(msg) => msg.get_sender_id(),
            SBP::MsgVelNEDDepA(msg) => msg.get_sender_id(),
            SBP::MsgDopsDepA(msg) => msg.get_sender_id(),
            SBP::MsgBaselineHeadingDepA(msg) => msg.get_sender_id(),
            SBP::MsgDops(msg) => msg.get_sender_id(),
            SBP::MsgPosECEF(msg) => msg.get_sender_id(),
            SBP::MsgPosLLH(msg) => msg.get_sender_id(),
            SBP::MsgBaselineECEF(msg) => msg.get_sender_id(),
            SBP::MsgBaselineNED(msg) => msg.get_sender_id(),
            SBP::MsgVelECEF(msg) => msg.get_sender_id(),
            SBP::MsgVelNED(msg) => msg.get_sender_id(),
            SBP::MsgBaselineHeading(msg) => msg.get_sender_id(),
            SBP::MsgAgeCorrections(msg) => msg.get_sender_id(),
            SBP::MsgPosLLHCov(msg) => msg.get_sender_id(),
            SBP::MsgVelNEDCov(msg) => msg.get_sender_id(),
            SBP::MsgVelBody(msg) => msg.get_sender_id(),
            SBP::MsgPosECEFCov(msg) => msg.get_sender_id(),
            SBP::MsgVelECEFCov(msg) => msg.get_sender_id(),
            SBP::MsgProtectionLevelDepA(msg) => msg.get_sender_id(),
            SBP::MsgProtectionLevel(msg) => msg.get_sender_id(),
            SBP::MsgPosLLHAcc(msg) => msg.get_sender_id(),
            SBP::MsgOrientQuat(msg) => msg.get_sender_id(),
            SBP::MsgOrientEuler(msg) => msg.get_sender_id(),
            SBP::MsgAngularRate(msg) => msg.get_sender_id(),
            SBP::MsgPosECEFGnss(msg) => msg.get_sender_id(),
            SBP::MsgPosLLHGnss(msg) => msg.get_sender_id(),
            SBP::MsgVelECEFGnss(msg) => msg.get_sender_id(),
            SBP::MsgVelNEDGnss(msg) => msg.get_sender_id(),
            SBP::MsgPosLLHCovGnss(msg) => msg.get_sender_id(),
            SBP::MsgVelNEDCovGnss(msg) => msg.get_sender_id(),
            SBP::MsgPosECEFCovGnss(msg) => msg.get_sender_id(),
            SBP::MsgVelECEFCovGnss(msg) => msg.get_sender_id(),
            SBP::MsgNdbEvent(msg) => msg.get_sender_id(),
            SBP::MsgLog(msg) => msg.get_sender_id(),
            SBP::MsgFwd(msg) => msg.get_sender_id(),
            SBP::MsgSsrOrbitClockDepA(msg) => msg.get_sender_id(),
            SBP::MsgSsrOrbitClock(msg) => msg.get_sender_id(),
            SBP::MsgSsrCodeBiases(msg) => msg.get_sender_id(),
            SBP::MsgSsrPhaseBiases(msg) => msg.get_sender_id(),
            SBP::MsgSsrStecCorrectionDepA(msg) => msg.get_sender_id(),
            SBP::MsgSsrGriddedCorrectionNoStdDepA(msg) => msg.get_sender_id(),
            SBP::MsgSsrGridDefinitionDepA(msg) => msg.get_sender_id(),
            SBP::MsgSsrTileDefinition(msg) => msg.get_sender_id(),
            SBP::MsgSsrGriddedCorrectionDepA(msg) => msg.get_sender_id(),
            SBP::MsgSsrStecCorrection(msg) => msg.get_sender_id(),
            SBP::MsgSsrGriddedCorrection(msg) => msg.get_sender_id(),
            SBP::MsgSsrSatelliteApc(msg) => msg.get_sender_id(),
            SBP::MsgOsr(msg) => msg.get_sender_id(),
            SBP::MsgUserData(msg) => msg.get_sender_id(),
            SBP::MsgImuRaw(msg) => msg.get_sender_id(),
            SBP::MsgImuAux(msg) => msg.get_sender_id(),
            SBP::MsgMagRaw(msg) => msg.get_sender_id(),
            SBP::MsgOdometry(msg) => msg.get_sender_id(),
            SBP::MsgWheeltick(msg) => msg.get_sender_id(),
            SBP::MsgFileioConfigReq(msg) => msg.get_sender_id(),
            SBP::MsgFileioConfigResp(msg) => msg.get_sender_id(),
            SBP::MsgSbasRaw(msg) => msg.get_sender_id(),
            SBP::MsgLinuxCpuStateDepA(msg) => msg.get_sender_id(),
            SBP::MsgLinuxMemStateDepA(msg) => msg.get_sender_id(),
            SBP::MsgLinuxSysStateDepA(msg) => msg.get_sender_id(),
            SBP::MsgLinuxProcessSocketCounts(msg) => msg.get_sender_id(),
            SBP::MsgLinuxProcessSocketQueues(msg) => msg.get_sender_id(),
            SBP::MsgLinuxSocketUsage(msg) => msg.get_sender_id(),
            SBP::MsgLinuxProcessFdCount(msg) => msg.get_sender_id(),
            SBP::MsgLinuxProcessFdSummary(msg) => msg.get_sender_id(),
            SBP::MsgLinuxCpuState(msg) => msg.get_sender_id(),
            SBP::MsgLinuxMemState(msg) => msg.get_sender_id(),
            SBP::MsgLinuxSysState(msg) => msg.get_sender_id(),
            SBP::MsgStartup(msg) => msg.get_sender_id(),
            SBP::MsgDgnssStatus(msg) => msg.get_sender_id(),
            SBP::MsgInsStatus(msg) => msg.get_sender_id(),
            SBP::MsgCsacTelemetry(msg) => msg.get_sender_id(),
            SBP::MsgCsacTelemetryLabels(msg) => msg.get_sender_id(),
            SBP::MsgInsUpdates(msg) => msg.get_sender_id(),
            SBP::MsgGnssTimeOffset(msg) => msg.get_sender_id(),
            SBP::MsgPpsTime(msg) => msg.get_sender_id(),
            SBP::MsgGroupMeta(msg) => msg.get_sender_id(),
            SBP::MsgSolnMeta(msg) => msg.get_sender_id(),
            SBP::MsgSolnMetaDepA(msg) => msg.get_sender_id(),
            SBP::MsgStatusReport(msg) => msg.get_sender_id(),
            SBP::MsgHeartbeat(msg) => msg.get_sender_id(),
            SBP::Unknown(msg) => msg.get_sender_id(),
        }
    }

    fn set_sender_id(&mut self, new_id: u16) {
        match self {
            SBP::MsgPrintDep(msg) => msg.set_sender_id(new_id),
            SBP::MsgTrackingStateDetailedDep(msg) => msg.set_sender_id(new_id),
            SBP::MsgTrackingStateDepB(msg) => msg.set_sender_id(new_id),
            SBP::MsgAcqResultDepB(msg) => msg.set_sender_id(new_id),
            SBP::MsgAcqResultDepA(msg) => msg.set_sender_id(new_id),
            SBP::MsgTrackingStateDepA(msg) => msg.set_sender_id(new_id),
            SBP::MsgThreadState(msg) => msg.set_sender_id(new_id),
            SBP::MsgUartStateDepa(msg) => msg.set_sender_id(new_id),
            SBP::MsgIarState(msg) => msg.set_sender_id(new_id),
            SBP::MsgEphemerisDepA(msg) => msg.set_sender_id(new_id),
            SBP::MsgMaskSatelliteDep(msg) => msg.set_sender_id(new_id),
            SBP::MsgTrackingIqDepA(msg) => msg.set_sender_id(new_id),
            SBP::MsgUartState(msg) => msg.set_sender_id(new_id),
            SBP::MsgAcqSvProfileDep(msg) => msg.set_sender_id(new_id),
            SBP::MsgAcqResultDepC(msg) => msg.set_sender_id(new_id),
            SBP::MsgTrackingStateDetailedDepA(msg) => msg.set_sender_id(new_id),
            SBP::MsgResetFilters(msg) => msg.set_sender_id(new_id),
            SBP::MsgInitBaseDep(msg) => msg.set_sender_id(new_id),
            SBP::MsgMaskSatellite(msg) => msg.set_sender_id(new_id),
            SBP::MsgTrackingIqDepB(msg) => msg.set_sender_id(new_id),
            SBP::MsgTrackingIq(msg) => msg.set_sender_id(new_id),
            SBP::MsgAcqSvProfile(msg) => msg.set_sender_id(new_id),
            SBP::MsgAcqResult(msg) => msg.set_sender_id(new_id),
            SBP::MsgTrackingState(msg) => msg.set_sender_id(new_id),
            SBP::MsgObsDepB(msg) => msg.set_sender_id(new_id),
            SBP::MsgBasePosLLH(msg) => msg.set_sender_id(new_id),
            SBP::MsgObsDepA(msg) => msg.set_sender_id(new_id),
            SBP::MsgEphemerisDepB(msg) => msg.set_sender_id(new_id),
            SBP::MsgEphemerisDepC(msg) => msg.set_sender_id(new_id),
            SBP::MsgBasePosECEF(msg) => msg.set_sender_id(new_id),
            SBP::MsgObsDepC(msg) => msg.set_sender_id(new_id),
            SBP::MsgObs(msg) => msg.set_sender_id(new_id),
            SBP::MsgSpecanDep(msg) => msg.set_sender_id(new_id),
            SBP::MsgSpecan(msg) => msg.set_sender_id(new_id),
            SBP::MsgMeasurementState(msg) => msg.set_sender_id(new_id),
            SBP::MsgSetTime(msg) => msg.set_sender_id(new_id),
            SBP::MsgAlmanac(msg) => msg.set_sender_id(new_id),
            SBP::MsgAlmanacGPSDep(msg) => msg.set_sender_id(new_id),
            SBP::MsgAlmanacGloDep(msg) => msg.set_sender_id(new_id),
            SBP::MsgAlmanacGPS(msg) => msg.set_sender_id(new_id),
            SBP::MsgAlmanacGlo(msg) => msg.set_sender_id(new_id),
            SBP::MsgGloBiases(msg) => msg.set_sender_id(new_id),
            SBP::MsgEphemerisDepD(msg) => msg.set_sender_id(new_id),
            SBP::MsgEphemerisGPSDepE(msg) => msg.set_sender_id(new_id),
            SBP::MsgEphemerisSbasDepA(msg) => msg.set_sender_id(new_id),
            SBP::MsgEphemerisGloDepA(msg) => msg.set_sender_id(new_id),
            SBP::MsgEphemerisSbasDepB(msg) => msg.set_sender_id(new_id),
            SBP::MsgEphemerisGloDepB(msg) => msg.set_sender_id(new_id),
            SBP::MsgEphemerisGPSDepF(msg) => msg.set_sender_id(new_id),
            SBP::MsgEphemerisGloDepC(msg) => msg.set_sender_id(new_id),
            SBP::MsgEphemerisGloDepD(msg) => msg.set_sender_id(new_id),
            SBP::MsgEphemerisBds(msg) => msg.set_sender_id(new_id),
            SBP::MsgEphemerisGPS(msg) => msg.set_sender_id(new_id),
            SBP::MsgEphemerisGlo(msg) => msg.set_sender_id(new_id),
            SBP::MsgEphemerisSbas(msg) => msg.set_sender_id(new_id),
            SBP::MsgEphemerisGal(msg) => msg.set_sender_id(new_id),
            SBP::MsgEphemerisQzss(msg) => msg.set_sender_id(new_id),
            SBP::MsgIono(msg) => msg.set_sender_id(new_id),
            SBP::MsgSvConfigurationGPSDep(msg) => msg.set_sender_id(new_id),
            SBP::MsgGroupDelayDepA(msg) => msg.set_sender_id(new_id),
            SBP::MsgGroupDelayDepB(msg) => msg.set_sender_id(new_id),
            SBP::MsgGroupDelay(msg) => msg.set_sender_id(new_id),
            SBP::MsgEphemerisGalDepA(msg) => msg.set_sender_id(new_id),
            SBP::MsgGnssCapb(msg) => msg.set_sender_id(new_id),
            SBP::MsgSvAzEl(msg) => msg.set_sender_id(new_id),
            SBP::MsgSettingsWrite(msg) => msg.set_sender_id(new_id),
            SBP::MsgSettingsSave(msg) => msg.set_sender_id(new_id),
            SBP::MsgSettingsReadByIndexReq(msg) => msg.set_sender_id(new_id),
            SBP::MsgFileioReadResp(msg) => msg.set_sender_id(new_id),
            SBP::MsgSettingsReadReq(msg) => msg.set_sender_id(new_id),
            SBP::MsgSettingsReadResp(msg) => msg.set_sender_id(new_id),
            SBP::MsgSettingsReadByIndexDone(msg) => msg.set_sender_id(new_id),
            SBP::MsgSettingsReadByIndexResp(msg) => msg.set_sender_id(new_id),
            SBP::MsgFileioReadReq(msg) => msg.set_sender_id(new_id),
            SBP::MsgFileioReadDirReq(msg) => msg.set_sender_id(new_id),
            SBP::MsgFileioReadDirResp(msg) => msg.set_sender_id(new_id),
            SBP::MsgFileioWriteResp(msg) => msg.set_sender_id(new_id),
            SBP::MsgFileioRemove(msg) => msg.set_sender_id(new_id),
            SBP::MsgFileioWriteReq(msg) => msg.set_sender_id(new_id),
            SBP::MsgSettingsRegister(msg) => msg.set_sender_id(new_id),
            SBP::MsgSettingsWriteResp(msg) => msg.set_sender_id(new_id),
            SBP::MsgBootloaderHandshakeDepA(msg) => msg.set_sender_id(new_id),
            SBP::MsgBootloaderJumpToApp(msg) => msg.set_sender_id(new_id),
            SBP::MsgResetDep(msg) => msg.set_sender_id(new_id),
            SBP::MsgBootloaderHandshakeReq(msg) => msg.set_sender_id(new_id),
            SBP::MsgBootloaderHandshakeResp(msg) => msg.set_sender_id(new_id),
            SBP::MsgDeviceMonitor(msg) => msg.set_sender_id(new_id),
            SBP::MsgReset(msg) => msg.set_sender_id(new_id),
            SBP::MsgCommandReq(msg) => msg.set_sender_id(new_id),
            SBP::MsgCommandResp(msg) => msg.set_sender_id(new_id),
            SBP::MsgNetworkStateReq(msg) => msg.set_sender_id(new_id),
            SBP::MsgNetworkStateResp(msg) => msg.set_sender_id(new_id),
            SBP::MsgCommandOutput(msg) => msg.set_sender_id(new_id),
            SBP::MsgNetworkBandwidthUsage(msg) => msg.set_sender_id(new_id),
            SBP::MsgCellModemStatus(msg) => msg.set_sender_id(new_id),
            SBP::MsgFrontEndGain(msg) => msg.set_sender_id(new_id),
            SBP::MsgCwResults(msg) => msg.set_sender_id(new_id),
            SBP::MsgCwStart(msg) => msg.set_sender_id(new_id),
            SBP::MsgNapDeviceDnaResp(msg) => msg.set_sender_id(new_id),
            SBP::MsgNapDeviceDnaReq(msg) => msg.set_sender_id(new_id),
            SBP::MsgFlashDone(msg) => msg.set_sender_id(new_id),
            SBP::MsgFlashReadResp(msg) => msg.set_sender_id(new_id),
            SBP::MsgFlashErase(msg) => msg.set_sender_id(new_id),
            SBP::MsgStmFlashLockSector(msg) => msg.set_sender_id(new_id),
            SBP::MsgStmFlashUnlockSector(msg) => msg.set_sender_id(new_id),
            SBP::MsgStmUniqueIdResp(msg) => msg.set_sender_id(new_id),
            SBP::MsgFlashProgram(msg) => msg.set_sender_id(new_id),
            SBP::MsgFlashReadReq(msg) => msg.set_sender_id(new_id),
            SBP::MsgStmUniqueIdReq(msg) => msg.set_sender_id(new_id),
            SBP::MsgM25FlashWriteStatus(msg) => msg.set_sender_id(new_id),
            SBP::MsgGPSTimeDepA(msg) => msg.set_sender_id(new_id),
            SBP::MsgExtEvent(msg) => msg.set_sender_id(new_id),
            SBP::MsgGPSTime(msg) => msg.set_sender_id(new_id),
            SBP::MsgUtcTime(msg) => msg.set_sender_id(new_id),
            SBP::MsgGPSTimeGnss(msg) => msg.set_sender_id(new_id),
            SBP::MsgUtcTimeGnss(msg) => msg.set_sender_id(new_id),
            SBP::MsgSettingsRegisterResp(msg) => msg.set_sender_id(new_id),
            SBP::MsgPosECEFDepA(msg) => msg.set_sender_id(new_id),
            SBP::MsgPosLLHDepA(msg) => msg.set_sender_id(new_id),
            SBP::MsgBaselineECEFDepA(msg) => msg.set_sender_id(new_id),
            SBP::MsgBaselineNEDDepA(msg) => msg.set_sender_id(new_id),
            SBP::MsgVelECEFDepA(msg) => msg.set_sender_id(new_id),
            SBP::MsgVelNEDDepA(msg) => msg.set_sender_id(new_id),
            SBP::MsgDopsDepA(msg) => msg.set_sender_id(new_id),
            SBP::MsgBaselineHeadingDepA(msg) => msg.set_sender_id(new_id),
            SBP::MsgDops(msg) => msg.set_sender_id(new_id),
            SBP::MsgPosECEF(msg) => msg.set_sender_id(new_id),
            SBP::MsgPosLLH(msg) => msg.set_sender_id(new_id),
            SBP::MsgBaselineECEF(msg) => msg.set_sender_id(new_id),
            SBP::MsgBaselineNED(msg) => msg.set_sender_id(new_id),
            SBP::MsgVelECEF(msg) => msg.set_sender_id(new_id),
            SBP::MsgVelNED(msg) => msg.set_sender_id(new_id),
            SBP::MsgBaselineHeading(msg) => msg.set_sender_id(new_id),
            SBP::MsgAgeCorrections(msg) => msg.set_sender_id(new_id),
            SBP::MsgPosLLHCov(msg) => msg.set_sender_id(new_id),
            SBP::MsgVelNEDCov(msg) => msg.set_sender_id(new_id),
            SBP::MsgVelBody(msg) => msg.set_sender_id(new_id),
            SBP::MsgPosECEFCov(msg) => msg.set_sender_id(new_id),
            SBP::MsgVelECEFCov(msg) => msg.set_sender_id(new_id),
            SBP::MsgProtectionLevelDepA(msg) => msg.set_sender_id(new_id),
            SBP::MsgProtectionLevel(msg) => msg.set_sender_id(new_id),
            SBP::MsgPosLLHAcc(msg) => msg.set_sender_id(new_id),
            SBP::MsgOrientQuat(msg) => msg.set_sender_id(new_id),
            SBP::MsgOrientEuler(msg) => msg.set_sender_id(new_id),
            SBP::MsgAngularRate(msg) => msg.set_sender_id(new_id),
            SBP::MsgPosECEFGnss(msg) => msg.set_sender_id(new_id),
            SBP::MsgPosLLHGnss(msg) => msg.set_sender_id(new_id),
            SBP::MsgVelECEFGnss(msg) => msg.set_sender_id(new_id),
            SBP::MsgVelNEDGnss(msg) => msg.set_sender_id(new_id),
            SBP::MsgPosLLHCovGnss(msg) => msg.set_sender_id(new_id),
            SBP::MsgVelNEDCovGnss(msg) => msg.set_sender_id(new_id),
            SBP::MsgPosECEFCovGnss(msg) => msg.set_sender_id(new_id),
            SBP::MsgVelECEFCovGnss(msg) => msg.set_sender_id(new_id),
            SBP::MsgNdbEvent(msg) => msg.set_sender_id(new_id),
            SBP::MsgLog(msg) => msg.set_sender_id(new_id),
            SBP::MsgFwd(msg) => msg.set_sender_id(new_id),
            SBP::MsgSsrOrbitClockDepA(msg) => msg.set_sender_id(new_id),
            SBP::MsgSsrOrbitClock(msg) => msg.set_sender_id(new_id),
            SBP::MsgSsrCodeBiases(msg) => msg.set_sender_id(new_id),
            SBP::MsgSsrPhaseBiases(msg) => msg.set_sender_id(new_id),
            SBP::MsgSsrStecCorrectionDepA(msg) => msg.set_sender_id(new_id),
            SBP::MsgSsrGriddedCorrectionNoStdDepA(msg) => msg.set_sender_id(new_id),
            SBP::MsgSsrGridDefinitionDepA(msg) => msg.set_sender_id(new_id),
            SBP::MsgSsrTileDefinition(msg) => msg.set_sender_id(new_id),
            SBP::MsgSsrGriddedCorrectionDepA(msg) => msg.set_sender_id(new_id),
            SBP::MsgSsrStecCorrection(msg) => msg.set_sender_id(new_id),
            SBP::MsgSsrGriddedCorrection(msg) => msg.set_sender_id(new_id),
            SBP::MsgSsrSatelliteApc(msg) => msg.set_sender_id(new_id),
            SBP::MsgOsr(msg) => msg.set_sender_id(new_id),
            SBP::MsgUserData(msg) => msg.set_sender_id(new_id),
            SBP::MsgImuRaw(msg) => msg.set_sender_id(new_id),
            SBP::MsgImuAux(msg) => msg.set_sender_id(new_id),
            SBP::MsgMagRaw(msg) => msg.set_sender_id(new_id),
            SBP::MsgOdometry(msg) => msg.set_sender_id(new_id),
            SBP::MsgWheeltick(msg) => msg.set_sender_id(new_id),
            SBP::MsgFileioConfigReq(msg) => msg.set_sender_id(new_id),
            SBP::MsgFileioConfigResp(msg) => msg.set_sender_id(new_id),
            SBP::MsgSbasRaw(msg) => msg.set_sender_id(new_id),
            SBP::MsgLinuxCpuStateDepA(msg) => msg.set_sender_id(new_id),
            SBP::MsgLinuxMemStateDepA(msg) => msg.set_sender_id(new_id),
            SBP::MsgLinuxSysStateDepA(msg) => msg.set_sender_id(new_id),
            SBP::MsgLinuxProcessSocketCounts(msg) => msg.set_sender_id(new_id),
            SBP::MsgLinuxProcessSocketQueues(msg) => msg.set_sender_id(new_id),
            SBP::MsgLinuxSocketUsage(msg) => msg.set_sender_id(new_id),
            SBP::MsgLinuxProcessFdCount(msg) => msg.set_sender_id(new_id),
            SBP::MsgLinuxProcessFdSummary(msg) => msg.set_sender_id(new_id),
            SBP::MsgLinuxCpuState(msg) => msg.set_sender_id(new_id),
            SBP::MsgLinuxMemState(msg) => msg.set_sender_id(new_id),
            SBP::MsgLinuxSysState(msg) => msg.set_sender_id(new_id),
            SBP::MsgStartup(msg) => msg.set_sender_id(new_id),
            SBP::MsgDgnssStatus(msg) => msg.set_sender_id(new_id),
            SBP::MsgInsStatus(msg) => msg.set_sender_id(new_id),
            SBP::MsgCsacTelemetry(msg) => msg.set_sender_id(new_id),
            SBP::MsgCsacTelemetryLabels(msg) => msg.set_sender_id(new_id),
            SBP::MsgInsUpdates(msg) => msg.set_sender_id(new_id),
            SBP::MsgGnssTimeOffset(msg) => msg.set_sender_id(new_id),
            SBP::MsgPpsTime(msg) => msg.set_sender_id(new_id),
            SBP::MsgGroupMeta(msg) => msg.set_sender_id(new_id),
            SBP::MsgSolnMeta(msg) => msg.set_sender_id(new_id),
            SBP::MsgSolnMetaDepA(msg) => msg.set_sender_id(new_id),
            SBP::MsgStatusReport(msg) => msg.set_sender_id(new_id),
            SBP::MsgHeartbeat(msg) => msg.set_sender_id(new_id),
            SBP::Unknown(msg) => msg.set_sender_id(new_id),
        }
    }

    fn to_frame(&self) -> Result<Vec<u8>, crate::FramerError> {
        match self {
            SBP::MsgPrintDep(msg) => msg.to_frame(),
            SBP::MsgTrackingStateDetailedDep(msg) => msg.to_frame(),
            SBP::MsgTrackingStateDepB(msg) => msg.to_frame(),
            SBP::MsgAcqResultDepB(msg) => msg.to_frame(),
            SBP::MsgAcqResultDepA(msg) => msg.to_frame(),
            SBP::MsgTrackingStateDepA(msg) => msg.to_frame(),
            SBP::MsgThreadState(msg) => msg.to_frame(),
            SBP::MsgUartStateDepa(msg) => msg.to_frame(),
            SBP::MsgIarState(msg) => msg.to_frame(),
            SBP::MsgEphemerisDepA(msg) => msg.to_frame(),
            SBP::MsgMaskSatelliteDep(msg) => msg.to_frame(),
            SBP::MsgTrackingIqDepA(msg) => msg.to_frame(),
            SBP::MsgUartState(msg) => msg.to_frame(),
            SBP::MsgAcqSvProfileDep(msg) => msg.to_frame(),
            SBP::MsgAcqResultDepC(msg) => msg.to_frame(),
            SBP::MsgTrackingStateDetailedDepA(msg) => msg.to_frame(),
            SBP::MsgResetFilters(msg) => msg.to_frame(),
            SBP::MsgInitBaseDep(msg) => msg.to_frame(),
            SBP::MsgMaskSatellite(msg) => msg.to_frame(),
            SBP::MsgTrackingIqDepB(msg) => msg.to_frame(),
            SBP::MsgTrackingIq(msg) => msg.to_frame(),
            SBP::MsgAcqSvProfile(msg) => msg.to_frame(),
            SBP::MsgAcqResult(msg) => msg.to_frame(),
            SBP::MsgTrackingState(msg) => msg.to_frame(),
            SBP::MsgObsDepB(msg) => msg.to_frame(),
            SBP::MsgBasePosLLH(msg) => msg.to_frame(),
            SBP::MsgObsDepA(msg) => msg.to_frame(),
            SBP::MsgEphemerisDepB(msg) => msg.to_frame(),
            SBP::MsgEphemerisDepC(msg) => msg.to_frame(),
            SBP::MsgBasePosECEF(msg) => msg.to_frame(),
            SBP::MsgObsDepC(msg) => msg.to_frame(),
            SBP::MsgObs(msg) => msg.to_frame(),
            SBP::MsgSpecanDep(msg) => msg.to_frame(),
            SBP::MsgSpecan(msg) => msg.to_frame(),
            SBP::MsgMeasurementState(msg) => msg.to_frame(),
            SBP::MsgSetTime(msg) => msg.to_frame(),
            SBP::MsgAlmanac(msg) => msg.to_frame(),
            SBP::MsgAlmanacGPSDep(msg) => msg.to_frame(),
            SBP::MsgAlmanacGloDep(msg) => msg.to_frame(),
            SBP::MsgAlmanacGPS(msg) => msg.to_frame(),
            SBP::MsgAlmanacGlo(msg) => msg.to_frame(),
            SBP::MsgGloBiases(msg) => msg.to_frame(),
            SBP::MsgEphemerisDepD(msg) => msg.to_frame(),
            SBP::MsgEphemerisGPSDepE(msg) => msg.to_frame(),
            SBP::MsgEphemerisSbasDepA(msg) => msg.to_frame(),
            SBP::MsgEphemerisGloDepA(msg) => msg.to_frame(),
            SBP::MsgEphemerisSbasDepB(msg) => msg.to_frame(),
            SBP::MsgEphemerisGloDepB(msg) => msg.to_frame(),
            SBP::MsgEphemerisGPSDepF(msg) => msg.to_frame(),
            SBP::MsgEphemerisGloDepC(msg) => msg.to_frame(),
            SBP::MsgEphemerisGloDepD(msg) => msg.to_frame(),
            SBP::MsgEphemerisBds(msg) => msg.to_frame(),
            SBP::MsgEphemerisGPS(msg) => msg.to_frame(),
            SBP::MsgEphemerisGlo(msg) => msg.to_frame(),
            SBP::MsgEphemerisSbas(msg) => msg.to_frame(),
            SBP::MsgEphemerisGal(msg) => msg.to_frame(),
            SBP::MsgEphemerisQzss(msg) => msg.to_frame(),
            SBP::MsgIono(msg) => msg.to_frame(),
            SBP::MsgSvConfigurationGPSDep(msg) => msg.to_frame(),
            SBP::MsgGroupDelayDepA(msg) => msg.to_frame(),
            SBP::MsgGroupDelayDepB(msg) => msg.to_frame(),
            SBP::MsgGroupDelay(msg) => msg.to_frame(),
            SBP::MsgEphemerisGalDepA(msg) => msg.to_frame(),
            SBP::MsgGnssCapb(msg) => msg.to_frame(),
            SBP::MsgSvAzEl(msg) => msg.to_frame(),
            SBP::MsgSettingsWrite(msg) => msg.to_frame(),
            SBP::MsgSettingsSave(msg) => msg.to_frame(),
            SBP::MsgSettingsReadByIndexReq(msg) => msg.to_frame(),
            SBP::MsgFileioReadResp(msg) => msg.to_frame(),
            SBP::MsgSettingsReadReq(msg) => msg.to_frame(),
            SBP::MsgSettingsReadResp(msg) => msg.to_frame(),
            SBP::MsgSettingsReadByIndexDone(msg) => msg.to_frame(),
            SBP::MsgSettingsReadByIndexResp(msg) => msg.to_frame(),
            SBP::MsgFileioReadReq(msg) => msg.to_frame(),
            SBP::MsgFileioReadDirReq(msg) => msg.to_frame(),
            SBP::MsgFileioReadDirResp(msg) => msg.to_frame(),
            SBP::MsgFileioWriteResp(msg) => msg.to_frame(),
            SBP::MsgFileioRemove(msg) => msg.to_frame(),
            SBP::MsgFileioWriteReq(msg) => msg.to_frame(),
            SBP::MsgSettingsRegister(msg) => msg.to_frame(),
            SBP::MsgSettingsWriteResp(msg) => msg.to_frame(),
            SBP::MsgBootloaderHandshakeDepA(msg) => msg.to_frame(),
            SBP::MsgBootloaderJumpToApp(msg) => msg.to_frame(),
            SBP::MsgResetDep(msg) => msg.to_frame(),
            SBP::MsgBootloaderHandshakeReq(msg) => msg.to_frame(),
            SBP::MsgBootloaderHandshakeResp(msg) => msg.to_frame(),
            SBP::MsgDeviceMonitor(msg) => msg.to_frame(),
            SBP::MsgReset(msg) => msg.to_frame(),
            SBP::MsgCommandReq(msg) => msg.to_frame(),
            SBP::MsgCommandResp(msg) => msg.to_frame(),
            SBP::MsgNetworkStateReq(msg) => msg.to_frame(),
            SBP::MsgNetworkStateResp(msg) => msg.to_frame(),
            SBP::MsgCommandOutput(msg) => msg.to_frame(),
            SBP::MsgNetworkBandwidthUsage(msg) => msg.to_frame(),
            SBP::MsgCellModemStatus(msg) => msg.to_frame(),
            SBP::MsgFrontEndGain(msg) => msg.to_frame(),
            SBP::MsgCwResults(msg) => msg.to_frame(),
            SBP::MsgCwStart(msg) => msg.to_frame(),
            SBP::MsgNapDeviceDnaResp(msg) => msg.to_frame(),
            SBP::MsgNapDeviceDnaReq(msg) => msg.to_frame(),
            SBP::MsgFlashDone(msg) => msg.to_frame(),
            SBP::MsgFlashReadResp(msg) => msg.to_frame(),
            SBP::MsgFlashErase(msg) => msg.to_frame(),
            SBP::MsgStmFlashLockSector(msg) => msg.to_frame(),
            SBP::MsgStmFlashUnlockSector(msg) => msg.to_frame(),
            SBP::MsgStmUniqueIdResp(msg) => msg.to_frame(),
            SBP::MsgFlashProgram(msg) => msg.to_frame(),
            SBP::MsgFlashReadReq(msg) => msg.to_frame(),
            SBP::MsgStmUniqueIdReq(msg) => msg.to_frame(),
            SBP::MsgM25FlashWriteStatus(msg) => msg.to_frame(),
            SBP::MsgGPSTimeDepA(msg) => msg.to_frame(),
            SBP::MsgExtEvent(msg) => msg.to_frame(),
            SBP::MsgGPSTime(msg) => msg.to_frame(),
            SBP::MsgUtcTime(msg) => msg.to_frame(),
            SBP::MsgGPSTimeGnss(msg) => msg.to_frame(),
            SBP::MsgUtcTimeGnss(msg) => msg.to_frame(),
            SBP::MsgSettingsRegisterResp(msg) => msg.to_frame(),
            SBP::MsgPosECEFDepA(msg) => msg.to_frame(),
            SBP::MsgPosLLHDepA(msg) => msg.to_frame(),
            SBP::MsgBaselineECEFDepA(msg) => msg.to_frame(),
            SBP::MsgBaselineNEDDepA(msg) => msg.to_frame(),
            SBP::MsgVelECEFDepA(msg) => msg.to_frame(),
            SBP::MsgVelNEDDepA(msg) => msg.to_frame(),
            SBP::MsgDopsDepA(msg) => msg.to_frame(),
            SBP::MsgBaselineHeadingDepA(msg) => msg.to_frame(),
            SBP::MsgDops(msg) => msg.to_frame(),
            SBP::MsgPosECEF(msg) => msg.to_frame(),
            SBP::MsgPosLLH(msg) => msg.to_frame(),
            SBP::MsgBaselineECEF(msg) => msg.to_frame(),
            SBP::MsgBaselineNED(msg) => msg.to_frame(),
            SBP::MsgVelECEF(msg) => msg.to_frame(),
            SBP::MsgVelNED(msg) => msg.to_frame(),
            SBP::MsgBaselineHeading(msg) => msg.to_frame(),
            SBP::MsgAgeCorrections(msg) => msg.to_frame(),
            SBP::MsgPosLLHCov(msg) => msg.to_frame(),
            SBP::MsgVelNEDCov(msg) => msg.to_frame(),
            SBP::MsgVelBody(msg) => msg.to_frame(),
            SBP::MsgPosECEFCov(msg) => msg.to_frame(),
            SBP::MsgVelECEFCov(msg) => msg.to_frame(),
            SBP::MsgProtectionLevelDepA(msg) => msg.to_frame(),
            SBP::MsgProtectionLevel(msg) => msg.to_frame(),
            SBP::MsgPosLLHAcc(msg) => msg.to_frame(),
            SBP::MsgOrientQuat(msg) => msg.to_frame(),
            SBP::MsgOrientEuler(msg) => msg.to_frame(),
            SBP::MsgAngularRate(msg) => msg.to_frame(),
            SBP::MsgPosECEFGnss(msg) => msg.to_frame(),
            SBP::MsgPosLLHGnss(msg) => msg.to_frame(),
            SBP::MsgVelECEFGnss(msg) => msg.to_frame(),
            SBP::MsgVelNEDGnss(msg) => msg.to_frame(),
            SBP::MsgPosLLHCovGnss(msg) => msg.to_frame(),
            SBP::MsgVelNEDCovGnss(msg) => msg.to_frame(),
            SBP::MsgPosECEFCovGnss(msg) => msg.to_frame(),
            SBP::MsgVelECEFCovGnss(msg) => msg.to_frame(),
            SBP::MsgNdbEvent(msg) => msg.to_frame(),
            SBP::MsgLog(msg) => msg.to_frame(),
            SBP::MsgFwd(msg) => msg.to_frame(),
            SBP::MsgSsrOrbitClockDepA(msg) => msg.to_frame(),
            SBP::MsgSsrOrbitClock(msg) => msg.to_frame(),
            SBP::MsgSsrCodeBiases(msg) => msg.to_frame(),
            SBP::MsgSsrPhaseBiases(msg) => msg.to_frame(),
            SBP::MsgSsrStecCorrectionDepA(msg) => msg.to_frame(),
            SBP::MsgSsrGriddedCorrectionNoStdDepA(msg) => msg.to_frame(),
            SBP::MsgSsrGridDefinitionDepA(msg) => msg.to_frame(),
            SBP::MsgSsrTileDefinition(msg) => msg.to_frame(),
            SBP::MsgSsrGriddedCorrectionDepA(msg) => msg.to_frame(),
            SBP::MsgSsrStecCorrection(msg) => msg.to_frame(),
            SBP::MsgSsrGriddedCorrection(msg) => msg.to_frame(),
            SBP::MsgSsrSatelliteApc(msg) => msg.to_frame(),
            SBP::MsgOsr(msg) => msg.to_frame(),
            SBP::MsgUserData(msg) => msg.to_frame(),
            SBP::MsgImuRaw(msg) => msg.to_frame(),
            SBP::MsgImuAux(msg) => msg.to_frame(),
            SBP::MsgMagRaw(msg) => msg.to_frame(),
            SBP::MsgOdometry(msg) => msg.to_frame(),
            SBP::MsgWheeltick(msg) => msg.to_frame(),
            SBP::MsgFileioConfigReq(msg) => msg.to_frame(),
            SBP::MsgFileioConfigResp(msg) => msg.to_frame(),
            SBP::MsgSbasRaw(msg) => msg.to_frame(),
            SBP::MsgLinuxCpuStateDepA(msg) => msg.to_frame(),
            SBP::MsgLinuxMemStateDepA(msg) => msg.to_frame(),
            SBP::MsgLinuxSysStateDepA(msg) => msg.to_frame(),
            SBP::MsgLinuxProcessSocketCounts(msg) => msg.to_frame(),
            SBP::MsgLinuxProcessSocketQueues(msg) => msg.to_frame(),
            SBP::MsgLinuxSocketUsage(msg) => msg.to_frame(),
            SBP::MsgLinuxProcessFdCount(msg) => msg.to_frame(),
            SBP::MsgLinuxProcessFdSummary(msg) => msg.to_frame(),
            SBP::MsgLinuxCpuState(msg) => msg.to_frame(),
            SBP::MsgLinuxMemState(msg) => msg.to_frame(),
            SBP::MsgLinuxSysState(msg) => msg.to_frame(),
            SBP::MsgStartup(msg) => msg.to_frame(),
            SBP::MsgDgnssStatus(msg) => msg.to_frame(),
            SBP::MsgInsStatus(msg) => msg.to_frame(),
            SBP::MsgCsacTelemetry(msg) => msg.to_frame(),
            SBP::MsgCsacTelemetryLabels(msg) => msg.to_frame(),
            SBP::MsgInsUpdates(msg) => msg.to_frame(),
            SBP::MsgGnssTimeOffset(msg) => msg.to_frame(),
            SBP::MsgPpsTime(msg) => msg.to_frame(),
            SBP::MsgGroupMeta(msg) => msg.to_frame(),
            SBP::MsgSolnMeta(msg) => msg.to_frame(),
            SBP::MsgSolnMetaDepA(msg) => msg.to_frame(),
            SBP::MsgStatusReport(msg) => msg.to_frame(),
            SBP::MsgHeartbeat(msg) => msg.to_frame(),
            SBP::Unknown(msg) => msg.to_frame(),
        }
    }

    fn write_frame(&self, buf: &mut Vec<u8>) -> Result<(), crate::FramerError> {
        match self {
            SBP::MsgPrintDep(msg) => msg.write_frame(buf),
            SBP::MsgTrackingStateDetailedDep(msg) => msg.write_frame(buf),
            SBP::MsgTrackingStateDepB(msg) => msg.write_frame(buf),
            SBP::MsgAcqResultDepB(msg) => msg.write_frame(buf),
            SBP::MsgAcqResultDepA(msg) => msg.write_frame(buf),
            SBP::MsgTrackingStateDepA(msg) => msg.write_frame(buf),
            SBP::MsgThreadState(msg) => msg.write_frame(buf),
            SBP::MsgUartStateDepa(msg) => msg.write_frame(buf),
            SBP::MsgIarState(msg) => msg.write_frame(buf),
            SBP::MsgEphemerisDepA(msg) => msg.write_frame(buf),
            SBP::MsgMaskSatelliteDep(msg) => msg.write_frame(buf),
            SBP::MsgTrackingIqDepA(msg) => msg.write_frame(buf),
            SBP::MsgUartState(msg) => msg.write_frame(buf),
            SBP::MsgAcqSvProfileDep(msg) => msg.write_frame(buf),
            SBP::MsgAcqResultDepC(msg) => msg.write_frame(buf),
            SBP::MsgTrackingStateDetailedDepA(msg) => msg.write_frame(buf),
            SBP::MsgResetFilters(msg) => msg.write_frame(buf),
            SBP::MsgInitBaseDep(msg) => msg.write_frame(buf),
            SBP::MsgMaskSatellite(msg) => msg.write_frame(buf),
            SBP::MsgTrackingIqDepB(msg) => msg.write_frame(buf),
            SBP::MsgTrackingIq(msg) => msg.write_frame(buf),
            SBP::MsgAcqSvProfile(msg) => msg.write_frame(buf),
            SBP::MsgAcqResult(msg) => msg.write_frame(buf),
            SBP::MsgTrackingState(msg) => msg.write_frame(buf),
            SBP::MsgObsDepB(msg) => msg.write_frame(buf),
            SBP::MsgBasePosLLH(msg) => msg.write_frame(buf),
            SBP::MsgObsDepA(msg) => msg.write_frame(buf),
            SBP::MsgEphemerisDepB(msg) => msg.write_frame(buf),
            SBP::MsgEphemerisDepC(msg) => msg.write_frame(buf),
            SBP::MsgBasePosECEF(msg) => msg.write_frame(buf),
            SBP::MsgObsDepC(msg) => msg.write_frame(buf),
            SBP::MsgObs(msg) => msg.write_frame(buf),
            SBP::MsgSpecanDep(msg) => msg.write_frame(buf),
            SBP::MsgSpecan(msg) => msg.write_frame(buf),
            SBP::MsgMeasurementState(msg) => msg.write_frame(buf),
            SBP::MsgSetTime(msg) => msg.write_frame(buf),
            SBP::MsgAlmanac(msg) => msg.write_frame(buf),
            SBP::MsgAlmanacGPSDep(msg) => msg.write_frame(buf),
            SBP::MsgAlmanacGloDep(msg) => msg.write_frame(buf),
            SBP::MsgAlmanacGPS(msg) => msg.write_frame(buf),
            SBP::MsgAlmanacGlo(msg) => msg.write_frame(buf),
            SBP::MsgGloBiases(msg) => msg.write_frame(buf),
            SBP::MsgEphemerisDepD(msg) => msg.write_frame(buf),
            SBP::MsgEphemerisGPSDepE(msg) => msg.write_frame(buf),
            SBP::MsgEphemerisSbasDepA(msg) => msg.write_frame(buf),
            SBP::MsgEphemerisGloDepA(msg) => msg.write_frame(buf),
            SBP::MsgEphemerisSbasDepB(msg) => msg.write_frame(buf),
            SBP::MsgEphemerisGloDepB(msg) => msg.write_frame(buf),
            SBP::MsgEphemerisGPSDepF(msg) => msg.write_frame(buf),
            SBP::MsgEphemerisGloDepC(msg) => msg.write_frame(buf),
            SBP::MsgEphemerisGloDepD(msg) => msg.write_frame(buf),
            SBP::MsgEphemerisBds(msg) => msg.write_frame(buf),
            SBP::MsgEphemerisGPS(msg) => msg.write_frame(buf),
            SBP::MsgEphemerisGlo(msg) => msg.write_frame(buf),
            SBP::MsgEphemerisSbas(msg) => msg.write_frame(buf),
            SBP::MsgEphemerisGal(msg) => msg.write_frame(buf),
            SBP::MsgEphemerisQzss(msg) => msg.write_frame(buf),
            SBP::MsgIono(msg) => msg.write_frame(buf),
            SBP::MsgSvConfigurationGPSDep(msg) => msg.write_frame(buf),
            SBP::MsgGroupDelayDepA(msg) => msg.write_frame(buf),
            SBP::MsgGroupDelayDepB(msg) => msg.write_frame(buf),
            SBP::MsgGroupDelay(msg) => msg.write_frame(buf),
            SBP::MsgEphemerisGalDepA(msg) => msg.write_frame(buf),
            SBP::MsgGnssCapb(msg) => msg.write_frame(buf),
            SBP::MsgSvAzEl(msg) => msg.write_frame(buf),
            SBP::MsgSettingsWrite(msg) => msg.write_frame(buf),
            SBP::MsgSettingsSave(msg) => msg.write_frame(buf),
            SBP::MsgSettingsReadByIndexReq(msg) => msg.write_frame(buf),
            SBP::MsgFileioReadResp(msg) => msg.write_frame(buf),
            SBP::MsgSettingsReadReq(msg) => msg.write_frame(buf),
            SBP::MsgSettingsReadResp(msg) => msg.write_frame(buf),
            SBP::MsgSettingsReadByIndexDone(msg) => msg.write_frame(buf),
            SBP::MsgSettingsReadByIndexResp(msg) => msg.write_frame(buf),
            SBP::MsgFileioReadReq(msg) => msg.write_frame(buf),
            SBP::MsgFileioReadDirReq(msg) => msg.write_frame(buf),
            SBP::MsgFileioReadDirResp(msg) => msg.write_frame(buf),
            SBP::MsgFileioWriteResp(msg) => msg.write_frame(buf),
            SBP::MsgFileioRemove(msg) => msg.write_frame(buf),
            SBP::MsgFileioWriteReq(msg) => msg.write_frame(buf),
            SBP::MsgSettingsRegister(msg) => msg.write_frame(buf),
            SBP::MsgSettingsWriteResp(msg) => msg.write_frame(buf),
            SBP::MsgBootloaderHandshakeDepA(msg) => msg.write_frame(buf),
            SBP::MsgBootloaderJumpToApp(msg) => msg.write_frame(buf),
            SBP::MsgResetDep(msg) => msg.write_frame(buf),
            SBP::MsgBootloaderHandshakeReq(msg) => msg.write_frame(buf),
            SBP::MsgBootloaderHandshakeResp(msg) => msg.write_frame(buf),
            SBP::MsgDeviceMonitor(msg) => msg.write_frame(buf),
            SBP::MsgReset(msg) => msg.write_frame(buf),
            SBP::MsgCommandReq(msg) => msg.write_frame(buf),
            SBP::MsgCommandResp(msg) => msg.write_frame(buf),
            SBP::MsgNetworkStateReq(msg) => msg.write_frame(buf),
            SBP::MsgNetworkStateResp(msg) => msg.write_frame(buf),
            SBP::MsgCommandOutput(msg) => msg.write_frame(buf),
            SBP::MsgNetworkBandwidthUsage(msg) => msg.write_frame(buf),
            SBP::MsgCellModemStatus(msg) => msg.write_frame(buf),
            SBP::MsgFrontEndGain(msg) => msg.write_frame(buf),
            SBP::MsgCwResults(msg) => msg.write_frame(buf),
            SBP::MsgCwStart(msg) => msg.write_frame(buf),
            SBP::MsgNapDeviceDnaResp(msg) => msg.write_frame(buf),
            SBP::MsgNapDeviceDnaReq(msg) => msg.write_frame(buf),
            SBP::MsgFlashDone(msg) => msg.write_frame(buf),
            SBP::MsgFlashReadResp(msg) => msg.write_frame(buf),
            SBP::MsgFlashErase(msg) => msg.write_frame(buf),
            SBP::MsgStmFlashLockSector(msg) => msg.write_frame(buf),
            SBP::MsgStmFlashUnlockSector(msg) => msg.write_frame(buf),
            SBP::MsgStmUniqueIdResp(msg) => msg.write_frame(buf),
            SBP::MsgFlashProgram(msg) => msg.write_frame(buf),
            SBP::MsgFlashReadReq(msg) => msg.write_frame(buf),
            SBP::MsgStmUniqueIdReq(msg) => msg.write_frame(buf),
            SBP::MsgM25FlashWriteStatus(msg) => msg.write_frame(buf),
            SBP::MsgGPSTimeDepA(msg) => msg.write_frame(buf),
            SBP::MsgExtEvent(msg) => msg.write_frame(buf),
            SBP::MsgGPSTime(msg) => msg.write_frame(buf),
            SBP::MsgUtcTime(msg) => msg.write_frame(buf),
            SBP::MsgGPSTimeGnss(msg) => msg.write_frame(buf),
            SBP::MsgUtcTimeGnss(msg) => msg.write_frame(buf),
            SBP::MsgSettingsRegisterResp(msg) => msg.write_frame(buf),
            SBP::MsgPosECEFDepA(msg) => msg.write_frame(buf),
            SBP::MsgPosLLHDepA(msg) => msg.write_frame(buf),
            SBP::MsgBaselineECEFDepA(msg) => msg.write_frame(buf),
            SBP::MsgBaselineNEDDepA(msg) => msg.write_frame(buf),
            SBP::MsgVelECEFDepA(msg) => msg.write_frame(buf),
            SBP::MsgVelNEDDepA(msg) => msg.write_frame(buf),
            SBP::MsgDopsDepA(msg) => msg.write_frame(buf),
            SBP::MsgBaselineHeadingDepA(msg) => msg.write_frame(buf),
            SBP::MsgDops(msg) => msg.write_frame(buf),
            SBP::MsgPosECEF(msg) => msg.write_frame(buf),
            SBP::MsgPosLLH(msg) => msg.write_frame(buf),
            SBP::MsgBaselineECEF(msg) => msg.write_frame(buf),
            SBP::MsgBaselineNED(msg) => msg.write_frame(buf),
            SBP::MsgVelECEF(msg) => msg.write_frame(buf),
            SBP::MsgVelNED(msg) => msg.write_frame(buf),
            SBP::MsgBaselineHeading(msg) => msg.write_frame(buf),
            SBP::MsgAgeCorrections(msg) => msg.write_frame(buf),
            SBP::MsgPosLLHCov(msg) => msg.write_frame(buf),
            SBP::MsgVelNEDCov(msg) => msg.write_frame(buf),
            SBP::MsgVelBody(msg) => msg.write_frame(buf),
            SBP::MsgPosECEFCov(msg) => msg.write_frame(buf),
            SBP::MsgVelECEFCov(msg) => msg.write_frame(buf),
            SBP::MsgProtectionLevelDepA(msg) => msg.write_frame(buf),
            SBP::MsgProtectionLevel(msg) => msg.write_frame(buf),
            SBP::MsgPosLLHAcc(msg) => msg.write_frame(buf),
            SBP::MsgOrientQuat(msg) => msg.write_frame(buf),
            SBP::MsgOrientEuler(msg) => msg.write_frame(buf),
            SBP::MsgAngularRate(msg) => msg.write_frame(buf),
            SBP::MsgPosECEFGnss(msg) => msg.write_frame(buf),
            SBP::MsgPosLLHGnss(msg) => msg.write_frame(buf),
            SBP::MsgVelECEFGnss(msg) => msg.write_frame(buf),
            SBP::MsgVelNEDGnss(msg) => msg.write_frame(buf),
            SBP::MsgPosLLHCovGnss(msg) => msg.write_frame(buf),
            SBP::MsgVelNEDCovGnss(msg) => msg.write_frame(buf),
            SBP::MsgPosECEFCovGnss(msg) => msg.write_frame(buf),
            SBP::MsgVelECEFCovGnss(msg) => msg.write_frame(buf),
            SBP::MsgNdbEvent(msg) => msg.write_frame(buf),
            SBP::MsgLog(msg) => msg.write_frame(buf),
            SBP::MsgFwd(msg) => msg.write_frame(buf),
            SBP::MsgSsrOrbitClockDepA(msg) => msg.write_frame(buf),
            SBP::MsgSsrOrbitClock(msg) => msg.write_frame(buf),
            SBP::MsgSsrCodeBiases(msg) => msg.write_frame(buf),
            SBP::MsgSsrPhaseBiases(msg) => msg.write_frame(buf),
            SBP::MsgSsrStecCorrectionDepA(msg) => msg.write_frame(buf),
            SBP::MsgSsrGriddedCorrectionNoStdDepA(msg) => msg.write_frame(buf),
            SBP::MsgSsrGridDefinitionDepA(msg) => msg.write_frame(buf),
            SBP::MsgSsrTileDefinition(msg) => msg.write_frame(buf),
            SBP::MsgSsrGriddedCorrectionDepA(msg) => msg.write_frame(buf),
            SBP::MsgSsrStecCorrection(msg) => msg.write_frame(buf),
            SBP::MsgSsrGriddedCorrection(msg) => msg.write_frame(buf),
            SBP::MsgSsrSatelliteApc(msg) => msg.write_frame(buf),
            SBP::MsgOsr(msg) => msg.write_frame(buf),
            SBP::MsgUserData(msg) => msg.write_frame(buf),
            SBP::MsgImuRaw(msg) => msg.write_frame(buf),
            SBP::MsgImuAux(msg) => msg.write_frame(buf),
            SBP::MsgMagRaw(msg) => msg.write_frame(buf),
            SBP::MsgOdometry(msg) => msg.write_frame(buf),
            SBP::MsgWheeltick(msg) => msg.write_frame(buf),
            SBP::MsgFileioConfigReq(msg) => msg.write_frame(buf),
            SBP::MsgFileioConfigResp(msg) => msg.write_frame(buf),
            SBP::MsgSbasRaw(msg) => msg.write_frame(buf),
            SBP::MsgLinuxCpuStateDepA(msg) => msg.write_frame(buf),
            SBP::MsgLinuxMemStateDepA(msg) => msg.write_frame(buf),
            SBP::MsgLinuxSysStateDepA(msg) => msg.write_frame(buf),
            SBP::MsgLinuxProcessSocketCounts(msg) => msg.write_frame(buf),
            SBP::MsgLinuxProcessSocketQueues(msg) => msg.write_frame(buf),
            SBP::MsgLinuxSocketUsage(msg) => msg.write_frame(buf),
            SBP::MsgLinuxProcessFdCount(msg) => msg.write_frame(buf),
            SBP::MsgLinuxProcessFdSummary(msg) => msg.write_frame(buf),
            SBP::MsgLinuxCpuState(msg) => msg.write_frame(buf),
            SBP::MsgLinuxMemState(msg) => msg.write_frame(buf),
            SBP::MsgLinuxSysState(msg) => msg.write_frame(buf),
            SBP::MsgStartup(msg) => msg.write_frame(buf),
            SBP::MsgDgnssStatus(msg) => msg.write_frame(buf),
            SBP::MsgInsStatus(msg) => msg.write_frame(buf),
            SBP::MsgCsacTelemetry(msg) => msg.write_frame(buf),
            SBP::MsgCsacTelemetryLabels(msg) => msg.write_frame(buf),
            SBP::MsgInsUpdates(msg) => msg.write_frame(buf),
            SBP::MsgGnssTimeOffset(msg) => msg.write_frame(buf),
            SBP::MsgPpsTime(msg) => msg.write_frame(buf),
            SBP::MsgGroupMeta(msg) => msg.write_frame(buf),
            SBP::MsgSolnMeta(msg) => msg.write_frame(buf),
            SBP::MsgSolnMetaDepA(msg) => msg.write_frame(buf),
            SBP::MsgStatusReport(msg) => msg.write_frame(buf),
            SBP::MsgHeartbeat(msg) => msg.write_frame(buf),
            SBP::Unknown(msg) => msg.write_frame(buf),
        }
    }

    #[cfg(feature = "swiftnav-rs")]
    fn gps_time(
        &self,
    ) -> Option<std::result::Result<crate::time::MessageTime, crate::time::GpsTimeError>> {
        match self {
            SBP::MsgPrintDep(msg) => msg.gps_time(),
            SBP::MsgTrackingStateDetailedDep(msg) => msg.gps_time(),
            SBP::MsgTrackingStateDepB(msg) => msg.gps_time(),
            SBP::MsgAcqResultDepB(msg) => msg.gps_time(),
            SBP::MsgAcqResultDepA(msg) => msg.gps_time(),
            SBP::MsgTrackingStateDepA(msg) => msg.gps_time(),
            SBP::MsgThreadState(msg) => msg.gps_time(),
            SBP::MsgUartStateDepa(msg) => msg.gps_time(),
            SBP::MsgIarState(msg) => msg.gps_time(),
            SBP::MsgEphemerisDepA(msg) => msg.gps_time(),
            SBP::MsgMaskSatelliteDep(msg) => msg.gps_time(),
            SBP::MsgTrackingIqDepA(msg) => msg.gps_time(),
            SBP::MsgUartState(msg) => msg.gps_time(),
            SBP::MsgAcqSvProfileDep(msg) => msg.gps_time(),
            SBP::MsgAcqResultDepC(msg) => msg.gps_time(),
            SBP::MsgTrackingStateDetailedDepA(msg) => msg.gps_time(),
            SBP::MsgResetFilters(msg) => msg.gps_time(),
            SBP::MsgInitBaseDep(msg) => msg.gps_time(),
            SBP::MsgMaskSatellite(msg) => msg.gps_time(),
            SBP::MsgTrackingIqDepB(msg) => msg.gps_time(),
            SBP::MsgTrackingIq(msg) => msg.gps_time(),
            SBP::MsgAcqSvProfile(msg) => msg.gps_time(),
            SBP::MsgAcqResult(msg) => msg.gps_time(),
            SBP::MsgTrackingState(msg) => msg.gps_time(),
            SBP::MsgObsDepB(msg) => msg.gps_time(),
            SBP::MsgBasePosLLH(msg) => msg.gps_time(),
            SBP::MsgObsDepA(msg) => msg.gps_time(),
            SBP::MsgEphemerisDepB(msg) => msg.gps_time(),
            SBP::MsgEphemerisDepC(msg) => msg.gps_time(),
            SBP::MsgBasePosECEF(msg) => msg.gps_time(),
            SBP::MsgObsDepC(msg) => msg.gps_time(),
            SBP::MsgObs(msg) => msg.gps_time(),
            SBP::MsgSpecanDep(msg) => msg.gps_time(),
            SBP::MsgSpecan(msg) => msg.gps_time(),
            SBP::MsgMeasurementState(msg) => msg.gps_time(),
            SBP::MsgSetTime(msg) => msg.gps_time(),
            SBP::MsgAlmanac(msg) => msg.gps_time(),
            SBP::MsgAlmanacGPSDep(msg) => msg.gps_time(),
            SBP::MsgAlmanacGloDep(msg) => msg.gps_time(),
            SBP::MsgAlmanacGPS(msg) => msg.gps_time(),
            SBP::MsgAlmanacGlo(msg) => msg.gps_time(),
            SBP::MsgGloBiases(msg) => msg.gps_time(),
            SBP::MsgEphemerisDepD(msg) => msg.gps_time(),
            SBP::MsgEphemerisGPSDepE(msg) => msg.gps_time(),
            SBP::MsgEphemerisSbasDepA(msg) => msg.gps_time(),
            SBP::MsgEphemerisGloDepA(msg) => msg.gps_time(),
            SBP::MsgEphemerisSbasDepB(msg) => msg.gps_time(),
            SBP::MsgEphemerisGloDepB(msg) => msg.gps_time(),
            SBP::MsgEphemerisGPSDepF(msg) => msg.gps_time(),
            SBP::MsgEphemerisGloDepC(msg) => msg.gps_time(),
            SBP::MsgEphemerisGloDepD(msg) => msg.gps_time(),
            SBP::MsgEphemerisBds(msg) => msg.gps_time(),
            SBP::MsgEphemerisGPS(msg) => msg.gps_time(),
            SBP::MsgEphemerisGlo(msg) => msg.gps_time(),
            SBP::MsgEphemerisSbas(msg) => msg.gps_time(),
            SBP::MsgEphemerisGal(msg) => msg.gps_time(),
            SBP::MsgEphemerisQzss(msg) => msg.gps_time(),
            SBP::MsgIono(msg) => msg.gps_time(),
            SBP::MsgSvConfigurationGPSDep(msg) => msg.gps_time(),
            SBP::MsgGroupDelayDepA(msg) => msg.gps_time(),
            SBP::MsgGroupDelayDepB(msg) => msg.gps_time(),
            SBP::MsgGroupDelay(msg) => msg.gps_time(),
            SBP::MsgEphemerisGalDepA(msg) => msg.gps_time(),
            SBP::MsgGnssCapb(msg) => msg.gps_time(),
            SBP::MsgSvAzEl(msg) => msg.gps_time(),
            SBP::MsgSettingsWrite(msg) => msg.gps_time(),
            SBP::MsgSettingsSave(msg) => msg.gps_time(),
            SBP::MsgSettingsReadByIndexReq(msg) => msg.gps_time(),
            SBP::MsgFileioReadResp(msg) => msg.gps_time(),
            SBP::MsgSettingsReadReq(msg) => msg.gps_time(),
            SBP::MsgSettingsReadResp(msg) => msg.gps_time(),
            SBP::MsgSettingsReadByIndexDone(msg) => msg.gps_time(),
            SBP::MsgSettingsReadByIndexResp(msg) => msg.gps_time(),
            SBP::MsgFileioReadReq(msg) => msg.gps_time(),
            SBP::MsgFileioReadDirReq(msg) => msg.gps_time(),
            SBP::MsgFileioReadDirResp(msg) => msg.gps_time(),
            SBP::MsgFileioWriteResp(msg) => msg.gps_time(),
            SBP::MsgFileioRemove(msg) => msg.gps_time(),
            SBP::MsgFileioWriteReq(msg) => msg.gps_time(),
            SBP::MsgSettingsRegister(msg) => msg.gps_time(),
            SBP::MsgSettingsWriteResp(msg) => msg.gps_time(),
            SBP::MsgBootloaderHandshakeDepA(msg) => msg.gps_time(),
            SBP::MsgBootloaderJumpToApp(msg) => msg.gps_time(),
            SBP::MsgResetDep(msg) => msg.gps_time(),
            SBP::MsgBootloaderHandshakeReq(msg) => msg.gps_time(),
            SBP::MsgBootloaderHandshakeResp(msg) => msg.gps_time(),
            SBP::MsgDeviceMonitor(msg) => msg.gps_time(),
            SBP::MsgReset(msg) => msg.gps_time(),
            SBP::MsgCommandReq(msg) => msg.gps_time(),
            SBP::MsgCommandResp(msg) => msg.gps_time(),
            SBP::MsgNetworkStateReq(msg) => msg.gps_time(),
            SBP::MsgNetworkStateResp(msg) => msg.gps_time(),
            SBP::MsgCommandOutput(msg) => msg.gps_time(),
            SBP::MsgNetworkBandwidthUsage(msg) => msg.gps_time(),
            SBP::MsgCellModemStatus(msg) => msg.gps_time(),
            SBP::MsgFrontEndGain(msg) => msg.gps_time(),
            SBP::MsgCwResults(msg) => msg.gps_time(),
            SBP::MsgCwStart(msg) => msg.gps_time(),
            SBP::MsgNapDeviceDnaResp(msg) => msg.gps_time(),
            SBP::MsgNapDeviceDnaReq(msg) => msg.gps_time(),
            SBP::MsgFlashDone(msg) => msg.gps_time(),
            SBP::MsgFlashReadResp(msg) => msg.gps_time(),
            SBP::MsgFlashErase(msg) => msg.gps_time(),
            SBP::MsgStmFlashLockSector(msg) => msg.gps_time(),
            SBP::MsgStmFlashUnlockSector(msg) => msg.gps_time(),
            SBP::MsgStmUniqueIdResp(msg) => msg.gps_time(),
            SBP::MsgFlashProgram(msg) => msg.gps_time(),
            SBP::MsgFlashReadReq(msg) => msg.gps_time(),
            SBP::MsgStmUniqueIdReq(msg) => msg.gps_time(),
            SBP::MsgM25FlashWriteStatus(msg) => msg.gps_time(),
            SBP::MsgGPSTimeDepA(msg) => msg.gps_time(),
            SBP::MsgExtEvent(msg) => msg.gps_time(),
            SBP::MsgGPSTime(msg) => msg.gps_time(),
            SBP::MsgUtcTime(msg) => msg.gps_time(),
            SBP::MsgGPSTimeGnss(msg) => msg.gps_time(),
            SBP::MsgUtcTimeGnss(msg) => msg.gps_time(),
            SBP::MsgSettingsRegisterResp(msg) => msg.gps_time(),
            SBP::MsgPosECEFDepA(msg) => msg.gps_time(),
            SBP::MsgPosLLHDepA(msg) => msg.gps_time(),
            SBP::MsgBaselineECEFDepA(msg) => msg.gps_time(),
            SBP::MsgBaselineNEDDepA(msg) => msg.gps_time(),
            SBP::MsgVelECEFDepA(msg) => msg.gps_time(),
            SBP::MsgVelNEDDepA(msg) => msg.gps_time(),
            SBP::MsgDopsDepA(msg) => msg.gps_time(),
            SBP::MsgBaselineHeadingDepA(msg) => msg.gps_time(),
            SBP::MsgDops(msg) => msg.gps_time(),
            SBP::MsgPosECEF(msg) => msg.gps_time(),
            SBP::MsgPosLLH(msg) => msg.gps_time(),
            SBP::MsgBaselineECEF(msg) => msg.gps_time(),
            SBP::MsgBaselineNED(msg) => msg.gps_time(),
            SBP::MsgVelECEF(msg) => msg.gps_time(),
            SBP::MsgVelNED(msg) => msg.gps_time(),
            SBP::MsgBaselineHeading(msg) => msg.gps_time(),
            SBP::MsgAgeCorrections(msg) => msg.gps_time(),
            SBP::MsgPosLLHCov(msg) => msg.gps_time(),
            SBP::MsgVelNEDCov(msg) => msg.gps_time(),
            SBP::MsgVelBody(msg) => msg.gps_time(),
            SBP::MsgPosECEFCov(msg) => msg.gps_time(),
            SBP::MsgVelECEFCov(msg) => msg.gps_time(),
            SBP::MsgProtectionLevelDepA(msg) => msg.gps_time(),
            SBP::MsgProtectionLevel(msg) => msg.gps_time(),
            SBP::MsgPosLLHAcc(msg) => msg.gps_time(),
            SBP::MsgOrientQuat(msg) => msg.gps_time(),
            SBP::MsgOrientEuler(msg) => msg.gps_time(),
            SBP::MsgAngularRate(msg) => msg.gps_time(),
            SBP::MsgPosECEFGnss(msg) => msg.gps_time(),
            SBP::MsgPosLLHGnss(msg) => msg.gps_time(),
            SBP::MsgVelECEFGnss(msg) => msg.gps_time(),
            SBP::MsgVelNEDGnss(msg) => msg.gps_time(),
            SBP::MsgPosLLHCovGnss(msg) => msg.gps_time(),
            SBP::MsgVelNEDCovGnss(msg) => msg.gps_time(),
            SBP::MsgPosECEFCovGnss(msg) => msg.gps_time(),
            SBP::MsgVelECEFCovGnss(msg) => msg.gps_time(),
            SBP::MsgNdbEvent(msg) => msg.gps_time(),
            SBP::MsgLog(msg) => msg.gps_time(),
            SBP::MsgFwd(msg) => msg.gps_time(),
            SBP::MsgSsrOrbitClockDepA(msg) => msg.gps_time(),
            SBP::MsgSsrOrbitClock(msg) => msg.gps_time(),
            SBP::MsgSsrCodeBiases(msg) => msg.gps_time(),
            SBP::MsgSsrPhaseBiases(msg) => msg.gps_time(),
            SBP::MsgSsrStecCorrectionDepA(msg) => msg.gps_time(),
            SBP::MsgSsrGriddedCorrectionNoStdDepA(msg) => msg.gps_time(),
            SBP::MsgSsrGridDefinitionDepA(msg) => msg.gps_time(),
            SBP::MsgSsrTileDefinition(msg) => msg.gps_time(),
            SBP::MsgSsrGriddedCorrectionDepA(msg) => msg.gps_time(),
            SBP::MsgSsrStecCorrection(msg) => msg.gps_time(),
            SBP::MsgSsrGriddedCorrection(msg) => msg.gps_time(),
            SBP::MsgSsrSatelliteApc(msg) => msg.gps_time(),
            SBP::MsgOsr(msg) => msg.gps_time(),
            SBP::MsgUserData(msg) => msg.gps_time(),
            SBP::MsgImuRaw(msg) => msg.gps_time(),
            SBP::MsgImuAux(msg) => msg.gps_time(),
            SBP::MsgMagRaw(msg) => msg.gps_time(),
            SBP::MsgOdometry(msg) => msg.gps_time(),
            SBP::MsgWheeltick(msg) => msg.gps_time(),
            SBP::MsgFileioConfigReq(msg) => msg.gps_time(),
            SBP::MsgFileioConfigResp(msg) => msg.gps_time(),
            SBP::MsgSbasRaw(msg) => msg.gps_time(),
            SBP::MsgLinuxCpuStateDepA(msg) => msg.gps_time(),
            SBP::MsgLinuxMemStateDepA(msg) => msg.gps_time(),
            SBP::MsgLinuxSysStateDepA(msg) => msg.gps_time(),
            SBP::MsgLinuxProcessSocketCounts(msg) => msg.gps_time(),
            SBP::MsgLinuxProcessSocketQueues(msg) => msg.gps_time(),
            SBP::MsgLinuxSocketUsage(msg) => msg.gps_time(),
            SBP::MsgLinuxProcessFdCount(msg) => msg.gps_time(),
            SBP::MsgLinuxProcessFdSummary(msg) => msg.gps_time(),
            SBP::MsgLinuxCpuState(msg) => msg.gps_time(),
            SBP::MsgLinuxMemState(msg) => msg.gps_time(),
            SBP::MsgLinuxSysState(msg) => msg.gps_time(),
            SBP::MsgStartup(msg) => msg.gps_time(),
            SBP::MsgDgnssStatus(msg) => msg.gps_time(),
            SBP::MsgInsStatus(msg) => msg.gps_time(),
            SBP::MsgCsacTelemetry(msg) => msg.gps_time(),
            SBP::MsgCsacTelemetryLabels(msg) => msg.gps_time(),
            SBP::MsgInsUpdates(msg) => msg.gps_time(),
            SBP::MsgGnssTimeOffset(msg) => msg.gps_time(),
            SBP::MsgPpsTime(msg) => msg.gps_time(),
            SBP::MsgGroupMeta(msg) => msg.gps_time(),
            SBP::MsgSolnMeta(msg) => msg.gps_time(),
            SBP::MsgSolnMetaDepA(msg) => msg.gps_time(),
            SBP::MsgStatusReport(msg) => msg.gps_time(),
            SBP::MsgHeartbeat(msg) => msg.gps_time(),
            SBP::Unknown(msg) => msg.gps_time(),
        }
    }
}

impl crate::SbpSerialize for SBP {
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        match self {
            SBP::MsgPrintDep(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgTrackingStateDetailedDep(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgTrackingStateDepB(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgAcqResultDepB(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgAcqResultDepA(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgTrackingStateDepA(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgThreadState(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgUartStateDepa(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgIarState(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgEphemerisDepA(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgMaskSatelliteDep(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgTrackingIqDepA(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgUartState(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgAcqSvProfileDep(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgAcqResultDepC(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgTrackingStateDetailedDepA(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgResetFilters(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgInitBaseDep(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgMaskSatellite(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgTrackingIqDepB(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgTrackingIq(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgAcqSvProfile(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgAcqResult(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgTrackingState(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgObsDepB(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgBasePosLLH(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgObsDepA(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgEphemerisDepB(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgEphemerisDepC(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgBasePosECEF(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgObsDepC(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgObs(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgSpecanDep(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgSpecan(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgMeasurementState(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgSetTime(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgAlmanac(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgAlmanacGPSDep(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgAlmanacGloDep(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgAlmanacGPS(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgAlmanacGlo(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgGloBiases(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgEphemerisDepD(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgEphemerisGPSDepE(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgEphemerisSbasDepA(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgEphemerisGloDepA(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgEphemerisSbasDepB(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgEphemerisGloDepB(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgEphemerisGPSDepF(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgEphemerisGloDepC(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgEphemerisGloDepD(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgEphemerisBds(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgEphemerisGPS(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgEphemerisGlo(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgEphemerisSbas(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgEphemerisGal(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgEphemerisQzss(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgIono(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgSvConfigurationGPSDep(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgGroupDelayDepA(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgGroupDelayDepB(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgGroupDelay(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgEphemerisGalDepA(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgGnssCapb(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgSvAzEl(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgSettingsWrite(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgSettingsSave(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgSettingsReadByIndexReq(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgFileioReadResp(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgSettingsReadReq(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgSettingsReadResp(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgSettingsReadByIndexDone(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgSettingsReadByIndexResp(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgFileioReadReq(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgFileioReadDirReq(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgFileioReadDirResp(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgFileioWriteResp(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgFileioRemove(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgFileioWriteReq(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgSettingsRegister(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgSettingsWriteResp(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgBootloaderHandshakeDepA(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgBootloaderJumpToApp(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgResetDep(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgBootloaderHandshakeReq(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgBootloaderHandshakeResp(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgDeviceMonitor(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgReset(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgCommandReq(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgCommandResp(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgNetworkStateReq(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgNetworkStateResp(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgCommandOutput(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgNetworkBandwidthUsage(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgCellModemStatus(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgFrontEndGain(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgCwResults(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgCwStart(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgNapDeviceDnaResp(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgNapDeviceDnaReq(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgFlashDone(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgFlashReadResp(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgFlashErase(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgStmFlashLockSector(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgStmFlashUnlockSector(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgStmUniqueIdResp(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgFlashProgram(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgFlashReadReq(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgStmUniqueIdReq(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgM25FlashWriteStatus(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgGPSTimeDepA(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgExtEvent(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgGPSTime(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgUtcTime(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgGPSTimeGnss(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgUtcTimeGnss(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgSettingsRegisterResp(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgPosECEFDepA(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgPosLLHDepA(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgBaselineECEFDepA(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgBaselineNEDDepA(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgVelECEFDepA(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgVelNEDDepA(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgDopsDepA(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgBaselineHeadingDepA(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgDops(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgPosECEF(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgPosLLH(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgBaselineECEF(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgBaselineNED(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgVelECEF(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgVelNED(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgBaselineHeading(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgAgeCorrections(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgPosLLHCov(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgVelNEDCov(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgVelBody(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgPosECEFCov(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgVelECEFCov(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgProtectionLevelDepA(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgProtectionLevel(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgPosLLHAcc(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgOrientQuat(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgOrientEuler(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgAngularRate(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgPosECEFGnss(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgPosLLHGnss(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgVelECEFGnss(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgVelNEDGnss(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgPosLLHCovGnss(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgVelNEDCovGnss(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgPosECEFCovGnss(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgVelECEFCovGnss(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgNdbEvent(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgLog(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgFwd(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgSsrOrbitClockDepA(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgSsrOrbitClock(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgSsrCodeBiases(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgSsrPhaseBiases(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgSsrStecCorrectionDepA(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgSsrGriddedCorrectionNoStdDepA(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgSsrGridDefinitionDepA(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgSsrTileDefinition(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgSsrGriddedCorrectionDepA(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgSsrStecCorrection(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgSsrGriddedCorrection(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgSsrSatelliteApc(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgOsr(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgUserData(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgImuRaw(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgImuAux(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgMagRaw(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgOdometry(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgWheeltick(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgFileioConfigReq(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgFileioConfigResp(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgSbasRaw(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgLinuxCpuStateDepA(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgLinuxMemStateDepA(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgLinuxSysStateDepA(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgLinuxProcessSocketCounts(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgLinuxProcessSocketQueues(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgLinuxSocketUsage(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgLinuxProcessFdCount(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgLinuxProcessFdSummary(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgLinuxCpuState(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgLinuxMemState(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgLinuxSysState(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgStartup(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgDgnssStatus(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgInsStatus(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgCsacTelemetry(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgCsacTelemetryLabels(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgInsUpdates(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgGnssTimeOffset(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgPpsTime(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgGroupMeta(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgSolnMeta(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgSolnMetaDepA(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgStatusReport(msg) => msg.append_to_sbp_buffer(buf),
            SBP::MsgHeartbeat(msg) => msg.append_to_sbp_buffer(buf),
            SBP::Unknown(msg) => msg.append_to_sbp_buffer(buf),
        }
    }

    fn sbp_size(&self) -> usize {
        match self {
            SBP::MsgPrintDep(msg) => msg.sbp_size(),
            SBP::MsgTrackingStateDetailedDep(msg) => msg.sbp_size(),
            SBP::MsgTrackingStateDepB(msg) => msg.sbp_size(),
            SBP::MsgAcqResultDepB(msg) => msg.sbp_size(),
            SBP::MsgAcqResultDepA(msg) => msg.sbp_size(),
            SBP::MsgTrackingStateDepA(msg) => msg.sbp_size(),
            SBP::MsgThreadState(msg) => msg.sbp_size(),
            SBP::MsgUartStateDepa(msg) => msg.sbp_size(),
            SBP::MsgIarState(msg) => msg.sbp_size(),
            SBP::MsgEphemerisDepA(msg) => msg.sbp_size(),
            SBP::MsgMaskSatelliteDep(msg) => msg.sbp_size(),
            SBP::MsgTrackingIqDepA(msg) => msg.sbp_size(),
            SBP::MsgUartState(msg) => msg.sbp_size(),
            SBP::MsgAcqSvProfileDep(msg) => msg.sbp_size(),
            SBP::MsgAcqResultDepC(msg) => msg.sbp_size(),
            SBP::MsgTrackingStateDetailedDepA(msg) => msg.sbp_size(),
            SBP::MsgResetFilters(msg) => msg.sbp_size(),
            SBP::MsgInitBaseDep(msg) => msg.sbp_size(),
            SBP::MsgMaskSatellite(msg) => msg.sbp_size(),
            SBP::MsgTrackingIqDepB(msg) => msg.sbp_size(),
            SBP::MsgTrackingIq(msg) => msg.sbp_size(),
            SBP::MsgAcqSvProfile(msg) => msg.sbp_size(),
            SBP::MsgAcqResult(msg) => msg.sbp_size(),
            SBP::MsgTrackingState(msg) => msg.sbp_size(),
            SBP::MsgObsDepB(msg) => msg.sbp_size(),
            SBP::MsgBasePosLLH(msg) => msg.sbp_size(),
            SBP::MsgObsDepA(msg) => msg.sbp_size(),
            SBP::MsgEphemerisDepB(msg) => msg.sbp_size(),
            SBP::MsgEphemerisDepC(msg) => msg.sbp_size(),
            SBP::MsgBasePosECEF(msg) => msg.sbp_size(),
            SBP::MsgObsDepC(msg) => msg.sbp_size(),
            SBP::MsgObs(msg) => msg.sbp_size(),
            SBP::MsgSpecanDep(msg) => msg.sbp_size(),
            SBP::MsgSpecan(msg) => msg.sbp_size(),
            SBP::MsgMeasurementState(msg) => msg.sbp_size(),
            SBP::MsgSetTime(msg) => msg.sbp_size(),
            SBP::MsgAlmanac(msg) => msg.sbp_size(),
            SBP::MsgAlmanacGPSDep(msg) => msg.sbp_size(),
            SBP::MsgAlmanacGloDep(msg) => msg.sbp_size(),
            SBP::MsgAlmanacGPS(msg) => msg.sbp_size(),
            SBP::MsgAlmanacGlo(msg) => msg.sbp_size(),
            SBP::MsgGloBiases(msg) => msg.sbp_size(),
            SBP::MsgEphemerisDepD(msg) => msg.sbp_size(),
            SBP::MsgEphemerisGPSDepE(msg) => msg.sbp_size(),
            SBP::MsgEphemerisSbasDepA(msg) => msg.sbp_size(),
            SBP::MsgEphemerisGloDepA(msg) => msg.sbp_size(),
            SBP::MsgEphemerisSbasDepB(msg) => msg.sbp_size(),
            SBP::MsgEphemerisGloDepB(msg) => msg.sbp_size(),
            SBP::MsgEphemerisGPSDepF(msg) => msg.sbp_size(),
            SBP::MsgEphemerisGloDepC(msg) => msg.sbp_size(),
            SBP::MsgEphemerisGloDepD(msg) => msg.sbp_size(),
            SBP::MsgEphemerisBds(msg) => msg.sbp_size(),
            SBP::MsgEphemerisGPS(msg) => msg.sbp_size(),
            SBP::MsgEphemerisGlo(msg) => msg.sbp_size(),
            SBP::MsgEphemerisSbas(msg) => msg.sbp_size(),
            SBP::MsgEphemerisGal(msg) => msg.sbp_size(),
            SBP::MsgEphemerisQzss(msg) => msg.sbp_size(),
            SBP::MsgIono(msg) => msg.sbp_size(),
            SBP::MsgSvConfigurationGPSDep(msg) => msg.sbp_size(),
            SBP::MsgGroupDelayDepA(msg) => msg.sbp_size(),
            SBP::MsgGroupDelayDepB(msg) => msg.sbp_size(),
            SBP::MsgGroupDelay(msg) => msg.sbp_size(),
            SBP::MsgEphemerisGalDepA(msg) => msg.sbp_size(),
            SBP::MsgGnssCapb(msg) => msg.sbp_size(),
            SBP::MsgSvAzEl(msg) => msg.sbp_size(),
            SBP::MsgSettingsWrite(msg) => msg.sbp_size(),
            SBP::MsgSettingsSave(msg) => msg.sbp_size(),
            SBP::MsgSettingsReadByIndexReq(msg) => msg.sbp_size(),
            SBP::MsgFileioReadResp(msg) => msg.sbp_size(),
            SBP::MsgSettingsReadReq(msg) => msg.sbp_size(),
            SBP::MsgSettingsReadResp(msg) => msg.sbp_size(),
            SBP::MsgSettingsReadByIndexDone(msg) => msg.sbp_size(),
            SBP::MsgSettingsReadByIndexResp(msg) => msg.sbp_size(),
            SBP::MsgFileioReadReq(msg) => msg.sbp_size(),
            SBP::MsgFileioReadDirReq(msg) => msg.sbp_size(),
            SBP::MsgFileioReadDirResp(msg) => msg.sbp_size(),
            SBP::MsgFileioWriteResp(msg) => msg.sbp_size(),
            SBP::MsgFileioRemove(msg) => msg.sbp_size(),
            SBP::MsgFileioWriteReq(msg) => msg.sbp_size(),
            SBP::MsgSettingsRegister(msg) => msg.sbp_size(),
            SBP::MsgSettingsWriteResp(msg) => msg.sbp_size(),
            SBP::MsgBootloaderHandshakeDepA(msg) => msg.sbp_size(),
            SBP::MsgBootloaderJumpToApp(msg) => msg.sbp_size(),
            SBP::MsgResetDep(msg) => msg.sbp_size(),
            SBP::MsgBootloaderHandshakeReq(msg) => msg.sbp_size(),
            SBP::MsgBootloaderHandshakeResp(msg) => msg.sbp_size(),
            SBP::MsgDeviceMonitor(msg) => msg.sbp_size(),
            SBP::MsgReset(msg) => msg.sbp_size(),
            SBP::MsgCommandReq(msg) => msg.sbp_size(),
            SBP::MsgCommandResp(msg) => msg.sbp_size(),
            SBP::MsgNetworkStateReq(msg) => msg.sbp_size(),
            SBP::MsgNetworkStateResp(msg) => msg.sbp_size(),
            SBP::MsgCommandOutput(msg) => msg.sbp_size(),
            SBP::MsgNetworkBandwidthUsage(msg) => msg.sbp_size(),
            SBP::MsgCellModemStatus(msg) => msg.sbp_size(),
            SBP::MsgFrontEndGain(msg) => msg.sbp_size(),
            SBP::MsgCwResults(msg) => msg.sbp_size(),
            SBP::MsgCwStart(msg) => msg.sbp_size(),
            SBP::MsgNapDeviceDnaResp(msg) => msg.sbp_size(),
            SBP::MsgNapDeviceDnaReq(msg) => msg.sbp_size(),
            SBP::MsgFlashDone(msg) => msg.sbp_size(),
            SBP::MsgFlashReadResp(msg) => msg.sbp_size(),
            SBP::MsgFlashErase(msg) => msg.sbp_size(),
            SBP::MsgStmFlashLockSector(msg) => msg.sbp_size(),
            SBP::MsgStmFlashUnlockSector(msg) => msg.sbp_size(),
            SBP::MsgStmUniqueIdResp(msg) => msg.sbp_size(),
            SBP::MsgFlashProgram(msg) => msg.sbp_size(),
            SBP::MsgFlashReadReq(msg) => msg.sbp_size(),
            SBP::MsgStmUniqueIdReq(msg) => msg.sbp_size(),
            SBP::MsgM25FlashWriteStatus(msg) => msg.sbp_size(),
            SBP::MsgGPSTimeDepA(msg) => msg.sbp_size(),
            SBP::MsgExtEvent(msg) => msg.sbp_size(),
            SBP::MsgGPSTime(msg) => msg.sbp_size(),
            SBP::MsgUtcTime(msg) => msg.sbp_size(),
            SBP::MsgGPSTimeGnss(msg) => msg.sbp_size(),
            SBP::MsgUtcTimeGnss(msg) => msg.sbp_size(),
            SBP::MsgSettingsRegisterResp(msg) => msg.sbp_size(),
            SBP::MsgPosECEFDepA(msg) => msg.sbp_size(),
            SBP::MsgPosLLHDepA(msg) => msg.sbp_size(),
            SBP::MsgBaselineECEFDepA(msg) => msg.sbp_size(),
            SBP::MsgBaselineNEDDepA(msg) => msg.sbp_size(),
            SBP::MsgVelECEFDepA(msg) => msg.sbp_size(),
            SBP::MsgVelNEDDepA(msg) => msg.sbp_size(),
            SBP::MsgDopsDepA(msg) => msg.sbp_size(),
            SBP::MsgBaselineHeadingDepA(msg) => msg.sbp_size(),
            SBP::MsgDops(msg) => msg.sbp_size(),
            SBP::MsgPosECEF(msg) => msg.sbp_size(),
            SBP::MsgPosLLH(msg) => msg.sbp_size(),
            SBP::MsgBaselineECEF(msg) => msg.sbp_size(),
            SBP::MsgBaselineNED(msg) => msg.sbp_size(),
            SBP::MsgVelECEF(msg) => msg.sbp_size(),
            SBP::MsgVelNED(msg) => msg.sbp_size(),
            SBP::MsgBaselineHeading(msg) => msg.sbp_size(),
            SBP::MsgAgeCorrections(msg) => msg.sbp_size(),
            SBP::MsgPosLLHCov(msg) => msg.sbp_size(),
            SBP::MsgVelNEDCov(msg) => msg.sbp_size(),
            SBP::MsgVelBody(msg) => msg.sbp_size(),
            SBP::MsgPosECEFCov(msg) => msg.sbp_size(),
            SBP::MsgVelECEFCov(msg) => msg.sbp_size(),
            SBP::MsgProtectionLevelDepA(msg) => msg.sbp_size(),
            SBP::MsgProtectionLevel(msg) => msg.sbp_size(),
            SBP::MsgPosLLHAcc(msg) => msg.sbp_size(),
            SBP::MsgOrientQuat(msg) => msg.sbp_size(),
            SBP::MsgOrientEuler(msg) => msg.sbp_size(),
            SBP::MsgAngularRate(msg) => msg.sbp_size(),
            SBP::MsgPosECEFGnss(msg) => msg.sbp_size(),
            SBP::MsgPosLLHGnss(msg) => msg.sbp_size(),
            SBP::MsgVelECEFGnss(msg) => msg.sbp_size(),
            SBP::MsgVelNEDGnss(msg) => msg.sbp_size(),
            SBP::MsgPosLLHCovGnss(msg) => msg.sbp_size(),
            SBP::MsgVelNEDCovGnss(msg) => msg.sbp_size(),
            SBP::MsgPosECEFCovGnss(msg) => msg.sbp_size(),
            SBP::MsgVelECEFCovGnss(msg) => msg.sbp_size(),
            SBP::MsgNdbEvent(msg) => msg.sbp_size(),
            SBP::MsgLog(msg) => msg.sbp_size(),
            SBP::MsgFwd(msg) => msg.sbp_size(),
            SBP::MsgSsrOrbitClockDepA(msg) => msg.sbp_size(),
            SBP::MsgSsrOrbitClock(msg) => msg.sbp_size(),
            SBP::MsgSsrCodeBiases(msg) => msg.sbp_size(),
            SBP::MsgSsrPhaseBiases(msg) => msg.sbp_size(),
            SBP::MsgSsrStecCorrectionDepA(msg) => msg.sbp_size(),
            SBP::MsgSsrGriddedCorrectionNoStdDepA(msg) => msg.sbp_size(),
            SBP::MsgSsrGridDefinitionDepA(msg) => msg.sbp_size(),
            SBP::MsgSsrTileDefinition(msg) => msg.sbp_size(),
            SBP::MsgSsrGriddedCorrectionDepA(msg) => msg.sbp_size(),
            SBP::MsgSsrStecCorrection(msg) => msg.sbp_size(),
            SBP::MsgSsrGriddedCorrection(msg) => msg.sbp_size(),
            SBP::MsgSsrSatelliteApc(msg) => msg.sbp_size(),
            SBP::MsgOsr(msg) => msg.sbp_size(),
            SBP::MsgUserData(msg) => msg.sbp_size(),
            SBP::MsgImuRaw(msg) => msg.sbp_size(),
            SBP::MsgImuAux(msg) => msg.sbp_size(),
            SBP::MsgMagRaw(msg) => msg.sbp_size(),
            SBP::MsgOdometry(msg) => msg.sbp_size(),
            SBP::MsgWheeltick(msg) => msg.sbp_size(),
            SBP::MsgFileioConfigReq(msg) => msg.sbp_size(),
            SBP::MsgFileioConfigResp(msg) => msg.sbp_size(),
            SBP::MsgSbasRaw(msg) => msg.sbp_size(),
            SBP::MsgLinuxCpuStateDepA(msg) => msg.sbp_size(),
            SBP::MsgLinuxMemStateDepA(msg) => msg.sbp_size(),
            SBP::MsgLinuxSysStateDepA(msg) => msg.sbp_size(),
            SBP::MsgLinuxProcessSocketCounts(msg) => msg.sbp_size(),
            SBP::MsgLinuxProcessSocketQueues(msg) => msg.sbp_size(),
            SBP::MsgLinuxSocketUsage(msg) => msg.sbp_size(),
            SBP::MsgLinuxProcessFdCount(msg) => msg.sbp_size(),
            SBP::MsgLinuxProcessFdSummary(msg) => msg.sbp_size(),
            SBP::MsgLinuxCpuState(msg) => msg.sbp_size(),
            SBP::MsgLinuxMemState(msg) => msg.sbp_size(),
            SBP::MsgLinuxSysState(msg) => msg.sbp_size(),
            SBP::MsgStartup(msg) => msg.sbp_size(),
            SBP::MsgDgnssStatus(msg) => msg.sbp_size(),
            SBP::MsgInsStatus(msg) => msg.sbp_size(),
            SBP::MsgCsacTelemetry(msg) => msg.sbp_size(),
            SBP::MsgCsacTelemetryLabels(msg) => msg.sbp_size(),
            SBP::MsgInsUpdates(msg) => msg.sbp_size(),
            SBP::MsgGnssTimeOffset(msg) => msg.sbp_size(),
            SBP::MsgPpsTime(msg) => msg.sbp_size(),
            SBP::MsgGroupMeta(msg) => msg.sbp_size(),
            SBP::MsgSolnMeta(msg) => msg.sbp_size(),
            SBP::MsgSolnMetaDepA(msg) => msg.sbp_size(),
            SBP::MsgStatusReport(msg) => msg.sbp_size(),
            SBP::MsgHeartbeat(msg) => msg.sbp_size(),
            SBP::Unknown(msg) => msg.sbp_size(),
        }
    }
}
impl From<MsgPrintDep> for SBP {
    fn from(msg: MsgPrintDep) -> Self {
        SBP::MsgPrintDep(msg)
    }
}
impl From<MsgTrackingStateDetailedDep> for SBP {
    fn from(msg: MsgTrackingStateDetailedDep) -> Self {
        SBP::MsgTrackingStateDetailedDep(msg)
    }
}
impl From<MsgTrackingStateDepB> for SBP {
    fn from(msg: MsgTrackingStateDepB) -> Self {
        SBP::MsgTrackingStateDepB(msg)
    }
}
impl From<MsgAcqResultDepB> for SBP {
    fn from(msg: MsgAcqResultDepB) -> Self {
        SBP::MsgAcqResultDepB(msg)
    }
}
impl From<MsgAcqResultDepA> for SBP {
    fn from(msg: MsgAcqResultDepA) -> Self {
        SBP::MsgAcqResultDepA(msg)
    }
}
impl From<MsgTrackingStateDepA> for SBP {
    fn from(msg: MsgTrackingStateDepA) -> Self {
        SBP::MsgTrackingStateDepA(msg)
    }
}
impl From<MsgThreadState> for SBP {
    fn from(msg: MsgThreadState) -> Self {
        SBP::MsgThreadState(msg)
    }
}
impl From<MsgUartStateDepa> for SBP {
    fn from(msg: MsgUartStateDepa) -> Self {
        SBP::MsgUartStateDepa(msg)
    }
}
impl From<MsgIarState> for SBP {
    fn from(msg: MsgIarState) -> Self {
        SBP::MsgIarState(msg)
    }
}
impl From<MsgEphemerisDepA> for SBP {
    fn from(msg: MsgEphemerisDepA) -> Self {
        SBP::MsgEphemerisDepA(msg)
    }
}
impl From<MsgMaskSatelliteDep> for SBP {
    fn from(msg: MsgMaskSatelliteDep) -> Self {
        SBP::MsgMaskSatelliteDep(msg)
    }
}
impl From<MsgTrackingIqDepA> for SBP {
    fn from(msg: MsgTrackingIqDepA) -> Self {
        SBP::MsgTrackingIqDepA(msg)
    }
}
impl From<MsgUartState> for SBP {
    fn from(msg: MsgUartState) -> Self {
        SBP::MsgUartState(msg)
    }
}
impl From<MsgAcqSvProfileDep> for SBP {
    fn from(msg: MsgAcqSvProfileDep) -> Self {
        SBP::MsgAcqSvProfileDep(msg)
    }
}
impl From<MsgAcqResultDepC> for SBP {
    fn from(msg: MsgAcqResultDepC) -> Self {
        SBP::MsgAcqResultDepC(msg)
    }
}
impl From<MsgTrackingStateDetailedDepA> for SBP {
    fn from(msg: MsgTrackingStateDetailedDepA) -> Self {
        SBP::MsgTrackingStateDetailedDepA(msg)
    }
}
impl From<MsgResetFilters> for SBP {
    fn from(msg: MsgResetFilters) -> Self {
        SBP::MsgResetFilters(msg)
    }
}
impl From<MsgInitBaseDep> for SBP {
    fn from(msg: MsgInitBaseDep) -> Self {
        SBP::MsgInitBaseDep(msg)
    }
}
impl From<MsgMaskSatellite> for SBP {
    fn from(msg: MsgMaskSatellite) -> Self {
        SBP::MsgMaskSatellite(msg)
    }
}
impl From<MsgTrackingIqDepB> for SBP {
    fn from(msg: MsgTrackingIqDepB) -> Self {
        SBP::MsgTrackingIqDepB(msg)
    }
}
impl From<MsgTrackingIq> for SBP {
    fn from(msg: MsgTrackingIq) -> Self {
        SBP::MsgTrackingIq(msg)
    }
}
impl From<MsgAcqSvProfile> for SBP {
    fn from(msg: MsgAcqSvProfile) -> Self {
        SBP::MsgAcqSvProfile(msg)
    }
}
impl From<MsgAcqResult> for SBP {
    fn from(msg: MsgAcqResult) -> Self {
        SBP::MsgAcqResult(msg)
    }
}
impl From<MsgTrackingState> for SBP {
    fn from(msg: MsgTrackingState) -> Self {
        SBP::MsgTrackingState(msg)
    }
}
impl From<MsgObsDepB> for SBP {
    fn from(msg: MsgObsDepB) -> Self {
        SBP::MsgObsDepB(msg)
    }
}
impl From<MsgBasePosLLH> for SBP {
    fn from(msg: MsgBasePosLLH) -> Self {
        SBP::MsgBasePosLLH(msg)
    }
}
impl From<MsgObsDepA> for SBP {
    fn from(msg: MsgObsDepA) -> Self {
        SBP::MsgObsDepA(msg)
    }
}
impl From<MsgEphemerisDepB> for SBP {
    fn from(msg: MsgEphemerisDepB) -> Self {
        SBP::MsgEphemerisDepB(msg)
    }
}
impl From<MsgEphemerisDepC> for SBP {
    fn from(msg: MsgEphemerisDepC) -> Self {
        SBP::MsgEphemerisDepC(msg)
    }
}
impl From<MsgBasePosECEF> for SBP {
    fn from(msg: MsgBasePosECEF) -> Self {
        SBP::MsgBasePosECEF(msg)
    }
}
impl From<MsgObsDepC> for SBP {
    fn from(msg: MsgObsDepC) -> Self {
        SBP::MsgObsDepC(msg)
    }
}
impl From<MsgObs> for SBP {
    fn from(msg: MsgObs) -> Self {
        SBP::MsgObs(msg)
    }
}
impl From<MsgSpecanDep> for SBP {
    fn from(msg: MsgSpecanDep) -> Self {
        SBP::MsgSpecanDep(msg)
    }
}
impl From<MsgSpecan> for SBP {
    fn from(msg: MsgSpecan) -> Self {
        SBP::MsgSpecan(msg)
    }
}
impl From<MsgMeasurementState> for SBP {
    fn from(msg: MsgMeasurementState) -> Self {
        SBP::MsgMeasurementState(msg)
    }
}
impl From<MsgSetTime> for SBP {
    fn from(msg: MsgSetTime) -> Self {
        SBP::MsgSetTime(msg)
    }
}
impl From<MsgAlmanac> for SBP {
    fn from(msg: MsgAlmanac) -> Self {
        SBP::MsgAlmanac(msg)
    }
}
impl From<MsgAlmanacGPSDep> for SBP {
    fn from(msg: MsgAlmanacGPSDep) -> Self {
        SBP::MsgAlmanacGPSDep(msg)
    }
}
impl From<MsgAlmanacGloDep> for SBP {
    fn from(msg: MsgAlmanacGloDep) -> Self {
        SBP::MsgAlmanacGloDep(msg)
    }
}
impl From<MsgAlmanacGPS> for SBP {
    fn from(msg: MsgAlmanacGPS) -> Self {
        SBP::MsgAlmanacGPS(msg)
    }
}
impl From<MsgAlmanacGlo> for SBP {
    fn from(msg: MsgAlmanacGlo) -> Self {
        SBP::MsgAlmanacGlo(msg)
    }
}
impl From<MsgGloBiases> for SBP {
    fn from(msg: MsgGloBiases) -> Self {
        SBP::MsgGloBiases(msg)
    }
}
impl From<MsgEphemerisDepD> for SBP {
    fn from(msg: MsgEphemerisDepD) -> Self {
        SBP::MsgEphemerisDepD(msg)
    }
}
impl From<MsgEphemerisGPSDepE> for SBP {
    fn from(msg: MsgEphemerisGPSDepE) -> Self {
        SBP::MsgEphemerisGPSDepE(msg)
    }
}
impl From<MsgEphemerisSbasDepA> for SBP {
    fn from(msg: MsgEphemerisSbasDepA) -> Self {
        SBP::MsgEphemerisSbasDepA(msg)
    }
}
impl From<MsgEphemerisGloDepA> for SBP {
    fn from(msg: MsgEphemerisGloDepA) -> Self {
        SBP::MsgEphemerisGloDepA(msg)
    }
}
impl From<MsgEphemerisSbasDepB> for SBP {
    fn from(msg: MsgEphemerisSbasDepB) -> Self {
        SBP::MsgEphemerisSbasDepB(msg)
    }
}
impl From<MsgEphemerisGloDepB> for SBP {
    fn from(msg: MsgEphemerisGloDepB) -> Self {
        SBP::MsgEphemerisGloDepB(msg)
    }
}
impl From<MsgEphemerisGPSDepF> for SBP {
    fn from(msg: MsgEphemerisGPSDepF) -> Self {
        SBP::MsgEphemerisGPSDepF(msg)
    }
}
impl From<MsgEphemerisGloDepC> for SBP {
    fn from(msg: MsgEphemerisGloDepC) -> Self {
        SBP::MsgEphemerisGloDepC(msg)
    }
}
impl From<MsgEphemerisGloDepD> for SBP {
    fn from(msg: MsgEphemerisGloDepD) -> Self {
        SBP::MsgEphemerisGloDepD(msg)
    }
}
impl From<MsgEphemerisBds> for SBP {
    fn from(msg: MsgEphemerisBds) -> Self {
        SBP::MsgEphemerisBds(msg)
    }
}
impl From<MsgEphemerisGPS> for SBP {
    fn from(msg: MsgEphemerisGPS) -> Self {
        SBP::MsgEphemerisGPS(msg)
    }
}
impl From<MsgEphemerisGlo> for SBP {
    fn from(msg: MsgEphemerisGlo) -> Self {
        SBP::MsgEphemerisGlo(msg)
    }
}
impl From<MsgEphemerisSbas> for SBP {
    fn from(msg: MsgEphemerisSbas) -> Self {
        SBP::MsgEphemerisSbas(msg)
    }
}
impl From<MsgEphemerisGal> for SBP {
    fn from(msg: MsgEphemerisGal) -> Self {
        SBP::MsgEphemerisGal(msg)
    }
}
impl From<MsgEphemerisQzss> for SBP {
    fn from(msg: MsgEphemerisQzss) -> Self {
        SBP::MsgEphemerisQzss(msg)
    }
}
impl From<MsgIono> for SBP {
    fn from(msg: MsgIono) -> Self {
        SBP::MsgIono(msg)
    }
}
impl From<MsgSvConfigurationGPSDep> for SBP {
    fn from(msg: MsgSvConfigurationGPSDep) -> Self {
        SBP::MsgSvConfigurationGPSDep(msg)
    }
}
impl From<MsgGroupDelayDepA> for SBP {
    fn from(msg: MsgGroupDelayDepA) -> Self {
        SBP::MsgGroupDelayDepA(msg)
    }
}
impl From<MsgGroupDelayDepB> for SBP {
    fn from(msg: MsgGroupDelayDepB) -> Self {
        SBP::MsgGroupDelayDepB(msg)
    }
}
impl From<MsgGroupDelay> for SBP {
    fn from(msg: MsgGroupDelay) -> Self {
        SBP::MsgGroupDelay(msg)
    }
}
impl From<MsgEphemerisGalDepA> for SBP {
    fn from(msg: MsgEphemerisGalDepA) -> Self {
        SBP::MsgEphemerisGalDepA(msg)
    }
}
impl From<MsgGnssCapb> for SBP {
    fn from(msg: MsgGnssCapb) -> Self {
        SBP::MsgGnssCapb(msg)
    }
}
impl From<MsgSvAzEl> for SBP {
    fn from(msg: MsgSvAzEl) -> Self {
        SBP::MsgSvAzEl(msg)
    }
}
impl From<MsgSettingsWrite> for SBP {
    fn from(msg: MsgSettingsWrite) -> Self {
        SBP::MsgSettingsWrite(msg)
    }
}
impl From<MsgSettingsSave> for SBP {
    fn from(msg: MsgSettingsSave) -> Self {
        SBP::MsgSettingsSave(msg)
    }
}
impl From<MsgSettingsReadByIndexReq> for SBP {
    fn from(msg: MsgSettingsReadByIndexReq) -> Self {
        SBP::MsgSettingsReadByIndexReq(msg)
    }
}
impl From<MsgFileioReadResp> for SBP {
    fn from(msg: MsgFileioReadResp) -> Self {
        SBP::MsgFileioReadResp(msg)
    }
}
impl From<MsgSettingsReadReq> for SBP {
    fn from(msg: MsgSettingsReadReq) -> Self {
        SBP::MsgSettingsReadReq(msg)
    }
}
impl From<MsgSettingsReadResp> for SBP {
    fn from(msg: MsgSettingsReadResp) -> Self {
        SBP::MsgSettingsReadResp(msg)
    }
}
impl From<MsgSettingsReadByIndexDone> for SBP {
    fn from(msg: MsgSettingsReadByIndexDone) -> Self {
        SBP::MsgSettingsReadByIndexDone(msg)
    }
}
impl From<MsgSettingsReadByIndexResp> for SBP {
    fn from(msg: MsgSettingsReadByIndexResp) -> Self {
        SBP::MsgSettingsReadByIndexResp(msg)
    }
}
impl From<MsgFileioReadReq> for SBP {
    fn from(msg: MsgFileioReadReq) -> Self {
        SBP::MsgFileioReadReq(msg)
    }
}
impl From<MsgFileioReadDirReq> for SBP {
    fn from(msg: MsgFileioReadDirReq) -> Self {
        SBP::MsgFileioReadDirReq(msg)
    }
}
impl From<MsgFileioReadDirResp> for SBP {
    fn from(msg: MsgFileioReadDirResp) -> Self {
        SBP::MsgFileioReadDirResp(msg)
    }
}
impl From<MsgFileioWriteResp> for SBP {
    fn from(msg: MsgFileioWriteResp) -> Self {
        SBP::MsgFileioWriteResp(msg)
    }
}
impl From<MsgFileioRemove> for SBP {
    fn from(msg: MsgFileioRemove) -> Self {
        SBP::MsgFileioRemove(msg)
    }
}
impl From<MsgFileioWriteReq> for SBP {
    fn from(msg: MsgFileioWriteReq) -> Self {
        SBP::MsgFileioWriteReq(msg)
    }
}
impl From<MsgSettingsRegister> for SBP {
    fn from(msg: MsgSettingsRegister) -> Self {
        SBP::MsgSettingsRegister(msg)
    }
}
impl From<MsgSettingsWriteResp> for SBP {
    fn from(msg: MsgSettingsWriteResp) -> Self {
        SBP::MsgSettingsWriteResp(msg)
    }
}
impl From<MsgBootloaderHandshakeDepA> for SBP {
    fn from(msg: MsgBootloaderHandshakeDepA) -> Self {
        SBP::MsgBootloaderHandshakeDepA(msg)
    }
}
impl From<MsgBootloaderJumpToApp> for SBP {
    fn from(msg: MsgBootloaderJumpToApp) -> Self {
        SBP::MsgBootloaderJumpToApp(msg)
    }
}
impl From<MsgResetDep> for SBP {
    fn from(msg: MsgResetDep) -> Self {
        SBP::MsgResetDep(msg)
    }
}
impl From<MsgBootloaderHandshakeReq> for SBP {
    fn from(msg: MsgBootloaderHandshakeReq) -> Self {
        SBP::MsgBootloaderHandshakeReq(msg)
    }
}
impl From<MsgBootloaderHandshakeResp> for SBP {
    fn from(msg: MsgBootloaderHandshakeResp) -> Self {
        SBP::MsgBootloaderHandshakeResp(msg)
    }
}
impl From<MsgDeviceMonitor> for SBP {
    fn from(msg: MsgDeviceMonitor) -> Self {
        SBP::MsgDeviceMonitor(msg)
    }
}
impl From<MsgReset> for SBP {
    fn from(msg: MsgReset) -> Self {
        SBP::MsgReset(msg)
    }
}
impl From<MsgCommandReq> for SBP {
    fn from(msg: MsgCommandReq) -> Self {
        SBP::MsgCommandReq(msg)
    }
}
impl From<MsgCommandResp> for SBP {
    fn from(msg: MsgCommandResp) -> Self {
        SBP::MsgCommandResp(msg)
    }
}
impl From<MsgNetworkStateReq> for SBP {
    fn from(msg: MsgNetworkStateReq) -> Self {
        SBP::MsgNetworkStateReq(msg)
    }
}
impl From<MsgNetworkStateResp> for SBP {
    fn from(msg: MsgNetworkStateResp) -> Self {
        SBP::MsgNetworkStateResp(msg)
    }
}
impl From<MsgCommandOutput> for SBP {
    fn from(msg: MsgCommandOutput) -> Self {
        SBP::MsgCommandOutput(msg)
    }
}
impl From<MsgNetworkBandwidthUsage> for SBP {
    fn from(msg: MsgNetworkBandwidthUsage) -> Self {
        SBP::MsgNetworkBandwidthUsage(msg)
    }
}
impl From<MsgCellModemStatus> for SBP {
    fn from(msg: MsgCellModemStatus) -> Self {
        SBP::MsgCellModemStatus(msg)
    }
}
impl From<MsgFrontEndGain> for SBP {
    fn from(msg: MsgFrontEndGain) -> Self {
        SBP::MsgFrontEndGain(msg)
    }
}
impl From<MsgCwResults> for SBP {
    fn from(msg: MsgCwResults) -> Self {
        SBP::MsgCwResults(msg)
    }
}
impl From<MsgCwStart> for SBP {
    fn from(msg: MsgCwStart) -> Self {
        SBP::MsgCwStart(msg)
    }
}
impl From<MsgNapDeviceDnaResp> for SBP {
    fn from(msg: MsgNapDeviceDnaResp) -> Self {
        SBP::MsgNapDeviceDnaResp(msg)
    }
}
impl From<MsgNapDeviceDnaReq> for SBP {
    fn from(msg: MsgNapDeviceDnaReq) -> Self {
        SBP::MsgNapDeviceDnaReq(msg)
    }
}
impl From<MsgFlashDone> for SBP {
    fn from(msg: MsgFlashDone) -> Self {
        SBP::MsgFlashDone(msg)
    }
}
impl From<MsgFlashReadResp> for SBP {
    fn from(msg: MsgFlashReadResp) -> Self {
        SBP::MsgFlashReadResp(msg)
    }
}
impl From<MsgFlashErase> for SBP {
    fn from(msg: MsgFlashErase) -> Self {
        SBP::MsgFlashErase(msg)
    }
}
impl From<MsgStmFlashLockSector> for SBP {
    fn from(msg: MsgStmFlashLockSector) -> Self {
        SBP::MsgStmFlashLockSector(msg)
    }
}
impl From<MsgStmFlashUnlockSector> for SBP {
    fn from(msg: MsgStmFlashUnlockSector) -> Self {
        SBP::MsgStmFlashUnlockSector(msg)
    }
}
impl From<MsgStmUniqueIdResp> for SBP {
    fn from(msg: MsgStmUniqueIdResp) -> Self {
        SBP::MsgStmUniqueIdResp(msg)
    }
}
impl From<MsgFlashProgram> for SBP {
    fn from(msg: MsgFlashProgram) -> Self {
        SBP::MsgFlashProgram(msg)
    }
}
impl From<MsgFlashReadReq> for SBP {
    fn from(msg: MsgFlashReadReq) -> Self {
        SBP::MsgFlashReadReq(msg)
    }
}
impl From<MsgStmUniqueIdReq> for SBP {
    fn from(msg: MsgStmUniqueIdReq) -> Self {
        SBP::MsgStmUniqueIdReq(msg)
    }
}
impl From<MsgM25FlashWriteStatus> for SBP {
    fn from(msg: MsgM25FlashWriteStatus) -> Self {
        SBP::MsgM25FlashWriteStatus(msg)
    }
}
impl From<MsgGPSTimeDepA> for SBP {
    fn from(msg: MsgGPSTimeDepA) -> Self {
        SBP::MsgGPSTimeDepA(msg)
    }
}
impl From<MsgExtEvent> for SBP {
    fn from(msg: MsgExtEvent) -> Self {
        SBP::MsgExtEvent(msg)
    }
}
impl From<MsgGPSTime> for SBP {
    fn from(msg: MsgGPSTime) -> Self {
        SBP::MsgGPSTime(msg)
    }
}
impl From<MsgUtcTime> for SBP {
    fn from(msg: MsgUtcTime) -> Self {
        SBP::MsgUtcTime(msg)
    }
}
impl From<MsgGPSTimeGnss> for SBP {
    fn from(msg: MsgGPSTimeGnss) -> Self {
        SBP::MsgGPSTimeGnss(msg)
    }
}
impl From<MsgUtcTimeGnss> for SBP {
    fn from(msg: MsgUtcTimeGnss) -> Self {
        SBP::MsgUtcTimeGnss(msg)
    }
}
impl From<MsgSettingsRegisterResp> for SBP {
    fn from(msg: MsgSettingsRegisterResp) -> Self {
        SBP::MsgSettingsRegisterResp(msg)
    }
}
impl From<MsgPosECEFDepA> for SBP {
    fn from(msg: MsgPosECEFDepA) -> Self {
        SBP::MsgPosECEFDepA(msg)
    }
}
impl From<MsgPosLLHDepA> for SBP {
    fn from(msg: MsgPosLLHDepA) -> Self {
        SBP::MsgPosLLHDepA(msg)
    }
}
impl From<MsgBaselineECEFDepA> for SBP {
    fn from(msg: MsgBaselineECEFDepA) -> Self {
        SBP::MsgBaselineECEFDepA(msg)
    }
}
impl From<MsgBaselineNEDDepA> for SBP {
    fn from(msg: MsgBaselineNEDDepA) -> Self {
        SBP::MsgBaselineNEDDepA(msg)
    }
}
impl From<MsgVelECEFDepA> for SBP {
    fn from(msg: MsgVelECEFDepA) -> Self {
        SBP::MsgVelECEFDepA(msg)
    }
}
impl From<MsgVelNEDDepA> for SBP {
    fn from(msg: MsgVelNEDDepA) -> Self {
        SBP::MsgVelNEDDepA(msg)
    }
}
impl From<MsgDopsDepA> for SBP {
    fn from(msg: MsgDopsDepA) -> Self {
        SBP::MsgDopsDepA(msg)
    }
}
impl From<MsgBaselineHeadingDepA> for SBP {
    fn from(msg: MsgBaselineHeadingDepA) -> Self {
        SBP::MsgBaselineHeadingDepA(msg)
    }
}
impl From<MsgDops> for SBP {
    fn from(msg: MsgDops) -> Self {
        SBP::MsgDops(msg)
    }
}
impl From<MsgPosECEF> for SBP {
    fn from(msg: MsgPosECEF) -> Self {
        SBP::MsgPosECEF(msg)
    }
}
impl From<MsgPosLLH> for SBP {
    fn from(msg: MsgPosLLH) -> Self {
        SBP::MsgPosLLH(msg)
    }
}
impl From<MsgBaselineECEF> for SBP {
    fn from(msg: MsgBaselineECEF) -> Self {
        SBP::MsgBaselineECEF(msg)
    }
}
impl From<MsgBaselineNED> for SBP {
    fn from(msg: MsgBaselineNED) -> Self {
        SBP::MsgBaselineNED(msg)
    }
}
impl From<MsgVelECEF> for SBP {
    fn from(msg: MsgVelECEF) -> Self {
        SBP::MsgVelECEF(msg)
    }
}
impl From<MsgVelNED> for SBP {
    fn from(msg: MsgVelNED) -> Self {
        SBP::MsgVelNED(msg)
    }
}
impl From<MsgBaselineHeading> for SBP {
    fn from(msg: MsgBaselineHeading) -> Self {
        SBP::MsgBaselineHeading(msg)
    }
}
impl From<MsgAgeCorrections> for SBP {
    fn from(msg: MsgAgeCorrections) -> Self {
        SBP::MsgAgeCorrections(msg)
    }
}
impl From<MsgPosLLHCov> for SBP {
    fn from(msg: MsgPosLLHCov) -> Self {
        SBP::MsgPosLLHCov(msg)
    }
}
impl From<MsgVelNEDCov> for SBP {
    fn from(msg: MsgVelNEDCov) -> Self {
        SBP::MsgVelNEDCov(msg)
    }
}
impl From<MsgVelBody> for SBP {
    fn from(msg: MsgVelBody) -> Self {
        SBP::MsgVelBody(msg)
    }
}
impl From<MsgPosECEFCov> for SBP {
    fn from(msg: MsgPosECEFCov) -> Self {
        SBP::MsgPosECEFCov(msg)
    }
}
impl From<MsgVelECEFCov> for SBP {
    fn from(msg: MsgVelECEFCov) -> Self {
        SBP::MsgVelECEFCov(msg)
    }
}
impl From<MsgProtectionLevelDepA> for SBP {
    fn from(msg: MsgProtectionLevelDepA) -> Self {
        SBP::MsgProtectionLevelDepA(msg)
    }
}
impl From<MsgProtectionLevel> for SBP {
    fn from(msg: MsgProtectionLevel) -> Self {
        SBP::MsgProtectionLevel(msg)
    }
}
impl From<MsgPosLLHAcc> for SBP {
    fn from(msg: MsgPosLLHAcc) -> Self {
        SBP::MsgPosLLHAcc(msg)
    }
}
impl From<MsgOrientQuat> for SBP {
    fn from(msg: MsgOrientQuat) -> Self {
        SBP::MsgOrientQuat(msg)
    }
}
impl From<MsgOrientEuler> for SBP {
    fn from(msg: MsgOrientEuler) -> Self {
        SBP::MsgOrientEuler(msg)
    }
}
impl From<MsgAngularRate> for SBP {
    fn from(msg: MsgAngularRate) -> Self {
        SBP::MsgAngularRate(msg)
    }
}
impl From<MsgPosECEFGnss> for SBP {
    fn from(msg: MsgPosECEFGnss) -> Self {
        SBP::MsgPosECEFGnss(msg)
    }
}
impl From<MsgPosLLHGnss> for SBP {
    fn from(msg: MsgPosLLHGnss) -> Self {
        SBP::MsgPosLLHGnss(msg)
    }
}
impl From<MsgVelECEFGnss> for SBP {
    fn from(msg: MsgVelECEFGnss) -> Self {
        SBP::MsgVelECEFGnss(msg)
    }
}
impl From<MsgVelNEDGnss> for SBP {
    fn from(msg: MsgVelNEDGnss) -> Self {
        SBP::MsgVelNEDGnss(msg)
    }
}
impl From<MsgPosLLHCovGnss> for SBP {
    fn from(msg: MsgPosLLHCovGnss) -> Self {
        SBP::MsgPosLLHCovGnss(msg)
    }
}
impl From<MsgVelNEDCovGnss> for SBP {
    fn from(msg: MsgVelNEDCovGnss) -> Self {
        SBP::MsgVelNEDCovGnss(msg)
    }
}
impl From<MsgPosECEFCovGnss> for SBP {
    fn from(msg: MsgPosECEFCovGnss) -> Self {
        SBP::MsgPosECEFCovGnss(msg)
    }
}
impl From<MsgVelECEFCovGnss> for SBP {
    fn from(msg: MsgVelECEFCovGnss) -> Self {
        SBP::MsgVelECEFCovGnss(msg)
    }
}
impl From<MsgNdbEvent> for SBP {
    fn from(msg: MsgNdbEvent) -> Self {
        SBP::MsgNdbEvent(msg)
    }
}
impl From<MsgLog> for SBP {
    fn from(msg: MsgLog) -> Self {
        SBP::MsgLog(msg)
    }
}
impl From<MsgFwd> for SBP {
    fn from(msg: MsgFwd) -> Self {
        SBP::MsgFwd(msg)
    }
}
impl From<MsgSsrOrbitClockDepA> for SBP {
    fn from(msg: MsgSsrOrbitClockDepA) -> Self {
        SBP::MsgSsrOrbitClockDepA(msg)
    }
}
impl From<MsgSsrOrbitClock> for SBP {
    fn from(msg: MsgSsrOrbitClock) -> Self {
        SBP::MsgSsrOrbitClock(msg)
    }
}
impl From<MsgSsrCodeBiases> for SBP {
    fn from(msg: MsgSsrCodeBiases) -> Self {
        SBP::MsgSsrCodeBiases(msg)
    }
}
impl From<MsgSsrPhaseBiases> for SBP {
    fn from(msg: MsgSsrPhaseBiases) -> Self {
        SBP::MsgSsrPhaseBiases(msg)
    }
}
impl From<MsgSsrStecCorrectionDepA> for SBP {
    fn from(msg: MsgSsrStecCorrectionDepA) -> Self {
        SBP::MsgSsrStecCorrectionDepA(msg)
    }
}
impl From<MsgSsrGriddedCorrectionNoStdDepA> for SBP {
    fn from(msg: MsgSsrGriddedCorrectionNoStdDepA) -> Self {
        SBP::MsgSsrGriddedCorrectionNoStdDepA(msg)
    }
}
impl From<MsgSsrGridDefinitionDepA> for SBP {
    fn from(msg: MsgSsrGridDefinitionDepA) -> Self {
        SBP::MsgSsrGridDefinitionDepA(msg)
    }
}
impl From<MsgSsrTileDefinition> for SBP {
    fn from(msg: MsgSsrTileDefinition) -> Self {
        SBP::MsgSsrTileDefinition(msg)
    }
}
impl From<MsgSsrGriddedCorrectionDepA> for SBP {
    fn from(msg: MsgSsrGriddedCorrectionDepA) -> Self {
        SBP::MsgSsrGriddedCorrectionDepA(msg)
    }
}
impl From<MsgSsrStecCorrection> for SBP {
    fn from(msg: MsgSsrStecCorrection) -> Self {
        SBP::MsgSsrStecCorrection(msg)
    }
}
impl From<MsgSsrGriddedCorrection> for SBP {
    fn from(msg: MsgSsrGriddedCorrection) -> Self {
        SBP::MsgSsrGriddedCorrection(msg)
    }
}
impl From<MsgSsrSatelliteApc> for SBP {
    fn from(msg: MsgSsrSatelliteApc) -> Self {
        SBP::MsgSsrSatelliteApc(msg)
    }
}
impl From<MsgOsr> for SBP {
    fn from(msg: MsgOsr) -> Self {
        SBP::MsgOsr(msg)
    }
}
impl From<MsgUserData> for SBP {
    fn from(msg: MsgUserData) -> Self {
        SBP::MsgUserData(msg)
    }
}
impl From<MsgImuRaw> for SBP {
    fn from(msg: MsgImuRaw) -> Self {
        SBP::MsgImuRaw(msg)
    }
}
impl From<MsgImuAux> for SBP {
    fn from(msg: MsgImuAux) -> Self {
        SBP::MsgImuAux(msg)
    }
}
impl From<MsgMagRaw> for SBP {
    fn from(msg: MsgMagRaw) -> Self {
        SBP::MsgMagRaw(msg)
    }
}
impl From<MsgOdometry> for SBP {
    fn from(msg: MsgOdometry) -> Self {
        SBP::MsgOdometry(msg)
    }
}
impl From<MsgWheeltick> for SBP {
    fn from(msg: MsgWheeltick) -> Self {
        SBP::MsgWheeltick(msg)
    }
}
impl From<MsgFileioConfigReq> for SBP {
    fn from(msg: MsgFileioConfigReq) -> Self {
        SBP::MsgFileioConfigReq(msg)
    }
}
impl From<MsgFileioConfigResp> for SBP {
    fn from(msg: MsgFileioConfigResp) -> Self {
        SBP::MsgFileioConfigResp(msg)
    }
}
impl From<MsgSbasRaw> for SBP {
    fn from(msg: MsgSbasRaw) -> Self {
        SBP::MsgSbasRaw(msg)
    }
}
impl From<MsgLinuxCpuStateDepA> for SBP {
    fn from(msg: MsgLinuxCpuStateDepA) -> Self {
        SBP::MsgLinuxCpuStateDepA(msg)
    }
}
impl From<MsgLinuxMemStateDepA> for SBP {
    fn from(msg: MsgLinuxMemStateDepA) -> Self {
        SBP::MsgLinuxMemStateDepA(msg)
    }
}
impl From<MsgLinuxSysStateDepA> for SBP {
    fn from(msg: MsgLinuxSysStateDepA) -> Self {
        SBP::MsgLinuxSysStateDepA(msg)
    }
}
impl From<MsgLinuxProcessSocketCounts> for SBP {
    fn from(msg: MsgLinuxProcessSocketCounts) -> Self {
        SBP::MsgLinuxProcessSocketCounts(msg)
    }
}
impl From<MsgLinuxProcessSocketQueues> for SBP {
    fn from(msg: MsgLinuxProcessSocketQueues) -> Self {
        SBP::MsgLinuxProcessSocketQueues(msg)
    }
}
impl From<MsgLinuxSocketUsage> for SBP {
    fn from(msg: MsgLinuxSocketUsage) -> Self {
        SBP::MsgLinuxSocketUsage(msg)
    }
}
impl From<MsgLinuxProcessFdCount> for SBP {
    fn from(msg: MsgLinuxProcessFdCount) -> Self {
        SBP::MsgLinuxProcessFdCount(msg)
    }
}
impl From<MsgLinuxProcessFdSummary> for SBP {
    fn from(msg: MsgLinuxProcessFdSummary) -> Self {
        SBP::MsgLinuxProcessFdSummary(msg)
    }
}
impl From<MsgLinuxCpuState> for SBP {
    fn from(msg: MsgLinuxCpuState) -> Self {
        SBP::MsgLinuxCpuState(msg)
    }
}
impl From<MsgLinuxMemState> for SBP {
    fn from(msg: MsgLinuxMemState) -> Self {
        SBP::MsgLinuxMemState(msg)
    }
}
impl From<MsgLinuxSysState> for SBP {
    fn from(msg: MsgLinuxSysState) -> Self {
        SBP::MsgLinuxSysState(msg)
    }
}
impl From<MsgStartup> for SBP {
    fn from(msg: MsgStartup) -> Self {
        SBP::MsgStartup(msg)
    }
}
impl From<MsgDgnssStatus> for SBP {
    fn from(msg: MsgDgnssStatus) -> Self {
        SBP::MsgDgnssStatus(msg)
    }
}
impl From<MsgInsStatus> for SBP {
    fn from(msg: MsgInsStatus) -> Self {
        SBP::MsgInsStatus(msg)
    }
}
impl From<MsgCsacTelemetry> for SBP {
    fn from(msg: MsgCsacTelemetry) -> Self {
        SBP::MsgCsacTelemetry(msg)
    }
}
impl From<MsgCsacTelemetryLabels> for SBP {
    fn from(msg: MsgCsacTelemetryLabels) -> Self {
        SBP::MsgCsacTelemetryLabels(msg)
    }
}
impl From<MsgInsUpdates> for SBP {
    fn from(msg: MsgInsUpdates) -> Self {
        SBP::MsgInsUpdates(msg)
    }
}
impl From<MsgGnssTimeOffset> for SBP {
    fn from(msg: MsgGnssTimeOffset) -> Self {
        SBP::MsgGnssTimeOffset(msg)
    }
}
impl From<MsgPpsTime> for SBP {
    fn from(msg: MsgPpsTime) -> Self {
        SBP::MsgPpsTime(msg)
    }
}
impl From<MsgGroupMeta> for SBP {
    fn from(msg: MsgGroupMeta) -> Self {
        SBP::MsgGroupMeta(msg)
    }
}
impl From<MsgSolnMeta> for SBP {
    fn from(msg: MsgSolnMeta) -> Self {
        SBP::MsgSolnMeta(msg)
    }
}
impl From<MsgSolnMetaDepA> for SBP {
    fn from(msg: MsgSolnMetaDepA) -> Self {
        SBP::MsgSolnMetaDepA(msg)
    }
}
impl From<MsgStatusReport> for SBP {
    fn from(msg: MsgStatusReport) -> Self {
        SBP::MsgStatusReport(msg)
    }
}
impl From<MsgHeartbeat> for SBP {
    fn from(msg: MsgHeartbeat) -> Self {
        SBP::MsgHeartbeat(msg)
    }
}

impl From<Unknown> for SBP {
    fn from(msg: Unknown) -> Self {
        SBP::Unknown(msg)
    }
}
