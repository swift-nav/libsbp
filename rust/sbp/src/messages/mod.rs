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

//****************************************************************************
// Automatically generated from
// 'generator/sbpg/targets/resources/rust/sbp_messages_mod.rs'
//
// Please do not hand edit!
//****************************************************************************/
pub mod acquisition;
pub mod bootload;
pub mod ext_events;
pub mod file_io;
pub mod flash;
pub mod gnss;
pub mod imu;
pub mod integrity;
pub mod invalid;
pub mod linux;
pub mod logging;
pub mod mag;
pub mod navigation;
pub mod ndb;
pub mod observation;
pub mod orientation;
pub mod piksi;
pub mod profiling;
pub mod sbas;
pub mod settings;
pub mod signing;
pub mod solution_meta;
pub mod ssr;
pub mod system;
pub mod telemetry;
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
use self::integrity::msg_acknowledge::MsgAcknowledge;
use self::integrity::msg_ssr_flag_high_level::MsgSsrFlagHighLevel;
use self::integrity::msg_ssr_flag_iono_grid_point_sat_los::MsgSsrFlagIonoGridPointSatLos;
use self::integrity::msg_ssr_flag_iono_grid_points::MsgSsrFlagIonoGridPoints;
use self::integrity::msg_ssr_flag_iono_tile_sat_los::MsgSsrFlagIonoTileSatLos;
use self::integrity::msg_ssr_flag_satellites::MsgSsrFlagSatellites;
use self::integrity::msg_ssr_flag_tropo_grid_points::MsgSsrFlagTropoGridPoints;
use self::invalid::Invalid;
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
use self::navigation::msg_pose_relative::MsgPoseRelative;
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
use self::profiling::msg_measurement_point::MsgMeasurementPoint;
use self::profiling::msg_profiling_resource_counter::MsgProfilingResourceCounter;
use self::profiling::msg_profiling_system_info::MsgProfilingSystemInfo;
use self::profiling::msg_profiling_thread_info::MsgProfilingThreadInfo;
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
use self::signing::msg_certificate_chain::MsgCertificateChain;
use self::signing::msg_certificate_chain_dep::MsgCertificateChainDep;
use self::signing::msg_ecdsa_certificate::MsgEcdsaCertificate;
use self::signing::msg_ecdsa_signature::MsgEcdsaSignature;
use self::signing::msg_ecdsa_signature_dep_a::MsgEcdsaSignatureDepA;
use self::signing::msg_ecdsa_signature_dep_b::MsgEcdsaSignatureDepB;
use self::signing::msg_ed25519_certificate_dep::MsgEd25519CertificateDep;
use self::signing::msg_ed25519_signature_dep_a::MsgEd25519SignatureDepA;
use self::signing::msg_ed25519_signature_dep_b::MsgEd25519SignatureDepB;
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
use self::ssr::msg_ssr_satellite_apc_dep::MsgSsrSatelliteApcDep;
use self::ssr::msg_ssr_stec_correction::MsgSsrStecCorrection;
use self::ssr::msg_ssr_stec_correction_dep::MsgSsrStecCorrectionDep;
use self::ssr::msg_ssr_stec_correction_dep_a::MsgSsrStecCorrectionDepA;
use self::ssr::msg_ssr_tile_definition::MsgSsrTileDefinition;
use self::ssr::msg_ssr_tile_definition_dep_a::MsgSsrTileDefinitionDepA;
use self::ssr::msg_ssr_tile_definition_dep_b::MsgSsrTileDefinitionDepB;
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
use self::telemetry::msg_tel_sv::MsgTelSv;
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

    pub use super::{ConcreteMessage, FriendlyName, Sbp, SbpMessage, TryFromSbpError};

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
pub trait SbpMessage: WireFormat + Clone {
    /// Get the message name.
    fn message_name(&self) -> &'static str;
    /// Get the message type.
    fn message_type(&self) -> Option<u16>;
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
    /// Get friendly name associated with the message.
    fn friendly_name(&self) -> &'static str {
        ""
    }
    /// Tells you if the message is valid or if it is not a valid message and may need to be
    /// special cased at certain points.
    fn is_valid(&self) -> bool;
    fn into_valid_msg(self) -> Result<Self, crate::messages::invalid::Invalid>;
}

/// Implemented by messages who's message name and type are known at compile time.
/// This is everything that implements [SbpMessage] except for [Sbp].
pub trait ConcreteMessage: SbpMessage + TryFrom<Sbp, Error = TryFromSbpError> {
    /// The message type.
    const MESSAGE_TYPE: u16;
    /// The message name.
    const MESSAGE_NAME: &'static str;
}

/// Friendly name representation of Sbp message
pub trait FriendlyName {
    fn friendly_name() -> &'static str;
}

/// The error returned when using [TryFrom] to convert [Sbp] to the wrong message type.
#[derive(Debug, Clone)]
pub struct TryFromSbpError(pub Sbp);

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
    /// Deprecated
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
    /// Deprecated
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
    /// Deprecated
    MsgAlmanacGpsDep(MsgAlmanacGpsDep),
    /// Deprecated
    MsgAlmanacGloDep(MsgAlmanacGloDep),
    /// Satellite broadcast almanac for GPS
    MsgAlmanacGps(MsgAlmanacGps),
    /// Satellite broadcast almanac for GLO
    MsgAlmanacGlo(MsgAlmanacGlo),
    /// GLONASS L1/L2 Code-Phase biases
    MsgGloBiases(MsgGloBiases),
    /// Deprecated
    MsgEphemerisDepD(MsgEphemerisDepD),
    /// Deprecated
    MsgEphemerisGpsDepE(MsgEphemerisGpsDepE),
    /// Deprecated
    MsgEphemerisSbasDepA(MsgEphemerisSbasDepA),
    /// Deprecated
    MsgEphemerisGloDepA(MsgEphemerisGloDepA),
    /// Deprecated
    MsgEphemerisSbasDepB(MsgEphemerisSbasDepB),
    /// Deprecated
    MsgEphemerisGloDepB(MsgEphemerisGloDepB),
    /// Deprecated
    MsgEphemerisGpsDepF(MsgEphemerisGpsDepF),
    /// Deprecated
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
    /// Deprecated
    MsgSvConfigurationGpsDep(MsgSvConfigurationGpsDep),
    /// Deprecated
    MsgGroupDelayDepA(MsgGroupDelayDepA),
    /// Deprecated
    MsgGroupDelayDepB(MsgGroupDelayDepB),
    /// Group Delay
    MsgGroupDelay(MsgGroupDelay),
    /// Deprecated
    MsgEphemerisGalDepA(MsgEphemerisGalDepA),
    /// GNSS capabilities masks
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
    /// Deprecated
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
    /// Deprecated
    MsgGpsTimeDepA(MsgGpsTimeDepA),
    /// Reports timestamped external pin event
    MsgExtEvent(MsgExtEvent),
    /// GPS Time (GNSS + inertial)
    MsgGpsTime(MsgGpsTime),
    /// UTC Time
    MsgUtcTime(MsgUtcTime),
    /// GNSS-only GPS Time
    MsgGpsTimeGnss(MsgGpsTimeGnss),
    /// GNSS-only UTC Time
    MsgUtcTimeGnss(MsgUtcTimeGnss),
    /// Per-signal telemetry
    MsgTelSv(MsgTelSv),
    /// Register setting and default value (device <= host)
    MsgSettingsRegisterResp(MsgSettingsRegisterResp),
    /// Deprecated
    MsgPosEcefDepA(MsgPosEcefDepA),
    /// Deprecated
    MsgPosLlhDepA(MsgPosLlhDepA),
    /// Deprecated
    MsgBaselineEcefDepA(MsgBaselineEcefDepA),
    /// Deprecated
    MsgBaselineNedDepA(MsgBaselineNedDepA),
    /// Deprecated
    MsgVelEcefDepA(MsgVelEcefDepA),
    /// Deprecated
    MsgVelNedDepA(MsgVelNedDepA),
    /// Deprecated
    MsgDopsDepA(MsgDopsDepA),
    /// Deprecated
    MsgBaselineHeadingDepA(MsgBaselineHeadingDepA),
    /// GNSS-only Dilution of Precision
    MsgDops(MsgDops),
    /// Position in ECEF
    MsgPosEcef(MsgPosEcef),
    /// Geodetic Position
    MsgPosLlh(MsgPosLlh),
    /// GNSS-only Baseline Position in ECEF
    MsgBaselineEcef(MsgBaselineEcef),
    /// GNSS-only Baseline in NED
    MsgBaselineNed(MsgBaselineNed),
    /// Velocity in ECEF
    MsgVelEcef(MsgVelEcef),
    /// Velocity in NED
    MsgVelNed(MsgVelNed),
    /// Heading relative to True North
    MsgBaselineHeading(MsgBaselineHeading),
    /// Age of corrections
    MsgAgeCorrections(MsgAgeCorrections),
    /// Geodetic Position with Covariances
    MsgPosLlhCov(MsgPosLlhCov),
    /// Velocity in NED with Covariances
    MsgVelNedCov(MsgVelNedCov),
    /// Velocity in User Frame
    MsgVelBody(MsgVelBody),
    /// Position in ECEF with Covariances
    MsgPosEcefCov(MsgPosEcefCov),
    /// Velocity in ECEF with Covariances
    MsgVelEcefCov(MsgVelEcefCov),
    /// Deprecated
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
    /// GNSS-only Geodetic Position with Covariances
    MsgPosLlhCovGnss(MsgPosLlhCovGnss),
    /// GNSS-only Velocity in NED with Covariances
    MsgVelNedCovGnss(MsgVelNedCovGnss),
    /// GNSS-only Position in ECEF with Covariances
    MsgPosEcefCovGnss(MsgPosEcefCovGnss),
    /// GNSS-only Velocity in ECEF with Covariances
    MsgVelEcefCovGnss(MsgVelEcefCovGnss),
    /// Leap second SBP message.
    MsgUtcLeapSecond(MsgUtcLeapSecond),
    /// Reference Frame Transformation Parameters
    MsgReferenceFrameParam(MsgReferenceFrameParam),
    /// Relative Pose
    MsgPoseRelative(MsgPoseRelative),
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
    /// Deprecated
    MsgSsrTileDefinitionDepA(MsgSsrTileDefinitionDepA),
    /// Deprecated
    MsgSsrTileDefinitionDepB(MsgSsrTileDefinitionDepB),
    /// Definition of a SSR atmospheric correction tile.
    MsgSsrTileDefinition(MsgSsrTileDefinition),
    /// Deprecated
    MsgSsrGriddedCorrectionDepA(MsgSsrGriddedCorrectionDepA),
    /// Deprecated
    MsgSsrStecCorrectionDep(MsgSsrStecCorrectionDep),
    /// Gridded troposphere and STEC correction residuals
    MsgSsrGriddedCorrection(MsgSsrGriddedCorrection),
    /// STEC correction polynomial coefficients
    MsgSsrStecCorrection(MsgSsrStecCorrection),
    /// Gridded troposhere and STEC correction residuals bounds
    MsgSsrGriddedCorrectionBounds(MsgSsrGriddedCorrectionBounds),
    /// Deprecated
    MsgSsrSatelliteApcDep(MsgSsrSatelliteApcDep),
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
    /// Acknowledgement message in response to a request for corrections
    MsgAcknowledge(MsgAcknowledge),
    /// Deprecated
    MsgEd25519SignatureDepA(MsgEd25519SignatureDepA),
    /// Deprecated
    MsgEd25519CertificateDep(MsgEd25519CertificateDep),
    /// Deprecated
    MsgEd25519SignatureDepB(MsgEd25519SignatureDepB),
    /// An ECDSA certificate split over multiple messages
    MsgEcdsaCertificate(MsgEcdsaCertificate),
    /// Deprecated
    MsgCertificateChainDep(MsgCertificateChainDep),
    /// Deprecated
    MsgEcdsaSignatureDepA(MsgEcdsaSignatureDepA),
    /// Deprecated
    MsgEcdsaSignatureDepB(MsgEcdsaSignatureDepB),
    /// An ECDSA signature
    MsgEcdsaSignature(MsgEcdsaSignature),
    /// The certificate chain
    MsgCertificateChain(MsgCertificateChain),
    /// Request advice on the optimal configuration for FileIO
    MsgFileioConfigReq(MsgFileioConfigReq),
    /// Response with advice on the optimal configuration for FileIO.
    MsgFileioConfigResp(MsgFileioConfigResp),
    /// Raw SBAS data
    MsgSbasRaw(MsgSbasRaw),
    /// Deprecated
    MsgLinuxCpuStateDepA(MsgLinuxCpuStateDepA),
    /// Deprecated
    MsgLinuxMemStateDepA(MsgLinuxMemStateDepA),
    /// Deprecated
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
    /// Profiling Measurement Point
    MsgMeasurementPoint(MsgMeasurementPoint),
    /// System Profiling Information
    MsgProfilingSystemInfo(MsgProfilingSystemInfo),
    /// Thread Profiling Information
    MsgProfilingThreadInfo(MsgProfilingThreadInfo),
    /// Information about resource buckets
    MsgProfilingResourceCounter(MsgProfilingResourceCounter),
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
    /// Invalid message type.
    Invalid(Invalid),
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
            Some(MsgTelSv::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgTelSv>(value).map(Sbp::MsgTelSv)
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
            Some(MsgPoseRelative::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgPoseRelative>(value).map(Sbp::MsgPoseRelative)
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
            Some(MsgSsrTileDefinitionDepA::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgSsrTileDefinitionDepA>(value)
                    .map(Sbp::MsgSsrTileDefinitionDepA)
            }
            Some(MsgSsrTileDefinitionDepB::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgSsrTileDefinitionDepB>(value)
                    .map(Sbp::MsgSsrTileDefinitionDepB)
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
            Some(MsgSsrSatelliteApcDep::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgSsrSatelliteApcDep>(value)
                    .map(Sbp::MsgSsrSatelliteApcDep)
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
            Some(MsgAcknowledge::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgAcknowledge>(value).map(Sbp::MsgAcknowledge)
            }
            Some(MsgEd25519SignatureDepA::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgEd25519SignatureDepA>(value)
                    .map(Sbp::MsgEd25519SignatureDepA)
            }
            Some(MsgEd25519CertificateDep::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgEd25519CertificateDep>(value)
                    .map(Sbp::MsgEd25519CertificateDep)
            }
            Some(MsgEd25519SignatureDepB::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgEd25519SignatureDepB>(value)
                    .map(Sbp::MsgEd25519SignatureDepB)
            }
            Some(MsgEcdsaCertificate::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgEcdsaCertificate>(value).map(Sbp::MsgEcdsaCertificate)
            }
            Some(MsgCertificateChainDep::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgCertificateChainDep>(value)
                    .map(Sbp::MsgCertificateChainDep)
            }
            Some(MsgEcdsaSignatureDepA::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgEcdsaSignatureDepA>(value)
                    .map(Sbp::MsgEcdsaSignatureDepA)
            }
            Some(MsgEcdsaSignatureDepB::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgEcdsaSignatureDepB>(value)
                    .map(Sbp::MsgEcdsaSignatureDepB)
            }
            Some(MsgEcdsaSignature::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgEcdsaSignature>(value).map(Sbp::MsgEcdsaSignature)
            }
            Some(MsgCertificateChain::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgCertificateChain>(value).map(Sbp::MsgCertificateChain)
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
            Some(MsgMeasurementPoint::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgMeasurementPoint>(value).map(Sbp::MsgMeasurementPoint)
            }
            Some(MsgProfilingSystemInfo::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgProfilingSystemInfo>(value)
                    .map(Sbp::MsgProfilingSystemInfo)
            }
            Some(MsgProfilingThreadInfo::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgProfilingThreadInfo>(value)
                    .map(Sbp::MsgProfilingThreadInfo)
            }
            Some(MsgProfilingResourceCounter::MESSAGE_TYPE) => {
                serde_json::from_value::<MsgProfilingResourceCounter>(value)
                    .map(Sbp::MsgProfilingResourceCounter)
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
            msg_id @ Some(_) => serde_json::from_value::<Unknown>(value)
                .map(|msg| Unknown { msg_id, ..msg })
                .map(Sbp::Unknown),
            None => serde_json::from_value::<Invalid>(value)
                .map(|msg| Invalid { ..msg })
                .map(Sbp::Invalid),
        }
        .map_err(serde::de::Error::custom)
    }
}

#[derive(Debug, Clone)]
pub struct SbpMsgParseError {
    /// the message type
    pub msg_type: u16,
    /// the sender_id
    pub sender_id: u16,
    /// A vec that just contains the invalid payload bytes
    pub invalid_payload: Vec<u8>,
}

impl From<SbpMsgParseError> for PayloadParseError {
    fn from(
        SbpMsgParseError {
            invalid_payload, ..
        }: SbpMsgParseError,
    ) -> Self {
        Self { invalid_payload }
    }
}

impl std::fmt::Display for SbpMsgParseError {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        write!(f, "error parsing payload")
    }
}

impl std::error::Error for SbpMsgParseError {}

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
    ) -> Result<Sbp, SbpMsgParseError> {
        let sbp_msg = match msg_type {
            MsgPrintDep::MESSAGE_TYPE => MsgPrintDep::parse(&mut payload).map(Sbp::MsgPrintDep),
            MsgTrackingStateDetailedDep::MESSAGE_TYPE => {
                MsgTrackingStateDetailedDep::parse(&mut payload)
                    .map(Sbp::MsgTrackingStateDetailedDep)
            }
            MsgTrackingStateDepB::MESSAGE_TYPE => {
                MsgTrackingStateDepB::parse(&mut payload).map(Sbp::MsgTrackingStateDepB)
            }
            MsgAcqResultDepB::MESSAGE_TYPE => {
                MsgAcqResultDepB::parse(&mut payload).map(Sbp::MsgAcqResultDepB)
            }
            MsgAcqResultDepA::MESSAGE_TYPE => {
                MsgAcqResultDepA::parse(&mut payload).map(Sbp::MsgAcqResultDepA)
            }
            MsgTrackingStateDepA::MESSAGE_TYPE => {
                MsgTrackingStateDepA::parse(&mut payload).map(Sbp::MsgTrackingStateDepA)
            }
            MsgThreadState::MESSAGE_TYPE => {
                MsgThreadState::parse(&mut payload).map(Sbp::MsgThreadState)
            }
            MsgUartStateDepa::MESSAGE_TYPE => {
                MsgUartStateDepa::parse(&mut payload).map(Sbp::MsgUartStateDepa)
            }
            MsgIarState::MESSAGE_TYPE => MsgIarState::parse(&mut payload).map(Sbp::MsgIarState),
            MsgEphemerisDepA::MESSAGE_TYPE => {
                MsgEphemerisDepA::parse(&mut payload).map(Sbp::MsgEphemerisDepA)
            }
            MsgMaskSatelliteDep::MESSAGE_TYPE => {
                MsgMaskSatelliteDep::parse(&mut payload).map(Sbp::MsgMaskSatelliteDep)
            }
            MsgTrackingIqDepA::MESSAGE_TYPE => {
                MsgTrackingIqDepA::parse(&mut payload).map(Sbp::MsgTrackingIqDepA)
            }
            MsgUartState::MESSAGE_TYPE => MsgUartState::parse(&mut payload).map(Sbp::MsgUartState),
            MsgAcqSvProfileDep::MESSAGE_TYPE => {
                MsgAcqSvProfileDep::parse(&mut payload).map(Sbp::MsgAcqSvProfileDep)
            }
            MsgAcqResultDepC::MESSAGE_TYPE => {
                MsgAcqResultDepC::parse(&mut payload).map(Sbp::MsgAcqResultDepC)
            }
            MsgTrackingStateDetailedDepA::MESSAGE_TYPE => {
                MsgTrackingStateDetailedDepA::parse(&mut payload)
                    .map(Sbp::MsgTrackingStateDetailedDepA)
            }
            MsgResetFilters::MESSAGE_TYPE => {
                MsgResetFilters::parse(&mut payload).map(Sbp::MsgResetFilters)
            }
            MsgInitBaseDep::MESSAGE_TYPE => {
                MsgInitBaseDep::parse(&mut payload).map(Sbp::MsgInitBaseDep)
            }
            MsgMaskSatellite::MESSAGE_TYPE => {
                MsgMaskSatellite::parse(&mut payload).map(Sbp::MsgMaskSatellite)
            }
            MsgTrackingIqDepB::MESSAGE_TYPE => {
                MsgTrackingIqDepB::parse(&mut payload).map(Sbp::MsgTrackingIqDepB)
            }
            MsgTrackingIq::MESSAGE_TYPE => {
                MsgTrackingIq::parse(&mut payload).map(Sbp::MsgTrackingIq)
            }
            MsgAcqSvProfile::MESSAGE_TYPE => {
                MsgAcqSvProfile::parse(&mut payload).map(Sbp::MsgAcqSvProfile)
            }
            MsgAcqResult::MESSAGE_TYPE => MsgAcqResult::parse(&mut payload).map(Sbp::MsgAcqResult),
            MsgTrackingState::MESSAGE_TYPE => {
                MsgTrackingState::parse(&mut payload).map(Sbp::MsgTrackingState)
            }
            MsgObsDepB::MESSAGE_TYPE => MsgObsDepB::parse(&mut payload).map(Sbp::MsgObsDepB),
            MsgBasePosLlh::MESSAGE_TYPE => {
                MsgBasePosLlh::parse(&mut payload).map(Sbp::MsgBasePosLlh)
            }
            MsgObsDepA::MESSAGE_TYPE => MsgObsDepA::parse(&mut payload).map(Sbp::MsgObsDepA),
            MsgEphemerisDepB::MESSAGE_TYPE => {
                MsgEphemerisDepB::parse(&mut payload).map(Sbp::MsgEphemerisDepB)
            }
            MsgEphemerisDepC::MESSAGE_TYPE => {
                MsgEphemerisDepC::parse(&mut payload).map(Sbp::MsgEphemerisDepC)
            }
            MsgBasePosEcef::MESSAGE_TYPE => {
                MsgBasePosEcef::parse(&mut payload).map(Sbp::MsgBasePosEcef)
            }
            MsgObsDepC::MESSAGE_TYPE => MsgObsDepC::parse(&mut payload).map(Sbp::MsgObsDepC),
            MsgObs::MESSAGE_TYPE => MsgObs::parse(&mut payload).map(Sbp::MsgObs),
            MsgSpecanDep::MESSAGE_TYPE => MsgSpecanDep::parse(&mut payload).map(Sbp::MsgSpecanDep),
            MsgSpecan::MESSAGE_TYPE => MsgSpecan::parse(&mut payload).map(Sbp::MsgSpecan),
            MsgMeasurementState::MESSAGE_TYPE => {
                MsgMeasurementState::parse(&mut payload).map(Sbp::MsgMeasurementState)
            }
            MsgSetTime::MESSAGE_TYPE => MsgSetTime::parse(&mut payload).map(Sbp::MsgSetTime),
            MsgAlmanac::MESSAGE_TYPE => MsgAlmanac::parse(&mut payload).map(Sbp::MsgAlmanac),
            MsgAlmanacGpsDep::MESSAGE_TYPE => {
                MsgAlmanacGpsDep::parse(&mut payload).map(Sbp::MsgAlmanacGpsDep)
            }
            MsgAlmanacGloDep::MESSAGE_TYPE => {
                MsgAlmanacGloDep::parse(&mut payload).map(Sbp::MsgAlmanacGloDep)
            }
            MsgAlmanacGps::MESSAGE_TYPE => {
                MsgAlmanacGps::parse(&mut payload).map(Sbp::MsgAlmanacGps)
            }
            MsgAlmanacGlo::MESSAGE_TYPE => {
                MsgAlmanacGlo::parse(&mut payload).map(Sbp::MsgAlmanacGlo)
            }
            MsgGloBiases::MESSAGE_TYPE => MsgGloBiases::parse(&mut payload).map(Sbp::MsgGloBiases),
            MsgEphemerisDepD::MESSAGE_TYPE => {
                MsgEphemerisDepD::parse(&mut payload).map(Sbp::MsgEphemerisDepD)
            }
            MsgEphemerisGpsDepE::MESSAGE_TYPE => {
                MsgEphemerisGpsDepE::parse(&mut payload).map(Sbp::MsgEphemerisGpsDepE)
            }
            MsgEphemerisSbasDepA::MESSAGE_TYPE => {
                MsgEphemerisSbasDepA::parse(&mut payload).map(Sbp::MsgEphemerisSbasDepA)
            }
            MsgEphemerisGloDepA::MESSAGE_TYPE => {
                MsgEphemerisGloDepA::parse(&mut payload).map(Sbp::MsgEphemerisGloDepA)
            }
            MsgEphemerisSbasDepB::MESSAGE_TYPE => {
                MsgEphemerisSbasDepB::parse(&mut payload).map(Sbp::MsgEphemerisSbasDepB)
            }
            MsgEphemerisGloDepB::MESSAGE_TYPE => {
                MsgEphemerisGloDepB::parse(&mut payload).map(Sbp::MsgEphemerisGloDepB)
            }
            MsgEphemerisGpsDepF::MESSAGE_TYPE => {
                MsgEphemerisGpsDepF::parse(&mut payload).map(Sbp::MsgEphemerisGpsDepF)
            }
            MsgEphemerisGloDepC::MESSAGE_TYPE => {
                MsgEphemerisGloDepC::parse(&mut payload).map(Sbp::MsgEphemerisGloDepC)
            }
            MsgEphemerisGloDepD::MESSAGE_TYPE => {
                MsgEphemerisGloDepD::parse(&mut payload).map(Sbp::MsgEphemerisGloDepD)
            }
            MsgEphemerisBds::MESSAGE_TYPE => {
                MsgEphemerisBds::parse(&mut payload).map(Sbp::MsgEphemerisBds)
            }
            MsgEphemerisGps::MESSAGE_TYPE => {
                MsgEphemerisGps::parse(&mut payload).map(Sbp::MsgEphemerisGps)
            }
            MsgEphemerisGlo::MESSAGE_TYPE => {
                MsgEphemerisGlo::parse(&mut payload).map(Sbp::MsgEphemerisGlo)
            }
            MsgEphemerisSbas::MESSAGE_TYPE => {
                MsgEphemerisSbas::parse(&mut payload).map(Sbp::MsgEphemerisSbas)
            }
            MsgEphemerisGal::MESSAGE_TYPE => {
                MsgEphemerisGal::parse(&mut payload).map(Sbp::MsgEphemerisGal)
            }
            MsgEphemerisQzss::MESSAGE_TYPE => {
                MsgEphemerisQzss::parse(&mut payload).map(Sbp::MsgEphemerisQzss)
            }
            MsgIono::MESSAGE_TYPE => MsgIono::parse(&mut payload).map(Sbp::MsgIono),
            MsgSvConfigurationGpsDep::MESSAGE_TYPE => {
                MsgSvConfigurationGpsDep::parse(&mut payload).map(Sbp::MsgSvConfigurationGpsDep)
            }
            MsgGroupDelayDepA::MESSAGE_TYPE => {
                MsgGroupDelayDepA::parse(&mut payload).map(Sbp::MsgGroupDelayDepA)
            }
            MsgGroupDelayDepB::MESSAGE_TYPE => {
                MsgGroupDelayDepB::parse(&mut payload).map(Sbp::MsgGroupDelayDepB)
            }
            MsgGroupDelay::MESSAGE_TYPE => {
                MsgGroupDelay::parse(&mut payload).map(Sbp::MsgGroupDelay)
            }
            MsgEphemerisGalDepA::MESSAGE_TYPE => {
                MsgEphemerisGalDepA::parse(&mut payload).map(Sbp::MsgEphemerisGalDepA)
            }
            MsgGnssCapb::MESSAGE_TYPE => MsgGnssCapb::parse(&mut payload).map(Sbp::MsgGnssCapb),
            MsgSvAzEl::MESSAGE_TYPE => MsgSvAzEl::parse(&mut payload).map(Sbp::MsgSvAzEl),
            MsgSettingsWrite::MESSAGE_TYPE => {
                MsgSettingsWrite::parse(&mut payload).map(Sbp::MsgSettingsWrite)
            }
            MsgSettingsSave::MESSAGE_TYPE => {
                MsgSettingsSave::parse(&mut payload).map(Sbp::MsgSettingsSave)
            }
            MsgSettingsReadByIndexReq::MESSAGE_TYPE => {
                MsgSettingsReadByIndexReq::parse(&mut payload).map(Sbp::MsgSettingsReadByIndexReq)
            }
            MsgFileioReadResp::MESSAGE_TYPE => {
                MsgFileioReadResp::parse(&mut payload).map(Sbp::MsgFileioReadResp)
            }
            MsgSettingsReadReq::MESSAGE_TYPE => {
                MsgSettingsReadReq::parse(&mut payload).map(Sbp::MsgSettingsReadReq)
            }
            MsgSettingsReadResp::MESSAGE_TYPE => {
                MsgSettingsReadResp::parse(&mut payload).map(Sbp::MsgSettingsReadResp)
            }
            MsgSettingsReadByIndexDone::MESSAGE_TYPE => {
                MsgSettingsReadByIndexDone::parse(&mut payload).map(Sbp::MsgSettingsReadByIndexDone)
            }
            MsgSettingsReadByIndexResp::MESSAGE_TYPE => {
                MsgSettingsReadByIndexResp::parse(&mut payload).map(Sbp::MsgSettingsReadByIndexResp)
            }
            MsgFileioReadReq::MESSAGE_TYPE => {
                MsgFileioReadReq::parse(&mut payload).map(Sbp::MsgFileioReadReq)
            }
            MsgFileioReadDirReq::MESSAGE_TYPE => {
                MsgFileioReadDirReq::parse(&mut payload).map(Sbp::MsgFileioReadDirReq)
            }
            MsgFileioReadDirResp::MESSAGE_TYPE => {
                MsgFileioReadDirResp::parse(&mut payload).map(Sbp::MsgFileioReadDirResp)
            }
            MsgFileioWriteResp::MESSAGE_TYPE => {
                MsgFileioWriteResp::parse(&mut payload).map(Sbp::MsgFileioWriteResp)
            }
            MsgFileioRemove::MESSAGE_TYPE => {
                MsgFileioRemove::parse(&mut payload).map(Sbp::MsgFileioRemove)
            }
            MsgFileioWriteReq::MESSAGE_TYPE => {
                MsgFileioWriteReq::parse(&mut payload).map(Sbp::MsgFileioWriteReq)
            }
            MsgSettingsRegister::MESSAGE_TYPE => {
                MsgSettingsRegister::parse(&mut payload).map(Sbp::MsgSettingsRegister)
            }
            MsgSettingsWriteResp::MESSAGE_TYPE => {
                MsgSettingsWriteResp::parse(&mut payload).map(Sbp::MsgSettingsWriteResp)
            }
            MsgBootloaderHandshakeDepA::MESSAGE_TYPE => {
                MsgBootloaderHandshakeDepA::parse(&mut payload).map(Sbp::MsgBootloaderHandshakeDepA)
            }
            MsgBootloaderJumpToApp::MESSAGE_TYPE => {
                MsgBootloaderJumpToApp::parse(&mut payload).map(Sbp::MsgBootloaderJumpToApp)
            }
            MsgResetDep::MESSAGE_TYPE => MsgResetDep::parse(&mut payload).map(Sbp::MsgResetDep),
            MsgBootloaderHandshakeReq::MESSAGE_TYPE => {
                MsgBootloaderHandshakeReq::parse(&mut payload).map(Sbp::MsgBootloaderHandshakeReq)
            }
            MsgBootloaderHandshakeResp::MESSAGE_TYPE => {
                MsgBootloaderHandshakeResp::parse(&mut payload).map(Sbp::MsgBootloaderHandshakeResp)
            }
            MsgDeviceMonitor::MESSAGE_TYPE => {
                MsgDeviceMonitor::parse(&mut payload).map(Sbp::MsgDeviceMonitor)
            }
            MsgReset::MESSAGE_TYPE => MsgReset::parse(&mut payload).map(Sbp::MsgReset),
            MsgCommandReq::MESSAGE_TYPE => {
                MsgCommandReq::parse(&mut payload).map(Sbp::MsgCommandReq)
            }
            MsgCommandResp::MESSAGE_TYPE => {
                MsgCommandResp::parse(&mut payload).map(Sbp::MsgCommandResp)
            }
            MsgNetworkStateReq::MESSAGE_TYPE => {
                MsgNetworkStateReq::parse(&mut payload).map(Sbp::MsgNetworkStateReq)
            }
            MsgNetworkStateResp::MESSAGE_TYPE => {
                MsgNetworkStateResp::parse(&mut payload).map(Sbp::MsgNetworkStateResp)
            }
            MsgCommandOutput::MESSAGE_TYPE => {
                MsgCommandOutput::parse(&mut payload).map(Sbp::MsgCommandOutput)
            }
            MsgNetworkBandwidthUsage::MESSAGE_TYPE => {
                MsgNetworkBandwidthUsage::parse(&mut payload).map(Sbp::MsgNetworkBandwidthUsage)
            }
            MsgCellModemStatus::MESSAGE_TYPE => {
                MsgCellModemStatus::parse(&mut payload).map(Sbp::MsgCellModemStatus)
            }
            MsgFrontEndGain::MESSAGE_TYPE => {
                MsgFrontEndGain::parse(&mut payload).map(Sbp::MsgFrontEndGain)
            }
            MsgCwResults::MESSAGE_TYPE => MsgCwResults::parse(&mut payload).map(Sbp::MsgCwResults),
            MsgCwStart::MESSAGE_TYPE => MsgCwStart::parse(&mut payload).map(Sbp::MsgCwStart),
            MsgNapDeviceDnaResp::MESSAGE_TYPE => {
                MsgNapDeviceDnaResp::parse(&mut payload).map(Sbp::MsgNapDeviceDnaResp)
            }
            MsgNapDeviceDnaReq::MESSAGE_TYPE => {
                MsgNapDeviceDnaReq::parse(&mut payload).map(Sbp::MsgNapDeviceDnaReq)
            }
            MsgFlashDone::MESSAGE_TYPE => MsgFlashDone::parse(&mut payload).map(Sbp::MsgFlashDone),
            MsgFlashReadResp::MESSAGE_TYPE => {
                MsgFlashReadResp::parse(&mut payload).map(Sbp::MsgFlashReadResp)
            }
            MsgFlashErase::MESSAGE_TYPE => {
                MsgFlashErase::parse(&mut payload).map(Sbp::MsgFlashErase)
            }
            MsgStmFlashLockSector::MESSAGE_TYPE => {
                MsgStmFlashLockSector::parse(&mut payload).map(Sbp::MsgStmFlashLockSector)
            }
            MsgStmFlashUnlockSector::MESSAGE_TYPE => {
                MsgStmFlashUnlockSector::parse(&mut payload).map(Sbp::MsgStmFlashUnlockSector)
            }
            MsgStmUniqueIdResp::MESSAGE_TYPE => {
                MsgStmUniqueIdResp::parse(&mut payload).map(Sbp::MsgStmUniqueIdResp)
            }
            MsgFlashProgram::MESSAGE_TYPE => {
                MsgFlashProgram::parse(&mut payload).map(Sbp::MsgFlashProgram)
            }
            MsgFlashReadReq::MESSAGE_TYPE => {
                MsgFlashReadReq::parse(&mut payload).map(Sbp::MsgFlashReadReq)
            }
            MsgStmUniqueIdReq::MESSAGE_TYPE => {
                MsgStmUniqueIdReq::parse(&mut payload).map(Sbp::MsgStmUniqueIdReq)
            }
            MsgM25FlashWriteStatus::MESSAGE_TYPE => {
                MsgM25FlashWriteStatus::parse(&mut payload).map(Sbp::MsgM25FlashWriteStatus)
            }
            MsgGpsTimeDepA::MESSAGE_TYPE => {
                MsgGpsTimeDepA::parse(&mut payload).map(Sbp::MsgGpsTimeDepA)
            }
            MsgExtEvent::MESSAGE_TYPE => MsgExtEvent::parse(&mut payload).map(Sbp::MsgExtEvent),
            MsgGpsTime::MESSAGE_TYPE => MsgGpsTime::parse(&mut payload).map(Sbp::MsgGpsTime),
            MsgUtcTime::MESSAGE_TYPE => MsgUtcTime::parse(&mut payload).map(Sbp::MsgUtcTime),
            MsgGpsTimeGnss::MESSAGE_TYPE => {
                MsgGpsTimeGnss::parse(&mut payload).map(Sbp::MsgGpsTimeGnss)
            }
            MsgUtcTimeGnss::MESSAGE_TYPE => {
                MsgUtcTimeGnss::parse(&mut payload).map(Sbp::MsgUtcTimeGnss)
            }
            MsgTelSv::MESSAGE_TYPE => MsgTelSv::parse(&mut payload).map(Sbp::MsgTelSv),
            MsgSettingsRegisterResp::MESSAGE_TYPE => {
                MsgSettingsRegisterResp::parse(&mut payload).map(Sbp::MsgSettingsRegisterResp)
            }
            MsgPosEcefDepA::MESSAGE_TYPE => {
                MsgPosEcefDepA::parse(&mut payload).map(Sbp::MsgPosEcefDepA)
            }
            MsgPosLlhDepA::MESSAGE_TYPE => {
                MsgPosLlhDepA::parse(&mut payload).map(Sbp::MsgPosLlhDepA)
            }
            MsgBaselineEcefDepA::MESSAGE_TYPE => {
                MsgBaselineEcefDepA::parse(&mut payload).map(Sbp::MsgBaselineEcefDepA)
            }
            MsgBaselineNedDepA::MESSAGE_TYPE => {
                MsgBaselineNedDepA::parse(&mut payload).map(Sbp::MsgBaselineNedDepA)
            }
            MsgVelEcefDepA::MESSAGE_TYPE => {
                MsgVelEcefDepA::parse(&mut payload).map(Sbp::MsgVelEcefDepA)
            }
            MsgVelNedDepA::MESSAGE_TYPE => {
                MsgVelNedDepA::parse(&mut payload).map(Sbp::MsgVelNedDepA)
            }
            MsgDopsDepA::MESSAGE_TYPE => MsgDopsDepA::parse(&mut payload).map(Sbp::MsgDopsDepA),
            MsgBaselineHeadingDepA::MESSAGE_TYPE => {
                MsgBaselineHeadingDepA::parse(&mut payload).map(Sbp::MsgBaselineHeadingDepA)
            }
            MsgDops::MESSAGE_TYPE => MsgDops::parse(&mut payload).map(Sbp::MsgDops),
            MsgPosEcef::MESSAGE_TYPE => MsgPosEcef::parse(&mut payload).map(Sbp::MsgPosEcef),
            MsgPosLlh::MESSAGE_TYPE => MsgPosLlh::parse(&mut payload).map(Sbp::MsgPosLlh),
            MsgBaselineEcef::MESSAGE_TYPE => {
                MsgBaselineEcef::parse(&mut payload).map(Sbp::MsgBaselineEcef)
            }
            MsgBaselineNed::MESSAGE_TYPE => {
                MsgBaselineNed::parse(&mut payload).map(Sbp::MsgBaselineNed)
            }
            MsgVelEcef::MESSAGE_TYPE => MsgVelEcef::parse(&mut payload).map(Sbp::MsgVelEcef),
            MsgVelNed::MESSAGE_TYPE => MsgVelNed::parse(&mut payload).map(Sbp::MsgVelNed),
            MsgBaselineHeading::MESSAGE_TYPE => {
                MsgBaselineHeading::parse(&mut payload).map(Sbp::MsgBaselineHeading)
            }
            MsgAgeCorrections::MESSAGE_TYPE => {
                MsgAgeCorrections::parse(&mut payload).map(Sbp::MsgAgeCorrections)
            }
            MsgPosLlhCov::MESSAGE_TYPE => MsgPosLlhCov::parse(&mut payload).map(Sbp::MsgPosLlhCov),
            MsgVelNedCov::MESSAGE_TYPE => MsgVelNedCov::parse(&mut payload).map(Sbp::MsgVelNedCov),
            MsgVelBody::MESSAGE_TYPE => MsgVelBody::parse(&mut payload).map(Sbp::MsgVelBody),
            MsgPosEcefCov::MESSAGE_TYPE => {
                MsgPosEcefCov::parse(&mut payload).map(Sbp::MsgPosEcefCov)
            }
            MsgVelEcefCov::MESSAGE_TYPE => {
                MsgVelEcefCov::parse(&mut payload).map(Sbp::MsgVelEcefCov)
            }
            MsgProtectionLevelDepA::MESSAGE_TYPE => {
                MsgProtectionLevelDepA::parse(&mut payload).map(Sbp::MsgProtectionLevelDepA)
            }
            MsgProtectionLevel::MESSAGE_TYPE => {
                MsgProtectionLevel::parse(&mut payload).map(Sbp::MsgProtectionLevel)
            }
            MsgPosLlhAcc::MESSAGE_TYPE => MsgPosLlhAcc::parse(&mut payload).map(Sbp::MsgPosLlhAcc),
            MsgVelCog::MESSAGE_TYPE => MsgVelCog::parse(&mut payload).map(Sbp::MsgVelCog),
            MsgOrientQuat::MESSAGE_TYPE => {
                MsgOrientQuat::parse(&mut payload).map(Sbp::MsgOrientQuat)
            }
            MsgOrientEuler::MESSAGE_TYPE => {
                MsgOrientEuler::parse(&mut payload).map(Sbp::MsgOrientEuler)
            }
            MsgAngularRate::MESSAGE_TYPE => {
                MsgAngularRate::parse(&mut payload).map(Sbp::MsgAngularRate)
            }
            MsgPosEcefGnss::MESSAGE_TYPE => {
                MsgPosEcefGnss::parse(&mut payload).map(Sbp::MsgPosEcefGnss)
            }
            MsgPosLlhGnss::MESSAGE_TYPE => {
                MsgPosLlhGnss::parse(&mut payload).map(Sbp::MsgPosLlhGnss)
            }
            MsgVelEcefGnss::MESSAGE_TYPE => {
                MsgVelEcefGnss::parse(&mut payload).map(Sbp::MsgVelEcefGnss)
            }
            MsgVelNedGnss::MESSAGE_TYPE => {
                MsgVelNedGnss::parse(&mut payload).map(Sbp::MsgVelNedGnss)
            }
            MsgPosLlhCovGnss::MESSAGE_TYPE => {
                MsgPosLlhCovGnss::parse(&mut payload).map(Sbp::MsgPosLlhCovGnss)
            }
            MsgVelNedCovGnss::MESSAGE_TYPE => {
                MsgVelNedCovGnss::parse(&mut payload).map(Sbp::MsgVelNedCovGnss)
            }
            MsgPosEcefCovGnss::MESSAGE_TYPE => {
                MsgPosEcefCovGnss::parse(&mut payload).map(Sbp::MsgPosEcefCovGnss)
            }
            MsgVelEcefCovGnss::MESSAGE_TYPE => {
                MsgVelEcefCovGnss::parse(&mut payload).map(Sbp::MsgVelEcefCovGnss)
            }
            MsgUtcLeapSecond::MESSAGE_TYPE => {
                MsgUtcLeapSecond::parse(&mut payload).map(Sbp::MsgUtcLeapSecond)
            }
            MsgReferenceFrameParam::MESSAGE_TYPE => {
                MsgReferenceFrameParam::parse(&mut payload).map(Sbp::MsgReferenceFrameParam)
            }
            MsgPoseRelative::MESSAGE_TYPE => {
                MsgPoseRelative::parse(&mut payload).map(Sbp::MsgPoseRelative)
            }
            MsgNdbEvent::MESSAGE_TYPE => MsgNdbEvent::parse(&mut payload).map(Sbp::MsgNdbEvent),
            MsgLog::MESSAGE_TYPE => MsgLog::parse(&mut payload).map(Sbp::MsgLog),
            MsgFwd::MESSAGE_TYPE => MsgFwd::parse(&mut payload).map(Sbp::MsgFwd),
            MsgSsrOrbitClockDepA::MESSAGE_TYPE => {
                MsgSsrOrbitClockDepA::parse(&mut payload).map(Sbp::MsgSsrOrbitClockDepA)
            }
            MsgSsrOrbitClock::MESSAGE_TYPE => {
                MsgSsrOrbitClock::parse(&mut payload).map(Sbp::MsgSsrOrbitClock)
            }
            MsgSsrOrbitClockBounds::MESSAGE_TYPE => {
                MsgSsrOrbitClockBounds::parse(&mut payload).map(Sbp::MsgSsrOrbitClockBounds)
            }
            MsgSsrOrbitClockBoundsDegradation::MESSAGE_TYPE => {
                MsgSsrOrbitClockBoundsDegradation::parse(&mut payload)
                    .map(Sbp::MsgSsrOrbitClockBoundsDegradation)
            }
            MsgSsrCodeBiases::MESSAGE_TYPE => {
                MsgSsrCodeBiases::parse(&mut payload).map(Sbp::MsgSsrCodeBiases)
            }
            MsgSsrPhaseBiases::MESSAGE_TYPE => {
                MsgSsrPhaseBiases::parse(&mut payload).map(Sbp::MsgSsrPhaseBiases)
            }
            MsgSsrStecCorrectionDepA::MESSAGE_TYPE => {
                MsgSsrStecCorrectionDepA::parse(&mut payload).map(Sbp::MsgSsrStecCorrectionDepA)
            }
            MsgSsrCodePhaseBiasesBounds::MESSAGE_TYPE => {
                MsgSsrCodePhaseBiasesBounds::parse(&mut payload)
                    .map(Sbp::MsgSsrCodePhaseBiasesBounds)
            }
            MsgSsrGriddedCorrectionNoStdDepA::MESSAGE_TYPE => {
                MsgSsrGriddedCorrectionNoStdDepA::parse(&mut payload)
                    .map(Sbp::MsgSsrGriddedCorrectionNoStdDepA)
            }
            MsgSsrGridDefinitionDepA::MESSAGE_TYPE => {
                MsgSsrGridDefinitionDepA::parse(&mut payload).map(Sbp::MsgSsrGridDefinitionDepA)
            }
            MsgSsrTileDefinitionDepA::MESSAGE_TYPE => {
                MsgSsrTileDefinitionDepA::parse(&mut payload).map(Sbp::MsgSsrTileDefinitionDepA)
            }
            MsgSsrTileDefinitionDepB::MESSAGE_TYPE => {
                MsgSsrTileDefinitionDepB::parse(&mut payload).map(Sbp::MsgSsrTileDefinitionDepB)
            }
            MsgSsrTileDefinition::MESSAGE_TYPE => {
                MsgSsrTileDefinition::parse(&mut payload).map(Sbp::MsgSsrTileDefinition)
            }
            MsgSsrGriddedCorrectionDepA::MESSAGE_TYPE => {
                MsgSsrGriddedCorrectionDepA::parse(&mut payload)
                    .map(Sbp::MsgSsrGriddedCorrectionDepA)
            }
            MsgSsrStecCorrectionDep::MESSAGE_TYPE => {
                MsgSsrStecCorrectionDep::parse(&mut payload).map(Sbp::MsgSsrStecCorrectionDep)
            }
            MsgSsrGriddedCorrection::MESSAGE_TYPE => {
                MsgSsrGriddedCorrection::parse(&mut payload).map(Sbp::MsgSsrGriddedCorrection)
            }
            MsgSsrStecCorrection::MESSAGE_TYPE => {
                MsgSsrStecCorrection::parse(&mut payload).map(Sbp::MsgSsrStecCorrection)
            }
            MsgSsrGriddedCorrectionBounds::MESSAGE_TYPE => {
                MsgSsrGriddedCorrectionBounds::parse(&mut payload)
                    .map(Sbp::MsgSsrGriddedCorrectionBounds)
            }
            MsgSsrSatelliteApcDep::MESSAGE_TYPE => {
                MsgSsrSatelliteApcDep::parse(&mut payload).map(Sbp::MsgSsrSatelliteApcDep)
            }
            MsgSsrSatelliteApc::MESSAGE_TYPE => {
                MsgSsrSatelliteApc::parse(&mut payload).map(Sbp::MsgSsrSatelliteApc)
            }
            MsgOsr::MESSAGE_TYPE => MsgOsr::parse(&mut payload).map(Sbp::MsgOsr),
            MsgUserData::MESSAGE_TYPE => MsgUserData::parse(&mut payload).map(Sbp::MsgUserData),
            MsgImuRaw::MESSAGE_TYPE => MsgImuRaw::parse(&mut payload).map(Sbp::MsgImuRaw),
            MsgImuAux::MESSAGE_TYPE => MsgImuAux::parse(&mut payload).map(Sbp::MsgImuAux),
            MsgMagRaw::MESSAGE_TYPE => MsgMagRaw::parse(&mut payload).map(Sbp::MsgMagRaw),
            MsgOdometry::MESSAGE_TYPE => MsgOdometry::parse(&mut payload).map(Sbp::MsgOdometry),
            MsgWheeltick::MESSAGE_TYPE => MsgWheeltick::parse(&mut payload).map(Sbp::MsgWheeltick),
            MsgSsrFlagHighLevel::MESSAGE_TYPE => {
                MsgSsrFlagHighLevel::parse(&mut payload).map(Sbp::MsgSsrFlagHighLevel)
            }
            MsgSsrFlagSatellites::MESSAGE_TYPE => {
                MsgSsrFlagSatellites::parse(&mut payload).map(Sbp::MsgSsrFlagSatellites)
            }
            MsgSsrFlagTropoGridPoints::MESSAGE_TYPE => {
                MsgSsrFlagTropoGridPoints::parse(&mut payload).map(Sbp::MsgSsrFlagTropoGridPoints)
            }
            MsgSsrFlagIonoGridPoints::MESSAGE_TYPE => {
                MsgSsrFlagIonoGridPoints::parse(&mut payload).map(Sbp::MsgSsrFlagIonoGridPoints)
            }
            MsgSsrFlagIonoTileSatLos::MESSAGE_TYPE => {
                MsgSsrFlagIonoTileSatLos::parse(&mut payload).map(Sbp::MsgSsrFlagIonoTileSatLos)
            }
            MsgSsrFlagIonoGridPointSatLos::MESSAGE_TYPE => {
                MsgSsrFlagIonoGridPointSatLos::parse(&mut payload)
                    .map(Sbp::MsgSsrFlagIonoGridPointSatLos)
            }
            MsgAcknowledge::MESSAGE_TYPE => {
                MsgAcknowledge::parse(&mut payload).map(Sbp::MsgAcknowledge)
            }
            MsgEd25519SignatureDepA::MESSAGE_TYPE => {
                MsgEd25519SignatureDepA::parse(&mut payload).map(Sbp::MsgEd25519SignatureDepA)
            }
            MsgEd25519CertificateDep::MESSAGE_TYPE => {
                MsgEd25519CertificateDep::parse(&mut payload).map(Sbp::MsgEd25519CertificateDep)
            }
            MsgEd25519SignatureDepB::MESSAGE_TYPE => {
                MsgEd25519SignatureDepB::parse(&mut payload).map(Sbp::MsgEd25519SignatureDepB)
            }
            MsgEcdsaCertificate::MESSAGE_TYPE => {
                MsgEcdsaCertificate::parse(&mut payload).map(Sbp::MsgEcdsaCertificate)
            }
            MsgCertificateChainDep::MESSAGE_TYPE => {
                MsgCertificateChainDep::parse(&mut payload).map(Sbp::MsgCertificateChainDep)
            }
            MsgEcdsaSignatureDepA::MESSAGE_TYPE => {
                MsgEcdsaSignatureDepA::parse(&mut payload).map(Sbp::MsgEcdsaSignatureDepA)
            }
            MsgEcdsaSignatureDepB::MESSAGE_TYPE => {
                MsgEcdsaSignatureDepB::parse(&mut payload).map(Sbp::MsgEcdsaSignatureDepB)
            }
            MsgEcdsaSignature::MESSAGE_TYPE => {
                MsgEcdsaSignature::parse(&mut payload).map(Sbp::MsgEcdsaSignature)
            }
            MsgCertificateChain::MESSAGE_TYPE => {
                MsgCertificateChain::parse(&mut payload).map(Sbp::MsgCertificateChain)
            }
            MsgFileioConfigReq::MESSAGE_TYPE => {
                MsgFileioConfigReq::parse(&mut payload).map(Sbp::MsgFileioConfigReq)
            }
            MsgFileioConfigResp::MESSAGE_TYPE => {
                MsgFileioConfigResp::parse(&mut payload).map(Sbp::MsgFileioConfigResp)
            }
            MsgSbasRaw::MESSAGE_TYPE => MsgSbasRaw::parse(&mut payload).map(Sbp::MsgSbasRaw),
            MsgLinuxCpuStateDepA::MESSAGE_TYPE => {
                MsgLinuxCpuStateDepA::parse(&mut payload).map(Sbp::MsgLinuxCpuStateDepA)
            }
            MsgLinuxMemStateDepA::MESSAGE_TYPE => {
                MsgLinuxMemStateDepA::parse(&mut payload).map(Sbp::MsgLinuxMemStateDepA)
            }
            MsgLinuxSysStateDepA::MESSAGE_TYPE => {
                MsgLinuxSysStateDepA::parse(&mut payload).map(Sbp::MsgLinuxSysStateDepA)
            }
            MsgLinuxProcessSocketCounts::MESSAGE_TYPE => {
                MsgLinuxProcessSocketCounts::parse(&mut payload)
                    .map(Sbp::MsgLinuxProcessSocketCounts)
            }
            MsgLinuxProcessSocketQueues::MESSAGE_TYPE => {
                MsgLinuxProcessSocketQueues::parse(&mut payload)
                    .map(Sbp::MsgLinuxProcessSocketQueues)
            }
            MsgLinuxSocketUsage::MESSAGE_TYPE => {
                MsgLinuxSocketUsage::parse(&mut payload).map(Sbp::MsgLinuxSocketUsage)
            }
            MsgLinuxProcessFdCount::MESSAGE_TYPE => {
                MsgLinuxProcessFdCount::parse(&mut payload).map(Sbp::MsgLinuxProcessFdCount)
            }
            MsgLinuxProcessFdSummary::MESSAGE_TYPE => {
                MsgLinuxProcessFdSummary::parse(&mut payload).map(Sbp::MsgLinuxProcessFdSummary)
            }
            MsgLinuxCpuState::MESSAGE_TYPE => {
                MsgLinuxCpuState::parse(&mut payload).map(Sbp::MsgLinuxCpuState)
            }
            MsgLinuxMemState::MESSAGE_TYPE => {
                MsgLinuxMemState::parse(&mut payload).map(Sbp::MsgLinuxMemState)
            }
            MsgLinuxSysState::MESSAGE_TYPE => {
                MsgLinuxSysState::parse(&mut payload).map(Sbp::MsgLinuxSysState)
            }
            MsgMeasurementPoint::MESSAGE_TYPE => {
                MsgMeasurementPoint::parse(&mut payload).map(Sbp::MsgMeasurementPoint)
            }
            MsgProfilingSystemInfo::MESSAGE_TYPE => {
                MsgProfilingSystemInfo::parse(&mut payload).map(Sbp::MsgProfilingSystemInfo)
            }
            MsgProfilingThreadInfo::MESSAGE_TYPE => {
                MsgProfilingThreadInfo::parse(&mut payload).map(Sbp::MsgProfilingThreadInfo)
            }
            MsgProfilingResourceCounter::MESSAGE_TYPE => {
                MsgProfilingResourceCounter::parse(&mut payload)
                    .map(Sbp::MsgProfilingResourceCounter)
            }
            MsgStartup::MESSAGE_TYPE => MsgStartup::parse(&mut payload).map(Sbp::MsgStartup),
            MsgDgnssStatus::MESSAGE_TYPE => {
                MsgDgnssStatus::parse(&mut payload).map(Sbp::MsgDgnssStatus)
            }
            MsgInsStatus::MESSAGE_TYPE => MsgInsStatus::parse(&mut payload).map(Sbp::MsgInsStatus),
            MsgCsacTelemetry::MESSAGE_TYPE => {
                MsgCsacTelemetry::parse(&mut payload).map(Sbp::MsgCsacTelemetry)
            }
            MsgCsacTelemetryLabels::MESSAGE_TYPE => {
                MsgCsacTelemetryLabels::parse(&mut payload).map(Sbp::MsgCsacTelemetryLabels)
            }
            MsgInsUpdates::MESSAGE_TYPE => {
                MsgInsUpdates::parse(&mut payload).map(Sbp::MsgInsUpdates)
            }
            MsgGnssTimeOffset::MESSAGE_TYPE => {
                MsgGnssTimeOffset::parse(&mut payload).map(Sbp::MsgGnssTimeOffset)
            }
            MsgPpsTime::MESSAGE_TYPE => MsgPpsTime::parse(&mut payload).map(Sbp::MsgPpsTime),
            MsgSensorAidEvent::MESSAGE_TYPE => {
                MsgSensorAidEvent::parse(&mut payload).map(Sbp::MsgSensorAidEvent)
            }
            MsgGroupMeta::MESSAGE_TYPE => MsgGroupMeta::parse(&mut payload).map(Sbp::MsgGroupMeta),
            MsgSolnMeta::MESSAGE_TYPE => MsgSolnMeta::parse(&mut payload).map(Sbp::MsgSolnMeta),
            MsgSolnMetaDepA::MESSAGE_TYPE => {
                MsgSolnMetaDepA::parse(&mut payload).map(Sbp::MsgSolnMetaDepA)
            }
            MsgStatusJournal::MESSAGE_TYPE => {
                MsgStatusJournal::parse(&mut payload).map(Sbp::MsgStatusJournal)
            }
            MsgStatusReport::MESSAGE_TYPE => {
                MsgStatusReport::parse(&mut payload).map(Sbp::MsgStatusReport)
            }
            MsgHeartbeat::MESSAGE_TYPE => MsgHeartbeat::parse(&mut payload).map(Sbp::MsgHeartbeat),
            msg_type => {
                Unknown::parse(&mut payload)
                    // keep the msg ID we originally saw
                    .map(|msg| Unknown {
                        msg_id: Some(msg_type),
                        ..msg
                    })
                    .map(Sbp::Unknown)
            }
        };
        // Inject sender_id, handle error
        match sbp_msg {
            Ok(mut msg) => {
                msg.set_sender_id(sender_id);
                Ok(msg)
            }
            Err(PayloadParseError { invalid_payload }) => Err(SbpMsgParseError {
                msg_type,
                sender_id,
                invalid_payload,
            }),
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
            Sbp::MsgTelSv(msg) => msg.message_name(),
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
            Sbp::MsgPoseRelative(msg) => msg.message_name(),
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
            Sbp::MsgSsrTileDefinitionDepA(msg) => msg.message_name(),
            Sbp::MsgSsrTileDefinitionDepB(msg) => msg.message_name(),
            Sbp::MsgSsrTileDefinition(msg) => msg.message_name(),
            Sbp::MsgSsrGriddedCorrectionDepA(msg) => msg.message_name(),
            Sbp::MsgSsrStecCorrectionDep(msg) => msg.message_name(),
            Sbp::MsgSsrGriddedCorrection(msg) => msg.message_name(),
            Sbp::MsgSsrStecCorrection(msg) => msg.message_name(),
            Sbp::MsgSsrGriddedCorrectionBounds(msg) => msg.message_name(),
            Sbp::MsgSsrSatelliteApcDep(msg) => msg.message_name(),
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
            Sbp::MsgAcknowledge(msg) => msg.message_name(),
            Sbp::MsgEd25519SignatureDepA(msg) => msg.message_name(),
            Sbp::MsgEd25519CertificateDep(msg) => msg.message_name(),
            Sbp::MsgEd25519SignatureDepB(msg) => msg.message_name(),
            Sbp::MsgEcdsaCertificate(msg) => msg.message_name(),
            Sbp::MsgCertificateChainDep(msg) => msg.message_name(),
            Sbp::MsgEcdsaSignatureDepA(msg) => msg.message_name(),
            Sbp::MsgEcdsaSignatureDepB(msg) => msg.message_name(),
            Sbp::MsgEcdsaSignature(msg) => msg.message_name(),
            Sbp::MsgCertificateChain(msg) => msg.message_name(),
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
            Sbp::MsgMeasurementPoint(msg) => msg.message_name(),
            Sbp::MsgProfilingSystemInfo(msg) => msg.message_name(),
            Sbp::MsgProfilingThreadInfo(msg) => msg.message_name(),
            Sbp::MsgProfilingResourceCounter(msg) => msg.message_name(),
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
            Sbp::Invalid(msg) => msg.message_name(),
        }
    }

    fn message_type(&self) -> Option<u16> {
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
            Sbp::MsgTelSv(msg) => msg.message_type(),
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
            Sbp::MsgPoseRelative(msg) => msg.message_type(),
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
            Sbp::MsgSsrTileDefinitionDepA(msg) => msg.message_type(),
            Sbp::MsgSsrTileDefinitionDepB(msg) => msg.message_type(),
            Sbp::MsgSsrTileDefinition(msg) => msg.message_type(),
            Sbp::MsgSsrGriddedCorrectionDepA(msg) => msg.message_type(),
            Sbp::MsgSsrStecCorrectionDep(msg) => msg.message_type(),
            Sbp::MsgSsrGriddedCorrection(msg) => msg.message_type(),
            Sbp::MsgSsrStecCorrection(msg) => msg.message_type(),
            Sbp::MsgSsrGriddedCorrectionBounds(msg) => msg.message_type(),
            Sbp::MsgSsrSatelliteApcDep(msg) => msg.message_type(),
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
            Sbp::MsgAcknowledge(msg) => msg.message_type(),
            Sbp::MsgEd25519SignatureDepA(msg) => msg.message_type(),
            Sbp::MsgEd25519CertificateDep(msg) => msg.message_type(),
            Sbp::MsgEd25519SignatureDepB(msg) => msg.message_type(),
            Sbp::MsgEcdsaCertificate(msg) => msg.message_type(),
            Sbp::MsgCertificateChainDep(msg) => msg.message_type(),
            Sbp::MsgEcdsaSignatureDepA(msg) => msg.message_type(),
            Sbp::MsgEcdsaSignatureDepB(msg) => msg.message_type(),
            Sbp::MsgEcdsaSignature(msg) => msg.message_type(),
            Sbp::MsgCertificateChain(msg) => msg.message_type(),
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
            Sbp::MsgMeasurementPoint(msg) => msg.message_type(),
            Sbp::MsgProfilingSystemInfo(msg) => msg.message_type(),
            Sbp::MsgProfilingThreadInfo(msg) => msg.message_type(),
            Sbp::MsgProfilingResourceCounter(msg) => msg.message_type(),
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
            Sbp::Invalid(msg) => msg.message_type(),
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
            Sbp::MsgTelSv(msg) => msg.sender_id(),
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
            Sbp::MsgPoseRelative(msg) => msg.sender_id(),
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
            Sbp::MsgSsrTileDefinitionDepA(msg) => msg.sender_id(),
            Sbp::MsgSsrTileDefinitionDepB(msg) => msg.sender_id(),
            Sbp::MsgSsrTileDefinition(msg) => msg.sender_id(),
            Sbp::MsgSsrGriddedCorrectionDepA(msg) => msg.sender_id(),
            Sbp::MsgSsrStecCorrectionDep(msg) => msg.sender_id(),
            Sbp::MsgSsrGriddedCorrection(msg) => msg.sender_id(),
            Sbp::MsgSsrStecCorrection(msg) => msg.sender_id(),
            Sbp::MsgSsrGriddedCorrectionBounds(msg) => msg.sender_id(),
            Sbp::MsgSsrSatelliteApcDep(msg) => msg.sender_id(),
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
            Sbp::MsgAcknowledge(msg) => msg.sender_id(),
            Sbp::MsgEd25519SignatureDepA(msg) => msg.sender_id(),
            Sbp::MsgEd25519CertificateDep(msg) => msg.sender_id(),
            Sbp::MsgEd25519SignatureDepB(msg) => msg.sender_id(),
            Sbp::MsgEcdsaCertificate(msg) => msg.sender_id(),
            Sbp::MsgCertificateChainDep(msg) => msg.sender_id(),
            Sbp::MsgEcdsaSignatureDepA(msg) => msg.sender_id(),
            Sbp::MsgEcdsaSignatureDepB(msg) => msg.sender_id(),
            Sbp::MsgEcdsaSignature(msg) => msg.sender_id(),
            Sbp::MsgCertificateChain(msg) => msg.sender_id(),
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
            Sbp::MsgMeasurementPoint(msg) => msg.sender_id(),
            Sbp::MsgProfilingSystemInfo(msg) => msg.sender_id(),
            Sbp::MsgProfilingThreadInfo(msg) => msg.sender_id(),
            Sbp::MsgProfilingResourceCounter(msg) => msg.sender_id(),
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
            Sbp::Invalid(msg) => msg.sender_id(),
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
            Sbp::MsgTelSv(msg) => msg.set_sender_id(new_id),
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
            Sbp::MsgPoseRelative(msg) => msg.set_sender_id(new_id),
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
            Sbp::MsgSsrTileDefinitionDepA(msg) => msg.set_sender_id(new_id),
            Sbp::MsgSsrTileDefinitionDepB(msg) => msg.set_sender_id(new_id),
            Sbp::MsgSsrTileDefinition(msg) => msg.set_sender_id(new_id),
            Sbp::MsgSsrGriddedCorrectionDepA(msg) => msg.set_sender_id(new_id),
            Sbp::MsgSsrStecCorrectionDep(msg) => msg.set_sender_id(new_id),
            Sbp::MsgSsrGriddedCorrection(msg) => msg.set_sender_id(new_id),
            Sbp::MsgSsrStecCorrection(msg) => msg.set_sender_id(new_id),
            Sbp::MsgSsrGriddedCorrectionBounds(msg) => msg.set_sender_id(new_id),
            Sbp::MsgSsrSatelliteApcDep(msg) => msg.set_sender_id(new_id),
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
            Sbp::MsgAcknowledge(msg) => msg.set_sender_id(new_id),
            Sbp::MsgEd25519SignatureDepA(msg) => msg.set_sender_id(new_id),
            Sbp::MsgEd25519CertificateDep(msg) => msg.set_sender_id(new_id),
            Sbp::MsgEd25519SignatureDepB(msg) => msg.set_sender_id(new_id),
            Sbp::MsgEcdsaCertificate(msg) => msg.set_sender_id(new_id),
            Sbp::MsgCertificateChainDep(msg) => msg.set_sender_id(new_id),
            Sbp::MsgEcdsaSignatureDepA(msg) => msg.set_sender_id(new_id),
            Sbp::MsgEcdsaSignatureDepB(msg) => msg.set_sender_id(new_id),
            Sbp::MsgEcdsaSignature(msg) => msg.set_sender_id(new_id),
            Sbp::MsgCertificateChain(msg) => msg.set_sender_id(new_id),
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
            Sbp::MsgMeasurementPoint(msg) => msg.set_sender_id(new_id),
            Sbp::MsgProfilingSystemInfo(msg) => msg.set_sender_id(new_id),
            Sbp::MsgProfilingThreadInfo(msg) => msg.set_sender_id(new_id),
            Sbp::MsgProfilingResourceCounter(msg) => msg.set_sender_id(new_id),
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
            Sbp::Invalid(msg) => msg.set_sender_id(new_id),
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
            Sbp::MsgTelSv(msg) => msg.encoded_len(),
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
            Sbp::MsgPoseRelative(msg) => msg.encoded_len(),
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
            Sbp::MsgSsrTileDefinitionDepA(msg) => msg.encoded_len(),
            Sbp::MsgSsrTileDefinitionDepB(msg) => msg.encoded_len(),
            Sbp::MsgSsrTileDefinition(msg) => msg.encoded_len(),
            Sbp::MsgSsrGriddedCorrectionDepA(msg) => msg.encoded_len(),
            Sbp::MsgSsrStecCorrectionDep(msg) => msg.encoded_len(),
            Sbp::MsgSsrGriddedCorrection(msg) => msg.encoded_len(),
            Sbp::MsgSsrStecCorrection(msg) => msg.encoded_len(),
            Sbp::MsgSsrGriddedCorrectionBounds(msg) => msg.encoded_len(),
            Sbp::MsgSsrSatelliteApcDep(msg) => msg.encoded_len(),
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
            Sbp::MsgAcknowledge(msg) => msg.encoded_len(),
            Sbp::MsgEd25519SignatureDepA(msg) => msg.encoded_len(),
            Sbp::MsgEd25519CertificateDep(msg) => msg.encoded_len(),
            Sbp::MsgEd25519SignatureDepB(msg) => msg.encoded_len(),
            Sbp::MsgEcdsaCertificate(msg) => msg.encoded_len(),
            Sbp::MsgCertificateChainDep(msg) => msg.encoded_len(),
            Sbp::MsgEcdsaSignatureDepA(msg) => msg.encoded_len(),
            Sbp::MsgEcdsaSignatureDepB(msg) => msg.encoded_len(),
            Sbp::MsgEcdsaSignature(msg) => msg.encoded_len(),
            Sbp::MsgCertificateChain(msg) => msg.encoded_len(),
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
            Sbp::MsgMeasurementPoint(msg) => msg.encoded_len(),
            Sbp::MsgProfilingSystemInfo(msg) => msg.encoded_len(),
            Sbp::MsgProfilingThreadInfo(msg) => msg.encoded_len(),
            Sbp::MsgProfilingResourceCounter(msg) => msg.encoded_len(),
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
            Sbp::Invalid(msg) => msg.encoded_len(),
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
            Sbp::MsgTelSv(msg) => msg.gps_time(),
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
            Sbp::MsgPoseRelative(msg) => msg.gps_time(),
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
            Sbp::MsgSsrTileDefinitionDepA(msg) => msg.gps_time(),
            Sbp::MsgSsrTileDefinitionDepB(msg) => msg.gps_time(),
            Sbp::MsgSsrTileDefinition(msg) => msg.gps_time(),
            Sbp::MsgSsrGriddedCorrectionDepA(msg) => msg.gps_time(),
            Sbp::MsgSsrStecCorrectionDep(msg) => msg.gps_time(),
            Sbp::MsgSsrGriddedCorrection(msg) => msg.gps_time(),
            Sbp::MsgSsrStecCorrection(msg) => msg.gps_time(),
            Sbp::MsgSsrGriddedCorrectionBounds(msg) => msg.gps_time(),
            Sbp::MsgSsrSatelliteApcDep(msg) => msg.gps_time(),
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
            Sbp::MsgAcknowledge(msg) => msg.gps_time(),
            Sbp::MsgEd25519SignatureDepA(msg) => msg.gps_time(),
            Sbp::MsgEd25519CertificateDep(msg) => msg.gps_time(),
            Sbp::MsgEd25519SignatureDepB(msg) => msg.gps_time(),
            Sbp::MsgEcdsaCertificate(msg) => msg.gps_time(),
            Sbp::MsgCertificateChainDep(msg) => msg.gps_time(),
            Sbp::MsgEcdsaSignatureDepA(msg) => msg.gps_time(),
            Sbp::MsgEcdsaSignatureDepB(msg) => msg.gps_time(),
            Sbp::MsgEcdsaSignature(msg) => msg.gps_time(),
            Sbp::MsgCertificateChain(msg) => msg.gps_time(),
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
            Sbp::MsgMeasurementPoint(msg) => msg.gps_time(),
            Sbp::MsgProfilingSystemInfo(msg) => msg.gps_time(),
            Sbp::MsgProfilingThreadInfo(msg) => msg.gps_time(),
            Sbp::MsgProfilingResourceCounter(msg) => msg.gps_time(),
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
            Sbp::Invalid(msg) => msg.gps_time(),
        }
    }

    fn friendly_name(&self) -> &'static str {
        match self {
            Sbp::MsgPrintDep(msg) => msg.friendly_name(),
            Sbp::MsgTrackingStateDetailedDep(msg) => msg.friendly_name(),
            Sbp::MsgTrackingStateDepB(msg) => msg.friendly_name(),
            Sbp::MsgAcqResultDepB(msg) => msg.friendly_name(),
            Sbp::MsgAcqResultDepA(msg) => msg.friendly_name(),
            Sbp::MsgTrackingStateDepA(msg) => msg.friendly_name(),
            Sbp::MsgThreadState(msg) => msg.friendly_name(),
            Sbp::MsgUartStateDepa(msg) => msg.friendly_name(),
            Sbp::MsgIarState(msg) => msg.friendly_name(),
            Sbp::MsgEphemerisDepA(msg) => msg.friendly_name(),
            Sbp::MsgMaskSatelliteDep(msg) => msg.friendly_name(),
            Sbp::MsgTrackingIqDepA(msg) => msg.friendly_name(),
            Sbp::MsgUartState(msg) => msg.friendly_name(),
            Sbp::MsgAcqSvProfileDep(msg) => msg.friendly_name(),
            Sbp::MsgAcqResultDepC(msg) => msg.friendly_name(),
            Sbp::MsgTrackingStateDetailedDepA(msg) => msg.friendly_name(),
            Sbp::MsgResetFilters(msg) => msg.friendly_name(),
            Sbp::MsgInitBaseDep(msg) => msg.friendly_name(),
            Sbp::MsgMaskSatellite(msg) => msg.friendly_name(),
            Sbp::MsgTrackingIqDepB(msg) => msg.friendly_name(),
            Sbp::MsgTrackingIq(msg) => msg.friendly_name(),
            Sbp::MsgAcqSvProfile(msg) => msg.friendly_name(),
            Sbp::MsgAcqResult(msg) => msg.friendly_name(),
            Sbp::MsgTrackingState(msg) => msg.friendly_name(),
            Sbp::MsgObsDepB(msg) => msg.friendly_name(),
            Sbp::MsgBasePosLlh(msg) => msg.friendly_name(),
            Sbp::MsgObsDepA(msg) => msg.friendly_name(),
            Sbp::MsgEphemerisDepB(msg) => msg.friendly_name(),
            Sbp::MsgEphemerisDepC(msg) => msg.friendly_name(),
            Sbp::MsgBasePosEcef(msg) => msg.friendly_name(),
            Sbp::MsgObsDepC(msg) => msg.friendly_name(),
            Sbp::MsgObs(msg) => msg.friendly_name(),
            Sbp::MsgSpecanDep(msg) => msg.friendly_name(),
            Sbp::MsgSpecan(msg) => msg.friendly_name(),
            Sbp::MsgMeasurementState(msg) => msg.friendly_name(),
            Sbp::MsgSetTime(msg) => msg.friendly_name(),
            Sbp::MsgAlmanac(msg) => msg.friendly_name(),
            Sbp::MsgAlmanacGpsDep(msg) => msg.friendly_name(),
            Sbp::MsgAlmanacGloDep(msg) => msg.friendly_name(),
            Sbp::MsgAlmanacGps(msg) => msg.friendly_name(),
            Sbp::MsgAlmanacGlo(msg) => msg.friendly_name(),
            Sbp::MsgGloBiases(msg) => msg.friendly_name(),
            Sbp::MsgEphemerisDepD(msg) => msg.friendly_name(),
            Sbp::MsgEphemerisGpsDepE(msg) => msg.friendly_name(),
            Sbp::MsgEphemerisSbasDepA(msg) => msg.friendly_name(),
            Sbp::MsgEphemerisGloDepA(msg) => msg.friendly_name(),
            Sbp::MsgEphemerisSbasDepB(msg) => msg.friendly_name(),
            Sbp::MsgEphemerisGloDepB(msg) => msg.friendly_name(),
            Sbp::MsgEphemerisGpsDepF(msg) => msg.friendly_name(),
            Sbp::MsgEphemerisGloDepC(msg) => msg.friendly_name(),
            Sbp::MsgEphemerisGloDepD(msg) => msg.friendly_name(),
            Sbp::MsgEphemerisBds(msg) => msg.friendly_name(),
            Sbp::MsgEphemerisGps(msg) => msg.friendly_name(),
            Sbp::MsgEphemerisGlo(msg) => msg.friendly_name(),
            Sbp::MsgEphemerisSbas(msg) => msg.friendly_name(),
            Sbp::MsgEphemerisGal(msg) => msg.friendly_name(),
            Sbp::MsgEphemerisQzss(msg) => msg.friendly_name(),
            Sbp::MsgIono(msg) => msg.friendly_name(),
            Sbp::MsgSvConfigurationGpsDep(msg) => msg.friendly_name(),
            Sbp::MsgGroupDelayDepA(msg) => msg.friendly_name(),
            Sbp::MsgGroupDelayDepB(msg) => msg.friendly_name(),
            Sbp::MsgGroupDelay(msg) => msg.friendly_name(),
            Sbp::MsgEphemerisGalDepA(msg) => msg.friendly_name(),
            Sbp::MsgGnssCapb(msg) => msg.friendly_name(),
            Sbp::MsgSvAzEl(msg) => msg.friendly_name(),
            Sbp::MsgSettingsWrite(msg) => msg.friendly_name(),
            Sbp::MsgSettingsSave(msg) => msg.friendly_name(),
            Sbp::MsgSettingsReadByIndexReq(msg) => msg.friendly_name(),
            Sbp::MsgFileioReadResp(msg) => msg.friendly_name(),
            Sbp::MsgSettingsReadReq(msg) => msg.friendly_name(),
            Sbp::MsgSettingsReadResp(msg) => msg.friendly_name(),
            Sbp::MsgSettingsReadByIndexDone(msg) => msg.friendly_name(),
            Sbp::MsgSettingsReadByIndexResp(msg) => msg.friendly_name(),
            Sbp::MsgFileioReadReq(msg) => msg.friendly_name(),
            Sbp::MsgFileioReadDirReq(msg) => msg.friendly_name(),
            Sbp::MsgFileioReadDirResp(msg) => msg.friendly_name(),
            Sbp::MsgFileioWriteResp(msg) => msg.friendly_name(),
            Sbp::MsgFileioRemove(msg) => msg.friendly_name(),
            Sbp::MsgFileioWriteReq(msg) => msg.friendly_name(),
            Sbp::MsgSettingsRegister(msg) => msg.friendly_name(),
            Sbp::MsgSettingsWriteResp(msg) => msg.friendly_name(),
            Sbp::MsgBootloaderHandshakeDepA(msg) => msg.friendly_name(),
            Sbp::MsgBootloaderJumpToApp(msg) => msg.friendly_name(),
            Sbp::MsgResetDep(msg) => msg.friendly_name(),
            Sbp::MsgBootloaderHandshakeReq(msg) => msg.friendly_name(),
            Sbp::MsgBootloaderHandshakeResp(msg) => msg.friendly_name(),
            Sbp::MsgDeviceMonitor(msg) => msg.friendly_name(),
            Sbp::MsgReset(msg) => msg.friendly_name(),
            Sbp::MsgCommandReq(msg) => msg.friendly_name(),
            Sbp::MsgCommandResp(msg) => msg.friendly_name(),
            Sbp::MsgNetworkStateReq(msg) => msg.friendly_name(),
            Sbp::MsgNetworkStateResp(msg) => msg.friendly_name(),
            Sbp::MsgCommandOutput(msg) => msg.friendly_name(),
            Sbp::MsgNetworkBandwidthUsage(msg) => msg.friendly_name(),
            Sbp::MsgCellModemStatus(msg) => msg.friendly_name(),
            Sbp::MsgFrontEndGain(msg) => msg.friendly_name(),
            Sbp::MsgCwResults(msg) => msg.friendly_name(),
            Sbp::MsgCwStart(msg) => msg.friendly_name(),
            Sbp::MsgNapDeviceDnaResp(msg) => msg.friendly_name(),
            Sbp::MsgNapDeviceDnaReq(msg) => msg.friendly_name(),
            Sbp::MsgFlashDone(msg) => msg.friendly_name(),
            Sbp::MsgFlashReadResp(msg) => msg.friendly_name(),
            Sbp::MsgFlashErase(msg) => msg.friendly_name(),
            Sbp::MsgStmFlashLockSector(msg) => msg.friendly_name(),
            Sbp::MsgStmFlashUnlockSector(msg) => msg.friendly_name(),
            Sbp::MsgStmUniqueIdResp(msg) => msg.friendly_name(),
            Sbp::MsgFlashProgram(msg) => msg.friendly_name(),
            Sbp::MsgFlashReadReq(msg) => msg.friendly_name(),
            Sbp::MsgStmUniqueIdReq(msg) => msg.friendly_name(),
            Sbp::MsgM25FlashWriteStatus(msg) => msg.friendly_name(),
            Sbp::MsgGpsTimeDepA(msg) => msg.friendly_name(),
            Sbp::MsgExtEvent(msg) => msg.friendly_name(),
            Sbp::MsgGpsTime(msg) => msg.friendly_name(),
            Sbp::MsgUtcTime(msg) => msg.friendly_name(),
            Sbp::MsgGpsTimeGnss(msg) => msg.friendly_name(),
            Sbp::MsgUtcTimeGnss(msg) => msg.friendly_name(),
            Sbp::MsgTelSv(msg) => msg.friendly_name(),
            Sbp::MsgSettingsRegisterResp(msg) => msg.friendly_name(),
            Sbp::MsgPosEcefDepA(msg) => msg.friendly_name(),
            Sbp::MsgPosLlhDepA(msg) => msg.friendly_name(),
            Sbp::MsgBaselineEcefDepA(msg) => msg.friendly_name(),
            Sbp::MsgBaselineNedDepA(msg) => msg.friendly_name(),
            Sbp::MsgVelEcefDepA(msg) => msg.friendly_name(),
            Sbp::MsgVelNedDepA(msg) => msg.friendly_name(),
            Sbp::MsgDopsDepA(msg) => msg.friendly_name(),
            Sbp::MsgBaselineHeadingDepA(msg) => msg.friendly_name(),
            Sbp::MsgDops(msg) => msg.friendly_name(),
            Sbp::MsgPosEcef(msg) => msg.friendly_name(),
            Sbp::MsgPosLlh(msg) => msg.friendly_name(),
            Sbp::MsgBaselineEcef(msg) => msg.friendly_name(),
            Sbp::MsgBaselineNed(msg) => msg.friendly_name(),
            Sbp::MsgVelEcef(msg) => msg.friendly_name(),
            Sbp::MsgVelNed(msg) => msg.friendly_name(),
            Sbp::MsgBaselineHeading(msg) => msg.friendly_name(),
            Sbp::MsgAgeCorrections(msg) => msg.friendly_name(),
            Sbp::MsgPosLlhCov(msg) => msg.friendly_name(),
            Sbp::MsgVelNedCov(msg) => msg.friendly_name(),
            Sbp::MsgVelBody(msg) => msg.friendly_name(),
            Sbp::MsgPosEcefCov(msg) => msg.friendly_name(),
            Sbp::MsgVelEcefCov(msg) => msg.friendly_name(),
            Sbp::MsgProtectionLevelDepA(msg) => msg.friendly_name(),
            Sbp::MsgProtectionLevel(msg) => msg.friendly_name(),
            Sbp::MsgPosLlhAcc(msg) => msg.friendly_name(),
            Sbp::MsgVelCog(msg) => msg.friendly_name(),
            Sbp::MsgOrientQuat(msg) => msg.friendly_name(),
            Sbp::MsgOrientEuler(msg) => msg.friendly_name(),
            Sbp::MsgAngularRate(msg) => msg.friendly_name(),
            Sbp::MsgPosEcefGnss(msg) => msg.friendly_name(),
            Sbp::MsgPosLlhGnss(msg) => msg.friendly_name(),
            Sbp::MsgVelEcefGnss(msg) => msg.friendly_name(),
            Sbp::MsgVelNedGnss(msg) => msg.friendly_name(),
            Sbp::MsgPosLlhCovGnss(msg) => msg.friendly_name(),
            Sbp::MsgVelNedCovGnss(msg) => msg.friendly_name(),
            Sbp::MsgPosEcefCovGnss(msg) => msg.friendly_name(),
            Sbp::MsgVelEcefCovGnss(msg) => msg.friendly_name(),
            Sbp::MsgUtcLeapSecond(msg) => msg.friendly_name(),
            Sbp::MsgReferenceFrameParam(msg) => msg.friendly_name(),
            Sbp::MsgPoseRelative(msg) => msg.friendly_name(),
            Sbp::MsgNdbEvent(msg) => msg.friendly_name(),
            Sbp::MsgLog(msg) => msg.friendly_name(),
            Sbp::MsgFwd(msg) => msg.friendly_name(),
            Sbp::MsgSsrOrbitClockDepA(msg) => msg.friendly_name(),
            Sbp::MsgSsrOrbitClock(msg) => msg.friendly_name(),
            Sbp::MsgSsrOrbitClockBounds(msg) => msg.friendly_name(),
            Sbp::MsgSsrOrbitClockBoundsDegradation(msg) => msg.friendly_name(),
            Sbp::MsgSsrCodeBiases(msg) => msg.friendly_name(),
            Sbp::MsgSsrPhaseBiases(msg) => msg.friendly_name(),
            Sbp::MsgSsrStecCorrectionDepA(msg) => msg.friendly_name(),
            Sbp::MsgSsrCodePhaseBiasesBounds(msg) => msg.friendly_name(),
            Sbp::MsgSsrGriddedCorrectionNoStdDepA(msg) => msg.friendly_name(),
            Sbp::MsgSsrGridDefinitionDepA(msg) => msg.friendly_name(),
            Sbp::MsgSsrTileDefinitionDepA(msg) => msg.friendly_name(),
            Sbp::MsgSsrTileDefinitionDepB(msg) => msg.friendly_name(),
            Sbp::MsgSsrTileDefinition(msg) => msg.friendly_name(),
            Sbp::MsgSsrGriddedCorrectionDepA(msg) => msg.friendly_name(),
            Sbp::MsgSsrStecCorrectionDep(msg) => msg.friendly_name(),
            Sbp::MsgSsrGriddedCorrection(msg) => msg.friendly_name(),
            Sbp::MsgSsrStecCorrection(msg) => msg.friendly_name(),
            Sbp::MsgSsrGriddedCorrectionBounds(msg) => msg.friendly_name(),
            Sbp::MsgSsrSatelliteApcDep(msg) => msg.friendly_name(),
            Sbp::MsgSsrSatelliteApc(msg) => msg.friendly_name(),
            Sbp::MsgOsr(msg) => msg.friendly_name(),
            Sbp::MsgUserData(msg) => msg.friendly_name(),
            Sbp::MsgImuRaw(msg) => msg.friendly_name(),
            Sbp::MsgImuAux(msg) => msg.friendly_name(),
            Sbp::MsgMagRaw(msg) => msg.friendly_name(),
            Sbp::MsgOdometry(msg) => msg.friendly_name(),
            Sbp::MsgWheeltick(msg) => msg.friendly_name(),
            Sbp::MsgSsrFlagHighLevel(msg) => msg.friendly_name(),
            Sbp::MsgSsrFlagSatellites(msg) => msg.friendly_name(),
            Sbp::MsgSsrFlagTropoGridPoints(msg) => msg.friendly_name(),
            Sbp::MsgSsrFlagIonoGridPoints(msg) => msg.friendly_name(),
            Sbp::MsgSsrFlagIonoTileSatLos(msg) => msg.friendly_name(),
            Sbp::MsgSsrFlagIonoGridPointSatLos(msg) => msg.friendly_name(),
            Sbp::MsgAcknowledge(msg) => msg.friendly_name(),
            Sbp::MsgEd25519SignatureDepA(msg) => msg.friendly_name(),
            Sbp::MsgEd25519CertificateDep(msg) => msg.friendly_name(),
            Sbp::MsgEd25519SignatureDepB(msg) => msg.friendly_name(),
            Sbp::MsgEcdsaCertificate(msg) => msg.friendly_name(),
            Sbp::MsgCertificateChainDep(msg) => msg.friendly_name(),
            Sbp::MsgEcdsaSignatureDepA(msg) => msg.friendly_name(),
            Sbp::MsgEcdsaSignatureDepB(msg) => msg.friendly_name(),
            Sbp::MsgEcdsaSignature(msg) => msg.friendly_name(),
            Sbp::MsgCertificateChain(msg) => msg.friendly_name(),
            Sbp::MsgFileioConfigReq(msg) => msg.friendly_name(),
            Sbp::MsgFileioConfigResp(msg) => msg.friendly_name(),
            Sbp::MsgSbasRaw(msg) => msg.friendly_name(),
            Sbp::MsgLinuxCpuStateDepA(msg) => msg.friendly_name(),
            Sbp::MsgLinuxMemStateDepA(msg) => msg.friendly_name(),
            Sbp::MsgLinuxSysStateDepA(msg) => msg.friendly_name(),
            Sbp::MsgLinuxProcessSocketCounts(msg) => msg.friendly_name(),
            Sbp::MsgLinuxProcessSocketQueues(msg) => msg.friendly_name(),
            Sbp::MsgLinuxSocketUsage(msg) => msg.friendly_name(),
            Sbp::MsgLinuxProcessFdCount(msg) => msg.friendly_name(),
            Sbp::MsgLinuxProcessFdSummary(msg) => msg.friendly_name(),
            Sbp::MsgLinuxCpuState(msg) => msg.friendly_name(),
            Sbp::MsgLinuxMemState(msg) => msg.friendly_name(),
            Sbp::MsgLinuxSysState(msg) => msg.friendly_name(),
            Sbp::MsgMeasurementPoint(msg) => msg.friendly_name(),
            Sbp::MsgProfilingSystemInfo(msg) => msg.friendly_name(),
            Sbp::MsgProfilingThreadInfo(msg) => msg.friendly_name(),
            Sbp::MsgProfilingResourceCounter(msg) => msg.friendly_name(),
            Sbp::MsgStartup(msg) => msg.friendly_name(),
            Sbp::MsgDgnssStatus(msg) => msg.friendly_name(),
            Sbp::MsgInsStatus(msg) => msg.friendly_name(),
            Sbp::MsgCsacTelemetry(msg) => msg.friendly_name(),
            Sbp::MsgCsacTelemetryLabels(msg) => msg.friendly_name(),
            Sbp::MsgInsUpdates(msg) => msg.friendly_name(),
            Sbp::MsgGnssTimeOffset(msg) => msg.friendly_name(),
            Sbp::MsgPpsTime(msg) => msg.friendly_name(),
            Sbp::MsgSensorAidEvent(msg) => msg.friendly_name(),
            Sbp::MsgGroupMeta(msg) => msg.friendly_name(),
            Sbp::MsgSolnMeta(msg) => msg.friendly_name(),
            Sbp::MsgSolnMetaDepA(msg) => msg.friendly_name(),
            Sbp::MsgStatusJournal(msg) => msg.friendly_name(),
            Sbp::MsgStatusReport(msg) => msg.friendly_name(),
            Sbp::MsgHeartbeat(msg) => msg.friendly_name(),
            Sbp::Unknown(msg) => msg.friendly_name(),
            Sbp::Invalid(msg) => msg.friendly_name(),
        }
    }

    fn is_valid(&self) -> bool {
        match self {
            Sbp::MsgPrintDep(msg) => msg.is_valid(),
            Sbp::MsgTrackingStateDetailedDep(msg) => msg.is_valid(),
            Sbp::MsgTrackingStateDepB(msg) => msg.is_valid(),
            Sbp::MsgAcqResultDepB(msg) => msg.is_valid(),
            Sbp::MsgAcqResultDepA(msg) => msg.is_valid(),
            Sbp::MsgTrackingStateDepA(msg) => msg.is_valid(),
            Sbp::MsgThreadState(msg) => msg.is_valid(),
            Sbp::MsgUartStateDepa(msg) => msg.is_valid(),
            Sbp::MsgIarState(msg) => msg.is_valid(),
            Sbp::MsgEphemerisDepA(msg) => msg.is_valid(),
            Sbp::MsgMaskSatelliteDep(msg) => msg.is_valid(),
            Sbp::MsgTrackingIqDepA(msg) => msg.is_valid(),
            Sbp::MsgUartState(msg) => msg.is_valid(),
            Sbp::MsgAcqSvProfileDep(msg) => msg.is_valid(),
            Sbp::MsgAcqResultDepC(msg) => msg.is_valid(),
            Sbp::MsgTrackingStateDetailedDepA(msg) => msg.is_valid(),
            Sbp::MsgResetFilters(msg) => msg.is_valid(),
            Sbp::MsgInitBaseDep(msg) => msg.is_valid(),
            Sbp::MsgMaskSatellite(msg) => msg.is_valid(),
            Sbp::MsgTrackingIqDepB(msg) => msg.is_valid(),
            Sbp::MsgTrackingIq(msg) => msg.is_valid(),
            Sbp::MsgAcqSvProfile(msg) => msg.is_valid(),
            Sbp::MsgAcqResult(msg) => msg.is_valid(),
            Sbp::MsgTrackingState(msg) => msg.is_valid(),
            Sbp::MsgObsDepB(msg) => msg.is_valid(),
            Sbp::MsgBasePosLlh(msg) => msg.is_valid(),
            Sbp::MsgObsDepA(msg) => msg.is_valid(),
            Sbp::MsgEphemerisDepB(msg) => msg.is_valid(),
            Sbp::MsgEphemerisDepC(msg) => msg.is_valid(),
            Sbp::MsgBasePosEcef(msg) => msg.is_valid(),
            Sbp::MsgObsDepC(msg) => msg.is_valid(),
            Sbp::MsgObs(msg) => msg.is_valid(),
            Sbp::MsgSpecanDep(msg) => msg.is_valid(),
            Sbp::MsgSpecan(msg) => msg.is_valid(),
            Sbp::MsgMeasurementState(msg) => msg.is_valid(),
            Sbp::MsgSetTime(msg) => msg.is_valid(),
            Sbp::MsgAlmanac(msg) => msg.is_valid(),
            Sbp::MsgAlmanacGpsDep(msg) => msg.is_valid(),
            Sbp::MsgAlmanacGloDep(msg) => msg.is_valid(),
            Sbp::MsgAlmanacGps(msg) => msg.is_valid(),
            Sbp::MsgAlmanacGlo(msg) => msg.is_valid(),
            Sbp::MsgGloBiases(msg) => msg.is_valid(),
            Sbp::MsgEphemerisDepD(msg) => msg.is_valid(),
            Sbp::MsgEphemerisGpsDepE(msg) => msg.is_valid(),
            Sbp::MsgEphemerisSbasDepA(msg) => msg.is_valid(),
            Sbp::MsgEphemerisGloDepA(msg) => msg.is_valid(),
            Sbp::MsgEphemerisSbasDepB(msg) => msg.is_valid(),
            Sbp::MsgEphemerisGloDepB(msg) => msg.is_valid(),
            Sbp::MsgEphemerisGpsDepF(msg) => msg.is_valid(),
            Sbp::MsgEphemerisGloDepC(msg) => msg.is_valid(),
            Sbp::MsgEphemerisGloDepD(msg) => msg.is_valid(),
            Sbp::MsgEphemerisBds(msg) => msg.is_valid(),
            Sbp::MsgEphemerisGps(msg) => msg.is_valid(),
            Sbp::MsgEphemerisGlo(msg) => msg.is_valid(),
            Sbp::MsgEphemerisSbas(msg) => msg.is_valid(),
            Sbp::MsgEphemerisGal(msg) => msg.is_valid(),
            Sbp::MsgEphemerisQzss(msg) => msg.is_valid(),
            Sbp::MsgIono(msg) => msg.is_valid(),
            Sbp::MsgSvConfigurationGpsDep(msg) => msg.is_valid(),
            Sbp::MsgGroupDelayDepA(msg) => msg.is_valid(),
            Sbp::MsgGroupDelayDepB(msg) => msg.is_valid(),
            Sbp::MsgGroupDelay(msg) => msg.is_valid(),
            Sbp::MsgEphemerisGalDepA(msg) => msg.is_valid(),
            Sbp::MsgGnssCapb(msg) => msg.is_valid(),
            Sbp::MsgSvAzEl(msg) => msg.is_valid(),
            Sbp::MsgSettingsWrite(msg) => msg.is_valid(),
            Sbp::MsgSettingsSave(msg) => msg.is_valid(),
            Sbp::MsgSettingsReadByIndexReq(msg) => msg.is_valid(),
            Sbp::MsgFileioReadResp(msg) => msg.is_valid(),
            Sbp::MsgSettingsReadReq(msg) => msg.is_valid(),
            Sbp::MsgSettingsReadResp(msg) => msg.is_valid(),
            Sbp::MsgSettingsReadByIndexDone(msg) => msg.is_valid(),
            Sbp::MsgSettingsReadByIndexResp(msg) => msg.is_valid(),
            Sbp::MsgFileioReadReq(msg) => msg.is_valid(),
            Sbp::MsgFileioReadDirReq(msg) => msg.is_valid(),
            Sbp::MsgFileioReadDirResp(msg) => msg.is_valid(),
            Sbp::MsgFileioWriteResp(msg) => msg.is_valid(),
            Sbp::MsgFileioRemove(msg) => msg.is_valid(),
            Sbp::MsgFileioWriteReq(msg) => msg.is_valid(),
            Sbp::MsgSettingsRegister(msg) => msg.is_valid(),
            Sbp::MsgSettingsWriteResp(msg) => msg.is_valid(),
            Sbp::MsgBootloaderHandshakeDepA(msg) => msg.is_valid(),
            Sbp::MsgBootloaderJumpToApp(msg) => msg.is_valid(),
            Sbp::MsgResetDep(msg) => msg.is_valid(),
            Sbp::MsgBootloaderHandshakeReq(msg) => msg.is_valid(),
            Sbp::MsgBootloaderHandshakeResp(msg) => msg.is_valid(),
            Sbp::MsgDeviceMonitor(msg) => msg.is_valid(),
            Sbp::MsgReset(msg) => msg.is_valid(),
            Sbp::MsgCommandReq(msg) => msg.is_valid(),
            Sbp::MsgCommandResp(msg) => msg.is_valid(),
            Sbp::MsgNetworkStateReq(msg) => msg.is_valid(),
            Sbp::MsgNetworkStateResp(msg) => msg.is_valid(),
            Sbp::MsgCommandOutput(msg) => msg.is_valid(),
            Sbp::MsgNetworkBandwidthUsage(msg) => msg.is_valid(),
            Sbp::MsgCellModemStatus(msg) => msg.is_valid(),
            Sbp::MsgFrontEndGain(msg) => msg.is_valid(),
            Sbp::MsgCwResults(msg) => msg.is_valid(),
            Sbp::MsgCwStart(msg) => msg.is_valid(),
            Sbp::MsgNapDeviceDnaResp(msg) => msg.is_valid(),
            Sbp::MsgNapDeviceDnaReq(msg) => msg.is_valid(),
            Sbp::MsgFlashDone(msg) => msg.is_valid(),
            Sbp::MsgFlashReadResp(msg) => msg.is_valid(),
            Sbp::MsgFlashErase(msg) => msg.is_valid(),
            Sbp::MsgStmFlashLockSector(msg) => msg.is_valid(),
            Sbp::MsgStmFlashUnlockSector(msg) => msg.is_valid(),
            Sbp::MsgStmUniqueIdResp(msg) => msg.is_valid(),
            Sbp::MsgFlashProgram(msg) => msg.is_valid(),
            Sbp::MsgFlashReadReq(msg) => msg.is_valid(),
            Sbp::MsgStmUniqueIdReq(msg) => msg.is_valid(),
            Sbp::MsgM25FlashWriteStatus(msg) => msg.is_valid(),
            Sbp::MsgGpsTimeDepA(msg) => msg.is_valid(),
            Sbp::MsgExtEvent(msg) => msg.is_valid(),
            Sbp::MsgGpsTime(msg) => msg.is_valid(),
            Sbp::MsgUtcTime(msg) => msg.is_valid(),
            Sbp::MsgGpsTimeGnss(msg) => msg.is_valid(),
            Sbp::MsgUtcTimeGnss(msg) => msg.is_valid(),
            Sbp::MsgTelSv(msg) => msg.is_valid(),
            Sbp::MsgSettingsRegisterResp(msg) => msg.is_valid(),
            Sbp::MsgPosEcefDepA(msg) => msg.is_valid(),
            Sbp::MsgPosLlhDepA(msg) => msg.is_valid(),
            Sbp::MsgBaselineEcefDepA(msg) => msg.is_valid(),
            Sbp::MsgBaselineNedDepA(msg) => msg.is_valid(),
            Sbp::MsgVelEcefDepA(msg) => msg.is_valid(),
            Sbp::MsgVelNedDepA(msg) => msg.is_valid(),
            Sbp::MsgDopsDepA(msg) => msg.is_valid(),
            Sbp::MsgBaselineHeadingDepA(msg) => msg.is_valid(),
            Sbp::MsgDops(msg) => msg.is_valid(),
            Sbp::MsgPosEcef(msg) => msg.is_valid(),
            Sbp::MsgPosLlh(msg) => msg.is_valid(),
            Sbp::MsgBaselineEcef(msg) => msg.is_valid(),
            Sbp::MsgBaselineNed(msg) => msg.is_valid(),
            Sbp::MsgVelEcef(msg) => msg.is_valid(),
            Sbp::MsgVelNed(msg) => msg.is_valid(),
            Sbp::MsgBaselineHeading(msg) => msg.is_valid(),
            Sbp::MsgAgeCorrections(msg) => msg.is_valid(),
            Sbp::MsgPosLlhCov(msg) => msg.is_valid(),
            Sbp::MsgVelNedCov(msg) => msg.is_valid(),
            Sbp::MsgVelBody(msg) => msg.is_valid(),
            Sbp::MsgPosEcefCov(msg) => msg.is_valid(),
            Sbp::MsgVelEcefCov(msg) => msg.is_valid(),
            Sbp::MsgProtectionLevelDepA(msg) => msg.is_valid(),
            Sbp::MsgProtectionLevel(msg) => msg.is_valid(),
            Sbp::MsgPosLlhAcc(msg) => msg.is_valid(),
            Sbp::MsgVelCog(msg) => msg.is_valid(),
            Sbp::MsgOrientQuat(msg) => msg.is_valid(),
            Sbp::MsgOrientEuler(msg) => msg.is_valid(),
            Sbp::MsgAngularRate(msg) => msg.is_valid(),
            Sbp::MsgPosEcefGnss(msg) => msg.is_valid(),
            Sbp::MsgPosLlhGnss(msg) => msg.is_valid(),
            Sbp::MsgVelEcefGnss(msg) => msg.is_valid(),
            Sbp::MsgVelNedGnss(msg) => msg.is_valid(),
            Sbp::MsgPosLlhCovGnss(msg) => msg.is_valid(),
            Sbp::MsgVelNedCovGnss(msg) => msg.is_valid(),
            Sbp::MsgPosEcefCovGnss(msg) => msg.is_valid(),
            Sbp::MsgVelEcefCovGnss(msg) => msg.is_valid(),
            Sbp::MsgUtcLeapSecond(msg) => msg.is_valid(),
            Sbp::MsgReferenceFrameParam(msg) => msg.is_valid(),
            Sbp::MsgPoseRelative(msg) => msg.is_valid(),
            Sbp::MsgNdbEvent(msg) => msg.is_valid(),
            Sbp::MsgLog(msg) => msg.is_valid(),
            Sbp::MsgFwd(msg) => msg.is_valid(),
            Sbp::MsgSsrOrbitClockDepA(msg) => msg.is_valid(),
            Sbp::MsgSsrOrbitClock(msg) => msg.is_valid(),
            Sbp::MsgSsrOrbitClockBounds(msg) => msg.is_valid(),
            Sbp::MsgSsrOrbitClockBoundsDegradation(msg) => msg.is_valid(),
            Sbp::MsgSsrCodeBiases(msg) => msg.is_valid(),
            Sbp::MsgSsrPhaseBiases(msg) => msg.is_valid(),
            Sbp::MsgSsrStecCorrectionDepA(msg) => msg.is_valid(),
            Sbp::MsgSsrCodePhaseBiasesBounds(msg) => msg.is_valid(),
            Sbp::MsgSsrGriddedCorrectionNoStdDepA(msg) => msg.is_valid(),
            Sbp::MsgSsrGridDefinitionDepA(msg) => msg.is_valid(),
            Sbp::MsgSsrTileDefinitionDepA(msg) => msg.is_valid(),
            Sbp::MsgSsrTileDefinitionDepB(msg) => msg.is_valid(),
            Sbp::MsgSsrTileDefinition(msg) => msg.is_valid(),
            Sbp::MsgSsrGriddedCorrectionDepA(msg) => msg.is_valid(),
            Sbp::MsgSsrStecCorrectionDep(msg) => msg.is_valid(),
            Sbp::MsgSsrGriddedCorrection(msg) => msg.is_valid(),
            Sbp::MsgSsrStecCorrection(msg) => msg.is_valid(),
            Sbp::MsgSsrGriddedCorrectionBounds(msg) => msg.is_valid(),
            Sbp::MsgSsrSatelliteApcDep(msg) => msg.is_valid(),
            Sbp::MsgSsrSatelliteApc(msg) => msg.is_valid(),
            Sbp::MsgOsr(msg) => msg.is_valid(),
            Sbp::MsgUserData(msg) => msg.is_valid(),
            Sbp::MsgImuRaw(msg) => msg.is_valid(),
            Sbp::MsgImuAux(msg) => msg.is_valid(),
            Sbp::MsgMagRaw(msg) => msg.is_valid(),
            Sbp::MsgOdometry(msg) => msg.is_valid(),
            Sbp::MsgWheeltick(msg) => msg.is_valid(),
            Sbp::MsgSsrFlagHighLevel(msg) => msg.is_valid(),
            Sbp::MsgSsrFlagSatellites(msg) => msg.is_valid(),
            Sbp::MsgSsrFlagTropoGridPoints(msg) => msg.is_valid(),
            Sbp::MsgSsrFlagIonoGridPoints(msg) => msg.is_valid(),
            Sbp::MsgSsrFlagIonoTileSatLos(msg) => msg.is_valid(),
            Sbp::MsgSsrFlagIonoGridPointSatLos(msg) => msg.is_valid(),
            Sbp::MsgAcknowledge(msg) => msg.is_valid(),
            Sbp::MsgEd25519SignatureDepA(msg) => msg.is_valid(),
            Sbp::MsgEd25519CertificateDep(msg) => msg.is_valid(),
            Sbp::MsgEd25519SignatureDepB(msg) => msg.is_valid(),
            Sbp::MsgEcdsaCertificate(msg) => msg.is_valid(),
            Sbp::MsgCertificateChainDep(msg) => msg.is_valid(),
            Sbp::MsgEcdsaSignatureDepA(msg) => msg.is_valid(),
            Sbp::MsgEcdsaSignatureDepB(msg) => msg.is_valid(),
            Sbp::MsgEcdsaSignature(msg) => msg.is_valid(),
            Sbp::MsgCertificateChain(msg) => msg.is_valid(),
            Sbp::MsgFileioConfigReq(msg) => msg.is_valid(),
            Sbp::MsgFileioConfigResp(msg) => msg.is_valid(),
            Sbp::MsgSbasRaw(msg) => msg.is_valid(),
            Sbp::MsgLinuxCpuStateDepA(msg) => msg.is_valid(),
            Sbp::MsgLinuxMemStateDepA(msg) => msg.is_valid(),
            Sbp::MsgLinuxSysStateDepA(msg) => msg.is_valid(),
            Sbp::MsgLinuxProcessSocketCounts(msg) => msg.is_valid(),
            Sbp::MsgLinuxProcessSocketQueues(msg) => msg.is_valid(),
            Sbp::MsgLinuxSocketUsage(msg) => msg.is_valid(),
            Sbp::MsgLinuxProcessFdCount(msg) => msg.is_valid(),
            Sbp::MsgLinuxProcessFdSummary(msg) => msg.is_valid(),
            Sbp::MsgLinuxCpuState(msg) => msg.is_valid(),
            Sbp::MsgLinuxMemState(msg) => msg.is_valid(),
            Sbp::MsgLinuxSysState(msg) => msg.is_valid(),
            Sbp::MsgMeasurementPoint(msg) => msg.is_valid(),
            Sbp::MsgProfilingSystemInfo(msg) => msg.is_valid(),
            Sbp::MsgProfilingThreadInfo(msg) => msg.is_valid(),
            Sbp::MsgProfilingResourceCounter(msg) => msg.is_valid(),
            Sbp::MsgStartup(msg) => msg.is_valid(),
            Sbp::MsgDgnssStatus(msg) => msg.is_valid(),
            Sbp::MsgInsStatus(msg) => msg.is_valid(),
            Sbp::MsgCsacTelemetry(msg) => msg.is_valid(),
            Sbp::MsgCsacTelemetryLabels(msg) => msg.is_valid(),
            Sbp::MsgInsUpdates(msg) => msg.is_valid(),
            Sbp::MsgGnssTimeOffset(msg) => msg.is_valid(),
            Sbp::MsgPpsTime(msg) => msg.is_valid(),
            Sbp::MsgSensorAidEvent(msg) => msg.is_valid(),
            Sbp::MsgGroupMeta(msg) => msg.is_valid(),
            Sbp::MsgSolnMeta(msg) => msg.is_valid(),
            Sbp::MsgSolnMetaDepA(msg) => msg.is_valid(),
            Sbp::MsgStatusJournal(msg) => msg.is_valid(),
            Sbp::MsgStatusReport(msg) => msg.is_valid(),
            Sbp::MsgHeartbeat(msg) => msg.is_valid(),
            Sbp::Unknown(msg) => msg.is_valid(),
            Sbp::Invalid(msg) => msg.is_valid(),
        }
    }
    fn into_valid_msg(self) -> Result<Self, crate::messages::invalid::Invalid> {
        match self {
            Sbp::MsgPrintDep(msg) => Ok(Sbp::MsgPrintDep(msg.into_valid_msg()?)),
            Sbp::MsgTrackingStateDetailedDep(msg) => {
                Ok(Sbp::MsgTrackingStateDetailedDep(msg.into_valid_msg()?))
            }
            Sbp::MsgTrackingStateDepB(msg) => Ok(Sbp::MsgTrackingStateDepB(msg.into_valid_msg()?)),
            Sbp::MsgAcqResultDepB(msg) => Ok(Sbp::MsgAcqResultDepB(msg.into_valid_msg()?)),
            Sbp::MsgAcqResultDepA(msg) => Ok(Sbp::MsgAcqResultDepA(msg.into_valid_msg()?)),
            Sbp::MsgTrackingStateDepA(msg) => Ok(Sbp::MsgTrackingStateDepA(msg.into_valid_msg()?)),
            Sbp::MsgThreadState(msg) => Ok(Sbp::MsgThreadState(msg.into_valid_msg()?)),
            Sbp::MsgUartStateDepa(msg) => Ok(Sbp::MsgUartStateDepa(msg.into_valid_msg()?)),
            Sbp::MsgIarState(msg) => Ok(Sbp::MsgIarState(msg.into_valid_msg()?)),
            Sbp::MsgEphemerisDepA(msg) => Ok(Sbp::MsgEphemerisDepA(msg.into_valid_msg()?)),
            Sbp::MsgMaskSatelliteDep(msg) => Ok(Sbp::MsgMaskSatelliteDep(msg.into_valid_msg()?)),
            Sbp::MsgTrackingIqDepA(msg) => Ok(Sbp::MsgTrackingIqDepA(msg.into_valid_msg()?)),
            Sbp::MsgUartState(msg) => Ok(Sbp::MsgUartState(msg.into_valid_msg()?)),
            Sbp::MsgAcqSvProfileDep(msg) => Ok(Sbp::MsgAcqSvProfileDep(msg.into_valid_msg()?)),
            Sbp::MsgAcqResultDepC(msg) => Ok(Sbp::MsgAcqResultDepC(msg.into_valid_msg()?)),
            Sbp::MsgTrackingStateDetailedDepA(msg) => {
                Ok(Sbp::MsgTrackingStateDetailedDepA(msg.into_valid_msg()?))
            }
            Sbp::MsgResetFilters(msg) => Ok(Sbp::MsgResetFilters(msg.into_valid_msg()?)),
            Sbp::MsgInitBaseDep(msg) => Ok(Sbp::MsgInitBaseDep(msg.into_valid_msg()?)),
            Sbp::MsgMaskSatellite(msg) => Ok(Sbp::MsgMaskSatellite(msg.into_valid_msg()?)),
            Sbp::MsgTrackingIqDepB(msg) => Ok(Sbp::MsgTrackingIqDepB(msg.into_valid_msg()?)),
            Sbp::MsgTrackingIq(msg) => Ok(Sbp::MsgTrackingIq(msg.into_valid_msg()?)),
            Sbp::MsgAcqSvProfile(msg) => Ok(Sbp::MsgAcqSvProfile(msg.into_valid_msg()?)),
            Sbp::MsgAcqResult(msg) => Ok(Sbp::MsgAcqResult(msg.into_valid_msg()?)),
            Sbp::MsgTrackingState(msg) => Ok(Sbp::MsgTrackingState(msg.into_valid_msg()?)),
            Sbp::MsgObsDepB(msg) => Ok(Sbp::MsgObsDepB(msg.into_valid_msg()?)),
            Sbp::MsgBasePosLlh(msg) => Ok(Sbp::MsgBasePosLlh(msg.into_valid_msg()?)),
            Sbp::MsgObsDepA(msg) => Ok(Sbp::MsgObsDepA(msg.into_valid_msg()?)),
            Sbp::MsgEphemerisDepB(msg) => Ok(Sbp::MsgEphemerisDepB(msg.into_valid_msg()?)),
            Sbp::MsgEphemerisDepC(msg) => Ok(Sbp::MsgEphemerisDepC(msg.into_valid_msg()?)),
            Sbp::MsgBasePosEcef(msg) => Ok(Sbp::MsgBasePosEcef(msg.into_valid_msg()?)),
            Sbp::MsgObsDepC(msg) => Ok(Sbp::MsgObsDepC(msg.into_valid_msg()?)),
            Sbp::MsgObs(msg) => Ok(Sbp::MsgObs(msg.into_valid_msg()?)),
            Sbp::MsgSpecanDep(msg) => Ok(Sbp::MsgSpecanDep(msg.into_valid_msg()?)),
            Sbp::MsgSpecan(msg) => Ok(Sbp::MsgSpecan(msg.into_valid_msg()?)),
            Sbp::MsgMeasurementState(msg) => Ok(Sbp::MsgMeasurementState(msg.into_valid_msg()?)),
            Sbp::MsgSetTime(msg) => Ok(Sbp::MsgSetTime(msg.into_valid_msg()?)),
            Sbp::MsgAlmanac(msg) => Ok(Sbp::MsgAlmanac(msg.into_valid_msg()?)),
            Sbp::MsgAlmanacGpsDep(msg) => Ok(Sbp::MsgAlmanacGpsDep(msg.into_valid_msg()?)),
            Sbp::MsgAlmanacGloDep(msg) => Ok(Sbp::MsgAlmanacGloDep(msg.into_valid_msg()?)),
            Sbp::MsgAlmanacGps(msg) => Ok(Sbp::MsgAlmanacGps(msg.into_valid_msg()?)),
            Sbp::MsgAlmanacGlo(msg) => Ok(Sbp::MsgAlmanacGlo(msg.into_valid_msg()?)),
            Sbp::MsgGloBiases(msg) => Ok(Sbp::MsgGloBiases(msg.into_valid_msg()?)),
            Sbp::MsgEphemerisDepD(msg) => Ok(Sbp::MsgEphemerisDepD(msg.into_valid_msg()?)),
            Sbp::MsgEphemerisGpsDepE(msg) => Ok(Sbp::MsgEphemerisGpsDepE(msg.into_valid_msg()?)),
            Sbp::MsgEphemerisSbasDepA(msg) => Ok(Sbp::MsgEphemerisSbasDepA(msg.into_valid_msg()?)),
            Sbp::MsgEphemerisGloDepA(msg) => Ok(Sbp::MsgEphemerisGloDepA(msg.into_valid_msg()?)),
            Sbp::MsgEphemerisSbasDepB(msg) => Ok(Sbp::MsgEphemerisSbasDepB(msg.into_valid_msg()?)),
            Sbp::MsgEphemerisGloDepB(msg) => Ok(Sbp::MsgEphemerisGloDepB(msg.into_valid_msg()?)),
            Sbp::MsgEphemerisGpsDepF(msg) => Ok(Sbp::MsgEphemerisGpsDepF(msg.into_valid_msg()?)),
            Sbp::MsgEphemerisGloDepC(msg) => Ok(Sbp::MsgEphemerisGloDepC(msg.into_valid_msg()?)),
            Sbp::MsgEphemerisGloDepD(msg) => Ok(Sbp::MsgEphemerisGloDepD(msg.into_valid_msg()?)),
            Sbp::MsgEphemerisBds(msg) => Ok(Sbp::MsgEphemerisBds(msg.into_valid_msg()?)),
            Sbp::MsgEphemerisGps(msg) => Ok(Sbp::MsgEphemerisGps(msg.into_valid_msg()?)),
            Sbp::MsgEphemerisGlo(msg) => Ok(Sbp::MsgEphemerisGlo(msg.into_valid_msg()?)),
            Sbp::MsgEphemerisSbas(msg) => Ok(Sbp::MsgEphemerisSbas(msg.into_valid_msg()?)),
            Sbp::MsgEphemerisGal(msg) => Ok(Sbp::MsgEphemerisGal(msg.into_valid_msg()?)),
            Sbp::MsgEphemerisQzss(msg) => Ok(Sbp::MsgEphemerisQzss(msg.into_valid_msg()?)),
            Sbp::MsgIono(msg) => Ok(Sbp::MsgIono(msg.into_valid_msg()?)),
            Sbp::MsgSvConfigurationGpsDep(msg) => {
                Ok(Sbp::MsgSvConfigurationGpsDep(msg.into_valid_msg()?))
            }
            Sbp::MsgGroupDelayDepA(msg) => Ok(Sbp::MsgGroupDelayDepA(msg.into_valid_msg()?)),
            Sbp::MsgGroupDelayDepB(msg) => Ok(Sbp::MsgGroupDelayDepB(msg.into_valid_msg()?)),
            Sbp::MsgGroupDelay(msg) => Ok(Sbp::MsgGroupDelay(msg.into_valid_msg()?)),
            Sbp::MsgEphemerisGalDepA(msg) => Ok(Sbp::MsgEphemerisGalDepA(msg.into_valid_msg()?)),
            Sbp::MsgGnssCapb(msg) => Ok(Sbp::MsgGnssCapb(msg.into_valid_msg()?)),
            Sbp::MsgSvAzEl(msg) => Ok(Sbp::MsgSvAzEl(msg.into_valid_msg()?)),
            Sbp::MsgSettingsWrite(msg) => Ok(Sbp::MsgSettingsWrite(msg.into_valid_msg()?)),
            Sbp::MsgSettingsSave(msg) => Ok(Sbp::MsgSettingsSave(msg.into_valid_msg()?)),
            Sbp::MsgSettingsReadByIndexReq(msg) => {
                Ok(Sbp::MsgSettingsReadByIndexReq(msg.into_valid_msg()?))
            }
            Sbp::MsgFileioReadResp(msg) => Ok(Sbp::MsgFileioReadResp(msg.into_valid_msg()?)),
            Sbp::MsgSettingsReadReq(msg) => Ok(Sbp::MsgSettingsReadReq(msg.into_valid_msg()?)),
            Sbp::MsgSettingsReadResp(msg) => Ok(Sbp::MsgSettingsReadResp(msg.into_valid_msg()?)),
            Sbp::MsgSettingsReadByIndexDone(msg) => {
                Ok(Sbp::MsgSettingsReadByIndexDone(msg.into_valid_msg()?))
            }
            Sbp::MsgSettingsReadByIndexResp(msg) => {
                Ok(Sbp::MsgSettingsReadByIndexResp(msg.into_valid_msg()?))
            }
            Sbp::MsgFileioReadReq(msg) => Ok(Sbp::MsgFileioReadReq(msg.into_valid_msg()?)),
            Sbp::MsgFileioReadDirReq(msg) => Ok(Sbp::MsgFileioReadDirReq(msg.into_valid_msg()?)),
            Sbp::MsgFileioReadDirResp(msg) => Ok(Sbp::MsgFileioReadDirResp(msg.into_valid_msg()?)),
            Sbp::MsgFileioWriteResp(msg) => Ok(Sbp::MsgFileioWriteResp(msg.into_valid_msg()?)),
            Sbp::MsgFileioRemove(msg) => Ok(Sbp::MsgFileioRemove(msg.into_valid_msg()?)),
            Sbp::MsgFileioWriteReq(msg) => Ok(Sbp::MsgFileioWriteReq(msg.into_valid_msg()?)),
            Sbp::MsgSettingsRegister(msg) => Ok(Sbp::MsgSettingsRegister(msg.into_valid_msg()?)),
            Sbp::MsgSettingsWriteResp(msg) => Ok(Sbp::MsgSettingsWriteResp(msg.into_valid_msg()?)),
            Sbp::MsgBootloaderHandshakeDepA(msg) => {
                Ok(Sbp::MsgBootloaderHandshakeDepA(msg.into_valid_msg()?))
            }
            Sbp::MsgBootloaderJumpToApp(msg) => {
                Ok(Sbp::MsgBootloaderJumpToApp(msg.into_valid_msg()?))
            }
            Sbp::MsgResetDep(msg) => Ok(Sbp::MsgResetDep(msg.into_valid_msg()?)),
            Sbp::MsgBootloaderHandshakeReq(msg) => {
                Ok(Sbp::MsgBootloaderHandshakeReq(msg.into_valid_msg()?))
            }
            Sbp::MsgBootloaderHandshakeResp(msg) => {
                Ok(Sbp::MsgBootloaderHandshakeResp(msg.into_valid_msg()?))
            }
            Sbp::MsgDeviceMonitor(msg) => Ok(Sbp::MsgDeviceMonitor(msg.into_valid_msg()?)),
            Sbp::MsgReset(msg) => Ok(Sbp::MsgReset(msg.into_valid_msg()?)),
            Sbp::MsgCommandReq(msg) => Ok(Sbp::MsgCommandReq(msg.into_valid_msg()?)),
            Sbp::MsgCommandResp(msg) => Ok(Sbp::MsgCommandResp(msg.into_valid_msg()?)),
            Sbp::MsgNetworkStateReq(msg) => Ok(Sbp::MsgNetworkStateReq(msg.into_valid_msg()?)),
            Sbp::MsgNetworkStateResp(msg) => Ok(Sbp::MsgNetworkStateResp(msg.into_valid_msg()?)),
            Sbp::MsgCommandOutput(msg) => Ok(Sbp::MsgCommandOutput(msg.into_valid_msg()?)),
            Sbp::MsgNetworkBandwidthUsage(msg) => {
                Ok(Sbp::MsgNetworkBandwidthUsage(msg.into_valid_msg()?))
            }
            Sbp::MsgCellModemStatus(msg) => Ok(Sbp::MsgCellModemStatus(msg.into_valid_msg()?)),
            Sbp::MsgFrontEndGain(msg) => Ok(Sbp::MsgFrontEndGain(msg.into_valid_msg()?)),
            Sbp::MsgCwResults(msg) => Ok(Sbp::MsgCwResults(msg.into_valid_msg()?)),
            Sbp::MsgCwStart(msg) => Ok(Sbp::MsgCwStart(msg.into_valid_msg()?)),
            Sbp::MsgNapDeviceDnaResp(msg) => Ok(Sbp::MsgNapDeviceDnaResp(msg.into_valid_msg()?)),
            Sbp::MsgNapDeviceDnaReq(msg) => Ok(Sbp::MsgNapDeviceDnaReq(msg.into_valid_msg()?)),
            Sbp::MsgFlashDone(msg) => Ok(Sbp::MsgFlashDone(msg.into_valid_msg()?)),
            Sbp::MsgFlashReadResp(msg) => Ok(Sbp::MsgFlashReadResp(msg.into_valid_msg()?)),
            Sbp::MsgFlashErase(msg) => Ok(Sbp::MsgFlashErase(msg.into_valid_msg()?)),
            Sbp::MsgStmFlashLockSector(msg) => {
                Ok(Sbp::MsgStmFlashLockSector(msg.into_valid_msg()?))
            }
            Sbp::MsgStmFlashUnlockSector(msg) => {
                Ok(Sbp::MsgStmFlashUnlockSector(msg.into_valid_msg()?))
            }
            Sbp::MsgStmUniqueIdResp(msg) => Ok(Sbp::MsgStmUniqueIdResp(msg.into_valid_msg()?)),
            Sbp::MsgFlashProgram(msg) => Ok(Sbp::MsgFlashProgram(msg.into_valid_msg()?)),
            Sbp::MsgFlashReadReq(msg) => Ok(Sbp::MsgFlashReadReq(msg.into_valid_msg()?)),
            Sbp::MsgStmUniqueIdReq(msg) => Ok(Sbp::MsgStmUniqueIdReq(msg.into_valid_msg()?)),
            Sbp::MsgM25FlashWriteStatus(msg) => {
                Ok(Sbp::MsgM25FlashWriteStatus(msg.into_valid_msg()?))
            }
            Sbp::MsgGpsTimeDepA(msg) => Ok(Sbp::MsgGpsTimeDepA(msg.into_valid_msg()?)),
            Sbp::MsgExtEvent(msg) => Ok(Sbp::MsgExtEvent(msg.into_valid_msg()?)),
            Sbp::MsgGpsTime(msg) => Ok(Sbp::MsgGpsTime(msg.into_valid_msg()?)),
            Sbp::MsgUtcTime(msg) => Ok(Sbp::MsgUtcTime(msg.into_valid_msg()?)),
            Sbp::MsgGpsTimeGnss(msg) => Ok(Sbp::MsgGpsTimeGnss(msg.into_valid_msg()?)),
            Sbp::MsgUtcTimeGnss(msg) => Ok(Sbp::MsgUtcTimeGnss(msg.into_valid_msg()?)),
            Sbp::MsgTelSv(msg) => Ok(Sbp::MsgTelSv(msg.into_valid_msg()?)),
            Sbp::MsgSettingsRegisterResp(msg) => {
                Ok(Sbp::MsgSettingsRegisterResp(msg.into_valid_msg()?))
            }
            Sbp::MsgPosEcefDepA(msg) => Ok(Sbp::MsgPosEcefDepA(msg.into_valid_msg()?)),
            Sbp::MsgPosLlhDepA(msg) => Ok(Sbp::MsgPosLlhDepA(msg.into_valid_msg()?)),
            Sbp::MsgBaselineEcefDepA(msg) => Ok(Sbp::MsgBaselineEcefDepA(msg.into_valid_msg()?)),
            Sbp::MsgBaselineNedDepA(msg) => Ok(Sbp::MsgBaselineNedDepA(msg.into_valid_msg()?)),
            Sbp::MsgVelEcefDepA(msg) => Ok(Sbp::MsgVelEcefDepA(msg.into_valid_msg()?)),
            Sbp::MsgVelNedDepA(msg) => Ok(Sbp::MsgVelNedDepA(msg.into_valid_msg()?)),
            Sbp::MsgDopsDepA(msg) => Ok(Sbp::MsgDopsDepA(msg.into_valid_msg()?)),
            Sbp::MsgBaselineHeadingDepA(msg) => {
                Ok(Sbp::MsgBaselineHeadingDepA(msg.into_valid_msg()?))
            }
            Sbp::MsgDops(msg) => Ok(Sbp::MsgDops(msg.into_valid_msg()?)),
            Sbp::MsgPosEcef(msg) => Ok(Sbp::MsgPosEcef(msg.into_valid_msg()?)),
            Sbp::MsgPosLlh(msg) => Ok(Sbp::MsgPosLlh(msg.into_valid_msg()?)),
            Sbp::MsgBaselineEcef(msg) => Ok(Sbp::MsgBaselineEcef(msg.into_valid_msg()?)),
            Sbp::MsgBaselineNed(msg) => Ok(Sbp::MsgBaselineNed(msg.into_valid_msg()?)),
            Sbp::MsgVelEcef(msg) => Ok(Sbp::MsgVelEcef(msg.into_valid_msg()?)),
            Sbp::MsgVelNed(msg) => Ok(Sbp::MsgVelNed(msg.into_valid_msg()?)),
            Sbp::MsgBaselineHeading(msg) => Ok(Sbp::MsgBaselineHeading(msg.into_valid_msg()?)),
            Sbp::MsgAgeCorrections(msg) => Ok(Sbp::MsgAgeCorrections(msg.into_valid_msg()?)),
            Sbp::MsgPosLlhCov(msg) => Ok(Sbp::MsgPosLlhCov(msg.into_valid_msg()?)),
            Sbp::MsgVelNedCov(msg) => Ok(Sbp::MsgVelNedCov(msg.into_valid_msg()?)),
            Sbp::MsgVelBody(msg) => Ok(Sbp::MsgVelBody(msg.into_valid_msg()?)),
            Sbp::MsgPosEcefCov(msg) => Ok(Sbp::MsgPosEcefCov(msg.into_valid_msg()?)),
            Sbp::MsgVelEcefCov(msg) => Ok(Sbp::MsgVelEcefCov(msg.into_valid_msg()?)),
            Sbp::MsgProtectionLevelDepA(msg) => {
                Ok(Sbp::MsgProtectionLevelDepA(msg.into_valid_msg()?))
            }
            Sbp::MsgProtectionLevel(msg) => Ok(Sbp::MsgProtectionLevel(msg.into_valid_msg()?)),
            Sbp::MsgPosLlhAcc(msg) => Ok(Sbp::MsgPosLlhAcc(msg.into_valid_msg()?)),
            Sbp::MsgVelCog(msg) => Ok(Sbp::MsgVelCog(msg.into_valid_msg()?)),
            Sbp::MsgOrientQuat(msg) => Ok(Sbp::MsgOrientQuat(msg.into_valid_msg()?)),
            Sbp::MsgOrientEuler(msg) => Ok(Sbp::MsgOrientEuler(msg.into_valid_msg()?)),
            Sbp::MsgAngularRate(msg) => Ok(Sbp::MsgAngularRate(msg.into_valid_msg()?)),
            Sbp::MsgPosEcefGnss(msg) => Ok(Sbp::MsgPosEcefGnss(msg.into_valid_msg()?)),
            Sbp::MsgPosLlhGnss(msg) => Ok(Sbp::MsgPosLlhGnss(msg.into_valid_msg()?)),
            Sbp::MsgVelEcefGnss(msg) => Ok(Sbp::MsgVelEcefGnss(msg.into_valid_msg()?)),
            Sbp::MsgVelNedGnss(msg) => Ok(Sbp::MsgVelNedGnss(msg.into_valid_msg()?)),
            Sbp::MsgPosLlhCovGnss(msg) => Ok(Sbp::MsgPosLlhCovGnss(msg.into_valid_msg()?)),
            Sbp::MsgVelNedCovGnss(msg) => Ok(Sbp::MsgVelNedCovGnss(msg.into_valid_msg()?)),
            Sbp::MsgPosEcefCovGnss(msg) => Ok(Sbp::MsgPosEcefCovGnss(msg.into_valid_msg()?)),
            Sbp::MsgVelEcefCovGnss(msg) => Ok(Sbp::MsgVelEcefCovGnss(msg.into_valid_msg()?)),
            Sbp::MsgUtcLeapSecond(msg) => Ok(Sbp::MsgUtcLeapSecond(msg.into_valid_msg()?)),
            Sbp::MsgReferenceFrameParam(msg) => {
                Ok(Sbp::MsgReferenceFrameParam(msg.into_valid_msg()?))
            }
            Sbp::MsgPoseRelative(msg) => Ok(Sbp::MsgPoseRelative(msg.into_valid_msg()?)),
            Sbp::MsgNdbEvent(msg) => Ok(Sbp::MsgNdbEvent(msg.into_valid_msg()?)),
            Sbp::MsgLog(msg) => Ok(Sbp::MsgLog(msg.into_valid_msg()?)),
            Sbp::MsgFwd(msg) => Ok(Sbp::MsgFwd(msg.into_valid_msg()?)),
            Sbp::MsgSsrOrbitClockDepA(msg) => Ok(Sbp::MsgSsrOrbitClockDepA(msg.into_valid_msg()?)),
            Sbp::MsgSsrOrbitClock(msg) => Ok(Sbp::MsgSsrOrbitClock(msg.into_valid_msg()?)),
            Sbp::MsgSsrOrbitClockBounds(msg) => {
                Ok(Sbp::MsgSsrOrbitClockBounds(msg.into_valid_msg()?))
            }
            Sbp::MsgSsrOrbitClockBoundsDegradation(msg) => Ok(
                Sbp::MsgSsrOrbitClockBoundsDegradation(msg.into_valid_msg()?),
            ),
            Sbp::MsgSsrCodeBiases(msg) => Ok(Sbp::MsgSsrCodeBiases(msg.into_valid_msg()?)),
            Sbp::MsgSsrPhaseBiases(msg) => Ok(Sbp::MsgSsrPhaseBiases(msg.into_valid_msg()?)),
            Sbp::MsgSsrStecCorrectionDepA(msg) => {
                Ok(Sbp::MsgSsrStecCorrectionDepA(msg.into_valid_msg()?))
            }
            Sbp::MsgSsrCodePhaseBiasesBounds(msg) => {
                Ok(Sbp::MsgSsrCodePhaseBiasesBounds(msg.into_valid_msg()?))
            }
            Sbp::MsgSsrGriddedCorrectionNoStdDepA(msg) => {
                Ok(Sbp::MsgSsrGriddedCorrectionNoStdDepA(msg.into_valid_msg()?))
            }
            Sbp::MsgSsrGridDefinitionDepA(msg) => {
                Ok(Sbp::MsgSsrGridDefinitionDepA(msg.into_valid_msg()?))
            }
            Sbp::MsgSsrTileDefinitionDepA(msg) => {
                Ok(Sbp::MsgSsrTileDefinitionDepA(msg.into_valid_msg()?))
            }
            Sbp::MsgSsrTileDefinitionDepB(msg) => {
                Ok(Sbp::MsgSsrTileDefinitionDepB(msg.into_valid_msg()?))
            }
            Sbp::MsgSsrTileDefinition(msg) => Ok(Sbp::MsgSsrTileDefinition(msg.into_valid_msg()?)),
            Sbp::MsgSsrGriddedCorrectionDepA(msg) => {
                Ok(Sbp::MsgSsrGriddedCorrectionDepA(msg.into_valid_msg()?))
            }
            Sbp::MsgSsrStecCorrectionDep(msg) => {
                Ok(Sbp::MsgSsrStecCorrectionDep(msg.into_valid_msg()?))
            }
            Sbp::MsgSsrGriddedCorrection(msg) => {
                Ok(Sbp::MsgSsrGriddedCorrection(msg.into_valid_msg()?))
            }
            Sbp::MsgSsrStecCorrection(msg) => Ok(Sbp::MsgSsrStecCorrection(msg.into_valid_msg()?)),
            Sbp::MsgSsrGriddedCorrectionBounds(msg) => {
                Ok(Sbp::MsgSsrGriddedCorrectionBounds(msg.into_valid_msg()?))
            }
            Sbp::MsgSsrSatelliteApcDep(msg) => {
                Ok(Sbp::MsgSsrSatelliteApcDep(msg.into_valid_msg()?))
            }
            Sbp::MsgSsrSatelliteApc(msg) => Ok(Sbp::MsgSsrSatelliteApc(msg.into_valid_msg()?)),
            Sbp::MsgOsr(msg) => Ok(Sbp::MsgOsr(msg.into_valid_msg()?)),
            Sbp::MsgUserData(msg) => Ok(Sbp::MsgUserData(msg.into_valid_msg()?)),
            Sbp::MsgImuRaw(msg) => Ok(Sbp::MsgImuRaw(msg.into_valid_msg()?)),
            Sbp::MsgImuAux(msg) => Ok(Sbp::MsgImuAux(msg.into_valid_msg()?)),
            Sbp::MsgMagRaw(msg) => Ok(Sbp::MsgMagRaw(msg.into_valid_msg()?)),
            Sbp::MsgOdometry(msg) => Ok(Sbp::MsgOdometry(msg.into_valid_msg()?)),
            Sbp::MsgWheeltick(msg) => Ok(Sbp::MsgWheeltick(msg.into_valid_msg()?)),
            Sbp::MsgSsrFlagHighLevel(msg) => Ok(Sbp::MsgSsrFlagHighLevel(msg.into_valid_msg()?)),
            Sbp::MsgSsrFlagSatellites(msg) => Ok(Sbp::MsgSsrFlagSatellites(msg.into_valid_msg()?)),
            Sbp::MsgSsrFlagTropoGridPoints(msg) => {
                Ok(Sbp::MsgSsrFlagTropoGridPoints(msg.into_valid_msg()?))
            }
            Sbp::MsgSsrFlagIonoGridPoints(msg) => {
                Ok(Sbp::MsgSsrFlagIonoGridPoints(msg.into_valid_msg()?))
            }
            Sbp::MsgSsrFlagIonoTileSatLos(msg) => {
                Ok(Sbp::MsgSsrFlagIonoTileSatLos(msg.into_valid_msg()?))
            }
            Sbp::MsgSsrFlagIonoGridPointSatLos(msg) => {
                Ok(Sbp::MsgSsrFlagIonoGridPointSatLos(msg.into_valid_msg()?))
            }
            Sbp::MsgAcknowledge(msg) => Ok(Sbp::MsgAcknowledge(msg.into_valid_msg()?)),
            Sbp::MsgEd25519SignatureDepA(msg) => {
                Ok(Sbp::MsgEd25519SignatureDepA(msg.into_valid_msg()?))
            }
            Sbp::MsgEd25519CertificateDep(msg) => {
                Ok(Sbp::MsgEd25519CertificateDep(msg.into_valid_msg()?))
            }
            Sbp::MsgEd25519SignatureDepB(msg) => {
                Ok(Sbp::MsgEd25519SignatureDepB(msg.into_valid_msg()?))
            }
            Sbp::MsgEcdsaCertificate(msg) => Ok(Sbp::MsgEcdsaCertificate(msg.into_valid_msg()?)),
            Sbp::MsgCertificateChainDep(msg) => {
                Ok(Sbp::MsgCertificateChainDep(msg.into_valid_msg()?))
            }
            Sbp::MsgEcdsaSignatureDepA(msg) => {
                Ok(Sbp::MsgEcdsaSignatureDepA(msg.into_valid_msg()?))
            }
            Sbp::MsgEcdsaSignatureDepB(msg) => {
                Ok(Sbp::MsgEcdsaSignatureDepB(msg.into_valid_msg()?))
            }
            Sbp::MsgEcdsaSignature(msg) => Ok(Sbp::MsgEcdsaSignature(msg.into_valid_msg()?)),
            Sbp::MsgCertificateChain(msg) => Ok(Sbp::MsgCertificateChain(msg.into_valid_msg()?)),
            Sbp::MsgFileioConfigReq(msg) => Ok(Sbp::MsgFileioConfigReq(msg.into_valid_msg()?)),
            Sbp::MsgFileioConfigResp(msg) => Ok(Sbp::MsgFileioConfigResp(msg.into_valid_msg()?)),
            Sbp::MsgSbasRaw(msg) => Ok(Sbp::MsgSbasRaw(msg.into_valid_msg()?)),
            Sbp::MsgLinuxCpuStateDepA(msg) => Ok(Sbp::MsgLinuxCpuStateDepA(msg.into_valid_msg()?)),
            Sbp::MsgLinuxMemStateDepA(msg) => Ok(Sbp::MsgLinuxMemStateDepA(msg.into_valid_msg()?)),
            Sbp::MsgLinuxSysStateDepA(msg) => Ok(Sbp::MsgLinuxSysStateDepA(msg.into_valid_msg()?)),
            Sbp::MsgLinuxProcessSocketCounts(msg) => {
                Ok(Sbp::MsgLinuxProcessSocketCounts(msg.into_valid_msg()?))
            }
            Sbp::MsgLinuxProcessSocketQueues(msg) => {
                Ok(Sbp::MsgLinuxProcessSocketQueues(msg.into_valid_msg()?))
            }
            Sbp::MsgLinuxSocketUsage(msg) => Ok(Sbp::MsgLinuxSocketUsage(msg.into_valid_msg()?)),
            Sbp::MsgLinuxProcessFdCount(msg) => {
                Ok(Sbp::MsgLinuxProcessFdCount(msg.into_valid_msg()?))
            }
            Sbp::MsgLinuxProcessFdSummary(msg) => {
                Ok(Sbp::MsgLinuxProcessFdSummary(msg.into_valid_msg()?))
            }
            Sbp::MsgLinuxCpuState(msg) => Ok(Sbp::MsgLinuxCpuState(msg.into_valid_msg()?)),
            Sbp::MsgLinuxMemState(msg) => Ok(Sbp::MsgLinuxMemState(msg.into_valid_msg()?)),
            Sbp::MsgLinuxSysState(msg) => Ok(Sbp::MsgLinuxSysState(msg.into_valid_msg()?)),
            Sbp::MsgMeasurementPoint(msg) => Ok(Sbp::MsgMeasurementPoint(msg.into_valid_msg()?)),
            Sbp::MsgProfilingSystemInfo(msg) => {
                Ok(Sbp::MsgProfilingSystemInfo(msg.into_valid_msg()?))
            }
            Sbp::MsgProfilingThreadInfo(msg) => {
                Ok(Sbp::MsgProfilingThreadInfo(msg.into_valid_msg()?))
            }
            Sbp::MsgProfilingResourceCounter(msg) => {
                Ok(Sbp::MsgProfilingResourceCounter(msg.into_valid_msg()?))
            }
            Sbp::MsgStartup(msg) => Ok(Sbp::MsgStartup(msg.into_valid_msg()?)),
            Sbp::MsgDgnssStatus(msg) => Ok(Sbp::MsgDgnssStatus(msg.into_valid_msg()?)),
            Sbp::MsgInsStatus(msg) => Ok(Sbp::MsgInsStatus(msg.into_valid_msg()?)),
            Sbp::MsgCsacTelemetry(msg) => Ok(Sbp::MsgCsacTelemetry(msg.into_valid_msg()?)),
            Sbp::MsgCsacTelemetryLabels(msg) => {
                Ok(Sbp::MsgCsacTelemetryLabels(msg.into_valid_msg()?))
            }
            Sbp::MsgInsUpdates(msg) => Ok(Sbp::MsgInsUpdates(msg.into_valid_msg()?)),
            Sbp::MsgGnssTimeOffset(msg) => Ok(Sbp::MsgGnssTimeOffset(msg.into_valid_msg()?)),
            Sbp::MsgPpsTime(msg) => Ok(Sbp::MsgPpsTime(msg.into_valid_msg()?)),
            Sbp::MsgSensorAidEvent(msg) => Ok(Sbp::MsgSensorAidEvent(msg.into_valid_msg()?)),
            Sbp::MsgGroupMeta(msg) => Ok(Sbp::MsgGroupMeta(msg.into_valid_msg()?)),
            Sbp::MsgSolnMeta(msg) => Ok(Sbp::MsgSolnMeta(msg.into_valid_msg()?)),
            Sbp::MsgSolnMetaDepA(msg) => Ok(Sbp::MsgSolnMetaDepA(msg.into_valid_msg()?)),
            Sbp::MsgStatusJournal(msg) => Ok(Sbp::MsgStatusJournal(msg.into_valid_msg()?)),
            Sbp::MsgStatusReport(msg) => Ok(Sbp::MsgStatusReport(msg.into_valid_msg()?)),
            Sbp::MsgHeartbeat(msg) => Ok(Sbp::MsgHeartbeat(msg.into_valid_msg()?)),
            Sbp::Unknown(msg) => Ok(Sbp::Unknown(msg.into_valid_msg()?)),
            Sbp::Invalid(msg) => {
                // should never pass
                let res = msg.into_valid_msg();
                debug_assert!(res.is_err(), "invalid messages may never be valid");
                Ok(Sbp::Invalid(res?))
            }
        }
    }
}

impl WireFormat for Sbp {
    const MIN_LEN: usize = crate::MAX_FRAME_LEN;

    fn parse_unchecked<B: Buf>(_: &mut B) -> Self {
        unimplemented!("Sbp must be parsed with Sbp::from_parts");
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
            Sbp::MsgTelSv(msg) => WireFormat::write(msg, buf),
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
            Sbp::MsgPoseRelative(msg) => WireFormat::write(msg, buf),
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
            Sbp::MsgSsrTileDefinitionDepA(msg) => WireFormat::write(msg, buf),
            Sbp::MsgSsrTileDefinitionDepB(msg) => WireFormat::write(msg, buf),
            Sbp::MsgSsrTileDefinition(msg) => WireFormat::write(msg, buf),
            Sbp::MsgSsrGriddedCorrectionDepA(msg) => WireFormat::write(msg, buf),
            Sbp::MsgSsrStecCorrectionDep(msg) => WireFormat::write(msg, buf),
            Sbp::MsgSsrGriddedCorrection(msg) => WireFormat::write(msg, buf),
            Sbp::MsgSsrStecCorrection(msg) => WireFormat::write(msg, buf),
            Sbp::MsgSsrGriddedCorrectionBounds(msg) => WireFormat::write(msg, buf),
            Sbp::MsgSsrSatelliteApcDep(msg) => WireFormat::write(msg, buf),
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
            Sbp::MsgAcknowledge(msg) => WireFormat::write(msg, buf),
            Sbp::MsgEd25519SignatureDepA(msg) => WireFormat::write(msg, buf),
            Sbp::MsgEd25519CertificateDep(msg) => WireFormat::write(msg, buf),
            Sbp::MsgEd25519SignatureDepB(msg) => WireFormat::write(msg, buf),
            Sbp::MsgEcdsaCertificate(msg) => WireFormat::write(msg, buf),
            Sbp::MsgCertificateChainDep(msg) => WireFormat::write(msg, buf),
            Sbp::MsgEcdsaSignatureDepA(msg) => WireFormat::write(msg, buf),
            Sbp::MsgEcdsaSignatureDepB(msg) => WireFormat::write(msg, buf),
            Sbp::MsgEcdsaSignature(msg) => WireFormat::write(msg, buf),
            Sbp::MsgCertificateChain(msg) => WireFormat::write(msg, buf),
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
            Sbp::MsgMeasurementPoint(msg) => WireFormat::write(msg, buf),
            Sbp::MsgProfilingSystemInfo(msg) => WireFormat::write(msg, buf),
            Sbp::MsgProfilingThreadInfo(msg) => WireFormat::write(msg, buf),
            Sbp::MsgProfilingResourceCounter(msg) => WireFormat::write(msg, buf),
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
            Sbp::Invalid(msg) => WireFormat::write(msg, buf),
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
            Sbp::MsgTelSv(msg) => WireFormat::len(msg),
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
            Sbp::MsgPoseRelative(msg) => WireFormat::len(msg),
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
            Sbp::MsgSsrTileDefinitionDepA(msg) => WireFormat::len(msg),
            Sbp::MsgSsrTileDefinitionDepB(msg) => WireFormat::len(msg),
            Sbp::MsgSsrTileDefinition(msg) => WireFormat::len(msg),
            Sbp::MsgSsrGriddedCorrectionDepA(msg) => WireFormat::len(msg),
            Sbp::MsgSsrStecCorrectionDep(msg) => WireFormat::len(msg),
            Sbp::MsgSsrGriddedCorrection(msg) => WireFormat::len(msg),
            Sbp::MsgSsrStecCorrection(msg) => WireFormat::len(msg),
            Sbp::MsgSsrGriddedCorrectionBounds(msg) => WireFormat::len(msg),
            Sbp::MsgSsrSatelliteApcDep(msg) => WireFormat::len(msg),
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
            Sbp::MsgAcknowledge(msg) => WireFormat::len(msg),
            Sbp::MsgEd25519SignatureDepA(msg) => WireFormat::len(msg),
            Sbp::MsgEd25519CertificateDep(msg) => WireFormat::len(msg),
            Sbp::MsgEd25519SignatureDepB(msg) => WireFormat::len(msg),
            Sbp::MsgEcdsaCertificate(msg) => WireFormat::len(msg),
            Sbp::MsgCertificateChainDep(msg) => WireFormat::len(msg),
            Sbp::MsgEcdsaSignatureDepA(msg) => WireFormat::len(msg),
            Sbp::MsgEcdsaSignatureDepB(msg) => WireFormat::len(msg),
            Sbp::MsgEcdsaSignature(msg) => WireFormat::len(msg),
            Sbp::MsgCertificateChain(msg) => WireFormat::len(msg),
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
            Sbp::MsgMeasurementPoint(msg) => WireFormat::len(msg),
            Sbp::MsgProfilingSystemInfo(msg) => WireFormat::len(msg),
            Sbp::MsgProfilingThreadInfo(msg) => WireFormat::len(msg),
            Sbp::MsgProfilingResourceCounter(msg) => WireFormat::len(msg),
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
            Sbp::Invalid(msg) => WireFormat::len(msg),
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

impl From<MsgTelSv> for Sbp {
    fn from(msg: MsgTelSv) -> Self {
        Sbp::MsgTelSv(msg)
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

impl From<MsgPoseRelative> for Sbp {
    fn from(msg: MsgPoseRelative) -> Self {
        Sbp::MsgPoseRelative(msg)
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

impl From<MsgSsrTileDefinitionDepA> for Sbp {
    fn from(msg: MsgSsrTileDefinitionDepA) -> Self {
        Sbp::MsgSsrTileDefinitionDepA(msg)
    }
}

impl From<MsgSsrTileDefinitionDepB> for Sbp {
    fn from(msg: MsgSsrTileDefinitionDepB) -> Self {
        Sbp::MsgSsrTileDefinitionDepB(msg)
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

impl From<MsgSsrSatelliteApcDep> for Sbp {
    fn from(msg: MsgSsrSatelliteApcDep) -> Self {
        Sbp::MsgSsrSatelliteApcDep(msg)
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

impl From<MsgAcknowledge> for Sbp {
    fn from(msg: MsgAcknowledge) -> Self {
        Sbp::MsgAcknowledge(msg)
    }
}

impl From<MsgEd25519SignatureDepA> for Sbp {
    fn from(msg: MsgEd25519SignatureDepA) -> Self {
        Sbp::MsgEd25519SignatureDepA(msg)
    }
}

impl From<MsgEd25519CertificateDep> for Sbp {
    fn from(msg: MsgEd25519CertificateDep) -> Self {
        Sbp::MsgEd25519CertificateDep(msg)
    }
}

impl From<MsgEd25519SignatureDepB> for Sbp {
    fn from(msg: MsgEd25519SignatureDepB) -> Self {
        Sbp::MsgEd25519SignatureDepB(msg)
    }
}

impl From<MsgEcdsaCertificate> for Sbp {
    fn from(msg: MsgEcdsaCertificate) -> Self {
        Sbp::MsgEcdsaCertificate(msg)
    }
}

impl From<MsgCertificateChainDep> for Sbp {
    fn from(msg: MsgCertificateChainDep) -> Self {
        Sbp::MsgCertificateChainDep(msg)
    }
}

impl From<MsgEcdsaSignatureDepA> for Sbp {
    fn from(msg: MsgEcdsaSignatureDepA) -> Self {
        Sbp::MsgEcdsaSignatureDepA(msg)
    }
}

impl From<MsgEcdsaSignatureDepB> for Sbp {
    fn from(msg: MsgEcdsaSignatureDepB) -> Self {
        Sbp::MsgEcdsaSignatureDepB(msg)
    }
}

impl From<MsgEcdsaSignature> for Sbp {
    fn from(msg: MsgEcdsaSignature) -> Self {
        Sbp::MsgEcdsaSignature(msg)
    }
}

impl From<MsgCertificateChain> for Sbp {
    fn from(msg: MsgCertificateChain) -> Self {
        Sbp::MsgCertificateChain(msg)
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

impl From<MsgMeasurementPoint> for Sbp {
    fn from(msg: MsgMeasurementPoint) -> Self {
        Sbp::MsgMeasurementPoint(msg)
    }
}

impl From<MsgProfilingSystemInfo> for Sbp {
    fn from(msg: MsgProfilingSystemInfo) -> Self {
        Sbp::MsgProfilingSystemInfo(msg)
    }
}

impl From<MsgProfilingThreadInfo> for Sbp {
    fn from(msg: MsgProfilingThreadInfo) -> Self {
        Sbp::MsgProfilingThreadInfo(msg)
    }
}

impl From<MsgProfilingResourceCounter> for Sbp {
    fn from(msg: MsgProfilingResourceCounter) -> Self {
        Sbp::MsgProfilingResourceCounter(msg)
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
impl From<Invalid> for Sbp {
    fn from(msg: Invalid) -> Self {
        Sbp::Invalid(msg)
    }
}
