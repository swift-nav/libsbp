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

#ifndef SBP_CPP_UNPACKED_MESSAGE_TRAITS_H
#define SBP_CPP_UNPACKED_MESSAGE_TRAITS_H

#include <libsbp/sbp.h>
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
  static constexpr bool is_unpacked = true;
  static const sbp_msg_print_dep_t& get(const sbp_msg_t &msg) {
    return msg.print_dep;
  }
  static sbp_msg_print_dep_t& get(sbp_msg_t &msg) {
    return msg.print_dep;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_print_dep_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_print_dep_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_tracking_state_detailed_dep_t> {
  static constexpr u16 id = 17;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_tracking_state_detailed_dep_t& get(const sbp_msg_t &msg) {
    return msg.tracking_state_detailed_dep;
  }
  static sbp_msg_tracking_state_detailed_dep_t& get(sbp_msg_t &msg) {
    return msg.tracking_state_detailed_dep;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_tracking_state_detailed_dep_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_tracking_state_detailed_dep_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_tracking_state_dep_b_t> {
  static constexpr u16 id = 19;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_tracking_state_dep_b_t& get(const sbp_msg_t &msg) {
    return msg.tracking_state_dep_b;
  }
  static sbp_msg_tracking_state_dep_b_t& get(sbp_msg_t &msg) {
    return msg.tracking_state_dep_b;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_tracking_state_dep_b_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_tracking_state_dep_b_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_acq_result_dep_b_t> {
  static constexpr u16 id = 20;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_acq_result_dep_b_t& get(const sbp_msg_t &msg) {
    return msg.acq_result_dep_b;
  }
  static sbp_msg_acq_result_dep_b_t& get(sbp_msg_t &msg) {
    return msg.acq_result_dep_b;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_acq_result_dep_b_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_acq_result_dep_b_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_acq_result_dep_a_t> {
  static constexpr u16 id = 21;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_acq_result_dep_a_t& get(const sbp_msg_t &msg) {
    return msg.acq_result_dep_a;
  }
  static sbp_msg_acq_result_dep_a_t& get(sbp_msg_t &msg) {
    return msg.acq_result_dep_a;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_acq_result_dep_a_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_acq_result_dep_a_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_tracking_state_dep_a_t> {
  static constexpr u16 id = 22;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_tracking_state_dep_a_t& get(const sbp_msg_t &msg) {
    return msg.tracking_state_dep_a;
  }
  static sbp_msg_tracking_state_dep_a_t& get(sbp_msg_t &msg) {
    return msg.tracking_state_dep_a;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_tracking_state_dep_a_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_tracking_state_dep_a_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_thread_state_t> {
  static constexpr u16 id = 23;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_thread_state_t& get(const sbp_msg_t &msg) {
    return msg.thread_state;
  }
  static sbp_msg_thread_state_t& get(sbp_msg_t &msg) {
    return msg.thread_state;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_thread_state_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_thread_state_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_uart_state_depa_t> {
  static constexpr u16 id = 24;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_uart_state_depa_t& get(const sbp_msg_t &msg) {
    return msg.uart_state_depa;
  }
  static sbp_msg_uart_state_depa_t& get(sbp_msg_t &msg) {
    return msg.uart_state_depa;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_uart_state_depa_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_uart_state_depa_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_iar_state_t> {
  static constexpr u16 id = 25;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_iar_state_t& get(const sbp_msg_t &msg) {
    return msg.iar_state;
  }
  static sbp_msg_iar_state_t& get(sbp_msg_t &msg) {
    return msg.iar_state;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_iar_state_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_iar_state_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_ephemeris_dep_a_t> {
  static constexpr u16 id = 26;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_ephemeris_dep_a_t& get(const sbp_msg_t &msg) {
    return msg.ephemeris_dep_a;
  }
  static sbp_msg_ephemeris_dep_a_t& get(sbp_msg_t &msg) {
    return msg.ephemeris_dep_a;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_ephemeris_dep_a_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_ephemeris_dep_a_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_mask_satellite_dep_t> {
  static constexpr u16 id = 27;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_mask_satellite_dep_t& get(const sbp_msg_t &msg) {
    return msg.mask_satellite_dep;
  }
  static sbp_msg_mask_satellite_dep_t& get(sbp_msg_t &msg) {
    return msg.mask_satellite_dep;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_mask_satellite_dep_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_mask_satellite_dep_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_tracking_iq_dep_a_t> {
  static constexpr u16 id = 28;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_tracking_iq_dep_a_t& get(const sbp_msg_t &msg) {
    return msg.tracking_iq_dep_a;
  }
  static sbp_msg_tracking_iq_dep_a_t& get(sbp_msg_t &msg) {
    return msg.tracking_iq_dep_a;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_tracking_iq_dep_a_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_tracking_iq_dep_a_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_uart_state_t> {
  static constexpr u16 id = 29;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_uart_state_t& get(const sbp_msg_t &msg) {
    return msg.uart_state;
  }
  static sbp_msg_uart_state_t& get(sbp_msg_t &msg) {
    return msg.uart_state;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_uart_state_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_uart_state_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_acq_sv_profile_dep_t> {
  static constexpr u16 id = 30;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_acq_sv_profile_dep_t& get(const sbp_msg_t &msg) {
    return msg.acq_sv_profile_dep;
  }
  static sbp_msg_acq_sv_profile_dep_t& get(sbp_msg_t &msg) {
    return msg.acq_sv_profile_dep;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_acq_sv_profile_dep_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_acq_sv_profile_dep_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_acq_result_dep_c_t> {
  static constexpr u16 id = 31;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_acq_result_dep_c_t& get(const sbp_msg_t &msg) {
    return msg.acq_result_dep_c;
  }
  static sbp_msg_acq_result_dep_c_t& get(sbp_msg_t &msg) {
    return msg.acq_result_dep_c;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_acq_result_dep_c_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_acq_result_dep_c_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_tracking_state_detailed_dep_a_t> {
  static constexpr u16 id = 33;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_tracking_state_detailed_dep_a_t& get(const sbp_msg_t &msg) {
    return msg.tracking_state_detailed_dep_a;
  }
  static sbp_msg_tracking_state_detailed_dep_a_t& get(sbp_msg_t &msg) {
    return msg.tracking_state_detailed_dep_a;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_tracking_state_detailed_dep_a_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_tracking_state_detailed_dep_a_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_reset_filters_t> {
  static constexpr u16 id = 34;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_reset_filters_t& get(const sbp_msg_t &msg) {
    return msg.reset_filters;
  }
  static sbp_msg_reset_filters_t& get(sbp_msg_t &msg) {
    return msg.reset_filters;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_reset_filters_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_reset_filters_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_init_base_dep_t> {
  static constexpr u16 id = 35;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_init_base_dep_t& get(const sbp_msg_t &msg) {
    return msg.init_base_dep;
  }
  static sbp_msg_init_base_dep_t& get(sbp_msg_t &msg) {
    return msg.init_base_dep;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_init_base_dep_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_init_base_dep_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_mask_satellite_t> {
  static constexpr u16 id = 43;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_mask_satellite_t& get(const sbp_msg_t &msg) {
    return msg.mask_satellite;
  }
  static sbp_msg_mask_satellite_t& get(sbp_msg_t &msg) {
    return msg.mask_satellite;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_mask_satellite_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_mask_satellite_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_tracking_iq_dep_b_t> {
  static constexpr u16 id = 44;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_tracking_iq_dep_b_t& get(const sbp_msg_t &msg) {
    return msg.tracking_iq_dep_b;
  }
  static sbp_msg_tracking_iq_dep_b_t& get(sbp_msg_t &msg) {
    return msg.tracking_iq_dep_b;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_tracking_iq_dep_b_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_tracking_iq_dep_b_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_tracking_iq_t> {
  static constexpr u16 id = 45;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_tracking_iq_t& get(const sbp_msg_t &msg) {
    return msg.tracking_iq;
  }
  static sbp_msg_tracking_iq_t& get(sbp_msg_t &msg) {
    return msg.tracking_iq;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_tracking_iq_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_tracking_iq_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_acq_sv_profile_t> {
  static constexpr u16 id = 46;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_acq_sv_profile_t& get(const sbp_msg_t &msg) {
    return msg.acq_sv_profile;
  }
  static sbp_msg_acq_sv_profile_t& get(sbp_msg_t &msg) {
    return msg.acq_sv_profile;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_acq_sv_profile_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_acq_sv_profile_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_acq_result_t> {
  static constexpr u16 id = 47;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_acq_result_t& get(const sbp_msg_t &msg) {
    return msg.acq_result;
  }
  static sbp_msg_acq_result_t& get(sbp_msg_t &msg) {
    return msg.acq_result;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_acq_result_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_acq_result_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_tracking_state_t> {
  static constexpr u16 id = 65;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_tracking_state_t& get(const sbp_msg_t &msg) {
    return msg.tracking_state;
  }
  static sbp_msg_tracking_state_t& get(sbp_msg_t &msg) {
    return msg.tracking_state;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_tracking_state_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_tracking_state_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_obs_dep_b_t> {
  static constexpr u16 id = 67;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_obs_dep_b_t& get(const sbp_msg_t &msg) {
    return msg.obs_dep_b;
  }
  static sbp_msg_obs_dep_b_t& get(sbp_msg_t &msg) {
    return msg.obs_dep_b;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_obs_dep_b_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_obs_dep_b_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_base_pos_llh_t> {
  static constexpr u16 id = 68;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_base_pos_llh_t& get(const sbp_msg_t &msg) {
    return msg.base_pos_llh;
  }
  static sbp_msg_base_pos_llh_t& get(sbp_msg_t &msg) {
    return msg.base_pos_llh;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_base_pos_llh_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_base_pos_llh_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_obs_dep_a_t> {
  static constexpr u16 id = 69;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_obs_dep_a_t& get(const sbp_msg_t &msg) {
    return msg.obs_dep_a;
  }
  static sbp_msg_obs_dep_a_t& get(sbp_msg_t &msg) {
    return msg.obs_dep_a;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_obs_dep_a_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_obs_dep_a_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_ephemeris_dep_b_t> {
  static constexpr u16 id = 70;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_ephemeris_dep_b_t& get(const sbp_msg_t &msg) {
    return msg.ephemeris_dep_b;
  }
  static sbp_msg_ephemeris_dep_b_t& get(sbp_msg_t &msg) {
    return msg.ephemeris_dep_b;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_ephemeris_dep_b_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_ephemeris_dep_b_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_ephemeris_dep_c_t> {
  static constexpr u16 id = 71;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_ephemeris_dep_c_t& get(const sbp_msg_t &msg) {
    return msg.ephemeris_dep_c;
  }
  static sbp_msg_ephemeris_dep_c_t& get(sbp_msg_t &msg) {
    return msg.ephemeris_dep_c;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_ephemeris_dep_c_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_ephemeris_dep_c_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_base_pos_ecef_t> {
  static constexpr u16 id = 72;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_base_pos_ecef_t& get(const sbp_msg_t &msg) {
    return msg.base_pos_ecef;
  }
  static sbp_msg_base_pos_ecef_t& get(sbp_msg_t &msg) {
    return msg.base_pos_ecef;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_base_pos_ecef_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_base_pos_ecef_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_obs_dep_c_t> {
  static constexpr u16 id = 73;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_obs_dep_c_t& get(const sbp_msg_t &msg) {
    return msg.obs_dep_c;
  }
  static sbp_msg_obs_dep_c_t& get(sbp_msg_t &msg) {
    return msg.obs_dep_c;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_obs_dep_c_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_obs_dep_c_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_obs_t> {
  static constexpr u16 id = 74;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_obs_t& get(const sbp_msg_t &msg) {
    return msg.obs;
  }
  static sbp_msg_obs_t& get(sbp_msg_t &msg) {
    return msg.obs;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_obs_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_obs_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_specan_dep_t> {
  static constexpr u16 id = 80;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_specan_dep_t& get(const sbp_msg_t &msg) {
    return msg.specan_dep;
  }
  static sbp_msg_specan_dep_t& get(sbp_msg_t &msg) {
    return msg.specan_dep;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_specan_dep_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_specan_dep_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_specan_t> {
  static constexpr u16 id = 81;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_specan_t& get(const sbp_msg_t &msg) {
    return msg.specan;
  }
  static sbp_msg_specan_t& get(sbp_msg_t &msg) {
    return msg.specan;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_specan_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_specan_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_measurement_state_t> {
  static constexpr u16 id = 97;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_measurement_state_t& get(const sbp_msg_t &msg) {
    return msg.measurement_state;
  }
  static sbp_msg_measurement_state_t& get(sbp_msg_t &msg) {
    return msg.measurement_state;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_measurement_state_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_measurement_state_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_set_time_t> {
  static constexpr u16 id = 104;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_set_time_t& get(const sbp_msg_t &msg) {
    return msg.set_time;
  }
  static sbp_msg_set_time_t& get(sbp_msg_t &msg) {
    return msg.set_time;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_set_time_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_set_time_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_almanac_t> {
  static constexpr u16 id = 105;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_almanac_t& get(const sbp_msg_t &msg) {
    return msg.almanac;
  }
  static sbp_msg_almanac_t& get(sbp_msg_t &msg) {
    return msg.almanac;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_almanac_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_almanac_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_almanac_gps_dep_t> {
  static constexpr u16 id = 112;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_almanac_gps_dep_t& get(const sbp_msg_t &msg) {
    return msg.almanac_gps_dep;
  }
  static sbp_msg_almanac_gps_dep_t& get(sbp_msg_t &msg) {
    return msg.almanac_gps_dep;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_almanac_gps_dep_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_almanac_gps_dep_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_almanac_glo_dep_t> {
  static constexpr u16 id = 113;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_almanac_glo_dep_t& get(const sbp_msg_t &msg) {
    return msg.almanac_glo_dep;
  }
  static sbp_msg_almanac_glo_dep_t& get(sbp_msg_t &msg) {
    return msg.almanac_glo_dep;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_almanac_glo_dep_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_almanac_glo_dep_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_almanac_gps_t> {
  static constexpr u16 id = 114;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_almanac_gps_t& get(const sbp_msg_t &msg) {
    return msg.almanac_gps;
  }
  static sbp_msg_almanac_gps_t& get(sbp_msg_t &msg) {
    return msg.almanac_gps;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_almanac_gps_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_almanac_gps_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_almanac_glo_t> {
  static constexpr u16 id = 115;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_almanac_glo_t& get(const sbp_msg_t &msg) {
    return msg.almanac_glo;
  }
  static sbp_msg_almanac_glo_t& get(sbp_msg_t &msg) {
    return msg.almanac_glo;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_almanac_glo_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_almanac_glo_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_glo_biases_t> {
  static constexpr u16 id = 117;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_glo_biases_t& get(const sbp_msg_t &msg) {
    return msg.glo_biases;
  }
  static sbp_msg_glo_biases_t& get(sbp_msg_t &msg) {
    return msg.glo_biases;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_glo_biases_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_glo_biases_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_ephemeris_dep_d_t> {
  static constexpr u16 id = 128;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_ephemeris_dep_d_t& get(const sbp_msg_t &msg) {
    return msg.ephemeris_dep_d;
  }
  static sbp_msg_ephemeris_dep_d_t& get(sbp_msg_t &msg) {
    return msg.ephemeris_dep_d;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_ephemeris_dep_d_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_ephemeris_dep_d_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_ephemeris_gps_dep_e_t> {
  static constexpr u16 id = 129;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_ephemeris_gps_dep_e_t& get(const sbp_msg_t &msg) {
    return msg.ephemeris_gps_dep_e;
  }
  static sbp_msg_ephemeris_gps_dep_e_t& get(sbp_msg_t &msg) {
    return msg.ephemeris_gps_dep_e;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_ephemeris_gps_dep_e_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_ephemeris_gps_dep_e_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_ephemeris_sbas_dep_a_t> {
  static constexpr u16 id = 130;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_ephemeris_sbas_dep_a_t& get(const sbp_msg_t &msg) {
    return msg.ephemeris_sbas_dep_a;
  }
  static sbp_msg_ephemeris_sbas_dep_a_t& get(sbp_msg_t &msg) {
    return msg.ephemeris_sbas_dep_a;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_ephemeris_sbas_dep_a_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_ephemeris_sbas_dep_a_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_ephemeris_glo_dep_a_t> {
  static constexpr u16 id = 131;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_ephemeris_glo_dep_a_t& get(const sbp_msg_t &msg) {
    return msg.ephemeris_glo_dep_a;
  }
  static sbp_msg_ephemeris_glo_dep_a_t& get(sbp_msg_t &msg) {
    return msg.ephemeris_glo_dep_a;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_ephemeris_glo_dep_a_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_ephemeris_glo_dep_a_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_ephemeris_sbas_dep_b_t> {
  static constexpr u16 id = 132;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_ephemeris_sbas_dep_b_t& get(const sbp_msg_t &msg) {
    return msg.ephemeris_sbas_dep_b;
  }
  static sbp_msg_ephemeris_sbas_dep_b_t& get(sbp_msg_t &msg) {
    return msg.ephemeris_sbas_dep_b;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_ephemeris_sbas_dep_b_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_ephemeris_sbas_dep_b_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_ephemeris_glo_dep_b_t> {
  static constexpr u16 id = 133;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_ephemeris_glo_dep_b_t& get(const sbp_msg_t &msg) {
    return msg.ephemeris_glo_dep_b;
  }
  static sbp_msg_ephemeris_glo_dep_b_t& get(sbp_msg_t &msg) {
    return msg.ephemeris_glo_dep_b;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_ephemeris_glo_dep_b_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_ephemeris_glo_dep_b_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_ephemeris_gps_dep_f_t> {
  static constexpr u16 id = 134;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_ephemeris_gps_dep_f_t& get(const sbp_msg_t &msg) {
    return msg.ephemeris_gps_dep_f;
  }
  static sbp_msg_ephemeris_gps_dep_f_t& get(sbp_msg_t &msg) {
    return msg.ephemeris_gps_dep_f;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_ephemeris_gps_dep_f_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_ephemeris_gps_dep_f_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_ephemeris_glo_dep_c_t> {
  static constexpr u16 id = 135;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_ephemeris_glo_dep_c_t& get(const sbp_msg_t &msg) {
    return msg.ephemeris_glo_dep_c;
  }
  static sbp_msg_ephemeris_glo_dep_c_t& get(sbp_msg_t &msg) {
    return msg.ephemeris_glo_dep_c;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_ephemeris_glo_dep_c_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_ephemeris_glo_dep_c_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_ephemeris_glo_dep_d_t> {
  static constexpr u16 id = 136;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_ephemeris_glo_dep_d_t& get(const sbp_msg_t &msg) {
    return msg.ephemeris_glo_dep_d;
  }
  static sbp_msg_ephemeris_glo_dep_d_t& get(sbp_msg_t &msg) {
    return msg.ephemeris_glo_dep_d;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_ephemeris_glo_dep_d_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_ephemeris_glo_dep_d_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_ephemeris_bds_t> {
  static constexpr u16 id = 137;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_ephemeris_bds_t& get(const sbp_msg_t &msg) {
    return msg.ephemeris_bds;
  }
  static sbp_msg_ephemeris_bds_t& get(sbp_msg_t &msg) {
    return msg.ephemeris_bds;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_ephemeris_bds_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_ephemeris_bds_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_ephemeris_gps_t> {
  static constexpr u16 id = 138;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_ephemeris_gps_t& get(const sbp_msg_t &msg) {
    return msg.ephemeris_gps;
  }
  static sbp_msg_ephemeris_gps_t& get(sbp_msg_t &msg) {
    return msg.ephemeris_gps;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_ephemeris_gps_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_ephemeris_gps_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_ephemeris_glo_t> {
  static constexpr u16 id = 139;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_ephemeris_glo_t& get(const sbp_msg_t &msg) {
    return msg.ephemeris_glo;
  }
  static sbp_msg_ephemeris_glo_t& get(sbp_msg_t &msg) {
    return msg.ephemeris_glo;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_ephemeris_glo_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_ephemeris_glo_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_ephemeris_sbas_t> {
  static constexpr u16 id = 140;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_ephemeris_sbas_t& get(const sbp_msg_t &msg) {
    return msg.ephemeris_sbas;
  }
  static sbp_msg_ephemeris_sbas_t& get(sbp_msg_t &msg) {
    return msg.ephemeris_sbas;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_ephemeris_sbas_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_ephemeris_sbas_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_ephemeris_gal_t> {
  static constexpr u16 id = 141;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_ephemeris_gal_t& get(const sbp_msg_t &msg) {
    return msg.ephemeris_gal;
  }
  static sbp_msg_ephemeris_gal_t& get(sbp_msg_t &msg) {
    return msg.ephemeris_gal;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_ephemeris_gal_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_ephemeris_gal_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_ephemeris_qzss_t> {
  static constexpr u16 id = 142;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_ephemeris_qzss_t& get(const sbp_msg_t &msg) {
    return msg.ephemeris_qzss;
  }
  static sbp_msg_ephemeris_qzss_t& get(sbp_msg_t &msg) {
    return msg.ephemeris_qzss;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_ephemeris_qzss_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_ephemeris_qzss_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_iono_t> {
  static constexpr u16 id = 144;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_iono_t& get(const sbp_msg_t &msg) {
    return msg.iono;
  }
  static sbp_msg_iono_t& get(sbp_msg_t &msg) {
    return msg.iono;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_iono_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_iono_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_sv_configuration_gps_dep_t> {
  static constexpr u16 id = 145;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_sv_configuration_gps_dep_t& get(const sbp_msg_t &msg) {
    return msg.sv_configuration_gps_dep;
  }
  static sbp_msg_sv_configuration_gps_dep_t& get(sbp_msg_t &msg) {
    return msg.sv_configuration_gps_dep;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_sv_configuration_gps_dep_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_sv_configuration_gps_dep_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_group_delay_dep_a_t> {
  static constexpr u16 id = 146;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_group_delay_dep_a_t& get(const sbp_msg_t &msg) {
    return msg.group_delay_dep_a;
  }
  static sbp_msg_group_delay_dep_a_t& get(sbp_msg_t &msg) {
    return msg.group_delay_dep_a;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_group_delay_dep_a_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_group_delay_dep_a_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_group_delay_dep_b_t> {
  static constexpr u16 id = 147;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_group_delay_dep_b_t& get(const sbp_msg_t &msg) {
    return msg.group_delay_dep_b;
  }
  static sbp_msg_group_delay_dep_b_t& get(sbp_msg_t &msg) {
    return msg.group_delay_dep_b;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_group_delay_dep_b_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_group_delay_dep_b_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_group_delay_t> {
  static constexpr u16 id = 148;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_group_delay_t& get(const sbp_msg_t &msg) {
    return msg.group_delay;
  }
  static sbp_msg_group_delay_t& get(sbp_msg_t &msg) {
    return msg.group_delay;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_group_delay_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_group_delay_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_ephemeris_gal_dep_a_t> {
  static constexpr u16 id = 149;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_ephemeris_gal_dep_a_t& get(const sbp_msg_t &msg) {
    return msg.ephemeris_gal_dep_a;
  }
  static sbp_msg_ephemeris_gal_dep_a_t& get(sbp_msg_t &msg) {
    return msg.ephemeris_gal_dep_a;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_ephemeris_gal_dep_a_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_ephemeris_gal_dep_a_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_gnss_capb_t> {
  static constexpr u16 id = 150;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_gnss_capb_t& get(const sbp_msg_t &msg) {
    return msg.gnss_capb;
  }
  static sbp_msg_gnss_capb_t& get(sbp_msg_t &msg) {
    return msg.gnss_capb;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_gnss_capb_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_gnss_capb_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_sv_az_el_t> {
  static constexpr u16 id = 151;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_sv_az_el_t& get(const sbp_msg_t &msg) {
    return msg.sv_az_el;
  }
  static sbp_msg_sv_az_el_t& get(sbp_msg_t &msg) {
    return msg.sv_az_el;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_sv_az_el_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_sv_az_el_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_settings_write_t> {
  static constexpr u16 id = 160;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_settings_write_t& get(const sbp_msg_t &msg) {
    return msg.settings_write;
  }
  static sbp_msg_settings_write_t& get(sbp_msg_t &msg) {
    return msg.settings_write;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_settings_write_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_settings_write_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_settings_save_t> {
  static constexpr u16 id = 161;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_settings_save_t& get(const sbp_msg_t &msg) {
    return msg.settings_save;
  }
  static sbp_msg_settings_save_t& get(sbp_msg_t &msg) {
    return msg.settings_save;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_settings_save_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_settings_save_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_settings_read_by_index_req_t> {
  static constexpr u16 id = 162;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_settings_read_by_index_req_t& get(const sbp_msg_t &msg) {
    return msg.settings_read_by_index_req;
  }
  static sbp_msg_settings_read_by_index_req_t& get(sbp_msg_t &msg) {
    return msg.settings_read_by_index_req;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_settings_read_by_index_req_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_settings_read_by_index_req_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_fileio_read_resp_t> {
  static constexpr u16 id = 163;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_fileio_read_resp_t& get(const sbp_msg_t &msg) {
    return msg.fileio_read_resp;
  }
  static sbp_msg_fileio_read_resp_t& get(sbp_msg_t &msg) {
    return msg.fileio_read_resp;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_fileio_read_resp_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_fileio_read_resp_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_settings_read_req_t> {
  static constexpr u16 id = 164;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_settings_read_req_t& get(const sbp_msg_t &msg) {
    return msg.settings_read_req;
  }
  static sbp_msg_settings_read_req_t& get(sbp_msg_t &msg) {
    return msg.settings_read_req;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_settings_read_req_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_settings_read_req_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_settings_read_resp_t> {
  static constexpr u16 id = 165;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_settings_read_resp_t& get(const sbp_msg_t &msg) {
    return msg.settings_read_resp;
  }
  static sbp_msg_settings_read_resp_t& get(sbp_msg_t &msg) {
    return msg.settings_read_resp;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_settings_read_resp_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_settings_read_resp_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_settings_read_by_index_done_t> {
  static constexpr u16 id = 166;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_settings_read_by_index_done_t& get(const sbp_msg_t &msg) {
    return msg.settings_read_by_index_done;
  }
  static sbp_msg_settings_read_by_index_done_t& get(sbp_msg_t &msg) {
    return msg.settings_read_by_index_done;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_settings_read_by_index_done_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_settings_read_by_index_done_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_settings_read_by_index_resp_t> {
  static constexpr u16 id = 167;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_settings_read_by_index_resp_t& get(const sbp_msg_t &msg) {
    return msg.settings_read_by_index_resp;
  }
  static sbp_msg_settings_read_by_index_resp_t& get(sbp_msg_t &msg) {
    return msg.settings_read_by_index_resp;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_settings_read_by_index_resp_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_settings_read_by_index_resp_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_fileio_read_req_t> {
  static constexpr u16 id = 168;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_fileio_read_req_t& get(const sbp_msg_t &msg) {
    return msg.fileio_read_req;
  }
  static sbp_msg_fileio_read_req_t& get(sbp_msg_t &msg) {
    return msg.fileio_read_req;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_fileio_read_req_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_fileio_read_req_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_fileio_read_dir_req_t> {
  static constexpr u16 id = 169;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_fileio_read_dir_req_t& get(const sbp_msg_t &msg) {
    return msg.fileio_read_dir_req;
  }
  static sbp_msg_fileio_read_dir_req_t& get(sbp_msg_t &msg) {
    return msg.fileio_read_dir_req;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_fileio_read_dir_req_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_fileio_read_dir_req_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_fileio_read_dir_resp_t> {
  static constexpr u16 id = 170;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_fileio_read_dir_resp_t& get(const sbp_msg_t &msg) {
    return msg.fileio_read_dir_resp;
  }
  static sbp_msg_fileio_read_dir_resp_t& get(sbp_msg_t &msg) {
    return msg.fileio_read_dir_resp;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_fileio_read_dir_resp_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_fileio_read_dir_resp_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_fileio_write_resp_t> {
  static constexpr u16 id = 171;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_fileio_write_resp_t& get(const sbp_msg_t &msg) {
    return msg.fileio_write_resp;
  }
  static sbp_msg_fileio_write_resp_t& get(sbp_msg_t &msg) {
    return msg.fileio_write_resp;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_fileio_write_resp_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_fileio_write_resp_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_fileio_remove_t> {
  static constexpr u16 id = 172;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_fileio_remove_t& get(const sbp_msg_t &msg) {
    return msg.fileio_remove;
  }
  static sbp_msg_fileio_remove_t& get(sbp_msg_t &msg) {
    return msg.fileio_remove;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_fileio_remove_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_fileio_remove_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_fileio_write_req_t> {
  static constexpr u16 id = 173;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_fileio_write_req_t& get(const sbp_msg_t &msg) {
    return msg.fileio_write_req;
  }
  static sbp_msg_fileio_write_req_t& get(sbp_msg_t &msg) {
    return msg.fileio_write_req;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_fileio_write_req_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_fileio_write_req_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_settings_register_t> {
  static constexpr u16 id = 174;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_settings_register_t& get(const sbp_msg_t &msg) {
    return msg.settings_register;
  }
  static sbp_msg_settings_register_t& get(sbp_msg_t &msg) {
    return msg.settings_register;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_settings_register_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_settings_register_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_settings_write_resp_t> {
  static constexpr u16 id = 175;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_settings_write_resp_t& get(const sbp_msg_t &msg) {
    return msg.settings_write_resp;
  }
  static sbp_msg_settings_write_resp_t& get(sbp_msg_t &msg) {
    return msg.settings_write_resp;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_settings_write_resp_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_settings_write_resp_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_bootloader_handshake_dep_a_t> {
  static constexpr u16 id = 176;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_bootloader_handshake_dep_a_t& get(const sbp_msg_t &msg) {
    return msg.bootloader_handshake_dep_a;
  }
  static sbp_msg_bootloader_handshake_dep_a_t& get(sbp_msg_t &msg) {
    return msg.bootloader_handshake_dep_a;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_bootloader_handshake_dep_a_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_bootloader_handshake_dep_a_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_bootloader_jump_to_app_t> {
  static constexpr u16 id = 177;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_bootloader_jump_to_app_t& get(const sbp_msg_t &msg) {
    return msg.bootloader_jump_to_app;
  }
  static sbp_msg_bootloader_jump_to_app_t& get(sbp_msg_t &msg) {
    return msg.bootloader_jump_to_app;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_bootloader_jump_to_app_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_bootloader_jump_to_app_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_reset_dep_t> {
  static constexpr u16 id = 178;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_reset_dep_t& get(const sbp_msg_t &msg) {
    return msg.reset_dep;
  }
  static sbp_msg_reset_dep_t& get(sbp_msg_t &msg) {
    return msg.reset_dep;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_reset_dep_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_reset_dep_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_bootloader_handshake_req_t> {
  static constexpr u16 id = 179;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_bootloader_handshake_req_t& get(const sbp_msg_t &msg) {
    return msg.bootloader_handshake_req;
  }
  static sbp_msg_bootloader_handshake_req_t& get(sbp_msg_t &msg) {
    return msg.bootloader_handshake_req;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_bootloader_handshake_req_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_bootloader_handshake_req_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_bootloader_handshake_resp_t> {
  static constexpr u16 id = 180;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_bootloader_handshake_resp_t& get(const sbp_msg_t &msg) {
    return msg.bootloader_handshake_resp;
  }
  static sbp_msg_bootloader_handshake_resp_t& get(sbp_msg_t &msg) {
    return msg.bootloader_handshake_resp;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_bootloader_handshake_resp_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_bootloader_handshake_resp_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_device_monitor_t> {
  static constexpr u16 id = 181;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_device_monitor_t& get(const sbp_msg_t &msg) {
    return msg.device_monitor;
  }
  static sbp_msg_device_monitor_t& get(sbp_msg_t &msg) {
    return msg.device_monitor;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_device_monitor_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_device_monitor_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_reset_t> {
  static constexpr u16 id = 182;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_reset_t& get(const sbp_msg_t &msg) {
    return msg.reset;
  }
  static sbp_msg_reset_t& get(sbp_msg_t &msg) {
    return msg.reset;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_reset_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_reset_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_command_req_t> {
  static constexpr u16 id = 184;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_command_req_t& get(const sbp_msg_t &msg) {
    return msg.command_req;
  }
  static sbp_msg_command_req_t& get(sbp_msg_t &msg) {
    return msg.command_req;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_command_req_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_command_req_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_command_resp_t> {
  static constexpr u16 id = 185;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_command_resp_t& get(const sbp_msg_t &msg) {
    return msg.command_resp;
  }
  static sbp_msg_command_resp_t& get(sbp_msg_t &msg) {
    return msg.command_resp;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_command_resp_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_command_resp_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_network_state_req_t> {
  static constexpr u16 id = 186;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_network_state_req_t& get(const sbp_msg_t &msg) {
    return msg.network_state_req;
  }
  static sbp_msg_network_state_req_t& get(sbp_msg_t &msg) {
    return msg.network_state_req;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_network_state_req_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_network_state_req_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_network_state_resp_t> {
  static constexpr u16 id = 187;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_network_state_resp_t& get(const sbp_msg_t &msg) {
    return msg.network_state_resp;
  }
  static sbp_msg_network_state_resp_t& get(sbp_msg_t &msg) {
    return msg.network_state_resp;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_network_state_resp_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_network_state_resp_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_command_output_t> {
  static constexpr u16 id = 188;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_command_output_t& get(const sbp_msg_t &msg) {
    return msg.command_output;
  }
  static sbp_msg_command_output_t& get(sbp_msg_t &msg) {
    return msg.command_output;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_command_output_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_command_output_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_network_bandwidth_usage_t> {
  static constexpr u16 id = 189;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_network_bandwidth_usage_t& get(const sbp_msg_t &msg) {
    return msg.network_bandwidth_usage;
  }
  static sbp_msg_network_bandwidth_usage_t& get(sbp_msg_t &msg) {
    return msg.network_bandwidth_usage;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_network_bandwidth_usage_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_network_bandwidth_usage_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_cell_modem_status_t> {
  static constexpr u16 id = 190;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_cell_modem_status_t& get(const sbp_msg_t &msg) {
    return msg.cell_modem_status;
  }
  static sbp_msg_cell_modem_status_t& get(sbp_msg_t &msg) {
    return msg.cell_modem_status;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_cell_modem_status_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_cell_modem_status_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_front_end_gain_t> {
  static constexpr u16 id = 191;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_front_end_gain_t& get(const sbp_msg_t &msg) {
    return msg.front_end_gain;
  }
  static sbp_msg_front_end_gain_t& get(sbp_msg_t &msg) {
    return msg.front_end_gain;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_front_end_gain_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_front_end_gain_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_cw_results_t> {
  static constexpr u16 id = 192;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_cw_results_t& get(const sbp_msg_t &msg) {
    return msg.cw_results;
  }
  static sbp_msg_cw_results_t& get(sbp_msg_t &msg) {
    return msg.cw_results;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_cw_results_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_cw_results_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_cw_start_t> {
  static constexpr u16 id = 193;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_cw_start_t& get(const sbp_msg_t &msg) {
    return msg.cw_start;
  }
  static sbp_msg_cw_start_t& get(sbp_msg_t &msg) {
    return msg.cw_start;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_cw_start_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_cw_start_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_nap_device_dna_resp_t> {
  static constexpr u16 id = 221;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_nap_device_dna_resp_t& get(const sbp_msg_t &msg) {
    return msg.nap_device_dna_resp;
  }
  static sbp_msg_nap_device_dna_resp_t& get(sbp_msg_t &msg) {
    return msg.nap_device_dna_resp;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_nap_device_dna_resp_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_nap_device_dna_resp_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_nap_device_dna_req_t> {
  static constexpr u16 id = 222;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_nap_device_dna_req_t& get(const sbp_msg_t &msg) {
    return msg.nap_device_dna_req;
  }
  static sbp_msg_nap_device_dna_req_t& get(sbp_msg_t &msg) {
    return msg.nap_device_dna_req;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_nap_device_dna_req_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_nap_device_dna_req_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_flash_done_t> {
  static constexpr u16 id = 224;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_flash_done_t& get(const sbp_msg_t &msg) {
    return msg.flash_done;
  }
  static sbp_msg_flash_done_t& get(sbp_msg_t &msg) {
    return msg.flash_done;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_flash_done_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_flash_done_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_flash_read_resp_t> {
  static constexpr u16 id = 225;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_flash_read_resp_t& get(const sbp_msg_t &msg) {
    return msg.flash_read_resp;
  }
  static sbp_msg_flash_read_resp_t& get(sbp_msg_t &msg) {
    return msg.flash_read_resp;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_flash_read_resp_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_flash_read_resp_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_flash_erase_t> {
  static constexpr u16 id = 226;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_flash_erase_t& get(const sbp_msg_t &msg) {
    return msg.flash_erase;
  }
  static sbp_msg_flash_erase_t& get(sbp_msg_t &msg) {
    return msg.flash_erase;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_flash_erase_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_flash_erase_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_stm_flash_lock_sector_t> {
  static constexpr u16 id = 227;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_stm_flash_lock_sector_t& get(const sbp_msg_t &msg) {
    return msg.stm_flash_lock_sector;
  }
  static sbp_msg_stm_flash_lock_sector_t& get(sbp_msg_t &msg) {
    return msg.stm_flash_lock_sector;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_stm_flash_lock_sector_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_stm_flash_lock_sector_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_stm_flash_unlock_sector_t> {
  static constexpr u16 id = 228;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_stm_flash_unlock_sector_t& get(const sbp_msg_t &msg) {
    return msg.stm_flash_unlock_sector;
  }
  static sbp_msg_stm_flash_unlock_sector_t& get(sbp_msg_t &msg) {
    return msg.stm_flash_unlock_sector;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_stm_flash_unlock_sector_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_stm_flash_unlock_sector_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_stm_unique_id_resp_t> {
  static constexpr u16 id = 229;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_stm_unique_id_resp_t& get(const sbp_msg_t &msg) {
    return msg.stm_unique_id_resp;
  }
  static sbp_msg_stm_unique_id_resp_t& get(sbp_msg_t &msg) {
    return msg.stm_unique_id_resp;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_stm_unique_id_resp_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_stm_unique_id_resp_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_flash_program_t> {
  static constexpr u16 id = 230;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_flash_program_t& get(const sbp_msg_t &msg) {
    return msg.flash_program;
  }
  static sbp_msg_flash_program_t& get(sbp_msg_t &msg) {
    return msg.flash_program;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_flash_program_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_flash_program_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_flash_read_req_t> {
  static constexpr u16 id = 231;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_flash_read_req_t& get(const sbp_msg_t &msg) {
    return msg.flash_read_req;
  }
  static sbp_msg_flash_read_req_t& get(sbp_msg_t &msg) {
    return msg.flash_read_req;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_flash_read_req_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_flash_read_req_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_stm_unique_id_req_t> {
  static constexpr u16 id = 232;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_stm_unique_id_req_t& get(const sbp_msg_t &msg) {
    return msg.stm_unique_id_req;
  }
  static sbp_msg_stm_unique_id_req_t& get(sbp_msg_t &msg) {
    return msg.stm_unique_id_req;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_stm_unique_id_req_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_stm_unique_id_req_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_m25_flash_write_status_t> {
  static constexpr u16 id = 243;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_m25_flash_write_status_t& get(const sbp_msg_t &msg) {
    return msg.m25_flash_write_status;
  }
  static sbp_msg_m25_flash_write_status_t& get(sbp_msg_t &msg) {
    return msg.m25_flash_write_status;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_m25_flash_write_status_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_m25_flash_write_status_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_gps_time_dep_a_t> {
  static constexpr u16 id = 256;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_gps_time_dep_a_t& get(const sbp_msg_t &msg) {
    return msg.gps_time_dep_a;
  }
  static sbp_msg_gps_time_dep_a_t& get(sbp_msg_t &msg) {
    return msg.gps_time_dep_a;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_gps_time_dep_a_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_gps_time_dep_a_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_ext_event_t> {
  static constexpr u16 id = 257;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_ext_event_t& get(const sbp_msg_t &msg) {
    return msg.ext_event;
  }
  static sbp_msg_ext_event_t& get(sbp_msg_t &msg) {
    return msg.ext_event;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_ext_event_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_ext_event_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_gps_time_t> {
  static constexpr u16 id = 258;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_gps_time_t& get(const sbp_msg_t &msg) {
    return msg.gps_time;
  }
  static sbp_msg_gps_time_t& get(sbp_msg_t &msg) {
    return msg.gps_time;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_gps_time_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_gps_time_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_utc_time_t> {
  static constexpr u16 id = 259;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_utc_time_t& get(const sbp_msg_t &msg) {
    return msg.utc_time;
  }
  static sbp_msg_utc_time_t& get(sbp_msg_t &msg) {
    return msg.utc_time;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_utc_time_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_utc_time_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_gps_time_gnss_t> {
  static constexpr u16 id = 260;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_gps_time_gnss_t& get(const sbp_msg_t &msg) {
    return msg.gps_time_gnss;
  }
  static sbp_msg_gps_time_gnss_t& get(sbp_msg_t &msg) {
    return msg.gps_time_gnss;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_gps_time_gnss_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_gps_time_gnss_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_utc_time_gnss_t> {
  static constexpr u16 id = 261;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_utc_time_gnss_t& get(const sbp_msg_t &msg) {
    return msg.utc_time_gnss;
  }
  static sbp_msg_utc_time_gnss_t& get(sbp_msg_t &msg) {
    return msg.utc_time_gnss;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_utc_time_gnss_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_utc_time_gnss_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_settings_register_resp_t> {
  static constexpr u16 id = 431;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_settings_register_resp_t& get(const sbp_msg_t &msg) {
    return msg.settings_register_resp;
  }
  static sbp_msg_settings_register_resp_t& get(sbp_msg_t &msg) {
    return msg.settings_register_resp;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_settings_register_resp_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_settings_register_resp_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_pos_ecef_dep_a_t> {
  static constexpr u16 id = 512;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_pos_ecef_dep_a_t& get(const sbp_msg_t &msg) {
    return msg.pos_ecef_dep_a;
  }
  static sbp_msg_pos_ecef_dep_a_t& get(sbp_msg_t &msg) {
    return msg.pos_ecef_dep_a;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_pos_ecef_dep_a_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_pos_ecef_dep_a_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_pos_llh_dep_a_t> {
  static constexpr u16 id = 513;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_pos_llh_dep_a_t& get(const sbp_msg_t &msg) {
    return msg.pos_llh_dep_a;
  }
  static sbp_msg_pos_llh_dep_a_t& get(sbp_msg_t &msg) {
    return msg.pos_llh_dep_a;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_pos_llh_dep_a_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_pos_llh_dep_a_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_baseline_ecef_dep_a_t> {
  static constexpr u16 id = 514;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_baseline_ecef_dep_a_t& get(const sbp_msg_t &msg) {
    return msg.baseline_ecef_dep_a;
  }
  static sbp_msg_baseline_ecef_dep_a_t& get(sbp_msg_t &msg) {
    return msg.baseline_ecef_dep_a;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_baseline_ecef_dep_a_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_baseline_ecef_dep_a_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_baseline_ned_dep_a_t> {
  static constexpr u16 id = 515;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_baseline_ned_dep_a_t& get(const sbp_msg_t &msg) {
    return msg.baseline_ned_dep_a;
  }
  static sbp_msg_baseline_ned_dep_a_t& get(sbp_msg_t &msg) {
    return msg.baseline_ned_dep_a;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_baseline_ned_dep_a_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_baseline_ned_dep_a_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_vel_ecef_dep_a_t> {
  static constexpr u16 id = 516;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_vel_ecef_dep_a_t& get(const sbp_msg_t &msg) {
    return msg.vel_ecef_dep_a;
  }
  static sbp_msg_vel_ecef_dep_a_t& get(sbp_msg_t &msg) {
    return msg.vel_ecef_dep_a;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_vel_ecef_dep_a_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_vel_ecef_dep_a_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_vel_ned_dep_a_t> {
  static constexpr u16 id = 517;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_vel_ned_dep_a_t& get(const sbp_msg_t &msg) {
    return msg.vel_ned_dep_a;
  }
  static sbp_msg_vel_ned_dep_a_t& get(sbp_msg_t &msg) {
    return msg.vel_ned_dep_a;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_vel_ned_dep_a_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_vel_ned_dep_a_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_dops_dep_a_t> {
  static constexpr u16 id = 518;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_dops_dep_a_t& get(const sbp_msg_t &msg) {
    return msg.dops_dep_a;
  }
  static sbp_msg_dops_dep_a_t& get(sbp_msg_t &msg) {
    return msg.dops_dep_a;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_dops_dep_a_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_dops_dep_a_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_baseline_heading_dep_a_t> {
  static constexpr u16 id = 519;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_baseline_heading_dep_a_t& get(const sbp_msg_t &msg) {
    return msg.baseline_heading_dep_a;
  }
  static sbp_msg_baseline_heading_dep_a_t& get(sbp_msg_t &msg) {
    return msg.baseline_heading_dep_a;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_baseline_heading_dep_a_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_baseline_heading_dep_a_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_dops_t> {
  static constexpr u16 id = 520;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_dops_t& get(const sbp_msg_t &msg) {
    return msg.dops;
  }
  static sbp_msg_dops_t& get(sbp_msg_t &msg) {
    return msg.dops;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_dops_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_dops_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_pos_ecef_t> {
  static constexpr u16 id = 521;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_pos_ecef_t& get(const sbp_msg_t &msg) {
    return msg.pos_ecef;
  }
  static sbp_msg_pos_ecef_t& get(sbp_msg_t &msg) {
    return msg.pos_ecef;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_pos_ecef_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_pos_ecef_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_pos_llh_t> {
  static constexpr u16 id = 522;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_pos_llh_t& get(const sbp_msg_t &msg) {
    return msg.pos_llh;
  }
  static sbp_msg_pos_llh_t& get(sbp_msg_t &msg) {
    return msg.pos_llh;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_pos_llh_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_pos_llh_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_baseline_ecef_t> {
  static constexpr u16 id = 523;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_baseline_ecef_t& get(const sbp_msg_t &msg) {
    return msg.baseline_ecef;
  }
  static sbp_msg_baseline_ecef_t& get(sbp_msg_t &msg) {
    return msg.baseline_ecef;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_baseline_ecef_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_baseline_ecef_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_baseline_ned_t> {
  static constexpr u16 id = 524;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_baseline_ned_t& get(const sbp_msg_t &msg) {
    return msg.baseline_ned;
  }
  static sbp_msg_baseline_ned_t& get(sbp_msg_t &msg) {
    return msg.baseline_ned;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_baseline_ned_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_baseline_ned_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_vel_ecef_t> {
  static constexpr u16 id = 525;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_vel_ecef_t& get(const sbp_msg_t &msg) {
    return msg.vel_ecef;
  }
  static sbp_msg_vel_ecef_t& get(sbp_msg_t &msg) {
    return msg.vel_ecef;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_vel_ecef_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_vel_ecef_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_vel_ned_t> {
  static constexpr u16 id = 526;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_vel_ned_t& get(const sbp_msg_t &msg) {
    return msg.vel_ned;
  }
  static sbp_msg_vel_ned_t& get(sbp_msg_t &msg) {
    return msg.vel_ned;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_vel_ned_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_vel_ned_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_baseline_heading_t> {
  static constexpr u16 id = 527;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_baseline_heading_t& get(const sbp_msg_t &msg) {
    return msg.baseline_heading;
  }
  static sbp_msg_baseline_heading_t& get(sbp_msg_t &msg) {
    return msg.baseline_heading;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_baseline_heading_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_baseline_heading_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_age_corrections_t> {
  static constexpr u16 id = 528;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_age_corrections_t& get(const sbp_msg_t &msg) {
    return msg.age_corrections;
  }
  static sbp_msg_age_corrections_t& get(sbp_msg_t &msg) {
    return msg.age_corrections;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_age_corrections_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_age_corrections_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_pos_llh_cov_t> {
  static constexpr u16 id = 529;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_pos_llh_cov_t& get(const sbp_msg_t &msg) {
    return msg.pos_llh_cov;
  }
  static sbp_msg_pos_llh_cov_t& get(sbp_msg_t &msg) {
    return msg.pos_llh_cov;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_pos_llh_cov_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_pos_llh_cov_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_vel_ned_cov_t> {
  static constexpr u16 id = 530;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_vel_ned_cov_t& get(const sbp_msg_t &msg) {
    return msg.vel_ned_cov;
  }
  static sbp_msg_vel_ned_cov_t& get(sbp_msg_t &msg) {
    return msg.vel_ned_cov;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_vel_ned_cov_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_vel_ned_cov_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_vel_body_t> {
  static constexpr u16 id = 531;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_vel_body_t& get(const sbp_msg_t &msg) {
    return msg.vel_body;
  }
  static sbp_msg_vel_body_t& get(sbp_msg_t &msg) {
    return msg.vel_body;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_vel_body_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_vel_body_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_pos_ecef_cov_t> {
  static constexpr u16 id = 532;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_pos_ecef_cov_t& get(const sbp_msg_t &msg) {
    return msg.pos_ecef_cov;
  }
  static sbp_msg_pos_ecef_cov_t& get(sbp_msg_t &msg) {
    return msg.pos_ecef_cov;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_pos_ecef_cov_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_pos_ecef_cov_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_vel_ecef_cov_t> {
  static constexpr u16 id = 533;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_vel_ecef_cov_t& get(const sbp_msg_t &msg) {
    return msg.vel_ecef_cov;
  }
  static sbp_msg_vel_ecef_cov_t& get(sbp_msg_t &msg) {
    return msg.vel_ecef_cov;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_vel_ecef_cov_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_vel_ecef_cov_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_protection_level_dep_a_t> {
  static constexpr u16 id = 534;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_protection_level_dep_a_t& get(const sbp_msg_t &msg) {
    return msg.protection_level_dep_a;
  }
  static sbp_msg_protection_level_dep_a_t& get(sbp_msg_t &msg) {
    return msg.protection_level_dep_a;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_protection_level_dep_a_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_protection_level_dep_a_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_protection_level_t> {
  static constexpr u16 id = 535;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_protection_level_t& get(const sbp_msg_t &msg) {
    return msg.protection_level;
  }
  static sbp_msg_protection_level_t& get(sbp_msg_t &msg) {
    return msg.protection_level;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_protection_level_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_protection_level_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_orient_quat_t> {
  static constexpr u16 id = 544;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_orient_quat_t& get(const sbp_msg_t &msg) {
    return msg.orient_quat;
  }
  static sbp_msg_orient_quat_t& get(sbp_msg_t &msg) {
    return msg.orient_quat;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_orient_quat_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_orient_quat_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_orient_euler_t> {
  static constexpr u16 id = 545;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_orient_euler_t& get(const sbp_msg_t &msg) {
    return msg.orient_euler;
  }
  static sbp_msg_orient_euler_t& get(sbp_msg_t &msg) {
    return msg.orient_euler;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_orient_euler_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_orient_euler_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_angular_rate_t> {
  static constexpr u16 id = 546;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_angular_rate_t& get(const sbp_msg_t &msg) {
    return msg.angular_rate;
  }
  static sbp_msg_angular_rate_t& get(sbp_msg_t &msg) {
    return msg.angular_rate;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_angular_rate_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_angular_rate_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_pos_ecef_gnss_t> {
  static constexpr u16 id = 553;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_pos_ecef_gnss_t& get(const sbp_msg_t &msg) {
    return msg.pos_ecef_gnss;
  }
  static sbp_msg_pos_ecef_gnss_t& get(sbp_msg_t &msg) {
    return msg.pos_ecef_gnss;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_pos_ecef_gnss_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_pos_ecef_gnss_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_pos_llh_gnss_t> {
  static constexpr u16 id = 554;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_pos_llh_gnss_t& get(const sbp_msg_t &msg) {
    return msg.pos_llh_gnss;
  }
  static sbp_msg_pos_llh_gnss_t& get(sbp_msg_t &msg) {
    return msg.pos_llh_gnss;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_pos_llh_gnss_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_pos_llh_gnss_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_vel_ecef_gnss_t> {
  static constexpr u16 id = 557;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_vel_ecef_gnss_t& get(const sbp_msg_t &msg) {
    return msg.vel_ecef_gnss;
  }
  static sbp_msg_vel_ecef_gnss_t& get(sbp_msg_t &msg) {
    return msg.vel_ecef_gnss;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_vel_ecef_gnss_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_vel_ecef_gnss_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_vel_ned_gnss_t> {
  static constexpr u16 id = 558;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_vel_ned_gnss_t& get(const sbp_msg_t &msg) {
    return msg.vel_ned_gnss;
  }
  static sbp_msg_vel_ned_gnss_t& get(sbp_msg_t &msg) {
    return msg.vel_ned_gnss;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_vel_ned_gnss_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_vel_ned_gnss_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_pos_llh_cov_gnss_t> {
  static constexpr u16 id = 561;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_pos_llh_cov_gnss_t& get(const sbp_msg_t &msg) {
    return msg.pos_llh_cov_gnss;
  }
  static sbp_msg_pos_llh_cov_gnss_t& get(sbp_msg_t &msg) {
    return msg.pos_llh_cov_gnss;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_pos_llh_cov_gnss_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_pos_llh_cov_gnss_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_vel_ned_cov_gnss_t> {
  static constexpr u16 id = 562;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_vel_ned_cov_gnss_t& get(const sbp_msg_t &msg) {
    return msg.vel_ned_cov_gnss;
  }
  static sbp_msg_vel_ned_cov_gnss_t& get(sbp_msg_t &msg) {
    return msg.vel_ned_cov_gnss;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_vel_ned_cov_gnss_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_vel_ned_cov_gnss_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_pos_ecef_cov_gnss_t> {
  static constexpr u16 id = 564;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_pos_ecef_cov_gnss_t& get(const sbp_msg_t &msg) {
    return msg.pos_ecef_cov_gnss;
  }
  static sbp_msg_pos_ecef_cov_gnss_t& get(sbp_msg_t &msg) {
    return msg.pos_ecef_cov_gnss;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_pos_ecef_cov_gnss_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_pos_ecef_cov_gnss_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_vel_ecef_cov_gnss_t> {
  static constexpr u16 id = 565;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_vel_ecef_cov_gnss_t& get(const sbp_msg_t &msg) {
    return msg.vel_ecef_cov_gnss;
  }
  static sbp_msg_vel_ecef_cov_gnss_t& get(sbp_msg_t &msg) {
    return msg.vel_ecef_cov_gnss;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_vel_ecef_cov_gnss_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_vel_ecef_cov_gnss_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_ndb_event_t> {
  static constexpr u16 id = 1024;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_ndb_event_t& get(const sbp_msg_t &msg) {
    return msg.ndb_event;
  }
  static sbp_msg_ndb_event_t& get(sbp_msg_t &msg) {
    return msg.ndb_event;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_ndb_event_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_ndb_event_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_log_t> {
  static constexpr u16 id = 1025;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_log_t& get(const sbp_msg_t &msg) {
    return msg.log;
  }
  static sbp_msg_log_t& get(sbp_msg_t &msg) {
    return msg.log;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_log_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_log_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_fwd_t> {
  static constexpr u16 id = 1026;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_fwd_t& get(const sbp_msg_t &msg) {
    return msg.fwd;
  }
  static sbp_msg_fwd_t& get(sbp_msg_t &msg) {
    return msg.fwd;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_fwd_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_fwd_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_ssr_orbit_clock_dep_a_t> {
  static constexpr u16 id = 1500;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_ssr_orbit_clock_dep_a_t& get(const sbp_msg_t &msg) {
    return msg.ssr_orbit_clock_dep_a;
  }
  static sbp_msg_ssr_orbit_clock_dep_a_t& get(sbp_msg_t &msg) {
    return msg.ssr_orbit_clock_dep_a;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_ssr_orbit_clock_dep_a_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_ssr_orbit_clock_dep_a_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_ssr_orbit_clock_t> {
  static constexpr u16 id = 1501;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_ssr_orbit_clock_t& get(const sbp_msg_t &msg) {
    return msg.ssr_orbit_clock;
  }
  static sbp_msg_ssr_orbit_clock_t& get(sbp_msg_t &msg) {
    return msg.ssr_orbit_clock;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_ssr_orbit_clock_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_ssr_orbit_clock_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_ssr_code_biases_t> {
  static constexpr u16 id = 1505;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_ssr_code_biases_t& get(const sbp_msg_t &msg) {
    return msg.ssr_code_biases;
  }
  static sbp_msg_ssr_code_biases_t& get(sbp_msg_t &msg) {
    return msg.ssr_code_biases;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_ssr_code_biases_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_ssr_code_biases_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_ssr_phase_biases_t> {
  static constexpr u16 id = 1510;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_ssr_phase_biases_t& get(const sbp_msg_t &msg) {
    return msg.ssr_phase_biases;
  }
  static sbp_msg_ssr_phase_biases_t& get(sbp_msg_t &msg) {
    return msg.ssr_phase_biases;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_ssr_phase_biases_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_ssr_phase_biases_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_ssr_stec_correction_dep_a_t> {
  static constexpr u16 id = 1515;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_ssr_stec_correction_dep_a_t& get(const sbp_msg_t &msg) {
    return msg.ssr_stec_correction_dep_a;
  }
  static sbp_msg_ssr_stec_correction_dep_a_t& get(sbp_msg_t &msg) {
    return msg.ssr_stec_correction_dep_a;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_ssr_stec_correction_dep_a_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_ssr_stec_correction_dep_a_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_ssr_gridded_correction_no_std_dep_a_t> {
  static constexpr u16 id = 1520;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_ssr_gridded_correction_no_std_dep_a_t& get(const sbp_msg_t &msg) {
    return msg.ssr_gridded_correction_no_std_dep_a;
  }
  static sbp_msg_ssr_gridded_correction_no_std_dep_a_t& get(sbp_msg_t &msg) {
    return msg.ssr_gridded_correction_no_std_dep_a;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_ssr_gridded_correction_no_std_dep_a_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_ssr_gridded_correction_no_std_dep_a_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_ssr_grid_definition_dep_a_t> {
  static constexpr u16 id = 1525;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_ssr_grid_definition_dep_a_t& get(const sbp_msg_t &msg) {
    return msg.ssr_grid_definition_dep_a;
  }
  static sbp_msg_ssr_grid_definition_dep_a_t& get(sbp_msg_t &msg) {
    return msg.ssr_grid_definition_dep_a;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_ssr_grid_definition_dep_a_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_ssr_grid_definition_dep_a_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_ssr_tile_definition_t> {
  static constexpr u16 id = 1526;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_ssr_tile_definition_t& get(const sbp_msg_t &msg) {
    return msg.ssr_tile_definition;
  }
  static sbp_msg_ssr_tile_definition_t& get(sbp_msg_t &msg) {
    return msg.ssr_tile_definition;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_ssr_tile_definition_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_ssr_tile_definition_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_ssr_gridded_correction_dep_a_t> {
  static constexpr u16 id = 1530;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_ssr_gridded_correction_dep_a_t& get(const sbp_msg_t &msg) {
    return msg.ssr_gridded_correction_dep_a;
  }
  static sbp_msg_ssr_gridded_correction_dep_a_t& get(sbp_msg_t &msg) {
    return msg.ssr_gridded_correction_dep_a;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_ssr_gridded_correction_dep_a_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_ssr_gridded_correction_dep_a_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_ssr_stec_correction_t> {
  static constexpr u16 id = 1531;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_ssr_stec_correction_t& get(const sbp_msg_t &msg) {
    return msg.ssr_stec_correction;
  }
  static sbp_msg_ssr_stec_correction_t& get(sbp_msg_t &msg) {
    return msg.ssr_stec_correction;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_ssr_stec_correction_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_ssr_stec_correction_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_ssr_gridded_correction_t> {
  static constexpr u16 id = 1532;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_ssr_gridded_correction_t& get(const sbp_msg_t &msg) {
    return msg.ssr_gridded_correction;
  }
  static sbp_msg_ssr_gridded_correction_t& get(sbp_msg_t &msg) {
    return msg.ssr_gridded_correction;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_ssr_gridded_correction_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_ssr_gridded_correction_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_ssr_satellite_apc_t> {
  static constexpr u16 id = 1540;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_ssr_satellite_apc_t& get(const sbp_msg_t &msg) {
    return msg.ssr_satellite_apc;
  }
  static sbp_msg_ssr_satellite_apc_t& get(sbp_msg_t &msg) {
    return msg.ssr_satellite_apc;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_ssr_satellite_apc_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_ssr_satellite_apc_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_osr_t> {
  static constexpr u16 id = 1600;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_osr_t& get(const sbp_msg_t &msg) {
    return msg.osr;
  }
  static sbp_msg_osr_t& get(sbp_msg_t &msg) {
    return msg.osr;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_osr_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_osr_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_user_data_t> {
  static constexpr u16 id = 2048;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_user_data_t& get(const sbp_msg_t &msg) {
    return msg.user_data;
  }
  static sbp_msg_user_data_t& get(sbp_msg_t &msg) {
    return msg.user_data;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_user_data_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_user_data_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_imu_raw_t> {
  static constexpr u16 id = 2304;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_imu_raw_t& get(const sbp_msg_t &msg) {
    return msg.imu_raw;
  }
  static sbp_msg_imu_raw_t& get(sbp_msg_t &msg) {
    return msg.imu_raw;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_imu_raw_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_imu_raw_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_imu_aux_t> {
  static constexpr u16 id = 2305;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_imu_aux_t& get(const sbp_msg_t &msg) {
    return msg.imu_aux;
  }
  static sbp_msg_imu_aux_t& get(sbp_msg_t &msg) {
    return msg.imu_aux;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_imu_aux_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_imu_aux_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_mag_raw_t> {
  static constexpr u16 id = 2306;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_mag_raw_t& get(const sbp_msg_t &msg) {
    return msg.mag_raw;
  }
  static sbp_msg_mag_raw_t& get(sbp_msg_t &msg) {
    return msg.mag_raw;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_mag_raw_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_mag_raw_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_odometry_t> {
  static constexpr u16 id = 2307;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_odometry_t& get(const sbp_msg_t &msg) {
    return msg.odometry;
  }
  static sbp_msg_odometry_t& get(sbp_msg_t &msg) {
    return msg.odometry;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_odometry_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_odometry_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_wheeltick_t> {
  static constexpr u16 id = 2308;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_wheeltick_t& get(const sbp_msg_t &msg) {
    return msg.wheeltick;
  }
  static sbp_msg_wheeltick_t& get(sbp_msg_t &msg) {
    return msg.wheeltick;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_wheeltick_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_wheeltick_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_fileio_config_req_t> {
  static constexpr u16 id = 4097;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_fileio_config_req_t& get(const sbp_msg_t &msg) {
    return msg.fileio_config_req;
  }
  static sbp_msg_fileio_config_req_t& get(sbp_msg_t &msg) {
    return msg.fileio_config_req;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_fileio_config_req_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_fileio_config_req_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_fileio_config_resp_t> {
  static constexpr u16 id = 4098;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_fileio_config_resp_t& get(const sbp_msg_t &msg) {
    return msg.fileio_config_resp;
  }
  static sbp_msg_fileio_config_resp_t& get(sbp_msg_t &msg) {
    return msg.fileio_config_resp;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_fileio_config_resp_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_fileio_config_resp_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_sbas_raw_t> {
  static constexpr u16 id = 30583;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_sbas_raw_t& get(const sbp_msg_t &msg) {
    return msg.sbas_raw;
  }
  static sbp_msg_sbas_raw_t& get(sbp_msg_t &msg) {
    return msg.sbas_raw;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_sbas_raw_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_sbas_raw_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_linux_cpu_state_dep_a_t> {
  static constexpr u16 id = 32512;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_linux_cpu_state_dep_a_t& get(const sbp_msg_t &msg) {
    return msg.linux_cpu_state_dep_a;
  }
  static sbp_msg_linux_cpu_state_dep_a_t& get(sbp_msg_t &msg) {
    return msg.linux_cpu_state_dep_a;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_linux_cpu_state_dep_a_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_linux_cpu_state_dep_a_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_linux_mem_state_dep_a_t> {
  static constexpr u16 id = 32513;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_linux_mem_state_dep_a_t& get(const sbp_msg_t &msg) {
    return msg.linux_mem_state_dep_a;
  }
  static sbp_msg_linux_mem_state_dep_a_t& get(sbp_msg_t &msg) {
    return msg.linux_mem_state_dep_a;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_linux_mem_state_dep_a_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_linux_mem_state_dep_a_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_linux_sys_state_dep_a_t> {
  static constexpr u16 id = 32514;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_linux_sys_state_dep_a_t& get(const sbp_msg_t &msg) {
    return msg.linux_sys_state_dep_a;
  }
  static sbp_msg_linux_sys_state_dep_a_t& get(sbp_msg_t &msg) {
    return msg.linux_sys_state_dep_a;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_linux_sys_state_dep_a_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_linux_sys_state_dep_a_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_linux_process_socket_counts_t> {
  static constexpr u16 id = 32515;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_linux_process_socket_counts_t& get(const sbp_msg_t &msg) {
    return msg.linux_process_socket_counts;
  }
  static sbp_msg_linux_process_socket_counts_t& get(sbp_msg_t &msg) {
    return msg.linux_process_socket_counts;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_linux_process_socket_counts_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_linux_process_socket_counts_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_linux_process_socket_queues_t> {
  static constexpr u16 id = 32516;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_linux_process_socket_queues_t& get(const sbp_msg_t &msg) {
    return msg.linux_process_socket_queues;
  }
  static sbp_msg_linux_process_socket_queues_t& get(sbp_msg_t &msg) {
    return msg.linux_process_socket_queues;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_linux_process_socket_queues_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_linux_process_socket_queues_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_linux_socket_usage_t> {
  static constexpr u16 id = 32517;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_linux_socket_usage_t& get(const sbp_msg_t &msg) {
    return msg.linux_socket_usage;
  }
  static sbp_msg_linux_socket_usage_t& get(sbp_msg_t &msg) {
    return msg.linux_socket_usage;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_linux_socket_usage_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_linux_socket_usage_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_linux_process_fd_count_t> {
  static constexpr u16 id = 32518;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_linux_process_fd_count_t& get(const sbp_msg_t &msg) {
    return msg.linux_process_fd_count;
  }
  static sbp_msg_linux_process_fd_count_t& get(sbp_msg_t &msg) {
    return msg.linux_process_fd_count;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_linux_process_fd_count_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_linux_process_fd_count_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_linux_process_fd_summary_t> {
  static constexpr u16 id = 32519;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_linux_process_fd_summary_t& get(const sbp_msg_t &msg) {
    return msg.linux_process_fd_summary;
  }
  static sbp_msg_linux_process_fd_summary_t& get(sbp_msg_t &msg) {
    return msg.linux_process_fd_summary;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_linux_process_fd_summary_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_linux_process_fd_summary_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_linux_cpu_state_t> {
  static constexpr u16 id = 32520;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_linux_cpu_state_t& get(const sbp_msg_t &msg) {
    return msg.linux_cpu_state;
  }
  static sbp_msg_linux_cpu_state_t& get(sbp_msg_t &msg) {
    return msg.linux_cpu_state;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_linux_cpu_state_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_linux_cpu_state_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_linux_mem_state_t> {
  static constexpr u16 id = 32521;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_linux_mem_state_t& get(const sbp_msg_t &msg) {
    return msg.linux_mem_state;
  }
  static sbp_msg_linux_mem_state_t& get(sbp_msg_t &msg) {
    return msg.linux_mem_state;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_linux_mem_state_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_linux_mem_state_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_linux_sys_state_t> {
  static constexpr u16 id = 32522;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_linux_sys_state_t& get(const sbp_msg_t &msg) {
    return msg.linux_sys_state;
  }
  static sbp_msg_linux_sys_state_t& get(sbp_msg_t &msg) {
    return msg.linux_sys_state;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_linux_sys_state_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_linux_sys_state_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_startup_t> {
  static constexpr u16 id = 65280;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_startup_t& get(const sbp_msg_t &msg) {
    return msg.startup;
  }
  static sbp_msg_startup_t& get(sbp_msg_t &msg) {
    return msg.startup;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_startup_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_startup_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_dgnss_status_t> {
  static constexpr u16 id = 65282;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_dgnss_status_t& get(const sbp_msg_t &msg) {
    return msg.dgnss_status;
  }
  static sbp_msg_dgnss_status_t& get(sbp_msg_t &msg) {
    return msg.dgnss_status;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_dgnss_status_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_dgnss_status_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_ins_status_t> {
  static constexpr u16 id = 65283;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_ins_status_t& get(const sbp_msg_t &msg) {
    return msg.ins_status;
  }
  static sbp_msg_ins_status_t& get(sbp_msg_t &msg) {
    return msg.ins_status;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_ins_status_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_ins_status_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_csac_telemetry_t> {
  static constexpr u16 id = 65284;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_csac_telemetry_t& get(const sbp_msg_t &msg) {
    return msg.csac_telemetry;
  }
  static sbp_msg_csac_telemetry_t& get(sbp_msg_t &msg) {
    return msg.csac_telemetry;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_csac_telemetry_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_csac_telemetry_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_csac_telemetry_labels_t> {
  static constexpr u16 id = 65285;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_csac_telemetry_labels_t& get(const sbp_msg_t &msg) {
    return msg.csac_telemetry_labels;
  }
  static sbp_msg_csac_telemetry_labels_t& get(sbp_msg_t &msg) {
    return msg.csac_telemetry_labels;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_csac_telemetry_labels_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_csac_telemetry_labels_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_ins_updates_t> {
  static constexpr u16 id = 65286;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_ins_updates_t& get(const sbp_msg_t &msg) {
    return msg.ins_updates;
  }
  static sbp_msg_ins_updates_t& get(sbp_msg_t &msg) {
    return msg.ins_updates;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_ins_updates_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_ins_updates_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_gnss_time_offset_t> {
  static constexpr u16 id = 65287;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_gnss_time_offset_t& get(const sbp_msg_t &msg) {
    return msg.gnss_time_offset;
  }
  static sbp_msg_gnss_time_offset_t& get(sbp_msg_t &msg) {
    return msg.gnss_time_offset;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_gnss_time_offset_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_gnss_time_offset_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_pps_time_t> {
  static constexpr u16 id = 65288;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_pps_time_t& get(const sbp_msg_t &msg) {
    return msg.pps_time;
  }
  static sbp_msg_pps_time_t& get(sbp_msg_t &msg) {
    return msg.pps_time;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_pps_time_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_pps_time_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_group_meta_t> {
  static constexpr u16 id = 65290;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_group_meta_t& get(const sbp_msg_t &msg) {
    return msg.group_meta;
  }
  static sbp_msg_group_meta_t& get(sbp_msg_t &msg) {
    return msg.group_meta;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_group_meta_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_group_meta_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_soln_meta_t> {
  static constexpr u16 id = 65294;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_soln_meta_t& get(const sbp_msg_t &msg) {
    return msg.soln_meta;
  }
  static sbp_msg_soln_meta_t& get(sbp_msg_t &msg) {
    return msg.soln_meta;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_soln_meta_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_soln_meta_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_soln_meta_dep_a_t> {
  static constexpr u16 id = 65295;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_soln_meta_dep_a_t& get(const sbp_msg_t &msg) {
    return msg.soln_meta_dep_a;
  }
  static sbp_msg_soln_meta_dep_a_t& get(sbp_msg_t &msg) {
    return msg.soln_meta_dep_a;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_soln_meta_dep_a_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_soln_meta_dep_a_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_status_report_t> {
  static constexpr u16 id = 65534;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_status_report_t& get(const sbp_msg_t &msg) {
    return msg.status_report;
  }
  static sbp_msg_status_report_t& get(sbp_msg_t &msg) {
    return msg.status_report;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_status_report_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_status_report_t(state, sender_id, &msg, write);
  }
};


template<>
struct MessageTraits<sbp_msg_heartbeat_t> {
  static constexpr u16 id = 65535;
  static constexpr bool is_unpacked = true;
  static const sbp_msg_heartbeat_t& get(const sbp_msg_t &msg) {
    return msg.heartbeat;
  }
  static sbp_msg_heartbeat_t& get(sbp_msg_t &msg) {
    return msg.heartbeat;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_heartbeat_t &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_sbp_msg_heartbeat_t(state, sender_id, &msg, write);
  }
};




} // namespace sbp

#endif //SBP_CPP_MESSAGE_TRAITS_H
