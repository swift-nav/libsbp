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
 * Automatically generated from yaml/(((filepath)))
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

#ifndef LIBSBP_V4_(((pkg_name|upper)))_(((m.name|upper)))_H
#define LIBSBP_V4_(((pkg_name|upper)))_(((m.name|upper)))_H

#include <stdbool.h>
#include <stddef.h>
#include <stdarg.h>
#include <string.h>
#include <stdint.h>
#include <math.h>

#include <libsbp/common.h>
#include <libsbp/v4/string/sbp_string.h>
#include <libsbp/(((pkg_name)))_macros.h>

((*- for i in include *))
#include <libsbp/v4/(((i)))>
((*- endfor *))
((*- for i in sibling_include *))
#include <libsbp/v4/(((i))).h>
((*- endfor *))

#ifdef __cplusplus
  extern "C" {
#endif

/******************************************************************************
 *
 * SBP_(((m.name|upper)))
 *
 *****************************************************************************/

((*- if m.desc *))
/** (((m.short_desc)))
 *
(((m.desc|commentify)))
 */
((*- endif *))
typedef struct {
  ((*- if m.fields *))
  ((*- for f in m.fields *))

  ((* if f.desc *))
  /**
(((f.desc|commentify))) ((* if f.units *))[(((f.units)))]((* endif*))
   */
  ((*- endif *))
  ((*- if f.packing == "packed-string" *))
  sbp_string_t (((f.name)));
  ((*- elif f.packing == "single" *))
  (((f.basetype|convert_unpacked))) (((f.name)));
  ((*- else *))
  (((f.basetype|convert_unpacked))) (((f.name)))[(((f.max_items)))];
  ((*- if f.generate_size_fn *))
  /**
   * Number of elements in (((f.name)))
   *
   * When sending a message fill in this field with the number elements set in (((f.name))) before calling an appropriate libsbp send function
   *
   * When receiving a message query this field for the number of elements in (((f.name))). The value of any elements beyond the index specified in this field is undefined
   */
  u8 (((f.size_fn)));
  ((*- endif *))
  ((*- endif *))
  ((*- endfor *))
  ((*- else *))
  /**
   * Do not use this field, it exists only to prevent illegal C syntax. Any value written to this field will be ignored
   */
  char DO_NOT_USE_dummy_field_to_prevent_empty_struct;
  ((*- endif *))
} (((m.type_name)));

((* for f in m.fields *))
  ((*- if f.packing == "packed-string" *))
  ((*- set prefix = m.prefix + "_" + f.name *))
  ((*- set comment_name = m.type_name + "::" + f.name *))
  ((*- if f.packing == "packed-string" *))
  /**
   * Initialise (((comment_name))) to empty
   *
   * @param msg (((m.type_name))) instance
   */
  void (((prefix)))_init( (((-m.type_name))) *msg);

  /**
   * Test (((comment_name))) for validity
   *
   * @param msg (((m.type_name))) instance
   * @return true is (((comment_name))) is valid for encoding purposes, false otherwise
   */
  bool (((prefix)))_valid(const (((m.type_name))) *msg);

  /**
   * Tests 2 instances of (((comment_name))) for equality
   *
   * Returns a value with the same definitions as #strcmp from the C standard library
   *
   * @param a (((m.type_name))) instance
   * @param b (((m.type_name))) instance
   * @return 0 if equal, <0 if a<b, >0 if a>b
   */
  int (((prefix)))_strcmp(const (((m.type_name))) *a, const (((m.type_name))) *b);

  /**
   * Get the encoded size of (((comment_name)))
   *
   * @param msg (((m.type_name))) instance
   * @return Size of (((comment_name))) in wire representation
   */
  size_t (((prefix)))_encoded_len(const (((m.type_name))) *msg);

  /**
   * Query (((comment_name))) for remaining space
   *
   * Returns the number of bytes (not including NULL terminator) which can be added to (((comment_name))) before it exceeds the maximum size of the field in wire representation
   *
   * @param msg (((m.type_name))) instance
   * @return Maximum number of bytes that can be appended to the existing string
   */
  size_t (((prefix)))_space_remaining(const (((m.type_name))) *msg);

  ((*- if f.encoding == "unterminated" or f.encoding == "null_terminated" *))
  /**
   * Set (((comment_name)))
   *
   * Erase any existing content and replace with the specified string
   *
   * This function will return true if the new string was successfully applied. If the specified string is longer than can be represented in wire encoding this function will return false
   *
   * @param msg (((m.type_name))) instance
   * @param new_str New string
   * @return true on success, false otherwise
   */
  bool (((prefix)))_set( (((-m.type_name))) *msg, const char *new_str);

  /**
   * Set (((comment_name))) with printf style formatting
   *
   * Erase any existing content and replace with the formatted string
   *
   * This function will return true if the new string was successfully applied. If the operation would end up overflowing the maximum size of this field in wire encoding the existing contents will be erased and this function will return false.
   *
   * @param msg (((m.type_name))) instance
   * @param fmt printf style format string
   * @return true on success, false otherwise
   */
  bool (((prefix)))_printf( (((-m.type_name))) *msg, const char *fmt, ...) SBP_ATTR_FORMAT(2,3);

  /**
   * Set (((comment_name))) with printf style formatting
   *
   * Identical to #(((prefix)))_printf except it takes a va_list argument
   *
   * @param msg (((m.type_name))) instance
   * @param fmt printf style format string
   * @param ap Argument list
   * @return true on success, false otherwise
   */
  bool (((prefix)))_vprintf( (((-m.type_name))) *msg, const char *fmt, va_list ap);

  /**
   * Append (((comment_name))) with printf style formatting
   *
   * The new string will be appended to the existing contents of the string (if any). If the operation would end up overflowing the maximum size of this field in wire encoding the existing contents will be unmodified and this function will return false.
   *
   * @param msg (((m.type_name))) instance
   * @param fmt printf style format string
   * @return true on success, false otherwise
   */
  bool (((prefix)))_append_printf( (((-m.type_name))) *msg, const char *fmt, ...) SBP_ATTR_FORMAT(2,3);

  /**
   * Append (((comment_name))) with printf style formatting
   *
   * Identical to #(((prefix)))_append_printf except it takes a va_list argument
   *
   * @param msg (((m.type_name))) instance
   * @param fmt printf style format string
   * @param ap Argument list
   * @return true on success, false otherwise
   *
   */
  bool (((prefix)))_append_vprintf( (((-m.type_name))) *msg, const char *fmt, va_list ap);

  /**
   * Obtain the string value from (((comment_name)))
   *
   * @param msg (((m.type_name))) instance
   * @return String contents
   */
  const char *(((prefix)))_get(const (((m.type_name))) *msg);

  /**
   * Obtain the length of (((comment_name)))
   *
   * The returned value does not include the NULL terminator.
   *
   * @param msg (((m.type_name))) instance
   * @return Length of section
   */
  size_t (((prefix)))_section_strlen(const (((m.type_name))) *msg, size_t section);
  ((*- elif f.encoding == "multipart" or f.encoding == "double_null_terminated" *))
  /**
   * Return the number of sections in (((comment_name)))
   *
   * @param msg (((m.type_name))) instance
   * @return Number of sections in string
   */
  size_t (((prefix)))_count_sections(const (((m.type_name))) *msg);

  /**
   * Add a section to (((comment_name)))
   *
   * The specified string will be appended to the field as a new section. If the new section would end up overflowing the maximum encoded length of this field the string will not be changed and this function will return false
   *
   * @param msg (((m.type_name))) instance 
   * @param new_str New string
   * @return true on success, false otherwise
   */
  bool (((prefix)))_add_section( (((-m.type_name))) *msg, const char *new_str);

  /**
   * Add a section to (((comment_name))) with printf style formatting
   *
   * A new section will be added to the field according to the specified printf style format string and arguments. If the operation would end up overflowing the maximum size of this field in wire encoding the existing contents will be unmodified and this function will return false.
   *
   * @param msg (((m.type_name))) instance
   * @param fmt printf style format string
   * @return true on success, false otherwise
   */
  bool (((prefix)))_add_section_printf( (((-m.type_name))) *msg, const char *fmt, ...) SBP_ATTR_FORMAT(2,3);

  /**
   * Add a section to (((comment_name))) with printf style formatting
   *
   * Identical to #(((prefix)))_add_section_printf except it takes a va_list argument
   *
   * @param msg (((m.type_name))) instance
   * @param fmt printf style format string
   * @param ap Argument list
   * @return true on success, false otherwise
   */
  bool (((prefix)))_add_section_vprintf( (((-m.type_name))) *msg, const char *fmt, va_list ap);

  /**
   * Append a string to the last section in (((comment_name)))
   *
   * If the field is currently empty this function will behave exactly like #(((prefix)))_add_section
   *
   * If the field already contains one or more sections the given string will be appended on to the last section in the string. 
   *
   * If the operation would end up overflowing the maximum size of this field in wire encoding the existing contents will be unmodified and this function will return false.
   *
   * @param msg (((m.type_name))) instance
   * @param str New string
   * @return true on success, false otherwise
   */
  bool (((prefix)))_append( (((-m.type_name))) *msg, const char *str);

  /**
   * Append a string to the last section in (((comment_name))) with printf style formatting
   *
   * If the field is currently empty this function will behave exactly like #(((prefix)))_add_section_printf
   *
   * If the field already contains one or more sections the given string will be appended on to the last section in the string.
   *
   * If the operation would end up overflowing the maximum size of this field in wire encoding the existing contents will be unmodified and this function will return false.
   *
   * @param msg (((m.type_name))) instance
   * @param fmt printf style format string
   * @return true on success, false otherwise
   */
  bool (((prefix)))_append_printf( (((-m.type_name))) *msg, const char *fmt, ...) SBP_ATTR_FORMAT(2,3);

  /**
   * Append a string to the last section in (((comment_name))) with printf style formatting
   *
   * If the field is currently empty this function will behave exactly like #(((prefix)))_add_section_vprintf
   *
   * If the field already contains one or more sections the given string will be sppended on to the last section in the string.
   *
   * If the operation would end overflowing the maximum size of this field in wire encoding the existing contents will be unmodified and this function will return false.
   *
   * @param msg (((m.type_name))) instance
   * @param fmt printf style format string
   * @param ap Argument list
   * @return true on success, false otherwise
   */
  bool (((prefix)))_append_vprintf( (((-m.type_name))) *msg, const char *fmt, va_list ap);

  /**
   * Obtain a section from (((comment_name)))
   *
   * Returns a pointer to the given subsection in the field. Sections are 0-indexed, the \p section parameters must be less than the value returned from #(((prefix)))_count_sections.
   *
   * @param msg (((m.type_name))) instance
   * @param section Section number
   * @return Pointer to C string, NULL on error
   */
  const char *(((prefix)))_get_section(const (((m.type_name))) *msg, size_t section);

  /**
   * Obtain the length of a section in (((comment_name)))
   *
   * The returned value does not include the NULL terminator.
   *
   * If the given section does not exist 0 is returned.
   *
   * @param msg (((m.type_name))) instance
   * @param section Section number
   * @return Length of section
   */
  size_t (((prefix)))_section_strlen(const (((m.type_name))) *msg, size_t section);
  ((*- else *))
  **** INVALID STRING ENCODING : (((f.encoding))) ****
  ((* endif *))
  ((*- endif *))
  ((*- endif *))
((*- endfor *))

/**
 * Get encoded size of an instance of (((m.type_name)))
 *
 * @param msg (((m.type_name))) instance
 * @return Length of on-wire representation
 */
size_t (((m.prefix)))_encoded_len(const (((m.type_name))) *msg);

/**
 * Encode an instance of (((m.type_name))) to wire representation
 *
 * This function encodes the given instance in to the user provided buffer. The buffer provided to this function must be large enough to store the encoded message otherwise it will return SBP_ENCODE_ERROR without writing anything to the buffer.
 *
 * Specify the length of the destination buffer in the \p len parameter. If non-null the number of bytes written to the buffer will be returned in \p n_written.
 *
 * @param buf Destination buffer
 * @param len Length of \p buf
 * @param n_written If not null, on success will be set to the number of bytes written to \p buf
 * @param msg Instance of (((m.type_name))) to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 (((m.prefix)))_encode(uint8_t *buf, uint8_t len, uint8_t *n_written, const (((m.type_name))) *msg);

/**
 * Decode an instance of (((m.type_name))) from wire representation
 *
 * This function decodes the wire representation of a (((m.type_name))) message to the given instance. The caller must specify the length of the buffer in the \p len parameter. If non-null the number of bytes read from the buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the (((m.type_name))) instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 (((m.prefix)))_decode(const uint8_t *buf, uint8_t len, uint8_t *n_read, (((m.type_name))) *msg);
((*- if m.is_real_message *))
/**
 * Send an instance of (((m.type_name))) with the given write function
 *
 * An equivalent of #sbp_send_message which operates specifically on (((m.type_name)))
 *
 * The given message will be encoded to wire representation and passed in to the given write function callback. The write callback will be called several times for each invocation of this function.
 *
 * @param s SBP state
 * @param sender_id SBP sender id
 * @param msg Message to send
 * @param write Write function
 * @param SBP_OK on success, or other libsbp error code
 */
s8 (((m.prefix)))_send(sbp_state_t  *s, u16 sender_id, const (((m.type_name))) *msg, sbp_write_fn_t write);
((*- endif *))

/**
 * Compare two instances of (((m.type_name)))
 *
 * The two instances will be compared and a value returned consistent with the return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p b
 * A value greater than 0 will be returned if \p b is considered to be greater than \p b
 *
 * @param a (((m.type_name))) instance
 * @param b (((m.type_name))) instance
 * @return 0, <0, >0
 */
int (((m.prefix)))_cmp(const (((m.type_name))) *a, const (((m.type_name))) *b);

#ifdef __cplusplus
  }

static inline bool operator==(const (((m.type_name))) &lhs, const (((m.type_name))) &rhs) {
  return (((m.prefix)))_cmp(&lhs, &rhs) == 0;
}

static inline bool operator!=(const (((m.type_name))) &lhs, const (((m.type_name))) &rhs) {
  return (((m.prefix)))_cmp(&lhs, &rhs) != 0;
}

static inline bool operator<(const (((m.type_name))) &lhs, const (((m.type_name))) &rhs) {
  return (((m.prefix)))_cmp(&lhs, &rhs) < 0;
}

static inline bool operator<=(const (((m.type_name))) &lhs, const (((m.type_name))) &rhs) {
  return (((m.prefix)))_cmp(&lhs, &rhs) <= 0;
}

static inline bool operator>(const (((m.type_name))) &lhs, const (((m.type_name))) &rhs) {
  return (((m.prefix)))_cmp(&lhs, &rhs) > 0;
}

static inline bool operator>=(const (((m.type_name))) &lhs, const (((m.type_name))) &rhs) {
  return (((m.prefix)))_cmp(&lhs, &rhs) >= 0;
}

#endif

#endif /* LIBSBP_V4_(((pkg_name|upper)))_(((m.name|upper)))_H */


