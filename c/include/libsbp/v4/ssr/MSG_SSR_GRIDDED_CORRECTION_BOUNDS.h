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

#ifndef LIBSBP_V4_SSR_MSG_SSR_GRIDDED_CORRECTION_BOUNDS_H
#define LIBSBP_V4_SSR_MSG_SSR_GRIDDED_CORRECTION_BOUNDS_H

#include <math.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>

#include <libsbp/common.h>
#include <libsbp/ssr_macros.h>
#include <libsbp/v4/ssr/BoundsHeader.h>
#include <libsbp/v4/ssr/STECSatElementIntegrity.h>
#include <libsbp/v4/ssr/TroposphericDelayCorrection.h>
#include <libsbp/v4/string/sbp_string.h>

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
 *
 * SBP_MSG_SSR_GRIDDED_CORRECTION_BOUNDS
 *
 *****************************************************************************/
/** Gridded troposhere and STEC correction residuals bounds
 *
 * Note 1: Range: 0-17.5 m. i<= 200, mean = 0.01i; 200<i<=230,
 * mean=2+0.1(i-200); i>230, mean=5+0.5(i-230).
 */
typedef struct {
  /**
   * Header of a bounds message.
   */
  sbp_bounds_header_t header;

  /**
   * IOD of the correction.
   */
  u8 ssr_iod_atmo;

  /**
   * Set this tile belongs to.
   */
  u16 tile_set_id;

  /**
   * Unique identifier of this tile in the tile set.
   */
  u16 tile_id;

  /**
   * Tropo Quality Indicator. Similar to RTCM DF389.
   */
  u8 tropo_qi;

  /**
   * Index of the Grid Point.
   */
  u16 grid_point_id;

  /**
   * Tropospheric delay at grid point.
   */
  sbp_tropospheric_delay_correction_t tropo_delay_correction;

  /**
   * Vertical Hydrostatic Error Bound Mean. [0.005 m]
   */
  u8 tropo_v_hydro_bound_mu;

  /**
   * Vertical Hydrostatic Error Bound StDev. [0.005 m]
   */
  u8 tropo_v_hydro_bound_sig;

  /**
   * Vertical Wet Error Bound Mean. [0.005 m]
   */
  u8 tropo_v_wet_bound_mu;

  /**
   * Vertical Wet Error Bound StDev. [0.005 m]
   */
  u8 tropo_v_wet_bound_sig;

  /**
   * Number of satellites.
   */
  u8 n_sats;

  /**
   * Array of STEC polynomial coefficients and its bounds for each space
   * vehicle.
   */
  sbp_stec_sat_element_integrity_t
      stec_sat_list[SBP_MSG_SSR_GRIDDED_CORRECTION_BOUNDS_STEC_SAT_LIST_MAX];
} sbp_msg_ssr_gridded_correction_bounds_t;

/**
 * Get encoded size of an instance of sbp_msg_ssr_gridded_correction_bounds_t
 *
 * @param msg sbp_msg_ssr_gridded_correction_bounds_t instance
 * @return Length of on-wire representation
 */
static inline size_t sbp_msg_ssr_gridded_correction_bounds_encoded_len(
    const sbp_msg_ssr_gridded_correction_bounds_t *msg) {
  return SBP_MSG_SSR_GRIDDED_CORRECTION_BOUNDS_ENCODED_OVERHEAD +
         (msg->n_sats * SBP_STEC_SAT_ELEMENT_INTEGRITY_ENCODED_LEN);
}

/**
 * Encode an instance of sbp_msg_ssr_gridded_correction_bounds_t to wire
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
 * @param msg Instance of sbp_msg_ssr_gridded_correction_bounds_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
SBP_EXPORT s8 sbp_msg_ssr_gridded_correction_bounds_encode(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_msg_ssr_gridded_correction_bounds_t *msg);

/**
 * Decode an instance of sbp_msg_ssr_gridded_correction_bounds_t from wire
 * representation
 *
 * This function decodes the wire representation of a
 * sbp_msg_ssr_gridded_correction_bounds_t message to the given instance. The
 * caller must specify the length of the buffer in the \p len parameter. If
 * non-null the number of bytes read from the buffer will be returned in \p
 * n_read.
 *
 * @param buf Wire representation of the sbp_msg_ssr_gridded_correction_bounds_t
 * instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
SBP_EXPORT s8 sbp_msg_ssr_gridded_correction_bounds_decode(
    const uint8_t *buf, uint8_t len, uint8_t *n_read,
    sbp_msg_ssr_gridded_correction_bounds_t *msg);
/**
 * Send an instance of sbp_msg_ssr_gridded_correction_bounds_t with the given
 * write function
 *
 * An equivalent of #sbp_message_send which operates specifically on
 * sbp_msg_ssr_gridded_correction_bounds_t
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
SBP_EXPORT s8 sbp_msg_ssr_gridded_correction_bounds_send(
    sbp_state_t *s, u16 sender_id,
    const sbp_msg_ssr_gridded_correction_bounds_t *msg, sbp_write_fn_t write);

/**
 * Compare two instances of sbp_msg_ssr_gridded_correction_bounds_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_ssr_gridded_correction_bounds_t instance
 * @param b sbp_msg_ssr_gridded_correction_bounds_t instance
 * @return 0, <0, >0
 */
SBP_EXPORT int sbp_msg_ssr_gridded_correction_bounds_cmp(
    const sbp_msg_ssr_gridded_correction_bounds_t *a,
    const sbp_msg_ssr_gridded_correction_bounds_t *b);

#ifdef __cplusplus
}

static inline bool operator==(
    const sbp_msg_ssr_gridded_correction_bounds_t &lhs,
    const sbp_msg_ssr_gridded_correction_bounds_t &rhs) {
  return sbp_msg_ssr_gridded_correction_bounds_cmp(&lhs, &rhs) == 0;
}

static inline bool operator!=(
    const sbp_msg_ssr_gridded_correction_bounds_t &lhs,
    const sbp_msg_ssr_gridded_correction_bounds_t &rhs) {
  return sbp_msg_ssr_gridded_correction_bounds_cmp(&lhs, &rhs) != 0;
}

static inline bool operator<(
    const sbp_msg_ssr_gridded_correction_bounds_t &lhs,
    const sbp_msg_ssr_gridded_correction_bounds_t &rhs) {
  return sbp_msg_ssr_gridded_correction_bounds_cmp(&lhs, &rhs) < 0;
}

static inline bool operator<=(
    const sbp_msg_ssr_gridded_correction_bounds_t &lhs,
    const sbp_msg_ssr_gridded_correction_bounds_t &rhs) {
  return sbp_msg_ssr_gridded_correction_bounds_cmp(&lhs, &rhs) <= 0;
}

static inline bool operator>(
    const sbp_msg_ssr_gridded_correction_bounds_t &lhs,
    const sbp_msg_ssr_gridded_correction_bounds_t &rhs) {
  return sbp_msg_ssr_gridded_correction_bounds_cmp(&lhs, &rhs) > 0;
}

static inline bool operator>=(
    const sbp_msg_ssr_gridded_correction_bounds_t &lhs,
    const sbp_msg_ssr_gridded_correction_bounds_t &rhs) {
  return sbp_msg_ssr_gridded_correction_bounds_cmp(&lhs, &rhs) >= 0;
}

#endif  // ifdef __cplusplus

#endif /* LIBSBP_V4_SSR_MSG_SSR_GRIDDED_CORRECTION_BOUNDS_H */
