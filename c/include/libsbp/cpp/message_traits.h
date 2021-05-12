/**
 * Copyright (C) 2019 Swift Navigation Inc.
 * Contact: https://support.swiftnav.com
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

#include <libsbp/unpacked/sbp_msg.h>
#include <libsbp/unpacked/acquisition.h>
#include <libsbp/unpacked/bootload.h>
#include <libsbp/unpacked/ext_events.h>
#include <libsbp/unpacked/file_io.h>
#include <libsbp/unpacked/flash.h>
#include <libsbp/unpacked/gnss.h>
#include <libsbp/unpacked/imu.h>
#include <libsbp/unpacked/linux.h>
#include <libsbp/unpacked/logging.h>
#include <libsbp/unpacked/mag.h>
#include <libsbp/unpacked/navigation.h>
#include <libsbp/unpacked/ndb.h>
#include <libsbp/unpacked/observation.h>
#include <libsbp/unpacked/orientation.h>
#include <libsbp/unpacked/piksi.h>
#include <libsbp/unpacked/sbas.h>
#include <libsbp/unpacked/settings.h>
#include <libsbp/unpacked/solution_meta.h>
#include <libsbp/unpacked/ssr.h>
#include <libsbp/unpacked/system.h>
#include <libsbp/unpacked/tracking.h>
#include <libsbp/unpacked/user.h>
#include <libsbp/unpacked/vehicle.h>

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
struct MessageTraits<sbp_msg_print_dep_t> {
  static constexpr u16 id = 16;
  static const sbp_msg_print_dep_t &get(const sbp_msg_t &msg) { return msg.MSG_PRINT_DEP; }
};



template<>
struct MessageTraits<sbp_msg_tracking_state_detailed_dep_t> {
  static constexpr u16 id = 17;
  static const sbp_msg_tracking_state_detailed_dep_t &get(const sbp_msg_t &msg) { return msg.MSG_TRACKING_STATE_DETAILED_DEP; }
};



template<>
struct MessageTraits<sbp_msg_tracking_state_dep_b_t> {
  static constexpr u16 id = 19;
  static const sbp_msg_tracking_state_dep_b_t &get(const sbp_msg_t &msg) { return msg.MSG_TRACKING_STATE_DEP_B; }
};



template<>
struct MessageTraits<sbp_msg_acq_result_dep_b_t> {
  static constexpr u16 id = 20;
  static const sbp_msg_acq_result_dep_b_t &get(const sbp_msg_t &msg) { return msg.MSG_ACQ_RESULT_DEP_B; }
};



template<>
struct MessageTraits<sbp_msg_acq_result_dep_a_t> {
  static constexpr u16 id = 21;
  static const sbp_msg_acq_result_dep_a_t &get(const sbp_msg_t &msg) { return msg.MSG_ACQ_RESULT_DEP_A; }
};



template<>
struct MessageTraits<sbp_msg_tracking_state_dep_a_t> {
  static constexpr u16 id = 22;
  static const sbp_msg_tracking_state_dep_a_t &get(const sbp_msg_t &msg) { return msg.MSG_TRACKING_STATE_DEP_A; }
};



template<>
struct MessageTraits<sbp_msg_thread_state_t> {
  static constexpr u16 id = 23;
  static const sbp_msg_thread_state_t &get(const sbp_msg_t &msg) { return msg.MSG_THREAD_STATE; }
};



template<>
struct MessageTraits<sbp_msg_uart_state_depa_t> {
  static constexpr u16 id = 24;
  static const sbp_msg_uart_state_depa_t &get(const sbp_msg_t &msg) { return msg.MSG_UART_STATE_DEPA; }
};



template<>
struct MessageTraits<sbp_msg_iar_state_t> {
  static constexpr u16 id = 25;
  static const sbp_msg_iar_state_t &get(const sbp_msg_t &msg) { return msg.MSG_IAR_STATE; }
};



template<>
struct MessageTraits<sbp_msg_ephemeris_dep_a_t> {
  static constexpr u16 id = 26;
  static const sbp_msg_ephemeris_dep_a_t &get(const sbp_msg_t &msg) { return msg.MSG_EPHEMERIS_DEP_A; }
};



template<>
struct MessageTraits<sbp_msg_mask_satellite_dep_t> {
  static constexpr u16 id = 27;
  static const sbp_msg_mask_satellite_dep_t &get(const sbp_msg_t &msg) { return msg.MSG_MASK_SATELLITE_DEP; }
};



template<>
struct MessageTraits<sbp_msg_tracking_iq_dep_a_t> {
  static constexpr u16 id = 28;
  static const sbp_msg_tracking_iq_dep_a_t &get(const sbp_msg_t &msg) { return msg.MSG_TRACKING_IQ_DEP_A; }
};



template<>
struct MessageTraits<sbp_msg_uart_state_t> {
  static constexpr u16 id = 29;
  static const sbp_msg_uart_state_t &get(const sbp_msg_t &msg) { return msg.MSG_UART_STATE; }
};



template<>
struct MessageTraits<sbp_msg_acq_sv_profile_dep_t> {
  static constexpr u16 id = 30;
  static const sbp_msg_acq_sv_profile_dep_t &get(const sbp_msg_t &msg) { return msg.MSG_ACQ_SV_PROFILE_DEP; }
};



template<>
struct MessageTraits<sbp_msg_acq_result_dep_c_t> {
  static constexpr u16 id = 31;
  static const sbp_msg_acq_result_dep_c_t &get(const sbp_msg_t &msg) { return msg.MSG_ACQ_RESULT_DEP_C; }
};



template<>
struct MessageTraits<sbp_msg_tracking_state_detailed_dep_a_t> {
  static constexpr u16 id = 33;
  static const sbp_msg_tracking_state_detailed_dep_a_t &get(const sbp_msg_t &msg) { return msg.MSG_TRACKING_STATE_DETAILED_DEP_A; }
};



template<>
struct MessageTraits<sbp_msg_reset_filters_t> {
  static constexpr u16 id = 34;
  static const sbp_msg_reset_filters_t &get(const sbp_msg_t &msg) { return msg.MSG_RESET_FILTERS; }
};



template<>
struct MessageTraits<sbp_msg_init_base_dep_t> {
  static constexpr u16 id = 35;
  static const sbp_msg_init_base_dep_t &get(const sbp_msg_t &msg) { return msg.MSG_INIT_BASE_DEP; }
};



template<>
struct MessageTraits<sbp_msg_mask_satellite_t> {
  static constexpr u16 id = 43;
  static const sbp_msg_mask_satellite_t &get(const sbp_msg_t &msg) { return msg.MSG_MASK_SATELLITE; }
};



template<>
struct MessageTraits<sbp_msg_tracking_iq_dep_b_t> {
  static constexpr u16 id = 44;
  static const sbp_msg_tracking_iq_dep_b_t &get(const sbp_msg_t &msg) { return msg.MSG_TRACKING_IQ_DEP_B; }
};



template<>
struct MessageTraits<sbp_msg_tracking_iq_t> {
  static constexpr u16 id = 45;
  static const sbp_msg_tracking_iq_t &get(const sbp_msg_t &msg) { return msg.MSG_TRACKING_IQ; }
};



template<>
struct MessageTraits<sbp_msg_acq_sv_profile_t> {
  static constexpr u16 id = 46;
  static const sbp_msg_acq_sv_profile_t &get(const sbp_msg_t &msg) { return msg.MSG_ACQ_SV_PROFILE; }
};



template<>
struct MessageTraits<sbp_msg_acq_result_t> {
  static constexpr u16 id = 47;
  static const sbp_msg_acq_result_t &get(const sbp_msg_t &msg) { return msg.MSG_ACQ_RESULT; }
};



template<>
struct MessageTraits<sbp_msg_tracking_state_t> {
  static constexpr u16 id = 65;
  static const sbp_msg_tracking_state_t &get(const sbp_msg_t &msg) { return msg.MSG_TRACKING_STATE; }
};



template<>
struct MessageTraits<sbp_msg_obs_dep_b_t> {
  static constexpr u16 id = 67;
  static const sbp_msg_obs_dep_b_t &get(const sbp_msg_t &msg) { return msg.MSG_OBS_DEP_B; }
};



template<>
struct MessageTraits<sbp_msg_base_pos_llh_t> {
  static constexpr u16 id = 68;
  static const sbp_msg_base_pos_llh_t &get(const sbp_msg_t &msg) { return msg.MSG_BASE_POS_LLH; }
};



template<>
struct MessageTraits<sbp_msg_obs_dep_a_t> {
  static constexpr u16 id = 69;
  static const sbp_msg_obs_dep_a_t &get(const sbp_msg_t &msg) { return msg.MSG_OBS_DEP_A; }
};



template<>
struct MessageTraits<sbp_msg_ephemeris_dep_b_t> {
  static constexpr u16 id = 70;
  static const sbp_msg_ephemeris_dep_b_t &get(const sbp_msg_t &msg) { return msg.MSG_EPHEMERIS_DEP_B; }
};



template<>
struct MessageTraits<sbp_msg_ephemeris_dep_c_t> {
  static constexpr u16 id = 71;
  static const sbp_msg_ephemeris_dep_c_t &get(const sbp_msg_t &msg) { return msg.MSG_EPHEMERIS_DEP_C; }
};



template<>
struct MessageTraits<sbp_msg_base_pos_ecef_t> {
  static constexpr u16 id = 72;
  static const sbp_msg_base_pos_ecef_t &get(const sbp_msg_t &msg) { return msg.MSG_BASE_POS_ECEF; }
};



template<>
struct MessageTraits<sbp_msg_obs_dep_c_t> {
  static constexpr u16 id = 73;
  static const sbp_msg_obs_dep_c_t &get(const sbp_msg_t &msg) { return msg.MSG_OBS_DEP_C; }
};



template<>
struct MessageTraits<sbp_msg_obs_t> {
  static constexpr u16 id = 74;
  static const sbp_msg_obs_t &get(const sbp_msg_t &msg) { return msg.MSG_OBS; }
};



template<>
struct MessageTraits<sbp_msg_specan_dep_t> {
  static constexpr u16 id = 80;
  static const sbp_msg_specan_dep_t &get(const sbp_msg_t &msg) { return msg.MSG_SPECAN_DEP; }
};



template<>
struct MessageTraits<sbp_msg_specan_t> {
  static constexpr u16 id = 81;
  static const sbp_msg_specan_t &get(const sbp_msg_t &msg) { return msg.MSG_SPECAN; }
};



template<>
struct MessageTraits<sbp_msg_measurement_state_t> {
  static constexpr u16 id = 97;
  static const sbp_msg_measurement_state_t &get(const sbp_msg_t &msg) { return msg.MSG_MEASUREMENT_STATE; }
};



template<>
struct MessageTraits<sbp_msg_set_time_t> {
  static constexpr u16 id = 104;
  static const sbp_msg_set_time_t &get(const sbp_msg_t &msg) { return msg.MSG_SET_TIME; }
};



template<>
struct MessageTraits<sbp_msg_almanac_t> {
  static constexpr u16 id = 105;
  static const sbp_msg_almanac_t &get(const sbp_msg_t &msg) { return msg.MSG_ALMANAC; }
};



template<>
struct MessageTraits<sbp_msg_almanac_gps_dep_t> {
  static constexpr u16 id = 112;
  static const sbp_msg_almanac_gps_dep_t &get(const sbp_msg_t &msg) { return msg.MSG_ALMANAC_GPS_DEP; }
};



template<>
struct MessageTraits<sbp_msg_almanac_glo_dep_t> {
  static constexpr u16 id = 113;
  static const sbp_msg_almanac_glo_dep_t &get(const sbp_msg_t &msg) { return msg.MSG_ALMANAC_GLO_DEP; }
};



template<>
struct MessageTraits<sbp_msg_almanac_gps_t> {
  static constexpr u16 id = 114;
  static const sbp_msg_almanac_gps_t &get(const sbp_msg_t &msg) { return msg.MSG_ALMANAC_GPS; }
};



template<>
struct MessageTraits<sbp_msg_almanac_glo_t> {
  static constexpr u16 id = 115;
  static const sbp_msg_almanac_glo_t &get(const sbp_msg_t &msg) { return msg.MSG_ALMANAC_GLO; }
};



template<>
struct MessageTraits<sbp_msg_glo_biases_t> {
  static constexpr u16 id = 117;
  static const sbp_msg_glo_biases_t &get(const sbp_msg_t &msg) { return msg.MSG_GLO_BIASES; }
};



template<>
struct MessageTraits<sbp_msg_ephemeris_dep_d_t> {
  static constexpr u16 id = 128;
  static const sbp_msg_ephemeris_dep_d_t &get(const sbp_msg_t &msg) { return msg.MSG_EPHEMERIS_DEP_D; }
};



template<>
struct MessageTraits<sbp_msg_ephemeris_gps_dep_e_t> {
  static constexpr u16 id = 129;
  static const sbp_msg_ephemeris_gps_dep_e_t &get(const sbp_msg_t &msg) { return msg.MSG_EPHEMERIS_GPS_DEP_E; }
};



template<>
struct MessageTraits<sbp_msg_ephemeris_sbas_dep_a_t> {
  static constexpr u16 id = 130;
  static const sbp_msg_ephemeris_sbas_dep_a_t &get(const sbp_msg_t &msg) { return msg.MSG_EPHEMERIS_SBAS_DEP_A; }
};



template<>
struct MessageTraits<sbp_msg_ephemeris_glo_dep_a_t> {
  static constexpr u16 id = 131;
  static const sbp_msg_ephemeris_glo_dep_a_t &get(const sbp_msg_t &msg) { return msg.MSG_EPHEMERIS_GLO_DEP_A; }
};



template<>
struct MessageTraits<sbp_msg_ephemeris_sbas_dep_b_t> {
  static constexpr u16 id = 132;
  static const sbp_msg_ephemeris_sbas_dep_b_t &get(const sbp_msg_t &msg) { return msg.MSG_EPHEMERIS_SBAS_DEP_B; }
};



template<>
struct MessageTraits<sbp_msg_ephemeris_glo_dep_b_t> {
  static constexpr u16 id = 133;
  static const sbp_msg_ephemeris_glo_dep_b_t &get(const sbp_msg_t &msg) { return msg.MSG_EPHEMERIS_GLO_DEP_B; }
};



template<>
struct MessageTraits<sbp_msg_ephemeris_gps_dep_f_t> {
  static constexpr u16 id = 134;
  static const sbp_msg_ephemeris_gps_dep_f_t &get(const sbp_msg_t &msg) { return msg.MSG_EPHEMERIS_GPS_DEP_F; }
};



template<>
struct MessageTraits<sbp_msg_ephemeris_glo_dep_c_t> {
  static constexpr u16 id = 135;
  static const sbp_msg_ephemeris_glo_dep_c_t &get(const sbp_msg_t &msg) { return msg.MSG_EPHEMERIS_GLO_DEP_C; }
};



template<>
struct MessageTraits<sbp_msg_ephemeris_glo_dep_d_t> {
  static constexpr u16 id = 136;
  static const sbp_msg_ephemeris_glo_dep_d_t &get(const sbp_msg_t &msg) { return msg.MSG_EPHEMERIS_GLO_DEP_D; }
};



template<>
struct MessageTraits<sbp_msg_ephemeris_bds_t> {
  static constexpr u16 id = 137;
  static const sbp_msg_ephemeris_bds_t &get(const sbp_msg_t &msg) { return msg.MSG_EPHEMERIS_BDS; }
};



template<>
struct MessageTraits<sbp_msg_ephemeris_gps_t> {
  static constexpr u16 id = 138;
  static const sbp_msg_ephemeris_gps_t &get(const sbp_msg_t &msg) { return msg.MSG_EPHEMERIS_GPS; }
};



template<>
struct MessageTraits<sbp_msg_ephemeris_glo_t> {
  static constexpr u16 id = 139;
  static const sbp_msg_ephemeris_glo_t &get(const sbp_msg_t &msg) { return msg.MSG_EPHEMERIS_GLO; }
};



template<>
struct MessageTraits<sbp_msg_ephemeris_sbas_t> {
  static constexpr u16 id = 140;
  static const sbp_msg_ephemeris_sbas_t &get(const sbp_msg_t &msg) { return msg.MSG_EPHEMERIS_SBAS; }
};



template<>
struct MessageTraits<sbp_msg_ephemeris_gal_t> {
  static constexpr u16 id = 141;
  static const sbp_msg_ephemeris_gal_t &get(const sbp_msg_t &msg) { return msg.MSG_EPHEMERIS_GAL; }
};



template<>
struct MessageTraits<sbp_msg_ephemeris_qzss_t> {
  static constexpr u16 id = 142;
  static const sbp_msg_ephemeris_qzss_t &get(const sbp_msg_t &msg) { return msg.MSG_EPHEMERIS_QZSS; }
};



template<>
struct MessageTraits<sbp_msg_iono_t> {
  static constexpr u16 id = 144;
  static const sbp_msg_iono_t &get(const sbp_msg_t &msg) { return msg.MSG_IONO; }
};



template<>
struct MessageTraits<sbp_msg_sv_configuration_gps_dep_t> {
  static constexpr u16 id = 145;
  static const sbp_msg_sv_configuration_gps_dep_t &get(const sbp_msg_t &msg) { return msg.MSG_SV_CONFIGURATION_GPS_DEP; }
};



template<>
struct MessageTraits<sbp_msg_group_delay_dep_a_t> {
  static constexpr u16 id = 146;
  static const sbp_msg_group_delay_dep_a_t &get(const sbp_msg_t &msg) { return msg.MSG_GROUP_DELAY_DEP_A; }
};



template<>
struct MessageTraits<sbp_msg_group_delay_dep_b_t> {
  static constexpr u16 id = 147;
  static const sbp_msg_group_delay_dep_b_t &get(const sbp_msg_t &msg) { return msg.MSG_GROUP_DELAY_DEP_B; }
};



template<>
struct MessageTraits<sbp_msg_group_delay_t> {
  static constexpr u16 id = 148;
  static const sbp_msg_group_delay_t &get(const sbp_msg_t &msg) { return msg.MSG_GROUP_DELAY; }
};



template<>
struct MessageTraits<sbp_msg_ephemeris_gal_dep_a_t> {
  static constexpr u16 id = 149;
  static const sbp_msg_ephemeris_gal_dep_a_t &get(const sbp_msg_t &msg) { return msg.MSG_EPHEMERIS_GAL_DEP_A; }
};



template<>
struct MessageTraits<sbp_msg_gnss_capb_t> {
  static constexpr u16 id = 150;
  static const sbp_msg_gnss_capb_t &get(const sbp_msg_t &msg) { return msg.MSG_GNSS_CAPB; }
};



template<>
struct MessageTraits<sbp_msg_sv_az_el_t> {
  static constexpr u16 id = 151;
  static const sbp_msg_sv_az_el_t &get(const sbp_msg_t &msg) { return msg.MSG_SV_AZ_EL; }
};



template<>
struct MessageTraits<sbp_msg_settings_write_t> {
  static constexpr u16 id = 160;
  static const sbp_msg_settings_write_t &get(const sbp_msg_t &msg) { return msg.MSG_SETTINGS_WRITE; }
};



template<>
struct MessageTraits<sbp_msg_settings_save_t> {
  static constexpr u16 id = 161;
  static const sbp_msg_settings_save_t &get(const sbp_msg_t &msg) { return msg.MSG_SETTINGS_SAVE; }
};



template<>
struct MessageTraits<sbp_msg_settings_read_by_index_req_t> {
  static constexpr u16 id = 162;
  static const sbp_msg_settings_read_by_index_req_t &get(const sbp_msg_t &msg) { return msg.MSG_SETTINGS_READ_BY_INDEX_REQ; }
};



template<>
struct MessageTraits<sbp_msg_fileio_read_resp_t> {
  static constexpr u16 id = 163;
  static const sbp_msg_fileio_read_resp_t &get(const sbp_msg_t &msg) { return msg.MSG_FILEIO_READ_RESP; }
};



template<>
struct MessageTraits<sbp_msg_settings_read_req_t> {
  static constexpr u16 id = 164;
  static const sbp_msg_settings_read_req_t &get(const sbp_msg_t &msg) { return msg.MSG_SETTINGS_READ_REQ; }
};



template<>
struct MessageTraits<sbp_msg_settings_read_resp_t> {
  static constexpr u16 id = 165;
  static const sbp_msg_settings_read_resp_t &get(const sbp_msg_t &msg) { return msg.MSG_SETTINGS_READ_RESP; }
};



template<>
struct MessageTraits<sbp_msg_settings_read_by_index_done_t> {
  static constexpr u16 id = 166;
  static const sbp_msg_settings_read_by_index_done_t &get(const sbp_msg_t &msg) { return msg.MSG_SETTINGS_READ_BY_INDEX_DONE; }
};



template<>
struct MessageTraits<sbp_msg_settings_read_by_index_resp_t> {
  static constexpr u16 id = 167;
  static const sbp_msg_settings_read_by_index_resp_t &get(const sbp_msg_t &msg) { return msg.MSG_SETTINGS_READ_BY_INDEX_RESP; }
};



template<>
struct MessageTraits<sbp_msg_fileio_read_req_t> {
  static constexpr u16 id = 168;
  static const sbp_msg_fileio_read_req_t &get(const sbp_msg_t &msg) { return msg.MSG_FILEIO_READ_REQ; }
};



template<>
struct MessageTraits<sbp_msg_fileio_read_dir_req_t> {
  static constexpr u16 id = 169;
  static const sbp_msg_fileio_read_dir_req_t &get(const sbp_msg_t &msg) { return msg.MSG_FILEIO_READ_DIR_REQ; }
};



template<>
struct MessageTraits<sbp_msg_fileio_read_dir_resp_t> {
  static constexpr u16 id = 170;
  static const sbp_msg_fileio_read_dir_resp_t &get(const sbp_msg_t &msg) { return msg.MSG_FILEIO_READ_DIR_RESP; }
};



template<>
struct MessageTraits<sbp_msg_fileio_write_resp_t> {
  static constexpr u16 id = 171;
  static const sbp_msg_fileio_write_resp_t &get(const sbp_msg_t &msg) { return msg.MSG_FILEIO_WRITE_RESP; }
};



template<>
struct MessageTraits<sbp_msg_fileio_remove_t> {
  static constexpr u16 id = 172;
  static const sbp_msg_fileio_remove_t &get(const sbp_msg_t &msg) { return msg.MSG_FILEIO_REMOVE; }
};



template<>
struct MessageTraits<sbp_msg_fileio_write_req_t> {
  static constexpr u16 id = 173;
  static const sbp_msg_fileio_write_req_t &get(const sbp_msg_t &msg) { return msg.MSG_FILEIO_WRITE_REQ; }
};



template<>
struct MessageTraits<sbp_msg_settings_register_t> {
  static constexpr u16 id = 174;
  static const sbp_msg_settings_register_t &get(const sbp_msg_t &msg) { return msg.MSG_SETTINGS_REGISTER; }
};



template<>
struct MessageTraits<sbp_msg_settings_write_resp_t> {
  static constexpr u16 id = 175;
  static const sbp_msg_settings_write_resp_t &get(const sbp_msg_t &msg) { return msg.MSG_SETTINGS_WRITE_RESP; }
};



template<>
struct MessageTraits<sbp_msg_bootloader_handshake_dep_a_t> {
  static constexpr u16 id = 176;
  static const sbp_msg_bootloader_handshake_dep_a_t &get(const sbp_msg_t &msg) { return msg.MSG_BOOTLOADER_HANDSHAKE_DEP_A; }
};



template<>
struct MessageTraits<sbp_msg_bootloader_jump_to_app_t> {
  static constexpr u16 id = 177;
  static const sbp_msg_bootloader_jump_to_app_t &get(const sbp_msg_t &msg) { return msg.MSG_BOOTLOADER_JUMP_TO_APP; }
};



template<>
struct MessageTraits<sbp_msg_reset_dep_t> {
  static constexpr u16 id = 178;
  static const sbp_msg_reset_dep_t &get(const sbp_msg_t &msg) { return msg.MSG_RESET_DEP; }
};



template<>
struct MessageTraits<sbp_msg_bootloader_handshake_req_t> {
  static constexpr u16 id = 179;
  static const sbp_msg_bootloader_handshake_req_t &get(const sbp_msg_t &msg) { return msg.MSG_BOOTLOADER_HANDSHAKE_REQ; }
};



template<>
struct MessageTraits<sbp_msg_bootloader_handshake_resp_t> {
  static constexpr u16 id = 180;
  static const sbp_msg_bootloader_handshake_resp_t &get(const sbp_msg_t &msg) { return msg.MSG_BOOTLOADER_HANDSHAKE_RESP; }
};



template<>
struct MessageTraits<sbp_msg_device_monitor_t> {
  static constexpr u16 id = 181;
  static const sbp_msg_device_monitor_t &get(const sbp_msg_t &msg) { return msg.MSG_DEVICE_MONITOR; }
};



template<>
struct MessageTraits<sbp_msg_reset_t> {
  static constexpr u16 id = 182;
  static const sbp_msg_reset_t &get(const sbp_msg_t &msg) { return msg.MSG_RESET; }
};



template<>
struct MessageTraits<sbp_msg_command_req_t> {
  static constexpr u16 id = 184;
  static const sbp_msg_command_req_t &get(const sbp_msg_t &msg) { return msg.MSG_COMMAND_REQ; }
};



template<>
struct MessageTraits<sbp_msg_command_resp_t> {
  static constexpr u16 id = 185;
  static const sbp_msg_command_resp_t &get(const sbp_msg_t &msg) { return msg.MSG_COMMAND_RESP; }
};



template<>
struct MessageTraits<sbp_msg_network_state_req_t> {
  static constexpr u16 id = 186;
  static const sbp_msg_network_state_req_t &get(const sbp_msg_t &msg) { return msg.MSG_NETWORK_STATE_REQ; }
};



template<>
struct MessageTraits<sbp_msg_network_state_resp_t> {
  static constexpr u16 id = 187;
  static const sbp_msg_network_state_resp_t &get(const sbp_msg_t &msg) { return msg.MSG_NETWORK_STATE_RESP; }
};



template<>
struct MessageTraits<sbp_msg_command_output_t> {
  static constexpr u16 id = 188;
  static const sbp_msg_command_output_t &get(const sbp_msg_t &msg) { return msg.MSG_COMMAND_OUTPUT; }
};



template<>
struct MessageTraits<sbp_msg_network_bandwidth_usage_t> {
  static constexpr u16 id = 189;
  static const sbp_msg_network_bandwidth_usage_t &get(const sbp_msg_t &msg) { return msg.MSG_NETWORK_BANDWIDTH_USAGE; }
};



template<>
struct MessageTraits<sbp_msg_cell_modem_status_t> {
  static constexpr u16 id = 190;
  static const sbp_msg_cell_modem_status_t &get(const sbp_msg_t &msg) { return msg.MSG_CELL_MODEM_STATUS; }
};



template<>
struct MessageTraits<sbp_msg_front_end_gain_t> {
  static constexpr u16 id = 191;
  static const sbp_msg_front_end_gain_t &get(const sbp_msg_t &msg) { return msg.MSG_FRONT_END_GAIN; }
};



template<>
struct MessageTraits<sbp_msg_cw_results_t> {
  static constexpr u16 id = 192;
  static const sbp_msg_cw_results_t &get(const sbp_msg_t &msg) { return msg.MSG_CW_RESULTS; }
};



template<>
struct MessageTraits<sbp_msg_cw_start_t> {
  static constexpr u16 id = 193;
  static const sbp_msg_cw_start_t &get(const sbp_msg_t &msg) { return msg.MSG_CW_START; }
};



template<>
struct MessageTraits<sbp_msg_nap_device_dna_resp_t> {
  static constexpr u16 id = 221;
  static const sbp_msg_nap_device_dna_resp_t &get(const sbp_msg_t &msg) { return msg.MSG_NAP_DEVICE_DNA_RESP; }
};



template<>
struct MessageTraits<sbp_msg_nap_device_dna_req_t> {
  static constexpr u16 id = 222;
  static const sbp_msg_nap_device_dna_req_t &get(const sbp_msg_t &msg) { return msg.MSG_NAP_DEVICE_DNA_REQ; }
};



template<>
struct MessageTraits<sbp_msg_flash_done_t> {
  static constexpr u16 id = 224;
  static const sbp_msg_flash_done_t &get(const sbp_msg_t &msg) { return msg.MSG_FLASH_DONE; }
};



template<>
struct MessageTraits<sbp_msg_flash_read_resp_t> {
  static constexpr u16 id = 225;
  static const sbp_msg_flash_read_resp_t &get(const sbp_msg_t &msg) { return msg.MSG_FLASH_READ_RESP; }
};



template<>
struct MessageTraits<sbp_msg_flash_erase_t> {
  static constexpr u16 id = 226;
  static const sbp_msg_flash_erase_t &get(const sbp_msg_t &msg) { return msg.MSG_FLASH_ERASE; }
};



template<>
struct MessageTraits<sbp_msg_stm_flash_lock_sector_t> {
  static constexpr u16 id = 227;
  static const sbp_msg_stm_flash_lock_sector_t &get(const sbp_msg_t &msg) { return msg.MSG_STM_FLASH_LOCK_SECTOR; }
};



template<>
struct MessageTraits<sbp_msg_stm_flash_unlock_sector_t> {
  static constexpr u16 id = 228;
  static const sbp_msg_stm_flash_unlock_sector_t &get(const sbp_msg_t &msg) { return msg.MSG_STM_FLASH_UNLOCK_SECTOR; }
};



template<>
struct MessageTraits<sbp_msg_stm_unique_id_resp_t> {
  static constexpr u16 id = 229;
  static const sbp_msg_stm_unique_id_resp_t &get(const sbp_msg_t &msg) { return msg.MSG_STM_UNIQUE_ID_RESP; }
};



template<>
struct MessageTraits<sbp_msg_flash_program_t> {
  static constexpr u16 id = 230;
  static const sbp_msg_flash_program_t &get(const sbp_msg_t &msg) { return msg.MSG_FLASH_PROGRAM; }
};



template<>
struct MessageTraits<sbp_msg_flash_read_req_t> {
  static constexpr u16 id = 231;
  static const sbp_msg_flash_read_req_t &get(const sbp_msg_t &msg) { return msg.MSG_FLASH_READ_REQ; }
};



template<>
struct MessageTraits<sbp_msg_stm_unique_id_req_t> {
  static constexpr u16 id = 232;
  static const sbp_msg_stm_unique_id_req_t &get(const sbp_msg_t &msg) { return msg.MSG_STM_UNIQUE_ID_REQ; }
};



template<>
struct MessageTraits<sbp_msg_m25_flash_write_status_t> {
  static constexpr u16 id = 243;
  static const sbp_msg_m25_flash_write_status_t &get(const sbp_msg_t &msg) { return msg.MSG_M25_FLASH_WRITE_STATUS; }
};



template<>
struct MessageTraits<sbp_msg_gps_time_dep_a_t> {
  static constexpr u16 id = 256;
  static const sbp_msg_gps_time_dep_a_t &get(const sbp_msg_t &msg) { return msg.MSG_GPS_TIME_DEP_A; }
};



template<>
struct MessageTraits<sbp_msg_ext_event_t> {
  static constexpr u16 id = 257;
  static const sbp_msg_ext_event_t &get(const sbp_msg_t &msg) { return msg.MSG_EXT_EVENT; }
};



template<>
struct MessageTraits<sbp_msg_gps_time_t> {
  static constexpr u16 id = 258;
  static const sbp_msg_gps_time_t &get(const sbp_msg_t &msg) { return msg.MSG_GPS_TIME; }
};



template<>
struct MessageTraits<sbp_msg_utc_time_t> {
  static constexpr u16 id = 259;
  static const sbp_msg_utc_time_t &get(const sbp_msg_t &msg) { return msg.MSG_UTC_TIME; }
};



template<>
struct MessageTraits<sbp_msg_gps_time_gnss_t> {
  static constexpr u16 id = 260;
  static const sbp_msg_gps_time_gnss_t &get(const sbp_msg_t &msg) { return msg.MSG_GPS_TIME_GNSS; }
};



template<>
struct MessageTraits<sbp_msg_utc_time_gnss_t> {
  static constexpr u16 id = 261;
  static const sbp_msg_utc_time_gnss_t &get(const sbp_msg_t &msg) { return msg.MSG_UTC_TIME_GNSS; }
};



template<>
struct MessageTraits<sbp_msg_settings_register_resp_t> {
  static constexpr u16 id = 431;
  static const sbp_msg_settings_register_resp_t &get(const sbp_msg_t &msg) { return msg.MSG_SETTINGS_REGISTER_RESP; }
};



template<>
struct MessageTraits<sbp_msg_pos_ecef_dep_a_t> {
  static constexpr u16 id = 512;
  static const sbp_msg_pos_ecef_dep_a_t &get(const sbp_msg_t &msg) { return msg.MSG_POS_ECEF_DEP_A; }
};



template<>
struct MessageTraits<sbp_msg_pos_llh_dep_a_t> {
  static constexpr u16 id = 513;
  static const sbp_msg_pos_llh_dep_a_t &get(const sbp_msg_t &msg) { return msg.MSG_POS_LLH_DEP_A; }
};



template<>
struct MessageTraits<sbp_msg_baseline_ecef_dep_a_t> {
  static constexpr u16 id = 514;
  static const sbp_msg_baseline_ecef_dep_a_t &get(const sbp_msg_t &msg) { return msg.MSG_BASELINE_ECEF_DEP_A; }
};



template<>
struct MessageTraits<sbp_msg_baseline_ned_dep_a_t> {
  static constexpr u16 id = 515;
  static const sbp_msg_baseline_ned_dep_a_t &get(const sbp_msg_t &msg) { return msg.MSG_BASELINE_NED_DEP_A; }
};



template<>
struct MessageTraits<sbp_msg_vel_ecef_dep_a_t> {
  static constexpr u16 id = 516;
  static const sbp_msg_vel_ecef_dep_a_t &get(const sbp_msg_t &msg) { return msg.MSG_VEL_ECEF_DEP_A; }
};



template<>
struct MessageTraits<sbp_msg_vel_ned_dep_a_t> {
  static constexpr u16 id = 517;
  static const sbp_msg_vel_ned_dep_a_t &get(const sbp_msg_t &msg) { return msg.MSG_VEL_NED_DEP_A; }
};



template<>
struct MessageTraits<sbp_msg_dops_dep_a_t> {
  static constexpr u16 id = 518;
  static const sbp_msg_dops_dep_a_t &get(const sbp_msg_t &msg) { return msg.MSG_DOPS_DEP_A; }
};



template<>
struct MessageTraits<sbp_msg_baseline_heading_dep_a_t> {
  static constexpr u16 id = 519;
  static const sbp_msg_baseline_heading_dep_a_t &get(const sbp_msg_t &msg) { return msg.MSG_BASELINE_HEADING_DEP_A; }
};



template<>
struct MessageTraits<sbp_msg_dops_t> {
  static constexpr u16 id = 520;
  static const sbp_msg_dops_t &get(const sbp_msg_t &msg) { return msg.MSG_DOPS; }
};



template<>
struct MessageTraits<sbp_msg_pos_ecef_t> {
  static constexpr u16 id = 521;
  static const sbp_msg_pos_ecef_t &get(const sbp_msg_t &msg) { return msg.MSG_POS_ECEF; }
};



template<>
struct MessageTraits<sbp_msg_pos_llh_t> {
  static constexpr u16 id = 522;
  static const sbp_msg_pos_llh_t &get(const sbp_msg_t &msg) { return msg.MSG_POS_LLH; }
};



template<>
struct MessageTraits<sbp_msg_baseline_ecef_t> {
  static constexpr u16 id = 523;
  static const sbp_msg_baseline_ecef_t &get(const sbp_msg_t &msg) { return msg.MSG_BASELINE_ECEF; }
};



template<>
struct MessageTraits<sbp_msg_baseline_ned_t> {
  static constexpr u16 id = 524;
  static const sbp_msg_baseline_ned_t &get(const sbp_msg_t &msg) { return msg.MSG_BASELINE_NED; }
};



template<>
struct MessageTraits<sbp_msg_vel_ecef_t> {
  static constexpr u16 id = 525;
  static const sbp_msg_vel_ecef_t &get(const sbp_msg_t &msg) { return msg.MSG_VEL_ECEF; }
};



template<>
struct MessageTraits<sbp_msg_vel_ned_t> {
  static constexpr u16 id = 526;
  static const sbp_msg_vel_ned_t &get(const sbp_msg_t &msg) { return msg.MSG_VEL_NED; }
};



template<>
struct MessageTraits<sbp_msg_baseline_heading_t> {
  static constexpr u16 id = 527;
  static const sbp_msg_baseline_heading_t &get(const sbp_msg_t &msg) { return msg.MSG_BASELINE_HEADING; }
};



template<>
struct MessageTraits<sbp_msg_age_corrections_t> {
  static constexpr u16 id = 528;
  static const sbp_msg_age_corrections_t &get(const sbp_msg_t &msg) { return msg.MSG_AGE_CORRECTIONS; }
};



template<>
struct MessageTraits<sbp_msg_pos_llh_cov_t> {
  static constexpr u16 id = 529;
  static const sbp_msg_pos_llh_cov_t &get(const sbp_msg_t &msg) { return msg.MSG_POS_LLH_COV; }
};



template<>
struct MessageTraits<sbp_msg_vel_ned_cov_t> {
  static constexpr u16 id = 530;
  static const sbp_msg_vel_ned_cov_t &get(const sbp_msg_t &msg) { return msg.MSG_VEL_NED_COV; }
};



template<>
struct MessageTraits<sbp_msg_vel_body_t> {
  static constexpr u16 id = 531;
  static const sbp_msg_vel_body_t &get(const sbp_msg_t &msg) { return msg.MSG_VEL_BODY; }
};



template<>
struct MessageTraits<sbp_msg_pos_ecef_cov_t> {
  static constexpr u16 id = 532;
  static const sbp_msg_pos_ecef_cov_t &get(const sbp_msg_t &msg) { return msg.MSG_POS_ECEF_COV; }
};



template<>
struct MessageTraits<sbp_msg_vel_ecef_cov_t> {
  static constexpr u16 id = 533;
  static const sbp_msg_vel_ecef_cov_t &get(const sbp_msg_t &msg) { return msg.MSG_VEL_ECEF_COV; }
};



template<>
struct MessageTraits<sbp_msg_protection_level_dep_a_t> {
  static constexpr u16 id = 534;
  static const sbp_msg_protection_level_dep_a_t &get(const sbp_msg_t &msg) { return msg.MSG_PROTECTION_LEVEL_DEP_A; }
};



template<>
struct MessageTraits<sbp_msg_protection_level_t> {
  static constexpr u16 id = 535;
  static const sbp_msg_protection_level_t &get(const sbp_msg_t &msg) { return msg.MSG_PROTECTION_LEVEL; }
};



template<>
struct MessageTraits<sbp_msg_orient_quat_t> {
  static constexpr u16 id = 544;
  static const sbp_msg_orient_quat_t &get(const sbp_msg_t &msg) { return msg.MSG_ORIENT_QUAT; }
};



template<>
struct MessageTraits<sbp_msg_orient_euler_t> {
  static constexpr u16 id = 545;
  static const sbp_msg_orient_euler_t &get(const sbp_msg_t &msg) { return msg.MSG_ORIENT_EULER; }
};



template<>
struct MessageTraits<sbp_msg_angular_rate_t> {
  static constexpr u16 id = 546;
  static const sbp_msg_angular_rate_t &get(const sbp_msg_t &msg) { return msg.MSG_ANGULAR_RATE; }
};



template<>
struct MessageTraits<sbp_msg_pos_ecef_gnss_t> {
  static constexpr u16 id = 553;
  static const sbp_msg_pos_ecef_gnss_t &get(const sbp_msg_t &msg) { return msg.MSG_POS_ECEF_GNSS; }
};



template<>
struct MessageTraits<sbp_msg_pos_llh_gnss_t> {
  static constexpr u16 id = 554;
  static const sbp_msg_pos_llh_gnss_t &get(const sbp_msg_t &msg) { return msg.MSG_POS_LLH_GNSS; }
};



template<>
struct MessageTraits<sbp_msg_vel_ecef_gnss_t> {
  static constexpr u16 id = 557;
  static const sbp_msg_vel_ecef_gnss_t &get(const sbp_msg_t &msg) { return msg.MSG_VEL_ECEF_GNSS; }
};



template<>
struct MessageTraits<sbp_msg_vel_ned_gnss_t> {
  static constexpr u16 id = 558;
  static const sbp_msg_vel_ned_gnss_t &get(const sbp_msg_t &msg) { return msg.MSG_VEL_NED_GNSS; }
};



template<>
struct MessageTraits<sbp_msg_pos_llh_cov_gnss_t> {
  static constexpr u16 id = 561;
  static const sbp_msg_pos_llh_cov_gnss_t &get(const sbp_msg_t &msg) { return msg.MSG_POS_LLH_COV_GNSS; }
};



template<>
struct MessageTraits<sbp_msg_vel_ned_cov_gnss_t> {
  static constexpr u16 id = 562;
  static const sbp_msg_vel_ned_cov_gnss_t &get(const sbp_msg_t &msg) { return msg.MSG_VEL_NED_COV_GNSS; }
};



template<>
struct MessageTraits<sbp_msg_pos_ecef_cov_gnss_t> {
  static constexpr u16 id = 564;
  static const sbp_msg_pos_ecef_cov_gnss_t &get(const sbp_msg_t &msg) { return msg.MSG_POS_ECEF_COV_GNSS; }
};



template<>
struct MessageTraits<sbp_msg_vel_ecef_cov_gnss_t> {
  static constexpr u16 id = 565;
  static const sbp_msg_vel_ecef_cov_gnss_t &get(const sbp_msg_t &msg) { return msg.MSG_VEL_ECEF_COV_GNSS; }
};



template<>
struct MessageTraits<sbp_msg_ndb_event_t> {
  static constexpr u16 id = 1024;
  static const sbp_msg_ndb_event_t &get(const sbp_msg_t &msg) { return msg.MSG_NDB_EVENT; }
};



template<>
struct MessageTraits<sbp_msg_log_t> {
  static constexpr u16 id = 1025;
  static const sbp_msg_log_t &get(const sbp_msg_t &msg) { return msg.MSG_LOG; }
};



template<>
struct MessageTraits<sbp_msg_fwd_t> {
  static constexpr u16 id = 1026;
  static const sbp_msg_fwd_t &get(const sbp_msg_t &msg) { return msg.MSG_FWD; }
};



template<>
struct MessageTraits<sbp_msg_ssr_orbit_clock_dep_a_t> {
  static constexpr u16 id = 1500;
  static const sbp_msg_ssr_orbit_clock_dep_a_t &get(const sbp_msg_t &msg) { return msg.MSG_SSR_ORBIT_CLOCK_DEP_A; }
};



template<>
struct MessageTraits<sbp_msg_ssr_orbit_clock_t> {
  static constexpr u16 id = 1501;
  static const sbp_msg_ssr_orbit_clock_t &get(const sbp_msg_t &msg) { return msg.MSG_SSR_ORBIT_CLOCK; }
};



template<>
struct MessageTraits<sbp_msg_ssr_code_biases_t> {
  static constexpr u16 id = 1505;
  static const sbp_msg_ssr_code_biases_t &get(const sbp_msg_t &msg) { return msg.MSG_SSR_CODE_BIASES; }
};



template<>
struct MessageTraits<sbp_msg_ssr_phase_biases_t> {
  static constexpr u16 id = 1510;
  static const sbp_msg_ssr_phase_biases_t &get(const sbp_msg_t &msg) { return msg.MSG_SSR_PHASE_BIASES; }
};



template<>
struct MessageTraits<sbp_msg_ssr_stec_correction_dep_a_t> {
  static constexpr u16 id = 1515;
  static const sbp_msg_ssr_stec_correction_dep_a_t &get(const sbp_msg_t &msg) { return msg.MSG_SSR_STEC_CORRECTION_DEP_A; }
};



template<>
struct MessageTraits<sbp_msg_ssr_gridded_correction_no_std_dep_a_t> {
  static constexpr u16 id = 1520;
  static const sbp_msg_ssr_gridded_correction_no_std_dep_a_t &get(const sbp_msg_t &msg) { return msg.MSG_SSR_GRIDDED_CORRECTION_NO_STD_DEP_A; }
};



template<>
struct MessageTraits<sbp_msg_ssr_grid_definition_dep_a_t> {
  static constexpr u16 id = 1525;
  static const sbp_msg_ssr_grid_definition_dep_a_t &get(const sbp_msg_t &msg) { return msg.MSG_SSR_GRID_DEFINITION_DEP_A; }
};



template<>
struct MessageTraits<sbp_msg_ssr_tile_definition_t> {
  static constexpr u16 id = 1526;
  static const sbp_msg_ssr_tile_definition_t &get(const sbp_msg_t &msg) { return msg.MSG_SSR_TILE_DEFINITION; }
};



template<>
struct MessageTraits<sbp_msg_ssr_gridded_correction_dep_a_t> {
  static constexpr u16 id = 1530;
  static const sbp_msg_ssr_gridded_correction_dep_a_t &get(const sbp_msg_t &msg) { return msg.MSG_SSR_GRIDDED_CORRECTION_DEP_A; }
};



template<>
struct MessageTraits<sbp_msg_ssr_stec_correction_t> {
  static constexpr u16 id = 1531;
  static const sbp_msg_ssr_stec_correction_t &get(const sbp_msg_t &msg) { return msg.MSG_SSR_STEC_CORRECTION; }
};



template<>
struct MessageTraits<sbp_msg_ssr_gridded_correction_t> {
  static constexpr u16 id = 1532;
  static const sbp_msg_ssr_gridded_correction_t &get(const sbp_msg_t &msg) { return msg.MSG_SSR_GRIDDED_CORRECTION; }
};



template<>
struct MessageTraits<sbp_msg_ssr_satellite_apc_t> {
  static constexpr u16 id = 1540;
  static const sbp_msg_ssr_satellite_apc_t &get(const sbp_msg_t &msg) { return msg.MSG_SSR_SATELLITE_APC; }
};



template<>
struct MessageTraits<sbp_msg_osr_t> {
  static constexpr u16 id = 1600;
  static const sbp_msg_osr_t &get(const sbp_msg_t &msg) { return msg.MSG_OSR; }
};



template<>
struct MessageTraits<sbp_msg_user_data_t> {
  static constexpr u16 id = 2048;
  static const sbp_msg_user_data_t &get(const sbp_msg_t &msg) { return msg.MSG_USER_DATA; }
};



template<>
struct MessageTraits<sbp_msg_imu_raw_t> {
  static constexpr u16 id = 2304;
  static const sbp_msg_imu_raw_t &get(const sbp_msg_t &msg) { return msg.MSG_IMU_RAW; }
};



template<>
struct MessageTraits<sbp_msg_imu_aux_t> {
  static constexpr u16 id = 2305;
  static const sbp_msg_imu_aux_t &get(const sbp_msg_t &msg) { return msg.MSG_IMU_AUX; }
};



template<>
struct MessageTraits<sbp_msg_mag_raw_t> {
  static constexpr u16 id = 2306;
  static const sbp_msg_mag_raw_t &get(const sbp_msg_t &msg) { return msg.MSG_MAG_RAW; }
};



template<>
struct MessageTraits<sbp_msg_odometry_t> {
  static constexpr u16 id = 2307;
  static const sbp_msg_odometry_t &get(const sbp_msg_t &msg) { return msg.MSG_ODOMETRY; }
};



template<>
struct MessageTraits<sbp_msg_wheeltick_t> {
  static constexpr u16 id = 2308;
  static const sbp_msg_wheeltick_t &get(const sbp_msg_t &msg) { return msg.MSG_WHEELTICK; }
};



template<>
struct MessageTraits<sbp_msg_fileio_config_req_t> {
  static constexpr u16 id = 4097;
  static const sbp_msg_fileio_config_req_t &get(const sbp_msg_t &msg) { return msg.MSG_FILEIO_CONFIG_REQ; }
};



template<>
struct MessageTraits<sbp_msg_fileio_config_resp_t> {
  static constexpr u16 id = 4098;
  static const sbp_msg_fileio_config_resp_t &get(const sbp_msg_t &msg) { return msg.MSG_FILEIO_CONFIG_RESP; }
};



template<>
struct MessageTraits<sbp_msg_sbas_raw_t> {
  static constexpr u16 id = 30583;
  static const sbp_msg_sbas_raw_t &get(const sbp_msg_t &msg) { return msg.MSG_SBAS_RAW; }
};



template<>
struct MessageTraits<sbp_msg_linux_cpu_state_dep_a_t> {
  static constexpr u16 id = 32512;
  static const sbp_msg_linux_cpu_state_dep_a_t &get(const sbp_msg_t &msg) { return msg.MSG_LINUX_CPU_STATE_DEP_A; }
};



template<>
struct MessageTraits<sbp_msg_linux_mem_state_dep_a_t> {
  static constexpr u16 id = 32513;
  static const sbp_msg_linux_mem_state_dep_a_t &get(const sbp_msg_t &msg) { return msg.MSG_LINUX_MEM_STATE_DEP_A; }
};



template<>
struct MessageTraits<sbp_msg_linux_sys_state_dep_a_t> {
  static constexpr u16 id = 32514;
  static const sbp_msg_linux_sys_state_dep_a_t &get(const sbp_msg_t &msg) { return msg.MSG_LINUX_SYS_STATE_DEP_A; }
};



template<>
struct MessageTraits<sbp_msg_linux_process_socket_counts_t> {
  static constexpr u16 id = 32515;
  static const sbp_msg_linux_process_socket_counts_t &get(const sbp_msg_t &msg) { return msg.MSG_LINUX_PROCESS_SOCKET_COUNTS; }
};



template<>
struct MessageTraits<sbp_msg_linux_process_socket_queues_t> {
  static constexpr u16 id = 32516;
  static const sbp_msg_linux_process_socket_queues_t &get(const sbp_msg_t &msg) { return msg.MSG_LINUX_PROCESS_SOCKET_QUEUES; }
};



template<>
struct MessageTraits<sbp_msg_linux_socket_usage_t> {
  static constexpr u16 id = 32517;
  static const sbp_msg_linux_socket_usage_t &get(const sbp_msg_t &msg) { return msg.MSG_LINUX_SOCKET_USAGE; }
};



template<>
struct MessageTraits<sbp_msg_linux_process_fd_count_t> {
  static constexpr u16 id = 32518;
  static const sbp_msg_linux_process_fd_count_t &get(const sbp_msg_t &msg) { return msg.MSG_LINUX_PROCESS_FD_COUNT; }
};



template<>
struct MessageTraits<sbp_msg_linux_process_fd_summary_t> {
  static constexpr u16 id = 32519;
  static const sbp_msg_linux_process_fd_summary_t &get(const sbp_msg_t &msg) { return msg.MSG_LINUX_PROCESS_FD_SUMMARY; }
};



template<>
struct MessageTraits<sbp_msg_linux_cpu_state_t> {
  static constexpr u16 id = 32520;
  static const sbp_msg_linux_cpu_state_t &get(const sbp_msg_t &msg) { return msg.MSG_LINUX_CPU_STATE; }
};



template<>
struct MessageTraits<sbp_msg_linux_mem_state_t> {
  static constexpr u16 id = 32521;
  static const sbp_msg_linux_mem_state_t &get(const sbp_msg_t &msg) { return msg.MSG_LINUX_MEM_STATE; }
};



template<>
struct MessageTraits<sbp_msg_linux_sys_state_t> {
  static constexpr u16 id = 32522;
  static const sbp_msg_linux_sys_state_t &get(const sbp_msg_t &msg) { return msg.MSG_LINUX_SYS_STATE; }
};



template<>
struct MessageTraits<sbp_msg_startup_t> {
  static constexpr u16 id = 65280;
  static const sbp_msg_startup_t &get(const sbp_msg_t &msg) { return msg.MSG_STARTUP; }
};



template<>
struct MessageTraits<sbp_msg_dgnss_status_t> {
  static constexpr u16 id = 65282;
  static const sbp_msg_dgnss_status_t &get(const sbp_msg_t &msg) { return msg.MSG_DGNSS_STATUS; }
};



template<>
struct MessageTraits<sbp_msg_ins_status_t> {
  static constexpr u16 id = 65283;
  static const sbp_msg_ins_status_t &get(const sbp_msg_t &msg) { return msg.MSG_INS_STATUS; }
};



template<>
struct MessageTraits<sbp_msg_csac_telemetry_t> {
  static constexpr u16 id = 65284;
  static const sbp_msg_csac_telemetry_t &get(const sbp_msg_t &msg) { return msg.MSG_CSAC_TELEMETRY; }
};



template<>
struct MessageTraits<sbp_msg_csac_telemetry_labels_t> {
  static constexpr u16 id = 65285;
  static const sbp_msg_csac_telemetry_labels_t &get(const sbp_msg_t &msg) { return msg.MSG_CSAC_TELEMETRY_LABELS; }
};



template<>
struct MessageTraits<sbp_msg_ins_updates_t> {
  static constexpr u16 id = 65286;
  static const sbp_msg_ins_updates_t &get(const sbp_msg_t &msg) { return msg.MSG_INS_UPDATES; }
};



template<>
struct MessageTraits<sbp_msg_gnss_time_offset_t> {
  static constexpr u16 id = 65287;
  static const sbp_msg_gnss_time_offset_t &get(const sbp_msg_t &msg) { return msg.MSG_GNSS_TIME_OFFSET; }
};



template<>
struct MessageTraits<sbp_msg_pps_time_t> {
  static constexpr u16 id = 65288;
  static const sbp_msg_pps_time_t &get(const sbp_msg_t &msg) { return msg.MSG_PPS_TIME; }
};



template<>
struct MessageTraits<sbp_msg_group_meta_t> {
  static constexpr u16 id = 65290;
  static const sbp_msg_group_meta_t &get(const sbp_msg_t &msg) { return msg.MSG_GROUP_META; }
};



template<>
struct MessageTraits<sbp_msg_soln_meta_t> {
  static constexpr u16 id = 65294;
  static const sbp_msg_soln_meta_t &get(const sbp_msg_t &msg) { return msg.MSG_SOLN_META; }
};



template<>
struct MessageTraits<sbp_msg_soln_meta_dep_a_t> {
  static constexpr u16 id = 65295;
  static const sbp_msg_soln_meta_dep_a_t &get(const sbp_msg_t &msg) { return msg.MSG_SOLN_META_DEP_A; }
};



template<>
struct MessageTraits<sbp_msg_status_report_t> {
  static constexpr u16 id = 65534;
  static const sbp_msg_status_report_t &get(const sbp_msg_t &msg) { return msg.MSG_STATUS_REPORT; }
};



template<>
struct MessageTraits<sbp_msg_heartbeat_t> {
  static constexpr u16 id = 65535;
  static const sbp_msg_heartbeat_t &get(const sbp_msg_t &msg) { return msg.MSG_HEARTBEAT; }
};





} // namespace sbp

#endif //SBP_CPP_MESSAGE_TRAITS_H
