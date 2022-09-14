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
pub mod integrity;
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
pub mod signing;
pub mod solution_meta;
pub mod ssr;
pub mod system;
pub mod tracking;
pub mod unknown;
pub mod user;
pub mod vehicle;
use self::acquisition::msg_acq_result::MsgAcqResult;
use self::acquisition::msg_acq_result_dep_a::MsgAcqResultDepA;
use self::acquisition::msg_acq_result_dep_b::MsgAcqResultDepB;
use self::acquisition::msg_acq_result_dep_c::MsgAcqResultDepC;
use self::acquisition::msg_acq_sv_profile::MsgAcqSvProfile;
use self::acquisition::msg_acq_sv_profile_dep::MsgAcqSvProfileDep;
use self::bootload::msg_bootloader_handshake_dep_a::MsgBootloaderHandshakeDepA;
use self::bootload::msg_bootloader_handshake_req::MsgBootloaderHandshakeReq;
use self::bootload::msg_bootloader_handshake_resp::MsgBootloaderHandshakeResp;
use self::bootload::msg_bootloader_jump_to_app::MsgBootloaderJumpToApp;
use self::bootload::msg_nap_device_dna_req::MsgNapDeviceDnaReq;
use self::bootload::msg_nap_device_dna_resp::MsgNapDeviceDnaResp;
use self::ext_events::msg_ext_event::MsgExtEvent;
use self::file_io::msg_fileio_config_req::MsgFileioConfigReq;
use self::file_io::msg_fileio_config_resp::MsgFileioConfigResp;
use self::file_io::msg_fileio_read_dir_req::MsgFileioReadDirReq;
use self::file_io::msg_fileio_read_dir_resp::MsgFileioReadDirResp;
use self::file_io::msg_fileio_read_req::MsgFileioReadReq;
use self::file_io::msg_fileio_read_resp::MsgFileioReadResp;
use self::file_io::msg_fileio_remove::MsgFileioRemove;
use self::file_io::msg_fileio_write_req::MsgFileioWriteReq;
use self::file_io::msg_fileio_write_resp::MsgFileioWriteResp;
use self::flash::msg_flash_done::MsgFlashDone;
use self::flash::msg_flash_erase::MsgFlashErase;
use self::flash::msg_flash_program::MsgFlashProgram;
use self::flash::msg_flash_read_req::MsgFlashReadReq;
use self::flash::msg_flash_read_resp::MsgFlashReadResp;
use self::flash::msg_m25_flash_write_status::MsgM25FlashWriteStatus;
use self::flash::msg_stm_flash_lock_sector::MsgStmFlashLockSector;
use self::flash::msg_stm_flash_unlock_sector::MsgStmFlashUnlockSector;
use self::flash::msg_stm_unique_id_req::MsgStmUniqueIdReq;
use self::flash::msg_stm_unique_id_resp::MsgStmUniqueIdResp;
use self::imu::msg_imu_aux::MsgImuAux;
use self::imu::msg_imu_raw::MsgImuRaw;
use self::integrity::msg_ssr_flag_high_level::MsgSsrFlagHighLevel;
use self::integrity::msg_ssr_flag_iono_grid_point_sat_los::MsgSsrFlagIonoGridPointSatLos;
use self::integrity::msg_ssr_flag_iono_grid_points::MsgSsrFlagIonoGridPoints;
use self::integrity::msg_ssr_flag_iono_tile_sat_los::MsgSsrFlagIonoTileSatLos;
use self::integrity::msg_ssr_flag_satellites::MsgSsrFlagSatellites;
use self::integrity::msg_ssr_flag_tropo_grid_points::MsgSsrFlagTropoGridPoints;
use self::linux::msg_linux_cpu_state::MsgLinuxCpuState;
use self::linux::msg_linux_cpu_state_dep_a::MsgLinuxCpuStateDepA;
use self::linux::msg_linux_mem_state::MsgLinuxMemState;
use self::linux::msg_linux_mem_state_dep_a::MsgLinuxMemStateDepA;
use self::linux::msg_linux_process_fd_count::MsgLinuxProcessFdCount;
use self::linux::msg_linux_process_fd_summary::MsgLinuxProcessFdSummary;
use self::linux::msg_linux_process_socket_counts::MsgLinuxProcessSocketCounts;
use self::linux::msg_linux_process_socket_queues::MsgLinuxProcessSocketQueues;
use self::linux::msg_linux_socket_usage::MsgLinuxSocketUsage;
use self::linux::msg_linux_sys_state::MsgLinuxSysState;
use self::linux::msg_linux_sys_state_dep_a::MsgLinuxSysStateDepA;
use self::logging::msg_fwd::MsgFwd;
use self::logging::msg_log::MsgLog;
use self::logging::msg_print_dep::MsgPrintDep;
use self::mag::msg_mag_raw::MsgMagRaw;
use self::navigation::msg_age_corrections::MsgAgeCorrections;
use self::navigation::msg_baseline_ecef::MsgBaselineEcef;
use self::navigation::msg_baseline_ecef_dep_a::MsgBaselineEcefDepA;
use self::navigation::msg_baseline_heading_dep_a::MsgBaselineHeadingDepA;
use self::navigation::msg_baseline_ned::MsgBaselineNed;
use self::navigation::msg_baseline_ned_dep_a::MsgBaselineNedDepA;
use self::navigation::msg_dops::MsgDops;
use self::navigation::msg_dops_dep_a::MsgDopsDepA;
use self::navigation::msg_gps_time::MsgGpsTime;
use self::navigation::msg_gps_time_dep_a::MsgGpsTimeDepA;
use self::navigation::msg_gps_time_gnss::MsgGpsTimeGnss;
use self::navigation::msg_pos_ecef::MsgPosEcef;
use self::navigation::msg_pos_ecef_cov::MsgPosEcefCov;
use self::navigation::msg_pos_ecef_cov_gnss::MsgPosEcefCovGnss;
use self::navigation::msg_pos_ecef_dep_a::MsgPosEcefDepA;
use self::navigation::msg_pos_ecef_gnss::MsgPosEcefGnss;
use self::navigation::msg_pos_llh::MsgPosLlh;
use self::navigation::msg_pos_llh_acc::MsgPosLlhAcc;
use self::navigation::msg_pos_llh_cov::MsgPosLlhCov;
use self::navigation::msg_pos_llh_cov_gnss::MsgPosLlhCovGnss;
use self::navigation::msg_pos_llh_dep_a::MsgPosLlhDepA;
use self::navigation::msg_pos_llh_gnss::MsgPosLlhGnss;
use self::navigation::msg_protection_level::MsgProtectionLevel;
use self::navigation::msg_protection_level_dep_a::MsgProtectionLevelDepA;
use self::navigation::msg_reference_frame_param::MsgReferenceFrameParam;
use self::navigation::msg_utc_leap_second::MsgUtcLeapSecond;
use self::navigation::msg_utc_time::MsgUtcTime;
use self::navigation::msg_utc_time_gnss::MsgUtcTimeGnss;
use self::navigation::msg_vel_body::MsgVelBody;
use self::navigation::msg_vel_cog::MsgVelCog;
use self::navigation::msg_vel_ecef::MsgVelEcef;
use self::navigation::msg_vel_ecef_cov::MsgVelEcefCov;
use self::navigation::msg_vel_ecef_cov_gnss::MsgVelEcefCovGnss;
use self::navigation::msg_vel_ecef_dep_a::MsgVelEcefDepA;
use self::navigation::msg_vel_ecef_gnss::MsgVelEcefGnss;
use self::navigation::msg_vel_ned::MsgVelNed;
use self::navigation::msg_vel_ned_cov::MsgVelNedCov;
use self::navigation::msg_vel_ned_cov_gnss::MsgVelNedCovGnss;
use self::navigation::msg_vel_ned_dep_a::MsgVelNedDepA;
use self::navigation::msg_vel_ned_gnss::MsgVelNedGnss;
use self::ndb::msg_ndb_event::MsgNdbEvent;
use self::observation::msg_almanac_glo::MsgAlmanacGlo;
use self::observation::msg_almanac_glo_dep::MsgAlmanacGloDep;
use self::observation::msg_almanac_gps::MsgAlmanacGps;
use self::observation::msg_almanac_gps_dep::MsgAlmanacGpsDep;
use self::observation::msg_base_pos_ecef::MsgBasePosEcef;
use self::observation::msg_base_pos_llh::MsgBasePosLlh;
use self::observation::msg_ephemeris_bds::MsgEphemerisBds;
use self::observation::msg_ephemeris_dep_a::MsgEphemerisDepA;
use self::observation::msg_ephemeris_dep_b::MsgEphemerisDepB;
use self::observation::msg_ephemeris_dep_c::MsgEphemerisDepC;
use self::observation::msg_ephemeris_dep_d::MsgEphemerisDepD;
use self::observation::msg_ephemeris_gal::MsgEphemerisGal;
use self::observation::msg_ephemeris_gal_dep_a::MsgEphemerisGalDepA;
use self::observation::msg_ephemeris_glo::MsgEphemerisGlo;
use self::observation::msg_ephemeris_glo_dep_a::MsgEphemerisGloDepA;
use self::observation::msg_ephemeris_glo_dep_b::MsgEphemerisGloDepB;
use self::observation::msg_ephemeris_glo_dep_c::MsgEphemerisGloDepC;
use self::observation::msg_ephemeris_glo_dep_d::MsgEphemerisGloDepD;
use self::observation::msg_ephemeris_gps::MsgEphemerisGps;
use self::observation::msg_ephemeris_gps_dep_e::MsgEphemerisGpsDepE;
use self::observation::msg_ephemeris_gps_dep_f::MsgEphemerisGpsDepF;
use self::observation::msg_ephemeris_qzss::MsgEphemerisQzss;
use self::observation::msg_ephemeris_sbas::MsgEphemerisSbas;
use self::observation::msg_ephemeris_sbas_dep_a::MsgEphemerisSbasDepA;
use self::observation::msg_ephemeris_sbas_dep_b::MsgEphemerisSbasDepB;
use self::observation::msg_glo_biases::MsgGloBiases;
use self::observation::msg_gnss_capb::MsgGnssCapb;
use self::observation::msg_group_delay::MsgGroupDelay;
use self::observation::msg_group_delay_dep_a::MsgGroupDelayDepA;
use self::observation::msg_group_delay_dep_b::MsgGroupDelayDepB;
use self::observation::msg_iono::MsgIono;
use self::observation::msg_obs::MsgObs;
use self::observation::msg_obs_dep_a::MsgObsDepA;
use self::observation::msg_obs_dep_b::MsgObsDepB;
use self::observation::msg_obs_dep_c::MsgObsDepC;
use self::observation::msg_osr::MsgOsr;
use self::observation::msg_sv_az_el::MsgSvAzEl;
use self::observation::msg_sv_configuration_gps_dep::MsgSvConfigurationGpsDep;
use self::orientation::msg_angular_rate::MsgAngularRate;
use self::orientation::msg_baseline_heading::MsgBaselineHeading;
use self::orientation::msg_orient_euler::MsgOrientEuler;
use self::orientation::msg_orient_quat::MsgOrientQuat;
use self::piksi::msg_almanac::MsgAlmanac;
use self::piksi::msg_cell_modem_status::MsgCellModemStatus;
use self::piksi::msg_command_output::MsgCommandOutput;
use self::piksi::msg_command_req::MsgCommandReq;
use self::piksi::msg_command_resp::MsgCommandResp;
use self::piksi::msg_cw_results::MsgCwResults;
use self::piksi::msg_cw_start::MsgCwStart;
use self::piksi::msg_device_monitor::MsgDeviceMonitor;
use self::piksi::msg_front_end_gain::MsgFrontEndGain;
use self::piksi::msg_iar_state::MsgIarState;
use self::piksi::msg_init_base_dep::MsgInitBaseDep;
use self::piksi::msg_mask_satellite::MsgMaskSatellite;
use self::piksi::msg_mask_satellite_dep::MsgMaskSatelliteDep;
use self::piksi::msg_network_bandwidth_usage::MsgNetworkBandwidthUsage;
use self::piksi::msg_network_state_req::MsgNetworkStateReq;
use self::piksi::msg_network_state_resp::MsgNetworkStateResp;
use self::piksi::msg_reset::MsgReset;
use self::piksi::msg_reset_dep::MsgResetDep;
use self::piksi::msg_reset_filters::MsgResetFilters;
use self::piksi::msg_set_time::MsgSetTime;
use self::piksi::msg_specan::MsgSpecan;
use self::piksi::msg_specan_dep::MsgSpecanDep;
use self::piksi::msg_thread_state::MsgThreadState;
use self::piksi::msg_uart_state::MsgUartState;
use self::piksi::msg_uart_state_depa::MsgUartStateDepa;
use self::sbas::msg_sbas_raw::MsgSbasRaw;
use self::settings::msg_settings_read_by_index_done::MsgSettingsReadByIndexDone;
use self::settings::msg_settings_read_by_index_req::MsgSettingsReadByIndexReq;
use self::settings::msg_settings_read_by_index_resp::MsgSettingsReadByIndexResp;
use self::settings::msg_settings_read_req::MsgSettingsReadReq;
use self::settings::msg_settings_read_resp::MsgSettingsReadResp;
use self::settings::msg_settings_register::MsgSettingsRegister;
use self::settings::msg_settings_register_resp::MsgSettingsRegisterResp;
use self::settings::msg_settings_save::MsgSettingsSave;
use self::settings::msg_settings_write::MsgSettingsWrite;
use self::settings::msg_settings_write_resp::MsgSettingsWriteResp;
use self::signing::msg_ed25519_certificate::MsgEd25519Certificate;
use self::signing::msg_ed25519_signature::MsgEd25519Signature;
use self::solution_meta::msg_soln_meta::MsgSolnMeta;
use self::solution_meta::msg_soln_meta_dep_a::MsgSolnMetaDepA;
use self::ssr::msg_ssr_code_biases::MsgSsrCodeBiases;
use self::ssr::msg_ssr_code_phase_biases_bounds::MsgSsrCodePhaseBiasesBounds;
use self::ssr::msg_ssr_grid_definition_dep_a::MsgSsrGridDefinitionDepA;
use self::ssr::msg_ssr_gridded_correction::MsgSsrGriddedCorrection;
use self::ssr::msg_ssr_gridded_correction_bounds::MsgSsrGriddedCorrectionBounds;
use self::ssr::msg_ssr_gridded_correction_dep_a::MsgSsrGriddedCorrectionDepA;
use self::ssr::msg_ssr_gridded_correction_no_std_dep_a::MsgSsrGriddedCorrectionNoStdDepA;
use self::ssr::msg_ssr_orbit_clock::MsgSsrOrbitClock;
use self::ssr::msg_ssr_orbit_clock_bounds::MsgSsrOrbitClockBounds;
use self::ssr::msg_ssr_orbit_clock_bounds_degradation::MsgSsrOrbitClockBoundsDegradation;
use self::ssr::msg_ssr_orbit_clock_dep_a::MsgSsrOrbitClockDepA;
use self::ssr::msg_ssr_phase_biases::MsgSsrPhaseBiases;
use self::ssr::msg_ssr_satellite_apc::MsgSsrSatelliteApc;
use self::ssr::msg_ssr_stec_correction::MsgSsrStecCorrection;
use self::ssr::msg_ssr_stec_correction_dep::MsgSsrStecCorrectionDep;
use self::ssr::msg_ssr_stec_correction_dep_a::MsgSsrStecCorrectionDepA;
use self::ssr::msg_ssr_tile_definition::MsgSsrTileDefinition;
use self::ssr::msg_ssr_tile_definition_dep::MsgSsrTileDefinitionDep;
use self::system::msg_csac_telemetry::MsgCsacTelemetry;
use self::system::msg_csac_telemetry_labels::MsgCsacTelemetryLabels;
use self::system::msg_dgnss_status::MsgDgnssStatus;
use self::system::msg_gnss_time_offset::MsgGnssTimeOffset;
use self::system::msg_group_meta::MsgGroupMeta;
use self::system::msg_heartbeat::MsgHeartbeat;
use self::system::msg_ins_status::MsgInsStatus;
use self::system::msg_ins_updates::MsgInsUpdates;
use self::system::msg_pps_time::MsgPpsTime;
use self::system::msg_sensor_aid_event::MsgSensorAidEvent;
use self::system::msg_startup::MsgStartup;
use self::system::msg_status_journal::MsgStatusJournal;
use self::system::msg_status_report::MsgStatusReport;
use self::tracking::msg_measurement_state::MsgMeasurementState;
use self::tracking::msg_tracking_iq::MsgTrackingIq;
use self::tracking::msg_tracking_iq_dep_a::MsgTrackingIqDepA;
use self::tracking::msg_tracking_iq_dep_b::MsgTrackingIqDepB;
use self::tracking::msg_tracking_state::MsgTrackingState;
use self::tracking::msg_tracking_state_dep_a::MsgTrackingStateDepA;
use self::tracking::msg_tracking_state_dep_b::MsgTrackingStateDepB;
use self::tracking::msg_tracking_state_detailed_dep::MsgTrackingStateDetailedDep;
use self::tracking::msg_tracking_state_detailed_dep_a::MsgTrackingStateDetailedDepA;
use self::unknown::Unknown;
use self::user::msg_user_data::MsgUserData;
use self::vehicle::msg_odometry::MsgOdometry;
use self::vehicle::msg_wheeltick::MsgWheeltick;

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

    #[cfg(feature = "serde")]
    pub use serde_big_array::BigArray;

    macro_rules! get_bit_range {
        ($bitrange:expr, $source_ty:ty, $target_ty:ty, $msb:expr, $lsb:expr) => {{
            let source_bit_len = std::mem::size_of::<$source_ty>() * 8;
            let target_bit_len = std::mem::size_of::<$target_ty>() * 8;
            let result = (($bitrange << (source_bit_len - $msb - 1))
                >> (source_bit_len - $msb - 1 + $lsb)) as $target_ty;
            result << (target_bit_len - ($msb - $lsb + 1)) >> (target_bit_len - ($msb - $lsb + 1))
        }};
    }

    macro_rules! set_bit_range {
        ($bitrange:expr, $value: expr, $source_ty:ty, $target_ty:ty, $msb:expr, $lsb:expr) => {
            let source_bit_len = std::mem::size_of::<$source_ty>() * 8;
            let mask: $source_ty = !(0 as $source_ty)
                << (source_bit_len - $msb - 1)
                >> (source_bit_len - $msb - 1 + $lsb)
                << ($lsb);
            *$bitrange &= !mask;
            *$bitrange |= ($value as $source_ty << $lsb) & mask;
        };
    }

    pub(crate) use get_bit_range;
    pub(crate) use set_bit_range;
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
#[derive(Debug, PartialEq, Clone)]
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
    /// Leap second SBP message.
    MsgUtcLeapSecond(MsgUtcLeapSecond),
    /// Reference Frame Transformation Parameters
    MsgReferenceFrameParam(MsgReferenceFrameParam),
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
    /// Combined Orbit and Clock Bound
    MsgSsrOrbitClockBounds(MsgSsrOrbitClockBounds),
    /// Combined Orbit and Clock Bound Degradation Parameter
    MsgSsrOrbitClockBoundsDegradation(MsgSsrOrbitClockBoundsDegradation),
    /// Precise code biases correction
    MsgSsrCodeBiases(MsgSsrCodeBiases),
    /// Precise phase biases correction
    MsgSsrPhaseBiases(MsgSsrPhaseBiases),
    /// Deprecated
    MsgSsrStecCorrectionDepA(MsgSsrStecCorrectionDepA),
    /// Combined Code and Phase Biases Bounds
    MsgSsrCodePhaseBiasesBounds(MsgSsrCodePhaseBiasesBounds),
    /// Deprecated
    MsgSsrGriddedCorrectionNoStdDepA(MsgSsrGriddedCorrectionNoStdDepA),
    /// Deprecated
    MsgSsrGridDefinitionDepA(MsgSsrGridDefinitionDepA),
    /// Definition of a SSR atmospheric correction tile.
    MsgSsrTileDefinitionDep(MsgSsrTileDefinitionDep),
    /// Definition of a SSR atmospheric correction tile.
    MsgSsrTileDefinition(MsgSsrTileDefinition),
    /// Deprecated
    MsgSsrGriddedCorrectionDepA(MsgSsrGriddedCorrectionDepA),
    /// STEC correction polynomial coefficients
    MsgSsrStecCorrectionDep(MsgSsrStecCorrectionDep),
    /// Gridded troposphere and STEC correction residuals
    MsgSsrGriddedCorrection(MsgSsrGriddedCorrection),
    /// STEC correction polynomial coefficients
    MsgSsrStecCorrection(MsgSsrStecCorrection),
    /// Gridded troposhere and STEC correction residuals bounds
    MsgSsrGriddedCorrectionBounds(MsgSsrGriddedCorrectionBounds),
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
    /// High level integrity flags
    MsgSsrFlagHighLevel(MsgSsrFlagHighLevel),
    /// List of satellites which are faulty, per constellation
    MsgSsrFlagSatellites(MsgSsrFlagSatellites),
    /// List of grid points which are faulty
    MsgSsrFlagTropoGridPoints(MsgSsrFlagTropoGridPoints),
    /// List of grid points which are faulty
    MsgSsrFlagIonoGridPoints(MsgSsrFlagIonoGridPoints),
    /// List of all the LOS which are faulty
    MsgSsrFlagIonoTileSatLos(MsgSsrFlagIonoTileSatLos),
    /// List of all the grid points to satellite which are faulty
    MsgSsrFlagIonoGridPointSatLos(MsgSsrFlagIonoGridPointSatLos),
    /// ED25519 signature for groups of RTCM messages
    MsgEd25519Signature(MsgEd25519Signature),
    /// ED25519 certificate, split over multiple messages
    MsgEd25519Certificate(MsgEd25519Certificate),
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
    /// Sensor state and update status data
    MsgSensorAidEvent(MsgSensorAidEvent),
    /// Solution Group Metadata
    MsgGroupMeta(MsgGroupMeta),
    /// Solution Sensors Metadata
    MsgSolnMeta(MsgSolnMeta),
    /// Deprecated
    MsgSolnMetaDepA(MsgSolnMetaDepA),
    /// Status report journal
    MsgStatusJournal(MsgStatusJournal),
    /// Status report message
    MsgStatusReport(MsgStatusReport),
    /// System heartbeat message
    MsgHeartbeat(MsgHeartbeat),
    /// Unknown message type
    Unknown(Unknown),
}

#[cfg(feature = "serde_json")]
impl<'de> serde::Deserialize<'de> for Sbp {
    fn deserialize<D>(deserializer: D) -> Result<Self, D::Error>
    where
        D: serde::Deserializer<'de>,
    {
        let value = serde_json::Value::deserialize(deserializer)?;
        match value
            .get("msg_type")
            .and_then(|v| v.as_u64())
            .and_then(|v| v.try_into().ok())
        {
            Some(MsgPrintDep::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgPrintDep>(value).map(Sbp::MsgPrintDep)
            }
            Some(MsgTrackingStateDetailedDep::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgTrackingStateDetailedDep>(value)
                    .map(Sbp::MsgTrackingStateDetailedDep)
            }
            Some(MsgTrackingStateDepB::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgTrackingStateDepB>(value).map(Sbp::MsgTrackingStateDepB)
            }
            Some(MsgAcqResultDepB::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgAcqResultDepB>(value).map(Sbp::MsgAcqResultDepB)
            }
            Some(MsgAcqResultDepA::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgAcqResultDepA>(value).map(Sbp::MsgAcqResultDepA)
            }
            Some(MsgTrackingStateDepA::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgTrackingStateDepA>(value).map(Sbp::MsgTrackingStateDepA)
            }
            Some(MsgThreadState::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgThreadState>(value).map(Sbp::MsgThreadState)
            }
            Some(MsgUartStateDepa::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgUartStateDepa>(value).map(Sbp::MsgUartStateDepa)
            }
            Some(MsgIarState::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgIarState>(value).map(Sbp::MsgIarState)
            }
            Some(MsgEphemerisDepA::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgEphemerisDepA>(value).map(Sbp::MsgEphemerisDepA)
            }
            Some(MsgMaskSatelliteDep::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgMaskSatelliteDep>(value).map(Sbp::MsgMaskSatelliteDep)
            }
            Some(MsgTrackingIqDepA::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgTrackingIqDepA>(value).map(Sbp::MsgTrackingIqDepA)
            }
            Some(MsgUartState::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgUartState>(value).map(Sbp::MsgUartState)
            }
            Some(MsgAcqSvProfileDep::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgAcqSvProfileDep>(value).map(Sbp::MsgAcqSvProfileDep)
            }
            Some(MsgAcqResultDepC::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgAcqResultDepC>(value).map(Sbp::MsgAcqResultDepC)
            }
            Some(MsgTrackingStateDetailedDepA::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgTrackingStateDetailedDepA>(value)
                    .map(Sbp::MsgTrackingStateDetailedDepA)
            }
            Some(MsgResetFilters::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgResetFilters>(value).map(Sbp::MsgResetFilters)
            }
            Some(MsgInitBaseDep::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgInitBaseDep>(value).map(Sbp::MsgInitBaseDep)
            }
            Some(MsgMaskSatellite::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgMaskSatellite>(value).map(Sbp::MsgMaskSatellite)
            }
            Some(MsgTrackingIqDepB::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgTrackingIqDepB>(value).map(Sbp::MsgTrackingIqDepB)
            }
            Some(MsgTrackingIq::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgTrackingIq>(value).map(Sbp::MsgTrackingIq)
            }
            Some(MsgAcqSvProfile::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgAcqSvProfile>(value).map(Sbp::MsgAcqSvProfile)
            }
            Some(MsgAcqResult::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgAcqResult>(value).map(Sbp::MsgAcqResult)
            }
            Some(MsgTrackingState::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgTrackingState>(value).map(Sbp::MsgTrackingState)
            }
            Some(MsgObsDepB::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgObsDepB>(value).map(Sbp::MsgObsDepB)
            }
            Some(MsgBasePosLlh::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgBasePosLlh>(value).map(Sbp::MsgBasePosLlh)
            }
            Some(MsgObsDepA::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgObsDepA>(value).map(Sbp::MsgObsDepA)
            }
            Some(MsgEphemerisDepB::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgEphemerisDepB>(value).map(Sbp::MsgEphemerisDepB)
            }
            Some(MsgEphemerisDepC::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgEphemerisDepC>(value).map(Sbp::MsgEphemerisDepC)
            }
            Some(MsgBasePosEcef::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgBasePosEcef>(value).map(Sbp::MsgBasePosEcef)
            }
            Some(MsgObsDepC::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgObsDepC>(value).map(Sbp::MsgObsDepC)
            }
            Some(MsgObs::MESSAGE_TYPE) => serde_json::from_value::<MsgObs>(value).map(Sbp::MsgObs),
            Some(MsgSpecanDep::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgSpecanDep>(value).map(Sbp::MsgSpecanDep)
            }
            Some(MsgSpecan::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgSpecan>(value).map(Sbp::MsgSpecan)
            }
            Some(MsgMeasurementState::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgMeasurementState>(value).map(Sbp::MsgMeasurementState)
            }
            Some(MsgSetTime::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgSetTime>(value).map(Sbp::MsgSetTime)
            }
            Some(MsgAlmanac::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgAlmanac>(value).map(Sbp::MsgAlmanac)
            }
            Some(MsgAlmanacGpsDep::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgAlmanacGpsDep>(value).map(Sbp::MsgAlmanacGpsDep)
            }
            Some(MsgAlmanacGloDep::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgAlmanacGloDep>(value).map(Sbp::MsgAlmanacGloDep)
            }
            Some(MsgAlmanacGps::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgAlmanacGps>(value).map(Sbp::MsgAlmanacGps)
            }
            Some(MsgAlmanacGlo::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgAlmanacGlo>(value).map(Sbp::MsgAlmanacGlo)
            }
            Some(MsgGloBiases::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgGloBiases>(value).map(Sbp::MsgGloBiases)
            }
            Some(MsgEphemerisDepD::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgEphemerisDepD>(value).map(Sbp::MsgEphemerisDepD)
            }
            Some(MsgEphemerisGpsDepE::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgEphemerisGpsDepE>(value).map(Sbp::MsgEphemerisGpsDepE)
            }
            Some(MsgEphemerisSbasDepA::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgEphemerisSbasDepA>(value).map(Sbp::MsgEphemerisSbasDepA)
            }
            Some(MsgEphemerisGloDepA::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgEphemerisGloDepA>(value).map(Sbp::MsgEphemerisGloDepA)
            }
            Some(MsgEphemerisSbasDepB::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgEphemerisSbasDepB>(value).map(Sbp::MsgEphemerisSbasDepB)
            }
            Some(MsgEphemerisGloDepB::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgEphemerisGloDepB>(value).map(Sbp::MsgEphemerisGloDepB)
            }
            Some(MsgEphemerisGpsDepF::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgEphemerisGpsDepF>(value).map(Sbp::MsgEphemerisGpsDepF)
            }
            Some(MsgEphemerisGloDepC::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgEphemerisGloDepC>(value).map(Sbp::MsgEphemerisGloDepC)
            }
            Some(MsgEphemerisGloDepD::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgEphemerisGloDepD>(value).map(Sbp::MsgEphemerisGloDepD)
            }
            Some(MsgEphemerisBds::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgEphemerisBds>(value).map(Sbp::MsgEphemerisBds)
            }
            Some(MsgEphemerisGps::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgEphemerisGps>(value).map(Sbp::MsgEphemerisGps)
            }
            Some(MsgEphemerisGlo::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgEphemerisGlo>(value).map(Sbp::MsgEphemerisGlo)
            }
            Some(MsgEphemerisSbas::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgEphemerisSbas>(value).map(Sbp::MsgEphemerisSbas)
            }
            Some(MsgEphemerisGal::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgEphemerisGal>(value).map(Sbp::MsgEphemerisGal)
            }
            Some(MsgEphemerisQzss::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgEphemerisQzss>(value).map(Sbp::MsgEphemerisQzss)
            }
            Some(MsgIono::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgIono>(value).map(Sbp::MsgIono)
            }
            Some(MsgSvConfigurationGpsDep::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgSvConfigurationGpsDep>(value)
                    .map(Sbp::MsgSvConfigurationGpsDep)
            }
            Some(MsgGroupDelayDepA::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgGroupDelayDepA>(value).map(Sbp::MsgGroupDelayDepA)
            }
            Some(MsgGroupDelayDepB::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgGroupDelayDepB>(value).map(Sbp::MsgGroupDelayDepB)
            }
            Some(MsgGroupDelay::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgGroupDelay>(value).map(Sbp::MsgGroupDelay)
            }
            Some(MsgEphemerisGalDepA::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgEphemerisGalDepA>(value).map(Sbp::MsgEphemerisGalDepA)
            }
            Some(MsgGnssCapb::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgGnssCapb>(value).map(Sbp::MsgGnssCapb)
            }
            Some(MsgSvAzEl::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgSvAzEl>(value).map(Sbp::MsgSvAzEl)
            }
            Some(MsgSettingsWrite::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgSettingsWrite>(value).map(Sbp::MsgSettingsWrite)
            }
            Some(MsgSettingsSave::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgSettingsSave>(value).map(Sbp::MsgSettingsSave)
            }
            Some(MsgSettingsReadByIndexReq::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgSettingsReadByIndexReq>(value)
                    .map(Sbp::MsgSettingsReadByIndexReq)
            }
            Some(MsgFileioReadResp::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgFileioReadResp>(value).map(Sbp::MsgFileioReadResp)
            }
            Some(MsgSettingsReadReq::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgSettingsReadReq>(value).map(Sbp::MsgSettingsReadReq)
            }
            Some(MsgSettingsReadResp::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgSettingsReadResp>(value).map(Sbp::MsgSettingsReadResp)
            }
            Some(MsgSettingsReadByIndexDone::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgSettingsReadByIndexDone>(value)
                    .map(Sbp::MsgSettingsReadByIndexDone)
            }
            Some(MsgSettingsReadByIndexResp::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgSettingsReadByIndexResp>(value)
                    .map(Sbp::MsgSettingsReadByIndexResp)
            }
            Some(MsgFileioReadReq::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgFileioReadReq>(value).map(Sbp::MsgFileioReadReq)
            }
            Some(MsgFileioReadDirReq::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgFileioReadDirReq>(value).map(Sbp::MsgFileioReadDirReq)
            }
            Some(MsgFileioReadDirResp::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgFileioReadDirResp>(value).map(Sbp::MsgFileioReadDirResp)
            }
            Some(MsgFileioWriteResp::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgFileioWriteResp>(value).map(Sbp::MsgFileioWriteResp)
            }
            Some(MsgFileioRemove::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgFileioRemove>(value).map(Sbp::MsgFileioRemove)
            }
            Some(MsgFileioWriteReq::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgFileioWriteReq>(value).map(Sbp::MsgFileioWriteReq)
            }
            Some(MsgSettingsRegister::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgSettingsRegister>(value).map(Sbp::MsgSettingsRegister)
            }
            Some(MsgSettingsWriteResp::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgSettingsWriteResp>(value).map(Sbp::MsgSettingsWriteResp)
            }
            Some(MsgBootloaderHandshakeDepA::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgBootloaderHandshakeDepA>(value)
                    .map(Sbp::MsgBootloaderHandshakeDepA)
            }
            Some(MsgBootloaderJumpToApp::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgBootloaderJumpToApp>(value)
                    .map(Sbp::MsgBootloaderJumpToApp)
            }
            Some(MsgResetDep::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgResetDep>(value).map(Sbp::MsgResetDep)
            }
            Some(MsgBootloaderHandshakeReq::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgBootloaderHandshakeReq>(value)
                    .map(Sbp::MsgBootloaderHandshakeReq)
            }
            Some(MsgBootloaderHandshakeResp::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgBootloaderHandshakeResp>(value)
                    .map(Sbp::MsgBootloaderHandshakeResp)
            }
            Some(MsgDeviceMonitor::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgDeviceMonitor>(value).map(Sbp::MsgDeviceMonitor)
            }
            Some(MsgReset::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgReset>(value).map(Sbp::MsgReset)
            }
            Some(MsgCommandReq::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgCommandReq>(value).map(Sbp::MsgCommandReq)
            }
            Some(MsgCommandResp::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgCommandResp>(value).map(Sbp::MsgCommandResp)
            }
            Some(MsgNetworkStateReq::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgNetworkStateReq>(value).map(Sbp::MsgNetworkStateReq)
            }
            Some(MsgNetworkStateResp::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgNetworkStateResp>(value).map(Sbp::MsgNetworkStateResp)
            }
            Some(MsgCommandOutput::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgCommandOutput>(value).map(Sbp::MsgCommandOutput)
            }
            Some(MsgNetworkBandwidthUsage::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgNetworkBandwidthUsage>(value)
                    .map(Sbp::MsgNetworkBandwidthUsage)
            }
            Some(MsgCellModemStatus::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgCellModemStatus>(value).map(Sbp::MsgCellModemStatus)
            }
            Some(MsgFrontEndGain::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgFrontEndGain>(value).map(Sbp::MsgFrontEndGain)
            }
            Some(MsgCwResults::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgCwResults>(value).map(Sbp::MsgCwResults)
            }
            Some(MsgCwStart::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgCwStart>(value).map(Sbp::MsgCwStart)
            }
            Some(MsgNapDeviceDnaResp::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgNapDeviceDnaResp>(value).map(Sbp::MsgNapDeviceDnaResp)
            }
            Some(MsgNapDeviceDnaReq::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgNapDeviceDnaReq>(value).map(Sbp::MsgNapDeviceDnaReq)
            }
            Some(MsgFlashDone::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgFlashDone>(value).map(Sbp::MsgFlashDone)
            }
            Some(MsgFlashReadResp::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgFlashReadResp>(value).map(Sbp::MsgFlashReadResp)
            }
            Some(MsgFlashErase::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgFlashErase>(value).map(Sbp::MsgFlashErase)
            }
            Some(MsgStmFlashLockSector::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgStmFlashLockSector>(value)
                    .map(Sbp::MsgStmFlashLockSector)
            }
            Some(MsgStmFlashUnlockSector::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgStmFlashUnlockSector>(value)
                    .map(Sbp::MsgStmFlashUnlockSector)
            }
            Some(MsgStmUniqueIdResp::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgStmUniqueIdResp>(value).map(Sbp::MsgStmUniqueIdResp)
            }
            Some(MsgFlashProgram::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgFlashProgram>(value).map(Sbp::MsgFlashProgram)
            }
            Some(MsgFlashReadReq::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgFlashReadReq>(value).map(Sbp::MsgFlashReadReq)
            }
            Some(MsgStmUniqueIdReq::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgStmUniqueIdReq>(value).map(Sbp::MsgStmUniqueIdReq)
            }
            Some(MsgM25FlashWriteStatus::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgM25FlashWriteStatus>(value)
                    .map(Sbp::MsgM25FlashWriteStatus)
            }
            Some(MsgGpsTimeDepA::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgGpsTimeDepA>(value).map(Sbp::MsgGpsTimeDepA)
            }
            Some(MsgExtEvent::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgExtEvent>(value).map(Sbp::MsgExtEvent)
            }
            Some(MsgGpsTime::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgGpsTime>(value).map(Sbp::MsgGpsTime)
            }
            Some(MsgUtcTime::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgUtcTime>(value).map(Sbp::MsgUtcTime)
            }
            Some(MsgGpsTimeGnss::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgGpsTimeGnss>(value).map(Sbp::MsgGpsTimeGnss)
            }
            Some(MsgUtcTimeGnss::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgUtcTimeGnss>(value).map(Sbp::MsgUtcTimeGnss)
            }
            Some(MsgSettingsRegisterResp::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgSettingsRegisterResp>(value)
                    .map(Sbp::MsgSettingsRegisterResp)
            }
            Some(MsgPosEcefDepA::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgPosEcefDepA>(value).map(Sbp::MsgPosEcefDepA)
            }
            Some(MsgPosLlhDepA::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgPosLlhDepA>(value).map(Sbp::MsgPosLlhDepA)
            }
            Some(MsgBaselineEcefDepA::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgBaselineEcefDepA>(value).map(Sbp::MsgBaselineEcefDepA)
            }
            Some(MsgBaselineNedDepA::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgBaselineNedDepA>(value).map(Sbp::MsgBaselineNedDepA)
            }
            Some(MsgVelEcefDepA::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgVelEcefDepA>(value).map(Sbp::MsgVelEcefDepA)
            }
            Some(MsgVelNedDepA::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgVelNedDepA>(value).map(Sbp::MsgVelNedDepA)
            }
            Some(MsgDopsDepA::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgDopsDepA>(value).map(Sbp::MsgDopsDepA)
            }
            Some(MsgBaselineHeadingDepA::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgBaselineHeadingDepA>(value)
                    .map(Sbp::MsgBaselineHeadingDepA)
            }
            Some(MsgDops::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgDops>(value).map(Sbp::MsgDops)
            }
            Some(MsgPosEcef::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgPosEcef>(value).map(Sbp::MsgPosEcef)
            }
            Some(MsgPosLlh::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgPosLlh>(value).map(Sbp::MsgPosLlh)
            }
            Some(MsgBaselineEcef::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgBaselineEcef>(value).map(Sbp::MsgBaselineEcef)
            }
            Some(MsgBaselineNed::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgBaselineNed>(value).map(Sbp::MsgBaselineNed)
            }
            Some(MsgVelEcef::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgVelEcef>(value).map(Sbp::MsgVelEcef)
            }
            Some(MsgVelNed::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgVelNed>(value).map(Sbp::MsgVelNed)
            }
            Some(MsgBaselineHeading::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgBaselineHeading>(value).map(Sbp::MsgBaselineHeading)
            }
            Some(MsgAgeCorrections::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgAgeCorrections>(value).map(Sbp::MsgAgeCorrections)
            }
            Some(MsgPosLlhCov::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgPosLlhCov>(value).map(Sbp::MsgPosLlhCov)
            }
            Some(MsgVelNedCov::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgVelNedCov>(value).map(Sbp::MsgVelNedCov)
            }
            Some(MsgVelBody::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgVelBody>(value).map(Sbp::MsgVelBody)
            }
            Some(MsgPosEcefCov::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgPosEcefCov>(value).map(Sbp::MsgPosEcefCov)
            }
            Some(MsgVelEcefCov::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgVelEcefCov>(value).map(Sbp::MsgVelEcefCov)
            }
            Some(MsgProtectionLevelDepA::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgProtectionLevelDepA>(value)
                    .map(Sbp::MsgProtectionLevelDepA)
            }
            Some(MsgProtectionLevel::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgProtectionLevel>(value).map(Sbp::MsgProtectionLevel)
            }
            Some(MsgPosLlhAcc::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgPosLlhAcc>(value).map(Sbp::MsgPosLlhAcc)
            }
            Some(MsgVelCog::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgVelCog>(value).map(Sbp::MsgVelCog)
            }
            Some(MsgOrientQuat::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgOrientQuat>(value).map(Sbp::MsgOrientQuat)
            }
            Some(MsgOrientEuler::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgOrientEuler>(value).map(Sbp::MsgOrientEuler)
            }
            Some(MsgAngularRate::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgAngularRate>(value).map(Sbp::MsgAngularRate)
            }
            Some(MsgPosEcefGnss::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgPosEcefGnss>(value).map(Sbp::MsgPosEcefGnss)
            }
            Some(MsgPosLlhGnss::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgPosLlhGnss>(value).map(Sbp::MsgPosLlhGnss)
            }
            Some(MsgVelEcefGnss::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgVelEcefGnss>(value).map(Sbp::MsgVelEcefGnss)
            }
            Some(MsgVelNedGnss::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgVelNedGnss>(value).map(Sbp::MsgVelNedGnss)
            }
            Some(MsgPosLlhCovGnss::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgPosLlhCovGnss>(value).map(Sbp::MsgPosLlhCovGnss)
            }
            Some(MsgVelNedCovGnss::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgVelNedCovGnss>(value).map(Sbp::MsgVelNedCovGnss)
            }
            Some(MsgPosEcefCovGnss::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgPosEcefCovGnss>(value).map(Sbp::MsgPosEcefCovGnss)
            }
            Some(MsgVelEcefCovGnss::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgVelEcefCovGnss>(value).map(Sbp::MsgVelEcefCovGnss)
            }
            Some(MsgUtcLeapSecond::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgUtcLeapSecond>(value).map(Sbp::MsgUtcLeapSecond)
            }
            Some(MsgReferenceFrameParam::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgReferenceFrameParam>(value)
                    .map(Sbp::MsgReferenceFrameParam)
            }
            Some(MsgNdbEvent::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgNdbEvent>(value).map(Sbp::MsgNdbEvent)
            }
            Some(MsgLog::MESSAGE_TYPE) => serde_json::from_value::<MsgLog>(value).map(Sbp::MsgLog),
            Some(MsgFwd::MESSAGE_TYPE) => serde_json::from_value::<MsgFwd>(value).map(Sbp::MsgFwd),
            Some(MsgSsrOrbitClockDepA::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgSsrOrbitClockDepA>(value).map(Sbp::MsgSsrOrbitClockDepA)
            }
            Some(MsgSsrOrbitClock::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgSsrOrbitClock>(value).map(Sbp::MsgSsrOrbitClock)
            }
            Some(MsgSsrOrbitClockBounds::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgSsrOrbitClockBounds>(value)
                    .map(Sbp::MsgSsrOrbitClockBounds)
            }
            Some(MsgSsrOrbitClockBoundsDegradation::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgSsrOrbitClockBoundsDegradation>(value)
                    .map(Sbp::MsgSsrOrbitClockBoundsDegradation)
            }
            Some(MsgSsrCodeBiases::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgSsrCodeBiases>(value).map(Sbp::MsgSsrCodeBiases)
            }
            Some(MsgSsrPhaseBiases::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgSsrPhaseBiases>(value).map(Sbp::MsgSsrPhaseBiases)
            }
            Some(MsgSsrStecCorrectionDepA::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgSsrStecCorrectionDepA>(value)
                    .map(Sbp::MsgSsrStecCorrectionDepA)
            }
            Some(MsgSsrCodePhaseBiasesBounds::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgSsrCodePhaseBiasesBounds>(value)
                    .map(Sbp::MsgSsrCodePhaseBiasesBounds)
            }
            Some(MsgSsrGriddedCorrectionNoStdDepA::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgSsrGriddedCorrectionNoStdDepA>(value)
                    .map(Sbp::MsgSsrGriddedCorrectionNoStdDepA)
            }
            Some(MsgSsrGridDefinitionDepA::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgSsrGridDefinitionDepA>(value)
                    .map(Sbp::MsgSsrGridDefinitionDepA)
            }
            Some(MsgSsrTileDefinitionDep::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgSsrTileDefinitionDep>(value)
                    .map(Sbp::MsgSsrTileDefinitionDep)
            }
            Some(MsgSsrTileDefinition::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgSsrTileDefinition>(value).map(Sbp::MsgSsrTileDefinition)
            }
            Some(MsgSsrGriddedCorrectionDepA::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgSsrGriddedCorrectionDepA>(value)
                    .map(Sbp::MsgSsrGriddedCorrectionDepA)
            }
            Some(MsgSsrStecCorrectionDep::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgSsrStecCorrectionDep>(value)
                    .map(Sbp::MsgSsrStecCorrectionDep)
            }
            Some(MsgSsrGriddedCorrection::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgSsrGriddedCorrection>(value)
                    .map(Sbp::MsgSsrGriddedCorrection)
            }
            Some(MsgSsrStecCorrection::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgSsrStecCorrection>(value).map(Sbp::MsgSsrStecCorrection)
            }
            Some(MsgSsrGriddedCorrectionBounds::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgSsrGriddedCorrectionBounds>(value)
                    .map(Sbp::MsgSsrGriddedCorrectionBounds)
            }
            Some(MsgSsrSatelliteApc::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgSsrSatelliteApc>(value).map(Sbp::MsgSsrSatelliteApc)
            }
            Some(MsgOsr::MESSAGE_TYPE) => serde_json::from_value::<MsgOsr>(value).map(Sbp::MsgOsr),
            Some(MsgUserData::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgUserData>(value).map(Sbp::MsgUserData)
            }
            Some(MsgImuRaw::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgImuRaw>(value).map(Sbp::MsgImuRaw)
            }
            Some(MsgImuAux::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgImuAux>(value).map(Sbp::MsgImuAux)
            }
            Some(MsgMagRaw::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgMagRaw>(value).map(Sbp::MsgMagRaw)
            }
            Some(MsgOdometry::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgOdometry>(value).map(Sbp::MsgOdometry)
            }
            Some(MsgWheeltick::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgWheeltick>(value).map(Sbp::MsgWheeltick)
            }
            Some(MsgSsrFlagHighLevel::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgSsrFlagHighLevel>(value).map(Sbp::MsgSsrFlagHighLevel)
            }
            Some(MsgSsrFlagSatellites::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgSsrFlagSatellites>(value).map(Sbp::MsgSsrFlagSatellites)
            }
            Some(MsgSsrFlagTropoGridPoints::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgSsrFlagTropoGridPoints>(value)
                    .map(Sbp::MsgSsrFlagTropoGridPoints)
            }
            Some(MsgSsrFlagIonoGridPoints::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgSsrFlagIonoGridPoints>(value)
                    .map(Sbp::MsgSsrFlagIonoGridPoints)
            }
            Some(MsgSsrFlagIonoTileSatLos::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgSsrFlagIonoTileSatLos>(value)
                    .map(Sbp::MsgSsrFlagIonoTileSatLos)
            }
            Some(MsgSsrFlagIonoGridPointSatLos::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgSsrFlagIonoGridPointSatLos>(value)
                    .map(Sbp::MsgSsrFlagIonoGridPointSatLos)
            }
            Some(MsgEd25519Signature::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgEd25519Signature>(value).map(Sbp::MsgEd25519Signature)
            }
            Some(MsgEd25519Certificate::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgEd25519Certificate>(value)
                    .map(Sbp::MsgEd25519Certificate)
            }
            Some(MsgFileioConfigReq::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgFileioConfigReq>(value).map(Sbp::MsgFileioConfigReq)
            }
            Some(MsgFileioConfigResp::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgFileioConfigResp>(value).map(Sbp::MsgFileioConfigResp)
            }
            Some(MsgSbasRaw::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgSbasRaw>(value).map(Sbp::MsgSbasRaw)
            }
            Some(MsgLinuxCpuStateDepA::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgLinuxCpuStateDepA>(value).map(Sbp::MsgLinuxCpuStateDepA)
            }
            Some(MsgLinuxMemStateDepA::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgLinuxMemStateDepA>(value).map(Sbp::MsgLinuxMemStateDepA)
            }
            Some(MsgLinuxSysStateDepA::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgLinuxSysStateDepA>(value).map(Sbp::MsgLinuxSysStateDepA)
            }
            Some(MsgLinuxProcessSocketCounts::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgLinuxProcessSocketCounts>(value)
                    .map(Sbp::MsgLinuxProcessSocketCounts)
            }
            Some(MsgLinuxProcessSocketQueues::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgLinuxProcessSocketQueues>(value)
                    .map(Sbp::MsgLinuxProcessSocketQueues)
            }
            Some(MsgLinuxSocketUsage::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgLinuxSocketUsage>(value).map(Sbp::MsgLinuxSocketUsage)
            }
            Some(MsgLinuxProcessFdCount::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgLinuxProcessFdCount>(value)
                    .map(Sbp::MsgLinuxProcessFdCount)
            }
            Some(MsgLinuxProcessFdSummary::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgLinuxProcessFdSummary>(value)
                    .map(Sbp::MsgLinuxProcessFdSummary)
            }
            Some(MsgLinuxCpuState::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgLinuxCpuState>(value).map(Sbp::MsgLinuxCpuState)
            }
            Some(MsgLinuxMemState::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgLinuxMemState>(value).map(Sbp::MsgLinuxMemState)
            }
            Some(MsgLinuxSysState::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgLinuxSysState>(value).map(Sbp::MsgLinuxSysState)
            }
            Some(MsgStartup::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgStartup>(value).map(Sbp::MsgStartup)
            }
            Some(MsgDgnssStatus::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgDgnssStatus>(value).map(Sbp::MsgDgnssStatus)
            }
            Some(MsgInsStatus::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgInsStatus>(value).map(Sbp::MsgInsStatus)
            }
            Some(MsgCsacTelemetry::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgCsacTelemetry>(value).map(Sbp::MsgCsacTelemetry)
            }
            Some(MsgCsacTelemetryLabels::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgCsacTelemetryLabels>(value)
                    .map(Sbp::MsgCsacTelemetryLabels)
            }
            Some(MsgInsUpdates::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgInsUpdates>(value).map(Sbp::MsgInsUpdates)
            }
            Some(MsgGnssTimeOffset::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgGnssTimeOffset>(value).map(Sbp::MsgGnssTimeOffset)
            }
            Some(MsgPpsTime::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgPpsTime>(value).map(Sbp::MsgPpsTime)
            }
            Some(MsgSensorAidEvent::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgSensorAidEvent>(value).map(Sbp::MsgSensorAidEvent)
            }
            Some(MsgGroupMeta::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgGroupMeta>(value).map(Sbp::MsgGroupMeta)
            }
            Some(MsgSolnMeta::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgSolnMeta>(value).map(Sbp::MsgSolnMeta)
            }
            Some(MsgSolnMetaDepA::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgSolnMetaDepA>(value).map(Sbp::MsgSolnMetaDepA)
            }
            Some(MsgStatusJournal::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgStatusJournal>(value).map(Sbp::MsgStatusJournal)
            }
            Some(MsgStatusReport::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgStatusReport>(value).map(Sbp::MsgStatusReport)
            }
            Some(MsgHeartbeat::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgHeartbeat>(value).map(Sbp::MsgHeartbeat)
            }
            _ => serde_json::from_value::<Unknown>(value).map(Sbp::Unknown),
        }
        .map_err(serde::de::Error::custom)
    }
}

impl Sbp {
    /// Parse a message from given fields.
    ///
    /// # Example
    ///
    /// ```
    /// use std::convert::TryInto;
    ///
    /// use sbp::messages::logging::MsgLog;
    /// use sbp::Sbp;
    ///
    /// fn main() -> Result<(), Box<dyn std::error::Error>> {
    ///     // log level 1 and with "hello" as the message
    ///     let msg_type = 1025;
    ///     let sender_id = 1;
    ///     let payload: &[u8] = &[1, 104, 101, 108, 108, 111];
    ///
    ///     let msg: MsgLog = Sbp::from_parts(msg_type, sender_id, payload)?.try_into()?;
    ///     assert_eq!(msg.sender_id, Some(1));
    ///     assert_eq!(msg.level, 1);
    ///     assert_eq!(msg.text.as_bytes(), "hello".as_bytes());
    ///     Ok(())
    /// }
    /// ```
    pub fn from_parts<B: bytes::Buf>(
        msg_type: u16,
        sender_id: u16,
        mut payload: B,
    ) -> Result<Sbp, PayloadParseError> {
        match msg_type {
            MsgPrintDep::MESSAGE_TYPE => {
                let mut msg = MsgPrintDep::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgPrintDep(msg))
            }
            MsgTrackingStateDetailedDep::MESSAGE_TYPE => {
                let mut msg = MsgTrackingStateDetailedDep::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgTrackingStateDetailedDep(msg))
            }
            MsgTrackingStateDepB::MESSAGE_TYPE => {
                let mut msg = MsgTrackingStateDepB::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgTrackingStateDepB(msg))
            }
            MsgAcqResultDepB::MESSAGE_TYPE => {
                let mut msg = MsgAcqResultDepB::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgAcqResultDepB(msg))
            }
            MsgAcqResultDepA::MESSAGE_TYPE => {
                let mut msg = MsgAcqResultDepA::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgAcqResultDepA(msg))
            }
            MsgTrackingStateDepA::MESSAGE_TYPE => {
                let mut msg = MsgTrackingStateDepA::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgTrackingStateDepA(msg))
            }
            MsgThreadState::MESSAGE_TYPE => {
                let mut msg = MsgThreadState::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgThreadState(msg))
            }
            MsgUartStateDepa::MESSAGE_TYPE => {
                let mut msg = MsgUartStateDepa::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgUartStateDepa(msg))
            }
            MsgIarState::MESSAGE_TYPE => {
                let mut msg = MsgIarState::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgIarState(msg))
            }
            MsgEphemerisDepA::MESSAGE_TYPE => {
                let mut msg = MsgEphemerisDepA::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgEphemerisDepA(msg))
            }
            MsgMaskSatelliteDep::MESSAGE_TYPE => {
                let mut msg = MsgMaskSatelliteDep::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgMaskSatelliteDep(msg))
            }
            MsgTrackingIqDepA::MESSAGE_TYPE => {
                let mut msg = MsgTrackingIqDepA::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgTrackingIqDepA(msg))
            }
            MsgUartState::MESSAGE_TYPE => {
                let mut msg = MsgUartState::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgUartState(msg))
            }
            MsgAcqSvProfileDep::MESSAGE_TYPE => {
                let mut msg = MsgAcqSvProfileDep::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgAcqSvProfileDep(msg))
            }
            MsgAcqResultDepC::MESSAGE_TYPE => {
                let mut msg = MsgAcqResultDepC::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgAcqResultDepC(msg))
            }
            MsgTrackingStateDetailedDepA::MESSAGE_TYPE => {
                let mut msg = MsgTrackingStateDetailedDepA::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgTrackingStateDetailedDepA(msg))
            }
            MsgResetFilters::MESSAGE_TYPE => {
                let mut msg = MsgResetFilters::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgResetFilters(msg))
            }
            MsgInitBaseDep::MESSAGE_TYPE => {
                let mut msg = MsgInitBaseDep::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgInitBaseDep(msg))
            }
            MsgMaskSatellite::MESSAGE_TYPE => {
                let mut msg = MsgMaskSatellite::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgMaskSatellite(msg))
            }
            MsgTrackingIqDepB::MESSAGE_TYPE => {
                let mut msg = MsgTrackingIqDepB::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgTrackingIqDepB(msg))
            }
            MsgTrackingIq::MESSAGE_TYPE => {
                let mut msg = MsgTrackingIq::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgTrackingIq(msg))
            }
            MsgAcqSvProfile::MESSAGE_TYPE => {
                let mut msg = MsgAcqSvProfile::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgAcqSvProfile(msg))
            }
            MsgAcqResult::MESSAGE_TYPE => {
                let mut msg = MsgAcqResult::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgAcqResult(msg))
            }
            MsgTrackingState::MESSAGE_TYPE => {
                let mut msg = MsgTrackingState::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgTrackingState(msg))
            }
            MsgObsDepB::MESSAGE_TYPE => {
                let mut msg = MsgObsDepB::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgObsDepB(msg))
            }
            MsgBasePosLlh::MESSAGE_TYPE => {
                let mut msg = MsgBasePosLlh::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgBasePosLlh(msg))
            }
            MsgObsDepA::MESSAGE_TYPE => {
                let mut msg = MsgObsDepA::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgObsDepA(msg))
            }
            MsgEphemerisDepB::MESSAGE_TYPE => {
                let mut msg = MsgEphemerisDepB::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgEphemerisDepB(msg))
            }
            MsgEphemerisDepC::MESSAGE_TYPE => {
                let mut msg = MsgEphemerisDepC::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgEphemerisDepC(msg))
            }
            MsgBasePosEcef::MESSAGE_TYPE => {
                let mut msg = MsgBasePosEcef::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgBasePosEcef(msg))
            }
            MsgObsDepC::MESSAGE_TYPE => {
                let mut msg = MsgObsDepC::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgObsDepC(msg))
            }
            MsgObs::MESSAGE_TYPE => {
                let mut msg = MsgObs::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgObs(msg))
            }
            MsgSpecanDep::MESSAGE_TYPE => {
                let mut msg = MsgSpecanDep::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgSpecanDep(msg))
            }
            MsgSpecan::MESSAGE_TYPE => {
                let mut msg = MsgSpecan::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgSpecan(msg))
            }
            MsgMeasurementState::MESSAGE_TYPE => {
                let mut msg = MsgMeasurementState::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgMeasurementState(msg))
            }
            MsgSetTime::MESSAGE_TYPE => {
                let mut msg = MsgSetTime::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgSetTime(msg))
            }
            MsgAlmanac::MESSAGE_TYPE => {
                let mut msg = MsgAlmanac::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgAlmanac(msg))
            }
            MsgAlmanacGpsDep::MESSAGE_TYPE => {
                let mut msg = MsgAlmanacGpsDep::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgAlmanacGpsDep(msg))
            }
            MsgAlmanacGloDep::MESSAGE_TYPE => {
                let mut msg = MsgAlmanacGloDep::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgAlmanacGloDep(msg))
            }
            MsgAlmanacGps::MESSAGE_TYPE => {
                let mut msg = MsgAlmanacGps::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgAlmanacGps(msg))
            }
            MsgAlmanacGlo::MESSAGE_TYPE => {
                let mut msg = MsgAlmanacGlo::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgAlmanacGlo(msg))
            }
            MsgGloBiases::MESSAGE_TYPE => {
                let mut msg = MsgGloBiases::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgGloBiases(msg))
            }
            MsgEphemerisDepD::MESSAGE_TYPE => {
                let mut msg = MsgEphemerisDepD::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgEphemerisDepD(msg))
            }
            MsgEphemerisGpsDepE::MESSAGE_TYPE => {
                let mut msg = MsgEphemerisGpsDepE::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgEphemerisGpsDepE(msg))
            }
            MsgEphemerisSbasDepA::MESSAGE_TYPE => {
                let mut msg = MsgEphemerisSbasDepA::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgEphemerisSbasDepA(msg))
            }
            MsgEphemerisGloDepA::MESSAGE_TYPE => {
                let mut msg = MsgEphemerisGloDepA::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgEphemerisGloDepA(msg))
            }
            MsgEphemerisSbasDepB::MESSAGE_TYPE => {
                let mut msg = MsgEphemerisSbasDepB::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgEphemerisSbasDepB(msg))
            }
            MsgEphemerisGloDepB::MESSAGE_TYPE => {
                let mut msg = MsgEphemerisGloDepB::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgEphemerisGloDepB(msg))
            }
            MsgEphemerisGpsDepF::MESSAGE_TYPE => {
                let mut msg = MsgEphemerisGpsDepF::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgEphemerisGpsDepF(msg))
            }
            MsgEphemerisGloDepC::MESSAGE_TYPE => {
                let mut msg = MsgEphemerisGloDepC::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgEphemerisGloDepC(msg))
            }
            MsgEphemerisGloDepD::MESSAGE_TYPE => {
                let mut msg = MsgEphemerisGloDepD::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgEphemerisGloDepD(msg))
            }
            MsgEphemerisBds::MESSAGE_TYPE => {
                let mut msg = MsgEphemerisBds::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgEphemerisBds(msg))
            }
            MsgEphemerisGps::MESSAGE_TYPE => {
                let mut msg = MsgEphemerisGps::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgEphemerisGps(msg))
            }
            MsgEphemerisGlo::MESSAGE_TYPE => {
                let mut msg = MsgEphemerisGlo::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgEphemerisGlo(msg))
            }
            MsgEphemerisSbas::MESSAGE_TYPE => {
                let mut msg = MsgEphemerisSbas::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgEphemerisSbas(msg))
            }
            MsgEphemerisGal::MESSAGE_TYPE => {
                let mut msg = MsgEphemerisGal::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgEphemerisGal(msg))
            }
            MsgEphemerisQzss::MESSAGE_TYPE => {
                let mut msg = MsgEphemerisQzss::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgEphemerisQzss(msg))
            }
            MsgIono::MESSAGE_TYPE => {
                let mut msg = MsgIono::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgIono(msg))
            }
            MsgSvConfigurationGpsDep::MESSAGE_TYPE => {
                let mut msg = MsgSvConfigurationGpsDep::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgSvConfigurationGpsDep(msg))
            }
            MsgGroupDelayDepA::MESSAGE_TYPE => {
                let mut msg = MsgGroupDelayDepA::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgGroupDelayDepA(msg))
            }
            MsgGroupDelayDepB::MESSAGE_TYPE => {
                let mut msg = MsgGroupDelayDepB::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgGroupDelayDepB(msg))
            }
            MsgGroupDelay::MESSAGE_TYPE => {
                let mut msg = MsgGroupDelay::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgGroupDelay(msg))
            }
            MsgEphemerisGalDepA::MESSAGE_TYPE => {
                let mut msg = MsgEphemerisGalDepA::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgEphemerisGalDepA(msg))
            }
            MsgGnssCapb::MESSAGE_TYPE => {
                let mut msg = MsgGnssCapb::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgGnssCapb(msg))
            }
            MsgSvAzEl::MESSAGE_TYPE => {
                let mut msg = MsgSvAzEl::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgSvAzEl(msg))
            }
            MsgSettingsWrite::MESSAGE_TYPE => {
                let mut msg = MsgSettingsWrite::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgSettingsWrite(msg))
            }
            MsgSettingsSave::MESSAGE_TYPE => {
                let mut msg = MsgSettingsSave::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgSettingsSave(msg))
            }
            MsgSettingsReadByIndexReq::MESSAGE_TYPE => {
                let mut msg = MsgSettingsReadByIndexReq::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgSettingsReadByIndexReq(msg))
            }
            MsgFileioReadResp::MESSAGE_TYPE => {
                let mut msg = MsgFileioReadResp::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgFileioReadResp(msg))
            }
            MsgSettingsReadReq::MESSAGE_TYPE => {
                let mut msg = MsgSettingsReadReq::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgSettingsReadReq(msg))
            }
            MsgSettingsReadResp::MESSAGE_TYPE => {
                let mut msg = MsgSettingsReadResp::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgSettingsReadResp(msg))
            }
            MsgSettingsReadByIndexDone::MESSAGE_TYPE => {
                let mut msg = MsgSettingsReadByIndexDone::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgSettingsReadByIndexDone(msg))
            }
            MsgSettingsReadByIndexResp::MESSAGE_TYPE => {
                let mut msg = MsgSettingsReadByIndexResp::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgSettingsReadByIndexResp(msg))
            }
            MsgFileioReadReq::MESSAGE_TYPE => {
                let mut msg = MsgFileioReadReq::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgFileioReadReq(msg))
            }
            MsgFileioReadDirReq::MESSAGE_TYPE => {
                let mut msg = MsgFileioReadDirReq::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgFileioReadDirReq(msg))
            }
            MsgFileioReadDirResp::MESSAGE_TYPE => {
                let mut msg = MsgFileioReadDirResp::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgFileioReadDirResp(msg))
            }
            MsgFileioWriteResp::MESSAGE_TYPE => {
                let mut msg = MsgFileioWriteResp::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgFileioWriteResp(msg))
            }
            MsgFileioRemove::MESSAGE_TYPE => {
                let mut msg = MsgFileioRemove::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgFileioRemove(msg))
            }
            MsgFileioWriteReq::MESSAGE_TYPE => {
                let mut msg = MsgFileioWriteReq::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgFileioWriteReq(msg))
            }
            MsgSettingsRegister::MESSAGE_TYPE => {
                let mut msg = MsgSettingsRegister::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgSettingsRegister(msg))
            }
            MsgSettingsWriteResp::MESSAGE_TYPE => {
                let mut msg = MsgSettingsWriteResp::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgSettingsWriteResp(msg))
            }
            MsgBootloaderHandshakeDepA::MESSAGE_TYPE => {
                let mut msg = MsgBootloaderHandshakeDepA::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgBootloaderHandshakeDepA(msg))
            }
            MsgBootloaderJumpToApp::MESSAGE_TYPE => {
                let mut msg = MsgBootloaderJumpToApp::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgBootloaderJumpToApp(msg))
            }
            MsgResetDep::MESSAGE_TYPE => {
                let mut msg = MsgResetDep::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgResetDep(msg))
            }
            MsgBootloaderHandshakeReq::MESSAGE_TYPE => {
                let mut msg = MsgBootloaderHandshakeReq::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgBootloaderHandshakeReq(msg))
            }
            MsgBootloaderHandshakeResp::MESSAGE_TYPE => {
                let mut msg = MsgBootloaderHandshakeResp::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgBootloaderHandshakeResp(msg))
            }
            MsgDeviceMonitor::MESSAGE_TYPE => {
                let mut msg = MsgDeviceMonitor::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgDeviceMonitor(msg))
            }
            MsgReset::MESSAGE_TYPE => {
                let mut msg = MsgReset::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgReset(msg))
            }
            MsgCommandReq::MESSAGE_TYPE => {
                let mut msg = MsgCommandReq::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgCommandReq(msg))
            }
            MsgCommandResp::MESSAGE_TYPE => {
                let mut msg = MsgCommandResp::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgCommandResp(msg))
            }
            MsgNetworkStateReq::MESSAGE_TYPE => {
                let mut msg = MsgNetworkStateReq::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgNetworkStateReq(msg))
            }
            MsgNetworkStateResp::MESSAGE_TYPE => {
                let mut msg = MsgNetworkStateResp::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgNetworkStateResp(msg))
            }
            MsgCommandOutput::MESSAGE_TYPE => {
                let mut msg = MsgCommandOutput::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgCommandOutput(msg))
            }
            MsgNetworkBandwidthUsage::MESSAGE_TYPE => {
                let mut msg = MsgNetworkBandwidthUsage::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgNetworkBandwidthUsage(msg))
            }
            MsgCellModemStatus::MESSAGE_TYPE => {
                let mut msg = MsgCellModemStatus::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgCellModemStatus(msg))
            }
            MsgFrontEndGain::MESSAGE_TYPE => {
                let mut msg = MsgFrontEndGain::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgFrontEndGain(msg))
            }
            MsgCwResults::MESSAGE_TYPE => {
                let mut msg = MsgCwResults::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgCwResults(msg))
            }
            MsgCwStart::MESSAGE_TYPE => {
                let mut msg = MsgCwStart::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgCwStart(msg))
            }
            MsgNapDeviceDnaResp::MESSAGE_TYPE => {
                let mut msg = MsgNapDeviceDnaResp::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgNapDeviceDnaResp(msg))
            }
            MsgNapDeviceDnaReq::MESSAGE_TYPE => {
                let mut msg = MsgNapDeviceDnaReq::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgNapDeviceDnaReq(msg))
            }
            MsgFlashDone::MESSAGE_TYPE => {
                let mut msg = MsgFlashDone::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgFlashDone(msg))
            }
            MsgFlashReadResp::MESSAGE_TYPE => {
                let mut msg = MsgFlashReadResp::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgFlashReadResp(msg))
            }
            MsgFlashErase::MESSAGE_TYPE => {
                let mut msg = MsgFlashErase::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgFlashErase(msg))
            }
            MsgStmFlashLockSector::MESSAGE_TYPE => {
                let mut msg = MsgStmFlashLockSector::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgStmFlashLockSector(msg))
            }
            MsgStmFlashUnlockSector::MESSAGE_TYPE => {
                let mut msg = MsgStmFlashUnlockSector::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgStmFlashUnlockSector(msg))
            }
            MsgStmUniqueIdResp::MESSAGE_TYPE => {
                let mut msg = MsgStmUniqueIdResp::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgStmUniqueIdResp(msg))
            }
            MsgFlashProgram::MESSAGE_TYPE => {
                let mut msg = MsgFlashProgram::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgFlashProgram(msg))
            }
            MsgFlashReadReq::MESSAGE_TYPE => {
                let mut msg = MsgFlashReadReq::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgFlashReadReq(msg))
            }
            MsgStmUniqueIdReq::MESSAGE_TYPE => {
                let mut msg = MsgStmUniqueIdReq::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgStmUniqueIdReq(msg))
            }
            MsgM25FlashWriteStatus::MESSAGE_TYPE => {
                let mut msg = MsgM25FlashWriteStatus::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgM25FlashWriteStatus(msg))
            }
            MsgGpsTimeDepA::MESSAGE_TYPE => {
                let mut msg = MsgGpsTimeDepA::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgGpsTimeDepA(msg))
            }
            MsgExtEvent::MESSAGE_TYPE => {
                let mut msg = MsgExtEvent::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgExtEvent(msg))
            }
            MsgGpsTime::MESSAGE_TYPE => {
                let mut msg = MsgGpsTime::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgGpsTime(msg))
            }
            MsgUtcTime::MESSAGE_TYPE => {
                let mut msg = MsgUtcTime::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgUtcTime(msg))
            }
            MsgGpsTimeGnss::MESSAGE_TYPE => {
                let mut msg = MsgGpsTimeGnss::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgGpsTimeGnss(msg))
            }
            MsgUtcTimeGnss::MESSAGE_TYPE => {
                let mut msg = MsgUtcTimeGnss::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgUtcTimeGnss(msg))
            }
            MsgSettingsRegisterResp::MESSAGE_TYPE => {
                let mut msg = MsgSettingsRegisterResp::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgSettingsRegisterResp(msg))
            }
            MsgPosEcefDepA::MESSAGE_TYPE => {
                let mut msg = MsgPosEcefDepA::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgPosEcefDepA(msg))
            }
            MsgPosLlhDepA::MESSAGE_TYPE => {
                let mut msg = MsgPosLlhDepA::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgPosLlhDepA(msg))
            }
            MsgBaselineEcefDepA::MESSAGE_TYPE => {
                let mut msg = MsgBaselineEcefDepA::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgBaselineEcefDepA(msg))
            }
            MsgBaselineNedDepA::MESSAGE_TYPE => {
                let mut msg = MsgBaselineNedDepA::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgBaselineNedDepA(msg))
            }
            MsgVelEcefDepA::MESSAGE_TYPE => {
                let mut msg = MsgVelEcefDepA::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgVelEcefDepA(msg))
            }
            MsgVelNedDepA::MESSAGE_TYPE => {
                let mut msg = MsgVelNedDepA::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgVelNedDepA(msg))
            }
            MsgDopsDepA::MESSAGE_TYPE => {
                let mut msg = MsgDopsDepA::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgDopsDepA(msg))
            }
            MsgBaselineHeadingDepA::MESSAGE_TYPE => {
                let mut msg = MsgBaselineHeadingDepA::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgBaselineHeadingDepA(msg))
            }
            MsgDops::MESSAGE_TYPE => {
                let mut msg = MsgDops::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgDops(msg))
            }
            MsgPosEcef::MESSAGE_TYPE => {
                let mut msg = MsgPosEcef::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgPosEcef(msg))
            }
            MsgPosLlh::MESSAGE_TYPE => {
                let mut msg = MsgPosLlh::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgPosLlh(msg))
            }
            MsgBaselineEcef::MESSAGE_TYPE => {
                let mut msg = MsgBaselineEcef::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgBaselineEcef(msg))
            }
            MsgBaselineNed::MESSAGE_TYPE => {
                let mut msg = MsgBaselineNed::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgBaselineNed(msg))
            }
            MsgVelEcef::MESSAGE_TYPE => {
                let mut msg = MsgVelEcef::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgVelEcef(msg))
            }
            MsgVelNed::MESSAGE_TYPE => {
                let mut msg = MsgVelNed::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgVelNed(msg))
            }
            MsgBaselineHeading::MESSAGE_TYPE => {
                let mut msg = MsgBaselineHeading::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgBaselineHeading(msg))
            }
            MsgAgeCorrections::MESSAGE_TYPE => {
                let mut msg = MsgAgeCorrections::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgAgeCorrections(msg))
            }
            MsgPosLlhCov::MESSAGE_TYPE => {
                let mut msg = MsgPosLlhCov::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgPosLlhCov(msg))
            }
            MsgVelNedCov::MESSAGE_TYPE => {
                let mut msg = MsgVelNedCov::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgVelNedCov(msg))
            }
            MsgVelBody::MESSAGE_TYPE => {
                let mut msg = MsgVelBody::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgVelBody(msg))
            }
            MsgPosEcefCov::MESSAGE_TYPE => {
                let mut msg = MsgPosEcefCov::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgPosEcefCov(msg))
            }
            MsgVelEcefCov::MESSAGE_TYPE => {
                let mut msg = MsgVelEcefCov::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgVelEcefCov(msg))
            }
            MsgProtectionLevelDepA::MESSAGE_TYPE => {
                let mut msg = MsgProtectionLevelDepA::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgProtectionLevelDepA(msg))
            }
            MsgProtectionLevel::MESSAGE_TYPE => {
                let mut msg = MsgProtectionLevel::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgProtectionLevel(msg))
            }
            MsgPosLlhAcc::MESSAGE_TYPE => {
                let mut msg = MsgPosLlhAcc::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgPosLlhAcc(msg))
            }
            MsgVelCog::MESSAGE_TYPE => {
                let mut msg = MsgVelCog::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgVelCog(msg))
            }
            MsgOrientQuat::MESSAGE_TYPE => {
                let mut msg = MsgOrientQuat::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgOrientQuat(msg))
            }
            MsgOrientEuler::MESSAGE_TYPE => {
                let mut msg = MsgOrientEuler::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgOrientEuler(msg))
            }
            MsgAngularRate::MESSAGE_TYPE => {
                let mut msg = MsgAngularRate::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgAngularRate(msg))
            }
            MsgPosEcefGnss::MESSAGE_TYPE => {
                let mut msg = MsgPosEcefGnss::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgPosEcefGnss(msg))
            }
            MsgPosLlhGnss::MESSAGE_TYPE => {
                let mut msg = MsgPosLlhGnss::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgPosLlhGnss(msg))
            }
            MsgVelEcefGnss::MESSAGE_TYPE => {
                let mut msg = MsgVelEcefGnss::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgVelEcefGnss(msg))
            }
            MsgVelNedGnss::MESSAGE_TYPE => {
                let mut msg = MsgVelNedGnss::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgVelNedGnss(msg))
            }
            MsgPosLlhCovGnss::MESSAGE_TYPE => {
                let mut msg = MsgPosLlhCovGnss::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgPosLlhCovGnss(msg))
            }
            MsgVelNedCovGnss::MESSAGE_TYPE => {
                let mut msg = MsgVelNedCovGnss::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgVelNedCovGnss(msg))
            }
            MsgPosEcefCovGnss::MESSAGE_TYPE => {
                let mut msg = MsgPosEcefCovGnss::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgPosEcefCovGnss(msg))
            }
            MsgVelEcefCovGnss::MESSAGE_TYPE => {
                let mut msg = MsgVelEcefCovGnss::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgVelEcefCovGnss(msg))
            }
            MsgUtcLeapSecond::MESSAGE_TYPE => {
                let mut msg = MsgUtcLeapSecond::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgUtcLeapSecond(msg))
            }
            MsgReferenceFrameParam::MESSAGE_TYPE => {
                let mut msg = MsgReferenceFrameParam::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgReferenceFrameParam(msg))
            }
            MsgNdbEvent::MESSAGE_TYPE => {
                let mut msg = MsgNdbEvent::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgNdbEvent(msg))
            }
            MsgLog::MESSAGE_TYPE => {
                let mut msg = MsgLog::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgLog(msg))
            }
            MsgFwd::MESSAGE_TYPE => {
                let mut msg = MsgFwd::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgFwd(msg))
            }
            MsgSsrOrbitClockDepA::MESSAGE_TYPE => {
                let mut msg = MsgSsrOrbitClockDepA::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgSsrOrbitClockDepA(msg))
            }
            MsgSsrOrbitClock::MESSAGE_TYPE => {
                let mut msg = MsgSsrOrbitClock::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgSsrOrbitClock(msg))
            }
            MsgSsrOrbitClockBounds::MESSAGE_TYPE => {
                let mut msg = MsgSsrOrbitClockBounds::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgSsrOrbitClockBounds(msg))
            }
            MsgSsrOrbitClockBoundsDegradation::MESSAGE_TYPE => {
                let mut msg = MsgSsrOrbitClockBoundsDegradation::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgSsrOrbitClockBoundsDegradation(msg))
            }
            MsgSsrCodeBiases::MESSAGE_TYPE => {
                let mut msg = MsgSsrCodeBiases::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgSsrCodeBiases(msg))
            }
            MsgSsrPhaseBiases::MESSAGE_TYPE => {
                let mut msg = MsgSsrPhaseBiases::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgSsrPhaseBiases(msg))
            }
            MsgSsrStecCorrectionDepA::MESSAGE_TYPE => {
                let mut msg = MsgSsrStecCorrectionDepA::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgSsrStecCorrectionDepA(msg))
            }
            MsgSsrCodePhaseBiasesBounds::MESSAGE_TYPE => {
                let mut msg = MsgSsrCodePhaseBiasesBounds::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgSsrCodePhaseBiasesBounds(msg))
            }
            MsgSsrGriddedCorrectionNoStdDepA::MESSAGE_TYPE => {
                let mut msg = MsgSsrGriddedCorrectionNoStdDepA::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgSsrGriddedCorrectionNoStdDepA(msg))
            }
            MsgSsrGridDefinitionDepA::MESSAGE_TYPE => {
                let mut msg = MsgSsrGridDefinitionDepA::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgSsrGridDefinitionDepA(msg))
            }
            MsgSsrTileDefinitionDep::MESSAGE_TYPE => {
                let mut msg = MsgSsrTileDefinitionDep::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgSsrTileDefinitionDep(msg))
            }
            MsgSsrTileDefinition::MESSAGE_TYPE => {
                let mut msg = MsgSsrTileDefinition::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgSsrTileDefinition(msg))
            }
            MsgSsrGriddedCorrectionDepA::MESSAGE_TYPE => {
                let mut msg = MsgSsrGriddedCorrectionDepA::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgSsrGriddedCorrectionDepA(msg))
            }
            MsgSsrStecCorrectionDep::MESSAGE_TYPE => {
                let mut msg = MsgSsrStecCorrectionDep::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgSsrStecCorrectionDep(msg))
            }
            MsgSsrGriddedCorrection::MESSAGE_TYPE => {
                let mut msg = MsgSsrGriddedCorrection::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgSsrGriddedCorrection(msg))
            }
            MsgSsrStecCorrection::MESSAGE_TYPE => {
                let mut msg = MsgSsrStecCorrection::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgSsrStecCorrection(msg))
            }
            MsgSsrGriddedCorrectionBounds::MESSAGE_TYPE => {
                let mut msg = MsgSsrGriddedCorrectionBounds::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgSsrGriddedCorrectionBounds(msg))
            }
            MsgSsrSatelliteApc::MESSAGE_TYPE => {
                let mut msg = MsgSsrSatelliteApc::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgSsrSatelliteApc(msg))
            }
            MsgOsr::MESSAGE_TYPE => {
                let mut msg = MsgOsr::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgOsr(msg))
            }
            MsgUserData::MESSAGE_TYPE => {
                let mut msg = MsgUserData::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgUserData(msg))
            }
            MsgImuRaw::MESSAGE_TYPE => {
                let mut msg = MsgImuRaw::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgImuRaw(msg))
            }
            MsgImuAux::MESSAGE_TYPE => {
                let mut msg = MsgImuAux::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgImuAux(msg))
            }
            MsgMagRaw::MESSAGE_TYPE => {
                let mut msg = MsgMagRaw::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgMagRaw(msg))
            }
            MsgOdometry::MESSAGE_TYPE => {
                let mut msg = MsgOdometry::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgOdometry(msg))
            }
            MsgWheeltick::MESSAGE_TYPE => {
                let mut msg = MsgWheeltick::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgWheeltick(msg))
            }
            MsgSsrFlagHighLevel::MESSAGE_TYPE => {
                let mut msg = MsgSsrFlagHighLevel::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgSsrFlagHighLevel(msg))
            }
            MsgSsrFlagSatellites::MESSAGE_TYPE => {
                let mut msg = MsgSsrFlagSatellites::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgSsrFlagSatellites(msg))
            }
            MsgSsrFlagTropoGridPoints::MESSAGE_TYPE => {
                let mut msg = MsgSsrFlagTropoGridPoints::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgSsrFlagTropoGridPoints(msg))
            }
            MsgSsrFlagIonoGridPoints::MESSAGE_TYPE => {
                let mut msg = MsgSsrFlagIonoGridPoints::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgSsrFlagIonoGridPoints(msg))
            }
            MsgSsrFlagIonoTileSatLos::MESSAGE_TYPE => {
                let mut msg = MsgSsrFlagIonoTileSatLos::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgSsrFlagIonoTileSatLos(msg))
            }
            MsgSsrFlagIonoGridPointSatLos::MESSAGE_TYPE => {
                let mut msg = MsgSsrFlagIonoGridPointSatLos::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgSsrFlagIonoGridPointSatLos(msg))
            }
            MsgEd25519Signature::MESSAGE_TYPE => {
                let mut msg = MsgEd25519Signature::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgEd25519Signature(msg))
            }
            MsgEd25519Certificate::MESSAGE_TYPE => {
                let mut msg = MsgEd25519Certificate::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgEd25519Certificate(msg))
            }
            MsgFileioConfigReq::MESSAGE_TYPE => {
                let mut msg = MsgFileioConfigReq::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgFileioConfigReq(msg))
            }
            MsgFileioConfigResp::MESSAGE_TYPE => {
                let mut msg = MsgFileioConfigResp::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgFileioConfigResp(msg))
            }
            MsgSbasRaw::MESSAGE_TYPE => {
                let mut msg = MsgSbasRaw::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgSbasRaw(msg))
            }
            MsgLinuxCpuStateDepA::MESSAGE_TYPE => {
                let mut msg = MsgLinuxCpuStateDepA::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgLinuxCpuStateDepA(msg))
            }
            MsgLinuxMemStateDepA::MESSAGE_TYPE => {
                let mut msg = MsgLinuxMemStateDepA::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgLinuxMemStateDepA(msg))
            }
            MsgLinuxSysStateDepA::MESSAGE_TYPE => {
                let mut msg = MsgLinuxSysStateDepA::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgLinuxSysStateDepA(msg))
            }
            MsgLinuxProcessSocketCounts::MESSAGE_TYPE => {
                let mut msg = MsgLinuxProcessSocketCounts::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgLinuxProcessSocketCounts(msg))
            }
            MsgLinuxProcessSocketQueues::MESSAGE_TYPE => {
                let mut msg = MsgLinuxProcessSocketQueues::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgLinuxProcessSocketQueues(msg))
            }
            MsgLinuxSocketUsage::MESSAGE_TYPE => {
                let mut msg = MsgLinuxSocketUsage::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgLinuxSocketUsage(msg))
            }
            MsgLinuxProcessFdCount::MESSAGE_TYPE => {
                let mut msg = MsgLinuxProcessFdCount::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgLinuxProcessFdCount(msg))
            }
            MsgLinuxProcessFdSummary::MESSAGE_TYPE => {
                let mut msg = MsgLinuxProcessFdSummary::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgLinuxProcessFdSummary(msg))
            }
            MsgLinuxCpuState::MESSAGE_TYPE => {
                let mut msg = MsgLinuxCpuState::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgLinuxCpuState(msg))
            }
            MsgLinuxMemState::MESSAGE_TYPE => {
                let mut msg = MsgLinuxMemState::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgLinuxMemState(msg))
            }
            MsgLinuxSysState::MESSAGE_TYPE => {
                let mut msg = MsgLinuxSysState::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgLinuxSysState(msg))
            }
            MsgStartup::MESSAGE_TYPE => {
                let mut msg = MsgStartup::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgStartup(msg))
            }
            MsgDgnssStatus::MESSAGE_TYPE => {
                let mut msg = MsgDgnssStatus::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgDgnssStatus(msg))
            }
            MsgInsStatus::MESSAGE_TYPE => {
                let mut msg = MsgInsStatus::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgInsStatus(msg))
            }
            MsgCsacTelemetry::MESSAGE_TYPE => {
                let mut msg = MsgCsacTelemetry::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgCsacTelemetry(msg))
            }
            MsgCsacTelemetryLabels::MESSAGE_TYPE => {
                let mut msg = MsgCsacTelemetryLabels::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgCsacTelemetryLabels(msg))
            }
            MsgInsUpdates::MESSAGE_TYPE => {
                let mut msg = MsgInsUpdates::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgInsUpdates(msg))
            }
            MsgGnssTimeOffset::MESSAGE_TYPE => {
                let mut msg = MsgGnssTimeOffset::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgGnssTimeOffset(msg))
            }
            MsgPpsTime::MESSAGE_TYPE => {
                let mut msg = MsgPpsTime::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgPpsTime(msg))
            }
            MsgSensorAidEvent::MESSAGE_TYPE => {
                let mut msg = MsgSensorAidEvent::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgSensorAidEvent(msg))
            }
            MsgGroupMeta::MESSAGE_TYPE => {
                let mut msg = MsgGroupMeta::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgGroupMeta(msg))
            }
            MsgSolnMeta::MESSAGE_TYPE => {
                let mut msg = MsgSolnMeta::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgSolnMeta(msg))
            }
            MsgSolnMetaDepA::MESSAGE_TYPE => {
                let mut msg = MsgSolnMetaDepA::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgSolnMetaDepA(msg))
            }
            MsgStatusJournal::MESSAGE_TYPE => {
                let mut msg = MsgStatusJournal::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgStatusJournal(msg))
            }
            MsgStatusReport::MESSAGE_TYPE => {
                let mut msg = MsgStatusReport::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgStatusReport(msg))
            }
            MsgHeartbeat::MESSAGE_TYPE => {
                let mut msg = MsgHeartbeat::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
                Ok(Sbp::MsgHeartbeat(msg))
            }
            _ => {
                let mut msg = Unknown::parse(&mut payload)?;
                msg.set_sender_id(sender_id);
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
            Sbp::MsgUtcLeapSecond(msg) => msg.message_name(),
            Sbp::MsgReferenceFrameParam(msg) => msg.message_name(),
            Sbp::MsgNdbEvent(msg) => msg.message_name(),
            Sbp::MsgLog(msg) => msg.message_name(),
            Sbp::MsgFwd(msg) => msg.message_name(),
            Sbp::MsgSsrOrbitClockDepA(msg) => msg.message_name(),
            Sbp::MsgSsrOrbitClock(msg) => msg.message_name(),
            Sbp::MsgSsrOrbitClockBounds(msg) => msg.message_name(),
            Sbp::MsgSsrOrbitClockBoundsDegradation(msg) => msg.message_name(),
            Sbp::MsgSsrCodeBiases(msg) => msg.message_name(),
            Sbp::MsgSsrPhaseBiases(msg) => msg.message_name(),
            Sbp::MsgSsrStecCorrectionDepA(msg) => msg.message_name(),
            Sbp::MsgSsrCodePhaseBiasesBounds(msg) => msg.message_name(),
            Sbp::MsgSsrGriddedCorrectionNoStdDepA(msg) => msg.message_name(),
            Sbp::MsgSsrGridDefinitionDepA(msg) => msg.message_name(),
            Sbp::MsgSsrTileDefinitionDep(msg) => msg.message_name(),
            Sbp::MsgSsrTileDefinition(msg) => msg.message_name(),
            Sbp::MsgSsrGriddedCorrectionDepA(msg) => msg.message_name(),
            Sbp::MsgSsrStecCorrectionDep(msg) => msg.message_name(),
            Sbp::MsgSsrGriddedCorrection(msg) => msg.message_name(),
            Sbp::MsgSsrStecCorrection(msg) => msg.message_name(),
            Sbp::MsgSsrGriddedCorrectionBounds(msg) => msg.message_name(),
            Sbp::MsgSsrSatelliteApc(msg) => msg.message_name(),
            Sbp::MsgOsr(msg) => msg.message_name(),
            Sbp::MsgUserData(msg) => msg.message_name(),
            Sbp::MsgImuRaw(msg) => msg.message_name(),
            Sbp::MsgImuAux(msg) => msg.message_name(),
            Sbp::MsgMagRaw(msg) => msg.message_name(),
            Sbp::MsgOdometry(msg) => msg.message_name(),
            Sbp::MsgWheeltick(msg) => msg.message_name(),
            Sbp::MsgSsrFlagHighLevel(msg) => msg.message_name(),
            Sbp::MsgSsrFlagSatellites(msg) => msg.message_name(),
            Sbp::MsgSsrFlagTropoGridPoints(msg) => msg.message_name(),
            Sbp::MsgSsrFlagIonoGridPoints(msg) => msg.message_name(),
            Sbp::MsgSsrFlagIonoTileSatLos(msg) => msg.message_name(),
            Sbp::MsgSsrFlagIonoGridPointSatLos(msg) => msg.message_name(),
            Sbp::MsgEd25519Signature(msg) => msg.message_name(),
            Sbp::MsgEd25519Certificate(msg) => msg.message_name(),
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
            Sbp::MsgSensorAidEvent(msg) => msg.message_name(),
            Sbp::MsgGroupMeta(msg) => msg.message_name(),
            Sbp::MsgSolnMeta(msg) => msg.message_name(),
            Sbp::MsgSolnMetaDepA(msg) => msg.message_name(),
            Sbp::MsgStatusJournal(msg) => msg.message_name(),
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
            Sbp::MsgUtcLeapSecond(msg) => msg.message_type(),
            Sbp::MsgReferenceFrameParam(msg) => msg.message_type(),
            Sbp::MsgNdbEvent(msg) => msg.message_type(),
            Sbp::MsgLog(msg) => msg.message_type(),
            Sbp::MsgFwd(msg) => msg.message_type(),
            Sbp::MsgSsrOrbitClockDepA(msg) => msg.message_type(),
            Sbp::MsgSsrOrbitClock(msg) => msg.message_type(),
            Sbp::MsgSsrOrbitClockBounds(msg) => msg.message_type(),
            Sbp::MsgSsrOrbitClockBoundsDegradation(msg) => msg.message_type(),
            Sbp::MsgSsrCodeBiases(msg) => msg.message_type(),
            Sbp::MsgSsrPhaseBiases(msg) => msg.message_type(),
            Sbp::MsgSsrStecCorrectionDepA(msg) => msg.message_type(),
            Sbp::MsgSsrCodePhaseBiasesBounds(msg) => msg.message_type(),
            Sbp::MsgSsrGriddedCorrectionNoStdDepA(msg) => msg.message_type(),
            Sbp::MsgSsrGridDefinitionDepA(msg) => msg.message_type(),
            Sbp::MsgSsrTileDefinitionDep(msg) => msg.message_type(),
            Sbp::MsgSsrTileDefinition(msg) => msg.message_type(),
            Sbp::MsgSsrGriddedCorrectionDepA(msg) => msg.message_type(),
            Sbp::MsgSsrStecCorrectionDep(msg) => msg.message_type(),
            Sbp::MsgSsrGriddedCorrection(msg) => msg.message_type(),
            Sbp::MsgSsrStecCorrection(msg) => msg.message_type(),
            Sbp::MsgSsrGriddedCorrectionBounds(msg) => msg.message_type(),
            Sbp::MsgSsrSatelliteApc(msg) => msg.message_type(),
            Sbp::MsgOsr(msg) => msg.message_type(),
            Sbp::MsgUserData(msg) => msg.message_type(),
            Sbp::MsgImuRaw(msg) => msg.message_type(),
            Sbp::MsgImuAux(msg) => msg.message_type(),
            Sbp::MsgMagRaw(msg) => msg.message_type(),
            Sbp::MsgOdometry(msg) => msg.message_type(),
            Sbp::MsgWheeltick(msg) => msg.message_type(),
            Sbp::MsgSsrFlagHighLevel(msg) => msg.message_type(),
            Sbp::MsgSsrFlagSatellites(msg) => msg.message_type(),
            Sbp::MsgSsrFlagTropoGridPoints(msg) => msg.message_type(),
            Sbp::MsgSsrFlagIonoGridPoints(msg) => msg.message_type(),
            Sbp::MsgSsrFlagIonoTileSatLos(msg) => msg.message_type(),
            Sbp::MsgSsrFlagIonoGridPointSatLos(msg) => msg.message_type(),
            Sbp::MsgEd25519Signature(msg) => msg.message_type(),
            Sbp::MsgEd25519Certificate(msg) => msg.message_type(),
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
            Sbp::MsgSensorAidEvent(msg) => msg.message_type(),
            Sbp::MsgGroupMeta(msg) => msg.message_type(),
            Sbp::MsgSolnMeta(msg) => msg.message_type(),
            Sbp::MsgSolnMetaDepA(msg) => msg.message_type(),
            Sbp::MsgStatusJournal(msg) => msg.message_type(),
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
            Sbp::MsgUtcLeapSecond(msg) => msg.sender_id(),
            Sbp::MsgReferenceFrameParam(msg) => msg.sender_id(),
            Sbp::MsgNdbEvent(msg) => msg.sender_id(),
            Sbp::MsgLog(msg) => msg.sender_id(),
            Sbp::MsgFwd(msg) => msg.sender_id(),
            Sbp::MsgSsrOrbitClockDepA(msg) => msg.sender_id(),
            Sbp::MsgSsrOrbitClock(msg) => msg.sender_id(),
            Sbp::MsgSsrOrbitClockBounds(msg) => msg.sender_id(),
            Sbp::MsgSsrOrbitClockBoundsDegradation(msg) => msg.sender_id(),
            Sbp::MsgSsrCodeBiases(msg) => msg.sender_id(),
            Sbp::MsgSsrPhaseBiases(msg) => msg.sender_id(),
            Sbp::MsgSsrStecCorrectionDepA(msg) => msg.sender_id(),
            Sbp::MsgSsrCodePhaseBiasesBounds(msg) => msg.sender_id(),
            Sbp::MsgSsrGriddedCorrectionNoStdDepA(msg) => msg.sender_id(),
            Sbp::MsgSsrGridDefinitionDepA(msg) => msg.sender_id(),
            Sbp::MsgSsrTileDefinitionDep(msg) => msg.sender_id(),
            Sbp::MsgSsrTileDefinition(msg) => msg.sender_id(),
            Sbp::MsgSsrGriddedCorrectionDepA(msg) => msg.sender_id(),
            Sbp::MsgSsrStecCorrectionDep(msg) => msg.sender_id(),
            Sbp::MsgSsrGriddedCorrection(msg) => msg.sender_id(),
            Sbp::MsgSsrStecCorrection(msg) => msg.sender_id(),
            Sbp::MsgSsrGriddedCorrectionBounds(msg) => msg.sender_id(),
            Sbp::MsgSsrSatelliteApc(msg) => msg.sender_id(),
            Sbp::MsgOsr(msg) => msg.sender_id(),
            Sbp::MsgUserData(msg) => msg.sender_id(),
            Sbp::MsgImuRaw(msg) => msg.sender_id(),
            Sbp::MsgImuAux(msg) => msg.sender_id(),
            Sbp::MsgMagRaw(msg) => msg.sender_id(),
            Sbp::MsgOdometry(msg) => msg.sender_id(),
            Sbp::MsgWheeltick(msg) => msg.sender_id(),
            Sbp::MsgSsrFlagHighLevel(msg) => msg.sender_id(),
            Sbp::MsgSsrFlagSatellites(msg) => msg.sender_id(),
            Sbp::MsgSsrFlagTropoGridPoints(msg) => msg.sender_id(),
            Sbp::MsgSsrFlagIonoGridPoints(msg) => msg.sender_id(),
            Sbp::MsgSsrFlagIonoTileSatLos(msg) => msg.sender_id(),
            Sbp::MsgSsrFlagIonoGridPointSatLos(msg) => msg.sender_id(),
            Sbp::MsgEd25519Signature(msg) => msg.sender_id(),
            Sbp::MsgEd25519Certificate(msg) => msg.sender_id(),
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
            Sbp::MsgSensorAidEvent(msg) => msg.sender_id(),
            Sbp::MsgGroupMeta(msg) => msg.sender_id(),
            Sbp::MsgSolnMeta(msg) => msg.sender_id(),
            Sbp::MsgSolnMetaDepA(msg) => msg.sender_id(),
            Sbp::MsgStatusJournal(msg) => msg.sender_id(),
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
            Sbp::MsgUtcLeapSecond(msg) => msg.set_sender_id(new_id),
            Sbp::MsgReferenceFrameParam(msg) => msg.set_sender_id(new_id),
            Sbp::MsgNdbEvent(msg) => msg.set_sender_id(new_id),
            Sbp::MsgLog(msg) => msg.set_sender_id(new_id),
            Sbp::MsgFwd(msg) => msg.set_sender_id(new_id),
            Sbp::MsgSsrOrbitClockDepA(msg) => msg.set_sender_id(new_id),
            Sbp::MsgSsrOrbitClock(msg) => msg.set_sender_id(new_id),
            Sbp::MsgSsrOrbitClockBounds(msg) => msg.set_sender_id(new_id),
            Sbp::MsgSsrOrbitClockBoundsDegradation(msg) => msg.set_sender_id(new_id),
            Sbp::MsgSsrCodeBiases(msg) => msg.set_sender_id(new_id),
            Sbp::MsgSsrPhaseBiases(msg) => msg.set_sender_id(new_id),
            Sbp::MsgSsrStecCorrectionDepA(msg) => msg.set_sender_id(new_id),
            Sbp::MsgSsrCodePhaseBiasesBounds(msg) => msg.set_sender_id(new_id),
            Sbp::MsgSsrGriddedCorrectionNoStdDepA(msg) => msg.set_sender_id(new_id),
            Sbp::MsgSsrGridDefinitionDepA(msg) => msg.set_sender_id(new_id),
            Sbp::MsgSsrTileDefinitionDep(msg) => msg.set_sender_id(new_id),
            Sbp::MsgSsrTileDefinition(msg) => msg.set_sender_id(new_id),
            Sbp::MsgSsrGriddedCorrectionDepA(msg) => msg.set_sender_id(new_id),
            Sbp::MsgSsrStecCorrectionDep(msg) => msg.set_sender_id(new_id),
            Sbp::MsgSsrGriddedCorrection(msg) => msg.set_sender_id(new_id),
            Sbp::MsgSsrStecCorrection(msg) => msg.set_sender_id(new_id),
            Sbp::MsgSsrGriddedCorrectionBounds(msg) => msg.set_sender_id(new_id),
            Sbp::MsgSsrSatelliteApc(msg) => msg.set_sender_id(new_id),
            Sbp::MsgOsr(msg) => msg.set_sender_id(new_id),
            Sbp::MsgUserData(msg) => msg.set_sender_id(new_id),
            Sbp::MsgImuRaw(msg) => msg.set_sender_id(new_id),
            Sbp::MsgImuAux(msg) => msg.set_sender_id(new_id),
            Sbp::MsgMagRaw(msg) => msg.set_sender_id(new_id),
            Sbp::MsgOdometry(msg) => msg.set_sender_id(new_id),
            Sbp::MsgWheeltick(msg) => msg.set_sender_id(new_id),
            Sbp::MsgSsrFlagHighLevel(msg) => msg.set_sender_id(new_id),
            Sbp::MsgSsrFlagSatellites(msg) => msg.set_sender_id(new_id),
            Sbp::MsgSsrFlagTropoGridPoints(msg) => msg.set_sender_id(new_id),
            Sbp::MsgSsrFlagIonoGridPoints(msg) => msg.set_sender_id(new_id),
            Sbp::MsgSsrFlagIonoTileSatLos(msg) => msg.set_sender_id(new_id),
            Sbp::MsgSsrFlagIonoGridPointSatLos(msg) => msg.set_sender_id(new_id),
            Sbp::MsgEd25519Signature(msg) => msg.set_sender_id(new_id),
            Sbp::MsgEd25519Certificate(msg) => msg.set_sender_id(new_id),
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
            Sbp::MsgSensorAidEvent(msg) => msg.set_sender_id(new_id),
            Sbp::MsgGroupMeta(msg) => msg.set_sender_id(new_id),
            Sbp::MsgSolnMeta(msg) => msg.set_sender_id(new_id),
            Sbp::MsgSolnMetaDepA(msg) => msg.set_sender_id(new_id),
            Sbp::MsgStatusJournal(msg) => msg.set_sender_id(new_id),
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
            Sbp::MsgUtcLeapSecond(msg) => msg.encoded_len(),
            Sbp::MsgReferenceFrameParam(msg) => msg.encoded_len(),
            Sbp::MsgNdbEvent(msg) => msg.encoded_len(),
            Sbp::MsgLog(msg) => msg.encoded_len(),
            Sbp::MsgFwd(msg) => msg.encoded_len(),
            Sbp::MsgSsrOrbitClockDepA(msg) => msg.encoded_len(),
            Sbp::MsgSsrOrbitClock(msg) => msg.encoded_len(),
            Sbp::MsgSsrOrbitClockBounds(msg) => msg.encoded_len(),
            Sbp::MsgSsrOrbitClockBoundsDegradation(msg) => msg.encoded_len(),
            Sbp::MsgSsrCodeBiases(msg) => msg.encoded_len(),
            Sbp::MsgSsrPhaseBiases(msg) => msg.encoded_len(),
            Sbp::MsgSsrStecCorrectionDepA(msg) => msg.encoded_len(),
            Sbp::MsgSsrCodePhaseBiasesBounds(msg) => msg.encoded_len(),
            Sbp::MsgSsrGriddedCorrectionNoStdDepA(msg) => msg.encoded_len(),
            Sbp::MsgSsrGridDefinitionDepA(msg) => msg.encoded_len(),
            Sbp::MsgSsrTileDefinitionDep(msg) => msg.encoded_len(),
            Sbp::MsgSsrTileDefinition(msg) => msg.encoded_len(),
            Sbp::MsgSsrGriddedCorrectionDepA(msg) => msg.encoded_len(),
            Sbp::MsgSsrStecCorrectionDep(msg) => msg.encoded_len(),
            Sbp::MsgSsrGriddedCorrection(msg) => msg.encoded_len(),
            Sbp::MsgSsrStecCorrection(msg) => msg.encoded_len(),
            Sbp::MsgSsrGriddedCorrectionBounds(msg) => msg.encoded_len(),
            Sbp::MsgSsrSatelliteApc(msg) => msg.encoded_len(),
            Sbp::MsgOsr(msg) => msg.encoded_len(),
            Sbp::MsgUserData(msg) => msg.encoded_len(),
            Sbp::MsgImuRaw(msg) => msg.encoded_len(),
            Sbp::MsgImuAux(msg) => msg.encoded_len(),
            Sbp::MsgMagRaw(msg) => msg.encoded_len(),
            Sbp::MsgOdometry(msg) => msg.encoded_len(),
            Sbp::MsgWheeltick(msg) => msg.encoded_len(),
            Sbp::MsgSsrFlagHighLevel(msg) => msg.encoded_len(),
            Sbp::MsgSsrFlagSatellites(msg) => msg.encoded_len(),
            Sbp::MsgSsrFlagTropoGridPoints(msg) => msg.encoded_len(),
            Sbp::MsgSsrFlagIonoGridPoints(msg) => msg.encoded_len(),
            Sbp::MsgSsrFlagIonoTileSatLos(msg) => msg.encoded_len(),
            Sbp::MsgSsrFlagIonoGridPointSatLos(msg) => msg.encoded_len(),
            Sbp::MsgEd25519Signature(msg) => msg.encoded_len(),
            Sbp::MsgEd25519Certificate(msg) => msg.encoded_len(),
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
            Sbp::MsgSensorAidEvent(msg) => msg.encoded_len(),
            Sbp::MsgGroupMeta(msg) => msg.encoded_len(),
            Sbp::MsgSolnMeta(msg) => msg.encoded_len(),
            Sbp::MsgSolnMetaDepA(msg) => msg.encoded_len(),
            Sbp::MsgStatusJournal(msg) => msg.encoded_len(),
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
            Sbp::MsgUtcLeapSecond(msg) => msg.gps_time(),
            Sbp::MsgReferenceFrameParam(msg) => msg.gps_time(),
            Sbp::MsgNdbEvent(msg) => msg.gps_time(),
            Sbp::MsgLog(msg) => msg.gps_time(),
            Sbp::MsgFwd(msg) => msg.gps_time(),
            Sbp::MsgSsrOrbitClockDepA(msg) => msg.gps_time(),
            Sbp::MsgSsrOrbitClock(msg) => msg.gps_time(),
            Sbp::MsgSsrOrbitClockBounds(msg) => msg.gps_time(),
            Sbp::MsgSsrOrbitClockBoundsDegradation(msg) => msg.gps_time(),
            Sbp::MsgSsrCodeBiases(msg) => msg.gps_time(),
            Sbp::MsgSsrPhaseBiases(msg) => msg.gps_time(),
            Sbp::MsgSsrStecCorrectionDepA(msg) => msg.gps_time(),
            Sbp::MsgSsrCodePhaseBiasesBounds(msg) => msg.gps_time(),
            Sbp::MsgSsrGriddedCorrectionNoStdDepA(msg) => msg.gps_time(),
            Sbp::MsgSsrGridDefinitionDepA(msg) => msg.gps_time(),
            Sbp::MsgSsrTileDefinitionDep(msg) => msg.gps_time(),
            Sbp::MsgSsrTileDefinition(msg) => msg.gps_time(),
            Sbp::MsgSsrGriddedCorrectionDepA(msg) => msg.gps_time(),
            Sbp::MsgSsrStecCorrectionDep(msg) => msg.gps_time(),
            Sbp::MsgSsrGriddedCorrection(msg) => msg.gps_time(),
            Sbp::MsgSsrStecCorrection(msg) => msg.gps_time(),
            Sbp::MsgSsrGriddedCorrectionBounds(msg) => msg.gps_time(),
            Sbp::MsgSsrSatelliteApc(msg) => msg.gps_time(),
            Sbp::MsgOsr(msg) => msg.gps_time(),
            Sbp::MsgUserData(msg) => msg.gps_time(),
            Sbp::MsgImuRaw(msg) => msg.gps_time(),
            Sbp::MsgImuAux(msg) => msg.gps_time(),
            Sbp::MsgMagRaw(msg) => msg.gps_time(),
            Sbp::MsgOdometry(msg) => msg.gps_time(),
            Sbp::MsgWheeltick(msg) => msg.gps_time(),
            Sbp::MsgSsrFlagHighLevel(msg) => msg.gps_time(),
            Sbp::MsgSsrFlagSatellites(msg) => msg.gps_time(),
            Sbp::MsgSsrFlagTropoGridPoints(msg) => msg.gps_time(),
            Sbp::MsgSsrFlagIonoGridPoints(msg) => msg.gps_time(),
            Sbp::MsgSsrFlagIonoTileSatLos(msg) => msg.gps_time(),
            Sbp::MsgSsrFlagIonoGridPointSatLos(msg) => msg.gps_time(),
            Sbp::MsgEd25519Signature(msg) => msg.gps_time(),
            Sbp::MsgEd25519Certificate(msg) => msg.gps_time(),
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
            Sbp::MsgSensorAidEvent(msg) => msg.gps_time(),
            Sbp::MsgGroupMeta(msg) => msg.gps_time(),
            Sbp::MsgSolnMeta(msg) => msg.gps_time(),
            Sbp::MsgSolnMetaDepA(msg) => msg.gps_time(),
            Sbp::MsgStatusJournal(msg) => msg.gps_time(),
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
            Sbp::MsgUtcLeapSecond(msg) => WireFormat::write(msg, buf),
            Sbp::MsgReferenceFrameParam(msg) => WireFormat::write(msg, buf),
            Sbp::MsgNdbEvent(msg) => WireFormat::write(msg, buf),
            Sbp::MsgLog(msg) => WireFormat::write(msg, buf),
            Sbp::MsgFwd(msg) => WireFormat::write(msg, buf),
            Sbp::MsgSsrOrbitClockDepA(msg) => WireFormat::write(msg, buf),
            Sbp::MsgSsrOrbitClock(msg) => WireFormat::write(msg, buf),
            Sbp::MsgSsrOrbitClockBounds(msg) => WireFormat::write(msg, buf),
            Sbp::MsgSsrOrbitClockBoundsDegradation(msg) => WireFormat::write(msg, buf),
            Sbp::MsgSsrCodeBiases(msg) => WireFormat::write(msg, buf),
            Sbp::MsgSsrPhaseBiases(msg) => WireFormat::write(msg, buf),
            Sbp::MsgSsrStecCorrectionDepA(msg) => WireFormat::write(msg, buf),
            Sbp::MsgSsrCodePhaseBiasesBounds(msg) => WireFormat::write(msg, buf),
            Sbp::MsgSsrGriddedCorrectionNoStdDepA(msg) => WireFormat::write(msg, buf),
            Sbp::MsgSsrGridDefinitionDepA(msg) => WireFormat::write(msg, buf),
            Sbp::MsgSsrTileDefinitionDep(msg) => WireFormat::write(msg, buf),
            Sbp::MsgSsrTileDefinition(msg) => WireFormat::write(msg, buf),
            Sbp::MsgSsrGriddedCorrectionDepA(msg) => WireFormat::write(msg, buf),
            Sbp::MsgSsrStecCorrectionDep(msg) => WireFormat::write(msg, buf),
            Sbp::MsgSsrGriddedCorrection(msg) => WireFormat::write(msg, buf),
            Sbp::MsgSsrStecCorrection(msg) => WireFormat::write(msg, buf),
            Sbp::MsgSsrGriddedCorrectionBounds(msg) => WireFormat::write(msg, buf),
            Sbp::MsgSsrSatelliteApc(msg) => WireFormat::write(msg, buf),
            Sbp::MsgOsr(msg) => WireFormat::write(msg, buf),
            Sbp::MsgUserData(msg) => WireFormat::write(msg, buf),
            Sbp::MsgImuRaw(msg) => WireFormat::write(msg, buf),
            Sbp::MsgImuAux(msg) => WireFormat::write(msg, buf),
            Sbp::MsgMagRaw(msg) => WireFormat::write(msg, buf),
            Sbp::MsgOdometry(msg) => WireFormat::write(msg, buf),
            Sbp::MsgWheeltick(msg) => WireFormat::write(msg, buf),
            Sbp::MsgSsrFlagHighLevel(msg) => WireFormat::write(msg, buf),
            Sbp::MsgSsrFlagSatellites(msg) => WireFormat::write(msg, buf),
            Sbp::MsgSsrFlagTropoGridPoints(msg) => WireFormat::write(msg, buf),
            Sbp::MsgSsrFlagIonoGridPoints(msg) => WireFormat::write(msg, buf),
            Sbp::MsgSsrFlagIonoTileSatLos(msg) => WireFormat::write(msg, buf),
            Sbp::MsgSsrFlagIonoGridPointSatLos(msg) => WireFormat::write(msg, buf),
            Sbp::MsgEd25519Signature(msg) => WireFormat::write(msg, buf),
            Sbp::MsgEd25519Certificate(msg) => WireFormat::write(msg, buf),
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
            Sbp::MsgSensorAidEvent(msg) => WireFormat::write(msg, buf),
            Sbp::MsgGroupMeta(msg) => WireFormat::write(msg, buf),
            Sbp::MsgSolnMeta(msg) => WireFormat::write(msg, buf),
            Sbp::MsgSolnMetaDepA(msg) => WireFormat::write(msg, buf),
            Sbp::MsgStatusJournal(msg) => WireFormat::write(msg, buf),
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
            Sbp::MsgUtcLeapSecond(msg) => WireFormat::len(msg),
            Sbp::MsgReferenceFrameParam(msg) => WireFormat::len(msg),
            Sbp::MsgNdbEvent(msg) => WireFormat::len(msg),
            Sbp::MsgLog(msg) => WireFormat::len(msg),
            Sbp::MsgFwd(msg) => WireFormat::len(msg),
            Sbp::MsgSsrOrbitClockDepA(msg) => WireFormat::len(msg),
            Sbp::MsgSsrOrbitClock(msg) => WireFormat::len(msg),
            Sbp::MsgSsrOrbitClockBounds(msg) => WireFormat::len(msg),
            Sbp::MsgSsrOrbitClockBoundsDegradation(msg) => WireFormat::len(msg),
            Sbp::MsgSsrCodeBiases(msg) => WireFormat::len(msg),
            Sbp::MsgSsrPhaseBiases(msg) => WireFormat::len(msg),
            Sbp::MsgSsrStecCorrectionDepA(msg) => WireFormat::len(msg),
            Sbp::MsgSsrCodePhaseBiasesBounds(msg) => WireFormat::len(msg),
            Sbp::MsgSsrGriddedCorrectionNoStdDepA(msg) => WireFormat::len(msg),
            Sbp::MsgSsrGridDefinitionDepA(msg) => WireFormat::len(msg),
            Sbp::MsgSsrTileDefinitionDep(msg) => WireFormat::len(msg),
            Sbp::MsgSsrTileDefinition(msg) => WireFormat::len(msg),
            Sbp::MsgSsrGriddedCorrectionDepA(msg) => WireFormat::len(msg),
            Sbp::MsgSsrStecCorrectionDep(msg) => WireFormat::len(msg),
            Sbp::MsgSsrGriddedCorrection(msg) => WireFormat::len(msg),
            Sbp::MsgSsrStecCorrection(msg) => WireFormat::len(msg),
            Sbp::MsgSsrGriddedCorrectionBounds(msg) => WireFormat::len(msg),
            Sbp::MsgSsrSatelliteApc(msg) => WireFormat::len(msg),
            Sbp::MsgOsr(msg) => WireFormat::len(msg),
            Sbp::MsgUserData(msg) => WireFormat::len(msg),
            Sbp::MsgImuRaw(msg) => WireFormat::len(msg),
            Sbp::MsgImuAux(msg) => WireFormat::len(msg),
            Sbp::MsgMagRaw(msg) => WireFormat::len(msg),
            Sbp::MsgOdometry(msg) => WireFormat::len(msg),
            Sbp::MsgWheeltick(msg) => WireFormat::len(msg),
            Sbp::MsgSsrFlagHighLevel(msg) => WireFormat::len(msg),
            Sbp::MsgSsrFlagSatellites(msg) => WireFormat::len(msg),
            Sbp::MsgSsrFlagTropoGridPoints(msg) => WireFormat::len(msg),
            Sbp::MsgSsrFlagIonoGridPoints(msg) => WireFormat::len(msg),
            Sbp::MsgSsrFlagIonoTileSatLos(msg) => WireFormat::len(msg),
            Sbp::MsgSsrFlagIonoGridPointSatLos(msg) => WireFormat::len(msg),
            Sbp::MsgEd25519Signature(msg) => WireFormat::len(msg),
            Sbp::MsgEd25519Certificate(msg) => WireFormat::len(msg),
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
            Sbp::MsgSensorAidEvent(msg) => WireFormat::len(msg),
            Sbp::MsgGroupMeta(msg) => WireFormat::len(msg),
            Sbp::MsgSolnMeta(msg) => WireFormat::len(msg),
            Sbp::MsgSolnMetaDepA(msg) => WireFormat::len(msg),
            Sbp::MsgStatusJournal(msg) => WireFormat::len(msg),
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

impl From<MsgUtcLeapSecond> for Sbp {
    fn from(msg: MsgUtcLeapSecond) -> Self {
        Sbp::MsgUtcLeapSecond(msg)
    }
}

impl From<MsgReferenceFrameParam> for Sbp {
    fn from(msg: MsgReferenceFrameParam) -> Self {
        Sbp::MsgReferenceFrameParam(msg)
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

impl From<MsgSsrOrbitClockBounds> for Sbp {
    fn from(msg: MsgSsrOrbitClockBounds) -> Self {
        Sbp::MsgSsrOrbitClockBounds(msg)
    }
}

impl From<MsgSsrOrbitClockBoundsDegradation> for Sbp {
    fn from(msg: MsgSsrOrbitClockBoundsDegradation) -> Self {
        Sbp::MsgSsrOrbitClockBoundsDegradation(msg)
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

impl From<MsgSsrCodePhaseBiasesBounds> for Sbp {
    fn from(msg: MsgSsrCodePhaseBiasesBounds) -> Self {
        Sbp::MsgSsrCodePhaseBiasesBounds(msg)
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

impl From<MsgSsrTileDefinitionDep> for Sbp {
    fn from(msg: MsgSsrTileDefinitionDep) -> Self {
        Sbp::MsgSsrTileDefinitionDep(msg)
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

impl From<MsgSsrStecCorrectionDep> for Sbp {
    fn from(msg: MsgSsrStecCorrectionDep) -> Self {
        Sbp::MsgSsrStecCorrectionDep(msg)
    }
}

impl From<MsgSsrGriddedCorrection> for Sbp {
    fn from(msg: MsgSsrGriddedCorrection) -> Self {
        Sbp::MsgSsrGriddedCorrection(msg)
    }
}

impl From<MsgSsrStecCorrection> for Sbp {
    fn from(msg: MsgSsrStecCorrection) -> Self {
        Sbp::MsgSsrStecCorrection(msg)
    }
}

impl From<MsgSsrGriddedCorrectionBounds> for Sbp {
    fn from(msg: MsgSsrGriddedCorrectionBounds) -> Self {
        Sbp::MsgSsrGriddedCorrectionBounds(msg)
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

impl From<MsgSsrFlagHighLevel> for Sbp {
    fn from(msg: MsgSsrFlagHighLevel) -> Self {
        Sbp::MsgSsrFlagHighLevel(msg)
    }
}

impl From<MsgSsrFlagSatellites> for Sbp {
    fn from(msg: MsgSsrFlagSatellites) -> Self {
        Sbp::MsgSsrFlagSatellites(msg)
    }
}

impl From<MsgSsrFlagTropoGridPoints> for Sbp {
    fn from(msg: MsgSsrFlagTropoGridPoints) -> Self {
        Sbp::MsgSsrFlagTropoGridPoints(msg)
    }
}

impl From<MsgSsrFlagIonoGridPoints> for Sbp {
    fn from(msg: MsgSsrFlagIonoGridPoints) -> Self {
        Sbp::MsgSsrFlagIonoGridPoints(msg)
    }
}

impl From<MsgSsrFlagIonoTileSatLos> for Sbp {
    fn from(msg: MsgSsrFlagIonoTileSatLos) -> Self {
        Sbp::MsgSsrFlagIonoTileSatLos(msg)
    }
}

impl From<MsgSsrFlagIonoGridPointSatLos> for Sbp {
    fn from(msg: MsgSsrFlagIonoGridPointSatLos) -> Self {
        Sbp::MsgSsrFlagIonoGridPointSatLos(msg)
    }
}

impl From<MsgEd25519Signature> for Sbp {
    fn from(msg: MsgEd25519Signature) -> Self {
        Sbp::MsgEd25519Signature(msg)
    }
}

impl From<MsgEd25519Certificate> for Sbp {
    fn from(msg: MsgEd25519Certificate) -> Self {
        Sbp::MsgEd25519Certificate(msg)
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

impl From<MsgSensorAidEvent> for Sbp {
    fn from(msg: MsgSensorAidEvent) -> Self {
        Sbp::MsgSensorAidEvent(msg)
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

impl From<MsgStatusJournal> for Sbp {
    fn from(msg: MsgStatusJournal) -> Self {
        Sbp::MsgStatusJournal(msg)
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
