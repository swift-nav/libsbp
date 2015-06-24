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
  u32 sid;      /**< Signal identifier being tracked - values 0x00 through 0x1F
represent GPS PRNs 1 through 32 respectively (PRN-1 notation);
other values reserved for future use
 */
  float cn0;      /**< Carrier-to-noise density [dB Hz] */
} tracking_channel_state_t;


/** Satellite tracking channel states
 *
 * The tracking message returns a variable-length array of tracking
 * channel states. It reports status and snr power measurements for
 * all tracked satellites.
 */
#define SBP_MSG_TRACKING_STATE       0x0013
typedef struct __attribute__((packed)) {
  tracking_channel_state_t states[0]; /**< Satellite tracking channel state */
} msg_tracking_state_t;


/** Complex correlation structure
 *
 * Structure containing in-phase and quadrature correlation components.
 */
typedef struct __attribute__((packed)) {
  s32 I;    /**< In-phase correlation */
  s32 Q;    /**< Quadrature correlation */
} tracking_channel_correlation_t;


/** Tracking channel correlations
 *
 * When enabled, a tracking channel can output the correlations at each
 * update interval.
 */
#define SBP_MSG_TRACKING_IQ          0x001C
typedef struct __attribute__((packed)) {
  u8 channel;    /**< Tracking channel of origin */
  u32 sid;        /**< Signal identifier being tracked - values 0x00 through 0x1F
represent GPS PRNs 1 through 32 respectively (PRN-1 notation);
other values reserved for future use
 */
  tracking_channel_correlation_t corrs[3];   /**< Early, Prompt and Late correlations */
} msg_tracking_iq_t;


/** Deprecated
 *
* Deprecated.
 */
typedef struct __attribute__((packed)) {
  u8 state;    /**< Status of tracking channel */
  u8 prn;      /**< PRN-1 being tracked */
  float cn0;      /**< Carrier-to-noise density [dB Hz] */
} tracking_channel_state_dep_a_t;


/** Deprecated
 *
* Deprecated.
 */
#define SBP_MSG_TRACKING_STATE_DEP_A 0x0016
typedef struct __attribute__((packed)) {
  tracking_channel_state_dep_a_t states[0]; /**< Satellite tracking channel state */
} msg_tracking_state_dep_a_t;


/** \} */

#endif /* LIBSBP_TRACKING_MESSAGES_H */