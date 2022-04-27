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

#ifndef LIBSBP_V4_SSR_GRIDDEFINITIONHEADERDEPA_H
#define LIBSBP_V4_SSR_GRIDDEFINITIONHEADERDEPA_H

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
 * SBP_GRIDDEFINITIONHEADERDEPA
 *
 *****************************************************************************/
/** Defines the grid for MSG_SSR_GRIDDED_CORRECTION messages
 *
 * Defines the grid for MSG_SSR_GRIDDED_CORRECTION messages. Also includes an
 * RLE encoded validity list.
 */
typedef struct {
  /**
   * region_size (deg) = 10 / region_size_inverse 0 is an invalid value.
   * [inverse degrees]
   */
  u8 region_size_inverse;

  /**
   * grid height (deg) = grid width (deg) = area_width / region_size 0 is an
   * invalid value.
   */
  u16 area_width;

  /**
   * North-West corner latitude (deg) = region_size * lat_nw_corner_enc - 90
   */
  u16 lat_nw_corner_enc;

  /**
   * North-West corner longitude (deg) = region_size * lon_nw_corner_enc - 180
   */
  u16 lon_nw_corner_enc;

  /**
   * Number of messages in the dataset
   */
  u8 num_msgs;

  /**
   * Position of this message in the dataset
   */
  u8 seq_num;
} sbp_grid_definition_header_dep_a_t;

/**
 * Get encoded size of an instance of sbp_grid_definition_header_dep_a_t
 *
 * @param msg sbp_grid_definition_header_dep_a_t instance
 * @return Length of on-wire representation
 */
static inline size_t sbp_grid_definition_header_dep_a_encoded_len(
    const sbp_grid_definition_header_dep_a_t *msg) {
  (void)msg;
  return SBP_GRID_DEFINITION_HEADER_DEP_A_ENCODED_LEN;
}

/**
 * Encode an instance of sbp_grid_definition_header_dep_a_t to wire
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
 * @param msg Instance of sbp_grid_definition_header_dep_a_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
SBP_EXPORT s8 sbp_grid_definition_header_dep_a_encode(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_grid_definition_header_dep_a_t *msg);

/**
 * Decode an instance of sbp_grid_definition_header_dep_a_t from wire
 * representation
 *
 * This function decodes the wire representation of a
 * sbp_grid_definition_header_dep_a_t message to the given instance. The caller
 * must specify the length of the buffer in the \p len parameter. If non-null
 * the number of bytes read from the buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_grid_definition_header_dep_a_t
 * instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
SBP_EXPORT s8 sbp_grid_definition_header_dep_a_decode(
    const uint8_t *buf, uint8_t len, uint8_t *n_read,
    sbp_grid_definition_header_dep_a_t *msg);

/**
 * Compare two instances of sbp_grid_definition_header_dep_a_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_grid_definition_header_dep_a_t instance
 * @param b sbp_grid_definition_header_dep_a_t instance
 * @return 0, <0, >0
 */
SBP_EXPORT int sbp_grid_definition_header_dep_a_cmp(
    const sbp_grid_definition_header_dep_a_t *a,
    const sbp_grid_definition_header_dep_a_t *b);

#ifdef __cplusplus
}

static inline bool operator==(const sbp_grid_definition_header_dep_a_t &lhs,
                              const sbp_grid_definition_header_dep_a_t &rhs) {
  return sbp_grid_definition_header_dep_a_cmp(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_grid_definition_header_dep_a_t &lhs,
                              const sbp_grid_definition_header_dep_a_t &rhs) {
  return sbp_grid_definition_header_dep_a_cmp(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_grid_definition_header_dep_a_t &lhs,
                             const sbp_grid_definition_header_dep_a_t &rhs) {
  return sbp_grid_definition_header_dep_a_cmp(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_grid_definition_header_dep_a_t &lhs,
                              const sbp_grid_definition_header_dep_a_t &rhs) {
  return sbp_grid_definition_header_dep_a_cmp(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_grid_definition_header_dep_a_t &lhs,
                             const sbp_grid_definition_header_dep_a_t &rhs) {
  return sbp_grid_definition_header_dep_a_cmp(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_grid_definition_header_dep_a_t &lhs,
                              const sbp_grid_definition_header_dep_a_t &rhs) {
  return sbp_grid_definition_header_dep_a_cmp(&lhs, &rhs) >= 0;
}

#endif  // ifdef __cplusplus

#endif /* LIBSBP_V4_SSR_GRIDDEFINITIONHEADERDEPA_H */
