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

#ifndef LIBSBP_OBSERVATION_MSG_EPHEMERIS_BDS_CNAV_H
#define LIBSBP_OBSERVATION_MSG_EPHEMERIS_BDS_CNAV_H

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
 * SBP_MSG_EPHEMERIS_BDS_CNAV
 *
 *****************************************************************************/
/** Satellite broadcast ephemeris for BDS from the B-CNAV1 or B-CNAV2 message
 *
 * The ephemeris message returns one BeiDou-3 civil navigation data set, either
 * from the B-CNAV1 message of the B1C signal (subframe 2 with the health and
 * integrity fields of subframe 3, BDS-SIS-ICD-B1C-1.0) or from the B-CNAV2
 * message of the B2a signal (message types 10, 11 and 30, BDS-SIS-ICD-B2a-1.0).
 * MSG_EPHEMERIS_BDS cannot carry it losslessly: it has no semi-major axis rate
 * or mean motion rate and holds the D1/D2 group delays TGD1 and TGD2 instead of
 * the B1C and B2a terms. The satellite position follows from the user algorithm
 * of Table 7-9 of either ICD, the clock correction from section 7.5.2 and the
 * group delay corrections from section 7.6.2. Times are GPS time (BDT plus 14
 * s). The common health_bits hold the satellite health status HS (0 healthy, 1
 * unhealthy or in test, section 7.14). The common ura is -1: the ICDs do not
 * yet define the signal in space accuracy values (section 7.16).
 */
typedef struct {
  /**
   * Values common for all ephemeris types
   */
  sbp_ephemeris_common_content_t common;

  /**
   * Issue of data, ephemeris (section 7.4.1)
   */
  u8 iode;

  /**
   * Issue of data, clock (section 7.4.2). Its 8 LSBs equal iode
   * (section 7.4.3).
   */
  u16 iodc;

  /**
   * Signal in space monitoring accuracy index (section 7.17)
   */
  u8 sismai;

  /**
   * Source and status flags of the data set
   */
  u8 flags;

  /**
   * Semi-major axis at reference time (A_ref of the orbit type plus delta A)
   * [m]
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
   * Rate of right ascension [rad/s]
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
   * Group delay differential between the B1C pilot component and B3I [s]
   */
  float tgd_b1cp;

  /**
   * Group delay differential between the B2a pilot component and B3I [s]
   */
  float tgd_b2ap;

  /**
   * Group delay differential between the B1C data and pilot components.
   * Broadcast in B-CNAV1 only, 0 in B-CNAV2 data sets. [s]
   */
  float isc_b1cd;

  /**
   * Group delay differential between the B2a data and pilot components.
   * Broadcast in B-CNAV2 only, 0 in B-CNAV1 data sets. [s]
   */
  float isc_b2ad;
} sbp_msg_ephemeris_bds_cnav_t;

/**
 * Get encoded size of an instance of sbp_msg_ephemeris_bds_cnav_t
 *
 * @param msg sbp_msg_ephemeris_bds_cnav_t instance
 * @return Length of on-wire representation
 */
static inline size_t sbp_msg_ephemeris_bds_cnav_encoded_len(
    const sbp_msg_ephemeris_bds_cnav_t *msg) {
  (void)msg;
  return SBP_MSG_EPHEMERIS_BDS_CNAV_ENCODED_LEN;
}

/**
 * Encode an instance of sbp_msg_ephemeris_bds_cnav_t to wire representation
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
 * @param msg Instance of sbp_msg_ephemeris_bds_cnav_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
SBP_EXPORT s8
sbp_msg_ephemeris_bds_cnav_encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                                  const sbp_msg_ephemeris_bds_cnav_t *msg);

/**
 * Decode an instance of sbp_msg_ephemeris_bds_cnav_t from wire representation
 *
 * This function decodes the wire representation of a
 * sbp_msg_ephemeris_bds_cnav_t message to the given instance. The caller must
 * specify the length of the buffer in the \p len parameter. If non-null the
 * number of bytes read from the buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_msg_ephemeris_bds_cnav_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
SBP_EXPORT s8 sbp_msg_ephemeris_bds_cnav_decode(
    const uint8_t *buf, uint8_t len, uint8_t *n_read,
    sbp_msg_ephemeris_bds_cnav_t *msg);
/**
 * Send an instance of sbp_msg_ephemeris_bds_cnav_t with the given write
 * function
 *
 * An equivalent of #sbp_message_send which operates specifically on
 * sbp_msg_ephemeris_bds_cnav_t
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
SBP_EXPORT s8 sbp_msg_ephemeris_bds_cnav_send(
    sbp_state_t *s, u16 sender_id, const sbp_msg_ephemeris_bds_cnav_t *msg,
    sbp_write_fn_t write);

/**
 * Compare two instances of sbp_msg_ephemeris_bds_cnav_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_ephemeris_bds_cnav_t instance
 * @param b sbp_msg_ephemeris_bds_cnav_t instance
 * @return 0, <0, >0
 */
SBP_EXPORT int sbp_msg_ephemeris_bds_cnav_cmp(
    const sbp_msg_ephemeris_bds_cnav_t *a,
    const sbp_msg_ephemeris_bds_cnav_t *b);

#ifdef __cplusplus
}

static inline bool operator==(const sbp_msg_ephemeris_bds_cnav_t &lhs,
                              const sbp_msg_ephemeris_bds_cnav_t &rhs) {
  return sbp_msg_ephemeris_bds_cnav_cmp(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_msg_ephemeris_bds_cnav_t &lhs,
                              const sbp_msg_ephemeris_bds_cnav_t &rhs) {
  return sbp_msg_ephemeris_bds_cnav_cmp(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_ephemeris_bds_cnav_t &lhs,
                             const sbp_msg_ephemeris_bds_cnav_t &rhs) {
  return sbp_msg_ephemeris_bds_cnav_cmp(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_msg_ephemeris_bds_cnav_t &lhs,
                              const sbp_msg_ephemeris_bds_cnav_t &rhs) {
  return sbp_msg_ephemeris_bds_cnav_cmp(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_ephemeris_bds_cnav_t &lhs,
                             const sbp_msg_ephemeris_bds_cnav_t &rhs) {
  return sbp_msg_ephemeris_bds_cnav_cmp(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_msg_ephemeris_bds_cnav_t &lhs,
                              const sbp_msg_ephemeris_bds_cnav_t &rhs) {
  return sbp_msg_ephemeris_bds_cnav_cmp(&lhs, &rhs) >= 0;
}

#endif  // ifdef __cplusplus

#endif /* LIBSBP_OBSERVATION_MSG_EPHEMERIS_BDS_CNAV_H */
