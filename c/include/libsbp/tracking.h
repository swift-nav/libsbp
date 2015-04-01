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
 * with generate.py at 2015-04-02 12:08:48.606597. Please do not hand edit!
 *****************************************************************************/

#ifndef LIBSBP_TRACKING_MESSAGES_H
#define LIBSBP_TRACKING_MESSAGES_H

#include "common.h"


/** Satellite tracking channel state.
 *
 * Tracking channel state for a specific satellite PRN and measured
 * signal power.
 */
typedef struct __attribute__((packed)) {
  u8 state;    /**< Status of tracking channel. */
  u8 prn;      /**< PRN being tracked. */
  float cn0;      /**< Carrier-to-noise density [dB Hz] */
} tracking_channel_state_t;


/** Satellite tracking channel states.
 *
 * The tracking message returns a variable-length array of tracking
 * channel states. It reports status and code/carrier phase signal
 * power measurements for all tracked satellites.
 */
#define SBP_MSG_TRACKING_STATE 0x0016
typedef struct __attribute__((packed)) {
  tracking_channel_state_t states[0]; /**< Satellite tracking channel state. */
} msg_tracking_state_t;


/** WGS84 satellite orbit ephemeris parameters
 *
 * The ephemeris message returns a set of satellite orbit
 * parameters that is used to calculate GPS satellite position,
 * velocity, and clock offset (WGS84). Please see the Navstar GPS
 * Space Segment/Navigation user interfaces (ICD-GPS-200, Table
 * 20-III) for more details
 * (http://www.navcen.uscg.gov/pubs/gps/icd200/icd200cw1234.pdf).
 */
#define SBP_MSG_EPHEMERIS      0x001A
typedef struct __attribute__((packed)) {
  double tgd;         /**< Group delay differential between L1 and L2 (?) [s] */
  double crs;         /**< Amplitude of the sine harmonic correction term to the orbit radius [m] */
  double crc;         /**< Amplitude of the cosine harmonic correction term to the orbit radius [m] */
  double cuc;         /**< Amplitude of the cosine harmonic correction term to the argument of latitude [rad] */
  double cus;         /**< Amplitude of the sine harmonic correction term to the argument of latitude [rad] */
  double cic;         /**< Amplitude of the cosine harmonic correction term to the angle of inclination [rad] */
  double cis;         /**< Amplitude of the sine harmonic correction term to the angle of inclination [rad] */
  double dn;          /**< Mean motion difference [rad/s] */
  double m0;          /**< Mean anomaly at reference time [radians] */
  double ecc;         /**< Eccentricity of satellite orbit */
  double sqrta;       /**< Square root of the semi-major axis of orbit [m^(1/2)] */
  double omega0;      /**< Longitude of ascending node of orbit plane at weekly epoch [rad] */
  double omegadot;    /**< Rate of right ascension [rad/s] */
  double w;           /**< Argument of perigee [rad] */
  double inc;         /**< Inclination [rad] */
  double inc_dot;     /**< Inclination first derivative [rad/s] */
  double af0;         /**< Polynomial clock correction coefficient (clock bias) [s] */
  double af1;         /**< Polynomial clock correction coefficient (clock drift) [s/s] */
  double af2;         /**< Polynomial clock correction coefficient (rate of clock drift) [s/s^2] */
  double toe_tow;     /**< Time of week [s] */
  u16 toe_wn;      /**< Week number [week] */
  double toc_tow;     /**< Clock reference time of week [s] */
  u16 toc_wn;      /**< Clock reference week number [week] */
  u8 valid;       /**< Is valid? */
  u8 healthy;     /**< Satellite is healthy? */
  u8 prn;         /**< PRN being tracked */
} msg_ephemeris_t;


#endif /* LIBSBP_TRACKING_MESSAGES_H */