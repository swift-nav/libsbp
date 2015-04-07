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
 * Automatically generated from yaml/swiftnav/sbp/system.yaml
 * with generate.py at 2015-04-02 12:08:48.603510. Please do not hand edit!
 *****************************************************************************/

#ifndef LIBSBP_SYSTEM_MESSAGES_H
#define LIBSBP_SYSTEM_MESSAGES_H

#include "common.h"


/** System start-up message
 *
 * The system start-up message is sent once on system
 * start-up. It is intended to be used to notify the host or
 * other attached devices that the system has started and is now
 * ready to respond to commands or configuration requests.
 */
#define SBP_MSG_STARTUP   0xFF00
typedef struct __attribute__((packed)) {
  u32 reserved;    /**< Reserved */
} msg_startup_t;


/** System heartbeat message
 *
 * The heartbeat message is sent periodically to inform the host
 * or other attached devices that the system is running. It is
 * intended to be used to monitor for system malfunctions and
 * also contains status flags that indicate to the host the
 * status of the system and if it is operating correctly.
 * 
 * The system error flag is used to indicate that an error has
 * occurred in the system. To determine the source of the error
 * the remaining error flags should be inspected.
 */
#define SBP_MSG_HEARTBEAT 0xFFFF
typedef struct __attribute__((packed)) {
  u32 flags;    /**< Status flags */
} msg_heartbeat_t;


#endif /* LIBSBP_SYSTEM_MESSAGES_H */