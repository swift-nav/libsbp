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
 * Automatically generated from yaml/swiftnav/sbp/acquisition.yaml
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

#ifndef LIBSBP_V4_ACQUISITION_ACQSVPROFILE_H
#define LIBSBP_V4_ACQUISITION_ACQSVPROFILE_H

#include <math.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>

#include <libsbp/acquisition_macros.h>
#include <libsbp/common.h>
#include <libsbp/v4/gnss/GnssSignal.h>
#include <libsbp/v4/string/sbp_string.h>

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
 *
 * SBP_ACQSVPROFILE
 *
 *****************************************************************************/
/** Acq perfomance measurement and debug
 *
 * Profile for a specific SV for debugging purposes. The message describes SV
 * profile during acquisition time. The message is used to debug and measure the
 * performance.
 */
typedef struct {
  /**
   * SV search job type (deep, fallback, etc)
   */
  u8 job_type;

  /**
   * Acquisition status 1 is Success, 0 is Failure
   */
  u8 status;

  /**
   * CN0 value. Only valid if status is '1' [dB-Hz*10]
   */
  u16 cn0;

  /**
   * Acquisition integration time [ms]
   */
  u8 int_time;

  /**
   * GNSS signal for which acquisition was attempted
   */
  sbp_v4_gnss_signal_t sid;

  /**
   * Acq frequency bin width [Hz]
   */
  u16 bin_width;

  /**
   * Timestamp of the job complete event [ms]
   */
  u32 timestamp;

  /**
   * Time spent to search for sid.code [us]
   */
  u32 time_spent;

  /**
   * Doppler range lowest frequency [Hz]
   */
  s32 cf_min;

  /**
   * Doppler range highest frequency [Hz]
   */
  s32 cf_max;

  /**
   * Doppler value of detected peak. Only valid if status is '1' [Hz]
   */
  s32 cf;

  /**
   * Codephase of detected peak. Only valid if status is '1' [chips*10]
   */
  u32 cp;
} sbp_acq_sv_profile_t;

/**
 * Get encoded size of an instance of sbp_acq_sv_profile_t
 *
 * @param msg sbp_acq_sv_profile_t instance
 * @return Length of on-wire representation
 */
static inline size_t sbp_acq_sv_profile_encoded_len(
    const sbp_acq_sv_profile_t *msg) {
  (void)msg;
  return SBP_ACQ_SV_PROFILE_ENCODED_LEN;
}

/**
 * Encode an instance of sbp_acq_sv_profile_t to wire representation
 *
 * This function encodes the given instance in to the user provided buffer. The
 * buffer provided to this function must be large enough to store the encoded
 * message otherwise it will return SBP_ENCODE_ERROR without writing anything to
 * the buffer.
 *
 * Specify the length of the destination buffer in the \p len parameter. If
 * non-null the number of bytes written to the buffer will be returned in \p
 * n_written.
 *
 * @param buf Destination buffer
 * @param len Length of \p buf
 * @param n_written If not null, on success will be set to the number of bytes
 * written to \p buf
 * @param msg Instance of sbp_acq_sv_profile_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
SBP_EXPORT s8 sbp_acq_sv_profile_encode(uint8_t *buf, uint8_t len,
                                        uint8_t *n_written,
                                        const sbp_acq_sv_profile_t *msg);

/**
 * Decode an instance of sbp_acq_sv_profile_t from wire representation
 *
 * This function decodes the wire representation of a sbp_acq_sv_profile_t
 * message to the given instance. The caller must specify the length of the
 * buffer in the \p len parameter. If non-null the number of bytes read from the
 * buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_acq_sv_profile_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
SBP_EXPORT s8 sbp_acq_sv_profile_decode(const uint8_t *buf, uint8_t len,
                                        uint8_t *n_read,
                                        sbp_acq_sv_profile_t *msg);

/**
 * Compare two instances of sbp_acq_sv_profile_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_acq_sv_profile_t instance
 * @param b sbp_acq_sv_profile_t instance
 * @return 0, <0, >0
 */
SBP_EXPORT int sbp_acq_sv_profile_cmp(const sbp_acq_sv_profile_t *a,
                                      const sbp_acq_sv_profile_t *b);

#ifdef __cplusplus
}

static inline bool operator==(const sbp_acq_sv_profile_t &lhs,
                              const sbp_acq_sv_profile_t &rhs) {
  return sbp_acq_sv_profile_cmp(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_acq_sv_profile_t &lhs,
                              const sbp_acq_sv_profile_t &rhs) {
  return sbp_acq_sv_profile_cmp(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_acq_sv_profile_t &lhs,
                             const sbp_acq_sv_profile_t &rhs) {
  return sbp_acq_sv_profile_cmp(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_acq_sv_profile_t &lhs,
                              const sbp_acq_sv_profile_t &rhs) {
  return sbp_acq_sv_profile_cmp(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_acq_sv_profile_t &lhs,
                             const sbp_acq_sv_profile_t &rhs) {
  return sbp_acq_sv_profile_cmp(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_acq_sv_profile_t &lhs,
                              const sbp_acq_sv_profile_t &rhs) {
  return sbp_acq_sv_profile_cmp(&lhs, &rhs) >= 0;
}

#endif  // ifdef __cplusplus

#endif /* LIBSBP_V4_ACQUISITION_ACQSVPROFILE_H */
