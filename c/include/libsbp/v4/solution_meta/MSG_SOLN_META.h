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
 * Automatically generated from yaml/swiftnav/sbp/solution_meta.yaml
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

#ifndef LIBSBP_V4_SOLUTION_META_MSG_SOLN_META_H
#define LIBSBP_V4_SOLUTION_META_MSG_SOLN_META_H

#include <math.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>

#include <libsbp/common.h>
#include <libsbp/solution_meta_macros.h>
#include <libsbp/v4/solution_meta/SolutionInputType.h>
#include <libsbp/v4/string/sbp_string.h>

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
 *
 * SBP_MSG_SOLN_META
 *
 *****************************************************************************/
/** Solution Sensors Metadata
 *
 * This message contains all metadata about the sensors received and/or used in
 * computing the sensorfusion solution. It focuses primarily, but not only, on
 * GNSS metadata. Regarding the age of the last received valid GNSS solution,
 * the highest two bits are time status, indicating whether age gnss can or can
 * not be used to retrieve time of measurement (noted TOM, also known as time of
 * validity) If it can, subtract 'age gnss' from 'tow' in navigation messages to
 * get TOM. Can be used before alignment is complete in the Fusion Engine, when
 * output solution is the last received valid GNSS solution and its tow is not a
 * TOM.
 */
typedef struct {
  /**
   * GPS time of week rounded to the nearest millisecond [ms]
   */
  u32 tow;

  /**
   * Position Dilution of Precision as per last available DOPS from PVT engine
   * (0xFFFF indicates invalid) [0.01]
   */
  u16 pdop;

  /**
   * Horizontal Dilution of Precision as per last available DOPS from PVT engine
   * (0xFFFF indicates invalid) [0.01]
   */
  u16 hdop;

  /**
   * Vertical Dilution of Precision as per last available DOPS from PVT engine
   * (0xFFFF indicates invalid) [0.01]
   */
  u16 vdop;

  /**
   * Age of corrections as per last available AGE_CORRECTIONS from PVT engine
   * (0xFFFF indicates invalid) [deciseconds]
   */
  u16 age_corrections;

  /**
   * Age and Time Status of the last received valid GNSS solution. [ms]
   */
  u32 age_gnss;

  /**
   * Array of Metadata describing the sensors potentially involved in the
   * solution. Each element in the array represents a single sensor type and
   * consists of flags containing (meta)data pertaining to that specific single
   * sensor. Refer to each (XX)InputType descriptor in the present doc.
   */
  sbp_solution_input_type_t sol_in[SBP_MSG_SOLN_META_SOL_IN_MAX];
  /**
   * Number of elements in sol_in
   *
   * When sending a message fill in this field with the number elements set in
   * sol_in before calling an appropriate libsbp send function
   *
   * When receiving a message query this field for the number of elements in
   * sol_in. The value of any elements beyond the index specified in this field
   * is undefined
   */
  u8 n_sol_in;
} sbp_msg_soln_meta_t;

/**
 * Get encoded size of an instance of sbp_msg_soln_meta_t
 *
 * @param msg sbp_msg_soln_meta_t instance
 * @return Length of on-wire representation
 */
static inline size_t sbp_msg_soln_meta_encoded_len(
    const sbp_msg_soln_meta_t *msg) {
  return SBP_MSG_SOLN_META_ENCODED_OVERHEAD +
         (msg->n_sol_in * SBP_SOLUTION_INPUT_TYPE_ENCODED_LEN);
}

/**
 * Encode an instance of sbp_msg_soln_meta_t to wire representation
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
 * @param msg Instance of sbp_msg_soln_meta_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
SBP_EXPORT s8 sbp_msg_soln_meta_encode(uint8_t *buf, uint8_t len,
                                       uint8_t *n_written,
                                       const sbp_msg_soln_meta_t *msg);

/**
 * Decode an instance of sbp_msg_soln_meta_t from wire representation
 *
 * This function decodes the wire representation of a sbp_msg_soln_meta_t
 * message to the given instance. The caller must specify the length of the
 * buffer in the \p len parameter. If non-null the number of bytes read from the
 * buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_msg_soln_meta_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
SBP_EXPORT s8 sbp_msg_soln_meta_decode(const uint8_t *buf, uint8_t len,
                                       uint8_t *n_read,
                                       sbp_msg_soln_meta_t *msg);
/**
 * Send an instance of sbp_msg_soln_meta_t with the given write function
 *
 * An equivalent of #sbp_message_send which operates specifically on
 * sbp_msg_soln_meta_t
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
SBP_EXPORT s8 sbp_msg_soln_meta_send(sbp_state_t *s, u16 sender_id,
                                     const sbp_msg_soln_meta_t *msg,
                                     sbp_write_fn_t write);

/**
 * Compare two instances of sbp_msg_soln_meta_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_soln_meta_t instance
 * @param b sbp_msg_soln_meta_t instance
 * @return 0, <0, >0
 */
SBP_EXPORT int sbp_msg_soln_meta_cmp(const sbp_msg_soln_meta_t *a,
                                     const sbp_msg_soln_meta_t *b);

#ifdef __cplusplus
}

static inline bool operator==(const sbp_msg_soln_meta_t &lhs,
                              const sbp_msg_soln_meta_t &rhs) {
  return sbp_msg_soln_meta_cmp(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_msg_soln_meta_t &lhs,
                              const sbp_msg_soln_meta_t &rhs) {
  return sbp_msg_soln_meta_cmp(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_soln_meta_t &lhs,
                             const sbp_msg_soln_meta_t &rhs) {
  return sbp_msg_soln_meta_cmp(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_msg_soln_meta_t &lhs,
                              const sbp_msg_soln_meta_t &rhs) {
  return sbp_msg_soln_meta_cmp(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_soln_meta_t &lhs,
                             const sbp_msg_soln_meta_t &rhs) {
  return sbp_msg_soln_meta_cmp(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_msg_soln_meta_t &lhs,
                              const sbp_msg_soln_meta_t &rhs) {
  return sbp_msg_soln_meta_cmp(&lhs, &rhs) >= 0;
}

#endif  // ifdef __cplusplus

#endif /* LIBSBP_V4_SOLUTION_META_MSG_SOLN_META_H */
