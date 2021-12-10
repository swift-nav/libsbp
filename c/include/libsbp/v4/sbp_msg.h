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

#include <stdbool.h>
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
static inline s8 sbp_message_encode(uint8_t *buf, uint8_t len,
                                    uint8_t *n_written, sbp_msg_type_t msg_type,
                                    const sbp_msg_t *msg) {
  switch (msg_type) {
    case SbpMsgAcqResultDepA:
      return sbp_msg_acq_result_dep_a_encode(buf, len, n_written,
                                             &msg->acq_result_dep_a);
    case SbpMsgAcqResultDepB:
      return sbp_msg_acq_result_dep_b_encode(buf, len, n_written,
                                             &msg->acq_result_dep_b);
    case SbpMsgAcqResultDepC:
      return sbp_msg_acq_result_dep_c_encode(buf, len, n_written,
                                             &msg->acq_result_dep_c);
    case SbpMsgAcqResult:
      return sbp_msg_acq_result_encode(buf, len, n_written, &msg->acq_result);
    case SbpMsgAcqSvProfileDep:
      return sbp_msg_acq_sv_profile_dep_encode(buf, len, n_written,
                                               &msg->acq_sv_profile_dep);
    case SbpMsgAcqSvProfile:
      return sbp_msg_acq_sv_profile_encode(buf, len, n_written,
                                           &msg->acq_sv_profile);
    case SbpMsgAgeCorrections:
      return sbp_msg_age_corrections_encode(buf, len, n_written,
                                            &msg->age_corrections);
    case SbpMsgAlmanacGloDep:
      return sbp_msg_almanac_glo_dep_encode(buf, len, n_written,
                                            &msg->almanac_glo_dep);
    case SbpMsgAlmanacGlo:
      return sbp_msg_almanac_glo_encode(buf, len, n_written, &msg->almanac_glo);
    case SbpMsgAlmanacGpsDep:
      return sbp_msg_almanac_gps_dep_encode(buf, len, n_written,
                                            &msg->almanac_gps_dep);
    case SbpMsgAlmanacGps:
      return sbp_msg_almanac_gps_encode(buf, len, n_written, &msg->almanac_gps);
    case SbpMsgAlmanac:
      return sbp_msg_almanac_encode(buf, len, n_written, &msg->almanac);
    case SbpMsgAngularRate:
      return sbp_msg_angular_rate_encode(buf, len, n_written,
                                         &msg->angular_rate);
    case SbpMsgBasePosEcef:
      return sbp_msg_base_pos_ecef_encode(buf, len, n_written,
                                          &msg->base_pos_ecef);
    case SbpMsgBasePosLlh:
      return sbp_msg_base_pos_llh_encode(buf, len, n_written,
                                         &msg->base_pos_llh);
    case SbpMsgBaselineEcefDepA:
      return sbp_msg_baseline_ecef_dep_a_encode(buf, len, n_written,
                                                &msg->baseline_ecef_dep_a);
    case SbpMsgBaselineEcef:
      return sbp_msg_baseline_ecef_encode(buf, len, n_written,
                                          &msg->baseline_ecef);
    case SbpMsgBaselineHeadingDepA:
      return sbp_msg_baseline_heading_dep_a_encode(
          buf, len, n_written, &msg->baseline_heading_dep_a);
    case SbpMsgBaselineHeading:
      return sbp_msg_baseline_heading_encode(buf, len, n_written,
                                             &msg->baseline_heading);
    case SbpMsgBaselineNedDepA:
      return sbp_msg_baseline_ned_dep_a_encode(buf, len, n_written,
                                               &msg->baseline_ned_dep_a);
    case SbpMsgBaselineNed:
      return sbp_msg_baseline_ned_encode(buf, len, n_written,
                                         &msg->baseline_ned);
    case SbpMsgBootloaderHandshakeDepA:
      return sbp_msg_bootloader_handshake_dep_a_encode(
          buf, len, n_written, &msg->bootloader_handshake_dep_a);
    case SbpMsgBootloaderHandshakeReq:
      return sbp_msg_bootloader_handshake_req_encode(
          buf, len, n_written, &msg->bootloader_handshake_req);
    case SbpMsgBootloaderHandshakeResp:
      return sbp_msg_bootloader_handshake_resp_encode(
          buf, len, n_written, &msg->bootloader_handshake_resp);
    case SbpMsgBootloaderJumpToApp:
      return sbp_msg_bootloader_jump_to_app_encode(
          buf, len, n_written, &msg->bootloader_jump_to_app);
    case SbpMsgCellModemStatus:
      return sbp_msg_cell_modem_status_encode(buf, len, n_written,
                                              &msg->cell_modem_status);
    case SbpMsgCommandOutput:
      return sbp_msg_command_output_encode(buf, len, n_written,
                                           &msg->command_output);
    case SbpMsgCommandReq:
      return sbp_msg_command_req_encode(buf, len, n_written, &msg->command_req);
    case SbpMsgCommandResp:
      return sbp_msg_command_resp_encode(buf, len, n_written,
                                         &msg->command_resp);
    case SbpMsgCsacTelemetryLabels:
      return sbp_msg_csac_telemetry_labels_encode(buf, len, n_written,
                                                  &msg->csac_telemetry_labels);
    case SbpMsgCsacTelemetry:
      return sbp_msg_csac_telemetry_encode(buf, len, n_written,
                                           &msg->csac_telemetry);
    case SbpMsgCwResults:
      return sbp_msg_cw_results_encode(buf, len, n_written, &msg->cw_results);
    case SbpMsgCwStart:
      return sbp_msg_cw_start_encode(buf, len, n_written, &msg->cw_start);
    case SbpMsgDeviceMonitor:
      return sbp_msg_device_monitor_encode(buf, len, n_written,
                                           &msg->device_monitor);
    case SbpMsgDgnssStatus:
      return sbp_msg_dgnss_status_encode(buf, len, n_written,
                                         &msg->dgnss_status);
    case SbpMsgDopsDepA:
      return sbp_msg_dops_dep_a_encode(buf, len, n_written, &msg->dops_dep_a);
    case SbpMsgDops:
      return sbp_msg_dops_encode(buf, len, n_written, &msg->dops);
    case SbpMsgEphemerisBds:
      return sbp_msg_ephemeris_bds_encode(buf, len, n_written,
                                          &msg->ephemeris_bds);
    case SbpMsgEphemerisDepA:
      return sbp_msg_ephemeris_dep_a_encode(buf, len, n_written,
                                            &msg->ephemeris_dep_a);
    case SbpMsgEphemerisDepB:
      return sbp_msg_ephemeris_dep_b_encode(buf, len, n_written,
                                            &msg->ephemeris_dep_b);
    case SbpMsgEphemerisDepC:
      return sbp_msg_ephemeris_dep_c_encode(buf, len, n_written,
                                            &msg->ephemeris_dep_c);
    case SbpMsgEphemerisDepD:
      return sbp_msg_ephemeris_dep_d_encode(buf, len, n_written,
                                            &msg->ephemeris_dep_d);
    case SbpMsgEphemerisGalDepA:
      return sbp_msg_ephemeris_gal_dep_a_encode(buf, len, n_written,
                                                &msg->ephemeris_gal_dep_a);
    case SbpMsgEphemerisGal:
      return sbp_msg_ephemeris_gal_encode(buf, len, n_written,
                                          &msg->ephemeris_gal);
    case SbpMsgEphemerisGloDepA:
      return sbp_msg_ephemeris_glo_dep_a_encode(buf, len, n_written,
                                                &msg->ephemeris_glo_dep_a);
    case SbpMsgEphemerisGloDepB:
      return sbp_msg_ephemeris_glo_dep_b_encode(buf, len, n_written,
                                                &msg->ephemeris_glo_dep_b);
    case SbpMsgEphemerisGloDepC:
      return sbp_msg_ephemeris_glo_dep_c_encode(buf, len, n_written,
                                                &msg->ephemeris_glo_dep_c);
    case SbpMsgEphemerisGloDepD:
      return sbp_msg_ephemeris_glo_dep_d_encode(buf, len, n_written,
                                                &msg->ephemeris_glo_dep_d);
    case SbpMsgEphemerisGlo:
      return sbp_msg_ephemeris_glo_encode(buf, len, n_written,
                                          &msg->ephemeris_glo);
    case SbpMsgEphemerisGpsDepE:
      return sbp_msg_ephemeris_gps_dep_e_encode(buf, len, n_written,
                                                &msg->ephemeris_gps_dep_e);
    case SbpMsgEphemerisGpsDepF:
      return sbp_msg_ephemeris_gps_dep_f_encode(buf, len, n_written,
                                                &msg->ephemeris_gps_dep_f);
    case SbpMsgEphemerisGps:
      return sbp_msg_ephemeris_gps_encode(buf, len, n_written,
                                          &msg->ephemeris_gps);
    case SbpMsgEphemerisQzss:
      return sbp_msg_ephemeris_qzss_encode(buf, len, n_written,
                                           &msg->ephemeris_qzss);
    case SbpMsgEphemerisSbasDepA:
      return sbp_msg_ephemeris_sbas_dep_a_encode(buf, len, n_written,
                                                 &msg->ephemeris_sbas_dep_a);
    case SbpMsgEphemerisSbasDepB:
      return sbp_msg_ephemeris_sbas_dep_b_encode(buf, len, n_written,
                                                 &msg->ephemeris_sbas_dep_b);
    case SbpMsgEphemerisSbas:
      return sbp_msg_ephemeris_sbas_encode(buf, len, n_written,
                                           &msg->ephemeris_sbas);
    case SbpMsgExtEvent:
      return sbp_msg_ext_event_encode(buf, len, n_written, &msg->ext_event);
    case SbpMsgFileioConfigReq:
      return sbp_msg_fileio_config_req_encode(buf, len, n_written,
                                              &msg->fileio_config_req);
    case SbpMsgFileioConfigResp:
      return sbp_msg_fileio_config_resp_encode(buf, len, n_written,
                                               &msg->fileio_config_resp);
    case SbpMsgFileioReadDirReq:
      return sbp_msg_fileio_read_dir_req_encode(buf, len, n_written,
                                                &msg->fileio_read_dir_req);
    case SbpMsgFileioReadDirResp:
      return sbp_msg_fileio_read_dir_resp_encode(buf, len, n_written,
                                                 &msg->fileio_read_dir_resp);
    case SbpMsgFileioReadReq:
      return sbp_msg_fileio_read_req_encode(buf, len, n_written,
                                            &msg->fileio_read_req);
    case SbpMsgFileioReadResp:
      return sbp_msg_fileio_read_resp_encode(buf, len, n_written,
                                             &msg->fileio_read_resp);
    case SbpMsgFileioRemove:
      return sbp_msg_fileio_remove_encode(buf, len, n_written,
                                          &msg->fileio_remove);
    case SbpMsgFileioWriteReq:
      return sbp_msg_fileio_write_req_encode(buf, len, n_written,
                                             &msg->fileio_write_req);
    case SbpMsgFileioWriteResp:
      return sbp_msg_fileio_write_resp_encode(buf, len, n_written,
                                              &msg->fileio_write_resp);
    case SbpMsgFlashDone:
      return sbp_msg_flash_done_encode(buf, len, n_written, &msg->flash_done);
    case SbpMsgFlashErase:
      return sbp_msg_flash_erase_encode(buf, len, n_written, &msg->flash_erase);
    case SbpMsgFlashProgram:
      return sbp_msg_flash_program_encode(buf, len, n_written,
                                          &msg->flash_program);
    case SbpMsgFlashReadReq:
      return sbp_msg_flash_read_req_encode(buf, len, n_written,
                                           &msg->flash_read_req);
    case SbpMsgFlashReadResp:
      return sbp_msg_flash_read_resp_encode(buf, len, n_written,
                                            &msg->flash_read_resp);
    case SbpMsgFrontEndGain:
      return sbp_msg_front_end_gain_encode(buf, len, n_written,
                                           &msg->front_end_gain);
    case SbpMsgFwd:
      return sbp_msg_fwd_encode(buf, len, n_written, &msg->fwd);
    case SbpMsgGloBiases:
      return sbp_msg_glo_biases_encode(buf, len, n_written, &msg->glo_biases);
    case SbpMsgGnssCapb:
      return sbp_msg_gnss_capb_encode(buf, len, n_written, &msg->gnss_capb);
    case SbpMsgGnssTimeOffset:
      return sbp_msg_gnss_time_offset_encode(buf, len, n_written,
                                             &msg->gnss_time_offset);
    case SbpMsgGpsTimeDepA:
      return sbp_msg_gps_time_dep_a_encode(buf, len, n_written,
                                           &msg->gps_time_dep_a);
    case SbpMsgGpsTimeGnss:
      return sbp_msg_gps_time_gnss_encode(buf, len, n_written,
                                          &msg->gps_time_gnss);
    case SbpMsgGpsTime:
      return sbp_msg_gps_time_encode(buf, len, n_written, &msg->gps_time);
    case SbpMsgGroupDelayDepA:
      return sbp_msg_group_delay_dep_a_encode(buf, len, n_written,
                                              &msg->group_delay_dep_a);
    case SbpMsgGroupDelayDepB:
      return sbp_msg_group_delay_dep_b_encode(buf, len, n_written,
                                              &msg->group_delay_dep_b);
    case SbpMsgGroupDelay:
      return sbp_msg_group_delay_encode(buf, len, n_written, &msg->group_delay);
    case SbpMsgGroupMeta:
      return sbp_msg_group_meta_encode(buf, len, n_written, &msg->group_meta);
    case SbpMsgHeartbeat:
      return sbp_msg_heartbeat_encode(buf, len, n_written, &msg->heartbeat);
    case SbpMsgIarState:
      return sbp_msg_iar_state_encode(buf, len, n_written, &msg->iar_state);
    case SbpMsgImuAux:
      return sbp_msg_imu_aux_encode(buf, len, n_written, &msg->imu_aux);
    case SbpMsgImuRaw:
      return sbp_msg_imu_raw_encode(buf, len, n_written, &msg->imu_raw);
    case SbpMsgInitBaseDep:
      return sbp_msg_init_base_dep_encode(buf, len, n_written,
                                          &msg->init_base_dep);
    case SbpMsgInsStatus:
      return sbp_msg_ins_status_encode(buf, len, n_written, &msg->ins_status);
    case SbpMsgInsUpdates:
      return sbp_msg_ins_updates_encode(buf, len, n_written, &msg->ins_updates);
    case SbpMsgIono:
      return sbp_msg_iono_encode(buf, len, n_written, &msg->iono);
    case SbpMsgLinuxCpuStateDepA:
      return sbp_msg_linux_cpu_state_dep_a_encode(buf, len, n_written,
                                                  &msg->linux_cpu_state_dep_a);
    case SbpMsgLinuxCpuState:
      return sbp_msg_linux_cpu_state_encode(buf, len, n_written,
                                            &msg->linux_cpu_state);
    case SbpMsgLinuxMemStateDepA:
      return sbp_msg_linux_mem_state_dep_a_encode(buf, len, n_written,
                                                  &msg->linux_mem_state_dep_a);
    case SbpMsgLinuxMemState:
      return sbp_msg_linux_mem_state_encode(buf, len, n_written,
                                            &msg->linux_mem_state);
    case SbpMsgLinuxProcessFdCount:
      return sbp_msg_linux_process_fd_count_encode(
          buf, len, n_written, &msg->linux_process_fd_count);
    case SbpMsgLinuxProcessFdSummary:
      return sbp_msg_linux_process_fd_summary_encode(
          buf, len, n_written, &msg->linux_process_fd_summary);
    case SbpMsgLinuxProcessSocketCounts:
      return sbp_msg_linux_process_socket_counts_encode(
          buf, len, n_written, &msg->linux_process_socket_counts);
    case SbpMsgLinuxProcessSocketQueues:
      return sbp_msg_linux_process_socket_queues_encode(
          buf, len, n_written, &msg->linux_process_socket_queues);
    case SbpMsgLinuxSocketUsage:
      return sbp_msg_linux_socket_usage_encode(buf, len, n_written,
                                               &msg->linux_socket_usage);
    case SbpMsgLinuxSysStateDepA:
      return sbp_msg_linux_sys_state_dep_a_encode(buf, len, n_written,
                                                  &msg->linux_sys_state_dep_a);
    case SbpMsgLinuxSysState:
      return sbp_msg_linux_sys_state_encode(buf, len, n_written,
                                            &msg->linux_sys_state);
    case SbpMsgLog:
      return sbp_msg_log_encode(buf, len, n_written, &msg->log);
    case SbpMsgM25FlashWriteStatus:
      return sbp_msg_m25_flash_write_status_encode(
          buf, len, n_written, &msg->m25_flash_write_status);
    case SbpMsgMagRaw:
      return sbp_msg_mag_raw_encode(buf, len, n_written, &msg->mag_raw);
    case SbpMsgMaskSatelliteDep:
      return sbp_msg_mask_satellite_dep_encode(buf, len, n_written,
                                               &msg->mask_satellite_dep);
    case SbpMsgMaskSatellite:
      return sbp_msg_mask_satellite_encode(buf, len, n_written,
                                           &msg->mask_satellite);
    case SbpMsgMeasurementState:
      return sbp_msg_measurement_state_encode(buf, len, n_written,
                                              &msg->measurement_state);
    case SbpMsgNapDeviceDnaReq:
      return sbp_msg_nap_device_dna_req_encode(buf, len, n_written,
                                               &msg->nap_device_dna_req);
    case SbpMsgNapDeviceDnaResp:
      return sbp_msg_nap_device_dna_resp_encode(buf, len, n_written,
                                                &msg->nap_device_dna_resp);
    case SbpMsgNdbEvent:
      return sbp_msg_ndb_event_encode(buf, len, n_written, &msg->ndb_event);
    case SbpMsgNetworkBandwidthUsage:
      return sbp_msg_network_bandwidth_usage_encode(
          buf, len, n_written, &msg->network_bandwidth_usage);
    case SbpMsgNetworkStateReq:
      return sbp_msg_network_state_req_encode(buf, len, n_written,
                                              &msg->network_state_req);
    case SbpMsgNetworkStateResp:
      return sbp_msg_network_state_resp_encode(buf, len, n_written,
                                               &msg->network_state_resp);
    case SbpMsgObsDepA:
      return sbp_msg_obs_dep_a_encode(buf, len, n_written, &msg->obs_dep_a);
    case SbpMsgObsDepB:
      return sbp_msg_obs_dep_b_encode(buf, len, n_written, &msg->obs_dep_b);
    case SbpMsgObsDepC:
      return sbp_msg_obs_dep_c_encode(buf, len, n_written, &msg->obs_dep_c);
    case SbpMsgObs:
      return sbp_msg_obs_encode(buf, len, n_written, &msg->obs);
    case SbpMsgOdometry:
      return sbp_msg_odometry_encode(buf, len, n_written, &msg->odometry);
    case SbpMsgOrientEuler:
      return sbp_msg_orient_euler_encode(buf, len, n_written,
                                         &msg->orient_euler);
    case SbpMsgOrientQuat:
      return sbp_msg_orient_quat_encode(buf, len, n_written, &msg->orient_quat);
    case SbpMsgOsr:
      return sbp_msg_osr_encode(buf, len, n_written, &msg->osr);
    case SbpMsgPosEcefCovGnss:
      return sbp_msg_pos_ecef_cov_gnss_encode(buf, len, n_written,
                                              &msg->pos_ecef_cov_gnss);
    case SbpMsgPosEcefCov:
      return sbp_msg_pos_ecef_cov_encode(buf, len, n_written,
                                         &msg->pos_ecef_cov);
    case SbpMsgPosEcefDepA:
      return sbp_msg_pos_ecef_dep_a_encode(buf, len, n_written,
                                           &msg->pos_ecef_dep_a);
    case SbpMsgPosEcefGnss:
      return sbp_msg_pos_ecef_gnss_encode(buf, len, n_written,
                                          &msg->pos_ecef_gnss);
    case SbpMsgPosEcef:
      return sbp_msg_pos_ecef_encode(buf, len, n_written, &msg->pos_ecef);
    case SbpMsgPosLlhAcc:
      return sbp_msg_pos_llh_acc_encode(buf, len, n_written, &msg->pos_llh_acc);
    case SbpMsgPosLlhCovGnss:
      return sbp_msg_pos_llh_cov_gnss_encode(buf, len, n_written,
                                             &msg->pos_llh_cov_gnss);
    case SbpMsgPosLlhCov:
      return sbp_msg_pos_llh_cov_encode(buf, len, n_written, &msg->pos_llh_cov);
    case SbpMsgPosLlhDepA:
      return sbp_msg_pos_llh_dep_a_encode(buf, len, n_written,
                                          &msg->pos_llh_dep_a);
    case SbpMsgPosLlhGnss:
      return sbp_msg_pos_llh_gnss_encode(buf, len, n_written,
                                         &msg->pos_llh_gnss);
    case SbpMsgPosLlh:
      return sbp_msg_pos_llh_encode(buf, len, n_written, &msg->pos_llh);
    case SbpMsgPpsTime:
      return sbp_msg_pps_time_encode(buf, len, n_written, &msg->pps_time);
    case SbpMsgPrintDep:
      return sbp_msg_print_dep_encode(buf, len, n_written, &msg->print_dep);
    case SbpMsgProtectionLevelDepA:
      return sbp_msg_protection_level_dep_a_encode(
          buf, len, n_written, &msg->protection_level_dep_a);
    case SbpMsgProtectionLevel:
      return sbp_msg_protection_level_encode(buf, len, n_written,
                                             &msg->protection_level);
    case SbpMsgResetDep:
      return sbp_msg_reset_dep_encode(buf, len, n_written, &msg->reset_dep);
    case SbpMsgResetFilters:
      return sbp_msg_reset_filters_encode(buf, len, n_written,
                                          &msg->reset_filters);
    case SbpMsgReset:
      return sbp_msg_reset_encode(buf, len, n_written, &msg->reset);
    case SbpMsgSbasRaw:
      return sbp_msg_sbas_raw_encode(buf, len, n_written, &msg->sbas_raw);
    case SbpMsgSetTime:
      return sbp_msg_set_time_encode(buf, len, n_written, &msg->set_time);
    case SbpMsgSettingsReadByIndexDone:
      return sbp_msg_settings_read_by_index_done_encode(
          buf, len, n_written, &msg->settings_read_by_index_done);
    case SbpMsgSettingsReadByIndexReq:
      return sbp_msg_settings_read_by_index_req_encode(
          buf, len, n_written, &msg->settings_read_by_index_req);
    case SbpMsgSettingsReadByIndexResp:
      return sbp_msg_settings_read_by_index_resp_encode(
          buf, len, n_written, &msg->settings_read_by_index_resp);
    case SbpMsgSettingsReadReq:
      return sbp_msg_settings_read_req_encode(buf, len, n_written,
                                              &msg->settings_read_req);
    case SbpMsgSettingsReadResp:
      return sbp_msg_settings_read_resp_encode(buf, len, n_written,
                                               &msg->settings_read_resp);
    case SbpMsgSettingsRegisterResp:
      return sbp_msg_settings_register_resp_encode(
          buf, len, n_written, &msg->settings_register_resp);
    case SbpMsgSettingsRegister:
      return sbp_msg_settings_register_encode(buf, len, n_written,
                                              &msg->settings_register);
    case SbpMsgSettingsSave:
      return sbp_msg_settings_save_encode(buf, len, n_written,
                                          &msg->settings_save);
    case SbpMsgSettingsWriteResp:
      return sbp_msg_settings_write_resp_encode(buf, len, n_written,
                                                &msg->settings_write_resp);
    case SbpMsgSettingsWrite:
      return sbp_msg_settings_write_encode(buf, len, n_written,
                                           &msg->settings_write);
    case SbpMsgSolnMetaDepA:
      return sbp_msg_soln_meta_dep_a_encode(buf, len, n_written,
                                            &msg->soln_meta_dep_a);
    case SbpMsgSolnMeta:
      return sbp_msg_soln_meta_encode(buf, len, n_written, &msg->soln_meta);
    case SbpMsgSpecanDep:
      return sbp_msg_specan_dep_encode(buf, len, n_written, &msg->specan_dep);
    case SbpMsgSpecan:
      return sbp_msg_specan_encode(buf, len, n_written, &msg->specan);
    case SbpMsgSsrCodeBiases:
      return sbp_msg_ssr_code_biases_encode(buf, len, n_written,
                                            &msg->ssr_code_biases);
    case SbpMsgSsrGridDefinitionDepA:
      return sbp_msg_ssr_grid_definition_dep_a_encode(
          buf, len, n_written, &msg->ssr_grid_definition_dep_a);
    case SbpMsgSsrGriddedCorrectionDepA:
      return sbp_msg_ssr_gridded_correction_dep_a_encode(
          buf, len, n_written, &msg->ssr_gridded_correction_dep_a);
    case SbpMsgSsrGriddedCorrectionNoStdDepA:
      return sbp_msg_ssr_gridded_correction_no_std_dep_a_encode(
          buf, len, n_written, &msg->ssr_gridded_correction_no_std_dep_a);
    case SbpMsgSsrGriddedCorrection:
      return sbp_msg_ssr_gridded_correction_encode(
          buf, len, n_written, &msg->ssr_gridded_correction);
    case SbpMsgSsrOrbitClockDepA:
      return sbp_msg_ssr_orbit_clock_dep_a_encode(buf, len, n_written,
                                                  &msg->ssr_orbit_clock_dep_a);
    case SbpMsgSsrOrbitClock:
      return sbp_msg_ssr_orbit_clock_encode(buf, len, n_written,
                                            &msg->ssr_orbit_clock);
    case SbpMsgSsrPhaseBiases:
      return sbp_msg_ssr_phase_biases_encode(buf, len, n_written,
                                             &msg->ssr_phase_biases);
    case SbpMsgSsrSatelliteApc:
      return sbp_msg_ssr_satellite_apc_encode(buf, len, n_written,
                                              &msg->ssr_satellite_apc);
    case SbpMsgSsrStecCorrectionDepA:
      return sbp_msg_ssr_stec_correction_dep_a_encode(
          buf, len, n_written, &msg->ssr_stec_correction_dep_a);
    case SbpMsgSsrStecCorrection:
      return sbp_msg_ssr_stec_correction_encode(buf, len, n_written,
                                                &msg->ssr_stec_correction);
    case SbpMsgSsrTileDefinition:
      return sbp_msg_ssr_tile_definition_encode(buf, len, n_written,
                                                &msg->ssr_tile_definition);
    case SbpMsgStartup:
      return sbp_msg_startup_encode(buf, len, n_written, &msg->startup);
    case SbpMsgStatusReport:
      return sbp_msg_status_report_encode(buf, len, n_written,
                                          &msg->status_report);
    case SbpMsgStmFlashLockSector:
      return sbp_msg_stm_flash_lock_sector_encode(buf, len, n_written,
                                                  &msg->stm_flash_lock_sector);
    case SbpMsgStmFlashUnlockSector:
      return sbp_msg_stm_flash_unlock_sector_encode(
          buf, len, n_written, &msg->stm_flash_unlock_sector);
    case SbpMsgStmUniqueIdReq:
      return sbp_msg_stm_unique_id_req_encode(buf, len, n_written,
                                              &msg->stm_unique_id_req);
    case SbpMsgStmUniqueIdResp:
      return sbp_msg_stm_unique_id_resp_encode(buf, len, n_written,
                                               &msg->stm_unique_id_resp);
    case SbpMsgSvAzEl:
      return sbp_msg_sv_az_el_encode(buf, len, n_written, &msg->sv_az_el);
    case SbpMsgSvConfigurationGpsDep:
      return sbp_msg_sv_configuration_gps_dep_encode(
          buf, len, n_written, &msg->sv_configuration_gps_dep);
    case SbpMsgThreadState:
      return sbp_msg_thread_state_encode(buf, len, n_written,
                                         &msg->thread_state);
    case SbpMsgTrackingIqDepA:
      return sbp_msg_tracking_iq_dep_a_encode(buf, len, n_written,
                                              &msg->tracking_iq_dep_a);
    case SbpMsgTrackingIqDepB:
      return sbp_msg_tracking_iq_dep_b_encode(buf, len, n_written,
                                              &msg->tracking_iq_dep_b);
    case SbpMsgTrackingIq:
      return sbp_msg_tracking_iq_encode(buf, len, n_written, &msg->tracking_iq);
    case SbpMsgTrackingStateDepA:
      return sbp_msg_tracking_state_dep_a_encode(buf, len, n_written,
                                                 &msg->tracking_state_dep_a);
    case SbpMsgTrackingStateDepB:
      return sbp_msg_tracking_state_dep_b_encode(buf, len, n_written,
                                                 &msg->tracking_state_dep_b);
    case SbpMsgTrackingStateDetailedDepA:
      return sbp_msg_tracking_state_detailed_dep_a_encode(
          buf, len, n_written, &msg->tracking_state_detailed_dep_a);
    case SbpMsgTrackingStateDetailedDep:
      return sbp_msg_tracking_state_detailed_dep_encode(
          buf, len, n_written, &msg->tracking_state_detailed_dep);
    case SbpMsgTrackingState:
      return sbp_msg_tracking_state_encode(buf, len, n_written,
                                           &msg->tracking_state);
    case SbpMsgUartStateDepa:
      return sbp_msg_uart_state_depa_encode(buf, len, n_written,
                                            &msg->uart_state_depa);
    case SbpMsgUartState:
      return sbp_msg_uart_state_encode(buf, len, n_written, &msg->uart_state);
    case SbpMsgUserData:
      return sbp_msg_user_data_encode(buf, len, n_written, &msg->user_data);
    case SbpMsgUtcTimeGnss:
      return sbp_msg_utc_time_gnss_encode(buf, len, n_written,
                                          &msg->utc_time_gnss);
    case SbpMsgUtcTime:
      return sbp_msg_utc_time_encode(buf, len, n_written, &msg->utc_time);
    case SbpMsgVelBody:
      return sbp_msg_vel_body_encode(buf, len, n_written, &msg->vel_body);
    case SbpMsgVelCog:
      return sbp_msg_vel_cog_encode(buf, len, n_written, &msg->vel_cog);
    case SbpMsgVelEcefCovGnss:
      return sbp_msg_vel_ecef_cov_gnss_encode(buf, len, n_written,
                                              &msg->vel_ecef_cov_gnss);
    case SbpMsgVelEcefCov:
      return sbp_msg_vel_ecef_cov_encode(buf, len, n_written,
                                         &msg->vel_ecef_cov);
    case SbpMsgVelEcefDepA:
      return sbp_msg_vel_ecef_dep_a_encode(buf, len, n_written,
                                           &msg->vel_ecef_dep_a);
    case SbpMsgVelEcefGnss:
      return sbp_msg_vel_ecef_gnss_encode(buf, len, n_written,
                                          &msg->vel_ecef_gnss);
    case SbpMsgVelEcef:
      return sbp_msg_vel_ecef_encode(buf, len, n_written, &msg->vel_ecef);
    case SbpMsgVelNedCovGnss:
      return sbp_msg_vel_ned_cov_gnss_encode(buf, len, n_written,
                                             &msg->vel_ned_cov_gnss);
    case SbpMsgVelNedCov:
      return sbp_msg_vel_ned_cov_encode(buf, len, n_written, &msg->vel_ned_cov);
    case SbpMsgVelNedDepA:
      return sbp_msg_vel_ned_dep_a_encode(buf, len, n_written,
                                          &msg->vel_ned_dep_a);
    case SbpMsgVelNedGnss:
      return sbp_msg_vel_ned_gnss_encode(buf, len, n_written,
                                         &msg->vel_ned_gnss);
    case SbpMsgVelNed:
      return sbp_msg_vel_ned_encode(buf, len, n_written, &msg->vel_ned);
    case SbpMsgWheeltick:
      return sbp_msg_wheeltick_encode(buf, len, n_written, &msg->wheeltick);
    default:
      break;
  }
  return -1;
}

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
static inline s8 sbp_message_decode(const uint8_t *buf, uint8_t len,
                                    uint8_t *n_read, sbp_msg_type_t msg_type,
                                    sbp_msg_t *msg) {
  switch (msg_type) {
    case SbpMsgAcqResultDepA:
      return sbp_msg_acq_result_dep_a_decode(buf, len, n_read,
                                             &msg->acq_result_dep_a);
    case SbpMsgAcqResultDepB:
      return sbp_msg_acq_result_dep_b_decode(buf, len, n_read,
                                             &msg->acq_result_dep_b);
    case SbpMsgAcqResultDepC:
      return sbp_msg_acq_result_dep_c_decode(buf, len, n_read,
                                             &msg->acq_result_dep_c);
    case SbpMsgAcqResult:
      return sbp_msg_acq_result_decode(buf, len, n_read, &msg->acq_result);
    case SbpMsgAcqSvProfileDep:
      return sbp_msg_acq_sv_profile_dep_decode(buf, len, n_read,
                                               &msg->acq_sv_profile_dep);
    case SbpMsgAcqSvProfile:
      return sbp_msg_acq_sv_profile_decode(buf, len, n_read,
                                           &msg->acq_sv_profile);
    case SbpMsgAgeCorrections:
      return sbp_msg_age_corrections_decode(buf, len, n_read,
                                            &msg->age_corrections);
    case SbpMsgAlmanacGloDep:
      return sbp_msg_almanac_glo_dep_decode(buf, len, n_read,
                                            &msg->almanac_glo_dep);
    case SbpMsgAlmanacGlo:
      return sbp_msg_almanac_glo_decode(buf, len, n_read, &msg->almanac_glo);
    case SbpMsgAlmanacGpsDep:
      return sbp_msg_almanac_gps_dep_decode(buf, len, n_read,
                                            &msg->almanac_gps_dep);
    case SbpMsgAlmanacGps:
      return sbp_msg_almanac_gps_decode(buf, len, n_read, &msg->almanac_gps);
    case SbpMsgAlmanac:
      return sbp_msg_almanac_decode(buf, len, n_read, &msg->almanac);
    case SbpMsgAngularRate:
      return sbp_msg_angular_rate_decode(buf, len, n_read, &msg->angular_rate);
    case SbpMsgBasePosEcef:
      return sbp_msg_base_pos_ecef_decode(buf, len, n_read,
                                          &msg->base_pos_ecef);
    case SbpMsgBasePosLlh:
      return sbp_msg_base_pos_llh_decode(buf, len, n_read, &msg->base_pos_llh);
    case SbpMsgBaselineEcefDepA:
      return sbp_msg_baseline_ecef_dep_a_decode(buf, len, n_read,
                                                &msg->baseline_ecef_dep_a);
    case SbpMsgBaselineEcef:
      return sbp_msg_baseline_ecef_decode(buf, len, n_read,
                                          &msg->baseline_ecef);
    case SbpMsgBaselineHeadingDepA:
      return sbp_msg_baseline_heading_dep_a_decode(
          buf, len, n_read, &msg->baseline_heading_dep_a);
    case SbpMsgBaselineHeading:
      return sbp_msg_baseline_heading_decode(buf, len, n_read,
                                             &msg->baseline_heading);
    case SbpMsgBaselineNedDepA:
      return sbp_msg_baseline_ned_dep_a_decode(buf, len, n_read,
                                               &msg->baseline_ned_dep_a);
    case SbpMsgBaselineNed:
      return sbp_msg_baseline_ned_decode(buf, len, n_read, &msg->baseline_ned);
    case SbpMsgBootloaderHandshakeDepA:
      return sbp_msg_bootloader_handshake_dep_a_decode(
          buf, len, n_read, &msg->bootloader_handshake_dep_a);
    case SbpMsgBootloaderHandshakeReq:
      return sbp_msg_bootloader_handshake_req_decode(
          buf, len, n_read, &msg->bootloader_handshake_req);
    case SbpMsgBootloaderHandshakeResp:
      return sbp_msg_bootloader_handshake_resp_decode(
          buf, len, n_read, &msg->bootloader_handshake_resp);
    case SbpMsgBootloaderJumpToApp:
      return sbp_msg_bootloader_jump_to_app_decode(
          buf, len, n_read, &msg->bootloader_jump_to_app);
    case SbpMsgCellModemStatus:
      return sbp_msg_cell_modem_status_decode(buf, len, n_read,
                                              &msg->cell_modem_status);
    case SbpMsgCommandOutput:
      return sbp_msg_command_output_decode(buf, len, n_read,
                                           &msg->command_output);
    case SbpMsgCommandReq:
      return sbp_msg_command_req_decode(buf, len, n_read, &msg->command_req);
    case SbpMsgCommandResp:
      return sbp_msg_command_resp_decode(buf, len, n_read, &msg->command_resp);
    case SbpMsgCsacTelemetryLabels:
      return sbp_msg_csac_telemetry_labels_decode(buf, len, n_read,
                                                  &msg->csac_telemetry_labels);
    case SbpMsgCsacTelemetry:
      return sbp_msg_csac_telemetry_decode(buf, len, n_read,
                                           &msg->csac_telemetry);
    case SbpMsgCwResults:
      return sbp_msg_cw_results_decode(buf, len, n_read, &msg->cw_results);
    case SbpMsgCwStart:
      return sbp_msg_cw_start_decode(buf, len, n_read, &msg->cw_start);
    case SbpMsgDeviceMonitor:
      return sbp_msg_device_monitor_decode(buf, len, n_read,
                                           &msg->device_monitor);
    case SbpMsgDgnssStatus:
      return sbp_msg_dgnss_status_decode(buf, len, n_read, &msg->dgnss_status);
    case SbpMsgDopsDepA:
      return sbp_msg_dops_dep_a_decode(buf, len, n_read, &msg->dops_dep_a);
    case SbpMsgDops:
      return sbp_msg_dops_decode(buf, len, n_read, &msg->dops);
    case SbpMsgEphemerisBds:
      return sbp_msg_ephemeris_bds_decode(buf, len, n_read,
                                          &msg->ephemeris_bds);
    case SbpMsgEphemerisDepA:
      return sbp_msg_ephemeris_dep_a_decode(buf, len, n_read,
                                            &msg->ephemeris_dep_a);
    case SbpMsgEphemerisDepB:
      return sbp_msg_ephemeris_dep_b_decode(buf, len, n_read,
                                            &msg->ephemeris_dep_b);
    case SbpMsgEphemerisDepC:
      return sbp_msg_ephemeris_dep_c_decode(buf, len, n_read,
                                            &msg->ephemeris_dep_c);
    case SbpMsgEphemerisDepD:
      return sbp_msg_ephemeris_dep_d_decode(buf, len, n_read,
                                            &msg->ephemeris_dep_d);
    case SbpMsgEphemerisGalDepA:
      return sbp_msg_ephemeris_gal_dep_a_decode(buf, len, n_read,
                                                &msg->ephemeris_gal_dep_a);
    case SbpMsgEphemerisGal:
      return sbp_msg_ephemeris_gal_decode(buf, len, n_read,
                                          &msg->ephemeris_gal);
    case SbpMsgEphemerisGloDepA:
      return sbp_msg_ephemeris_glo_dep_a_decode(buf, len, n_read,
                                                &msg->ephemeris_glo_dep_a);
    case SbpMsgEphemerisGloDepB:
      return sbp_msg_ephemeris_glo_dep_b_decode(buf, len, n_read,
                                                &msg->ephemeris_glo_dep_b);
    case SbpMsgEphemerisGloDepC:
      return sbp_msg_ephemeris_glo_dep_c_decode(buf, len, n_read,
                                                &msg->ephemeris_glo_dep_c);
    case SbpMsgEphemerisGloDepD:
      return sbp_msg_ephemeris_glo_dep_d_decode(buf, len, n_read,
                                                &msg->ephemeris_glo_dep_d);
    case SbpMsgEphemerisGlo:
      return sbp_msg_ephemeris_glo_decode(buf, len, n_read,
                                          &msg->ephemeris_glo);
    case SbpMsgEphemerisGpsDepE:
      return sbp_msg_ephemeris_gps_dep_e_decode(buf, len, n_read,
                                                &msg->ephemeris_gps_dep_e);
    case SbpMsgEphemerisGpsDepF:
      return sbp_msg_ephemeris_gps_dep_f_decode(buf, len, n_read,
                                                &msg->ephemeris_gps_dep_f);
    case SbpMsgEphemerisGps:
      return sbp_msg_ephemeris_gps_decode(buf, len, n_read,
                                          &msg->ephemeris_gps);
    case SbpMsgEphemerisQzss:
      return sbp_msg_ephemeris_qzss_decode(buf, len, n_read,
                                           &msg->ephemeris_qzss);
    case SbpMsgEphemerisSbasDepA:
      return sbp_msg_ephemeris_sbas_dep_a_decode(buf, len, n_read,
                                                 &msg->ephemeris_sbas_dep_a);
    case SbpMsgEphemerisSbasDepB:
      return sbp_msg_ephemeris_sbas_dep_b_decode(buf, len, n_read,
                                                 &msg->ephemeris_sbas_dep_b);
    case SbpMsgEphemerisSbas:
      return sbp_msg_ephemeris_sbas_decode(buf, len, n_read,
                                           &msg->ephemeris_sbas);
    case SbpMsgExtEvent:
      return sbp_msg_ext_event_decode(buf, len, n_read, &msg->ext_event);
    case SbpMsgFileioConfigReq:
      return sbp_msg_fileio_config_req_decode(buf, len, n_read,
                                              &msg->fileio_config_req);
    case SbpMsgFileioConfigResp:
      return sbp_msg_fileio_config_resp_decode(buf, len, n_read,
                                               &msg->fileio_config_resp);
    case SbpMsgFileioReadDirReq:
      return sbp_msg_fileio_read_dir_req_decode(buf, len, n_read,
                                                &msg->fileio_read_dir_req);
    case SbpMsgFileioReadDirResp:
      return sbp_msg_fileio_read_dir_resp_decode(buf, len, n_read,
                                                 &msg->fileio_read_dir_resp);
    case SbpMsgFileioReadReq:
      return sbp_msg_fileio_read_req_decode(buf, len, n_read,
                                            &msg->fileio_read_req);
    case SbpMsgFileioReadResp:
      return sbp_msg_fileio_read_resp_decode(buf, len, n_read,
                                             &msg->fileio_read_resp);
    case SbpMsgFileioRemove:
      return sbp_msg_fileio_remove_decode(buf, len, n_read,
                                          &msg->fileio_remove);
    case SbpMsgFileioWriteReq:
      return sbp_msg_fileio_write_req_decode(buf, len, n_read,
                                             &msg->fileio_write_req);
    case SbpMsgFileioWriteResp:
      return sbp_msg_fileio_write_resp_decode(buf, len, n_read,
                                              &msg->fileio_write_resp);
    case SbpMsgFlashDone:
      return sbp_msg_flash_done_decode(buf, len, n_read, &msg->flash_done);
    case SbpMsgFlashErase:
      return sbp_msg_flash_erase_decode(buf, len, n_read, &msg->flash_erase);
    case SbpMsgFlashProgram:
      return sbp_msg_flash_program_decode(buf, len, n_read,
                                          &msg->flash_program);
    case SbpMsgFlashReadReq:
      return sbp_msg_flash_read_req_decode(buf, len, n_read,
                                           &msg->flash_read_req);
    case SbpMsgFlashReadResp:
      return sbp_msg_flash_read_resp_decode(buf, len, n_read,
                                            &msg->flash_read_resp);
    case SbpMsgFrontEndGain:
      return sbp_msg_front_end_gain_decode(buf, len, n_read,
                                           &msg->front_end_gain);
    case SbpMsgFwd:
      return sbp_msg_fwd_decode(buf, len, n_read, &msg->fwd);
    case SbpMsgGloBiases:
      return sbp_msg_glo_biases_decode(buf, len, n_read, &msg->glo_biases);
    case SbpMsgGnssCapb:
      return sbp_msg_gnss_capb_decode(buf, len, n_read, &msg->gnss_capb);
    case SbpMsgGnssTimeOffset:
      return sbp_msg_gnss_time_offset_decode(buf, len, n_read,
                                             &msg->gnss_time_offset);
    case SbpMsgGpsTimeDepA:
      return sbp_msg_gps_time_dep_a_decode(buf, len, n_read,
                                           &msg->gps_time_dep_a);
    case SbpMsgGpsTimeGnss:
      return sbp_msg_gps_time_gnss_decode(buf, len, n_read,
                                          &msg->gps_time_gnss);
    case SbpMsgGpsTime:
      return sbp_msg_gps_time_decode(buf, len, n_read, &msg->gps_time);
    case SbpMsgGroupDelayDepA:
      return sbp_msg_group_delay_dep_a_decode(buf, len, n_read,
                                              &msg->group_delay_dep_a);
    case SbpMsgGroupDelayDepB:
      return sbp_msg_group_delay_dep_b_decode(buf, len, n_read,
                                              &msg->group_delay_dep_b);
    case SbpMsgGroupDelay:
      return sbp_msg_group_delay_decode(buf, len, n_read, &msg->group_delay);
    case SbpMsgGroupMeta:
      return sbp_msg_group_meta_decode(buf, len, n_read, &msg->group_meta);
    case SbpMsgHeartbeat:
      return sbp_msg_heartbeat_decode(buf, len, n_read, &msg->heartbeat);
    case SbpMsgIarState:
      return sbp_msg_iar_state_decode(buf, len, n_read, &msg->iar_state);
    case SbpMsgImuAux:
      return sbp_msg_imu_aux_decode(buf, len, n_read, &msg->imu_aux);
    case SbpMsgImuRaw:
      return sbp_msg_imu_raw_decode(buf, len, n_read, &msg->imu_raw);
    case SbpMsgInitBaseDep:
      return sbp_msg_init_base_dep_decode(buf, len, n_read,
                                          &msg->init_base_dep);
    case SbpMsgInsStatus:
      return sbp_msg_ins_status_decode(buf, len, n_read, &msg->ins_status);
    case SbpMsgInsUpdates:
      return sbp_msg_ins_updates_decode(buf, len, n_read, &msg->ins_updates);
    case SbpMsgIono:
      return sbp_msg_iono_decode(buf, len, n_read, &msg->iono);
    case SbpMsgLinuxCpuStateDepA:
      return sbp_msg_linux_cpu_state_dep_a_decode(buf, len, n_read,
                                                  &msg->linux_cpu_state_dep_a);
    case SbpMsgLinuxCpuState:
      return sbp_msg_linux_cpu_state_decode(buf, len, n_read,
                                            &msg->linux_cpu_state);
    case SbpMsgLinuxMemStateDepA:
      return sbp_msg_linux_mem_state_dep_a_decode(buf, len, n_read,
                                                  &msg->linux_mem_state_dep_a);
    case SbpMsgLinuxMemState:
      return sbp_msg_linux_mem_state_decode(buf, len, n_read,
                                            &msg->linux_mem_state);
    case SbpMsgLinuxProcessFdCount:
      return sbp_msg_linux_process_fd_count_decode(
          buf, len, n_read, &msg->linux_process_fd_count);
    case SbpMsgLinuxProcessFdSummary:
      return sbp_msg_linux_process_fd_summary_decode(
          buf, len, n_read, &msg->linux_process_fd_summary);
    case SbpMsgLinuxProcessSocketCounts:
      return sbp_msg_linux_process_socket_counts_decode(
          buf, len, n_read, &msg->linux_process_socket_counts);
    case SbpMsgLinuxProcessSocketQueues:
      return sbp_msg_linux_process_socket_queues_decode(
          buf, len, n_read, &msg->linux_process_socket_queues);
    case SbpMsgLinuxSocketUsage:
      return sbp_msg_linux_socket_usage_decode(buf, len, n_read,
                                               &msg->linux_socket_usage);
    case SbpMsgLinuxSysStateDepA:
      return sbp_msg_linux_sys_state_dep_a_decode(buf, len, n_read,
                                                  &msg->linux_sys_state_dep_a);
    case SbpMsgLinuxSysState:
      return sbp_msg_linux_sys_state_decode(buf, len, n_read,
                                            &msg->linux_sys_state);
    case SbpMsgLog:
      return sbp_msg_log_decode(buf, len, n_read, &msg->log);
    case SbpMsgM25FlashWriteStatus:
      return sbp_msg_m25_flash_write_status_decode(
          buf, len, n_read, &msg->m25_flash_write_status);
    case SbpMsgMagRaw:
      return sbp_msg_mag_raw_decode(buf, len, n_read, &msg->mag_raw);
    case SbpMsgMaskSatelliteDep:
      return sbp_msg_mask_satellite_dep_decode(buf, len, n_read,
                                               &msg->mask_satellite_dep);
    case SbpMsgMaskSatellite:
      return sbp_msg_mask_satellite_decode(buf, len, n_read,
                                           &msg->mask_satellite);
    case SbpMsgMeasurementState:
      return sbp_msg_measurement_state_decode(buf, len, n_read,
                                              &msg->measurement_state);
    case SbpMsgNapDeviceDnaReq:
      return sbp_msg_nap_device_dna_req_decode(buf, len, n_read,
                                               &msg->nap_device_dna_req);
    case SbpMsgNapDeviceDnaResp:
      return sbp_msg_nap_device_dna_resp_decode(buf, len, n_read,
                                                &msg->nap_device_dna_resp);
    case SbpMsgNdbEvent:
      return sbp_msg_ndb_event_decode(buf, len, n_read, &msg->ndb_event);
    case SbpMsgNetworkBandwidthUsage:
      return sbp_msg_network_bandwidth_usage_decode(
          buf, len, n_read, &msg->network_bandwidth_usage);
    case SbpMsgNetworkStateReq:
      return sbp_msg_network_state_req_decode(buf, len, n_read,
                                              &msg->network_state_req);
    case SbpMsgNetworkStateResp:
      return sbp_msg_network_state_resp_decode(buf, len, n_read,
                                               &msg->network_state_resp);
    case SbpMsgObsDepA:
      return sbp_msg_obs_dep_a_decode(buf, len, n_read, &msg->obs_dep_a);
    case SbpMsgObsDepB:
      return sbp_msg_obs_dep_b_decode(buf, len, n_read, &msg->obs_dep_b);
    case SbpMsgObsDepC:
      return sbp_msg_obs_dep_c_decode(buf, len, n_read, &msg->obs_dep_c);
    case SbpMsgObs:
      return sbp_msg_obs_decode(buf, len, n_read, &msg->obs);
    case SbpMsgOdometry:
      return sbp_msg_odometry_decode(buf, len, n_read, &msg->odometry);
    case SbpMsgOrientEuler:
      return sbp_msg_orient_euler_decode(buf, len, n_read, &msg->orient_euler);
    case SbpMsgOrientQuat:
      return sbp_msg_orient_quat_decode(buf, len, n_read, &msg->orient_quat);
    case SbpMsgOsr:
      return sbp_msg_osr_decode(buf, len, n_read, &msg->osr);
    case SbpMsgPosEcefCovGnss:
      return sbp_msg_pos_ecef_cov_gnss_decode(buf, len, n_read,
                                              &msg->pos_ecef_cov_gnss);
    case SbpMsgPosEcefCov:
      return sbp_msg_pos_ecef_cov_decode(buf, len, n_read, &msg->pos_ecef_cov);
    case SbpMsgPosEcefDepA:
      return sbp_msg_pos_ecef_dep_a_decode(buf, len, n_read,
                                           &msg->pos_ecef_dep_a);
    case SbpMsgPosEcefGnss:
      return sbp_msg_pos_ecef_gnss_decode(buf, len, n_read,
                                          &msg->pos_ecef_gnss);
    case SbpMsgPosEcef:
      return sbp_msg_pos_ecef_decode(buf, len, n_read, &msg->pos_ecef);
    case SbpMsgPosLlhAcc:
      return sbp_msg_pos_llh_acc_decode(buf, len, n_read, &msg->pos_llh_acc);
    case SbpMsgPosLlhCovGnss:
      return sbp_msg_pos_llh_cov_gnss_decode(buf, len, n_read,
                                             &msg->pos_llh_cov_gnss);
    case SbpMsgPosLlhCov:
      return sbp_msg_pos_llh_cov_decode(buf, len, n_read, &msg->pos_llh_cov);
    case SbpMsgPosLlhDepA:
      return sbp_msg_pos_llh_dep_a_decode(buf, len, n_read,
                                          &msg->pos_llh_dep_a);
    case SbpMsgPosLlhGnss:
      return sbp_msg_pos_llh_gnss_decode(buf, len, n_read, &msg->pos_llh_gnss);
    case SbpMsgPosLlh:
      return sbp_msg_pos_llh_decode(buf, len, n_read, &msg->pos_llh);
    case SbpMsgPpsTime:
      return sbp_msg_pps_time_decode(buf, len, n_read, &msg->pps_time);
    case SbpMsgPrintDep:
      return sbp_msg_print_dep_decode(buf, len, n_read, &msg->print_dep);
    case SbpMsgProtectionLevelDepA:
      return sbp_msg_protection_level_dep_a_decode(
          buf, len, n_read, &msg->protection_level_dep_a);
    case SbpMsgProtectionLevel:
      return sbp_msg_protection_level_decode(buf, len, n_read,
                                             &msg->protection_level);
    case SbpMsgResetDep:
      return sbp_msg_reset_dep_decode(buf, len, n_read, &msg->reset_dep);
    case SbpMsgResetFilters:
      return sbp_msg_reset_filters_decode(buf, len, n_read,
                                          &msg->reset_filters);
    case SbpMsgReset:
      return sbp_msg_reset_decode(buf, len, n_read, &msg->reset);
    case SbpMsgSbasRaw:
      return sbp_msg_sbas_raw_decode(buf, len, n_read, &msg->sbas_raw);
    case SbpMsgSetTime:
      return sbp_msg_set_time_decode(buf, len, n_read, &msg->set_time);
    case SbpMsgSettingsReadByIndexDone:
      return sbp_msg_settings_read_by_index_done_decode(
          buf, len, n_read, &msg->settings_read_by_index_done);
    case SbpMsgSettingsReadByIndexReq:
      return sbp_msg_settings_read_by_index_req_decode(
          buf, len, n_read, &msg->settings_read_by_index_req);
    case SbpMsgSettingsReadByIndexResp:
      return sbp_msg_settings_read_by_index_resp_decode(
          buf, len, n_read, &msg->settings_read_by_index_resp);
    case SbpMsgSettingsReadReq:
      return sbp_msg_settings_read_req_decode(buf, len, n_read,
                                              &msg->settings_read_req);
    case SbpMsgSettingsReadResp:
      return sbp_msg_settings_read_resp_decode(buf, len, n_read,
                                               &msg->settings_read_resp);
    case SbpMsgSettingsRegisterResp:
      return sbp_msg_settings_register_resp_decode(
          buf, len, n_read, &msg->settings_register_resp);
    case SbpMsgSettingsRegister:
      return sbp_msg_settings_register_decode(buf, len, n_read,
                                              &msg->settings_register);
    case SbpMsgSettingsSave:
      return sbp_msg_settings_save_decode(buf, len, n_read,
                                          &msg->settings_save);
    case SbpMsgSettingsWriteResp:
      return sbp_msg_settings_write_resp_decode(buf, len, n_read,
                                                &msg->settings_write_resp);
    case SbpMsgSettingsWrite:
      return sbp_msg_settings_write_decode(buf, len, n_read,
                                           &msg->settings_write);
    case SbpMsgSolnMetaDepA:
      return sbp_msg_soln_meta_dep_a_decode(buf, len, n_read,
                                            &msg->soln_meta_dep_a);
    case SbpMsgSolnMeta:
      return sbp_msg_soln_meta_decode(buf, len, n_read, &msg->soln_meta);
    case SbpMsgSpecanDep:
      return sbp_msg_specan_dep_decode(buf, len, n_read, &msg->specan_dep);
    case SbpMsgSpecan:
      return sbp_msg_specan_decode(buf, len, n_read, &msg->specan);
    case SbpMsgSsrCodeBiases:
      return sbp_msg_ssr_code_biases_decode(buf, len, n_read,
                                            &msg->ssr_code_biases);
    case SbpMsgSsrGridDefinitionDepA:
      return sbp_msg_ssr_grid_definition_dep_a_decode(
          buf, len, n_read, &msg->ssr_grid_definition_dep_a);
    case SbpMsgSsrGriddedCorrectionDepA:
      return sbp_msg_ssr_gridded_correction_dep_a_decode(
          buf, len, n_read, &msg->ssr_gridded_correction_dep_a);
    case SbpMsgSsrGriddedCorrectionNoStdDepA:
      return sbp_msg_ssr_gridded_correction_no_std_dep_a_decode(
          buf, len, n_read, &msg->ssr_gridded_correction_no_std_dep_a);
    case SbpMsgSsrGriddedCorrection:
      return sbp_msg_ssr_gridded_correction_decode(
          buf, len, n_read, &msg->ssr_gridded_correction);
    case SbpMsgSsrOrbitClockDepA:
      return sbp_msg_ssr_orbit_clock_dep_a_decode(buf, len, n_read,
                                                  &msg->ssr_orbit_clock_dep_a);
    case SbpMsgSsrOrbitClock:
      return sbp_msg_ssr_orbit_clock_decode(buf, len, n_read,
                                            &msg->ssr_orbit_clock);
    case SbpMsgSsrPhaseBiases:
      return sbp_msg_ssr_phase_biases_decode(buf, len, n_read,
                                             &msg->ssr_phase_biases);
    case SbpMsgSsrSatelliteApc:
      return sbp_msg_ssr_satellite_apc_decode(buf, len, n_read,
                                              &msg->ssr_satellite_apc);
    case SbpMsgSsrStecCorrectionDepA:
      return sbp_msg_ssr_stec_correction_dep_a_decode(
          buf, len, n_read, &msg->ssr_stec_correction_dep_a);
    case SbpMsgSsrStecCorrection:
      return sbp_msg_ssr_stec_correction_decode(buf, len, n_read,
                                                &msg->ssr_stec_correction);
    case SbpMsgSsrTileDefinition:
      return sbp_msg_ssr_tile_definition_decode(buf, len, n_read,
                                                &msg->ssr_tile_definition);
    case SbpMsgStartup:
      return sbp_msg_startup_decode(buf, len, n_read, &msg->startup);
    case SbpMsgStatusReport:
      return sbp_msg_status_report_decode(buf, len, n_read,
                                          &msg->status_report);
    case SbpMsgStmFlashLockSector:
      return sbp_msg_stm_flash_lock_sector_decode(buf, len, n_read,
                                                  &msg->stm_flash_lock_sector);
    case SbpMsgStmFlashUnlockSector:
      return sbp_msg_stm_flash_unlock_sector_decode(
          buf, len, n_read, &msg->stm_flash_unlock_sector);
    case SbpMsgStmUniqueIdReq:
      return sbp_msg_stm_unique_id_req_decode(buf, len, n_read,
                                              &msg->stm_unique_id_req);
    case SbpMsgStmUniqueIdResp:
      return sbp_msg_stm_unique_id_resp_decode(buf, len, n_read,
                                               &msg->stm_unique_id_resp);
    case SbpMsgSvAzEl:
      return sbp_msg_sv_az_el_decode(buf, len, n_read, &msg->sv_az_el);
    case SbpMsgSvConfigurationGpsDep:
      return sbp_msg_sv_configuration_gps_dep_decode(
          buf, len, n_read, &msg->sv_configuration_gps_dep);
    case SbpMsgThreadState:
      return sbp_msg_thread_state_decode(buf, len, n_read, &msg->thread_state);
    case SbpMsgTrackingIqDepA:
      return sbp_msg_tracking_iq_dep_a_decode(buf, len, n_read,
                                              &msg->tracking_iq_dep_a);
    case SbpMsgTrackingIqDepB:
      return sbp_msg_tracking_iq_dep_b_decode(buf, len, n_read,
                                              &msg->tracking_iq_dep_b);
    case SbpMsgTrackingIq:
      return sbp_msg_tracking_iq_decode(buf, len, n_read, &msg->tracking_iq);
    case SbpMsgTrackingStateDepA:
      return sbp_msg_tracking_state_dep_a_decode(buf, len, n_read,
                                                 &msg->tracking_state_dep_a);
    case SbpMsgTrackingStateDepB:
      return sbp_msg_tracking_state_dep_b_decode(buf, len, n_read,
                                                 &msg->tracking_state_dep_b);
    case SbpMsgTrackingStateDetailedDepA:
      return sbp_msg_tracking_state_detailed_dep_a_decode(
          buf, len, n_read, &msg->tracking_state_detailed_dep_a);
    case SbpMsgTrackingStateDetailedDep:
      return sbp_msg_tracking_state_detailed_dep_decode(
          buf, len, n_read, &msg->tracking_state_detailed_dep);
    case SbpMsgTrackingState:
      return sbp_msg_tracking_state_decode(buf, len, n_read,
                                           &msg->tracking_state);
    case SbpMsgUartStateDepa:
      return sbp_msg_uart_state_depa_decode(buf, len, n_read,
                                            &msg->uart_state_depa);
    case SbpMsgUartState:
      return sbp_msg_uart_state_decode(buf, len, n_read, &msg->uart_state);
    case SbpMsgUserData:
      return sbp_msg_user_data_decode(buf, len, n_read, &msg->user_data);
    case SbpMsgUtcTimeGnss:
      return sbp_msg_utc_time_gnss_decode(buf, len, n_read,
                                          &msg->utc_time_gnss);
    case SbpMsgUtcTime:
      return sbp_msg_utc_time_decode(buf, len, n_read, &msg->utc_time);
    case SbpMsgVelBody:
      return sbp_msg_vel_body_decode(buf, len, n_read, &msg->vel_body);
    case SbpMsgVelCog:
      return sbp_msg_vel_cog_decode(buf, len, n_read, &msg->vel_cog);
    case SbpMsgVelEcefCovGnss:
      return sbp_msg_vel_ecef_cov_gnss_decode(buf, len, n_read,
                                              &msg->vel_ecef_cov_gnss);
    case SbpMsgVelEcefCov:
      return sbp_msg_vel_ecef_cov_decode(buf, len, n_read, &msg->vel_ecef_cov);
    case SbpMsgVelEcefDepA:
      return sbp_msg_vel_ecef_dep_a_decode(buf, len, n_read,
                                           &msg->vel_ecef_dep_a);
    case SbpMsgVelEcefGnss:
      return sbp_msg_vel_ecef_gnss_decode(buf, len, n_read,
                                          &msg->vel_ecef_gnss);
    case SbpMsgVelEcef:
      return sbp_msg_vel_ecef_decode(buf, len, n_read, &msg->vel_ecef);
    case SbpMsgVelNedCovGnss:
      return sbp_msg_vel_ned_cov_gnss_decode(buf, len, n_read,
                                             &msg->vel_ned_cov_gnss);
    case SbpMsgVelNedCov:
      return sbp_msg_vel_ned_cov_decode(buf, len, n_read, &msg->vel_ned_cov);
    case SbpMsgVelNedDepA:
      return sbp_msg_vel_ned_dep_a_decode(buf, len, n_read,
                                          &msg->vel_ned_dep_a);
    case SbpMsgVelNedGnss:
      return sbp_msg_vel_ned_gnss_decode(buf, len, n_read, &msg->vel_ned_gnss);
    case SbpMsgVelNed:
      return sbp_msg_vel_ned_decode(buf, len, n_read, &msg->vel_ned);
    case SbpMsgWheeltick:
      return sbp_msg_wheeltick_decode(buf, len, n_read, &msg->wheeltick);
    default:
      break;
  }
  return -1;
}

/** Returns the wire format size in bytes of a given SBP message.
 *
 * \param msg_type    SBP message type
 * \param msg         SBP message
 * \return            The Number of bytes that the given message would be on the
 * wire
 */
static inline size_t sbp_message_encoded_len(sbp_msg_type_t msg_type,
                                             const sbp_msg_t *msg) {
  switch (msg_type) {
    case SbpMsgAcqResultDepA:
      return sbp_msg_acq_result_dep_a_encoded_len(&msg->acq_result_dep_a);
    case SbpMsgAcqResultDepB:
      return sbp_msg_acq_result_dep_b_encoded_len(&msg->acq_result_dep_b);
    case SbpMsgAcqResultDepC:
      return sbp_msg_acq_result_dep_c_encoded_len(&msg->acq_result_dep_c);
    case SbpMsgAcqResult:
      return sbp_msg_acq_result_encoded_len(&msg->acq_result);
    case SbpMsgAcqSvProfileDep:
      return sbp_msg_acq_sv_profile_dep_encoded_len(&msg->acq_sv_profile_dep);
    case SbpMsgAcqSvProfile:
      return sbp_msg_acq_sv_profile_encoded_len(&msg->acq_sv_profile);
    case SbpMsgAgeCorrections:
      return sbp_msg_age_corrections_encoded_len(&msg->age_corrections);
    case SbpMsgAlmanacGloDep:
      return sbp_msg_almanac_glo_dep_encoded_len(&msg->almanac_glo_dep);
    case SbpMsgAlmanacGlo:
      return sbp_msg_almanac_glo_encoded_len(&msg->almanac_glo);
    case SbpMsgAlmanacGpsDep:
      return sbp_msg_almanac_gps_dep_encoded_len(&msg->almanac_gps_dep);
    case SbpMsgAlmanacGps:
      return sbp_msg_almanac_gps_encoded_len(&msg->almanac_gps);
    case SbpMsgAlmanac:
      return sbp_msg_almanac_encoded_len(&msg->almanac);
    case SbpMsgAngularRate:
      return sbp_msg_angular_rate_encoded_len(&msg->angular_rate);
    case SbpMsgBasePosEcef:
      return sbp_msg_base_pos_ecef_encoded_len(&msg->base_pos_ecef);
    case SbpMsgBasePosLlh:
      return sbp_msg_base_pos_llh_encoded_len(&msg->base_pos_llh);
    case SbpMsgBaselineEcefDepA:
      return sbp_msg_baseline_ecef_dep_a_encoded_len(&msg->baseline_ecef_dep_a);
    case SbpMsgBaselineEcef:
      return sbp_msg_baseline_ecef_encoded_len(&msg->baseline_ecef);
    case SbpMsgBaselineHeadingDepA:
      return sbp_msg_baseline_heading_dep_a_encoded_len(
          &msg->baseline_heading_dep_a);
    case SbpMsgBaselineHeading:
      return sbp_msg_baseline_heading_encoded_len(&msg->baseline_heading);
    case SbpMsgBaselineNedDepA:
      return sbp_msg_baseline_ned_dep_a_encoded_len(&msg->baseline_ned_dep_a);
    case SbpMsgBaselineNed:
      return sbp_msg_baseline_ned_encoded_len(&msg->baseline_ned);
    case SbpMsgBootloaderHandshakeDepA:
      return sbp_msg_bootloader_handshake_dep_a_encoded_len(
          &msg->bootloader_handshake_dep_a);
    case SbpMsgBootloaderHandshakeReq:
      return sbp_msg_bootloader_handshake_req_encoded_len(
          &msg->bootloader_handshake_req);
    case SbpMsgBootloaderHandshakeResp:
      return sbp_msg_bootloader_handshake_resp_encoded_len(
          &msg->bootloader_handshake_resp);
    case SbpMsgBootloaderJumpToApp:
      return sbp_msg_bootloader_jump_to_app_encoded_len(
          &msg->bootloader_jump_to_app);
    case SbpMsgCellModemStatus:
      return sbp_msg_cell_modem_status_encoded_len(&msg->cell_modem_status);
    case SbpMsgCommandOutput:
      return sbp_msg_command_output_encoded_len(&msg->command_output);
    case SbpMsgCommandReq:
      return sbp_msg_command_req_encoded_len(&msg->command_req);
    case SbpMsgCommandResp:
      return sbp_msg_command_resp_encoded_len(&msg->command_resp);
    case SbpMsgCsacTelemetryLabels:
      return sbp_msg_csac_telemetry_labels_encoded_len(
          &msg->csac_telemetry_labels);
    case SbpMsgCsacTelemetry:
      return sbp_msg_csac_telemetry_encoded_len(&msg->csac_telemetry);
    case SbpMsgCwResults:
      return sbp_msg_cw_results_encoded_len(&msg->cw_results);
    case SbpMsgCwStart:
      return sbp_msg_cw_start_encoded_len(&msg->cw_start);
    case SbpMsgDeviceMonitor:
      return sbp_msg_device_monitor_encoded_len(&msg->device_monitor);
    case SbpMsgDgnssStatus:
      return sbp_msg_dgnss_status_encoded_len(&msg->dgnss_status);
    case SbpMsgDopsDepA:
      return sbp_msg_dops_dep_a_encoded_len(&msg->dops_dep_a);
    case SbpMsgDops:
      return sbp_msg_dops_encoded_len(&msg->dops);
    case SbpMsgEphemerisBds:
      return sbp_msg_ephemeris_bds_encoded_len(&msg->ephemeris_bds);
    case SbpMsgEphemerisDepA:
      return sbp_msg_ephemeris_dep_a_encoded_len(&msg->ephemeris_dep_a);
    case SbpMsgEphemerisDepB:
      return sbp_msg_ephemeris_dep_b_encoded_len(&msg->ephemeris_dep_b);
    case SbpMsgEphemerisDepC:
      return sbp_msg_ephemeris_dep_c_encoded_len(&msg->ephemeris_dep_c);
    case SbpMsgEphemerisDepD:
      return sbp_msg_ephemeris_dep_d_encoded_len(&msg->ephemeris_dep_d);
    case SbpMsgEphemerisGalDepA:
      return sbp_msg_ephemeris_gal_dep_a_encoded_len(&msg->ephemeris_gal_dep_a);
    case SbpMsgEphemerisGal:
      return sbp_msg_ephemeris_gal_encoded_len(&msg->ephemeris_gal);
    case SbpMsgEphemerisGloDepA:
      return sbp_msg_ephemeris_glo_dep_a_encoded_len(&msg->ephemeris_glo_dep_a);
    case SbpMsgEphemerisGloDepB:
      return sbp_msg_ephemeris_glo_dep_b_encoded_len(&msg->ephemeris_glo_dep_b);
    case SbpMsgEphemerisGloDepC:
      return sbp_msg_ephemeris_glo_dep_c_encoded_len(&msg->ephemeris_glo_dep_c);
    case SbpMsgEphemerisGloDepD:
      return sbp_msg_ephemeris_glo_dep_d_encoded_len(&msg->ephemeris_glo_dep_d);
    case SbpMsgEphemerisGlo:
      return sbp_msg_ephemeris_glo_encoded_len(&msg->ephemeris_glo);
    case SbpMsgEphemerisGpsDepE:
      return sbp_msg_ephemeris_gps_dep_e_encoded_len(&msg->ephemeris_gps_dep_e);
    case SbpMsgEphemerisGpsDepF:
      return sbp_msg_ephemeris_gps_dep_f_encoded_len(&msg->ephemeris_gps_dep_f);
    case SbpMsgEphemerisGps:
      return sbp_msg_ephemeris_gps_encoded_len(&msg->ephemeris_gps);
    case SbpMsgEphemerisQzss:
      return sbp_msg_ephemeris_qzss_encoded_len(&msg->ephemeris_qzss);
    case SbpMsgEphemerisSbasDepA:
      return sbp_msg_ephemeris_sbas_dep_a_encoded_len(
          &msg->ephemeris_sbas_dep_a);
    case SbpMsgEphemerisSbasDepB:
      return sbp_msg_ephemeris_sbas_dep_b_encoded_len(
          &msg->ephemeris_sbas_dep_b);
    case SbpMsgEphemerisSbas:
      return sbp_msg_ephemeris_sbas_encoded_len(&msg->ephemeris_sbas);
    case SbpMsgExtEvent:
      return sbp_msg_ext_event_encoded_len(&msg->ext_event);
    case SbpMsgFileioConfigReq:
      return sbp_msg_fileio_config_req_encoded_len(&msg->fileio_config_req);
    case SbpMsgFileioConfigResp:
      return sbp_msg_fileio_config_resp_encoded_len(&msg->fileio_config_resp);
    case SbpMsgFileioReadDirReq:
      return sbp_msg_fileio_read_dir_req_encoded_len(&msg->fileio_read_dir_req);
    case SbpMsgFileioReadDirResp:
      return sbp_msg_fileio_read_dir_resp_encoded_len(
          &msg->fileio_read_dir_resp);
    case SbpMsgFileioReadReq:
      return sbp_msg_fileio_read_req_encoded_len(&msg->fileio_read_req);
    case SbpMsgFileioReadResp:
      return sbp_msg_fileio_read_resp_encoded_len(&msg->fileio_read_resp);
    case SbpMsgFileioRemove:
      return sbp_msg_fileio_remove_encoded_len(&msg->fileio_remove);
    case SbpMsgFileioWriteReq:
      return sbp_msg_fileio_write_req_encoded_len(&msg->fileio_write_req);
    case SbpMsgFileioWriteResp:
      return sbp_msg_fileio_write_resp_encoded_len(&msg->fileio_write_resp);
    case SbpMsgFlashDone:
      return sbp_msg_flash_done_encoded_len(&msg->flash_done);
    case SbpMsgFlashErase:
      return sbp_msg_flash_erase_encoded_len(&msg->flash_erase);
    case SbpMsgFlashProgram:
      return sbp_msg_flash_program_encoded_len(&msg->flash_program);
    case SbpMsgFlashReadReq:
      return sbp_msg_flash_read_req_encoded_len(&msg->flash_read_req);
    case SbpMsgFlashReadResp:
      return sbp_msg_flash_read_resp_encoded_len(&msg->flash_read_resp);
    case SbpMsgFrontEndGain:
      return sbp_msg_front_end_gain_encoded_len(&msg->front_end_gain);
    case SbpMsgFwd:
      return sbp_msg_fwd_encoded_len(&msg->fwd);
    case SbpMsgGloBiases:
      return sbp_msg_glo_biases_encoded_len(&msg->glo_biases);
    case SbpMsgGnssCapb:
      return sbp_msg_gnss_capb_encoded_len(&msg->gnss_capb);
    case SbpMsgGnssTimeOffset:
      return sbp_msg_gnss_time_offset_encoded_len(&msg->gnss_time_offset);
    case SbpMsgGpsTimeDepA:
      return sbp_msg_gps_time_dep_a_encoded_len(&msg->gps_time_dep_a);
    case SbpMsgGpsTimeGnss:
      return sbp_msg_gps_time_gnss_encoded_len(&msg->gps_time_gnss);
    case SbpMsgGpsTime:
      return sbp_msg_gps_time_encoded_len(&msg->gps_time);
    case SbpMsgGroupDelayDepA:
      return sbp_msg_group_delay_dep_a_encoded_len(&msg->group_delay_dep_a);
    case SbpMsgGroupDelayDepB:
      return sbp_msg_group_delay_dep_b_encoded_len(&msg->group_delay_dep_b);
    case SbpMsgGroupDelay:
      return sbp_msg_group_delay_encoded_len(&msg->group_delay);
    case SbpMsgGroupMeta:
      return sbp_msg_group_meta_encoded_len(&msg->group_meta);
    case SbpMsgHeartbeat:
      return sbp_msg_heartbeat_encoded_len(&msg->heartbeat);
    case SbpMsgIarState:
      return sbp_msg_iar_state_encoded_len(&msg->iar_state);
    case SbpMsgImuAux:
      return sbp_msg_imu_aux_encoded_len(&msg->imu_aux);
    case SbpMsgImuRaw:
      return sbp_msg_imu_raw_encoded_len(&msg->imu_raw);
    case SbpMsgInitBaseDep:
      return sbp_msg_init_base_dep_encoded_len(&msg->init_base_dep);
    case SbpMsgInsStatus:
      return sbp_msg_ins_status_encoded_len(&msg->ins_status);
    case SbpMsgInsUpdates:
      return sbp_msg_ins_updates_encoded_len(&msg->ins_updates);
    case SbpMsgIono:
      return sbp_msg_iono_encoded_len(&msg->iono);
    case SbpMsgLinuxCpuStateDepA:
      return sbp_msg_linux_cpu_state_dep_a_encoded_len(
          &msg->linux_cpu_state_dep_a);
    case SbpMsgLinuxCpuState:
      return sbp_msg_linux_cpu_state_encoded_len(&msg->linux_cpu_state);
    case SbpMsgLinuxMemStateDepA:
      return sbp_msg_linux_mem_state_dep_a_encoded_len(
          &msg->linux_mem_state_dep_a);
    case SbpMsgLinuxMemState:
      return sbp_msg_linux_mem_state_encoded_len(&msg->linux_mem_state);
    case SbpMsgLinuxProcessFdCount:
      return sbp_msg_linux_process_fd_count_encoded_len(
          &msg->linux_process_fd_count);
    case SbpMsgLinuxProcessFdSummary:
      return sbp_msg_linux_process_fd_summary_encoded_len(
          &msg->linux_process_fd_summary);
    case SbpMsgLinuxProcessSocketCounts:
      return sbp_msg_linux_process_socket_counts_encoded_len(
          &msg->linux_process_socket_counts);
    case SbpMsgLinuxProcessSocketQueues:
      return sbp_msg_linux_process_socket_queues_encoded_len(
          &msg->linux_process_socket_queues);
    case SbpMsgLinuxSocketUsage:
      return sbp_msg_linux_socket_usage_encoded_len(&msg->linux_socket_usage);
    case SbpMsgLinuxSysStateDepA:
      return sbp_msg_linux_sys_state_dep_a_encoded_len(
          &msg->linux_sys_state_dep_a);
    case SbpMsgLinuxSysState:
      return sbp_msg_linux_sys_state_encoded_len(&msg->linux_sys_state);
    case SbpMsgLog:
      return sbp_msg_log_encoded_len(&msg->log);
    case SbpMsgM25FlashWriteStatus:
      return sbp_msg_m25_flash_write_status_encoded_len(
          &msg->m25_flash_write_status);
    case SbpMsgMagRaw:
      return sbp_msg_mag_raw_encoded_len(&msg->mag_raw);
    case SbpMsgMaskSatelliteDep:
      return sbp_msg_mask_satellite_dep_encoded_len(&msg->mask_satellite_dep);
    case SbpMsgMaskSatellite:
      return sbp_msg_mask_satellite_encoded_len(&msg->mask_satellite);
    case SbpMsgMeasurementState:
      return sbp_msg_measurement_state_encoded_len(&msg->measurement_state);
    case SbpMsgNapDeviceDnaReq:
      return sbp_msg_nap_device_dna_req_encoded_len(&msg->nap_device_dna_req);
    case SbpMsgNapDeviceDnaResp:
      return sbp_msg_nap_device_dna_resp_encoded_len(&msg->nap_device_dna_resp);
    case SbpMsgNdbEvent:
      return sbp_msg_ndb_event_encoded_len(&msg->ndb_event);
    case SbpMsgNetworkBandwidthUsage:
      return sbp_msg_network_bandwidth_usage_encoded_len(
          &msg->network_bandwidth_usage);
    case SbpMsgNetworkStateReq:
      return sbp_msg_network_state_req_encoded_len(&msg->network_state_req);
    case SbpMsgNetworkStateResp:
      return sbp_msg_network_state_resp_encoded_len(&msg->network_state_resp);
    case SbpMsgObsDepA:
      return sbp_msg_obs_dep_a_encoded_len(&msg->obs_dep_a);
    case SbpMsgObsDepB:
      return sbp_msg_obs_dep_b_encoded_len(&msg->obs_dep_b);
    case SbpMsgObsDepC:
      return sbp_msg_obs_dep_c_encoded_len(&msg->obs_dep_c);
    case SbpMsgObs:
      return sbp_msg_obs_encoded_len(&msg->obs);
    case SbpMsgOdometry:
      return sbp_msg_odometry_encoded_len(&msg->odometry);
    case SbpMsgOrientEuler:
      return sbp_msg_orient_euler_encoded_len(&msg->orient_euler);
    case SbpMsgOrientQuat:
      return sbp_msg_orient_quat_encoded_len(&msg->orient_quat);
    case SbpMsgOsr:
      return sbp_msg_osr_encoded_len(&msg->osr);
    case SbpMsgPosEcefCovGnss:
      return sbp_msg_pos_ecef_cov_gnss_encoded_len(&msg->pos_ecef_cov_gnss);
    case SbpMsgPosEcefCov:
      return sbp_msg_pos_ecef_cov_encoded_len(&msg->pos_ecef_cov);
    case SbpMsgPosEcefDepA:
      return sbp_msg_pos_ecef_dep_a_encoded_len(&msg->pos_ecef_dep_a);
    case SbpMsgPosEcefGnss:
      return sbp_msg_pos_ecef_gnss_encoded_len(&msg->pos_ecef_gnss);
    case SbpMsgPosEcef:
      return sbp_msg_pos_ecef_encoded_len(&msg->pos_ecef);
    case SbpMsgPosLlhAcc:
      return sbp_msg_pos_llh_acc_encoded_len(&msg->pos_llh_acc);
    case SbpMsgPosLlhCovGnss:
      return sbp_msg_pos_llh_cov_gnss_encoded_len(&msg->pos_llh_cov_gnss);
    case SbpMsgPosLlhCov:
      return sbp_msg_pos_llh_cov_encoded_len(&msg->pos_llh_cov);
    case SbpMsgPosLlhDepA:
      return sbp_msg_pos_llh_dep_a_encoded_len(&msg->pos_llh_dep_a);
    case SbpMsgPosLlhGnss:
      return sbp_msg_pos_llh_gnss_encoded_len(&msg->pos_llh_gnss);
    case SbpMsgPosLlh:
      return sbp_msg_pos_llh_encoded_len(&msg->pos_llh);
    case SbpMsgPpsTime:
      return sbp_msg_pps_time_encoded_len(&msg->pps_time);
    case SbpMsgPrintDep:
      return sbp_msg_print_dep_encoded_len(&msg->print_dep);
    case SbpMsgProtectionLevelDepA:
      return sbp_msg_protection_level_dep_a_encoded_len(
          &msg->protection_level_dep_a);
    case SbpMsgProtectionLevel:
      return sbp_msg_protection_level_encoded_len(&msg->protection_level);
    case SbpMsgResetDep:
      return sbp_msg_reset_dep_encoded_len(&msg->reset_dep);
    case SbpMsgResetFilters:
      return sbp_msg_reset_filters_encoded_len(&msg->reset_filters);
    case SbpMsgReset:
      return sbp_msg_reset_encoded_len(&msg->reset);
    case SbpMsgSbasRaw:
      return sbp_msg_sbas_raw_encoded_len(&msg->sbas_raw);
    case SbpMsgSetTime:
      return sbp_msg_set_time_encoded_len(&msg->set_time);
    case SbpMsgSettingsReadByIndexDone:
      return sbp_msg_settings_read_by_index_done_encoded_len(
          &msg->settings_read_by_index_done);
    case SbpMsgSettingsReadByIndexReq:
      return sbp_msg_settings_read_by_index_req_encoded_len(
          &msg->settings_read_by_index_req);
    case SbpMsgSettingsReadByIndexResp:
      return sbp_msg_settings_read_by_index_resp_encoded_len(
          &msg->settings_read_by_index_resp);
    case SbpMsgSettingsReadReq:
      return sbp_msg_settings_read_req_encoded_len(&msg->settings_read_req);
    case SbpMsgSettingsReadResp:
      return sbp_msg_settings_read_resp_encoded_len(&msg->settings_read_resp);
    case SbpMsgSettingsRegisterResp:
      return sbp_msg_settings_register_resp_encoded_len(
          &msg->settings_register_resp);
    case SbpMsgSettingsRegister:
      return sbp_msg_settings_register_encoded_len(&msg->settings_register);
    case SbpMsgSettingsSave:
      return sbp_msg_settings_save_encoded_len(&msg->settings_save);
    case SbpMsgSettingsWriteResp:
      return sbp_msg_settings_write_resp_encoded_len(&msg->settings_write_resp);
    case SbpMsgSettingsWrite:
      return sbp_msg_settings_write_encoded_len(&msg->settings_write);
    case SbpMsgSolnMetaDepA:
      return sbp_msg_soln_meta_dep_a_encoded_len(&msg->soln_meta_dep_a);
    case SbpMsgSolnMeta:
      return sbp_msg_soln_meta_encoded_len(&msg->soln_meta);
    case SbpMsgSpecanDep:
      return sbp_msg_specan_dep_encoded_len(&msg->specan_dep);
    case SbpMsgSpecan:
      return sbp_msg_specan_encoded_len(&msg->specan);
    case SbpMsgSsrCodeBiases:
      return sbp_msg_ssr_code_biases_encoded_len(&msg->ssr_code_biases);
    case SbpMsgSsrGridDefinitionDepA:
      return sbp_msg_ssr_grid_definition_dep_a_encoded_len(
          &msg->ssr_grid_definition_dep_a);
    case SbpMsgSsrGriddedCorrectionDepA:
      return sbp_msg_ssr_gridded_correction_dep_a_encoded_len(
          &msg->ssr_gridded_correction_dep_a);
    case SbpMsgSsrGriddedCorrectionNoStdDepA:
      return sbp_msg_ssr_gridded_correction_no_std_dep_a_encoded_len(
          &msg->ssr_gridded_correction_no_std_dep_a);
    case SbpMsgSsrGriddedCorrection:
      return sbp_msg_ssr_gridded_correction_encoded_len(
          &msg->ssr_gridded_correction);
    case SbpMsgSsrOrbitClockDepA:
      return sbp_msg_ssr_orbit_clock_dep_a_encoded_len(
          &msg->ssr_orbit_clock_dep_a);
    case SbpMsgSsrOrbitClock:
      return sbp_msg_ssr_orbit_clock_encoded_len(&msg->ssr_orbit_clock);
    case SbpMsgSsrPhaseBiases:
      return sbp_msg_ssr_phase_biases_encoded_len(&msg->ssr_phase_biases);
    case SbpMsgSsrSatelliteApc:
      return sbp_msg_ssr_satellite_apc_encoded_len(&msg->ssr_satellite_apc);
    case SbpMsgSsrStecCorrectionDepA:
      return sbp_msg_ssr_stec_correction_dep_a_encoded_len(
          &msg->ssr_stec_correction_dep_a);
    case SbpMsgSsrStecCorrection:
      return sbp_msg_ssr_stec_correction_encoded_len(&msg->ssr_stec_correction);
    case SbpMsgSsrTileDefinition:
      return sbp_msg_ssr_tile_definition_encoded_len(&msg->ssr_tile_definition);
    case SbpMsgStartup:
      return sbp_msg_startup_encoded_len(&msg->startup);
    case SbpMsgStatusReport:
      return sbp_msg_status_report_encoded_len(&msg->status_report);
    case SbpMsgStmFlashLockSector:
      return sbp_msg_stm_flash_lock_sector_encoded_len(
          &msg->stm_flash_lock_sector);
    case SbpMsgStmFlashUnlockSector:
      return sbp_msg_stm_flash_unlock_sector_encoded_len(
          &msg->stm_flash_unlock_sector);
    case SbpMsgStmUniqueIdReq:
      return sbp_msg_stm_unique_id_req_encoded_len(&msg->stm_unique_id_req);
    case SbpMsgStmUniqueIdResp:
      return sbp_msg_stm_unique_id_resp_encoded_len(&msg->stm_unique_id_resp);
    case SbpMsgSvAzEl:
      return sbp_msg_sv_az_el_encoded_len(&msg->sv_az_el);
    case SbpMsgSvConfigurationGpsDep:
      return sbp_msg_sv_configuration_gps_dep_encoded_len(
          &msg->sv_configuration_gps_dep);
    case SbpMsgThreadState:
      return sbp_msg_thread_state_encoded_len(&msg->thread_state);
    case SbpMsgTrackingIqDepA:
      return sbp_msg_tracking_iq_dep_a_encoded_len(&msg->tracking_iq_dep_a);
    case SbpMsgTrackingIqDepB:
      return sbp_msg_tracking_iq_dep_b_encoded_len(&msg->tracking_iq_dep_b);
    case SbpMsgTrackingIq:
      return sbp_msg_tracking_iq_encoded_len(&msg->tracking_iq);
    case SbpMsgTrackingStateDepA:
      return sbp_msg_tracking_state_dep_a_encoded_len(
          &msg->tracking_state_dep_a);
    case SbpMsgTrackingStateDepB:
      return sbp_msg_tracking_state_dep_b_encoded_len(
          &msg->tracking_state_dep_b);
    case SbpMsgTrackingStateDetailedDepA:
      return sbp_msg_tracking_state_detailed_dep_a_encoded_len(
          &msg->tracking_state_detailed_dep_a);
    case SbpMsgTrackingStateDetailedDep:
      return sbp_msg_tracking_state_detailed_dep_encoded_len(
          &msg->tracking_state_detailed_dep);
    case SbpMsgTrackingState:
      return sbp_msg_tracking_state_encoded_len(&msg->tracking_state);
    case SbpMsgUartStateDepa:
      return sbp_msg_uart_state_depa_encoded_len(&msg->uart_state_depa);
    case SbpMsgUartState:
      return sbp_msg_uart_state_encoded_len(&msg->uart_state);
    case SbpMsgUserData:
      return sbp_msg_user_data_encoded_len(&msg->user_data);
    case SbpMsgUtcTimeGnss:
      return sbp_msg_utc_time_gnss_encoded_len(&msg->utc_time_gnss);
    case SbpMsgUtcTime:
      return sbp_msg_utc_time_encoded_len(&msg->utc_time);
    case SbpMsgVelBody:
      return sbp_msg_vel_body_encoded_len(&msg->vel_body);
    case SbpMsgVelCog:
      return sbp_msg_vel_cog_encoded_len(&msg->vel_cog);
    case SbpMsgVelEcefCovGnss:
      return sbp_msg_vel_ecef_cov_gnss_encoded_len(&msg->vel_ecef_cov_gnss);
    case SbpMsgVelEcefCov:
      return sbp_msg_vel_ecef_cov_encoded_len(&msg->vel_ecef_cov);
    case SbpMsgVelEcefDepA:
      return sbp_msg_vel_ecef_dep_a_encoded_len(&msg->vel_ecef_dep_a);
    case SbpMsgVelEcefGnss:
      return sbp_msg_vel_ecef_gnss_encoded_len(&msg->vel_ecef_gnss);
    case SbpMsgVelEcef:
      return sbp_msg_vel_ecef_encoded_len(&msg->vel_ecef);
    case SbpMsgVelNedCovGnss:
      return sbp_msg_vel_ned_cov_gnss_encoded_len(&msg->vel_ned_cov_gnss);
    case SbpMsgVelNedCov:
      return sbp_msg_vel_ned_cov_encoded_len(&msg->vel_ned_cov);
    case SbpMsgVelNedDepA:
      return sbp_msg_vel_ned_dep_a_encoded_len(&msg->vel_ned_dep_a);
    case SbpMsgVelNedGnss:
      return sbp_msg_vel_ned_gnss_encoded_len(&msg->vel_ned_gnss);
    case SbpMsgVelNed:
      return sbp_msg_vel_ned_encoded_len(&msg->vel_ned);
    case SbpMsgWheeltick:
      return sbp_msg_wheeltick_encoded_len(&msg->wheeltick);
    default:
      break;
  }
  return 0;
}

/** Compares two SBP messages of equal type.
 *
 * \param msg_type    SBP message type
 * \param a           The first message to compare
 * \param b           The second message to compare
 * \return            0 if the two messages have equal fields
 *                    1 if, on the first non-equal field, a.field > b.field
 *                    -1 if, on the first non-equal field, a.field < b.field
 */
static inline int sbp_message_cmp(sbp_msg_type_t msg_type, const sbp_msg_t *a,
                                  const sbp_msg_t *b) {
  switch (msg_type) {
    case SbpMsgAcqResultDepA:
      return sbp_msg_acq_result_dep_a_cmp(&a->acq_result_dep_a,
                                          &b->acq_result_dep_a);
    case SbpMsgAcqResultDepB:
      return sbp_msg_acq_result_dep_b_cmp(&a->acq_result_dep_b,
                                          &b->acq_result_dep_b);
    case SbpMsgAcqResultDepC:
      return sbp_msg_acq_result_dep_c_cmp(&a->acq_result_dep_c,
                                          &b->acq_result_dep_c);
    case SbpMsgAcqResult:
      return sbp_msg_acq_result_cmp(&a->acq_result, &b->acq_result);
    case SbpMsgAcqSvProfileDep:
      return sbp_msg_acq_sv_profile_dep_cmp(&a->acq_sv_profile_dep,
                                            &b->acq_sv_profile_dep);
    case SbpMsgAcqSvProfile:
      return sbp_msg_acq_sv_profile_cmp(&a->acq_sv_profile, &b->acq_sv_profile);
    case SbpMsgAgeCorrections:
      return sbp_msg_age_corrections_cmp(&a->age_corrections,
                                         &b->age_corrections);
    case SbpMsgAlmanacGloDep:
      return sbp_msg_almanac_glo_dep_cmp(&a->almanac_glo_dep,
                                         &b->almanac_glo_dep);
    case SbpMsgAlmanacGlo:
      return sbp_msg_almanac_glo_cmp(&a->almanac_glo, &b->almanac_glo);
    case SbpMsgAlmanacGpsDep:
      return sbp_msg_almanac_gps_dep_cmp(&a->almanac_gps_dep,
                                         &b->almanac_gps_dep);
    case SbpMsgAlmanacGps:
      return sbp_msg_almanac_gps_cmp(&a->almanac_gps, &b->almanac_gps);
    case SbpMsgAlmanac:
      return sbp_msg_almanac_cmp(&a->almanac, &b->almanac);
    case SbpMsgAngularRate:
      return sbp_msg_angular_rate_cmp(&a->angular_rate, &b->angular_rate);
    case SbpMsgBasePosEcef:
      return sbp_msg_base_pos_ecef_cmp(&a->base_pos_ecef, &b->base_pos_ecef);
    case SbpMsgBasePosLlh:
      return sbp_msg_base_pos_llh_cmp(&a->base_pos_llh, &b->base_pos_llh);
    case SbpMsgBaselineEcefDepA:
      return sbp_msg_baseline_ecef_dep_a_cmp(&a->baseline_ecef_dep_a,
                                             &b->baseline_ecef_dep_a);
    case SbpMsgBaselineEcef:
      return sbp_msg_baseline_ecef_cmp(&a->baseline_ecef, &b->baseline_ecef);
    case SbpMsgBaselineHeadingDepA:
      return sbp_msg_baseline_heading_dep_a_cmp(&a->baseline_heading_dep_a,
                                                &b->baseline_heading_dep_a);
    case SbpMsgBaselineHeading:
      return sbp_msg_baseline_heading_cmp(&a->baseline_heading,
                                          &b->baseline_heading);
    case SbpMsgBaselineNedDepA:
      return sbp_msg_baseline_ned_dep_a_cmp(&a->baseline_ned_dep_a,
                                            &b->baseline_ned_dep_a);
    case SbpMsgBaselineNed:
      return sbp_msg_baseline_ned_cmp(&a->baseline_ned, &b->baseline_ned);
    case SbpMsgBootloaderHandshakeDepA:
      return sbp_msg_bootloader_handshake_dep_a_cmp(
          &a->bootloader_handshake_dep_a, &b->bootloader_handshake_dep_a);
    case SbpMsgBootloaderHandshakeReq:
      return sbp_msg_bootloader_handshake_req_cmp(&a->bootloader_handshake_req,
                                                  &b->bootloader_handshake_req);
    case SbpMsgBootloaderHandshakeResp:
      return sbp_msg_bootloader_handshake_resp_cmp(
          &a->bootloader_handshake_resp, &b->bootloader_handshake_resp);
    case SbpMsgBootloaderJumpToApp:
      return sbp_msg_bootloader_jump_to_app_cmp(&a->bootloader_jump_to_app,
                                                &b->bootloader_jump_to_app);
    case SbpMsgCellModemStatus:
      return sbp_msg_cell_modem_status_cmp(&a->cell_modem_status,
                                           &b->cell_modem_status);
    case SbpMsgCommandOutput:
      return sbp_msg_command_output_cmp(&a->command_output, &b->command_output);
    case SbpMsgCommandReq:
      return sbp_msg_command_req_cmp(&a->command_req, &b->command_req);
    case SbpMsgCommandResp:
      return sbp_msg_command_resp_cmp(&a->command_resp, &b->command_resp);
    case SbpMsgCsacTelemetryLabels:
      return sbp_msg_csac_telemetry_labels_cmp(&a->csac_telemetry_labels,
                                               &b->csac_telemetry_labels);
    case SbpMsgCsacTelemetry:
      return sbp_msg_csac_telemetry_cmp(&a->csac_telemetry, &b->csac_telemetry);
    case SbpMsgCwResults:
      return sbp_msg_cw_results_cmp(&a->cw_results, &b->cw_results);
    case SbpMsgCwStart:
      return sbp_msg_cw_start_cmp(&a->cw_start, &b->cw_start);
    case SbpMsgDeviceMonitor:
      return sbp_msg_device_monitor_cmp(&a->device_monitor, &b->device_monitor);
    case SbpMsgDgnssStatus:
      return sbp_msg_dgnss_status_cmp(&a->dgnss_status, &b->dgnss_status);
    case SbpMsgDopsDepA:
      return sbp_msg_dops_dep_a_cmp(&a->dops_dep_a, &b->dops_dep_a);
    case SbpMsgDops:
      return sbp_msg_dops_cmp(&a->dops, &b->dops);
    case SbpMsgEphemerisBds:
      return sbp_msg_ephemeris_bds_cmp(&a->ephemeris_bds, &b->ephemeris_bds);
    case SbpMsgEphemerisDepA:
      return sbp_msg_ephemeris_dep_a_cmp(&a->ephemeris_dep_a,
                                         &b->ephemeris_dep_a);
    case SbpMsgEphemerisDepB:
      return sbp_msg_ephemeris_dep_b_cmp(&a->ephemeris_dep_b,
                                         &b->ephemeris_dep_b);
    case SbpMsgEphemerisDepC:
      return sbp_msg_ephemeris_dep_c_cmp(&a->ephemeris_dep_c,
                                         &b->ephemeris_dep_c);
    case SbpMsgEphemerisDepD:
      return sbp_msg_ephemeris_dep_d_cmp(&a->ephemeris_dep_d,
                                         &b->ephemeris_dep_d);
    case SbpMsgEphemerisGalDepA:
      return sbp_msg_ephemeris_gal_dep_a_cmp(&a->ephemeris_gal_dep_a,
                                             &b->ephemeris_gal_dep_a);
    case SbpMsgEphemerisGal:
      return sbp_msg_ephemeris_gal_cmp(&a->ephemeris_gal, &b->ephemeris_gal);
    case SbpMsgEphemerisGloDepA:
      return sbp_msg_ephemeris_glo_dep_a_cmp(&a->ephemeris_glo_dep_a,
                                             &b->ephemeris_glo_dep_a);
    case SbpMsgEphemerisGloDepB:
      return sbp_msg_ephemeris_glo_dep_b_cmp(&a->ephemeris_glo_dep_b,
                                             &b->ephemeris_glo_dep_b);
    case SbpMsgEphemerisGloDepC:
      return sbp_msg_ephemeris_glo_dep_c_cmp(&a->ephemeris_glo_dep_c,
                                             &b->ephemeris_glo_dep_c);
    case SbpMsgEphemerisGloDepD:
      return sbp_msg_ephemeris_glo_dep_d_cmp(&a->ephemeris_glo_dep_d,
                                             &b->ephemeris_glo_dep_d);
    case SbpMsgEphemerisGlo:
      return sbp_msg_ephemeris_glo_cmp(&a->ephemeris_glo, &b->ephemeris_glo);
    case SbpMsgEphemerisGpsDepE:
      return sbp_msg_ephemeris_gps_dep_e_cmp(&a->ephemeris_gps_dep_e,
                                             &b->ephemeris_gps_dep_e);
    case SbpMsgEphemerisGpsDepF:
      return sbp_msg_ephemeris_gps_dep_f_cmp(&a->ephemeris_gps_dep_f,
                                             &b->ephemeris_gps_dep_f);
    case SbpMsgEphemerisGps:
      return sbp_msg_ephemeris_gps_cmp(&a->ephemeris_gps, &b->ephemeris_gps);
    case SbpMsgEphemerisQzss:
      return sbp_msg_ephemeris_qzss_cmp(&a->ephemeris_qzss, &b->ephemeris_qzss);
    case SbpMsgEphemerisSbasDepA:
      return sbp_msg_ephemeris_sbas_dep_a_cmp(&a->ephemeris_sbas_dep_a,
                                              &b->ephemeris_sbas_dep_a);
    case SbpMsgEphemerisSbasDepB:
      return sbp_msg_ephemeris_sbas_dep_b_cmp(&a->ephemeris_sbas_dep_b,
                                              &b->ephemeris_sbas_dep_b);
    case SbpMsgEphemerisSbas:
      return sbp_msg_ephemeris_sbas_cmp(&a->ephemeris_sbas, &b->ephemeris_sbas);
    case SbpMsgExtEvent:
      return sbp_msg_ext_event_cmp(&a->ext_event, &b->ext_event);
    case SbpMsgFileioConfigReq:
      return sbp_msg_fileio_config_req_cmp(&a->fileio_config_req,
                                           &b->fileio_config_req);
    case SbpMsgFileioConfigResp:
      return sbp_msg_fileio_config_resp_cmp(&a->fileio_config_resp,
                                            &b->fileio_config_resp);
    case SbpMsgFileioReadDirReq:
      return sbp_msg_fileio_read_dir_req_cmp(&a->fileio_read_dir_req,
                                             &b->fileio_read_dir_req);
    case SbpMsgFileioReadDirResp:
      return sbp_msg_fileio_read_dir_resp_cmp(&a->fileio_read_dir_resp,
                                              &b->fileio_read_dir_resp);
    case SbpMsgFileioReadReq:
      return sbp_msg_fileio_read_req_cmp(&a->fileio_read_req,
                                         &b->fileio_read_req);
    case SbpMsgFileioReadResp:
      return sbp_msg_fileio_read_resp_cmp(&a->fileio_read_resp,
                                          &b->fileio_read_resp);
    case SbpMsgFileioRemove:
      return sbp_msg_fileio_remove_cmp(&a->fileio_remove, &b->fileio_remove);
    case SbpMsgFileioWriteReq:
      return sbp_msg_fileio_write_req_cmp(&a->fileio_write_req,
                                          &b->fileio_write_req);
    case SbpMsgFileioWriteResp:
      return sbp_msg_fileio_write_resp_cmp(&a->fileio_write_resp,
                                           &b->fileio_write_resp);
    case SbpMsgFlashDone:
      return sbp_msg_flash_done_cmp(&a->flash_done, &b->flash_done);
    case SbpMsgFlashErase:
      return sbp_msg_flash_erase_cmp(&a->flash_erase, &b->flash_erase);
    case SbpMsgFlashProgram:
      return sbp_msg_flash_program_cmp(&a->flash_program, &b->flash_program);
    case SbpMsgFlashReadReq:
      return sbp_msg_flash_read_req_cmp(&a->flash_read_req, &b->flash_read_req);
    case SbpMsgFlashReadResp:
      return sbp_msg_flash_read_resp_cmp(&a->flash_read_resp,
                                         &b->flash_read_resp);
    case SbpMsgFrontEndGain:
      return sbp_msg_front_end_gain_cmp(&a->front_end_gain, &b->front_end_gain);
    case SbpMsgFwd:
      return sbp_msg_fwd_cmp(&a->fwd, &b->fwd);
    case SbpMsgGloBiases:
      return sbp_msg_glo_biases_cmp(&a->glo_biases, &b->glo_biases);
    case SbpMsgGnssCapb:
      return sbp_msg_gnss_capb_cmp(&a->gnss_capb, &b->gnss_capb);
    case SbpMsgGnssTimeOffset:
      return sbp_msg_gnss_time_offset_cmp(&a->gnss_time_offset,
                                          &b->gnss_time_offset);
    case SbpMsgGpsTimeDepA:
      return sbp_msg_gps_time_dep_a_cmp(&a->gps_time_dep_a, &b->gps_time_dep_a);
    case SbpMsgGpsTimeGnss:
      return sbp_msg_gps_time_gnss_cmp(&a->gps_time_gnss, &b->gps_time_gnss);
    case SbpMsgGpsTime:
      return sbp_msg_gps_time_cmp(&a->gps_time, &b->gps_time);
    case SbpMsgGroupDelayDepA:
      return sbp_msg_group_delay_dep_a_cmp(&a->group_delay_dep_a,
                                           &b->group_delay_dep_a);
    case SbpMsgGroupDelayDepB:
      return sbp_msg_group_delay_dep_b_cmp(&a->group_delay_dep_b,
                                           &b->group_delay_dep_b);
    case SbpMsgGroupDelay:
      return sbp_msg_group_delay_cmp(&a->group_delay, &b->group_delay);
    case SbpMsgGroupMeta:
      return sbp_msg_group_meta_cmp(&a->group_meta, &b->group_meta);
    case SbpMsgHeartbeat:
      return sbp_msg_heartbeat_cmp(&a->heartbeat, &b->heartbeat);
    case SbpMsgIarState:
      return sbp_msg_iar_state_cmp(&a->iar_state, &b->iar_state);
    case SbpMsgImuAux:
      return sbp_msg_imu_aux_cmp(&a->imu_aux, &b->imu_aux);
    case SbpMsgImuRaw:
      return sbp_msg_imu_raw_cmp(&a->imu_raw, &b->imu_raw);
    case SbpMsgInitBaseDep:
      return sbp_msg_init_base_dep_cmp(&a->init_base_dep, &b->init_base_dep);
    case SbpMsgInsStatus:
      return sbp_msg_ins_status_cmp(&a->ins_status, &b->ins_status);
    case SbpMsgInsUpdates:
      return sbp_msg_ins_updates_cmp(&a->ins_updates, &b->ins_updates);
    case SbpMsgIono:
      return sbp_msg_iono_cmp(&a->iono, &b->iono);
    case SbpMsgLinuxCpuStateDepA:
      return sbp_msg_linux_cpu_state_dep_a_cmp(&a->linux_cpu_state_dep_a,
                                               &b->linux_cpu_state_dep_a);
    case SbpMsgLinuxCpuState:
      return sbp_msg_linux_cpu_state_cmp(&a->linux_cpu_state,
                                         &b->linux_cpu_state);
    case SbpMsgLinuxMemStateDepA:
      return sbp_msg_linux_mem_state_dep_a_cmp(&a->linux_mem_state_dep_a,
                                               &b->linux_mem_state_dep_a);
    case SbpMsgLinuxMemState:
      return sbp_msg_linux_mem_state_cmp(&a->linux_mem_state,
                                         &b->linux_mem_state);
    case SbpMsgLinuxProcessFdCount:
      return sbp_msg_linux_process_fd_count_cmp(&a->linux_process_fd_count,
                                                &b->linux_process_fd_count);
    case SbpMsgLinuxProcessFdSummary:
      return sbp_msg_linux_process_fd_summary_cmp(&a->linux_process_fd_summary,
                                                  &b->linux_process_fd_summary);
    case SbpMsgLinuxProcessSocketCounts:
      return sbp_msg_linux_process_socket_counts_cmp(
          &a->linux_process_socket_counts, &b->linux_process_socket_counts);
    case SbpMsgLinuxProcessSocketQueues:
      return sbp_msg_linux_process_socket_queues_cmp(
          &a->linux_process_socket_queues, &b->linux_process_socket_queues);
    case SbpMsgLinuxSocketUsage:
      return sbp_msg_linux_socket_usage_cmp(&a->linux_socket_usage,
                                            &b->linux_socket_usage);
    case SbpMsgLinuxSysStateDepA:
      return sbp_msg_linux_sys_state_dep_a_cmp(&a->linux_sys_state_dep_a,
                                               &b->linux_sys_state_dep_a);
    case SbpMsgLinuxSysState:
      return sbp_msg_linux_sys_state_cmp(&a->linux_sys_state,
                                         &b->linux_sys_state);
    case SbpMsgLog:
      return sbp_msg_log_cmp(&a->log, &b->log);
    case SbpMsgM25FlashWriteStatus:
      return sbp_msg_m25_flash_write_status_cmp(&a->m25_flash_write_status,
                                                &b->m25_flash_write_status);
    case SbpMsgMagRaw:
      return sbp_msg_mag_raw_cmp(&a->mag_raw, &b->mag_raw);
    case SbpMsgMaskSatelliteDep:
      return sbp_msg_mask_satellite_dep_cmp(&a->mask_satellite_dep,
                                            &b->mask_satellite_dep);
    case SbpMsgMaskSatellite:
      return sbp_msg_mask_satellite_cmp(&a->mask_satellite, &b->mask_satellite);
    case SbpMsgMeasurementState:
      return sbp_msg_measurement_state_cmp(&a->measurement_state,
                                           &b->measurement_state);
    case SbpMsgNapDeviceDnaReq:
      return sbp_msg_nap_device_dna_req_cmp(&a->nap_device_dna_req,
                                            &b->nap_device_dna_req);
    case SbpMsgNapDeviceDnaResp:
      return sbp_msg_nap_device_dna_resp_cmp(&a->nap_device_dna_resp,
                                             &b->nap_device_dna_resp);
    case SbpMsgNdbEvent:
      return sbp_msg_ndb_event_cmp(&a->ndb_event, &b->ndb_event);
    case SbpMsgNetworkBandwidthUsage:
      return sbp_msg_network_bandwidth_usage_cmp(&a->network_bandwidth_usage,
                                                 &b->network_bandwidth_usage);
    case SbpMsgNetworkStateReq:
      return sbp_msg_network_state_req_cmp(&a->network_state_req,
                                           &b->network_state_req);
    case SbpMsgNetworkStateResp:
      return sbp_msg_network_state_resp_cmp(&a->network_state_resp,
                                            &b->network_state_resp);
    case SbpMsgObsDepA:
      return sbp_msg_obs_dep_a_cmp(&a->obs_dep_a, &b->obs_dep_a);
    case SbpMsgObsDepB:
      return sbp_msg_obs_dep_b_cmp(&a->obs_dep_b, &b->obs_dep_b);
    case SbpMsgObsDepC:
      return sbp_msg_obs_dep_c_cmp(&a->obs_dep_c, &b->obs_dep_c);
    case SbpMsgObs:
      return sbp_msg_obs_cmp(&a->obs, &b->obs);
    case SbpMsgOdometry:
      return sbp_msg_odometry_cmp(&a->odometry, &b->odometry);
    case SbpMsgOrientEuler:
      return sbp_msg_orient_euler_cmp(&a->orient_euler, &b->orient_euler);
    case SbpMsgOrientQuat:
      return sbp_msg_orient_quat_cmp(&a->orient_quat, &b->orient_quat);
    case SbpMsgOsr:
      return sbp_msg_osr_cmp(&a->osr, &b->osr);
    case SbpMsgPosEcefCovGnss:
      return sbp_msg_pos_ecef_cov_gnss_cmp(&a->pos_ecef_cov_gnss,
                                           &b->pos_ecef_cov_gnss);
    case SbpMsgPosEcefCov:
      return sbp_msg_pos_ecef_cov_cmp(&a->pos_ecef_cov, &b->pos_ecef_cov);
    case SbpMsgPosEcefDepA:
      return sbp_msg_pos_ecef_dep_a_cmp(&a->pos_ecef_dep_a, &b->pos_ecef_dep_a);
    case SbpMsgPosEcefGnss:
      return sbp_msg_pos_ecef_gnss_cmp(&a->pos_ecef_gnss, &b->pos_ecef_gnss);
    case SbpMsgPosEcef:
      return sbp_msg_pos_ecef_cmp(&a->pos_ecef, &b->pos_ecef);
    case SbpMsgPosLlhAcc:
      return sbp_msg_pos_llh_acc_cmp(&a->pos_llh_acc, &b->pos_llh_acc);
    case SbpMsgPosLlhCovGnss:
      return sbp_msg_pos_llh_cov_gnss_cmp(&a->pos_llh_cov_gnss,
                                          &b->pos_llh_cov_gnss);
    case SbpMsgPosLlhCov:
      return sbp_msg_pos_llh_cov_cmp(&a->pos_llh_cov, &b->pos_llh_cov);
    case SbpMsgPosLlhDepA:
      return sbp_msg_pos_llh_dep_a_cmp(&a->pos_llh_dep_a, &b->pos_llh_dep_a);
    case SbpMsgPosLlhGnss:
      return sbp_msg_pos_llh_gnss_cmp(&a->pos_llh_gnss, &b->pos_llh_gnss);
    case SbpMsgPosLlh:
      return sbp_msg_pos_llh_cmp(&a->pos_llh, &b->pos_llh);
    case SbpMsgPpsTime:
      return sbp_msg_pps_time_cmp(&a->pps_time, &b->pps_time);
    case SbpMsgPrintDep:
      return sbp_msg_print_dep_cmp(&a->print_dep, &b->print_dep);
    case SbpMsgProtectionLevelDepA:
      return sbp_msg_protection_level_dep_a_cmp(&a->protection_level_dep_a,
                                                &b->protection_level_dep_a);
    case SbpMsgProtectionLevel:
      return sbp_msg_protection_level_cmp(&a->protection_level,
                                          &b->protection_level);
    case SbpMsgResetDep:
      return sbp_msg_reset_dep_cmp(&a->reset_dep, &b->reset_dep);
    case SbpMsgResetFilters:
      return sbp_msg_reset_filters_cmp(&a->reset_filters, &b->reset_filters);
    case SbpMsgReset:
      return sbp_msg_reset_cmp(&a->reset, &b->reset);
    case SbpMsgSbasRaw:
      return sbp_msg_sbas_raw_cmp(&a->sbas_raw, &b->sbas_raw);
    case SbpMsgSetTime:
      return sbp_msg_set_time_cmp(&a->set_time, &b->set_time);
    case SbpMsgSettingsReadByIndexDone:
      return sbp_msg_settings_read_by_index_done_cmp(
          &a->settings_read_by_index_done, &b->settings_read_by_index_done);
    case SbpMsgSettingsReadByIndexReq:
      return sbp_msg_settings_read_by_index_req_cmp(
          &a->settings_read_by_index_req, &b->settings_read_by_index_req);
    case SbpMsgSettingsReadByIndexResp:
      return sbp_msg_settings_read_by_index_resp_cmp(
          &a->settings_read_by_index_resp, &b->settings_read_by_index_resp);
    case SbpMsgSettingsReadReq:
      return sbp_msg_settings_read_req_cmp(&a->settings_read_req,
                                           &b->settings_read_req);
    case SbpMsgSettingsReadResp:
      return sbp_msg_settings_read_resp_cmp(&a->settings_read_resp,
                                            &b->settings_read_resp);
    case SbpMsgSettingsRegisterResp:
      return sbp_msg_settings_register_resp_cmp(&a->settings_register_resp,
                                                &b->settings_register_resp);
    case SbpMsgSettingsRegister:
      return sbp_msg_settings_register_cmp(&a->settings_register,
                                           &b->settings_register);
    case SbpMsgSettingsSave:
      return sbp_msg_settings_save_cmp(&a->settings_save, &b->settings_save);
    case SbpMsgSettingsWriteResp:
      return sbp_msg_settings_write_resp_cmp(&a->settings_write_resp,
                                             &b->settings_write_resp);
    case SbpMsgSettingsWrite:
      return sbp_msg_settings_write_cmp(&a->settings_write, &b->settings_write);
    case SbpMsgSolnMetaDepA:
      return sbp_msg_soln_meta_dep_a_cmp(&a->soln_meta_dep_a,
                                         &b->soln_meta_dep_a);
    case SbpMsgSolnMeta:
      return sbp_msg_soln_meta_cmp(&a->soln_meta, &b->soln_meta);
    case SbpMsgSpecanDep:
      return sbp_msg_specan_dep_cmp(&a->specan_dep, &b->specan_dep);
    case SbpMsgSpecan:
      return sbp_msg_specan_cmp(&a->specan, &b->specan);
    case SbpMsgSsrCodeBiases:
      return sbp_msg_ssr_code_biases_cmp(&a->ssr_code_biases,
                                         &b->ssr_code_biases);
    case SbpMsgSsrGridDefinitionDepA:
      return sbp_msg_ssr_grid_definition_dep_a_cmp(
          &a->ssr_grid_definition_dep_a, &b->ssr_grid_definition_dep_a);
    case SbpMsgSsrGriddedCorrectionDepA:
      return sbp_msg_ssr_gridded_correction_dep_a_cmp(
          &a->ssr_gridded_correction_dep_a, &b->ssr_gridded_correction_dep_a);
    case SbpMsgSsrGriddedCorrectionNoStdDepA:
      return sbp_msg_ssr_gridded_correction_no_std_dep_a_cmp(
          &a->ssr_gridded_correction_no_std_dep_a,
          &b->ssr_gridded_correction_no_std_dep_a);
    case SbpMsgSsrGriddedCorrection:
      return sbp_msg_ssr_gridded_correction_cmp(&a->ssr_gridded_correction,
                                                &b->ssr_gridded_correction);
    case SbpMsgSsrOrbitClockDepA:
      return sbp_msg_ssr_orbit_clock_dep_a_cmp(&a->ssr_orbit_clock_dep_a,
                                               &b->ssr_orbit_clock_dep_a);
    case SbpMsgSsrOrbitClock:
      return sbp_msg_ssr_orbit_clock_cmp(&a->ssr_orbit_clock,
                                         &b->ssr_orbit_clock);
    case SbpMsgSsrPhaseBiases:
      return sbp_msg_ssr_phase_biases_cmp(&a->ssr_phase_biases,
                                          &b->ssr_phase_biases);
    case SbpMsgSsrSatelliteApc:
      return sbp_msg_ssr_satellite_apc_cmp(&a->ssr_satellite_apc,
                                           &b->ssr_satellite_apc);
    case SbpMsgSsrStecCorrectionDepA:
      return sbp_msg_ssr_stec_correction_dep_a_cmp(
          &a->ssr_stec_correction_dep_a, &b->ssr_stec_correction_dep_a);
    case SbpMsgSsrStecCorrection:
      return sbp_msg_ssr_stec_correction_cmp(&a->ssr_stec_correction,
                                             &b->ssr_stec_correction);
    case SbpMsgSsrTileDefinition:
      return sbp_msg_ssr_tile_definition_cmp(&a->ssr_tile_definition,
                                             &b->ssr_tile_definition);
    case SbpMsgStartup:
      return sbp_msg_startup_cmp(&a->startup, &b->startup);
    case SbpMsgStatusReport:
      return sbp_msg_status_report_cmp(&a->status_report, &b->status_report);
    case SbpMsgStmFlashLockSector:
      return sbp_msg_stm_flash_lock_sector_cmp(&a->stm_flash_lock_sector,
                                               &b->stm_flash_lock_sector);
    case SbpMsgStmFlashUnlockSector:
      return sbp_msg_stm_flash_unlock_sector_cmp(&a->stm_flash_unlock_sector,
                                                 &b->stm_flash_unlock_sector);
    case SbpMsgStmUniqueIdReq:
      return sbp_msg_stm_unique_id_req_cmp(&a->stm_unique_id_req,
                                           &b->stm_unique_id_req);
    case SbpMsgStmUniqueIdResp:
      return sbp_msg_stm_unique_id_resp_cmp(&a->stm_unique_id_resp,
                                            &b->stm_unique_id_resp);
    case SbpMsgSvAzEl:
      return sbp_msg_sv_az_el_cmp(&a->sv_az_el, &b->sv_az_el);
    case SbpMsgSvConfigurationGpsDep:
      return sbp_msg_sv_configuration_gps_dep_cmp(&a->sv_configuration_gps_dep,
                                                  &b->sv_configuration_gps_dep);
    case SbpMsgThreadState:
      return sbp_msg_thread_state_cmp(&a->thread_state, &b->thread_state);
    case SbpMsgTrackingIqDepA:
      return sbp_msg_tracking_iq_dep_a_cmp(&a->tracking_iq_dep_a,
                                           &b->tracking_iq_dep_a);
    case SbpMsgTrackingIqDepB:
      return sbp_msg_tracking_iq_dep_b_cmp(&a->tracking_iq_dep_b,
                                           &b->tracking_iq_dep_b);
    case SbpMsgTrackingIq:
      return sbp_msg_tracking_iq_cmp(&a->tracking_iq, &b->tracking_iq);
    case SbpMsgTrackingStateDepA:
      return sbp_msg_tracking_state_dep_a_cmp(&a->tracking_state_dep_a,
                                              &b->tracking_state_dep_a);
    case SbpMsgTrackingStateDepB:
      return sbp_msg_tracking_state_dep_b_cmp(&a->tracking_state_dep_b,
                                              &b->tracking_state_dep_b);
    case SbpMsgTrackingStateDetailedDepA:
      return sbp_msg_tracking_state_detailed_dep_a_cmp(
          &a->tracking_state_detailed_dep_a, &b->tracking_state_detailed_dep_a);
    case SbpMsgTrackingStateDetailedDep:
      return sbp_msg_tracking_state_detailed_dep_cmp(
          &a->tracking_state_detailed_dep, &b->tracking_state_detailed_dep);
    case SbpMsgTrackingState:
      return sbp_msg_tracking_state_cmp(&a->tracking_state, &b->tracking_state);
    case SbpMsgUartStateDepa:
      return sbp_msg_uart_state_depa_cmp(&a->uart_state_depa,
                                         &b->uart_state_depa);
    case SbpMsgUartState:
      return sbp_msg_uart_state_cmp(&a->uart_state, &b->uart_state);
    case SbpMsgUserData:
      return sbp_msg_user_data_cmp(&a->user_data, &b->user_data);
    case SbpMsgUtcTimeGnss:
      return sbp_msg_utc_time_gnss_cmp(&a->utc_time_gnss, &b->utc_time_gnss);
    case SbpMsgUtcTime:
      return sbp_msg_utc_time_cmp(&a->utc_time, &b->utc_time);
    case SbpMsgVelBody:
      return sbp_msg_vel_body_cmp(&a->vel_body, &b->vel_body);
    case SbpMsgVelCog:
      return sbp_msg_vel_cog_cmp(&a->vel_cog, &b->vel_cog);
    case SbpMsgVelEcefCovGnss:
      return sbp_msg_vel_ecef_cov_gnss_cmp(&a->vel_ecef_cov_gnss,
                                           &b->vel_ecef_cov_gnss);
    case SbpMsgVelEcefCov:
      return sbp_msg_vel_ecef_cov_cmp(&a->vel_ecef_cov, &b->vel_ecef_cov);
    case SbpMsgVelEcefDepA:
      return sbp_msg_vel_ecef_dep_a_cmp(&a->vel_ecef_dep_a, &b->vel_ecef_dep_a);
    case SbpMsgVelEcefGnss:
      return sbp_msg_vel_ecef_gnss_cmp(&a->vel_ecef_gnss, &b->vel_ecef_gnss);
    case SbpMsgVelEcef:
      return sbp_msg_vel_ecef_cmp(&a->vel_ecef, &b->vel_ecef);
    case SbpMsgVelNedCovGnss:
      return sbp_msg_vel_ned_cov_gnss_cmp(&a->vel_ned_cov_gnss,
                                          &b->vel_ned_cov_gnss);
    case SbpMsgVelNedCov:
      return sbp_msg_vel_ned_cov_cmp(&a->vel_ned_cov, &b->vel_ned_cov);
    case SbpMsgVelNedDepA:
      return sbp_msg_vel_ned_dep_a_cmp(&a->vel_ned_dep_a, &b->vel_ned_dep_a);
    case SbpMsgVelNedGnss:
      return sbp_msg_vel_ned_gnss_cmp(&a->vel_ned_gnss, &b->vel_ned_gnss);
    case SbpMsgVelNed:
      return sbp_msg_vel_ned_cmp(&a->vel_ned, &b->vel_ned);
    case SbpMsgWheeltick:
      return sbp_msg_wheeltick_cmp(&a->wheeltick, &b->wheeltick);
    default:
      break;
  }
  return 0;
}

#ifdef __cplusplus
}
#endif

#endif /* LIBSBP_V4_SBP_MSG_H */
