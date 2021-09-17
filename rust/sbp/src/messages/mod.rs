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
use self::navigation::MsgBaselineEcef;
use self::navigation::MsgBaselineEcefDepA;
use self::navigation::MsgBaselineHeadingDepA;
use self::navigation::MsgBaselineNed;
use self::navigation::MsgBaselineNedDepA;
use self::navigation::MsgDops;
use self::navigation::MsgDopsDepA;
use self::navigation::MsgGpsTime;
use self::navigation::MsgGpsTimeDepA;
use self::navigation::MsgGpsTimeGnss;
use self::navigation::MsgPosEcef;
use self::navigation::MsgPosEcefCov;
use self::navigation::MsgPosEcefCovGnss;
use self::navigation::MsgPosEcefDepA;
use self::navigation::MsgPosEcefGnss;
use self::navigation::MsgPosLlh;
use self::navigation::MsgPosLlhAcc;
use self::navigation::MsgPosLlhCov;
use self::navigation::MsgPosLlhCovGnss;
use self::navigation::MsgPosLlhDepA;
use self::navigation::MsgPosLlhGnss;
use self::navigation::MsgProtectionLevel;
use self::navigation::MsgProtectionLevelDepA;
use self::navigation::MsgUtcTime;
use self::navigation::MsgUtcTimeGnss;
use self::navigation::MsgVelBody;
use self::navigation::MsgVelEcef;
use self::navigation::MsgVelEcefCov;
use self::navigation::MsgVelEcefCovGnss;
use self::navigation::MsgVelEcefDepA;
use self::navigation::MsgVelEcefGnss;
use self::navigation::MsgVelNed;
use self::navigation::MsgVelNedCov;
use self::navigation::MsgVelNedCovGnss;
use self::navigation::MsgVelNedDepA;
use self::navigation::MsgVelNedGnss;
use self::ndb::MsgNdbEvent;
use self::observation::MsgAlmanacGlo;
use self::observation::MsgAlmanacGloDep;
use self::observation::MsgAlmanacGps;
use self::observation::MsgAlmanacGpsDep;
use self::observation::MsgBasePosEcef;
use self::observation::MsgBasePosLlh;
use self::observation::MsgEphemerisBds;
use self::observation::MsgEphemerisDepA;
use self::observation::MsgEphemerisDepB;
use self::observation::MsgEphemerisDepC;
use self::observation::MsgEphemerisDepD;
use self::observation::MsgEphemerisGal;
use self::observation::MsgEphemerisGalDepA;
use self::observation::MsgEphemerisGlo;
use self::observation::MsgEphemerisGloDepA;
use self::observation::MsgEphemerisGloDepB;
use self::observation::MsgEphemerisGloDepC;
use self::observation::MsgEphemerisGloDepD;
use self::observation::MsgEphemerisGps;
use self::observation::MsgEphemerisGpsDepE;
use self::observation::MsgEphemerisGpsDepF;
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
use self::observation::MsgSvConfigurationGpsDep;
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

pub trait SbpMessage: SbpSerialize {
    fn message_name(&self) -> &'static str;
    fn message_type(&self) -> u16;
    fn sender_id(&self) -> Option<u16>;
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
    SbpMessage + std::convert::TryFrom<Sbp, Error = TryFromSbpError> + Clone + Sized
{
    const MESSAGE_TYPE: u16;
    const MESSAGE_NAME: &'static str;
}

#[derive(Debug, Clone)]
pub struct TryFromSbpError;

impl std::fmt::Display for TryFromSbpError {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        write!(f, "invalid message type for conversion")
    }
}

impl std::error::Error for TryFromSbpError {}

#[cfg_attr(feature = "sbp_serde", derive(serde::Serialize), serde(untagged))]
#[derive(Debug, Clone)]
#[non_exhaustive]
pub enum Sbp {
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
    MsgBasePosLlh(MsgBasePosLlh),
    MsgObsDepA(MsgObsDepA),
    MsgEphemerisDepB(MsgEphemerisDepB),
    MsgEphemerisDepC(MsgEphemerisDepC),
    MsgBasePosEcef(MsgBasePosEcef),
    MsgObsDepC(MsgObsDepC),
    MsgObs(MsgObs),
    MsgSpecanDep(MsgSpecanDep),
    MsgSpecan(MsgSpecan),
    MsgMeasurementState(MsgMeasurementState),
    MsgSetTime(MsgSetTime),
    MsgAlmanac(MsgAlmanac),
    MsgAlmanacGpsDep(MsgAlmanacGpsDep),
    MsgAlmanacGloDep(MsgAlmanacGloDep),
    MsgAlmanacGps(MsgAlmanacGps),
    MsgAlmanacGlo(MsgAlmanacGlo),
    MsgGloBiases(MsgGloBiases),
    MsgEphemerisDepD(MsgEphemerisDepD),
    MsgEphemerisGpsDepE(MsgEphemerisGpsDepE),
    MsgEphemerisSbasDepA(MsgEphemerisSbasDepA),
    MsgEphemerisGloDepA(MsgEphemerisGloDepA),
    MsgEphemerisSbasDepB(MsgEphemerisSbasDepB),
    MsgEphemerisGloDepB(MsgEphemerisGloDepB),
    MsgEphemerisGpsDepF(MsgEphemerisGpsDepF),
    MsgEphemerisGloDepC(MsgEphemerisGloDepC),
    MsgEphemerisGloDepD(MsgEphemerisGloDepD),
    MsgEphemerisBds(MsgEphemerisBds),
    MsgEphemerisGps(MsgEphemerisGps),
    MsgEphemerisGlo(MsgEphemerisGlo),
    MsgEphemerisSbas(MsgEphemerisSbas),
    MsgEphemerisGal(MsgEphemerisGal),
    MsgEphemerisQzss(MsgEphemerisQzss),
    MsgIono(MsgIono),
    MsgSvConfigurationGpsDep(MsgSvConfigurationGpsDep),
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
    MsgGpsTimeDepA(MsgGpsTimeDepA),
    MsgExtEvent(MsgExtEvent),
    MsgGpsTime(MsgGpsTime),
    MsgUtcTime(MsgUtcTime),
    MsgGpsTimeGnss(MsgGpsTimeGnss),
    MsgUtcTimeGnss(MsgUtcTimeGnss),
    MsgSettingsRegisterResp(MsgSettingsRegisterResp),
    MsgPosEcefDepA(MsgPosEcefDepA),
    MsgPosLlhDepA(MsgPosLlhDepA),
    MsgBaselineEcefDepA(MsgBaselineEcefDepA),
    MsgBaselineNedDepA(MsgBaselineNedDepA),
    MsgVelEcefDepA(MsgVelEcefDepA),
    MsgVelNedDepA(MsgVelNedDepA),
    MsgDopsDepA(MsgDopsDepA),
    MsgBaselineHeadingDepA(MsgBaselineHeadingDepA),
    MsgDops(MsgDops),
    MsgPosEcef(MsgPosEcef),
    MsgPosLlh(MsgPosLlh),
    MsgBaselineEcef(MsgBaselineEcef),
    MsgBaselineNed(MsgBaselineNed),
    MsgVelEcef(MsgVelEcef),
    MsgVelNed(MsgVelNed),
    MsgBaselineHeading(MsgBaselineHeading),
    MsgAgeCorrections(MsgAgeCorrections),
    MsgPosLlhCov(MsgPosLlhCov),
    MsgVelNedCov(MsgVelNedCov),
    MsgVelBody(MsgVelBody),
    MsgPosEcefCov(MsgPosEcefCov),
    MsgVelEcefCov(MsgVelEcefCov),
    MsgProtectionLevelDepA(MsgProtectionLevelDepA),
    MsgProtectionLevel(MsgProtectionLevel),
    MsgPosLlhAcc(MsgPosLlhAcc),
    MsgOrientQuat(MsgOrientQuat),
    MsgOrientEuler(MsgOrientEuler),
    MsgAngularRate(MsgAngularRate),
    MsgPosEcefGnss(MsgPosEcefGnss),
    MsgPosLlhGnss(MsgPosLlhGnss),
    MsgVelEcefGnss(MsgVelEcefGnss),
    MsgVelNedGnss(MsgVelNedGnss),
    MsgPosLlhCovGnss(MsgPosLlhCovGnss),
    MsgVelNedCovGnss(MsgVelNedCovGnss),
    MsgPosEcefCovGnss(MsgPosEcefCovGnss),
    MsgVelEcefCovGnss(MsgVelEcefCovGnss),
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

impl Sbp {
    pub fn parse(msg_id: u16, sender_id: u16, payload: &mut &[u8]) -> Result<Sbp, crate::Error> {
        match msg_id {
            16 => {
                let mut msg = MsgPrintDep::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgPrintDep(msg))
            }
            17 => {
                let mut msg = MsgTrackingStateDetailedDep::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgTrackingStateDetailedDep(msg))
            }
            19 => {
                let mut msg = MsgTrackingStateDepB::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgTrackingStateDepB(msg))
            }
            20 => {
                let mut msg = MsgAcqResultDepB::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgAcqResultDepB(msg))
            }
            21 => {
                let mut msg = MsgAcqResultDepA::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgAcqResultDepA(msg))
            }
            22 => {
                let mut msg = MsgTrackingStateDepA::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgTrackingStateDepA(msg))
            }
            23 => {
                let mut msg = MsgThreadState::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgThreadState(msg))
            }
            24 => {
                let mut msg = MsgUartStateDepa::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgUartStateDepa(msg))
            }
            25 => {
                let mut msg = MsgIarState::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgIarState(msg))
            }
            26 => {
                let mut msg = MsgEphemerisDepA::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgEphemerisDepA(msg))
            }
            27 => {
                let mut msg = MsgMaskSatelliteDep::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgMaskSatelliteDep(msg))
            }
            28 => {
                let mut msg = MsgTrackingIqDepA::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgTrackingIqDepA(msg))
            }
            29 => {
                let mut msg = MsgUartState::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgUartState(msg))
            }
            30 => {
                let mut msg = MsgAcqSvProfileDep::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgAcqSvProfileDep(msg))
            }
            31 => {
                let mut msg = MsgAcqResultDepC::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgAcqResultDepC(msg))
            }
            33 => {
                let mut msg = MsgTrackingStateDetailedDepA::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgTrackingStateDetailedDepA(msg))
            }
            34 => {
                let mut msg = MsgResetFilters::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgResetFilters(msg))
            }
            35 => {
                let mut msg = MsgInitBaseDep::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgInitBaseDep(msg))
            }
            43 => {
                let mut msg = MsgMaskSatellite::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgMaskSatellite(msg))
            }
            44 => {
                let mut msg = MsgTrackingIqDepB::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgTrackingIqDepB(msg))
            }
            45 => {
                let mut msg = MsgTrackingIq::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgTrackingIq(msg))
            }
            46 => {
                let mut msg = MsgAcqSvProfile::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgAcqSvProfile(msg))
            }
            47 => {
                let mut msg = MsgAcqResult::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgAcqResult(msg))
            }
            65 => {
                let mut msg = MsgTrackingState::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgTrackingState(msg))
            }
            67 => {
                let mut msg = MsgObsDepB::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgObsDepB(msg))
            }
            68 => {
                let mut msg = MsgBasePosLlh::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgBasePosLlh(msg))
            }
            69 => {
                let mut msg = MsgObsDepA::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgObsDepA(msg))
            }
            70 => {
                let mut msg = MsgEphemerisDepB::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgEphemerisDepB(msg))
            }
            71 => {
                let mut msg = MsgEphemerisDepC::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgEphemerisDepC(msg))
            }
            72 => {
                let mut msg = MsgBasePosEcef::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgBasePosEcef(msg))
            }
            73 => {
                let mut msg = MsgObsDepC::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgObsDepC(msg))
            }
            74 => {
                let mut msg = MsgObs::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgObs(msg))
            }
            80 => {
                let mut msg = MsgSpecanDep::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgSpecanDep(msg))
            }
            81 => {
                let mut msg = MsgSpecan::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgSpecan(msg))
            }
            97 => {
                let mut msg = MsgMeasurementState::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgMeasurementState(msg))
            }
            104 => {
                let mut msg = MsgSetTime::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgSetTime(msg))
            }
            105 => {
                let mut msg = MsgAlmanac::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgAlmanac(msg))
            }
            112 => {
                let mut msg = MsgAlmanacGpsDep::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgAlmanacGpsDep(msg))
            }
            113 => {
                let mut msg = MsgAlmanacGloDep::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgAlmanacGloDep(msg))
            }
            114 => {
                let mut msg = MsgAlmanacGps::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgAlmanacGps(msg))
            }
            115 => {
                let mut msg = MsgAlmanacGlo::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgAlmanacGlo(msg))
            }
            117 => {
                let mut msg = MsgGloBiases::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgGloBiases(msg))
            }
            128 => {
                let mut msg = MsgEphemerisDepD::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgEphemerisDepD(msg))
            }
            129 => {
                let mut msg = MsgEphemerisGpsDepE::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgEphemerisGpsDepE(msg))
            }
            130 => {
                let mut msg = MsgEphemerisSbasDepA::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgEphemerisSbasDepA(msg))
            }
            131 => {
                let mut msg = MsgEphemerisGloDepA::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgEphemerisGloDepA(msg))
            }
            132 => {
                let mut msg = MsgEphemerisSbasDepB::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgEphemerisSbasDepB(msg))
            }
            133 => {
                let mut msg = MsgEphemerisGloDepB::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgEphemerisGloDepB(msg))
            }
            134 => {
                let mut msg = MsgEphemerisGpsDepF::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgEphemerisGpsDepF(msg))
            }
            135 => {
                let mut msg = MsgEphemerisGloDepC::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgEphemerisGloDepC(msg))
            }
            136 => {
                let mut msg = MsgEphemerisGloDepD::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgEphemerisGloDepD(msg))
            }
            137 => {
                let mut msg = MsgEphemerisBds::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgEphemerisBds(msg))
            }
            138 => {
                let mut msg = MsgEphemerisGps::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgEphemerisGps(msg))
            }
            139 => {
                let mut msg = MsgEphemerisGlo::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgEphemerisGlo(msg))
            }
            140 => {
                let mut msg = MsgEphemerisSbas::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgEphemerisSbas(msg))
            }
            141 => {
                let mut msg = MsgEphemerisGal::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgEphemerisGal(msg))
            }
            142 => {
                let mut msg = MsgEphemerisQzss::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgEphemerisQzss(msg))
            }
            144 => {
                let mut msg = MsgIono::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgIono(msg))
            }
            145 => {
                let mut msg = MsgSvConfigurationGpsDep::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgSvConfigurationGpsDep(msg))
            }
            146 => {
                let mut msg = MsgGroupDelayDepA::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgGroupDelayDepA(msg))
            }
            147 => {
                let mut msg = MsgGroupDelayDepB::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgGroupDelayDepB(msg))
            }
            148 => {
                let mut msg = MsgGroupDelay::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgGroupDelay(msg))
            }
            149 => {
                let mut msg = MsgEphemerisGalDepA::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgEphemerisGalDepA(msg))
            }
            150 => {
                let mut msg = MsgGnssCapb::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgGnssCapb(msg))
            }
            151 => {
                let mut msg = MsgSvAzEl::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgSvAzEl(msg))
            }
            160 => {
                let mut msg = MsgSettingsWrite::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgSettingsWrite(msg))
            }
            161 => {
                let mut msg = MsgSettingsSave::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgSettingsSave(msg))
            }
            162 => {
                let mut msg = MsgSettingsReadByIndexReq::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgSettingsReadByIndexReq(msg))
            }
            163 => {
                let mut msg = MsgFileioReadResp::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgFileioReadResp(msg))
            }
            164 => {
                let mut msg = MsgSettingsReadReq::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgSettingsReadReq(msg))
            }
            165 => {
                let mut msg = MsgSettingsReadResp::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgSettingsReadResp(msg))
            }
            166 => {
                let mut msg = MsgSettingsReadByIndexDone::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgSettingsReadByIndexDone(msg))
            }
            167 => {
                let mut msg = MsgSettingsReadByIndexResp::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgSettingsReadByIndexResp(msg))
            }
            168 => {
                let mut msg = MsgFileioReadReq::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgFileioReadReq(msg))
            }
            169 => {
                let mut msg = MsgFileioReadDirReq::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgFileioReadDirReq(msg))
            }
            170 => {
                let mut msg = MsgFileioReadDirResp::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgFileioReadDirResp(msg))
            }
            171 => {
                let mut msg = MsgFileioWriteResp::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgFileioWriteResp(msg))
            }
            172 => {
                let mut msg = MsgFileioRemove::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgFileioRemove(msg))
            }
            173 => {
                let mut msg = MsgFileioWriteReq::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgFileioWriteReq(msg))
            }
            174 => {
                let mut msg = MsgSettingsRegister::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgSettingsRegister(msg))
            }
            175 => {
                let mut msg = MsgSettingsWriteResp::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgSettingsWriteResp(msg))
            }
            176 => {
                let mut msg = MsgBootloaderHandshakeDepA::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgBootloaderHandshakeDepA(msg))
            }
            177 => {
                let mut msg = MsgBootloaderJumpToApp::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgBootloaderJumpToApp(msg))
            }
            178 => {
                let mut msg = MsgResetDep::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgResetDep(msg))
            }
            179 => {
                let mut msg = MsgBootloaderHandshakeReq::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgBootloaderHandshakeReq(msg))
            }
            180 => {
                let mut msg = MsgBootloaderHandshakeResp::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgBootloaderHandshakeResp(msg))
            }
            181 => {
                let mut msg = MsgDeviceMonitor::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgDeviceMonitor(msg))
            }
            182 => {
                let mut msg = MsgReset::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgReset(msg))
            }
            184 => {
                let mut msg = MsgCommandReq::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgCommandReq(msg))
            }
            185 => {
                let mut msg = MsgCommandResp::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgCommandResp(msg))
            }
            186 => {
                let mut msg = MsgNetworkStateReq::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgNetworkStateReq(msg))
            }
            187 => {
                let mut msg = MsgNetworkStateResp::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgNetworkStateResp(msg))
            }
            188 => {
                let mut msg = MsgCommandOutput::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgCommandOutput(msg))
            }
            189 => {
                let mut msg = MsgNetworkBandwidthUsage::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgNetworkBandwidthUsage(msg))
            }
            190 => {
                let mut msg = MsgCellModemStatus::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgCellModemStatus(msg))
            }
            191 => {
                let mut msg = MsgFrontEndGain::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgFrontEndGain(msg))
            }
            192 => {
                let mut msg = MsgCwResults::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgCwResults(msg))
            }
            193 => {
                let mut msg = MsgCwStart::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgCwStart(msg))
            }
            221 => {
                let mut msg = MsgNapDeviceDnaResp::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgNapDeviceDnaResp(msg))
            }
            222 => {
                let mut msg = MsgNapDeviceDnaReq::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgNapDeviceDnaReq(msg))
            }
            224 => {
                let mut msg = MsgFlashDone::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgFlashDone(msg))
            }
            225 => {
                let mut msg = MsgFlashReadResp::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgFlashReadResp(msg))
            }
            226 => {
                let mut msg = MsgFlashErase::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgFlashErase(msg))
            }
            227 => {
                let mut msg = MsgStmFlashLockSector::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgStmFlashLockSector(msg))
            }
            228 => {
                let mut msg = MsgStmFlashUnlockSector::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgStmFlashUnlockSector(msg))
            }
            229 => {
                let mut msg = MsgStmUniqueIdResp::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgStmUniqueIdResp(msg))
            }
            230 => {
                let mut msg = MsgFlashProgram::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgFlashProgram(msg))
            }
            231 => {
                let mut msg = MsgFlashReadReq::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgFlashReadReq(msg))
            }
            232 => {
                let mut msg = MsgStmUniqueIdReq::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgStmUniqueIdReq(msg))
            }
            243 => {
                let mut msg = MsgM25FlashWriteStatus::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgM25FlashWriteStatus(msg))
            }
            256 => {
                let mut msg = MsgGpsTimeDepA::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgGpsTimeDepA(msg))
            }
            257 => {
                let mut msg = MsgExtEvent::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgExtEvent(msg))
            }
            258 => {
                let mut msg = MsgGpsTime::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgGpsTime(msg))
            }
            259 => {
                let mut msg = MsgUtcTime::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgUtcTime(msg))
            }
            260 => {
                let mut msg = MsgGpsTimeGnss::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgGpsTimeGnss(msg))
            }
            261 => {
                let mut msg = MsgUtcTimeGnss::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgUtcTimeGnss(msg))
            }
            431 => {
                let mut msg = MsgSettingsRegisterResp::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgSettingsRegisterResp(msg))
            }
            512 => {
                let mut msg = MsgPosEcefDepA::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgPosEcefDepA(msg))
            }
            513 => {
                let mut msg = MsgPosLlhDepA::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgPosLlhDepA(msg))
            }
            514 => {
                let mut msg = MsgBaselineEcefDepA::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgBaselineEcefDepA(msg))
            }
            515 => {
                let mut msg = MsgBaselineNedDepA::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgBaselineNedDepA(msg))
            }
            516 => {
                let mut msg = MsgVelEcefDepA::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgVelEcefDepA(msg))
            }
            517 => {
                let mut msg = MsgVelNedDepA::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgVelNedDepA(msg))
            }
            518 => {
                let mut msg = MsgDopsDepA::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgDopsDepA(msg))
            }
            519 => {
                let mut msg = MsgBaselineHeadingDepA::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgBaselineHeadingDepA(msg))
            }
            520 => {
                let mut msg = MsgDops::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgDops(msg))
            }
            521 => {
                let mut msg = MsgPosEcef::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgPosEcef(msg))
            }
            522 => {
                let mut msg = MsgPosLlh::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgPosLlh(msg))
            }
            523 => {
                let mut msg = MsgBaselineEcef::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgBaselineEcef(msg))
            }
            524 => {
                let mut msg = MsgBaselineNed::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgBaselineNed(msg))
            }
            525 => {
                let mut msg = MsgVelEcef::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgVelEcef(msg))
            }
            526 => {
                let mut msg = MsgVelNed::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgVelNed(msg))
            }
            527 => {
                let mut msg = MsgBaselineHeading::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgBaselineHeading(msg))
            }
            528 => {
                let mut msg = MsgAgeCorrections::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgAgeCorrections(msg))
            }
            529 => {
                let mut msg = MsgPosLlhCov::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgPosLlhCov(msg))
            }
            530 => {
                let mut msg = MsgVelNedCov::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgVelNedCov(msg))
            }
            531 => {
                let mut msg = MsgVelBody::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgVelBody(msg))
            }
            532 => {
                let mut msg = MsgPosEcefCov::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgPosEcefCov(msg))
            }
            533 => {
                let mut msg = MsgVelEcefCov::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgVelEcefCov(msg))
            }
            534 => {
                let mut msg = MsgProtectionLevelDepA::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgProtectionLevelDepA(msg))
            }
            535 => {
                let mut msg = MsgProtectionLevel::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgProtectionLevel(msg))
            }
            536 => {
                let mut msg = MsgPosLlhAcc::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgPosLlhAcc(msg))
            }
            544 => {
                let mut msg = MsgOrientQuat::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgOrientQuat(msg))
            }
            545 => {
                let mut msg = MsgOrientEuler::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgOrientEuler(msg))
            }
            546 => {
                let mut msg = MsgAngularRate::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgAngularRate(msg))
            }
            553 => {
                let mut msg = MsgPosEcefGnss::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgPosEcefGnss(msg))
            }
            554 => {
                let mut msg = MsgPosLlhGnss::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgPosLlhGnss(msg))
            }
            557 => {
                let mut msg = MsgVelEcefGnss::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgVelEcefGnss(msg))
            }
            558 => {
                let mut msg = MsgVelNedGnss::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgVelNedGnss(msg))
            }
            561 => {
                let mut msg = MsgPosLlhCovGnss::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgPosLlhCovGnss(msg))
            }
            562 => {
                let mut msg = MsgVelNedCovGnss::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgVelNedCovGnss(msg))
            }
            564 => {
                let mut msg = MsgPosEcefCovGnss::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgPosEcefCovGnss(msg))
            }
            565 => {
                let mut msg = MsgVelEcefCovGnss::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgVelEcefCovGnss(msg))
            }
            1024 => {
                let mut msg = MsgNdbEvent::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgNdbEvent(msg))
            }
            1025 => {
                let mut msg = MsgLog::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgLog(msg))
            }
            1026 => {
                let mut msg = MsgFwd::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgFwd(msg))
            }
            1500 => {
                let mut msg = MsgSsrOrbitClockDepA::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgSsrOrbitClockDepA(msg))
            }
            1501 => {
                let mut msg = MsgSsrOrbitClock::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgSsrOrbitClock(msg))
            }
            1505 => {
                let mut msg = MsgSsrCodeBiases::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgSsrCodeBiases(msg))
            }
            1510 => {
                let mut msg = MsgSsrPhaseBiases::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgSsrPhaseBiases(msg))
            }
            1515 => {
                let mut msg = MsgSsrStecCorrectionDepA::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgSsrStecCorrectionDepA(msg))
            }
            1520 => {
                let mut msg = MsgSsrGriddedCorrectionNoStdDepA::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgSsrGriddedCorrectionNoStdDepA(msg))
            }
            1525 => {
                let mut msg = MsgSsrGridDefinitionDepA::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgSsrGridDefinitionDepA(msg))
            }
            1526 => {
                let mut msg = MsgSsrTileDefinition::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgSsrTileDefinition(msg))
            }
            1530 => {
                let mut msg = MsgSsrGriddedCorrectionDepA::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgSsrGriddedCorrectionDepA(msg))
            }
            1531 => {
                let mut msg = MsgSsrStecCorrection::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgSsrStecCorrection(msg))
            }
            1532 => {
                let mut msg = MsgSsrGriddedCorrection::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgSsrGriddedCorrection(msg))
            }
            1540 => {
                let mut msg = MsgSsrSatelliteApc::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgSsrSatelliteApc(msg))
            }
            1600 => {
                let mut msg = MsgOsr::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgOsr(msg))
            }
            2048 => {
                let mut msg = MsgUserData::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgUserData(msg))
            }
            2304 => {
                let mut msg = MsgImuRaw::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgImuRaw(msg))
            }
            2305 => {
                let mut msg = MsgImuAux::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgImuAux(msg))
            }
            2306 => {
                let mut msg = MsgMagRaw::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgMagRaw(msg))
            }
            2307 => {
                let mut msg = MsgOdometry::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgOdometry(msg))
            }
            2308 => {
                let mut msg = MsgWheeltick::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgWheeltick(msg))
            }
            4097 => {
                let mut msg = MsgFileioConfigReq::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgFileioConfigReq(msg))
            }
            4098 => {
                let mut msg = MsgFileioConfigResp::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgFileioConfigResp(msg))
            }
            30583 => {
                let mut msg = MsgSbasRaw::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgSbasRaw(msg))
            }
            32512 => {
                let mut msg = MsgLinuxCpuStateDepA::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgLinuxCpuStateDepA(msg))
            }
            32513 => {
                let mut msg = MsgLinuxMemStateDepA::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgLinuxMemStateDepA(msg))
            }
            32514 => {
                let mut msg = MsgLinuxSysStateDepA::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgLinuxSysStateDepA(msg))
            }
            32515 => {
                let mut msg = MsgLinuxProcessSocketCounts::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgLinuxProcessSocketCounts(msg))
            }
            32516 => {
                let mut msg = MsgLinuxProcessSocketQueues::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgLinuxProcessSocketQueues(msg))
            }
            32517 => {
                let mut msg = MsgLinuxSocketUsage::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgLinuxSocketUsage(msg))
            }
            32518 => {
                let mut msg = MsgLinuxProcessFdCount::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgLinuxProcessFdCount(msg))
            }
            32519 => {
                let mut msg = MsgLinuxProcessFdSummary::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgLinuxProcessFdSummary(msg))
            }
            32520 => {
                let mut msg = MsgLinuxCpuState::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgLinuxCpuState(msg))
            }
            32521 => {
                let mut msg = MsgLinuxMemState::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgLinuxMemState(msg))
            }
            32522 => {
                let mut msg = MsgLinuxSysState::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgLinuxSysState(msg))
            }
            65280 => {
                let mut msg = MsgStartup::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgStartup(msg))
            }
            65282 => {
                let mut msg = MsgDgnssStatus::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgDgnssStatus(msg))
            }
            65283 => {
                let mut msg = MsgInsStatus::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgInsStatus(msg))
            }
            65284 => {
                let mut msg = MsgCsacTelemetry::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgCsacTelemetry(msg))
            }
            65285 => {
                let mut msg = MsgCsacTelemetryLabels::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgCsacTelemetryLabels(msg))
            }
            65286 => {
                let mut msg = MsgInsUpdates::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgInsUpdates(msg))
            }
            65287 => {
                let mut msg = MsgGnssTimeOffset::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgGnssTimeOffset(msg))
            }
            65288 => {
                let mut msg = MsgPpsTime::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgPpsTime(msg))
            }
            65290 => {
                let mut msg = MsgGroupMeta::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgGroupMeta(msg))
            }
            65294 => {
                let mut msg = MsgSolnMeta::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgSolnMeta(msg))
            }
            65295 => {
                let mut msg = MsgSolnMetaDepA::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgSolnMetaDepA(msg))
            }
            65534 => {
                let mut msg = MsgStatusReport::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgStatusReport(msg))
            }
            65535 => {
                let mut msg = MsgHeartbeat::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgHeartbeat(msg))
            }
            _ => Ok(Sbp::Unknown(Unknown {
                msg_id: msg_id,
                sender_id: sender_id,
                payload: payload.to_vec(),
            })),
        }
    }
}

impl crate::SbpMessage for Sbp {
    fn message_name(&self) -> &'static str {
        match self {
            Sbp::MsgPrintDep(msg) => msg.message_name(),
            Sbp::MsgTrackingStateDetailedDep(msg) => msg.message_name(),
            Sbp::MsgTrackingStateDepB(msg) => msg.message_name(),
            Sbp::MsgAcqResultDepB(msg) => msg.message_name(),
            Sbp::MsgAcqResultDepA(msg) => msg.message_name(),
            Sbp::MsgTrackingStateDepA(msg) => msg.message_name(),
            Sbp::MsgThreadState(msg) => msg.message_name(),
            Sbp::MsgUartStateDepa(msg) => msg.message_name(),
            Sbp::MsgIarState(msg) => msg.message_name(),
            Sbp::MsgEphemerisDepA(msg) => msg.message_name(),
            Sbp::MsgMaskSatelliteDep(msg) => msg.message_name(),
            Sbp::MsgTrackingIqDepA(msg) => msg.message_name(),
            Sbp::MsgUartState(msg) => msg.message_name(),
            Sbp::MsgAcqSvProfileDep(msg) => msg.message_name(),
            Sbp::MsgAcqResultDepC(msg) => msg.message_name(),
            Sbp::MsgTrackingStateDetailedDepA(msg) => msg.message_name(),
            Sbp::MsgResetFilters(msg) => msg.message_name(),
            Sbp::MsgInitBaseDep(msg) => msg.message_name(),
            Sbp::MsgMaskSatellite(msg) => msg.message_name(),
            Sbp::MsgTrackingIqDepB(msg) => msg.message_name(),
            Sbp::MsgTrackingIq(msg) => msg.message_name(),
            Sbp::MsgAcqSvProfile(msg) => msg.message_name(),
            Sbp::MsgAcqResult(msg) => msg.message_name(),
            Sbp::MsgTrackingState(msg) => msg.message_name(),
            Sbp::MsgObsDepB(msg) => msg.message_name(),
            Sbp::MsgBasePosLlh(msg) => msg.message_name(),
            Sbp::MsgObsDepA(msg) => msg.message_name(),
            Sbp::MsgEphemerisDepB(msg) => msg.message_name(),
            Sbp::MsgEphemerisDepC(msg) => msg.message_name(),
            Sbp::MsgBasePosEcef(msg) => msg.message_name(),
            Sbp::MsgObsDepC(msg) => msg.message_name(),
            Sbp::MsgObs(msg) => msg.message_name(),
            Sbp::MsgSpecanDep(msg) => msg.message_name(),
            Sbp::MsgSpecan(msg) => msg.message_name(),
            Sbp::MsgMeasurementState(msg) => msg.message_name(),
            Sbp::MsgSetTime(msg) => msg.message_name(),
            Sbp::MsgAlmanac(msg) => msg.message_name(),
            Sbp::MsgAlmanacGpsDep(msg) => msg.message_name(),
            Sbp::MsgAlmanacGloDep(msg) => msg.message_name(),
            Sbp::MsgAlmanacGps(msg) => msg.message_name(),
            Sbp::MsgAlmanacGlo(msg) => msg.message_name(),
            Sbp::MsgGloBiases(msg) => msg.message_name(),
            Sbp::MsgEphemerisDepD(msg) => msg.message_name(),
            Sbp::MsgEphemerisGpsDepE(msg) => msg.message_name(),
            Sbp::MsgEphemerisSbasDepA(msg) => msg.message_name(),
            Sbp::MsgEphemerisGloDepA(msg) => msg.message_name(),
            Sbp::MsgEphemerisSbasDepB(msg) => msg.message_name(),
            Sbp::MsgEphemerisGloDepB(msg) => msg.message_name(),
            Sbp::MsgEphemerisGpsDepF(msg) => msg.message_name(),
            Sbp::MsgEphemerisGloDepC(msg) => msg.message_name(),
            Sbp::MsgEphemerisGloDepD(msg) => msg.message_name(),
            Sbp::MsgEphemerisBds(msg) => msg.message_name(),
            Sbp::MsgEphemerisGps(msg) => msg.message_name(),
            Sbp::MsgEphemerisGlo(msg) => msg.message_name(),
            Sbp::MsgEphemerisSbas(msg) => msg.message_name(),
            Sbp::MsgEphemerisGal(msg) => msg.message_name(),
            Sbp::MsgEphemerisQzss(msg) => msg.message_name(),
            Sbp::MsgIono(msg) => msg.message_name(),
            Sbp::MsgSvConfigurationGpsDep(msg) => msg.message_name(),
            Sbp::MsgGroupDelayDepA(msg) => msg.message_name(),
            Sbp::MsgGroupDelayDepB(msg) => msg.message_name(),
            Sbp::MsgGroupDelay(msg) => msg.message_name(),
            Sbp::MsgEphemerisGalDepA(msg) => msg.message_name(),
            Sbp::MsgGnssCapb(msg) => msg.message_name(),
            Sbp::MsgSvAzEl(msg) => msg.message_name(),
            Sbp::MsgSettingsWrite(msg) => msg.message_name(),
            Sbp::MsgSettingsSave(msg) => msg.message_name(),
            Sbp::MsgSettingsReadByIndexReq(msg) => msg.message_name(),
            Sbp::MsgFileioReadResp(msg) => msg.message_name(),
            Sbp::MsgSettingsReadReq(msg) => msg.message_name(),
            Sbp::MsgSettingsReadResp(msg) => msg.message_name(),
            Sbp::MsgSettingsReadByIndexDone(msg) => msg.message_name(),
            Sbp::MsgSettingsReadByIndexResp(msg) => msg.message_name(),
            Sbp::MsgFileioReadReq(msg) => msg.message_name(),
            Sbp::MsgFileioReadDirReq(msg) => msg.message_name(),
            Sbp::MsgFileioReadDirResp(msg) => msg.message_name(),
            Sbp::MsgFileioWriteResp(msg) => msg.message_name(),
            Sbp::MsgFileioRemove(msg) => msg.message_name(),
            Sbp::MsgFileioWriteReq(msg) => msg.message_name(),
            Sbp::MsgSettingsRegister(msg) => msg.message_name(),
            Sbp::MsgSettingsWriteResp(msg) => msg.message_name(),
            Sbp::MsgBootloaderHandshakeDepA(msg) => msg.message_name(),
            Sbp::MsgBootloaderJumpToApp(msg) => msg.message_name(),
            Sbp::MsgResetDep(msg) => msg.message_name(),
            Sbp::MsgBootloaderHandshakeReq(msg) => msg.message_name(),
            Sbp::MsgBootloaderHandshakeResp(msg) => msg.message_name(),
            Sbp::MsgDeviceMonitor(msg) => msg.message_name(),
            Sbp::MsgReset(msg) => msg.message_name(),
            Sbp::MsgCommandReq(msg) => msg.message_name(),
            Sbp::MsgCommandResp(msg) => msg.message_name(),
            Sbp::MsgNetworkStateReq(msg) => msg.message_name(),
            Sbp::MsgNetworkStateResp(msg) => msg.message_name(),
            Sbp::MsgCommandOutput(msg) => msg.message_name(),
            Sbp::MsgNetworkBandwidthUsage(msg) => msg.message_name(),
            Sbp::MsgCellModemStatus(msg) => msg.message_name(),
            Sbp::MsgFrontEndGain(msg) => msg.message_name(),
            Sbp::MsgCwResults(msg) => msg.message_name(),
            Sbp::MsgCwStart(msg) => msg.message_name(),
            Sbp::MsgNapDeviceDnaResp(msg) => msg.message_name(),
            Sbp::MsgNapDeviceDnaReq(msg) => msg.message_name(),
            Sbp::MsgFlashDone(msg) => msg.message_name(),
            Sbp::MsgFlashReadResp(msg) => msg.message_name(),
            Sbp::MsgFlashErase(msg) => msg.message_name(),
            Sbp::MsgStmFlashLockSector(msg) => msg.message_name(),
            Sbp::MsgStmFlashUnlockSector(msg) => msg.message_name(),
            Sbp::MsgStmUniqueIdResp(msg) => msg.message_name(),
            Sbp::MsgFlashProgram(msg) => msg.message_name(),
            Sbp::MsgFlashReadReq(msg) => msg.message_name(),
            Sbp::MsgStmUniqueIdReq(msg) => msg.message_name(),
            Sbp::MsgM25FlashWriteStatus(msg) => msg.message_name(),
            Sbp::MsgGpsTimeDepA(msg) => msg.message_name(),
            Sbp::MsgExtEvent(msg) => msg.message_name(),
            Sbp::MsgGpsTime(msg) => msg.message_name(),
            Sbp::MsgUtcTime(msg) => msg.message_name(),
            Sbp::MsgGpsTimeGnss(msg) => msg.message_name(),
            Sbp::MsgUtcTimeGnss(msg) => msg.message_name(),
            Sbp::MsgSettingsRegisterResp(msg) => msg.message_name(),
            Sbp::MsgPosEcefDepA(msg) => msg.message_name(),
            Sbp::MsgPosLlhDepA(msg) => msg.message_name(),
            Sbp::MsgBaselineEcefDepA(msg) => msg.message_name(),
            Sbp::MsgBaselineNedDepA(msg) => msg.message_name(),
            Sbp::MsgVelEcefDepA(msg) => msg.message_name(),
            Sbp::MsgVelNedDepA(msg) => msg.message_name(),
            Sbp::MsgDopsDepA(msg) => msg.message_name(),
            Sbp::MsgBaselineHeadingDepA(msg) => msg.message_name(),
            Sbp::MsgDops(msg) => msg.message_name(),
            Sbp::MsgPosEcef(msg) => msg.message_name(),
            Sbp::MsgPosLlh(msg) => msg.message_name(),
            Sbp::MsgBaselineEcef(msg) => msg.message_name(),
            Sbp::MsgBaselineNed(msg) => msg.message_name(),
            Sbp::MsgVelEcef(msg) => msg.message_name(),
            Sbp::MsgVelNed(msg) => msg.message_name(),
            Sbp::MsgBaselineHeading(msg) => msg.message_name(),
            Sbp::MsgAgeCorrections(msg) => msg.message_name(),
            Sbp::MsgPosLlhCov(msg) => msg.message_name(),
            Sbp::MsgVelNedCov(msg) => msg.message_name(),
            Sbp::MsgVelBody(msg) => msg.message_name(),
            Sbp::MsgPosEcefCov(msg) => msg.message_name(),
            Sbp::MsgVelEcefCov(msg) => msg.message_name(),
            Sbp::MsgProtectionLevelDepA(msg) => msg.message_name(),
            Sbp::MsgProtectionLevel(msg) => msg.message_name(),
            Sbp::MsgPosLlhAcc(msg) => msg.message_name(),
            Sbp::MsgOrientQuat(msg) => msg.message_name(),
            Sbp::MsgOrientEuler(msg) => msg.message_name(),
            Sbp::MsgAngularRate(msg) => msg.message_name(),
            Sbp::MsgPosEcefGnss(msg) => msg.message_name(),
            Sbp::MsgPosLlhGnss(msg) => msg.message_name(),
            Sbp::MsgVelEcefGnss(msg) => msg.message_name(),
            Sbp::MsgVelNedGnss(msg) => msg.message_name(),
            Sbp::MsgPosLlhCovGnss(msg) => msg.message_name(),
            Sbp::MsgVelNedCovGnss(msg) => msg.message_name(),
            Sbp::MsgPosEcefCovGnss(msg) => msg.message_name(),
            Sbp::MsgVelEcefCovGnss(msg) => msg.message_name(),
            Sbp::MsgNdbEvent(msg) => msg.message_name(),
            Sbp::MsgLog(msg) => msg.message_name(),
            Sbp::MsgFwd(msg) => msg.message_name(),
            Sbp::MsgSsrOrbitClockDepA(msg) => msg.message_name(),
            Sbp::MsgSsrOrbitClock(msg) => msg.message_name(),
            Sbp::MsgSsrCodeBiases(msg) => msg.message_name(),
            Sbp::MsgSsrPhaseBiases(msg) => msg.message_name(),
            Sbp::MsgSsrStecCorrectionDepA(msg) => msg.message_name(),
            Sbp::MsgSsrGriddedCorrectionNoStdDepA(msg) => msg.message_name(),
            Sbp::MsgSsrGridDefinitionDepA(msg) => msg.message_name(),
            Sbp::MsgSsrTileDefinition(msg) => msg.message_name(),
            Sbp::MsgSsrGriddedCorrectionDepA(msg) => msg.message_name(),
            Sbp::MsgSsrStecCorrection(msg) => msg.message_name(),
            Sbp::MsgSsrGriddedCorrection(msg) => msg.message_name(),
            Sbp::MsgSsrSatelliteApc(msg) => msg.message_name(),
            Sbp::MsgOsr(msg) => msg.message_name(),
            Sbp::MsgUserData(msg) => msg.message_name(),
            Sbp::MsgImuRaw(msg) => msg.message_name(),
            Sbp::MsgImuAux(msg) => msg.message_name(),
            Sbp::MsgMagRaw(msg) => msg.message_name(),
            Sbp::MsgOdometry(msg) => msg.message_name(),
            Sbp::MsgWheeltick(msg) => msg.message_name(),
            Sbp::MsgFileioConfigReq(msg) => msg.message_name(),
            Sbp::MsgFileioConfigResp(msg) => msg.message_name(),
            Sbp::MsgSbasRaw(msg) => msg.message_name(),
            Sbp::MsgLinuxCpuStateDepA(msg) => msg.message_name(),
            Sbp::MsgLinuxMemStateDepA(msg) => msg.message_name(),
            Sbp::MsgLinuxSysStateDepA(msg) => msg.message_name(),
            Sbp::MsgLinuxProcessSocketCounts(msg) => msg.message_name(),
            Sbp::MsgLinuxProcessSocketQueues(msg) => msg.message_name(),
            Sbp::MsgLinuxSocketUsage(msg) => msg.message_name(),
            Sbp::MsgLinuxProcessFdCount(msg) => msg.message_name(),
            Sbp::MsgLinuxProcessFdSummary(msg) => msg.message_name(),
            Sbp::MsgLinuxCpuState(msg) => msg.message_name(),
            Sbp::MsgLinuxMemState(msg) => msg.message_name(),
            Sbp::MsgLinuxSysState(msg) => msg.message_name(),
            Sbp::MsgStartup(msg) => msg.message_name(),
            Sbp::MsgDgnssStatus(msg) => msg.message_name(),
            Sbp::MsgInsStatus(msg) => msg.message_name(),
            Sbp::MsgCsacTelemetry(msg) => msg.message_name(),
            Sbp::MsgCsacTelemetryLabels(msg) => msg.message_name(),
            Sbp::MsgInsUpdates(msg) => msg.message_name(),
            Sbp::MsgGnssTimeOffset(msg) => msg.message_name(),
            Sbp::MsgPpsTime(msg) => msg.message_name(),
            Sbp::MsgGroupMeta(msg) => msg.message_name(),
            Sbp::MsgSolnMeta(msg) => msg.message_name(),
            Sbp::MsgSolnMetaDepA(msg) => msg.message_name(),
            Sbp::MsgStatusReport(msg) => msg.message_name(),
            Sbp::MsgHeartbeat(msg) => msg.message_name(),
            Sbp::Unknown(msg) => msg.message_name(),
        }
    }

    fn message_type(&self) -> u16 {
        match self {
            Sbp::MsgPrintDep(msg) => msg.message_type(),
            Sbp::MsgTrackingStateDetailedDep(msg) => msg.message_type(),
            Sbp::MsgTrackingStateDepB(msg) => msg.message_type(),
            Sbp::MsgAcqResultDepB(msg) => msg.message_type(),
            Sbp::MsgAcqResultDepA(msg) => msg.message_type(),
            Sbp::MsgTrackingStateDepA(msg) => msg.message_type(),
            Sbp::MsgThreadState(msg) => msg.message_type(),
            Sbp::MsgUartStateDepa(msg) => msg.message_type(),
            Sbp::MsgIarState(msg) => msg.message_type(),
            Sbp::MsgEphemerisDepA(msg) => msg.message_type(),
            Sbp::MsgMaskSatelliteDep(msg) => msg.message_type(),
            Sbp::MsgTrackingIqDepA(msg) => msg.message_type(),
            Sbp::MsgUartState(msg) => msg.message_type(),
            Sbp::MsgAcqSvProfileDep(msg) => msg.message_type(),
            Sbp::MsgAcqResultDepC(msg) => msg.message_type(),
            Sbp::MsgTrackingStateDetailedDepA(msg) => msg.message_type(),
            Sbp::MsgResetFilters(msg) => msg.message_type(),
            Sbp::MsgInitBaseDep(msg) => msg.message_type(),
            Sbp::MsgMaskSatellite(msg) => msg.message_type(),
            Sbp::MsgTrackingIqDepB(msg) => msg.message_type(),
            Sbp::MsgTrackingIq(msg) => msg.message_type(),
            Sbp::MsgAcqSvProfile(msg) => msg.message_type(),
            Sbp::MsgAcqResult(msg) => msg.message_type(),
            Sbp::MsgTrackingState(msg) => msg.message_type(),
            Sbp::MsgObsDepB(msg) => msg.message_type(),
            Sbp::MsgBasePosLlh(msg) => msg.message_type(),
            Sbp::MsgObsDepA(msg) => msg.message_type(),
            Sbp::MsgEphemerisDepB(msg) => msg.message_type(),
            Sbp::MsgEphemerisDepC(msg) => msg.message_type(),
            Sbp::MsgBasePosEcef(msg) => msg.message_type(),
            Sbp::MsgObsDepC(msg) => msg.message_type(),
            Sbp::MsgObs(msg) => msg.message_type(),
            Sbp::MsgSpecanDep(msg) => msg.message_type(),
            Sbp::MsgSpecan(msg) => msg.message_type(),
            Sbp::MsgMeasurementState(msg) => msg.message_type(),
            Sbp::MsgSetTime(msg) => msg.message_type(),
            Sbp::MsgAlmanac(msg) => msg.message_type(),
            Sbp::MsgAlmanacGpsDep(msg) => msg.message_type(),
            Sbp::MsgAlmanacGloDep(msg) => msg.message_type(),
            Sbp::MsgAlmanacGps(msg) => msg.message_type(),
            Sbp::MsgAlmanacGlo(msg) => msg.message_type(),
            Sbp::MsgGloBiases(msg) => msg.message_type(),
            Sbp::MsgEphemerisDepD(msg) => msg.message_type(),
            Sbp::MsgEphemerisGpsDepE(msg) => msg.message_type(),
            Sbp::MsgEphemerisSbasDepA(msg) => msg.message_type(),
            Sbp::MsgEphemerisGloDepA(msg) => msg.message_type(),
            Sbp::MsgEphemerisSbasDepB(msg) => msg.message_type(),
            Sbp::MsgEphemerisGloDepB(msg) => msg.message_type(),
            Sbp::MsgEphemerisGpsDepF(msg) => msg.message_type(),
            Sbp::MsgEphemerisGloDepC(msg) => msg.message_type(),
            Sbp::MsgEphemerisGloDepD(msg) => msg.message_type(),
            Sbp::MsgEphemerisBds(msg) => msg.message_type(),
            Sbp::MsgEphemerisGps(msg) => msg.message_type(),
            Sbp::MsgEphemerisGlo(msg) => msg.message_type(),
            Sbp::MsgEphemerisSbas(msg) => msg.message_type(),
            Sbp::MsgEphemerisGal(msg) => msg.message_type(),
            Sbp::MsgEphemerisQzss(msg) => msg.message_type(),
            Sbp::MsgIono(msg) => msg.message_type(),
            Sbp::MsgSvConfigurationGpsDep(msg) => msg.message_type(),
            Sbp::MsgGroupDelayDepA(msg) => msg.message_type(),
            Sbp::MsgGroupDelayDepB(msg) => msg.message_type(),
            Sbp::MsgGroupDelay(msg) => msg.message_type(),
            Sbp::MsgEphemerisGalDepA(msg) => msg.message_type(),
            Sbp::MsgGnssCapb(msg) => msg.message_type(),
            Sbp::MsgSvAzEl(msg) => msg.message_type(),
            Sbp::MsgSettingsWrite(msg) => msg.message_type(),
            Sbp::MsgSettingsSave(msg) => msg.message_type(),
            Sbp::MsgSettingsReadByIndexReq(msg) => msg.message_type(),
            Sbp::MsgFileioReadResp(msg) => msg.message_type(),
            Sbp::MsgSettingsReadReq(msg) => msg.message_type(),
            Sbp::MsgSettingsReadResp(msg) => msg.message_type(),
            Sbp::MsgSettingsReadByIndexDone(msg) => msg.message_type(),
            Sbp::MsgSettingsReadByIndexResp(msg) => msg.message_type(),
            Sbp::MsgFileioReadReq(msg) => msg.message_type(),
            Sbp::MsgFileioReadDirReq(msg) => msg.message_type(),
            Sbp::MsgFileioReadDirResp(msg) => msg.message_type(),
            Sbp::MsgFileioWriteResp(msg) => msg.message_type(),
            Sbp::MsgFileioRemove(msg) => msg.message_type(),
            Sbp::MsgFileioWriteReq(msg) => msg.message_type(),
            Sbp::MsgSettingsRegister(msg) => msg.message_type(),
            Sbp::MsgSettingsWriteResp(msg) => msg.message_type(),
            Sbp::MsgBootloaderHandshakeDepA(msg) => msg.message_type(),
            Sbp::MsgBootloaderJumpToApp(msg) => msg.message_type(),
            Sbp::MsgResetDep(msg) => msg.message_type(),
            Sbp::MsgBootloaderHandshakeReq(msg) => msg.message_type(),
            Sbp::MsgBootloaderHandshakeResp(msg) => msg.message_type(),
            Sbp::MsgDeviceMonitor(msg) => msg.message_type(),
            Sbp::MsgReset(msg) => msg.message_type(),
            Sbp::MsgCommandReq(msg) => msg.message_type(),
            Sbp::MsgCommandResp(msg) => msg.message_type(),
            Sbp::MsgNetworkStateReq(msg) => msg.message_type(),
            Sbp::MsgNetworkStateResp(msg) => msg.message_type(),
            Sbp::MsgCommandOutput(msg) => msg.message_type(),
            Sbp::MsgNetworkBandwidthUsage(msg) => msg.message_type(),
            Sbp::MsgCellModemStatus(msg) => msg.message_type(),
            Sbp::MsgFrontEndGain(msg) => msg.message_type(),
            Sbp::MsgCwResults(msg) => msg.message_type(),
            Sbp::MsgCwStart(msg) => msg.message_type(),
            Sbp::MsgNapDeviceDnaResp(msg) => msg.message_type(),
            Sbp::MsgNapDeviceDnaReq(msg) => msg.message_type(),
            Sbp::MsgFlashDone(msg) => msg.message_type(),
            Sbp::MsgFlashReadResp(msg) => msg.message_type(),
            Sbp::MsgFlashErase(msg) => msg.message_type(),
            Sbp::MsgStmFlashLockSector(msg) => msg.message_type(),
            Sbp::MsgStmFlashUnlockSector(msg) => msg.message_type(),
            Sbp::MsgStmUniqueIdResp(msg) => msg.message_type(),
            Sbp::MsgFlashProgram(msg) => msg.message_type(),
            Sbp::MsgFlashReadReq(msg) => msg.message_type(),
            Sbp::MsgStmUniqueIdReq(msg) => msg.message_type(),
            Sbp::MsgM25FlashWriteStatus(msg) => msg.message_type(),
            Sbp::MsgGpsTimeDepA(msg) => msg.message_type(),
            Sbp::MsgExtEvent(msg) => msg.message_type(),
            Sbp::MsgGpsTime(msg) => msg.message_type(),
            Sbp::MsgUtcTime(msg) => msg.message_type(),
            Sbp::MsgGpsTimeGnss(msg) => msg.message_type(),
            Sbp::MsgUtcTimeGnss(msg) => msg.message_type(),
            Sbp::MsgSettingsRegisterResp(msg) => msg.message_type(),
            Sbp::MsgPosEcefDepA(msg) => msg.message_type(),
            Sbp::MsgPosLlhDepA(msg) => msg.message_type(),
            Sbp::MsgBaselineEcefDepA(msg) => msg.message_type(),
            Sbp::MsgBaselineNedDepA(msg) => msg.message_type(),
            Sbp::MsgVelEcefDepA(msg) => msg.message_type(),
            Sbp::MsgVelNedDepA(msg) => msg.message_type(),
            Sbp::MsgDopsDepA(msg) => msg.message_type(),
            Sbp::MsgBaselineHeadingDepA(msg) => msg.message_type(),
            Sbp::MsgDops(msg) => msg.message_type(),
            Sbp::MsgPosEcef(msg) => msg.message_type(),
            Sbp::MsgPosLlh(msg) => msg.message_type(),
            Sbp::MsgBaselineEcef(msg) => msg.message_type(),
            Sbp::MsgBaselineNed(msg) => msg.message_type(),
            Sbp::MsgVelEcef(msg) => msg.message_type(),
            Sbp::MsgVelNed(msg) => msg.message_type(),
            Sbp::MsgBaselineHeading(msg) => msg.message_type(),
            Sbp::MsgAgeCorrections(msg) => msg.message_type(),
            Sbp::MsgPosLlhCov(msg) => msg.message_type(),
            Sbp::MsgVelNedCov(msg) => msg.message_type(),
            Sbp::MsgVelBody(msg) => msg.message_type(),
            Sbp::MsgPosEcefCov(msg) => msg.message_type(),
            Sbp::MsgVelEcefCov(msg) => msg.message_type(),
            Sbp::MsgProtectionLevelDepA(msg) => msg.message_type(),
            Sbp::MsgProtectionLevel(msg) => msg.message_type(),
            Sbp::MsgPosLlhAcc(msg) => msg.message_type(),
            Sbp::MsgOrientQuat(msg) => msg.message_type(),
            Sbp::MsgOrientEuler(msg) => msg.message_type(),
            Sbp::MsgAngularRate(msg) => msg.message_type(),
            Sbp::MsgPosEcefGnss(msg) => msg.message_type(),
            Sbp::MsgPosLlhGnss(msg) => msg.message_type(),
            Sbp::MsgVelEcefGnss(msg) => msg.message_type(),
            Sbp::MsgVelNedGnss(msg) => msg.message_type(),
            Sbp::MsgPosLlhCovGnss(msg) => msg.message_type(),
            Sbp::MsgVelNedCovGnss(msg) => msg.message_type(),
            Sbp::MsgPosEcefCovGnss(msg) => msg.message_type(),
            Sbp::MsgVelEcefCovGnss(msg) => msg.message_type(),
            Sbp::MsgNdbEvent(msg) => msg.message_type(),
            Sbp::MsgLog(msg) => msg.message_type(),
            Sbp::MsgFwd(msg) => msg.message_type(),
            Sbp::MsgSsrOrbitClockDepA(msg) => msg.message_type(),
            Sbp::MsgSsrOrbitClock(msg) => msg.message_type(),
            Sbp::MsgSsrCodeBiases(msg) => msg.message_type(),
            Sbp::MsgSsrPhaseBiases(msg) => msg.message_type(),
            Sbp::MsgSsrStecCorrectionDepA(msg) => msg.message_type(),
            Sbp::MsgSsrGriddedCorrectionNoStdDepA(msg) => msg.message_type(),
            Sbp::MsgSsrGridDefinitionDepA(msg) => msg.message_type(),
            Sbp::MsgSsrTileDefinition(msg) => msg.message_type(),
            Sbp::MsgSsrGriddedCorrectionDepA(msg) => msg.message_type(),
            Sbp::MsgSsrStecCorrection(msg) => msg.message_type(),
            Sbp::MsgSsrGriddedCorrection(msg) => msg.message_type(),
            Sbp::MsgSsrSatelliteApc(msg) => msg.message_type(),
            Sbp::MsgOsr(msg) => msg.message_type(),
            Sbp::MsgUserData(msg) => msg.message_type(),
            Sbp::MsgImuRaw(msg) => msg.message_type(),
            Sbp::MsgImuAux(msg) => msg.message_type(),
            Sbp::MsgMagRaw(msg) => msg.message_type(),
            Sbp::MsgOdometry(msg) => msg.message_type(),
            Sbp::MsgWheeltick(msg) => msg.message_type(),
            Sbp::MsgFileioConfigReq(msg) => msg.message_type(),
            Sbp::MsgFileioConfigResp(msg) => msg.message_type(),
            Sbp::MsgSbasRaw(msg) => msg.message_type(),
            Sbp::MsgLinuxCpuStateDepA(msg) => msg.message_type(),
            Sbp::MsgLinuxMemStateDepA(msg) => msg.message_type(),
            Sbp::MsgLinuxSysStateDepA(msg) => msg.message_type(),
            Sbp::MsgLinuxProcessSocketCounts(msg) => msg.message_type(),
            Sbp::MsgLinuxProcessSocketQueues(msg) => msg.message_type(),
            Sbp::MsgLinuxSocketUsage(msg) => msg.message_type(),
            Sbp::MsgLinuxProcessFdCount(msg) => msg.message_type(),
            Sbp::MsgLinuxProcessFdSummary(msg) => msg.message_type(),
            Sbp::MsgLinuxCpuState(msg) => msg.message_type(),
            Sbp::MsgLinuxMemState(msg) => msg.message_type(),
            Sbp::MsgLinuxSysState(msg) => msg.message_type(),
            Sbp::MsgStartup(msg) => msg.message_type(),
            Sbp::MsgDgnssStatus(msg) => msg.message_type(),
            Sbp::MsgInsStatus(msg) => msg.message_type(),
            Sbp::MsgCsacTelemetry(msg) => msg.message_type(),
            Sbp::MsgCsacTelemetryLabels(msg) => msg.message_type(),
            Sbp::MsgInsUpdates(msg) => msg.message_type(),
            Sbp::MsgGnssTimeOffset(msg) => msg.message_type(),
            Sbp::MsgPpsTime(msg) => msg.message_type(),
            Sbp::MsgGroupMeta(msg) => msg.message_type(),
            Sbp::MsgSolnMeta(msg) => msg.message_type(),
            Sbp::MsgSolnMetaDepA(msg) => msg.message_type(),
            Sbp::MsgStatusReport(msg) => msg.message_type(),
            Sbp::MsgHeartbeat(msg) => msg.message_type(),
            Sbp::Unknown(msg) => msg.message_type(),
        }
    }

    fn sender_id(&self) -> Option<u16> {
        match self {
            Sbp::MsgPrintDep(msg) => msg.sender_id(),
            Sbp::MsgTrackingStateDetailedDep(msg) => msg.sender_id(),
            Sbp::MsgTrackingStateDepB(msg) => msg.sender_id(),
            Sbp::MsgAcqResultDepB(msg) => msg.sender_id(),
            Sbp::MsgAcqResultDepA(msg) => msg.sender_id(),
            Sbp::MsgTrackingStateDepA(msg) => msg.sender_id(),
            Sbp::MsgThreadState(msg) => msg.sender_id(),
            Sbp::MsgUartStateDepa(msg) => msg.sender_id(),
            Sbp::MsgIarState(msg) => msg.sender_id(),
            Sbp::MsgEphemerisDepA(msg) => msg.sender_id(),
            Sbp::MsgMaskSatelliteDep(msg) => msg.sender_id(),
            Sbp::MsgTrackingIqDepA(msg) => msg.sender_id(),
            Sbp::MsgUartState(msg) => msg.sender_id(),
            Sbp::MsgAcqSvProfileDep(msg) => msg.sender_id(),
            Sbp::MsgAcqResultDepC(msg) => msg.sender_id(),
            Sbp::MsgTrackingStateDetailedDepA(msg) => msg.sender_id(),
            Sbp::MsgResetFilters(msg) => msg.sender_id(),
            Sbp::MsgInitBaseDep(msg) => msg.sender_id(),
            Sbp::MsgMaskSatellite(msg) => msg.sender_id(),
            Sbp::MsgTrackingIqDepB(msg) => msg.sender_id(),
            Sbp::MsgTrackingIq(msg) => msg.sender_id(),
            Sbp::MsgAcqSvProfile(msg) => msg.sender_id(),
            Sbp::MsgAcqResult(msg) => msg.sender_id(),
            Sbp::MsgTrackingState(msg) => msg.sender_id(),
            Sbp::MsgObsDepB(msg) => msg.sender_id(),
            Sbp::MsgBasePosLlh(msg) => msg.sender_id(),
            Sbp::MsgObsDepA(msg) => msg.sender_id(),
            Sbp::MsgEphemerisDepB(msg) => msg.sender_id(),
            Sbp::MsgEphemerisDepC(msg) => msg.sender_id(),
            Sbp::MsgBasePosEcef(msg) => msg.sender_id(),
            Sbp::MsgObsDepC(msg) => msg.sender_id(),
            Sbp::MsgObs(msg) => msg.sender_id(),
            Sbp::MsgSpecanDep(msg) => msg.sender_id(),
            Sbp::MsgSpecan(msg) => msg.sender_id(),
            Sbp::MsgMeasurementState(msg) => msg.sender_id(),
            Sbp::MsgSetTime(msg) => msg.sender_id(),
            Sbp::MsgAlmanac(msg) => msg.sender_id(),
            Sbp::MsgAlmanacGpsDep(msg) => msg.sender_id(),
            Sbp::MsgAlmanacGloDep(msg) => msg.sender_id(),
            Sbp::MsgAlmanacGps(msg) => msg.sender_id(),
            Sbp::MsgAlmanacGlo(msg) => msg.sender_id(),
            Sbp::MsgGloBiases(msg) => msg.sender_id(),
            Sbp::MsgEphemerisDepD(msg) => msg.sender_id(),
            Sbp::MsgEphemerisGpsDepE(msg) => msg.sender_id(),
            Sbp::MsgEphemerisSbasDepA(msg) => msg.sender_id(),
            Sbp::MsgEphemerisGloDepA(msg) => msg.sender_id(),
            Sbp::MsgEphemerisSbasDepB(msg) => msg.sender_id(),
            Sbp::MsgEphemerisGloDepB(msg) => msg.sender_id(),
            Sbp::MsgEphemerisGpsDepF(msg) => msg.sender_id(),
            Sbp::MsgEphemerisGloDepC(msg) => msg.sender_id(),
            Sbp::MsgEphemerisGloDepD(msg) => msg.sender_id(),
            Sbp::MsgEphemerisBds(msg) => msg.sender_id(),
            Sbp::MsgEphemerisGps(msg) => msg.sender_id(),
            Sbp::MsgEphemerisGlo(msg) => msg.sender_id(),
            Sbp::MsgEphemerisSbas(msg) => msg.sender_id(),
            Sbp::MsgEphemerisGal(msg) => msg.sender_id(),
            Sbp::MsgEphemerisQzss(msg) => msg.sender_id(),
            Sbp::MsgIono(msg) => msg.sender_id(),
            Sbp::MsgSvConfigurationGpsDep(msg) => msg.sender_id(),
            Sbp::MsgGroupDelayDepA(msg) => msg.sender_id(),
            Sbp::MsgGroupDelayDepB(msg) => msg.sender_id(),
            Sbp::MsgGroupDelay(msg) => msg.sender_id(),
            Sbp::MsgEphemerisGalDepA(msg) => msg.sender_id(),
            Sbp::MsgGnssCapb(msg) => msg.sender_id(),
            Sbp::MsgSvAzEl(msg) => msg.sender_id(),
            Sbp::MsgSettingsWrite(msg) => msg.sender_id(),
            Sbp::MsgSettingsSave(msg) => msg.sender_id(),
            Sbp::MsgSettingsReadByIndexReq(msg) => msg.sender_id(),
            Sbp::MsgFileioReadResp(msg) => msg.sender_id(),
            Sbp::MsgSettingsReadReq(msg) => msg.sender_id(),
            Sbp::MsgSettingsReadResp(msg) => msg.sender_id(),
            Sbp::MsgSettingsReadByIndexDone(msg) => msg.sender_id(),
            Sbp::MsgSettingsReadByIndexResp(msg) => msg.sender_id(),
            Sbp::MsgFileioReadReq(msg) => msg.sender_id(),
            Sbp::MsgFileioReadDirReq(msg) => msg.sender_id(),
            Sbp::MsgFileioReadDirResp(msg) => msg.sender_id(),
            Sbp::MsgFileioWriteResp(msg) => msg.sender_id(),
            Sbp::MsgFileioRemove(msg) => msg.sender_id(),
            Sbp::MsgFileioWriteReq(msg) => msg.sender_id(),
            Sbp::MsgSettingsRegister(msg) => msg.sender_id(),
            Sbp::MsgSettingsWriteResp(msg) => msg.sender_id(),
            Sbp::MsgBootloaderHandshakeDepA(msg) => msg.sender_id(),
            Sbp::MsgBootloaderJumpToApp(msg) => msg.sender_id(),
            Sbp::MsgResetDep(msg) => msg.sender_id(),
            Sbp::MsgBootloaderHandshakeReq(msg) => msg.sender_id(),
            Sbp::MsgBootloaderHandshakeResp(msg) => msg.sender_id(),
            Sbp::MsgDeviceMonitor(msg) => msg.sender_id(),
            Sbp::MsgReset(msg) => msg.sender_id(),
            Sbp::MsgCommandReq(msg) => msg.sender_id(),
            Sbp::MsgCommandResp(msg) => msg.sender_id(),
            Sbp::MsgNetworkStateReq(msg) => msg.sender_id(),
            Sbp::MsgNetworkStateResp(msg) => msg.sender_id(),
            Sbp::MsgCommandOutput(msg) => msg.sender_id(),
            Sbp::MsgNetworkBandwidthUsage(msg) => msg.sender_id(),
            Sbp::MsgCellModemStatus(msg) => msg.sender_id(),
            Sbp::MsgFrontEndGain(msg) => msg.sender_id(),
            Sbp::MsgCwResults(msg) => msg.sender_id(),
            Sbp::MsgCwStart(msg) => msg.sender_id(),
            Sbp::MsgNapDeviceDnaResp(msg) => msg.sender_id(),
            Sbp::MsgNapDeviceDnaReq(msg) => msg.sender_id(),
            Sbp::MsgFlashDone(msg) => msg.sender_id(),
            Sbp::MsgFlashReadResp(msg) => msg.sender_id(),
            Sbp::MsgFlashErase(msg) => msg.sender_id(),
            Sbp::MsgStmFlashLockSector(msg) => msg.sender_id(),
            Sbp::MsgStmFlashUnlockSector(msg) => msg.sender_id(),
            Sbp::MsgStmUniqueIdResp(msg) => msg.sender_id(),
            Sbp::MsgFlashProgram(msg) => msg.sender_id(),
            Sbp::MsgFlashReadReq(msg) => msg.sender_id(),
            Sbp::MsgStmUniqueIdReq(msg) => msg.sender_id(),
            Sbp::MsgM25FlashWriteStatus(msg) => msg.sender_id(),
            Sbp::MsgGpsTimeDepA(msg) => msg.sender_id(),
            Sbp::MsgExtEvent(msg) => msg.sender_id(),
            Sbp::MsgGpsTime(msg) => msg.sender_id(),
            Sbp::MsgUtcTime(msg) => msg.sender_id(),
            Sbp::MsgGpsTimeGnss(msg) => msg.sender_id(),
            Sbp::MsgUtcTimeGnss(msg) => msg.sender_id(),
            Sbp::MsgSettingsRegisterResp(msg) => msg.sender_id(),
            Sbp::MsgPosEcefDepA(msg) => msg.sender_id(),
            Sbp::MsgPosLlhDepA(msg) => msg.sender_id(),
            Sbp::MsgBaselineEcefDepA(msg) => msg.sender_id(),
            Sbp::MsgBaselineNedDepA(msg) => msg.sender_id(),
            Sbp::MsgVelEcefDepA(msg) => msg.sender_id(),
            Sbp::MsgVelNedDepA(msg) => msg.sender_id(),
            Sbp::MsgDopsDepA(msg) => msg.sender_id(),
            Sbp::MsgBaselineHeadingDepA(msg) => msg.sender_id(),
            Sbp::MsgDops(msg) => msg.sender_id(),
            Sbp::MsgPosEcef(msg) => msg.sender_id(),
            Sbp::MsgPosLlh(msg) => msg.sender_id(),
            Sbp::MsgBaselineEcef(msg) => msg.sender_id(),
            Sbp::MsgBaselineNed(msg) => msg.sender_id(),
            Sbp::MsgVelEcef(msg) => msg.sender_id(),
            Sbp::MsgVelNed(msg) => msg.sender_id(),
            Sbp::MsgBaselineHeading(msg) => msg.sender_id(),
            Sbp::MsgAgeCorrections(msg) => msg.sender_id(),
            Sbp::MsgPosLlhCov(msg) => msg.sender_id(),
            Sbp::MsgVelNedCov(msg) => msg.sender_id(),
            Sbp::MsgVelBody(msg) => msg.sender_id(),
            Sbp::MsgPosEcefCov(msg) => msg.sender_id(),
            Sbp::MsgVelEcefCov(msg) => msg.sender_id(),
            Sbp::MsgProtectionLevelDepA(msg) => msg.sender_id(),
            Sbp::MsgProtectionLevel(msg) => msg.sender_id(),
            Sbp::MsgPosLlhAcc(msg) => msg.sender_id(),
            Sbp::MsgOrientQuat(msg) => msg.sender_id(),
            Sbp::MsgOrientEuler(msg) => msg.sender_id(),
            Sbp::MsgAngularRate(msg) => msg.sender_id(),
            Sbp::MsgPosEcefGnss(msg) => msg.sender_id(),
            Sbp::MsgPosLlhGnss(msg) => msg.sender_id(),
            Sbp::MsgVelEcefGnss(msg) => msg.sender_id(),
            Sbp::MsgVelNedGnss(msg) => msg.sender_id(),
            Sbp::MsgPosLlhCovGnss(msg) => msg.sender_id(),
            Sbp::MsgVelNedCovGnss(msg) => msg.sender_id(),
            Sbp::MsgPosEcefCovGnss(msg) => msg.sender_id(),
            Sbp::MsgVelEcefCovGnss(msg) => msg.sender_id(),
            Sbp::MsgNdbEvent(msg) => msg.sender_id(),
            Sbp::MsgLog(msg) => msg.sender_id(),
            Sbp::MsgFwd(msg) => msg.sender_id(),
            Sbp::MsgSsrOrbitClockDepA(msg) => msg.sender_id(),
            Sbp::MsgSsrOrbitClock(msg) => msg.sender_id(),
            Sbp::MsgSsrCodeBiases(msg) => msg.sender_id(),
            Sbp::MsgSsrPhaseBiases(msg) => msg.sender_id(),
            Sbp::MsgSsrStecCorrectionDepA(msg) => msg.sender_id(),
            Sbp::MsgSsrGriddedCorrectionNoStdDepA(msg) => msg.sender_id(),
            Sbp::MsgSsrGridDefinitionDepA(msg) => msg.sender_id(),
            Sbp::MsgSsrTileDefinition(msg) => msg.sender_id(),
            Sbp::MsgSsrGriddedCorrectionDepA(msg) => msg.sender_id(),
            Sbp::MsgSsrStecCorrection(msg) => msg.sender_id(),
            Sbp::MsgSsrGriddedCorrection(msg) => msg.sender_id(),
            Sbp::MsgSsrSatelliteApc(msg) => msg.sender_id(),
            Sbp::MsgOsr(msg) => msg.sender_id(),
            Sbp::MsgUserData(msg) => msg.sender_id(),
            Sbp::MsgImuRaw(msg) => msg.sender_id(),
            Sbp::MsgImuAux(msg) => msg.sender_id(),
            Sbp::MsgMagRaw(msg) => msg.sender_id(),
            Sbp::MsgOdometry(msg) => msg.sender_id(),
            Sbp::MsgWheeltick(msg) => msg.sender_id(),
            Sbp::MsgFileioConfigReq(msg) => msg.sender_id(),
            Sbp::MsgFileioConfigResp(msg) => msg.sender_id(),
            Sbp::MsgSbasRaw(msg) => msg.sender_id(),
            Sbp::MsgLinuxCpuStateDepA(msg) => msg.sender_id(),
            Sbp::MsgLinuxMemStateDepA(msg) => msg.sender_id(),
            Sbp::MsgLinuxSysStateDepA(msg) => msg.sender_id(),
            Sbp::MsgLinuxProcessSocketCounts(msg) => msg.sender_id(),
            Sbp::MsgLinuxProcessSocketQueues(msg) => msg.sender_id(),
            Sbp::MsgLinuxSocketUsage(msg) => msg.sender_id(),
            Sbp::MsgLinuxProcessFdCount(msg) => msg.sender_id(),
            Sbp::MsgLinuxProcessFdSummary(msg) => msg.sender_id(),
            Sbp::MsgLinuxCpuState(msg) => msg.sender_id(),
            Sbp::MsgLinuxMemState(msg) => msg.sender_id(),
            Sbp::MsgLinuxSysState(msg) => msg.sender_id(),
            Sbp::MsgStartup(msg) => msg.sender_id(),
            Sbp::MsgDgnssStatus(msg) => msg.sender_id(),
            Sbp::MsgInsStatus(msg) => msg.sender_id(),
            Sbp::MsgCsacTelemetry(msg) => msg.sender_id(),
            Sbp::MsgCsacTelemetryLabels(msg) => msg.sender_id(),
            Sbp::MsgInsUpdates(msg) => msg.sender_id(),
            Sbp::MsgGnssTimeOffset(msg) => msg.sender_id(),
            Sbp::MsgPpsTime(msg) => msg.sender_id(),
            Sbp::MsgGroupMeta(msg) => msg.sender_id(),
            Sbp::MsgSolnMeta(msg) => msg.sender_id(),
            Sbp::MsgSolnMetaDepA(msg) => msg.sender_id(),
            Sbp::MsgStatusReport(msg) => msg.sender_id(),
            Sbp::MsgHeartbeat(msg) => msg.sender_id(),
            Sbp::Unknown(msg) => msg.sender_id(),
        }
    }

    fn set_sender_id(&mut self, new_id: u16) {
        match self {
            Sbp::MsgPrintDep(msg) => msg.set_sender_id(new_id),
            Sbp::MsgTrackingStateDetailedDep(msg) => msg.set_sender_id(new_id),
            Sbp::MsgTrackingStateDepB(msg) => msg.set_sender_id(new_id),
            Sbp::MsgAcqResultDepB(msg) => msg.set_sender_id(new_id),
            Sbp::MsgAcqResultDepA(msg) => msg.set_sender_id(new_id),
            Sbp::MsgTrackingStateDepA(msg) => msg.set_sender_id(new_id),
            Sbp::MsgThreadState(msg) => msg.set_sender_id(new_id),
            Sbp::MsgUartStateDepa(msg) => msg.set_sender_id(new_id),
            Sbp::MsgIarState(msg) => msg.set_sender_id(new_id),
            Sbp::MsgEphemerisDepA(msg) => msg.set_sender_id(new_id),
            Sbp::MsgMaskSatelliteDep(msg) => msg.set_sender_id(new_id),
            Sbp::MsgTrackingIqDepA(msg) => msg.set_sender_id(new_id),
            Sbp::MsgUartState(msg) => msg.set_sender_id(new_id),
            Sbp::MsgAcqSvProfileDep(msg) => msg.set_sender_id(new_id),
            Sbp::MsgAcqResultDepC(msg) => msg.set_sender_id(new_id),
            Sbp::MsgTrackingStateDetailedDepA(msg) => msg.set_sender_id(new_id),
            Sbp::MsgResetFilters(msg) => msg.set_sender_id(new_id),
            Sbp::MsgInitBaseDep(msg) => msg.set_sender_id(new_id),
            Sbp::MsgMaskSatellite(msg) => msg.set_sender_id(new_id),
            Sbp::MsgTrackingIqDepB(msg) => msg.set_sender_id(new_id),
            Sbp::MsgTrackingIq(msg) => msg.set_sender_id(new_id),
            Sbp::MsgAcqSvProfile(msg) => msg.set_sender_id(new_id),
            Sbp::MsgAcqResult(msg) => msg.set_sender_id(new_id),
            Sbp::MsgTrackingState(msg) => msg.set_sender_id(new_id),
            Sbp::MsgObsDepB(msg) => msg.set_sender_id(new_id),
            Sbp::MsgBasePosLlh(msg) => msg.set_sender_id(new_id),
            Sbp::MsgObsDepA(msg) => msg.set_sender_id(new_id),
            Sbp::MsgEphemerisDepB(msg) => msg.set_sender_id(new_id),
            Sbp::MsgEphemerisDepC(msg) => msg.set_sender_id(new_id),
            Sbp::MsgBasePosEcef(msg) => msg.set_sender_id(new_id),
            Sbp::MsgObsDepC(msg) => msg.set_sender_id(new_id),
            Sbp::MsgObs(msg) => msg.set_sender_id(new_id),
            Sbp::MsgSpecanDep(msg) => msg.set_sender_id(new_id),
            Sbp::MsgSpecan(msg) => msg.set_sender_id(new_id),
            Sbp::MsgMeasurementState(msg) => msg.set_sender_id(new_id),
            Sbp::MsgSetTime(msg) => msg.set_sender_id(new_id),
            Sbp::MsgAlmanac(msg) => msg.set_sender_id(new_id),
            Sbp::MsgAlmanacGpsDep(msg) => msg.set_sender_id(new_id),
            Sbp::MsgAlmanacGloDep(msg) => msg.set_sender_id(new_id),
            Sbp::MsgAlmanacGps(msg) => msg.set_sender_id(new_id),
            Sbp::MsgAlmanacGlo(msg) => msg.set_sender_id(new_id),
            Sbp::MsgGloBiases(msg) => msg.set_sender_id(new_id),
            Sbp::MsgEphemerisDepD(msg) => msg.set_sender_id(new_id),
            Sbp::MsgEphemerisGpsDepE(msg) => msg.set_sender_id(new_id),
            Sbp::MsgEphemerisSbasDepA(msg) => msg.set_sender_id(new_id),
            Sbp::MsgEphemerisGloDepA(msg) => msg.set_sender_id(new_id),
            Sbp::MsgEphemerisSbasDepB(msg) => msg.set_sender_id(new_id),
            Sbp::MsgEphemerisGloDepB(msg) => msg.set_sender_id(new_id),
            Sbp::MsgEphemerisGpsDepF(msg) => msg.set_sender_id(new_id),
            Sbp::MsgEphemerisGloDepC(msg) => msg.set_sender_id(new_id),
            Sbp::MsgEphemerisGloDepD(msg) => msg.set_sender_id(new_id),
            Sbp::MsgEphemerisBds(msg) => msg.set_sender_id(new_id),
            Sbp::MsgEphemerisGps(msg) => msg.set_sender_id(new_id),
            Sbp::MsgEphemerisGlo(msg) => msg.set_sender_id(new_id),
            Sbp::MsgEphemerisSbas(msg) => msg.set_sender_id(new_id),
            Sbp::MsgEphemerisGal(msg) => msg.set_sender_id(new_id),
            Sbp::MsgEphemerisQzss(msg) => msg.set_sender_id(new_id),
            Sbp::MsgIono(msg) => msg.set_sender_id(new_id),
            Sbp::MsgSvConfigurationGpsDep(msg) => msg.set_sender_id(new_id),
            Sbp::MsgGroupDelayDepA(msg) => msg.set_sender_id(new_id),
            Sbp::MsgGroupDelayDepB(msg) => msg.set_sender_id(new_id),
            Sbp::MsgGroupDelay(msg) => msg.set_sender_id(new_id),
            Sbp::MsgEphemerisGalDepA(msg) => msg.set_sender_id(new_id),
            Sbp::MsgGnssCapb(msg) => msg.set_sender_id(new_id),
            Sbp::MsgSvAzEl(msg) => msg.set_sender_id(new_id),
            Sbp::MsgSettingsWrite(msg) => msg.set_sender_id(new_id),
            Sbp::MsgSettingsSave(msg) => msg.set_sender_id(new_id),
            Sbp::MsgSettingsReadByIndexReq(msg) => msg.set_sender_id(new_id),
            Sbp::MsgFileioReadResp(msg) => msg.set_sender_id(new_id),
            Sbp::MsgSettingsReadReq(msg) => msg.set_sender_id(new_id),
            Sbp::MsgSettingsReadResp(msg) => msg.set_sender_id(new_id),
            Sbp::MsgSettingsReadByIndexDone(msg) => msg.set_sender_id(new_id),
            Sbp::MsgSettingsReadByIndexResp(msg) => msg.set_sender_id(new_id),
            Sbp::MsgFileioReadReq(msg) => msg.set_sender_id(new_id),
            Sbp::MsgFileioReadDirReq(msg) => msg.set_sender_id(new_id),
            Sbp::MsgFileioReadDirResp(msg) => msg.set_sender_id(new_id),
            Sbp::MsgFileioWriteResp(msg) => msg.set_sender_id(new_id),
            Sbp::MsgFileioRemove(msg) => msg.set_sender_id(new_id),
            Sbp::MsgFileioWriteReq(msg) => msg.set_sender_id(new_id),
            Sbp::MsgSettingsRegister(msg) => msg.set_sender_id(new_id),
            Sbp::MsgSettingsWriteResp(msg) => msg.set_sender_id(new_id),
            Sbp::MsgBootloaderHandshakeDepA(msg) => msg.set_sender_id(new_id),
            Sbp::MsgBootloaderJumpToApp(msg) => msg.set_sender_id(new_id),
            Sbp::MsgResetDep(msg) => msg.set_sender_id(new_id),
            Sbp::MsgBootloaderHandshakeReq(msg) => msg.set_sender_id(new_id),
            Sbp::MsgBootloaderHandshakeResp(msg) => msg.set_sender_id(new_id),
            Sbp::MsgDeviceMonitor(msg) => msg.set_sender_id(new_id),
            Sbp::MsgReset(msg) => msg.set_sender_id(new_id),
            Sbp::MsgCommandReq(msg) => msg.set_sender_id(new_id),
            Sbp::MsgCommandResp(msg) => msg.set_sender_id(new_id),
            Sbp::MsgNetworkStateReq(msg) => msg.set_sender_id(new_id),
            Sbp::MsgNetworkStateResp(msg) => msg.set_sender_id(new_id),
            Sbp::MsgCommandOutput(msg) => msg.set_sender_id(new_id),
            Sbp::MsgNetworkBandwidthUsage(msg) => msg.set_sender_id(new_id),
            Sbp::MsgCellModemStatus(msg) => msg.set_sender_id(new_id),
            Sbp::MsgFrontEndGain(msg) => msg.set_sender_id(new_id),
            Sbp::MsgCwResults(msg) => msg.set_sender_id(new_id),
            Sbp::MsgCwStart(msg) => msg.set_sender_id(new_id),
            Sbp::MsgNapDeviceDnaResp(msg) => msg.set_sender_id(new_id),
            Sbp::MsgNapDeviceDnaReq(msg) => msg.set_sender_id(new_id),
            Sbp::MsgFlashDone(msg) => msg.set_sender_id(new_id),
            Sbp::MsgFlashReadResp(msg) => msg.set_sender_id(new_id),
            Sbp::MsgFlashErase(msg) => msg.set_sender_id(new_id),
            Sbp::MsgStmFlashLockSector(msg) => msg.set_sender_id(new_id),
            Sbp::MsgStmFlashUnlockSector(msg) => msg.set_sender_id(new_id),
            Sbp::MsgStmUniqueIdResp(msg) => msg.set_sender_id(new_id),
            Sbp::MsgFlashProgram(msg) => msg.set_sender_id(new_id),
            Sbp::MsgFlashReadReq(msg) => msg.set_sender_id(new_id),
            Sbp::MsgStmUniqueIdReq(msg) => msg.set_sender_id(new_id),
            Sbp::MsgM25FlashWriteStatus(msg) => msg.set_sender_id(new_id),
            Sbp::MsgGpsTimeDepA(msg) => msg.set_sender_id(new_id),
            Sbp::MsgExtEvent(msg) => msg.set_sender_id(new_id),
            Sbp::MsgGpsTime(msg) => msg.set_sender_id(new_id),
            Sbp::MsgUtcTime(msg) => msg.set_sender_id(new_id),
            Sbp::MsgGpsTimeGnss(msg) => msg.set_sender_id(new_id),
            Sbp::MsgUtcTimeGnss(msg) => msg.set_sender_id(new_id),
            Sbp::MsgSettingsRegisterResp(msg) => msg.set_sender_id(new_id),
            Sbp::MsgPosEcefDepA(msg) => msg.set_sender_id(new_id),
            Sbp::MsgPosLlhDepA(msg) => msg.set_sender_id(new_id),
            Sbp::MsgBaselineEcefDepA(msg) => msg.set_sender_id(new_id),
            Sbp::MsgBaselineNedDepA(msg) => msg.set_sender_id(new_id),
            Sbp::MsgVelEcefDepA(msg) => msg.set_sender_id(new_id),
            Sbp::MsgVelNedDepA(msg) => msg.set_sender_id(new_id),
            Sbp::MsgDopsDepA(msg) => msg.set_sender_id(new_id),
            Sbp::MsgBaselineHeadingDepA(msg) => msg.set_sender_id(new_id),
            Sbp::MsgDops(msg) => msg.set_sender_id(new_id),
            Sbp::MsgPosEcef(msg) => msg.set_sender_id(new_id),
            Sbp::MsgPosLlh(msg) => msg.set_sender_id(new_id),
            Sbp::MsgBaselineEcef(msg) => msg.set_sender_id(new_id),
            Sbp::MsgBaselineNed(msg) => msg.set_sender_id(new_id),
            Sbp::MsgVelEcef(msg) => msg.set_sender_id(new_id),
            Sbp::MsgVelNed(msg) => msg.set_sender_id(new_id),
            Sbp::MsgBaselineHeading(msg) => msg.set_sender_id(new_id),
            Sbp::MsgAgeCorrections(msg) => msg.set_sender_id(new_id),
            Sbp::MsgPosLlhCov(msg) => msg.set_sender_id(new_id),
            Sbp::MsgVelNedCov(msg) => msg.set_sender_id(new_id),
            Sbp::MsgVelBody(msg) => msg.set_sender_id(new_id),
            Sbp::MsgPosEcefCov(msg) => msg.set_sender_id(new_id),
            Sbp::MsgVelEcefCov(msg) => msg.set_sender_id(new_id),
            Sbp::MsgProtectionLevelDepA(msg) => msg.set_sender_id(new_id),
            Sbp::MsgProtectionLevel(msg) => msg.set_sender_id(new_id),
            Sbp::MsgPosLlhAcc(msg) => msg.set_sender_id(new_id),
            Sbp::MsgOrientQuat(msg) => msg.set_sender_id(new_id),
            Sbp::MsgOrientEuler(msg) => msg.set_sender_id(new_id),
            Sbp::MsgAngularRate(msg) => msg.set_sender_id(new_id),
            Sbp::MsgPosEcefGnss(msg) => msg.set_sender_id(new_id),
            Sbp::MsgPosLlhGnss(msg) => msg.set_sender_id(new_id),
            Sbp::MsgVelEcefGnss(msg) => msg.set_sender_id(new_id),
            Sbp::MsgVelNedGnss(msg) => msg.set_sender_id(new_id),
            Sbp::MsgPosLlhCovGnss(msg) => msg.set_sender_id(new_id),
            Sbp::MsgVelNedCovGnss(msg) => msg.set_sender_id(new_id),
            Sbp::MsgPosEcefCovGnss(msg) => msg.set_sender_id(new_id),
            Sbp::MsgVelEcefCovGnss(msg) => msg.set_sender_id(new_id),
            Sbp::MsgNdbEvent(msg) => msg.set_sender_id(new_id),
            Sbp::MsgLog(msg) => msg.set_sender_id(new_id),
            Sbp::MsgFwd(msg) => msg.set_sender_id(new_id),
            Sbp::MsgSsrOrbitClockDepA(msg) => msg.set_sender_id(new_id),
            Sbp::MsgSsrOrbitClock(msg) => msg.set_sender_id(new_id),
            Sbp::MsgSsrCodeBiases(msg) => msg.set_sender_id(new_id),
            Sbp::MsgSsrPhaseBiases(msg) => msg.set_sender_id(new_id),
            Sbp::MsgSsrStecCorrectionDepA(msg) => msg.set_sender_id(new_id),
            Sbp::MsgSsrGriddedCorrectionNoStdDepA(msg) => msg.set_sender_id(new_id),
            Sbp::MsgSsrGridDefinitionDepA(msg) => msg.set_sender_id(new_id),
            Sbp::MsgSsrTileDefinition(msg) => msg.set_sender_id(new_id),
            Sbp::MsgSsrGriddedCorrectionDepA(msg) => msg.set_sender_id(new_id),
            Sbp::MsgSsrStecCorrection(msg) => msg.set_sender_id(new_id),
            Sbp::MsgSsrGriddedCorrection(msg) => msg.set_sender_id(new_id),
            Sbp::MsgSsrSatelliteApc(msg) => msg.set_sender_id(new_id),
            Sbp::MsgOsr(msg) => msg.set_sender_id(new_id),
            Sbp::MsgUserData(msg) => msg.set_sender_id(new_id),
            Sbp::MsgImuRaw(msg) => msg.set_sender_id(new_id),
            Sbp::MsgImuAux(msg) => msg.set_sender_id(new_id),
            Sbp::MsgMagRaw(msg) => msg.set_sender_id(new_id),
            Sbp::MsgOdometry(msg) => msg.set_sender_id(new_id),
            Sbp::MsgWheeltick(msg) => msg.set_sender_id(new_id),
            Sbp::MsgFileioConfigReq(msg) => msg.set_sender_id(new_id),
            Sbp::MsgFileioConfigResp(msg) => msg.set_sender_id(new_id),
            Sbp::MsgSbasRaw(msg) => msg.set_sender_id(new_id),
            Sbp::MsgLinuxCpuStateDepA(msg) => msg.set_sender_id(new_id),
            Sbp::MsgLinuxMemStateDepA(msg) => msg.set_sender_id(new_id),
            Sbp::MsgLinuxSysStateDepA(msg) => msg.set_sender_id(new_id),
            Sbp::MsgLinuxProcessSocketCounts(msg) => msg.set_sender_id(new_id),
            Sbp::MsgLinuxProcessSocketQueues(msg) => msg.set_sender_id(new_id),
            Sbp::MsgLinuxSocketUsage(msg) => msg.set_sender_id(new_id),
            Sbp::MsgLinuxProcessFdCount(msg) => msg.set_sender_id(new_id),
            Sbp::MsgLinuxProcessFdSummary(msg) => msg.set_sender_id(new_id),
            Sbp::MsgLinuxCpuState(msg) => msg.set_sender_id(new_id),
            Sbp::MsgLinuxMemState(msg) => msg.set_sender_id(new_id),
            Sbp::MsgLinuxSysState(msg) => msg.set_sender_id(new_id),
            Sbp::MsgStartup(msg) => msg.set_sender_id(new_id),
            Sbp::MsgDgnssStatus(msg) => msg.set_sender_id(new_id),
            Sbp::MsgInsStatus(msg) => msg.set_sender_id(new_id),
            Sbp::MsgCsacTelemetry(msg) => msg.set_sender_id(new_id),
            Sbp::MsgCsacTelemetryLabels(msg) => msg.set_sender_id(new_id),
            Sbp::MsgInsUpdates(msg) => msg.set_sender_id(new_id),
            Sbp::MsgGnssTimeOffset(msg) => msg.set_sender_id(new_id),
            Sbp::MsgPpsTime(msg) => msg.set_sender_id(new_id),
            Sbp::MsgGroupMeta(msg) => msg.set_sender_id(new_id),
            Sbp::MsgSolnMeta(msg) => msg.set_sender_id(new_id),
            Sbp::MsgSolnMetaDepA(msg) => msg.set_sender_id(new_id),
            Sbp::MsgStatusReport(msg) => msg.set_sender_id(new_id),
            Sbp::MsgHeartbeat(msg) => msg.set_sender_id(new_id),
            Sbp::Unknown(msg) => msg.set_sender_id(new_id),
        }
    }

    fn to_frame(&self) -> Result<Vec<u8>, crate::FramerError> {
        match self {
            Sbp::MsgPrintDep(msg) => msg.to_frame(),
            Sbp::MsgTrackingStateDetailedDep(msg) => msg.to_frame(),
            Sbp::MsgTrackingStateDepB(msg) => msg.to_frame(),
            Sbp::MsgAcqResultDepB(msg) => msg.to_frame(),
            Sbp::MsgAcqResultDepA(msg) => msg.to_frame(),
            Sbp::MsgTrackingStateDepA(msg) => msg.to_frame(),
            Sbp::MsgThreadState(msg) => msg.to_frame(),
            Sbp::MsgUartStateDepa(msg) => msg.to_frame(),
            Sbp::MsgIarState(msg) => msg.to_frame(),
            Sbp::MsgEphemerisDepA(msg) => msg.to_frame(),
            Sbp::MsgMaskSatelliteDep(msg) => msg.to_frame(),
            Sbp::MsgTrackingIqDepA(msg) => msg.to_frame(),
            Sbp::MsgUartState(msg) => msg.to_frame(),
            Sbp::MsgAcqSvProfileDep(msg) => msg.to_frame(),
            Sbp::MsgAcqResultDepC(msg) => msg.to_frame(),
            Sbp::MsgTrackingStateDetailedDepA(msg) => msg.to_frame(),
            Sbp::MsgResetFilters(msg) => msg.to_frame(),
            Sbp::MsgInitBaseDep(msg) => msg.to_frame(),
            Sbp::MsgMaskSatellite(msg) => msg.to_frame(),
            Sbp::MsgTrackingIqDepB(msg) => msg.to_frame(),
            Sbp::MsgTrackingIq(msg) => msg.to_frame(),
            Sbp::MsgAcqSvProfile(msg) => msg.to_frame(),
            Sbp::MsgAcqResult(msg) => msg.to_frame(),
            Sbp::MsgTrackingState(msg) => msg.to_frame(),
            Sbp::MsgObsDepB(msg) => msg.to_frame(),
            Sbp::MsgBasePosLlh(msg) => msg.to_frame(),
            Sbp::MsgObsDepA(msg) => msg.to_frame(),
            Sbp::MsgEphemerisDepB(msg) => msg.to_frame(),
            Sbp::MsgEphemerisDepC(msg) => msg.to_frame(),
            Sbp::MsgBasePosEcef(msg) => msg.to_frame(),
            Sbp::MsgObsDepC(msg) => msg.to_frame(),
            Sbp::MsgObs(msg) => msg.to_frame(),
            Sbp::MsgSpecanDep(msg) => msg.to_frame(),
            Sbp::MsgSpecan(msg) => msg.to_frame(),
            Sbp::MsgMeasurementState(msg) => msg.to_frame(),
            Sbp::MsgSetTime(msg) => msg.to_frame(),
            Sbp::MsgAlmanac(msg) => msg.to_frame(),
            Sbp::MsgAlmanacGpsDep(msg) => msg.to_frame(),
            Sbp::MsgAlmanacGloDep(msg) => msg.to_frame(),
            Sbp::MsgAlmanacGps(msg) => msg.to_frame(),
            Sbp::MsgAlmanacGlo(msg) => msg.to_frame(),
            Sbp::MsgGloBiases(msg) => msg.to_frame(),
            Sbp::MsgEphemerisDepD(msg) => msg.to_frame(),
            Sbp::MsgEphemerisGpsDepE(msg) => msg.to_frame(),
            Sbp::MsgEphemerisSbasDepA(msg) => msg.to_frame(),
            Sbp::MsgEphemerisGloDepA(msg) => msg.to_frame(),
            Sbp::MsgEphemerisSbasDepB(msg) => msg.to_frame(),
            Sbp::MsgEphemerisGloDepB(msg) => msg.to_frame(),
            Sbp::MsgEphemerisGpsDepF(msg) => msg.to_frame(),
            Sbp::MsgEphemerisGloDepC(msg) => msg.to_frame(),
            Sbp::MsgEphemerisGloDepD(msg) => msg.to_frame(),
            Sbp::MsgEphemerisBds(msg) => msg.to_frame(),
            Sbp::MsgEphemerisGps(msg) => msg.to_frame(),
            Sbp::MsgEphemerisGlo(msg) => msg.to_frame(),
            Sbp::MsgEphemerisSbas(msg) => msg.to_frame(),
            Sbp::MsgEphemerisGal(msg) => msg.to_frame(),
            Sbp::MsgEphemerisQzss(msg) => msg.to_frame(),
            Sbp::MsgIono(msg) => msg.to_frame(),
            Sbp::MsgSvConfigurationGpsDep(msg) => msg.to_frame(),
            Sbp::MsgGroupDelayDepA(msg) => msg.to_frame(),
            Sbp::MsgGroupDelayDepB(msg) => msg.to_frame(),
            Sbp::MsgGroupDelay(msg) => msg.to_frame(),
            Sbp::MsgEphemerisGalDepA(msg) => msg.to_frame(),
            Sbp::MsgGnssCapb(msg) => msg.to_frame(),
            Sbp::MsgSvAzEl(msg) => msg.to_frame(),
            Sbp::MsgSettingsWrite(msg) => msg.to_frame(),
            Sbp::MsgSettingsSave(msg) => msg.to_frame(),
            Sbp::MsgSettingsReadByIndexReq(msg) => msg.to_frame(),
            Sbp::MsgFileioReadResp(msg) => msg.to_frame(),
            Sbp::MsgSettingsReadReq(msg) => msg.to_frame(),
            Sbp::MsgSettingsReadResp(msg) => msg.to_frame(),
            Sbp::MsgSettingsReadByIndexDone(msg) => msg.to_frame(),
            Sbp::MsgSettingsReadByIndexResp(msg) => msg.to_frame(),
            Sbp::MsgFileioReadReq(msg) => msg.to_frame(),
            Sbp::MsgFileioReadDirReq(msg) => msg.to_frame(),
            Sbp::MsgFileioReadDirResp(msg) => msg.to_frame(),
            Sbp::MsgFileioWriteResp(msg) => msg.to_frame(),
            Sbp::MsgFileioRemove(msg) => msg.to_frame(),
            Sbp::MsgFileioWriteReq(msg) => msg.to_frame(),
            Sbp::MsgSettingsRegister(msg) => msg.to_frame(),
            Sbp::MsgSettingsWriteResp(msg) => msg.to_frame(),
            Sbp::MsgBootloaderHandshakeDepA(msg) => msg.to_frame(),
            Sbp::MsgBootloaderJumpToApp(msg) => msg.to_frame(),
            Sbp::MsgResetDep(msg) => msg.to_frame(),
            Sbp::MsgBootloaderHandshakeReq(msg) => msg.to_frame(),
            Sbp::MsgBootloaderHandshakeResp(msg) => msg.to_frame(),
            Sbp::MsgDeviceMonitor(msg) => msg.to_frame(),
            Sbp::MsgReset(msg) => msg.to_frame(),
            Sbp::MsgCommandReq(msg) => msg.to_frame(),
            Sbp::MsgCommandResp(msg) => msg.to_frame(),
            Sbp::MsgNetworkStateReq(msg) => msg.to_frame(),
            Sbp::MsgNetworkStateResp(msg) => msg.to_frame(),
            Sbp::MsgCommandOutput(msg) => msg.to_frame(),
            Sbp::MsgNetworkBandwidthUsage(msg) => msg.to_frame(),
            Sbp::MsgCellModemStatus(msg) => msg.to_frame(),
            Sbp::MsgFrontEndGain(msg) => msg.to_frame(),
            Sbp::MsgCwResults(msg) => msg.to_frame(),
            Sbp::MsgCwStart(msg) => msg.to_frame(),
            Sbp::MsgNapDeviceDnaResp(msg) => msg.to_frame(),
            Sbp::MsgNapDeviceDnaReq(msg) => msg.to_frame(),
            Sbp::MsgFlashDone(msg) => msg.to_frame(),
            Sbp::MsgFlashReadResp(msg) => msg.to_frame(),
            Sbp::MsgFlashErase(msg) => msg.to_frame(),
            Sbp::MsgStmFlashLockSector(msg) => msg.to_frame(),
            Sbp::MsgStmFlashUnlockSector(msg) => msg.to_frame(),
            Sbp::MsgStmUniqueIdResp(msg) => msg.to_frame(),
            Sbp::MsgFlashProgram(msg) => msg.to_frame(),
            Sbp::MsgFlashReadReq(msg) => msg.to_frame(),
            Sbp::MsgStmUniqueIdReq(msg) => msg.to_frame(),
            Sbp::MsgM25FlashWriteStatus(msg) => msg.to_frame(),
            Sbp::MsgGpsTimeDepA(msg) => msg.to_frame(),
            Sbp::MsgExtEvent(msg) => msg.to_frame(),
            Sbp::MsgGpsTime(msg) => msg.to_frame(),
            Sbp::MsgUtcTime(msg) => msg.to_frame(),
            Sbp::MsgGpsTimeGnss(msg) => msg.to_frame(),
            Sbp::MsgUtcTimeGnss(msg) => msg.to_frame(),
            Sbp::MsgSettingsRegisterResp(msg) => msg.to_frame(),
            Sbp::MsgPosEcefDepA(msg) => msg.to_frame(),
            Sbp::MsgPosLlhDepA(msg) => msg.to_frame(),
            Sbp::MsgBaselineEcefDepA(msg) => msg.to_frame(),
            Sbp::MsgBaselineNedDepA(msg) => msg.to_frame(),
            Sbp::MsgVelEcefDepA(msg) => msg.to_frame(),
            Sbp::MsgVelNedDepA(msg) => msg.to_frame(),
            Sbp::MsgDopsDepA(msg) => msg.to_frame(),
            Sbp::MsgBaselineHeadingDepA(msg) => msg.to_frame(),
            Sbp::MsgDops(msg) => msg.to_frame(),
            Sbp::MsgPosEcef(msg) => msg.to_frame(),
            Sbp::MsgPosLlh(msg) => msg.to_frame(),
            Sbp::MsgBaselineEcef(msg) => msg.to_frame(),
            Sbp::MsgBaselineNed(msg) => msg.to_frame(),
            Sbp::MsgVelEcef(msg) => msg.to_frame(),
            Sbp::MsgVelNed(msg) => msg.to_frame(),
            Sbp::MsgBaselineHeading(msg) => msg.to_frame(),
            Sbp::MsgAgeCorrections(msg) => msg.to_frame(),
            Sbp::MsgPosLlhCov(msg) => msg.to_frame(),
            Sbp::MsgVelNedCov(msg) => msg.to_frame(),
            Sbp::MsgVelBody(msg) => msg.to_frame(),
            Sbp::MsgPosEcefCov(msg) => msg.to_frame(),
            Sbp::MsgVelEcefCov(msg) => msg.to_frame(),
            Sbp::MsgProtectionLevelDepA(msg) => msg.to_frame(),
            Sbp::MsgProtectionLevel(msg) => msg.to_frame(),
            Sbp::MsgPosLlhAcc(msg) => msg.to_frame(),
            Sbp::MsgOrientQuat(msg) => msg.to_frame(),
            Sbp::MsgOrientEuler(msg) => msg.to_frame(),
            Sbp::MsgAngularRate(msg) => msg.to_frame(),
            Sbp::MsgPosEcefGnss(msg) => msg.to_frame(),
            Sbp::MsgPosLlhGnss(msg) => msg.to_frame(),
            Sbp::MsgVelEcefGnss(msg) => msg.to_frame(),
            Sbp::MsgVelNedGnss(msg) => msg.to_frame(),
            Sbp::MsgPosLlhCovGnss(msg) => msg.to_frame(),
            Sbp::MsgVelNedCovGnss(msg) => msg.to_frame(),
            Sbp::MsgPosEcefCovGnss(msg) => msg.to_frame(),
            Sbp::MsgVelEcefCovGnss(msg) => msg.to_frame(),
            Sbp::MsgNdbEvent(msg) => msg.to_frame(),
            Sbp::MsgLog(msg) => msg.to_frame(),
            Sbp::MsgFwd(msg) => msg.to_frame(),
            Sbp::MsgSsrOrbitClockDepA(msg) => msg.to_frame(),
            Sbp::MsgSsrOrbitClock(msg) => msg.to_frame(),
            Sbp::MsgSsrCodeBiases(msg) => msg.to_frame(),
            Sbp::MsgSsrPhaseBiases(msg) => msg.to_frame(),
            Sbp::MsgSsrStecCorrectionDepA(msg) => msg.to_frame(),
            Sbp::MsgSsrGriddedCorrectionNoStdDepA(msg) => msg.to_frame(),
            Sbp::MsgSsrGridDefinitionDepA(msg) => msg.to_frame(),
            Sbp::MsgSsrTileDefinition(msg) => msg.to_frame(),
            Sbp::MsgSsrGriddedCorrectionDepA(msg) => msg.to_frame(),
            Sbp::MsgSsrStecCorrection(msg) => msg.to_frame(),
            Sbp::MsgSsrGriddedCorrection(msg) => msg.to_frame(),
            Sbp::MsgSsrSatelliteApc(msg) => msg.to_frame(),
            Sbp::MsgOsr(msg) => msg.to_frame(),
            Sbp::MsgUserData(msg) => msg.to_frame(),
            Sbp::MsgImuRaw(msg) => msg.to_frame(),
            Sbp::MsgImuAux(msg) => msg.to_frame(),
            Sbp::MsgMagRaw(msg) => msg.to_frame(),
            Sbp::MsgOdometry(msg) => msg.to_frame(),
            Sbp::MsgWheeltick(msg) => msg.to_frame(),
            Sbp::MsgFileioConfigReq(msg) => msg.to_frame(),
            Sbp::MsgFileioConfigResp(msg) => msg.to_frame(),
            Sbp::MsgSbasRaw(msg) => msg.to_frame(),
            Sbp::MsgLinuxCpuStateDepA(msg) => msg.to_frame(),
            Sbp::MsgLinuxMemStateDepA(msg) => msg.to_frame(),
            Sbp::MsgLinuxSysStateDepA(msg) => msg.to_frame(),
            Sbp::MsgLinuxProcessSocketCounts(msg) => msg.to_frame(),
            Sbp::MsgLinuxProcessSocketQueues(msg) => msg.to_frame(),
            Sbp::MsgLinuxSocketUsage(msg) => msg.to_frame(),
            Sbp::MsgLinuxProcessFdCount(msg) => msg.to_frame(),
            Sbp::MsgLinuxProcessFdSummary(msg) => msg.to_frame(),
            Sbp::MsgLinuxCpuState(msg) => msg.to_frame(),
            Sbp::MsgLinuxMemState(msg) => msg.to_frame(),
            Sbp::MsgLinuxSysState(msg) => msg.to_frame(),
            Sbp::MsgStartup(msg) => msg.to_frame(),
            Sbp::MsgDgnssStatus(msg) => msg.to_frame(),
            Sbp::MsgInsStatus(msg) => msg.to_frame(),
            Sbp::MsgCsacTelemetry(msg) => msg.to_frame(),
            Sbp::MsgCsacTelemetryLabels(msg) => msg.to_frame(),
            Sbp::MsgInsUpdates(msg) => msg.to_frame(),
            Sbp::MsgGnssTimeOffset(msg) => msg.to_frame(),
            Sbp::MsgPpsTime(msg) => msg.to_frame(),
            Sbp::MsgGroupMeta(msg) => msg.to_frame(),
            Sbp::MsgSolnMeta(msg) => msg.to_frame(),
            Sbp::MsgSolnMetaDepA(msg) => msg.to_frame(),
            Sbp::MsgStatusReport(msg) => msg.to_frame(),
            Sbp::MsgHeartbeat(msg) => msg.to_frame(),
            Sbp::Unknown(msg) => msg.to_frame(),
        }
    }

    fn write_frame(&self, buf: &mut Vec<u8>) -> Result<(), crate::FramerError> {
        match self {
            Sbp::MsgPrintDep(msg) => msg.write_frame(buf),
            Sbp::MsgTrackingStateDetailedDep(msg) => msg.write_frame(buf),
            Sbp::MsgTrackingStateDepB(msg) => msg.write_frame(buf),
            Sbp::MsgAcqResultDepB(msg) => msg.write_frame(buf),
            Sbp::MsgAcqResultDepA(msg) => msg.write_frame(buf),
            Sbp::MsgTrackingStateDepA(msg) => msg.write_frame(buf),
            Sbp::MsgThreadState(msg) => msg.write_frame(buf),
            Sbp::MsgUartStateDepa(msg) => msg.write_frame(buf),
            Sbp::MsgIarState(msg) => msg.write_frame(buf),
            Sbp::MsgEphemerisDepA(msg) => msg.write_frame(buf),
            Sbp::MsgMaskSatelliteDep(msg) => msg.write_frame(buf),
            Sbp::MsgTrackingIqDepA(msg) => msg.write_frame(buf),
            Sbp::MsgUartState(msg) => msg.write_frame(buf),
            Sbp::MsgAcqSvProfileDep(msg) => msg.write_frame(buf),
            Sbp::MsgAcqResultDepC(msg) => msg.write_frame(buf),
            Sbp::MsgTrackingStateDetailedDepA(msg) => msg.write_frame(buf),
            Sbp::MsgResetFilters(msg) => msg.write_frame(buf),
            Sbp::MsgInitBaseDep(msg) => msg.write_frame(buf),
            Sbp::MsgMaskSatellite(msg) => msg.write_frame(buf),
            Sbp::MsgTrackingIqDepB(msg) => msg.write_frame(buf),
            Sbp::MsgTrackingIq(msg) => msg.write_frame(buf),
            Sbp::MsgAcqSvProfile(msg) => msg.write_frame(buf),
            Sbp::MsgAcqResult(msg) => msg.write_frame(buf),
            Sbp::MsgTrackingState(msg) => msg.write_frame(buf),
            Sbp::MsgObsDepB(msg) => msg.write_frame(buf),
            Sbp::MsgBasePosLlh(msg) => msg.write_frame(buf),
            Sbp::MsgObsDepA(msg) => msg.write_frame(buf),
            Sbp::MsgEphemerisDepB(msg) => msg.write_frame(buf),
            Sbp::MsgEphemerisDepC(msg) => msg.write_frame(buf),
            Sbp::MsgBasePosEcef(msg) => msg.write_frame(buf),
            Sbp::MsgObsDepC(msg) => msg.write_frame(buf),
            Sbp::MsgObs(msg) => msg.write_frame(buf),
            Sbp::MsgSpecanDep(msg) => msg.write_frame(buf),
            Sbp::MsgSpecan(msg) => msg.write_frame(buf),
            Sbp::MsgMeasurementState(msg) => msg.write_frame(buf),
            Sbp::MsgSetTime(msg) => msg.write_frame(buf),
            Sbp::MsgAlmanac(msg) => msg.write_frame(buf),
            Sbp::MsgAlmanacGpsDep(msg) => msg.write_frame(buf),
            Sbp::MsgAlmanacGloDep(msg) => msg.write_frame(buf),
            Sbp::MsgAlmanacGps(msg) => msg.write_frame(buf),
            Sbp::MsgAlmanacGlo(msg) => msg.write_frame(buf),
            Sbp::MsgGloBiases(msg) => msg.write_frame(buf),
            Sbp::MsgEphemerisDepD(msg) => msg.write_frame(buf),
            Sbp::MsgEphemerisGpsDepE(msg) => msg.write_frame(buf),
            Sbp::MsgEphemerisSbasDepA(msg) => msg.write_frame(buf),
            Sbp::MsgEphemerisGloDepA(msg) => msg.write_frame(buf),
            Sbp::MsgEphemerisSbasDepB(msg) => msg.write_frame(buf),
            Sbp::MsgEphemerisGloDepB(msg) => msg.write_frame(buf),
            Sbp::MsgEphemerisGpsDepF(msg) => msg.write_frame(buf),
            Sbp::MsgEphemerisGloDepC(msg) => msg.write_frame(buf),
            Sbp::MsgEphemerisGloDepD(msg) => msg.write_frame(buf),
            Sbp::MsgEphemerisBds(msg) => msg.write_frame(buf),
            Sbp::MsgEphemerisGps(msg) => msg.write_frame(buf),
            Sbp::MsgEphemerisGlo(msg) => msg.write_frame(buf),
            Sbp::MsgEphemerisSbas(msg) => msg.write_frame(buf),
            Sbp::MsgEphemerisGal(msg) => msg.write_frame(buf),
            Sbp::MsgEphemerisQzss(msg) => msg.write_frame(buf),
            Sbp::MsgIono(msg) => msg.write_frame(buf),
            Sbp::MsgSvConfigurationGpsDep(msg) => msg.write_frame(buf),
            Sbp::MsgGroupDelayDepA(msg) => msg.write_frame(buf),
            Sbp::MsgGroupDelayDepB(msg) => msg.write_frame(buf),
            Sbp::MsgGroupDelay(msg) => msg.write_frame(buf),
            Sbp::MsgEphemerisGalDepA(msg) => msg.write_frame(buf),
            Sbp::MsgGnssCapb(msg) => msg.write_frame(buf),
            Sbp::MsgSvAzEl(msg) => msg.write_frame(buf),
            Sbp::MsgSettingsWrite(msg) => msg.write_frame(buf),
            Sbp::MsgSettingsSave(msg) => msg.write_frame(buf),
            Sbp::MsgSettingsReadByIndexReq(msg) => msg.write_frame(buf),
            Sbp::MsgFileioReadResp(msg) => msg.write_frame(buf),
            Sbp::MsgSettingsReadReq(msg) => msg.write_frame(buf),
            Sbp::MsgSettingsReadResp(msg) => msg.write_frame(buf),
            Sbp::MsgSettingsReadByIndexDone(msg) => msg.write_frame(buf),
            Sbp::MsgSettingsReadByIndexResp(msg) => msg.write_frame(buf),
            Sbp::MsgFileioReadReq(msg) => msg.write_frame(buf),
            Sbp::MsgFileioReadDirReq(msg) => msg.write_frame(buf),
            Sbp::MsgFileioReadDirResp(msg) => msg.write_frame(buf),
            Sbp::MsgFileioWriteResp(msg) => msg.write_frame(buf),
            Sbp::MsgFileioRemove(msg) => msg.write_frame(buf),
            Sbp::MsgFileioWriteReq(msg) => msg.write_frame(buf),
            Sbp::MsgSettingsRegister(msg) => msg.write_frame(buf),
            Sbp::MsgSettingsWriteResp(msg) => msg.write_frame(buf),
            Sbp::MsgBootloaderHandshakeDepA(msg) => msg.write_frame(buf),
            Sbp::MsgBootloaderJumpToApp(msg) => msg.write_frame(buf),
            Sbp::MsgResetDep(msg) => msg.write_frame(buf),
            Sbp::MsgBootloaderHandshakeReq(msg) => msg.write_frame(buf),
            Sbp::MsgBootloaderHandshakeResp(msg) => msg.write_frame(buf),
            Sbp::MsgDeviceMonitor(msg) => msg.write_frame(buf),
            Sbp::MsgReset(msg) => msg.write_frame(buf),
            Sbp::MsgCommandReq(msg) => msg.write_frame(buf),
            Sbp::MsgCommandResp(msg) => msg.write_frame(buf),
            Sbp::MsgNetworkStateReq(msg) => msg.write_frame(buf),
            Sbp::MsgNetworkStateResp(msg) => msg.write_frame(buf),
            Sbp::MsgCommandOutput(msg) => msg.write_frame(buf),
            Sbp::MsgNetworkBandwidthUsage(msg) => msg.write_frame(buf),
            Sbp::MsgCellModemStatus(msg) => msg.write_frame(buf),
            Sbp::MsgFrontEndGain(msg) => msg.write_frame(buf),
            Sbp::MsgCwResults(msg) => msg.write_frame(buf),
            Sbp::MsgCwStart(msg) => msg.write_frame(buf),
            Sbp::MsgNapDeviceDnaResp(msg) => msg.write_frame(buf),
            Sbp::MsgNapDeviceDnaReq(msg) => msg.write_frame(buf),
            Sbp::MsgFlashDone(msg) => msg.write_frame(buf),
            Sbp::MsgFlashReadResp(msg) => msg.write_frame(buf),
            Sbp::MsgFlashErase(msg) => msg.write_frame(buf),
            Sbp::MsgStmFlashLockSector(msg) => msg.write_frame(buf),
            Sbp::MsgStmFlashUnlockSector(msg) => msg.write_frame(buf),
            Sbp::MsgStmUniqueIdResp(msg) => msg.write_frame(buf),
            Sbp::MsgFlashProgram(msg) => msg.write_frame(buf),
            Sbp::MsgFlashReadReq(msg) => msg.write_frame(buf),
            Sbp::MsgStmUniqueIdReq(msg) => msg.write_frame(buf),
            Sbp::MsgM25FlashWriteStatus(msg) => msg.write_frame(buf),
            Sbp::MsgGpsTimeDepA(msg) => msg.write_frame(buf),
            Sbp::MsgExtEvent(msg) => msg.write_frame(buf),
            Sbp::MsgGpsTime(msg) => msg.write_frame(buf),
            Sbp::MsgUtcTime(msg) => msg.write_frame(buf),
            Sbp::MsgGpsTimeGnss(msg) => msg.write_frame(buf),
            Sbp::MsgUtcTimeGnss(msg) => msg.write_frame(buf),
            Sbp::MsgSettingsRegisterResp(msg) => msg.write_frame(buf),
            Sbp::MsgPosEcefDepA(msg) => msg.write_frame(buf),
            Sbp::MsgPosLlhDepA(msg) => msg.write_frame(buf),
            Sbp::MsgBaselineEcefDepA(msg) => msg.write_frame(buf),
            Sbp::MsgBaselineNedDepA(msg) => msg.write_frame(buf),
            Sbp::MsgVelEcefDepA(msg) => msg.write_frame(buf),
            Sbp::MsgVelNedDepA(msg) => msg.write_frame(buf),
            Sbp::MsgDopsDepA(msg) => msg.write_frame(buf),
            Sbp::MsgBaselineHeadingDepA(msg) => msg.write_frame(buf),
            Sbp::MsgDops(msg) => msg.write_frame(buf),
            Sbp::MsgPosEcef(msg) => msg.write_frame(buf),
            Sbp::MsgPosLlh(msg) => msg.write_frame(buf),
            Sbp::MsgBaselineEcef(msg) => msg.write_frame(buf),
            Sbp::MsgBaselineNed(msg) => msg.write_frame(buf),
            Sbp::MsgVelEcef(msg) => msg.write_frame(buf),
            Sbp::MsgVelNed(msg) => msg.write_frame(buf),
            Sbp::MsgBaselineHeading(msg) => msg.write_frame(buf),
            Sbp::MsgAgeCorrections(msg) => msg.write_frame(buf),
            Sbp::MsgPosLlhCov(msg) => msg.write_frame(buf),
            Sbp::MsgVelNedCov(msg) => msg.write_frame(buf),
            Sbp::MsgVelBody(msg) => msg.write_frame(buf),
            Sbp::MsgPosEcefCov(msg) => msg.write_frame(buf),
            Sbp::MsgVelEcefCov(msg) => msg.write_frame(buf),
            Sbp::MsgProtectionLevelDepA(msg) => msg.write_frame(buf),
            Sbp::MsgProtectionLevel(msg) => msg.write_frame(buf),
            Sbp::MsgPosLlhAcc(msg) => msg.write_frame(buf),
            Sbp::MsgOrientQuat(msg) => msg.write_frame(buf),
            Sbp::MsgOrientEuler(msg) => msg.write_frame(buf),
            Sbp::MsgAngularRate(msg) => msg.write_frame(buf),
            Sbp::MsgPosEcefGnss(msg) => msg.write_frame(buf),
            Sbp::MsgPosLlhGnss(msg) => msg.write_frame(buf),
            Sbp::MsgVelEcefGnss(msg) => msg.write_frame(buf),
            Sbp::MsgVelNedGnss(msg) => msg.write_frame(buf),
            Sbp::MsgPosLlhCovGnss(msg) => msg.write_frame(buf),
            Sbp::MsgVelNedCovGnss(msg) => msg.write_frame(buf),
            Sbp::MsgPosEcefCovGnss(msg) => msg.write_frame(buf),
            Sbp::MsgVelEcefCovGnss(msg) => msg.write_frame(buf),
            Sbp::MsgNdbEvent(msg) => msg.write_frame(buf),
            Sbp::MsgLog(msg) => msg.write_frame(buf),
            Sbp::MsgFwd(msg) => msg.write_frame(buf),
            Sbp::MsgSsrOrbitClockDepA(msg) => msg.write_frame(buf),
            Sbp::MsgSsrOrbitClock(msg) => msg.write_frame(buf),
            Sbp::MsgSsrCodeBiases(msg) => msg.write_frame(buf),
            Sbp::MsgSsrPhaseBiases(msg) => msg.write_frame(buf),
            Sbp::MsgSsrStecCorrectionDepA(msg) => msg.write_frame(buf),
            Sbp::MsgSsrGriddedCorrectionNoStdDepA(msg) => msg.write_frame(buf),
            Sbp::MsgSsrGridDefinitionDepA(msg) => msg.write_frame(buf),
            Sbp::MsgSsrTileDefinition(msg) => msg.write_frame(buf),
            Sbp::MsgSsrGriddedCorrectionDepA(msg) => msg.write_frame(buf),
            Sbp::MsgSsrStecCorrection(msg) => msg.write_frame(buf),
            Sbp::MsgSsrGriddedCorrection(msg) => msg.write_frame(buf),
            Sbp::MsgSsrSatelliteApc(msg) => msg.write_frame(buf),
            Sbp::MsgOsr(msg) => msg.write_frame(buf),
            Sbp::MsgUserData(msg) => msg.write_frame(buf),
            Sbp::MsgImuRaw(msg) => msg.write_frame(buf),
            Sbp::MsgImuAux(msg) => msg.write_frame(buf),
            Sbp::MsgMagRaw(msg) => msg.write_frame(buf),
            Sbp::MsgOdometry(msg) => msg.write_frame(buf),
            Sbp::MsgWheeltick(msg) => msg.write_frame(buf),
            Sbp::MsgFileioConfigReq(msg) => msg.write_frame(buf),
            Sbp::MsgFileioConfigResp(msg) => msg.write_frame(buf),
            Sbp::MsgSbasRaw(msg) => msg.write_frame(buf),
            Sbp::MsgLinuxCpuStateDepA(msg) => msg.write_frame(buf),
            Sbp::MsgLinuxMemStateDepA(msg) => msg.write_frame(buf),
            Sbp::MsgLinuxSysStateDepA(msg) => msg.write_frame(buf),
            Sbp::MsgLinuxProcessSocketCounts(msg) => msg.write_frame(buf),
            Sbp::MsgLinuxProcessSocketQueues(msg) => msg.write_frame(buf),
            Sbp::MsgLinuxSocketUsage(msg) => msg.write_frame(buf),
            Sbp::MsgLinuxProcessFdCount(msg) => msg.write_frame(buf),
            Sbp::MsgLinuxProcessFdSummary(msg) => msg.write_frame(buf),
            Sbp::MsgLinuxCpuState(msg) => msg.write_frame(buf),
            Sbp::MsgLinuxMemState(msg) => msg.write_frame(buf),
            Sbp::MsgLinuxSysState(msg) => msg.write_frame(buf),
            Sbp::MsgStartup(msg) => msg.write_frame(buf),
            Sbp::MsgDgnssStatus(msg) => msg.write_frame(buf),
            Sbp::MsgInsStatus(msg) => msg.write_frame(buf),
            Sbp::MsgCsacTelemetry(msg) => msg.write_frame(buf),
            Sbp::MsgCsacTelemetryLabels(msg) => msg.write_frame(buf),
            Sbp::MsgInsUpdates(msg) => msg.write_frame(buf),
            Sbp::MsgGnssTimeOffset(msg) => msg.write_frame(buf),
            Sbp::MsgPpsTime(msg) => msg.write_frame(buf),
            Sbp::MsgGroupMeta(msg) => msg.write_frame(buf),
            Sbp::MsgSolnMeta(msg) => msg.write_frame(buf),
            Sbp::MsgSolnMetaDepA(msg) => msg.write_frame(buf),
            Sbp::MsgStatusReport(msg) => msg.write_frame(buf),
            Sbp::MsgHeartbeat(msg) => msg.write_frame(buf),
            Sbp::Unknown(msg) => msg.write_frame(buf),
        }
    }

    #[cfg(feature = "swiftnav-rs")]
    fn gps_time(
        &self,
    ) -> Option<std::result::Result<crate::time::MessageTime, crate::time::GpsTimeError>> {
        match self {
            Sbp::MsgPrintDep(msg) => msg.gps_time(),
            Sbp::MsgTrackingStateDetailedDep(msg) => msg.gps_time(),
            Sbp::MsgTrackingStateDepB(msg) => msg.gps_time(),
            Sbp::MsgAcqResultDepB(msg) => msg.gps_time(),
            Sbp::MsgAcqResultDepA(msg) => msg.gps_time(),
            Sbp::MsgTrackingStateDepA(msg) => msg.gps_time(),
            Sbp::MsgThreadState(msg) => msg.gps_time(),
            Sbp::MsgUartStateDepa(msg) => msg.gps_time(),
            Sbp::MsgIarState(msg) => msg.gps_time(),
            Sbp::MsgEphemerisDepA(msg) => msg.gps_time(),
            Sbp::MsgMaskSatelliteDep(msg) => msg.gps_time(),
            Sbp::MsgTrackingIqDepA(msg) => msg.gps_time(),
            Sbp::MsgUartState(msg) => msg.gps_time(),
            Sbp::MsgAcqSvProfileDep(msg) => msg.gps_time(),
            Sbp::MsgAcqResultDepC(msg) => msg.gps_time(),
            Sbp::MsgTrackingStateDetailedDepA(msg) => msg.gps_time(),
            Sbp::MsgResetFilters(msg) => msg.gps_time(),
            Sbp::MsgInitBaseDep(msg) => msg.gps_time(),
            Sbp::MsgMaskSatellite(msg) => msg.gps_time(),
            Sbp::MsgTrackingIqDepB(msg) => msg.gps_time(),
            Sbp::MsgTrackingIq(msg) => msg.gps_time(),
            Sbp::MsgAcqSvProfile(msg) => msg.gps_time(),
            Sbp::MsgAcqResult(msg) => msg.gps_time(),
            Sbp::MsgTrackingState(msg) => msg.gps_time(),
            Sbp::MsgObsDepB(msg) => msg.gps_time(),
            Sbp::MsgBasePosLlh(msg) => msg.gps_time(),
            Sbp::MsgObsDepA(msg) => msg.gps_time(),
            Sbp::MsgEphemerisDepB(msg) => msg.gps_time(),
            Sbp::MsgEphemerisDepC(msg) => msg.gps_time(),
            Sbp::MsgBasePosEcef(msg) => msg.gps_time(),
            Sbp::MsgObsDepC(msg) => msg.gps_time(),
            Sbp::MsgObs(msg) => msg.gps_time(),
            Sbp::MsgSpecanDep(msg) => msg.gps_time(),
            Sbp::MsgSpecan(msg) => msg.gps_time(),
            Sbp::MsgMeasurementState(msg) => msg.gps_time(),
            Sbp::MsgSetTime(msg) => msg.gps_time(),
            Sbp::MsgAlmanac(msg) => msg.gps_time(),
            Sbp::MsgAlmanacGpsDep(msg) => msg.gps_time(),
            Sbp::MsgAlmanacGloDep(msg) => msg.gps_time(),
            Sbp::MsgAlmanacGps(msg) => msg.gps_time(),
            Sbp::MsgAlmanacGlo(msg) => msg.gps_time(),
            Sbp::MsgGloBiases(msg) => msg.gps_time(),
            Sbp::MsgEphemerisDepD(msg) => msg.gps_time(),
            Sbp::MsgEphemerisGpsDepE(msg) => msg.gps_time(),
            Sbp::MsgEphemerisSbasDepA(msg) => msg.gps_time(),
            Sbp::MsgEphemerisGloDepA(msg) => msg.gps_time(),
            Sbp::MsgEphemerisSbasDepB(msg) => msg.gps_time(),
            Sbp::MsgEphemerisGloDepB(msg) => msg.gps_time(),
            Sbp::MsgEphemerisGpsDepF(msg) => msg.gps_time(),
            Sbp::MsgEphemerisGloDepC(msg) => msg.gps_time(),
            Sbp::MsgEphemerisGloDepD(msg) => msg.gps_time(),
            Sbp::MsgEphemerisBds(msg) => msg.gps_time(),
            Sbp::MsgEphemerisGps(msg) => msg.gps_time(),
            Sbp::MsgEphemerisGlo(msg) => msg.gps_time(),
            Sbp::MsgEphemerisSbas(msg) => msg.gps_time(),
            Sbp::MsgEphemerisGal(msg) => msg.gps_time(),
            Sbp::MsgEphemerisQzss(msg) => msg.gps_time(),
            Sbp::MsgIono(msg) => msg.gps_time(),
            Sbp::MsgSvConfigurationGpsDep(msg) => msg.gps_time(),
            Sbp::MsgGroupDelayDepA(msg) => msg.gps_time(),
            Sbp::MsgGroupDelayDepB(msg) => msg.gps_time(),
            Sbp::MsgGroupDelay(msg) => msg.gps_time(),
            Sbp::MsgEphemerisGalDepA(msg) => msg.gps_time(),
            Sbp::MsgGnssCapb(msg) => msg.gps_time(),
            Sbp::MsgSvAzEl(msg) => msg.gps_time(),
            Sbp::MsgSettingsWrite(msg) => msg.gps_time(),
            Sbp::MsgSettingsSave(msg) => msg.gps_time(),
            Sbp::MsgSettingsReadByIndexReq(msg) => msg.gps_time(),
            Sbp::MsgFileioReadResp(msg) => msg.gps_time(),
            Sbp::MsgSettingsReadReq(msg) => msg.gps_time(),
            Sbp::MsgSettingsReadResp(msg) => msg.gps_time(),
            Sbp::MsgSettingsReadByIndexDone(msg) => msg.gps_time(),
            Sbp::MsgSettingsReadByIndexResp(msg) => msg.gps_time(),
            Sbp::MsgFileioReadReq(msg) => msg.gps_time(),
            Sbp::MsgFileioReadDirReq(msg) => msg.gps_time(),
            Sbp::MsgFileioReadDirResp(msg) => msg.gps_time(),
            Sbp::MsgFileioWriteResp(msg) => msg.gps_time(),
            Sbp::MsgFileioRemove(msg) => msg.gps_time(),
            Sbp::MsgFileioWriteReq(msg) => msg.gps_time(),
            Sbp::MsgSettingsRegister(msg) => msg.gps_time(),
            Sbp::MsgSettingsWriteResp(msg) => msg.gps_time(),
            Sbp::MsgBootloaderHandshakeDepA(msg) => msg.gps_time(),
            Sbp::MsgBootloaderJumpToApp(msg) => msg.gps_time(),
            Sbp::MsgResetDep(msg) => msg.gps_time(),
            Sbp::MsgBootloaderHandshakeReq(msg) => msg.gps_time(),
            Sbp::MsgBootloaderHandshakeResp(msg) => msg.gps_time(),
            Sbp::MsgDeviceMonitor(msg) => msg.gps_time(),
            Sbp::MsgReset(msg) => msg.gps_time(),
            Sbp::MsgCommandReq(msg) => msg.gps_time(),
            Sbp::MsgCommandResp(msg) => msg.gps_time(),
            Sbp::MsgNetworkStateReq(msg) => msg.gps_time(),
            Sbp::MsgNetworkStateResp(msg) => msg.gps_time(),
            Sbp::MsgCommandOutput(msg) => msg.gps_time(),
            Sbp::MsgNetworkBandwidthUsage(msg) => msg.gps_time(),
            Sbp::MsgCellModemStatus(msg) => msg.gps_time(),
            Sbp::MsgFrontEndGain(msg) => msg.gps_time(),
            Sbp::MsgCwResults(msg) => msg.gps_time(),
            Sbp::MsgCwStart(msg) => msg.gps_time(),
            Sbp::MsgNapDeviceDnaResp(msg) => msg.gps_time(),
            Sbp::MsgNapDeviceDnaReq(msg) => msg.gps_time(),
            Sbp::MsgFlashDone(msg) => msg.gps_time(),
            Sbp::MsgFlashReadResp(msg) => msg.gps_time(),
            Sbp::MsgFlashErase(msg) => msg.gps_time(),
            Sbp::MsgStmFlashLockSector(msg) => msg.gps_time(),
            Sbp::MsgStmFlashUnlockSector(msg) => msg.gps_time(),
            Sbp::MsgStmUniqueIdResp(msg) => msg.gps_time(),
            Sbp::MsgFlashProgram(msg) => msg.gps_time(),
            Sbp::MsgFlashReadReq(msg) => msg.gps_time(),
            Sbp::MsgStmUniqueIdReq(msg) => msg.gps_time(),
            Sbp::MsgM25FlashWriteStatus(msg) => msg.gps_time(),
            Sbp::MsgGpsTimeDepA(msg) => msg.gps_time(),
            Sbp::MsgExtEvent(msg) => msg.gps_time(),
            Sbp::MsgGpsTime(msg) => msg.gps_time(),
            Sbp::MsgUtcTime(msg) => msg.gps_time(),
            Sbp::MsgGpsTimeGnss(msg) => msg.gps_time(),
            Sbp::MsgUtcTimeGnss(msg) => msg.gps_time(),
            Sbp::MsgSettingsRegisterResp(msg) => msg.gps_time(),
            Sbp::MsgPosEcefDepA(msg) => msg.gps_time(),
            Sbp::MsgPosLlhDepA(msg) => msg.gps_time(),
            Sbp::MsgBaselineEcefDepA(msg) => msg.gps_time(),
            Sbp::MsgBaselineNedDepA(msg) => msg.gps_time(),
            Sbp::MsgVelEcefDepA(msg) => msg.gps_time(),
            Sbp::MsgVelNedDepA(msg) => msg.gps_time(),
            Sbp::MsgDopsDepA(msg) => msg.gps_time(),
            Sbp::MsgBaselineHeadingDepA(msg) => msg.gps_time(),
            Sbp::MsgDops(msg) => msg.gps_time(),
            Sbp::MsgPosEcef(msg) => msg.gps_time(),
            Sbp::MsgPosLlh(msg) => msg.gps_time(),
            Sbp::MsgBaselineEcef(msg) => msg.gps_time(),
            Sbp::MsgBaselineNed(msg) => msg.gps_time(),
            Sbp::MsgVelEcef(msg) => msg.gps_time(),
            Sbp::MsgVelNed(msg) => msg.gps_time(),
            Sbp::MsgBaselineHeading(msg) => msg.gps_time(),
            Sbp::MsgAgeCorrections(msg) => msg.gps_time(),
            Sbp::MsgPosLlhCov(msg) => msg.gps_time(),
            Sbp::MsgVelNedCov(msg) => msg.gps_time(),
            Sbp::MsgVelBody(msg) => msg.gps_time(),
            Sbp::MsgPosEcefCov(msg) => msg.gps_time(),
            Sbp::MsgVelEcefCov(msg) => msg.gps_time(),
            Sbp::MsgProtectionLevelDepA(msg) => msg.gps_time(),
            Sbp::MsgProtectionLevel(msg) => msg.gps_time(),
            Sbp::MsgPosLlhAcc(msg) => msg.gps_time(),
            Sbp::MsgOrientQuat(msg) => msg.gps_time(),
            Sbp::MsgOrientEuler(msg) => msg.gps_time(),
            Sbp::MsgAngularRate(msg) => msg.gps_time(),
            Sbp::MsgPosEcefGnss(msg) => msg.gps_time(),
            Sbp::MsgPosLlhGnss(msg) => msg.gps_time(),
            Sbp::MsgVelEcefGnss(msg) => msg.gps_time(),
            Sbp::MsgVelNedGnss(msg) => msg.gps_time(),
            Sbp::MsgPosLlhCovGnss(msg) => msg.gps_time(),
            Sbp::MsgVelNedCovGnss(msg) => msg.gps_time(),
            Sbp::MsgPosEcefCovGnss(msg) => msg.gps_time(),
            Sbp::MsgVelEcefCovGnss(msg) => msg.gps_time(),
            Sbp::MsgNdbEvent(msg) => msg.gps_time(),
            Sbp::MsgLog(msg) => msg.gps_time(),
            Sbp::MsgFwd(msg) => msg.gps_time(),
            Sbp::MsgSsrOrbitClockDepA(msg) => msg.gps_time(),
            Sbp::MsgSsrOrbitClock(msg) => msg.gps_time(),
            Sbp::MsgSsrCodeBiases(msg) => msg.gps_time(),
            Sbp::MsgSsrPhaseBiases(msg) => msg.gps_time(),
            Sbp::MsgSsrStecCorrectionDepA(msg) => msg.gps_time(),
            Sbp::MsgSsrGriddedCorrectionNoStdDepA(msg) => msg.gps_time(),
            Sbp::MsgSsrGridDefinitionDepA(msg) => msg.gps_time(),
            Sbp::MsgSsrTileDefinition(msg) => msg.gps_time(),
            Sbp::MsgSsrGriddedCorrectionDepA(msg) => msg.gps_time(),
            Sbp::MsgSsrStecCorrection(msg) => msg.gps_time(),
            Sbp::MsgSsrGriddedCorrection(msg) => msg.gps_time(),
            Sbp::MsgSsrSatelliteApc(msg) => msg.gps_time(),
            Sbp::MsgOsr(msg) => msg.gps_time(),
            Sbp::MsgUserData(msg) => msg.gps_time(),
            Sbp::MsgImuRaw(msg) => msg.gps_time(),
            Sbp::MsgImuAux(msg) => msg.gps_time(),
            Sbp::MsgMagRaw(msg) => msg.gps_time(),
            Sbp::MsgOdometry(msg) => msg.gps_time(),
            Sbp::MsgWheeltick(msg) => msg.gps_time(),
            Sbp::MsgFileioConfigReq(msg) => msg.gps_time(),
            Sbp::MsgFileioConfigResp(msg) => msg.gps_time(),
            Sbp::MsgSbasRaw(msg) => msg.gps_time(),
            Sbp::MsgLinuxCpuStateDepA(msg) => msg.gps_time(),
            Sbp::MsgLinuxMemStateDepA(msg) => msg.gps_time(),
            Sbp::MsgLinuxSysStateDepA(msg) => msg.gps_time(),
            Sbp::MsgLinuxProcessSocketCounts(msg) => msg.gps_time(),
            Sbp::MsgLinuxProcessSocketQueues(msg) => msg.gps_time(),
            Sbp::MsgLinuxSocketUsage(msg) => msg.gps_time(),
            Sbp::MsgLinuxProcessFdCount(msg) => msg.gps_time(),
            Sbp::MsgLinuxProcessFdSummary(msg) => msg.gps_time(),
            Sbp::MsgLinuxCpuState(msg) => msg.gps_time(),
            Sbp::MsgLinuxMemState(msg) => msg.gps_time(),
            Sbp::MsgLinuxSysState(msg) => msg.gps_time(),
            Sbp::MsgStartup(msg) => msg.gps_time(),
            Sbp::MsgDgnssStatus(msg) => msg.gps_time(),
            Sbp::MsgInsStatus(msg) => msg.gps_time(),
            Sbp::MsgCsacTelemetry(msg) => msg.gps_time(),
            Sbp::MsgCsacTelemetryLabels(msg) => msg.gps_time(),
            Sbp::MsgInsUpdates(msg) => msg.gps_time(),
            Sbp::MsgGnssTimeOffset(msg) => msg.gps_time(),
            Sbp::MsgPpsTime(msg) => msg.gps_time(),
            Sbp::MsgGroupMeta(msg) => msg.gps_time(),
            Sbp::MsgSolnMeta(msg) => msg.gps_time(),
            Sbp::MsgSolnMetaDepA(msg) => msg.gps_time(),
            Sbp::MsgStatusReport(msg) => msg.gps_time(),
            Sbp::MsgHeartbeat(msg) => msg.gps_time(),
            Sbp::Unknown(msg) => msg.gps_time(),
        }
    }
}

impl crate::SbpSerialize for Sbp {
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        match self {
            Sbp::MsgPrintDep(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgTrackingStateDetailedDep(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgTrackingStateDepB(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgAcqResultDepB(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgAcqResultDepA(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgTrackingStateDepA(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgThreadState(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgUartStateDepa(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgIarState(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgEphemerisDepA(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgMaskSatelliteDep(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgTrackingIqDepA(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgUartState(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgAcqSvProfileDep(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgAcqResultDepC(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgTrackingStateDetailedDepA(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgResetFilters(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgInitBaseDep(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgMaskSatellite(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgTrackingIqDepB(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgTrackingIq(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgAcqSvProfile(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgAcqResult(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgTrackingState(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgObsDepB(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgBasePosLlh(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgObsDepA(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgEphemerisDepB(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgEphemerisDepC(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgBasePosEcef(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgObsDepC(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgObs(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgSpecanDep(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgSpecan(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgMeasurementState(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgSetTime(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgAlmanac(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgAlmanacGpsDep(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgAlmanacGloDep(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgAlmanacGps(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgAlmanacGlo(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgGloBiases(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgEphemerisDepD(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgEphemerisGpsDepE(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgEphemerisSbasDepA(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgEphemerisGloDepA(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgEphemerisSbasDepB(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgEphemerisGloDepB(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgEphemerisGpsDepF(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgEphemerisGloDepC(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgEphemerisGloDepD(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgEphemerisBds(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgEphemerisGps(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgEphemerisGlo(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgEphemerisSbas(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgEphemerisGal(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgEphemerisQzss(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgIono(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgSvConfigurationGpsDep(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgGroupDelayDepA(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgGroupDelayDepB(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgGroupDelay(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgEphemerisGalDepA(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgGnssCapb(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgSvAzEl(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgSettingsWrite(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgSettingsSave(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgSettingsReadByIndexReq(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgFileioReadResp(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgSettingsReadReq(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgSettingsReadResp(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgSettingsReadByIndexDone(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgSettingsReadByIndexResp(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgFileioReadReq(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgFileioReadDirReq(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgFileioReadDirResp(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgFileioWriteResp(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgFileioRemove(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgFileioWriteReq(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgSettingsRegister(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgSettingsWriteResp(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgBootloaderHandshakeDepA(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgBootloaderJumpToApp(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgResetDep(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgBootloaderHandshakeReq(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgBootloaderHandshakeResp(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgDeviceMonitor(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgReset(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgCommandReq(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgCommandResp(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgNetworkStateReq(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgNetworkStateResp(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgCommandOutput(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgNetworkBandwidthUsage(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgCellModemStatus(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgFrontEndGain(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgCwResults(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgCwStart(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgNapDeviceDnaResp(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgNapDeviceDnaReq(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgFlashDone(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgFlashReadResp(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgFlashErase(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgStmFlashLockSector(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgStmFlashUnlockSector(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgStmUniqueIdResp(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgFlashProgram(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgFlashReadReq(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgStmUniqueIdReq(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgM25FlashWriteStatus(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgGpsTimeDepA(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgExtEvent(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgGpsTime(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgUtcTime(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgGpsTimeGnss(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgUtcTimeGnss(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgSettingsRegisterResp(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgPosEcefDepA(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgPosLlhDepA(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgBaselineEcefDepA(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgBaselineNedDepA(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgVelEcefDepA(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgVelNedDepA(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgDopsDepA(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgBaselineHeadingDepA(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgDops(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgPosEcef(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgPosLlh(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgBaselineEcef(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgBaselineNed(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgVelEcef(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgVelNed(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgBaselineHeading(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgAgeCorrections(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgPosLlhCov(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgVelNedCov(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgVelBody(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgPosEcefCov(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgVelEcefCov(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgProtectionLevelDepA(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgProtectionLevel(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgPosLlhAcc(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgOrientQuat(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgOrientEuler(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgAngularRate(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgPosEcefGnss(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgPosLlhGnss(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgVelEcefGnss(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgVelNedGnss(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgPosLlhCovGnss(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgVelNedCovGnss(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgPosEcefCovGnss(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgVelEcefCovGnss(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgNdbEvent(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgLog(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgFwd(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgSsrOrbitClockDepA(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgSsrOrbitClock(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgSsrCodeBiases(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgSsrPhaseBiases(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgSsrStecCorrectionDepA(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgSsrGriddedCorrectionNoStdDepA(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgSsrGridDefinitionDepA(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgSsrTileDefinition(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgSsrGriddedCorrectionDepA(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgSsrStecCorrection(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgSsrGriddedCorrection(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgSsrSatelliteApc(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgOsr(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgUserData(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgImuRaw(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgImuAux(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgMagRaw(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgOdometry(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgWheeltick(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgFileioConfigReq(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgFileioConfigResp(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgSbasRaw(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgLinuxCpuStateDepA(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgLinuxMemStateDepA(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgLinuxSysStateDepA(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgLinuxProcessSocketCounts(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgLinuxProcessSocketQueues(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgLinuxSocketUsage(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgLinuxProcessFdCount(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgLinuxProcessFdSummary(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgLinuxCpuState(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgLinuxMemState(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgLinuxSysState(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgStartup(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgDgnssStatus(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgInsStatus(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgCsacTelemetry(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgCsacTelemetryLabels(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgInsUpdates(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgGnssTimeOffset(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgPpsTime(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgGroupMeta(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgSolnMeta(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgSolnMetaDepA(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgStatusReport(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::MsgHeartbeat(msg) => msg.append_to_sbp_buffer(buf),
            Sbp::Unknown(msg) => msg.append_to_sbp_buffer(buf),
        }
    }

    fn sbp_size(&self) -> usize {
        match self {
            Sbp::MsgPrintDep(msg) => msg.sbp_size(),
            Sbp::MsgTrackingStateDetailedDep(msg) => msg.sbp_size(),
            Sbp::MsgTrackingStateDepB(msg) => msg.sbp_size(),
            Sbp::MsgAcqResultDepB(msg) => msg.sbp_size(),
            Sbp::MsgAcqResultDepA(msg) => msg.sbp_size(),
            Sbp::MsgTrackingStateDepA(msg) => msg.sbp_size(),
            Sbp::MsgThreadState(msg) => msg.sbp_size(),
            Sbp::MsgUartStateDepa(msg) => msg.sbp_size(),
            Sbp::MsgIarState(msg) => msg.sbp_size(),
            Sbp::MsgEphemerisDepA(msg) => msg.sbp_size(),
            Sbp::MsgMaskSatelliteDep(msg) => msg.sbp_size(),
            Sbp::MsgTrackingIqDepA(msg) => msg.sbp_size(),
            Sbp::MsgUartState(msg) => msg.sbp_size(),
            Sbp::MsgAcqSvProfileDep(msg) => msg.sbp_size(),
            Sbp::MsgAcqResultDepC(msg) => msg.sbp_size(),
            Sbp::MsgTrackingStateDetailedDepA(msg) => msg.sbp_size(),
            Sbp::MsgResetFilters(msg) => msg.sbp_size(),
            Sbp::MsgInitBaseDep(msg) => msg.sbp_size(),
            Sbp::MsgMaskSatellite(msg) => msg.sbp_size(),
            Sbp::MsgTrackingIqDepB(msg) => msg.sbp_size(),
            Sbp::MsgTrackingIq(msg) => msg.sbp_size(),
            Sbp::MsgAcqSvProfile(msg) => msg.sbp_size(),
            Sbp::MsgAcqResult(msg) => msg.sbp_size(),
            Sbp::MsgTrackingState(msg) => msg.sbp_size(),
            Sbp::MsgObsDepB(msg) => msg.sbp_size(),
            Sbp::MsgBasePosLlh(msg) => msg.sbp_size(),
            Sbp::MsgObsDepA(msg) => msg.sbp_size(),
            Sbp::MsgEphemerisDepB(msg) => msg.sbp_size(),
            Sbp::MsgEphemerisDepC(msg) => msg.sbp_size(),
            Sbp::MsgBasePosEcef(msg) => msg.sbp_size(),
            Sbp::MsgObsDepC(msg) => msg.sbp_size(),
            Sbp::MsgObs(msg) => msg.sbp_size(),
            Sbp::MsgSpecanDep(msg) => msg.sbp_size(),
            Sbp::MsgSpecan(msg) => msg.sbp_size(),
            Sbp::MsgMeasurementState(msg) => msg.sbp_size(),
            Sbp::MsgSetTime(msg) => msg.sbp_size(),
            Sbp::MsgAlmanac(msg) => msg.sbp_size(),
            Sbp::MsgAlmanacGpsDep(msg) => msg.sbp_size(),
            Sbp::MsgAlmanacGloDep(msg) => msg.sbp_size(),
            Sbp::MsgAlmanacGps(msg) => msg.sbp_size(),
            Sbp::MsgAlmanacGlo(msg) => msg.sbp_size(),
            Sbp::MsgGloBiases(msg) => msg.sbp_size(),
            Sbp::MsgEphemerisDepD(msg) => msg.sbp_size(),
            Sbp::MsgEphemerisGpsDepE(msg) => msg.sbp_size(),
            Sbp::MsgEphemerisSbasDepA(msg) => msg.sbp_size(),
            Sbp::MsgEphemerisGloDepA(msg) => msg.sbp_size(),
            Sbp::MsgEphemerisSbasDepB(msg) => msg.sbp_size(),
            Sbp::MsgEphemerisGloDepB(msg) => msg.sbp_size(),
            Sbp::MsgEphemerisGpsDepF(msg) => msg.sbp_size(),
            Sbp::MsgEphemerisGloDepC(msg) => msg.sbp_size(),
            Sbp::MsgEphemerisGloDepD(msg) => msg.sbp_size(),
            Sbp::MsgEphemerisBds(msg) => msg.sbp_size(),
            Sbp::MsgEphemerisGps(msg) => msg.sbp_size(),
            Sbp::MsgEphemerisGlo(msg) => msg.sbp_size(),
            Sbp::MsgEphemerisSbas(msg) => msg.sbp_size(),
            Sbp::MsgEphemerisGal(msg) => msg.sbp_size(),
            Sbp::MsgEphemerisQzss(msg) => msg.sbp_size(),
            Sbp::MsgIono(msg) => msg.sbp_size(),
            Sbp::MsgSvConfigurationGpsDep(msg) => msg.sbp_size(),
            Sbp::MsgGroupDelayDepA(msg) => msg.sbp_size(),
            Sbp::MsgGroupDelayDepB(msg) => msg.sbp_size(),
            Sbp::MsgGroupDelay(msg) => msg.sbp_size(),
            Sbp::MsgEphemerisGalDepA(msg) => msg.sbp_size(),
            Sbp::MsgGnssCapb(msg) => msg.sbp_size(),
            Sbp::MsgSvAzEl(msg) => msg.sbp_size(),
            Sbp::MsgSettingsWrite(msg) => msg.sbp_size(),
            Sbp::MsgSettingsSave(msg) => msg.sbp_size(),
            Sbp::MsgSettingsReadByIndexReq(msg) => msg.sbp_size(),
            Sbp::MsgFileioReadResp(msg) => msg.sbp_size(),
            Sbp::MsgSettingsReadReq(msg) => msg.sbp_size(),
            Sbp::MsgSettingsReadResp(msg) => msg.sbp_size(),
            Sbp::MsgSettingsReadByIndexDone(msg) => msg.sbp_size(),
            Sbp::MsgSettingsReadByIndexResp(msg) => msg.sbp_size(),
            Sbp::MsgFileioReadReq(msg) => msg.sbp_size(),
            Sbp::MsgFileioReadDirReq(msg) => msg.sbp_size(),
            Sbp::MsgFileioReadDirResp(msg) => msg.sbp_size(),
            Sbp::MsgFileioWriteResp(msg) => msg.sbp_size(),
            Sbp::MsgFileioRemove(msg) => msg.sbp_size(),
            Sbp::MsgFileioWriteReq(msg) => msg.sbp_size(),
            Sbp::MsgSettingsRegister(msg) => msg.sbp_size(),
            Sbp::MsgSettingsWriteResp(msg) => msg.sbp_size(),
            Sbp::MsgBootloaderHandshakeDepA(msg) => msg.sbp_size(),
            Sbp::MsgBootloaderJumpToApp(msg) => msg.sbp_size(),
            Sbp::MsgResetDep(msg) => msg.sbp_size(),
            Sbp::MsgBootloaderHandshakeReq(msg) => msg.sbp_size(),
            Sbp::MsgBootloaderHandshakeResp(msg) => msg.sbp_size(),
            Sbp::MsgDeviceMonitor(msg) => msg.sbp_size(),
            Sbp::MsgReset(msg) => msg.sbp_size(),
            Sbp::MsgCommandReq(msg) => msg.sbp_size(),
            Sbp::MsgCommandResp(msg) => msg.sbp_size(),
            Sbp::MsgNetworkStateReq(msg) => msg.sbp_size(),
            Sbp::MsgNetworkStateResp(msg) => msg.sbp_size(),
            Sbp::MsgCommandOutput(msg) => msg.sbp_size(),
            Sbp::MsgNetworkBandwidthUsage(msg) => msg.sbp_size(),
            Sbp::MsgCellModemStatus(msg) => msg.sbp_size(),
            Sbp::MsgFrontEndGain(msg) => msg.sbp_size(),
            Sbp::MsgCwResults(msg) => msg.sbp_size(),
            Sbp::MsgCwStart(msg) => msg.sbp_size(),
            Sbp::MsgNapDeviceDnaResp(msg) => msg.sbp_size(),
            Sbp::MsgNapDeviceDnaReq(msg) => msg.sbp_size(),
            Sbp::MsgFlashDone(msg) => msg.sbp_size(),
            Sbp::MsgFlashReadResp(msg) => msg.sbp_size(),
            Sbp::MsgFlashErase(msg) => msg.sbp_size(),
            Sbp::MsgStmFlashLockSector(msg) => msg.sbp_size(),
            Sbp::MsgStmFlashUnlockSector(msg) => msg.sbp_size(),
            Sbp::MsgStmUniqueIdResp(msg) => msg.sbp_size(),
            Sbp::MsgFlashProgram(msg) => msg.sbp_size(),
            Sbp::MsgFlashReadReq(msg) => msg.sbp_size(),
            Sbp::MsgStmUniqueIdReq(msg) => msg.sbp_size(),
            Sbp::MsgM25FlashWriteStatus(msg) => msg.sbp_size(),
            Sbp::MsgGpsTimeDepA(msg) => msg.sbp_size(),
            Sbp::MsgExtEvent(msg) => msg.sbp_size(),
            Sbp::MsgGpsTime(msg) => msg.sbp_size(),
            Sbp::MsgUtcTime(msg) => msg.sbp_size(),
            Sbp::MsgGpsTimeGnss(msg) => msg.sbp_size(),
            Sbp::MsgUtcTimeGnss(msg) => msg.sbp_size(),
            Sbp::MsgSettingsRegisterResp(msg) => msg.sbp_size(),
            Sbp::MsgPosEcefDepA(msg) => msg.sbp_size(),
            Sbp::MsgPosLlhDepA(msg) => msg.sbp_size(),
            Sbp::MsgBaselineEcefDepA(msg) => msg.sbp_size(),
            Sbp::MsgBaselineNedDepA(msg) => msg.sbp_size(),
            Sbp::MsgVelEcefDepA(msg) => msg.sbp_size(),
            Sbp::MsgVelNedDepA(msg) => msg.sbp_size(),
            Sbp::MsgDopsDepA(msg) => msg.sbp_size(),
            Sbp::MsgBaselineHeadingDepA(msg) => msg.sbp_size(),
            Sbp::MsgDops(msg) => msg.sbp_size(),
            Sbp::MsgPosEcef(msg) => msg.sbp_size(),
            Sbp::MsgPosLlh(msg) => msg.sbp_size(),
            Sbp::MsgBaselineEcef(msg) => msg.sbp_size(),
            Sbp::MsgBaselineNed(msg) => msg.sbp_size(),
            Sbp::MsgVelEcef(msg) => msg.sbp_size(),
            Sbp::MsgVelNed(msg) => msg.sbp_size(),
            Sbp::MsgBaselineHeading(msg) => msg.sbp_size(),
            Sbp::MsgAgeCorrections(msg) => msg.sbp_size(),
            Sbp::MsgPosLlhCov(msg) => msg.sbp_size(),
            Sbp::MsgVelNedCov(msg) => msg.sbp_size(),
            Sbp::MsgVelBody(msg) => msg.sbp_size(),
            Sbp::MsgPosEcefCov(msg) => msg.sbp_size(),
            Sbp::MsgVelEcefCov(msg) => msg.sbp_size(),
            Sbp::MsgProtectionLevelDepA(msg) => msg.sbp_size(),
            Sbp::MsgProtectionLevel(msg) => msg.sbp_size(),
            Sbp::MsgPosLlhAcc(msg) => msg.sbp_size(),
            Sbp::MsgOrientQuat(msg) => msg.sbp_size(),
            Sbp::MsgOrientEuler(msg) => msg.sbp_size(),
            Sbp::MsgAngularRate(msg) => msg.sbp_size(),
            Sbp::MsgPosEcefGnss(msg) => msg.sbp_size(),
            Sbp::MsgPosLlhGnss(msg) => msg.sbp_size(),
            Sbp::MsgVelEcefGnss(msg) => msg.sbp_size(),
            Sbp::MsgVelNedGnss(msg) => msg.sbp_size(),
            Sbp::MsgPosLlhCovGnss(msg) => msg.sbp_size(),
            Sbp::MsgVelNedCovGnss(msg) => msg.sbp_size(),
            Sbp::MsgPosEcefCovGnss(msg) => msg.sbp_size(),
            Sbp::MsgVelEcefCovGnss(msg) => msg.sbp_size(),
            Sbp::MsgNdbEvent(msg) => msg.sbp_size(),
            Sbp::MsgLog(msg) => msg.sbp_size(),
            Sbp::MsgFwd(msg) => msg.sbp_size(),
            Sbp::MsgSsrOrbitClockDepA(msg) => msg.sbp_size(),
            Sbp::MsgSsrOrbitClock(msg) => msg.sbp_size(),
            Sbp::MsgSsrCodeBiases(msg) => msg.sbp_size(),
            Sbp::MsgSsrPhaseBiases(msg) => msg.sbp_size(),
            Sbp::MsgSsrStecCorrectionDepA(msg) => msg.sbp_size(),
            Sbp::MsgSsrGriddedCorrectionNoStdDepA(msg) => msg.sbp_size(),
            Sbp::MsgSsrGridDefinitionDepA(msg) => msg.sbp_size(),
            Sbp::MsgSsrTileDefinition(msg) => msg.sbp_size(),
            Sbp::MsgSsrGriddedCorrectionDepA(msg) => msg.sbp_size(),
            Sbp::MsgSsrStecCorrection(msg) => msg.sbp_size(),
            Sbp::MsgSsrGriddedCorrection(msg) => msg.sbp_size(),
            Sbp::MsgSsrSatelliteApc(msg) => msg.sbp_size(),
            Sbp::MsgOsr(msg) => msg.sbp_size(),
            Sbp::MsgUserData(msg) => msg.sbp_size(),
            Sbp::MsgImuRaw(msg) => msg.sbp_size(),
            Sbp::MsgImuAux(msg) => msg.sbp_size(),
            Sbp::MsgMagRaw(msg) => msg.sbp_size(),
            Sbp::MsgOdometry(msg) => msg.sbp_size(),
            Sbp::MsgWheeltick(msg) => msg.sbp_size(),
            Sbp::MsgFileioConfigReq(msg) => msg.sbp_size(),
            Sbp::MsgFileioConfigResp(msg) => msg.sbp_size(),
            Sbp::MsgSbasRaw(msg) => msg.sbp_size(),
            Sbp::MsgLinuxCpuStateDepA(msg) => msg.sbp_size(),
            Sbp::MsgLinuxMemStateDepA(msg) => msg.sbp_size(),
            Sbp::MsgLinuxSysStateDepA(msg) => msg.sbp_size(),
            Sbp::MsgLinuxProcessSocketCounts(msg) => msg.sbp_size(),
            Sbp::MsgLinuxProcessSocketQueues(msg) => msg.sbp_size(),
            Sbp::MsgLinuxSocketUsage(msg) => msg.sbp_size(),
            Sbp::MsgLinuxProcessFdCount(msg) => msg.sbp_size(),
            Sbp::MsgLinuxProcessFdSummary(msg) => msg.sbp_size(),
            Sbp::MsgLinuxCpuState(msg) => msg.sbp_size(),
            Sbp::MsgLinuxMemState(msg) => msg.sbp_size(),
            Sbp::MsgLinuxSysState(msg) => msg.sbp_size(),
            Sbp::MsgStartup(msg) => msg.sbp_size(),
            Sbp::MsgDgnssStatus(msg) => msg.sbp_size(),
            Sbp::MsgInsStatus(msg) => msg.sbp_size(),
            Sbp::MsgCsacTelemetry(msg) => msg.sbp_size(),
            Sbp::MsgCsacTelemetryLabels(msg) => msg.sbp_size(),
            Sbp::MsgInsUpdates(msg) => msg.sbp_size(),
            Sbp::MsgGnssTimeOffset(msg) => msg.sbp_size(),
            Sbp::MsgPpsTime(msg) => msg.sbp_size(),
            Sbp::MsgGroupMeta(msg) => msg.sbp_size(),
            Sbp::MsgSolnMeta(msg) => msg.sbp_size(),
            Sbp::MsgSolnMetaDepA(msg) => msg.sbp_size(),
            Sbp::MsgStatusReport(msg) => msg.sbp_size(),
            Sbp::MsgHeartbeat(msg) => msg.sbp_size(),
            Sbp::Unknown(msg) => msg.sbp_size(),
        }
    }
}
impl From<MsgPrintDep> for Sbp {
    fn from(msg: MsgPrintDep) -> Self {
        Sbp::MsgPrintDep(msg)
    }
}
impl From<MsgTrackingStateDetailedDep> for Sbp {
    fn from(msg: MsgTrackingStateDetailedDep) -> Self {
        Sbp::MsgTrackingStateDetailedDep(msg)
    }
}
impl From<MsgTrackingStateDepB> for Sbp {
    fn from(msg: MsgTrackingStateDepB) -> Self {
        Sbp::MsgTrackingStateDepB(msg)
    }
}
impl From<MsgAcqResultDepB> for Sbp {
    fn from(msg: MsgAcqResultDepB) -> Self {
        Sbp::MsgAcqResultDepB(msg)
    }
}
impl From<MsgAcqResultDepA> for Sbp {
    fn from(msg: MsgAcqResultDepA) -> Self {
        Sbp::MsgAcqResultDepA(msg)
    }
}
impl From<MsgTrackingStateDepA> for Sbp {
    fn from(msg: MsgTrackingStateDepA) -> Self {
        Sbp::MsgTrackingStateDepA(msg)
    }
}
impl From<MsgThreadState> for Sbp {
    fn from(msg: MsgThreadState) -> Self {
        Sbp::MsgThreadState(msg)
    }
}
impl From<MsgUartStateDepa> for Sbp {
    fn from(msg: MsgUartStateDepa) -> Self {
        Sbp::MsgUartStateDepa(msg)
    }
}
impl From<MsgIarState> for Sbp {
    fn from(msg: MsgIarState) -> Self {
        Sbp::MsgIarState(msg)
    }
}
impl From<MsgEphemerisDepA> for Sbp {
    fn from(msg: MsgEphemerisDepA) -> Self {
        Sbp::MsgEphemerisDepA(msg)
    }
}
impl From<MsgMaskSatelliteDep> for Sbp {
    fn from(msg: MsgMaskSatelliteDep) -> Self {
        Sbp::MsgMaskSatelliteDep(msg)
    }
}
impl From<MsgTrackingIqDepA> for Sbp {
    fn from(msg: MsgTrackingIqDepA) -> Self {
        Sbp::MsgTrackingIqDepA(msg)
    }
}
impl From<MsgUartState> for Sbp {
    fn from(msg: MsgUartState) -> Self {
        Sbp::MsgUartState(msg)
    }
}
impl From<MsgAcqSvProfileDep> for Sbp {
    fn from(msg: MsgAcqSvProfileDep) -> Self {
        Sbp::MsgAcqSvProfileDep(msg)
    }
}
impl From<MsgAcqResultDepC> for Sbp {
    fn from(msg: MsgAcqResultDepC) -> Self {
        Sbp::MsgAcqResultDepC(msg)
    }
}
impl From<MsgTrackingStateDetailedDepA> for Sbp {
    fn from(msg: MsgTrackingStateDetailedDepA) -> Self {
        Sbp::MsgTrackingStateDetailedDepA(msg)
    }
}
impl From<MsgResetFilters> for Sbp {
    fn from(msg: MsgResetFilters) -> Self {
        Sbp::MsgResetFilters(msg)
    }
}
impl From<MsgInitBaseDep> for Sbp {
    fn from(msg: MsgInitBaseDep) -> Self {
        Sbp::MsgInitBaseDep(msg)
    }
}
impl From<MsgMaskSatellite> for Sbp {
    fn from(msg: MsgMaskSatellite) -> Self {
        Sbp::MsgMaskSatellite(msg)
    }
}
impl From<MsgTrackingIqDepB> for Sbp {
    fn from(msg: MsgTrackingIqDepB) -> Self {
        Sbp::MsgTrackingIqDepB(msg)
    }
}
impl From<MsgTrackingIq> for Sbp {
    fn from(msg: MsgTrackingIq) -> Self {
        Sbp::MsgTrackingIq(msg)
    }
}
impl From<MsgAcqSvProfile> for Sbp {
    fn from(msg: MsgAcqSvProfile) -> Self {
        Sbp::MsgAcqSvProfile(msg)
    }
}
impl From<MsgAcqResult> for Sbp {
    fn from(msg: MsgAcqResult) -> Self {
        Sbp::MsgAcqResult(msg)
    }
}
impl From<MsgTrackingState> for Sbp {
    fn from(msg: MsgTrackingState) -> Self {
        Sbp::MsgTrackingState(msg)
    }
}
impl From<MsgObsDepB> for Sbp {
    fn from(msg: MsgObsDepB) -> Self {
        Sbp::MsgObsDepB(msg)
    }
}
impl From<MsgBasePosLlh> for Sbp {
    fn from(msg: MsgBasePosLlh) -> Self {
        Sbp::MsgBasePosLlh(msg)
    }
}
impl From<MsgObsDepA> for Sbp {
    fn from(msg: MsgObsDepA) -> Self {
        Sbp::MsgObsDepA(msg)
    }
}
impl From<MsgEphemerisDepB> for Sbp {
    fn from(msg: MsgEphemerisDepB) -> Self {
        Sbp::MsgEphemerisDepB(msg)
    }
}
impl From<MsgEphemerisDepC> for Sbp {
    fn from(msg: MsgEphemerisDepC) -> Self {
        Sbp::MsgEphemerisDepC(msg)
    }
}
impl From<MsgBasePosEcef> for Sbp {
    fn from(msg: MsgBasePosEcef) -> Self {
        Sbp::MsgBasePosEcef(msg)
    }
}
impl From<MsgObsDepC> for Sbp {
    fn from(msg: MsgObsDepC) -> Self {
        Sbp::MsgObsDepC(msg)
    }
}
impl From<MsgObs> for Sbp {
    fn from(msg: MsgObs) -> Self {
        Sbp::MsgObs(msg)
    }
}
impl From<MsgSpecanDep> for Sbp {
    fn from(msg: MsgSpecanDep) -> Self {
        Sbp::MsgSpecanDep(msg)
    }
}
impl From<MsgSpecan> for Sbp {
    fn from(msg: MsgSpecan) -> Self {
        Sbp::MsgSpecan(msg)
    }
}
impl From<MsgMeasurementState> for Sbp {
    fn from(msg: MsgMeasurementState) -> Self {
        Sbp::MsgMeasurementState(msg)
    }
}
impl From<MsgSetTime> for Sbp {
    fn from(msg: MsgSetTime) -> Self {
        Sbp::MsgSetTime(msg)
    }
}
impl From<MsgAlmanac> for Sbp {
    fn from(msg: MsgAlmanac) -> Self {
        Sbp::MsgAlmanac(msg)
    }
}
impl From<MsgAlmanacGpsDep> for Sbp {
    fn from(msg: MsgAlmanacGpsDep) -> Self {
        Sbp::MsgAlmanacGpsDep(msg)
    }
}
impl From<MsgAlmanacGloDep> for Sbp {
    fn from(msg: MsgAlmanacGloDep) -> Self {
        Sbp::MsgAlmanacGloDep(msg)
    }
}
impl From<MsgAlmanacGps> for Sbp {
    fn from(msg: MsgAlmanacGps) -> Self {
        Sbp::MsgAlmanacGps(msg)
    }
}
impl From<MsgAlmanacGlo> for Sbp {
    fn from(msg: MsgAlmanacGlo) -> Self {
        Sbp::MsgAlmanacGlo(msg)
    }
}
impl From<MsgGloBiases> for Sbp {
    fn from(msg: MsgGloBiases) -> Self {
        Sbp::MsgGloBiases(msg)
    }
}
impl From<MsgEphemerisDepD> for Sbp {
    fn from(msg: MsgEphemerisDepD) -> Self {
        Sbp::MsgEphemerisDepD(msg)
    }
}
impl From<MsgEphemerisGpsDepE> for Sbp {
    fn from(msg: MsgEphemerisGpsDepE) -> Self {
        Sbp::MsgEphemerisGpsDepE(msg)
    }
}
impl From<MsgEphemerisSbasDepA> for Sbp {
    fn from(msg: MsgEphemerisSbasDepA) -> Self {
        Sbp::MsgEphemerisSbasDepA(msg)
    }
}
impl From<MsgEphemerisGloDepA> for Sbp {
    fn from(msg: MsgEphemerisGloDepA) -> Self {
        Sbp::MsgEphemerisGloDepA(msg)
    }
}
impl From<MsgEphemerisSbasDepB> for Sbp {
    fn from(msg: MsgEphemerisSbasDepB) -> Self {
        Sbp::MsgEphemerisSbasDepB(msg)
    }
}
impl From<MsgEphemerisGloDepB> for Sbp {
    fn from(msg: MsgEphemerisGloDepB) -> Self {
        Sbp::MsgEphemerisGloDepB(msg)
    }
}
impl From<MsgEphemerisGpsDepF> for Sbp {
    fn from(msg: MsgEphemerisGpsDepF) -> Self {
        Sbp::MsgEphemerisGpsDepF(msg)
    }
}
impl From<MsgEphemerisGloDepC> for Sbp {
    fn from(msg: MsgEphemerisGloDepC) -> Self {
        Sbp::MsgEphemerisGloDepC(msg)
    }
}
impl From<MsgEphemerisGloDepD> for Sbp {
    fn from(msg: MsgEphemerisGloDepD) -> Self {
        Sbp::MsgEphemerisGloDepD(msg)
    }
}
impl From<MsgEphemerisBds> for Sbp {
    fn from(msg: MsgEphemerisBds) -> Self {
        Sbp::MsgEphemerisBds(msg)
    }
}
impl From<MsgEphemerisGps> for Sbp {
    fn from(msg: MsgEphemerisGps) -> Self {
        Sbp::MsgEphemerisGps(msg)
    }
}
impl From<MsgEphemerisGlo> for Sbp {
    fn from(msg: MsgEphemerisGlo) -> Self {
        Sbp::MsgEphemerisGlo(msg)
    }
}
impl From<MsgEphemerisSbas> for Sbp {
    fn from(msg: MsgEphemerisSbas) -> Self {
        Sbp::MsgEphemerisSbas(msg)
    }
}
impl From<MsgEphemerisGal> for Sbp {
    fn from(msg: MsgEphemerisGal) -> Self {
        Sbp::MsgEphemerisGal(msg)
    }
}
impl From<MsgEphemerisQzss> for Sbp {
    fn from(msg: MsgEphemerisQzss) -> Self {
        Sbp::MsgEphemerisQzss(msg)
    }
}
impl From<MsgIono> for Sbp {
    fn from(msg: MsgIono) -> Self {
        Sbp::MsgIono(msg)
    }
}
impl From<MsgSvConfigurationGpsDep> for Sbp {
    fn from(msg: MsgSvConfigurationGpsDep) -> Self {
        Sbp::MsgSvConfigurationGpsDep(msg)
    }
}
impl From<MsgGroupDelayDepA> for Sbp {
    fn from(msg: MsgGroupDelayDepA) -> Self {
        Sbp::MsgGroupDelayDepA(msg)
    }
}
impl From<MsgGroupDelayDepB> for Sbp {
    fn from(msg: MsgGroupDelayDepB) -> Self {
        Sbp::MsgGroupDelayDepB(msg)
    }
}
impl From<MsgGroupDelay> for Sbp {
    fn from(msg: MsgGroupDelay) -> Self {
        Sbp::MsgGroupDelay(msg)
    }
}
impl From<MsgEphemerisGalDepA> for Sbp {
    fn from(msg: MsgEphemerisGalDepA) -> Self {
        Sbp::MsgEphemerisGalDepA(msg)
    }
}
impl From<MsgGnssCapb> for Sbp {
    fn from(msg: MsgGnssCapb) -> Self {
        Sbp::MsgGnssCapb(msg)
    }
}
impl From<MsgSvAzEl> for Sbp {
    fn from(msg: MsgSvAzEl) -> Self {
        Sbp::MsgSvAzEl(msg)
    }
}
impl From<MsgSettingsWrite> for Sbp {
    fn from(msg: MsgSettingsWrite) -> Self {
        Sbp::MsgSettingsWrite(msg)
    }
}
impl From<MsgSettingsSave> for Sbp {
    fn from(msg: MsgSettingsSave) -> Self {
        Sbp::MsgSettingsSave(msg)
    }
}
impl From<MsgSettingsReadByIndexReq> for Sbp {
    fn from(msg: MsgSettingsReadByIndexReq) -> Self {
        Sbp::MsgSettingsReadByIndexReq(msg)
    }
}
impl From<MsgFileioReadResp> for Sbp {
    fn from(msg: MsgFileioReadResp) -> Self {
        Sbp::MsgFileioReadResp(msg)
    }
}
impl From<MsgSettingsReadReq> for Sbp {
    fn from(msg: MsgSettingsReadReq) -> Self {
        Sbp::MsgSettingsReadReq(msg)
    }
}
impl From<MsgSettingsReadResp> for Sbp {
    fn from(msg: MsgSettingsReadResp) -> Self {
        Sbp::MsgSettingsReadResp(msg)
    }
}
impl From<MsgSettingsReadByIndexDone> for Sbp {
    fn from(msg: MsgSettingsReadByIndexDone) -> Self {
        Sbp::MsgSettingsReadByIndexDone(msg)
    }
}
impl From<MsgSettingsReadByIndexResp> for Sbp {
    fn from(msg: MsgSettingsReadByIndexResp) -> Self {
        Sbp::MsgSettingsReadByIndexResp(msg)
    }
}
impl From<MsgFileioReadReq> for Sbp {
    fn from(msg: MsgFileioReadReq) -> Self {
        Sbp::MsgFileioReadReq(msg)
    }
}
impl From<MsgFileioReadDirReq> for Sbp {
    fn from(msg: MsgFileioReadDirReq) -> Self {
        Sbp::MsgFileioReadDirReq(msg)
    }
}
impl From<MsgFileioReadDirResp> for Sbp {
    fn from(msg: MsgFileioReadDirResp) -> Self {
        Sbp::MsgFileioReadDirResp(msg)
    }
}
impl From<MsgFileioWriteResp> for Sbp {
    fn from(msg: MsgFileioWriteResp) -> Self {
        Sbp::MsgFileioWriteResp(msg)
    }
}
impl From<MsgFileioRemove> for Sbp {
    fn from(msg: MsgFileioRemove) -> Self {
        Sbp::MsgFileioRemove(msg)
    }
}
impl From<MsgFileioWriteReq> for Sbp {
    fn from(msg: MsgFileioWriteReq) -> Self {
        Sbp::MsgFileioWriteReq(msg)
    }
}
impl From<MsgSettingsRegister> for Sbp {
    fn from(msg: MsgSettingsRegister) -> Self {
        Sbp::MsgSettingsRegister(msg)
    }
}
impl From<MsgSettingsWriteResp> for Sbp {
    fn from(msg: MsgSettingsWriteResp) -> Self {
        Sbp::MsgSettingsWriteResp(msg)
    }
}
impl From<MsgBootloaderHandshakeDepA> for Sbp {
    fn from(msg: MsgBootloaderHandshakeDepA) -> Self {
        Sbp::MsgBootloaderHandshakeDepA(msg)
    }
}
impl From<MsgBootloaderJumpToApp> for Sbp {
    fn from(msg: MsgBootloaderJumpToApp) -> Self {
        Sbp::MsgBootloaderJumpToApp(msg)
    }
}
impl From<MsgResetDep> for Sbp {
    fn from(msg: MsgResetDep) -> Self {
        Sbp::MsgResetDep(msg)
    }
}
impl From<MsgBootloaderHandshakeReq> for Sbp {
    fn from(msg: MsgBootloaderHandshakeReq) -> Self {
        Sbp::MsgBootloaderHandshakeReq(msg)
    }
}
impl From<MsgBootloaderHandshakeResp> for Sbp {
    fn from(msg: MsgBootloaderHandshakeResp) -> Self {
        Sbp::MsgBootloaderHandshakeResp(msg)
    }
}
impl From<MsgDeviceMonitor> for Sbp {
    fn from(msg: MsgDeviceMonitor) -> Self {
        Sbp::MsgDeviceMonitor(msg)
    }
}
impl From<MsgReset> for Sbp {
    fn from(msg: MsgReset) -> Self {
        Sbp::MsgReset(msg)
    }
}
impl From<MsgCommandReq> for Sbp {
    fn from(msg: MsgCommandReq) -> Self {
        Sbp::MsgCommandReq(msg)
    }
}
impl From<MsgCommandResp> for Sbp {
    fn from(msg: MsgCommandResp) -> Self {
        Sbp::MsgCommandResp(msg)
    }
}
impl From<MsgNetworkStateReq> for Sbp {
    fn from(msg: MsgNetworkStateReq) -> Self {
        Sbp::MsgNetworkStateReq(msg)
    }
}
impl From<MsgNetworkStateResp> for Sbp {
    fn from(msg: MsgNetworkStateResp) -> Self {
        Sbp::MsgNetworkStateResp(msg)
    }
}
impl From<MsgCommandOutput> for Sbp {
    fn from(msg: MsgCommandOutput) -> Self {
        Sbp::MsgCommandOutput(msg)
    }
}
impl From<MsgNetworkBandwidthUsage> for Sbp {
    fn from(msg: MsgNetworkBandwidthUsage) -> Self {
        Sbp::MsgNetworkBandwidthUsage(msg)
    }
}
impl From<MsgCellModemStatus> for Sbp {
    fn from(msg: MsgCellModemStatus) -> Self {
        Sbp::MsgCellModemStatus(msg)
    }
}
impl From<MsgFrontEndGain> for Sbp {
    fn from(msg: MsgFrontEndGain) -> Self {
        Sbp::MsgFrontEndGain(msg)
    }
}
impl From<MsgCwResults> for Sbp {
    fn from(msg: MsgCwResults) -> Self {
        Sbp::MsgCwResults(msg)
    }
}
impl From<MsgCwStart> for Sbp {
    fn from(msg: MsgCwStart) -> Self {
        Sbp::MsgCwStart(msg)
    }
}
impl From<MsgNapDeviceDnaResp> for Sbp {
    fn from(msg: MsgNapDeviceDnaResp) -> Self {
        Sbp::MsgNapDeviceDnaResp(msg)
    }
}
impl From<MsgNapDeviceDnaReq> for Sbp {
    fn from(msg: MsgNapDeviceDnaReq) -> Self {
        Sbp::MsgNapDeviceDnaReq(msg)
    }
}
impl From<MsgFlashDone> for Sbp {
    fn from(msg: MsgFlashDone) -> Self {
        Sbp::MsgFlashDone(msg)
    }
}
impl From<MsgFlashReadResp> for Sbp {
    fn from(msg: MsgFlashReadResp) -> Self {
        Sbp::MsgFlashReadResp(msg)
    }
}
impl From<MsgFlashErase> for Sbp {
    fn from(msg: MsgFlashErase) -> Self {
        Sbp::MsgFlashErase(msg)
    }
}
impl From<MsgStmFlashLockSector> for Sbp {
    fn from(msg: MsgStmFlashLockSector) -> Self {
        Sbp::MsgStmFlashLockSector(msg)
    }
}
impl From<MsgStmFlashUnlockSector> for Sbp {
    fn from(msg: MsgStmFlashUnlockSector) -> Self {
        Sbp::MsgStmFlashUnlockSector(msg)
    }
}
impl From<MsgStmUniqueIdResp> for Sbp {
    fn from(msg: MsgStmUniqueIdResp) -> Self {
        Sbp::MsgStmUniqueIdResp(msg)
    }
}
impl From<MsgFlashProgram> for Sbp {
    fn from(msg: MsgFlashProgram) -> Self {
        Sbp::MsgFlashProgram(msg)
    }
}
impl From<MsgFlashReadReq> for Sbp {
    fn from(msg: MsgFlashReadReq) -> Self {
        Sbp::MsgFlashReadReq(msg)
    }
}
impl From<MsgStmUniqueIdReq> for Sbp {
    fn from(msg: MsgStmUniqueIdReq) -> Self {
        Sbp::MsgStmUniqueIdReq(msg)
    }
}
impl From<MsgM25FlashWriteStatus> for Sbp {
    fn from(msg: MsgM25FlashWriteStatus) -> Self {
        Sbp::MsgM25FlashWriteStatus(msg)
    }
}
impl From<MsgGpsTimeDepA> for Sbp {
    fn from(msg: MsgGpsTimeDepA) -> Self {
        Sbp::MsgGpsTimeDepA(msg)
    }
}
impl From<MsgExtEvent> for Sbp {
    fn from(msg: MsgExtEvent) -> Self {
        Sbp::MsgExtEvent(msg)
    }
}
impl From<MsgGpsTime> for Sbp {
    fn from(msg: MsgGpsTime) -> Self {
        Sbp::MsgGpsTime(msg)
    }
}
impl From<MsgUtcTime> for Sbp {
    fn from(msg: MsgUtcTime) -> Self {
        Sbp::MsgUtcTime(msg)
    }
}
impl From<MsgGpsTimeGnss> for Sbp {
    fn from(msg: MsgGpsTimeGnss) -> Self {
        Sbp::MsgGpsTimeGnss(msg)
    }
}
impl From<MsgUtcTimeGnss> for Sbp {
    fn from(msg: MsgUtcTimeGnss) -> Self {
        Sbp::MsgUtcTimeGnss(msg)
    }
}
impl From<MsgSettingsRegisterResp> for Sbp {
    fn from(msg: MsgSettingsRegisterResp) -> Self {
        Sbp::MsgSettingsRegisterResp(msg)
    }
}
impl From<MsgPosEcefDepA> for Sbp {
    fn from(msg: MsgPosEcefDepA) -> Self {
        Sbp::MsgPosEcefDepA(msg)
    }
}
impl From<MsgPosLlhDepA> for Sbp {
    fn from(msg: MsgPosLlhDepA) -> Self {
        Sbp::MsgPosLlhDepA(msg)
    }
}
impl From<MsgBaselineEcefDepA> for Sbp {
    fn from(msg: MsgBaselineEcefDepA) -> Self {
        Sbp::MsgBaselineEcefDepA(msg)
    }
}
impl From<MsgBaselineNedDepA> for Sbp {
    fn from(msg: MsgBaselineNedDepA) -> Self {
        Sbp::MsgBaselineNedDepA(msg)
    }
}
impl From<MsgVelEcefDepA> for Sbp {
    fn from(msg: MsgVelEcefDepA) -> Self {
        Sbp::MsgVelEcefDepA(msg)
    }
}
impl From<MsgVelNedDepA> for Sbp {
    fn from(msg: MsgVelNedDepA) -> Self {
        Sbp::MsgVelNedDepA(msg)
    }
}
impl From<MsgDopsDepA> for Sbp {
    fn from(msg: MsgDopsDepA) -> Self {
        Sbp::MsgDopsDepA(msg)
    }
}
impl From<MsgBaselineHeadingDepA> for Sbp {
    fn from(msg: MsgBaselineHeadingDepA) -> Self {
        Sbp::MsgBaselineHeadingDepA(msg)
    }
}
impl From<MsgDops> for Sbp {
    fn from(msg: MsgDops) -> Self {
        Sbp::MsgDops(msg)
    }
}
impl From<MsgPosEcef> for Sbp {
    fn from(msg: MsgPosEcef) -> Self {
        Sbp::MsgPosEcef(msg)
    }
}
impl From<MsgPosLlh> for Sbp {
    fn from(msg: MsgPosLlh) -> Self {
        Sbp::MsgPosLlh(msg)
    }
}
impl From<MsgBaselineEcef> for Sbp {
    fn from(msg: MsgBaselineEcef) -> Self {
        Sbp::MsgBaselineEcef(msg)
    }
}
impl From<MsgBaselineNed> for Sbp {
    fn from(msg: MsgBaselineNed) -> Self {
        Sbp::MsgBaselineNed(msg)
    }
}
impl From<MsgVelEcef> for Sbp {
    fn from(msg: MsgVelEcef) -> Self {
        Sbp::MsgVelEcef(msg)
    }
}
impl From<MsgVelNed> for Sbp {
    fn from(msg: MsgVelNed) -> Self {
        Sbp::MsgVelNed(msg)
    }
}
impl From<MsgBaselineHeading> for Sbp {
    fn from(msg: MsgBaselineHeading) -> Self {
        Sbp::MsgBaselineHeading(msg)
    }
}
impl From<MsgAgeCorrections> for Sbp {
    fn from(msg: MsgAgeCorrections) -> Self {
        Sbp::MsgAgeCorrections(msg)
    }
}
impl From<MsgPosLlhCov> for Sbp {
    fn from(msg: MsgPosLlhCov) -> Self {
        Sbp::MsgPosLlhCov(msg)
    }
}
impl From<MsgVelNedCov> for Sbp {
    fn from(msg: MsgVelNedCov) -> Self {
        Sbp::MsgVelNedCov(msg)
    }
}
impl From<MsgVelBody> for Sbp {
    fn from(msg: MsgVelBody) -> Self {
        Sbp::MsgVelBody(msg)
    }
}
impl From<MsgPosEcefCov> for Sbp {
    fn from(msg: MsgPosEcefCov) -> Self {
        Sbp::MsgPosEcefCov(msg)
    }
}
impl From<MsgVelEcefCov> for Sbp {
    fn from(msg: MsgVelEcefCov) -> Self {
        Sbp::MsgVelEcefCov(msg)
    }
}
impl From<MsgProtectionLevelDepA> for Sbp {
    fn from(msg: MsgProtectionLevelDepA) -> Self {
        Sbp::MsgProtectionLevelDepA(msg)
    }
}
impl From<MsgProtectionLevel> for Sbp {
    fn from(msg: MsgProtectionLevel) -> Self {
        Sbp::MsgProtectionLevel(msg)
    }
}
impl From<MsgPosLlhAcc> for Sbp {
    fn from(msg: MsgPosLlhAcc) -> Self {
        Sbp::MsgPosLlhAcc(msg)
    }
}
impl From<MsgOrientQuat> for Sbp {
    fn from(msg: MsgOrientQuat) -> Self {
        Sbp::MsgOrientQuat(msg)
    }
}
impl From<MsgOrientEuler> for Sbp {
    fn from(msg: MsgOrientEuler) -> Self {
        Sbp::MsgOrientEuler(msg)
    }
}
impl From<MsgAngularRate> for Sbp {
    fn from(msg: MsgAngularRate) -> Self {
        Sbp::MsgAngularRate(msg)
    }
}
impl From<MsgPosEcefGnss> for Sbp {
    fn from(msg: MsgPosEcefGnss) -> Self {
        Sbp::MsgPosEcefGnss(msg)
    }
}
impl From<MsgPosLlhGnss> for Sbp {
    fn from(msg: MsgPosLlhGnss) -> Self {
        Sbp::MsgPosLlhGnss(msg)
    }
}
impl From<MsgVelEcefGnss> for Sbp {
    fn from(msg: MsgVelEcefGnss) -> Self {
        Sbp::MsgVelEcefGnss(msg)
    }
}
impl From<MsgVelNedGnss> for Sbp {
    fn from(msg: MsgVelNedGnss) -> Self {
        Sbp::MsgVelNedGnss(msg)
    }
}
impl From<MsgPosLlhCovGnss> for Sbp {
    fn from(msg: MsgPosLlhCovGnss) -> Self {
        Sbp::MsgPosLlhCovGnss(msg)
    }
}
impl From<MsgVelNedCovGnss> for Sbp {
    fn from(msg: MsgVelNedCovGnss) -> Self {
        Sbp::MsgVelNedCovGnss(msg)
    }
}
impl From<MsgPosEcefCovGnss> for Sbp {
    fn from(msg: MsgPosEcefCovGnss) -> Self {
        Sbp::MsgPosEcefCovGnss(msg)
    }
}
impl From<MsgVelEcefCovGnss> for Sbp {
    fn from(msg: MsgVelEcefCovGnss) -> Self {
        Sbp::MsgVelEcefCovGnss(msg)
    }
}
impl From<MsgNdbEvent> for Sbp {
    fn from(msg: MsgNdbEvent) -> Self {
        Sbp::MsgNdbEvent(msg)
    }
}
impl From<MsgLog> for Sbp {
    fn from(msg: MsgLog) -> Self {
        Sbp::MsgLog(msg)
    }
}
impl From<MsgFwd> for Sbp {
    fn from(msg: MsgFwd) -> Self {
        Sbp::MsgFwd(msg)
    }
}
impl From<MsgSsrOrbitClockDepA> for Sbp {
    fn from(msg: MsgSsrOrbitClockDepA) -> Self {
        Sbp::MsgSsrOrbitClockDepA(msg)
    }
}
impl From<MsgSsrOrbitClock> for Sbp {
    fn from(msg: MsgSsrOrbitClock) -> Self {
        Sbp::MsgSsrOrbitClock(msg)
    }
}
impl From<MsgSsrCodeBiases> for Sbp {
    fn from(msg: MsgSsrCodeBiases) -> Self {
        Sbp::MsgSsrCodeBiases(msg)
    }
}
impl From<MsgSsrPhaseBiases> for Sbp {
    fn from(msg: MsgSsrPhaseBiases) -> Self {
        Sbp::MsgSsrPhaseBiases(msg)
    }
}
impl From<MsgSsrStecCorrectionDepA> for Sbp {
    fn from(msg: MsgSsrStecCorrectionDepA) -> Self {
        Sbp::MsgSsrStecCorrectionDepA(msg)
    }
}
impl From<MsgSsrGriddedCorrectionNoStdDepA> for Sbp {
    fn from(msg: MsgSsrGriddedCorrectionNoStdDepA) -> Self {
        Sbp::MsgSsrGriddedCorrectionNoStdDepA(msg)
    }
}
impl From<MsgSsrGridDefinitionDepA> for Sbp {
    fn from(msg: MsgSsrGridDefinitionDepA) -> Self {
        Sbp::MsgSsrGridDefinitionDepA(msg)
    }
}
impl From<MsgSsrTileDefinition> for Sbp {
    fn from(msg: MsgSsrTileDefinition) -> Self {
        Sbp::MsgSsrTileDefinition(msg)
    }
}
impl From<MsgSsrGriddedCorrectionDepA> for Sbp {
    fn from(msg: MsgSsrGriddedCorrectionDepA) -> Self {
        Sbp::MsgSsrGriddedCorrectionDepA(msg)
    }
}
impl From<MsgSsrStecCorrection> for Sbp {
    fn from(msg: MsgSsrStecCorrection) -> Self {
        Sbp::MsgSsrStecCorrection(msg)
    }
}
impl From<MsgSsrGriddedCorrection> for Sbp {
    fn from(msg: MsgSsrGriddedCorrection) -> Self {
        Sbp::MsgSsrGriddedCorrection(msg)
    }
}
impl From<MsgSsrSatelliteApc> for Sbp {
    fn from(msg: MsgSsrSatelliteApc) -> Self {
        Sbp::MsgSsrSatelliteApc(msg)
    }
}
impl From<MsgOsr> for Sbp {
    fn from(msg: MsgOsr) -> Self {
        Sbp::MsgOsr(msg)
    }
}
impl From<MsgUserData> for Sbp {
    fn from(msg: MsgUserData) -> Self {
        Sbp::MsgUserData(msg)
    }
}
impl From<MsgImuRaw> for Sbp {
    fn from(msg: MsgImuRaw) -> Self {
        Sbp::MsgImuRaw(msg)
    }
}
impl From<MsgImuAux> for Sbp {
    fn from(msg: MsgImuAux) -> Self {
        Sbp::MsgImuAux(msg)
    }
}
impl From<MsgMagRaw> for Sbp {
    fn from(msg: MsgMagRaw) -> Self {
        Sbp::MsgMagRaw(msg)
    }
}
impl From<MsgOdometry> for Sbp {
    fn from(msg: MsgOdometry) -> Self {
        Sbp::MsgOdometry(msg)
    }
}
impl From<MsgWheeltick> for Sbp {
    fn from(msg: MsgWheeltick) -> Self {
        Sbp::MsgWheeltick(msg)
    }
}
impl From<MsgFileioConfigReq> for Sbp {
    fn from(msg: MsgFileioConfigReq) -> Self {
        Sbp::MsgFileioConfigReq(msg)
    }
}
impl From<MsgFileioConfigResp> for Sbp {
    fn from(msg: MsgFileioConfigResp) -> Self {
        Sbp::MsgFileioConfigResp(msg)
    }
}
impl From<MsgSbasRaw> for Sbp {
    fn from(msg: MsgSbasRaw) -> Self {
        Sbp::MsgSbasRaw(msg)
    }
}
impl From<MsgLinuxCpuStateDepA> for Sbp {
    fn from(msg: MsgLinuxCpuStateDepA) -> Self {
        Sbp::MsgLinuxCpuStateDepA(msg)
    }
}
impl From<MsgLinuxMemStateDepA> for Sbp {
    fn from(msg: MsgLinuxMemStateDepA) -> Self {
        Sbp::MsgLinuxMemStateDepA(msg)
    }
}
impl From<MsgLinuxSysStateDepA> for Sbp {
    fn from(msg: MsgLinuxSysStateDepA) -> Self {
        Sbp::MsgLinuxSysStateDepA(msg)
    }
}
impl From<MsgLinuxProcessSocketCounts> for Sbp {
    fn from(msg: MsgLinuxProcessSocketCounts) -> Self {
        Sbp::MsgLinuxProcessSocketCounts(msg)
    }
}
impl From<MsgLinuxProcessSocketQueues> for Sbp {
    fn from(msg: MsgLinuxProcessSocketQueues) -> Self {
        Sbp::MsgLinuxProcessSocketQueues(msg)
    }
}
impl From<MsgLinuxSocketUsage> for Sbp {
    fn from(msg: MsgLinuxSocketUsage) -> Self {
        Sbp::MsgLinuxSocketUsage(msg)
    }
}
impl From<MsgLinuxProcessFdCount> for Sbp {
    fn from(msg: MsgLinuxProcessFdCount) -> Self {
        Sbp::MsgLinuxProcessFdCount(msg)
    }
}
impl From<MsgLinuxProcessFdSummary> for Sbp {
    fn from(msg: MsgLinuxProcessFdSummary) -> Self {
        Sbp::MsgLinuxProcessFdSummary(msg)
    }
}
impl From<MsgLinuxCpuState> for Sbp {
    fn from(msg: MsgLinuxCpuState) -> Self {
        Sbp::MsgLinuxCpuState(msg)
    }
}
impl From<MsgLinuxMemState> for Sbp {
    fn from(msg: MsgLinuxMemState) -> Self {
        Sbp::MsgLinuxMemState(msg)
    }
}
impl From<MsgLinuxSysState> for Sbp {
    fn from(msg: MsgLinuxSysState) -> Self {
        Sbp::MsgLinuxSysState(msg)
    }
}
impl From<MsgStartup> for Sbp {
    fn from(msg: MsgStartup) -> Self {
        Sbp::MsgStartup(msg)
    }
}
impl From<MsgDgnssStatus> for Sbp {
    fn from(msg: MsgDgnssStatus) -> Self {
        Sbp::MsgDgnssStatus(msg)
    }
}
impl From<MsgInsStatus> for Sbp {
    fn from(msg: MsgInsStatus) -> Self {
        Sbp::MsgInsStatus(msg)
    }
}
impl From<MsgCsacTelemetry> for Sbp {
    fn from(msg: MsgCsacTelemetry) -> Self {
        Sbp::MsgCsacTelemetry(msg)
    }
}
impl From<MsgCsacTelemetryLabels> for Sbp {
    fn from(msg: MsgCsacTelemetryLabels) -> Self {
        Sbp::MsgCsacTelemetryLabels(msg)
    }
}
impl From<MsgInsUpdates> for Sbp {
    fn from(msg: MsgInsUpdates) -> Self {
        Sbp::MsgInsUpdates(msg)
    }
}
impl From<MsgGnssTimeOffset> for Sbp {
    fn from(msg: MsgGnssTimeOffset) -> Self {
        Sbp::MsgGnssTimeOffset(msg)
    }
}
impl From<MsgPpsTime> for Sbp {
    fn from(msg: MsgPpsTime) -> Self {
        Sbp::MsgPpsTime(msg)
    }
}
impl From<MsgGroupMeta> for Sbp {
    fn from(msg: MsgGroupMeta) -> Self {
        Sbp::MsgGroupMeta(msg)
    }
}
impl From<MsgSolnMeta> for Sbp {
    fn from(msg: MsgSolnMeta) -> Self {
        Sbp::MsgSolnMeta(msg)
    }
}
impl From<MsgSolnMetaDepA> for Sbp {
    fn from(msg: MsgSolnMetaDepA) -> Self {
        Sbp::MsgSolnMetaDepA(msg)
    }
}
impl From<MsgStatusReport> for Sbp {
    fn from(msg: MsgStatusReport) -> Self {
        Sbp::MsgStatusReport(msg)
    }
}
impl From<MsgHeartbeat> for Sbp {
    fn from(msg: MsgHeartbeat) -> Self {
        Sbp::MsgHeartbeat(msg)
    }
}

impl From<Unknown> for Sbp {
    fn from(msg: Unknown) -> Self {
        Sbp::Unknown(msg)
    }
}
