#ifndef NEW_MESSAGES_UNION_H
#define NEW_MESSAGES_UNION_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <libsbp/unpacked/tracking.h>
#include <libsbp/unpacked/settings.h>
#include <libsbp/unpacked/ssr.h>
#include <libsbp/unpacked/ext_events.h>
#include <libsbp/unpacked/vehicle.h>
#include <libsbp/unpacked/user.h>
#include <libsbp/unpacked/linux.h>
#include <libsbp/unpacked/navigation.h>
#include <libsbp/unpacked/file_io.h>
#include <libsbp/unpacked/logging.h>
#include <libsbp/unpacked/bootload.h>
#include <libsbp/unpacked/system.h>
#include <libsbp/unpacked/observation.h>
#include <libsbp/unpacked/sbas.h>
#include <libsbp/unpacked/piksi.h>
#include <libsbp/unpacked/flash.h>
#include <libsbp/unpacked/imu.h>
#include <libsbp/unpacked/ndb.h>
#include <libsbp/unpacked/acquisition.h>
#include <libsbp/unpacked/solution_meta.h>
#include <libsbp/unpacked/orientation.h>
#include <libsbp/unpacked/mag.h>
#include <libsbp/unpacked/gnss.h>

#ifdef __cplusplus
  extern "C" {
#endif

typedef union {
  sbp_msg_tracking_state_detailed_dep_a_t tracking_state_detailed_dep_a;
  sbp_msg_tracking_state_detailed_dep_t tracking_state_detailed_dep;
  sbp_msg_tracking_state_t tracking_state;
  sbp_msg_measurement_state_t measurement_state;
  sbp_msg_tracking_iq_t tracking_iq;
  sbp_msg_tracking_iq_dep_b_t tracking_iq_dep_b;
  sbp_msg_tracking_iq_dep_a_t tracking_iq_dep_a;
  sbp_msg_tracking_state_dep_a_t tracking_state_dep_a;
  sbp_msg_tracking_state_dep_b_t tracking_state_dep_b;
  sbp_msg_settings_save_t settings_save;
  sbp_msg_settings_write_t settings_write;
  sbp_msg_settings_write_resp_t settings_write_resp;
  sbp_msg_settings_read_req_t settings_read_req;
  sbp_msg_settings_read_resp_t settings_read_resp;
  sbp_msg_settings_read_by_index_req_t settings_read_by_index_req;
  sbp_msg_settings_read_by_index_resp_t settings_read_by_index_resp;
  sbp_msg_settings_read_by_index_done_t settings_read_by_index_done;
  sbp_msg_settings_register_t settings_register;
  sbp_msg_settings_register_resp_t settings_register_resp;
  sbp_msg_ssr_orbit_clock_t ssr_orbit_clock;
  sbp_msg_ssr_code_biases_t ssr_code_biases;
  sbp_msg_ssr_phase_biases_t ssr_phase_biases;
  sbp_msg_ssr_stec_correction_t ssr_stec_correction;
  sbp_msg_ssr_gridded_correction_t ssr_gridded_correction;
  sbp_msg_ssr_tile_definition_t ssr_tile_definition;
  sbp_msg_ssr_satellite_apc_t ssr_satellite_apc;
  sbp_msg_ssr_orbit_clock_dep_a_t ssr_orbit_clock_dep_a;
  sbp_msg_ssr_stec_correction_dep_a_t ssr_stec_correction_dep_a;
  sbp_msg_ssr_gridded_correction_no_std_dep_a_t ssr_gridded_correction_no_std_dep_a;
  sbp_msg_ssr_gridded_correction_dep_a_t ssr_gridded_correction_dep_a;
  sbp_msg_ssr_grid_definition_dep_a_t ssr_grid_definition_dep_a;
  sbp_msg_ext_event_t ext_event;
  sbp_msg_odometry_t odometry;
  sbp_msg_wheeltick_t wheeltick;
  sbp_msg_user_data_t user_data;
  sbp_msg_linux_cpu_state_dep_a_t linux_cpu_state_dep_a;
  sbp_msg_linux_mem_state_dep_a_t linux_mem_state_dep_a;
  sbp_msg_linux_sys_state_dep_a_t linux_sys_state_dep_a;
  sbp_msg_linux_process_socket_counts_t linux_process_socket_counts;
  sbp_msg_linux_process_socket_queues_t linux_process_socket_queues;
  sbp_msg_linux_socket_usage_t linux_socket_usage;
  sbp_msg_linux_process_fd_count_t linux_process_fd_count;
  sbp_msg_linux_process_fd_summary_t linux_process_fd_summary;
  sbp_msg_linux_cpu_state_t linux_cpu_state;
  sbp_msg_linux_mem_state_t linux_mem_state;
  sbp_msg_linux_sys_state_t linux_sys_state;
  sbp_msg_gps_time_t gps_time;
  sbp_msg_gps_time_gnss_t gps_time_gnss;
  sbp_msg_utc_time_t utc_time;
  sbp_msg_utc_time_gnss_t utc_time_gnss;
  sbp_msg_dops_t dops;
  sbp_msg_pos_ecef_t pos_ecef;
  sbp_msg_pos_ecef_cov_t pos_ecef_cov;
  sbp_msg_pos_llh_t pos_llh;
  sbp_msg_pos_llh_cov_t pos_llh_cov;
  sbp_msg_baseline_ecef_t baseline_ecef;
  sbp_msg_baseline_ned_t baseline_ned;
  sbp_msg_vel_ecef_t vel_ecef;
  sbp_msg_vel_ecef_cov_t vel_ecef_cov;
  sbp_msg_vel_ned_t vel_ned;
  sbp_msg_vel_ned_cov_t vel_ned_cov;
  sbp_msg_pos_ecef_gnss_t pos_ecef_gnss;
  sbp_msg_pos_ecef_cov_gnss_t pos_ecef_cov_gnss;
  sbp_msg_pos_llh_gnss_t pos_llh_gnss;
  sbp_msg_pos_llh_cov_gnss_t pos_llh_cov_gnss;
  sbp_msg_vel_ecef_gnss_t vel_ecef_gnss;
  sbp_msg_vel_ecef_cov_gnss_t vel_ecef_cov_gnss;
  sbp_msg_vel_ned_gnss_t vel_ned_gnss;
  sbp_msg_vel_ned_cov_gnss_t vel_ned_cov_gnss;
  sbp_msg_vel_body_t vel_body;
  sbp_msg_age_corrections_t age_corrections;
  sbp_msg_gps_time_dep_a_t gps_time_dep_a;
  sbp_msg_dops_dep_a_t dops_dep_a;
  sbp_msg_pos_ecef_dep_a_t pos_ecef_dep_a;
  sbp_msg_pos_llh_dep_a_t pos_llh_dep_a;
  sbp_msg_baseline_ecef_dep_a_t baseline_ecef_dep_a;
  sbp_msg_baseline_ned_dep_a_t baseline_ned_dep_a;
  sbp_msg_vel_ecef_dep_a_t vel_ecef_dep_a;
  sbp_msg_vel_ned_dep_a_t vel_ned_dep_a;
  sbp_msg_baseline_heading_dep_a_t baseline_heading_dep_a;
  sbp_msg_protection_level_dep_a_t protection_level_dep_a;
  sbp_msg_protection_level_t protection_level;
  sbp_msg_fileio_read_req_t fileio_read_req;
  sbp_msg_fileio_read_resp_t fileio_read_resp;
  sbp_msg_fileio_read_dir_req_t fileio_read_dir_req;
  sbp_msg_fileio_read_dir_resp_t fileio_read_dir_resp;
  sbp_msg_fileio_remove_t fileio_remove;
  sbp_msg_fileio_write_req_t fileio_write_req;
  sbp_msg_fileio_write_resp_t fileio_write_resp;
  sbp_msg_fileio_config_req_t fileio_config_req;
  sbp_msg_fileio_config_resp_t fileio_config_resp;
  sbp_msg_log_t log;
  sbp_msg_fwd_t fwd;
  sbp_msg_print_dep_t print_dep;
  sbp_msg_bootloader_handshake_req_t bootloader_handshake_req;
  sbp_msg_bootloader_handshake_resp_t bootloader_handshake_resp;
  sbp_msg_bootloader_jump_to_app_t bootloader_jump_to_app;
  sbp_msg_nap_device_dna_req_t nap_device_dna_req;
  sbp_msg_nap_device_dna_resp_t nap_device_dna_resp;
  sbp_msg_bootloader_handshake_dep_a_t bootloader_handshake_dep_a;
  sbp_msg_startup_t startup;
  sbp_msg_dgnss_status_t dgnss_status;
  sbp_msg_heartbeat_t heartbeat;
  sbp_msg_status_report_t status_report;
  sbp_msg_ins_status_t ins_status;
  sbp_msg_csac_telemetry_t csac_telemetry;
  sbp_msg_csac_telemetry_labels_t csac_telemetry_labels;
  sbp_msg_ins_updates_t ins_updates;
  sbp_msg_gnss_time_offset_t gnss_time_offset;
  sbp_msg_pps_time_t pps_time;
  sbp_msg_group_meta_t group_meta;
  sbp_msg_obs_t obs;
  sbp_msg_base_pos_llh_t base_pos_llh;
  sbp_msg_base_pos_ecef_t base_pos_ecef;
  sbp_msg_ephemeris_gps_dep_e_t ephemeris_gps_dep_e;
  sbp_msg_ephemeris_gps_dep_f_t ephemeris_gps_dep_f;
  sbp_msg_ephemeris_gps_t ephemeris_gps;
  sbp_msg_ephemeris_qzss_t ephemeris_qzss;
  sbp_msg_ephemeris_bds_t ephemeris_bds;
  sbp_msg_ephemeris_gal_dep_a_t ephemeris_gal_dep_a;
  sbp_msg_ephemeris_gal_t ephemeris_gal;
  sbp_msg_ephemeris_sbas_dep_a_t ephemeris_sbas_dep_a;
  sbp_msg_ephemeris_glo_dep_a_t ephemeris_glo_dep_a;
  sbp_msg_ephemeris_sbas_dep_b_t ephemeris_sbas_dep_b;
  sbp_msg_ephemeris_sbas_t ephemeris_sbas;
  sbp_msg_ephemeris_glo_dep_b_t ephemeris_glo_dep_b;
  sbp_msg_ephemeris_glo_dep_c_t ephemeris_glo_dep_c;
  sbp_msg_ephemeris_glo_dep_d_t ephemeris_glo_dep_d;
  sbp_msg_ephemeris_glo_t ephemeris_glo;
  sbp_msg_ephemeris_dep_d_t ephemeris_dep_d;
  sbp_msg_ephemeris_dep_a_t ephemeris_dep_a;
  sbp_msg_ephemeris_dep_b_t ephemeris_dep_b;
  sbp_msg_ephemeris_dep_c_t ephemeris_dep_c;
  sbp_msg_obs_dep_a_t obs_dep_a;
  sbp_msg_obs_dep_b_t obs_dep_b;
  sbp_msg_obs_dep_c_t obs_dep_c;
  sbp_msg_iono_t iono;
  sbp_msg_sv_configuration_gps_dep_t sv_configuration_gps_dep;
  sbp_msg_gnss_capb_t gnss_capb;
  sbp_msg_group_delay_dep_a_t group_delay_dep_a;
  sbp_msg_group_delay_dep_b_t group_delay_dep_b;
  sbp_msg_group_delay_t group_delay;
  sbp_msg_almanac_gps_dep_t almanac_gps_dep;
  sbp_msg_almanac_gps_t almanac_gps;
  sbp_msg_almanac_glo_dep_t almanac_glo_dep;
  sbp_msg_almanac_glo_t almanac_glo;
  sbp_msg_glo_biases_t glo_biases;
  sbp_msg_sv_az_el_t sv_az_el;
  sbp_msg_osr_t osr;
  sbp_msg_sbas_raw_t sbas_raw;
  sbp_msg_almanac_t almanac;
  sbp_msg_set_time_t set_time;
  sbp_msg_reset_t reset;
  sbp_msg_reset_dep_t reset_dep;
  sbp_msg_cw_results_t cw_results;
  sbp_msg_cw_start_t cw_start;
  sbp_msg_reset_filters_t reset_filters;
  sbp_msg_init_base_dep_t init_base_dep;
  sbp_msg_thread_state_t thread_state;
  sbp_msg_uart_state_t uart_state;
  sbp_msg_uart_state_depa_t uart_state_depa;
  sbp_msg_iar_state_t iar_state;
  sbp_msg_mask_satellite_t mask_satellite;
  sbp_msg_mask_satellite_dep_t mask_satellite_dep;
  sbp_msg_device_monitor_t device_monitor;
  sbp_msg_command_req_t command_req;
  sbp_msg_command_resp_t command_resp;
  sbp_msg_command_output_t command_output;
  sbp_msg_network_state_req_t network_state_req;
  sbp_msg_network_state_resp_t network_state_resp;
  sbp_msg_network_bandwidth_usage_t network_bandwidth_usage;
  sbp_msg_cell_modem_status_t cell_modem_status;
  sbp_msg_specan_dep_t specan_dep;
  sbp_msg_specan_t specan;
  sbp_msg_front_end_gain_t front_end_gain;
  sbp_msg_flash_program_t flash_program;
  sbp_msg_flash_done_t flash_done;
  sbp_msg_flash_read_req_t flash_read_req;
  sbp_msg_flash_read_resp_t flash_read_resp;
  sbp_msg_flash_erase_t flash_erase;
  sbp_msg_stm_flash_lock_sector_t stm_flash_lock_sector;
  sbp_msg_stm_flash_unlock_sector_t stm_flash_unlock_sector;
  sbp_msg_stm_unique_id_req_t stm_unique_id_req;
  sbp_msg_stm_unique_id_resp_t stm_unique_id_resp;
  sbp_msg_m25_flash_write_status_t m25_flash_write_status;
  sbp_msg_imu_raw_t imu_raw;
  sbp_msg_imu_aux_t imu_aux;
  sbp_msg_ndb_event_t ndb_event;
  sbp_msg_acq_result_t acq_result;
  sbp_msg_acq_result_dep_c_t acq_result_dep_c;
  sbp_msg_acq_result_dep_b_t acq_result_dep_b;
  sbp_msg_acq_result_dep_a_t acq_result_dep_a;
  sbp_msg_acq_sv_profile_t acq_sv_profile;
  sbp_msg_acq_sv_profile_dep_t acq_sv_profile_dep;
  sbp_msg_soln_meta_dep_a_t soln_meta_dep_a;
  sbp_msg_soln_meta_t soln_meta;
  sbp_msg_baseline_heading_t baseline_heading;
  sbp_msg_orient_quat_t orient_quat;
  sbp_msg_orient_euler_t orient_euler;
  sbp_msg_angular_rate_t angular_rate;
  sbp_msg_mag_raw_t mag_raw;
} sbp_msg_t;

static inline s8 sbp_pack_msg(uint8_t *buf, uint8_t len, uint8_t *n_written, uint16_t msg_type, const sbp_msg_t *msg) {
  switch(msg_type) {
    case SBP_MSG_TRACKING_STATE_DETAILED_DEP_A:
      return sbp_pack_sbp_msg_tracking_state_detailed_dep_a_t(buf, len, n_written, &msg->tracking_state_detailed_dep_a);
    case SBP_MSG_TRACKING_STATE_DETAILED_DEP:
      return sbp_pack_sbp_msg_tracking_state_detailed_dep_t(buf, len, n_written, &msg->tracking_state_detailed_dep);
    case SBP_MSG_TRACKING_STATE:
      return sbp_pack_sbp_msg_tracking_state_t(buf, len, n_written, &msg->tracking_state);
    case SBP_MSG_MEASUREMENT_STATE:
      return sbp_pack_sbp_msg_measurement_state_t(buf, len, n_written, &msg->measurement_state);
    case SBP_MSG_TRACKING_IQ:
      return sbp_pack_sbp_msg_tracking_iq_t(buf, len, n_written, &msg->tracking_iq);
    case SBP_MSG_TRACKING_IQ_DEP_B:
      return sbp_pack_sbp_msg_tracking_iq_dep_b_t(buf, len, n_written, &msg->tracking_iq_dep_b);
    case SBP_MSG_TRACKING_IQ_DEP_A:
      return sbp_pack_sbp_msg_tracking_iq_dep_a_t(buf, len, n_written, &msg->tracking_iq_dep_a);
    case SBP_MSG_TRACKING_STATE_DEP_A:
      return sbp_pack_sbp_msg_tracking_state_dep_a_t(buf, len, n_written, &msg->tracking_state_dep_a);
    case SBP_MSG_TRACKING_STATE_DEP_B:
      return sbp_pack_sbp_msg_tracking_state_dep_b_t(buf, len, n_written, &msg->tracking_state_dep_b);
    case SBP_MSG_SETTINGS_SAVE:
      return sbp_pack_sbp_msg_settings_save_t(buf, len, n_written, &msg->settings_save);
    case SBP_MSG_SETTINGS_WRITE:
      return sbp_pack_sbp_msg_settings_write_t(buf, len, n_written, &msg->settings_write);
    case SBP_MSG_SETTINGS_WRITE_RESP:
      return sbp_pack_sbp_msg_settings_write_resp_t(buf, len, n_written, &msg->settings_write_resp);
    case SBP_MSG_SETTINGS_READ_REQ:
      return sbp_pack_sbp_msg_settings_read_req_t(buf, len, n_written, &msg->settings_read_req);
    case SBP_MSG_SETTINGS_READ_RESP:
      return sbp_pack_sbp_msg_settings_read_resp_t(buf, len, n_written, &msg->settings_read_resp);
    case SBP_MSG_SETTINGS_READ_BY_INDEX_REQ:
      return sbp_pack_sbp_msg_settings_read_by_index_req_t(buf, len, n_written, &msg->settings_read_by_index_req);
    case SBP_MSG_SETTINGS_READ_BY_INDEX_RESP:
      return sbp_pack_sbp_msg_settings_read_by_index_resp_t(buf, len, n_written, &msg->settings_read_by_index_resp);
    case SBP_MSG_SETTINGS_READ_BY_INDEX_DONE:
      return sbp_pack_sbp_msg_settings_read_by_index_done_t(buf, len, n_written, &msg->settings_read_by_index_done);
    case SBP_MSG_SETTINGS_REGISTER:
      return sbp_pack_sbp_msg_settings_register_t(buf, len, n_written, &msg->settings_register);
    case SBP_MSG_SETTINGS_REGISTER_RESP:
      return sbp_pack_sbp_msg_settings_register_resp_t(buf, len, n_written, &msg->settings_register_resp);
    case SBP_MSG_SSR_ORBIT_CLOCK:
      return sbp_pack_sbp_msg_ssr_orbit_clock_t(buf, len, n_written, &msg->ssr_orbit_clock);
    case SBP_MSG_SSR_CODE_BIASES:
      return sbp_pack_sbp_msg_ssr_code_biases_t(buf, len, n_written, &msg->ssr_code_biases);
    case SBP_MSG_SSR_PHASE_BIASES:
      return sbp_pack_sbp_msg_ssr_phase_biases_t(buf, len, n_written, &msg->ssr_phase_biases);
    case SBP_MSG_SSR_STEC_CORRECTION:
      return sbp_pack_sbp_msg_ssr_stec_correction_t(buf, len, n_written, &msg->ssr_stec_correction);
    case SBP_MSG_SSR_GRIDDED_CORRECTION:
      return sbp_pack_sbp_msg_ssr_gridded_correction_t(buf, len, n_written, &msg->ssr_gridded_correction);
    case SBP_MSG_SSR_TILE_DEFINITION:
      return sbp_pack_sbp_msg_ssr_tile_definition_t(buf, len, n_written, &msg->ssr_tile_definition);
    case SBP_MSG_SSR_SATELLITE_APC:
      return sbp_pack_sbp_msg_ssr_satellite_apc_t(buf, len, n_written, &msg->ssr_satellite_apc);
    case SBP_MSG_SSR_ORBIT_CLOCK_DEP_A:
      return sbp_pack_sbp_msg_ssr_orbit_clock_dep_a_t(buf, len, n_written, &msg->ssr_orbit_clock_dep_a);
    case SBP_MSG_SSR_STEC_CORRECTION_DEP_A:
      return sbp_pack_sbp_msg_ssr_stec_correction_dep_a_t(buf, len, n_written, &msg->ssr_stec_correction_dep_a);
    case SBP_MSG_SSR_GRIDDED_CORRECTION_NO_STD_DEP_A:
      return sbp_pack_sbp_msg_ssr_gridded_correction_no_std_dep_a_t(buf, len, n_written, &msg->ssr_gridded_correction_no_std_dep_a);
    case SBP_MSG_SSR_GRIDDED_CORRECTION_DEP_A:
      return sbp_pack_sbp_msg_ssr_gridded_correction_dep_a_t(buf, len, n_written, &msg->ssr_gridded_correction_dep_a);
    case SBP_MSG_SSR_GRID_DEFINITION_DEP_A:
      return sbp_pack_sbp_msg_ssr_grid_definition_dep_a_t(buf, len, n_written, &msg->ssr_grid_definition_dep_a);
    case SBP_MSG_EXT_EVENT:
      return sbp_pack_sbp_msg_ext_event_t(buf, len, n_written, &msg->ext_event);
    case SBP_MSG_ODOMETRY:
      return sbp_pack_sbp_msg_odometry_t(buf, len, n_written, &msg->odometry);
    case SBP_MSG_WHEELTICK:
      return sbp_pack_sbp_msg_wheeltick_t(buf, len, n_written, &msg->wheeltick);
    case SBP_MSG_USER_DATA:
      return sbp_pack_sbp_msg_user_data_t(buf, len, n_written, &msg->user_data);
    case SBP_MSG_LINUX_CPU_STATE_DEP_A:
      return sbp_pack_sbp_msg_linux_cpu_state_dep_a_t(buf, len, n_written, &msg->linux_cpu_state_dep_a);
    case SBP_MSG_LINUX_MEM_STATE_DEP_A:
      return sbp_pack_sbp_msg_linux_mem_state_dep_a_t(buf, len, n_written, &msg->linux_mem_state_dep_a);
    case SBP_MSG_LINUX_SYS_STATE_DEP_A:
      return sbp_pack_sbp_msg_linux_sys_state_dep_a_t(buf, len, n_written, &msg->linux_sys_state_dep_a);
    case SBP_MSG_LINUX_PROCESS_SOCKET_COUNTS:
      return sbp_pack_sbp_msg_linux_process_socket_counts_t(buf, len, n_written, &msg->linux_process_socket_counts);
    case SBP_MSG_LINUX_PROCESS_SOCKET_QUEUES:
      return sbp_pack_sbp_msg_linux_process_socket_queues_t(buf, len, n_written, &msg->linux_process_socket_queues);
    case SBP_MSG_LINUX_SOCKET_USAGE:
      return sbp_pack_sbp_msg_linux_socket_usage_t(buf, len, n_written, &msg->linux_socket_usage);
    case SBP_MSG_LINUX_PROCESS_FD_COUNT:
      return sbp_pack_sbp_msg_linux_process_fd_count_t(buf, len, n_written, &msg->linux_process_fd_count);
    case SBP_MSG_LINUX_PROCESS_FD_SUMMARY:
      return sbp_pack_sbp_msg_linux_process_fd_summary_t(buf, len, n_written, &msg->linux_process_fd_summary);
    case SBP_MSG_LINUX_CPU_STATE:
      return sbp_pack_sbp_msg_linux_cpu_state_t(buf, len, n_written, &msg->linux_cpu_state);
    case SBP_MSG_LINUX_MEM_STATE:
      return sbp_pack_sbp_msg_linux_mem_state_t(buf, len, n_written, &msg->linux_mem_state);
    case SBP_MSG_LINUX_SYS_STATE:
      return sbp_pack_sbp_msg_linux_sys_state_t(buf, len, n_written, &msg->linux_sys_state);
    case SBP_MSG_GPS_TIME:
      return sbp_pack_sbp_msg_gps_time_t(buf, len, n_written, &msg->gps_time);
    case SBP_MSG_GPS_TIME_GNSS:
      return sbp_pack_sbp_msg_gps_time_gnss_t(buf, len, n_written, &msg->gps_time_gnss);
    case SBP_MSG_UTC_TIME:
      return sbp_pack_sbp_msg_utc_time_t(buf, len, n_written, &msg->utc_time);
    case SBP_MSG_UTC_TIME_GNSS:
      return sbp_pack_sbp_msg_utc_time_gnss_t(buf, len, n_written, &msg->utc_time_gnss);
    case SBP_MSG_DOPS:
      return sbp_pack_sbp_msg_dops_t(buf, len, n_written, &msg->dops);
    case SBP_MSG_POS_ECEF:
      return sbp_pack_sbp_msg_pos_ecef_t(buf, len, n_written, &msg->pos_ecef);
    case SBP_MSG_POS_ECEF_COV:
      return sbp_pack_sbp_msg_pos_ecef_cov_t(buf, len, n_written, &msg->pos_ecef_cov);
    case SBP_MSG_POS_LLH:
      return sbp_pack_sbp_msg_pos_llh_t(buf, len, n_written, &msg->pos_llh);
    case SBP_MSG_POS_LLH_COV:
      return sbp_pack_sbp_msg_pos_llh_cov_t(buf, len, n_written, &msg->pos_llh_cov);
    case SBP_MSG_BASELINE_ECEF:
      return sbp_pack_sbp_msg_baseline_ecef_t(buf, len, n_written, &msg->baseline_ecef);
    case SBP_MSG_BASELINE_NED:
      return sbp_pack_sbp_msg_baseline_ned_t(buf, len, n_written, &msg->baseline_ned);
    case SBP_MSG_VEL_ECEF:
      return sbp_pack_sbp_msg_vel_ecef_t(buf, len, n_written, &msg->vel_ecef);
    case SBP_MSG_VEL_ECEF_COV:
      return sbp_pack_sbp_msg_vel_ecef_cov_t(buf, len, n_written, &msg->vel_ecef_cov);
    case SBP_MSG_VEL_NED:
      return sbp_pack_sbp_msg_vel_ned_t(buf, len, n_written, &msg->vel_ned);
    case SBP_MSG_VEL_NED_COV:
      return sbp_pack_sbp_msg_vel_ned_cov_t(buf, len, n_written, &msg->vel_ned_cov);
    case SBP_MSG_POS_ECEF_GNSS:
      return sbp_pack_sbp_msg_pos_ecef_gnss_t(buf, len, n_written, &msg->pos_ecef_gnss);
    case SBP_MSG_POS_ECEF_COV_GNSS:
      return sbp_pack_sbp_msg_pos_ecef_cov_gnss_t(buf, len, n_written, &msg->pos_ecef_cov_gnss);
    case SBP_MSG_POS_LLH_GNSS:
      return sbp_pack_sbp_msg_pos_llh_gnss_t(buf, len, n_written, &msg->pos_llh_gnss);
    case SBP_MSG_POS_LLH_COV_GNSS:
      return sbp_pack_sbp_msg_pos_llh_cov_gnss_t(buf, len, n_written, &msg->pos_llh_cov_gnss);
    case SBP_MSG_VEL_ECEF_GNSS:
      return sbp_pack_sbp_msg_vel_ecef_gnss_t(buf, len, n_written, &msg->vel_ecef_gnss);
    case SBP_MSG_VEL_ECEF_COV_GNSS:
      return sbp_pack_sbp_msg_vel_ecef_cov_gnss_t(buf, len, n_written, &msg->vel_ecef_cov_gnss);
    case SBP_MSG_VEL_NED_GNSS:
      return sbp_pack_sbp_msg_vel_ned_gnss_t(buf, len, n_written, &msg->vel_ned_gnss);
    case SBP_MSG_VEL_NED_COV_GNSS:
      return sbp_pack_sbp_msg_vel_ned_cov_gnss_t(buf, len, n_written, &msg->vel_ned_cov_gnss);
    case SBP_MSG_VEL_BODY:
      return sbp_pack_sbp_msg_vel_body_t(buf, len, n_written, &msg->vel_body);
    case SBP_MSG_AGE_CORRECTIONS:
      return sbp_pack_sbp_msg_age_corrections_t(buf, len, n_written, &msg->age_corrections);
    case SBP_MSG_GPS_TIME_DEP_A:
      return sbp_pack_sbp_msg_gps_time_dep_a_t(buf, len, n_written, &msg->gps_time_dep_a);
    case SBP_MSG_DOPS_DEP_A:
      return sbp_pack_sbp_msg_dops_dep_a_t(buf, len, n_written, &msg->dops_dep_a);
    case SBP_MSG_POS_ECEF_DEP_A:
      return sbp_pack_sbp_msg_pos_ecef_dep_a_t(buf, len, n_written, &msg->pos_ecef_dep_a);
    case SBP_MSG_POS_LLH_DEP_A:
      return sbp_pack_sbp_msg_pos_llh_dep_a_t(buf, len, n_written, &msg->pos_llh_dep_a);
    case SBP_MSG_BASELINE_ECEF_DEP_A:
      return sbp_pack_sbp_msg_baseline_ecef_dep_a_t(buf, len, n_written, &msg->baseline_ecef_dep_a);
    case SBP_MSG_BASELINE_NED_DEP_A:
      return sbp_pack_sbp_msg_baseline_ned_dep_a_t(buf, len, n_written, &msg->baseline_ned_dep_a);
    case SBP_MSG_VEL_ECEF_DEP_A:
      return sbp_pack_sbp_msg_vel_ecef_dep_a_t(buf, len, n_written, &msg->vel_ecef_dep_a);
    case SBP_MSG_VEL_NED_DEP_A:
      return sbp_pack_sbp_msg_vel_ned_dep_a_t(buf, len, n_written, &msg->vel_ned_dep_a);
    case SBP_MSG_BASELINE_HEADING_DEP_A:
      return sbp_pack_sbp_msg_baseline_heading_dep_a_t(buf, len, n_written, &msg->baseline_heading_dep_a);
    case SBP_MSG_PROTECTION_LEVEL_DEP_A:
      return sbp_pack_sbp_msg_protection_level_dep_a_t(buf, len, n_written, &msg->protection_level_dep_a);
    case SBP_MSG_PROTECTION_LEVEL:
      return sbp_pack_sbp_msg_protection_level_t(buf, len, n_written, &msg->protection_level);
    case SBP_MSG_FILEIO_READ_REQ:
      return sbp_pack_sbp_msg_fileio_read_req_t(buf, len, n_written, &msg->fileio_read_req);
    case SBP_MSG_FILEIO_READ_RESP:
      return sbp_pack_sbp_msg_fileio_read_resp_t(buf, len, n_written, &msg->fileio_read_resp);
    case SBP_MSG_FILEIO_READ_DIR_REQ:
      return sbp_pack_sbp_msg_fileio_read_dir_req_t(buf, len, n_written, &msg->fileio_read_dir_req);
    case SBP_MSG_FILEIO_READ_DIR_RESP:
      return sbp_pack_sbp_msg_fileio_read_dir_resp_t(buf, len, n_written, &msg->fileio_read_dir_resp);
    case SBP_MSG_FILEIO_REMOVE:
      return sbp_pack_sbp_msg_fileio_remove_t(buf, len, n_written, &msg->fileio_remove);
    case SBP_MSG_FILEIO_WRITE_REQ:
      return sbp_pack_sbp_msg_fileio_write_req_t(buf, len, n_written, &msg->fileio_write_req);
    case SBP_MSG_FILEIO_WRITE_RESP:
      return sbp_pack_sbp_msg_fileio_write_resp_t(buf, len, n_written, &msg->fileio_write_resp);
    case SBP_MSG_FILEIO_CONFIG_REQ:
      return sbp_pack_sbp_msg_fileio_config_req_t(buf, len, n_written, &msg->fileio_config_req);
    case SBP_MSG_FILEIO_CONFIG_RESP:
      return sbp_pack_sbp_msg_fileio_config_resp_t(buf, len, n_written, &msg->fileio_config_resp);
    case SBP_MSG_LOG:
      return sbp_pack_sbp_msg_log_t(buf, len, n_written, &msg->log);
    case SBP_MSG_FWD:
      return sbp_pack_sbp_msg_fwd_t(buf, len, n_written, &msg->fwd);
    case SBP_MSG_PRINT_DEP:
      return sbp_pack_sbp_msg_print_dep_t(buf, len, n_written, &msg->print_dep);
    case SBP_MSG_BOOTLOADER_HANDSHAKE_REQ:
      return sbp_pack_sbp_msg_bootloader_handshake_req_t(buf, len, n_written, &msg->bootloader_handshake_req);
    case SBP_MSG_BOOTLOADER_HANDSHAKE_RESP:
      return sbp_pack_sbp_msg_bootloader_handshake_resp_t(buf, len, n_written, &msg->bootloader_handshake_resp);
    case SBP_MSG_BOOTLOADER_JUMP_TO_APP:
      return sbp_pack_sbp_msg_bootloader_jump_to_app_t(buf, len, n_written, &msg->bootloader_jump_to_app);
    case SBP_MSG_NAP_DEVICE_DNA_REQ:
      return sbp_pack_sbp_msg_nap_device_dna_req_t(buf, len, n_written, &msg->nap_device_dna_req);
    case SBP_MSG_NAP_DEVICE_DNA_RESP:
      return sbp_pack_sbp_msg_nap_device_dna_resp_t(buf, len, n_written, &msg->nap_device_dna_resp);
    case SBP_MSG_BOOTLOADER_HANDSHAKE_DEP_A:
      return sbp_pack_sbp_msg_bootloader_handshake_dep_a_t(buf, len, n_written, &msg->bootloader_handshake_dep_a);
    case SBP_MSG_STARTUP:
      return sbp_pack_sbp_msg_startup_t(buf, len, n_written, &msg->startup);
    case SBP_MSG_DGNSS_STATUS:
      return sbp_pack_sbp_msg_dgnss_status_t(buf, len, n_written, &msg->dgnss_status);
    case SBP_MSG_HEARTBEAT:
      return sbp_pack_sbp_msg_heartbeat_t(buf, len, n_written, &msg->heartbeat);
    case SBP_MSG_STATUS_REPORT:
      return sbp_pack_sbp_msg_status_report_t(buf, len, n_written, &msg->status_report);
    case SBP_MSG_INS_STATUS:
      return sbp_pack_sbp_msg_ins_status_t(buf, len, n_written, &msg->ins_status);
    case SBP_MSG_CSAC_TELEMETRY:
      return sbp_pack_sbp_msg_csac_telemetry_t(buf, len, n_written, &msg->csac_telemetry);
    case SBP_MSG_CSAC_TELEMETRY_LABELS:
      return sbp_pack_sbp_msg_csac_telemetry_labels_t(buf, len, n_written, &msg->csac_telemetry_labels);
    case SBP_MSG_INS_UPDATES:
      return sbp_pack_sbp_msg_ins_updates_t(buf, len, n_written, &msg->ins_updates);
    case SBP_MSG_GNSS_TIME_OFFSET:
      return sbp_pack_sbp_msg_gnss_time_offset_t(buf, len, n_written, &msg->gnss_time_offset);
    case SBP_MSG_PPS_TIME:
      return sbp_pack_sbp_msg_pps_time_t(buf, len, n_written, &msg->pps_time);
    case SBP_MSG_GROUP_META:
      return sbp_pack_sbp_msg_group_meta_t(buf, len, n_written, &msg->group_meta);
    case SBP_MSG_OBS:
      return sbp_pack_sbp_msg_obs_t(buf, len, n_written, &msg->obs);
    case SBP_MSG_BASE_POS_LLH:
      return sbp_pack_sbp_msg_base_pos_llh_t(buf, len, n_written, &msg->base_pos_llh);
    case SBP_MSG_BASE_POS_ECEF:
      return sbp_pack_sbp_msg_base_pos_ecef_t(buf, len, n_written, &msg->base_pos_ecef);
    case SBP_MSG_EPHEMERIS_GPS_DEP_E:
      return sbp_pack_sbp_msg_ephemeris_gps_dep_e_t(buf, len, n_written, &msg->ephemeris_gps_dep_e);
    case SBP_MSG_EPHEMERIS_GPS_DEP_F:
      return sbp_pack_sbp_msg_ephemeris_gps_dep_f_t(buf, len, n_written, &msg->ephemeris_gps_dep_f);
    case SBP_MSG_EPHEMERIS_GPS:
      return sbp_pack_sbp_msg_ephemeris_gps_t(buf, len, n_written, &msg->ephemeris_gps);
    case SBP_MSG_EPHEMERIS_QZSS:
      return sbp_pack_sbp_msg_ephemeris_qzss_t(buf, len, n_written, &msg->ephemeris_qzss);
    case SBP_MSG_EPHEMERIS_BDS:
      return sbp_pack_sbp_msg_ephemeris_bds_t(buf, len, n_written, &msg->ephemeris_bds);
    case SBP_MSG_EPHEMERIS_GAL_DEP_A:
      return sbp_pack_sbp_msg_ephemeris_gal_dep_a_t(buf, len, n_written, &msg->ephemeris_gal_dep_a);
    case SBP_MSG_EPHEMERIS_GAL:
      return sbp_pack_sbp_msg_ephemeris_gal_t(buf, len, n_written, &msg->ephemeris_gal);
    case SBP_MSG_EPHEMERIS_SBAS_DEP_A:
      return sbp_pack_sbp_msg_ephemeris_sbas_dep_a_t(buf, len, n_written, &msg->ephemeris_sbas_dep_a);
    case SBP_MSG_EPHEMERIS_GLO_DEP_A:
      return sbp_pack_sbp_msg_ephemeris_glo_dep_a_t(buf, len, n_written, &msg->ephemeris_glo_dep_a);
    case SBP_MSG_EPHEMERIS_SBAS_DEP_B:
      return sbp_pack_sbp_msg_ephemeris_sbas_dep_b_t(buf, len, n_written, &msg->ephemeris_sbas_dep_b);
    case SBP_MSG_EPHEMERIS_SBAS:
      return sbp_pack_sbp_msg_ephemeris_sbas_t(buf, len, n_written, &msg->ephemeris_sbas);
    case SBP_MSG_EPHEMERIS_GLO_DEP_B:
      return sbp_pack_sbp_msg_ephemeris_glo_dep_b_t(buf, len, n_written, &msg->ephemeris_glo_dep_b);
    case SBP_MSG_EPHEMERIS_GLO_DEP_C:
      return sbp_pack_sbp_msg_ephemeris_glo_dep_c_t(buf, len, n_written, &msg->ephemeris_glo_dep_c);
    case SBP_MSG_EPHEMERIS_GLO_DEP_D:
      return sbp_pack_sbp_msg_ephemeris_glo_dep_d_t(buf, len, n_written, &msg->ephemeris_glo_dep_d);
    case SBP_MSG_EPHEMERIS_GLO:
      return sbp_pack_sbp_msg_ephemeris_glo_t(buf, len, n_written, &msg->ephemeris_glo);
    case SBP_MSG_EPHEMERIS_DEP_D:
      return sbp_pack_sbp_msg_ephemeris_dep_d_t(buf, len, n_written, &msg->ephemeris_dep_d);
    case SBP_MSG_EPHEMERIS_DEP_A:
      return sbp_pack_sbp_msg_ephemeris_dep_a_t(buf, len, n_written, &msg->ephemeris_dep_a);
    case SBP_MSG_EPHEMERIS_DEP_B:
      return sbp_pack_sbp_msg_ephemeris_dep_b_t(buf, len, n_written, &msg->ephemeris_dep_b);
    case SBP_MSG_EPHEMERIS_DEP_C:
      return sbp_pack_sbp_msg_ephemeris_dep_c_t(buf, len, n_written, &msg->ephemeris_dep_c);
    case SBP_MSG_OBS_DEP_A:
      return sbp_pack_sbp_msg_obs_dep_a_t(buf, len, n_written, &msg->obs_dep_a);
    case SBP_MSG_OBS_DEP_B:
      return sbp_pack_sbp_msg_obs_dep_b_t(buf, len, n_written, &msg->obs_dep_b);
    case SBP_MSG_OBS_DEP_C:
      return sbp_pack_sbp_msg_obs_dep_c_t(buf, len, n_written, &msg->obs_dep_c);
    case SBP_MSG_IONO:
      return sbp_pack_sbp_msg_iono_t(buf, len, n_written, &msg->iono);
    case SBP_MSG_SV_CONFIGURATION_GPS_DEP:
      return sbp_pack_sbp_msg_sv_configuration_gps_dep_t(buf, len, n_written, &msg->sv_configuration_gps_dep);
    case SBP_MSG_GNSS_CAPB:
      return sbp_pack_sbp_msg_gnss_capb_t(buf, len, n_written, &msg->gnss_capb);
    case SBP_MSG_GROUP_DELAY_DEP_A:
      return sbp_pack_sbp_msg_group_delay_dep_a_t(buf, len, n_written, &msg->group_delay_dep_a);
    case SBP_MSG_GROUP_DELAY_DEP_B:
      return sbp_pack_sbp_msg_group_delay_dep_b_t(buf, len, n_written, &msg->group_delay_dep_b);
    case SBP_MSG_GROUP_DELAY:
      return sbp_pack_sbp_msg_group_delay_t(buf, len, n_written, &msg->group_delay);
    case SBP_MSG_ALMANAC_GPS_DEP:
      return sbp_pack_sbp_msg_almanac_gps_dep_t(buf, len, n_written, &msg->almanac_gps_dep);
    case SBP_MSG_ALMANAC_GPS:
      return sbp_pack_sbp_msg_almanac_gps_t(buf, len, n_written, &msg->almanac_gps);
    case SBP_MSG_ALMANAC_GLO_DEP:
      return sbp_pack_sbp_msg_almanac_glo_dep_t(buf, len, n_written, &msg->almanac_glo_dep);
    case SBP_MSG_ALMANAC_GLO:
      return sbp_pack_sbp_msg_almanac_glo_t(buf, len, n_written, &msg->almanac_glo);
    case SBP_MSG_GLO_BIASES:
      return sbp_pack_sbp_msg_glo_biases_t(buf, len, n_written, &msg->glo_biases);
    case SBP_MSG_SV_AZ_EL:
      return sbp_pack_sbp_msg_sv_az_el_t(buf, len, n_written, &msg->sv_az_el);
    case SBP_MSG_OSR:
      return sbp_pack_sbp_msg_osr_t(buf, len, n_written, &msg->osr);
    case SBP_MSG_SBAS_RAW:
      return sbp_pack_sbp_msg_sbas_raw_t(buf, len, n_written, &msg->sbas_raw);
    case SBP_MSG_ALMANAC:
      return sbp_pack_sbp_msg_almanac_t(buf, len, n_written, &msg->almanac);
    case SBP_MSG_SET_TIME:
      return sbp_pack_sbp_msg_set_time_t(buf, len, n_written, &msg->set_time);
    case SBP_MSG_RESET:
      return sbp_pack_sbp_msg_reset_t(buf, len, n_written, &msg->reset);
    case SBP_MSG_RESET_DEP:
      return sbp_pack_sbp_msg_reset_dep_t(buf, len, n_written, &msg->reset_dep);
    case SBP_MSG_CW_RESULTS:
      return sbp_pack_sbp_msg_cw_results_t(buf, len, n_written, &msg->cw_results);
    case SBP_MSG_CW_START:
      return sbp_pack_sbp_msg_cw_start_t(buf, len, n_written, &msg->cw_start);
    case SBP_MSG_RESET_FILTERS:
      return sbp_pack_sbp_msg_reset_filters_t(buf, len, n_written, &msg->reset_filters);
    case SBP_MSG_INIT_BASE_DEP:
      return sbp_pack_sbp_msg_init_base_dep_t(buf, len, n_written, &msg->init_base_dep);
    case SBP_MSG_THREAD_STATE:
      return sbp_pack_sbp_msg_thread_state_t(buf, len, n_written, &msg->thread_state);
    case SBP_MSG_UART_STATE:
      return sbp_pack_sbp_msg_uart_state_t(buf, len, n_written, &msg->uart_state);
    case SBP_MSG_UART_STATE_DEPA:
      return sbp_pack_sbp_msg_uart_state_depa_t(buf, len, n_written, &msg->uart_state_depa);
    case SBP_MSG_IAR_STATE:
      return sbp_pack_sbp_msg_iar_state_t(buf, len, n_written, &msg->iar_state);
    case SBP_MSG_MASK_SATELLITE:
      return sbp_pack_sbp_msg_mask_satellite_t(buf, len, n_written, &msg->mask_satellite);
    case SBP_MSG_MASK_SATELLITE_DEP:
      return sbp_pack_sbp_msg_mask_satellite_dep_t(buf, len, n_written, &msg->mask_satellite_dep);
    case SBP_MSG_DEVICE_MONITOR:
      return sbp_pack_sbp_msg_device_monitor_t(buf, len, n_written, &msg->device_monitor);
    case SBP_MSG_COMMAND_REQ:
      return sbp_pack_sbp_msg_command_req_t(buf, len, n_written, &msg->command_req);
    case SBP_MSG_COMMAND_RESP:
      return sbp_pack_sbp_msg_command_resp_t(buf, len, n_written, &msg->command_resp);
    case SBP_MSG_COMMAND_OUTPUT:
      return sbp_pack_sbp_msg_command_output_t(buf, len, n_written, &msg->command_output);
    case SBP_MSG_NETWORK_STATE_REQ:
      return sbp_pack_sbp_msg_network_state_req_t(buf, len, n_written, &msg->network_state_req);
    case SBP_MSG_NETWORK_STATE_RESP:
      return sbp_pack_sbp_msg_network_state_resp_t(buf, len, n_written, &msg->network_state_resp);
    case SBP_MSG_NETWORK_BANDWIDTH_USAGE:
      return sbp_pack_sbp_msg_network_bandwidth_usage_t(buf, len, n_written, &msg->network_bandwidth_usage);
    case SBP_MSG_CELL_MODEM_STATUS:
      return sbp_pack_sbp_msg_cell_modem_status_t(buf, len, n_written, &msg->cell_modem_status);
    case SBP_MSG_SPECAN_DEP:
      return sbp_pack_sbp_msg_specan_dep_t(buf, len, n_written, &msg->specan_dep);
    case SBP_MSG_SPECAN:
      return sbp_pack_sbp_msg_specan_t(buf, len, n_written, &msg->specan);
    case SBP_MSG_FRONT_END_GAIN:
      return sbp_pack_sbp_msg_front_end_gain_t(buf, len, n_written, &msg->front_end_gain);
    case SBP_MSG_FLASH_PROGRAM:
      return sbp_pack_sbp_msg_flash_program_t(buf, len, n_written, &msg->flash_program);
    case SBP_MSG_FLASH_DONE:
      return sbp_pack_sbp_msg_flash_done_t(buf, len, n_written, &msg->flash_done);
    case SBP_MSG_FLASH_READ_REQ:
      return sbp_pack_sbp_msg_flash_read_req_t(buf, len, n_written, &msg->flash_read_req);
    case SBP_MSG_FLASH_READ_RESP:
      return sbp_pack_sbp_msg_flash_read_resp_t(buf, len, n_written, &msg->flash_read_resp);
    case SBP_MSG_FLASH_ERASE:
      return sbp_pack_sbp_msg_flash_erase_t(buf, len, n_written, &msg->flash_erase);
    case SBP_MSG_STM_FLASH_LOCK_SECTOR:
      return sbp_pack_sbp_msg_stm_flash_lock_sector_t(buf, len, n_written, &msg->stm_flash_lock_sector);
    case SBP_MSG_STM_FLASH_UNLOCK_SECTOR:
      return sbp_pack_sbp_msg_stm_flash_unlock_sector_t(buf, len, n_written, &msg->stm_flash_unlock_sector);
    case SBP_MSG_STM_UNIQUE_ID_REQ:
      return sbp_pack_sbp_msg_stm_unique_id_req_t(buf, len, n_written, &msg->stm_unique_id_req);
    case SBP_MSG_STM_UNIQUE_ID_RESP:
      return sbp_pack_sbp_msg_stm_unique_id_resp_t(buf, len, n_written, &msg->stm_unique_id_resp);
    case SBP_MSG_M25_FLASH_WRITE_STATUS:
      return sbp_pack_sbp_msg_m25_flash_write_status_t(buf, len, n_written, &msg->m25_flash_write_status);
    case SBP_MSG_IMU_RAW:
      return sbp_pack_sbp_msg_imu_raw_t(buf, len, n_written, &msg->imu_raw);
    case SBP_MSG_IMU_AUX:
      return sbp_pack_sbp_msg_imu_aux_t(buf, len, n_written, &msg->imu_aux);
    case SBP_MSG_NDB_EVENT:
      return sbp_pack_sbp_msg_ndb_event_t(buf, len, n_written, &msg->ndb_event);
    case SBP_MSG_ACQ_RESULT:
      return sbp_pack_sbp_msg_acq_result_t(buf, len, n_written, &msg->acq_result);
    case SBP_MSG_ACQ_RESULT_DEP_C:
      return sbp_pack_sbp_msg_acq_result_dep_c_t(buf, len, n_written, &msg->acq_result_dep_c);
    case SBP_MSG_ACQ_RESULT_DEP_B:
      return sbp_pack_sbp_msg_acq_result_dep_b_t(buf, len, n_written, &msg->acq_result_dep_b);
    case SBP_MSG_ACQ_RESULT_DEP_A:
      return sbp_pack_sbp_msg_acq_result_dep_a_t(buf, len, n_written, &msg->acq_result_dep_a);
    case SBP_MSG_ACQ_SV_PROFILE:
      return sbp_pack_sbp_msg_acq_sv_profile_t(buf, len, n_written, &msg->acq_sv_profile);
    case SBP_MSG_ACQ_SV_PROFILE_DEP:
      return sbp_pack_sbp_msg_acq_sv_profile_dep_t(buf, len, n_written, &msg->acq_sv_profile_dep);
    case SBP_MSG_SOLN_META_DEP_A:
      return sbp_pack_sbp_msg_soln_meta_dep_a_t(buf, len, n_written, &msg->soln_meta_dep_a);
    case SBP_MSG_SOLN_META:
      return sbp_pack_sbp_msg_soln_meta_t(buf, len, n_written, &msg->soln_meta);
    case SBP_MSG_BASELINE_HEADING:
      return sbp_pack_sbp_msg_baseline_heading_t(buf, len, n_written, &msg->baseline_heading);
    case SBP_MSG_ORIENT_QUAT:
      return sbp_pack_sbp_msg_orient_quat_t(buf, len, n_written, &msg->orient_quat);
    case SBP_MSG_ORIENT_EULER:
      return sbp_pack_sbp_msg_orient_euler_t(buf, len, n_written, &msg->orient_euler);
    case SBP_MSG_ANGULAR_RATE:
      return sbp_pack_sbp_msg_angular_rate_t(buf, len, n_written, &msg->angular_rate);
    case SBP_MSG_MAG_RAW:
      return sbp_pack_sbp_msg_mag_raw_t(buf, len, n_written, &msg->mag_raw);
    default:
      break;
  }
  return false;
}

static inline s8 sbp_unpack_msg(const uint8_t *buf, uint8_t len, uint8_t *n_read, uint16_t msg_type, sbp_msg_t *msg) {
  switch(msg_type) {
    case SBP_MSG_TRACKING_STATE_DETAILED_DEP_A:
      return sbp_unpack_sbp_msg_tracking_state_detailed_dep_a_t(buf, len, n_read, &msg->tracking_state_detailed_dep_a);
    case SBP_MSG_TRACKING_STATE_DETAILED_DEP:
      return sbp_unpack_sbp_msg_tracking_state_detailed_dep_t(buf, len, n_read, &msg->tracking_state_detailed_dep);
    case SBP_MSG_TRACKING_STATE:
      return sbp_unpack_sbp_msg_tracking_state_t(buf, len, n_read, &msg->tracking_state);
    case SBP_MSG_MEASUREMENT_STATE:
      return sbp_unpack_sbp_msg_measurement_state_t(buf, len, n_read, &msg->measurement_state);
    case SBP_MSG_TRACKING_IQ:
      return sbp_unpack_sbp_msg_tracking_iq_t(buf, len, n_read, &msg->tracking_iq);
    case SBP_MSG_TRACKING_IQ_DEP_B:
      return sbp_unpack_sbp_msg_tracking_iq_dep_b_t(buf, len, n_read, &msg->tracking_iq_dep_b);
    case SBP_MSG_TRACKING_IQ_DEP_A:
      return sbp_unpack_sbp_msg_tracking_iq_dep_a_t(buf, len, n_read, &msg->tracking_iq_dep_a);
    case SBP_MSG_TRACKING_STATE_DEP_A:
      return sbp_unpack_sbp_msg_tracking_state_dep_a_t(buf, len, n_read, &msg->tracking_state_dep_a);
    case SBP_MSG_TRACKING_STATE_DEP_B:
      return sbp_unpack_sbp_msg_tracking_state_dep_b_t(buf, len, n_read, &msg->tracking_state_dep_b);
    case SBP_MSG_SETTINGS_SAVE:
      return sbp_unpack_sbp_msg_settings_save_t(buf, len, n_read, &msg->settings_save);
    case SBP_MSG_SETTINGS_WRITE:
      return sbp_unpack_sbp_msg_settings_write_t(buf, len, n_read, &msg->settings_write);
    case SBP_MSG_SETTINGS_WRITE_RESP:
      return sbp_unpack_sbp_msg_settings_write_resp_t(buf, len, n_read, &msg->settings_write_resp);
    case SBP_MSG_SETTINGS_READ_REQ:
      return sbp_unpack_sbp_msg_settings_read_req_t(buf, len, n_read, &msg->settings_read_req);
    case SBP_MSG_SETTINGS_READ_RESP:
      return sbp_unpack_sbp_msg_settings_read_resp_t(buf, len, n_read, &msg->settings_read_resp);
    case SBP_MSG_SETTINGS_READ_BY_INDEX_REQ:
      return sbp_unpack_sbp_msg_settings_read_by_index_req_t(buf, len, n_read, &msg->settings_read_by_index_req);
    case SBP_MSG_SETTINGS_READ_BY_INDEX_RESP:
      return sbp_unpack_sbp_msg_settings_read_by_index_resp_t(buf, len, n_read, &msg->settings_read_by_index_resp);
    case SBP_MSG_SETTINGS_READ_BY_INDEX_DONE:
      return sbp_unpack_sbp_msg_settings_read_by_index_done_t(buf, len, n_read, &msg->settings_read_by_index_done);
    case SBP_MSG_SETTINGS_REGISTER:
      return sbp_unpack_sbp_msg_settings_register_t(buf, len, n_read, &msg->settings_register);
    case SBP_MSG_SETTINGS_REGISTER_RESP:
      return sbp_unpack_sbp_msg_settings_register_resp_t(buf, len, n_read, &msg->settings_register_resp);
    case SBP_MSG_SSR_ORBIT_CLOCK:
      return sbp_unpack_sbp_msg_ssr_orbit_clock_t(buf, len, n_read, &msg->ssr_orbit_clock);
    case SBP_MSG_SSR_CODE_BIASES:
      return sbp_unpack_sbp_msg_ssr_code_biases_t(buf, len, n_read, &msg->ssr_code_biases);
    case SBP_MSG_SSR_PHASE_BIASES:
      return sbp_unpack_sbp_msg_ssr_phase_biases_t(buf, len, n_read, &msg->ssr_phase_biases);
    case SBP_MSG_SSR_STEC_CORRECTION:
      return sbp_unpack_sbp_msg_ssr_stec_correction_t(buf, len, n_read, &msg->ssr_stec_correction);
    case SBP_MSG_SSR_GRIDDED_CORRECTION:
      return sbp_unpack_sbp_msg_ssr_gridded_correction_t(buf, len, n_read, &msg->ssr_gridded_correction);
    case SBP_MSG_SSR_TILE_DEFINITION:
      return sbp_unpack_sbp_msg_ssr_tile_definition_t(buf, len, n_read, &msg->ssr_tile_definition);
    case SBP_MSG_SSR_SATELLITE_APC:
      return sbp_unpack_sbp_msg_ssr_satellite_apc_t(buf, len, n_read, &msg->ssr_satellite_apc);
    case SBP_MSG_SSR_ORBIT_CLOCK_DEP_A:
      return sbp_unpack_sbp_msg_ssr_orbit_clock_dep_a_t(buf, len, n_read, &msg->ssr_orbit_clock_dep_a);
    case SBP_MSG_SSR_STEC_CORRECTION_DEP_A:
      return sbp_unpack_sbp_msg_ssr_stec_correction_dep_a_t(buf, len, n_read, &msg->ssr_stec_correction_dep_a);
    case SBP_MSG_SSR_GRIDDED_CORRECTION_NO_STD_DEP_A:
      return sbp_unpack_sbp_msg_ssr_gridded_correction_no_std_dep_a_t(buf, len, n_read, &msg->ssr_gridded_correction_no_std_dep_a);
    case SBP_MSG_SSR_GRIDDED_CORRECTION_DEP_A:
      return sbp_unpack_sbp_msg_ssr_gridded_correction_dep_a_t(buf, len, n_read, &msg->ssr_gridded_correction_dep_a);
    case SBP_MSG_SSR_GRID_DEFINITION_DEP_A:
      return sbp_unpack_sbp_msg_ssr_grid_definition_dep_a_t(buf, len, n_read, &msg->ssr_grid_definition_dep_a);
    case SBP_MSG_EXT_EVENT:
      return sbp_unpack_sbp_msg_ext_event_t(buf, len, n_read, &msg->ext_event);
    case SBP_MSG_ODOMETRY:
      return sbp_unpack_sbp_msg_odometry_t(buf, len, n_read, &msg->odometry);
    case SBP_MSG_WHEELTICK:
      return sbp_unpack_sbp_msg_wheeltick_t(buf, len, n_read, &msg->wheeltick);
    case SBP_MSG_USER_DATA:
      return sbp_unpack_sbp_msg_user_data_t(buf, len, n_read, &msg->user_data);
    case SBP_MSG_LINUX_CPU_STATE_DEP_A:
      return sbp_unpack_sbp_msg_linux_cpu_state_dep_a_t(buf, len, n_read, &msg->linux_cpu_state_dep_a);
    case SBP_MSG_LINUX_MEM_STATE_DEP_A:
      return sbp_unpack_sbp_msg_linux_mem_state_dep_a_t(buf, len, n_read, &msg->linux_mem_state_dep_a);
    case SBP_MSG_LINUX_SYS_STATE_DEP_A:
      return sbp_unpack_sbp_msg_linux_sys_state_dep_a_t(buf, len, n_read, &msg->linux_sys_state_dep_a);
    case SBP_MSG_LINUX_PROCESS_SOCKET_COUNTS:
      return sbp_unpack_sbp_msg_linux_process_socket_counts_t(buf, len, n_read, &msg->linux_process_socket_counts);
    case SBP_MSG_LINUX_PROCESS_SOCKET_QUEUES:
      return sbp_unpack_sbp_msg_linux_process_socket_queues_t(buf, len, n_read, &msg->linux_process_socket_queues);
    case SBP_MSG_LINUX_SOCKET_USAGE:
      return sbp_unpack_sbp_msg_linux_socket_usage_t(buf, len, n_read, &msg->linux_socket_usage);
    case SBP_MSG_LINUX_PROCESS_FD_COUNT:
      return sbp_unpack_sbp_msg_linux_process_fd_count_t(buf, len, n_read, &msg->linux_process_fd_count);
    case SBP_MSG_LINUX_PROCESS_FD_SUMMARY:
      return sbp_unpack_sbp_msg_linux_process_fd_summary_t(buf, len, n_read, &msg->linux_process_fd_summary);
    case SBP_MSG_LINUX_CPU_STATE:
      return sbp_unpack_sbp_msg_linux_cpu_state_t(buf, len, n_read, &msg->linux_cpu_state);
    case SBP_MSG_LINUX_MEM_STATE:
      return sbp_unpack_sbp_msg_linux_mem_state_t(buf, len, n_read, &msg->linux_mem_state);
    case SBP_MSG_LINUX_SYS_STATE:
      return sbp_unpack_sbp_msg_linux_sys_state_t(buf, len, n_read, &msg->linux_sys_state);
    case SBP_MSG_GPS_TIME:
      return sbp_unpack_sbp_msg_gps_time_t(buf, len, n_read, &msg->gps_time);
    case SBP_MSG_GPS_TIME_GNSS:
      return sbp_unpack_sbp_msg_gps_time_gnss_t(buf, len, n_read, &msg->gps_time_gnss);
    case SBP_MSG_UTC_TIME:
      return sbp_unpack_sbp_msg_utc_time_t(buf, len, n_read, &msg->utc_time);
    case SBP_MSG_UTC_TIME_GNSS:
      return sbp_unpack_sbp_msg_utc_time_gnss_t(buf, len, n_read, &msg->utc_time_gnss);
    case SBP_MSG_DOPS:
      return sbp_unpack_sbp_msg_dops_t(buf, len, n_read, &msg->dops);
    case SBP_MSG_POS_ECEF:
      return sbp_unpack_sbp_msg_pos_ecef_t(buf, len, n_read, &msg->pos_ecef);
    case SBP_MSG_POS_ECEF_COV:
      return sbp_unpack_sbp_msg_pos_ecef_cov_t(buf, len, n_read, &msg->pos_ecef_cov);
    case SBP_MSG_POS_LLH:
      return sbp_unpack_sbp_msg_pos_llh_t(buf, len, n_read, &msg->pos_llh);
    case SBP_MSG_POS_LLH_COV:
      return sbp_unpack_sbp_msg_pos_llh_cov_t(buf, len, n_read, &msg->pos_llh_cov);
    case SBP_MSG_BASELINE_ECEF:
      return sbp_unpack_sbp_msg_baseline_ecef_t(buf, len, n_read, &msg->baseline_ecef);
    case SBP_MSG_BASELINE_NED:
      return sbp_unpack_sbp_msg_baseline_ned_t(buf, len, n_read, &msg->baseline_ned);
    case SBP_MSG_VEL_ECEF:
      return sbp_unpack_sbp_msg_vel_ecef_t(buf, len, n_read, &msg->vel_ecef);
    case SBP_MSG_VEL_ECEF_COV:
      return sbp_unpack_sbp_msg_vel_ecef_cov_t(buf, len, n_read, &msg->vel_ecef_cov);
    case SBP_MSG_VEL_NED:
      return sbp_unpack_sbp_msg_vel_ned_t(buf, len, n_read, &msg->vel_ned);
    case SBP_MSG_VEL_NED_COV:
      return sbp_unpack_sbp_msg_vel_ned_cov_t(buf, len, n_read, &msg->vel_ned_cov);
    case SBP_MSG_POS_ECEF_GNSS:
      return sbp_unpack_sbp_msg_pos_ecef_gnss_t(buf, len, n_read, &msg->pos_ecef_gnss);
    case SBP_MSG_POS_ECEF_COV_GNSS:
      return sbp_unpack_sbp_msg_pos_ecef_cov_gnss_t(buf, len, n_read, &msg->pos_ecef_cov_gnss);
    case SBP_MSG_POS_LLH_GNSS:
      return sbp_unpack_sbp_msg_pos_llh_gnss_t(buf, len, n_read, &msg->pos_llh_gnss);
    case SBP_MSG_POS_LLH_COV_GNSS:
      return sbp_unpack_sbp_msg_pos_llh_cov_gnss_t(buf, len, n_read, &msg->pos_llh_cov_gnss);
    case SBP_MSG_VEL_ECEF_GNSS:
      return sbp_unpack_sbp_msg_vel_ecef_gnss_t(buf, len, n_read, &msg->vel_ecef_gnss);
    case SBP_MSG_VEL_ECEF_COV_GNSS:
      return sbp_unpack_sbp_msg_vel_ecef_cov_gnss_t(buf, len, n_read, &msg->vel_ecef_cov_gnss);
    case SBP_MSG_VEL_NED_GNSS:
      return sbp_unpack_sbp_msg_vel_ned_gnss_t(buf, len, n_read, &msg->vel_ned_gnss);
    case SBP_MSG_VEL_NED_COV_GNSS:
      return sbp_unpack_sbp_msg_vel_ned_cov_gnss_t(buf, len, n_read, &msg->vel_ned_cov_gnss);
    case SBP_MSG_VEL_BODY:
      return sbp_unpack_sbp_msg_vel_body_t(buf, len, n_read, &msg->vel_body);
    case SBP_MSG_AGE_CORRECTIONS:
      return sbp_unpack_sbp_msg_age_corrections_t(buf, len, n_read, &msg->age_corrections);
    case SBP_MSG_GPS_TIME_DEP_A:
      return sbp_unpack_sbp_msg_gps_time_dep_a_t(buf, len, n_read, &msg->gps_time_dep_a);
    case SBP_MSG_DOPS_DEP_A:
      return sbp_unpack_sbp_msg_dops_dep_a_t(buf, len, n_read, &msg->dops_dep_a);
    case SBP_MSG_POS_ECEF_DEP_A:
      return sbp_unpack_sbp_msg_pos_ecef_dep_a_t(buf, len, n_read, &msg->pos_ecef_dep_a);
    case SBP_MSG_POS_LLH_DEP_A:
      return sbp_unpack_sbp_msg_pos_llh_dep_a_t(buf, len, n_read, &msg->pos_llh_dep_a);
    case SBP_MSG_BASELINE_ECEF_DEP_A:
      return sbp_unpack_sbp_msg_baseline_ecef_dep_a_t(buf, len, n_read, &msg->baseline_ecef_dep_a);
    case SBP_MSG_BASELINE_NED_DEP_A:
      return sbp_unpack_sbp_msg_baseline_ned_dep_a_t(buf, len, n_read, &msg->baseline_ned_dep_a);
    case SBP_MSG_VEL_ECEF_DEP_A:
      return sbp_unpack_sbp_msg_vel_ecef_dep_a_t(buf, len, n_read, &msg->vel_ecef_dep_a);
    case SBP_MSG_VEL_NED_DEP_A:
      return sbp_unpack_sbp_msg_vel_ned_dep_a_t(buf, len, n_read, &msg->vel_ned_dep_a);
    case SBP_MSG_BASELINE_HEADING_DEP_A:
      return sbp_unpack_sbp_msg_baseline_heading_dep_a_t(buf, len, n_read, &msg->baseline_heading_dep_a);
    case SBP_MSG_PROTECTION_LEVEL_DEP_A:
      return sbp_unpack_sbp_msg_protection_level_dep_a_t(buf, len, n_read, &msg->protection_level_dep_a);
    case SBP_MSG_PROTECTION_LEVEL:
      return sbp_unpack_sbp_msg_protection_level_t(buf, len, n_read, &msg->protection_level);
    case SBP_MSG_FILEIO_READ_REQ:
      return sbp_unpack_sbp_msg_fileio_read_req_t(buf, len, n_read, &msg->fileio_read_req);
    case SBP_MSG_FILEIO_READ_RESP:
      return sbp_unpack_sbp_msg_fileio_read_resp_t(buf, len, n_read, &msg->fileio_read_resp);
    case SBP_MSG_FILEIO_READ_DIR_REQ:
      return sbp_unpack_sbp_msg_fileio_read_dir_req_t(buf, len, n_read, &msg->fileio_read_dir_req);
    case SBP_MSG_FILEIO_READ_DIR_RESP:
      return sbp_unpack_sbp_msg_fileio_read_dir_resp_t(buf, len, n_read, &msg->fileio_read_dir_resp);
    case SBP_MSG_FILEIO_REMOVE:
      return sbp_unpack_sbp_msg_fileio_remove_t(buf, len, n_read, &msg->fileio_remove);
    case SBP_MSG_FILEIO_WRITE_REQ:
      return sbp_unpack_sbp_msg_fileio_write_req_t(buf, len, n_read, &msg->fileio_write_req);
    case SBP_MSG_FILEIO_WRITE_RESP:
      return sbp_unpack_sbp_msg_fileio_write_resp_t(buf, len, n_read, &msg->fileio_write_resp);
    case SBP_MSG_FILEIO_CONFIG_REQ:
      return sbp_unpack_sbp_msg_fileio_config_req_t(buf, len, n_read, &msg->fileio_config_req);
    case SBP_MSG_FILEIO_CONFIG_RESP:
      return sbp_unpack_sbp_msg_fileio_config_resp_t(buf, len, n_read, &msg->fileio_config_resp);
    case SBP_MSG_LOG:
      return sbp_unpack_sbp_msg_log_t(buf, len, n_read, &msg->log);
    case SBP_MSG_FWD:
      return sbp_unpack_sbp_msg_fwd_t(buf, len, n_read, &msg->fwd);
    case SBP_MSG_PRINT_DEP:
      return sbp_unpack_sbp_msg_print_dep_t(buf, len, n_read, &msg->print_dep);
    case SBP_MSG_BOOTLOADER_HANDSHAKE_REQ:
      return sbp_unpack_sbp_msg_bootloader_handshake_req_t(buf, len, n_read, &msg->bootloader_handshake_req);
    case SBP_MSG_BOOTLOADER_HANDSHAKE_RESP:
      return sbp_unpack_sbp_msg_bootloader_handshake_resp_t(buf, len, n_read, &msg->bootloader_handshake_resp);
    case SBP_MSG_BOOTLOADER_JUMP_TO_APP:
      return sbp_unpack_sbp_msg_bootloader_jump_to_app_t(buf, len, n_read, &msg->bootloader_jump_to_app);
    case SBP_MSG_NAP_DEVICE_DNA_REQ:
      return sbp_unpack_sbp_msg_nap_device_dna_req_t(buf, len, n_read, &msg->nap_device_dna_req);
    case SBP_MSG_NAP_DEVICE_DNA_RESP:
      return sbp_unpack_sbp_msg_nap_device_dna_resp_t(buf, len, n_read, &msg->nap_device_dna_resp);
    case SBP_MSG_BOOTLOADER_HANDSHAKE_DEP_A:
      return sbp_unpack_sbp_msg_bootloader_handshake_dep_a_t(buf, len, n_read, &msg->bootloader_handshake_dep_a);
    case SBP_MSG_STARTUP:
      return sbp_unpack_sbp_msg_startup_t(buf, len, n_read, &msg->startup);
    case SBP_MSG_DGNSS_STATUS:
      return sbp_unpack_sbp_msg_dgnss_status_t(buf, len, n_read, &msg->dgnss_status);
    case SBP_MSG_HEARTBEAT:
      return sbp_unpack_sbp_msg_heartbeat_t(buf, len, n_read, &msg->heartbeat);
    case SBP_MSG_STATUS_REPORT:
      return sbp_unpack_sbp_msg_status_report_t(buf, len, n_read, &msg->status_report);
    case SBP_MSG_INS_STATUS:
      return sbp_unpack_sbp_msg_ins_status_t(buf, len, n_read, &msg->ins_status);
    case SBP_MSG_CSAC_TELEMETRY:
      return sbp_unpack_sbp_msg_csac_telemetry_t(buf, len, n_read, &msg->csac_telemetry);
    case SBP_MSG_CSAC_TELEMETRY_LABELS:
      return sbp_unpack_sbp_msg_csac_telemetry_labels_t(buf, len, n_read, &msg->csac_telemetry_labels);
    case SBP_MSG_INS_UPDATES:
      return sbp_unpack_sbp_msg_ins_updates_t(buf, len, n_read, &msg->ins_updates);
    case SBP_MSG_GNSS_TIME_OFFSET:
      return sbp_unpack_sbp_msg_gnss_time_offset_t(buf, len, n_read, &msg->gnss_time_offset);
    case SBP_MSG_PPS_TIME:
      return sbp_unpack_sbp_msg_pps_time_t(buf, len, n_read, &msg->pps_time);
    case SBP_MSG_GROUP_META:
      return sbp_unpack_sbp_msg_group_meta_t(buf, len, n_read, &msg->group_meta);
    case SBP_MSG_OBS:
      return sbp_unpack_sbp_msg_obs_t(buf, len, n_read, &msg->obs);
    case SBP_MSG_BASE_POS_LLH:
      return sbp_unpack_sbp_msg_base_pos_llh_t(buf, len, n_read, &msg->base_pos_llh);
    case SBP_MSG_BASE_POS_ECEF:
      return sbp_unpack_sbp_msg_base_pos_ecef_t(buf, len, n_read, &msg->base_pos_ecef);
    case SBP_MSG_EPHEMERIS_GPS_DEP_E:
      return sbp_unpack_sbp_msg_ephemeris_gps_dep_e_t(buf, len, n_read, &msg->ephemeris_gps_dep_e);
    case SBP_MSG_EPHEMERIS_GPS_DEP_F:
      return sbp_unpack_sbp_msg_ephemeris_gps_dep_f_t(buf, len, n_read, &msg->ephemeris_gps_dep_f);
    case SBP_MSG_EPHEMERIS_GPS:
      return sbp_unpack_sbp_msg_ephemeris_gps_t(buf, len, n_read, &msg->ephemeris_gps);
    case SBP_MSG_EPHEMERIS_QZSS:
      return sbp_unpack_sbp_msg_ephemeris_qzss_t(buf, len, n_read, &msg->ephemeris_qzss);
    case SBP_MSG_EPHEMERIS_BDS:
      return sbp_unpack_sbp_msg_ephemeris_bds_t(buf, len, n_read, &msg->ephemeris_bds);
    case SBP_MSG_EPHEMERIS_GAL_DEP_A:
      return sbp_unpack_sbp_msg_ephemeris_gal_dep_a_t(buf, len, n_read, &msg->ephemeris_gal_dep_a);
    case SBP_MSG_EPHEMERIS_GAL:
      return sbp_unpack_sbp_msg_ephemeris_gal_t(buf, len, n_read, &msg->ephemeris_gal);
    case SBP_MSG_EPHEMERIS_SBAS_DEP_A:
      return sbp_unpack_sbp_msg_ephemeris_sbas_dep_a_t(buf, len, n_read, &msg->ephemeris_sbas_dep_a);
    case SBP_MSG_EPHEMERIS_GLO_DEP_A:
      return sbp_unpack_sbp_msg_ephemeris_glo_dep_a_t(buf, len, n_read, &msg->ephemeris_glo_dep_a);
    case SBP_MSG_EPHEMERIS_SBAS_DEP_B:
      return sbp_unpack_sbp_msg_ephemeris_sbas_dep_b_t(buf, len, n_read, &msg->ephemeris_sbas_dep_b);
    case SBP_MSG_EPHEMERIS_SBAS:
      return sbp_unpack_sbp_msg_ephemeris_sbas_t(buf, len, n_read, &msg->ephemeris_sbas);
    case SBP_MSG_EPHEMERIS_GLO_DEP_B:
      return sbp_unpack_sbp_msg_ephemeris_glo_dep_b_t(buf, len, n_read, &msg->ephemeris_glo_dep_b);
    case SBP_MSG_EPHEMERIS_GLO_DEP_C:
      return sbp_unpack_sbp_msg_ephemeris_glo_dep_c_t(buf, len, n_read, &msg->ephemeris_glo_dep_c);
    case SBP_MSG_EPHEMERIS_GLO_DEP_D:
      return sbp_unpack_sbp_msg_ephemeris_glo_dep_d_t(buf, len, n_read, &msg->ephemeris_glo_dep_d);
    case SBP_MSG_EPHEMERIS_GLO:
      return sbp_unpack_sbp_msg_ephemeris_glo_t(buf, len, n_read, &msg->ephemeris_glo);
    case SBP_MSG_EPHEMERIS_DEP_D:
      return sbp_unpack_sbp_msg_ephemeris_dep_d_t(buf, len, n_read, &msg->ephemeris_dep_d);
    case SBP_MSG_EPHEMERIS_DEP_A:
      return sbp_unpack_sbp_msg_ephemeris_dep_a_t(buf, len, n_read, &msg->ephemeris_dep_a);
    case SBP_MSG_EPHEMERIS_DEP_B:
      return sbp_unpack_sbp_msg_ephemeris_dep_b_t(buf, len, n_read, &msg->ephemeris_dep_b);
    case SBP_MSG_EPHEMERIS_DEP_C:
      return sbp_unpack_sbp_msg_ephemeris_dep_c_t(buf, len, n_read, &msg->ephemeris_dep_c);
    case SBP_MSG_OBS_DEP_A:
      return sbp_unpack_sbp_msg_obs_dep_a_t(buf, len, n_read, &msg->obs_dep_a);
    case SBP_MSG_OBS_DEP_B:
      return sbp_unpack_sbp_msg_obs_dep_b_t(buf, len, n_read, &msg->obs_dep_b);
    case SBP_MSG_OBS_DEP_C:
      return sbp_unpack_sbp_msg_obs_dep_c_t(buf, len, n_read, &msg->obs_dep_c);
    case SBP_MSG_IONO:
      return sbp_unpack_sbp_msg_iono_t(buf, len, n_read, &msg->iono);
    case SBP_MSG_SV_CONFIGURATION_GPS_DEP:
      return sbp_unpack_sbp_msg_sv_configuration_gps_dep_t(buf, len, n_read, &msg->sv_configuration_gps_dep);
    case SBP_MSG_GNSS_CAPB:
      return sbp_unpack_sbp_msg_gnss_capb_t(buf, len, n_read, &msg->gnss_capb);
    case SBP_MSG_GROUP_DELAY_DEP_A:
      return sbp_unpack_sbp_msg_group_delay_dep_a_t(buf, len, n_read, &msg->group_delay_dep_a);
    case SBP_MSG_GROUP_DELAY_DEP_B:
      return sbp_unpack_sbp_msg_group_delay_dep_b_t(buf, len, n_read, &msg->group_delay_dep_b);
    case SBP_MSG_GROUP_DELAY:
      return sbp_unpack_sbp_msg_group_delay_t(buf, len, n_read, &msg->group_delay);
    case SBP_MSG_ALMANAC_GPS_DEP:
      return sbp_unpack_sbp_msg_almanac_gps_dep_t(buf, len, n_read, &msg->almanac_gps_dep);
    case SBP_MSG_ALMANAC_GPS:
      return sbp_unpack_sbp_msg_almanac_gps_t(buf, len, n_read, &msg->almanac_gps);
    case SBP_MSG_ALMANAC_GLO_DEP:
      return sbp_unpack_sbp_msg_almanac_glo_dep_t(buf, len, n_read, &msg->almanac_glo_dep);
    case SBP_MSG_ALMANAC_GLO:
      return sbp_unpack_sbp_msg_almanac_glo_t(buf, len, n_read, &msg->almanac_glo);
    case SBP_MSG_GLO_BIASES:
      return sbp_unpack_sbp_msg_glo_biases_t(buf, len, n_read, &msg->glo_biases);
    case SBP_MSG_SV_AZ_EL:
      return sbp_unpack_sbp_msg_sv_az_el_t(buf, len, n_read, &msg->sv_az_el);
    case SBP_MSG_OSR:
      return sbp_unpack_sbp_msg_osr_t(buf, len, n_read, &msg->osr);
    case SBP_MSG_SBAS_RAW:
      return sbp_unpack_sbp_msg_sbas_raw_t(buf, len, n_read, &msg->sbas_raw);
    case SBP_MSG_ALMANAC:
      return sbp_unpack_sbp_msg_almanac_t(buf, len, n_read, &msg->almanac);
    case SBP_MSG_SET_TIME:
      return sbp_unpack_sbp_msg_set_time_t(buf, len, n_read, &msg->set_time);
    case SBP_MSG_RESET:
      return sbp_unpack_sbp_msg_reset_t(buf, len, n_read, &msg->reset);
    case SBP_MSG_RESET_DEP:
      return sbp_unpack_sbp_msg_reset_dep_t(buf, len, n_read, &msg->reset_dep);
    case SBP_MSG_CW_RESULTS:
      return sbp_unpack_sbp_msg_cw_results_t(buf, len, n_read, &msg->cw_results);
    case SBP_MSG_CW_START:
      return sbp_unpack_sbp_msg_cw_start_t(buf, len, n_read, &msg->cw_start);
    case SBP_MSG_RESET_FILTERS:
      return sbp_unpack_sbp_msg_reset_filters_t(buf, len, n_read, &msg->reset_filters);
    case SBP_MSG_INIT_BASE_DEP:
      return sbp_unpack_sbp_msg_init_base_dep_t(buf, len, n_read, &msg->init_base_dep);
    case SBP_MSG_THREAD_STATE:
      return sbp_unpack_sbp_msg_thread_state_t(buf, len, n_read, &msg->thread_state);
    case SBP_MSG_UART_STATE:
      return sbp_unpack_sbp_msg_uart_state_t(buf, len, n_read, &msg->uart_state);
    case SBP_MSG_UART_STATE_DEPA:
      return sbp_unpack_sbp_msg_uart_state_depa_t(buf, len, n_read, &msg->uart_state_depa);
    case SBP_MSG_IAR_STATE:
      return sbp_unpack_sbp_msg_iar_state_t(buf, len, n_read, &msg->iar_state);
    case SBP_MSG_MASK_SATELLITE:
      return sbp_unpack_sbp_msg_mask_satellite_t(buf, len, n_read, &msg->mask_satellite);
    case SBP_MSG_MASK_SATELLITE_DEP:
      return sbp_unpack_sbp_msg_mask_satellite_dep_t(buf, len, n_read, &msg->mask_satellite_dep);
    case SBP_MSG_DEVICE_MONITOR:
      return sbp_unpack_sbp_msg_device_monitor_t(buf, len, n_read, &msg->device_monitor);
    case SBP_MSG_COMMAND_REQ:
      return sbp_unpack_sbp_msg_command_req_t(buf, len, n_read, &msg->command_req);
    case SBP_MSG_COMMAND_RESP:
      return sbp_unpack_sbp_msg_command_resp_t(buf, len, n_read, &msg->command_resp);
    case SBP_MSG_COMMAND_OUTPUT:
      return sbp_unpack_sbp_msg_command_output_t(buf, len, n_read, &msg->command_output);
    case SBP_MSG_NETWORK_STATE_REQ:
      return sbp_unpack_sbp_msg_network_state_req_t(buf, len, n_read, &msg->network_state_req);
    case SBP_MSG_NETWORK_STATE_RESP:
      return sbp_unpack_sbp_msg_network_state_resp_t(buf, len, n_read, &msg->network_state_resp);
    case SBP_MSG_NETWORK_BANDWIDTH_USAGE:
      return sbp_unpack_sbp_msg_network_bandwidth_usage_t(buf, len, n_read, &msg->network_bandwidth_usage);
    case SBP_MSG_CELL_MODEM_STATUS:
      return sbp_unpack_sbp_msg_cell_modem_status_t(buf, len, n_read, &msg->cell_modem_status);
    case SBP_MSG_SPECAN_DEP:
      return sbp_unpack_sbp_msg_specan_dep_t(buf, len, n_read, &msg->specan_dep);
    case SBP_MSG_SPECAN:
      return sbp_unpack_sbp_msg_specan_t(buf, len, n_read, &msg->specan);
    case SBP_MSG_FRONT_END_GAIN:
      return sbp_unpack_sbp_msg_front_end_gain_t(buf, len, n_read, &msg->front_end_gain);
    case SBP_MSG_FLASH_PROGRAM:
      return sbp_unpack_sbp_msg_flash_program_t(buf, len, n_read, &msg->flash_program);
    case SBP_MSG_FLASH_DONE:
      return sbp_unpack_sbp_msg_flash_done_t(buf, len, n_read, &msg->flash_done);
    case SBP_MSG_FLASH_READ_REQ:
      return sbp_unpack_sbp_msg_flash_read_req_t(buf, len, n_read, &msg->flash_read_req);
    case SBP_MSG_FLASH_READ_RESP:
      return sbp_unpack_sbp_msg_flash_read_resp_t(buf, len, n_read, &msg->flash_read_resp);
    case SBP_MSG_FLASH_ERASE:
      return sbp_unpack_sbp_msg_flash_erase_t(buf, len, n_read, &msg->flash_erase);
    case SBP_MSG_STM_FLASH_LOCK_SECTOR:
      return sbp_unpack_sbp_msg_stm_flash_lock_sector_t(buf, len, n_read, &msg->stm_flash_lock_sector);
    case SBP_MSG_STM_FLASH_UNLOCK_SECTOR:
      return sbp_unpack_sbp_msg_stm_flash_unlock_sector_t(buf, len, n_read, &msg->stm_flash_unlock_sector);
    case SBP_MSG_STM_UNIQUE_ID_REQ:
      return sbp_unpack_sbp_msg_stm_unique_id_req_t(buf, len, n_read, &msg->stm_unique_id_req);
    case SBP_MSG_STM_UNIQUE_ID_RESP:
      return sbp_unpack_sbp_msg_stm_unique_id_resp_t(buf, len, n_read, &msg->stm_unique_id_resp);
    case SBP_MSG_M25_FLASH_WRITE_STATUS:
      return sbp_unpack_sbp_msg_m25_flash_write_status_t(buf, len, n_read, &msg->m25_flash_write_status);
    case SBP_MSG_IMU_RAW:
      return sbp_unpack_sbp_msg_imu_raw_t(buf, len, n_read, &msg->imu_raw);
    case SBP_MSG_IMU_AUX:
      return sbp_unpack_sbp_msg_imu_aux_t(buf, len, n_read, &msg->imu_aux);
    case SBP_MSG_NDB_EVENT:
      return sbp_unpack_sbp_msg_ndb_event_t(buf, len, n_read, &msg->ndb_event);
    case SBP_MSG_ACQ_RESULT:
      return sbp_unpack_sbp_msg_acq_result_t(buf, len, n_read, &msg->acq_result);
    case SBP_MSG_ACQ_RESULT_DEP_C:
      return sbp_unpack_sbp_msg_acq_result_dep_c_t(buf, len, n_read, &msg->acq_result_dep_c);
    case SBP_MSG_ACQ_RESULT_DEP_B:
      return sbp_unpack_sbp_msg_acq_result_dep_b_t(buf, len, n_read, &msg->acq_result_dep_b);
    case SBP_MSG_ACQ_RESULT_DEP_A:
      return sbp_unpack_sbp_msg_acq_result_dep_a_t(buf, len, n_read, &msg->acq_result_dep_a);
    case SBP_MSG_ACQ_SV_PROFILE:
      return sbp_unpack_sbp_msg_acq_sv_profile_t(buf, len, n_read, &msg->acq_sv_profile);
    case SBP_MSG_ACQ_SV_PROFILE_DEP:
      return sbp_unpack_sbp_msg_acq_sv_profile_dep_t(buf, len, n_read, &msg->acq_sv_profile_dep);
    case SBP_MSG_SOLN_META_DEP_A:
      return sbp_unpack_sbp_msg_soln_meta_dep_a_t(buf, len, n_read, &msg->soln_meta_dep_a);
    case SBP_MSG_SOLN_META:
      return sbp_unpack_sbp_msg_soln_meta_t(buf, len, n_read, &msg->soln_meta);
    case SBP_MSG_BASELINE_HEADING:
      return sbp_unpack_sbp_msg_baseline_heading_t(buf, len, n_read, &msg->baseline_heading);
    case SBP_MSG_ORIENT_QUAT:
      return sbp_unpack_sbp_msg_orient_quat_t(buf, len, n_read, &msg->orient_quat);
    case SBP_MSG_ORIENT_EULER:
      return sbp_unpack_sbp_msg_orient_euler_t(buf, len, n_read, &msg->orient_euler);
    case SBP_MSG_ANGULAR_RATE:
      return sbp_unpack_sbp_msg_angular_rate_t(buf, len, n_read, &msg->angular_rate);
    case SBP_MSG_MAG_RAW:
      return sbp_unpack_sbp_msg_mag_raw_t(buf, len, n_read, &msg->mag_raw);
    default:
      break;
  }
  return false;
}

static inline size_t sbp_packed_size(uint16_t msg_type, const sbp_msg_t *msg) {
  switch(msg_type) {
    case SBP_MSG_TRACKING_STATE_DETAILED_DEP_A:
      return sbp_packed_size_sbp_msg_tracking_state_detailed_dep_a_t(&msg->tracking_state_detailed_dep_a);
    case SBP_MSG_TRACKING_STATE_DETAILED_DEP:
      return sbp_packed_size_sbp_msg_tracking_state_detailed_dep_t(&msg->tracking_state_detailed_dep);
    case SBP_MSG_TRACKING_STATE:
      return sbp_packed_size_sbp_msg_tracking_state_t(&msg->tracking_state);
    case SBP_MSG_MEASUREMENT_STATE:
      return sbp_packed_size_sbp_msg_measurement_state_t(&msg->measurement_state);
    case SBP_MSG_TRACKING_IQ:
      return sbp_packed_size_sbp_msg_tracking_iq_t(&msg->tracking_iq);
    case SBP_MSG_TRACKING_IQ_DEP_B:
      return sbp_packed_size_sbp_msg_tracking_iq_dep_b_t(&msg->tracking_iq_dep_b);
    case SBP_MSG_TRACKING_IQ_DEP_A:
      return sbp_packed_size_sbp_msg_tracking_iq_dep_a_t(&msg->tracking_iq_dep_a);
    case SBP_MSG_TRACKING_STATE_DEP_A:
      return sbp_packed_size_sbp_msg_tracking_state_dep_a_t(&msg->tracking_state_dep_a);
    case SBP_MSG_TRACKING_STATE_DEP_B:
      return sbp_packed_size_sbp_msg_tracking_state_dep_b_t(&msg->tracking_state_dep_b);
    case SBP_MSG_SETTINGS_SAVE:
      return sbp_packed_size_sbp_msg_settings_save_t(&msg->settings_save);
    case SBP_MSG_SETTINGS_WRITE:
      return sbp_packed_size_sbp_msg_settings_write_t(&msg->settings_write);
    case SBP_MSG_SETTINGS_WRITE_RESP:
      return sbp_packed_size_sbp_msg_settings_write_resp_t(&msg->settings_write_resp);
    case SBP_MSG_SETTINGS_READ_REQ:
      return sbp_packed_size_sbp_msg_settings_read_req_t(&msg->settings_read_req);
    case SBP_MSG_SETTINGS_READ_RESP:
      return sbp_packed_size_sbp_msg_settings_read_resp_t(&msg->settings_read_resp);
    case SBP_MSG_SETTINGS_READ_BY_INDEX_REQ:
      return sbp_packed_size_sbp_msg_settings_read_by_index_req_t(&msg->settings_read_by_index_req);
    case SBP_MSG_SETTINGS_READ_BY_INDEX_RESP:
      return sbp_packed_size_sbp_msg_settings_read_by_index_resp_t(&msg->settings_read_by_index_resp);
    case SBP_MSG_SETTINGS_READ_BY_INDEX_DONE:
      return sbp_packed_size_sbp_msg_settings_read_by_index_done_t(&msg->settings_read_by_index_done);
    case SBP_MSG_SETTINGS_REGISTER:
      return sbp_packed_size_sbp_msg_settings_register_t(&msg->settings_register);
    case SBP_MSG_SETTINGS_REGISTER_RESP:
      return sbp_packed_size_sbp_msg_settings_register_resp_t(&msg->settings_register_resp);
    case SBP_MSG_SSR_ORBIT_CLOCK:
      return sbp_packed_size_sbp_msg_ssr_orbit_clock_t(&msg->ssr_orbit_clock);
    case SBP_MSG_SSR_CODE_BIASES:
      return sbp_packed_size_sbp_msg_ssr_code_biases_t(&msg->ssr_code_biases);
    case SBP_MSG_SSR_PHASE_BIASES:
      return sbp_packed_size_sbp_msg_ssr_phase_biases_t(&msg->ssr_phase_biases);
    case SBP_MSG_SSR_STEC_CORRECTION:
      return sbp_packed_size_sbp_msg_ssr_stec_correction_t(&msg->ssr_stec_correction);
    case SBP_MSG_SSR_GRIDDED_CORRECTION:
      return sbp_packed_size_sbp_msg_ssr_gridded_correction_t(&msg->ssr_gridded_correction);
    case SBP_MSG_SSR_TILE_DEFINITION:
      return sbp_packed_size_sbp_msg_ssr_tile_definition_t(&msg->ssr_tile_definition);
    case SBP_MSG_SSR_SATELLITE_APC:
      return sbp_packed_size_sbp_msg_ssr_satellite_apc_t(&msg->ssr_satellite_apc);
    case SBP_MSG_SSR_ORBIT_CLOCK_DEP_A:
      return sbp_packed_size_sbp_msg_ssr_orbit_clock_dep_a_t(&msg->ssr_orbit_clock_dep_a);
    case SBP_MSG_SSR_STEC_CORRECTION_DEP_A:
      return sbp_packed_size_sbp_msg_ssr_stec_correction_dep_a_t(&msg->ssr_stec_correction_dep_a);
    case SBP_MSG_SSR_GRIDDED_CORRECTION_NO_STD_DEP_A:
      return sbp_packed_size_sbp_msg_ssr_gridded_correction_no_std_dep_a_t(&msg->ssr_gridded_correction_no_std_dep_a);
    case SBP_MSG_SSR_GRIDDED_CORRECTION_DEP_A:
      return sbp_packed_size_sbp_msg_ssr_gridded_correction_dep_a_t(&msg->ssr_gridded_correction_dep_a);
    case SBP_MSG_SSR_GRID_DEFINITION_DEP_A:
      return sbp_packed_size_sbp_msg_ssr_grid_definition_dep_a_t(&msg->ssr_grid_definition_dep_a);
    case SBP_MSG_EXT_EVENT:
      return sbp_packed_size_sbp_msg_ext_event_t(&msg->ext_event);
    case SBP_MSG_ODOMETRY:
      return sbp_packed_size_sbp_msg_odometry_t(&msg->odometry);
    case SBP_MSG_WHEELTICK:
      return sbp_packed_size_sbp_msg_wheeltick_t(&msg->wheeltick);
    case SBP_MSG_USER_DATA:
      return sbp_packed_size_sbp_msg_user_data_t(&msg->user_data);
    case SBP_MSG_LINUX_CPU_STATE_DEP_A:
      return sbp_packed_size_sbp_msg_linux_cpu_state_dep_a_t(&msg->linux_cpu_state_dep_a);
    case SBP_MSG_LINUX_MEM_STATE_DEP_A:
      return sbp_packed_size_sbp_msg_linux_mem_state_dep_a_t(&msg->linux_mem_state_dep_a);
    case SBP_MSG_LINUX_SYS_STATE_DEP_A:
      return sbp_packed_size_sbp_msg_linux_sys_state_dep_a_t(&msg->linux_sys_state_dep_a);
    case SBP_MSG_LINUX_PROCESS_SOCKET_COUNTS:
      return sbp_packed_size_sbp_msg_linux_process_socket_counts_t(&msg->linux_process_socket_counts);
    case SBP_MSG_LINUX_PROCESS_SOCKET_QUEUES:
      return sbp_packed_size_sbp_msg_linux_process_socket_queues_t(&msg->linux_process_socket_queues);
    case SBP_MSG_LINUX_SOCKET_USAGE:
      return sbp_packed_size_sbp_msg_linux_socket_usage_t(&msg->linux_socket_usage);
    case SBP_MSG_LINUX_PROCESS_FD_COUNT:
      return sbp_packed_size_sbp_msg_linux_process_fd_count_t(&msg->linux_process_fd_count);
    case SBP_MSG_LINUX_PROCESS_FD_SUMMARY:
      return sbp_packed_size_sbp_msg_linux_process_fd_summary_t(&msg->linux_process_fd_summary);
    case SBP_MSG_LINUX_CPU_STATE:
      return sbp_packed_size_sbp_msg_linux_cpu_state_t(&msg->linux_cpu_state);
    case SBP_MSG_LINUX_MEM_STATE:
      return sbp_packed_size_sbp_msg_linux_mem_state_t(&msg->linux_mem_state);
    case SBP_MSG_LINUX_SYS_STATE:
      return sbp_packed_size_sbp_msg_linux_sys_state_t(&msg->linux_sys_state);
    case SBP_MSG_GPS_TIME:
      return sbp_packed_size_sbp_msg_gps_time_t(&msg->gps_time);
    case SBP_MSG_GPS_TIME_GNSS:
      return sbp_packed_size_sbp_msg_gps_time_gnss_t(&msg->gps_time_gnss);
    case SBP_MSG_UTC_TIME:
      return sbp_packed_size_sbp_msg_utc_time_t(&msg->utc_time);
    case SBP_MSG_UTC_TIME_GNSS:
      return sbp_packed_size_sbp_msg_utc_time_gnss_t(&msg->utc_time_gnss);
    case SBP_MSG_DOPS:
      return sbp_packed_size_sbp_msg_dops_t(&msg->dops);
    case SBP_MSG_POS_ECEF:
      return sbp_packed_size_sbp_msg_pos_ecef_t(&msg->pos_ecef);
    case SBP_MSG_POS_ECEF_COV:
      return sbp_packed_size_sbp_msg_pos_ecef_cov_t(&msg->pos_ecef_cov);
    case SBP_MSG_POS_LLH:
      return sbp_packed_size_sbp_msg_pos_llh_t(&msg->pos_llh);
    case SBP_MSG_POS_LLH_COV:
      return sbp_packed_size_sbp_msg_pos_llh_cov_t(&msg->pos_llh_cov);
    case SBP_MSG_BASELINE_ECEF:
      return sbp_packed_size_sbp_msg_baseline_ecef_t(&msg->baseline_ecef);
    case SBP_MSG_BASELINE_NED:
      return sbp_packed_size_sbp_msg_baseline_ned_t(&msg->baseline_ned);
    case SBP_MSG_VEL_ECEF:
      return sbp_packed_size_sbp_msg_vel_ecef_t(&msg->vel_ecef);
    case SBP_MSG_VEL_ECEF_COV:
      return sbp_packed_size_sbp_msg_vel_ecef_cov_t(&msg->vel_ecef_cov);
    case SBP_MSG_VEL_NED:
      return sbp_packed_size_sbp_msg_vel_ned_t(&msg->vel_ned);
    case SBP_MSG_VEL_NED_COV:
      return sbp_packed_size_sbp_msg_vel_ned_cov_t(&msg->vel_ned_cov);
    case SBP_MSG_POS_ECEF_GNSS:
      return sbp_packed_size_sbp_msg_pos_ecef_gnss_t(&msg->pos_ecef_gnss);
    case SBP_MSG_POS_ECEF_COV_GNSS:
      return sbp_packed_size_sbp_msg_pos_ecef_cov_gnss_t(&msg->pos_ecef_cov_gnss);
    case SBP_MSG_POS_LLH_GNSS:
      return sbp_packed_size_sbp_msg_pos_llh_gnss_t(&msg->pos_llh_gnss);
    case SBP_MSG_POS_LLH_COV_GNSS:
      return sbp_packed_size_sbp_msg_pos_llh_cov_gnss_t(&msg->pos_llh_cov_gnss);
    case SBP_MSG_VEL_ECEF_GNSS:
      return sbp_packed_size_sbp_msg_vel_ecef_gnss_t(&msg->vel_ecef_gnss);
    case SBP_MSG_VEL_ECEF_COV_GNSS:
      return sbp_packed_size_sbp_msg_vel_ecef_cov_gnss_t(&msg->vel_ecef_cov_gnss);
    case SBP_MSG_VEL_NED_GNSS:
      return sbp_packed_size_sbp_msg_vel_ned_gnss_t(&msg->vel_ned_gnss);
    case SBP_MSG_VEL_NED_COV_GNSS:
      return sbp_packed_size_sbp_msg_vel_ned_cov_gnss_t(&msg->vel_ned_cov_gnss);
    case SBP_MSG_VEL_BODY:
      return sbp_packed_size_sbp_msg_vel_body_t(&msg->vel_body);
    case SBP_MSG_AGE_CORRECTIONS:
      return sbp_packed_size_sbp_msg_age_corrections_t(&msg->age_corrections);
    case SBP_MSG_GPS_TIME_DEP_A:
      return sbp_packed_size_sbp_msg_gps_time_dep_a_t(&msg->gps_time_dep_a);
    case SBP_MSG_DOPS_DEP_A:
      return sbp_packed_size_sbp_msg_dops_dep_a_t(&msg->dops_dep_a);
    case SBP_MSG_POS_ECEF_DEP_A:
      return sbp_packed_size_sbp_msg_pos_ecef_dep_a_t(&msg->pos_ecef_dep_a);
    case SBP_MSG_POS_LLH_DEP_A:
      return sbp_packed_size_sbp_msg_pos_llh_dep_a_t(&msg->pos_llh_dep_a);
    case SBP_MSG_BASELINE_ECEF_DEP_A:
      return sbp_packed_size_sbp_msg_baseline_ecef_dep_a_t(&msg->baseline_ecef_dep_a);
    case SBP_MSG_BASELINE_NED_DEP_A:
      return sbp_packed_size_sbp_msg_baseline_ned_dep_a_t(&msg->baseline_ned_dep_a);
    case SBP_MSG_VEL_ECEF_DEP_A:
      return sbp_packed_size_sbp_msg_vel_ecef_dep_a_t(&msg->vel_ecef_dep_a);
    case SBP_MSG_VEL_NED_DEP_A:
      return sbp_packed_size_sbp_msg_vel_ned_dep_a_t(&msg->vel_ned_dep_a);
    case SBP_MSG_BASELINE_HEADING_DEP_A:
      return sbp_packed_size_sbp_msg_baseline_heading_dep_a_t(&msg->baseline_heading_dep_a);
    case SBP_MSG_PROTECTION_LEVEL_DEP_A:
      return sbp_packed_size_sbp_msg_protection_level_dep_a_t(&msg->protection_level_dep_a);
    case SBP_MSG_PROTECTION_LEVEL:
      return sbp_packed_size_sbp_msg_protection_level_t(&msg->protection_level);
    case SBP_MSG_FILEIO_READ_REQ:
      return sbp_packed_size_sbp_msg_fileio_read_req_t(&msg->fileio_read_req);
    case SBP_MSG_FILEIO_READ_RESP:
      return sbp_packed_size_sbp_msg_fileio_read_resp_t(&msg->fileio_read_resp);
    case SBP_MSG_FILEIO_READ_DIR_REQ:
      return sbp_packed_size_sbp_msg_fileio_read_dir_req_t(&msg->fileio_read_dir_req);
    case SBP_MSG_FILEIO_READ_DIR_RESP:
      return sbp_packed_size_sbp_msg_fileio_read_dir_resp_t(&msg->fileio_read_dir_resp);
    case SBP_MSG_FILEIO_REMOVE:
      return sbp_packed_size_sbp_msg_fileio_remove_t(&msg->fileio_remove);
    case SBP_MSG_FILEIO_WRITE_REQ:
      return sbp_packed_size_sbp_msg_fileio_write_req_t(&msg->fileio_write_req);
    case SBP_MSG_FILEIO_WRITE_RESP:
      return sbp_packed_size_sbp_msg_fileio_write_resp_t(&msg->fileio_write_resp);
    case SBP_MSG_FILEIO_CONFIG_REQ:
      return sbp_packed_size_sbp_msg_fileio_config_req_t(&msg->fileio_config_req);
    case SBP_MSG_FILEIO_CONFIG_RESP:
      return sbp_packed_size_sbp_msg_fileio_config_resp_t(&msg->fileio_config_resp);
    case SBP_MSG_LOG:
      return sbp_packed_size_sbp_msg_log_t(&msg->log);
    case SBP_MSG_FWD:
      return sbp_packed_size_sbp_msg_fwd_t(&msg->fwd);
    case SBP_MSG_PRINT_DEP:
      return sbp_packed_size_sbp_msg_print_dep_t(&msg->print_dep);
    case SBP_MSG_BOOTLOADER_HANDSHAKE_REQ:
      return sbp_packed_size_sbp_msg_bootloader_handshake_req_t(&msg->bootloader_handshake_req);
    case SBP_MSG_BOOTLOADER_HANDSHAKE_RESP:
      return sbp_packed_size_sbp_msg_bootloader_handshake_resp_t(&msg->bootloader_handshake_resp);
    case SBP_MSG_BOOTLOADER_JUMP_TO_APP:
      return sbp_packed_size_sbp_msg_bootloader_jump_to_app_t(&msg->bootloader_jump_to_app);
    case SBP_MSG_NAP_DEVICE_DNA_REQ:
      return sbp_packed_size_sbp_msg_nap_device_dna_req_t(&msg->nap_device_dna_req);
    case SBP_MSG_NAP_DEVICE_DNA_RESP:
      return sbp_packed_size_sbp_msg_nap_device_dna_resp_t(&msg->nap_device_dna_resp);
    case SBP_MSG_BOOTLOADER_HANDSHAKE_DEP_A:
      return sbp_packed_size_sbp_msg_bootloader_handshake_dep_a_t(&msg->bootloader_handshake_dep_a);
    case SBP_MSG_STARTUP:
      return sbp_packed_size_sbp_msg_startup_t(&msg->startup);
    case SBP_MSG_DGNSS_STATUS:
      return sbp_packed_size_sbp_msg_dgnss_status_t(&msg->dgnss_status);
    case SBP_MSG_HEARTBEAT:
      return sbp_packed_size_sbp_msg_heartbeat_t(&msg->heartbeat);
    case SBP_MSG_STATUS_REPORT:
      return sbp_packed_size_sbp_msg_status_report_t(&msg->status_report);
    case SBP_MSG_INS_STATUS:
      return sbp_packed_size_sbp_msg_ins_status_t(&msg->ins_status);
    case SBP_MSG_CSAC_TELEMETRY:
      return sbp_packed_size_sbp_msg_csac_telemetry_t(&msg->csac_telemetry);
    case SBP_MSG_CSAC_TELEMETRY_LABELS:
      return sbp_packed_size_sbp_msg_csac_telemetry_labels_t(&msg->csac_telemetry_labels);
    case SBP_MSG_INS_UPDATES:
      return sbp_packed_size_sbp_msg_ins_updates_t(&msg->ins_updates);
    case SBP_MSG_GNSS_TIME_OFFSET:
      return sbp_packed_size_sbp_msg_gnss_time_offset_t(&msg->gnss_time_offset);
    case SBP_MSG_PPS_TIME:
      return sbp_packed_size_sbp_msg_pps_time_t(&msg->pps_time);
    case SBP_MSG_GROUP_META:
      return sbp_packed_size_sbp_msg_group_meta_t(&msg->group_meta);
    case SBP_MSG_OBS:
      return sbp_packed_size_sbp_msg_obs_t(&msg->obs);
    case SBP_MSG_BASE_POS_LLH:
      return sbp_packed_size_sbp_msg_base_pos_llh_t(&msg->base_pos_llh);
    case SBP_MSG_BASE_POS_ECEF:
      return sbp_packed_size_sbp_msg_base_pos_ecef_t(&msg->base_pos_ecef);
    case SBP_MSG_EPHEMERIS_GPS_DEP_E:
      return sbp_packed_size_sbp_msg_ephemeris_gps_dep_e_t(&msg->ephemeris_gps_dep_e);
    case SBP_MSG_EPHEMERIS_GPS_DEP_F:
      return sbp_packed_size_sbp_msg_ephemeris_gps_dep_f_t(&msg->ephemeris_gps_dep_f);
    case SBP_MSG_EPHEMERIS_GPS:
      return sbp_packed_size_sbp_msg_ephemeris_gps_t(&msg->ephemeris_gps);
    case SBP_MSG_EPHEMERIS_QZSS:
      return sbp_packed_size_sbp_msg_ephemeris_qzss_t(&msg->ephemeris_qzss);
    case SBP_MSG_EPHEMERIS_BDS:
      return sbp_packed_size_sbp_msg_ephemeris_bds_t(&msg->ephemeris_bds);
    case SBP_MSG_EPHEMERIS_GAL_DEP_A:
      return sbp_packed_size_sbp_msg_ephemeris_gal_dep_a_t(&msg->ephemeris_gal_dep_a);
    case SBP_MSG_EPHEMERIS_GAL:
      return sbp_packed_size_sbp_msg_ephemeris_gal_t(&msg->ephemeris_gal);
    case SBP_MSG_EPHEMERIS_SBAS_DEP_A:
      return sbp_packed_size_sbp_msg_ephemeris_sbas_dep_a_t(&msg->ephemeris_sbas_dep_a);
    case SBP_MSG_EPHEMERIS_GLO_DEP_A:
      return sbp_packed_size_sbp_msg_ephemeris_glo_dep_a_t(&msg->ephemeris_glo_dep_a);
    case SBP_MSG_EPHEMERIS_SBAS_DEP_B:
      return sbp_packed_size_sbp_msg_ephemeris_sbas_dep_b_t(&msg->ephemeris_sbas_dep_b);
    case SBP_MSG_EPHEMERIS_SBAS:
      return sbp_packed_size_sbp_msg_ephemeris_sbas_t(&msg->ephemeris_sbas);
    case SBP_MSG_EPHEMERIS_GLO_DEP_B:
      return sbp_packed_size_sbp_msg_ephemeris_glo_dep_b_t(&msg->ephemeris_glo_dep_b);
    case SBP_MSG_EPHEMERIS_GLO_DEP_C:
      return sbp_packed_size_sbp_msg_ephemeris_glo_dep_c_t(&msg->ephemeris_glo_dep_c);
    case SBP_MSG_EPHEMERIS_GLO_DEP_D:
      return sbp_packed_size_sbp_msg_ephemeris_glo_dep_d_t(&msg->ephemeris_glo_dep_d);
    case SBP_MSG_EPHEMERIS_GLO:
      return sbp_packed_size_sbp_msg_ephemeris_glo_t(&msg->ephemeris_glo);
    case SBP_MSG_EPHEMERIS_DEP_D:
      return sbp_packed_size_sbp_msg_ephemeris_dep_d_t(&msg->ephemeris_dep_d);
    case SBP_MSG_EPHEMERIS_DEP_A:
      return sbp_packed_size_sbp_msg_ephemeris_dep_a_t(&msg->ephemeris_dep_a);
    case SBP_MSG_EPHEMERIS_DEP_B:
      return sbp_packed_size_sbp_msg_ephemeris_dep_b_t(&msg->ephemeris_dep_b);
    case SBP_MSG_EPHEMERIS_DEP_C:
      return sbp_packed_size_sbp_msg_ephemeris_dep_c_t(&msg->ephemeris_dep_c);
    case SBP_MSG_OBS_DEP_A:
      return sbp_packed_size_sbp_msg_obs_dep_a_t(&msg->obs_dep_a);
    case SBP_MSG_OBS_DEP_B:
      return sbp_packed_size_sbp_msg_obs_dep_b_t(&msg->obs_dep_b);
    case SBP_MSG_OBS_DEP_C:
      return sbp_packed_size_sbp_msg_obs_dep_c_t(&msg->obs_dep_c);
    case SBP_MSG_IONO:
      return sbp_packed_size_sbp_msg_iono_t(&msg->iono);
    case SBP_MSG_SV_CONFIGURATION_GPS_DEP:
      return sbp_packed_size_sbp_msg_sv_configuration_gps_dep_t(&msg->sv_configuration_gps_dep);
    case SBP_MSG_GNSS_CAPB:
      return sbp_packed_size_sbp_msg_gnss_capb_t(&msg->gnss_capb);
    case SBP_MSG_GROUP_DELAY_DEP_A:
      return sbp_packed_size_sbp_msg_group_delay_dep_a_t(&msg->group_delay_dep_a);
    case SBP_MSG_GROUP_DELAY_DEP_B:
      return sbp_packed_size_sbp_msg_group_delay_dep_b_t(&msg->group_delay_dep_b);
    case SBP_MSG_GROUP_DELAY:
      return sbp_packed_size_sbp_msg_group_delay_t(&msg->group_delay);
    case SBP_MSG_ALMANAC_GPS_DEP:
      return sbp_packed_size_sbp_msg_almanac_gps_dep_t(&msg->almanac_gps_dep);
    case SBP_MSG_ALMANAC_GPS:
      return sbp_packed_size_sbp_msg_almanac_gps_t(&msg->almanac_gps);
    case SBP_MSG_ALMANAC_GLO_DEP:
      return sbp_packed_size_sbp_msg_almanac_glo_dep_t(&msg->almanac_glo_dep);
    case SBP_MSG_ALMANAC_GLO:
      return sbp_packed_size_sbp_msg_almanac_glo_t(&msg->almanac_glo);
    case SBP_MSG_GLO_BIASES:
      return sbp_packed_size_sbp_msg_glo_biases_t(&msg->glo_biases);
    case SBP_MSG_SV_AZ_EL:
      return sbp_packed_size_sbp_msg_sv_az_el_t(&msg->sv_az_el);
    case SBP_MSG_OSR:
      return sbp_packed_size_sbp_msg_osr_t(&msg->osr);
    case SBP_MSG_SBAS_RAW:
      return sbp_packed_size_sbp_msg_sbas_raw_t(&msg->sbas_raw);
    case SBP_MSG_ALMANAC:
      return sbp_packed_size_sbp_msg_almanac_t(&msg->almanac);
    case SBP_MSG_SET_TIME:
      return sbp_packed_size_sbp_msg_set_time_t(&msg->set_time);
    case SBP_MSG_RESET:
      return sbp_packed_size_sbp_msg_reset_t(&msg->reset);
    case SBP_MSG_RESET_DEP:
      return sbp_packed_size_sbp_msg_reset_dep_t(&msg->reset_dep);
    case SBP_MSG_CW_RESULTS:
      return sbp_packed_size_sbp_msg_cw_results_t(&msg->cw_results);
    case SBP_MSG_CW_START:
      return sbp_packed_size_sbp_msg_cw_start_t(&msg->cw_start);
    case SBP_MSG_RESET_FILTERS:
      return sbp_packed_size_sbp_msg_reset_filters_t(&msg->reset_filters);
    case SBP_MSG_INIT_BASE_DEP:
      return sbp_packed_size_sbp_msg_init_base_dep_t(&msg->init_base_dep);
    case SBP_MSG_THREAD_STATE:
      return sbp_packed_size_sbp_msg_thread_state_t(&msg->thread_state);
    case SBP_MSG_UART_STATE:
      return sbp_packed_size_sbp_msg_uart_state_t(&msg->uart_state);
    case SBP_MSG_UART_STATE_DEPA:
      return sbp_packed_size_sbp_msg_uart_state_depa_t(&msg->uart_state_depa);
    case SBP_MSG_IAR_STATE:
      return sbp_packed_size_sbp_msg_iar_state_t(&msg->iar_state);
    case SBP_MSG_MASK_SATELLITE:
      return sbp_packed_size_sbp_msg_mask_satellite_t(&msg->mask_satellite);
    case SBP_MSG_MASK_SATELLITE_DEP:
      return sbp_packed_size_sbp_msg_mask_satellite_dep_t(&msg->mask_satellite_dep);
    case SBP_MSG_DEVICE_MONITOR:
      return sbp_packed_size_sbp_msg_device_monitor_t(&msg->device_monitor);
    case SBP_MSG_COMMAND_REQ:
      return sbp_packed_size_sbp_msg_command_req_t(&msg->command_req);
    case SBP_MSG_COMMAND_RESP:
      return sbp_packed_size_sbp_msg_command_resp_t(&msg->command_resp);
    case SBP_MSG_COMMAND_OUTPUT:
      return sbp_packed_size_sbp_msg_command_output_t(&msg->command_output);
    case SBP_MSG_NETWORK_STATE_REQ:
      return sbp_packed_size_sbp_msg_network_state_req_t(&msg->network_state_req);
    case SBP_MSG_NETWORK_STATE_RESP:
      return sbp_packed_size_sbp_msg_network_state_resp_t(&msg->network_state_resp);
    case SBP_MSG_NETWORK_BANDWIDTH_USAGE:
      return sbp_packed_size_sbp_msg_network_bandwidth_usage_t(&msg->network_bandwidth_usage);
    case SBP_MSG_CELL_MODEM_STATUS:
      return sbp_packed_size_sbp_msg_cell_modem_status_t(&msg->cell_modem_status);
    case SBP_MSG_SPECAN_DEP:
      return sbp_packed_size_sbp_msg_specan_dep_t(&msg->specan_dep);
    case SBP_MSG_SPECAN:
      return sbp_packed_size_sbp_msg_specan_t(&msg->specan);
    case SBP_MSG_FRONT_END_GAIN:
      return sbp_packed_size_sbp_msg_front_end_gain_t(&msg->front_end_gain);
    case SBP_MSG_FLASH_PROGRAM:
      return sbp_packed_size_sbp_msg_flash_program_t(&msg->flash_program);
    case SBP_MSG_FLASH_DONE:
      return sbp_packed_size_sbp_msg_flash_done_t(&msg->flash_done);
    case SBP_MSG_FLASH_READ_REQ:
      return sbp_packed_size_sbp_msg_flash_read_req_t(&msg->flash_read_req);
    case SBP_MSG_FLASH_READ_RESP:
      return sbp_packed_size_sbp_msg_flash_read_resp_t(&msg->flash_read_resp);
    case SBP_MSG_FLASH_ERASE:
      return sbp_packed_size_sbp_msg_flash_erase_t(&msg->flash_erase);
    case SBP_MSG_STM_FLASH_LOCK_SECTOR:
      return sbp_packed_size_sbp_msg_stm_flash_lock_sector_t(&msg->stm_flash_lock_sector);
    case SBP_MSG_STM_FLASH_UNLOCK_SECTOR:
      return sbp_packed_size_sbp_msg_stm_flash_unlock_sector_t(&msg->stm_flash_unlock_sector);
    case SBP_MSG_STM_UNIQUE_ID_REQ:
      return sbp_packed_size_sbp_msg_stm_unique_id_req_t(&msg->stm_unique_id_req);
    case SBP_MSG_STM_UNIQUE_ID_RESP:
      return sbp_packed_size_sbp_msg_stm_unique_id_resp_t(&msg->stm_unique_id_resp);
    case SBP_MSG_M25_FLASH_WRITE_STATUS:
      return sbp_packed_size_sbp_msg_m25_flash_write_status_t(&msg->m25_flash_write_status);
    case SBP_MSG_IMU_RAW:
      return sbp_packed_size_sbp_msg_imu_raw_t(&msg->imu_raw);
    case SBP_MSG_IMU_AUX:
      return sbp_packed_size_sbp_msg_imu_aux_t(&msg->imu_aux);
    case SBP_MSG_NDB_EVENT:
      return sbp_packed_size_sbp_msg_ndb_event_t(&msg->ndb_event);
    case SBP_MSG_ACQ_RESULT:
      return sbp_packed_size_sbp_msg_acq_result_t(&msg->acq_result);
    case SBP_MSG_ACQ_RESULT_DEP_C:
      return sbp_packed_size_sbp_msg_acq_result_dep_c_t(&msg->acq_result_dep_c);
    case SBP_MSG_ACQ_RESULT_DEP_B:
      return sbp_packed_size_sbp_msg_acq_result_dep_b_t(&msg->acq_result_dep_b);
    case SBP_MSG_ACQ_RESULT_DEP_A:
      return sbp_packed_size_sbp_msg_acq_result_dep_a_t(&msg->acq_result_dep_a);
    case SBP_MSG_ACQ_SV_PROFILE:
      return sbp_packed_size_sbp_msg_acq_sv_profile_t(&msg->acq_sv_profile);
    case SBP_MSG_ACQ_SV_PROFILE_DEP:
      return sbp_packed_size_sbp_msg_acq_sv_profile_dep_t(&msg->acq_sv_profile_dep);
    case SBP_MSG_SOLN_META_DEP_A:
      return sbp_packed_size_sbp_msg_soln_meta_dep_a_t(&msg->soln_meta_dep_a);
    case SBP_MSG_SOLN_META:
      return sbp_packed_size_sbp_msg_soln_meta_t(&msg->soln_meta);
    case SBP_MSG_BASELINE_HEADING:
      return sbp_packed_size_sbp_msg_baseline_heading_t(&msg->baseline_heading);
    case SBP_MSG_ORIENT_QUAT:
      return sbp_packed_size_sbp_msg_orient_quat_t(&msg->orient_quat);
    case SBP_MSG_ORIENT_EULER:
      return sbp_packed_size_sbp_msg_orient_euler_t(&msg->orient_euler);
    case SBP_MSG_ANGULAR_RATE:
      return sbp_packed_size_sbp_msg_angular_rate_t(&msg->angular_rate);
    case SBP_MSG_MAG_RAW:
      return sbp_packed_size_sbp_msg_mag_raw_t(&msg->mag_raw);
    default:
      break;
  }
  return 0;
}

static inline int sbp_msg_cmp(uint16_t msg_type, const sbp_msg_t *a, const sbp_msg_t *b) {
  switch(msg_type) {
    case SBP_MSG_TRACKING_STATE_DETAILED_DEP_A:
      return sbp_cmp_sbp_msg_tracking_state_detailed_dep_a_t(&a->tracking_state_detailed_dep_a, &b->tracking_state_detailed_dep_a);
    case SBP_MSG_TRACKING_STATE_DETAILED_DEP:
      return sbp_cmp_sbp_msg_tracking_state_detailed_dep_t(&a->tracking_state_detailed_dep, &b->tracking_state_detailed_dep);
    case SBP_MSG_TRACKING_STATE:
      return sbp_cmp_sbp_msg_tracking_state_t(&a->tracking_state, &b->tracking_state);
    case SBP_MSG_MEASUREMENT_STATE:
      return sbp_cmp_sbp_msg_measurement_state_t(&a->measurement_state, &b->measurement_state);
    case SBP_MSG_TRACKING_IQ:
      return sbp_cmp_sbp_msg_tracking_iq_t(&a->tracking_iq, &b->tracking_iq);
    case SBP_MSG_TRACKING_IQ_DEP_B:
      return sbp_cmp_sbp_msg_tracking_iq_dep_b_t(&a->tracking_iq_dep_b, &b->tracking_iq_dep_b);
    case SBP_MSG_TRACKING_IQ_DEP_A:
      return sbp_cmp_sbp_msg_tracking_iq_dep_a_t(&a->tracking_iq_dep_a, &b->tracking_iq_dep_a);
    case SBP_MSG_TRACKING_STATE_DEP_A:
      return sbp_cmp_sbp_msg_tracking_state_dep_a_t(&a->tracking_state_dep_a, &b->tracking_state_dep_a);
    case SBP_MSG_TRACKING_STATE_DEP_B:
      return sbp_cmp_sbp_msg_tracking_state_dep_b_t(&a->tracking_state_dep_b, &b->tracking_state_dep_b);
    case SBP_MSG_SETTINGS_SAVE:
      return sbp_cmp_sbp_msg_settings_save_t(&a->settings_save, &b->settings_save);
    case SBP_MSG_SETTINGS_WRITE:
      return sbp_cmp_sbp_msg_settings_write_t(&a->settings_write, &b->settings_write);
    case SBP_MSG_SETTINGS_WRITE_RESP:
      return sbp_cmp_sbp_msg_settings_write_resp_t(&a->settings_write_resp, &b->settings_write_resp);
    case SBP_MSG_SETTINGS_READ_REQ:
      return sbp_cmp_sbp_msg_settings_read_req_t(&a->settings_read_req, &b->settings_read_req);
    case SBP_MSG_SETTINGS_READ_RESP:
      return sbp_cmp_sbp_msg_settings_read_resp_t(&a->settings_read_resp, &b->settings_read_resp);
    case SBP_MSG_SETTINGS_READ_BY_INDEX_REQ:
      return sbp_cmp_sbp_msg_settings_read_by_index_req_t(&a->settings_read_by_index_req, &b->settings_read_by_index_req);
    case SBP_MSG_SETTINGS_READ_BY_INDEX_RESP:
      return sbp_cmp_sbp_msg_settings_read_by_index_resp_t(&a->settings_read_by_index_resp, &b->settings_read_by_index_resp);
    case SBP_MSG_SETTINGS_READ_BY_INDEX_DONE:
      return sbp_cmp_sbp_msg_settings_read_by_index_done_t(&a->settings_read_by_index_done, &b->settings_read_by_index_done);
    case SBP_MSG_SETTINGS_REGISTER:
      return sbp_cmp_sbp_msg_settings_register_t(&a->settings_register, &b->settings_register);
    case SBP_MSG_SETTINGS_REGISTER_RESP:
      return sbp_cmp_sbp_msg_settings_register_resp_t(&a->settings_register_resp, &b->settings_register_resp);
    case SBP_MSG_SSR_ORBIT_CLOCK:
      return sbp_cmp_sbp_msg_ssr_orbit_clock_t(&a->ssr_orbit_clock, &b->ssr_orbit_clock);
    case SBP_MSG_SSR_CODE_BIASES:
      return sbp_cmp_sbp_msg_ssr_code_biases_t(&a->ssr_code_biases, &b->ssr_code_biases);
    case SBP_MSG_SSR_PHASE_BIASES:
      return sbp_cmp_sbp_msg_ssr_phase_biases_t(&a->ssr_phase_biases, &b->ssr_phase_biases);
    case SBP_MSG_SSR_STEC_CORRECTION:
      return sbp_cmp_sbp_msg_ssr_stec_correction_t(&a->ssr_stec_correction, &b->ssr_stec_correction);
    case SBP_MSG_SSR_GRIDDED_CORRECTION:
      return sbp_cmp_sbp_msg_ssr_gridded_correction_t(&a->ssr_gridded_correction, &b->ssr_gridded_correction);
    case SBP_MSG_SSR_TILE_DEFINITION:
      return sbp_cmp_sbp_msg_ssr_tile_definition_t(&a->ssr_tile_definition, &b->ssr_tile_definition);
    case SBP_MSG_SSR_SATELLITE_APC:
      return sbp_cmp_sbp_msg_ssr_satellite_apc_t(&a->ssr_satellite_apc, &b->ssr_satellite_apc);
    case SBP_MSG_SSR_ORBIT_CLOCK_DEP_A:
      return sbp_cmp_sbp_msg_ssr_orbit_clock_dep_a_t(&a->ssr_orbit_clock_dep_a, &b->ssr_orbit_clock_dep_a);
    case SBP_MSG_SSR_STEC_CORRECTION_DEP_A:
      return sbp_cmp_sbp_msg_ssr_stec_correction_dep_a_t(&a->ssr_stec_correction_dep_a, &b->ssr_stec_correction_dep_a);
    case SBP_MSG_SSR_GRIDDED_CORRECTION_NO_STD_DEP_A:
      return sbp_cmp_sbp_msg_ssr_gridded_correction_no_std_dep_a_t(&a->ssr_gridded_correction_no_std_dep_a, &b->ssr_gridded_correction_no_std_dep_a);
    case SBP_MSG_SSR_GRIDDED_CORRECTION_DEP_A:
      return sbp_cmp_sbp_msg_ssr_gridded_correction_dep_a_t(&a->ssr_gridded_correction_dep_a, &b->ssr_gridded_correction_dep_a);
    case SBP_MSG_SSR_GRID_DEFINITION_DEP_A:
      return sbp_cmp_sbp_msg_ssr_grid_definition_dep_a_t(&a->ssr_grid_definition_dep_a, &b->ssr_grid_definition_dep_a);
    case SBP_MSG_EXT_EVENT:
      return sbp_cmp_sbp_msg_ext_event_t(&a->ext_event, &b->ext_event);
    case SBP_MSG_ODOMETRY:
      return sbp_cmp_sbp_msg_odometry_t(&a->odometry, &b->odometry);
    case SBP_MSG_WHEELTICK:
      return sbp_cmp_sbp_msg_wheeltick_t(&a->wheeltick, &b->wheeltick);
    case SBP_MSG_USER_DATA:
      return sbp_cmp_sbp_msg_user_data_t(&a->user_data, &b->user_data);
    case SBP_MSG_LINUX_CPU_STATE_DEP_A:
      return sbp_cmp_sbp_msg_linux_cpu_state_dep_a_t(&a->linux_cpu_state_dep_a, &b->linux_cpu_state_dep_a);
    case SBP_MSG_LINUX_MEM_STATE_DEP_A:
      return sbp_cmp_sbp_msg_linux_mem_state_dep_a_t(&a->linux_mem_state_dep_a, &b->linux_mem_state_dep_a);
    case SBP_MSG_LINUX_SYS_STATE_DEP_A:
      return sbp_cmp_sbp_msg_linux_sys_state_dep_a_t(&a->linux_sys_state_dep_a, &b->linux_sys_state_dep_a);
    case SBP_MSG_LINUX_PROCESS_SOCKET_COUNTS:
      return sbp_cmp_sbp_msg_linux_process_socket_counts_t(&a->linux_process_socket_counts, &b->linux_process_socket_counts);
    case SBP_MSG_LINUX_PROCESS_SOCKET_QUEUES:
      return sbp_cmp_sbp_msg_linux_process_socket_queues_t(&a->linux_process_socket_queues, &b->linux_process_socket_queues);
    case SBP_MSG_LINUX_SOCKET_USAGE:
      return sbp_cmp_sbp_msg_linux_socket_usage_t(&a->linux_socket_usage, &b->linux_socket_usage);
    case SBP_MSG_LINUX_PROCESS_FD_COUNT:
      return sbp_cmp_sbp_msg_linux_process_fd_count_t(&a->linux_process_fd_count, &b->linux_process_fd_count);
    case SBP_MSG_LINUX_PROCESS_FD_SUMMARY:
      return sbp_cmp_sbp_msg_linux_process_fd_summary_t(&a->linux_process_fd_summary, &b->linux_process_fd_summary);
    case SBP_MSG_LINUX_CPU_STATE:
      return sbp_cmp_sbp_msg_linux_cpu_state_t(&a->linux_cpu_state, &b->linux_cpu_state);
    case SBP_MSG_LINUX_MEM_STATE:
      return sbp_cmp_sbp_msg_linux_mem_state_t(&a->linux_mem_state, &b->linux_mem_state);
    case SBP_MSG_LINUX_SYS_STATE:
      return sbp_cmp_sbp_msg_linux_sys_state_t(&a->linux_sys_state, &b->linux_sys_state);
    case SBP_MSG_GPS_TIME:
      return sbp_cmp_sbp_msg_gps_time_t(&a->gps_time, &b->gps_time);
    case SBP_MSG_GPS_TIME_GNSS:
      return sbp_cmp_sbp_msg_gps_time_gnss_t(&a->gps_time_gnss, &b->gps_time_gnss);
    case SBP_MSG_UTC_TIME:
      return sbp_cmp_sbp_msg_utc_time_t(&a->utc_time, &b->utc_time);
    case SBP_MSG_UTC_TIME_GNSS:
      return sbp_cmp_sbp_msg_utc_time_gnss_t(&a->utc_time_gnss, &b->utc_time_gnss);
    case SBP_MSG_DOPS:
      return sbp_cmp_sbp_msg_dops_t(&a->dops, &b->dops);
    case SBP_MSG_POS_ECEF:
      return sbp_cmp_sbp_msg_pos_ecef_t(&a->pos_ecef, &b->pos_ecef);
    case SBP_MSG_POS_ECEF_COV:
      return sbp_cmp_sbp_msg_pos_ecef_cov_t(&a->pos_ecef_cov, &b->pos_ecef_cov);
    case SBP_MSG_POS_LLH:
      return sbp_cmp_sbp_msg_pos_llh_t(&a->pos_llh, &b->pos_llh);
    case SBP_MSG_POS_LLH_COV:
      return sbp_cmp_sbp_msg_pos_llh_cov_t(&a->pos_llh_cov, &b->pos_llh_cov);
    case SBP_MSG_BASELINE_ECEF:
      return sbp_cmp_sbp_msg_baseline_ecef_t(&a->baseline_ecef, &b->baseline_ecef);
    case SBP_MSG_BASELINE_NED:
      return sbp_cmp_sbp_msg_baseline_ned_t(&a->baseline_ned, &b->baseline_ned);
    case SBP_MSG_VEL_ECEF:
      return sbp_cmp_sbp_msg_vel_ecef_t(&a->vel_ecef, &b->vel_ecef);
    case SBP_MSG_VEL_ECEF_COV:
      return sbp_cmp_sbp_msg_vel_ecef_cov_t(&a->vel_ecef_cov, &b->vel_ecef_cov);
    case SBP_MSG_VEL_NED:
      return sbp_cmp_sbp_msg_vel_ned_t(&a->vel_ned, &b->vel_ned);
    case SBP_MSG_VEL_NED_COV:
      return sbp_cmp_sbp_msg_vel_ned_cov_t(&a->vel_ned_cov, &b->vel_ned_cov);
    case SBP_MSG_POS_ECEF_GNSS:
      return sbp_cmp_sbp_msg_pos_ecef_gnss_t(&a->pos_ecef_gnss, &b->pos_ecef_gnss);
    case SBP_MSG_POS_ECEF_COV_GNSS:
      return sbp_cmp_sbp_msg_pos_ecef_cov_gnss_t(&a->pos_ecef_cov_gnss, &b->pos_ecef_cov_gnss);
    case SBP_MSG_POS_LLH_GNSS:
      return sbp_cmp_sbp_msg_pos_llh_gnss_t(&a->pos_llh_gnss, &b->pos_llh_gnss);
    case SBP_MSG_POS_LLH_COV_GNSS:
      return sbp_cmp_sbp_msg_pos_llh_cov_gnss_t(&a->pos_llh_cov_gnss, &b->pos_llh_cov_gnss);
    case SBP_MSG_VEL_ECEF_GNSS:
      return sbp_cmp_sbp_msg_vel_ecef_gnss_t(&a->vel_ecef_gnss, &b->vel_ecef_gnss);
    case SBP_MSG_VEL_ECEF_COV_GNSS:
      return sbp_cmp_sbp_msg_vel_ecef_cov_gnss_t(&a->vel_ecef_cov_gnss, &b->vel_ecef_cov_gnss);
    case SBP_MSG_VEL_NED_GNSS:
      return sbp_cmp_sbp_msg_vel_ned_gnss_t(&a->vel_ned_gnss, &b->vel_ned_gnss);
    case SBP_MSG_VEL_NED_COV_GNSS:
      return sbp_cmp_sbp_msg_vel_ned_cov_gnss_t(&a->vel_ned_cov_gnss, &b->vel_ned_cov_gnss);
    case SBP_MSG_VEL_BODY:
      return sbp_cmp_sbp_msg_vel_body_t(&a->vel_body, &b->vel_body);
    case SBP_MSG_AGE_CORRECTIONS:
      return sbp_cmp_sbp_msg_age_corrections_t(&a->age_corrections, &b->age_corrections);
    case SBP_MSG_GPS_TIME_DEP_A:
      return sbp_cmp_sbp_msg_gps_time_dep_a_t(&a->gps_time_dep_a, &b->gps_time_dep_a);
    case SBP_MSG_DOPS_DEP_A:
      return sbp_cmp_sbp_msg_dops_dep_a_t(&a->dops_dep_a, &b->dops_dep_a);
    case SBP_MSG_POS_ECEF_DEP_A:
      return sbp_cmp_sbp_msg_pos_ecef_dep_a_t(&a->pos_ecef_dep_a, &b->pos_ecef_dep_a);
    case SBP_MSG_POS_LLH_DEP_A:
      return sbp_cmp_sbp_msg_pos_llh_dep_a_t(&a->pos_llh_dep_a, &b->pos_llh_dep_a);
    case SBP_MSG_BASELINE_ECEF_DEP_A:
      return sbp_cmp_sbp_msg_baseline_ecef_dep_a_t(&a->baseline_ecef_dep_a, &b->baseline_ecef_dep_a);
    case SBP_MSG_BASELINE_NED_DEP_A:
      return sbp_cmp_sbp_msg_baseline_ned_dep_a_t(&a->baseline_ned_dep_a, &b->baseline_ned_dep_a);
    case SBP_MSG_VEL_ECEF_DEP_A:
      return sbp_cmp_sbp_msg_vel_ecef_dep_a_t(&a->vel_ecef_dep_a, &b->vel_ecef_dep_a);
    case SBP_MSG_VEL_NED_DEP_A:
      return sbp_cmp_sbp_msg_vel_ned_dep_a_t(&a->vel_ned_dep_a, &b->vel_ned_dep_a);
    case SBP_MSG_BASELINE_HEADING_DEP_A:
      return sbp_cmp_sbp_msg_baseline_heading_dep_a_t(&a->baseline_heading_dep_a, &b->baseline_heading_dep_a);
    case SBP_MSG_PROTECTION_LEVEL_DEP_A:
      return sbp_cmp_sbp_msg_protection_level_dep_a_t(&a->protection_level_dep_a, &b->protection_level_dep_a);
    case SBP_MSG_PROTECTION_LEVEL:
      return sbp_cmp_sbp_msg_protection_level_t(&a->protection_level, &b->protection_level);
    case SBP_MSG_FILEIO_READ_REQ:
      return sbp_cmp_sbp_msg_fileio_read_req_t(&a->fileio_read_req, &b->fileio_read_req);
    case SBP_MSG_FILEIO_READ_RESP:
      return sbp_cmp_sbp_msg_fileio_read_resp_t(&a->fileio_read_resp, &b->fileio_read_resp);
    case SBP_MSG_FILEIO_READ_DIR_REQ:
      return sbp_cmp_sbp_msg_fileio_read_dir_req_t(&a->fileio_read_dir_req, &b->fileio_read_dir_req);
    case SBP_MSG_FILEIO_READ_DIR_RESP:
      return sbp_cmp_sbp_msg_fileio_read_dir_resp_t(&a->fileio_read_dir_resp, &b->fileio_read_dir_resp);
    case SBP_MSG_FILEIO_REMOVE:
      return sbp_cmp_sbp_msg_fileio_remove_t(&a->fileio_remove, &b->fileio_remove);
    case SBP_MSG_FILEIO_WRITE_REQ:
      return sbp_cmp_sbp_msg_fileio_write_req_t(&a->fileio_write_req, &b->fileio_write_req);
    case SBP_MSG_FILEIO_WRITE_RESP:
      return sbp_cmp_sbp_msg_fileio_write_resp_t(&a->fileio_write_resp, &b->fileio_write_resp);
    case SBP_MSG_FILEIO_CONFIG_REQ:
      return sbp_cmp_sbp_msg_fileio_config_req_t(&a->fileio_config_req, &b->fileio_config_req);
    case SBP_MSG_FILEIO_CONFIG_RESP:
      return sbp_cmp_sbp_msg_fileio_config_resp_t(&a->fileio_config_resp, &b->fileio_config_resp);
    case SBP_MSG_LOG:
      return sbp_cmp_sbp_msg_log_t(&a->log, &b->log);
    case SBP_MSG_FWD:
      return sbp_cmp_sbp_msg_fwd_t(&a->fwd, &b->fwd);
    case SBP_MSG_PRINT_DEP:
      return sbp_cmp_sbp_msg_print_dep_t(&a->print_dep, &b->print_dep);
    case SBP_MSG_BOOTLOADER_HANDSHAKE_REQ:
      return sbp_cmp_sbp_msg_bootloader_handshake_req_t(&a->bootloader_handshake_req, &b->bootloader_handshake_req);
    case SBP_MSG_BOOTLOADER_HANDSHAKE_RESP:
      return sbp_cmp_sbp_msg_bootloader_handshake_resp_t(&a->bootloader_handshake_resp, &b->bootloader_handshake_resp);
    case SBP_MSG_BOOTLOADER_JUMP_TO_APP:
      return sbp_cmp_sbp_msg_bootloader_jump_to_app_t(&a->bootloader_jump_to_app, &b->bootloader_jump_to_app);
    case SBP_MSG_NAP_DEVICE_DNA_REQ:
      return sbp_cmp_sbp_msg_nap_device_dna_req_t(&a->nap_device_dna_req, &b->nap_device_dna_req);
    case SBP_MSG_NAP_DEVICE_DNA_RESP:
      return sbp_cmp_sbp_msg_nap_device_dna_resp_t(&a->nap_device_dna_resp, &b->nap_device_dna_resp);
    case SBP_MSG_BOOTLOADER_HANDSHAKE_DEP_A:
      return sbp_cmp_sbp_msg_bootloader_handshake_dep_a_t(&a->bootloader_handshake_dep_a, &b->bootloader_handshake_dep_a);
    case SBP_MSG_STARTUP:
      return sbp_cmp_sbp_msg_startup_t(&a->startup, &b->startup);
    case SBP_MSG_DGNSS_STATUS:
      return sbp_cmp_sbp_msg_dgnss_status_t(&a->dgnss_status, &b->dgnss_status);
    case SBP_MSG_HEARTBEAT:
      return sbp_cmp_sbp_msg_heartbeat_t(&a->heartbeat, &b->heartbeat);
    case SBP_MSG_STATUS_REPORT:
      return sbp_cmp_sbp_msg_status_report_t(&a->status_report, &b->status_report);
    case SBP_MSG_INS_STATUS:
      return sbp_cmp_sbp_msg_ins_status_t(&a->ins_status, &b->ins_status);
    case SBP_MSG_CSAC_TELEMETRY:
      return sbp_cmp_sbp_msg_csac_telemetry_t(&a->csac_telemetry, &b->csac_telemetry);
    case SBP_MSG_CSAC_TELEMETRY_LABELS:
      return sbp_cmp_sbp_msg_csac_telemetry_labels_t(&a->csac_telemetry_labels, &b->csac_telemetry_labels);
    case SBP_MSG_INS_UPDATES:
      return sbp_cmp_sbp_msg_ins_updates_t(&a->ins_updates, &b->ins_updates);
    case SBP_MSG_GNSS_TIME_OFFSET:
      return sbp_cmp_sbp_msg_gnss_time_offset_t(&a->gnss_time_offset, &b->gnss_time_offset);
    case SBP_MSG_PPS_TIME:
      return sbp_cmp_sbp_msg_pps_time_t(&a->pps_time, &b->pps_time);
    case SBP_MSG_GROUP_META:
      return sbp_cmp_sbp_msg_group_meta_t(&a->group_meta, &b->group_meta);
    case SBP_MSG_OBS:
      return sbp_cmp_sbp_msg_obs_t(&a->obs, &b->obs);
    case SBP_MSG_BASE_POS_LLH:
      return sbp_cmp_sbp_msg_base_pos_llh_t(&a->base_pos_llh, &b->base_pos_llh);
    case SBP_MSG_BASE_POS_ECEF:
      return sbp_cmp_sbp_msg_base_pos_ecef_t(&a->base_pos_ecef, &b->base_pos_ecef);
    case SBP_MSG_EPHEMERIS_GPS_DEP_E:
      return sbp_cmp_sbp_msg_ephemeris_gps_dep_e_t(&a->ephemeris_gps_dep_e, &b->ephemeris_gps_dep_e);
    case SBP_MSG_EPHEMERIS_GPS_DEP_F:
      return sbp_cmp_sbp_msg_ephemeris_gps_dep_f_t(&a->ephemeris_gps_dep_f, &b->ephemeris_gps_dep_f);
    case SBP_MSG_EPHEMERIS_GPS:
      return sbp_cmp_sbp_msg_ephemeris_gps_t(&a->ephemeris_gps, &b->ephemeris_gps);
    case SBP_MSG_EPHEMERIS_QZSS:
      return sbp_cmp_sbp_msg_ephemeris_qzss_t(&a->ephemeris_qzss, &b->ephemeris_qzss);
    case SBP_MSG_EPHEMERIS_BDS:
      return sbp_cmp_sbp_msg_ephemeris_bds_t(&a->ephemeris_bds, &b->ephemeris_bds);
    case SBP_MSG_EPHEMERIS_GAL_DEP_A:
      return sbp_cmp_sbp_msg_ephemeris_gal_dep_a_t(&a->ephemeris_gal_dep_a, &b->ephemeris_gal_dep_a);
    case SBP_MSG_EPHEMERIS_GAL:
      return sbp_cmp_sbp_msg_ephemeris_gal_t(&a->ephemeris_gal, &b->ephemeris_gal);
    case SBP_MSG_EPHEMERIS_SBAS_DEP_A:
      return sbp_cmp_sbp_msg_ephemeris_sbas_dep_a_t(&a->ephemeris_sbas_dep_a, &b->ephemeris_sbas_dep_a);
    case SBP_MSG_EPHEMERIS_GLO_DEP_A:
      return sbp_cmp_sbp_msg_ephemeris_glo_dep_a_t(&a->ephemeris_glo_dep_a, &b->ephemeris_glo_dep_a);
    case SBP_MSG_EPHEMERIS_SBAS_DEP_B:
      return sbp_cmp_sbp_msg_ephemeris_sbas_dep_b_t(&a->ephemeris_sbas_dep_b, &b->ephemeris_sbas_dep_b);
    case SBP_MSG_EPHEMERIS_SBAS:
      return sbp_cmp_sbp_msg_ephemeris_sbas_t(&a->ephemeris_sbas, &b->ephemeris_sbas);
    case SBP_MSG_EPHEMERIS_GLO_DEP_B:
      return sbp_cmp_sbp_msg_ephemeris_glo_dep_b_t(&a->ephemeris_glo_dep_b, &b->ephemeris_glo_dep_b);
    case SBP_MSG_EPHEMERIS_GLO_DEP_C:
      return sbp_cmp_sbp_msg_ephemeris_glo_dep_c_t(&a->ephemeris_glo_dep_c, &b->ephemeris_glo_dep_c);
    case SBP_MSG_EPHEMERIS_GLO_DEP_D:
      return sbp_cmp_sbp_msg_ephemeris_glo_dep_d_t(&a->ephemeris_glo_dep_d, &b->ephemeris_glo_dep_d);
    case SBP_MSG_EPHEMERIS_GLO:
      return sbp_cmp_sbp_msg_ephemeris_glo_t(&a->ephemeris_glo, &b->ephemeris_glo);
    case SBP_MSG_EPHEMERIS_DEP_D:
      return sbp_cmp_sbp_msg_ephemeris_dep_d_t(&a->ephemeris_dep_d, &b->ephemeris_dep_d);
    case SBP_MSG_EPHEMERIS_DEP_A:
      return sbp_cmp_sbp_msg_ephemeris_dep_a_t(&a->ephemeris_dep_a, &b->ephemeris_dep_a);
    case SBP_MSG_EPHEMERIS_DEP_B:
      return sbp_cmp_sbp_msg_ephemeris_dep_b_t(&a->ephemeris_dep_b, &b->ephemeris_dep_b);
    case SBP_MSG_EPHEMERIS_DEP_C:
      return sbp_cmp_sbp_msg_ephemeris_dep_c_t(&a->ephemeris_dep_c, &b->ephemeris_dep_c);
    case SBP_MSG_OBS_DEP_A:
      return sbp_cmp_sbp_msg_obs_dep_a_t(&a->obs_dep_a, &b->obs_dep_a);
    case SBP_MSG_OBS_DEP_B:
      return sbp_cmp_sbp_msg_obs_dep_b_t(&a->obs_dep_b, &b->obs_dep_b);
    case SBP_MSG_OBS_DEP_C:
      return sbp_cmp_sbp_msg_obs_dep_c_t(&a->obs_dep_c, &b->obs_dep_c);
    case SBP_MSG_IONO:
      return sbp_cmp_sbp_msg_iono_t(&a->iono, &b->iono);
    case SBP_MSG_SV_CONFIGURATION_GPS_DEP:
      return sbp_cmp_sbp_msg_sv_configuration_gps_dep_t(&a->sv_configuration_gps_dep, &b->sv_configuration_gps_dep);
    case SBP_MSG_GNSS_CAPB:
      return sbp_cmp_sbp_msg_gnss_capb_t(&a->gnss_capb, &b->gnss_capb);
    case SBP_MSG_GROUP_DELAY_DEP_A:
      return sbp_cmp_sbp_msg_group_delay_dep_a_t(&a->group_delay_dep_a, &b->group_delay_dep_a);
    case SBP_MSG_GROUP_DELAY_DEP_B:
      return sbp_cmp_sbp_msg_group_delay_dep_b_t(&a->group_delay_dep_b, &b->group_delay_dep_b);
    case SBP_MSG_GROUP_DELAY:
      return sbp_cmp_sbp_msg_group_delay_t(&a->group_delay, &b->group_delay);
    case SBP_MSG_ALMANAC_GPS_DEP:
      return sbp_cmp_sbp_msg_almanac_gps_dep_t(&a->almanac_gps_dep, &b->almanac_gps_dep);
    case SBP_MSG_ALMANAC_GPS:
      return sbp_cmp_sbp_msg_almanac_gps_t(&a->almanac_gps, &b->almanac_gps);
    case SBP_MSG_ALMANAC_GLO_DEP:
      return sbp_cmp_sbp_msg_almanac_glo_dep_t(&a->almanac_glo_dep, &b->almanac_glo_dep);
    case SBP_MSG_ALMANAC_GLO:
      return sbp_cmp_sbp_msg_almanac_glo_t(&a->almanac_glo, &b->almanac_glo);
    case SBP_MSG_GLO_BIASES:
      return sbp_cmp_sbp_msg_glo_biases_t(&a->glo_biases, &b->glo_biases);
    case SBP_MSG_SV_AZ_EL:
      return sbp_cmp_sbp_msg_sv_az_el_t(&a->sv_az_el, &b->sv_az_el);
    case SBP_MSG_OSR:
      return sbp_cmp_sbp_msg_osr_t(&a->osr, &b->osr);
    case SBP_MSG_SBAS_RAW:
      return sbp_cmp_sbp_msg_sbas_raw_t(&a->sbas_raw, &b->sbas_raw);
    case SBP_MSG_ALMANAC:
      return sbp_cmp_sbp_msg_almanac_t(&a->almanac, &b->almanac);
    case SBP_MSG_SET_TIME:
      return sbp_cmp_sbp_msg_set_time_t(&a->set_time, &b->set_time);
    case SBP_MSG_RESET:
      return sbp_cmp_sbp_msg_reset_t(&a->reset, &b->reset);
    case SBP_MSG_RESET_DEP:
      return sbp_cmp_sbp_msg_reset_dep_t(&a->reset_dep, &b->reset_dep);
    case SBP_MSG_CW_RESULTS:
      return sbp_cmp_sbp_msg_cw_results_t(&a->cw_results, &b->cw_results);
    case SBP_MSG_CW_START:
      return sbp_cmp_sbp_msg_cw_start_t(&a->cw_start, &b->cw_start);
    case SBP_MSG_RESET_FILTERS:
      return sbp_cmp_sbp_msg_reset_filters_t(&a->reset_filters, &b->reset_filters);
    case SBP_MSG_INIT_BASE_DEP:
      return sbp_cmp_sbp_msg_init_base_dep_t(&a->init_base_dep, &b->init_base_dep);
    case SBP_MSG_THREAD_STATE:
      return sbp_cmp_sbp_msg_thread_state_t(&a->thread_state, &b->thread_state);
    case SBP_MSG_UART_STATE:
      return sbp_cmp_sbp_msg_uart_state_t(&a->uart_state, &b->uart_state);
    case SBP_MSG_UART_STATE_DEPA:
      return sbp_cmp_sbp_msg_uart_state_depa_t(&a->uart_state_depa, &b->uart_state_depa);
    case SBP_MSG_IAR_STATE:
      return sbp_cmp_sbp_msg_iar_state_t(&a->iar_state, &b->iar_state);
    case SBP_MSG_MASK_SATELLITE:
      return sbp_cmp_sbp_msg_mask_satellite_t(&a->mask_satellite, &b->mask_satellite);
    case SBP_MSG_MASK_SATELLITE_DEP:
      return sbp_cmp_sbp_msg_mask_satellite_dep_t(&a->mask_satellite_dep, &b->mask_satellite_dep);
    case SBP_MSG_DEVICE_MONITOR:
      return sbp_cmp_sbp_msg_device_monitor_t(&a->device_monitor, &b->device_monitor);
    case SBP_MSG_COMMAND_REQ:
      return sbp_cmp_sbp_msg_command_req_t(&a->command_req, &b->command_req);
    case SBP_MSG_COMMAND_RESP:
      return sbp_cmp_sbp_msg_command_resp_t(&a->command_resp, &b->command_resp);
    case SBP_MSG_COMMAND_OUTPUT:
      return sbp_cmp_sbp_msg_command_output_t(&a->command_output, &b->command_output);
    case SBP_MSG_NETWORK_STATE_REQ:
      return sbp_cmp_sbp_msg_network_state_req_t(&a->network_state_req, &b->network_state_req);
    case SBP_MSG_NETWORK_STATE_RESP:
      return sbp_cmp_sbp_msg_network_state_resp_t(&a->network_state_resp, &b->network_state_resp);
    case SBP_MSG_NETWORK_BANDWIDTH_USAGE:
      return sbp_cmp_sbp_msg_network_bandwidth_usage_t(&a->network_bandwidth_usage, &b->network_bandwidth_usage);
    case SBP_MSG_CELL_MODEM_STATUS:
      return sbp_cmp_sbp_msg_cell_modem_status_t(&a->cell_modem_status, &b->cell_modem_status);
    case SBP_MSG_SPECAN_DEP:
      return sbp_cmp_sbp_msg_specan_dep_t(&a->specan_dep, &b->specan_dep);
    case SBP_MSG_SPECAN:
      return sbp_cmp_sbp_msg_specan_t(&a->specan, &b->specan);
    case SBP_MSG_FRONT_END_GAIN:
      return sbp_cmp_sbp_msg_front_end_gain_t(&a->front_end_gain, &b->front_end_gain);
    case SBP_MSG_FLASH_PROGRAM:
      return sbp_cmp_sbp_msg_flash_program_t(&a->flash_program, &b->flash_program);
    case SBP_MSG_FLASH_DONE:
      return sbp_cmp_sbp_msg_flash_done_t(&a->flash_done, &b->flash_done);
    case SBP_MSG_FLASH_READ_REQ:
      return sbp_cmp_sbp_msg_flash_read_req_t(&a->flash_read_req, &b->flash_read_req);
    case SBP_MSG_FLASH_READ_RESP:
      return sbp_cmp_sbp_msg_flash_read_resp_t(&a->flash_read_resp, &b->flash_read_resp);
    case SBP_MSG_FLASH_ERASE:
      return sbp_cmp_sbp_msg_flash_erase_t(&a->flash_erase, &b->flash_erase);
    case SBP_MSG_STM_FLASH_LOCK_SECTOR:
      return sbp_cmp_sbp_msg_stm_flash_lock_sector_t(&a->stm_flash_lock_sector, &b->stm_flash_lock_sector);
    case SBP_MSG_STM_FLASH_UNLOCK_SECTOR:
      return sbp_cmp_sbp_msg_stm_flash_unlock_sector_t(&a->stm_flash_unlock_sector, &b->stm_flash_unlock_sector);
    case SBP_MSG_STM_UNIQUE_ID_REQ:
      return sbp_cmp_sbp_msg_stm_unique_id_req_t(&a->stm_unique_id_req, &b->stm_unique_id_req);
    case SBP_MSG_STM_UNIQUE_ID_RESP:
      return sbp_cmp_sbp_msg_stm_unique_id_resp_t(&a->stm_unique_id_resp, &b->stm_unique_id_resp);
    case SBP_MSG_M25_FLASH_WRITE_STATUS:
      return sbp_cmp_sbp_msg_m25_flash_write_status_t(&a->m25_flash_write_status, &b->m25_flash_write_status);
    case SBP_MSG_IMU_RAW:
      return sbp_cmp_sbp_msg_imu_raw_t(&a->imu_raw, &b->imu_raw);
    case SBP_MSG_IMU_AUX:
      return sbp_cmp_sbp_msg_imu_aux_t(&a->imu_aux, &b->imu_aux);
    case SBP_MSG_NDB_EVENT:
      return sbp_cmp_sbp_msg_ndb_event_t(&a->ndb_event, &b->ndb_event);
    case SBP_MSG_ACQ_RESULT:
      return sbp_cmp_sbp_msg_acq_result_t(&a->acq_result, &b->acq_result);
    case SBP_MSG_ACQ_RESULT_DEP_C:
      return sbp_cmp_sbp_msg_acq_result_dep_c_t(&a->acq_result_dep_c, &b->acq_result_dep_c);
    case SBP_MSG_ACQ_RESULT_DEP_B:
      return sbp_cmp_sbp_msg_acq_result_dep_b_t(&a->acq_result_dep_b, &b->acq_result_dep_b);
    case SBP_MSG_ACQ_RESULT_DEP_A:
      return sbp_cmp_sbp_msg_acq_result_dep_a_t(&a->acq_result_dep_a, &b->acq_result_dep_a);
    case SBP_MSG_ACQ_SV_PROFILE:
      return sbp_cmp_sbp_msg_acq_sv_profile_t(&a->acq_sv_profile, &b->acq_sv_profile);
    case SBP_MSG_ACQ_SV_PROFILE_DEP:
      return sbp_cmp_sbp_msg_acq_sv_profile_dep_t(&a->acq_sv_profile_dep, &b->acq_sv_profile_dep);
    case SBP_MSG_SOLN_META_DEP_A:
      return sbp_cmp_sbp_msg_soln_meta_dep_a_t(&a->soln_meta_dep_a, &b->soln_meta_dep_a);
    case SBP_MSG_SOLN_META:
      return sbp_cmp_sbp_msg_soln_meta_t(&a->soln_meta, &b->soln_meta);
    case SBP_MSG_BASELINE_HEADING:
      return sbp_cmp_sbp_msg_baseline_heading_t(&a->baseline_heading, &b->baseline_heading);
    case SBP_MSG_ORIENT_QUAT:
      return sbp_cmp_sbp_msg_orient_quat_t(&a->orient_quat, &b->orient_quat);
    case SBP_MSG_ORIENT_EULER:
      return sbp_cmp_sbp_msg_orient_euler_t(&a->orient_euler, &b->orient_euler);
    case SBP_MSG_ANGULAR_RATE:
      return sbp_cmp_sbp_msg_angular_rate_t(&a->angular_rate, &b->angular_rate);
    case SBP_MSG_MAG_RAW:
      return sbp_cmp_sbp_msg_mag_raw_t(&a->mag_raw, &b->mag_raw);
    default:
      break;
  }
  return false;
}

#ifdef __cplusplus
}
#endif

#endif
