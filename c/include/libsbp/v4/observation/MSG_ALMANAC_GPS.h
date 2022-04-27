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

#ifndef LIBSBP_V4_OBSERVATION_MSG_ALMANAC_GPS_H
#define LIBSBP_V4_OBSERVATION_MSG_ALMANAC_GPS_H

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
 * SBP_MSG_ALMANAC_GPS
 *
 *****************************************************************************/
/** Satellite broadcast ephemeris for GPS
 *
 * The almanac message returns a set of satellite orbit parameters. Almanac data
 * is not very precise and is considered valid for up to several months. Please
 * see the Navstar GPS Space Segment/Navigation user interfaces (ICD-GPS-200,
 * Chapter 20.3.3.5.1.2 Almanac Data) for more details.
 */
typedef struct {
  /**
   * Values common for all almanac types
   */
  sbp_almanac_common_content_t common;

  /**
   * Mean anomaly at reference time [rad]
   */
  double m0;

  /**
   * Eccentricity of satellite orbit
   */
  double ecc;

  /**
   * Square root of the semi-major axis of orbit [m^(1/2)]
   */
  double sqrta;

  /**
   * Longitude of ascending node of orbit plane at weekly epoch [rad]
   */
  double omega0;

  /**
   * Rate of right ascension [rad/s]
   */
  double omegadot;

  /**
   * Argument of perigee [rad]
   */
  double w;

  /**
   * Inclination [rad]
   */
  double inc;

  /**
   * Polynomial clock correction coefficient (clock bias) [s]
   */
  double af0;

  /**
   * Polynomial clock correction coefficient (clock drift) [s/s]
   */
  double af1;
} sbp_msg_almanac_gps_t;

/**
 * Get encoded size of an instance of sbp_msg_almanac_gps_t
 *
 * @param msg sbp_msg_almanac_gps_t instance
 * @return Length of on-wire representation
 */
static inline size_t sbp_msg_almanac_gps_encoded_len(
    const sbp_msg_almanac_gps_t *msg) {
  (void)msg;
  return SBP_MSG_ALMANAC_GPS_ENCODED_LEN;
}

/**
 * Encode an instance of sbp_msg_almanac_gps_t to wire representation
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
 * @param msg Instance of sbp_msg_almanac_gps_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
SBP_EXPORT s8 sbp_msg_almanac_gps_encode(uint8_t *buf, uint8_t len,
                                         uint8_t *n_written,
                                         const sbp_msg_almanac_gps_t *msg);

/**
 * Decode an instance of sbp_msg_almanac_gps_t from wire representation
 *
 * This function decodes the wire representation of a sbp_msg_almanac_gps_t
 * message to the given instance. The caller must specify the length of the
 * buffer in the \p len parameter. If non-null the number of bytes read from the
 * buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_msg_almanac_gps_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
SBP_EXPORT s8 sbp_msg_almanac_gps_decode(const uint8_t *buf, uint8_t len,
                                         uint8_t *n_read,
                                         sbp_msg_almanac_gps_t *msg);
/**
 * Send an instance of sbp_msg_almanac_gps_t with the given write function
 *
 * An equivalent of #sbp_message_send which operates specifically on
 * sbp_msg_almanac_gps_t
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
SBP_EXPORT s8 sbp_msg_almanac_gps_send(sbp_state_t *s, u16 sender_id,
                                       const sbp_msg_almanac_gps_t *msg,
                                       sbp_write_fn_t write);

/**
 * Compare two instances of sbp_msg_almanac_gps_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_almanac_gps_t instance
 * @param b sbp_msg_almanac_gps_t instance
 * @return 0, <0, >0
 */
SBP_EXPORT int sbp_msg_almanac_gps_cmp(const sbp_msg_almanac_gps_t *a,
                                       const sbp_msg_almanac_gps_t *b);

#ifdef __cplusplus
}

static inline bool operator==(const sbp_msg_almanac_gps_t &lhs,
                              const sbp_msg_almanac_gps_t &rhs) {
  return sbp_msg_almanac_gps_cmp(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_msg_almanac_gps_t &lhs,
                              const sbp_msg_almanac_gps_t &rhs) {
  return sbp_msg_almanac_gps_cmp(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_almanac_gps_t &lhs,
                             const sbp_msg_almanac_gps_t &rhs) {
  return sbp_msg_almanac_gps_cmp(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_msg_almanac_gps_t &lhs,
                              const sbp_msg_almanac_gps_t &rhs) {
  return sbp_msg_almanac_gps_cmp(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_almanac_gps_t &lhs,
                             const sbp_msg_almanac_gps_t &rhs) {
  return sbp_msg_almanac_gps_cmp(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_msg_almanac_gps_t &lhs,
                              const sbp_msg_almanac_gps_t &rhs) {
  return sbp_msg_almanac_gps_cmp(&lhs, &rhs) >= 0;
}

#endif  // ifdef __cplusplus

#endif /* LIBSBP_V4_OBSERVATION_MSG_ALMANAC_GPS_H */
