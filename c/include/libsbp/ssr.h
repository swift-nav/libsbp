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
 * Automatically generated from yaml/swiftnav/sbp/ssr.yaml
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

/** \defgroup ssr Ssr
 *
 * * Precise State Space Representation (SSR) corrections format
 * \{ */

#ifndef LIBSBP_SSR_MESSAGES_H
#define LIBSBP_SSR_MESSAGES_H

#include "common.h"
#include "gnss.h"


/** SSR code biases corrections for a particular satellite.
 *
 * Code biases are to be added to pseudorange.
 * The corrections are conform with typical RTCMv3 MT1059 and 1065.
 */
typedef struct __attribute__((packed)) {
  u8 code;     /**< Signal constellation, band and code */
  s16 value;    /**< Code bias value [0.01 m] */
} code_biases_content_t;


/** SSR phase biases corrections for a particular satellite.
 *
 * Phase biases are to be added to carrier phase measurements.
 * The corrections are conform with typical RTCMv3 MT1059 and 1065.
 */
typedef struct __attribute__((packed)) {
  u8 code;                          /**< Signal constellation, band and code */
  u8 integer_indicator;             /**< Indicator for integer property */
  u8 widelane_integer_indicator;    /**< Indicator for two groups of Wide-Lane(s) integer property */
  u8 discontinuity_counter;         /**< Signal phase discontinuity counter. 
Increased for every discontinuity in phase.
 */
  s32 bias;                          /**< Phase bias for specified signal [0.1 mm] */
} phase_biases_content_t;


/** Precise orbit and clock correction
 *
 * The precise orbit and clock correction message is 
 * to be applied as a delta correction to broadcast 
 * ephemeris and is typically an equivalent to the 1060
 * and 1066 RTCM message types
 */
#define SBP_MSG_SSR_ORBIT_CLOCK  0x05DC
typedef struct __attribute__((packed)) {
  gps_time_sec_t time;               /**< GNSS reference time of the correction */
  sbp_gnss_signal_t sid;                /**< GNSS signal identifier (16 bit) */
  u8 update_interval;    /**< Update interval between consecutive corrections [s] */
  u8 iod_ssr;            /**< IOD of the SSR correction. A change of Issue Of Data
SSR is used to indicate a change in the SSR 
generating configuration
 */
  u8 iod;                /**< Issue of broadcast ephemeris data */
  s32 radial;             /**< Orbit radial delta correction [0.1 mm] */
  s32 along;              /**< Orbit along delta correction [0.4 mm] */
  s32 cross;              /**< Orbit along delta correction [0.4 mm] */
  s32 dot_radial;         /**< Velocity of orbit radial delta correction [0.001 mm/s] */
  s32 dot_along;          /**< Velocity of orbit along delta correction [0.004 mm/s] */
  s32 dot_cross;          /**< Velocity of orbit cross delta correction [0.004 mm/s] */
  s32 c0;                 /**< C0 polynomial coefficient for correction of broadcast satellite clock [0.1 mm] */
  s32 c1;                 /**< C1 polynomial coefficient for correction of broadcast satellite clock [0.001 mm/s] */
  s32 c2;                 /**< C2 polynomial coefficient for correction of broadcast satellite clock [0.00002 mm/s^-2] */
} msg_ssr_orbit_clock_t;


/** Precise code biases correction
 *
 * The precise code biases message is to be added
 * to the pseudorange of the corresponding signal
 * to get corrected pseudorange. It is typically 
 * an equivalent to the 1059 and 1065 RTCM message types
 */
#define SBP_MSG_SSR_CODE_BIASES  0x05E1
typedef struct __attribute__((packed)) {
  gps_time_sec_t time;               /**< GNSS reference time of the correction */
  sbp_gnss_signal_t sid;                /**< GNSS signal identifier (16 bit) */
  u8 update_interval;    /**< Update interval between consecutive corrections [s] */
  u8 iod_ssr;            /**< IOD of the SSR correction. A change of Issue Of Data
SSR is used to indicate a change in the SSR 
generating configuration
 */
  code_biases_content_t biases[0];          /**< Code biases for the different satellite signals */
} msg_ssr_code_biases_t;


/** Precise phase biases correction
 *
 * The precise phase biases message contains the biases
 * to be added to the carrier phase of the corresponding
 * signal to get corrected carrier phase measurement, as 
 * well as the satellite yaw angle to be applied to compute 
 * the phase wind-up correction. 
 * It is typically an equivalent to the 1265 RTCM message types
 */
#define SBP_MSG_SSR_PHASE_BIASES 0x05E6
typedef struct __attribute__((packed)) {
  gps_time_sec_t time;               /**< GNSS reference time of the correction */
  sbp_gnss_signal_t sid;                /**< GNSS signal identifier (16 bit) */
  u8 update_interval;    /**< Update interval between consecutive corrections [s] */
  u8 iod_ssr;            /**< IOD of the SSR correction. A change of Issue Of Data
SSR is used to indicate a change in the SSR 
generating configuration
 */
  u8 dispersive_bias;    /**< Indicator for the dispersive phase biases property.
 */
  u8 mw_consistency;     /**< Consistency indicator for Melbourne-Wubbena linear combinations
 */
  u16 yaw;                /**< Satellite yaw angle [1 / 256 semi-circle] */
  s8 yaw_rate;           /**< Satellite yaw angle rate [1 / 8192 semi-circle / s] */
  phase_biases_content_t biases[0];          /**< Phase biases corrections for a
satellite being tracked.
 */
} msg_ssr_phase_biases_t;


/** \} */

#endif /* LIBSBP_SSR_MESSAGES_H */