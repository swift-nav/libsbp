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
 * with generate.py at 2015-04-02 12:08:48.482015. Please do not hand edit!
 *****************************************************************************/

#ifndef LIBSBP_LOGGING_MESSAGES_H
#define LIBSBP_LOGGING_MESSAGES_H

#include "common.h"


/** Plaintext logging messages (Piksi => Host).
 *
 * This message contains a human-reabable payload string from the
 * Piksi containing errors, warnings and informational messages at
 * ERROR, WARNING, DEBUG, INFO logging levels. These message may
 * also contain information tagged by filename, as well as debug
 * info on function entry/exit when enabled within the firmware.
 */
#define SBP_MSG_PRINT     0x0010
typedef struct __attribute__((packed)) {
  char* text;    /**< Informative, human-readable string. */
} msg_print_t;


/** Legacy message for tracing variable values (Piksi => Host).
 *
 * This is an unused legacy message for tracing variable values
 * within the Piksi firmware and streaming those back to the host.
 */
#define SBP_MSG_DEBUG_VAR 0x0011


#endif /* LIBSBP_LOGGING_MESSAGES_H */