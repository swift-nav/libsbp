/*
 * Copyright (C) 2015-2018 Swift Navigation Inc.
 * Contact: https://support.swiftnav.com
 *
 * This source is subject to the license found in the file 'LICENSE' which must
 * be be distributed together with this source. All other rights reserved.
 *
 * THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
 * EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
 */

/*****************************************************************************
 * Automatically generated from yaml/swiftnav/sbp/logging.yaml
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

/** \defgroup logging Logging
 *
 *  * Logging and debugging messages from the device.
 * \{ */

#ifndef LIBSBP_LOGGING_MESSAGES_H
#define LIBSBP_LOGGING_MESSAGES_H

#include "common.h"

SBP_PACK_START
#ifdef __ghs__
#pragma pack(1)
#endif


/** Plaintext logging messages with levels
 *
 * This message contains a human-readable payload string from the
 * device containing errors, warnings and informational messages at
 * ERROR, WARNING, DEBUG, INFO logging levels.
 */
#define SBP_MSG_LOG       0x0401
#define SBP_LOG_LOGGING_LEVEL_MASK (0x7)
#define SBP_LOG_LOGGING_LEVEL_SHIFT (0u)
#define SBP_LOG_LOGGING_LEVEL_GET(flags) \
                             (((flags) >> SBP_LOG_LOGGING_LEVEL_SHIFT) \
                             & SBP_LOG_LOGGING_LEVEL_MASK)
#define SBP_LOG_LOGGING_LEVEL_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_LOG_LOGGING_LEVEL_MASK)) \
                             << (SBP_LOG_LOGGING_LEVEL_SHIFT)));} while(0)
                             

#define SBP_LOG_LOGGING_LEVEL_EMERG (0)
#define SBP_LOG_LOGGING_LEVEL_ALERT (1)
#define SBP_LOG_LOGGING_LEVEL_CRIT (2)
#define SBP_LOG_LOGGING_LEVEL_ERROR (3)
#define SBP_LOG_LOGGING_LEVEL_WARN (4)
#define SBP_LOG_LOGGING_LEVEL_NOTICE (5)
#define SBP_LOG_LOGGING_LEVEL_INFO (6)
#define SBP_LOG_LOGGING_LEVEL_DEBUG (7)

typedef struct SBP_ATTR_PACKED {
  u8 level;    /**< Logging level */
#ifdef SBP_ENABLE_VARIABLE_SIZED_ARRAYS
  char text[0];  /**< Human-readable string */
#endif
} msg_log_t;
#define MSG_LOG_T_GET_TEXT_PTR(msg) (( char *)(msg+1))
#define MSG_LOG_T_GET_TEXT_CPTR(msg) ((const char *)(msg+1))
 

/** Wrapper for FWD a separate stream of information over SBP
 *
 * This message provides the ability to forward messages over SBP.  This may take the form
 * of wrapping up SBP messages received by Piksi for logging purposes or wrapping 
 * another protocol with SBP.
 * 
 * The source identifier indicates from what interface a forwarded stream derived.
 * The protocol identifier identifies what the expected protocol the forwarded msg contains.
 * Protocol 0 represents SBP and the remaining values are implementation defined.
 */
#define SBP_MSG_FWD       0x0402

typedef struct SBP_ATTR_PACKED {
  u8 source;         /**< source identifier */
  u8 protocol;       /**< protocol identifier */
#ifdef SBP_ENABLE_VARIABLE_SIZED_ARRAYS
  char fwd_payload[0]; /**< variable length wrapped binary message */
#endif
} msg_fwd_t;
#define MSG_FWD_T_GET_FWD_PAYLOAD_PTR(msg) (( char *)(msg+1))
#define MSG_FWD_T_GET_FWD_PAYLOAD_CPTR(msg) ((const char *)(msg+1))
 

/** Deprecated
 *
* Deprecated.
 */
#define SBP_MSG_PRINT_DEP 0x0010
#ifdef SBP_ENABLE_VARIABLE_SIZED_ARRAYS

typedef struct SBP_ATTR_PACKED {
  char text[0]; /**< Human-readable string */
} msg_print_dep_t;
#endif
 

/** \} */
static inline void static_asserts_for_module_MSG_LOG(void) {
#ifdef __cplusplus
static_assert(offsetof(msg_log_t, level ) == 0, "Offset of level in msg_log_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_log_t, level ) == 0, offset_of_level_in_msg_log_t_is_incorrect)
#endif
#ifdef SBP_ENABLE_VARIABLE_SIZED_ARRAYS
#ifdef __cplusplus
static_assert(offsetof(msg_log_t, text ) == 0 + sizeof(u8), "Offset of text in msg_log_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_log_t, text ) == 0 + sizeof(u8), offset_of_text_in_msg_log_t_is_incorrect)
#endif
#endif
}

static inline void static_asserts_for_module_MSG_FWD(void) {
#ifdef __cplusplus
static_assert(offsetof(msg_fwd_t, source ) == 0, "Offset of source in msg_fwd_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_fwd_t, source ) == 0, offset_of_source_in_msg_fwd_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_fwd_t, protocol ) == 0 + sizeof(u8), "Offset of protocol in msg_fwd_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_fwd_t, protocol ) == 0 + sizeof(u8), offset_of_protocol_in_msg_fwd_t_is_incorrect)
#endif
#ifdef SBP_ENABLE_VARIABLE_SIZED_ARRAYS
#ifdef __cplusplus
static_assert(offsetof(msg_fwd_t, fwd_payload ) == 0 + sizeof(u8) + sizeof(u8), "Offset of fwd_payload in msg_fwd_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_fwd_t, fwd_payload ) == 0 + sizeof(u8) + sizeof(u8), offset_of_fwd_payload_in_msg_fwd_t_is_incorrect)
#endif
#endif
}

static inline void static_asserts_for_module_MSG_PRINT_DEP(void) {
#ifdef SBP_ENABLE_VARIABLE_SIZED_ARRAYS
#ifdef __cplusplus
static_assert(offsetof(msg_print_dep_t, text ) == 0, "Offset of text in msg_print_dep_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_print_dep_t, text ) == 0, offset_of_text_in_msg_print_dep_t_is_incorrect)
#endif
#endif
}


#ifdef __ghs__
#pragma pack()
#endif
SBP_PACK_END

#endif /* LIBSBP_LOGGING_MESSAGES_H */
