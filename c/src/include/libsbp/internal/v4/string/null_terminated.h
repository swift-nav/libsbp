/*
 * Copyright (C) 2021 Swift Navigation Inc.
 * Contact: Swift Navigation <dev@swift-nav.com>
 *
 * This source is subject to the license found in the file 'LICENSE' which must
 * be be distributed together with this source. All other rights reserved.
 *
 * THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
 * EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
 */

/**
 * @file null_terminated.h
 *
 * Handles encoding and deecoding of NULL terminated strings.
 *
 * In SBP a NULL terminated string has the same definition as string in the C
 * language. On the wire it is a sequence of characters with a NULL character to
 * indicate the end of the string.
 *
 * For example the string "text" would be represented on the wire as
 *
 * text\0
 *
 * for a total of 5 bytes.
 *
 * While it is possible for a consumer of libsbp to interact directly with the
 * on-wire encoding of a NULL terminated strings these functions exist for
 * harmony with the other string encodings in SBP.
 *
 * The value of a NULL terminated string can be retrieved with
 * #sbp_null_terminated_string_get, and set with one of the "set" functions.
 * Characteristics of the string can be queried with a number of different
 * functions.
 */

#ifndef LIBSBP_INTERNAL_V4_STRING_NULL_TERMINATED_H
#define LIBSBP_INTERNAL_V4_STRING_NULL_TERMINATED_H

#include <stdarg.h>
#include <stdbool.h>
#include <stddef.h>

#include <libsbp/common.h>
#include <libsbp/internal/v4/common.h>
#include <libsbp/v4/string/sbp_string.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Initialize a null terminated string
 *
 * @param s string
 */
void sbp_null_terminated_string_init(sbp_string_t *s);

/**
 * Check a null terminated string for validity
 *
 * A null terminated string is considered valid if it meets all the following
 * criteria:
 * - `s->encoded_len` is less than or equal to \p maxlen
 * - `s->encoded_len` is greater than or equal to 1
 * - The final byte in `s->data` is NULL
 *
 * All other functions which deal with NULL terminated strings will first check
 * for validity before proceeding. If the given string object is currently
 * considered invalid mutator functions (eg: #sbp_null_terminated_string_set,
 * #sbp_null_terminated_string_append) will first initialize the string object
 * to an empty state before performing their task. Accessor functions (eg:
 * #sbp_null_terminated_string_get, #sbp_null_terminated_string_strlen) will
 * return 0, NULL, or whatever value they would normally return for an
 * initialized but otherwise empty NULL terminated string.
 *
 * Attempting to encode an invalid NULL terminated string will result in a
 * single NULL character being written to the destination (assuming there is
 * sufficient space in the destination buffer).
 *
 * @param s string
 * @param maxlen Maximum encoded length
 * @return true if valid, false otherwise
 */
bool sbp_null_terminated_string_valid(const sbp_string_t *s,
                                      size_t maxlen);

/**
 * Compare two null terminated strings
 *
 * The return value has the same definition as C standard library comparison
 * functions such as memcmp, strcmp
 *
 * An invalid string will be considered as less than a valid string.
 *
 * @param a string
 * @param b string
 * @param maxlen Maximum encoded length
 * @return Comparison result
 */
int sbp_null_terminated_string_strcmp(const sbp_string_t *a,
                                      const sbp_string_t *b,
                                      size_t maxlen);

/**
 * Get encoded length of a double null terminated string
 *
 * If the string is invalid the returned value is 0
 *
 * @param s string
 * @param maxlen Maximum encoded length
 * @return Encoded length
 */
size_t sbp_null_terminated_string_encoded_len(const sbp_string_t *s,
                                              size_t maxlen);

/**
 * Get available space in a double null terminated string
 *
 * The return value is the maximum number of bytes that can be added to the
 * string without exceeding the maximum encoded length
 *
 * @param s string
 * @param maxlen Maximum encoded length
 * @return Available space
 */
size_t sbp_null_terminated_string_space_remaining(const sbp_string_t *s,
                                                  size_t maxlen);

/**
 * Get length of a null terminated string, not including the NULL terminator
 *
 * @param s string
 * @param maxlen Maximum encoded length
 * @return Length of string
 */
size_t sbp_null_terminated_string_strlen(const sbp_string_t *s,
                                         size_t maxlen);

/**
 * Set a null terminated string from a raw buffer
 *
 * If the should_trunc parameter is true, and new string contents are larger
 * than can be stored, then as much as possible will be written from new_str to
 * s
 *
 * If the should_trunc parameter is false, and new string contents are larger
 * than can be stored, the string will not be modified and false will be
 * returned
 *
 * @param s string
 * @param maxlen Maximum encoded length
 * @param should_trunc Whether the new_str should be truncated to fit in s
 * @param n_written If not null, on success will be set to the number of bytes
 * written to s
 * @param new_buf New buffer contents
 * @param new_buf_len Length of the new buffer, not including NULL terminator
 * (if present)
 * @return true on success, false otherwise
 */
bool sbp_null_terminated_string_set_raw(sbp_string_t *s, size_t maxlen,
                                      bool should_trunc, size_t *n_written, const char *new_buf,
                                      size_t new_buf_len);

/**
 * Set a null terminated string
 *
 * If the should_trunc parameter is true, and new string contents are larger
 * than can be stored, then as much as possible will be written from new_str to
 * s
 *
 * If the should_trunc parameter is false, and new string contents are larger
 * than can be stored, the string will not be modified and false will be
 * returned
 *
 * @param s string
 * @param maxlen Maximum encoded length
 * @param should_trunc Whether the new_str should be truncated to fit in s
 * @param n_written If not null, on success will be set to the number of bytes
 * written to s
 * @param new_str New string contents
 * @return true on success, false otherwise
 */
bool sbp_null_terminated_string_set(sbp_string_t *s, size_t maxlen,
                                      bool should_trunc, size_t *n_written, const char *new_str);

/**
 * Set a null terminated string with printf style formatting
 *
 * If the new string would be greater than the maximum encoded length, and
 * should trunc is set to false, the original contents will not be modified and
 * false will be returned. Otherwise, if should trunc is set true, the new
 * string will be truncated so that it can fit in s.
 *
 * @param s string
 * @param maxlen Maximum encoded length
 * @param should_trunc Whether the new string should be truncated to fit in s
 * @param n_written If not null, on success will be set to the number of bytes
 * written to s
 * @param fmt print style format specification
 * @param ap Argument list
 * @return true on success, false otherwise
 */
bool sbp_null_terminated_string_vprintf(sbp_string_t *s, size_t maxlen, bool should_trunc, size_t *n_written,
                                        const char *fmt, va_list ap)
    SBP_ATTR_VFORMAT(5);

/**
 * Append to a null terminated string.
 *
 * If the current string's encoded length is less than the maximum encoded
 * length the function will clear off any previous data before attempting to
 * add in a new section.
 *
 * The new string will be appended to the current contents of this string. If
 * the resulting string would be greater than the maximum encoded length the
 * string will not be modified and false will be returned
 *
 * @param s string
 * @param maxlen Maximum encoded length
 * @param new_str String to append
 * @return true on success, false otherwise
 */
bool sbp_null_terminated_string_append(sbp_string_t *s, size_t maxlen,
                                       const char *new_str);

/**
 * Append to a null terminated string with printf style formatting
 *
 * If the current string's encoded length is less than the maximum encoded
 * length the function will clear off any previous data before attempting to add
 * in a new section.
 *
 * If the new string would be greater than the maximum encoded length, and
 * should trunc is set to false, the original contents will not be modified and
 * false will be returned. Otherwise, if should trunc is set true, the new
 * string will be truncated so that it can fit in s.
 *
 * @param s string
 * @param maxlen Maximum encoded length
 * @param should_trunc Whether the new string should be truncated to fit in s
 * @param n_written If not null, on success will be set to the number of bytes
 * written to s
 * @param fmt printf style format specification
 * @param ap Argument list
 * @return true on success, false otherwise
 */
bool sbp_null_terminated_string_append_vprintf(sbp_string_t *s,
                                               size_t maxlen, bool should_trunc, size_t *n_written,
                                               const char *fmt, va_list ap)
    SBP_ATTR_VFORMAT(5);

/**
 * Get contents
 *
 * If the string is invalid NULL will be returned
 *
 * @param s string
 * @param maxlen Maximum encoded length
 * @return String contents, or NULL
 */
const char *sbp_null_terminated_string_get(const sbp_string_t *s,
                                           size_t maxlen);

/**
 * Encode a null terminated string
 *
 * If the string is invalid or there is not enough space in the destination
 * buffer to hold the string false will be returned.
 *
 * @param s string
 * @param maxlen Maximum encoded length
 * @param ctx Encode context
 * @return true on success, false otherwise
 */
bool sbp_null_terminated_string_encode(const sbp_string_t *s,
                                       size_t maxlen,
                                       sbp_encode_ctx_t *ctx);

/**
 * Decode a null terminated string.
 *
 * Data will be read from the source buffer until either a NULL terminator is
 * found or all available data has been consumed. If the source buffer does not
 * contain a NULL terminator anywhere in the available data this function will
 * consume everything and append a null terminator.
 *
 * If the decoded string would be greater than the maximum encoded length no
 * data will be read and this function will return false.
 *
 * @param s string
 * @param maxlen Maximum encoded length
 * @param ctx Decode context
 * @return true on success, false otherwise
 */
bool sbp_null_terminated_string_decode(sbp_string_t *s, size_t maxlen,
                                       sbp_decode_ctx_t *ctx);

#ifdef __cplusplus
}
#endif

#endif
