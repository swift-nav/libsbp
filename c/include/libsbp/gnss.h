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
 * Automatically generated from yaml/swiftnav/sbp/gnss.yaml
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

/** \defgroup gnss Gnss
 *
 * * Various structs shared between modules
 * \{ */

#ifndef LIBSBP_GNSS_MESSAGES_H
#define LIBSBP_GNSS_MESSAGES_H

#include "common.h"

#if defined _MSC_VER || defined TOOLCHAIN_PRAGMA_PACK
#pragma pack(1)
#endif


/** Represents all the relevant information about the signal
 *
 * Signal identifier containing constellation, band, and satellite identifier
 */
#if defined _MSC_VER || defined TOOLCHAIN_PRAGMA_PACKED
typedef struct {
#else
typedef struct __attribute__((packed)) {
#endif
  u8 sat;     /**< Constellation-specific satellite identifier. This field for Glonass can  
either be (100+FCN) where FCN is in [-7,+6] or 
the Slot ID in [1,28]
 */
  u8 code;    /**< Signal constellation, band and code */
} sbp_gnss_signal_t;


/** Deprecated
 *
* Deprecated.
 */
#if defined _MSC_VER || defined TOOLCHAIN_PRAGMA_PACKED
typedef struct {
#else
typedef struct __attribute__((packed)) {
#endif
  u16 sat;         /**< Constellation-specific satellite identifier.

Note: unlike GnssSignal, GPS satellites are encoded as
(PRN - 1). Other constellations do not have this offset.
 */
  u8 code;        /**< Signal constellation, band and code */
  u8 reserved;    /**< Reserved */
} gnss_signal_dep_t;


/** Millisecond-accurate GPS time
 *
 * A wire-appropriate GPS time, defined as the number of
 * milliseconds since beginning of the week on the Saturday/Sunday
 * transition.
 */
#if defined _MSC_VER || defined TOOLCHAIN_PRAGMA_PACKED
typedef struct {
#else
typedef struct __attribute__((packed)) {
#endif
  u32 tow;    /**< Milliseconds since start of GPS week [ms] */
  u16 wn;     /**< GPS week number [week] */
} gps_time_dep_t;


/** Whole second accurate GPS time
 *
 * A GPS time, defined as the number of
 * seconds since beginning of the week on the Saturday/Sunday
 * transition.
 */
#if defined _MSC_VER || defined TOOLCHAIN_PRAGMA_PACKED
typedef struct {
#else
typedef struct __attribute__((packed)) {
#endif
  u32 tow;    /**< Seconds since start of GPS week [s] */
  u16 wn;     /**< GPS week number [week] */
} gps_time_sec_t;


/** Nanosecond-accurate receiver clock time
 *
 * A wire-appropriate receiver clock time, defined as the time
 * since the beginning of the week on the Saturday/Sunday
 * transition. In most cases, observations are epoch aligned
 * so ns field will be 0.
 */
#if defined _MSC_VER || defined TOOLCHAIN_PRAGMA_PACKED
typedef struct {
#else
typedef struct __attribute__((packed)) {
#endif
  u32 tow;            /**< Milliseconds since start of GPS week [ms] */
  s32 ns_residual;    /**< Nanosecond residual of millisecond-rounded TOW (ranges
from -500000 to 500000)
 [ns] */
  u16 wn;             /**< GPS week number [week] */
} sbp_gps_time_t;


/** GNSS carrier phase measurement.
 *
 * Carrier phase measurement in cycles represented as a 40-bit
 * fixed point number with Q32.8 layout, i.e. 32-bits of whole
 * cycles and 8-bits of fractional cycles. This phase has the
 * same sign as the pseudorange.
 */
#if defined _MSC_VER || defined TOOLCHAIN_PRAGMA_PACKED
typedef struct {
#else
typedef struct __attribute__((packed)) {
#endif
  s32 i;    /**< Carrier phase whole cycles [cycles] */
  u8 f;    /**< Carrier phase fractional part [cycles / 256] */
} carrier_phase_t;


/** \} */

#if defined _MSC_VER || defined TOOLCHAIN_PRAGMA_PACK
#pragma pack()
#endif

#endif /* LIBSBP_GNSS_MESSAGES_H */