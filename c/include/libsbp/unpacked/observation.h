#ifndef LIBSBP_OBSERVATION_MESSAGES_H
#define LIBSBP_OBSERVATION_MESSAGES_H

#include <stdbool.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>
#include <endian.h>
#include <math.h>

#include <libsbp/common.h>
#include <libsbp/string.h>
#include <libsbp/unpacked/gnss.h>
  /** Header for observation message.
   *
* Header of a GNSS observation message.
   */

	
typedef struct {
  
  /**
* GNSS time of this observation
   */
  sbp_sbp_gps_time_t
  t
  ;
  /**
 * Total number of observations. First nibble is the size
 * of the sequence (n), second nibble is the zero-indexed
 * counter (ith packet of n)
   */
    u8
  n_obs
  ;
} sbp_observation_header_t;


  /** GNSS doppler measurement.
   *
 * Doppler measurement in Hz represented as a 24-bit
 * fixed point number with Q16.8 layout, i.e. 16-bits of whole
 * doppler and 8-bits of fractional doppler. This doppler is defined
 * as positive for approaching satellites.
   */

typedef struct {
  
  /**
* Doppler whole Hz[Hz]
   */
    s16
  i
  ;
  /**
* Doppler fractional part[Hz / 256]
   */
    u8
  f
  ;
} sbp_doppler_t;


  /** GNSS observations for a particular satellite signal.
   *
 * Pseudorange and carrier phase observation for a satellite being tracked.
 * The observations are interoperable with 3rd party receivers and conform with
 * typical RTCM 3.1 message GPS/GLO observations.
 * 
 * Carrier phase observations are not guaranteed to be aligned to the RINEX 3
 * or RTCM 3.3 MSM reference signal and no 1/4 cycle adjustments are currently
 * peformed.
   */

	
	
	#define SBP_PACKEDOBSCONTENT_FLAGS_RAIM_EXCLUSION_MASK (0x1)
#define SBP_PACKEDOBSCONTENT_FLAGS_RAIM_EXCLUSION_SHIFT (7u)
#define SBP_PACKEDOBSCONTENT_FLAGS_RAIM_EXCLUSION_GET(flags) \
                             (((flags) >> SBP_PACKEDOBSCONTENT_FLAGS_RAIM_EXCLUSION_SHIFT) \
                             & SBP_PACKEDOBSCONTENT_FLAGS_RAIM_EXCLUSION_MASK)
#define SBP_PACKEDOBSCONTENT_FLAGS_RAIM_EXCLUSION_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_PACKEDOBSCONTENT_FLAGS_RAIM_EXCLUSION_MASK)) \
                             << (SBP_PACKEDOBSCONTENT_FLAGS_RAIM_EXCLUSION_SHIFT)));} while(0)
                             

#define SBP_PACKEDOBSCONTENT_FLAGS_RAIM_EXCLUSION_NO_EXCLUSION (0)
#define SBP_PACKEDOBSCONTENT_FLAGS_RAIM_EXCLUSION_MEASUREMENT_WAS_EXCLUDED_BY_SPP_RAIM_USE_WITH_CARE (1)
#define SBP_PACKEDOBSCONTENT_FLAGS_DOPPLER_VALID_MASK (0x1)
#define SBP_PACKEDOBSCONTENT_FLAGS_DOPPLER_VALID_SHIFT (3u)
#define SBP_PACKEDOBSCONTENT_FLAGS_DOPPLER_VALID_GET(flags) \
                             (((flags) >> SBP_PACKEDOBSCONTENT_FLAGS_DOPPLER_VALID_SHIFT) \
                             & SBP_PACKEDOBSCONTENT_FLAGS_DOPPLER_VALID_MASK)
#define SBP_PACKEDOBSCONTENT_FLAGS_DOPPLER_VALID_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_PACKEDOBSCONTENT_FLAGS_DOPPLER_VALID_MASK)) \
                             << (SBP_PACKEDOBSCONTENT_FLAGS_DOPPLER_VALID_SHIFT)));} while(0)
                             

#define SBP_PACKEDOBSCONTENT_FLAGS_DOPPLER_VALID_INVALID_DOPPLER_MEASUREMENT (0)
#define SBP_PACKEDOBSCONTENT_FLAGS_DOPPLER_VALID_VALID_DOPPLER_MEASUREMENT (1)
#define SBP_PACKEDOBSCONTENT_FLAGS_HALFCYCLE_AMBIGUITY_MASK (0x1)
#define SBP_PACKEDOBSCONTENT_FLAGS_HALFCYCLE_AMBIGUITY_SHIFT (2u)
#define SBP_PACKEDOBSCONTENT_FLAGS_HALFCYCLE_AMBIGUITY_GET(flags) \
                             (((flags) >> SBP_PACKEDOBSCONTENT_FLAGS_HALFCYCLE_AMBIGUITY_SHIFT) \
                             & SBP_PACKEDOBSCONTENT_FLAGS_HALFCYCLE_AMBIGUITY_MASK)
#define SBP_PACKEDOBSCONTENT_FLAGS_HALFCYCLE_AMBIGUITY_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_PACKEDOBSCONTENT_FLAGS_HALFCYCLE_AMBIGUITY_MASK)) \
                             << (SBP_PACKEDOBSCONTENT_FLAGS_HALFCYCLE_AMBIGUITY_SHIFT)));} while(0)
                             

#define SBP_PACKEDOBSCONTENT_FLAGS_HALFCYCLE_AMBIGUITY_HALF_CYCLE_PHASE_AMBIGUITY_UNRESOLVED (0)
#define SBP_PACKEDOBSCONTENT_FLAGS_HALFCYCLE_AMBIGUITY_HALF_CYCLE_PHASE_AMBIGUITY_RESOLVED (1)
#define SBP_PACKEDOBSCONTENT_FLAGS_CARRIER_PHASE_VALID_MASK (0x1)
#define SBP_PACKEDOBSCONTENT_FLAGS_CARRIER_PHASE_VALID_SHIFT (1u)
#define SBP_PACKEDOBSCONTENT_FLAGS_CARRIER_PHASE_VALID_GET(flags) \
                             (((flags) >> SBP_PACKEDOBSCONTENT_FLAGS_CARRIER_PHASE_VALID_SHIFT) \
                             & SBP_PACKEDOBSCONTENT_FLAGS_CARRIER_PHASE_VALID_MASK)
#define SBP_PACKEDOBSCONTENT_FLAGS_CARRIER_PHASE_VALID_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_PACKEDOBSCONTENT_FLAGS_CARRIER_PHASE_VALID_MASK)) \
                             << (SBP_PACKEDOBSCONTENT_FLAGS_CARRIER_PHASE_VALID_SHIFT)));} while(0)
                             

#define SBP_PACKEDOBSCONTENT_FLAGS_CARRIER_PHASE_VALID_INVALID_CARRIER_PHASE_MEASUREMENT (0)
#define SBP_PACKEDOBSCONTENT_FLAGS_CARRIER_PHASE_VALID_VALID_CARRIER_PHASE_MEASUREMENT (1)
#define SBP_PACKEDOBSCONTENT_FLAGS_PSEUDORANGE_VALID_MASK (0x1)
#define SBP_PACKEDOBSCONTENT_FLAGS_PSEUDORANGE_VALID_SHIFT (0u)
#define SBP_PACKEDOBSCONTENT_FLAGS_PSEUDORANGE_VALID_GET(flags) \
                             (((flags) >> SBP_PACKEDOBSCONTENT_FLAGS_PSEUDORANGE_VALID_SHIFT) \
                             & SBP_PACKEDOBSCONTENT_FLAGS_PSEUDORANGE_VALID_MASK)
#define SBP_PACKEDOBSCONTENT_FLAGS_PSEUDORANGE_VALID_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_PACKEDOBSCONTENT_FLAGS_PSEUDORANGE_VALID_MASK)) \
                             << (SBP_PACKEDOBSCONTENT_FLAGS_PSEUDORANGE_VALID_SHIFT)));} while(0)
                             

#define SBP_PACKEDOBSCONTENT_FLAGS_PSEUDORANGE_VALID_INVALID_PSEUDORANGE_MEASUREMENT (0)
#define SBP_PACKEDOBSCONTENT_FLAGS_PSEUDORANGE_VALID_VALID_PSEUDORANGE_MEASUREMENT_AND_COARSE_TOW_DECODED (1)
	
	#define SBP_PACKEDOBSCONTENT_SID_CODE__MASK (0xff)
#define SBP_PACKEDOBSCONTENT_SID_CODE__SHIFT (0u)
#define SBP_PACKEDOBSCONTENT_SID_CODE__GET(flags) \
                             (((flags) >> SBP_PACKEDOBSCONTENT_SID_CODE__SHIFT) \
                             & SBP_PACKEDOBSCONTENT_SID_CODE__MASK)
#define SBP_PACKEDOBSCONTENT_SID_CODE__SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_PACKEDOBSCONTENT_SID_CODE__MASK)) \
                             << (SBP_PACKEDOBSCONTENT_SID_CODE__SHIFT)));} while(0)
                             

#define SBP_PACKEDOBSCONTENT_SID_CODE__GPS_L1CA (0)
#define SBP_PACKEDOBSCONTENT_SID_CODE__GPS_L2CM (1)
#define SBP_PACKEDOBSCONTENT_SID_CODE__SBAS_L1CA (2)
#define SBP_PACKEDOBSCONTENT_SID_CODE__GLO_L1CA (3)
#define SBP_PACKEDOBSCONTENT_SID_CODE__GLO_L2CA (4)
#define SBP_PACKEDOBSCONTENT_SID_CODE__GPS_L1P (5)
#define SBP_PACKEDOBSCONTENT_SID_CODE__GPS_L2P (6)
#define SBP_PACKEDOBSCONTENT_SID_CODE__BDS2_B1 (12)
#define SBP_PACKEDOBSCONTENT_SID_CODE__BDS2_B2 (13)
#define SBP_PACKEDOBSCONTENT_SID_CODE__GAL_E1B (14)
#define SBP_PACKEDOBSCONTENT_SID_CODE__GAL_E7I (20)
#define SBP_PACKEDOBSCONTENT_SID_CODE__BDS3_B2A (47)
typedef struct {
  
  /**
* Pseudorange observation[2 cm]
   */
    u32
  P
  ;
  /**
* Carrier phase observation with typical sign convention.[cycles]
   */
  sbp_carrier_phase_t
  L
  ;
  /**
* Doppler observation with typical sign convention.[Hz]
   */
  sbp_doppler_t
  D
  ;
  /**
* Carrier-to-Noise density.  Zero implies invalid cn0.[dB Hz / 4]
   */
    u8
  cn0
  ;
  /**
 * Lock timer. This value gives an indication of the time
 * for which a signal has maintained continuous phase lock.
 * Whenever a signal has lost and regained lock, this
 * value is reset to zero. It is encoded according to DF402 from
 * the RTCM 10403.2 Amendment 2 specification.  Valid values range
 * from 0 to 15 and the most significant nibble is reserved for future use.
   */
    u8
  lock
  ;
  /**
 * Measurement status flags. A bit field of flags providing the
 * status of this observation.  If this field is 0 it means only the Cn0
 * estimate for the signal is valid.
   */
    u8
  flags
  ;
  /**
* GNSS signal identifier (16 bit)
   */
  sbp_sbp_gnss_signal_t
  sid
  ;
} sbp_packed_obs_content_t;


  /** Network correction for a particular satellite signal.
   *
 * Pseudorange and carrier phase network corrections for a satellite signal.
   */

	
	#define SBP_PACKEDOSRCONTENT_FLAGS_INVALID_PHASE_CORRECTIONS_MASK (0x1)
#define SBP_PACKEDOSRCONTENT_FLAGS_INVALID_PHASE_CORRECTIONS_SHIFT (4u)
#define SBP_PACKEDOSRCONTENT_FLAGS_INVALID_PHASE_CORRECTIONS_GET(flags) \
                             (((flags) >> SBP_PACKEDOSRCONTENT_FLAGS_INVALID_PHASE_CORRECTIONS_SHIFT) \
                             & SBP_PACKEDOSRCONTENT_FLAGS_INVALID_PHASE_CORRECTIONS_MASK)
#define SBP_PACKEDOSRCONTENT_FLAGS_INVALID_PHASE_CORRECTIONS_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_PACKEDOSRCONTENT_FLAGS_INVALID_PHASE_CORRECTIONS_MASK)) \
                             << (SBP_PACKEDOSRCONTENT_FLAGS_INVALID_PHASE_CORRECTIONS_SHIFT)));} while(0)
                             

#define SBP_PACKEDOSRCONTENT_FLAGS_INVALID_PHASE_CORRECTIONS_VALID_PHASE_CORRECTIONS (0)
#define SBP_PACKEDOSRCONTENT_FLAGS_INVALID_PHASE_CORRECTIONS_DO_NOT_USE_PHASE_CORRECTIONS (1)
#define SBP_PACKEDOSRCONTENT_FLAGS_INVALID_CODE_CORRECTIONS_MASK (0x1)
#define SBP_PACKEDOSRCONTENT_FLAGS_INVALID_CODE_CORRECTIONS_SHIFT (3u)
#define SBP_PACKEDOSRCONTENT_FLAGS_INVALID_CODE_CORRECTIONS_GET(flags) \
                             (((flags) >> SBP_PACKEDOSRCONTENT_FLAGS_INVALID_CODE_CORRECTIONS_SHIFT) \
                             & SBP_PACKEDOSRCONTENT_FLAGS_INVALID_CODE_CORRECTIONS_MASK)
#define SBP_PACKEDOSRCONTENT_FLAGS_INVALID_CODE_CORRECTIONS_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_PACKEDOSRCONTENT_FLAGS_INVALID_CODE_CORRECTIONS_MASK)) \
                             << (SBP_PACKEDOSRCONTENT_FLAGS_INVALID_CODE_CORRECTIONS_SHIFT)));} while(0)
                             

#define SBP_PACKEDOSRCONTENT_FLAGS_INVALID_CODE_CORRECTIONS_VALID_CODE_CORRECTIONS (0)
#define SBP_PACKEDOSRCONTENT_FLAGS_INVALID_CODE_CORRECTIONS_DO_NOT_USE_CODE_CORRECTIONS (1)
#define SBP_PACKEDOSRCONTENT_FLAGS_FULL_FIXING_FLAG_MASK (0x1)
#define SBP_PACKEDOSRCONTENT_FLAGS_FULL_FIXING_FLAG_SHIFT (2u)
#define SBP_PACKEDOSRCONTENT_FLAGS_FULL_FIXING_FLAG_GET(flags) \
                             (((flags) >> SBP_PACKEDOSRCONTENT_FLAGS_FULL_FIXING_FLAG_SHIFT) \
                             & SBP_PACKEDOSRCONTENT_FLAGS_FULL_FIXING_FLAG_MASK)
#define SBP_PACKEDOSRCONTENT_FLAGS_FULL_FIXING_FLAG_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_PACKEDOSRCONTENT_FLAGS_FULL_FIXING_FLAG_MASK)) \
                             << (SBP_PACKEDOSRCONTENT_FLAGS_FULL_FIXING_FLAG_SHIFT)));} while(0)
                             

#define SBP_PACKEDOSRCONTENT_FLAGS_FULL_FIXING_FLAG_FULL_FIXING_UNAVAILABLE (0)
#define SBP_PACKEDOSRCONTENT_FLAGS_FULL_FIXING_FLAG_FULL_FIXING_AVAILABLE (1)
#define SBP_PACKEDOSRCONTENT_FLAGS_PARTIAL_FIXING_FLAG_MASK (0x1)
#define SBP_PACKEDOSRCONTENT_FLAGS_PARTIAL_FIXING_FLAG_SHIFT (1u)
#define SBP_PACKEDOSRCONTENT_FLAGS_PARTIAL_FIXING_FLAG_GET(flags) \
                             (((flags) >> SBP_PACKEDOSRCONTENT_FLAGS_PARTIAL_FIXING_FLAG_SHIFT) \
                             & SBP_PACKEDOSRCONTENT_FLAGS_PARTIAL_FIXING_FLAG_MASK)
#define SBP_PACKEDOSRCONTENT_FLAGS_PARTIAL_FIXING_FLAG_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_PACKEDOSRCONTENT_FLAGS_PARTIAL_FIXING_FLAG_MASK)) \
                             << (SBP_PACKEDOSRCONTENT_FLAGS_PARTIAL_FIXING_FLAG_SHIFT)));} while(0)
                             

#define SBP_PACKEDOSRCONTENT_FLAGS_PARTIAL_FIXING_FLAG_PARTIAL_FIXING_UNAVAILABLE (0)
#define SBP_PACKEDOSRCONTENT_FLAGS_PARTIAL_FIXING_FLAG_PARTIAL_FIXING_AVAILABLE (1)
#define SBP_PACKEDOSRCONTENT_FLAGS_CORRECTION_VALIDITY_MASK (0x1)
#define SBP_PACKEDOSRCONTENT_FLAGS_CORRECTION_VALIDITY_SHIFT (0u)
#define SBP_PACKEDOSRCONTENT_FLAGS_CORRECTION_VALIDITY_GET(flags) \
                             (((flags) >> SBP_PACKEDOSRCONTENT_FLAGS_CORRECTION_VALIDITY_SHIFT) \
                             & SBP_PACKEDOSRCONTENT_FLAGS_CORRECTION_VALIDITY_MASK)
#define SBP_PACKEDOSRCONTENT_FLAGS_CORRECTION_VALIDITY_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_PACKEDOSRCONTENT_FLAGS_CORRECTION_VALIDITY_MASK)) \
                             << (SBP_PACKEDOSRCONTENT_FLAGS_CORRECTION_VALIDITY_SHIFT)));} while(0)
                             

#define SBP_PACKEDOSRCONTENT_FLAGS_CORRECTION_VALIDITY_DO_NOT_USE_SIGNAL (0)
#define SBP_PACKEDOSRCONTENT_FLAGS_CORRECTION_VALIDITY_VALID_SIGNAL (1)
	
	#define SBP_PACKEDOSRCONTENT_SID_CODE__MASK (0xff)
#define SBP_PACKEDOSRCONTENT_SID_CODE__SHIFT (0u)
#define SBP_PACKEDOSRCONTENT_SID_CODE__GET(flags) \
                             (((flags) >> SBP_PACKEDOSRCONTENT_SID_CODE__SHIFT) \
                             & SBP_PACKEDOSRCONTENT_SID_CODE__MASK)
#define SBP_PACKEDOSRCONTENT_SID_CODE__SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_PACKEDOSRCONTENT_SID_CODE__MASK)) \
                             << (SBP_PACKEDOSRCONTENT_SID_CODE__SHIFT)));} while(0)
                             

#define SBP_PACKEDOSRCONTENT_SID_CODE__GPS_L1CA (0)
#define SBP_PACKEDOSRCONTENT_SID_CODE__GPS_L2CM (1)
#define SBP_PACKEDOSRCONTENT_SID_CODE__SBAS_L1CA (2)
#define SBP_PACKEDOSRCONTENT_SID_CODE__GLO_L1CA (3)
#define SBP_PACKEDOSRCONTENT_SID_CODE__GLO_L2CA (4)
#define SBP_PACKEDOSRCONTENT_SID_CODE__GPS_L1P (5)
#define SBP_PACKEDOSRCONTENT_SID_CODE__GPS_L2P (6)
#define SBP_PACKEDOSRCONTENT_SID_CODE__BDS2_B1 (12)
#define SBP_PACKEDOSRCONTENT_SID_CODE__BDS2_B2 (13)
#define SBP_PACKEDOSRCONTENT_SID_CODE__GAL_E1B (14)
#define SBP_PACKEDOSRCONTENT_SID_CODE__GAL_E7I (20)
#define SBP_PACKEDOSRCONTENT_SID_CODE__BDS3_B2A (47)
typedef struct {
  
  /**
* Pseudorange observation[2 cm]
   */
    u32
  P
  ;
  /**
* Carrier phase observation with typical sign convention.[cycles]
   */
  sbp_carrier_phase_t
  L
  ;
  /**
 * Lock timer. This value gives an indication of the time
 * for which a signal has maintained continuous phase lock.
 * Whenever a signal has lost and regained lock, this
 * value is reset to zero. It is encoded according to DF402 from
 * the RTCM 10403.2 Amendment 2 specification.  Valid values range
 * from 0 to 15 and the most significant nibble is reserved for future use.
   */
    u8
  lock
  ;
  /**
 * Correction flags.
   */
    u8
  flags
  ;
  /**
* GNSS signal identifier (16 bit)
   */
  sbp_sbp_gnss_signal_t
  sid
  ;
  /**
* Slant ionospheric correction standard deviation[5 mm]
   */
    u16
  iono_std
  ;
  /**
* Slant tropospheric correction standard deviation[5 mm]
   */
    u16
  tropo_std
  ;
  /**
* Orbit/clock/bias correction projected on range standard deviation[5 mm]
   */
    u16
  range_std
  ;
} sbp_packed_osr_content_t;


  /** GPS satellite observations
   *
 * The GPS observations message reports all the raw pseudorange and
 * carrier phase observations for the satellites being tracked by
 * the device. Carrier phase observation here is represented as a
 * 40-bit fixed point number with Q32.8 layout (i.e. 32-bits of
 * whole cycles and 8-bits of fractional cycles). The observations
 * are be interoperable with 3rd party receivers and conform
 * with typical RTCMv3 GNSS observations.
   */
#define SBP_MSG_OBS                      0x004A

	
	
	
	
	
	#define SBP_OBS_OBS_FLAGS_RAIM_EXCLUSION_MASK (0x1)
#define SBP_OBS_OBS_FLAGS_RAIM_EXCLUSION_SHIFT (7u)
#define SBP_OBS_OBS_FLAGS_RAIM_EXCLUSION_GET(flags) \
                             (((flags) >> SBP_OBS_OBS_FLAGS_RAIM_EXCLUSION_SHIFT) \
                             & SBP_OBS_OBS_FLAGS_RAIM_EXCLUSION_MASK)
#define SBP_OBS_OBS_FLAGS_RAIM_EXCLUSION_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_OBS_OBS_FLAGS_RAIM_EXCLUSION_MASK)) \
                             << (SBP_OBS_OBS_FLAGS_RAIM_EXCLUSION_SHIFT)));} while(0)
                             

#define SBP_OBS_OBS_FLAGS_RAIM_EXCLUSION_NO_EXCLUSION (0)
#define SBP_OBS_OBS_FLAGS_RAIM_EXCLUSION_MEASUREMENT_WAS_EXCLUDED_BY_SPP_RAIM_USE_WITH_CARE (1)
#define SBP_OBS_OBS_FLAGS_DOPPLER_VALID_MASK (0x1)
#define SBP_OBS_OBS_FLAGS_DOPPLER_VALID_SHIFT (3u)
#define SBP_OBS_OBS_FLAGS_DOPPLER_VALID_GET(flags) \
                             (((flags) >> SBP_OBS_OBS_FLAGS_DOPPLER_VALID_SHIFT) \
                             & SBP_OBS_OBS_FLAGS_DOPPLER_VALID_MASK)
#define SBP_OBS_OBS_FLAGS_DOPPLER_VALID_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_OBS_OBS_FLAGS_DOPPLER_VALID_MASK)) \
                             << (SBP_OBS_OBS_FLAGS_DOPPLER_VALID_SHIFT)));} while(0)
                             

#define SBP_OBS_OBS_FLAGS_DOPPLER_VALID_INVALID_DOPPLER_MEASUREMENT (0)
#define SBP_OBS_OBS_FLAGS_DOPPLER_VALID_VALID_DOPPLER_MEASUREMENT (1)
#define SBP_OBS_OBS_FLAGS_HALFCYCLE_AMBIGUITY_MASK (0x1)
#define SBP_OBS_OBS_FLAGS_HALFCYCLE_AMBIGUITY_SHIFT (2u)
#define SBP_OBS_OBS_FLAGS_HALFCYCLE_AMBIGUITY_GET(flags) \
                             (((flags) >> SBP_OBS_OBS_FLAGS_HALFCYCLE_AMBIGUITY_SHIFT) \
                             & SBP_OBS_OBS_FLAGS_HALFCYCLE_AMBIGUITY_MASK)
#define SBP_OBS_OBS_FLAGS_HALFCYCLE_AMBIGUITY_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_OBS_OBS_FLAGS_HALFCYCLE_AMBIGUITY_MASK)) \
                             << (SBP_OBS_OBS_FLAGS_HALFCYCLE_AMBIGUITY_SHIFT)));} while(0)
                             

#define SBP_OBS_OBS_FLAGS_HALFCYCLE_AMBIGUITY_HALF_CYCLE_PHASE_AMBIGUITY_UNRESOLVED (0)
#define SBP_OBS_OBS_FLAGS_HALFCYCLE_AMBIGUITY_HALF_CYCLE_PHASE_AMBIGUITY_RESOLVED (1)
#define SBP_OBS_OBS_FLAGS_CARRIER_PHASE_VALID_MASK (0x1)
#define SBP_OBS_OBS_FLAGS_CARRIER_PHASE_VALID_SHIFT (1u)
#define SBP_OBS_OBS_FLAGS_CARRIER_PHASE_VALID_GET(flags) \
                             (((flags) >> SBP_OBS_OBS_FLAGS_CARRIER_PHASE_VALID_SHIFT) \
                             & SBP_OBS_OBS_FLAGS_CARRIER_PHASE_VALID_MASK)
#define SBP_OBS_OBS_FLAGS_CARRIER_PHASE_VALID_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_OBS_OBS_FLAGS_CARRIER_PHASE_VALID_MASK)) \
                             << (SBP_OBS_OBS_FLAGS_CARRIER_PHASE_VALID_SHIFT)));} while(0)
                             

#define SBP_OBS_OBS_FLAGS_CARRIER_PHASE_VALID_INVALID_CARRIER_PHASE_MEASUREMENT (0)
#define SBP_OBS_OBS_FLAGS_CARRIER_PHASE_VALID_VALID_CARRIER_PHASE_MEASUREMENT (1)
#define SBP_OBS_OBS_FLAGS_PSEUDORANGE_VALID_MASK (0x1)
#define SBP_OBS_OBS_FLAGS_PSEUDORANGE_VALID_SHIFT (0u)
#define SBP_OBS_OBS_FLAGS_PSEUDORANGE_VALID_GET(flags) \
                             (((flags) >> SBP_OBS_OBS_FLAGS_PSEUDORANGE_VALID_SHIFT) \
                             & SBP_OBS_OBS_FLAGS_PSEUDORANGE_VALID_MASK)
#define SBP_OBS_OBS_FLAGS_PSEUDORANGE_VALID_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_OBS_OBS_FLAGS_PSEUDORANGE_VALID_MASK)) \
                             << (SBP_OBS_OBS_FLAGS_PSEUDORANGE_VALID_SHIFT)));} while(0)
                             

#define SBP_OBS_OBS_FLAGS_PSEUDORANGE_VALID_INVALID_PSEUDORANGE_MEASUREMENT (0)
#define SBP_OBS_OBS_FLAGS_PSEUDORANGE_VALID_VALID_PSEUDORANGE_MEASUREMENT_AND_COARSE_TOW_DECODED (1)
	
	#define SBP_OBS_OBS_SID_CODE__MASK (0xff)
#define SBP_OBS_OBS_SID_CODE__SHIFT (0u)
#define SBP_OBS_OBS_SID_CODE__GET(flags) \
                             (((flags) >> SBP_OBS_OBS_SID_CODE__SHIFT) \
                             & SBP_OBS_OBS_SID_CODE__MASK)
#define SBP_OBS_OBS_SID_CODE__SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_OBS_OBS_SID_CODE__MASK)) \
                             << (SBP_OBS_OBS_SID_CODE__SHIFT)));} while(0)
                             

#define SBP_OBS_OBS_SID_CODE__GPS_L1CA (0)
#define SBP_OBS_OBS_SID_CODE__GPS_L2CM (1)
#define SBP_OBS_OBS_SID_CODE__SBAS_L1CA (2)
#define SBP_OBS_OBS_SID_CODE__GLO_L1CA (3)
#define SBP_OBS_OBS_SID_CODE__GLO_L2CA (4)
#define SBP_OBS_OBS_SID_CODE__GPS_L1P (5)
#define SBP_OBS_OBS_SID_CODE__GPS_L2P (6)
#define SBP_OBS_OBS_SID_CODE__BDS2_B1 (12)
#define SBP_OBS_OBS_SID_CODE__BDS2_B2 (13)
#define SBP_OBS_OBS_SID_CODE__GAL_E1B (14)
#define SBP_OBS_OBS_SID_CODE__GAL_E7I (20)
#define SBP_OBS_OBS_SID_CODE__BDS3_B2A (47)
typedef struct {
  
  /**
* Header of a GPS observation message
   */
  sbp_observation_header_t
  header
  ;
  /**
 * Pseudorange and carrier phase observation for a
 * satellite being tracked.
   */
  sbp_packed_obs_content_t
  obs
    [14]
  ;
  /**
   * Number of items in obs
   */
  u8 n_obs;
} sbp_msg_obs_t;


  /** Base station position
   *
 * The base station position message is the position reported by
 * the base station itself. It is used for pseudo-absolute RTK
 * positioning, and is required to be a high-accuracy surveyed
 * location of the base station. Any error here will result in an
 * error in the pseudo-absolute position output.
   */
#define SBP_MSG_BASE_POS_LLH             0x0044

typedef struct {
  
  /**
* Latitude[deg]
   */
    double
  lat
  ;
  /**
* Longitude[deg]
   */
    double
  lon
  ;
  /**
* Height[m]
   */
    double
  height
  ;
} sbp_msg_base_pos_llh_t;


  /** Base station position in ECEF
   *
 * The base station position message is the position reported by
 * the base station itself in absolute Earth Centered Earth Fixed
 * coordinates. It is used for pseudo-absolute RTK positioning, and
 * is required to be a high-accuracy surveyed location of the base
 * station. Any error here will result in an error in the
 * pseudo-absolute position output.
   */
#define SBP_MSG_BASE_POS_ECEF            0x0048

typedef struct {
  
  /**
* ECEF X coodinate[m]
   */
    double
  x
  ;
  /**
* ECEF Y coordinate[m]
   */
    double
  y
  ;
  /**
* ECEF Z coordinate[m]
   */
    double
  z
  ;
} sbp_msg_base_pos_ecef_t;



	
	#define SBP_EPHEMERISCOMMONCONTENT_SID_CODE__MASK (0xff)
#define SBP_EPHEMERISCOMMONCONTENT_SID_CODE__SHIFT (0u)
#define SBP_EPHEMERISCOMMONCONTENT_SID_CODE__GET(flags) \
                             (((flags) >> SBP_EPHEMERISCOMMONCONTENT_SID_CODE__SHIFT) \
                             & SBP_EPHEMERISCOMMONCONTENT_SID_CODE__MASK)
#define SBP_EPHEMERISCOMMONCONTENT_SID_CODE__SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_EPHEMERISCOMMONCONTENT_SID_CODE__MASK)) \
                             << (SBP_EPHEMERISCOMMONCONTENT_SID_CODE__SHIFT)));} while(0)
                             

#define SBP_EPHEMERISCOMMONCONTENT_SID_CODE__GPS_L1CA (0)
#define SBP_EPHEMERISCOMMONCONTENT_SID_CODE__GPS_L2CM (1)
#define SBP_EPHEMERISCOMMONCONTENT_SID_CODE__SBAS_L1CA (2)
#define SBP_EPHEMERISCOMMONCONTENT_SID_CODE__GLO_L1CA (3)
#define SBP_EPHEMERISCOMMONCONTENT_SID_CODE__GLO_L2CA (4)
#define SBP_EPHEMERISCOMMONCONTENT_SID_CODE__GPS_L1P (5)
#define SBP_EPHEMERISCOMMONCONTENT_SID_CODE__GPS_L2P (6)
#define SBP_EPHEMERISCOMMONCONTENT_SID_CODE__BDS2_B1 (12)
#define SBP_EPHEMERISCOMMONCONTENT_SID_CODE__BDS2_B2 (13)
#define SBP_EPHEMERISCOMMONCONTENT_SID_CODE__GAL_E1B (14)
#define SBP_EPHEMERISCOMMONCONTENT_SID_CODE__GAL_E7I (20)
#define SBP_EPHEMERISCOMMONCONTENT_SID_CODE__BDS3_B2A (47)
	
typedef struct {
  
  /**
* GNSS signal identifier (16 bit)
   */
  sbp_sbp_gnss_signal_t
  sid
  ;
  /**
* Time of Ephemerides
   */
  sbp_gps_time_sec_t
  toe
  ;
  /**
* User Range Accuracy[m]
   */
    float
  ura
  ;
  /**
* Curve fit interval[s]
   */
    u32
  fit_interval
  ;
  /**
* Status of ephemeris, 1 = valid, 0 = invalid
   */
    u8
  valid
  ;
  /**
 * Satellite health status.
 * GPS: ICD-GPS-200, chapter 20.3.3.3.1.4
 * SBAS: 0 = valid, non-zero = invalid
 * GLO: 0 = valid, non-zero = invalid
   */
    u8
  health_bits
  ;
} sbp_ephemeris_common_content_t;



	
	#define SBP_EPHEMERISCOMMONCONTENTDEPB_SID_CODE__MASK (0xff)
#define SBP_EPHEMERISCOMMONCONTENTDEPB_SID_CODE__SHIFT (0u)
#define SBP_EPHEMERISCOMMONCONTENTDEPB_SID_CODE__GET(flags) \
                             (((flags) >> SBP_EPHEMERISCOMMONCONTENTDEPB_SID_CODE__SHIFT) \
                             & SBP_EPHEMERISCOMMONCONTENTDEPB_SID_CODE__MASK)
#define SBP_EPHEMERISCOMMONCONTENTDEPB_SID_CODE__SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_EPHEMERISCOMMONCONTENTDEPB_SID_CODE__MASK)) \
                             << (SBP_EPHEMERISCOMMONCONTENTDEPB_SID_CODE__SHIFT)));} while(0)
                             

#define SBP_EPHEMERISCOMMONCONTENTDEPB_SID_CODE__GPS_L1CA (0)
#define SBP_EPHEMERISCOMMONCONTENTDEPB_SID_CODE__GPS_L2CM (1)
#define SBP_EPHEMERISCOMMONCONTENTDEPB_SID_CODE__SBAS_L1CA (2)
#define SBP_EPHEMERISCOMMONCONTENTDEPB_SID_CODE__GLO_L1CA (3)
#define SBP_EPHEMERISCOMMONCONTENTDEPB_SID_CODE__GLO_L2CA (4)
#define SBP_EPHEMERISCOMMONCONTENTDEPB_SID_CODE__GPS_L1P (5)
#define SBP_EPHEMERISCOMMONCONTENTDEPB_SID_CODE__GPS_L2P (6)
#define SBP_EPHEMERISCOMMONCONTENTDEPB_SID_CODE__BDS2_B1 (12)
#define SBP_EPHEMERISCOMMONCONTENTDEPB_SID_CODE__BDS2_B2 (13)
#define SBP_EPHEMERISCOMMONCONTENTDEPB_SID_CODE__GAL_E1B (14)
#define SBP_EPHEMERISCOMMONCONTENTDEPB_SID_CODE__GAL_E7I (20)
#define SBP_EPHEMERISCOMMONCONTENTDEPB_SID_CODE__BDS3_B2A (47)
	
typedef struct {
  
  /**
* GNSS signal identifier (16 bit)
   */
  sbp_sbp_gnss_signal_t
  sid
  ;
  /**
* Time of Ephemerides
   */
  sbp_gps_time_sec_t
  toe
  ;
  /**
* User Range Accuracy[m]
   */
    double
  ura
  ;
  /**
* Curve fit interval[s]
   */
    u32
  fit_interval
  ;
  /**
* Status of ephemeris, 1 = valid, 0 = invalid
   */
    u8
  valid
  ;
  /**
 * Satellite health status.
 * GPS: ICD-GPS-200, chapter 20.3.3.3.1.4
 * Others: 0 = valid, non-zero = invalid
   */
    u8
  health_bits
  ;
} sbp_ephemeris_common_content_dep_b_t;



	
	#define SBP_EPHEMERISCOMMONCONTENTDEPA_SID_CODE__MASK (0xff)
#define SBP_EPHEMERISCOMMONCONTENTDEPA_SID_CODE__SHIFT (0u)
#define SBP_EPHEMERISCOMMONCONTENTDEPA_SID_CODE__GET(flags) \
                             (((flags) >> SBP_EPHEMERISCOMMONCONTENTDEPA_SID_CODE__SHIFT) \
                             & SBP_EPHEMERISCOMMONCONTENTDEPA_SID_CODE__MASK)
#define SBP_EPHEMERISCOMMONCONTENTDEPA_SID_CODE__SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_EPHEMERISCOMMONCONTENTDEPA_SID_CODE__MASK)) \
                             << (SBP_EPHEMERISCOMMONCONTENTDEPA_SID_CODE__SHIFT)));} while(0)
                             

#define SBP_EPHEMERISCOMMONCONTENTDEPA_SID_CODE__GPS_L1CA (0)
#define SBP_EPHEMERISCOMMONCONTENTDEPA_SID_CODE__GPS_L2CM (1)
#define SBP_EPHEMERISCOMMONCONTENTDEPA_SID_CODE__SBAS_L1CA (2)
#define SBP_EPHEMERISCOMMONCONTENTDEPA_SID_CODE__GLO_L1CA (3)
#define SBP_EPHEMERISCOMMONCONTENTDEPA_SID_CODE__GLO_L2CA (4)
#define SBP_EPHEMERISCOMMONCONTENTDEPA_SID_CODE__GPS_L1P (5)
#define SBP_EPHEMERISCOMMONCONTENTDEPA_SID_CODE__GPS_L2P (6)
	
typedef struct {
  
  /**
* GNSS signal identifier
   */
  sbp_gnss_signal_dep_t
  sid
  ;
  /**
* Time of Ephemerides
   */
  sbp_gps_time_dep_t
  toe
  ;
  /**
* User Range Accuracy[m]
   */
    double
  ura
  ;
  /**
* Curve fit interval[s]
   */
    u32
  fit_interval
  ;
  /**
* Status of ephemeris, 1 = valid, 0 = invalid
   */
    u8
  valid
  ;
  /**
 * Satellite health status.
 * GPS: ICD-GPS-200, chapter 20.3.3.3.1.4
 * SBAS: 0 = valid, non-zero = invalid
 * GLO: 0 = valid, non-zero = invalid
   */
    u8
  health_bits
  ;
} sbp_ephemeris_common_content_dep_a_t;


  /** Satellite broadcast ephemeris for GPS
   *
 * The ephemeris message returns a set of satellite orbit
 * parameters that is used to calculate GPS satellite position,
 * velocity, and clock offset. Please see the Navstar GPS
 * Space Segment/Navigation user interfaces (ICD-GPS-200, Table
 * 20-III) for more details.
   */
#define SBP_MSG_EPHEMERIS_GPS_DEP_E      0x0081

	
	
	#define SBP_EPHEMERIS_GPS_DEP_E_COMMON_SID_CODE__MASK (0xff)
#define SBP_EPHEMERIS_GPS_DEP_E_COMMON_SID_CODE__SHIFT (0u)
#define SBP_EPHEMERIS_GPS_DEP_E_COMMON_SID_CODE__GET(flags) \
                             (((flags) >> SBP_EPHEMERIS_GPS_DEP_E_COMMON_SID_CODE__SHIFT) \
                             & SBP_EPHEMERIS_GPS_DEP_E_COMMON_SID_CODE__MASK)
#define SBP_EPHEMERIS_GPS_DEP_E_COMMON_SID_CODE__SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_EPHEMERIS_GPS_DEP_E_COMMON_SID_CODE__MASK)) \
                             << (SBP_EPHEMERIS_GPS_DEP_E_COMMON_SID_CODE__SHIFT)));} while(0)
                             

#define SBP_EPHEMERIS_GPS_DEP_E_COMMON_SID_CODE__GPS_L1CA (0)
#define SBP_EPHEMERIS_GPS_DEP_E_COMMON_SID_CODE__GPS_L2CM (1)
#define SBP_EPHEMERIS_GPS_DEP_E_COMMON_SID_CODE__SBAS_L1CA (2)
#define SBP_EPHEMERIS_GPS_DEP_E_COMMON_SID_CODE__GLO_L1CA (3)
#define SBP_EPHEMERIS_GPS_DEP_E_COMMON_SID_CODE__GLO_L2CA (4)
#define SBP_EPHEMERIS_GPS_DEP_E_COMMON_SID_CODE__GPS_L1P (5)
#define SBP_EPHEMERIS_GPS_DEP_E_COMMON_SID_CODE__GPS_L2P (6)
	
	
typedef struct {
  
  /**
* Values common for all ephemeris types
   */
  sbp_ephemeris_common_content_dep_a_t
  common
  ;
  /**
* Group delay differential between L1 and L2[s]
   */
    double
  tgd
  ;
  /**
* Amplitude of the sine harmonic correction term to the orbit radius[m]
   */
    double
  c_rs
  ;
  /**
* Amplitude of the cosine harmonic correction term to the orbit radius[m]
   */
    double
  c_rc
  ;
  /**
* Amplitude of the cosine harmonic correction term to the argument of latitude[rad]
   */
    double
  c_uc
  ;
  /**
* Amplitude of the sine harmonic correction term to the argument of latitude[rad]
   */
    double
  c_us
  ;
  /**
* Amplitude of the cosine harmonic correction term to the angle of inclination[rad]
   */
    double
  c_ic
  ;
  /**
* Amplitude of the sine harmonic correction term to the angle of inclination[rad]
   */
    double
  c_is
  ;
  /**
* Mean motion difference[rad/s]
   */
    double
  dn
  ;
  /**
* Mean anomaly at reference time[rad]
   */
    double
  m0
  ;
  /**
* Eccentricity of satellite orbit
   */
    double
  ecc
  ;
  /**
* Square root of the semi-major axis of orbit[m^(1/2)]
   */
    double
  sqrta
  ;
  /**
* Longitude of ascending node of orbit plane at weekly epoch[rad]
   */
    double
  omega0
  ;
  /**
* Rate of right ascension[rad/s]
   */
    double
  omegadot
  ;
  /**
* Argument of perigee[rad]
   */
    double
  w
  ;
  /**
* Inclination[rad]
   */
    double
  inc
  ;
  /**
* Inclination first derivative[rad/s]
   */
    double
  inc_dot
  ;
  /**
* Polynomial clock correction coefficient (clock bias)[s]
   */
    double
  af0
  ;
  /**
* Polynomial clock correction coefficient (clock drift)[s/s]
   */
    double
  af1
  ;
  /**
* Polynomial clock correction coefficient (rate of clock drift)[s/s^2]
   */
    double
  af2
  ;
  /**
* Clock reference
   */
  sbp_gps_time_dep_t
  toc
  ;
  /**
* Issue of ephemeris data
   */
    u8
  iode
  ;
  /**
* Issue of clock data
   */
    u16
  iodc
  ;
} sbp_msg_ephemeris_gps_dep_e_t;


  /** Deprecated
   *
 * This observation message has been deprecated in favor of
 * ephemeris message using floats for size reduction.
   */
#define SBP_MSG_EPHEMERIS_GPS_DEP_F      0x0086

	
	
	#define SBP_EPHEMERIS_GPS_DEP_F_COMMON_SID_CODE__MASK (0xff)
#define SBP_EPHEMERIS_GPS_DEP_F_COMMON_SID_CODE__SHIFT (0u)
#define SBP_EPHEMERIS_GPS_DEP_F_COMMON_SID_CODE__GET(flags) \
                             (((flags) >> SBP_EPHEMERIS_GPS_DEP_F_COMMON_SID_CODE__SHIFT) \
                             & SBP_EPHEMERIS_GPS_DEP_F_COMMON_SID_CODE__MASK)
#define SBP_EPHEMERIS_GPS_DEP_F_COMMON_SID_CODE__SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_EPHEMERIS_GPS_DEP_F_COMMON_SID_CODE__MASK)) \
                             << (SBP_EPHEMERIS_GPS_DEP_F_COMMON_SID_CODE__SHIFT)));} while(0)
                             

#define SBP_EPHEMERIS_GPS_DEP_F_COMMON_SID_CODE__GPS_L1CA (0)
#define SBP_EPHEMERIS_GPS_DEP_F_COMMON_SID_CODE__GPS_L2CM (1)
#define SBP_EPHEMERIS_GPS_DEP_F_COMMON_SID_CODE__SBAS_L1CA (2)
#define SBP_EPHEMERIS_GPS_DEP_F_COMMON_SID_CODE__GLO_L1CA (3)
#define SBP_EPHEMERIS_GPS_DEP_F_COMMON_SID_CODE__GLO_L2CA (4)
#define SBP_EPHEMERIS_GPS_DEP_F_COMMON_SID_CODE__GPS_L1P (5)
#define SBP_EPHEMERIS_GPS_DEP_F_COMMON_SID_CODE__GPS_L2P (6)
#define SBP_EPHEMERIS_GPS_DEP_F_COMMON_SID_CODE__BDS2_B1 (12)
#define SBP_EPHEMERIS_GPS_DEP_F_COMMON_SID_CODE__BDS2_B2 (13)
#define SBP_EPHEMERIS_GPS_DEP_F_COMMON_SID_CODE__GAL_E1B (14)
#define SBP_EPHEMERIS_GPS_DEP_F_COMMON_SID_CODE__GAL_E7I (20)
#define SBP_EPHEMERIS_GPS_DEP_F_COMMON_SID_CODE__BDS3_B2A (47)
	
	
typedef struct {
  
  /**
* Values common for all ephemeris types
   */
  sbp_ephemeris_common_content_dep_b_t
  common
  ;
  /**
* Group delay differential between L1 and L2[s]
   */
    double
  tgd
  ;
  /**
* Amplitude of the sine harmonic correction term to the orbit radius[m]
   */
    double
  c_rs
  ;
  /**
* Amplitude of the cosine harmonic correction term to the orbit radius[m]
   */
    double
  c_rc
  ;
  /**
* Amplitude of the cosine harmonic correction term to the argument of latitude[rad]
   */
    double
  c_uc
  ;
  /**
* Amplitude of the sine harmonic correction term to the argument of latitude[rad]
   */
    double
  c_us
  ;
  /**
* Amplitude of the cosine harmonic correction term to the angle of inclination[rad]
   */
    double
  c_ic
  ;
  /**
* Amplitude of the sine harmonic correction term to the angle of inclination[rad]
   */
    double
  c_is
  ;
  /**
* Mean motion difference[rad/s]
   */
    double
  dn
  ;
  /**
* Mean anomaly at reference time[rad]
   */
    double
  m0
  ;
  /**
* Eccentricity of satellite orbit
   */
    double
  ecc
  ;
  /**
* Square root of the semi-major axis of orbit[m^(1/2)]
   */
    double
  sqrta
  ;
  /**
* Longitude of ascending node of orbit plane at weekly epoch[rad]
   */
    double
  omega0
  ;
  /**
* Rate of right ascension[rad/s]
   */
    double
  omegadot
  ;
  /**
* Argument of perigee[rad]
   */
    double
  w
  ;
  /**
* Inclination[rad]
   */
    double
  inc
  ;
  /**
* Inclination first derivative[rad/s]
   */
    double
  inc_dot
  ;
  /**
* Polynomial clock correction coefficient (clock bias)[s]
   */
    double
  af0
  ;
  /**
* Polynomial clock correction coefficient (clock drift)[s/s]
   */
    double
  af1
  ;
  /**
* Polynomial clock correction coefficient (rate of clock drift)[s/s^2]
   */
    double
  af2
  ;
  /**
* Clock reference
   */
  sbp_gps_time_sec_t
  toc
  ;
  /**
* Issue of ephemeris data
   */
    u8
  iode
  ;
  /**
* Issue of clock data
   */
    u16
  iodc
  ;
} sbp_msg_ephemeris_gps_dep_f_t;


  /** Satellite broadcast ephemeris for GPS
   *
 * The ephemeris message returns a set of satellite orbit
 * parameters that is used to calculate GPS satellite position,
 * velocity, and clock offset. Please see the Navstar GPS
 * Space Segment/Navigation user interfaces (ICD-GPS-200, Table
 * 20-III) for more details.
   */
#define SBP_MSG_EPHEMERIS_GPS            0x008A

	
	
	#define SBP_EPHEMERIS_GPS_COMMON_SID_CODE__MASK (0xff)
#define SBP_EPHEMERIS_GPS_COMMON_SID_CODE__SHIFT (0u)
#define SBP_EPHEMERIS_GPS_COMMON_SID_CODE__GET(flags) \
                             (((flags) >> SBP_EPHEMERIS_GPS_COMMON_SID_CODE__SHIFT) \
                             & SBP_EPHEMERIS_GPS_COMMON_SID_CODE__MASK)
#define SBP_EPHEMERIS_GPS_COMMON_SID_CODE__SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_EPHEMERIS_GPS_COMMON_SID_CODE__MASK)) \
                             << (SBP_EPHEMERIS_GPS_COMMON_SID_CODE__SHIFT)));} while(0)
                             

#define SBP_EPHEMERIS_GPS_COMMON_SID_CODE__GPS_L1CA (0)
#define SBP_EPHEMERIS_GPS_COMMON_SID_CODE__GPS_L2CM (1)
#define SBP_EPHEMERIS_GPS_COMMON_SID_CODE__SBAS_L1CA (2)
#define SBP_EPHEMERIS_GPS_COMMON_SID_CODE__GLO_L1CA (3)
#define SBP_EPHEMERIS_GPS_COMMON_SID_CODE__GLO_L2CA (4)
#define SBP_EPHEMERIS_GPS_COMMON_SID_CODE__GPS_L1P (5)
#define SBP_EPHEMERIS_GPS_COMMON_SID_CODE__GPS_L2P (6)
#define SBP_EPHEMERIS_GPS_COMMON_SID_CODE__BDS2_B1 (12)
#define SBP_EPHEMERIS_GPS_COMMON_SID_CODE__BDS2_B2 (13)
#define SBP_EPHEMERIS_GPS_COMMON_SID_CODE__GAL_E1B (14)
#define SBP_EPHEMERIS_GPS_COMMON_SID_CODE__GAL_E7I (20)
#define SBP_EPHEMERIS_GPS_COMMON_SID_CODE__BDS3_B2A (47)
	
	
typedef struct {
  
  /**
* Values common for all ephemeris types
   */
  sbp_ephemeris_common_content_t
  common
  ;
  /**
* Group delay differential between L1 and L2[s]
   */
    float
  tgd
  ;
  /**
* Amplitude of the sine harmonic correction term to the orbit radius[m]
   */
    float
  c_rs
  ;
  /**
* Amplitude of the cosine harmonic correction term to the orbit radius[m]
   */
    float
  c_rc
  ;
  /**
* Amplitude of the cosine harmonic correction term to the argument of latitude[rad]
   */
    float
  c_uc
  ;
  /**
* Amplitude of the sine harmonic correction term to the argument of latitude[rad]
   */
    float
  c_us
  ;
  /**
* Amplitude of the cosine harmonic correction term to the angle of inclination[rad]
   */
    float
  c_ic
  ;
  /**
* Amplitude of the sine harmonic correction term to the angle of inclination[rad]
   */
    float
  c_is
  ;
  /**
* Mean motion difference[rad/s]
   */
    double
  dn
  ;
  /**
* Mean anomaly at reference time[rad]
   */
    double
  m0
  ;
  /**
* Eccentricity of satellite orbit
   */
    double
  ecc
  ;
  /**
* Square root of the semi-major axis of orbit[m^(1/2)]
   */
    double
  sqrta
  ;
  /**
* Longitude of ascending node of orbit plane at weekly epoch[rad]
   */
    double
  omega0
  ;
  /**
* Rate of right ascension[rad/s]
   */
    double
  omegadot
  ;
  /**
* Argument of perigee[rad]
   */
    double
  w
  ;
  /**
* Inclination[rad]
   */
    double
  inc
  ;
  /**
* Inclination first derivative[rad/s]
   */
    double
  inc_dot
  ;
  /**
* Polynomial clock correction coefficient (clock bias)[s]
   */
    float
  af0
  ;
  /**
* Polynomial clock correction coefficient (clock drift)[s/s]
   */
    float
  af1
  ;
  /**
* Polynomial clock correction coefficient (rate of clock drift)[s/s^2]
   */
    float
  af2
  ;
  /**
* Clock reference
   */
  sbp_gps_time_sec_t
  toc
  ;
  /**
* Issue of ephemeris data
   */
    u8
  iode
  ;
  /**
* Issue of clock data
   */
    u16
  iodc
  ;
} sbp_msg_ephemeris_gps_t;


  /** Satellite broadcast ephemeris for QZSS
   *
 * The ephemeris message returns a set of satellite orbit
 * parameters that is used to calculate QZSS satellite position,
 * velocity, and clock offset.
   */
#define SBP_MSG_EPHEMERIS_QZSS           0x008E

	
	
	#define SBP_EPHEMERIS_QZSS_COMMON_SID_CODE__MASK (0xff)
#define SBP_EPHEMERIS_QZSS_COMMON_SID_CODE__SHIFT (0u)
#define SBP_EPHEMERIS_QZSS_COMMON_SID_CODE__GET(flags) \
                             (((flags) >> SBP_EPHEMERIS_QZSS_COMMON_SID_CODE__SHIFT) \
                             & SBP_EPHEMERIS_QZSS_COMMON_SID_CODE__MASK)
#define SBP_EPHEMERIS_QZSS_COMMON_SID_CODE__SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_EPHEMERIS_QZSS_COMMON_SID_CODE__MASK)) \
                             << (SBP_EPHEMERIS_QZSS_COMMON_SID_CODE__SHIFT)));} while(0)
                             

#define SBP_EPHEMERIS_QZSS_COMMON_SID_CODE__GPS_L1CA (0)
#define SBP_EPHEMERIS_QZSS_COMMON_SID_CODE__GPS_L2CM (1)
#define SBP_EPHEMERIS_QZSS_COMMON_SID_CODE__SBAS_L1CA (2)
#define SBP_EPHEMERIS_QZSS_COMMON_SID_CODE__GLO_L1CA (3)
#define SBP_EPHEMERIS_QZSS_COMMON_SID_CODE__GLO_L2CA (4)
#define SBP_EPHEMERIS_QZSS_COMMON_SID_CODE__GPS_L1P (5)
#define SBP_EPHEMERIS_QZSS_COMMON_SID_CODE__GPS_L2P (6)
#define SBP_EPHEMERIS_QZSS_COMMON_SID_CODE__BDS2_B1 (12)
#define SBP_EPHEMERIS_QZSS_COMMON_SID_CODE__BDS2_B2 (13)
#define SBP_EPHEMERIS_QZSS_COMMON_SID_CODE__GAL_E1B (14)
#define SBP_EPHEMERIS_QZSS_COMMON_SID_CODE__GAL_E7I (20)
#define SBP_EPHEMERIS_QZSS_COMMON_SID_CODE__BDS3_B2A (47)
	
	
typedef struct {
  
  /**
* Values common for all ephemeris types
   */
  sbp_ephemeris_common_content_t
  common
  ;
  /**
* Group delay differential between L1 and L2[s]
   */
    float
  tgd
  ;
  /**
* Amplitude of the sine harmonic correction term to the orbit radius[m]
   */
    float
  c_rs
  ;
  /**
* Amplitude of the cosine harmonic correction term to the orbit radius[m]
   */
    float
  c_rc
  ;
  /**
* Amplitude of the cosine harmonic correction term to the argument of latitude[rad]
   */
    float
  c_uc
  ;
  /**
* Amplitude of the sine harmonic correction term to the argument of latitude[rad]
   */
    float
  c_us
  ;
  /**
* Amplitude of the cosine harmonic correction term to the angle of inclination[rad]
   */
    float
  c_ic
  ;
  /**
* Amplitude of the sine harmonic correction term to the angle of inclination[rad]
   */
    float
  c_is
  ;
  /**
* Mean motion difference[rad/s]
   */
    double
  dn
  ;
  /**
* Mean anomaly at reference time[rad]
   */
    double
  m0
  ;
  /**
* Eccentricity of satellite orbit
   */
    double
  ecc
  ;
  /**
* Square root of the semi-major axis of orbit[m^(1/2)]
   */
    double
  sqrta
  ;
  /**
* Longitude of ascending node of orbit plane at weekly epoch[rad]
   */
    double
  omega0
  ;
  /**
* Rate of right ascension[rad/s]
   */
    double
  omegadot
  ;
  /**
* Argument of perigee[rad]
   */
    double
  w
  ;
  /**
* Inclination[rad]
   */
    double
  inc
  ;
  /**
* Inclination first derivative[rad/s]
   */
    double
  inc_dot
  ;
  /**
* Polynomial clock correction coefficient (clock bias)[s]
   */
    float
  af0
  ;
  /**
* Polynomial clock correction coefficient (clock drift)[s/s]
   */
    float
  af1
  ;
  /**
* Polynomial clock correction coefficient (rate of clock drift)[s/s^2]
   */
    float
  af2
  ;
  /**
* Clock reference
   */
  sbp_gps_time_sec_t
  toc
  ;
  /**
* Issue of ephemeris data
   */
    u8
  iode
  ;
  /**
* Issue of clock data
   */
    u16
  iodc
  ;
} sbp_msg_ephemeris_qzss_t;


  /** Satellite broadcast ephemeris for BDS
   *
 * The ephemeris message returns a set of satellite orbit
 * parameters that is used to calculate BDS satellite position,
 * velocity, and clock offset. Please see the BeiDou Navigation
 * Satellite System SIS-ICD Version 2.1, Table 5-9 for more details.
   */
#define SBP_MSG_EPHEMERIS_BDS            0x0089

	
	
	#define SBP_EPHEMERIS_BDS_COMMON_SID_CODE__MASK (0xff)
#define SBP_EPHEMERIS_BDS_COMMON_SID_CODE__SHIFT (0u)
#define SBP_EPHEMERIS_BDS_COMMON_SID_CODE__GET(flags) \
                             (((flags) >> SBP_EPHEMERIS_BDS_COMMON_SID_CODE__SHIFT) \
                             & SBP_EPHEMERIS_BDS_COMMON_SID_CODE__MASK)
#define SBP_EPHEMERIS_BDS_COMMON_SID_CODE__SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_EPHEMERIS_BDS_COMMON_SID_CODE__MASK)) \
                             << (SBP_EPHEMERIS_BDS_COMMON_SID_CODE__SHIFT)));} while(0)
                             

#define SBP_EPHEMERIS_BDS_COMMON_SID_CODE__GPS_L1CA (0)
#define SBP_EPHEMERIS_BDS_COMMON_SID_CODE__GPS_L2CM (1)
#define SBP_EPHEMERIS_BDS_COMMON_SID_CODE__SBAS_L1CA (2)
#define SBP_EPHEMERIS_BDS_COMMON_SID_CODE__GLO_L1CA (3)
#define SBP_EPHEMERIS_BDS_COMMON_SID_CODE__GLO_L2CA (4)
#define SBP_EPHEMERIS_BDS_COMMON_SID_CODE__GPS_L1P (5)
#define SBP_EPHEMERIS_BDS_COMMON_SID_CODE__GPS_L2P (6)
#define SBP_EPHEMERIS_BDS_COMMON_SID_CODE__BDS2_B1 (12)
#define SBP_EPHEMERIS_BDS_COMMON_SID_CODE__BDS2_B2 (13)
#define SBP_EPHEMERIS_BDS_COMMON_SID_CODE__GAL_E1B (14)
#define SBP_EPHEMERIS_BDS_COMMON_SID_CODE__GAL_E7I (20)
#define SBP_EPHEMERIS_BDS_COMMON_SID_CODE__BDS3_B2A (47)
	
	
typedef struct {
  
  /**
* Values common for all ephemeris types
   */
  sbp_ephemeris_common_content_t
  common
  ;
  /**
* Group delay differential for B1[s]
   */
    float
  tgd1
  ;
  /**
* Group delay differential for B2[s]
   */
    float
  tgd2
  ;
  /**
* Amplitude of the sine harmonic correction term to the orbit radius[m]
   */
    float
  c_rs
  ;
  /**
* Amplitude of the cosine harmonic correction term to the orbit radius[m]
   */
    float
  c_rc
  ;
  /**
* Amplitude of the cosine harmonic correction term to the argument of latitude[rad]
   */
    float
  c_uc
  ;
  /**
* Amplitude of the sine harmonic correction term to the argument of latitude[rad]
   */
    float
  c_us
  ;
  /**
* Amplitude of the cosine harmonic correction term to the angle of inclination[rad]
   */
    float
  c_ic
  ;
  /**
* Amplitude of the sine harmonic correction term to the angle of inclination[rad]
   */
    float
  c_is
  ;
  /**
* Mean motion difference[rad/s]
   */
    double
  dn
  ;
  /**
* Mean anomaly at reference time[rad]
   */
    double
  m0
  ;
  /**
* Eccentricity of satellite orbit
   */
    double
  ecc
  ;
  /**
* Square root of the semi-major axis of orbit[m^(1/2)]
   */
    double
  sqrta
  ;
  /**
* Longitude of ascending node of orbit plane at weekly epoch[rad]
   */
    double
  omega0
  ;
  /**
* Rate of right ascension[rad/s]
   */
    double
  omegadot
  ;
  /**
* Argument of perigee[rad]
   */
    double
  w
  ;
  /**
* Inclination[rad]
   */
    double
  inc
  ;
  /**
* Inclination first derivative[rad/s]
   */
    double
  inc_dot
  ;
  /**
* Polynomial clock correction coefficient (clock bias)[s]
   */
    double
  af0
  ;
  /**
* Polynomial clock correction coefficient (clock drift)[s/s]
   */
    float
  af1
  ;
  /**
* Polynomial clock correction coefficient (rate of clock drift)[s/s^2]
   */
    float
  af2
  ;
  /**
* Clock reference
   */
  sbp_gps_time_sec_t
  toc
  ;
  /**
 * Issue of ephemeris data
 * 
 * Calculated from the navigation data parameter t_oe per RTCM/CSNO recommendation:
 * IODE = mod (t_oe / 720, 240)
   */
    u8
  iode
  ;
  /**
 * Issue of clock data
 * 
 * Calculated from the navigation data parameter t_oe per RTCM/CSNO recommendation:
 * IODE = mod (t_oc / 720, 240)
   */
    u16
  iodc
  ;
} sbp_msg_ephemeris_bds_t;


  /** Deprecated
   *
 * This observation message has been deprecated in favor of
 * an ephemeris message with explicit source of NAV data.
   */
#define SBP_MSG_EPHEMERIS_GAL_DEP_A      0x0095

	
	
	#define SBP_EPHEMERIS_GAL_DEP_A_COMMON_SID_CODE__MASK (0xff)
#define SBP_EPHEMERIS_GAL_DEP_A_COMMON_SID_CODE__SHIFT (0u)
#define SBP_EPHEMERIS_GAL_DEP_A_COMMON_SID_CODE__GET(flags) \
                             (((flags) >> SBP_EPHEMERIS_GAL_DEP_A_COMMON_SID_CODE__SHIFT) \
                             & SBP_EPHEMERIS_GAL_DEP_A_COMMON_SID_CODE__MASK)
#define SBP_EPHEMERIS_GAL_DEP_A_COMMON_SID_CODE__SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_EPHEMERIS_GAL_DEP_A_COMMON_SID_CODE__MASK)) \
                             << (SBP_EPHEMERIS_GAL_DEP_A_COMMON_SID_CODE__SHIFT)));} while(0)
                             

#define SBP_EPHEMERIS_GAL_DEP_A_COMMON_SID_CODE__GPS_L1CA (0)
#define SBP_EPHEMERIS_GAL_DEP_A_COMMON_SID_CODE__GPS_L2CM (1)
#define SBP_EPHEMERIS_GAL_DEP_A_COMMON_SID_CODE__SBAS_L1CA (2)
#define SBP_EPHEMERIS_GAL_DEP_A_COMMON_SID_CODE__GLO_L1CA (3)
#define SBP_EPHEMERIS_GAL_DEP_A_COMMON_SID_CODE__GLO_L2CA (4)
#define SBP_EPHEMERIS_GAL_DEP_A_COMMON_SID_CODE__GPS_L1P (5)
#define SBP_EPHEMERIS_GAL_DEP_A_COMMON_SID_CODE__GPS_L2P (6)
#define SBP_EPHEMERIS_GAL_DEP_A_COMMON_SID_CODE__BDS2_B1 (12)
#define SBP_EPHEMERIS_GAL_DEP_A_COMMON_SID_CODE__BDS2_B2 (13)
#define SBP_EPHEMERIS_GAL_DEP_A_COMMON_SID_CODE__GAL_E1B (14)
#define SBP_EPHEMERIS_GAL_DEP_A_COMMON_SID_CODE__GAL_E7I (20)
#define SBP_EPHEMERIS_GAL_DEP_A_COMMON_SID_CODE__BDS3_B2A (47)
	
	
typedef struct {
  
  /**
* Values common for all ephemeris types
   */
  sbp_ephemeris_common_content_t
  common
  ;
  /**
* E1-E5a Broadcast Group Delay[s]
   */
    float
  bgd_e1e5a
  ;
  /**
* E1-E5b Broadcast Group Delay[s]
   */
    float
  bgd_e1e5b
  ;
  /**
* Amplitude of the sine harmonic correction term to the orbit radius[m]
   */
    float
  c_rs
  ;
  /**
* Amplitude of the cosine harmonic correction term to the orbit radius[m]
   */
    float
  c_rc
  ;
  /**
* Amplitude of the cosine harmonic correction term to the argument of latitude[rad]
   */
    float
  c_uc
  ;
  /**
* Amplitude of the sine harmonic correction term to the argument of latitude[rad]
   */
    float
  c_us
  ;
  /**
* Amplitude of the cosine harmonic correction term to the angle of inclination[rad]
   */
    float
  c_ic
  ;
  /**
* Amplitude of the sine harmonic correction term to the angle of inclination[rad]
   */
    float
  c_is
  ;
  /**
* Mean motion difference[rad/s]
   */
    double
  dn
  ;
  /**
* Mean anomaly at reference time[rad]
   */
    double
  m0
  ;
  /**
* Eccentricity of satellite orbit
   */
    double
  ecc
  ;
  /**
* Square root of the semi-major axis of orbit[m^(1/2)]
   */
    double
  sqrta
  ;
  /**
* Longitude of ascending node of orbit plane at weekly epoch[rad]
   */
    double
  omega0
  ;
  /**
* Rate of right ascension[rad/s]
   */
    double
  omegadot
  ;
  /**
* Argument of perigee[rad]
   */
    double
  w
  ;
  /**
* Inclination[rad]
   */
    double
  inc
  ;
  /**
* Inclination first derivative[rad/s]
   */
    double
  inc_dot
  ;
  /**
* Polynomial clock correction coefficient (clock bias)[s]
   */
    double
  af0
  ;
  /**
* Polynomial clock correction coefficient (clock drift)[s/s]
   */
    double
  af1
  ;
  /**
* Polynomial clock correction coefficient (rate of clock drift)[s/s^2]
   */
    float
  af2
  ;
  /**
* Clock reference
   */
  sbp_gps_time_sec_t
  toc
  ;
  /**
* Issue of data (IODnav)
   */
    u16
  iode
  ;
  /**
* Issue of data (IODnav). Always equal to iode
   */
    u16
  iodc
  ;
} sbp_msg_ephemeris_gal_dep_a_t;


  /** Satellite broadcast ephemeris for Galileo
   *
 * The ephemeris message returns a set of satellite orbit
 * parameters that is used to calculate Galileo satellite position,
 * velocity, and clock offset. Please see the Signal In Space ICD
 * OS SIS ICD, Issue 1.3, December 2016 for more details.
   */
#define SBP_MSG_EPHEMERIS_GAL            0x008D

	
	
	#define SBP_EPHEMERIS_GAL_COMMON_SID_CODE__MASK (0xff)
#define SBP_EPHEMERIS_GAL_COMMON_SID_CODE__SHIFT (0u)
#define SBP_EPHEMERIS_GAL_COMMON_SID_CODE__GET(flags) \
                             (((flags) >> SBP_EPHEMERIS_GAL_COMMON_SID_CODE__SHIFT) \
                             & SBP_EPHEMERIS_GAL_COMMON_SID_CODE__MASK)
#define SBP_EPHEMERIS_GAL_COMMON_SID_CODE__SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_EPHEMERIS_GAL_COMMON_SID_CODE__MASK)) \
                             << (SBP_EPHEMERIS_GAL_COMMON_SID_CODE__SHIFT)));} while(0)
                             

#define SBP_EPHEMERIS_GAL_COMMON_SID_CODE__GPS_L1CA (0)
#define SBP_EPHEMERIS_GAL_COMMON_SID_CODE__GPS_L2CM (1)
#define SBP_EPHEMERIS_GAL_COMMON_SID_CODE__SBAS_L1CA (2)
#define SBP_EPHEMERIS_GAL_COMMON_SID_CODE__GLO_L1CA (3)
#define SBP_EPHEMERIS_GAL_COMMON_SID_CODE__GLO_L2CA (4)
#define SBP_EPHEMERIS_GAL_COMMON_SID_CODE__GPS_L1P (5)
#define SBP_EPHEMERIS_GAL_COMMON_SID_CODE__GPS_L2P (6)
#define SBP_EPHEMERIS_GAL_COMMON_SID_CODE__BDS2_B1 (12)
#define SBP_EPHEMERIS_GAL_COMMON_SID_CODE__BDS2_B2 (13)
#define SBP_EPHEMERIS_GAL_COMMON_SID_CODE__GAL_E1B (14)
#define SBP_EPHEMERIS_GAL_COMMON_SID_CODE__GAL_E7I (20)
#define SBP_EPHEMERIS_GAL_COMMON_SID_CODE__BDS3_B2A (47)
	
	
typedef struct {
  
  /**
* Values common for all ephemeris types
   */
  sbp_ephemeris_common_content_t
  common
  ;
  /**
* E1-E5a Broadcast Group Delay[s]
   */
    float
  bgd_e1e5a
  ;
  /**
* E1-E5b Broadcast Group Delay[s]
   */
    float
  bgd_e1e5b
  ;
  /**
* Amplitude of the sine harmonic correction term to the orbit radius[m]
   */
    float
  c_rs
  ;
  /**
* Amplitude of the cosine harmonic correction term to the orbit radius[m]
   */
    float
  c_rc
  ;
  /**
* Amplitude of the cosine harmonic correction term to the argument of latitude[rad]
   */
    float
  c_uc
  ;
  /**
* Amplitude of the sine harmonic correction term to the argument of latitude[rad]
   */
    float
  c_us
  ;
  /**
* Amplitude of the cosine harmonic correction term to the angle of inclination[rad]
   */
    float
  c_ic
  ;
  /**
* Amplitude of the sine harmonic correction term to the angle of inclination[rad]
   */
    float
  c_is
  ;
  /**
* Mean motion difference[rad/s]
   */
    double
  dn
  ;
  /**
* Mean anomaly at reference time[rad]
   */
    double
  m0
  ;
  /**
* Eccentricity of satellite orbit
   */
    double
  ecc
  ;
  /**
* Square root of the semi-major axis of orbit[m^(1/2)]
   */
    double
  sqrta
  ;
  /**
* Longitude of ascending node of orbit plane at weekly epoch[rad]
   */
    double
  omega0
  ;
  /**
* Rate of right ascension[rad/s]
   */
    double
  omegadot
  ;
  /**
* Argument of perigee[rad]
   */
    double
  w
  ;
  /**
* Inclination[rad]
   */
    double
  inc
  ;
  /**
* Inclination first derivative[rad/s]
   */
    double
  inc_dot
  ;
  /**
* Polynomial clock correction coefficient (clock bias)[s]
   */
    double
  af0
  ;
  /**
* Polynomial clock correction coefficient (clock drift)[s/s]
   */
    double
  af1
  ;
  /**
* Polynomial clock correction coefficient (rate of clock drift)[s/s^2]
   */
    float
  af2
  ;
  /**
* Clock reference
   */
  sbp_gps_time_sec_t
  toc
  ;
  /**
* Issue of data (IODnav)
   */
    u16
  iode
  ;
  /**
* Issue of data (IODnav). Always equal to iode
   */
    u16
  iodc
  ;
  /**
* 0=I/NAV, 1=F/NAV
   */
    u8
  source
  ;
} sbp_msg_ephemeris_gal_t;


#define SBP_MSG_EPHEMERIS_SBAS_DEP_A     0x0082

	
	
	#define SBP_EPHEMERIS_SBAS_DEP_A_COMMON_SID_CODE__MASK (0xff)
#define SBP_EPHEMERIS_SBAS_DEP_A_COMMON_SID_CODE__SHIFT (0u)
#define SBP_EPHEMERIS_SBAS_DEP_A_COMMON_SID_CODE__GET(flags) \
                             (((flags) >> SBP_EPHEMERIS_SBAS_DEP_A_COMMON_SID_CODE__SHIFT) \
                             & SBP_EPHEMERIS_SBAS_DEP_A_COMMON_SID_CODE__MASK)
#define SBP_EPHEMERIS_SBAS_DEP_A_COMMON_SID_CODE__SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_EPHEMERIS_SBAS_DEP_A_COMMON_SID_CODE__MASK)) \
                             << (SBP_EPHEMERIS_SBAS_DEP_A_COMMON_SID_CODE__SHIFT)));} while(0)
                             

#define SBP_EPHEMERIS_SBAS_DEP_A_COMMON_SID_CODE__GPS_L1CA (0)
#define SBP_EPHEMERIS_SBAS_DEP_A_COMMON_SID_CODE__GPS_L2CM (1)
#define SBP_EPHEMERIS_SBAS_DEP_A_COMMON_SID_CODE__SBAS_L1CA (2)
#define SBP_EPHEMERIS_SBAS_DEP_A_COMMON_SID_CODE__GLO_L1CA (3)
#define SBP_EPHEMERIS_SBAS_DEP_A_COMMON_SID_CODE__GLO_L2CA (4)
#define SBP_EPHEMERIS_SBAS_DEP_A_COMMON_SID_CODE__GPS_L1P (5)
#define SBP_EPHEMERIS_SBAS_DEP_A_COMMON_SID_CODE__GPS_L2P (6)
	
typedef struct {
  
  /**
* Values common for all ephemeris types
   */
  sbp_ephemeris_common_content_dep_a_t
  common
  ;
  /**
* Position of the GEO at time toe[m]
   */
    double
  pos
    [3]
  ;
  /**
* Velocity of the GEO at time toe[m/s]
   */
    double
  vel
    [3]
  ;
  /**
* Acceleration of the GEO at time toe[m/s^2]
   */
    double
  acc
    [3]
  ;
  /**
* Time offset of the GEO clock w.r.t. SBAS Network Time[s]
   */
    double
  a_gf0
  ;
  /**
* Drift of the GEO clock w.r.t. SBAS Network Time[s/s]
   */
    double
  a_gf1
  ;
} sbp_msg_ephemeris_sbas_dep_a_t;


  /** Satellite broadcast ephemeris for GLO
   *
 * The ephemeris message returns a set of satellite orbit
 * parameters that is used to calculate GLO satellite position,
 * velocity, and clock offset. Please see the GLO ICD 5.1 "Table 4.5
 * Characteristics of words of immediate information (ephemeris parameters)"
 * for more details.
   */
#define SBP_MSG_EPHEMERIS_GLO_DEP_A      0x0083

	
	
	#define SBP_EPHEMERIS_GLO_DEP_A_COMMON_SID_CODE__MASK (0xff)
#define SBP_EPHEMERIS_GLO_DEP_A_COMMON_SID_CODE__SHIFT (0u)
#define SBP_EPHEMERIS_GLO_DEP_A_COMMON_SID_CODE__GET(flags) \
                             (((flags) >> SBP_EPHEMERIS_GLO_DEP_A_COMMON_SID_CODE__SHIFT) \
                             & SBP_EPHEMERIS_GLO_DEP_A_COMMON_SID_CODE__MASK)
#define SBP_EPHEMERIS_GLO_DEP_A_COMMON_SID_CODE__SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_EPHEMERIS_GLO_DEP_A_COMMON_SID_CODE__MASK)) \
                             << (SBP_EPHEMERIS_GLO_DEP_A_COMMON_SID_CODE__SHIFT)));} while(0)
                             

#define SBP_EPHEMERIS_GLO_DEP_A_COMMON_SID_CODE__GPS_L1CA (0)
#define SBP_EPHEMERIS_GLO_DEP_A_COMMON_SID_CODE__GPS_L2CM (1)
#define SBP_EPHEMERIS_GLO_DEP_A_COMMON_SID_CODE__SBAS_L1CA (2)
#define SBP_EPHEMERIS_GLO_DEP_A_COMMON_SID_CODE__GLO_L1CA (3)
#define SBP_EPHEMERIS_GLO_DEP_A_COMMON_SID_CODE__GLO_L2CA (4)
#define SBP_EPHEMERIS_GLO_DEP_A_COMMON_SID_CODE__GPS_L1P (5)
#define SBP_EPHEMERIS_GLO_DEP_A_COMMON_SID_CODE__GPS_L2P (6)
	
typedef struct {
  
  /**
* Values common for all ephemeris types
   */
  sbp_ephemeris_common_content_dep_a_t
  common
  ;
  /**
* Relative deviation of predicted carrier frequency from nominal
   */
    double
  gamma
  ;
  /**
* Correction to the SV time[s]
   */
    double
  tau
  ;
  /**
* Position of the SV at tb in PZ-90.02 coordinates system[m]
   */
    double
  pos
    [3]
  ;
  /**
* Velocity vector of the SV at tb in PZ-90.02 coordinates system[m/s]
   */
    double
  vel
    [3]
  ;
  /**
* Acceleration vector of the SV at tb in PZ-90.02 coordinates sys[m/s^2]
   */
    double
  acc
    [3]
  ;
} sbp_msg_ephemeris_glo_dep_a_t;


  /** Deprecated
   *
 * This observation message has been deprecated in favor of
 * ephemeris message using floats for size reduction.
   */
#define SBP_MSG_EPHEMERIS_SBAS_DEP_B     0x0084

	
	
	#define SBP_EPHEMERIS_SBAS_DEP_B_COMMON_SID_CODE__MASK (0xff)
#define SBP_EPHEMERIS_SBAS_DEP_B_COMMON_SID_CODE__SHIFT (0u)
#define SBP_EPHEMERIS_SBAS_DEP_B_COMMON_SID_CODE__GET(flags) \
                             (((flags) >> SBP_EPHEMERIS_SBAS_DEP_B_COMMON_SID_CODE__SHIFT) \
                             & SBP_EPHEMERIS_SBAS_DEP_B_COMMON_SID_CODE__MASK)
#define SBP_EPHEMERIS_SBAS_DEP_B_COMMON_SID_CODE__SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_EPHEMERIS_SBAS_DEP_B_COMMON_SID_CODE__MASK)) \
                             << (SBP_EPHEMERIS_SBAS_DEP_B_COMMON_SID_CODE__SHIFT)));} while(0)
                             

#define SBP_EPHEMERIS_SBAS_DEP_B_COMMON_SID_CODE__GPS_L1CA (0)
#define SBP_EPHEMERIS_SBAS_DEP_B_COMMON_SID_CODE__GPS_L2CM (1)
#define SBP_EPHEMERIS_SBAS_DEP_B_COMMON_SID_CODE__SBAS_L1CA (2)
#define SBP_EPHEMERIS_SBAS_DEP_B_COMMON_SID_CODE__GLO_L1CA (3)
#define SBP_EPHEMERIS_SBAS_DEP_B_COMMON_SID_CODE__GLO_L2CA (4)
#define SBP_EPHEMERIS_SBAS_DEP_B_COMMON_SID_CODE__GPS_L1P (5)
#define SBP_EPHEMERIS_SBAS_DEP_B_COMMON_SID_CODE__GPS_L2P (6)
#define SBP_EPHEMERIS_SBAS_DEP_B_COMMON_SID_CODE__BDS2_B1 (12)
#define SBP_EPHEMERIS_SBAS_DEP_B_COMMON_SID_CODE__BDS2_B2 (13)
#define SBP_EPHEMERIS_SBAS_DEP_B_COMMON_SID_CODE__GAL_E1B (14)
#define SBP_EPHEMERIS_SBAS_DEP_B_COMMON_SID_CODE__GAL_E7I (20)
#define SBP_EPHEMERIS_SBAS_DEP_B_COMMON_SID_CODE__BDS3_B2A (47)
	
typedef struct {
  
  /**
* Values common for all ephemeris types
   */
  sbp_ephemeris_common_content_dep_b_t
  common
  ;
  /**
* Position of the GEO at time toe[m]
   */
    double
  pos
    [3]
  ;
  /**
* Velocity of the GEO at time toe[m/s]
   */
    double
  vel
    [3]
  ;
  /**
* Acceleration of the GEO at time toe[m/s^2]
   */
    double
  acc
    [3]
  ;
  /**
* Time offset of the GEO clock w.r.t. SBAS Network Time[s]
   */
    double
  a_gf0
  ;
  /**
* Drift of the GEO clock w.r.t. SBAS Network Time[s/s]
   */
    double
  a_gf1
  ;
} sbp_msg_ephemeris_sbas_dep_b_t;


#define SBP_MSG_EPHEMERIS_SBAS           0x008C

	
	
	#define SBP_EPHEMERIS_SBAS_COMMON_SID_CODE__MASK (0xff)
#define SBP_EPHEMERIS_SBAS_COMMON_SID_CODE__SHIFT (0u)
#define SBP_EPHEMERIS_SBAS_COMMON_SID_CODE__GET(flags) \
                             (((flags) >> SBP_EPHEMERIS_SBAS_COMMON_SID_CODE__SHIFT) \
                             & SBP_EPHEMERIS_SBAS_COMMON_SID_CODE__MASK)
#define SBP_EPHEMERIS_SBAS_COMMON_SID_CODE__SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_EPHEMERIS_SBAS_COMMON_SID_CODE__MASK)) \
                             << (SBP_EPHEMERIS_SBAS_COMMON_SID_CODE__SHIFT)));} while(0)
                             

#define SBP_EPHEMERIS_SBAS_COMMON_SID_CODE__GPS_L1CA (0)
#define SBP_EPHEMERIS_SBAS_COMMON_SID_CODE__GPS_L2CM (1)
#define SBP_EPHEMERIS_SBAS_COMMON_SID_CODE__SBAS_L1CA (2)
#define SBP_EPHEMERIS_SBAS_COMMON_SID_CODE__GLO_L1CA (3)
#define SBP_EPHEMERIS_SBAS_COMMON_SID_CODE__GLO_L2CA (4)
#define SBP_EPHEMERIS_SBAS_COMMON_SID_CODE__GPS_L1P (5)
#define SBP_EPHEMERIS_SBAS_COMMON_SID_CODE__GPS_L2P (6)
#define SBP_EPHEMERIS_SBAS_COMMON_SID_CODE__BDS2_B1 (12)
#define SBP_EPHEMERIS_SBAS_COMMON_SID_CODE__BDS2_B2 (13)
#define SBP_EPHEMERIS_SBAS_COMMON_SID_CODE__GAL_E1B (14)
#define SBP_EPHEMERIS_SBAS_COMMON_SID_CODE__GAL_E7I (20)
#define SBP_EPHEMERIS_SBAS_COMMON_SID_CODE__BDS3_B2A (47)
	
typedef struct {
  
  /**
* Values common for all ephemeris types
   */
  sbp_ephemeris_common_content_t
  common
  ;
  /**
* Position of the GEO at time toe[m]
   */
    double
  pos
    [3]
  ;
  /**
* Velocity of the GEO at time toe[m/s]
   */
    float
  vel
    [3]
  ;
  /**
* Acceleration of the GEO at time toe[m/s^2]
   */
    float
  acc
    [3]
  ;
  /**
* Time offset of the GEO clock w.r.t. SBAS Network Time[s]
   */
    float
  a_gf0
  ;
  /**
* Drift of the GEO clock w.r.t. SBAS Network Time[s/s]
   */
    float
  a_gf1
  ;
} sbp_msg_ephemeris_sbas_t;


  /** Satellite broadcast ephemeris for GLO
   *
 * The ephemeris message returns a set of satellite orbit
 * parameters that is used to calculate GLO satellite position,
 * velocity, and clock offset. Please see the GLO ICD 5.1 "Table 4.5
 * Characteristics of words of immediate information (ephemeris parameters)"
 * for more details.
   */
#define SBP_MSG_EPHEMERIS_GLO_DEP_B      0x0085

	
	
	#define SBP_EPHEMERIS_GLO_DEP_B_COMMON_SID_CODE__MASK (0xff)
#define SBP_EPHEMERIS_GLO_DEP_B_COMMON_SID_CODE__SHIFT (0u)
#define SBP_EPHEMERIS_GLO_DEP_B_COMMON_SID_CODE__GET(flags) \
                             (((flags) >> SBP_EPHEMERIS_GLO_DEP_B_COMMON_SID_CODE__SHIFT) \
                             & SBP_EPHEMERIS_GLO_DEP_B_COMMON_SID_CODE__MASK)
#define SBP_EPHEMERIS_GLO_DEP_B_COMMON_SID_CODE__SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_EPHEMERIS_GLO_DEP_B_COMMON_SID_CODE__MASK)) \
                             << (SBP_EPHEMERIS_GLO_DEP_B_COMMON_SID_CODE__SHIFT)));} while(0)
                             

#define SBP_EPHEMERIS_GLO_DEP_B_COMMON_SID_CODE__GPS_L1CA (0)
#define SBP_EPHEMERIS_GLO_DEP_B_COMMON_SID_CODE__GPS_L2CM (1)
#define SBP_EPHEMERIS_GLO_DEP_B_COMMON_SID_CODE__SBAS_L1CA (2)
#define SBP_EPHEMERIS_GLO_DEP_B_COMMON_SID_CODE__GLO_L1CA (3)
#define SBP_EPHEMERIS_GLO_DEP_B_COMMON_SID_CODE__GLO_L2CA (4)
#define SBP_EPHEMERIS_GLO_DEP_B_COMMON_SID_CODE__GPS_L1P (5)
#define SBP_EPHEMERIS_GLO_DEP_B_COMMON_SID_CODE__GPS_L2P (6)
#define SBP_EPHEMERIS_GLO_DEP_B_COMMON_SID_CODE__BDS2_B1 (12)
#define SBP_EPHEMERIS_GLO_DEP_B_COMMON_SID_CODE__BDS2_B2 (13)
#define SBP_EPHEMERIS_GLO_DEP_B_COMMON_SID_CODE__GAL_E1B (14)
#define SBP_EPHEMERIS_GLO_DEP_B_COMMON_SID_CODE__GAL_E7I (20)
#define SBP_EPHEMERIS_GLO_DEP_B_COMMON_SID_CODE__BDS3_B2A (47)
	
typedef struct {
  
  /**
* Values common for all ephemeris types
   */
  sbp_ephemeris_common_content_dep_b_t
  common
  ;
  /**
* Relative deviation of predicted carrier frequency from nominal
   */
    double
  gamma
  ;
  /**
* Correction to the SV time[s]
   */
    double
  tau
  ;
  /**
* Position of the SV at tb in PZ-90.02 coordinates system[m]
   */
    double
  pos
    [3]
  ;
  /**
* Velocity vector of the SV at tb in PZ-90.02 coordinates system[m/s]
   */
    double
  vel
    [3]
  ;
  /**
* Acceleration vector of the SV at tb in PZ-90.02 coordinates sys[m/s^2]
   */
    double
  acc
    [3]
  ;
} sbp_msg_ephemeris_glo_dep_b_t;


  /** Satellite broadcast ephemeris for GLO
   *
 * The ephemeris message returns a set of satellite orbit
 * parameters that is used to calculate GLO satellite position,
 * velocity, and clock offset. Please see the GLO ICD 5.1 "Table 4.5
 * Characteristics of words of immediate information (ephemeris parameters)"
 * for more details.
   */
#define SBP_MSG_EPHEMERIS_GLO_DEP_C      0x0087

	
	
	#define SBP_EPHEMERIS_GLO_DEP_C_COMMON_SID_CODE__MASK (0xff)
#define SBP_EPHEMERIS_GLO_DEP_C_COMMON_SID_CODE__SHIFT (0u)
#define SBP_EPHEMERIS_GLO_DEP_C_COMMON_SID_CODE__GET(flags) \
                             (((flags) >> SBP_EPHEMERIS_GLO_DEP_C_COMMON_SID_CODE__SHIFT) \
                             & SBP_EPHEMERIS_GLO_DEP_C_COMMON_SID_CODE__MASK)
#define SBP_EPHEMERIS_GLO_DEP_C_COMMON_SID_CODE__SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_EPHEMERIS_GLO_DEP_C_COMMON_SID_CODE__MASK)) \
                             << (SBP_EPHEMERIS_GLO_DEP_C_COMMON_SID_CODE__SHIFT)));} while(0)
                             

#define SBP_EPHEMERIS_GLO_DEP_C_COMMON_SID_CODE__GPS_L1CA (0)
#define SBP_EPHEMERIS_GLO_DEP_C_COMMON_SID_CODE__GPS_L2CM (1)
#define SBP_EPHEMERIS_GLO_DEP_C_COMMON_SID_CODE__SBAS_L1CA (2)
#define SBP_EPHEMERIS_GLO_DEP_C_COMMON_SID_CODE__GLO_L1CA (3)
#define SBP_EPHEMERIS_GLO_DEP_C_COMMON_SID_CODE__GLO_L2CA (4)
#define SBP_EPHEMERIS_GLO_DEP_C_COMMON_SID_CODE__GPS_L1P (5)
#define SBP_EPHEMERIS_GLO_DEP_C_COMMON_SID_CODE__GPS_L2P (6)
#define SBP_EPHEMERIS_GLO_DEP_C_COMMON_SID_CODE__BDS2_B1 (12)
#define SBP_EPHEMERIS_GLO_DEP_C_COMMON_SID_CODE__BDS2_B2 (13)
#define SBP_EPHEMERIS_GLO_DEP_C_COMMON_SID_CODE__GAL_E1B (14)
#define SBP_EPHEMERIS_GLO_DEP_C_COMMON_SID_CODE__GAL_E7I (20)
#define SBP_EPHEMERIS_GLO_DEP_C_COMMON_SID_CODE__BDS3_B2A (47)
	
typedef struct {
  
  /**
* Values common for all ephemeris types
   */
  sbp_ephemeris_common_content_dep_b_t
  common
  ;
  /**
* Relative deviation of predicted carrier frequency from nominal
   */
    double
  gamma
  ;
  /**
* Correction to the SV time[s]
   */
    double
  tau
  ;
  /**
* Equipment delay between L1 and L2[s]
   */
    double
  d_tau
  ;
  /**
* Position of the SV at tb in PZ-90.02 coordinates system[m]
   */
    double
  pos
    [3]
  ;
  /**
* Velocity vector of the SV at tb in PZ-90.02 coordinates system[m/s]
   */
    double
  vel
    [3]
  ;
  /**
* Acceleration vector of the SV at tb in PZ-90.02 coordinates sys[m/s^2]
   */
    double
  acc
    [3]
  ;
  /**
* Frequency slot. FCN+8 (that is [1..14]). 0 or 0xFF for invalid
   */
    u8
  fcn
  ;
} sbp_msg_ephemeris_glo_dep_c_t;


  /** Deprecated
   *
 * This observation message has been deprecated in favor of
 * ephemeris message using floats for size reduction.
   */
#define SBP_MSG_EPHEMERIS_GLO_DEP_D      0x0088

	
	
	#define SBP_EPHEMERIS_GLO_DEP_D_COMMON_SID_CODE__MASK (0xff)
#define SBP_EPHEMERIS_GLO_DEP_D_COMMON_SID_CODE__SHIFT (0u)
#define SBP_EPHEMERIS_GLO_DEP_D_COMMON_SID_CODE__GET(flags) \
                             (((flags) >> SBP_EPHEMERIS_GLO_DEP_D_COMMON_SID_CODE__SHIFT) \
                             & SBP_EPHEMERIS_GLO_DEP_D_COMMON_SID_CODE__MASK)
#define SBP_EPHEMERIS_GLO_DEP_D_COMMON_SID_CODE__SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_EPHEMERIS_GLO_DEP_D_COMMON_SID_CODE__MASK)) \
                             << (SBP_EPHEMERIS_GLO_DEP_D_COMMON_SID_CODE__SHIFT)));} while(0)
                             

#define SBP_EPHEMERIS_GLO_DEP_D_COMMON_SID_CODE__GPS_L1CA (0)
#define SBP_EPHEMERIS_GLO_DEP_D_COMMON_SID_CODE__GPS_L2CM (1)
#define SBP_EPHEMERIS_GLO_DEP_D_COMMON_SID_CODE__SBAS_L1CA (2)
#define SBP_EPHEMERIS_GLO_DEP_D_COMMON_SID_CODE__GLO_L1CA (3)
#define SBP_EPHEMERIS_GLO_DEP_D_COMMON_SID_CODE__GLO_L2CA (4)
#define SBP_EPHEMERIS_GLO_DEP_D_COMMON_SID_CODE__GPS_L1P (5)
#define SBP_EPHEMERIS_GLO_DEP_D_COMMON_SID_CODE__GPS_L2P (6)
#define SBP_EPHEMERIS_GLO_DEP_D_COMMON_SID_CODE__BDS2_B1 (12)
#define SBP_EPHEMERIS_GLO_DEP_D_COMMON_SID_CODE__BDS2_B2 (13)
#define SBP_EPHEMERIS_GLO_DEP_D_COMMON_SID_CODE__GAL_E1B (14)
#define SBP_EPHEMERIS_GLO_DEP_D_COMMON_SID_CODE__GAL_E7I (20)
#define SBP_EPHEMERIS_GLO_DEP_D_COMMON_SID_CODE__BDS3_B2A (47)
	
typedef struct {
  
  /**
* Values common for all ephemeris types
   */
  sbp_ephemeris_common_content_dep_b_t
  common
  ;
  /**
* Relative deviation of predicted carrier frequency from nominal
   */
    double
  gamma
  ;
  /**
* Correction to the SV time[s]
   */
    double
  tau
  ;
  /**
* Equipment delay between L1 and L2[s]
   */
    double
  d_tau
  ;
  /**
* Position of the SV at tb in PZ-90.02 coordinates system[m]
   */
    double
  pos
    [3]
  ;
  /**
* Velocity vector of the SV at tb in PZ-90.02 coordinates system[m/s]
   */
    double
  vel
    [3]
  ;
  /**
* Acceleration vector of the SV at tb in PZ-90.02 coordinates sys[m/s^2]
   */
    double
  acc
    [3]
  ;
  /**
* Frequency slot. FCN+8 (that is [1..14]). 0 or 0xFF for invalid
   */
    u8
  fcn
  ;
  /**
* Issue of data. Equal to the 7 bits of the immediate data word t_b
   */
    u8
  iod
  ;
} sbp_msg_ephemeris_glo_dep_d_t;


  /** Satellite broadcast ephemeris for GLO
   *
 * The ephemeris message returns a set of satellite orbit
 * parameters that is used to calculate GLO satellite position,
 * velocity, and clock offset. Please see the GLO ICD 5.1 "Table 4.5
 * Characteristics of words of immediate information (ephemeris parameters)"
 * for more details.
   */
#define SBP_MSG_EPHEMERIS_GLO            0x008B

	
	
	#define SBP_EPHEMERIS_GLO_COMMON_SID_CODE__MASK (0xff)
#define SBP_EPHEMERIS_GLO_COMMON_SID_CODE__SHIFT (0u)
#define SBP_EPHEMERIS_GLO_COMMON_SID_CODE__GET(flags) \
                             (((flags) >> SBP_EPHEMERIS_GLO_COMMON_SID_CODE__SHIFT) \
                             & SBP_EPHEMERIS_GLO_COMMON_SID_CODE__MASK)
#define SBP_EPHEMERIS_GLO_COMMON_SID_CODE__SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_EPHEMERIS_GLO_COMMON_SID_CODE__MASK)) \
                             << (SBP_EPHEMERIS_GLO_COMMON_SID_CODE__SHIFT)));} while(0)
                             

#define SBP_EPHEMERIS_GLO_COMMON_SID_CODE__GPS_L1CA (0)
#define SBP_EPHEMERIS_GLO_COMMON_SID_CODE__GPS_L2CM (1)
#define SBP_EPHEMERIS_GLO_COMMON_SID_CODE__SBAS_L1CA (2)
#define SBP_EPHEMERIS_GLO_COMMON_SID_CODE__GLO_L1CA (3)
#define SBP_EPHEMERIS_GLO_COMMON_SID_CODE__GLO_L2CA (4)
#define SBP_EPHEMERIS_GLO_COMMON_SID_CODE__GPS_L1P (5)
#define SBP_EPHEMERIS_GLO_COMMON_SID_CODE__GPS_L2P (6)
#define SBP_EPHEMERIS_GLO_COMMON_SID_CODE__BDS2_B1 (12)
#define SBP_EPHEMERIS_GLO_COMMON_SID_CODE__BDS2_B2 (13)
#define SBP_EPHEMERIS_GLO_COMMON_SID_CODE__GAL_E1B (14)
#define SBP_EPHEMERIS_GLO_COMMON_SID_CODE__GAL_E7I (20)
#define SBP_EPHEMERIS_GLO_COMMON_SID_CODE__BDS3_B2A (47)
	
typedef struct {
  
  /**
* Values common for all ephemeris types
   */
  sbp_ephemeris_common_content_t
  common
  ;
  /**
* Relative deviation of predicted carrier frequency from nominal
   */
    float
  gamma
  ;
  /**
* Correction to the SV time[s]
   */
    float
  tau
  ;
  /**
* Equipment delay between L1 and L2[s]
   */
    float
  d_tau
  ;
  /**
* Position of the SV at tb in PZ-90.02 coordinates system[m]
   */
    double
  pos
    [3]
  ;
  /**
* Velocity vector of the SV at tb in PZ-90.02 coordinates system[m/s]
   */
    double
  vel
    [3]
  ;
  /**
* Acceleration vector of the SV at tb in PZ-90.02 coordinates sys[m/s^2]
   */
    float
  acc
    [3]
  ;
  /**
* Frequency slot. FCN+8 (that is [1..14]). 0 or 0xFF for invalid
   */
    u8
  fcn
  ;
  /**
* Issue of data. Equal to the 7 bits of the immediate data word t_b
   */
    u8
  iod
  ;
} sbp_msg_ephemeris_glo_t;


  /** Satellite broadcast ephemeris
   *
 * The ephemeris message returns a set of satellite orbit
 * parameters that is used to calculate GPS satellite position,
 * velocity, and clock offset. Please see the Navstar GPS
 * Space Segment/Navigation user interfaces (ICD-GPS-200, Table
 * 20-III) for more details.
   */
#define SBP_MSG_EPHEMERIS_DEP_D          0x0080

	
	#define SBP_EPHEMERIS_DEP_D_SID_CODE__MASK (0xff)
#define SBP_EPHEMERIS_DEP_D_SID_CODE__SHIFT (0u)
#define SBP_EPHEMERIS_DEP_D_SID_CODE__GET(flags) \
                             (((flags) >> SBP_EPHEMERIS_DEP_D_SID_CODE__SHIFT) \
                             & SBP_EPHEMERIS_DEP_D_SID_CODE__MASK)
#define SBP_EPHEMERIS_DEP_D_SID_CODE__SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_EPHEMERIS_DEP_D_SID_CODE__MASK)) \
                             << (SBP_EPHEMERIS_DEP_D_SID_CODE__SHIFT)));} while(0)
                             

#define SBP_EPHEMERIS_DEP_D_SID_CODE__GPS_L1CA (0)
#define SBP_EPHEMERIS_DEP_D_SID_CODE__GPS_L2CM (1)
#define SBP_EPHEMERIS_DEP_D_SID_CODE__SBAS_L1CA (2)
#define SBP_EPHEMERIS_DEP_D_SID_CODE__GLO_L1CA (3)
#define SBP_EPHEMERIS_DEP_D_SID_CODE__GLO_L2CA (4)
#define SBP_EPHEMERIS_DEP_D_SID_CODE__GPS_L1P (5)
#define SBP_EPHEMERIS_DEP_D_SID_CODE__GPS_L2P (6)
typedef struct {
  
  /**
* Group delay differential between L1 and L2[s]
   */
    double
  tgd
  ;
  /**
* Amplitude of the sine harmonic correction term to the orbit radius[m]
   */
    double
  c_rs
  ;
  /**
* Amplitude of the cosine harmonic correction term to the orbit radius[m]
   */
    double
  c_rc
  ;
  /**
* Amplitude of the cosine harmonic correction term to the argument of latitude[rad]
   */
    double
  c_uc
  ;
  /**
* Amplitude of the sine harmonic correction term to the argument of latitude[rad]
   */
    double
  c_us
  ;
  /**
* Amplitude of the cosine harmonic correction term to the angle of inclination[rad]
   */
    double
  c_ic
  ;
  /**
* Amplitude of the sine harmonic correction term to the angle of inclination[rad]
   */
    double
  c_is
  ;
  /**
* Mean motion difference[rad/s]
   */
    double
  dn
  ;
  /**
* Mean anomaly at reference time[rad]
   */
    double
  m0
  ;
  /**
* Eccentricity of satellite orbit
   */
    double
  ecc
  ;
  /**
* Square root of the semi-major axis of orbit[m^(1/2)]
   */
    double
  sqrta
  ;
  /**
* Longitude of ascending node of orbit plane at weekly epoch[rad]
   */
    double
  omega0
  ;
  /**
* Rate of right ascension[rad/s]
   */
    double
  omegadot
  ;
  /**
* Argument of perigee[rad]
   */
    double
  w
  ;
  /**
* Inclination[rad]
   */
    double
  inc
  ;
  /**
* Inclination first derivative[rad/s]
   */
    double
  inc_dot
  ;
  /**
* Polynomial clock correction coefficient (clock bias)[s]
   */
    double
  af0
  ;
  /**
* Polynomial clock correction coefficient (clock drift)[s/s]
   */
    double
  af1
  ;
  /**
* Polynomial clock correction coefficient (rate of clock drift)[s/s^2]
   */
    double
  af2
  ;
  /**
* Time of week[s]
   */
    double
  toe_tow
  ;
  /**
* Week number[week]
   */
    u16
  toe_wn
  ;
  /**
* Clock reference time of week[s]
   */
    double
  toc_tow
  ;
  /**
* Clock reference week number[week]
   */
    u16
  toc_wn
  ;
  /**
* Is valid?
   */
    u8
  valid
  ;
  /**
* Satellite is healthy?
   */
    u8
  healthy
  ;
  /**
* GNSS signal identifier
   */
  sbp_gnss_signal_dep_t
  sid
  ;
  /**
* Issue of ephemeris data
   */
    u8
  iode
  ;
  /**
* Issue of clock data
   */
    u16
  iodc
  ;
  /**
* Reserved field
   */
    u32
  reserved
  ;
} sbp_msg_ephemeris_dep_d_t;


  /** Deprecated
   *
* Deprecated.
   */
#define SBP_MSG_EPHEMERIS_DEP_A          0x001A

typedef struct {
  
  /**
* Group delay differential between L1 and L2[s]
   */
    double
  tgd
  ;
  /**
* Amplitude of the sine harmonic correction term to the orbit radius[m]
   */
    double
  c_rs
  ;
  /**
* Amplitude of the cosine harmonic correction term to the orbit radius[m]
   */
    double
  c_rc
  ;
  /**
* Amplitude of the cosine harmonic correction term to the argument of latitude[rad]
   */
    double
  c_uc
  ;
  /**
* Amplitude of the sine harmonic correction term to the argument of latitude[rad]
   */
    double
  c_us
  ;
  /**
* Amplitude of the cosine harmonic correction term to the angle of inclination[rad]
   */
    double
  c_ic
  ;
  /**
* Amplitude of the sine harmonic correction term to the angle of inclination[rad]
   */
    double
  c_is
  ;
  /**
* Mean motion difference[rad/s]
   */
    double
  dn
  ;
  /**
* Mean anomaly at reference time[rad]
   */
    double
  m0
  ;
  /**
* Eccentricity of satellite orbit
   */
    double
  ecc
  ;
  /**
* Square root of the semi-major axis of orbit[m^(1/2)]
   */
    double
  sqrta
  ;
  /**
* Longitude of ascending node of orbit plane at weekly epoch[rad]
   */
    double
  omega0
  ;
  /**
* Rate of right ascension[rad/s]
   */
    double
  omegadot
  ;
  /**
* Argument of perigee[rad]
   */
    double
  w
  ;
  /**
* Inclination[rad]
   */
    double
  inc
  ;
  /**
* Inclination first derivative[rad/s]
   */
    double
  inc_dot
  ;
  /**
* Polynomial clock correction coefficient (clock bias)[s]
   */
    double
  af0
  ;
  /**
* Polynomial clock correction coefficient (clock drift)[s/s]
   */
    double
  af1
  ;
  /**
* Polynomial clock correction coefficient (rate of clock drift)[s/s^2]
   */
    double
  af2
  ;
  /**
* Time of week[s]
   */
    double
  toe_tow
  ;
  /**
* Week number[week]
   */
    u16
  toe_wn
  ;
  /**
* Clock reference time of week[s]
   */
    double
  toc_tow
  ;
  /**
* Clock reference week number[week]
   */
    u16
  toc_wn
  ;
  /**
* Is valid?
   */
    u8
  valid
  ;
  /**
* Satellite is healthy?
   */
    u8
  healthy
  ;
  /**
* PRN being tracked
   */
    u8
  prn
  ;
} sbp_msg_ephemeris_dep_a_t;


  /** Deprecated
   *
* Deprecated.
   */
#define SBP_MSG_EPHEMERIS_DEP_B          0x0046

typedef struct {
  
  /**
* Group delay differential between L1 and L2[s]
   */
    double
  tgd
  ;
  /**
* Amplitude of the sine harmonic correction term to the orbit radius[m]
   */
    double
  c_rs
  ;
  /**
* Amplitude of the cosine harmonic correction term to the orbit radius[m]
   */
    double
  c_rc
  ;
  /**
* Amplitude of the cosine harmonic correction term to the argument of latitude[rad]
   */
    double
  c_uc
  ;
  /**
* Amplitude of the sine harmonic correction term to the argument of latitude[rad]
   */
    double
  c_us
  ;
  /**
* Amplitude of the cosine harmonic correction term to the angle of inclination[rad]
   */
    double
  c_ic
  ;
  /**
* Amplitude of the sine harmonic correction term to the angle of inclination[rad]
   */
    double
  c_is
  ;
  /**
* Mean motion difference[rad/s]
   */
    double
  dn
  ;
  /**
* Mean anomaly at reference time[rad]
   */
    double
  m0
  ;
  /**
* Eccentricity of satellite orbit
   */
    double
  ecc
  ;
  /**
* Square root of the semi-major axis of orbit[m^(1/2)]
   */
    double
  sqrta
  ;
  /**
* Longitude of ascending node of orbit plane at weekly epoch[rad]
   */
    double
  omega0
  ;
  /**
* Rate of right ascension[rad/s]
   */
    double
  omegadot
  ;
  /**
* Argument of perigee[rad]
   */
    double
  w
  ;
  /**
* Inclination[rad]
   */
    double
  inc
  ;
  /**
* Inclination first derivative[rad/s]
   */
    double
  inc_dot
  ;
  /**
* Polynomial clock correction coefficient (clock bias)[s]
   */
    double
  af0
  ;
  /**
* Polynomial clock correction coefficient (clock drift)[s/s]
   */
    double
  af1
  ;
  /**
* Polynomial clock correction coefficient (rate of clock drift)[s/s^2]
   */
    double
  af2
  ;
  /**
* Time of week[s]
   */
    double
  toe_tow
  ;
  /**
* Week number[week]
   */
    u16
  toe_wn
  ;
  /**
* Clock reference time of week[s]
   */
    double
  toc_tow
  ;
  /**
* Clock reference week number[week]
   */
    u16
  toc_wn
  ;
  /**
* Is valid?
   */
    u8
  valid
  ;
  /**
* Satellite is healthy?
   */
    u8
  healthy
  ;
  /**
* PRN being tracked
   */
    u8
  prn
  ;
  /**
* Issue of ephemeris data
   */
    u8
  iode
  ;
} sbp_msg_ephemeris_dep_b_t;


  /** Satellite broadcast ephemeris
   *
 * The ephemeris message returns a set of satellite orbit
 * parameters that is used to calculate GPS satellite position,
 * velocity, and clock offset. Please see the Navstar GPS
 * Space Segment/Navigation user interfaces (ICD-GPS-200, Table
 * 20-III) for more details.
   */
#define SBP_MSG_EPHEMERIS_DEP_C          0x0047

	
	#define SBP_EPHEMERIS_DEP_C_SID_CODE__MASK (0xff)
#define SBP_EPHEMERIS_DEP_C_SID_CODE__SHIFT (0u)
#define SBP_EPHEMERIS_DEP_C_SID_CODE__GET(flags) \
                             (((flags) >> SBP_EPHEMERIS_DEP_C_SID_CODE__SHIFT) \
                             & SBP_EPHEMERIS_DEP_C_SID_CODE__MASK)
#define SBP_EPHEMERIS_DEP_C_SID_CODE__SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_EPHEMERIS_DEP_C_SID_CODE__MASK)) \
                             << (SBP_EPHEMERIS_DEP_C_SID_CODE__SHIFT)));} while(0)
                             

#define SBP_EPHEMERIS_DEP_C_SID_CODE__GPS_L1CA (0)
#define SBP_EPHEMERIS_DEP_C_SID_CODE__GPS_L2CM (1)
#define SBP_EPHEMERIS_DEP_C_SID_CODE__SBAS_L1CA (2)
#define SBP_EPHEMERIS_DEP_C_SID_CODE__GLO_L1CA (3)
#define SBP_EPHEMERIS_DEP_C_SID_CODE__GLO_L2CA (4)
#define SBP_EPHEMERIS_DEP_C_SID_CODE__GPS_L1P (5)
#define SBP_EPHEMERIS_DEP_C_SID_CODE__GPS_L2P (6)
typedef struct {
  
  /**
* Group delay differential between L1 and L2[s]
   */
    double
  tgd
  ;
  /**
* Amplitude of the sine harmonic correction term to the orbit radius[m]
   */
    double
  c_rs
  ;
  /**
* Amplitude of the cosine harmonic correction term to the orbit radius[m]
   */
    double
  c_rc
  ;
  /**
* Amplitude of the cosine harmonic correction term to the argument of latitude[rad]
   */
    double
  c_uc
  ;
  /**
* Amplitude of the sine harmonic correction term to the argument of latitude[rad]
   */
    double
  c_us
  ;
  /**
* Amplitude of the cosine harmonic correction term to the angle of inclination[rad]
   */
    double
  c_ic
  ;
  /**
* Amplitude of the sine harmonic correction term to the angle of inclination[rad]
   */
    double
  c_is
  ;
  /**
* Mean motion difference[rad/s]
   */
    double
  dn
  ;
  /**
* Mean anomaly at reference time[rad]
   */
    double
  m0
  ;
  /**
* Eccentricity of satellite orbit
   */
    double
  ecc
  ;
  /**
* Square root of the semi-major axis of orbit[m^(1/2)]
   */
    double
  sqrta
  ;
  /**
* Longitude of ascending node of orbit plane at weekly epoch[rad]
   */
    double
  omega0
  ;
  /**
* Rate of right ascension[rad/s]
   */
    double
  omegadot
  ;
  /**
* Argument of perigee[rad]
   */
    double
  w
  ;
  /**
* Inclination[rad]
   */
    double
  inc
  ;
  /**
* Inclination first derivative[rad/s]
   */
    double
  inc_dot
  ;
  /**
* Polynomial clock correction coefficient (clock bias)[s]
   */
    double
  af0
  ;
  /**
* Polynomial clock correction coefficient (clock drift)[s/s]
   */
    double
  af1
  ;
  /**
* Polynomial clock correction coefficient (rate of clock drift)[s/s^2]
   */
    double
  af2
  ;
  /**
* Time of week[s]
   */
    double
  toe_tow
  ;
  /**
* Week number[week]
   */
    u16
  toe_wn
  ;
  /**
* Clock reference time of week[s]
   */
    double
  toc_tow
  ;
  /**
* Clock reference week number[week]
   */
    u16
  toc_wn
  ;
  /**
* Is valid?
   */
    u8
  valid
  ;
  /**
* Satellite is healthy?
   */
    u8
  healthy
  ;
  /**
* GNSS signal identifier
   */
  sbp_gnss_signal_dep_t
  sid
  ;
  /**
* Issue of ephemeris data
   */
    u8
  iode
  ;
  /**
* Issue of clock data
   */
    u16
  iodc
  ;
  /**
* Reserved field
   */
    u32
  reserved
  ;
} sbp_msg_ephemeris_dep_c_t;


  /** Header for observation message.
   *
* Header of a GPS observation message.
   */

	
typedef struct {
  
  /**
* GPS time of this observation
   */
  sbp_gps_time_dep_t
  t
  ;
  /**
 * Total number of observations. First nibble is the size
 * of the sequence (n), second nibble is the zero-indexed
 * counter (ith packet of n)
   */
    u8
  n_obs
  ;
} sbp_observation_header_dep_t;


  /** GPS carrier phase measurement.
   *
 * Carrier phase measurement in cycles represented as a 40-bit
 * fixed point number with Q32.8 layout, i.e. 32-bits of whole
 * cycles and 8-bits of fractional cycles. This has the opposite
 * sign convention than a typical GPS receiver and the phase has
 * the opposite sign as the pseudorange.
   */

typedef struct {
  
  /**
* Carrier phase whole cycles[cycles]
   */
    s32
  i
  ;
  /**
* Carrier phase fractional part[cycles / 256]
   */
    u8
  f
  ;
} sbp_carrier_phase_dep_a_t;


  /** Deprecated
   *
* Deprecated.
   */

	
typedef struct {
  
  /**
* Pseudorange observation[cm]
   */
    u32
  P
  ;
  /**
* Carrier phase observation with opposite sign from typical convention
   */
  sbp_carrier_phase_dep_a_t
  L
  ;
  /**
* Carrier-to-Noise density[dB Hz / 4]
   */
    u8
  cn0
  ;
  /**
 * Lock indicator. This value changes whenever a satellite
 * signal has lost and regained lock, indicating that the
 * carrier phase ambiguity may have changed.
   */
    u16
  lock
  ;
  /**
* PRN-1 identifier of the satellite signal
   */
    u8
  prn
  ;
} sbp_packed_obs_content_dep_a_t;


  /** GPS observations for a particular satellite signal.
   *
 * Pseudorange and carrier phase observation for a satellite being
 * tracked.  Pseudoranges are referenced to a nominal pseudorange.
   */

	
	
	#define SBP_PACKEDOBSCONTENTDEPB_SID_CODE__MASK (0xff)
#define SBP_PACKEDOBSCONTENTDEPB_SID_CODE__SHIFT (0u)
#define SBP_PACKEDOBSCONTENTDEPB_SID_CODE__GET(flags) \
                             (((flags) >> SBP_PACKEDOBSCONTENTDEPB_SID_CODE__SHIFT) \
                             & SBP_PACKEDOBSCONTENTDEPB_SID_CODE__MASK)
#define SBP_PACKEDOBSCONTENTDEPB_SID_CODE__SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_PACKEDOBSCONTENTDEPB_SID_CODE__MASK)) \
                             << (SBP_PACKEDOBSCONTENTDEPB_SID_CODE__SHIFT)));} while(0)
                             

#define SBP_PACKEDOBSCONTENTDEPB_SID_CODE__GPS_L1CA (0)
#define SBP_PACKEDOBSCONTENTDEPB_SID_CODE__GPS_L2CM (1)
#define SBP_PACKEDOBSCONTENTDEPB_SID_CODE__SBAS_L1CA (2)
#define SBP_PACKEDOBSCONTENTDEPB_SID_CODE__GLO_L1CA (3)
#define SBP_PACKEDOBSCONTENTDEPB_SID_CODE__GLO_L2CA (4)
#define SBP_PACKEDOBSCONTENTDEPB_SID_CODE__GPS_L1P (5)
#define SBP_PACKEDOBSCONTENTDEPB_SID_CODE__GPS_L2P (6)
typedef struct {
  
  /**
* Pseudorange observation[cm]
   */
    u32
  P
  ;
  /**
* Carrier phase observation with opposite sign from typical convention.
   */
  sbp_carrier_phase_dep_a_t
  L
  ;
  /**
* Carrier-to-Noise density[dB Hz / 4]
   */
    u8
  cn0
  ;
  /**
 * Lock indicator. This value changes whenever a satellite
 * signal has lost and regained lock, indicating that the
 * carrier phase ambiguity may have changed.
   */
    u16
  lock
  ;
  /**
* GNSS signal identifier
   */
  sbp_gnss_signal_dep_t
  sid
  ;
} sbp_packed_obs_content_dep_b_t;


  /** GPS observations for a particular satellite signal.
   *
 * Pseudorange and carrier phase observation for a satellite being
 * tracked. The observations are be interoperable with 3rd party
 * receivers and conform with typical RTCMv3 GNSS observations.
   */

	
	
	#define SBP_PACKEDOBSCONTENTDEPC_SID_CODE__MASK (0xff)
#define SBP_PACKEDOBSCONTENTDEPC_SID_CODE__SHIFT (0u)
#define SBP_PACKEDOBSCONTENTDEPC_SID_CODE__GET(flags) \
                             (((flags) >> SBP_PACKEDOBSCONTENTDEPC_SID_CODE__SHIFT) \
                             & SBP_PACKEDOBSCONTENTDEPC_SID_CODE__MASK)
#define SBP_PACKEDOBSCONTENTDEPC_SID_CODE__SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_PACKEDOBSCONTENTDEPC_SID_CODE__MASK)) \
                             << (SBP_PACKEDOBSCONTENTDEPC_SID_CODE__SHIFT)));} while(0)
                             

#define SBP_PACKEDOBSCONTENTDEPC_SID_CODE__GPS_L1CA (0)
#define SBP_PACKEDOBSCONTENTDEPC_SID_CODE__GPS_L2CM (1)
#define SBP_PACKEDOBSCONTENTDEPC_SID_CODE__SBAS_L1CA (2)
#define SBP_PACKEDOBSCONTENTDEPC_SID_CODE__GLO_L1CA (3)
#define SBP_PACKEDOBSCONTENTDEPC_SID_CODE__GLO_L2CA (4)
#define SBP_PACKEDOBSCONTENTDEPC_SID_CODE__GPS_L1P (5)
#define SBP_PACKEDOBSCONTENTDEPC_SID_CODE__GPS_L2P (6)
typedef struct {
  
  /**
* Pseudorange observation[2 cm]
   */
    u32
  P
  ;
  /**
* Carrier phase observation with typical sign convention.[cycles]
   */
  sbp_carrier_phase_t
  L
  ;
  /**
* Carrier-to-Noise density[dB Hz / 4]
   */
    u8
  cn0
  ;
  /**
 * Lock indicator. This value changes whenever a satellite
 * signal has lost and regained lock, indicating that the
 * carrier phase ambiguity may have changed.
   */
    u16
  lock
  ;
  /**
* GNSS signal identifier
   */
  sbp_gnss_signal_dep_t
  sid
  ;
} sbp_packed_obs_content_dep_c_t;


  /** Deprecated
   *
* Deprecated.
   */
#define SBP_MSG_OBS_DEP_A                0x0045

	
	
	
	
typedef struct {
  
  /**
* Header of a GPS observation message
   */
  sbp_observation_header_dep_t
  header
  ;
  /**
 * Pseudorange and carrier phase observation for a
 * satellite being tracked.
   */
  sbp_packed_obs_content_dep_a_t
  obs
    [19]
  ;
  /**
   * Number of items in obs
   */
  u8 n_obs;
} sbp_msg_obs_dep_a_t;


  /** Deprecated
   *
 * This observation message has been deprecated in favor of
 * observations that are more interoperable. This message
 * should be used for observations referenced to
 * a nominal pseudorange which are not interoperable with
 * most 3rd party GNSS receievers or typical RTCMv3
 * observations.
   */
#define SBP_MSG_OBS_DEP_B                0x0043

	
	
	
	
	
	#define SBP_OBS_DEP_B_OBS_SID_CODE__MASK (0xff)
#define SBP_OBS_DEP_B_OBS_SID_CODE__SHIFT (0u)
#define SBP_OBS_DEP_B_OBS_SID_CODE__GET(flags) \
                             (((flags) >> SBP_OBS_DEP_B_OBS_SID_CODE__SHIFT) \
                             & SBP_OBS_DEP_B_OBS_SID_CODE__MASK)
#define SBP_OBS_DEP_B_OBS_SID_CODE__SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_OBS_DEP_B_OBS_SID_CODE__MASK)) \
                             << (SBP_OBS_DEP_B_OBS_SID_CODE__SHIFT)));} while(0)
                             

#define SBP_OBS_DEP_B_OBS_SID_CODE__GPS_L1CA (0)
#define SBP_OBS_DEP_B_OBS_SID_CODE__GPS_L2CM (1)
#define SBP_OBS_DEP_B_OBS_SID_CODE__SBAS_L1CA (2)
#define SBP_OBS_DEP_B_OBS_SID_CODE__GLO_L1CA (3)
#define SBP_OBS_DEP_B_OBS_SID_CODE__GLO_L2CA (4)
#define SBP_OBS_DEP_B_OBS_SID_CODE__GPS_L1P (5)
#define SBP_OBS_DEP_B_OBS_SID_CODE__GPS_L2P (6)
typedef struct {
  
  /**
* Header of a GPS observation message
   */
  sbp_observation_header_dep_t
  header
  ;
  /**
 * Pseudorange and carrier phase observation for a
 * satellite being tracked.
   */
  sbp_packed_obs_content_dep_b_t
  obs
    [15]
  ;
  /**
   * Number of items in obs
   */
  u8 n_obs;
} sbp_msg_obs_dep_b_t;


  /** Deprecated
   *
 * The GPS observations message reports all the raw pseudorange and
 * carrier phase observations for the satellites being tracked by
 * the device. Carrier phase observation here is represented as a
 * 40-bit fixed point number with Q32.8 layout (i.e. 32-bits of
 * whole cycles and 8-bits of fractional cycles). The observations
 * are interoperable with 3rd party receivers and conform
 * with typical RTCMv3 GNSS observations.
   */
#define SBP_MSG_OBS_DEP_C                0x0049

	
	
	
	
	
	#define SBP_OBS_DEP_C_OBS_SID_CODE__MASK (0xff)
#define SBP_OBS_DEP_C_OBS_SID_CODE__SHIFT (0u)
#define SBP_OBS_DEP_C_OBS_SID_CODE__GET(flags) \
                             (((flags) >> SBP_OBS_DEP_C_OBS_SID_CODE__SHIFT) \
                             & SBP_OBS_DEP_C_OBS_SID_CODE__MASK)
#define SBP_OBS_DEP_C_OBS_SID_CODE__SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_OBS_DEP_C_OBS_SID_CODE__MASK)) \
                             << (SBP_OBS_DEP_C_OBS_SID_CODE__SHIFT)));} while(0)
                             

#define SBP_OBS_DEP_C_OBS_SID_CODE__GPS_L1CA (0)
#define SBP_OBS_DEP_C_OBS_SID_CODE__GPS_L2CM (1)
#define SBP_OBS_DEP_C_OBS_SID_CODE__SBAS_L1CA (2)
#define SBP_OBS_DEP_C_OBS_SID_CODE__GLO_L1CA (3)
#define SBP_OBS_DEP_C_OBS_SID_CODE__GLO_L2CA (4)
#define SBP_OBS_DEP_C_OBS_SID_CODE__GPS_L1P (5)
#define SBP_OBS_DEP_C_OBS_SID_CODE__GPS_L2P (6)
typedef struct {
  
  /**
* Header of a GPS observation message
   */
  sbp_observation_header_dep_t
  header
  ;
  /**
 * Pseudorange and carrier phase observation for a
 * satellite being tracked.
   */
  sbp_packed_obs_content_dep_c_t
  obs
    [15]
  ;
  /**
   * Number of items in obs
   */
  u8 n_obs;
} sbp_msg_obs_dep_c_t;


  /** Iono corrections
   *
 * The ionospheric parameters which allow the "L1 only" or "L2 only" user to
 * utilize the ionospheric model for computation of the ionospheric delay.
 * Please see ICD-GPS-200 (Chapter 20.3.3.5.1.7) for more details.
   */
#define SBP_MSG_IONO                     0x0090

	
typedef struct {
  
  /**
* Navigation Message Correction Table Valitidy Time
   */
  sbp_gps_time_sec_t
  t_nmct
  ;
    double
  a0
  ;
    double
  a1
  ;
    double
  a2
  ;
    double
  a3
  ;
    double
  b0
  ;
    double
  b1
  ;
    double
  b2
  ;
    double
  b3
  ;
} sbp_msg_iono_t;


  /** L2C capability mask
   *
 * Please see ICD-GPS-200 (Chapter 20.3.3.5.1.4) for more details.
   */
#define SBP_MSG_SV_CONFIGURATION_GPS_DEP 0x0091

	
typedef struct {
  
  /**
* Navigation Message Correction Table Valitidy Time
   */
  sbp_gps_time_sec_t
  t_nmct
  ;
  /**
* L2C capability mask, SV32 bit being MSB, SV1 bit being LSB
   */
    u32
  l2c_mask
  ;
} sbp_msg_sv_configuration_gps_dep_t;



typedef struct {
  
  /**
* GPS SV active mask
   */
    u64
  gps_active
  ;
  /**
* GPS L2C active mask
   */
    u64
  gps_l2c
  ;
  /**
* GPS L5 active mask
   */
    u64
  gps_l5
  ;
  /**
* GLO active mask
   */
    u32
  glo_active
  ;
  /**
* GLO L2OF active mask
   */
    u32
  glo_l2of
  ;
  /**
* GLO L3 active mask
   */
    u32
  glo_l3
  ;
  /**
 * SBAS active mask (PRNs 120..158, AN 7/62.2.2-18/18 Table B-23,
 * https://www.caat.or.th/wp-content/uploads/2018/03/SL-2018.18.E-1.pdf)
   */
    u64
  sbas_active
  ;
  /**
 * SBAS L5 active mask (PRNs 120..158, AN 7/62.2.2-18/18 Table B-23,
 * https://www.caat.or.th/wp-content/uploads/2018/03/SL-2018.18.E-1.pdf)
   */
    u64
  sbas_l5
  ;
  /**
* BDS active mask
   */
    u64
  bds_active
  ;
  /**
* BDS D2NAV active mask
   */
    u64
  bds_d2nav
  ;
  /**
* BDS B2 active mask
   */
    u64
  bds_b2
  ;
  /**
* BDS B2A active mask
   */
    u64
  bds_b2a
  ;
  /**
* QZSS active mask
   */
    u32
  qzss_active
  ;
  /**
* GAL active mask
   */
    u64
  gal_active
  ;
  /**
* GAL E5 active mask
   */
    u64
  gal_e5
  ;
} sbp_gnss_capb_t;


#define SBP_MSG_GNSS_CAPB                0x0096

	
	
typedef struct {
  
  /**
* Navigation Message Correction Table Validity Time
   */
  sbp_gps_time_sec_t
  t_nmct
  ;
  /**
* GNSS capabilities masks
   */
  sbp_gnss_capb_t
  gc
  ;
} sbp_msg_gnss_capb_t;


  /** Group Delay
   *
* Please see ICD-GPS-200 (30.3.3.3.1.1) for more details.
   */
#define SBP_MSG_GROUP_DELAY_DEP_A        0x0092

	
typedef struct {
  
  /**
* Data Predict Time of Week
   */
  sbp_gps_time_dep_t
  t_op
  ;
  /**
* Satellite number
   */
    u8
  prn
  ;
  /**
 * bit-field indicating validity of the values,
 * LSB indicating tgd validity etc.
 * 1 = value is valid, 0 = value is not valid.
   */
    u8
  valid
  ;
    s16
  tgd
  ;
    s16
  isc_l1ca
  ;
    s16
  isc_l2c
  ;
} sbp_msg_group_delay_dep_a_t;


  /** Group Delay
   *
* Please see ICD-GPS-200 (30.3.3.3.1.1) for more details.
   */
#define SBP_MSG_GROUP_DELAY_DEP_B        0x0093

	
	
	#define SBP_GROUP_DELAY_DEP_B_SID_CODE__MASK (0xff)
#define SBP_GROUP_DELAY_DEP_B_SID_CODE__SHIFT (0u)
#define SBP_GROUP_DELAY_DEP_B_SID_CODE__GET(flags) \
                             (((flags) >> SBP_GROUP_DELAY_DEP_B_SID_CODE__SHIFT) \
                             & SBP_GROUP_DELAY_DEP_B_SID_CODE__MASK)
#define SBP_GROUP_DELAY_DEP_B_SID_CODE__SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_GROUP_DELAY_DEP_B_SID_CODE__MASK)) \
                             << (SBP_GROUP_DELAY_DEP_B_SID_CODE__SHIFT)));} while(0)
                             

#define SBP_GROUP_DELAY_DEP_B_SID_CODE__GPS_L1CA (0)
#define SBP_GROUP_DELAY_DEP_B_SID_CODE__GPS_L2CM (1)
#define SBP_GROUP_DELAY_DEP_B_SID_CODE__SBAS_L1CA (2)
#define SBP_GROUP_DELAY_DEP_B_SID_CODE__GLO_L1CA (3)
#define SBP_GROUP_DELAY_DEP_B_SID_CODE__GLO_L2CA (4)
#define SBP_GROUP_DELAY_DEP_B_SID_CODE__GPS_L1P (5)
#define SBP_GROUP_DELAY_DEP_B_SID_CODE__GPS_L2P (6)
typedef struct {
  
  /**
* Data Predict Time of Week
   */
  sbp_gps_time_sec_t
  t_op
  ;
  /**
* GNSS signal identifier
   */
  sbp_gnss_signal_dep_t
  sid
  ;
  /**
 * bit-field indicating validity of the values,
 * LSB indicating tgd validity etc.
 * 1 = value is valid, 0 = value is not valid.
   */
    u8
  valid
  ;
    s16
  tgd
  ;
    s16
  isc_l1ca
  ;
    s16
  isc_l2c
  ;
} sbp_msg_group_delay_dep_b_t;


  /** Group Delay
   *
* Please see ICD-GPS-200 (30.3.3.3.1.1) for more details.
   */
#define SBP_MSG_GROUP_DELAY              0x0094

	
	
	#define SBP_GROUP_DELAY_SID_CODE__MASK (0xff)
#define SBP_GROUP_DELAY_SID_CODE__SHIFT (0u)
#define SBP_GROUP_DELAY_SID_CODE__GET(flags) \
                             (((flags) >> SBP_GROUP_DELAY_SID_CODE__SHIFT) \
                             & SBP_GROUP_DELAY_SID_CODE__MASK)
#define SBP_GROUP_DELAY_SID_CODE__SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_GROUP_DELAY_SID_CODE__MASK)) \
                             << (SBP_GROUP_DELAY_SID_CODE__SHIFT)));} while(0)
                             

#define SBP_GROUP_DELAY_SID_CODE__GPS_L1CA (0)
#define SBP_GROUP_DELAY_SID_CODE__GPS_L2CM (1)
#define SBP_GROUP_DELAY_SID_CODE__SBAS_L1CA (2)
#define SBP_GROUP_DELAY_SID_CODE__GLO_L1CA (3)
#define SBP_GROUP_DELAY_SID_CODE__GLO_L2CA (4)
#define SBP_GROUP_DELAY_SID_CODE__GPS_L1P (5)
#define SBP_GROUP_DELAY_SID_CODE__GPS_L2P (6)
#define SBP_GROUP_DELAY_SID_CODE__BDS2_B1 (12)
#define SBP_GROUP_DELAY_SID_CODE__BDS2_B2 (13)
#define SBP_GROUP_DELAY_SID_CODE__GAL_E1B (14)
#define SBP_GROUP_DELAY_SID_CODE__GAL_E7I (20)
#define SBP_GROUP_DELAY_SID_CODE__BDS3_B2A (47)
typedef struct {
  
  /**
* Data Predict Time of Week
   */
  sbp_gps_time_sec_t
  t_op
  ;
  /**
* GNSS signal identifier
   */
  sbp_sbp_gnss_signal_t
  sid
  ;
  /**
 * bit-field indicating validity of the values,
 * LSB indicating tgd validity etc.
 * 1 = value is valid, 0 = value is not valid.
   */
    u8
  valid
  ;
    s16
  tgd
  ;
    s16
  isc_l1ca
  ;
    s16
  isc_l2c
  ;
} sbp_msg_group_delay_t;



	
	#define SBP_ALMANACCOMMONCONTENT_SID_CODE__MASK (0xff)
#define SBP_ALMANACCOMMONCONTENT_SID_CODE__SHIFT (0u)
#define SBP_ALMANACCOMMONCONTENT_SID_CODE__GET(flags) \
                             (((flags) >> SBP_ALMANACCOMMONCONTENT_SID_CODE__SHIFT) \
                             & SBP_ALMANACCOMMONCONTENT_SID_CODE__MASK)
#define SBP_ALMANACCOMMONCONTENT_SID_CODE__SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_ALMANACCOMMONCONTENT_SID_CODE__MASK)) \
                             << (SBP_ALMANACCOMMONCONTENT_SID_CODE__SHIFT)));} while(0)
                             

#define SBP_ALMANACCOMMONCONTENT_SID_CODE__GPS_L1CA (0)
#define SBP_ALMANACCOMMONCONTENT_SID_CODE__GPS_L2CM (1)
#define SBP_ALMANACCOMMONCONTENT_SID_CODE__SBAS_L1CA (2)
#define SBP_ALMANACCOMMONCONTENT_SID_CODE__GLO_L1CA (3)
#define SBP_ALMANACCOMMONCONTENT_SID_CODE__GLO_L2CA (4)
#define SBP_ALMANACCOMMONCONTENT_SID_CODE__GPS_L1P (5)
#define SBP_ALMANACCOMMONCONTENT_SID_CODE__GPS_L2P (6)
#define SBP_ALMANACCOMMONCONTENT_SID_CODE__BDS2_B1 (12)
#define SBP_ALMANACCOMMONCONTENT_SID_CODE__BDS2_B2 (13)
#define SBP_ALMANACCOMMONCONTENT_SID_CODE__GAL_E1B (14)
#define SBP_ALMANACCOMMONCONTENT_SID_CODE__GAL_E7I (20)
#define SBP_ALMANACCOMMONCONTENT_SID_CODE__BDS3_B2A (47)
	
typedef struct {
  
  /**
* GNSS signal identifier
   */
  sbp_sbp_gnss_signal_t
  sid
  ;
  /**
* Reference time of almanac
   */
  sbp_gps_time_sec_t
  toa
  ;
  /**
* User Range Accuracy[m]
   */
    double
  ura
  ;
  /**
* Curve fit interval[s]
   */
    u32
  fit_interval
  ;
  /**
* Status of almanac, 1 = valid, 0 = invalid
   */
    u8
  valid
  ;
  /**
 * Satellite health status for GPS:
 *   - bits 5-7: NAV data health status. See IS-GPS-200H
 *     Table 20-VII: NAV Data Health Indications.
 *   - bits 0-4: Signal health status. See IS-GPS-200H
 *     Table 20-VIII. Codes for Health of SV Signal
 *     Components.
 * Satellite health status for GLO:
 *   See GLO ICD 5.1 table 5.1 for details
 *   - bit 0: C(n), "unhealthy" flag that is transmitted within
 *     non-immediate data and indicates overall constellation status
 *     at the moment of almanac uploading.
 *     '0' indicates malfunction of n-satellite.
 *     '1' indicates that n-satellite is operational.
 *   - bit 1: Bn(ln), '0' indicates the satellite is operational
 *     and suitable for navigation.
   */
    u8
  health_bits
  ;
} sbp_almanac_common_content_t;



	
	#define SBP_ALMANACCOMMONCONTENTDEP_SID_CODE__MASK (0xff)
#define SBP_ALMANACCOMMONCONTENTDEP_SID_CODE__SHIFT (0u)
#define SBP_ALMANACCOMMONCONTENTDEP_SID_CODE__GET(flags) \
                             (((flags) >> SBP_ALMANACCOMMONCONTENTDEP_SID_CODE__SHIFT) \
                             & SBP_ALMANACCOMMONCONTENTDEP_SID_CODE__MASK)
#define SBP_ALMANACCOMMONCONTENTDEP_SID_CODE__SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_ALMANACCOMMONCONTENTDEP_SID_CODE__MASK)) \
                             << (SBP_ALMANACCOMMONCONTENTDEP_SID_CODE__SHIFT)));} while(0)
                             

#define SBP_ALMANACCOMMONCONTENTDEP_SID_CODE__GPS_L1CA (0)
#define SBP_ALMANACCOMMONCONTENTDEP_SID_CODE__GPS_L2CM (1)
#define SBP_ALMANACCOMMONCONTENTDEP_SID_CODE__SBAS_L1CA (2)
#define SBP_ALMANACCOMMONCONTENTDEP_SID_CODE__GLO_L1CA (3)
#define SBP_ALMANACCOMMONCONTENTDEP_SID_CODE__GLO_L2CA (4)
#define SBP_ALMANACCOMMONCONTENTDEP_SID_CODE__GPS_L1P (5)
#define SBP_ALMANACCOMMONCONTENTDEP_SID_CODE__GPS_L2P (6)
	
typedef struct {
  
  /**
* GNSS signal identifier
   */
  sbp_gnss_signal_dep_t
  sid
  ;
  /**
* Reference time of almanac
   */
  sbp_gps_time_sec_t
  toa
  ;
  /**
* User Range Accuracy[m]
   */
    double
  ura
  ;
  /**
* Curve fit interval[s]
   */
    u32
  fit_interval
  ;
  /**
* Status of almanac, 1 = valid, 0 = invalid
   */
    u8
  valid
  ;
  /**
 * Satellite health status for GPS:
 *   - bits 5-7: NAV data health status. See IS-GPS-200H
 *     Table 20-VII: NAV Data Health Indications.
 *   - bits 0-4: Signal health status. See IS-GPS-200H
 *     Table 20-VIII. Codes for Health of SV Signal
 *     Components.
 * Satellite health status for GLO:
 *   See GLO ICD 5.1 table 5.1 for details
 *   - bit 0: C(n), "unhealthy" flag that is transmitted within
 *     non-immediate data and indicates overall constellation status
 *     at the moment of almanac uploading.
 *     '0' indicates malfunction of n-satellite.
 *     '1' indicates that n-satellite is operational.
 *   - bit 1: Bn(ln), '0' indicates the satellite is operational
 *     and suitable for navigation.
   */
    u8
  health_bits
  ;
} sbp_almanac_common_content_dep_t;


  /** Satellite broadcast ephemeris for GPS
   *
 * The almanac message returns a set of satellite orbit parameters. Almanac
 * data is not very precise and is considered valid for up to several months.
 * Please see the Navstar GPS Space Segment/Navigation user interfaces
 * (ICD-GPS-200, Chapter 20.3.3.5.1.2 Almanac Data) for more details.
   */
#define SBP_MSG_ALMANAC_GPS_DEP          0x0070

	
	
	#define SBP_ALMANAC_GPS_DEP_COMMON_SID_CODE__MASK (0xff)
#define SBP_ALMANAC_GPS_DEP_COMMON_SID_CODE__SHIFT (0u)
#define SBP_ALMANAC_GPS_DEP_COMMON_SID_CODE__GET(flags) \
                             (((flags) >> SBP_ALMANAC_GPS_DEP_COMMON_SID_CODE__SHIFT) \
                             & SBP_ALMANAC_GPS_DEP_COMMON_SID_CODE__MASK)
#define SBP_ALMANAC_GPS_DEP_COMMON_SID_CODE__SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_ALMANAC_GPS_DEP_COMMON_SID_CODE__MASK)) \
                             << (SBP_ALMANAC_GPS_DEP_COMMON_SID_CODE__SHIFT)));} while(0)
                             

#define SBP_ALMANAC_GPS_DEP_COMMON_SID_CODE__GPS_L1CA (0)
#define SBP_ALMANAC_GPS_DEP_COMMON_SID_CODE__GPS_L2CM (1)
#define SBP_ALMANAC_GPS_DEP_COMMON_SID_CODE__SBAS_L1CA (2)
#define SBP_ALMANAC_GPS_DEP_COMMON_SID_CODE__GLO_L1CA (3)
#define SBP_ALMANAC_GPS_DEP_COMMON_SID_CODE__GLO_L2CA (4)
#define SBP_ALMANAC_GPS_DEP_COMMON_SID_CODE__GPS_L1P (5)
#define SBP_ALMANAC_GPS_DEP_COMMON_SID_CODE__GPS_L2P (6)
	
typedef struct {
  
  /**
* Values common for all almanac types
   */
  sbp_almanac_common_content_dep_t
  common
  ;
  /**
* Mean anomaly at reference time[rad]
   */
    double
  m0
  ;
  /**
* Eccentricity of satellite orbit
   */
    double
  ecc
  ;
  /**
* Square root of the semi-major axis of orbit[m^(1/2)]
   */
    double
  sqrta
  ;
  /**
* Longitude of ascending node of orbit plane at weekly epoch[rad]
   */
    double
  omega0
  ;
  /**
* Rate of right ascension[rad/s]
   */
    double
  omegadot
  ;
  /**
* Argument of perigee[rad]
   */
    double
  w
  ;
  /**
* Inclination[rad]
   */
    double
  inc
  ;
  /**
* Polynomial clock correction coefficient (clock bias)[s]
   */
    double
  af0
  ;
  /**
* Polynomial clock correction coefficient (clock drift)[s/s]
   */
    double
  af1
  ;
} sbp_msg_almanac_gps_dep_t;


  /** Satellite broadcast ephemeris for GPS
   *
 * The almanac message returns a set of satellite orbit parameters. Almanac
 * data is not very precise and is considered valid for up to several months.
 * Please see the Navstar GPS Space Segment/Navigation user interfaces
 * (ICD-GPS-200, Chapter 20.3.3.5.1.2 Almanac Data) for more details.
   */
#define SBP_MSG_ALMANAC_GPS              0x0072

	
	
	#define SBP_ALMANAC_GPS_COMMON_SID_CODE__MASK (0xff)
#define SBP_ALMANAC_GPS_COMMON_SID_CODE__SHIFT (0u)
#define SBP_ALMANAC_GPS_COMMON_SID_CODE__GET(flags) \
                             (((flags) >> SBP_ALMANAC_GPS_COMMON_SID_CODE__SHIFT) \
                             & SBP_ALMANAC_GPS_COMMON_SID_CODE__MASK)
#define SBP_ALMANAC_GPS_COMMON_SID_CODE__SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_ALMANAC_GPS_COMMON_SID_CODE__MASK)) \
                             << (SBP_ALMANAC_GPS_COMMON_SID_CODE__SHIFT)));} while(0)
                             

#define SBP_ALMANAC_GPS_COMMON_SID_CODE__GPS_L1CA (0)
#define SBP_ALMANAC_GPS_COMMON_SID_CODE__GPS_L2CM (1)
#define SBP_ALMANAC_GPS_COMMON_SID_CODE__SBAS_L1CA (2)
#define SBP_ALMANAC_GPS_COMMON_SID_CODE__GLO_L1CA (3)
#define SBP_ALMANAC_GPS_COMMON_SID_CODE__GLO_L2CA (4)
#define SBP_ALMANAC_GPS_COMMON_SID_CODE__GPS_L1P (5)
#define SBP_ALMANAC_GPS_COMMON_SID_CODE__GPS_L2P (6)
#define SBP_ALMANAC_GPS_COMMON_SID_CODE__BDS2_B1 (12)
#define SBP_ALMANAC_GPS_COMMON_SID_CODE__BDS2_B2 (13)
#define SBP_ALMANAC_GPS_COMMON_SID_CODE__GAL_E1B (14)
#define SBP_ALMANAC_GPS_COMMON_SID_CODE__GAL_E7I (20)
#define SBP_ALMANAC_GPS_COMMON_SID_CODE__BDS3_B2A (47)
	
typedef struct {
  
  /**
* Values common for all almanac types
   */
  sbp_almanac_common_content_t
  common
  ;
  /**
* Mean anomaly at reference time[rad]
   */
    double
  m0
  ;
  /**
* Eccentricity of satellite orbit
   */
    double
  ecc
  ;
  /**
* Square root of the semi-major axis of orbit[m^(1/2)]
   */
    double
  sqrta
  ;
  /**
* Longitude of ascending node of orbit plane at weekly epoch[rad]
   */
    double
  omega0
  ;
  /**
* Rate of right ascension[rad/s]
   */
    double
  omegadot
  ;
  /**
* Argument of perigee[rad]
   */
    double
  w
  ;
  /**
* Inclination[rad]
   */
    double
  inc
  ;
  /**
* Polynomial clock correction coefficient (clock bias)[s]
   */
    double
  af0
  ;
  /**
* Polynomial clock correction coefficient (clock drift)[s/s]
   */
    double
  af1
  ;
} sbp_msg_almanac_gps_t;


  /** Satellite broadcast ephemeris for GLO
   *
 * The almanac message returns a set of satellite orbit parameters. Almanac
 * data is not very precise and is considered valid for up to several months.
 * Please see the GLO ICD 5.1 "Chapter 4.5 Non-immediate information and
 * almanac" for details.
   */
#define SBP_MSG_ALMANAC_GLO_DEP          0x0071

	
	
	#define SBP_ALMANAC_GLO_DEP_COMMON_SID_CODE__MASK (0xff)
#define SBP_ALMANAC_GLO_DEP_COMMON_SID_CODE__SHIFT (0u)
#define SBP_ALMANAC_GLO_DEP_COMMON_SID_CODE__GET(flags) \
                             (((flags) >> SBP_ALMANAC_GLO_DEP_COMMON_SID_CODE__SHIFT) \
                             & SBP_ALMANAC_GLO_DEP_COMMON_SID_CODE__MASK)
#define SBP_ALMANAC_GLO_DEP_COMMON_SID_CODE__SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_ALMANAC_GLO_DEP_COMMON_SID_CODE__MASK)) \
                             << (SBP_ALMANAC_GLO_DEP_COMMON_SID_CODE__SHIFT)));} while(0)
                             

#define SBP_ALMANAC_GLO_DEP_COMMON_SID_CODE__GPS_L1CA (0)
#define SBP_ALMANAC_GLO_DEP_COMMON_SID_CODE__GPS_L2CM (1)
#define SBP_ALMANAC_GLO_DEP_COMMON_SID_CODE__SBAS_L1CA (2)
#define SBP_ALMANAC_GLO_DEP_COMMON_SID_CODE__GLO_L1CA (3)
#define SBP_ALMANAC_GLO_DEP_COMMON_SID_CODE__GLO_L2CA (4)
#define SBP_ALMANAC_GLO_DEP_COMMON_SID_CODE__GPS_L1P (5)
#define SBP_ALMANAC_GLO_DEP_COMMON_SID_CODE__GPS_L2P (6)
	
typedef struct {
  
  /**
* Values common for all almanac types
   */
  sbp_almanac_common_content_dep_t
  common
  ;
  /**
 * Longitude of the first ascending node of the orbit in PZ-90.02
 * coordinate system[rad]
   */
    double
  lambda_na
  ;
  /**
* Time of the first ascending node passage[s]
   */
    double
  t_lambda_na
  ;
  /**
* Value of inclination at instant of t_lambda[rad]
   */
    double
  i
  ;
  /**
* Value of Draconian period at instant of t_lambda[s/orbital period]
   */
    double
  t
  ;
  /**
* Rate of change of the Draconian period[s/(orbital period^2)]
   */
    double
  t_dot
  ;
  /**
* Eccentricity at instant of t_lambda
   */
    double
  epsilon
  ;
  /**
* Argument of perigee at instant of t_lambda[rad]
   */
    double
  omega
  ;
} sbp_msg_almanac_glo_dep_t;


  /** Satellite broadcast ephemeris for GLO
   *
 * The almanac message returns a set of satellite orbit parameters. Almanac
 * data is not very precise and is considered valid for up to several months.
 * Please see the GLO ICD 5.1 "Chapter 4.5 Non-immediate information and
 * almanac" for details.
   */
#define SBP_MSG_ALMANAC_GLO              0x0073

	
	
	#define SBP_ALMANAC_GLO_COMMON_SID_CODE__MASK (0xff)
#define SBP_ALMANAC_GLO_COMMON_SID_CODE__SHIFT (0u)
#define SBP_ALMANAC_GLO_COMMON_SID_CODE__GET(flags) \
                             (((flags) >> SBP_ALMANAC_GLO_COMMON_SID_CODE__SHIFT) \
                             & SBP_ALMANAC_GLO_COMMON_SID_CODE__MASK)
#define SBP_ALMANAC_GLO_COMMON_SID_CODE__SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_ALMANAC_GLO_COMMON_SID_CODE__MASK)) \
                             << (SBP_ALMANAC_GLO_COMMON_SID_CODE__SHIFT)));} while(0)
                             

#define SBP_ALMANAC_GLO_COMMON_SID_CODE__GPS_L1CA (0)
#define SBP_ALMANAC_GLO_COMMON_SID_CODE__GPS_L2CM (1)
#define SBP_ALMANAC_GLO_COMMON_SID_CODE__SBAS_L1CA (2)
#define SBP_ALMANAC_GLO_COMMON_SID_CODE__GLO_L1CA (3)
#define SBP_ALMANAC_GLO_COMMON_SID_CODE__GLO_L2CA (4)
#define SBP_ALMANAC_GLO_COMMON_SID_CODE__GPS_L1P (5)
#define SBP_ALMANAC_GLO_COMMON_SID_CODE__GPS_L2P (6)
#define SBP_ALMANAC_GLO_COMMON_SID_CODE__BDS2_B1 (12)
#define SBP_ALMANAC_GLO_COMMON_SID_CODE__BDS2_B2 (13)
#define SBP_ALMANAC_GLO_COMMON_SID_CODE__GAL_E1B (14)
#define SBP_ALMANAC_GLO_COMMON_SID_CODE__GAL_E7I (20)
#define SBP_ALMANAC_GLO_COMMON_SID_CODE__BDS3_B2A (47)
	
typedef struct {
  
  /**
* Values common for all almanac types
   */
  sbp_almanac_common_content_t
  common
  ;
  /**
 * Longitude of the first ascending node of the orbit in PZ-90.02
 * coordinate system[rad]
   */
    double
  lambda_na
  ;
  /**
* Time of the first ascending node passage[s]
   */
    double
  t_lambda_na
  ;
  /**
* Value of inclination at instant of t_lambda[rad]
   */
    double
  i
  ;
  /**
* Value of Draconian period at instant of t_lambda[s/orbital period]
   */
    double
  t
  ;
  /**
* Rate of change of the Draconian period[s/(orbital period^2)]
   */
    double
  t_dot
  ;
  /**
* Eccentricity at instant of t_lambda
   */
    double
  epsilon
  ;
  /**
* Argument of perigee at instant of t_lambda[rad]
   */
    double
  omega
  ;
} sbp_msg_almanac_glo_t;


  /** GLONASS L1/L2 Code-Phase biases
   *
 * The GLONASS L1/L2 Code-Phase biases allows to perform
 * GPS+GLONASS integer ambiguity resolution for baselines
 * with mixed receiver types (e.g. receiver of different
 * manufacturers)
   */
#define SBP_MSG_GLO_BIASES               0x0075

typedef struct {
  
  /**
* GLONASS FDMA signals mask[boolean]
   */
    u8
  mask
  ;
  /**
* GLONASS L1 C/A Code-Phase Bias[m * 0.02]
   */
    s16
  l1ca_bias
  ;
  /**
* GLONASS L1 P Code-Phase Bias[m * 0.02]
   */
    s16
  l1p_bias
  ;
  /**
* GLONASS L2 C/A Code-Phase Bias[m * 0.02]
   */
    s16
  l2ca_bias
  ;
  /**
* GLONASS L2 P Code-Phase Bias[m * 0.02]
   */
    s16
  l2p_bias
  ;
} sbp_msg_glo_biases_t;


  /** Satellite azimuth and elevation.
   *
* Satellite azimuth and elevation.
   */

	
	#define SBP_SVAZEL_SID_CODE__MASK (0xff)
#define SBP_SVAZEL_SID_CODE__SHIFT (0u)
#define SBP_SVAZEL_SID_CODE__GET(flags) \
                             (((flags) >> SBP_SVAZEL_SID_CODE__SHIFT) \
                             & SBP_SVAZEL_SID_CODE__MASK)
#define SBP_SVAZEL_SID_CODE__SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_SVAZEL_SID_CODE__MASK)) \
                             << (SBP_SVAZEL_SID_CODE__SHIFT)));} while(0)
                             

#define SBP_SVAZEL_SID_CODE__GPS_L1CA (0)
#define SBP_SVAZEL_SID_CODE__GPS_L2CM (1)
#define SBP_SVAZEL_SID_CODE__SBAS_L1CA (2)
#define SBP_SVAZEL_SID_CODE__GLO_L1CA (3)
#define SBP_SVAZEL_SID_CODE__GLO_L2CA (4)
#define SBP_SVAZEL_SID_CODE__GPS_L1P (5)
#define SBP_SVAZEL_SID_CODE__GPS_L2P (6)
#define SBP_SVAZEL_SID_CODE__BDS2_B1 (12)
#define SBP_SVAZEL_SID_CODE__BDS2_B2 (13)
#define SBP_SVAZEL_SID_CODE__GAL_E1B (14)
#define SBP_SVAZEL_SID_CODE__GAL_E7I (20)
#define SBP_SVAZEL_SID_CODE__BDS3_B2A (47)
typedef struct {
  
  /**
* GNSS signal identifier
   */
  sbp_sbp_gnss_signal_t
  sid
  ;
  /**
* Azimuth angle (range 0..179)[deg * 2]
   */
    u8
  az
  ;
  /**
* Elevation angle (range -90..90)[deg]
   */
    s8
  el
  ;
} sbp_sv_az_el_t;


  /** Satellite azimuths and elevations
   *
 * Azimuth and elevation angles of all the visible satellites
 * that the device does have ephemeris or almanac for.
   */
#define SBP_MSG_SV_AZ_EL                 0x0097

	
	
	#define SBP_SV_AZ_EL_AZEL_SID_CODE__MASK (0xff)
#define SBP_SV_AZ_EL_AZEL_SID_CODE__SHIFT (0u)
#define SBP_SV_AZ_EL_AZEL_SID_CODE__GET(flags) \
                             (((flags) >> SBP_SV_AZ_EL_AZEL_SID_CODE__SHIFT) \
                             & SBP_SV_AZ_EL_AZEL_SID_CODE__MASK)
#define SBP_SV_AZ_EL_AZEL_SID_CODE__SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_SV_AZ_EL_AZEL_SID_CODE__MASK)) \
                             << (SBP_SV_AZ_EL_AZEL_SID_CODE__SHIFT)));} while(0)
                             

#define SBP_SV_AZ_EL_AZEL_SID_CODE__GPS_L1CA (0)
#define SBP_SV_AZ_EL_AZEL_SID_CODE__GPS_L2CM (1)
#define SBP_SV_AZ_EL_AZEL_SID_CODE__SBAS_L1CA (2)
#define SBP_SV_AZ_EL_AZEL_SID_CODE__GLO_L1CA (3)
#define SBP_SV_AZ_EL_AZEL_SID_CODE__GLO_L2CA (4)
#define SBP_SV_AZ_EL_AZEL_SID_CODE__GPS_L1P (5)
#define SBP_SV_AZ_EL_AZEL_SID_CODE__GPS_L2P (6)
#define SBP_SV_AZ_EL_AZEL_SID_CODE__BDS2_B1 (12)
#define SBP_SV_AZ_EL_AZEL_SID_CODE__BDS2_B2 (13)
#define SBP_SV_AZ_EL_AZEL_SID_CODE__GAL_E1B (14)
#define SBP_SV_AZ_EL_AZEL_SID_CODE__GAL_E7I (20)
#define SBP_SV_AZ_EL_AZEL_SID_CODE__BDS3_B2A (47)
typedef struct {
  
  /**
* Azimuth and elevation per satellite
   */
  sbp_sv_az_el_t
  azel
    [63]
  ;
  /**
   * Number of items in azel
   */
  u8 n_azel;
} sbp_msg_sv_az_el_t;


  /** OSR corrections
   *
 * The OSR message contains network corrections in an observation-like format
   */
#define SBP_MSG_OSR                      0x0640

	
	
	
	
	#define SBP_OSR_OBS_FLAGS_INVALID_PHASE_CORRECTIONS_MASK (0x1)
#define SBP_OSR_OBS_FLAGS_INVALID_PHASE_CORRECTIONS_SHIFT (4u)
#define SBP_OSR_OBS_FLAGS_INVALID_PHASE_CORRECTIONS_GET(flags) \
                             (((flags) >> SBP_OSR_OBS_FLAGS_INVALID_PHASE_CORRECTIONS_SHIFT) \
                             & SBP_OSR_OBS_FLAGS_INVALID_PHASE_CORRECTIONS_MASK)
#define SBP_OSR_OBS_FLAGS_INVALID_PHASE_CORRECTIONS_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_OSR_OBS_FLAGS_INVALID_PHASE_CORRECTIONS_MASK)) \
                             << (SBP_OSR_OBS_FLAGS_INVALID_PHASE_CORRECTIONS_SHIFT)));} while(0)
                             

#define SBP_OSR_OBS_FLAGS_INVALID_PHASE_CORRECTIONS_VALID_PHASE_CORRECTIONS (0)
#define SBP_OSR_OBS_FLAGS_INVALID_PHASE_CORRECTIONS_DO_NOT_USE_PHASE_CORRECTIONS (1)
#define SBP_OSR_OBS_FLAGS_INVALID_CODE_CORRECTIONS_MASK (0x1)
#define SBP_OSR_OBS_FLAGS_INVALID_CODE_CORRECTIONS_SHIFT (3u)
#define SBP_OSR_OBS_FLAGS_INVALID_CODE_CORRECTIONS_GET(flags) \
                             (((flags) >> SBP_OSR_OBS_FLAGS_INVALID_CODE_CORRECTIONS_SHIFT) \
                             & SBP_OSR_OBS_FLAGS_INVALID_CODE_CORRECTIONS_MASK)
#define SBP_OSR_OBS_FLAGS_INVALID_CODE_CORRECTIONS_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_OSR_OBS_FLAGS_INVALID_CODE_CORRECTIONS_MASK)) \
                             << (SBP_OSR_OBS_FLAGS_INVALID_CODE_CORRECTIONS_SHIFT)));} while(0)
                             

#define SBP_OSR_OBS_FLAGS_INVALID_CODE_CORRECTIONS_VALID_CODE_CORRECTIONS (0)
#define SBP_OSR_OBS_FLAGS_INVALID_CODE_CORRECTIONS_DO_NOT_USE_CODE_CORRECTIONS (1)
#define SBP_OSR_OBS_FLAGS_FULL_FIXING_FLAG_MASK (0x1)
#define SBP_OSR_OBS_FLAGS_FULL_FIXING_FLAG_SHIFT (2u)
#define SBP_OSR_OBS_FLAGS_FULL_FIXING_FLAG_GET(flags) \
                             (((flags) >> SBP_OSR_OBS_FLAGS_FULL_FIXING_FLAG_SHIFT) \
                             & SBP_OSR_OBS_FLAGS_FULL_FIXING_FLAG_MASK)
#define SBP_OSR_OBS_FLAGS_FULL_FIXING_FLAG_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_OSR_OBS_FLAGS_FULL_FIXING_FLAG_MASK)) \
                             << (SBP_OSR_OBS_FLAGS_FULL_FIXING_FLAG_SHIFT)));} while(0)
                             

#define SBP_OSR_OBS_FLAGS_FULL_FIXING_FLAG_FULL_FIXING_UNAVAILABLE (0)
#define SBP_OSR_OBS_FLAGS_FULL_FIXING_FLAG_FULL_FIXING_AVAILABLE (1)
#define SBP_OSR_OBS_FLAGS_PARTIAL_FIXING_FLAG_MASK (0x1)
#define SBP_OSR_OBS_FLAGS_PARTIAL_FIXING_FLAG_SHIFT (1u)
#define SBP_OSR_OBS_FLAGS_PARTIAL_FIXING_FLAG_GET(flags) \
                             (((flags) >> SBP_OSR_OBS_FLAGS_PARTIAL_FIXING_FLAG_SHIFT) \
                             & SBP_OSR_OBS_FLAGS_PARTIAL_FIXING_FLAG_MASK)
#define SBP_OSR_OBS_FLAGS_PARTIAL_FIXING_FLAG_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_OSR_OBS_FLAGS_PARTIAL_FIXING_FLAG_MASK)) \
                             << (SBP_OSR_OBS_FLAGS_PARTIAL_FIXING_FLAG_SHIFT)));} while(0)
                             

#define SBP_OSR_OBS_FLAGS_PARTIAL_FIXING_FLAG_PARTIAL_FIXING_UNAVAILABLE (0)
#define SBP_OSR_OBS_FLAGS_PARTIAL_FIXING_FLAG_PARTIAL_FIXING_AVAILABLE (1)
#define SBP_OSR_OBS_FLAGS_CORRECTION_VALIDITY_MASK (0x1)
#define SBP_OSR_OBS_FLAGS_CORRECTION_VALIDITY_SHIFT (0u)
#define SBP_OSR_OBS_FLAGS_CORRECTION_VALIDITY_GET(flags) \
                             (((flags) >> SBP_OSR_OBS_FLAGS_CORRECTION_VALIDITY_SHIFT) \
                             & SBP_OSR_OBS_FLAGS_CORRECTION_VALIDITY_MASK)
#define SBP_OSR_OBS_FLAGS_CORRECTION_VALIDITY_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_OSR_OBS_FLAGS_CORRECTION_VALIDITY_MASK)) \
                             << (SBP_OSR_OBS_FLAGS_CORRECTION_VALIDITY_SHIFT)));} while(0)
                             

#define SBP_OSR_OBS_FLAGS_CORRECTION_VALIDITY_DO_NOT_USE_SIGNAL (0)
#define SBP_OSR_OBS_FLAGS_CORRECTION_VALIDITY_VALID_SIGNAL (1)
	
	#define SBP_OSR_OBS_SID_CODE__MASK (0xff)
#define SBP_OSR_OBS_SID_CODE__SHIFT (0u)
#define SBP_OSR_OBS_SID_CODE__GET(flags) \
                             (((flags) >> SBP_OSR_OBS_SID_CODE__SHIFT) \
                             & SBP_OSR_OBS_SID_CODE__MASK)
#define SBP_OSR_OBS_SID_CODE__SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_OSR_OBS_SID_CODE__MASK)) \
                             << (SBP_OSR_OBS_SID_CODE__SHIFT)));} while(0)
                             

#define SBP_OSR_OBS_SID_CODE__GPS_L1CA (0)
#define SBP_OSR_OBS_SID_CODE__GPS_L2CM (1)
#define SBP_OSR_OBS_SID_CODE__SBAS_L1CA (2)
#define SBP_OSR_OBS_SID_CODE__GLO_L1CA (3)
#define SBP_OSR_OBS_SID_CODE__GLO_L2CA (4)
#define SBP_OSR_OBS_SID_CODE__GPS_L1P (5)
#define SBP_OSR_OBS_SID_CODE__GPS_L2P (6)
#define SBP_OSR_OBS_SID_CODE__BDS2_B1 (12)
#define SBP_OSR_OBS_SID_CODE__BDS2_B2 (13)
#define SBP_OSR_OBS_SID_CODE__GAL_E1B (14)
#define SBP_OSR_OBS_SID_CODE__GAL_E7I (20)
#define SBP_OSR_OBS_SID_CODE__BDS3_B2A (47)
typedef struct {
  
  /**
* Header of a GPS observation message
   */
  sbp_observation_header_t
  header
  ;
  /**
 * Network correction for a
 * satellite signal.
   */
  sbp_packed_osr_content_t
  obs
    [12]
  ;
  /**
   * Number of items in obs
   */
  u8 n_obs;
} sbp_msg_osr_t;



#include <libsbp/unpacked/observation_operators.h>
#include <libsbp/unpacked/observation_packers.h>

#endif /* LIBSBP_OBSERVATION_MESSAGES_H */
