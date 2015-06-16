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
 * Automatically generated from yaml/swiftnav/sbp/tracking.yaml
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

/** \defgroup tracking Tracking
 *
 *  * Satellite code and carrier-phase tracking messages from the device.
 * \{ */

#ifndef LIBSBP_TRACKING_MESSAGES_H
#define LIBSBP_TRACKING_MESSAGES_H

#include "common.h"


/** Satellite tracking channel state
 *
 * Tracking channel state for a specific satellite PRN and measured
 * signal power.
 */
typedef struct __attribute__((packed)) {
  u8 state;    /**< Status of tracking channel */
  u8 prn;      /**< PRN-1 being tracked */
  float cn0;      /**< Carrier-to-noise density [dB Hz] */
} tracking_channel_state_t;


/** Satellite tracking channel states
 *
 * The tracking message returns a variable-length array of tracking
 * channel states. It reports status and snr power measurements for
 * all tracked satellites.
 */
#define SBP_MSG_TRACKING_STATE 0x0016
typedef struct __attribute__((packed)) {
  tracking_channel_state_t states[0]; /**< Satellite tracking channel state */
} msg_tracking_state_t;


/** \} */

#endif /* LIBSBP_TRACKING_MESSAGES_H */