#ifndef LIBSBP_TRACKING_MESSAGES_H
#define LIBSBP_TRACKING_MESSAGES_H

#include "common.h"
#include "gnss.h"

SBP_PACK_START
/** Detailed signal tracking channel states. DEPRECATED.
 *
 * The tracking message returns a set tracking channel parameters for a
 * single tracking channel useful for debugging issues.
 */
#define SBP_MSG_TRACKING_STATE_DETAILED_DEP_A 0x0021

#define SBP_TRACKING_STATE_DETAILED_DEP_A_SID_CODE__MASK (0xff)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_SID_CODE__SHIFT (0u)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_SID_CODE__GET(flags)      \
  (((flags) >> SBP_TRACKING_STATE_DETAILED_DEP_A_SID_CODE__SHIFT) & \
   SBP_TRACKING_STATE_DETAILED_DEP_A_SID_CODE__MASK)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_SID_CODE__SET(flags, val)           \
  do {                                                                        \
    ((flags) |= (((val) & (SBP_TRACKING_STATE_DETAILED_DEP_A_SID_CODE__MASK)) \
                 << (SBP_TRACKING_STATE_DETAILED_DEP_A_SID_CODE__SHIFT)));    \
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
#define SBP_TRACKING_STATE_DETAILED_DEP_A_SYNC_FLAGS_SYNCHRONIZATION_STATUS_MASK \
  (0x7)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_SYNC_FLAGS_SYNCHRONIZATION_STATUS_SHIFT \
  (0u)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_SYNC_FLAGS_SYNCHRONIZATION_STATUS_GET( \
    flags)                                                                       \
  (((flags) >>                                                                   \
    SBP_TRACKING_STATE_DETAILED_DEP_A_SYNC_FLAGS_SYNCHRONIZATION_STATUS_SHIFT) & \
   SBP_TRACKING_STATE_DETAILED_DEP_A_SYNC_FLAGS_SYNCHRONIZATION_STATUS_MASK)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_SYNC_FLAGS_SYNCHRONIZATION_STATUS_SET(        \
    flags, val)                                                                         \
  do {                                                                                  \
    ((flags) |=                                                                         \
     (((val) &                                                                          \
       (SBP_TRACKING_STATE_DETAILED_DEP_A_SYNC_FLAGS_SYNCHRONIZATION_STATUS_MASK))      \
      << (SBP_TRACKING_STATE_DETAILED_DEP_A_SYNC_FLAGS_SYNCHRONIZATION_STATUS_SHIFT))); \
  } while (0)

#define SBP_TRACKING_STATE_DETAILED_DEP_A_SYNC_FLAGS_SYNCHRONIZATION_STATUS_NO_SYNCHRONIZATION \
  (0)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_SYNC_FLAGS_SYNCHRONIZATION_STATUS_BIT_SYNCHRONIZATION \
  (1)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_SYNC_FLAGS_SYNCHRONIZATION_STATUS_WORD_SYNCHRONIZATION \
  (2)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_SYNC_FLAGS_SYNCHRONIZATION_STATUS_SUB_FRAME_SYNCHRONIZATION_MESSAGE_SYNCHRONIZATION \
  (3)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_TOW_FLAGS_WEEK_NUMBER_VALIDITY_STATUS_MASK \
  (0x1)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_TOW_FLAGS_WEEK_NUMBER_VALIDITY_STATUS_SHIFT \
  (3u)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_TOW_FLAGS_WEEK_NUMBER_VALIDITY_STATUS_GET( \
    flags)                                                                           \
  (((flags) >>                                                                       \
    SBP_TRACKING_STATE_DETAILED_DEP_A_TOW_FLAGS_WEEK_NUMBER_VALIDITY_STATUS_SHIFT) & \
   SBP_TRACKING_STATE_DETAILED_DEP_A_TOW_FLAGS_WEEK_NUMBER_VALIDITY_STATUS_MASK)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_TOW_FLAGS_WEEK_NUMBER_VALIDITY_STATUS_SET(        \
    flags, val)                                                                             \
  do {                                                                                      \
    ((flags) |=                                                                             \
     (((val) &                                                                              \
       (SBP_TRACKING_STATE_DETAILED_DEP_A_TOW_FLAGS_WEEK_NUMBER_VALIDITY_STATUS_MASK))      \
      << (SBP_TRACKING_STATE_DETAILED_DEP_A_TOW_FLAGS_WEEK_NUMBER_VALIDITY_STATUS_SHIFT))); \
  } while (0)

#define SBP_TRACKING_STATE_DETAILED_DEP_A_TOW_FLAGS_WEEK_NUMBER_VALIDITY_STATUS_WEEK_NUMBER_IS_NOT_VALID \
  (0)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_TOW_FLAGS_WEEK_NUMBER_VALIDITY_STATUS_WEEK_NUMBER_IS_VALID \
  (1)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_TOW_FLAGS_TOW_STATUS_MASK (0x7)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_TOW_FLAGS_TOW_STATUS_SHIFT (0u)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_TOW_FLAGS_TOW_STATUS_GET(flags)      \
  (((flags) >> SBP_TRACKING_STATE_DETAILED_DEP_A_TOW_FLAGS_TOW_STATUS_SHIFT) & \
   SBP_TRACKING_STATE_DETAILED_DEP_A_TOW_FLAGS_TOW_STATUS_MASK)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_TOW_FLAGS_TOW_STATUS_SET(flags, val) \
  do {                                                                         \
    ((flags) |=                                                                \
     (((val) & (SBP_TRACKING_STATE_DETAILED_DEP_A_TOW_FLAGS_TOW_STATUS_MASK))  \
      << (SBP_TRACKING_STATE_DETAILED_DEP_A_TOW_FLAGS_TOW_STATUS_SHIFT)));     \
  } while (0)

#define SBP_TRACKING_STATE_DETAILED_DEP_A_TOW_FLAGS_TOW_STATUS_TOW_IS_NOT_AVAILABLE \
  (0)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_TOW_FLAGS_TOW_STATUS_DECODED_TOW_IS_AVAILABLE \
  (1)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_TOW_FLAGS_TOW_STATUS_PROPAGATED_TOW_IS_AVAILABLE \
  (2)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_TRACK_FLAGS_FLL_STATUS_MASK (0x1)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_TRACK_FLAGS_FLL_STATUS_SHIFT (4u)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_TRACK_FLAGS_FLL_STATUS_GET(flags) \
  (((flags) >>                                                              \
    SBP_TRACKING_STATE_DETAILED_DEP_A_TRACK_FLAGS_FLL_STATUS_SHIFT) &       \
   SBP_TRACKING_STATE_DETAILED_DEP_A_TRACK_FLAGS_FLL_STATUS_MASK)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_TRACK_FLAGS_FLL_STATUS_SET(flags,  \
                                                                     val)    \
  do {                                                                       \
    ((flags) |=                                                              \
     (((val) &                                                               \
       (SBP_TRACKING_STATE_DETAILED_DEP_A_TRACK_FLAGS_FLL_STATUS_MASK))      \
      << (SBP_TRACKING_STATE_DETAILED_DEP_A_TRACK_FLAGS_FLL_STATUS_SHIFT))); \
  } while (0)

#define SBP_TRACKING_STATE_DETAILED_DEP_A_TRACK_FLAGS_FLL_STATUS_FLL_IS_INACTIVE \
  (0)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_TRACK_FLAGS_FLL_STATUS_FLL_IS_ACTIVE \
  (1)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_TRACK_FLAGS_PLL_STATUS_MASK (0x1)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_TRACK_FLAGS_PLL_STATUS_SHIFT (3u)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_TRACK_FLAGS_PLL_STATUS_GET(flags) \
  (((flags) >>                                                              \
    SBP_TRACKING_STATE_DETAILED_DEP_A_TRACK_FLAGS_PLL_STATUS_SHIFT) &       \
   SBP_TRACKING_STATE_DETAILED_DEP_A_TRACK_FLAGS_PLL_STATUS_MASK)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_TRACK_FLAGS_PLL_STATUS_SET(flags,  \
                                                                     val)    \
  do {                                                                       \
    ((flags) |=                                                              \
     (((val) &                                                               \
       (SBP_TRACKING_STATE_DETAILED_DEP_A_TRACK_FLAGS_PLL_STATUS_MASK))      \
      << (SBP_TRACKING_STATE_DETAILED_DEP_A_TRACK_FLAGS_PLL_STATUS_SHIFT))); \
  } while (0)

#define SBP_TRACKING_STATE_DETAILED_DEP_A_TRACK_FLAGS_PLL_STATUS_PLL_IS_INACTIVE \
  (0)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_TRACK_FLAGS_PLL_STATUS_PLL_IS_ACTIVE \
  (1)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_TRACK_FLAGS_TRACKING_LOOP_STATUS_MASK \
  (0x7)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_TRACK_FLAGS_TRACKING_LOOP_STATUS_SHIFT \
  (0u)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_TRACK_FLAGS_TRACKING_LOOP_STATUS_GET( \
    flags)                                                                      \
  (((flags) >>                                                                  \
    SBP_TRACKING_STATE_DETAILED_DEP_A_TRACK_FLAGS_TRACKING_LOOP_STATUS_SHIFT) & \
   SBP_TRACKING_STATE_DETAILED_DEP_A_TRACK_FLAGS_TRACKING_LOOP_STATUS_MASK)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_TRACK_FLAGS_TRACKING_LOOP_STATUS_SET(        \
    flags, val)                                                                        \
  do {                                                                                 \
    ((flags) |=                                                                        \
     (((val) &                                                                         \
       (SBP_TRACKING_STATE_DETAILED_DEP_A_TRACK_FLAGS_TRACKING_LOOP_STATUS_MASK))      \
      << (SBP_TRACKING_STATE_DETAILED_DEP_A_TRACK_FLAGS_TRACKING_LOOP_STATUS_SHIFT))); \
  } while (0)

#define SBP_TRACKING_STATE_DETAILED_DEP_A_TRACK_FLAGS_TRACKING_LOOP_STATUS_NO_LOCKS \
  (0)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_TRACK_FLAGS_TRACKING_LOOP_STATUS_FLLDLL_LOCK \
  (1)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_TRACK_FLAGS_TRACKING_LOOP_STATUS_PLL_OPTIMISTIC_LOCK \
  (2)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_TRACK_FLAGS_TRACKING_LOOP_STATUS_PLL_PESSIMISTIC_LOCK \
  (3)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_NAV_FLAGS_ALMANAC_AVAILABILITY_STATUS_MASK \
  (0x1)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_NAV_FLAGS_ALMANAC_AVAILABILITY_STATUS_SHIFT \
  (4u)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_NAV_FLAGS_ALMANAC_AVAILABILITY_STATUS_GET( \
    flags)                                                                           \
  (((flags) >>                                                                       \
    SBP_TRACKING_STATE_DETAILED_DEP_A_NAV_FLAGS_ALMANAC_AVAILABILITY_STATUS_SHIFT) & \
   SBP_TRACKING_STATE_DETAILED_DEP_A_NAV_FLAGS_ALMANAC_AVAILABILITY_STATUS_MASK)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_NAV_FLAGS_ALMANAC_AVAILABILITY_STATUS_SET(        \
    flags, val)                                                                             \
  do {                                                                                      \
    ((flags) |=                                                                             \
     (((val) &                                                                              \
       (SBP_TRACKING_STATE_DETAILED_DEP_A_NAV_FLAGS_ALMANAC_AVAILABILITY_STATUS_MASK))      \
      << (SBP_TRACKING_STATE_DETAILED_DEP_A_NAV_FLAGS_ALMANAC_AVAILABILITY_STATUS_SHIFT))); \
  } while (0)

#define SBP_TRACKING_STATE_DETAILED_DEP_A_NAV_FLAGS_ALMANAC_AVAILABILITY_STATUS_ALMANAC_IS_NOT_AVAILABLE \
  (0)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_NAV_FLAGS_ALMANAC_AVAILABILITY_STATUS_ALMANAC_IS_AVAILABLE \
  (1)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_NAV_FLAGS_EPHEMERIS_AVAILABILITY_STATUS_MASK \
  (0x1)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_NAV_FLAGS_EPHEMERIS_AVAILABILITY_STATUS_SHIFT \
  (3u)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_NAV_FLAGS_EPHEMERIS_AVAILABILITY_STATUS_GET( \
    flags)                                                                             \
  (((flags) >>                                                                         \
    SBP_TRACKING_STATE_DETAILED_DEP_A_NAV_FLAGS_EPHEMERIS_AVAILABILITY_STATUS_SHIFT) & \
   SBP_TRACKING_STATE_DETAILED_DEP_A_NAV_FLAGS_EPHEMERIS_AVAILABILITY_STATUS_MASK)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_NAV_FLAGS_EPHEMERIS_AVAILABILITY_STATUS_SET(        \
    flags, val)                                                                               \
  do {                                                                                        \
    ((flags) |=                                                                               \
     (((val) &                                                                                \
       (SBP_TRACKING_STATE_DETAILED_DEP_A_NAV_FLAGS_EPHEMERIS_AVAILABILITY_STATUS_MASK))      \
      << (SBP_TRACKING_STATE_DETAILED_DEP_A_NAV_FLAGS_EPHEMERIS_AVAILABILITY_STATUS_SHIFT))); \
  } while (0)

#define SBP_TRACKING_STATE_DETAILED_DEP_A_NAV_FLAGS_EPHEMERIS_AVAILABILITY_STATUS_EPHEMERIS_IS_NOT_AVAILABLE \
  (0)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_NAV_FLAGS_EPHEMERIS_AVAILABILITY_STATUS_EPHEMERIS_IS_AVAILABLE \
  (1)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_NAV_FLAGS_HEALTH_STATUS_MASK (0x7)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_NAV_FLAGS_HEALTH_STATUS_SHIFT (0u)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_NAV_FLAGS_HEALTH_STATUS_GET(flags) \
  (((flags) >>                                                               \
    SBP_TRACKING_STATE_DETAILED_DEP_A_NAV_FLAGS_HEALTH_STATUS_SHIFT) &       \
   SBP_TRACKING_STATE_DETAILED_DEP_A_NAV_FLAGS_HEALTH_STATUS_MASK)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_NAV_FLAGS_HEALTH_STATUS_SET(flags,  \
                                                                      val)    \
  do {                                                                        \
    ((flags) |=                                                               \
     (((val) &                                                                \
       (SBP_TRACKING_STATE_DETAILED_DEP_A_NAV_FLAGS_HEALTH_STATUS_MASK))      \
      << (SBP_TRACKING_STATE_DETAILED_DEP_A_NAV_FLAGS_HEALTH_STATUS_SHIFT))); \
  } while (0)

#define SBP_TRACKING_STATE_DETAILED_DEP_A_NAV_FLAGS_HEALTH_STATUS_HEALTH_IS_UNKNOWN \
  (0)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_NAV_FLAGS_HEALTH_STATUS_SIGNAL_IS_UNHEALTHY \
  (1)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_NAV_FLAGS_HEALTH_STATUS_SIGNAL_IS_HEALTHY \
  (2)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_PSET_FLAGS_PARAMETER_SETS_MASK (0x7)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_PSET_FLAGS_PARAMETER_SETS_SHIFT (0u)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_PSET_FLAGS_PARAMETER_SETS_GET(flags) \
  (((flags) >>                                                                 \
    SBP_TRACKING_STATE_DETAILED_DEP_A_PSET_FLAGS_PARAMETER_SETS_SHIFT) &       \
   SBP_TRACKING_STATE_DETAILED_DEP_A_PSET_FLAGS_PARAMETER_SETS_MASK)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_PSET_FLAGS_PARAMETER_SETS_SET(flags,  \
                                                                        val)    \
  do {                                                                          \
    ((flags) |=                                                                 \
     (((val) &                                                                  \
       (SBP_TRACKING_STATE_DETAILED_DEP_A_PSET_FLAGS_PARAMETER_SETS_MASK))      \
      << (SBP_TRACKING_STATE_DETAILED_DEP_A_PSET_FLAGS_PARAMETER_SETS_SHIFT))); \
  } while (0)

#define SBP_TRACKING_STATE_DETAILED_DEP_A_PSET_FLAGS_PARAMETER_SETS_1_MS_INTEGRATION_TIME \
  (0)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_PSET_FLAGS_PARAMETER_SETS_5_MS_INTEGRATION_TIME \
  (1)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_PSET_FLAGS_PARAMETER_SETS_10_MS_INTEGRATION_TIME \
  (2)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_PSET_FLAGS_PARAMETER_SETS_20_MS_INTEGRATION_TIME \
  (3)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_MISC_FLAGS_CLOCK_VALIDITY_STATUS_MASK \
  (0x1)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_MISC_FLAGS_CLOCK_VALIDITY_STATUS_SHIFT \
  (5u)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_MISC_FLAGS_CLOCK_VALIDITY_STATUS_GET( \
    flags)                                                                      \
  (((flags) >>                                                                  \
    SBP_TRACKING_STATE_DETAILED_DEP_A_MISC_FLAGS_CLOCK_VALIDITY_STATUS_SHIFT) & \
   SBP_TRACKING_STATE_DETAILED_DEP_A_MISC_FLAGS_CLOCK_VALIDITY_STATUS_MASK)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_MISC_FLAGS_CLOCK_VALIDITY_STATUS_SET(        \
    flags, val)                                                                        \
  do {                                                                                 \
    ((flags) |=                                                                        \
     (((val) &                                                                         \
       (SBP_TRACKING_STATE_DETAILED_DEP_A_MISC_FLAGS_CLOCK_VALIDITY_STATUS_MASK))      \
      << (SBP_TRACKING_STATE_DETAILED_DEP_A_MISC_FLAGS_CLOCK_VALIDITY_STATUS_SHIFT))); \
  } while (0)

#define SBP_TRACKING_STATE_DETAILED_DEP_A_MISC_FLAGS_CLOCK_VALIDITY_STATUS_CLOCK_OFFSET_AND_DRIFT_IS_NOT_VALID \
  (0)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_MISC_FLAGS_CLOCK_VALIDITY_STATUS_CLOCK_OFFSET_AND_DRIFT_IS_VALID \
  (1)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_MISC_FLAGS_PSEUDORANGE_VALIDITY_STATUS_MASK \
  (0x1)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_MISC_FLAGS_PSEUDORANGE_VALIDITY_STATUS_SHIFT \
  (4u)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_MISC_FLAGS_PSEUDORANGE_VALIDITY_STATUS_GET( \
    flags)                                                                            \
  (((flags) >>                                                                        \
    SBP_TRACKING_STATE_DETAILED_DEP_A_MISC_FLAGS_PSEUDORANGE_VALIDITY_STATUS_SHIFT) & \
   SBP_TRACKING_STATE_DETAILED_DEP_A_MISC_FLAGS_PSEUDORANGE_VALIDITY_STATUS_MASK)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_MISC_FLAGS_PSEUDORANGE_VALIDITY_STATUS_SET(        \
    flags, val)                                                                              \
  do {                                                                                       \
    ((flags) |=                                                                              \
     (((val) &                                                                               \
       (SBP_TRACKING_STATE_DETAILED_DEP_A_MISC_FLAGS_PSEUDORANGE_VALIDITY_STATUS_MASK))      \
      << (SBP_TRACKING_STATE_DETAILED_DEP_A_MISC_FLAGS_PSEUDORANGE_VALIDITY_STATUS_SHIFT))); \
  } while (0)

#define SBP_TRACKING_STATE_DETAILED_DEP_A_MISC_FLAGS_PSEUDORANGE_VALIDITY_STATUS_PSEUDORANGE_IS_NOT_VALID \
  (0)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_MISC_FLAGS_PSEUDORANGE_VALIDITY_STATUS_PSEUDORANGE_IS_VALID \
  (1)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_MISC_FLAGS_ACCELERATION_VALIDITY_STATUS_MASK \
  (0x1)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_MISC_FLAGS_ACCELERATION_VALIDITY_STATUS_SHIFT \
  (3u)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_MISC_FLAGS_ACCELERATION_VALIDITY_STATUS_GET( \
    flags)                                                                             \
  (((flags) >>                                                                         \
    SBP_TRACKING_STATE_DETAILED_DEP_A_MISC_FLAGS_ACCELERATION_VALIDITY_STATUS_SHIFT) & \
   SBP_TRACKING_STATE_DETAILED_DEP_A_MISC_FLAGS_ACCELERATION_VALIDITY_STATUS_MASK)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_MISC_FLAGS_ACCELERATION_VALIDITY_STATUS_SET(        \
    flags, val)                                                                               \
  do {                                                                                        \
    ((flags) |=                                                                               \
     (((val) &                                                                                \
       (SBP_TRACKING_STATE_DETAILED_DEP_A_MISC_FLAGS_ACCELERATION_VALIDITY_STATUS_MASK))      \
      << (SBP_TRACKING_STATE_DETAILED_DEP_A_MISC_FLAGS_ACCELERATION_VALIDITY_STATUS_SHIFT))); \
  } while (0)

#define SBP_TRACKING_STATE_DETAILED_DEP_A_MISC_FLAGS_ACCELERATION_VALIDITY_STATUS_ACCELERATION_IS_NOT_VALID \
  (0)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_MISC_FLAGS_ACCELERATION_VALIDITY_STATUS_ACCELERATION_IS_VALID \
  (1)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_MISC_FLAGS_CARRIER_HALF_CYCLE_AMBIGUITY_STATUS_MASK \
  (0x1)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_MISC_FLAGS_CARRIER_HALF_CYCLE_AMBIGUITY_STATUS_SHIFT \
  (2u)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_MISC_FLAGS_CARRIER_HALF_CYCLE_AMBIGUITY_STATUS_GET( \
    flags)                                                                                    \
  (((flags) >>                                                                                \
    SBP_TRACKING_STATE_DETAILED_DEP_A_MISC_FLAGS_CARRIER_HALF_CYCLE_AMBIGUITY_STATUS_SHIFT) & \
   SBP_TRACKING_STATE_DETAILED_DEP_A_MISC_FLAGS_CARRIER_HALF_CYCLE_AMBIGUITY_STATUS_MASK)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_MISC_FLAGS_CARRIER_HALF_CYCLE_AMBIGUITY_STATUS_SET(        \
    flags, val)                                                                                      \
  do {                                                                                               \
    ((flags) |=                                                                                      \
     (((val) &                                                                                       \
       (SBP_TRACKING_STATE_DETAILED_DEP_A_MISC_FLAGS_CARRIER_HALF_CYCLE_AMBIGUITY_STATUS_MASK))      \
      << (SBP_TRACKING_STATE_DETAILED_DEP_A_MISC_FLAGS_CARRIER_HALF_CYCLE_AMBIGUITY_STATUS_SHIFT))); \
  } while (0)

#define SBP_TRACKING_STATE_DETAILED_DEP_A_MISC_FLAGS_CARRIER_HALF_CYCLE_AMBIGUITY_STATUS_UNRESOLVED \
  (0)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_MISC_FLAGS_CARRIER_HALF_CYCLE_AMBIGUITY_STATUS_RESOLVED \
  (1)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_MISC_FLAGS_TRACKING_CHANNEL_STATUS_MASK \
  (0x3)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_MISC_FLAGS_TRACKING_CHANNEL_STATUS_SHIFT \
  (0u)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_MISC_FLAGS_TRACKING_CHANNEL_STATUS_GET( \
    flags)                                                                        \
  (((flags) >>                                                                    \
    SBP_TRACKING_STATE_DETAILED_DEP_A_MISC_FLAGS_TRACKING_CHANNEL_STATUS_SHIFT) & \
   SBP_TRACKING_STATE_DETAILED_DEP_A_MISC_FLAGS_TRACKING_CHANNEL_STATUS_MASK)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_MISC_FLAGS_TRACKING_CHANNEL_STATUS_SET(        \
    flags, val)                                                                          \
  do {                                                                                   \
    ((flags) |=                                                                          \
     (((val) &                                                                           \
       (SBP_TRACKING_STATE_DETAILED_DEP_A_MISC_FLAGS_TRACKING_CHANNEL_STATUS_MASK))      \
      << (SBP_TRACKING_STATE_DETAILED_DEP_A_MISC_FLAGS_TRACKING_CHANNEL_STATUS_SHIFT))); \
  } while (0)

#define SBP_TRACKING_STATE_DETAILED_DEP_A_MISC_FLAGS_TRACKING_CHANNEL_STATUS_RE_ACQUISITION \
  (0)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_MISC_FLAGS_TRACKING_CHANNEL_STATUS_RUNNING \
  (1)
typedef struct SBP_ATTR_PACKED {
  /**
   * Receiver clock time.[ns]
   */
  u64 recv_time;
  /**
   * Time of transmission of signal from satellite. TOW only valid when
   * TOW status is decoded or propagated. WN only valid when week
   * number valid flag is set.
   */
  struct SBP_ATTR_PACKED {
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
  struct SBP_ATTR_PACKED {
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
  struct SBP_ATTR_PACKED {
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
   * TCXO clock offset. Valid only when valid clock valid flag is set.[s / (2 ^
   * 20)]
   */
  s16 clock_offset;
  /**
   * TCXO clock drift. Valid only when valid clock valid flag is set.[(s / s) /
   * (2 ^ 31)]
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
/** Deprecated
 *
 * Deprecated.
 */
#define SBP_MSG_TRACKING_STATE_DETAILED_DEP 0x0011

#define SBP_TRACKING_STATE_DETAILED_DEP_SID_CODE__MASK (0xff)
#define SBP_TRACKING_STATE_DETAILED_DEP_SID_CODE__SHIFT (0u)
#define SBP_TRACKING_STATE_DETAILED_DEP_SID_CODE__GET(flags)      \
  (((flags) >> SBP_TRACKING_STATE_DETAILED_DEP_SID_CODE__SHIFT) & \
   SBP_TRACKING_STATE_DETAILED_DEP_SID_CODE__MASK)
#define SBP_TRACKING_STATE_DETAILED_DEP_SID_CODE__SET(flags, val)           \
  do {                                                                      \
    ((flags) |= (((val) & (SBP_TRACKING_STATE_DETAILED_DEP_SID_CODE__MASK)) \
                 << (SBP_TRACKING_STATE_DETAILED_DEP_SID_CODE__SHIFT)));    \
  } while (0)

#define SBP_TRACKING_STATE_DETAILED_DEP_SID_CODE__GPS_L1CA (0)
#define SBP_TRACKING_STATE_DETAILED_DEP_SID_CODE__GPS_L2CM (1)
#define SBP_TRACKING_STATE_DETAILED_DEP_SID_CODE__SBAS_L1CA (2)
#define SBP_TRACKING_STATE_DETAILED_DEP_SID_CODE__GLO_L1CA (3)
#define SBP_TRACKING_STATE_DETAILED_DEP_SID_CODE__GLO_L2CA (4)
#define SBP_TRACKING_STATE_DETAILED_DEP_SID_CODE__GPS_L1P (5)
#define SBP_TRACKING_STATE_DETAILED_DEP_SID_CODE__GPS_L2P (6)
#define SBP_TRACKING_STATE_DETAILED_DEP_SYNC_FLAGS_SYNCHRONIZATION_STATUS_MASK \
  (0x7)
#define SBP_TRACKING_STATE_DETAILED_DEP_SYNC_FLAGS_SYNCHRONIZATION_STATUS_SHIFT \
  (0u)
#define SBP_TRACKING_STATE_DETAILED_DEP_SYNC_FLAGS_SYNCHRONIZATION_STATUS_GET( \
    flags)                                                                     \
  (((flags) >>                                                                 \
    SBP_TRACKING_STATE_DETAILED_DEP_SYNC_FLAGS_SYNCHRONIZATION_STATUS_SHIFT) & \
   SBP_TRACKING_STATE_DETAILED_DEP_SYNC_FLAGS_SYNCHRONIZATION_STATUS_MASK)
#define SBP_TRACKING_STATE_DETAILED_DEP_SYNC_FLAGS_SYNCHRONIZATION_STATUS_SET(        \
    flags, val)                                                                       \
  do {                                                                                \
    ((flags) |=                                                                       \
     (((val) &                                                                        \
       (SBP_TRACKING_STATE_DETAILED_DEP_SYNC_FLAGS_SYNCHRONIZATION_STATUS_MASK))      \
      << (SBP_TRACKING_STATE_DETAILED_DEP_SYNC_FLAGS_SYNCHRONIZATION_STATUS_SHIFT))); \
  } while (0)

#define SBP_TRACKING_STATE_DETAILED_DEP_SYNC_FLAGS_SYNCHRONIZATION_STATUS_NO_SYNCHRONIZATION \
  (0)
#define SBP_TRACKING_STATE_DETAILED_DEP_SYNC_FLAGS_SYNCHRONIZATION_STATUS_BIT_SYNCHRONIZATION \
  (1)
#define SBP_TRACKING_STATE_DETAILED_DEP_SYNC_FLAGS_SYNCHRONIZATION_STATUS_WORD_SYNCHRONIZATION \
  (2)
#define SBP_TRACKING_STATE_DETAILED_DEP_SYNC_FLAGS_SYNCHRONIZATION_STATUS_SUB_FRAME_SYNCHRONIZATION_MESSAGE_SYNCHRONIZATION \
  (3)
#define SBP_TRACKING_STATE_DETAILED_DEP_TOW_FLAGS_WEEK_NUMBER_VALIDITY_STATUS_MASK \
  (0x1)
#define SBP_TRACKING_STATE_DETAILED_DEP_TOW_FLAGS_WEEK_NUMBER_VALIDITY_STATUS_SHIFT \
  (3u)
#define SBP_TRACKING_STATE_DETAILED_DEP_TOW_FLAGS_WEEK_NUMBER_VALIDITY_STATUS_GET( \
    flags)                                                                         \
  (((flags) >>                                                                     \
    SBP_TRACKING_STATE_DETAILED_DEP_TOW_FLAGS_WEEK_NUMBER_VALIDITY_STATUS_SHIFT) & \
   SBP_TRACKING_STATE_DETAILED_DEP_TOW_FLAGS_WEEK_NUMBER_VALIDITY_STATUS_MASK)
#define SBP_TRACKING_STATE_DETAILED_DEP_TOW_FLAGS_WEEK_NUMBER_VALIDITY_STATUS_SET(        \
    flags, val)                                                                           \
  do {                                                                                    \
    ((flags) |=                                                                           \
     (((val) &                                                                            \
       (SBP_TRACKING_STATE_DETAILED_DEP_TOW_FLAGS_WEEK_NUMBER_VALIDITY_STATUS_MASK))      \
      << (SBP_TRACKING_STATE_DETAILED_DEP_TOW_FLAGS_WEEK_NUMBER_VALIDITY_STATUS_SHIFT))); \
  } while (0)

#define SBP_TRACKING_STATE_DETAILED_DEP_TOW_FLAGS_WEEK_NUMBER_VALIDITY_STATUS_WEEK_NUMBER_IS_NOT_VALID \
  (0)
#define SBP_TRACKING_STATE_DETAILED_DEP_TOW_FLAGS_WEEK_NUMBER_VALIDITY_STATUS_WEEK_NUMBER_IS_VALID \
  (1)
#define SBP_TRACKING_STATE_DETAILED_DEP_TOW_FLAGS_TOW_STATUS_MASK (0x7)
#define SBP_TRACKING_STATE_DETAILED_DEP_TOW_FLAGS_TOW_STATUS_SHIFT (0u)
#define SBP_TRACKING_STATE_DETAILED_DEP_TOW_FLAGS_TOW_STATUS_GET(flags)      \
  (((flags) >> SBP_TRACKING_STATE_DETAILED_DEP_TOW_FLAGS_TOW_STATUS_SHIFT) & \
   SBP_TRACKING_STATE_DETAILED_DEP_TOW_FLAGS_TOW_STATUS_MASK)
#define SBP_TRACKING_STATE_DETAILED_DEP_TOW_FLAGS_TOW_STATUS_SET(flags, val) \
  do {                                                                       \
    ((flags) |=                                                              \
     (((val) & (SBP_TRACKING_STATE_DETAILED_DEP_TOW_FLAGS_TOW_STATUS_MASK))  \
      << (SBP_TRACKING_STATE_DETAILED_DEP_TOW_FLAGS_TOW_STATUS_SHIFT)));     \
  } while (0)

#define SBP_TRACKING_STATE_DETAILED_DEP_TOW_FLAGS_TOW_STATUS_TOW_IS_NOT_AVAILABLE \
  (0)
#define SBP_TRACKING_STATE_DETAILED_DEP_TOW_FLAGS_TOW_STATUS_DECODED_TOW_IS_AVAILABLE \
  (1)
#define SBP_TRACKING_STATE_DETAILED_DEP_TOW_FLAGS_TOW_STATUS_PROPAGATED_TOW_IS_AVAILABLE \
  (2)
#define SBP_TRACKING_STATE_DETAILED_DEP_TRACK_FLAGS_FLL_STATUS_MASK (0x1)
#define SBP_TRACKING_STATE_DETAILED_DEP_TRACK_FLAGS_FLL_STATUS_SHIFT (4u)
#define SBP_TRACKING_STATE_DETAILED_DEP_TRACK_FLAGS_FLL_STATUS_GET(flags)      \
  (((flags) >> SBP_TRACKING_STATE_DETAILED_DEP_TRACK_FLAGS_FLL_STATUS_SHIFT) & \
   SBP_TRACKING_STATE_DETAILED_DEP_TRACK_FLAGS_FLL_STATUS_MASK)
#define SBP_TRACKING_STATE_DETAILED_DEP_TRACK_FLAGS_FLL_STATUS_SET(flags, val) \
  do {                                                                         \
    ((flags) |=                                                                \
     (((val) & (SBP_TRACKING_STATE_DETAILED_DEP_TRACK_FLAGS_FLL_STATUS_MASK))  \
      << (SBP_TRACKING_STATE_DETAILED_DEP_TRACK_FLAGS_FLL_STATUS_SHIFT)));     \
  } while (0)

#define SBP_TRACKING_STATE_DETAILED_DEP_TRACK_FLAGS_FLL_STATUS_FLL_IS_INACTIVE \
  (0)
#define SBP_TRACKING_STATE_DETAILED_DEP_TRACK_FLAGS_FLL_STATUS_FLL_IS_ACTIVE (1)
#define SBP_TRACKING_STATE_DETAILED_DEP_TRACK_FLAGS_PLL_STATUS_MASK (0x1)
#define SBP_TRACKING_STATE_DETAILED_DEP_TRACK_FLAGS_PLL_STATUS_SHIFT (3u)
#define SBP_TRACKING_STATE_DETAILED_DEP_TRACK_FLAGS_PLL_STATUS_GET(flags)      \
  (((flags) >> SBP_TRACKING_STATE_DETAILED_DEP_TRACK_FLAGS_PLL_STATUS_SHIFT) & \
   SBP_TRACKING_STATE_DETAILED_DEP_TRACK_FLAGS_PLL_STATUS_MASK)
#define SBP_TRACKING_STATE_DETAILED_DEP_TRACK_FLAGS_PLL_STATUS_SET(flags, val) \
  do {                                                                         \
    ((flags) |=                                                                \
     (((val) & (SBP_TRACKING_STATE_DETAILED_DEP_TRACK_FLAGS_PLL_STATUS_MASK))  \
      << (SBP_TRACKING_STATE_DETAILED_DEP_TRACK_FLAGS_PLL_STATUS_SHIFT)));     \
  } while (0)

#define SBP_TRACKING_STATE_DETAILED_DEP_TRACK_FLAGS_PLL_STATUS_PLL_IS_INACTIVE \
  (0)
#define SBP_TRACKING_STATE_DETAILED_DEP_TRACK_FLAGS_PLL_STATUS_PLL_IS_ACTIVE (1)
#define SBP_TRACKING_STATE_DETAILED_DEP_TRACK_FLAGS_TRACKING_LOOP_STATUS_MASK \
  (0x7)
#define SBP_TRACKING_STATE_DETAILED_DEP_TRACK_FLAGS_TRACKING_LOOP_STATUS_SHIFT \
  (0u)
#define SBP_TRACKING_STATE_DETAILED_DEP_TRACK_FLAGS_TRACKING_LOOP_STATUS_GET( \
    flags)                                                                    \
  (((flags) >>                                                                \
    SBP_TRACKING_STATE_DETAILED_DEP_TRACK_FLAGS_TRACKING_LOOP_STATUS_SHIFT) & \
   SBP_TRACKING_STATE_DETAILED_DEP_TRACK_FLAGS_TRACKING_LOOP_STATUS_MASK)
#define SBP_TRACKING_STATE_DETAILED_DEP_TRACK_FLAGS_TRACKING_LOOP_STATUS_SET(        \
    flags, val)                                                                      \
  do {                                                                               \
    ((flags) |=                                                                      \
     (((val) &                                                                       \
       (SBP_TRACKING_STATE_DETAILED_DEP_TRACK_FLAGS_TRACKING_LOOP_STATUS_MASK))      \
      << (SBP_TRACKING_STATE_DETAILED_DEP_TRACK_FLAGS_TRACKING_LOOP_STATUS_SHIFT))); \
  } while (0)

#define SBP_TRACKING_STATE_DETAILED_DEP_TRACK_FLAGS_TRACKING_LOOP_STATUS_NO_LOCKS \
  (0)
#define SBP_TRACKING_STATE_DETAILED_DEP_TRACK_FLAGS_TRACKING_LOOP_STATUS_FLLDLL_LOCK \
  (1)
#define SBP_TRACKING_STATE_DETAILED_DEP_TRACK_FLAGS_TRACKING_LOOP_STATUS_PLL_OPTIMISTIC_LOCK \
  (2)
#define SBP_TRACKING_STATE_DETAILED_DEP_TRACK_FLAGS_TRACKING_LOOP_STATUS_PLL_PESSIMISTIC_LOCK \
  (3)
#define SBP_TRACKING_STATE_DETAILED_DEP_NAV_FLAGS_ALMANAC_AVAILABILITY_STATUS_MASK \
  (0x1)
#define SBP_TRACKING_STATE_DETAILED_DEP_NAV_FLAGS_ALMANAC_AVAILABILITY_STATUS_SHIFT \
  (4u)
#define SBP_TRACKING_STATE_DETAILED_DEP_NAV_FLAGS_ALMANAC_AVAILABILITY_STATUS_GET( \
    flags)                                                                         \
  (((flags) >>                                                                     \
    SBP_TRACKING_STATE_DETAILED_DEP_NAV_FLAGS_ALMANAC_AVAILABILITY_STATUS_SHIFT) & \
   SBP_TRACKING_STATE_DETAILED_DEP_NAV_FLAGS_ALMANAC_AVAILABILITY_STATUS_MASK)
#define SBP_TRACKING_STATE_DETAILED_DEP_NAV_FLAGS_ALMANAC_AVAILABILITY_STATUS_SET(        \
    flags, val)                                                                           \
  do {                                                                                    \
    ((flags) |=                                                                           \
     (((val) &                                                                            \
       (SBP_TRACKING_STATE_DETAILED_DEP_NAV_FLAGS_ALMANAC_AVAILABILITY_STATUS_MASK))      \
      << (SBP_TRACKING_STATE_DETAILED_DEP_NAV_FLAGS_ALMANAC_AVAILABILITY_STATUS_SHIFT))); \
  } while (0)

#define SBP_TRACKING_STATE_DETAILED_DEP_NAV_FLAGS_ALMANAC_AVAILABILITY_STATUS_ALMANAC_IS_NOT_AVAILABLE \
  (0)
#define SBP_TRACKING_STATE_DETAILED_DEP_NAV_FLAGS_ALMANAC_AVAILABILITY_STATUS_ALMANAC_IS_AVAILABLE \
  (1)
#define SBP_TRACKING_STATE_DETAILED_DEP_NAV_FLAGS_EPHEMERIS_AVAILABILITY_STATUS_MASK \
  (0x1)
#define SBP_TRACKING_STATE_DETAILED_DEP_NAV_FLAGS_EPHEMERIS_AVAILABILITY_STATUS_SHIFT \
  (3u)
#define SBP_TRACKING_STATE_DETAILED_DEP_NAV_FLAGS_EPHEMERIS_AVAILABILITY_STATUS_GET( \
    flags)                                                                           \
  (((flags) >>                                                                       \
    SBP_TRACKING_STATE_DETAILED_DEP_NAV_FLAGS_EPHEMERIS_AVAILABILITY_STATUS_SHIFT) & \
   SBP_TRACKING_STATE_DETAILED_DEP_NAV_FLAGS_EPHEMERIS_AVAILABILITY_STATUS_MASK)
#define SBP_TRACKING_STATE_DETAILED_DEP_NAV_FLAGS_EPHEMERIS_AVAILABILITY_STATUS_SET(        \
    flags, val)                                                                             \
  do {                                                                                      \
    ((flags) |=                                                                             \
     (((val) &                                                                              \
       (SBP_TRACKING_STATE_DETAILED_DEP_NAV_FLAGS_EPHEMERIS_AVAILABILITY_STATUS_MASK))      \
      << (SBP_TRACKING_STATE_DETAILED_DEP_NAV_FLAGS_EPHEMERIS_AVAILABILITY_STATUS_SHIFT))); \
  } while (0)

#define SBP_TRACKING_STATE_DETAILED_DEP_NAV_FLAGS_EPHEMERIS_AVAILABILITY_STATUS_EPHEMERIS_IS_NOT_AVAILABLE \
  (0)
#define SBP_TRACKING_STATE_DETAILED_DEP_NAV_FLAGS_EPHEMERIS_AVAILABILITY_STATUS_EPHEMERIS_IS_AVAILABLE \
  (1)
#define SBP_TRACKING_STATE_DETAILED_DEP_NAV_FLAGS_HEALTH_STATUS_MASK (0x7)
#define SBP_TRACKING_STATE_DETAILED_DEP_NAV_FLAGS_HEALTH_STATUS_SHIFT (0u)
#define SBP_TRACKING_STATE_DETAILED_DEP_NAV_FLAGS_HEALTH_STATUS_GET(flags) \
  (((flags) >>                                                             \
    SBP_TRACKING_STATE_DETAILED_DEP_NAV_FLAGS_HEALTH_STATUS_SHIFT) &       \
   SBP_TRACKING_STATE_DETAILED_DEP_NAV_FLAGS_HEALTH_STATUS_MASK)
#define SBP_TRACKING_STATE_DETAILED_DEP_NAV_FLAGS_HEALTH_STATUS_SET(flags,     \
                                                                    val)       \
  do {                                                                         \
    ((flags) |=                                                                \
     (((val) & (SBP_TRACKING_STATE_DETAILED_DEP_NAV_FLAGS_HEALTH_STATUS_MASK)) \
      << (SBP_TRACKING_STATE_DETAILED_DEP_NAV_FLAGS_HEALTH_STATUS_SHIFT)));    \
  } while (0)

#define SBP_TRACKING_STATE_DETAILED_DEP_NAV_FLAGS_HEALTH_STATUS_HEALTH_IS_UNKNOWN \
  (0)
#define SBP_TRACKING_STATE_DETAILED_DEP_NAV_FLAGS_HEALTH_STATUS_SIGNAL_IS_UNHEALTHY \
  (1)
#define SBP_TRACKING_STATE_DETAILED_DEP_NAV_FLAGS_HEALTH_STATUS_SIGNAL_IS_HEALTHY \
  (2)
#define SBP_TRACKING_STATE_DETAILED_DEP_PSET_FLAGS_PARAMETER_SETS_MASK (0x7)
#define SBP_TRACKING_STATE_DETAILED_DEP_PSET_FLAGS_PARAMETER_SETS_SHIFT (0u)
#define SBP_TRACKING_STATE_DETAILED_DEP_PSET_FLAGS_PARAMETER_SETS_GET(flags) \
  (((flags) >>                                                               \
    SBP_TRACKING_STATE_DETAILED_DEP_PSET_FLAGS_PARAMETER_SETS_SHIFT) &       \
   SBP_TRACKING_STATE_DETAILED_DEP_PSET_FLAGS_PARAMETER_SETS_MASK)
#define SBP_TRACKING_STATE_DETAILED_DEP_PSET_FLAGS_PARAMETER_SETS_SET(flags,  \
                                                                      val)    \
  do {                                                                        \
    ((flags) |=                                                               \
     (((val) &                                                                \
       (SBP_TRACKING_STATE_DETAILED_DEP_PSET_FLAGS_PARAMETER_SETS_MASK))      \
      << (SBP_TRACKING_STATE_DETAILED_DEP_PSET_FLAGS_PARAMETER_SETS_SHIFT))); \
  } while (0)

#define SBP_TRACKING_STATE_DETAILED_DEP_PSET_FLAGS_PARAMETER_SETS_1_MS_INTEGRATION_TIME \
  (0)
#define SBP_TRACKING_STATE_DETAILED_DEP_PSET_FLAGS_PARAMETER_SETS_5_MS_INTEGRATION_TIME \
  (1)
#define SBP_TRACKING_STATE_DETAILED_DEP_PSET_FLAGS_PARAMETER_SETS_10_MS_INTEGRATION_TIME \
  (2)
#define SBP_TRACKING_STATE_DETAILED_DEP_PSET_FLAGS_PARAMETER_SETS_20_MS_INTEGRATION_TIME \
  (3)
#define SBP_TRACKING_STATE_DETAILED_DEP_MISC_FLAGS_CLOCK_VALIDITY_STATUS_MASK \
  (0x1)
#define SBP_TRACKING_STATE_DETAILED_DEP_MISC_FLAGS_CLOCK_VALIDITY_STATUS_SHIFT \
  (5u)
#define SBP_TRACKING_STATE_DETAILED_DEP_MISC_FLAGS_CLOCK_VALIDITY_STATUS_GET( \
    flags)                                                                    \
  (((flags) >>                                                                \
    SBP_TRACKING_STATE_DETAILED_DEP_MISC_FLAGS_CLOCK_VALIDITY_STATUS_SHIFT) & \
   SBP_TRACKING_STATE_DETAILED_DEP_MISC_FLAGS_CLOCK_VALIDITY_STATUS_MASK)
#define SBP_TRACKING_STATE_DETAILED_DEP_MISC_FLAGS_CLOCK_VALIDITY_STATUS_SET(        \
    flags, val)                                                                      \
  do {                                                                               \
    ((flags) |=                                                                      \
     (((val) &                                                                       \
       (SBP_TRACKING_STATE_DETAILED_DEP_MISC_FLAGS_CLOCK_VALIDITY_STATUS_MASK))      \
      << (SBP_TRACKING_STATE_DETAILED_DEP_MISC_FLAGS_CLOCK_VALIDITY_STATUS_SHIFT))); \
  } while (0)

#define SBP_TRACKING_STATE_DETAILED_DEP_MISC_FLAGS_CLOCK_VALIDITY_STATUS_CLOCK_OFFSET_AND_DRIFT_IS_NOT_VALID \
  (0)
#define SBP_TRACKING_STATE_DETAILED_DEP_MISC_FLAGS_CLOCK_VALIDITY_STATUS_CLOCK_OFFSET_AND_DRIFT_IS_VALID \
  (1)
#define SBP_TRACKING_STATE_DETAILED_DEP_MISC_FLAGS_PSEUDORANGE_VALIDITY_STATUS_MASK \
  (0x1)
#define SBP_TRACKING_STATE_DETAILED_DEP_MISC_FLAGS_PSEUDORANGE_VALIDITY_STATUS_SHIFT \
  (4u)
#define SBP_TRACKING_STATE_DETAILED_DEP_MISC_FLAGS_PSEUDORANGE_VALIDITY_STATUS_GET( \
    flags)                                                                          \
  (((flags) >>                                                                      \
    SBP_TRACKING_STATE_DETAILED_DEP_MISC_FLAGS_PSEUDORANGE_VALIDITY_STATUS_SHIFT) & \
   SBP_TRACKING_STATE_DETAILED_DEP_MISC_FLAGS_PSEUDORANGE_VALIDITY_STATUS_MASK)
#define SBP_TRACKING_STATE_DETAILED_DEP_MISC_FLAGS_PSEUDORANGE_VALIDITY_STATUS_SET(        \
    flags, val)                                                                            \
  do {                                                                                     \
    ((flags) |=                                                                            \
     (((val) &                                                                             \
       (SBP_TRACKING_STATE_DETAILED_DEP_MISC_FLAGS_PSEUDORANGE_VALIDITY_STATUS_MASK))      \
      << (SBP_TRACKING_STATE_DETAILED_DEP_MISC_FLAGS_PSEUDORANGE_VALIDITY_STATUS_SHIFT))); \
  } while (0)

#define SBP_TRACKING_STATE_DETAILED_DEP_MISC_FLAGS_PSEUDORANGE_VALIDITY_STATUS_PSEUDORANGE_IS_NOT_VALID \
  (0)
#define SBP_TRACKING_STATE_DETAILED_DEP_MISC_FLAGS_PSEUDORANGE_VALIDITY_STATUS_PSEUDORANGE_IS_VALID \
  (1)
#define SBP_TRACKING_STATE_DETAILED_DEP_MISC_FLAGS_ACCELERATION_VALIDITY_STATUS_MASK \
  (0x1)
#define SBP_TRACKING_STATE_DETAILED_DEP_MISC_FLAGS_ACCELERATION_VALIDITY_STATUS_SHIFT \
  (3u)
#define SBP_TRACKING_STATE_DETAILED_DEP_MISC_FLAGS_ACCELERATION_VALIDITY_STATUS_GET( \
    flags)                                                                           \
  (((flags) >>                                                                       \
    SBP_TRACKING_STATE_DETAILED_DEP_MISC_FLAGS_ACCELERATION_VALIDITY_STATUS_SHIFT) & \
   SBP_TRACKING_STATE_DETAILED_DEP_MISC_FLAGS_ACCELERATION_VALIDITY_STATUS_MASK)
#define SBP_TRACKING_STATE_DETAILED_DEP_MISC_FLAGS_ACCELERATION_VALIDITY_STATUS_SET(        \
    flags, val)                                                                             \
  do {                                                                                      \
    ((flags) |=                                                                             \
     (((val) &                                                                              \
       (SBP_TRACKING_STATE_DETAILED_DEP_MISC_FLAGS_ACCELERATION_VALIDITY_STATUS_MASK))      \
      << (SBP_TRACKING_STATE_DETAILED_DEP_MISC_FLAGS_ACCELERATION_VALIDITY_STATUS_SHIFT))); \
  } while (0)

#define SBP_TRACKING_STATE_DETAILED_DEP_MISC_FLAGS_ACCELERATION_VALIDITY_STATUS_ACCELERATION_IS_NOT_VALID \
  (0)
#define SBP_TRACKING_STATE_DETAILED_DEP_MISC_FLAGS_ACCELERATION_VALIDITY_STATUS_ACCELERATION_IS_VALID \
  (1)
#define SBP_TRACKING_STATE_DETAILED_DEP_MISC_FLAGS_CARRIER_HALF_CYCLE_AMBIGUITY_STATUS_MASK \
  (0x1)
#define SBP_TRACKING_STATE_DETAILED_DEP_MISC_FLAGS_CARRIER_HALF_CYCLE_AMBIGUITY_STATUS_SHIFT \
  (2u)
#define SBP_TRACKING_STATE_DETAILED_DEP_MISC_FLAGS_CARRIER_HALF_CYCLE_AMBIGUITY_STATUS_GET( \
    flags)                                                                                  \
  (((flags) >>                                                                              \
    SBP_TRACKING_STATE_DETAILED_DEP_MISC_FLAGS_CARRIER_HALF_CYCLE_AMBIGUITY_STATUS_SHIFT) & \
   SBP_TRACKING_STATE_DETAILED_DEP_MISC_FLAGS_CARRIER_HALF_CYCLE_AMBIGUITY_STATUS_MASK)
#define SBP_TRACKING_STATE_DETAILED_DEP_MISC_FLAGS_CARRIER_HALF_CYCLE_AMBIGUITY_STATUS_SET(        \
    flags, val)                                                                                    \
  do {                                                                                             \
    ((flags) |=                                                                                    \
     (((val) &                                                                                     \
       (SBP_TRACKING_STATE_DETAILED_DEP_MISC_FLAGS_CARRIER_HALF_CYCLE_AMBIGUITY_STATUS_MASK))      \
      << (SBP_TRACKING_STATE_DETAILED_DEP_MISC_FLAGS_CARRIER_HALF_CYCLE_AMBIGUITY_STATUS_SHIFT))); \
  } while (0)

#define SBP_TRACKING_STATE_DETAILED_DEP_MISC_FLAGS_CARRIER_HALF_CYCLE_AMBIGUITY_STATUS_UNRESOLVED \
  (0)
#define SBP_TRACKING_STATE_DETAILED_DEP_MISC_FLAGS_CARRIER_HALF_CYCLE_AMBIGUITY_STATUS_RESOLVED \
  (1)
#define SBP_TRACKING_STATE_DETAILED_DEP_MISC_FLAGS_TRACKING_CHANNEL_STATUS_MASK \
  (0x3)
#define SBP_TRACKING_STATE_DETAILED_DEP_MISC_FLAGS_TRACKING_CHANNEL_STATUS_SHIFT \
  (0u)
#define SBP_TRACKING_STATE_DETAILED_DEP_MISC_FLAGS_TRACKING_CHANNEL_STATUS_GET( \
    flags)                                                                      \
  (((flags) >>                                                                  \
    SBP_TRACKING_STATE_DETAILED_DEP_MISC_FLAGS_TRACKING_CHANNEL_STATUS_SHIFT) & \
   SBP_TRACKING_STATE_DETAILED_DEP_MISC_FLAGS_TRACKING_CHANNEL_STATUS_MASK)
#define SBP_TRACKING_STATE_DETAILED_DEP_MISC_FLAGS_TRACKING_CHANNEL_STATUS_SET(        \
    flags, val)                                                                        \
  do {                                                                                 \
    ((flags) |=                                                                        \
     (((val) &                                                                         \
       (SBP_TRACKING_STATE_DETAILED_DEP_MISC_FLAGS_TRACKING_CHANNEL_STATUS_MASK))      \
      << (SBP_TRACKING_STATE_DETAILED_DEP_MISC_FLAGS_TRACKING_CHANNEL_STATUS_SHIFT))); \
  } while (0)

#define SBP_TRACKING_STATE_DETAILED_DEP_MISC_FLAGS_TRACKING_CHANNEL_STATUS_RE_ACQUISITION \
  (0)
#define SBP_TRACKING_STATE_DETAILED_DEP_MISC_FLAGS_TRACKING_CHANNEL_STATUS_RUNNING \
  (1)
typedef struct SBP_ATTR_PACKED {
  /**
   * Receiver clock time.[ns]
   */
  u64 recv_time;
  /**
   * Time of transmission of signal from satellite. TOW only valid when
   * TOW status is decoded or propagated. WN only valid when week
   * number valid flag is set.
   */
  struct SBP_ATTR_PACKED {
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
  struct SBP_ATTR_PACKED {
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
  struct SBP_ATTR_PACKED {
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
   * TCXO clock offset. Valid only when valid clock valid flag is set.[s / (2 ^
   * 20)]
   */
  s16 clock_offset;
  /**
   * TCXO clock drift. Valid only when valid clock valid flag is set.[(s / s) /
   * (2 ^ 31)]
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
/** Signal tracking channel states
 *
 * The tracking message returns a variable-length array of tracking
 * channel states. It reports status and carrier-to-noise density
 * measurements for all tracked satellites.
 */
#define SBP_MSG_TRACKING_STATE 0x0041

#define SBP_TRACKING_STATE_STATES_SID_CODE__MASK (0xff)
#define SBP_TRACKING_STATE_STATES_SID_CODE__SHIFT (0u)
#define SBP_TRACKING_STATE_STATES_SID_CODE__GET(flags)      \
  (((flags) >> SBP_TRACKING_STATE_STATES_SID_CODE__SHIFT) & \
   SBP_TRACKING_STATE_STATES_SID_CODE__MASK)
#define SBP_TRACKING_STATE_STATES_SID_CODE__SET(flags, val)           \
  do {                                                                \
    ((flags) |= (((val) & (SBP_TRACKING_STATE_STATES_SID_CODE__MASK)) \
                 << (SBP_TRACKING_STATE_STATES_SID_CODE__SHIFT)));    \
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
typedef struct SBP_ATTR_PACKED {
  /**
   * Signal tracking channel state
   */
  struct SBP_ATTR_PACKED {
    /**
     * GNSS signal being tracked
     */
    struct SBP_ATTR_PACKED {
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
} sbp_msg_tracking_state_t;
/** Measurement Engine signal tracking channel states
 *
 * The tracking message returns a variable-length array of tracking
 * channel states. It reports status and carrier-to-noise density
 * measurements for all tracked satellites.
 */
#define SBP_MSG_MEASUREMENT_STATE 0x0061

#define SBP_MEASUREMENT_STATE_STATES_MESID_CODE__MASK (0xff)
#define SBP_MEASUREMENT_STATE_STATES_MESID_CODE__SHIFT (0u)
#define SBP_MEASUREMENT_STATE_STATES_MESID_CODE__GET(flags)      \
  (((flags) >> SBP_MEASUREMENT_STATE_STATES_MESID_CODE__SHIFT) & \
   SBP_MEASUREMENT_STATE_STATES_MESID_CODE__MASK)
#define SBP_MEASUREMENT_STATE_STATES_MESID_CODE__SET(flags, val)           \
  do {                                                                     \
    ((flags) |= (((val) & (SBP_MEASUREMENT_STATE_STATES_MESID_CODE__MASK)) \
                 << (SBP_MEASUREMENT_STATE_STATES_MESID_CODE__SHIFT)));    \
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
typedef struct SBP_ATTR_PACKED {
  /**
   * ME signal tracking channel state
   */
  struct SBP_ATTR_PACKED {
    /**
     * Measurement Engine GNSS signal being tracked (carries either Glonass FCN
     * or SLOT)
     */
    struct SBP_ATTR_PACKED {
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
} sbp_msg_measurement_state_t;
/** Tracking channel correlations
 *
 * When enabled, a tracking channel can output the correlations at each
 * update interval.
 */
#define SBP_MSG_TRACKING_IQ 0x002D

#define SBP_TRACKING_IQ_SID_CODE__MASK (0xff)
#define SBP_TRACKING_IQ_SID_CODE__SHIFT (0u)
#define SBP_TRACKING_IQ_SID_CODE__GET(flags)      \
  (((flags) >> SBP_TRACKING_IQ_SID_CODE__SHIFT) & \
   SBP_TRACKING_IQ_SID_CODE__MASK)
#define SBP_TRACKING_IQ_SID_CODE__SET(flags, val)           \
  do {                                                      \
    ((flags) |= (((val) & (SBP_TRACKING_IQ_SID_CODE__MASK)) \
                 << (SBP_TRACKING_IQ_SID_CODE__SHIFT)));    \
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

typedef struct SBP_ATTR_PACKED {
  /**
   * Tracking channel of origin
   */
  u8 channel;
  /**
   * GNSS signal identifier
   */
  struct SBP_ATTR_PACKED {
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
  struct SBP_ATTR_PACKED {
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
/** Tracking channel correlations
 *
 * When enabled, a tracking channel can output the correlations at each
 * update interval.
 */
#define SBP_MSG_TRACKING_IQ_DEP_B 0x002C

#define SBP_TRACKING_IQ_DEP_B_SID_CODE__MASK (0xff)
#define SBP_TRACKING_IQ_DEP_B_SID_CODE__SHIFT (0u)
#define SBP_TRACKING_IQ_DEP_B_SID_CODE__GET(flags)      \
  (((flags) >> SBP_TRACKING_IQ_DEP_B_SID_CODE__SHIFT) & \
   SBP_TRACKING_IQ_DEP_B_SID_CODE__MASK)
#define SBP_TRACKING_IQ_DEP_B_SID_CODE__SET(flags, val)           \
  do {                                                            \
    ((flags) |= (((val) & (SBP_TRACKING_IQ_DEP_B_SID_CODE__MASK)) \
                 << (SBP_TRACKING_IQ_DEP_B_SID_CODE__SHIFT)));    \
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

typedef struct SBP_ATTR_PACKED {
  /**
   * Tracking channel of origin
   */
  u8 channel;
  /**
   * GNSS signal identifier
   */
  struct SBP_ATTR_PACKED {
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
  struct SBP_ATTR_PACKED {
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
/** Deprecated
 *
 * Deprecated.
 */
#define SBP_MSG_TRACKING_IQ_DEP_A 0x001C

#define SBP_TRACKING_IQ_DEP_A_SID_CODE__MASK (0xff)
#define SBP_TRACKING_IQ_DEP_A_SID_CODE__SHIFT (0u)
#define SBP_TRACKING_IQ_DEP_A_SID_CODE__GET(flags)      \
  (((flags) >> SBP_TRACKING_IQ_DEP_A_SID_CODE__SHIFT) & \
   SBP_TRACKING_IQ_DEP_A_SID_CODE__MASK)
#define SBP_TRACKING_IQ_DEP_A_SID_CODE__SET(flags, val)           \
  do {                                                            \
    ((flags) |= (((val) & (SBP_TRACKING_IQ_DEP_A_SID_CODE__MASK)) \
                 << (SBP_TRACKING_IQ_DEP_A_SID_CODE__SHIFT)));    \
  } while (0)

#define SBP_TRACKING_IQ_DEP_A_SID_CODE__GPS_L1CA (0)
#define SBP_TRACKING_IQ_DEP_A_SID_CODE__GPS_L2CM (1)
#define SBP_TRACKING_IQ_DEP_A_SID_CODE__SBAS_L1CA (2)
#define SBP_TRACKING_IQ_DEP_A_SID_CODE__GLO_L1CA (3)
#define SBP_TRACKING_IQ_DEP_A_SID_CODE__GLO_L2CA (4)
#define SBP_TRACKING_IQ_DEP_A_SID_CODE__GPS_L1P (5)
#define SBP_TRACKING_IQ_DEP_A_SID_CODE__GPS_L2P (6)

typedef struct SBP_ATTR_PACKED {
  /**
   * Tracking channel of origin
   */
  u8 channel;
  /**
   * GNSS signal identifier
   */
  struct SBP_ATTR_PACKED {
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
  struct SBP_ATTR_PACKED {
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
/** Deprecated
 *
 * Deprecated.
 */
#define SBP_MSG_TRACKING_STATE_DEP_A 0x0016

#define SBP_TRACKING_STATE_DEP_A_STATES_STATE_TRACKING_MODE_MASK (0x3)
#define SBP_TRACKING_STATE_DEP_A_STATES_STATE_TRACKING_MODE_SHIFT (0u)
#define SBP_TRACKING_STATE_DEP_A_STATES_STATE_TRACKING_MODE_GET(flags)      \
  (((flags) >> SBP_TRACKING_STATE_DEP_A_STATES_STATE_TRACKING_MODE_SHIFT) & \
   SBP_TRACKING_STATE_DEP_A_STATES_STATE_TRACKING_MODE_MASK)
#define SBP_TRACKING_STATE_DEP_A_STATES_STATE_TRACKING_MODE_SET(flags, val) \
  do {                                                                      \
    ((flags) |=                                                             \
     (((val) & (SBP_TRACKING_STATE_DEP_A_STATES_STATE_TRACKING_MODE_MASK))  \
      << (SBP_TRACKING_STATE_DEP_A_STATES_STATE_TRACKING_MODE_SHIFT)));     \
  } while (0)

#define SBP_TRACKING_STATE_DEP_A_STATES_STATE_TRACKING_MODE_DISABLED (0)
#define SBP_TRACKING_STATE_DEP_A_STATES_STATE_TRACKING_MODE_RUNNING (1)
typedef struct SBP_ATTR_PACKED {
  /**
   * Satellite tracking channel state
   */
  struct SBP_ATTR_PACKED {
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
} sbp_msg_tracking_state_dep_a_t;
/** Deprecated.
 *
 * Deprecated.
 */
#define SBP_MSG_TRACKING_STATE_DEP_B 0x0013

#define SBP_TRACKING_STATE_DEP_B_STATES_STATE_TRACKING_MODE_MASK (0x3)
#define SBP_TRACKING_STATE_DEP_B_STATES_STATE_TRACKING_MODE_SHIFT (0u)
#define SBP_TRACKING_STATE_DEP_B_STATES_STATE_TRACKING_MODE_GET(flags)      \
  (((flags) >> SBP_TRACKING_STATE_DEP_B_STATES_STATE_TRACKING_MODE_SHIFT) & \
   SBP_TRACKING_STATE_DEP_B_STATES_STATE_TRACKING_MODE_MASK)
#define SBP_TRACKING_STATE_DEP_B_STATES_STATE_TRACKING_MODE_SET(flags, val) \
  do {                                                                      \
    ((flags) |=                                                             \
     (((val) & (SBP_TRACKING_STATE_DEP_B_STATES_STATE_TRACKING_MODE_MASK))  \
      << (SBP_TRACKING_STATE_DEP_B_STATES_STATE_TRACKING_MODE_SHIFT)));     \
  } while (0)

#define SBP_TRACKING_STATE_DEP_B_STATES_STATE_TRACKING_MODE_DISABLED (0)
#define SBP_TRACKING_STATE_DEP_B_STATES_STATE_TRACKING_MODE_RUNNING (1)

#define SBP_TRACKING_STATE_DEP_B_STATES_SID_CODE__MASK (0xff)
#define SBP_TRACKING_STATE_DEP_B_STATES_SID_CODE__SHIFT (0u)
#define SBP_TRACKING_STATE_DEP_B_STATES_SID_CODE__GET(flags)      \
  (((flags) >> SBP_TRACKING_STATE_DEP_B_STATES_SID_CODE__SHIFT) & \
   SBP_TRACKING_STATE_DEP_B_STATES_SID_CODE__MASK)
#define SBP_TRACKING_STATE_DEP_B_STATES_SID_CODE__SET(flags, val)           \
  do {                                                                      \
    ((flags) |= (((val) & (SBP_TRACKING_STATE_DEP_B_STATES_SID_CODE__MASK)) \
                 << (SBP_TRACKING_STATE_DEP_B_STATES_SID_CODE__SHIFT)));    \
  } while (0)

#define SBP_TRACKING_STATE_DEP_B_STATES_SID_CODE__GPS_L1CA (0)
#define SBP_TRACKING_STATE_DEP_B_STATES_SID_CODE__GPS_L2CM (1)
#define SBP_TRACKING_STATE_DEP_B_STATES_SID_CODE__SBAS_L1CA (2)
#define SBP_TRACKING_STATE_DEP_B_STATES_SID_CODE__GLO_L1CA (3)
#define SBP_TRACKING_STATE_DEP_B_STATES_SID_CODE__GLO_L2CA (4)
#define SBP_TRACKING_STATE_DEP_B_STATES_SID_CODE__GPS_L1P (5)
#define SBP_TRACKING_STATE_DEP_B_STATES_SID_CODE__GPS_L2P (6)
typedef struct SBP_ATTR_PACKED {
  /**
   * Signal tracking channel state
   */
  struct SBP_ATTR_PACKED {
    /**
     * Status of tracking channel
     */
    u8 state;
    /**
     * GNSS signal being tracked
     */
    struct SBP_ATTR_PACKED {
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
} sbp_msg_tracking_state_dep_b_t;

SBP_PACK_END

#endif /* LIBSBP_TRACKING_MESSAGES_H */