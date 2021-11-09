/*
 * Copyright (C) 2015-2021 Swift Navigation Inc.
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
 * Automatically generated from yaml/swiftnav/sbp/tracking.yaml
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

#ifndef LIBSBP_TRACKING_MACROS_H
#define LIBSBP_TRACKING_MACROS_H

#define SBP_MSG_TRACKING_STATE_DETAILED_DEP_A 0x0021
#define SBP_TRACKING_STATE_DETAILED_DEP_A_SYNCHRONIZATION_STATUS_MASK (0x7)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_SYNCHRONIZATION_STATUS_SHIFT (0u)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_SYNCHRONIZATION_STATUS_GET(flags) \
  ((u8)(((flags) >>                                                         \
         SBP_TRACKING_STATE_DETAILED_DEP_A_SYNCHRONIZATION_STATUS_SHIFT) &  \
        SBP_TRACKING_STATE_DETAILED_DEP_A_SYNCHRONIZATION_STATUS_MASK))
#define SBP_TRACKING_STATE_DETAILED_DEP_A_SYNCHRONIZATION_STATUS_SET(flags,     \
                                                                     val)       \
  do {                                                                          \
    (flags) = (u8)(                                                             \
        (flags) |                                                               \
        (((val) &                                                               \
          (SBP_TRACKING_STATE_DETAILED_DEP_A_SYNCHRONIZATION_STATUS_MASK))      \
         << (SBP_TRACKING_STATE_DETAILED_DEP_A_SYNCHRONIZATION_STATUS_SHIFT))); \
  } while (0)

#define SBP_TRACKING_STATE_DETAILED_DEP_A_SYNCHRONIZATION_STATUS_NO_SYNCHRONIZATION \
  (0)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_SYNCHRONIZATION_STATUS_BIT_SYNCHRONIZATION \
  (1)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_SYNCHRONIZATION_STATUS_WORD_SYNCHRONIZATION \
  (2)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_SYNCHRONIZATION_STATUS_SUB_FRAME_SYNCHRONIZATION_MESSAGE_SYNCHRONIZATION \
  (3)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_WEEK_NUMBER_VALIDITY_STATUS_MASK (0x1)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_WEEK_NUMBER_VALIDITY_STATUS_SHIFT (3u)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_WEEK_NUMBER_VALIDITY_STATUS_GET(    \
    flags)                                                                    \
  ((u8)(                                                                      \
      ((flags) >>                                                             \
       SBP_TRACKING_STATE_DETAILED_DEP_A_WEEK_NUMBER_VALIDITY_STATUS_SHIFT) & \
      SBP_TRACKING_STATE_DETAILED_DEP_A_WEEK_NUMBER_VALIDITY_STATUS_MASK))
#define SBP_TRACKING_STATE_DETAILED_DEP_A_WEEK_NUMBER_VALIDITY_STATUS_SET(           \
    flags, val)                                                                      \
  do {                                                                               \
    (flags) = (u8)(                                                                  \
        (flags) |                                                                    \
        (((val) &                                                                    \
          (SBP_TRACKING_STATE_DETAILED_DEP_A_WEEK_NUMBER_VALIDITY_STATUS_MASK))      \
         << (SBP_TRACKING_STATE_DETAILED_DEP_A_WEEK_NUMBER_VALIDITY_STATUS_SHIFT))); \
  } while (0)

#define SBP_TRACKING_STATE_DETAILED_DEP_A_WEEK_NUMBER_VALIDITY_STATUS_WEEK_NUMBER_IS_NOT_VALID \
  (0)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_WEEK_NUMBER_VALIDITY_STATUS_WEEK_NUMBER_IS_VALID \
  (1)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_TOW_STATUS_MASK (0x7)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_TOW_STATUS_SHIFT (0u)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_TOW_STATUS_GET(flags)           \
  ((u8)(((flags) >> SBP_TRACKING_STATE_DETAILED_DEP_A_TOW_STATUS_SHIFT) & \
        SBP_TRACKING_STATE_DETAILED_DEP_A_TOW_STATUS_MASK))
#define SBP_TRACKING_STATE_DETAILED_DEP_A_TOW_STATUS_SET(flags, val)        \
  do {                                                                      \
    (flags) =                                                               \
        (u8)((flags) |                                                      \
             (((val) & (SBP_TRACKING_STATE_DETAILED_DEP_A_TOW_STATUS_MASK)) \
              << (SBP_TRACKING_STATE_DETAILED_DEP_A_TOW_STATUS_SHIFT)));    \
  } while (0)

#define SBP_TRACKING_STATE_DETAILED_DEP_A_TOW_STATUS_TOW_IS_NOT_AVAILABLE (0)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_TOW_STATUS_DECODED_TOW_IS_AVAILABLE \
  (1)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_TOW_STATUS_PROPAGATED_TOW_IS_AVAILABLE \
  (2)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_FLL_STATUS_MASK (0x1)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_FLL_STATUS_SHIFT (4u)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_FLL_STATUS_GET(flags)           \
  ((u8)(((flags) >> SBP_TRACKING_STATE_DETAILED_DEP_A_FLL_STATUS_SHIFT) & \
        SBP_TRACKING_STATE_DETAILED_DEP_A_FLL_STATUS_MASK))
#define SBP_TRACKING_STATE_DETAILED_DEP_A_FLL_STATUS_SET(flags, val)        \
  do {                                                                      \
    (flags) =                                                               \
        (u8)((flags) |                                                      \
             (((val) & (SBP_TRACKING_STATE_DETAILED_DEP_A_FLL_STATUS_MASK)) \
              << (SBP_TRACKING_STATE_DETAILED_DEP_A_FLL_STATUS_SHIFT)));    \
  } while (0)

#define SBP_TRACKING_STATE_DETAILED_DEP_A_FLL_STATUS_FLL_IS_INACTIVE (0)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_FLL_STATUS_FLL_IS_ACTIVE (1)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_PLL_STATUS_MASK (0x1)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_PLL_STATUS_SHIFT (3u)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_PLL_STATUS_GET(flags)           \
  ((u8)(((flags) >> SBP_TRACKING_STATE_DETAILED_DEP_A_PLL_STATUS_SHIFT) & \
        SBP_TRACKING_STATE_DETAILED_DEP_A_PLL_STATUS_MASK))
#define SBP_TRACKING_STATE_DETAILED_DEP_A_PLL_STATUS_SET(flags, val)        \
  do {                                                                      \
    (flags) =                                                               \
        (u8)((flags) |                                                      \
             (((val) & (SBP_TRACKING_STATE_DETAILED_DEP_A_PLL_STATUS_MASK)) \
              << (SBP_TRACKING_STATE_DETAILED_DEP_A_PLL_STATUS_SHIFT)));    \
  } while (0)

#define SBP_TRACKING_STATE_DETAILED_DEP_A_PLL_STATUS_PLL_IS_INACTIVE (0)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_PLL_STATUS_PLL_IS_ACTIVE (1)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_TRACKING_LOOP_STATUS_MASK (0x7)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_TRACKING_LOOP_STATUS_SHIFT (0u)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_TRACKING_LOOP_STATUS_GET(flags) \
  ((u8)(((flags) >>                                                       \
         SBP_TRACKING_STATE_DETAILED_DEP_A_TRACKING_LOOP_STATUS_SHIFT) &  \
        SBP_TRACKING_STATE_DETAILED_DEP_A_TRACKING_LOOP_STATUS_MASK))
#define SBP_TRACKING_STATE_DETAILED_DEP_A_TRACKING_LOOP_STATUS_SET(flags, val) \
  do {                                                                         \
    (flags) = (u8)(                                                            \
        (flags) |                                                              \
        (((val) &                                                              \
          (SBP_TRACKING_STATE_DETAILED_DEP_A_TRACKING_LOOP_STATUS_MASK))       \
         << (SBP_TRACKING_STATE_DETAILED_DEP_A_TRACKING_LOOP_STATUS_SHIFT)));  \
  } while (0)

#define SBP_TRACKING_STATE_DETAILED_DEP_A_TRACKING_LOOP_STATUS_NO_LOCKS (0)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_TRACKING_LOOP_STATUS_FLLDLL_LOCK (1)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_TRACKING_LOOP_STATUS_PLL_OPTIMISTIC_LOCK \
  (2)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_TRACKING_LOOP_STATUS_PLL_PESSIMISTIC_LOCK \
  (3)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_ALMANAC_AVAILABILITY_STATUS_MASK (0x1)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_ALMANAC_AVAILABILITY_STATUS_SHIFT (4u)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_ALMANAC_AVAILABILITY_STATUS_GET(    \
    flags)                                                                    \
  ((u8)(                                                                      \
      ((flags) >>                                                             \
       SBP_TRACKING_STATE_DETAILED_DEP_A_ALMANAC_AVAILABILITY_STATUS_SHIFT) & \
      SBP_TRACKING_STATE_DETAILED_DEP_A_ALMANAC_AVAILABILITY_STATUS_MASK))
#define SBP_TRACKING_STATE_DETAILED_DEP_A_ALMANAC_AVAILABILITY_STATUS_SET(           \
    flags, val)                                                                      \
  do {                                                                               \
    (flags) = (u8)(                                                                  \
        (flags) |                                                                    \
        (((val) &                                                                    \
          (SBP_TRACKING_STATE_DETAILED_DEP_A_ALMANAC_AVAILABILITY_STATUS_MASK))      \
         << (SBP_TRACKING_STATE_DETAILED_DEP_A_ALMANAC_AVAILABILITY_STATUS_SHIFT))); \
  } while (0)

#define SBP_TRACKING_STATE_DETAILED_DEP_A_ALMANAC_AVAILABILITY_STATUS_ALMANAC_IS_NOT_AVAILABLE \
  (0)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_ALMANAC_AVAILABILITY_STATUS_ALMANAC_IS_AVAILABLE \
  (1)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_EPHEMERIS_AVAILABILITY_STATUS_MASK \
  (0x1)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_EPHEMERIS_AVAILABILITY_STATUS_SHIFT \
  (3u)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_EPHEMERIS_AVAILABILITY_STATUS_GET(    \
    flags)                                                                      \
  ((u8)(                                                                        \
      ((flags) >>                                                               \
       SBP_TRACKING_STATE_DETAILED_DEP_A_EPHEMERIS_AVAILABILITY_STATUS_SHIFT) & \
      SBP_TRACKING_STATE_DETAILED_DEP_A_EPHEMERIS_AVAILABILITY_STATUS_MASK))
#define SBP_TRACKING_STATE_DETAILED_DEP_A_EPHEMERIS_AVAILABILITY_STATUS_SET(           \
    flags, val)                                                                        \
  do {                                                                                 \
    (flags) = (u8)(                                                                    \
        (flags) |                                                                      \
        (((val) &                                                                      \
          (SBP_TRACKING_STATE_DETAILED_DEP_A_EPHEMERIS_AVAILABILITY_STATUS_MASK))      \
         << (SBP_TRACKING_STATE_DETAILED_DEP_A_EPHEMERIS_AVAILABILITY_STATUS_SHIFT))); \
  } while (0)

#define SBP_TRACKING_STATE_DETAILED_DEP_A_EPHEMERIS_AVAILABILITY_STATUS_EPHEMERIS_IS_NOT_AVAILABLE \
  (0)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_EPHEMERIS_AVAILABILITY_STATUS_EPHEMERIS_IS_AVAILABLE \
  (1)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_HEALTH_STATUS_MASK (0x7)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_HEALTH_STATUS_SHIFT (0u)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_HEALTH_STATUS_GET(flags)           \
  ((u8)(((flags) >> SBP_TRACKING_STATE_DETAILED_DEP_A_HEALTH_STATUS_SHIFT) & \
        SBP_TRACKING_STATE_DETAILED_DEP_A_HEALTH_STATUS_MASK))
#define SBP_TRACKING_STATE_DETAILED_DEP_A_HEALTH_STATUS_SET(flags, val)        \
  do {                                                                         \
    (flags) =                                                                  \
        (u8)((flags) |                                                         \
             (((val) & (SBP_TRACKING_STATE_DETAILED_DEP_A_HEALTH_STATUS_MASK)) \
              << (SBP_TRACKING_STATE_DETAILED_DEP_A_HEALTH_STATUS_SHIFT)));    \
  } while (0)

#define SBP_TRACKING_STATE_DETAILED_DEP_A_HEALTH_STATUS_HEALTH_IS_UNKNOWN (0)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_HEALTH_STATUS_SIGNAL_IS_UNHEALTHY (1)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_HEALTH_STATUS_SIGNAL_IS_HEALTHY (2)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_PARAMETER_SETS_MASK (0x7)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_PARAMETER_SETS_SHIFT (0u)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_PARAMETER_SETS_GET(flags)           \
  ((u8)(((flags) >> SBP_TRACKING_STATE_DETAILED_DEP_A_PARAMETER_SETS_SHIFT) & \
        SBP_TRACKING_STATE_DETAILED_DEP_A_PARAMETER_SETS_MASK))
#define SBP_TRACKING_STATE_DETAILED_DEP_A_PARAMETER_SETS_SET(flags, val)   \
  do {                                                                     \
    (flags) = (u8)(                                                        \
        (flags) |                                                          \
        (((val) & (SBP_TRACKING_STATE_DETAILED_DEP_A_PARAMETER_SETS_MASK)) \
         << (SBP_TRACKING_STATE_DETAILED_DEP_A_PARAMETER_SETS_SHIFT)));    \
  } while (0)

#define SBP_TRACKING_STATE_DETAILED_DEP_A_PARAMETER_SETS_1_MS_INTEGRATION_TIME \
  (0)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_PARAMETER_SETS_5_MS_INTEGRATION_TIME \
  (1)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_PARAMETER_SETS_10_MS_INTEGRATION_TIME \
  (2)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_PARAMETER_SETS_20_MS_INTEGRATION_TIME \
  (3)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_CLOCK_VALIDITY_STATUS_MASK (0x1)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_CLOCK_VALIDITY_STATUS_SHIFT (5u)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_CLOCK_VALIDITY_STATUS_GET(flags) \
  ((u8)(((flags) >>                                                        \
         SBP_TRACKING_STATE_DETAILED_DEP_A_CLOCK_VALIDITY_STATUS_SHIFT) &  \
        SBP_TRACKING_STATE_DETAILED_DEP_A_CLOCK_VALIDITY_STATUS_MASK))
#define SBP_TRACKING_STATE_DETAILED_DEP_A_CLOCK_VALIDITY_STATUS_SET(flags,     \
                                                                    val)       \
  do {                                                                         \
    (flags) = (u8)(                                                            \
        (flags) |                                                              \
        (((val) &                                                              \
          (SBP_TRACKING_STATE_DETAILED_DEP_A_CLOCK_VALIDITY_STATUS_MASK))      \
         << (SBP_TRACKING_STATE_DETAILED_DEP_A_CLOCK_VALIDITY_STATUS_SHIFT))); \
  } while (0)

#define SBP_TRACKING_STATE_DETAILED_DEP_A_CLOCK_VALIDITY_STATUS_CLOCK_OFFSET_AND_DRIFT_IS_NOT_VALID \
  (0)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_CLOCK_VALIDITY_STATUS_CLOCK_OFFSET_AND_DRIFT_IS_VALID \
  (1)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_PSEUDORANGE_VALIDITY_STATUS_MASK (0x1)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_PSEUDORANGE_VALIDITY_STATUS_SHIFT (4u)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_PSEUDORANGE_VALIDITY_STATUS_GET(    \
    flags)                                                                    \
  ((u8)(                                                                      \
      ((flags) >>                                                             \
       SBP_TRACKING_STATE_DETAILED_DEP_A_PSEUDORANGE_VALIDITY_STATUS_SHIFT) & \
      SBP_TRACKING_STATE_DETAILED_DEP_A_PSEUDORANGE_VALIDITY_STATUS_MASK))
#define SBP_TRACKING_STATE_DETAILED_DEP_A_PSEUDORANGE_VALIDITY_STATUS_SET(           \
    flags, val)                                                                      \
  do {                                                                               \
    (flags) = (u8)(                                                                  \
        (flags) |                                                                    \
        (((val) &                                                                    \
          (SBP_TRACKING_STATE_DETAILED_DEP_A_PSEUDORANGE_VALIDITY_STATUS_MASK))      \
         << (SBP_TRACKING_STATE_DETAILED_DEP_A_PSEUDORANGE_VALIDITY_STATUS_SHIFT))); \
  } while (0)

#define SBP_TRACKING_STATE_DETAILED_DEP_A_PSEUDORANGE_VALIDITY_STATUS_PSEUDORANGE_IS_NOT_VALID \
  (0)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_PSEUDORANGE_VALIDITY_STATUS_PSEUDORANGE_IS_VALID \
  (1)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_ACCELERATION_VALIDITY_STATUS_MASK \
  (0x1)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_ACCELERATION_VALIDITY_STATUS_SHIFT \
  (3u)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_ACCELERATION_VALIDITY_STATUS_GET(    \
    flags)                                                                     \
  ((u8)(                                                                       \
      ((flags) >>                                                              \
       SBP_TRACKING_STATE_DETAILED_DEP_A_ACCELERATION_VALIDITY_STATUS_SHIFT) & \
      SBP_TRACKING_STATE_DETAILED_DEP_A_ACCELERATION_VALIDITY_STATUS_MASK))
#define SBP_TRACKING_STATE_DETAILED_DEP_A_ACCELERATION_VALIDITY_STATUS_SET(           \
    flags, val)                                                                       \
  do {                                                                                \
    (flags) = (u8)(                                                                   \
        (flags) |                                                                     \
        (((val) &                                                                     \
          (SBP_TRACKING_STATE_DETAILED_DEP_A_ACCELERATION_VALIDITY_STATUS_MASK))      \
         << (SBP_TRACKING_STATE_DETAILED_DEP_A_ACCELERATION_VALIDITY_STATUS_SHIFT))); \
  } while (0)

#define SBP_TRACKING_STATE_DETAILED_DEP_A_ACCELERATION_VALIDITY_STATUS_ACCELERATION_IS_NOT_VALID \
  (0)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_ACCELERATION_VALIDITY_STATUS_ACCELERATION_IS_VALID \
  (1)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_CARRIER_HALF_CYCLE_AMBIGUITY_STATUS_MASK \
  (0x1)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_CARRIER_HALF_CYCLE_AMBIGUITY_STATUS_SHIFT \
  (2u)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_CARRIER_HALF_CYCLE_AMBIGUITY_STATUS_GET(    \
    flags)                                                                            \
  ((u8)(                                                                              \
      ((flags) >>                                                                     \
       SBP_TRACKING_STATE_DETAILED_DEP_A_CARRIER_HALF_CYCLE_AMBIGUITY_STATUS_SHIFT) & \
      SBP_TRACKING_STATE_DETAILED_DEP_A_CARRIER_HALF_CYCLE_AMBIGUITY_STATUS_MASK))
#define SBP_TRACKING_STATE_DETAILED_DEP_A_CARRIER_HALF_CYCLE_AMBIGUITY_STATUS_SET(           \
    flags, val)                                                                              \
  do {                                                                                       \
    (flags) = (u8)(                                                                          \
        (flags) |                                                                            \
        (((val) &                                                                            \
          (SBP_TRACKING_STATE_DETAILED_DEP_A_CARRIER_HALF_CYCLE_AMBIGUITY_STATUS_MASK))      \
         << (SBP_TRACKING_STATE_DETAILED_DEP_A_CARRIER_HALF_CYCLE_AMBIGUITY_STATUS_SHIFT))); \
  } while (0)

#define SBP_TRACKING_STATE_DETAILED_DEP_A_CARRIER_HALF_CYCLE_AMBIGUITY_STATUS_UNRESOLVED \
  (0)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_CARRIER_HALF_CYCLE_AMBIGUITY_STATUS_RESOLVED \
  (1)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_TRACKING_CHANNEL_STATUS_MASK (0x3)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_TRACKING_CHANNEL_STATUS_SHIFT (0u)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_TRACKING_CHANNEL_STATUS_GET(flags) \
  ((u8)(((flags) >>                                                          \
         SBP_TRACKING_STATE_DETAILED_DEP_A_TRACKING_CHANNEL_STATUS_SHIFT) &  \
        SBP_TRACKING_STATE_DETAILED_DEP_A_TRACKING_CHANNEL_STATUS_MASK))
#define SBP_TRACKING_STATE_DETAILED_DEP_A_TRACKING_CHANNEL_STATUS_SET(flags,     \
                                                                      val)       \
  do {                                                                           \
    (flags) = (u8)(                                                              \
        (flags) |                                                                \
        (((val) &                                                                \
          (SBP_TRACKING_STATE_DETAILED_DEP_A_TRACKING_CHANNEL_STATUS_MASK))      \
         << (SBP_TRACKING_STATE_DETAILED_DEP_A_TRACKING_CHANNEL_STATUS_SHIFT))); \
  } while (0)

#define SBP_TRACKING_STATE_DETAILED_DEP_A_TRACKING_CHANNEL_STATUS_RE_ACQUISITION \
  (0)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_TRACKING_CHANNEL_STATUS_RUNNING (1)
/**
 * Encoded length of sbp_msg_tracking_state_detailed_dep_a_t (V4 API) and
 * msg_tracking_state_detailed_dep_a_t (legacy API)
 */
#define SBP_MSG_TRACKING_STATE_DETAILED_DEP_A_ENCODED_LEN 57u

#define SBP_MSG_TRACKING_STATE_DETAILED_DEP 0x0011
#define SBP_TRACKING_STATE_DETAILED_DEP_SYNCHRONIZATION_STATUS_MASK (0x7)
#define SBP_TRACKING_STATE_DETAILED_DEP_SYNCHRONIZATION_STATUS_SHIFT (0u)
#define SBP_TRACKING_STATE_DETAILED_DEP_SYNCHRONIZATION_STATUS_GET(flags) \
  ((u8)(((flags) >>                                                       \
         SBP_TRACKING_STATE_DETAILED_DEP_SYNCHRONIZATION_STATUS_SHIFT) &  \
        SBP_TRACKING_STATE_DETAILED_DEP_SYNCHRONIZATION_STATUS_MASK))
#define SBP_TRACKING_STATE_DETAILED_DEP_SYNCHRONIZATION_STATUS_SET(flags, val) \
  do {                                                                         \
    (flags) = (u8)(                                                            \
        (flags) |                                                              \
        (((val) &                                                              \
          (SBP_TRACKING_STATE_DETAILED_DEP_SYNCHRONIZATION_STATUS_MASK))       \
         << (SBP_TRACKING_STATE_DETAILED_DEP_SYNCHRONIZATION_STATUS_SHIFT)));  \
  } while (0)

#define SBP_TRACKING_STATE_DETAILED_DEP_SYNCHRONIZATION_STATUS_NO_SYNCHRONIZATION \
  (0)
#define SBP_TRACKING_STATE_DETAILED_DEP_SYNCHRONIZATION_STATUS_BIT_SYNCHRONIZATION \
  (1)
#define SBP_TRACKING_STATE_DETAILED_DEP_SYNCHRONIZATION_STATUS_WORD_SYNCHRONIZATION \
  (2)
#define SBP_TRACKING_STATE_DETAILED_DEP_SYNCHRONIZATION_STATUS_SUB_FRAME_SYNCHRONIZATION_MESSAGE_SYNCHRONIZATION \
  (3)
#define SBP_TRACKING_STATE_DETAILED_DEP_WEEK_NUMBER_VALIDITY_STATUS_MASK (0x1)
#define SBP_TRACKING_STATE_DETAILED_DEP_WEEK_NUMBER_VALIDITY_STATUS_SHIFT (3u)
#define SBP_TRACKING_STATE_DETAILED_DEP_WEEK_NUMBER_VALIDITY_STATUS_GET(flags) \
  ((u8)(((flags) >>                                                            \
         SBP_TRACKING_STATE_DETAILED_DEP_WEEK_NUMBER_VALIDITY_STATUS_SHIFT) &  \
        SBP_TRACKING_STATE_DETAILED_DEP_WEEK_NUMBER_VALIDITY_STATUS_MASK))
#define SBP_TRACKING_STATE_DETAILED_DEP_WEEK_NUMBER_VALIDITY_STATUS_SET(flags,     \
                                                                        val)       \
  do {                                                                             \
    (flags) = (u8)(                                                                \
        (flags) |                                                                  \
        (((val) &                                                                  \
          (SBP_TRACKING_STATE_DETAILED_DEP_WEEK_NUMBER_VALIDITY_STATUS_MASK))      \
         << (SBP_TRACKING_STATE_DETAILED_DEP_WEEK_NUMBER_VALIDITY_STATUS_SHIFT))); \
  } while (0)

#define SBP_TRACKING_STATE_DETAILED_DEP_WEEK_NUMBER_VALIDITY_STATUS_WEEK_NUMBER_IS_NOT_VALID \
  (0)
#define SBP_TRACKING_STATE_DETAILED_DEP_WEEK_NUMBER_VALIDITY_STATUS_WEEK_NUMBER_IS_VALID \
  (1)
#define SBP_TRACKING_STATE_DETAILED_DEP_TOW_STATUS_MASK (0x7)
#define SBP_TRACKING_STATE_DETAILED_DEP_TOW_STATUS_SHIFT (0u)
#define SBP_TRACKING_STATE_DETAILED_DEP_TOW_STATUS_GET(flags)           \
  ((u8)(((flags) >> SBP_TRACKING_STATE_DETAILED_DEP_TOW_STATUS_SHIFT) & \
        SBP_TRACKING_STATE_DETAILED_DEP_TOW_STATUS_MASK))
#define SBP_TRACKING_STATE_DETAILED_DEP_TOW_STATUS_SET(flags, val)             \
  do {                                                                         \
    (flags) = (u8)(                                                            \
        (flags) | (((val) & (SBP_TRACKING_STATE_DETAILED_DEP_TOW_STATUS_MASK)) \
                   << (SBP_TRACKING_STATE_DETAILED_DEP_TOW_STATUS_SHIFT)));    \
  } while (0)

#define SBP_TRACKING_STATE_DETAILED_DEP_TOW_STATUS_TOW_IS_NOT_AVAILABLE (0)
#define SBP_TRACKING_STATE_DETAILED_DEP_TOW_STATUS_DECODED_TOW_IS_AVAILABLE (1)
#define SBP_TRACKING_STATE_DETAILED_DEP_TOW_STATUS_PROPAGATED_TOW_IS_AVAILABLE \
  (2)
#define SBP_TRACKING_STATE_DETAILED_DEP_FLL_STATUS_MASK (0x1)
#define SBP_TRACKING_STATE_DETAILED_DEP_FLL_STATUS_SHIFT (4u)
#define SBP_TRACKING_STATE_DETAILED_DEP_FLL_STATUS_GET(flags)           \
  ((u8)(((flags) >> SBP_TRACKING_STATE_DETAILED_DEP_FLL_STATUS_SHIFT) & \
        SBP_TRACKING_STATE_DETAILED_DEP_FLL_STATUS_MASK))
#define SBP_TRACKING_STATE_DETAILED_DEP_FLL_STATUS_SET(flags, val)             \
  do {                                                                         \
    (flags) = (u8)(                                                            \
        (flags) | (((val) & (SBP_TRACKING_STATE_DETAILED_DEP_FLL_STATUS_MASK)) \
                   << (SBP_TRACKING_STATE_DETAILED_DEP_FLL_STATUS_SHIFT)));    \
  } while (0)

#define SBP_TRACKING_STATE_DETAILED_DEP_FLL_STATUS_FLL_IS_INACTIVE (0)
#define SBP_TRACKING_STATE_DETAILED_DEP_FLL_STATUS_FLL_IS_ACTIVE (1)
#define SBP_TRACKING_STATE_DETAILED_DEP_PLL_STATUS_MASK (0x1)
#define SBP_TRACKING_STATE_DETAILED_DEP_PLL_STATUS_SHIFT (3u)
#define SBP_TRACKING_STATE_DETAILED_DEP_PLL_STATUS_GET(flags)           \
  ((u8)(((flags) >> SBP_TRACKING_STATE_DETAILED_DEP_PLL_STATUS_SHIFT) & \
        SBP_TRACKING_STATE_DETAILED_DEP_PLL_STATUS_MASK))
#define SBP_TRACKING_STATE_DETAILED_DEP_PLL_STATUS_SET(flags, val)             \
  do {                                                                         \
    (flags) = (u8)(                                                            \
        (flags) | (((val) & (SBP_TRACKING_STATE_DETAILED_DEP_PLL_STATUS_MASK)) \
                   << (SBP_TRACKING_STATE_DETAILED_DEP_PLL_STATUS_SHIFT)));    \
  } while (0)

#define SBP_TRACKING_STATE_DETAILED_DEP_PLL_STATUS_PLL_IS_INACTIVE (0)
#define SBP_TRACKING_STATE_DETAILED_DEP_PLL_STATUS_PLL_IS_ACTIVE (1)
#define SBP_TRACKING_STATE_DETAILED_DEP_TRACKING_LOOP_STATUS_MASK (0x7)
#define SBP_TRACKING_STATE_DETAILED_DEP_TRACKING_LOOP_STATUS_SHIFT (0u)
#define SBP_TRACKING_STATE_DETAILED_DEP_TRACKING_LOOP_STATUS_GET(flags) \
  ((u8)(((flags) >>                                                     \
         SBP_TRACKING_STATE_DETAILED_DEP_TRACKING_LOOP_STATUS_SHIFT) &  \
        SBP_TRACKING_STATE_DETAILED_DEP_TRACKING_LOOP_STATUS_MASK))
#define SBP_TRACKING_STATE_DETAILED_DEP_TRACKING_LOOP_STATUS_SET(flags, val)   \
  do {                                                                         \
    (flags) = (u8)(                                                            \
        (flags) |                                                              \
        (((val) & (SBP_TRACKING_STATE_DETAILED_DEP_TRACKING_LOOP_STATUS_MASK)) \
         << (SBP_TRACKING_STATE_DETAILED_DEP_TRACKING_LOOP_STATUS_SHIFT)));    \
  } while (0)

#define SBP_TRACKING_STATE_DETAILED_DEP_TRACKING_LOOP_STATUS_NO_LOCKS (0)
#define SBP_TRACKING_STATE_DETAILED_DEP_TRACKING_LOOP_STATUS_FLLDLL_LOCK (1)
#define SBP_TRACKING_STATE_DETAILED_DEP_TRACKING_LOOP_STATUS_PLL_OPTIMISTIC_LOCK \
  (2)
#define SBP_TRACKING_STATE_DETAILED_DEP_TRACKING_LOOP_STATUS_PLL_PESSIMISTIC_LOCK \
  (3)
#define SBP_TRACKING_STATE_DETAILED_DEP_ALMANAC_AVAILABILITY_STATUS_MASK (0x1)
#define SBP_TRACKING_STATE_DETAILED_DEP_ALMANAC_AVAILABILITY_STATUS_SHIFT (4u)
#define SBP_TRACKING_STATE_DETAILED_DEP_ALMANAC_AVAILABILITY_STATUS_GET(flags) \
  ((u8)(((flags) >>                                                            \
         SBP_TRACKING_STATE_DETAILED_DEP_ALMANAC_AVAILABILITY_STATUS_SHIFT) &  \
        SBP_TRACKING_STATE_DETAILED_DEP_ALMANAC_AVAILABILITY_STATUS_MASK))
#define SBP_TRACKING_STATE_DETAILED_DEP_ALMANAC_AVAILABILITY_STATUS_SET(flags,     \
                                                                        val)       \
  do {                                                                             \
    (flags) = (u8)(                                                                \
        (flags) |                                                                  \
        (((val) &                                                                  \
          (SBP_TRACKING_STATE_DETAILED_DEP_ALMANAC_AVAILABILITY_STATUS_MASK))      \
         << (SBP_TRACKING_STATE_DETAILED_DEP_ALMANAC_AVAILABILITY_STATUS_SHIFT))); \
  } while (0)

#define SBP_TRACKING_STATE_DETAILED_DEP_ALMANAC_AVAILABILITY_STATUS_ALMANAC_IS_NOT_AVAILABLE \
  (0)
#define SBP_TRACKING_STATE_DETAILED_DEP_ALMANAC_AVAILABILITY_STATUS_ALMANAC_IS_AVAILABLE \
  (1)
#define SBP_TRACKING_STATE_DETAILED_DEP_EPHEMERIS_AVAILABILITY_STATUS_MASK (0x1)
#define SBP_TRACKING_STATE_DETAILED_DEP_EPHEMERIS_AVAILABILITY_STATUS_SHIFT (3u)
#define SBP_TRACKING_STATE_DETAILED_DEP_EPHEMERIS_AVAILABILITY_STATUS_GET(    \
    flags)                                                                    \
  ((u8)(                                                                      \
      ((flags) >>                                                             \
       SBP_TRACKING_STATE_DETAILED_DEP_EPHEMERIS_AVAILABILITY_STATUS_SHIFT) & \
      SBP_TRACKING_STATE_DETAILED_DEP_EPHEMERIS_AVAILABILITY_STATUS_MASK))
#define SBP_TRACKING_STATE_DETAILED_DEP_EPHEMERIS_AVAILABILITY_STATUS_SET(           \
    flags, val)                                                                      \
  do {                                                                               \
    (flags) = (u8)(                                                                  \
        (flags) |                                                                    \
        (((val) &                                                                    \
          (SBP_TRACKING_STATE_DETAILED_DEP_EPHEMERIS_AVAILABILITY_STATUS_MASK))      \
         << (SBP_TRACKING_STATE_DETAILED_DEP_EPHEMERIS_AVAILABILITY_STATUS_SHIFT))); \
  } while (0)

#define SBP_TRACKING_STATE_DETAILED_DEP_EPHEMERIS_AVAILABILITY_STATUS_EPHEMERIS_IS_NOT_AVAILABLE \
  (0)
#define SBP_TRACKING_STATE_DETAILED_DEP_EPHEMERIS_AVAILABILITY_STATUS_EPHEMERIS_IS_AVAILABLE \
  (1)
#define SBP_TRACKING_STATE_DETAILED_DEP_HEALTH_STATUS_MASK (0x7)
#define SBP_TRACKING_STATE_DETAILED_DEP_HEALTH_STATUS_SHIFT (0u)
#define SBP_TRACKING_STATE_DETAILED_DEP_HEALTH_STATUS_GET(flags)           \
  ((u8)(((flags) >> SBP_TRACKING_STATE_DETAILED_DEP_HEALTH_STATUS_SHIFT) & \
        SBP_TRACKING_STATE_DETAILED_DEP_HEALTH_STATUS_MASK))
#define SBP_TRACKING_STATE_DETAILED_DEP_HEALTH_STATUS_SET(flags, val)        \
  do {                                                                       \
    (flags) =                                                                \
        (u8)((flags) |                                                       \
             (((val) & (SBP_TRACKING_STATE_DETAILED_DEP_HEALTH_STATUS_MASK)) \
              << (SBP_TRACKING_STATE_DETAILED_DEP_HEALTH_STATUS_SHIFT)));    \
  } while (0)

#define SBP_TRACKING_STATE_DETAILED_DEP_HEALTH_STATUS_HEALTH_IS_UNKNOWN (0)
#define SBP_TRACKING_STATE_DETAILED_DEP_HEALTH_STATUS_SIGNAL_IS_UNHEALTHY (1)
#define SBP_TRACKING_STATE_DETAILED_DEP_HEALTH_STATUS_SIGNAL_IS_HEALTHY (2)
#define SBP_TRACKING_STATE_DETAILED_DEP_PARAMETER_SETS_MASK (0x7)
#define SBP_TRACKING_STATE_DETAILED_DEP_PARAMETER_SETS_SHIFT (0u)
#define SBP_TRACKING_STATE_DETAILED_DEP_PARAMETER_SETS_GET(flags)           \
  ((u8)(((flags) >> SBP_TRACKING_STATE_DETAILED_DEP_PARAMETER_SETS_SHIFT) & \
        SBP_TRACKING_STATE_DETAILED_DEP_PARAMETER_SETS_MASK))
#define SBP_TRACKING_STATE_DETAILED_DEP_PARAMETER_SETS_SET(flags, val)        \
  do {                                                                        \
    (flags) =                                                                 \
        (u8)((flags) |                                                        \
             (((val) & (SBP_TRACKING_STATE_DETAILED_DEP_PARAMETER_SETS_MASK)) \
              << (SBP_TRACKING_STATE_DETAILED_DEP_PARAMETER_SETS_SHIFT)));    \
  } while (0)

#define SBP_TRACKING_STATE_DETAILED_DEP_PARAMETER_SETS_1_MS_INTEGRATION_TIME (0)
#define SBP_TRACKING_STATE_DETAILED_DEP_PARAMETER_SETS_5_MS_INTEGRATION_TIME (1)
#define SBP_TRACKING_STATE_DETAILED_DEP_PARAMETER_SETS_10_MS_INTEGRATION_TIME \
  (2)
#define SBP_TRACKING_STATE_DETAILED_DEP_PARAMETER_SETS_20_MS_INTEGRATION_TIME \
  (3)
#define SBP_TRACKING_STATE_DETAILED_DEP_CLOCK_VALIDITY_STATUS_MASK (0x1)
#define SBP_TRACKING_STATE_DETAILED_DEP_CLOCK_VALIDITY_STATUS_SHIFT (5u)
#define SBP_TRACKING_STATE_DETAILED_DEP_CLOCK_VALIDITY_STATUS_GET(flags) \
  ((u8)(((flags) >>                                                      \
         SBP_TRACKING_STATE_DETAILED_DEP_CLOCK_VALIDITY_STATUS_SHIFT) &  \
        SBP_TRACKING_STATE_DETAILED_DEP_CLOCK_VALIDITY_STATUS_MASK))
#define SBP_TRACKING_STATE_DETAILED_DEP_CLOCK_VALIDITY_STATUS_SET(flags, val) \
  do {                                                                        \
    (flags) = (u8)(                                                           \
        (flags) |                                                             \
        (((val) &                                                             \
          (SBP_TRACKING_STATE_DETAILED_DEP_CLOCK_VALIDITY_STATUS_MASK))       \
         << (SBP_TRACKING_STATE_DETAILED_DEP_CLOCK_VALIDITY_STATUS_SHIFT)));  \
  } while (0)

#define SBP_TRACKING_STATE_DETAILED_DEP_CLOCK_VALIDITY_STATUS_CLOCK_OFFSET_AND_DRIFT_IS_NOT_VALID \
  (0)
#define SBP_TRACKING_STATE_DETAILED_DEP_CLOCK_VALIDITY_STATUS_CLOCK_OFFSET_AND_DRIFT_IS_VALID \
  (1)
#define SBP_TRACKING_STATE_DETAILED_DEP_PSEUDORANGE_VALIDITY_STATUS_MASK (0x1)
#define SBP_TRACKING_STATE_DETAILED_DEP_PSEUDORANGE_VALIDITY_STATUS_SHIFT (4u)
#define SBP_TRACKING_STATE_DETAILED_DEP_PSEUDORANGE_VALIDITY_STATUS_GET(flags) \
  ((u8)(((flags) >>                                                            \
         SBP_TRACKING_STATE_DETAILED_DEP_PSEUDORANGE_VALIDITY_STATUS_SHIFT) &  \
        SBP_TRACKING_STATE_DETAILED_DEP_PSEUDORANGE_VALIDITY_STATUS_MASK))
#define SBP_TRACKING_STATE_DETAILED_DEP_PSEUDORANGE_VALIDITY_STATUS_SET(flags,     \
                                                                        val)       \
  do {                                                                             \
    (flags) = (u8)(                                                                \
        (flags) |                                                                  \
        (((val) &                                                                  \
          (SBP_TRACKING_STATE_DETAILED_DEP_PSEUDORANGE_VALIDITY_STATUS_MASK))      \
         << (SBP_TRACKING_STATE_DETAILED_DEP_PSEUDORANGE_VALIDITY_STATUS_SHIFT))); \
  } while (0)

#define SBP_TRACKING_STATE_DETAILED_DEP_PSEUDORANGE_VALIDITY_STATUS_PSEUDORANGE_IS_NOT_VALID \
  (0)
#define SBP_TRACKING_STATE_DETAILED_DEP_PSEUDORANGE_VALIDITY_STATUS_PSEUDORANGE_IS_VALID \
  (1)
#define SBP_TRACKING_STATE_DETAILED_DEP_ACCELERATION_VALIDITY_STATUS_MASK (0x1)
#define SBP_TRACKING_STATE_DETAILED_DEP_ACCELERATION_VALIDITY_STATUS_SHIFT (3u)
#define SBP_TRACKING_STATE_DETAILED_DEP_ACCELERATION_VALIDITY_STATUS_GET(      \
    flags)                                                                     \
  ((u8)(((flags) >>                                                            \
         SBP_TRACKING_STATE_DETAILED_DEP_ACCELERATION_VALIDITY_STATUS_SHIFT) & \
        SBP_TRACKING_STATE_DETAILED_DEP_ACCELERATION_VALIDITY_STATUS_MASK))
#define SBP_TRACKING_STATE_DETAILED_DEP_ACCELERATION_VALIDITY_STATUS_SET(           \
    flags, val)                                                                     \
  do {                                                                              \
    (flags) = (u8)(                                                                 \
        (flags) |                                                                   \
        (((val) &                                                                   \
          (SBP_TRACKING_STATE_DETAILED_DEP_ACCELERATION_VALIDITY_STATUS_MASK))      \
         << (SBP_TRACKING_STATE_DETAILED_DEP_ACCELERATION_VALIDITY_STATUS_SHIFT))); \
  } while (0)

#define SBP_TRACKING_STATE_DETAILED_DEP_ACCELERATION_VALIDITY_STATUS_ACCELERATION_IS_NOT_VALID \
  (0)
#define SBP_TRACKING_STATE_DETAILED_DEP_ACCELERATION_VALIDITY_STATUS_ACCELERATION_IS_VALID \
  (1)
#define SBP_TRACKING_STATE_DETAILED_DEP_CARRIER_HALF_CYCLE_AMBIGUITY_STATUS_MASK \
  (0x1)
#define SBP_TRACKING_STATE_DETAILED_DEP_CARRIER_HALF_CYCLE_AMBIGUITY_STATUS_SHIFT \
  (2u)
#define SBP_TRACKING_STATE_DETAILED_DEP_CARRIER_HALF_CYCLE_AMBIGUITY_STATUS_GET(    \
    flags)                                                                          \
  ((u8)(                                                                            \
      ((flags) >>                                                                   \
       SBP_TRACKING_STATE_DETAILED_DEP_CARRIER_HALF_CYCLE_AMBIGUITY_STATUS_SHIFT) & \
      SBP_TRACKING_STATE_DETAILED_DEP_CARRIER_HALF_CYCLE_AMBIGUITY_STATUS_MASK))
#define SBP_TRACKING_STATE_DETAILED_DEP_CARRIER_HALF_CYCLE_AMBIGUITY_STATUS_SET(           \
    flags, val)                                                                            \
  do {                                                                                     \
    (flags) = (u8)(                                                                        \
        (flags) |                                                                          \
        (((val) &                                                                          \
          (SBP_TRACKING_STATE_DETAILED_DEP_CARRIER_HALF_CYCLE_AMBIGUITY_STATUS_MASK))      \
         << (SBP_TRACKING_STATE_DETAILED_DEP_CARRIER_HALF_CYCLE_AMBIGUITY_STATUS_SHIFT))); \
  } while (0)

#define SBP_TRACKING_STATE_DETAILED_DEP_CARRIER_HALF_CYCLE_AMBIGUITY_STATUS_UNRESOLVED \
  (0)
#define SBP_TRACKING_STATE_DETAILED_DEP_CARRIER_HALF_CYCLE_AMBIGUITY_STATUS_RESOLVED \
  (1)
#define SBP_TRACKING_STATE_DETAILED_DEP_TRACKING_CHANNEL_STATUS_MASK (0x3)
#define SBP_TRACKING_STATE_DETAILED_DEP_TRACKING_CHANNEL_STATUS_SHIFT (0u)
#define SBP_TRACKING_STATE_DETAILED_DEP_TRACKING_CHANNEL_STATUS_GET(flags) \
  ((u8)(((flags) >>                                                        \
         SBP_TRACKING_STATE_DETAILED_DEP_TRACKING_CHANNEL_STATUS_SHIFT) &  \
        SBP_TRACKING_STATE_DETAILED_DEP_TRACKING_CHANNEL_STATUS_MASK))
#define SBP_TRACKING_STATE_DETAILED_DEP_TRACKING_CHANNEL_STATUS_SET(flags,     \
                                                                    val)       \
  do {                                                                         \
    (flags) = (u8)(                                                            \
        (flags) |                                                              \
        (((val) &                                                              \
          (SBP_TRACKING_STATE_DETAILED_DEP_TRACKING_CHANNEL_STATUS_MASK))      \
         << (SBP_TRACKING_STATE_DETAILED_DEP_TRACKING_CHANNEL_STATUS_SHIFT))); \
  } while (0)

#define SBP_TRACKING_STATE_DETAILED_DEP_TRACKING_CHANNEL_STATUS_RE_ACQUISITION \
  (0)
#define SBP_TRACKING_STATE_DETAILED_DEP_TRACKING_CHANNEL_STATUS_RUNNING (1)
/**
 * Encoded length of sbp_msg_tracking_state_detailed_dep_t (V4 API) and
 * msg_tracking_state_detailed_dep_t (legacy API)
 */
#define SBP_MSG_TRACKING_STATE_DETAILED_DEP_ENCODED_LEN 55u

/**
 * Encoded length of sbp_tracking_channel_state_t (V4 API) and
 * tracking_channel_state_t (legacy API)
 */
#define SBP_TRACKING_CHANNEL_STATE_ENCODED_LEN 4u

#define SBP_MSG_TRACKING_STATE 0x0041
/**
 * The maximum number of items that can be stored in
 * sbp_msg_tracking_state_t::states (V4 API) or msg_tracking_state_t::states
 * (legacy API) before the maximum SBP message size is exceeded
 */
#define SBP_MSG_TRACKING_STATE_STATES_MAX 63u

/**
 * Encoded length of sbp_msg_tracking_state_t (V4 API) and
 * msg_tracking_state_t (legacy API)
 *
 * This type is not fixed size and an instance of this message may be longer
 * than the value indicated by this symbol. Users of the V4 API should call
 * #sbp_msg_tracking_state_encoded_len to determine the actual size of an
 * instance of this message. Users of the legacy API are required to track the
 * encoded message length when interacting with the legacy type.
 *
 * See the documentation for libsbp for more details regarding the message
 * structure and its variable length component(s)
 */
#define SBP_MSG_TRACKING_STATE_ENCODED_OVERHEAD 0u

/**
 * Encoded length of sbp_measurement_state_t (V4 API) and
 * measurement_state_t (legacy API)
 */
#define SBP_MEASUREMENT_STATE_ENCODED_LEN 3u

#define SBP_MSG_MEASUREMENT_STATE 0x0061
/**
 * The maximum number of items that can be stored in
 * sbp_msg_measurement_state_t::states (V4 API) or
 * msg_measurement_state_t::states (legacy API) before the maximum SBP message
 * size is exceeded
 */
#define SBP_MSG_MEASUREMENT_STATE_STATES_MAX 85u

/**
 * Encoded length of sbp_msg_measurement_state_t (V4 API) and
 * msg_measurement_state_t (legacy API)
 *
 * This type is not fixed size and an instance of this message may be longer
 * than the value indicated by this symbol. Users of the V4 API should call
 * #sbp_msg_measurement_state_encoded_len to determine the actual size of an
 * instance of this message. Users of the legacy API are required to track the
 * encoded message length when interacting with the legacy type.
 *
 * See the documentation for libsbp for more details regarding the message
 * structure and its variable length component(s)
 */
#define SBP_MSG_MEASUREMENT_STATE_ENCODED_OVERHEAD 0u

/**
 * Encoded length of sbp_tracking_channel_correlation_t (V4 API) and
 * tracking_channel_correlation_t (legacy API)
 */
#define SBP_TRACKING_CHANNEL_CORRELATION_ENCODED_LEN 4u

#define SBP_MSG_TRACKING_IQ 0x002D
/**
 * The maximum number of items that can be stored in
 * sbp_msg_tracking_iq_t::corrs (V4 API) or msg_tracking_iq_t::corrs (legacy
 * API) before the maximum SBP message size is exceeded
 */
#define SBP_MSG_TRACKING_IQ_CORRS_MAX 3u

/**
 * Encoded length of sbp_msg_tracking_iq_t (V4 API) and
 * msg_tracking_iq_t (legacy API)
 */
#define SBP_MSG_TRACKING_IQ_ENCODED_LEN 15u

/**
 * Encoded length of sbp_tracking_channel_correlation_dep_t (V4 API) and
 * tracking_channel_correlation_dep_t (legacy API)
 */
#define SBP_TRACKING_CHANNEL_CORRELATION_DEP_ENCODED_LEN 8u

#define SBP_MSG_TRACKING_IQ_DEP_B 0x002C
/**
 * The maximum number of items that can be stored in
 * sbp_msg_tracking_iq_dep_b_t::corrs (V4 API) or msg_tracking_iq_dep_b_t::corrs
 * (legacy API) before the maximum SBP message size is exceeded
 */
#define SBP_MSG_TRACKING_IQ_DEP_B_CORRS_MAX 3u

/**
 * Encoded length of sbp_msg_tracking_iq_dep_b_t (V4 API) and
 * msg_tracking_iq_dep_b_t (legacy API)
 */
#define SBP_MSG_TRACKING_IQ_DEP_B_ENCODED_LEN 27u

#define SBP_MSG_TRACKING_IQ_DEP_A 0x001C
/**
 * The maximum number of items that can be stored in
 * sbp_msg_tracking_iq_dep_a_t::corrs (V4 API) or msg_tracking_iq_dep_a_t::corrs
 * (legacy API) before the maximum SBP message size is exceeded
 */
#define SBP_MSG_TRACKING_IQ_DEP_A_CORRS_MAX 3u

/**
 * Encoded length of sbp_msg_tracking_iq_dep_a_t (V4 API) and
 * msg_tracking_iq_dep_a_t (legacy API)
 */
#define SBP_MSG_TRACKING_IQ_DEP_A_ENCODED_LEN 29u

#define SBP_TRACKINGCHANNELSTATEDEPA_TRACKING_MODE_MASK (0x3)
#define SBP_TRACKINGCHANNELSTATEDEPA_TRACKING_MODE_SHIFT (0u)
#define SBP_TRACKINGCHANNELSTATEDEPA_TRACKING_MODE_GET(flags)           \
  ((u8)(((flags) >> SBP_TRACKINGCHANNELSTATEDEPA_TRACKING_MODE_SHIFT) & \
        SBP_TRACKINGCHANNELSTATEDEPA_TRACKING_MODE_MASK))
#define SBP_TRACKINGCHANNELSTATEDEPA_TRACKING_MODE_SET(flags, val)             \
  do {                                                                         \
    (flags) = (u8)(                                                            \
        (flags) | (((val) & (SBP_TRACKINGCHANNELSTATEDEPA_TRACKING_MODE_MASK)) \
                   << (SBP_TRACKINGCHANNELSTATEDEPA_TRACKING_MODE_SHIFT)));    \
  } while (0)

#define SBP_TRACKINGCHANNELSTATEDEPA_TRACKING_MODE_DISABLED (0)
#define SBP_TRACKINGCHANNELSTATEDEPA_TRACKING_MODE_RUNNING (1)
/**
 * Encoded length of sbp_tracking_channel_state_dep_a_t (V4 API) and
 * tracking_channel_state_dep_a_t (legacy API)
 */
#define SBP_TRACKING_CHANNEL_STATE_DEP_A_ENCODED_LEN 6u

#define SBP_MSG_TRACKING_STATE_DEP_A 0x0016
/**
 * The maximum number of items that can be stored in
 * sbp_msg_tracking_state_dep_a_t::states (V4 API) or
 * msg_tracking_state_dep_a_t::states (legacy API) before the maximum SBP
 * message size is exceeded
 */
#define SBP_MSG_TRACKING_STATE_DEP_A_STATES_MAX 42u

/**
 * Encoded length of sbp_msg_tracking_state_dep_a_t (V4 API) and
 * msg_tracking_state_dep_a_t (legacy API)
 *
 * This type is not fixed size and an instance of this message may be longer
 * than the value indicated by this symbol. Users of the V4 API should call
 * #sbp_msg_tracking_state_dep_a_encoded_len to determine the actual size of an
 * instance of this message. Users of the legacy API are required to track the
 * encoded message length when interacting with the legacy type.
 *
 * See the documentation for libsbp for more details regarding the message
 * structure and its variable length component(s)
 */
#define SBP_MSG_TRACKING_STATE_DEP_A_ENCODED_OVERHEAD 0u

#define SBP_TRACKINGCHANNELSTATEDEPB_TRACKING_MODE_MASK (0x3)
#define SBP_TRACKINGCHANNELSTATEDEPB_TRACKING_MODE_SHIFT (0u)
#define SBP_TRACKINGCHANNELSTATEDEPB_TRACKING_MODE_GET(flags)           \
  ((u8)(((flags) >> SBP_TRACKINGCHANNELSTATEDEPB_TRACKING_MODE_SHIFT) & \
        SBP_TRACKINGCHANNELSTATEDEPB_TRACKING_MODE_MASK))
#define SBP_TRACKINGCHANNELSTATEDEPB_TRACKING_MODE_SET(flags, val)             \
  do {                                                                         \
    (flags) = (u8)(                                                            \
        (flags) | (((val) & (SBP_TRACKINGCHANNELSTATEDEPB_TRACKING_MODE_MASK)) \
                   << (SBP_TRACKINGCHANNELSTATEDEPB_TRACKING_MODE_SHIFT)));    \
  } while (0)

#define SBP_TRACKINGCHANNELSTATEDEPB_TRACKING_MODE_DISABLED (0)
#define SBP_TRACKINGCHANNELSTATEDEPB_TRACKING_MODE_RUNNING (1)
/**
 * Encoded length of sbp_tracking_channel_state_dep_b_t (V4 API) and
 * tracking_channel_state_dep_b_t (legacy API)
 */
#define SBP_TRACKING_CHANNEL_STATE_DEP_B_ENCODED_LEN 9u

#define SBP_MSG_TRACKING_STATE_DEP_B 0x0013
/**
 * The maximum number of items that can be stored in
 * sbp_msg_tracking_state_dep_b_t::states (V4 API) or
 * msg_tracking_state_dep_b_t::states (legacy API) before the maximum SBP
 * message size is exceeded
 */
#define SBP_MSG_TRACKING_STATE_DEP_B_STATES_MAX 28u

/**
 * Encoded length of sbp_msg_tracking_state_dep_b_t (V4 API) and
 * msg_tracking_state_dep_b_t (legacy API)
 *
 * This type is not fixed size and an instance of this message may be longer
 * than the value indicated by this symbol. Users of the V4 API should call
 * #sbp_msg_tracking_state_dep_b_encoded_len to determine the actual size of an
 * instance of this message. Users of the legacy API are required to track the
 * encoded message length when interacting with the legacy type.
 *
 * See the documentation for libsbp for more details regarding the message
 * structure and its variable length component(s)
 */
#define SBP_MSG_TRACKING_STATE_DEP_B_ENCODED_OVERHEAD 0u

#endif /* LIBSBP_TRACKING_MACROS_H */
