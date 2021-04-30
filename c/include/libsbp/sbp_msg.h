#ifndef NEW_MESSAGES_UNION_H
#define NEW_MESSAGES_UNION_H

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
#include <libsbp/solution_meta.h>
#include <libsbp/ssr.h>
#include <libsbp/system.h>
#include <libsbp/tracking.h>
#include <libsbp/user.h>
#include <libsbp/vehicle.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

typedef struct
{
  u16 type;
  union
  {
    sbp_msg_sbas_raw_t MSG_SBAS_RAW;
    sbp_msg_baseline_heading_t MSG_BASELINE_HEADING;
    sbp_msg_orient_quat_t MSG_ORIENT_QUAT;
    sbp_msg_orient_euler_t MSG_ORIENT_EULER;
    sbp_msg_angular_rate_t MSG_ANGULAR_RATE;
    sbp_msg_almanac_t MSG_ALMANAC;
    sbp_msg_set_time_t MSG_SET_TIME;
    sbp_msg_reset_t MSG_RESET;
    sbp_msg_reset_dep_t MSG_RESET_DEP;
    sbp_msg_cw_results_t MSG_CW_RESULTS;
    sbp_msg_cw_start_t MSG_CW_START;
    sbp_msg_reset_filters_t MSG_RESET_FILTERS;
    sbp_msg_init_base_dep_t MSG_INIT_BASE_DEP;
    sbp_msg_thread_state_t MSG_THREAD_STATE;
    sbp_msg_uart_state_t MSG_UART_STATE;
    sbp_msg_uart_state_depa_t MSG_UART_STATE_DEPA;
    sbp_msg_iar_state_t MSG_IAR_STATE;
    sbp_msg_mask_satellite_t MSG_MASK_SATELLITE;
    sbp_msg_mask_satellite_dep_t MSG_MASK_SATELLITE_DEP;
    sbp_msg_device_monitor_t MSG_DEVICE_MONITOR;
    sbp_msg_command_req_t MSG_COMMAND_REQ;
    sbp_msg_command_resp_t MSG_COMMAND_RESP;
    sbp_msg_command_output_t MSG_COMMAND_OUTPUT;
    sbp_msg_network_state_req_t MSG_NETWORK_STATE_REQ;
    sbp_msg_network_state_resp_t MSG_NETWORK_STATE_RESP;
    sbp_msg_network_bandwidth_usage_t MSG_NETWORK_BANDWIDTH_USAGE;
    sbp_msg_cell_modem_status_t MSG_CELL_MODEM_STATUS;
    sbp_msg_specan_dep_t MSG_SPECAN_DEP;
    sbp_msg_specan_t MSG_SPECAN;
    sbp_msg_front_end_gain_t MSG_FRONT_END_GAIN;
    sbp_msg_mag_raw_t MSG_MAG_RAW;
    sbp_msg_gps_time_t MSG_GPS_TIME;
    sbp_msg_gps_time_gnss_t MSG_GPS_TIME_GNSS;
    sbp_msg_utc_time_t MSG_UTC_TIME;
    sbp_msg_utc_time_gnss_t MSG_UTC_TIME_GNSS;
    sbp_msg_dops_t MSG_DOPS;
    sbp_msg_pos_ecef_t MSG_POS_ECEF;
    sbp_msg_pos_ecef_cov_t MSG_POS_ECEF_COV;
    sbp_msg_pos_llh_t MSG_POS_LLH;
    sbp_msg_pos_llh_cov_t MSG_POS_LLH_COV;
    sbp_msg_baseline_ecef_t MSG_BASELINE_ECEF;
    sbp_msg_baseline_ned_t MSG_BASELINE_NED;
    sbp_msg_vel_ecef_t MSG_VEL_ECEF;
    sbp_msg_vel_ecef_cov_t MSG_VEL_ECEF_COV;
    sbp_msg_vel_ned_t MSG_VEL_NED;
    sbp_msg_vel_ned_cov_t MSG_VEL_NED_COV;
    sbp_msg_pos_ecef_gnss_t MSG_POS_ECEF_GNSS;
    sbp_msg_pos_ecef_cov_gnss_t MSG_POS_ECEF_COV_GNSS;
    sbp_msg_pos_llh_gnss_t MSG_POS_LLH_GNSS;
    sbp_msg_pos_llh_cov_gnss_t MSG_POS_LLH_COV_GNSS;
    sbp_msg_vel_ecef_gnss_t MSG_VEL_ECEF_GNSS;
    sbp_msg_vel_ecef_cov_gnss_t MSG_VEL_ECEF_COV_GNSS;
    sbp_msg_vel_ned_gnss_t MSG_VEL_NED_GNSS;
    sbp_msg_vel_ned_cov_gnss_t MSG_VEL_NED_COV_GNSS;
    sbp_msg_vel_body_t MSG_VEL_BODY;
    sbp_msg_age_corrections_t MSG_AGE_CORRECTIONS;
    sbp_msg_gps_time_dep_a_t MSG_GPS_TIME_DEP_A;
    sbp_msg_dops_dep_a_t MSG_DOPS_DEP_A;
    sbp_msg_pos_ecef_dep_a_t MSG_POS_ECEF_DEP_A;
    sbp_msg_pos_llh_dep_a_t MSG_POS_LLH_DEP_A;
    sbp_msg_baseline_ecef_dep_a_t MSG_BASELINE_ECEF_DEP_A;
    sbp_msg_baseline_ned_dep_a_t MSG_BASELINE_NED_DEP_A;
    sbp_msg_vel_ecef_dep_a_t MSG_VEL_ECEF_DEP_A;
    sbp_msg_vel_ned_dep_a_t MSG_VEL_NED_DEP_A;
    sbp_msg_baseline_heading_dep_a_t MSG_BASELINE_HEADING_DEP_A;
    sbp_msg_protection_level_t MSG_PROTECTION_LEVEL;
    sbp_msg_ndb_event_t MSG_NDB_EVENT;
    sbp_msg_linux_cpu_state_dep_a_t MSG_LINUX_CPU_STATE_DEP_A;
    sbp_msg_linux_mem_state_dep_a_t MSG_LINUX_MEM_STATE_DEP_A;
    sbp_msg_linux_sys_state_dep_a_t MSG_LINUX_SYS_STATE_DEP_A;
    sbp_msg_linux_process_socket_counts_t MSG_LINUX_PROCESS_SOCKET_COUNTS;
    sbp_msg_linux_process_socket_queues_t MSG_LINUX_PROCESS_SOCKET_QUEUES;
    sbp_msg_linux_socket_usage_t MSG_LINUX_SOCKET_USAGE;
    sbp_msg_linux_process_fd_count_t MSG_LINUX_PROCESS_FD_COUNT;
    sbp_msg_linux_process_fd_summary_t MSG_LINUX_PROCESS_FD_SUMMARY;
    sbp_msg_linux_cpu_state_t MSG_LINUX_CPU_STATE;
    sbp_msg_linux_mem_state_t MSG_LINUX_MEM_STATE;
    sbp_msg_linux_sys_state_t MSG_LINUX_SYS_STATE;
    sbp_msg_log_t MSG_LOG;
    sbp_msg_fwd_t MSG_FWD;
    sbp_msg_print_dep_t MSG_PRINT_DEP;
    sbp_msg_obs_t MSG_OBS;
    sbp_msg_base_pos_llh_t MSG_BASE_POS_LLH;
    sbp_msg_base_pos_ecef_t MSG_BASE_POS_ECEF;
    sbp_msg_ephemeris_gps_dep_e_t MSG_EPHEMERIS_GPS_DEP_E;
    sbp_msg_ephemeris_gps_dep_f_t MSG_EPHEMERIS_GPS_DEP_F;
    sbp_msg_ephemeris_gps_t MSG_EPHEMERIS_GPS;
    sbp_msg_ephemeris_qzss_t MSG_EPHEMERIS_QZSS;
    sbp_msg_ephemeris_bds_t MSG_EPHEMERIS_BDS;
    sbp_msg_ephemeris_gal_dep_a_t MSG_EPHEMERIS_GAL_DEP_A;
    sbp_msg_ephemeris_gal_t MSG_EPHEMERIS_GAL;
    sbp_msg_ephemeris_sbas_dep_a_t MSG_EPHEMERIS_SBAS_DEP_A;
    sbp_msg_ephemeris_glo_dep_a_t MSG_EPHEMERIS_GLO_DEP_A;
    sbp_msg_ephemeris_sbas_dep_b_t MSG_EPHEMERIS_SBAS_DEP_B;
    sbp_msg_ephemeris_sbas_t MSG_EPHEMERIS_SBAS;
    sbp_msg_ephemeris_glo_dep_b_t MSG_EPHEMERIS_GLO_DEP_B;
    sbp_msg_ephemeris_glo_dep_c_t MSG_EPHEMERIS_GLO_DEP_C;
    sbp_msg_ephemeris_glo_dep_d_t MSG_EPHEMERIS_GLO_DEP_D;
    sbp_msg_ephemeris_glo_t MSG_EPHEMERIS_GLO;
    sbp_msg_ephemeris_dep_d_t MSG_EPHEMERIS_DEP_D;
    sbp_msg_ephemeris_dep_a_t MSG_EPHEMERIS_DEP_A;
    sbp_msg_ephemeris_dep_b_t MSG_EPHEMERIS_DEP_B;
    sbp_msg_ephemeris_dep_c_t MSG_EPHEMERIS_DEP_C;
    sbp_msg_obs_dep_a_t MSG_OBS_DEP_A;
    sbp_msg_obs_dep_b_t MSG_OBS_DEP_B;
    sbp_msg_obs_dep_c_t MSG_OBS_DEP_C;
    sbp_msg_iono_t MSG_IONO;
    sbp_msg_sv_configuration_gps_dep_t MSG_SV_CONFIGURATION_GPS_DEP;
    sbp_msg_gnss_capb_t MSG_GNSS_CAPB;
    sbp_msg_group_delay_dep_a_t MSG_GROUP_DELAY_DEP_A;
    sbp_msg_group_delay_dep_b_t MSG_GROUP_DELAY_DEP_B;
    sbp_msg_group_delay_t MSG_GROUP_DELAY;
    sbp_msg_almanac_gps_dep_t MSG_ALMANAC_GPS_DEP;
    sbp_msg_almanac_gps_t MSG_ALMANAC_GPS;
    sbp_msg_almanac_glo_dep_t MSG_ALMANAC_GLO_DEP;
    sbp_msg_almanac_glo_t MSG_ALMANAC_GLO;
    sbp_msg_glo_biases_t MSG_GLO_BIASES;
    sbp_msg_sv_az_el_t MSG_SV_AZ_EL;
    sbp_msg_osr_t MSG_OSR;
    sbp_msg_acq_result_t MSG_ACQ_RESULT;
    sbp_msg_acq_result_dep_c_t MSG_ACQ_RESULT_DEP_C;
    sbp_msg_acq_result_dep_b_t MSG_ACQ_RESULT_DEP_B;
    sbp_msg_acq_result_dep_a_t MSG_ACQ_RESULT_DEP_A;
    sbp_msg_acq_sv_profile_t MSG_ACQ_SV_PROFILE;
    sbp_msg_acq_sv_profile_dep_t MSG_ACQ_SV_PROFILE_DEP;
    sbp_msg_ssr_orbit_clock_t MSG_SSR_ORBIT_CLOCK;
    sbp_msg_ssr_code_biases_t MSG_SSR_CODE_BIASES;
    sbp_msg_ssr_phase_biases_t MSG_SSR_PHASE_BIASES;
    sbp_msg_ssr_stec_correction_t MSG_SSR_STEC_CORRECTION;
    sbp_msg_ssr_gridded_correction_t MSG_SSR_GRIDDED_CORRECTION;
    sbp_msg_ssr_tile_definition_t MSG_SSR_TILE_DEFINITION;
    sbp_msg_ssr_satellite_apc_t MSG_SSR_SATELLITE_APC;
    sbp_msg_ssr_orbit_clock_dep_a_t MSG_SSR_ORBIT_CLOCK_DEP_A;
    sbp_msg_ssr_stec_correction_dep_a_t MSG_SSR_STEC_CORRECTION_DEP_A;
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t MSG_SSR_GRIDDED_CORRECTION_NO_STD_DEP_A;
    sbp_msg_ssr_gridded_correction_dep_a_t MSG_SSR_GRIDDED_CORRECTION_DEP_A;
    sbp_msg_ssr_grid_definition_dep_a_t MSG_SSR_GRID_DEFINITION_DEP_A;
    sbp_msg_bootloader_handshake_req_t MSG_BOOTLOADER_HANDSHAKE_REQ;
    sbp_msg_bootloader_handshake_resp_t MSG_BOOTLOADER_HANDSHAKE_RESP;
    sbp_msg_bootloader_jump_to_app_t MSG_BOOTLOADER_JUMP_TO_APP;
    sbp_msg_nap_device_dna_req_t MSG_NAP_DEVICE_DNA_REQ;
    sbp_msg_nap_device_dna_resp_t MSG_NAP_DEVICE_DNA_RESP;
    sbp_msg_bootloader_handshake_dep_a_t MSG_BOOTLOADER_HANDSHAKE_DEP_A;
    sbp_msg_user_data_t MSG_USER_DATA;
    sbp_msg_settings_save_t MSG_SETTINGS_SAVE;
    sbp_msg_settings_write_t MSG_SETTINGS_WRITE;
    sbp_msg_settings_write_resp_t MSG_SETTINGS_WRITE_RESP;
    sbp_msg_settings_read_req_t MSG_SETTINGS_READ_REQ;
    sbp_msg_settings_read_resp_t MSG_SETTINGS_READ_RESP;
    sbp_msg_settings_read_by_index_req_t MSG_SETTINGS_READ_BY_INDEX_REQ;
    sbp_msg_settings_read_by_index_resp_t MSG_SETTINGS_READ_BY_INDEX_RESP;
    sbp_msg_settings_read_by_index_done_t MSG_SETTINGS_READ_BY_INDEX_DONE;
    sbp_msg_settings_register_t MSG_SETTINGS_REGISTER;
    sbp_msg_settings_register_resp_t MSG_SETTINGS_REGISTER_RESP;
    sbp_msg_imu_raw_t MSG_IMU_RAW;
    sbp_msg_imu_aux_t MSG_IMU_AUX;
    sbp_msg_fileio_read_req_t MSG_FILEIO_READ_REQ;
    sbp_msg_fileio_read_resp_t MSG_FILEIO_READ_RESP;
    sbp_msg_fileio_read_dir_req_t MSG_FILEIO_READ_DIR_REQ;
    sbp_msg_fileio_read_dir_resp_t MSG_FILEIO_READ_DIR_RESP;
    sbp_msg_fileio_remove_t MSG_FILEIO_REMOVE;
    sbp_msg_fileio_write_req_t MSG_FILEIO_WRITE_REQ;
    sbp_msg_fileio_write_resp_t MSG_FILEIO_WRITE_RESP;
    sbp_msg_fileio_config_req_t MSG_FILEIO_CONFIG_REQ;
    sbp_msg_fileio_config_resp_t MSG_FILEIO_CONFIG_RESP;
    sbp_msg_odometry_t MSG_ODOMETRY;
    sbp_msg_wheeltick_t MSG_WHEELTICK;
    sbp_msg_soln_meta_dep_a_t MSG_SOLN_META_DEP_A;
    sbp_msg_soln_meta_t MSG_SOLN_META;
    sbp_msg_flash_program_t MSG_FLASH_PROGRAM;
    sbp_msg_flash_done_t MSG_FLASH_DONE;
    sbp_msg_flash_read_req_t MSG_FLASH_READ_REQ;
    sbp_msg_flash_read_resp_t MSG_FLASH_READ_RESP;
    sbp_msg_flash_erase_t MSG_FLASH_ERASE;
    sbp_msg_stm_flash_lock_sector_t MSG_STM_FLASH_LOCK_SECTOR;
    sbp_msg_stm_flash_unlock_sector_t MSG_STM_FLASH_UNLOCK_SECTOR;
    sbp_msg_stm_unique_id_req_t MSG_STM_UNIQUE_ID_REQ;
    sbp_msg_stm_unique_id_resp_t MSG_STM_UNIQUE_ID_RESP;
    sbp_msg_m25_flash_write_status_t MSG_M25_FLASH_WRITE_STATUS;
    sbp_msg_tracking_state_detailed_dep_a_t MSG_TRACKING_STATE_DETAILED_DEP_A;
    sbp_msg_tracking_state_detailed_dep_t MSG_TRACKING_STATE_DETAILED_DEP;
    sbp_msg_tracking_state_t MSG_TRACKING_STATE;
    sbp_msg_measurement_state_t MSG_MEASUREMENT_STATE;
    sbp_msg_tracking_iq_t MSG_TRACKING_IQ;
    sbp_msg_tracking_iq_dep_b_t MSG_TRACKING_IQ_DEP_B;
    sbp_msg_tracking_iq_dep_a_t MSG_TRACKING_IQ_DEP_A;
    sbp_msg_tracking_state_dep_a_t MSG_TRACKING_STATE_DEP_A;
    sbp_msg_tracking_state_dep_b_t MSG_TRACKING_STATE_DEP_B;
    sbp_msg_ext_event_t MSG_EXT_EVENT;
    sbp_msg_startup_t MSG_STARTUP;
    sbp_msg_dgnss_status_t MSG_DGNSS_STATUS;
    sbp_msg_heartbeat_t MSG_HEARTBEAT;
    sbp_msg_status_report_t MSG_STATUS_REPORT;
    sbp_msg_ins_status_t MSG_INS_STATUS;
    sbp_msg_csac_telemetry_t MSG_CSAC_TELEMETRY;
    sbp_msg_csac_telemetry_labels_t MSG_CSAC_TELEMETRY_LABELS;
    sbp_msg_ins_updates_t MSG_INS_UPDATES;
    sbp_msg_gnss_time_offset_t MSG_GNSS_TIME_OFFSET;
    sbp_msg_group_meta_t MSG_GROUP_META;
  };
} sbp_msg_t;

static inline bool sbp_pack_msg(uint8_t *buf, size_t len, const sbp_msg_t *msg)
{
  switch (msg->type)
  {
    case SBP_MSG_SBAS_RAW:
      return sbp_pack_sbp_msg_sbas_raw_t(buf, len, &msg->MSG_SBAS_RAW);
    case SBP_MSG_BASELINE_HEADING:
      return sbp_pack_sbp_msg_baseline_heading_t(buf, len, &msg->MSG_BASELINE_HEADING);
    case SBP_MSG_ORIENT_QUAT:
      return sbp_pack_sbp_msg_orient_quat_t(buf, len, &msg->MSG_ORIENT_QUAT);
    case SBP_MSG_ORIENT_EULER:
      return sbp_pack_sbp_msg_orient_euler_t(buf, len, &msg->MSG_ORIENT_EULER);
    case SBP_MSG_ANGULAR_RATE:
      return sbp_pack_sbp_msg_angular_rate_t(buf, len, &msg->MSG_ANGULAR_RATE);
    case SBP_MSG_ALMANAC:
      return sbp_pack_sbp_msg_almanac_t(buf, len, &msg->MSG_ALMANAC);
    case SBP_MSG_SET_TIME:
      return sbp_pack_sbp_msg_set_time_t(buf, len, &msg->MSG_SET_TIME);
    case SBP_MSG_RESET:
      return sbp_pack_sbp_msg_reset_t(buf, len, &msg->MSG_RESET);
    case SBP_MSG_RESET_DEP:
      return sbp_pack_sbp_msg_reset_dep_t(buf, len, &msg->MSG_RESET_DEP);
    case SBP_MSG_CW_RESULTS:
      return sbp_pack_sbp_msg_cw_results_t(buf, len, &msg->MSG_CW_RESULTS);
    case SBP_MSG_CW_START:
      return sbp_pack_sbp_msg_cw_start_t(buf, len, &msg->MSG_CW_START);
    case SBP_MSG_RESET_FILTERS:
      return sbp_pack_sbp_msg_reset_filters_t(buf, len, &msg->MSG_RESET_FILTERS);
    case SBP_MSG_INIT_BASE_DEP:
      return sbp_pack_sbp_msg_init_base_dep_t(buf, len, &msg->MSG_INIT_BASE_DEP);
    case SBP_MSG_THREAD_STATE:
      return sbp_pack_sbp_msg_thread_state_t(buf, len, &msg->MSG_THREAD_STATE);
    case SBP_MSG_UART_STATE:
      return sbp_pack_sbp_msg_uart_state_t(buf, len, &msg->MSG_UART_STATE);
    case SBP_MSG_UART_STATE_DEPA:
      return sbp_pack_sbp_msg_uart_state_depa_t(buf, len, &msg->MSG_UART_STATE_DEPA);
    case SBP_MSG_IAR_STATE:
      return sbp_pack_sbp_msg_iar_state_t(buf, len, &msg->MSG_IAR_STATE);
    case SBP_MSG_MASK_SATELLITE:
      return sbp_pack_sbp_msg_mask_satellite_t(buf, len, &msg->MSG_MASK_SATELLITE);
    case SBP_MSG_MASK_SATELLITE_DEP:
      return sbp_pack_sbp_msg_mask_satellite_dep_t(buf, len, &msg->MSG_MASK_SATELLITE_DEP);
    case SBP_MSG_DEVICE_MONITOR:
      return sbp_pack_sbp_msg_device_monitor_t(buf, len, &msg->MSG_DEVICE_MONITOR);
    case SBP_MSG_COMMAND_REQ:
      return sbp_pack_sbp_msg_command_req_t(buf, len, &msg->MSG_COMMAND_REQ);
    case SBP_MSG_COMMAND_RESP:
      return sbp_pack_sbp_msg_command_resp_t(buf, len, &msg->MSG_COMMAND_RESP);
    case SBP_MSG_COMMAND_OUTPUT:
      return sbp_pack_sbp_msg_command_output_t(buf, len, &msg->MSG_COMMAND_OUTPUT);
    case SBP_MSG_NETWORK_STATE_REQ:
      return sbp_pack_sbp_msg_network_state_req_t(buf, len, &msg->MSG_NETWORK_STATE_REQ);
    case SBP_MSG_NETWORK_STATE_RESP:
      return sbp_pack_sbp_msg_network_state_resp_t(buf, len, &msg->MSG_NETWORK_STATE_RESP);
    case SBP_MSG_NETWORK_BANDWIDTH_USAGE:
      return sbp_pack_sbp_msg_network_bandwidth_usage_t(buf, len, &msg->MSG_NETWORK_BANDWIDTH_USAGE);
    case SBP_MSG_CELL_MODEM_STATUS:
      return sbp_pack_sbp_msg_cell_modem_status_t(buf, len, &msg->MSG_CELL_MODEM_STATUS);
    case SBP_MSG_SPECAN_DEP:
      return sbp_pack_sbp_msg_specan_dep_t(buf, len, &msg->MSG_SPECAN_DEP);
    case SBP_MSG_SPECAN:
      return sbp_pack_sbp_msg_specan_t(buf, len, &msg->MSG_SPECAN);
    case SBP_MSG_FRONT_END_GAIN:
      return sbp_pack_sbp_msg_front_end_gain_t(buf, len, &msg->MSG_FRONT_END_GAIN);
    case SBP_MSG_MAG_RAW:
      return sbp_pack_sbp_msg_mag_raw_t(buf, len, &msg->MSG_MAG_RAW);
    case SBP_MSG_GPS_TIME:
      return sbp_pack_sbp_msg_gps_time_t(buf, len, &msg->MSG_GPS_TIME);
    case SBP_MSG_GPS_TIME_GNSS:
      return sbp_pack_sbp_msg_gps_time_gnss_t(buf, len, &msg->MSG_GPS_TIME_GNSS);
    case SBP_MSG_UTC_TIME:
      return sbp_pack_sbp_msg_utc_time_t(buf, len, &msg->MSG_UTC_TIME);
    case SBP_MSG_UTC_TIME_GNSS:
      return sbp_pack_sbp_msg_utc_time_gnss_t(buf, len, &msg->MSG_UTC_TIME_GNSS);
    case SBP_MSG_DOPS:
      return sbp_pack_sbp_msg_dops_t(buf, len, &msg->MSG_DOPS);
    case SBP_MSG_POS_ECEF:
      return sbp_pack_sbp_msg_pos_ecef_t(buf, len, &msg->MSG_POS_ECEF);
    case SBP_MSG_POS_ECEF_COV:
      return sbp_pack_sbp_msg_pos_ecef_cov_t(buf, len, &msg->MSG_POS_ECEF_COV);
    case SBP_MSG_POS_LLH:
      return sbp_pack_sbp_msg_pos_llh_t(buf, len, &msg->MSG_POS_LLH);
    case SBP_MSG_POS_LLH_COV:
      return sbp_pack_sbp_msg_pos_llh_cov_t(buf, len, &msg->MSG_POS_LLH_COV);
    case SBP_MSG_BASELINE_ECEF:
      return sbp_pack_sbp_msg_baseline_ecef_t(buf, len, &msg->MSG_BASELINE_ECEF);
    case SBP_MSG_BASELINE_NED:
      return sbp_pack_sbp_msg_baseline_ned_t(buf, len, &msg->MSG_BASELINE_NED);
    case SBP_MSG_VEL_ECEF:
      return sbp_pack_sbp_msg_vel_ecef_t(buf, len, &msg->MSG_VEL_ECEF);
    case SBP_MSG_VEL_ECEF_COV:
      return sbp_pack_sbp_msg_vel_ecef_cov_t(buf, len, &msg->MSG_VEL_ECEF_COV);
    case SBP_MSG_VEL_NED:
      return sbp_pack_sbp_msg_vel_ned_t(buf, len, &msg->MSG_VEL_NED);
    case SBP_MSG_VEL_NED_COV:
      return sbp_pack_sbp_msg_vel_ned_cov_t(buf, len, &msg->MSG_VEL_NED_COV);
    case SBP_MSG_POS_ECEF_GNSS:
      return sbp_pack_sbp_msg_pos_ecef_gnss_t(buf, len, &msg->MSG_POS_ECEF_GNSS);
    case SBP_MSG_POS_ECEF_COV_GNSS:
      return sbp_pack_sbp_msg_pos_ecef_cov_gnss_t(buf, len, &msg->MSG_POS_ECEF_COV_GNSS);
    case SBP_MSG_POS_LLH_GNSS:
      return sbp_pack_sbp_msg_pos_llh_gnss_t(buf, len, &msg->MSG_POS_LLH_GNSS);
    case SBP_MSG_POS_LLH_COV_GNSS:
      return sbp_pack_sbp_msg_pos_llh_cov_gnss_t(buf, len, &msg->MSG_POS_LLH_COV_GNSS);
    case SBP_MSG_VEL_ECEF_GNSS:
      return sbp_pack_sbp_msg_vel_ecef_gnss_t(buf, len, &msg->MSG_VEL_ECEF_GNSS);
    case SBP_MSG_VEL_ECEF_COV_GNSS:
      return sbp_pack_sbp_msg_vel_ecef_cov_gnss_t(buf, len, &msg->MSG_VEL_ECEF_COV_GNSS);
    case SBP_MSG_VEL_NED_GNSS:
      return sbp_pack_sbp_msg_vel_ned_gnss_t(buf, len, &msg->MSG_VEL_NED_GNSS);
    case SBP_MSG_VEL_NED_COV_GNSS:
      return sbp_pack_sbp_msg_vel_ned_cov_gnss_t(buf, len, &msg->MSG_VEL_NED_COV_GNSS);
    case SBP_MSG_VEL_BODY:
      return sbp_pack_sbp_msg_vel_body_t(buf, len, &msg->MSG_VEL_BODY);
    case SBP_MSG_AGE_CORRECTIONS:
      return sbp_pack_sbp_msg_age_corrections_t(buf, len, &msg->MSG_AGE_CORRECTIONS);
    case SBP_MSG_GPS_TIME_DEP_A:
      return sbp_pack_sbp_msg_gps_time_dep_a_t(buf, len, &msg->MSG_GPS_TIME_DEP_A);
    case SBP_MSG_DOPS_DEP_A:
      return sbp_pack_sbp_msg_dops_dep_a_t(buf, len, &msg->MSG_DOPS_DEP_A);
    case SBP_MSG_POS_ECEF_DEP_A:
      return sbp_pack_sbp_msg_pos_ecef_dep_a_t(buf, len, &msg->MSG_POS_ECEF_DEP_A);
    case SBP_MSG_POS_LLH_DEP_A:
      return sbp_pack_sbp_msg_pos_llh_dep_a_t(buf, len, &msg->MSG_POS_LLH_DEP_A);
    case SBP_MSG_BASELINE_ECEF_DEP_A:
      return sbp_pack_sbp_msg_baseline_ecef_dep_a_t(buf, len, &msg->MSG_BASELINE_ECEF_DEP_A);
    case SBP_MSG_BASELINE_NED_DEP_A:
      return sbp_pack_sbp_msg_baseline_ned_dep_a_t(buf, len, &msg->MSG_BASELINE_NED_DEP_A);
    case SBP_MSG_VEL_ECEF_DEP_A:
      return sbp_pack_sbp_msg_vel_ecef_dep_a_t(buf, len, &msg->MSG_VEL_ECEF_DEP_A);
    case SBP_MSG_VEL_NED_DEP_A:
      return sbp_pack_sbp_msg_vel_ned_dep_a_t(buf, len, &msg->MSG_VEL_NED_DEP_A);
    case SBP_MSG_BASELINE_HEADING_DEP_A:
      return sbp_pack_sbp_msg_baseline_heading_dep_a_t(buf, len, &msg->MSG_BASELINE_HEADING_DEP_A);
    case SBP_MSG_PROTECTION_LEVEL:
      return sbp_pack_sbp_msg_protection_level_t(buf, len, &msg->MSG_PROTECTION_LEVEL);
    case SBP_MSG_NDB_EVENT:
      return sbp_pack_sbp_msg_ndb_event_t(buf, len, &msg->MSG_NDB_EVENT);
    case SBP_MSG_LINUX_CPU_STATE_DEP_A:
      return sbp_pack_sbp_msg_linux_cpu_state_dep_a_t(buf, len, &msg->MSG_LINUX_CPU_STATE_DEP_A);
    case SBP_MSG_LINUX_MEM_STATE_DEP_A:
      return sbp_pack_sbp_msg_linux_mem_state_dep_a_t(buf, len, &msg->MSG_LINUX_MEM_STATE_DEP_A);
    case SBP_MSG_LINUX_SYS_STATE_DEP_A:
      return sbp_pack_sbp_msg_linux_sys_state_dep_a_t(buf, len, &msg->MSG_LINUX_SYS_STATE_DEP_A);
    case SBP_MSG_LINUX_PROCESS_SOCKET_COUNTS:
      return sbp_pack_sbp_msg_linux_process_socket_counts_t(buf, len, &msg->MSG_LINUX_PROCESS_SOCKET_COUNTS);
    case SBP_MSG_LINUX_PROCESS_SOCKET_QUEUES:
      return sbp_pack_sbp_msg_linux_process_socket_queues_t(buf, len, &msg->MSG_LINUX_PROCESS_SOCKET_QUEUES);
    case SBP_MSG_LINUX_SOCKET_USAGE:
      return sbp_pack_sbp_msg_linux_socket_usage_t(buf, len, &msg->MSG_LINUX_SOCKET_USAGE);
    case SBP_MSG_LINUX_PROCESS_FD_COUNT:
      return sbp_pack_sbp_msg_linux_process_fd_count_t(buf, len, &msg->MSG_LINUX_PROCESS_FD_COUNT);
    case SBP_MSG_LINUX_PROCESS_FD_SUMMARY:
      return sbp_pack_sbp_msg_linux_process_fd_summary_t(buf, len, &msg->MSG_LINUX_PROCESS_FD_SUMMARY);
    case SBP_MSG_LINUX_CPU_STATE:
      return sbp_pack_sbp_msg_linux_cpu_state_t(buf, len, &msg->MSG_LINUX_CPU_STATE);
    case SBP_MSG_LINUX_MEM_STATE:
      return sbp_pack_sbp_msg_linux_mem_state_t(buf, len, &msg->MSG_LINUX_MEM_STATE);
    case SBP_MSG_LINUX_SYS_STATE:
      return sbp_pack_sbp_msg_linux_sys_state_t(buf, len, &msg->MSG_LINUX_SYS_STATE);
    case SBP_MSG_LOG:
      return sbp_pack_sbp_msg_log_t(buf, len, &msg->MSG_LOG);
    case SBP_MSG_FWD:
      return sbp_pack_sbp_msg_fwd_t(buf, len, &msg->MSG_FWD);
    case SBP_MSG_PRINT_DEP:
      return sbp_pack_sbp_msg_print_dep_t(buf, len, &msg->MSG_PRINT_DEP);
    case SBP_MSG_OBS:
      return sbp_pack_sbp_msg_obs_t(buf, len, &msg->MSG_OBS);
    case SBP_MSG_BASE_POS_LLH:
      return sbp_pack_sbp_msg_base_pos_llh_t(buf, len, &msg->MSG_BASE_POS_LLH);
    case SBP_MSG_BASE_POS_ECEF:
      return sbp_pack_sbp_msg_base_pos_ecef_t(buf, len, &msg->MSG_BASE_POS_ECEF);
    case SBP_MSG_EPHEMERIS_GPS_DEP_E:
      return sbp_pack_sbp_msg_ephemeris_gps_dep_e_t(buf, len, &msg->MSG_EPHEMERIS_GPS_DEP_E);
    case SBP_MSG_EPHEMERIS_GPS_DEP_F:
      return sbp_pack_sbp_msg_ephemeris_gps_dep_f_t(buf, len, &msg->MSG_EPHEMERIS_GPS_DEP_F);
    case SBP_MSG_EPHEMERIS_GPS:
      return sbp_pack_sbp_msg_ephemeris_gps_t(buf, len, &msg->MSG_EPHEMERIS_GPS);
    case SBP_MSG_EPHEMERIS_QZSS:
      return sbp_pack_sbp_msg_ephemeris_qzss_t(buf, len, &msg->MSG_EPHEMERIS_QZSS);
    case SBP_MSG_EPHEMERIS_BDS:
      return sbp_pack_sbp_msg_ephemeris_bds_t(buf, len, &msg->MSG_EPHEMERIS_BDS);
    case SBP_MSG_EPHEMERIS_GAL_DEP_A:
      return sbp_pack_sbp_msg_ephemeris_gal_dep_a_t(buf, len, &msg->MSG_EPHEMERIS_GAL_DEP_A);
    case SBP_MSG_EPHEMERIS_GAL:
      return sbp_pack_sbp_msg_ephemeris_gal_t(buf, len, &msg->MSG_EPHEMERIS_GAL);
    case SBP_MSG_EPHEMERIS_SBAS_DEP_A:
      return sbp_pack_sbp_msg_ephemeris_sbas_dep_a_t(buf, len, &msg->MSG_EPHEMERIS_SBAS_DEP_A);
    case SBP_MSG_EPHEMERIS_GLO_DEP_A:
      return sbp_pack_sbp_msg_ephemeris_glo_dep_a_t(buf, len, &msg->MSG_EPHEMERIS_GLO_DEP_A);
    case SBP_MSG_EPHEMERIS_SBAS_DEP_B:
      return sbp_pack_sbp_msg_ephemeris_sbas_dep_b_t(buf, len, &msg->MSG_EPHEMERIS_SBAS_DEP_B);
    case SBP_MSG_EPHEMERIS_SBAS:
      return sbp_pack_sbp_msg_ephemeris_sbas_t(buf, len, &msg->MSG_EPHEMERIS_SBAS);
    case SBP_MSG_EPHEMERIS_GLO_DEP_B:
      return sbp_pack_sbp_msg_ephemeris_glo_dep_b_t(buf, len, &msg->MSG_EPHEMERIS_GLO_DEP_B);
    case SBP_MSG_EPHEMERIS_GLO_DEP_C:
      return sbp_pack_sbp_msg_ephemeris_glo_dep_c_t(buf, len, &msg->MSG_EPHEMERIS_GLO_DEP_C);
    case SBP_MSG_EPHEMERIS_GLO_DEP_D:
      return sbp_pack_sbp_msg_ephemeris_glo_dep_d_t(buf, len, &msg->MSG_EPHEMERIS_GLO_DEP_D);
    case SBP_MSG_EPHEMERIS_GLO:
      return sbp_pack_sbp_msg_ephemeris_glo_t(buf, len, &msg->MSG_EPHEMERIS_GLO);
    case SBP_MSG_EPHEMERIS_DEP_D:
      return sbp_pack_sbp_msg_ephemeris_dep_d_t(buf, len, &msg->MSG_EPHEMERIS_DEP_D);
    case SBP_MSG_EPHEMERIS_DEP_A:
      return sbp_pack_sbp_msg_ephemeris_dep_a_t(buf, len, &msg->MSG_EPHEMERIS_DEP_A);
    case SBP_MSG_EPHEMERIS_DEP_B:
      return sbp_pack_sbp_msg_ephemeris_dep_b_t(buf, len, &msg->MSG_EPHEMERIS_DEP_B);
    case SBP_MSG_EPHEMERIS_DEP_C:
      return sbp_pack_sbp_msg_ephemeris_dep_c_t(buf, len, &msg->MSG_EPHEMERIS_DEP_C);
    case SBP_MSG_OBS_DEP_A:
      return sbp_pack_sbp_msg_obs_dep_a_t(buf, len, &msg->MSG_OBS_DEP_A);
    case SBP_MSG_OBS_DEP_B:
      return sbp_pack_sbp_msg_obs_dep_b_t(buf, len, &msg->MSG_OBS_DEP_B);
    case SBP_MSG_OBS_DEP_C:
      return sbp_pack_sbp_msg_obs_dep_c_t(buf, len, &msg->MSG_OBS_DEP_C);
    case SBP_MSG_IONO:
      return sbp_pack_sbp_msg_iono_t(buf, len, &msg->MSG_IONO);
    case SBP_MSG_SV_CONFIGURATION_GPS_DEP:
      return sbp_pack_sbp_msg_sv_configuration_gps_dep_t(buf, len, &msg->MSG_SV_CONFIGURATION_GPS_DEP);
    case SBP_MSG_GNSS_CAPB:
      return sbp_pack_sbp_msg_gnss_capb_t(buf, len, &msg->MSG_GNSS_CAPB);
    case SBP_MSG_GROUP_DELAY_DEP_A:
      return sbp_pack_sbp_msg_group_delay_dep_a_t(buf, len, &msg->MSG_GROUP_DELAY_DEP_A);
    case SBP_MSG_GROUP_DELAY_DEP_B:
      return sbp_pack_sbp_msg_group_delay_dep_b_t(buf, len, &msg->MSG_GROUP_DELAY_DEP_B);
    case SBP_MSG_GROUP_DELAY:
      return sbp_pack_sbp_msg_group_delay_t(buf, len, &msg->MSG_GROUP_DELAY);
    case SBP_MSG_ALMANAC_GPS_DEP:
      return sbp_pack_sbp_msg_almanac_gps_dep_t(buf, len, &msg->MSG_ALMANAC_GPS_DEP);
    case SBP_MSG_ALMANAC_GPS:
      return sbp_pack_sbp_msg_almanac_gps_t(buf, len, &msg->MSG_ALMANAC_GPS);
    case SBP_MSG_ALMANAC_GLO_DEP:
      return sbp_pack_sbp_msg_almanac_glo_dep_t(buf, len, &msg->MSG_ALMANAC_GLO_DEP);
    case SBP_MSG_ALMANAC_GLO:
      return sbp_pack_sbp_msg_almanac_glo_t(buf, len, &msg->MSG_ALMANAC_GLO);
    case SBP_MSG_GLO_BIASES:
      return sbp_pack_sbp_msg_glo_biases_t(buf, len, &msg->MSG_GLO_BIASES);
    case SBP_MSG_SV_AZ_EL:
      return sbp_pack_sbp_msg_sv_az_el_t(buf, len, &msg->MSG_SV_AZ_EL);
    case SBP_MSG_OSR:
      return sbp_pack_sbp_msg_osr_t(buf, len, &msg->MSG_OSR);
    case SBP_MSG_ACQ_RESULT:
      return sbp_pack_sbp_msg_acq_result_t(buf, len, &msg->MSG_ACQ_RESULT);
    case SBP_MSG_ACQ_RESULT_DEP_C:
      return sbp_pack_sbp_msg_acq_result_dep_c_t(buf, len, &msg->MSG_ACQ_RESULT_DEP_C);
    case SBP_MSG_ACQ_RESULT_DEP_B:
      return sbp_pack_sbp_msg_acq_result_dep_b_t(buf, len, &msg->MSG_ACQ_RESULT_DEP_B);
    case SBP_MSG_ACQ_RESULT_DEP_A:
      return sbp_pack_sbp_msg_acq_result_dep_a_t(buf, len, &msg->MSG_ACQ_RESULT_DEP_A);
    case SBP_MSG_ACQ_SV_PROFILE:
      return sbp_pack_sbp_msg_acq_sv_profile_t(buf, len, &msg->MSG_ACQ_SV_PROFILE);
    case SBP_MSG_ACQ_SV_PROFILE_DEP:
      return sbp_pack_sbp_msg_acq_sv_profile_dep_t(buf, len, &msg->MSG_ACQ_SV_PROFILE_DEP);
    case SBP_MSG_SSR_ORBIT_CLOCK:
      return sbp_pack_sbp_msg_ssr_orbit_clock_t(buf, len, &msg->MSG_SSR_ORBIT_CLOCK);
    case SBP_MSG_SSR_CODE_BIASES:
      return sbp_pack_sbp_msg_ssr_code_biases_t(buf, len, &msg->MSG_SSR_CODE_BIASES);
    case SBP_MSG_SSR_PHASE_BIASES:
      return sbp_pack_sbp_msg_ssr_phase_biases_t(buf, len, &msg->MSG_SSR_PHASE_BIASES);
    case SBP_MSG_SSR_STEC_CORRECTION:
      return sbp_pack_sbp_msg_ssr_stec_correction_t(buf, len, &msg->MSG_SSR_STEC_CORRECTION);
    case SBP_MSG_SSR_GRIDDED_CORRECTION:
      return sbp_pack_sbp_msg_ssr_gridded_correction_t(buf, len, &msg->MSG_SSR_GRIDDED_CORRECTION);
    case SBP_MSG_SSR_TILE_DEFINITION:
      return sbp_pack_sbp_msg_ssr_tile_definition_t(buf, len, &msg->MSG_SSR_TILE_DEFINITION);
    case SBP_MSG_SSR_SATELLITE_APC:
      return sbp_pack_sbp_msg_ssr_satellite_apc_t(buf, len, &msg->MSG_SSR_SATELLITE_APC);
    case SBP_MSG_SSR_ORBIT_CLOCK_DEP_A:
      return sbp_pack_sbp_msg_ssr_orbit_clock_dep_a_t(buf, len, &msg->MSG_SSR_ORBIT_CLOCK_DEP_A);
    case SBP_MSG_SSR_STEC_CORRECTION_DEP_A:
      return sbp_pack_sbp_msg_ssr_stec_correction_dep_a_t(buf, len, &msg->MSG_SSR_STEC_CORRECTION_DEP_A);
    case SBP_MSG_SSR_GRIDDED_CORRECTION_NO_STD_DEP_A:
      return sbp_pack_sbp_msg_ssr_gridded_correction_no_std_dep_a_t(
          buf, len, &msg->MSG_SSR_GRIDDED_CORRECTION_NO_STD_DEP_A);
    case SBP_MSG_SSR_GRIDDED_CORRECTION_DEP_A:
      return sbp_pack_sbp_msg_ssr_gridded_correction_dep_a_t(buf, len, &msg->MSG_SSR_GRIDDED_CORRECTION_DEP_A);
    case SBP_MSG_SSR_GRID_DEFINITION_DEP_A:
      return sbp_pack_sbp_msg_ssr_grid_definition_dep_a_t(buf, len, &msg->MSG_SSR_GRID_DEFINITION_DEP_A);
    case SBP_MSG_BOOTLOADER_HANDSHAKE_REQ:
      return sbp_pack_sbp_msg_bootloader_handshake_req_t(buf, len, &msg->MSG_BOOTLOADER_HANDSHAKE_REQ);
    case SBP_MSG_BOOTLOADER_HANDSHAKE_RESP:
      return sbp_pack_sbp_msg_bootloader_handshake_resp_t(buf, len, &msg->MSG_BOOTLOADER_HANDSHAKE_RESP);
    case SBP_MSG_BOOTLOADER_JUMP_TO_APP:
      return sbp_pack_sbp_msg_bootloader_jump_to_app_t(buf, len, &msg->MSG_BOOTLOADER_JUMP_TO_APP);
    case SBP_MSG_NAP_DEVICE_DNA_REQ:
      return sbp_pack_sbp_msg_nap_device_dna_req_t(buf, len, &msg->MSG_NAP_DEVICE_DNA_REQ);
    case SBP_MSG_NAP_DEVICE_DNA_RESP:
      return sbp_pack_sbp_msg_nap_device_dna_resp_t(buf, len, &msg->MSG_NAP_DEVICE_DNA_RESP);
    case SBP_MSG_BOOTLOADER_HANDSHAKE_DEP_A:
      return sbp_pack_sbp_msg_bootloader_handshake_dep_a_t(buf, len, &msg->MSG_BOOTLOADER_HANDSHAKE_DEP_A);
    case SBP_MSG_USER_DATA:
      return sbp_pack_sbp_msg_user_data_t(buf, len, &msg->MSG_USER_DATA);
    case SBP_MSG_SETTINGS_SAVE:
      return sbp_pack_sbp_msg_settings_save_t(buf, len, &msg->MSG_SETTINGS_SAVE);
    case SBP_MSG_SETTINGS_WRITE:
      return sbp_pack_sbp_msg_settings_write_t(buf, len, &msg->MSG_SETTINGS_WRITE);
    case SBP_MSG_SETTINGS_WRITE_RESP:
      return sbp_pack_sbp_msg_settings_write_resp_t(buf, len, &msg->MSG_SETTINGS_WRITE_RESP);
    case SBP_MSG_SETTINGS_READ_REQ:
      return sbp_pack_sbp_msg_settings_read_req_t(buf, len, &msg->MSG_SETTINGS_READ_REQ);
    case SBP_MSG_SETTINGS_READ_RESP:
      return sbp_pack_sbp_msg_settings_read_resp_t(buf, len, &msg->MSG_SETTINGS_READ_RESP);
    case SBP_MSG_SETTINGS_READ_BY_INDEX_REQ:
      return sbp_pack_sbp_msg_settings_read_by_index_req_t(buf, len, &msg->MSG_SETTINGS_READ_BY_INDEX_REQ);
    case SBP_MSG_SETTINGS_READ_BY_INDEX_RESP:
      return sbp_pack_sbp_msg_settings_read_by_index_resp_t(buf, len, &msg->MSG_SETTINGS_READ_BY_INDEX_RESP);
    case SBP_MSG_SETTINGS_READ_BY_INDEX_DONE:
      return sbp_pack_sbp_msg_settings_read_by_index_done_t(buf, len, &msg->MSG_SETTINGS_READ_BY_INDEX_DONE);
    case SBP_MSG_SETTINGS_REGISTER:
      return sbp_pack_sbp_msg_settings_register_t(buf, len, &msg->MSG_SETTINGS_REGISTER);
    case SBP_MSG_SETTINGS_REGISTER_RESP:
      return sbp_pack_sbp_msg_settings_register_resp_t(buf, len, &msg->MSG_SETTINGS_REGISTER_RESP);
    case SBP_MSG_IMU_RAW:
      return sbp_pack_sbp_msg_imu_raw_t(buf, len, &msg->MSG_IMU_RAW);
    case SBP_MSG_IMU_AUX:
      return sbp_pack_sbp_msg_imu_aux_t(buf, len, &msg->MSG_IMU_AUX);
    case SBP_MSG_FILEIO_READ_REQ:
      return sbp_pack_sbp_msg_fileio_read_req_t(buf, len, &msg->MSG_FILEIO_READ_REQ);
    case SBP_MSG_FILEIO_READ_RESP:
      return sbp_pack_sbp_msg_fileio_read_resp_t(buf, len, &msg->MSG_FILEIO_READ_RESP);
    case SBP_MSG_FILEIO_READ_DIR_REQ:
      return sbp_pack_sbp_msg_fileio_read_dir_req_t(buf, len, &msg->MSG_FILEIO_READ_DIR_REQ);
    case SBP_MSG_FILEIO_READ_DIR_RESP:
      return sbp_pack_sbp_msg_fileio_read_dir_resp_t(buf, len, &msg->MSG_FILEIO_READ_DIR_RESP);
    case SBP_MSG_FILEIO_REMOVE:
      return sbp_pack_sbp_msg_fileio_remove_t(buf, len, &msg->MSG_FILEIO_REMOVE);
    case SBP_MSG_FILEIO_WRITE_REQ:
      return sbp_pack_sbp_msg_fileio_write_req_t(buf, len, &msg->MSG_FILEIO_WRITE_REQ);
    case SBP_MSG_FILEIO_WRITE_RESP:
      return sbp_pack_sbp_msg_fileio_write_resp_t(buf, len, &msg->MSG_FILEIO_WRITE_RESP);
    case SBP_MSG_FILEIO_CONFIG_REQ:
      return sbp_pack_sbp_msg_fileio_config_req_t(buf, len, &msg->MSG_FILEIO_CONFIG_REQ);
    case SBP_MSG_FILEIO_CONFIG_RESP:
      return sbp_pack_sbp_msg_fileio_config_resp_t(buf, len, &msg->MSG_FILEIO_CONFIG_RESP);
    case SBP_MSG_ODOMETRY:
      return sbp_pack_sbp_msg_odometry_t(buf, len, &msg->MSG_ODOMETRY);
    case SBP_MSG_WHEELTICK:
      return sbp_pack_sbp_msg_wheeltick_t(buf, len, &msg->MSG_WHEELTICK);
    case SBP_MSG_SOLN_META_DEP_A:
      return sbp_pack_sbp_msg_soln_meta_dep_a_t(buf, len, &msg->MSG_SOLN_META_DEP_A);
    case SBP_MSG_SOLN_META:
      return sbp_pack_sbp_msg_soln_meta_t(buf, len, &msg->MSG_SOLN_META);
    case SBP_MSG_FLASH_PROGRAM:
      return sbp_pack_sbp_msg_flash_program_t(buf, len, &msg->MSG_FLASH_PROGRAM);
    case SBP_MSG_FLASH_DONE:
      return sbp_pack_sbp_msg_flash_done_t(buf, len, &msg->MSG_FLASH_DONE);
    case SBP_MSG_FLASH_READ_REQ:
      return sbp_pack_sbp_msg_flash_read_req_t(buf, len, &msg->MSG_FLASH_READ_REQ);
    case SBP_MSG_FLASH_READ_RESP:
      return sbp_pack_sbp_msg_flash_read_resp_t(buf, len, &msg->MSG_FLASH_READ_RESP);
    case SBP_MSG_FLASH_ERASE:
      return sbp_pack_sbp_msg_flash_erase_t(buf, len, &msg->MSG_FLASH_ERASE);
    case SBP_MSG_STM_FLASH_LOCK_SECTOR:
      return sbp_pack_sbp_msg_stm_flash_lock_sector_t(buf, len, &msg->MSG_STM_FLASH_LOCK_SECTOR);
    case SBP_MSG_STM_FLASH_UNLOCK_SECTOR:
      return sbp_pack_sbp_msg_stm_flash_unlock_sector_t(buf, len, &msg->MSG_STM_FLASH_UNLOCK_SECTOR);
    case SBP_MSG_STM_UNIQUE_ID_REQ:
      return sbp_pack_sbp_msg_stm_unique_id_req_t(buf, len, &msg->MSG_STM_UNIQUE_ID_REQ);
    case SBP_MSG_STM_UNIQUE_ID_RESP:
      return sbp_pack_sbp_msg_stm_unique_id_resp_t(buf, len, &msg->MSG_STM_UNIQUE_ID_RESP);
    case SBP_MSG_M25_FLASH_WRITE_STATUS:
      return sbp_pack_sbp_msg_m25_flash_write_status_t(buf, len, &msg->MSG_M25_FLASH_WRITE_STATUS);
    case SBP_MSG_TRACKING_STATE_DETAILED_DEP_A:
      return sbp_pack_sbp_msg_tracking_state_detailed_dep_a_t(buf, len, &msg->MSG_TRACKING_STATE_DETAILED_DEP_A);
    case SBP_MSG_TRACKING_STATE_DETAILED_DEP:
      return sbp_pack_sbp_msg_tracking_state_detailed_dep_t(buf, len, &msg->MSG_TRACKING_STATE_DETAILED_DEP);
    case SBP_MSG_TRACKING_STATE:
      return sbp_pack_sbp_msg_tracking_state_t(buf, len, &msg->MSG_TRACKING_STATE);
    case SBP_MSG_MEASUREMENT_STATE:
      return sbp_pack_sbp_msg_measurement_state_t(buf, len, &msg->MSG_MEASUREMENT_STATE);
    case SBP_MSG_TRACKING_IQ:
      return sbp_pack_sbp_msg_tracking_iq_t(buf, len, &msg->MSG_TRACKING_IQ);
    case SBP_MSG_TRACKING_IQ_DEP_B:
      return sbp_pack_sbp_msg_tracking_iq_dep_b_t(buf, len, &msg->MSG_TRACKING_IQ_DEP_B);
    case SBP_MSG_TRACKING_IQ_DEP_A:
      return sbp_pack_sbp_msg_tracking_iq_dep_a_t(buf, len, &msg->MSG_TRACKING_IQ_DEP_A);
    case SBP_MSG_TRACKING_STATE_DEP_A:
      return sbp_pack_sbp_msg_tracking_state_dep_a_t(buf, len, &msg->MSG_TRACKING_STATE_DEP_A);
    case SBP_MSG_TRACKING_STATE_DEP_B:
      return sbp_pack_sbp_msg_tracking_state_dep_b_t(buf, len, &msg->MSG_TRACKING_STATE_DEP_B);
    case SBP_MSG_EXT_EVENT:
      return sbp_pack_sbp_msg_ext_event_t(buf, len, &msg->MSG_EXT_EVENT);
    case SBP_MSG_STARTUP:
      return sbp_pack_sbp_msg_startup_t(buf, len, &msg->MSG_STARTUP);
    case SBP_MSG_DGNSS_STATUS:
      return sbp_pack_sbp_msg_dgnss_status_t(buf, len, &msg->MSG_DGNSS_STATUS);
    case SBP_MSG_HEARTBEAT:
      return sbp_pack_sbp_msg_heartbeat_t(buf, len, &msg->MSG_HEARTBEAT);
    case SBP_MSG_STATUS_REPORT:
      return sbp_pack_sbp_msg_status_report_t(buf, len, &msg->MSG_STATUS_REPORT);
    case SBP_MSG_INS_STATUS:
      return sbp_pack_sbp_msg_ins_status_t(buf, len, &msg->MSG_INS_STATUS);
    case SBP_MSG_CSAC_TELEMETRY:
      return sbp_pack_sbp_msg_csac_telemetry_t(buf, len, &msg->MSG_CSAC_TELEMETRY);
    case SBP_MSG_CSAC_TELEMETRY_LABELS:
      return sbp_pack_sbp_msg_csac_telemetry_labels_t(buf, len, &msg->MSG_CSAC_TELEMETRY_LABELS);
    case SBP_MSG_INS_UPDATES:
      return sbp_pack_sbp_msg_ins_updates_t(buf, len, &msg->MSG_INS_UPDATES);
    case SBP_MSG_GNSS_TIME_OFFSET:
      return sbp_pack_sbp_msg_gnss_time_offset_t(buf, len, &msg->MSG_GNSS_TIME_OFFSET);
    case SBP_MSG_GROUP_META:
      return sbp_pack_sbp_msg_group_meta_t(buf, len, &msg->MSG_GROUP_META);
    default:
      break;
  }
  return false;
}

static inline bool sbp_unpack_msg(const uint8_t *buf, size_t len, sbp_msg_t *msg)
{
  switch (msg->type)
  {
    case SBP_MSG_SBAS_RAW:
      return sbp_unpack_sbp_msg_sbas_raw_t(buf, len, &msg->MSG_SBAS_RAW);
    case SBP_MSG_BASELINE_HEADING:
      return sbp_unpack_sbp_msg_baseline_heading_t(buf, len, &msg->MSG_BASELINE_HEADING);
    case SBP_MSG_ORIENT_QUAT:
      return sbp_unpack_sbp_msg_orient_quat_t(buf, len, &msg->MSG_ORIENT_QUAT);
    case SBP_MSG_ORIENT_EULER:
      return sbp_unpack_sbp_msg_orient_euler_t(buf, len, &msg->MSG_ORIENT_EULER);
    case SBP_MSG_ANGULAR_RATE:
      return sbp_unpack_sbp_msg_angular_rate_t(buf, len, &msg->MSG_ANGULAR_RATE);
    case SBP_MSG_ALMANAC:
      return sbp_unpack_sbp_msg_almanac_t(buf, len, &msg->MSG_ALMANAC);
    case SBP_MSG_SET_TIME:
      return sbp_unpack_sbp_msg_set_time_t(buf, len, &msg->MSG_SET_TIME);
    case SBP_MSG_RESET:
      return sbp_unpack_sbp_msg_reset_t(buf, len, &msg->MSG_RESET);
    case SBP_MSG_RESET_DEP:
      return sbp_unpack_sbp_msg_reset_dep_t(buf, len, &msg->MSG_RESET_DEP);
    case SBP_MSG_CW_RESULTS:
      return sbp_unpack_sbp_msg_cw_results_t(buf, len, &msg->MSG_CW_RESULTS);
    case SBP_MSG_CW_START:
      return sbp_unpack_sbp_msg_cw_start_t(buf, len, &msg->MSG_CW_START);
    case SBP_MSG_RESET_FILTERS:
      return sbp_unpack_sbp_msg_reset_filters_t(buf, len, &msg->MSG_RESET_FILTERS);
    case SBP_MSG_INIT_BASE_DEP:
      return sbp_unpack_sbp_msg_init_base_dep_t(buf, len, &msg->MSG_INIT_BASE_DEP);
    case SBP_MSG_THREAD_STATE:
      return sbp_unpack_sbp_msg_thread_state_t(buf, len, &msg->MSG_THREAD_STATE);
    case SBP_MSG_UART_STATE:
      return sbp_unpack_sbp_msg_uart_state_t(buf, len, &msg->MSG_UART_STATE);
    case SBP_MSG_UART_STATE_DEPA:
      return sbp_unpack_sbp_msg_uart_state_depa_t(buf, len, &msg->MSG_UART_STATE_DEPA);
    case SBP_MSG_IAR_STATE:
      return sbp_unpack_sbp_msg_iar_state_t(buf, len, &msg->MSG_IAR_STATE);
    case SBP_MSG_MASK_SATELLITE:
      return sbp_unpack_sbp_msg_mask_satellite_t(buf, len, &msg->MSG_MASK_SATELLITE);
    case SBP_MSG_MASK_SATELLITE_DEP:
      return sbp_unpack_sbp_msg_mask_satellite_dep_t(buf, len, &msg->MSG_MASK_SATELLITE_DEP);
    case SBP_MSG_DEVICE_MONITOR:
      return sbp_unpack_sbp_msg_device_monitor_t(buf, len, &msg->MSG_DEVICE_MONITOR);
    case SBP_MSG_COMMAND_REQ:
      return sbp_unpack_sbp_msg_command_req_t(buf, len, &msg->MSG_COMMAND_REQ);
    case SBP_MSG_COMMAND_RESP:
      return sbp_unpack_sbp_msg_command_resp_t(buf, len, &msg->MSG_COMMAND_RESP);
    case SBP_MSG_COMMAND_OUTPUT:
      return sbp_unpack_sbp_msg_command_output_t(buf, len, &msg->MSG_COMMAND_OUTPUT);
    case SBP_MSG_NETWORK_STATE_REQ:
      return sbp_unpack_sbp_msg_network_state_req_t(buf, len, &msg->MSG_NETWORK_STATE_REQ);
    case SBP_MSG_NETWORK_STATE_RESP:
      return sbp_unpack_sbp_msg_network_state_resp_t(buf, len, &msg->MSG_NETWORK_STATE_RESP);
    case SBP_MSG_NETWORK_BANDWIDTH_USAGE:
      return sbp_unpack_sbp_msg_network_bandwidth_usage_t(buf, len, &msg->MSG_NETWORK_BANDWIDTH_USAGE);
    case SBP_MSG_CELL_MODEM_STATUS:
      return sbp_unpack_sbp_msg_cell_modem_status_t(buf, len, &msg->MSG_CELL_MODEM_STATUS);
    case SBP_MSG_SPECAN_DEP:
      return sbp_unpack_sbp_msg_specan_dep_t(buf, len, &msg->MSG_SPECAN_DEP);
    case SBP_MSG_SPECAN:
      return sbp_unpack_sbp_msg_specan_t(buf, len, &msg->MSG_SPECAN);
    case SBP_MSG_FRONT_END_GAIN:
      return sbp_unpack_sbp_msg_front_end_gain_t(buf, len, &msg->MSG_FRONT_END_GAIN);
    case SBP_MSG_MAG_RAW:
      return sbp_unpack_sbp_msg_mag_raw_t(buf, len, &msg->MSG_MAG_RAW);
    case SBP_MSG_GPS_TIME:
      return sbp_unpack_sbp_msg_gps_time_t(buf, len, &msg->MSG_GPS_TIME);
    case SBP_MSG_GPS_TIME_GNSS:
      return sbp_unpack_sbp_msg_gps_time_gnss_t(buf, len, &msg->MSG_GPS_TIME_GNSS);
    case SBP_MSG_UTC_TIME:
      return sbp_unpack_sbp_msg_utc_time_t(buf, len, &msg->MSG_UTC_TIME);
    case SBP_MSG_UTC_TIME_GNSS:
      return sbp_unpack_sbp_msg_utc_time_gnss_t(buf, len, &msg->MSG_UTC_TIME_GNSS);
    case SBP_MSG_DOPS:
      return sbp_unpack_sbp_msg_dops_t(buf, len, &msg->MSG_DOPS);
    case SBP_MSG_POS_ECEF:
      return sbp_unpack_sbp_msg_pos_ecef_t(buf, len, &msg->MSG_POS_ECEF);
    case SBP_MSG_POS_ECEF_COV:
      return sbp_unpack_sbp_msg_pos_ecef_cov_t(buf, len, &msg->MSG_POS_ECEF_COV);
    case SBP_MSG_POS_LLH:
      return sbp_unpack_sbp_msg_pos_llh_t(buf, len, &msg->MSG_POS_LLH);
    case SBP_MSG_POS_LLH_COV:
      return sbp_unpack_sbp_msg_pos_llh_cov_t(buf, len, &msg->MSG_POS_LLH_COV);
    case SBP_MSG_BASELINE_ECEF:
      return sbp_unpack_sbp_msg_baseline_ecef_t(buf, len, &msg->MSG_BASELINE_ECEF);
    case SBP_MSG_BASELINE_NED:
      return sbp_unpack_sbp_msg_baseline_ned_t(buf, len, &msg->MSG_BASELINE_NED);
    case SBP_MSG_VEL_ECEF:
      return sbp_unpack_sbp_msg_vel_ecef_t(buf, len, &msg->MSG_VEL_ECEF);
    case SBP_MSG_VEL_ECEF_COV:
      return sbp_unpack_sbp_msg_vel_ecef_cov_t(buf, len, &msg->MSG_VEL_ECEF_COV);
    case SBP_MSG_VEL_NED:
      return sbp_unpack_sbp_msg_vel_ned_t(buf, len, &msg->MSG_VEL_NED);
    case SBP_MSG_VEL_NED_COV:
      return sbp_unpack_sbp_msg_vel_ned_cov_t(buf, len, &msg->MSG_VEL_NED_COV);
    case SBP_MSG_POS_ECEF_GNSS:
      return sbp_unpack_sbp_msg_pos_ecef_gnss_t(buf, len, &msg->MSG_POS_ECEF_GNSS);
    case SBP_MSG_POS_ECEF_COV_GNSS:
      return sbp_unpack_sbp_msg_pos_ecef_cov_gnss_t(buf, len, &msg->MSG_POS_ECEF_COV_GNSS);
    case SBP_MSG_POS_LLH_GNSS:
      return sbp_unpack_sbp_msg_pos_llh_gnss_t(buf, len, &msg->MSG_POS_LLH_GNSS);
    case SBP_MSG_POS_LLH_COV_GNSS:
      return sbp_unpack_sbp_msg_pos_llh_cov_gnss_t(buf, len, &msg->MSG_POS_LLH_COV_GNSS);
    case SBP_MSG_VEL_ECEF_GNSS:
      return sbp_unpack_sbp_msg_vel_ecef_gnss_t(buf, len, &msg->MSG_VEL_ECEF_GNSS);
    case SBP_MSG_VEL_ECEF_COV_GNSS:
      return sbp_unpack_sbp_msg_vel_ecef_cov_gnss_t(buf, len, &msg->MSG_VEL_ECEF_COV_GNSS);
    case SBP_MSG_VEL_NED_GNSS:
      return sbp_unpack_sbp_msg_vel_ned_gnss_t(buf, len, &msg->MSG_VEL_NED_GNSS);
    case SBP_MSG_VEL_NED_COV_GNSS:
      return sbp_unpack_sbp_msg_vel_ned_cov_gnss_t(buf, len, &msg->MSG_VEL_NED_COV_GNSS);
    case SBP_MSG_VEL_BODY:
      return sbp_unpack_sbp_msg_vel_body_t(buf, len, &msg->MSG_VEL_BODY);
    case SBP_MSG_AGE_CORRECTIONS:
      return sbp_unpack_sbp_msg_age_corrections_t(buf, len, &msg->MSG_AGE_CORRECTIONS);
    case SBP_MSG_GPS_TIME_DEP_A:
      return sbp_unpack_sbp_msg_gps_time_dep_a_t(buf, len, &msg->MSG_GPS_TIME_DEP_A);
    case SBP_MSG_DOPS_DEP_A:
      return sbp_unpack_sbp_msg_dops_dep_a_t(buf, len, &msg->MSG_DOPS_DEP_A);
    case SBP_MSG_POS_ECEF_DEP_A:
      return sbp_unpack_sbp_msg_pos_ecef_dep_a_t(buf, len, &msg->MSG_POS_ECEF_DEP_A);
    case SBP_MSG_POS_LLH_DEP_A:
      return sbp_unpack_sbp_msg_pos_llh_dep_a_t(buf, len, &msg->MSG_POS_LLH_DEP_A);
    case SBP_MSG_BASELINE_ECEF_DEP_A:
      return sbp_unpack_sbp_msg_baseline_ecef_dep_a_t(buf, len, &msg->MSG_BASELINE_ECEF_DEP_A);
    case SBP_MSG_BASELINE_NED_DEP_A:
      return sbp_unpack_sbp_msg_baseline_ned_dep_a_t(buf, len, &msg->MSG_BASELINE_NED_DEP_A);
    case SBP_MSG_VEL_ECEF_DEP_A:
      return sbp_unpack_sbp_msg_vel_ecef_dep_a_t(buf, len, &msg->MSG_VEL_ECEF_DEP_A);
    case SBP_MSG_VEL_NED_DEP_A:
      return sbp_unpack_sbp_msg_vel_ned_dep_a_t(buf, len, &msg->MSG_VEL_NED_DEP_A);
    case SBP_MSG_BASELINE_HEADING_DEP_A:
      return sbp_unpack_sbp_msg_baseline_heading_dep_a_t(buf, len, &msg->MSG_BASELINE_HEADING_DEP_A);
    case SBP_MSG_PROTECTION_LEVEL:
      return sbp_unpack_sbp_msg_protection_level_t(buf, len, &msg->MSG_PROTECTION_LEVEL);
    case SBP_MSG_NDB_EVENT:
      return sbp_unpack_sbp_msg_ndb_event_t(buf, len, &msg->MSG_NDB_EVENT);
    case SBP_MSG_LINUX_CPU_STATE_DEP_A:
      return sbp_unpack_sbp_msg_linux_cpu_state_dep_a_t(buf, len, &msg->MSG_LINUX_CPU_STATE_DEP_A);
    case SBP_MSG_LINUX_MEM_STATE_DEP_A:
      return sbp_unpack_sbp_msg_linux_mem_state_dep_a_t(buf, len, &msg->MSG_LINUX_MEM_STATE_DEP_A);
    case SBP_MSG_LINUX_SYS_STATE_DEP_A:
      return sbp_unpack_sbp_msg_linux_sys_state_dep_a_t(buf, len, &msg->MSG_LINUX_SYS_STATE_DEP_A);
    case SBP_MSG_LINUX_PROCESS_SOCKET_COUNTS:
      return sbp_unpack_sbp_msg_linux_process_socket_counts_t(buf, len, &msg->MSG_LINUX_PROCESS_SOCKET_COUNTS);
    case SBP_MSG_LINUX_PROCESS_SOCKET_QUEUES:
      return sbp_unpack_sbp_msg_linux_process_socket_queues_t(buf, len, &msg->MSG_LINUX_PROCESS_SOCKET_QUEUES);
    case SBP_MSG_LINUX_SOCKET_USAGE:
      return sbp_unpack_sbp_msg_linux_socket_usage_t(buf, len, &msg->MSG_LINUX_SOCKET_USAGE);
    case SBP_MSG_LINUX_PROCESS_FD_COUNT:
      return sbp_unpack_sbp_msg_linux_process_fd_count_t(buf, len, &msg->MSG_LINUX_PROCESS_FD_COUNT);
    case SBP_MSG_LINUX_PROCESS_FD_SUMMARY:
      return sbp_unpack_sbp_msg_linux_process_fd_summary_t(buf, len, &msg->MSG_LINUX_PROCESS_FD_SUMMARY);
    case SBP_MSG_LINUX_CPU_STATE:
      return sbp_unpack_sbp_msg_linux_cpu_state_t(buf, len, &msg->MSG_LINUX_CPU_STATE);
    case SBP_MSG_LINUX_MEM_STATE:
      return sbp_unpack_sbp_msg_linux_mem_state_t(buf, len, &msg->MSG_LINUX_MEM_STATE);
    case SBP_MSG_LINUX_SYS_STATE:
      return sbp_unpack_sbp_msg_linux_sys_state_t(buf, len, &msg->MSG_LINUX_SYS_STATE);
    case SBP_MSG_LOG:
      return sbp_unpack_sbp_msg_log_t(buf, len, &msg->MSG_LOG);
    case SBP_MSG_FWD:
      return sbp_unpack_sbp_msg_fwd_t(buf, len, &msg->MSG_FWD);
    case SBP_MSG_PRINT_DEP:
      return sbp_unpack_sbp_msg_print_dep_t(buf, len, &msg->MSG_PRINT_DEP);
    case SBP_MSG_OBS:
      return sbp_unpack_sbp_msg_obs_t(buf, len, &msg->MSG_OBS);
    case SBP_MSG_BASE_POS_LLH:
      return sbp_unpack_sbp_msg_base_pos_llh_t(buf, len, &msg->MSG_BASE_POS_LLH);
    case SBP_MSG_BASE_POS_ECEF:
      return sbp_unpack_sbp_msg_base_pos_ecef_t(buf, len, &msg->MSG_BASE_POS_ECEF);
    case SBP_MSG_EPHEMERIS_GPS_DEP_E:
      return sbp_unpack_sbp_msg_ephemeris_gps_dep_e_t(buf, len, &msg->MSG_EPHEMERIS_GPS_DEP_E);
    case SBP_MSG_EPHEMERIS_GPS_DEP_F:
      return sbp_unpack_sbp_msg_ephemeris_gps_dep_f_t(buf, len, &msg->MSG_EPHEMERIS_GPS_DEP_F);
    case SBP_MSG_EPHEMERIS_GPS:
      return sbp_unpack_sbp_msg_ephemeris_gps_t(buf, len, &msg->MSG_EPHEMERIS_GPS);
    case SBP_MSG_EPHEMERIS_QZSS:
      return sbp_unpack_sbp_msg_ephemeris_qzss_t(buf, len, &msg->MSG_EPHEMERIS_QZSS);
    case SBP_MSG_EPHEMERIS_BDS:
      return sbp_unpack_sbp_msg_ephemeris_bds_t(buf, len, &msg->MSG_EPHEMERIS_BDS);
    case SBP_MSG_EPHEMERIS_GAL_DEP_A:
      return sbp_unpack_sbp_msg_ephemeris_gal_dep_a_t(buf, len, &msg->MSG_EPHEMERIS_GAL_DEP_A);
    case SBP_MSG_EPHEMERIS_GAL:
      return sbp_unpack_sbp_msg_ephemeris_gal_t(buf, len, &msg->MSG_EPHEMERIS_GAL);
    case SBP_MSG_EPHEMERIS_SBAS_DEP_A:
      return sbp_unpack_sbp_msg_ephemeris_sbas_dep_a_t(buf, len, &msg->MSG_EPHEMERIS_SBAS_DEP_A);
    case SBP_MSG_EPHEMERIS_GLO_DEP_A:
      return sbp_unpack_sbp_msg_ephemeris_glo_dep_a_t(buf, len, &msg->MSG_EPHEMERIS_GLO_DEP_A);
    case SBP_MSG_EPHEMERIS_SBAS_DEP_B:
      return sbp_unpack_sbp_msg_ephemeris_sbas_dep_b_t(buf, len, &msg->MSG_EPHEMERIS_SBAS_DEP_B);
    case SBP_MSG_EPHEMERIS_SBAS:
      return sbp_unpack_sbp_msg_ephemeris_sbas_t(buf, len, &msg->MSG_EPHEMERIS_SBAS);
    case SBP_MSG_EPHEMERIS_GLO_DEP_B:
      return sbp_unpack_sbp_msg_ephemeris_glo_dep_b_t(buf, len, &msg->MSG_EPHEMERIS_GLO_DEP_B);
    case SBP_MSG_EPHEMERIS_GLO_DEP_C:
      return sbp_unpack_sbp_msg_ephemeris_glo_dep_c_t(buf, len, &msg->MSG_EPHEMERIS_GLO_DEP_C);
    case SBP_MSG_EPHEMERIS_GLO_DEP_D:
      return sbp_unpack_sbp_msg_ephemeris_glo_dep_d_t(buf, len, &msg->MSG_EPHEMERIS_GLO_DEP_D);
    case SBP_MSG_EPHEMERIS_GLO:
      return sbp_unpack_sbp_msg_ephemeris_glo_t(buf, len, &msg->MSG_EPHEMERIS_GLO);
    case SBP_MSG_EPHEMERIS_DEP_D:
      return sbp_unpack_sbp_msg_ephemeris_dep_d_t(buf, len, &msg->MSG_EPHEMERIS_DEP_D);
    case SBP_MSG_EPHEMERIS_DEP_A:
      return sbp_unpack_sbp_msg_ephemeris_dep_a_t(buf, len, &msg->MSG_EPHEMERIS_DEP_A);
    case SBP_MSG_EPHEMERIS_DEP_B:
      return sbp_unpack_sbp_msg_ephemeris_dep_b_t(buf, len, &msg->MSG_EPHEMERIS_DEP_B);
    case SBP_MSG_EPHEMERIS_DEP_C:
      return sbp_unpack_sbp_msg_ephemeris_dep_c_t(buf, len, &msg->MSG_EPHEMERIS_DEP_C);
    case SBP_MSG_OBS_DEP_A:
      return sbp_unpack_sbp_msg_obs_dep_a_t(buf, len, &msg->MSG_OBS_DEP_A);
    case SBP_MSG_OBS_DEP_B:
      return sbp_unpack_sbp_msg_obs_dep_b_t(buf, len, &msg->MSG_OBS_DEP_B);
    case SBP_MSG_OBS_DEP_C:
      return sbp_unpack_sbp_msg_obs_dep_c_t(buf, len, &msg->MSG_OBS_DEP_C);
    case SBP_MSG_IONO:
      return sbp_unpack_sbp_msg_iono_t(buf, len, &msg->MSG_IONO);
    case SBP_MSG_SV_CONFIGURATION_GPS_DEP:
      return sbp_unpack_sbp_msg_sv_configuration_gps_dep_t(buf, len, &msg->MSG_SV_CONFIGURATION_GPS_DEP);
    case SBP_MSG_GNSS_CAPB:
      return sbp_unpack_sbp_msg_gnss_capb_t(buf, len, &msg->MSG_GNSS_CAPB);
    case SBP_MSG_GROUP_DELAY_DEP_A:
      return sbp_unpack_sbp_msg_group_delay_dep_a_t(buf, len, &msg->MSG_GROUP_DELAY_DEP_A);
    case SBP_MSG_GROUP_DELAY_DEP_B:
      return sbp_unpack_sbp_msg_group_delay_dep_b_t(buf, len, &msg->MSG_GROUP_DELAY_DEP_B);
    case SBP_MSG_GROUP_DELAY:
      return sbp_unpack_sbp_msg_group_delay_t(buf, len, &msg->MSG_GROUP_DELAY);
    case SBP_MSG_ALMANAC_GPS_DEP:
      return sbp_unpack_sbp_msg_almanac_gps_dep_t(buf, len, &msg->MSG_ALMANAC_GPS_DEP);
    case SBP_MSG_ALMANAC_GPS:
      return sbp_unpack_sbp_msg_almanac_gps_t(buf, len, &msg->MSG_ALMANAC_GPS);
    case SBP_MSG_ALMANAC_GLO_DEP:
      return sbp_unpack_sbp_msg_almanac_glo_dep_t(buf, len, &msg->MSG_ALMANAC_GLO_DEP);
    case SBP_MSG_ALMANAC_GLO:
      return sbp_unpack_sbp_msg_almanac_glo_t(buf, len, &msg->MSG_ALMANAC_GLO);
    case SBP_MSG_GLO_BIASES:
      return sbp_unpack_sbp_msg_glo_biases_t(buf, len, &msg->MSG_GLO_BIASES);
    case SBP_MSG_SV_AZ_EL:
      return sbp_unpack_sbp_msg_sv_az_el_t(buf, len, &msg->MSG_SV_AZ_EL);
    case SBP_MSG_OSR:
      return sbp_unpack_sbp_msg_osr_t(buf, len, &msg->MSG_OSR);
    case SBP_MSG_ACQ_RESULT:
      return sbp_unpack_sbp_msg_acq_result_t(buf, len, &msg->MSG_ACQ_RESULT);
    case SBP_MSG_ACQ_RESULT_DEP_C:
      return sbp_unpack_sbp_msg_acq_result_dep_c_t(buf, len, &msg->MSG_ACQ_RESULT_DEP_C);
    case SBP_MSG_ACQ_RESULT_DEP_B:
      return sbp_unpack_sbp_msg_acq_result_dep_b_t(buf, len, &msg->MSG_ACQ_RESULT_DEP_B);
    case SBP_MSG_ACQ_RESULT_DEP_A:
      return sbp_unpack_sbp_msg_acq_result_dep_a_t(buf, len, &msg->MSG_ACQ_RESULT_DEP_A);
    case SBP_MSG_ACQ_SV_PROFILE:
      return sbp_unpack_sbp_msg_acq_sv_profile_t(buf, len, &msg->MSG_ACQ_SV_PROFILE);
    case SBP_MSG_ACQ_SV_PROFILE_DEP:
      return sbp_unpack_sbp_msg_acq_sv_profile_dep_t(buf, len, &msg->MSG_ACQ_SV_PROFILE_DEP);
    case SBP_MSG_SSR_ORBIT_CLOCK:
      return sbp_unpack_sbp_msg_ssr_orbit_clock_t(buf, len, &msg->MSG_SSR_ORBIT_CLOCK);
    case SBP_MSG_SSR_CODE_BIASES:
      return sbp_unpack_sbp_msg_ssr_code_biases_t(buf, len, &msg->MSG_SSR_CODE_BIASES);
    case SBP_MSG_SSR_PHASE_BIASES:
      return sbp_unpack_sbp_msg_ssr_phase_biases_t(buf, len, &msg->MSG_SSR_PHASE_BIASES);
    case SBP_MSG_SSR_STEC_CORRECTION:
      return sbp_unpack_sbp_msg_ssr_stec_correction_t(buf, len, &msg->MSG_SSR_STEC_CORRECTION);
    case SBP_MSG_SSR_GRIDDED_CORRECTION:
      return sbp_unpack_sbp_msg_ssr_gridded_correction_t(buf, len, &msg->MSG_SSR_GRIDDED_CORRECTION);
    case SBP_MSG_SSR_TILE_DEFINITION:
      return sbp_unpack_sbp_msg_ssr_tile_definition_t(buf, len, &msg->MSG_SSR_TILE_DEFINITION);
    case SBP_MSG_SSR_SATELLITE_APC:
      return sbp_unpack_sbp_msg_ssr_satellite_apc_t(buf, len, &msg->MSG_SSR_SATELLITE_APC);
    case SBP_MSG_SSR_ORBIT_CLOCK_DEP_A:
      return sbp_unpack_sbp_msg_ssr_orbit_clock_dep_a_t(buf, len, &msg->MSG_SSR_ORBIT_CLOCK_DEP_A);
    case SBP_MSG_SSR_STEC_CORRECTION_DEP_A:
      return sbp_unpack_sbp_msg_ssr_stec_correction_dep_a_t(buf, len, &msg->MSG_SSR_STEC_CORRECTION_DEP_A);
    case SBP_MSG_SSR_GRIDDED_CORRECTION_NO_STD_DEP_A:
      return sbp_unpack_sbp_msg_ssr_gridded_correction_no_std_dep_a_t(
          buf, len, &msg->MSG_SSR_GRIDDED_CORRECTION_NO_STD_DEP_A);
    case SBP_MSG_SSR_GRIDDED_CORRECTION_DEP_A:
      return sbp_unpack_sbp_msg_ssr_gridded_correction_dep_a_t(buf, len, &msg->MSG_SSR_GRIDDED_CORRECTION_DEP_A);
    case SBP_MSG_SSR_GRID_DEFINITION_DEP_A:
      return sbp_unpack_sbp_msg_ssr_grid_definition_dep_a_t(buf, len, &msg->MSG_SSR_GRID_DEFINITION_DEP_A);
    case SBP_MSG_BOOTLOADER_HANDSHAKE_REQ:
      return sbp_unpack_sbp_msg_bootloader_handshake_req_t(buf, len, &msg->MSG_BOOTLOADER_HANDSHAKE_REQ);
    case SBP_MSG_BOOTLOADER_HANDSHAKE_RESP:
      return sbp_unpack_sbp_msg_bootloader_handshake_resp_t(buf, len, &msg->MSG_BOOTLOADER_HANDSHAKE_RESP);
    case SBP_MSG_BOOTLOADER_JUMP_TO_APP:
      return sbp_unpack_sbp_msg_bootloader_jump_to_app_t(buf, len, &msg->MSG_BOOTLOADER_JUMP_TO_APP);
    case SBP_MSG_NAP_DEVICE_DNA_REQ:
      return sbp_unpack_sbp_msg_nap_device_dna_req_t(buf, len, &msg->MSG_NAP_DEVICE_DNA_REQ);
    case SBP_MSG_NAP_DEVICE_DNA_RESP:
      return sbp_unpack_sbp_msg_nap_device_dna_resp_t(buf, len, &msg->MSG_NAP_DEVICE_DNA_RESP);
    case SBP_MSG_BOOTLOADER_HANDSHAKE_DEP_A:
      return sbp_unpack_sbp_msg_bootloader_handshake_dep_a_t(buf, len, &msg->MSG_BOOTLOADER_HANDSHAKE_DEP_A);
    case SBP_MSG_USER_DATA:
      return sbp_unpack_sbp_msg_user_data_t(buf, len, &msg->MSG_USER_DATA);
    case SBP_MSG_SETTINGS_SAVE:
      return sbp_unpack_sbp_msg_settings_save_t(buf, len, &msg->MSG_SETTINGS_SAVE);
    case SBP_MSG_SETTINGS_WRITE:
      return sbp_unpack_sbp_msg_settings_write_t(buf, len, &msg->MSG_SETTINGS_WRITE);
    case SBP_MSG_SETTINGS_WRITE_RESP:
      return sbp_unpack_sbp_msg_settings_write_resp_t(buf, len, &msg->MSG_SETTINGS_WRITE_RESP);
    case SBP_MSG_SETTINGS_READ_REQ:
      return sbp_unpack_sbp_msg_settings_read_req_t(buf, len, &msg->MSG_SETTINGS_READ_REQ);
    case SBP_MSG_SETTINGS_READ_RESP:
      return sbp_unpack_sbp_msg_settings_read_resp_t(buf, len, &msg->MSG_SETTINGS_READ_RESP);
    case SBP_MSG_SETTINGS_READ_BY_INDEX_REQ:
      return sbp_unpack_sbp_msg_settings_read_by_index_req_t(buf, len, &msg->MSG_SETTINGS_READ_BY_INDEX_REQ);
    case SBP_MSG_SETTINGS_READ_BY_INDEX_RESP:
      return sbp_unpack_sbp_msg_settings_read_by_index_resp_t(buf, len, &msg->MSG_SETTINGS_READ_BY_INDEX_RESP);
    case SBP_MSG_SETTINGS_READ_BY_INDEX_DONE:
      return sbp_unpack_sbp_msg_settings_read_by_index_done_t(buf, len, &msg->MSG_SETTINGS_READ_BY_INDEX_DONE);
    case SBP_MSG_SETTINGS_REGISTER:
      return sbp_unpack_sbp_msg_settings_register_t(buf, len, &msg->MSG_SETTINGS_REGISTER);
    case SBP_MSG_SETTINGS_REGISTER_RESP:
      return sbp_unpack_sbp_msg_settings_register_resp_t(buf, len, &msg->MSG_SETTINGS_REGISTER_RESP);
    case SBP_MSG_IMU_RAW:
      return sbp_unpack_sbp_msg_imu_raw_t(buf, len, &msg->MSG_IMU_RAW);
    case SBP_MSG_IMU_AUX:
      return sbp_unpack_sbp_msg_imu_aux_t(buf, len, &msg->MSG_IMU_AUX);
    case SBP_MSG_FILEIO_READ_REQ:
      return sbp_unpack_sbp_msg_fileio_read_req_t(buf, len, &msg->MSG_FILEIO_READ_REQ);
    case SBP_MSG_FILEIO_READ_RESP:
      return sbp_unpack_sbp_msg_fileio_read_resp_t(buf, len, &msg->MSG_FILEIO_READ_RESP);
    case SBP_MSG_FILEIO_READ_DIR_REQ:
      return sbp_unpack_sbp_msg_fileio_read_dir_req_t(buf, len, &msg->MSG_FILEIO_READ_DIR_REQ);
    case SBP_MSG_FILEIO_READ_DIR_RESP:
      return sbp_unpack_sbp_msg_fileio_read_dir_resp_t(buf, len, &msg->MSG_FILEIO_READ_DIR_RESP);
    case SBP_MSG_FILEIO_REMOVE:
      return sbp_unpack_sbp_msg_fileio_remove_t(buf, len, &msg->MSG_FILEIO_REMOVE);
    case SBP_MSG_FILEIO_WRITE_REQ:
      return sbp_unpack_sbp_msg_fileio_write_req_t(buf, len, &msg->MSG_FILEIO_WRITE_REQ);
    case SBP_MSG_FILEIO_WRITE_RESP:
      return sbp_unpack_sbp_msg_fileio_write_resp_t(buf, len, &msg->MSG_FILEIO_WRITE_RESP);
    case SBP_MSG_FILEIO_CONFIG_REQ:
      return sbp_unpack_sbp_msg_fileio_config_req_t(buf, len, &msg->MSG_FILEIO_CONFIG_REQ);
    case SBP_MSG_FILEIO_CONFIG_RESP:
      return sbp_unpack_sbp_msg_fileio_config_resp_t(buf, len, &msg->MSG_FILEIO_CONFIG_RESP);
    case SBP_MSG_ODOMETRY:
      return sbp_unpack_sbp_msg_odometry_t(buf, len, &msg->MSG_ODOMETRY);
    case SBP_MSG_WHEELTICK:
      return sbp_unpack_sbp_msg_wheeltick_t(buf, len, &msg->MSG_WHEELTICK);
    case SBP_MSG_SOLN_META_DEP_A:
      return sbp_unpack_sbp_msg_soln_meta_dep_a_t(buf, len, &msg->MSG_SOLN_META_DEP_A);
    case SBP_MSG_SOLN_META:
      return sbp_unpack_sbp_msg_soln_meta_t(buf, len, &msg->MSG_SOLN_META);
    case SBP_MSG_FLASH_PROGRAM:
      return sbp_unpack_sbp_msg_flash_program_t(buf, len, &msg->MSG_FLASH_PROGRAM);
    case SBP_MSG_FLASH_DONE:
      return sbp_unpack_sbp_msg_flash_done_t(buf, len, &msg->MSG_FLASH_DONE);
    case SBP_MSG_FLASH_READ_REQ:
      return sbp_unpack_sbp_msg_flash_read_req_t(buf, len, &msg->MSG_FLASH_READ_REQ);
    case SBP_MSG_FLASH_READ_RESP:
      return sbp_unpack_sbp_msg_flash_read_resp_t(buf, len, &msg->MSG_FLASH_READ_RESP);
    case SBP_MSG_FLASH_ERASE:
      return sbp_unpack_sbp_msg_flash_erase_t(buf, len, &msg->MSG_FLASH_ERASE);
    case SBP_MSG_STM_FLASH_LOCK_SECTOR:
      return sbp_unpack_sbp_msg_stm_flash_lock_sector_t(buf, len, &msg->MSG_STM_FLASH_LOCK_SECTOR);
    case SBP_MSG_STM_FLASH_UNLOCK_SECTOR:
      return sbp_unpack_sbp_msg_stm_flash_unlock_sector_t(buf, len, &msg->MSG_STM_FLASH_UNLOCK_SECTOR);
    case SBP_MSG_STM_UNIQUE_ID_REQ:
      return sbp_unpack_sbp_msg_stm_unique_id_req_t(buf, len, &msg->MSG_STM_UNIQUE_ID_REQ);
    case SBP_MSG_STM_UNIQUE_ID_RESP:
      return sbp_unpack_sbp_msg_stm_unique_id_resp_t(buf, len, &msg->MSG_STM_UNIQUE_ID_RESP);
    case SBP_MSG_M25_FLASH_WRITE_STATUS:
      return sbp_unpack_sbp_msg_m25_flash_write_status_t(buf, len, &msg->MSG_M25_FLASH_WRITE_STATUS);
    case SBP_MSG_TRACKING_STATE_DETAILED_DEP_A:
      return sbp_unpack_sbp_msg_tracking_state_detailed_dep_a_t(buf, len, &msg->MSG_TRACKING_STATE_DETAILED_DEP_A);
    case SBP_MSG_TRACKING_STATE_DETAILED_DEP:
      return sbp_unpack_sbp_msg_tracking_state_detailed_dep_t(buf, len, &msg->MSG_TRACKING_STATE_DETAILED_DEP);
    case SBP_MSG_TRACKING_STATE:
      return sbp_unpack_sbp_msg_tracking_state_t(buf, len, &msg->MSG_TRACKING_STATE);
    case SBP_MSG_MEASUREMENT_STATE:
      return sbp_unpack_sbp_msg_measurement_state_t(buf, len, &msg->MSG_MEASUREMENT_STATE);
    case SBP_MSG_TRACKING_IQ:
      return sbp_unpack_sbp_msg_tracking_iq_t(buf, len, &msg->MSG_TRACKING_IQ);
    case SBP_MSG_TRACKING_IQ_DEP_B:
      return sbp_unpack_sbp_msg_tracking_iq_dep_b_t(buf, len, &msg->MSG_TRACKING_IQ_DEP_B);
    case SBP_MSG_TRACKING_IQ_DEP_A:
      return sbp_unpack_sbp_msg_tracking_iq_dep_a_t(buf, len, &msg->MSG_TRACKING_IQ_DEP_A);
    case SBP_MSG_TRACKING_STATE_DEP_A:
      return sbp_unpack_sbp_msg_tracking_state_dep_a_t(buf, len, &msg->MSG_TRACKING_STATE_DEP_A);
    case SBP_MSG_TRACKING_STATE_DEP_B:
      return sbp_unpack_sbp_msg_tracking_state_dep_b_t(buf, len, &msg->MSG_TRACKING_STATE_DEP_B);
    case SBP_MSG_EXT_EVENT:
      return sbp_unpack_sbp_msg_ext_event_t(buf, len, &msg->MSG_EXT_EVENT);
    case SBP_MSG_STARTUP:
      return sbp_unpack_sbp_msg_startup_t(buf, len, &msg->MSG_STARTUP);
    case SBP_MSG_DGNSS_STATUS:
      return sbp_unpack_sbp_msg_dgnss_status_t(buf, len, &msg->MSG_DGNSS_STATUS);
    case SBP_MSG_HEARTBEAT:
      return sbp_unpack_sbp_msg_heartbeat_t(buf, len, &msg->MSG_HEARTBEAT);
    case SBP_MSG_STATUS_REPORT:
      return sbp_unpack_sbp_msg_status_report_t(buf, len, &msg->MSG_STATUS_REPORT);
    case SBP_MSG_INS_STATUS:
      return sbp_unpack_sbp_msg_ins_status_t(buf, len, &msg->MSG_INS_STATUS);
    case SBP_MSG_CSAC_TELEMETRY:
      return sbp_unpack_sbp_msg_csac_telemetry_t(buf, len, &msg->MSG_CSAC_TELEMETRY);
    case SBP_MSG_CSAC_TELEMETRY_LABELS:
      return sbp_unpack_sbp_msg_csac_telemetry_labels_t(buf, len, &msg->MSG_CSAC_TELEMETRY_LABELS);
    case SBP_MSG_INS_UPDATES:
      return sbp_unpack_sbp_msg_ins_updates_t(buf, len, &msg->MSG_INS_UPDATES);
    case SBP_MSG_GNSS_TIME_OFFSET:
      return sbp_unpack_sbp_msg_gnss_time_offset_t(buf, len, &msg->MSG_GNSS_TIME_OFFSET);
    case SBP_MSG_GROUP_META:
      return sbp_unpack_sbp_msg_group_meta_t(buf, len, &msg->MSG_GROUP_META);
    default:
      break;
  }
  return false;
}

static inline size_t sbp_packed_size(const sbp_msg_t *msg)
{
  switch (msg->type)
  {
    case SBP_MSG_SBAS_RAW:
      return sbp_packed_size_sbp_msg_sbas_raw_t(&msg->MSG_SBAS_RAW);
    case SBP_MSG_BASELINE_HEADING:
      return sbp_packed_size_sbp_msg_baseline_heading_t(&msg->MSG_BASELINE_HEADING);
    case SBP_MSG_ORIENT_QUAT:
      return sbp_packed_size_sbp_msg_orient_quat_t(&msg->MSG_ORIENT_QUAT);
    case SBP_MSG_ORIENT_EULER:
      return sbp_packed_size_sbp_msg_orient_euler_t(&msg->MSG_ORIENT_EULER);
    case SBP_MSG_ANGULAR_RATE:
      return sbp_packed_size_sbp_msg_angular_rate_t(&msg->MSG_ANGULAR_RATE);
    case SBP_MSG_ALMANAC:
      return sbp_packed_size_sbp_msg_almanac_t(&msg->MSG_ALMANAC);
    case SBP_MSG_SET_TIME:
      return sbp_packed_size_sbp_msg_set_time_t(&msg->MSG_SET_TIME);
    case SBP_MSG_RESET:
      return sbp_packed_size_sbp_msg_reset_t(&msg->MSG_RESET);
    case SBP_MSG_RESET_DEP:
      return sbp_packed_size_sbp_msg_reset_dep_t(&msg->MSG_RESET_DEP);
    case SBP_MSG_CW_RESULTS:
      return sbp_packed_size_sbp_msg_cw_results_t(&msg->MSG_CW_RESULTS);
    case SBP_MSG_CW_START:
      return sbp_packed_size_sbp_msg_cw_start_t(&msg->MSG_CW_START);
    case SBP_MSG_RESET_FILTERS:
      return sbp_packed_size_sbp_msg_reset_filters_t(&msg->MSG_RESET_FILTERS);
    case SBP_MSG_INIT_BASE_DEP:
      return sbp_packed_size_sbp_msg_init_base_dep_t(&msg->MSG_INIT_BASE_DEP);
    case SBP_MSG_THREAD_STATE:
      return sbp_packed_size_sbp_msg_thread_state_t(&msg->MSG_THREAD_STATE);
    case SBP_MSG_UART_STATE:
      return sbp_packed_size_sbp_msg_uart_state_t(&msg->MSG_UART_STATE);
    case SBP_MSG_UART_STATE_DEPA:
      return sbp_packed_size_sbp_msg_uart_state_depa_t(&msg->MSG_UART_STATE_DEPA);
    case SBP_MSG_IAR_STATE:
      return sbp_packed_size_sbp_msg_iar_state_t(&msg->MSG_IAR_STATE);
    case SBP_MSG_MASK_SATELLITE:
      return sbp_packed_size_sbp_msg_mask_satellite_t(&msg->MSG_MASK_SATELLITE);
    case SBP_MSG_MASK_SATELLITE_DEP:
      return sbp_packed_size_sbp_msg_mask_satellite_dep_t(&msg->MSG_MASK_SATELLITE_DEP);
    case SBP_MSG_DEVICE_MONITOR:
      return sbp_packed_size_sbp_msg_device_monitor_t(&msg->MSG_DEVICE_MONITOR);
    case SBP_MSG_COMMAND_REQ:
      return sbp_packed_size_sbp_msg_command_req_t(&msg->MSG_COMMAND_REQ);
    case SBP_MSG_COMMAND_RESP:
      return sbp_packed_size_sbp_msg_command_resp_t(&msg->MSG_COMMAND_RESP);
    case SBP_MSG_COMMAND_OUTPUT:
      return sbp_packed_size_sbp_msg_command_output_t(&msg->MSG_COMMAND_OUTPUT);
    case SBP_MSG_NETWORK_STATE_REQ:
      return sbp_packed_size_sbp_msg_network_state_req_t(&msg->MSG_NETWORK_STATE_REQ);
    case SBP_MSG_NETWORK_STATE_RESP:
      return sbp_packed_size_sbp_msg_network_state_resp_t(&msg->MSG_NETWORK_STATE_RESP);
    case SBP_MSG_NETWORK_BANDWIDTH_USAGE:
      return sbp_packed_size_sbp_msg_network_bandwidth_usage_t(&msg->MSG_NETWORK_BANDWIDTH_USAGE);
    case SBP_MSG_CELL_MODEM_STATUS:
      return sbp_packed_size_sbp_msg_cell_modem_status_t(&msg->MSG_CELL_MODEM_STATUS);
    case SBP_MSG_SPECAN_DEP:
      return sbp_packed_size_sbp_msg_specan_dep_t(&msg->MSG_SPECAN_DEP);
    case SBP_MSG_SPECAN:
      return sbp_packed_size_sbp_msg_specan_t(&msg->MSG_SPECAN);
    case SBP_MSG_FRONT_END_GAIN:
      return sbp_packed_size_sbp_msg_front_end_gain_t(&msg->MSG_FRONT_END_GAIN);
    case SBP_MSG_MAG_RAW:
      return sbp_packed_size_sbp_msg_mag_raw_t(&msg->MSG_MAG_RAW);
    case SBP_MSG_GPS_TIME:
      return sbp_packed_size_sbp_msg_gps_time_t(&msg->MSG_GPS_TIME);
    case SBP_MSG_GPS_TIME_GNSS:
      return sbp_packed_size_sbp_msg_gps_time_gnss_t(&msg->MSG_GPS_TIME_GNSS);
    case SBP_MSG_UTC_TIME:
      return sbp_packed_size_sbp_msg_utc_time_t(&msg->MSG_UTC_TIME);
    case SBP_MSG_UTC_TIME_GNSS:
      return sbp_packed_size_sbp_msg_utc_time_gnss_t(&msg->MSG_UTC_TIME_GNSS);
    case SBP_MSG_DOPS:
      return sbp_packed_size_sbp_msg_dops_t(&msg->MSG_DOPS);
    case SBP_MSG_POS_ECEF:
      return sbp_packed_size_sbp_msg_pos_ecef_t(&msg->MSG_POS_ECEF);
    case SBP_MSG_POS_ECEF_COV:
      return sbp_packed_size_sbp_msg_pos_ecef_cov_t(&msg->MSG_POS_ECEF_COV);
    case SBP_MSG_POS_LLH:
      return sbp_packed_size_sbp_msg_pos_llh_t(&msg->MSG_POS_LLH);
    case SBP_MSG_POS_LLH_COV:
      return sbp_packed_size_sbp_msg_pos_llh_cov_t(&msg->MSG_POS_LLH_COV);
    case SBP_MSG_BASELINE_ECEF:
      return sbp_packed_size_sbp_msg_baseline_ecef_t(&msg->MSG_BASELINE_ECEF);
    case SBP_MSG_BASELINE_NED:
      return sbp_packed_size_sbp_msg_baseline_ned_t(&msg->MSG_BASELINE_NED);
    case SBP_MSG_VEL_ECEF:
      return sbp_packed_size_sbp_msg_vel_ecef_t(&msg->MSG_VEL_ECEF);
    case SBP_MSG_VEL_ECEF_COV:
      return sbp_packed_size_sbp_msg_vel_ecef_cov_t(&msg->MSG_VEL_ECEF_COV);
    case SBP_MSG_VEL_NED:
      return sbp_packed_size_sbp_msg_vel_ned_t(&msg->MSG_VEL_NED);
    case SBP_MSG_VEL_NED_COV:
      return sbp_packed_size_sbp_msg_vel_ned_cov_t(&msg->MSG_VEL_NED_COV);
    case SBP_MSG_POS_ECEF_GNSS:
      return sbp_packed_size_sbp_msg_pos_ecef_gnss_t(&msg->MSG_POS_ECEF_GNSS);
    case SBP_MSG_POS_ECEF_COV_GNSS:
      return sbp_packed_size_sbp_msg_pos_ecef_cov_gnss_t(&msg->MSG_POS_ECEF_COV_GNSS);
    case SBP_MSG_POS_LLH_GNSS:
      return sbp_packed_size_sbp_msg_pos_llh_gnss_t(&msg->MSG_POS_LLH_GNSS);
    case SBP_MSG_POS_LLH_COV_GNSS:
      return sbp_packed_size_sbp_msg_pos_llh_cov_gnss_t(&msg->MSG_POS_LLH_COV_GNSS);
    case SBP_MSG_VEL_ECEF_GNSS:
      return sbp_packed_size_sbp_msg_vel_ecef_gnss_t(&msg->MSG_VEL_ECEF_GNSS);
    case SBP_MSG_VEL_ECEF_COV_GNSS:
      return sbp_packed_size_sbp_msg_vel_ecef_cov_gnss_t(&msg->MSG_VEL_ECEF_COV_GNSS);
    case SBP_MSG_VEL_NED_GNSS:
      return sbp_packed_size_sbp_msg_vel_ned_gnss_t(&msg->MSG_VEL_NED_GNSS);
    case SBP_MSG_VEL_NED_COV_GNSS:
      return sbp_packed_size_sbp_msg_vel_ned_cov_gnss_t(&msg->MSG_VEL_NED_COV_GNSS);
    case SBP_MSG_VEL_BODY:
      return sbp_packed_size_sbp_msg_vel_body_t(&msg->MSG_VEL_BODY);
    case SBP_MSG_AGE_CORRECTIONS:
      return sbp_packed_size_sbp_msg_age_corrections_t(&msg->MSG_AGE_CORRECTIONS);
    case SBP_MSG_GPS_TIME_DEP_A:
      return sbp_packed_size_sbp_msg_gps_time_dep_a_t(&msg->MSG_GPS_TIME_DEP_A);
    case SBP_MSG_DOPS_DEP_A:
      return sbp_packed_size_sbp_msg_dops_dep_a_t(&msg->MSG_DOPS_DEP_A);
    case SBP_MSG_POS_ECEF_DEP_A:
      return sbp_packed_size_sbp_msg_pos_ecef_dep_a_t(&msg->MSG_POS_ECEF_DEP_A);
    case SBP_MSG_POS_LLH_DEP_A:
      return sbp_packed_size_sbp_msg_pos_llh_dep_a_t(&msg->MSG_POS_LLH_DEP_A);
    case SBP_MSG_BASELINE_ECEF_DEP_A:
      return sbp_packed_size_sbp_msg_baseline_ecef_dep_a_t(&msg->MSG_BASELINE_ECEF_DEP_A);
    case SBP_MSG_BASELINE_NED_DEP_A:
      return sbp_packed_size_sbp_msg_baseline_ned_dep_a_t(&msg->MSG_BASELINE_NED_DEP_A);
    case SBP_MSG_VEL_ECEF_DEP_A:
      return sbp_packed_size_sbp_msg_vel_ecef_dep_a_t(&msg->MSG_VEL_ECEF_DEP_A);
    case SBP_MSG_VEL_NED_DEP_A:
      return sbp_packed_size_sbp_msg_vel_ned_dep_a_t(&msg->MSG_VEL_NED_DEP_A);
    case SBP_MSG_BASELINE_HEADING_DEP_A:
      return sbp_packed_size_sbp_msg_baseline_heading_dep_a_t(&msg->MSG_BASELINE_HEADING_DEP_A);
    case SBP_MSG_PROTECTION_LEVEL:
      return sbp_packed_size_sbp_msg_protection_level_t(&msg->MSG_PROTECTION_LEVEL);
    case SBP_MSG_NDB_EVENT:
      return sbp_packed_size_sbp_msg_ndb_event_t(&msg->MSG_NDB_EVENT);
    case SBP_MSG_LINUX_CPU_STATE_DEP_A:
      return sbp_packed_size_sbp_msg_linux_cpu_state_dep_a_t(&msg->MSG_LINUX_CPU_STATE_DEP_A);
    case SBP_MSG_LINUX_MEM_STATE_DEP_A:
      return sbp_packed_size_sbp_msg_linux_mem_state_dep_a_t(&msg->MSG_LINUX_MEM_STATE_DEP_A);
    case SBP_MSG_LINUX_SYS_STATE_DEP_A:
      return sbp_packed_size_sbp_msg_linux_sys_state_dep_a_t(&msg->MSG_LINUX_SYS_STATE_DEP_A);
    case SBP_MSG_LINUX_PROCESS_SOCKET_COUNTS:
      return sbp_packed_size_sbp_msg_linux_process_socket_counts_t(&msg->MSG_LINUX_PROCESS_SOCKET_COUNTS);
    case SBP_MSG_LINUX_PROCESS_SOCKET_QUEUES:
      return sbp_packed_size_sbp_msg_linux_process_socket_queues_t(&msg->MSG_LINUX_PROCESS_SOCKET_QUEUES);
    case SBP_MSG_LINUX_SOCKET_USAGE:
      return sbp_packed_size_sbp_msg_linux_socket_usage_t(&msg->MSG_LINUX_SOCKET_USAGE);
    case SBP_MSG_LINUX_PROCESS_FD_COUNT:
      return sbp_packed_size_sbp_msg_linux_process_fd_count_t(&msg->MSG_LINUX_PROCESS_FD_COUNT);
    case SBP_MSG_LINUX_PROCESS_FD_SUMMARY:
      return sbp_packed_size_sbp_msg_linux_process_fd_summary_t(&msg->MSG_LINUX_PROCESS_FD_SUMMARY);
    case SBP_MSG_LINUX_CPU_STATE:
      return sbp_packed_size_sbp_msg_linux_cpu_state_t(&msg->MSG_LINUX_CPU_STATE);
    case SBP_MSG_LINUX_MEM_STATE:
      return sbp_packed_size_sbp_msg_linux_mem_state_t(&msg->MSG_LINUX_MEM_STATE);
    case SBP_MSG_LINUX_SYS_STATE:
      return sbp_packed_size_sbp_msg_linux_sys_state_t(&msg->MSG_LINUX_SYS_STATE);
    case SBP_MSG_LOG:
      return sbp_packed_size_sbp_msg_log_t(&msg->MSG_LOG);
    case SBP_MSG_FWD:
      return sbp_packed_size_sbp_msg_fwd_t(&msg->MSG_FWD);
    case SBP_MSG_PRINT_DEP:
      return sbp_packed_size_sbp_msg_print_dep_t(&msg->MSG_PRINT_DEP);
    case SBP_MSG_OBS:
      return sbp_packed_size_sbp_msg_obs_t(&msg->MSG_OBS);
    case SBP_MSG_BASE_POS_LLH:
      return sbp_packed_size_sbp_msg_base_pos_llh_t(&msg->MSG_BASE_POS_LLH);
    case SBP_MSG_BASE_POS_ECEF:
      return sbp_packed_size_sbp_msg_base_pos_ecef_t(&msg->MSG_BASE_POS_ECEF);
    case SBP_MSG_EPHEMERIS_GPS_DEP_E:
      return sbp_packed_size_sbp_msg_ephemeris_gps_dep_e_t(&msg->MSG_EPHEMERIS_GPS_DEP_E);
    case SBP_MSG_EPHEMERIS_GPS_DEP_F:
      return sbp_packed_size_sbp_msg_ephemeris_gps_dep_f_t(&msg->MSG_EPHEMERIS_GPS_DEP_F);
    case SBP_MSG_EPHEMERIS_GPS:
      return sbp_packed_size_sbp_msg_ephemeris_gps_t(&msg->MSG_EPHEMERIS_GPS);
    case SBP_MSG_EPHEMERIS_QZSS:
      return sbp_packed_size_sbp_msg_ephemeris_qzss_t(&msg->MSG_EPHEMERIS_QZSS);
    case SBP_MSG_EPHEMERIS_BDS:
      return sbp_packed_size_sbp_msg_ephemeris_bds_t(&msg->MSG_EPHEMERIS_BDS);
    case SBP_MSG_EPHEMERIS_GAL_DEP_A:
      return sbp_packed_size_sbp_msg_ephemeris_gal_dep_a_t(&msg->MSG_EPHEMERIS_GAL_DEP_A);
    case SBP_MSG_EPHEMERIS_GAL:
      return sbp_packed_size_sbp_msg_ephemeris_gal_t(&msg->MSG_EPHEMERIS_GAL);
    case SBP_MSG_EPHEMERIS_SBAS_DEP_A:
      return sbp_packed_size_sbp_msg_ephemeris_sbas_dep_a_t(&msg->MSG_EPHEMERIS_SBAS_DEP_A);
    case SBP_MSG_EPHEMERIS_GLO_DEP_A:
      return sbp_packed_size_sbp_msg_ephemeris_glo_dep_a_t(&msg->MSG_EPHEMERIS_GLO_DEP_A);
    case SBP_MSG_EPHEMERIS_SBAS_DEP_B:
      return sbp_packed_size_sbp_msg_ephemeris_sbas_dep_b_t(&msg->MSG_EPHEMERIS_SBAS_DEP_B);
    case SBP_MSG_EPHEMERIS_SBAS:
      return sbp_packed_size_sbp_msg_ephemeris_sbas_t(&msg->MSG_EPHEMERIS_SBAS);
    case SBP_MSG_EPHEMERIS_GLO_DEP_B:
      return sbp_packed_size_sbp_msg_ephemeris_glo_dep_b_t(&msg->MSG_EPHEMERIS_GLO_DEP_B);
    case SBP_MSG_EPHEMERIS_GLO_DEP_C:
      return sbp_packed_size_sbp_msg_ephemeris_glo_dep_c_t(&msg->MSG_EPHEMERIS_GLO_DEP_C);
    case SBP_MSG_EPHEMERIS_GLO_DEP_D:
      return sbp_packed_size_sbp_msg_ephemeris_glo_dep_d_t(&msg->MSG_EPHEMERIS_GLO_DEP_D);
    case SBP_MSG_EPHEMERIS_GLO:
      return sbp_packed_size_sbp_msg_ephemeris_glo_t(&msg->MSG_EPHEMERIS_GLO);
    case SBP_MSG_EPHEMERIS_DEP_D:
      return sbp_packed_size_sbp_msg_ephemeris_dep_d_t(&msg->MSG_EPHEMERIS_DEP_D);
    case SBP_MSG_EPHEMERIS_DEP_A:
      return sbp_packed_size_sbp_msg_ephemeris_dep_a_t(&msg->MSG_EPHEMERIS_DEP_A);
    case SBP_MSG_EPHEMERIS_DEP_B:
      return sbp_packed_size_sbp_msg_ephemeris_dep_b_t(&msg->MSG_EPHEMERIS_DEP_B);
    case SBP_MSG_EPHEMERIS_DEP_C:
      return sbp_packed_size_sbp_msg_ephemeris_dep_c_t(&msg->MSG_EPHEMERIS_DEP_C);
    case SBP_MSG_OBS_DEP_A:
      return sbp_packed_size_sbp_msg_obs_dep_a_t(&msg->MSG_OBS_DEP_A);
    case SBP_MSG_OBS_DEP_B:
      return sbp_packed_size_sbp_msg_obs_dep_b_t(&msg->MSG_OBS_DEP_B);
    case SBP_MSG_OBS_DEP_C:
      return sbp_packed_size_sbp_msg_obs_dep_c_t(&msg->MSG_OBS_DEP_C);
    case SBP_MSG_IONO:
      return sbp_packed_size_sbp_msg_iono_t(&msg->MSG_IONO);
    case SBP_MSG_SV_CONFIGURATION_GPS_DEP:
      return sbp_packed_size_sbp_msg_sv_configuration_gps_dep_t(&msg->MSG_SV_CONFIGURATION_GPS_DEP);
    case SBP_MSG_GNSS_CAPB:
      return sbp_packed_size_sbp_msg_gnss_capb_t(&msg->MSG_GNSS_CAPB);
    case SBP_MSG_GROUP_DELAY_DEP_A:
      return sbp_packed_size_sbp_msg_group_delay_dep_a_t(&msg->MSG_GROUP_DELAY_DEP_A);
    case SBP_MSG_GROUP_DELAY_DEP_B:
      return sbp_packed_size_sbp_msg_group_delay_dep_b_t(&msg->MSG_GROUP_DELAY_DEP_B);
    case SBP_MSG_GROUP_DELAY:
      return sbp_packed_size_sbp_msg_group_delay_t(&msg->MSG_GROUP_DELAY);
    case SBP_MSG_ALMANAC_GPS_DEP:
      return sbp_packed_size_sbp_msg_almanac_gps_dep_t(&msg->MSG_ALMANAC_GPS_DEP);
    case SBP_MSG_ALMANAC_GPS:
      return sbp_packed_size_sbp_msg_almanac_gps_t(&msg->MSG_ALMANAC_GPS);
    case SBP_MSG_ALMANAC_GLO_DEP:
      return sbp_packed_size_sbp_msg_almanac_glo_dep_t(&msg->MSG_ALMANAC_GLO_DEP);
    case SBP_MSG_ALMANAC_GLO:
      return sbp_packed_size_sbp_msg_almanac_glo_t(&msg->MSG_ALMANAC_GLO);
    case SBP_MSG_GLO_BIASES:
      return sbp_packed_size_sbp_msg_glo_biases_t(&msg->MSG_GLO_BIASES);
    case SBP_MSG_SV_AZ_EL:
      return sbp_packed_size_sbp_msg_sv_az_el_t(&msg->MSG_SV_AZ_EL);
    case SBP_MSG_OSR:
      return sbp_packed_size_sbp_msg_osr_t(&msg->MSG_OSR);
    case SBP_MSG_ACQ_RESULT:
      return sbp_packed_size_sbp_msg_acq_result_t(&msg->MSG_ACQ_RESULT);
    case SBP_MSG_ACQ_RESULT_DEP_C:
      return sbp_packed_size_sbp_msg_acq_result_dep_c_t(&msg->MSG_ACQ_RESULT_DEP_C);
    case SBP_MSG_ACQ_RESULT_DEP_B:
      return sbp_packed_size_sbp_msg_acq_result_dep_b_t(&msg->MSG_ACQ_RESULT_DEP_B);
    case SBP_MSG_ACQ_RESULT_DEP_A:
      return sbp_packed_size_sbp_msg_acq_result_dep_a_t(&msg->MSG_ACQ_RESULT_DEP_A);
    case SBP_MSG_ACQ_SV_PROFILE:
      return sbp_packed_size_sbp_msg_acq_sv_profile_t(&msg->MSG_ACQ_SV_PROFILE);
    case SBP_MSG_ACQ_SV_PROFILE_DEP:
      return sbp_packed_size_sbp_msg_acq_sv_profile_dep_t(&msg->MSG_ACQ_SV_PROFILE_DEP);
    case SBP_MSG_SSR_ORBIT_CLOCK:
      return sbp_packed_size_sbp_msg_ssr_orbit_clock_t(&msg->MSG_SSR_ORBIT_CLOCK);
    case SBP_MSG_SSR_CODE_BIASES:
      return sbp_packed_size_sbp_msg_ssr_code_biases_t(&msg->MSG_SSR_CODE_BIASES);
    case SBP_MSG_SSR_PHASE_BIASES:
      return sbp_packed_size_sbp_msg_ssr_phase_biases_t(&msg->MSG_SSR_PHASE_BIASES);
    case SBP_MSG_SSR_STEC_CORRECTION:
      return sbp_packed_size_sbp_msg_ssr_stec_correction_t(&msg->MSG_SSR_STEC_CORRECTION);
    case SBP_MSG_SSR_GRIDDED_CORRECTION:
      return sbp_packed_size_sbp_msg_ssr_gridded_correction_t(&msg->MSG_SSR_GRIDDED_CORRECTION);
    case SBP_MSG_SSR_TILE_DEFINITION:
      return sbp_packed_size_sbp_msg_ssr_tile_definition_t(&msg->MSG_SSR_TILE_DEFINITION);
    case SBP_MSG_SSR_SATELLITE_APC:
      return sbp_packed_size_sbp_msg_ssr_satellite_apc_t(&msg->MSG_SSR_SATELLITE_APC);
    case SBP_MSG_SSR_ORBIT_CLOCK_DEP_A:
      return sbp_packed_size_sbp_msg_ssr_orbit_clock_dep_a_t(&msg->MSG_SSR_ORBIT_CLOCK_DEP_A);
    case SBP_MSG_SSR_STEC_CORRECTION_DEP_A:
      return sbp_packed_size_sbp_msg_ssr_stec_correction_dep_a_t(&msg->MSG_SSR_STEC_CORRECTION_DEP_A);
    case SBP_MSG_SSR_GRIDDED_CORRECTION_NO_STD_DEP_A:
      return sbp_packed_size_sbp_msg_ssr_gridded_correction_no_std_dep_a_t(
          &msg->MSG_SSR_GRIDDED_CORRECTION_NO_STD_DEP_A);
    case SBP_MSG_SSR_GRIDDED_CORRECTION_DEP_A:
      return sbp_packed_size_sbp_msg_ssr_gridded_correction_dep_a_t(&msg->MSG_SSR_GRIDDED_CORRECTION_DEP_A);
    case SBP_MSG_SSR_GRID_DEFINITION_DEP_A:
      return sbp_packed_size_sbp_msg_ssr_grid_definition_dep_a_t(&msg->MSG_SSR_GRID_DEFINITION_DEP_A);
    case SBP_MSG_BOOTLOADER_HANDSHAKE_REQ:
      return sbp_packed_size_sbp_msg_bootloader_handshake_req_t(&msg->MSG_BOOTLOADER_HANDSHAKE_REQ);
    case SBP_MSG_BOOTLOADER_HANDSHAKE_RESP:
      return sbp_packed_size_sbp_msg_bootloader_handshake_resp_t(&msg->MSG_BOOTLOADER_HANDSHAKE_RESP);
    case SBP_MSG_BOOTLOADER_JUMP_TO_APP:
      return sbp_packed_size_sbp_msg_bootloader_jump_to_app_t(&msg->MSG_BOOTLOADER_JUMP_TO_APP);
    case SBP_MSG_NAP_DEVICE_DNA_REQ:
      return sbp_packed_size_sbp_msg_nap_device_dna_req_t(&msg->MSG_NAP_DEVICE_DNA_REQ);
    case SBP_MSG_NAP_DEVICE_DNA_RESP:
      return sbp_packed_size_sbp_msg_nap_device_dna_resp_t(&msg->MSG_NAP_DEVICE_DNA_RESP);
    case SBP_MSG_BOOTLOADER_HANDSHAKE_DEP_A:
      return sbp_packed_size_sbp_msg_bootloader_handshake_dep_a_t(&msg->MSG_BOOTLOADER_HANDSHAKE_DEP_A);
    case SBP_MSG_USER_DATA:
      return sbp_packed_size_sbp_msg_user_data_t(&msg->MSG_USER_DATA);
    case SBP_MSG_SETTINGS_SAVE:
      return sbp_packed_size_sbp_msg_settings_save_t(&msg->MSG_SETTINGS_SAVE);
    case SBP_MSG_SETTINGS_WRITE:
      return sbp_packed_size_sbp_msg_settings_write_t(&msg->MSG_SETTINGS_WRITE);
    case SBP_MSG_SETTINGS_WRITE_RESP:
      return sbp_packed_size_sbp_msg_settings_write_resp_t(&msg->MSG_SETTINGS_WRITE_RESP);
    case SBP_MSG_SETTINGS_READ_REQ:
      return sbp_packed_size_sbp_msg_settings_read_req_t(&msg->MSG_SETTINGS_READ_REQ);
    case SBP_MSG_SETTINGS_READ_RESP:
      return sbp_packed_size_sbp_msg_settings_read_resp_t(&msg->MSG_SETTINGS_READ_RESP);
    case SBP_MSG_SETTINGS_READ_BY_INDEX_REQ:
      return sbp_packed_size_sbp_msg_settings_read_by_index_req_t(&msg->MSG_SETTINGS_READ_BY_INDEX_REQ);
    case SBP_MSG_SETTINGS_READ_BY_INDEX_RESP:
      return sbp_packed_size_sbp_msg_settings_read_by_index_resp_t(&msg->MSG_SETTINGS_READ_BY_INDEX_RESP);
    case SBP_MSG_SETTINGS_READ_BY_INDEX_DONE:
      return sbp_packed_size_sbp_msg_settings_read_by_index_done_t(&msg->MSG_SETTINGS_READ_BY_INDEX_DONE);
    case SBP_MSG_SETTINGS_REGISTER:
      return sbp_packed_size_sbp_msg_settings_register_t(&msg->MSG_SETTINGS_REGISTER);
    case SBP_MSG_SETTINGS_REGISTER_RESP:
      return sbp_packed_size_sbp_msg_settings_register_resp_t(&msg->MSG_SETTINGS_REGISTER_RESP);
    case SBP_MSG_IMU_RAW:
      return sbp_packed_size_sbp_msg_imu_raw_t(&msg->MSG_IMU_RAW);
    case SBP_MSG_IMU_AUX:
      return sbp_packed_size_sbp_msg_imu_aux_t(&msg->MSG_IMU_AUX);
    case SBP_MSG_FILEIO_READ_REQ:
      return sbp_packed_size_sbp_msg_fileio_read_req_t(&msg->MSG_FILEIO_READ_REQ);
    case SBP_MSG_FILEIO_READ_RESP:
      return sbp_packed_size_sbp_msg_fileio_read_resp_t(&msg->MSG_FILEIO_READ_RESP);
    case SBP_MSG_FILEIO_READ_DIR_REQ:
      return sbp_packed_size_sbp_msg_fileio_read_dir_req_t(&msg->MSG_FILEIO_READ_DIR_REQ);
    case SBP_MSG_FILEIO_READ_DIR_RESP:
      return sbp_packed_size_sbp_msg_fileio_read_dir_resp_t(&msg->MSG_FILEIO_READ_DIR_RESP);
    case SBP_MSG_FILEIO_REMOVE:
      return sbp_packed_size_sbp_msg_fileio_remove_t(&msg->MSG_FILEIO_REMOVE);
    case SBP_MSG_FILEIO_WRITE_REQ:
      return sbp_packed_size_sbp_msg_fileio_write_req_t(&msg->MSG_FILEIO_WRITE_REQ);
    case SBP_MSG_FILEIO_WRITE_RESP:
      return sbp_packed_size_sbp_msg_fileio_write_resp_t(&msg->MSG_FILEIO_WRITE_RESP);
    case SBP_MSG_FILEIO_CONFIG_REQ:
      return sbp_packed_size_sbp_msg_fileio_config_req_t(&msg->MSG_FILEIO_CONFIG_REQ);
    case SBP_MSG_FILEIO_CONFIG_RESP:
      return sbp_packed_size_sbp_msg_fileio_config_resp_t(&msg->MSG_FILEIO_CONFIG_RESP);
    case SBP_MSG_ODOMETRY:
      return sbp_packed_size_sbp_msg_odometry_t(&msg->MSG_ODOMETRY);
    case SBP_MSG_WHEELTICK:
      return sbp_packed_size_sbp_msg_wheeltick_t(&msg->MSG_WHEELTICK);
    case SBP_MSG_SOLN_META_DEP_A:
      return sbp_packed_size_sbp_msg_soln_meta_dep_a_t(&msg->MSG_SOLN_META_DEP_A);
    case SBP_MSG_SOLN_META:
      return sbp_packed_size_sbp_msg_soln_meta_t(&msg->MSG_SOLN_META);
    case SBP_MSG_FLASH_PROGRAM:
      return sbp_packed_size_sbp_msg_flash_program_t(&msg->MSG_FLASH_PROGRAM);
    case SBP_MSG_FLASH_DONE:
      return sbp_packed_size_sbp_msg_flash_done_t(&msg->MSG_FLASH_DONE);
    case SBP_MSG_FLASH_READ_REQ:
      return sbp_packed_size_sbp_msg_flash_read_req_t(&msg->MSG_FLASH_READ_REQ);
    case SBP_MSG_FLASH_READ_RESP:
      return sbp_packed_size_sbp_msg_flash_read_resp_t(&msg->MSG_FLASH_READ_RESP);
    case SBP_MSG_FLASH_ERASE:
      return sbp_packed_size_sbp_msg_flash_erase_t(&msg->MSG_FLASH_ERASE);
    case SBP_MSG_STM_FLASH_LOCK_SECTOR:
      return sbp_packed_size_sbp_msg_stm_flash_lock_sector_t(&msg->MSG_STM_FLASH_LOCK_SECTOR);
    case SBP_MSG_STM_FLASH_UNLOCK_SECTOR:
      return sbp_packed_size_sbp_msg_stm_flash_unlock_sector_t(&msg->MSG_STM_FLASH_UNLOCK_SECTOR);
    case SBP_MSG_STM_UNIQUE_ID_REQ:
      return sbp_packed_size_sbp_msg_stm_unique_id_req_t(&msg->MSG_STM_UNIQUE_ID_REQ);
    case SBP_MSG_STM_UNIQUE_ID_RESP:
      return sbp_packed_size_sbp_msg_stm_unique_id_resp_t(&msg->MSG_STM_UNIQUE_ID_RESP);
    case SBP_MSG_M25_FLASH_WRITE_STATUS:
      return sbp_packed_size_sbp_msg_m25_flash_write_status_t(&msg->MSG_M25_FLASH_WRITE_STATUS);
    case SBP_MSG_TRACKING_STATE_DETAILED_DEP_A:
      return sbp_packed_size_sbp_msg_tracking_state_detailed_dep_a_t(&msg->MSG_TRACKING_STATE_DETAILED_DEP_A);
    case SBP_MSG_TRACKING_STATE_DETAILED_DEP:
      return sbp_packed_size_sbp_msg_tracking_state_detailed_dep_t(&msg->MSG_TRACKING_STATE_DETAILED_DEP);
    case SBP_MSG_TRACKING_STATE:
      return sbp_packed_size_sbp_msg_tracking_state_t(&msg->MSG_TRACKING_STATE);
    case SBP_MSG_MEASUREMENT_STATE:
      return sbp_packed_size_sbp_msg_measurement_state_t(&msg->MSG_MEASUREMENT_STATE);
    case SBP_MSG_TRACKING_IQ:
      return sbp_packed_size_sbp_msg_tracking_iq_t(&msg->MSG_TRACKING_IQ);
    case SBP_MSG_TRACKING_IQ_DEP_B:
      return sbp_packed_size_sbp_msg_tracking_iq_dep_b_t(&msg->MSG_TRACKING_IQ_DEP_B);
    case SBP_MSG_TRACKING_IQ_DEP_A:
      return sbp_packed_size_sbp_msg_tracking_iq_dep_a_t(&msg->MSG_TRACKING_IQ_DEP_A);
    case SBP_MSG_TRACKING_STATE_DEP_A:
      return sbp_packed_size_sbp_msg_tracking_state_dep_a_t(&msg->MSG_TRACKING_STATE_DEP_A);
    case SBP_MSG_TRACKING_STATE_DEP_B:
      return sbp_packed_size_sbp_msg_tracking_state_dep_b_t(&msg->MSG_TRACKING_STATE_DEP_B);
    case SBP_MSG_EXT_EVENT:
      return sbp_packed_size_sbp_msg_ext_event_t(&msg->MSG_EXT_EVENT);
    case SBP_MSG_STARTUP:
      return sbp_packed_size_sbp_msg_startup_t(&msg->MSG_STARTUP);
    case SBP_MSG_DGNSS_STATUS:
      return sbp_packed_size_sbp_msg_dgnss_status_t(&msg->MSG_DGNSS_STATUS);
    case SBP_MSG_HEARTBEAT:
      return sbp_packed_size_sbp_msg_heartbeat_t(&msg->MSG_HEARTBEAT);
    case SBP_MSG_STATUS_REPORT:
      return sbp_packed_size_sbp_msg_status_report_t(&msg->MSG_STATUS_REPORT);
    case SBP_MSG_INS_STATUS:
      return sbp_packed_size_sbp_msg_ins_status_t(&msg->MSG_INS_STATUS);
    case SBP_MSG_CSAC_TELEMETRY:
      return sbp_packed_size_sbp_msg_csac_telemetry_t(&msg->MSG_CSAC_TELEMETRY);
    case SBP_MSG_CSAC_TELEMETRY_LABELS:
      return sbp_packed_size_sbp_msg_csac_telemetry_labels_t(&msg->MSG_CSAC_TELEMETRY_LABELS);
    case SBP_MSG_INS_UPDATES:
      return sbp_packed_size_sbp_msg_ins_updates_t(&msg->MSG_INS_UPDATES);
    case SBP_MSG_GNSS_TIME_OFFSET:
      return sbp_packed_size_sbp_msg_gnss_time_offset_t(&msg->MSG_GNSS_TIME_OFFSET);
    case SBP_MSG_GROUP_META:
      return sbp_packed_size_sbp_msg_group_meta_t(&msg->MSG_GROUP_META);
    default:
      break;
  }
  return 0;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_t &a, const sbp_msg_t &b)
{
  if (a.type != b.type)
  {
    return false;
  }
  switch (a.type)
  {
    case SBP_MSG_SBAS_RAW:
      return a.MSG_SBAS_RAW == b.MSG_SBAS_RAW;
    case SBP_MSG_BASELINE_HEADING:
      return a.MSG_BASELINE_HEADING == b.MSG_BASELINE_HEADING;
    case SBP_MSG_ORIENT_QUAT:
      return a.MSG_ORIENT_QUAT == b.MSG_ORIENT_QUAT;
    case SBP_MSG_ORIENT_EULER:
      return a.MSG_ORIENT_EULER == b.MSG_ORIENT_EULER;
    case SBP_MSG_ANGULAR_RATE:
      return a.MSG_ANGULAR_RATE == b.MSG_ANGULAR_RATE;
    case SBP_MSG_ALMANAC:
      return a.MSG_ALMANAC == b.MSG_ALMANAC;
    case SBP_MSG_SET_TIME:
      return a.MSG_SET_TIME == b.MSG_SET_TIME;
    case SBP_MSG_RESET:
      return a.MSG_RESET == b.MSG_RESET;
    case SBP_MSG_RESET_DEP:
      return a.MSG_RESET_DEP == b.MSG_RESET_DEP;
    case SBP_MSG_CW_RESULTS:
      return a.MSG_CW_RESULTS == b.MSG_CW_RESULTS;
    case SBP_MSG_CW_START:
      return a.MSG_CW_START == b.MSG_CW_START;
    case SBP_MSG_RESET_FILTERS:
      return a.MSG_RESET_FILTERS == b.MSG_RESET_FILTERS;
    case SBP_MSG_INIT_BASE_DEP:
      return a.MSG_INIT_BASE_DEP == b.MSG_INIT_BASE_DEP;
    case SBP_MSG_THREAD_STATE:
      return a.MSG_THREAD_STATE == b.MSG_THREAD_STATE;
    case SBP_MSG_UART_STATE:
      return a.MSG_UART_STATE == b.MSG_UART_STATE;
    case SBP_MSG_UART_STATE_DEPA:
      return a.MSG_UART_STATE_DEPA == b.MSG_UART_STATE_DEPA;
    case SBP_MSG_IAR_STATE:
      return a.MSG_IAR_STATE == b.MSG_IAR_STATE;
    case SBP_MSG_MASK_SATELLITE:
      return a.MSG_MASK_SATELLITE == b.MSG_MASK_SATELLITE;
    case SBP_MSG_MASK_SATELLITE_DEP:
      return a.MSG_MASK_SATELLITE_DEP == b.MSG_MASK_SATELLITE_DEP;
    case SBP_MSG_DEVICE_MONITOR:
      return a.MSG_DEVICE_MONITOR == b.MSG_DEVICE_MONITOR;
    case SBP_MSG_COMMAND_REQ:
      return a.MSG_COMMAND_REQ == b.MSG_COMMAND_REQ;
    case SBP_MSG_COMMAND_RESP:
      return a.MSG_COMMAND_RESP == b.MSG_COMMAND_RESP;
    case SBP_MSG_COMMAND_OUTPUT:
      return a.MSG_COMMAND_OUTPUT == b.MSG_COMMAND_OUTPUT;
    case SBP_MSG_NETWORK_STATE_REQ:
      return a.MSG_NETWORK_STATE_REQ == b.MSG_NETWORK_STATE_REQ;
    case SBP_MSG_NETWORK_STATE_RESP:
      return a.MSG_NETWORK_STATE_RESP == b.MSG_NETWORK_STATE_RESP;
    case SBP_MSG_NETWORK_BANDWIDTH_USAGE:
      return a.MSG_NETWORK_BANDWIDTH_USAGE == b.MSG_NETWORK_BANDWIDTH_USAGE;
    case SBP_MSG_CELL_MODEM_STATUS:
      return a.MSG_CELL_MODEM_STATUS == b.MSG_CELL_MODEM_STATUS;
    case SBP_MSG_SPECAN_DEP:
      return a.MSG_SPECAN_DEP == b.MSG_SPECAN_DEP;
    case SBP_MSG_SPECAN:
      return a.MSG_SPECAN == b.MSG_SPECAN;
    case SBP_MSG_FRONT_END_GAIN:
      return a.MSG_FRONT_END_GAIN == b.MSG_FRONT_END_GAIN;
    case SBP_MSG_MAG_RAW:
      return a.MSG_MAG_RAW == b.MSG_MAG_RAW;
    case SBP_MSG_GPS_TIME:
      return a.MSG_GPS_TIME == b.MSG_GPS_TIME;
    case SBP_MSG_GPS_TIME_GNSS:
      return a.MSG_GPS_TIME_GNSS == b.MSG_GPS_TIME_GNSS;
    case SBP_MSG_UTC_TIME:
      return a.MSG_UTC_TIME == b.MSG_UTC_TIME;
    case SBP_MSG_UTC_TIME_GNSS:
      return a.MSG_UTC_TIME_GNSS == b.MSG_UTC_TIME_GNSS;
    case SBP_MSG_DOPS:
      return a.MSG_DOPS == b.MSG_DOPS;
    case SBP_MSG_POS_ECEF:
      return a.MSG_POS_ECEF == b.MSG_POS_ECEF;
    case SBP_MSG_POS_ECEF_COV:
      return a.MSG_POS_ECEF_COV == b.MSG_POS_ECEF_COV;
    case SBP_MSG_POS_LLH:
      return a.MSG_POS_LLH == b.MSG_POS_LLH;
    case SBP_MSG_POS_LLH_COV:
      return a.MSG_POS_LLH_COV == b.MSG_POS_LLH_COV;
    case SBP_MSG_BASELINE_ECEF:
      return a.MSG_BASELINE_ECEF == b.MSG_BASELINE_ECEF;
    case SBP_MSG_BASELINE_NED:
      return a.MSG_BASELINE_NED == b.MSG_BASELINE_NED;
    case SBP_MSG_VEL_ECEF:
      return a.MSG_VEL_ECEF == b.MSG_VEL_ECEF;
    case SBP_MSG_VEL_ECEF_COV:
      return a.MSG_VEL_ECEF_COV == b.MSG_VEL_ECEF_COV;
    case SBP_MSG_VEL_NED:
      return a.MSG_VEL_NED == b.MSG_VEL_NED;
    case SBP_MSG_VEL_NED_COV:
      return a.MSG_VEL_NED_COV == b.MSG_VEL_NED_COV;
    case SBP_MSG_POS_ECEF_GNSS:
      return a.MSG_POS_ECEF_GNSS == b.MSG_POS_ECEF_GNSS;
    case SBP_MSG_POS_ECEF_COV_GNSS:
      return a.MSG_POS_ECEF_COV_GNSS == b.MSG_POS_ECEF_COV_GNSS;
    case SBP_MSG_POS_LLH_GNSS:
      return a.MSG_POS_LLH_GNSS == b.MSG_POS_LLH_GNSS;
    case SBP_MSG_POS_LLH_COV_GNSS:
      return a.MSG_POS_LLH_COV_GNSS == b.MSG_POS_LLH_COV_GNSS;
    case SBP_MSG_VEL_ECEF_GNSS:
      return a.MSG_VEL_ECEF_GNSS == b.MSG_VEL_ECEF_GNSS;
    case SBP_MSG_VEL_ECEF_COV_GNSS:
      return a.MSG_VEL_ECEF_COV_GNSS == b.MSG_VEL_ECEF_COV_GNSS;
    case SBP_MSG_VEL_NED_GNSS:
      return a.MSG_VEL_NED_GNSS == b.MSG_VEL_NED_GNSS;
    case SBP_MSG_VEL_NED_COV_GNSS:
      return a.MSG_VEL_NED_COV_GNSS == b.MSG_VEL_NED_COV_GNSS;
    case SBP_MSG_VEL_BODY:
      return a.MSG_VEL_BODY == b.MSG_VEL_BODY;
    case SBP_MSG_AGE_CORRECTIONS:
      return a.MSG_AGE_CORRECTIONS == b.MSG_AGE_CORRECTIONS;
    case SBP_MSG_GPS_TIME_DEP_A:
      return a.MSG_GPS_TIME_DEP_A == b.MSG_GPS_TIME_DEP_A;
    case SBP_MSG_DOPS_DEP_A:
      return a.MSG_DOPS_DEP_A == b.MSG_DOPS_DEP_A;
    case SBP_MSG_POS_ECEF_DEP_A:
      return a.MSG_POS_ECEF_DEP_A == b.MSG_POS_ECEF_DEP_A;
    case SBP_MSG_POS_LLH_DEP_A:
      return a.MSG_POS_LLH_DEP_A == b.MSG_POS_LLH_DEP_A;
    case SBP_MSG_BASELINE_ECEF_DEP_A:
      return a.MSG_BASELINE_ECEF_DEP_A == b.MSG_BASELINE_ECEF_DEP_A;
    case SBP_MSG_BASELINE_NED_DEP_A:
      return a.MSG_BASELINE_NED_DEP_A == b.MSG_BASELINE_NED_DEP_A;
    case SBP_MSG_VEL_ECEF_DEP_A:
      return a.MSG_VEL_ECEF_DEP_A == b.MSG_VEL_ECEF_DEP_A;
    case SBP_MSG_VEL_NED_DEP_A:
      return a.MSG_VEL_NED_DEP_A == b.MSG_VEL_NED_DEP_A;
    case SBP_MSG_BASELINE_HEADING_DEP_A:
      return a.MSG_BASELINE_HEADING_DEP_A == b.MSG_BASELINE_HEADING_DEP_A;
    case SBP_MSG_PROTECTION_LEVEL:
      return a.MSG_PROTECTION_LEVEL == b.MSG_PROTECTION_LEVEL;
    case SBP_MSG_NDB_EVENT:
      return a.MSG_NDB_EVENT == b.MSG_NDB_EVENT;
    case SBP_MSG_LINUX_CPU_STATE_DEP_A:
      return a.MSG_LINUX_CPU_STATE_DEP_A == b.MSG_LINUX_CPU_STATE_DEP_A;
    case SBP_MSG_LINUX_MEM_STATE_DEP_A:
      return a.MSG_LINUX_MEM_STATE_DEP_A == b.MSG_LINUX_MEM_STATE_DEP_A;
    case SBP_MSG_LINUX_SYS_STATE_DEP_A:
      return a.MSG_LINUX_SYS_STATE_DEP_A == b.MSG_LINUX_SYS_STATE_DEP_A;
    case SBP_MSG_LINUX_PROCESS_SOCKET_COUNTS:
      return a.MSG_LINUX_PROCESS_SOCKET_COUNTS == b.MSG_LINUX_PROCESS_SOCKET_COUNTS;
    case SBP_MSG_LINUX_PROCESS_SOCKET_QUEUES:
      return a.MSG_LINUX_PROCESS_SOCKET_QUEUES == b.MSG_LINUX_PROCESS_SOCKET_QUEUES;
    case SBP_MSG_LINUX_SOCKET_USAGE:
      return a.MSG_LINUX_SOCKET_USAGE == b.MSG_LINUX_SOCKET_USAGE;
    case SBP_MSG_LINUX_PROCESS_FD_COUNT:
      return a.MSG_LINUX_PROCESS_FD_COUNT == b.MSG_LINUX_PROCESS_FD_COUNT;
    case SBP_MSG_LINUX_PROCESS_FD_SUMMARY:
      return a.MSG_LINUX_PROCESS_FD_SUMMARY == b.MSG_LINUX_PROCESS_FD_SUMMARY;
    case SBP_MSG_LINUX_CPU_STATE:
      return a.MSG_LINUX_CPU_STATE == b.MSG_LINUX_CPU_STATE;
    case SBP_MSG_LINUX_MEM_STATE:
      return a.MSG_LINUX_MEM_STATE == b.MSG_LINUX_MEM_STATE;
    case SBP_MSG_LINUX_SYS_STATE:
      return a.MSG_LINUX_SYS_STATE == b.MSG_LINUX_SYS_STATE;
    case SBP_MSG_LOG:
      return a.MSG_LOG == b.MSG_LOG;
    case SBP_MSG_FWD:
      return a.MSG_FWD == b.MSG_FWD;
    case SBP_MSG_PRINT_DEP:
      return a.MSG_PRINT_DEP == b.MSG_PRINT_DEP;
    case SBP_MSG_OBS:
      return a.MSG_OBS == b.MSG_OBS;
    case SBP_MSG_BASE_POS_LLH:
      return a.MSG_BASE_POS_LLH == b.MSG_BASE_POS_LLH;
    case SBP_MSG_BASE_POS_ECEF:
      return a.MSG_BASE_POS_ECEF == b.MSG_BASE_POS_ECEF;
    case SBP_MSG_EPHEMERIS_GPS_DEP_E:
      return a.MSG_EPHEMERIS_GPS_DEP_E == b.MSG_EPHEMERIS_GPS_DEP_E;
    case SBP_MSG_EPHEMERIS_GPS_DEP_F:
      return a.MSG_EPHEMERIS_GPS_DEP_F == b.MSG_EPHEMERIS_GPS_DEP_F;
    case SBP_MSG_EPHEMERIS_GPS:
      return a.MSG_EPHEMERIS_GPS == b.MSG_EPHEMERIS_GPS;
    case SBP_MSG_EPHEMERIS_QZSS:
      return a.MSG_EPHEMERIS_QZSS == b.MSG_EPHEMERIS_QZSS;
    case SBP_MSG_EPHEMERIS_BDS:
      return a.MSG_EPHEMERIS_BDS == b.MSG_EPHEMERIS_BDS;
    case SBP_MSG_EPHEMERIS_GAL_DEP_A:
      return a.MSG_EPHEMERIS_GAL_DEP_A == b.MSG_EPHEMERIS_GAL_DEP_A;
    case SBP_MSG_EPHEMERIS_GAL:
      return a.MSG_EPHEMERIS_GAL == b.MSG_EPHEMERIS_GAL;
    case SBP_MSG_EPHEMERIS_SBAS_DEP_A:
      return a.MSG_EPHEMERIS_SBAS_DEP_A == b.MSG_EPHEMERIS_SBAS_DEP_A;
    case SBP_MSG_EPHEMERIS_GLO_DEP_A:
      return a.MSG_EPHEMERIS_GLO_DEP_A == b.MSG_EPHEMERIS_GLO_DEP_A;
    case SBP_MSG_EPHEMERIS_SBAS_DEP_B:
      return a.MSG_EPHEMERIS_SBAS_DEP_B == b.MSG_EPHEMERIS_SBAS_DEP_B;
    case SBP_MSG_EPHEMERIS_SBAS:
      return a.MSG_EPHEMERIS_SBAS == b.MSG_EPHEMERIS_SBAS;
    case SBP_MSG_EPHEMERIS_GLO_DEP_B:
      return a.MSG_EPHEMERIS_GLO_DEP_B == b.MSG_EPHEMERIS_GLO_DEP_B;
    case SBP_MSG_EPHEMERIS_GLO_DEP_C:
      return a.MSG_EPHEMERIS_GLO_DEP_C == b.MSG_EPHEMERIS_GLO_DEP_C;
    case SBP_MSG_EPHEMERIS_GLO_DEP_D:
      return a.MSG_EPHEMERIS_GLO_DEP_D == b.MSG_EPHEMERIS_GLO_DEP_D;
    case SBP_MSG_EPHEMERIS_GLO:
      return a.MSG_EPHEMERIS_GLO == b.MSG_EPHEMERIS_GLO;
    case SBP_MSG_EPHEMERIS_DEP_D:
      return a.MSG_EPHEMERIS_DEP_D == b.MSG_EPHEMERIS_DEP_D;
    case SBP_MSG_EPHEMERIS_DEP_A:
      return a.MSG_EPHEMERIS_DEP_A == b.MSG_EPHEMERIS_DEP_A;
    case SBP_MSG_EPHEMERIS_DEP_B:
      return a.MSG_EPHEMERIS_DEP_B == b.MSG_EPHEMERIS_DEP_B;
    case SBP_MSG_EPHEMERIS_DEP_C:
      return a.MSG_EPHEMERIS_DEP_C == b.MSG_EPHEMERIS_DEP_C;
    case SBP_MSG_OBS_DEP_A:
      return a.MSG_OBS_DEP_A == b.MSG_OBS_DEP_A;
    case SBP_MSG_OBS_DEP_B:
      return a.MSG_OBS_DEP_B == b.MSG_OBS_DEP_B;
    case SBP_MSG_OBS_DEP_C:
      return a.MSG_OBS_DEP_C == b.MSG_OBS_DEP_C;
    case SBP_MSG_IONO:
      return a.MSG_IONO == b.MSG_IONO;
    case SBP_MSG_SV_CONFIGURATION_GPS_DEP:
      return a.MSG_SV_CONFIGURATION_GPS_DEP == b.MSG_SV_CONFIGURATION_GPS_DEP;
    case SBP_MSG_GNSS_CAPB:
      return a.MSG_GNSS_CAPB == b.MSG_GNSS_CAPB;
    case SBP_MSG_GROUP_DELAY_DEP_A:
      return a.MSG_GROUP_DELAY_DEP_A == b.MSG_GROUP_DELAY_DEP_A;
    case SBP_MSG_GROUP_DELAY_DEP_B:
      return a.MSG_GROUP_DELAY_DEP_B == b.MSG_GROUP_DELAY_DEP_B;
    case SBP_MSG_GROUP_DELAY:
      return a.MSG_GROUP_DELAY == b.MSG_GROUP_DELAY;
    case SBP_MSG_ALMANAC_GPS_DEP:
      return a.MSG_ALMANAC_GPS_DEP == b.MSG_ALMANAC_GPS_DEP;
    case SBP_MSG_ALMANAC_GPS:
      return a.MSG_ALMANAC_GPS == b.MSG_ALMANAC_GPS;
    case SBP_MSG_ALMANAC_GLO_DEP:
      return a.MSG_ALMANAC_GLO_DEP == b.MSG_ALMANAC_GLO_DEP;
    case SBP_MSG_ALMANAC_GLO:
      return a.MSG_ALMANAC_GLO == b.MSG_ALMANAC_GLO;
    case SBP_MSG_GLO_BIASES:
      return a.MSG_GLO_BIASES == b.MSG_GLO_BIASES;
    case SBP_MSG_SV_AZ_EL:
      return a.MSG_SV_AZ_EL == b.MSG_SV_AZ_EL;
    case SBP_MSG_OSR:
      return a.MSG_OSR == b.MSG_OSR;
    case SBP_MSG_ACQ_RESULT:
      return a.MSG_ACQ_RESULT == b.MSG_ACQ_RESULT;
    case SBP_MSG_ACQ_RESULT_DEP_C:
      return a.MSG_ACQ_RESULT_DEP_C == b.MSG_ACQ_RESULT_DEP_C;
    case SBP_MSG_ACQ_RESULT_DEP_B:
      return a.MSG_ACQ_RESULT_DEP_B == b.MSG_ACQ_RESULT_DEP_B;
    case SBP_MSG_ACQ_RESULT_DEP_A:
      return a.MSG_ACQ_RESULT_DEP_A == b.MSG_ACQ_RESULT_DEP_A;
    case SBP_MSG_ACQ_SV_PROFILE:
      return a.MSG_ACQ_SV_PROFILE == b.MSG_ACQ_SV_PROFILE;
    case SBP_MSG_ACQ_SV_PROFILE_DEP:
      return a.MSG_ACQ_SV_PROFILE_DEP == b.MSG_ACQ_SV_PROFILE_DEP;
    case SBP_MSG_SSR_ORBIT_CLOCK:
      return a.MSG_SSR_ORBIT_CLOCK == b.MSG_SSR_ORBIT_CLOCK;
    case SBP_MSG_SSR_CODE_BIASES:
      return a.MSG_SSR_CODE_BIASES == b.MSG_SSR_CODE_BIASES;
    case SBP_MSG_SSR_PHASE_BIASES:
      return a.MSG_SSR_PHASE_BIASES == b.MSG_SSR_PHASE_BIASES;
    case SBP_MSG_SSR_STEC_CORRECTION:
      return a.MSG_SSR_STEC_CORRECTION == b.MSG_SSR_STEC_CORRECTION;
    case SBP_MSG_SSR_GRIDDED_CORRECTION:
      return a.MSG_SSR_GRIDDED_CORRECTION == b.MSG_SSR_GRIDDED_CORRECTION;
    case SBP_MSG_SSR_TILE_DEFINITION:
      return a.MSG_SSR_TILE_DEFINITION == b.MSG_SSR_TILE_DEFINITION;
    case SBP_MSG_SSR_SATELLITE_APC:
      return a.MSG_SSR_SATELLITE_APC == b.MSG_SSR_SATELLITE_APC;
    case SBP_MSG_SSR_ORBIT_CLOCK_DEP_A:
      return a.MSG_SSR_ORBIT_CLOCK_DEP_A == b.MSG_SSR_ORBIT_CLOCK_DEP_A;
    case SBP_MSG_SSR_STEC_CORRECTION_DEP_A:
      return a.MSG_SSR_STEC_CORRECTION_DEP_A == b.MSG_SSR_STEC_CORRECTION_DEP_A;
    case SBP_MSG_SSR_GRIDDED_CORRECTION_NO_STD_DEP_A:
      return a.MSG_SSR_GRIDDED_CORRECTION_NO_STD_DEP_A == b.MSG_SSR_GRIDDED_CORRECTION_NO_STD_DEP_A;
    case SBP_MSG_SSR_GRIDDED_CORRECTION_DEP_A:
      return a.MSG_SSR_GRIDDED_CORRECTION_DEP_A == b.MSG_SSR_GRIDDED_CORRECTION_DEP_A;
    case SBP_MSG_SSR_GRID_DEFINITION_DEP_A:
      return a.MSG_SSR_GRID_DEFINITION_DEP_A == b.MSG_SSR_GRID_DEFINITION_DEP_A;
    case SBP_MSG_BOOTLOADER_HANDSHAKE_REQ:
      return a.MSG_BOOTLOADER_HANDSHAKE_REQ == b.MSG_BOOTLOADER_HANDSHAKE_REQ;
    case SBP_MSG_BOOTLOADER_HANDSHAKE_RESP:
      return a.MSG_BOOTLOADER_HANDSHAKE_RESP == b.MSG_BOOTLOADER_HANDSHAKE_RESP;
    case SBP_MSG_BOOTLOADER_JUMP_TO_APP:
      return a.MSG_BOOTLOADER_JUMP_TO_APP == b.MSG_BOOTLOADER_JUMP_TO_APP;
    case SBP_MSG_NAP_DEVICE_DNA_REQ:
      return a.MSG_NAP_DEVICE_DNA_REQ == b.MSG_NAP_DEVICE_DNA_REQ;
    case SBP_MSG_NAP_DEVICE_DNA_RESP:
      return a.MSG_NAP_DEVICE_DNA_RESP == b.MSG_NAP_DEVICE_DNA_RESP;
    case SBP_MSG_BOOTLOADER_HANDSHAKE_DEP_A:
      return a.MSG_BOOTLOADER_HANDSHAKE_DEP_A == b.MSG_BOOTLOADER_HANDSHAKE_DEP_A;
    case SBP_MSG_USER_DATA:
      return a.MSG_USER_DATA == b.MSG_USER_DATA;
    case SBP_MSG_SETTINGS_SAVE:
      return a.MSG_SETTINGS_SAVE == b.MSG_SETTINGS_SAVE;
    case SBP_MSG_SETTINGS_WRITE:
      return a.MSG_SETTINGS_WRITE == b.MSG_SETTINGS_WRITE;
    case SBP_MSG_SETTINGS_WRITE_RESP:
      return a.MSG_SETTINGS_WRITE_RESP == b.MSG_SETTINGS_WRITE_RESP;
    case SBP_MSG_SETTINGS_READ_REQ:
      return a.MSG_SETTINGS_READ_REQ == b.MSG_SETTINGS_READ_REQ;
    case SBP_MSG_SETTINGS_READ_RESP:
      return a.MSG_SETTINGS_READ_RESP == b.MSG_SETTINGS_READ_RESP;
    case SBP_MSG_SETTINGS_READ_BY_INDEX_REQ:
      return a.MSG_SETTINGS_READ_BY_INDEX_REQ == b.MSG_SETTINGS_READ_BY_INDEX_REQ;
    case SBP_MSG_SETTINGS_READ_BY_INDEX_RESP:
      return a.MSG_SETTINGS_READ_BY_INDEX_RESP == b.MSG_SETTINGS_READ_BY_INDEX_RESP;
    case SBP_MSG_SETTINGS_READ_BY_INDEX_DONE:
      return a.MSG_SETTINGS_READ_BY_INDEX_DONE == b.MSG_SETTINGS_READ_BY_INDEX_DONE;
    case SBP_MSG_SETTINGS_REGISTER:
      return a.MSG_SETTINGS_REGISTER == b.MSG_SETTINGS_REGISTER;
    case SBP_MSG_SETTINGS_REGISTER_RESP:
      return a.MSG_SETTINGS_REGISTER_RESP == b.MSG_SETTINGS_REGISTER_RESP;
    case SBP_MSG_IMU_RAW:
      return a.MSG_IMU_RAW == b.MSG_IMU_RAW;
    case SBP_MSG_IMU_AUX:
      return a.MSG_IMU_AUX == b.MSG_IMU_AUX;
    case SBP_MSG_FILEIO_READ_REQ:
      return a.MSG_FILEIO_READ_REQ == b.MSG_FILEIO_READ_REQ;
    case SBP_MSG_FILEIO_READ_RESP:
      return a.MSG_FILEIO_READ_RESP == b.MSG_FILEIO_READ_RESP;
    case SBP_MSG_FILEIO_READ_DIR_REQ:
      return a.MSG_FILEIO_READ_DIR_REQ == b.MSG_FILEIO_READ_DIR_REQ;
    case SBP_MSG_FILEIO_READ_DIR_RESP:
      return a.MSG_FILEIO_READ_DIR_RESP == b.MSG_FILEIO_READ_DIR_RESP;
    case SBP_MSG_FILEIO_REMOVE:
      return a.MSG_FILEIO_REMOVE == b.MSG_FILEIO_REMOVE;
    case SBP_MSG_FILEIO_WRITE_REQ:
      return a.MSG_FILEIO_WRITE_REQ == b.MSG_FILEIO_WRITE_REQ;
    case SBP_MSG_FILEIO_WRITE_RESP:
      return a.MSG_FILEIO_WRITE_RESP == b.MSG_FILEIO_WRITE_RESP;
    case SBP_MSG_FILEIO_CONFIG_REQ:
      return a.MSG_FILEIO_CONFIG_REQ == b.MSG_FILEIO_CONFIG_REQ;
    case SBP_MSG_FILEIO_CONFIG_RESP:
      return a.MSG_FILEIO_CONFIG_RESP == b.MSG_FILEIO_CONFIG_RESP;
    case SBP_MSG_ODOMETRY:
      return a.MSG_ODOMETRY == b.MSG_ODOMETRY;
    case SBP_MSG_WHEELTICK:
      return a.MSG_WHEELTICK == b.MSG_WHEELTICK;
    case SBP_MSG_SOLN_META_DEP_A:
      return a.MSG_SOLN_META_DEP_A == b.MSG_SOLN_META_DEP_A;
    case SBP_MSG_SOLN_META:
      return a.MSG_SOLN_META == b.MSG_SOLN_META;
    case SBP_MSG_FLASH_PROGRAM:
      return a.MSG_FLASH_PROGRAM == b.MSG_FLASH_PROGRAM;
    case SBP_MSG_FLASH_DONE:
      return a.MSG_FLASH_DONE == b.MSG_FLASH_DONE;
    case SBP_MSG_FLASH_READ_REQ:
      return a.MSG_FLASH_READ_REQ == b.MSG_FLASH_READ_REQ;
    case SBP_MSG_FLASH_READ_RESP:
      return a.MSG_FLASH_READ_RESP == b.MSG_FLASH_READ_RESP;
    case SBP_MSG_FLASH_ERASE:
      return a.MSG_FLASH_ERASE == b.MSG_FLASH_ERASE;
    case SBP_MSG_STM_FLASH_LOCK_SECTOR:
      return a.MSG_STM_FLASH_LOCK_SECTOR == b.MSG_STM_FLASH_LOCK_SECTOR;
    case SBP_MSG_STM_FLASH_UNLOCK_SECTOR:
      return a.MSG_STM_FLASH_UNLOCK_SECTOR == b.MSG_STM_FLASH_UNLOCK_SECTOR;
    case SBP_MSG_STM_UNIQUE_ID_REQ:
      return a.MSG_STM_UNIQUE_ID_REQ == b.MSG_STM_UNIQUE_ID_REQ;
    case SBP_MSG_STM_UNIQUE_ID_RESP:
      return a.MSG_STM_UNIQUE_ID_RESP == b.MSG_STM_UNIQUE_ID_RESP;
    case SBP_MSG_M25_FLASH_WRITE_STATUS:
      return a.MSG_M25_FLASH_WRITE_STATUS == b.MSG_M25_FLASH_WRITE_STATUS;
    case SBP_MSG_TRACKING_STATE_DETAILED_DEP_A:
      return a.MSG_TRACKING_STATE_DETAILED_DEP_A == b.MSG_TRACKING_STATE_DETAILED_DEP_A;
    case SBP_MSG_TRACKING_STATE_DETAILED_DEP:
      return a.MSG_TRACKING_STATE_DETAILED_DEP == b.MSG_TRACKING_STATE_DETAILED_DEP;
    case SBP_MSG_TRACKING_STATE:
      return a.MSG_TRACKING_STATE == b.MSG_TRACKING_STATE;
    case SBP_MSG_MEASUREMENT_STATE:
      return a.MSG_MEASUREMENT_STATE == b.MSG_MEASUREMENT_STATE;
    case SBP_MSG_TRACKING_IQ:
      return a.MSG_TRACKING_IQ == b.MSG_TRACKING_IQ;
    case SBP_MSG_TRACKING_IQ_DEP_B:
      return a.MSG_TRACKING_IQ_DEP_B == b.MSG_TRACKING_IQ_DEP_B;
    case SBP_MSG_TRACKING_IQ_DEP_A:
      return a.MSG_TRACKING_IQ_DEP_A == b.MSG_TRACKING_IQ_DEP_A;
    case SBP_MSG_TRACKING_STATE_DEP_A:
      return a.MSG_TRACKING_STATE_DEP_A == b.MSG_TRACKING_STATE_DEP_A;
    case SBP_MSG_TRACKING_STATE_DEP_B:
      return a.MSG_TRACKING_STATE_DEP_B == b.MSG_TRACKING_STATE_DEP_B;
    case SBP_MSG_EXT_EVENT:
      return a.MSG_EXT_EVENT == b.MSG_EXT_EVENT;
    case SBP_MSG_STARTUP:
      return a.MSG_STARTUP == b.MSG_STARTUP;
    case SBP_MSG_DGNSS_STATUS:
      return a.MSG_DGNSS_STATUS == b.MSG_DGNSS_STATUS;
    case SBP_MSG_HEARTBEAT:
      return a.MSG_HEARTBEAT == b.MSG_HEARTBEAT;
    case SBP_MSG_STATUS_REPORT:
      return a.MSG_STATUS_REPORT == b.MSG_STATUS_REPORT;
    case SBP_MSG_INS_STATUS:
      return a.MSG_INS_STATUS == b.MSG_INS_STATUS;
    case SBP_MSG_CSAC_TELEMETRY:
      return a.MSG_CSAC_TELEMETRY == b.MSG_CSAC_TELEMETRY;
    case SBP_MSG_CSAC_TELEMETRY_LABELS:
      return a.MSG_CSAC_TELEMETRY_LABELS == b.MSG_CSAC_TELEMETRY_LABELS;
    case SBP_MSG_INS_UPDATES:
      return a.MSG_INS_UPDATES == b.MSG_INS_UPDATES;
    case SBP_MSG_GNSS_TIME_OFFSET:
      return a.MSG_GNSS_TIME_OFFSET == b.MSG_GNSS_TIME_OFFSET;
    case SBP_MSG_GROUP_META:
      return a.MSG_GROUP_META == b.MSG_GROUP_META;
    default:
      break;
  }
  return false;
}

static inline bool operator!=(const sbp_msg_t &a, const sbp_msg_t &b)
{
  return !(a == b);
}
#endif

#endif
