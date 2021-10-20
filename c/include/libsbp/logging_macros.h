/*
 * Copyright (C) 2015-2021 Swift Navigation Inc.
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

#ifndef LIBSBP_LOGGING_MACROS_H
#define LIBSBP_LOGGING_MACROS_H

#define SBP_MSG_LOG 0x0401
#define SBP_LOG_LOGGING_LEVEL_MASK (0x7)
#define SBP_LOG_LOGGING_LEVEL_SHIFT (0u)
#define SBP_LOG_LOGGING_LEVEL_GET(flags) \
  ((u8)(((flags) >> SBP_LOG_LOGGING_LEVEL_SHIFT) & SBP_LOG_LOGGING_LEVEL_MASK))
#define SBP_LOG_LOGGING_LEVEL_SET(flags, val)                        \
  do {                                                               \
    (flags) = (u8)((flags) | (((val) & (SBP_LOG_LOGGING_LEVEL_MASK)) \
                              << (SBP_LOG_LOGGING_LEVEL_SHIFT)));    \
  } while (0)

#define SBP_LOG_LOGGING_LEVEL_EMERG (0)
#define SBP_LOG_LOGGING_LEVEL_ALERT (1)
#define SBP_LOG_LOGGING_LEVEL_CRIT (2)
#define SBP_LOG_LOGGING_LEVEL_ERROR (3)
#define SBP_LOG_LOGGING_LEVEL_WARN (4)
#define SBP_LOG_LOGGING_LEVEL_NOTICE (5)
#define SBP_LOG_LOGGING_LEVEL_INFO (6)
#define SBP_LOG_LOGGING_LEVEL_DEBUG (7)
/**
 * The maximum number of items that can be stored in sbp_msg_log_t::text (V4
 * API) or msg_log_t::text (legacy API) before the maximum SBP message size is
 * exceeded
 */
#define SBP_MSG_LOG_TEXT_MAX 254u

/**
 * Encoded length of sbp_msg_log_t (V4 API) and
 * msg_log_t (legacy API)
 *
 * This type is not fixed size and an instance of this message may be longer
 * than the value indicated by this symbol. Users of the V4 API should call
 * #sbp_msg_log_encoded_len to determine the actual size of an instance
 * of this message. Users of the legacy API are required to track the encoded
 * message length when interacting with the legacy type.
 *
 * See the documentation for libsbp for more details regarding the message
 * structure and its variable length component(s)
 */
#define SBP_MSG_LOG_ENCODED_OVERHEAD 1u

#define SBP_MSG_FWD 0x0402
/**
 * The maximum number of items that can be stored in sbp_msg_fwd_t::fwd_payload
 * (V4 API) or msg_fwd_t::fwd_payload (legacy API) before the maximum SBP
 * message size is exceeded
 */
#define SBP_MSG_FWD_FWD_PAYLOAD_MAX 253u

/**
 * Encoded length of sbp_msg_fwd_t (V4 API) and
 * msg_fwd_t (legacy API)
 *
 * This type is not fixed size and an instance of this message may be longer
 * than the value indicated by this symbol. Users of the V4 API should call
 * #sbp_msg_fwd_encoded_len to determine the actual size of an instance
 * of this message. Users of the legacy API are required to track the encoded
 * message length when interacting with the legacy type.
 *
 * See the documentation for libsbp for more details regarding the message
 * structure and its variable length component(s)
 */
#define SBP_MSG_FWD_ENCODED_OVERHEAD 2u

#define SBP_MSG_PRINT_DEP 0x0010
/**
 * The maximum number of items that can be stored in sbp_msg_print_dep_t::text
 * (V4 API) or msg_print_dep_t::text (legacy API) before the maximum SBP message
 * size is exceeded
 */
#define SBP_MSG_PRINT_DEP_TEXT_MAX 255u

/**
 * Encoded length of sbp_msg_print_dep_t (V4 API) and
 * msg_print_dep_t (legacy API)
 *
 * This type is not fixed size and an instance of this message may be longer
 * than the value indicated by this symbol. Users of the V4 API should call
 * #sbp_msg_print_dep_encoded_len to determine the actual size of an instance
 * of this message. Users of the legacy API are required to track the encoded
 * message length when interacting with the legacy type.
 *
 * See the documentation for libsbp for more details regarding the message
 * structure and its variable length component(s)
 */
#define SBP_MSG_PRINT_DEP_ENCODED_OVERHEAD 0u

#endif /* LIBSBP_LOGGING_MACROS_H */
