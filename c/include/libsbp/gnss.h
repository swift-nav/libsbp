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

#ifndef LIBSBP_PACKED_GNSS_MESSAGES_H
#define LIBSBP_PACKED_GNSS_MESSAGES_H

#ifdef SBP_DISABLE_PACKED_HEADERS
#error "Packed SBP headers are disabled"
#endif

#include <libsbp/common.h>

SBP_PACK_START


#define SBP_GNSSSIGNAL__MASK (0xff)
#define SBP_GNSSSIGNAL__SHIFT (0u)
#define SBP_GNSSSIGNAL__GET(flags) \
                             (((flags) >> SBP_GNSSSIGNAL__SHIFT) \
                             & SBP_GNSSSIGNAL__MASK)
#define SBP_GNSSSIGNAL__SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_GNSSSIGNAL__MASK)) \
                             << (SBP_GNSSSIGNAL__SHIFT)));} while(0)
                             

#define SBP_GNSSSIGNAL__GPS_L1CA (0)
#define SBP_GNSSSIGNAL__GPS_L2CM (1)
#define SBP_GNSSSIGNAL__SBAS_L1CA (2)
#define SBP_GNSSSIGNAL__GLO_L1CA (3)
#define SBP_GNSSSIGNAL__GLO_L2CA (4)
#define SBP_GNSSSIGNAL__GPS_L1P (5)
#define SBP_GNSSSIGNAL__GPS_L2P (6)
#define SBP_GNSSSIGNAL__BDS2_B1 (12)
#define SBP_GNSSSIGNAL__BDS2_B2 (13)
#define SBP_GNSSSIGNAL__GAL_E1B (14)
#define SBP_GNSSSIGNAL__GAL_E7I (20)
#define SBP_GNSSSIGNAL__BDS3_B2A (47)
/** Represents all the relevant information about the signal
 *
 * Signal identifier containing constellation, band, and satellite identifier
 */
typedef struct SBP_ATTR_PACKED {
  
  /** 
    * Constellation-specific satellite identifier. This field for Glonass can  
 * either be (100+FCN) where FCN is in [-7,+6] or 
 * the Slot ID in [1,28] 
   */
  u8 sat;    
  
  /** 
   * Signal constellation, band and code 
   */
  u8 code;   
  
} sbp_gnss_signal_t;


/** Space vehicle identifier
 *
 * A (Constellation ID, satellite ID) tuple that uniquely identifies
 * a space vehicle
 */
typedef struct SBP_ATTR_PACKED {
  
  /** 
   * ID of the space vehicle within its constellation 
   */
  u8 satId;           
  
  /** 
   * Constellation ID to which the SV belongs 
   */
  u8 constellation;   
  
} sv_id_t;


#define SBP_GNSSSIGNALDEP__MASK (0xff)
#define SBP_GNSSSIGNALDEP__SHIFT (0u)
#define SBP_GNSSSIGNALDEP__GET(flags) \
                             (((flags) >> SBP_GNSSSIGNALDEP__SHIFT) \
                             & SBP_GNSSSIGNALDEP__MASK)
#define SBP_GNSSSIGNALDEP__SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_GNSSSIGNALDEP__MASK)) \
                             << (SBP_GNSSSIGNALDEP__SHIFT)));} while(0)
                             

#define SBP_GNSSSIGNALDEP__GPS_L1CA (0)
#define SBP_GNSSSIGNALDEP__GPS_L2CM (1)
#define SBP_GNSSSIGNALDEP__SBAS_L1CA (2)
#define SBP_GNSSSIGNALDEP__GLO_L1CA (3)
#define SBP_GNSSSIGNALDEP__GLO_L2CA (4)
#define SBP_GNSSSIGNALDEP__GPS_L1P (5)
#define SBP_GNSSSIGNALDEP__GPS_L2P (6)
/** Deprecated
 *
* Deprecated.
 */
typedef struct SBP_ATTR_PACKED {
  
  /** 
    * Constellation-specific satellite identifier.
 * 
 * Note: unlike GnssSignal, GPS satellites are encoded as
 * (PRN - 1). Other constellations do not have this offset. 
   */
  u16 sat;        
  
  /** 
   * Signal constellation, band and code 
   */
  u8 code;       
  
  /** 
   * Reserved 
   */
  u8 reserved;   
  
} gnss_signal_dep_t;


/** Millisecond-accurate GPS time
 *
 * A wire-appropriate GPS time, defined as the number of
 * milliseconds since beginning of the week on the Saturday/Sunday
 * transition.
 */
typedef struct SBP_ATTR_PACKED {
  
  /** 
   * Milliseconds since start of GPS week [ms] 
   */
  u32 tow;   
  
  /** 
   * GPS week number [week] 
   */
  u16 wn;    
  
} gps_time_dep_t;


/** Whole second accurate GPS time
 *
 * A GPS time, defined as the number of
 * seconds since beginning of the week on the Saturday/Sunday
 * transition.
 */
typedef struct SBP_ATTR_PACKED {
  
  /** 
   * Seconds since start of GPS week [s] 
   */
  u32 tow;   
  
  /** 
   * GPS week number [week] 
   */
  u16 wn;    
  
} gps_time_sec_t;


/** Nanosecond-accurate receiver clock time
 *
 * A wire-appropriate receiver clock time, defined as the time
 * since the beginning of the week on the Saturday/Sunday
 * transition. In most cases, observations are epoch aligned
 * so ns field will be 0.
 */
typedef struct SBP_ATTR_PACKED {
  
  /** 
   * Milliseconds since start of GPS week [ms] 
   */
  u32 tow;           
  
  /** 
    * Nanosecond residual of millisecond-rounded TOW (ranges
 * from -500000 to 500000) [ns] 
   */
  s32 ns_residual;   
  
  /** 
   * GPS week number [week] 
   */
  u16 wn;            
  
} sbp_gps_time_t;


/** GNSS carrier phase measurement.
 *
 * Carrier phase measurement in cycles represented as a 40-bit
 * fixed point number with Q32.8 layout, i.e. 32-bits of whole
 * cycles and 8-bits of fractional cycles. This phase has the
 * same sign as the pseudorange.
 */
typedef struct SBP_ATTR_PACKED {
  
  /** 
   * Carrier phase whole cycles [cycles] 
   */
  s32 i;   
  
  /** 
   * Carrier phase fractional part [cycles / 256] 
   */
  u8 f;   
  
} carrier_phase_t;


/** \} */

SBP_PACK_END

#endif /* LIBSBP_GNSS_MESSAGES_H */
