/*
 * Copyright (C) 2018 Swift Navigation Inc.
 * Contact: Luka Strizic <luka.strizic@swift-nav.com>
 *
 * This source is subject to the license found in the file 'LICENSE' which must
 * be be distributed together with this source. All other rights reserved.
 *
 * THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
 * EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
 */

/*****************************************************************************
 * Automatically generated from yaml/swiftnav/sbp/can.yaml
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

/** \defgroup can Can
 *
 * * CAN-related messages from and to the device.
 * \{ */

#ifndef LIBSBP_CAN_MESSAGES_H
#define LIBSBP_CAN_MESSAGES_H

#include "common.h"


/** Inbound CAN frame
 *
 * This message wraps an inbound CAN frame.
 */
#define SBP_MSG_CAN_IN 0x0300
typedef struct __attribute__((packed)) {
  u8 can_frame[16]; /**< CAN frame. [bytes] */
} msg_can_in_t;


/** \} */

#endif /* LIBSBP_CAN_MESSAGES_H */
