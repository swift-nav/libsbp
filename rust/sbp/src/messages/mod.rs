// Copyright (C) 2015-2018 Swift Navigation Inc.
// Contact: Swift Navigation <dev@swiftnav.com>
//
// This source is subject to the license found in the file 'LICENSE' which must
// be be distributed together with this source. All other rights reserved.
//
// THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
// EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
// WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
pub mod settings;
pub mod vehicle;
pub mod mag;
pub mod observation;
pub mod acquisition;
pub mod logging;
pub mod navigation;
pub mod gnss;
pub mod ndb;
pub mod linux;
pub mod flash;
pub mod piksi;
pub mod ext_events;
pub mod file_io;
pub mod user;
pub mod ssr;
pub mod bootload;
pub mod orientation;
pub mod system;
pub mod sbas;
pub mod tracking;
pub mod imu;
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
use self::vehicle::MsgOdometry;
use self::mag::MsgMagRaw;
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
use self::acquisition::MsgAcqResult;
use self::acquisition::MsgAcqResultDepC;
use self::acquisition::MsgAcqResultDepB;
use self::acquisition::MsgAcqResultDepA;
use self::acquisition::MsgAcqSvProfile;
use self::acquisition::MsgAcqSvProfileDep;
use self::logging::MsgLog;
use self::logging::MsgFwd;
use self::logging::MsgPrintDep;
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
use self::ndb::MsgNdbEvent;
use self::linux::MsgLinuxCpuState;
use self::linux::MsgLinuxMemState;
use self::linux::MsgLinuxSysState;
use self::linux::MsgLinuxProcessSocketCounts;
use self::linux::MsgLinuxProcessSocketQueues;
use self::linux::MsgLinuxSocketUsage;
use self::linux::MsgLinuxProcessFdCount;
use self::linux::MsgLinuxProcessFdSummary;
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
use self::ext_events::MsgExtEvent;
use self::file_io::MsgFileioReadReq;
use self::file_io::MsgFileioReadResp;
use self::file_io::MsgFileioReadDirReq;
use self::file_io::MsgFileioReadDirResp;
use self::file_io::MsgFileioRemove;
use self::file_io::MsgFileioWriteReq;
use self::file_io::MsgFileioWriteResp;
use self::file_io::MsgFileioConfigReq;
use self::file_io::MsgFileioConfigResp;
use self::user::MsgUserData;
use self::ssr::MsgSsrOrbitClock;
use self::ssr::MsgSsrOrbitClockDepA;
use self::ssr::MsgSsrCodeBiases;
use self::ssr::MsgSsrPhaseBiases;
use self::ssr::MsgSsrStecCorrection;
use self::ssr::MsgSsrGriddedCorrection;
use self::ssr::MsgSsrGridDefinition;
use self::bootload::MsgBootloaderHandshakeReq;
use self::bootload::MsgBootloaderHandshakeResp;
use self::bootload::MsgBootloaderJumpToApp;
use self::bootload::MsgNapDeviceDnaReq;
use self::bootload::MsgNapDeviceDnaResp;
use self::bootload::MsgBootloaderHandshakeDepA;
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
use self::sbas::MsgSbasRaw;
use self::tracking::MsgTrackingStateDetailedDepA;
use self::tracking::MsgTrackingStateDetailedDep;
use self::tracking::MsgTrackingState;
use self::tracking::MsgMeasurementState;
use self::tracking::MsgTrackingIq;
use self::tracking::MsgTrackingIqDepB;
use self::tracking::MsgTrackingIqDepA;
use self::tracking::MsgTrackingStateDepA;
use self::tracking::MsgTrackingStateDepB;
use self::imu::MsgImuRaw;
use self::imu::MsgImuAux;

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
    MsgImuAux(MsgImuAux),
    MsgSvAzEl(MsgSvAzEl),
    MsgSsrGridDefinition(MsgSsrGridDefinition),
    MsgUartStateDepa(MsgUartStateDepa),
    MsgInitBaseDep(MsgInitBaseDep),
    MsgAcqSvProfileDep(MsgAcqSvProfileDep),
    MsgBootloaderHandshakeDepA(MsgBootloaderHandshakeDepA),
    MsgTrackingStateDepA(MsgTrackingStateDepA),
    MsgTrackingStateDepB(MsgTrackingStateDepB),
    MsgMaskSatelliteDep(MsgMaskSatelliteDep),
    MsgTrackingIqDepA(MsgTrackingIqDepA),
    MsgSpecanDep(MsgSpecanDep),
    MsgAcqResultDepC(MsgAcqResultDepC),
    MsgObsDepA(MsgObsDepA),
    MsgTrackingStateDetailedDep(MsgTrackingStateDetailedDep),
    MsgAcqResultDepA(MsgAcqResultDepA),
    MsgAcqResultDepB(MsgAcqResultDepB),
    MsgPrintDep(MsgPrintDep),
    MsgEphemerisDepB(MsgEphemerisDepB),
    MsgEphemerisDepA(MsgEphemerisDepA),
    MsgCellModemStatus(MsgCellModemStatus),
    MsgOdometry(MsgOdometry),
    MsgGroupDelayDepA(MsgGroupDelayDepA),
    MsgGroupDelay(MsgGroupDelay),
    MsgGroupDelayDepB(MsgGroupDelayDepB),
    MsgSvConfigurationGPSDep(MsgSvConfigurationGPSDep),
    MsgImuRaw(MsgImuRaw),
    MsgMagRaw(MsgMagRaw),
    MsgExtEvent(MsgExtEvent),
    MsgNetworkStateReq(MsgNetworkStateReq),
    MsgCommandReq(MsgCommandReq),
    MsgFileioConfigReq(MsgFileioConfigReq),
    MsgSettingsWriteResp(MsgSettingsWriteResp),
    MsgCommandOutput(MsgCommandOutput),
    MsgSsrGriddedCorrection(MsgSsrGriddedCorrection),
    MsgSpecan(MsgSpecan),
    MsgLinuxSocketUsage(MsgLinuxSocketUsage),
    MsgLinuxProcessFdSummary(MsgLinuxProcessFdSummary),
    MsgCsacTelemetry(MsgCsacTelemetry),
    MsgCsacTelemetryLabels(MsgCsacTelemetryLabels),
    MsgGloBiases(MsgGloBiases),
    MsgObs(MsgObs),
    MsgObsDepC(MsgObsDepC),
    MsgInsStatus(MsgInsStatus),
    MsgOsr(MsgOsr),
    MsgSsrStecCorrection(MsgSsrStecCorrection),
    MsgUartState(MsgUartState),
    MsgFileioConfigResp(MsgFileioConfigResp),
    MsgAlmanacGlo(MsgAlmanacGlo),
    MsgAlmanacGloDep(MsgAlmanacGloDep),
    MsgAlmanacGPS(MsgAlmanacGPS),
    MsgAlmanacGPSDep(MsgAlmanacGPSDep),
    MsgNetworkBandwidthUsage(MsgNetworkBandwidthUsage),
    MsgBasePosECEF(MsgBasePosECEF),
    MsgBasePosLLH(MsgBasePosLLH),
    MsgNapDeviceDnaResp(MsgNapDeviceDnaResp),
    MsgNapDeviceDnaReq(MsgNapDeviceDnaReq),
    MsgEphemerisBds(MsgEphemerisBds),
    MsgEphemerisGlo(MsgEphemerisGlo),
    MsgEphemerisGloDepA(MsgEphemerisGloDepA),
    MsgEphemerisGloDepB(MsgEphemerisGloDepB),
    MsgEphemerisGloDepC(MsgEphemerisGloDepC),
    MsgEphemerisGPS(MsgEphemerisGPS),
    MsgEphemerisGPSDepE(MsgEphemerisGPSDepE),
    MsgEphemerisDepC(MsgEphemerisDepC),
    MsgEphemerisDepD(MsgEphemerisDepD),
    MsgEphemerisGal(MsgEphemerisGal),
    MsgEphemerisQzss(MsgEphemerisQzss),
    MsgFileioReadReq(MsgFileioReadReq),
    MsgFileioReadResp(MsgFileioReadResp),
    MsgFileioRemove(MsgFileioRemove),
    MsgFileioWriteReq(MsgFileioWriteReq),
    MsgFileioWriteResp(MsgFileioWriteResp),
    MsgFlashErase(MsgFlashErase),
    MsgStmFlashLockSector(MsgStmFlashLockSector),
    MsgFlashProgram(MsgFlashProgram),
    MsgFlashReadReq(MsgFlashReadReq),
    MsgFlashReadResp(MsgFlashReadResp),
    MsgM25FlashWriteStatus(MsgM25FlashWriteStatus),
    MsgStmFlashUnlockSector(MsgStmFlashUnlockSector),
    MsgBootloaderHandshakeReq(MsgBootloaderHandshakeReq),
    MsgBootloaderHandshakeResp(MsgBootloaderHandshakeResp),
    MsgHeartbeat(MsgHeartbeat),
    MsgBootloaderJumpToApp(MsgBootloaderJumpToApp),
    MsgIono(MsgIono),
    MsgAcqSvProfile(MsgAcqSvProfile),
    MsgPosECEFDepA(MsgPosECEFDepA),
    MsgPosECEF(MsgPosECEF),
    MsgPosECEFCov(MsgPosECEFCov),
    MsgSsrCodeBiases(MsgSsrCodeBiases),
    MsgSsrOrbitClock(MsgSsrOrbitClock),
    MsgSsrOrbitClockDepA(MsgSsrOrbitClockDepA),
    MsgSsrPhaseBiases(MsgSsrPhaseBiases),
    MsgFileioReadDirReq(MsgFileioReadDirReq),
    MsgFileioReadDirResp(MsgFileioReadDirResp),
    MsgCommandResp(MsgCommandResp),
    MsgSettingsSave(MsgSettingsSave),
    MsgSettingsReadReq(MsgSettingsReadReq),
    MsgSettingsReadResp(MsgSettingsReadResp),
    MsgSettingsWrite(MsgSettingsWrite),
    MsgSettingsReadByIndexDone(MsgSettingsReadByIndexDone),
    MsgSettingsReadByIndexReq(MsgSettingsReadByIndexReq),
    MsgSettingsReadByIndexResp(MsgSettingsReadByIndexResp),
    MsgNetworkStateResp(MsgNetworkStateResp),
    MsgStartup(MsgStartup),
    MsgThreadState(MsgThreadState),
    MsgTrackingStateDetailedDepA(MsgTrackingStateDetailedDepA),
    MsgMeasurementState(MsgMeasurementState),
    MsgTrackingState(MsgTrackingState),
    MsgDops(MsgDops),
    MsgDopsDepA(MsgDopsDepA),
    MsgAlmanac(MsgAlmanac),
    MsgCwResults(MsgCwResults),
    MsgCwStart(MsgCwStart),
    MsgMaskSatellite(MsgMaskSatellite),
    MsgUserData(MsgUserData),
    MsgLog(MsgLog),
    MsgDeviceMonitor(MsgDeviceMonitor),
    MsgFlashDone(MsgFlashDone),
    MsgFrontEndGain(MsgFrontEndGain),
    MsgAcqResult(MsgAcqResult),
    MsgReset(MsgReset),
    MsgResetDep(MsgResetDep),
    MsgLinuxCpuState(MsgLinuxCpuState),
    MsgLinuxMemState(MsgLinuxMemState),
    MsgSbasRaw(MsgSbasRaw),
    MsgNdbEvent(MsgNdbEvent),
    MsgDgnssStatus(MsgDgnssStatus),
    MsgFwd(MsgFwd),
    MsgStmUniqueIdResp(MsgStmUniqueIdResp),
    MsgStmUniqueIdReq(MsgStmUniqueIdReq),
    MsgSettingsRegister(MsgSettingsRegister),
    MsgAgeCorrections(MsgAgeCorrections),
    MsgGPSTime(MsgGPSTime),
    MsgGPSTimeDepA(MsgGPSTimeDepA),
    MsgUtcTime(MsgUtcTime),
    MsgBaselineHeading(MsgBaselineHeading),
    MsgBaselineHeadingDepA(MsgBaselineHeadingDepA),
    MsgBaselineECEFDepA(MsgBaselineECEFDepA),
    MsgBaselineECEF(MsgBaselineECEF),
    MsgBaselineNEDDepA(MsgBaselineNEDDepA),
    MsgBaselineNED(MsgBaselineNED),
    MsgAngularRate(MsgAngularRate),
    MsgOrientQuat(MsgOrientQuat),
    MsgIarState(MsgIarState),
    MsgVelECEFDepA(MsgVelECEFDepA),
    MsgVelECEF(MsgVelECEF),
    MsgVelECEFCov(MsgVelECEFCov),
    MsgVelNEDCov(MsgVelNEDCov),
    MsgVelNEDDepA(MsgVelNEDDepA),
    MsgVelNED(MsgVelNED),
    MsgVelBody(MsgVelBody),
    MsgOrientEuler(MsgOrientEuler),
    MsgResetFilters(MsgResetFilters),
    MsgSettingsRegisterResp(MsgSettingsRegisterResp),
    MsgSetTime(MsgSetTime),
    MsgEphemerisGalDepA(MsgEphemerisGalDepA),
    MsgEphemerisSbasDepB(MsgEphemerisSbasDepB),
    MsgEphemerisGloDepD(MsgEphemerisGloDepD),
    MsgEphemerisGPSDepF(MsgEphemerisGPSDepF),
    MsgObsDepB(MsgObsDepB),
    MsgPosLLHCov(MsgPosLLHCov),
    MsgPosLLH(MsgPosLLH),
    MsgPosLLHDepA(MsgPosLLHDepA),
    MsgLinuxSysState(MsgLinuxSysState),
    MsgLinuxProcessFdCount(MsgLinuxProcessFdCount),
    MsgLinuxProcessSocketCounts(MsgLinuxProcessSocketCounts),
    MsgLinuxProcessSocketQueues(MsgLinuxProcessSocketQueues),
    MsgTrackingIq(MsgTrackingIq),
    MsgTrackingIqDepB(MsgTrackingIqDepB),
    MsgEphemerisSbas(MsgEphemerisSbas),
    MsgEphemerisSbasDepA(MsgEphemerisSbasDepA),
    MsgGnssCapb(MsgGnssCapb),
}

impl SBP {
    pub fn parse(msg_id: u16, sender_id: u16, payload: &mut &[u8]) -> Result<SBP, ::Error> {
        let x: Result<SBP, ::Error> = match msg_id {
            2305 => {
                let mut msg = MsgImuAux::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgImuAux(msg))
            }
            151 => {
                let mut msg = MsgSvAzEl::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgSvAzEl(msg))
            }
            1525 => {
                let mut msg = MsgSsrGridDefinition::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgSsrGridDefinition(msg))
            }
            24 => {
                let mut msg = MsgUartStateDepa::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgUartStateDepa(msg))
            }
            35 => {
                let mut msg = MsgInitBaseDep::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgInitBaseDep(msg))
            }
            30 => {
                let mut msg = MsgAcqSvProfileDep::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgAcqSvProfileDep(msg))
            }
            176 => {
                let mut msg = MsgBootloaderHandshakeDepA::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgBootloaderHandshakeDepA(msg))
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
            80 => {
                let mut msg = MsgSpecanDep::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgSpecanDep(msg))
            }
            31 => {
                let mut msg = MsgAcqResultDepC::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgAcqResultDepC(msg))
            }
            69 => {
                let mut msg = MsgObsDepA::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgObsDepA(msg))
            }
            17 => {
                let mut msg = MsgTrackingStateDetailedDep::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgTrackingStateDetailedDep(msg))
            }
            21 => {
                let mut msg = MsgAcqResultDepA::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgAcqResultDepA(msg))
            }
            20 => {
                let mut msg = MsgAcqResultDepB::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgAcqResultDepB(msg))
            }
            16 => {
                let mut msg = MsgPrintDep::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgPrintDep(msg))
            }
            70 => {
                let mut msg = MsgEphemerisDepB::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgEphemerisDepB(msg))
            }
            26 => {
                let mut msg = MsgEphemerisDepA::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgEphemerisDepA(msg))
            }
            190 => {
                let mut msg = MsgCellModemStatus::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgCellModemStatus(msg))
            }
            2307 => {
                let mut msg = MsgOdometry::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgOdometry(msg))
            }
            146 => {
                let mut msg = MsgGroupDelayDepA::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgGroupDelayDepA(msg))
            }
            148 => {
                let mut msg = MsgGroupDelay::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgGroupDelay(msg))
            }
            147 => {
                let mut msg = MsgGroupDelayDepB::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgGroupDelayDepB(msg))
            }
            145 => {
                let mut msg = MsgSvConfigurationGPSDep::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgSvConfigurationGPSDep(msg))
            }
            2304 => {
                let mut msg = MsgImuRaw::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgImuRaw(msg))
            }
            2306 => {
                let mut msg = MsgMagRaw::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgMagRaw(msg))
            }
            257 => {
                let mut msg = MsgExtEvent::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgExtEvent(msg))
            }
            186 => {
                let mut msg = MsgNetworkStateReq::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgNetworkStateReq(msg))
            }
            184 => {
                let mut msg = MsgCommandReq::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgCommandReq(msg))
            }
            4097 => {
                let mut msg = MsgFileioConfigReq::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgFileioConfigReq(msg))
            }
            175 => {
                let mut msg = MsgSettingsWriteResp::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgSettingsWriteResp(msg))
            }
            188 => {
                let mut msg = MsgCommandOutput::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgCommandOutput(msg))
            }
            1520 => {
                let mut msg = MsgSsrGriddedCorrection::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgSsrGriddedCorrection(msg))
            }
            81 => {
                let mut msg = MsgSpecan::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgSpecan(msg))
            }
            32517 => {
                let mut msg = MsgLinuxSocketUsage::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgLinuxSocketUsage(msg))
            }
            32519 => {
                let mut msg = MsgLinuxProcessFdSummary::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgLinuxProcessFdSummary(msg))
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
            117 => {
                let mut msg = MsgGloBiases::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgGloBiases(msg))
            }
            74 => {
                let mut msg = MsgObs::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgObs(msg))
            }
            73 => {
                let mut msg = MsgObsDepC::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgObsDepC(msg))
            }
            65283 => {
                let mut msg = MsgInsStatus::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgInsStatus(msg))
            }
            1600 => {
                let mut msg = MsgOsr::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgOsr(msg))
            }
            1515 => {
                let mut msg = MsgSsrStecCorrection::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgSsrStecCorrection(msg))
            }
            29 => {
                let mut msg = MsgUartState::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgUartState(msg))
            }
            4098 => {
                let mut msg = MsgFileioConfigResp::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgFileioConfigResp(msg))
            }
            115 => {
                let mut msg = MsgAlmanacGlo::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgAlmanacGlo(msg))
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
            112 => {
                let mut msg = MsgAlmanacGPSDep::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgAlmanacGPSDep(msg))
            }
            189 => {
                let mut msg = MsgNetworkBandwidthUsage::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgNetworkBandwidthUsage(msg))
            }
            72 => {
                let mut msg = MsgBasePosECEF::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgBasePosECEF(msg))
            }
            68 => {
                let mut msg = MsgBasePosLLH::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgBasePosLLH(msg))
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
            137 => {
                let mut msg = MsgEphemerisBds::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgEphemerisBds(msg))
            }
            139 => {
                let mut msg = MsgEphemerisGlo::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgEphemerisGlo(msg))
            }
            131 => {
                let mut msg = MsgEphemerisGloDepA::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgEphemerisGloDepA(msg))
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
            138 => {
                let mut msg = MsgEphemerisGPS::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgEphemerisGPS(msg))
            }
            129 => {
                let mut msg = MsgEphemerisGPSDepE::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgEphemerisGPSDepE(msg))
            }
            71 => {
                let mut msg = MsgEphemerisDepC::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgEphemerisDepC(msg))
            }
            128 => {
                let mut msg = MsgEphemerisDepD::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgEphemerisDepD(msg))
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
            225 => {
                let mut msg = MsgFlashReadResp::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgFlashReadResp(msg))
            }
            243 => {
                let mut msg = MsgM25FlashWriteStatus::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgM25FlashWriteStatus(msg))
            }
            228 => {
                let mut msg = MsgStmFlashUnlockSector::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgStmFlashUnlockSector(msg))
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
            65535 => {
                let mut msg = MsgHeartbeat::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgHeartbeat(msg))
            }
            177 => {
                let mut msg = MsgBootloaderJumpToApp::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgBootloaderJumpToApp(msg))
            }
            144 => {
                let mut msg = MsgIono::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgIono(msg))
            }
            46 => {
                let mut msg = MsgAcqSvProfile::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgAcqSvProfile(msg))
            }
            512 => {
                let mut msg = MsgPosECEFDepA::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgPosECEFDepA(msg))
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
            1505 => {
                let mut msg = MsgSsrCodeBiases::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgSsrCodeBiases(msg))
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
            1510 => {
                let mut msg = MsgSsrPhaseBiases::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgSsrPhaseBiases(msg))
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
            185 => {
                let mut msg = MsgCommandResp::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgCommandResp(msg))
            }
            161 => {
                let mut msg = MsgSettingsSave::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgSettingsSave(msg))
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
            160 => {
                let mut msg = MsgSettingsWrite::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgSettingsWrite(msg))
            }
            166 => {
                let mut msg = MsgSettingsReadByIndexDone::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgSettingsReadByIndexDone(msg))
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
            187 => {
                let mut msg = MsgNetworkStateResp::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgNetworkStateResp(msg))
            }
            65280 => {
                let mut msg = MsgStartup::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgStartup(msg))
            }
            23 => {
                let mut msg = MsgThreadState::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgThreadState(msg))
            }
            33 => {
                let mut msg = MsgTrackingStateDetailedDepA::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgTrackingStateDetailedDepA(msg))
            }
            97 => {
                let mut msg = MsgMeasurementState::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgMeasurementState(msg))
            }
            65 => {
                let mut msg = MsgTrackingState::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgTrackingState(msg))
            }
            520 => {
                let mut msg = MsgDops::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgDops(msg))
            }
            518 => {
                let mut msg = MsgDopsDepA::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgDopsDepA(msg))
            }
            105 => {
                let mut msg = MsgAlmanac::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgAlmanac(msg))
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
            43 => {
                let mut msg = MsgMaskSatellite::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgMaskSatellite(msg))
            }
            2048 => {
                let mut msg = MsgUserData::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgUserData(msg))
            }
            1025 => {
                let mut msg = MsgLog::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgLog(msg))
            }
            181 => {
                let mut msg = MsgDeviceMonitor::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgDeviceMonitor(msg))
            }
            224 => {
                let mut msg = MsgFlashDone::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgFlashDone(msg))
            }
            191 => {
                let mut msg = MsgFrontEndGain::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgFrontEndGain(msg))
            }
            47 => {
                let mut msg = MsgAcqResult::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgAcqResult(msg))
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
            30583 => {
                let mut msg = MsgSbasRaw::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgSbasRaw(msg))
            }
            1024 => {
                let mut msg = MsgNdbEvent::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgNdbEvent(msg))
            }
            65282 => {
                let mut msg = MsgDgnssStatus::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgDgnssStatus(msg))
            }
            1026 => {
                let mut msg = MsgFwd::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgFwd(msg))
            }
            229 => {
                let mut msg = MsgStmUniqueIdResp::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgStmUniqueIdResp(msg))
            }
            232 => {
                let mut msg = MsgStmUniqueIdReq::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgStmUniqueIdReq(msg))
            }
            174 => {
                let mut msg = MsgSettingsRegister::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgSettingsRegister(msg))
            }
            528 => {
                let mut msg = MsgAgeCorrections::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgAgeCorrections(msg))
            }
            258 => {
                let mut msg = MsgGPSTime::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgGPSTime(msg))
            }
            256 => {
                let mut msg = MsgGPSTimeDepA::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgGPSTimeDepA(msg))
            }
            259 => {
                let mut msg = MsgUtcTime::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgUtcTime(msg))
            }
            527 => {
                let mut msg = MsgBaselineHeading::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgBaselineHeading(msg))
            }
            519 => {
                let mut msg = MsgBaselineHeadingDepA::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgBaselineHeadingDepA(msg))
            }
            514 => {
                let mut msg = MsgBaselineECEFDepA::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgBaselineECEFDepA(msg))
            }
            523 => {
                let mut msg = MsgBaselineECEF::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgBaselineECEF(msg))
            }
            515 => {
                let mut msg = MsgBaselineNEDDepA::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgBaselineNEDDepA(msg))
            }
            524 => {
                let mut msg = MsgBaselineNED::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgBaselineNED(msg))
            }
            546 => {
                let mut msg = MsgAngularRate::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgAngularRate(msg))
            }
            544 => {
                let mut msg = MsgOrientQuat::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgOrientQuat(msg))
            }
            25 => {
                let mut msg = MsgIarState::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgIarState(msg))
            }
            516 => {
                let mut msg = MsgVelECEFDepA::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgVelECEFDepA(msg))
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
            530 => {
                let mut msg = MsgVelNEDCov::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgVelNEDCov(msg))
            }
            517 => {
                let mut msg = MsgVelNEDDepA::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgVelNEDDepA(msg))
            }
            526 => {
                let mut msg = MsgVelNED::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgVelNED(msg))
            }
            531 => {
                let mut msg = MsgVelBody::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgVelBody(msg))
            }
            545 => {
                let mut msg = MsgOrientEuler::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgOrientEuler(msg))
            }
            34 => {
                let mut msg = MsgResetFilters::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgResetFilters(msg))
            }
            431 => {
                let mut msg = MsgSettingsRegisterResp::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgSettingsRegisterResp(msg))
            }
            104 => {
                let mut msg = MsgSetTime::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgSetTime(msg))
            }
            149 => {
                let mut msg = MsgEphemerisGalDepA::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgEphemerisGalDepA(msg))
            }
            132 => {
                let mut msg = MsgEphemerisSbasDepB::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgEphemerisSbasDepB(msg))
            }
            136 => {
                let mut msg = MsgEphemerisGloDepD::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgEphemerisGloDepD(msg))
            }
            134 => {
                let mut msg = MsgEphemerisGPSDepF::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgEphemerisGPSDepF(msg))
            }
            67 => {
                let mut msg = MsgObsDepB::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgObsDepB(msg))
            }
            529 => {
                let mut msg = MsgPosLLHCov::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgPosLLHCov(msg))
            }
            522 => {
                let mut msg = MsgPosLLH::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgPosLLH(msg))
            }
            513 => {
                let mut msg = MsgPosLLHDepA::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgPosLLHDepA(msg))
            }
            32514 => {
                let mut msg = MsgLinuxSysState::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgLinuxSysState(msg))
            }
            32518 => {
                let mut msg = MsgLinuxProcessFdCount::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgLinuxProcessFdCount(msg))
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
            140 => {
                let mut msg = MsgEphemerisSbas::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgEphemerisSbas(msg))
            }
            130 => {
                let mut msg = MsgEphemerisSbasDepA::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgEphemerisSbasDepA(msg))
            }
            150 => {
                let mut msg = MsgGnssCapb::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::MsgGnssCapb(msg))
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
