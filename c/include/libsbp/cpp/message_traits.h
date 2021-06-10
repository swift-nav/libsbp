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
struct MessageTraits<sbp_msg_acq_result_dep_a_t> {
  static constexpr sbp_msg_type_t id = SbpMsgAcqResultDepA;
  static const sbp_msg_acq_result_dep_a_t &get(const sbp_msg_t &msg) {
    return msg.acq_result_dep_a;
  }
  static sbp_msg_acq_result_dep_a_t &get(sbp_msg_t &msg) {
    return msg.acq_result_dep_a;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_acq_result_dep_a_t &msg, sbp_write_fn_t write) {
    return sbp_msg_acq_result_dep_a_send(state, sender_id, &msg, write);
  }
};

template <>
struct MessageTraits<sbp_msg_acq_result_dep_b_t> {
  static constexpr sbp_msg_type_t id = SbpMsgAcqResultDepB;
  static const sbp_msg_acq_result_dep_b_t &get(const sbp_msg_t &msg) {
    return msg.acq_result_dep_b;
  }
  static sbp_msg_acq_result_dep_b_t &get(sbp_msg_t &msg) {
    return msg.acq_result_dep_b;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_acq_result_dep_b_t &msg, sbp_write_fn_t write) {
    return sbp_msg_acq_result_dep_b_send(state, sender_id, &msg, write);
  }
};

template <>
struct MessageTraits<sbp_msg_acq_result_dep_c_t> {
  static constexpr sbp_msg_type_t id = SbpMsgAcqResultDepC;
  static const sbp_msg_acq_result_dep_c_t &get(const sbp_msg_t &msg) {
    return msg.acq_result_dep_c;
  }
  static sbp_msg_acq_result_dep_c_t &get(sbp_msg_t &msg) {
    return msg.acq_result_dep_c;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_acq_result_dep_c_t &msg, sbp_write_fn_t write) {
    return sbp_msg_acq_result_dep_c_send(state, sender_id, &msg, write);
  }
};

template <>
struct MessageTraits<sbp_msg_acq_result_t> {
  static constexpr sbp_msg_type_t id = SbpMsgAcqResult;
  static const sbp_msg_acq_result_t &get(const sbp_msg_t &msg) {
    return msg.acq_result;
  }
  static sbp_msg_acq_result_t &get(sbp_msg_t &msg) { return msg.acq_result; }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_acq_result_t &msg, sbp_write_fn_t write) {
    return sbp_msg_acq_result_send(state, sender_id, &msg, write);
  }
};

template <>
struct MessageTraits<sbp_msg_acq_sv_profile_dep_t> {
  static constexpr sbp_msg_type_t id = SbpMsgAcqSvProfileDep;
  static const sbp_msg_acq_sv_profile_dep_t &get(const sbp_msg_t &msg) {
    return msg.acq_sv_profile_dep;
  }
  static sbp_msg_acq_sv_profile_dep_t &get(sbp_msg_t &msg) {
    return msg.acq_sv_profile_dep;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_acq_sv_profile_dep_t &msg,
                 sbp_write_fn_t write) {
    return sbp_msg_acq_sv_profile_dep_send(state, sender_id, &msg, write);
  }
};

template <>
struct MessageTraits<sbp_msg_acq_sv_profile_t> {
  static constexpr sbp_msg_type_t id = SbpMsgAcqSvProfile;
  static const sbp_msg_acq_sv_profile_t &get(const sbp_msg_t &msg) {
    return msg.acq_sv_profile;
  }
  static sbp_msg_acq_sv_profile_t &get(sbp_msg_t &msg) {
    return msg.acq_sv_profile;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_acq_sv_profile_t &msg, sbp_write_fn_t write) {
    return sbp_msg_acq_sv_profile_send(state, sender_id, &msg, write);
  }
};

template <>
struct MessageTraits<sbp_msg_age_corrections_t> {
  static constexpr sbp_msg_type_t id = SbpMsgAgeCorrections;
  static const sbp_msg_age_corrections_t &get(const sbp_msg_t &msg) {
    return msg.age_corrections;
  }
  static sbp_msg_age_corrections_t &get(sbp_msg_t &msg) {
    return msg.age_corrections;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_age_corrections_t &msg, sbp_write_fn_t write) {
    return sbp_msg_age_corrections_send(state, sender_id, &msg, write);
  }
};

template <>
struct MessageTraits<sbp_msg_almanac_glo_dep_t> {
  static constexpr sbp_msg_type_t id = SbpMsgAlmanacGloDep;
  static const sbp_msg_almanac_glo_dep_t &get(const sbp_msg_t &msg) {
    return msg.almanac_glo_dep;
  }
  static sbp_msg_almanac_glo_dep_t &get(sbp_msg_t &msg) {
    return msg.almanac_glo_dep;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_almanac_glo_dep_t &msg, sbp_write_fn_t write) {
    return sbp_msg_almanac_glo_dep_send(state, sender_id, &msg, write);
  }
};

template <>
struct MessageTraits<sbp_msg_almanac_glo_t> {
  static constexpr sbp_msg_type_t id = SbpMsgAlmanacGlo;
  static const sbp_msg_almanac_glo_t &get(const sbp_msg_t &msg) {
    return msg.almanac_glo;
  }
  static sbp_msg_almanac_glo_t &get(sbp_msg_t &msg) { return msg.almanac_glo; }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_almanac_glo_t &msg, sbp_write_fn_t write) {
    return sbp_msg_almanac_glo_send(state, sender_id, &msg, write);
  }
};

template <>
struct MessageTraits<sbp_msg_almanac_gps_dep_t> {
  static constexpr sbp_msg_type_t id = SbpMsgAlmanacGpsDep;
  static const sbp_msg_almanac_gps_dep_t &get(const sbp_msg_t &msg) {
    return msg.almanac_gps_dep;
  }
  static sbp_msg_almanac_gps_dep_t &get(sbp_msg_t &msg) {
    return msg.almanac_gps_dep;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_almanac_gps_dep_t &msg, sbp_write_fn_t write) {
    return sbp_msg_almanac_gps_dep_send(state, sender_id, &msg, write);
  }
};

template <>
struct MessageTraits<sbp_msg_almanac_gps_t> {
  static constexpr sbp_msg_type_t id = SbpMsgAlmanacGps;
  static const sbp_msg_almanac_gps_t &get(const sbp_msg_t &msg) {
    return msg.almanac_gps;
  }
  static sbp_msg_almanac_gps_t &get(sbp_msg_t &msg) { return msg.almanac_gps; }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_almanac_gps_t &msg, sbp_write_fn_t write) {
    return sbp_msg_almanac_gps_send(state, sender_id, &msg, write);
  }
};

template <>
struct MessageTraits<sbp_msg_almanac_t> {
  static constexpr sbp_msg_type_t id = SbpMsgAlmanac;
  static const sbp_msg_almanac_t &get(const sbp_msg_t &msg) {
    return msg.almanac;
  }
  static sbp_msg_almanac_t &get(sbp_msg_t &msg) { return msg.almanac; }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_almanac_t &msg, sbp_write_fn_t write) {
    return sbp_msg_almanac_send(state, sender_id, &msg, write);
  }
};

template <>
struct MessageTraits<sbp_msg_angular_rate_t> {
  static constexpr sbp_msg_type_t id = SbpMsgAngularRate;
  static const sbp_msg_angular_rate_t &get(const sbp_msg_t &msg) {
    return msg.angular_rate;
  }
  static sbp_msg_angular_rate_t &get(sbp_msg_t &msg) {
    return msg.angular_rate;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_angular_rate_t &msg, sbp_write_fn_t write) {
    return sbp_msg_angular_rate_send(state, sender_id, &msg, write);
  }
};

template <>
struct MessageTraits<sbp_msg_base_pos_ecef_t> {
  static constexpr sbp_msg_type_t id = SbpMsgBasePosEcef;
  static const sbp_msg_base_pos_ecef_t &get(const sbp_msg_t &msg) {
    return msg.base_pos_ecef;
  }
  static sbp_msg_base_pos_ecef_t &get(sbp_msg_t &msg) {
    return msg.base_pos_ecef;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_base_pos_ecef_t &msg, sbp_write_fn_t write) {
    return sbp_msg_base_pos_ecef_send(state, sender_id, &msg, write);
  }
};

template <>
struct MessageTraits<sbp_msg_base_pos_llh_t> {
  static constexpr sbp_msg_type_t id = SbpMsgBasePosLlh;
  static const sbp_msg_base_pos_llh_t &get(const sbp_msg_t &msg) {
    return msg.base_pos_llh;
  }
  static sbp_msg_base_pos_llh_t &get(sbp_msg_t &msg) {
    return msg.base_pos_llh;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_base_pos_llh_t &msg, sbp_write_fn_t write) {
    return sbp_msg_base_pos_llh_send(state, sender_id, &msg, write);
  }
};

template <>
struct MessageTraits<sbp_msg_baseline_ecef_dep_a_t> {
  static constexpr sbp_msg_type_t id = SbpMsgBaselineEcefDepA;
  static const sbp_msg_baseline_ecef_dep_a_t &get(const sbp_msg_t &msg) {
    return msg.baseline_ecef_dep_a;
  }
  static sbp_msg_baseline_ecef_dep_a_t &get(sbp_msg_t &msg) {
    return msg.baseline_ecef_dep_a;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_baseline_ecef_dep_a_t &msg,
                 sbp_write_fn_t write) {
    return sbp_msg_baseline_ecef_dep_a_send(state, sender_id, &msg, write);
  }
};

template <>
struct MessageTraits<sbp_msg_baseline_ecef_t> {
  static constexpr sbp_msg_type_t id = SbpMsgBaselineEcef;
  static const sbp_msg_baseline_ecef_t &get(const sbp_msg_t &msg) {
    return msg.baseline_ecef;
  }
  static sbp_msg_baseline_ecef_t &get(sbp_msg_t &msg) {
    return msg.baseline_ecef;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_baseline_ecef_t &msg, sbp_write_fn_t write) {
    return sbp_msg_baseline_ecef_send(state, sender_id, &msg, write);
  }
};

template <>
struct MessageTraits<sbp_msg_baseline_heading_dep_a_t> {
  static constexpr sbp_msg_type_t id = SbpMsgBaselineHeadingDepA;
  static const sbp_msg_baseline_heading_dep_a_t &get(const sbp_msg_t &msg) {
    return msg.baseline_heading_dep_a;
  }
  static sbp_msg_baseline_heading_dep_a_t &get(sbp_msg_t &msg) {
    return msg.baseline_heading_dep_a;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_baseline_heading_dep_a_t &msg,
                 sbp_write_fn_t write) {
    return sbp_msg_baseline_heading_dep_a_send(state, sender_id, &msg, write);
  }
};

template <>
struct MessageTraits<sbp_msg_baseline_heading_t> {
  static constexpr sbp_msg_type_t id = SbpMsgBaselineHeading;
  static const sbp_msg_baseline_heading_t &get(const sbp_msg_t &msg) {
    return msg.baseline_heading;
  }
  static sbp_msg_baseline_heading_t &get(sbp_msg_t &msg) {
    return msg.baseline_heading;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_baseline_heading_t &msg, sbp_write_fn_t write) {
    return sbp_msg_baseline_heading_send(state, sender_id, &msg, write);
  }
};

template <>
struct MessageTraits<sbp_msg_baseline_ned_dep_a_t> {
  static constexpr sbp_msg_type_t id = SbpMsgBaselineNedDepA;
  static const sbp_msg_baseline_ned_dep_a_t &get(const sbp_msg_t &msg) {
    return msg.baseline_ned_dep_a;
  }
  static sbp_msg_baseline_ned_dep_a_t &get(sbp_msg_t &msg) {
    return msg.baseline_ned_dep_a;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_baseline_ned_dep_a_t &msg,
                 sbp_write_fn_t write) {
    return sbp_msg_baseline_ned_dep_a_send(state, sender_id, &msg, write);
  }
};

template <>
struct MessageTraits<sbp_msg_baseline_ned_t> {
  static constexpr sbp_msg_type_t id = SbpMsgBaselineNed;
  static const sbp_msg_baseline_ned_t &get(const sbp_msg_t &msg) {
    return msg.baseline_ned;
  }
  static sbp_msg_baseline_ned_t &get(sbp_msg_t &msg) {
    return msg.baseline_ned;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_baseline_ned_t &msg, sbp_write_fn_t write) {
    return sbp_msg_baseline_ned_send(state, sender_id, &msg, write);
  }
};

template <>
struct MessageTraits<sbp_msg_bootloader_handshake_dep_a_t> {
  static constexpr sbp_msg_type_t id = SbpMsgBootloaderHandshakeDepA;
  static const sbp_msg_bootloader_handshake_dep_a_t &get(const sbp_msg_t &msg) {
    return msg.bootloader_handshake_dep_a;
  }
  static sbp_msg_bootloader_handshake_dep_a_t &get(sbp_msg_t &msg) {
    return msg.bootloader_handshake_dep_a;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_bootloader_handshake_dep_a_t &msg,
                 sbp_write_fn_t write) {
    return sbp_msg_bootloader_handshake_dep_a_send(state, sender_id, &msg,
                                                   write);
  }
};

template <>
struct MessageTraits<sbp_msg_bootloader_handshake_req_t> {
  static constexpr sbp_msg_type_t id = SbpMsgBootloaderHandshakeReq;
  static const sbp_msg_bootloader_handshake_req_t &get(const sbp_msg_t &msg) {
    return msg.bootloader_handshake_req;
  }
  static sbp_msg_bootloader_handshake_req_t &get(sbp_msg_t &msg) {
    return msg.bootloader_handshake_req;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_bootloader_handshake_req_t &msg,
                 sbp_write_fn_t write) {
    return sbp_msg_bootloader_handshake_req_send(state, sender_id, &msg, write);
  }
};

template <>
struct MessageTraits<sbp_msg_bootloader_handshake_resp_t> {
  static constexpr sbp_msg_type_t id = SbpMsgBootloaderHandshakeResp;
  static const sbp_msg_bootloader_handshake_resp_t &get(const sbp_msg_t &msg) {
    return msg.bootloader_handshake_resp;
  }
  static sbp_msg_bootloader_handshake_resp_t &get(sbp_msg_t &msg) {
    return msg.bootloader_handshake_resp;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_bootloader_handshake_resp_t &msg,
                 sbp_write_fn_t write) {
    return sbp_msg_bootloader_handshake_resp_send(state, sender_id, &msg,
                                                  write);
  }
};

template <>
struct MessageTraits<sbp_msg_bootloader_jump_to_app_t> {
  static constexpr sbp_msg_type_t id = SbpMsgBootloaderJumpToApp;
  static const sbp_msg_bootloader_jump_to_app_t &get(const sbp_msg_t &msg) {
    return msg.bootloader_jump_to_app;
  }
  static sbp_msg_bootloader_jump_to_app_t &get(sbp_msg_t &msg) {
    return msg.bootloader_jump_to_app;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_bootloader_jump_to_app_t &msg,
                 sbp_write_fn_t write) {
    return sbp_msg_bootloader_jump_to_app_send(state, sender_id, &msg, write);
  }
};

template <>
struct MessageTraits<sbp_msg_cell_modem_status_t> {
  static constexpr sbp_msg_type_t id = SbpMsgCellModemStatus;
  static const sbp_msg_cell_modem_status_t &get(const sbp_msg_t &msg) {
    return msg.cell_modem_status;
  }
  static sbp_msg_cell_modem_status_t &get(sbp_msg_t &msg) {
    return msg.cell_modem_status;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_cell_modem_status_t &msg, sbp_write_fn_t write) {
    return sbp_msg_cell_modem_status_send(state, sender_id, &msg, write);
  }
};

template <>
struct MessageTraits<sbp_msg_command_output_t> {
  static constexpr sbp_msg_type_t id = SbpMsgCommandOutput;
  static const sbp_msg_command_output_t &get(const sbp_msg_t &msg) {
    return msg.command_output;
  }
  static sbp_msg_command_output_t &get(sbp_msg_t &msg) {
    return msg.command_output;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_command_output_t &msg, sbp_write_fn_t write) {
    return sbp_msg_command_output_send(state, sender_id, &msg, write);
  }
};

template <>
struct MessageTraits<sbp_msg_command_req_t> {
  static constexpr sbp_msg_type_t id = SbpMsgCommandReq;
  static const sbp_msg_command_req_t &get(const sbp_msg_t &msg) {
    return msg.command_req;
  }
  static sbp_msg_command_req_t &get(sbp_msg_t &msg) { return msg.command_req; }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_command_req_t &msg, sbp_write_fn_t write) {
    return sbp_msg_command_req_send(state, sender_id, &msg, write);
  }
};

template <>
struct MessageTraits<sbp_msg_command_resp_t> {
  static constexpr sbp_msg_type_t id = SbpMsgCommandResp;
  static const sbp_msg_command_resp_t &get(const sbp_msg_t &msg) {
    return msg.command_resp;
  }
  static sbp_msg_command_resp_t &get(sbp_msg_t &msg) {
    return msg.command_resp;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_command_resp_t &msg, sbp_write_fn_t write) {
    return sbp_msg_command_resp_send(state, sender_id, &msg, write);
  }
};

template <>
struct MessageTraits<sbp_msg_csac_telemetry_labels_t> {
  static constexpr sbp_msg_type_t id = SbpMsgCsacTelemetryLabels;
  static const sbp_msg_csac_telemetry_labels_t &get(const sbp_msg_t &msg) {
    return msg.csac_telemetry_labels;
  }
  static sbp_msg_csac_telemetry_labels_t &get(sbp_msg_t &msg) {
    return msg.csac_telemetry_labels;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_csac_telemetry_labels_t &msg,
                 sbp_write_fn_t write) {
    return sbp_msg_csac_telemetry_labels_send(state, sender_id, &msg, write);
  }
};

template <>
struct MessageTraits<sbp_msg_csac_telemetry_t> {
  static constexpr sbp_msg_type_t id = SbpMsgCsacTelemetry;
  static const sbp_msg_csac_telemetry_t &get(const sbp_msg_t &msg) {
    return msg.csac_telemetry;
  }
  static sbp_msg_csac_telemetry_t &get(sbp_msg_t &msg) {
    return msg.csac_telemetry;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_csac_telemetry_t &msg, sbp_write_fn_t write) {
    return sbp_msg_csac_telemetry_send(state, sender_id, &msg, write);
  }
};

template <>
struct MessageTraits<sbp_msg_cw_results_t> {
  static constexpr sbp_msg_type_t id = SbpMsgCwResults;
  static const sbp_msg_cw_results_t &get(const sbp_msg_t &msg) {
    return msg.cw_results;
  }
  static sbp_msg_cw_results_t &get(sbp_msg_t &msg) { return msg.cw_results; }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_cw_results_t &msg, sbp_write_fn_t write) {
    return sbp_msg_cw_results_send(state, sender_id, &msg, write);
  }
};

template <>
struct MessageTraits<sbp_msg_cw_start_t> {
  static constexpr sbp_msg_type_t id = SbpMsgCwStart;
  static const sbp_msg_cw_start_t &get(const sbp_msg_t &msg) {
    return msg.cw_start;
  }
  static sbp_msg_cw_start_t &get(sbp_msg_t &msg) { return msg.cw_start; }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_cw_start_t &msg, sbp_write_fn_t write) {
    return sbp_msg_cw_start_send(state, sender_id, &msg, write);
  }
};

template <>
struct MessageTraits<sbp_msg_device_monitor_t> {
  static constexpr sbp_msg_type_t id = SbpMsgDeviceMonitor;
  static const sbp_msg_device_monitor_t &get(const sbp_msg_t &msg) {
    return msg.device_monitor;
  }
  static sbp_msg_device_monitor_t &get(sbp_msg_t &msg) {
    return msg.device_monitor;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_device_monitor_t &msg, sbp_write_fn_t write) {
    return sbp_msg_device_monitor_send(state, sender_id, &msg, write);
  }
};

template <>
struct MessageTraits<sbp_msg_dgnss_status_t> {
  static constexpr sbp_msg_type_t id = SbpMsgDgnssStatus;
  static const sbp_msg_dgnss_status_t &get(const sbp_msg_t &msg) {
    return msg.dgnss_status;
  }
  static sbp_msg_dgnss_status_t &get(sbp_msg_t &msg) {
    return msg.dgnss_status;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_dgnss_status_t &msg, sbp_write_fn_t write) {
    return sbp_msg_dgnss_status_send(state, sender_id, &msg, write);
  }
};

template <>
struct MessageTraits<sbp_msg_dops_dep_a_t> {
  static constexpr sbp_msg_type_t id = SbpMsgDopsDepA;
  static const sbp_msg_dops_dep_a_t &get(const sbp_msg_t &msg) {
    return msg.dops_dep_a;
  }
  static sbp_msg_dops_dep_a_t &get(sbp_msg_t &msg) { return msg.dops_dep_a; }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_dops_dep_a_t &msg, sbp_write_fn_t write) {
    return sbp_msg_dops_dep_a_send(state, sender_id, &msg, write);
  }
};

template <>
struct MessageTraits<sbp_msg_dops_t> {
  static constexpr sbp_msg_type_t id = SbpMsgDops;
  static const sbp_msg_dops_t &get(const sbp_msg_t &msg) { return msg.dops; }
  static sbp_msg_dops_t &get(sbp_msg_t &msg) { return msg.dops; }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_dops_t &msg,
                 sbp_write_fn_t write) {
    return sbp_msg_dops_send(state, sender_id, &msg, write);
  }
};

template <>
struct MessageTraits<sbp_msg_ephemeris_bds_t> {
  static constexpr sbp_msg_type_t id = SbpMsgEphemerisBds;
  static const sbp_msg_ephemeris_bds_t &get(const sbp_msg_t &msg) {
    return msg.ephemeris_bds;
  }
  static sbp_msg_ephemeris_bds_t &get(sbp_msg_t &msg) {
    return msg.ephemeris_bds;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_ephemeris_bds_t &msg, sbp_write_fn_t write) {
    return sbp_msg_ephemeris_bds_send(state, sender_id, &msg, write);
  }
};

template <>
struct MessageTraits<sbp_msg_ephemeris_dep_a_t> {
  static constexpr sbp_msg_type_t id = SbpMsgEphemerisDepA;
  static const sbp_msg_ephemeris_dep_a_t &get(const sbp_msg_t &msg) {
    return msg.ephemeris_dep_a;
  }
  static sbp_msg_ephemeris_dep_a_t &get(sbp_msg_t &msg) {
    return msg.ephemeris_dep_a;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_ephemeris_dep_a_t &msg, sbp_write_fn_t write) {
    return sbp_msg_ephemeris_dep_a_send(state, sender_id, &msg, write);
  }
};

template <>
struct MessageTraits<sbp_msg_ephemeris_dep_b_t> {
  static constexpr sbp_msg_type_t id = SbpMsgEphemerisDepB;
  static const sbp_msg_ephemeris_dep_b_t &get(const sbp_msg_t &msg) {
    return msg.ephemeris_dep_b;
  }
  static sbp_msg_ephemeris_dep_b_t &get(sbp_msg_t &msg) {
    return msg.ephemeris_dep_b;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_ephemeris_dep_b_t &msg, sbp_write_fn_t write) {
    return sbp_msg_ephemeris_dep_b_send(state, sender_id, &msg, write);
  }
};

template <>
struct MessageTraits<sbp_msg_ephemeris_dep_c_t> {
  static constexpr sbp_msg_type_t id = SbpMsgEphemerisDepC;
  static const sbp_msg_ephemeris_dep_c_t &get(const sbp_msg_t &msg) {
    return msg.ephemeris_dep_c;
  }
  static sbp_msg_ephemeris_dep_c_t &get(sbp_msg_t &msg) {
    return msg.ephemeris_dep_c;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_ephemeris_dep_c_t &msg, sbp_write_fn_t write) {
    return sbp_msg_ephemeris_dep_c_send(state, sender_id, &msg, write);
  }
};

template <>
struct MessageTraits<sbp_msg_ephemeris_dep_d_t> {
  static constexpr sbp_msg_type_t id = SbpMsgEphemerisDepD;
  static const sbp_msg_ephemeris_dep_d_t &get(const sbp_msg_t &msg) {
    return msg.ephemeris_dep_d;
  }
  static sbp_msg_ephemeris_dep_d_t &get(sbp_msg_t &msg) {
    return msg.ephemeris_dep_d;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_ephemeris_dep_d_t &msg, sbp_write_fn_t write) {
    return sbp_msg_ephemeris_dep_d_send(state, sender_id, &msg, write);
  }
};

template <>
struct MessageTraits<sbp_msg_ephemeris_gal_dep_a_t> {
  static constexpr sbp_msg_type_t id = SbpMsgEphemerisGalDepA;
  static const sbp_msg_ephemeris_gal_dep_a_t &get(const sbp_msg_t &msg) {
    return msg.ephemeris_gal_dep_a;
  }
  static sbp_msg_ephemeris_gal_dep_a_t &get(sbp_msg_t &msg) {
    return msg.ephemeris_gal_dep_a;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_ephemeris_gal_dep_a_t &msg,
                 sbp_write_fn_t write) {
    return sbp_msg_ephemeris_gal_dep_a_send(state, sender_id, &msg, write);
  }
};

template <>
struct MessageTraits<sbp_msg_ephemeris_gal_t> {
  static constexpr sbp_msg_type_t id = SbpMsgEphemerisGal;
  static const sbp_msg_ephemeris_gal_t &get(const sbp_msg_t &msg) {
    return msg.ephemeris_gal;
  }
  static sbp_msg_ephemeris_gal_t &get(sbp_msg_t &msg) {
    return msg.ephemeris_gal;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_ephemeris_gal_t &msg, sbp_write_fn_t write) {
    return sbp_msg_ephemeris_gal_send(state, sender_id, &msg, write);
  }
};

template <>
struct MessageTraits<sbp_msg_ephemeris_glo_dep_a_t> {
  static constexpr sbp_msg_type_t id = SbpMsgEphemerisGloDepA;
  static const sbp_msg_ephemeris_glo_dep_a_t &get(const sbp_msg_t &msg) {
    return msg.ephemeris_glo_dep_a;
  }
  static sbp_msg_ephemeris_glo_dep_a_t &get(sbp_msg_t &msg) {
    return msg.ephemeris_glo_dep_a;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_ephemeris_glo_dep_a_t &msg,
                 sbp_write_fn_t write) {
    return sbp_msg_ephemeris_glo_dep_a_send(state, sender_id, &msg, write);
  }
};

template <>
struct MessageTraits<sbp_msg_ephemeris_glo_dep_b_t> {
  static constexpr sbp_msg_type_t id = SbpMsgEphemerisGloDepB;
  static const sbp_msg_ephemeris_glo_dep_b_t &get(const sbp_msg_t &msg) {
    return msg.ephemeris_glo_dep_b;
  }
  static sbp_msg_ephemeris_glo_dep_b_t &get(sbp_msg_t &msg) {
    return msg.ephemeris_glo_dep_b;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_ephemeris_glo_dep_b_t &msg,
                 sbp_write_fn_t write) {
    return sbp_msg_ephemeris_glo_dep_b_send(state, sender_id, &msg, write);
  }
};

template <>
struct MessageTraits<sbp_msg_ephemeris_glo_dep_c_t> {
  static constexpr sbp_msg_type_t id = SbpMsgEphemerisGloDepC;
  static const sbp_msg_ephemeris_glo_dep_c_t &get(const sbp_msg_t &msg) {
    return msg.ephemeris_glo_dep_c;
  }
  static sbp_msg_ephemeris_glo_dep_c_t &get(sbp_msg_t &msg) {
    return msg.ephemeris_glo_dep_c;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_ephemeris_glo_dep_c_t &msg,
                 sbp_write_fn_t write) {
    return sbp_msg_ephemeris_glo_dep_c_send(state, sender_id, &msg, write);
  }
};

template <>
struct MessageTraits<sbp_msg_ephemeris_glo_dep_d_t> {
  static constexpr sbp_msg_type_t id = SbpMsgEphemerisGloDepD;
  static const sbp_msg_ephemeris_glo_dep_d_t &get(const sbp_msg_t &msg) {
    return msg.ephemeris_glo_dep_d;
  }
  static sbp_msg_ephemeris_glo_dep_d_t &get(sbp_msg_t &msg) {
    return msg.ephemeris_glo_dep_d;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_ephemeris_glo_dep_d_t &msg,
                 sbp_write_fn_t write) {
    return sbp_msg_ephemeris_glo_dep_d_send(state, sender_id, &msg, write);
  }
};

template <>
struct MessageTraits<sbp_msg_ephemeris_glo_t> {
  static constexpr sbp_msg_type_t id = SbpMsgEphemerisGlo;
  static const sbp_msg_ephemeris_glo_t &get(const sbp_msg_t &msg) {
    return msg.ephemeris_glo;
  }
  static sbp_msg_ephemeris_glo_t &get(sbp_msg_t &msg) {
    return msg.ephemeris_glo;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_ephemeris_glo_t &msg, sbp_write_fn_t write) {
    return sbp_msg_ephemeris_glo_send(state, sender_id, &msg, write);
  }
};

template <>
struct MessageTraits<sbp_msg_ephemeris_gps_dep_e_t> {
  static constexpr sbp_msg_type_t id = SbpMsgEphemerisGpsDepE;
  static const sbp_msg_ephemeris_gps_dep_e_t &get(const sbp_msg_t &msg) {
    return msg.ephemeris_gps_dep_e;
  }
  static sbp_msg_ephemeris_gps_dep_e_t &get(sbp_msg_t &msg) {
    return msg.ephemeris_gps_dep_e;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_ephemeris_gps_dep_e_t &msg,
                 sbp_write_fn_t write) {
    return sbp_msg_ephemeris_gps_dep_e_send(state, sender_id, &msg, write);
  }
};

template <>
struct MessageTraits<sbp_msg_ephemeris_gps_dep_f_t> {
  static constexpr sbp_msg_type_t id = SbpMsgEphemerisGpsDepF;
  static const sbp_msg_ephemeris_gps_dep_f_t &get(const sbp_msg_t &msg) {
    return msg.ephemeris_gps_dep_f;
  }
  static sbp_msg_ephemeris_gps_dep_f_t &get(sbp_msg_t &msg) {
    return msg.ephemeris_gps_dep_f;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_ephemeris_gps_dep_f_t &msg,
                 sbp_write_fn_t write) {
    return sbp_msg_ephemeris_gps_dep_f_send(state, sender_id, &msg, write);
  }
};

template <>
struct MessageTraits<sbp_msg_ephemeris_gps_t> {
  static constexpr sbp_msg_type_t id = SbpMsgEphemerisGps;
  static const sbp_msg_ephemeris_gps_t &get(const sbp_msg_t &msg) {
    return msg.ephemeris_gps;
  }
  static sbp_msg_ephemeris_gps_t &get(sbp_msg_t &msg) {
    return msg.ephemeris_gps;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_ephemeris_gps_t &msg, sbp_write_fn_t write) {
    return sbp_msg_ephemeris_gps_send(state, sender_id, &msg, write);
  }
};

template <>
struct MessageTraits<sbp_msg_ephemeris_qzss_t> {
  static constexpr sbp_msg_type_t id = SbpMsgEphemerisQzss;
  static const sbp_msg_ephemeris_qzss_t &get(const sbp_msg_t &msg) {
    return msg.ephemeris_qzss;
  }
  static sbp_msg_ephemeris_qzss_t &get(sbp_msg_t &msg) {
    return msg.ephemeris_qzss;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_ephemeris_qzss_t &msg, sbp_write_fn_t write) {
    return sbp_msg_ephemeris_qzss_send(state, sender_id, &msg, write);
  }
};

template <>
struct MessageTraits<sbp_msg_ephemeris_sbas_dep_a_t> {
  static constexpr sbp_msg_type_t id = SbpMsgEphemerisSbasDepA;
  static const sbp_msg_ephemeris_sbas_dep_a_t &get(const sbp_msg_t &msg) {
    return msg.ephemeris_sbas_dep_a;
  }
  static sbp_msg_ephemeris_sbas_dep_a_t &get(sbp_msg_t &msg) {
    return msg.ephemeris_sbas_dep_a;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_ephemeris_sbas_dep_a_t &msg,
                 sbp_write_fn_t write) {
    return sbp_msg_ephemeris_sbas_dep_a_send(state, sender_id, &msg, write);
  }
};

template <>
struct MessageTraits<sbp_msg_ephemeris_sbas_dep_b_t> {
  static constexpr sbp_msg_type_t id = SbpMsgEphemerisSbasDepB;
  static const sbp_msg_ephemeris_sbas_dep_b_t &get(const sbp_msg_t &msg) {
    return msg.ephemeris_sbas_dep_b;
  }
  static sbp_msg_ephemeris_sbas_dep_b_t &get(sbp_msg_t &msg) {
    return msg.ephemeris_sbas_dep_b;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_ephemeris_sbas_dep_b_t &msg,
                 sbp_write_fn_t write) {
    return sbp_msg_ephemeris_sbas_dep_b_send(state, sender_id, &msg, write);
  }
};

template <>
struct MessageTraits<sbp_msg_ephemeris_sbas_t> {
  static constexpr sbp_msg_type_t id = SbpMsgEphemerisSbas;
  static const sbp_msg_ephemeris_sbas_t &get(const sbp_msg_t &msg) {
    return msg.ephemeris_sbas;
  }
  static sbp_msg_ephemeris_sbas_t &get(sbp_msg_t &msg) {
    return msg.ephemeris_sbas;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_ephemeris_sbas_t &msg, sbp_write_fn_t write) {
    return sbp_msg_ephemeris_sbas_send(state, sender_id, &msg, write);
  }
};

template <>
struct MessageTraits<sbp_msg_ext_event_t> {
  static constexpr sbp_msg_type_t id = SbpMsgExtEvent;
  static const sbp_msg_ext_event_t &get(const sbp_msg_t &msg) {
    return msg.ext_event;
  }
  static sbp_msg_ext_event_t &get(sbp_msg_t &msg) { return msg.ext_event; }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_ext_event_t &msg, sbp_write_fn_t write) {
    return sbp_msg_ext_event_send(state, sender_id, &msg, write);
  }
};

template <>
struct MessageTraits<sbp_msg_fileio_config_req_t> {
  static constexpr sbp_msg_type_t id = SbpMsgFileioConfigReq;
  static const sbp_msg_fileio_config_req_t &get(const sbp_msg_t &msg) {
    return msg.fileio_config_req;
  }
  static sbp_msg_fileio_config_req_t &get(sbp_msg_t &msg) {
    return msg.fileio_config_req;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_fileio_config_req_t &msg, sbp_write_fn_t write) {
    return sbp_msg_fileio_config_req_send(state, sender_id, &msg, write);
  }
};

template <>
struct MessageTraits<sbp_msg_fileio_config_resp_t> {
  static constexpr sbp_msg_type_t id = SbpMsgFileioConfigResp;
  static const sbp_msg_fileio_config_resp_t &get(const sbp_msg_t &msg) {
    return msg.fileio_config_resp;
  }
  static sbp_msg_fileio_config_resp_t &get(sbp_msg_t &msg) {
    return msg.fileio_config_resp;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_fileio_config_resp_t &msg,
                 sbp_write_fn_t write) {
    return sbp_msg_fileio_config_resp_send(state, sender_id, &msg, write);
  }
};

template <>
struct MessageTraits<sbp_msg_fileio_read_dir_req_t> {
  static constexpr sbp_msg_type_t id = SbpMsgFileioReadDirReq;
  static const sbp_msg_fileio_read_dir_req_t &get(const sbp_msg_t &msg) {
    return msg.fileio_read_dir_req;
  }
  static sbp_msg_fileio_read_dir_req_t &get(sbp_msg_t &msg) {
    return msg.fileio_read_dir_req;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_fileio_read_dir_req_t &msg,
                 sbp_write_fn_t write) {
    return sbp_msg_fileio_read_dir_req_send(state, sender_id, &msg, write);
  }
};

template <>
struct MessageTraits<sbp_msg_fileio_read_dir_resp_t> {
  static constexpr sbp_msg_type_t id = SbpMsgFileioReadDirResp;
  static const sbp_msg_fileio_read_dir_resp_t &get(const sbp_msg_t &msg) {
    return msg.fileio_read_dir_resp;
  }
  static sbp_msg_fileio_read_dir_resp_t &get(sbp_msg_t &msg) {
    return msg.fileio_read_dir_resp;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_fileio_read_dir_resp_t &msg,
                 sbp_write_fn_t write) {
    return sbp_msg_fileio_read_dir_resp_send(state, sender_id, &msg, write);
  }
};

template <>
struct MessageTraits<sbp_msg_fileio_read_req_t> {
  static constexpr sbp_msg_type_t id = SbpMsgFileioReadReq;
  static const sbp_msg_fileio_read_req_t &get(const sbp_msg_t &msg) {
    return msg.fileio_read_req;
  }
  static sbp_msg_fileio_read_req_t &get(sbp_msg_t &msg) {
    return msg.fileio_read_req;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_fileio_read_req_t &msg, sbp_write_fn_t write) {
    return sbp_msg_fileio_read_req_send(state, sender_id, &msg, write);
  }
};

template <>
struct MessageTraits<sbp_msg_fileio_read_resp_t> {
  static constexpr sbp_msg_type_t id = SbpMsgFileioReadResp;
  static const sbp_msg_fileio_read_resp_t &get(const sbp_msg_t &msg) {
    return msg.fileio_read_resp;
  }
  static sbp_msg_fileio_read_resp_t &get(sbp_msg_t &msg) {
    return msg.fileio_read_resp;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_fileio_read_resp_t &msg, sbp_write_fn_t write) {
    return sbp_msg_fileio_read_resp_send(state, sender_id, &msg, write);
  }
};

template <>
struct MessageTraits<sbp_msg_fileio_remove_t> {
  static constexpr sbp_msg_type_t id = SbpMsgFileioRemove;
  static const sbp_msg_fileio_remove_t &get(const sbp_msg_t &msg) {
    return msg.fileio_remove;
  }
  static sbp_msg_fileio_remove_t &get(sbp_msg_t &msg) {
    return msg.fileio_remove;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_fileio_remove_t &msg, sbp_write_fn_t write) {
    return sbp_msg_fileio_remove_send(state, sender_id, &msg, write);
  }
};

template <>
struct MessageTraits<sbp_msg_fileio_write_req_t> {
  static constexpr sbp_msg_type_t id = SbpMsgFileioWriteReq;
  static const sbp_msg_fileio_write_req_t &get(const sbp_msg_t &msg) {
    return msg.fileio_write_req;
  }
  static sbp_msg_fileio_write_req_t &get(sbp_msg_t &msg) {
    return msg.fileio_write_req;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_fileio_write_req_t &msg, sbp_write_fn_t write) {
    return sbp_msg_fileio_write_req_send(state, sender_id, &msg, write);
  }
};

template <>
struct MessageTraits<sbp_msg_fileio_write_resp_t> {
  static constexpr sbp_msg_type_t id = SbpMsgFileioWriteResp;
  static const sbp_msg_fileio_write_resp_t &get(const sbp_msg_t &msg) {
    return msg.fileio_write_resp;
  }
  static sbp_msg_fileio_write_resp_t &get(sbp_msg_t &msg) {
    return msg.fileio_write_resp;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_fileio_write_resp_t &msg, sbp_write_fn_t write) {
    return sbp_msg_fileio_write_resp_send(state, sender_id, &msg, write);
  }
};

template <>
struct MessageTraits<sbp_msg_flash_done_t> {
  static constexpr sbp_msg_type_t id = SbpMsgFlashDone;
  static const sbp_msg_flash_done_t &get(const sbp_msg_t &msg) {
    return msg.flash_done;
  }
  static sbp_msg_flash_done_t &get(sbp_msg_t &msg) { return msg.flash_done; }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_flash_done_t &msg, sbp_write_fn_t write) {
    return sbp_msg_flash_done_send(state, sender_id, &msg, write);
  }
};

template <>
struct MessageTraits<sbp_msg_flash_erase_t> {
  static constexpr sbp_msg_type_t id = SbpMsgFlashErase;
  static const sbp_msg_flash_erase_t &get(const sbp_msg_t &msg) {
    return msg.flash_erase;
  }
  static sbp_msg_flash_erase_t &get(sbp_msg_t &msg) { return msg.flash_erase; }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_flash_erase_t &msg, sbp_write_fn_t write) {
    return sbp_msg_flash_erase_send(state, sender_id, &msg, write);
  }
};

template <>
struct MessageTraits<sbp_msg_flash_program_t> {
  static constexpr sbp_msg_type_t id = SbpMsgFlashProgram;
  static const sbp_msg_flash_program_t &get(const sbp_msg_t &msg) {
    return msg.flash_program;
  }
  static sbp_msg_flash_program_t &get(sbp_msg_t &msg) {
    return msg.flash_program;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_flash_program_t &msg, sbp_write_fn_t write) {
    return sbp_msg_flash_program_send(state, sender_id, &msg, write);
  }
};

template <>
struct MessageTraits<sbp_msg_flash_read_req_t> {
  static constexpr sbp_msg_type_t id = SbpMsgFlashReadReq;
  static const sbp_msg_flash_read_req_t &get(const sbp_msg_t &msg) {
    return msg.flash_read_req;
  }
  static sbp_msg_flash_read_req_t &get(sbp_msg_t &msg) {
    return msg.flash_read_req;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_flash_read_req_t &msg, sbp_write_fn_t write) {
    return sbp_msg_flash_read_req_send(state, sender_id, &msg, write);
  }
};

template <>
struct MessageTraits<sbp_msg_flash_read_resp_t> {
  static constexpr sbp_msg_type_t id = SbpMsgFlashReadResp;
  static const sbp_msg_flash_read_resp_t &get(const sbp_msg_t &msg) {
    return msg.flash_read_resp;
  }
  static sbp_msg_flash_read_resp_t &get(sbp_msg_t &msg) {
    return msg.flash_read_resp;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_flash_read_resp_t &msg, sbp_write_fn_t write) {
    return sbp_msg_flash_read_resp_send(state, sender_id, &msg, write);
  }
};

template <>
struct MessageTraits<sbp_msg_front_end_gain_t> {
  static constexpr sbp_msg_type_t id = SbpMsgFrontEndGain;
  static const sbp_msg_front_end_gain_t &get(const sbp_msg_t &msg) {
    return msg.front_end_gain;
  }
  static sbp_msg_front_end_gain_t &get(sbp_msg_t &msg) {
    return msg.front_end_gain;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_front_end_gain_t &msg, sbp_write_fn_t write) {
    return sbp_msg_front_end_gain_send(state, sender_id, &msg, write);
  }
};

template <>
struct MessageTraits<sbp_msg_fwd_t> {
  static constexpr sbp_msg_type_t id = SbpMsgFwd;
  static const sbp_msg_fwd_t &get(const sbp_msg_t &msg) { return msg.fwd; }
  static sbp_msg_fwd_t &get(sbp_msg_t &msg) { return msg.fwd; }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_fwd_t &msg,
                 sbp_write_fn_t write) {
    return sbp_msg_fwd_send(state, sender_id, &msg, write);
  }
};

template <>
struct MessageTraits<sbp_msg_glo_biases_t> {
  static constexpr sbp_msg_type_t id = SbpMsgGloBiases;
  static const sbp_msg_glo_biases_t &get(const sbp_msg_t &msg) {
    return msg.glo_biases;
  }
  static sbp_msg_glo_biases_t &get(sbp_msg_t &msg) { return msg.glo_biases; }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_glo_biases_t &msg, sbp_write_fn_t write) {
    return sbp_msg_glo_biases_send(state, sender_id, &msg, write);
  }
};

template <>
struct MessageTraits<sbp_msg_gnss_capb_t> {
  static constexpr sbp_msg_type_t id = SbpMsgGnssCapb;
  static const sbp_msg_gnss_capb_t &get(const sbp_msg_t &msg) {
    return msg.gnss_capb;
  }
  static sbp_msg_gnss_capb_t &get(sbp_msg_t &msg) { return msg.gnss_capb; }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_gnss_capb_t &msg, sbp_write_fn_t write) {
    return sbp_msg_gnss_capb_send(state, sender_id, &msg, write);
  }
};

template <>
struct MessageTraits<sbp_msg_gnss_time_offset_t> {
  static constexpr sbp_msg_type_t id = SbpMsgGnssTimeOffset;
  static const sbp_msg_gnss_time_offset_t &get(const sbp_msg_t &msg) {
    return msg.gnss_time_offset;
  }
  static sbp_msg_gnss_time_offset_t &get(sbp_msg_t &msg) {
    return msg.gnss_time_offset;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_gnss_time_offset_t &msg, sbp_write_fn_t write) {
    return sbp_msg_gnss_time_offset_send(state, sender_id, &msg, write);
  }
};

template <>
struct MessageTraits<sbp_msg_gps_time_dep_a_t> {
  static constexpr sbp_msg_type_t id = SbpMsgGpsTimeDepA;
  static const sbp_msg_gps_time_dep_a_t &get(const sbp_msg_t &msg) {
    return msg.gps_time_dep_a;
  }
  static sbp_msg_gps_time_dep_a_t &get(sbp_msg_t &msg) {
    return msg.gps_time_dep_a;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_gps_time_dep_a_t &msg, sbp_write_fn_t write) {
    return sbp_msg_gps_time_dep_a_send(state, sender_id, &msg, write);
  }
};

template <>
struct MessageTraits<sbp_msg_gps_time_gnss_t> {
  static constexpr sbp_msg_type_t id = SbpMsgGpsTimeGnss;
  static const sbp_msg_gps_time_gnss_t &get(const sbp_msg_t &msg) {
    return msg.gps_time_gnss;
  }
  static sbp_msg_gps_time_gnss_t &get(sbp_msg_t &msg) {
    return msg.gps_time_gnss;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_gps_time_gnss_t &msg, sbp_write_fn_t write) {
    return sbp_msg_gps_time_gnss_send(state, sender_id, &msg, write);
  }
};

template <>
struct MessageTraits<sbp_msg_gps_time_t> {
  static constexpr sbp_msg_type_t id = SbpMsgGpsTime;
  static const sbp_msg_gps_time_t &get(const sbp_msg_t &msg) {
    return msg.gps_time;
  }
  static sbp_msg_gps_time_t &get(sbp_msg_t &msg) { return msg.gps_time; }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_gps_time_t &msg, sbp_write_fn_t write) {
    return sbp_msg_gps_time_send(state, sender_id, &msg, write);
  }
};

template <>
struct MessageTraits<sbp_msg_group_delay_dep_a_t> {
  static constexpr sbp_msg_type_t id = SbpMsgGroupDelayDepA;
  static const sbp_msg_group_delay_dep_a_t &get(const sbp_msg_t &msg) {
    return msg.group_delay_dep_a;
  }
  static sbp_msg_group_delay_dep_a_t &get(sbp_msg_t &msg) {
    return msg.group_delay_dep_a;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_group_delay_dep_a_t &msg, sbp_write_fn_t write) {
    return sbp_msg_group_delay_dep_a_send(state, sender_id, &msg, write);
  }
};

template <>
struct MessageTraits<sbp_msg_group_delay_dep_b_t> {
  static constexpr sbp_msg_type_t id = SbpMsgGroupDelayDepB;
  static const sbp_msg_group_delay_dep_b_t &get(const sbp_msg_t &msg) {
    return msg.group_delay_dep_b;
  }
  static sbp_msg_group_delay_dep_b_t &get(sbp_msg_t &msg) {
    return msg.group_delay_dep_b;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_group_delay_dep_b_t &msg, sbp_write_fn_t write) {
    return sbp_msg_group_delay_dep_b_send(state, sender_id, &msg, write);
  }
};

template <>
struct MessageTraits<sbp_msg_group_delay_t> {
  static constexpr sbp_msg_type_t id = SbpMsgGroupDelay;
  static const sbp_msg_group_delay_t &get(const sbp_msg_t &msg) {
    return msg.group_delay;
  }
  static sbp_msg_group_delay_t &get(sbp_msg_t &msg) { return msg.group_delay; }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_group_delay_t &msg, sbp_write_fn_t write) {
    return sbp_msg_group_delay_send(state, sender_id, &msg, write);
  }
};

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
struct MessageTraits<sbp_msg_heartbeat_t> {
  static constexpr sbp_msg_type_t id = SbpMsgHeartbeat;
  static const sbp_msg_heartbeat_t &get(const sbp_msg_t &msg) {
    return msg.heartbeat;
  }
  static sbp_msg_heartbeat_t &get(sbp_msg_t &msg) { return msg.heartbeat; }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_heartbeat_t &msg, sbp_write_fn_t write) {
    return sbp_msg_heartbeat_send(state, sender_id, &msg, write);
  }
};

template <>
struct MessageTraits<sbp_msg_iar_state_t> {
  static constexpr sbp_msg_type_t id = SbpMsgIarState;
  static const sbp_msg_iar_state_t &get(const sbp_msg_t &msg) {
    return msg.iar_state;
  }
  static sbp_msg_iar_state_t &get(sbp_msg_t &msg) { return msg.iar_state; }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_iar_state_t &msg, sbp_write_fn_t write) {
    return sbp_msg_iar_state_send(state, sender_id, &msg, write);
  }
};

template <>
struct MessageTraits<sbp_msg_imu_aux_t> {
  static constexpr sbp_msg_type_t id = SbpMsgImuAux;
  static const sbp_msg_imu_aux_t &get(const sbp_msg_t &msg) {
    return msg.imu_aux;
  }
  static sbp_msg_imu_aux_t &get(sbp_msg_t &msg) { return msg.imu_aux; }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_imu_aux_t &msg, sbp_write_fn_t write) {
    return sbp_msg_imu_aux_send(state, sender_id, &msg, write);
  }
};

template <>
struct MessageTraits<sbp_msg_imu_raw_t> {
  static constexpr sbp_msg_type_t id = SbpMsgImuRaw;
  static const sbp_msg_imu_raw_t &get(const sbp_msg_t &msg) {
    return msg.imu_raw;
  }
  static sbp_msg_imu_raw_t &get(sbp_msg_t &msg) { return msg.imu_raw; }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_imu_raw_t &msg, sbp_write_fn_t write) {
    return sbp_msg_imu_raw_send(state, sender_id, &msg, write);
  }
};

template <>
struct MessageTraits<sbp_msg_init_base_dep_t> {
  static constexpr sbp_msg_type_t id = SbpMsgInitBaseDep;
  static const sbp_msg_init_base_dep_t &get(const sbp_msg_t &msg) {
    return msg.init_base_dep;
  }
  static sbp_msg_init_base_dep_t &get(sbp_msg_t &msg) {
    return msg.init_base_dep;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_init_base_dep_t &msg, sbp_write_fn_t write) {
    return sbp_msg_init_base_dep_send(state, sender_id, &msg, write);
  }
};

template <>
struct MessageTraits<sbp_msg_ins_status_t> {
  static constexpr sbp_msg_type_t id = SbpMsgInsStatus;
  static const sbp_msg_ins_status_t &get(const sbp_msg_t &msg) {
    return msg.ins_status;
  }
  static sbp_msg_ins_status_t &get(sbp_msg_t &msg) { return msg.ins_status; }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_ins_status_t &msg, sbp_write_fn_t write) {
    return sbp_msg_ins_status_send(state, sender_id, &msg, write);
  }
};

template <>
struct MessageTraits<sbp_msg_ins_updates_t> {
  static constexpr sbp_msg_type_t id = SbpMsgInsUpdates;
  static const sbp_msg_ins_updates_t &get(const sbp_msg_t &msg) {
    return msg.ins_updates;
  }
  static sbp_msg_ins_updates_t &get(sbp_msg_t &msg) { return msg.ins_updates; }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_ins_updates_t &msg, sbp_write_fn_t write) {
    return sbp_msg_ins_updates_send(state, sender_id, &msg, write);
  }
};

template <>
struct MessageTraits<sbp_msg_iono_t> {
  static constexpr sbp_msg_type_t id = SbpMsgIono;
  static const sbp_msg_iono_t &get(const sbp_msg_t &msg) { return msg.iono; }
  static sbp_msg_iono_t &get(sbp_msg_t &msg) { return msg.iono; }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_iono_t &msg,
                 sbp_write_fn_t write) {
    return sbp_msg_iono_send(state, sender_id, &msg, write);
  }
};

template <>
struct MessageTraits<sbp_msg_linux_cpu_state_dep_a_t> {
  static constexpr sbp_msg_type_t id = SbpMsgLinuxCpuStateDepA;
  static const sbp_msg_linux_cpu_state_dep_a_t &get(const sbp_msg_t &msg) {
    return msg.linux_cpu_state_dep_a;
  }
  static sbp_msg_linux_cpu_state_dep_a_t &get(sbp_msg_t &msg) {
    return msg.linux_cpu_state_dep_a;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_linux_cpu_state_dep_a_t &msg,
                 sbp_write_fn_t write) {
    return sbp_msg_linux_cpu_state_dep_a_send(state, sender_id, &msg, write);
  }
};

template <>
struct MessageTraits<sbp_msg_linux_cpu_state_t> {
  static constexpr sbp_msg_type_t id = SbpMsgLinuxCpuState;
  static const sbp_msg_linux_cpu_state_t &get(const sbp_msg_t &msg) {
    return msg.linux_cpu_state;
  }
  static sbp_msg_linux_cpu_state_t &get(sbp_msg_t &msg) {
    return msg.linux_cpu_state;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_linux_cpu_state_t &msg, sbp_write_fn_t write) {
    return sbp_msg_linux_cpu_state_send(state, sender_id, &msg, write);
  }
};

template <>
struct MessageTraits<sbp_msg_linux_mem_state_dep_a_t> {
  static constexpr sbp_msg_type_t id = SbpMsgLinuxMemStateDepA;
  static const sbp_msg_linux_mem_state_dep_a_t &get(const sbp_msg_t &msg) {
    return msg.linux_mem_state_dep_a;
  }
  static sbp_msg_linux_mem_state_dep_a_t &get(sbp_msg_t &msg) {
    return msg.linux_mem_state_dep_a;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_linux_mem_state_dep_a_t &msg,
                 sbp_write_fn_t write) {
    return sbp_msg_linux_mem_state_dep_a_send(state, sender_id, &msg, write);
  }
};

template <>
struct MessageTraits<sbp_msg_linux_mem_state_t> {
  static constexpr sbp_msg_type_t id = SbpMsgLinuxMemState;
  static const sbp_msg_linux_mem_state_t &get(const sbp_msg_t &msg) {
    return msg.linux_mem_state;
  }
  static sbp_msg_linux_mem_state_t &get(sbp_msg_t &msg) {
    return msg.linux_mem_state;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_linux_mem_state_t &msg, sbp_write_fn_t write) {
    return sbp_msg_linux_mem_state_send(state, sender_id, &msg, write);
  }
};

template <>
struct MessageTraits<sbp_msg_linux_process_fd_count_t> {
  static constexpr sbp_msg_type_t id = SbpMsgLinuxProcessFdCount;
  static const sbp_msg_linux_process_fd_count_t &get(const sbp_msg_t &msg) {
    return msg.linux_process_fd_count;
  }
  static sbp_msg_linux_process_fd_count_t &get(sbp_msg_t &msg) {
    return msg.linux_process_fd_count;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_linux_process_fd_count_t &msg,
                 sbp_write_fn_t write) {
    return sbp_msg_linux_process_fd_count_send(state, sender_id, &msg, write);
  }
};

template <>
struct MessageTraits<sbp_msg_linux_process_fd_summary_t> {
  static constexpr sbp_msg_type_t id = SbpMsgLinuxProcessFdSummary;
  static const sbp_msg_linux_process_fd_summary_t &get(const sbp_msg_t &msg) {
    return msg.linux_process_fd_summary;
  }
  static sbp_msg_linux_process_fd_summary_t &get(sbp_msg_t &msg) {
    return msg.linux_process_fd_summary;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_linux_process_fd_summary_t &msg,
                 sbp_write_fn_t write) {
    return sbp_msg_linux_process_fd_summary_send(state, sender_id, &msg, write);
  }
};

template <>
struct MessageTraits<sbp_msg_linux_process_socket_counts_t> {
  static constexpr sbp_msg_type_t id = SbpMsgLinuxProcessSocketCounts;
  static const sbp_msg_linux_process_socket_counts_t &get(
      const sbp_msg_t &msg) {
    return msg.linux_process_socket_counts;
  }
  static sbp_msg_linux_process_socket_counts_t &get(sbp_msg_t &msg) {
    return msg.linux_process_socket_counts;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_linux_process_socket_counts_t &msg,
                 sbp_write_fn_t write) {
    return sbp_msg_linux_process_socket_counts_send(state, sender_id, &msg,
                                                    write);
  }
};

template <>
struct MessageTraits<sbp_msg_linux_process_socket_queues_t> {
  static constexpr sbp_msg_type_t id = SbpMsgLinuxProcessSocketQueues;
  static const sbp_msg_linux_process_socket_queues_t &get(
      const sbp_msg_t &msg) {
    return msg.linux_process_socket_queues;
  }
  static sbp_msg_linux_process_socket_queues_t &get(sbp_msg_t &msg) {
    return msg.linux_process_socket_queues;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_linux_process_socket_queues_t &msg,
                 sbp_write_fn_t write) {
    return sbp_msg_linux_process_socket_queues_send(state, sender_id, &msg,
                                                    write);
  }
};

template <>
struct MessageTraits<sbp_msg_linux_socket_usage_t> {
  static constexpr sbp_msg_type_t id = SbpMsgLinuxSocketUsage;
  static const sbp_msg_linux_socket_usage_t &get(const sbp_msg_t &msg) {
    return msg.linux_socket_usage;
  }
  static sbp_msg_linux_socket_usage_t &get(sbp_msg_t &msg) {
    return msg.linux_socket_usage;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_linux_socket_usage_t &msg,
                 sbp_write_fn_t write) {
    return sbp_msg_linux_socket_usage_send(state, sender_id, &msg, write);
  }
};

template <>
struct MessageTraits<sbp_msg_linux_sys_state_dep_a_t> {
  static constexpr sbp_msg_type_t id = SbpMsgLinuxSysStateDepA;
  static const sbp_msg_linux_sys_state_dep_a_t &get(const sbp_msg_t &msg) {
    return msg.linux_sys_state_dep_a;
  }
  static sbp_msg_linux_sys_state_dep_a_t &get(sbp_msg_t &msg) {
    return msg.linux_sys_state_dep_a;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_linux_sys_state_dep_a_t &msg,
                 sbp_write_fn_t write) {
    return sbp_msg_linux_sys_state_dep_a_send(state, sender_id, &msg, write);
  }
};

template <>
struct MessageTraits<sbp_msg_linux_sys_state_t> {
  static constexpr sbp_msg_type_t id = SbpMsgLinuxSysState;
  static const sbp_msg_linux_sys_state_t &get(const sbp_msg_t &msg) {
    return msg.linux_sys_state;
  }
  static sbp_msg_linux_sys_state_t &get(sbp_msg_t &msg) {
    return msg.linux_sys_state;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_linux_sys_state_t &msg, sbp_write_fn_t write) {
    return sbp_msg_linux_sys_state_send(state, sender_id, &msg, write);
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
struct MessageTraits<sbp_msg_m25_flash_write_status_t> {
  static constexpr sbp_msg_type_t id = SbpMsgM25FlashWriteStatus;
  static const sbp_msg_m25_flash_write_status_t &get(const sbp_msg_t &msg) {
    return msg.m25_flash_write_status;
  }
  static sbp_msg_m25_flash_write_status_t &get(sbp_msg_t &msg) {
    return msg.m25_flash_write_status;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_m25_flash_write_status_t &msg,
                 sbp_write_fn_t write) {
    return sbp_msg_m25_flash_write_status_send(state, sender_id, &msg, write);
  }
};

template <>
struct MessageTraits<sbp_msg_mag_raw_t> {
  static constexpr sbp_msg_type_t id = SbpMsgMagRaw;
  static const sbp_msg_mag_raw_t &get(const sbp_msg_t &msg) {
    return msg.mag_raw;
  }
  static sbp_msg_mag_raw_t &get(sbp_msg_t &msg) { return msg.mag_raw; }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_mag_raw_t &msg, sbp_write_fn_t write) {
    return sbp_msg_mag_raw_send(state, sender_id, &msg, write);
  }
};

template <>
struct MessageTraits<sbp_msg_mask_satellite_dep_t> {
  static constexpr sbp_msg_type_t id = SbpMsgMaskSatelliteDep;
  static const sbp_msg_mask_satellite_dep_t &get(const sbp_msg_t &msg) {
    return msg.mask_satellite_dep;
  }
  static sbp_msg_mask_satellite_dep_t &get(sbp_msg_t &msg) {
    return msg.mask_satellite_dep;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_mask_satellite_dep_t &msg,
                 sbp_write_fn_t write) {
    return sbp_msg_mask_satellite_dep_send(state, sender_id, &msg, write);
  }
};

template <>
struct MessageTraits<sbp_msg_mask_satellite_t> {
  static constexpr sbp_msg_type_t id = SbpMsgMaskSatellite;
  static const sbp_msg_mask_satellite_t &get(const sbp_msg_t &msg) {
    return msg.mask_satellite;
  }
  static sbp_msg_mask_satellite_t &get(sbp_msg_t &msg) {
    return msg.mask_satellite;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_mask_satellite_t &msg, sbp_write_fn_t write) {
    return sbp_msg_mask_satellite_send(state, sender_id, &msg, write);
  }
};

template <>
struct MessageTraits<sbp_msg_measurement_state_t> {
  static constexpr sbp_msg_type_t id = SbpMsgMeasurementState;
  static const sbp_msg_measurement_state_t &get(const sbp_msg_t &msg) {
    return msg.measurement_state;
  }
  static sbp_msg_measurement_state_t &get(sbp_msg_t &msg) {
    return msg.measurement_state;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_measurement_state_t &msg, sbp_write_fn_t write) {
    return sbp_msg_measurement_state_send(state, sender_id, &msg, write);
  }
};

template <>
struct MessageTraits<sbp_msg_nap_device_dna_req_t> {
  static constexpr sbp_msg_type_t id = SbpMsgNapDeviceDnaReq;
  static const sbp_msg_nap_device_dna_req_t &get(const sbp_msg_t &msg) {
    return msg.nap_device_dna_req;
  }
  static sbp_msg_nap_device_dna_req_t &get(sbp_msg_t &msg) {
    return msg.nap_device_dna_req;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_nap_device_dna_req_t &msg,
                 sbp_write_fn_t write) {
    return sbp_msg_nap_device_dna_req_send(state, sender_id, &msg, write);
  }
};

template <>
struct MessageTraits<sbp_msg_nap_device_dna_resp_t> {
  static constexpr sbp_msg_type_t id = SbpMsgNapDeviceDnaResp;
  static const sbp_msg_nap_device_dna_resp_t &get(const sbp_msg_t &msg) {
    return msg.nap_device_dna_resp;
  }
  static sbp_msg_nap_device_dna_resp_t &get(sbp_msg_t &msg) {
    return msg.nap_device_dna_resp;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_nap_device_dna_resp_t &msg,
                 sbp_write_fn_t write) {
    return sbp_msg_nap_device_dna_resp_send(state, sender_id, &msg, write);
  }
};

template <>
struct MessageTraits<sbp_msg_ndb_event_t> {
  static constexpr sbp_msg_type_t id = SbpMsgNdbEvent;
  static const sbp_msg_ndb_event_t &get(const sbp_msg_t &msg) {
    return msg.ndb_event;
  }
  static sbp_msg_ndb_event_t &get(sbp_msg_t &msg) { return msg.ndb_event; }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_ndb_event_t &msg, sbp_write_fn_t write) {
    return sbp_msg_ndb_event_send(state, sender_id, &msg, write);
  }
};

template <>
struct MessageTraits<sbp_msg_network_bandwidth_usage_t> {
  static constexpr sbp_msg_type_t id = SbpMsgNetworkBandwidthUsage;
  static const sbp_msg_network_bandwidth_usage_t &get(const sbp_msg_t &msg) {
    return msg.network_bandwidth_usage;
  }
  static sbp_msg_network_bandwidth_usage_t &get(sbp_msg_t &msg) {
    return msg.network_bandwidth_usage;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_network_bandwidth_usage_t &msg,
                 sbp_write_fn_t write) {
    return sbp_msg_network_bandwidth_usage_send(state, sender_id, &msg, write);
  }
};

template <>
struct MessageTraits<sbp_msg_network_state_req_t> {
  static constexpr sbp_msg_type_t id = SbpMsgNetworkStateReq;
  static const sbp_msg_network_state_req_t &get(const sbp_msg_t &msg) {
    return msg.network_state_req;
  }
  static sbp_msg_network_state_req_t &get(sbp_msg_t &msg) {
    return msg.network_state_req;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_network_state_req_t &msg, sbp_write_fn_t write) {
    return sbp_msg_network_state_req_send(state, sender_id, &msg, write);
  }
};

template <>
struct MessageTraits<sbp_msg_network_state_resp_t> {
  static constexpr sbp_msg_type_t id = SbpMsgNetworkStateResp;
  static const sbp_msg_network_state_resp_t &get(const sbp_msg_t &msg) {
    return msg.network_state_resp;
  }
  static sbp_msg_network_state_resp_t &get(sbp_msg_t &msg) {
    return msg.network_state_resp;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_network_state_resp_t &msg,
                 sbp_write_fn_t write) {
    return sbp_msg_network_state_resp_send(state, sender_id, &msg, write);
  }
};

template <>
struct MessageTraits<sbp_msg_obs_dep_a_t> {
  static constexpr sbp_msg_type_t id = SbpMsgObsDepA;
  static const sbp_msg_obs_dep_a_t &get(const sbp_msg_t &msg) {
    return msg.obs_dep_a;
  }
  static sbp_msg_obs_dep_a_t &get(sbp_msg_t &msg) { return msg.obs_dep_a; }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_obs_dep_a_t &msg, sbp_write_fn_t write) {
    return sbp_msg_obs_dep_a_send(state, sender_id, &msg, write);
  }
};

template <>
struct MessageTraits<sbp_msg_obs_dep_b_t> {
  static constexpr sbp_msg_type_t id = SbpMsgObsDepB;
  static const sbp_msg_obs_dep_b_t &get(const sbp_msg_t &msg) {
    return msg.obs_dep_b;
  }
  static sbp_msg_obs_dep_b_t &get(sbp_msg_t &msg) { return msg.obs_dep_b; }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_obs_dep_b_t &msg, sbp_write_fn_t write) {
    return sbp_msg_obs_dep_b_send(state, sender_id, &msg, write);
  }
};

template <>
struct MessageTraits<sbp_msg_obs_dep_c_t> {
  static constexpr sbp_msg_type_t id = SbpMsgObsDepC;
  static const sbp_msg_obs_dep_c_t &get(const sbp_msg_t &msg) {
    return msg.obs_dep_c;
  }
  static sbp_msg_obs_dep_c_t &get(sbp_msg_t &msg) { return msg.obs_dep_c; }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_obs_dep_c_t &msg, sbp_write_fn_t write) {
    return sbp_msg_obs_dep_c_send(state, sender_id, &msg, write);
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
struct MessageTraits<sbp_msg_odometry_t> {
  static constexpr sbp_msg_type_t id = SbpMsgOdometry;
  static const sbp_msg_odometry_t &get(const sbp_msg_t &msg) {
    return msg.odometry;
  }
  static sbp_msg_odometry_t &get(sbp_msg_t &msg) { return msg.odometry; }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_odometry_t &msg, sbp_write_fn_t write) {
    return sbp_msg_odometry_send(state, sender_id, &msg, write);
  }
};

template <>
struct MessageTraits<sbp_msg_orient_euler_t> {
  static constexpr sbp_msg_type_t id = SbpMsgOrientEuler;
  static const sbp_msg_orient_euler_t &get(const sbp_msg_t &msg) {
    return msg.orient_euler;
  }
  static sbp_msg_orient_euler_t &get(sbp_msg_t &msg) {
    return msg.orient_euler;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_orient_euler_t &msg, sbp_write_fn_t write) {
    return sbp_msg_orient_euler_send(state, sender_id, &msg, write);
  }
};

template <>
struct MessageTraits<sbp_msg_orient_quat_t> {
  static constexpr sbp_msg_type_t id = SbpMsgOrientQuat;
  static const sbp_msg_orient_quat_t &get(const sbp_msg_t &msg) {
    return msg.orient_quat;
  }
  static sbp_msg_orient_quat_t &get(sbp_msg_t &msg) { return msg.orient_quat; }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_orient_quat_t &msg, sbp_write_fn_t write) {
    return sbp_msg_orient_quat_send(state, sender_id, &msg, write);
  }
};

template <>
struct MessageTraits<sbp_msg_osr_t> {
  static constexpr sbp_msg_type_t id = SbpMsgOsr;
  static const sbp_msg_osr_t &get(const sbp_msg_t &msg) { return msg.osr; }
  static sbp_msg_osr_t &get(sbp_msg_t &msg) { return msg.osr; }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_osr_t &msg,
                 sbp_write_fn_t write) {
    return sbp_msg_osr_send(state, sender_id, &msg, write);
  }
};

template <>
struct MessageTraits<sbp_msg_pos_ecef_cov_gnss_t> {
  static constexpr sbp_msg_type_t id = SbpMsgPosEcefCovGnss;
  static const sbp_msg_pos_ecef_cov_gnss_t &get(const sbp_msg_t &msg) {
    return msg.pos_ecef_cov_gnss;
  }
  static sbp_msg_pos_ecef_cov_gnss_t &get(sbp_msg_t &msg) {
    return msg.pos_ecef_cov_gnss;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_pos_ecef_cov_gnss_t &msg, sbp_write_fn_t write) {
    return sbp_msg_pos_ecef_cov_gnss_send(state, sender_id, &msg, write);
  }
};

template <>
struct MessageTraits<sbp_msg_pos_ecef_cov_t> {
  static constexpr sbp_msg_type_t id = SbpMsgPosEcefCov;
  static const sbp_msg_pos_ecef_cov_t &get(const sbp_msg_t &msg) {
    return msg.pos_ecef_cov;
  }
  static sbp_msg_pos_ecef_cov_t &get(sbp_msg_t &msg) {
    return msg.pos_ecef_cov;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_pos_ecef_cov_t &msg, sbp_write_fn_t write) {
    return sbp_msg_pos_ecef_cov_send(state, sender_id, &msg, write);
  }
};

template <>
struct MessageTraits<sbp_msg_pos_ecef_dep_a_t> {
  static constexpr sbp_msg_type_t id = SbpMsgPosEcefDepA;
  static const sbp_msg_pos_ecef_dep_a_t &get(const sbp_msg_t &msg) {
    return msg.pos_ecef_dep_a;
  }
  static sbp_msg_pos_ecef_dep_a_t &get(sbp_msg_t &msg) {
    return msg.pos_ecef_dep_a;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_pos_ecef_dep_a_t &msg, sbp_write_fn_t write) {
    return sbp_msg_pos_ecef_dep_a_send(state, sender_id, &msg, write);
  }
};

template <>
struct MessageTraits<sbp_msg_pos_ecef_gnss_t> {
  static constexpr sbp_msg_type_t id = SbpMsgPosEcefGnss;
  static const sbp_msg_pos_ecef_gnss_t &get(const sbp_msg_t &msg) {
    return msg.pos_ecef_gnss;
  }
  static sbp_msg_pos_ecef_gnss_t &get(sbp_msg_t &msg) {
    return msg.pos_ecef_gnss;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_pos_ecef_gnss_t &msg, sbp_write_fn_t write) {
    return sbp_msg_pos_ecef_gnss_send(state, sender_id, &msg, write);
  }
};

template <>
struct MessageTraits<sbp_msg_pos_ecef_t> {
  static constexpr sbp_msg_type_t id = SbpMsgPosEcef;
  static const sbp_msg_pos_ecef_t &get(const sbp_msg_t &msg) {
    return msg.pos_ecef;
  }
  static sbp_msg_pos_ecef_t &get(sbp_msg_t &msg) { return msg.pos_ecef; }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_pos_ecef_t &msg, sbp_write_fn_t write) {
    return sbp_msg_pos_ecef_send(state, sender_id, &msg, write);
  }
};

template <>
struct MessageTraits<sbp_msg_pos_llh_cov_gnss_t> {
  static constexpr sbp_msg_type_t id = SbpMsgPosLlhCovGnss;
  static const sbp_msg_pos_llh_cov_gnss_t &get(const sbp_msg_t &msg) {
    return msg.pos_llh_cov_gnss;
  }
  static sbp_msg_pos_llh_cov_gnss_t &get(sbp_msg_t &msg) {
    return msg.pos_llh_cov_gnss;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_pos_llh_cov_gnss_t &msg, sbp_write_fn_t write) {
    return sbp_msg_pos_llh_cov_gnss_send(state, sender_id, &msg, write);
  }
};

template <>
struct MessageTraits<sbp_msg_pos_llh_cov_t> {
  static constexpr sbp_msg_type_t id = SbpMsgPosLlhCov;
  static const sbp_msg_pos_llh_cov_t &get(const sbp_msg_t &msg) {
    return msg.pos_llh_cov;
  }
  static sbp_msg_pos_llh_cov_t &get(sbp_msg_t &msg) { return msg.pos_llh_cov; }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_pos_llh_cov_t &msg, sbp_write_fn_t write) {
    return sbp_msg_pos_llh_cov_send(state, sender_id, &msg, write);
  }
};

template <>
struct MessageTraits<sbp_msg_pos_llh_dep_a_t> {
  static constexpr sbp_msg_type_t id = SbpMsgPosLlhDepA;
  static const sbp_msg_pos_llh_dep_a_t &get(const sbp_msg_t &msg) {
    return msg.pos_llh_dep_a;
  }
  static sbp_msg_pos_llh_dep_a_t &get(sbp_msg_t &msg) {
    return msg.pos_llh_dep_a;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_pos_llh_dep_a_t &msg, sbp_write_fn_t write) {
    return sbp_msg_pos_llh_dep_a_send(state, sender_id, &msg, write);
  }
};

template <>
struct MessageTraits<sbp_msg_pos_llh_gnss_t> {
  static constexpr sbp_msg_type_t id = SbpMsgPosLlhGnss;
  static const sbp_msg_pos_llh_gnss_t &get(const sbp_msg_t &msg) {
    return msg.pos_llh_gnss;
  }
  static sbp_msg_pos_llh_gnss_t &get(sbp_msg_t &msg) {
    return msg.pos_llh_gnss;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_pos_llh_gnss_t &msg, sbp_write_fn_t write) {
    return sbp_msg_pos_llh_gnss_send(state, sender_id, &msg, write);
  }
};

template <>
struct MessageTraits<sbp_msg_pos_llh_t> {
  static constexpr sbp_msg_type_t id = SbpMsgPosLlh;
  static const sbp_msg_pos_llh_t &get(const sbp_msg_t &msg) {
    return msg.pos_llh;
  }
  static sbp_msg_pos_llh_t &get(sbp_msg_t &msg) { return msg.pos_llh; }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_pos_llh_t &msg, sbp_write_fn_t write) {
    return sbp_msg_pos_llh_send(state, sender_id, &msg, write);
  }
};

template <>
struct MessageTraits<sbp_msg_pps_time_t> {
  static constexpr sbp_msg_type_t id = SbpMsgPpsTime;
  static const sbp_msg_pps_time_t &get(const sbp_msg_t &msg) {
    return msg.pps_time;
  }
  static sbp_msg_pps_time_t &get(sbp_msg_t &msg) { return msg.pps_time; }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_pps_time_t &msg, sbp_write_fn_t write) {
    return sbp_msg_pps_time_send(state, sender_id, &msg, write);
  }
};

template <>
struct MessageTraits<sbp_msg_print_dep_t> {
  static constexpr sbp_msg_type_t id = SbpMsgPrintDep;
  static const sbp_msg_print_dep_t &get(const sbp_msg_t &msg) {
    return msg.print_dep;
  }
  static sbp_msg_print_dep_t &get(sbp_msg_t &msg) { return msg.print_dep; }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_print_dep_t &msg, sbp_write_fn_t write) {
    return sbp_msg_print_dep_send(state, sender_id, &msg, write);
  }
};

template <>
struct MessageTraits<sbp_msg_protection_level_dep_a_t> {
  static constexpr sbp_msg_type_t id = SbpMsgProtectionLevelDepA;
  static const sbp_msg_protection_level_dep_a_t &get(const sbp_msg_t &msg) {
    return msg.protection_level_dep_a;
  }
  static sbp_msg_protection_level_dep_a_t &get(sbp_msg_t &msg) {
    return msg.protection_level_dep_a;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_protection_level_dep_a_t &msg,
                 sbp_write_fn_t write) {
    return sbp_msg_protection_level_dep_a_send(state, sender_id, &msg, write);
  }
};

template <>
struct MessageTraits<sbp_msg_protection_level_t> {
  static constexpr sbp_msg_type_t id = SbpMsgProtectionLevel;
  static const sbp_msg_protection_level_t &get(const sbp_msg_t &msg) {
    return msg.protection_level;
  }
  static sbp_msg_protection_level_t &get(sbp_msg_t &msg) {
    return msg.protection_level;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_protection_level_t &msg, sbp_write_fn_t write) {
    return sbp_msg_protection_level_send(state, sender_id, &msg, write);
  }
};

template <>
struct MessageTraits<sbp_msg_reset_dep_t> {
  static constexpr sbp_msg_type_t id = SbpMsgResetDep;
  static const sbp_msg_reset_dep_t &get(const sbp_msg_t &msg) {
    return msg.reset_dep;
  }
  static sbp_msg_reset_dep_t &get(sbp_msg_t &msg) { return msg.reset_dep; }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_reset_dep_t &msg, sbp_write_fn_t write) {
    return sbp_msg_reset_dep_send(state, sender_id, &msg, write);
  }
};

template <>
struct MessageTraits<sbp_msg_reset_filters_t> {
  static constexpr sbp_msg_type_t id = SbpMsgResetFilters;
  static const sbp_msg_reset_filters_t &get(const sbp_msg_t &msg) {
    return msg.reset_filters;
  }
  static sbp_msg_reset_filters_t &get(sbp_msg_t &msg) {
    return msg.reset_filters;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_reset_filters_t &msg, sbp_write_fn_t write) {
    return sbp_msg_reset_filters_send(state, sender_id, &msg, write);
  }
};

template <>
struct MessageTraits<sbp_msg_reset_t> {
  static constexpr sbp_msg_type_t id = SbpMsgReset;
  static const sbp_msg_reset_t &get(const sbp_msg_t &msg) { return msg.reset; }
  static sbp_msg_reset_t &get(sbp_msg_t &msg) { return msg.reset; }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_reset_t &msg,
                 sbp_write_fn_t write) {
    return sbp_msg_reset_send(state, sender_id, &msg, write);
  }
};

template <>
struct MessageTraits<sbp_msg_sbas_raw_t> {
  static constexpr sbp_msg_type_t id = SbpMsgSbasRaw;
  static const sbp_msg_sbas_raw_t &get(const sbp_msg_t &msg) {
    return msg.sbas_raw;
  }
  static sbp_msg_sbas_raw_t &get(sbp_msg_t &msg) { return msg.sbas_raw; }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_sbas_raw_t &msg, sbp_write_fn_t write) {
    return sbp_msg_sbas_raw_send(state, sender_id, &msg, write);
  }
};

template <>
struct MessageTraits<sbp_msg_set_time_t> {
  static constexpr sbp_msg_type_t id = SbpMsgSetTime;
  static const sbp_msg_set_time_t &get(const sbp_msg_t &msg) {
    return msg.set_time;
  }
  static sbp_msg_set_time_t &get(sbp_msg_t &msg) { return msg.set_time; }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_set_time_t &msg, sbp_write_fn_t write) {
    return sbp_msg_set_time_send(state, sender_id, &msg, write);
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
struct MessageTraits<sbp_msg_settings_read_by_index_req_t> {
  static constexpr sbp_msg_type_t id = SbpMsgSettingsReadByIndexReq;
  static const sbp_msg_settings_read_by_index_req_t &get(const sbp_msg_t &msg) {
    return msg.settings_read_by_index_req;
  }
  static sbp_msg_settings_read_by_index_req_t &get(sbp_msg_t &msg) {
    return msg.settings_read_by_index_req;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_settings_read_by_index_req_t &msg,
                 sbp_write_fn_t write) {
    return sbp_msg_settings_read_by_index_req_send(state, sender_id, &msg,
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
struct MessageTraits<sbp_msg_settings_read_req_t> {
  static constexpr sbp_msg_type_t id = SbpMsgSettingsReadReq;
  static const sbp_msg_settings_read_req_t &get(const sbp_msg_t &msg) {
    return msg.settings_read_req;
  }
  static sbp_msg_settings_read_req_t &get(sbp_msg_t &msg) {
    return msg.settings_read_req;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_settings_read_req_t &msg, sbp_write_fn_t write) {
    return sbp_msg_settings_read_req_send(state, sender_id, &msg, write);
  }
};

template <>
struct MessageTraits<sbp_msg_settings_read_resp_t> {
  static constexpr sbp_msg_type_t id = SbpMsgSettingsReadResp;
  static const sbp_msg_settings_read_resp_t &get(const sbp_msg_t &msg) {
    return msg.settings_read_resp;
  }
  static sbp_msg_settings_read_resp_t &get(sbp_msg_t &msg) {
    return msg.settings_read_resp;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_settings_read_resp_t &msg,
                 sbp_write_fn_t write) {
    return sbp_msg_settings_read_resp_send(state, sender_id, &msg, write);
  }
};

template <>
struct MessageTraits<sbp_msg_settings_register_resp_t> {
  static constexpr sbp_msg_type_t id = SbpMsgSettingsRegisterResp;
  static const sbp_msg_settings_register_resp_t &get(const sbp_msg_t &msg) {
    return msg.settings_register_resp;
  }
  static sbp_msg_settings_register_resp_t &get(sbp_msg_t &msg) {
    return msg.settings_register_resp;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_settings_register_resp_t &msg,
                 sbp_write_fn_t write) {
    return sbp_msg_settings_register_resp_send(state, sender_id, &msg, write);
  }
};

template <>
struct MessageTraits<sbp_msg_settings_register_t> {
  static constexpr sbp_msg_type_t id = SbpMsgSettingsRegister;
  static const sbp_msg_settings_register_t &get(const sbp_msg_t &msg) {
    return msg.settings_register;
  }
  static sbp_msg_settings_register_t &get(sbp_msg_t &msg) {
    return msg.settings_register;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_settings_register_t &msg, sbp_write_fn_t write) {
    return sbp_msg_settings_register_send(state, sender_id, &msg, write);
  }
};

template <>
struct MessageTraits<sbp_msg_settings_save_t> {
  static constexpr sbp_msg_type_t id = SbpMsgSettingsSave;
  static const sbp_msg_settings_save_t &get(const sbp_msg_t &msg) {
    return msg.settings_save;
  }
  static sbp_msg_settings_save_t &get(sbp_msg_t &msg) {
    return msg.settings_save;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_settings_save_t &msg, sbp_write_fn_t write) {
    return sbp_msg_settings_save_send(state, sender_id, &msg, write);
  }
};

template <>
struct MessageTraits<sbp_msg_settings_write_resp_t> {
  static constexpr sbp_msg_type_t id = SbpMsgSettingsWriteResp;
  static const sbp_msg_settings_write_resp_t &get(const sbp_msg_t &msg) {
    return msg.settings_write_resp;
  }
  static sbp_msg_settings_write_resp_t &get(sbp_msg_t &msg) {
    return msg.settings_write_resp;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_settings_write_resp_t &msg,
                 sbp_write_fn_t write) {
    return sbp_msg_settings_write_resp_send(state, sender_id, &msg, write);
  }
};

template <>
struct MessageTraits<sbp_msg_settings_write_t> {
  static constexpr sbp_msg_type_t id = SbpMsgSettingsWrite;
  static const sbp_msg_settings_write_t &get(const sbp_msg_t &msg) {
    return msg.settings_write;
  }
  static sbp_msg_settings_write_t &get(sbp_msg_t &msg) {
    return msg.settings_write;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_settings_write_t &msg, sbp_write_fn_t write) {
    return sbp_msg_settings_write_send(state, sender_id, &msg, write);
  }
};

template <>
struct MessageTraits<sbp_msg_soln_meta_dep_a_t> {
  static constexpr sbp_msg_type_t id = SbpMsgSolnMetaDepA;
  static const sbp_msg_soln_meta_dep_a_t &get(const sbp_msg_t &msg) {
    return msg.soln_meta_dep_a;
  }
  static sbp_msg_soln_meta_dep_a_t &get(sbp_msg_t &msg) {
    return msg.soln_meta_dep_a;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_soln_meta_dep_a_t &msg, sbp_write_fn_t write) {
    return sbp_msg_soln_meta_dep_a_send(state, sender_id, &msg, write);
  }
};

template <>
struct MessageTraits<sbp_msg_soln_meta_t> {
  static constexpr sbp_msg_type_t id = SbpMsgSolnMeta;
  static const sbp_msg_soln_meta_t &get(const sbp_msg_t &msg) {
    return msg.soln_meta;
  }
  static sbp_msg_soln_meta_t &get(sbp_msg_t &msg) { return msg.soln_meta; }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_soln_meta_t &msg, sbp_write_fn_t write) {
    return sbp_msg_soln_meta_send(state, sender_id, &msg, write);
  }
};

template <>
struct MessageTraits<sbp_msg_specan_dep_t> {
  static constexpr sbp_msg_type_t id = SbpMsgSpecanDep;
  static const sbp_msg_specan_dep_t &get(const sbp_msg_t &msg) {
    return msg.specan_dep;
  }
  static sbp_msg_specan_dep_t &get(sbp_msg_t &msg) { return msg.specan_dep; }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_specan_dep_t &msg, sbp_write_fn_t write) {
    return sbp_msg_specan_dep_send(state, sender_id, &msg, write);
  }
};

template <>
struct MessageTraits<sbp_msg_specan_t> {
  static constexpr sbp_msg_type_t id = SbpMsgSpecan;
  static const sbp_msg_specan_t &get(const sbp_msg_t &msg) {
    return msg.specan;
  }
  static sbp_msg_specan_t &get(sbp_msg_t &msg) { return msg.specan; }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_specan_t &msg,
                 sbp_write_fn_t write) {
    return sbp_msg_specan_send(state, sender_id, &msg, write);
  }
};

template <>
struct MessageTraits<sbp_msg_ssr_code_biases_t> {
  static constexpr sbp_msg_type_t id = SbpMsgSsrCodeBiases;
  static const sbp_msg_ssr_code_biases_t &get(const sbp_msg_t &msg) {
    return msg.ssr_code_biases;
  }
  static sbp_msg_ssr_code_biases_t &get(sbp_msg_t &msg) {
    return msg.ssr_code_biases;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_ssr_code_biases_t &msg, sbp_write_fn_t write) {
    return sbp_msg_ssr_code_biases_send(state, sender_id, &msg, write);
  }
};

template <>
struct MessageTraits<sbp_msg_ssr_grid_definition_dep_a_t> {
  static constexpr sbp_msg_type_t id = SbpMsgSsrGridDefinitionDepA;
  static const sbp_msg_ssr_grid_definition_dep_a_t &get(const sbp_msg_t &msg) {
    return msg.ssr_grid_definition_dep_a;
  }
  static sbp_msg_ssr_grid_definition_dep_a_t &get(sbp_msg_t &msg) {
    return msg.ssr_grid_definition_dep_a;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_ssr_grid_definition_dep_a_t &msg,
                 sbp_write_fn_t write) {
    return sbp_msg_ssr_grid_definition_dep_a_send(state, sender_id, &msg,
                                                  write);
  }
};

template <>
struct MessageTraits<sbp_msg_ssr_gridded_correction_dep_a_t> {
  static constexpr sbp_msg_type_t id = SbpMsgSsrGriddedCorrectionDepA;
  static const sbp_msg_ssr_gridded_correction_dep_a_t &get(
      const sbp_msg_t &msg) {
    return msg.ssr_gridded_correction_dep_a;
  }
  static sbp_msg_ssr_gridded_correction_dep_a_t &get(sbp_msg_t &msg) {
    return msg.ssr_gridded_correction_dep_a;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_ssr_gridded_correction_dep_a_t &msg,
                 sbp_write_fn_t write) {
    return sbp_msg_ssr_gridded_correction_dep_a_send(state, sender_id, &msg,
                                                     write);
  }
};

template <>
struct MessageTraits<sbp_msg_ssr_gridded_correction_no_std_dep_a_t> {
  static constexpr sbp_msg_type_t id = SbpMsgSsrGriddedCorrectionNoStdDepA;
  static const sbp_msg_ssr_gridded_correction_no_std_dep_a_t &get(
      const sbp_msg_t &msg) {
    return msg.ssr_gridded_correction_no_std_dep_a;
  }
  static sbp_msg_ssr_gridded_correction_no_std_dep_a_t &get(sbp_msg_t &msg) {
    return msg.ssr_gridded_correction_no_std_dep_a;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_ssr_gridded_correction_no_std_dep_a_t &msg,
                 sbp_write_fn_t write) {
    return sbp_msg_ssr_gridded_correction_no_std_dep_a_send(state, sender_id,
                                                            &msg, write);
  }
};

template <>
struct MessageTraits<sbp_msg_ssr_gridded_correction_t> {
  static constexpr sbp_msg_type_t id = SbpMsgSsrGriddedCorrection;
  static const sbp_msg_ssr_gridded_correction_t &get(const sbp_msg_t &msg) {
    return msg.ssr_gridded_correction;
  }
  static sbp_msg_ssr_gridded_correction_t &get(sbp_msg_t &msg) {
    return msg.ssr_gridded_correction;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_ssr_gridded_correction_t &msg,
                 sbp_write_fn_t write) {
    return sbp_msg_ssr_gridded_correction_send(state, sender_id, &msg, write);
  }
};

template <>
struct MessageTraits<sbp_msg_ssr_orbit_clock_dep_a_t> {
  static constexpr sbp_msg_type_t id = SbpMsgSsrOrbitClockDepA;
  static const sbp_msg_ssr_orbit_clock_dep_a_t &get(const sbp_msg_t &msg) {
    return msg.ssr_orbit_clock_dep_a;
  }
  static sbp_msg_ssr_orbit_clock_dep_a_t &get(sbp_msg_t &msg) {
    return msg.ssr_orbit_clock_dep_a;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_ssr_orbit_clock_dep_a_t &msg,
                 sbp_write_fn_t write) {
    return sbp_msg_ssr_orbit_clock_dep_a_send(state, sender_id, &msg, write);
  }
};

template <>
struct MessageTraits<sbp_msg_ssr_orbit_clock_t> {
  static constexpr sbp_msg_type_t id = SbpMsgSsrOrbitClock;
  static const sbp_msg_ssr_orbit_clock_t &get(const sbp_msg_t &msg) {
    return msg.ssr_orbit_clock;
  }
  static sbp_msg_ssr_orbit_clock_t &get(sbp_msg_t &msg) {
    return msg.ssr_orbit_clock;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_ssr_orbit_clock_t &msg, sbp_write_fn_t write) {
    return sbp_msg_ssr_orbit_clock_send(state, sender_id, &msg, write);
  }
};

template <>
struct MessageTraits<sbp_msg_ssr_phase_biases_t> {
  static constexpr sbp_msg_type_t id = SbpMsgSsrPhaseBiases;
  static const sbp_msg_ssr_phase_biases_t &get(const sbp_msg_t &msg) {
    return msg.ssr_phase_biases;
  }
  static sbp_msg_ssr_phase_biases_t &get(sbp_msg_t &msg) {
    return msg.ssr_phase_biases;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_ssr_phase_biases_t &msg, sbp_write_fn_t write) {
    return sbp_msg_ssr_phase_biases_send(state, sender_id, &msg, write);
  }
};

template <>
struct MessageTraits<sbp_msg_ssr_satellite_apc_t> {
  static constexpr sbp_msg_type_t id = SbpMsgSsrSatelliteApc;
  static const sbp_msg_ssr_satellite_apc_t &get(const sbp_msg_t &msg) {
    return msg.ssr_satellite_apc;
  }
  static sbp_msg_ssr_satellite_apc_t &get(sbp_msg_t &msg) {
    return msg.ssr_satellite_apc;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_ssr_satellite_apc_t &msg, sbp_write_fn_t write) {
    return sbp_msg_ssr_satellite_apc_send(state, sender_id, &msg, write);
  }
};

template <>
struct MessageTraits<sbp_msg_ssr_stec_correction_dep_a_t> {
  static constexpr sbp_msg_type_t id = SbpMsgSsrStecCorrectionDepA;
  static const sbp_msg_ssr_stec_correction_dep_a_t &get(const sbp_msg_t &msg) {
    return msg.ssr_stec_correction_dep_a;
  }
  static sbp_msg_ssr_stec_correction_dep_a_t &get(sbp_msg_t &msg) {
    return msg.ssr_stec_correction_dep_a;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_ssr_stec_correction_dep_a_t &msg,
                 sbp_write_fn_t write) {
    return sbp_msg_ssr_stec_correction_dep_a_send(state, sender_id, &msg,
                                                  write);
  }
};

template <>
struct MessageTraits<sbp_msg_ssr_stec_correction_t> {
  static constexpr sbp_msg_type_t id = SbpMsgSsrStecCorrection;
  static const sbp_msg_ssr_stec_correction_t &get(const sbp_msg_t &msg) {
    return msg.ssr_stec_correction;
  }
  static sbp_msg_ssr_stec_correction_t &get(sbp_msg_t &msg) {
    return msg.ssr_stec_correction;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_ssr_stec_correction_t &msg,
                 sbp_write_fn_t write) {
    return sbp_msg_ssr_stec_correction_send(state, sender_id, &msg, write);
  }
};

template <>
struct MessageTraits<sbp_msg_ssr_tile_definition_t> {
  static constexpr sbp_msg_type_t id = SbpMsgSsrTileDefinition;
  static const sbp_msg_ssr_tile_definition_t &get(const sbp_msg_t &msg) {
    return msg.ssr_tile_definition;
  }
  static sbp_msg_ssr_tile_definition_t &get(sbp_msg_t &msg) {
    return msg.ssr_tile_definition;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_ssr_tile_definition_t &msg,
                 sbp_write_fn_t write) {
    return sbp_msg_ssr_tile_definition_send(state, sender_id, &msg, write);
  }
};

template <>
struct MessageTraits<sbp_msg_startup_t> {
  static constexpr sbp_msg_type_t id = SbpMsgStartup;
  static const sbp_msg_startup_t &get(const sbp_msg_t &msg) {
    return msg.startup;
  }
  static sbp_msg_startup_t &get(sbp_msg_t &msg) { return msg.startup; }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_startup_t &msg, sbp_write_fn_t write) {
    return sbp_msg_startup_send(state, sender_id, &msg, write);
  }
};

template <>
struct MessageTraits<sbp_msg_status_report_t> {
  static constexpr sbp_msg_type_t id = SbpMsgStatusReport;
  static const sbp_msg_status_report_t &get(const sbp_msg_t &msg) {
    return msg.status_report;
  }
  static sbp_msg_status_report_t &get(sbp_msg_t &msg) {
    return msg.status_report;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_status_report_t &msg, sbp_write_fn_t write) {
    return sbp_msg_status_report_send(state, sender_id, &msg, write);
  }
};

template <>
struct MessageTraits<sbp_msg_stm_flash_lock_sector_t> {
  static constexpr sbp_msg_type_t id = SbpMsgStmFlashLockSector;
  static const sbp_msg_stm_flash_lock_sector_t &get(const sbp_msg_t &msg) {
    return msg.stm_flash_lock_sector;
  }
  static sbp_msg_stm_flash_lock_sector_t &get(sbp_msg_t &msg) {
    return msg.stm_flash_lock_sector;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_stm_flash_lock_sector_t &msg,
                 sbp_write_fn_t write) {
    return sbp_msg_stm_flash_lock_sector_send(state, sender_id, &msg, write);
  }
};

template <>
struct MessageTraits<sbp_msg_stm_flash_unlock_sector_t> {
  static constexpr sbp_msg_type_t id = SbpMsgStmFlashUnlockSector;
  static const sbp_msg_stm_flash_unlock_sector_t &get(const sbp_msg_t &msg) {
    return msg.stm_flash_unlock_sector;
  }
  static sbp_msg_stm_flash_unlock_sector_t &get(sbp_msg_t &msg) {
    return msg.stm_flash_unlock_sector;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_stm_flash_unlock_sector_t &msg,
                 sbp_write_fn_t write) {
    return sbp_msg_stm_flash_unlock_sector_send(state, sender_id, &msg, write);
  }
};

template <>
struct MessageTraits<sbp_msg_stm_unique_id_req_t> {
  static constexpr sbp_msg_type_t id = SbpMsgStmUniqueIdReq;
  static const sbp_msg_stm_unique_id_req_t &get(const sbp_msg_t &msg) {
    return msg.stm_unique_id_req;
  }
  static sbp_msg_stm_unique_id_req_t &get(sbp_msg_t &msg) {
    return msg.stm_unique_id_req;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_stm_unique_id_req_t &msg, sbp_write_fn_t write) {
    return sbp_msg_stm_unique_id_req_send(state, sender_id, &msg, write);
  }
};

template <>
struct MessageTraits<sbp_msg_stm_unique_id_resp_t> {
  static constexpr sbp_msg_type_t id = SbpMsgStmUniqueIdResp;
  static const sbp_msg_stm_unique_id_resp_t &get(const sbp_msg_t &msg) {
    return msg.stm_unique_id_resp;
  }
  static sbp_msg_stm_unique_id_resp_t &get(sbp_msg_t &msg) {
    return msg.stm_unique_id_resp;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_stm_unique_id_resp_t &msg,
                 sbp_write_fn_t write) {
    return sbp_msg_stm_unique_id_resp_send(state, sender_id, &msg, write);
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

template <>
struct MessageTraits<sbp_msg_sv_configuration_gps_dep_t> {
  static constexpr sbp_msg_type_t id = SbpMsgSvConfigurationGpsDep;
  static const sbp_msg_sv_configuration_gps_dep_t &get(const sbp_msg_t &msg) {
    return msg.sv_configuration_gps_dep;
  }
  static sbp_msg_sv_configuration_gps_dep_t &get(sbp_msg_t &msg) {
    return msg.sv_configuration_gps_dep;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_sv_configuration_gps_dep_t &msg,
                 sbp_write_fn_t write) {
    return sbp_msg_sv_configuration_gps_dep_send(state, sender_id, &msg, write);
  }
};

template <>
struct MessageTraits<sbp_msg_thread_state_t> {
  static constexpr sbp_msg_type_t id = SbpMsgThreadState;
  static const sbp_msg_thread_state_t &get(const sbp_msg_t &msg) {
    return msg.thread_state;
  }
  static sbp_msg_thread_state_t &get(sbp_msg_t &msg) {
    return msg.thread_state;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_thread_state_t &msg, sbp_write_fn_t write) {
    return sbp_msg_thread_state_send(state, sender_id, &msg, write);
  }
};

template <>
struct MessageTraits<sbp_msg_tracking_iq_dep_a_t> {
  static constexpr sbp_msg_type_t id = SbpMsgTrackingIqDepA;
  static const sbp_msg_tracking_iq_dep_a_t &get(const sbp_msg_t &msg) {
    return msg.tracking_iq_dep_a;
  }
  static sbp_msg_tracking_iq_dep_a_t &get(sbp_msg_t &msg) {
    return msg.tracking_iq_dep_a;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_tracking_iq_dep_a_t &msg, sbp_write_fn_t write) {
    return sbp_msg_tracking_iq_dep_a_send(state, sender_id, &msg, write);
  }
};

template <>
struct MessageTraits<sbp_msg_tracking_iq_dep_b_t> {
  static constexpr sbp_msg_type_t id = SbpMsgTrackingIqDepB;
  static const sbp_msg_tracking_iq_dep_b_t &get(const sbp_msg_t &msg) {
    return msg.tracking_iq_dep_b;
  }
  static sbp_msg_tracking_iq_dep_b_t &get(sbp_msg_t &msg) {
    return msg.tracking_iq_dep_b;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_tracking_iq_dep_b_t &msg, sbp_write_fn_t write) {
    return sbp_msg_tracking_iq_dep_b_send(state, sender_id, &msg, write);
  }
};

template <>
struct MessageTraits<sbp_msg_tracking_iq_t> {
  static constexpr sbp_msg_type_t id = SbpMsgTrackingIq;
  static const sbp_msg_tracking_iq_t &get(const sbp_msg_t &msg) {
    return msg.tracking_iq;
  }
  static sbp_msg_tracking_iq_t &get(sbp_msg_t &msg) { return msg.tracking_iq; }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_tracking_iq_t &msg, sbp_write_fn_t write) {
    return sbp_msg_tracking_iq_send(state, sender_id, &msg, write);
  }
};

template <>
struct MessageTraits<sbp_msg_tracking_state_dep_a_t> {
  static constexpr sbp_msg_type_t id = SbpMsgTrackingStateDepA;
  static const sbp_msg_tracking_state_dep_a_t &get(const sbp_msg_t &msg) {
    return msg.tracking_state_dep_a;
  }
  static sbp_msg_tracking_state_dep_a_t &get(sbp_msg_t &msg) {
    return msg.tracking_state_dep_a;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_tracking_state_dep_a_t &msg,
                 sbp_write_fn_t write) {
    return sbp_msg_tracking_state_dep_a_send(state, sender_id, &msg, write);
  }
};

template <>
struct MessageTraits<sbp_msg_tracking_state_dep_b_t> {
  static constexpr sbp_msg_type_t id = SbpMsgTrackingStateDepB;
  static const sbp_msg_tracking_state_dep_b_t &get(const sbp_msg_t &msg) {
    return msg.tracking_state_dep_b;
  }
  static sbp_msg_tracking_state_dep_b_t &get(sbp_msg_t &msg) {
    return msg.tracking_state_dep_b;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_tracking_state_dep_b_t &msg,
                 sbp_write_fn_t write) {
    return sbp_msg_tracking_state_dep_b_send(state, sender_id, &msg, write);
  }
};

template <>
struct MessageTraits<sbp_msg_tracking_state_detailed_dep_a_t> {
  static constexpr sbp_msg_type_t id = SbpMsgTrackingStateDetailedDepA;
  static const sbp_msg_tracking_state_detailed_dep_a_t &get(
      const sbp_msg_t &msg) {
    return msg.tracking_state_detailed_dep_a;
  }
  static sbp_msg_tracking_state_detailed_dep_a_t &get(sbp_msg_t &msg) {
    return msg.tracking_state_detailed_dep_a;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_tracking_state_detailed_dep_a_t &msg,
                 sbp_write_fn_t write) {
    return sbp_msg_tracking_state_detailed_dep_a_send(state, sender_id, &msg,
                                                      write);
  }
};

template <>
struct MessageTraits<sbp_msg_tracking_state_detailed_dep_t> {
  static constexpr sbp_msg_type_t id = SbpMsgTrackingStateDetailedDep;
  static const sbp_msg_tracking_state_detailed_dep_t &get(
      const sbp_msg_t &msg) {
    return msg.tracking_state_detailed_dep;
  }
  static sbp_msg_tracking_state_detailed_dep_t &get(sbp_msg_t &msg) {
    return msg.tracking_state_detailed_dep;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_tracking_state_detailed_dep_t &msg,
                 sbp_write_fn_t write) {
    return sbp_msg_tracking_state_detailed_dep_send(state, sender_id, &msg,
                                                    write);
  }
};

template <>
struct MessageTraits<sbp_msg_tracking_state_t> {
  static constexpr sbp_msg_type_t id = SbpMsgTrackingState;
  static const sbp_msg_tracking_state_t &get(const sbp_msg_t &msg) {
    return msg.tracking_state;
  }
  static sbp_msg_tracking_state_t &get(sbp_msg_t &msg) {
    return msg.tracking_state;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_tracking_state_t &msg, sbp_write_fn_t write) {
    return sbp_msg_tracking_state_send(state, sender_id, &msg, write);
  }
};

template <>
struct MessageTraits<sbp_msg_uart_state_depa_t> {
  static constexpr sbp_msg_type_t id = SbpMsgUartStateDepa;
  static const sbp_msg_uart_state_depa_t &get(const sbp_msg_t &msg) {
    return msg.uart_state_depa;
  }
  static sbp_msg_uart_state_depa_t &get(sbp_msg_t &msg) {
    return msg.uart_state_depa;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_uart_state_depa_t &msg, sbp_write_fn_t write) {
    return sbp_msg_uart_state_depa_send(state, sender_id, &msg, write);
  }
};

template <>
struct MessageTraits<sbp_msg_uart_state_t> {
  static constexpr sbp_msg_type_t id = SbpMsgUartState;
  static const sbp_msg_uart_state_t &get(const sbp_msg_t &msg) {
    return msg.uart_state;
  }
  static sbp_msg_uart_state_t &get(sbp_msg_t &msg) { return msg.uart_state; }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_uart_state_t &msg, sbp_write_fn_t write) {
    return sbp_msg_uart_state_send(state, sender_id, &msg, write);
  }
};

template <>
struct MessageTraits<sbp_msg_user_data_t> {
  static constexpr sbp_msg_type_t id = SbpMsgUserData;
  static const sbp_msg_user_data_t &get(const sbp_msg_t &msg) {
    return msg.user_data;
  }
  static sbp_msg_user_data_t &get(sbp_msg_t &msg) { return msg.user_data; }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_user_data_t &msg, sbp_write_fn_t write) {
    return sbp_msg_user_data_send(state, sender_id, &msg, write);
  }
};

template <>
struct MessageTraits<sbp_msg_utc_time_gnss_t> {
  static constexpr sbp_msg_type_t id = SbpMsgUtcTimeGnss;
  static const sbp_msg_utc_time_gnss_t &get(const sbp_msg_t &msg) {
    return msg.utc_time_gnss;
  }
  static sbp_msg_utc_time_gnss_t &get(sbp_msg_t &msg) {
    return msg.utc_time_gnss;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_utc_time_gnss_t &msg, sbp_write_fn_t write) {
    return sbp_msg_utc_time_gnss_send(state, sender_id, &msg, write);
  }
};

template <>
struct MessageTraits<sbp_msg_utc_time_t> {
  static constexpr sbp_msg_type_t id = SbpMsgUtcTime;
  static const sbp_msg_utc_time_t &get(const sbp_msg_t &msg) {
    return msg.utc_time;
  }
  static sbp_msg_utc_time_t &get(sbp_msg_t &msg) { return msg.utc_time; }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_utc_time_t &msg, sbp_write_fn_t write) {
    return sbp_msg_utc_time_send(state, sender_id, &msg, write);
  }
};

template <>
struct MessageTraits<sbp_msg_vel_body_t> {
  static constexpr sbp_msg_type_t id = SbpMsgVelBody;
  static const sbp_msg_vel_body_t &get(const sbp_msg_t &msg) {
    return msg.vel_body;
  }
  static sbp_msg_vel_body_t &get(sbp_msg_t &msg) { return msg.vel_body; }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_vel_body_t &msg, sbp_write_fn_t write) {
    return sbp_msg_vel_body_send(state, sender_id, &msg, write);
  }
};

template <>
struct MessageTraits<sbp_msg_vel_ecef_cov_gnss_t> {
  static constexpr sbp_msg_type_t id = SbpMsgVelEcefCovGnss;
  static const sbp_msg_vel_ecef_cov_gnss_t &get(const sbp_msg_t &msg) {
    return msg.vel_ecef_cov_gnss;
  }
  static sbp_msg_vel_ecef_cov_gnss_t &get(sbp_msg_t &msg) {
    return msg.vel_ecef_cov_gnss;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_vel_ecef_cov_gnss_t &msg, sbp_write_fn_t write) {
    return sbp_msg_vel_ecef_cov_gnss_send(state, sender_id, &msg, write);
  }
};

template <>
struct MessageTraits<sbp_msg_vel_ecef_cov_t> {
  static constexpr sbp_msg_type_t id = SbpMsgVelEcefCov;
  static const sbp_msg_vel_ecef_cov_t &get(const sbp_msg_t &msg) {
    return msg.vel_ecef_cov;
  }
  static sbp_msg_vel_ecef_cov_t &get(sbp_msg_t &msg) {
    return msg.vel_ecef_cov;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_vel_ecef_cov_t &msg, sbp_write_fn_t write) {
    return sbp_msg_vel_ecef_cov_send(state, sender_id, &msg, write);
  }
};

template <>
struct MessageTraits<sbp_msg_vel_ecef_dep_a_t> {
  static constexpr sbp_msg_type_t id = SbpMsgVelEcefDepA;
  static const sbp_msg_vel_ecef_dep_a_t &get(const sbp_msg_t &msg) {
    return msg.vel_ecef_dep_a;
  }
  static sbp_msg_vel_ecef_dep_a_t &get(sbp_msg_t &msg) {
    return msg.vel_ecef_dep_a;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_vel_ecef_dep_a_t &msg, sbp_write_fn_t write) {
    return sbp_msg_vel_ecef_dep_a_send(state, sender_id, &msg, write);
  }
};

template <>
struct MessageTraits<sbp_msg_vel_ecef_gnss_t> {
  static constexpr sbp_msg_type_t id = SbpMsgVelEcefGnss;
  static const sbp_msg_vel_ecef_gnss_t &get(const sbp_msg_t &msg) {
    return msg.vel_ecef_gnss;
  }
  static sbp_msg_vel_ecef_gnss_t &get(sbp_msg_t &msg) {
    return msg.vel_ecef_gnss;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_vel_ecef_gnss_t &msg, sbp_write_fn_t write) {
    return sbp_msg_vel_ecef_gnss_send(state, sender_id, &msg, write);
  }
};

template <>
struct MessageTraits<sbp_msg_vel_ecef_t> {
  static constexpr sbp_msg_type_t id = SbpMsgVelEcef;
  static const sbp_msg_vel_ecef_t &get(const sbp_msg_t &msg) {
    return msg.vel_ecef;
  }
  static sbp_msg_vel_ecef_t &get(sbp_msg_t &msg) { return msg.vel_ecef; }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_vel_ecef_t &msg, sbp_write_fn_t write) {
    return sbp_msg_vel_ecef_send(state, sender_id, &msg, write);
  }
};

template <>
struct MessageTraits<sbp_msg_vel_ned_cov_gnss_t> {
  static constexpr sbp_msg_type_t id = SbpMsgVelNedCovGnss;
  static const sbp_msg_vel_ned_cov_gnss_t &get(const sbp_msg_t &msg) {
    return msg.vel_ned_cov_gnss;
  }
  static sbp_msg_vel_ned_cov_gnss_t &get(sbp_msg_t &msg) {
    return msg.vel_ned_cov_gnss;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_vel_ned_cov_gnss_t &msg, sbp_write_fn_t write) {
    return sbp_msg_vel_ned_cov_gnss_send(state, sender_id, &msg, write);
  }
};

template <>
struct MessageTraits<sbp_msg_vel_ned_cov_t> {
  static constexpr sbp_msg_type_t id = SbpMsgVelNedCov;
  static const sbp_msg_vel_ned_cov_t &get(const sbp_msg_t &msg) {
    return msg.vel_ned_cov;
  }
  static sbp_msg_vel_ned_cov_t &get(sbp_msg_t &msg) { return msg.vel_ned_cov; }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_vel_ned_cov_t &msg, sbp_write_fn_t write) {
    return sbp_msg_vel_ned_cov_send(state, sender_id, &msg, write);
  }
};

template <>
struct MessageTraits<sbp_msg_vel_ned_dep_a_t> {
  static constexpr sbp_msg_type_t id = SbpMsgVelNedDepA;
  static const sbp_msg_vel_ned_dep_a_t &get(const sbp_msg_t &msg) {
    return msg.vel_ned_dep_a;
  }
  static sbp_msg_vel_ned_dep_a_t &get(sbp_msg_t &msg) {
    return msg.vel_ned_dep_a;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_vel_ned_dep_a_t &msg, sbp_write_fn_t write) {
    return sbp_msg_vel_ned_dep_a_send(state, sender_id, &msg, write);
  }
};

template <>
struct MessageTraits<sbp_msg_vel_ned_gnss_t> {
  static constexpr sbp_msg_type_t id = SbpMsgVelNedGnss;
  static const sbp_msg_vel_ned_gnss_t &get(const sbp_msg_t &msg) {
    return msg.vel_ned_gnss;
  }
  static sbp_msg_vel_ned_gnss_t &get(sbp_msg_t &msg) {
    return msg.vel_ned_gnss;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_vel_ned_gnss_t &msg, sbp_write_fn_t write) {
    return sbp_msg_vel_ned_gnss_send(state, sender_id, &msg, write);
  }
};

template <>
struct MessageTraits<sbp_msg_vel_ned_t> {
  static constexpr sbp_msg_type_t id = SbpMsgVelNed;
  static const sbp_msg_vel_ned_t &get(const sbp_msg_t &msg) {
    return msg.vel_ned;
  }
  static sbp_msg_vel_ned_t &get(sbp_msg_t &msg) { return msg.vel_ned; }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_vel_ned_t &msg, sbp_write_fn_t write) {
    return sbp_msg_vel_ned_send(state, sender_id, &msg, write);
  }
};

template <>
struct MessageTraits<sbp_msg_wheeltick_t> {
  static constexpr sbp_msg_type_t id = SbpMsgWheeltick;
  static const sbp_msg_wheeltick_t &get(const sbp_msg_t &msg) {
    return msg.wheeltick;
  }
  static sbp_msg_wheeltick_t &get(sbp_msg_t &msg) { return msg.wheeltick; }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_wheeltick_t &msg, sbp_write_fn_t write) {
    return sbp_msg_wheeltick_send(state, sender_id, &msg, write);
  }
};

}  // namespace sbp

#endif  // LIBSBP_CPP_MESSAGE_TRAITS_H
