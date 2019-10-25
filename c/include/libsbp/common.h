/*
 * Copyright (C) 2012 Swift Navigation Inc.
 * Contact: Henry Hallam <henry@swift-nav.com>
 *          Fergus Noble <fergus@swift-nav.com>
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

/** \} */

#endif /* LIBSBP_COMMON_H */

