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
 * Automatically generated from yaml/swiftnav/sbp/telemetry.yaml
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

#ifndef LIBSBP_TELEMETRY_TELEMETRYSV_H
#define LIBSBP_TELEMETRY_TELEMETRYSV_H

#include <math.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>

#include <libsbp/common.h>
#include <libsbp/gnss/GnssSignal.h>
#include <libsbp/string/sbp_string.h>
#include <libsbp/telemetry_macros.h>

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
 *
 * SBP_TELEMETRYSV
 *
 *****************************************************************************/
typedef struct {
  /**
   * Azimuth angle (range 0..179) [deg * 2]
   */
  u8 az;

  /**
   * Elevation angle (range -90..90) [deg]
   */
  s8 el;

  /**
   * Observation availability at filter update
   */
  u8 availability_flags;

  /**
   * Pseudorange observation residual [1 dm]
   */
  s16 pseudorange_residual;

  /**
   * Carrier-phase or carrier-phase-derived observation residual [5 mm]
   */
  s16 phase_residual;

  /**
   * Reports if observation is marked as an outlier and is excluded from the
   * update
   */
  u8 outlier_flags;

  /**
   * Ephemeris metadata
   */
  u8 ephemeris_flags;

  /**
   * Reserved
   */
  u8 correction_flags;

  /**
   * GNSS signal identifier (16 bit)
   */
  sbp_gnss_signal_t sid;
} sbp_telemetry_sv_t;

/**
 * Get encoded size of an instance of sbp_telemetry_sv_t
 *
 * @param msg sbp_telemetry_sv_t instance
 * @return Length of on-wire representation
 */
static inline size_t sbp_telemetry_sv_encoded_len(
    const sbp_telemetry_sv_t *msg) {
  (void)msg;
  return SBP_TELEMETRY_SV_ENCODED_LEN;
}

/**
 * Encode an instance of sbp_telemetry_sv_t to wire representation
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
 * @param msg Instance of sbp_telemetry_sv_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
SBP_EXPORT s8 sbp_telemetry_sv_encode(uint8_t *buf, uint8_t len,
                                      uint8_t *n_written,
                                      const sbp_telemetry_sv_t *msg);

/**
 * Decode an instance of sbp_telemetry_sv_t from wire representation
 *
 * This function decodes the wire representation of a sbp_telemetry_sv_t message
 * to the given instance. The caller must specify the length of the buffer in
 * the \p len parameter. If non-null the number of bytes read from the buffer
 * will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_telemetry_sv_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
SBP_EXPORT s8 sbp_telemetry_sv_decode(const uint8_t *buf, uint8_t len,
                                      uint8_t *n_read, sbp_telemetry_sv_t *msg);

/**
 * Compare two instances of sbp_telemetry_sv_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_telemetry_sv_t instance
 * @param b sbp_telemetry_sv_t instance
 * @return 0, <0, >0
 */
SBP_EXPORT int sbp_telemetry_sv_cmp(const sbp_telemetry_sv_t *a,
                                    const sbp_telemetry_sv_t *b);

#ifdef __cplusplus
}

static inline bool operator==(const sbp_telemetry_sv_t &lhs,
                              const sbp_telemetry_sv_t &rhs) {
  return sbp_telemetry_sv_cmp(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_telemetry_sv_t &lhs,
                              const sbp_telemetry_sv_t &rhs) {
  return sbp_telemetry_sv_cmp(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_telemetry_sv_t &lhs,
                             const sbp_telemetry_sv_t &rhs) {
  return sbp_telemetry_sv_cmp(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_telemetry_sv_t &lhs,
                              const sbp_telemetry_sv_t &rhs) {
  return sbp_telemetry_sv_cmp(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_telemetry_sv_t &lhs,
                             const sbp_telemetry_sv_t &rhs) {
  return sbp_telemetry_sv_cmp(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_telemetry_sv_t &lhs,
                              const sbp_telemetry_sv_t &rhs) {
  return sbp_telemetry_sv_cmp(&lhs, &rhs) >= 0;
}

#endif  // ifdef __cplusplus

#endif /* LIBSBP_TELEMETRY_TELEMETRYSV_H */
