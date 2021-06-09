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
 * Automatically generated from yaml/swiftnav/sbp/settings.yaml
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

#ifndef LIBSBP_V4_SETTINGS_MSG_SETTINGS_WRITE_RESP_MESSAGES_H
#define LIBSBP_V4_SETTINGS_MSG_SETTINGS_WRITE_RESP_MESSAGES_H

#include <endian.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>

#include <libsbp/common.h>
#include <libsbp/settings_macros.h>
#include <libsbp/v4/string/double_null_terminated.h>
#include <libsbp/v4/string/multipart.h>
#include <libsbp/v4/string/null_terminated.h>
#include <libsbp/v4/string/unterminated.h>

#ifdef __cplusplus
extern "C" {
#endif

struct sbp_state;

/******************************************************************************
 *
 * SBP_MSG_SETTINGS_WRITE_RESP
 *
 *****************************************************************************/
/** Acknowledgement with status of MSG_SETTINGS_WRITE
 *
 * Return the status of a write request with the new value of the setting.  If
 * the requested value is rejected, the current value will be returned. The
 * string field is a NULL-terminated and NULL-delimited string with contents
 * "SECTION_SETTING\0SETTING\0VALUE\0" where the '\0' escape sequence denotes
 * the NULL character and where quotation marks are omitted. An example string
 * that could be sent from device is "solution\0soln_freq\010\0".
 */
typedef struct {
  /**
   * Write status
   */
  u8 status;

  /**
   * A NULL-terminated and delimited string with contents
   * "SECTION_SETTING\0SETTING\0VALUE\0"
   */
  sbp_multipart_string_t setting;
} sbp_msg_settings_write_resp_t;

/**
 * Initialise sbp_msg_settings_write_resp_t::setting to empty
 *
 * @param msg sbp_msg_settings_write_resp_t instance
 */
void sbp_msg_settings_write_resp_setting_init(sbp_multipart_string_t *s);

/**
 * Test sbp_msg_settings_write_resp_t::setting for validity
 *
 * @param msg sbp_msg_settings_write_resp_t instance
 * @return true is sbp_msg_settings_write_resp_t::setting is valid for encoding
 * purposes, false otherwise
 */
bool sbp_msg_settings_write_resp_setting_valid(const sbp_multipart_string_t *s);

/**
 * Tests 2 instances of sbp_msg_settings_write_resp_t::setting for equality
 *
 * Returns a value with the same definitions as #strcmp from the C standard
 * library
 *
 * @param a sbp_msg_settings_write_resp_t instance
 * @param b sbp_msg_settings_write_resp_t instance
 * @return 0 if equal, <0 if a<b, >0 if a>b
 */
int sbp_msg_settings_write_resp_setting_strcmp(const sbp_multipart_string_t *a,
                                               const sbp_multipart_string_t *b);

/**
 * Get the encoded size of sbp_msg_settings_write_resp_t::setting
 *
 * @param msg sbp_msg_settings_write_resp_t instance
 * @return Size of sbp_msg_settings_write_resp_t::setting in wire representation
 */
uint8_t sbp_msg_settings_write_resp_setting_encoded_len(
    const sbp_multipart_string_t *s);

/**
 * Query sbp_msg_settings_write_resp_t::setting for remaining space
 *
 * Returns the number of bytes (not including NULL terminator) which can be
 * added to sbp_msg_settings_write_resp_t::setting before it exceeds the maximum
 * size of the field in wire representation
 *
 * @param msg sbp_msg_settings_write_resp_t instance
 * @return Maximum number of bytes that can be appended to the existing string
 */
uint8_t sbp_msg_settings_write_resp_setting_space_remaining(
    const sbp_multipart_string_t *s);
/**
 * Return the number of sections in sbp_msg_settings_write_resp_t::setting
 *
 * @param msg sbp_msg_settings_write_resp_t instance
 * @return Number of sections in string
 */
uint8_t sbp_msg_settings_write_resp_setting_count_sections(
    const sbp_multipart_string_t *s);

/**
 * Add a section to sbp_msg_settings_write_resp_t::setting
 *
 * The specified string will be appended to the field as a new section. If the
 * new section would end up overflowing the maximum encoded length of this field
 * the string will not be changed and this function will return false
 *
 * @param msg sbp_msg_settings_write_resp_t instance
 * @param new_str New string
 * @return true on success, false otherwise
 */
bool sbp_msg_settings_write_resp_setting_add_section(sbp_multipart_string_t *s,
                                                     const char *new_str);

/**
 * Add a section to sbp_msg_settings_write_resp_t::setting with printf style
 * formatting
 *
 * A new section will be added to the field according to the specified printf
 * style format string and arguments. If the operation would end up overflowing
 * the maximum size of this field in wire encoding the existing contents will be
 * unmodified and this function will return false.
 *
 * @param msg sbp_msg_settings_write_resp_t instance
 * @param fmt printf style format string
 * @return true on success, false otherwise
 */
bool sbp_msg_settings_write_resp_setting_add_section_printf(
    sbp_multipart_string_t *s, const char *fmt, ...) SBP_ATTR_FORMAT(2, 3);

/**
 * Add a section to sbp_msg_settings_write_resp_t::setting with printf style
 * formatting
 *
 * Identical to #sbp_msg_settings_write_resp_setting_add_section_printf except
 * it takes a va_list argument
 *
 * @param msg sbp_msg_settings_write_resp_t instance
 * @param fmt printf style format string
 * @param ap Argument list
 * @return true on success, false otherwise
 */
bool sbp_msg_settings_write_resp_setting_add_section_vprintf(
    sbp_multipart_string_t *s, const char *fmt, va_list ap);

/**
 * Append a string to the last section in sbp_msg_settings_write_resp_t::setting
 *
 * If the field is currently empty this function will behave exactly like
 * #sbp_msg_settings_write_resp_setting_add_section
 *
 * If the field already contains one or more sections the given string will be
 * appended on to the last section in the string.
 *
 * If the operation would end up overflowing the maximum size of this field in
 * wire encoding the existing contents will be unmodified and this function will
 * return false.
 *
 * @param msg sbp_msg_settings_write_resp_t instance
 * @param str New string
 * @return true on success, false otherwise
 */
bool sbp_msg_settings_write_resp_setting_append(sbp_multipart_string_t *s,
                                                const char *str);

/**
 * Append a string to the last section in sbp_msg_settings_write_resp_t::setting
 * with printf style formatting
 *
 * If the field is currently empty this function will behave exactly like
 * #sbp_msg_settings_write_resp_setting_add_section_printf
 *
 * If the field already contains one or more sections the given string will be
 * appended on to the last section in the string.
 *
 * If the operation would end up overflowing the maximum size of this field in
 * wire encoding the existing contents will be unmodified and this function will
 * return false.
 *
 * @param msg sbp_msg_settings_write_resp_t instance
 * @param fmt printf style format string
 * @return true on success, false otherwise
 */
bool sbp_msg_settings_write_resp_setting_append_printf(
    sbp_multipart_string_t *s, const char *fmt, ...) SBP_ATTR_FORMAT(2, 3);

/**
 * Append a string to the last section in sbp_msg_settings_write_resp_t::setting
 * with printf style formatting
 *
 * If the field is currently empty this function will behave exactly like
 * #sbp_msg_settings_write_resp_setting_add_section_vprintf
 *
 * If the field already contains one or more sections the given string will be
 * sppended on to the last section in the string.
 *
 * If the operation would end overflowing the maximum size of this field in wire
 * encoding the existing contents will be unmodified and this function will
 * return false.
 *
 * @param msg sbp_msg_settings_write_resp_t instance
 * @param fmt printf style format string
 * @param ap Argument list
 * @return true on success, false otherwise
 */
bool sbp_msg_settings_write_resp_setting_append_vprintf(
    sbp_multipart_string_t *s, const char *fmt, va_list ap);

/**
 * Obtain a section from sbp_msg_settings_write_resp_t::setting
 *
 * Returns a pointer to the given subsection in the field. Sections are
 * 0-indexed, the \p section parameters must be less than the value returned
 * from #sbp_msg_settings_write_resp_setting_count_sections.
 *
 * @param msg sbp_msg_settings_write_resp_t instance
 * @param section Section number
 * @return Pointer to C string, NULL on error
 */
const char *sbp_msg_settings_write_resp_setting_get_section(
    const sbp_multipart_string_t *s, uint8_t section);

/**
 * Obtain the length of a section in sbp_msg_settings_write_resp_t::setting
 *
 * The returned value does not include the NULL terminator.
 *
 * If the given section does not exist 0 is returned.
 *
 * @param msg sbp_msg_settings_write_resp_t instance
 * @param section Section number
 * @return Length of section
 */
uint8_t sbp_msg_settings_write_resp_setting_section_strlen(
    const sbp_multipart_string_t *s, uint8_t section);

/**
 * Get encoded size of an instance of sbp_msg_settings_write_resp_t
 *
 * @param msg sbp_msg_settings_write_resp_t instance
 * @return Length of on-wire representation
 */
size_t sbp_msg_settings_write_resp_encoded_len(
    const sbp_msg_settings_write_resp_t *msg);

/**
 * Encode an instance of sbp_msg_settings_write_resp_t to wire representation
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
 * @param msg Instance of sbp_msg_settings_write_resp_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_msg_settings_write_resp_encode(uint8_t *buf, uint8_t len,
                                      uint8_t *n_written,
                                      const sbp_msg_settings_write_resp_t *msg);

/**
 * Decode an instance of sbp_msg_settings_write_resp_t from wire representation
 *
 * This function decodes the wire representation of a
 * sbp_msg_settings_write_resp_t message to the given instance. The caller must
 * specify the length of the buffer in the \p len parameter. If non-null the
 * number of bytes read from the buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_msg_settings_write_resp_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_msg_settings_write_resp_decode(const uint8_t *buf, uint8_t len,
                                      uint8_t *n_read,
                                      sbp_msg_settings_write_resp_t *msg);
/**
 * Send an instance of sbp_msg_settings_write_resp_t with the given write
 * function
 *
 * An equivalent of #sbp_send_message which operates specifically on
 * sbp_msg_settings_write_resp_t
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
s8 sbp_msg_settings_write_resp_send(struct sbp_state *s, u16 sender_id,
                                    const sbp_msg_settings_write_resp_t *msg,
                                    sbp_write_fn_t write);

/**
 * Compare two instances of sbp_msg_settings_write_resp_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_settings_write_resp_t instance
 * @param b sbp_msg_settings_write_resp_t instance
 * @return 0, <0, >0
 */
int sbp_msg_settings_write_resp_cmp(const sbp_msg_settings_write_resp_t *a,
                                    const sbp_msg_settings_write_resp_t *b);

#ifdef __cplusplus
}

static inline bool operator==(const sbp_msg_settings_write_resp_t &lhs,
                              const sbp_msg_settings_write_resp_t &rhs) {
  return sbp_msg_settings_write_resp_cmp(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_msg_settings_write_resp_t &lhs,
                              const sbp_msg_settings_write_resp_t &rhs) {
  return sbp_msg_settings_write_resp_cmp(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_settings_write_resp_t &lhs,
                             const sbp_msg_settings_write_resp_t &rhs) {
  return sbp_msg_settings_write_resp_cmp(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_msg_settings_write_resp_t &lhs,
                              const sbp_msg_settings_write_resp_t &rhs) {
  return sbp_msg_settings_write_resp_cmp(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_settings_write_resp_t &lhs,
                             const sbp_msg_settings_write_resp_t &rhs) {
  return sbp_msg_settings_write_resp_cmp(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_msg_settings_write_resp_t &lhs,
                              const sbp_msg_settings_write_resp_t &rhs) {
  return sbp_msg_settings_write_resp_cmp(&lhs, &rhs) >= 0;
}

#endif

#endif /* LIBSBP_V4_SETTINGS_MESSAGES_H */
