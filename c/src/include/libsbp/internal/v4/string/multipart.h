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
 * @file multipart.h
 *
 * Handles encoding and decoding of multipart strings.
 *
 * In SBP a multipart string is not a single C string but a collection of
 * smaller strings (or sections) each separated by a NULL character.
 *
 * For example, a multipart string might contain 3 sections - "one", "two", and
 * "three". On the wire this string would be encoded as
 *
 * one\0two\0three\0
 *
 * for a total of 14 bytes.
 *
 * A multipart string might contain no sections in which case on the wire it
 * would consist of just a single NULL character.
 *
 * Since C string are NULL terminated it isn't possible for a consumer of libsbp
 * to interact directly with the wire encoding of a multipart string without
 * performing some sort of tokenization on the input or carefully constructing
 * the output.
 *
 * The functions in this file handle all aspects of interacting with a multipart
 * string for a consumer of libsbp, including all encoding and decoding
 * considerations.
 *
 * When processing an incoming multipart string individual sections can be
 * retrieved from the multipart string object with
 * #sbp_multipart_string_get_section. The returned string will corrospond to the
 * requested section number and will always be represented in C format. For
 * example when operating on the string from the first example above, calling
 * #sbp_multipart_string_get_section(&string, maxlen, 0) will return
 * the C string "one". Calling #sbp_multipart_string_get_section(&string,
 * maxlen, 1) will return "two" and so on.
 *
 * Other characteristics of the string such as the number of sections, the
 * length of any given section, or the total encoded length of the multipart
 * string can be queried at will.
 *
 * When constructing a multipart string new sections can be added with one of
 * the "add" functions. All query functions can be used as described above.
 */

#ifndef LIBSBP_INTERNAL_V4_STRING_MULTIPART_H
#define LIBSBP_INTERNAL_V4_STRING_MULTIPART_H

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
 * Initialize a multipart string
 *
 * @param s string
 */
void sbp_multipart_string_init(sbp_string_t *s);

/**
 * Check a multipart string for validity
 *
 * A multipart string is considered valid if all the following critera are met:
 * - `s->encoded_len` is greater than or equal to \p maxlen
 * - The final character in `s->data` is NULL
 *
 * All other functions which deal with multipart strings will first check for
 * validity before proceeding. If the given string object is currently
 * considered invalid mutator functions (eg: #sbp_multipart_string_add_section,
 * #sbp_multipart_string_append) will first initialize the string object to an
 * empty state before performing their task. Accessor functions (eg:
 * #sbp_multipart_string_get_section, #sbp_multipart_string_count_sections) will
 * return 0, NULL, or whatever value they would normally return for an
 * initialized but otherwise empty multipart string.
 *
 * Attempting to encode an invalid multipart string will result in a single NULL
 * terminator character being written to the destination (assuming there is
 * sufficient space in the destination buffer).
 *
 * @param s string
 * @param maxlen Maximum encoded length
 * @return true is the string is valid, false otherwise
 */
bool sbp_multipart_string_valid(const sbp_string_t *s, size_t maxlen);

/**
 * Compare two multipart strings
 *
 * The return value has the same definition as C standard library comparison
 * functions such as memcmp, strcmp
 *
 * An invalid string will be considered as less than a valid string.
 *
 * @param a multipart string
 * @param b multipart string
 * @param maxlen Maximum encoded length
 * @return Comparison result
 */
int sbp_multipart_string_strcmp(const sbp_string_t *a, const sbp_string_t *b,
                                size_t maxlen);

/**
 * Get the encoded length of a multipart string
 *
 * If the string is invalid the returned value is 0
 *
 * @param s string
 * @param maxlen Maximum encoded length
 * @return Encoded length
 */
size_t sbp_multipart_string_encoded_len(const sbp_string_t *s,
                                        size_t maxlen);

/**
 * Get available space in a multipart string
 *
 * The return value is the maximum number of bytes that can be added to the
 * string before it exceeds the maximum encoded length
 *
 * @param s string
 * @param maxlen Maximum encoded length
 * @return Available space
 */
size_t sbp_multipart_string_space_remaining(const sbp_string_t *s,
                                            size_t maxlen);

/**
 * Count sections in a multipart string
 *
 * If the string is invalid the return value is 0
 *
 * @param s string
 * @param maxlen Maximum encoded length
 * @return Number of sections
 */
size_t sbp_multipart_string_count_sections(const sbp_string_t *s,
                                           size_t maxlen);

/**
 * Get length of a section in a multipart string
 *
 * The sections in a multipart string are 0-indexed.
 *
 * If the string is invalid 0 is returned.
 *
 * If the requested section is greater than the number of sections in the string
 * 0 is returned
 *
 * @param s string
 * @param maxlen Maximum encoded length
 * @param section Section number
 * @return Length of section
 */
size_t sbp_multipart_string_section_strlen(const sbp_string_t *s,
                                           size_t maxlen,
                                           size_t section);

/**
 * Add section to a multipart string
 *
 * If the current string's encoded length is greater than the maximum encoded
 * length (more generally, if the current string is considered to be invalid)
 * the function will clear off any previous data before attempting to add in a
 * new section.
 *
 * If the resulting string would be greater than the maximum encoded length the
 * string will not be modified and false will be returned
 *
 * @param s string
 * @param maxlen Maximum encoded length
 * @param str New section string
 * @return true on success, false otherwise
 */
bool sbp_multipart_string_add_section(sbp_string_t *s, size_t maxlen,
                                      const char *str);

/**
 * Add a section to a multipart string with printf style formatting
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
 * @param fmt printf style format specification
 * @param ap Argument list
 * @return true on success, false otherwise
 */
bool sbp_multipart_string_add_section_vprintf(sbp_string_t *s,
                                              size_t maxlen,
                                              const char *fmt, va_list ap)
    SBP_ATTR_VFORMAT(3);

/**
 * Append to the last section of a multipart string
 *
 * The specified string will be appended to the last section in the multipart
 * string.
 *
 * If the current string's encoded length is less than the maximum encoded
 * length the function will clear off any previous data before attempting to
 * add in a new section.
 *
 * If the resulting string would be greater than the maximum encoded length the
 * string will not be modified and false will be returned.
 *
 * If the string is currently invalid it will be initialized and this function
 * will behave identically to #sbp_multipart_string_add_section operating on an
 * empty string.
 *
 * @param s string
 * @param maxlen Maximum encoded length
 * @param new_str string to append
 * @return true on success, false otherwise
 */
bool sbp_multipart_string_append(sbp_string_t *s, size_t maxlen,
                                 const char *new_str);

/**
 * Append to the last section of a multipart string with printf style formatting
 *
 * The newly formatted string will be appended to the last section in the
 * multipart string.
 *
 * If the current string's encoded length is less than the maximum encoded
 * length the function will clear off any previous data before attempting to
 * add in a new section.
 *
 * If the resulting string would be greater than the maximum encoded length the
 * string will not be modified and false will be returned.
 *
 * If the string is currently invalid it will be initialized and this function
 * will behave identically to #sbp_multipart_string_add_section_vprintf
 * operating on an empty string
 *
 * @param s string
 * @param maxlen Maximum encoded length
 * @param fmt printf style format specification
 * @param ap Argument list
 * @return true on success, false otherwise
 */
bool sbp_multipart_string_append_vprintf(sbp_string_t *s,
                                         size_t maxlen,
                                         const char *fmt, va_list ap)
    SBP_ATTR_VFORMAT(3);

/**
 * Retrieve a section from a multipart string
 *
 * The sections in a multipart string are 0-indexed.
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
const char *sbp_multipart_string_get_section(const sbp_string_t *s,
                                             size_t maxlen,
                                             size_t section);

/**
 * Encode a multipart string to a buffer
 *
 * If the string is invalid or there is not enough space in the destination
 * buffer to hold the string false will be returned.
 *
 * @param s string
 * @param maxlen Maximum encoded length
 * @param ctx Encode context
 * @return true on success, false otherwise
 */
bool sbp_multipart_string_encode(const sbp_string_t *s, size_t maxlen,
                                 sbp_encode_ctx_t *ctx);

/**
 * Decode a multipart string froma buffer
 *
 * If the source buffer does not contain a valid multipart string no data will
 * be read and false will be returned.
 *
 * This function will consume all remaining data in the source buffer.
 *
 * @param s string
 * @param maxlen Maximum encoded length
 * @param ctx Decode context
 * @return true on success, false otherwise
 */
bool sbp_multipart_string_decode(sbp_string_t *s, size_t maxlen,
                                 sbp_decode_ctx_t *ctx);

#ifdef __cplusplus
}
#endif

#endif
