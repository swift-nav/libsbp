/*
 * Copyright (C) 2021 Swift Navigation Inc.
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

#ifndef LIBSBP_CPP_TRACKING_MESSAGES_H
#define LIBSBP_CPP_TRACKING_MESSAGES_H

#include <cstddef>
#include <libsbp/common.h>
#include <libsbp/sbp.h>
#include <libsbp/cpp/gnss.h>

namespace sbp {
  
  /**
   * Detailed signal tracking channel states. DEPRECATED.
   *
   * The tracking message returns a set tracking channel parameters for a
   * single tracking channel useful for debugging issues.
   */
  
  struct SBP_ATTR_PACKED MsgTrackingStateDetailedDepA {
    u64 recv_time; /** Receiver clock time. [ns] */
    GPSTime tot; /** Time of transmission of signal from satellite. TOW only valid when
TOW status is decoded or propagated. WN only valid when week
number valid flag is set.
 */
    u32 P; /** Pseudorange observation. Valid only when pseudorange valid flag is
set.
 [2 cm] */
    u16 P_std; /** Pseudorange observation standard deviation. Valid only when
pseudorange valid flag is set.
 [2 cm] */
    CarrierPhase L; /** Carrier phase observation with typical sign convention. Valid only
when PLL pessimistic lock is achieved.
 [cycles] */
    u8 cn0; /** Carrier-to-Noise density [dB Hz / 4] */
    u16 lock; /** Lock time. It is encoded according to DF402 from the RTCM 10403.2
Amendment 2 specification. Valid values range from 0 to 15.
 */
    GnssSignal sid; /** GNSS signal identifier. */
    s32 doppler; /** Carrier Doppler frequency. [Hz / 16] */
    u16 doppler_std; /** Carrier Doppler frequency standard deviation. [Hz / 16] */
    u32 uptime; /** Number of seconds of continuous tracking. Specifies how much time
signal is in continuous track.
 [s] */
    s16 clock_offset; /** TCXO clock offset. Valid only when valid clock valid flag is set.
 [s / (2 ^ 20)] */
    s16 clock_drift; /** TCXO clock drift. Valid only when valid clock valid flag is set.
 [(s / s) / (2 ^ 31)] */
    u16 corr_spacing; /** Early-Prompt (EP) and Prompt-Late (PL) correlators spacing. [ns] */
    s8 acceleration; /** Acceleration. Valid only when acceleration valid flag is set. [g / 8] */
    u8 sync_flags; /** Synchronization status flags. */
    u8 tow_flags; /** TOW status flags. */
    u8 track_flags; /** Tracking loop status flags. */
    u8 nav_flags; /** Navigation data status flags. */
    u8 pset_flags; /** Parameters sets flags. */
    u8 misc_flags; /** Miscellaneous flags. */
  };
  
  /**
   * Deprecated
   *
   * Deprecated.
   */
  
  struct SBP_ATTR_PACKED MsgTrackingStateDetailedDep {
    u64 recv_time; /** Receiver clock time. [ns] */
    GPSTimeDep tot; /** Time of transmission of signal from satellite. TOW only valid when
TOW status is decoded or propagated. WN only valid when week
number valid flag is set.
 */
    u32 P; /** Pseudorange observation. Valid only when pseudorange valid flag is
set.
 [2 cm] */
    u16 P_std; /** Pseudorange observation standard deviation. Valid only when
pseudorange valid flag is set.
 [2 cm] */
    CarrierPhase L; /** Carrier phase observation with typical sign convention. Valid only
when PLL pessimistic lock is achieved.
 [cycles] */
    u8 cn0; /** Carrier-to-Noise density [dB Hz / 4] */
    u16 lock; /** Lock time. It is encoded according to DF402 from the RTCM 10403.2
Amendment 2 specification. Valid values range from 0 to 15.
 */
    GnssSignalDep sid; /** GNSS signal identifier. */
    s32 doppler; /** Carrier Doppler frequency. [Hz / 16] */
    u16 doppler_std; /** Carrier Doppler frequency standard deviation. [Hz / 16] */
    u32 uptime; /** Number of seconds of continuous tracking. Specifies how much time
signal is in continuous track.
 [s] */
    s16 clock_offset; /** TCXO clock offset. Valid only when valid clock valid flag is set.
 [s / (2 ^ 20)] */
    s16 clock_drift; /** TCXO clock drift. Valid only when valid clock valid flag is set.
 [(s / s) / (2 ^ 31)] */
    u16 corr_spacing; /** Early-Prompt (EP) and Prompt-Late (PL) correlators spacing. [ns] */
    s8 acceleration; /** Acceleration. Valid only when acceleration valid flag is set. [g / 8] */
    u8 sync_flags; /** Synchronization status flags. */
    u8 tow_flags; /** TOW status flags. */
    u8 track_flags; /** Tracking loop status flags. */
    u8 nav_flags; /** Navigation data status flags. */
    u8 pset_flags; /** Parameters sets flags. */
    u8 misc_flags; /** Miscellaneous flags. */
  };
  
  /**
   * Signal tracking channel state
   *
   * Tracking channel state for a specific satellite signal and
   * measured signal power.
   */
  
  struct SBP_ATTR_PACKED TrackingChannelState {
    GnssSignal sid; /** GNSS signal being tracked */
    u8 fcn; /** Frequency channel number (GLONASS only) */
    u8 cn0; /** Carrier-to-Noise density.  Zero implies invalid cn0. [dB Hz / 4] */
  };
  
  /**
   * Signal tracking channel states
   *
   * The tracking message returns a variable-length array of tracking
   * channel states. It reports status and carrier-to-noise density
   * measurements for all tracked satellites.
   */
  template<size_t STATES_COUNT = (SBP_MAX_PAYLOAD_LEN - (0)) / sizeof(TrackingChannelState)>
  struct SBP_ATTR_PACKED MsgTrackingState {
    TrackingChannelState states[STATES_COUNT]; /** Signal tracking channel state */
  };
  
  /**
   * Measurement Engine signal tracking channel state
   *
   * Measurement Engine tracking channel state for a specific satellite signal
   * and measured signal power.
   * The mesid field for Glonass can either
   * carry the FCN as 100 + FCN where FCN is in [-7, +6] or
   * the Slot ID (from 1 to 28)
   */
  
  struct SBP_ATTR_PACKED MeasurementState {
    GnssSignal mesid; /** Measurement Engine GNSS signal being tracked (carries either Glonass FCN or SLOT) */
    u8 cn0; /** Carrier-to-Noise density.  Zero implies invalid cn0. [dB Hz / 4] */
  };
  
  /**
   * Measurement Engine signal tracking channel states
   *
   * The tracking message returns a variable-length array of tracking
   * channel states. It reports status and carrier-to-noise density
   * measurements for all tracked satellites.
   */
  template<size_t STATES_COUNT = (SBP_MAX_PAYLOAD_LEN - (0)) / sizeof(MeasurementState)>
  struct SBP_ATTR_PACKED MsgMeasurementState {
    MeasurementState states[STATES_COUNT]; /** ME signal tracking channel state */
  };
  
  /**
   * Complex correlation structure
   *
   * Structure containing in-phase and quadrature correlation components.
   */
  
  struct SBP_ATTR_PACKED TrackingChannelCorrelation {
    s16 I; /** In-phase correlation */
    s16 Q; /** Quadrature correlation */
  };
  
  /**
   * Tracking channel correlations
   *
   * When enabled, a tracking channel can output the correlations at each
   * update interval.
   */
  
  struct SBP_ATTR_PACKED MsgTrackingIq {
    u8 channel; /** Tracking channel of origin */
    GnssSignal sid; /** GNSS signal identifier */
    TrackingChannelCorrelation corrs[3]; /** Early, Prompt and Late correlations */
  };
  
  /**
   * Complex correlation structure
   *
   * Structure containing in-phase and quadrature correlation components.
   */
  
  struct SBP_ATTR_PACKED TrackingChannelCorrelationDep {
    s32 I; /** In-phase correlation */
    s32 Q; /** Quadrature correlation */
  };
  
  /**
   * Tracking channel correlations
   *
   * When enabled, a tracking channel can output the correlations at each
   * update interval.
   */
  
  struct SBP_ATTR_PACKED MsgTrackingIqDepB {
    u8 channel; /** Tracking channel of origin */
    GnssSignal sid; /** GNSS signal identifier */
    TrackingChannelCorrelationDep corrs[3]; /** Early, Prompt and Late correlations */
  };
  
  /**
   * Deprecated
   *
   * Deprecated.
   */
  
  struct SBP_ATTR_PACKED MsgTrackingIqDepA {
    u8 channel; /** Tracking channel of origin */
    GnssSignalDep sid; /** GNSS signal identifier */
    TrackingChannelCorrelationDep corrs[3]; /** Early, Prompt and Late correlations */
  };
  
  /**
   * Deprecated
   *
   * Deprecated.
   */
  
  struct SBP_ATTR_PACKED TrackingChannelStateDepA {
    u8 state; /** Status of tracking channel */
    u8 prn; /** PRN-1 being tracked */
    float cn0; /** Carrier-to-noise density [dB Hz] */
  };
  
  /**
   * Deprecated
   *
   * Deprecated.
   */
  template<size_t STATES_COUNT = (SBP_MAX_PAYLOAD_LEN - (0)) / sizeof(TrackingChannelStateDepA)>
  struct SBP_ATTR_PACKED MsgTrackingStateDepA {
    TrackingChannelStateDepA states[STATES_COUNT]; /** Satellite tracking channel state */
  };
  
  /**
   * Deprecated.
   *
   * Deprecated.
   */
  
  struct SBP_ATTR_PACKED TrackingChannelStateDepB {
    u8 state; /** Status of tracking channel */
    GnssSignalDep sid; /** GNSS signal being tracked */
    float cn0; /** Carrier-to-noise density [dB Hz] */
  };
  
  /**
   * Deprecated.
   *
   * Deprecated.
   */
  template<size_t STATES_COUNT = (SBP_MAX_PAYLOAD_LEN - (0)) / sizeof(TrackingChannelStateDepB)>
  struct SBP_ATTR_PACKED MsgTrackingStateDepB {
    TrackingChannelStateDepB states[STATES_COUNT]; /** Signal tracking channel state */
  };
  

}  // namespace sbp

#endif /* LIBSBP_CPP_TRACKING_MESSAGES_H */