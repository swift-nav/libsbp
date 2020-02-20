/**
 * Copyright (C) 2019 Swift Navigation Inc.
 * Contact: Swift Navigation <dev@swiftnav.com>
 *
 * This source is subject to the license found in the file 'LICENSE' which must
 * be be distributed together with this source. All other rights reserved.
 *
 * THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
 * EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
 */

#ifndef SBP_CPP_MESSAGE_TRAITS_H
#define SBP_CPP_MESSAGE_TRAITS_H
#include <libsbp/acquisition.h>
#include <libsbp/bootload.h>
#include <libsbp/ext_events.h>
#include <libsbp/file_io.h>
#include <libsbp/flash.h>
#include <libsbp/gnss.h>
#include <libsbp/imu.h>
#include <libsbp/linux.h>
#include <libsbp/logging.h>
#include <libsbp/mag.h>
#include <libsbp/navigation.h>
#include <libsbp/ndb.h>
#include <libsbp/observation.h>
#include <libsbp/orientation.h>
#include <libsbp/piksi.h>
#include <libsbp/sbas.h>
#include <libsbp/settings.h>
#include <libsbp/ssr.h>
#include <libsbp/system.h>
#include <libsbp/tracking.h>
#include <libsbp/user.h>
#include <libsbp/vehicle.h>

namespace sbp {

/**
 * Type traits containing meta-information for each SBP message type.
 *
 * These are only meant to be used by the C++ library at compile time.
 * These are automatically generated, DO NOT EDIT.
 */
template<typename>
struct MessageTraits;


template<>
struct MessageTraits<msg_print_dep_t> {
  static constexpr u16 id = 16;
};


template<>
struct MessageTraits<msg_tracking_state_detailed_dep_t> {
  static constexpr u16 id = 17;
};


template<>
struct MessageTraits<msg_tracking_state_dep_b_t> {
  static constexpr u16 id = 19;
};


template<>
struct MessageTraits<msg_acq_result_dep_b_t> {
  static constexpr u16 id = 20;
};


template<>
struct MessageTraits<msg_acq_result_dep_a_t> {
  static constexpr u16 id = 21;
};


template<>
struct MessageTraits<msg_tracking_state_dep_a_t> {
  static constexpr u16 id = 22;
};


template<>
struct MessageTraits<msg_thread_state_t> {
  static constexpr u16 id = 23;
};


template<>
struct MessageTraits<msg_uart_state_depa_t> {
  static constexpr u16 id = 24;
};


template<>
struct MessageTraits<msg_iar_state_t> {
  static constexpr u16 id = 25;
};


template<>
struct MessageTraits<msg_ephemeris_dep_a_t> {
  static constexpr u16 id = 26;
};


template<>
struct MessageTraits<msg_mask_satellite_dep_t> {
  static constexpr u16 id = 27;
};


template<>
struct MessageTraits<msg_tracking_iq_dep_a_t> {
  static constexpr u16 id = 28;
};


template<>
struct MessageTraits<msg_uart_state_t> {
  static constexpr u16 id = 29;
};


template<>
struct MessageTraits<msg_acq_sv_profile_dep_t> {
  static constexpr u16 id = 30;
};


template<>
struct MessageTraits<msg_acq_result_dep_c_t> {
  static constexpr u16 id = 31;
};


template<>
struct MessageTraits<msg_tracking_state_detailed_dep_a_t> {
  static constexpr u16 id = 33;
};


template<>
struct MessageTraits<msg_reset_filters_t> {
  static constexpr u16 id = 34;
};



template<>
struct MessageTraits<msg_mask_satellite_t> {
  static constexpr u16 id = 43;
};


template<>
struct MessageTraits<msg_tracking_iq_dep_b_t> {
  static constexpr u16 id = 44;
};


template<>
struct MessageTraits<msg_tracking_iq_t> {
  static constexpr u16 id = 45;
};


template<>
struct MessageTraits<msg_acq_sv_profile_t> {
  static constexpr u16 id = 46;
};


template<>
struct MessageTraits<msg_acq_result_t> {
  static constexpr u16 id = 47;
};


template<>
struct MessageTraits<msg_tracking_state_t> {
  static constexpr u16 id = 65;
};


template<>
struct MessageTraits<msg_obs_dep_b_t> {
  static constexpr u16 id = 67;
};


template<>
struct MessageTraits<msg_base_pos_llh_t> {
  static constexpr u16 id = 68;
};


template<>
struct MessageTraits<msg_obs_dep_a_t> {
  static constexpr u16 id = 69;
};


template<>
struct MessageTraits<msg_ephemeris_dep_b_t> {
  static constexpr u16 id = 70;
};


template<>
struct MessageTraits<msg_ephemeris_dep_c_t> {
  static constexpr u16 id = 71;
};


template<>
struct MessageTraits<msg_base_pos_ecef_t> {
  static constexpr u16 id = 72;
};


template<>
struct MessageTraits<msg_obs_dep_c_t> {
  static constexpr u16 id = 73;
};


template<>
struct MessageTraits<msg_obs_t> {
  static constexpr u16 id = 74;
};


template<>
struct MessageTraits<msg_specan_dep_t> {
  static constexpr u16 id = 80;
};


template<>
struct MessageTraits<msg_specan_t> {
  static constexpr u16 id = 81;
};


template<>
struct MessageTraits<msg_measurement_state_t> {
  static constexpr u16 id = 97;
};




template<>
struct MessageTraits<msg_almanac_gps_dep_t> {
  static constexpr u16 id = 112;
};


template<>
struct MessageTraits<msg_almanac_glo_dep_t> {
  static constexpr u16 id = 113;
};


template<>
struct MessageTraits<msg_almanac_gps_t> {
  static constexpr u16 id = 114;
};


template<>
struct MessageTraits<msg_almanac_glo_t> {
  static constexpr u16 id = 115;
};


template<>
struct MessageTraits<msg_glo_biases_t> {
  static constexpr u16 id = 117;
};


template<>
struct MessageTraits<msg_ephemeris_dep_d_t> {
  static constexpr u16 id = 128;
};


template<>
struct MessageTraits<msg_ephemeris_gps_dep_e_t> {
  static constexpr u16 id = 129;
};


template<>
struct MessageTraits<msg_ephemeris_sbas_dep_a_t> {
  static constexpr u16 id = 130;
};


template<>
struct MessageTraits<msg_ephemeris_glo_dep_a_t> {
  static constexpr u16 id = 131;
};


template<>
struct MessageTraits<msg_ephemeris_sbas_dep_b_t> {
  static constexpr u16 id = 132;
};


template<>
struct MessageTraits<msg_ephemeris_glo_dep_b_t> {
  static constexpr u16 id = 133;
};


template<>
struct MessageTraits<msg_ephemeris_gps_dep_f_t> {
  static constexpr u16 id = 134;
};


template<>
struct MessageTraits<msg_ephemeris_glo_dep_c_t> {
  static constexpr u16 id = 135;
};


template<>
struct MessageTraits<msg_ephemeris_glo_dep_d_t> {
  static constexpr u16 id = 136;
};


template<>
struct MessageTraits<msg_ephemeris_bds_t> {
  static constexpr u16 id = 137;
};


template<>
struct MessageTraits<msg_ephemeris_gps_t> {
  static constexpr u16 id = 138;
};


template<>
struct MessageTraits<msg_ephemeris_glo_t> {
  static constexpr u16 id = 139;
};


template<>
struct MessageTraits<msg_ephemeris_sbas_t> {
  static constexpr u16 id = 140;
};


template<>
struct MessageTraits<msg_ephemeris_gal_t> {
  static constexpr u16 id = 141;
};


template<>
struct MessageTraits<msg_ephemeris_qzss_t> {
  static constexpr u16 id = 142;
};


template<>
struct MessageTraits<msg_iono_t> {
  static constexpr u16 id = 144;
};


template<>
struct MessageTraits<msg_sv_configuration_gps_dep_t> {
  static constexpr u16 id = 145;
};


template<>
struct MessageTraits<msg_group_delay_dep_a_t> {
  static constexpr u16 id = 146;
};


template<>
struct MessageTraits<msg_group_delay_dep_b_t> {
  static constexpr u16 id = 147;
};


template<>
struct MessageTraits<msg_group_delay_t> {
  static constexpr u16 id = 148;
};


template<>
struct MessageTraits<msg_ephemeris_gal_dep_a_t> {
  static constexpr u16 id = 149;
};


template<>
struct MessageTraits<msg_gnss_capb_t> {
  static constexpr u16 id = 150;
};


template<>
struct MessageTraits<msg_sv_az_el_t> {
  static constexpr u16 id = 151;
};


template<>
struct MessageTraits<msg_settings_write_t> {
  static constexpr u16 id = 160;
};



template<>
struct MessageTraits<msg_settings_read_by_index_req_t> {
  static constexpr u16 id = 162;
};


template<>
struct MessageTraits<msg_fileio_read_resp_t> {
  static constexpr u16 id = 163;
};


template<>
struct MessageTraits<msg_settings_read_req_t> {
  static constexpr u16 id = 164;
};


template<>
struct MessageTraits<msg_settings_read_resp_t> {
  static constexpr u16 id = 165;
};



template<>
struct MessageTraits<msg_settings_read_by_index_resp_t> {
  static constexpr u16 id = 167;
};


template<>
struct MessageTraits<msg_fileio_read_req_t> {
  static constexpr u16 id = 168;
};


template<>
struct MessageTraits<msg_fileio_read_dir_req_t> {
  static constexpr u16 id = 169;
};


template<>
struct MessageTraits<msg_fileio_read_dir_resp_t> {
  static constexpr u16 id = 170;
};


template<>
struct MessageTraits<msg_fileio_write_resp_t> {
  static constexpr u16 id = 171;
};


template<>
struct MessageTraits<msg_fileio_remove_t> {
  static constexpr u16 id = 172;
};


template<>
struct MessageTraits<msg_fileio_write_req_t> {
  static constexpr u16 id = 173;
};


template<>
struct MessageTraits<msg_settings_register_t> {
  static constexpr u16 id = 174;
};


template<>
struct MessageTraits<msg_settings_write_resp_t> {
  static constexpr u16 id = 175;
};


template<>
struct MessageTraits<msg_bootloader_handshake_dep_a_t> {
  static constexpr u16 id = 176;
};


template<>
struct MessageTraits<msg_bootloader_jump_to_app_t> {
  static constexpr u16 id = 177;
};




template<>
struct MessageTraits<msg_bootloader_handshake_resp_t> {
  static constexpr u16 id = 180;
};


template<>
struct MessageTraits<msg_device_monitor_t> {
  static constexpr u16 id = 181;
};


template<>
struct MessageTraits<msg_reset_t> {
  static constexpr u16 id = 182;
};


template<>
struct MessageTraits<msg_command_req_t> {
  static constexpr u16 id = 184;
};


template<>
struct MessageTraits<msg_command_resp_t> {
  static constexpr u16 id = 185;
};



template<>
struct MessageTraits<msg_network_state_resp_t> {
  static constexpr u16 id = 187;
};


template<>
struct MessageTraits<msg_command_output_t> {
  static constexpr u16 id = 188;
};


template<>
struct MessageTraits<msg_network_bandwidth_usage_t> {
  static constexpr u16 id = 189;
};


template<>
struct MessageTraits<msg_cell_modem_status_t> {
  static constexpr u16 id = 190;
};


template<>
struct MessageTraits<msg_front_end_gain_t> {
  static constexpr u16 id = 191;
};




template<>
struct MessageTraits<msg_nap_device_dna_resp_t> {
  static constexpr u16 id = 221;
};



template<>
struct MessageTraits<msg_flash_done_t> {
  static constexpr u16 id = 224;
};


template<>
struct MessageTraits<msg_flash_read_resp_t> {
  static constexpr u16 id = 225;
};


template<>
struct MessageTraits<msg_flash_erase_t> {
  static constexpr u16 id = 226;
};


template<>
struct MessageTraits<msg_stm_flash_lock_sector_t> {
  static constexpr u16 id = 227;
};


template<>
struct MessageTraits<msg_stm_flash_unlock_sector_t> {
  static constexpr u16 id = 228;
};


template<>
struct MessageTraits<msg_stm_unique_id_resp_t> {
  static constexpr u16 id = 229;
};


template<>
struct MessageTraits<msg_flash_program_t> {
  static constexpr u16 id = 230;
};


template<>
struct MessageTraits<msg_flash_read_req_t> {
  static constexpr u16 id = 231;
};



template<>
struct MessageTraits<msg_m25_flash_write_status_t> {
  static constexpr u16 id = 243;
};


template<>
struct MessageTraits<msg_gps_time_dep_a_t> {
  static constexpr u16 id = 256;
};


template<>
struct MessageTraits<msg_ext_event_t> {
  static constexpr u16 id = 257;
};


template<>
struct MessageTraits<msg_gps_time_t> {
  static constexpr u16 id = 258;
};


template<>
struct MessageTraits<msg_utc_time_t> {
  static constexpr u16 id = 259;
};


template<>
struct MessageTraits<msg_settings_register_resp_t> {
  static constexpr u16 id = 431;
};


template<>
struct MessageTraits<msg_pos_ecef_dep_a_t> {
  static constexpr u16 id = 512;
};


template<>
struct MessageTraits<msg_pos_llh_dep_a_t> {
  static constexpr u16 id = 513;
};


template<>
struct MessageTraits<msg_baseline_ecef_dep_a_t> {
  static constexpr u16 id = 514;
};


template<>
struct MessageTraits<msg_baseline_ned_dep_a_t> {
  static constexpr u16 id = 515;
};


template<>
struct MessageTraits<msg_vel_ecef_dep_a_t> {
  static constexpr u16 id = 516;
};


template<>
struct MessageTraits<msg_vel_ned_dep_a_t> {
  static constexpr u16 id = 517;
};


template<>
struct MessageTraits<msg_dops_dep_a_t> {
  static constexpr u16 id = 518;
};


template<>
struct MessageTraits<msg_baseline_heading_dep_a_t> {
  static constexpr u16 id = 519;
};


template<>
struct MessageTraits<msg_dops_t> {
  static constexpr u16 id = 520;
};


template<>
struct MessageTraits<msg_pos_ecef_t> {
  static constexpr u16 id = 521;
};


template<>
struct MessageTraits<msg_pos_llh_t> {
  static constexpr u16 id = 522;
};


template<>
struct MessageTraits<msg_baseline_ecef_t> {
  static constexpr u16 id = 523;
};


template<>
struct MessageTraits<msg_baseline_ned_t> {
  static constexpr u16 id = 524;
};


template<>
struct MessageTraits<msg_vel_ecef_t> {
  static constexpr u16 id = 525;
};


template<>
struct MessageTraits<msg_vel_ned_t> {
  static constexpr u16 id = 526;
};


template<>
struct MessageTraits<msg_baseline_heading_t> {
  static constexpr u16 id = 527;
};


template<>
struct MessageTraits<msg_age_corrections_t> {
  static constexpr u16 id = 528;
};


template<>
struct MessageTraits<msg_pos_llh_cov_t> {
  static constexpr u16 id = 529;
};


template<>
struct MessageTraits<msg_vel_ned_cov_t> {
  static constexpr u16 id = 530;
};


template<>
struct MessageTraits<msg_vel_body_t> {
  static constexpr u16 id = 531;
};


template<>
struct MessageTraits<msg_pos_ecef_cov_t> {
  static constexpr u16 id = 532;
};


template<>
struct MessageTraits<msg_vel_ecef_cov_t> {
  static constexpr u16 id = 533;
};


template<>
struct MessageTraits<msg_protection_level_t> {
  static constexpr u16 id = 534;
};


template<>
struct MessageTraits<msg_orient_quat_t> {
  static constexpr u16 id = 544;
};


template<>
struct MessageTraits<msg_orient_euler_t> {
  static constexpr u16 id = 545;
};


template<>
struct MessageTraits<msg_angular_rate_t> {
  static constexpr u16 id = 546;
};


template<>
struct MessageTraits<msg_pos_ecef_gnss_t> {
  static constexpr u16 id = 553;
};


template<>
struct MessageTraits<msg_pos_llh_gnss_t> {
  static constexpr u16 id = 554;
};


template<>
struct MessageTraits<msg_vel_ecef_gnss_t> {
  static constexpr u16 id = 557;
};


template<>
struct MessageTraits<msg_vel_ned_gnss_t> {
  static constexpr u16 id = 558;
};


template<>
struct MessageTraits<msg_pos_llh_cov_gnss_t> {
  static constexpr u16 id = 561;
};


template<>
struct MessageTraits<msg_vel_ned_cov_gnss_t> {
  static constexpr u16 id = 562;
};


template<>
struct MessageTraits<msg_pos_ecef_cov_gnss_t> {
  static constexpr u16 id = 564;
};


template<>
struct MessageTraits<msg_vel_ecef_cov_gnss_t> {
  static constexpr u16 id = 565;
};


template<>
struct MessageTraits<msg_ndb_event_t> {
  static constexpr u16 id = 1024;
};


template<>
struct MessageTraits<msg_log_t> {
  static constexpr u16 id = 1025;
};


template<>
struct MessageTraits<msg_fwd_t> {
  static constexpr u16 id = 1026;
};


template<>
struct MessageTraits<msg_ssr_orbit_clock_dep_a_t> {
  static constexpr u16 id = 1500;
};


template<>
struct MessageTraits<msg_ssr_orbit_clock_t> {
  static constexpr u16 id = 1501;
};


template<>
struct MessageTraits<msg_ssr_code_biases_t> {
  static constexpr u16 id = 1505;
};


template<>
struct MessageTraits<msg_ssr_phase_biases_t> {
  static constexpr u16 id = 1510;
};


template<>
struct MessageTraits<msg_ssr_stec_correction_t> {
  static constexpr u16 id = 1515;
};


template<>
struct MessageTraits<msg_ssr_gridded_correction_no_std_t> {
  static constexpr u16 id = 1520;
};


template<>
struct MessageTraits<msg_ssr_grid_definition_t> {
  static constexpr u16 id = 1525;
};


template<>
struct MessageTraits<msg_ssr_gridded_correction_t> {
  static constexpr u16 id = 1530;
};


template<>
struct MessageTraits<msg_osr_t> {
  static constexpr u16 id = 1600;
};


template<>
struct MessageTraits<msg_user_data_t> {
  static constexpr u16 id = 2048;
};


template<>
struct MessageTraits<msg_imu_raw_t> {
  static constexpr u16 id = 2304;
};


template<>
struct MessageTraits<msg_imu_aux_t> {
  static constexpr u16 id = 2305;
};


template<>
struct MessageTraits<msg_mag_raw_t> {
  static constexpr u16 id = 2306;
};


template<>
struct MessageTraits<msg_odometry_t> {
  static constexpr u16 id = 2307;
};


template<>
struct MessageTraits<msg_wheeltick_t> {
  static constexpr u16 id = 2308;
};


template<>
struct MessageTraits<msg_fileio_config_req_t> {
  static constexpr u16 id = 4097;
};


template<>
struct MessageTraits<msg_fileio_config_resp_t> {
  static constexpr u16 id = 4098;
};


template<>
struct MessageTraits<msg_sbas_raw_t> {
  static constexpr u16 id = 30583;
};


template<>
struct MessageTraits<msg_linux_cpu_state_t> {
  static constexpr u16 id = 32512;
};


template<>
struct MessageTraits<msg_linux_mem_state_t> {
  static constexpr u16 id = 32513;
};


template<>
struct MessageTraits<msg_linux_sys_state_t> {
  static constexpr u16 id = 32514;
};


template<>
struct MessageTraits<msg_linux_process_socket_counts_t> {
  static constexpr u16 id = 32515;
};


template<>
struct MessageTraits<msg_linux_process_socket_queues_t> {
  static constexpr u16 id = 32516;
};


template<>
struct MessageTraits<msg_linux_socket_usage_t> {
  static constexpr u16 id = 32517;
};


template<>
struct MessageTraits<msg_linux_process_fd_count_t> {
  static constexpr u16 id = 32518;
};


template<>
struct MessageTraits<msg_linux_process_fd_summary_t> {
  static constexpr u16 id = 32519;
};


template<>
struct MessageTraits<msg_startup_t> {
  static constexpr u16 id = 65280;
};


template<>
struct MessageTraits<msg_dgnss_status_t> {
  static constexpr u16 id = 65282;
};


template<>
struct MessageTraits<msg_ins_status_t> {
  static constexpr u16 id = 65283;
};


template<>
struct MessageTraits<msg_csac_telemetry_t> {
  static constexpr u16 id = 65284;
};


template<>
struct MessageTraits<msg_csac_telemetry_labels_t> {
  static constexpr u16 id = 65285;
};


template<>
struct MessageTraits<msg_heartbeat_t> {
  static constexpr u16 id = 65535;
};




} // namespace sbp

#endif //SBP_CPP_MESSAGE_TRAITS_H