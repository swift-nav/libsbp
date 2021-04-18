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
 * Automatically generated from yaml/swiftnav/sbp/acquisition.yaml
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

#ifndef LIBSBP_CPP_ACQUISITION_MESSAGES_H
#define LIBSBP_CPP_ACQUISITION_MESSAGES_H

#include <cstddef>
#include <libsbp/common.h>
#include <libsbp/sbp.h>
#include <libsbp/cpp/gnss.h>

namespace sbp {
  
  /**
   * Satellite acquisition result
   *
   * This message describes the results from an attempted GPS signal
   * acquisition search for a satellite PRN over a code phase/carrier
   * frequency range. It contains the parameters of the point in the
   * acquisition search space with the best carrier-to-noise (CN/0)
   * ratio.
   */
  
  struct SBP_ATTR_PACKED MsgAcqResult {
    float cn0; /** CN/0 of best point [dB Hz] */
    float cp; /** Code phase of best point [chips] */
    float cf; /** Carrier frequency of best point [hz] */
    GnssSignal sid; /** GNSS signal for which acquisition was attempted */
  };
  
  /**
   * Deprecated
   *
   * Deprecated.
   */
  
  struct SBP_ATTR_PACKED MsgAcqResultDepC {
    float cn0; /** CN/0 of best point [dB Hz] */
    float cp; /** Code phase of best point [chips] */
    float cf; /** Carrier frequency of best point [hz] */
    GnssSignalDep sid; /** GNSS signal for which acquisition was attempted */
  };
  
  /**
   * Deprecated
   *
   * Deprecated.
   */
  
  struct SBP_ATTR_PACKED MsgAcqResultDepB {
    float snr; /** SNR of best point. Currently in arbitrary SNR points, but will
be in units of dB Hz in a later revision of this message.
 */
    float cp; /** Code phase of best point [chips] */
    float cf; /** Carrier frequency of best point [hz] */
    GnssSignalDep sid; /** GNSS signal for which acquisition was attempted */
  };
  
  /**
   * Deprecated
   *
   * Deprecated.
   */
  
  struct SBP_ATTR_PACKED MsgAcqResultDepA {
    float snr; /** SNR of best point. Currently dimensonless, but will have
units of dB Hz in the revision of this message.
 */
    float cp; /** Code phase of best point [chips] */
    float cf; /** Carrier frequency of best point [hz] */
    u8 prn; /** PRN-1 identifier of the satellite signal for which
acquisition was attempted
 */
  };
  
  /**
   * Acq perfomance measurement and debug
   *
   * Profile for a specific SV for debugging purposes
   * The message describes SV profile during acquisition time.
   * The message is used to debug and measure the performance.
   */
  
  struct SBP_ATTR_PACKED AcqSvProfile {
    u8 job_type; /** SV search job type (deep, fallback, etc) */
    u8 status; /** Acquisition status 1 is Success, 0 is Failure */
    u16 cn0; /** CN0 value. Only valid if status is '1' [dB-Hz*10] */
    u8 int_time; /** Acquisition integration time [ms] */
    GnssSignal sid; /** GNSS signal for which acquisition was attempted */
    u16 bin_width; /** Acq frequency bin width [Hz] */
    u32 timestamp; /** Timestamp of the job complete event [ms] */
    u32 time_spent; /** Time spent to search for sid.code [us] */
    s32 cf_min; /** Doppler range lowest frequency [Hz] */
    s32 cf_max; /** Doppler range highest frequency [Hz] */
    s32 cf; /** Doppler value of detected peak. Only valid if status is '1' [Hz] */
    u32 cp; /** Codephase of detected peak. Only valid if status is '1' [chips*10] */
  };
  
  /**
   * Deprecated
   *
   * Deprecated.
   */
  
  struct SBP_ATTR_PACKED AcqSvProfileDep {
    u8 job_type; /** SV search job type (deep, fallback, etc) */
    u8 status; /** Acquisition status 1 is Success, 0 is Failure */
    u16 cn0; /** CN0 value. Only valid if status is '1' [dB-Hz*10] */
    u8 int_time; /** Acquisition integration time [ms] */
    GnssSignalDep sid; /** GNSS signal for which acquisition was attempted */
    u16 bin_width; /** Acq frequency bin width [Hz] */
    u32 timestamp; /** Timestamp of the job complete event [ms] */
    u32 time_spent; /** Time spent to search for sid.code [us] */
    s32 cf_min; /** Doppler range lowest frequency [Hz] */
    s32 cf_max; /** Doppler range highest frequency [Hz] */
    s32 cf; /** Doppler value of detected peak. Only valid if status is '1' [Hz] */
    u32 cp; /** Codephase of detected peak. Only valid if status is '1' [chips*10] */
  };
  
  /**
   * Acquisition perfomance measurement and debug
   *
   * The message describes all SV profiles during acquisition time.
   * The message is used to debug and measure the performance.
   */
  template<size_t ACQ_SV_PROFILE_COUNT = (SBP_MAX_PAYLOAD_LEN - (0)) / sizeof(AcqSvProfile)>
  struct SBP_ATTR_PACKED MsgAcqSvProfile {
    static constexpr size_t kAcqSvProfileCount = ACQ_SV_PROFILE_COUNT;
    AcqSvProfile acq_sv_profile[ACQ_SV_PROFILE_COUNT]; /** SV profiles during acquisition time */
  };
  
  /**
   * Deprecated.
   *
   * Deprecated.
   */
  template<size_t ACQ_SV_PROFILE_COUNT = (SBP_MAX_PAYLOAD_LEN - (0)) / sizeof(AcqSvProfileDep)>
  struct SBP_ATTR_PACKED MsgAcqSvProfileDep {
    static constexpr size_t kAcqSvProfileCount = ACQ_SV_PROFILE_COUNT;
    AcqSvProfileDep acq_sv_profile[ACQ_SV_PROFILE_COUNT]; /** SV profiles during acquisition time */
  };
  

}  // namespace sbp

#endif /* LIBSBP_CPP_ACQUISITION_MESSAGES_H */