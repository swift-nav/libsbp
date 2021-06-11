/*
 * Copyright (C) 2015-2021 Swift Navigation Inc.
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

#ifndef LIBSBP_V4_SBP_MSG_H
#define LIBSBP_V4_SBP_MSG_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#include <libsbp/sbp_msg_type.h>
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
#include <libsbp/v4/settings.h>
#include <libsbp/v4/solution_meta.h>
#include <libsbp/v4/ssr.h>
#include <libsbp/v4/system.h>
#include <libsbp/v4/tracking.h>
#include <libsbp/v4/user.h>
#include <libsbp/v4/vehicle.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Used to hold an individual sbp_msg struct so that the message can be used in
 * all general purpose functions within this file.
 */
typedef union {
  sbp_msg_group_meta_t group_meta;
  sbp_msg_log_t log;
  sbp_msg_obs_t obs;
  sbp_msg_settings_read_by_index_done_t settings_read_by_index_done;
  sbp_msg_settings_read_by_index_resp_t settings_read_by_index_resp;
  sbp_msg_sv_az_el_t sv_az_el;
} sbp_msg_t;

/** Encodes a SBP message to the SBP wire format, writing it to the given
 * buffer.
 *
 * \param buf         Buffer to write the resulting encoded data to
 * \param len         The amount of bytes available in buf
 * \param n_written   (out) Number of bytes written to buf
 * \param msg_type    SBP message type
 * \param msg         SBP message to encode
 * \return `SBP_ENCODE_ERROR` (-7) if message was unable to be encoded
 *         `SBP_OK` (0) if the message was successfully encoded and written to
 * buf callback
 */
static inline s8 sbp_message_encode(uint8_t *buf, uint8_t len,
                                    uint8_t *n_written, sbp_msg_type_t msg_type,
                                    const sbp_msg_t *msg) {
  switch (msg_type) {
    case SbpMsgGroupMeta:
      return sbp_msg_group_meta_encode(buf, len, n_written, &msg->group_meta);
    case SbpMsgLog:
      return sbp_msg_log_encode(buf, len, n_written, &msg->log);
    case SbpMsgObs:
      return sbp_msg_obs_encode(buf, len, n_written, &msg->obs);
    case SbpMsgSettingsReadByIndexDone:
      return sbp_msg_settings_read_by_index_done_encode(
          buf, len, n_written, &msg->settings_read_by_index_done);
    case SbpMsgSettingsReadByIndexResp:
      return sbp_msg_settings_read_by_index_resp_encode(
          buf, len, n_written, &msg->settings_read_by_index_resp);
    case SbpMsgSvAzEl:
      return sbp_msg_sv_az_el_encode(buf, len, n_written, &msg->sv_az_el);
    default:
      break;
  }
  return -1;
}

/** Decodes a SBP message from the SBP encoded wire format.
 *
 * \param buf         Buffer containing the encoded SBP message
 * \param len         Number of bytes in buf
 * \param n_read      (out) The number of bytes read when decoding
 * \param msg_type    SBP message type to decode to
 * \param msg         SBP message struct to fill in the details of
 * \return `SBP_DECODE_ERROR` (-8) if message was unable to be decoded
 *         `SBP_OK` (0) if the message was successfully decoded
 *         callback
 */
static inline s8 sbp_message_decode(const uint8_t *buf, uint8_t len,
                                    uint8_t *n_read, sbp_msg_type_t msg_type,
                                    sbp_msg_t *msg) {
  switch (msg_type) {
    case SbpMsgGroupMeta:
      return sbp_msg_group_meta_decode(buf, len, n_read, &msg->group_meta);
    case SbpMsgLog:
      return sbp_msg_log_decode(buf, len, n_read, &msg->log);
    case SbpMsgObs:
      return sbp_msg_obs_decode(buf, len, n_read, &msg->obs);
    case SbpMsgSettingsReadByIndexDone:
      return sbp_msg_settings_read_by_index_done_decode(
          buf, len, n_read, &msg->settings_read_by_index_done);
    case SbpMsgSettingsReadByIndexResp:
      return sbp_msg_settings_read_by_index_resp_decode(
          buf, len, n_read, &msg->settings_read_by_index_resp);
    case SbpMsgSvAzEl:
      return sbp_msg_sv_az_el_decode(buf, len, n_read, &msg->sv_az_el);
    default:
      break;
  }
  return -1;
}

/** Returns the wire format size in bytes of a given SBP message.
 *
 * \param msg_type    SBP message type
 * \param msg         SBP message
 * \return            The Number of bytes that the given message would be on the
 * wire
 */
static inline size_t sbp_message_encoded_len(sbp_msg_type_t msg_type,
                                             const sbp_msg_t *msg) {
  switch (msg_type) {
    case SbpMsgGroupMeta:
      return sbp_msg_group_meta_encoded_len(&msg->group_meta);
    case SbpMsgLog:
      return sbp_msg_log_encoded_len(&msg->log);
    case SbpMsgObs:
      return sbp_msg_obs_encoded_len(&msg->obs);
    case SbpMsgSettingsReadByIndexDone:
      return sbp_msg_settings_read_by_index_done_encoded_len(
          &msg->settings_read_by_index_done);
    case SbpMsgSettingsReadByIndexResp:
      return sbp_msg_settings_read_by_index_resp_encoded_len(
          &msg->settings_read_by_index_resp);
    case SbpMsgSvAzEl:
      return sbp_msg_sv_az_el_encoded_len(&msg->sv_az_el);
    default:
      break;
  }
  return 0;
}

/** Compares two SBP messages of equal type.
 *
 * \param msg_type    SBP message type
 * \param a           The first message to compare
 * \param b           The second message to compare
 * \return            0 if the two messages have equal fields
 *                    1 if, on the first non-equal field, a.field > b.field
 *                    -1 if, on the first non-equal field, a.field < b.field
 */
static inline int sbp_message_cmp(sbp_msg_type_t msg_type, const sbp_msg_t *a,
                                  const sbp_msg_t *b) {
  switch (msg_type) {
    case SbpMsgGroupMeta:
      return sbp_msg_group_meta_cmp(&a->group_meta, &b->group_meta);
    case SbpMsgLog:
      return sbp_msg_log_cmp(&a->log, &b->log);
    case SbpMsgObs:
      return sbp_msg_obs_cmp(&a->obs, &b->obs);
    case SbpMsgSettingsReadByIndexDone:
      return sbp_msg_settings_read_by_index_done_cmp(
          &a->settings_read_by_index_done, &b->settings_read_by_index_done);
    case SbpMsgSettingsReadByIndexResp:
      return sbp_msg_settings_read_by_index_resp_cmp(
          &a->settings_read_by_index_resp, &b->settings_read_by_index_resp);
    case SbpMsgSvAzEl:
      return sbp_msg_sv_az_el_cmp(&a->sv_az_el, &b->sv_az_el);
    default:
      break;
  }
  return 0;
}

#ifdef __cplusplus
}
#endif

#endif /* LIBSBP_V4_SBP_MSG_H */
