/**
 * Copyright (C) 2021 Swift Navigation Inc.
 * Contact: https://support.swiftnav.com
 *
 * This source is subject to the license found in the file 'LICENSE' which must
 * be distributed together with this source. All other rights reserved.
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
#include <libsbp/acquisition.h>
#include <libsbp/bootload.h>
#include <libsbp/ext_events.h>
#include <libsbp/file_io.h>
#include <libsbp/flash.h>
#include <libsbp/gnss.h>
#include <libsbp/imu.h>
#include <libsbp/integrity.h>
#include <libsbp/linux.h>
#include <libsbp/logging.h>
#include <libsbp/mag.h>
#include <libsbp/navigation.h>
#include <libsbp/ndb.h>
#include <libsbp/observation.h>
#include <libsbp/orientation.h>
#include <libsbp/piksi.h>
#include <libsbp/profiling.h>
#include <libsbp/sbas.h>
#include <libsbp/sbp_msg.h>
#include <libsbp/sbp_msg_type.h>
#include <libsbp/settings.h>
#include <libsbp/signing.h>
#include <libsbp/solution_meta.h>
#include <libsbp/ssr.h>
#include <libsbp/system.h>
#include <libsbp/telemetry.h>
#include <libsbp/tracking.h>
#include <libsbp/user.h>
#include <libsbp/vehicle.h>

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
struct MessageTraits<sbp_msg_acknowledge_t> {
  static constexpr sbp_msg_type_t id = SbpMsgAcknowledge;
  static constexpr const char *name = "MSG_ACKNOWLEDGE";
  static const sbp_msg_acknowledge_t &get(const sbp_msg_t &msg) {
    return msg.acknowledge;
  }
  static sbp_msg_acknowledge_t &get(sbp_msg_t &msg) { return msg.acknowledge; }
  static void to_sbp_msg(const sbp_msg_acknowledge_t &msg, sbp_msg_t *sbp_msg) {
    sbp_msg->acknowledge = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_acknowledge_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.acknowledge = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_acknowledge_t &msg, sbp_write_fn_t write) {
    return sbp_msg_acknowledge_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_acknowledge_t &msg) {
    return sbp_msg_acknowledge_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_acknowledge_t *msg) {
    return sbp_msg_acknowledge_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_acknowledge_t &msg) {
    return sbp_msg_acknowledge_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_acq_result_dep_a_t> {
  static constexpr sbp_msg_type_t id = SbpMsgAcqResultDepA;
  static constexpr const char *name = "MSG_ACQ_RESULT_DEP_A";
  static const sbp_msg_acq_result_dep_a_t &get(const sbp_msg_t &msg) {
    return msg.acq_result_dep_a;
  }
  static sbp_msg_acq_result_dep_a_t &get(sbp_msg_t &msg) {
    return msg.acq_result_dep_a;
  }
  static void to_sbp_msg(const sbp_msg_acq_result_dep_a_t &msg,
                         sbp_msg_t *sbp_msg) {
    sbp_msg->acq_result_dep_a = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_acq_result_dep_a_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.acq_result_dep_a = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_acq_result_dep_a_t &msg, sbp_write_fn_t write) {
    return sbp_msg_acq_result_dep_a_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_acq_result_dep_a_t &msg) {
    return sbp_msg_acq_result_dep_a_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_acq_result_dep_a_t *msg) {
    return sbp_msg_acq_result_dep_a_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_acq_result_dep_a_t &msg) {
    return sbp_msg_acq_result_dep_a_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_acq_result_dep_b_t> {
  static constexpr sbp_msg_type_t id = SbpMsgAcqResultDepB;
  static constexpr const char *name = "MSG_ACQ_RESULT_DEP_B";
  static const sbp_msg_acq_result_dep_b_t &get(const sbp_msg_t &msg) {
    return msg.acq_result_dep_b;
  }
  static sbp_msg_acq_result_dep_b_t &get(sbp_msg_t &msg) {
    return msg.acq_result_dep_b;
  }
  static void to_sbp_msg(const sbp_msg_acq_result_dep_b_t &msg,
                         sbp_msg_t *sbp_msg) {
    sbp_msg->acq_result_dep_b = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_acq_result_dep_b_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.acq_result_dep_b = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_acq_result_dep_b_t &msg, sbp_write_fn_t write) {
    return sbp_msg_acq_result_dep_b_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_acq_result_dep_b_t &msg) {
    return sbp_msg_acq_result_dep_b_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_acq_result_dep_b_t *msg) {
    return sbp_msg_acq_result_dep_b_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_acq_result_dep_b_t &msg) {
    return sbp_msg_acq_result_dep_b_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_acq_result_dep_c_t> {
  static constexpr sbp_msg_type_t id = SbpMsgAcqResultDepC;
  static constexpr const char *name = "MSG_ACQ_RESULT_DEP_C";
  static const sbp_msg_acq_result_dep_c_t &get(const sbp_msg_t &msg) {
    return msg.acq_result_dep_c;
  }
  static sbp_msg_acq_result_dep_c_t &get(sbp_msg_t &msg) {
    return msg.acq_result_dep_c;
  }
  static void to_sbp_msg(const sbp_msg_acq_result_dep_c_t &msg,
                         sbp_msg_t *sbp_msg) {
    sbp_msg->acq_result_dep_c = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_acq_result_dep_c_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.acq_result_dep_c = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_acq_result_dep_c_t &msg, sbp_write_fn_t write) {
    return sbp_msg_acq_result_dep_c_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_acq_result_dep_c_t &msg) {
    return sbp_msg_acq_result_dep_c_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_acq_result_dep_c_t *msg) {
    return sbp_msg_acq_result_dep_c_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_acq_result_dep_c_t &msg) {
    return sbp_msg_acq_result_dep_c_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_acq_result_t> {
  static constexpr sbp_msg_type_t id = SbpMsgAcqResult;
  static constexpr const char *name = "MSG_ACQ_RESULT";
  static const sbp_msg_acq_result_t &get(const sbp_msg_t &msg) {
    return msg.acq_result;
  }
  static sbp_msg_acq_result_t &get(sbp_msg_t &msg) { return msg.acq_result; }
  static void to_sbp_msg(const sbp_msg_acq_result_t &msg, sbp_msg_t *sbp_msg) {
    sbp_msg->acq_result = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_acq_result_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.acq_result = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_acq_result_t &msg, sbp_write_fn_t write) {
    return sbp_msg_acq_result_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_acq_result_t &msg) {
    return sbp_msg_acq_result_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_acq_result_t *msg) {
    return sbp_msg_acq_result_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_acq_result_t &msg) {
    return sbp_msg_acq_result_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_acq_sv_profile_dep_t> {
  static constexpr sbp_msg_type_t id = SbpMsgAcqSvProfileDep;
  static constexpr const char *name = "MSG_ACQ_SV_PROFILE_DEP";
  static const sbp_msg_acq_sv_profile_dep_t &get(const sbp_msg_t &msg) {
    return msg.acq_sv_profile_dep;
  }
  static sbp_msg_acq_sv_profile_dep_t &get(sbp_msg_t &msg) {
    return msg.acq_sv_profile_dep;
  }
  static void to_sbp_msg(const sbp_msg_acq_sv_profile_dep_t &msg,
                         sbp_msg_t *sbp_msg) {
    sbp_msg->acq_sv_profile_dep = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_acq_sv_profile_dep_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.acq_sv_profile_dep = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_acq_sv_profile_dep_t &msg,
                 sbp_write_fn_t write) {
    return sbp_msg_acq_sv_profile_dep_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_acq_sv_profile_dep_t &msg) {
    return sbp_msg_acq_sv_profile_dep_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_acq_sv_profile_dep_t *msg) {
    return sbp_msg_acq_sv_profile_dep_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_acq_sv_profile_dep_t &msg) {
    return sbp_msg_acq_sv_profile_dep_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_acq_sv_profile_t> {
  static constexpr sbp_msg_type_t id = SbpMsgAcqSvProfile;
  static constexpr const char *name = "MSG_ACQ_SV_PROFILE";
  static const sbp_msg_acq_sv_profile_t &get(const sbp_msg_t &msg) {
    return msg.acq_sv_profile;
  }
  static sbp_msg_acq_sv_profile_t &get(sbp_msg_t &msg) {
    return msg.acq_sv_profile;
  }
  static void to_sbp_msg(const sbp_msg_acq_sv_profile_t &msg,
                         sbp_msg_t *sbp_msg) {
    sbp_msg->acq_sv_profile = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_acq_sv_profile_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.acq_sv_profile = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_acq_sv_profile_t &msg, sbp_write_fn_t write) {
    return sbp_msg_acq_sv_profile_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_acq_sv_profile_t &msg) {
    return sbp_msg_acq_sv_profile_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_acq_sv_profile_t *msg) {
    return sbp_msg_acq_sv_profile_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_acq_sv_profile_t &msg) {
    return sbp_msg_acq_sv_profile_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_aes_cmac_signature_t> {
  static constexpr sbp_msg_type_t id = SbpMsgAesCmacSignature;
  static constexpr const char *name = "MSG_AES_CMAC_SIGNATURE";
  static const sbp_msg_aes_cmac_signature_t &get(const sbp_msg_t &msg) {
    return msg.aes_cmac_signature;
  }
  static sbp_msg_aes_cmac_signature_t &get(sbp_msg_t &msg) {
    return msg.aes_cmac_signature;
  }
  static void to_sbp_msg(const sbp_msg_aes_cmac_signature_t &msg,
                         sbp_msg_t *sbp_msg) {
    sbp_msg->aes_cmac_signature = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_aes_cmac_signature_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.aes_cmac_signature = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_aes_cmac_signature_t &msg,
                 sbp_write_fn_t write) {
    return sbp_msg_aes_cmac_signature_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_aes_cmac_signature_t &msg) {
    return sbp_msg_aes_cmac_signature_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_aes_cmac_signature_t *msg) {
    return sbp_msg_aes_cmac_signature_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_aes_cmac_signature_t &msg) {
    return sbp_msg_aes_cmac_signature_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_age_corrections_t> {
  static constexpr sbp_msg_type_t id = SbpMsgAgeCorrections;
  static constexpr const char *name = "MSG_AGE_CORRECTIONS";
  static const sbp_msg_age_corrections_t &get(const sbp_msg_t &msg) {
    return msg.age_corrections;
  }
  static sbp_msg_age_corrections_t &get(sbp_msg_t &msg) {
    return msg.age_corrections;
  }
  static void to_sbp_msg(const sbp_msg_age_corrections_t &msg,
                         sbp_msg_t *sbp_msg) {
    sbp_msg->age_corrections = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_age_corrections_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.age_corrections = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_age_corrections_t &msg, sbp_write_fn_t write) {
    return sbp_msg_age_corrections_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_age_corrections_t &msg) {
    return sbp_msg_age_corrections_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_age_corrections_t *msg) {
    return sbp_msg_age_corrections_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_age_corrections_t &msg) {
    return sbp_msg_age_corrections_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_almanac_glo_dep_t> {
  static constexpr sbp_msg_type_t id = SbpMsgAlmanacGloDep;
  static constexpr const char *name = "MSG_ALMANAC_GLO_DEP";
  static const sbp_msg_almanac_glo_dep_t &get(const sbp_msg_t &msg) {
    return msg.almanac_glo_dep;
  }
  static sbp_msg_almanac_glo_dep_t &get(sbp_msg_t &msg) {
    return msg.almanac_glo_dep;
  }
  static void to_sbp_msg(const sbp_msg_almanac_glo_dep_t &msg,
                         sbp_msg_t *sbp_msg) {
    sbp_msg->almanac_glo_dep = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_almanac_glo_dep_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.almanac_glo_dep = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_almanac_glo_dep_t &msg, sbp_write_fn_t write) {
    return sbp_msg_almanac_glo_dep_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_almanac_glo_dep_t &msg) {
    return sbp_msg_almanac_glo_dep_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_almanac_glo_dep_t *msg) {
    return sbp_msg_almanac_glo_dep_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_almanac_glo_dep_t &msg) {
    return sbp_msg_almanac_glo_dep_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_almanac_glo_t> {
  static constexpr sbp_msg_type_t id = SbpMsgAlmanacGlo;
  static constexpr const char *name = "MSG_ALMANAC_GLO";
  static const sbp_msg_almanac_glo_t &get(const sbp_msg_t &msg) {
    return msg.almanac_glo;
  }
  static sbp_msg_almanac_glo_t &get(sbp_msg_t &msg) { return msg.almanac_glo; }
  static void to_sbp_msg(const sbp_msg_almanac_glo_t &msg, sbp_msg_t *sbp_msg) {
    sbp_msg->almanac_glo = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_almanac_glo_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.almanac_glo = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_almanac_glo_t &msg, sbp_write_fn_t write) {
    return sbp_msg_almanac_glo_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_almanac_glo_t &msg) {
    return sbp_msg_almanac_glo_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_almanac_glo_t *msg) {
    return sbp_msg_almanac_glo_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_almanac_glo_t &msg) {
    return sbp_msg_almanac_glo_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_almanac_gps_dep_t> {
  static constexpr sbp_msg_type_t id = SbpMsgAlmanacGpsDep;
  static constexpr const char *name = "MSG_ALMANAC_GPS_DEP";
  static const sbp_msg_almanac_gps_dep_t &get(const sbp_msg_t &msg) {
    return msg.almanac_gps_dep;
  }
  static sbp_msg_almanac_gps_dep_t &get(sbp_msg_t &msg) {
    return msg.almanac_gps_dep;
  }
  static void to_sbp_msg(const sbp_msg_almanac_gps_dep_t &msg,
                         sbp_msg_t *sbp_msg) {
    sbp_msg->almanac_gps_dep = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_almanac_gps_dep_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.almanac_gps_dep = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_almanac_gps_dep_t &msg, sbp_write_fn_t write) {
    return sbp_msg_almanac_gps_dep_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_almanac_gps_dep_t &msg) {
    return sbp_msg_almanac_gps_dep_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_almanac_gps_dep_t *msg) {
    return sbp_msg_almanac_gps_dep_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_almanac_gps_dep_t &msg) {
    return sbp_msg_almanac_gps_dep_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_almanac_gps_t> {
  static constexpr sbp_msg_type_t id = SbpMsgAlmanacGps;
  static constexpr const char *name = "MSG_ALMANAC_GPS";
  static const sbp_msg_almanac_gps_t &get(const sbp_msg_t &msg) {
    return msg.almanac_gps;
  }
  static sbp_msg_almanac_gps_t &get(sbp_msg_t &msg) { return msg.almanac_gps; }
  static void to_sbp_msg(const sbp_msg_almanac_gps_t &msg, sbp_msg_t *sbp_msg) {
    sbp_msg->almanac_gps = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_almanac_gps_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.almanac_gps = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_almanac_gps_t &msg, sbp_write_fn_t write) {
    return sbp_msg_almanac_gps_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_almanac_gps_t &msg) {
    return sbp_msg_almanac_gps_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_almanac_gps_t *msg) {
    return sbp_msg_almanac_gps_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_almanac_gps_t &msg) {
    return sbp_msg_almanac_gps_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_almanac_t> {
  static constexpr sbp_msg_type_t id = SbpMsgAlmanac;
  static constexpr const char *name = "MSG_ALMANAC";
  static const sbp_msg_almanac_t &get(const sbp_msg_t &msg) {
    return msg.almanac;
  }
  static sbp_msg_almanac_t &get(sbp_msg_t &msg) { return msg.almanac; }
  static void to_sbp_msg(const sbp_msg_almanac_t &msg, sbp_msg_t *sbp_msg) {
    sbp_msg->almanac = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_almanac_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.almanac = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_almanac_t &msg, sbp_write_fn_t write) {
    return sbp_msg_almanac_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_almanac_t &msg) {
    return sbp_msg_almanac_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_almanac_t *msg) {
    return sbp_msg_almanac_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_almanac_t &msg) {
    return sbp_msg_almanac_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_angular_rate_t> {
  static constexpr sbp_msg_type_t id = SbpMsgAngularRate;
  static constexpr const char *name = "MSG_ANGULAR_RATE";
  static const sbp_msg_angular_rate_t &get(const sbp_msg_t &msg) {
    return msg.angular_rate;
  }
  static sbp_msg_angular_rate_t &get(sbp_msg_t &msg) {
    return msg.angular_rate;
  }
  static void to_sbp_msg(const sbp_msg_angular_rate_t &msg,
                         sbp_msg_t *sbp_msg) {
    sbp_msg->angular_rate = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_angular_rate_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.angular_rate = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_angular_rate_t &msg, sbp_write_fn_t write) {
    return sbp_msg_angular_rate_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_angular_rate_t &msg) {
    return sbp_msg_angular_rate_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_angular_rate_t *msg) {
    return sbp_msg_angular_rate_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_angular_rate_t &msg) {
    return sbp_msg_angular_rate_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_base_pos_ecef_t> {
  static constexpr sbp_msg_type_t id = SbpMsgBasePosEcef;
  static constexpr const char *name = "MSG_BASE_POS_ECEF";
  static const sbp_msg_base_pos_ecef_t &get(const sbp_msg_t &msg) {
    return msg.base_pos_ecef;
  }
  static sbp_msg_base_pos_ecef_t &get(sbp_msg_t &msg) {
    return msg.base_pos_ecef;
  }
  static void to_sbp_msg(const sbp_msg_base_pos_ecef_t &msg,
                         sbp_msg_t *sbp_msg) {
    sbp_msg->base_pos_ecef = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_base_pos_ecef_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.base_pos_ecef = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_base_pos_ecef_t &msg, sbp_write_fn_t write) {
    return sbp_msg_base_pos_ecef_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_base_pos_ecef_t &msg) {
    return sbp_msg_base_pos_ecef_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_base_pos_ecef_t *msg) {
    return sbp_msg_base_pos_ecef_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_base_pos_ecef_t &msg) {
    return sbp_msg_base_pos_ecef_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_base_pos_llh_t> {
  static constexpr sbp_msg_type_t id = SbpMsgBasePosLlh;
  static constexpr const char *name = "MSG_BASE_POS_LLH";
  static const sbp_msg_base_pos_llh_t &get(const sbp_msg_t &msg) {
    return msg.base_pos_llh;
  }
  static sbp_msg_base_pos_llh_t &get(sbp_msg_t &msg) {
    return msg.base_pos_llh;
  }
  static void to_sbp_msg(const sbp_msg_base_pos_llh_t &msg,
                         sbp_msg_t *sbp_msg) {
    sbp_msg->base_pos_llh = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_base_pos_llh_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.base_pos_llh = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_base_pos_llh_t &msg, sbp_write_fn_t write) {
    return sbp_msg_base_pos_llh_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_base_pos_llh_t &msg) {
    return sbp_msg_base_pos_llh_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_base_pos_llh_t *msg) {
    return sbp_msg_base_pos_llh_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_base_pos_llh_t &msg) {
    return sbp_msg_base_pos_llh_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_baseline_ecef_dep_a_t> {
  static constexpr sbp_msg_type_t id = SbpMsgBaselineEcefDepA;
  static constexpr const char *name = "MSG_BASELINE_ECEF_DEP_A";
  static const sbp_msg_baseline_ecef_dep_a_t &get(const sbp_msg_t &msg) {
    return msg.baseline_ecef_dep_a;
  }
  static sbp_msg_baseline_ecef_dep_a_t &get(sbp_msg_t &msg) {
    return msg.baseline_ecef_dep_a;
  }
  static void to_sbp_msg(const sbp_msg_baseline_ecef_dep_a_t &msg,
                         sbp_msg_t *sbp_msg) {
    sbp_msg->baseline_ecef_dep_a = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_baseline_ecef_dep_a_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.baseline_ecef_dep_a = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_baseline_ecef_dep_a_t &msg,
                 sbp_write_fn_t write) {
    return sbp_msg_baseline_ecef_dep_a_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_baseline_ecef_dep_a_t &msg) {
    return sbp_msg_baseline_ecef_dep_a_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_baseline_ecef_dep_a_t *msg) {
    return sbp_msg_baseline_ecef_dep_a_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_baseline_ecef_dep_a_t &msg) {
    return sbp_msg_baseline_ecef_dep_a_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_baseline_ecef_t> {
  static constexpr sbp_msg_type_t id = SbpMsgBaselineEcef;
  static constexpr const char *name = "MSG_BASELINE_ECEF";
  static const sbp_msg_baseline_ecef_t &get(const sbp_msg_t &msg) {
    return msg.baseline_ecef;
  }
  static sbp_msg_baseline_ecef_t &get(sbp_msg_t &msg) {
    return msg.baseline_ecef;
  }
  static void to_sbp_msg(const sbp_msg_baseline_ecef_t &msg,
                         sbp_msg_t *sbp_msg) {
    sbp_msg->baseline_ecef = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_baseline_ecef_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.baseline_ecef = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_baseline_ecef_t &msg, sbp_write_fn_t write) {
    return sbp_msg_baseline_ecef_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_baseline_ecef_t &msg) {
    return sbp_msg_baseline_ecef_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_baseline_ecef_t *msg) {
    return sbp_msg_baseline_ecef_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_baseline_ecef_t &msg) {
    return sbp_msg_baseline_ecef_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_baseline_heading_dep_a_t> {
  static constexpr sbp_msg_type_t id = SbpMsgBaselineHeadingDepA;
  static constexpr const char *name = "MSG_BASELINE_HEADING_DEP_A";
  static const sbp_msg_baseline_heading_dep_a_t &get(const sbp_msg_t &msg) {
    return msg.baseline_heading_dep_a;
  }
  static sbp_msg_baseline_heading_dep_a_t &get(sbp_msg_t &msg) {
    return msg.baseline_heading_dep_a;
  }
  static void to_sbp_msg(const sbp_msg_baseline_heading_dep_a_t &msg,
                         sbp_msg_t *sbp_msg) {
    sbp_msg->baseline_heading_dep_a = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_baseline_heading_dep_a_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.baseline_heading_dep_a = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_baseline_heading_dep_a_t &msg,
                 sbp_write_fn_t write) {
    return sbp_msg_baseline_heading_dep_a_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_baseline_heading_dep_a_t &msg) {
    return sbp_msg_baseline_heading_dep_a_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_baseline_heading_dep_a_t *msg) {
    return sbp_msg_baseline_heading_dep_a_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_baseline_heading_dep_a_t &msg) {
    return sbp_msg_baseline_heading_dep_a_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_baseline_heading_t> {
  static constexpr sbp_msg_type_t id = SbpMsgBaselineHeading;
  static constexpr const char *name = "MSG_BASELINE_HEADING";
  static const sbp_msg_baseline_heading_t &get(const sbp_msg_t &msg) {
    return msg.baseline_heading;
  }
  static sbp_msg_baseline_heading_t &get(sbp_msg_t &msg) {
    return msg.baseline_heading;
  }
  static void to_sbp_msg(const sbp_msg_baseline_heading_t &msg,
                         sbp_msg_t *sbp_msg) {
    sbp_msg->baseline_heading = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_baseline_heading_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.baseline_heading = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_baseline_heading_t &msg, sbp_write_fn_t write) {
    return sbp_msg_baseline_heading_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_baseline_heading_t &msg) {
    return sbp_msg_baseline_heading_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_baseline_heading_t *msg) {
    return sbp_msg_baseline_heading_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_baseline_heading_t &msg) {
    return sbp_msg_baseline_heading_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_baseline_ned_dep_a_t> {
  static constexpr sbp_msg_type_t id = SbpMsgBaselineNedDepA;
  static constexpr const char *name = "MSG_BASELINE_NED_DEP_A";
  static const sbp_msg_baseline_ned_dep_a_t &get(const sbp_msg_t &msg) {
    return msg.baseline_ned_dep_a;
  }
  static sbp_msg_baseline_ned_dep_a_t &get(sbp_msg_t &msg) {
    return msg.baseline_ned_dep_a;
  }
  static void to_sbp_msg(const sbp_msg_baseline_ned_dep_a_t &msg,
                         sbp_msg_t *sbp_msg) {
    sbp_msg->baseline_ned_dep_a = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_baseline_ned_dep_a_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.baseline_ned_dep_a = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_baseline_ned_dep_a_t &msg,
                 sbp_write_fn_t write) {
    return sbp_msg_baseline_ned_dep_a_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_baseline_ned_dep_a_t &msg) {
    return sbp_msg_baseline_ned_dep_a_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_baseline_ned_dep_a_t *msg) {
    return sbp_msg_baseline_ned_dep_a_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_baseline_ned_dep_a_t &msg) {
    return sbp_msg_baseline_ned_dep_a_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_baseline_ned_t> {
  static constexpr sbp_msg_type_t id = SbpMsgBaselineNed;
  static constexpr const char *name = "MSG_BASELINE_NED";
  static const sbp_msg_baseline_ned_t &get(const sbp_msg_t &msg) {
    return msg.baseline_ned;
  }
  static sbp_msg_baseline_ned_t &get(sbp_msg_t &msg) {
    return msg.baseline_ned;
  }
  static void to_sbp_msg(const sbp_msg_baseline_ned_t &msg,
                         sbp_msg_t *sbp_msg) {
    sbp_msg->baseline_ned = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_baseline_ned_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.baseline_ned = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_baseline_ned_t &msg, sbp_write_fn_t write) {
    return sbp_msg_baseline_ned_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_baseline_ned_t &msg) {
    return sbp_msg_baseline_ned_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_baseline_ned_t *msg) {
    return sbp_msg_baseline_ned_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_baseline_ned_t &msg) {
    return sbp_msg_baseline_ned_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_bootloader_handshake_dep_a_t> {
  static constexpr sbp_msg_type_t id = SbpMsgBootloaderHandshakeDepA;
  static constexpr const char *name = "MSG_BOOTLOADER_HANDSHAKE_DEP_A";
  static const sbp_msg_bootloader_handshake_dep_a_t &get(const sbp_msg_t &msg) {
    return msg.bootloader_handshake_dep_a;
  }
  static sbp_msg_bootloader_handshake_dep_a_t &get(sbp_msg_t &msg) {
    return msg.bootloader_handshake_dep_a;
  }
  static void to_sbp_msg(const sbp_msg_bootloader_handshake_dep_a_t &msg,
                         sbp_msg_t *sbp_msg) {
    sbp_msg->bootloader_handshake_dep_a = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_bootloader_handshake_dep_a_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.bootloader_handshake_dep_a = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_bootloader_handshake_dep_a_t &msg,
                 sbp_write_fn_t write) {
    return sbp_msg_bootloader_handshake_dep_a_send(state, sender_id, &msg,
                                                   write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_bootloader_handshake_dep_a_t &msg) {
    return sbp_msg_bootloader_handshake_dep_a_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_bootloader_handshake_dep_a_t *msg) {
    return sbp_msg_bootloader_handshake_dep_a_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_bootloader_handshake_dep_a_t &msg) {
    return sbp_msg_bootloader_handshake_dep_a_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_bootloader_handshake_req_t> {
  static constexpr sbp_msg_type_t id = SbpMsgBootloaderHandshakeReq;
  static constexpr const char *name = "MSG_BOOTLOADER_HANDSHAKE_REQ";
  static const sbp_msg_bootloader_handshake_req_t &get(const sbp_msg_t &msg) {
    return msg.bootloader_handshake_req;
  }
  static sbp_msg_bootloader_handshake_req_t &get(sbp_msg_t &msg) {
    return msg.bootloader_handshake_req;
  }
  static void to_sbp_msg(const sbp_msg_bootloader_handshake_req_t &msg,
                         sbp_msg_t *sbp_msg) {
    sbp_msg->bootloader_handshake_req = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_bootloader_handshake_req_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.bootloader_handshake_req = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_bootloader_handshake_req_t &msg,
                 sbp_write_fn_t write) {
    return sbp_msg_bootloader_handshake_req_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_bootloader_handshake_req_t &msg) {
    return sbp_msg_bootloader_handshake_req_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_bootloader_handshake_req_t *msg) {
    return sbp_msg_bootloader_handshake_req_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_bootloader_handshake_req_t &msg) {
    return sbp_msg_bootloader_handshake_req_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_bootloader_handshake_resp_t> {
  static constexpr sbp_msg_type_t id = SbpMsgBootloaderHandshakeResp;
  static constexpr const char *name = "MSG_BOOTLOADER_HANDSHAKE_RESP";
  static const sbp_msg_bootloader_handshake_resp_t &get(const sbp_msg_t &msg) {
    return msg.bootloader_handshake_resp;
  }
  static sbp_msg_bootloader_handshake_resp_t &get(sbp_msg_t &msg) {
    return msg.bootloader_handshake_resp;
  }
  static void to_sbp_msg(const sbp_msg_bootloader_handshake_resp_t &msg,
                         sbp_msg_t *sbp_msg) {
    sbp_msg->bootloader_handshake_resp = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_bootloader_handshake_resp_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.bootloader_handshake_resp = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_bootloader_handshake_resp_t &msg,
                 sbp_write_fn_t write) {
    return sbp_msg_bootloader_handshake_resp_send(state, sender_id, &msg,
                                                  write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_bootloader_handshake_resp_t &msg) {
    return sbp_msg_bootloader_handshake_resp_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_bootloader_handshake_resp_t *msg) {
    return sbp_msg_bootloader_handshake_resp_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_bootloader_handshake_resp_t &msg) {
    return sbp_msg_bootloader_handshake_resp_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_bootloader_jump_to_app_t> {
  static constexpr sbp_msg_type_t id = SbpMsgBootloaderJumpToApp;
  static constexpr const char *name = "MSG_BOOTLOADER_JUMP_TO_APP";
  static const sbp_msg_bootloader_jump_to_app_t &get(const sbp_msg_t &msg) {
    return msg.bootloader_jump_to_app;
  }
  static sbp_msg_bootloader_jump_to_app_t &get(sbp_msg_t &msg) {
    return msg.bootloader_jump_to_app;
  }
  static void to_sbp_msg(const sbp_msg_bootloader_jump_to_app_t &msg,
                         sbp_msg_t *sbp_msg) {
    sbp_msg->bootloader_jump_to_app = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_bootloader_jump_to_app_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.bootloader_jump_to_app = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_bootloader_jump_to_app_t &msg,
                 sbp_write_fn_t write) {
    return sbp_msg_bootloader_jump_to_app_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_bootloader_jump_to_app_t &msg) {
    return sbp_msg_bootloader_jump_to_app_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_bootloader_jump_to_app_t *msg) {
    return sbp_msg_bootloader_jump_to_app_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_bootloader_jump_to_app_t &msg) {
    return sbp_msg_bootloader_jump_to_app_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_cell_modem_status_t> {
  static constexpr sbp_msg_type_t id = SbpMsgCellModemStatus;
  static constexpr const char *name = "MSG_CELL_MODEM_STATUS";
  static const sbp_msg_cell_modem_status_t &get(const sbp_msg_t &msg) {
    return msg.cell_modem_status;
  }
  static sbp_msg_cell_modem_status_t &get(sbp_msg_t &msg) {
    return msg.cell_modem_status;
  }
  static void to_sbp_msg(const sbp_msg_cell_modem_status_t &msg,
                         sbp_msg_t *sbp_msg) {
    sbp_msg->cell_modem_status = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_cell_modem_status_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.cell_modem_status = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_cell_modem_status_t &msg, sbp_write_fn_t write) {
    return sbp_msg_cell_modem_status_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_cell_modem_status_t &msg) {
    return sbp_msg_cell_modem_status_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_cell_modem_status_t *msg) {
    return sbp_msg_cell_modem_status_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_cell_modem_status_t &msg) {
    return sbp_msg_cell_modem_status_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_certificate_chain_dep_t> {
  static constexpr sbp_msg_type_t id = SbpMsgCertificateChainDep;
  static constexpr const char *name = "MSG_CERTIFICATE_CHAIN_DEP";
  static const sbp_msg_certificate_chain_dep_t &get(const sbp_msg_t &msg) {
    return msg.certificate_chain_dep;
  }
  static sbp_msg_certificate_chain_dep_t &get(sbp_msg_t &msg) {
    return msg.certificate_chain_dep;
  }
  static void to_sbp_msg(const sbp_msg_certificate_chain_dep_t &msg,
                         sbp_msg_t *sbp_msg) {
    sbp_msg->certificate_chain_dep = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_certificate_chain_dep_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.certificate_chain_dep = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_certificate_chain_dep_t &msg,
                 sbp_write_fn_t write) {
    return sbp_msg_certificate_chain_dep_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_certificate_chain_dep_t &msg) {
    return sbp_msg_certificate_chain_dep_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_certificate_chain_dep_t *msg) {
    return sbp_msg_certificate_chain_dep_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_certificate_chain_dep_t &msg) {
    return sbp_msg_certificate_chain_dep_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_certificate_chain_t> {
  static constexpr sbp_msg_type_t id = SbpMsgCertificateChain;
  static constexpr const char *name = "MSG_CERTIFICATE_CHAIN";
  static const sbp_msg_certificate_chain_t &get(const sbp_msg_t &msg) {
    return msg.certificate_chain;
  }
  static sbp_msg_certificate_chain_t &get(sbp_msg_t &msg) {
    return msg.certificate_chain;
  }
  static void to_sbp_msg(const sbp_msg_certificate_chain_t &msg,
                         sbp_msg_t *sbp_msg) {
    sbp_msg->certificate_chain = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_certificate_chain_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.certificate_chain = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_certificate_chain_t &msg, sbp_write_fn_t write) {
    return sbp_msg_certificate_chain_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_certificate_chain_t &msg) {
    return sbp_msg_certificate_chain_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_certificate_chain_t *msg) {
    return sbp_msg_certificate_chain_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_certificate_chain_t &msg) {
    return sbp_msg_certificate_chain_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_command_output_t> {
  static constexpr sbp_msg_type_t id = SbpMsgCommandOutput;
  static constexpr const char *name = "MSG_COMMAND_OUTPUT";
  static const sbp_msg_command_output_t &get(const sbp_msg_t &msg) {
    return msg.command_output;
  }
  static sbp_msg_command_output_t &get(sbp_msg_t &msg) {
    return msg.command_output;
  }
  static void to_sbp_msg(const sbp_msg_command_output_t &msg,
                         sbp_msg_t *sbp_msg) {
    sbp_msg->command_output = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_command_output_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.command_output = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_command_output_t &msg, sbp_write_fn_t write) {
    return sbp_msg_command_output_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_command_output_t &msg) {
    return sbp_msg_command_output_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_command_output_t *msg) {
    return sbp_msg_command_output_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_command_output_t &msg) {
    return sbp_msg_command_output_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_command_req_t> {
  static constexpr sbp_msg_type_t id = SbpMsgCommandReq;
  static constexpr const char *name = "MSG_COMMAND_REQ";
  static const sbp_msg_command_req_t &get(const sbp_msg_t &msg) {
    return msg.command_req;
  }
  static sbp_msg_command_req_t &get(sbp_msg_t &msg) { return msg.command_req; }
  static void to_sbp_msg(const sbp_msg_command_req_t &msg, sbp_msg_t *sbp_msg) {
    sbp_msg->command_req = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_command_req_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.command_req = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_command_req_t &msg, sbp_write_fn_t write) {
    return sbp_msg_command_req_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_command_req_t &msg) {
    return sbp_msg_command_req_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_command_req_t *msg) {
    return sbp_msg_command_req_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_command_req_t &msg) {
    return sbp_msg_command_req_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_command_resp_t> {
  static constexpr sbp_msg_type_t id = SbpMsgCommandResp;
  static constexpr const char *name = "MSG_COMMAND_RESP";
  static const sbp_msg_command_resp_t &get(const sbp_msg_t &msg) {
    return msg.command_resp;
  }
  static sbp_msg_command_resp_t &get(sbp_msg_t &msg) {
    return msg.command_resp;
  }
  static void to_sbp_msg(const sbp_msg_command_resp_t &msg,
                         sbp_msg_t *sbp_msg) {
    sbp_msg->command_resp = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_command_resp_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.command_resp = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_command_resp_t &msg, sbp_write_fn_t write) {
    return sbp_msg_command_resp_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_command_resp_t &msg) {
    return sbp_msg_command_resp_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_command_resp_t *msg) {
    return sbp_msg_command_resp_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_command_resp_t &msg) {
    return sbp_msg_command_resp_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_csac_telemetry_labels_t> {
  static constexpr sbp_msg_type_t id = SbpMsgCsacTelemetryLabels;
  static constexpr const char *name = "MSG_CSAC_TELEMETRY_LABELS";
  static const sbp_msg_csac_telemetry_labels_t &get(const sbp_msg_t &msg) {
    return msg.csac_telemetry_labels;
  }
  static sbp_msg_csac_telemetry_labels_t &get(sbp_msg_t &msg) {
    return msg.csac_telemetry_labels;
  }
  static void to_sbp_msg(const sbp_msg_csac_telemetry_labels_t &msg,
                         sbp_msg_t *sbp_msg) {
    sbp_msg->csac_telemetry_labels = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_csac_telemetry_labels_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.csac_telemetry_labels = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_csac_telemetry_labels_t &msg,
                 sbp_write_fn_t write) {
    return sbp_msg_csac_telemetry_labels_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_csac_telemetry_labels_t &msg) {
    return sbp_msg_csac_telemetry_labels_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_csac_telemetry_labels_t *msg) {
    return sbp_msg_csac_telemetry_labels_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_csac_telemetry_labels_t &msg) {
    return sbp_msg_csac_telemetry_labels_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_csac_telemetry_t> {
  static constexpr sbp_msg_type_t id = SbpMsgCsacTelemetry;
  static constexpr const char *name = "MSG_CSAC_TELEMETRY";
  static const sbp_msg_csac_telemetry_t &get(const sbp_msg_t &msg) {
    return msg.csac_telemetry;
  }
  static sbp_msg_csac_telemetry_t &get(sbp_msg_t &msg) {
    return msg.csac_telemetry;
  }
  static void to_sbp_msg(const sbp_msg_csac_telemetry_t &msg,
                         sbp_msg_t *sbp_msg) {
    sbp_msg->csac_telemetry = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_csac_telemetry_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.csac_telemetry = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_csac_telemetry_t &msg, sbp_write_fn_t write) {
    return sbp_msg_csac_telemetry_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_csac_telemetry_t &msg) {
    return sbp_msg_csac_telemetry_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_csac_telemetry_t *msg) {
    return sbp_msg_csac_telemetry_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_csac_telemetry_t &msg) {
    return sbp_msg_csac_telemetry_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_cw_results_t> {
  static constexpr sbp_msg_type_t id = SbpMsgCwResults;
  static constexpr const char *name = "MSG_CW_RESULTS";
  static const sbp_msg_cw_results_t &get(const sbp_msg_t &msg) {
    return msg.cw_results;
  }
  static sbp_msg_cw_results_t &get(sbp_msg_t &msg) { return msg.cw_results; }
  static void to_sbp_msg(const sbp_msg_cw_results_t &msg, sbp_msg_t *sbp_msg) {
    sbp_msg->cw_results = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_cw_results_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.cw_results = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_cw_results_t &msg, sbp_write_fn_t write) {
    return sbp_msg_cw_results_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_cw_results_t &msg) {
    return sbp_msg_cw_results_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_cw_results_t *msg) {
    return sbp_msg_cw_results_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_cw_results_t &msg) {
    return sbp_msg_cw_results_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_cw_start_t> {
  static constexpr sbp_msg_type_t id = SbpMsgCwStart;
  static constexpr const char *name = "MSG_CW_START";
  static const sbp_msg_cw_start_t &get(const sbp_msg_t &msg) {
    return msg.cw_start;
  }
  static sbp_msg_cw_start_t &get(sbp_msg_t &msg) { return msg.cw_start; }
  static void to_sbp_msg(const sbp_msg_cw_start_t &msg, sbp_msg_t *sbp_msg) {
    sbp_msg->cw_start = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_cw_start_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.cw_start = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_cw_start_t &msg, sbp_write_fn_t write) {
    return sbp_msg_cw_start_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_cw_start_t &msg) {
    return sbp_msg_cw_start_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_cw_start_t *msg) {
    return sbp_msg_cw_start_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_cw_start_t &msg) {
    return sbp_msg_cw_start_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_device_monitor_t> {
  static constexpr sbp_msg_type_t id = SbpMsgDeviceMonitor;
  static constexpr const char *name = "MSG_DEVICE_MONITOR";
  static const sbp_msg_device_monitor_t &get(const sbp_msg_t &msg) {
    return msg.device_monitor;
  }
  static sbp_msg_device_monitor_t &get(sbp_msg_t &msg) {
    return msg.device_monitor;
  }
  static void to_sbp_msg(const sbp_msg_device_monitor_t &msg,
                         sbp_msg_t *sbp_msg) {
    sbp_msg->device_monitor = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_device_monitor_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.device_monitor = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_device_monitor_t &msg, sbp_write_fn_t write) {
    return sbp_msg_device_monitor_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_device_monitor_t &msg) {
    return sbp_msg_device_monitor_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_device_monitor_t *msg) {
    return sbp_msg_device_monitor_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_device_monitor_t &msg) {
    return sbp_msg_device_monitor_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_dgnss_status_t> {
  static constexpr sbp_msg_type_t id = SbpMsgDgnssStatus;
  static constexpr const char *name = "MSG_DGNSS_STATUS";
  static const sbp_msg_dgnss_status_t &get(const sbp_msg_t &msg) {
    return msg.dgnss_status;
  }
  static sbp_msg_dgnss_status_t &get(sbp_msg_t &msg) {
    return msg.dgnss_status;
  }
  static void to_sbp_msg(const sbp_msg_dgnss_status_t &msg,
                         sbp_msg_t *sbp_msg) {
    sbp_msg->dgnss_status = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_dgnss_status_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.dgnss_status = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_dgnss_status_t &msg, sbp_write_fn_t write) {
    return sbp_msg_dgnss_status_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_dgnss_status_t &msg) {
    return sbp_msg_dgnss_status_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_dgnss_status_t *msg) {
    return sbp_msg_dgnss_status_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_dgnss_status_t &msg) {
    return sbp_msg_dgnss_status_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_dops_dep_a_t> {
  static constexpr sbp_msg_type_t id = SbpMsgDopsDepA;
  static constexpr const char *name = "MSG_DOPS_DEP_A";
  static const sbp_msg_dops_dep_a_t &get(const sbp_msg_t &msg) {
    return msg.dops_dep_a;
  }
  static sbp_msg_dops_dep_a_t &get(sbp_msg_t &msg) { return msg.dops_dep_a; }
  static void to_sbp_msg(const sbp_msg_dops_dep_a_t &msg, sbp_msg_t *sbp_msg) {
    sbp_msg->dops_dep_a = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_dops_dep_a_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.dops_dep_a = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_dops_dep_a_t &msg, sbp_write_fn_t write) {
    return sbp_msg_dops_dep_a_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_dops_dep_a_t &msg) {
    return sbp_msg_dops_dep_a_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_dops_dep_a_t *msg) {
    return sbp_msg_dops_dep_a_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_dops_dep_a_t &msg) {
    return sbp_msg_dops_dep_a_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_dops_t> {
  static constexpr sbp_msg_type_t id = SbpMsgDops;
  static constexpr const char *name = "MSG_DOPS";
  static const sbp_msg_dops_t &get(const sbp_msg_t &msg) { return msg.dops; }
  static sbp_msg_dops_t &get(sbp_msg_t &msg) { return msg.dops; }
  static void to_sbp_msg(const sbp_msg_dops_t &msg, sbp_msg_t *sbp_msg) {
    sbp_msg->dops = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_dops_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.dops = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_dops_t &msg,
                 sbp_write_fn_t write) {
    return sbp_msg_dops_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_dops_t &msg) {
    return sbp_msg_dops_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_dops_t *msg) {
    return sbp_msg_dops_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_dops_t &msg) {
    return sbp_msg_dops_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_ecdsa_certificate_t> {
  static constexpr sbp_msg_type_t id = SbpMsgEcdsaCertificate;
  static constexpr const char *name = "MSG_ECDSA_CERTIFICATE";
  static const sbp_msg_ecdsa_certificate_t &get(const sbp_msg_t &msg) {
    return msg.ecdsa_certificate;
  }
  static sbp_msg_ecdsa_certificate_t &get(sbp_msg_t &msg) {
    return msg.ecdsa_certificate;
  }
  static void to_sbp_msg(const sbp_msg_ecdsa_certificate_t &msg,
                         sbp_msg_t *sbp_msg) {
    sbp_msg->ecdsa_certificate = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_ecdsa_certificate_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.ecdsa_certificate = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_ecdsa_certificate_t &msg, sbp_write_fn_t write) {
    return sbp_msg_ecdsa_certificate_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_ecdsa_certificate_t &msg) {
    return sbp_msg_ecdsa_certificate_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_ecdsa_certificate_t *msg) {
    return sbp_msg_ecdsa_certificate_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_ecdsa_certificate_t &msg) {
    return sbp_msg_ecdsa_certificate_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_ecdsa_signature_dep_a_t> {
  static constexpr sbp_msg_type_t id = SbpMsgEcdsaSignatureDepA;
  static constexpr const char *name = "MSG_ECDSA_SIGNATURE_DEP_A";
  static const sbp_msg_ecdsa_signature_dep_a_t &get(const sbp_msg_t &msg) {
    return msg.ecdsa_signature_dep_a;
  }
  static sbp_msg_ecdsa_signature_dep_a_t &get(sbp_msg_t &msg) {
    return msg.ecdsa_signature_dep_a;
  }
  static void to_sbp_msg(const sbp_msg_ecdsa_signature_dep_a_t &msg,
                         sbp_msg_t *sbp_msg) {
    sbp_msg->ecdsa_signature_dep_a = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_ecdsa_signature_dep_a_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.ecdsa_signature_dep_a = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_ecdsa_signature_dep_a_t &msg,
                 sbp_write_fn_t write) {
    return sbp_msg_ecdsa_signature_dep_a_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_ecdsa_signature_dep_a_t &msg) {
    return sbp_msg_ecdsa_signature_dep_a_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_ecdsa_signature_dep_a_t *msg) {
    return sbp_msg_ecdsa_signature_dep_a_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_ecdsa_signature_dep_a_t &msg) {
    return sbp_msg_ecdsa_signature_dep_a_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_ecdsa_signature_dep_b_t> {
  static constexpr sbp_msg_type_t id = SbpMsgEcdsaSignatureDepB;
  static constexpr const char *name = "MSG_ECDSA_SIGNATURE_DEP_B";
  static const sbp_msg_ecdsa_signature_dep_b_t &get(const sbp_msg_t &msg) {
    return msg.ecdsa_signature_dep_b;
  }
  static sbp_msg_ecdsa_signature_dep_b_t &get(sbp_msg_t &msg) {
    return msg.ecdsa_signature_dep_b;
  }
  static void to_sbp_msg(const sbp_msg_ecdsa_signature_dep_b_t &msg,
                         sbp_msg_t *sbp_msg) {
    sbp_msg->ecdsa_signature_dep_b = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_ecdsa_signature_dep_b_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.ecdsa_signature_dep_b = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_ecdsa_signature_dep_b_t &msg,
                 sbp_write_fn_t write) {
    return sbp_msg_ecdsa_signature_dep_b_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_ecdsa_signature_dep_b_t &msg) {
    return sbp_msg_ecdsa_signature_dep_b_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_ecdsa_signature_dep_b_t *msg) {
    return sbp_msg_ecdsa_signature_dep_b_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_ecdsa_signature_dep_b_t &msg) {
    return sbp_msg_ecdsa_signature_dep_b_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_ecdsa_signature_t> {
  static constexpr sbp_msg_type_t id = SbpMsgEcdsaSignature;
  static constexpr const char *name = "MSG_ECDSA_SIGNATURE";
  static const sbp_msg_ecdsa_signature_t &get(const sbp_msg_t &msg) {
    return msg.ecdsa_signature;
  }
  static sbp_msg_ecdsa_signature_t &get(sbp_msg_t &msg) {
    return msg.ecdsa_signature;
  }
  static void to_sbp_msg(const sbp_msg_ecdsa_signature_t &msg,
                         sbp_msg_t *sbp_msg) {
    sbp_msg->ecdsa_signature = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_ecdsa_signature_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.ecdsa_signature = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_ecdsa_signature_t &msg, sbp_write_fn_t write) {
    return sbp_msg_ecdsa_signature_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_ecdsa_signature_t &msg) {
    return sbp_msg_ecdsa_signature_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_ecdsa_signature_t *msg) {
    return sbp_msg_ecdsa_signature_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_ecdsa_signature_t &msg) {
    return sbp_msg_ecdsa_signature_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_ed25519_certificate_dep_t> {
  static constexpr sbp_msg_type_t id = SbpMsgEd25519CertificateDep;
  static constexpr const char *name = "MSG_ED25519_CERTIFICATE_DEP";
  static const sbp_msg_ed25519_certificate_dep_t &get(const sbp_msg_t &msg) {
    return msg.ed25519_certificate_dep;
  }
  static sbp_msg_ed25519_certificate_dep_t &get(sbp_msg_t &msg) {
    return msg.ed25519_certificate_dep;
  }
  static void to_sbp_msg(const sbp_msg_ed25519_certificate_dep_t &msg,
                         sbp_msg_t *sbp_msg) {
    sbp_msg->ed25519_certificate_dep = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_ed25519_certificate_dep_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.ed25519_certificate_dep = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_ed25519_certificate_dep_t &msg,
                 sbp_write_fn_t write) {
    return sbp_msg_ed25519_certificate_dep_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_ed25519_certificate_dep_t &msg) {
    return sbp_msg_ed25519_certificate_dep_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_ed25519_certificate_dep_t *msg) {
    return sbp_msg_ed25519_certificate_dep_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_ed25519_certificate_dep_t &msg) {
    return sbp_msg_ed25519_certificate_dep_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_ed25519_signature_dep_a_t> {
  static constexpr sbp_msg_type_t id = SbpMsgEd25519SignatureDepA;
  static constexpr const char *name = "MSG_ED25519_SIGNATURE_DEP_A";
  static const sbp_msg_ed25519_signature_dep_a_t &get(const sbp_msg_t &msg) {
    return msg.ed25519_signature_dep_a;
  }
  static sbp_msg_ed25519_signature_dep_a_t &get(sbp_msg_t &msg) {
    return msg.ed25519_signature_dep_a;
  }
  static void to_sbp_msg(const sbp_msg_ed25519_signature_dep_a_t &msg,
                         sbp_msg_t *sbp_msg) {
    sbp_msg->ed25519_signature_dep_a = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_ed25519_signature_dep_a_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.ed25519_signature_dep_a = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_ed25519_signature_dep_a_t &msg,
                 sbp_write_fn_t write) {
    return sbp_msg_ed25519_signature_dep_a_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_ed25519_signature_dep_a_t &msg) {
    return sbp_msg_ed25519_signature_dep_a_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_ed25519_signature_dep_a_t *msg) {
    return sbp_msg_ed25519_signature_dep_a_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_ed25519_signature_dep_a_t &msg) {
    return sbp_msg_ed25519_signature_dep_a_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_ed25519_signature_dep_b_t> {
  static constexpr sbp_msg_type_t id = SbpMsgEd25519SignatureDepB;
  static constexpr const char *name = "MSG_ED25519_SIGNATURE_DEP_B";
  static const sbp_msg_ed25519_signature_dep_b_t &get(const sbp_msg_t &msg) {
    return msg.ed25519_signature_dep_b;
  }
  static sbp_msg_ed25519_signature_dep_b_t &get(sbp_msg_t &msg) {
    return msg.ed25519_signature_dep_b;
  }
  static void to_sbp_msg(const sbp_msg_ed25519_signature_dep_b_t &msg,
                         sbp_msg_t *sbp_msg) {
    sbp_msg->ed25519_signature_dep_b = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_ed25519_signature_dep_b_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.ed25519_signature_dep_b = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_ed25519_signature_dep_b_t &msg,
                 sbp_write_fn_t write) {
    return sbp_msg_ed25519_signature_dep_b_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_ed25519_signature_dep_b_t &msg) {
    return sbp_msg_ed25519_signature_dep_b_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_ed25519_signature_dep_b_t *msg) {
    return sbp_msg_ed25519_signature_dep_b_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_ed25519_signature_dep_b_t &msg) {
    return sbp_msg_ed25519_signature_dep_b_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_ephemeris_bds_t> {
  static constexpr sbp_msg_type_t id = SbpMsgEphemerisBds;
  static constexpr const char *name = "MSG_EPHEMERIS_BDS";
  static const sbp_msg_ephemeris_bds_t &get(const sbp_msg_t &msg) {
    return msg.ephemeris_bds;
  }
  static sbp_msg_ephemeris_bds_t &get(sbp_msg_t &msg) {
    return msg.ephemeris_bds;
  }
  static void to_sbp_msg(const sbp_msg_ephemeris_bds_t &msg,
                         sbp_msg_t *sbp_msg) {
    sbp_msg->ephemeris_bds = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_ephemeris_bds_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.ephemeris_bds = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_ephemeris_bds_t &msg, sbp_write_fn_t write) {
    return sbp_msg_ephemeris_bds_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_ephemeris_bds_t &msg) {
    return sbp_msg_ephemeris_bds_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_ephemeris_bds_t *msg) {
    return sbp_msg_ephemeris_bds_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_ephemeris_bds_t &msg) {
    return sbp_msg_ephemeris_bds_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_ephemeris_dep_a_t> {
  static constexpr sbp_msg_type_t id = SbpMsgEphemerisDepA;
  static constexpr const char *name = "MSG_EPHEMERIS_DEP_A";
  static const sbp_msg_ephemeris_dep_a_t &get(const sbp_msg_t &msg) {
    return msg.ephemeris_dep_a;
  }
  static sbp_msg_ephemeris_dep_a_t &get(sbp_msg_t &msg) {
    return msg.ephemeris_dep_a;
  }
  static void to_sbp_msg(const sbp_msg_ephemeris_dep_a_t &msg,
                         sbp_msg_t *sbp_msg) {
    sbp_msg->ephemeris_dep_a = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_ephemeris_dep_a_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.ephemeris_dep_a = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_ephemeris_dep_a_t &msg, sbp_write_fn_t write) {
    return sbp_msg_ephemeris_dep_a_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_ephemeris_dep_a_t &msg) {
    return sbp_msg_ephemeris_dep_a_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_ephemeris_dep_a_t *msg) {
    return sbp_msg_ephemeris_dep_a_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_ephemeris_dep_a_t &msg) {
    return sbp_msg_ephemeris_dep_a_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_ephemeris_dep_b_t> {
  static constexpr sbp_msg_type_t id = SbpMsgEphemerisDepB;
  static constexpr const char *name = "MSG_EPHEMERIS_DEP_B";
  static const sbp_msg_ephemeris_dep_b_t &get(const sbp_msg_t &msg) {
    return msg.ephemeris_dep_b;
  }
  static sbp_msg_ephemeris_dep_b_t &get(sbp_msg_t &msg) {
    return msg.ephemeris_dep_b;
  }
  static void to_sbp_msg(const sbp_msg_ephemeris_dep_b_t &msg,
                         sbp_msg_t *sbp_msg) {
    sbp_msg->ephemeris_dep_b = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_ephemeris_dep_b_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.ephemeris_dep_b = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_ephemeris_dep_b_t &msg, sbp_write_fn_t write) {
    return sbp_msg_ephemeris_dep_b_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_ephemeris_dep_b_t &msg) {
    return sbp_msg_ephemeris_dep_b_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_ephemeris_dep_b_t *msg) {
    return sbp_msg_ephemeris_dep_b_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_ephemeris_dep_b_t &msg) {
    return sbp_msg_ephemeris_dep_b_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_ephemeris_dep_c_t> {
  static constexpr sbp_msg_type_t id = SbpMsgEphemerisDepC;
  static constexpr const char *name = "MSG_EPHEMERIS_DEP_C";
  static const sbp_msg_ephemeris_dep_c_t &get(const sbp_msg_t &msg) {
    return msg.ephemeris_dep_c;
  }
  static sbp_msg_ephemeris_dep_c_t &get(sbp_msg_t &msg) {
    return msg.ephemeris_dep_c;
  }
  static void to_sbp_msg(const sbp_msg_ephemeris_dep_c_t &msg,
                         sbp_msg_t *sbp_msg) {
    sbp_msg->ephemeris_dep_c = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_ephemeris_dep_c_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.ephemeris_dep_c = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_ephemeris_dep_c_t &msg, sbp_write_fn_t write) {
    return sbp_msg_ephemeris_dep_c_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_ephemeris_dep_c_t &msg) {
    return sbp_msg_ephemeris_dep_c_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_ephemeris_dep_c_t *msg) {
    return sbp_msg_ephemeris_dep_c_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_ephemeris_dep_c_t &msg) {
    return sbp_msg_ephemeris_dep_c_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_ephemeris_dep_d_t> {
  static constexpr sbp_msg_type_t id = SbpMsgEphemerisDepD;
  static constexpr const char *name = "MSG_EPHEMERIS_DEP_D";
  static const sbp_msg_ephemeris_dep_d_t &get(const sbp_msg_t &msg) {
    return msg.ephemeris_dep_d;
  }
  static sbp_msg_ephemeris_dep_d_t &get(sbp_msg_t &msg) {
    return msg.ephemeris_dep_d;
  }
  static void to_sbp_msg(const sbp_msg_ephemeris_dep_d_t &msg,
                         sbp_msg_t *sbp_msg) {
    sbp_msg->ephemeris_dep_d = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_ephemeris_dep_d_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.ephemeris_dep_d = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_ephemeris_dep_d_t &msg, sbp_write_fn_t write) {
    return sbp_msg_ephemeris_dep_d_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_ephemeris_dep_d_t &msg) {
    return sbp_msg_ephemeris_dep_d_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_ephemeris_dep_d_t *msg) {
    return sbp_msg_ephemeris_dep_d_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_ephemeris_dep_d_t &msg) {
    return sbp_msg_ephemeris_dep_d_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_ephemeris_gal_dep_a_t> {
  static constexpr sbp_msg_type_t id = SbpMsgEphemerisGalDepA;
  static constexpr const char *name = "MSG_EPHEMERIS_GAL_DEP_A";
  static const sbp_msg_ephemeris_gal_dep_a_t &get(const sbp_msg_t &msg) {
    return msg.ephemeris_gal_dep_a;
  }
  static sbp_msg_ephemeris_gal_dep_a_t &get(sbp_msg_t &msg) {
    return msg.ephemeris_gal_dep_a;
  }
  static void to_sbp_msg(const sbp_msg_ephemeris_gal_dep_a_t &msg,
                         sbp_msg_t *sbp_msg) {
    sbp_msg->ephemeris_gal_dep_a = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_ephemeris_gal_dep_a_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.ephemeris_gal_dep_a = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_ephemeris_gal_dep_a_t &msg,
                 sbp_write_fn_t write) {
    return sbp_msg_ephemeris_gal_dep_a_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_ephemeris_gal_dep_a_t &msg) {
    return sbp_msg_ephemeris_gal_dep_a_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_ephemeris_gal_dep_a_t *msg) {
    return sbp_msg_ephemeris_gal_dep_a_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_ephemeris_gal_dep_a_t &msg) {
    return sbp_msg_ephemeris_gal_dep_a_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_ephemeris_gal_t> {
  static constexpr sbp_msg_type_t id = SbpMsgEphemerisGal;
  static constexpr const char *name = "MSG_EPHEMERIS_GAL";
  static const sbp_msg_ephemeris_gal_t &get(const sbp_msg_t &msg) {
    return msg.ephemeris_gal;
  }
  static sbp_msg_ephemeris_gal_t &get(sbp_msg_t &msg) {
    return msg.ephemeris_gal;
  }
  static void to_sbp_msg(const sbp_msg_ephemeris_gal_t &msg,
                         sbp_msg_t *sbp_msg) {
    sbp_msg->ephemeris_gal = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_ephemeris_gal_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.ephemeris_gal = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_ephemeris_gal_t &msg, sbp_write_fn_t write) {
    return sbp_msg_ephemeris_gal_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_ephemeris_gal_t &msg) {
    return sbp_msg_ephemeris_gal_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_ephemeris_gal_t *msg) {
    return sbp_msg_ephemeris_gal_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_ephemeris_gal_t &msg) {
    return sbp_msg_ephemeris_gal_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_ephemeris_glo_dep_a_t> {
  static constexpr sbp_msg_type_t id = SbpMsgEphemerisGloDepA;
  static constexpr const char *name = "MSG_EPHEMERIS_GLO_DEP_A";
  static const sbp_msg_ephemeris_glo_dep_a_t &get(const sbp_msg_t &msg) {
    return msg.ephemeris_glo_dep_a;
  }
  static sbp_msg_ephemeris_glo_dep_a_t &get(sbp_msg_t &msg) {
    return msg.ephemeris_glo_dep_a;
  }
  static void to_sbp_msg(const sbp_msg_ephemeris_glo_dep_a_t &msg,
                         sbp_msg_t *sbp_msg) {
    sbp_msg->ephemeris_glo_dep_a = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_ephemeris_glo_dep_a_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.ephemeris_glo_dep_a = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_ephemeris_glo_dep_a_t &msg,
                 sbp_write_fn_t write) {
    return sbp_msg_ephemeris_glo_dep_a_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_ephemeris_glo_dep_a_t &msg) {
    return sbp_msg_ephemeris_glo_dep_a_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_ephemeris_glo_dep_a_t *msg) {
    return sbp_msg_ephemeris_glo_dep_a_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_ephemeris_glo_dep_a_t &msg) {
    return sbp_msg_ephemeris_glo_dep_a_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_ephemeris_glo_dep_b_t> {
  static constexpr sbp_msg_type_t id = SbpMsgEphemerisGloDepB;
  static constexpr const char *name = "MSG_EPHEMERIS_GLO_DEP_B";
  static const sbp_msg_ephemeris_glo_dep_b_t &get(const sbp_msg_t &msg) {
    return msg.ephemeris_glo_dep_b;
  }
  static sbp_msg_ephemeris_glo_dep_b_t &get(sbp_msg_t &msg) {
    return msg.ephemeris_glo_dep_b;
  }
  static void to_sbp_msg(const sbp_msg_ephemeris_glo_dep_b_t &msg,
                         sbp_msg_t *sbp_msg) {
    sbp_msg->ephemeris_glo_dep_b = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_ephemeris_glo_dep_b_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.ephemeris_glo_dep_b = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_ephemeris_glo_dep_b_t &msg,
                 sbp_write_fn_t write) {
    return sbp_msg_ephemeris_glo_dep_b_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_ephemeris_glo_dep_b_t &msg) {
    return sbp_msg_ephemeris_glo_dep_b_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_ephemeris_glo_dep_b_t *msg) {
    return sbp_msg_ephemeris_glo_dep_b_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_ephemeris_glo_dep_b_t &msg) {
    return sbp_msg_ephemeris_glo_dep_b_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_ephemeris_glo_dep_c_t> {
  static constexpr sbp_msg_type_t id = SbpMsgEphemerisGloDepC;
  static constexpr const char *name = "MSG_EPHEMERIS_GLO_DEP_C";
  static const sbp_msg_ephemeris_glo_dep_c_t &get(const sbp_msg_t &msg) {
    return msg.ephemeris_glo_dep_c;
  }
  static sbp_msg_ephemeris_glo_dep_c_t &get(sbp_msg_t &msg) {
    return msg.ephemeris_glo_dep_c;
  }
  static void to_sbp_msg(const sbp_msg_ephemeris_glo_dep_c_t &msg,
                         sbp_msg_t *sbp_msg) {
    sbp_msg->ephemeris_glo_dep_c = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_ephemeris_glo_dep_c_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.ephemeris_glo_dep_c = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_ephemeris_glo_dep_c_t &msg,
                 sbp_write_fn_t write) {
    return sbp_msg_ephemeris_glo_dep_c_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_ephemeris_glo_dep_c_t &msg) {
    return sbp_msg_ephemeris_glo_dep_c_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_ephemeris_glo_dep_c_t *msg) {
    return sbp_msg_ephemeris_glo_dep_c_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_ephemeris_glo_dep_c_t &msg) {
    return sbp_msg_ephemeris_glo_dep_c_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_ephemeris_glo_dep_d_t> {
  static constexpr sbp_msg_type_t id = SbpMsgEphemerisGloDepD;
  static constexpr const char *name = "MSG_EPHEMERIS_GLO_DEP_D";
  static const sbp_msg_ephemeris_glo_dep_d_t &get(const sbp_msg_t &msg) {
    return msg.ephemeris_glo_dep_d;
  }
  static sbp_msg_ephemeris_glo_dep_d_t &get(sbp_msg_t &msg) {
    return msg.ephemeris_glo_dep_d;
  }
  static void to_sbp_msg(const sbp_msg_ephemeris_glo_dep_d_t &msg,
                         sbp_msg_t *sbp_msg) {
    sbp_msg->ephemeris_glo_dep_d = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_ephemeris_glo_dep_d_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.ephemeris_glo_dep_d = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_ephemeris_glo_dep_d_t &msg,
                 sbp_write_fn_t write) {
    return sbp_msg_ephemeris_glo_dep_d_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_ephemeris_glo_dep_d_t &msg) {
    return sbp_msg_ephemeris_glo_dep_d_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_ephemeris_glo_dep_d_t *msg) {
    return sbp_msg_ephemeris_glo_dep_d_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_ephemeris_glo_dep_d_t &msg) {
    return sbp_msg_ephemeris_glo_dep_d_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_ephemeris_glo_t> {
  static constexpr sbp_msg_type_t id = SbpMsgEphemerisGlo;
  static constexpr const char *name = "MSG_EPHEMERIS_GLO";
  static const sbp_msg_ephemeris_glo_t &get(const sbp_msg_t &msg) {
    return msg.ephemeris_glo;
  }
  static sbp_msg_ephemeris_glo_t &get(sbp_msg_t &msg) {
    return msg.ephemeris_glo;
  }
  static void to_sbp_msg(const sbp_msg_ephemeris_glo_t &msg,
                         sbp_msg_t *sbp_msg) {
    sbp_msg->ephemeris_glo = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_ephemeris_glo_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.ephemeris_glo = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_ephemeris_glo_t &msg, sbp_write_fn_t write) {
    return sbp_msg_ephemeris_glo_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_ephemeris_glo_t &msg) {
    return sbp_msg_ephemeris_glo_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_ephemeris_glo_t *msg) {
    return sbp_msg_ephemeris_glo_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_ephemeris_glo_t &msg) {
    return sbp_msg_ephemeris_glo_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_ephemeris_gps_dep_e_t> {
  static constexpr sbp_msg_type_t id = SbpMsgEphemerisGpsDepE;
  static constexpr const char *name = "MSG_EPHEMERIS_GPS_DEP_E";
  static const sbp_msg_ephemeris_gps_dep_e_t &get(const sbp_msg_t &msg) {
    return msg.ephemeris_gps_dep_e;
  }
  static sbp_msg_ephemeris_gps_dep_e_t &get(sbp_msg_t &msg) {
    return msg.ephemeris_gps_dep_e;
  }
  static void to_sbp_msg(const sbp_msg_ephemeris_gps_dep_e_t &msg,
                         sbp_msg_t *sbp_msg) {
    sbp_msg->ephemeris_gps_dep_e = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_ephemeris_gps_dep_e_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.ephemeris_gps_dep_e = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_ephemeris_gps_dep_e_t &msg,
                 sbp_write_fn_t write) {
    return sbp_msg_ephemeris_gps_dep_e_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_ephemeris_gps_dep_e_t &msg) {
    return sbp_msg_ephemeris_gps_dep_e_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_ephemeris_gps_dep_e_t *msg) {
    return sbp_msg_ephemeris_gps_dep_e_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_ephemeris_gps_dep_e_t &msg) {
    return sbp_msg_ephemeris_gps_dep_e_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_ephemeris_gps_dep_f_t> {
  static constexpr sbp_msg_type_t id = SbpMsgEphemerisGpsDepF;
  static constexpr const char *name = "MSG_EPHEMERIS_GPS_DEP_F";
  static const sbp_msg_ephemeris_gps_dep_f_t &get(const sbp_msg_t &msg) {
    return msg.ephemeris_gps_dep_f;
  }
  static sbp_msg_ephemeris_gps_dep_f_t &get(sbp_msg_t &msg) {
    return msg.ephemeris_gps_dep_f;
  }
  static void to_sbp_msg(const sbp_msg_ephemeris_gps_dep_f_t &msg,
                         sbp_msg_t *sbp_msg) {
    sbp_msg->ephemeris_gps_dep_f = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_ephemeris_gps_dep_f_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.ephemeris_gps_dep_f = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_ephemeris_gps_dep_f_t &msg,
                 sbp_write_fn_t write) {
    return sbp_msg_ephemeris_gps_dep_f_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_ephemeris_gps_dep_f_t &msg) {
    return sbp_msg_ephemeris_gps_dep_f_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_ephemeris_gps_dep_f_t *msg) {
    return sbp_msg_ephemeris_gps_dep_f_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_ephemeris_gps_dep_f_t &msg) {
    return sbp_msg_ephemeris_gps_dep_f_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_ephemeris_gps_t> {
  static constexpr sbp_msg_type_t id = SbpMsgEphemerisGps;
  static constexpr const char *name = "MSG_EPHEMERIS_GPS";
  static const sbp_msg_ephemeris_gps_t &get(const sbp_msg_t &msg) {
    return msg.ephemeris_gps;
  }
  static sbp_msg_ephemeris_gps_t &get(sbp_msg_t &msg) {
    return msg.ephemeris_gps;
  }
  static void to_sbp_msg(const sbp_msg_ephemeris_gps_t &msg,
                         sbp_msg_t *sbp_msg) {
    sbp_msg->ephemeris_gps = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_ephemeris_gps_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.ephemeris_gps = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_ephemeris_gps_t &msg, sbp_write_fn_t write) {
    return sbp_msg_ephemeris_gps_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_ephemeris_gps_t &msg) {
    return sbp_msg_ephemeris_gps_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_ephemeris_gps_t *msg) {
    return sbp_msg_ephemeris_gps_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_ephemeris_gps_t &msg) {
    return sbp_msg_ephemeris_gps_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_ephemeris_qzss_t> {
  static constexpr sbp_msg_type_t id = SbpMsgEphemerisQzss;
  static constexpr const char *name = "MSG_EPHEMERIS_QZSS";
  static const sbp_msg_ephemeris_qzss_t &get(const sbp_msg_t &msg) {
    return msg.ephemeris_qzss;
  }
  static sbp_msg_ephemeris_qzss_t &get(sbp_msg_t &msg) {
    return msg.ephemeris_qzss;
  }
  static void to_sbp_msg(const sbp_msg_ephemeris_qzss_t &msg,
                         sbp_msg_t *sbp_msg) {
    sbp_msg->ephemeris_qzss = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_ephemeris_qzss_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.ephemeris_qzss = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_ephemeris_qzss_t &msg, sbp_write_fn_t write) {
    return sbp_msg_ephemeris_qzss_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_ephemeris_qzss_t &msg) {
    return sbp_msg_ephemeris_qzss_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_ephemeris_qzss_t *msg) {
    return sbp_msg_ephemeris_qzss_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_ephemeris_qzss_t &msg) {
    return sbp_msg_ephemeris_qzss_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_ephemeris_sbas_dep_a_t> {
  static constexpr sbp_msg_type_t id = SbpMsgEphemerisSbasDepA;
  static constexpr const char *name = "MSG_EPHEMERIS_SBAS_DEP_A";
  static const sbp_msg_ephemeris_sbas_dep_a_t &get(const sbp_msg_t &msg) {
    return msg.ephemeris_sbas_dep_a;
  }
  static sbp_msg_ephemeris_sbas_dep_a_t &get(sbp_msg_t &msg) {
    return msg.ephemeris_sbas_dep_a;
  }
  static void to_sbp_msg(const sbp_msg_ephemeris_sbas_dep_a_t &msg,
                         sbp_msg_t *sbp_msg) {
    sbp_msg->ephemeris_sbas_dep_a = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_ephemeris_sbas_dep_a_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.ephemeris_sbas_dep_a = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_ephemeris_sbas_dep_a_t &msg,
                 sbp_write_fn_t write) {
    return sbp_msg_ephemeris_sbas_dep_a_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_ephemeris_sbas_dep_a_t &msg) {
    return sbp_msg_ephemeris_sbas_dep_a_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_ephemeris_sbas_dep_a_t *msg) {
    return sbp_msg_ephemeris_sbas_dep_a_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_ephemeris_sbas_dep_a_t &msg) {
    return sbp_msg_ephemeris_sbas_dep_a_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_ephemeris_sbas_dep_b_t> {
  static constexpr sbp_msg_type_t id = SbpMsgEphemerisSbasDepB;
  static constexpr const char *name = "MSG_EPHEMERIS_SBAS_DEP_B";
  static const sbp_msg_ephemeris_sbas_dep_b_t &get(const sbp_msg_t &msg) {
    return msg.ephemeris_sbas_dep_b;
  }
  static sbp_msg_ephemeris_sbas_dep_b_t &get(sbp_msg_t &msg) {
    return msg.ephemeris_sbas_dep_b;
  }
  static void to_sbp_msg(const sbp_msg_ephemeris_sbas_dep_b_t &msg,
                         sbp_msg_t *sbp_msg) {
    sbp_msg->ephemeris_sbas_dep_b = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_ephemeris_sbas_dep_b_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.ephemeris_sbas_dep_b = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_ephemeris_sbas_dep_b_t &msg,
                 sbp_write_fn_t write) {
    return sbp_msg_ephemeris_sbas_dep_b_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_ephemeris_sbas_dep_b_t &msg) {
    return sbp_msg_ephemeris_sbas_dep_b_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_ephemeris_sbas_dep_b_t *msg) {
    return sbp_msg_ephemeris_sbas_dep_b_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_ephemeris_sbas_dep_b_t &msg) {
    return sbp_msg_ephemeris_sbas_dep_b_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_ephemeris_sbas_t> {
  static constexpr sbp_msg_type_t id = SbpMsgEphemerisSbas;
  static constexpr const char *name = "MSG_EPHEMERIS_SBAS";
  static const sbp_msg_ephemeris_sbas_t &get(const sbp_msg_t &msg) {
    return msg.ephemeris_sbas;
  }
  static sbp_msg_ephemeris_sbas_t &get(sbp_msg_t &msg) {
    return msg.ephemeris_sbas;
  }
  static void to_sbp_msg(const sbp_msg_ephemeris_sbas_t &msg,
                         sbp_msg_t *sbp_msg) {
    sbp_msg->ephemeris_sbas = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_ephemeris_sbas_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.ephemeris_sbas = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_ephemeris_sbas_t &msg, sbp_write_fn_t write) {
    return sbp_msg_ephemeris_sbas_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_ephemeris_sbas_t &msg) {
    return sbp_msg_ephemeris_sbas_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_ephemeris_sbas_t *msg) {
    return sbp_msg_ephemeris_sbas_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_ephemeris_sbas_t &msg) {
    return sbp_msg_ephemeris_sbas_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_ext_event_t> {
  static constexpr sbp_msg_type_t id = SbpMsgExtEvent;
  static constexpr const char *name = "MSG_EXT_EVENT";
  static const sbp_msg_ext_event_t &get(const sbp_msg_t &msg) {
    return msg.ext_event;
  }
  static sbp_msg_ext_event_t &get(sbp_msg_t &msg) { return msg.ext_event; }
  static void to_sbp_msg(const sbp_msg_ext_event_t &msg, sbp_msg_t *sbp_msg) {
    sbp_msg->ext_event = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_ext_event_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.ext_event = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_ext_event_t &msg, sbp_write_fn_t write) {
    return sbp_msg_ext_event_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_ext_event_t &msg) {
    return sbp_msg_ext_event_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_ext_event_t *msg) {
    return sbp_msg_ext_event_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_ext_event_t &msg) {
    return sbp_msg_ext_event_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_fileio_config_req_t> {
  static constexpr sbp_msg_type_t id = SbpMsgFileioConfigReq;
  static constexpr const char *name = "MSG_FILEIO_CONFIG_REQ";
  static const sbp_msg_fileio_config_req_t &get(const sbp_msg_t &msg) {
    return msg.fileio_config_req;
  }
  static sbp_msg_fileio_config_req_t &get(sbp_msg_t &msg) {
    return msg.fileio_config_req;
  }
  static void to_sbp_msg(const sbp_msg_fileio_config_req_t &msg,
                         sbp_msg_t *sbp_msg) {
    sbp_msg->fileio_config_req = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_fileio_config_req_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.fileio_config_req = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_fileio_config_req_t &msg, sbp_write_fn_t write) {
    return sbp_msg_fileio_config_req_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_fileio_config_req_t &msg) {
    return sbp_msg_fileio_config_req_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_fileio_config_req_t *msg) {
    return sbp_msg_fileio_config_req_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_fileio_config_req_t &msg) {
    return sbp_msg_fileio_config_req_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_fileio_config_resp_t> {
  static constexpr sbp_msg_type_t id = SbpMsgFileioConfigResp;
  static constexpr const char *name = "MSG_FILEIO_CONFIG_RESP";
  static const sbp_msg_fileio_config_resp_t &get(const sbp_msg_t &msg) {
    return msg.fileio_config_resp;
  }
  static sbp_msg_fileio_config_resp_t &get(sbp_msg_t &msg) {
    return msg.fileio_config_resp;
  }
  static void to_sbp_msg(const sbp_msg_fileio_config_resp_t &msg,
                         sbp_msg_t *sbp_msg) {
    sbp_msg->fileio_config_resp = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_fileio_config_resp_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.fileio_config_resp = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_fileio_config_resp_t &msg,
                 sbp_write_fn_t write) {
    return sbp_msg_fileio_config_resp_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_fileio_config_resp_t &msg) {
    return sbp_msg_fileio_config_resp_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_fileio_config_resp_t *msg) {
    return sbp_msg_fileio_config_resp_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_fileio_config_resp_t &msg) {
    return sbp_msg_fileio_config_resp_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_fileio_read_dir_req_t> {
  static constexpr sbp_msg_type_t id = SbpMsgFileioReadDirReq;
  static constexpr const char *name = "MSG_FILEIO_READ_DIR_REQ";
  static const sbp_msg_fileio_read_dir_req_t &get(const sbp_msg_t &msg) {
    return msg.fileio_read_dir_req;
  }
  static sbp_msg_fileio_read_dir_req_t &get(sbp_msg_t &msg) {
    return msg.fileio_read_dir_req;
  }
  static void to_sbp_msg(const sbp_msg_fileio_read_dir_req_t &msg,
                         sbp_msg_t *sbp_msg) {
    sbp_msg->fileio_read_dir_req = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_fileio_read_dir_req_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.fileio_read_dir_req = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_fileio_read_dir_req_t &msg,
                 sbp_write_fn_t write) {
    return sbp_msg_fileio_read_dir_req_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_fileio_read_dir_req_t &msg) {
    return sbp_msg_fileio_read_dir_req_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_fileio_read_dir_req_t *msg) {
    return sbp_msg_fileio_read_dir_req_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_fileio_read_dir_req_t &msg) {
    return sbp_msg_fileio_read_dir_req_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_fileio_read_dir_resp_t> {
  static constexpr sbp_msg_type_t id = SbpMsgFileioReadDirResp;
  static constexpr const char *name = "MSG_FILEIO_READ_DIR_RESP";
  static const sbp_msg_fileio_read_dir_resp_t &get(const sbp_msg_t &msg) {
    return msg.fileio_read_dir_resp;
  }
  static sbp_msg_fileio_read_dir_resp_t &get(sbp_msg_t &msg) {
    return msg.fileio_read_dir_resp;
  }
  static void to_sbp_msg(const sbp_msg_fileio_read_dir_resp_t &msg,
                         sbp_msg_t *sbp_msg) {
    sbp_msg->fileio_read_dir_resp = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_fileio_read_dir_resp_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.fileio_read_dir_resp = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_fileio_read_dir_resp_t &msg,
                 sbp_write_fn_t write) {
    return sbp_msg_fileio_read_dir_resp_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_fileio_read_dir_resp_t &msg) {
    return sbp_msg_fileio_read_dir_resp_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_fileio_read_dir_resp_t *msg) {
    return sbp_msg_fileio_read_dir_resp_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_fileio_read_dir_resp_t &msg) {
    return sbp_msg_fileio_read_dir_resp_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_fileio_read_req_t> {
  static constexpr sbp_msg_type_t id = SbpMsgFileioReadReq;
  static constexpr const char *name = "MSG_FILEIO_READ_REQ";
  static const sbp_msg_fileio_read_req_t &get(const sbp_msg_t &msg) {
    return msg.fileio_read_req;
  }
  static sbp_msg_fileio_read_req_t &get(sbp_msg_t &msg) {
    return msg.fileio_read_req;
  }
  static void to_sbp_msg(const sbp_msg_fileio_read_req_t &msg,
                         sbp_msg_t *sbp_msg) {
    sbp_msg->fileio_read_req = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_fileio_read_req_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.fileio_read_req = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_fileio_read_req_t &msg, sbp_write_fn_t write) {
    return sbp_msg_fileio_read_req_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_fileio_read_req_t &msg) {
    return sbp_msg_fileio_read_req_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_fileio_read_req_t *msg) {
    return sbp_msg_fileio_read_req_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_fileio_read_req_t &msg) {
    return sbp_msg_fileio_read_req_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_fileio_read_resp_t> {
  static constexpr sbp_msg_type_t id = SbpMsgFileioReadResp;
  static constexpr const char *name = "MSG_FILEIO_READ_RESP";
  static const sbp_msg_fileio_read_resp_t &get(const sbp_msg_t &msg) {
    return msg.fileio_read_resp;
  }
  static sbp_msg_fileio_read_resp_t &get(sbp_msg_t &msg) {
    return msg.fileio_read_resp;
  }
  static void to_sbp_msg(const sbp_msg_fileio_read_resp_t &msg,
                         sbp_msg_t *sbp_msg) {
    sbp_msg->fileio_read_resp = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_fileio_read_resp_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.fileio_read_resp = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_fileio_read_resp_t &msg, sbp_write_fn_t write) {
    return sbp_msg_fileio_read_resp_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_fileio_read_resp_t &msg) {
    return sbp_msg_fileio_read_resp_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_fileio_read_resp_t *msg) {
    return sbp_msg_fileio_read_resp_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_fileio_read_resp_t &msg) {
    return sbp_msg_fileio_read_resp_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_fileio_remove_t> {
  static constexpr sbp_msg_type_t id = SbpMsgFileioRemove;
  static constexpr const char *name = "MSG_FILEIO_REMOVE";
  static const sbp_msg_fileio_remove_t &get(const sbp_msg_t &msg) {
    return msg.fileio_remove;
  }
  static sbp_msg_fileio_remove_t &get(sbp_msg_t &msg) {
    return msg.fileio_remove;
  }
  static void to_sbp_msg(const sbp_msg_fileio_remove_t &msg,
                         sbp_msg_t *sbp_msg) {
    sbp_msg->fileio_remove = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_fileio_remove_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.fileio_remove = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_fileio_remove_t &msg, sbp_write_fn_t write) {
    return sbp_msg_fileio_remove_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_fileio_remove_t &msg) {
    return sbp_msg_fileio_remove_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_fileio_remove_t *msg) {
    return sbp_msg_fileio_remove_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_fileio_remove_t &msg) {
    return sbp_msg_fileio_remove_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_fileio_write_req_t> {
  static constexpr sbp_msg_type_t id = SbpMsgFileioWriteReq;
  static constexpr const char *name = "MSG_FILEIO_WRITE_REQ";
  static const sbp_msg_fileio_write_req_t &get(const sbp_msg_t &msg) {
    return msg.fileio_write_req;
  }
  static sbp_msg_fileio_write_req_t &get(sbp_msg_t &msg) {
    return msg.fileio_write_req;
  }
  static void to_sbp_msg(const sbp_msg_fileio_write_req_t &msg,
                         sbp_msg_t *sbp_msg) {
    sbp_msg->fileio_write_req = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_fileio_write_req_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.fileio_write_req = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_fileio_write_req_t &msg, sbp_write_fn_t write) {
    return sbp_msg_fileio_write_req_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_fileio_write_req_t &msg) {
    return sbp_msg_fileio_write_req_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_fileio_write_req_t *msg) {
    return sbp_msg_fileio_write_req_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_fileio_write_req_t &msg) {
    return sbp_msg_fileio_write_req_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_fileio_write_resp_t> {
  static constexpr sbp_msg_type_t id = SbpMsgFileioWriteResp;
  static constexpr const char *name = "MSG_FILEIO_WRITE_RESP";
  static const sbp_msg_fileio_write_resp_t &get(const sbp_msg_t &msg) {
    return msg.fileio_write_resp;
  }
  static sbp_msg_fileio_write_resp_t &get(sbp_msg_t &msg) {
    return msg.fileio_write_resp;
  }
  static void to_sbp_msg(const sbp_msg_fileio_write_resp_t &msg,
                         sbp_msg_t *sbp_msg) {
    sbp_msg->fileio_write_resp = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_fileio_write_resp_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.fileio_write_resp = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_fileio_write_resp_t &msg, sbp_write_fn_t write) {
    return sbp_msg_fileio_write_resp_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_fileio_write_resp_t &msg) {
    return sbp_msg_fileio_write_resp_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_fileio_write_resp_t *msg) {
    return sbp_msg_fileio_write_resp_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_fileio_write_resp_t &msg) {
    return sbp_msg_fileio_write_resp_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_flash_done_t> {
  static constexpr sbp_msg_type_t id = SbpMsgFlashDone;
  static constexpr const char *name = "MSG_FLASH_DONE";
  static const sbp_msg_flash_done_t &get(const sbp_msg_t &msg) {
    return msg.flash_done;
  }
  static sbp_msg_flash_done_t &get(sbp_msg_t &msg) { return msg.flash_done; }
  static void to_sbp_msg(const sbp_msg_flash_done_t &msg, sbp_msg_t *sbp_msg) {
    sbp_msg->flash_done = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_flash_done_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.flash_done = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_flash_done_t &msg, sbp_write_fn_t write) {
    return sbp_msg_flash_done_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_flash_done_t &msg) {
    return sbp_msg_flash_done_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_flash_done_t *msg) {
    return sbp_msg_flash_done_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_flash_done_t &msg) {
    return sbp_msg_flash_done_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_flash_erase_t> {
  static constexpr sbp_msg_type_t id = SbpMsgFlashErase;
  static constexpr const char *name = "MSG_FLASH_ERASE";
  static const sbp_msg_flash_erase_t &get(const sbp_msg_t &msg) {
    return msg.flash_erase;
  }
  static sbp_msg_flash_erase_t &get(sbp_msg_t &msg) { return msg.flash_erase; }
  static void to_sbp_msg(const sbp_msg_flash_erase_t &msg, sbp_msg_t *sbp_msg) {
    sbp_msg->flash_erase = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_flash_erase_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.flash_erase = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_flash_erase_t &msg, sbp_write_fn_t write) {
    return sbp_msg_flash_erase_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_flash_erase_t &msg) {
    return sbp_msg_flash_erase_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_flash_erase_t *msg) {
    return sbp_msg_flash_erase_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_flash_erase_t &msg) {
    return sbp_msg_flash_erase_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_flash_program_t> {
  static constexpr sbp_msg_type_t id = SbpMsgFlashProgram;
  static constexpr const char *name = "MSG_FLASH_PROGRAM";
  static const sbp_msg_flash_program_t &get(const sbp_msg_t &msg) {
    return msg.flash_program;
  }
  static sbp_msg_flash_program_t &get(sbp_msg_t &msg) {
    return msg.flash_program;
  }
  static void to_sbp_msg(const sbp_msg_flash_program_t &msg,
                         sbp_msg_t *sbp_msg) {
    sbp_msg->flash_program = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_flash_program_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.flash_program = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_flash_program_t &msg, sbp_write_fn_t write) {
    return sbp_msg_flash_program_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_flash_program_t &msg) {
    return sbp_msg_flash_program_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_flash_program_t *msg) {
    return sbp_msg_flash_program_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_flash_program_t &msg) {
    return sbp_msg_flash_program_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_flash_read_req_t> {
  static constexpr sbp_msg_type_t id = SbpMsgFlashReadReq;
  static constexpr const char *name = "MSG_FLASH_READ_REQ";
  static const sbp_msg_flash_read_req_t &get(const sbp_msg_t &msg) {
    return msg.flash_read_req;
  }
  static sbp_msg_flash_read_req_t &get(sbp_msg_t &msg) {
    return msg.flash_read_req;
  }
  static void to_sbp_msg(const sbp_msg_flash_read_req_t &msg,
                         sbp_msg_t *sbp_msg) {
    sbp_msg->flash_read_req = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_flash_read_req_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.flash_read_req = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_flash_read_req_t &msg, sbp_write_fn_t write) {
    return sbp_msg_flash_read_req_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_flash_read_req_t &msg) {
    return sbp_msg_flash_read_req_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_flash_read_req_t *msg) {
    return sbp_msg_flash_read_req_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_flash_read_req_t &msg) {
    return sbp_msg_flash_read_req_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_flash_read_resp_t> {
  static constexpr sbp_msg_type_t id = SbpMsgFlashReadResp;
  static constexpr const char *name = "MSG_FLASH_READ_RESP";
  static const sbp_msg_flash_read_resp_t &get(const sbp_msg_t &msg) {
    return msg.flash_read_resp;
  }
  static sbp_msg_flash_read_resp_t &get(sbp_msg_t &msg) {
    return msg.flash_read_resp;
  }
  static void to_sbp_msg(const sbp_msg_flash_read_resp_t &msg,
                         sbp_msg_t *sbp_msg) {
    sbp_msg->flash_read_resp = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_flash_read_resp_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.flash_read_resp = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_flash_read_resp_t &msg, sbp_write_fn_t write) {
    return sbp_msg_flash_read_resp_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_flash_read_resp_t &msg) {
    return sbp_msg_flash_read_resp_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_flash_read_resp_t *msg) {
    return sbp_msg_flash_read_resp_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_flash_read_resp_t &msg) {
    return sbp_msg_flash_read_resp_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_front_end_gain_t> {
  static constexpr sbp_msg_type_t id = SbpMsgFrontEndGain;
  static constexpr const char *name = "MSG_FRONT_END_GAIN";
  static const sbp_msg_front_end_gain_t &get(const sbp_msg_t &msg) {
    return msg.front_end_gain;
  }
  static sbp_msg_front_end_gain_t &get(sbp_msg_t &msg) {
    return msg.front_end_gain;
  }
  static void to_sbp_msg(const sbp_msg_front_end_gain_t &msg,
                         sbp_msg_t *sbp_msg) {
    sbp_msg->front_end_gain = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_front_end_gain_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.front_end_gain = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_front_end_gain_t &msg, sbp_write_fn_t write) {
    return sbp_msg_front_end_gain_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_front_end_gain_t &msg) {
    return sbp_msg_front_end_gain_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_front_end_gain_t *msg) {
    return sbp_msg_front_end_gain_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_front_end_gain_t &msg) {
    return sbp_msg_front_end_gain_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_fwd_t> {
  static constexpr sbp_msg_type_t id = SbpMsgFwd;
  static constexpr const char *name = "MSG_FWD";
  static const sbp_msg_fwd_t &get(const sbp_msg_t &msg) { return msg.fwd; }
  static sbp_msg_fwd_t &get(sbp_msg_t &msg) { return msg.fwd; }
  static void to_sbp_msg(const sbp_msg_fwd_t &msg, sbp_msg_t *sbp_msg) {
    sbp_msg->fwd = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_fwd_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.fwd = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_fwd_t &msg,
                 sbp_write_fn_t write) {
    return sbp_msg_fwd_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_fwd_t &msg) {
    return sbp_msg_fwd_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_fwd_t *msg) {
    return sbp_msg_fwd_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_fwd_t &msg) {
    return sbp_msg_fwd_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_glo_biases_t> {
  static constexpr sbp_msg_type_t id = SbpMsgGloBiases;
  static constexpr const char *name = "MSG_GLO_BIASES";
  static const sbp_msg_glo_biases_t &get(const sbp_msg_t &msg) {
    return msg.glo_biases;
  }
  static sbp_msg_glo_biases_t &get(sbp_msg_t &msg) { return msg.glo_biases; }
  static void to_sbp_msg(const sbp_msg_glo_biases_t &msg, sbp_msg_t *sbp_msg) {
    sbp_msg->glo_biases = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_glo_biases_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.glo_biases = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_glo_biases_t &msg, sbp_write_fn_t write) {
    return sbp_msg_glo_biases_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_glo_biases_t &msg) {
    return sbp_msg_glo_biases_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_glo_biases_t *msg) {
    return sbp_msg_glo_biases_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_glo_biases_t &msg) {
    return sbp_msg_glo_biases_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_gnss_capb_t> {
  static constexpr sbp_msg_type_t id = SbpMsgGnssCapb;
  static constexpr const char *name = "MSG_GNSS_CAPB";
  static const sbp_msg_gnss_capb_t &get(const sbp_msg_t &msg) {
    return msg.gnss_capb;
  }
  static sbp_msg_gnss_capb_t &get(sbp_msg_t &msg) { return msg.gnss_capb; }
  static void to_sbp_msg(const sbp_msg_gnss_capb_t &msg, sbp_msg_t *sbp_msg) {
    sbp_msg->gnss_capb = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_gnss_capb_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.gnss_capb = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_gnss_capb_t &msg, sbp_write_fn_t write) {
    return sbp_msg_gnss_capb_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_gnss_capb_t &msg) {
    return sbp_msg_gnss_capb_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_gnss_capb_t *msg) {
    return sbp_msg_gnss_capb_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_gnss_capb_t &msg) {
    return sbp_msg_gnss_capb_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_gnss_time_offset_t> {
  static constexpr sbp_msg_type_t id = SbpMsgGnssTimeOffset;
  static constexpr const char *name = "MSG_GNSS_TIME_OFFSET";
  static const sbp_msg_gnss_time_offset_t &get(const sbp_msg_t &msg) {
    return msg.gnss_time_offset;
  }
  static sbp_msg_gnss_time_offset_t &get(sbp_msg_t &msg) {
    return msg.gnss_time_offset;
  }
  static void to_sbp_msg(const sbp_msg_gnss_time_offset_t &msg,
                         sbp_msg_t *sbp_msg) {
    sbp_msg->gnss_time_offset = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_gnss_time_offset_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.gnss_time_offset = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_gnss_time_offset_t &msg, sbp_write_fn_t write) {
    return sbp_msg_gnss_time_offset_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_gnss_time_offset_t &msg) {
    return sbp_msg_gnss_time_offset_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_gnss_time_offset_t *msg) {
    return sbp_msg_gnss_time_offset_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_gnss_time_offset_t &msg) {
    return sbp_msg_gnss_time_offset_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_gps_time_dep_a_t> {
  static constexpr sbp_msg_type_t id = SbpMsgGpsTimeDepA;
  static constexpr const char *name = "MSG_GPS_TIME_DEP_A";
  static const sbp_msg_gps_time_dep_a_t &get(const sbp_msg_t &msg) {
    return msg.gps_time_dep_a;
  }
  static sbp_msg_gps_time_dep_a_t &get(sbp_msg_t &msg) {
    return msg.gps_time_dep_a;
  }
  static void to_sbp_msg(const sbp_msg_gps_time_dep_a_t &msg,
                         sbp_msg_t *sbp_msg) {
    sbp_msg->gps_time_dep_a = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_gps_time_dep_a_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.gps_time_dep_a = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_gps_time_dep_a_t &msg, sbp_write_fn_t write) {
    return sbp_msg_gps_time_dep_a_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_gps_time_dep_a_t &msg) {
    return sbp_msg_gps_time_dep_a_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_gps_time_dep_a_t *msg) {
    return sbp_msg_gps_time_dep_a_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_gps_time_dep_a_t &msg) {
    return sbp_msg_gps_time_dep_a_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_gps_time_gnss_t> {
  static constexpr sbp_msg_type_t id = SbpMsgGpsTimeGnss;
  static constexpr const char *name = "MSG_GPS_TIME_GNSS";
  static const sbp_msg_gps_time_gnss_t &get(const sbp_msg_t &msg) {
    return msg.gps_time_gnss;
  }
  static sbp_msg_gps_time_gnss_t &get(sbp_msg_t &msg) {
    return msg.gps_time_gnss;
  }
  static void to_sbp_msg(const sbp_msg_gps_time_gnss_t &msg,
                         sbp_msg_t *sbp_msg) {
    sbp_msg->gps_time_gnss = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_gps_time_gnss_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.gps_time_gnss = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_gps_time_gnss_t &msg, sbp_write_fn_t write) {
    return sbp_msg_gps_time_gnss_send(state, sender_id, &msg, write);
  }
  static sbp_msg_gps_time_gnss_t to_gnss(const sbp_msg_gps_time_gnss_t &msg) {
    return msg;
  }
  static sbp_msg_gps_time_t to_non_gnss(const sbp_msg_gps_time_gnss_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.gps_time_gnss = msg;
    return sbp_msg.gps_time;
  }

  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_gps_time_gnss_t &msg) {
    return sbp_msg_gps_time_gnss_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_gps_time_gnss_t *msg) {
    return sbp_msg_gps_time_gnss_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_gps_time_gnss_t &msg) {
    return sbp_msg_gps_time_gnss_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_gps_time_t> {
  static constexpr sbp_msg_type_t id = SbpMsgGpsTime;
  static constexpr const char *name = "MSG_GPS_TIME";
  static const sbp_msg_gps_time_t &get(const sbp_msg_t &msg) {
    return msg.gps_time;
  }
  static sbp_msg_gps_time_t &get(sbp_msg_t &msg) { return msg.gps_time; }
  static void to_sbp_msg(const sbp_msg_gps_time_t &msg, sbp_msg_t *sbp_msg) {
    sbp_msg->gps_time = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_gps_time_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.gps_time = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_gps_time_t &msg, sbp_write_fn_t write) {
    return sbp_msg_gps_time_send(state, sender_id, &msg, write);
  }
  static sbp_msg_gps_time_gnss_t to_gnss(const sbp_msg_gps_time_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.gps_time = msg;
    return sbp_msg.gps_time_gnss;
  }
  static sbp_msg_gps_time_t to_non_gnss(const sbp_msg_gps_time_t &msg) {
    return msg;
  }

  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_gps_time_t &msg) {
    return sbp_msg_gps_time_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_gps_time_t *msg) {
    return sbp_msg_gps_time_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_gps_time_t &msg) {
    return sbp_msg_gps_time_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_group_delay_dep_a_t> {
  static constexpr sbp_msg_type_t id = SbpMsgGroupDelayDepA;
  static constexpr const char *name = "MSG_GROUP_DELAY_DEP_A";
  static const sbp_msg_group_delay_dep_a_t &get(const sbp_msg_t &msg) {
    return msg.group_delay_dep_a;
  }
  static sbp_msg_group_delay_dep_a_t &get(sbp_msg_t &msg) {
    return msg.group_delay_dep_a;
  }
  static void to_sbp_msg(const sbp_msg_group_delay_dep_a_t &msg,
                         sbp_msg_t *sbp_msg) {
    sbp_msg->group_delay_dep_a = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_group_delay_dep_a_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.group_delay_dep_a = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_group_delay_dep_a_t &msg, sbp_write_fn_t write) {
    return sbp_msg_group_delay_dep_a_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_group_delay_dep_a_t &msg) {
    return sbp_msg_group_delay_dep_a_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_group_delay_dep_a_t *msg) {
    return sbp_msg_group_delay_dep_a_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_group_delay_dep_a_t &msg) {
    return sbp_msg_group_delay_dep_a_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_group_delay_dep_b_t> {
  static constexpr sbp_msg_type_t id = SbpMsgGroupDelayDepB;
  static constexpr const char *name = "MSG_GROUP_DELAY_DEP_B";
  static const sbp_msg_group_delay_dep_b_t &get(const sbp_msg_t &msg) {
    return msg.group_delay_dep_b;
  }
  static sbp_msg_group_delay_dep_b_t &get(sbp_msg_t &msg) {
    return msg.group_delay_dep_b;
  }
  static void to_sbp_msg(const sbp_msg_group_delay_dep_b_t &msg,
                         sbp_msg_t *sbp_msg) {
    sbp_msg->group_delay_dep_b = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_group_delay_dep_b_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.group_delay_dep_b = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_group_delay_dep_b_t &msg, sbp_write_fn_t write) {
    return sbp_msg_group_delay_dep_b_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_group_delay_dep_b_t &msg) {
    return sbp_msg_group_delay_dep_b_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_group_delay_dep_b_t *msg) {
    return sbp_msg_group_delay_dep_b_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_group_delay_dep_b_t &msg) {
    return sbp_msg_group_delay_dep_b_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_group_delay_t> {
  static constexpr sbp_msg_type_t id = SbpMsgGroupDelay;
  static constexpr const char *name = "MSG_GROUP_DELAY";
  static const sbp_msg_group_delay_t &get(const sbp_msg_t &msg) {
    return msg.group_delay;
  }
  static sbp_msg_group_delay_t &get(sbp_msg_t &msg) { return msg.group_delay; }
  static void to_sbp_msg(const sbp_msg_group_delay_t &msg, sbp_msg_t *sbp_msg) {
    sbp_msg->group_delay = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_group_delay_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.group_delay = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_group_delay_t &msg, sbp_write_fn_t write) {
    return sbp_msg_group_delay_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_group_delay_t &msg) {
    return sbp_msg_group_delay_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_group_delay_t *msg) {
    return sbp_msg_group_delay_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_group_delay_t &msg) {
    return sbp_msg_group_delay_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_group_meta_t> {
  static constexpr sbp_msg_type_t id = SbpMsgGroupMeta;
  static constexpr const char *name = "MSG_GROUP_META";
  static const sbp_msg_group_meta_t &get(const sbp_msg_t &msg) {
    return msg.group_meta;
  }
  static sbp_msg_group_meta_t &get(sbp_msg_t &msg) { return msg.group_meta; }
  static void to_sbp_msg(const sbp_msg_group_meta_t &msg, sbp_msg_t *sbp_msg) {
    sbp_msg->group_meta = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_group_meta_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.group_meta = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_group_meta_t &msg, sbp_write_fn_t write) {
    return sbp_msg_group_meta_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_group_meta_t &msg) {
    return sbp_msg_group_meta_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_group_meta_t *msg) {
    return sbp_msg_group_meta_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_group_meta_t &msg) {
    return sbp_msg_group_meta_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_heartbeat_t> {
  static constexpr sbp_msg_type_t id = SbpMsgHeartbeat;
  static constexpr const char *name = "MSG_HEARTBEAT";
  static const sbp_msg_heartbeat_t &get(const sbp_msg_t &msg) {
    return msg.heartbeat;
  }
  static sbp_msg_heartbeat_t &get(sbp_msg_t &msg) { return msg.heartbeat; }
  static void to_sbp_msg(const sbp_msg_heartbeat_t &msg, sbp_msg_t *sbp_msg) {
    sbp_msg->heartbeat = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_heartbeat_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.heartbeat = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_heartbeat_t &msg, sbp_write_fn_t write) {
    return sbp_msg_heartbeat_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_heartbeat_t &msg) {
    return sbp_msg_heartbeat_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_heartbeat_t *msg) {
    return sbp_msg_heartbeat_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_heartbeat_t &msg) {
    return sbp_msg_heartbeat_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_iar_state_t> {
  static constexpr sbp_msg_type_t id = SbpMsgIarState;
  static constexpr const char *name = "MSG_IAR_STATE";
  static const sbp_msg_iar_state_t &get(const sbp_msg_t &msg) {
    return msg.iar_state;
  }
  static sbp_msg_iar_state_t &get(sbp_msg_t &msg) { return msg.iar_state; }
  static void to_sbp_msg(const sbp_msg_iar_state_t &msg, sbp_msg_t *sbp_msg) {
    sbp_msg->iar_state = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_iar_state_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.iar_state = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_iar_state_t &msg, sbp_write_fn_t write) {
    return sbp_msg_iar_state_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_iar_state_t &msg) {
    return sbp_msg_iar_state_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_iar_state_t *msg) {
    return sbp_msg_iar_state_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_iar_state_t &msg) {
    return sbp_msg_iar_state_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_imu_aux_t> {
  static constexpr sbp_msg_type_t id = SbpMsgImuAux;
  static constexpr const char *name = "MSG_IMU_AUX";
  static const sbp_msg_imu_aux_t &get(const sbp_msg_t &msg) {
    return msg.imu_aux;
  }
  static sbp_msg_imu_aux_t &get(sbp_msg_t &msg) { return msg.imu_aux; }
  static void to_sbp_msg(const sbp_msg_imu_aux_t &msg, sbp_msg_t *sbp_msg) {
    sbp_msg->imu_aux = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_imu_aux_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.imu_aux = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_imu_aux_t &msg, sbp_write_fn_t write) {
    return sbp_msg_imu_aux_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_imu_aux_t &msg) {
    return sbp_msg_imu_aux_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_imu_aux_t *msg) {
    return sbp_msg_imu_aux_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_imu_aux_t &msg) {
    return sbp_msg_imu_aux_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_imu_comp_t> {
  static constexpr sbp_msg_type_t id = SbpMsgImuComp;
  static constexpr const char *name = "MSG_IMU_COMP";
  static const sbp_msg_imu_comp_t &get(const sbp_msg_t &msg) {
    return msg.imu_comp;
  }
  static sbp_msg_imu_comp_t &get(sbp_msg_t &msg) { return msg.imu_comp; }
  static void to_sbp_msg(const sbp_msg_imu_comp_t &msg, sbp_msg_t *sbp_msg) {
    sbp_msg->imu_comp = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_imu_comp_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.imu_comp = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_imu_comp_t &msg, sbp_write_fn_t write) {
    return sbp_msg_imu_comp_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_imu_comp_t &msg) {
    return sbp_msg_imu_comp_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_imu_comp_t *msg) {
    return sbp_msg_imu_comp_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_imu_comp_t &msg) {
    return sbp_msg_imu_comp_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_imu_raw_t> {
  static constexpr sbp_msg_type_t id = SbpMsgImuRaw;
  static constexpr const char *name = "MSG_IMU_RAW";
  static const sbp_msg_imu_raw_t &get(const sbp_msg_t &msg) {
    return msg.imu_raw;
  }
  static sbp_msg_imu_raw_t &get(sbp_msg_t &msg) { return msg.imu_raw; }
  static void to_sbp_msg(const sbp_msg_imu_raw_t &msg, sbp_msg_t *sbp_msg) {
    sbp_msg->imu_raw = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_imu_raw_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.imu_raw = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_imu_raw_t &msg, sbp_write_fn_t write) {
    return sbp_msg_imu_raw_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_imu_raw_t &msg) {
    return sbp_msg_imu_raw_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_imu_raw_t *msg) {
    return sbp_msg_imu_raw_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_imu_raw_t &msg) {
    return sbp_msg_imu_raw_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_init_base_dep_t> {
  static constexpr sbp_msg_type_t id = SbpMsgInitBaseDep;
  static constexpr const char *name = "MSG_INIT_BASE_DEP";
  static const sbp_msg_init_base_dep_t &get(const sbp_msg_t &msg) {
    return msg.init_base_dep;
  }
  static sbp_msg_init_base_dep_t &get(sbp_msg_t &msg) {
    return msg.init_base_dep;
  }
  static void to_sbp_msg(const sbp_msg_init_base_dep_t &msg,
                         sbp_msg_t *sbp_msg) {
    sbp_msg->init_base_dep = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_init_base_dep_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.init_base_dep = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_init_base_dep_t &msg, sbp_write_fn_t write) {
    return sbp_msg_init_base_dep_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_init_base_dep_t &msg) {
    return sbp_msg_init_base_dep_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_init_base_dep_t *msg) {
    return sbp_msg_init_base_dep_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_init_base_dep_t &msg) {
    return sbp_msg_init_base_dep_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_ins_status_t> {
  static constexpr sbp_msg_type_t id = SbpMsgInsStatus;
  static constexpr const char *name = "MSG_INS_STATUS";
  static const sbp_msg_ins_status_t &get(const sbp_msg_t &msg) {
    return msg.ins_status;
  }
  static sbp_msg_ins_status_t &get(sbp_msg_t &msg) { return msg.ins_status; }
  static void to_sbp_msg(const sbp_msg_ins_status_t &msg, sbp_msg_t *sbp_msg) {
    sbp_msg->ins_status = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_ins_status_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.ins_status = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_ins_status_t &msg, sbp_write_fn_t write) {
    return sbp_msg_ins_status_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_ins_status_t &msg) {
    return sbp_msg_ins_status_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_ins_status_t *msg) {
    return sbp_msg_ins_status_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_ins_status_t &msg) {
    return sbp_msg_ins_status_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_ins_updates_t> {
  static constexpr sbp_msg_type_t id = SbpMsgInsUpdates;
  static constexpr const char *name = "MSG_INS_UPDATES";
  static const sbp_msg_ins_updates_t &get(const sbp_msg_t &msg) {
    return msg.ins_updates;
  }
  static sbp_msg_ins_updates_t &get(sbp_msg_t &msg) { return msg.ins_updates; }
  static void to_sbp_msg(const sbp_msg_ins_updates_t &msg, sbp_msg_t *sbp_msg) {
    sbp_msg->ins_updates = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_ins_updates_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.ins_updates = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_ins_updates_t &msg, sbp_write_fn_t write) {
    return sbp_msg_ins_updates_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_ins_updates_t &msg) {
    return sbp_msg_ins_updates_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_ins_updates_t *msg) {
    return sbp_msg_ins_updates_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_ins_updates_t &msg) {
    return sbp_msg_ins_updates_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_iono_t> {
  static constexpr sbp_msg_type_t id = SbpMsgIono;
  static constexpr const char *name = "MSG_IONO";
  static const sbp_msg_iono_t &get(const sbp_msg_t &msg) { return msg.iono; }
  static sbp_msg_iono_t &get(sbp_msg_t &msg) { return msg.iono; }
  static void to_sbp_msg(const sbp_msg_iono_t &msg, sbp_msg_t *sbp_msg) {
    sbp_msg->iono = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_iono_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.iono = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_iono_t &msg,
                 sbp_write_fn_t write) {
    return sbp_msg_iono_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_iono_t &msg) {
    return sbp_msg_iono_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_iono_t *msg) {
    return sbp_msg_iono_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_iono_t &msg) {
    return sbp_msg_iono_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_linux_cpu_state_dep_a_t> {
  static constexpr sbp_msg_type_t id = SbpMsgLinuxCpuStateDepA;
  static constexpr const char *name = "MSG_LINUX_CPU_STATE_DEP_A";
  static const sbp_msg_linux_cpu_state_dep_a_t &get(const sbp_msg_t &msg) {
    return msg.linux_cpu_state_dep_a;
  }
  static sbp_msg_linux_cpu_state_dep_a_t &get(sbp_msg_t &msg) {
    return msg.linux_cpu_state_dep_a;
  }
  static void to_sbp_msg(const sbp_msg_linux_cpu_state_dep_a_t &msg,
                         sbp_msg_t *sbp_msg) {
    sbp_msg->linux_cpu_state_dep_a = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_linux_cpu_state_dep_a_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.linux_cpu_state_dep_a = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_linux_cpu_state_dep_a_t &msg,
                 sbp_write_fn_t write) {
    return sbp_msg_linux_cpu_state_dep_a_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_linux_cpu_state_dep_a_t &msg) {
    return sbp_msg_linux_cpu_state_dep_a_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_linux_cpu_state_dep_a_t *msg) {
    return sbp_msg_linux_cpu_state_dep_a_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_linux_cpu_state_dep_a_t &msg) {
    return sbp_msg_linux_cpu_state_dep_a_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_linux_cpu_state_t> {
  static constexpr sbp_msg_type_t id = SbpMsgLinuxCpuState;
  static constexpr const char *name = "MSG_LINUX_CPU_STATE";
  static const sbp_msg_linux_cpu_state_t &get(const sbp_msg_t &msg) {
    return msg.linux_cpu_state;
  }
  static sbp_msg_linux_cpu_state_t &get(sbp_msg_t &msg) {
    return msg.linux_cpu_state;
  }
  static void to_sbp_msg(const sbp_msg_linux_cpu_state_t &msg,
                         sbp_msg_t *sbp_msg) {
    sbp_msg->linux_cpu_state = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_linux_cpu_state_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.linux_cpu_state = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_linux_cpu_state_t &msg, sbp_write_fn_t write) {
    return sbp_msg_linux_cpu_state_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_linux_cpu_state_t &msg) {
    return sbp_msg_linux_cpu_state_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_linux_cpu_state_t *msg) {
    return sbp_msg_linux_cpu_state_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_linux_cpu_state_t &msg) {
    return sbp_msg_linux_cpu_state_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_linux_mem_state_dep_a_t> {
  static constexpr sbp_msg_type_t id = SbpMsgLinuxMemStateDepA;
  static constexpr const char *name = "MSG_LINUX_MEM_STATE_DEP_A";
  static const sbp_msg_linux_mem_state_dep_a_t &get(const sbp_msg_t &msg) {
    return msg.linux_mem_state_dep_a;
  }
  static sbp_msg_linux_mem_state_dep_a_t &get(sbp_msg_t &msg) {
    return msg.linux_mem_state_dep_a;
  }
  static void to_sbp_msg(const sbp_msg_linux_mem_state_dep_a_t &msg,
                         sbp_msg_t *sbp_msg) {
    sbp_msg->linux_mem_state_dep_a = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_linux_mem_state_dep_a_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.linux_mem_state_dep_a = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_linux_mem_state_dep_a_t &msg,
                 sbp_write_fn_t write) {
    return sbp_msg_linux_mem_state_dep_a_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_linux_mem_state_dep_a_t &msg) {
    return sbp_msg_linux_mem_state_dep_a_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_linux_mem_state_dep_a_t *msg) {
    return sbp_msg_linux_mem_state_dep_a_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_linux_mem_state_dep_a_t &msg) {
    return sbp_msg_linux_mem_state_dep_a_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_linux_mem_state_t> {
  static constexpr sbp_msg_type_t id = SbpMsgLinuxMemState;
  static constexpr const char *name = "MSG_LINUX_MEM_STATE";
  static const sbp_msg_linux_mem_state_t &get(const sbp_msg_t &msg) {
    return msg.linux_mem_state;
  }
  static sbp_msg_linux_mem_state_t &get(sbp_msg_t &msg) {
    return msg.linux_mem_state;
  }
  static void to_sbp_msg(const sbp_msg_linux_mem_state_t &msg,
                         sbp_msg_t *sbp_msg) {
    sbp_msg->linux_mem_state = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_linux_mem_state_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.linux_mem_state = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_linux_mem_state_t &msg, sbp_write_fn_t write) {
    return sbp_msg_linux_mem_state_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_linux_mem_state_t &msg) {
    return sbp_msg_linux_mem_state_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_linux_mem_state_t *msg) {
    return sbp_msg_linux_mem_state_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_linux_mem_state_t &msg) {
    return sbp_msg_linux_mem_state_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_linux_process_fd_count_t> {
  static constexpr sbp_msg_type_t id = SbpMsgLinuxProcessFdCount;
  static constexpr const char *name = "MSG_LINUX_PROCESS_FD_COUNT";
  static const sbp_msg_linux_process_fd_count_t &get(const sbp_msg_t &msg) {
    return msg.linux_process_fd_count;
  }
  static sbp_msg_linux_process_fd_count_t &get(sbp_msg_t &msg) {
    return msg.linux_process_fd_count;
  }
  static void to_sbp_msg(const sbp_msg_linux_process_fd_count_t &msg,
                         sbp_msg_t *sbp_msg) {
    sbp_msg->linux_process_fd_count = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_linux_process_fd_count_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.linux_process_fd_count = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_linux_process_fd_count_t &msg,
                 sbp_write_fn_t write) {
    return sbp_msg_linux_process_fd_count_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_linux_process_fd_count_t &msg) {
    return sbp_msg_linux_process_fd_count_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_linux_process_fd_count_t *msg) {
    return sbp_msg_linux_process_fd_count_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_linux_process_fd_count_t &msg) {
    return sbp_msg_linux_process_fd_count_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_linux_process_fd_summary_t> {
  static constexpr sbp_msg_type_t id = SbpMsgLinuxProcessFdSummary;
  static constexpr const char *name = "MSG_LINUX_PROCESS_FD_SUMMARY";
  static const sbp_msg_linux_process_fd_summary_t &get(const sbp_msg_t &msg) {
    return msg.linux_process_fd_summary;
  }
  static sbp_msg_linux_process_fd_summary_t &get(sbp_msg_t &msg) {
    return msg.linux_process_fd_summary;
  }
  static void to_sbp_msg(const sbp_msg_linux_process_fd_summary_t &msg,
                         sbp_msg_t *sbp_msg) {
    sbp_msg->linux_process_fd_summary = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_linux_process_fd_summary_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.linux_process_fd_summary = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_linux_process_fd_summary_t &msg,
                 sbp_write_fn_t write) {
    return sbp_msg_linux_process_fd_summary_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_linux_process_fd_summary_t &msg) {
    return sbp_msg_linux_process_fd_summary_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_linux_process_fd_summary_t *msg) {
    return sbp_msg_linux_process_fd_summary_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_linux_process_fd_summary_t &msg) {
    return sbp_msg_linux_process_fd_summary_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_linux_process_socket_counts_t> {
  static constexpr sbp_msg_type_t id = SbpMsgLinuxProcessSocketCounts;
  static constexpr const char *name = "MSG_LINUX_PROCESS_SOCKET_COUNTS";
  static const sbp_msg_linux_process_socket_counts_t &get(
      const sbp_msg_t &msg) {
    return msg.linux_process_socket_counts;
  }
  static sbp_msg_linux_process_socket_counts_t &get(sbp_msg_t &msg) {
    return msg.linux_process_socket_counts;
  }
  static void to_sbp_msg(const sbp_msg_linux_process_socket_counts_t &msg,
                         sbp_msg_t *sbp_msg) {
    sbp_msg->linux_process_socket_counts = msg;
  }
  static sbp_msg_t to_sbp_msg(
      const sbp_msg_linux_process_socket_counts_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.linux_process_socket_counts = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_linux_process_socket_counts_t &msg,
                 sbp_write_fn_t write) {
    return sbp_msg_linux_process_socket_counts_send(state, sender_id, &msg,
                                                    write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_linux_process_socket_counts_t &msg) {
    return sbp_msg_linux_process_socket_counts_encode(buf, len, n_written,
                                                      &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_linux_process_socket_counts_t *msg) {
    return sbp_msg_linux_process_socket_counts_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_linux_process_socket_counts_t &msg) {
    return sbp_msg_linux_process_socket_counts_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_linux_process_socket_queues_t> {
  static constexpr sbp_msg_type_t id = SbpMsgLinuxProcessSocketQueues;
  static constexpr const char *name = "MSG_LINUX_PROCESS_SOCKET_QUEUES";
  static const sbp_msg_linux_process_socket_queues_t &get(
      const sbp_msg_t &msg) {
    return msg.linux_process_socket_queues;
  }
  static sbp_msg_linux_process_socket_queues_t &get(sbp_msg_t &msg) {
    return msg.linux_process_socket_queues;
  }
  static void to_sbp_msg(const sbp_msg_linux_process_socket_queues_t &msg,
                         sbp_msg_t *sbp_msg) {
    sbp_msg->linux_process_socket_queues = msg;
  }
  static sbp_msg_t to_sbp_msg(
      const sbp_msg_linux_process_socket_queues_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.linux_process_socket_queues = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_linux_process_socket_queues_t &msg,
                 sbp_write_fn_t write) {
    return sbp_msg_linux_process_socket_queues_send(state, sender_id, &msg,
                                                    write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_linux_process_socket_queues_t &msg) {
    return sbp_msg_linux_process_socket_queues_encode(buf, len, n_written,
                                                      &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_linux_process_socket_queues_t *msg) {
    return sbp_msg_linux_process_socket_queues_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_linux_process_socket_queues_t &msg) {
    return sbp_msg_linux_process_socket_queues_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_linux_socket_usage_t> {
  static constexpr sbp_msg_type_t id = SbpMsgLinuxSocketUsage;
  static constexpr const char *name = "MSG_LINUX_SOCKET_USAGE";
  static const sbp_msg_linux_socket_usage_t &get(const sbp_msg_t &msg) {
    return msg.linux_socket_usage;
  }
  static sbp_msg_linux_socket_usage_t &get(sbp_msg_t &msg) {
    return msg.linux_socket_usage;
  }
  static void to_sbp_msg(const sbp_msg_linux_socket_usage_t &msg,
                         sbp_msg_t *sbp_msg) {
    sbp_msg->linux_socket_usage = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_linux_socket_usage_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.linux_socket_usage = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_linux_socket_usage_t &msg,
                 sbp_write_fn_t write) {
    return sbp_msg_linux_socket_usage_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_linux_socket_usage_t &msg) {
    return sbp_msg_linux_socket_usage_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_linux_socket_usage_t *msg) {
    return sbp_msg_linux_socket_usage_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_linux_socket_usage_t &msg) {
    return sbp_msg_linux_socket_usage_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_linux_sys_state_dep_a_t> {
  static constexpr sbp_msg_type_t id = SbpMsgLinuxSysStateDepA;
  static constexpr const char *name = "MSG_LINUX_SYS_STATE_DEP_A";
  static const sbp_msg_linux_sys_state_dep_a_t &get(const sbp_msg_t &msg) {
    return msg.linux_sys_state_dep_a;
  }
  static sbp_msg_linux_sys_state_dep_a_t &get(sbp_msg_t &msg) {
    return msg.linux_sys_state_dep_a;
  }
  static void to_sbp_msg(const sbp_msg_linux_sys_state_dep_a_t &msg,
                         sbp_msg_t *sbp_msg) {
    sbp_msg->linux_sys_state_dep_a = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_linux_sys_state_dep_a_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.linux_sys_state_dep_a = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_linux_sys_state_dep_a_t &msg,
                 sbp_write_fn_t write) {
    return sbp_msg_linux_sys_state_dep_a_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_linux_sys_state_dep_a_t &msg) {
    return sbp_msg_linux_sys_state_dep_a_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_linux_sys_state_dep_a_t *msg) {
    return sbp_msg_linux_sys_state_dep_a_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_linux_sys_state_dep_a_t &msg) {
    return sbp_msg_linux_sys_state_dep_a_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_linux_sys_state_t> {
  static constexpr sbp_msg_type_t id = SbpMsgLinuxSysState;
  static constexpr const char *name = "MSG_LINUX_SYS_STATE";
  static const sbp_msg_linux_sys_state_t &get(const sbp_msg_t &msg) {
    return msg.linux_sys_state;
  }
  static sbp_msg_linux_sys_state_t &get(sbp_msg_t &msg) {
    return msg.linux_sys_state;
  }
  static void to_sbp_msg(const sbp_msg_linux_sys_state_t &msg,
                         sbp_msg_t *sbp_msg) {
    sbp_msg->linux_sys_state = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_linux_sys_state_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.linux_sys_state = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_linux_sys_state_t &msg, sbp_write_fn_t write) {
    return sbp_msg_linux_sys_state_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_linux_sys_state_t &msg) {
    return sbp_msg_linux_sys_state_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_linux_sys_state_t *msg) {
    return sbp_msg_linux_sys_state_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_linux_sys_state_t &msg) {
    return sbp_msg_linux_sys_state_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_log_t> {
  static constexpr sbp_msg_type_t id = SbpMsgLog;
  static constexpr const char *name = "MSG_LOG";
  static const sbp_msg_log_t &get(const sbp_msg_t &msg) { return msg.log; }
  static sbp_msg_log_t &get(sbp_msg_t &msg) { return msg.log; }
  static void to_sbp_msg(const sbp_msg_log_t &msg, sbp_msg_t *sbp_msg) {
    sbp_msg->log = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_log_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.log = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_log_t &msg,
                 sbp_write_fn_t write) {
    return sbp_msg_log_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_log_t &msg) {
    return sbp_msg_log_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_log_t *msg) {
    return sbp_msg_log_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_log_t &msg) {
    return sbp_msg_log_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_m25_flash_write_status_t> {
  static constexpr sbp_msg_type_t id = SbpMsgM25FlashWriteStatus;
  static constexpr const char *name = "MSG_M25_FLASH_WRITE_STATUS";
  static const sbp_msg_m25_flash_write_status_t &get(const sbp_msg_t &msg) {
    return msg.m25_flash_write_status;
  }
  static sbp_msg_m25_flash_write_status_t &get(sbp_msg_t &msg) {
    return msg.m25_flash_write_status;
  }
  static void to_sbp_msg(const sbp_msg_m25_flash_write_status_t &msg,
                         sbp_msg_t *sbp_msg) {
    sbp_msg->m25_flash_write_status = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_m25_flash_write_status_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.m25_flash_write_status = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_m25_flash_write_status_t &msg,
                 sbp_write_fn_t write) {
    return sbp_msg_m25_flash_write_status_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_m25_flash_write_status_t &msg) {
    return sbp_msg_m25_flash_write_status_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_m25_flash_write_status_t *msg) {
    return sbp_msg_m25_flash_write_status_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_m25_flash_write_status_t &msg) {
    return sbp_msg_m25_flash_write_status_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_mag_raw_t> {
  static constexpr sbp_msg_type_t id = SbpMsgMagRaw;
  static constexpr const char *name = "MSG_MAG_RAW";
  static const sbp_msg_mag_raw_t &get(const sbp_msg_t &msg) {
    return msg.mag_raw;
  }
  static sbp_msg_mag_raw_t &get(sbp_msg_t &msg) { return msg.mag_raw; }
  static void to_sbp_msg(const sbp_msg_mag_raw_t &msg, sbp_msg_t *sbp_msg) {
    sbp_msg->mag_raw = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_mag_raw_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.mag_raw = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_mag_raw_t &msg, sbp_write_fn_t write) {
    return sbp_msg_mag_raw_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_mag_raw_t &msg) {
    return sbp_msg_mag_raw_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_mag_raw_t *msg) {
    return sbp_msg_mag_raw_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_mag_raw_t &msg) {
    return sbp_msg_mag_raw_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_mask_satellite_dep_t> {
  static constexpr sbp_msg_type_t id = SbpMsgMaskSatelliteDep;
  static constexpr const char *name = "MSG_MASK_SATELLITE_DEP";
  static const sbp_msg_mask_satellite_dep_t &get(const sbp_msg_t &msg) {
    return msg.mask_satellite_dep;
  }
  static sbp_msg_mask_satellite_dep_t &get(sbp_msg_t &msg) {
    return msg.mask_satellite_dep;
  }
  static void to_sbp_msg(const sbp_msg_mask_satellite_dep_t &msg,
                         sbp_msg_t *sbp_msg) {
    sbp_msg->mask_satellite_dep = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_mask_satellite_dep_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.mask_satellite_dep = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_mask_satellite_dep_t &msg,
                 sbp_write_fn_t write) {
    return sbp_msg_mask_satellite_dep_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_mask_satellite_dep_t &msg) {
    return sbp_msg_mask_satellite_dep_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_mask_satellite_dep_t *msg) {
    return sbp_msg_mask_satellite_dep_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_mask_satellite_dep_t &msg) {
    return sbp_msg_mask_satellite_dep_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_mask_satellite_t> {
  static constexpr sbp_msg_type_t id = SbpMsgMaskSatellite;
  static constexpr const char *name = "MSG_MASK_SATELLITE";
  static const sbp_msg_mask_satellite_t &get(const sbp_msg_t &msg) {
    return msg.mask_satellite;
  }
  static sbp_msg_mask_satellite_t &get(sbp_msg_t &msg) {
    return msg.mask_satellite;
  }
  static void to_sbp_msg(const sbp_msg_mask_satellite_t &msg,
                         sbp_msg_t *sbp_msg) {
    sbp_msg->mask_satellite = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_mask_satellite_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.mask_satellite = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_mask_satellite_t &msg, sbp_write_fn_t write) {
    return sbp_msg_mask_satellite_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_mask_satellite_t &msg) {
    return sbp_msg_mask_satellite_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_mask_satellite_t *msg) {
    return sbp_msg_mask_satellite_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_mask_satellite_t &msg) {
    return sbp_msg_mask_satellite_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_measurement_point_t> {
  static constexpr sbp_msg_type_t id = SbpMsgMeasurementPoint;
  static constexpr const char *name = "MSG_MEASUREMENT_POINT";
  static const sbp_msg_measurement_point_t &get(const sbp_msg_t &msg) {
    return msg.measurement_point;
  }
  static sbp_msg_measurement_point_t &get(sbp_msg_t &msg) {
    return msg.measurement_point;
  }
  static void to_sbp_msg(const sbp_msg_measurement_point_t &msg,
                         sbp_msg_t *sbp_msg) {
    sbp_msg->measurement_point = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_measurement_point_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.measurement_point = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_measurement_point_t &msg, sbp_write_fn_t write) {
    return sbp_msg_measurement_point_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_measurement_point_t &msg) {
    return sbp_msg_measurement_point_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_measurement_point_t *msg) {
    return sbp_msg_measurement_point_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_measurement_point_t &msg) {
    return sbp_msg_measurement_point_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_measurement_state_t> {
  static constexpr sbp_msg_type_t id = SbpMsgMeasurementState;
  static constexpr const char *name = "MSG_MEASUREMENT_STATE";
  static const sbp_msg_measurement_state_t &get(const sbp_msg_t &msg) {
    return msg.measurement_state;
  }
  static sbp_msg_measurement_state_t &get(sbp_msg_t &msg) {
    return msg.measurement_state;
  }
  static void to_sbp_msg(const sbp_msg_measurement_state_t &msg,
                         sbp_msg_t *sbp_msg) {
    sbp_msg->measurement_state = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_measurement_state_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.measurement_state = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_measurement_state_t &msg, sbp_write_fn_t write) {
    return sbp_msg_measurement_state_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_measurement_state_t &msg) {
    return sbp_msg_measurement_state_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_measurement_state_t *msg) {
    return sbp_msg_measurement_state_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_measurement_state_t &msg) {
    return sbp_msg_measurement_state_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_nap_device_dna_req_t> {
  static constexpr sbp_msg_type_t id = SbpMsgNapDeviceDnaReq;
  static constexpr const char *name = "MSG_NAP_DEVICE_DNA_REQ";
  static const sbp_msg_nap_device_dna_req_t &get(const sbp_msg_t &msg) {
    return msg.nap_device_dna_req;
  }
  static sbp_msg_nap_device_dna_req_t &get(sbp_msg_t &msg) {
    return msg.nap_device_dna_req;
  }
  static void to_sbp_msg(const sbp_msg_nap_device_dna_req_t &msg,
                         sbp_msg_t *sbp_msg) {
    sbp_msg->nap_device_dna_req = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_nap_device_dna_req_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.nap_device_dna_req = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_nap_device_dna_req_t &msg,
                 sbp_write_fn_t write) {
    return sbp_msg_nap_device_dna_req_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_nap_device_dna_req_t &msg) {
    return sbp_msg_nap_device_dna_req_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_nap_device_dna_req_t *msg) {
    return sbp_msg_nap_device_dna_req_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_nap_device_dna_req_t &msg) {
    return sbp_msg_nap_device_dna_req_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_nap_device_dna_resp_t> {
  static constexpr sbp_msg_type_t id = SbpMsgNapDeviceDnaResp;
  static constexpr const char *name = "MSG_NAP_DEVICE_DNA_RESP";
  static const sbp_msg_nap_device_dna_resp_t &get(const sbp_msg_t &msg) {
    return msg.nap_device_dna_resp;
  }
  static sbp_msg_nap_device_dna_resp_t &get(sbp_msg_t &msg) {
    return msg.nap_device_dna_resp;
  }
  static void to_sbp_msg(const sbp_msg_nap_device_dna_resp_t &msg,
                         sbp_msg_t *sbp_msg) {
    sbp_msg->nap_device_dna_resp = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_nap_device_dna_resp_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.nap_device_dna_resp = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_nap_device_dna_resp_t &msg,
                 sbp_write_fn_t write) {
    return sbp_msg_nap_device_dna_resp_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_nap_device_dna_resp_t &msg) {
    return sbp_msg_nap_device_dna_resp_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_nap_device_dna_resp_t *msg) {
    return sbp_msg_nap_device_dna_resp_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_nap_device_dna_resp_t &msg) {
    return sbp_msg_nap_device_dna_resp_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_ndb_event_t> {
  static constexpr sbp_msg_type_t id = SbpMsgNdbEvent;
  static constexpr const char *name = "MSG_NDB_EVENT";
  static const sbp_msg_ndb_event_t &get(const sbp_msg_t &msg) {
    return msg.ndb_event;
  }
  static sbp_msg_ndb_event_t &get(sbp_msg_t &msg) { return msg.ndb_event; }
  static void to_sbp_msg(const sbp_msg_ndb_event_t &msg, sbp_msg_t *sbp_msg) {
    sbp_msg->ndb_event = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_ndb_event_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.ndb_event = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_ndb_event_t &msg, sbp_write_fn_t write) {
    return sbp_msg_ndb_event_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_ndb_event_t &msg) {
    return sbp_msg_ndb_event_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_ndb_event_t *msg) {
    return sbp_msg_ndb_event_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_ndb_event_t &msg) {
    return sbp_msg_ndb_event_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_network_bandwidth_usage_t> {
  static constexpr sbp_msg_type_t id = SbpMsgNetworkBandwidthUsage;
  static constexpr const char *name = "MSG_NETWORK_BANDWIDTH_USAGE";
  static const sbp_msg_network_bandwidth_usage_t &get(const sbp_msg_t &msg) {
    return msg.network_bandwidth_usage;
  }
  static sbp_msg_network_bandwidth_usage_t &get(sbp_msg_t &msg) {
    return msg.network_bandwidth_usage;
  }
  static void to_sbp_msg(const sbp_msg_network_bandwidth_usage_t &msg,
                         sbp_msg_t *sbp_msg) {
    sbp_msg->network_bandwidth_usage = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_network_bandwidth_usage_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.network_bandwidth_usage = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_network_bandwidth_usage_t &msg,
                 sbp_write_fn_t write) {
    return sbp_msg_network_bandwidth_usage_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_network_bandwidth_usage_t &msg) {
    return sbp_msg_network_bandwidth_usage_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_network_bandwidth_usage_t *msg) {
    return sbp_msg_network_bandwidth_usage_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_network_bandwidth_usage_t &msg) {
    return sbp_msg_network_bandwidth_usage_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_network_state_req_t> {
  static constexpr sbp_msg_type_t id = SbpMsgNetworkStateReq;
  static constexpr const char *name = "MSG_NETWORK_STATE_REQ";
  static const sbp_msg_network_state_req_t &get(const sbp_msg_t &msg) {
    return msg.network_state_req;
  }
  static sbp_msg_network_state_req_t &get(sbp_msg_t &msg) {
    return msg.network_state_req;
  }
  static void to_sbp_msg(const sbp_msg_network_state_req_t &msg,
                         sbp_msg_t *sbp_msg) {
    sbp_msg->network_state_req = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_network_state_req_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.network_state_req = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_network_state_req_t &msg, sbp_write_fn_t write) {
    return sbp_msg_network_state_req_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_network_state_req_t &msg) {
    return sbp_msg_network_state_req_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_network_state_req_t *msg) {
    return sbp_msg_network_state_req_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_network_state_req_t &msg) {
    return sbp_msg_network_state_req_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_network_state_resp_t> {
  static constexpr sbp_msg_type_t id = SbpMsgNetworkStateResp;
  static constexpr const char *name = "MSG_NETWORK_STATE_RESP";
  static const sbp_msg_network_state_resp_t &get(const sbp_msg_t &msg) {
    return msg.network_state_resp;
  }
  static sbp_msg_network_state_resp_t &get(sbp_msg_t &msg) {
    return msg.network_state_resp;
  }
  static void to_sbp_msg(const sbp_msg_network_state_resp_t &msg,
                         sbp_msg_t *sbp_msg) {
    sbp_msg->network_state_resp = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_network_state_resp_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.network_state_resp = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_network_state_resp_t &msg,
                 sbp_write_fn_t write) {
    return sbp_msg_network_state_resp_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_network_state_resp_t &msg) {
    return sbp_msg_network_state_resp_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_network_state_resp_t *msg) {
    return sbp_msg_network_state_resp_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_network_state_resp_t &msg) {
    return sbp_msg_network_state_resp_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_obs_dep_a_t> {
  static constexpr sbp_msg_type_t id = SbpMsgObsDepA;
  static constexpr const char *name = "MSG_OBS_DEP_A";
  static const sbp_msg_obs_dep_a_t &get(const sbp_msg_t &msg) {
    return msg.obs_dep_a;
  }
  static sbp_msg_obs_dep_a_t &get(sbp_msg_t &msg) { return msg.obs_dep_a; }
  static void to_sbp_msg(const sbp_msg_obs_dep_a_t &msg, sbp_msg_t *sbp_msg) {
    sbp_msg->obs_dep_a = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_obs_dep_a_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.obs_dep_a = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_obs_dep_a_t &msg, sbp_write_fn_t write) {
    return sbp_msg_obs_dep_a_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_obs_dep_a_t &msg) {
    return sbp_msg_obs_dep_a_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_obs_dep_a_t *msg) {
    return sbp_msg_obs_dep_a_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_obs_dep_a_t &msg) {
    return sbp_msg_obs_dep_a_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_obs_dep_b_t> {
  static constexpr sbp_msg_type_t id = SbpMsgObsDepB;
  static constexpr const char *name = "MSG_OBS_DEP_B";
  static const sbp_msg_obs_dep_b_t &get(const sbp_msg_t &msg) {
    return msg.obs_dep_b;
  }
  static sbp_msg_obs_dep_b_t &get(sbp_msg_t &msg) { return msg.obs_dep_b; }
  static void to_sbp_msg(const sbp_msg_obs_dep_b_t &msg, sbp_msg_t *sbp_msg) {
    sbp_msg->obs_dep_b = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_obs_dep_b_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.obs_dep_b = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_obs_dep_b_t &msg, sbp_write_fn_t write) {
    return sbp_msg_obs_dep_b_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_obs_dep_b_t &msg) {
    return sbp_msg_obs_dep_b_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_obs_dep_b_t *msg) {
    return sbp_msg_obs_dep_b_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_obs_dep_b_t &msg) {
    return sbp_msg_obs_dep_b_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_obs_dep_c_t> {
  static constexpr sbp_msg_type_t id = SbpMsgObsDepC;
  static constexpr const char *name = "MSG_OBS_DEP_C";
  static const sbp_msg_obs_dep_c_t &get(const sbp_msg_t &msg) {
    return msg.obs_dep_c;
  }
  static sbp_msg_obs_dep_c_t &get(sbp_msg_t &msg) { return msg.obs_dep_c; }
  static void to_sbp_msg(const sbp_msg_obs_dep_c_t &msg, sbp_msg_t *sbp_msg) {
    sbp_msg->obs_dep_c = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_obs_dep_c_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.obs_dep_c = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_obs_dep_c_t &msg, sbp_write_fn_t write) {
    return sbp_msg_obs_dep_c_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_obs_dep_c_t &msg) {
    return sbp_msg_obs_dep_c_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_obs_dep_c_t *msg) {
    return sbp_msg_obs_dep_c_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_obs_dep_c_t &msg) {
    return sbp_msg_obs_dep_c_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_obs_t> {
  static constexpr sbp_msg_type_t id = SbpMsgObs;
  static constexpr const char *name = "MSG_OBS";
  static const sbp_msg_obs_t &get(const sbp_msg_t &msg) { return msg.obs; }
  static sbp_msg_obs_t &get(sbp_msg_t &msg) { return msg.obs; }
  static void to_sbp_msg(const sbp_msg_obs_t &msg, sbp_msg_t *sbp_msg) {
    sbp_msg->obs = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_obs_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.obs = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_obs_t &msg,
                 sbp_write_fn_t write) {
    return sbp_msg_obs_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_obs_t &msg) {
    return sbp_msg_obs_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_obs_t *msg) {
    return sbp_msg_obs_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_obs_t &msg) {
    return sbp_msg_obs_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_odometry_t> {
  static constexpr sbp_msg_type_t id = SbpMsgOdometry;
  static constexpr const char *name = "MSG_ODOMETRY";
  static const sbp_msg_odometry_t &get(const sbp_msg_t &msg) {
    return msg.odometry;
  }
  static sbp_msg_odometry_t &get(sbp_msg_t &msg) { return msg.odometry; }
  static void to_sbp_msg(const sbp_msg_odometry_t &msg, sbp_msg_t *sbp_msg) {
    sbp_msg->odometry = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_odometry_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.odometry = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_odometry_t &msg, sbp_write_fn_t write) {
    return sbp_msg_odometry_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_odometry_t &msg) {
    return sbp_msg_odometry_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_odometry_t *msg) {
    return sbp_msg_odometry_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_odometry_t &msg) {
    return sbp_msg_odometry_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_orient_euler_t> {
  static constexpr sbp_msg_type_t id = SbpMsgOrientEuler;
  static constexpr const char *name = "MSG_ORIENT_EULER";
  static const sbp_msg_orient_euler_t &get(const sbp_msg_t &msg) {
    return msg.orient_euler;
  }
  static sbp_msg_orient_euler_t &get(sbp_msg_t &msg) {
    return msg.orient_euler;
  }
  static void to_sbp_msg(const sbp_msg_orient_euler_t &msg,
                         sbp_msg_t *sbp_msg) {
    sbp_msg->orient_euler = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_orient_euler_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.orient_euler = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_orient_euler_t &msg, sbp_write_fn_t write) {
    return sbp_msg_orient_euler_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_orient_euler_t &msg) {
    return sbp_msg_orient_euler_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_orient_euler_t *msg) {
    return sbp_msg_orient_euler_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_orient_euler_t &msg) {
    return sbp_msg_orient_euler_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_orient_quat_t> {
  static constexpr sbp_msg_type_t id = SbpMsgOrientQuat;
  static constexpr const char *name = "MSG_ORIENT_QUAT";
  static const sbp_msg_orient_quat_t &get(const sbp_msg_t &msg) {
    return msg.orient_quat;
  }
  static sbp_msg_orient_quat_t &get(sbp_msg_t &msg) { return msg.orient_quat; }
  static void to_sbp_msg(const sbp_msg_orient_quat_t &msg, sbp_msg_t *sbp_msg) {
    sbp_msg->orient_quat = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_orient_quat_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.orient_quat = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_orient_quat_t &msg, sbp_write_fn_t write) {
    return sbp_msg_orient_quat_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_orient_quat_t &msg) {
    return sbp_msg_orient_quat_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_orient_quat_t *msg) {
    return sbp_msg_orient_quat_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_orient_quat_t &msg) {
    return sbp_msg_orient_quat_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_osr_t> {
  static constexpr sbp_msg_type_t id = SbpMsgOsr;
  static constexpr const char *name = "MSG_OSR";
  static const sbp_msg_osr_t &get(const sbp_msg_t &msg) { return msg.osr; }
  static sbp_msg_osr_t &get(sbp_msg_t &msg) { return msg.osr; }
  static void to_sbp_msg(const sbp_msg_osr_t &msg, sbp_msg_t *sbp_msg) {
    sbp_msg->osr = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_osr_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.osr = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_osr_t &msg,
                 sbp_write_fn_t write) {
    return sbp_msg_osr_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_osr_t &msg) {
    return sbp_msg_osr_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_osr_t *msg) {
    return sbp_msg_osr_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_osr_t &msg) {
    return sbp_msg_osr_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_pos_ecef_cov_gnss_t> {
  static constexpr sbp_msg_type_t id = SbpMsgPosEcefCovGnss;
  static constexpr const char *name = "MSG_POS_ECEF_COV_GNSS";
  static const sbp_msg_pos_ecef_cov_gnss_t &get(const sbp_msg_t &msg) {
    return msg.pos_ecef_cov_gnss;
  }
  static sbp_msg_pos_ecef_cov_gnss_t &get(sbp_msg_t &msg) {
    return msg.pos_ecef_cov_gnss;
  }
  static void to_sbp_msg(const sbp_msg_pos_ecef_cov_gnss_t &msg,
                         sbp_msg_t *sbp_msg) {
    sbp_msg->pos_ecef_cov_gnss = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_pos_ecef_cov_gnss_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.pos_ecef_cov_gnss = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_pos_ecef_cov_gnss_t &msg, sbp_write_fn_t write) {
    return sbp_msg_pos_ecef_cov_gnss_send(state, sender_id, &msg, write);
  }
  static sbp_msg_pos_ecef_cov_gnss_t to_gnss(
      const sbp_msg_pos_ecef_cov_gnss_t &msg) {
    return msg;
  }
  static sbp_msg_pos_ecef_cov_t to_non_gnss(
      const sbp_msg_pos_ecef_cov_gnss_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.pos_ecef_cov_gnss = msg;
    return sbp_msg.pos_ecef_cov;
  }

  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_pos_ecef_cov_gnss_t &msg) {
    return sbp_msg_pos_ecef_cov_gnss_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_pos_ecef_cov_gnss_t *msg) {
    return sbp_msg_pos_ecef_cov_gnss_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_pos_ecef_cov_gnss_t &msg) {
    return sbp_msg_pos_ecef_cov_gnss_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_pos_ecef_cov_t> {
  static constexpr sbp_msg_type_t id = SbpMsgPosEcefCov;
  static constexpr const char *name = "MSG_POS_ECEF_COV";
  static const sbp_msg_pos_ecef_cov_t &get(const sbp_msg_t &msg) {
    return msg.pos_ecef_cov;
  }
  static sbp_msg_pos_ecef_cov_t &get(sbp_msg_t &msg) {
    return msg.pos_ecef_cov;
  }
  static void to_sbp_msg(const sbp_msg_pos_ecef_cov_t &msg,
                         sbp_msg_t *sbp_msg) {
    sbp_msg->pos_ecef_cov = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_pos_ecef_cov_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.pos_ecef_cov = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_pos_ecef_cov_t &msg, sbp_write_fn_t write) {
    return sbp_msg_pos_ecef_cov_send(state, sender_id, &msg, write);
  }
  static sbp_msg_pos_ecef_cov_gnss_t to_gnss(
      const sbp_msg_pos_ecef_cov_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.pos_ecef_cov = msg;
    return sbp_msg.pos_ecef_cov_gnss;
  }
  static sbp_msg_pos_ecef_cov_t to_non_gnss(const sbp_msg_pos_ecef_cov_t &msg) {
    return msg;
  }

  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_pos_ecef_cov_t &msg) {
    return sbp_msg_pos_ecef_cov_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_pos_ecef_cov_t *msg) {
    return sbp_msg_pos_ecef_cov_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_pos_ecef_cov_t &msg) {
    return sbp_msg_pos_ecef_cov_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_pos_ecef_dep_a_t> {
  static constexpr sbp_msg_type_t id = SbpMsgPosEcefDepA;
  static constexpr const char *name = "MSG_POS_ECEF_DEP_A";
  static const sbp_msg_pos_ecef_dep_a_t &get(const sbp_msg_t &msg) {
    return msg.pos_ecef_dep_a;
  }
  static sbp_msg_pos_ecef_dep_a_t &get(sbp_msg_t &msg) {
    return msg.pos_ecef_dep_a;
  }
  static void to_sbp_msg(const sbp_msg_pos_ecef_dep_a_t &msg,
                         sbp_msg_t *sbp_msg) {
    sbp_msg->pos_ecef_dep_a = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_pos_ecef_dep_a_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.pos_ecef_dep_a = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_pos_ecef_dep_a_t &msg, sbp_write_fn_t write) {
    return sbp_msg_pos_ecef_dep_a_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_pos_ecef_dep_a_t &msg) {
    return sbp_msg_pos_ecef_dep_a_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_pos_ecef_dep_a_t *msg) {
    return sbp_msg_pos_ecef_dep_a_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_pos_ecef_dep_a_t &msg) {
    return sbp_msg_pos_ecef_dep_a_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_pos_ecef_gnss_t> {
  static constexpr sbp_msg_type_t id = SbpMsgPosEcefGnss;
  static constexpr const char *name = "MSG_POS_ECEF_GNSS";
  static const sbp_msg_pos_ecef_gnss_t &get(const sbp_msg_t &msg) {
    return msg.pos_ecef_gnss;
  }
  static sbp_msg_pos_ecef_gnss_t &get(sbp_msg_t &msg) {
    return msg.pos_ecef_gnss;
  }
  static void to_sbp_msg(const sbp_msg_pos_ecef_gnss_t &msg,
                         sbp_msg_t *sbp_msg) {
    sbp_msg->pos_ecef_gnss = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_pos_ecef_gnss_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.pos_ecef_gnss = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_pos_ecef_gnss_t &msg, sbp_write_fn_t write) {
    return sbp_msg_pos_ecef_gnss_send(state, sender_id, &msg, write);
  }
  static sbp_msg_pos_ecef_gnss_t to_gnss(const sbp_msg_pos_ecef_gnss_t &msg) {
    return msg;
  }
  static sbp_msg_pos_ecef_t to_non_gnss(const sbp_msg_pos_ecef_gnss_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.pos_ecef_gnss = msg;
    return sbp_msg.pos_ecef;
  }

  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_pos_ecef_gnss_t &msg) {
    return sbp_msg_pos_ecef_gnss_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_pos_ecef_gnss_t *msg) {
    return sbp_msg_pos_ecef_gnss_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_pos_ecef_gnss_t &msg) {
    return sbp_msg_pos_ecef_gnss_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_pos_ecef_t> {
  static constexpr sbp_msg_type_t id = SbpMsgPosEcef;
  static constexpr const char *name = "MSG_POS_ECEF";
  static const sbp_msg_pos_ecef_t &get(const sbp_msg_t &msg) {
    return msg.pos_ecef;
  }
  static sbp_msg_pos_ecef_t &get(sbp_msg_t &msg) { return msg.pos_ecef; }
  static void to_sbp_msg(const sbp_msg_pos_ecef_t &msg, sbp_msg_t *sbp_msg) {
    sbp_msg->pos_ecef = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_pos_ecef_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.pos_ecef = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_pos_ecef_t &msg, sbp_write_fn_t write) {
    return sbp_msg_pos_ecef_send(state, sender_id, &msg, write);
  }
  static sbp_msg_pos_ecef_gnss_t to_gnss(const sbp_msg_pos_ecef_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.pos_ecef = msg;
    return sbp_msg.pos_ecef_gnss;
  }
  static sbp_msg_pos_ecef_t to_non_gnss(const sbp_msg_pos_ecef_t &msg) {
    return msg;
  }

  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_pos_ecef_t &msg) {
    return sbp_msg_pos_ecef_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_pos_ecef_t *msg) {
    return sbp_msg_pos_ecef_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_pos_ecef_t &msg) {
    return sbp_msg_pos_ecef_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_pos_llh_acc_t> {
  static constexpr sbp_msg_type_t id = SbpMsgPosLlhAcc;
  static constexpr const char *name = "MSG_POS_LLH_ACC";
  static const sbp_msg_pos_llh_acc_t &get(const sbp_msg_t &msg) {
    return msg.pos_llh_acc;
  }
  static sbp_msg_pos_llh_acc_t &get(sbp_msg_t &msg) { return msg.pos_llh_acc; }
  static void to_sbp_msg(const sbp_msg_pos_llh_acc_t &msg, sbp_msg_t *sbp_msg) {
    sbp_msg->pos_llh_acc = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_pos_llh_acc_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.pos_llh_acc = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_pos_llh_acc_t &msg, sbp_write_fn_t write) {
    return sbp_msg_pos_llh_acc_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_pos_llh_acc_t &msg) {
    return sbp_msg_pos_llh_acc_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_pos_llh_acc_t *msg) {
    return sbp_msg_pos_llh_acc_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_pos_llh_acc_t &msg) {
    return sbp_msg_pos_llh_acc_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_pos_llh_cov_gnss_t> {
  static constexpr sbp_msg_type_t id = SbpMsgPosLlhCovGnss;
  static constexpr const char *name = "MSG_POS_LLH_COV_GNSS";
  static const sbp_msg_pos_llh_cov_gnss_t &get(const sbp_msg_t &msg) {
    return msg.pos_llh_cov_gnss;
  }
  static sbp_msg_pos_llh_cov_gnss_t &get(sbp_msg_t &msg) {
    return msg.pos_llh_cov_gnss;
  }
  static void to_sbp_msg(const sbp_msg_pos_llh_cov_gnss_t &msg,
                         sbp_msg_t *sbp_msg) {
    sbp_msg->pos_llh_cov_gnss = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_pos_llh_cov_gnss_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.pos_llh_cov_gnss = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_pos_llh_cov_gnss_t &msg, sbp_write_fn_t write) {
    return sbp_msg_pos_llh_cov_gnss_send(state, sender_id, &msg, write);
  }
  static sbp_msg_pos_llh_cov_gnss_t to_gnss(
      const sbp_msg_pos_llh_cov_gnss_t &msg) {
    return msg;
  }
  static sbp_msg_pos_llh_cov_t to_non_gnss(
      const sbp_msg_pos_llh_cov_gnss_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.pos_llh_cov_gnss = msg;
    return sbp_msg.pos_llh_cov;
  }

  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_pos_llh_cov_gnss_t &msg) {
    return sbp_msg_pos_llh_cov_gnss_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_pos_llh_cov_gnss_t *msg) {
    return sbp_msg_pos_llh_cov_gnss_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_pos_llh_cov_gnss_t &msg) {
    return sbp_msg_pos_llh_cov_gnss_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_pos_llh_cov_t> {
  static constexpr sbp_msg_type_t id = SbpMsgPosLlhCov;
  static constexpr const char *name = "MSG_POS_LLH_COV";
  static const sbp_msg_pos_llh_cov_t &get(const sbp_msg_t &msg) {
    return msg.pos_llh_cov;
  }
  static sbp_msg_pos_llh_cov_t &get(sbp_msg_t &msg) { return msg.pos_llh_cov; }
  static void to_sbp_msg(const sbp_msg_pos_llh_cov_t &msg, sbp_msg_t *sbp_msg) {
    sbp_msg->pos_llh_cov = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_pos_llh_cov_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.pos_llh_cov = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_pos_llh_cov_t &msg, sbp_write_fn_t write) {
    return sbp_msg_pos_llh_cov_send(state, sender_id, &msg, write);
  }
  static sbp_msg_pos_llh_cov_gnss_t to_gnss(const sbp_msg_pos_llh_cov_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.pos_llh_cov = msg;
    return sbp_msg.pos_llh_cov_gnss;
  }
  static sbp_msg_pos_llh_cov_t to_non_gnss(const sbp_msg_pos_llh_cov_t &msg) {
    return msg;
  }

  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_pos_llh_cov_t &msg) {
    return sbp_msg_pos_llh_cov_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_pos_llh_cov_t *msg) {
    return sbp_msg_pos_llh_cov_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_pos_llh_cov_t &msg) {
    return sbp_msg_pos_llh_cov_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_pos_llh_dep_a_t> {
  static constexpr sbp_msg_type_t id = SbpMsgPosLlhDepA;
  static constexpr const char *name = "MSG_POS_LLH_DEP_A";
  static const sbp_msg_pos_llh_dep_a_t &get(const sbp_msg_t &msg) {
    return msg.pos_llh_dep_a;
  }
  static sbp_msg_pos_llh_dep_a_t &get(sbp_msg_t &msg) {
    return msg.pos_llh_dep_a;
  }
  static void to_sbp_msg(const sbp_msg_pos_llh_dep_a_t &msg,
                         sbp_msg_t *sbp_msg) {
    sbp_msg->pos_llh_dep_a = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_pos_llh_dep_a_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.pos_llh_dep_a = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_pos_llh_dep_a_t &msg, sbp_write_fn_t write) {
    return sbp_msg_pos_llh_dep_a_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_pos_llh_dep_a_t &msg) {
    return sbp_msg_pos_llh_dep_a_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_pos_llh_dep_a_t *msg) {
    return sbp_msg_pos_llh_dep_a_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_pos_llh_dep_a_t &msg) {
    return sbp_msg_pos_llh_dep_a_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_pos_llh_gnss_t> {
  static constexpr sbp_msg_type_t id = SbpMsgPosLlhGnss;
  static constexpr const char *name = "MSG_POS_LLH_GNSS";
  static const sbp_msg_pos_llh_gnss_t &get(const sbp_msg_t &msg) {
    return msg.pos_llh_gnss;
  }
  static sbp_msg_pos_llh_gnss_t &get(sbp_msg_t &msg) {
    return msg.pos_llh_gnss;
  }
  static void to_sbp_msg(const sbp_msg_pos_llh_gnss_t &msg,
                         sbp_msg_t *sbp_msg) {
    sbp_msg->pos_llh_gnss = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_pos_llh_gnss_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.pos_llh_gnss = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_pos_llh_gnss_t &msg, sbp_write_fn_t write) {
    return sbp_msg_pos_llh_gnss_send(state, sender_id, &msg, write);
  }
  static sbp_msg_pos_llh_gnss_t to_gnss(const sbp_msg_pos_llh_gnss_t &msg) {
    return msg;
  }
  static sbp_msg_pos_llh_t to_non_gnss(const sbp_msg_pos_llh_gnss_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.pos_llh_gnss = msg;
    return sbp_msg.pos_llh;
  }

  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_pos_llh_gnss_t &msg) {
    return sbp_msg_pos_llh_gnss_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_pos_llh_gnss_t *msg) {
    return sbp_msg_pos_llh_gnss_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_pos_llh_gnss_t &msg) {
    return sbp_msg_pos_llh_gnss_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_pos_llh_t> {
  static constexpr sbp_msg_type_t id = SbpMsgPosLlh;
  static constexpr const char *name = "MSG_POS_LLH";
  static const sbp_msg_pos_llh_t &get(const sbp_msg_t &msg) {
    return msg.pos_llh;
  }
  static sbp_msg_pos_llh_t &get(sbp_msg_t &msg) { return msg.pos_llh; }
  static void to_sbp_msg(const sbp_msg_pos_llh_t &msg, sbp_msg_t *sbp_msg) {
    sbp_msg->pos_llh = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_pos_llh_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.pos_llh = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_pos_llh_t &msg, sbp_write_fn_t write) {
    return sbp_msg_pos_llh_send(state, sender_id, &msg, write);
  }
  static sbp_msg_pos_llh_gnss_t to_gnss(const sbp_msg_pos_llh_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.pos_llh = msg;
    return sbp_msg.pos_llh_gnss;
  }
  static sbp_msg_pos_llh_t to_non_gnss(const sbp_msg_pos_llh_t &msg) {
    return msg;
  }

  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_pos_llh_t &msg) {
    return sbp_msg_pos_llh_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_pos_llh_t *msg) {
    return sbp_msg_pos_llh_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_pos_llh_t &msg) {
    return sbp_msg_pos_llh_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_pose_relative_t> {
  static constexpr sbp_msg_type_t id = SbpMsgPoseRelative;
  static constexpr const char *name = "MSG_POSE_RELATIVE";
  static const sbp_msg_pose_relative_t &get(const sbp_msg_t &msg) {
    return msg.pose_relative;
  }
  static sbp_msg_pose_relative_t &get(sbp_msg_t &msg) {
    return msg.pose_relative;
  }
  static void to_sbp_msg(const sbp_msg_pose_relative_t &msg,
                         sbp_msg_t *sbp_msg) {
    sbp_msg->pose_relative = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_pose_relative_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.pose_relative = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_pose_relative_t &msg, sbp_write_fn_t write) {
    return sbp_msg_pose_relative_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_pose_relative_t &msg) {
    return sbp_msg_pose_relative_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_pose_relative_t *msg) {
    return sbp_msg_pose_relative_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_pose_relative_t &msg) {
    return sbp_msg_pose_relative_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_pps_time_t> {
  static constexpr sbp_msg_type_t id = SbpMsgPpsTime;
  static constexpr const char *name = "MSG_PPS_TIME";
  static const sbp_msg_pps_time_t &get(const sbp_msg_t &msg) {
    return msg.pps_time;
  }
  static sbp_msg_pps_time_t &get(sbp_msg_t &msg) { return msg.pps_time; }
  static void to_sbp_msg(const sbp_msg_pps_time_t &msg, sbp_msg_t *sbp_msg) {
    sbp_msg->pps_time = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_pps_time_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.pps_time = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_pps_time_t &msg, sbp_write_fn_t write) {
    return sbp_msg_pps_time_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_pps_time_t &msg) {
    return sbp_msg_pps_time_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_pps_time_t *msg) {
    return sbp_msg_pps_time_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_pps_time_t &msg) {
    return sbp_msg_pps_time_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_print_dep_t> {
  static constexpr sbp_msg_type_t id = SbpMsgPrintDep;
  static constexpr const char *name = "MSG_PRINT_DEP";
  static const sbp_msg_print_dep_t &get(const sbp_msg_t &msg) {
    return msg.print_dep;
  }
  static sbp_msg_print_dep_t &get(sbp_msg_t &msg) { return msg.print_dep; }
  static void to_sbp_msg(const sbp_msg_print_dep_t &msg, sbp_msg_t *sbp_msg) {
    sbp_msg->print_dep = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_print_dep_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.print_dep = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_print_dep_t &msg, sbp_write_fn_t write) {
    return sbp_msg_print_dep_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_print_dep_t &msg) {
    return sbp_msg_print_dep_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_print_dep_t *msg) {
    return sbp_msg_print_dep_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_print_dep_t &msg) {
    return sbp_msg_print_dep_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_profiling_resource_counter_t> {
  static constexpr sbp_msg_type_t id = SbpMsgProfilingResourceCounter;
  static constexpr const char *name = "MSG_PROFILING_RESOURCE_COUNTER";
  static const sbp_msg_profiling_resource_counter_t &get(const sbp_msg_t &msg) {
    return msg.profiling_resource_counter;
  }
  static sbp_msg_profiling_resource_counter_t &get(sbp_msg_t &msg) {
    return msg.profiling_resource_counter;
  }
  static void to_sbp_msg(const sbp_msg_profiling_resource_counter_t &msg,
                         sbp_msg_t *sbp_msg) {
    sbp_msg->profiling_resource_counter = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_profiling_resource_counter_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.profiling_resource_counter = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_profiling_resource_counter_t &msg,
                 sbp_write_fn_t write) {
    return sbp_msg_profiling_resource_counter_send(state, sender_id, &msg,
                                                   write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_profiling_resource_counter_t &msg) {
    return sbp_msg_profiling_resource_counter_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_profiling_resource_counter_t *msg) {
    return sbp_msg_profiling_resource_counter_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_profiling_resource_counter_t &msg) {
    return sbp_msg_profiling_resource_counter_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_profiling_system_info_t> {
  static constexpr sbp_msg_type_t id = SbpMsgProfilingSystemInfo;
  static constexpr const char *name = "MSG_PROFILING_SYSTEM_INFO";
  static const sbp_msg_profiling_system_info_t &get(const sbp_msg_t &msg) {
    return msg.profiling_system_info;
  }
  static sbp_msg_profiling_system_info_t &get(sbp_msg_t &msg) {
    return msg.profiling_system_info;
  }
  static void to_sbp_msg(const sbp_msg_profiling_system_info_t &msg,
                         sbp_msg_t *sbp_msg) {
    sbp_msg->profiling_system_info = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_profiling_system_info_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.profiling_system_info = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_profiling_system_info_t &msg,
                 sbp_write_fn_t write) {
    return sbp_msg_profiling_system_info_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_profiling_system_info_t &msg) {
    return sbp_msg_profiling_system_info_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_profiling_system_info_t *msg) {
    return sbp_msg_profiling_system_info_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_profiling_system_info_t &msg) {
    return sbp_msg_profiling_system_info_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_profiling_thread_info_t> {
  static constexpr sbp_msg_type_t id = SbpMsgProfilingThreadInfo;
  static constexpr const char *name = "MSG_PROFILING_THREAD_INFO";
  static const sbp_msg_profiling_thread_info_t &get(const sbp_msg_t &msg) {
    return msg.profiling_thread_info;
  }
  static sbp_msg_profiling_thread_info_t &get(sbp_msg_t &msg) {
    return msg.profiling_thread_info;
  }
  static void to_sbp_msg(const sbp_msg_profiling_thread_info_t &msg,
                         sbp_msg_t *sbp_msg) {
    sbp_msg->profiling_thread_info = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_profiling_thread_info_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.profiling_thread_info = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_profiling_thread_info_t &msg,
                 sbp_write_fn_t write) {
    return sbp_msg_profiling_thread_info_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_profiling_thread_info_t &msg) {
    return sbp_msg_profiling_thread_info_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_profiling_thread_info_t *msg) {
    return sbp_msg_profiling_thread_info_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_profiling_thread_info_t &msg) {
    return sbp_msg_profiling_thread_info_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_protection_level_dep_a_t> {
  static constexpr sbp_msg_type_t id = SbpMsgProtectionLevelDepA;
  static constexpr const char *name = "MSG_PROTECTION_LEVEL_DEP_A";
  static const sbp_msg_protection_level_dep_a_t &get(const sbp_msg_t &msg) {
    return msg.protection_level_dep_a;
  }
  static sbp_msg_protection_level_dep_a_t &get(sbp_msg_t &msg) {
    return msg.protection_level_dep_a;
  }
  static void to_sbp_msg(const sbp_msg_protection_level_dep_a_t &msg,
                         sbp_msg_t *sbp_msg) {
    sbp_msg->protection_level_dep_a = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_protection_level_dep_a_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.protection_level_dep_a = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_protection_level_dep_a_t &msg,
                 sbp_write_fn_t write) {
    return sbp_msg_protection_level_dep_a_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_protection_level_dep_a_t &msg) {
    return sbp_msg_protection_level_dep_a_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_protection_level_dep_a_t *msg) {
    return sbp_msg_protection_level_dep_a_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_protection_level_dep_a_t &msg) {
    return sbp_msg_protection_level_dep_a_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_protection_level_t> {
  static constexpr sbp_msg_type_t id = SbpMsgProtectionLevel;
  static constexpr const char *name = "MSG_PROTECTION_LEVEL";
  static const sbp_msg_protection_level_t &get(const sbp_msg_t &msg) {
    return msg.protection_level;
  }
  static sbp_msg_protection_level_t &get(sbp_msg_t &msg) {
    return msg.protection_level;
  }
  static void to_sbp_msg(const sbp_msg_protection_level_t &msg,
                         sbp_msg_t *sbp_msg) {
    sbp_msg->protection_level = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_protection_level_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.protection_level = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_protection_level_t &msg, sbp_write_fn_t write) {
    return sbp_msg_protection_level_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_protection_level_t &msg) {
    return sbp_msg_protection_level_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_protection_level_t *msg) {
    return sbp_msg_protection_level_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_protection_level_t &msg) {
    return sbp_msg_protection_level_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_reference_frame_param_t> {
  static constexpr sbp_msg_type_t id = SbpMsgReferenceFrameParam;
  static constexpr const char *name = "MSG_REFERENCE_FRAME_PARAM";
  static const sbp_msg_reference_frame_param_t &get(const sbp_msg_t &msg) {
    return msg.reference_frame_param;
  }
  static sbp_msg_reference_frame_param_t &get(sbp_msg_t &msg) {
    return msg.reference_frame_param;
  }
  static void to_sbp_msg(const sbp_msg_reference_frame_param_t &msg,
                         sbp_msg_t *sbp_msg) {
    sbp_msg->reference_frame_param = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_reference_frame_param_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.reference_frame_param = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_reference_frame_param_t &msg,
                 sbp_write_fn_t write) {
    return sbp_msg_reference_frame_param_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_reference_frame_param_t &msg) {
    return sbp_msg_reference_frame_param_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_reference_frame_param_t *msg) {
    return sbp_msg_reference_frame_param_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_reference_frame_param_t &msg) {
    return sbp_msg_reference_frame_param_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_reset_dep_t> {
  static constexpr sbp_msg_type_t id = SbpMsgResetDep;
  static constexpr const char *name = "MSG_RESET_DEP";
  static const sbp_msg_reset_dep_t &get(const sbp_msg_t &msg) {
    return msg.reset_dep;
  }
  static sbp_msg_reset_dep_t &get(sbp_msg_t &msg) { return msg.reset_dep; }
  static void to_sbp_msg(const sbp_msg_reset_dep_t &msg, sbp_msg_t *sbp_msg) {
    sbp_msg->reset_dep = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_reset_dep_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.reset_dep = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_reset_dep_t &msg, sbp_write_fn_t write) {
    return sbp_msg_reset_dep_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_reset_dep_t &msg) {
    return sbp_msg_reset_dep_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_reset_dep_t *msg) {
    return sbp_msg_reset_dep_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_reset_dep_t &msg) {
    return sbp_msg_reset_dep_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_reset_filters_t> {
  static constexpr sbp_msg_type_t id = SbpMsgResetFilters;
  static constexpr const char *name = "MSG_RESET_FILTERS";
  static const sbp_msg_reset_filters_t &get(const sbp_msg_t &msg) {
    return msg.reset_filters;
  }
  static sbp_msg_reset_filters_t &get(sbp_msg_t &msg) {
    return msg.reset_filters;
  }
  static void to_sbp_msg(const sbp_msg_reset_filters_t &msg,
                         sbp_msg_t *sbp_msg) {
    sbp_msg->reset_filters = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_reset_filters_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.reset_filters = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_reset_filters_t &msg, sbp_write_fn_t write) {
    return sbp_msg_reset_filters_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_reset_filters_t &msg) {
    return sbp_msg_reset_filters_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_reset_filters_t *msg) {
    return sbp_msg_reset_filters_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_reset_filters_t &msg) {
    return sbp_msg_reset_filters_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_reset_t> {
  static constexpr sbp_msg_type_t id = SbpMsgReset;
  static constexpr const char *name = "MSG_RESET";
  static const sbp_msg_reset_t &get(const sbp_msg_t &msg) { return msg.reset; }
  static sbp_msg_reset_t &get(sbp_msg_t &msg) { return msg.reset; }
  static void to_sbp_msg(const sbp_msg_reset_t &msg, sbp_msg_t *sbp_msg) {
    sbp_msg->reset = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_reset_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.reset = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_reset_t &msg,
                 sbp_write_fn_t write) {
    return sbp_msg_reset_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_reset_t &msg) {
    return sbp_msg_reset_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_reset_t *msg) {
    return sbp_msg_reset_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_reset_t &msg) {
    return sbp_msg_reset_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_sbas_raw_t> {
  static constexpr sbp_msg_type_t id = SbpMsgSbasRaw;
  static constexpr const char *name = "MSG_SBAS_RAW";
  static const sbp_msg_sbas_raw_t &get(const sbp_msg_t &msg) {
    return msg.sbas_raw;
  }
  static sbp_msg_sbas_raw_t &get(sbp_msg_t &msg) { return msg.sbas_raw; }
  static void to_sbp_msg(const sbp_msg_sbas_raw_t &msg, sbp_msg_t *sbp_msg) {
    sbp_msg->sbas_raw = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_sbas_raw_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.sbas_raw = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_sbas_raw_t &msg, sbp_write_fn_t write) {
    return sbp_msg_sbas_raw_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_sbas_raw_t &msg) {
    return sbp_msg_sbas_raw_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_sbas_raw_t *msg) {
    return sbp_msg_sbas_raw_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_sbas_raw_t &msg) {
    return sbp_msg_sbas_raw_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_sensor_aid_event_t> {
  static constexpr sbp_msg_type_t id = SbpMsgSensorAidEvent;
  static constexpr const char *name = "MSG_SENSOR_AID_EVENT";
  static const sbp_msg_sensor_aid_event_t &get(const sbp_msg_t &msg) {
    return msg.sensor_aid_event;
  }
  static sbp_msg_sensor_aid_event_t &get(sbp_msg_t &msg) {
    return msg.sensor_aid_event;
  }
  static void to_sbp_msg(const sbp_msg_sensor_aid_event_t &msg,
                         sbp_msg_t *sbp_msg) {
    sbp_msg->sensor_aid_event = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_sensor_aid_event_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.sensor_aid_event = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_sensor_aid_event_t &msg, sbp_write_fn_t write) {
    return sbp_msg_sensor_aid_event_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_sensor_aid_event_t &msg) {
    return sbp_msg_sensor_aid_event_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_sensor_aid_event_t *msg) {
    return sbp_msg_sensor_aid_event_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_sensor_aid_event_t &msg) {
    return sbp_msg_sensor_aid_event_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_set_time_t> {
  static constexpr sbp_msg_type_t id = SbpMsgSetTime;
  static constexpr const char *name = "MSG_SET_TIME";
  static const sbp_msg_set_time_t &get(const sbp_msg_t &msg) {
    return msg.set_time;
  }
  static sbp_msg_set_time_t &get(sbp_msg_t &msg) { return msg.set_time; }
  static void to_sbp_msg(const sbp_msg_set_time_t &msg, sbp_msg_t *sbp_msg) {
    sbp_msg->set_time = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_set_time_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.set_time = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_set_time_t &msg, sbp_write_fn_t write) {
    return sbp_msg_set_time_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_set_time_t &msg) {
    return sbp_msg_set_time_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_set_time_t *msg) {
    return sbp_msg_set_time_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_set_time_t &msg) {
    return sbp_msg_set_time_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_settings_read_by_index_done_t> {
  static constexpr sbp_msg_type_t id = SbpMsgSettingsReadByIndexDone;
  static constexpr const char *name = "MSG_SETTINGS_READ_BY_INDEX_DONE";
  static const sbp_msg_settings_read_by_index_done_t &get(
      const sbp_msg_t &msg) {
    return msg.settings_read_by_index_done;
  }
  static sbp_msg_settings_read_by_index_done_t &get(sbp_msg_t &msg) {
    return msg.settings_read_by_index_done;
  }
  static void to_sbp_msg(const sbp_msg_settings_read_by_index_done_t &msg,
                         sbp_msg_t *sbp_msg) {
    sbp_msg->settings_read_by_index_done = msg;
  }
  static sbp_msg_t to_sbp_msg(
      const sbp_msg_settings_read_by_index_done_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.settings_read_by_index_done = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_settings_read_by_index_done_t &msg,
                 sbp_write_fn_t write) {
    return sbp_msg_settings_read_by_index_done_send(state, sender_id, &msg,
                                                    write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_settings_read_by_index_done_t &msg) {
    return sbp_msg_settings_read_by_index_done_encode(buf, len, n_written,
                                                      &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_settings_read_by_index_done_t *msg) {
    return sbp_msg_settings_read_by_index_done_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_settings_read_by_index_done_t &msg) {
    return sbp_msg_settings_read_by_index_done_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_settings_read_by_index_req_t> {
  static constexpr sbp_msg_type_t id = SbpMsgSettingsReadByIndexReq;
  static constexpr const char *name = "MSG_SETTINGS_READ_BY_INDEX_REQ";
  static const sbp_msg_settings_read_by_index_req_t &get(const sbp_msg_t &msg) {
    return msg.settings_read_by_index_req;
  }
  static sbp_msg_settings_read_by_index_req_t &get(sbp_msg_t &msg) {
    return msg.settings_read_by_index_req;
  }
  static void to_sbp_msg(const sbp_msg_settings_read_by_index_req_t &msg,
                         sbp_msg_t *sbp_msg) {
    sbp_msg->settings_read_by_index_req = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_settings_read_by_index_req_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.settings_read_by_index_req = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_settings_read_by_index_req_t &msg,
                 sbp_write_fn_t write) {
    return sbp_msg_settings_read_by_index_req_send(state, sender_id, &msg,
                                                   write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_settings_read_by_index_req_t &msg) {
    return sbp_msg_settings_read_by_index_req_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_settings_read_by_index_req_t *msg) {
    return sbp_msg_settings_read_by_index_req_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_settings_read_by_index_req_t &msg) {
    return sbp_msg_settings_read_by_index_req_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_settings_read_by_index_resp_t> {
  static constexpr sbp_msg_type_t id = SbpMsgSettingsReadByIndexResp;
  static constexpr const char *name = "MSG_SETTINGS_READ_BY_INDEX_RESP";
  static const sbp_msg_settings_read_by_index_resp_t &get(
      const sbp_msg_t &msg) {
    return msg.settings_read_by_index_resp;
  }
  static sbp_msg_settings_read_by_index_resp_t &get(sbp_msg_t &msg) {
    return msg.settings_read_by_index_resp;
  }
  static void to_sbp_msg(const sbp_msg_settings_read_by_index_resp_t &msg,
                         sbp_msg_t *sbp_msg) {
    sbp_msg->settings_read_by_index_resp = msg;
  }
  static sbp_msg_t to_sbp_msg(
      const sbp_msg_settings_read_by_index_resp_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.settings_read_by_index_resp = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_settings_read_by_index_resp_t &msg,
                 sbp_write_fn_t write) {
    return sbp_msg_settings_read_by_index_resp_send(state, sender_id, &msg,
                                                    write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_settings_read_by_index_resp_t &msg) {
    return sbp_msg_settings_read_by_index_resp_encode(buf, len, n_written,
                                                      &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_settings_read_by_index_resp_t *msg) {
    return sbp_msg_settings_read_by_index_resp_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_settings_read_by_index_resp_t &msg) {
    return sbp_msg_settings_read_by_index_resp_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_settings_read_req_t> {
  static constexpr sbp_msg_type_t id = SbpMsgSettingsReadReq;
  static constexpr const char *name = "MSG_SETTINGS_READ_REQ";
  static const sbp_msg_settings_read_req_t &get(const sbp_msg_t &msg) {
    return msg.settings_read_req;
  }
  static sbp_msg_settings_read_req_t &get(sbp_msg_t &msg) {
    return msg.settings_read_req;
  }
  static void to_sbp_msg(const sbp_msg_settings_read_req_t &msg,
                         sbp_msg_t *sbp_msg) {
    sbp_msg->settings_read_req = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_settings_read_req_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.settings_read_req = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_settings_read_req_t &msg, sbp_write_fn_t write) {
    return sbp_msg_settings_read_req_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_settings_read_req_t &msg) {
    return sbp_msg_settings_read_req_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_settings_read_req_t *msg) {
    return sbp_msg_settings_read_req_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_settings_read_req_t &msg) {
    return sbp_msg_settings_read_req_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_settings_read_resp_t> {
  static constexpr sbp_msg_type_t id = SbpMsgSettingsReadResp;
  static constexpr const char *name = "MSG_SETTINGS_READ_RESP";
  static const sbp_msg_settings_read_resp_t &get(const sbp_msg_t &msg) {
    return msg.settings_read_resp;
  }
  static sbp_msg_settings_read_resp_t &get(sbp_msg_t &msg) {
    return msg.settings_read_resp;
  }
  static void to_sbp_msg(const sbp_msg_settings_read_resp_t &msg,
                         sbp_msg_t *sbp_msg) {
    sbp_msg->settings_read_resp = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_settings_read_resp_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.settings_read_resp = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_settings_read_resp_t &msg,
                 sbp_write_fn_t write) {
    return sbp_msg_settings_read_resp_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_settings_read_resp_t &msg) {
    return sbp_msg_settings_read_resp_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_settings_read_resp_t *msg) {
    return sbp_msg_settings_read_resp_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_settings_read_resp_t &msg) {
    return sbp_msg_settings_read_resp_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_settings_register_resp_t> {
  static constexpr sbp_msg_type_t id = SbpMsgSettingsRegisterResp;
  static constexpr const char *name = "MSG_SETTINGS_REGISTER_RESP";
  static const sbp_msg_settings_register_resp_t &get(const sbp_msg_t &msg) {
    return msg.settings_register_resp;
  }
  static sbp_msg_settings_register_resp_t &get(sbp_msg_t &msg) {
    return msg.settings_register_resp;
  }
  static void to_sbp_msg(const sbp_msg_settings_register_resp_t &msg,
                         sbp_msg_t *sbp_msg) {
    sbp_msg->settings_register_resp = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_settings_register_resp_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.settings_register_resp = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_settings_register_resp_t &msg,
                 sbp_write_fn_t write) {
    return sbp_msg_settings_register_resp_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_settings_register_resp_t &msg) {
    return sbp_msg_settings_register_resp_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_settings_register_resp_t *msg) {
    return sbp_msg_settings_register_resp_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_settings_register_resp_t &msg) {
    return sbp_msg_settings_register_resp_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_settings_register_t> {
  static constexpr sbp_msg_type_t id = SbpMsgSettingsRegister;
  static constexpr const char *name = "MSG_SETTINGS_REGISTER";
  static const sbp_msg_settings_register_t &get(const sbp_msg_t &msg) {
    return msg.settings_register;
  }
  static sbp_msg_settings_register_t &get(sbp_msg_t &msg) {
    return msg.settings_register;
  }
  static void to_sbp_msg(const sbp_msg_settings_register_t &msg,
                         sbp_msg_t *sbp_msg) {
    sbp_msg->settings_register = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_settings_register_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.settings_register = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_settings_register_t &msg, sbp_write_fn_t write) {
    return sbp_msg_settings_register_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_settings_register_t &msg) {
    return sbp_msg_settings_register_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_settings_register_t *msg) {
    return sbp_msg_settings_register_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_settings_register_t &msg) {
    return sbp_msg_settings_register_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_settings_save_t> {
  static constexpr sbp_msg_type_t id = SbpMsgSettingsSave;
  static constexpr const char *name = "MSG_SETTINGS_SAVE";
  static const sbp_msg_settings_save_t &get(const sbp_msg_t &msg) {
    return msg.settings_save;
  }
  static sbp_msg_settings_save_t &get(sbp_msg_t &msg) {
    return msg.settings_save;
  }
  static void to_sbp_msg(const sbp_msg_settings_save_t &msg,
                         sbp_msg_t *sbp_msg) {
    sbp_msg->settings_save = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_settings_save_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.settings_save = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_settings_save_t &msg, sbp_write_fn_t write) {
    return sbp_msg_settings_save_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_settings_save_t &msg) {
    return sbp_msg_settings_save_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_settings_save_t *msg) {
    return sbp_msg_settings_save_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_settings_save_t &msg) {
    return sbp_msg_settings_save_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_settings_write_resp_t> {
  static constexpr sbp_msg_type_t id = SbpMsgSettingsWriteResp;
  static constexpr const char *name = "MSG_SETTINGS_WRITE_RESP";
  static const sbp_msg_settings_write_resp_t &get(const sbp_msg_t &msg) {
    return msg.settings_write_resp;
  }
  static sbp_msg_settings_write_resp_t &get(sbp_msg_t &msg) {
    return msg.settings_write_resp;
  }
  static void to_sbp_msg(const sbp_msg_settings_write_resp_t &msg,
                         sbp_msg_t *sbp_msg) {
    sbp_msg->settings_write_resp = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_settings_write_resp_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.settings_write_resp = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_settings_write_resp_t &msg,
                 sbp_write_fn_t write) {
    return sbp_msg_settings_write_resp_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_settings_write_resp_t &msg) {
    return sbp_msg_settings_write_resp_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_settings_write_resp_t *msg) {
    return sbp_msg_settings_write_resp_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_settings_write_resp_t &msg) {
    return sbp_msg_settings_write_resp_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_settings_write_t> {
  static constexpr sbp_msg_type_t id = SbpMsgSettingsWrite;
  static constexpr const char *name = "MSG_SETTINGS_WRITE";
  static const sbp_msg_settings_write_t &get(const sbp_msg_t &msg) {
    return msg.settings_write;
  }
  static sbp_msg_settings_write_t &get(sbp_msg_t &msg) {
    return msg.settings_write;
  }
  static void to_sbp_msg(const sbp_msg_settings_write_t &msg,
                         sbp_msg_t *sbp_msg) {
    sbp_msg->settings_write = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_settings_write_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.settings_write = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_settings_write_t &msg, sbp_write_fn_t write) {
    return sbp_msg_settings_write_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_settings_write_t &msg) {
    return sbp_msg_settings_write_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_settings_write_t *msg) {
    return sbp_msg_settings_write_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_settings_write_t &msg) {
    return sbp_msg_settings_write_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_soln_meta_dep_a_t> {
  static constexpr sbp_msg_type_t id = SbpMsgSolnMetaDepA;
  static constexpr const char *name = "MSG_SOLN_META_DEP_A";
  static const sbp_msg_soln_meta_dep_a_t &get(const sbp_msg_t &msg) {
    return msg.soln_meta_dep_a;
  }
  static sbp_msg_soln_meta_dep_a_t &get(sbp_msg_t &msg) {
    return msg.soln_meta_dep_a;
  }
  static void to_sbp_msg(const sbp_msg_soln_meta_dep_a_t &msg,
                         sbp_msg_t *sbp_msg) {
    sbp_msg->soln_meta_dep_a = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_soln_meta_dep_a_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.soln_meta_dep_a = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_soln_meta_dep_a_t &msg, sbp_write_fn_t write) {
    return sbp_msg_soln_meta_dep_a_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_soln_meta_dep_a_t &msg) {
    return sbp_msg_soln_meta_dep_a_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_soln_meta_dep_a_t *msg) {
    return sbp_msg_soln_meta_dep_a_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_soln_meta_dep_a_t &msg) {
    return sbp_msg_soln_meta_dep_a_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_soln_meta_t> {
  static constexpr sbp_msg_type_t id = SbpMsgSolnMeta;
  static constexpr const char *name = "MSG_SOLN_META";
  static const sbp_msg_soln_meta_t &get(const sbp_msg_t &msg) {
    return msg.soln_meta;
  }
  static sbp_msg_soln_meta_t &get(sbp_msg_t &msg) { return msg.soln_meta; }
  static void to_sbp_msg(const sbp_msg_soln_meta_t &msg, sbp_msg_t *sbp_msg) {
    sbp_msg->soln_meta = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_soln_meta_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.soln_meta = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_soln_meta_t &msg, sbp_write_fn_t write) {
    return sbp_msg_soln_meta_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_soln_meta_t &msg) {
    return sbp_msg_soln_meta_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_soln_meta_t *msg) {
    return sbp_msg_soln_meta_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_soln_meta_t &msg) {
    return sbp_msg_soln_meta_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_specan_dep_t> {
  static constexpr sbp_msg_type_t id = SbpMsgSpecanDep;
  static constexpr const char *name = "MSG_SPECAN_DEP";
  static const sbp_msg_specan_dep_t &get(const sbp_msg_t &msg) {
    return msg.specan_dep;
  }
  static sbp_msg_specan_dep_t &get(sbp_msg_t &msg) { return msg.specan_dep; }
  static void to_sbp_msg(const sbp_msg_specan_dep_t &msg, sbp_msg_t *sbp_msg) {
    sbp_msg->specan_dep = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_specan_dep_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.specan_dep = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_specan_dep_t &msg, sbp_write_fn_t write) {
    return sbp_msg_specan_dep_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_specan_dep_t &msg) {
    return sbp_msg_specan_dep_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_specan_dep_t *msg) {
    return sbp_msg_specan_dep_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_specan_dep_t &msg) {
    return sbp_msg_specan_dep_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_specan_t> {
  static constexpr sbp_msg_type_t id = SbpMsgSpecan;
  static constexpr const char *name = "MSG_SPECAN";
  static const sbp_msg_specan_t &get(const sbp_msg_t &msg) {
    return msg.specan;
  }
  static sbp_msg_specan_t &get(sbp_msg_t &msg) { return msg.specan; }
  static void to_sbp_msg(const sbp_msg_specan_t &msg, sbp_msg_t *sbp_msg) {
    sbp_msg->specan = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_specan_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.specan = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_specan_t &msg,
                 sbp_write_fn_t write) {
    return sbp_msg_specan_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_specan_t &msg) {
    return sbp_msg_specan_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_specan_t *msg) {
    return sbp_msg_specan_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_specan_t &msg) {
    return sbp_msg_specan_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_ssr_code_biases_t> {
  static constexpr sbp_msg_type_t id = SbpMsgSsrCodeBiases;
  static constexpr const char *name = "MSG_SSR_CODE_BIASES";
  static const sbp_msg_ssr_code_biases_t &get(const sbp_msg_t &msg) {
    return msg.ssr_code_biases;
  }
  static sbp_msg_ssr_code_biases_t &get(sbp_msg_t &msg) {
    return msg.ssr_code_biases;
  }
  static void to_sbp_msg(const sbp_msg_ssr_code_biases_t &msg,
                         sbp_msg_t *sbp_msg) {
    sbp_msg->ssr_code_biases = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_ssr_code_biases_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.ssr_code_biases = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_ssr_code_biases_t &msg, sbp_write_fn_t write) {
    return sbp_msg_ssr_code_biases_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_ssr_code_biases_t &msg) {
    return sbp_msg_ssr_code_biases_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_ssr_code_biases_t *msg) {
    return sbp_msg_ssr_code_biases_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_ssr_code_biases_t &msg) {
    return sbp_msg_ssr_code_biases_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_ssr_code_phase_biases_bounds_t> {
  static constexpr sbp_msg_type_t id = SbpMsgSsrCodePhaseBiasesBounds;
  static constexpr const char *name = "MSG_SSR_CODE_PHASE_BIASES_BOUNDS";
  static const sbp_msg_ssr_code_phase_biases_bounds_t &get(
      const sbp_msg_t &msg) {
    return msg.ssr_code_phase_biases_bounds;
  }
  static sbp_msg_ssr_code_phase_biases_bounds_t &get(sbp_msg_t &msg) {
    return msg.ssr_code_phase_biases_bounds;
  }
  static void to_sbp_msg(const sbp_msg_ssr_code_phase_biases_bounds_t &msg,
                         sbp_msg_t *sbp_msg) {
    sbp_msg->ssr_code_phase_biases_bounds = msg;
  }
  static sbp_msg_t to_sbp_msg(
      const sbp_msg_ssr_code_phase_biases_bounds_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.ssr_code_phase_biases_bounds = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_ssr_code_phase_biases_bounds_t &msg,
                 sbp_write_fn_t write) {
    return sbp_msg_ssr_code_phase_biases_bounds_send(state, sender_id, &msg,
                                                     write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_ssr_code_phase_biases_bounds_t &msg) {
    return sbp_msg_ssr_code_phase_biases_bounds_encode(buf, len, n_written,
                                                       &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_ssr_code_phase_biases_bounds_t *msg) {
    return sbp_msg_ssr_code_phase_biases_bounds_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_ssr_code_phase_biases_bounds_t &msg) {
    return sbp_msg_ssr_code_phase_biases_bounds_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_ssr_flag_high_level_t> {
  static constexpr sbp_msg_type_t id = SbpMsgSsrFlagHighLevel;
  static constexpr const char *name = "MSG_SSR_FLAG_HIGH_LEVEL";
  static const sbp_msg_ssr_flag_high_level_t &get(const sbp_msg_t &msg) {
    return msg.ssr_flag_high_level;
  }
  static sbp_msg_ssr_flag_high_level_t &get(sbp_msg_t &msg) {
    return msg.ssr_flag_high_level;
  }
  static void to_sbp_msg(const sbp_msg_ssr_flag_high_level_t &msg,
                         sbp_msg_t *sbp_msg) {
    sbp_msg->ssr_flag_high_level = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_ssr_flag_high_level_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.ssr_flag_high_level = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_ssr_flag_high_level_t &msg,
                 sbp_write_fn_t write) {
    return sbp_msg_ssr_flag_high_level_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_ssr_flag_high_level_t &msg) {
    return sbp_msg_ssr_flag_high_level_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_ssr_flag_high_level_t *msg) {
    return sbp_msg_ssr_flag_high_level_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_ssr_flag_high_level_t &msg) {
    return sbp_msg_ssr_flag_high_level_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_ssr_flag_iono_grid_point_sat_los_t> {
  static constexpr sbp_msg_type_t id = SbpMsgSsrFlagIonoGridPointSatLos;
  static constexpr const char *name = "MSG_SSR_FLAG_IONO_GRID_POINT_SAT_LOS";
  static const sbp_msg_ssr_flag_iono_grid_point_sat_los_t &get(
      const sbp_msg_t &msg) {
    return msg.ssr_flag_iono_grid_point_sat_los;
  }
  static sbp_msg_ssr_flag_iono_grid_point_sat_los_t &get(sbp_msg_t &msg) {
    return msg.ssr_flag_iono_grid_point_sat_los;
  }
  static void to_sbp_msg(const sbp_msg_ssr_flag_iono_grid_point_sat_los_t &msg,
                         sbp_msg_t *sbp_msg) {
    sbp_msg->ssr_flag_iono_grid_point_sat_los = msg;
  }
  static sbp_msg_t to_sbp_msg(
      const sbp_msg_ssr_flag_iono_grid_point_sat_los_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.ssr_flag_iono_grid_point_sat_los = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_ssr_flag_iono_grid_point_sat_los_t &msg,
                 sbp_write_fn_t write) {
    return sbp_msg_ssr_flag_iono_grid_point_sat_los_send(state, sender_id, &msg,
                                                         write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_ssr_flag_iono_grid_point_sat_los_t &msg) {
    return sbp_msg_ssr_flag_iono_grid_point_sat_los_encode(buf, len, n_written,
                                                           &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_ssr_flag_iono_grid_point_sat_los_t *msg) {
    return sbp_msg_ssr_flag_iono_grid_point_sat_los_decode(buf, len, n_read,
                                                           msg);
  }
  static size_t encoded_len(
      const sbp_msg_ssr_flag_iono_grid_point_sat_los_t &msg) {
    return sbp_msg_ssr_flag_iono_grid_point_sat_los_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_ssr_flag_iono_grid_points_t> {
  static constexpr sbp_msg_type_t id = SbpMsgSsrFlagIonoGridPoints;
  static constexpr const char *name = "MSG_SSR_FLAG_IONO_GRID_POINTS";
  static const sbp_msg_ssr_flag_iono_grid_points_t &get(const sbp_msg_t &msg) {
    return msg.ssr_flag_iono_grid_points;
  }
  static sbp_msg_ssr_flag_iono_grid_points_t &get(sbp_msg_t &msg) {
    return msg.ssr_flag_iono_grid_points;
  }
  static void to_sbp_msg(const sbp_msg_ssr_flag_iono_grid_points_t &msg,
                         sbp_msg_t *sbp_msg) {
    sbp_msg->ssr_flag_iono_grid_points = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_ssr_flag_iono_grid_points_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.ssr_flag_iono_grid_points = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_ssr_flag_iono_grid_points_t &msg,
                 sbp_write_fn_t write) {
    return sbp_msg_ssr_flag_iono_grid_points_send(state, sender_id, &msg,
                                                  write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_ssr_flag_iono_grid_points_t &msg) {
    return sbp_msg_ssr_flag_iono_grid_points_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_ssr_flag_iono_grid_points_t *msg) {
    return sbp_msg_ssr_flag_iono_grid_points_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_ssr_flag_iono_grid_points_t &msg) {
    return sbp_msg_ssr_flag_iono_grid_points_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_ssr_flag_iono_tile_sat_los_t> {
  static constexpr sbp_msg_type_t id = SbpMsgSsrFlagIonoTileSatLos;
  static constexpr const char *name = "MSG_SSR_FLAG_IONO_TILE_SAT_LOS";
  static const sbp_msg_ssr_flag_iono_tile_sat_los_t &get(const sbp_msg_t &msg) {
    return msg.ssr_flag_iono_tile_sat_los;
  }
  static sbp_msg_ssr_flag_iono_tile_sat_los_t &get(sbp_msg_t &msg) {
    return msg.ssr_flag_iono_tile_sat_los;
  }
  static void to_sbp_msg(const sbp_msg_ssr_flag_iono_tile_sat_los_t &msg,
                         sbp_msg_t *sbp_msg) {
    sbp_msg->ssr_flag_iono_tile_sat_los = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_ssr_flag_iono_tile_sat_los_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.ssr_flag_iono_tile_sat_los = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_ssr_flag_iono_tile_sat_los_t &msg,
                 sbp_write_fn_t write) {
    return sbp_msg_ssr_flag_iono_tile_sat_los_send(state, sender_id, &msg,
                                                   write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_ssr_flag_iono_tile_sat_los_t &msg) {
    return sbp_msg_ssr_flag_iono_tile_sat_los_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_ssr_flag_iono_tile_sat_los_t *msg) {
    return sbp_msg_ssr_flag_iono_tile_sat_los_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_ssr_flag_iono_tile_sat_los_t &msg) {
    return sbp_msg_ssr_flag_iono_tile_sat_los_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_ssr_flag_satellites_t> {
  static constexpr sbp_msg_type_t id = SbpMsgSsrFlagSatellites;
  static constexpr const char *name = "MSG_SSR_FLAG_SATELLITES";
  static const sbp_msg_ssr_flag_satellites_t &get(const sbp_msg_t &msg) {
    return msg.ssr_flag_satellites;
  }
  static sbp_msg_ssr_flag_satellites_t &get(sbp_msg_t &msg) {
    return msg.ssr_flag_satellites;
  }
  static void to_sbp_msg(const sbp_msg_ssr_flag_satellites_t &msg,
                         sbp_msg_t *sbp_msg) {
    sbp_msg->ssr_flag_satellites = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_ssr_flag_satellites_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.ssr_flag_satellites = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_ssr_flag_satellites_t &msg,
                 sbp_write_fn_t write) {
    return sbp_msg_ssr_flag_satellites_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_ssr_flag_satellites_t &msg) {
    return sbp_msg_ssr_flag_satellites_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_ssr_flag_satellites_t *msg) {
    return sbp_msg_ssr_flag_satellites_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_ssr_flag_satellites_t &msg) {
    return sbp_msg_ssr_flag_satellites_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_ssr_flag_tropo_grid_points_t> {
  static constexpr sbp_msg_type_t id = SbpMsgSsrFlagTropoGridPoints;
  static constexpr const char *name = "MSG_SSR_FLAG_TROPO_GRID_POINTS";
  static const sbp_msg_ssr_flag_tropo_grid_points_t &get(const sbp_msg_t &msg) {
    return msg.ssr_flag_tropo_grid_points;
  }
  static sbp_msg_ssr_flag_tropo_grid_points_t &get(sbp_msg_t &msg) {
    return msg.ssr_flag_tropo_grid_points;
  }
  static void to_sbp_msg(const sbp_msg_ssr_flag_tropo_grid_points_t &msg,
                         sbp_msg_t *sbp_msg) {
    sbp_msg->ssr_flag_tropo_grid_points = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_ssr_flag_tropo_grid_points_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.ssr_flag_tropo_grid_points = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_ssr_flag_tropo_grid_points_t &msg,
                 sbp_write_fn_t write) {
    return sbp_msg_ssr_flag_tropo_grid_points_send(state, sender_id, &msg,
                                                   write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_ssr_flag_tropo_grid_points_t &msg) {
    return sbp_msg_ssr_flag_tropo_grid_points_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_ssr_flag_tropo_grid_points_t *msg) {
    return sbp_msg_ssr_flag_tropo_grid_points_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_ssr_flag_tropo_grid_points_t &msg) {
    return sbp_msg_ssr_flag_tropo_grid_points_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_ssr_grid_definition_dep_a_t> {
  static constexpr sbp_msg_type_t id = SbpMsgSsrGridDefinitionDepA;
  static constexpr const char *name = "MSG_SSR_GRID_DEFINITION_DEP_A";
  static const sbp_msg_ssr_grid_definition_dep_a_t &get(const sbp_msg_t &msg) {
    return msg.ssr_grid_definition_dep_a;
  }
  static sbp_msg_ssr_grid_definition_dep_a_t &get(sbp_msg_t &msg) {
    return msg.ssr_grid_definition_dep_a;
  }
  static void to_sbp_msg(const sbp_msg_ssr_grid_definition_dep_a_t &msg,
                         sbp_msg_t *sbp_msg) {
    sbp_msg->ssr_grid_definition_dep_a = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_ssr_grid_definition_dep_a_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.ssr_grid_definition_dep_a = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_ssr_grid_definition_dep_a_t &msg,
                 sbp_write_fn_t write) {
    return sbp_msg_ssr_grid_definition_dep_a_send(state, sender_id, &msg,
                                                  write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_ssr_grid_definition_dep_a_t &msg) {
    return sbp_msg_ssr_grid_definition_dep_a_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_ssr_grid_definition_dep_a_t *msg) {
    return sbp_msg_ssr_grid_definition_dep_a_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_ssr_grid_definition_dep_a_t &msg) {
    return sbp_msg_ssr_grid_definition_dep_a_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_ssr_gridded_correction_bounds_t> {
  static constexpr sbp_msg_type_t id = SbpMsgSsrGriddedCorrectionBounds;
  static constexpr const char *name = "MSG_SSR_GRIDDED_CORRECTION_BOUNDS";
  static const sbp_msg_ssr_gridded_correction_bounds_t &get(
      const sbp_msg_t &msg) {
    return msg.ssr_gridded_correction_bounds;
  }
  static sbp_msg_ssr_gridded_correction_bounds_t &get(sbp_msg_t &msg) {
    return msg.ssr_gridded_correction_bounds;
  }
  static void to_sbp_msg(const sbp_msg_ssr_gridded_correction_bounds_t &msg,
                         sbp_msg_t *sbp_msg) {
    sbp_msg->ssr_gridded_correction_bounds = msg;
  }
  static sbp_msg_t to_sbp_msg(
      const sbp_msg_ssr_gridded_correction_bounds_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.ssr_gridded_correction_bounds = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_ssr_gridded_correction_bounds_t &msg,
                 sbp_write_fn_t write) {
    return sbp_msg_ssr_gridded_correction_bounds_send(state, sender_id, &msg,
                                                      write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_ssr_gridded_correction_bounds_t &msg) {
    return sbp_msg_ssr_gridded_correction_bounds_encode(buf, len, n_written,
                                                        &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_ssr_gridded_correction_bounds_t *msg) {
    return sbp_msg_ssr_gridded_correction_bounds_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(
      const sbp_msg_ssr_gridded_correction_bounds_t &msg) {
    return sbp_msg_ssr_gridded_correction_bounds_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_ssr_gridded_correction_dep_a_t> {
  static constexpr sbp_msg_type_t id = SbpMsgSsrGriddedCorrectionDepA;
  static constexpr const char *name = "MSG_SSR_GRIDDED_CORRECTION_DEP_A";
  static const sbp_msg_ssr_gridded_correction_dep_a_t &get(
      const sbp_msg_t &msg) {
    return msg.ssr_gridded_correction_dep_a;
  }
  static sbp_msg_ssr_gridded_correction_dep_a_t &get(sbp_msg_t &msg) {
    return msg.ssr_gridded_correction_dep_a;
  }
  static void to_sbp_msg(const sbp_msg_ssr_gridded_correction_dep_a_t &msg,
                         sbp_msg_t *sbp_msg) {
    sbp_msg->ssr_gridded_correction_dep_a = msg;
  }
  static sbp_msg_t to_sbp_msg(
      const sbp_msg_ssr_gridded_correction_dep_a_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.ssr_gridded_correction_dep_a = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_ssr_gridded_correction_dep_a_t &msg,
                 sbp_write_fn_t write) {
    return sbp_msg_ssr_gridded_correction_dep_a_send(state, sender_id, &msg,
                                                     write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_ssr_gridded_correction_dep_a_t &msg) {
    return sbp_msg_ssr_gridded_correction_dep_a_encode(buf, len, n_written,
                                                       &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_ssr_gridded_correction_dep_a_t *msg) {
    return sbp_msg_ssr_gridded_correction_dep_a_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_ssr_gridded_correction_dep_a_t &msg) {
    return sbp_msg_ssr_gridded_correction_dep_a_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_ssr_gridded_correction_no_std_dep_a_t> {
  static constexpr sbp_msg_type_t id = SbpMsgSsrGriddedCorrectionNoStdDepA;
  static constexpr const char *name = "MSG_SSR_GRIDDED_CORRECTION_NO_STD_DEP_A";
  static const sbp_msg_ssr_gridded_correction_no_std_dep_a_t &get(
      const sbp_msg_t &msg) {
    return msg.ssr_gridded_correction_no_std_dep_a;
  }
  static sbp_msg_ssr_gridded_correction_no_std_dep_a_t &get(sbp_msg_t &msg) {
    return msg.ssr_gridded_correction_no_std_dep_a;
  }
  static void to_sbp_msg(
      const sbp_msg_ssr_gridded_correction_no_std_dep_a_t &msg,
      sbp_msg_t *sbp_msg) {
    sbp_msg->ssr_gridded_correction_no_std_dep_a = msg;
  }
  static sbp_msg_t to_sbp_msg(
      const sbp_msg_ssr_gridded_correction_no_std_dep_a_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.ssr_gridded_correction_no_std_dep_a = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_ssr_gridded_correction_no_std_dep_a_t &msg,
                 sbp_write_fn_t write) {
    return sbp_msg_ssr_gridded_correction_no_std_dep_a_send(state, sender_id,
                                                            &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_ssr_gridded_correction_no_std_dep_a_t &msg) {
    return sbp_msg_ssr_gridded_correction_no_std_dep_a_encode(buf, len,
                                                              n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_ssr_gridded_correction_no_std_dep_a_t *msg) {
    return sbp_msg_ssr_gridded_correction_no_std_dep_a_decode(buf, len, n_read,
                                                              msg);
  }
  static size_t encoded_len(
      const sbp_msg_ssr_gridded_correction_no_std_dep_a_t &msg) {
    return sbp_msg_ssr_gridded_correction_no_std_dep_a_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_ssr_gridded_correction_t> {
  static constexpr sbp_msg_type_t id = SbpMsgSsrGriddedCorrection;
  static constexpr const char *name = "MSG_SSR_GRIDDED_CORRECTION";
  static const sbp_msg_ssr_gridded_correction_t &get(const sbp_msg_t &msg) {
    return msg.ssr_gridded_correction;
  }
  static sbp_msg_ssr_gridded_correction_t &get(sbp_msg_t &msg) {
    return msg.ssr_gridded_correction;
  }
  static void to_sbp_msg(const sbp_msg_ssr_gridded_correction_t &msg,
                         sbp_msg_t *sbp_msg) {
    sbp_msg->ssr_gridded_correction = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_ssr_gridded_correction_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.ssr_gridded_correction = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_ssr_gridded_correction_t &msg,
                 sbp_write_fn_t write) {
    return sbp_msg_ssr_gridded_correction_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_ssr_gridded_correction_t &msg) {
    return sbp_msg_ssr_gridded_correction_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_ssr_gridded_correction_t *msg) {
    return sbp_msg_ssr_gridded_correction_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_ssr_gridded_correction_t &msg) {
    return sbp_msg_ssr_gridded_correction_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_ssr_orbit_clock_bounds_degradation_t> {
  static constexpr sbp_msg_type_t id = SbpMsgSsrOrbitClockBoundsDegradation;
  static constexpr const char *name = "MSG_SSR_ORBIT_CLOCK_BOUNDS_DEGRADATION";
  static const sbp_msg_ssr_orbit_clock_bounds_degradation_t &get(
      const sbp_msg_t &msg) {
    return msg.ssr_orbit_clock_bounds_degradation;
  }
  static sbp_msg_ssr_orbit_clock_bounds_degradation_t &get(sbp_msg_t &msg) {
    return msg.ssr_orbit_clock_bounds_degradation;
  }
  static void to_sbp_msg(
      const sbp_msg_ssr_orbit_clock_bounds_degradation_t &msg,
      sbp_msg_t *sbp_msg) {
    sbp_msg->ssr_orbit_clock_bounds_degradation = msg;
  }
  static sbp_msg_t to_sbp_msg(
      const sbp_msg_ssr_orbit_clock_bounds_degradation_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.ssr_orbit_clock_bounds_degradation = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_ssr_orbit_clock_bounds_degradation_t &msg,
                 sbp_write_fn_t write) {
    return sbp_msg_ssr_orbit_clock_bounds_degradation_send(state, sender_id,
                                                           &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_ssr_orbit_clock_bounds_degradation_t &msg) {
    return sbp_msg_ssr_orbit_clock_bounds_degradation_encode(buf, len,
                                                             n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_ssr_orbit_clock_bounds_degradation_t *msg) {
    return sbp_msg_ssr_orbit_clock_bounds_degradation_decode(buf, len, n_read,
                                                             msg);
  }
  static size_t encoded_len(
      const sbp_msg_ssr_orbit_clock_bounds_degradation_t &msg) {
    return sbp_msg_ssr_orbit_clock_bounds_degradation_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_ssr_orbit_clock_bounds_t> {
  static constexpr sbp_msg_type_t id = SbpMsgSsrOrbitClockBounds;
  static constexpr const char *name = "MSG_SSR_ORBIT_CLOCK_BOUNDS";
  static const sbp_msg_ssr_orbit_clock_bounds_t &get(const sbp_msg_t &msg) {
    return msg.ssr_orbit_clock_bounds;
  }
  static sbp_msg_ssr_orbit_clock_bounds_t &get(sbp_msg_t &msg) {
    return msg.ssr_orbit_clock_bounds;
  }
  static void to_sbp_msg(const sbp_msg_ssr_orbit_clock_bounds_t &msg,
                         sbp_msg_t *sbp_msg) {
    sbp_msg->ssr_orbit_clock_bounds = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_ssr_orbit_clock_bounds_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.ssr_orbit_clock_bounds = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_ssr_orbit_clock_bounds_t &msg,
                 sbp_write_fn_t write) {
    return sbp_msg_ssr_orbit_clock_bounds_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_ssr_orbit_clock_bounds_t &msg) {
    return sbp_msg_ssr_orbit_clock_bounds_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_ssr_orbit_clock_bounds_t *msg) {
    return sbp_msg_ssr_orbit_clock_bounds_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_ssr_orbit_clock_bounds_t &msg) {
    return sbp_msg_ssr_orbit_clock_bounds_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_ssr_orbit_clock_dep_a_t> {
  static constexpr sbp_msg_type_t id = SbpMsgSsrOrbitClockDepA;
  static constexpr const char *name = "MSG_SSR_ORBIT_CLOCK_DEP_A";
  static const sbp_msg_ssr_orbit_clock_dep_a_t &get(const sbp_msg_t &msg) {
    return msg.ssr_orbit_clock_dep_a;
  }
  static sbp_msg_ssr_orbit_clock_dep_a_t &get(sbp_msg_t &msg) {
    return msg.ssr_orbit_clock_dep_a;
  }
  static void to_sbp_msg(const sbp_msg_ssr_orbit_clock_dep_a_t &msg,
                         sbp_msg_t *sbp_msg) {
    sbp_msg->ssr_orbit_clock_dep_a = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_ssr_orbit_clock_dep_a_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.ssr_orbit_clock_dep_a = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_ssr_orbit_clock_dep_a_t &msg,
                 sbp_write_fn_t write) {
    return sbp_msg_ssr_orbit_clock_dep_a_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_ssr_orbit_clock_dep_a_t &msg) {
    return sbp_msg_ssr_orbit_clock_dep_a_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_ssr_orbit_clock_dep_a_t *msg) {
    return sbp_msg_ssr_orbit_clock_dep_a_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_ssr_orbit_clock_dep_a_t &msg) {
    return sbp_msg_ssr_orbit_clock_dep_a_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_ssr_orbit_clock_t> {
  static constexpr sbp_msg_type_t id = SbpMsgSsrOrbitClock;
  static constexpr const char *name = "MSG_SSR_ORBIT_CLOCK";
  static const sbp_msg_ssr_orbit_clock_t &get(const sbp_msg_t &msg) {
    return msg.ssr_orbit_clock;
  }
  static sbp_msg_ssr_orbit_clock_t &get(sbp_msg_t &msg) {
    return msg.ssr_orbit_clock;
  }
  static void to_sbp_msg(const sbp_msg_ssr_orbit_clock_t &msg,
                         sbp_msg_t *sbp_msg) {
    sbp_msg->ssr_orbit_clock = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_ssr_orbit_clock_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.ssr_orbit_clock = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_ssr_orbit_clock_t &msg, sbp_write_fn_t write) {
    return sbp_msg_ssr_orbit_clock_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_ssr_orbit_clock_t &msg) {
    return sbp_msg_ssr_orbit_clock_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_ssr_orbit_clock_t *msg) {
    return sbp_msg_ssr_orbit_clock_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_ssr_orbit_clock_t &msg) {
    return sbp_msg_ssr_orbit_clock_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_ssr_phase_biases_t> {
  static constexpr sbp_msg_type_t id = SbpMsgSsrPhaseBiases;
  static constexpr const char *name = "MSG_SSR_PHASE_BIASES";
  static const sbp_msg_ssr_phase_biases_t &get(const sbp_msg_t &msg) {
    return msg.ssr_phase_biases;
  }
  static sbp_msg_ssr_phase_biases_t &get(sbp_msg_t &msg) {
    return msg.ssr_phase_biases;
  }
  static void to_sbp_msg(const sbp_msg_ssr_phase_biases_t &msg,
                         sbp_msg_t *sbp_msg) {
    sbp_msg->ssr_phase_biases = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_ssr_phase_biases_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.ssr_phase_biases = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_ssr_phase_biases_t &msg, sbp_write_fn_t write) {
    return sbp_msg_ssr_phase_biases_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_ssr_phase_biases_t &msg) {
    return sbp_msg_ssr_phase_biases_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_ssr_phase_biases_t *msg) {
    return sbp_msg_ssr_phase_biases_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_ssr_phase_biases_t &msg) {
    return sbp_msg_ssr_phase_biases_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_ssr_satellite_apc_dep_t> {
  static constexpr sbp_msg_type_t id = SbpMsgSsrSatelliteApcDep;
  static constexpr const char *name = "MSG_SSR_SATELLITE_APC_DEP";
  static const sbp_msg_ssr_satellite_apc_dep_t &get(const sbp_msg_t &msg) {
    return msg.ssr_satellite_apc_dep;
  }
  static sbp_msg_ssr_satellite_apc_dep_t &get(sbp_msg_t &msg) {
    return msg.ssr_satellite_apc_dep;
  }
  static void to_sbp_msg(const sbp_msg_ssr_satellite_apc_dep_t &msg,
                         sbp_msg_t *sbp_msg) {
    sbp_msg->ssr_satellite_apc_dep = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_ssr_satellite_apc_dep_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.ssr_satellite_apc_dep = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_ssr_satellite_apc_dep_t &msg,
                 sbp_write_fn_t write) {
    return sbp_msg_ssr_satellite_apc_dep_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_ssr_satellite_apc_dep_t &msg) {
    return sbp_msg_ssr_satellite_apc_dep_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_ssr_satellite_apc_dep_t *msg) {
    return sbp_msg_ssr_satellite_apc_dep_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_ssr_satellite_apc_dep_t &msg) {
    return sbp_msg_ssr_satellite_apc_dep_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_ssr_satellite_apc_t> {
  static constexpr sbp_msg_type_t id = SbpMsgSsrSatelliteApc;
  static constexpr const char *name = "MSG_SSR_SATELLITE_APC";
  static const sbp_msg_ssr_satellite_apc_t &get(const sbp_msg_t &msg) {
    return msg.ssr_satellite_apc;
  }
  static sbp_msg_ssr_satellite_apc_t &get(sbp_msg_t &msg) {
    return msg.ssr_satellite_apc;
  }
  static void to_sbp_msg(const sbp_msg_ssr_satellite_apc_t &msg,
                         sbp_msg_t *sbp_msg) {
    sbp_msg->ssr_satellite_apc = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_ssr_satellite_apc_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.ssr_satellite_apc = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_ssr_satellite_apc_t &msg, sbp_write_fn_t write) {
    return sbp_msg_ssr_satellite_apc_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_ssr_satellite_apc_t &msg) {
    return sbp_msg_ssr_satellite_apc_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_ssr_satellite_apc_t *msg) {
    return sbp_msg_ssr_satellite_apc_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_ssr_satellite_apc_t &msg) {
    return sbp_msg_ssr_satellite_apc_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_ssr_stec_correction_dep_a_t> {
  static constexpr sbp_msg_type_t id = SbpMsgSsrStecCorrectionDepA;
  static constexpr const char *name = "MSG_SSR_STEC_CORRECTION_DEP_A";
  static const sbp_msg_ssr_stec_correction_dep_a_t &get(const sbp_msg_t &msg) {
    return msg.ssr_stec_correction_dep_a;
  }
  static sbp_msg_ssr_stec_correction_dep_a_t &get(sbp_msg_t &msg) {
    return msg.ssr_stec_correction_dep_a;
  }
  static void to_sbp_msg(const sbp_msg_ssr_stec_correction_dep_a_t &msg,
                         sbp_msg_t *sbp_msg) {
    sbp_msg->ssr_stec_correction_dep_a = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_ssr_stec_correction_dep_a_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.ssr_stec_correction_dep_a = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_ssr_stec_correction_dep_a_t &msg,
                 sbp_write_fn_t write) {
    return sbp_msg_ssr_stec_correction_dep_a_send(state, sender_id, &msg,
                                                  write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_ssr_stec_correction_dep_a_t &msg) {
    return sbp_msg_ssr_stec_correction_dep_a_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_ssr_stec_correction_dep_a_t *msg) {
    return sbp_msg_ssr_stec_correction_dep_a_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_ssr_stec_correction_dep_a_t &msg) {
    return sbp_msg_ssr_stec_correction_dep_a_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_ssr_stec_correction_dep_t> {
  static constexpr sbp_msg_type_t id = SbpMsgSsrStecCorrectionDep;
  static constexpr const char *name = "MSG_SSR_STEC_CORRECTION_DEP";
  static const sbp_msg_ssr_stec_correction_dep_t &get(const sbp_msg_t &msg) {
    return msg.ssr_stec_correction_dep;
  }
  static sbp_msg_ssr_stec_correction_dep_t &get(sbp_msg_t &msg) {
    return msg.ssr_stec_correction_dep;
  }
  static void to_sbp_msg(const sbp_msg_ssr_stec_correction_dep_t &msg,
                         sbp_msg_t *sbp_msg) {
    sbp_msg->ssr_stec_correction_dep = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_ssr_stec_correction_dep_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.ssr_stec_correction_dep = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_ssr_stec_correction_dep_t &msg,
                 sbp_write_fn_t write) {
    return sbp_msg_ssr_stec_correction_dep_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_ssr_stec_correction_dep_t &msg) {
    return sbp_msg_ssr_stec_correction_dep_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_ssr_stec_correction_dep_t *msg) {
    return sbp_msg_ssr_stec_correction_dep_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_ssr_stec_correction_dep_t &msg) {
    return sbp_msg_ssr_stec_correction_dep_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_ssr_stec_correction_t> {
  static constexpr sbp_msg_type_t id = SbpMsgSsrStecCorrection;
  static constexpr const char *name = "MSG_SSR_STEC_CORRECTION";
  static const sbp_msg_ssr_stec_correction_t &get(const sbp_msg_t &msg) {
    return msg.ssr_stec_correction;
  }
  static sbp_msg_ssr_stec_correction_t &get(sbp_msg_t &msg) {
    return msg.ssr_stec_correction;
  }
  static void to_sbp_msg(const sbp_msg_ssr_stec_correction_t &msg,
                         sbp_msg_t *sbp_msg) {
    sbp_msg->ssr_stec_correction = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_ssr_stec_correction_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.ssr_stec_correction = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_ssr_stec_correction_t &msg,
                 sbp_write_fn_t write) {
    return sbp_msg_ssr_stec_correction_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_ssr_stec_correction_t &msg) {
    return sbp_msg_ssr_stec_correction_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_ssr_stec_correction_t *msg) {
    return sbp_msg_ssr_stec_correction_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_ssr_stec_correction_t &msg) {
    return sbp_msg_ssr_stec_correction_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_ssr_tile_definition_dep_a_t> {
  static constexpr sbp_msg_type_t id = SbpMsgSsrTileDefinitionDepA;
  static constexpr const char *name = "MSG_SSR_TILE_DEFINITION_DEP_A";
  static const sbp_msg_ssr_tile_definition_dep_a_t &get(const sbp_msg_t &msg) {
    return msg.ssr_tile_definition_dep_a;
  }
  static sbp_msg_ssr_tile_definition_dep_a_t &get(sbp_msg_t &msg) {
    return msg.ssr_tile_definition_dep_a;
  }
  static void to_sbp_msg(const sbp_msg_ssr_tile_definition_dep_a_t &msg,
                         sbp_msg_t *sbp_msg) {
    sbp_msg->ssr_tile_definition_dep_a = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_ssr_tile_definition_dep_a_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.ssr_tile_definition_dep_a = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_ssr_tile_definition_dep_a_t &msg,
                 sbp_write_fn_t write) {
    return sbp_msg_ssr_tile_definition_dep_a_send(state, sender_id, &msg,
                                                  write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_ssr_tile_definition_dep_a_t &msg) {
    return sbp_msg_ssr_tile_definition_dep_a_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_ssr_tile_definition_dep_a_t *msg) {
    return sbp_msg_ssr_tile_definition_dep_a_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_ssr_tile_definition_dep_a_t &msg) {
    return sbp_msg_ssr_tile_definition_dep_a_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_ssr_tile_definition_dep_b_t> {
  static constexpr sbp_msg_type_t id = SbpMsgSsrTileDefinitionDepB;
  static constexpr const char *name = "MSG_SSR_TILE_DEFINITION_DEP_B";
  static const sbp_msg_ssr_tile_definition_dep_b_t &get(const sbp_msg_t &msg) {
    return msg.ssr_tile_definition_dep_b;
  }
  static sbp_msg_ssr_tile_definition_dep_b_t &get(sbp_msg_t &msg) {
    return msg.ssr_tile_definition_dep_b;
  }
  static void to_sbp_msg(const sbp_msg_ssr_tile_definition_dep_b_t &msg,
                         sbp_msg_t *sbp_msg) {
    sbp_msg->ssr_tile_definition_dep_b = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_ssr_tile_definition_dep_b_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.ssr_tile_definition_dep_b = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_ssr_tile_definition_dep_b_t &msg,
                 sbp_write_fn_t write) {
    return sbp_msg_ssr_tile_definition_dep_b_send(state, sender_id, &msg,
                                                  write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_ssr_tile_definition_dep_b_t &msg) {
    return sbp_msg_ssr_tile_definition_dep_b_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_ssr_tile_definition_dep_b_t *msg) {
    return sbp_msg_ssr_tile_definition_dep_b_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_ssr_tile_definition_dep_b_t &msg) {
    return sbp_msg_ssr_tile_definition_dep_b_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_ssr_tile_definition_t> {
  static constexpr sbp_msg_type_t id = SbpMsgSsrTileDefinition;
  static constexpr const char *name = "MSG_SSR_TILE_DEFINITION";
  static const sbp_msg_ssr_tile_definition_t &get(const sbp_msg_t &msg) {
    return msg.ssr_tile_definition;
  }
  static sbp_msg_ssr_tile_definition_t &get(sbp_msg_t &msg) {
    return msg.ssr_tile_definition;
  }
  static void to_sbp_msg(const sbp_msg_ssr_tile_definition_t &msg,
                         sbp_msg_t *sbp_msg) {
    sbp_msg->ssr_tile_definition = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_ssr_tile_definition_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.ssr_tile_definition = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_ssr_tile_definition_t &msg,
                 sbp_write_fn_t write) {
    return sbp_msg_ssr_tile_definition_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_ssr_tile_definition_t &msg) {
    return sbp_msg_ssr_tile_definition_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_ssr_tile_definition_t *msg) {
    return sbp_msg_ssr_tile_definition_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_ssr_tile_definition_t &msg) {
    return sbp_msg_ssr_tile_definition_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_startup_t> {
  static constexpr sbp_msg_type_t id = SbpMsgStartup;
  static constexpr const char *name = "MSG_STARTUP";
  static const sbp_msg_startup_t &get(const sbp_msg_t &msg) {
    return msg.startup;
  }
  static sbp_msg_startup_t &get(sbp_msg_t &msg) { return msg.startup; }
  static void to_sbp_msg(const sbp_msg_startup_t &msg, sbp_msg_t *sbp_msg) {
    sbp_msg->startup = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_startup_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.startup = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_startup_t &msg, sbp_write_fn_t write) {
    return sbp_msg_startup_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_startup_t &msg) {
    return sbp_msg_startup_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_startup_t *msg) {
    return sbp_msg_startup_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_startup_t &msg) {
    return sbp_msg_startup_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_status_journal_t> {
  static constexpr sbp_msg_type_t id = SbpMsgStatusJournal;
  static constexpr const char *name = "MSG_STATUS_JOURNAL";
  static const sbp_msg_status_journal_t &get(const sbp_msg_t &msg) {
    return msg.status_journal;
  }
  static sbp_msg_status_journal_t &get(sbp_msg_t &msg) {
    return msg.status_journal;
  }
  static void to_sbp_msg(const sbp_msg_status_journal_t &msg,
                         sbp_msg_t *sbp_msg) {
    sbp_msg->status_journal = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_status_journal_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.status_journal = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_status_journal_t &msg, sbp_write_fn_t write) {
    return sbp_msg_status_journal_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_status_journal_t &msg) {
    return sbp_msg_status_journal_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_status_journal_t *msg) {
    return sbp_msg_status_journal_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_status_journal_t &msg) {
    return sbp_msg_status_journal_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_status_report_t> {
  static constexpr sbp_msg_type_t id = SbpMsgStatusReport;
  static constexpr const char *name = "MSG_STATUS_REPORT";
  static const sbp_msg_status_report_t &get(const sbp_msg_t &msg) {
    return msg.status_report;
  }
  static sbp_msg_status_report_t &get(sbp_msg_t &msg) {
    return msg.status_report;
  }
  static void to_sbp_msg(const sbp_msg_status_report_t &msg,
                         sbp_msg_t *sbp_msg) {
    sbp_msg->status_report = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_status_report_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.status_report = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_status_report_t &msg, sbp_write_fn_t write) {
    return sbp_msg_status_report_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_status_report_t &msg) {
    return sbp_msg_status_report_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_status_report_t *msg) {
    return sbp_msg_status_report_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_status_report_t &msg) {
    return sbp_msg_status_report_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_stm_flash_lock_sector_t> {
  static constexpr sbp_msg_type_t id = SbpMsgStmFlashLockSector;
  static constexpr const char *name = "MSG_STM_FLASH_LOCK_SECTOR";
  static const sbp_msg_stm_flash_lock_sector_t &get(const sbp_msg_t &msg) {
    return msg.stm_flash_lock_sector;
  }
  static sbp_msg_stm_flash_lock_sector_t &get(sbp_msg_t &msg) {
    return msg.stm_flash_lock_sector;
  }
  static void to_sbp_msg(const sbp_msg_stm_flash_lock_sector_t &msg,
                         sbp_msg_t *sbp_msg) {
    sbp_msg->stm_flash_lock_sector = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_stm_flash_lock_sector_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.stm_flash_lock_sector = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_stm_flash_lock_sector_t &msg,
                 sbp_write_fn_t write) {
    return sbp_msg_stm_flash_lock_sector_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_stm_flash_lock_sector_t &msg) {
    return sbp_msg_stm_flash_lock_sector_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_stm_flash_lock_sector_t *msg) {
    return sbp_msg_stm_flash_lock_sector_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_stm_flash_lock_sector_t &msg) {
    return sbp_msg_stm_flash_lock_sector_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_stm_flash_unlock_sector_t> {
  static constexpr sbp_msg_type_t id = SbpMsgStmFlashUnlockSector;
  static constexpr const char *name = "MSG_STM_FLASH_UNLOCK_SECTOR";
  static const sbp_msg_stm_flash_unlock_sector_t &get(const sbp_msg_t &msg) {
    return msg.stm_flash_unlock_sector;
  }
  static sbp_msg_stm_flash_unlock_sector_t &get(sbp_msg_t &msg) {
    return msg.stm_flash_unlock_sector;
  }
  static void to_sbp_msg(const sbp_msg_stm_flash_unlock_sector_t &msg,
                         sbp_msg_t *sbp_msg) {
    sbp_msg->stm_flash_unlock_sector = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_stm_flash_unlock_sector_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.stm_flash_unlock_sector = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_stm_flash_unlock_sector_t &msg,
                 sbp_write_fn_t write) {
    return sbp_msg_stm_flash_unlock_sector_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_stm_flash_unlock_sector_t &msg) {
    return sbp_msg_stm_flash_unlock_sector_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_stm_flash_unlock_sector_t *msg) {
    return sbp_msg_stm_flash_unlock_sector_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_stm_flash_unlock_sector_t &msg) {
    return sbp_msg_stm_flash_unlock_sector_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_stm_unique_id_req_t> {
  static constexpr sbp_msg_type_t id = SbpMsgStmUniqueIdReq;
  static constexpr const char *name = "MSG_STM_UNIQUE_ID_REQ";
  static const sbp_msg_stm_unique_id_req_t &get(const sbp_msg_t &msg) {
    return msg.stm_unique_id_req;
  }
  static sbp_msg_stm_unique_id_req_t &get(sbp_msg_t &msg) {
    return msg.stm_unique_id_req;
  }
  static void to_sbp_msg(const sbp_msg_stm_unique_id_req_t &msg,
                         sbp_msg_t *sbp_msg) {
    sbp_msg->stm_unique_id_req = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_stm_unique_id_req_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.stm_unique_id_req = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_stm_unique_id_req_t &msg, sbp_write_fn_t write) {
    return sbp_msg_stm_unique_id_req_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_stm_unique_id_req_t &msg) {
    return sbp_msg_stm_unique_id_req_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_stm_unique_id_req_t *msg) {
    return sbp_msg_stm_unique_id_req_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_stm_unique_id_req_t &msg) {
    return sbp_msg_stm_unique_id_req_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_stm_unique_id_resp_t> {
  static constexpr sbp_msg_type_t id = SbpMsgStmUniqueIdResp;
  static constexpr const char *name = "MSG_STM_UNIQUE_ID_RESP";
  static const sbp_msg_stm_unique_id_resp_t &get(const sbp_msg_t &msg) {
    return msg.stm_unique_id_resp;
  }
  static sbp_msg_stm_unique_id_resp_t &get(sbp_msg_t &msg) {
    return msg.stm_unique_id_resp;
  }
  static void to_sbp_msg(const sbp_msg_stm_unique_id_resp_t &msg,
                         sbp_msg_t *sbp_msg) {
    sbp_msg->stm_unique_id_resp = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_stm_unique_id_resp_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.stm_unique_id_resp = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_stm_unique_id_resp_t &msg,
                 sbp_write_fn_t write) {
    return sbp_msg_stm_unique_id_resp_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_stm_unique_id_resp_t &msg) {
    return sbp_msg_stm_unique_id_resp_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_stm_unique_id_resp_t *msg) {
    return sbp_msg_stm_unique_id_resp_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_stm_unique_id_resp_t &msg) {
    return sbp_msg_stm_unique_id_resp_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_sv_az_el_t> {
  static constexpr sbp_msg_type_t id = SbpMsgSvAzEl;
  static constexpr const char *name = "MSG_SV_AZ_EL";
  static const sbp_msg_sv_az_el_t &get(const sbp_msg_t &msg) {
    return msg.sv_az_el;
  }
  static sbp_msg_sv_az_el_t &get(sbp_msg_t &msg) { return msg.sv_az_el; }
  static void to_sbp_msg(const sbp_msg_sv_az_el_t &msg, sbp_msg_t *sbp_msg) {
    sbp_msg->sv_az_el = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_sv_az_el_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.sv_az_el = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_sv_az_el_t &msg, sbp_write_fn_t write) {
    return sbp_msg_sv_az_el_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_sv_az_el_t &msg) {
    return sbp_msg_sv_az_el_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_sv_az_el_t *msg) {
    return sbp_msg_sv_az_el_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_sv_az_el_t &msg) {
    return sbp_msg_sv_az_el_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_sv_configuration_gps_dep_t> {
  static constexpr sbp_msg_type_t id = SbpMsgSvConfigurationGpsDep;
  static constexpr const char *name = "MSG_SV_CONFIGURATION_GPS_DEP";
  static const sbp_msg_sv_configuration_gps_dep_t &get(const sbp_msg_t &msg) {
    return msg.sv_configuration_gps_dep;
  }
  static sbp_msg_sv_configuration_gps_dep_t &get(sbp_msg_t &msg) {
    return msg.sv_configuration_gps_dep;
  }
  static void to_sbp_msg(const sbp_msg_sv_configuration_gps_dep_t &msg,
                         sbp_msg_t *sbp_msg) {
    sbp_msg->sv_configuration_gps_dep = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_sv_configuration_gps_dep_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.sv_configuration_gps_dep = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_sv_configuration_gps_dep_t &msg,
                 sbp_write_fn_t write) {
    return sbp_msg_sv_configuration_gps_dep_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_sv_configuration_gps_dep_t &msg) {
    return sbp_msg_sv_configuration_gps_dep_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_sv_configuration_gps_dep_t *msg) {
    return sbp_msg_sv_configuration_gps_dep_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_sv_configuration_gps_dep_t &msg) {
    return sbp_msg_sv_configuration_gps_dep_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_tel_sv_t> {
  static constexpr sbp_msg_type_t id = SbpMsgTelSv;
  static constexpr const char *name = "MSG_TEL_SV";
  static const sbp_msg_tel_sv_t &get(const sbp_msg_t &msg) {
    return msg.tel_sv;
  }
  static sbp_msg_tel_sv_t &get(sbp_msg_t &msg) { return msg.tel_sv; }
  static void to_sbp_msg(const sbp_msg_tel_sv_t &msg, sbp_msg_t *sbp_msg) {
    sbp_msg->tel_sv = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_tel_sv_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.tel_sv = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const sbp_msg_tel_sv_t &msg,
                 sbp_write_fn_t write) {
    return sbp_msg_tel_sv_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_tel_sv_t &msg) {
    return sbp_msg_tel_sv_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_tel_sv_t *msg) {
    return sbp_msg_tel_sv_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_tel_sv_t &msg) {
    return sbp_msg_tel_sv_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_thread_state_t> {
  static constexpr sbp_msg_type_t id = SbpMsgThreadState;
  static constexpr const char *name = "MSG_THREAD_STATE";
  static const sbp_msg_thread_state_t &get(const sbp_msg_t &msg) {
    return msg.thread_state;
  }
  static sbp_msg_thread_state_t &get(sbp_msg_t &msg) {
    return msg.thread_state;
  }
  static void to_sbp_msg(const sbp_msg_thread_state_t &msg,
                         sbp_msg_t *sbp_msg) {
    sbp_msg->thread_state = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_thread_state_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.thread_state = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_thread_state_t &msg, sbp_write_fn_t write) {
    return sbp_msg_thread_state_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_thread_state_t &msg) {
    return sbp_msg_thread_state_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_thread_state_t *msg) {
    return sbp_msg_thread_state_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_thread_state_t &msg) {
    return sbp_msg_thread_state_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_tracking_iq_dep_a_t> {
  static constexpr sbp_msg_type_t id = SbpMsgTrackingIqDepA;
  static constexpr const char *name = "MSG_TRACKING_IQ_DEP_A";
  static const sbp_msg_tracking_iq_dep_a_t &get(const sbp_msg_t &msg) {
    return msg.tracking_iq_dep_a;
  }
  static sbp_msg_tracking_iq_dep_a_t &get(sbp_msg_t &msg) {
    return msg.tracking_iq_dep_a;
  }
  static void to_sbp_msg(const sbp_msg_tracking_iq_dep_a_t &msg,
                         sbp_msg_t *sbp_msg) {
    sbp_msg->tracking_iq_dep_a = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_tracking_iq_dep_a_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.tracking_iq_dep_a = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_tracking_iq_dep_a_t &msg, sbp_write_fn_t write) {
    return sbp_msg_tracking_iq_dep_a_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_tracking_iq_dep_a_t &msg) {
    return sbp_msg_tracking_iq_dep_a_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_tracking_iq_dep_a_t *msg) {
    return sbp_msg_tracking_iq_dep_a_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_tracking_iq_dep_a_t &msg) {
    return sbp_msg_tracking_iq_dep_a_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_tracking_iq_dep_b_t> {
  static constexpr sbp_msg_type_t id = SbpMsgTrackingIqDepB;
  static constexpr const char *name = "MSG_TRACKING_IQ_DEP_B";
  static const sbp_msg_tracking_iq_dep_b_t &get(const sbp_msg_t &msg) {
    return msg.tracking_iq_dep_b;
  }
  static sbp_msg_tracking_iq_dep_b_t &get(sbp_msg_t &msg) {
    return msg.tracking_iq_dep_b;
  }
  static void to_sbp_msg(const sbp_msg_tracking_iq_dep_b_t &msg,
                         sbp_msg_t *sbp_msg) {
    sbp_msg->tracking_iq_dep_b = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_tracking_iq_dep_b_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.tracking_iq_dep_b = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_tracking_iq_dep_b_t &msg, sbp_write_fn_t write) {
    return sbp_msg_tracking_iq_dep_b_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_tracking_iq_dep_b_t &msg) {
    return sbp_msg_tracking_iq_dep_b_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_tracking_iq_dep_b_t *msg) {
    return sbp_msg_tracking_iq_dep_b_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_tracking_iq_dep_b_t &msg) {
    return sbp_msg_tracking_iq_dep_b_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_tracking_iq_t> {
  static constexpr sbp_msg_type_t id = SbpMsgTrackingIq;
  static constexpr const char *name = "MSG_TRACKING_IQ";
  static const sbp_msg_tracking_iq_t &get(const sbp_msg_t &msg) {
    return msg.tracking_iq;
  }
  static sbp_msg_tracking_iq_t &get(sbp_msg_t &msg) { return msg.tracking_iq; }
  static void to_sbp_msg(const sbp_msg_tracking_iq_t &msg, sbp_msg_t *sbp_msg) {
    sbp_msg->tracking_iq = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_tracking_iq_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.tracking_iq = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_tracking_iq_t &msg, sbp_write_fn_t write) {
    return sbp_msg_tracking_iq_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_tracking_iq_t &msg) {
    return sbp_msg_tracking_iq_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_tracking_iq_t *msg) {
    return sbp_msg_tracking_iq_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_tracking_iq_t &msg) {
    return sbp_msg_tracking_iq_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_tracking_state_dep_a_t> {
  static constexpr sbp_msg_type_t id = SbpMsgTrackingStateDepA;
  static constexpr const char *name = "MSG_TRACKING_STATE_DEP_A";
  static const sbp_msg_tracking_state_dep_a_t &get(const sbp_msg_t &msg) {
    return msg.tracking_state_dep_a;
  }
  static sbp_msg_tracking_state_dep_a_t &get(sbp_msg_t &msg) {
    return msg.tracking_state_dep_a;
  }
  static void to_sbp_msg(const sbp_msg_tracking_state_dep_a_t &msg,
                         sbp_msg_t *sbp_msg) {
    sbp_msg->tracking_state_dep_a = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_tracking_state_dep_a_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.tracking_state_dep_a = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_tracking_state_dep_a_t &msg,
                 sbp_write_fn_t write) {
    return sbp_msg_tracking_state_dep_a_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_tracking_state_dep_a_t &msg) {
    return sbp_msg_tracking_state_dep_a_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_tracking_state_dep_a_t *msg) {
    return sbp_msg_tracking_state_dep_a_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_tracking_state_dep_a_t &msg) {
    return sbp_msg_tracking_state_dep_a_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_tracking_state_dep_b_t> {
  static constexpr sbp_msg_type_t id = SbpMsgTrackingStateDepB;
  static constexpr const char *name = "MSG_TRACKING_STATE_DEP_B";
  static const sbp_msg_tracking_state_dep_b_t &get(const sbp_msg_t &msg) {
    return msg.tracking_state_dep_b;
  }
  static sbp_msg_tracking_state_dep_b_t &get(sbp_msg_t &msg) {
    return msg.tracking_state_dep_b;
  }
  static void to_sbp_msg(const sbp_msg_tracking_state_dep_b_t &msg,
                         sbp_msg_t *sbp_msg) {
    sbp_msg->tracking_state_dep_b = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_tracking_state_dep_b_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.tracking_state_dep_b = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_tracking_state_dep_b_t &msg,
                 sbp_write_fn_t write) {
    return sbp_msg_tracking_state_dep_b_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_tracking_state_dep_b_t &msg) {
    return sbp_msg_tracking_state_dep_b_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_tracking_state_dep_b_t *msg) {
    return sbp_msg_tracking_state_dep_b_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_tracking_state_dep_b_t &msg) {
    return sbp_msg_tracking_state_dep_b_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_tracking_state_detailed_dep_a_t> {
  static constexpr sbp_msg_type_t id = SbpMsgTrackingStateDetailedDepA;
  static constexpr const char *name = "MSG_TRACKING_STATE_DETAILED_DEP_A";
  static const sbp_msg_tracking_state_detailed_dep_a_t &get(
      const sbp_msg_t &msg) {
    return msg.tracking_state_detailed_dep_a;
  }
  static sbp_msg_tracking_state_detailed_dep_a_t &get(sbp_msg_t &msg) {
    return msg.tracking_state_detailed_dep_a;
  }
  static void to_sbp_msg(const sbp_msg_tracking_state_detailed_dep_a_t &msg,
                         sbp_msg_t *sbp_msg) {
    sbp_msg->tracking_state_detailed_dep_a = msg;
  }
  static sbp_msg_t to_sbp_msg(
      const sbp_msg_tracking_state_detailed_dep_a_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.tracking_state_detailed_dep_a = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_tracking_state_detailed_dep_a_t &msg,
                 sbp_write_fn_t write) {
    return sbp_msg_tracking_state_detailed_dep_a_send(state, sender_id, &msg,
                                                      write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_tracking_state_detailed_dep_a_t &msg) {
    return sbp_msg_tracking_state_detailed_dep_a_encode(buf, len, n_written,
                                                        &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_tracking_state_detailed_dep_a_t *msg) {
    return sbp_msg_tracking_state_detailed_dep_a_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(
      const sbp_msg_tracking_state_detailed_dep_a_t &msg) {
    return sbp_msg_tracking_state_detailed_dep_a_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_tracking_state_detailed_dep_t> {
  static constexpr sbp_msg_type_t id = SbpMsgTrackingStateDetailedDep;
  static constexpr const char *name = "MSG_TRACKING_STATE_DETAILED_DEP";
  static const sbp_msg_tracking_state_detailed_dep_t &get(
      const sbp_msg_t &msg) {
    return msg.tracking_state_detailed_dep;
  }
  static sbp_msg_tracking_state_detailed_dep_t &get(sbp_msg_t &msg) {
    return msg.tracking_state_detailed_dep;
  }
  static void to_sbp_msg(const sbp_msg_tracking_state_detailed_dep_t &msg,
                         sbp_msg_t *sbp_msg) {
    sbp_msg->tracking_state_detailed_dep = msg;
  }
  static sbp_msg_t to_sbp_msg(
      const sbp_msg_tracking_state_detailed_dep_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.tracking_state_detailed_dep = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_tracking_state_detailed_dep_t &msg,
                 sbp_write_fn_t write) {
    return sbp_msg_tracking_state_detailed_dep_send(state, sender_id, &msg,
                                                    write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_tracking_state_detailed_dep_t &msg) {
    return sbp_msg_tracking_state_detailed_dep_encode(buf, len, n_written,
                                                      &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_tracking_state_detailed_dep_t *msg) {
    return sbp_msg_tracking_state_detailed_dep_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_tracking_state_detailed_dep_t &msg) {
    return sbp_msg_tracking_state_detailed_dep_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_tracking_state_t> {
  static constexpr sbp_msg_type_t id = SbpMsgTrackingState;
  static constexpr const char *name = "MSG_TRACKING_STATE";
  static const sbp_msg_tracking_state_t &get(const sbp_msg_t &msg) {
    return msg.tracking_state;
  }
  static sbp_msg_tracking_state_t &get(sbp_msg_t &msg) {
    return msg.tracking_state;
  }
  static void to_sbp_msg(const sbp_msg_tracking_state_t &msg,
                         sbp_msg_t *sbp_msg) {
    sbp_msg->tracking_state = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_tracking_state_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.tracking_state = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_tracking_state_t &msg, sbp_write_fn_t write) {
    return sbp_msg_tracking_state_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_tracking_state_t &msg) {
    return sbp_msg_tracking_state_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_tracking_state_t *msg) {
    return sbp_msg_tracking_state_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_tracking_state_t &msg) {
    return sbp_msg_tracking_state_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_uart_state_depa_t> {
  static constexpr sbp_msg_type_t id = SbpMsgUartStateDepa;
  static constexpr const char *name = "MSG_UART_STATE_DEPA";
  static const sbp_msg_uart_state_depa_t &get(const sbp_msg_t &msg) {
    return msg.uart_state_depa;
  }
  static sbp_msg_uart_state_depa_t &get(sbp_msg_t &msg) {
    return msg.uart_state_depa;
  }
  static void to_sbp_msg(const sbp_msg_uart_state_depa_t &msg,
                         sbp_msg_t *sbp_msg) {
    sbp_msg->uart_state_depa = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_uart_state_depa_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.uart_state_depa = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_uart_state_depa_t &msg, sbp_write_fn_t write) {
    return sbp_msg_uart_state_depa_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_uart_state_depa_t &msg) {
    return sbp_msg_uart_state_depa_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_uart_state_depa_t *msg) {
    return sbp_msg_uart_state_depa_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_uart_state_depa_t &msg) {
    return sbp_msg_uart_state_depa_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_uart_state_t> {
  static constexpr sbp_msg_type_t id = SbpMsgUartState;
  static constexpr const char *name = "MSG_UART_STATE";
  static const sbp_msg_uart_state_t &get(const sbp_msg_t &msg) {
    return msg.uart_state;
  }
  static sbp_msg_uart_state_t &get(sbp_msg_t &msg) { return msg.uart_state; }
  static void to_sbp_msg(const sbp_msg_uart_state_t &msg, sbp_msg_t *sbp_msg) {
    sbp_msg->uart_state = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_uart_state_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.uart_state = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_uart_state_t &msg, sbp_write_fn_t write) {
    return sbp_msg_uart_state_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_uart_state_t &msg) {
    return sbp_msg_uart_state_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_uart_state_t *msg) {
    return sbp_msg_uart_state_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_uart_state_t &msg) {
    return sbp_msg_uart_state_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_user_data_t> {
  static constexpr sbp_msg_type_t id = SbpMsgUserData;
  static constexpr const char *name = "MSG_USER_DATA";
  static const sbp_msg_user_data_t &get(const sbp_msg_t &msg) {
    return msg.user_data;
  }
  static sbp_msg_user_data_t &get(sbp_msg_t &msg) { return msg.user_data; }
  static void to_sbp_msg(const sbp_msg_user_data_t &msg, sbp_msg_t *sbp_msg) {
    sbp_msg->user_data = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_user_data_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.user_data = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_user_data_t &msg, sbp_write_fn_t write) {
    return sbp_msg_user_data_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_user_data_t &msg) {
    return sbp_msg_user_data_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_user_data_t *msg) {
    return sbp_msg_user_data_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_user_data_t &msg) {
    return sbp_msg_user_data_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_utc_leap_second_t> {
  static constexpr sbp_msg_type_t id = SbpMsgUtcLeapSecond;
  static constexpr const char *name = "MSG_UTC_LEAP_SECOND";
  static const sbp_msg_utc_leap_second_t &get(const sbp_msg_t &msg) {
    return msg.utc_leap_second;
  }
  static sbp_msg_utc_leap_second_t &get(sbp_msg_t &msg) {
    return msg.utc_leap_second;
  }
  static void to_sbp_msg(const sbp_msg_utc_leap_second_t &msg,
                         sbp_msg_t *sbp_msg) {
    sbp_msg->utc_leap_second = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_utc_leap_second_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.utc_leap_second = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_utc_leap_second_t &msg, sbp_write_fn_t write) {
    return sbp_msg_utc_leap_second_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_utc_leap_second_t &msg) {
    return sbp_msg_utc_leap_second_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_utc_leap_second_t *msg) {
    return sbp_msg_utc_leap_second_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_utc_leap_second_t &msg) {
    return sbp_msg_utc_leap_second_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_utc_time_gnss_t> {
  static constexpr sbp_msg_type_t id = SbpMsgUtcTimeGnss;
  static constexpr const char *name = "MSG_UTC_TIME_GNSS";
  static const sbp_msg_utc_time_gnss_t &get(const sbp_msg_t &msg) {
    return msg.utc_time_gnss;
  }
  static sbp_msg_utc_time_gnss_t &get(sbp_msg_t &msg) {
    return msg.utc_time_gnss;
  }
  static void to_sbp_msg(const sbp_msg_utc_time_gnss_t &msg,
                         sbp_msg_t *sbp_msg) {
    sbp_msg->utc_time_gnss = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_utc_time_gnss_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.utc_time_gnss = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_utc_time_gnss_t &msg, sbp_write_fn_t write) {
    return sbp_msg_utc_time_gnss_send(state, sender_id, &msg, write);
  }
  static sbp_msg_utc_time_gnss_t to_gnss(const sbp_msg_utc_time_gnss_t &msg) {
    return msg;
  }
  static sbp_msg_utc_time_t to_non_gnss(const sbp_msg_utc_time_gnss_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.utc_time_gnss = msg;
    return sbp_msg.utc_time;
  }

  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_utc_time_gnss_t &msg) {
    return sbp_msg_utc_time_gnss_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_utc_time_gnss_t *msg) {
    return sbp_msg_utc_time_gnss_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_utc_time_gnss_t &msg) {
    return sbp_msg_utc_time_gnss_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_utc_time_t> {
  static constexpr sbp_msg_type_t id = SbpMsgUtcTime;
  static constexpr const char *name = "MSG_UTC_TIME";
  static const sbp_msg_utc_time_t &get(const sbp_msg_t &msg) {
    return msg.utc_time;
  }
  static sbp_msg_utc_time_t &get(sbp_msg_t &msg) { return msg.utc_time; }
  static void to_sbp_msg(const sbp_msg_utc_time_t &msg, sbp_msg_t *sbp_msg) {
    sbp_msg->utc_time = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_utc_time_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.utc_time = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_utc_time_t &msg, sbp_write_fn_t write) {
    return sbp_msg_utc_time_send(state, sender_id, &msg, write);
  }
  static sbp_msg_utc_time_gnss_t to_gnss(const sbp_msg_utc_time_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.utc_time = msg;
    return sbp_msg.utc_time_gnss;
  }
  static sbp_msg_utc_time_t to_non_gnss(const sbp_msg_utc_time_t &msg) {
    return msg;
  }

  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_utc_time_t &msg) {
    return sbp_msg_utc_time_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_utc_time_t *msg) {
    return sbp_msg_utc_time_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_utc_time_t &msg) {
    return sbp_msg_utc_time_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_vel_body_t> {
  static constexpr sbp_msg_type_t id = SbpMsgVelBody;
  static constexpr const char *name = "MSG_VEL_BODY";
  static const sbp_msg_vel_body_t &get(const sbp_msg_t &msg) {
    return msg.vel_body;
  }
  static sbp_msg_vel_body_t &get(sbp_msg_t &msg) { return msg.vel_body; }
  static void to_sbp_msg(const sbp_msg_vel_body_t &msg, sbp_msg_t *sbp_msg) {
    sbp_msg->vel_body = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_vel_body_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.vel_body = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_vel_body_t &msg, sbp_write_fn_t write) {
    return sbp_msg_vel_body_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_vel_body_t &msg) {
    return sbp_msg_vel_body_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_vel_body_t *msg) {
    return sbp_msg_vel_body_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_vel_body_t &msg) {
    return sbp_msg_vel_body_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_vel_cog_t> {
  static constexpr sbp_msg_type_t id = SbpMsgVelCog;
  static constexpr const char *name = "MSG_VEL_COG";
  static const sbp_msg_vel_cog_t &get(const sbp_msg_t &msg) {
    return msg.vel_cog;
  }
  static sbp_msg_vel_cog_t &get(sbp_msg_t &msg) { return msg.vel_cog; }
  static void to_sbp_msg(const sbp_msg_vel_cog_t &msg, sbp_msg_t *sbp_msg) {
    sbp_msg->vel_cog = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_vel_cog_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.vel_cog = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_vel_cog_t &msg, sbp_write_fn_t write) {
    return sbp_msg_vel_cog_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_vel_cog_t &msg) {
    return sbp_msg_vel_cog_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_vel_cog_t *msg) {
    return sbp_msg_vel_cog_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_vel_cog_t &msg) {
    return sbp_msg_vel_cog_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_vel_ecef_cov_gnss_t> {
  static constexpr sbp_msg_type_t id = SbpMsgVelEcefCovGnss;
  static constexpr const char *name = "MSG_VEL_ECEF_COV_GNSS";
  static const sbp_msg_vel_ecef_cov_gnss_t &get(const sbp_msg_t &msg) {
    return msg.vel_ecef_cov_gnss;
  }
  static sbp_msg_vel_ecef_cov_gnss_t &get(sbp_msg_t &msg) {
    return msg.vel_ecef_cov_gnss;
  }
  static void to_sbp_msg(const sbp_msg_vel_ecef_cov_gnss_t &msg,
                         sbp_msg_t *sbp_msg) {
    sbp_msg->vel_ecef_cov_gnss = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_vel_ecef_cov_gnss_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.vel_ecef_cov_gnss = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_vel_ecef_cov_gnss_t &msg, sbp_write_fn_t write) {
    return sbp_msg_vel_ecef_cov_gnss_send(state, sender_id, &msg, write);
  }
  static sbp_msg_vel_ecef_cov_gnss_t to_gnss(
      const sbp_msg_vel_ecef_cov_gnss_t &msg) {
    return msg;
  }
  static sbp_msg_vel_ecef_cov_t to_non_gnss(
      const sbp_msg_vel_ecef_cov_gnss_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.vel_ecef_cov_gnss = msg;
    return sbp_msg.vel_ecef_cov;
  }

  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_vel_ecef_cov_gnss_t &msg) {
    return sbp_msg_vel_ecef_cov_gnss_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_vel_ecef_cov_gnss_t *msg) {
    return sbp_msg_vel_ecef_cov_gnss_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_vel_ecef_cov_gnss_t &msg) {
    return sbp_msg_vel_ecef_cov_gnss_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_vel_ecef_cov_t> {
  static constexpr sbp_msg_type_t id = SbpMsgVelEcefCov;
  static constexpr const char *name = "MSG_VEL_ECEF_COV";
  static const sbp_msg_vel_ecef_cov_t &get(const sbp_msg_t &msg) {
    return msg.vel_ecef_cov;
  }
  static sbp_msg_vel_ecef_cov_t &get(sbp_msg_t &msg) {
    return msg.vel_ecef_cov;
  }
  static void to_sbp_msg(const sbp_msg_vel_ecef_cov_t &msg,
                         sbp_msg_t *sbp_msg) {
    sbp_msg->vel_ecef_cov = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_vel_ecef_cov_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.vel_ecef_cov = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_vel_ecef_cov_t &msg, sbp_write_fn_t write) {
    return sbp_msg_vel_ecef_cov_send(state, sender_id, &msg, write);
  }
  static sbp_msg_vel_ecef_cov_gnss_t to_gnss(
      const sbp_msg_vel_ecef_cov_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.vel_ecef_cov = msg;
    return sbp_msg.vel_ecef_cov_gnss;
  }
  static sbp_msg_vel_ecef_cov_t to_non_gnss(const sbp_msg_vel_ecef_cov_t &msg) {
    return msg;
  }

  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_vel_ecef_cov_t &msg) {
    return sbp_msg_vel_ecef_cov_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_vel_ecef_cov_t *msg) {
    return sbp_msg_vel_ecef_cov_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_vel_ecef_cov_t &msg) {
    return sbp_msg_vel_ecef_cov_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_vel_ecef_dep_a_t> {
  static constexpr sbp_msg_type_t id = SbpMsgVelEcefDepA;
  static constexpr const char *name = "MSG_VEL_ECEF_DEP_A";
  static const sbp_msg_vel_ecef_dep_a_t &get(const sbp_msg_t &msg) {
    return msg.vel_ecef_dep_a;
  }
  static sbp_msg_vel_ecef_dep_a_t &get(sbp_msg_t &msg) {
    return msg.vel_ecef_dep_a;
  }
  static void to_sbp_msg(const sbp_msg_vel_ecef_dep_a_t &msg,
                         sbp_msg_t *sbp_msg) {
    sbp_msg->vel_ecef_dep_a = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_vel_ecef_dep_a_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.vel_ecef_dep_a = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_vel_ecef_dep_a_t &msg, sbp_write_fn_t write) {
    return sbp_msg_vel_ecef_dep_a_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_vel_ecef_dep_a_t &msg) {
    return sbp_msg_vel_ecef_dep_a_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_vel_ecef_dep_a_t *msg) {
    return sbp_msg_vel_ecef_dep_a_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_vel_ecef_dep_a_t &msg) {
    return sbp_msg_vel_ecef_dep_a_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_vel_ecef_gnss_t> {
  static constexpr sbp_msg_type_t id = SbpMsgVelEcefGnss;
  static constexpr const char *name = "MSG_VEL_ECEF_GNSS";
  static const sbp_msg_vel_ecef_gnss_t &get(const sbp_msg_t &msg) {
    return msg.vel_ecef_gnss;
  }
  static sbp_msg_vel_ecef_gnss_t &get(sbp_msg_t &msg) {
    return msg.vel_ecef_gnss;
  }
  static void to_sbp_msg(const sbp_msg_vel_ecef_gnss_t &msg,
                         sbp_msg_t *sbp_msg) {
    sbp_msg->vel_ecef_gnss = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_vel_ecef_gnss_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.vel_ecef_gnss = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_vel_ecef_gnss_t &msg, sbp_write_fn_t write) {
    return sbp_msg_vel_ecef_gnss_send(state, sender_id, &msg, write);
  }
  static sbp_msg_vel_ecef_gnss_t to_gnss(const sbp_msg_vel_ecef_gnss_t &msg) {
    return msg;
  }
  static sbp_msg_vel_ecef_t to_non_gnss(const sbp_msg_vel_ecef_gnss_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.vel_ecef_gnss = msg;
    return sbp_msg.vel_ecef;
  }

  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_vel_ecef_gnss_t &msg) {
    return sbp_msg_vel_ecef_gnss_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_vel_ecef_gnss_t *msg) {
    return sbp_msg_vel_ecef_gnss_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_vel_ecef_gnss_t &msg) {
    return sbp_msg_vel_ecef_gnss_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_vel_ecef_t> {
  static constexpr sbp_msg_type_t id = SbpMsgVelEcef;
  static constexpr const char *name = "MSG_VEL_ECEF";
  static const sbp_msg_vel_ecef_t &get(const sbp_msg_t &msg) {
    return msg.vel_ecef;
  }
  static sbp_msg_vel_ecef_t &get(sbp_msg_t &msg) { return msg.vel_ecef; }
  static void to_sbp_msg(const sbp_msg_vel_ecef_t &msg, sbp_msg_t *sbp_msg) {
    sbp_msg->vel_ecef = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_vel_ecef_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.vel_ecef = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_vel_ecef_t &msg, sbp_write_fn_t write) {
    return sbp_msg_vel_ecef_send(state, sender_id, &msg, write);
  }
  static sbp_msg_vel_ecef_gnss_t to_gnss(const sbp_msg_vel_ecef_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.vel_ecef = msg;
    return sbp_msg.vel_ecef_gnss;
  }
  static sbp_msg_vel_ecef_t to_non_gnss(const sbp_msg_vel_ecef_t &msg) {
    return msg;
  }

  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_vel_ecef_t &msg) {
    return sbp_msg_vel_ecef_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_vel_ecef_t *msg) {
    return sbp_msg_vel_ecef_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_vel_ecef_t &msg) {
    return sbp_msg_vel_ecef_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_vel_ned_cov_gnss_t> {
  static constexpr sbp_msg_type_t id = SbpMsgVelNedCovGnss;
  static constexpr const char *name = "MSG_VEL_NED_COV_GNSS";
  static const sbp_msg_vel_ned_cov_gnss_t &get(const sbp_msg_t &msg) {
    return msg.vel_ned_cov_gnss;
  }
  static sbp_msg_vel_ned_cov_gnss_t &get(sbp_msg_t &msg) {
    return msg.vel_ned_cov_gnss;
  }
  static void to_sbp_msg(const sbp_msg_vel_ned_cov_gnss_t &msg,
                         sbp_msg_t *sbp_msg) {
    sbp_msg->vel_ned_cov_gnss = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_vel_ned_cov_gnss_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.vel_ned_cov_gnss = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_vel_ned_cov_gnss_t &msg, sbp_write_fn_t write) {
    return sbp_msg_vel_ned_cov_gnss_send(state, sender_id, &msg, write);
  }
  static sbp_msg_vel_ned_cov_gnss_t to_gnss(
      const sbp_msg_vel_ned_cov_gnss_t &msg) {
    return msg;
  }
  static sbp_msg_vel_ned_cov_t to_non_gnss(
      const sbp_msg_vel_ned_cov_gnss_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.vel_ned_cov_gnss = msg;
    return sbp_msg.vel_ned_cov;
  }

  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_vel_ned_cov_gnss_t &msg) {
    return sbp_msg_vel_ned_cov_gnss_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_vel_ned_cov_gnss_t *msg) {
    return sbp_msg_vel_ned_cov_gnss_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_vel_ned_cov_gnss_t &msg) {
    return sbp_msg_vel_ned_cov_gnss_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_vel_ned_cov_t> {
  static constexpr sbp_msg_type_t id = SbpMsgVelNedCov;
  static constexpr const char *name = "MSG_VEL_NED_COV";
  static const sbp_msg_vel_ned_cov_t &get(const sbp_msg_t &msg) {
    return msg.vel_ned_cov;
  }
  static sbp_msg_vel_ned_cov_t &get(sbp_msg_t &msg) { return msg.vel_ned_cov; }
  static void to_sbp_msg(const sbp_msg_vel_ned_cov_t &msg, sbp_msg_t *sbp_msg) {
    sbp_msg->vel_ned_cov = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_vel_ned_cov_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.vel_ned_cov = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_vel_ned_cov_t &msg, sbp_write_fn_t write) {
    return sbp_msg_vel_ned_cov_send(state, sender_id, &msg, write);
  }
  static sbp_msg_vel_ned_cov_gnss_t to_gnss(const sbp_msg_vel_ned_cov_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.vel_ned_cov = msg;
    return sbp_msg.vel_ned_cov_gnss;
  }
  static sbp_msg_vel_ned_cov_t to_non_gnss(const sbp_msg_vel_ned_cov_t &msg) {
    return msg;
  }

  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_vel_ned_cov_t &msg) {
    return sbp_msg_vel_ned_cov_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_vel_ned_cov_t *msg) {
    return sbp_msg_vel_ned_cov_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_vel_ned_cov_t &msg) {
    return sbp_msg_vel_ned_cov_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_vel_ned_dep_a_t> {
  static constexpr sbp_msg_type_t id = SbpMsgVelNedDepA;
  static constexpr const char *name = "MSG_VEL_NED_DEP_A";
  static const sbp_msg_vel_ned_dep_a_t &get(const sbp_msg_t &msg) {
    return msg.vel_ned_dep_a;
  }
  static sbp_msg_vel_ned_dep_a_t &get(sbp_msg_t &msg) {
    return msg.vel_ned_dep_a;
  }
  static void to_sbp_msg(const sbp_msg_vel_ned_dep_a_t &msg,
                         sbp_msg_t *sbp_msg) {
    sbp_msg->vel_ned_dep_a = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_vel_ned_dep_a_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.vel_ned_dep_a = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_vel_ned_dep_a_t &msg, sbp_write_fn_t write) {
    return sbp_msg_vel_ned_dep_a_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_vel_ned_dep_a_t &msg) {
    return sbp_msg_vel_ned_dep_a_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_vel_ned_dep_a_t *msg) {
    return sbp_msg_vel_ned_dep_a_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_vel_ned_dep_a_t &msg) {
    return sbp_msg_vel_ned_dep_a_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_vel_ned_gnss_t> {
  static constexpr sbp_msg_type_t id = SbpMsgVelNedGnss;
  static constexpr const char *name = "MSG_VEL_NED_GNSS";
  static const sbp_msg_vel_ned_gnss_t &get(const sbp_msg_t &msg) {
    return msg.vel_ned_gnss;
  }
  static sbp_msg_vel_ned_gnss_t &get(sbp_msg_t &msg) {
    return msg.vel_ned_gnss;
  }
  static void to_sbp_msg(const sbp_msg_vel_ned_gnss_t &msg,
                         sbp_msg_t *sbp_msg) {
    sbp_msg->vel_ned_gnss = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_vel_ned_gnss_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.vel_ned_gnss = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_vel_ned_gnss_t &msg, sbp_write_fn_t write) {
    return sbp_msg_vel_ned_gnss_send(state, sender_id, &msg, write);
  }
  static sbp_msg_vel_ned_gnss_t to_gnss(const sbp_msg_vel_ned_gnss_t &msg) {
    return msg;
  }
  static sbp_msg_vel_ned_t to_non_gnss(const sbp_msg_vel_ned_gnss_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.vel_ned_gnss = msg;
    return sbp_msg.vel_ned;
  }

  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_vel_ned_gnss_t &msg) {
    return sbp_msg_vel_ned_gnss_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_vel_ned_gnss_t *msg) {
    return sbp_msg_vel_ned_gnss_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_vel_ned_gnss_t &msg) {
    return sbp_msg_vel_ned_gnss_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_vel_ned_t> {
  static constexpr sbp_msg_type_t id = SbpMsgVelNed;
  static constexpr const char *name = "MSG_VEL_NED";
  static const sbp_msg_vel_ned_t &get(const sbp_msg_t &msg) {
    return msg.vel_ned;
  }
  static sbp_msg_vel_ned_t &get(sbp_msg_t &msg) { return msg.vel_ned; }
  static void to_sbp_msg(const sbp_msg_vel_ned_t &msg, sbp_msg_t *sbp_msg) {
    sbp_msg->vel_ned = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_vel_ned_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.vel_ned = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_vel_ned_t &msg, sbp_write_fn_t write) {
    return sbp_msg_vel_ned_send(state, sender_id, &msg, write);
  }
  static sbp_msg_vel_ned_gnss_t to_gnss(const sbp_msg_vel_ned_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.vel_ned = msg;
    return sbp_msg.vel_ned_gnss;
  }
  static sbp_msg_vel_ned_t to_non_gnss(const sbp_msg_vel_ned_t &msg) {
    return msg;
  }

  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_vel_ned_t &msg) {
    return sbp_msg_vel_ned_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_vel_ned_t *msg) {
    return sbp_msg_vel_ned_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_vel_ned_t &msg) {
    return sbp_msg_vel_ned_encoded_len(&msg);
  }
};

template <>
struct MessageTraits<sbp_msg_wheeltick_t> {
  static constexpr sbp_msg_type_t id = SbpMsgWheeltick;
  static constexpr const char *name = "MSG_WHEELTICK";
  static const sbp_msg_wheeltick_t &get(const sbp_msg_t &msg) {
    return msg.wheeltick;
  }
  static sbp_msg_wheeltick_t &get(sbp_msg_t &msg) { return msg.wheeltick; }
  static void to_sbp_msg(const sbp_msg_wheeltick_t &msg, sbp_msg_t *sbp_msg) {
    sbp_msg->wheeltick = msg;
  }
  static sbp_msg_t to_sbp_msg(const sbp_msg_wheeltick_t &msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.wheeltick = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id,
                 const sbp_msg_wheeltick_t &msg, sbp_write_fn_t write) {
    return sbp_msg_wheeltick_send(state, sender_id, &msg, write);
  }
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                   const sbp_msg_wheeltick_t &msg) {
    return sbp_msg_wheeltick_encode(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                   sbp_msg_wheeltick_t *msg) {
    return sbp_msg_wheeltick_decode(buf, len, n_read, msg);
  }
  static size_t encoded_len(const sbp_msg_wheeltick_t &msg) {
    return sbp_msg_wheeltick_encoded_len(&msg);
  }
};

}  // namespace sbp

#endif  // LIBSBP_CPP_MESSAGE_TRAITS_H
