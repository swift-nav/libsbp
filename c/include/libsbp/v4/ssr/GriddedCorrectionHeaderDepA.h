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
 * Automatically generated from yaml/swiftnav/sbp/ssr.yaml
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

#ifndef LIBSBP_V4_SSR_GRIDDEDCORRECTIONHEADERDEPA_H
#define LIBSBP_V4_SSR_GRIDDEDCORRECTIONHEADERDEPA_H

#include <math.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>

#include <libsbp/common.h>
#include <libsbp/ssr_macros.h>
#include <libsbp/v4/gnss/GPSTimeSec.h>
#include <libsbp/v4/string/sbp_string.h>

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
 *
 * SBP_GRIDDEDCORRECTIONHEADERDEPA
 *
 *****************************************************************************/
/** Header for MSG_SSR_GRIDDED_CORRECTION_DEP
 *
 * The 3GPP message contains nested variable length arrays which are not
 * supported in SBP, so each grid point will be identified by the index.
 */
typedef struct {
  /**
   * GNSS reference time of the correction
   */
  sbp_gps_time_sec_t time;

  /**
   * Number of messages in the dataset
   */
  u16 num_msgs;

  /**
   * Position of this message in the dataset
   */
  u16 seq_num;

  /**
   * Update interval between consecutive corrections. Encoded following RTCM
   * DF391 specification.
   */
  u8 update_interval;

  /**
   * IOD of the SSR atmospheric correction
   */
  u8 iod_atmo;

  /**
   * Quality of the troposphere data. Encoded following RTCM DF389 specification
   * in units of m.
   */
  u8 tropo_quality_indicator;
} sbp_gridded_correction_header_dep_a_t;

/**
 * Get encoded size of an instance of sbp_gridded_correction_header_dep_a_t
 *
 * @param msg sbp_gridded_correction_header_dep_a_t instance
 * @return Length of on-wire representation
 */
static inline size_t sbp_gridded_correction_header_dep_a_encoded_len(
    const sbp_gridded_correction_header_dep_a_t *msg) {
  (void)msg;
  return SBP_GRIDDED_CORRECTION_HEADER_DEP_A_ENCODED_LEN;
}

/**
 * Encode an instance of sbp_gridded_correction_header_dep_a_t to wire
 * representation
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
 * @param msg Instance of sbp_gridded_correction_header_dep_a_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
SBP_EXPORT s8 sbp_gridded_correction_header_dep_a_encode(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_gridded_correction_header_dep_a_t *msg);

/**
 * Decode an instance of sbp_gridded_correction_header_dep_a_t from wire
 * representation
 *
 * This function decodes the wire representation of a
 * sbp_gridded_correction_header_dep_a_t message to the given instance. The
 * caller must specify the length of the buffer in the \p len parameter. If
 * non-null the number of bytes read from the buffer will be returned in \p
 * n_read.
 *
 * @param buf Wire representation of the sbp_gridded_correction_header_dep_a_t
 * instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
SBP_EXPORT s8 sbp_gridded_correction_header_dep_a_decode(
    const uint8_t *buf, uint8_t len, uint8_t *n_read,
    sbp_gridded_correction_header_dep_a_t *msg);

/**
 * Compare two instances of sbp_gridded_correction_header_dep_a_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_gridded_correction_header_dep_a_t instance
 * @param b sbp_gridded_correction_header_dep_a_t instance
 * @return 0, <0, >0
 */
SBP_EXPORT int sbp_gridded_correction_header_dep_a_cmp(
    const sbp_gridded_correction_header_dep_a_t *a,
    const sbp_gridded_correction_header_dep_a_t *b);

#ifdef __cplusplus
}

static inline bool operator==(
    const sbp_gridded_correction_header_dep_a_t &lhs,
    const sbp_gridded_correction_header_dep_a_t &rhs) {
  return sbp_gridded_correction_header_dep_a_cmp(&lhs, &rhs) == 0;
}

static inline bool operator!=(
    const sbp_gridded_correction_header_dep_a_t &lhs,
    const sbp_gridded_correction_header_dep_a_t &rhs) {
  return sbp_gridded_correction_header_dep_a_cmp(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_gridded_correction_header_dep_a_t &lhs,
                             const sbp_gridded_correction_header_dep_a_t &rhs) {
  return sbp_gridded_correction_header_dep_a_cmp(&lhs, &rhs) < 0;
}

static inline bool operator<=(
    const sbp_gridded_correction_header_dep_a_t &lhs,
    const sbp_gridded_correction_header_dep_a_t &rhs) {
  return sbp_gridded_correction_header_dep_a_cmp(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_gridded_correction_header_dep_a_t &lhs,
                             const sbp_gridded_correction_header_dep_a_t &rhs) {
  return sbp_gridded_correction_header_dep_a_cmp(&lhs, &rhs) > 0;
}

static inline bool operator>=(
    const sbp_gridded_correction_header_dep_a_t &lhs,
    const sbp_gridded_correction_header_dep_a_t &rhs) {
  return sbp_gridded_correction_header_dep_a_cmp(&lhs, &rhs) >= 0;
}

#endif  // ifdef __cplusplus

#endif /* LIBSBP_V4_SSR_GRIDDEDCORRECTIONHEADERDEPA_H */
