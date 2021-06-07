/*
 * Copyright (C) 2015-2018 Swift Navigation Inc.
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

#ifndef LIBSBP_NEW_(((pkg_name|upper)))_MESSAGES_H
#define LIBSBP_NEW_(((pkg_name|upper)))_MESSAGES_H

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

#ifdef __cplusplus
  extern "C" {
#endif

struct sbp_state;


((* for m in msgs *))
((*- set msg_type = m.name|convert_unpacked *))
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

((*- for f in m.fields *))
  ((*- if f.packing == "packed-string" *))
  ((*- set prefix = msg_type + "_" + f.name *))
  ((*- set string_type = "sbp_" + f.encoding + "_string_t" *))
  ((*- if f.packing == "packed-string" *))
  void (((prefix)))_init( (((-string_type))) *s);
  bool (((prefix)))_valid(const (((string_type))) *s);
  int (((prefix)))_strcmp(const (((string_type))) *a, const (((string_type))) *b);
  uint8_t (((prefix)))_packed_len(const (((string_type))) *s);
  uint8_t (((prefix)))_space_remaining(const (((string_type))) *s);

  ((*- if f.encoding == "unterminated" or f.encoding == "null_terminated" *))
  bool (((prefix)))_set( (((-string_type))) *s, const char *new_str);
  bool (((prefix)))_printf( (((-string_type))) *s, const char *fmt, ...) SBP_ATTR_FORMAT(2,3);
  bool (((prefix)))_vprintf( (((-string_type))) *s, const char *fmt, va_list ap);
  bool (((prefix)))_append_printf( (((-string_type))) *s, const char *fmt, ...) SBP_ATTR_FORMAT(2,3);
  bool (((prefix)))_append_vprintf( (((-string_type))) *s, const char *fmt, va_list ap);
  const char *(((prefix)))_get(const (((string_type))) *s);
  ((*- elif f.encoding == "multipart" or f.encoding == "double_null_terminated" *))
  uint8_t (((prefix)))_count_sections(const (((string_type))) *s);
  bool (((prefix)))_add_section( (((-string_type))) *s, const char *new_str);
  bool (((prefix)))_add_section_printf( (((-string_type))) *s, const char *fmt, ...) SBP_ATTR_FORMAT(2,3);
  bool (((prefix)))_add_section_vprintf( (((-string_type))) *s, const char *fmt, va_list ap);
  bool (((prefix)))_append( (((-string_type))) *s, const char *str);
  bool (((prefix)))_append_printf( (((-string_type))) *s, const char *fmt, ...) SBP_ATTR_FORMAT(2,3);
  bool (((prefix)))_append_vprintf( (((-string_type))) *s, const char *fmt, va_list ap);
  const char *(((prefix)))_get_section(const (((string_type))) *s, uint8_t section);
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
s8 sbp_send_(((msg_type)))(struct sbp_state  *s, u16 sender_id, const (((msg_type))) *msg, s32 (*write)(u8 *buff, u32 n, void *context));
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

((* endfor *))

#ifdef __cplusplus
  }

((*- for m in msgs *))
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
((*- endfor *))

#endif

#endif /* LIBSBP_NEW_(((pkg_name|upper)))_MESSAGES_H */

