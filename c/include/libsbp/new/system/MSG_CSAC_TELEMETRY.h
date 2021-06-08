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
 * Automatically generated from yaml/swiftnav/sbp/system.yaml
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

#ifndef LIBSBP_NEW_SYSTEM_MSG_CSAC_TELEMETRY_MESSAGES_H
#define LIBSBP_NEW_SYSTEM_MSG_CSAC_TELEMETRY_MESSAGES_H

#include <endian.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>

#include <libsbp/common.h>
#include <libsbp/new/string/double_null_terminated.h>
#include <libsbp/new/string/multipart.h>
#include <libsbp/new/string/null_terminated.h>
#include <libsbp/new/string/unterminated.h>
#include <libsbp/system_macros.h>

#ifdef __cplusplus
extern "C" {
#endif

struct sbp_state;
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
   * Index representing the type of telemetry in use.  It is implemention
   * defined.
   */
  u8 id;

  /**
   * Comma separated list of values as defined by the index
   */
  sbp_unterminated_string_t telemetry;
} sbp_msg_csac_telemetry_t;

/**
 * Initialise sbp_msg_csac_telemetry_t::telemetry to empty
 *
 * @param msg sbp_msg_csac_telemetry_t instance
 */
void sbp_msg_csac_telemetry_t_telemetry_init(sbp_unterminated_string_t *s);

/**
 * Test sbp_msg_csac_telemetry_t::telemetry for validity
 *
 * @param msg sbp_msg_csac_telemetry_t instance
 * @return true is sbp_msg_csac_telemetry_t::telemetry is valid for encoding
 * purposes, false otherwise
 */
bool sbp_msg_csac_telemetry_t_telemetry_valid(
    const sbp_unterminated_string_t *s);

/**
 * Tests 2 instances of sbp_msg_csac_telemetry_t::telemetry for equality
 *
 * Returns a value with the same definitions as #strcmp from the C standard
 * library
 *
 * @param a sbp_msg_csac_telemetry_t instance
 * @param b sbp_msg_csac_telemetry_t instance
 * @return 0 if equal, <0 if a<b, >0 if a>b
 */
int sbp_msg_csac_telemetry_t_telemetry_strcmp(
    const sbp_unterminated_string_t *a, const sbp_unterminated_string_t *b);

/**
 * Get the encoded size of sbp_msg_csac_telemetry_t::telemetry
 *
 * @param msg sbp_msg_csac_telemetry_t instance
 * @return Size of sbp_msg_csac_telemetry_t::telemetry in wire representation
 */
uint8_t sbp_msg_csac_telemetry_t_telemetry_packed_len(
    const sbp_unterminated_string_t *s);

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
uint8_t sbp_msg_csac_telemetry_t_telemetry_space_remaining(
    const sbp_unterminated_string_t *s);
/**
 * Set sbp_msg_csac_telemetry_t::telemetry
 *
 * Erase any existing content and replace with the specified string
 *
 * This function will return true if the new string was successfully applied. If
 * the specified string is longer than can be represented in wire encoding this
 * function will return false
 *
 * @param msg sbp_msg_csac_telemetry_t instance
 * @param new_str New string
 * @return true on success, false otherwise
 */
bool sbp_msg_csac_telemetry_t_telemetry_set(sbp_unterminated_string_t *s,
                                            const char *new_str);

/**
 * Set sbp_msg_csac_telemetry_t::telemetry with printf style formatting
 *
 * Erase any existing content and replace with the formatted string
 *
 * This function will return true if the new string was successfully applied. If
 * the operation would end up overflowing the maximum size of this field in wire
 * encoding the existing contents will be erased and this function will return
 * false.
 *
 * @param msg sbp_msg_csac_telemetry_t instance
 * @param fmt printf style format string
 * @return true on success, false otherwise
 */
bool sbp_msg_csac_telemetry_t_telemetry_printf(sbp_unterminated_string_t *s,
                                               const char *fmt, ...)
    SBP_ATTR_FORMAT(2, 3);

/**
 * Set sbp_msg_csac_telemetry_t::telemetry with printf style formatting
 *
 * Identical to #sbp_msg_csac_telemetry_t_telemetry_printf except it takes a
 * va_list argument
 *
 * @param msg sbp_msg_csac_telemetry_t instance
 * @param fmt printf style format string
 * @param ap Argument list
 * @return true on success, false otherwise
 */
bool sbp_msg_csac_telemetry_t_telemetry_vprintf(sbp_unterminated_string_t *s,
                                                const char *fmt, va_list ap);

/**
 * Append sbp_msg_csac_telemetry_t::telemetry with printf style formatting
 *
 * The new string will be appended to the existing contents of the string (if
 * any). If the operation would end up overflowing the maximum size of this
 * field in wire encoding the existing contents will be unmodified and this
 * function will return false.
 *
 * @param msg sbp_msg_csac_telemetry_t instance
 * @param fmt printf style format string
 * @return true on success, false otherwise
 */
bool sbp_msg_csac_telemetry_t_telemetry_append_printf(
    sbp_unterminated_string_t *s, const char *fmt, ...) SBP_ATTR_FORMAT(2, 3);

/**
 * Append sbp_msg_csac_telemetry_t::telemetry with printf style formatting
 *
 * Identical to #sbp_msg_csac_telemetry_t_telemetry_append_printf except it
 * takes a va_list argument
 *
 * @param msg sbp_msg_csac_telemetry_t instance
 * @param fmt printf style format string
 * @param ap Argument list
 * @return true on success, false otherwise
 *
 */
bool sbp_msg_csac_telemetry_t_telemetry_append_vprintf(
    sbp_unterminated_string_t *s, const char *fmt, va_list ap);

/**
 * Obtain the string value from sbp_msg_csac_telemetry_t::telemetry
 *
 * @param msg sbp_msg_csac_telemetry_t instance
 * @return String contents
 */
const char *sbp_msg_csac_telemetry_t_telemetry_get(
    const sbp_unterminated_string_t *s);

/**
 * Obtain the length of sbp_msg_csac_telemetry_t::telemetry
 *
 * The returned value does not include the NULL terminator.
 *
 * @param msg sbp_msg_csac_telemetry_t instance
 * @return Length of section
 */
uint8_t sbp_msg_csac_telemetry_t_telemetry_section_strlen(
    const sbp_unterminated_string_t *s, uint8_t section);

/**
 * Get encoded size of an instance of sbp_msg_csac_telemetry_t
 *
 * @param msg sbp_msg_csac_telemetry_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_msg_csac_telemetry_t(
    const sbp_msg_csac_telemetry_t *msg);

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
s8 sbp_encode_sbp_msg_csac_telemetry_t(uint8_t *buf, uint8_t len,
                                       uint8_t *n_written,
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
s8 sbp_decode_sbp_msg_csac_telemetry_t(const uint8_t *buf, uint8_t len,
                                       uint8_t *n_read,
                                       sbp_msg_csac_telemetry_t *msg);
/**
 * Send an instance of sbp_msg_csac_telemetry_t with the given write function
 *
 * An equivalent of #sbp_send_message which operates specifically on
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
 * @param SBP_OK on success, or other libsbp error code
 */
s8 sbp_send_sbp_msg_csac_telemetry_t(struct sbp_state *s, u16 sender_id,
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
int sbp_cmp_sbp_msg_csac_telemetry_t(const sbp_msg_csac_telemetry_t *a,
                                     const sbp_msg_csac_telemetry_t *b);

#ifdef __cplusplus
}
static inline bool operator==(const sbp_msg_csac_telemetry_t &lhs,
                              const sbp_msg_csac_telemetry_t &rhs) {
  return sbp_cmp_sbp_msg_csac_telemetry_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_msg_csac_telemetry_t &lhs,
                              const sbp_msg_csac_telemetry_t &rhs) {
  return sbp_cmp_sbp_msg_csac_telemetry_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_csac_telemetry_t &lhs,
                             const sbp_msg_csac_telemetry_t &rhs) {
  return sbp_cmp_sbp_msg_csac_telemetry_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_msg_csac_telemetry_t &lhs,
                              const sbp_msg_csac_telemetry_t &rhs) {
  return sbp_cmp_sbp_msg_csac_telemetry_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_csac_telemetry_t &lhs,
                             const sbp_msg_csac_telemetry_t &rhs) {
  return sbp_cmp_sbp_msg_csac_telemetry_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_msg_csac_telemetry_t &lhs,
                              const sbp_msg_csac_telemetry_t &rhs) {
  return sbp_cmp_sbp_msg_csac_telemetry_t(&lhs, &rhs) >= 0;
}

#endif

#endif /* LIBSBP_NEW_SYSTEM_MESSAGES_H */
