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

#ifndef LIBSBP_NEW_(((pkg_name|upper)))_(((m.name|upper)))_MESSAGES_H
#define LIBSBP_NEW_(((pkg_name|upper)))_(((m.name|upper)))_MESSAGES_H

#include <stdbool.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>
#include <endian.h>
#include <math.h>

#include <libsbp/common.h>
#include <libsbp/new/string/multipart.h>
#include <libsbp/new/string/double_null_terminated.h>
#include <libsbp/new/string/unterminated.h>
#include <libsbp/new/string/null_terminated.h>
#include <libsbp/(((pkg_name)))_macros.h>

((*- for i in include *))
#include <libsbp/new/(((i)))>
((*- endfor *))
((*- for i in sibling_include *))
#include <libsbp/new/(((i))).h>
((*- endfor *))

#ifdef __cplusplus
  extern "C" {
#endif

struct sbp_state;


((*- set msg_type = m.name|convert_unpacked *))
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
  sbp_(((f.options.encoding.value)))_string_t (((f.name)));
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
} (((msg_type)));

((* for f in m.fields *))
  ((*- if f.packing == "packed-string" *))
  ((*- set prefix = msg_type + "_" + f.name *))
  ((*- set string_type = "sbp_" + f.encoding + "_string_t" *))
  ((*- set comment_name = msg_type + "::" + f.name *))
  ((*- if f.packing == "packed-string" *))
  /**
   * Initialise (((comment_name))) to empty
   *
   * @param msg (((msg_type))) instance
   */
  void (((prefix)))_init( (((-string_type))) *s);

  /**
   * Test (((comment_name))) for validity
   *
   * @param msg (((msg_type))) instance
   * @return true is (((comment_name))) is valid for encoding purposes, false otherwise
   */
  bool (((prefix)))_valid(const (((string_type))) *s);

  /**
   * Tests 2 instances of (((comment_name))) for equality
   *
   * Returns a value with the same definitions as #strcmp from the C standard library
   *
   * @param a (((msg_type))) instance
   * @param b (((msg_type))) instance
   * @return 0 if equal, <0 if a<b, >0 if a>b
   */
  int (((prefix)))_strcmp(const (((string_type))) *a, const (((string_type))) *b);

  /**
   * Get the encoded size of (((comment_name)))
   *
   * @param msg (((msg_type))) instance
   * @return Size of (((comment_name))) in wire representation
   */
  uint8_t (((prefix)))_packed_len(const (((string_type))) *s);

  /**
   * Query (((comment_name))) for remaining space
   *
   * Returns the number of bytes (not including NULL terminator) which can be added to (((comment_name))) before it exceeds the maximum size of the field in wire representation
   *
   * @param msg (((msg_type))) instance
   * @return Maximum number of bytes that can be appended to the existing string
   */
  uint8_t (((prefix)))_space_remaining(const (((string_type))) *s);

  ((*- if f.encoding == "unterminated" or f.encoding == "null_terminated" *))
  /**
   * Set (((comment_name)))
   *
   * Erase any existing content and replace with the specified string
   *
   * This function will return true if the new string was successfully applied. If the specified string is longer than can be represented in wire encoding this function will return false
   *
   * @param msg (((msg_type))) instance
   * @param new_str New string
   * @return true on success, false otherwise
   */
  bool (((prefix)))_set( (((-string_type))) *s, const char *new_str);

  /**
   * Set (((comment_name))) with printf style formatting
   *
   * Erase any existing content and replace with the formatted string
   *
   * This function will return true if the new string was successfully applied. If the operation would end up overflowing the maximum size of this field in wire encoding the existing contents will be erased and this function will return false.
   *
   * @param msg (((msg_type))) instance
   * @param fmt printf style format string
   * @return true on success, false otherwise
   */
  bool (((prefix)))_printf( (((-string_type))) *s, const char *fmt, ...) SBP_ATTR_FORMAT(2,3);

  /**
   * Set (((comment_name))) with printf style formatting
   *
   * Identical to #(((prefix)))_printf except it takes a va_list argument
   *
   * @param msg (((msg_type))) instance
   * @param fmt printf style format string
   * @param ap Argument list
   * @return true on success, false otherwise
   */
  bool (((prefix)))_vprintf( (((-string_type))) *s, const char *fmt, va_list ap);

  /**
   * Append (((comment_name))) with printf style formatting
   *
   * The new string will be appended to the existing contents of the string (if any). If the operation would end up overflowing the maximum size of this field in wire encoding the existing contents will be unmodified and this function will return false.
   *
   * @param msg (((msg_type))) instance
   * @param fmt printf style format string
   * @return true on success, false otherwise
   */
  bool (((prefix)))_append_printf( (((-string_type))) *s, const char *fmt, ...) SBP_ATTR_FORMAT(2,3);

  /**
   * Append (((comment_name))) with printf style formatting
   *
   * Identical to #(((prefix)))_append_printf except it takes a va_list argument
   *
   * @param msg (((msg_type))) instance
   * @param fmt printf style format string
   * @param ap Argument list
   * @return true on success, false otherwise
   *
   */
  bool (((prefix)))_append_vprintf( (((-string_type))) *s, const char *fmt, va_list ap);

  /**
   * Obtain the string value from (((comment_name)))
   *
   * @param msg (((msg_type))) instance
   * @return String contents
   */
  const char *(((prefix)))_get(const (((string_type))) *s);

  /**
   * Obtain the length of (((comment_name)))
   *
   * The returned value does not include the NULL terminator.
   *
   * @param msg (((msg_type))) instance
   * @return Length of section
   */
  uint8_t (((prefix)))_section_strlen(const (((string_type))) *s, uint8_t section);
  ((*- elif f.encoding == "multipart" or f.encoding == "double_null_terminated" *))
  /**
   * Return the number of sections in (((comment_name)))
   *
   * @param msg (((msg_type))) instance
   * @return Number of sections in string
   */
  uint8_t (((prefix)))_count_sections(const (((string_type))) *s);

  /**
   * Add a section to (((comment_name)))
   *
   * The specified string will be appended to the field as a new section. If the new section would end up overflowing the maximum encoded length of this field the string will not be changed and this function will return false
   *
   * @param msg (((msg_type))) instance 
   * @param new_str New string
   * @return true on success, false otherwise
   */
  bool (((prefix)))_add_section( (((-string_type))) *s, const char *new_str);

  /**
   * Add a section to (((comment_name))) with printf style formatting
   *
   * A new section will be added to the field according to the specified printf style format string and arguments. If the operation would end up overflowing the maximum size of this field in wire encoding the existing contents will be unmodified and this function will return false.
   *
   * @param msg (((msg_type))) instance
   * @param fmt printf style format string
   * @return true on success, false otherwise
   */
  bool (((prefix)))_add_section_printf( (((-string_type))) *s, const char *fmt, ...) SBP_ATTR_FORMAT(2,3);

  /**
   * Add a section to (((comment_name))) with printf style formatting
   *
   * Identical to #(((prefix)))_add_section_printf except it takes a va_list argument
   *
   * @param msg (((msg_type))) instance
   * @param fmt printf style format string
   * @param ap Argument list
   * @return true on success, false otherwise
   */
  bool (((prefix)))_add_section_vprintf( (((-string_type))) *s, const char *fmt, va_list ap);

  /**
   * Append a string to the last section in (((comment_name)))
   *
   * If the field is currently empty this function will behave exactly like #(((prefix)))_add_section
   *
   * If the field already contains one or more sections the given string will be appended on to the last section in the string. 
   *
   * If the operation would end up overflowing the maximum size of this field in wire encoding the existing contents will be unmodified and this function will return false.
   *
   * @param msg (((msg_type))) instance
   * @param str New string
   * @return true on success, false otherwise
   */
  bool (((prefix)))_append( (((-string_type))) *s, const char *str);

  /**
   * Append a string to the last section in (((comment_name))) with printf style formatting
   *
   * If the field is currently empty this function will behave exactly like #(((prefix)))_add_section_printf
   *
   * If the field already contains one or more sections the given string will be appended on to the last section in the string.
   *
   * If the operation would end up overflowing the maximum size of this field in wire encoding the existing contents will be unmodified and this function will return false.
   *
   * @param msg (((msg_type))) instance
   * @param fmt printf style format string
   * @return true on success, false otherwise
   */
  bool (((prefix)))_append_printf( (((-string_type))) *s, const char *fmt, ...) SBP_ATTR_FORMAT(2,3);

  /**
   * Append a string to the last section in (((comment_name))) with printf style formatting
   *
   * If the field is currently empty this function will behave exactly like #(((prefix)))_add_section_vprintf
   *
   * If the field already contains one or more sections the given string will be sppended on to the last section in the string.
   *
   * If the operation would end overflowing the maximum size of this field in wire encoding the existing contents will be unmodified and this function will return false.
   *
   * @param msg (((msg_type))) instance
   * @param fmt printf style format string
   * @param ap Argument list
   * @return true on success, false otherwise
   */
  bool (((prefix)))_append_vprintf( (((-string_type))) *s, const char *fmt, va_list ap);

  /**
   * Obtain a section from (((comment_name)))
   *
   * Returns a pointer to the given subsection in the field. Sections are 0-indexed, the \p section parameters must be less than the value returned from #(((prefix)))_count_sections.
   *
   * @param msg (((msg_type))) instance
   * @param section Section number
   * @return Pointer to C string, NULL on error
   */
  const char *(((prefix)))_get_section(const (((string_type))) *s, uint8_t section);

  /**
   * Obtain the length of a section in (((comment_name)))
   *
   * The returned value does not include the NULL terminator.
   *
   * If the given section does not exist 0 is returned.
   *
   * @param msg (((msg_type))) instance
   * @param section Section number
   * @return Length of section
   */
  uint8_t (((prefix)))_section_strlen(const (((string_type))) *s, uint8_t section);
  ((*- else *))
  **** INVALID STRING ENCODING : (((f.encoding))) ****
  ((* endif *))
  ((*- endif *))
  ((*- endif *))
((*- endfor *))

/**
 * Get encoded size of an instance of (((msg_type)))
 *
 * @param msg (((msg_type))) instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_(((msg_type)))(const (((msg_type))) *msg);

/**
 * Encode an instance of (((msg_type))) to wire representation
 *
 * This function encodes the given instance in to the user provided buffer. The buffer provided to this function must be large enough to store the encoded message otherwise it will return SBP_ENCODE_ERROR without writing anything to the buffer.
 *
 * Specify the length of the destination buffer in the \p len parameter. If non-null the number of bytes written to the buffer will be returned in \p n_written.
 *
 * @param buf Destination buffer
 * @param len Length of \p buf
 * @param n_written If not null, on success will be set to the number of bytes written to \p buf
 * @param msg Instance of (((msg_type))) to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_(((msg_type)))(uint8_t *buf, uint8_t len, uint8_t *n_written, const (((msg_type))) *msg);

/**
 * Decode an instance of (((msg_type))) from wire representation
 *
 * This function decodes the wire representation of a (((msg_type))) message to the given instance. The caller must specify the length of the buffer in the \p len parameter. If non-null the number of bytes read from the buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the (((msg_type))) instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_(((msg_type)))(const uint8_t *buf, uint8_t len, uint8_t *n_read, (((msg_type))) *msg);
((*- if m.is_real_message *))
/**
 * Send an instance of (((msg_type))) with the given write function
 *
 * An equivalent of #sbp_send_message which operates specifically on (((msg_type)))
 *
 * The given message will be encoded to wire representation and passed in to the given write function callback. The write callback will be called several times for each invocation of this function.
 *
 * @param s SBP state
 * @param sender_id SBP sender id
 * @param msg Message to send
 * @param write Write function
 * @param SBP_OK on success, or other libsbp error code
 */
s8 sbp_send_(((msg_type)))(struct sbp_state  *s, u16 sender_id, const (((msg_type))) *msg, sbp_write_fn_t write);
((*- endif *))

/**
 * Compare two instances of (((msg_type)))
 *
 * The two instances will be compared and a value returned consistent with the return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p b
 * A value greater than 0 will be returned if \p b is considered to be greater than \p b
 *
 * @param a (((msg_type))) instance
 * @param b (((msg_type))) instance
 * @return 0, <0, >0
 */
int sbp_cmp_(((msg_type)))(const (((msg_type))) *a, const (((msg_type))) *b);

#ifdef __cplusplus
  }

((*- set msg_type = m.name|convert_unpacked *))
static inline bool operator==(const (((msg_type))) &lhs, const (((msg_type))) &rhs) {
  return sbp_cmp_(((msg_type)))(&lhs, &rhs) == 0;
}

static inline bool operator!=(const (((msg_type))) &lhs, const (((msg_type))) &rhs) {
  return sbp_cmp_(((msg_type)))(&lhs, &rhs) != 0;
}

static inline bool operator<(const (((msg_type))) &lhs, const (((msg_type))) &rhs) {
  return sbp_cmp_(((msg_type)))(&lhs, &rhs) < 0;
}

static inline bool operator<=(const (((msg_type))) &lhs, const (((msg_type))) &rhs) {
  return sbp_cmp_(((msg_type)))(&lhs, &rhs) <= 0;
}

static inline bool operator>(const (((msg_type))) &lhs, const (((msg_type))) &rhs) {
  return sbp_cmp_(((msg_type)))(&lhs, &rhs) > 0;
}

static inline bool operator>=(const (((msg_type))) &lhs, const (((msg_type))) &rhs) {
  return sbp_cmp_(((msg_type)))(&lhs, &rhs) >= 0;
}

#endif

#endif /* LIBSBP_NEW_(((pkg_name|upper)))_MESSAGES_H */

