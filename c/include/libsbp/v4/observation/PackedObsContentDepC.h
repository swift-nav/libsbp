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

#ifndef LIBSBP_V4_OBSERVATION_PACKEDOBSCONTENTDEPC_H
#define LIBSBP_V4_OBSERVATION_PACKEDOBSCONTENTDEPC_H

#include <math.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>

#include <libsbp/common.h>
#include <libsbp/observation_macros.h>
#include <libsbp/v4/gnss/CarrierPhase.h>
#include <libsbp/v4/gnss/GnssSignalDep.h>
#include <libsbp/v4/string/sbp_string.h>

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
 *
 * SBP_PACKEDOBSCONTENTDEPC
 *
 *****************************************************************************/
/** GPS observations for a particular satellite signal
 *
 * Pseudorange and carrier phase observation for a satellite being tracked. The
 * observations are be interoperable with 3rd party receivers and conform with
 * typical RTCMv3 GNSS observations.
 */
typedef struct {
  /**
   * Pseudorange observation [2 cm]
   */
  u32 P;

  /**
   * Carrier phase observation with typical sign convention. [cycles]
   */
  sbp_carrier_phase_t L;

  /**
   * Carrier-to-Noise density [dB Hz / 4]
   */
  u8 cn0;

  /**
   * Lock indicator. This value changes whenever a satellite signal has lost and
   * regained lock, indicating that the carrier phase ambiguity may have
   * changed.
   */
  u16 lock;

  /**
   * GNSS signal identifier
   */
  sbp_gnss_signal_dep_t sid;
} sbp_packed_obs_content_dep_c_t;

/**
 * Get encoded size of an instance of sbp_packed_obs_content_dep_c_t
 *
 * @param msg sbp_packed_obs_content_dep_c_t instance
 * @return Length of on-wire representation
 */
static inline size_t sbp_packed_obs_content_dep_c_encoded_len(
    const sbp_packed_obs_content_dep_c_t *msg) {
  (void)msg;
  return SBP_PACKED_OBS_CONTENT_DEP_C_ENCODED_LEN;
}

/**
 * Encode an instance of sbp_packed_obs_content_dep_c_t to wire representation
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
 * @param msg Instance of sbp_packed_obs_content_dep_c_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
SBP_EXPORT s8 sbp_packed_obs_content_dep_c_encode(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_packed_obs_content_dep_c_t *msg);

/**
 * Decode an instance of sbp_packed_obs_content_dep_c_t from wire representation
 *
 * This function decodes the wire representation of a
 * sbp_packed_obs_content_dep_c_t message to the given instance. The caller must
 * specify the length of the buffer in the \p len parameter. If non-null the
 * number of bytes read from the buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_packed_obs_content_dep_c_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
SBP_EXPORT s8 sbp_packed_obs_content_dep_c_decode(
    const uint8_t *buf, uint8_t len, uint8_t *n_read,
    sbp_packed_obs_content_dep_c_t *msg);

/**
 * Compare two instances of sbp_packed_obs_content_dep_c_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_packed_obs_content_dep_c_t instance
 * @param b sbp_packed_obs_content_dep_c_t instance
 * @return 0, <0, >0
 */
SBP_EXPORT int sbp_packed_obs_content_dep_c_cmp(
    const sbp_packed_obs_content_dep_c_t *a,
    const sbp_packed_obs_content_dep_c_t *b);

#ifdef __cplusplus
}

static inline bool operator==(const sbp_packed_obs_content_dep_c_t &lhs,
                              const sbp_packed_obs_content_dep_c_t &rhs) {
  return sbp_packed_obs_content_dep_c_cmp(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_packed_obs_content_dep_c_t &lhs,
                              const sbp_packed_obs_content_dep_c_t &rhs) {
  return sbp_packed_obs_content_dep_c_cmp(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_packed_obs_content_dep_c_t &lhs,
                             const sbp_packed_obs_content_dep_c_t &rhs) {
  return sbp_packed_obs_content_dep_c_cmp(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_packed_obs_content_dep_c_t &lhs,
                              const sbp_packed_obs_content_dep_c_t &rhs) {
  return sbp_packed_obs_content_dep_c_cmp(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_packed_obs_content_dep_c_t &lhs,
                             const sbp_packed_obs_content_dep_c_t &rhs) {
  return sbp_packed_obs_content_dep_c_cmp(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_packed_obs_content_dep_c_t &lhs,
                              const sbp_packed_obs_content_dep_c_t &rhs) {
  return sbp_packed_obs_content_dep_c_cmp(&lhs, &rhs) >= 0;
}

#endif  // ifdef __cplusplus

#endif /* LIBSBP_V4_OBSERVATION_PACKEDOBSCONTENTDEPC_H */
