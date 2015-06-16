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
 * Automatically generated from yaml/swiftnav/sbp/deprecated.yaml
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

/** \defgroup deprecated Deprecated
 *
 * * Deprecated SBP messages.
 * \{ */

#ifndef LIBSBP_DEPRECATED_MESSAGES_H
#define LIBSBP_DEPRECATED_MESSAGES_H

#include "common.h"


/** Bootloading handshake response (host <= device)
 *
 * The handshake message response from the device establishes a
 * handshake between the device bootloader and the host. The
 * request from the host is MSG_BOOTLOADER_HANDSHAKE_HOST.  The
 * payload string contains the bootloader version number, but
 * returns an empty string for earlier versions.
 */
#define SBP_MSG_BOOTLOADER_HANDSHAKE_DEPRECATED 0x00B0
typedef struct __attribute__((packed)) {
  u8 handshake[0]; /**< Version number string (not NULL terminated) */
} msg_bootloader_handshake_deprecated_t;


/** Deprecated
 *
* Deprecated.
 */
#define SBP_MSG_EPHEMERIS_DEPRECATED            0x001A
typedef struct __attribute__((packed)) {
  double tgd;         /**< Group delay differential between L1 and L2 [s] */
  double c_rs;        /**< Amplitude of the sine harmonic correction term to the orbit radius [m] */
  double c_rc;        /**< Amplitude of the cosine harmonic correction term to the orbit radius [m] */
  double c_uc;        /**< Amplitude of the cosine harmonic correction term to the argument of latitude [rad] */
  double c_us;        /**< Amplitude of the sine harmonic correction term to the argument of latitude [rad] */
  double c_ic;        /**< Amplitude of the cosine harmonic correction term to the angle of inclination [rad] */
  double c_is;        /**< Amplitude of the sine harmonic correction term to the angle of inclination [rad] */
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
} msg_ephemeris_deprecated_t;


/** \} */

#endif /* LIBSBP_DEPRECATED_MESSAGES_H */