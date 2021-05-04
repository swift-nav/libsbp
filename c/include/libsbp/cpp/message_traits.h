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
#include <libsbp/user.h>
#include <libsbp/vehicle.h>

namespace sbp
{

/**
 * Type traits containing meta-information for each SBP message type.
 *
 * These are only meant to be used by the C++ library at compile time.
 * These are automatically generated, DO NOT EDIT.
 */
template <typename> struct MessageTraits;

template <> struct MessageTraits<sbp_msg_print_dep_t>
{
  static constexpr u16 id = 16;
  static constexpr bool is_unpacked = true;
};

template <> struct MessageTraits<msg_print_dep_t>
{
  static constexpr u16 id = 16;
  static constexpr bool is_unpacked = false;
};

template <> struct MessageTraits<sbp_msg_tracking_state_detailed_dep_t>
{
  static constexpr u16 id = 17;
  static constexpr bool is_unpacked = true;
};

template <> struct MessageTraits<msg_tracking_state_detailed_dep_t>
{
  static constexpr u16 id = 17;
  static constexpr bool is_unpacked = false;
};

template <> struct MessageTraits<sbp_msg_tracking_state_dep_b_t>
{
  static constexpr u16 id = 19;
  static constexpr bool is_unpacked = true;
};

template <> struct MessageTraits<msg_tracking_state_dep_b_t>
{
  static constexpr u16 id = 19;
  static constexpr bool is_unpacked = false;
};

template <> struct MessageTraits<sbp_msg_acq_result_dep_b_t>
{
  static constexpr u16 id = 20;
  static constexpr bool is_unpacked = true;
};

template <> struct MessageTraits<msg_acq_result_dep_b_t>
{
  static constexpr u16 id = 20;
  static constexpr bool is_unpacked = false;
};

template <> struct MessageTraits<sbp_msg_acq_result_dep_a_t>
{
  static constexpr u16 id = 21;
  static constexpr bool is_unpacked = true;
};

template <> struct MessageTraits<msg_acq_result_dep_a_t>
{
  static constexpr u16 id = 21;
  static constexpr bool is_unpacked = false;
};

template <> struct MessageTraits<sbp_msg_tracking_state_dep_a_t>
{
  static constexpr u16 id = 22;
  static constexpr bool is_unpacked = true;
};

template <> struct MessageTraits<msg_tracking_state_dep_a_t>
{
  static constexpr u16 id = 22;
  static constexpr bool is_unpacked = false;
};

template <> struct MessageTraits<sbp_msg_thread_state_t>
{
  static constexpr u16 id = 23;
  static constexpr bool is_unpacked = true;
};

template <> struct MessageTraits<msg_thread_state_t>
{
  static constexpr u16 id = 23;
  static constexpr bool is_unpacked = false;
};

template <> struct MessageTraits<sbp_msg_uart_state_depa_t>
{
  static constexpr u16 id = 24;
  static constexpr bool is_unpacked = true;
};

template <> struct MessageTraits<msg_uart_state_depa_t>
{
  static constexpr u16 id = 24;
  static constexpr bool is_unpacked = false;
};

template <> struct MessageTraits<sbp_msg_iar_state_t>
{
  static constexpr u16 id = 25;
  static constexpr bool is_unpacked = true;
};

template <> struct MessageTraits<msg_iar_state_t>
{
  static constexpr u16 id = 25;
  static constexpr bool is_unpacked = false;
};

template <> struct MessageTraits<sbp_msg_ephemeris_dep_a_t>
{
  static constexpr u16 id = 26;
  static constexpr bool is_unpacked = true;
};

template <> struct MessageTraits<msg_ephemeris_dep_a_t>
{
  static constexpr u16 id = 26;
  static constexpr bool is_unpacked = false;
};

template <> struct MessageTraits<sbp_msg_mask_satellite_dep_t>
{
  static constexpr u16 id = 27;
  static constexpr bool is_unpacked = true;
};

template <> struct MessageTraits<msg_mask_satellite_dep_t>
{
  static constexpr u16 id = 27;
  static constexpr bool is_unpacked = false;
};

template <> struct MessageTraits<sbp_msg_tracking_iq_dep_a_t>
{
  static constexpr u16 id = 28;
  static constexpr bool is_unpacked = true;
};

template <> struct MessageTraits<msg_tracking_iq_dep_a_t>
{
  static constexpr u16 id = 28;
  static constexpr bool is_unpacked = false;
};

template <> struct MessageTraits<sbp_msg_uart_state_t>
{
  static constexpr u16 id = 29;
  static constexpr bool is_unpacked = true;
};

template <> struct MessageTraits<msg_uart_state_t>
{
  static constexpr u16 id = 29;
  static constexpr bool is_unpacked = false;
};

template <> struct MessageTraits<sbp_msg_acq_sv_profile_dep_t>
{
  static constexpr u16 id = 30;
  static constexpr bool is_unpacked = true;
};

template <> struct MessageTraits<msg_acq_sv_profile_dep_t>
{
  static constexpr u16 id = 30;
  static constexpr bool is_unpacked = false;
};

template <> struct MessageTraits<sbp_msg_acq_result_dep_c_t>
{
  static constexpr u16 id = 31;
  static constexpr bool is_unpacked = true;
};

template <> struct MessageTraits<msg_acq_result_dep_c_t>
{
  static constexpr u16 id = 31;
  static constexpr bool is_unpacked = false;
};

template <> struct MessageTraits<sbp_msg_tracking_state_detailed_dep_a_t>
{
  static constexpr u16 id = 33;
  static constexpr bool is_unpacked = true;
};

template <> struct MessageTraits<msg_tracking_state_detailed_dep_a_t>
{
  static constexpr u16 id = 33;
  static constexpr bool is_unpacked = false;
};

template <> struct MessageTraits<sbp_msg_reset_filters_t>
{
  static constexpr u16 id = 34;
  static constexpr bool is_unpacked = true;
};

template <> struct MessageTraits<msg_reset_filters_t>
{
  static constexpr u16 id = 34;
  static constexpr bool is_unpacked = false;
};

template <> struct MessageTraits<sbp_msg_mask_satellite_t>
{
  static constexpr u16 id = 43;
  static constexpr bool is_unpacked = true;
};

template <> struct MessageTraits<msg_mask_satellite_t>
{
  static constexpr u16 id = 43;
  static constexpr bool is_unpacked = false;
};

template <> struct MessageTraits<sbp_msg_tracking_iq_dep_b_t>
{
  static constexpr u16 id = 44;
  static constexpr bool is_unpacked = true;
};

template <> struct MessageTraits<msg_tracking_iq_dep_b_t>
{
  static constexpr u16 id = 44;
  static constexpr bool is_unpacked = false;
};

template <> struct MessageTraits<sbp_msg_tracking_iq_t>
{
  static constexpr u16 id = 45;
  static constexpr bool is_unpacked = true;
};

template <> struct MessageTraits<msg_tracking_iq_t>
{
  static constexpr u16 id = 45;
  static constexpr bool is_unpacked = false;
};

template <> struct MessageTraits<sbp_msg_acq_sv_profile_t>
{
  static constexpr u16 id = 46;
  static constexpr bool is_unpacked = true;
};

template <> struct MessageTraits<msg_acq_sv_profile_t>
{
  static constexpr u16 id = 46;
  static constexpr bool is_unpacked = false;
};

template <> struct MessageTraits<sbp_msg_acq_result_t>
{
  static constexpr u16 id = 47;
  static constexpr bool is_unpacked = true;
};

template <> struct MessageTraits<msg_acq_result_t>
{
  static constexpr u16 id = 47;
  static constexpr bool is_unpacked = false;
};

template <> struct MessageTraits<sbp_msg_tracking_state_t>
{
  static constexpr u16 id = 65;
  static constexpr bool is_unpacked = true;
};

template <> struct MessageTraits<msg_tracking_state_t>
{
  static constexpr u16 id = 65;
  static constexpr bool is_unpacked = false;
};

template <> struct MessageTraits<sbp_msg_obs_dep_b_t>
{
  static constexpr u16 id = 67;
  static constexpr bool is_unpacked = true;
};

template <> struct MessageTraits<msg_obs_dep_b_t>
{
  static constexpr u16 id = 67;
  static constexpr bool is_unpacked = false;
};

template <> struct MessageTraits<sbp_msg_base_pos_llh_t>
{
  static constexpr u16 id = 68;
  static constexpr bool is_unpacked = true;
};

template <> struct MessageTraits<msg_base_pos_llh_t>
{
  static constexpr u16 id = 68;
  static constexpr bool is_unpacked = false;
};

template <> struct MessageTraits<sbp_msg_obs_dep_a_t>
{
  static constexpr u16 id = 69;
  static constexpr bool is_unpacked = true;
};

template <> struct MessageTraits<msg_obs_dep_a_t>
{
  static constexpr u16 id = 69;
  static constexpr bool is_unpacked = false;
};

template <> struct MessageTraits<sbp_msg_ephemeris_dep_b_t>
{
  static constexpr u16 id = 70;
  static constexpr bool is_unpacked = true;
};

template <> struct MessageTraits<msg_ephemeris_dep_b_t>
{
  static constexpr u16 id = 70;
  static constexpr bool is_unpacked = false;
};

template <> struct MessageTraits<sbp_msg_ephemeris_dep_c_t>
{
  static constexpr u16 id = 71;
  static constexpr bool is_unpacked = true;
};

template <> struct MessageTraits<msg_ephemeris_dep_c_t>
{
  static constexpr u16 id = 71;
  static constexpr bool is_unpacked = false;
};

template <> struct MessageTraits<sbp_msg_base_pos_ecef_t>
{
  static constexpr u16 id = 72;
  static constexpr bool is_unpacked = true;
};

template <> struct MessageTraits<msg_base_pos_ecef_t>
{
  static constexpr u16 id = 72;
  static constexpr bool is_unpacked = false;
};

template <> struct MessageTraits<sbp_msg_obs_dep_c_t>
{
  static constexpr u16 id = 73;
  static constexpr bool is_unpacked = true;
};

template <> struct MessageTraits<msg_obs_dep_c_t>
{
  static constexpr u16 id = 73;
  static constexpr bool is_unpacked = false;
};

template <> struct MessageTraits<sbp_msg_obs_t>
{
  static constexpr u16 id = 74;
  static constexpr bool is_unpacked = true;
};

template <> struct MessageTraits<msg_obs_t>
{
  static constexpr u16 id = 74;
  static constexpr bool is_unpacked = false;
};

template <> struct MessageTraits<sbp_msg_specan_dep_t>
{
  static constexpr u16 id = 80;
  static constexpr bool is_unpacked = true;
};

template <> struct MessageTraits<msg_specan_dep_t>
{
  static constexpr u16 id = 80;
  static constexpr bool is_unpacked = false;
};

template <> struct MessageTraits<sbp_msg_specan_t>
{
  static constexpr u16 id = 81;
  static constexpr bool is_unpacked = true;
};

template <> struct MessageTraits<msg_specan_t>
{
  static constexpr u16 id = 81;
  static constexpr bool is_unpacked = false;
};

template <> struct MessageTraits<sbp_msg_measurement_state_t>
{
  static constexpr u16 id = 97;
  static constexpr bool is_unpacked = true;
};

template <> struct MessageTraits<msg_measurement_state_t>
{
  static constexpr u16 id = 97;
  static constexpr bool is_unpacked = false;
};

template <> struct MessageTraits<sbp_msg_almanac_gps_dep_t>
{
  static constexpr u16 id = 112;
  static constexpr bool is_unpacked = true;
};

template <> struct MessageTraits<msg_almanac_gps_dep_t>
{
  static constexpr u16 id = 112;
  static constexpr bool is_unpacked = false;
};

template <> struct MessageTraits<sbp_msg_almanac_glo_dep_t>
{
  static constexpr u16 id = 113;
  static constexpr bool is_unpacked = true;
};

template <> struct MessageTraits<msg_almanac_glo_dep_t>
{
  static constexpr u16 id = 113;
  static constexpr bool is_unpacked = false;
};

template <> struct MessageTraits<sbp_msg_almanac_gps_t>
{
  static constexpr u16 id = 114;
  static constexpr bool is_unpacked = true;
};

template <> struct MessageTraits<msg_almanac_gps_t>
{
  static constexpr u16 id = 114;
  static constexpr bool is_unpacked = false;
};

template <> struct MessageTraits<sbp_msg_almanac_glo_t>
{
  static constexpr u16 id = 115;
  static constexpr bool is_unpacked = true;
};

template <> struct MessageTraits<msg_almanac_glo_t>
{
  static constexpr u16 id = 115;
  static constexpr bool is_unpacked = false;
};

template <> struct MessageTraits<sbp_msg_glo_biases_t>
{
  static constexpr u16 id = 117;
  static constexpr bool is_unpacked = true;
};

template <> struct MessageTraits<msg_glo_biases_t>
{
  static constexpr u16 id = 117;
  static constexpr bool is_unpacked = false;
};

template <> struct MessageTraits<sbp_msg_ephemeris_dep_d_t>
{
  static constexpr u16 id = 128;
  static constexpr bool is_unpacked = true;
};

template <> struct MessageTraits<msg_ephemeris_dep_d_t>
{
  static constexpr u16 id = 128;
  static constexpr bool is_unpacked = false;
};

template <> struct MessageTraits<sbp_msg_ephemeris_gps_dep_e_t>
{
  static constexpr u16 id = 129;
  static constexpr bool is_unpacked = true;
};

template <> struct MessageTraits<msg_ephemeris_gps_dep_e_t>
{
  static constexpr u16 id = 129;
  static constexpr bool is_unpacked = false;
};

template <> struct MessageTraits<sbp_msg_ephemeris_sbas_dep_a_t>
{
  static constexpr u16 id = 130;
  static constexpr bool is_unpacked = true;
};

template <> struct MessageTraits<msg_ephemeris_sbas_dep_a_t>
{
  static constexpr u16 id = 130;
  static constexpr bool is_unpacked = false;
};

template <> struct MessageTraits<sbp_msg_ephemeris_glo_dep_a_t>
{
  static constexpr u16 id = 131;
  static constexpr bool is_unpacked = true;
};

template <> struct MessageTraits<msg_ephemeris_glo_dep_a_t>
{
  static constexpr u16 id = 131;
  static constexpr bool is_unpacked = false;
};

template <> struct MessageTraits<sbp_msg_ephemeris_sbas_dep_b_t>
{
  static constexpr u16 id = 132;
  static constexpr bool is_unpacked = true;
};

template <> struct MessageTraits<msg_ephemeris_sbas_dep_b_t>
{
  static constexpr u16 id = 132;
  static constexpr bool is_unpacked = false;
};

template <> struct MessageTraits<sbp_msg_ephemeris_glo_dep_b_t>
{
  static constexpr u16 id = 133;
  static constexpr bool is_unpacked = true;
};

template <> struct MessageTraits<msg_ephemeris_glo_dep_b_t>
{
  static constexpr u16 id = 133;
  static constexpr bool is_unpacked = false;
};

template <> struct MessageTraits<sbp_msg_ephemeris_gps_dep_f_t>
{
  static constexpr u16 id = 134;
  static constexpr bool is_unpacked = true;
};

template <> struct MessageTraits<msg_ephemeris_gps_dep_f_t>
{
  static constexpr u16 id = 134;
  static constexpr bool is_unpacked = false;
};

template <> struct MessageTraits<sbp_msg_ephemeris_glo_dep_c_t>
{
  static constexpr u16 id = 135;
  static constexpr bool is_unpacked = true;
};

template <> struct MessageTraits<msg_ephemeris_glo_dep_c_t>
{
  static constexpr u16 id = 135;
  static constexpr bool is_unpacked = false;
};

template <> struct MessageTraits<sbp_msg_ephemeris_glo_dep_d_t>
{
  static constexpr u16 id = 136;
  static constexpr bool is_unpacked = true;
};

template <> struct MessageTraits<msg_ephemeris_glo_dep_d_t>
{
  static constexpr u16 id = 136;
  static constexpr bool is_unpacked = false;
};

template <> struct MessageTraits<sbp_msg_ephemeris_bds_t>
{
  static constexpr u16 id = 137;
  static constexpr bool is_unpacked = true;
};

template <> struct MessageTraits<msg_ephemeris_bds_t>
{
  static constexpr u16 id = 137;
  static constexpr bool is_unpacked = false;
};

template <> struct MessageTraits<sbp_msg_ephemeris_gps_t>
{
  static constexpr u16 id = 138;
  static constexpr bool is_unpacked = true;
};

template <> struct MessageTraits<msg_ephemeris_gps_t>
{
  static constexpr u16 id = 138;
  static constexpr bool is_unpacked = false;
};

template <> struct MessageTraits<sbp_msg_ephemeris_glo_t>
{
  static constexpr u16 id = 139;
  static constexpr bool is_unpacked = true;
};

template <> struct MessageTraits<msg_ephemeris_glo_t>
{
  static constexpr u16 id = 139;
  static constexpr bool is_unpacked = false;
};

template <> struct MessageTraits<sbp_msg_ephemeris_sbas_t>
{
  static constexpr u16 id = 140;
  static constexpr bool is_unpacked = true;
};

template <> struct MessageTraits<msg_ephemeris_sbas_t>
{
  static constexpr u16 id = 140;
  static constexpr bool is_unpacked = false;
};

template <> struct MessageTraits<sbp_msg_ephemeris_gal_t>
{
  static constexpr u16 id = 141;
  static constexpr bool is_unpacked = true;
};

template <> struct MessageTraits<msg_ephemeris_gal_t>
{
  static constexpr u16 id = 141;
  static constexpr bool is_unpacked = false;
};

template <> struct MessageTraits<sbp_msg_ephemeris_qzss_t>
{
  static constexpr u16 id = 142;
  static constexpr bool is_unpacked = true;
};

template <> struct MessageTraits<msg_ephemeris_qzss_t>
{
  static constexpr u16 id = 142;
  static constexpr bool is_unpacked = false;
};

template <> struct MessageTraits<sbp_msg_iono_t>
{
  static constexpr u16 id = 144;
  static constexpr bool is_unpacked = true;
};

template <> struct MessageTraits<msg_iono_t>
{
  static constexpr u16 id = 144;
  static constexpr bool is_unpacked = false;
};

template <> struct MessageTraits<sbp_msg_sv_configuration_gps_dep_t>
{
  static constexpr u16 id = 145;
  static constexpr bool is_unpacked = true;
};

template <> struct MessageTraits<msg_sv_configuration_gps_dep_t>
{
  static constexpr u16 id = 145;
  static constexpr bool is_unpacked = false;
};

template <> struct MessageTraits<sbp_msg_group_delay_dep_a_t>
{
  static constexpr u16 id = 146;
  static constexpr bool is_unpacked = true;
};

template <> struct MessageTraits<msg_group_delay_dep_a_t>
{
  static constexpr u16 id = 146;
  static constexpr bool is_unpacked = false;
};

template <> struct MessageTraits<sbp_msg_group_delay_dep_b_t>
{
  static constexpr u16 id = 147;
  static constexpr bool is_unpacked = true;
};

template <> struct MessageTraits<msg_group_delay_dep_b_t>
{
  static constexpr u16 id = 147;
  static constexpr bool is_unpacked = false;
};

template <> struct MessageTraits<sbp_msg_group_delay_t>
{
  static constexpr u16 id = 148;
  static constexpr bool is_unpacked = true;
};

template <> struct MessageTraits<msg_group_delay_t>
{
  static constexpr u16 id = 148;
  static constexpr bool is_unpacked = false;
};

template <> struct MessageTraits<sbp_msg_ephemeris_gal_dep_a_t>
{
  static constexpr u16 id = 149;
  static constexpr bool is_unpacked = true;
};

template <> struct MessageTraits<msg_ephemeris_gal_dep_a_t>
{
  static constexpr u16 id = 149;
  static constexpr bool is_unpacked = false;
};

template <> struct MessageTraits<sbp_msg_gnss_capb_t>
{
  static constexpr u16 id = 150;
  static constexpr bool is_unpacked = true;
};

template <> struct MessageTraits<msg_gnss_capb_t>
{
  static constexpr u16 id = 150;
  static constexpr bool is_unpacked = false;
};

template <> struct MessageTraits<sbp_msg_sv_az_el_t>
{
  static constexpr u16 id = 151;
  static constexpr bool is_unpacked = true;
};

template <> struct MessageTraits<msg_sv_az_el_t>
{
  static constexpr u16 id = 151;
  static constexpr bool is_unpacked = false;
};

template <> struct MessageTraits<sbp_msg_settings_write_t>
{
  static constexpr u16 id = 160;
  static constexpr bool is_unpacked = true;
};

template <> struct MessageTraits<msg_settings_write_t>
{
  static constexpr u16 id = 160;
  static constexpr bool is_unpacked = false;
};

template <> struct MessageTraits<sbp_msg_settings_read_by_index_req_t>
{
  static constexpr u16 id = 162;
  static constexpr bool is_unpacked = true;
};

template <> struct MessageTraits<msg_settings_read_by_index_req_t>
{
  static constexpr u16 id = 162;
  static constexpr bool is_unpacked = false;
};

template <> struct MessageTraits<sbp_msg_fileio_read_resp_t>
{
  static constexpr u16 id = 163;
  static constexpr bool is_unpacked = true;
};

template <> struct MessageTraits<msg_fileio_read_resp_t>
{
  static constexpr u16 id = 163;
  static constexpr bool is_unpacked = false;
};

template <> struct MessageTraits<sbp_msg_settings_read_req_t>
{
  static constexpr u16 id = 164;
  static constexpr bool is_unpacked = true;
};

template <> struct MessageTraits<msg_settings_read_req_t>
{
  static constexpr u16 id = 164;
  static constexpr bool is_unpacked = false;
};

template <> struct MessageTraits<sbp_msg_settings_read_resp_t>
{
  static constexpr u16 id = 165;
  static constexpr bool is_unpacked = true;
};

template <> struct MessageTraits<msg_settings_read_resp_t>
{
  static constexpr u16 id = 165;
  static constexpr bool is_unpacked = false;
};

template <> struct MessageTraits<sbp_msg_settings_read_by_index_resp_t>
{
  static constexpr u16 id = 167;
  static constexpr bool is_unpacked = true;
};

template <> struct MessageTraits<msg_settings_read_by_index_resp_t>
{
  static constexpr u16 id = 167;
  static constexpr bool is_unpacked = false;
};

template <> struct MessageTraits<sbp_msg_fileio_read_req_t>
{
  static constexpr u16 id = 168;
  static constexpr bool is_unpacked = true;
};

template <> struct MessageTraits<msg_fileio_read_req_t>
{
  static constexpr u16 id = 168;
  static constexpr bool is_unpacked = false;
};

template <> struct MessageTraits<sbp_msg_fileio_read_dir_req_t>
{
  static constexpr u16 id = 169;
  static constexpr bool is_unpacked = true;
};

template <> struct MessageTraits<msg_fileio_read_dir_req_t>
{
  static constexpr u16 id = 169;
  static constexpr bool is_unpacked = false;
};

template <> struct MessageTraits<sbp_msg_fileio_read_dir_resp_t>
{
  static constexpr u16 id = 170;
  static constexpr bool is_unpacked = true;
};

template <> struct MessageTraits<msg_fileio_read_dir_resp_t>
{
  static constexpr u16 id = 170;
  static constexpr bool is_unpacked = false;
};

template <> struct MessageTraits<sbp_msg_fileio_write_resp_t>
{
  static constexpr u16 id = 171;
  static constexpr bool is_unpacked = true;
};

template <> struct MessageTraits<msg_fileio_write_resp_t>
{
  static constexpr u16 id = 171;
  static constexpr bool is_unpacked = false;
};

template <> struct MessageTraits<sbp_msg_fileio_remove_t>
{
  static constexpr u16 id = 172;
  static constexpr bool is_unpacked = true;
};

template <> struct MessageTraits<msg_fileio_remove_t>
{
  static constexpr u16 id = 172;
  static constexpr bool is_unpacked = false;
};

template <> struct MessageTraits<sbp_msg_fileio_write_req_t>
{
  static constexpr u16 id = 173;
  static constexpr bool is_unpacked = true;
};

template <> struct MessageTraits<msg_fileio_write_req_t>
{
  static constexpr u16 id = 173;
  static constexpr bool is_unpacked = false;
};

template <> struct MessageTraits<sbp_msg_settings_register_t>
{
  static constexpr u16 id = 174;
  static constexpr bool is_unpacked = true;
};

template <> struct MessageTraits<msg_settings_register_t>
{
  static constexpr u16 id = 174;
  static constexpr bool is_unpacked = false;
};

template <> struct MessageTraits<sbp_msg_settings_write_resp_t>
{
  static constexpr u16 id = 175;
  static constexpr bool is_unpacked = true;
};

template <> struct MessageTraits<msg_settings_write_resp_t>
{
  static constexpr u16 id = 175;
  static constexpr bool is_unpacked = false;
};

template <> struct MessageTraits<sbp_msg_bootloader_handshake_dep_a_t>
{
  static constexpr u16 id = 176;
  static constexpr bool is_unpacked = true;
};

template <> struct MessageTraits<msg_bootloader_handshake_dep_a_t>
{
  static constexpr u16 id = 176;
  static constexpr bool is_unpacked = false;
};

template <> struct MessageTraits<sbp_msg_bootloader_jump_to_app_t>
{
  static constexpr u16 id = 177;
  static constexpr bool is_unpacked = true;
};

template <> struct MessageTraits<msg_bootloader_jump_to_app_t>
{
  static constexpr u16 id = 177;
  static constexpr bool is_unpacked = false;
};

template <> struct MessageTraits<sbp_msg_bootloader_handshake_resp_t>
{
  static constexpr u16 id = 180;
  static constexpr bool is_unpacked = true;
};

template <> struct MessageTraits<msg_bootloader_handshake_resp_t>
{
  static constexpr u16 id = 180;
  static constexpr bool is_unpacked = false;
};

template <> struct MessageTraits<sbp_msg_device_monitor_t>
{
  static constexpr u16 id = 181;
  static constexpr bool is_unpacked = true;
};

template <> struct MessageTraits<msg_device_monitor_t>
{
  static constexpr u16 id = 181;
  static constexpr bool is_unpacked = false;
};

template <> struct MessageTraits<sbp_msg_reset_t>
{
  static constexpr u16 id = 182;
  static constexpr bool is_unpacked = true;
};

template <> struct MessageTraits<msg_reset_t>
{
  static constexpr u16 id = 182;
  static constexpr bool is_unpacked = false;
};

template <> struct MessageTraits<sbp_msg_command_req_t>
{
  static constexpr u16 id = 184;
  static constexpr bool is_unpacked = true;
};

template <> struct MessageTraits<msg_command_req_t>
{
  static constexpr u16 id = 184;
  static constexpr bool is_unpacked = false;
};

template <> struct MessageTraits<sbp_msg_command_resp_t>
{
  static constexpr u16 id = 185;
  static constexpr bool is_unpacked = true;
};

template <> struct MessageTraits<msg_command_resp_t>
{
  static constexpr u16 id = 185;
  static constexpr bool is_unpacked = false;
};

template <> struct MessageTraits<sbp_msg_network_state_resp_t>
{
  static constexpr u16 id = 187;
  static constexpr bool is_unpacked = true;
};

template <> struct MessageTraits<msg_network_state_resp_t>
{
  static constexpr u16 id = 187;
  static constexpr bool is_unpacked = false;
};

template <> struct MessageTraits<sbp_msg_command_output_t>
{
  static constexpr u16 id = 188;
  static constexpr bool is_unpacked = true;
};

template <> struct MessageTraits<msg_command_output_t>
{
  static constexpr u16 id = 188;
  static constexpr bool is_unpacked = false;
};

template <> struct MessageTraits<sbp_msg_network_bandwidth_usage_t>
{
  static constexpr u16 id = 189;
  static constexpr bool is_unpacked = true;
};

template <> struct MessageTraits<msg_network_bandwidth_usage_t>
{
  static constexpr u16 id = 189;
  static constexpr bool is_unpacked = false;
};

template <> struct MessageTraits<sbp_msg_cell_modem_status_t>
{
  static constexpr u16 id = 190;
  static constexpr bool is_unpacked = true;
};

template <> struct MessageTraits<msg_cell_modem_status_t>
{
  static constexpr u16 id = 190;
  static constexpr bool is_unpacked = false;
};

template <> struct MessageTraits<sbp_msg_front_end_gain_t>
{
  static constexpr u16 id = 191;
  static constexpr bool is_unpacked = true;
};

template <> struct MessageTraits<msg_front_end_gain_t>
{
  static constexpr u16 id = 191;
  static constexpr bool is_unpacked = false;
};

template <> struct MessageTraits<sbp_msg_nap_device_dna_resp_t>
{
  static constexpr u16 id = 221;
  static constexpr bool is_unpacked = true;
};

template <> struct MessageTraits<msg_nap_device_dna_resp_t>
{
  static constexpr u16 id = 221;
  static constexpr bool is_unpacked = false;
};

template <> struct MessageTraits<sbp_msg_flash_done_t>
{
  static constexpr u16 id = 224;
  static constexpr bool is_unpacked = true;
};

template <> struct MessageTraits<msg_flash_done_t>
{
  static constexpr u16 id = 224;
  static constexpr bool is_unpacked = false;
};

template <> struct MessageTraits<sbp_msg_flash_read_resp_t>
{
  static constexpr u16 id = 225;
  static constexpr bool is_unpacked = true;
};

template <> struct MessageTraits<msg_flash_read_resp_t>
{
  static constexpr u16 id = 225;
  static constexpr bool is_unpacked = false;
};

template <> struct MessageTraits<sbp_msg_flash_erase_t>
{
  static constexpr u16 id = 226;
  static constexpr bool is_unpacked = true;
};

template <> struct MessageTraits<msg_flash_erase_t>
{
  static constexpr u16 id = 226;
  static constexpr bool is_unpacked = false;
};

template <> struct MessageTraits<sbp_msg_stm_flash_lock_sector_t>
{
  static constexpr u16 id = 227;
  static constexpr bool is_unpacked = true;
};

template <> struct MessageTraits<msg_stm_flash_lock_sector_t>
{
  static constexpr u16 id = 227;
  static constexpr bool is_unpacked = false;
};

template <> struct MessageTraits<sbp_msg_stm_flash_unlock_sector_t>
{
  static constexpr u16 id = 228;
  static constexpr bool is_unpacked = true;
};

template <> struct MessageTraits<msg_stm_flash_unlock_sector_t>
{
  static constexpr u16 id = 228;
  static constexpr bool is_unpacked = false;
};

template <> struct MessageTraits<sbp_msg_stm_unique_id_resp_t>
{
  static constexpr u16 id = 229;
  static constexpr bool is_unpacked = true;
};

template <> struct MessageTraits<msg_stm_unique_id_resp_t>
{
  static constexpr u16 id = 229;
  static constexpr bool is_unpacked = false;
};

template <> struct MessageTraits<sbp_msg_flash_program_t>
{
  static constexpr u16 id = 230;
  static constexpr bool is_unpacked = true;
};

template <> struct MessageTraits<msg_flash_program_t>
{
  static constexpr u16 id = 230;
  static constexpr bool is_unpacked = false;
};

template <> struct MessageTraits<sbp_msg_flash_read_req_t>
{
  static constexpr u16 id = 231;
  static constexpr bool is_unpacked = true;
};

template <> struct MessageTraits<msg_flash_read_req_t>
{
  static constexpr u16 id = 231;
  static constexpr bool is_unpacked = false;
};

template <> struct MessageTraits<sbp_msg_m25_flash_write_status_t>
{
  static constexpr u16 id = 243;
  static constexpr bool is_unpacked = true;
};

template <> struct MessageTraits<msg_m25_flash_write_status_t>
{
  static constexpr u16 id = 243;
  static constexpr bool is_unpacked = false;
};

template <> struct MessageTraits<sbp_msg_gps_time_dep_a_t>
{
  static constexpr u16 id = 256;
  static constexpr bool is_unpacked = true;
};

template <> struct MessageTraits<msg_gps_time_dep_a_t>
{
  static constexpr u16 id = 256;
  static constexpr bool is_unpacked = false;
};

template <> struct MessageTraits<sbp_msg_ext_event_t>
{
  static constexpr u16 id = 257;
  static constexpr bool is_unpacked = true;
};

template <> struct MessageTraits<msg_ext_event_t>
{
  static constexpr u16 id = 257;
  static constexpr bool is_unpacked = false;
};

template <> struct MessageTraits<sbp_msg_gps_time_t>
{
  static constexpr u16 id = 258;
  static constexpr bool is_unpacked = true;
};

template <> struct MessageTraits<msg_gps_time_t>
{
  static constexpr u16 id = 258;
  static constexpr bool is_unpacked = false;
};

template <> struct MessageTraits<sbp_msg_utc_time_t>
{
  static constexpr u16 id = 259;
  static constexpr bool is_unpacked = true;
};

template <> struct MessageTraits<msg_utc_time_t>
{
  static constexpr u16 id = 259;
  static constexpr bool is_unpacked = false;
};

template <> struct MessageTraits<sbp_msg_gps_time_gnss_t>
{
  static constexpr u16 id = 260;
  static constexpr bool is_unpacked = true;
};

template <> struct MessageTraits<msg_gps_time_gnss_t>
{
  static constexpr u16 id = 260;
  static constexpr bool is_unpacked = false;
};

template <> struct MessageTraits<sbp_msg_utc_time_gnss_t>
{
  static constexpr u16 id = 261;
  static constexpr bool is_unpacked = true;
};

template <> struct MessageTraits<msg_utc_time_gnss_t>
{
  static constexpr u16 id = 261;
  static constexpr bool is_unpacked = false;
};

template <> struct MessageTraits<sbp_msg_settings_register_resp_t>
{
  static constexpr u16 id = 431;
  static constexpr bool is_unpacked = true;
};

template <> struct MessageTraits<msg_settings_register_resp_t>
{
  static constexpr u16 id = 431;
  static constexpr bool is_unpacked = false;
};

template <> struct MessageTraits<sbp_msg_pos_ecef_dep_a_t>
{
  static constexpr u16 id = 512;
  static constexpr bool is_unpacked = true;
};

template <> struct MessageTraits<msg_pos_ecef_dep_a_t>
{
  static constexpr u16 id = 512;
  static constexpr bool is_unpacked = false;
};

template <> struct MessageTraits<sbp_msg_pos_llh_dep_a_t>
{
  static constexpr u16 id = 513;
  static constexpr bool is_unpacked = true;
};

template <> struct MessageTraits<msg_pos_llh_dep_a_t>
{
  static constexpr u16 id = 513;
  static constexpr bool is_unpacked = false;
};

template <> struct MessageTraits<sbp_msg_baseline_ecef_dep_a_t>
{
  static constexpr u16 id = 514;
  static constexpr bool is_unpacked = true;
};

template <> struct MessageTraits<msg_baseline_ecef_dep_a_t>
{
  static constexpr u16 id = 514;
  static constexpr bool is_unpacked = false;
};

template <> struct MessageTraits<sbp_msg_baseline_ned_dep_a_t>
{
  static constexpr u16 id = 515;
  static constexpr bool is_unpacked = true;
};

template <> struct MessageTraits<msg_baseline_ned_dep_a_t>
{
  static constexpr u16 id = 515;
  static constexpr bool is_unpacked = false;
};

template <> struct MessageTraits<sbp_msg_vel_ecef_dep_a_t>
{
  static constexpr u16 id = 516;
  static constexpr bool is_unpacked = true;
};

template <> struct MessageTraits<msg_vel_ecef_dep_a_t>
{
  static constexpr u16 id = 516;
  static constexpr bool is_unpacked = false;
};

template <> struct MessageTraits<sbp_msg_vel_ned_dep_a_t>
{
  static constexpr u16 id = 517;
  static constexpr bool is_unpacked = true;
};

template <> struct MessageTraits<msg_vel_ned_dep_a_t>
{
  static constexpr u16 id = 517;
  static constexpr bool is_unpacked = false;
};

template <> struct MessageTraits<sbp_msg_dops_dep_a_t>
{
  static constexpr u16 id = 518;
  static constexpr bool is_unpacked = true;
};

template <> struct MessageTraits<msg_dops_dep_a_t>
{
  static constexpr u16 id = 518;
  static constexpr bool is_unpacked = false;
};

template <> struct MessageTraits<sbp_msg_baseline_heading_dep_a_t>
{
  static constexpr u16 id = 519;
  static constexpr bool is_unpacked = true;
};

template <> struct MessageTraits<msg_baseline_heading_dep_a_t>
{
  static constexpr u16 id = 519;
  static constexpr bool is_unpacked = false;
};

template <> struct MessageTraits<sbp_msg_dops_t>
{
  static constexpr u16 id = 520;
  static constexpr bool is_unpacked = true;
};

template <> struct MessageTraits<msg_dops_t>
{
  static constexpr u16 id = 520;
  static constexpr bool is_unpacked = false;
};

template <> struct MessageTraits<sbp_msg_pos_ecef_t>
{
  static constexpr u16 id = 521;
  static constexpr bool is_unpacked = true;
};

template <> struct MessageTraits<msg_pos_ecef_t>
{
  static constexpr u16 id = 521;
  static constexpr bool is_unpacked = false;
};

template <> struct MessageTraits<sbp_msg_pos_llh_t>
{
  static constexpr u16 id = 522;
  static constexpr bool is_unpacked = true;
};

template <> struct MessageTraits<msg_pos_llh_t>
{
  static constexpr u16 id = 522;
  static constexpr bool is_unpacked = false;
};

template <> struct MessageTraits<sbp_msg_baseline_ecef_t>
{
  static constexpr u16 id = 523;
  static constexpr bool is_unpacked = true;
};

template <> struct MessageTraits<msg_baseline_ecef_t>
{
  static constexpr u16 id = 523;
  static constexpr bool is_unpacked = false;
};

template <> struct MessageTraits<sbp_msg_baseline_ned_t>
{
  static constexpr u16 id = 524;
  static constexpr bool is_unpacked = true;
};

template <> struct MessageTraits<msg_baseline_ned_t>
{
  static constexpr u16 id = 524;
  static constexpr bool is_unpacked = false;
};

template <> struct MessageTraits<sbp_msg_vel_ecef_t>
{
  static constexpr u16 id = 525;
  static constexpr bool is_unpacked = true;
};

template <> struct MessageTraits<msg_vel_ecef_t>
{
  static constexpr u16 id = 525;
  static constexpr bool is_unpacked = false;
};

template <> struct MessageTraits<sbp_msg_vel_ned_t>
{
  static constexpr u16 id = 526;
  static constexpr bool is_unpacked = true;
};

template <> struct MessageTraits<msg_vel_ned_t>
{
  static constexpr u16 id = 526;
  static constexpr bool is_unpacked = false;
};

template <> struct MessageTraits<sbp_msg_baseline_heading_t>
{
  static constexpr u16 id = 527;
  static constexpr bool is_unpacked = true;
};

template <> struct MessageTraits<msg_baseline_heading_t>
{
  static constexpr u16 id = 527;
  static constexpr bool is_unpacked = false;
};

template <> struct MessageTraits<sbp_msg_age_corrections_t>
{
  static constexpr u16 id = 528;
  static constexpr bool is_unpacked = true;
};

template <> struct MessageTraits<msg_age_corrections_t>
{
  static constexpr u16 id = 528;
  static constexpr bool is_unpacked = false;
};

template <> struct MessageTraits<sbp_msg_pos_llh_cov_t>
{
  static constexpr u16 id = 529;
  static constexpr bool is_unpacked = true;
};

template <> struct MessageTraits<msg_pos_llh_cov_t>
{
  static constexpr u16 id = 529;
  static constexpr bool is_unpacked = false;
};

template <> struct MessageTraits<sbp_msg_vel_ned_cov_t>
{
  static constexpr u16 id = 530;
  static constexpr bool is_unpacked = true;
};

template <> struct MessageTraits<msg_vel_ned_cov_t>
{
  static constexpr u16 id = 530;
  static constexpr bool is_unpacked = false;
};

template <> struct MessageTraits<sbp_msg_vel_body_t>
{
  static constexpr u16 id = 531;
  static constexpr bool is_unpacked = true;
};

template <> struct MessageTraits<msg_vel_body_t>
{
  static constexpr u16 id = 531;
  static constexpr bool is_unpacked = false;
};

template <> struct MessageTraits<sbp_msg_pos_ecef_cov_t>
{
  static constexpr u16 id = 532;
  static constexpr bool is_unpacked = true;
};

template <> struct MessageTraits<msg_pos_ecef_cov_t>
{
  static constexpr u16 id = 532;
  static constexpr bool is_unpacked = false;
};

template <> struct MessageTraits<sbp_msg_vel_ecef_cov_t>
{
  static constexpr u16 id = 533;
  static constexpr bool is_unpacked = true;
};

template <> struct MessageTraits<msg_vel_ecef_cov_t>
{
  static constexpr u16 id = 533;
  static constexpr bool is_unpacked = false;
};

template <> struct MessageTraits<sbp_msg_protection_level_t>
{
  static constexpr u16 id = 534;
  static constexpr bool is_unpacked = true;
};

template <> struct MessageTraits<msg_protection_level_t>
{
  static constexpr u16 id = 534;
  static constexpr bool is_unpacked = false;
};

template <> struct MessageTraits<sbp_msg_orient_quat_t>
{
  static constexpr u16 id = 544;
  static constexpr bool is_unpacked = true;
};

template <> struct MessageTraits<msg_orient_quat_t>
{
  static constexpr u16 id = 544;
  static constexpr bool is_unpacked = false;
};

template <> struct MessageTraits<sbp_msg_orient_euler_t>
{
  static constexpr u16 id = 545;
  static constexpr bool is_unpacked = true;
};

template <> struct MessageTraits<msg_orient_euler_t>
{
  static constexpr u16 id = 545;
  static constexpr bool is_unpacked = false;
};

template <> struct MessageTraits<sbp_msg_angular_rate_t>
{
  static constexpr u16 id = 546;
  static constexpr bool is_unpacked = true;
};

template <> struct MessageTraits<msg_angular_rate_t>
{
  static constexpr u16 id = 546;
  static constexpr bool is_unpacked = false;
};

template <> struct MessageTraits<sbp_msg_pos_ecef_gnss_t>
{
  static constexpr u16 id = 553;
  static constexpr bool is_unpacked = true;
};

template <> struct MessageTraits<msg_pos_ecef_gnss_t>
{
  static constexpr u16 id = 553;
  static constexpr bool is_unpacked = false;
};

template <> struct MessageTraits<sbp_msg_pos_llh_gnss_t>
{
  static constexpr u16 id = 554;
  static constexpr bool is_unpacked = true;
};

template <> struct MessageTraits<msg_pos_llh_gnss_t>
{
  static constexpr u16 id = 554;
  static constexpr bool is_unpacked = false;
};

template <> struct MessageTraits<sbp_msg_vel_ecef_gnss_t>
{
  static constexpr u16 id = 557;
  static constexpr bool is_unpacked = true;
};

template <> struct MessageTraits<msg_vel_ecef_gnss_t>
{
  static constexpr u16 id = 557;
  static constexpr bool is_unpacked = false;
};

template <> struct MessageTraits<sbp_msg_vel_ned_gnss_t>
{
  static constexpr u16 id = 558;
  static constexpr bool is_unpacked = true;
};

template <> struct MessageTraits<msg_vel_ned_gnss_t>
{
  static constexpr u16 id = 558;
  static constexpr bool is_unpacked = false;
};

template <> struct MessageTraits<sbp_msg_pos_llh_cov_gnss_t>
{
  static constexpr u16 id = 561;
  static constexpr bool is_unpacked = true;
};

template <> struct MessageTraits<msg_pos_llh_cov_gnss_t>
{
  static constexpr u16 id = 561;
  static constexpr bool is_unpacked = false;
};

template <> struct MessageTraits<sbp_msg_vel_ned_cov_gnss_t>
{
  static constexpr u16 id = 562;
  static constexpr bool is_unpacked = true;
};

template <> struct MessageTraits<msg_vel_ned_cov_gnss_t>
{
  static constexpr u16 id = 562;
  static constexpr bool is_unpacked = false;
};

template <> struct MessageTraits<sbp_msg_pos_ecef_cov_gnss_t>
{
  static constexpr u16 id = 564;
  static constexpr bool is_unpacked = true;
};

template <> struct MessageTraits<msg_pos_ecef_cov_gnss_t>
{
  static constexpr u16 id = 564;
  static constexpr bool is_unpacked = false;
};

template <> struct MessageTraits<sbp_msg_vel_ecef_cov_gnss_t>
{
  static constexpr u16 id = 565;
  static constexpr bool is_unpacked = true;
};

template <> struct MessageTraits<msg_vel_ecef_cov_gnss_t>
{
  static constexpr u16 id = 565;
  static constexpr bool is_unpacked = false;
};

template <> struct MessageTraits<sbp_msg_ndb_event_t>
{
  static constexpr u16 id = 1024;
  static constexpr bool is_unpacked = true;
};

template <> struct MessageTraits<msg_ndb_event_t>
{
  static constexpr u16 id = 1024;
  static constexpr bool is_unpacked = false;
};

template <> struct MessageTraits<sbp_msg_log_t>
{
  static constexpr u16 id = 1025;
  static constexpr bool is_unpacked = true;
};

template <> struct MessageTraits<msg_log_t>
{
  static constexpr u16 id = 1025;
  static constexpr bool is_unpacked = false;
};

template <> struct MessageTraits<sbp_msg_fwd_t>
{
  static constexpr u16 id = 1026;
  static constexpr bool is_unpacked = true;
};

template <> struct MessageTraits<msg_fwd_t>
{
  static constexpr u16 id = 1026;
  static constexpr bool is_unpacked = false;
};

template <> struct MessageTraits<sbp_msg_ssr_orbit_clock_dep_a_t>
{
  static constexpr u16 id = 1500;
  static constexpr bool is_unpacked = true;
};

template <> struct MessageTraits<msg_ssr_orbit_clock_dep_a_t>
{
  static constexpr u16 id = 1500;
  static constexpr bool is_unpacked = false;
};

template <> struct MessageTraits<sbp_msg_ssr_orbit_clock_t>
{
  static constexpr u16 id = 1501;
  static constexpr bool is_unpacked = true;
};

template <> struct MessageTraits<msg_ssr_orbit_clock_t>
{
  static constexpr u16 id = 1501;
  static constexpr bool is_unpacked = false;
};

template <> struct MessageTraits<sbp_msg_ssr_code_biases_t>
{
  static constexpr u16 id = 1505;
  static constexpr bool is_unpacked = true;
};

template <> struct MessageTraits<msg_ssr_code_biases_t>
{
  static constexpr u16 id = 1505;
  static constexpr bool is_unpacked = false;
};

template <> struct MessageTraits<sbp_msg_ssr_phase_biases_t>
{
  static constexpr u16 id = 1510;
  static constexpr bool is_unpacked = true;
};

template <> struct MessageTraits<msg_ssr_phase_biases_t>
{
  static constexpr u16 id = 1510;
  static constexpr bool is_unpacked = false;
};

template <> struct MessageTraits<sbp_msg_ssr_stec_correction_dep_a_t>
{
  static constexpr u16 id = 1515;
  static constexpr bool is_unpacked = true;
};

template <> struct MessageTraits<msg_ssr_stec_correction_dep_a_t>
{
  static constexpr u16 id = 1515;
  static constexpr bool is_unpacked = false;
};

template <> struct MessageTraits<sbp_msg_ssr_gridded_correction_no_std_dep_a_t>
{
  static constexpr u16 id = 1520;
  static constexpr bool is_unpacked = true;
};

template <> struct MessageTraits<msg_ssr_gridded_correction_no_std_dep_a_t>
{
  static constexpr u16 id = 1520;
  static constexpr bool is_unpacked = false;
};

template <> struct MessageTraits<sbp_msg_ssr_grid_definition_dep_a_t>
{
  static constexpr u16 id = 1525;
  static constexpr bool is_unpacked = true;
};

template <> struct MessageTraits<msg_ssr_grid_definition_dep_a_t>
{
  static constexpr u16 id = 1525;
  static constexpr bool is_unpacked = false;
};

template <> struct MessageTraits<sbp_msg_ssr_tile_definition_t>
{
  static constexpr u16 id = 1526;
  static constexpr bool is_unpacked = true;
};

template <> struct MessageTraits<msg_ssr_tile_definition_t>
{
  static constexpr u16 id = 1526;
  static constexpr bool is_unpacked = false;
};

template <> struct MessageTraits<sbp_msg_ssr_gridded_correction_dep_a_t>
{
  static constexpr u16 id = 1530;
  static constexpr bool is_unpacked = true;
};

template <> struct MessageTraits<msg_ssr_gridded_correction_dep_a_t>
{
  static constexpr u16 id = 1530;
  static constexpr bool is_unpacked = false;
};

template <> struct MessageTraits<sbp_msg_ssr_stec_correction_t>
{
  static constexpr u16 id = 1531;
  static constexpr bool is_unpacked = true;
};

template <> struct MessageTraits<msg_ssr_stec_correction_t>
{
  static constexpr u16 id = 1531;
  static constexpr bool is_unpacked = false;
};

template <> struct MessageTraits<sbp_msg_ssr_gridded_correction_t>
{
  static constexpr u16 id = 1532;
  static constexpr bool is_unpacked = true;
};

template <> struct MessageTraits<msg_ssr_gridded_correction_t>
{
  static constexpr u16 id = 1532;
  static constexpr bool is_unpacked = false;
};

template <> struct MessageTraits<sbp_msg_ssr_satellite_apc_t>
{
  static constexpr u16 id = 1540;
  static constexpr bool is_unpacked = true;
};

template <> struct MessageTraits<msg_ssr_satellite_apc_t>
{
  static constexpr u16 id = 1540;
  static constexpr bool is_unpacked = false;
};

template <> struct MessageTraits<sbp_msg_osr_t>
{
  static constexpr u16 id = 1600;
  static constexpr bool is_unpacked = true;
};

template <> struct MessageTraits<msg_osr_t>
{
  static constexpr u16 id = 1600;
  static constexpr bool is_unpacked = false;
};

template <> struct MessageTraits<sbp_msg_user_data_t>
{
  static constexpr u16 id = 2048;
  static constexpr bool is_unpacked = true;
};

template <> struct MessageTraits<msg_user_data_t>
{
  static constexpr u16 id = 2048;
  static constexpr bool is_unpacked = false;
};

template <> struct MessageTraits<sbp_msg_imu_raw_t>
{
  static constexpr u16 id = 2304;
  static constexpr bool is_unpacked = true;
};

template <> struct MessageTraits<msg_imu_raw_t>
{
  static constexpr u16 id = 2304;
  static constexpr bool is_unpacked = false;
};

template <> struct MessageTraits<sbp_msg_imu_aux_t>
{
  static constexpr u16 id = 2305;
  static constexpr bool is_unpacked = true;
};

template <> struct MessageTraits<msg_imu_aux_t>
{
  static constexpr u16 id = 2305;
  static constexpr bool is_unpacked = false;
};

template <> struct MessageTraits<sbp_msg_mag_raw_t>
{
  static constexpr u16 id = 2306;
  static constexpr bool is_unpacked = true;
};

template <> struct MessageTraits<msg_mag_raw_t>
{
  static constexpr u16 id = 2306;
  static constexpr bool is_unpacked = false;
};

template <> struct MessageTraits<sbp_msg_odometry_t>
{
  static constexpr u16 id = 2307;
  static constexpr bool is_unpacked = true;
};

template <> struct MessageTraits<msg_odometry_t>
{
  static constexpr u16 id = 2307;
  static constexpr bool is_unpacked = false;
};

template <> struct MessageTraits<sbp_msg_wheeltick_t>
{
  static constexpr u16 id = 2308;
  static constexpr bool is_unpacked = true;
};

template <> struct MessageTraits<msg_wheeltick_t>
{
  static constexpr u16 id = 2308;
  static constexpr bool is_unpacked = false;
};

template <> struct MessageTraits<sbp_msg_fileio_config_req_t>
{
  static constexpr u16 id = 4097;
  static constexpr bool is_unpacked = true;
};

template <> struct MessageTraits<msg_fileio_config_req_t>
{
  static constexpr u16 id = 4097;
  static constexpr bool is_unpacked = false;
};

template <> struct MessageTraits<sbp_msg_fileio_config_resp_t>
{
  static constexpr u16 id = 4098;
  static constexpr bool is_unpacked = true;
};

template <> struct MessageTraits<msg_fileio_config_resp_t>
{
  static constexpr u16 id = 4098;
  static constexpr bool is_unpacked = false;
};

template <> struct MessageTraits<sbp_msg_sbas_raw_t>
{
  static constexpr u16 id = 30583;
  static constexpr bool is_unpacked = true;
};

template <> struct MessageTraits<msg_sbas_raw_t>
{
  static constexpr u16 id = 30583;
  static constexpr bool is_unpacked = false;
};

template <> struct MessageTraits<sbp_msg_linux_cpu_state_dep_a_t>
{
  static constexpr u16 id = 32512;
  static constexpr bool is_unpacked = true;
};

template <> struct MessageTraits<msg_linux_cpu_state_dep_a_t>
{
  static constexpr u16 id = 32512;
  static constexpr bool is_unpacked = false;
};

template <> struct MessageTraits<sbp_msg_linux_mem_state_dep_a_t>
{
  static constexpr u16 id = 32513;
  static constexpr bool is_unpacked = true;
};

template <> struct MessageTraits<msg_linux_mem_state_dep_a_t>
{
  static constexpr u16 id = 32513;
  static constexpr bool is_unpacked = false;
};

template <> struct MessageTraits<sbp_msg_linux_sys_state_dep_a_t>
{
  static constexpr u16 id = 32514;
  static constexpr bool is_unpacked = true;
};

template <> struct MessageTraits<msg_linux_sys_state_dep_a_t>
{
  static constexpr u16 id = 32514;
  static constexpr bool is_unpacked = false;
};

template <> struct MessageTraits<sbp_msg_linux_process_socket_counts_t>
{
  static constexpr u16 id = 32515;
  static constexpr bool is_unpacked = true;
};

template <> struct MessageTraits<msg_linux_process_socket_counts_t>
{
  static constexpr u16 id = 32515;
  static constexpr bool is_unpacked = false;
};

template <> struct MessageTraits<sbp_msg_linux_process_socket_queues_t>
{
  static constexpr u16 id = 32516;
  static constexpr bool is_unpacked = true;
};

template <> struct MessageTraits<msg_linux_process_socket_queues_t>
{
  static constexpr u16 id = 32516;
  static constexpr bool is_unpacked = false;
};

template <> struct MessageTraits<sbp_msg_linux_socket_usage_t>
{
  static constexpr u16 id = 32517;
  static constexpr bool is_unpacked = true;
};

template <> struct MessageTraits<msg_linux_socket_usage_t>
{
  static constexpr u16 id = 32517;
  static constexpr bool is_unpacked = false;
};

template <> struct MessageTraits<sbp_msg_linux_process_fd_count_t>
{
  static constexpr u16 id = 32518;
  static constexpr bool is_unpacked = true;
};

template <> struct MessageTraits<msg_linux_process_fd_count_t>
{
  static constexpr u16 id = 32518;
  static constexpr bool is_unpacked = false;
};

template <> struct MessageTraits<sbp_msg_linux_process_fd_summary_t>
{
  static constexpr u16 id = 32519;
  static constexpr bool is_unpacked = true;
};

template <> struct MessageTraits<msg_linux_process_fd_summary_t>
{
  static constexpr u16 id = 32519;
  static constexpr bool is_unpacked = false;
};

template <> struct MessageTraits<sbp_msg_linux_cpu_state_t>
{
  static constexpr u16 id = 32520;
  static constexpr bool is_unpacked = true;
};

template <> struct MessageTraits<msg_linux_cpu_state_t>
{
  static constexpr u16 id = 32520;
  static constexpr bool is_unpacked = false;
};

template <> struct MessageTraits<sbp_msg_linux_mem_state_t>
{
  static constexpr u16 id = 32521;
  static constexpr bool is_unpacked = true;
};

template <> struct MessageTraits<msg_linux_mem_state_t>
{
  static constexpr u16 id = 32521;
  static constexpr bool is_unpacked = false;
};

template <> struct MessageTraits<sbp_msg_linux_sys_state_t>
{
  static constexpr u16 id = 32522;
  static constexpr bool is_unpacked = true;
};

template <> struct MessageTraits<msg_linux_sys_state_t>
{
  static constexpr u16 id = 32522;
  static constexpr bool is_unpacked = false;
};

template <> struct MessageTraits<sbp_msg_startup_t>
{
  static constexpr u16 id = 65280;
  static constexpr bool is_unpacked = true;
};

template <> struct MessageTraits<msg_startup_t>
{
  static constexpr u16 id = 65280;
  static constexpr bool is_unpacked = false;
};

template <> struct MessageTraits<sbp_msg_dgnss_status_t>
{
  static constexpr u16 id = 65282;
  static constexpr bool is_unpacked = true;
};

template <> struct MessageTraits<msg_dgnss_status_t>
{
  static constexpr u16 id = 65282;
  static constexpr bool is_unpacked = false;
};

template <> struct MessageTraits<sbp_msg_ins_status_t>
{
  static constexpr u16 id = 65283;
  static constexpr bool is_unpacked = true;
};

template <> struct MessageTraits<msg_ins_status_t>
{
  static constexpr u16 id = 65283;
  static constexpr bool is_unpacked = false;
};

template <> struct MessageTraits<sbp_msg_csac_telemetry_t>
{
  static constexpr u16 id = 65284;
  static constexpr bool is_unpacked = true;
};

template <> struct MessageTraits<msg_csac_telemetry_t>
{
  static constexpr u16 id = 65284;
  static constexpr bool is_unpacked = false;
};

template <> struct MessageTraits<sbp_msg_csac_telemetry_labels_t>
{
  static constexpr u16 id = 65285;
  static constexpr bool is_unpacked = true;
};

template <> struct MessageTraits<msg_csac_telemetry_labels_t>
{
  static constexpr u16 id = 65285;
  static constexpr bool is_unpacked = false;
};

template <> struct MessageTraits<sbp_msg_ins_updates_t>
{
  static constexpr u16 id = 65286;
  static constexpr bool is_unpacked = true;
};

template <> struct MessageTraits<msg_ins_updates_t>
{
  static constexpr u16 id = 65286;
  static constexpr bool is_unpacked = false;
};

template <> struct MessageTraits<sbp_msg_gnss_time_offset_t>
{
  static constexpr u16 id = 65287;
  static constexpr bool is_unpacked = true;
};

template <> struct MessageTraits<msg_gnss_time_offset_t>
{
  static constexpr u16 id = 65287;
  static constexpr bool is_unpacked = false;
};

template <> struct MessageTraits<sbp_msg_group_meta_t>
{
  static constexpr u16 id = 65290;
  static constexpr bool is_unpacked = true;
};

template <> struct MessageTraits<msg_group_meta_t>
{
  static constexpr u16 id = 65290;
  static constexpr bool is_unpacked = false;
};

template <> struct MessageTraits<sbp_msg_soln_meta_t>
{
  static constexpr u16 id = 65294;
  static constexpr bool is_unpacked = true;
};

template <> struct MessageTraits<msg_soln_meta_t>
{
  static constexpr u16 id = 65294;
  static constexpr bool is_unpacked = false;
};

template <> struct MessageTraits<sbp_msg_soln_meta_dep_a_t>
{
  static constexpr u16 id = 65295;
  static constexpr bool is_unpacked = true;
};

template <> struct MessageTraits<msg_soln_meta_dep_a_t>
{
  static constexpr u16 id = 65295;
  static constexpr bool is_unpacked = false;
};

template <> struct MessageTraits<sbp_msg_status_report_t>
{
  static constexpr u16 id = 65534;
  static constexpr bool is_unpacked = true;
};

template <> struct MessageTraits<msg_status_report_t>
{
  static constexpr u16 id = 65534;
  static constexpr bool is_unpacked = false;
};

template <> struct MessageTraits<sbp_msg_heartbeat_t>
{
  static constexpr u16 id = 65535;
  static constexpr bool is_unpacked = true;
};

template <> struct MessageTraits<msg_heartbeat_t>
{
  static constexpr u16 id = 65535;
  static constexpr bool is_unpacked = false;
};

} // namespace sbp

#endif // SBP_CPP_MESSAGE_TRAITS_H