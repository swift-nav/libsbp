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
  static const sbp_msg_print_dep_t &get(const sbp_msg_t &msg) { 
    return msg.print_dep;
  }
};



template<>
struct MessageTraits<sbp_msg_tracking_state_detailed_dep_t> {
  static constexpr u16 id = 17;
  static const sbp_msg_tracking_state_detailed_dep_t &get(const sbp_msg_t &msg) { 
    return msg.tracking_state_detailed_dep;
  }
};



template<>
struct MessageTraits<sbp_msg_tracking_state_dep_b_t> {
  static constexpr u16 id = 19;
  static const sbp_msg_tracking_state_dep_b_t &get(const sbp_msg_t &msg) { 
    return msg.tracking_state_dep_b;
  }
};



template<>
struct MessageTraits<sbp_msg_acq_result_dep_b_t> {
  static constexpr u16 id = 20;
  static const sbp_msg_acq_result_dep_b_t &get(const sbp_msg_t &msg) { 
    return msg.acq_result_dep_b;
  }
};



template<>
struct MessageTraits<sbp_msg_acq_result_dep_a_t> {
  static constexpr u16 id = 21;
  static const sbp_msg_acq_result_dep_a_t &get(const sbp_msg_t &msg) { 
    return msg.acq_result_dep_a;
  }
};



template<>
struct MessageTraits<sbp_msg_tracking_state_dep_a_t> {
  static constexpr u16 id = 22;
  static const sbp_msg_tracking_state_dep_a_t &get(const sbp_msg_t &msg) { 
    return msg.tracking_state_dep_a;
  }
};



template<>
struct MessageTraits<sbp_msg_thread_state_t> {
  static constexpr u16 id = 23;
  static const sbp_msg_thread_state_t &get(const sbp_msg_t &msg) { 
    return msg.thread_state;
  }
};



template<>
struct MessageTraits<sbp_msg_uart_state_depa_t> {
  static constexpr u16 id = 24;
  static const sbp_msg_uart_state_depa_t &get(const sbp_msg_t &msg) { 
    return msg.uart_state_depa;
  }
};



template<>
struct MessageTraits<sbp_msg_iar_state_t> {
  static constexpr u16 id = 25;
  static const sbp_msg_iar_state_t &get(const sbp_msg_t &msg) { 
    return msg.iar_state;
  }
};



template<>
struct MessageTraits<sbp_msg_ephemeris_dep_a_t> {
  static constexpr u16 id = 26;
  static const sbp_msg_ephemeris_dep_a_t &get(const sbp_msg_t &msg) { 
    return msg.ephemeris_dep_a;
  }
};



template<>
struct MessageTraits<sbp_msg_mask_satellite_dep_t> {
  static constexpr u16 id = 27;
  static const sbp_msg_mask_satellite_dep_t &get(const sbp_msg_t &msg) { 
    return msg.mask_satellite_dep;
  }
};



template<>
struct MessageTraits<sbp_msg_tracking_iq_dep_a_t> {
  static constexpr u16 id = 28;
  static const sbp_msg_tracking_iq_dep_a_t &get(const sbp_msg_t &msg) { 
    return msg.tracking_iq_dep_a;
  }
};



template<>
struct MessageTraits<sbp_msg_uart_state_t> {
  static constexpr u16 id = 29;
  static const sbp_msg_uart_state_t &get(const sbp_msg_t &msg) { 
    return msg.uart_state;
  }
};



template<>
struct MessageTraits<sbp_msg_acq_sv_profile_dep_t> {
  static constexpr u16 id = 30;
  static const sbp_msg_acq_sv_profile_dep_t &get(const sbp_msg_t &msg) { 
    return msg.acq_sv_profile_dep;
  }
};



template<>
struct MessageTraits<sbp_msg_acq_result_dep_c_t> {
  static constexpr u16 id = 31;
  static const sbp_msg_acq_result_dep_c_t &get(const sbp_msg_t &msg) { 
    return msg.acq_result_dep_c;
  }
};



template<>
struct MessageTraits<sbp_msg_tracking_state_detailed_dep_a_t> {
  static constexpr u16 id = 33;
  static const sbp_msg_tracking_state_detailed_dep_a_t &get(const sbp_msg_t &msg) { 
    return msg.tracking_state_detailed_dep_a;
  }
};



template<>
struct MessageTraits<sbp_msg_reset_filters_t> {
  static constexpr u16 id = 34;
  static const sbp_msg_reset_filters_t &get(const sbp_msg_t &msg) { 
    return msg.reset_filters;
  }
};



template<>
struct MessageTraits<sbp_msg_init_base_dep_t> {
  static constexpr u16 id = 35;
  static const sbp_msg_init_base_dep_t &get(const sbp_msg_t &msg) { 
    return msg.init_base_dep;
  }
};



template<>
struct MessageTraits<sbp_msg_mask_satellite_t> {
  static constexpr u16 id = 43;
  static const sbp_msg_mask_satellite_t &get(const sbp_msg_t &msg) { 
    return msg.mask_satellite;
  }
};



template<>
struct MessageTraits<sbp_msg_tracking_iq_dep_b_t> {
  static constexpr u16 id = 44;
  static const sbp_msg_tracking_iq_dep_b_t &get(const sbp_msg_t &msg) { 
    return msg.tracking_iq_dep_b;
  }
};



template<>
struct MessageTraits<sbp_msg_tracking_iq_t> {
  static constexpr u16 id = 45;
  static const sbp_msg_tracking_iq_t &get(const sbp_msg_t &msg) { 
    return msg.tracking_iq;
  }
};



template<>
struct MessageTraits<sbp_msg_acq_sv_profile_t> {
  static constexpr u16 id = 46;
  static const sbp_msg_acq_sv_profile_t &get(const sbp_msg_t &msg) { 
    return msg.acq_sv_profile;
  }
};



template<>
struct MessageTraits<sbp_msg_acq_result_t> {
  static constexpr u16 id = 47;
  static const sbp_msg_acq_result_t &get(const sbp_msg_t &msg) { 
    return msg.acq_result;
  }
};



template<>
struct MessageTraits<sbp_msg_tracking_state_t> {
  static constexpr u16 id = 65;
  static const sbp_msg_tracking_state_t &get(const sbp_msg_t &msg) { 
    return msg.tracking_state;
  }
};



template<>
struct MessageTraits<sbp_msg_obs_dep_b_t> {
  static constexpr u16 id = 67;
  static const sbp_msg_obs_dep_b_t &get(const sbp_msg_t &msg) { 
    return msg.obs_dep_b;
  }
};



template<>
struct MessageTraits<sbp_msg_base_pos_llh_t> {
  static constexpr u16 id = 68;
  static const sbp_msg_base_pos_llh_t &get(const sbp_msg_t &msg) { 
    return msg.base_pos_llh;
  }
};



template<>
struct MessageTraits<sbp_msg_obs_dep_a_t> {
  static constexpr u16 id = 69;
  static const sbp_msg_obs_dep_a_t &get(const sbp_msg_t &msg) { 
    return msg.obs_dep_a;
  }
};



template<>
struct MessageTraits<sbp_msg_ephemeris_dep_b_t> {
  static constexpr u16 id = 70;
  static const sbp_msg_ephemeris_dep_b_t &get(const sbp_msg_t &msg) { 
    return msg.ephemeris_dep_b;
  }
};



template<>
struct MessageTraits<sbp_msg_ephemeris_dep_c_t> {
  static constexpr u16 id = 71;
  static const sbp_msg_ephemeris_dep_c_t &get(const sbp_msg_t &msg) { 
    return msg.ephemeris_dep_c;
  }
};



template<>
struct MessageTraits<sbp_msg_base_pos_ecef_t> {
  static constexpr u16 id = 72;
  static const sbp_msg_base_pos_ecef_t &get(const sbp_msg_t &msg) { 
    return msg.base_pos_ecef;
  }
};



template<>
struct MessageTraits<sbp_msg_obs_dep_c_t> {
  static constexpr u16 id = 73;
  static const sbp_msg_obs_dep_c_t &get(const sbp_msg_t &msg) { 
    return msg.obs_dep_c;
  }
};



template<>
struct MessageTraits<sbp_msg_obs_t> {
  static constexpr u16 id = 74;
  static const sbp_msg_obs_t &get(const sbp_msg_t &msg) { 
    return msg.obs;
  }
};



template<>
struct MessageTraits<sbp_msg_specan_dep_t> {
  static constexpr u16 id = 80;
  static const sbp_msg_specan_dep_t &get(const sbp_msg_t &msg) { 
    return msg.specan_dep;
  }
};



template<>
struct MessageTraits<sbp_msg_specan_t> {
  static constexpr u16 id = 81;
  static const sbp_msg_specan_t &get(const sbp_msg_t &msg) { 
    return msg.specan;
  }
};



template<>
struct MessageTraits<sbp_msg_measurement_state_t> {
  static constexpr u16 id = 97;
  static const sbp_msg_measurement_state_t &get(const sbp_msg_t &msg) { 
    return msg.measurement_state;
  }
};



template<>
struct MessageTraits<sbp_msg_set_time_t> {
  static constexpr u16 id = 104;
  static const sbp_msg_set_time_t &get(const sbp_msg_t &msg) { 
    return msg.set_time;
  }
};



template<>
struct MessageTraits<sbp_msg_almanac_t> {
  static constexpr u16 id = 105;
  static const sbp_msg_almanac_t &get(const sbp_msg_t &msg) { 
    return msg.almanac;
  }
};



template<>
struct MessageTraits<sbp_msg_almanac_gps_dep_t> {
  static constexpr u16 id = 112;
  static const sbp_msg_almanac_gps_dep_t &get(const sbp_msg_t &msg) { 
    return msg.almanac_gps_dep;
  }
};



template<>
struct MessageTraits<sbp_msg_almanac_glo_dep_t> {
  static constexpr u16 id = 113;
  static const sbp_msg_almanac_glo_dep_t &get(const sbp_msg_t &msg) { 
    return msg.almanac_glo_dep;
  }
};



template<>
struct MessageTraits<sbp_msg_almanac_gps_t> {
  static constexpr u16 id = 114;
  static const sbp_msg_almanac_gps_t &get(const sbp_msg_t &msg) { 
    return msg.almanac_gps;
  }
};



template<>
struct MessageTraits<sbp_msg_almanac_glo_t> {
  static constexpr u16 id = 115;
  static const sbp_msg_almanac_glo_t &get(const sbp_msg_t &msg) { 
    return msg.almanac_glo;
  }
};



template<>
struct MessageTraits<sbp_msg_glo_biases_t> {
  static constexpr u16 id = 117;
  static const sbp_msg_glo_biases_t &get(const sbp_msg_t &msg) { 
    return msg.glo_biases;
  }
};



template<>
struct MessageTraits<sbp_msg_ephemeris_dep_d_t> {
  static constexpr u16 id = 128;
  static const sbp_msg_ephemeris_dep_d_t &get(const sbp_msg_t &msg) { 
    return msg.ephemeris_dep_d;
  }
};



template<>
struct MessageTraits<sbp_msg_ephemeris_gps_dep_e_t> {
  static constexpr u16 id = 129;
  static const sbp_msg_ephemeris_gps_dep_e_t &get(const sbp_msg_t &msg) { 
    return msg.ephemeris_gps_dep_e;
  }
};



template<>
struct MessageTraits<sbp_msg_ephemeris_sbas_dep_a_t> {
  static constexpr u16 id = 130;
  static const sbp_msg_ephemeris_sbas_dep_a_t &get(const sbp_msg_t &msg) { 
    return msg.ephemeris_sbas_dep_a;
  }
};



template<>
struct MessageTraits<sbp_msg_ephemeris_glo_dep_a_t> {
  static constexpr u16 id = 131;
  static const sbp_msg_ephemeris_glo_dep_a_t &get(const sbp_msg_t &msg) { 
    return msg.ephemeris_glo_dep_a;
  }
};



template<>
struct MessageTraits<sbp_msg_ephemeris_sbas_dep_b_t> {
  static constexpr u16 id = 132;
  static const sbp_msg_ephemeris_sbas_dep_b_t &get(const sbp_msg_t &msg) { 
    return msg.ephemeris_sbas_dep_b;
  }
};



template<>
struct MessageTraits<sbp_msg_ephemeris_glo_dep_b_t> {
  static constexpr u16 id = 133;
  static const sbp_msg_ephemeris_glo_dep_b_t &get(const sbp_msg_t &msg) { 
    return msg.ephemeris_glo_dep_b;
  }
};



template<>
struct MessageTraits<sbp_msg_ephemeris_gps_dep_f_t> {
  static constexpr u16 id = 134;
  static const sbp_msg_ephemeris_gps_dep_f_t &get(const sbp_msg_t &msg) { 
    return msg.ephemeris_gps_dep_f;
  }
};



template<>
struct MessageTraits<sbp_msg_ephemeris_glo_dep_c_t> {
  static constexpr u16 id = 135;
  static const sbp_msg_ephemeris_glo_dep_c_t &get(const sbp_msg_t &msg) { 
    return msg.ephemeris_glo_dep_c;
  }
};



template<>
struct MessageTraits<sbp_msg_ephemeris_glo_dep_d_t> {
  static constexpr u16 id = 136;
  static const sbp_msg_ephemeris_glo_dep_d_t &get(const sbp_msg_t &msg) { 
    return msg.ephemeris_glo_dep_d;
  }
};



template<>
struct MessageTraits<sbp_msg_ephemeris_bds_t> {
  static constexpr u16 id = 137;
  static const sbp_msg_ephemeris_bds_t &get(const sbp_msg_t &msg) { 
    return msg.ephemeris_bds;
  }
};



template<>
struct MessageTraits<sbp_msg_ephemeris_gps_t> {
  static constexpr u16 id = 138;
  static const sbp_msg_ephemeris_gps_t &get(const sbp_msg_t &msg) { 
    return msg.ephemeris_gps;
  }
};



template<>
struct MessageTraits<sbp_msg_ephemeris_glo_t> {
  static constexpr u16 id = 139;
  static const sbp_msg_ephemeris_glo_t &get(const sbp_msg_t &msg) { 
    return msg.ephemeris_glo;
  }
};



template<>
struct MessageTraits<sbp_msg_ephemeris_sbas_t> {
  static constexpr u16 id = 140;
  static const sbp_msg_ephemeris_sbas_t &get(const sbp_msg_t &msg) { 
    return msg.ephemeris_sbas;
  }
};



template<>
struct MessageTraits<sbp_msg_ephemeris_gal_t> {
  static constexpr u16 id = 141;
  static const sbp_msg_ephemeris_gal_t &get(const sbp_msg_t &msg) { 
    return msg.ephemeris_gal;
  }
};



template<>
struct MessageTraits<sbp_msg_ephemeris_qzss_t> {
  static constexpr u16 id = 142;
  static const sbp_msg_ephemeris_qzss_t &get(const sbp_msg_t &msg) { 
    return msg.ephemeris_qzss;
  }
};



template<>
struct MessageTraits<sbp_msg_iono_t> {
  static constexpr u16 id = 144;
  static const sbp_msg_iono_t &get(const sbp_msg_t &msg) { 
    return msg.iono;
  }
};



template<>
struct MessageTraits<sbp_msg_sv_configuration_gps_dep_t> {
  static constexpr u16 id = 145;
  static const sbp_msg_sv_configuration_gps_dep_t &get(const sbp_msg_t &msg) { 
    return msg.sv_configuration_gps_dep;
  }
};



template<>
struct MessageTraits<sbp_msg_group_delay_dep_a_t> {
  static constexpr u16 id = 146;
  static const sbp_msg_group_delay_dep_a_t &get(const sbp_msg_t &msg) { 
    return msg.group_delay_dep_a;
  }
};



template<>
struct MessageTraits<sbp_msg_group_delay_dep_b_t> {
  static constexpr u16 id = 147;
  static const sbp_msg_group_delay_dep_b_t &get(const sbp_msg_t &msg) { 
    return msg.group_delay_dep_b;
  }
};



template<>
struct MessageTraits<sbp_msg_group_delay_t> {
  static constexpr u16 id = 148;
  static const sbp_msg_group_delay_t &get(const sbp_msg_t &msg) { 
    return msg.group_delay;
  }
};



template<>
struct MessageTraits<sbp_msg_ephemeris_gal_dep_a_t> {
  static constexpr u16 id = 149;
  static const sbp_msg_ephemeris_gal_dep_a_t &get(const sbp_msg_t &msg) { 
    return msg.ephemeris_gal_dep_a;
  }
};



template<>
struct MessageTraits<sbp_msg_gnss_capb_t> {
  static constexpr u16 id = 150;
  static const sbp_msg_gnss_capb_t &get(const sbp_msg_t &msg) { 
    return msg.gnss_capb;
  }
};



template<>
struct MessageTraits<sbp_msg_sv_az_el_t> {
  static constexpr u16 id = 151;
  static const sbp_msg_sv_az_el_t &get(const sbp_msg_t &msg) { 
    return msg.sv_az_el;
  }
};



template<>
struct MessageTraits<sbp_msg_settings_write_t> {
  static constexpr u16 id = 160;
  static const sbp_msg_settings_write_t &get(const sbp_msg_t &msg) { 
    return msg.settings_write;
  }
};



template<>
struct MessageTraits<sbp_msg_settings_save_t> {
  static constexpr u16 id = 161;
  static const sbp_msg_settings_save_t &get(const sbp_msg_t &msg) { 
    return msg.settings_save;
  }
};



template<>
struct MessageTraits<sbp_msg_settings_read_by_index_req_t> {
  static constexpr u16 id = 162;
  static const sbp_msg_settings_read_by_index_req_t &get(const sbp_msg_t &msg) { 
    return msg.settings_read_by_index_req;
  }
};



template<>
struct MessageTraits<sbp_msg_fileio_read_resp_t> {
  static constexpr u16 id = 163;
  static const sbp_msg_fileio_read_resp_t &get(const sbp_msg_t &msg) { 
    return msg.fileio_read_resp;
  }
};



template<>
struct MessageTraits<sbp_msg_settings_read_req_t> {
  static constexpr u16 id = 164;
  static const sbp_msg_settings_read_req_t &get(const sbp_msg_t &msg) { 
    return msg.settings_read_req;
  }
};



template<>
struct MessageTraits<sbp_msg_settings_read_resp_t> {
  static constexpr u16 id = 165;
  static const sbp_msg_settings_read_resp_t &get(const sbp_msg_t &msg) { 
    return msg.settings_read_resp;
  }
};



template<>
struct MessageTraits<sbp_msg_settings_read_by_index_done_t> {
  static constexpr u16 id = 166;
  static const sbp_msg_settings_read_by_index_done_t &get(const sbp_msg_t &msg) { 
    return msg.settings_read_by_index_done;
  }
};



template<>
struct MessageTraits<sbp_msg_settings_read_by_index_resp_t> {
  static constexpr u16 id = 167;
  static const sbp_msg_settings_read_by_index_resp_t &get(const sbp_msg_t &msg) { 
    return msg.settings_read_by_index_resp;
  }
};



template<>
struct MessageTraits<sbp_msg_fileio_read_req_t> {
  static constexpr u16 id = 168;
  static const sbp_msg_fileio_read_req_t &get(const sbp_msg_t &msg) { 
    return msg.fileio_read_req;
  }
};



template<>
struct MessageTraits<sbp_msg_fileio_read_dir_req_t> {
  static constexpr u16 id = 169;
  static const sbp_msg_fileio_read_dir_req_t &get(const sbp_msg_t &msg) { 
    return msg.fileio_read_dir_req;
  }
};



template<>
struct MessageTraits<sbp_msg_fileio_read_dir_resp_t> {
  static constexpr u16 id = 170;
  static const sbp_msg_fileio_read_dir_resp_t &get(const sbp_msg_t &msg) { 
    return msg.fileio_read_dir_resp;
  }
};



template<>
struct MessageTraits<sbp_msg_fileio_write_resp_t> {
  static constexpr u16 id = 171;
  static const sbp_msg_fileio_write_resp_t &get(const sbp_msg_t &msg) { 
    return msg.fileio_write_resp;
  }
};



template<>
struct MessageTraits<sbp_msg_fileio_remove_t> {
  static constexpr u16 id = 172;
  static const sbp_msg_fileio_remove_t &get(const sbp_msg_t &msg) { 
    return msg.fileio_remove;
  }
};



template<>
struct MessageTraits<sbp_msg_fileio_write_req_t> {
  static constexpr u16 id = 173;
  static const sbp_msg_fileio_write_req_t &get(const sbp_msg_t &msg) { 
    return msg.fileio_write_req;
  }
};



template<>
struct MessageTraits<sbp_msg_settings_register_t> {
  static constexpr u16 id = 174;
  static const sbp_msg_settings_register_t &get(const sbp_msg_t &msg) { 
    return msg.settings_register;
  }
};



template<>
struct MessageTraits<sbp_msg_settings_write_resp_t> {
  static constexpr u16 id = 175;
  static const sbp_msg_settings_write_resp_t &get(const sbp_msg_t &msg) { 
    return msg.settings_write_resp;
  }
};



template<>
struct MessageTraits<sbp_msg_bootloader_handshake_dep_a_t> {
  static constexpr u16 id = 176;
  static const sbp_msg_bootloader_handshake_dep_a_t &get(const sbp_msg_t &msg) { 
    return msg.bootloader_handshake_dep_a;
  }
};



template<>
struct MessageTraits<sbp_msg_bootloader_jump_to_app_t> {
  static constexpr u16 id = 177;
  static const sbp_msg_bootloader_jump_to_app_t &get(const sbp_msg_t &msg) { 
    return msg.bootloader_jump_to_app;
  }
};



template<>
struct MessageTraits<sbp_msg_reset_dep_t> {
  static constexpr u16 id = 178;
  static const sbp_msg_reset_dep_t &get(const sbp_msg_t &msg) { 
    return msg.reset_dep;
  }
};



template<>
struct MessageTraits<sbp_msg_bootloader_handshake_req_t> {
  static constexpr u16 id = 179;
  static const sbp_msg_bootloader_handshake_req_t &get(const sbp_msg_t &msg) { 
    return msg.bootloader_handshake_req;
  }
};



template<>
struct MessageTraits<sbp_msg_bootloader_handshake_resp_t> {
  static constexpr u16 id = 180;
  static const sbp_msg_bootloader_handshake_resp_t &get(const sbp_msg_t &msg) { 
    return msg.bootloader_handshake_resp;
  }
};



template<>
struct MessageTraits<sbp_msg_device_monitor_t> {
  static constexpr u16 id = 181;
  static const sbp_msg_device_monitor_t &get(const sbp_msg_t &msg) { 
    return msg.device_monitor;
  }
};



template<>
struct MessageTraits<sbp_msg_reset_t> {
  static constexpr u16 id = 182;
  static const sbp_msg_reset_t &get(const sbp_msg_t &msg) { 
    return msg.reset;
  }
};



template<>
struct MessageTraits<sbp_msg_command_req_t> {
  static constexpr u16 id = 184;
  static const sbp_msg_command_req_t &get(const sbp_msg_t &msg) { 
    return msg.command_req;
  }
};



template<>
struct MessageTraits<sbp_msg_command_resp_t> {
  static constexpr u16 id = 185;
  static const sbp_msg_command_resp_t &get(const sbp_msg_t &msg) { 
    return msg.command_resp;
  }
};



template<>
struct MessageTraits<sbp_msg_network_state_req_t> {
  static constexpr u16 id = 186;
  static const sbp_msg_network_state_req_t &get(const sbp_msg_t &msg) { 
    return msg.network_state_req;
  }
};



template<>
struct MessageTraits<sbp_msg_network_state_resp_t> {
  static constexpr u16 id = 187;
  static const sbp_msg_network_state_resp_t &get(const sbp_msg_t &msg) { 
    return msg.network_state_resp;
  }
};



template<>
struct MessageTraits<sbp_msg_command_output_t> {
  static constexpr u16 id = 188;
  static const sbp_msg_command_output_t &get(const sbp_msg_t &msg) { 
    return msg.command_output;
  }
};



template<>
struct MessageTraits<sbp_msg_network_bandwidth_usage_t> {
  static constexpr u16 id = 189;
  static const sbp_msg_network_bandwidth_usage_t &get(const sbp_msg_t &msg) { 
    return msg.network_bandwidth_usage;
  }
};



template<>
struct MessageTraits<sbp_msg_cell_modem_status_t> {
  static constexpr u16 id = 190;
  static const sbp_msg_cell_modem_status_t &get(const sbp_msg_t &msg) { 
    return msg.cell_modem_status;
  }
};



template<>
struct MessageTraits<sbp_msg_front_end_gain_t> {
  static constexpr u16 id = 191;
  static const sbp_msg_front_end_gain_t &get(const sbp_msg_t &msg) { 
    return msg.front_end_gain;
  }
};



template<>
struct MessageTraits<sbp_msg_cw_results_t> {
  static constexpr u16 id = 192;
  static const sbp_msg_cw_results_t &get(const sbp_msg_t &msg) { 
    return msg.cw_results;
  }
};



template<>
struct MessageTraits<sbp_msg_cw_start_t> {
  static constexpr u16 id = 193;
  static const sbp_msg_cw_start_t &get(const sbp_msg_t &msg) { 
    return msg.cw_start;
  }
};



template<>
struct MessageTraits<sbp_msg_nap_device_dna_resp_t> {
  static constexpr u16 id = 221;
  static const sbp_msg_nap_device_dna_resp_t &get(const sbp_msg_t &msg) { 
    return msg.nap_device_dna_resp;
  }
};



template<>
struct MessageTraits<sbp_msg_nap_device_dna_req_t> {
  static constexpr u16 id = 222;
  static const sbp_msg_nap_device_dna_req_t &get(const sbp_msg_t &msg) { 
    return msg.nap_device_dna_req;
  }
};



template<>
struct MessageTraits<sbp_msg_flash_done_t> {
  static constexpr u16 id = 224;
  static const sbp_msg_flash_done_t &get(const sbp_msg_t &msg) { 
    return msg.flash_done;
  }
};



template<>
struct MessageTraits<sbp_msg_flash_read_resp_t> {
  static constexpr u16 id = 225;
  static const sbp_msg_flash_read_resp_t &get(const sbp_msg_t &msg) { 
    return msg.flash_read_resp;
  }
};



template<>
struct MessageTraits<sbp_msg_flash_erase_t> {
  static constexpr u16 id = 226;
  static const sbp_msg_flash_erase_t &get(const sbp_msg_t &msg) { 
    return msg.flash_erase;
  }
};



template<>
struct MessageTraits<sbp_msg_stm_flash_lock_sector_t> {
  static constexpr u16 id = 227;
  static const sbp_msg_stm_flash_lock_sector_t &get(const sbp_msg_t &msg) { 
    return msg.stm_flash_lock_sector;
  }
};



template<>
struct MessageTraits<sbp_msg_stm_flash_unlock_sector_t> {
  static constexpr u16 id = 228;
  static const sbp_msg_stm_flash_unlock_sector_t &get(const sbp_msg_t &msg) { 
    return msg.stm_flash_unlock_sector;
  }
};



template<>
struct MessageTraits<sbp_msg_stm_unique_id_resp_t> {
  static constexpr u16 id = 229;
  static const sbp_msg_stm_unique_id_resp_t &get(const sbp_msg_t &msg) { 
    return msg.stm_unique_id_resp;
  }
};



template<>
struct MessageTraits<sbp_msg_flash_program_t> {
  static constexpr u16 id = 230;
  static const sbp_msg_flash_program_t &get(const sbp_msg_t &msg) { 
    return msg.flash_program;
  }
};



template<>
struct MessageTraits<sbp_msg_flash_read_req_t> {
  static constexpr u16 id = 231;
  static const sbp_msg_flash_read_req_t &get(const sbp_msg_t &msg) { 
    return msg.flash_read_req;
  }
};



template<>
struct MessageTraits<sbp_msg_stm_unique_id_req_t> {
  static constexpr u16 id = 232;
  static const sbp_msg_stm_unique_id_req_t &get(const sbp_msg_t &msg) { 
    return msg.stm_unique_id_req;
  }
};



template<>
struct MessageTraits<sbp_msg_m25_flash_write_status_t> {
  static constexpr u16 id = 243;
  static const sbp_msg_m25_flash_write_status_t &get(const sbp_msg_t &msg) { 
    return msg.m25_flash_write_status;
  }
};



template<>
struct MessageTraits<sbp_msg_gps_time_dep_a_t> {
  static constexpr u16 id = 256;
  static const sbp_msg_gps_time_dep_a_t &get(const sbp_msg_t &msg) { 
    return msg.gps_time_dep_a;
  }
};



template<>
struct MessageTraits<sbp_msg_ext_event_t> {
  static constexpr u16 id = 257;
  static const sbp_msg_ext_event_t &get(const sbp_msg_t &msg) { 
    return msg.ext_event;
  }
};



template<>
struct MessageTraits<sbp_msg_gps_time_t> {
  static constexpr u16 id = 258;
  static const sbp_msg_gps_time_t &get(const sbp_msg_t &msg) { 
    return msg.gps_time;
  }
};



template<>
struct MessageTraits<sbp_msg_utc_time_t> {
  static constexpr u16 id = 259;
  static const sbp_msg_utc_time_t &get(const sbp_msg_t &msg) { 
    return msg.utc_time;
  }
};



template<>
struct MessageTraits<sbp_msg_gps_time_gnss_t> {
  static constexpr u16 id = 260;
  static const sbp_msg_gps_time_gnss_t &get(const sbp_msg_t &msg) { 
    return msg.gps_time_gnss;
  }
};



template<>
struct MessageTraits<sbp_msg_utc_time_gnss_t> {
  static constexpr u16 id = 261;
  static const sbp_msg_utc_time_gnss_t &get(const sbp_msg_t &msg) { 
    return msg.utc_time_gnss;
  }
};



template<>
struct MessageTraits<sbp_msg_settings_register_resp_t> {
  static constexpr u16 id = 431;
  static const sbp_msg_settings_register_resp_t &get(const sbp_msg_t &msg) { 
    return msg.settings_register_resp;
  }
};



template<>
struct MessageTraits<sbp_msg_pos_ecef_dep_a_t> {
  static constexpr u16 id = 512;
  static const sbp_msg_pos_ecef_dep_a_t &get(const sbp_msg_t &msg) { 
    return msg.pos_ecef_dep_a;
  }
};



template<>
struct MessageTraits<sbp_msg_pos_llh_dep_a_t> {
  static constexpr u16 id = 513;
  static const sbp_msg_pos_llh_dep_a_t &get(const sbp_msg_t &msg) { 
    return msg.pos_llh_dep_a;
  }
};



template<>
struct MessageTraits<sbp_msg_baseline_ecef_dep_a_t> {
  static constexpr u16 id = 514;
  static const sbp_msg_baseline_ecef_dep_a_t &get(const sbp_msg_t &msg) { 
    return msg.baseline_ecef_dep_a;
  }
};



template<>
struct MessageTraits<sbp_msg_baseline_ned_dep_a_t> {
  static constexpr u16 id = 515;
  static const sbp_msg_baseline_ned_dep_a_t &get(const sbp_msg_t &msg) { 
    return msg.baseline_ned_dep_a;
  }
};



template<>
struct MessageTraits<sbp_msg_vel_ecef_dep_a_t> {
  static constexpr u16 id = 516;
  static const sbp_msg_vel_ecef_dep_a_t &get(const sbp_msg_t &msg) { 
    return msg.vel_ecef_dep_a;
  }
};



template<>
struct MessageTraits<sbp_msg_vel_ned_dep_a_t> {
  static constexpr u16 id = 517;
  static const sbp_msg_vel_ned_dep_a_t &get(const sbp_msg_t &msg) { 
    return msg.vel_ned_dep_a;
  }
};



template<>
struct MessageTraits<sbp_msg_dops_dep_a_t> {
  static constexpr u16 id = 518;
  static const sbp_msg_dops_dep_a_t &get(const sbp_msg_t &msg) { 
    return msg.dops_dep_a;
  }
};



template<>
struct MessageTraits<sbp_msg_baseline_heading_dep_a_t> {
  static constexpr u16 id = 519;
  static const sbp_msg_baseline_heading_dep_a_t &get(const sbp_msg_t &msg) { 
    return msg.baseline_heading_dep_a;
  }
};



template<>
struct MessageTraits<sbp_msg_dops_t> {
  static constexpr u16 id = 520;
  static const sbp_msg_dops_t &get(const sbp_msg_t &msg) { 
    return msg.dops;
  }
};



template<>
struct MessageTraits<sbp_msg_pos_ecef_t> {
  static constexpr u16 id = 521;
  static const sbp_msg_pos_ecef_t &get(const sbp_msg_t &msg) { 
    return msg.pos_ecef;
  }
};



template<>
struct MessageTraits<sbp_msg_pos_llh_t> {
  static constexpr u16 id = 522;
  static const sbp_msg_pos_llh_t &get(const sbp_msg_t &msg) { 
    return msg.pos_llh;
  }
};



template<>
struct MessageTraits<sbp_msg_baseline_ecef_t> {
  static constexpr u16 id = 523;
  static const sbp_msg_baseline_ecef_t &get(const sbp_msg_t &msg) { 
    return msg.baseline_ecef;
  }
};



template<>
struct MessageTraits<sbp_msg_baseline_ned_t> {
  static constexpr u16 id = 524;
  static const sbp_msg_baseline_ned_t &get(const sbp_msg_t &msg) { 
    return msg.baseline_ned;
  }
};



template<>
struct MessageTraits<sbp_msg_vel_ecef_t> {
  static constexpr u16 id = 525;
  static const sbp_msg_vel_ecef_t &get(const sbp_msg_t &msg) { 
    return msg.vel_ecef;
  }
};



template<>
struct MessageTraits<sbp_msg_vel_ned_t> {
  static constexpr u16 id = 526;
  static const sbp_msg_vel_ned_t &get(const sbp_msg_t &msg) { 
    return msg.vel_ned;
  }
};



template<>
struct MessageTraits<sbp_msg_baseline_heading_t> {
  static constexpr u16 id = 527;
  static const sbp_msg_baseline_heading_t &get(const sbp_msg_t &msg) { 
    return msg.baseline_heading;
  }
};



template<>
struct MessageTraits<sbp_msg_age_corrections_t> {
  static constexpr u16 id = 528;
  static const sbp_msg_age_corrections_t &get(const sbp_msg_t &msg) { 
    return msg.age_corrections;
  }
};



template<>
struct MessageTraits<sbp_msg_pos_llh_cov_t> {
  static constexpr u16 id = 529;
  static const sbp_msg_pos_llh_cov_t &get(const sbp_msg_t &msg) { 
    return msg.pos_llh_cov;
  }
};



template<>
struct MessageTraits<sbp_msg_vel_ned_cov_t> {
  static constexpr u16 id = 530;
  static const sbp_msg_vel_ned_cov_t &get(const sbp_msg_t &msg) { 
    return msg.vel_ned_cov;
  }
};



template<>
struct MessageTraits<sbp_msg_vel_body_t> {
  static constexpr u16 id = 531;
  static const sbp_msg_vel_body_t &get(const sbp_msg_t &msg) { 
    return msg.vel_body;
  }
};



template<>
struct MessageTraits<sbp_msg_pos_ecef_cov_t> {
  static constexpr u16 id = 532;
  static const sbp_msg_pos_ecef_cov_t &get(const sbp_msg_t &msg) { 
    return msg.pos_ecef_cov;
  }
};



template<>
struct MessageTraits<sbp_msg_vel_ecef_cov_t> {
  static constexpr u16 id = 533;
  static const sbp_msg_vel_ecef_cov_t &get(const sbp_msg_t &msg) { 
    return msg.vel_ecef_cov;
  }
};



template<>
struct MessageTraits<sbp_msg_protection_level_dep_a_t> {
  static constexpr u16 id = 534;
  static const sbp_msg_protection_level_dep_a_t &get(const sbp_msg_t &msg) { 
    return msg.protection_level_dep_a;
  }
};



template<>
struct MessageTraits<sbp_msg_protection_level_t> {
  static constexpr u16 id = 535;
  static const sbp_msg_protection_level_t &get(const sbp_msg_t &msg) { 
    return msg.protection_level;
  }
};



template<>
struct MessageTraits<sbp_msg_orient_quat_t> {
  static constexpr u16 id = 544;
  static const sbp_msg_orient_quat_t &get(const sbp_msg_t &msg) { 
    return msg.orient_quat;
  }
};



template<>
struct MessageTraits<sbp_msg_orient_euler_t> {
  static constexpr u16 id = 545;
  static const sbp_msg_orient_euler_t &get(const sbp_msg_t &msg) { 
    return msg.orient_euler;
  }
};



template<>
struct MessageTraits<sbp_msg_angular_rate_t> {
  static constexpr u16 id = 546;
  static const sbp_msg_angular_rate_t &get(const sbp_msg_t &msg) { 
    return msg.angular_rate;
  }
};



template<>
struct MessageTraits<sbp_msg_pos_ecef_gnss_t> {
  static constexpr u16 id = 553;
  static const sbp_msg_pos_ecef_gnss_t &get(const sbp_msg_t &msg) { 
    return msg.pos_ecef_gnss;
  }
};



template<>
struct MessageTraits<sbp_msg_pos_llh_gnss_t> {
  static constexpr u16 id = 554;
  static const sbp_msg_pos_llh_gnss_t &get(const sbp_msg_t &msg) { 
    return msg.pos_llh_gnss;
  }
};



template<>
struct MessageTraits<sbp_msg_vel_ecef_gnss_t> {
  static constexpr u16 id = 557;
  static const sbp_msg_vel_ecef_gnss_t &get(const sbp_msg_t &msg) { 
    return msg.vel_ecef_gnss;
  }
};



template<>
struct MessageTraits<sbp_msg_vel_ned_gnss_t> {
  static constexpr u16 id = 558;
  static const sbp_msg_vel_ned_gnss_t &get(const sbp_msg_t &msg) { 
    return msg.vel_ned_gnss;
  }
};



template<>
struct MessageTraits<sbp_msg_pos_llh_cov_gnss_t> {
  static constexpr u16 id = 561;
  static const sbp_msg_pos_llh_cov_gnss_t &get(const sbp_msg_t &msg) { 
    return msg.pos_llh_cov_gnss;
  }
};



template<>
struct MessageTraits<sbp_msg_vel_ned_cov_gnss_t> {
  static constexpr u16 id = 562;
  static const sbp_msg_vel_ned_cov_gnss_t &get(const sbp_msg_t &msg) { 
    return msg.vel_ned_cov_gnss;
  }
};



template<>
struct MessageTraits<sbp_msg_pos_ecef_cov_gnss_t> {
  static constexpr u16 id = 564;
  static const sbp_msg_pos_ecef_cov_gnss_t &get(const sbp_msg_t &msg) { 
    return msg.pos_ecef_cov_gnss;
  }
};



template<>
struct MessageTraits<sbp_msg_vel_ecef_cov_gnss_t> {
  static constexpr u16 id = 565;
  static const sbp_msg_vel_ecef_cov_gnss_t &get(const sbp_msg_t &msg) { 
    return msg.vel_ecef_cov_gnss;
  }
};



template<>
struct MessageTraits<sbp_msg_ndb_event_t> {
  static constexpr u16 id = 1024;
  static const sbp_msg_ndb_event_t &get(const sbp_msg_t &msg) { 
    return msg.ndb_event;
  }
};



template<>
struct MessageTraits<sbp_msg_log_t> {
  static constexpr u16 id = 1025;
  static const sbp_msg_log_t &get(const sbp_msg_t &msg) { 
    return msg.log;
  }
};



template<>
struct MessageTraits<sbp_msg_fwd_t> {
  static constexpr u16 id = 1026;
  static const sbp_msg_fwd_t &get(const sbp_msg_t &msg) { 
    return msg.fwd;
  }
};



template<>
struct MessageTraits<sbp_msg_ssr_orbit_clock_dep_a_t> {
  static constexpr u16 id = 1500;
  static const sbp_msg_ssr_orbit_clock_dep_a_t &get(const sbp_msg_t &msg) { 
    return msg.ssr_orbit_clock_dep_a;
  }
};



template<>
struct MessageTraits<sbp_msg_ssr_orbit_clock_t> {
  static constexpr u16 id = 1501;
  static const sbp_msg_ssr_orbit_clock_t &get(const sbp_msg_t &msg) { 
    return msg.ssr_orbit_clock;
  }
};



template<>
struct MessageTraits<sbp_msg_ssr_code_biases_t> {
  static constexpr u16 id = 1505;
  static const sbp_msg_ssr_code_biases_t &get(const sbp_msg_t &msg) { 
    return msg.ssr_code_biases;
  }
};



template<>
struct MessageTraits<sbp_msg_ssr_phase_biases_t> {
  static constexpr u16 id = 1510;
  static const sbp_msg_ssr_phase_biases_t &get(const sbp_msg_t &msg) { 
    return msg.ssr_phase_biases;
  }
};



template<>
struct MessageTraits<sbp_msg_ssr_stec_correction_dep_a_t> {
  static constexpr u16 id = 1515;
  static const sbp_msg_ssr_stec_correction_dep_a_t &get(const sbp_msg_t &msg) { 
    return msg.ssr_stec_correction_dep_a;
  }
};



template<>
struct MessageTraits<sbp_msg_ssr_gridded_correction_no_std_dep_a_t> {
  static constexpr u16 id = 1520;
  static const sbp_msg_ssr_gridded_correction_no_std_dep_a_t &get(const sbp_msg_t &msg) { 
    return msg.ssr_gridded_correction_no_std_dep_a;
  }
};



template<>
struct MessageTraits<sbp_msg_ssr_grid_definition_dep_a_t> {
  static constexpr u16 id = 1525;
  static const sbp_msg_ssr_grid_definition_dep_a_t &get(const sbp_msg_t &msg) { 
    return msg.ssr_grid_definition_dep_a;
  }
};



template<>
struct MessageTraits<sbp_msg_ssr_tile_definition_t> {
  static constexpr u16 id = 1526;
  static const sbp_msg_ssr_tile_definition_t &get(const sbp_msg_t &msg) { 
    return msg.ssr_tile_definition;
  }
};



template<>
struct MessageTraits<sbp_msg_ssr_gridded_correction_dep_a_t> {
  static constexpr u16 id = 1530;
  static const sbp_msg_ssr_gridded_correction_dep_a_t &get(const sbp_msg_t &msg) { 
    return msg.ssr_gridded_correction_dep_a;
  }
};



template<>
struct MessageTraits<sbp_msg_ssr_stec_correction_t> {
  static constexpr u16 id = 1531;
  static const sbp_msg_ssr_stec_correction_t &get(const sbp_msg_t &msg) { 
    return msg.ssr_stec_correction;
  }
};



template<>
struct MessageTraits<sbp_msg_ssr_gridded_correction_t> {
  static constexpr u16 id = 1532;
  static const sbp_msg_ssr_gridded_correction_t &get(const sbp_msg_t &msg) { 
    return msg.ssr_gridded_correction;
  }
};



template<>
struct MessageTraits<sbp_msg_ssr_satellite_apc_t> {
  static constexpr u16 id = 1540;
  static const sbp_msg_ssr_satellite_apc_t &get(const sbp_msg_t &msg) { 
    return msg.ssr_satellite_apc;
  }
};



template<>
struct MessageTraits<sbp_msg_osr_t> {
  static constexpr u16 id = 1600;
  static const sbp_msg_osr_t &get(const sbp_msg_t &msg) { 
    return msg.osr;
  }
};



template<>
struct MessageTraits<sbp_msg_user_data_t> {
  static constexpr u16 id = 2048;
  static const sbp_msg_user_data_t &get(const sbp_msg_t &msg) { 
    return msg.user_data;
  }
};



template<>
struct MessageTraits<sbp_msg_imu_raw_t> {
  static constexpr u16 id = 2304;
  static const sbp_msg_imu_raw_t &get(const sbp_msg_t &msg) { 
    return msg.imu_raw;
  }
};



template<>
struct MessageTraits<sbp_msg_imu_aux_t> {
  static constexpr u16 id = 2305;
  static const sbp_msg_imu_aux_t &get(const sbp_msg_t &msg) { 
    return msg.imu_aux;
  }
};



template<>
struct MessageTraits<sbp_msg_mag_raw_t> {
  static constexpr u16 id = 2306;
  static const sbp_msg_mag_raw_t &get(const sbp_msg_t &msg) { 
    return msg.mag_raw;
  }
};



template<>
struct MessageTraits<sbp_msg_odometry_t> {
  static constexpr u16 id = 2307;
  static const sbp_msg_odometry_t &get(const sbp_msg_t &msg) { 
    return msg.odometry;
  }
};



template<>
struct MessageTraits<sbp_msg_wheeltick_t> {
  static constexpr u16 id = 2308;
  static const sbp_msg_wheeltick_t &get(const sbp_msg_t &msg) { 
    return msg.wheeltick;
  }
};



template<>
struct MessageTraits<sbp_msg_fileio_config_req_t> {
  static constexpr u16 id = 4097;
  static const sbp_msg_fileio_config_req_t &get(const sbp_msg_t &msg) { 
    return msg.fileio_config_req;
  }
};



template<>
struct MessageTraits<sbp_msg_fileio_config_resp_t> {
  static constexpr u16 id = 4098;
  static const sbp_msg_fileio_config_resp_t &get(const sbp_msg_t &msg) { 
    return msg.fileio_config_resp;
  }
};



template<>
struct MessageTraits<sbp_msg_sbas_raw_t> {
  static constexpr u16 id = 30583;
  static const sbp_msg_sbas_raw_t &get(const sbp_msg_t &msg) { 
    return msg.sbas_raw;
  }
};



template<>
struct MessageTraits<sbp_msg_linux_cpu_state_dep_a_t> {
  static constexpr u16 id = 32512;
  static const sbp_msg_linux_cpu_state_dep_a_t &get(const sbp_msg_t &msg) { 
    return msg.linux_cpu_state_dep_a;
  }
};



template<>
struct MessageTraits<sbp_msg_linux_mem_state_dep_a_t> {
  static constexpr u16 id = 32513;
  static const sbp_msg_linux_mem_state_dep_a_t &get(const sbp_msg_t &msg) { 
    return msg.linux_mem_state_dep_a;
  }
};



template<>
struct MessageTraits<sbp_msg_linux_sys_state_dep_a_t> {
  static constexpr u16 id = 32514;
  static const sbp_msg_linux_sys_state_dep_a_t &get(const sbp_msg_t &msg) { 
    return msg.linux_sys_state_dep_a;
  }
};



template<>
struct MessageTraits<sbp_msg_linux_process_socket_counts_t> {
  static constexpr u16 id = 32515;
  static const sbp_msg_linux_process_socket_counts_t &get(const sbp_msg_t &msg) { 
    return msg.linux_process_socket_counts;
  }
};



template<>
struct MessageTraits<sbp_msg_linux_process_socket_queues_t> {
  static constexpr u16 id = 32516;
  static const sbp_msg_linux_process_socket_queues_t &get(const sbp_msg_t &msg) { 
    return msg.linux_process_socket_queues;
  }
};



template<>
struct MessageTraits<sbp_msg_linux_socket_usage_t> {
  static constexpr u16 id = 32517;
  static const sbp_msg_linux_socket_usage_t &get(const sbp_msg_t &msg) { 
    return msg.linux_socket_usage;
  }
};



template<>
struct MessageTraits<sbp_msg_linux_process_fd_count_t> {
  static constexpr u16 id = 32518;
  static const sbp_msg_linux_process_fd_count_t &get(const sbp_msg_t &msg) { 
    return msg.linux_process_fd_count;
  }
};



template<>
struct MessageTraits<sbp_msg_linux_process_fd_summary_t> {
  static constexpr u16 id = 32519;
  static const sbp_msg_linux_process_fd_summary_t &get(const sbp_msg_t &msg) { 
    return msg.linux_process_fd_summary;
  }
};



template<>
struct MessageTraits<sbp_msg_linux_cpu_state_t> {
  static constexpr u16 id = 32520;
  static const sbp_msg_linux_cpu_state_t &get(const sbp_msg_t &msg) { 
    return msg.linux_cpu_state;
  }
};



template<>
struct MessageTraits<sbp_msg_linux_mem_state_t> {
  static constexpr u16 id = 32521;
  static const sbp_msg_linux_mem_state_t &get(const sbp_msg_t &msg) { 
    return msg.linux_mem_state;
  }
};



template<>
struct MessageTraits<sbp_msg_linux_sys_state_t> {
  static constexpr u16 id = 32522;
  static const sbp_msg_linux_sys_state_t &get(const sbp_msg_t &msg) { 
    return msg.linux_sys_state;
  }
};



template<>
struct MessageTraits<sbp_msg_startup_t> {
  static constexpr u16 id = 65280;
  static const sbp_msg_startup_t &get(const sbp_msg_t &msg) { 
    return msg.startup;
  }
};



template<>
struct MessageTraits<sbp_msg_dgnss_status_t> {
  static constexpr u16 id = 65282;
  static const sbp_msg_dgnss_status_t &get(const sbp_msg_t &msg) { 
    return msg.dgnss_status;
  }
};



template<>
struct MessageTraits<sbp_msg_ins_status_t> {
  static constexpr u16 id = 65283;
  static const sbp_msg_ins_status_t &get(const sbp_msg_t &msg) { 
    return msg.ins_status;
  }
};



template<>
struct MessageTraits<sbp_msg_csac_telemetry_t> {
  static constexpr u16 id = 65284;
  static const sbp_msg_csac_telemetry_t &get(const sbp_msg_t &msg) { 
    return msg.csac_telemetry;
  }
};



template<>
struct MessageTraits<sbp_msg_csac_telemetry_labels_t> {
  static constexpr u16 id = 65285;
  static const sbp_msg_csac_telemetry_labels_t &get(const sbp_msg_t &msg) { 
    return msg.csac_telemetry_labels;
  }
};



template<>
struct MessageTraits<sbp_msg_ins_updates_t> {
  static constexpr u16 id = 65286;
  static const sbp_msg_ins_updates_t &get(const sbp_msg_t &msg) { 
    return msg.ins_updates;
  }
};



template<>
struct MessageTraits<sbp_msg_gnss_time_offset_t> {
  static constexpr u16 id = 65287;
  static const sbp_msg_gnss_time_offset_t &get(const sbp_msg_t &msg) { 
    return msg.gnss_time_offset;
  }
};



template<>
struct MessageTraits<sbp_msg_pps_time_t> {
  static constexpr u16 id = 65288;
  static const sbp_msg_pps_time_t &get(const sbp_msg_t &msg) { 
    return msg.pps_time;
  }
};



template<>
struct MessageTraits<sbp_msg_group_meta_t> {
  static constexpr u16 id = 65290;
  static const sbp_msg_group_meta_t &get(const sbp_msg_t &msg) { 
    return msg.group_meta;
  }
};



template<>
struct MessageTraits<sbp_msg_soln_meta_t> {
  static constexpr u16 id = 65294;
  static const sbp_msg_soln_meta_t &get(const sbp_msg_t &msg) { 
    return msg.soln_meta;
  }
};



template<>
struct MessageTraits<sbp_msg_soln_meta_dep_a_t> {
  static constexpr u16 id = 65295;
  static const sbp_msg_soln_meta_dep_a_t &get(const sbp_msg_t &msg) { 
    return msg.soln_meta_dep_a;
  }
};



template<>
struct MessageTraits<sbp_msg_status_report_t> {
  static constexpr u16 id = 65534;
  static const sbp_msg_status_report_t &get(const sbp_msg_t &msg) { 
    return msg.status_report;
  }
};



template<>
struct MessageTraits<sbp_msg_heartbeat_t> {
  static constexpr u16 id = 65535;
  static const sbp_msg_heartbeat_t &get(const sbp_msg_t &msg) { 
    return msg.heartbeat;
  }
};





} // namespace sbp

#endif //SBP_CPP_MESSAGE_TRAITS_H