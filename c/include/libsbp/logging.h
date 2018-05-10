/*
 * Copyright (C) 2015-2018 Swift Navigation Inc.
 * Contact: Swift Navigation <dev@swiftnav.com>
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

#if defined _MSC_VER || defined TOOLCHAIN_PRAGMA_PACK
#pragma pack(1)
#endif


/** Plaintext logging messages with levels
 *
 * This message contains a human-readable payload string from the
 * device containing errors, warnings and informational messages at
 * ERROR, WARNING, DEBUG, INFO logging levels.
 */
#define SBP_MSG_LOG       0x0401
#if defined _MSC_VER || defined TOOLCHAIN_PRAGMA_PACKED
typedef struct {
#else
typedef struct __attribute__((packed)) {
#endif
  u8 level;    /**< Logging level */
  char text[0];  /**< Human-readable string */
} msg_log_t;


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
#if defined _MSC_VER || defined TOOLCHAIN_PRAGMA_PACKED
typedef struct {
#else
typedef struct __attribute__((packed)) {
#endif
  u8 source;         /**< source identifier */
  u8 protocol;       /**< protocol identifier */
  char fwd_payload[0]; /**< variable length wrapped binary message */
} msg_fwd_t;


/** Tweet
 *
* All the news fit to tweet.
 */
#define SBP_MSG_TWEET     0x0012
#if defined _MSC_VER || defined TOOLCHAIN_PRAGMA_PACKED
typedef struct {
#else
typedef struct __attribute__((packed)) {
#endif
  char tweet[140]; /**< Human-readable string */
} msg_tweet_t;


/** Deprecated
 *
* Deprecated.
 */
#define SBP_MSG_PRINT_DEP 0x0010
#if defined _MSC_VER || defined TOOLCHAIN_PRAGMA_PACKED
typedef struct {
#else
typedef struct __attribute__((packed)) {
#endif
  char text[0]; /**< Human-readable string */
} msg_print_dep_t;


/** \} */

#if defined _MSC_VER || defined TOOLCHAIN_PRAGMA_PACK
#pragma pack()
#endif

#endif /* LIBSBP_LOGGING_MESSAGES_H */