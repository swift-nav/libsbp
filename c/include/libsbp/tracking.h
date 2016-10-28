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
#include "gnss.h"


/** Detailed signal tracking channel states
 *
 * The tracking message returns a set tracking channel parameters for a
 * single tracking channel useful for debugging issues.
 */
#define SBP_MSG_TRACKING_STATE_DETAILED 0x0011
typedef struct __attribute__((packed)) {
  u64 recv_time;       /**< Receiver clock time. [ns] */
  obs_gps_time_t tot;             /**< Time of transmission of signal from satellite. */
  u32 P;               /**< Pseudorange observation. [2 cm] */
  u16 P_std;           /**< Pseudorange observation standard deviation. [2 cm] */
  carrier_phase_t L;               /**< Carrier phase observation with typical sign convention. Only valid
when PLL pessimistic lock is achieved.
 [cycles] */
  u8 cn0;             /**< Carrier-to-Noise density [dB Hz * 4] */
  u16 lock;            /**< Lock indicator. This value changes whenever a satellite
signal has lost and regained lock, indicating that the
carrier phase ambiguity may have changed.
 */
  sbp_gnss_signal_t sid;             /**< GNSS signal identifier. */
  s32 doppler;         /**< Carrier Doppler frequency. [Hz * 10] */
  u16 doppler_std;     /**< Carrier Doppler frequency standard deviation. [Hz * 10] */
  u32 uptime;          /**< Number of seconds of continuous tracking. Specifies how much time
signal is in continuous track.
 [s] */
  u16 clock_offset;    /**< TCXO clock offset. [ppb * 10] */
  u16 clock_drift;     /**< TCXO clock drift. [(ppb * 10) / s] */
  u16 corr_spacing;    /**< Early-Prompt (EP) and Prompt-Late (PL) correlators spacing. [ns] */
  u8 acceleration;    /**< Acceleration. Valid only when acceleration valid flag is set. [g * 10] */
  u8 sync_flags;      /**< Synchronization status flags. */
  u8 tow_flags;       /**< TOW status flags. */
  u8 track_flags;     /**< Tracking loop status flags. */
  u8 nav_flags;       /**< Navigation data status flags. */
  u8 pset_flags;      /**< Parameters sets flags. */
  u8 misc_flags;      /**< Miscellaneous flags. */
} msg_tracking_state_detailed_t;


/** Signal tracking channel state
 *
 * Tracking channel state for a specific satellite signal and
 * measured signal power.
 */
typedef struct __attribute__((packed)) {
  u8 state;    /**< Status of tracking channel */
  sbp_gnss_signal_t sid;      /**< GNSS signal being tracked */
  float cn0;      /**< Carrier-to-noise density [dB Hz] */
} tracking_channel_state_t;


/** Signal tracking channel states
 *
 * The tracking message returns a variable-length array of tracking
 * channel states. It reports status and carrier-to-noise density
 * measurements for all tracked satellites.
 */
#define SBP_MSG_TRACKING_STATE          0x0013
typedef struct __attribute__((packed)) {
  tracking_channel_state_t states[0]; /**< Signal tracking channel state */
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
#define SBP_MSG_TRACKING_IQ             0x001C
typedef struct __attribute__((packed)) {
  u8 channel;    /**< Tracking channel of origin */
  sbp_gnss_signal_t sid;        /**< GNSS signal identifier */
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
#define SBP_MSG_TRACKING_STATE_DEP_A    0x0016
typedef struct __attribute__((packed)) {
  tracking_channel_state_dep_a_t states[0]; /**< Satellite tracking channel state */
} msg_tracking_state_dep_a_t;


/** \} */

#endif /* LIBSBP_TRACKING_MESSAGES_H */