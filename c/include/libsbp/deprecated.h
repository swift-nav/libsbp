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


/** Deprecated
 *
* Deprecated.
 */
#define SBP_MSG_BOOTLOADER_HANDSHAKE_DEPRECATED 0x00B0
typedef struct __attribute__((packed)) {
  u8 handshake[0]; /**< Version number string (not NULL terminated) */
} msg_bootloader_handshake_deprecated_t;


/** Deprecated
 *
* Deprecated.
 */
#define SBP_MSG_NAP_DEVICE_DNA_DEPRECATED       0x00DD
typedef struct __attribute__((packed)) {
  u8 dna[8]; /**< 57-bit SwiftNAP FPGA Device ID. Remaining bits are padded
on the right.
 */
} msg_nap_device_dna_deprecated_t;


/** Deprecated
 *
* Deprecated.
 */
#define SBP_MSG_FLASH_PROGRAM_DEPRECATED        0x00E0
typedef struct __attribute__((packed)) {
  u8 target;        /**< Target flags */
  u8 addr_start[3]; /**< Starting address offset to program [bytes] */
  u8 addr_len;      /**< Length of set of addresses to program, counting up from
starting address
 [bytes] */
  u8 data[0];       /**< Data to program addresses with, with length N=addr_len */
} msg_flash_program_deprecated_t;


/** Deprecated
 *
* Deprecated.
 */
#define SBP_MSG_FLASH_READ_DEPRECATED           0x00E1
typedef struct __attribute__((packed)) {
  u8 target;        /**< Target flags */
  u8 addr_start[3]; /**< Starting address offset to read from [bytes] */
  u8 addr_len;      /**< Length of set of addresses to read, counting up from
starting address
 [bytes] */
} msg_flash_read_deprecated_t;


/** Deprecated
 *
* Deprecated.
 */
#define SBP_MSG_STM_UNIQUE_ID_DEPRECATED        0x00E5
typedef struct __attribute__((packed)) {
  u8 stm_id[12]; /**< Device unique ID */
} msg_stm_unique_id_deprecated_t;


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