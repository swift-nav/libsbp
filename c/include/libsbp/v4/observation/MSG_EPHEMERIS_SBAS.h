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
 * Automatically generated from yaml/swiftnav/sbp/observation.yaml
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

#ifndef LIBSBP_V4_OBSERVATION_MSG_EPHEMERIS_SBAS_MESSAGES_H
#define LIBSBP_V4_OBSERVATION_MSG_EPHEMERIS_SBAS_MESSAGES_H

#include <endian.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>

#include <libsbp/common.h>
#include <libsbp/observation_macros.h>
#include <libsbp/v4/gnss.h>
#include <libsbp/v4/observation/EphemerisCommonContent.h>
#include <libsbp/v4/string/double_null_terminated.h>
#include <libsbp/v4/string/multipart.h>
#include <libsbp/v4/string/null_terminated.h>
#include <libsbp/v4/string/unterminated.h>

#ifdef __cplusplus
extern "C" {
#endif

struct sbp_state;

/******************************************************************************
 *
 * SBP_MSG_EPHEMERIS_SBAS
 *
 *****************************************************************************/
typedef struct {
  /**
   * Values common for all ephemeris types
   */
  sbp_ephemeris_common_content_t common;

  /**
   * Position of the GEO at time toe [m]
   */
  double pos[3];

  /**
   * Velocity of the GEO at time toe [m/s]
   */
  float vel[3];

  /**
   * Acceleration of the GEO at time toe [m/s^2]
   */
  float acc[3];

  /**
   * Time offset of the GEO clock w.r.t. SBAS Network Time [s]
   */
  float a_gf0;

  /**
   * Drift of the GEO clock w.r.t. SBAS Network Time [s/s]
   */
  float a_gf1;
} sbp_msg_ephemeris_sbas_t;

/**
 * Get encoded size of an instance of sbp_msg_ephemeris_sbas_t
 *
 * @param msg sbp_msg_ephemeris_sbas_t instance
 * @return Length of on-wire representation
 */
size_t sbp_msg_ephemeris_sbas_encoded_len(const sbp_msg_ephemeris_sbas_t *msg);

/**
 * Encode an instance of sbp_msg_ephemeris_sbas_t to wire representation
 *
 * This function encodes the given instance in to the user provided buffer. The
 * buffer provided to this function must be large enough to store the encoded
 * message otherwise it will return SBP_ENCODE_ERROR without writing anything to
 * the buffer.
 *
 * Specify the length of the destination buffer in the \p len parameter. If
 * non-null the number of bytes written to the buffer will be returned in \p
 * n_written.
 *
 * @param buf Destination buffer
 * @param len Length of \p buf
 * @param n_written If not null, on success will be set to the number of bytes
 * written to \p buf
 * @param msg Instance of sbp_msg_ephemeris_sbas_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_msg_ephemeris_sbas_encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                                 const sbp_msg_ephemeris_sbas_t *msg);

/**
 * Decode an instance of sbp_msg_ephemeris_sbas_t from wire representation
 *
 * This function decodes the wire representation of a sbp_msg_ephemeris_sbas_t
 * message to the given instance. The caller must specify the length of the
 * buffer in the \p len parameter. If non-null the number of bytes read from the
 * buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_msg_ephemeris_sbas_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_msg_ephemeris_sbas_decode(const uint8_t *buf, uint8_t len,
                                 uint8_t *n_read,
                                 sbp_msg_ephemeris_sbas_t *msg);
/**
 * Send an instance of sbp_msg_ephemeris_sbas_t with the given write function
 *
 * An equivalent of #sbp_send_message which operates specifically on
 * sbp_msg_ephemeris_sbas_t
 *
 * The given message will be encoded to wire representation and passed in to the
 * given write function callback. The write callback will be called several
 * times for each invocation of this function.
 *
 * @param s SBP state
 * @param sender_id SBP sender id
 * @param msg Message to send
 * @param write Write function
 * @param SBP_OK on success, or other libsbp error code
 */
s8 sbp_msg_ephemeris_sbas_send(struct sbp_state *s, u16 sender_id,
                               const sbp_msg_ephemeris_sbas_t *msg,
                               sbp_write_fn_t write);

/**
 * Compare two instances of sbp_msg_ephemeris_sbas_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_ephemeris_sbas_t instance
 * @param b sbp_msg_ephemeris_sbas_t instance
 * @return 0, <0, >0
 */
int sbp_msg_ephemeris_sbas_cmp(const sbp_msg_ephemeris_sbas_t *a,
                               const sbp_msg_ephemeris_sbas_t *b);

#ifdef __cplusplus
}

static inline bool operator==(const sbp_msg_ephemeris_sbas_t &lhs,
                              const sbp_msg_ephemeris_sbas_t &rhs) {
  return sbp_msg_ephemeris_sbas_cmp(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_msg_ephemeris_sbas_t &lhs,
                              const sbp_msg_ephemeris_sbas_t &rhs) {
  return sbp_msg_ephemeris_sbas_cmp(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_ephemeris_sbas_t &lhs,
                             const sbp_msg_ephemeris_sbas_t &rhs) {
  return sbp_msg_ephemeris_sbas_cmp(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_msg_ephemeris_sbas_t &lhs,
                              const sbp_msg_ephemeris_sbas_t &rhs) {
  return sbp_msg_ephemeris_sbas_cmp(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_ephemeris_sbas_t &lhs,
                             const sbp_msg_ephemeris_sbas_t &rhs) {
  return sbp_msg_ephemeris_sbas_cmp(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_msg_ephemeris_sbas_t &lhs,
                              const sbp_msg_ephemeris_sbas_t &rhs) {
  return sbp_msg_ephemeris_sbas_cmp(&lhs, &rhs) >= 0;
}

#endif

#endif /* LIBSBP_V4_OBSERVATION_MESSAGES_H */
