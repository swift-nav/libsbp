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
 * Automatically generated from yaml/swiftnav/sbp/observation.yaml
 * with generate.py at 2015-04-02 12:08:48.412942. Please do not hand edit!
 *****************************************************************************/

#ifndef LIBSBP_OBSERVATION_MESSAGES_H
#define LIBSBP_OBSERVATION_MESSAGES_H

#include "common.h"


/** Millisecond-accurate GPS time.
 *
 * A wire-appropriate GPS time, defined as the number of
 * milliseconds since beginning of the week on the Saturday/Sunday
 * transition.
 */
typedef struct __attribute__((packed)) {
  u32 tow;    /**< Milliseconds since start of GPS week [ms] */
  u16 wn;     /**< GPS week number [week] */
} obs_gps_time_t;


/** GPS carrier phase measurement.
 *
 * Carrier phase measurement in cycles represented as a 40-bit
 * fixed point number with Q32.8 layout, i.e. 32-bits of whole
 * cycles and 8-bits of fractional cycles.
 */
typedef struct __attribute__((packed)) {
  s32 i;    /**< Carrier phase whole cycles. [cycles] */
  u8 f;    /**< Carrier phase fractional part. [cycles / 255] */
} carrier_phase_t;


/** Header for observation message.
 *

 */
typedef struct __attribute__((packed)) {
  obs_gps_time_t t;        /**< GPS time of this observation. */
  u8 n_obs;    /**< Total number of observations. First nibble is the size
of the sequence (n), second nibble is the zero-indexed
counter (ith packet of n)
 */
} observation_header_t;


/** GPS observations for a particular satellite signal.
 *
 * Pseudorange and carrier phase observation for a satellite being
 * tracked.
 */
typedef struct __attribute__((packed)) {
  u32 P;       /**< Pseudorange observation. [cm] */
  carrier_phase_t L;       /**< Carrier phase observation. */
  u8 cn0;     /**< Carrier-to-Noise density [dB Hz] */
  u16 lock;    /**< Lock indicator. This value changes whenever a satellite
signal has lost and regained lock, indicating that the
carrier phase ambiguity may have changed. There is no
significance to the value of the lock indicator.
 */
  u8 prn;     /**< PRN identifier of the satellite signal */
} packed_obs_content_t;


/** GPS satellite observations.
 *
 * The GPS observations message reports all the pseudo range and
 * carrier phase observations for the satellites being tracked by
 * the Piksi.
 */
#define SBP_MSG_OBS      0x0045
typedef struct __attribute__((packed)) {
  observation_header_t header;    /**< Header of a GPS observation message */
  packed_obs_content_t obs[0];    /**< Pseudorange and carrier phase observation for a
satellite being tracked.
 */
} msg_obs_t;


/** Base station position.
 *
 * This may be the position as reported by the base station itself or the
 * position obtained from doing a single point solution using the base
 * station observations.
 */
#define SBP_MSG_BASE_POS 0x0044
typedef struct __attribute__((packed)) {
  double lat;       /**< Latitude [deg] */
  double lon;       /**< Longitude [deg] */
  double height;    /**< Height [m] */
} msg_base_pos_t;


#endif /* LIBSBP_OBSERVATION_MESSAGES_H */