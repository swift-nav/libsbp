//
// Copyright (C) 2019-2021 Swift Navigation Inc.
// Contact: https://support.swiftnav.com
//
// This source is subject to the license found in the file 'LICENSE' which must
// be be distributed together with this source. All other rights reserved.
//
// THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
// EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
// WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.

// This file was auto-generated. Do not modify by hand!
mod auto_check_sbp_acquisition_msg_acq_result_dep_a;
mod auto_check_sbp_acquisition_msg_acq_result_dep_b;
mod auto_check_sbp_acquisition_msg_acq_result_dep_c;
mod auto_check_sbp_bootload_msg_bootloader_handshake_resp;
mod auto_check_sbp_ext_events_msg_ext_event;
mod auto_check_sbp_file_io_msg_fileio_write_resp;
mod auto_check_sbp_imu_msg_imu_aux;
mod auto_check_sbp_imu_msg_imu_raw;
mod auto_check_sbp_logging_msg_fwd;
mod auto_check_sbp_logging_msg_log;
mod auto_check_sbp_logging_msg_print_dep;
mod auto_check_sbp_navigation_msg_age_corrections;
mod auto_check_sbp_navigation_msg_baseline_ecef;
mod auto_check_sbp_navigation_msg_baseline_ecef_dep_a;
mod auto_check_sbp_navigation_msg_baseline_ned;
mod auto_check_sbp_navigation_msg_baseline_ned_dep_a;
mod auto_check_sbp_navigation_msg_dops;
mod auto_check_sbp_navigation_msg_dops_dep_a;
mod auto_check_sbp_navigation_msg_gps_time;
mod auto_check_sbp_navigation_msg_gps_time_dep_a;
mod auto_check_sbp_navigation_msg_gps_time_gnss;
mod auto_check_sbp_navigation_msg_pos_ecef;
mod auto_check_sbp_navigation_msg_pos_ecef_cov;
mod auto_check_sbp_navigation_msg_pos_ecef_cov_gnss;
mod auto_check_sbp_navigation_msg_pos_ecef_dep_a;
mod auto_check_sbp_navigation_msg_pos_ecefgnss;
mod auto_check_sbp_navigation_msg_pos_llh;
mod auto_check_sbp_navigation_msg_pos_llh_cov;
mod auto_check_sbp_navigation_msg_pos_llh_cov_gnss;
mod auto_check_sbp_navigation_msg_pos_llh_dep_a;
mod auto_check_sbp_navigation_msg_pos_llh_gnss;
mod auto_check_sbp_navigation_msg_protection_level;
mod auto_check_sbp_navigation_msg_utc_time;
mod auto_check_sbp_navigation_msg_utc_time_gnss;
mod auto_check_sbp_navigation_msg_vel_body;
mod auto_check_sbp_navigation_msg_vel_cog;
mod auto_check_sbp_navigation_msg_vel_ecef;
mod auto_check_sbp_navigation_msg_vel_ecef_cov;
mod auto_check_sbp_navigation_msg_vel_ecef_cov_gnss;
mod auto_check_sbp_navigation_msg_vel_ecef_dep_a;
mod auto_check_sbp_navigation_msg_vel_ecef_gnss;
mod auto_check_sbp_navigation_msg_vel_ned;
mod auto_check_sbp_navigation_msg_vel_ned_cov_gnss;
mod auto_check_sbp_navigation_msg_vel_ned_dep_a;
mod auto_check_sbp_navigation_msg_vel_ned_gnss;
mod auto_check_sbp_navigation_msg_vel_nedcov;
mod auto_check_sbp_observation_msg_base_pos_ecef;
mod auto_check_sbp_observation_msg_ephemeris_bds;
mod auto_check_sbp_observation_msg_ephemeris_dep_b;
mod auto_check_sbp_observation_msg_ephemeris_gal;
mod auto_check_sbp_observation_msg_ephemeris_glo;
mod auto_check_sbp_observation_msg_ephemeris_gps;
mod auto_check_sbp_observation_msg_ephemeris_qzss;
mod auto_check_sbp_observation_msg_glo_biases;
mod auto_check_sbp_observation_msg_obs;
mod auto_check_sbp_observation_msg_obs_dep_a;
mod auto_check_sbp_observation_msg_obs_dep_b;
mod auto_check_sbp_observation_msg_obs_dep_c;
mod auto_check_sbp_observation_msg_osr;
mod auto_check_sbp_observation_msg_sv_az_el;
mod auto_check_sbp_orientation_msg_angular_rate;
mod auto_check_sbp_orientation_msg_orient_euler;
mod auto_check_sbp_orientation_msg_orient_quat;
mod auto_check_sbp_piksi_msg_device_monitor;
mod auto_check_sbp_piksi_msg_iar_state;
mod auto_check_sbp_piksi_msg_network_bandwidth_usage;
mod auto_check_sbp_piksi_msg_thread_state;
mod auto_check_sbp_piksi_msg_uart_state;
mod auto_check_sbp_piksi_msg_uart_state_dep_a;
mod auto_check_sbp_sbas_msg_sbas_raw;
mod auto_check_sbp_settings_msg_settings_read_by_index_done;
mod auto_check_sbp_settings_msg_settings_read_by_index_resp;
mod auto_check_sbp_system_msg_dgnss_status;
mod auto_check_sbp_system_msg_group_meta;
mod auto_check_sbp_system_msg_heartbeat;
mod auto_check_sbp_system_msg_ins_status;
mod auto_check_sbp_system_msg_ins_updates;
mod auto_check_sbp_system_msg_startup;
mod auto_check_sbp_tracking_msg_measurement_state;
mod auto_check_sbp_tracking_msg_tracking_state;
mod auto_check_sbp_tracking_msg_tracking_state_detailed_dep;
mod auto_check_sbp_tracking_msgtracking_state_dep_a;
mod auto_check_sbp_vehicle_msg_odometry;

pub use std::io::Cursor;

pub use sbp::iter_messages;
pub use sbp::messages::SbpMessage;

pub trait AlmostEq {
    fn almost_eq(self, rhs: Self) -> bool;
}

impl AlmostEq for f32 {
    fn almost_eq(self, rhs: Self) -> bool {
        const ULP: f32 = 5.0;
        ((self - rhs).abs() <= (std::f32::EPSILON * (self + rhs).abs() * ULP))
            || ((self - rhs).abs() < std::f32::MIN)
    }
}

impl AlmostEq for f64 {
    fn almost_eq(self, rhs: Self) -> bool {
        const ULP: f64 = 5.0;
        ((self - rhs).abs() <= (std::f64::EPSILON * (self + rhs).abs() * ULP))
            || ((self - rhs).abs() < std::f64::MIN)
    }
}
