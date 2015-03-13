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
 * Automatically generated from piksi/yaml/
 * with generate.py at 2015-03-13 13:32:04.128822. Please do not hand edit!
 *****************************************************************************/

#ifndef LIBSBP_OBSERVATION_MESSAGES_H
#define LIBSBP_OBSERVATION_MESSAGES_H

#include "common.h"
#include "lib.h"


/** None
  * GPS time, defined as the number of milliseconds since the
 * beginning of the week on the Saturday/Sunday transition.
 */
typedef struct __attribute__((packed)) {
  u32 tow;    /**< Milliseconds since start of GPS week [ms] */
  u16 wn;     /**< GPS week number [week] */
} gps_time_t;


/** None
 
 */
typedef struct __attribute__((packed)) {
  gps_time_t t;        /**< GPS time of this observation. */
  u8 n_obs;    /**< Total number of observations. First nibble is the size
of the sequence (n), second nibble is the zero-indexed
counter (ith packet of n)
 */
} observation_header_t;


/** None
 
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


#define SBP_MSG_OBS      0x0045
typedef struct __attribute__((packed)) {
  observation_header_t header;    /**< Header of a GPS observation message */
  packed_obs_content_t* obs;       /**< Observations */
} msg_obs_t;


#define SBP_MSG_BASE_POS 0x0044
typedef struct __attribute__((packed)) {
  double lat;       /**< Latitude [deg] */
  double lon;       /**< Longitude [deg] */
  double height;    /**< Height [m] */
} msg_base_pos_t;


#endif /* LIBSBP_OBSERVATION_MESSAGES_H */