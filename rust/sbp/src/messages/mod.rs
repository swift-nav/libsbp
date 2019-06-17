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
pub mod ssr;
pub mod system;
pub mod tracking;
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
use self::linux::MsgLinuxMemState;
use self::linux::MsgLinuxProcessFdCount;
use self::linux::MsgLinuxProcessFdSummary;
use self::linux::MsgLinuxProcessSocketCounts;
use self::linux::MsgLinuxProcessSocketQueues;
use self::linux::MsgLinuxSocketUsage;
use self::linux::MsgLinuxSysState;
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
use self::navigation::MsgPosECEF;
use self::navigation::MsgPosECEFCov;
use self::navigation::MsgPosECEFDepA;
use self::navigation::MsgPosLLH;
use self::navigation::MsgPosLLHCov;
use self::navigation::MsgPosLLHDepA;
use self::navigation::MsgUtcTime;
use self::navigation::MsgVelBody;
use self::navigation::MsgVelECEF;
use self::navigation::MsgVelECEFCov;
use self::navigation::MsgVelECEFDepA;
use self::navigation::MsgVelNED;
use self::navigation::MsgVelNEDCov;
use self::navigation::MsgVelNEDDepA;
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
use self::ssr::MsgSsrCodeBiases;
use self::ssr::MsgSsrGridDefinition;
use self::ssr::MsgSsrGriddedCorrection;
use self::ssr::MsgSsrOrbitClock;
use self::ssr::MsgSsrOrbitClockDepA;
use self::ssr::MsgSsrPhaseBiases;
use self::ssr::MsgSsrStecCorrection;
use self::system::MsgCsacTelemetry;
use self::system::MsgCsacTelemetryLabels;
use self::system::MsgDgnssStatus;
use self::system::MsgHeartbeat;
use self::system::MsgInsStatus;
use self::system::MsgStartup;
use self::tracking::MsgMeasurementState;
use self::tracking::MsgTrackingIq;
use self::tracking::MsgTrackingIqDepA;
use self::tracking::MsgTrackingIqDepB;
use self::tracking::MsgTrackingState;
use self::tracking::MsgTrackingStateDepA;
use self::tracking::MsgTrackingStateDepB;
use self::tracking::MsgTrackingStateDetailedDep;
use self::tracking::MsgTrackingStateDetailedDepA;
use self::user::MsgUserData;
use self::vehicle::MsgOdometry;

#[derive(Debug)]
pub enum SBP {
    Unknown { id: u16 },
    MsgSsrOrbitClock(MsgSsrOrbitClock),
    MsgSsrOrbitClockDepA(MsgSsrOrbitClockDepA),
    MsgSsrCodeBiases(MsgSsrCodeBiases),
    MsgSsrPhaseBiases(MsgSsrPhaseBiases),
    MsgSsrStecCorrection(MsgSsrStecCorrection),
    MsgSsrGriddedCorrection(MsgSsrGriddedCorrection),
    MsgSsrGridDefinition(MsgSsrGridDefinition),
    MsgNdbEvent(MsgNdbEvent),
    MsgImuRaw(MsgImuRaw),
    MsgImuAux(MsgImuAux),
    MsgUserData(MsgUserData),
    MsgOdometry(MsgOdometry),
    MsgSbasRaw(MsgSbasRaw),
    MsgAcqResult(MsgAcqResult),
    MsgAcqResultDepC(MsgAcqResultDepC),
    MsgAcqResultDepB(MsgAcqResultDepB),
    MsgAcqResultDepA(MsgAcqResultDepA),
    MsgAcqSvProfile(MsgAcqSvProfile),
    MsgAcqSvProfileDep(MsgAcqSvProfileDep),
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
    MsgFileioReadReq(MsgFileioReadReq),
    MsgFileioReadResp(MsgFileioReadResp),
    MsgFileioReadDirReq(MsgFileioReadDirReq),
    MsgFileioReadDirResp(MsgFileioReadDirResp),
    MsgFileioRemove(MsgFileioRemove),
    MsgFileioWriteReq(MsgFileioWriteReq),
    MsgFileioWriteResp(MsgFileioWriteResp),
    MsgFileioConfigReq(MsgFileioConfigReq),
    MsgFileioConfigResp(MsgFileioConfigResp),
    MsgStartup(MsgStartup),
    MsgDgnssStatus(MsgDgnssStatus),
    MsgHeartbeat(MsgHeartbeat),
    MsgInsStatus(MsgInsStatus),
    MsgCsacTelemetry(MsgCsacTelemetry),
    MsgCsacTelemetryLabels(MsgCsacTelemetryLabels),
    MsgLinuxCpuState(MsgLinuxCpuState),
    MsgLinuxMemState(MsgLinuxMemState),
    MsgLinuxSysState(MsgLinuxSysState),
    MsgLinuxProcessSocketCounts(MsgLinuxProcessSocketCounts),
    MsgLinuxProcessSocketQueues(MsgLinuxProcessSocketQueues),
    MsgLinuxSocketUsage(MsgLinuxSocketUsage),
    MsgLinuxProcessFdCount(MsgLinuxProcessFdCount),
    MsgLinuxProcessFdSummary(MsgLinuxProcessFdSummary),
    MsgExtEvent(MsgExtEvent),
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
    MsgBaselineHeading(MsgBaselineHeading),
    MsgOrientQuat(MsgOrientQuat),
    MsgOrientEuler(MsgOrientEuler),
    MsgAngularRate(MsgAngularRate),
    MsgTrackingStateDetailedDepA(MsgTrackingStateDetailedDepA),
    MsgTrackingStateDetailedDep(MsgTrackingStateDetailedDep),
    MsgTrackingState(MsgTrackingState),
    MsgMeasurementState(MsgMeasurementState),
    MsgTrackingIq(MsgTrackingIq),
    MsgTrackingIqDepB(MsgTrackingIqDepB),
    MsgTrackingIqDepA(MsgTrackingIqDepA),
    MsgTrackingStateDepA(MsgTrackingStateDepA),
    MsgTrackingStateDepB(MsgTrackingStateDepB),
    MsgLog(MsgLog),
    MsgFwd(MsgFwd),
    MsgPrintDep(MsgPrintDep),
    MsgBootloaderHandshakeReq(MsgBootloaderHandshakeReq),
    MsgBootloaderHandshakeResp(MsgBootloaderHandshakeResp),
    MsgBootloaderJumpToApp(MsgBootloaderJumpToApp),
    MsgNapDeviceDnaReq(MsgNapDeviceDnaReq),
    MsgNapDeviceDnaResp(MsgNapDeviceDnaResp),
    MsgBootloaderHandshakeDepA(MsgBootloaderHandshakeDepA),
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
    MsgMagRaw(MsgMagRaw),
}

impl SBP {
    pub fn parse(id: u16, payload: &mut &[u8]) -> Result<SBP, ::Error> {
        let x: Result<SBP, ::Error> = match id {
            1501 => Ok(SBP::MsgSsrOrbitClock(MsgSsrOrbitClock::parse(payload)?)),
            1500 => Ok(SBP::MsgSsrOrbitClockDepA(MsgSsrOrbitClockDepA::parse(
                payload,
            )?)),
            1505 => Ok(SBP::MsgSsrCodeBiases(MsgSsrCodeBiases::parse(payload)?)),
            1510 => Ok(SBP::MsgSsrPhaseBiases(MsgSsrPhaseBiases::parse(payload)?)),
            1515 => Ok(SBP::MsgSsrStecCorrection(MsgSsrStecCorrection::parse(
                payload,
            )?)),
            1520 => Ok(SBP::MsgSsrGriddedCorrection(
                MsgSsrGriddedCorrection::parse(payload)?,
            )),
            1525 => Ok(SBP::MsgSsrGridDefinition(MsgSsrGridDefinition::parse(
                payload,
            )?)),
            1024 => Ok(SBP::MsgNdbEvent(MsgNdbEvent::parse(payload)?)),
            2304 => Ok(SBP::MsgImuRaw(MsgImuRaw::parse(payload)?)),
            2305 => Ok(SBP::MsgImuAux(MsgImuAux::parse(payload)?)),
            2048 => Ok(SBP::MsgUserData(MsgUserData::parse(payload)?)),
            2307 => Ok(SBP::MsgOdometry(MsgOdometry::parse(payload)?)),
            30583 => Ok(SBP::MsgSbasRaw(MsgSbasRaw::parse(payload)?)),
            47 => Ok(SBP::MsgAcqResult(MsgAcqResult::parse(payload)?)),
            31 => Ok(SBP::MsgAcqResultDepC(MsgAcqResultDepC::parse(payload)?)),
            20 => Ok(SBP::MsgAcqResultDepB(MsgAcqResultDepB::parse(payload)?)),
            21 => Ok(SBP::MsgAcqResultDepA(MsgAcqResultDepA::parse(payload)?)),
            46 => Ok(SBP::MsgAcqSvProfile(MsgAcqSvProfile::parse(payload)?)),
            30 => Ok(SBP::MsgAcqSvProfileDep(MsgAcqSvProfileDep::parse(payload)?)),
            161 => Ok(SBP::MsgSettingsSave(MsgSettingsSave::parse(payload)?)),
            160 => Ok(SBP::MsgSettingsWrite(MsgSettingsWrite::parse(payload)?)),
            175 => Ok(SBP::MsgSettingsWriteResp(MsgSettingsWriteResp::parse(
                payload,
            )?)),
            164 => Ok(SBP::MsgSettingsReadReq(MsgSettingsReadReq::parse(payload)?)),
            165 => Ok(SBP::MsgSettingsReadResp(MsgSettingsReadResp::parse(
                payload,
            )?)),
            162 => Ok(SBP::MsgSettingsReadByIndexReq(
                MsgSettingsReadByIndexReq::parse(payload)?,
            )),
            167 => Ok(SBP::MsgSettingsReadByIndexResp(
                MsgSettingsReadByIndexResp::parse(payload)?,
            )),
            166 => Ok(SBP::MsgSettingsReadByIndexDone(
                MsgSettingsReadByIndexDone::parse(payload)?,
            )),
            174 => Ok(SBP::MsgSettingsRegister(MsgSettingsRegister::parse(
                payload,
            )?)),
            431 => Ok(SBP::MsgSettingsRegisterResp(
                MsgSettingsRegisterResp::parse(payload)?,
            )),
            168 => Ok(SBP::MsgFileioReadReq(MsgFileioReadReq::parse(payload)?)),
            163 => Ok(SBP::MsgFileioReadResp(MsgFileioReadResp::parse(payload)?)),
            169 => Ok(SBP::MsgFileioReadDirReq(MsgFileioReadDirReq::parse(
                payload,
            )?)),
            170 => Ok(SBP::MsgFileioReadDirResp(MsgFileioReadDirResp::parse(
                payload,
            )?)),
            172 => Ok(SBP::MsgFileioRemove(MsgFileioRemove::parse(payload)?)),
            173 => Ok(SBP::MsgFileioWriteReq(MsgFileioWriteReq::parse(payload)?)),
            171 => Ok(SBP::MsgFileioWriteResp(MsgFileioWriteResp::parse(payload)?)),
            4097 => Ok(SBP::MsgFileioConfigReq(MsgFileioConfigReq::parse(payload)?)),
            4098 => Ok(SBP::MsgFileioConfigResp(MsgFileioConfigResp::parse(
                payload,
            )?)),
            65280 => Ok(SBP::MsgStartup(MsgStartup::parse(payload)?)),
            65282 => Ok(SBP::MsgDgnssStatus(MsgDgnssStatus::parse(payload)?)),
            65535 => Ok(SBP::MsgHeartbeat(MsgHeartbeat::parse(payload)?)),
            65283 => Ok(SBP::MsgInsStatus(MsgInsStatus::parse(payload)?)),
            65284 => Ok(SBP::MsgCsacTelemetry(MsgCsacTelemetry::parse(payload)?)),
            65285 => Ok(SBP::MsgCsacTelemetryLabels(MsgCsacTelemetryLabels::parse(
                payload,
            )?)),
            32512 => Ok(SBP::MsgLinuxCpuState(MsgLinuxCpuState::parse(payload)?)),
            32513 => Ok(SBP::MsgLinuxMemState(MsgLinuxMemState::parse(payload)?)),
            32514 => Ok(SBP::MsgLinuxSysState(MsgLinuxSysState::parse(payload)?)),
            32515 => Ok(SBP::MsgLinuxProcessSocketCounts(
                MsgLinuxProcessSocketCounts::parse(payload)?,
            )),
            32516 => Ok(SBP::MsgLinuxProcessSocketQueues(
                MsgLinuxProcessSocketQueues::parse(payload)?,
            )),
            32517 => Ok(SBP::MsgLinuxSocketUsage(MsgLinuxSocketUsage::parse(
                payload,
            )?)),
            32518 => Ok(SBP::MsgLinuxProcessFdCount(MsgLinuxProcessFdCount::parse(
                payload,
            )?)),
            32519 => Ok(SBP::MsgLinuxProcessFdSummary(
                MsgLinuxProcessFdSummary::parse(payload)?,
            )),
            257 => Ok(SBP::MsgExtEvent(MsgExtEvent::parse(payload)?)),
            74 => Ok(SBP::MsgObs(MsgObs::parse(payload)?)),
            68 => Ok(SBP::MsgBasePosLLH(MsgBasePosLLH::parse(payload)?)),
            72 => Ok(SBP::MsgBasePosECEF(MsgBasePosECEF::parse(payload)?)),
            129 => Ok(SBP::MsgEphemerisGPSDepE(MsgEphemerisGPSDepE::parse(
                payload,
            )?)),
            134 => Ok(SBP::MsgEphemerisGPSDepF(MsgEphemerisGPSDepF::parse(
                payload,
            )?)),
            138 => Ok(SBP::MsgEphemerisGPS(MsgEphemerisGPS::parse(payload)?)),
            142 => Ok(SBP::MsgEphemerisQzss(MsgEphemerisQzss::parse(payload)?)),
            137 => Ok(SBP::MsgEphemerisBds(MsgEphemerisBds::parse(payload)?)),
            149 => Ok(SBP::MsgEphemerisGalDepA(MsgEphemerisGalDepA::parse(
                payload,
            )?)),
            141 => Ok(SBP::MsgEphemerisGal(MsgEphemerisGal::parse(payload)?)),
            130 => Ok(SBP::MsgEphemerisSbasDepA(MsgEphemerisSbasDepA::parse(
                payload,
            )?)),
            131 => Ok(SBP::MsgEphemerisGloDepA(MsgEphemerisGloDepA::parse(
                payload,
            )?)),
            132 => Ok(SBP::MsgEphemerisSbasDepB(MsgEphemerisSbasDepB::parse(
                payload,
            )?)),
            140 => Ok(SBP::MsgEphemerisSbas(MsgEphemerisSbas::parse(payload)?)),
            133 => Ok(SBP::MsgEphemerisGloDepB(MsgEphemerisGloDepB::parse(
                payload,
            )?)),
            135 => Ok(SBP::MsgEphemerisGloDepC(MsgEphemerisGloDepC::parse(
                payload,
            )?)),
            136 => Ok(SBP::MsgEphemerisGloDepD(MsgEphemerisGloDepD::parse(
                payload,
            )?)),
            139 => Ok(SBP::MsgEphemerisGlo(MsgEphemerisGlo::parse(payload)?)),
            128 => Ok(SBP::MsgEphemerisDepD(MsgEphemerisDepD::parse(payload)?)),
            26 => Ok(SBP::MsgEphemerisDepA(MsgEphemerisDepA::parse(payload)?)),
            70 => Ok(SBP::MsgEphemerisDepB(MsgEphemerisDepB::parse(payload)?)),
            71 => Ok(SBP::MsgEphemerisDepC(MsgEphemerisDepC::parse(payload)?)),
            69 => Ok(SBP::MsgObsDepA(MsgObsDepA::parse(payload)?)),
            67 => Ok(SBP::MsgObsDepB(MsgObsDepB::parse(payload)?)),
            73 => Ok(SBP::MsgObsDepC(MsgObsDepC::parse(payload)?)),
            144 => Ok(SBP::MsgIono(MsgIono::parse(payload)?)),
            145 => Ok(SBP::MsgSvConfigurationGPSDep(
                MsgSvConfigurationGPSDep::parse(payload)?,
            )),
            150 => Ok(SBP::MsgGnssCapb(MsgGnssCapb::parse(payload)?)),
            146 => Ok(SBP::MsgGroupDelayDepA(MsgGroupDelayDepA::parse(payload)?)),
            147 => Ok(SBP::MsgGroupDelayDepB(MsgGroupDelayDepB::parse(payload)?)),
            148 => Ok(SBP::MsgGroupDelay(MsgGroupDelay::parse(payload)?)),
            112 => Ok(SBP::MsgAlmanacGPSDep(MsgAlmanacGPSDep::parse(payload)?)),
            114 => Ok(SBP::MsgAlmanacGPS(MsgAlmanacGPS::parse(payload)?)),
            113 => Ok(SBP::MsgAlmanacGloDep(MsgAlmanacGloDep::parse(payload)?)),
            115 => Ok(SBP::MsgAlmanacGlo(MsgAlmanacGlo::parse(payload)?)),
            117 => Ok(SBP::MsgGloBiases(MsgGloBiases::parse(payload)?)),
            151 => Ok(SBP::MsgSvAzEl(MsgSvAzEl::parse(payload)?)),
            1600 => Ok(SBP::MsgOsr(MsgOsr::parse(payload)?)),
            230 => Ok(SBP::MsgFlashProgram(MsgFlashProgram::parse(payload)?)),
            224 => Ok(SBP::MsgFlashDone(MsgFlashDone::parse(payload)?)),
            231 => Ok(SBP::MsgFlashReadReq(MsgFlashReadReq::parse(payload)?)),
            225 => Ok(SBP::MsgFlashReadResp(MsgFlashReadResp::parse(payload)?)),
            226 => Ok(SBP::MsgFlashErase(MsgFlashErase::parse(payload)?)),
            227 => Ok(SBP::MsgStmFlashLockSector(MsgStmFlashLockSector::parse(
                payload,
            )?)),
            228 => Ok(SBP::MsgStmFlashUnlockSector(
                MsgStmFlashUnlockSector::parse(payload)?,
            )),
            232 => Ok(SBP::MsgStmUniqueIdReq(MsgStmUniqueIdReq::parse(payload)?)),
            229 => Ok(SBP::MsgStmUniqueIdResp(MsgStmUniqueIdResp::parse(payload)?)),
            243 => Ok(SBP::MsgM25FlashWriteStatus(MsgM25FlashWriteStatus::parse(
                payload,
            )?)),
            258 => Ok(SBP::MsgGPSTime(MsgGPSTime::parse(payload)?)),
            259 => Ok(SBP::MsgUtcTime(MsgUtcTime::parse(payload)?)),
            520 => Ok(SBP::MsgDops(MsgDops::parse(payload)?)),
            521 => Ok(SBP::MsgPosECEF(MsgPosECEF::parse(payload)?)),
            532 => Ok(SBP::MsgPosECEFCov(MsgPosECEFCov::parse(payload)?)),
            522 => Ok(SBP::MsgPosLLH(MsgPosLLH::parse(payload)?)),
            529 => Ok(SBP::MsgPosLLHCov(MsgPosLLHCov::parse(payload)?)),
            523 => Ok(SBP::MsgBaselineECEF(MsgBaselineECEF::parse(payload)?)),
            524 => Ok(SBP::MsgBaselineNED(MsgBaselineNED::parse(payload)?)),
            525 => Ok(SBP::MsgVelECEF(MsgVelECEF::parse(payload)?)),
            533 => Ok(SBP::MsgVelECEFCov(MsgVelECEFCov::parse(payload)?)),
            526 => Ok(SBP::MsgVelNED(MsgVelNED::parse(payload)?)),
            530 => Ok(SBP::MsgVelNEDCov(MsgVelNEDCov::parse(payload)?)),
            531 => Ok(SBP::MsgVelBody(MsgVelBody::parse(payload)?)),
            528 => Ok(SBP::MsgAgeCorrections(MsgAgeCorrections::parse(payload)?)),
            256 => Ok(SBP::MsgGPSTimeDepA(MsgGPSTimeDepA::parse(payload)?)),
            518 => Ok(SBP::MsgDopsDepA(MsgDopsDepA::parse(payload)?)),
            512 => Ok(SBP::MsgPosECEFDepA(MsgPosECEFDepA::parse(payload)?)),
            513 => Ok(SBP::MsgPosLLHDepA(MsgPosLLHDepA::parse(payload)?)),
            514 => Ok(SBP::MsgBaselineECEFDepA(MsgBaselineECEFDepA::parse(
                payload,
            )?)),
            515 => Ok(SBP::MsgBaselineNEDDepA(MsgBaselineNEDDepA::parse(payload)?)),
            516 => Ok(SBP::MsgVelECEFDepA(MsgVelECEFDepA::parse(payload)?)),
            517 => Ok(SBP::MsgVelNEDDepA(MsgVelNEDDepA::parse(payload)?)),
            519 => Ok(SBP::MsgBaselineHeadingDepA(MsgBaselineHeadingDepA::parse(
                payload,
            )?)),
            527 => Ok(SBP::MsgBaselineHeading(MsgBaselineHeading::parse(payload)?)),
            544 => Ok(SBP::MsgOrientQuat(MsgOrientQuat::parse(payload)?)),
            545 => Ok(SBP::MsgOrientEuler(MsgOrientEuler::parse(payload)?)),
            546 => Ok(SBP::MsgAngularRate(MsgAngularRate::parse(payload)?)),
            33 => Ok(SBP::MsgTrackingStateDetailedDepA(
                MsgTrackingStateDetailedDepA::parse(payload)?,
            )),
            17 => Ok(SBP::MsgTrackingStateDetailedDep(
                MsgTrackingStateDetailedDep::parse(payload)?,
            )),
            65 => Ok(SBP::MsgTrackingState(MsgTrackingState::parse(payload)?)),
            97 => Ok(SBP::MsgMeasurementState(MsgMeasurementState::parse(
                payload,
            )?)),
            45 => Ok(SBP::MsgTrackingIq(MsgTrackingIq::parse(payload)?)),
            44 => Ok(SBP::MsgTrackingIqDepB(MsgTrackingIqDepB::parse(payload)?)),
            28 => Ok(SBP::MsgTrackingIqDepA(MsgTrackingIqDepA::parse(payload)?)),
            22 => Ok(SBP::MsgTrackingStateDepA(MsgTrackingStateDepA::parse(
                payload,
            )?)),
            19 => Ok(SBP::MsgTrackingStateDepB(MsgTrackingStateDepB::parse(
                payload,
            )?)),
            1025 => Ok(SBP::MsgLog(MsgLog::parse(payload)?)),
            1026 => Ok(SBP::MsgFwd(MsgFwd::parse(payload)?)),
            16 => Ok(SBP::MsgPrintDep(MsgPrintDep::parse(payload)?)),
            179 => Ok(SBP::MsgBootloaderHandshakeReq(
                MsgBootloaderHandshakeReq::parse(payload)?,
            )),
            180 => Ok(SBP::MsgBootloaderHandshakeResp(
                MsgBootloaderHandshakeResp::parse(payload)?,
            )),
            177 => Ok(SBP::MsgBootloaderJumpToApp(MsgBootloaderJumpToApp::parse(
                payload,
            )?)),
            222 => Ok(SBP::MsgNapDeviceDnaReq(MsgNapDeviceDnaReq::parse(payload)?)),
            221 => Ok(SBP::MsgNapDeviceDnaResp(MsgNapDeviceDnaResp::parse(
                payload,
            )?)),
            176 => Ok(SBP::MsgBootloaderHandshakeDepA(
                MsgBootloaderHandshakeDepA::parse(payload)?,
            )),
            105 => Ok(SBP::MsgAlmanac(MsgAlmanac::parse(payload)?)),
            104 => Ok(SBP::MsgSetTime(MsgSetTime::parse(payload)?)),
            182 => Ok(SBP::MsgReset(MsgReset::parse(payload)?)),
            178 => Ok(SBP::MsgResetDep(MsgResetDep::parse(payload)?)),
            192 => Ok(SBP::MsgCwResults(MsgCwResults::parse(payload)?)),
            193 => Ok(SBP::MsgCwStart(MsgCwStart::parse(payload)?)),
            34 => Ok(SBP::MsgResetFilters(MsgResetFilters::parse(payload)?)),
            35 => Ok(SBP::MsgInitBaseDep(MsgInitBaseDep::parse(payload)?)),
            23 => Ok(SBP::MsgThreadState(MsgThreadState::parse(payload)?)),
            29 => Ok(SBP::MsgUartState(MsgUartState::parse(payload)?)),
            24 => Ok(SBP::MsgUartStateDepa(MsgUartStateDepa::parse(payload)?)),
            25 => Ok(SBP::MsgIarState(MsgIarState::parse(payload)?)),
            43 => Ok(SBP::MsgMaskSatellite(MsgMaskSatellite::parse(payload)?)),
            27 => Ok(SBP::MsgMaskSatelliteDep(MsgMaskSatelliteDep::parse(
                payload,
            )?)),
            181 => Ok(SBP::MsgDeviceMonitor(MsgDeviceMonitor::parse(payload)?)),
            184 => Ok(SBP::MsgCommandReq(MsgCommandReq::parse(payload)?)),
            185 => Ok(SBP::MsgCommandResp(MsgCommandResp::parse(payload)?)),
            188 => Ok(SBP::MsgCommandOutput(MsgCommandOutput::parse(payload)?)),
            186 => Ok(SBP::MsgNetworkStateReq(MsgNetworkStateReq::parse(payload)?)),
            187 => Ok(SBP::MsgNetworkStateResp(MsgNetworkStateResp::parse(
                payload,
            )?)),
            189 => Ok(SBP::MsgNetworkBandwidthUsage(
                MsgNetworkBandwidthUsage::parse(payload)?,
            )),
            190 => Ok(SBP::MsgCellModemStatus(MsgCellModemStatus::parse(payload)?)),
            80 => Ok(SBP::MsgSpecanDep(MsgSpecanDep::parse(payload)?)),
            81 => Ok(SBP::MsgSpecan(MsgSpecan::parse(payload)?)),
            191 => Ok(SBP::MsgFrontEndGain(MsgFrontEndGain::parse(payload)?)),
            2306 => Ok(SBP::MsgMagRaw(MsgMagRaw::parse(payload)?)),
            _ => Ok(SBP::Unknown { id }),
        };
        match x {
            Ok(x) => Ok(x),
            Err(_) => Err(::Error::ParseError),
        }
    }
}
