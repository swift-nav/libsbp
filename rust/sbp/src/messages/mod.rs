// Copyright (C) 2015-2018 Swift Navigation Inc.
// Contact: Swift Navigation <dev@swiftnav.com>
//
// This source is subject to the license found in the file 'LICENSE' which must
// be be distributed together with this source. All other rights reserved.
//
// THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
// EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
// WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
pub mod acquisition;
pub mod logging;
pub mod gnss;
pub mod sbas;
pub mod settings;
pub mod mag;
pub mod tracking;
pub mod flash;
pub mod user;
pub mod piksi;
pub mod bootload;
pub mod observation;
pub mod ssr;
pub mod navigation;
pub mod linux;
pub mod orientation;
pub mod system;
pub mod ndb;
pub mod imu;
pub mod vehicle;
pub mod file_io;
pub mod ext_events;
use self::acquisition::MsgAcqResult;
use self::acquisition::MsgAcqResultDepC;
use self::acquisition::MsgAcqResultDepB;
use self::acquisition::MsgAcqResultDepA;
use self::acquisition::MsgAcqSvProfile;
use self::acquisition::MsgAcqSvProfileDep;
use self::logging::MsgLog;
use self::logging::MsgFwd;
use self::logging::MsgPrintDep;
use self::sbas::MsgSbasRaw;
use self::settings::MsgSettingsSave;
use self::settings::MsgSettingsWrite;
use self::settings::MsgSettingsWriteResp;
use self::settings::MsgSettingsReadReq;
use self::settings::MsgSettingsReadResp;
use self::settings::MsgSettingsReadByIndexReq;
use self::settings::MsgSettingsReadByIndexResp;
use self::settings::MsgSettingsReadByIndexDone;
use self::settings::MsgSettingsRegister;
use self::settings::MsgSettingsRegisterResp;
use self::mag::MsgMagRaw;
use self::tracking::MsgTrackingStateDetailedDepA;
use self::tracking::MsgTrackingStateDetailedDep;
use self::tracking::MsgTrackingState;
use self::tracking::MsgMeasurementState;
use self::tracking::MsgTrackingIq;
use self::tracking::MsgTrackingIqDepB;
use self::tracking::MsgTrackingIqDepA;
use self::tracking::MsgTrackingStateDepA;
use self::tracking::MsgTrackingStateDepB;
use self::flash::MsgFlashProgram;
use self::flash::MsgFlashDone;
use self::flash::MsgFlashReadReq;
use self::flash::MsgFlashReadResp;
use self::flash::MsgFlashErase;
use self::flash::MsgStmFlashLockSector;
use self::flash::MsgStmFlashUnlockSector;
use self::flash::MsgStmUniqueIdReq;
use self::flash::MsgStmUniqueIdResp;
use self::flash::MsgM25FlashWriteStatus;
use self::user::MsgUserData;
use self::piksi::MsgAlmanac;
use self::piksi::MsgSetTime;
use self::piksi::MsgReset;
use self::piksi::MsgResetDep;
use self::piksi::MsgCwResults;
use self::piksi::MsgCwStart;
use self::piksi::MsgResetFilters;
use self::piksi::MsgInitBaseDep;
use self::piksi::MsgThreadState;
use self::piksi::MsgUartState;
use self::piksi::MsgUartStateDepa;
use self::piksi::MsgIarState;
use self::piksi::MsgMaskSatellite;
use self::piksi::MsgMaskSatelliteDep;
use self::piksi::MsgDeviceMonitor;
use self::piksi::MsgCommandReq;
use self::piksi::MsgCommandResp;
use self::piksi::MsgCommandOutput;
use self::piksi::MsgNetworkStateReq;
use self::piksi::MsgNetworkStateResp;
use self::piksi::MsgNetworkBandwidthUsage;
use self::piksi::MsgCellModemStatus;
use self::piksi::MsgSpecanDep;
use self::piksi::MsgSpecan;
use self::piksi::MsgFrontEndGain;
use self::bootload::MsgBootloaderHandshakeReq;
use self::bootload::MsgBootloaderHandshakeResp;
use self::bootload::MsgBootloaderJumpToApp;
use self::bootload::MsgNapDeviceDnaReq;
use self::bootload::MsgNapDeviceDnaResp;
use self::bootload::MsgBootloaderHandshakeDepA;
use self::observation::MsgObs;
use self::observation::MsgBasePosLLH;
use self::observation::MsgBasePosECEF;
use self::observation::MsgEphemerisGPSDepE;
use self::observation::MsgEphemerisGPSDepF;
use self::observation::MsgEphemerisGPS;
use self::observation::MsgEphemerisQzss;
use self::observation::MsgEphemerisBds;
use self::observation::MsgEphemerisGalDepA;
use self::observation::MsgEphemerisGal;
use self::observation::MsgEphemerisSbasDepA;
use self::observation::MsgEphemerisGloDepA;
use self::observation::MsgEphemerisSbasDepB;
use self::observation::MsgEphemerisSbas;
use self::observation::MsgEphemerisGloDepB;
use self::observation::MsgEphemerisGloDepC;
use self::observation::MsgEphemerisGloDepD;
use self::observation::MsgEphemerisGlo;
use self::observation::MsgEphemerisDepD;
use self::observation::MsgEphemerisDepA;
use self::observation::MsgEphemerisDepB;
use self::observation::MsgEphemerisDepC;
use self::observation::MsgObsDepA;
use self::observation::MsgObsDepB;
use self::observation::MsgObsDepC;
use self::observation::MsgIono;
use self::observation::MsgSvConfigurationGPSDep;
use self::observation::MsgGnssCapb;
use self::observation::MsgGroupDelayDepA;
use self::observation::MsgGroupDelayDepB;
use self::observation::MsgGroupDelay;
use self::observation::MsgAlmanacGPSDep;
use self::observation::MsgAlmanacGPS;
use self::observation::MsgAlmanacGloDep;
use self::observation::MsgAlmanacGlo;
use self::observation::MsgGloBiases;
use self::observation::MsgSvAzEl;
use self::observation::MsgOsr;
use self::ssr::MsgSsrOrbitClock;
use self::ssr::MsgSsrOrbitClockDepA;
use self::ssr::MsgSsrCodeBiases;
use self::ssr::MsgSsrPhaseBiases;
use self::ssr::MsgSsrStecCorrection;
use self::ssr::MsgSsrGriddedCorrection;
use self::ssr::MsgSsrGridDefinition;
use self::navigation::MsgGPSTime;
use self::navigation::MsgUtcTime;
use self::navigation::MsgDops;
use self::navigation::MsgPosECEF;
use self::navigation::MsgPosECEFCov;
use self::navigation::MsgPosLLH;
use self::navigation::MsgPosLLHCov;
use self::navigation::MsgBaselineECEF;
use self::navigation::MsgBaselineNED;
use self::navigation::MsgVelECEF;
use self::navigation::MsgVelECEFCov;
use self::navigation::MsgVelNED;
use self::navigation::MsgVelNEDCov;
use self::navigation::MsgVelBody;
use self::navigation::MsgAgeCorrections;
use self::navigation::MsgGPSTimeDepA;
use self::navigation::MsgDopsDepA;
use self::navigation::MsgPosECEFDepA;
use self::navigation::MsgPosLLHDepA;
use self::navigation::MsgBaselineECEFDepA;
use self::navigation::MsgBaselineNEDDepA;
use self::navigation::MsgVelECEFDepA;
use self::navigation::MsgVelNEDDepA;
use self::navigation::MsgBaselineHeadingDepA;
use self::linux::MsgLinuxCpuState;
use self::linux::MsgLinuxMemState;
use self::linux::MsgLinuxSysState;
use self::linux::MsgLinuxProcessSocketCounts;
use self::linux::MsgLinuxProcessSocketQueues;
use self::linux::MsgLinuxSocketUsage;
use self::linux::MsgLinuxProcessFdCount;
use self::linux::MsgLinuxProcessFdSummary;
use self::orientation::MsgBaselineHeading;
use self::orientation::MsgOrientQuat;
use self::orientation::MsgOrientEuler;
use self::orientation::MsgAngularRate;
use self::system::MsgStartup;
use self::system::MsgDgnssStatus;
use self::system::MsgHeartbeat;
use self::system::MsgInsStatus;
use self::system::MsgCsacTelemetry;
use self::system::MsgCsacTelemetryLabels;
use self::ndb::MsgNdbEvent;
use self::imu::MsgImuRaw;
use self::imu::MsgImuAux;
use self::vehicle::MsgOdometry;
use self::file_io::MsgFileioReadReq;
use self::file_io::MsgFileioReadResp;
use self::file_io::MsgFileioReadDirReq;
use self::file_io::MsgFileioReadDirResp;
use self::file_io::MsgFileioRemove;
use self::file_io::MsgFileioWriteReq;
use self::file_io::MsgFileioWriteResp;
use self::file_io::MsgFileioConfigReq;
use self::file_io::MsgFileioConfigResp;
use self::ext_events::MsgExtEvent;

trait SBPMessage {
    const MSG_ID: u16;

    fn get_sender_id(&self) -> Option<u16>;
    fn set_sender_id(&mut self, new_id: u16);
}

#[derive(Debug)]
pub enum SBP {
    Unknown {
        msg_id: u16,
        sender_id: u16,
        payload: Vec<u8>,
    },
    MsgAcqResult(MsgAcqResult),
    MsgAcqResultDepC(MsgAcqResultDepC),
    MsgAcqResultDepB(MsgAcqResultDepB),
    MsgAcqResultDepA(MsgAcqResultDepA),
    MsgAcqSvProfile(MsgAcqSvProfile),
    MsgAcqSvProfileDep(MsgAcqSvProfileDep),
    MsgLog(MsgLog),
    MsgFwd(MsgFwd),
    MsgPrintDep(MsgPrintDep),
    MsgSbasRaw(MsgSbasRaw),
    MsgSettingsSave(MsgSettingsSave),
    MsgSettingsWrite(MsgSettingsWrite),
    MsgSettingsWriteResp(MsgSettingsWriteResp),
    MsgSettingsReadReq(MsgSettingsReadReq),
    MsgSettingsReadResp(MsgSettingsReadResp),
    MsgSettingsReadByIndexReq(MsgSettingsReadByIndexReq),
    MsgSettingsReadByIndexResp(MsgSettingsReadByIndexResp),
    MsgSettingsReadByIndexDone(MsgSettingsReadByIndexDone),
    MsgSettingsRegister(MsgSettingsRegister),
    MsgSettingsRegisterResp(MsgSettingsRegisterResp),
    MsgMagRaw(MsgMagRaw),
    MsgTrackingStateDetailedDepA(MsgTrackingStateDetailedDepA),
    MsgTrackingStateDetailedDep(MsgTrackingStateDetailedDep),
    MsgTrackingState(MsgTrackingState),
    MsgMeasurementState(MsgMeasurementState),
    MsgTrackingIq(MsgTrackingIq),
    MsgTrackingIqDepB(MsgTrackingIqDepB),
    MsgTrackingIqDepA(MsgTrackingIqDepA),
    MsgTrackingStateDepA(MsgTrackingStateDepA),
    MsgTrackingStateDepB(MsgTrackingStateDepB),
    MsgFlashProgram(MsgFlashProgram),
    MsgFlashDone(MsgFlashDone),
    MsgFlashReadReq(MsgFlashReadReq),
    MsgFlashReadResp(MsgFlashReadResp),
    MsgFlashErase(MsgFlashErase),
    MsgStmFlashLockSector(MsgStmFlashLockSector),
    MsgStmFlashUnlockSector(MsgStmFlashUnlockSector),
    MsgStmUniqueIdReq(MsgStmUniqueIdReq),
    MsgStmUniqueIdResp(MsgStmUniqueIdResp),
    MsgM25FlashWriteStatus(MsgM25FlashWriteStatus),
    MsgUserData(MsgUserData),
    MsgAlmanac(MsgAlmanac),
    MsgSetTime(MsgSetTime),
    MsgReset(MsgReset),
    MsgResetDep(MsgResetDep),
    MsgCwResults(MsgCwResults),
    MsgCwStart(MsgCwStart),
    MsgResetFilters(MsgResetFilters),
    MsgInitBaseDep(MsgInitBaseDep),
    MsgThreadState(MsgThreadState),
    MsgUartState(MsgUartState),
    MsgUartStateDepa(MsgUartStateDepa),
    MsgIarState(MsgIarState),
    MsgMaskSatellite(MsgMaskSatellite),
    MsgMaskSatelliteDep(MsgMaskSatelliteDep),
    MsgDeviceMonitor(MsgDeviceMonitor),
    MsgCommandReq(MsgCommandReq),
    MsgCommandResp(MsgCommandResp),
    MsgCommandOutput(MsgCommandOutput),
    MsgNetworkStateReq(MsgNetworkStateReq),
    MsgNetworkStateResp(MsgNetworkStateResp),
    MsgNetworkBandwidthUsage(MsgNetworkBandwidthUsage),
    MsgCellModemStatus(MsgCellModemStatus),
    MsgSpecanDep(MsgSpecanDep),
    MsgSpecan(MsgSpecan),
    MsgFrontEndGain(MsgFrontEndGain),
    MsgBootloaderHandshakeReq(MsgBootloaderHandshakeReq),
    MsgBootloaderHandshakeResp(MsgBootloaderHandshakeResp),
    MsgBootloaderJumpToApp(MsgBootloaderJumpToApp),
    MsgNapDeviceDnaReq(MsgNapDeviceDnaReq),
    MsgNapDeviceDnaResp(MsgNapDeviceDnaResp),
    MsgBootloaderHandshakeDepA(MsgBootloaderHandshakeDepA),
    MsgObs(MsgObs),
    MsgBasePosLLH(MsgBasePosLLH),
    MsgBasePosECEF(MsgBasePosECEF),
    MsgEphemerisGPSDepE(MsgEphemerisGPSDepE),
    MsgEphemerisGPSDepF(MsgEphemerisGPSDepF),
    MsgEphemerisGPS(MsgEphemerisGPS),
    MsgEphemerisQzss(MsgEphemerisQzss),
    MsgEphemerisBds(MsgEphemerisBds),
    MsgEphemerisGalDepA(MsgEphemerisGalDepA),
    MsgEphemerisGal(MsgEphemerisGal),
    MsgEphemerisSbasDepA(MsgEphemerisSbasDepA),
    MsgEphemerisGloDepA(MsgEphemerisGloDepA),
    MsgEphemerisSbasDepB(MsgEphemerisSbasDepB),
    MsgEphemerisSbas(MsgEphemerisSbas),
    MsgEphemerisGloDepB(MsgEphemerisGloDepB),
    MsgEphemerisGloDepC(MsgEphemerisGloDepC),
    MsgEphemerisGloDepD(MsgEphemerisGloDepD),
    MsgEphemerisGlo(MsgEphemerisGlo),
    MsgEphemerisDepD(MsgEphemerisDepD),
    MsgEphemerisDepA(MsgEphemerisDepA),
    MsgEphemerisDepB(MsgEphemerisDepB),
    MsgEphemerisDepC(MsgEphemerisDepC),
    MsgObsDepA(MsgObsDepA),
    MsgObsDepB(MsgObsDepB),
    MsgObsDepC(MsgObsDepC),
    MsgIono(MsgIono),
    MsgSvConfigurationGPSDep(MsgSvConfigurationGPSDep),
    MsgGnssCapb(MsgGnssCapb),
    MsgGroupDelayDepA(MsgGroupDelayDepA),
    MsgGroupDelayDepB(MsgGroupDelayDepB),
    MsgGroupDelay(MsgGroupDelay),
    MsgAlmanacGPSDep(MsgAlmanacGPSDep),
    MsgAlmanacGPS(MsgAlmanacGPS),
    MsgAlmanacGloDep(MsgAlmanacGloDep),
    MsgAlmanacGlo(MsgAlmanacGlo),
    MsgGloBiases(MsgGloBiases),
    MsgSvAzEl(MsgSvAzEl),
    MsgOsr(MsgOsr),
    MsgSsrOrbitClock(MsgSsrOrbitClock),
    MsgSsrOrbitClockDepA(MsgSsrOrbitClockDepA),
    MsgSsrCodeBiases(MsgSsrCodeBiases),
    MsgSsrPhaseBiases(MsgSsrPhaseBiases),
    MsgSsrStecCorrection(MsgSsrStecCorrection),
    MsgSsrGriddedCorrection(MsgSsrGriddedCorrection),
    MsgSsrGridDefinition(MsgSsrGridDefinition),
    MsgGPSTime(MsgGPSTime),
    MsgUtcTime(MsgUtcTime),
    MsgDops(MsgDops),
    MsgPosECEF(MsgPosECEF),
    MsgPosECEFCov(MsgPosECEFCov),
    MsgPosLLH(MsgPosLLH),
    MsgPosLLHCov(MsgPosLLHCov),
    MsgBaselineECEF(MsgBaselineECEF),
    MsgBaselineNED(MsgBaselineNED),
    MsgVelECEF(MsgVelECEF),
    MsgVelECEFCov(MsgVelECEFCov),
    MsgVelNED(MsgVelNED),
    MsgVelNEDCov(MsgVelNEDCov),
    MsgVelBody(MsgVelBody),
    MsgAgeCorrections(MsgAgeCorrections),
    MsgGPSTimeDepA(MsgGPSTimeDepA),
    MsgDopsDepA(MsgDopsDepA),
    MsgPosECEFDepA(MsgPosECEFDepA),
    MsgPosLLHDepA(MsgPosLLHDepA),
    MsgBaselineECEFDepA(MsgBaselineECEFDepA),
    MsgBaselineNEDDepA(MsgBaselineNEDDepA),
    MsgVelECEFDepA(MsgVelECEFDepA),
    MsgVelNEDDepA(MsgVelNEDDepA),
    MsgBaselineHeadingDepA(MsgBaselineHeadingDepA),
    MsgLinuxCpuState(MsgLinuxCpuState),
    MsgLinuxMemState(MsgLinuxMemState),
    MsgLinuxSysState(MsgLinuxSysState),
    MsgLinuxProcessSocketCounts(MsgLinuxProcessSocketCounts),
    MsgLinuxProcessSocketQueues(MsgLinuxProcessSocketQueues),
    MsgLinuxSocketUsage(MsgLinuxSocketUsage),
    MsgLinuxProcessFdCount(MsgLinuxProcessFdCount),
    MsgLinuxProcessFdSummary(MsgLinuxProcessFdSummary),
    MsgBaselineHeading(MsgBaselineHeading),
    MsgOrientQuat(MsgOrientQuat),
    MsgOrientEuler(MsgOrientEuler),
    MsgAngularRate(MsgAngularRate),
    MsgStartup(MsgStartup),
    MsgDgnssStatus(MsgDgnssStatus),
    MsgHeartbeat(MsgHeartbeat),
    MsgInsStatus(MsgInsStatus),
    MsgCsacTelemetry(MsgCsacTelemetry),
    MsgCsacTelemetryLabels(MsgCsacTelemetryLabels),
    MsgNdbEvent(MsgNdbEvent),
    MsgImuRaw(MsgImuRaw),
    MsgImuAux(MsgImuAux),
    MsgOdometry(MsgOdometry),
    MsgFileioReadReq(MsgFileioReadReq),
    MsgFileioReadResp(MsgFileioReadResp),
    MsgFileioReadDirReq(MsgFileioReadDirReq),
    MsgFileioReadDirResp(MsgFileioReadDirResp),
    MsgFileioRemove(MsgFileioRemove),
    MsgFileioWriteReq(MsgFileioWriteReq),
    MsgFileioWriteResp(MsgFileioWriteResp),
    MsgFileioConfigReq(MsgFileioConfigReq),
    MsgFileioConfigResp(MsgFileioConfigResp),
    MsgExtEvent(MsgExtEvent),
}

impl SBP {
    pub fn parse(msg_id: u16, sender_id: u16, payload: &mut &[u8]) -> Result<SBP, ::Error> {
        let x: Result<SBP, ::Error> = match msg_id {
            47 => {
                let mut msg = MsgAcqResult::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgAcqResult(msg))
            }
            31 => {
                let mut msg = MsgAcqResultDepC::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgAcqResultDepC(msg))
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
            46 => {
                let mut msg = MsgAcqSvProfile::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgAcqSvProfile(msg))
            }
            30 => {
                let mut msg = MsgAcqSvProfileDep::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgAcqSvProfileDep(msg))
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
            16 => {
                let mut msg = MsgPrintDep::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgPrintDep(msg))
            }
            30583 => {
                let mut msg = MsgSbasRaw::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgSbasRaw(msg))
            }
            161 => {
                let mut msg = MsgSettingsSave::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgSettingsSave(msg))
            }
            160 => {
                let mut msg = MsgSettingsWrite::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgSettingsWrite(msg))
            }
            175 => {
                let mut msg = MsgSettingsWriteResp::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgSettingsWriteResp(msg))
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
            162 => {
                let mut msg = MsgSettingsReadByIndexReq::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgSettingsReadByIndexReq(msg))
            }
            167 => {
                let mut msg = MsgSettingsReadByIndexResp::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgSettingsReadByIndexResp(msg))
            }
            166 => {
                let mut msg = MsgSettingsReadByIndexDone::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgSettingsReadByIndexDone(msg))
            }
            174 => {
                let mut msg = MsgSettingsRegister::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgSettingsRegister(msg))
            }
            431 => {
                let mut msg = MsgSettingsRegisterResp::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgSettingsRegisterResp(msg))
            }
            2306 => {
                let mut msg = MsgMagRaw::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgMagRaw(msg))
            }
            33 => {
                let mut msg = MsgTrackingStateDetailedDepA::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgTrackingStateDetailedDepA(msg))
            }
            17 => {
                let mut msg = MsgTrackingStateDetailedDep::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgTrackingStateDetailedDep(msg))
            }
            65 => {
                let mut msg = MsgTrackingState::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgTrackingState(msg))
            }
            97 => {
                let mut msg = MsgMeasurementState::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgMeasurementState(msg))
            }
            45 => {
                let mut msg = MsgTrackingIq::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgTrackingIq(msg))
            }
            44 => {
                let mut msg = MsgTrackingIqDepB::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgTrackingIqDepB(msg))
            }
            28 => {
                let mut msg = MsgTrackingIqDepA::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgTrackingIqDepA(msg))
            }
            22 => {
                let mut msg = MsgTrackingStateDepA::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgTrackingStateDepA(msg))
            }
            19 => {
                let mut msg = MsgTrackingStateDepB::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgTrackingStateDepB(msg))
            }
            230 => {
                let mut msg = MsgFlashProgram::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgFlashProgram(msg))
            }
            224 => {
                let mut msg = MsgFlashDone::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgFlashDone(msg))
            }
            231 => {
                let mut msg = MsgFlashReadReq::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgFlashReadReq(msg))
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
            232 => {
                let mut msg = MsgStmUniqueIdReq::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgStmUniqueIdReq(msg))
            }
            229 => {
                let mut msg = MsgStmUniqueIdResp::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgStmUniqueIdResp(msg))
            }
            243 => {
                let mut msg = MsgM25FlashWriteStatus::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgM25FlashWriteStatus(msg))
            }
            2048 => {
                let mut msg = MsgUserData::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgUserData(msg))
            }
            105 => {
                let mut msg = MsgAlmanac::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgAlmanac(msg))
            }
            104 => {
                let mut msg = MsgSetTime::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgSetTime(msg))
            }
            182 => {
                let mut msg = MsgReset::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgReset(msg))
            }
            178 => {
                let mut msg = MsgResetDep::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgResetDep(msg))
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
            23 => {
                let mut msg = MsgThreadState::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgThreadState(msg))
            }
            29 => {
                let mut msg = MsgUartState::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgUartState(msg))
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
            43 => {
                let mut msg = MsgMaskSatellite::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgMaskSatellite(msg))
            }
            27 => {
                let mut msg = MsgMaskSatelliteDep::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgMaskSatelliteDep(msg))
            }
            181 => {
                let mut msg = MsgDeviceMonitor::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgDeviceMonitor(msg))
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
            188 => {
                let mut msg = MsgCommandOutput::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgCommandOutput(msg))
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
            191 => {
                let mut msg = MsgFrontEndGain::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgFrontEndGain(msg))
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
            177 => {
                let mut msg = MsgBootloaderJumpToApp::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgBootloaderJumpToApp(msg))
            }
            222 => {
                let mut msg = MsgNapDeviceDnaReq::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgNapDeviceDnaReq(msg))
            }
            221 => {
                let mut msg = MsgNapDeviceDnaResp::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgNapDeviceDnaResp(msg))
            }
            176 => {
                let mut msg = MsgBootloaderHandshakeDepA::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgBootloaderHandshakeDepA(msg))
            }
            74 => {
                let mut msg = MsgObs::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgObs(msg))
            }
            68 => {
                let mut msg = MsgBasePosLLH::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgBasePosLLH(msg))
            }
            72 => {
                let mut msg = MsgBasePosECEF::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgBasePosECEF(msg))
            }
            129 => {
                let mut msg = MsgEphemerisGPSDepE::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgEphemerisGPSDepE(msg))
            }
            134 => {
                let mut msg = MsgEphemerisGPSDepF::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgEphemerisGPSDepF(msg))
            }
            138 => {
                let mut msg = MsgEphemerisGPS::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgEphemerisGPS(msg))
            }
            142 => {
                let mut msg = MsgEphemerisQzss::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgEphemerisQzss(msg))
            }
            137 => {
                let mut msg = MsgEphemerisBds::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgEphemerisBds(msg))
            }
            149 => {
                let mut msg = MsgEphemerisGalDepA::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgEphemerisGalDepA(msg))
            }
            141 => {
                let mut msg = MsgEphemerisGal::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgEphemerisGal(msg))
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
            140 => {
                let mut msg = MsgEphemerisSbas::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgEphemerisSbas(msg))
            }
            133 => {
                let mut msg = MsgEphemerisGloDepB::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgEphemerisGloDepB(msg))
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
            139 => {
                let mut msg = MsgEphemerisGlo::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgEphemerisGlo(msg))
            }
            128 => {
                let mut msg = MsgEphemerisDepD::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgEphemerisDepD(msg))
            }
            26 => {
                let mut msg = MsgEphemerisDepA::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgEphemerisDepA(msg))
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
            69 => {
                let mut msg = MsgObsDepA::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgObsDepA(msg))
            }
            67 => {
                let mut msg = MsgObsDepB::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgObsDepB(msg))
            }
            73 => {
                let mut msg = MsgObsDepC::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgObsDepC(msg))
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
            150 => {
                let mut msg = MsgGnssCapb::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgGnssCapb(msg))
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
            112 => {
                let mut msg = MsgAlmanacGPSDep::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgAlmanacGPSDep(msg))
            }
            114 => {
                let mut msg = MsgAlmanacGPS::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgAlmanacGPS(msg))
            }
            113 => {
                let mut msg = MsgAlmanacGloDep::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgAlmanacGloDep(msg))
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
            151 => {
                let mut msg = MsgSvAzEl::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgSvAzEl(msg))
            }
            1600 => {
                let mut msg = MsgOsr::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgOsr(msg))
            }
            1501 => {
                let mut msg = MsgSsrOrbitClock::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgSsrOrbitClock(msg))
            }
            1500 => {
                let mut msg = MsgSsrOrbitClockDepA::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgSsrOrbitClockDepA(msg))
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
                let mut msg = MsgSsrStecCorrection::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgSsrStecCorrection(msg))
            }
            1520 => {
                let mut msg = MsgSsrGriddedCorrection::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgSsrGriddedCorrection(msg))
            }
            1525 => {
                let mut msg = MsgSsrGridDefinition::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgSsrGridDefinition(msg))
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
            532 => {
                let mut msg = MsgPosECEFCov::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgPosECEFCov(msg))
            }
            522 => {
                let mut msg = MsgPosLLH::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgPosLLH(msg))
            }
            529 => {
                let mut msg = MsgPosLLHCov::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgPosLLHCov(msg))
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
            533 => {
                let mut msg = MsgVelECEFCov::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgVelECEFCov(msg))
            }
            526 => {
                let mut msg = MsgVelNED::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgVelNED(msg))
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
            528 => {
                let mut msg = MsgAgeCorrections::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgAgeCorrections(msg))
            }
            256 => {
                let mut msg = MsgGPSTimeDepA::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgGPSTimeDepA(msg))
            }
            518 => {
                let mut msg = MsgDopsDepA::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgDopsDepA(msg))
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
            519 => {
                let mut msg = MsgBaselineHeadingDepA::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgBaselineHeadingDepA(msg))
            }
            32512 => {
                let mut msg = MsgLinuxCpuState::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgLinuxCpuState(msg))
            }
            32513 => {
                let mut msg = MsgLinuxMemState::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgLinuxMemState(msg))
            }
            32514 => {
                let mut msg = MsgLinuxSysState::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgLinuxSysState(msg))
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
            527 => {
                let mut msg = MsgBaselineHeading::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgBaselineHeading(msg))
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
            65535 => {
                let mut msg = MsgHeartbeat::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgHeartbeat(msg))
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
            1024 => {
                let mut msg = MsgNdbEvent::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgNdbEvent(msg))
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
            2307 => {
                let mut msg = MsgOdometry::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgOdometry(msg))
            }
            168 => {
                let mut msg = MsgFileioReadReq::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgFileioReadReq(msg))
            }
            163 => {
                let mut msg = MsgFileioReadResp::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgFileioReadResp(msg))
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
            171 => {
                let mut msg = MsgFileioWriteResp::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgFileioWriteResp(msg))
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
            257 => {
                let mut msg = MsgExtEvent::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgExtEvent(msg))
            }
            _ => Ok(SBP::Unknown {
                msg_id: msg_id,
                sender_id: sender_id,
                payload: payload.to_vec(),
            }),
        };
        match x {
            Ok(x) => Ok(x),
            Err(_) => Err(::Error::ParseError),
        }
    }
}
