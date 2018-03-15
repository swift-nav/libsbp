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
pub mod user;
pub mod mag;
pub mod ndb;
pub mod ext_events;
pub mod observation;
pub mod gnss;
pub mod piksi;
pub mod ssr;
pub mod acquisition;
pub mod sbas;
pub mod bootload;
pub mod logging;
pub mod file_io;
pub mod vehicle;
pub mod system;
pub mod imu;
pub mod flash;
pub mod orientation;
pub mod tracking;
pub mod navigation;
use self::settings::MsgSettingsSave;
use self::settings::MsgSettingsWrite;
use self::settings::MsgSettingsWriteResp;
use self::settings::MsgSettingsReadReq;
use self::settings::MsgSettingsReadResp;
use self::settings::MsgSettingsReadByIndexReq;
use self::settings::MsgSettingsReadByIndexResp;
use self::settings::MsgSettingsReadByIndexDone;
use self::settings::MsgSettingsRegister;
use self::user::MsgUserData;
use self::mag::MsgMagRaw;
use self::ndb::MsgNdbEvent;
use self::ext_events::MsgExtEvent;
use self::observation::MsgObs;
use self::observation::MsgBasePosLLH;
use self::observation::MsgBasePosECEF;
use self::observation::MsgEphemerisGPSDepE;
use self::observation::MsgEphemerisGPS;
use self::observation::MsgEphemerisSbasDepA;
use self::observation::MsgEphemerisGloDepA;
use self::observation::MsgEphemerisSbas;
use self::observation::MsgEphemerisGloDepB;
use self::observation::MsgEphemerisGloDepC;
use self::observation::MsgEphemerisGlo;
use self::observation::MsgEphemerisDepD;
use self::observation::MsgEphemerisDepA;
use self::observation::MsgEphemerisDepB;
use self::observation::MsgEphemerisDepC;
use self::observation::MsgObsDepA;
use self::observation::MsgObsDepB;
use self::observation::MsgObsDepC;
use self::observation::MsgIono;
use self::observation::MsgSvConfigurationGPS;
use self::observation::MsgGroupDelayDepA;
use self::observation::MsgGroupDelayDepB;
use self::observation::MsgGroupDelay;
use self::observation::MsgAlmanacGPSDep;
use self::observation::MsgAlmanacGPS;
use self::observation::MsgAlmanacGloDep;
use self::observation::MsgAlmanacGlo;
use self::observation::MsgGloBiases;
use self::piksi::MsgAlmanac;
use self::piksi::MsgSetTime;
use self::piksi::MsgReset;
use self::piksi::MsgResetDep;
use self::piksi::MsgCwResults;
use self::piksi::MsgCwStart;
use self::piksi::MsgResetFilters;
use self::piksi::MsgInitBase;
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
use self::piksi::MsgSpecanDep;
use self::piksi::MsgSpecan;
use self::ssr::MsgSsrOrbitClock;
use self::ssr::MsgSsrCodeBiases;
use self::ssr::MsgSsrPhaseBiases;
use self::acquisition::MsgAcqResult;
use self::acquisition::MsgAcqResultDepC;
use self::acquisition::MsgAcqResultDepB;
use self::acquisition::MsgAcqResultDepA;
use self::acquisition::MsgAcqSvProfile;
use self::acquisition::MsgAcqSvProfileDep;
use self::sbas::MsgSbasRaw;
use self::bootload::MsgBootloaderHandshakeReq;
use self::bootload::MsgBootloaderHandshakeResp;
use self::bootload::MsgBootloaderJumpToApp;
use self::bootload::MsgNapDeviceDnaReq;
use self::bootload::MsgNapDeviceDnaResp;
use self::bootload::MsgBootloaderHandshakeDepA;
use self::logging::MsgLog;
use self::logging::MsgFwd;
use self::logging::MsgTweet;
use self::logging::MsgPrintDep;
use self::file_io::MsgFileioReadReq;
use self::file_io::MsgFileioReadResp;
use self::file_io::MsgFileioReadDirReq;
use self::file_io::MsgFileioReadDirResp;
use self::file_io::MsgFileioRemove;
use self::file_io::MsgFileioWriteReq;
use self::file_io::MsgFileioWriteResp;
use self::vehicle::MsgOdometry;
use self::system::MsgStartup;
use self::system::MsgDgnssStatus;
use self::system::MsgHeartbeat;
use self::system::MsgInsStatus;
use self::imu::MsgImuRaw;
use self::imu::MsgImuAux;
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
use self::orientation::MsgBaselineHeading;
use self::orientation::MsgOrientQuat;
use self::orientation::MsgOrientEuler;
use self::orientation::MsgAngularRate;
use self::tracking::MsgTrackingStateDetailedDepA;
use self::tracking::MsgTrackingStateDetailedDep;
use self::tracking::MsgTrackingState;
use self::tracking::MsgTrackingIq;
use self::tracking::MsgTrackingIqDep;
use self::tracking::MsgTrackingStateDepA;
use self::tracking::MsgTrackingStateDepB;
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

#[derive(Debug)]
pub enum SBP {
    Unknown { id: u16 },
    MsgVelNEDDepA( MsgVelNEDDepA ),
    MsgBaselineHeadingDepA( MsgBaselineHeadingDepA ),
    MsgPosECEF( MsgPosECEF ),
    MsgPosECEFCov( MsgPosECEFCov ),
    MsgPosLLH( MsgPosLLH ),
    MsgPosLLHCov( MsgPosLLHCov ),
    MsgBaselineECEF( MsgBaselineECEF ),
    MsgBaselineNED( MsgBaselineNED ),
    MsgVelECEF( MsgVelECEF ),
    MsgVelECEFCov( MsgVelECEFCov ),
    MsgVelNED( MsgVelNED ),
    MsgVelNEDCov( MsgVelNEDCov ),
    MsgVelBody( MsgVelBody ),
    MsgAgeCorrections( MsgAgeCorrections ),
    MsgGPSTimeDepA( MsgGPSTimeDepA ),
    MsgDopsDepA( MsgDopsDepA ),
    MsgPosECEFDepA( MsgPosECEFDepA ),
    MsgPosLLHDepA( MsgPosLLHDepA ),
    MsgBaselineECEFDepA( MsgBaselineECEFDepA ),
    MsgBaselineNEDDepA( MsgBaselineNEDDepA ),
    MsgVelECEFDepA( MsgVelECEFDepA ),
    MsgFlashReadReq( MsgFlashReadReq ),
    MsgFlashReadResp( MsgFlashReadResp ),
    MsgFlashErase( MsgFlashErase ),
    MsgStmFlashLockSector( MsgStmFlashLockSector ),
    MsgStmFlashUnlockSector( MsgStmFlashUnlockSector ),
    MsgStmUniqueIdReq( MsgStmUniqueIdReq ),
    MsgStmUniqueIdResp( MsgStmUniqueIdResp ),
    MsgM25FlashWriteStatus( MsgM25FlashWriteStatus ),
    MsgBaselineHeading( MsgBaselineHeading ),
    MsgOrientQuat( MsgOrientQuat ),
    MsgOrientEuler( MsgOrientEuler ),
    MsgAngularRate( MsgAngularRate ),
    MsgTrackingStateDetailedDepA( MsgTrackingStateDetailedDepA ),
    MsgTrackingStateDetailedDep( MsgTrackingStateDetailedDep ),
    MsgTrackingState( MsgTrackingState ),
    MsgTrackingIq( MsgTrackingIq ),
    MsgTrackingIqDep( MsgTrackingIqDep ),
    MsgTrackingStateDepA( MsgTrackingStateDepA ),
    MsgTrackingStateDepB( MsgTrackingStateDepB ),
    MsgGPSTime( MsgGPSTime ),
    MsgUtcTime( MsgUtcTime ),
    MsgDops( MsgDops ),
    MsgSsrOrbitClock( MsgSsrOrbitClock ),
    MsgSsrCodeBiases( MsgSsrCodeBiases ),
    MsgSsrPhaseBiases( MsgSsrPhaseBiases ),
    MsgAcqResult( MsgAcqResult ),
    MsgAcqResultDepC( MsgAcqResultDepC ),
    MsgAcqResultDepB( MsgAcqResultDepB ),
    MsgAcqResultDepA( MsgAcqResultDepA ),
    MsgAcqSvProfile( MsgAcqSvProfile ),
    MsgAcqSvProfileDep( MsgAcqSvProfileDep ),
    MsgSbasRaw( MsgSbasRaw ),
    MsgBootloaderHandshakeReq( MsgBootloaderHandshakeReq ),
    MsgBootloaderHandshakeResp( MsgBootloaderHandshakeResp ),
    MsgBootloaderJumpToApp( MsgBootloaderJumpToApp ),
    MsgNapDeviceDnaReq( MsgNapDeviceDnaReq ),
    MsgNapDeviceDnaResp( MsgNapDeviceDnaResp ),
    MsgBootloaderHandshakeDepA( MsgBootloaderHandshakeDepA ),
    MsgLog( MsgLog ),
    MsgFwd( MsgFwd ),
    MsgTweet( MsgTweet ),
    MsgPrintDep( MsgPrintDep ),
    MsgFileioReadReq( MsgFileioReadReq ),
    MsgFileioReadResp( MsgFileioReadResp ),
    MsgFileioReadDirReq( MsgFileioReadDirReq ),
    MsgFileioReadDirResp( MsgFileioReadDirResp ),
    MsgFileioRemove( MsgFileioRemove ),
    MsgFileioWriteReq( MsgFileioWriteReq ),
    MsgFileioWriteResp( MsgFileioWriteResp ),
    MsgOdometry( MsgOdometry ),
    MsgStartup( MsgStartup ),
    MsgDgnssStatus( MsgDgnssStatus ),
    MsgHeartbeat( MsgHeartbeat ),
    MsgInsStatus( MsgInsStatus ),
    MsgImuRaw( MsgImuRaw ),
    MsgImuAux( MsgImuAux ),
    MsgFlashProgram( MsgFlashProgram ),
    MsgFlashDone( MsgFlashDone ),
    MsgGroupDelayDepA( MsgGroupDelayDepA ),
    MsgGroupDelayDepB( MsgGroupDelayDepB ),
    MsgGroupDelay( MsgGroupDelay ),
    MsgAlmanacGPSDep( MsgAlmanacGPSDep ),
    MsgAlmanacGPS( MsgAlmanacGPS ),
    MsgAlmanacGloDep( MsgAlmanacGloDep ),
    MsgAlmanacGlo( MsgAlmanacGlo ),
    MsgGloBiases( MsgGloBiases ),
    MsgAlmanac( MsgAlmanac ),
    MsgSetTime( MsgSetTime ),
    MsgReset( MsgReset ),
    MsgResetDep( MsgResetDep ),
    MsgCwResults( MsgCwResults ),
    MsgCwStart( MsgCwStart ),
    MsgResetFilters( MsgResetFilters ),
    MsgInitBase( MsgInitBase ),
    MsgThreadState( MsgThreadState ),
    MsgUartState( MsgUartState ),
    MsgSpecan( MsgSpecan ),
    MsgEphemerisGlo( MsgEphemerisGlo ),
    MsgEphemerisDepD( MsgEphemerisDepD ),
    MsgEphemerisDepA( MsgEphemerisDepA ),
    MsgEphemerisDepB( MsgEphemerisDepB ),
    MsgEphemerisDepC( MsgEphemerisDepC ),
    MsgObsDepA( MsgObsDepA ),
    MsgObsDepB( MsgObsDepB ),
    MsgObsDepC( MsgObsDepC ),
    MsgIono( MsgIono ),
    MsgSvConfigurationGPS( MsgSvConfigurationGPS ),
    MsgMagRaw( MsgMagRaw ),
    MsgNdbEvent( MsgNdbEvent ),
    MsgExtEvent( MsgExtEvent ),
    MsgObs( MsgObs ),
    MsgBasePosLLH( MsgBasePosLLH ),
    MsgBasePosECEF( MsgBasePosECEF ),
    MsgEphemerisGPSDepE( MsgEphemerisGPSDepE ),
    MsgEphemerisGPS( MsgEphemerisGPS ),
    MsgEphemerisSbasDepA( MsgEphemerisSbasDepA ),
    MsgEphemerisGloDepA( MsgEphemerisGloDepA ),
    MsgEphemerisSbas( MsgEphemerisSbas ),
    MsgEphemerisGloDepB( MsgEphemerisGloDepB ),
    MsgEphemerisGloDepC( MsgEphemerisGloDepC ),
    MsgSettingsSave( MsgSettingsSave ),
    MsgSettingsWrite( MsgSettingsWrite ),
    MsgSettingsWriteResp( MsgSettingsWriteResp ),
    MsgSettingsReadReq( MsgSettingsReadReq ),
    MsgSettingsReadResp( MsgSettingsReadResp ),
    MsgSettingsReadByIndexReq( MsgSettingsReadByIndexReq ),
    MsgSettingsReadByIndexResp( MsgSettingsReadByIndexResp ),
    MsgSettingsReadByIndexDone( MsgSettingsReadByIndexDone ),
    MsgSettingsRegister( MsgSettingsRegister ),
    MsgUserData( MsgUserData ),
    MsgNetworkBandwidthUsage( MsgNetworkBandwidthUsage ),
    MsgSpecanDep( MsgSpecanDep ),
    MsgCommandReq( MsgCommandReq ),
    MsgCommandResp( MsgCommandResp ),
    MsgCommandOutput( MsgCommandOutput ),
    MsgNetworkStateReq( MsgNetworkStateReq ),
    MsgNetworkStateResp( MsgNetworkStateResp ),
    MsgUartStateDepa( MsgUartStateDepa ),
    MsgIarState( MsgIarState ),
    MsgMaskSatellite( MsgMaskSatellite ),
    MsgMaskSatelliteDep( MsgMaskSatelliteDep ),
    MsgDeviceMonitor( MsgDeviceMonitor ),
}

impl SBP {
    pub fn parse(id: u16, payload: &mut &[u8]) -> Result<SBP, ::Error> {
        let x: Result<SBP, ::Error> = match id {
            517 => Ok(SBP::MsgVelNEDDepA( MsgVelNEDDepA::parse(payload)? )),
            519 => Ok(SBP::MsgBaselineHeadingDepA( MsgBaselineHeadingDepA::parse(payload)? )),
            521 => Ok(SBP::MsgPosECEF( MsgPosECEF::parse(payload)? )),
            532 => Ok(SBP::MsgPosECEFCov( MsgPosECEFCov::parse(payload)? )),
            522 => Ok(SBP::MsgPosLLH( MsgPosLLH::parse(payload)? )),
            529 => Ok(SBP::MsgPosLLHCov( MsgPosLLHCov::parse(payload)? )),
            523 => Ok(SBP::MsgBaselineECEF( MsgBaselineECEF::parse(payload)? )),
            524 => Ok(SBP::MsgBaselineNED( MsgBaselineNED::parse(payload)? )),
            525 => Ok(SBP::MsgVelECEF( MsgVelECEF::parse(payload)? )),
            533 => Ok(SBP::MsgVelECEFCov( MsgVelECEFCov::parse(payload)? )),
            526 => Ok(SBP::MsgVelNED( MsgVelNED::parse(payload)? )),
            530 => Ok(SBP::MsgVelNEDCov( MsgVelNEDCov::parse(payload)? )),
            531 => Ok(SBP::MsgVelBody( MsgVelBody::parse(payload)? )),
            528 => Ok(SBP::MsgAgeCorrections( MsgAgeCorrections::parse(payload)? )),
            256 => Ok(SBP::MsgGPSTimeDepA( MsgGPSTimeDepA::parse(payload)? )),
            518 => Ok(SBP::MsgDopsDepA( MsgDopsDepA::parse(payload)? )),
            512 => Ok(SBP::MsgPosECEFDepA( MsgPosECEFDepA::parse(payload)? )),
            513 => Ok(SBP::MsgPosLLHDepA( MsgPosLLHDepA::parse(payload)? )),
            514 => Ok(SBP::MsgBaselineECEFDepA( MsgBaselineECEFDepA::parse(payload)? )),
            515 => Ok(SBP::MsgBaselineNEDDepA( MsgBaselineNEDDepA::parse(payload)? )),
            516 => Ok(SBP::MsgVelECEFDepA( MsgVelECEFDepA::parse(payload)? )),
            231 => Ok(SBP::MsgFlashReadReq( MsgFlashReadReq::parse(payload)? )),
            225 => Ok(SBP::MsgFlashReadResp( MsgFlashReadResp::parse(payload)? )),
            226 => Ok(SBP::MsgFlashErase( MsgFlashErase::parse(payload)? )),
            227 => Ok(SBP::MsgStmFlashLockSector( MsgStmFlashLockSector::parse(payload)? )),
            228 => Ok(SBP::MsgStmFlashUnlockSector( MsgStmFlashUnlockSector::parse(payload)? )),
            232 => Ok(SBP::MsgStmUniqueIdReq( MsgStmUniqueIdReq::parse(payload)? )),
            229 => Ok(SBP::MsgStmUniqueIdResp( MsgStmUniqueIdResp::parse(payload)? )),
            243 => Ok(SBP::MsgM25FlashWriteStatus( MsgM25FlashWriteStatus::parse(payload)? )),
            527 => Ok(SBP::MsgBaselineHeading( MsgBaselineHeading::parse(payload)? )),
            544 => Ok(SBP::MsgOrientQuat( MsgOrientQuat::parse(payload)? )),
            545 => Ok(SBP::MsgOrientEuler( MsgOrientEuler::parse(payload)? )),
            546 => Ok(SBP::MsgAngularRate( MsgAngularRate::parse(payload)? )),
            33 => Ok(SBP::MsgTrackingStateDetailedDepA( MsgTrackingStateDetailedDepA::parse(payload)? )),
            17 => Ok(SBP::MsgTrackingStateDetailedDep( MsgTrackingStateDetailedDep::parse(payload)? )),
            65 => Ok(SBP::MsgTrackingState( MsgTrackingState::parse(payload)? )),
            44 => Ok(SBP::MsgTrackingIq( MsgTrackingIq::parse(payload)? )),
            28 => Ok(SBP::MsgTrackingIqDep( MsgTrackingIqDep::parse(payload)? )),
            22 => Ok(SBP::MsgTrackingStateDepA( MsgTrackingStateDepA::parse(payload)? )),
            19 => Ok(SBP::MsgTrackingStateDepB( MsgTrackingStateDepB::parse(payload)? )),
            258 => Ok(SBP::MsgGPSTime( MsgGPSTime::parse(payload)? )),
            259 => Ok(SBP::MsgUtcTime( MsgUtcTime::parse(payload)? )),
            520 => Ok(SBP::MsgDops( MsgDops::parse(payload)? )),
            1500 => Ok(SBP::MsgSsrOrbitClock( MsgSsrOrbitClock::parse(payload)? )),
            1505 => Ok(SBP::MsgSsrCodeBiases( MsgSsrCodeBiases::parse(payload)? )),
            1510 => Ok(SBP::MsgSsrPhaseBiases( MsgSsrPhaseBiases::parse(payload)? )),
            47 => Ok(SBP::MsgAcqResult( MsgAcqResult::parse(payload)? )),
            31 => Ok(SBP::MsgAcqResultDepC( MsgAcqResultDepC::parse(payload)? )),
            20 => Ok(SBP::MsgAcqResultDepB( MsgAcqResultDepB::parse(payload)? )),
            21 => Ok(SBP::MsgAcqResultDepA( MsgAcqResultDepA::parse(payload)? )),
            46 => Ok(SBP::MsgAcqSvProfile( MsgAcqSvProfile::parse(payload)? )),
            30 => Ok(SBP::MsgAcqSvProfileDep( MsgAcqSvProfileDep::parse(payload)? )),
            30583 => Ok(SBP::MsgSbasRaw( MsgSbasRaw::parse(payload)? )),
            179 => Ok(SBP::MsgBootloaderHandshakeReq( MsgBootloaderHandshakeReq::parse(payload)? )),
            180 => Ok(SBP::MsgBootloaderHandshakeResp( MsgBootloaderHandshakeResp::parse(payload)? )),
            177 => Ok(SBP::MsgBootloaderJumpToApp( MsgBootloaderJumpToApp::parse(payload)? )),
            222 => Ok(SBP::MsgNapDeviceDnaReq( MsgNapDeviceDnaReq::parse(payload)? )),
            221 => Ok(SBP::MsgNapDeviceDnaResp( MsgNapDeviceDnaResp::parse(payload)? )),
            176 => Ok(SBP::MsgBootloaderHandshakeDepA( MsgBootloaderHandshakeDepA::parse(payload)? )),
            1025 => Ok(SBP::MsgLog( MsgLog::parse(payload)? )),
            1026 => Ok(SBP::MsgFwd( MsgFwd::parse(payload)? )),
            18 => Ok(SBP::MsgTweet( MsgTweet::parse(payload)? )),
            16 => Ok(SBP::MsgPrintDep( MsgPrintDep::parse(payload)? )),
            168 => Ok(SBP::MsgFileioReadReq( MsgFileioReadReq::parse(payload)? )),
            163 => Ok(SBP::MsgFileioReadResp( MsgFileioReadResp::parse(payload)? )),
            169 => Ok(SBP::MsgFileioReadDirReq( MsgFileioReadDirReq::parse(payload)? )),
            170 => Ok(SBP::MsgFileioReadDirResp( MsgFileioReadDirResp::parse(payload)? )),
            172 => Ok(SBP::MsgFileioRemove( MsgFileioRemove::parse(payload)? )),
            173 => Ok(SBP::MsgFileioWriteReq( MsgFileioWriteReq::parse(payload)? )),
            171 => Ok(SBP::MsgFileioWriteResp( MsgFileioWriteResp::parse(payload)? )),
            2307 => Ok(SBP::MsgOdometry( MsgOdometry::parse(payload)? )),
            65280 => Ok(SBP::MsgStartup( MsgStartup::parse(payload)? )),
            65282 => Ok(SBP::MsgDgnssStatus( MsgDgnssStatus::parse(payload)? )),
            65535 => Ok(SBP::MsgHeartbeat( MsgHeartbeat::parse(payload)? )),
            65283 => Ok(SBP::MsgInsStatus( MsgInsStatus::parse(payload)? )),
            2304 => Ok(SBP::MsgImuRaw( MsgImuRaw::parse(payload)? )),
            2305 => Ok(SBP::MsgImuAux( MsgImuAux::parse(payload)? )),
            230 => Ok(SBP::MsgFlashProgram( MsgFlashProgram::parse(payload)? )),
            224 => Ok(SBP::MsgFlashDone( MsgFlashDone::parse(payload)? )),
            146 => Ok(SBP::MsgGroupDelayDepA( MsgGroupDelayDepA::parse(payload)? )),
            147 => Ok(SBP::MsgGroupDelayDepB( MsgGroupDelayDepB::parse(payload)? )),
            148 => Ok(SBP::MsgGroupDelay( MsgGroupDelay::parse(payload)? )),
            112 => Ok(SBP::MsgAlmanacGPSDep( MsgAlmanacGPSDep::parse(payload)? )),
            114 => Ok(SBP::MsgAlmanacGPS( MsgAlmanacGPS::parse(payload)? )),
            113 => Ok(SBP::MsgAlmanacGloDep( MsgAlmanacGloDep::parse(payload)? )),
            115 => Ok(SBP::MsgAlmanacGlo( MsgAlmanacGlo::parse(payload)? )),
            117 => Ok(SBP::MsgGloBiases( MsgGloBiases::parse(payload)? )),
            105 => Ok(SBP::MsgAlmanac( MsgAlmanac::parse(payload)? )),
            104 => Ok(SBP::MsgSetTime( MsgSetTime::parse(payload)? )),
            182 => Ok(SBP::MsgReset( MsgReset::parse(payload)? )),
            178 => Ok(SBP::MsgResetDep( MsgResetDep::parse(payload)? )),
            192 => Ok(SBP::MsgCwResults( MsgCwResults::parse(payload)? )),
            193 => Ok(SBP::MsgCwStart( MsgCwStart::parse(payload)? )),
            34 => Ok(SBP::MsgResetFilters( MsgResetFilters::parse(payload)? )),
            35 => Ok(SBP::MsgInitBase( MsgInitBase::parse(payload)? )),
            23 => Ok(SBP::MsgThreadState( MsgThreadState::parse(payload)? )),
            29 => Ok(SBP::MsgUartState( MsgUartState::parse(payload)? )),
            81 => Ok(SBP::MsgSpecan( MsgSpecan::parse(payload)? )),
            136 => Ok(SBP::MsgEphemerisGlo( MsgEphemerisGlo::parse(payload)? )),
            128 => Ok(SBP::MsgEphemerisDepD( MsgEphemerisDepD::parse(payload)? )),
            26 => Ok(SBP::MsgEphemerisDepA( MsgEphemerisDepA::parse(payload)? )),
            70 => Ok(SBP::MsgEphemerisDepB( MsgEphemerisDepB::parse(payload)? )),
            71 => Ok(SBP::MsgEphemerisDepC( MsgEphemerisDepC::parse(payload)? )),
            69 => Ok(SBP::MsgObsDepA( MsgObsDepA::parse(payload)? )),
            67 => Ok(SBP::MsgObsDepB( MsgObsDepB::parse(payload)? )),
            73 => Ok(SBP::MsgObsDepC( MsgObsDepC::parse(payload)? )),
            144 => Ok(SBP::MsgIono( MsgIono::parse(payload)? )),
            145 => Ok(SBP::MsgSvConfigurationGPS( MsgSvConfigurationGPS::parse(payload)? )),
            2306 => Ok(SBP::MsgMagRaw( MsgMagRaw::parse(payload)? )),
            1024 => Ok(SBP::MsgNdbEvent( MsgNdbEvent::parse(payload)? )),
            257 => Ok(SBP::MsgExtEvent( MsgExtEvent::parse(payload)? )),
            74 => Ok(SBP::MsgObs( MsgObs::parse(payload)? )),
            68 => Ok(SBP::MsgBasePosLLH( MsgBasePosLLH::parse(payload)? )),
            72 => Ok(SBP::MsgBasePosECEF( MsgBasePosECEF::parse(payload)? )),
            129 => Ok(SBP::MsgEphemerisGPSDepE( MsgEphemerisGPSDepE::parse(payload)? )),
            134 => Ok(SBP::MsgEphemerisGPS( MsgEphemerisGPS::parse(payload)? )),
            130 => Ok(SBP::MsgEphemerisSbasDepA( MsgEphemerisSbasDepA::parse(payload)? )),
            131 => Ok(SBP::MsgEphemerisGloDepA( MsgEphemerisGloDepA::parse(payload)? )),
            132 => Ok(SBP::MsgEphemerisSbas( MsgEphemerisSbas::parse(payload)? )),
            133 => Ok(SBP::MsgEphemerisGloDepB( MsgEphemerisGloDepB::parse(payload)? )),
            135 => Ok(SBP::MsgEphemerisGloDepC( MsgEphemerisGloDepC::parse(payload)? )),
            161 => Ok(SBP::MsgSettingsSave( MsgSettingsSave::parse(payload)? )),
            160 => Ok(SBP::MsgSettingsWrite( MsgSettingsWrite::parse(payload)? )),
            175 => Ok(SBP::MsgSettingsWriteResp( MsgSettingsWriteResp::parse(payload)? )),
            164 => Ok(SBP::MsgSettingsReadReq( MsgSettingsReadReq::parse(payload)? )),
            165 => Ok(SBP::MsgSettingsReadResp( MsgSettingsReadResp::parse(payload)? )),
            162 => Ok(SBP::MsgSettingsReadByIndexReq( MsgSettingsReadByIndexReq::parse(payload)? )),
            167 => Ok(SBP::MsgSettingsReadByIndexResp( MsgSettingsReadByIndexResp::parse(payload)? )),
            166 => Ok(SBP::MsgSettingsReadByIndexDone( MsgSettingsReadByIndexDone::parse(payload)? )),
            174 => Ok(SBP::MsgSettingsRegister( MsgSettingsRegister::parse(payload)? )),
            2048 => Ok(SBP::MsgUserData( MsgUserData::parse(payload)? )),
            189 => Ok(SBP::MsgNetworkBandwidthUsage( MsgNetworkBandwidthUsage::parse(payload)? )),
            80 => Ok(SBP::MsgSpecanDep( MsgSpecanDep::parse(payload)? )),
            184 => Ok(SBP::MsgCommandReq( MsgCommandReq::parse(payload)? )),
            185 => Ok(SBP::MsgCommandResp( MsgCommandResp::parse(payload)? )),
            188 => Ok(SBP::MsgCommandOutput( MsgCommandOutput::parse(payload)? )),
            186 => Ok(SBP::MsgNetworkStateReq( MsgNetworkStateReq::parse(payload)? )),
            187 => Ok(SBP::MsgNetworkStateResp( MsgNetworkStateResp::parse(payload)? )),
            24 => Ok(SBP::MsgUartStateDepa( MsgUartStateDepa::parse(payload)? )),
            25 => Ok(SBP::MsgIarState( MsgIarState::parse(payload)? )),
            43 => Ok(SBP::MsgMaskSatellite( MsgMaskSatellite::parse(payload)? )),
            27 => Ok(SBP::MsgMaskSatelliteDep( MsgMaskSatelliteDep::parse(payload)? )),
            181 => Ok(SBP::MsgDeviceMonitor( MsgDeviceMonitor::parse(payload)? )),
            _ => Ok(SBP::Unknown {id})
        };
        match x {
            Ok(x) => Ok(x),
            Err(_) => Err(::Error::ParseError),
        }
    }
}