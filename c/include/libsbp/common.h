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
#endif

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

static inline void sbp_pack_u16(uint8_t *buf, uint16_t v) {
  buf[0] = (uint8_t)(v & 0xff);
  buf[1] = (uint8_t)((v & 0xff00) >> 8);
}

static inline void sbp_pack_u32(uint8_t *buf, uint32_t v) {
  buf[0] = (uint8_t)(v & 0xff);
  buf[1] = (uint8_t)((v & 0xff00) >> 8);
  buf[2] = (uint8_t)((v & 0xff0000) >> 16);
  buf[3] = (uint8_t)((v & 0xff000000) >> 24);
}

static inline void sbp_pack_u64(uint8_t *buf, uint64_t v) {
  buf[0] = (uint8_t)(v & 0xff);
  buf[1] = (uint8_t)((v & 0xff00) >> 8);
  buf[2] = (uint8_t)((v & 0xff0000) >> 16);
  buf[3] = (uint8_t)((v & 0xff000000) >> 24);
  buf[4] = (uint8_t)((v & 0xff00000000) >> 32);
  buf[5] = (uint8_t)((v & 0xff0000000000) >> 40);
  buf[6] = (uint8_t)((v & 0xff000000000000) >> 48);
  buf[7] = (uint8_t)((v & 0xff00000000000000) >> 56);
}

static inline void sbp_pack_s16(uint8_t *buf, s16 v) { sbp_pack_u16(buf, (u16)v); }
static inline void sbp_pack_s32(uint8_t *buf, s32 v) { sbp_pack_u32(buf, (u32)v); }
static inline void sbp_pack_s64(uint8_t *buf, s64 v) { sbp_pack_u64(buf, (u64)v); }

static inline uint16_t sbp_unpack_u16(const uint8_t *buf) {
  uint32_t v = buf[1];
  v <<= 8;
  v |= buf[0];
  return (uint16_t)v;
}

static inline uint32_t sbp_unpack_u32(const uint8_t *buf) {
  uint32_t v = buf[3];
  v <<= 8;
  v |= buf[2];
  v <<= 8;
  v |= buf[1];
  v <<= 8;
  v |= buf[0];
  return v;
}

static inline uint64_t sbp_unpack_u64(const uint8_t *buf) {
  uint64_t v = buf[7];
  v <<= 8;
  v |= buf[6];
  v <<= 8;
  v |= buf[5];
  v <<= 8;
  v |= buf[4];
  v <<= 8;
  v |= buf[3];
  v <<= 8;
  v |= buf[2];
  v <<= 8;
  v |= buf[1];
  v <<= 8;
  v |= buf[0];
  return v;
}

static inline s16 sbp_unpack_s16(const uint8_t *buf) { return (s16)sbp_unpack_u16(buf); }
static inline s32 sbp_unpack_s32(const uint8_t *buf) { return (s32)sbp_unpack_u32(buf); }
static inline s64 sbp_unpack_s64(const uint8_t *buf) { return (s64)sbp_unpack_u64(buf); }

/** \} */

#endif /* LIBSBP_COMMON_H */

