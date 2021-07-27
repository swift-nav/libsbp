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

#ifndef LIBSBP_INTERNAL_V4_STRING_SBP_STRING_H
#define LIBSBP_INTERNAL_V4_STRING_SBP_STRING_H

#include <stdarg.h>
#include <stdbool.h>
#include <stdint.h>

#include <libsbp/common.h>
#include <libsbp/internal/v4/common.h>
#include <libsbp/v4/string/sbp_string.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Generic string handling parameters
 */
typedef struct {
  /**
   * Test a string for validity
   */
  bool (*valid)(const sbp_string_t *s, size_t maxlen);

  /**
   * Initialize a string
   */
  void (*init)(sbp_string_t *s);

  /**
   * When #sbp_string_encode is called with an invalid source string it will
   * write this string to the output instead
   */
  const char *default_output;

  /**
   * Length of data in default_output
   */
  size_t default_output_len;

  /**
   * When decoding a string #sbp_string_decode will add a missing NULL
   * terminator to the resulting string if this flag is set to true.
   *
   * When set to false no modification will be made even if that means the
   * resulting string is invalid
   */
  bool inject_missing_terminator;
} sbp_string_params_t;

/**
 * Compare 2 string
 *
 * Each string will be tested for validity before comparison. An invalid string
 * is considered to always be less than a valid string.
 *
 * The return value has the same definition as C standard library comparison
 * functions like memcmp, strcmp
 *
 * @param a string
 * @param b string
 * @param maxlen Maximum encoded length
 * @param params string params
 */
int sbp_string_cmp(const sbp_string_t *a, const sbp_string_t *b,
                   size_t maxlen, const sbp_string_params_t *params);

/**
 * Copy exactly n bytes from str to buf.
 *
 * If the destination buffer can't store the entire source string no data will
 * be copied and false will be returned.
 *
 * @param buf destination buffer
 * @param copied On return will be set to the number of bytes copied
 * @param max Maximum number of bytes to copy
 * @param str Source string
 * @param n Number of bytes to copy from str to buf
 * @return true on success, false otherwise
 */
bool sbp_string_copy_to_buf(char *buf, size_t *copied, size_t max,
                            const char *str, size_t n);

/**
 * Printf to a buffer
 *
 * If the destination buffer can't store the entire formatted string, and
 * should_trunc is false, no data will be written and false will be returned.
 * Otherwise, if should_trunc is true, the formatted message will be truncated
 * to fit in the destination buffer.
 *
 * @param buf Destination buffer
 * @param copied On return will be set to the number of bytes written
 * @param max Maximum number of bytes to write
 * @param should_trunc Whether the formatted string should be formatted to fit
 * in the destination buffer
 * @param fmt Printf style format string
 * @param ap Argument list
 * @return true on success, false otherwise
 */
bool sbp_string_vprintf_to_buf(char *buf, size_t *copied, size_t max, bool should_trunc,
                               const char *fmt, va_list ap) SBP_ATTR_VFORMAT(5);

/**
 * Write a string to a buffer
 *
 * If the destination buffer doesn't have enough space to store the string no
 * data will be written and false returned.
 *
 * If the string is invalid then the default string will be written to the
 * buffer as specified in params
 *
 * @param s string
 * @param maxlen Maximum encoded length
 * @param ctx Encode context
 * @param params String params
 * @return true on success, false otherwise
 */
bool sbp_string_encode(const sbp_string_t *s, size_t maxlen,
                       sbp_encode_ctx_t *ctx,
                       const sbp_string_params_t *params);

/**
 * Decode a string from a buffer
 *
 * All available data in the source buffer will be consumed and copied in to the
 * destination string.
 *
 * If the resulting string would be invalid no data will be read and false will
 * be returned.
 *
 * If requested by the string params this function will append a NULL terminator
 * to the resulting string if none was available in the source buffer.
 *
 * @param s destination string
 * @param maxlen Maximum encoded length
 * @param ctx Decode context
 * @param params string params
 * @return true on success, false otherwise
 */
bool sbp_string_decode(sbp_string_t *s, size_t maxlen,
                       sbp_decode_ctx_t *ctx,
                       const sbp_string_params_t *params);

#ifdef __cplusplus
}
#endif

#endif /* LIBSBP_INTERNAL_V4_STRING_SBP_STRING_H */
