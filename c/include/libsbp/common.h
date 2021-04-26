/*
 * Copyright (C) 2012 Swift Navigation Inc.
 * Contact: Swift Navigation <dev@swift-nav.com>
 *
 * This source is subject to the license found in the file 'LICENSE' which must
 * be be distributed together with this source. All other rights reserved.
 *
 * THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
 * EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
 */

#ifndef LIBSBP_COMMON_H
#define LIBSBP_COMMON_H

#ifndef _RUSTC_BINDGEN_
#include <stdint.h>
#include <stdbool.h>
#include <inttypes.h>
#include <assert.h>
#include <stddef.h>
#include <string.h>
#endif

static inline size_t sbp_strlen_sections(const char *str, size_t n,
                                         bool optional_final_section) {
  size_t sections = 0;
  for (size_t i = 0; i < 256; i++) {
    if (str[i] == 0) {
      sections++;
      if (sections == n) {
        return i + 1;
      }
      if (optional_final_section && sections == n - 1 && str[i + 1] == 0) {
        return i + 1;
      }
    }
  }
  assert(0 && "Invalid string");
}

static inline size_t sbp_strlen(const char *str, const char *termination) {
  if (0 == strcmp(termination, "none")) {
    return strlen(str);
  }
  if (0 == strcmp(termination, "nul")) {
    return strlen(str) + 1;
  }
  if (0 == strcmp(termination, "2-nul")) {
    for (size_t i = 0; i < 256; i++) {
      if (str[i] == 0 && str[i + 1] == 0) {
        return i + 2;
      }
    }
    assert(0 && "Invalid string");
  }
  if (0 == strcmp(termination, "2-section")) {
    return sbp_strlen_sections(str, 2, false);
  }
  if (0 == strcmp(termination, "3-section")) {
    return sbp_strlen_sections(str, 3, false);
  }
  if (0 == strcmp(termination, "4-section")) {
    return sbp_strlen_sections(str, 4, false);
  }
  if (0 == strcmp(termination, "3-4-section")) {
    return sbp_strlen_sections(str, 4, true);
  }
  assert(0 && "Unknown termination");
}

static inline size_t sbp_pack_string_sections(char *out, const char *str,
                                              size_t n,
                                              bool optional_final_section) {
  size_t sections = 0;
  for (size_t i = 0; i < 256; i++) {
    out[i] = str[i];
    if (str[i] == 0) {
      sections++;
      if (sections == n) {
        return i + 1;
      }
      if (optional_final_section && sections == n - 1 && str[i + 1] == 0) {
        return i + 1;
      }
    }
  }
  assert(0 && "Invalid string");
}

static inline size_t sbp_pack_string(uint8_t *buf, const char *str,
                                     const char *termination) {
  char *out = (char *)buf;
  if (0 == strcmp(termination, "none")) {
    strncpy(out, str, strlen(str));
    return strlen(str);
  }
  if (0 == strcmp(termination, "nul")) {
    strcpy(out, str);
    return strlen(str + 1);
  }
  if (0 == strcmp(termination, "2-nul")) {
    for (size_t i = 0; i < 256; i++) {
      out[i] = str[i];
      if (str[i] == 0 && str[i + 1] == 0) {
        out[i + 1] = 0;
        return i + 2;
      }
    }
    assert(0 && "Invalid string");
  }
  if (0 == strcmp(termination, "2-section")) {
    return sbp_pack_string_sections(out, str, 2, false);
  }
  if (0 == strcmp(termination, "3-section")) {
    return sbp_pack_string_sections(out, str, 3, false);
  }
  if (0 == strcmp(termination, "4-section")) {
    return sbp_pack_string_sections(out, str, 4, false);
  }
  if (0 == strcmp(termination, "3-4-section")) {
    return sbp_pack_string_sections(out, str, 4, true);
  }
  assert(0 && "Unknown termination");
}

static inline size_t sbp_unpack_string(const char *buf, size_t len, char *out,
                                       const char *termination) {
  if (0 == strcmp(termination, "none")) {
    strncpy(out, buf, len);
    out[len] = 0;
    return len;
  }
  if (0 == strcmp(termination, "nul")) {
    strcpy(out, buf);
    return strlen(out) + 1;
  }
  if (0 == strcmp(termination, "2-nul")) {
    for (size_t i = 0; i < 256; i++) {
      out[i] = buf[i];
      if (buf[i] == 0 && buf[i + 1] == 0) {
        out[i + 1] = 0;
        return i + 2;
      }
    }
    assert(0 && "Invalid string");
  }
  if (0 == strcmp(termination, "2-section")) {
    return sbp_pack_string_sections(out, buf, 2, false);
  }
  if (0 == strcmp(termination, "3-section")) {
    return sbp_pack_string_sections(out, buf, 3, false);
  }
  if (0 == strcmp(termination, "4-section")) {
    return sbp_pack_string_sections(out, buf, 4, false);
  }
  if (0 == strcmp(termination, "3-4-section")) {
    return sbp_pack_string_sections(out, buf, 4, true);
  }
  assert(0 && "Unknown termination");
}

/* Should match guard in libswiftnav/common.h */
#ifndef COMMON_INT_TYPES
#define COMMON_INT_TYPES
/** \defgroup common_inttypes Integer types
 * Specified-width integer type definitions for shorter and nicer code.
 *
 * These should be used in preference to unspecified width types such as
 * `int` which can lead to portability issues between different platforms.
 * \{ */

#ifndef _RUSTC_BINDGEN_
/** Signed 8-bit integer. */
typedef int8_t s8;
/** Signed 16-bit integer. */
typedef int16_t s16;
/** Signed 32-bit integer. */
typedef int32_t s32;
/** Signed 64-bit integer. */
typedef int64_t s64;
/** Unsigned 8-bit integer. */
typedef uint8_t u8;
/** Unsigned 16-bit integer. */
typedef uint16_t u16;
/** Unsigned 32-bit integer. */
typedef uint32_t u32;
/** Unsigned 64-bit integer. */
typedef uint64_t u64;
#endif

#endif

/* Set packing based upon toolchain */
#if defined(__GNUC__) || defined(__clang__)

#define SBP_PACK_START /* Intentionally empty */
#define SBP_PACK_END /* Intentionally empty */
#define SBP_ATTR_PACKED __attribute__((packed))

#elif defined(_MSC_VER)

#define SBP_PACK_START __pragma(pack(1));
#define SBP_PACK_END __pragma(pack());
#define SBP_ATTR_PACKED /* Intentionally empty */

#else

#if !defined(SBP_PACK_START) || !defined(SBP_PACK_END) || !defined(SBP_ATTR_PACKED)
#error Unknown compiler, please override SBP_PACK_START, SBP_PACK_END, and SBP_ATTR_PACKED
#endif 

#endif /* toolchaing packing macros */

/** \} */

#endif /* LIBSBP_COMMON_H */

