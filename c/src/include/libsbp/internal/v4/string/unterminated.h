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
 * @file unterminated.h
 *
 * Handles encoding and decoding of unterminated strings.
 *
 * In SBP an unterminated string is a sequence of characters without a NULL
 * terminator to indicate the end of the string. Unterminated strings can only
 * appear at the end of an SBP payload, their length is indicated by the
 * remaining length of payload when processing incoming data.
 *
 * For example, the string "text" would be represented on the wire as
 *
 * text
 *
 * for a total of 4 bytes
 *
 * Since C strings require a NULL terminator it isn't possible for a consumer of
 * SBP to interact directly with the on-wire encoding of an unterminated string
 * since it's missing the NULL terminator. Instead the incoming unterminated
 * string must be copied to some other user provided buffer and a NULL
 * terminator added before it can be processed.
 *
 * The functions in this file provide a convenient way to interact with strings
 * which don't have a NULL terminator on the wire. These functions ensure that
 * strings are always in correct C string representation for the consumer of
 * libsbp and will handle the adding or removal of NULL terminators when
 * encoding or decoding the string to the wire format.
 *
 * That value of an unterminated string can be retrieved with
 * #sbp_unterminated_string_get, and set with one of the "set" functions.
 * Characteristics of the string can be queried with a number of different
 * funtions.
 */

#ifndef LIBSBP_INTERNAL_V4_STRING_UNTERMINATED_H
#define LIBSBP_INTERNAL_V4_STRING_UNTERMINATED_H

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
 * Initialize an unterminated string
 *
 * @param s string
 */
void sbp_unterminated_string_init(sbp_string_t *s);

/**
 * Check an unterminated string for validity
 *
 * An unterminated string is considered valid if:
 * - `s->encoded_len` is less than or equal to \p maxlen
 *
 * AND one of the following criteria is met:
 * - `s->data[s->encoded_len]` (the first byte past the end of the encoded
 * string) is NULL (this criteria ensures compatibility with C standard library
 * string functions)
 * - `s->data[s->encoded_len-1]` is NULL (this criteria copes with receiving a
 * string from the wire representations which erroneously contains a NULL
 * terminator)
 *
 * All other functions which deal with unterminated strings will first check for
 * validity before proceeding. If the given string object is currently
 * considered invalid mutator functions (eg: #sbp_unterminated_string_set,
 * #sbp_unterminated_string_append) will first initialize the string object to
 * an empty state before performing their task. Accessor functions (eg:
 * #sbp_unterminated_string_get, #sbp_unterminated_string_strlen) will return 0,
 * NULL, or whatever value they would normally return for an initialized but
 * otherwise empty NULL terminated string.
 *
 * Attempting to encode an invalid unterminated string will result in no data
 * being written to the destination.
 *
 * @param s string
 * @param maxlen Maximum encoded length
 * @return true if valid, false otherwise
 */
bool sbp_unterminated_string_valid(const sbp_string_t *s,
                                   size_t maxlen);

/**
 * Compare two unterminated string
 *
 * The return value has the same definition as C standard library comparison
 * functions such as memcmp, strcmp
 *
 * An invalid string will be considered as less than a valid string
 *
 * @param a unterminated string
 * @param b unterminated string
 * @param maxlen Maximum encoded length
 * @return Comparison result
 */
int sbp_unterminated_string_strcmp(const sbp_string_t *a, const sbp_string_t *b,
                                   size_t maxlen);

/**
 * Get encoded length of an unterminated string
 *
 * If the string is invalid the returned value is 0
 *
 * @param s string
 * @param maxlen Maximum encoded length
 * @return Encoded length
 */
size_t sbp_unterminated_string_encoded_len(const sbp_string_t *s,
                                           size_t maxlen);

/**
 * Get available space in an unterminated string
 *
 * The return value is the maximum number of bytes that can be added to the
 * string without exceeding the maximum encoded length
 *
 * @param s string
 * @param maxlen Maximum encoded length
 * @return Available space
 */
size_t sbp_unterminated_string_space_remaining(const sbp_string_t *s,
                                               size_t maxlen);

/**
 * Get length of an unterminated string.
 *
 * This value is always equal to #sbp_unterminated_string_encoded_len
 *
 * @param s string
 * @param maxlen Maximum encoded length
 * @return String length
 */
size_t sbp_unterminated_string_strlen(const sbp_string_t *s,
                                      size_t maxlen);

/**
 * Set an unterminated string from a raw buffer
 *
 * If the should_trunc parameter is true, and new string contents are larger than
 * can be stored, then as much as possible will be written from new_str to s
 *
 * If the should_trunc parameter is false, and new string contents are larger than
 * can be stored, the string will not be modified and false will be returned
 *
 * @param s string
 * @param maxlen Maximum encoded length
 * @param should_trunc Whether the new_str should be truncated to fit in s
 * @param n_written If not null, on success will be set to the number of bytes
 * written to s
 * @param new_buf New buffer contents
 * @param new_buf_len Length of the new buffer, not including NULL terminator (if present)
 * @return Number of characters written from new_buf to s
 */
bool sbp_unterminated_string_set_raw(sbp_string_t *s, size_t maxlen,
                                      bool should_trunc, size_t *n_written, const char *new_buf,
                                      size_t new_buf_len);

/**
 * Set an unterminated string
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
bool sbp_unterminated_string_set(sbp_string_t *s, size_t maxlen,
                                      bool should_trunc, size_t *n_written, const char *new_str);
/**
 * Set an unterminated string with printf style formatting
 *
 * If the new string would be greater than the maximum encoded length, and
 * should trunc is set to false, the original contents will not be modified and
 * false will be returned. Otherwise, if should trunc is set true, the new
 * string will be truncated so that it can fit in s.
 *
 * @param s string
 * @param maxlen Maximum encoded length
 * @param should_trunc Whether the new_str should be truncated to fit in s
 * @param n_written If not null, on success will be set to the number of bytes
 * written to s
 * @param fmt printf style format specification
 * @param ap Argument list
 * @return true on success, false otherwise
 */
bool sbp_unterminated_string_vprintf(sbp_string_t *s, size_t maxlen, bool should_trunc, size_t *n_written,
                                     const char *fmt, va_list ap)
    SBP_ATTR_VFORMAT(5);

/**
 * Append an unterminated string
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
bool sbp_unterminated_string_append(sbp_string_t *s, size_t maxlen,
                                    const char *new_str);

/**
 * Append to an unterminated string will printf style formatting
 *
 * If the current string's encoded length is less than the maximum encoded
 * length the function will clear off any previous data before attempting to
 * add in a new section.
 *
 * If the new string would be greater than the maximum encoded length, and
 * should trunc is set to false, the original contents will not be modified and
 * false will be returned. Otherwise, if should trunc is set true, the new
 * string will be truncated so that it can fit in s.
 *
 * @param s string
 * @param maxlen Maximum encoded length
 * @param should_trunc Whether the new_str should be truncated to fit in s
 * @param n_written If not null, on success will be set to the number of bytes
 * written to s
 * @param fmt printf style format specification
 * @param ap Argument list
 * @return true on success, false otherwise
 */
bool sbp_unterminated_string_append_vprintf(sbp_string_t *s,
                                            size_t maxlen, bool should_trunc, size_t *n_written,
                                            const char *fmt, va_list ap)
    SBP_ATTR_VFORMAT(5);

/**
 * Get contents of an unterminated
 *
 * If the string is invalid NULL will be returned
 *
 * @param s string
 * @param maxlen Maximum encoded length
 * @return String contents or NULL
 */
const char *sbp_unterminated_string_get(const sbp_string_t *s,
                                        size_t maxlen);

/**
 * Encode an unterminated string
 *
 * If the string is invalid or there is not enough space in the destination
 * buffer to hold the string false will be returned.
 *
 * @param s string
 * @param maxlen Maximum encoded length
 * @param ctx Encode context
 * @return true on success, false otherwise
 */
bool sbp_unterminated_string_encode(const sbp_string_t *s,
                                    size_t maxlen,
                                    sbp_encode_ctx_t *ctx);

/**
 * Decode a null terminated string.
 *
 * All available data will be consumed from the source buffer
 *
 * @param s string
 * @param maxlen Maximum encoded length
 * @param ctx Decode context
 * @return true on success, false otherwise
 */
bool sbp_unterminated_string_decode(sbp_string_t *s, size_t maxlen,
                                    sbp_decode_ctx_t *ctx);

#ifdef __cplusplus
}
#endif

#endif
