/*
 * Copyright (C) 2015-2018 Swift Navigation Inc.
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
 * Automatically generated
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

#ifndef NEW_MESSAGES_UNION_H
#define NEW_MESSAGES_UNION_H

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
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

struct sbp_state;

typedef union {
  sbp_msg_log_t log;
  sbp_msg_obs_t obs;
  sbp_msg_sv_az_el_t sv_az_el;
  sbp_msg_settings_read_by_index_resp_t settings_read_by_index_resp;
  sbp_msg_settings_read_by_index_done_t settings_read_by_index_done;
  sbp_msg_group_meta_t group_meta;
} sbp_msg_t;

static inline s8 sbp_encode_msg(uint8_t *buf, uint8_t len, uint8_t *n_written,
                                uint16_t msg_type, const sbp_msg_t *msg) {
  switch (msg_type) {
    case SBP_MSG_LOG:
      return sbp_encode_sbp_msg_log_t(buf, len, n_written, &msg->log);
    case SBP_MSG_OBS:
      return sbp_encode_sbp_msg_obs_t(buf, len, n_written, &msg->obs);
    case SBP_MSG_SV_AZ_EL:
      return sbp_encode_sbp_msg_sv_az_el_t(buf, len, n_written, &msg->sv_az_el);
    case SBP_MSG_SETTINGS_READ_BY_INDEX_RESP:
      return sbp_encode_sbp_msg_settings_read_by_index_resp_t(
          buf, len, n_written, &msg->settings_read_by_index_resp);
    case SBP_MSG_SETTINGS_READ_BY_INDEX_DONE:
      return sbp_encode_sbp_msg_settings_read_by_index_done_t(
          buf, len, n_written, &msg->settings_read_by_index_done);
    case SBP_MSG_GROUP_META:
      return sbp_encode_sbp_msg_group_meta_t(buf, len, n_written,
                                             &msg->group_meta);
    default:
      break;
  }
  return -1;
}

static inline s8 sbp_decode_msg(const uint8_t *buf, uint8_t len,
                                uint8_t *n_read, uint16_t msg_type,
                                sbp_msg_t *msg) {
  switch (msg_type) {
    case SBP_MSG_LOG:
      return sbp_decode_sbp_msg_log_t(buf, len, n_read, &msg->log);
    case SBP_MSG_OBS:
      return sbp_decode_sbp_msg_obs_t(buf, len, n_read, &msg->obs);
    case SBP_MSG_SV_AZ_EL:
      return sbp_decode_sbp_msg_sv_az_el_t(buf, len, n_read, &msg->sv_az_el);
    case SBP_MSG_SETTINGS_READ_BY_INDEX_RESP:
      return sbp_decode_sbp_msg_settings_read_by_index_resp_t(
          buf, len, n_read, &msg->settings_read_by_index_resp);
    case SBP_MSG_SETTINGS_READ_BY_INDEX_DONE:
      return sbp_decode_sbp_msg_settings_read_by_index_done_t(
          buf, len, n_read, &msg->settings_read_by_index_done);
    case SBP_MSG_GROUP_META:
      return sbp_decode_sbp_msg_group_meta_t(buf, len, n_read,
                                             &msg->group_meta);
    default:
      break;
  }
  return -1;
}

static inline size_t sbp_packed_size(uint16_t msg_type, const sbp_msg_t *msg) {
  switch (msg_type) {
    case SBP_MSG_LOG:
      return sbp_packed_size_sbp_msg_log_t(&msg->log);
    case SBP_MSG_OBS:
      return sbp_packed_size_sbp_msg_obs_t(&msg->obs);
    case SBP_MSG_SV_AZ_EL:
      return sbp_packed_size_sbp_msg_sv_az_el_t(&msg->sv_az_el);
    case SBP_MSG_SETTINGS_READ_BY_INDEX_RESP:
      return sbp_packed_size_sbp_msg_settings_read_by_index_resp_t(
          &msg->settings_read_by_index_resp);
    case SBP_MSG_SETTINGS_READ_BY_INDEX_DONE:
      return sbp_packed_size_sbp_msg_settings_read_by_index_done_t(
          &msg->settings_read_by_index_done);
    case SBP_MSG_GROUP_META:
      return sbp_packed_size_sbp_msg_group_meta_t(&msg->group_meta);
    default:
      break;
  }
  return 0;
}

static inline int sbp_msg_cmp(uint16_t msg_type, const sbp_msg_t *a,
                              const sbp_msg_t *b) {
  switch (msg_type) {
    case SBP_MSG_LOG:
      return sbp_cmp_sbp_msg_log_t(&a->log, &b->log);
    case SBP_MSG_OBS:
      return sbp_cmp_sbp_msg_obs_t(&a->obs, &b->obs);
    case SBP_MSG_SV_AZ_EL:
      return sbp_cmp_sbp_msg_sv_az_el_t(&a->sv_az_el, &b->sv_az_el);
    case SBP_MSG_SETTINGS_READ_BY_INDEX_RESP:
      return sbp_cmp_sbp_msg_settings_read_by_index_resp_t(
          &a->settings_read_by_index_resp, &b->settings_read_by_index_resp);
    case SBP_MSG_SETTINGS_READ_BY_INDEX_DONE:
      return sbp_cmp_sbp_msg_settings_read_by_index_done_t(
          &a->settings_read_by_index_done, &b->settings_read_by_index_done);
    case SBP_MSG_GROUP_META:
      return sbp_cmp_sbp_msg_group_meta_t(&a->group_meta, &b->group_meta);
    default:
      break;
  }
  return 0;
}

#ifdef __cplusplus
}
#endif

#endif
