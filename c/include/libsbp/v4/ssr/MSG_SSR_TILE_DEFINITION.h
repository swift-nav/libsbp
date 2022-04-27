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

#ifndef LIBSBP_V4_SSR_MSG_SSR_TILE_DEFINITION_H
#define LIBSBP_V4_SSR_MSG_SSR_TILE_DEFINITION_H

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
 * SBP_MSG_SSR_TILE_DEFINITION
 *
 *****************************************************************************/
/** Definition of a SSR atmospheric correction tile.

 *
 * Provides the correction point coordinates for the atmospheric correction
 values in the MSG_SSR_STEC_CORRECTION and MSG_SSR_GRIDDED_CORRECTION messages.
 *
 */
typedef struct {
  /**
   * Unique identifier of the tile set this tile belongs to.
   */
  u16 tile_set_id;

  /**
   * Unique identifier of this tile in the tile set.
   * See GNSS-SSR-ArrayOfCorrectionPoints field correctionPointSetID.
   */
  u16 tile_id;

  /**
   * North-West corner correction point latitude.
   *
   * The relation between the latitude X in the range [-90, 90] and the coded
   * number N is:
   *
   * N = floor((X / 90) * 2^14)
   *
   * See GNSS-SSR-ArrayOfCorrectionPoints field referencePointLatitude. [encoded
   * degrees]
   */
  s16 corner_nw_lat;

  /**
   * North-West corner correction point longitude.
   *
   * The relation between the longitude X in the range [-180, 180] and the coded
   * number N is:
   *
   * N = floor((X / 180) * 2^15)
   *
   * See GNSS-SSR-ArrayOfCorrectionPoints field referencePointLongitude.
   * [encoded degrees]
   */
  s16 corner_nw_lon;

  /**
   * Spacing of the correction points in the latitude direction.
   *
   * See GNSS-SSR-ArrayOfCorrectionPoints field stepOfLatitude. [0.01 degrees]
   */
  u16 spacing_lat;

  /**
   * Spacing of the correction points in the longitude direction.
   *
   * See GNSS-SSR-ArrayOfCorrectionPoints field stepOfLongitude. [0.01 degrees]
   */
  u16 spacing_lon;

  /**
   * Number of steps in the latitude direction.
   *
   * See GNSS-SSR-ArrayOfCorrectionPoints field numberOfStepsLatitude.
   */
  u16 rows;

  /**
   * Number of steps in the longitude direction.
   *
   * See GNSS-SSR-ArrayOfCorrectionPoints field numberOfStepsLongitude.
   */
  u16 cols;

  /**
   * Specifies the availability of correction data at the correction points in
   * the array.
   *
   * If a specific bit is enabled (set to 1), the correction is not available.
   * Only the first rows * cols bits are used, the remainder are set to 0. If
   * there are more then 64 correction points the remaining corrections are
   * always available.
   *
   * Starting with the northwest corner of the array (top left on a north
   * oriented map) the correction points are enumerated with row precedence -
   * first row west to east, second row west to east, until last row west to
   * east - ending with the southeast corner of the array.
   *
   * See GNSS-SSR-ArrayOfCorrectionPoints field bitmaskOfGrids but note the
   * definition of the bits is inverted.
   */
  u64 bitmask;
} sbp_msg_ssr_tile_definition_t;

/**
 * Get encoded size of an instance of sbp_msg_ssr_tile_definition_t
 *
 * @param msg sbp_msg_ssr_tile_definition_t instance
 * @return Length of on-wire representation
 */
static inline size_t sbp_msg_ssr_tile_definition_encoded_len(
    const sbp_msg_ssr_tile_definition_t *msg) {
  (void)msg;
  return SBP_MSG_SSR_TILE_DEFINITION_ENCODED_LEN;
}

/**
 * Encode an instance of sbp_msg_ssr_tile_definition_t to wire representation
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
 * @param msg Instance of sbp_msg_ssr_tile_definition_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
SBP_EXPORT s8 sbp_msg_ssr_tile_definition_encode(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_msg_ssr_tile_definition_t *msg);

/**
 * Decode an instance of sbp_msg_ssr_tile_definition_t from wire representation
 *
 * This function decodes the wire representation of a
 * sbp_msg_ssr_tile_definition_t message to the given instance. The caller must
 * specify the length of the buffer in the \p len parameter. If non-null the
 * number of bytes read from the buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_msg_ssr_tile_definition_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
SBP_EXPORT s8 sbp_msg_ssr_tile_definition_decode(
    const uint8_t *buf, uint8_t len, uint8_t *n_read,
    sbp_msg_ssr_tile_definition_t *msg);
/**
 * Send an instance of sbp_msg_ssr_tile_definition_t with the given write
 * function
 *
 * An equivalent of #sbp_message_send which operates specifically on
 * sbp_msg_ssr_tile_definition_t
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
SBP_EXPORT s8 sbp_msg_ssr_tile_definition_send(
    sbp_state_t *s, u16 sender_id, const sbp_msg_ssr_tile_definition_t *msg,
    sbp_write_fn_t write);

/**
 * Compare two instances of sbp_msg_ssr_tile_definition_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_ssr_tile_definition_t instance
 * @param b sbp_msg_ssr_tile_definition_t instance
 * @return 0, <0, >0
 */
SBP_EXPORT int sbp_msg_ssr_tile_definition_cmp(
    const sbp_msg_ssr_tile_definition_t *a,
    const sbp_msg_ssr_tile_definition_t *b);

#ifdef __cplusplus
}

static inline bool operator==(const sbp_msg_ssr_tile_definition_t &lhs,
                              const sbp_msg_ssr_tile_definition_t &rhs) {
  return sbp_msg_ssr_tile_definition_cmp(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_msg_ssr_tile_definition_t &lhs,
                              const sbp_msg_ssr_tile_definition_t &rhs) {
  return sbp_msg_ssr_tile_definition_cmp(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_ssr_tile_definition_t &lhs,
                             const sbp_msg_ssr_tile_definition_t &rhs) {
  return sbp_msg_ssr_tile_definition_cmp(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_msg_ssr_tile_definition_t &lhs,
                              const sbp_msg_ssr_tile_definition_t &rhs) {
  return sbp_msg_ssr_tile_definition_cmp(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_ssr_tile_definition_t &lhs,
                             const sbp_msg_ssr_tile_definition_t &rhs) {
  return sbp_msg_ssr_tile_definition_cmp(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_msg_ssr_tile_definition_t &lhs,
                              const sbp_msg_ssr_tile_definition_t &rhs) {
  return sbp_msg_ssr_tile_definition_cmp(&lhs, &rhs) >= 0;
}

#endif  // ifdef __cplusplus

#endif /* LIBSBP_V4_SSR_MSG_SSR_TILE_DEFINITION_H */
