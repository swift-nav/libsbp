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

#ifndef LIBSBP_NEW_OBSERVATION_MSG_EPHEMERIS_GLO_DEP_A_MESSAGES_H
#define LIBSBP_NEW_OBSERVATION_MSG_EPHEMERIS_GLO_DEP_A_MESSAGES_H

#include <endian.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>

#include <libsbp/common.h>
#include <libsbp/new/gnss.h>
#include <libsbp/new/observation/EphemerisCommonContentDepA.h>
#include <libsbp/new/string/double_null_terminated.h>
#include <libsbp/new/string/multipart.h>
#include <libsbp/new/string/null_terminated.h>
#include <libsbp/new/string/unterminated.h>
#include <libsbp/observation_macros.h>

#ifdef __cplusplus
extern "C" {
#endif

struct sbp_state;
/******************************************************************************
 *
 * SBP_MSG_EPHEMERIS_GLO_DEP_A
 *
 *****************************************************************************/
/** Satellite broadcast ephemeris for GLO
 *
 * The ephemeris message returns a set of satellite orbit parameters that is
 * used to calculate GLO satellite position, velocity, and clock offset. Please
 * see the GLO ICD 5.1 "Table 4.5 Characteristics of words of immediate
 * information (ephemeris parameters)" for more details.
 */
typedef struct {
  /**
   * Values common for all ephemeris types
   */
  sbp_ephemeris_common_content_dep_a_t common;

  /**
   * Relative deviation of predicted carrier frequency from nominal
   */
  double gamma;

  /**
   * Correction to the SV time [s]
   */
  double tau;

  /**
   * Position of the SV at tb in PZ-90.02 coordinates system [m]
   */
  double pos[3];

  /**
   * Velocity vector of the SV at tb in PZ-90.02 coordinates system [m/s]
   */
  double vel[3];

  /**
   * Acceleration vector of the SV at tb in PZ-90.02 coordinates sys [m/s^2]
   */
  double acc[3];
} sbp_msg_ephemeris_glo_dep_a_t;

/**
 * Get encoded size of an instance of sbp_msg_ephemeris_glo_dep_a_t
 *
 * @param msg sbp_msg_ephemeris_glo_dep_a_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_msg_ephemeris_glo_dep_a_t(
    const sbp_msg_ephemeris_glo_dep_a_t *msg);

/**
 * Encode an instance of sbp_msg_ephemeris_glo_dep_a_t to wire representation
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
 * @param msg Instance of sbp_msg_ephemeris_glo_dep_a_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_msg_ephemeris_glo_dep_a_t(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_msg_ephemeris_glo_dep_a_t *msg);

/**
 * Decode an instance of sbp_msg_ephemeris_glo_dep_a_t from wire representation
 *
 * This function decodes the wire representation of a
 * sbp_msg_ephemeris_glo_dep_a_t message to the given instance. The caller must
 * specify the length of the buffer in the \p len parameter. If non-null the
 * number of bytes read from the buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_msg_ephemeris_glo_dep_a_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_msg_ephemeris_glo_dep_a_t(const uint8_t *buf, uint8_t len,
                                            uint8_t *n_read,
                                            sbp_msg_ephemeris_glo_dep_a_t *msg);
/**
 * Send an instance of sbp_msg_ephemeris_glo_dep_a_t with the given write
 * function
 *
 * An equivalent of #sbp_send_message which operates specifically on
 * sbp_msg_ephemeris_glo_dep_a_t
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
s8 sbp_send_sbp_msg_ephemeris_glo_dep_a_t(
    struct sbp_state *s, u16 sender_id,
    const sbp_msg_ephemeris_glo_dep_a_t *msg,
    s32 (*write)(u8 *buff, u32 n, void *context));

/**
 * Compare two instances of sbp_msg_ephemeris_glo_dep_a_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_ephemeris_glo_dep_a_t instance
 * @param b sbp_msg_ephemeris_glo_dep_a_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_msg_ephemeris_glo_dep_a_t(
    const sbp_msg_ephemeris_glo_dep_a_t *a,
    const sbp_msg_ephemeris_glo_dep_a_t *b);

#ifdef __cplusplus
}
static inline bool operator==(const sbp_msg_ephemeris_glo_dep_a_t &lhs,
                              const sbp_msg_ephemeris_glo_dep_a_t &rhs) {
  return sbp_cmp_sbp_msg_ephemeris_glo_dep_a_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_msg_ephemeris_glo_dep_a_t &lhs,
                              const sbp_msg_ephemeris_glo_dep_a_t &rhs) {
  return sbp_cmp_sbp_msg_ephemeris_glo_dep_a_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_ephemeris_glo_dep_a_t &lhs,
                             const sbp_msg_ephemeris_glo_dep_a_t &rhs) {
  return sbp_cmp_sbp_msg_ephemeris_glo_dep_a_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_msg_ephemeris_glo_dep_a_t &lhs,
                              const sbp_msg_ephemeris_glo_dep_a_t &rhs) {
  return sbp_cmp_sbp_msg_ephemeris_glo_dep_a_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_ephemeris_glo_dep_a_t &lhs,
                             const sbp_msg_ephemeris_glo_dep_a_t &rhs) {
  return sbp_cmp_sbp_msg_ephemeris_glo_dep_a_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_msg_ephemeris_glo_dep_a_t &lhs,
                              const sbp_msg_ephemeris_glo_dep_a_t &rhs) {
  return sbp_cmp_sbp_msg_ephemeris_glo_dep_a_t(&lhs, &rhs) >= 0;
}

#endif

#endif /* LIBSBP_NEW_OBSERVATION_MESSAGES_H */
