/*
 * Copyright (C) 2015-2021 Swift Navigation Inc.
 * Contact: https://support.swiftnav.com
 *
 * This source is subject to the license found in the file 'LICENSE' which must
 * be be distributed together with this source. All other rights reserved.
 *
 * THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
 * EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
 */

/*****************************************************************************
 * Automatically generated
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

#ifndef LIBSBP_V4_SBP_MSG_H
#define LIBSBP_V4_SBP_MSG_H

#include <stddef.h>
#include <stdint.h>

#include <libsbp/sbp_msg_type.h>
#include <libsbp/v4/acquisition.h>
#include <libsbp/v4/bootload.h>
#include <libsbp/v4/ext_events.h>
#include <libsbp/v4/file_io.h>
#include <libsbp/v4/flash.h>
#include <libsbp/v4/gnss.h>
#include <libsbp/v4/imu.h>
#include <libsbp/v4/linux.h>
#include <libsbp/v4/logging.h>
#include <libsbp/v4/mag.h>
#include <libsbp/v4/navigation.h>
#include <libsbp/v4/ndb.h>
#include <libsbp/v4/observation.h>
#include <libsbp/v4/orientation.h>
#include <libsbp/v4/piksi.h>
#include <libsbp/v4/sbas.h>
#include <libsbp/v4/settings.h>
#include <libsbp/v4/solution_meta.h>
#include <libsbp/v4/ssr.h>
#include <libsbp/v4/system.h>
#include <libsbp/v4/tracking.h>
#include <libsbp/v4/user.h>
#include <libsbp/v4/vehicle.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Used to hold an individual sbp_msg struct so that the message can be used in
 * all general purpose functions within this file.
 */
typedef union {
  sbp_msg_acq_result_dep_a_t acq_result_dep_a;
  sbp_msg_acq_result_dep_b_t acq_result_dep_b;
  sbp_msg_acq_result_dep_c_t acq_result_dep_c;
  sbp_msg_acq_result_t acq_result;
  sbp_msg_acq_sv_profile_dep_t acq_sv_profile_dep;
  sbp_msg_acq_sv_profile_t acq_sv_profile;
  sbp_msg_age_corrections_t age_corrections;
  sbp_msg_almanac_glo_dep_t almanac_glo_dep;
  sbp_msg_almanac_glo_t almanac_glo;
  sbp_msg_almanac_gps_dep_t almanac_gps_dep;
  sbp_msg_almanac_gps_t almanac_gps;
  sbp_msg_almanac_t almanac;
  sbp_msg_angular_rate_t angular_rate;
  sbp_msg_base_pos_ecef_t base_pos_ecef;
  sbp_msg_base_pos_llh_t base_pos_llh;
  sbp_msg_baseline_ecef_dep_a_t baseline_ecef_dep_a;
  sbp_msg_baseline_ecef_t baseline_ecef;
  sbp_msg_baseline_heading_dep_a_t baseline_heading_dep_a;
  sbp_msg_baseline_heading_t baseline_heading;
  sbp_msg_baseline_ned_dep_a_t baseline_ned_dep_a;
  sbp_msg_baseline_ned_t baseline_ned;
  sbp_msg_bootloader_handshake_dep_a_t bootloader_handshake_dep_a;
  sbp_msg_bootloader_handshake_req_t bootloader_handshake_req;
  sbp_msg_bootloader_handshake_resp_t bootloader_handshake_resp;
  sbp_msg_bootloader_jump_to_app_t bootloader_jump_to_app;
  sbp_msg_cell_modem_status_t cell_modem_status;
  sbp_msg_command_output_t command_output;
  sbp_msg_command_req_t command_req;
  sbp_msg_command_resp_t command_resp;
  sbp_msg_csac_telemetry_labels_t csac_telemetry_labels;
  sbp_msg_csac_telemetry_t csac_telemetry;
  sbp_msg_cw_results_t cw_results;
  sbp_msg_cw_start_t cw_start;
  sbp_msg_device_monitor_t device_monitor;
  sbp_msg_dgnss_status_t dgnss_status;
  sbp_msg_dops_dep_a_t dops_dep_a;
  sbp_msg_dops_t dops;
  sbp_msg_ephemeris_bds_t ephemeris_bds;
  sbp_msg_ephemeris_dep_a_t ephemeris_dep_a;
  sbp_msg_ephemeris_dep_b_t ephemeris_dep_b;
  sbp_msg_ephemeris_dep_c_t ephemeris_dep_c;
  sbp_msg_ephemeris_dep_d_t ephemeris_dep_d;
  sbp_msg_ephemeris_gal_dep_a_t ephemeris_gal_dep_a;
  sbp_msg_ephemeris_gal_t ephemeris_gal;
  sbp_msg_ephemeris_glo_dep_a_t ephemeris_glo_dep_a;
  sbp_msg_ephemeris_glo_dep_b_t ephemeris_glo_dep_b;
  sbp_msg_ephemeris_glo_dep_c_t ephemeris_glo_dep_c;
  sbp_msg_ephemeris_glo_dep_d_t ephemeris_glo_dep_d;
  sbp_msg_ephemeris_glo_t ephemeris_glo;
  sbp_msg_ephemeris_gps_dep_e_t ephemeris_gps_dep_e;
  sbp_msg_ephemeris_gps_dep_f_t ephemeris_gps_dep_f;
  sbp_msg_ephemeris_gps_t ephemeris_gps;
  sbp_msg_ephemeris_qzss_t ephemeris_qzss;
  sbp_msg_ephemeris_sbas_dep_a_t ephemeris_sbas_dep_a;
  sbp_msg_ephemeris_sbas_dep_b_t ephemeris_sbas_dep_b;
  sbp_msg_ephemeris_sbas_t ephemeris_sbas;
  sbp_msg_ext_event_t ext_event;
  sbp_msg_fileio_config_req_t fileio_config_req;
  sbp_msg_fileio_config_resp_t fileio_config_resp;
  sbp_msg_fileio_read_dir_req_t fileio_read_dir_req;
  sbp_msg_fileio_read_dir_resp_t fileio_read_dir_resp;
  sbp_msg_fileio_read_req_t fileio_read_req;
  sbp_msg_fileio_read_resp_t fileio_read_resp;
  sbp_msg_fileio_remove_t fileio_remove;
  sbp_msg_fileio_write_req_t fileio_write_req;
  sbp_msg_fileio_write_resp_t fileio_write_resp;
  sbp_msg_flash_done_t flash_done;
  sbp_msg_flash_erase_t flash_erase;
  sbp_msg_flash_program_t flash_program;
  sbp_msg_flash_read_req_t flash_read_req;
  sbp_msg_flash_read_resp_t flash_read_resp;
  sbp_msg_front_end_gain_t front_end_gain;
  sbp_msg_fwd_t fwd;
  sbp_msg_glo_biases_t glo_biases;
  sbp_msg_gnss_capb_t gnss_capb;
  sbp_msg_gnss_time_offset_t gnss_time_offset;
  sbp_msg_gps_time_dep_a_t gps_time_dep_a;
  sbp_msg_gps_time_gnss_t gps_time_gnss;
  sbp_msg_gps_time_t gps_time;
  sbp_msg_group_delay_dep_a_t group_delay_dep_a;
  sbp_msg_group_delay_dep_b_t group_delay_dep_b;
  sbp_msg_group_delay_t group_delay;
  sbp_msg_group_meta_t group_meta;
  sbp_msg_heartbeat_t heartbeat;
  sbp_msg_iar_state_t iar_state;
  sbp_msg_imu_aux_t imu_aux;
  sbp_msg_imu_raw_t imu_raw;
  sbp_msg_init_base_dep_t init_base_dep;
  sbp_msg_ins_status_t ins_status;
  sbp_msg_ins_updates_t ins_updates;
  sbp_msg_iono_t iono;
  sbp_msg_linux_cpu_state_dep_a_t linux_cpu_state_dep_a;
  sbp_msg_linux_cpu_state_t linux_cpu_state;
  sbp_msg_linux_mem_state_dep_a_t linux_mem_state_dep_a;
  sbp_msg_linux_mem_state_t linux_mem_state;
  sbp_msg_linux_process_fd_count_t linux_process_fd_count;
  sbp_msg_linux_process_fd_summary_t linux_process_fd_summary;
  sbp_msg_linux_process_socket_counts_t linux_process_socket_counts;
  sbp_msg_linux_process_socket_queues_t linux_process_socket_queues;
  sbp_msg_linux_socket_usage_t linux_socket_usage;
  sbp_msg_linux_sys_state_dep_a_t linux_sys_state_dep_a;
  sbp_msg_linux_sys_state_t linux_sys_state;
  sbp_msg_log_t log;
  sbp_msg_m25_flash_write_status_t m25_flash_write_status;
  sbp_msg_mag_raw_t mag_raw;
  sbp_msg_mask_satellite_dep_t mask_satellite_dep;
  sbp_msg_mask_satellite_t mask_satellite;
  sbp_msg_measurement_state_t measurement_state;
  sbp_msg_nap_device_dna_req_t nap_device_dna_req;
  sbp_msg_nap_device_dna_resp_t nap_device_dna_resp;
  sbp_msg_ndb_event_t ndb_event;
  sbp_msg_network_bandwidth_usage_t network_bandwidth_usage;
  sbp_msg_network_state_req_t network_state_req;
  sbp_msg_network_state_resp_t network_state_resp;
  sbp_msg_obs_dep_a_t obs_dep_a;
  sbp_msg_obs_dep_b_t obs_dep_b;
  sbp_msg_obs_dep_c_t obs_dep_c;
  sbp_msg_obs_t obs;
  sbp_msg_odometry_t odometry;
  sbp_msg_orient_euler_t orient_euler;
  sbp_msg_orient_quat_t orient_quat;
  sbp_msg_osr_t osr;
  sbp_msg_pos_ecef_cov_gnss_t pos_ecef_cov_gnss;
  sbp_msg_pos_ecef_cov_t pos_ecef_cov;
  sbp_msg_pos_ecef_dep_a_t pos_ecef_dep_a;
  sbp_msg_pos_ecef_gnss_t pos_ecef_gnss;
  sbp_msg_pos_ecef_t pos_ecef;
  sbp_msg_pos_llh_acc_t pos_llh_acc;
  sbp_msg_pos_llh_cov_gnss_t pos_llh_cov_gnss;
  sbp_msg_pos_llh_cov_t pos_llh_cov;
  sbp_msg_pos_llh_dep_a_t pos_llh_dep_a;
  sbp_msg_pos_llh_gnss_t pos_llh_gnss;
  sbp_msg_pos_llh_t pos_llh;
  sbp_msg_pps_time_t pps_time;
  sbp_msg_print_dep_t print_dep;
  sbp_msg_protection_level_dep_a_t protection_level_dep_a;
  sbp_msg_protection_level_t protection_level;
  sbp_msg_reset_dep_t reset_dep;
  sbp_msg_reset_filters_t reset_filters;
  sbp_msg_reset_t reset;
  sbp_msg_sbas_raw_t sbas_raw;
  sbp_msg_sensor_aid_event_t sensor_aid_event;
  sbp_msg_set_time_t set_time;
  sbp_msg_settings_read_by_index_done_t settings_read_by_index_done;
  sbp_msg_settings_read_by_index_req_t settings_read_by_index_req;
  sbp_msg_settings_read_by_index_resp_t settings_read_by_index_resp;
  sbp_msg_settings_read_req_t settings_read_req;
  sbp_msg_settings_read_resp_t settings_read_resp;
  sbp_msg_settings_register_resp_t settings_register_resp;
  sbp_msg_settings_register_t settings_register;
  sbp_msg_settings_save_t settings_save;
  sbp_msg_settings_write_resp_t settings_write_resp;
  sbp_msg_settings_write_t settings_write;
  sbp_msg_soln_meta_dep_a_t soln_meta_dep_a;
  sbp_msg_soln_meta_t soln_meta;
  sbp_msg_specan_dep_t specan_dep;
  sbp_msg_specan_t specan;
  sbp_msg_ssr_code_biases_t ssr_code_biases;
  sbp_msg_ssr_grid_definition_dep_a_t ssr_grid_definition_dep_a;
  sbp_msg_ssr_gridded_correction_dep_a_t ssr_gridded_correction_dep_a;
  sbp_msg_ssr_gridded_correction_no_std_dep_a_t
      ssr_gridded_correction_no_std_dep_a;
  sbp_msg_ssr_gridded_correction_t ssr_gridded_correction;
  sbp_msg_ssr_orbit_clock_dep_a_t ssr_orbit_clock_dep_a;
  sbp_msg_ssr_orbit_clock_t ssr_orbit_clock;
  sbp_msg_ssr_phase_biases_t ssr_phase_biases;
  sbp_msg_ssr_satellite_apc_t ssr_satellite_apc;
  sbp_msg_ssr_stec_correction_dep_a_t ssr_stec_correction_dep_a;
  sbp_msg_ssr_stec_correction_t ssr_stec_correction;
  sbp_msg_ssr_tile_definition_t ssr_tile_definition;
  sbp_msg_startup_t startup;
  sbp_msg_status_report_t status_report;
  sbp_msg_stm_flash_lock_sector_t stm_flash_lock_sector;
  sbp_msg_stm_flash_unlock_sector_t stm_flash_unlock_sector;
  sbp_msg_stm_unique_id_req_t stm_unique_id_req;
  sbp_msg_stm_unique_id_resp_t stm_unique_id_resp;
  sbp_msg_sv_az_el_t sv_az_el;
  sbp_msg_sv_configuration_gps_dep_t sv_configuration_gps_dep;
  sbp_msg_thread_state_t thread_state;
  sbp_msg_tracking_iq_dep_a_t tracking_iq_dep_a;
  sbp_msg_tracking_iq_dep_b_t tracking_iq_dep_b;
  sbp_msg_tracking_iq_t tracking_iq;
  sbp_msg_tracking_state_dep_a_t tracking_state_dep_a;
  sbp_msg_tracking_state_dep_b_t tracking_state_dep_b;
  sbp_msg_tracking_state_detailed_dep_a_t tracking_state_detailed_dep_a;
  sbp_msg_tracking_state_detailed_dep_t tracking_state_detailed_dep;
  sbp_msg_tracking_state_t tracking_state;
  sbp_msg_uart_state_depa_t uart_state_depa;
  sbp_msg_uart_state_t uart_state;
  sbp_msg_user_data_t user_data;
  sbp_msg_utc_time_gnss_t utc_time_gnss;
  sbp_msg_utc_time_t utc_time;
  sbp_msg_vel_body_t vel_body;
  sbp_msg_vel_cog_t vel_cog;
  sbp_msg_vel_ecef_cov_gnss_t vel_ecef_cov_gnss;
  sbp_msg_vel_ecef_cov_t vel_ecef_cov;
  sbp_msg_vel_ecef_dep_a_t vel_ecef_dep_a;
  sbp_msg_vel_ecef_gnss_t vel_ecef_gnss;
  sbp_msg_vel_ecef_t vel_ecef;
  sbp_msg_vel_ned_cov_gnss_t vel_ned_cov_gnss;
  sbp_msg_vel_ned_cov_t vel_ned_cov;
  sbp_msg_vel_ned_dep_a_t vel_ned_dep_a;
  sbp_msg_vel_ned_gnss_t vel_ned_gnss;
  sbp_msg_vel_ned_t vel_ned;
  sbp_msg_wheeltick_t wheeltick;
} sbp_msg_t;

/** Encodes a SBP message to the SBP wire format, writing it to the given
 * buffer.
 *
 * \param buf         Buffer to write the resulting encoded data to
 * \param len         The amount of bytes available in buf
 * \param n_written   (out) Number of bytes written to buf
 * \param msg_type    SBP message type
 * \param msg         SBP message to encode
 * \return `SBP_ENCODE_ERROR` (-7) if message was unable to be encoded
 *         `SBP_OK` (0) if the message was successfully encoded and written to
 * buf callback
 */
s8 sbp_message_encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                      sbp_msg_type_t msg_type, const sbp_msg_t *msg);

/** Decodes a SBP message from the SBP encoded wire format.
 *
 * \param buf         Buffer containing the encoded SBP message
 * \param len         Number of bytes in buf
 * \param n_read      (out) The number of bytes read when decoding
 * \param msg_type    SBP message type to decode to
 * \param msg         SBP message struct to fill in the details of
 * \return `SBP_DECODE_ERROR` (-8) if message was unable to be decoded
 *         `SBP_OK` (0) if the message was successfully decoded
 *         callback
 */
s8 sbp_message_decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                      sbp_msg_type_t msg_type, sbp_msg_t *msg);

/** Returns the wire format size in bytes of a given SBP message.
 *
 * \param msg_type    SBP message type
 * \param msg         SBP message
 * \return            The Number of bytes that the given message would be on the
 * wire
 */
size_t sbp_message_encoded_len(sbp_msg_type_t msg_type, const sbp_msg_t *msg);

/** Compares two SBP messages of equal type.
 *
 * \param msg_type    SBP message type
 * \param a           The first message to compare
 * \param b           The second message to compare
 * \return            0 if the two messages have equal fields
 *                    1 if, on the first non-equal field, a.field > b.field
 *                    -1 if, on the first non-equal field, a.field < b.field
 */
int sbp_message_cmp(sbp_msg_type_t msg_type, const sbp_msg_t *a,
                    const sbp_msg_t *b);

#ifdef __cplusplus
}
#endif

#endif /* LIBSBP_V4_SBP_MSG_H */
