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
 * @file double_null_terminated.h
 *
 * Handles encoding and decoding of double NULL terminated strings.
 *
 * In SBP double NULL terminated strings are rather similar to multipart strings
 * except they have an extra NULL terminator at the end of a sequence. A double
 * NULL terminated string is not a single C style string, rather it is a
 * collection of substrings (or sections) each separated on the wire with a NULL
 * terminator with the end of sequence being marked by an extra NULL terminator.
 *
 * For example, a double NULL terminated string might contain 3 sections -
 * "one", "two", and "three". On the wire this string would be encoded as
 *
 * one\0two\0three\0\0
 *
 * for a total of 15 bytes.
 *
 * A double NULL terminated string might contain no sections in which case on
 * the wire it would consists of just two NULL terminators with no printable
 * text.
 *
 * Since C strings are NULL terminated it isn't possible for a consumer of
 * libsbp to interact directly with the wire encoding of a double NULL
 * terminated string without performing some sort of tokenization on the input
 * or carefully constructing the output.
 *
 * The functions in this file handle all aspects of interacting with a double
 * NULL terminated string for a consumer of libsbp, including all encoding and
 * decoding considerations.
 *
 * When processing an incoming double NULL terminated string individual sections
 * can be retrieved from the double NULL terminated string object with
 * #sbp_double_null_terminated_string_get_section. The returned string will
 * corrospond to the requested section number and will always be represented in
 * C format. For example when operating on the string from the first example
 * above, calling `sbp_double_null_terminated_string_get_section(&string,
 * maxlen, 0)` will return the C string "one". Calling
 * `sbp_double_null_terminated_string_get_section(&string, maxlen, 1)`
 * will return "two" and so on.
 *
 * Other characteristics of the string such as the number of sections, the
 * length of any given section, or the total encoded length of the double NULL
 * terminated string can be queried at will.
 *
 * When constructing a double NULL terminated string new sections can be added
 * with one of the "add" functions. All query functions can be used as described
 * above.
 */

#ifndef LIBSBP_INTERNAL_V4_STRING_DOUBLE_NULL_TERMINATED_H
#define LIBSBP_INTERNAL_V4_STRING_DOUBLE_NULL_TERMINATED_H

#include <stdarg.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#include <libsbp/common.h>
#include <libsbp/internal/v4/common.h>
#include <libsbp/v4/string/sbp_string.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Initialize a double null terminated string
 *
 * @param s string
 */
void sbp_double_null_terminated_string_init(sbp_string_t *s);

/**
 * Check a double null terminated string for validity
 *
 * A double null terminated string is considered valid if it meets all the
 * following criteria:
 * - `s->encoded_len` is less than or equal to \p maxlen
 * - `s->encoded_len` is greater than or equal to 2
 * - The final 2 bytes in `s->data` are both NULL
 *
 * All other functions which deal with double NULL terminated strings will first
 * check for validity before proceeding. If the given string object is currently
 * considered invalid mutator functions (eg:
 * #sbp_double_null_terminated_string_add_section,
 * #sbp_double_null_terminated_string_append) will first initialize the string
 * object to an empty state before performing their task. Accessor functions
 * (eg: #sbp_double_null_terminated_string_get_section,
 * #sbp_double_null_terminated_string_count_sections) will return 0, NULL, or
 * whatever value they would normally return for an initialized but otherwise
 * empty double NULL terminated string.
 *
 * Attempting to encode an invalid double NULL terminated string will result in
 * 2 NULL terminator characters being written to the destination (assuming there
 * is sufficient space in the destination buffer).
 *
 * @param s string
 * @param maxlen Maximum encoded length
 * @return true is the string is valid for encoding, false otherwise
 */
bool sbp_double_null_terminated_string_valid(const sbp_string_t *s,
                                             size_t maxlen);

/**
 * Compare two double null terminated strings
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
int sbp_double_null_terminated_string_strcmp(const sbp_string_t *a,
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
size_t sbp_double_null_terminated_string_encoded_len(const sbp_string_t *s,
                                                     size_t maxlen);

/**
 * Get available space in a double null terminated string
 *
 * The return value is the maximum number of bytes that can be added to the
 * string before it exceeds the maximum encoded length
 *
 * @param s string
 * @param maxlen Maximum encoded length
 * @return Available space
 */
size_t
sbp_double_null_terminated_string_space_remaining(const sbp_string_t *s,
                                                  size_t maxlen);

/**
 * Count sections in a double null terminated string
 *
 * If the string is invalid the return value is 0
 *
 * @param s string
 * @param maxlen Maximum encoded length
 * @return Number of sections
 */
size_t sbp_double_null_terminated_string_count_sections(const sbp_string_t *s,
                                                        size_t maxlen);

/**
 * Add section to a double null terminated string
 *
 * If the current string's encoded length is less than the maximum encoded
 * length the function will clear off any previous data before attempting to
 * add in a new section.
 *
 * If the resulting string would be greater than the maximum encoded length the
 * string will not be modified and false will be returned.
 *
 * @param s string
 * @param maxlen Maximum encoded length
 * @param str New section string
 * @return true on success, false otherwise
 */
bool sbp_double_null_terminated_string_add_section(sbp_string_t *s,
                                                   size_t maxlen,
                                                   const char *str);

/**
 * Add a section to a double null terminated string with printf style formatting
 *
 * If the current string's encoded length is less than the maximum encoded
 * length the function will clear off any previous data before attempting to
 * add in a new section.
 *
 * If the resulting string would be greater than the maximum encoded length the
 * string will not be modified and false will be returned.
 *
 * @param s string
 * @param maxlen Maximum encoded length
 * @param fmt Printf style format specification
 * @param ap Argument list
 * @return true on success, false otherwise
 */
bool sbp_double_null_terminated_string_add_section_vprintf(
    sbp_string_t *s, size_t maxlen, const char *fmt, va_list ap)
    SBP_ATTR_VFORMAT(3);

/**
 * Append to the last section of a double null terminated string
 *
 * If the current string's encoded length is less than the maximum encoded
 * length the function will clear off any previous data before attempting to
 * add in a new section.
 *
 * If the resulting string would be greater than the maximum encoded length the
 * string will not be modified and false will be returned.
 *
 * If the string is currently invalid it will be initialized and this function
 * will behave identically to #sbp_double_null_terminated_string_add_section
 * operating on an empty string
 *
 * @param s string
 * @param maxlen Maximum encoded length
 * @param new_str String to append
 * @return true on success, false otherwise
 */
bool sbp_double_null_terminated_string_append(sbp_string_t *s,
                                              size_t maxlen,
                                              const char *new_str);

/**
 * Append to the last section of a double null terminated string with printf
 * style formatting
 *
 * The newly formatted string will be appended to the last section in the double
 * null terminated string.
 *
 * If the current string's encoded length is less than the maximum encoded
 * length the function will clear off any previous data before attempting to
 * add in a new section.
 *
 * If the resulting string would be greater than the maximum encoded length the
 * string will not be modified and false will be returned.
 *
 * If the string is currently invalid it will be initialized and this function
 * will behave identically to
 * #sbp_double_null_terminated_string_add_section_vprintf operating on an empty
 * string
 *
 * @param s string
 * @param maxlen Maximum encoded length
 * @param fmt Printf style format specification
 * @param ap Argument list
 * @return true on success, false otherwise
 */
bool sbp_double_null_terminated_string_append_vprintf(sbp_string_t *s,
                                                      size_t maxlen,
                                                      const char *fmt,
                                                      va_list ap)
    SBP_ATTR_VFORMAT(3);

/**
 * Retrive a section from a double null terminated string
 *
 * The sections in a double null terminated string are 0-indexed.
 *
 * If the string is invalid NULL is returned.
 *
 * If the requested section is greater than the number of sections in the string
 * NULL is returned
 *
 * @param s string
 * @param maxlen Maximum encoded length
 * @param section Section number
 * @return Requested section, or NULL
 */
const char *sbp_double_null_terminated_string_get_section(
    const sbp_string_t *s, size_t maxlen, size_t section);

/**
 * Get length of a section in a double null terminated string
 *
 * The sections in a double null terminated string are 0-indexed.
 *
 * If the string is invalid 0 is returned.
 *
 * If the requested section is greater than the number of sections in the string
 * 0 is returned.
 *
 * @param s string
 * @param maxlen Maximum encoded length
 * @param section Section number
 * @return Length of section
 */
size_t sbp_double_null_terminated_string_section_strlen(const sbp_string_t *s,
                                                        size_t maxlen,
                                                        size_t section);

/**
 * Encode a double null terminated string to a buffer
 *
 * If the string is invalid or there is not enough space in the destination
 * buffer to hold the string false will be returned.
 *
 * @param s string
 * @param maxlen Maximum encoded length
 * @param ctx Encode context
 * @return true on success, false otherwise
 */
bool sbp_double_null_terminated_string_encode(const sbp_string_t *s,
                                              size_t maxlen,
                                              sbp_encode_ctx_t *ctx);

/**
 * Decode a double null terminated string from a buffer
 *
 * If the source buffer does not contain a valid double null terminated string
 * no data will be read and false will be returned
 *
 * This function will consume all remaining data in the source buffer.
 *
 * @param s string
 * @param maxlen Maximum encoded length
 * @param ctx Decode context
 * @return true on success, false otherwise
 */
bool sbp_double_null_terminated_string_decode(sbp_string_t *s,
                                              size_t maxlen,
                                              sbp_decode_ctx_t *ctx);

#ifdef __cplusplus
}
#endif

#endif
