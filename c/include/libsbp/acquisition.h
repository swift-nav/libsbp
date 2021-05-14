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
 * Automatically generated from yaml/swiftnav/sbp/acquisition.yaml
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

/** \defgroup acquisition Acquisition
 *
 * * Satellite acquisition messages from the device.
 * \{ */

#ifndef LIBSBP_ACQUISITION_MESSAGES_H
#define LIBSBP_ACQUISITION_MESSAGES_H

#include "common.h"
#include "gnss.h"

SBP_PACK_START


/** Satellite acquisition result
 *
 * This message describes the results from an attempted GPS signal
 * acquisition search for a satellite PRN over a code phase/carrier
 * frequency range. It contains the parameters of the point in the
 * acquisition search space with the best carrier-to-noise (CN/0)
 * ratio.
 */
#define SBP_MSG_ACQ_RESULT         0x002F

typedef struct SBP_ATTR_PACKED {
  float cn0;    /**< CN/0 of best point [dB Hz] */
  float cp;     /**< Code phase of best point [chips] */
  float cf;     /**< Carrier frequency of best point [hz] */
  sbp_gnss_signal_t sid;    /**< GNSS signal for which acquisition was attempted */
} msg_acq_result_t;
 

/** Deprecated
 *
* Deprecated.
 */
#define SBP_MSG_ACQ_RESULT_DEP_C   0x001F

typedef struct SBP_ATTR_PACKED {
  float cn0;    /**< CN/0 of best point [dB Hz] */
  float cp;     /**< Code phase of best point [chips] */
  float cf;     /**< Carrier frequency of best point [hz] */
  gnss_signal_dep_t sid;    /**< GNSS signal for which acquisition was attempted */
} msg_acq_result_dep_c_t;
 

/** Deprecated
 *
* Deprecated.
 */
#define SBP_MSG_ACQ_RESULT_DEP_B   0x0014

typedef struct SBP_ATTR_PACKED {
  float snr;    /**< SNR of best point. Currently in arbitrary SNR points, but will
be in units of dB Hz in a later revision of this message.
 */
  float cp;     /**< Code phase of best point [chips] */
  float cf;     /**< Carrier frequency of best point [hz] */
  gnss_signal_dep_t sid;    /**< GNSS signal for which acquisition was attempted */
} msg_acq_result_dep_b_t;
 

/** Deprecated
 *
* Deprecated.
 */
#define SBP_MSG_ACQ_RESULT_DEP_A   0x0015

typedef struct SBP_ATTR_PACKED {
  float snr;    /**< SNR of best point. Currently dimensonless, but will have
units of dB Hz in the revision of this message.
 */
  float cp;     /**< Code phase of best point [chips] */
  float cf;     /**< Carrier frequency of best point [hz] */
  u8 prn;    /**< PRN-1 identifier of the satellite signal for which
acquisition was attempted
 */
} msg_acq_result_dep_a_t;
 

/** Acq perfomance measurement and debug
 *
 * Profile for a specific SV for debugging purposes
 * The message describes SV profile during acquisition time.
 * The message is used to debug and measure the performance.
 */

typedef struct SBP_ATTR_PACKED {
  u8 job_type;      /**< SV search job type (deep, fallback, etc) */
  u8 status;        /**< Acquisition status 1 is Success, 0 is Failure */
  u16 cn0;           /**< CN0 value. Only valid if status is '1' [dB-Hz*10] */
  u8 int_time;      /**< Acquisition integration time [ms] */
  sbp_gnss_signal_t sid;           /**< GNSS signal for which acquisition was attempted */
  u16 bin_width;     /**< Acq frequency bin width [Hz] */
  u32 timestamp;     /**< Timestamp of the job complete event [ms] */
  u32 time_spent;    /**< Time spent to search for sid.code [us] */
  s32 cf_min;        /**< Doppler range lowest frequency [Hz] */
  s32 cf_max;        /**< Doppler range highest frequency [Hz] */
  s32 cf;            /**< Doppler value of detected peak. Only valid if status is '1' [Hz] */
  u32 cp;            /**< Codephase of detected peak. Only valid if status is '1' [chips*10] */
} acq_sv_profile_t;
 

/** Deprecated
 *
* Deprecated.
 */

typedef struct SBP_ATTR_PACKED {
  u8 job_type;      /**< SV search job type (deep, fallback, etc) */
  u8 status;        /**< Acquisition status 1 is Success, 0 is Failure */
  u16 cn0;           /**< CN0 value. Only valid if status is '1' [dB-Hz*10] */
  u8 int_time;      /**< Acquisition integration time [ms] */
  gnss_signal_dep_t sid;           /**< GNSS signal for which acquisition was attempted */
  u16 bin_width;     /**< Acq frequency bin width [Hz] */
  u32 timestamp;     /**< Timestamp of the job complete event [ms] */
  u32 time_spent;    /**< Time spent to search for sid.code [us] */
  s32 cf_min;        /**< Doppler range lowest frequency [Hz] */
  s32 cf_max;        /**< Doppler range highest frequency [Hz] */
  s32 cf;            /**< Doppler value of detected peak. Only valid if status is '1' [Hz] */
  u32 cp;            /**< Codephase of detected peak. Only valid if status is '1' [chips*10] */
} acq_sv_profile_dep_t;
 

/** Acquisition perfomance measurement and debug
 *
 * The message describes all SV profiles during acquisition time.
 * The message is used to debug and measure the performance.
 */
#define SBP_MSG_ACQ_SV_PROFILE     0x002E
#ifdef SBP_ENABLE_VARIABLE_SIZED_ARRAYS

typedef struct SBP_ATTR_PACKED {
  acq_sv_profile_t acq_sv_profile[0]; /**< SV profiles during acquisition time */
} msg_acq_sv_profile_t;
#endif
 

/** Deprecated.
 *
* Deprecated.
 */
#define SBP_MSG_ACQ_SV_PROFILE_DEP 0x001E
#ifdef SBP_ENABLE_VARIABLE_SIZED_ARRAYS

typedef struct SBP_ATTR_PACKED {
  acq_sv_profile_dep_t acq_sv_profile[0]; /**< SV profiles during acquisition time */
} msg_acq_sv_profile_dep_t;
#endif
 

/** \} */
static inline void static_asserts_for_module_MSG_ACQ_RESULT(void) {
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_acq_result_t, cn0 ) == 0, offset_of_cn0_in_msg_acq_result_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_acq_result_t, cp ) == 0 + sizeof(float), offset_of_cp_in_msg_acq_result_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_acq_result_t, cf ) == 0 + sizeof(float) + sizeof(float), offset_of_cf_in_msg_acq_result_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_acq_result_t, sid ) == 0 + sizeof(float) + sizeof(float) + sizeof(float), offset_of_sid_in_msg_acq_result_t_is_incorrect)
}

static inline void static_asserts_for_module_MSG_ACQ_RESULT_DEP_C(void) {
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_acq_result_dep_c_t, cn0 ) == 0, offset_of_cn0_in_msg_acq_result_dep_c_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_acq_result_dep_c_t, cp ) == 0 + sizeof(float), offset_of_cp_in_msg_acq_result_dep_c_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_acq_result_dep_c_t, cf ) == 0 + sizeof(float) + sizeof(float), offset_of_cf_in_msg_acq_result_dep_c_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_acq_result_dep_c_t, sid ) == 0 + sizeof(float) + sizeof(float) + sizeof(float), offset_of_sid_in_msg_acq_result_dep_c_t_is_incorrect)
}

static inline void static_asserts_for_module_MSG_ACQ_RESULT_DEP_B(void) {
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_acq_result_dep_b_t, snr ) == 0, offset_of_snr_in_msg_acq_result_dep_b_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_acq_result_dep_b_t, cp ) == 0 + sizeof(float), offset_of_cp_in_msg_acq_result_dep_b_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_acq_result_dep_b_t, cf ) == 0 + sizeof(float) + sizeof(float), offset_of_cf_in_msg_acq_result_dep_b_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_acq_result_dep_b_t, sid ) == 0 + sizeof(float) + sizeof(float) + sizeof(float), offset_of_sid_in_msg_acq_result_dep_b_t_is_incorrect)
}

static inline void static_asserts_for_module_MSG_ACQ_RESULT_DEP_A(void) {
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_acq_result_dep_a_t, snr ) == 0, offset_of_snr_in_msg_acq_result_dep_a_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_acq_result_dep_a_t, cp ) == 0 + sizeof(float), offset_of_cp_in_msg_acq_result_dep_a_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_acq_result_dep_a_t, cf ) == 0 + sizeof(float) + sizeof(float), offset_of_cf_in_msg_acq_result_dep_a_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_acq_result_dep_a_t, prn ) == 0 + sizeof(float) + sizeof(float) + sizeof(float), offset_of_prn_in_msg_acq_result_dep_a_t_is_incorrect)
}

static inline void static_asserts_for_module_AcqSvProfile(void) {
SBP_STATIC_ASSERT(SBP_OFFSET_OF(acq_sv_profile_t, job_type ) == 0, offset_of_job_type_in_acq_sv_profile_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(acq_sv_profile_t, status ) == 0 + sizeof(u8), offset_of_status_in_acq_sv_profile_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(acq_sv_profile_t, cn0 ) == 0 + sizeof(u8) + sizeof(u8), offset_of_cn0_in_acq_sv_profile_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(acq_sv_profile_t, int_time ) == 0 + sizeof(u8) + sizeof(u8) + sizeof(u16), offset_of_int_time_in_acq_sv_profile_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(acq_sv_profile_t, sid ) == 0 + sizeof(u8) + sizeof(u8) + sizeof(u16) + sizeof(u8), offset_of_sid_in_acq_sv_profile_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(acq_sv_profile_t, bin_width ) == 0 + sizeof(u8) + sizeof(u8) + sizeof(u16) + sizeof(u8) + sizeof(sbp_gnss_signal_t), offset_of_bin_width_in_acq_sv_profile_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(acq_sv_profile_t, timestamp ) == 0 + sizeof(u8) + sizeof(u8) + sizeof(u16) + sizeof(u8) + sizeof(sbp_gnss_signal_t) + sizeof(u16), offset_of_timestamp_in_acq_sv_profile_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(acq_sv_profile_t, time_spent ) == 0 + sizeof(u8) + sizeof(u8) + sizeof(u16) + sizeof(u8) + sizeof(sbp_gnss_signal_t) + sizeof(u16) + sizeof(u32), offset_of_time_spent_in_acq_sv_profile_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(acq_sv_profile_t, cf_min ) == 0 + sizeof(u8) + sizeof(u8) + sizeof(u16) + sizeof(u8) + sizeof(sbp_gnss_signal_t) + sizeof(u16) + sizeof(u32) + sizeof(u32), offset_of_cf_min_in_acq_sv_profile_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(acq_sv_profile_t, cf_max ) == 0 + sizeof(u8) + sizeof(u8) + sizeof(u16) + sizeof(u8) + sizeof(sbp_gnss_signal_t) + sizeof(u16) + sizeof(u32) + sizeof(u32) + sizeof(s32), offset_of_cf_max_in_acq_sv_profile_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(acq_sv_profile_t, cf ) == 0 + sizeof(u8) + sizeof(u8) + sizeof(u16) + sizeof(u8) + sizeof(sbp_gnss_signal_t) + sizeof(u16) + sizeof(u32) + sizeof(u32) + sizeof(s32) + sizeof(s32), offset_of_cf_in_acq_sv_profile_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(acq_sv_profile_t, cp ) == 0 + sizeof(u8) + sizeof(u8) + sizeof(u16) + sizeof(u8) + sizeof(sbp_gnss_signal_t) + sizeof(u16) + sizeof(u32) + sizeof(u32) + sizeof(s32) + sizeof(s32) + sizeof(s32), offset_of_cp_in_acq_sv_profile_t_is_incorrect)
}

static inline void static_asserts_for_module_AcqSvProfileDep(void) {
SBP_STATIC_ASSERT(SBP_OFFSET_OF(acq_sv_profile_dep_t, job_type ) == 0, offset_of_job_type_in_acq_sv_profile_dep_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(acq_sv_profile_dep_t, status ) == 0 + sizeof(u8), offset_of_status_in_acq_sv_profile_dep_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(acq_sv_profile_dep_t, cn0 ) == 0 + sizeof(u8) + sizeof(u8), offset_of_cn0_in_acq_sv_profile_dep_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(acq_sv_profile_dep_t, int_time ) == 0 + sizeof(u8) + sizeof(u8) + sizeof(u16), offset_of_int_time_in_acq_sv_profile_dep_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(acq_sv_profile_dep_t, sid ) == 0 + sizeof(u8) + sizeof(u8) + sizeof(u16) + sizeof(u8), offset_of_sid_in_acq_sv_profile_dep_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(acq_sv_profile_dep_t, bin_width ) == 0 + sizeof(u8) + sizeof(u8) + sizeof(u16) + sizeof(u8) + sizeof(gnss_signal_dep_t), offset_of_bin_width_in_acq_sv_profile_dep_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(acq_sv_profile_dep_t, timestamp ) == 0 + sizeof(u8) + sizeof(u8) + sizeof(u16) + sizeof(u8) + sizeof(gnss_signal_dep_t) + sizeof(u16), offset_of_timestamp_in_acq_sv_profile_dep_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(acq_sv_profile_dep_t, time_spent ) == 0 + sizeof(u8) + sizeof(u8) + sizeof(u16) + sizeof(u8) + sizeof(gnss_signal_dep_t) + sizeof(u16) + sizeof(u32), offset_of_time_spent_in_acq_sv_profile_dep_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(acq_sv_profile_dep_t, cf_min ) == 0 + sizeof(u8) + sizeof(u8) + sizeof(u16) + sizeof(u8) + sizeof(gnss_signal_dep_t) + sizeof(u16) + sizeof(u32) + sizeof(u32), offset_of_cf_min_in_acq_sv_profile_dep_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(acq_sv_profile_dep_t, cf_max ) == 0 + sizeof(u8) + sizeof(u8) + sizeof(u16) + sizeof(u8) + sizeof(gnss_signal_dep_t) + sizeof(u16) + sizeof(u32) + sizeof(u32) + sizeof(s32), offset_of_cf_max_in_acq_sv_profile_dep_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(acq_sv_profile_dep_t, cf ) == 0 + sizeof(u8) + sizeof(u8) + sizeof(u16) + sizeof(u8) + sizeof(gnss_signal_dep_t) + sizeof(u16) + sizeof(u32) + sizeof(u32) + sizeof(s32) + sizeof(s32), offset_of_cf_in_acq_sv_profile_dep_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(acq_sv_profile_dep_t, cp ) == 0 + sizeof(u8) + sizeof(u8) + sizeof(u16) + sizeof(u8) + sizeof(gnss_signal_dep_t) + sizeof(u16) + sizeof(u32) + sizeof(u32) + sizeof(s32) + sizeof(s32) + sizeof(s32), offset_of_cp_in_acq_sv_profile_dep_t_is_incorrect)
}

static inline void static_asserts_for_module_MSG_ACQ_SV_PROFILE(void) {
#ifdef SBP_ENABLE_VARIABLE_SIZED_ARRAYS
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_acq_sv_profile_t, acq_sv_profile ) == 0, offset_of_acq_sv_profile_in_msg_acq_sv_profile_t_is_incorrect)
#endif
}

static inline void static_asserts_for_module_MSG_ACQ_SV_PROFILE_DEP(void) {
#ifdef SBP_ENABLE_VARIABLE_SIZED_ARRAYS
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_acq_sv_profile_dep_t, acq_sv_profile ) == 0, offset_of_acq_sv_profile_in_msg_acq_sv_profile_dep_t_is_incorrect)
#endif
}


SBP_PACK_END

#endif /* LIBSBP_ACQUISITION_MESSAGES_H */
