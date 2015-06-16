/*
 * Copyright (C) 2015 Swift Navigation Inc.
 * Contact: Fergus Noble <fergus@swift-nav.com>
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
 *  * Logging and debugging messages from the device. These are in the
 * implementation-defined range (0x0000-0x00FF).
 * \{ */

#ifndef LIBSBP_LOGGING_MESSAGES_H
#define LIBSBP_LOGGING_MESSAGES_H

#include "common.h"


/** Plaintext logging messages
 *
 * This message contains a human-readable payload string from the
 * device containing errors, warnings and informational messages at
 * ERROR, WARNING, DEBUG, INFO logging levels.
 */
#define SBP_MSG_PRINT     0x0010
typedef struct __attribute__((packed)) {
  char text[0]; /**< Human-readable string */
} msg_print_t;


/** Legacy message for tracing variable values
 *
 * This is an unused legacy message for tracing variable values
 * within the device firmware and streaming those back to the host.
 */
#define SBP_MSG_DEBUG_VAR 0x0011


/** \} */

#endif /* LIBSBP_LOGGING_MESSAGES_H */