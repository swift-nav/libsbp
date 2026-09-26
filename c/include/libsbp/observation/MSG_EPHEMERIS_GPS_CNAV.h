/*
 * Copyright (C) 2015-2021 Swift Navigation Inc.
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
 * Automatically generated from yaml/swiftnav/sbp/observation.yaml
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

#ifndef LIBSBP_OBSERVATION_MSG_EPHEMERIS_GPS_CNAV_H
#define LIBSBP_OBSERVATION_MSG_EPHEMERIS_GPS_CNAV_H

#include <math.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>

#include <libsbp/common.h>
#include <libsbp/gnss/GPSTimeSec.h>
#include <libsbp/observation/EphemerisCommonContent.h>
#include <libsbp/observation_macros.h>
#include <libsbp/string/sbp_string.h>

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
 *
 * SBP_MSG_EPHEMERIS_GPS_CNAV
 *
 *****************************************************************************/
/** Satellite broadcast ephemeris for GPS from the CNAV message
 *
 * The ephemeris message returns one GPS civil navigation (CNAV) data set: the
 * orbit parameters of message types 10 and 11, the clock correction and group
 * delay parameters of message type 30. The satellite position follows from the
 * user algorithm of IS-GPS-200N Table 30-II, the clock correction from
 * paragraph 20.3.3.3.3.1 and the group delay corrections from
 * paragraph 30.3.3.3.1.1. The common toe equals the toc of the data set. The
 * common ura is the root sum square of the nominal URA_ED and URA_NED0 values,
 * or -1 when either index signals that no accuracy prediction is available. The
 * common health_bits hold the L1, L2 and L5 signal health bits of message type
 * 10 (bit 2 L1, bit 1 L2, bit 0 L5; 1 means all codes and data on that carrier
 * are bad or unavailable).
 */
typedef struct {
  /**
   * Values common for all ephemeris types
   */
  sbp_ephemeris_common_content_t common;

  /**
   * CEI data sequence propagation time
   */
  sbp_gps_time_sec_t top;

  /**
   * Elevation-dependent accuracy index, IS-GPS-200N 30.3.3.1.1.4
   */
  s8 ura_ed_index;

  /**
   * Non-elevation-dependent accuracy index, IS-GPS-200N 30.3.3.2.4
   */
  s8 ura_ned0_index;

  /**
   * Non-elevation-dependent accuracy change index
   */
  u8 ura_ned1_index;

  /**
   * Non-elevation-dependent accuracy change rate index
   */
  u8 ura_ned2_index;

  /**
   * Status flags of the data set
   */
  u8 flags;

  /**
   * Semi-major axis at reference time (A_REF plus delta A) [m]
   */
  double a;

  /**
   * Change rate in semi-major axis [m/s]
   */
  double a_dot;

  /**
   * Mean motion difference from computed value at reference time [rad/s]
   */
  double dn;

  /**
   * Rate of mean motion difference from computed value [rad/s^2]
   */
  double dn_dot;

  /**
   * Mean anomaly at reference time [rad]
   */
  double m0;

  /**
   * Eccentricity of satellite orbit
   */
  double ecc;

  /**
   * Argument of perigee [rad]
   */
  double w;

  /**
   * Longitude of ascending node of orbit plane at weekly epoch [rad]
   */
  double omega0;

  /**
   * Rate of right ascension (OMEGA_DOT_REF plus delta OMEGA_DOT) [rad/s]
   */
  double omegadot;

  /**
   * Inclination angle at reference time [rad]
   */
  double inc;

  /**
   * Rate of inclination angle [rad/s]
   */
  double inc_dot;

  /**
   * Amplitude of the sine harmonic correction term to the orbit radius [m]
   */
  float c_rs;

  /**
   * Amplitude of the cosine harmonic correction term to the orbit radius [m]
   */
  float c_rc;

  /**
   * Amplitude of the cosine harmonic correction term to the argument of
   * latitude [rad]
   */
  float c_uc;

  /**
   * Amplitude of the sine harmonic correction term to the argument of latitude
   * [rad]
   */
  float c_us;

  /**
   * Amplitude of the cosine harmonic correction term to the angle of
   * inclination [rad]
   */
  float c_ic;

  /**
   * Amplitude of the sine harmonic correction term to the angle of inclination
   * [rad]
   */
  float c_is;

  /**
   * Polynomial clock correction coefficient (clock bias) [s]
   */
  double af0;

  /**
   * Polynomial clock correction coefficient (clock drift) [s/s]
   */
  float af1;

  /**
   * Polynomial clock correction coefficient (rate of clock drift) [s/s^2]
   */
  float af2;

  /**
   * Clock reference
   */
  sbp_gps_time_sec_t toc;

  /**
   * Group delay differential between L1 P(Y) and L2 P(Y) [s]
   */
  float tgd;

  /**
   * Inter-signal correction between L1 P(Y) and L1 C/A [s]
   */
  float isc_l1ca;

  /**
   * Inter-signal correction between L1 P(Y) and L2C [s]
   */
  float isc_l2c;

  /**
   * Inter-signal correction between L1 P(Y) and L5 I5 [s]
   */
  float isc_l5i5;

  /**
   * Inter-signal correction between L1 P(Y) and L5 Q5 [s]
   */
  float isc_l5q5;
} sbp_msg_ephemeris_gps_cnav_t;

/**
 * Get encoded size of an instance of sbp_msg_ephemeris_gps_cnav_t
 *
 * @param msg sbp_msg_ephemeris_gps_cnav_t instance
 * @return Length of on-wire representation
 */
static inline size_t sbp_msg_ephemeris_gps_cnav_encoded_len(
    const sbp_msg_ephemeris_gps_cnav_t *msg) {
  (void)msg;
  return SBP_MSG_EPHEMERIS_GPS_CNAV_ENCODED_LEN;
}

/**
 * Encode an instance of sbp_msg_ephemeris_gps_cnav_t to wire representation
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
 * @param msg Instance of sbp_msg_ephemeris_gps_cnav_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
SBP_EXPORT s8
sbp_msg_ephemeris_gps_cnav_encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                                  const sbp_msg_ephemeris_gps_cnav_t *msg);

/**
 * Decode an instance of sbp_msg_ephemeris_gps_cnav_t from wire representation
 *
 * This function decodes the wire representation of a
 * sbp_msg_ephemeris_gps_cnav_t message to the given instance. The caller must
 * specify the length of the buffer in the \p len parameter. If non-null the
 * number of bytes read from the buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_msg_ephemeris_gps_cnav_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
SBP_EXPORT s8 sbp_msg_ephemeris_gps_cnav_decode(
    const uint8_t *buf, uint8_t len, uint8_t *n_read,
    sbp_msg_ephemeris_gps_cnav_t *msg);
/**
 * Send an instance of sbp_msg_ephemeris_gps_cnav_t with the given write
 * function
 *
 * An equivalent of #sbp_message_send which operates specifically on
 * sbp_msg_ephemeris_gps_cnav_t
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
SBP_EXPORT s8 sbp_msg_ephemeris_gps_cnav_send(
    sbp_state_t *s, u16 sender_id, const sbp_msg_ephemeris_gps_cnav_t *msg,
    sbp_write_fn_t write);

/**
 * Compare two instances of sbp_msg_ephemeris_gps_cnav_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_ephemeris_gps_cnav_t instance
 * @param b sbp_msg_ephemeris_gps_cnav_t instance
 * @return 0, <0, >0
 */
SBP_EXPORT int sbp_msg_ephemeris_gps_cnav_cmp(
    const sbp_msg_ephemeris_gps_cnav_t *a,
    const sbp_msg_ephemeris_gps_cnav_t *b);

#ifdef __cplusplus
}

static inline bool operator==(const sbp_msg_ephemeris_gps_cnav_t &lhs,
                              const sbp_msg_ephemeris_gps_cnav_t &rhs) {
  return sbp_msg_ephemeris_gps_cnav_cmp(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_msg_ephemeris_gps_cnav_t &lhs,
                              const sbp_msg_ephemeris_gps_cnav_t &rhs) {
  return sbp_msg_ephemeris_gps_cnav_cmp(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_ephemeris_gps_cnav_t &lhs,
                             const sbp_msg_ephemeris_gps_cnav_t &rhs) {
  return sbp_msg_ephemeris_gps_cnav_cmp(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_msg_ephemeris_gps_cnav_t &lhs,
                              const sbp_msg_ephemeris_gps_cnav_t &rhs) {
  return sbp_msg_ephemeris_gps_cnav_cmp(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_ephemeris_gps_cnav_t &lhs,
                             const sbp_msg_ephemeris_gps_cnav_t &rhs) {
  return sbp_msg_ephemeris_gps_cnav_cmp(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_msg_ephemeris_gps_cnav_t &lhs,
                              const sbp_msg_ephemeris_gps_cnav_t &rhs) {
  return sbp_msg_ephemeris_gps_cnav_cmp(&lhs, &rhs) >= 0;
}

#endif  // ifdef __cplusplus

#endif /* LIBSBP_OBSERVATION_MSG_EPHEMERIS_GPS_CNAV_H */
