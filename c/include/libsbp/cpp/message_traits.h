/**
 * Copyright (C) 2021 Swift Navigation Inc.
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
 * Automatically generated with generate.py. Please do not hand edit!
 *****************************************************************************/

#ifndef LIBSBP_CPP_MESSAGE_TRAITS_H
#define LIBSBP_CPP_MESSAGE_TRAITS_H

#include <libsbp/sbp.h>
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
#include <libsbp/v4/sbp_msg.h>
#include <libsbp/v4/settings.h>
#include <libsbp/v4/solution_meta.h>
#include <libsbp/v4/ssr.h>
#include <libsbp/v4/system.h>
#include <libsbp/v4/tracking.h>
#include <libsbp/v4/user.h>
#include <libsbp/v4/vehicle.h>

namespace sbp {

/**
 * Type traits containing meta-information for each SBP message type.
 *
 * These are only meant to be used by the C++ library at compile time.
 * These are automatically generated, DO NOT EDIT.
 */
template <typename>
struct MessageTraits;

template <>
struct MessageTraits<sbp_msg_group_meta_t> {
  static constexpr sbp_msg_type_t id = SbpMsgGroupMeta;
  static const sbp_msg_group_meta_t &get(const sbp_msg_t &msg) {
    return msg.group_meta;
  }
  static sbp_msg_group_meta_t &get(sbp_msg_t &msg) { return msg.group_meta; }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_group_meta_t &msg, sbp_write_fn_t write) {
    return sbp_msg_group_meta_send(state, sender_id, &msg, write);
  }
};

template <>
struct MessageTraits<sbp_msg_log_t> {
  static constexpr sbp_msg_type_t id = SbpMsgLog;
  static const sbp_msg_log_t &get(const sbp_msg_t &msg) { return msg.log; }
  static sbp_msg_log_t &get(sbp_msg_t &msg) { return msg.log; }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_log_t &msg,
                 sbp_write_fn_t write) {
    return sbp_msg_log_send(state, sender_id, &msg, write);
  }
};

template <>
struct MessageTraits<sbp_msg_obs_t> {
  static constexpr sbp_msg_type_t id = SbpMsgObs;
  static const sbp_msg_obs_t &get(const sbp_msg_t &msg) { return msg.obs; }
  static sbp_msg_obs_t &get(sbp_msg_t &msg) { return msg.obs; }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_obs_t &msg,
                 sbp_write_fn_t write) {
    return sbp_msg_obs_send(state, sender_id, &msg, write);
  }
};

template <>
struct MessageTraits<sbp_msg_settings_read_by_index_done_t> {
  static constexpr sbp_msg_type_t id = SbpMsgSettingsReadByIndexDone;
  static const sbp_msg_settings_read_by_index_done_t &get(
      const sbp_msg_t &msg) {
    return msg.settings_read_by_index_done;
  }
  static sbp_msg_settings_read_by_index_done_t &get(sbp_msg_t &msg) {
    return msg.settings_read_by_index_done;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_settings_read_by_index_done_t &msg,
                 sbp_write_fn_t write) {
    return sbp_msg_settings_read_by_index_done_send(state, sender_id, &msg,
                                                    write);
  }
};

template <>
struct MessageTraits<sbp_msg_settings_read_by_index_resp_t> {
  static constexpr sbp_msg_type_t id = SbpMsgSettingsReadByIndexResp;
  static const sbp_msg_settings_read_by_index_resp_t &get(
      const sbp_msg_t &msg) {
    return msg.settings_read_by_index_resp;
  }
  static sbp_msg_settings_read_by_index_resp_t &get(sbp_msg_t &msg) {
    return msg.settings_read_by_index_resp;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_settings_read_by_index_resp_t &msg,
                 sbp_write_fn_t write) {
    return sbp_msg_settings_read_by_index_resp_send(state, sender_id, &msg,
                                                    write);
  }
};

template <>
struct MessageTraits<sbp_msg_sv_az_el_t> {
  static constexpr sbp_msg_type_t id = SbpMsgSvAzEl;
  static const sbp_msg_sv_az_el_t &get(const sbp_msg_t &msg) {
    return msg.sv_az_el;
  }
  static sbp_msg_sv_az_el_t &get(sbp_msg_t &msg) { return msg.sv_az_el; }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_sv_az_el_t &msg, sbp_write_fn_t write) {
    return sbp_msg_sv_az_el_send(state, sender_id, &msg, write);
  }
};

}  // namespace sbp

#endif  // LIBSBP_CPP_MESSAGE_TRAITS_H
