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

#ifndef LIBSBP_V4_SSR_TROPOSPHERICDELAYCORRECTIONNOSTD_H
#define LIBSBP_V4_SSR_TROPOSPHERICDELAYCORRECTIONNOSTD_H

#include <math.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>

#include <libsbp/common.h>
#include <libsbp/ssr_macros.h>
#include <libsbp/v4/string/sbp_string.h>

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
 *
 * SBP_TROPOSPHERICDELAYCORRECTIONNOSTD
 *
 *****************************************************************************/
/** None
 *
 * Troposphere vertical delays at the grid point.
 */
typedef struct {
  /**
   * Hydrostatic vertical delay [4 mm (add 2.3 m to get actual vertical hydro
   * delay)]
   */
  s16 hydro;

  /**
   * Wet vertical delay [4 mm (add 0.252 m to get actual vertical wet delay)]
   */
  s8 wet;
} sbp_tropospheric_delay_correction_no_std_t;

/**
 * Get encoded size of an instance of sbp_tropospheric_delay_correction_no_std_t
 *
 * @param msg sbp_tropospheric_delay_correction_no_std_t instance
 * @return Length of on-wire representation
 */
static inline size_t sbp_tropospheric_delay_correction_no_std_encoded_len(
    const sbp_tropospheric_delay_correction_no_std_t *msg) {
  (void)msg;
  return SBP_TROPOSPHERIC_DELAY_CORRECTION_NO_STD_ENCODED_LEN;
}

/**
 * Encode an instance of sbp_tropospheric_delay_correction_no_std_t to wire
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
 * @param msg Instance of sbp_tropospheric_delay_correction_no_std_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
SBP_EXPORT s8 sbp_tropospheric_delay_correction_no_std_encode(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_tropospheric_delay_correction_no_std_t *msg);

/**
 * Decode an instance of sbp_tropospheric_delay_correction_no_std_t from wire
 * representation
 *
 * This function decodes the wire representation of a
 * sbp_tropospheric_delay_correction_no_std_t message to the given instance. The
 * caller must specify the length of the buffer in the \p len parameter. If
 * non-null the number of bytes read from the buffer will be returned in \p
 * n_read.
 *
 * @param buf Wire representation of the
 * sbp_tropospheric_delay_correction_no_std_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
SBP_EXPORT s8 sbp_tropospheric_delay_correction_no_std_decode(
    const uint8_t *buf, uint8_t len, uint8_t *n_read,
    sbp_tropospheric_delay_correction_no_std_t *msg);

/**
 * Compare two instances of sbp_tropospheric_delay_correction_no_std_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_tropospheric_delay_correction_no_std_t instance
 * @param b sbp_tropospheric_delay_correction_no_std_t instance
 * @return 0, <0, >0
 */
SBP_EXPORT int sbp_tropospheric_delay_correction_no_std_cmp(
    const sbp_tropospheric_delay_correction_no_std_t *a,
    const sbp_tropospheric_delay_correction_no_std_t *b);

#ifdef __cplusplus
}

static inline bool operator==(
    const sbp_tropospheric_delay_correction_no_std_t &lhs,
    const sbp_tropospheric_delay_correction_no_std_t &rhs) {
  return sbp_tropospheric_delay_correction_no_std_cmp(&lhs, &rhs) == 0;
}

static inline bool operator!=(
    const sbp_tropospheric_delay_correction_no_std_t &lhs,
    const sbp_tropospheric_delay_correction_no_std_t &rhs) {
  return sbp_tropospheric_delay_correction_no_std_cmp(&lhs, &rhs) != 0;
}

static inline bool operator<(
    const sbp_tropospheric_delay_correction_no_std_t &lhs,
    const sbp_tropospheric_delay_correction_no_std_t &rhs) {
  return sbp_tropospheric_delay_correction_no_std_cmp(&lhs, &rhs) < 0;
}

static inline bool operator<=(
    const sbp_tropospheric_delay_correction_no_std_t &lhs,
    const sbp_tropospheric_delay_correction_no_std_t &rhs) {
  return sbp_tropospheric_delay_correction_no_std_cmp(&lhs, &rhs) <= 0;
}

static inline bool operator>(
    const sbp_tropospheric_delay_correction_no_std_t &lhs,
    const sbp_tropospheric_delay_correction_no_std_t &rhs) {
  return sbp_tropospheric_delay_correction_no_std_cmp(&lhs, &rhs) > 0;
}

static inline bool operator>=(
    const sbp_tropospheric_delay_correction_no_std_t &lhs,
    const sbp_tropospheric_delay_correction_no_std_t &rhs) {
  return sbp_tropospheric_delay_correction_no_std_cmp(&lhs, &rhs) >= 0;
}

#endif  // ifdef __cplusplus

#endif /* LIBSBP_V4_SSR_TROPOSPHERICDELAYCORRECTIONNOSTD_H */
