/*
 * Copyright (C) 2012-2021 Swift Navigation Inc.
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

#define SBP_ENCODED_LEN_U8 1u
#define SBP_ENCODED_LEN_S8 1u
#define SBP_ENCODED_LEN_U16 2u
#define SBP_ENCODED_LEN_S16 2u
#define SBP_ENCODED_LEN_U32 4u
#define SBP_ENCODED_LEN_S32 4u
#define SBP_ENCODED_LEN_U64 8u
#define SBP_ENCODED_LEN_S64 8u
#define SBP_ENCODED_LEN_FLOAT 4u
#define SBP_ENCODED_LEN_DOUBLE 8u
#define SBP_ENCODED_LEN_CHAR 1u

/**
 * Write callback
 *
 * The user of libsbp must provide a write callback conforming to this type
 * to functions which send messages (eg, #sbp_message_send). The write 
 * function will be called several times during the course of sending a single 
 * message. The context parameter can be set by calling #sbp_state_set_io_context.
 *
 * @param buff Data to write
 * @param n Length of \p buff
 * @param context User provided context
 * @return Number of bytes written, or <0 to indicate error
 */
typedef s32 (*sbp_write_fn_t)(u8 *buff, u32 n, void *context);

/**
 * Read callback
 *
 * The user of libsbp must provide a read callback conforming to this type when
 * calling #sbp_process. This function will be called once per invocation of 
 * #sbp_process in order to read data from an input source. Once the entire 
 * frame has been read any registered callbacks will be invoked.
 *
 * @param buff Destination buffer
 * @param n Length of \p buff, maximum number of bytes to read
 * @context User provided context, see #sbp_state_set_io_context
 * @return Number of bytes read, or -1 to indicate error
 */
typedef s32 (*sbp_read_fn_t)(u8 *buff, u32 n, void *context);

/* Forward declarations */
struct sbp_state;
typedef struct sbp_state sbp_state_t;
struct sbp_msg_callbacks_node;
typedef struct sbp_msg_callbacks_node sbp_msg_callbacks_node_t;

/* Set packing based upon toolchain */
#if defined(__GNUC__) || defined(__clang__)

#define SBP_PACK_START /* Intentionally empty */
#define SBP_PACK_END /* Intentionally empty */
#define SBP_ATTR_PACKED __attribute__((packed))
#define DO_PRAGMA(x) _Pragma(#x)
#define SBP_MESSAGE(msg) DO_PRAGMA(message (msg))
#define SBP_DEPRECATED __attribute__((deprecated))
#define SBP_ATTR_FORMAT(fmt,args) __attribute__((format(printf,fmt,args)))
#define SBP_ATTR_VFORMAT(fmt) __attribute__((format(printf,fmt,0)))
#define SBP_EXPORT __attribute__((visibility("default")))

#elif defined(_MSC_VER)

#define SBP_PACK_START __pragma(pack(1));
#define SBP_PACK_END __pragma(pack());
#define SBP_ATTR_PACKED /* Intentionally empty */
#define SBP_MESSAGE(msg) /* Intentionally empty */
#define SBP_DEPRECATED __declspec(deprecated)
#define SBP_ATTR_FORMAT(fmt,args)
#define SBP_ATTR_VFORMAT(fmt)

#if !defined(_WINDLL)
#define SBP_EXPORT
#elif defined(sbp_EXPORTS)
#define SBP_EXPORT __declspec(dllexport)
#else
#define SBP_EXPORT __declspec(dllimport)
#endif

#elif defined(__ghs__)

#define SBP_PACK_START /* Intentionally empty */
#define SBP_PACK_END /* Intentionally empty */
#define SBP_ATTR_PACKED __attribute__((packed))
#define SBP_MESSAGE(msg) /* Intentionally empty */
#define SBP_DEPRECATED /* Intentionally empty */
#define SBP_ATTR_FORMAT(fmt,args)
#define SBP_ATTR_VFORMAT(fmt)
#define SBP_EXPORT /* Intentionally empty */

#else

#if !defined(SBP_PACK_START) || !defined(SBP_PACK_END) || !defined(SBP_ATTR_PACKED)
#error Unknown compiler, please override SBP_PACK_START, SBP_PACK_END, and SBP_ATTR_PACKED
#endif 

#endif /* toolchaing packing macros */

/** \} */

#endif /* LIBSBP_COMMON_H */
