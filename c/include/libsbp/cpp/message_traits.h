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
#include <libsbp/new/sbp_msg.h>
#include <libsbp/new/acquisition.h>
#include <libsbp/new/bootload.h>
#include <libsbp/new/ext_events.h>
#include <libsbp/new/file_io.h>
#include <libsbp/new/flash.h>
#include <libsbp/new/gnss.h>
#include <libsbp/new/imu.h>
#include <libsbp/new/linux.h>
#include <libsbp/new/logging.h>
#include <libsbp/new/mag.h>
#include <libsbp/new/navigation.h>
#include <libsbp/new/ndb.h>
#include <libsbp/new/observation.h>
#include <libsbp/new/orientation.h>
#include <libsbp/new/piksi.h>
#include <libsbp/new/sbas.h>
#include <libsbp/new/settings.h>
#include <libsbp/new/solution_meta.h>
#include <libsbp/new/ssr.h>
#include <libsbp/new/system.h>
#include <libsbp/new/tracking.h>
#include <libsbp/new/user.h>
#include <libsbp/new/vehicle.h>

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




} // namespace sbp

#endif //SBP_CPP_MESSAGE_TRAITS_H
