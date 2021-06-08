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

#ifndef LIBSBP_NEW_ACQUISITION_MESSAGES_H
#define LIBSBP_NEW_ACQUISITION_MESSAGES_H

#include <endian.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>

#include <libsbp/acquisition_macros.h>
#include <libsbp/common.h>
#include <libsbp/new/gnss.h>
#include <libsbp/new/string/double_null_terminated.h>
#include <libsbp/new/string/multipart.h>
#include <libsbp/new/string/null_terminated.h>
#include <libsbp/new/string/unterminated.h>

#ifdef __cplusplus
extern "C" {
#endif

struct sbp_state;

/*
 *
 *
 *
 ******************************************************************************
 *
 * SBP_MSG_ACQ_RESULT
 *
 *****************************************************************************/
/** Satellite acquisition result
 *
 * This message describes the results from an attempted GPS signal acquisition
 * search for a satellite PRN over a code phase/carrier frequency range. It
 * contains the parameters of the point in the acquisition search space with the
 * best carrier-to-noise (CN/0) ratio.
 */
typedef struct {
  /**
   * CN/0 of best point [dB Hz]
   */
  float cn0;

  /**
   * Code phase of best point [chips]
   */
  float cp;

  /**
   * Carrier frequency of best point [hz]
   */
  float cf;

  /**
   * GNSS signal for which acquisition was attempted
   */
  sbp_sbp_gnss_signal_t sid;
} sbp_msg_acq_result_t;

/**
 * Get encoded size of an instance of sbp_msg_acq_result_t
 *
 * @param msg sbp_msg_acq_result_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_msg_acq_result_t(const sbp_msg_acq_result_t *msg);

/**
 * Encode an instance of sbp_msg_acq_result_t to wire representation
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
 * @param msg Instance of sbp_msg_acq_result_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_msg_acq_result_t(uint8_t *buf, uint8_t len,
                                   uint8_t *n_written,
                                   const sbp_msg_acq_result_t *msg);

/**
 * Decode an instance of sbp_msg_acq_result_t from wire representation
 *
 * This function decodes the wire representation of a sbp_msg_acq_result_t
 * message to the given instance. The caller must specify the length of the
 * buffer in the \p len parameter. If non-null the number of bytes read from the
 * buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_msg_acq_result_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_msg_acq_result_t(const uint8_t *buf, uint8_t len,
                                   uint8_t *n_read, sbp_msg_acq_result_t *msg);
/**
 * Send an instance of sbp_msg_acq_result_t with the given write function
 *
 * An equivalent of #sbp_send_message which operates specifically on
 * sbp_msg_acq_result_t
 *
 * The given message will be encoded to wire representation and passed in to the
 * given write function callback. The write callback will be called several
 * times for each invocation of this function.
 *
 * @param s SBP state
 * @param sender_id SBP sender id
 * @param msg Message to send
 * @param write Write function
 * @param SBP_OK on success, or other libsbp error code
 */
s8 sbp_send_sbp_msg_acq_result_t(struct sbp_state *s, u16 sender_id,
                                 const sbp_msg_acq_result_t *msg,
                                 s32 (*write)(u8 *buff, u32 n, void *context));

/**
 * Compare two instances of sbp_msg_acq_result_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_acq_result_t instance
 * @param b sbp_msg_acq_result_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_msg_acq_result_t(const sbp_msg_acq_result_t *a,
                                 const sbp_msg_acq_result_t *b);

/*
 *
 *
 *
 ******************************************************************************
 *
 * SBP_MSG_ACQ_RESULT_DEP_C
 *
 *****************************************************************************/
/** Deprecated
 *
 * Deprecated.
 */
typedef struct {
  /**
   * CN/0 of best point [dB Hz]
   */
  float cn0;

  /**
   * Code phase of best point [chips]
   */
  float cp;

  /**
   * Carrier frequency of best point [hz]
   */
  float cf;

  /**
   * GNSS signal for which acquisition was attempted
   */
  sbp_gnss_signal_dep_t sid;
} sbp_msg_acq_result_dep_c_t;

/**
 * Get encoded size of an instance of sbp_msg_acq_result_dep_c_t
 *
 * @param msg sbp_msg_acq_result_dep_c_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_msg_acq_result_dep_c_t(
    const sbp_msg_acq_result_dep_c_t *msg);

/**
 * Encode an instance of sbp_msg_acq_result_dep_c_t to wire representation
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
 * @param msg Instance of sbp_msg_acq_result_dep_c_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_msg_acq_result_dep_c_t(uint8_t *buf, uint8_t len,
                                         uint8_t *n_written,
                                         const sbp_msg_acq_result_dep_c_t *msg);

/**
 * Decode an instance of sbp_msg_acq_result_dep_c_t from wire representation
 *
 * This function decodes the wire representation of a sbp_msg_acq_result_dep_c_t
 * message to the given instance. The caller must specify the length of the
 * buffer in the \p len parameter. If non-null the number of bytes read from the
 * buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_msg_acq_result_dep_c_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_msg_acq_result_dep_c_t(const uint8_t *buf, uint8_t len,
                                         uint8_t *n_read,
                                         sbp_msg_acq_result_dep_c_t *msg);
/**
 * Send an instance of sbp_msg_acq_result_dep_c_t with the given write function
 *
 * An equivalent of #sbp_send_message which operates specifically on
 * sbp_msg_acq_result_dep_c_t
 *
 * The given message will be encoded to wire representation and passed in to the
 * given write function callback. The write callback will be called several
 * times for each invocation of this function.
 *
 * @param s SBP state
 * @param sender_id SBP sender id
 * @param msg Message to send
 * @param write Write function
 * @param SBP_OK on success, or other libsbp error code
 */
s8 sbp_send_sbp_msg_acq_result_dep_c_t(struct sbp_state *s, u16 sender_id,
                                       const sbp_msg_acq_result_dep_c_t *msg,
                                       s32 (*write)(u8 *buff, u32 n,
                                                    void *context));

/**
 * Compare two instances of sbp_msg_acq_result_dep_c_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_acq_result_dep_c_t instance
 * @param b sbp_msg_acq_result_dep_c_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_msg_acq_result_dep_c_t(const sbp_msg_acq_result_dep_c_t *a,
                                       const sbp_msg_acq_result_dep_c_t *b);

/*
 *
 *
 *
 ******************************************************************************
 *
 * SBP_MSG_ACQ_RESULT_DEP_B
 *
 *****************************************************************************/
/** Deprecated
 *
 * Deprecated.
 */
typedef struct {
  /**
   * SNR of best point. Currently in arbitrary SNR points, but will be in units
   * of dB Hz in a later revision of this message.
   */
  float snr;

  /**
   * Code phase of best point [chips]
   */
  float cp;

  /**
   * Carrier frequency of best point [hz]
   */
  float cf;

  /**
   * GNSS signal for which acquisition was attempted
   */
  sbp_gnss_signal_dep_t sid;
} sbp_msg_acq_result_dep_b_t;

/**
 * Get encoded size of an instance of sbp_msg_acq_result_dep_b_t
 *
 * @param msg sbp_msg_acq_result_dep_b_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_msg_acq_result_dep_b_t(
    const sbp_msg_acq_result_dep_b_t *msg);

/**
 * Encode an instance of sbp_msg_acq_result_dep_b_t to wire representation
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
 * @param msg Instance of sbp_msg_acq_result_dep_b_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_msg_acq_result_dep_b_t(uint8_t *buf, uint8_t len,
                                         uint8_t *n_written,
                                         const sbp_msg_acq_result_dep_b_t *msg);

/**
 * Decode an instance of sbp_msg_acq_result_dep_b_t from wire representation
 *
 * This function decodes the wire representation of a sbp_msg_acq_result_dep_b_t
 * message to the given instance. The caller must specify the length of the
 * buffer in the \p len parameter. If non-null the number of bytes read from the
 * buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_msg_acq_result_dep_b_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_msg_acq_result_dep_b_t(const uint8_t *buf, uint8_t len,
                                         uint8_t *n_read,
                                         sbp_msg_acq_result_dep_b_t *msg);
/**
 * Send an instance of sbp_msg_acq_result_dep_b_t with the given write function
 *
 * An equivalent of #sbp_send_message which operates specifically on
 * sbp_msg_acq_result_dep_b_t
 *
 * The given message will be encoded to wire representation and passed in to the
 * given write function callback. The write callback will be called several
 * times for each invocation of this function.
 *
 * @param s SBP state
 * @param sender_id SBP sender id
 * @param msg Message to send
 * @param write Write function
 * @param SBP_OK on success, or other libsbp error code
 */
s8 sbp_send_sbp_msg_acq_result_dep_b_t(struct sbp_state *s, u16 sender_id,
                                       const sbp_msg_acq_result_dep_b_t *msg,
                                       s32 (*write)(u8 *buff, u32 n,
                                                    void *context));

/**
 * Compare two instances of sbp_msg_acq_result_dep_b_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_acq_result_dep_b_t instance
 * @param b sbp_msg_acq_result_dep_b_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_msg_acq_result_dep_b_t(const sbp_msg_acq_result_dep_b_t *a,
                                       const sbp_msg_acq_result_dep_b_t *b);

/*
 *
 *
 *
 ******************************************************************************
 *
 * SBP_MSG_ACQ_RESULT_DEP_A
 *
 *****************************************************************************/
/** Deprecated
 *
 * Deprecated.
 */
typedef struct {
  /**
   * SNR of best point. Currently dimensonless, but will have units of dB Hz in
   * the revision of this message.
   */
  float snr;

  /**
   * Code phase of best point [chips]
   */
  float cp;

  /**
   * Carrier frequency of best point [hz]
   */
  float cf;

  /**
   * PRN-1 identifier of the satellite signal for which acquisition was
   * attempted
   */
  u8 prn;
} sbp_msg_acq_result_dep_a_t;

/**
 * Get encoded size of an instance of sbp_msg_acq_result_dep_a_t
 *
 * @param msg sbp_msg_acq_result_dep_a_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_msg_acq_result_dep_a_t(
    const sbp_msg_acq_result_dep_a_t *msg);

/**
 * Encode an instance of sbp_msg_acq_result_dep_a_t to wire representation
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
 * @param msg Instance of sbp_msg_acq_result_dep_a_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_msg_acq_result_dep_a_t(uint8_t *buf, uint8_t len,
                                         uint8_t *n_written,
                                         const sbp_msg_acq_result_dep_a_t *msg);

/**
 * Decode an instance of sbp_msg_acq_result_dep_a_t from wire representation
 *
 * This function decodes the wire representation of a sbp_msg_acq_result_dep_a_t
 * message to the given instance. The caller must specify the length of the
 * buffer in the \p len parameter. If non-null the number of bytes read from the
 * buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_msg_acq_result_dep_a_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_msg_acq_result_dep_a_t(const uint8_t *buf, uint8_t len,
                                         uint8_t *n_read,
                                         sbp_msg_acq_result_dep_a_t *msg);
/**
 * Send an instance of sbp_msg_acq_result_dep_a_t with the given write function
 *
 * An equivalent of #sbp_send_message which operates specifically on
 * sbp_msg_acq_result_dep_a_t
 *
 * The given message will be encoded to wire representation and passed in to the
 * given write function callback. The write callback will be called several
 * times for each invocation of this function.
 *
 * @param s SBP state
 * @param sender_id SBP sender id
 * @param msg Message to send
 * @param write Write function
 * @param SBP_OK on success, or other libsbp error code
 */
s8 sbp_send_sbp_msg_acq_result_dep_a_t(struct sbp_state *s, u16 sender_id,
                                       const sbp_msg_acq_result_dep_a_t *msg,
                                       s32 (*write)(u8 *buff, u32 n,
                                                    void *context));

/**
 * Compare two instances of sbp_msg_acq_result_dep_a_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_acq_result_dep_a_t instance
 * @param b sbp_msg_acq_result_dep_a_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_msg_acq_result_dep_a_t(const sbp_msg_acq_result_dep_a_t *a,
                                       const sbp_msg_acq_result_dep_a_t *b);

/*
 *
 *
 *
 ******************************************************************************
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
  sbp_sbp_gnss_signal_t sid;

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
size_t sbp_packed_size_sbp_acq_sv_profile_t(const sbp_acq_sv_profile_t *msg);

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
s8 sbp_encode_sbp_acq_sv_profile_t(uint8_t *buf, uint8_t len,
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
s8 sbp_decode_sbp_acq_sv_profile_t(const uint8_t *buf, uint8_t len,
                                   uint8_t *n_read, sbp_acq_sv_profile_t *msg);

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
int sbp_cmp_sbp_acq_sv_profile_t(const sbp_acq_sv_profile_t *a,
                                 const sbp_acq_sv_profile_t *b);

/*
 *
 *
 *
 ******************************************************************************
 *
 * SBP_ACQSVPROFILEDEP
 *
 *****************************************************************************/
/** Deprecated
 *
 * Deprecated.
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
  sbp_gnss_signal_dep_t sid;

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
} sbp_acq_sv_profile_dep_t;

/**
 * Get encoded size of an instance of sbp_acq_sv_profile_dep_t
 *
 * @param msg sbp_acq_sv_profile_dep_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_acq_sv_profile_dep_t(
    const sbp_acq_sv_profile_dep_t *msg);

/**
 * Encode an instance of sbp_acq_sv_profile_dep_t to wire representation
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
 * @param msg Instance of sbp_acq_sv_profile_dep_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_acq_sv_profile_dep_t(uint8_t *buf, uint8_t len,
                                       uint8_t *n_written,
                                       const sbp_acq_sv_profile_dep_t *msg);

/**
 * Decode an instance of sbp_acq_sv_profile_dep_t from wire representation
 *
 * This function decodes the wire representation of a sbp_acq_sv_profile_dep_t
 * message to the given instance. The caller must specify the length of the
 * buffer in the \p len parameter. If non-null the number of bytes read from the
 * buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_acq_sv_profile_dep_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_acq_sv_profile_dep_t(const uint8_t *buf, uint8_t len,
                                       uint8_t *n_read,
                                       sbp_acq_sv_profile_dep_t *msg);

/**
 * Compare two instances of sbp_acq_sv_profile_dep_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_acq_sv_profile_dep_t instance
 * @param b sbp_acq_sv_profile_dep_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_acq_sv_profile_dep_t(const sbp_acq_sv_profile_dep_t *a,
                                     const sbp_acq_sv_profile_dep_t *b);

/*
 *
 *
 *
 ******************************************************************************
 *
 * SBP_MSG_ACQ_SV_PROFILE
 *
 *****************************************************************************/
/** Acquisition perfomance measurement and debug
 *
 * The message describes all SV profiles during acquisition time. The message is
 * used to debug and measure the performance.
 */
typedef struct {
  /**
   * SV profiles during acquisition time
   */
  sbp_acq_sv_profile_t acq_sv_profile[7];
  /**
   * Number of elements in acq_sv_profile
   *
   * When sending a message fill in this field with the number elements set in
   * acq_sv_profile before calling an appropriate libsbp send function
   *
   * When receiving a message query this field for the number of elements in
   * acq_sv_profile. The value of any elements beyond the index specified in
   * this field is undefined
   */
  u8 n_acq_sv_profile;
} sbp_msg_acq_sv_profile_t;

/**
 * Get encoded size of an instance of sbp_msg_acq_sv_profile_t
 *
 * @param msg sbp_msg_acq_sv_profile_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_msg_acq_sv_profile_t(
    const sbp_msg_acq_sv_profile_t *msg);

/**
 * Encode an instance of sbp_msg_acq_sv_profile_t to wire representation
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
 * @param msg Instance of sbp_msg_acq_sv_profile_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_msg_acq_sv_profile_t(uint8_t *buf, uint8_t len,
                                       uint8_t *n_written,
                                       const sbp_msg_acq_sv_profile_t *msg);

/**
 * Decode an instance of sbp_msg_acq_sv_profile_t from wire representation
 *
 * This function decodes the wire representation of a sbp_msg_acq_sv_profile_t
 * message to the given instance. The caller must specify the length of the
 * buffer in the \p len parameter. If non-null the number of bytes read from the
 * buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_msg_acq_sv_profile_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_msg_acq_sv_profile_t(const uint8_t *buf, uint8_t len,
                                       uint8_t *n_read,
                                       sbp_msg_acq_sv_profile_t *msg);
/**
 * Send an instance of sbp_msg_acq_sv_profile_t with the given write function
 *
 * An equivalent of #sbp_send_message which operates specifically on
 * sbp_msg_acq_sv_profile_t
 *
 * The given message will be encoded to wire representation and passed in to the
 * given write function callback. The write callback will be called several
 * times for each invocation of this function.
 *
 * @param s SBP state
 * @param sender_id SBP sender id
 * @param msg Message to send
 * @param write Write function
 * @param SBP_OK on success, or other libsbp error code
 */
s8 sbp_send_sbp_msg_acq_sv_profile_t(struct sbp_state *s, u16 sender_id,
                                     const sbp_msg_acq_sv_profile_t *msg,
                                     s32 (*write)(u8 *buff, u32 n,
                                                  void *context));

/**
 * Compare two instances of sbp_msg_acq_sv_profile_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_acq_sv_profile_t instance
 * @param b sbp_msg_acq_sv_profile_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_msg_acq_sv_profile_t(const sbp_msg_acq_sv_profile_t *a,
                                     const sbp_msg_acq_sv_profile_t *b);

/*
 *
 *
 *
 ******************************************************************************
 *
 * SBP_MSG_ACQ_SV_PROFILE_DEP
 *
 *****************************************************************************/
/** Deprecated
 *
 * Deprecated.
 */
typedef struct {
  /**
   * SV profiles during acquisition time
   */
  sbp_acq_sv_profile_dep_t acq_sv_profile[7];
  /**
   * Number of elements in acq_sv_profile
   *
   * When sending a message fill in this field with the number elements set in
   * acq_sv_profile before calling an appropriate libsbp send function
   *
   * When receiving a message query this field for the number of elements in
   * acq_sv_profile. The value of any elements beyond the index specified in
   * this field is undefined
   */
  u8 n_acq_sv_profile;
} sbp_msg_acq_sv_profile_dep_t;

/**
 * Get encoded size of an instance of sbp_msg_acq_sv_profile_dep_t
 *
 * @param msg sbp_msg_acq_sv_profile_dep_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_msg_acq_sv_profile_dep_t(
    const sbp_msg_acq_sv_profile_dep_t *msg);

/**
 * Encode an instance of sbp_msg_acq_sv_profile_dep_t to wire representation
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
 * @param msg Instance of sbp_msg_acq_sv_profile_dep_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_msg_acq_sv_profile_dep_t(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_msg_acq_sv_profile_dep_t *msg);

/**
 * Decode an instance of sbp_msg_acq_sv_profile_dep_t from wire representation
 *
 * This function decodes the wire representation of a
 * sbp_msg_acq_sv_profile_dep_t message to the given instance. The caller must
 * specify the length of the buffer in the \p len parameter. If non-null the
 * number of bytes read from the buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_msg_acq_sv_profile_dep_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_msg_acq_sv_profile_dep_t(const uint8_t *buf, uint8_t len,
                                           uint8_t *n_read,
                                           sbp_msg_acq_sv_profile_dep_t *msg);
/**
 * Send an instance of sbp_msg_acq_sv_profile_dep_t with the given write
 * function
 *
 * An equivalent of #sbp_send_message which operates specifically on
 * sbp_msg_acq_sv_profile_dep_t
 *
 * The given message will be encoded to wire representation and passed in to the
 * given write function callback. The write callback will be called several
 * times for each invocation of this function.
 *
 * @param s SBP state
 * @param sender_id SBP sender id
 * @param msg Message to send
 * @param write Write function
 * @param SBP_OK on success, or other libsbp error code
 */
s8 sbp_send_sbp_msg_acq_sv_profile_dep_t(
    struct sbp_state *s, u16 sender_id, const sbp_msg_acq_sv_profile_dep_t *msg,
    s32 (*write)(u8 *buff, u32 n, void *context));

/**
 * Compare two instances of sbp_msg_acq_sv_profile_dep_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_acq_sv_profile_dep_t instance
 * @param b sbp_msg_acq_sv_profile_dep_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_msg_acq_sv_profile_dep_t(const sbp_msg_acq_sv_profile_dep_t *a,
                                         const sbp_msg_acq_sv_profile_dep_t *b);

#ifdef __cplusplus
}
static inline bool operator==(const sbp_msg_acq_result_t &lhs,
                              const sbp_msg_acq_result_t &rhs) {
  return sbp_cmp_sbp_msg_acq_result_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_msg_acq_result_t &lhs,
                              const sbp_msg_acq_result_t &rhs) {
  return sbp_cmp_sbp_msg_acq_result_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_acq_result_t &lhs,
                             const sbp_msg_acq_result_t &rhs) {
  return sbp_cmp_sbp_msg_acq_result_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_msg_acq_result_t &lhs,
                              const sbp_msg_acq_result_t &rhs) {
  return sbp_cmp_sbp_msg_acq_result_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_acq_result_t &lhs,
                             const sbp_msg_acq_result_t &rhs) {
  return sbp_cmp_sbp_msg_acq_result_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_msg_acq_result_t &lhs,
                              const sbp_msg_acq_result_t &rhs) {
  return sbp_cmp_sbp_msg_acq_result_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_msg_acq_result_dep_c_t &lhs,
                              const sbp_msg_acq_result_dep_c_t &rhs) {
  return sbp_cmp_sbp_msg_acq_result_dep_c_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_msg_acq_result_dep_c_t &lhs,
                              const sbp_msg_acq_result_dep_c_t &rhs) {
  return sbp_cmp_sbp_msg_acq_result_dep_c_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_acq_result_dep_c_t &lhs,
                             const sbp_msg_acq_result_dep_c_t &rhs) {
  return sbp_cmp_sbp_msg_acq_result_dep_c_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_msg_acq_result_dep_c_t &lhs,
                              const sbp_msg_acq_result_dep_c_t &rhs) {
  return sbp_cmp_sbp_msg_acq_result_dep_c_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_acq_result_dep_c_t &lhs,
                             const sbp_msg_acq_result_dep_c_t &rhs) {
  return sbp_cmp_sbp_msg_acq_result_dep_c_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_msg_acq_result_dep_c_t &lhs,
                              const sbp_msg_acq_result_dep_c_t &rhs) {
  return sbp_cmp_sbp_msg_acq_result_dep_c_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_msg_acq_result_dep_b_t &lhs,
                              const sbp_msg_acq_result_dep_b_t &rhs) {
  return sbp_cmp_sbp_msg_acq_result_dep_b_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_msg_acq_result_dep_b_t &lhs,
                              const sbp_msg_acq_result_dep_b_t &rhs) {
  return sbp_cmp_sbp_msg_acq_result_dep_b_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_acq_result_dep_b_t &lhs,
                             const sbp_msg_acq_result_dep_b_t &rhs) {
  return sbp_cmp_sbp_msg_acq_result_dep_b_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_msg_acq_result_dep_b_t &lhs,
                              const sbp_msg_acq_result_dep_b_t &rhs) {
  return sbp_cmp_sbp_msg_acq_result_dep_b_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_acq_result_dep_b_t &lhs,
                             const sbp_msg_acq_result_dep_b_t &rhs) {
  return sbp_cmp_sbp_msg_acq_result_dep_b_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_msg_acq_result_dep_b_t &lhs,
                              const sbp_msg_acq_result_dep_b_t &rhs) {
  return sbp_cmp_sbp_msg_acq_result_dep_b_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_msg_acq_result_dep_a_t &lhs,
                              const sbp_msg_acq_result_dep_a_t &rhs) {
  return sbp_cmp_sbp_msg_acq_result_dep_a_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_msg_acq_result_dep_a_t &lhs,
                              const sbp_msg_acq_result_dep_a_t &rhs) {
  return sbp_cmp_sbp_msg_acq_result_dep_a_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_acq_result_dep_a_t &lhs,
                             const sbp_msg_acq_result_dep_a_t &rhs) {
  return sbp_cmp_sbp_msg_acq_result_dep_a_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_msg_acq_result_dep_a_t &lhs,
                              const sbp_msg_acq_result_dep_a_t &rhs) {
  return sbp_cmp_sbp_msg_acq_result_dep_a_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_acq_result_dep_a_t &lhs,
                             const sbp_msg_acq_result_dep_a_t &rhs) {
  return sbp_cmp_sbp_msg_acq_result_dep_a_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_msg_acq_result_dep_a_t &lhs,
                              const sbp_msg_acq_result_dep_a_t &rhs) {
  return sbp_cmp_sbp_msg_acq_result_dep_a_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_acq_sv_profile_t &lhs,
                              const sbp_acq_sv_profile_t &rhs) {
  return sbp_cmp_sbp_acq_sv_profile_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_acq_sv_profile_t &lhs,
                              const sbp_acq_sv_profile_t &rhs) {
  return sbp_cmp_sbp_acq_sv_profile_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_acq_sv_profile_t &lhs,
                             const sbp_acq_sv_profile_t &rhs) {
  return sbp_cmp_sbp_acq_sv_profile_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_acq_sv_profile_t &lhs,
                              const sbp_acq_sv_profile_t &rhs) {
  return sbp_cmp_sbp_acq_sv_profile_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_acq_sv_profile_t &lhs,
                             const sbp_acq_sv_profile_t &rhs) {
  return sbp_cmp_sbp_acq_sv_profile_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_acq_sv_profile_t &lhs,
                              const sbp_acq_sv_profile_t &rhs) {
  return sbp_cmp_sbp_acq_sv_profile_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_acq_sv_profile_dep_t &lhs,
                              const sbp_acq_sv_profile_dep_t &rhs) {
  return sbp_cmp_sbp_acq_sv_profile_dep_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_acq_sv_profile_dep_t &lhs,
                              const sbp_acq_sv_profile_dep_t &rhs) {
  return sbp_cmp_sbp_acq_sv_profile_dep_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_acq_sv_profile_dep_t &lhs,
                             const sbp_acq_sv_profile_dep_t &rhs) {
  return sbp_cmp_sbp_acq_sv_profile_dep_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_acq_sv_profile_dep_t &lhs,
                              const sbp_acq_sv_profile_dep_t &rhs) {
  return sbp_cmp_sbp_acq_sv_profile_dep_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_acq_sv_profile_dep_t &lhs,
                             const sbp_acq_sv_profile_dep_t &rhs) {
  return sbp_cmp_sbp_acq_sv_profile_dep_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_acq_sv_profile_dep_t &lhs,
                              const sbp_acq_sv_profile_dep_t &rhs) {
  return sbp_cmp_sbp_acq_sv_profile_dep_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_msg_acq_sv_profile_t &lhs,
                              const sbp_msg_acq_sv_profile_t &rhs) {
  return sbp_cmp_sbp_msg_acq_sv_profile_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_msg_acq_sv_profile_t &lhs,
                              const sbp_msg_acq_sv_profile_t &rhs) {
  return sbp_cmp_sbp_msg_acq_sv_profile_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_acq_sv_profile_t &lhs,
                             const sbp_msg_acq_sv_profile_t &rhs) {
  return sbp_cmp_sbp_msg_acq_sv_profile_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_msg_acq_sv_profile_t &lhs,
                              const sbp_msg_acq_sv_profile_t &rhs) {
  return sbp_cmp_sbp_msg_acq_sv_profile_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_acq_sv_profile_t &lhs,
                             const sbp_msg_acq_sv_profile_t &rhs) {
  return sbp_cmp_sbp_msg_acq_sv_profile_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_msg_acq_sv_profile_t &lhs,
                              const sbp_msg_acq_sv_profile_t &rhs) {
  return sbp_cmp_sbp_msg_acq_sv_profile_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_msg_acq_sv_profile_dep_t &lhs,
                              const sbp_msg_acq_sv_profile_dep_t &rhs) {
  return sbp_cmp_sbp_msg_acq_sv_profile_dep_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_msg_acq_sv_profile_dep_t &lhs,
                              const sbp_msg_acq_sv_profile_dep_t &rhs) {
  return sbp_cmp_sbp_msg_acq_sv_profile_dep_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_acq_sv_profile_dep_t &lhs,
                             const sbp_msg_acq_sv_profile_dep_t &rhs) {
  return sbp_cmp_sbp_msg_acq_sv_profile_dep_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_msg_acq_sv_profile_dep_t &lhs,
                              const sbp_msg_acq_sv_profile_dep_t &rhs) {
  return sbp_cmp_sbp_msg_acq_sv_profile_dep_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_acq_sv_profile_dep_t &lhs,
                             const sbp_msg_acq_sv_profile_dep_t &rhs) {
  return sbp_cmp_sbp_msg_acq_sv_profile_dep_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_msg_acq_sv_profile_dep_t &lhs,
                              const sbp_msg_acq_sv_profile_dep_t &rhs) {
  return sbp_cmp_sbp_msg_acq_sv_profile_dep_t(&lhs, &rhs) >= 0;
}

#endif

#endif /* LIBSBP_NEW_ACQUISITION_MESSAGES_H */
