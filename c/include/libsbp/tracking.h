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
 * Automatically generated from yaml/swiftnav/sbp/tracking.yaml
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

/** \defgroup tracking Tracking
 *
 *  * Satellite code and carrier-phase tracking messages from the device.
 * \{ */

#ifndef LIBSBP_TRACKING_MESSAGES_H
#define LIBSBP_TRACKING_MESSAGES_H

#include "common.h"
#include "gnss.h"

SBP_PACK_START
#ifdef __ghs__
#pragma pack(1)
#endif


/** Detailed signal tracking channel states. DEPRECATED.
 *
 * The tracking message returns a set tracking channel parameters for a
 * single tracking channel useful for debugging issues.
 */
#define SBP_MSG_TRACKING_STATE_DETAILED_DEP_A 0x0021
#define SBP_TRACKING_STATE_DETAILED_DEP_A_SYNCHRONIZATION_STATUS_MASK (0x7)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_SYNCHRONIZATION_STATUS_SHIFT (0u)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_SYNCHRONIZATION_STATUS_GET(flags) \
                             (((flags) >> SBP_TRACKING_STATE_DETAILED_DEP_A_SYNCHRONIZATION_STATUS_SHIFT) \
                             & SBP_TRACKING_STATE_DETAILED_DEP_A_SYNCHRONIZATION_STATUS_MASK)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_SYNCHRONIZATION_STATUS_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_TRACKING_STATE_DETAILED_DEP_A_SYNCHRONIZATION_STATUS_MASK)) \
                             << (SBP_TRACKING_STATE_DETAILED_DEP_A_SYNCHRONIZATION_STATUS_SHIFT)));} while(0)
                             

#define SBP_TRACKING_STATE_DETAILED_DEP_A_SYNCHRONIZATION_STATUS_NO_SYNCHRONIZATION (0)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_SYNCHRONIZATION_STATUS_BIT_SYNCHRONIZATION (1)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_SYNCHRONIZATION_STATUS_WORD_SYNCHRONIZATION (2)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_SYNCHRONIZATION_STATUS_SUB_FRAME_SYNCHRONIZATION_MESSAGE_SYNCHRONIZATION (3)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_WEEK_NUMBER_VALIDITY_STATUS_MASK (0x1)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_WEEK_NUMBER_VALIDITY_STATUS_SHIFT (3u)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_WEEK_NUMBER_VALIDITY_STATUS_GET(flags) \
                             (((flags) >> SBP_TRACKING_STATE_DETAILED_DEP_A_WEEK_NUMBER_VALIDITY_STATUS_SHIFT) \
                             & SBP_TRACKING_STATE_DETAILED_DEP_A_WEEK_NUMBER_VALIDITY_STATUS_MASK)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_WEEK_NUMBER_VALIDITY_STATUS_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_TRACKING_STATE_DETAILED_DEP_A_WEEK_NUMBER_VALIDITY_STATUS_MASK)) \
                             << (SBP_TRACKING_STATE_DETAILED_DEP_A_WEEK_NUMBER_VALIDITY_STATUS_SHIFT)));} while(0)
                             

#define SBP_TRACKING_STATE_DETAILED_DEP_A_WEEK_NUMBER_VALIDITY_STATUS_WEEK_NUMBER_IS_NOT_VALID (0)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_WEEK_NUMBER_VALIDITY_STATUS_WEEK_NUMBER_IS_VALID (1)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_TOW_STATUS_MASK (0x7)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_TOW_STATUS_SHIFT (0u)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_TOW_STATUS_GET(flags) \
                             (((flags) >> SBP_TRACKING_STATE_DETAILED_DEP_A_TOW_STATUS_SHIFT) \
                             & SBP_TRACKING_STATE_DETAILED_DEP_A_TOW_STATUS_MASK)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_TOW_STATUS_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_TRACKING_STATE_DETAILED_DEP_A_TOW_STATUS_MASK)) \
                             << (SBP_TRACKING_STATE_DETAILED_DEP_A_TOW_STATUS_SHIFT)));} while(0)
                             

#define SBP_TRACKING_STATE_DETAILED_DEP_A_TOW_STATUS_TOW_IS_NOT_AVAILABLE (0)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_TOW_STATUS_DECODED_TOW_IS_AVAILABLE (1)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_TOW_STATUS_PROPAGATED_TOW_IS_AVAILABLE (2)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_FLL_STATUS_MASK (0x1)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_FLL_STATUS_SHIFT (4u)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_FLL_STATUS_GET(flags) \
                             (((flags) >> SBP_TRACKING_STATE_DETAILED_DEP_A_FLL_STATUS_SHIFT) \
                             & SBP_TRACKING_STATE_DETAILED_DEP_A_FLL_STATUS_MASK)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_FLL_STATUS_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_TRACKING_STATE_DETAILED_DEP_A_FLL_STATUS_MASK)) \
                             << (SBP_TRACKING_STATE_DETAILED_DEP_A_FLL_STATUS_SHIFT)));} while(0)
                             

#define SBP_TRACKING_STATE_DETAILED_DEP_A_FLL_STATUS_FLL_IS_INACTIVE (0)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_FLL_STATUS_FLL_IS_ACTIVE (1)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_PLL_STATUS_MASK (0x1)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_PLL_STATUS_SHIFT (3u)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_PLL_STATUS_GET(flags) \
                             (((flags) >> SBP_TRACKING_STATE_DETAILED_DEP_A_PLL_STATUS_SHIFT) \
                             & SBP_TRACKING_STATE_DETAILED_DEP_A_PLL_STATUS_MASK)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_PLL_STATUS_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_TRACKING_STATE_DETAILED_DEP_A_PLL_STATUS_MASK)) \
                             << (SBP_TRACKING_STATE_DETAILED_DEP_A_PLL_STATUS_SHIFT)));} while(0)
                             

#define SBP_TRACKING_STATE_DETAILED_DEP_A_PLL_STATUS_PLL_IS_INACTIVE (0)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_PLL_STATUS_PLL_IS_ACTIVE (1)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_TRACKING_LOOP_STATUS_MASK (0x7)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_TRACKING_LOOP_STATUS_SHIFT (0u)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_TRACKING_LOOP_STATUS_GET(flags) \
                             (((flags) >> SBP_TRACKING_STATE_DETAILED_DEP_A_TRACKING_LOOP_STATUS_SHIFT) \
                             & SBP_TRACKING_STATE_DETAILED_DEP_A_TRACKING_LOOP_STATUS_MASK)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_TRACKING_LOOP_STATUS_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_TRACKING_STATE_DETAILED_DEP_A_TRACKING_LOOP_STATUS_MASK)) \
                             << (SBP_TRACKING_STATE_DETAILED_DEP_A_TRACKING_LOOP_STATUS_SHIFT)));} while(0)
                             

#define SBP_TRACKING_STATE_DETAILED_DEP_A_TRACKING_LOOP_STATUS_NO_LOCKS (0)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_TRACKING_LOOP_STATUS_FLLDLL_LOCK (1)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_TRACKING_LOOP_STATUS_PLL_OPTIMISTIC_LOCK (2)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_TRACKING_LOOP_STATUS_PLL_PESSIMISTIC_LOCK (3)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_ALMANAC_AVAILABILITY_STATUS_MASK (0x1)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_ALMANAC_AVAILABILITY_STATUS_SHIFT (4u)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_ALMANAC_AVAILABILITY_STATUS_GET(flags) \
                             (((flags) >> SBP_TRACKING_STATE_DETAILED_DEP_A_ALMANAC_AVAILABILITY_STATUS_SHIFT) \
                             & SBP_TRACKING_STATE_DETAILED_DEP_A_ALMANAC_AVAILABILITY_STATUS_MASK)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_ALMANAC_AVAILABILITY_STATUS_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_TRACKING_STATE_DETAILED_DEP_A_ALMANAC_AVAILABILITY_STATUS_MASK)) \
                             << (SBP_TRACKING_STATE_DETAILED_DEP_A_ALMANAC_AVAILABILITY_STATUS_SHIFT)));} while(0)
                             

#define SBP_TRACKING_STATE_DETAILED_DEP_A_ALMANAC_AVAILABILITY_STATUS_ALMANAC_IS_NOT_AVAILABLE (0)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_ALMANAC_AVAILABILITY_STATUS_ALMANAC_IS_AVAILABLE (1)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_EPHEMERIS_AVAILABILITY_STATUS_MASK (0x1)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_EPHEMERIS_AVAILABILITY_STATUS_SHIFT (3u)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_EPHEMERIS_AVAILABILITY_STATUS_GET(flags) \
                             (((flags) >> SBP_TRACKING_STATE_DETAILED_DEP_A_EPHEMERIS_AVAILABILITY_STATUS_SHIFT) \
                             & SBP_TRACKING_STATE_DETAILED_DEP_A_EPHEMERIS_AVAILABILITY_STATUS_MASK)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_EPHEMERIS_AVAILABILITY_STATUS_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_TRACKING_STATE_DETAILED_DEP_A_EPHEMERIS_AVAILABILITY_STATUS_MASK)) \
                             << (SBP_TRACKING_STATE_DETAILED_DEP_A_EPHEMERIS_AVAILABILITY_STATUS_SHIFT)));} while(0)
                             

#define SBP_TRACKING_STATE_DETAILED_DEP_A_EPHEMERIS_AVAILABILITY_STATUS_EPHEMERIS_IS_NOT_AVAILABLE (0)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_EPHEMERIS_AVAILABILITY_STATUS_EPHEMERIS_IS_AVAILABLE (1)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_HEALTH_STATUS_MASK (0x7)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_HEALTH_STATUS_SHIFT (0u)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_HEALTH_STATUS_GET(flags) \
                             (((flags) >> SBP_TRACKING_STATE_DETAILED_DEP_A_HEALTH_STATUS_SHIFT) \
                             & SBP_TRACKING_STATE_DETAILED_DEP_A_HEALTH_STATUS_MASK)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_HEALTH_STATUS_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_TRACKING_STATE_DETAILED_DEP_A_HEALTH_STATUS_MASK)) \
                             << (SBP_TRACKING_STATE_DETAILED_DEP_A_HEALTH_STATUS_SHIFT)));} while(0)
                             

#define SBP_TRACKING_STATE_DETAILED_DEP_A_HEALTH_STATUS_HEALTH_IS_UNKNOWN (0)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_HEALTH_STATUS_SIGNAL_IS_UNHEALTHY (1)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_HEALTH_STATUS_SIGNAL_IS_HEALTHY (2)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_PARAMETER_SETS_MASK (0x7)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_PARAMETER_SETS_SHIFT (0u)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_PARAMETER_SETS_GET(flags) \
                             (((flags) >> SBP_TRACKING_STATE_DETAILED_DEP_A_PARAMETER_SETS_SHIFT) \
                             & SBP_TRACKING_STATE_DETAILED_DEP_A_PARAMETER_SETS_MASK)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_PARAMETER_SETS_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_TRACKING_STATE_DETAILED_DEP_A_PARAMETER_SETS_MASK)) \
                             << (SBP_TRACKING_STATE_DETAILED_DEP_A_PARAMETER_SETS_SHIFT)));} while(0)
                             

#define SBP_TRACKING_STATE_DETAILED_DEP_A_PARAMETER_SETS_1_MS_INTEGRATION_TIME (0)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_PARAMETER_SETS_5_MS_INTEGRATION_TIME (1)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_PARAMETER_SETS_10_MS_INTEGRATION_TIME (2)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_PARAMETER_SETS_20_MS_INTEGRATION_TIME (3)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_CLOCK_VALIDITY_STATUS_MASK (0x1)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_CLOCK_VALIDITY_STATUS_SHIFT (5u)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_CLOCK_VALIDITY_STATUS_GET(flags) \
                             (((flags) >> SBP_TRACKING_STATE_DETAILED_DEP_A_CLOCK_VALIDITY_STATUS_SHIFT) \
                             & SBP_TRACKING_STATE_DETAILED_DEP_A_CLOCK_VALIDITY_STATUS_MASK)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_CLOCK_VALIDITY_STATUS_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_TRACKING_STATE_DETAILED_DEP_A_CLOCK_VALIDITY_STATUS_MASK)) \
                             << (SBP_TRACKING_STATE_DETAILED_DEP_A_CLOCK_VALIDITY_STATUS_SHIFT)));} while(0)
                             

#define SBP_TRACKING_STATE_DETAILED_DEP_A_CLOCK_VALIDITY_STATUS_CLOCK_OFFSET_AND_DRIFT_IS_NOT_VALID (0)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_CLOCK_VALIDITY_STATUS_CLOCK_OFFSET_AND_DRIFT_IS_VALID (1)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_PSEUDORANGE_VALIDITY_STATUS_MASK (0x1)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_PSEUDORANGE_VALIDITY_STATUS_SHIFT (4u)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_PSEUDORANGE_VALIDITY_STATUS_GET(flags) \
                             (((flags) >> SBP_TRACKING_STATE_DETAILED_DEP_A_PSEUDORANGE_VALIDITY_STATUS_SHIFT) \
                             & SBP_TRACKING_STATE_DETAILED_DEP_A_PSEUDORANGE_VALIDITY_STATUS_MASK)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_PSEUDORANGE_VALIDITY_STATUS_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_TRACKING_STATE_DETAILED_DEP_A_PSEUDORANGE_VALIDITY_STATUS_MASK)) \
                             << (SBP_TRACKING_STATE_DETAILED_DEP_A_PSEUDORANGE_VALIDITY_STATUS_SHIFT)));} while(0)
                             

#define SBP_TRACKING_STATE_DETAILED_DEP_A_PSEUDORANGE_VALIDITY_STATUS_PSEUDORANGE_IS_NOT_VALID (0)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_PSEUDORANGE_VALIDITY_STATUS_PSEUDORANGE_IS_VALID (1)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_ACCELERATION_VALIDITY_STATUS_MASK (0x1)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_ACCELERATION_VALIDITY_STATUS_SHIFT (3u)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_ACCELERATION_VALIDITY_STATUS_GET(flags) \
                             (((flags) >> SBP_TRACKING_STATE_DETAILED_DEP_A_ACCELERATION_VALIDITY_STATUS_SHIFT) \
                             & SBP_TRACKING_STATE_DETAILED_DEP_A_ACCELERATION_VALIDITY_STATUS_MASK)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_ACCELERATION_VALIDITY_STATUS_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_TRACKING_STATE_DETAILED_DEP_A_ACCELERATION_VALIDITY_STATUS_MASK)) \
                             << (SBP_TRACKING_STATE_DETAILED_DEP_A_ACCELERATION_VALIDITY_STATUS_SHIFT)));} while(0)
                             

#define SBP_TRACKING_STATE_DETAILED_DEP_A_ACCELERATION_VALIDITY_STATUS_ACCELERATION_IS_NOT_VALID (0)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_ACCELERATION_VALIDITY_STATUS_ACCELERATION_IS_VALID (1)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_CARRIER_HALF_CYCLE_AMBIGUITY_STATUS_MASK (0x1)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_CARRIER_HALF_CYCLE_AMBIGUITY_STATUS_SHIFT (2u)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_CARRIER_HALF_CYCLE_AMBIGUITY_STATUS_GET(flags) \
                             (((flags) >> SBP_TRACKING_STATE_DETAILED_DEP_A_CARRIER_HALF_CYCLE_AMBIGUITY_STATUS_SHIFT) \
                             & SBP_TRACKING_STATE_DETAILED_DEP_A_CARRIER_HALF_CYCLE_AMBIGUITY_STATUS_MASK)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_CARRIER_HALF_CYCLE_AMBIGUITY_STATUS_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_TRACKING_STATE_DETAILED_DEP_A_CARRIER_HALF_CYCLE_AMBIGUITY_STATUS_MASK)) \
                             << (SBP_TRACKING_STATE_DETAILED_DEP_A_CARRIER_HALF_CYCLE_AMBIGUITY_STATUS_SHIFT)));} while(0)
                             

#define SBP_TRACKING_STATE_DETAILED_DEP_A_CARRIER_HALF_CYCLE_AMBIGUITY_STATUS_UNRESOLVED (0)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_CARRIER_HALF_CYCLE_AMBIGUITY_STATUS_RESOLVED (1)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_TRACKING_CHANNEL_STATUS_MASK (0x3)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_TRACKING_CHANNEL_STATUS_SHIFT (0u)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_TRACKING_CHANNEL_STATUS_GET(flags) \
                             (((flags) >> SBP_TRACKING_STATE_DETAILED_DEP_A_TRACKING_CHANNEL_STATUS_SHIFT) \
                             & SBP_TRACKING_STATE_DETAILED_DEP_A_TRACKING_CHANNEL_STATUS_MASK)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_TRACKING_CHANNEL_STATUS_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_TRACKING_STATE_DETAILED_DEP_A_TRACKING_CHANNEL_STATUS_MASK)) \
                             << (SBP_TRACKING_STATE_DETAILED_DEP_A_TRACKING_CHANNEL_STATUS_SHIFT)));} while(0)
                             

#define SBP_TRACKING_STATE_DETAILED_DEP_A_TRACKING_CHANNEL_STATUS_RE_ACQUISITION (0)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_TRACKING_CHANNEL_STATUS_RUNNING (1)

typedef struct SBP_ATTR_PACKED {
  u64 recv_time;       /**< Receiver clock time. [ns] */
  sbp_gps_time_t tot;             /**< Time of transmission of signal from satellite. TOW only valid when
TOW status is decoded or propagated. WN only valid when week
number valid flag is set.
 */
  u32 P;               /**< Pseudorange observation. Valid only when pseudorange valid flag is
set.
 [2 cm] */
  u16 P_std;           /**< Pseudorange observation standard deviation. Valid only when
pseudorange valid flag is set.
 [2 cm] */
  carrier_phase_t L;               /**< Carrier phase observation with typical sign convention. Valid only
when PLL pessimistic lock is achieved.
 [cycles] */
  u8 cn0;             /**< Carrier-to-Noise density [dB Hz / 4] */
  u16 lock;            /**< Lock time. It is encoded according to DF402 from the RTCM 10403.2
Amendment 2 specification. Valid values range from 0 to 15.
 */
  sbp_gnss_signal_t sid;             /**< GNSS signal identifier. */
  s32 doppler;         /**< Carrier Doppler frequency. [Hz / 16] */
  u16 doppler_std;     /**< Carrier Doppler frequency standard deviation. [Hz / 16] */
  u32 uptime;          /**< Number of seconds of continuous tracking. Specifies how much time
signal is in continuous track.
 [s] */
  s16 clock_offset;    /**< TCXO clock offset. Valid only when valid clock valid flag is set.
 [s / (2 ^ 20)] */
  s16 clock_drift;     /**< TCXO clock drift. Valid only when valid clock valid flag is set.
 [(s / s) / (2 ^ 31)] */
  u16 corr_spacing;    /**< Early-Prompt (EP) and Prompt-Late (PL) correlators spacing. [ns] */
  s8 acceleration;    /**< Acceleration. Valid only when acceleration valid flag is set. [g / 8] */
  u8 sync_flags;      /**< Synchronization status flags. */
  u8 tow_flags;       /**< TOW status flags. */
  u8 track_flags;     /**< Tracking loop status flags. */
  u8 nav_flags;       /**< Navigation data status flags. */
  u8 pset_flags;      /**< Parameters sets flags. */
  u8 misc_flags;      /**< Miscellaneous flags. */
} msg_tracking_state_detailed_dep_a_t;
 

/** Deprecated
 *
* Deprecated.
 */
#define SBP_MSG_TRACKING_STATE_DETAILED_DEP   0x0011
#define SBP_TRACKING_STATE_DETAILED_DEP_SYNCHRONIZATION_STATUS_MASK (0x7)
#define SBP_TRACKING_STATE_DETAILED_DEP_SYNCHRONIZATION_STATUS_SHIFT (0u)
#define SBP_TRACKING_STATE_DETAILED_DEP_SYNCHRONIZATION_STATUS_GET(flags) \
                             (((flags) >> SBP_TRACKING_STATE_DETAILED_DEP_SYNCHRONIZATION_STATUS_SHIFT) \
                             & SBP_TRACKING_STATE_DETAILED_DEP_SYNCHRONIZATION_STATUS_MASK)
#define SBP_TRACKING_STATE_DETAILED_DEP_SYNCHRONIZATION_STATUS_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_TRACKING_STATE_DETAILED_DEP_SYNCHRONIZATION_STATUS_MASK)) \
                             << (SBP_TRACKING_STATE_DETAILED_DEP_SYNCHRONIZATION_STATUS_SHIFT)));} while(0)
                             

#define SBP_TRACKING_STATE_DETAILED_DEP_SYNCHRONIZATION_STATUS_NO_SYNCHRONIZATION (0)
#define SBP_TRACKING_STATE_DETAILED_DEP_SYNCHRONIZATION_STATUS_BIT_SYNCHRONIZATION (1)
#define SBP_TRACKING_STATE_DETAILED_DEP_SYNCHRONIZATION_STATUS_WORD_SYNCHRONIZATION (2)
#define SBP_TRACKING_STATE_DETAILED_DEP_SYNCHRONIZATION_STATUS_SUB_FRAME_SYNCHRONIZATION_MESSAGE_SYNCHRONIZATION (3)
#define SBP_TRACKING_STATE_DETAILED_DEP_WEEK_NUMBER_VALIDITY_STATUS_MASK (0x1)
#define SBP_TRACKING_STATE_DETAILED_DEP_WEEK_NUMBER_VALIDITY_STATUS_SHIFT (3u)
#define SBP_TRACKING_STATE_DETAILED_DEP_WEEK_NUMBER_VALIDITY_STATUS_GET(flags) \
                             (((flags) >> SBP_TRACKING_STATE_DETAILED_DEP_WEEK_NUMBER_VALIDITY_STATUS_SHIFT) \
                             & SBP_TRACKING_STATE_DETAILED_DEP_WEEK_NUMBER_VALIDITY_STATUS_MASK)
#define SBP_TRACKING_STATE_DETAILED_DEP_WEEK_NUMBER_VALIDITY_STATUS_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_TRACKING_STATE_DETAILED_DEP_WEEK_NUMBER_VALIDITY_STATUS_MASK)) \
                             << (SBP_TRACKING_STATE_DETAILED_DEP_WEEK_NUMBER_VALIDITY_STATUS_SHIFT)));} while(0)
                             

#define SBP_TRACKING_STATE_DETAILED_DEP_WEEK_NUMBER_VALIDITY_STATUS_WEEK_NUMBER_IS_NOT_VALID (0)
#define SBP_TRACKING_STATE_DETAILED_DEP_WEEK_NUMBER_VALIDITY_STATUS_WEEK_NUMBER_IS_VALID (1)
#define SBP_TRACKING_STATE_DETAILED_DEP_TOW_STATUS_MASK (0x7)
#define SBP_TRACKING_STATE_DETAILED_DEP_TOW_STATUS_SHIFT (0u)
#define SBP_TRACKING_STATE_DETAILED_DEP_TOW_STATUS_GET(flags) \
                             (((flags) >> SBP_TRACKING_STATE_DETAILED_DEP_TOW_STATUS_SHIFT) \
                             & SBP_TRACKING_STATE_DETAILED_DEP_TOW_STATUS_MASK)
#define SBP_TRACKING_STATE_DETAILED_DEP_TOW_STATUS_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_TRACKING_STATE_DETAILED_DEP_TOW_STATUS_MASK)) \
                             << (SBP_TRACKING_STATE_DETAILED_DEP_TOW_STATUS_SHIFT)));} while(0)
                             

#define SBP_TRACKING_STATE_DETAILED_DEP_TOW_STATUS_TOW_IS_NOT_AVAILABLE (0)
#define SBP_TRACKING_STATE_DETAILED_DEP_TOW_STATUS_DECODED_TOW_IS_AVAILABLE (1)
#define SBP_TRACKING_STATE_DETAILED_DEP_TOW_STATUS_PROPAGATED_TOW_IS_AVAILABLE (2)
#define SBP_TRACKING_STATE_DETAILED_DEP_FLL_STATUS_MASK (0x1)
#define SBP_TRACKING_STATE_DETAILED_DEP_FLL_STATUS_SHIFT (4u)
#define SBP_TRACKING_STATE_DETAILED_DEP_FLL_STATUS_GET(flags) \
                             (((flags) >> SBP_TRACKING_STATE_DETAILED_DEP_FLL_STATUS_SHIFT) \
                             & SBP_TRACKING_STATE_DETAILED_DEP_FLL_STATUS_MASK)
#define SBP_TRACKING_STATE_DETAILED_DEP_FLL_STATUS_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_TRACKING_STATE_DETAILED_DEP_FLL_STATUS_MASK)) \
                             << (SBP_TRACKING_STATE_DETAILED_DEP_FLL_STATUS_SHIFT)));} while(0)
                             

#define SBP_TRACKING_STATE_DETAILED_DEP_FLL_STATUS_FLL_IS_INACTIVE (0)
#define SBP_TRACKING_STATE_DETAILED_DEP_FLL_STATUS_FLL_IS_ACTIVE (1)
#define SBP_TRACKING_STATE_DETAILED_DEP_PLL_STATUS_MASK (0x1)
#define SBP_TRACKING_STATE_DETAILED_DEP_PLL_STATUS_SHIFT (3u)
#define SBP_TRACKING_STATE_DETAILED_DEP_PLL_STATUS_GET(flags) \
                             (((flags) >> SBP_TRACKING_STATE_DETAILED_DEP_PLL_STATUS_SHIFT) \
                             & SBP_TRACKING_STATE_DETAILED_DEP_PLL_STATUS_MASK)
#define SBP_TRACKING_STATE_DETAILED_DEP_PLL_STATUS_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_TRACKING_STATE_DETAILED_DEP_PLL_STATUS_MASK)) \
                             << (SBP_TRACKING_STATE_DETAILED_DEP_PLL_STATUS_SHIFT)));} while(0)
                             

#define SBP_TRACKING_STATE_DETAILED_DEP_PLL_STATUS_PLL_IS_INACTIVE (0)
#define SBP_TRACKING_STATE_DETAILED_DEP_PLL_STATUS_PLL_IS_ACTIVE (1)
#define SBP_TRACKING_STATE_DETAILED_DEP_TRACKING_LOOP_STATUS_MASK (0x7)
#define SBP_TRACKING_STATE_DETAILED_DEP_TRACKING_LOOP_STATUS_SHIFT (0u)
#define SBP_TRACKING_STATE_DETAILED_DEP_TRACKING_LOOP_STATUS_GET(flags) \
                             (((flags) >> SBP_TRACKING_STATE_DETAILED_DEP_TRACKING_LOOP_STATUS_SHIFT) \
                             & SBP_TRACKING_STATE_DETAILED_DEP_TRACKING_LOOP_STATUS_MASK)
#define SBP_TRACKING_STATE_DETAILED_DEP_TRACKING_LOOP_STATUS_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_TRACKING_STATE_DETAILED_DEP_TRACKING_LOOP_STATUS_MASK)) \
                             << (SBP_TRACKING_STATE_DETAILED_DEP_TRACKING_LOOP_STATUS_SHIFT)));} while(0)
                             

#define SBP_TRACKING_STATE_DETAILED_DEP_TRACKING_LOOP_STATUS_NO_LOCKS (0)
#define SBP_TRACKING_STATE_DETAILED_DEP_TRACKING_LOOP_STATUS_FLLDLL_LOCK (1)
#define SBP_TRACKING_STATE_DETAILED_DEP_TRACKING_LOOP_STATUS_PLL_OPTIMISTIC_LOCK (2)
#define SBP_TRACKING_STATE_DETAILED_DEP_TRACKING_LOOP_STATUS_PLL_PESSIMISTIC_LOCK (3)
#define SBP_TRACKING_STATE_DETAILED_DEP_ALMANAC_AVAILABILITY_STATUS_MASK (0x1)
#define SBP_TRACKING_STATE_DETAILED_DEP_ALMANAC_AVAILABILITY_STATUS_SHIFT (4u)
#define SBP_TRACKING_STATE_DETAILED_DEP_ALMANAC_AVAILABILITY_STATUS_GET(flags) \
                             (((flags) >> SBP_TRACKING_STATE_DETAILED_DEP_ALMANAC_AVAILABILITY_STATUS_SHIFT) \
                             & SBP_TRACKING_STATE_DETAILED_DEP_ALMANAC_AVAILABILITY_STATUS_MASK)
#define SBP_TRACKING_STATE_DETAILED_DEP_ALMANAC_AVAILABILITY_STATUS_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_TRACKING_STATE_DETAILED_DEP_ALMANAC_AVAILABILITY_STATUS_MASK)) \
                             << (SBP_TRACKING_STATE_DETAILED_DEP_ALMANAC_AVAILABILITY_STATUS_SHIFT)));} while(0)
                             

#define SBP_TRACKING_STATE_DETAILED_DEP_ALMANAC_AVAILABILITY_STATUS_ALMANAC_IS_NOT_AVAILABLE (0)
#define SBP_TRACKING_STATE_DETAILED_DEP_ALMANAC_AVAILABILITY_STATUS_ALMANAC_IS_AVAILABLE (1)
#define SBP_TRACKING_STATE_DETAILED_DEP_EPHEMERIS_AVAILABILITY_STATUS_MASK (0x1)
#define SBP_TRACKING_STATE_DETAILED_DEP_EPHEMERIS_AVAILABILITY_STATUS_SHIFT (3u)
#define SBP_TRACKING_STATE_DETAILED_DEP_EPHEMERIS_AVAILABILITY_STATUS_GET(flags) \
                             (((flags) >> SBP_TRACKING_STATE_DETAILED_DEP_EPHEMERIS_AVAILABILITY_STATUS_SHIFT) \
                             & SBP_TRACKING_STATE_DETAILED_DEP_EPHEMERIS_AVAILABILITY_STATUS_MASK)
#define SBP_TRACKING_STATE_DETAILED_DEP_EPHEMERIS_AVAILABILITY_STATUS_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_TRACKING_STATE_DETAILED_DEP_EPHEMERIS_AVAILABILITY_STATUS_MASK)) \
                             << (SBP_TRACKING_STATE_DETAILED_DEP_EPHEMERIS_AVAILABILITY_STATUS_SHIFT)));} while(0)
                             

#define SBP_TRACKING_STATE_DETAILED_DEP_EPHEMERIS_AVAILABILITY_STATUS_EPHEMERIS_IS_NOT_AVAILABLE (0)
#define SBP_TRACKING_STATE_DETAILED_DEP_EPHEMERIS_AVAILABILITY_STATUS_EPHEMERIS_IS_AVAILABLE (1)
#define SBP_TRACKING_STATE_DETAILED_DEP_HEALTH_STATUS_MASK (0x7)
#define SBP_TRACKING_STATE_DETAILED_DEP_HEALTH_STATUS_SHIFT (0u)
#define SBP_TRACKING_STATE_DETAILED_DEP_HEALTH_STATUS_GET(flags) \
                             (((flags) >> SBP_TRACKING_STATE_DETAILED_DEP_HEALTH_STATUS_SHIFT) \
                             & SBP_TRACKING_STATE_DETAILED_DEP_HEALTH_STATUS_MASK)
#define SBP_TRACKING_STATE_DETAILED_DEP_HEALTH_STATUS_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_TRACKING_STATE_DETAILED_DEP_HEALTH_STATUS_MASK)) \
                             << (SBP_TRACKING_STATE_DETAILED_DEP_HEALTH_STATUS_SHIFT)));} while(0)
                             

#define SBP_TRACKING_STATE_DETAILED_DEP_HEALTH_STATUS_HEALTH_IS_UNKNOWN (0)
#define SBP_TRACKING_STATE_DETAILED_DEP_HEALTH_STATUS_SIGNAL_IS_UNHEALTHY (1)
#define SBP_TRACKING_STATE_DETAILED_DEP_HEALTH_STATUS_SIGNAL_IS_HEALTHY (2)
#define SBP_TRACKING_STATE_DETAILED_DEP_PARAMETER_SETS_MASK (0x7)
#define SBP_TRACKING_STATE_DETAILED_DEP_PARAMETER_SETS_SHIFT (0u)
#define SBP_TRACKING_STATE_DETAILED_DEP_PARAMETER_SETS_GET(flags) \
                             (((flags) >> SBP_TRACKING_STATE_DETAILED_DEP_PARAMETER_SETS_SHIFT) \
                             & SBP_TRACKING_STATE_DETAILED_DEP_PARAMETER_SETS_MASK)
#define SBP_TRACKING_STATE_DETAILED_DEP_PARAMETER_SETS_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_TRACKING_STATE_DETAILED_DEP_PARAMETER_SETS_MASK)) \
                             << (SBP_TRACKING_STATE_DETAILED_DEP_PARAMETER_SETS_SHIFT)));} while(0)
                             

#define SBP_TRACKING_STATE_DETAILED_DEP_PARAMETER_SETS_1_MS_INTEGRATION_TIME (0)
#define SBP_TRACKING_STATE_DETAILED_DEP_PARAMETER_SETS_5_MS_INTEGRATION_TIME (1)
#define SBP_TRACKING_STATE_DETAILED_DEP_PARAMETER_SETS_10_MS_INTEGRATION_TIME (2)
#define SBP_TRACKING_STATE_DETAILED_DEP_PARAMETER_SETS_20_MS_INTEGRATION_TIME (3)
#define SBP_TRACKING_STATE_DETAILED_DEP_CLOCK_VALIDITY_STATUS_MASK (0x1)
#define SBP_TRACKING_STATE_DETAILED_DEP_CLOCK_VALIDITY_STATUS_SHIFT (5u)
#define SBP_TRACKING_STATE_DETAILED_DEP_CLOCK_VALIDITY_STATUS_GET(flags) \
                             (((flags) >> SBP_TRACKING_STATE_DETAILED_DEP_CLOCK_VALIDITY_STATUS_SHIFT) \
                             & SBP_TRACKING_STATE_DETAILED_DEP_CLOCK_VALIDITY_STATUS_MASK)
#define SBP_TRACKING_STATE_DETAILED_DEP_CLOCK_VALIDITY_STATUS_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_TRACKING_STATE_DETAILED_DEP_CLOCK_VALIDITY_STATUS_MASK)) \
                             << (SBP_TRACKING_STATE_DETAILED_DEP_CLOCK_VALIDITY_STATUS_SHIFT)));} while(0)
                             

#define SBP_TRACKING_STATE_DETAILED_DEP_CLOCK_VALIDITY_STATUS_CLOCK_OFFSET_AND_DRIFT_IS_NOT_VALID (0)
#define SBP_TRACKING_STATE_DETAILED_DEP_CLOCK_VALIDITY_STATUS_CLOCK_OFFSET_AND_DRIFT_IS_VALID (1)
#define SBP_TRACKING_STATE_DETAILED_DEP_PSEUDORANGE_VALIDITY_STATUS_MASK (0x1)
#define SBP_TRACKING_STATE_DETAILED_DEP_PSEUDORANGE_VALIDITY_STATUS_SHIFT (4u)
#define SBP_TRACKING_STATE_DETAILED_DEP_PSEUDORANGE_VALIDITY_STATUS_GET(flags) \
                             (((flags) >> SBP_TRACKING_STATE_DETAILED_DEP_PSEUDORANGE_VALIDITY_STATUS_SHIFT) \
                             & SBP_TRACKING_STATE_DETAILED_DEP_PSEUDORANGE_VALIDITY_STATUS_MASK)
#define SBP_TRACKING_STATE_DETAILED_DEP_PSEUDORANGE_VALIDITY_STATUS_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_TRACKING_STATE_DETAILED_DEP_PSEUDORANGE_VALIDITY_STATUS_MASK)) \
                             << (SBP_TRACKING_STATE_DETAILED_DEP_PSEUDORANGE_VALIDITY_STATUS_SHIFT)));} while(0)
                             

#define SBP_TRACKING_STATE_DETAILED_DEP_PSEUDORANGE_VALIDITY_STATUS_PSEUDORANGE_IS_NOT_VALID (0)
#define SBP_TRACKING_STATE_DETAILED_DEP_PSEUDORANGE_VALIDITY_STATUS_PSEUDORANGE_IS_VALID (1)
#define SBP_TRACKING_STATE_DETAILED_DEP_ACCELERATION_VALIDITY_STATUS_MASK (0x1)
#define SBP_TRACKING_STATE_DETAILED_DEP_ACCELERATION_VALIDITY_STATUS_SHIFT (3u)
#define SBP_TRACKING_STATE_DETAILED_DEP_ACCELERATION_VALIDITY_STATUS_GET(flags) \
                             (((flags) >> SBP_TRACKING_STATE_DETAILED_DEP_ACCELERATION_VALIDITY_STATUS_SHIFT) \
                             & SBP_TRACKING_STATE_DETAILED_DEP_ACCELERATION_VALIDITY_STATUS_MASK)
#define SBP_TRACKING_STATE_DETAILED_DEP_ACCELERATION_VALIDITY_STATUS_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_TRACKING_STATE_DETAILED_DEP_ACCELERATION_VALIDITY_STATUS_MASK)) \
                             << (SBP_TRACKING_STATE_DETAILED_DEP_ACCELERATION_VALIDITY_STATUS_SHIFT)));} while(0)
                             

#define SBP_TRACKING_STATE_DETAILED_DEP_ACCELERATION_VALIDITY_STATUS_ACCELERATION_IS_NOT_VALID (0)
#define SBP_TRACKING_STATE_DETAILED_DEP_ACCELERATION_VALIDITY_STATUS_ACCELERATION_IS_VALID (1)
#define SBP_TRACKING_STATE_DETAILED_DEP_CARRIER_HALF_CYCLE_AMBIGUITY_STATUS_MASK (0x1)
#define SBP_TRACKING_STATE_DETAILED_DEP_CARRIER_HALF_CYCLE_AMBIGUITY_STATUS_SHIFT (2u)
#define SBP_TRACKING_STATE_DETAILED_DEP_CARRIER_HALF_CYCLE_AMBIGUITY_STATUS_GET(flags) \
                             (((flags) >> SBP_TRACKING_STATE_DETAILED_DEP_CARRIER_HALF_CYCLE_AMBIGUITY_STATUS_SHIFT) \
                             & SBP_TRACKING_STATE_DETAILED_DEP_CARRIER_HALF_CYCLE_AMBIGUITY_STATUS_MASK)
#define SBP_TRACKING_STATE_DETAILED_DEP_CARRIER_HALF_CYCLE_AMBIGUITY_STATUS_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_TRACKING_STATE_DETAILED_DEP_CARRIER_HALF_CYCLE_AMBIGUITY_STATUS_MASK)) \
                             << (SBP_TRACKING_STATE_DETAILED_DEP_CARRIER_HALF_CYCLE_AMBIGUITY_STATUS_SHIFT)));} while(0)
                             

#define SBP_TRACKING_STATE_DETAILED_DEP_CARRIER_HALF_CYCLE_AMBIGUITY_STATUS_UNRESOLVED (0)
#define SBP_TRACKING_STATE_DETAILED_DEP_CARRIER_HALF_CYCLE_AMBIGUITY_STATUS_RESOLVED (1)
#define SBP_TRACKING_STATE_DETAILED_DEP_TRACKING_CHANNEL_STATUS_MASK (0x3)
#define SBP_TRACKING_STATE_DETAILED_DEP_TRACKING_CHANNEL_STATUS_SHIFT (0u)
#define SBP_TRACKING_STATE_DETAILED_DEP_TRACKING_CHANNEL_STATUS_GET(flags) \
                             (((flags) >> SBP_TRACKING_STATE_DETAILED_DEP_TRACKING_CHANNEL_STATUS_SHIFT) \
                             & SBP_TRACKING_STATE_DETAILED_DEP_TRACKING_CHANNEL_STATUS_MASK)
#define SBP_TRACKING_STATE_DETAILED_DEP_TRACKING_CHANNEL_STATUS_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_TRACKING_STATE_DETAILED_DEP_TRACKING_CHANNEL_STATUS_MASK)) \
                             << (SBP_TRACKING_STATE_DETAILED_DEP_TRACKING_CHANNEL_STATUS_SHIFT)));} while(0)
                             

#define SBP_TRACKING_STATE_DETAILED_DEP_TRACKING_CHANNEL_STATUS_RE_ACQUISITION (0)
#define SBP_TRACKING_STATE_DETAILED_DEP_TRACKING_CHANNEL_STATUS_RUNNING (1)

typedef struct SBP_ATTR_PACKED {
  u64 recv_time;       /**< Receiver clock time. [ns] */
  gps_time_dep_t tot;             /**< Time of transmission of signal from satellite. TOW only valid when
TOW status is decoded or propagated. WN only valid when week
number valid flag is set.
 */
  u32 P;               /**< Pseudorange observation. Valid only when pseudorange valid flag is
set.
 [2 cm] */
  u16 P_std;           /**< Pseudorange observation standard deviation. Valid only when
pseudorange valid flag is set.
 [2 cm] */
  carrier_phase_t L;               /**< Carrier phase observation with typical sign convention. Valid only
when PLL pessimistic lock is achieved.
 [cycles] */
  u8 cn0;             /**< Carrier-to-Noise density [dB Hz / 4] */
  u16 lock;            /**< Lock time. It is encoded according to DF402 from the RTCM 10403.2
Amendment 2 specification. Valid values range from 0 to 15.
 */
  gnss_signal_dep_t sid;             /**< GNSS signal identifier. */
  s32 doppler;         /**< Carrier Doppler frequency. [Hz / 16] */
  u16 doppler_std;     /**< Carrier Doppler frequency standard deviation. [Hz / 16] */
  u32 uptime;          /**< Number of seconds of continuous tracking. Specifies how much time
signal is in continuous track.
 [s] */
  s16 clock_offset;    /**< TCXO clock offset. Valid only when valid clock valid flag is set.
 [s / (2 ^ 20)] */
  s16 clock_drift;     /**< TCXO clock drift. Valid only when valid clock valid flag is set.
 [(s / s) / (2 ^ 31)] */
  u16 corr_spacing;    /**< Early-Prompt (EP) and Prompt-Late (PL) correlators spacing. [ns] */
  s8 acceleration;    /**< Acceleration. Valid only when acceleration valid flag is set. [g / 8] */
  u8 sync_flags;      /**< Synchronization status flags. */
  u8 tow_flags;       /**< TOW status flags. */
  u8 track_flags;     /**< Tracking loop status flags. */
  u8 nav_flags;       /**< Navigation data status flags. */
  u8 pset_flags;      /**< Parameters sets flags. */
  u8 misc_flags;      /**< Miscellaneous flags. */
} msg_tracking_state_detailed_dep_t;
 

/** Signal tracking channel state
 *
 * Tracking channel state for a specific satellite signal and
 * measured signal power.
 */

typedef struct SBP_ATTR_PACKED {
  sbp_gnss_signal_t sid;    /**< GNSS signal being tracked */
  u8 fcn;    /**< Frequency channel number (GLONASS only) */
  u8 cn0;    /**< Carrier-to-Noise density.  Zero implies invalid cn0. [dB Hz / 4] */
} tracking_channel_state_t;
 

/** Signal tracking channel states
 *
 * The tracking message returns a variable-length array of tracking
 * channel states. It reports status and carrier-to-noise density
 * measurements for all tracked satellites.
 */
#define SBP_MSG_TRACKING_STATE                0x0041
#ifdef SBP_ENABLE_VARIABLE_SIZED_ARRAYS

typedef struct SBP_ATTR_PACKED {
  tracking_channel_state_t states[0]; /**< Signal tracking channel state */
} msg_tracking_state_t;
#endif
 

/** Measurement Engine signal tracking channel state
 *
 * Measurement Engine tracking channel state for a specific satellite signal
 * and measured signal power.
 * The mesid field for Glonass can either
 * carry the FCN as 100 + FCN where FCN is in [-7, +6] or
 * the Slot ID (from 1 to 28)
 */

typedef struct SBP_ATTR_PACKED {
  sbp_gnss_signal_t mesid;    /**< Measurement Engine GNSS signal being tracked (carries either Glonass FCN or SLOT) */
  u8 cn0;      /**< Carrier-to-Noise density.  Zero implies invalid cn0. [dB Hz / 4] */
} measurement_state_t;
 

/** Measurement Engine signal tracking channel states
 *
 * The tracking message returns a variable-length array of tracking
 * channel states. It reports status and carrier-to-noise density
 * measurements for all tracked satellites.
 */
#define SBP_MSG_MEASUREMENT_STATE             0x0061
#ifdef SBP_ENABLE_VARIABLE_SIZED_ARRAYS

typedef struct SBP_ATTR_PACKED {
  measurement_state_t states[0]; /**< ME signal tracking channel state */
} msg_measurement_state_t;
#endif
 

/** Complex correlation structure
 *
 * Structure containing in-phase and quadrature correlation components.
 */

typedef struct SBP_ATTR_PACKED {
  s16 I;    /**< In-phase correlation */
  s16 Q;    /**< Quadrature correlation */
} tracking_channel_correlation_t;
 

/** Tracking channel correlations
 *
 * When enabled, a tracking channel can output the correlations at each
 * update interval.
 */
#define SBP_MSG_TRACKING_IQ                   0x002D

typedef struct SBP_ATTR_PACKED {
  u8 channel;    /**< Tracking channel of origin */
  sbp_gnss_signal_t sid;        /**< GNSS signal identifier */
  tracking_channel_correlation_t corrs[3];   /**< Early, Prompt and Late correlations */
} msg_tracking_iq_t;
 

/** Complex correlation structure
 *
 * Structure containing in-phase and quadrature correlation components.
 */

typedef struct SBP_ATTR_PACKED {
  s32 I;    /**< In-phase correlation */
  s32 Q;    /**< Quadrature correlation */
} tracking_channel_correlation_dep_t;
 

/** Tracking channel correlations
 *
 * When enabled, a tracking channel can output the correlations at each
 * update interval.
 */
#define SBP_MSG_TRACKING_IQ_DEP_B             0x002C

typedef struct SBP_ATTR_PACKED {
  u8 channel;    /**< Tracking channel of origin */
  sbp_gnss_signal_t sid;        /**< GNSS signal identifier */
  tracking_channel_correlation_dep_t corrs[3];   /**< Early, Prompt and Late correlations */
} msg_tracking_iq_dep_b_t;
 

/** Deprecated
 *
* Deprecated.
 */
#define SBP_MSG_TRACKING_IQ_DEP_A             0x001C

typedef struct SBP_ATTR_PACKED {
  u8 channel;    /**< Tracking channel of origin */
  gnss_signal_dep_t sid;        /**< GNSS signal identifier */
  tracking_channel_correlation_dep_t corrs[3];   /**< Early, Prompt and Late correlations */
} msg_tracking_iq_dep_a_t;
 

/** Deprecated
 *
* Deprecated.
 */

typedef struct SBP_ATTR_PACKED {
  u8 state;    /**< Status of tracking channel */
  u8 prn;      /**< PRN-1 being tracked */
  float cn0;      /**< Carrier-to-noise density [dB Hz] */
} tracking_channel_state_dep_a_t;
 

/** Deprecated
 *
* Deprecated.
 */
#define SBP_MSG_TRACKING_STATE_DEP_A          0x0016
#ifdef SBP_ENABLE_VARIABLE_SIZED_ARRAYS

typedef struct SBP_ATTR_PACKED {
  tracking_channel_state_dep_a_t states[0]; /**< Satellite tracking channel state */
} msg_tracking_state_dep_a_t;
#endif
 

/** Deprecated.
 *
* Deprecated.
 */

typedef struct SBP_ATTR_PACKED {
  u8 state;    /**< Status of tracking channel */
  gnss_signal_dep_t sid;      /**< GNSS signal being tracked */
  float cn0;      /**< Carrier-to-noise density [dB Hz] */
} tracking_channel_state_dep_b_t;
 

/** Deprecated.
 *
* Deprecated.
 */
#define SBP_MSG_TRACKING_STATE_DEP_B          0x0013
#ifdef SBP_ENABLE_VARIABLE_SIZED_ARRAYS

typedef struct SBP_ATTR_PACKED {
  tracking_channel_state_dep_b_t states[0]; /**< Signal tracking channel state */
} msg_tracking_state_dep_b_t;
#endif
 

/** \} */
static inline void static_asserts_for_module_MSG_TRACKING_STATE_DETAILED_DEP_A(void) {
#ifdef __cplusplus
static_assert(offsetof(msg_tracking_state_detailed_dep_a_t, recv_time ) == 0, "Offset of recv_time in msg_tracking_state_detailed_dep_a_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_tracking_state_detailed_dep_a_t, recv_time ) == 0, offset_of_recv_time_in_msg_tracking_state_detailed_dep_a_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_tracking_state_detailed_dep_a_t, tot ) == 0 + sizeof(u64), "Offset of tot in msg_tracking_state_detailed_dep_a_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_tracking_state_detailed_dep_a_t, tot ) == 0 + sizeof(u64), offset_of_tot_in_msg_tracking_state_detailed_dep_a_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_tracking_state_detailed_dep_a_t, P ) == 0 + sizeof(u64) + sizeof(sbp_gps_time_t), "Offset of P in msg_tracking_state_detailed_dep_a_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_tracking_state_detailed_dep_a_t, P ) == 0 + sizeof(u64) + sizeof(sbp_gps_time_t), offset_of_P_in_msg_tracking_state_detailed_dep_a_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_tracking_state_detailed_dep_a_t, P_std ) == 0 + sizeof(u64) + sizeof(sbp_gps_time_t) + sizeof(u32), "Offset of P_std in msg_tracking_state_detailed_dep_a_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_tracking_state_detailed_dep_a_t, P_std ) == 0 + sizeof(u64) + sizeof(sbp_gps_time_t) + sizeof(u32), offset_of_P_std_in_msg_tracking_state_detailed_dep_a_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_tracking_state_detailed_dep_a_t, L ) == 0 + sizeof(u64) + sizeof(sbp_gps_time_t) + sizeof(u32) + sizeof(u16), "Offset of L in msg_tracking_state_detailed_dep_a_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_tracking_state_detailed_dep_a_t, L ) == 0 + sizeof(u64) + sizeof(sbp_gps_time_t) + sizeof(u32) + sizeof(u16), offset_of_L_in_msg_tracking_state_detailed_dep_a_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_tracking_state_detailed_dep_a_t, cn0 ) == 0 + sizeof(u64) + sizeof(sbp_gps_time_t) + sizeof(u32) + sizeof(u16) + sizeof(carrier_phase_t), "Offset of cn0 in msg_tracking_state_detailed_dep_a_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_tracking_state_detailed_dep_a_t, cn0 ) == 0 + sizeof(u64) + sizeof(sbp_gps_time_t) + sizeof(u32) + sizeof(u16) + sizeof(carrier_phase_t), offset_of_cn0_in_msg_tracking_state_detailed_dep_a_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_tracking_state_detailed_dep_a_t, lock ) == 0 + sizeof(u64) + sizeof(sbp_gps_time_t) + sizeof(u32) + sizeof(u16) + sizeof(carrier_phase_t) + sizeof(u8), "Offset of lock in msg_tracking_state_detailed_dep_a_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_tracking_state_detailed_dep_a_t, lock ) == 0 + sizeof(u64) + sizeof(sbp_gps_time_t) + sizeof(u32) + sizeof(u16) + sizeof(carrier_phase_t) + sizeof(u8), offset_of_lock_in_msg_tracking_state_detailed_dep_a_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_tracking_state_detailed_dep_a_t, sid ) == 0 + sizeof(u64) + sizeof(sbp_gps_time_t) + sizeof(u32) + sizeof(u16) + sizeof(carrier_phase_t) + sizeof(u8) + sizeof(u16), "Offset of sid in msg_tracking_state_detailed_dep_a_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_tracking_state_detailed_dep_a_t, sid ) == 0 + sizeof(u64) + sizeof(sbp_gps_time_t) + sizeof(u32) + sizeof(u16) + sizeof(carrier_phase_t) + sizeof(u8) + sizeof(u16), offset_of_sid_in_msg_tracking_state_detailed_dep_a_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_tracking_state_detailed_dep_a_t, doppler ) == 0 + sizeof(u64) + sizeof(sbp_gps_time_t) + sizeof(u32) + sizeof(u16) + sizeof(carrier_phase_t) + sizeof(u8) + sizeof(u16) + sizeof(sbp_gnss_signal_t), "Offset of doppler in msg_tracking_state_detailed_dep_a_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_tracking_state_detailed_dep_a_t, doppler ) == 0 + sizeof(u64) + sizeof(sbp_gps_time_t) + sizeof(u32) + sizeof(u16) + sizeof(carrier_phase_t) + sizeof(u8) + sizeof(u16) + sizeof(sbp_gnss_signal_t), offset_of_doppler_in_msg_tracking_state_detailed_dep_a_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_tracking_state_detailed_dep_a_t, doppler_std ) == 0 + sizeof(u64) + sizeof(sbp_gps_time_t) + sizeof(u32) + sizeof(u16) + sizeof(carrier_phase_t) + sizeof(u8) + sizeof(u16) + sizeof(sbp_gnss_signal_t) + sizeof(s32), "Offset of doppler_std in msg_tracking_state_detailed_dep_a_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_tracking_state_detailed_dep_a_t, doppler_std ) == 0 + sizeof(u64) + sizeof(sbp_gps_time_t) + sizeof(u32) + sizeof(u16) + sizeof(carrier_phase_t) + sizeof(u8) + sizeof(u16) + sizeof(sbp_gnss_signal_t) + sizeof(s32), offset_of_doppler_std_in_msg_tracking_state_detailed_dep_a_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_tracking_state_detailed_dep_a_t, uptime ) == 0 + sizeof(u64) + sizeof(sbp_gps_time_t) + sizeof(u32) + sizeof(u16) + sizeof(carrier_phase_t) + sizeof(u8) + sizeof(u16) + sizeof(sbp_gnss_signal_t) + sizeof(s32) + sizeof(u16), "Offset of uptime in msg_tracking_state_detailed_dep_a_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_tracking_state_detailed_dep_a_t, uptime ) == 0 + sizeof(u64) + sizeof(sbp_gps_time_t) + sizeof(u32) + sizeof(u16) + sizeof(carrier_phase_t) + sizeof(u8) + sizeof(u16) + sizeof(sbp_gnss_signal_t) + sizeof(s32) + sizeof(u16), offset_of_uptime_in_msg_tracking_state_detailed_dep_a_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_tracking_state_detailed_dep_a_t, clock_offset ) == 0 + sizeof(u64) + sizeof(sbp_gps_time_t) + sizeof(u32) + sizeof(u16) + sizeof(carrier_phase_t) + sizeof(u8) + sizeof(u16) + sizeof(sbp_gnss_signal_t) + sizeof(s32) + sizeof(u16) + sizeof(u32), "Offset of clock_offset in msg_tracking_state_detailed_dep_a_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_tracking_state_detailed_dep_a_t, clock_offset ) == 0 + sizeof(u64) + sizeof(sbp_gps_time_t) + sizeof(u32) + sizeof(u16) + sizeof(carrier_phase_t) + sizeof(u8) + sizeof(u16) + sizeof(sbp_gnss_signal_t) + sizeof(s32) + sizeof(u16) + sizeof(u32), offset_of_clock_offset_in_msg_tracking_state_detailed_dep_a_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_tracking_state_detailed_dep_a_t, clock_drift ) == 0 + sizeof(u64) + sizeof(sbp_gps_time_t) + sizeof(u32) + sizeof(u16) + sizeof(carrier_phase_t) + sizeof(u8) + sizeof(u16) + sizeof(sbp_gnss_signal_t) + sizeof(s32) + sizeof(u16) + sizeof(u32) + sizeof(s16), "Offset of clock_drift in msg_tracking_state_detailed_dep_a_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_tracking_state_detailed_dep_a_t, clock_drift ) == 0 + sizeof(u64) + sizeof(sbp_gps_time_t) + sizeof(u32) + sizeof(u16) + sizeof(carrier_phase_t) + sizeof(u8) + sizeof(u16) + sizeof(sbp_gnss_signal_t) + sizeof(s32) + sizeof(u16) + sizeof(u32) + sizeof(s16), offset_of_clock_drift_in_msg_tracking_state_detailed_dep_a_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_tracking_state_detailed_dep_a_t, corr_spacing ) == 0 + sizeof(u64) + sizeof(sbp_gps_time_t) + sizeof(u32) + sizeof(u16) + sizeof(carrier_phase_t) + sizeof(u8) + sizeof(u16) + sizeof(sbp_gnss_signal_t) + sizeof(s32) + sizeof(u16) + sizeof(u32) + sizeof(s16) + sizeof(s16), "Offset of corr_spacing in msg_tracking_state_detailed_dep_a_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_tracking_state_detailed_dep_a_t, corr_spacing ) == 0 + sizeof(u64) + sizeof(sbp_gps_time_t) + sizeof(u32) + sizeof(u16) + sizeof(carrier_phase_t) + sizeof(u8) + sizeof(u16) + sizeof(sbp_gnss_signal_t) + sizeof(s32) + sizeof(u16) + sizeof(u32) + sizeof(s16) + sizeof(s16), offset_of_corr_spacing_in_msg_tracking_state_detailed_dep_a_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_tracking_state_detailed_dep_a_t, acceleration ) == 0 + sizeof(u64) + sizeof(sbp_gps_time_t) + sizeof(u32) + sizeof(u16) + sizeof(carrier_phase_t) + sizeof(u8) + sizeof(u16) + sizeof(sbp_gnss_signal_t) + sizeof(s32) + sizeof(u16) + sizeof(u32) + sizeof(s16) + sizeof(s16) + sizeof(u16), "Offset of acceleration in msg_tracking_state_detailed_dep_a_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_tracking_state_detailed_dep_a_t, acceleration ) == 0 + sizeof(u64) + sizeof(sbp_gps_time_t) + sizeof(u32) + sizeof(u16) + sizeof(carrier_phase_t) + sizeof(u8) + sizeof(u16) + sizeof(sbp_gnss_signal_t) + sizeof(s32) + sizeof(u16) + sizeof(u32) + sizeof(s16) + sizeof(s16) + sizeof(u16), offset_of_acceleration_in_msg_tracking_state_detailed_dep_a_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_tracking_state_detailed_dep_a_t, sync_flags ) == 0 + sizeof(u64) + sizeof(sbp_gps_time_t) + sizeof(u32) + sizeof(u16) + sizeof(carrier_phase_t) + sizeof(u8) + sizeof(u16) + sizeof(sbp_gnss_signal_t) + sizeof(s32) + sizeof(u16) + sizeof(u32) + sizeof(s16) + sizeof(s16) + sizeof(u16) + sizeof(s8), "Offset of sync_flags in msg_tracking_state_detailed_dep_a_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_tracking_state_detailed_dep_a_t, sync_flags ) == 0 + sizeof(u64) + sizeof(sbp_gps_time_t) + sizeof(u32) + sizeof(u16) + sizeof(carrier_phase_t) + sizeof(u8) + sizeof(u16) + sizeof(sbp_gnss_signal_t) + sizeof(s32) + sizeof(u16) + sizeof(u32) + sizeof(s16) + sizeof(s16) + sizeof(u16) + sizeof(s8), offset_of_sync_flags_in_msg_tracking_state_detailed_dep_a_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_tracking_state_detailed_dep_a_t, tow_flags ) == 0 + sizeof(u64) + sizeof(sbp_gps_time_t) + sizeof(u32) + sizeof(u16) + sizeof(carrier_phase_t) + sizeof(u8) + sizeof(u16) + sizeof(sbp_gnss_signal_t) + sizeof(s32) + sizeof(u16) + sizeof(u32) + sizeof(s16) + sizeof(s16) + sizeof(u16) + sizeof(s8) + sizeof(u8), "Offset of tow_flags in msg_tracking_state_detailed_dep_a_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_tracking_state_detailed_dep_a_t, tow_flags ) == 0 + sizeof(u64) + sizeof(sbp_gps_time_t) + sizeof(u32) + sizeof(u16) + sizeof(carrier_phase_t) + sizeof(u8) + sizeof(u16) + sizeof(sbp_gnss_signal_t) + sizeof(s32) + sizeof(u16) + sizeof(u32) + sizeof(s16) + sizeof(s16) + sizeof(u16) + sizeof(s8) + sizeof(u8), offset_of_tow_flags_in_msg_tracking_state_detailed_dep_a_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_tracking_state_detailed_dep_a_t, track_flags ) == 0 + sizeof(u64) + sizeof(sbp_gps_time_t) + sizeof(u32) + sizeof(u16) + sizeof(carrier_phase_t) + sizeof(u8) + sizeof(u16) + sizeof(sbp_gnss_signal_t) + sizeof(s32) + sizeof(u16) + sizeof(u32) + sizeof(s16) + sizeof(s16) + sizeof(u16) + sizeof(s8) + sizeof(u8) + sizeof(u8), "Offset of track_flags in msg_tracking_state_detailed_dep_a_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_tracking_state_detailed_dep_a_t, track_flags ) == 0 + sizeof(u64) + sizeof(sbp_gps_time_t) + sizeof(u32) + sizeof(u16) + sizeof(carrier_phase_t) + sizeof(u8) + sizeof(u16) + sizeof(sbp_gnss_signal_t) + sizeof(s32) + sizeof(u16) + sizeof(u32) + sizeof(s16) + sizeof(s16) + sizeof(u16) + sizeof(s8) + sizeof(u8) + sizeof(u8), offset_of_track_flags_in_msg_tracking_state_detailed_dep_a_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_tracking_state_detailed_dep_a_t, nav_flags ) == 0 + sizeof(u64) + sizeof(sbp_gps_time_t) + sizeof(u32) + sizeof(u16) + sizeof(carrier_phase_t) + sizeof(u8) + sizeof(u16) + sizeof(sbp_gnss_signal_t) + sizeof(s32) + sizeof(u16) + sizeof(u32) + sizeof(s16) + sizeof(s16) + sizeof(u16) + sizeof(s8) + sizeof(u8) + sizeof(u8) + sizeof(u8), "Offset of nav_flags in msg_tracking_state_detailed_dep_a_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_tracking_state_detailed_dep_a_t, nav_flags ) == 0 + sizeof(u64) + sizeof(sbp_gps_time_t) + sizeof(u32) + sizeof(u16) + sizeof(carrier_phase_t) + sizeof(u8) + sizeof(u16) + sizeof(sbp_gnss_signal_t) + sizeof(s32) + sizeof(u16) + sizeof(u32) + sizeof(s16) + sizeof(s16) + sizeof(u16) + sizeof(s8) + sizeof(u8) + sizeof(u8) + sizeof(u8), offset_of_nav_flags_in_msg_tracking_state_detailed_dep_a_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_tracking_state_detailed_dep_a_t, pset_flags ) == 0 + sizeof(u64) + sizeof(sbp_gps_time_t) + sizeof(u32) + sizeof(u16) + sizeof(carrier_phase_t) + sizeof(u8) + sizeof(u16) + sizeof(sbp_gnss_signal_t) + sizeof(s32) + sizeof(u16) + sizeof(u32) + sizeof(s16) + sizeof(s16) + sizeof(u16) + sizeof(s8) + sizeof(u8) + sizeof(u8) + sizeof(u8) + sizeof(u8), "Offset of pset_flags in msg_tracking_state_detailed_dep_a_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_tracking_state_detailed_dep_a_t, pset_flags ) == 0 + sizeof(u64) + sizeof(sbp_gps_time_t) + sizeof(u32) + sizeof(u16) + sizeof(carrier_phase_t) + sizeof(u8) + sizeof(u16) + sizeof(sbp_gnss_signal_t) + sizeof(s32) + sizeof(u16) + sizeof(u32) + sizeof(s16) + sizeof(s16) + sizeof(u16) + sizeof(s8) + sizeof(u8) + sizeof(u8) + sizeof(u8) + sizeof(u8), offset_of_pset_flags_in_msg_tracking_state_detailed_dep_a_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_tracking_state_detailed_dep_a_t, misc_flags ) == 0 + sizeof(u64) + sizeof(sbp_gps_time_t) + sizeof(u32) + sizeof(u16) + sizeof(carrier_phase_t) + sizeof(u8) + sizeof(u16) + sizeof(sbp_gnss_signal_t) + sizeof(s32) + sizeof(u16) + sizeof(u32) + sizeof(s16) + sizeof(s16) + sizeof(u16) + sizeof(s8) + sizeof(u8) + sizeof(u8) + sizeof(u8) + sizeof(u8) + sizeof(u8), "Offset of misc_flags in msg_tracking_state_detailed_dep_a_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_tracking_state_detailed_dep_a_t, misc_flags ) == 0 + sizeof(u64) + sizeof(sbp_gps_time_t) + sizeof(u32) + sizeof(u16) + sizeof(carrier_phase_t) + sizeof(u8) + sizeof(u16) + sizeof(sbp_gnss_signal_t) + sizeof(s32) + sizeof(u16) + sizeof(u32) + sizeof(s16) + sizeof(s16) + sizeof(u16) + sizeof(s8) + sizeof(u8) + sizeof(u8) + sizeof(u8) + sizeof(u8) + sizeof(u8), offset_of_misc_flags_in_msg_tracking_state_detailed_dep_a_t_is_incorrect)
#endif
}

static inline void static_asserts_for_module_MSG_TRACKING_STATE_DETAILED_DEP(void) {
#ifdef __cplusplus
static_assert(offsetof(msg_tracking_state_detailed_dep_t, recv_time ) == 0, "Offset of recv_time in msg_tracking_state_detailed_dep_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_tracking_state_detailed_dep_t, recv_time ) == 0, offset_of_recv_time_in_msg_tracking_state_detailed_dep_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_tracking_state_detailed_dep_t, tot ) == 0 + sizeof(u64), "Offset of tot in msg_tracking_state_detailed_dep_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_tracking_state_detailed_dep_t, tot ) == 0 + sizeof(u64), offset_of_tot_in_msg_tracking_state_detailed_dep_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_tracking_state_detailed_dep_t, P ) == 0 + sizeof(u64) + sizeof(gps_time_dep_t), "Offset of P in msg_tracking_state_detailed_dep_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_tracking_state_detailed_dep_t, P ) == 0 + sizeof(u64) + sizeof(gps_time_dep_t), offset_of_P_in_msg_tracking_state_detailed_dep_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_tracking_state_detailed_dep_t, P_std ) == 0 + sizeof(u64) + sizeof(gps_time_dep_t) + sizeof(u32), "Offset of P_std in msg_tracking_state_detailed_dep_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_tracking_state_detailed_dep_t, P_std ) == 0 + sizeof(u64) + sizeof(gps_time_dep_t) + sizeof(u32), offset_of_P_std_in_msg_tracking_state_detailed_dep_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_tracking_state_detailed_dep_t, L ) == 0 + sizeof(u64) + sizeof(gps_time_dep_t) + sizeof(u32) + sizeof(u16), "Offset of L in msg_tracking_state_detailed_dep_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_tracking_state_detailed_dep_t, L ) == 0 + sizeof(u64) + sizeof(gps_time_dep_t) + sizeof(u32) + sizeof(u16), offset_of_L_in_msg_tracking_state_detailed_dep_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_tracking_state_detailed_dep_t, cn0 ) == 0 + sizeof(u64) + sizeof(gps_time_dep_t) + sizeof(u32) + sizeof(u16) + sizeof(carrier_phase_t), "Offset of cn0 in msg_tracking_state_detailed_dep_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_tracking_state_detailed_dep_t, cn0 ) == 0 + sizeof(u64) + sizeof(gps_time_dep_t) + sizeof(u32) + sizeof(u16) + sizeof(carrier_phase_t), offset_of_cn0_in_msg_tracking_state_detailed_dep_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_tracking_state_detailed_dep_t, lock ) == 0 + sizeof(u64) + sizeof(gps_time_dep_t) + sizeof(u32) + sizeof(u16) + sizeof(carrier_phase_t) + sizeof(u8), "Offset of lock in msg_tracking_state_detailed_dep_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_tracking_state_detailed_dep_t, lock ) == 0 + sizeof(u64) + sizeof(gps_time_dep_t) + sizeof(u32) + sizeof(u16) + sizeof(carrier_phase_t) + sizeof(u8), offset_of_lock_in_msg_tracking_state_detailed_dep_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_tracking_state_detailed_dep_t, sid ) == 0 + sizeof(u64) + sizeof(gps_time_dep_t) + sizeof(u32) + sizeof(u16) + sizeof(carrier_phase_t) + sizeof(u8) + sizeof(u16), "Offset of sid in msg_tracking_state_detailed_dep_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_tracking_state_detailed_dep_t, sid ) == 0 + sizeof(u64) + sizeof(gps_time_dep_t) + sizeof(u32) + sizeof(u16) + sizeof(carrier_phase_t) + sizeof(u8) + sizeof(u16), offset_of_sid_in_msg_tracking_state_detailed_dep_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_tracking_state_detailed_dep_t, doppler ) == 0 + sizeof(u64) + sizeof(gps_time_dep_t) + sizeof(u32) + sizeof(u16) + sizeof(carrier_phase_t) + sizeof(u8) + sizeof(u16) + sizeof(gnss_signal_dep_t), "Offset of doppler in msg_tracking_state_detailed_dep_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_tracking_state_detailed_dep_t, doppler ) == 0 + sizeof(u64) + sizeof(gps_time_dep_t) + sizeof(u32) + sizeof(u16) + sizeof(carrier_phase_t) + sizeof(u8) + sizeof(u16) + sizeof(gnss_signal_dep_t), offset_of_doppler_in_msg_tracking_state_detailed_dep_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_tracking_state_detailed_dep_t, doppler_std ) == 0 + sizeof(u64) + sizeof(gps_time_dep_t) + sizeof(u32) + sizeof(u16) + sizeof(carrier_phase_t) + sizeof(u8) + sizeof(u16) + sizeof(gnss_signal_dep_t) + sizeof(s32), "Offset of doppler_std in msg_tracking_state_detailed_dep_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_tracking_state_detailed_dep_t, doppler_std ) == 0 + sizeof(u64) + sizeof(gps_time_dep_t) + sizeof(u32) + sizeof(u16) + sizeof(carrier_phase_t) + sizeof(u8) + sizeof(u16) + sizeof(gnss_signal_dep_t) + sizeof(s32), offset_of_doppler_std_in_msg_tracking_state_detailed_dep_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_tracking_state_detailed_dep_t, uptime ) == 0 + sizeof(u64) + sizeof(gps_time_dep_t) + sizeof(u32) + sizeof(u16) + sizeof(carrier_phase_t) + sizeof(u8) + sizeof(u16) + sizeof(gnss_signal_dep_t) + sizeof(s32) + sizeof(u16), "Offset of uptime in msg_tracking_state_detailed_dep_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_tracking_state_detailed_dep_t, uptime ) == 0 + sizeof(u64) + sizeof(gps_time_dep_t) + sizeof(u32) + sizeof(u16) + sizeof(carrier_phase_t) + sizeof(u8) + sizeof(u16) + sizeof(gnss_signal_dep_t) + sizeof(s32) + sizeof(u16), offset_of_uptime_in_msg_tracking_state_detailed_dep_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_tracking_state_detailed_dep_t, clock_offset ) == 0 + sizeof(u64) + sizeof(gps_time_dep_t) + sizeof(u32) + sizeof(u16) + sizeof(carrier_phase_t) + sizeof(u8) + sizeof(u16) + sizeof(gnss_signal_dep_t) + sizeof(s32) + sizeof(u16) + sizeof(u32), "Offset of clock_offset in msg_tracking_state_detailed_dep_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_tracking_state_detailed_dep_t, clock_offset ) == 0 + sizeof(u64) + sizeof(gps_time_dep_t) + sizeof(u32) + sizeof(u16) + sizeof(carrier_phase_t) + sizeof(u8) + sizeof(u16) + sizeof(gnss_signal_dep_t) + sizeof(s32) + sizeof(u16) + sizeof(u32), offset_of_clock_offset_in_msg_tracking_state_detailed_dep_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_tracking_state_detailed_dep_t, clock_drift ) == 0 + sizeof(u64) + sizeof(gps_time_dep_t) + sizeof(u32) + sizeof(u16) + sizeof(carrier_phase_t) + sizeof(u8) + sizeof(u16) + sizeof(gnss_signal_dep_t) + sizeof(s32) + sizeof(u16) + sizeof(u32) + sizeof(s16), "Offset of clock_drift in msg_tracking_state_detailed_dep_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_tracking_state_detailed_dep_t, clock_drift ) == 0 + sizeof(u64) + sizeof(gps_time_dep_t) + sizeof(u32) + sizeof(u16) + sizeof(carrier_phase_t) + sizeof(u8) + sizeof(u16) + sizeof(gnss_signal_dep_t) + sizeof(s32) + sizeof(u16) + sizeof(u32) + sizeof(s16), offset_of_clock_drift_in_msg_tracking_state_detailed_dep_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_tracking_state_detailed_dep_t, corr_spacing ) == 0 + sizeof(u64) + sizeof(gps_time_dep_t) + sizeof(u32) + sizeof(u16) + sizeof(carrier_phase_t) + sizeof(u8) + sizeof(u16) + sizeof(gnss_signal_dep_t) + sizeof(s32) + sizeof(u16) + sizeof(u32) + sizeof(s16) + sizeof(s16), "Offset of corr_spacing in msg_tracking_state_detailed_dep_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_tracking_state_detailed_dep_t, corr_spacing ) == 0 + sizeof(u64) + sizeof(gps_time_dep_t) + sizeof(u32) + sizeof(u16) + sizeof(carrier_phase_t) + sizeof(u8) + sizeof(u16) + sizeof(gnss_signal_dep_t) + sizeof(s32) + sizeof(u16) + sizeof(u32) + sizeof(s16) + sizeof(s16), offset_of_corr_spacing_in_msg_tracking_state_detailed_dep_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_tracking_state_detailed_dep_t, acceleration ) == 0 + sizeof(u64) + sizeof(gps_time_dep_t) + sizeof(u32) + sizeof(u16) + sizeof(carrier_phase_t) + sizeof(u8) + sizeof(u16) + sizeof(gnss_signal_dep_t) + sizeof(s32) + sizeof(u16) + sizeof(u32) + sizeof(s16) + sizeof(s16) + sizeof(u16), "Offset of acceleration in msg_tracking_state_detailed_dep_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_tracking_state_detailed_dep_t, acceleration ) == 0 + sizeof(u64) + sizeof(gps_time_dep_t) + sizeof(u32) + sizeof(u16) + sizeof(carrier_phase_t) + sizeof(u8) + sizeof(u16) + sizeof(gnss_signal_dep_t) + sizeof(s32) + sizeof(u16) + sizeof(u32) + sizeof(s16) + sizeof(s16) + sizeof(u16), offset_of_acceleration_in_msg_tracking_state_detailed_dep_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_tracking_state_detailed_dep_t, sync_flags ) == 0 + sizeof(u64) + sizeof(gps_time_dep_t) + sizeof(u32) + sizeof(u16) + sizeof(carrier_phase_t) + sizeof(u8) + sizeof(u16) + sizeof(gnss_signal_dep_t) + sizeof(s32) + sizeof(u16) + sizeof(u32) + sizeof(s16) + sizeof(s16) + sizeof(u16) + sizeof(s8), "Offset of sync_flags in msg_tracking_state_detailed_dep_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_tracking_state_detailed_dep_t, sync_flags ) == 0 + sizeof(u64) + sizeof(gps_time_dep_t) + sizeof(u32) + sizeof(u16) + sizeof(carrier_phase_t) + sizeof(u8) + sizeof(u16) + sizeof(gnss_signal_dep_t) + sizeof(s32) + sizeof(u16) + sizeof(u32) + sizeof(s16) + sizeof(s16) + sizeof(u16) + sizeof(s8), offset_of_sync_flags_in_msg_tracking_state_detailed_dep_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_tracking_state_detailed_dep_t, tow_flags ) == 0 + sizeof(u64) + sizeof(gps_time_dep_t) + sizeof(u32) + sizeof(u16) + sizeof(carrier_phase_t) + sizeof(u8) + sizeof(u16) + sizeof(gnss_signal_dep_t) + sizeof(s32) + sizeof(u16) + sizeof(u32) + sizeof(s16) + sizeof(s16) + sizeof(u16) + sizeof(s8) + sizeof(u8), "Offset of tow_flags in msg_tracking_state_detailed_dep_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_tracking_state_detailed_dep_t, tow_flags ) == 0 + sizeof(u64) + sizeof(gps_time_dep_t) + sizeof(u32) + sizeof(u16) + sizeof(carrier_phase_t) + sizeof(u8) + sizeof(u16) + sizeof(gnss_signal_dep_t) + sizeof(s32) + sizeof(u16) + sizeof(u32) + sizeof(s16) + sizeof(s16) + sizeof(u16) + sizeof(s8) + sizeof(u8), offset_of_tow_flags_in_msg_tracking_state_detailed_dep_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_tracking_state_detailed_dep_t, track_flags ) == 0 + sizeof(u64) + sizeof(gps_time_dep_t) + sizeof(u32) + sizeof(u16) + sizeof(carrier_phase_t) + sizeof(u8) + sizeof(u16) + sizeof(gnss_signal_dep_t) + sizeof(s32) + sizeof(u16) + sizeof(u32) + sizeof(s16) + sizeof(s16) + sizeof(u16) + sizeof(s8) + sizeof(u8) + sizeof(u8), "Offset of track_flags in msg_tracking_state_detailed_dep_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_tracking_state_detailed_dep_t, track_flags ) == 0 + sizeof(u64) + sizeof(gps_time_dep_t) + sizeof(u32) + sizeof(u16) + sizeof(carrier_phase_t) + sizeof(u8) + sizeof(u16) + sizeof(gnss_signal_dep_t) + sizeof(s32) + sizeof(u16) + sizeof(u32) + sizeof(s16) + sizeof(s16) + sizeof(u16) + sizeof(s8) + sizeof(u8) + sizeof(u8), offset_of_track_flags_in_msg_tracking_state_detailed_dep_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_tracking_state_detailed_dep_t, nav_flags ) == 0 + sizeof(u64) + sizeof(gps_time_dep_t) + sizeof(u32) + sizeof(u16) + sizeof(carrier_phase_t) + sizeof(u8) + sizeof(u16) + sizeof(gnss_signal_dep_t) + sizeof(s32) + sizeof(u16) + sizeof(u32) + sizeof(s16) + sizeof(s16) + sizeof(u16) + sizeof(s8) + sizeof(u8) + sizeof(u8) + sizeof(u8), "Offset of nav_flags in msg_tracking_state_detailed_dep_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_tracking_state_detailed_dep_t, nav_flags ) == 0 + sizeof(u64) + sizeof(gps_time_dep_t) + sizeof(u32) + sizeof(u16) + sizeof(carrier_phase_t) + sizeof(u8) + sizeof(u16) + sizeof(gnss_signal_dep_t) + sizeof(s32) + sizeof(u16) + sizeof(u32) + sizeof(s16) + sizeof(s16) + sizeof(u16) + sizeof(s8) + sizeof(u8) + sizeof(u8) + sizeof(u8), offset_of_nav_flags_in_msg_tracking_state_detailed_dep_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_tracking_state_detailed_dep_t, pset_flags ) == 0 + sizeof(u64) + sizeof(gps_time_dep_t) + sizeof(u32) + sizeof(u16) + sizeof(carrier_phase_t) + sizeof(u8) + sizeof(u16) + sizeof(gnss_signal_dep_t) + sizeof(s32) + sizeof(u16) + sizeof(u32) + sizeof(s16) + sizeof(s16) + sizeof(u16) + sizeof(s8) + sizeof(u8) + sizeof(u8) + sizeof(u8) + sizeof(u8), "Offset of pset_flags in msg_tracking_state_detailed_dep_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_tracking_state_detailed_dep_t, pset_flags ) == 0 + sizeof(u64) + sizeof(gps_time_dep_t) + sizeof(u32) + sizeof(u16) + sizeof(carrier_phase_t) + sizeof(u8) + sizeof(u16) + sizeof(gnss_signal_dep_t) + sizeof(s32) + sizeof(u16) + sizeof(u32) + sizeof(s16) + sizeof(s16) + sizeof(u16) + sizeof(s8) + sizeof(u8) + sizeof(u8) + sizeof(u8) + sizeof(u8), offset_of_pset_flags_in_msg_tracking_state_detailed_dep_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_tracking_state_detailed_dep_t, misc_flags ) == 0 + sizeof(u64) + sizeof(gps_time_dep_t) + sizeof(u32) + sizeof(u16) + sizeof(carrier_phase_t) + sizeof(u8) + sizeof(u16) + sizeof(gnss_signal_dep_t) + sizeof(s32) + sizeof(u16) + sizeof(u32) + sizeof(s16) + sizeof(s16) + sizeof(u16) + sizeof(s8) + sizeof(u8) + sizeof(u8) + sizeof(u8) + sizeof(u8) + sizeof(u8), "Offset of misc_flags in msg_tracking_state_detailed_dep_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_tracking_state_detailed_dep_t, misc_flags ) == 0 + sizeof(u64) + sizeof(gps_time_dep_t) + sizeof(u32) + sizeof(u16) + sizeof(carrier_phase_t) + sizeof(u8) + sizeof(u16) + sizeof(gnss_signal_dep_t) + sizeof(s32) + sizeof(u16) + sizeof(u32) + sizeof(s16) + sizeof(s16) + sizeof(u16) + sizeof(s8) + sizeof(u8) + sizeof(u8) + sizeof(u8) + sizeof(u8) + sizeof(u8), offset_of_misc_flags_in_msg_tracking_state_detailed_dep_t_is_incorrect)
#endif
}

static inline void static_asserts_for_module_TrackingChannelState(void) {
#ifdef __cplusplus
static_assert(offsetof(tracking_channel_state_t, sid ) == 0, "Offset of sid in tracking_channel_state_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(tracking_channel_state_t, sid ) == 0, offset_of_sid_in_tracking_channel_state_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(tracking_channel_state_t, fcn ) == 0 + sizeof(sbp_gnss_signal_t), "Offset of fcn in tracking_channel_state_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(tracking_channel_state_t, fcn ) == 0 + sizeof(sbp_gnss_signal_t), offset_of_fcn_in_tracking_channel_state_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(tracking_channel_state_t, cn0 ) == 0 + sizeof(sbp_gnss_signal_t) + sizeof(u8), "Offset of cn0 in tracking_channel_state_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(tracking_channel_state_t, cn0 ) == 0 + sizeof(sbp_gnss_signal_t) + sizeof(u8), offset_of_cn0_in_tracking_channel_state_t_is_incorrect)
#endif
}

static inline void static_asserts_for_module_MSG_TRACKING_STATE(void) {
#ifdef SBP_ENABLE_VARIABLE_SIZED_ARRAYS
#ifdef __cplusplus
static_assert(offsetof(msg_tracking_state_t, states ) == 0, "Offset of states in msg_tracking_state_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_tracking_state_t, states ) == 0, offset_of_states_in_msg_tracking_state_t_is_incorrect)
#endif
#endif
}

static inline void static_asserts_for_module_MeasurementState(void) {
#ifdef __cplusplus
static_assert(offsetof(measurement_state_t, mesid ) == 0, "Offset of mesid in measurement_state_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(measurement_state_t, mesid ) == 0, offset_of_mesid_in_measurement_state_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(measurement_state_t, cn0 ) == 0 + sizeof(sbp_gnss_signal_t), "Offset of cn0 in measurement_state_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(measurement_state_t, cn0 ) == 0 + sizeof(sbp_gnss_signal_t), offset_of_cn0_in_measurement_state_t_is_incorrect)
#endif
}

static inline void static_asserts_for_module_MSG_MEASUREMENT_STATE(void) {
#ifdef SBP_ENABLE_VARIABLE_SIZED_ARRAYS
#ifdef __cplusplus
static_assert(offsetof(msg_measurement_state_t, states ) == 0, "Offset of states in msg_measurement_state_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_measurement_state_t, states ) == 0, offset_of_states_in_msg_measurement_state_t_is_incorrect)
#endif
#endif
}

static inline void static_asserts_for_module_TrackingChannelCorrelation(void) {
#ifdef __cplusplus
static_assert(offsetof(tracking_channel_correlation_t, I ) == 0, "Offset of I in tracking_channel_correlation_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(tracking_channel_correlation_t, I ) == 0, offset_of_I_in_tracking_channel_correlation_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(tracking_channel_correlation_t, Q ) == 0 + sizeof(s16), "Offset of Q in tracking_channel_correlation_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(tracking_channel_correlation_t, Q ) == 0 + sizeof(s16), offset_of_Q_in_tracking_channel_correlation_t_is_incorrect)
#endif
}

static inline void static_asserts_for_module_MSG_TRACKING_IQ(void) {
#ifdef __cplusplus
static_assert(offsetof(msg_tracking_iq_t, channel ) == 0, "Offset of channel in msg_tracking_iq_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_tracking_iq_t, channel ) == 0, offset_of_channel_in_msg_tracking_iq_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_tracking_iq_t, sid ) == 0 + sizeof(u8), "Offset of sid in msg_tracking_iq_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_tracking_iq_t, sid ) == 0 + sizeof(u8), offset_of_sid_in_msg_tracking_iq_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_tracking_iq_t, corrs ) == 0 + sizeof(u8) + sizeof(sbp_gnss_signal_t), "Offset of corrs in msg_tracking_iq_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_tracking_iq_t, corrs ) == 0 + sizeof(u8) + sizeof(sbp_gnss_signal_t), offset_of_corrs_in_msg_tracking_iq_t_is_incorrect)
#endif
}

static inline void static_asserts_for_module_TrackingChannelCorrelationDep(void) {
#ifdef __cplusplus
static_assert(offsetof(tracking_channel_correlation_dep_t, I ) == 0, "Offset of I in tracking_channel_correlation_dep_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(tracking_channel_correlation_dep_t, I ) == 0, offset_of_I_in_tracking_channel_correlation_dep_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(tracking_channel_correlation_dep_t, Q ) == 0 + sizeof(s32), "Offset of Q in tracking_channel_correlation_dep_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(tracking_channel_correlation_dep_t, Q ) == 0 + sizeof(s32), offset_of_Q_in_tracking_channel_correlation_dep_t_is_incorrect)
#endif
}

static inline void static_asserts_for_module_MSG_TRACKING_IQ_DEP_B(void) {
#ifdef __cplusplus
static_assert(offsetof(msg_tracking_iq_dep_b_t, channel ) == 0, "Offset of channel in msg_tracking_iq_dep_b_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_tracking_iq_dep_b_t, channel ) == 0, offset_of_channel_in_msg_tracking_iq_dep_b_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_tracking_iq_dep_b_t, sid ) == 0 + sizeof(u8), "Offset of sid in msg_tracking_iq_dep_b_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_tracking_iq_dep_b_t, sid ) == 0 + sizeof(u8), offset_of_sid_in_msg_tracking_iq_dep_b_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_tracking_iq_dep_b_t, corrs ) == 0 + sizeof(u8) + sizeof(sbp_gnss_signal_t), "Offset of corrs in msg_tracking_iq_dep_b_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_tracking_iq_dep_b_t, corrs ) == 0 + sizeof(u8) + sizeof(sbp_gnss_signal_t), offset_of_corrs_in_msg_tracking_iq_dep_b_t_is_incorrect)
#endif
}

static inline void static_asserts_for_module_MSG_TRACKING_IQ_DEP_A(void) {
#ifdef __cplusplus
static_assert(offsetof(msg_tracking_iq_dep_a_t, channel ) == 0, "Offset of channel in msg_tracking_iq_dep_a_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_tracking_iq_dep_a_t, channel ) == 0, offset_of_channel_in_msg_tracking_iq_dep_a_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_tracking_iq_dep_a_t, sid ) == 0 + sizeof(u8), "Offset of sid in msg_tracking_iq_dep_a_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_tracking_iq_dep_a_t, sid ) == 0 + sizeof(u8), offset_of_sid_in_msg_tracking_iq_dep_a_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_tracking_iq_dep_a_t, corrs ) == 0 + sizeof(u8) + sizeof(gnss_signal_dep_t), "Offset of corrs in msg_tracking_iq_dep_a_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_tracking_iq_dep_a_t, corrs ) == 0 + sizeof(u8) + sizeof(gnss_signal_dep_t), offset_of_corrs_in_msg_tracking_iq_dep_a_t_is_incorrect)
#endif
}

static inline void static_asserts_for_module_TrackingChannelStateDepA(void) {
#ifdef __cplusplus
static_assert(offsetof(tracking_channel_state_dep_a_t, state ) == 0, "Offset of state in tracking_channel_state_dep_a_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(tracking_channel_state_dep_a_t, state ) == 0, offset_of_state_in_tracking_channel_state_dep_a_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(tracking_channel_state_dep_a_t, prn ) == 0 + sizeof(u8), "Offset of prn in tracking_channel_state_dep_a_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(tracking_channel_state_dep_a_t, prn ) == 0 + sizeof(u8), offset_of_prn_in_tracking_channel_state_dep_a_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(tracking_channel_state_dep_a_t, cn0 ) == 0 + sizeof(u8) + sizeof(u8), "Offset of cn0 in tracking_channel_state_dep_a_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(tracking_channel_state_dep_a_t, cn0 ) == 0 + sizeof(u8) + sizeof(u8), offset_of_cn0_in_tracking_channel_state_dep_a_t_is_incorrect)
#endif
}

static inline void static_asserts_for_module_MSG_TRACKING_STATE_DEP_A(void) {
#ifdef SBP_ENABLE_VARIABLE_SIZED_ARRAYS
#ifdef __cplusplus
static_assert(offsetof(msg_tracking_state_dep_a_t, states ) == 0, "Offset of states in msg_tracking_state_dep_a_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_tracking_state_dep_a_t, states ) == 0, offset_of_states_in_msg_tracking_state_dep_a_t_is_incorrect)
#endif
#endif
}

static inline void static_asserts_for_module_TrackingChannelStateDepB(void) {
#ifdef __cplusplus
static_assert(offsetof(tracking_channel_state_dep_b_t, state ) == 0, "Offset of state in tracking_channel_state_dep_b_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(tracking_channel_state_dep_b_t, state ) == 0, offset_of_state_in_tracking_channel_state_dep_b_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(tracking_channel_state_dep_b_t, sid ) == 0 + sizeof(u8), "Offset of sid in tracking_channel_state_dep_b_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(tracking_channel_state_dep_b_t, sid ) == 0 + sizeof(u8), offset_of_sid_in_tracking_channel_state_dep_b_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(tracking_channel_state_dep_b_t, cn0 ) == 0 + sizeof(u8) + sizeof(gnss_signal_dep_t), "Offset of cn0 in tracking_channel_state_dep_b_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(tracking_channel_state_dep_b_t, cn0 ) == 0 + sizeof(u8) + sizeof(gnss_signal_dep_t), offset_of_cn0_in_tracking_channel_state_dep_b_t_is_incorrect)
#endif
}

static inline void static_asserts_for_module_MSG_TRACKING_STATE_DEP_B(void) {
#ifdef SBP_ENABLE_VARIABLE_SIZED_ARRAYS
#ifdef __cplusplus
static_assert(offsetof(msg_tracking_state_dep_b_t, states ) == 0, "Offset of states in msg_tracking_state_dep_b_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_tracking_state_dep_b_t, states ) == 0, offset_of_states_in_msg_tracking_state_dep_b_t_is_incorrect)
#endif
#endif
}


#ifdef __ghs__
#pragma pack()
#endif
SBP_PACK_END

#endif /* LIBSBP_TRACKING_MESSAGES_H */
