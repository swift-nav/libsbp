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

#ifndef LIBSBP_INTERNAL_V4_STRING_SBP_STRNLEN_H
#define LIBSBP_INTERNAL_V4_STRING_SBP_STRNLEN_H

#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Safe version of strlen
 *
 * Up to \p max bytes will be read from \p str.
 *
 * This function returns as soon as it finds a NULL terminator. If no NULL
 * terminator is found before the maximum number of bytes have been read it will
 * return a value equal to \p max.
 *
 * Therefore a return value of \p max indicates that the string is likely
 * invalid
 *
 * @param str string
 * @param limit Max length
 * @return string length
 */
static inline size_t sbp_strnlen(const char *str, size_t limit) {
  size_t len = 0;
  while (len < limit && str[len] != 0) {
    len++;
  }
  return len;
}

#ifdef __cplusplus
}
#endif

#endif
