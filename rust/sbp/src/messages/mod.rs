// Copyright (C) 2015-2021 Swift Navigation Inc.
// Contact: https://support.swiftnav.com
//
// This source is subject to the license found in the file 'LICENSE' which must
// be be distributed together with this source. All other rights reserved.
//
// THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
// EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
// WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
//! SBP message definitions.
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
use self::navigation::MsgVelCog;
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

mod lib {
    //! Common imports so we can just `use super::lib::*` in all the message files

    pub use std::convert::{TryFrom, TryInto};

    pub use crate::sbp_string::{
        DoubleNullTerminated, Multipart, NullTerminated, SbpString, Unterminated,
    };
    #[cfg(feature = "swiftnav")]
    pub use crate::time;
    pub use crate::wire_format::{PayloadParseError, WireFormat};

    pub use super::{ConcreteMessage, Sbp, SbpMessage, TryFromSbpError};

    pub use bytes::{Buf, BufMut};
}

use lib::*;

/// Common functionality available to all SBP messages.
pub trait SbpMessage: WireFormat + Clone + Sized {
    /// Get the message name.
    fn message_name(&self) -> &'static str;
    /// Get the message type.
    fn message_type(&self) -> u16;
    /// Get the sender_id if it is set.
    fn sender_id(&self) -> Option<u16>;
    /// Set the sender id.
    fn set_sender_id(&mut self, new_id: u16);
    /// Number of bytes this message will take on the wire.
    fn encoded_len(&self) -> usize;
    /// Get the GPS time associated with the message.
    #[cfg(feature = "swiftnav")]
    fn gps_time(&self) -> Option<Result<crate::time::MessageTime, crate::time::GpsTimeError>> {
        None
    }
}

/// Implemented by messages who's message name and type are known at compile time.
/// This is everything that implements [SbpMessage] except for [Sbp].
pub trait ConcreteMessage: SbpMessage + TryFrom<Sbp, Error = TryFromSbpError> {
    /// The message type.
    const MESSAGE_TYPE: u16;
    /// The message name.
    const MESSAGE_NAME: &'static str;
}

/// The error returned when using [TryFrom] to convert [Sbp] to the wrong message type.
#[derive(Debug, Clone)]
pub struct TryFromSbpError;

impl std::fmt::Display for TryFromSbpError {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        write!(f, "invalid message type for conversion")
    }
}

impl std::error::Error for TryFromSbpError {}

/// Represents any SBP message.
#[cfg_attr(feature = "serde", derive(serde::Serialize), serde(untagged))]
#[derive(Debug, Clone)]
#[non_exhaustive]
pub enum Sbp {
    /// Deprecated
    MsgPrintDep(MsgPrintDep),
    /// Deprecated
    MsgTrackingStateDetailedDep(MsgTrackingStateDetailedDep),
    /// Deprecated
    MsgTrackingStateDepB(MsgTrackingStateDepB),
    /// Deprecated
    MsgAcqResultDepB(MsgAcqResultDepB),
    /// Deprecated
    MsgAcqResultDepA(MsgAcqResultDepA),
    /// Deprecated
    MsgTrackingStateDepA(MsgTrackingStateDepA),
    /// State of an RTOS thread
    MsgThreadState(MsgThreadState),
    /// Deprecated
    MsgUartStateDepa(MsgUartStateDepa),
    /// State of the Integer Ambiguity Resolution (IAR) process
    MsgIarState(MsgIarState),
    /// Deprecated
    MsgEphemerisDepA(MsgEphemerisDepA),
    /// Deprecated
    MsgMaskSatelliteDep(MsgMaskSatelliteDep),
    /// Deprecated
    MsgTrackingIqDepA(MsgTrackingIqDepA),
    /// State of the UART channels
    MsgUartState(MsgUartState),
    /// Deprecated
    MsgAcqSvProfileDep(MsgAcqSvProfileDep),
    /// Deprecated
    MsgAcqResultDepC(MsgAcqResultDepC),
    /// Detailed signal tracking channel states. DEPRECATED
    MsgTrackingStateDetailedDepA(MsgTrackingStateDetailedDepA),
    /// Reset IAR filters (host => Piksi)
    MsgResetFilters(MsgResetFilters),
    /// Deprecated
    MsgInitBaseDep(MsgInitBaseDep),
    /// Mask a satellite from use in Piksi subsystems
    MsgMaskSatellite(MsgMaskSatellite),
    /// Tracking channel correlations
    MsgTrackingIqDepB(MsgTrackingIqDepB),
    /// Tracking channel correlations
    MsgTrackingIq(MsgTrackingIq),
    /// Acquisition perfomance measurement and debug
    MsgAcqSvProfile(MsgAcqSvProfile),
    /// Satellite acquisition result
    MsgAcqResult(MsgAcqResult),
    /// Signal tracking channel states
    MsgTrackingState(MsgTrackingState),
    /// Deprecated
    MsgObsDepB(MsgObsDepB),
    /// Base station position
    MsgBasePosLlh(MsgBasePosLlh),
    /// Deprecated
    MsgObsDepA(MsgObsDepA),
    /// Deprecated
    MsgEphemerisDepB(MsgEphemerisDepB),
    /// Satellite broadcast ephemeris
    MsgEphemerisDepC(MsgEphemerisDepC),
    /// Base station position in ECEF
    MsgBasePosEcef(MsgBasePosEcef),
    /// Deprecated
    MsgObsDepC(MsgObsDepC),
    /// GPS satellite observations
    MsgObs(MsgObs),
    /// Deprecated
    MsgSpecanDep(MsgSpecanDep),
    /// Spectrum analyzer
    MsgSpecan(MsgSpecan),
    /// Measurement Engine signal tracking channel states
    MsgMeasurementState(MsgMeasurementState),
    /// Send GPS time from host (host => Piksi)
    MsgSetTime(MsgSetTime),
    /// Legacy message to load satellite almanac (host => Piksi)
    MsgAlmanac(MsgAlmanac),
    /// Satellite broadcast ephemeris for GPS
    MsgAlmanacGpsDep(MsgAlmanacGpsDep),
    /// Satellite broadcast ephemeris for GLO
    MsgAlmanacGloDep(MsgAlmanacGloDep),
    /// Satellite broadcast ephemeris for GPS
    MsgAlmanacGps(MsgAlmanacGps),
    /// Satellite broadcast ephemeris for GLO
    MsgAlmanacGlo(MsgAlmanacGlo),
    /// GLONASS L1/L2 Code-Phase biases
    MsgGloBiases(MsgGloBiases),
    /// Satellite broadcast ephemeris
    MsgEphemerisDepD(MsgEphemerisDepD),
    /// Satellite broadcast ephemeris for GPS
    MsgEphemerisGpsDepE(MsgEphemerisGpsDepE),
    /// Satellite broadcast ephemeris for SBAS
    MsgEphemerisSbasDepA(MsgEphemerisSbasDepA),
    /// Satellite broadcast ephemeris for GLO
    MsgEphemerisGloDepA(MsgEphemerisGloDepA),
    /// Deprecated
    MsgEphemerisSbasDepB(MsgEphemerisSbasDepB),
    /// Satellite broadcast ephemeris for GLO
    MsgEphemerisGloDepB(MsgEphemerisGloDepB),
    /// Deprecated
    MsgEphemerisGpsDepF(MsgEphemerisGpsDepF),
    /// Satellite broadcast ephemeris for GLO
    MsgEphemerisGloDepC(MsgEphemerisGloDepC),
    /// Deprecated
    MsgEphemerisGloDepD(MsgEphemerisGloDepD),
    /// Satellite broadcast ephemeris for BDS
    MsgEphemerisBds(MsgEphemerisBds),
    /// Satellite broadcast ephemeris for GPS
    MsgEphemerisGps(MsgEphemerisGps),
    /// Satellite broadcast ephemeris for GLO
    MsgEphemerisGlo(MsgEphemerisGlo),
    /// Satellite broadcast ephemeris for SBAS
    MsgEphemerisSbas(MsgEphemerisSbas),
    /// Satellite broadcast ephemeris for Galileo
    MsgEphemerisGal(MsgEphemerisGal),
    /// Satellite broadcast ephemeris for QZSS
    MsgEphemerisQzss(MsgEphemerisQzss),
    /// Iono corrections
    MsgIono(MsgIono),
    /// L2C capability mask
    MsgSvConfigurationGpsDep(MsgSvConfigurationGpsDep),
    /// Group Delay
    MsgGroupDelayDepA(MsgGroupDelayDepA),
    /// Group Delay
    MsgGroupDelayDepB(MsgGroupDelayDepB),
    /// Group Delay
    MsgGroupDelay(MsgGroupDelay),
    /// Deprecated
    MsgEphemerisGalDepA(MsgEphemerisGalDepA),
    /// GNSS capabilities
    MsgGnssCapb(MsgGnssCapb),
    /// Satellite azimuths and elevations
    MsgSvAzEl(MsgSvAzEl),
    /// Write device configuration settings (host => device)
    MsgSettingsWrite(MsgSettingsWrite),
    /// Save settings to flash (host => device)
    MsgSettingsSave(MsgSettingsSave),
    /// Read setting by direct index (host => device)
    MsgSettingsReadByIndexReq(MsgSettingsReadByIndexReq),
    /// File read from the file system (host <= device)
    MsgFileioReadResp(MsgFileioReadResp),
    /// Read device configuration settings (host => device)
    MsgSettingsReadReq(MsgSettingsReadReq),
    /// Read device configuration settings (host <= device)
    MsgSettingsReadResp(MsgSettingsReadResp),
    /// Finished reading settings (host <= device)
    MsgSettingsReadByIndexDone(MsgSettingsReadByIndexDone),
    /// Read setting by direct index (host <= device)
    MsgSettingsReadByIndexResp(MsgSettingsReadByIndexResp),
    /// Read file from the file system (host => device)
    MsgFileioReadReq(MsgFileioReadReq),
    /// List files in a directory (host => device)
    MsgFileioReadDirReq(MsgFileioReadDirReq),
    /// Files listed in a directory (host <= device)
    MsgFileioReadDirResp(MsgFileioReadDirResp),
    /// File written to (host <= device)
    MsgFileioWriteResp(MsgFileioWriteResp),
    /// Delete a file from the file system (host => device)
    MsgFileioRemove(MsgFileioRemove),
    /// Write to file (host => device)
    MsgFileioWriteReq(MsgFileioWriteReq),
    /// Register setting and default value (device => host)
    MsgSettingsRegister(MsgSettingsRegister),
    /// Acknowledgement with status of MSG_SETTINGS_WRITE
    MsgSettingsWriteResp(MsgSettingsWriteResp),
    /// Deprecated
    MsgBootloaderHandshakeDepA(MsgBootloaderHandshakeDepA),
    /// Bootloader jump to application (host => device)
    MsgBootloaderJumpToApp(MsgBootloaderJumpToApp),
    /// Reset the device (host => Piksi)
    MsgResetDep(MsgResetDep),
    /// Bootloading handshake request (host => device)
    MsgBootloaderHandshakeReq(MsgBootloaderHandshakeReq),
    /// Bootloading handshake response (host <= device)
    MsgBootloaderHandshakeResp(MsgBootloaderHandshakeResp),
    /// Device temperature and voltage levels
    MsgDeviceMonitor(MsgDeviceMonitor),
    /// Reset the device (host => Piksi)
    MsgReset(MsgReset),
    /// Execute a command (host => device)
    MsgCommandReq(MsgCommandReq),
    /// Exit code from executed command (device => host)
    MsgCommandResp(MsgCommandResp),
    /// Request state of Piksi network interfaces
    MsgNetworkStateReq(MsgNetworkStateReq),
    /// State of network interface
    MsgNetworkStateResp(MsgNetworkStateResp),
    /// Command output
    MsgCommandOutput(MsgCommandOutput),
    /// Bandwidth usage reporting message
    MsgNetworkBandwidthUsage(MsgNetworkBandwidthUsage),
    /// Cell modem information update message
    MsgCellModemStatus(MsgCellModemStatus),
    /// RF AGC status
    MsgFrontEndGain(MsgFrontEndGain),
    /// Legacy message for CW interference channel (Piksi => host)
    MsgCwResults(MsgCwResults),
    /// Legacy message for CW interference channel (host => Piksi)
    MsgCwStart(MsgCwStart),
    /// Read FPGA device ID over UART response (host <= device)
    MsgNapDeviceDnaResp(MsgNapDeviceDnaResp),
    /// Read FPGA device ID over UART request (host => device)
    MsgNapDeviceDnaReq(MsgNapDeviceDnaReq),
    /// Flash response message (host <= device)
    MsgFlashDone(MsgFlashDone),
    /// Read STM or M25 flash address response (host <= device)
    MsgFlashReadResp(MsgFlashReadResp),
    /// Erase sector of device flash memory (host => device)
    MsgFlashErase(MsgFlashErase),
    /// Lock sector of STM flash memory (host => device)
    MsgStmFlashLockSector(MsgStmFlashLockSector),
    /// Unlock sector of STM flash memory (host => device)
    MsgStmFlashUnlockSector(MsgStmFlashUnlockSector),
    /// Read device's hard-coded unique ID response (host <= device)
    MsgStmUniqueIdResp(MsgStmUniqueIdResp),
    /// Program flash addresses
    MsgFlashProgram(MsgFlashProgram),
    /// Read STM or M25 flash address request (host => device)
    MsgFlashReadReq(MsgFlashReadReq),
    /// Read device's hard-coded unique ID request (host => device)
    MsgStmUniqueIdReq(MsgStmUniqueIdReq),
    /// Write M25 flash status register (host => device)
    MsgM25FlashWriteStatus(MsgM25FlashWriteStatus),
    /// GPS Time (v1.0)
    MsgGpsTimeDepA(MsgGpsTimeDepA),
    /// Reports timestamped external pin event
    MsgExtEvent(MsgExtEvent),
    /// GPS Time
    MsgGpsTime(MsgGpsTime),
    /// UTC Time
    MsgUtcTime(MsgUtcTime),
    /// GPS Time
    MsgGpsTimeGnss(MsgGpsTimeGnss),
    /// UTC Time
    MsgUtcTimeGnss(MsgUtcTimeGnss),
    /// Register setting and default value (device <= host)
    MsgSettingsRegisterResp(MsgSettingsRegisterResp),
    /// Single-point position in ECEF
    MsgPosEcefDepA(MsgPosEcefDepA),
    /// Geodetic Position
    MsgPosLlhDepA(MsgPosLlhDepA),
    /// Baseline Position in ECEF
    MsgBaselineEcefDepA(MsgBaselineEcefDepA),
    /// Baseline in NED
    MsgBaselineNedDepA(MsgBaselineNedDepA),
    /// Velocity in ECEF
    MsgVelEcefDepA(MsgVelEcefDepA),
    /// Velocity in NED
    MsgVelNedDepA(MsgVelNedDepA),
    /// Dilution of Precision
    MsgDopsDepA(MsgDopsDepA),
    /// Heading relative to True North
    MsgBaselineHeadingDepA(MsgBaselineHeadingDepA),
    /// Dilution of Precision
    MsgDops(MsgDops),
    /// Single-point position in ECEF
    MsgPosEcef(MsgPosEcef),
    /// Geodetic Position
    MsgPosLlh(MsgPosLlh),
    /// Baseline Position in ECEF
    MsgBaselineEcef(MsgBaselineEcef),
    /// Baseline in NED
    MsgBaselineNed(MsgBaselineNed),
    /// Velocity in ECEF
    MsgVelEcef(MsgVelEcef),
    /// Velocity in NED
    MsgVelNed(MsgVelNed),
    /// Heading relative to True North
    MsgBaselineHeading(MsgBaselineHeading),
    /// Age of corrections
    MsgAgeCorrections(MsgAgeCorrections),
    /// Geodetic Position
    MsgPosLlhCov(MsgPosLlhCov),
    /// Velocity in NED
    MsgVelNedCov(MsgVelNedCov),
    /// Velocity in User Frame
    MsgVelBody(MsgVelBody),
    /// Single-point position in ECEF
    MsgPosEcefCov(MsgPosEcefCov),
    /// Velocity in ECEF
    MsgVelEcefCov(MsgVelEcefCov),
    /// Computed Position and Protection Level
    MsgProtectionLevelDepA(MsgProtectionLevelDepA),
    /// Computed state and Protection Levels
    MsgProtectionLevel(MsgProtectionLevel),
    /// Geodetic Position and Accuracy
    MsgPosLlhAcc(MsgPosLlhAcc),
    /// Velocity expressed as course over ground
    MsgVelCog(MsgVelCog),
    /// Quaternion 4 component vector
    MsgOrientQuat(MsgOrientQuat),
    /// Euler angles
    MsgOrientEuler(MsgOrientEuler),
    /// Vehicle Body Frame instantaneous angular rates
    MsgAngularRate(MsgAngularRate),
    /// GNSS-only Position in ECEF
    MsgPosEcefGnss(MsgPosEcefGnss),
    /// GNSS-only Geodetic Position
    MsgPosLlhGnss(MsgPosLlhGnss),
    /// GNSS-only Velocity in ECEF
    MsgVelEcefGnss(MsgVelEcefGnss),
    /// GNSS-only Velocity in NED
    MsgVelNedGnss(MsgVelNedGnss),
    /// GNSS-only Geodetic Position
    MsgPosLlhCovGnss(MsgPosLlhCovGnss),
    /// GNSS-only Velocity in NED
    MsgVelNedCovGnss(MsgVelNedCovGnss),
    /// GNSS-only Position in ECEF
    MsgPosEcefCovGnss(MsgPosEcefCovGnss),
    /// GNSS-only Velocity in ECEF
    MsgVelEcefCovGnss(MsgVelEcefCovGnss),
    /// Navigation DataBase Event
    MsgNdbEvent(MsgNdbEvent),
    /// Plaintext logging messages with levels
    MsgLog(MsgLog),
    /// Wrapper for FWD a separate stream of information over SBP
    MsgFwd(MsgFwd),
    /// Deprecated
    MsgSsrOrbitClockDepA(MsgSsrOrbitClockDepA),
    /// Precise orbit and clock correction
    MsgSsrOrbitClock(MsgSsrOrbitClock),
    /// Precise code biases correction
    MsgSsrCodeBiases(MsgSsrCodeBiases),
    /// Precise phase biases correction
    MsgSsrPhaseBiases(MsgSsrPhaseBiases),
    /// Deprecated
    MsgSsrStecCorrectionDepA(MsgSsrStecCorrectionDepA),
    /// Deprecated
    MsgSsrGriddedCorrectionNoStdDepA(MsgSsrGriddedCorrectionNoStdDepA),
    /// Deprecated
    MsgSsrGridDefinitionDepA(MsgSsrGridDefinitionDepA),
    /// Definition of a SSR atmospheric correction tile.
    MsgSsrTileDefinition(MsgSsrTileDefinition),
    /// Deprecated
    MsgSsrGriddedCorrectionDepA(MsgSsrGriddedCorrectionDepA),
    /// STEC correction polynomial coefficients
    MsgSsrStecCorrection(MsgSsrStecCorrection),
    /// Gridded troposphere and STEC correction residuals
    MsgSsrGriddedCorrection(MsgSsrGriddedCorrection),
    /// Satellite antenna phase center corrections
    MsgSsrSatelliteApc(MsgSsrSatelliteApc),
    /// OSR corrections
    MsgOsr(MsgOsr),
    /// User data
    MsgUserData(MsgUserData),
    /// Raw IMU data
    MsgImuRaw(MsgImuRaw),
    /// Auxiliary IMU data
    MsgImuAux(MsgImuAux),
    /// Raw magnetometer data
    MsgMagRaw(MsgMagRaw),
    /// Vehicle forward (x-axis) velocity
    MsgOdometry(MsgOdometry),
    /// Accumulated wheeltick count message
    MsgWheeltick(MsgWheeltick),
    /// Request advice on the optimal configuration for FileIO
    MsgFileioConfigReq(MsgFileioConfigReq),
    /// Response with advice on the optimal configuration for FileIO.
    MsgFileioConfigResp(MsgFileioConfigResp),
    /// Raw SBAS data
    MsgSbasRaw(MsgSbasRaw),
    /// List CPU state on the system. DEPRECATED
    MsgLinuxCpuStateDepA(MsgLinuxCpuStateDepA),
    /// List memory state on the system. DEPRECATED
    MsgLinuxMemStateDepA(MsgLinuxMemStateDepA),
    /// CPU, Memory and Process Starts/Stops. DEPRECATED
    MsgLinuxSysStateDepA(MsgLinuxSysStateDepA),
    /// A list of processes with high socket counts
    MsgLinuxProcessSocketCounts(MsgLinuxProcessSocketCounts),
    /// A list of processes with deep socket queues
    MsgLinuxProcessSocketQueues(MsgLinuxProcessSocketQueues),
    /// Summary of socket usage across the system
    MsgLinuxSocketUsage(MsgLinuxSocketUsage),
    /// Summary of processes with large amounts of open file descriptors
    MsgLinuxProcessFdCount(MsgLinuxProcessFdCount),
    /// Summary of open file descriptors on the system
    MsgLinuxProcessFdSummary(MsgLinuxProcessFdSummary),
    /// List CPU state on the system
    MsgLinuxCpuState(MsgLinuxCpuState),
    /// List memory state on the system
    MsgLinuxMemState(MsgLinuxMemState),
    /// CPU, Memory and Process Starts/Stops
    MsgLinuxSysState(MsgLinuxSysState),
    /// System start-up message
    MsgStartup(MsgStartup),
    /// Status of received corrections
    MsgDgnssStatus(MsgDgnssStatus),
    /// Inertial Navigation System status message
    MsgInsStatus(MsgInsStatus),
    /// Experimental telemetry message
    MsgCsacTelemetry(MsgCsacTelemetry),
    /// Experimental telemetry message labels
    MsgCsacTelemetryLabels(MsgCsacTelemetryLabels),
    /// Inertial Navigation System update status message
    MsgInsUpdates(MsgInsUpdates),
    /// Offset of the local time with respect to GNSS time
    MsgGnssTimeOffset(MsgGnssTimeOffset),
    /// Local time at detection of PPS pulse
    MsgPpsTime(MsgPpsTime),
    /// Solution Group Metadata
    MsgGroupMeta(MsgGroupMeta),
    /// Solution Sensors Metadata
    MsgSolnMeta(MsgSolnMeta),
    /// Deprecated
    MsgSolnMetaDepA(MsgSolnMetaDepA),
    /// Status report message
    MsgStatusReport(MsgStatusReport),
    /// System heartbeat message
    MsgHeartbeat(MsgHeartbeat),
    /// Unknown message type
    Unknown(Unknown),
}

impl Sbp {
    /// Parse a message from a [Frame](crate::Frame).
    ///
    /// # Example
    ///
    /// ```
    /// use std::convert::TryInto;
    ///
    /// use sbp::messages::logging::MsgLog;
    /// use sbp::{Frame, Sbp};
    ///
    /// fn main() -> Result<(), Box<dyn std::error::Error>> {
    ///     // log level 1 and with "hello" as the message
    ///     let payload: &[u8] = &[1, 104, 101, 108, 108, 111];
    ///     let frame = Frame {
    ///         msg_type: 1025,
    ///         sender_id: 1,
    ///         payload,
    ///     };
    ///     let msg: MsgLog = Sbp::from_frame(frame)?.try_into()?;
    ///     assert_eq!(msg.sender_id, Some(1));
    ///     assert_eq!(msg.level, 1);
    ///     assert_eq!(msg.text.as_bytes(), "hello".as_bytes());
    ///     Ok(())
    /// }
    /// ```
    pub fn from_frame<B: Buf>(mut frame: crate::Frame<B>) -> Result<Sbp, PayloadParseError> {
        match frame.msg_type {
            MsgPrintDep::MESSAGE_TYPE => {
                let mut msg = MsgPrintDep::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgPrintDep(msg))
            }
            MsgTrackingStateDetailedDep::MESSAGE_TYPE => {
                let mut msg = MsgTrackingStateDetailedDep::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgTrackingStateDetailedDep(msg))
            }
            MsgTrackingStateDepB::MESSAGE_TYPE => {
                let mut msg = MsgTrackingStateDepB::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgTrackingStateDepB(msg))
            }
            MsgAcqResultDepB::MESSAGE_TYPE => {
                let mut msg = MsgAcqResultDepB::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgAcqResultDepB(msg))
            }
            MsgAcqResultDepA::MESSAGE_TYPE => {
                let mut msg = MsgAcqResultDepA::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgAcqResultDepA(msg))
            }
            MsgTrackingStateDepA::MESSAGE_TYPE => {
                let mut msg = MsgTrackingStateDepA::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgTrackingStateDepA(msg))
            }
            MsgThreadState::MESSAGE_TYPE => {
                let mut msg = MsgThreadState::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgThreadState(msg))
            }
            MsgUartStateDepa::MESSAGE_TYPE => {
                let mut msg = MsgUartStateDepa::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgUartStateDepa(msg))
            }
            MsgIarState::MESSAGE_TYPE => {
                let mut msg = MsgIarState::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgIarState(msg))
            }
            MsgEphemerisDepA::MESSAGE_TYPE => {
                let mut msg = MsgEphemerisDepA::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgEphemerisDepA(msg))
            }
            MsgMaskSatelliteDep::MESSAGE_TYPE => {
                let mut msg = MsgMaskSatelliteDep::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgMaskSatelliteDep(msg))
            }
            MsgTrackingIqDepA::MESSAGE_TYPE => {
                let mut msg = MsgTrackingIqDepA::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgTrackingIqDepA(msg))
            }
            MsgUartState::MESSAGE_TYPE => {
                let mut msg = MsgUartState::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgUartState(msg))
            }
            MsgAcqSvProfileDep::MESSAGE_TYPE => {
                let mut msg = MsgAcqSvProfileDep::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgAcqSvProfileDep(msg))
            }
            MsgAcqResultDepC::MESSAGE_TYPE => {
                let mut msg = MsgAcqResultDepC::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgAcqResultDepC(msg))
            }
            MsgTrackingStateDetailedDepA::MESSAGE_TYPE => {
                let mut msg = MsgTrackingStateDetailedDepA::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgTrackingStateDetailedDepA(msg))
            }
            MsgResetFilters::MESSAGE_TYPE => {
                let mut msg = MsgResetFilters::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgResetFilters(msg))
            }
            MsgInitBaseDep::MESSAGE_TYPE => {
                let mut msg = MsgInitBaseDep::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgInitBaseDep(msg))
            }
            MsgMaskSatellite::MESSAGE_TYPE => {
                let mut msg = MsgMaskSatellite::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgMaskSatellite(msg))
            }
            MsgTrackingIqDepB::MESSAGE_TYPE => {
                let mut msg = MsgTrackingIqDepB::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgTrackingIqDepB(msg))
            }
            MsgTrackingIq::MESSAGE_TYPE => {
                let mut msg = MsgTrackingIq::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgTrackingIq(msg))
            }
            MsgAcqSvProfile::MESSAGE_TYPE => {
                let mut msg = MsgAcqSvProfile::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgAcqSvProfile(msg))
            }
            MsgAcqResult::MESSAGE_TYPE => {
                let mut msg = MsgAcqResult::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgAcqResult(msg))
            }
            MsgTrackingState::MESSAGE_TYPE => {
                let mut msg = MsgTrackingState::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgTrackingState(msg))
            }
            MsgObsDepB::MESSAGE_TYPE => {
                let mut msg = MsgObsDepB::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgObsDepB(msg))
            }
            MsgBasePosLlh::MESSAGE_TYPE => {
                let mut msg = MsgBasePosLlh::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgBasePosLlh(msg))
            }
            MsgObsDepA::MESSAGE_TYPE => {
                let mut msg = MsgObsDepA::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgObsDepA(msg))
            }
            MsgEphemerisDepB::MESSAGE_TYPE => {
                let mut msg = MsgEphemerisDepB::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgEphemerisDepB(msg))
            }
            MsgEphemerisDepC::MESSAGE_TYPE => {
                let mut msg = MsgEphemerisDepC::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgEphemerisDepC(msg))
            }
            MsgBasePosEcef::MESSAGE_TYPE => {
                let mut msg = MsgBasePosEcef::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgBasePosEcef(msg))
            }
            MsgObsDepC::MESSAGE_TYPE => {
                let mut msg = MsgObsDepC::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgObsDepC(msg))
            }
            MsgObs::MESSAGE_TYPE => {
                let mut msg = MsgObs::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgObs(msg))
            }
            MsgSpecanDep::MESSAGE_TYPE => {
                let mut msg = MsgSpecanDep::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgSpecanDep(msg))
            }
            MsgSpecan::MESSAGE_TYPE => {
                let mut msg = MsgSpecan::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgSpecan(msg))
            }
            MsgMeasurementState::MESSAGE_TYPE => {
                let mut msg = MsgMeasurementState::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgMeasurementState(msg))
            }
            MsgSetTime::MESSAGE_TYPE => {
                let mut msg = MsgSetTime::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgSetTime(msg))
            }
            MsgAlmanac::MESSAGE_TYPE => {
                let mut msg = MsgAlmanac::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgAlmanac(msg))
            }
            MsgAlmanacGpsDep::MESSAGE_TYPE => {
                let mut msg = MsgAlmanacGpsDep::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgAlmanacGpsDep(msg))
            }
            MsgAlmanacGloDep::MESSAGE_TYPE => {
                let mut msg = MsgAlmanacGloDep::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgAlmanacGloDep(msg))
            }
            MsgAlmanacGps::MESSAGE_TYPE => {
                let mut msg = MsgAlmanacGps::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgAlmanacGps(msg))
            }
            MsgAlmanacGlo::MESSAGE_TYPE => {
                let mut msg = MsgAlmanacGlo::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgAlmanacGlo(msg))
            }
            MsgGloBiases::MESSAGE_TYPE => {
                let mut msg = MsgGloBiases::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgGloBiases(msg))
            }
            MsgEphemerisDepD::MESSAGE_TYPE => {
                let mut msg = MsgEphemerisDepD::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgEphemerisDepD(msg))
            }
            MsgEphemerisGpsDepE::MESSAGE_TYPE => {
                let mut msg = MsgEphemerisGpsDepE::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgEphemerisGpsDepE(msg))
            }
            MsgEphemerisSbasDepA::MESSAGE_TYPE => {
                let mut msg = MsgEphemerisSbasDepA::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgEphemerisSbasDepA(msg))
            }
            MsgEphemerisGloDepA::MESSAGE_TYPE => {
                let mut msg = MsgEphemerisGloDepA::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgEphemerisGloDepA(msg))
            }
            MsgEphemerisSbasDepB::MESSAGE_TYPE => {
                let mut msg = MsgEphemerisSbasDepB::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgEphemerisSbasDepB(msg))
            }
            MsgEphemerisGloDepB::MESSAGE_TYPE => {
                let mut msg = MsgEphemerisGloDepB::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgEphemerisGloDepB(msg))
            }
            MsgEphemerisGpsDepF::MESSAGE_TYPE => {
                let mut msg = MsgEphemerisGpsDepF::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgEphemerisGpsDepF(msg))
            }
            MsgEphemerisGloDepC::MESSAGE_TYPE => {
                let mut msg = MsgEphemerisGloDepC::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgEphemerisGloDepC(msg))
            }
            MsgEphemerisGloDepD::MESSAGE_TYPE => {
                let mut msg = MsgEphemerisGloDepD::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgEphemerisGloDepD(msg))
            }
            MsgEphemerisBds::MESSAGE_TYPE => {
                let mut msg = MsgEphemerisBds::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgEphemerisBds(msg))
            }
            MsgEphemerisGps::MESSAGE_TYPE => {
                let mut msg = MsgEphemerisGps::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgEphemerisGps(msg))
            }
            MsgEphemerisGlo::MESSAGE_TYPE => {
                let mut msg = MsgEphemerisGlo::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgEphemerisGlo(msg))
            }
            MsgEphemerisSbas::MESSAGE_TYPE => {
                let mut msg = MsgEphemerisSbas::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgEphemerisSbas(msg))
            }
            MsgEphemerisGal::MESSAGE_TYPE => {
                let mut msg = MsgEphemerisGal::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgEphemerisGal(msg))
            }
            MsgEphemerisQzss::MESSAGE_TYPE => {
                let mut msg = MsgEphemerisQzss::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgEphemerisQzss(msg))
            }
            MsgIono::MESSAGE_TYPE => {
                let mut msg = MsgIono::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgIono(msg))
            }
            MsgSvConfigurationGpsDep::MESSAGE_TYPE => {
                let mut msg = MsgSvConfigurationGpsDep::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgSvConfigurationGpsDep(msg))
            }
            MsgGroupDelayDepA::MESSAGE_TYPE => {
                let mut msg = MsgGroupDelayDepA::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgGroupDelayDepA(msg))
            }
            MsgGroupDelayDepB::MESSAGE_TYPE => {
                let mut msg = MsgGroupDelayDepB::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgGroupDelayDepB(msg))
            }
            MsgGroupDelay::MESSAGE_TYPE => {
                let mut msg = MsgGroupDelay::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgGroupDelay(msg))
            }
            MsgEphemerisGalDepA::MESSAGE_TYPE => {
                let mut msg = MsgEphemerisGalDepA::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgEphemerisGalDepA(msg))
            }
            MsgGnssCapb::MESSAGE_TYPE => {
                let mut msg = MsgGnssCapb::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgGnssCapb(msg))
            }
            MsgSvAzEl::MESSAGE_TYPE => {
                let mut msg = MsgSvAzEl::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgSvAzEl(msg))
            }
            MsgSettingsWrite::MESSAGE_TYPE => {
                let mut msg = MsgSettingsWrite::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgSettingsWrite(msg))
            }
            MsgSettingsSave::MESSAGE_TYPE => {
                let mut msg = MsgSettingsSave::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgSettingsSave(msg))
            }
            MsgSettingsReadByIndexReq::MESSAGE_TYPE => {
                let mut msg = MsgSettingsReadByIndexReq::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgSettingsReadByIndexReq(msg))
            }
            MsgFileioReadResp::MESSAGE_TYPE => {
                let mut msg = MsgFileioReadResp::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgFileioReadResp(msg))
            }
            MsgSettingsReadReq::MESSAGE_TYPE => {
                let mut msg = MsgSettingsReadReq::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgSettingsReadReq(msg))
            }
            MsgSettingsReadResp::MESSAGE_TYPE => {
                let mut msg = MsgSettingsReadResp::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgSettingsReadResp(msg))
            }
            MsgSettingsReadByIndexDone::MESSAGE_TYPE => {
                let mut msg = MsgSettingsReadByIndexDone::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgSettingsReadByIndexDone(msg))
            }
            MsgSettingsReadByIndexResp::MESSAGE_TYPE => {
                let mut msg = MsgSettingsReadByIndexResp::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgSettingsReadByIndexResp(msg))
            }
            MsgFileioReadReq::MESSAGE_TYPE => {
                let mut msg = MsgFileioReadReq::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgFileioReadReq(msg))
            }
            MsgFileioReadDirReq::MESSAGE_TYPE => {
                let mut msg = MsgFileioReadDirReq::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgFileioReadDirReq(msg))
            }
            MsgFileioReadDirResp::MESSAGE_TYPE => {
                let mut msg = MsgFileioReadDirResp::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgFileioReadDirResp(msg))
            }
            MsgFileioWriteResp::MESSAGE_TYPE => {
                let mut msg = MsgFileioWriteResp::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgFileioWriteResp(msg))
            }
            MsgFileioRemove::MESSAGE_TYPE => {
                let mut msg = MsgFileioRemove::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgFileioRemove(msg))
            }
            MsgFileioWriteReq::MESSAGE_TYPE => {
                let mut msg = MsgFileioWriteReq::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgFileioWriteReq(msg))
            }
            MsgSettingsRegister::MESSAGE_TYPE => {
                let mut msg = MsgSettingsRegister::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgSettingsRegister(msg))
            }
            MsgSettingsWriteResp::MESSAGE_TYPE => {
                let mut msg = MsgSettingsWriteResp::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgSettingsWriteResp(msg))
            }
            MsgBootloaderHandshakeDepA::MESSAGE_TYPE => {
                let mut msg = MsgBootloaderHandshakeDepA::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgBootloaderHandshakeDepA(msg))
            }
            MsgBootloaderJumpToApp::MESSAGE_TYPE => {
                let mut msg = MsgBootloaderJumpToApp::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgBootloaderJumpToApp(msg))
            }
            MsgResetDep::MESSAGE_TYPE => {
                let mut msg = MsgResetDep::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgResetDep(msg))
            }
            MsgBootloaderHandshakeReq::MESSAGE_TYPE => {
                let mut msg = MsgBootloaderHandshakeReq::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgBootloaderHandshakeReq(msg))
            }
            MsgBootloaderHandshakeResp::MESSAGE_TYPE => {
                let mut msg = MsgBootloaderHandshakeResp::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgBootloaderHandshakeResp(msg))
            }
            MsgDeviceMonitor::MESSAGE_TYPE => {
                let mut msg = MsgDeviceMonitor::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgDeviceMonitor(msg))
            }
            MsgReset::MESSAGE_TYPE => {
                let mut msg = MsgReset::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgReset(msg))
            }
            MsgCommandReq::MESSAGE_TYPE => {
                let mut msg = MsgCommandReq::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgCommandReq(msg))
            }
            MsgCommandResp::MESSAGE_TYPE => {
                let mut msg = MsgCommandResp::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgCommandResp(msg))
            }
            MsgNetworkStateReq::MESSAGE_TYPE => {
                let mut msg = MsgNetworkStateReq::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgNetworkStateReq(msg))
            }
            MsgNetworkStateResp::MESSAGE_TYPE => {
                let mut msg = MsgNetworkStateResp::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgNetworkStateResp(msg))
            }
            MsgCommandOutput::MESSAGE_TYPE => {
                let mut msg = MsgCommandOutput::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgCommandOutput(msg))
            }
            MsgNetworkBandwidthUsage::MESSAGE_TYPE => {
                let mut msg = MsgNetworkBandwidthUsage::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgNetworkBandwidthUsage(msg))
            }
            MsgCellModemStatus::MESSAGE_TYPE => {
                let mut msg = MsgCellModemStatus::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgCellModemStatus(msg))
            }
            MsgFrontEndGain::MESSAGE_TYPE => {
                let mut msg = MsgFrontEndGain::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgFrontEndGain(msg))
            }
            MsgCwResults::MESSAGE_TYPE => {
                let mut msg = MsgCwResults::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgCwResults(msg))
            }
            MsgCwStart::MESSAGE_TYPE => {
                let mut msg = MsgCwStart::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgCwStart(msg))
            }
            MsgNapDeviceDnaResp::MESSAGE_TYPE => {
                let mut msg = MsgNapDeviceDnaResp::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgNapDeviceDnaResp(msg))
            }
            MsgNapDeviceDnaReq::MESSAGE_TYPE => {
                let mut msg = MsgNapDeviceDnaReq::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgNapDeviceDnaReq(msg))
            }
            MsgFlashDone::MESSAGE_TYPE => {
                let mut msg = MsgFlashDone::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgFlashDone(msg))
            }
            MsgFlashReadResp::MESSAGE_TYPE => {
                let mut msg = MsgFlashReadResp::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgFlashReadResp(msg))
            }
            MsgFlashErase::MESSAGE_TYPE => {
                let mut msg = MsgFlashErase::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgFlashErase(msg))
            }
            MsgStmFlashLockSector::MESSAGE_TYPE => {
                let mut msg = MsgStmFlashLockSector::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgStmFlashLockSector(msg))
            }
            MsgStmFlashUnlockSector::MESSAGE_TYPE => {
                let mut msg = MsgStmFlashUnlockSector::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgStmFlashUnlockSector(msg))
            }
            MsgStmUniqueIdResp::MESSAGE_TYPE => {
                let mut msg = MsgStmUniqueIdResp::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgStmUniqueIdResp(msg))
            }
            MsgFlashProgram::MESSAGE_TYPE => {
                let mut msg = MsgFlashProgram::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgFlashProgram(msg))
            }
            MsgFlashReadReq::MESSAGE_TYPE => {
                let mut msg = MsgFlashReadReq::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgFlashReadReq(msg))
            }
            MsgStmUniqueIdReq::MESSAGE_TYPE => {
                let mut msg = MsgStmUniqueIdReq::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgStmUniqueIdReq(msg))
            }
            MsgM25FlashWriteStatus::MESSAGE_TYPE => {
                let mut msg = MsgM25FlashWriteStatus::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgM25FlashWriteStatus(msg))
            }
            MsgGpsTimeDepA::MESSAGE_TYPE => {
                let mut msg = MsgGpsTimeDepA::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgGpsTimeDepA(msg))
            }
            MsgExtEvent::MESSAGE_TYPE => {
                let mut msg = MsgExtEvent::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgExtEvent(msg))
            }
            MsgGpsTime::MESSAGE_TYPE => {
                let mut msg = MsgGpsTime::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgGpsTime(msg))
            }
            MsgUtcTime::MESSAGE_TYPE => {
                let mut msg = MsgUtcTime::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgUtcTime(msg))
            }
            MsgGpsTimeGnss::MESSAGE_TYPE => {
                let mut msg = MsgGpsTimeGnss::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgGpsTimeGnss(msg))
            }
            MsgUtcTimeGnss::MESSAGE_TYPE => {
                let mut msg = MsgUtcTimeGnss::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgUtcTimeGnss(msg))
            }
            MsgSettingsRegisterResp::MESSAGE_TYPE => {
                let mut msg = MsgSettingsRegisterResp::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgSettingsRegisterResp(msg))
            }
            MsgPosEcefDepA::MESSAGE_TYPE => {
                let mut msg = MsgPosEcefDepA::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgPosEcefDepA(msg))
            }
            MsgPosLlhDepA::MESSAGE_TYPE => {
                let mut msg = MsgPosLlhDepA::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgPosLlhDepA(msg))
            }
            MsgBaselineEcefDepA::MESSAGE_TYPE => {
                let mut msg = MsgBaselineEcefDepA::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgBaselineEcefDepA(msg))
            }
            MsgBaselineNedDepA::MESSAGE_TYPE => {
                let mut msg = MsgBaselineNedDepA::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgBaselineNedDepA(msg))
            }
            MsgVelEcefDepA::MESSAGE_TYPE => {
                let mut msg = MsgVelEcefDepA::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgVelEcefDepA(msg))
            }
            MsgVelNedDepA::MESSAGE_TYPE => {
                let mut msg = MsgVelNedDepA::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgVelNedDepA(msg))
            }
            MsgDopsDepA::MESSAGE_TYPE => {
                let mut msg = MsgDopsDepA::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgDopsDepA(msg))
            }
            MsgBaselineHeadingDepA::MESSAGE_TYPE => {
                let mut msg = MsgBaselineHeadingDepA::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgBaselineHeadingDepA(msg))
            }
            MsgDops::MESSAGE_TYPE => {
                let mut msg = MsgDops::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgDops(msg))
            }
            MsgPosEcef::MESSAGE_TYPE => {
                let mut msg = MsgPosEcef::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgPosEcef(msg))
            }
            MsgPosLlh::MESSAGE_TYPE => {
                let mut msg = MsgPosLlh::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgPosLlh(msg))
            }
            MsgBaselineEcef::MESSAGE_TYPE => {
                let mut msg = MsgBaselineEcef::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgBaselineEcef(msg))
            }
            MsgBaselineNed::MESSAGE_TYPE => {
                let mut msg = MsgBaselineNed::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgBaselineNed(msg))
            }
            MsgVelEcef::MESSAGE_TYPE => {
                let mut msg = MsgVelEcef::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgVelEcef(msg))
            }
            MsgVelNed::MESSAGE_TYPE => {
                let mut msg = MsgVelNed::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgVelNed(msg))
            }
            MsgBaselineHeading::MESSAGE_TYPE => {
                let mut msg = MsgBaselineHeading::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgBaselineHeading(msg))
            }
            MsgAgeCorrections::MESSAGE_TYPE => {
                let mut msg = MsgAgeCorrections::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgAgeCorrections(msg))
            }
            MsgPosLlhCov::MESSAGE_TYPE => {
                let mut msg = MsgPosLlhCov::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgPosLlhCov(msg))
            }
            MsgVelNedCov::MESSAGE_TYPE => {
                let mut msg = MsgVelNedCov::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgVelNedCov(msg))
            }
            MsgVelBody::MESSAGE_TYPE => {
                let mut msg = MsgVelBody::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgVelBody(msg))
            }
            MsgPosEcefCov::MESSAGE_TYPE => {
                let mut msg = MsgPosEcefCov::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgPosEcefCov(msg))
            }
            MsgVelEcefCov::MESSAGE_TYPE => {
                let mut msg = MsgVelEcefCov::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgVelEcefCov(msg))
            }
            MsgProtectionLevelDepA::MESSAGE_TYPE => {
                let mut msg = MsgProtectionLevelDepA::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgProtectionLevelDepA(msg))
            }
            MsgProtectionLevel::MESSAGE_TYPE => {
                let mut msg = MsgProtectionLevel::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgProtectionLevel(msg))
            }
            MsgPosLlhAcc::MESSAGE_TYPE => {
                let mut msg = MsgPosLlhAcc::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgPosLlhAcc(msg))
            }
            MsgVelCog::MESSAGE_TYPE => {
                let mut msg = MsgVelCog::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgVelCog(msg))
            }
            MsgOrientQuat::MESSAGE_TYPE => {
                let mut msg = MsgOrientQuat::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgOrientQuat(msg))
            }
            MsgOrientEuler::MESSAGE_TYPE => {
                let mut msg = MsgOrientEuler::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgOrientEuler(msg))
            }
            MsgAngularRate::MESSAGE_TYPE => {
                let mut msg = MsgAngularRate::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgAngularRate(msg))
            }
            MsgPosEcefGnss::MESSAGE_TYPE => {
                let mut msg = MsgPosEcefGnss::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgPosEcefGnss(msg))
            }
            MsgPosLlhGnss::MESSAGE_TYPE => {
                let mut msg = MsgPosLlhGnss::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgPosLlhGnss(msg))
            }
            MsgVelEcefGnss::MESSAGE_TYPE => {
                let mut msg = MsgVelEcefGnss::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgVelEcefGnss(msg))
            }
            MsgVelNedGnss::MESSAGE_TYPE => {
                let mut msg = MsgVelNedGnss::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgVelNedGnss(msg))
            }
            MsgPosLlhCovGnss::MESSAGE_TYPE => {
                let mut msg = MsgPosLlhCovGnss::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgPosLlhCovGnss(msg))
            }
            MsgVelNedCovGnss::MESSAGE_TYPE => {
                let mut msg = MsgVelNedCovGnss::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgVelNedCovGnss(msg))
            }
            MsgPosEcefCovGnss::MESSAGE_TYPE => {
                let mut msg = MsgPosEcefCovGnss::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgPosEcefCovGnss(msg))
            }
            MsgVelEcefCovGnss::MESSAGE_TYPE => {
                let mut msg = MsgVelEcefCovGnss::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgVelEcefCovGnss(msg))
            }
            MsgNdbEvent::MESSAGE_TYPE => {
                let mut msg = MsgNdbEvent::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgNdbEvent(msg))
            }
            MsgLog::MESSAGE_TYPE => {
                let mut msg = MsgLog::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgLog(msg))
            }
            MsgFwd::MESSAGE_TYPE => {
                let mut msg = MsgFwd::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgFwd(msg))
            }
            MsgSsrOrbitClockDepA::MESSAGE_TYPE => {
                let mut msg = MsgSsrOrbitClockDepA::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgSsrOrbitClockDepA(msg))
            }
            MsgSsrOrbitClock::MESSAGE_TYPE => {
                let mut msg = MsgSsrOrbitClock::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgSsrOrbitClock(msg))
            }
            MsgSsrCodeBiases::MESSAGE_TYPE => {
                let mut msg = MsgSsrCodeBiases::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgSsrCodeBiases(msg))
            }
            MsgSsrPhaseBiases::MESSAGE_TYPE => {
                let mut msg = MsgSsrPhaseBiases::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgSsrPhaseBiases(msg))
            }
            MsgSsrStecCorrectionDepA::MESSAGE_TYPE => {
                let mut msg = MsgSsrStecCorrectionDepA::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgSsrStecCorrectionDepA(msg))
            }
            MsgSsrGriddedCorrectionNoStdDepA::MESSAGE_TYPE => {
                let mut msg = MsgSsrGriddedCorrectionNoStdDepA::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgSsrGriddedCorrectionNoStdDepA(msg))
            }
            MsgSsrGridDefinitionDepA::MESSAGE_TYPE => {
                let mut msg = MsgSsrGridDefinitionDepA::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgSsrGridDefinitionDepA(msg))
            }
            MsgSsrTileDefinition::MESSAGE_TYPE => {
                let mut msg = MsgSsrTileDefinition::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgSsrTileDefinition(msg))
            }
            MsgSsrGriddedCorrectionDepA::MESSAGE_TYPE => {
                let mut msg = MsgSsrGriddedCorrectionDepA::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgSsrGriddedCorrectionDepA(msg))
            }
            MsgSsrStecCorrection::MESSAGE_TYPE => {
                let mut msg = MsgSsrStecCorrection::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgSsrStecCorrection(msg))
            }
            MsgSsrGriddedCorrection::MESSAGE_TYPE => {
                let mut msg = MsgSsrGriddedCorrection::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgSsrGriddedCorrection(msg))
            }
            MsgSsrSatelliteApc::MESSAGE_TYPE => {
                let mut msg = MsgSsrSatelliteApc::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgSsrSatelliteApc(msg))
            }
            MsgOsr::MESSAGE_TYPE => {
                let mut msg = MsgOsr::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgOsr(msg))
            }
            MsgUserData::MESSAGE_TYPE => {
                let mut msg = MsgUserData::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgUserData(msg))
            }
            MsgImuRaw::MESSAGE_TYPE => {
                let mut msg = MsgImuRaw::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgImuRaw(msg))
            }
            MsgImuAux::MESSAGE_TYPE => {
                let mut msg = MsgImuAux::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgImuAux(msg))
            }
            MsgMagRaw::MESSAGE_TYPE => {
                let mut msg = MsgMagRaw::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgMagRaw(msg))
            }
            MsgOdometry::MESSAGE_TYPE => {
                let mut msg = MsgOdometry::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgOdometry(msg))
            }
            MsgWheeltick::MESSAGE_TYPE => {
                let mut msg = MsgWheeltick::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgWheeltick(msg))
            }
            MsgFileioConfigReq::MESSAGE_TYPE => {
                let mut msg = MsgFileioConfigReq::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgFileioConfigReq(msg))
            }
            MsgFileioConfigResp::MESSAGE_TYPE => {
                let mut msg = MsgFileioConfigResp::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgFileioConfigResp(msg))
            }
            MsgSbasRaw::MESSAGE_TYPE => {
                let mut msg = MsgSbasRaw::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgSbasRaw(msg))
            }
            MsgLinuxCpuStateDepA::MESSAGE_TYPE => {
                let mut msg = MsgLinuxCpuStateDepA::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgLinuxCpuStateDepA(msg))
            }
            MsgLinuxMemStateDepA::MESSAGE_TYPE => {
                let mut msg = MsgLinuxMemStateDepA::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgLinuxMemStateDepA(msg))
            }
            MsgLinuxSysStateDepA::MESSAGE_TYPE => {
                let mut msg = MsgLinuxSysStateDepA::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgLinuxSysStateDepA(msg))
            }
            MsgLinuxProcessSocketCounts::MESSAGE_TYPE => {
                let mut msg = MsgLinuxProcessSocketCounts::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgLinuxProcessSocketCounts(msg))
            }
            MsgLinuxProcessSocketQueues::MESSAGE_TYPE => {
                let mut msg = MsgLinuxProcessSocketQueues::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgLinuxProcessSocketQueues(msg))
            }
            MsgLinuxSocketUsage::MESSAGE_TYPE => {
                let mut msg = MsgLinuxSocketUsage::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgLinuxSocketUsage(msg))
            }
            MsgLinuxProcessFdCount::MESSAGE_TYPE => {
                let mut msg = MsgLinuxProcessFdCount::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgLinuxProcessFdCount(msg))
            }
            MsgLinuxProcessFdSummary::MESSAGE_TYPE => {
                let mut msg = MsgLinuxProcessFdSummary::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgLinuxProcessFdSummary(msg))
            }
            MsgLinuxCpuState::MESSAGE_TYPE => {
                let mut msg = MsgLinuxCpuState::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgLinuxCpuState(msg))
            }
            MsgLinuxMemState::MESSAGE_TYPE => {
                let mut msg = MsgLinuxMemState::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgLinuxMemState(msg))
            }
            MsgLinuxSysState::MESSAGE_TYPE => {
                let mut msg = MsgLinuxSysState::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgLinuxSysState(msg))
            }
            MsgStartup::MESSAGE_TYPE => {
                let mut msg = MsgStartup::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgStartup(msg))
            }
            MsgDgnssStatus::MESSAGE_TYPE => {
                let mut msg = MsgDgnssStatus::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgDgnssStatus(msg))
            }
            MsgInsStatus::MESSAGE_TYPE => {
                let mut msg = MsgInsStatus::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgInsStatus(msg))
            }
            MsgCsacTelemetry::MESSAGE_TYPE => {
                let mut msg = MsgCsacTelemetry::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgCsacTelemetry(msg))
            }
            MsgCsacTelemetryLabels::MESSAGE_TYPE => {
                let mut msg = MsgCsacTelemetryLabels::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgCsacTelemetryLabels(msg))
            }
            MsgInsUpdates::MESSAGE_TYPE => {
                let mut msg = MsgInsUpdates::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgInsUpdates(msg))
            }
            MsgGnssTimeOffset::MESSAGE_TYPE => {
                let mut msg = MsgGnssTimeOffset::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgGnssTimeOffset(msg))
            }
            MsgPpsTime::MESSAGE_TYPE => {
                let mut msg = MsgPpsTime::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgPpsTime(msg))
            }
            MsgGroupMeta::MESSAGE_TYPE => {
                let mut msg = MsgGroupMeta::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgGroupMeta(msg))
            }
            MsgSolnMeta::MESSAGE_TYPE => {
                let mut msg = MsgSolnMeta::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgSolnMeta(msg))
            }
            MsgSolnMetaDepA::MESSAGE_TYPE => {
                let mut msg = MsgSolnMetaDepA::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgSolnMetaDepA(msg))
            }
            MsgStatusReport::MESSAGE_TYPE => {
                let mut msg = MsgStatusReport::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgStatusReport(msg))
            }
            MsgHeartbeat::MESSAGE_TYPE => {
                let mut msg = MsgHeartbeat::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::MsgHeartbeat(msg))
            }
            _ => {
                let mut msg = Unknown::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::Unknown(msg))
            }
        }
    }
}

impl SbpMessage for Sbp {
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
            Sbp::MsgVelCog(msg) => msg.message_name(),
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
            Sbp::MsgVelCog(msg) => msg.message_type(),
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
            Sbp::MsgVelCog(msg) => msg.sender_id(),
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
            Sbp::MsgVelCog(msg) => msg.set_sender_id(new_id),
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

    fn encoded_len(&self) -> usize {
        match self {
            Sbp::MsgPrintDep(msg) => msg.encoded_len(),
            Sbp::MsgTrackingStateDetailedDep(msg) => msg.encoded_len(),
            Sbp::MsgTrackingStateDepB(msg) => msg.encoded_len(),
            Sbp::MsgAcqResultDepB(msg) => msg.encoded_len(),
            Sbp::MsgAcqResultDepA(msg) => msg.encoded_len(),
            Sbp::MsgTrackingStateDepA(msg) => msg.encoded_len(),
            Sbp::MsgThreadState(msg) => msg.encoded_len(),
            Sbp::MsgUartStateDepa(msg) => msg.encoded_len(),
            Sbp::MsgIarState(msg) => msg.encoded_len(),
            Sbp::MsgEphemerisDepA(msg) => msg.encoded_len(),
            Sbp::MsgMaskSatelliteDep(msg) => msg.encoded_len(),
            Sbp::MsgTrackingIqDepA(msg) => msg.encoded_len(),
            Sbp::MsgUartState(msg) => msg.encoded_len(),
            Sbp::MsgAcqSvProfileDep(msg) => msg.encoded_len(),
            Sbp::MsgAcqResultDepC(msg) => msg.encoded_len(),
            Sbp::MsgTrackingStateDetailedDepA(msg) => msg.encoded_len(),
            Sbp::MsgResetFilters(msg) => msg.encoded_len(),
            Sbp::MsgInitBaseDep(msg) => msg.encoded_len(),
            Sbp::MsgMaskSatellite(msg) => msg.encoded_len(),
            Sbp::MsgTrackingIqDepB(msg) => msg.encoded_len(),
            Sbp::MsgTrackingIq(msg) => msg.encoded_len(),
            Sbp::MsgAcqSvProfile(msg) => msg.encoded_len(),
            Sbp::MsgAcqResult(msg) => msg.encoded_len(),
            Sbp::MsgTrackingState(msg) => msg.encoded_len(),
            Sbp::MsgObsDepB(msg) => msg.encoded_len(),
            Sbp::MsgBasePosLlh(msg) => msg.encoded_len(),
            Sbp::MsgObsDepA(msg) => msg.encoded_len(),
            Sbp::MsgEphemerisDepB(msg) => msg.encoded_len(),
            Sbp::MsgEphemerisDepC(msg) => msg.encoded_len(),
            Sbp::MsgBasePosEcef(msg) => msg.encoded_len(),
            Sbp::MsgObsDepC(msg) => msg.encoded_len(),
            Sbp::MsgObs(msg) => msg.encoded_len(),
            Sbp::MsgSpecanDep(msg) => msg.encoded_len(),
            Sbp::MsgSpecan(msg) => msg.encoded_len(),
            Sbp::MsgMeasurementState(msg) => msg.encoded_len(),
            Sbp::MsgSetTime(msg) => msg.encoded_len(),
            Sbp::MsgAlmanac(msg) => msg.encoded_len(),
            Sbp::MsgAlmanacGpsDep(msg) => msg.encoded_len(),
            Sbp::MsgAlmanacGloDep(msg) => msg.encoded_len(),
            Sbp::MsgAlmanacGps(msg) => msg.encoded_len(),
            Sbp::MsgAlmanacGlo(msg) => msg.encoded_len(),
            Sbp::MsgGloBiases(msg) => msg.encoded_len(),
            Sbp::MsgEphemerisDepD(msg) => msg.encoded_len(),
            Sbp::MsgEphemerisGpsDepE(msg) => msg.encoded_len(),
            Sbp::MsgEphemerisSbasDepA(msg) => msg.encoded_len(),
            Sbp::MsgEphemerisGloDepA(msg) => msg.encoded_len(),
            Sbp::MsgEphemerisSbasDepB(msg) => msg.encoded_len(),
            Sbp::MsgEphemerisGloDepB(msg) => msg.encoded_len(),
            Sbp::MsgEphemerisGpsDepF(msg) => msg.encoded_len(),
            Sbp::MsgEphemerisGloDepC(msg) => msg.encoded_len(),
            Sbp::MsgEphemerisGloDepD(msg) => msg.encoded_len(),
            Sbp::MsgEphemerisBds(msg) => msg.encoded_len(),
            Sbp::MsgEphemerisGps(msg) => msg.encoded_len(),
            Sbp::MsgEphemerisGlo(msg) => msg.encoded_len(),
            Sbp::MsgEphemerisSbas(msg) => msg.encoded_len(),
            Sbp::MsgEphemerisGal(msg) => msg.encoded_len(),
            Sbp::MsgEphemerisQzss(msg) => msg.encoded_len(),
            Sbp::MsgIono(msg) => msg.encoded_len(),
            Sbp::MsgSvConfigurationGpsDep(msg) => msg.encoded_len(),
            Sbp::MsgGroupDelayDepA(msg) => msg.encoded_len(),
            Sbp::MsgGroupDelayDepB(msg) => msg.encoded_len(),
            Sbp::MsgGroupDelay(msg) => msg.encoded_len(),
            Sbp::MsgEphemerisGalDepA(msg) => msg.encoded_len(),
            Sbp::MsgGnssCapb(msg) => msg.encoded_len(),
            Sbp::MsgSvAzEl(msg) => msg.encoded_len(),
            Sbp::MsgSettingsWrite(msg) => msg.encoded_len(),
            Sbp::MsgSettingsSave(msg) => msg.encoded_len(),
            Sbp::MsgSettingsReadByIndexReq(msg) => msg.encoded_len(),
            Sbp::MsgFileioReadResp(msg) => msg.encoded_len(),
            Sbp::MsgSettingsReadReq(msg) => msg.encoded_len(),
            Sbp::MsgSettingsReadResp(msg) => msg.encoded_len(),
            Sbp::MsgSettingsReadByIndexDone(msg) => msg.encoded_len(),
            Sbp::MsgSettingsReadByIndexResp(msg) => msg.encoded_len(),
            Sbp::MsgFileioReadReq(msg) => msg.encoded_len(),
            Sbp::MsgFileioReadDirReq(msg) => msg.encoded_len(),
            Sbp::MsgFileioReadDirResp(msg) => msg.encoded_len(),
            Sbp::MsgFileioWriteResp(msg) => msg.encoded_len(),
            Sbp::MsgFileioRemove(msg) => msg.encoded_len(),
            Sbp::MsgFileioWriteReq(msg) => msg.encoded_len(),
            Sbp::MsgSettingsRegister(msg) => msg.encoded_len(),
            Sbp::MsgSettingsWriteResp(msg) => msg.encoded_len(),
            Sbp::MsgBootloaderHandshakeDepA(msg) => msg.encoded_len(),
            Sbp::MsgBootloaderJumpToApp(msg) => msg.encoded_len(),
            Sbp::MsgResetDep(msg) => msg.encoded_len(),
            Sbp::MsgBootloaderHandshakeReq(msg) => msg.encoded_len(),
            Sbp::MsgBootloaderHandshakeResp(msg) => msg.encoded_len(),
            Sbp::MsgDeviceMonitor(msg) => msg.encoded_len(),
            Sbp::MsgReset(msg) => msg.encoded_len(),
            Sbp::MsgCommandReq(msg) => msg.encoded_len(),
            Sbp::MsgCommandResp(msg) => msg.encoded_len(),
            Sbp::MsgNetworkStateReq(msg) => msg.encoded_len(),
            Sbp::MsgNetworkStateResp(msg) => msg.encoded_len(),
            Sbp::MsgCommandOutput(msg) => msg.encoded_len(),
            Sbp::MsgNetworkBandwidthUsage(msg) => msg.encoded_len(),
            Sbp::MsgCellModemStatus(msg) => msg.encoded_len(),
            Sbp::MsgFrontEndGain(msg) => msg.encoded_len(),
            Sbp::MsgCwResults(msg) => msg.encoded_len(),
            Sbp::MsgCwStart(msg) => msg.encoded_len(),
            Sbp::MsgNapDeviceDnaResp(msg) => msg.encoded_len(),
            Sbp::MsgNapDeviceDnaReq(msg) => msg.encoded_len(),
            Sbp::MsgFlashDone(msg) => msg.encoded_len(),
            Sbp::MsgFlashReadResp(msg) => msg.encoded_len(),
            Sbp::MsgFlashErase(msg) => msg.encoded_len(),
            Sbp::MsgStmFlashLockSector(msg) => msg.encoded_len(),
            Sbp::MsgStmFlashUnlockSector(msg) => msg.encoded_len(),
            Sbp::MsgStmUniqueIdResp(msg) => msg.encoded_len(),
            Sbp::MsgFlashProgram(msg) => msg.encoded_len(),
            Sbp::MsgFlashReadReq(msg) => msg.encoded_len(),
            Sbp::MsgStmUniqueIdReq(msg) => msg.encoded_len(),
            Sbp::MsgM25FlashWriteStatus(msg) => msg.encoded_len(),
            Sbp::MsgGpsTimeDepA(msg) => msg.encoded_len(),
            Sbp::MsgExtEvent(msg) => msg.encoded_len(),
            Sbp::MsgGpsTime(msg) => msg.encoded_len(),
            Sbp::MsgUtcTime(msg) => msg.encoded_len(),
            Sbp::MsgGpsTimeGnss(msg) => msg.encoded_len(),
            Sbp::MsgUtcTimeGnss(msg) => msg.encoded_len(),
            Sbp::MsgSettingsRegisterResp(msg) => msg.encoded_len(),
            Sbp::MsgPosEcefDepA(msg) => msg.encoded_len(),
            Sbp::MsgPosLlhDepA(msg) => msg.encoded_len(),
            Sbp::MsgBaselineEcefDepA(msg) => msg.encoded_len(),
            Sbp::MsgBaselineNedDepA(msg) => msg.encoded_len(),
            Sbp::MsgVelEcefDepA(msg) => msg.encoded_len(),
            Sbp::MsgVelNedDepA(msg) => msg.encoded_len(),
            Sbp::MsgDopsDepA(msg) => msg.encoded_len(),
            Sbp::MsgBaselineHeadingDepA(msg) => msg.encoded_len(),
            Sbp::MsgDops(msg) => msg.encoded_len(),
            Sbp::MsgPosEcef(msg) => msg.encoded_len(),
            Sbp::MsgPosLlh(msg) => msg.encoded_len(),
            Sbp::MsgBaselineEcef(msg) => msg.encoded_len(),
            Sbp::MsgBaselineNed(msg) => msg.encoded_len(),
            Sbp::MsgVelEcef(msg) => msg.encoded_len(),
            Sbp::MsgVelNed(msg) => msg.encoded_len(),
            Sbp::MsgBaselineHeading(msg) => msg.encoded_len(),
            Sbp::MsgAgeCorrections(msg) => msg.encoded_len(),
            Sbp::MsgPosLlhCov(msg) => msg.encoded_len(),
            Sbp::MsgVelNedCov(msg) => msg.encoded_len(),
            Sbp::MsgVelBody(msg) => msg.encoded_len(),
            Sbp::MsgPosEcefCov(msg) => msg.encoded_len(),
            Sbp::MsgVelEcefCov(msg) => msg.encoded_len(),
            Sbp::MsgProtectionLevelDepA(msg) => msg.encoded_len(),
            Sbp::MsgProtectionLevel(msg) => msg.encoded_len(),
            Sbp::MsgPosLlhAcc(msg) => msg.encoded_len(),
            Sbp::MsgVelCog(msg) => msg.encoded_len(),
            Sbp::MsgOrientQuat(msg) => msg.encoded_len(),
            Sbp::MsgOrientEuler(msg) => msg.encoded_len(),
            Sbp::MsgAngularRate(msg) => msg.encoded_len(),
            Sbp::MsgPosEcefGnss(msg) => msg.encoded_len(),
            Sbp::MsgPosLlhGnss(msg) => msg.encoded_len(),
            Sbp::MsgVelEcefGnss(msg) => msg.encoded_len(),
            Sbp::MsgVelNedGnss(msg) => msg.encoded_len(),
            Sbp::MsgPosLlhCovGnss(msg) => msg.encoded_len(),
            Sbp::MsgVelNedCovGnss(msg) => msg.encoded_len(),
            Sbp::MsgPosEcefCovGnss(msg) => msg.encoded_len(),
            Sbp::MsgVelEcefCovGnss(msg) => msg.encoded_len(),
            Sbp::MsgNdbEvent(msg) => msg.encoded_len(),
            Sbp::MsgLog(msg) => msg.encoded_len(),
            Sbp::MsgFwd(msg) => msg.encoded_len(),
            Sbp::MsgSsrOrbitClockDepA(msg) => msg.encoded_len(),
            Sbp::MsgSsrOrbitClock(msg) => msg.encoded_len(),
            Sbp::MsgSsrCodeBiases(msg) => msg.encoded_len(),
            Sbp::MsgSsrPhaseBiases(msg) => msg.encoded_len(),
            Sbp::MsgSsrStecCorrectionDepA(msg) => msg.encoded_len(),
            Sbp::MsgSsrGriddedCorrectionNoStdDepA(msg) => msg.encoded_len(),
            Sbp::MsgSsrGridDefinitionDepA(msg) => msg.encoded_len(),
            Sbp::MsgSsrTileDefinition(msg) => msg.encoded_len(),
            Sbp::MsgSsrGriddedCorrectionDepA(msg) => msg.encoded_len(),
            Sbp::MsgSsrStecCorrection(msg) => msg.encoded_len(),
            Sbp::MsgSsrGriddedCorrection(msg) => msg.encoded_len(),
            Sbp::MsgSsrSatelliteApc(msg) => msg.encoded_len(),
            Sbp::MsgOsr(msg) => msg.encoded_len(),
            Sbp::MsgUserData(msg) => msg.encoded_len(),
            Sbp::MsgImuRaw(msg) => msg.encoded_len(),
            Sbp::MsgImuAux(msg) => msg.encoded_len(),
            Sbp::MsgMagRaw(msg) => msg.encoded_len(),
            Sbp::MsgOdometry(msg) => msg.encoded_len(),
            Sbp::MsgWheeltick(msg) => msg.encoded_len(),
            Sbp::MsgFileioConfigReq(msg) => msg.encoded_len(),
            Sbp::MsgFileioConfigResp(msg) => msg.encoded_len(),
            Sbp::MsgSbasRaw(msg) => msg.encoded_len(),
            Sbp::MsgLinuxCpuStateDepA(msg) => msg.encoded_len(),
            Sbp::MsgLinuxMemStateDepA(msg) => msg.encoded_len(),
            Sbp::MsgLinuxSysStateDepA(msg) => msg.encoded_len(),
            Sbp::MsgLinuxProcessSocketCounts(msg) => msg.encoded_len(),
            Sbp::MsgLinuxProcessSocketQueues(msg) => msg.encoded_len(),
            Sbp::MsgLinuxSocketUsage(msg) => msg.encoded_len(),
            Sbp::MsgLinuxProcessFdCount(msg) => msg.encoded_len(),
            Sbp::MsgLinuxProcessFdSummary(msg) => msg.encoded_len(),
            Sbp::MsgLinuxCpuState(msg) => msg.encoded_len(),
            Sbp::MsgLinuxMemState(msg) => msg.encoded_len(),
            Sbp::MsgLinuxSysState(msg) => msg.encoded_len(),
            Sbp::MsgStartup(msg) => msg.encoded_len(),
            Sbp::MsgDgnssStatus(msg) => msg.encoded_len(),
            Sbp::MsgInsStatus(msg) => msg.encoded_len(),
            Sbp::MsgCsacTelemetry(msg) => msg.encoded_len(),
            Sbp::MsgCsacTelemetryLabels(msg) => msg.encoded_len(),
            Sbp::MsgInsUpdates(msg) => msg.encoded_len(),
            Sbp::MsgGnssTimeOffset(msg) => msg.encoded_len(),
            Sbp::MsgPpsTime(msg) => msg.encoded_len(),
            Sbp::MsgGroupMeta(msg) => msg.encoded_len(),
            Sbp::MsgSolnMeta(msg) => msg.encoded_len(),
            Sbp::MsgSolnMetaDepA(msg) => msg.encoded_len(),
            Sbp::MsgStatusReport(msg) => msg.encoded_len(),
            Sbp::MsgHeartbeat(msg) => msg.encoded_len(),
            Sbp::Unknown(msg) => msg.encoded_len(),
        }
    }

    #[cfg(feature = "swiftnav")]
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
            Sbp::MsgVelCog(msg) => msg.gps_time(),
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

impl WireFormat for Sbp {
    const MIN_LEN: usize = crate::MAX_FRAME_LEN;

    fn parse_unchecked<B: Buf>(_: &mut B) -> Self {
        unimplemented!("Sbp must be parsed with Sbp::from_frame");
    }

    fn write<B: BufMut>(&self, buf: &mut B) {
        match self {
            Sbp::MsgPrintDep(msg) => WireFormat::write(msg, buf),
            Sbp::MsgTrackingStateDetailedDep(msg) => WireFormat::write(msg, buf),
            Sbp::MsgTrackingStateDepB(msg) => WireFormat::write(msg, buf),
            Sbp::MsgAcqResultDepB(msg) => WireFormat::write(msg, buf),
            Sbp::MsgAcqResultDepA(msg) => WireFormat::write(msg, buf),
            Sbp::MsgTrackingStateDepA(msg) => WireFormat::write(msg, buf),
            Sbp::MsgThreadState(msg) => WireFormat::write(msg, buf),
            Sbp::MsgUartStateDepa(msg) => WireFormat::write(msg, buf),
            Sbp::MsgIarState(msg) => WireFormat::write(msg, buf),
            Sbp::MsgEphemerisDepA(msg) => WireFormat::write(msg, buf),
            Sbp::MsgMaskSatelliteDep(msg) => WireFormat::write(msg, buf),
            Sbp::MsgTrackingIqDepA(msg) => WireFormat::write(msg, buf),
            Sbp::MsgUartState(msg) => WireFormat::write(msg, buf),
            Sbp::MsgAcqSvProfileDep(msg) => WireFormat::write(msg, buf),
            Sbp::MsgAcqResultDepC(msg) => WireFormat::write(msg, buf),
            Sbp::MsgTrackingStateDetailedDepA(msg) => WireFormat::write(msg, buf),
            Sbp::MsgResetFilters(msg) => WireFormat::write(msg, buf),
            Sbp::MsgInitBaseDep(msg) => WireFormat::write(msg, buf),
            Sbp::MsgMaskSatellite(msg) => WireFormat::write(msg, buf),
            Sbp::MsgTrackingIqDepB(msg) => WireFormat::write(msg, buf),
            Sbp::MsgTrackingIq(msg) => WireFormat::write(msg, buf),
            Sbp::MsgAcqSvProfile(msg) => WireFormat::write(msg, buf),
            Sbp::MsgAcqResult(msg) => WireFormat::write(msg, buf),
            Sbp::MsgTrackingState(msg) => WireFormat::write(msg, buf),
            Sbp::MsgObsDepB(msg) => WireFormat::write(msg, buf),
            Sbp::MsgBasePosLlh(msg) => WireFormat::write(msg, buf),
            Sbp::MsgObsDepA(msg) => WireFormat::write(msg, buf),
            Sbp::MsgEphemerisDepB(msg) => WireFormat::write(msg, buf),
            Sbp::MsgEphemerisDepC(msg) => WireFormat::write(msg, buf),
            Sbp::MsgBasePosEcef(msg) => WireFormat::write(msg, buf),
            Sbp::MsgObsDepC(msg) => WireFormat::write(msg, buf),
            Sbp::MsgObs(msg) => WireFormat::write(msg, buf),
            Sbp::MsgSpecanDep(msg) => WireFormat::write(msg, buf),
            Sbp::MsgSpecan(msg) => WireFormat::write(msg, buf),
            Sbp::MsgMeasurementState(msg) => WireFormat::write(msg, buf),
            Sbp::MsgSetTime(msg) => WireFormat::write(msg, buf),
            Sbp::MsgAlmanac(msg) => WireFormat::write(msg, buf),
            Sbp::MsgAlmanacGpsDep(msg) => WireFormat::write(msg, buf),
            Sbp::MsgAlmanacGloDep(msg) => WireFormat::write(msg, buf),
            Sbp::MsgAlmanacGps(msg) => WireFormat::write(msg, buf),
            Sbp::MsgAlmanacGlo(msg) => WireFormat::write(msg, buf),
            Sbp::MsgGloBiases(msg) => WireFormat::write(msg, buf),
            Sbp::MsgEphemerisDepD(msg) => WireFormat::write(msg, buf),
            Sbp::MsgEphemerisGpsDepE(msg) => WireFormat::write(msg, buf),
            Sbp::MsgEphemerisSbasDepA(msg) => WireFormat::write(msg, buf),
            Sbp::MsgEphemerisGloDepA(msg) => WireFormat::write(msg, buf),
            Sbp::MsgEphemerisSbasDepB(msg) => WireFormat::write(msg, buf),
            Sbp::MsgEphemerisGloDepB(msg) => WireFormat::write(msg, buf),
            Sbp::MsgEphemerisGpsDepF(msg) => WireFormat::write(msg, buf),
            Sbp::MsgEphemerisGloDepC(msg) => WireFormat::write(msg, buf),
            Sbp::MsgEphemerisGloDepD(msg) => WireFormat::write(msg, buf),
            Sbp::MsgEphemerisBds(msg) => WireFormat::write(msg, buf),
            Sbp::MsgEphemerisGps(msg) => WireFormat::write(msg, buf),
            Sbp::MsgEphemerisGlo(msg) => WireFormat::write(msg, buf),
            Sbp::MsgEphemerisSbas(msg) => WireFormat::write(msg, buf),
            Sbp::MsgEphemerisGal(msg) => WireFormat::write(msg, buf),
            Sbp::MsgEphemerisQzss(msg) => WireFormat::write(msg, buf),
            Sbp::MsgIono(msg) => WireFormat::write(msg, buf),
            Sbp::MsgSvConfigurationGpsDep(msg) => WireFormat::write(msg, buf),
            Sbp::MsgGroupDelayDepA(msg) => WireFormat::write(msg, buf),
            Sbp::MsgGroupDelayDepB(msg) => WireFormat::write(msg, buf),
            Sbp::MsgGroupDelay(msg) => WireFormat::write(msg, buf),
            Sbp::MsgEphemerisGalDepA(msg) => WireFormat::write(msg, buf),
            Sbp::MsgGnssCapb(msg) => WireFormat::write(msg, buf),
            Sbp::MsgSvAzEl(msg) => WireFormat::write(msg, buf),
            Sbp::MsgSettingsWrite(msg) => WireFormat::write(msg, buf),
            Sbp::MsgSettingsSave(msg) => WireFormat::write(msg, buf),
            Sbp::MsgSettingsReadByIndexReq(msg) => WireFormat::write(msg, buf),
            Sbp::MsgFileioReadResp(msg) => WireFormat::write(msg, buf),
            Sbp::MsgSettingsReadReq(msg) => WireFormat::write(msg, buf),
            Sbp::MsgSettingsReadResp(msg) => WireFormat::write(msg, buf),
            Sbp::MsgSettingsReadByIndexDone(msg) => WireFormat::write(msg, buf),
            Sbp::MsgSettingsReadByIndexResp(msg) => WireFormat::write(msg, buf),
            Sbp::MsgFileioReadReq(msg) => WireFormat::write(msg, buf),
            Sbp::MsgFileioReadDirReq(msg) => WireFormat::write(msg, buf),
            Sbp::MsgFileioReadDirResp(msg) => WireFormat::write(msg, buf),
            Sbp::MsgFileioWriteResp(msg) => WireFormat::write(msg, buf),
            Sbp::MsgFileioRemove(msg) => WireFormat::write(msg, buf),
            Sbp::MsgFileioWriteReq(msg) => WireFormat::write(msg, buf),
            Sbp::MsgSettingsRegister(msg) => WireFormat::write(msg, buf),
            Sbp::MsgSettingsWriteResp(msg) => WireFormat::write(msg, buf),
            Sbp::MsgBootloaderHandshakeDepA(msg) => WireFormat::write(msg, buf),
            Sbp::MsgBootloaderJumpToApp(msg) => WireFormat::write(msg, buf),
            Sbp::MsgResetDep(msg) => WireFormat::write(msg, buf),
            Sbp::MsgBootloaderHandshakeReq(msg) => WireFormat::write(msg, buf),
            Sbp::MsgBootloaderHandshakeResp(msg) => WireFormat::write(msg, buf),
            Sbp::MsgDeviceMonitor(msg) => WireFormat::write(msg, buf),
            Sbp::MsgReset(msg) => WireFormat::write(msg, buf),
            Sbp::MsgCommandReq(msg) => WireFormat::write(msg, buf),
            Sbp::MsgCommandResp(msg) => WireFormat::write(msg, buf),
            Sbp::MsgNetworkStateReq(msg) => WireFormat::write(msg, buf),
            Sbp::MsgNetworkStateResp(msg) => WireFormat::write(msg, buf),
            Sbp::MsgCommandOutput(msg) => WireFormat::write(msg, buf),
            Sbp::MsgNetworkBandwidthUsage(msg) => WireFormat::write(msg, buf),
            Sbp::MsgCellModemStatus(msg) => WireFormat::write(msg, buf),
            Sbp::MsgFrontEndGain(msg) => WireFormat::write(msg, buf),
            Sbp::MsgCwResults(msg) => WireFormat::write(msg, buf),
            Sbp::MsgCwStart(msg) => WireFormat::write(msg, buf),
            Sbp::MsgNapDeviceDnaResp(msg) => WireFormat::write(msg, buf),
            Sbp::MsgNapDeviceDnaReq(msg) => WireFormat::write(msg, buf),
            Sbp::MsgFlashDone(msg) => WireFormat::write(msg, buf),
            Sbp::MsgFlashReadResp(msg) => WireFormat::write(msg, buf),
            Sbp::MsgFlashErase(msg) => WireFormat::write(msg, buf),
            Sbp::MsgStmFlashLockSector(msg) => WireFormat::write(msg, buf),
            Sbp::MsgStmFlashUnlockSector(msg) => WireFormat::write(msg, buf),
            Sbp::MsgStmUniqueIdResp(msg) => WireFormat::write(msg, buf),
            Sbp::MsgFlashProgram(msg) => WireFormat::write(msg, buf),
            Sbp::MsgFlashReadReq(msg) => WireFormat::write(msg, buf),
            Sbp::MsgStmUniqueIdReq(msg) => WireFormat::write(msg, buf),
            Sbp::MsgM25FlashWriteStatus(msg) => WireFormat::write(msg, buf),
            Sbp::MsgGpsTimeDepA(msg) => WireFormat::write(msg, buf),
            Sbp::MsgExtEvent(msg) => WireFormat::write(msg, buf),
            Sbp::MsgGpsTime(msg) => WireFormat::write(msg, buf),
            Sbp::MsgUtcTime(msg) => WireFormat::write(msg, buf),
            Sbp::MsgGpsTimeGnss(msg) => WireFormat::write(msg, buf),
            Sbp::MsgUtcTimeGnss(msg) => WireFormat::write(msg, buf),
            Sbp::MsgSettingsRegisterResp(msg) => WireFormat::write(msg, buf),
            Sbp::MsgPosEcefDepA(msg) => WireFormat::write(msg, buf),
            Sbp::MsgPosLlhDepA(msg) => WireFormat::write(msg, buf),
            Sbp::MsgBaselineEcefDepA(msg) => WireFormat::write(msg, buf),
            Sbp::MsgBaselineNedDepA(msg) => WireFormat::write(msg, buf),
            Sbp::MsgVelEcefDepA(msg) => WireFormat::write(msg, buf),
            Sbp::MsgVelNedDepA(msg) => WireFormat::write(msg, buf),
            Sbp::MsgDopsDepA(msg) => WireFormat::write(msg, buf),
            Sbp::MsgBaselineHeadingDepA(msg) => WireFormat::write(msg, buf),
            Sbp::MsgDops(msg) => WireFormat::write(msg, buf),
            Sbp::MsgPosEcef(msg) => WireFormat::write(msg, buf),
            Sbp::MsgPosLlh(msg) => WireFormat::write(msg, buf),
            Sbp::MsgBaselineEcef(msg) => WireFormat::write(msg, buf),
            Sbp::MsgBaselineNed(msg) => WireFormat::write(msg, buf),
            Sbp::MsgVelEcef(msg) => WireFormat::write(msg, buf),
            Sbp::MsgVelNed(msg) => WireFormat::write(msg, buf),
            Sbp::MsgBaselineHeading(msg) => WireFormat::write(msg, buf),
            Sbp::MsgAgeCorrections(msg) => WireFormat::write(msg, buf),
            Sbp::MsgPosLlhCov(msg) => WireFormat::write(msg, buf),
            Sbp::MsgVelNedCov(msg) => WireFormat::write(msg, buf),
            Sbp::MsgVelBody(msg) => WireFormat::write(msg, buf),
            Sbp::MsgPosEcefCov(msg) => WireFormat::write(msg, buf),
            Sbp::MsgVelEcefCov(msg) => WireFormat::write(msg, buf),
            Sbp::MsgProtectionLevelDepA(msg) => WireFormat::write(msg, buf),
            Sbp::MsgProtectionLevel(msg) => WireFormat::write(msg, buf),
            Sbp::MsgPosLlhAcc(msg) => WireFormat::write(msg, buf),
            Sbp::MsgVelCog(msg) => WireFormat::write(msg, buf),
            Sbp::MsgOrientQuat(msg) => WireFormat::write(msg, buf),
            Sbp::MsgOrientEuler(msg) => WireFormat::write(msg, buf),
            Sbp::MsgAngularRate(msg) => WireFormat::write(msg, buf),
            Sbp::MsgPosEcefGnss(msg) => WireFormat::write(msg, buf),
            Sbp::MsgPosLlhGnss(msg) => WireFormat::write(msg, buf),
            Sbp::MsgVelEcefGnss(msg) => WireFormat::write(msg, buf),
            Sbp::MsgVelNedGnss(msg) => WireFormat::write(msg, buf),
            Sbp::MsgPosLlhCovGnss(msg) => WireFormat::write(msg, buf),
            Sbp::MsgVelNedCovGnss(msg) => WireFormat::write(msg, buf),
            Sbp::MsgPosEcefCovGnss(msg) => WireFormat::write(msg, buf),
            Sbp::MsgVelEcefCovGnss(msg) => WireFormat::write(msg, buf),
            Sbp::MsgNdbEvent(msg) => WireFormat::write(msg, buf),
            Sbp::MsgLog(msg) => WireFormat::write(msg, buf),
            Sbp::MsgFwd(msg) => WireFormat::write(msg, buf),
            Sbp::MsgSsrOrbitClockDepA(msg) => WireFormat::write(msg, buf),
            Sbp::MsgSsrOrbitClock(msg) => WireFormat::write(msg, buf),
            Sbp::MsgSsrCodeBiases(msg) => WireFormat::write(msg, buf),
            Sbp::MsgSsrPhaseBiases(msg) => WireFormat::write(msg, buf),
            Sbp::MsgSsrStecCorrectionDepA(msg) => WireFormat::write(msg, buf),
            Sbp::MsgSsrGriddedCorrectionNoStdDepA(msg) => WireFormat::write(msg, buf),
            Sbp::MsgSsrGridDefinitionDepA(msg) => WireFormat::write(msg, buf),
            Sbp::MsgSsrTileDefinition(msg) => WireFormat::write(msg, buf),
            Sbp::MsgSsrGriddedCorrectionDepA(msg) => WireFormat::write(msg, buf),
            Sbp::MsgSsrStecCorrection(msg) => WireFormat::write(msg, buf),
            Sbp::MsgSsrGriddedCorrection(msg) => WireFormat::write(msg, buf),
            Sbp::MsgSsrSatelliteApc(msg) => WireFormat::write(msg, buf),
            Sbp::MsgOsr(msg) => WireFormat::write(msg, buf),
            Sbp::MsgUserData(msg) => WireFormat::write(msg, buf),
            Sbp::MsgImuRaw(msg) => WireFormat::write(msg, buf),
            Sbp::MsgImuAux(msg) => WireFormat::write(msg, buf),
            Sbp::MsgMagRaw(msg) => WireFormat::write(msg, buf),
            Sbp::MsgOdometry(msg) => WireFormat::write(msg, buf),
            Sbp::MsgWheeltick(msg) => WireFormat::write(msg, buf),
            Sbp::MsgFileioConfigReq(msg) => WireFormat::write(msg, buf),
            Sbp::MsgFileioConfigResp(msg) => WireFormat::write(msg, buf),
            Sbp::MsgSbasRaw(msg) => WireFormat::write(msg, buf),
            Sbp::MsgLinuxCpuStateDepA(msg) => WireFormat::write(msg, buf),
            Sbp::MsgLinuxMemStateDepA(msg) => WireFormat::write(msg, buf),
            Sbp::MsgLinuxSysStateDepA(msg) => WireFormat::write(msg, buf),
            Sbp::MsgLinuxProcessSocketCounts(msg) => WireFormat::write(msg, buf),
            Sbp::MsgLinuxProcessSocketQueues(msg) => WireFormat::write(msg, buf),
            Sbp::MsgLinuxSocketUsage(msg) => WireFormat::write(msg, buf),
            Sbp::MsgLinuxProcessFdCount(msg) => WireFormat::write(msg, buf),
            Sbp::MsgLinuxProcessFdSummary(msg) => WireFormat::write(msg, buf),
            Sbp::MsgLinuxCpuState(msg) => WireFormat::write(msg, buf),
            Sbp::MsgLinuxMemState(msg) => WireFormat::write(msg, buf),
            Sbp::MsgLinuxSysState(msg) => WireFormat::write(msg, buf),
            Sbp::MsgStartup(msg) => WireFormat::write(msg, buf),
            Sbp::MsgDgnssStatus(msg) => WireFormat::write(msg, buf),
            Sbp::MsgInsStatus(msg) => WireFormat::write(msg, buf),
            Sbp::MsgCsacTelemetry(msg) => WireFormat::write(msg, buf),
            Sbp::MsgCsacTelemetryLabels(msg) => WireFormat::write(msg, buf),
            Sbp::MsgInsUpdates(msg) => WireFormat::write(msg, buf),
            Sbp::MsgGnssTimeOffset(msg) => WireFormat::write(msg, buf),
            Sbp::MsgPpsTime(msg) => WireFormat::write(msg, buf),
            Sbp::MsgGroupMeta(msg) => WireFormat::write(msg, buf),
            Sbp::MsgSolnMeta(msg) => WireFormat::write(msg, buf),
            Sbp::MsgSolnMetaDepA(msg) => WireFormat::write(msg, buf),
            Sbp::MsgStatusReport(msg) => WireFormat::write(msg, buf),
            Sbp::MsgHeartbeat(msg) => WireFormat::write(msg, buf),
            Sbp::Unknown(msg) => WireFormat::write(msg, buf),
        }
    }

    fn len(&self) -> usize {
        match self {
            Sbp::MsgPrintDep(msg) => WireFormat::len(msg),
            Sbp::MsgTrackingStateDetailedDep(msg) => WireFormat::len(msg),
            Sbp::MsgTrackingStateDepB(msg) => WireFormat::len(msg),
            Sbp::MsgAcqResultDepB(msg) => WireFormat::len(msg),
            Sbp::MsgAcqResultDepA(msg) => WireFormat::len(msg),
            Sbp::MsgTrackingStateDepA(msg) => WireFormat::len(msg),
            Sbp::MsgThreadState(msg) => WireFormat::len(msg),
            Sbp::MsgUartStateDepa(msg) => WireFormat::len(msg),
            Sbp::MsgIarState(msg) => WireFormat::len(msg),
            Sbp::MsgEphemerisDepA(msg) => WireFormat::len(msg),
            Sbp::MsgMaskSatelliteDep(msg) => WireFormat::len(msg),
            Sbp::MsgTrackingIqDepA(msg) => WireFormat::len(msg),
            Sbp::MsgUartState(msg) => WireFormat::len(msg),
            Sbp::MsgAcqSvProfileDep(msg) => WireFormat::len(msg),
            Sbp::MsgAcqResultDepC(msg) => WireFormat::len(msg),
            Sbp::MsgTrackingStateDetailedDepA(msg) => WireFormat::len(msg),
            Sbp::MsgResetFilters(msg) => WireFormat::len(msg),
            Sbp::MsgInitBaseDep(msg) => WireFormat::len(msg),
            Sbp::MsgMaskSatellite(msg) => WireFormat::len(msg),
            Sbp::MsgTrackingIqDepB(msg) => WireFormat::len(msg),
            Sbp::MsgTrackingIq(msg) => WireFormat::len(msg),
            Sbp::MsgAcqSvProfile(msg) => WireFormat::len(msg),
            Sbp::MsgAcqResult(msg) => WireFormat::len(msg),
            Sbp::MsgTrackingState(msg) => WireFormat::len(msg),
            Sbp::MsgObsDepB(msg) => WireFormat::len(msg),
            Sbp::MsgBasePosLlh(msg) => WireFormat::len(msg),
            Sbp::MsgObsDepA(msg) => WireFormat::len(msg),
            Sbp::MsgEphemerisDepB(msg) => WireFormat::len(msg),
            Sbp::MsgEphemerisDepC(msg) => WireFormat::len(msg),
            Sbp::MsgBasePosEcef(msg) => WireFormat::len(msg),
            Sbp::MsgObsDepC(msg) => WireFormat::len(msg),
            Sbp::MsgObs(msg) => WireFormat::len(msg),
            Sbp::MsgSpecanDep(msg) => WireFormat::len(msg),
            Sbp::MsgSpecan(msg) => WireFormat::len(msg),
            Sbp::MsgMeasurementState(msg) => WireFormat::len(msg),
            Sbp::MsgSetTime(msg) => WireFormat::len(msg),
            Sbp::MsgAlmanac(msg) => WireFormat::len(msg),
            Sbp::MsgAlmanacGpsDep(msg) => WireFormat::len(msg),
            Sbp::MsgAlmanacGloDep(msg) => WireFormat::len(msg),
            Sbp::MsgAlmanacGps(msg) => WireFormat::len(msg),
            Sbp::MsgAlmanacGlo(msg) => WireFormat::len(msg),
            Sbp::MsgGloBiases(msg) => WireFormat::len(msg),
            Sbp::MsgEphemerisDepD(msg) => WireFormat::len(msg),
            Sbp::MsgEphemerisGpsDepE(msg) => WireFormat::len(msg),
            Sbp::MsgEphemerisSbasDepA(msg) => WireFormat::len(msg),
            Sbp::MsgEphemerisGloDepA(msg) => WireFormat::len(msg),
            Sbp::MsgEphemerisSbasDepB(msg) => WireFormat::len(msg),
            Sbp::MsgEphemerisGloDepB(msg) => WireFormat::len(msg),
            Sbp::MsgEphemerisGpsDepF(msg) => WireFormat::len(msg),
            Sbp::MsgEphemerisGloDepC(msg) => WireFormat::len(msg),
            Sbp::MsgEphemerisGloDepD(msg) => WireFormat::len(msg),
            Sbp::MsgEphemerisBds(msg) => WireFormat::len(msg),
            Sbp::MsgEphemerisGps(msg) => WireFormat::len(msg),
            Sbp::MsgEphemerisGlo(msg) => WireFormat::len(msg),
            Sbp::MsgEphemerisSbas(msg) => WireFormat::len(msg),
            Sbp::MsgEphemerisGal(msg) => WireFormat::len(msg),
            Sbp::MsgEphemerisQzss(msg) => WireFormat::len(msg),
            Sbp::MsgIono(msg) => WireFormat::len(msg),
            Sbp::MsgSvConfigurationGpsDep(msg) => WireFormat::len(msg),
            Sbp::MsgGroupDelayDepA(msg) => WireFormat::len(msg),
            Sbp::MsgGroupDelayDepB(msg) => WireFormat::len(msg),
            Sbp::MsgGroupDelay(msg) => WireFormat::len(msg),
            Sbp::MsgEphemerisGalDepA(msg) => WireFormat::len(msg),
            Sbp::MsgGnssCapb(msg) => WireFormat::len(msg),
            Sbp::MsgSvAzEl(msg) => WireFormat::len(msg),
            Sbp::MsgSettingsWrite(msg) => WireFormat::len(msg),
            Sbp::MsgSettingsSave(msg) => WireFormat::len(msg),
            Sbp::MsgSettingsReadByIndexReq(msg) => WireFormat::len(msg),
            Sbp::MsgFileioReadResp(msg) => WireFormat::len(msg),
            Sbp::MsgSettingsReadReq(msg) => WireFormat::len(msg),
            Sbp::MsgSettingsReadResp(msg) => WireFormat::len(msg),
            Sbp::MsgSettingsReadByIndexDone(msg) => WireFormat::len(msg),
            Sbp::MsgSettingsReadByIndexResp(msg) => WireFormat::len(msg),
            Sbp::MsgFileioReadReq(msg) => WireFormat::len(msg),
            Sbp::MsgFileioReadDirReq(msg) => WireFormat::len(msg),
            Sbp::MsgFileioReadDirResp(msg) => WireFormat::len(msg),
            Sbp::MsgFileioWriteResp(msg) => WireFormat::len(msg),
            Sbp::MsgFileioRemove(msg) => WireFormat::len(msg),
            Sbp::MsgFileioWriteReq(msg) => WireFormat::len(msg),
            Sbp::MsgSettingsRegister(msg) => WireFormat::len(msg),
            Sbp::MsgSettingsWriteResp(msg) => WireFormat::len(msg),
            Sbp::MsgBootloaderHandshakeDepA(msg) => WireFormat::len(msg),
            Sbp::MsgBootloaderJumpToApp(msg) => WireFormat::len(msg),
            Sbp::MsgResetDep(msg) => WireFormat::len(msg),
            Sbp::MsgBootloaderHandshakeReq(msg) => WireFormat::len(msg),
            Sbp::MsgBootloaderHandshakeResp(msg) => WireFormat::len(msg),
            Sbp::MsgDeviceMonitor(msg) => WireFormat::len(msg),
            Sbp::MsgReset(msg) => WireFormat::len(msg),
            Sbp::MsgCommandReq(msg) => WireFormat::len(msg),
            Sbp::MsgCommandResp(msg) => WireFormat::len(msg),
            Sbp::MsgNetworkStateReq(msg) => WireFormat::len(msg),
            Sbp::MsgNetworkStateResp(msg) => WireFormat::len(msg),
            Sbp::MsgCommandOutput(msg) => WireFormat::len(msg),
            Sbp::MsgNetworkBandwidthUsage(msg) => WireFormat::len(msg),
            Sbp::MsgCellModemStatus(msg) => WireFormat::len(msg),
            Sbp::MsgFrontEndGain(msg) => WireFormat::len(msg),
            Sbp::MsgCwResults(msg) => WireFormat::len(msg),
            Sbp::MsgCwStart(msg) => WireFormat::len(msg),
            Sbp::MsgNapDeviceDnaResp(msg) => WireFormat::len(msg),
            Sbp::MsgNapDeviceDnaReq(msg) => WireFormat::len(msg),
            Sbp::MsgFlashDone(msg) => WireFormat::len(msg),
            Sbp::MsgFlashReadResp(msg) => WireFormat::len(msg),
            Sbp::MsgFlashErase(msg) => WireFormat::len(msg),
            Sbp::MsgStmFlashLockSector(msg) => WireFormat::len(msg),
            Sbp::MsgStmFlashUnlockSector(msg) => WireFormat::len(msg),
            Sbp::MsgStmUniqueIdResp(msg) => WireFormat::len(msg),
            Sbp::MsgFlashProgram(msg) => WireFormat::len(msg),
            Sbp::MsgFlashReadReq(msg) => WireFormat::len(msg),
            Sbp::MsgStmUniqueIdReq(msg) => WireFormat::len(msg),
            Sbp::MsgM25FlashWriteStatus(msg) => WireFormat::len(msg),
            Sbp::MsgGpsTimeDepA(msg) => WireFormat::len(msg),
            Sbp::MsgExtEvent(msg) => WireFormat::len(msg),
            Sbp::MsgGpsTime(msg) => WireFormat::len(msg),
            Sbp::MsgUtcTime(msg) => WireFormat::len(msg),
            Sbp::MsgGpsTimeGnss(msg) => WireFormat::len(msg),
            Sbp::MsgUtcTimeGnss(msg) => WireFormat::len(msg),
            Sbp::MsgSettingsRegisterResp(msg) => WireFormat::len(msg),
            Sbp::MsgPosEcefDepA(msg) => WireFormat::len(msg),
            Sbp::MsgPosLlhDepA(msg) => WireFormat::len(msg),
            Sbp::MsgBaselineEcefDepA(msg) => WireFormat::len(msg),
            Sbp::MsgBaselineNedDepA(msg) => WireFormat::len(msg),
            Sbp::MsgVelEcefDepA(msg) => WireFormat::len(msg),
            Sbp::MsgVelNedDepA(msg) => WireFormat::len(msg),
            Sbp::MsgDopsDepA(msg) => WireFormat::len(msg),
            Sbp::MsgBaselineHeadingDepA(msg) => WireFormat::len(msg),
            Sbp::MsgDops(msg) => WireFormat::len(msg),
            Sbp::MsgPosEcef(msg) => WireFormat::len(msg),
            Sbp::MsgPosLlh(msg) => WireFormat::len(msg),
            Sbp::MsgBaselineEcef(msg) => WireFormat::len(msg),
            Sbp::MsgBaselineNed(msg) => WireFormat::len(msg),
            Sbp::MsgVelEcef(msg) => WireFormat::len(msg),
            Sbp::MsgVelNed(msg) => WireFormat::len(msg),
            Sbp::MsgBaselineHeading(msg) => WireFormat::len(msg),
            Sbp::MsgAgeCorrections(msg) => WireFormat::len(msg),
            Sbp::MsgPosLlhCov(msg) => WireFormat::len(msg),
            Sbp::MsgVelNedCov(msg) => WireFormat::len(msg),
            Sbp::MsgVelBody(msg) => WireFormat::len(msg),
            Sbp::MsgPosEcefCov(msg) => WireFormat::len(msg),
            Sbp::MsgVelEcefCov(msg) => WireFormat::len(msg),
            Sbp::MsgProtectionLevelDepA(msg) => WireFormat::len(msg),
            Sbp::MsgProtectionLevel(msg) => WireFormat::len(msg),
            Sbp::MsgPosLlhAcc(msg) => WireFormat::len(msg),
            Sbp::MsgVelCog(msg) => WireFormat::len(msg),
            Sbp::MsgOrientQuat(msg) => WireFormat::len(msg),
            Sbp::MsgOrientEuler(msg) => WireFormat::len(msg),
            Sbp::MsgAngularRate(msg) => WireFormat::len(msg),
            Sbp::MsgPosEcefGnss(msg) => WireFormat::len(msg),
            Sbp::MsgPosLlhGnss(msg) => WireFormat::len(msg),
            Sbp::MsgVelEcefGnss(msg) => WireFormat::len(msg),
            Sbp::MsgVelNedGnss(msg) => WireFormat::len(msg),
            Sbp::MsgPosLlhCovGnss(msg) => WireFormat::len(msg),
            Sbp::MsgVelNedCovGnss(msg) => WireFormat::len(msg),
            Sbp::MsgPosEcefCovGnss(msg) => WireFormat::len(msg),
            Sbp::MsgVelEcefCovGnss(msg) => WireFormat::len(msg),
            Sbp::MsgNdbEvent(msg) => WireFormat::len(msg),
            Sbp::MsgLog(msg) => WireFormat::len(msg),
            Sbp::MsgFwd(msg) => WireFormat::len(msg),
            Sbp::MsgSsrOrbitClockDepA(msg) => WireFormat::len(msg),
            Sbp::MsgSsrOrbitClock(msg) => WireFormat::len(msg),
            Sbp::MsgSsrCodeBiases(msg) => WireFormat::len(msg),
            Sbp::MsgSsrPhaseBiases(msg) => WireFormat::len(msg),
            Sbp::MsgSsrStecCorrectionDepA(msg) => WireFormat::len(msg),
            Sbp::MsgSsrGriddedCorrectionNoStdDepA(msg) => WireFormat::len(msg),
            Sbp::MsgSsrGridDefinitionDepA(msg) => WireFormat::len(msg),
            Sbp::MsgSsrTileDefinition(msg) => WireFormat::len(msg),
            Sbp::MsgSsrGriddedCorrectionDepA(msg) => WireFormat::len(msg),
            Sbp::MsgSsrStecCorrection(msg) => WireFormat::len(msg),
            Sbp::MsgSsrGriddedCorrection(msg) => WireFormat::len(msg),
            Sbp::MsgSsrSatelliteApc(msg) => WireFormat::len(msg),
            Sbp::MsgOsr(msg) => WireFormat::len(msg),
            Sbp::MsgUserData(msg) => WireFormat::len(msg),
            Sbp::MsgImuRaw(msg) => WireFormat::len(msg),
            Sbp::MsgImuAux(msg) => WireFormat::len(msg),
            Sbp::MsgMagRaw(msg) => WireFormat::len(msg),
            Sbp::MsgOdometry(msg) => WireFormat::len(msg),
            Sbp::MsgWheeltick(msg) => WireFormat::len(msg),
            Sbp::MsgFileioConfigReq(msg) => WireFormat::len(msg),
            Sbp::MsgFileioConfigResp(msg) => WireFormat::len(msg),
            Sbp::MsgSbasRaw(msg) => WireFormat::len(msg),
            Sbp::MsgLinuxCpuStateDepA(msg) => WireFormat::len(msg),
            Sbp::MsgLinuxMemStateDepA(msg) => WireFormat::len(msg),
            Sbp::MsgLinuxSysStateDepA(msg) => WireFormat::len(msg),
            Sbp::MsgLinuxProcessSocketCounts(msg) => WireFormat::len(msg),
            Sbp::MsgLinuxProcessSocketQueues(msg) => WireFormat::len(msg),
            Sbp::MsgLinuxSocketUsage(msg) => WireFormat::len(msg),
            Sbp::MsgLinuxProcessFdCount(msg) => WireFormat::len(msg),
            Sbp::MsgLinuxProcessFdSummary(msg) => WireFormat::len(msg),
            Sbp::MsgLinuxCpuState(msg) => WireFormat::len(msg),
            Sbp::MsgLinuxMemState(msg) => WireFormat::len(msg),
            Sbp::MsgLinuxSysState(msg) => WireFormat::len(msg),
            Sbp::MsgStartup(msg) => WireFormat::len(msg),
            Sbp::MsgDgnssStatus(msg) => WireFormat::len(msg),
            Sbp::MsgInsStatus(msg) => WireFormat::len(msg),
            Sbp::MsgCsacTelemetry(msg) => WireFormat::len(msg),
            Sbp::MsgCsacTelemetryLabels(msg) => WireFormat::len(msg),
            Sbp::MsgInsUpdates(msg) => WireFormat::len(msg),
            Sbp::MsgGnssTimeOffset(msg) => WireFormat::len(msg),
            Sbp::MsgPpsTime(msg) => WireFormat::len(msg),
            Sbp::MsgGroupMeta(msg) => WireFormat::len(msg),
            Sbp::MsgSolnMeta(msg) => WireFormat::len(msg),
            Sbp::MsgSolnMetaDepA(msg) => WireFormat::len(msg),
            Sbp::MsgStatusReport(msg) => WireFormat::len(msg),
            Sbp::MsgHeartbeat(msg) => WireFormat::len(msg),
            Sbp::Unknown(msg) => WireFormat::len(msg),
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

impl From<MsgVelCog> for Sbp {
    fn from(msg: MsgVelCog) -> Self {
        Sbp::MsgVelCog(msg)
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
