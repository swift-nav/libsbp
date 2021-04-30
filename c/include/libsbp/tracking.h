#ifndef LIBSBP_TRACKING_MESSAGES_H
#define LIBSBP_TRACKING_MESSAGES_H

#include <endian.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>

#include <libsbp/common.h>
#include <libsbp/gnss.h>
/** Detailed signal tracking channel states. DEPRECATED.
 *
 * The tracking message returns a set tracking channel parameters for a
 * single tracking channel useful for debugging issues.
 */
#define SBP_MSG_TRACKING_STATE_DETAILED_DEP_A 0x0021

#define SBP_TRACKING_STATE_DETAILED_DEP_A_SID_CODE__MASK (0xff)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_SID_CODE__SHIFT (0u)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_SID_CODE__GET(flags) \
  (((flags) >> SBP_TRACKING_STATE_DETAILED_DEP_A_SID_CODE__SHIFT) & SBP_TRACKING_STATE_DETAILED_DEP_A_SID_CODE__MASK)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_SID_CODE__SET(flags, val) \
  do \
  { \
    ((flags) |= (((val) & (SBP_TRACKING_STATE_DETAILED_DEP_A_SID_CODE__MASK)) \
                 << (SBP_TRACKING_STATE_DETAILED_DEP_A_SID_CODE__SHIFT))); \
  } while (0)

#define SBP_TRACKING_STATE_DETAILED_DEP_A_SID_CODE__GPS_L1CA (0)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_SID_CODE__GPS_L2CM (1)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_SID_CODE__SBAS_L1CA (2)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_SID_CODE__GLO_L1CA (3)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_SID_CODE__GLO_L2CA (4)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_SID_CODE__GPS_L1P (5)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_SID_CODE__GPS_L2P (6)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_SID_CODE__BDS2_B1 (12)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_SID_CODE__BDS2_B2 (13)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_SID_CODE__GAL_E1B (14)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_SID_CODE__GAL_E7I (20)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_SID_CODE__BDS3_B2A (47)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_SYNC_FLAGS_SYNCHRONIZATION_STATUS_MASK (0x7)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_SYNC_FLAGS_SYNCHRONIZATION_STATUS_SHIFT (0u)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_SYNC_FLAGS_SYNCHRONIZATION_STATUS_GET(flags) \
  (((flags) >> SBP_TRACKING_STATE_DETAILED_DEP_A_SYNC_FLAGS_SYNCHRONIZATION_STATUS_SHIFT) & \
   SBP_TRACKING_STATE_DETAILED_DEP_A_SYNC_FLAGS_SYNCHRONIZATION_STATUS_MASK)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_SYNC_FLAGS_SYNCHRONIZATION_STATUS_SET(flags, val) \
  do \
  { \
    ((flags) |= (((val) & (SBP_TRACKING_STATE_DETAILED_DEP_A_SYNC_FLAGS_SYNCHRONIZATION_STATUS_MASK)) \
                 << (SBP_TRACKING_STATE_DETAILED_DEP_A_SYNC_FLAGS_SYNCHRONIZATION_STATUS_SHIFT))); \
  } while (0)

#define SBP_TRACKING_STATE_DETAILED_DEP_A_SYNC_FLAGS_SYNCHRONIZATION_STATUS_NO_SYNCHRONIZATION (0)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_SYNC_FLAGS_SYNCHRONIZATION_STATUS_BIT_SYNCHRONIZATION (1)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_SYNC_FLAGS_SYNCHRONIZATION_STATUS_WORD_SYNCHRONIZATION (2)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_SYNC_FLAGS_SYNCHRONIZATION_STATUS_SUB_FRAME_SYNCHRONIZATION_MESSAGE_SYNCHRONIZATION \
  (3)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_TOW_FLAGS_WEEK_NUMBER_VALIDITY_STATUS_MASK (0x1)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_TOW_FLAGS_WEEK_NUMBER_VALIDITY_STATUS_SHIFT (3u)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_TOW_FLAGS_WEEK_NUMBER_VALIDITY_STATUS_GET(flags) \
  (((flags) >> SBP_TRACKING_STATE_DETAILED_DEP_A_TOW_FLAGS_WEEK_NUMBER_VALIDITY_STATUS_SHIFT) & \
   SBP_TRACKING_STATE_DETAILED_DEP_A_TOW_FLAGS_WEEK_NUMBER_VALIDITY_STATUS_MASK)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_TOW_FLAGS_WEEK_NUMBER_VALIDITY_STATUS_SET(flags, val) \
  do \
  { \
    ((flags) |= (((val) & (SBP_TRACKING_STATE_DETAILED_DEP_A_TOW_FLAGS_WEEK_NUMBER_VALIDITY_STATUS_MASK)) \
                 << (SBP_TRACKING_STATE_DETAILED_DEP_A_TOW_FLAGS_WEEK_NUMBER_VALIDITY_STATUS_SHIFT))); \
  } while (0)

#define SBP_TRACKING_STATE_DETAILED_DEP_A_TOW_FLAGS_WEEK_NUMBER_VALIDITY_STATUS_WEEK_NUMBER_IS_NOT_VALID (0)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_TOW_FLAGS_WEEK_NUMBER_VALIDITY_STATUS_WEEK_NUMBER_IS_VALID (1)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_TOW_FLAGS_TOW_STATUS_MASK (0x7)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_TOW_FLAGS_TOW_STATUS_SHIFT (0u)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_TOW_FLAGS_TOW_STATUS_GET(flags) \
  (((flags) >> SBP_TRACKING_STATE_DETAILED_DEP_A_TOW_FLAGS_TOW_STATUS_SHIFT) & \
   SBP_TRACKING_STATE_DETAILED_DEP_A_TOW_FLAGS_TOW_STATUS_MASK)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_TOW_FLAGS_TOW_STATUS_SET(flags, val) \
  do \
  { \
    ((flags) |= (((val) & (SBP_TRACKING_STATE_DETAILED_DEP_A_TOW_FLAGS_TOW_STATUS_MASK)) \
                 << (SBP_TRACKING_STATE_DETAILED_DEP_A_TOW_FLAGS_TOW_STATUS_SHIFT))); \
  } while (0)

#define SBP_TRACKING_STATE_DETAILED_DEP_A_TOW_FLAGS_TOW_STATUS_TOW_IS_NOT_AVAILABLE (0)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_TOW_FLAGS_TOW_STATUS_DECODED_TOW_IS_AVAILABLE (1)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_TOW_FLAGS_TOW_STATUS_PROPAGATED_TOW_IS_AVAILABLE (2)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_TRACK_FLAGS_FLL_STATUS_MASK (0x1)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_TRACK_FLAGS_FLL_STATUS_SHIFT (4u)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_TRACK_FLAGS_FLL_STATUS_GET(flags) \
  (((flags) >> SBP_TRACKING_STATE_DETAILED_DEP_A_TRACK_FLAGS_FLL_STATUS_SHIFT) & \
   SBP_TRACKING_STATE_DETAILED_DEP_A_TRACK_FLAGS_FLL_STATUS_MASK)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_TRACK_FLAGS_FLL_STATUS_SET(flags, val) \
  do \
  { \
    ((flags) |= (((val) & (SBP_TRACKING_STATE_DETAILED_DEP_A_TRACK_FLAGS_FLL_STATUS_MASK)) \
                 << (SBP_TRACKING_STATE_DETAILED_DEP_A_TRACK_FLAGS_FLL_STATUS_SHIFT))); \
  } while (0)

#define SBP_TRACKING_STATE_DETAILED_DEP_A_TRACK_FLAGS_FLL_STATUS_FLL_IS_INACTIVE (0)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_TRACK_FLAGS_FLL_STATUS_FLL_IS_ACTIVE (1)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_TRACK_FLAGS_PLL_STATUS_MASK (0x1)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_TRACK_FLAGS_PLL_STATUS_SHIFT (3u)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_TRACK_FLAGS_PLL_STATUS_GET(flags) \
  (((flags) >> SBP_TRACKING_STATE_DETAILED_DEP_A_TRACK_FLAGS_PLL_STATUS_SHIFT) & \
   SBP_TRACKING_STATE_DETAILED_DEP_A_TRACK_FLAGS_PLL_STATUS_MASK)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_TRACK_FLAGS_PLL_STATUS_SET(flags, val) \
  do \
  { \
    ((flags) |= (((val) & (SBP_TRACKING_STATE_DETAILED_DEP_A_TRACK_FLAGS_PLL_STATUS_MASK)) \
                 << (SBP_TRACKING_STATE_DETAILED_DEP_A_TRACK_FLAGS_PLL_STATUS_SHIFT))); \
  } while (0)

#define SBP_TRACKING_STATE_DETAILED_DEP_A_TRACK_FLAGS_PLL_STATUS_PLL_IS_INACTIVE (0)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_TRACK_FLAGS_PLL_STATUS_PLL_IS_ACTIVE (1)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_TRACK_FLAGS_TRACKING_LOOP_STATUS_MASK (0x7)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_TRACK_FLAGS_TRACKING_LOOP_STATUS_SHIFT (0u)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_TRACK_FLAGS_TRACKING_LOOP_STATUS_GET(flags) \
  (((flags) >> SBP_TRACKING_STATE_DETAILED_DEP_A_TRACK_FLAGS_TRACKING_LOOP_STATUS_SHIFT) & \
   SBP_TRACKING_STATE_DETAILED_DEP_A_TRACK_FLAGS_TRACKING_LOOP_STATUS_MASK)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_TRACK_FLAGS_TRACKING_LOOP_STATUS_SET(flags, val) \
  do \
  { \
    ((flags) |= (((val) & (SBP_TRACKING_STATE_DETAILED_DEP_A_TRACK_FLAGS_TRACKING_LOOP_STATUS_MASK)) \
                 << (SBP_TRACKING_STATE_DETAILED_DEP_A_TRACK_FLAGS_TRACKING_LOOP_STATUS_SHIFT))); \
  } while (0)

#define SBP_TRACKING_STATE_DETAILED_DEP_A_TRACK_FLAGS_TRACKING_LOOP_STATUS_NO_LOCKS (0)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_TRACK_FLAGS_TRACKING_LOOP_STATUS_FLLDLL_LOCK (1)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_TRACK_FLAGS_TRACKING_LOOP_STATUS_PLL_OPTIMISTIC_LOCK (2)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_TRACK_FLAGS_TRACKING_LOOP_STATUS_PLL_PESSIMISTIC_LOCK (3)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_NAV_FLAGS_ALMANAC_AVAILABILITY_STATUS_MASK (0x1)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_NAV_FLAGS_ALMANAC_AVAILABILITY_STATUS_SHIFT (4u)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_NAV_FLAGS_ALMANAC_AVAILABILITY_STATUS_GET(flags) \
  (((flags) >> SBP_TRACKING_STATE_DETAILED_DEP_A_NAV_FLAGS_ALMANAC_AVAILABILITY_STATUS_SHIFT) & \
   SBP_TRACKING_STATE_DETAILED_DEP_A_NAV_FLAGS_ALMANAC_AVAILABILITY_STATUS_MASK)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_NAV_FLAGS_ALMANAC_AVAILABILITY_STATUS_SET(flags, val) \
  do \
  { \
    ((flags) |= (((val) & (SBP_TRACKING_STATE_DETAILED_DEP_A_NAV_FLAGS_ALMANAC_AVAILABILITY_STATUS_MASK)) \
                 << (SBP_TRACKING_STATE_DETAILED_DEP_A_NAV_FLAGS_ALMANAC_AVAILABILITY_STATUS_SHIFT))); \
  } while (0)

#define SBP_TRACKING_STATE_DETAILED_DEP_A_NAV_FLAGS_ALMANAC_AVAILABILITY_STATUS_ALMANAC_IS_NOT_AVAILABLE (0)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_NAV_FLAGS_ALMANAC_AVAILABILITY_STATUS_ALMANAC_IS_AVAILABLE (1)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_NAV_FLAGS_EPHEMERIS_AVAILABILITY_STATUS_MASK (0x1)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_NAV_FLAGS_EPHEMERIS_AVAILABILITY_STATUS_SHIFT (3u)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_NAV_FLAGS_EPHEMERIS_AVAILABILITY_STATUS_GET(flags) \
  (((flags) >> SBP_TRACKING_STATE_DETAILED_DEP_A_NAV_FLAGS_EPHEMERIS_AVAILABILITY_STATUS_SHIFT) & \
   SBP_TRACKING_STATE_DETAILED_DEP_A_NAV_FLAGS_EPHEMERIS_AVAILABILITY_STATUS_MASK)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_NAV_FLAGS_EPHEMERIS_AVAILABILITY_STATUS_SET(flags, val) \
  do \
  { \
    ((flags) |= (((val) & (SBP_TRACKING_STATE_DETAILED_DEP_A_NAV_FLAGS_EPHEMERIS_AVAILABILITY_STATUS_MASK)) \
                 << (SBP_TRACKING_STATE_DETAILED_DEP_A_NAV_FLAGS_EPHEMERIS_AVAILABILITY_STATUS_SHIFT))); \
  } while (0)

#define SBP_TRACKING_STATE_DETAILED_DEP_A_NAV_FLAGS_EPHEMERIS_AVAILABILITY_STATUS_EPHEMERIS_IS_NOT_AVAILABLE (0)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_NAV_FLAGS_EPHEMERIS_AVAILABILITY_STATUS_EPHEMERIS_IS_AVAILABLE (1)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_NAV_FLAGS_HEALTH_STATUS_MASK (0x7)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_NAV_FLAGS_HEALTH_STATUS_SHIFT (0u)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_NAV_FLAGS_HEALTH_STATUS_GET(flags) \
  (((flags) >> SBP_TRACKING_STATE_DETAILED_DEP_A_NAV_FLAGS_HEALTH_STATUS_SHIFT) & \
   SBP_TRACKING_STATE_DETAILED_DEP_A_NAV_FLAGS_HEALTH_STATUS_MASK)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_NAV_FLAGS_HEALTH_STATUS_SET(flags, val) \
  do \
  { \
    ((flags) |= (((val) & (SBP_TRACKING_STATE_DETAILED_DEP_A_NAV_FLAGS_HEALTH_STATUS_MASK)) \
                 << (SBP_TRACKING_STATE_DETAILED_DEP_A_NAV_FLAGS_HEALTH_STATUS_SHIFT))); \
  } while (0)

#define SBP_TRACKING_STATE_DETAILED_DEP_A_NAV_FLAGS_HEALTH_STATUS_HEALTH_IS_UNKNOWN (0)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_NAV_FLAGS_HEALTH_STATUS_SIGNAL_IS_UNHEALTHY (1)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_NAV_FLAGS_HEALTH_STATUS_SIGNAL_IS_HEALTHY (2)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_PSET_FLAGS_PARAMETER_SETS_MASK (0x7)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_PSET_FLAGS_PARAMETER_SETS_SHIFT (0u)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_PSET_FLAGS_PARAMETER_SETS_GET(flags) \
  (((flags) >> SBP_TRACKING_STATE_DETAILED_DEP_A_PSET_FLAGS_PARAMETER_SETS_SHIFT) & \
   SBP_TRACKING_STATE_DETAILED_DEP_A_PSET_FLAGS_PARAMETER_SETS_MASK)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_PSET_FLAGS_PARAMETER_SETS_SET(flags, val) \
  do \
  { \
    ((flags) |= (((val) & (SBP_TRACKING_STATE_DETAILED_DEP_A_PSET_FLAGS_PARAMETER_SETS_MASK)) \
                 << (SBP_TRACKING_STATE_DETAILED_DEP_A_PSET_FLAGS_PARAMETER_SETS_SHIFT))); \
  } while (0)

#define SBP_TRACKING_STATE_DETAILED_DEP_A_PSET_FLAGS_PARAMETER_SETS_1_MS_INTEGRATION_TIME (0)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_PSET_FLAGS_PARAMETER_SETS_5_MS_INTEGRATION_TIME (1)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_PSET_FLAGS_PARAMETER_SETS_10_MS_INTEGRATION_TIME (2)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_PSET_FLAGS_PARAMETER_SETS_20_MS_INTEGRATION_TIME (3)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_MISC_FLAGS_CLOCK_VALIDITY_STATUS_MASK (0x1)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_MISC_FLAGS_CLOCK_VALIDITY_STATUS_SHIFT (5u)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_MISC_FLAGS_CLOCK_VALIDITY_STATUS_GET(flags) \
  (((flags) >> SBP_TRACKING_STATE_DETAILED_DEP_A_MISC_FLAGS_CLOCK_VALIDITY_STATUS_SHIFT) & \
   SBP_TRACKING_STATE_DETAILED_DEP_A_MISC_FLAGS_CLOCK_VALIDITY_STATUS_MASK)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_MISC_FLAGS_CLOCK_VALIDITY_STATUS_SET(flags, val) \
  do \
  { \
    ((flags) |= (((val) & (SBP_TRACKING_STATE_DETAILED_DEP_A_MISC_FLAGS_CLOCK_VALIDITY_STATUS_MASK)) \
                 << (SBP_TRACKING_STATE_DETAILED_DEP_A_MISC_FLAGS_CLOCK_VALIDITY_STATUS_SHIFT))); \
  } while (0)

#define SBP_TRACKING_STATE_DETAILED_DEP_A_MISC_FLAGS_CLOCK_VALIDITY_STATUS_CLOCK_OFFSET_AND_DRIFT_IS_NOT_VALID (0)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_MISC_FLAGS_CLOCK_VALIDITY_STATUS_CLOCK_OFFSET_AND_DRIFT_IS_VALID (1)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_MISC_FLAGS_PSEUDORANGE_VALIDITY_STATUS_MASK (0x1)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_MISC_FLAGS_PSEUDORANGE_VALIDITY_STATUS_SHIFT (4u)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_MISC_FLAGS_PSEUDORANGE_VALIDITY_STATUS_GET(flags) \
  (((flags) >> SBP_TRACKING_STATE_DETAILED_DEP_A_MISC_FLAGS_PSEUDORANGE_VALIDITY_STATUS_SHIFT) & \
   SBP_TRACKING_STATE_DETAILED_DEP_A_MISC_FLAGS_PSEUDORANGE_VALIDITY_STATUS_MASK)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_MISC_FLAGS_PSEUDORANGE_VALIDITY_STATUS_SET(flags, val) \
  do \
  { \
    ((flags) |= (((val) & (SBP_TRACKING_STATE_DETAILED_DEP_A_MISC_FLAGS_PSEUDORANGE_VALIDITY_STATUS_MASK)) \
                 << (SBP_TRACKING_STATE_DETAILED_DEP_A_MISC_FLAGS_PSEUDORANGE_VALIDITY_STATUS_SHIFT))); \
  } while (0)

#define SBP_TRACKING_STATE_DETAILED_DEP_A_MISC_FLAGS_PSEUDORANGE_VALIDITY_STATUS_PSEUDORANGE_IS_NOT_VALID (0)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_MISC_FLAGS_PSEUDORANGE_VALIDITY_STATUS_PSEUDORANGE_IS_VALID (1)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_MISC_FLAGS_ACCELERATION_VALIDITY_STATUS_MASK (0x1)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_MISC_FLAGS_ACCELERATION_VALIDITY_STATUS_SHIFT (3u)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_MISC_FLAGS_ACCELERATION_VALIDITY_STATUS_GET(flags) \
  (((flags) >> SBP_TRACKING_STATE_DETAILED_DEP_A_MISC_FLAGS_ACCELERATION_VALIDITY_STATUS_SHIFT) & \
   SBP_TRACKING_STATE_DETAILED_DEP_A_MISC_FLAGS_ACCELERATION_VALIDITY_STATUS_MASK)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_MISC_FLAGS_ACCELERATION_VALIDITY_STATUS_SET(flags, val) \
  do \
  { \
    ((flags) |= (((val) & (SBP_TRACKING_STATE_DETAILED_DEP_A_MISC_FLAGS_ACCELERATION_VALIDITY_STATUS_MASK)) \
                 << (SBP_TRACKING_STATE_DETAILED_DEP_A_MISC_FLAGS_ACCELERATION_VALIDITY_STATUS_SHIFT))); \
  } while (0)

#define SBP_TRACKING_STATE_DETAILED_DEP_A_MISC_FLAGS_ACCELERATION_VALIDITY_STATUS_ACCELERATION_IS_NOT_VALID (0)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_MISC_FLAGS_ACCELERATION_VALIDITY_STATUS_ACCELERATION_IS_VALID (1)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_MISC_FLAGS_CARRIER_HALF_CYCLE_AMBIGUITY_STATUS_MASK (0x1)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_MISC_FLAGS_CARRIER_HALF_CYCLE_AMBIGUITY_STATUS_SHIFT (2u)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_MISC_FLAGS_CARRIER_HALF_CYCLE_AMBIGUITY_STATUS_GET(flags) \
  (((flags) >> SBP_TRACKING_STATE_DETAILED_DEP_A_MISC_FLAGS_CARRIER_HALF_CYCLE_AMBIGUITY_STATUS_SHIFT) & \
   SBP_TRACKING_STATE_DETAILED_DEP_A_MISC_FLAGS_CARRIER_HALF_CYCLE_AMBIGUITY_STATUS_MASK)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_MISC_FLAGS_CARRIER_HALF_CYCLE_AMBIGUITY_STATUS_SET(flags, val) \
  do \
  { \
    ((flags) |= (((val) & (SBP_TRACKING_STATE_DETAILED_DEP_A_MISC_FLAGS_CARRIER_HALF_CYCLE_AMBIGUITY_STATUS_MASK)) \
                 << (SBP_TRACKING_STATE_DETAILED_DEP_A_MISC_FLAGS_CARRIER_HALF_CYCLE_AMBIGUITY_STATUS_SHIFT))); \
  } while (0)

#define SBP_TRACKING_STATE_DETAILED_DEP_A_MISC_FLAGS_CARRIER_HALF_CYCLE_AMBIGUITY_STATUS_UNRESOLVED (0)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_MISC_FLAGS_CARRIER_HALF_CYCLE_AMBIGUITY_STATUS_RESOLVED (1)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_MISC_FLAGS_TRACKING_CHANNEL_STATUS_MASK (0x3)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_MISC_FLAGS_TRACKING_CHANNEL_STATUS_SHIFT (0u)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_MISC_FLAGS_TRACKING_CHANNEL_STATUS_GET(flags) \
  (((flags) >> SBP_TRACKING_STATE_DETAILED_DEP_A_MISC_FLAGS_TRACKING_CHANNEL_STATUS_SHIFT) & \
   SBP_TRACKING_STATE_DETAILED_DEP_A_MISC_FLAGS_TRACKING_CHANNEL_STATUS_MASK)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_MISC_FLAGS_TRACKING_CHANNEL_STATUS_SET(flags, val) \
  do \
  { \
    ((flags) |= (((val) & (SBP_TRACKING_STATE_DETAILED_DEP_A_MISC_FLAGS_TRACKING_CHANNEL_STATUS_MASK)) \
                 << (SBP_TRACKING_STATE_DETAILED_DEP_A_MISC_FLAGS_TRACKING_CHANNEL_STATUS_SHIFT))); \
  } while (0)

#define SBP_TRACKING_STATE_DETAILED_DEP_A_MISC_FLAGS_TRACKING_CHANNEL_STATUS_RE_ACQUISITION (0)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_MISC_FLAGS_TRACKING_CHANNEL_STATUS_RUNNING (1)
typedef struct
{

  /**
   * Receiver clock time.[ns]
   */
  u64 recv_time;
  /**
   * Time of transmission of signal from satellite. TOW only valid when
   * TOW status is decoded or propagated. WN only valid when week
   * number valid flag is set.
   */
  struct
  {

    /**
     * Milliseconds since start of GPS week[ms]
     */
    u32 tow;
    /**
     * Nanosecond residual of millisecond-rounded TOW (ranges
     * from -500000 to 500000)[ns]
     */
    s32 ns_residual;
    /**
     * GPS week number[week]
     */
    u16 wn;
  } tot;
  /**
   * Pseudorange observation. Valid only when pseudorange valid flag is
   * set.[2 cm]
   */
  u32 P;
  /**
   * Pseudorange observation standard deviation. Valid only when
   * pseudorange valid flag is set.[2 cm]
   */
  u16 P_std;
  /**
   * Carrier phase observation with typical sign convention. Valid only
   * when PLL pessimistic lock is achieved.[cycles]
   */
  struct
  {

    /**
     * Carrier phase whole cycles[cycles]
     */
    s32 i;
    /**
     * Carrier phase fractional part[cycles / 256]
     */
    u8 f;
  } L;
  /**
   * Carrier-to-Noise density[dB Hz / 4]
   */
  u8 cn0;
  /**
   * Lock time. It is encoded according to DF402 from the RTCM 10403.2
   * Amendment 2 specification. Valid values range from 0 to 15.
   */
  u16 lock;
  /**
   * GNSS signal identifier.
   */
  struct
  {

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
  } sid;
  /**
   * Carrier Doppler frequency.[Hz / 16]
   */
  s32 doppler;
  /**
   * Carrier Doppler frequency standard deviation.[Hz / 16]
   */
  u16 doppler_std;
  /**
   * Number of seconds of continuous tracking. Specifies how much time
   * signal is in continuous track.[s]
   */
  u32 uptime;
  /**
   * TCXO clock offset. Valid only when valid clock valid flag is set.[s / (2 ^ 20)]
   */
  s16 clock_offset;
  /**
   * TCXO clock drift. Valid only when valid clock valid flag is set.[(s / s) / (2 ^ 31)]
   */
  s16 clock_drift;
  /**
   * Early-Prompt (EP) and Prompt-Late (PL) correlators spacing.[ns]
   */
  u16 corr_spacing;
  /**
   * Acceleration. Valid only when acceleration valid flag is set.[g / 8]
   */
  s8 acceleration;
  /**
   * Synchronization status flags.
   */
  u8 sync_flags;
  /**
   * TOW status flags.
   */
  u8 tow_flags;
  /**
   * Tracking loop status flags.
   */
  u8 track_flags;
  /**
   * Navigation data status flags.
   */
  u8 nav_flags;
  /**
   * Parameters sets flags.
   */
  u8 pset_flags;
  /**
   * Miscellaneous flags.
   */
  u8 misc_flags;
} sbp_msg_tracking_state_detailed_dep_a_t;

static inline size_t
sbp_packed_size_sbp_msg_tracking_state_detailed_dep_a_t(const sbp_msg_tracking_state_detailed_dep_a_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->recv_time) + (0 + sizeof(msg->tot.tow) + sizeof(msg->tot.ns_residual) + sizeof(msg->tot.wn)) +
         sizeof(msg->P) + sizeof(msg->P_std) + (0 + sizeof(msg->L.i) + sizeof(msg->L.f)) + sizeof(msg->cn0) +
         sizeof(msg->lock) + (0 + sizeof(msg->sid.sat) + sizeof(msg->sid.code)) + sizeof(msg->doppler) +
         sizeof(msg->doppler_std) + sizeof(msg->uptime) + sizeof(msg->clock_offset) + sizeof(msg->clock_drift) +
         sizeof(msg->corr_spacing) + sizeof(msg->acceleration) + sizeof(msg->sync_flags) + sizeof(msg->tow_flags) +
         sizeof(msg->track_flags) + sizeof(msg->nav_flags) + sizeof(msg->pset_flags) + sizeof(msg->misc_flags);
}

static inline bool sbp_pack_sbp_msg_tracking_state_detailed_dep_a_t(u8 *buf,
                                                                    size_t len,
                                                                    const sbp_msg_tracking_state_detailed_dep_a_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_tracking_state_detailed_dep_a_t(msg) > len)
  {
    return false;
  }

  if (offset + 8 > len)
  {
    return false;
  }
  u64 msgrecv_time = htole64(msg->recv_time);
  memcpy(buf + offset, &msgrecv_time, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgtottow = htole32(msg->tot.tow);
  memcpy(buf + offset, &msgtottow, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgtotns_residual = htole32(*(const u32 *)&msg->tot.ns_residual);
  memcpy(buf + offset, &msgtotns_residual, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgtotwn = htole16(msg->tot.wn);
  memcpy(buf + offset, &msgtotwn, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgP = htole32(msg->P);
  memcpy(buf + offset, &msgP, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgP_std = htole16(msg->P_std);
  memcpy(buf + offset, &msgP_std, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgLi = htole32(*(const u32 *)&msg->L.i);
  memcpy(buf + offset, &msgLi, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgLf = msg->L.f;
  memcpy(buf + offset, &msgLf, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgcn0 = msg->cn0;
  memcpy(buf + offset, &msgcn0, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msglock = htole16(msg->lock);
  memcpy(buf + offset, &msglock, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgsidsat = msg->sid.sat;
  memcpy(buf + offset, &msgsidsat, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgsidcode = msg->sid.code;
  memcpy(buf + offset, &msgsidcode, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgdoppler = htole32(*(const u32 *)&msg->doppler);
  memcpy(buf + offset, &msgdoppler, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgdoppler_std = htole16(msg->doppler_std);
  memcpy(buf + offset, &msgdoppler_std, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msguptime = htole32(msg->uptime);
  memcpy(buf + offset, &msguptime, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgclock_offset = htole16(*(const u16 *)&msg->clock_offset);
  memcpy(buf + offset, &msgclock_offset, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgclock_drift = htole16(*(const u16 *)&msg->clock_drift);
  memcpy(buf + offset, &msgclock_drift, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgcorr_spacing = htole16(msg->corr_spacing);
  memcpy(buf + offset, &msgcorr_spacing, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  s8 msgacceleration = msg->acceleration;
  memcpy(buf + offset, &msgacceleration, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgsync_flags = msg->sync_flags;
  memcpy(buf + offset, &msgsync_flags, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgtow_flags = msg->tow_flags;
  memcpy(buf + offset, &msgtow_flags, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgtrack_flags = msg->track_flags;
  memcpy(buf + offset, &msgtrack_flags, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgnav_flags = msg->nav_flags;
  memcpy(buf + offset, &msgnav_flags, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgpset_flags = msg->pset_flags;
  memcpy(buf + offset, &msgpset_flags, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgmisc_flags = msg->misc_flags;
  memcpy(buf + offset, &msgmisc_flags, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline bool sbp_unpack_sbp_msg_tracking_state_detailed_dep_a_t(const u8 *buf,
                                                                      size_t len,
                                                                      sbp_msg_tracking_state_detailed_dep_a_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->recv_time, buf + offset, 8);
  msg->recv_time = le64toh(msg->recv_time);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->tot.tow, buf + offset, 4);
  msg->tot.tow = le32toh(msg->tot.tow);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->tot.ns_residual, buf + offset, 4);
  u32 msgtotns_residual = *(const u32 *)&msg->tot.ns_residual;
  msgtotns_residual = le32toh(msgtotns_residual);
  msg->tot.ns_residual = *(const s32 *)&msgtotns_residual;
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->tot.wn, buf + offset, 2);
  msg->tot.wn = le16toh(msg->tot.wn);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->P, buf + offset, 4);
  msg->P = le32toh(msg->P);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->P_std, buf + offset, 2);
  msg->P_std = le16toh(msg->P_std);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->L.i, buf + offset, 4);
  u32 msgLi = *(const u32 *)&msg->L.i;
  msgLi = le32toh(msgLi);
  msg->L.i = *(const s32 *)&msgLi;
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->L.f, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->cn0, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->lock, buf + offset, 2);
  msg->lock = le16toh(msg->lock);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->sid.sat, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->sid.code, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->doppler, buf + offset, 4);
  u32 msgdoppler = *(const u32 *)&msg->doppler;
  msgdoppler = le32toh(msgdoppler);
  msg->doppler = *(const s32 *)&msgdoppler;
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->doppler_std, buf + offset, 2);
  msg->doppler_std = le16toh(msg->doppler_std);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->uptime, buf + offset, 4);
  msg->uptime = le32toh(msg->uptime);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->clock_offset, buf + offset, 2);
  u16 msgclock_offset = *(const u16 *)&msg->clock_offset;
  msgclock_offset = le16toh(msgclock_offset);
  msg->clock_offset = *(const s16 *)&msgclock_offset;
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->clock_drift, buf + offset, 2);
  u16 msgclock_drift = *(const u16 *)&msg->clock_drift;
  msgclock_drift = le16toh(msgclock_drift);
  msg->clock_drift = *(const s16 *)&msgclock_drift;
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->corr_spacing, buf + offset, 2);
  msg->corr_spacing = le16toh(msg->corr_spacing);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->acceleration, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->sync_flags, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->tow_flags, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->track_flags, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->nav_flags, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->pset_flags, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->misc_flags, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_tracking_state_detailed_dep_a_t &a,
                              const sbp_msg_tracking_state_detailed_dep_a_t &b)
{
  (void)a;
  (void)b;

  if (a.recv_time != b.recv_time)
  {
    return false;
  }

  if (a.tot.tow != b.tot.tow)
  {
    return false;
  }

  if (a.tot.ns_residual != b.tot.ns_residual)
  {
    return false;
  }

  if (a.tot.wn != b.tot.wn)
  {
    return false;
  }

  if (a.P != b.P)
  {
    return false;
  }

  if (a.P_std != b.P_std)
  {
    return false;
  }

  if (a.L.i != b.L.i)
  {
    return false;
  }

  if (a.L.f != b.L.f)
  {
    return false;
  }

  if (a.cn0 != b.cn0)
  {
    return false;
  }

  if (a.lock != b.lock)
  {
    return false;
  }

  if (a.sid.sat != b.sid.sat)
  {
    return false;
  }

  if (a.sid.code != b.sid.code)
  {
    return false;
  }

  if (a.doppler != b.doppler)
  {
    return false;
  }

  if (a.doppler_std != b.doppler_std)
  {
    return false;
  }

  if (a.uptime != b.uptime)
  {
    return false;
  }

  if (a.clock_offset != b.clock_offset)
  {
    return false;
  }

  if (a.clock_drift != b.clock_drift)
  {
    return false;
  }

  if (a.corr_spacing != b.corr_spacing)
  {
    return false;
  }

  if (a.acceleration != b.acceleration)
  {
    return false;
  }

  if (a.sync_flags != b.sync_flags)
  {
    return false;
  }

  if (a.tow_flags != b.tow_flags)
  {
    return false;
  }

  if (a.track_flags != b.track_flags)
  {
    return false;
  }

  if (a.nav_flags != b.nav_flags)
  {
    return false;
  }

  if (a.pset_flags != b.pset_flags)
  {
    return false;
  }

  if (a.misc_flags != b.misc_flags)
  {
    return false;
  }

  return true;
}

static inline bool operator!=(const sbp_msg_tracking_state_detailed_dep_a_t &a,
                              const sbp_msg_tracking_state_detailed_dep_a_t &b)
{
  return !(a == b);
}
#endif
/** Deprecated
 *
 * Deprecated.
 */
#define SBP_MSG_TRACKING_STATE_DETAILED_DEP 0x0011

#define SBP_TRACKING_STATE_DETAILED_DEP_SID_CODE__MASK (0xff)
#define SBP_TRACKING_STATE_DETAILED_DEP_SID_CODE__SHIFT (0u)
#define SBP_TRACKING_STATE_DETAILED_DEP_SID_CODE__GET(flags) \
  (((flags) >> SBP_TRACKING_STATE_DETAILED_DEP_SID_CODE__SHIFT) & SBP_TRACKING_STATE_DETAILED_DEP_SID_CODE__MASK)
#define SBP_TRACKING_STATE_DETAILED_DEP_SID_CODE__SET(flags, val) \
  do \
  { \
    ((flags) |= (((val) & (SBP_TRACKING_STATE_DETAILED_DEP_SID_CODE__MASK)) \
                 << (SBP_TRACKING_STATE_DETAILED_DEP_SID_CODE__SHIFT))); \
  } while (0)

#define SBP_TRACKING_STATE_DETAILED_DEP_SID_CODE__GPS_L1CA (0)
#define SBP_TRACKING_STATE_DETAILED_DEP_SID_CODE__GPS_L2CM (1)
#define SBP_TRACKING_STATE_DETAILED_DEP_SID_CODE__SBAS_L1CA (2)
#define SBP_TRACKING_STATE_DETAILED_DEP_SID_CODE__GLO_L1CA (3)
#define SBP_TRACKING_STATE_DETAILED_DEP_SID_CODE__GLO_L2CA (4)
#define SBP_TRACKING_STATE_DETAILED_DEP_SID_CODE__GPS_L1P (5)
#define SBP_TRACKING_STATE_DETAILED_DEP_SID_CODE__GPS_L2P (6)
#define SBP_TRACKING_STATE_DETAILED_DEP_SYNC_FLAGS_SYNCHRONIZATION_STATUS_MASK (0x7)
#define SBP_TRACKING_STATE_DETAILED_DEP_SYNC_FLAGS_SYNCHRONIZATION_STATUS_SHIFT (0u)
#define SBP_TRACKING_STATE_DETAILED_DEP_SYNC_FLAGS_SYNCHRONIZATION_STATUS_GET(flags) \
  (((flags) >> SBP_TRACKING_STATE_DETAILED_DEP_SYNC_FLAGS_SYNCHRONIZATION_STATUS_SHIFT) & \
   SBP_TRACKING_STATE_DETAILED_DEP_SYNC_FLAGS_SYNCHRONIZATION_STATUS_MASK)
#define SBP_TRACKING_STATE_DETAILED_DEP_SYNC_FLAGS_SYNCHRONIZATION_STATUS_SET(flags, val) \
  do \
  { \
    ((flags) |= (((val) & (SBP_TRACKING_STATE_DETAILED_DEP_SYNC_FLAGS_SYNCHRONIZATION_STATUS_MASK)) \
                 << (SBP_TRACKING_STATE_DETAILED_DEP_SYNC_FLAGS_SYNCHRONIZATION_STATUS_SHIFT))); \
  } while (0)

#define SBP_TRACKING_STATE_DETAILED_DEP_SYNC_FLAGS_SYNCHRONIZATION_STATUS_NO_SYNCHRONIZATION (0)
#define SBP_TRACKING_STATE_DETAILED_DEP_SYNC_FLAGS_SYNCHRONIZATION_STATUS_BIT_SYNCHRONIZATION (1)
#define SBP_TRACKING_STATE_DETAILED_DEP_SYNC_FLAGS_SYNCHRONIZATION_STATUS_WORD_SYNCHRONIZATION (2)
#define SBP_TRACKING_STATE_DETAILED_DEP_SYNC_FLAGS_SYNCHRONIZATION_STATUS_SUB_FRAME_SYNCHRONIZATION_MESSAGE_SYNCHRONIZATION \
  (3)
#define SBP_TRACKING_STATE_DETAILED_DEP_TOW_FLAGS_WEEK_NUMBER_VALIDITY_STATUS_MASK (0x1)
#define SBP_TRACKING_STATE_DETAILED_DEP_TOW_FLAGS_WEEK_NUMBER_VALIDITY_STATUS_SHIFT (3u)
#define SBP_TRACKING_STATE_DETAILED_DEP_TOW_FLAGS_WEEK_NUMBER_VALIDITY_STATUS_GET(flags) \
  (((flags) >> SBP_TRACKING_STATE_DETAILED_DEP_TOW_FLAGS_WEEK_NUMBER_VALIDITY_STATUS_SHIFT) & \
   SBP_TRACKING_STATE_DETAILED_DEP_TOW_FLAGS_WEEK_NUMBER_VALIDITY_STATUS_MASK)
#define SBP_TRACKING_STATE_DETAILED_DEP_TOW_FLAGS_WEEK_NUMBER_VALIDITY_STATUS_SET(flags, val) \
  do \
  { \
    ((flags) |= (((val) & (SBP_TRACKING_STATE_DETAILED_DEP_TOW_FLAGS_WEEK_NUMBER_VALIDITY_STATUS_MASK)) \
                 << (SBP_TRACKING_STATE_DETAILED_DEP_TOW_FLAGS_WEEK_NUMBER_VALIDITY_STATUS_SHIFT))); \
  } while (0)

#define SBP_TRACKING_STATE_DETAILED_DEP_TOW_FLAGS_WEEK_NUMBER_VALIDITY_STATUS_WEEK_NUMBER_IS_NOT_VALID (0)
#define SBP_TRACKING_STATE_DETAILED_DEP_TOW_FLAGS_WEEK_NUMBER_VALIDITY_STATUS_WEEK_NUMBER_IS_VALID (1)
#define SBP_TRACKING_STATE_DETAILED_DEP_TOW_FLAGS_TOW_STATUS_MASK (0x7)
#define SBP_TRACKING_STATE_DETAILED_DEP_TOW_FLAGS_TOW_STATUS_SHIFT (0u)
#define SBP_TRACKING_STATE_DETAILED_DEP_TOW_FLAGS_TOW_STATUS_GET(flags) \
  (((flags) >> SBP_TRACKING_STATE_DETAILED_DEP_TOW_FLAGS_TOW_STATUS_SHIFT) & \
   SBP_TRACKING_STATE_DETAILED_DEP_TOW_FLAGS_TOW_STATUS_MASK)
#define SBP_TRACKING_STATE_DETAILED_DEP_TOW_FLAGS_TOW_STATUS_SET(flags, val) \
  do \
  { \
    ((flags) |= (((val) & (SBP_TRACKING_STATE_DETAILED_DEP_TOW_FLAGS_TOW_STATUS_MASK)) \
                 << (SBP_TRACKING_STATE_DETAILED_DEP_TOW_FLAGS_TOW_STATUS_SHIFT))); \
  } while (0)

#define SBP_TRACKING_STATE_DETAILED_DEP_TOW_FLAGS_TOW_STATUS_TOW_IS_NOT_AVAILABLE (0)
#define SBP_TRACKING_STATE_DETAILED_DEP_TOW_FLAGS_TOW_STATUS_DECODED_TOW_IS_AVAILABLE (1)
#define SBP_TRACKING_STATE_DETAILED_DEP_TOW_FLAGS_TOW_STATUS_PROPAGATED_TOW_IS_AVAILABLE (2)
#define SBP_TRACKING_STATE_DETAILED_DEP_TRACK_FLAGS_FLL_STATUS_MASK (0x1)
#define SBP_TRACKING_STATE_DETAILED_DEP_TRACK_FLAGS_FLL_STATUS_SHIFT (4u)
#define SBP_TRACKING_STATE_DETAILED_DEP_TRACK_FLAGS_FLL_STATUS_GET(flags) \
  (((flags) >> SBP_TRACKING_STATE_DETAILED_DEP_TRACK_FLAGS_FLL_STATUS_SHIFT) & \
   SBP_TRACKING_STATE_DETAILED_DEP_TRACK_FLAGS_FLL_STATUS_MASK)
#define SBP_TRACKING_STATE_DETAILED_DEP_TRACK_FLAGS_FLL_STATUS_SET(flags, val) \
  do \
  { \
    ((flags) |= (((val) & (SBP_TRACKING_STATE_DETAILED_DEP_TRACK_FLAGS_FLL_STATUS_MASK)) \
                 << (SBP_TRACKING_STATE_DETAILED_DEP_TRACK_FLAGS_FLL_STATUS_SHIFT))); \
  } while (0)

#define SBP_TRACKING_STATE_DETAILED_DEP_TRACK_FLAGS_FLL_STATUS_FLL_IS_INACTIVE (0)
#define SBP_TRACKING_STATE_DETAILED_DEP_TRACK_FLAGS_FLL_STATUS_FLL_IS_ACTIVE (1)
#define SBP_TRACKING_STATE_DETAILED_DEP_TRACK_FLAGS_PLL_STATUS_MASK (0x1)
#define SBP_TRACKING_STATE_DETAILED_DEP_TRACK_FLAGS_PLL_STATUS_SHIFT (3u)
#define SBP_TRACKING_STATE_DETAILED_DEP_TRACK_FLAGS_PLL_STATUS_GET(flags) \
  (((flags) >> SBP_TRACKING_STATE_DETAILED_DEP_TRACK_FLAGS_PLL_STATUS_SHIFT) & \
   SBP_TRACKING_STATE_DETAILED_DEP_TRACK_FLAGS_PLL_STATUS_MASK)
#define SBP_TRACKING_STATE_DETAILED_DEP_TRACK_FLAGS_PLL_STATUS_SET(flags, val) \
  do \
  { \
    ((flags) |= (((val) & (SBP_TRACKING_STATE_DETAILED_DEP_TRACK_FLAGS_PLL_STATUS_MASK)) \
                 << (SBP_TRACKING_STATE_DETAILED_DEP_TRACK_FLAGS_PLL_STATUS_SHIFT))); \
  } while (0)

#define SBP_TRACKING_STATE_DETAILED_DEP_TRACK_FLAGS_PLL_STATUS_PLL_IS_INACTIVE (0)
#define SBP_TRACKING_STATE_DETAILED_DEP_TRACK_FLAGS_PLL_STATUS_PLL_IS_ACTIVE (1)
#define SBP_TRACKING_STATE_DETAILED_DEP_TRACK_FLAGS_TRACKING_LOOP_STATUS_MASK (0x7)
#define SBP_TRACKING_STATE_DETAILED_DEP_TRACK_FLAGS_TRACKING_LOOP_STATUS_SHIFT (0u)
#define SBP_TRACKING_STATE_DETAILED_DEP_TRACK_FLAGS_TRACKING_LOOP_STATUS_GET(flags) \
  (((flags) >> SBP_TRACKING_STATE_DETAILED_DEP_TRACK_FLAGS_TRACKING_LOOP_STATUS_SHIFT) & \
   SBP_TRACKING_STATE_DETAILED_DEP_TRACK_FLAGS_TRACKING_LOOP_STATUS_MASK)
#define SBP_TRACKING_STATE_DETAILED_DEP_TRACK_FLAGS_TRACKING_LOOP_STATUS_SET(flags, val) \
  do \
  { \
    ((flags) |= (((val) & (SBP_TRACKING_STATE_DETAILED_DEP_TRACK_FLAGS_TRACKING_LOOP_STATUS_MASK)) \
                 << (SBP_TRACKING_STATE_DETAILED_DEP_TRACK_FLAGS_TRACKING_LOOP_STATUS_SHIFT))); \
  } while (0)

#define SBP_TRACKING_STATE_DETAILED_DEP_TRACK_FLAGS_TRACKING_LOOP_STATUS_NO_LOCKS (0)
#define SBP_TRACKING_STATE_DETAILED_DEP_TRACK_FLAGS_TRACKING_LOOP_STATUS_FLLDLL_LOCK (1)
#define SBP_TRACKING_STATE_DETAILED_DEP_TRACK_FLAGS_TRACKING_LOOP_STATUS_PLL_OPTIMISTIC_LOCK (2)
#define SBP_TRACKING_STATE_DETAILED_DEP_TRACK_FLAGS_TRACKING_LOOP_STATUS_PLL_PESSIMISTIC_LOCK (3)
#define SBP_TRACKING_STATE_DETAILED_DEP_NAV_FLAGS_ALMANAC_AVAILABILITY_STATUS_MASK (0x1)
#define SBP_TRACKING_STATE_DETAILED_DEP_NAV_FLAGS_ALMANAC_AVAILABILITY_STATUS_SHIFT (4u)
#define SBP_TRACKING_STATE_DETAILED_DEP_NAV_FLAGS_ALMANAC_AVAILABILITY_STATUS_GET(flags) \
  (((flags) >> SBP_TRACKING_STATE_DETAILED_DEP_NAV_FLAGS_ALMANAC_AVAILABILITY_STATUS_SHIFT) & \
   SBP_TRACKING_STATE_DETAILED_DEP_NAV_FLAGS_ALMANAC_AVAILABILITY_STATUS_MASK)
#define SBP_TRACKING_STATE_DETAILED_DEP_NAV_FLAGS_ALMANAC_AVAILABILITY_STATUS_SET(flags, val) \
  do \
  { \
    ((flags) |= (((val) & (SBP_TRACKING_STATE_DETAILED_DEP_NAV_FLAGS_ALMANAC_AVAILABILITY_STATUS_MASK)) \
                 << (SBP_TRACKING_STATE_DETAILED_DEP_NAV_FLAGS_ALMANAC_AVAILABILITY_STATUS_SHIFT))); \
  } while (0)

#define SBP_TRACKING_STATE_DETAILED_DEP_NAV_FLAGS_ALMANAC_AVAILABILITY_STATUS_ALMANAC_IS_NOT_AVAILABLE (0)
#define SBP_TRACKING_STATE_DETAILED_DEP_NAV_FLAGS_ALMANAC_AVAILABILITY_STATUS_ALMANAC_IS_AVAILABLE (1)
#define SBP_TRACKING_STATE_DETAILED_DEP_NAV_FLAGS_EPHEMERIS_AVAILABILITY_STATUS_MASK (0x1)
#define SBP_TRACKING_STATE_DETAILED_DEP_NAV_FLAGS_EPHEMERIS_AVAILABILITY_STATUS_SHIFT (3u)
#define SBP_TRACKING_STATE_DETAILED_DEP_NAV_FLAGS_EPHEMERIS_AVAILABILITY_STATUS_GET(flags) \
  (((flags) >> SBP_TRACKING_STATE_DETAILED_DEP_NAV_FLAGS_EPHEMERIS_AVAILABILITY_STATUS_SHIFT) & \
   SBP_TRACKING_STATE_DETAILED_DEP_NAV_FLAGS_EPHEMERIS_AVAILABILITY_STATUS_MASK)
#define SBP_TRACKING_STATE_DETAILED_DEP_NAV_FLAGS_EPHEMERIS_AVAILABILITY_STATUS_SET(flags, val) \
  do \
  { \
    ((flags) |= (((val) & (SBP_TRACKING_STATE_DETAILED_DEP_NAV_FLAGS_EPHEMERIS_AVAILABILITY_STATUS_MASK)) \
                 << (SBP_TRACKING_STATE_DETAILED_DEP_NAV_FLAGS_EPHEMERIS_AVAILABILITY_STATUS_SHIFT))); \
  } while (0)

#define SBP_TRACKING_STATE_DETAILED_DEP_NAV_FLAGS_EPHEMERIS_AVAILABILITY_STATUS_EPHEMERIS_IS_NOT_AVAILABLE (0)
#define SBP_TRACKING_STATE_DETAILED_DEP_NAV_FLAGS_EPHEMERIS_AVAILABILITY_STATUS_EPHEMERIS_IS_AVAILABLE (1)
#define SBP_TRACKING_STATE_DETAILED_DEP_NAV_FLAGS_HEALTH_STATUS_MASK (0x7)
#define SBP_TRACKING_STATE_DETAILED_DEP_NAV_FLAGS_HEALTH_STATUS_SHIFT (0u)
#define SBP_TRACKING_STATE_DETAILED_DEP_NAV_FLAGS_HEALTH_STATUS_GET(flags) \
  (((flags) >> SBP_TRACKING_STATE_DETAILED_DEP_NAV_FLAGS_HEALTH_STATUS_SHIFT) & \
   SBP_TRACKING_STATE_DETAILED_DEP_NAV_FLAGS_HEALTH_STATUS_MASK)
#define SBP_TRACKING_STATE_DETAILED_DEP_NAV_FLAGS_HEALTH_STATUS_SET(flags, val) \
  do \
  { \
    ((flags) |= (((val) & (SBP_TRACKING_STATE_DETAILED_DEP_NAV_FLAGS_HEALTH_STATUS_MASK)) \
                 << (SBP_TRACKING_STATE_DETAILED_DEP_NAV_FLAGS_HEALTH_STATUS_SHIFT))); \
  } while (0)

#define SBP_TRACKING_STATE_DETAILED_DEP_NAV_FLAGS_HEALTH_STATUS_HEALTH_IS_UNKNOWN (0)
#define SBP_TRACKING_STATE_DETAILED_DEP_NAV_FLAGS_HEALTH_STATUS_SIGNAL_IS_UNHEALTHY (1)
#define SBP_TRACKING_STATE_DETAILED_DEP_NAV_FLAGS_HEALTH_STATUS_SIGNAL_IS_HEALTHY (2)
#define SBP_TRACKING_STATE_DETAILED_DEP_PSET_FLAGS_PARAMETER_SETS_MASK (0x7)
#define SBP_TRACKING_STATE_DETAILED_DEP_PSET_FLAGS_PARAMETER_SETS_SHIFT (0u)
#define SBP_TRACKING_STATE_DETAILED_DEP_PSET_FLAGS_PARAMETER_SETS_GET(flags) \
  (((flags) >> SBP_TRACKING_STATE_DETAILED_DEP_PSET_FLAGS_PARAMETER_SETS_SHIFT) & \
   SBP_TRACKING_STATE_DETAILED_DEP_PSET_FLAGS_PARAMETER_SETS_MASK)
#define SBP_TRACKING_STATE_DETAILED_DEP_PSET_FLAGS_PARAMETER_SETS_SET(flags, val) \
  do \
  { \
    ((flags) |= (((val) & (SBP_TRACKING_STATE_DETAILED_DEP_PSET_FLAGS_PARAMETER_SETS_MASK)) \
                 << (SBP_TRACKING_STATE_DETAILED_DEP_PSET_FLAGS_PARAMETER_SETS_SHIFT))); \
  } while (0)

#define SBP_TRACKING_STATE_DETAILED_DEP_PSET_FLAGS_PARAMETER_SETS_1_MS_INTEGRATION_TIME (0)
#define SBP_TRACKING_STATE_DETAILED_DEP_PSET_FLAGS_PARAMETER_SETS_5_MS_INTEGRATION_TIME (1)
#define SBP_TRACKING_STATE_DETAILED_DEP_PSET_FLAGS_PARAMETER_SETS_10_MS_INTEGRATION_TIME (2)
#define SBP_TRACKING_STATE_DETAILED_DEP_PSET_FLAGS_PARAMETER_SETS_20_MS_INTEGRATION_TIME (3)
#define SBP_TRACKING_STATE_DETAILED_DEP_MISC_FLAGS_CLOCK_VALIDITY_STATUS_MASK (0x1)
#define SBP_TRACKING_STATE_DETAILED_DEP_MISC_FLAGS_CLOCK_VALIDITY_STATUS_SHIFT (5u)
#define SBP_TRACKING_STATE_DETAILED_DEP_MISC_FLAGS_CLOCK_VALIDITY_STATUS_GET(flags) \
  (((flags) >> SBP_TRACKING_STATE_DETAILED_DEP_MISC_FLAGS_CLOCK_VALIDITY_STATUS_SHIFT) & \
   SBP_TRACKING_STATE_DETAILED_DEP_MISC_FLAGS_CLOCK_VALIDITY_STATUS_MASK)
#define SBP_TRACKING_STATE_DETAILED_DEP_MISC_FLAGS_CLOCK_VALIDITY_STATUS_SET(flags, val) \
  do \
  { \
    ((flags) |= (((val) & (SBP_TRACKING_STATE_DETAILED_DEP_MISC_FLAGS_CLOCK_VALIDITY_STATUS_MASK)) \
                 << (SBP_TRACKING_STATE_DETAILED_DEP_MISC_FLAGS_CLOCK_VALIDITY_STATUS_SHIFT))); \
  } while (0)

#define SBP_TRACKING_STATE_DETAILED_DEP_MISC_FLAGS_CLOCK_VALIDITY_STATUS_CLOCK_OFFSET_AND_DRIFT_IS_NOT_VALID (0)
#define SBP_TRACKING_STATE_DETAILED_DEP_MISC_FLAGS_CLOCK_VALIDITY_STATUS_CLOCK_OFFSET_AND_DRIFT_IS_VALID (1)
#define SBP_TRACKING_STATE_DETAILED_DEP_MISC_FLAGS_PSEUDORANGE_VALIDITY_STATUS_MASK (0x1)
#define SBP_TRACKING_STATE_DETAILED_DEP_MISC_FLAGS_PSEUDORANGE_VALIDITY_STATUS_SHIFT (4u)
#define SBP_TRACKING_STATE_DETAILED_DEP_MISC_FLAGS_PSEUDORANGE_VALIDITY_STATUS_GET(flags) \
  (((flags) >> SBP_TRACKING_STATE_DETAILED_DEP_MISC_FLAGS_PSEUDORANGE_VALIDITY_STATUS_SHIFT) & \
   SBP_TRACKING_STATE_DETAILED_DEP_MISC_FLAGS_PSEUDORANGE_VALIDITY_STATUS_MASK)
#define SBP_TRACKING_STATE_DETAILED_DEP_MISC_FLAGS_PSEUDORANGE_VALIDITY_STATUS_SET(flags, val) \
  do \
  { \
    ((flags) |= (((val) & (SBP_TRACKING_STATE_DETAILED_DEP_MISC_FLAGS_PSEUDORANGE_VALIDITY_STATUS_MASK)) \
                 << (SBP_TRACKING_STATE_DETAILED_DEP_MISC_FLAGS_PSEUDORANGE_VALIDITY_STATUS_SHIFT))); \
  } while (0)

#define SBP_TRACKING_STATE_DETAILED_DEP_MISC_FLAGS_PSEUDORANGE_VALIDITY_STATUS_PSEUDORANGE_IS_NOT_VALID (0)
#define SBP_TRACKING_STATE_DETAILED_DEP_MISC_FLAGS_PSEUDORANGE_VALIDITY_STATUS_PSEUDORANGE_IS_VALID (1)
#define SBP_TRACKING_STATE_DETAILED_DEP_MISC_FLAGS_ACCELERATION_VALIDITY_STATUS_MASK (0x1)
#define SBP_TRACKING_STATE_DETAILED_DEP_MISC_FLAGS_ACCELERATION_VALIDITY_STATUS_SHIFT (3u)
#define SBP_TRACKING_STATE_DETAILED_DEP_MISC_FLAGS_ACCELERATION_VALIDITY_STATUS_GET(flags) \
  (((flags) >> SBP_TRACKING_STATE_DETAILED_DEP_MISC_FLAGS_ACCELERATION_VALIDITY_STATUS_SHIFT) & \
   SBP_TRACKING_STATE_DETAILED_DEP_MISC_FLAGS_ACCELERATION_VALIDITY_STATUS_MASK)
#define SBP_TRACKING_STATE_DETAILED_DEP_MISC_FLAGS_ACCELERATION_VALIDITY_STATUS_SET(flags, val) \
  do \
  { \
    ((flags) |= (((val) & (SBP_TRACKING_STATE_DETAILED_DEP_MISC_FLAGS_ACCELERATION_VALIDITY_STATUS_MASK)) \
                 << (SBP_TRACKING_STATE_DETAILED_DEP_MISC_FLAGS_ACCELERATION_VALIDITY_STATUS_SHIFT))); \
  } while (0)

#define SBP_TRACKING_STATE_DETAILED_DEP_MISC_FLAGS_ACCELERATION_VALIDITY_STATUS_ACCELERATION_IS_NOT_VALID (0)
#define SBP_TRACKING_STATE_DETAILED_DEP_MISC_FLAGS_ACCELERATION_VALIDITY_STATUS_ACCELERATION_IS_VALID (1)
#define SBP_TRACKING_STATE_DETAILED_DEP_MISC_FLAGS_CARRIER_HALF_CYCLE_AMBIGUITY_STATUS_MASK (0x1)
#define SBP_TRACKING_STATE_DETAILED_DEP_MISC_FLAGS_CARRIER_HALF_CYCLE_AMBIGUITY_STATUS_SHIFT (2u)
#define SBP_TRACKING_STATE_DETAILED_DEP_MISC_FLAGS_CARRIER_HALF_CYCLE_AMBIGUITY_STATUS_GET(flags) \
  (((flags) >> SBP_TRACKING_STATE_DETAILED_DEP_MISC_FLAGS_CARRIER_HALF_CYCLE_AMBIGUITY_STATUS_SHIFT) & \
   SBP_TRACKING_STATE_DETAILED_DEP_MISC_FLAGS_CARRIER_HALF_CYCLE_AMBIGUITY_STATUS_MASK)
#define SBP_TRACKING_STATE_DETAILED_DEP_MISC_FLAGS_CARRIER_HALF_CYCLE_AMBIGUITY_STATUS_SET(flags, val) \
  do \
  { \
    ((flags) |= (((val) & (SBP_TRACKING_STATE_DETAILED_DEP_MISC_FLAGS_CARRIER_HALF_CYCLE_AMBIGUITY_STATUS_MASK)) \
                 << (SBP_TRACKING_STATE_DETAILED_DEP_MISC_FLAGS_CARRIER_HALF_CYCLE_AMBIGUITY_STATUS_SHIFT))); \
  } while (0)

#define SBP_TRACKING_STATE_DETAILED_DEP_MISC_FLAGS_CARRIER_HALF_CYCLE_AMBIGUITY_STATUS_UNRESOLVED (0)
#define SBP_TRACKING_STATE_DETAILED_DEP_MISC_FLAGS_CARRIER_HALF_CYCLE_AMBIGUITY_STATUS_RESOLVED (1)
#define SBP_TRACKING_STATE_DETAILED_DEP_MISC_FLAGS_TRACKING_CHANNEL_STATUS_MASK (0x3)
#define SBP_TRACKING_STATE_DETAILED_DEP_MISC_FLAGS_TRACKING_CHANNEL_STATUS_SHIFT (0u)
#define SBP_TRACKING_STATE_DETAILED_DEP_MISC_FLAGS_TRACKING_CHANNEL_STATUS_GET(flags) \
  (((flags) >> SBP_TRACKING_STATE_DETAILED_DEP_MISC_FLAGS_TRACKING_CHANNEL_STATUS_SHIFT) & \
   SBP_TRACKING_STATE_DETAILED_DEP_MISC_FLAGS_TRACKING_CHANNEL_STATUS_MASK)
#define SBP_TRACKING_STATE_DETAILED_DEP_MISC_FLAGS_TRACKING_CHANNEL_STATUS_SET(flags, val) \
  do \
  { \
    ((flags) |= (((val) & (SBP_TRACKING_STATE_DETAILED_DEP_MISC_FLAGS_TRACKING_CHANNEL_STATUS_MASK)) \
                 << (SBP_TRACKING_STATE_DETAILED_DEP_MISC_FLAGS_TRACKING_CHANNEL_STATUS_SHIFT))); \
  } while (0)

#define SBP_TRACKING_STATE_DETAILED_DEP_MISC_FLAGS_TRACKING_CHANNEL_STATUS_RE_ACQUISITION (0)
#define SBP_TRACKING_STATE_DETAILED_DEP_MISC_FLAGS_TRACKING_CHANNEL_STATUS_RUNNING (1)
typedef struct
{

  /**
   * Receiver clock time.[ns]
   */
  u64 recv_time;
  /**
   * Time of transmission of signal from satellite. TOW only valid when
   * TOW status is decoded or propagated. WN only valid when week
   * number valid flag is set.
   */
  struct
  {

    /**
     * Milliseconds since start of GPS week[ms]
     */
    u32 tow;
    /**
     * GPS week number[week]
     */
    u16 wn;
  } tot;
  /**
   * Pseudorange observation. Valid only when pseudorange valid flag is
   * set.[2 cm]
   */
  u32 P;
  /**
   * Pseudorange observation standard deviation. Valid only when
   * pseudorange valid flag is set.[2 cm]
   */
  u16 P_std;
  /**
   * Carrier phase observation with typical sign convention. Valid only
   * when PLL pessimistic lock is achieved.[cycles]
   */
  struct
  {

    /**
     * Carrier phase whole cycles[cycles]
     */
    s32 i;
    /**
     * Carrier phase fractional part[cycles / 256]
     */
    u8 f;
  } L;
  /**
   * Carrier-to-Noise density[dB Hz / 4]
   */
  u8 cn0;
  /**
   * Lock time. It is encoded according to DF402 from the RTCM 10403.2
   * Amendment 2 specification. Valid values range from 0 to 15.
   */
  u16 lock;
  /**
   * GNSS signal identifier.
   */
  struct
  {

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
  } sid;
  /**
   * Carrier Doppler frequency.[Hz / 16]
   */
  s32 doppler;
  /**
   * Carrier Doppler frequency standard deviation.[Hz / 16]
   */
  u16 doppler_std;
  /**
   * Number of seconds of continuous tracking. Specifies how much time
   * signal is in continuous track.[s]
   */
  u32 uptime;
  /**
   * TCXO clock offset. Valid only when valid clock valid flag is set.[s / (2 ^ 20)]
   */
  s16 clock_offset;
  /**
   * TCXO clock drift. Valid only when valid clock valid flag is set.[(s / s) / (2 ^ 31)]
   */
  s16 clock_drift;
  /**
   * Early-Prompt (EP) and Prompt-Late (PL) correlators spacing.[ns]
   */
  u16 corr_spacing;
  /**
   * Acceleration. Valid only when acceleration valid flag is set.[g / 8]
   */
  s8 acceleration;
  /**
   * Synchronization status flags.
   */
  u8 sync_flags;
  /**
   * TOW status flags.
   */
  u8 tow_flags;
  /**
   * Tracking loop status flags.
   */
  u8 track_flags;
  /**
   * Navigation data status flags.
   */
  u8 nav_flags;
  /**
   * Parameters sets flags.
   */
  u8 pset_flags;
  /**
   * Miscellaneous flags.
   */
  u8 misc_flags;
} sbp_msg_tracking_state_detailed_dep_t;

static inline size_t
sbp_packed_size_sbp_msg_tracking_state_detailed_dep_t(const sbp_msg_tracking_state_detailed_dep_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->recv_time) + (0 + sizeof(msg->tot.tow) + sizeof(msg->tot.wn)) + sizeof(msg->P) +
         sizeof(msg->P_std) + (0 + sizeof(msg->L.i) + sizeof(msg->L.f)) + sizeof(msg->cn0) + sizeof(msg->lock) +
         (0 + sizeof(msg->sid.sat) + sizeof(msg->sid.code) + sizeof(msg->sid.reserved)) + sizeof(msg->doppler) +
         sizeof(msg->doppler_std) + sizeof(msg->uptime) + sizeof(msg->clock_offset) + sizeof(msg->clock_drift) +
         sizeof(msg->corr_spacing) + sizeof(msg->acceleration) + sizeof(msg->sync_flags) + sizeof(msg->tow_flags) +
         sizeof(msg->track_flags) + sizeof(msg->nav_flags) + sizeof(msg->pset_flags) + sizeof(msg->misc_flags);
}

static inline bool
sbp_pack_sbp_msg_tracking_state_detailed_dep_t(u8 *buf, size_t len, const sbp_msg_tracking_state_detailed_dep_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_tracking_state_detailed_dep_t(msg) > len)
  {
    return false;
  }

  if (offset + 8 > len)
  {
    return false;
  }
  u64 msgrecv_time = htole64(msg->recv_time);
  memcpy(buf + offset, &msgrecv_time, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgtottow = htole32(msg->tot.tow);
  memcpy(buf + offset, &msgtottow, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgtotwn = htole16(msg->tot.wn);
  memcpy(buf + offset, &msgtotwn, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgP = htole32(msg->P);
  memcpy(buf + offset, &msgP, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgP_std = htole16(msg->P_std);
  memcpy(buf + offset, &msgP_std, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgLi = htole32(*(const u32 *)&msg->L.i);
  memcpy(buf + offset, &msgLi, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgLf = msg->L.f;
  memcpy(buf + offset, &msgLf, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgcn0 = msg->cn0;
  memcpy(buf + offset, &msgcn0, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msglock = htole16(msg->lock);
  memcpy(buf + offset, &msglock, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgsidsat = htole16(msg->sid.sat);
  memcpy(buf + offset, &msgsidsat, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgsidcode = msg->sid.code;
  memcpy(buf + offset, &msgsidcode, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgsidreserved = msg->sid.reserved;
  memcpy(buf + offset, &msgsidreserved, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgdoppler = htole32(*(const u32 *)&msg->doppler);
  memcpy(buf + offset, &msgdoppler, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgdoppler_std = htole16(msg->doppler_std);
  memcpy(buf + offset, &msgdoppler_std, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msguptime = htole32(msg->uptime);
  memcpy(buf + offset, &msguptime, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgclock_offset = htole16(*(const u16 *)&msg->clock_offset);
  memcpy(buf + offset, &msgclock_offset, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgclock_drift = htole16(*(const u16 *)&msg->clock_drift);
  memcpy(buf + offset, &msgclock_drift, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgcorr_spacing = htole16(msg->corr_spacing);
  memcpy(buf + offset, &msgcorr_spacing, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  s8 msgacceleration = msg->acceleration;
  memcpy(buf + offset, &msgacceleration, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgsync_flags = msg->sync_flags;
  memcpy(buf + offset, &msgsync_flags, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgtow_flags = msg->tow_flags;
  memcpy(buf + offset, &msgtow_flags, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgtrack_flags = msg->track_flags;
  memcpy(buf + offset, &msgtrack_flags, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgnav_flags = msg->nav_flags;
  memcpy(buf + offset, &msgnav_flags, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgpset_flags = msg->pset_flags;
  memcpy(buf + offset, &msgpset_flags, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgmisc_flags = msg->misc_flags;
  memcpy(buf + offset, &msgmisc_flags, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline bool
sbp_unpack_sbp_msg_tracking_state_detailed_dep_t(const u8 *buf, size_t len, sbp_msg_tracking_state_detailed_dep_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->recv_time, buf + offset, 8);
  msg->recv_time = le64toh(msg->recv_time);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->tot.tow, buf + offset, 4);
  msg->tot.tow = le32toh(msg->tot.tow);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->tot.wn, buf + offset, 2);
  msg->tot.wn = le16toh(msg->tot.wn);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->P, buf + offset, 4);
  msg->P = le32toh(msg->P);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->P_std, buf + offset, 2);
  msg->P_std = le16toh(msg->P_std);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->L.i, buf + offset, 4);
  u32 msgLi = *(const u32 *)&msg->L.i;
  msgLi = le32toh(msgLi);
  msg->L.i = *(const s32 *)&msgLi;
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->L.f, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->cn0, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->lock, buf + offset, 2);
  msg->lock = le16toh(msg->lock);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->sid.sat, buf + offset, 2);
  msg->sid.sat = le16toh(msg->sid.sat);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->sid.code, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->sid.reserved, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->doppler, buf + offset, 4);
  u32 msgdoppler = *(const u32 *)&msg->doppler;
  msgdoppler = le32toh(msgdoppler);
  msg->doppler = *(const s32 *)&msgdoppler;
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->doppler_std, buf + offset, 2);
  msg->doppler_std = le16toh(msg->doppler_std);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->uptime, buf + offset, 4);
  msg->uptime = le32toh(msg->uptime);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->clock_offset, buf + offset, 2);
  u16 msgclock_offset = *(const u16 *)&msg->clock_offset;
  msgclock_offset = le16toh(msgclock_offset);
  msg->clock_offset = *(const s16 *)&msgclock_offset;
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->clock_drift, buf + offset, 2);
  u16 msgclock_drift = *(const u16 *)&msg->clock_drift;
  msgclock_drift = le16toh(msgclock_drift);
  msg->clock_drift = *(const s16 *)&msgclock_drift;
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->corr_spacing, buf + offset, 2);
  msg->corr_spacing = le16toh(msg->corr_spacing);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->acceleration, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->sync_flags, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->tow_flags, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->track_flags, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->nav_flags, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->pset_flags, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->misc_flags, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_tracking_state_detailed_dep_t &a,
                              const sbp_msg_tracking_state_detailed_dep_t &b)
{
  (void)a;
  (void)b;

  if (a.recv_time != b.recv_time)
  {
    return false;
  }

  if (a.tot.tow != b.tot.tow)
  {
    return false;
  }

  if (a.tot.wn != b.tot.wn)
  {
    return false;
  }

  if (a.P != b.P)
  {
    return false;
  }

  if (a.P_std != b.P_std)
  {
    return false;
  }

  if (a.L.i != b.L.i)
  {
    return false;
  }

  if (a.L.f != b.L.f)
  {
    return false;
  }

  if (a.cn0 != b.cn0)
  {
    return false;
  }

  if (a.lock != b.lock)
  {
    return false;
  }

  if (a.sid.sat != b.sid.sat)
  {
    return false;
  }

  if (a.sid.code != b.sid.code)
  {
    return false;
  }

  if (a.sid.reserved != b.sid.reserved)
  {
    return false;
  }

  if (a.doppler != b.doppler)
  {
    return false;
  }

  if (a.doppler_std != b.doppler_std)
  {
    return false;
  }

  if (a.uptime != b.uptime)
  {
    return false;
  }

  if (a.clock_offset != b.clock_offset)
  {
    return false;
  }

  if (a.clock_drift != b.clock_drift)
  {
    return false;
  }

  if (a.corr_spacing != b.corr_spacing)
  {
    return false;
  }

  if (a.acceleration != b.acceleration)
  {
    return false;
  }

  if (a.sync_flags != b.sync_flags)
  {
    return false;
  }

  if (a.tow_flags != b.tow_flags)
  {
    return false;
  }

  if (a.track_flags != b.track_flags)
  {
    return false;
  }

  if (a.nav_flags != b.nav_flags)
  {
    return false;
  }

  if (a.pset_flags != b.pset_flags)
  {
    return false;
  }

  if (a.misc_flags != b.misc_flags)
  {
    return false;
  }

  return true;
}

static inline bool operator!=(const sbp_msg_tracking_state_detailed_dep_t &a,
                              const sbp_msg_tracking_state_detailed_dep_t &b)
{
  return !(a == b);
}
#endif
/** Signal tracking channel states
 *
 * The tracking message returns a variable-length array of tracking
 * channel states. It reports status and carrier-to-noise density
 * measurements for all tracked satellites.
 */
#define SBP_MSG_TRACKING_STATE 0x0041

#define SBP_TRACKING_STATE_STATES_SID_CODE__MASK (0xff)
#define SBP_TRACKING_STATE_STATES_SID_CODE__SHIFT (0u)
#define SBP_TRACKING_STATE_STATES_SID_CODE__GET(flags) \
  (((flags) >> SBP_TRACKING_STATE_STATES_SID_CODE__SHIFT) & SBP_TRACKING_STATE_STATES_SID_CODE__MASK)
#define SBP_TRACKING_STATE_STATES_SID_CODE__SET(flags, val) \
  do \
  { \
    ((flags) |= \
     (((val) & (SBP_TRACKING_STATE_STATES_SID_CODE__MASK)) << (SBP_TRACKING_STATE_STATES_SID_CODE__SHIFT))); \
  } while (0)

#define SBP_TRACKING_STATE_STATES_SID_CODE__GPS_L1CA (0)
#define SBP_TRACKING_STATE_STATES_SID_CODE__GPS_L2CM (1)
#define SBP_TRACKING_STATE_STATES_SID_CODE__SBAS_L1CA (2)
#define SBP_TRACKING_STATE_STATES_SID_CODE__GLO_L1CA (3)
#define SBP_TRACKING_STATE_STATES_SID_CODE__GLO_L2CA (4)
#define SBP_TRACKING_STATE_STATES_SID_CODE__GPS_L1P (5)
#define SBP_TRACKING_STATE_STATES_SID_CODE__GPS_L2P (6)
#define SBP_TRACKING_STATE_STATES_SID_CODE__BDS2_B1 (12)
#define SBP_TRACKING_STATE_STATES_SID_CODE__BDS2_B2 (13)
#define SBP_TRACKING_STATE_STATES_SID_CODE__GAL_E1B (14)
#define SBP_TRACKING_STATE_STATES_SID_CODE__GAL_E7I (20)
#define SBP_TRACKING_STATE_STATES_SID_CODE__BDS3_B2A (47)
typedef struct
{

  /**
   * Signal tracking channel state
   */
  struct
  {

    /**
     * GNSS signal being tracked
     */
    struct
    {

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
    } sid;
    /**
     * Frequency channel number (GLONASS only)
     */
    u8 fcn;
    /**
     * Carrier-to-Noise density.  Zero implies invalid cn0.[dB Hz / 4]
     */
    u8 cn0;
  } states[63];
  /**
   * Number of items in states
   */
  u8 n_states;
} sbp_msg_tracking_state_t;

static inline size_t sbp_packed_size_sbp_msg_tracking_state_t(const sbp_msg_tracking_state_t *msg)
{
  (void)msg;
  return 0 + (msg->n_states * (0 + (0 + sizeof(msg->states[0].sid.sat) + sizeof(msg->states[0].sid.code)) +
                               sizeof(msg->states[0].fcn) + sizeof(msg->states[0].cn0)));
}

static inline bool sbp_pack_sbp_msg_tracking_state_t(u8 *buf, size_t len, const sbp_msg_tracking_state_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_tracking_state_t(msg) > len)
  {
    return false;
  }

  for (size_t msgstates_idx = 0; msgstates_idx < (size_t)msg->n_states; msgstates_idx++)
  {

    if (offset + 1 > len)
    {
      return false;
    }
    u8 msgstatesmsgstates_idxsidsat = msg->states[msgstates_idx].sid.sat;
    memcpy(buf + offset, &msgstatesmsgstates_idxsidsat, 1);
    // NOLINTNEXTLINE
    offset += 1;

    if (offset + 1 > len)
    {
      return false;
    }
    u8 msgstatesmsgstates_idxsidcode = msg->states[msgstates_idx].sid.code;
    memcpy(buf + offset, &msgstatesmsgstates_idxsidcode, 1);
    // NOLINTNEXTLINE
    offset += 1;

    if (offset + 1 > len)
    {
      return false;
    }
    u8 msgstatesmsgstates_idxfcn = msg->states[msgstates_idx].fcn;
    memcpy(buf + offset, &msgstatesmsgstates_idxfcn, 1);
    // NOLINTNEXTLINE
    offset += 1;

    if (offset + 1 > len)
    {
      return false;
    }
    u8 msgstatesmsgstates_idxcn0 = msg->states[msgstates_idx].cn0;
    memcpy(buf + offset, &msgstatesmsgstates_idxcn0, 1);
    // NOLINTNEXTLINE
    offset += 1;
  }
  return true;
}

static inline bool sbp_unpack_sbp_msg_tracking_state_t(const u8 *buf, size_t len, sbp_msg_tracking_state_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  msg->n_states = (u8)((len - offset) / 4);

  for (size_t msgstates_idx = 0; msgstates_idx < msg->n_states; msgstates_idx++)
  {

    if (offset + 1 > len)
    {
      return false;
    }
    memcpy(&msg->states[msgstates_idx].sid.sat, buf + offset, 1);
    // NOLINTNEXTLINE
    offset += 1;

    if (offset + 1 > len)
    {
      return false;
    }
    memcpy(&msg->states[msgstates_idx].sid.code, buf + offset, 1);
    // NOLINTNEXTLINE
    offset += 1;

    if (offset + 1 > len)
    {
      return false;
    }
    memcpy(&msg->states[msgstates_idx].fcn, buf + offset, 1);
    // NOLINTNEXTLINE
    offset += 1;

    if (offset + 1 > len)
    {
      return false;
    }
    memcpy(&msg->states[msgstates_idx].cn0, buf + offset, 1);
    // NOLINTNEXTLINE
    offset += 1;
  }
  return true;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_tracking_state_t &a, const sbp_msg_tracking_state_t &b)
{
  (void)a;
  (void)b;

  if (a.n_states != b.n_states)
  {
    return false;
  }
  for (size_t states_idx = 0; states_idx < (size_t)a.n_states; states_idx++)
  {

    if (a.states[states_idx].sid.sat != b.states[states_idx].sid.sat)
    {
      return false;
    }

    if (a.states[states_idx].sid.code != b.states[states_idx].sid.code)
    {
      return false;
    }

    if (a.states[states_idx].fcn != b.states[states_idx].fcn)
    {
      return false;
    }

    if (a.states[states_idx].cn0 != b.states[states_idx].cn0)
    {
      return false;
    }
  }

  return true;
}

static inline bool operator!=(const sbp_msg_tracking_state_t &a, const sbp_msg_tracking_state_t &b)
{
  return !(a == b);
}
#endif
/** Measurement Engine signal tracking channel states
 *
 * The tracking message returns a variable-length array of tracking
 * channel states. It reports status and carrier-to-noise density
 * measurements for all tracked satellites.
 */
#define SBP_MSG_MEASUREMENT_STATE 0x0061

#define SBP_MEASUREMENT_STATE_STATES_MESID_CODE__MASK (0xff)
#define SBP_MEASUREMENT_STATE_STATES_MESID_CODE__SHIFT (0u)
#define SBP_MEASUREMENT_STATE_STATES_MESID_CODE__GET(flags) \
  (((flags) >> SBP_MEASUREMENT_STATE_STATES_MESID_CODE__SHIFT) & SBP_MEASUREMENT_STATE_STATES_MESID_CODE__MASK)
#define SBP_MEASUREMENT_STATE_STATES_MESID_CODE__SET(flags, val) \
  do \
  { \
    ((flags) |= \
     (((val) & (SBP_MEASUREMENT_STATE_STATES_MESID_CODE__MASK)) << (SBP_MEASUREMENT_STATE_STATES_MESID_CODE__SHIFT))); \
  } while (0)

#define SBP_MEASUREMENT_STATE_STATES_MESID_CODE__GPS_L1CA (0)
#define SBP_MEASUREMENT_STATE_STATES_MESID_CODE__GPS_L2CM (1)
#define SBP_MEASUREMENT_STATE_STATES_MESID_CODE__SBAS_L1CA (2)
#define SBP_MEASUREMENT_STATE_STATES_MESID_CODE__GLO_L1CA (3)
#define SBP_MEASUREMENT_STATE_STATES_MESID_CODE__GLO_L2CA (4)
#define SBP_MEASUREMENT_STATE_STATES_MESID_CODE__GPS_L1P (5)
#define SBP_MEASUREMENT_STATE_STATES_MESID_CODE__GPS_L2P (6)
#define SBP_MEASUREMENT_STATE_STATES_MESID_CODE__BDS2_B1 (12)
#define SBP_MEASUREMENT_STATE_STATES_MESID_CODE__BDS2_B2 (13)
#define SBP_MEASUREMENT_STATE_STATES_MESID_CODE__GAL_E1B (14)
#define SBP_MEASUREMENT_STATE_STATES_MESID_CODE__GAL_E7I (20)
#define SBP_MEASUREMENT_STATE_STATES_MESID_CODE__BDS3_B2A (47)
typedef struct
{

  /**
   * ME signal tracking channel state
   */
  struct
  {

    /**
     * Measurement Engine GNSS signal being tracked (carries either Glonass FCN or SLOT)
     */
    struct
    {

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
    } mesid;
    /**
     * Carrier-to-Noise density.  Zero implies invalid cn0.[dB Hz / 4]
     */
    u8 cn0;
  } states[85];
  /**
   * Number of items in states
   */
  u8 n_states;
} sbp_msg_measurement_state_t;

static inline size_t sbp_packed_size_sbp_msg_measurement_state_t(const sbp_msg_measurement_state_t *msg)
{
  (void)msg;
  return 0 + (msg->n_states * (0 + (0 + sizeof(msg->states[0].mesid.sat) + sizeof(msg->states[0].mesid.code)) +
                               sizeof(msg->states[0].cn0)));
}

static inline bool sbp_pack_sbp_msg_measurement_state_t(u8 *buf, size_t len, const sbp_msg_measurement_state_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_measurement_state_t(msg) > len)
  {
    return false;
  }

  for (size_t msgstates_idx = 0; msgstates_idx < (size_t)msg->n_states; msgstates_idx++)
  {

    if (offset + 1 > len)
    {
      return false;
    }
    u8 msgstatesmsgstates_idxmesidsat = msg->states[msgstates_idx].mesid.sat;
    memcpy(buf + offset, &msgstatesmsgstates_idxmesidsat, 1);
    // NOLINTNEXTLINE
    offset += 1;

    if (offset + 1 > len)
    {
      return false;
    }
    u8 msgstatesmsgstates_idxmesidcode = msg->states[msgstates_idx].mesid.code;
    memcpy(buf + offset, &msgstatesmsgstates_idxmesidcode, 1);
    // NOLINTNEXTLINE
    offset += 1;

    if (offset + 1 > len)
    {
      return false;
    }
    u8 msgstatesmsgstates_idxcn0 = msg->states[msgstates_idx].cn0;
    memcpy(buf + offset, &msgstatesmsgstates_idxcn0, 1);
    // NOLINTNEXTLINE
    offset += 1;
  }
  return true;
}

static inline bool sbp_unpack_sbp_msg_measurement_state_t(const u8 *buf, size_t len, sbp_msg_measurement_state_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  msg->n_states = (u8)((len - offset) / 3);

  for (size_t msgstates_idx = 0; msgstates_idx < msg->n_states; msgstates_idx++)
  {

    if (offset + 1 > len)
    {
      return false;
    }
    memcpy(&msg->states[msgstates_idx].mesid.sat, buf + offset, 1);
    // NOLINTNEXTLINE
    offset += 1;

    if (offset + 1 > len)
    {
      return false;
    }
    memcpy(&msg->states[msgstates_idx].mesid.code, buf + offset, 1);
    // NOLINTNEXTLINE
    offset += 1;

    if (offset + 1 > len)
    {
      return false;
    }
    memcpy(&msg->states[msgstates_idx].cn0, buf + offset, 1);
    // NOLINTNEXTLINE
    offset += 1;
  }
  return true;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_measurement_state_t &a, const sbp_msg_measurement_state_t &b)
{
  (void)a;
  (void)b;

  if (a.n_states != b.n_states)
  {
    return false;
  }
  for (size_t states_idx = 0; states_idx < (size_t)a.n_states; states_idx++)
  {

    if (a.states[states_idx].mesid.sat != b.states[states_idx].mesid.sat)
    {
      return false;
    }

    if (a.states[states_idx].mesid.code != b.states[states_idx].mesid.code)
    {
      return false;
    }

    if (a.states[states_idx].cn0 != b.states[states_idx].cn0)
    {
      return false;
    }
  }

  return true;
}

static inline bool operator!=(const sbp_msg_measurement_state_t &a, const sbp_msg_measurement_state_t &b)
{
  return !(a == b);
}
#endif
/** Tracking channel correlations
 *
 * When enabled, a tracking channel can output the correlations at each
 * update interval.
 */
#define SBP_MSG_TRACKING_IQ 0x002D

#define SBP_TRACKING_IQ_SID_CODE__MASK (0xff)
#define SBP_TRACKING_IQ_SID_CODE__SHIFT (0u)
#define SBP_TRACKING_IQ_SID_CODE__GET(flags) \
  (((flags) >> SBP_TRACKING_IQ_SID_CODE__SHIFT) & SBP_TRACKING_IQ_SID_CODE__MASK)
#define SBP_TRACKING_IQ_SID_CODE__SET(flags, val) \
  do \
  { \
    ((flags) |= (((val) & (SBP_TRACKING_IQ_SID_CODE__MASK)) << (SBP_TRACKING_IQ_SID_CODE__SHIFT))); \
  } while (0)

#define SBP_TRACKING_IQ_SID_CODE__GPS_L1CA (0)
#define SBP_TRACKING_IQ_SID_CODE__GPS_L2CM (1)
#define SBP_TRACKING_IQ_SID_CODE__SBAS_L1CA (2)
#define SBP_TRACKING_IQ_SID_CODE__GLO_L1CA (3)
#define SBP_TRACKING_IQ_SID_CODE__GLO_L2CA (4)
#define SBP_TRACKING_IQ_SID_CODE__GPS_L1P (5)
#define SBP_TRACKING_IQ_SID_CODE__GPS_L2P (6)
#define SBP_TRACKING_IQ_SID_CODE__BDS2_B1 (12)
#define SBP_TRACKING_IQ_SID_CODE__BDS2_B2 (13)
#define SBP_TRACKING_IQ_SID_CODE__GAL_E1B (14)
#define SBP_TRACKING_IQ_SID_CODE__GAL_E7I (20)
#define SBP_TRACKING_IQ_SID_CODE__BDS3_B2A (47)

typedef struct
{

  /**
   * Tracking channel of origin
   */
  u8 channel;
  /**
   * GNSS signal identifier
   */
  struct
  {

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
  } sid;
  /**
   * Early, Prompt and Late correlations
   */
  struct
  {

    /**
     * In-phase correlation
     */
    s16 I;
    /**
     * Quadrature correlation
     */
    s16 Q;
  } corrs[3];
} sbp_msg_tracking_iq_t;

static inline size_t sbp_packed_size_sbp_msg_tracking_iq_t(const sbp_msg_tracking_iq_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->channel) + (0 + sizeof(msg->sid.sat) + sizeof(msg->sid.code)) +
         (3 * (0 + sizeof(msg->corrs[0].I) + sizeof(msg->corrs[0].Q)));
}

static inline bool sbp_pack_sbp_msg_tracking_iq_t(u8 *buf, size_t len, const sbp_msg_tracking_iq_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_tracking_iq_t(msg) > len)
  {
    return false;
  }

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgchannel = msg->channel;
  memcpy(buf + offset, &msgchannel, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgsidsat = msg->sid.sat;
  memcpy(buf + offset, &msgsidsat, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgsidcode = msg->sid.code;
  memcpy(buf + offset, &msgsidcode, 1);
  // NOLINTNEXTLINE
  offset += 1;
  for (size_t msgcorrs_idx = 0; msgcorrs_idx < 3; msgcorrs_idx++)
  {

    if (offset + 2 > len)
    {
      return false;
    }
    u16 msgcorrsmsgcorrs_idxI = htole16(*(const u16 *)&msg->corrs[msgcorrs_idx].I);
    memcpy(buf + offset, &msgcorrsmsgcorrs_idxI, 2);
    // NOLINTNEXTLINE
    offset += 2;

    if (offset + 2 > len)
    {
      return false;
    }
    u16 msgcorrsmsgcorrs_idxQ = htole16(*(const u16 *)&msg->corrs[msgcorrs_idx].Q);
    memcpy(buf + offset, &msgcorrsmsgcorrs_idxQ, 2);
    // NOLINTNEXTLINE
    offset += 2;
  }
  return true;
}

static inline bool sbp_unpack_sbp_msg_tracking_iq_t(const u8 *buf, size_t len, sbp_msg_tracking_iq_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->channel, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->sid.sat, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->sid.code, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
  for (size_t msgcorrs_idx = 0; msgcorrs_idx < 3; msgcorrs_idx++)
  {

    if (offset + 2 > len)
    {
      return false;
    }
    memcpy(&msg->corrs[msgcorrs_idx].I, buf + offset, 2);
    u16 msgcorrsmsgcorrs_idxI = *(const u16 *)&msg->corrs[msgcorrs_idx].I;
    msgcorrsmsgcorrs_idxI = le16toh(msgcorrsmsgcorrs_idxI);
    msg->corrs[msgcorrs_idx].I = *(const s16 *)&msgcorrsmsgcorrs_idxI;
    // NOLINTNEXTLINE
    offset += 2;

    if (offset + 2 > len)
    {
      return false;
    }
    memcpy(&msg->corrs[msgcorrs_idx].Q, buf + offset, 2);
    u16 msgcorrsmsgcorrs_idxQ = *(const u16 *)&msg->corrs[msgcorrs_idx].Q;
    msgcorrsmsgcorrs_idxQ = le16toh(msgcorrsmsgcorrs_idxQ);
    msg->corrs[msgcorrs_idx].Q = *(const s16 *)&msgcorrsmsgcorrs_idxQ;
    // NOLINTNEXTLINE
    offset += 2;
  }
  return true;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_tracking_iq_t &a, const sbp_msg_tracking_iq_t &b)
{
  (void)a;
  (void)b;

  if (a.channel != b.channel)
  {
    return false;
  }

  if (a.sid.sat != b.sid.sat)
  {
    return false;
  }

  if (a.sid.code != b.sid.code)
  {
    return false;
  }
  for (size_t corrs_idx = 0; corrs_idx < 3; corrs_idx++)
  {

    if (a.corrs[corrs_idx].I != b.corrs[corrs_idx].I)
    {
      return false;
    }

    if (a.corrs[corrs_idx].Q != b.corrs[corrs_idx].Q)
    {
      return false;
    }
  }

  return true;
}

static inline bool operator!=(const sbp_msg_tracking_iq_t &a, const sbp_msg_tracking_iq_t &b)
{
  return !(a == b);
}
#endif
/** Tracking channel correlations
 *
 * When enabled, a tracking channel can output the correlations at each
 * update interval.
 */
#define SBP_MSG_TRACKING_IQ_DEP_B 0x002C

#define SBP_TRACKING_IQ_DEP_B_SID_CODE__MASK (0xff)
#define SBP_TRACKING_IQ_DEP_B_SID_CODE__SHIFT (0u)
#define SBP_TRACKING_IQ_DEP_B_SID_CODE__GET(flags) \
  (((flags) >> SBP_TRACKING_IQ_DEP_B_SID_CODE__SHIFT) & SBP_TRACKING_IQ_DEP_B_SID_CODE__MASK)
#define SBP_TRACKING_IQ_DEP_B_SID_CODE__SET(flags, val) \
  do \
  { \
    ((flags) |= (((val) & (SBP_TRACKING_IQ_DEP_B_SID_CODE__MASK)) << (SBP_TRACKING_IQ_DEP_B_SID_CODE__SHIFT))); \
  } while (0)

#define SBP_TRACKING_IQ_DEP_B_SID_CODE__GPS_L1CA (0)
#define SBP_TRACKING_IQ_DEP_B_SID_CODE__GPS_L2CM (1)
#define SBP_TRACKING_IQ_DEP_B_SID_CODE__SBAS_L1CA (2)
#define SBP_TRACKING_IQ_DEP_B_SID_CODE__GLO_L1CA (3)
#define SBP_TRACKING_IQ_DEP_B_SID_CODE__GLO_L2CA (4)
#define SBP_TRACKING_IQ_DEP_B_SID_CODE__GPS_L1P (5)
#define SBP_TRACKING_IQ_DEP_B_SID_CODE__GPS_L2P (6)
#define SBP_TRACKING_IQ_DEP_B_SID_CODE__BDS2_B1 (12)
#define SBP_TRACKING_IQ_DEP_B_SID_CODE__BDS2_B2 (13)
#define SBP_TRACKING_IQ_DEP_B_SID_CODE__GAL_E1B (14)
#define SBP_TRACKING_IQ_DEP_B_SID_CODE__GAL_E7I (20)
#define SBP_TRACKING_IQ_DEP_B_SID_CODE__BDS3_B2A (47)

typedef struct
{

  /**
   * Tracking channel of origin
   */
  u8 channel;
  /**
   * GNSS signal identifier
   */
  struct
  {

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
  } sid;
  /**
   * Early, Prompt and Late correlations
   */
  struct
  {

    /**
     * In-phase correlation
     */
    s32 I;
    /**
     * Quadrature correlation
     */
    s32 Q;
  } corrs[3];
} sbp_msg_tracking_iq_dep_b_t;

static inline size_t sbp_packed_size_sbp_msg_tracking_iq_dep_b_t(const sbp_msg_tracking_iq_dep_b_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->channel) + (0 + sizeof(msg->sid.sat) + sizeof(msg->sid.code)) +
         (3 * (0 + sizeof(msg->corrs[0].I) + sizeof(msg->corrs[0].Q)));
}

static inline bool sbp_pack_sbp_msg_tracking_iq_dep_b_t(u8 *buf, size_t len, const sbp_msg_tracking_iq_dep_b_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_tracking_iq_dep_b_t(msg) > len)
  {
    return false;
  }

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgchannel = msg->channel;
  memcpy(buf + offset, &msgchannel, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgsidsat = msg->sid.sat;
  memcpy(buf + offset, &msgsidsat, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgsidcode = msg->sid.code;
  memcpy(buf + offset, &msgsidcode, 1);
  // NOLINTNEXTLINE
  offset += 1;
  for (size_t msgcorrs_idx = 0; msgcorrs_idx < 3; msgcorrs_idx++)
  {

    if (offset + 4 > len)
    {
      return false;
    }
    u32 msgcorrsmsgcorrs_idxI = htole32(*(const u32 *)&msg->corrs[msgcorrs_idx].I);
    memcpy(buf + offset, &msgcorrsmsgcorrs_idxI, 4);
    // NOLINTNEXTLINE
    offset += 4;

    if (offset + 4 > len)
    {
      return false;
    }
    u32 msgcorrsmsgcorrs_idxQ = htole32(*(const u32 *)&msg->corrs[msgcorrs_idx].Q);
    memcpy(buf + offset, &msgcorrsmsgcorrs_idxQ, 4);
    // NOLINTNEXTLINE
    offset += 4;
  }
  return true;
}

static inline bool sbp_unpack_sbp_msg_tracking_iq_dep_b_t(const u8 *buf, size_t len, sbp_msg_tracking_iq_dep_b_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->channel, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->sid.sat, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->sid.code, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
  for (size_t msgcorrs_idx = 0; msgcorrs_idx < 3; msgcorrs_idx++)
  {

    if (offset + 4 > len)
    {
      return false;
    }
    memcpy(&msg->corrs[msgcorrs_idx].I, buf + offset, 4);
    u32 msgcorrsmsgcorrs_idxI = *(const u32 *)&msg->corrs[msgcorrs_idx].I;
    msgcorrsmsgcorrs_idxI = le32toh(msgcorrsmsgcorrs_idxI);
    msg->corrs[msgcorrs_idx].I = *(const s32 *)&msgcorrsmsgcorrs_idxI;
    // NOLINTNEXTLINE
    offset += 4;

    if (offset + 4 > len)
    {
      return false;
    }
    memcpy(&msg->corrs[msgcorrs_idx].Q, buf + offset, 4);
    u32 msgcorrsmsgcorrs_idxQ = *(const u32 *)&msg->corrs[msgcorrs_idx].Q;
    msgcorrsmsgcorrs_idxQ = le32toh(msgcorrsmsgcorrs_idxQ);
    msg->corrs[msgcorrs_idx].Q = *(const s32 *)&msgcorrsmsgcorrs_idxQ;
    // NOLINTNEXTLINE
    offset += 4;
  }
  return true;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_tracking_iq_dep_b_t &a, const sbp_msg_tracking_iq_dep_b_t &b)
{
  (void)a;
  (void)b;

  if (a.channel != b.channel)
  {
    return false;
  }

  if (a.sid.sat != b.sid.sat)
  {
    return false;
  }

  if (a.sid.code != b.sid.code)
  {
    return false;
  }
  for (size_t corrs_idx = 0; corrs_idx < 3; corrs_idx++)
  {

    if (a.corrs[corrs_idx].I != b.corrs[corrs_idx].I)
    {
      return false;
    }

    if (a.corrs[corrs_idx].Q != b.corrs[corrs_idx].Q)
    {
      return false;
    }
  }

  return true;
}

static inline bool operator!=(const sbp_msg_tracking_iq_dep_b_t &a, const sbp_msg_tracking_iq_dep_b_t &b)
{
  return !(a == b);
}
#endif
/** Deprecated
 *
 * Deprecated.
 */
#define SBP_MSG_TRACKING_IQ_DEP_A 0x001C

#define SBP_TRACKING_IQ_DEP_A_SID_CODE__MASK (0xff)
#define SBP_TRACKING_IQ_DEP_A_SID_CODE__SHIFT (0u)
#define SBP_TRACKING_IQ_DEP_A_SID_CODE__GET(flags) \
  (((flags) >> SBP_TRACKING_IQ_DEP_A_SID_CODE__SHIFT) & SBP_TRACKING_IQ_DEP_A_SID_CODE__MASK)
#define SBP_TRACKING_IQ_DEP_A_SID_CODE__SET(flags, val) \
  do \
  { \
    ((flags) |= (((val) & (SBP_TRACKING_IQ_DEP_A_SID_CODE__MASK)) << (SBP_TRACKING_IQ_DEP_A_SID_CODE__SHIFT))); \
  } while (0)

#define SBP_TRACKING_IQ_DEP_A_SID_CODE__GPS_L1CA (0)
#define SBP_TRACKING_IQ_DEP_A_SID_CODE__GPS_L2CM (1)
#define SBP_TRACKING_IQ_DEP_A_SID_CODE__SBAS_L1CA (2)
#define SBP_TRACKING_IQ_DEP_A_SID_CODE__GLO_L1CA (3)
#define SBP_TRACKING_IQ_DEP_A_SID_CODE__GLO_L2CA (4)
#define SBP_TRACKING_IQ_DEP_A_SID_CODE__GPS_L1P (5)
#define SBP_TRACKING_IQ_DEP_A_SID_CODE__GPS_L2P (6)

typedef struct
{

  /**
   * Tracking channel of origin
   */
  u8 channel;
  /**
   * GNSS signal identifier
   */
  struct
  {

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
  } sid;
  /**
   * Early, Prompt and Late correlations
   */
  struct
  {

    /**
     * In-phase correlation
     */
    s32 I;
    /**
     * Quadrature correlation
     */
    s32 Q;
  } corrs[3];
} sbp_msg_tracking_iq_dep_a_t;

static inline size_t sbp_packed_size_sbp_msg_tracking_iq_dep_a_t(const sbp_msg_tracking_iq_dep_a_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->channel) + (0 + sizeof(msg->sid.sat) + sizeof(msg->sid.code) + sizeof(msg->sid.reserved)) +
         (3 * (0 + sizeof(msg->corrs[0].I) + sizeof(msg->corrs[0].Q)));
}

static inline bool sbp_pack_sbp_msg_tracking_iq_dep_a_t(u8 *buf, size_t len, const sbp_msg_tracking_iq_dep_a_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_tracking_iq_dep_a_t(msg) > len)
  {
    return false;
  }

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgchannel = msg->channel;
  memcpy(buf + offset, &msgchannel, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgsidsat = htole16(msg->sid.sat);
  memcpy(buf + offset, &msgsidsat, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgsidcode = msg->sid.code;
  memcpy(buf + offset, &msgsidcode, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgsidreserved = msg->sid.reserved;
  memcpy(buf + offset, &msgsidreserved, 1);
  // NOLINTNEXTLINE
  offset += 1;
  for (size_t msgcorrs_idx = 0; msgcorrs_idx < 3; msgcorrs_idx++)
  {

    if (offset + 4 > len)
    {
      return false;
    }
    u32 msgcorrsmsgcorrs_idxI = htole32(*(const u32 *)&msg->corrs[msgcorrs_idx].I);
    memcpy(buf + offset, &msgcorrsmsgcorrs_idxI, 4);
    // NOLINTNEXTLINE
    offset += 4;

    if (offset + 4 > len)
    {
      return false;
    }
    u32 msgcorrsmsgcorrs_idxQ = htole32(*(const u32 *)&msg->corrs[msgcorrs_idx].Q);
    memcpy(buf + offset, &msgcorrsmsgcorrs_idxQ, 4);
    // NOLINTNEXTLINE
    offset += 4;
  }
  return true;
}

static inline bool sbp_unpack_sbp_msg_tracking_iq_dep_a_t(const u8 *buf, size_t len, sbp_msg_tracking_iq_dep_a_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->channel, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->sid.sat, buf + offset, 2);
  msg->sid.sat = le16toh(msg->sid.sat);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->sid.code, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->sid.reserved, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
  for (size_t msgcorrs_idx = 0; msgcorrs_idx < 3; msgcorrs_idx++)
  {

    if (offset + 4 > len)
    {
      return false;
    }
    memcpy(&msg->corrs[msgcorrs_idx].I, buf + offset, 4);
    u32 msgcorrsmsgcorrs_idxI = *(const u32 *)&msg->corrs[msgcorrs_idx].I;
    msgcorrsmsgcorrs_idxI = le32toh(msgcorrsmsgcorrs_idxI);
    msg->corrs[msgcorrs_idx].I = *(const s32 *)&msgcorrsmsgcorrs_idxI;
    // NOLINTNEXTLINE
    offset += 4;

    if (offset + 4 > len)
    {
      return false;
    }
    memcpy(&msg->corrs[msgcorrs_idx].Q, buf + offset, 4);
    u32 msgcorrsmsgcorrs_idxQ = *(const u32 *)&msg->corrs[msgcorrs_idx].Q;
    msgcorrsmsgcorrs_idxQ = le32toh(msgcorrsmsgcorrs_idxQ);
    msg->corrs[msgcorrs_idx].Q = *(const s32 *)&msgcorrsmsgcorrs_idxQ;
    // NOLINTNEXTLINE
    offset += 4;
  }
  return true;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_tracking_iq_dep_a_t &a, const sbp_msg_tracking_iq_dep_a_t &b)
{
  (void)a;
  (void)b;

  if (a.channel != b.channel)
  {
    return false;
  }

  if (a.sid.sat != b.sid.sat)
  {
    return false;
  }

  if (a.sid.code != b.sid.code)
  {
    return false;
  }

  if (a.sid.reserved != b.sid.reserved)
  {
    return false;
  }
  for (size_t corrs_idx = 0; corrs_idx < 3; corrs_idx++)
  {

    if (a.corrs[corrs_idx].I != b.corrs[corrs_idx].I)
    {
      return false;
    }

    if (a.corrs[corrs_idx].Q != b.corrs[corrs_idx].Q)
    {
      return false;
    }
  }

  return true;
}

static inline bool operator!=(const sbp_msg_tracking_iq_dep_a_t &a, const sbp_msg_tracking_iq_dep_a_t &b)
{
  return !(a == b);
}
#endif
/** Deprecated
 *
 * Deprecated.
 */
#define SBP_MSG_TRACKING_STATE_DEP_A 0x0016

#define SBP_TRACKING_STATE_DEP_A_STATES_STATE_TRACKING_MODE_MASK (0x3)
#define SBP_TRACKING_STATE_DEP_A_STATES_STATE_TRACKING_MODE_SHIFT (0u)
#define SBP_TRACKING_STATE_DEP_A_STATES_STATE_TRACKING_MODE_GET(flags) \
  (((flags) >> SBP_TRACKING_STATE_DEP_A_STATES_STATE_TRACKING_MODE_SHIFT) & \
   SBP_TRACKING_STATE_DEP_A_STATES_STATE_TRACKING_MODE_MASK)
#define SBP_TRACKING_STATE_DEP_A_STATES_STATE_TRACKING_MODE_SET(flags, val) \
  do \
  { \
    ((flags) |= (((val) & (SBP_TRACKING_STATE_DEP_A_STATES_STATE_TRACKING_MODE_MASK)) \
                 << (SBP_TRACKING_STATE_DEP_A_STATES_STATE_TRACKING_MODE_SHIFT))); \
  } while (0)

#define SBP_TRACKING_STATE_DEP_A_STATES_STATE_TRACKING_MODE_DISABLED (0)
#define SBP_TRACKING_STATE_DEP_A_STATES_STATE_TRACKING_MODE_RUNNING (1)
typedef struct
{

  /**
   * Satellite tracking channel state
   */
  struct
  {

    /**
     * Status of tracking channel
     */
    u8 state;
    /**
     * PRN-1 being tracked
     */
    u8 prn;
    /**
     * Carrier-to-noise density[dB Hz]
     */
    float cn0;
  } states[42];
  /**
   * Number of items in states
   */
  u8 n_states;
} sbp_msg_tracking_state_dep_a_t;

static inline size_t sbp_packed_size_sbp_msg_tracking_state_dep_a_t(const sbp_msg_tracking_state_dep_a_t *msg)
{
  (void)msg;
  return 0 +
         (msg->n_states * (0 + sizeof(msg->states[0].state) + sizeof(msg->states[0].prn) + sizeof(msg->states[0].cn0)));
}

static inline bool
sbp_pack_sbp_msg_tracking_state_dep_a_t(u8 *buf, size_t len, const sbp_msg_tracking_state_dep_a_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_tracking_state_dep_a_t(msg) > len)
  {
    return false;
  }

  for (size_t msgstates_idx = 0; msgstates_idx < (size_t)msg->n_states; msgstates_idx++)
  {

    if (offset + 1 > len)
    {
      return false;
    }
    u8 msgstatesmsgstates_idxstate = msg->states[msgstates_idx].state;
    memcpy(buf + offset, &msgstatesmsgstates_idxstate, 1);
    // NOLINTNEXTLINE
    offset += 1;

    if (offset + 1 > len)
    {
      return false;
    }
    u8 msgstatesmsgstates_idxprn = msg->states[msgstates_idx].prn;
    memcpy(buf + offset, &msgstatesmsgstates_idxprn, 1);
    // NOLINTNEXTLINE
    offset += 1;

    if (offset + 4 > len)
    {
      return false;
    }
    float msgstatesmsgstates_idxcn0 = msg->states[msgstates_idx].cn0;
    memcpy(buf + offset, &msgstatesmsgstates_idxcn0, 4);
    // NOLINTNEXTLINE
    offset += 4;
  }
  return true;
}

static inline bool
sbp_unpack_sbp_msg_tracking_state_dep_a_t(const u8 *buf, size_t len, sbp_msg_tracking_state_dep_a_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  msg->n_states = (u8)((len - offset) / 6);

  for (size_t msgstates_idx = 0; msgstates_idx < msg->n_states; msgstates_idx++)
  {

    if (offset + 1 > len)
    {
      return false;
    }
    memcpy(&msg->states[msgstates_idx].state, buf + offset, 1);
    // NOLINTNEXTLINE
    offset += 1;

    if (offset + 1 > len)
    {
      return false;
    }
    memcpy(&msg->states[msgstates_idx].prn, buf + offset, 1);
    // NOLINTNEXTLINE
    offset += 1;

    if (offset + 4 > len)
    {
      return false;
    }
    memcpy(&msg->states[msgstates_idx].cn0, buf + offset, 4);
    // NOLINTNEXTLINE
    offset += 4;
  }
  return true;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_tracking_state_dep_a_t &a, const sbp_msg_tracking_state_dep_a_t &b)
{
  (void)a;
  (void)b;

  if (a.n_states != b.n_states)
  {
    return false;
  }
  for (size_t states_idx = 0; states_idx < (size_t)a.n_states; states_idx++)
  {

    if (a.states[states_idx].state != b.states[states_idx].state)
    {
      return false;
    }

    if (a.states[states_idx].prn != b.states[states_idx].prn)
    {
      return false;
    }

    if (fabs(a.states[states_idx].cn0 - b.states[states_idx].cn0) > 0.001)
    {
      return false;
    }
  }

  return true;
}

static inline bool operator!=(const sbp_msg_tracking_state_dep_a_t &a, const sbp_msg_tracking_state_dep_a_t &b)
{
  return !(a == b);
}
#endif
/** Deprecated.
 *
 * Deprecated.
 */
#define SBP_MSG_TRACKING_STATE_DEP_B 0x0013

#define SBP_TRACKING_STATE_DEP_B_STATES_STATE_TRACKING_MODE_MASK (0x3)
#define SBP_TRACKING_STATE_DEP_B_STATES_STATE_TRACKING_MODE_SHIFT (0u)
#define SBP_TRACKING_STATE_DEP_B_STATES_STATE_TRACKING_MODE_GET(flags) \
  (((flags) >> SBP_TRACKING_STATE_DEP_B_STATES_STATE_TRACKING_MODE_SHIFT) & \
   SBP_TRACKING_STATE_DEP_B_STATES_STATE_TRACKING_MODE_MASK)
#define SBP_TRACKING_STATE_DEP_B_STATES_STATE_TRACKING_MODE_SET(flags, val) \
  do \
  { \
    ((flags) |= (((val) & (SBP_TRACKING_STATE_DEP_B_STATES_STATE_TRACKING_MODE_MASK)) \
                 << (SBP_TRACKING_STATE_DEP_B_STATES_STATE_TRACKING_MODE_SHIFT))); \
  } while (0)

#define SBP_TRACKING_STATE_DEP_B_STATES_STATE_TRACKING_MODE_DISABLED (0)
#define SBP_TRACKING_STATE_DEP_B_STATES_STATE_TRACKING_MODE_RUNNING (1)

#define SBP_TRACKING_STATE_DEP_B_STATES_SID_CODE__MASK (0xff)
#define SBP_TRACKING_STATE_DEP_B_STATES_SID_CODE__SHIFT (0u)
#define SBP_TRACKING_STATE_DEP_B_STATES_SID_CODE__GET(flags) \
  (((flags) >> SBP_TRACKING_STATE_DEP_B_STATES_SID_CODE__SHIFT) & SBP_TRACKING_STATE_DEP_B_STATES_SID_CODE__MASK)
#define SBP_TRACKING_STATE_DEP_B_STATES_SID_CODE__SET(flags, val) \
  do \
  { \
    ((flags) |= (((val) & (SBP_TRACKING_STATE_DEP_B_STATES_SID_CODE__MASK)) \
                 << (SBP_TRACKING_STATE_DEP_B_STATES_SID_CODE__SHIFT))); \
  } while (0)

#define SBP_TRACKING_STATE_DEP_B_STATES_SID_CODE__GPS_L1CA (0)
#define SBP_TRACKING_STATE_DEP_B_STATES_SID_CODE__GPS_L2CM (1)
#define SBP_TRACKING_STATE_DEP_B_STATES_SID_CODE__SBAS_L1CA (2)
#define SBP_TRACKING_STATE_DEP_B_STATES_SID_CODE__GLO_L1CA (3)
#define SBP_TRACKING_STATE_DEP_B_STATES_SID_CODE__GLO_L2CA (4)
#define SBP_TRACKING_STATE_DEP_B_STATES_SID_CODE__GPS_L1P (5)
#define SBP_TRACKING_STATE_DEP_B_STATES_SID_CODE__GPS_L2P (6)
typedef struct
{

  /**
   * Signal tracking channel state
   */
  struct
  {

    /**
     * Status of tracking channel
     */
    u8 state;
    /**
     * GNSS signal being tracked
     */
    struct
    {

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
    } sid;
    /**
     * Carrier-to-noise density[dB Hz]
     */
    float cn0;
  } states[28];
  /**
   * Number of items in states
   */
  u8 n_states;
} sbp_msg_tracking_state_dep_b_t;

static inline size_t sbp_packed_size_sbp_msg_tracking_state_dep_b_t(const sbp_msg_tracking_state_dep_b_t *msg)
{
  (void)msg;
  return 0 + (msg->n_states * (0 + sizeof(msg->states[0].state) +
                               (0 + sizeof(msg->states[0].sid.sat) + sizeof(msg->states[0].sid.code) +
                                sizeof(msg->states[0].sid.reserved)) +
                               sizeof(msg->states[0].cn0)));
}

static inline bool
sbp_pack_sbp_msg_tracking_state_dep_b_t(u8 *buf, size_t len, const sbp_msg_tracking_state_dep_b_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_tracking_state_dep_b_t(msg) > len)
  {
    return false;
  }

  for (size_t msgstates_idx = 0; msgstates_idx < (size_t)msg->n_states; msgstates_idx++)
  {

    if (offset + 1 > len)
    {
      return false;
    }
    u8 msgstatesmsgstates_idxstate = msg->states[msgstates_idx].state;
    memcpy(buf + offset, &msgstatesmsgstates_idxstate, 1);
    // NOLINTNEXTLINE
    offset += 1;

    if (offset + 2 > len)
    {
      return false;
    }
    u16 msgstatesmsgstates_idxsidsat = htole16(msg->states[msgstates_idx].sid.sat);
    memcpy(buf + offset, &msgstatesmsgstates_idxsidsat, 2);
    // NOLINTNEXTLINE
    offset += 2;

    if (offset + 1 > len)
    {
      return false;
    }
    u8 msgstatesmsgstates_idxsidcode = msg->states[msgstates_idx].sid.code;
    memcpy(buf + offset, &msgstatesmsgstates_idxsidcode, 1);
    // NOLINTNEXTLINE
    offset += 1;

    if (offset + 1 > len)
    {
      return false;
    }
    u8 msgstatesmsgstates_idxsidreserved = msg->states[msgstates_idx].sid.reserved;
    memcpy(buf + offset, &msgstatesmsgstates_idxsidreserved, 1);
    // NOLINTNEXTLINE
    offset += 1;

    if (offset + 4 > len)
    {
      return false;
    }
    float msgstatesmsgstates_idxcn0 = msg->states[msgstates_idx].cn0;
    memcpy(buf + offset, &msgstatesmsgstates_idxcn0, 4);
    // NOLINTNEXTLINE
    offset += 4;
  }
  return true;
}

static inline bool
sbp_unpack_sbp_msg_tracking_state_dep_b_t(const u8 *buf, size_t len, sbp_msg_tracking_state_dep_b_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  msg->n_states = (u8)((len - offset) / 9);

  for (size_t msgstates_idx = 0; msgstates_idx < msg->n_states; msgstates_idx++)
  {

    if (offset + 1 > len)
    {
      return false;
    }
    memcpy(&msg->states[msgstates_idx].state, buf + offset, 1);
    // NOLINTNEXTLINE
    offset += 1;

    if (offset + 2 > len)
    {
      return false;
    }
    memcpy(&msg->states[msgstates_idx].sid.sat, buf + offset, 2);
    msg->states[msgstates_idx].sid.sat = le16toh(msg->states[msgstates_idx].sid.sat);
    // NOLINTNEXTLINE
    offset += 2;

    if (offset + 1 > len)
    {
      return false;
    }
    memcpy(&msg->states[msgstates_idx].sid.code, buf + offset, 1);
    // NOLINTNEXTLINE
    offset += 1;

    if (offset + 1 > len)
    {
      return false;
    }
    memcpy(&msg->states[msgstates_idx].sid.reserved, buf + offset, 1);
    // NOLINTNEXTLINE
    offset += 1;

    if (offset + 4 > len)
    {
      return false;
    }
    memcpy(&msg->states[msgstates_idx].cn0, buf + offset, 4);
    // NOLINTNEXTLINE
    offset += 4;
  }
  return true;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_tracking_state_dep_b_t &a, const sbp_msg_tracking_state_dep_b_t &b)
{
  (void)a;
  (void)b;

  if (a.n_states != b.n_states)
  {
    return false;
  }
  for (size_t states_idx = 0; states_idx < (size_t)a.n_states; states_idx++)
  {

    if (a.states[states_idx].state != b.states[states_idx].state)
    {
      return false;
    }

    if (a.states[states_idx].sid.sat != b.states[states_idx].sid.sat)
    {
      return false;
    }

    if (a.states[states_idx].sid.code != b.states[states_idx].sid.code)
    {
      return false;
    }

    if (a.states[states_idx].sid.reserved != b.states[states_idx].sid.reserved)
    {
      return false;
    }

    if (fabs(a.states[states_idx].cn0 - b.states[states_idx].cn0) > 0.001)
    {
      return false;
    }
  }

  return true;
}

static inline bool operator!=(const sbp_msg_tracking_state_dep_b_t &a, const sbp_msg_tracking_state_dep_b_t &b)
{
  return !(a == b);
}
#endif

#endif /* LIBSBP_TRACKING_MESSAGES_H */