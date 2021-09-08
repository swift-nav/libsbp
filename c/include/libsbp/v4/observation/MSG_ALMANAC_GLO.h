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

#ifndef LIBSBP_V4_OBSERVATION_MSG_ALMANAC_GLO_H
#define LIBSBP_V4_OBSERVATION_MSG_ALMANAC_GLO_H

#include <math.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>

#include <libsbp/common.h>
#include <libsbp/observation_macros.h>
#include <libsbp/v4/observation/AlmanacCommonContent.h>
#include <libsbp/v4/string/sbp_string.h>

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
 *
 * SBP_MSG_ALMANAC_GLO
 *
 *****************************************************************************/
/** Satellite broadcast ephemeris for GLO
 *
 * The almanac message returns a set of satellite orbit parameters. Almanac data
 * is not very precise and is considered valid for up to several months. Please
 * see the GLO ICD 5.1 "Chapter 4.5 Non-immediate information and almanac" for
 * details.
 */
typedef struct {
  /**
   * Values common for all almanac types
   */
  sbp_almanac_common_content_t common;

  /**
   * Longitude of the first ascending node of the orbit in PZ-90.02 coordinate
   * system [rad]
   */
  double lambda_na;

  /**
   * Time of the first ascending node passage [s]
   */
  double t_lambda_na;

  /**
   * Value of inclination at instant of t_lambda [rad]
   */
  double i;

  /**
   * Value of Draconian period at instant of t_lambda [s/orbital period]
   */
  double t;

  /**
   * Rate of change of the Draconian period [s/(orbital period^2)]
   */
  double t_dot;

  /**
   * Eccentricity at instant of t_lambda
   */
  double epsilon;

  /**
   * Argument of perigee at instant of t_lambda [rad]
   */
  double omega;
} sbp_msg_almanac_glo_t;

/**
 * Get encoded size of an instance of sbp_msg_almanac_glo_t
 *
 * @param msg sbp_msg_almanac_glo_t instance
 * @return Length of on-wire representation
 */
static inline size_t sbp_msg_almanac_glo_encoded_len(
    const sbp_msg_almanac_glo_t *msg) {
  (void)msg;
  return SBP_MSG_ALMANAC_GLO_ENCODED_LEN;
}

/**
 * Encode an instance of sbp_msg_almanac_glo_t to wire representation
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
 * @param msg Instance of sbp_msg_almanac_glo_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
SBP_EXPORT s8 sbp_msg_almanac_glo_encode(uint8_t *buf, uint8_t len,
                                         uint8_t *n_written,
                                         const sbp_msg_almanac_glo_t *msg);

/**
 * Decode an instance of sbp_msg_almanac_glo_t from wire representation
 *
 * This function decodes the wire representation of a sbp_msg_almanac_glo_t
 * message to the given instance. The caller must specify the length of the
 * buffer in the \p len parameter. If non-null the number of bytes read from the
 * buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_msg_almanac_glo_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
SBP_EXPORT s8 sbp_msg_almanac_glo_decode(const uint8_t *buf, uint8_t len,
                                         uint8_t *n_read,
                                         sbp_msg_almanac_glo_t *msg);
/**
 * Send an instance of sbp_msg_almanac_glo_t with the given write function
 *
 * An equivalent of #sbp_message_send which operates specifically on
 * sbp_msg_almanac_glo_t
 *
 * The given message will be encoded to wire representation and passed in to the
 * given write function callback. The write callback will be called several
 * times for each invocation of this function.
 *
 * @param s SBP state
 * @param sender_id SBP sender id
 * @param msg Message to send
 * @param write Write function
 * @return SBP_OK on success, or other libsbp error code
 */
SBP_EXPORT s8 sbp_msg_almanac_glo_send(sbp_state_t *s, u16 sender_id,
                                       const sbp_msg_almanac_glo_t *msg,
                                       sbp_write_fn_t write);

/**
 * Compare two instances of sbp_msg_almanac_glo_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_almanac_glo_t instance
 * @param b sbp_msg_almanac_glo_t instance
 * @return 0, <0, >0
 */
SBP_EXPORT int sbp_msg_almanac_glo_cmp(const sbp_msg_almanac_glo_t *a,
                                       const sbp_msg_almanac_glo_t *b);

#ifdef __cplusplus
}

static inline bool operator==(const sbp_msg_almanac_glo_t &lhs,
                              const sbp_msg_almanac_glo_t &rhs) {
  return sbp_msg_almanac_glo_cmp(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_msg_almanac_glo_t &lhs,
                              const sbp_msg_almanac_glo_t &rhs) {
  return sbp_msg_almanac_glo_cmp(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_almanac_glo_t &lhs,
                             const sbp_msg_almanac_glo_t &rhs) {
  return sbp_msg_almanac_glo_cmp(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_msg_almanac_glo_t &lhs,
                              const sbp_msg_almanac_glo_t &rhs) {
  return sbp_msg_almanac_glo_cmp(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_almanac_glo_t &lhs,
                             const sbp_msg_almanac_glo_t &rhs) {
  return sbp_msg_almanac_glo_cmp(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_msg_almanac_glo_t &lhs,
                              const sbp_msg_almanac_glo_t &rhs) {
  return sbp_msg_almanac_glo_cmp(&lhs, &rhs) >= 0;
}

#endif  // ifdef __cplusplus

#endif /* LIBSBP_V4_OBSERVATION_MSG_ALMANAC_GLO_H */
