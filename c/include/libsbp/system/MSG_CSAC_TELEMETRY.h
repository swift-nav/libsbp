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
 * Automatically generated from yaml/swiftnav/sbp/system.yaml
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

#ifndef LIBSBP_SYSTEM_MSG_CSAC_TELEMETRY_H
#define LIBSBP_SYSTEM_MSG_CSAC_TELEMETRY_H

#include <math.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>

#include <libsbp/common.h>
#include <libsbp/string/sbp_string.h>
#include <libsbp/system_macros.h>

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
 *
 * SBP_MSG_CSAC_TELEMETRY
 *
 *****************************************************************************/
/** Experimental telemetry message
 *
 * The CSAC telemetry message has an implementation defined telemetry string
 * from a device. It is not produced or available on general Swift Products. It
 * is intended to be a low rate message for status purposes.
 */
typedef struct {
  /**
   * Index representing the type of telemetry in use.  It is implementation
   * defined.
   */
  u8 id;

  /**
   * Comma separated list of values as defined by the index
   */
  sbp_string_t telemetry;
} sbp_msg_csac_telemetry_t;

/**
 * Initialise sbp_msg_csac_telemetry_t::telemetry to empty
 *
 * @param msg sbp_msg_csac_telemetry_t instance
 */
SBP_EXPORT void sbp_msg_csac_telemetry_telemetry_init(
    sbp_msg_csac_telemetry_t *msg);

/**
 * Test sbp_msg_csac_telemetry_t::telemetry for validity
 *
 * @param msg sbp_msg_csac_telemetry_t instance
 * @return true is sbp_msg_csac_telemetry_t::telemetry is valid for encoding
 * purposes, false otherwise
 */
SBP_EXPORT bool sbp_msg_csac_telemetry_telemetry_valid(
    const sbp_msg_csac_telemetry_t *msg);

/**
 * Tests 2 instances of sbp_msg_csac_telemetry_t::telemetry for equality
 *
 * Returns a value with the same definitions as strcmp from the C standard
 * library
 *
 * @param a sbp_msg_csac_telemetry_t instance
 * @param b sbp_msg_csac_telemetry_t instance
 * @return 0 if equal, <0 if a<b, >0 if a>b
 */
SBP_EXPORT int sbp_msg_csac_telemetry_telemetry_strcmp(
    const sbp_msg_csac_telemetry_t *a, const sbp_msg_csac_telemetry_t *b);

/**
 * Get the encoded size of sbp_msg_csac_telemetry_t::telemetry
 *
 * @param msg sbp_msg_csac_telemetry_t instance
 * @return Size of sbp_msg_csac_telemetry_t::telemetry in wire representation
 */
SBP_EXPORT size_t sbp_msg_csac_telemetry_telemetry_encoded_len(
    const sbp_msg_csac_telemetry_t *msg);

/**
 * Query sbp_msg_csac_telemetry_t::telemetry for remaining space
 *
 * Returns the number of bytes (not including NULL terminator) which can be
 * added to sbp_msg_csac_telemetry_t::telemetry before it exceeds the maximum
 * size of the field in wire representation
 *
 * @param msg sbp_msg_csac_telemetry_t instance
 * @return Maximum number of bytes that can be appended to the existing string
 */
SBP_EXPORT size_t sbp_msg_csac_telemetry_telemetry_space_remaining(
    const sbp_msg_csac_telemetry_t *msg);
/**
 * Set sbp_msg_csac_telemetry_t::telemetry
 *
 * Erase any existing content and replace with the specified string
 *
 * If the should_trunc parameter is set to false and the specified string is
 * longer than can be represented in wire encoding, this function will return
 * false. Otherwise, if should_trunc is set to true, then as much as possible
 * will be read from the new_str as can fit in the msg.
 *
 * @param msg sbp_msg_csac_telemetry_t instance
 * @param new_str New string
 * @param should_trunc Whether the new_str can be truncated to fit in msg
 * @param n_written If not null, on success will be set to the number of bytes
 * written to msg
 * @return true on success, false otherwise
 */
SBP_EXPORT bool sbp_msg_csac_telemetry_telemetry_set(
    sbp_msg_csac_telemetry_t *msg, const char *new_str, bool should_trunc,
    size_t *n_written);

/**
 * Set sbp_msg_csac_telemetry_t::telemetry from a raw buffer
 *
 * Erase any existing content and replace with the specified raw buffer
 *
 * If the should_trunc parameter is set to false and the specified string is
 * longer than can be represented in wire encoding, this function will return
 * false. Otherwise, if should_trunc is set to true, then as much as possible
 * will be read from the new_str as can fit in the msg.
 *
 * @param msg sbp_msg_csac_telemetry_t instance
 * @param new_buf New buffer
 * @param new_buf_len New buffer length
 * @param should_trunc Whether the new_str can be truncated to fit in msg
 * @param n_written If not null, on success will be set to the number of bytes
 * written to msg
 * @return true on success, false otherwise
 */
SBP_EXPORT bool sbp_msg_csac_telemetry_telemetry_set_raw(
    sbp_msg_csac_telemetry_t *msg, const char *new_buf, size_t new_buf_len,
    bool should_trunc, size_t *n_written);

/**
 * Set sbp_msg_csac_telemetry_t::telemetry with printf style formatting
 *
 * Erase any existing content and replace with the formatted string
 *
 * This function will return true if the new string was successfully applied.
 * If should_trunc is set false, and the operation would end up overflowing the
 * maximum size of this field in wire encoding the existing contents will be
 * erased and this function will return false. Otherwise, if should_trunc is
 * set true, the input formatted string will be truncated to fit.
 *
 * @param msg sbp_msg_csac_telemetry_t instance
 * @param should_trunc Whether the input string should be truncated to fit
 * @param n_written If not null, on success will be set to the number of bytes
 * written to msg
 * @param fmt printf style format string
 * @return true on success, false otherwise
 */
SBP_EXPORT bool sbp_msg_csac_telemetry_telemetry_printf(
    sbp_msg_csac_telemetry_t *msg, bool should_trunc, size_t *n_written,
    const char *fmt, ...) SBP_ATTR_FORMAT(4, 5);

/**
 * Set sbp_msg_csac_telemetry_t::telemetry with printf style formatting
 *
 * Identical to #sbp_msg_csac_telemetry_telemetry_printf except it takes a
 * va_list argument
 *
 * @param msg sbp_msg_csac_telemetry_t instance
 * @param should_trunc Whether the input string should be truncated to fit
 * @param n_written If not null, on success will be set to the number of bytes
 * written to msg
 * @param fmt printf style format string
 * @param ap Argument list
 * @return true on success, false otherwise
 */
SBP_EXPORT bool sbp_msg_csac_telemetry_telemetry_vprintf(
    sbp_msg_csac_telemetry_t *msg, bool should_trunc, size_t *n_written,
    const char *fmt, va_list ap) SBP_ATTR_VFORMAT(4);

/**
 * Append sbp_msg_csac_telemetry_t::telemetry with printf style formatting
 *
 * The new string will be appended to the existing contents of the string (if
 * any). If should_trunc is false and the operation would end up overflowing
 * the maximum size of this field in wire encoding, the existing contents will
 * be unmodified and this function will return false. Otherwise, if
 * should_trunc is true, the input string will be truncated to fit.
 *
 * @param msg sbp_msg_csac_telemetry_t instance
 * @param should_trunc Whether the input string should be truncated to fit
 * @param n_written If not null, on success will be set to the number of bytes
 * written to msg
 * @param fmt printf style format string
 * @return true on success, false otherwise
 */
SBP_EXPORT bool sbp_msg_csac_telemetry_telemetry_append_printf(
    sbp_msg_csac_telemetry_t *msg, bool should_trunc, size_t *n_written,
    const char *fmt, ...) SBP_ATTR_FORMAT(4, 5);

/**
 * Append sbp_msg_csac_telemetry_t::telemetry with printf style formatting
 *
 * Identical to #sbp_msg_csac_telemetry_telemetry_append_printf except it takes
 * a va_list argument
 *
 * @param msg sbp_msg_csac_telemetry_t instance
 * @param should_trunc Whether the input string should be truncated to fit
 * @param n_written If not null, on success will be set to the number of bytes
 * written to msg
 * @param fmt printf style format string
 * @param ap Argument list
 * @return true on success, false otherwise
 */
SBP_EXPORT bool sbp_msg_csac_telemetry_telemetry_append_vprintf(
    sbp_msg_csac_telemetry_t *msg, bool should_trunc, size_t *n_written,
    const char *fmt, va_list ap) SBP_ATTR_VFORMAT(4);

/**
 * Obtain the string value from sbp_msg_csac_telemetry_t::telemetry
 *
 * @param msg sbp_msg_csac_telemetry_t instance
 * @return String contents
 */
SBP_EXPORT const char *sbp_msg_csac_telemetry_telemetry_get(
    const sbp_msg_csac_telemetry_t *msg);

/**
 * Obtain the length of sbp_msg_csac_telemetry_t::telemetry
 *
 * The returned value does not include the NULL terminator.
 *
 * @param msg sbp_msg_csac_telemetry_t instance
 * @return Length of string
 */
SBP_EXPORT size_t
sbp_msg_csac_telemetry_telemetry_strlen(const sbp_msg_csac_telemetry_t *msg);

/**
 * Get encoded size of an instance of sbp_msg_csac_telemetry_t
 *
 * @param msg sbp_msg_csac_telemetry_t instance
 * @return Length of on-wire representation
 */
static inline size_t sbp_msg_csac_telemetry_encoded_len(
    const sbp_msg_csac_telemetry_t *msg) {
  return SBP_MSG_CSAC_TELEMETRY_ENCODED_OVERHEAD +
         sbp_msg_csac_telemetry_telemetry_encoded_len(msg);
}

/**
 * Encode an instance of sbp_msg_csac_telemetry_t to wire representation
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
 * @param msg Instance of sbp_msg_csac_telemetry_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
SBP_EXPORT s8
sbp_msg_csac_telemetry_encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                              const sbp_msg_csac_telemetry_t *msg);

/**
 * Decode an instance of sbp_msg_csac_telemetry_t from wire representation
 *
 * This function decodes the wire representation of a sbp_msg_csac_telemetry_t
 * message to the given instance. The caller must specify the length of the
 * buffer in the \p len parameter. If non-null the number of bytes read from the
 * buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_msg_csac_telemetry_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
SBP_EXPORT s8 sbp_msg_csac_telemetry_decode(const uint8_t *buf, uint8_t len,
                                            uint8_t *n_read,
                                            sbp_msg_csac_telemetry_t *msg);
/**
 * Send an instance of sbp_msg_csac_telemetry_t with the given write function
 *
 * An equivalent of #sbp_message_send which operates specifically on
 * sbp_msg_csac_telemetry_t
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
SBP_EXPORT s8 sbp_msg_csac_telemetry_send(sbp_state_t *s, u16 sender_id,
                                          const sbp_msg_csac_telemetry_t *msg,
                                          sbp_write_fn_t write);

/**
 * Compare two instances of sbp_msg_csac_telemetry_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_csac_telemetry_t instance
 * @param b sbp_msg_csac_telemetry_t instance
 * @return 0, <0, >0
 */
SBP_EXPORT int sbp_msg_csac_telemetry_cmp(const sbp_msg_csac_telemetry_t *a,
                                          const sbp_msg_csac_telemetry_t *b);

#ifdef __cplusplus
}

static inline bool operator==(const sbp_msg_csac_telemetry_t &lhs,
                              const sbp_msg_csac_telemetry_t &rhs) {
  return sbp_msg_csac_telemetry_cmp(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_msg_csac_telemetry_t &lhs,
                              const sbp_msg_csac_telemetry_t &rhs) {
  return sbp_msg_csac_telemetry_cmp(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_csac_telemetry_t &lhs,
                             const sbp_msg_csac_telemetry_t &rhs) {
  return sbp_msg_csac_telemetry_cmp(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_msg_csac_telemetry_t &lhs,
                              const sbp_msg_csac_telemetry_t &rhs) {
  return sbp_msg_csac_telemetry_cmp(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_csac_telemetry_t &lhs,
                             const sbp_msg_csac_telemetry_t &rhs) {
  return sbp_msg_csac_telemetry_cmp(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_msg_csac_telemetry_t &lhs,
                              const sbp_msg_csac_telemetry_t &rhs) {
  return sbp_msg_csac_telemetry_cmp(&lhs, &rhs) >= 0;
}

#endif  // ifdef __cplusplus

#endif /* LIBSBP_SYSTEM_MSG_CSAC_TELEMETRY_H */
