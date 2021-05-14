/*
 * Copyright (C) 2015-2018 Swift Navigation Inc.
 * Contact: https://support.swiftnav.com
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

SBP_PACK_START
#ifdef __ghs__
#pragma pack(1)
#endif


/** Represents all the relevant information about the signal
 *
 * Signal identifier containing constellation, band, and satellite identifier
 */

typedef struct SBP_ATTR_PACKED {
  u8 sat;     /**< Constellation-specific satellite identifier. This field for Glonass can  
either be (100+FCN) where FCN is in [-7,+6] or 
the Slot ID in [1,28]
 */
  u8 code;    /**< Signal constellation, band and code */
} sbp_gnss_signal_t;
 

/** Space vehicle identifier
 *
 * A (Constellation ID, satellite ID) tuple that uniquely identifies
 * a space vehicle
 */

typedef struct SBP_ATTR_PACKED {
  u8 satId;            /**< ID of the space vehicle within its constellation */
  u8 constellation;    /**< Constellation ID to which the SV belongs */
} sv_id_t;
 

/** Deprecated
 *
* Deprecated.
 */

typedef struct SBP_ATTR_PACKED {
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

typedef struct SBP_ATTR_PACKED {
  u32 tow;    /**< Milliseconds since start of GPS week [ms] */
  u16 wn;     /**< GPS week number [week] */
} gps_time_dep_t;
 

/** Whole second accurate GPS time
 *
 * A GPS time, defined as the number of
 * seconds since beginning of the week on the Saturday/Sunday
 * transition.
 */

typedef struct SBP_ATTR_PACKED {
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

typedef struct SBP_ATTR_PACKED {
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

typedef struct SBP_ATTR_PACKED {
  s32 i;    /**< Carrier phase whole cycles [cycles] */
  u8 f;    /**< Carrier phase fractional part [cycles / 256] */
} carrier_phase_t;
 

/** \} */
static inline void static_asserts_for_module_GnssSignal(void) {
#ifdef __cplusplus
static_assert(offsetof(sbp_gnss_signal_t, sat ) == 0, "Offset of sat in sbp_gnss_signal_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(sbp_gnss_signal_t, sat ) == 0, offset_of_sat_in_sbp_gnss_signal_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(sbp_gnss_signal_t, code ) == 0 + sizeof(u8), "Offset of code in sbp_gnss_signal_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(sbp_gnss_signal_t, code ) == 0 + sizeof(u8), offset_of_code_in_sbp_gnss_signal_t_is_incorrect)
#endif
}

static inline void static_asserts_for_module_SvId(void) {
#ifdef __cplusplus
static_assert(offsetof(sv_id_t, satId ) == 0, "Offset of satId in sv_id_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(sv_id_t, satId ) == 0, offset_of_satId_in_sv_id_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(sv_id_t, constellation ) == 0 + sizeof(u8), "Offset of constellation in sv_id_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(sv_id_t, constellation ) == 0 + sizeof(u8), offset_of_constellation_in_sv_id_t_is_incorrect)
#endif
}

static inline void static_asserts_for_module_GnssSignalDep(void) {
#ifdef __cplusplus
static_assert(offsetof(gnss_signal_dep_t, sat ) == 0, "Offset of sat in gnss_signal_dep_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(gnss_signal_dep_t, sat ) == 0, offset_of_sat_in_gnss_signal_dep_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(gnss_signal_dep_t, code ) == 0 + sizeof(u16), "Offset of code in gnss_signal_dep_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(gnss_signal_dep_t, code ) == 0 + sizeof(u16), offset_of_code_in_gnss_signal_dep_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(gnss_signal_dep_t, reserved ) == 0 + sizeof(u16) + sizeof(u8), "Offset of reserved in gnss_signal_dep_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(gnss_signal_dep_t, reserved ) == 0 + sizeof(u16) + sizeof(u8), offset_of_reserved_in_gnss_signal_dep_t_is_incorrect)
#endif
}

static inline void static_asserts_for_module_GPSTimeDep(void) {
#ifdef __cplusplus
static_assert(offsetof(gps_time_dep_t, tow ) == 0, "Offset of tow in gps_time_dep_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(gps_time_dep_t, tow ) == 0, offset_of_tow_in_gps_time_dep_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(gps_time_dep_t, wn ) == 0 + sizeof(u32), "Offset of wn in gps_time_dep_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(gps_time_dep_t, wn ) == 0 + sizeof(u32), offset_of_wn_in_gps_time_dep_t_is_incorrect)
#endif
}

static inline void static_asserts_for_module_GPSTimeSec(void) {
#ifdef __cplusplus
static_assert(offsetof(gps_time_sec_t, tow ) == 0, "Offset of tow in gps_time_sec_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(gps_time_sec_t, tow ) == 0, offset_of_tow_in_gps_time_sec_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(gps_time_sec_t, wn ) == 0 + sizeof(u32), "Offset of wn in gps_time_sec_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(gps_time_sec_t, wn ) == 0 + sizeof(u32), offset_of_wn_in_gps_time_sec_t_is_incorrect)
#endif
}

static inline void static_asserts_for_module_GPSTime(void) {
#ifdef __cplusplus
static_assert(offsetof(sbp_gps_time_t, tow ) == 0, "Offset of tow in sbp_gps_time_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(sbp_gps_time_t, tow ) == 0, offset_of_tow_in_sbp_gps_time_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(sbp_gps_time_t, ns_residual ) == 0 + sizeof(u32), "Offset of ns_residual in sbp_gps_time_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(sbp_gps_time_t, ns_residual ) == 0 + sizeof(u32), offset_of_ns_residual_in_sbp_gps_time_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(sbp_gps_time_t, wn ) == 0 + sizeof(u32) + sizeof(s32), "Offset of wn in sbp_gps_time_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(sbp_gps_time_t, wn ) == 0 + sizeof(u32) + sizeof(s32), offset_of_wn_in_sbp_gps_time_t_is_incorrect)
#endif
}

static inline void static_asserts_for_module_CarrierPhase(void) {
#ifdef __cplusplus
static_assert(offsetof(carrier_phase_t, i ) == 0, "Offset of i in carrier_phase_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(carrier_phase_t, i ) == 0, offset_of_i_in_carrier_phase_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(carrier_phase_t, f ) == 0 + sizeof(s32), "Offset of f in carrier_phase_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(carrier_phase_t, f ) == 0 + sizeof(s32), offset_of_f_in_carrier_phase_t_is_incorrect)
#endif
}


#ifdef __ghs__
#pragma pack()
#endif
SBP_PACK_END

#endif /* LIBSBP_GNSS_MESSAGES_H */
