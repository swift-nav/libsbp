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
 * Automatically generated from yaml/swiftnav/sbp/observation.yaml
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

#ifndef LIBSBP_NEW_OBSERVATION_MESSAGES_H
#define LIBSBP_NEW_OBSERVATION_MESSAGES_H

#include <endian.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>

#include <libsbp/common.h>
#include <libsbp/new/gnss.h>
#include <libsbp/new/string/double_null_terminated.h>
#include <libsbp/new/string/multipart.h>
#include <libsbp/new/string/null_terminated.h>
#include <libsbp/new/string/unterminated.h>
#include <libsbp/observation_macros.h>

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
 * SBP_OBSERVATIONHEADER
 *
 *****************************************************************************/
/** Header for observation message
 *
 * Header of a GNSS observation message.
 */
typedef struct {
  /**
   * GNSS time of this observation
   */
  sbp_sbp_gps_time_t t;

  /**
   * Total number of observations. First nibble is the size of the sequence (n),
   * second nibble is the zero-indexed counter (ith packet of n)
   */
  u8 n_obs;
} sbp_observation_header_t;

/**
 * Get encoded size of an instance of sbp_observation_header_t
 *
 * @param msg sbp_observation_header_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_observation_header_t(
    const sbp_observation_header_t *msg);

/**
 * Encode an instance of sbp_observation_header_t to wire representation
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
 * @param msg Instance of sbp_observation_header_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_observation_header_t(uint8_t *buf, uint8_t len,
                                       uint8_t *n_written,
                                       const sbp_observation_header_t *msg);

/**
 * Decode an instance of sbp_observation_header_t from wire representation
 *
 * This function decodes the wire representation of a sbp_observation_header_t
 * message to the given instance. The caller must specify the length of the
 * buffer in the \p len parameter. If non-null the number of bytes read from the
 * buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_observation_header_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_observation_header_t(const uint8_t *buf, uint8_t len,
                                       uint8_t *n_read,
                                       sbp_observation_header_t *msg);

/**
 * Compare two instances of sbp_observation_header_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_observation_header_t instance
 * @param b sbp_observation_header_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_observation_header_t(const sbp_observation_header_t *a,
                                     const sbp_observation_header_t *b);

/*
 *
 *
 *
 ******************************************************************************
 *
 * SBP_DOPPLER
 *
 *****************************************************************************/
/** GNSS doppler measurement
 *
 * Doppler measurement in Hz represented as a 24-bit fixed point number with
 * Q16.8 layout, i.e. 16-bits of whole doppler and 8-bits of fractional doppler.
 * This doppler is defined as positive for approaching satellites.
 */
typedef struct {
  /**
   * Doppler whole Hz [Hz]
   */
  s16 i;

  /**
   * Doppler fractional part [Hz / 256]
   */
  u8 f;
} sbp_doppler_t;

/**
 * Get encoded size of an instance of sbp_doppler_t
 *
 * @param msg sbp_doppler_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_doppler_t(const sbp_doppler_t *msg);

/**
 * Encode an instance of sbp_doppler_t to wire representation
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
 * @param msg Instance of sbp_doppler_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_doppler_t(uint8_t *buf, uint8_t len, uint8_t *n_written,
                            const sbp_doppler_t *msg);

/**
 * Decode an instance of sbp_doppler_t from wire representation
 *
 * This function decodes the wire representation of a sbp_doppler_t message to
 * the given instance. The caller must specify the length of the buffer in the
 * \p len parameter. If non-null the number of bytes read from the buffer will
 * be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_doppler_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_doppler_t(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                            sbp_doppler_t *msg);

/**
 * Compare two instances of sbp_doppler_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_doppler_t instance
 * @param b sbp_doppler_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_doppler_t(const sbp_doppler_t *a, const sbp_doppler_t *b);

/*
 *
 *
 *
 ******************************************************************************
 *
 * SBP_PACKEDOBSCONTENT
 *
 *****************************************************************************/
/** GNSS observations for a particular satellite signal
 *
 * Pseudorange and carrier phase observation for a satellite being tracked. The
 * observations are interoperable with 3rd party receivers and conform with
 * typical RTCM 3.1 message GPS/GLO observations.
 *
 */
typedef struct {
  /**
   * Pseudorange observation [2 cm]
   */
  u32 P;

  /**
   * Carrier phase observation with typical sign convention. [cycles]
   */
  sbp_carrier_phase_t L;

  /**
   * Doppler observation with typical sign convention. [Hz]
   */
  sbp_doppler_t D;

  /**
   * Carrier-to-Noise density.  Zero implies invalid cn0. [dB Hz / 4]
   */
  u8 cn0;

  /**
   * Lock timer. This value gives an indication of the time for which a signal
   * has maintained continuous phase lock. Whenever a signal has lost and
   * regained lock, this value is reset to zero. It is encoded according to
   * DF402 from the RTCM 10403.2 Amendment 2 specification.  Valid values range
   * from 0 to 15 and the most significant nibble is reserved for future use.
   */
  u8 lock;

  /**
   * Measurement status flags. A bit field of flags providing the status of this
   * observation.  If this field is 0 it means only the Cn0 estimate for the
   * signal is valid.
   */
  u8 flags;

  /**
   * GNSS signal identifier (16 bit)
   */
  sbp_sbp_gnss_signal_t sid;
} sbp_packed_obs_content_t;

/**
 * Get encoded size of an instance of sbp_packed_obs_content_t
 *
 * @param msg sbp_packed_obs_content_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_packed_obs_content_t(
    const sbp_packed_obs_content_t *msg);

/**
 * Encode an instance of sbp_packed_obs_content_t to wire representation
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
 * @param msg Instance of sbp_packed_obs_content_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_packed_obs_content_t(uint8_t *buf, uint8_t len,
                                       uint8_t *n_written,
                                       const sbp_packed_obs_content_t *msg);

/**
 * Decode an instance of sbp_packed_obs_content_t from wire representation
 *
 * This function decodes the wire representation of a sbp_packed_obs_content_t
 * message to the given instance. The caller must specify the length of the
 * buffer in the \p len parameter. If non-null the number of bytes read from the
 * buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_packed_obs_content_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_packed_obs_content_t(const uint8_t *buf, uint8_t len,
                                       uint8_t *n_read,
                                       sbp_packed_obs_content_t *msg);

/**
 * Compare two instances of sbp_packed_obs_content_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_packed_obs_content_t instance
 * @param b sbp_packed_obs_content_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_packed_obs_content_t(const sbp_packed_obs_content_t *a,
                                     const sbp_packed_obs_content_t *b);

/*
 *
 *
 *
 ******************************************************************************
 *
 * SBP_PACKEDOSRCONTENT
 *
 *****************************************************************************/
/** Network correction for a particular satellite signal
 *
 * Pseudorange and carrier phase network corrections for a satellite signal.
 */
typedef struct {
  /**
   * Pseudorange observation [2 cm]
   */
  u32 P;

  /**
   * Carrier phase observation with typical sign convention. [cycles]
   */
  sbp_carrier_phase_t L;

  /**
   * Lock timer. This value gives an indication of the time for which a signal
   * has maintained continuous phase lock. Whenever a signal has lost and
   * regained lock, this value is reset to zero. It is encoded according to
   * DF402 from the RTCM 10403.2 Amendment 2 specification.  Valid values range
   * from 0 to 15 and the most significant nibble is reserved for future use.
   */
  u8 lock;

  /**
   * Correction flags.
   */
  u8 flags;

  /**
   * GNSS signal identifier (16 bit)
   */
  sbp_sbp_gnss_signal_t sid;

  /**
   * Slant ionospheric correction standard deviation [5 mm]
   */
  u16 iono_std;

  /**
   * Slant tropospheric correction standard deviation [5 mm]
   */
  u16 tropo_std;

  /**
   * Orbit/clock/bias correction projected on range standard deviation [5 mm]
   */
  u16 range_std;
} sbp_packed_osr_content_t;

/**
 * Get encoded size of an instance of sbp_packed_osr_content_t
 *
 * @param msg sbp_packed_osr_content_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_packed_osr_content_t(
    const sbp_packed_osr_content_t *msg);

/**
 * Encode an instance of sbp_packed_osr_content_t to wire representation
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
 * @param msg Instance of sbp_packed_osr_content_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_packed_osr_content_t(uint8_t *buf, uint8_t len,
                                       uint8_t *n_written,
                                       const sbp_packed_osr_content_t *msg);

/**
 * Decode an instance of sbp_packed_osr_content_t from wire representation
 *
 * This function decodes the wire representation of a sbp_packed_osr_content_t
 * message to the given instance. The caller must specify the length of the
 * buffer in the \p len parameter. If non-null the number of bytes read from the
 * buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_packed_osr_content_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_packed_osr_content_t(const uint8_t *buf, uint8_t len,
                                       uint8_t *n_read,
                                       sbp_packed_osr_content_t *msg);

/**
 * Compare two instances of sbp_packed_osr_content_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_packed_osr_content_t instance
 * @param b sbp_packed_osr_content_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_packed_osr_content_t(const sbp_packed_osr_content_t *a,
                                     const sbp_packed_osr_content_t *b);

/*
 *
 *
 *
 ******************************************************************************
 *
 * SBP_MSG_OBS
 *
 *****************************************************************************/
/** GPS satellite observations
 *
 * The GPS observations message reports all the raw pseudorange and carrier
 * phase observations for the satellites being tracked by the device. Carrier
 * phase observation here is represented as a 40-bit fixed point number with
 * Q32.8 layout (i.e. 32-bits of whole cycles and 8-bits of fractional cycles).
 * The observations are be interoperable with 3rd party receivers and conform
 * with typical RTCMv3 GNSS observations.
 */
typedef struct {
  /**
   * Header of a GPS observation message
   */
  sbp_observation_header_t header;

  /**
   * Pseudorange and carrier phase observation for a satellite being tracked.
   */
  sbp_packed_obs_content_t obs[14];
  /**
   * Number of elements in obs
   *
   * When sending a message fill in this field with the number elements set in
   * obs before calling an appropriate libsbp send function
   *
   * When receiving a message query this field for the number of elements in
   * obs. The value of any elements beyond the index specified in this field is
   * undefined
   */
  u8 n_obs;
} sbp_msg_obs_t;

/**
 * Get encoded size of an instance of sbp_msg_obs_t
 *
 * @param msg sbp_msg_obs_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_msg_obs_t(const sbp_msg_obs_t *msg);

/**
 * Encode an instance of sbp_msg_obs_t to wire representation
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
 * @param msg Instance of sbp_msg_obs_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_msg_obs_t(uint8_t *buf, uint8_t len, uint8_t *n_written,
                            const sbp_msg_obs_t *msg);

/**
 * Decode an instance of sbp_msg_obs_t from wire representation
 *
 * This function decodes the wire representation of a sbp_msg_obs_t message to
 * the given instance. The caller must specify the length of the buffer in the
 * \p len parameter. If non-null the number of bytes read from the buffer will
 * be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_msg_obs_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_msg_obs_t(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                            sbp_msg_obs_t *msg);
/**
 * Send an instance of sbp_msg_obs_t with the given write function
 *
 * An equivalent of #sbp_send_message which operates specifically on
 * sbp_msg_obs_t
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
s8 sbp_send_sbp_msg_obs_t(struct sbp_state *s, u16 sender_id,
                          const sbp_msg_obs_t *msg,
                          s32 (*write)(u8 *buff, u32 n, void *context));

/**
 * Compare two instances of sbp_msg_obs_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_obs_t instance
 * @param b sbp_msg_obs_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_msg_obs_t(const sbp_msg_obs_t *a, const sbp_msg_obs_t *b);

/*
 *
 *
 *
 ******************************************************************************
 *
 * SBP_MSG_BASE_POS_LLH
 *
 *****************************************************************************/
/** Base station position
 *
 * The base station position message is the position reported by the base
 * station itself. It is used for pseudo-absolute RTK positioning, and is
 * required to be a high-accuracy surveyed location of the base station. Any
 * error here will result in an error in the pseudo-absolute position output.
 */
typedef struct {
  /**
   * Latitude [deg]
   */
  double lat;

  /**
   * Longitude [deg]
   */
  double lon;

  /**
   * Height [m]
   */
  double height;
} sbp_msg_base_pos_llh_t;

/**
 * Get encoded size of an instance of sbp_msg_base_pos_llh_t
 *
 * @param msg sbp_msg_base_pos_llh_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_msg_base_pos_llh_t(
    const sbp_msg_base_pos_llh_t *msg);

/**
 * Encode an instance of sbp_msg_base_pos_llh_t to wire representation
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
 * @param msg Instance of sbp_msg_base_pos_llh_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_msg_base_pos_llh_t(uint8_t *buf, uint8_t len,
                                     uint8_t *n_written,
                                     const sbp_msg_base_pos_llh_t *msg);

/**
 * Decode an instance of sbp_msg_base_pos_llh_t from wire representation
 *
 * This function decodes the wire representation of a sbp_msg_base_pos_llh_t
 * message to the given instance. The caller must specify the length of the
 * buffer in the \p len parameter. If non-null the number of bytes read from the
 * buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_msg_base_pos_llh_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_msg_base_pos_llh_t(const uint8_t *buf, uint8_t len,
                                     uint8_t *n_read,
                                     sbp_msg_base_pos_llh_t *msg);
/**
 * Send an instance of sbp_msg_base_pos_llh_t with the given write function
 *
 * An equivalent of #sbp_send_message which operates specifically on
 * sbp_msg_base_pos_llh_t
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
s8 sbp_send_sbp_msg_base_pos_llh_t(struct sbp_state *s, u16 sender_id,
                                   const sbp_msg_base_pos_llh_t *msg,
                                   s32 (*write)(u8 *buff, u32 n,
                                                void *context));

/**
 * Compare two instances of sbp_msg_base_pos_llh_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_base_pos_llh_t instance
 * @param b sbp_msg_base_pos_llh_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_msg_base_pos_llh_t(const sbp_msg_base_pos_llh_t *a,
                                   const sbp_msg_base_pos_llh_t *b);

/*
 *
 *
 *
 ******************************************************************************
 *
 * SBP_MSG_BASE_POS_ECEF
 *
 *****************************************************************************/
/** Base station position in ECEF
 *
 * The base station position message is the position reported by the base
 * station itself in absolute Earth Centered Earth Fixed coordinates. It is used
 * for pseudo-absolute RTK positioning, and is required to be a high-accuracy
 * surveyed location of the base station. Any error here will result in an error
 * in the pseudo-absolute position output.
 */
typedef struct {
  /**
   * ECEF X coodinate [m]
   */
  double x;

  /**
   * ECEF Y coordinate [m]
   */
  double y;

  /**
   * ECEF Z coordinate [m]
   */
  double z;
} sbp_msg_base_pos_ecef_t;

/**
 * Get encoded size of an instance of sbp_msg_base_pos_ecef_t
 *
 * @param msg sbp_msg_base_pos_ecef_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_msg_base_pos_ecef_t(
    const sbp_msg_base_pos_ecef_t *msg);

/**
 * Encode an instance of sbp_msg_base_pos_ecef_t to wire representation
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
 * @param msg Instance of sbp_msg_base_pos_ecef_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_msg_base_pos_ecef_t(uint8_t *buf, uint8_t len,
                                      uint8_t *n_written,
                                      const sbp_msg_base_pos_ecef_t *msg);

/**
 * Decode an instance of sbp_msg_base_pos_ecef_t from wire representation
 *
 * This function decodes the wire representation of a sbp_msg_base_pos_ecef_t
 * message to the given instance. The caller must specify the length of the
 * buffer in the \p len parameter. If non-null the number of bytes read from the
 * buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_msg_base_pos_ecef_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_msg_base_pos_ecef_t(const uint8_t *buf, uint8_t len,
                                      uint8_t *n_read,
                                      sbp_msg_base_pos_ecef_t *msg);
/**
 * Send an instance of sbp_msg_base_pos_ecef_t with the given write function
 *
 * An equivalent of #sbp_send_message which operates specifically on
 * sbp_msg_base_pos_ecef_t
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
s8 sbp_send_sbp_msg_base_pos_ecef_t(struct sbp_state *s, u16 sender_id,
                                    const sbp_msg_base_pos_ecef_t *msg,
                                    s32 (*write)(u8 *buff, u32 n,
                                                 void *context));

/**
 * Compare two instances of sbp_msg_base_pos_ecef_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_base_pos_ecef_t instance
 * @param b sbp_msg_base_pos_ecef_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_msg_base_pos_ecef_t(const sbp_msg_base_pos_ecef_t *a,
                                    const sbp_msg_base_pos_ecef_t *b);

/*
 *
 *
 *
 ******************************************************************************
 *
 * SBP_EPHEMERISCOMMONCONTENT
 *
 *****************************************************************************/
typedef struct {
  /**
   * GNSS signal identifier (16 bit)
   */
  sbp_sbp_gnss_signal_t sid;

  /**
   * Time of Ephemerides
   */
  sbp_gps_time_sec_t toe;

  /**
   * User Range Accuracy [m]
   */
  float ura;

  /**
   * Curve fit interval [s]
   */
  u32 fit_interval;

  /**
   * Status of ephemeris, 1 = valid, 0 = invalid
   */
  u8 valid;

  /**
   * Satellite health status.
   * GPS: ICD-GPS-200, chapter 20.3.3.3.1.4
   * SBAS: 0 = valid, non-zero = invalid
   * GLO: 0 = valid, non-zero = invalid
   */
  u8 health_bits;
} sbp_ephemeris_common_content_t;

/**
 * Get encoded size of an instance of sbp_ephemeris_common_content_t
 *
 * @param msg sbp_ephemeris_common_content_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_ephemeris_common_content_t(
    const sbp_ephemeris_common_content_t *msg);

/**
 * Encode an instance of sbp_ephemeris_common_content_t to wire representation
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
 * @param msg Instance of sbp_ephemeris_common_content_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_ephemeris_common_content_t(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_ephemeris_common_content_t *msg);

/**
 * Decode an instance of sbp_ephemeris_common_content_t from wire representation
 *
 * This function decodes the wire representation of a
 * sbp_ephemeris_common_content_t message to the given instance. The caller must
 * specify the length of the buffer in the \p len parameter. If non-null the
 * number of bytes read from the buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_ephemeris_common_content_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_ephemeris_common_content_t(
    const uint8_t *buf, uint8_t len, uint8_t *n_read,
    sbp_ephemeris_common_content_t *msg);

/**
 * Compare two instances of sbp_ephemeris_common_content_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_ephemeris_common_content_t instance
 * @param b sbp_ephemeris_common_content_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_ephemeris_common_content_t(
    const sbp_ephemeris_common_content_t *a,
    const sbp_ephemeris_common_content_t *b);

/*
 *
 *
 *
 ******************************************************************************
 *
 * SBP_EPHEMERISCOMMONCONTENTDEPB
 *
 *****************************************************************************/
typedef struct {
  /**
   * GNSS signal identifier (16 bit)
   */
  sbp_sbp_gnss_signal_t sid;

  /**
   * Time of Ephemerides
   */
  sbp_gps_time_sec_t toe;

  /**
   * User Range Accuracy [m]
   */
  double ura;

  /**
   * Curve fit interval [s]
   */
  u32 fit_interval;

  /**
   * Status of ephemeris, 1 = valid, 0 = invalid
   */
  u8 valid;

  /**
   * Satellite health status.
   * GPS: ICD-GPS-200, chapter 20.3.3.3.1.4
   * Others: 0 = valid, non-zero = invalid
   */
  u8 health_bits;
} sbp_ephemeris_common_content_dep_b_t;

/**
 * Get encoded size of an instance of sbp_ephemeris_common_content_dep_b_t
 *
 * @param msg sbp_ephemeris_common_content_dep_b_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_ephemeris_common_content_dep_b_t(
    const sbp_ephemeris_common_content_dep_b_t *msg);

/**
 * Encode an instance of sbp_ephemeris_common_content_dep_b_t to wire
 * representation
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
 * @param msg Instance of sbp_ephemeris_common_content_dep_b_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_ephemeris_common_content_dep_b_t(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_ephemeris_common_content_dep_b_t *msg);

/**
 * Decode an instance of sbp_ephemeris_common_content_dep_b_t from wire
 * representation
 *
 * This function decodes the wire representation of a
 * sbp_ephemeris_common_content_dep_b_t message to the given instance. The
 * caller must specify the length of the buffer in the \p len parameter. If
 * non-null the number of bytes read from the buffer will be returned in \p
 * n_read.
 *
 * @param buf Wire representation of the sbp_ephemeris_common_content_dep_b_t
 * instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_ephemeris_common_content_dep_b_t(
    const uint8_t *buf, uint8_t len, uint8_t *n_read,
    sbp_ephemeris_common_content_dep_b_t *msg);

/**
 * Compare two instances of sbp_ephemeris_common_content_dep_b_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_ephemeris_common_content_dep_b_t instance
 * @param b sbp_ephemeris_common_content_dep_b_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_ephemeris_common_content_dep_b_t(
    const sbp_ephemeris_common_content_dep_b_t *a,
    const sbp_ephemeris_common_content_dep_b_t *b);

/*
 *
 *
 *
 ******************************************************************************
 *
 * SBP_EPHEMERISCOMMONCONTENTDEPA
 *
 *****************************************************************************/
typedef struct {
  /**
   * GNSS signal identifier
   */
  sbp_gnss_signal_dep_t sid;

  /**
   * Time of Ephemerides
   */
  sbp_gps_time_dep_t toe;

  /**
   * User Range Accuracy [m]
   */
  double ura;

  /**
   * Curve fit interval [s]
   */
  u32 fit_interval;

  /**
   * Status of ephemeris, 1 = valid, 0 = invalid
   */
  u8 valid;

  /**
   * Satellite health status.
   * GPS: ICD-GPS-200, chapter 20.3.3.3.1.4
   * SBAS: 0 = valid, non-zero = invalid
   * GLO: 0 = valid, non-zero = invalid
   */
  u8 health_bits;
} sbp_ephemeris_common_content_dep_a_t;

/**
 * Get encoded size of an instance of sbp_ephemeris_common_content_dep_a_t
 *
 * @param msg sbp_ephemeris_common_content_dep_a_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_ephemeris_common_content_dep_a_t(
    const sbp_ephemeris_common_content_dep_a_t *msg);

/**
 * Encode an instance of sbp_ephemeris_common_content_dep_a_t to wire
 * representation
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
 * @param msg Instance of sbp_ephemeris_common_content_dep_a_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_ephemeris_common_content_dep_a_t(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_ephemeris_common_content_dep_a_t *msg);

/**
 * Decode an instance of sbp_ephemeris_common_content_dep_a_t from wire
 * representation
 *
 * This function decodes the wire representation of a
 * sbp_ephemeris_common_content_dep_a_t message to the given instance. The
 * caller must specify the length of the buffer in the \p len parameter. If
 * non-null the number of bytes read from the buffer will be returned in \p
 * n_read.
 *
 * @param buf Wire representation of the sbp_ephemeris_common_content_dep_a_t
 * instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_ephemeris_common_content_dep_a_t(
    const uint8_t *buf, uint8_t len, uint8_t *n_read,
    sbp_ephemeris_common_content_dep_a_t *msg);

/**
 * Compare two instances of sbp_ephemeris_common_content_dep_a_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_ephemeris_common_content_dep_a_t instance
 * @param b sbp_ephemeris_common_content_dep_a_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_ephemeris_common_content_dep_a_t(
    const sbp_ephemeris_common_content_dep_a_t *a,
    const sbp_ephemeris_common_content_dep_a_t *b);

/*
 *
 *
 *
 ******************************************************************************
 *
 * SBP_MSG_EPHEMERIS_GPS_DEP_E
 *
 *****************************************************************************/
/** Satellite broadcast ephemeris for GPS
 *
 * The ephemeris message returns a set of satellite orbit parameters that is
 * used to calculate GPS satellite position, velocity, and clock offset. Please
 * see the Navstar GPS Space Segment/Navigation user interfaces (ICD-GPS-200,
 * Table 20-III) for more details.
 */
typedef struct {
  /**
   * Values common for all ephemeris types
   */
  sbp_ephemeris_common_content_dep_a_t common;

  /**
   * Group delay differential between L1 and L2 [s]
   */
  double tgd;

  /**
   * Amplitude of the sine harmonic correction term to the orbit radius [m]
   */
  double c_rs;

  /**
   * Amplitude of the cosine harmonic correction term to the orbit radius [m]
   */
  double c_rc;

  /**
   * Amplitude of the cosine harmonic correction term to the argument of
   * latitude [rad]
   */
  double c_uc;

  /**
   * Amplitude of the sine harmonic correction term to the argument of latitude
   * [rad]
   */
  double c_us;

  /**
   * Amplitude of the cosine harmonic correction term to the angle of
   * inclination [rad]
   */
  double c_ic;

  /**
   * Amplitude of the sine harmonic correction term to the angle of inclination
   * [rad]
   */
  double c_is;

  /**
   * Mean motion difference [rad/s]
   */
  double dn;

  /**
   * Mean anomaly at reference time [rad]
   */
  double m0;

  /**
   * Eccentricity of satellite orbit
   */
  double ecc;

  /**
   * Square root of the semi-major axis of orbit [m^(1/2)]
   */
  double sqrta;

  /**
   * Longitude of ascending node of orbit plane at weekly epoch [rad]
   */
  double omega0;

  /**
   * Rate of right ascension [rad/s]
   */
  double omegadot;

  /**
   * Argument of perigee [rad]
   */
  double w;

  /**
   * Inclination [rad]
   */
  double inc;

  /**
   * Inclination first derivative [rad/s]
   */
  double inc_dot;

  /**
   * Polynomial clock correction coefficient (clock bias) [s]
   */
  double af0;

  /**
   * Polynomial clock correction coefficient (clock drift) [s/s]
   */
  double af1;

  /**
   * Polynomial clock correction coefficient (rate of clock drift) [s/s^2]
   */
  double af2;

  /**
   * Clock reference
   */
  sbp_gps_time_dep_t toc;

  /**
   * Issue of ephemeris data
   */
  u8 iode;

  /**
   * Issue of clock data
   */
  u16 iodc;
} sbp_msg_ephemeris_gps_dep_e_t;

/**
 * Get encoded size of an instance of sbp_msg_ephemeris_gps_dep_e_t
 *
 * @param msg sbp_msg_ephemeris_gps_dep_e_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_msg_ephemeris_gps_dep_e_t(
    const sbp_msg_ephemeris_gps_dep_e_t *msg);

/**
 * Encode an instance of sbp_msg_ephemeris_gps_dep_e_t to wire representation
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
 * @param msg Instance of sbp_msg_ephemeris_gps_dep_e_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_msg_ephemeris_gps_dep_e_t(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_msg_ephemeris_gps_dep_e_t *msg);

/**
 * Decode an instance of sbp_msg_ephemeris_gps_dep_e_t from wire representation
 *
 * This function decodes the wire representation of a
 * sbp_msg_ephemeris_gps_dep_e_t message to the given instance. The caller must
 * specify the length of the buffer in the \p len parameter. If non-null the
 * number of bytes read from the buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_msg_ephemeris_gps_dep_e_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_msg_ephemeris_gps_dep_e_t(const uint8_t *buf, uint8_t len,
                                            uint8_t *n_read,
                                            sbp_msg_ephemeris_gps_dep_e_t *msg);
/**
 * Send an instance of sbp_msg_ephemeris_gps_dep_e_t with the given write
 * function
 *
 * An equivalent of #sbp_send_message which operates specifically on
 * sbp_msg_ephemeris_gps_dep_e_t
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
s8 sbp_send_sbp_msg_ephemeris_gps_dep_e_t(
    struct sbp_state *s, u16 sender_id,
    const sbp_msg_ephemeris_gps_dep_e_t *msg,
    s32 (*write)(u8 *buff, u32 n, void *context));

/**
 * Compare two instances of sbp_msg_ephemeris_gps_dep_e_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_ephemeris_gps_dep_e_t instance
 * @param b sbp_msg_ephemeris_gps_dep_e_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_msg_ephemeris_gps_dep_e_t(
    const sbp_msg_ephemeris_gps_dep_e_t *a,
    const sbp_msg_ephemeris_gps_dep_e_t *b);

/*
 *
 *
 *
 ******************************************************************************
 *
 * SBP_MSG_EPHEMERIS_GPS_DEP_F
 *
 *****************************************************************************/
/** Deprecated
 *
 * This observation message has been deprecated in favor of ephemeris message
 * using floats for size reduction.
 */
typedef struct {
  /**
   * Values common for all ephemeris types
   */
  sbp_ephemeris_common_content_dep_b_t common;

  /**
   * Group delay differential between L1 and L2 [s]
   */
  double tgd;

  /**
   * Amplitude of the sine harmonic correction term to the orbit radius [m]
   */
  double c_rs;

  /**
   * Amplitude of the cosine harmonic correction term to the orbit radius [m]
   */
  double c_rc;

  /**
   * Amplitude of the cosine harmonic correction term to the argument of
   * latitude [rad]
   */
  double c_uc;

  /**
   * Amplitude of the sine harmonic correction term to the argument of latitude
   * [rad]
   */
  double c_us;

  /**
   * Amplitude of the cosine harmonic correction term to the angle of
   * inclination [rad]
   */
  double c_ic;

  /**
   * Amplitude of the sine harmonic correction term to the angle of inclination
   * [rad]
   */
  double c_is;

  /**
   * Mean motion difference [rad/s]
   */
  double dn;

  /**
   * Mean anomaly at reference time [rad]
   */
  double m0;

  /**
   * Eccentricity of satellite orbit
   */
  double ecc;

  /**
   * Square root of the semi-major axis of orbit [m^(1/2)]
   */
  double sqrta;

  /**
   * Longitude of ascending node of orbit plane at weekly epoch [rad]
   */
  double omega0;

  /**
   * Rate of right ascension [rad/s]
   */
  double omegadot;

  /**
   * Argument of perigee [rad]
   */
  double w;

  /**
   * Inclination [rad]
   */
  double inc;

  /**
   * Inclination first derivative [rad/s]
   */
  double inc_dot;

  /**
   * Polynomial clock correction coefficient (clock bias) [s]
   */
  double af0;

  /**
   * Polynomial clock correction coefficient (clock drift) [s/s]
   */
  double af1;

  /**
   * Polynomial clock correction coefficient (rate of clock drift) [s/s^2]
   */
  double af2;

  /**
   * Clock reference
   */
  sbp_gps_time_sec_t toc;

  /**
   * Issue of ephemeris data
   */
  u8 iode;

  /**
   * Issue of clock data
   */
  u16 iodc;
} sbp_msg_ephemeris_gps_dep_f_t;

/**
 * Get encoded size of an instance of sbp_msg_ephemeris_gps_dep_f_t
 *
 * @param msg sbp_msg_ephemeris_gps_dep_f_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_msg_ephemeris_gps_dep_f_t(
    const sbp_msg_ephemeris_gps_dep_f_t *msg);

/**
 * Encode an instance of sbp_msg_ephemeris_gps_dep_f_t to wire representation
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
 * @param msg Instance of sbp_msg_ephemeris_gps_dep_f_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_msg_ephemeris_gps_dep_f_t(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_msg_ephemeris_gps_dep_f_t *msg);

/**
 * Decode an instance of sbp_msg_ephemeris_gps_dep_f_t from wire representation
 *
 * This function decodes the wire representation of a
 * sbp_msg_ephemeris_gps_dep_f_t message to the given instance. The caller must
 * specify the length of the buffer in the \p len parameter. If non-null the
 * number of bytes read from the buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_msg_ephemeris_gps_dep_f_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_msg_ephemeris_gps_dep_f_t(const uint8_t *buf, uint8_t len,
                                            uint8_t *n_read,
                                            sbp_msg_ephemeris_gps_dep_f_t *msg);
/**
 * Send an instance of sbp_msg_ephemeris_gps_dep_f_t with the given write
 * function
 *
 * An equivalent of #sbp_send_message which operates specifically on
 * sbp_msg_ephemeris_gps_dep_f_t
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
s8 sbp_send_sbp_msg_ephemeris_gps_dep_f_t(
    struct sbp_state *s, u16 sender_id,
    const sbp_msg_ephemeris_gps_dep_f_t *msg,
    s32 (*write)(u8 *buff, u32 n, void *context));

/**
 * Compare two instances of sbp_msg_ephemeris_gps_dep_f_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_ephemeris_gps_dep_f_t instance
 * @param b sbp_msg_ephemeris_gps_dep_f_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_msg_ephemeris_gps_dep_f_t(
    const sbp_msg_ephemeris_gps_dep_f_t *a,
    const sbp_msg_ephemeris_gps_dep_f_t *b);

/*
 *
 *
 *
 ******************************************************************************
 *
 * SBP_MSG_EPHEMERIS_GPS
 *
 *****************************************************************************/
/** Satellite broadcast ephemeris for GPS
 *
 * The ephemeris message returns a set of satellite orbit parameters that is
 * used to calculate GPS satellite position, velocity, and clock offset. Please
 * see the Navstar GPS Space Segment/Navigation user interfaces (ICD-GPS-200,
 * Table 20-III) for more details.
 */
typedef struct {
  /**
   * Values common for all ephemeris types
   */
  sbp_ephemeris_common_content_t common;

  /**
   * Group delay differential between L1 and L2 [s]
   */
  float tgd;

  /**
   * Amplitude of the sine harmonic correction term to the orbit radius [m]
   */
  float c_rs;

  /**
   * Amplitude of the cosine harmonic correction term to the orbit radius [m]
   */
  float c_rc;

  /**
   * Amplitude of the cosine harmonic correction term to the argument of
   * latitude [rad]
   */
  float c_uc;

  /**
   * Amplitude of the sine harmonic correction term to the argument of latitude
   * [rad]
   */
  float c_us;

  /**
   * Amplitude of the cosine harmonic correction term to the angle of
   * inclination [rad]
   */
  float c_ic;

  /**
   * Amplitude of the sine harmonic correction term to the angle of inclination
   * [rad]
   */
  float c_is;

  /**
   * Mean motion difference [rad/s]
   */
  double dn;

  /**
   * Mean anomaly at reference time [rad]
   */
  double m0;

  /**
   * Eccentricity of satellite orbit
   */
  double ecc;

  /**
   * Square root of the semi-major axis of orbit [m^(1/2)]
   */
  double sqrta;

  /**
   * Longitude of ascending node of orbit plane at weekly epoch [rad]
   */
  double omega0;

  /**
   * Rate of right ascension [rad/s]
   */
  double omegadot;

  /**
   * Argument of perigee [rad]
   */
  double w;

  /**
   * Inclination [rad]
   */
  double inc;

  /**
   * Inclination first derivative [rad/s]
   */
  double inc_dot;

  /**
   * Polynomial clock correction coefficient (clock bias) [s]
   */
  float af0;

  /**
   * Polynomial clock correction coefficient (clock drift) [s/s]
   */
  float af1;

  /**
   * Polynomial clock correction coefficient (rate of clock drift) [s/s^2]
   */
  float af2;

  /**
   * Clock reference
   */
  sbp_gps_time_sec_t toc;

  /**
   * Issue of ephemeris data
   */
  u8 iode;

  /**
   * Issue of clock data
   */
  u16 iodc;
} sbp_msg_ephemeris_gps_t;

/**
 * Get encoded size of an instance of sbp_msg_ephemeris_gps_t
 *
 * @param msg sbp_msg_ephemeris_gps_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_msg_ephemeris_gps_t(
    const sbp_msg_ephemeris_gps_t *msg);

/**
 * Encode an instance of sbp_msg_ephemeris_gps_t to wire representation
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
 * @param msg Instance of sbp_msg_ephemeris_gps_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_msg_ephemeris_gps_t(uint8_t *buf, uint8_t len,
                                      uint8_t *n_written,
                                      const sbp_msg_ephemeris_gps_t *msg);

/**
 * Decode an instance of sbp_msg_ephemeris_gps_t from wire representation
 *
 * This function decodes the wire representation of a sbp_msg_ephemeris_gps_t
 * message to the given instance. The caller must specify the length of the
 * buffer in the \p len parameter. If non-null the number of bytes read from the
 * buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_msg_ephemeris_gps_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_msg_ephemeris_gps_t(const uint8_t *buf, uint8_t len,
                                      uint8_t *n_read,
                                      sbp_msg_ephemeris_gps_t *msg);
/**
 * Send an instance of sbp_msg_ephemeris_gps_t with the given write function
 *
 * An equivalent of #sbp_send_message which operates specifically on
 * sbp_msg_ephemeris_gps_t
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
s8 sbp_send_sbp_msg_ephemeris_gps_t(struct sbp_state *s, u16 sender_id,
                                    const sbp_msg_ephemeris_gps_t *msg,
                                    s32 (*write)(u8 *buff, u32 n,
                                                 void *context));

/**
 * Compare two instances of sbp_msg_ephemeris_gps_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_ephemeris_gps_t instance
 * @param b sbp_msg_ephemeris_gps_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_msg_ephemeris_gps_t(const sbp_msg_ephemeris_gps_t *a,
                                    const sbp_msg_ephemeris_gps_t *b);

/*
 *
 *
 *
 ******************************************************************************
 *
 * SBP_MSG_EPHEMERIS_QZSS
 *
 *****************************************************************************/
/** Satellite broadcast ephemeris for QZSS
 *
 * The ephemeris message returns a set of satellite orbit parameters that is
 * used to calculate QZSS satellite position, velocity, and clock offset.
 */
typedef struct {
  /**
   * Values common for all ephemeris types
   */
  sbp_ephemeris_common_content_t common;

  /**
   * Group delay differential between L1 and L2 [s]
   */
  float tgd;

  /**
   * Amplitude of the sine harmonic correction term to the orbit radius [m]
   */
  float c_rs;

  /**
   * Amplitude of the cosine harmonic correction term to the orbit radius [m]
   */
  float c_rc;

  /**
   * Amplitude of the cosine harmonic correction term to the argument of
   * latitude [rad]
   */
  float c_uc;

  /**
   * Amplitude of the sine harmonic correction term to the argument of latitude
   * [rad]
   */
  float c_us;

  /**
   * Amplitude of the cosine harmonic correction term to the angle of
   * inclination [rad]
   */
  float c_ic;

  /**
   * Amplitude of the sine harmonic correction term to the angle of inclination
   * [rad]
   */
  float c_is;

  /**
   * Mean motion difference [rad/s]
   */
  double dn;

  /**
   * Mean anomaly at reference time [rad]
   */
  double m0;

  /**
   * Eccentricity of satellite orbit
   */
  double ecc;

  /**
   * Square root of the semi-major axis of orbit [m^(1/2)]
   */
  double sqrta;

  /**
   * Longitude of ascending node of orbit plane at weekly epoch [rad]
   */
  double omega0;

  /**
   * Rate of right ascension [rad/s]
   */
  double omegadot;

  /**
   * Argument of perigee [rad]
   */
  double w;

  /**
   * Inclination [rad]
   */
  double inc;

  /**
   * Inclination first derivative [rad/s]
   */
  double inc_dot;

  /**
   * Polynomial clock correction coefficient (clock bias) [s]
   */
  float af0;

  /**
   * Polynomial clock correction coefficient (clock drift) [s/s]
   */
  float af1;

  /**
   * Polynomial clock correction coefficient (rate of clock drift) [s/s^2]
   */
  float af2;

  /**
   * Clock reference
   */
  sbp_gps_time_sec_t toc;

  /**
   * Issue of ephemeris data
   */
  u8 iode;

  /**
   * Issue of clock data
   */
  u16 iodc;
} sbp_msg_ephemeris_qzss_t;

/**
 * Get encoded size of an instance of sbp_msg_ephemeris_qzss_t
 *
 * @param msg sbp_msg_ephemeris_qzss_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_msg_ephemeris_qzss_t(
    const sbp_msg_ephemeris_qzss_t *msg);

/**
 * Encode an instance of sbp_msg_ephemeris_qzss_t to wire representation
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
 * @param msg Instance of sbp_msg_ephemeris_qzss_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_msg_ephemeris_qzss_t(uint8_t *buf, uint8_t len,
                                       uint8_t *n_written,
                                       const sbp_msg_ephemeris_qzss_t *msg);

/**
 * Decode an instance of sbp_msg_ephemeris_qzss_t from wire representation
 *
 * This function decodes the wire representation of a sbp_msg_ephemeris_qzss_t
 * message to the given instance. The caller must specify the length of the
 * buffer in the \p len parameter. If non-null the number of bytes read from the
 * buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_msg_ephemeris_qzss_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_msg_ephemeris_qzss_t(const uint8_t *buf, uint8_t len,
                                       uint8_t *n_read,
                                       sbp_msg_ephemeris_qzss_t *msg);
/**
 * Send an instance of sbp_msg_ephemeris_qzss_t with the given write function
 *
 * An equivalent of #sbp_send_message which operates specifically on
 * sbp_msg_ephemeris_qzss_t
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
s8 sbp_send_sbp_msg_ephemeris_qzss_t(struct sbp_state *s, u16 sender_id,
                                     const sbp_msg_ephemeris_qzss_t *msg,
                                     s32 (*write)(u8 *buff, u32 n,
                                                  void *context));

/**
 * Compare two instances of sbp_msg_ephemeris_qzss_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_ephemeris_qzss_t instance
 * @param b sbp_msg_ephemeris_qzss_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_msg_ephemeris_qzss_t(const sbp_msg_ephemeris_qzss_t *a,
                                     const sbp_msg_ephemeris_qzss_t *b);

/*
 *
 *
 *
 ******************************************************************************
 *
 * SBP_MSG_EPHEMERIS_BDS
 *
 *****************************************************************************/
/** Satellite broadcast ephemeris for BDS
 *
 * The ephemeris message returns a set of satellite orbit parameters that is
 * used to calculate BDS satellite position, velocity, and clock offset. Please
 * see the BeiDou Navigation Satellite System SIS-ICD Version 2.1, Table 5-9 for
 * more details.
 */
typedef struct {
  /**
   * Values common for all ephemeris types
   */
  sbp_ephemeris_common_content_t common;

  /**
   * Group delay differential for B1 [s]
   */
  float tgd1;

  /**
   * Group delay differential for B2 [s]
   */
  float tgd2;

  /**
   * Amplitude of the sine harmonic correction term to the orbit radius [m]
   */
  float c_rs;

  /**
   * Amplitude of the cosine harmonic correction term to the orbit radius [m]
   */
  float c_rc;

  /**
   * Amplitude of the cosine harmonic correction term to the argument of
   * latitude [rad]
   */
  float c_uc;

  /**
   * Amplitude of the sine harmonic correction term to the argument of latitude
   * [rad]
   */
  float c_us;

  /**
   * Amplitude of the cosine harmonic correction term to the angle of
   * inclination [rad]
   */
  float c_ic;

  /**
   * Amplitude of the sine harmonic correction term to the angle of inclination
   * [rad]
   */
  float c_is;

  /**
   * Mean motion difference [rad/s]
   */
  double dn;

  /**
   * Mean anomaly at reference time [rad]
   */
  double m0;

  /**
   * Eccentricity of satellite orbit
   */
  double ecc;

  /**
   * Square root of the semi-major axis of orbit [m^(1/2)]
   */
  double sqrta;

  /**
   * Longitude of ascending node of orbit plane at weekly epoch [rad]
   */
  double omega0;

  /**
   * Rate of right ascension [rad/s]
   */
  double omegadot;

  /**
   * Argument of perigee [rad]
   */
  double w;

  /**
   * Inclination [rad]
   */
  double inc;

  /**
   * Inclination first derivative [rad/s]
   */
  double inc_dot;

  /**
   * Polynomial clock correction coefficient (clock bias) [s]
   */
  double af0;

  /**
   * Polynomial clock correction coefficient (clock drift) [s/s]
   */
  float af1;

  /**
   * Polynomial clock correction coefficient (rate of clock drift) [s/s^2]
   */
  float af2;

  /**
   * Clock reference
   */
  sbp_gps_time_sec_t toc;

  /**
   * Issue of ephemeris data
   * Calculated from the navigation data parameter t_oe per RTCM/CSNO
   * recommendation: IODE = mod (t_oe / 720, 240)
   */
  u8 iode;

  /**
   * Issue of clock data
   * Calculated from the navigation data parameter t_oe per RTCM/CSNO
   * recommendation: IODE = mod (t_oc / 720, 240)
   */
  u16 iodc;
} sbp_msg_ephemeris_bds_t;

/**
 * Get encoded size of an instance of sbp_msg_ephemeris_bds_t
 *
 * @param msg sbp_msg_ephemeris_bds_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_msg_ephemeris_bds_t(
    const sbp_msg_ephemeris_bds_t *msg);

/**
 * Encode an instance of sbp_msg_ephemeris_bds_t to wire representation
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
 * @param msg Instance of sbp_msg_ephemeris_bds_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_msg_ephemeris_bds_t(uint8_t *buf, uint8_t len,
                                      uint8_t *n_written,
                                      const sbp_msg_ephemeris_bds_t *msg);

/**
 * Decode an instance of sbp_msg_ephemeris_bds_t from wire representation
 *
 * This function decodes the wire representation of a sbp_msg_ephemeris_bds_t
 * message to the given instance. The caller must specify the length of the
 * buffer in the \p len parameter. If non-null the number of bytes read from the
 * buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_msg_ephemeris_bds_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_msg_ephemeris_bds_t(const uint8_t *buf, uint8_t len,
                                      uint8_t *n_read,
                                      sbp_msg_ephemeris_bds_t *msg);
/**
 * Send an instance of sbp_msg_ephemeris_bds_t with the given write function
 *
 * An equivalent of #sbp_send_message which operates specifically on
 * sbp_msg_ephemeris_bds_t
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
s8 sbp_send_sbp_msg_ephemeris_bds_t(struct sbp_state *s, u16 sender_id,
                                    const sbp_msg_ephemeris_bds_t *msg,
                                    s32 (*write)(u8 *buff, u32 n,
                                                 void *context));

/**
 * Compare two instances of sbp_msg_ephemeris_bds_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_ephemeris_bds_t instance
 * @param b sbp_msg_ephemeris_bds_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_msg_ephemeris_bds_t(const sbp_msg_ephemeris_bds_t *a,
                                    const sbp_msg_ephemeris_bds_t *b);

/*
 *
 *
 *
 ******************************************************************************
 *
 * SBP_MSG_EPHEMERIS_GAL_DEP_A
 *
 *****************************************************************************/
/** Deprecated
 *
 * This observation message has been deprecated in favor of an ephemeris message
 * with explicit source of NAV data.
 */
typedef struct {
  /**
   * Values common for all ephemeris types
   */
  sbp_ephemeris_common_content_t common;

  /**
   * E1-E5a Broadcast Group Delay [s]
   */
  float bgd_e1e5a;

  /**
   * E1-E5b Broadcast Group Delay [s]
   */
  float bgd_e1e5b;

  /**
   * Amplitude of the sine harmonic correction term to the orbit radius [m]
   */
  float c_rs;

  /**
   * Amplitude of the cosine harmonic correction term to the orbit radius [m]
   */
  float c_rc;

  /**
   * Amplitude of the cosine harmonic correction term to the argument of
   * latitude [rad]
   */
  float c_uc;

  /**
   * Amplitude of the sine harmonic correction term to the argument of latitude
   * [rad]
   */
  float c_us;

  /**
   * Amplitude of the cosine harmonic correction term to the angle of
   * inclination [rad]
   */
  float c_ic;

  /**
   * Amplitude of the sine harmonic correction term to the angle of inclination
   * [rad]
   */
  float c_is;

  /**
   * Mean motion difference [rad/s]
   */
  double dn;

  /**
   * Mean anomaly at reference time [rad]
   */
  double m0;

  /**
   * Eccentricity of satellite orbit
   */
  double ecc;

  /**
   * Square root of the semi-major axis of orbit [m^(1/2)]
   */
  double sqrta;

  /**
   * Longitude of ascending node of orbit plane at weekly epoch [rad]
   */
  double omega0;

  /**
   * Rate of right ascension [rad/s]
   */
  double omegadot;

  /**
   * Argument of perigee [rad]
   */
  double w;

  /**
   * Inclination [rad]
   */
  double inc;

  /**
   * Inclination first derivative [rad/s]
   */
  double inc_dot;

  /**
   * Polynomial clock correction coefficient (clock bias) [s]
   */
  double af0;

  /**
   * Polynomial clock correction coefficient (clock drift) [s/s]
   */
  double af1;

  /**
   * Polynomial clock correction coefficient (rate of clock drift) [s/s^2]
   */
  float af2;

  /**
   * Clock reference
   */
  sbp_gps_time_sec_t toc;

  /**
   * Issue of data (IODnav)
   */
  u16 iode;

  /**
   * Issue of data (IODnav). Always equal to iode
   */
  u16 iodc;
} sbp_msg_ephemeris_gal_dep_a_t;

/**
 * Get encoded size of an instance of sbp_msg_ephemeris_gal_dep_a_t
 *
 * @param msg sbp_msg_ephemeris_gal_dep_a_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_msg_ephemeris_gal_dep_a_t(
    const sbp_msg_ephemeris_gal_dep_a_t *msg);

/**
 * Encode an instance of sbp_msg_ephemeris_gal_dep_a_t to wire representation
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
 * @param msg Instance of sbp_msg_ephemeris_gal_dep_a_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_msg_ephemeris_gal_dep_a_t(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_msg_ephemeris_gal_dep_a_t *msg);

/**
 * Decode an instance of sbp_msg_ephemeris_gal_dep_a_t from wire representation
 *
 * This function decodes the wire representation of a
 * sbp_msg_ephemeris_gal_dep_a_t message to the given instance. The caller must
 * specify the length of the buffer in the \p len parameter. If non-null the
 * number of bytes read from the buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_msg_ephemeris_gal_dep_a_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_msg_ephemeris_gal_dep_a_t(const uint8_t *buf, uint8_t len,
                                            uint8_t *n_read,
                                            sbp_msg_ephemeris_gal_dep_a_t *msg);
/**
 * Send an instance of sbp_msg_ephemeris_gal_dep_a_t with the given write
 * function
 *
 * An equivalent of #sbp_send_message which operates specifically on
 * sbp_msg_ephemeris_gal_dep_a_t
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
s8 sbp_send_sbp_msg_ephemeris_gal_dep_a_t(
    struct sbp_state *s, u16 sender_id,
    const sbp_msg_ephemeris_gal_dep_a_t *msg,
    s32 (*write)(u8 *buff, u32 n, void *context));

/**
 * Compare two instances of sbp_msg_ephemeris_gal_dep_a_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_ephemeris_gal_dep_a_t instance
 * @param b sbp_msg_ephemeris_gal_dep_a_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_msg_ephemeris_gal_dep_a_t(
    const sbp_msg_ephemeris_gal_dep_a_t *a,
    const sbp_msg_ephemeris_gal_dep_a_t *b);

/*
 *
 *
 *
 ******************************************************************************
 *
 * SBP_MSG_EPHEMERIS_GAL
 *
 *****************************************************************************/
/** Satellite broadcast ephemeris for Galileo
 *
 * The ephemeris message returns a set of satellite orbit parameters that is
 * used to calculate Galileo satellite position, velocity, and clock offset.
 * Please see the Signal In Space ICD OS SIS ICD, Issue 1.3, December 2016 for
 * more details.
 */
typedef struct {
  /**
   * Values common for all ephemeris types
   */
  sbp_ephemeris_common_content_t common;

  /**
   * E1-E5a Broadcast Group Delay [s]
   */
  float bgd_e1e5a;

  /**
   * E1-E5b Broadcast Group Delay [s]
   */
  float bgd_e1e5b;

  /**
   * Amplitude of the sine harmonic correction term to the orbit radius [m]
   */
  float c_rs;

  /**
   * Amplitude of the cosine harmonic correction term to the orbit radius [m]
   */
  float c_rc;

  /**
   * Amplitude of the cosine harmonic correction term to the argument of
   * latitude [rad]
   */
  float c_uc;

  /**
   * Amplitude of the sine harmonic correction term to the argument of latitude
   * [rad]
   */
  float c_us;

  /**
   * Amplitude of the cosine harmonic correction term to the angle of
   * inclination [rad]
   */
  float c_ic;

  /**
   * Amplitude of the sine harmonic correction term to the angle of inclination
   * [rad]
   */
  float c_is;

  /**
   * Mean motion difference [rad/s]
   */
  double dn;

  /**
   * Mean anomaly at reference time [rad]
   */
  double m0;

  /**
   * Eccentricity of satellite orbit
   */
  double ecc;

  /**
   * Square root of the semi-major axis of orbit [m^(1/2)]
   */
  double sqrta;

  /**
   * Longitude of ascending node of orbit plane at weekly epoch [rad]
   */
  double omega0;

  /**
   * Rate of right ascension [rad/s]
   */
  double omegadot;

  /**
   * Argument of perigee [rad]
   */
  double w;

  /**
   * Inclination [rad]
   */
  double inc;

  /**
   * Inclination first derivative [rad/s]
   */
  double inc_dot;

  /**
   * Polynomial clock correction coefficient (clock bias) [s]
   */
  double af0;

  /**
   * Polynomial clock correction coefficient (clock drift) [s/s]
   */
  double af1;

  /**
   * Polynomial clock correction coefficient (rate of clock drift) [s/s^2]
   */
  float af2;

  /**
   * Clock reference
   */
  sbp_gps_time_sec_t toc;

  /**
   * Issue of data (IODnav)
   */
  u16 iode;

  /**
   * Issue of data (IODnav). Always equal to iode
   */
  u16 iodc;

  /**
   * 0=I/NAV, 1=F/NAV
   */
  u8 source;
} sbp_msg_ephemeris_gal_t;

/**
 * Get encoded size of an instance of sbp_msg_ephemeris_gal_t
 *
 * @param msg sbp_msg_ephemeris_gal_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_msg_ephemeris_gal_t(
    const sbp_msg_ephemeris_gal_t *msg);

/**
 * Encode an instance of sbp_msg_ephemeris_gal_t to wire representation
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
 * @param msg Instance of sbp_msg_ephemeris_gal_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_msg_ephemeris_gal_t(uint8_t *buf, uint8_t len,
                                      uint8_t *n_written,
                                      const sbp_msg_ephemeris_gal_t *msg);

/**
 * Decode an instance of sbp_msg_ephemeris_gal_t from wire representation
 *
 * This function decodes the wire representation of a sbp_msg_ephemeris_gal_t
 * message to the given instance. The caller must specify the length of the
 * buffer in the \p len parameter. If non-null the number of bytes read from the
 * buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_msg_ephemeris_gal_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_msg_ephemeris_gal_t(const uint8_t *buf, uint8_t len,
                                      uint8_t *n_read,
                                      sbp_msg_ephemeris_gal_t *msg);
/**
 * Send an instance of sbp_msg_ephemeris_gal_t with the given write function
 *
 * An equivalent of #sbp_send_message which operates specifically on
 * sbp_msg_ephemeris_gal_t
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
s8 sbp_send_sbp_msg_ephemeris_gal_t(struct sbp_state *s, u16 sender_id,
                                    const sbp_msg_ephemeris_gal_t *msg,
                                    s32 (*write)(u8 *buff, u32 n,
                                                 void *context));

/**
 * Compare two instances of sbp_msg_ephemeris_gal_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_ephemeris_gal_t instance
 * @param b sbp_msg_ephemeris_gal_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_msg_ephemeris_gal_t(const sbp_msg_ephemeris_gal_t *a,
                                    const sbp_msg_ephemeris_gal_t *b);

/*
 *
 *
 *
 ******************************************************************************
 *
 * SBP_MSG_EPHEMERIS_SBAS_DEP_A
 *
 *****************************************************************************/
typedef struct {
  /**
   * Values common for all ephemeris types
   */
  sbp_ephemeris_common_content_dep_a_t common;

  /**
   * Position of the GEO at time toe [m]
   */
  double pos[3];

  /**
   * Velocity of the GEO at time toe [m/s]
   */
  double vel[3];

  /**
   * Acceleration of the GEO at time toe [m/s^2]
   */
  double acc[3];

  /**
   * Time offset of the GEO clock w.r.t. SBAS Network Time [s]
   */
  double a_gf0;

  /**
   * Drift of the GEO clock w.r.t. SBAS Network Time [s/s]
   */
  double a_gf1;
} sbp_msg_ephemeris_sbas_dep_a_t;

/**
 * Get encoded size of an instance of sbp_msg_ephemeris_sbas_dep_a_t
 *
 * @param msg sbp_msg_ephemeris_sbas_dep_a_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_msg_ephemeris_sbas_dep_a_t(
    const sbp_msg_ephemeris_sbas_dep_a_t *msg);

/**
 * Encode an instance of sbp_msg_ephemeris_sbas_dep_a_t to wire representation
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
 * @param msg Instance of sbp_msg_ephemeris_sbas_dep_a_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_msg_ephemeris_sbas_dep_a_t(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_msg_ephemeris_sbas_dep_a_t *msg);

/**
 * Decode an instance of sbp_msg_ephemeris_sbas_dep_a_t from wire representation
 *
 * This function decodes the wire representation of a
 * sbp_msg_ephemeris_sbas_dep_a_t message to the given instance. The caller must
 * specify the length of the buffer in the \p len parameter. If non-null the
 * number of bytes read from the buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_msg_ephemeris_sbas_dep_a_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_msg_ephemeris_sbas_dep_a_t(
    const uint8_t *buf, uint8_t len, uint8_t *n_read,
    sbp_msg_ephemeris_sbas_dep_a_t *msg);
/**
 * Send an instance of sbp_msg_ephemeris_sbas_dep_a_t with the given write
 * function
 *
 * An equivalent of #sbp_send_message which operates specifically on
 * sbp_msg_ephemeris_sbas_dep_a_t
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
s8 sbp_send_sbp_msg_ephemeris_sbas_dep_a_t(
    struct sbp_state *s, u16 sender_id,
    const sbp_msg_ephemeris_sbas_dep_a_t *msg,
    s32 (*write)(u8 *buff, u32 n, void *context));

/**
 * Compare two instances of sbp_msg_ephemeris_sbas_dep_a_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_ephemeris_sbas_dep_a_t instance
 * @param b sbp_msg_ephemeris_sbas_dep_a_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_msg_ephemeris_sbas_dep_a_t(
    const sbp_msg_ephemeris_sbas_dep_a_t *a,
    const sbp_msg_ephemeris_sbas_dep_a_t *b);

/*
 *
 *
 *
 ******************************************************************************
 *
 * SBP_MSG_EPHEMERIS_GLO_DEP_A
 *
 *****************************************************************************/
/** Satellite broadcast ephemeris for GLO
 *
 * The ephemeris message returns a set of satellite orbit parameters that is
 * used to calculate GLO satellite position, velocity, and clock offset. Please
 * see the GLO ICD 5.1 "Table 4.5 Characteristics of words of immediate
 * information (ephemeris parameters)" for more details.
 */
typedef struct {
  /**
   * Values common for all ephemeris types
   */
  sbp_ephemeris_common_content_dep_a_t common;

  /**
   * Relative deviation of predicted carrier frequency from nominal
   */
  double gamma;

  /**
   * Correction to the SV time [s]
   */
  double tau;

  /**
   * Position of the SV at tb in PZ-90.02 coordinates system [m]
   */
  double pos[3];

  /**
   * Velocity vector of the SV at tb in PZ-90.02 coordinates system [m/s]
   */
  double vel[3];

  /**
   * Acceleration vector of the SV at tb in PZ-90.02 coordinates sys [m/s^2]
   */
  double acc[3];
} sbp_msg_ephemeris_glo_dep_a_t;

/**
 * Get encoded size of an instance of sbp_msg_ephemeris_glo_dep_a_t
 *
 * @param msg sbp_msg_ephemeris_glo_dep_a_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_msg_ephemeris_glo_dep_a_t(
    const sbp_msg_ephemeris_glo_dep_a_t *msg);

/**
 * Encode an instance of sbp_msg_ephemeris_glo_dep_a_t to wire representation
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
 * @param msg Instance of sbp_msg_ephemeris_glo_dep_a_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_msg_ephemeris_glo_dep_a_t(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_msg_ephemeris_glo_dep_a_t *msg);

/**
 * Decode an instance of sbp_msg_ephemeris_glo_dep_a_t from wire representation
 *
 * This function decodes the wire representation of a
 * sbp_msg_ephemeris_glo_dep_a_t message to the given instance. The caller must
 * specify the length of the buffer in the \p len parameter. If non-null the
 * number of bytes read from the buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_msg_ephemeris_glo_dep_a_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_msg_ephemeris_glo_dep_a_t(const uint8_t *buf, uint8_t len,
                                            uint8_t *n_read,
                                            sbp_msg_ephemeris_glo_dep_a_t *msg);
/**
 * Send an instance of sbp_msg_ephemeris_glo_dep_a_t with the given write
 * function
 *
 * An equivalent of #sbp_send_message which operates specifically on
 * sbp_msg_ephemeris_glo_dep_a_t
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
s8 sbp_send_sbp_msg_ephemeris_glo_dep_a_t(
    struct sbp_state *s, u16 sender_id,
    const sbp_msg_ephemeris_glo_dep_a_t *msg,
    s32 (*write)(u8 *buff, u32 n, void *context));

/**
 * Compare two instances of sbp_msg_ephemeris_glo_dep_a_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_ephemeris_glo_dep_a_t instance
 * @param b sbp_msg_ephemeris_glo_dep_a_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_msg_ephemeris_glo_dep_a_t(
    const sbp_msg_ephemeris_glo_dep_a_t *a,
    const sbp_msg_ephemeris_glo_dep_a_t *b);

/*
 *
 *
 *
 ******************************************************************************
 *
 * SBP_MSG_EPHEMERIS_SBAS_DEP_B
 *
 *****************************************************************************/
/** Deprecated
 *
 * This observation message has been deprecated in favor of ephemeris message
 * using floats for size reduction.
 */
typedef struct {
  /**
   * Values common for all ephemeris types
   */
  sbp_ephemeris_common_content_dep_b_t common;

  /**
   * Position of the GEO at time toe [m]
   */
  double pos[3];

  /**
   * Velocity of the GEO at time toe [m/s]
   */
  double vel[3];

  /**
   * Acceleration of the GEO at time toe [m/s^2]
   */
  double acc[3];

  /**
   * Time offset of the GEO clock w.r.t. SBAS Network Time [s]
   */
  double a_gf0;

  /**
   * Drift of the GEO clock w.r.t. SBAS Network Time [s/s]
   */
  double a_gf1;
} sbp_msg_ephemeris_sbas_dep_b_t;

/**
 * Get encoded size of an instance of sbp_msg_ephemeris_sbas_dep_b_t
 *
 * @param msg sbp_msg_ephemeris_sbas_dep_b_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_msg_ephemeris_sbas_dep_b_t(
    const sbp_msg_ephemeris_sbas_dep_b_t *msg);

/**
 * Encode an instance of sbp_msg_ephemeris_sbas_dep_b_t to wire representation
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
 * @param msg Instance of sbp_msg_ephemeris_sbas_dep_b_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_msg_ephemeris_sbas_dep_b_t(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_msg_ephemeris_sbas_dep_b_t *msg);

/**
 * Decode an instance of sbp_msg_ephemeris_sbas_dep_b_t from wire representation
 *
 * This function decodes the wire representation of a
 * sbp_msg_ephemeris_sbas_dep_b_t message to the given instance. The caller must
 * specify the length of the buffer in the \p len parameter. If non-null the
 * number of bytes read from the buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_msg_ephemeris_sbas_dep_b_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_msg_ephemeris_sbas_dep_b_t(
    const uint8_t *buf, uint8_t len, uint8_t *n_read,
    sbp_msg_ephemeris_sbas_dep_b_t *msg);
/**
 * Send an instance of sbp_msg_ephemeris_sbas_dep_b_t with the given write
 * function
 *
 * An equivalent of #sbp_send_message which operates specifically on
 * sbp_msg_ephemeris_sbas_dep_b_t
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
s8 sbp_send_sbp_msg_ephemeris_sbas_dep_b_t(
    struct sbp_state *s, u16 sender_id,
    const sbp_msg_ephemeris_sbas_dep_b_t *msg,
    s32 (*write)(u8 *buff, u32 n, void *context));

/**
 * Compare two instances of sbp_msg_ephemeris_sbas_dep_b_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_ephemeris_sbas_dep_b_t instance
 * @param b sbp_msg_ephemeris_sbas_dep_b_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_msg_ephemeris_sbas_dep_b_t(
    const sbp_msg_ephemeris_sbas_dep_b_t *a,
    const sbp_msg_ephemeris_sbas_dep_b_t *b);

/*
 *
 *
 *
 ******************************************************************************
 *
 * SBP_MSG_EPHEMERIS_SBAS
 *
 *****************************************************************************/
typedef struct {
  /**
   * Values common for all ephemeris types
   */
  sbp_ephemeris_common_content_t common;

  /**
   * Position of the GEO at time toe [m]
   */
  double pos[3];

  /**
   * Velocity of the GEO at time toe [m/s]
   */
  float vel[3];

  /**
   * Acceleration of the GEO at time toe [m/s^2]
   */
  float acc[3];

  /**
   * Time offset of the GEO clock w.r.t. SBAS Network Time [s]
   */
  float a_gf0;

  /**
   * Drift of the GEO clock w.r.t. SBAS Network Time [s/s]
   */
  float a_gf1;
} sbp_msg_ephemeris_sbas_t;

/**
 * Get encoded size of an instance of sbp_msg_ephemeris_sbas_t
 *
 * @param msg sbp_msg_ephemeris_sbas_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_msg_ephemeris_sbas_t(
    const sbp_msg_ephemeris_sbas_t *msg);

/**
 * Encode an instance of sbp_msg_ephemeris_sbas_t to wire representation
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
 * @param msg Instance of sbp_msg_ephemeris_sbas_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_msg_ephemeris_sbas_t(uint8_t *buf, uint8_t len,
                                       uint8_t *n_written,
                                       const sbp_msg_ephemeris_sbas_t *msg);

/**
 * Decode an instance of sbp_msg_ephemeris_sbas_t from wire representation
 *
 * This function decodes the wire representation of a sbp_msg_ephemeris_sbas_t
 * message to the given instance. The caller must specify the length of the
 * buffer in the \p len parameter. If non-null the number of bytes read from the
 * buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_msg_ephemeris_sbas_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_msg_ephemeris_sbas_t(const uint8_t *buf, uint8_t len,
                                       uint8_t *n_read,
                                       sbp_msg_ephemeris_sbas_t *msg);
/**
 * Send an instance of sbp_msg_ephemeris_sbas_t with the given write function
 *
 * An equivalent of #sbp_send_message which operates specifically on
 * sbp_msg_ephemeris_sbas_t
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
s8 sbp_send_sbp_msg_ephemeris_sbas_t(struct sbp_state *s, u16 sender_id,
                                     const sbp_msg_ephemeris_sbas_t *msg,
                                     s32 (*write)(u8 *buff, u32 n,
                                                  void *context));

/**
 * Compare two instances of sbp_msg_ephemeris_sbas_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_ephemeris_sbas_t instance
 * @param b sbp_msg_ephemeris_sbas_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_msg_ephemeris_sbas_t(const sbp_msg_ephemeris_sbas_t *a,
                                     const sbp_msg_ephemeris_sbas_t *b);

/*
 *
 *
 *
 ******************************************************************************
 *
 * SBP_MSG_EPHEMERIS_GLO_DEP_B
 *
 *****************************************************************************/
/** Satellite broadcast ephemeris for GLO
 *
 * The ephemeris message returns a set of satellite orbit parameters that is
 * used to calculate GLO satellite position, velocity, and clock offset. Please
 * see the GLO ICD 5.1 "Table 4.5 Characteristics of words of immediate
 * information (ephemeris parameters)" for more details.
 */
typedef struct {
  /**
   * Values common for all ephemeris types
   */
  sbp_ephemeris_common_content_dep_b_t common;

  /**
   * Relative deviation of predicted carrier frequency from nominal
   */
  double gamma;

  /**
   * Correction to the SV time [s]
   */
  double tau;

  /**
   * Position of the SV at tb in PZ-90.02 coordinates system [m]
   */
  double pos[3];

  /**
   * Velocity vector of the SV at tb in PZ-90.02 coordinates system [m/s]
   */
  double vel[3];

  /**
   * Acceleration vector of the SV at tb in PZ-90.02 coordinates sys [m/s^2]
   */
  double acc[3];
} sbp_msg_ephemeris_glo_dep_b_t;

/**
 * Get encoded size of an instance of sbp_msg_ephemeris_glo_dep_b_t
 *
 * @param msg sbp_msg_ephemeris_glo_dep_b_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_msg_ephemeris_glo_dep_b_t(
    const sbp_msg_ephemeris_glo_dep_b_t *msg);

/**
 * Encode an instance of sbp_msg_ephemeris_glo_dep_b_t to wire representation
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
 * @param msg Instance of sbp_msg_ephemeris_glo_dep_b_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_msg_ephemeris_glo_dep_b_t(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_msg_ephemeris_glo_dep_b_t *msg);

/**
 * Decode an instance of sbp_msg_ephemeris_glo_dep_b_t from wire representation
 *
 * This function decodes the wire representation of a
 * sbp_msg_ephemeris_glo_dep_b_t message to the given instance. The caller must
 * specify the length of the buffer in the \p len parameter. If non-null the
 * number of bytes read from the buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_msg_ephemeris_glo_dep_b_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_msg_ephemeris_glo_dep_b_t(const uint8_t *buf, uint8_t len,
                                            uint8_t *n_read,
                                            sbp_msg_ephemeris_glo_dep_b_t *msg);
/**
 * Send an instance of sbp_msg_ephemeris_glo_dep_b_t with the given write
 * function
 *
 * An equivalent of #sbp_send_message which operates specifically on
 * sbp_msg_ephemeris_glo_dep_b_t
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
s8 sbp_send_sbp_msg_ephemeris_glo_dep_b_t(
    struct sbp_state *s, u16 sender_id,
    const sbp_msg_ephemeris_glo_dep_b_t *msg,
    s32 (*write)(u8 *buff, u32 n, void *context));

/**
 * Compare two instances of sbp_msg_ephemeris_glo_dep_b_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_ephemeris_glo_dep_b_t instance
 * @param b sbp_msg_ephemeris_glo_dep_b_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_msg_ephemeris_glo_dep_b_t(
    const sbp_msg_ephemeris_glo_dep_b_t *a,
    const sbp_msg_ephemeris_glo_dep_b_t *b);

/*
 *
 *
 *
 ******************************************************************************
 *
 * SBP_MSG_EPHEMERIS_GLO_DEP_C
 *
 *****************************************************************************/
/** Satellite broadcast ephemeris for GLO
 *
 * The ephemeris message returns a set of satellite orbit parameters that is
 * used to calculate GLO satellite position, velocity, and clock offset. Please
 * see the GLO ICD 5.1 "Table 4.5 Characteristics of words of immediate
 * information (ephemeris parameters)" for more details.
 */
typedef struct {
  /**
   * Values common for all ephemeris types
   */
  sbp_ephemeris_common_content_dep_b_t common;

  /**
   * Relative deviation of predicted carrier frequency from nominal
   */
  double gamma;

  /**
   * Correction to the SV time [s]
   */
  double tau;

  /**
   * Equipment delay between L1 and L2 [s]
   */
  double d_tau;

  /**
   * Position of the SV at tb in PZ-90.02 coordinates system [m]
   */
  double pos[3];

  /**
   * Velocity vector of the SV at tb in PZ-90.02 coordinates system [m/s]
   */
  double vel[3];

  /**
   * Acceleration vector of the SV at tb in PZ-90.02 coordinates sys [m/s^2]
   */
  double acc[3];

  /**
   * Frequency slot. FCN+8 (that is [1..14]). 0 or 0xFF for invalid
   */
  u8 fcn;
} sbp_msg_ephemeris_glo_dep_c_t;

/**
 * Get encoded size of an instance of sbp_msg_ephemeris_glo_dep_c_t
 *
 * @param msg sbp_msg_ephemeris_glo_dep_c_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_msg_ephemeris_glo_dep_c_t(
    const sbp_msg_ephemeris_glo_dep_c_t *msg);

/**
 * Encode an instance of sbp_msg_ephemeris_glo_dep_c_t to wire representation
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
 * @param msg Instance of sbp_msg_ephemeris_glo_dep_c_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_msg_ephemeris_glo_dep_c_t(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_msg_ephemeris_glo_dep_c_t *msg);

/**
 * Decode an instance of sbp_msg_ephemeris_glo_dep_c_t from wire representation
 *
 * This function decodes the wire representation of a
 * sbp_msg_ephemeris_glo_dep_c_t message to the given instance. The caller must
 * specify the length of the buffer in the \p len parameter. If non-null the
 * number of bytes read from the buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_msg_ephemeris_glo_dep_c_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_msg_ephemeris_glo_dep_c_t(const uint8_t *buf, uint8_t len,
                                            uint8_t *n_read,
                                            sbp_msg_ephemeris_glo_dep_c_t *msg);
/**
 * Send an instance of sbp_msg_ephemeris_glo_dep_c_t with the given write
 * function
 *
 * An equivalent of #sbp_send_message which operates specifically on
 * sbp_msg_ephemeris_glo_dep_c_t
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
s8 sbp_send_sbp_msg_ephemeris_glo_dep_c_t(
    struct sbp_state *s, u16 sender_id,
    const sbp_msg_ephemeris_glo_dep_c_t *msg,
    s32 (*write)(u8 *buff, u32 n, void *context));

/**
 * Compare two instances of sbp_msg_ephemeris_glo_dep_c_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_ephemeris_glo_dep_c_t instance
 * @param b sbp_msg_ephemeris_glo_dep_c_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_msg_ephemeris_glo_dep_c_t(
    const sbp_msg_ephemeris_glo_dep_c_t *a,
    const sbp_msg_ephemeris_glo_dep_c_t *b);

/*
 *
 *
 *
 ******************************************************************************
 *
 * SBP_MSG_EPHEMERIS_GLO_DEP_D
 *
 *****************************************************************************/
/** Deprecated
 *
 * This observation message has been deprecated in favor of ephemeris message
 * using floats for size reduction.
 */
typedef struct {
  /**
   * Values common for all ephemeris types
   */
  sbp_ephemeris_common_content_dep_b_t common;

  /**
   * Relative deviation of predicted carrier frequency from nominal
   */
  double gamma;

  /**
   * Correction to the SV time [s]
   */
  double tau;

  /**
   * Equipment delay between L1 and L2 [s]
   */
  double d_tau;

  /**
   * Position of the SV at tb in PZ-90.02 coordinates system [m]
   */
  double pos[3];

  /**
   * Velocity vector of the SV at tb in PZ-90.02 coordinates system [m/s]
   */
  double vel[3];

  /**
   * Acceleration vector of the SV at tb in PZ-90.02 coordinates sys [m/s^2]
   */
  double acc[3];

  /**
   * Frequency slot. FCN+8 (that is [1..14]). 0 or 0xFF for invalid
   */
  u8 fcn;

  /**
   * Issue of data. Equal to the 7 bits of the immediate data word t_b
   */
  u8 iod;
} sbp_msg_ephemeris_glo_dep_d_t;

/**
 * Get encoded size of an instance of sbp_msg_ephemeris_glo_dep_d_t
 *
 * @param msg sbp_msg_ephemeris_glo_dep_d_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_msg_ephemeris_glo_dep_d_t(
    const sbp_msg_ephemeris_glo_dep_d_t *msg);

/**
 * Encode an instance of sbp_msg_ephemeris_glo_dep_d_t to wire representation
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
 * @param msg Instance of sbp_msg_ephemeris_glo_dep_d_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_msg_ephemeris_glo_dep_d_t(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_msg_ephemeris_glo_dep_d_t *msg);

/**
 * Decode an instance of sbp_msg_ephemeris_glo_dep_d_t from wire representation
 *
 * This function decodes the wire representation of a
 * sbp_msg_ephemeris_glo_dep_d_t message to the given instance. The caller must
 * specify the length of the buffer in the \p len parameter. If non-null the
 * number of bytes read from the buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_msg_ephemeris_glo_dep_d_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_msg_ephemeris_glo_dep_d_t(const uint8_t *buf, uint8_t len,
                                            uint8_t *n_read,
                                            sbp_msg_ephemeris_glo_dep_d_t *msg);
/**
 * Send an instance of sbp_msg_ephemeris_glo_dep_d_t with the given write
 * function
 *
 * An equivalent of #sbp_send_message which operates specifically on
 * sbp_msg_ephemeris_glo_dep_d_t
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
s8 sbp_send_sbp_msg_ephemeris_glo_dep_d_t(
    struct sbp_state *s, u16 sender_id,
    const sbp_msg_ephemeris_glo_dep_d_t *msg,
    s32 (*write)(u8 *buff, u32 n, void *context));

/**
 * Compare two instances of sbp_msg_ephemeris_glo_dep_d_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_ephemeris_glo_dep_d_t instance
 * @param b sbp_msg_ephemeris_glo_dep_d_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_msg_ephemeris_glo_dep_d_t(
    const sbp_msg_ephemeris_glo_dep_d_t *a,
    const sbp_msg_ephemeris_glo_dep_d_t *b);

/*
 *
 *
 *
 ******************************************************************************
 *
 * SBP_MSG_EPHEMERIS_GLO
 *
 *****************************************************************************/
/** Satellite broadcast ephemeris for GLO
 *
 * The ephemeris message returns a set of satellite orbit parameters that is
 * used to calculate GLO satellite position, velocity, and clock offset. Please
 * see the GLO ICD 5.1 "Table 4.5 Characteristics of words of immediate
 * information (ephemeris parameters)" for more details.
 */
typedef struct {
  /**
   * Values common for all ephemeris types
   */
  sbp_ephemeris_common_content_t common;

  /**
   * Relative deviation of predicted carrier frequency from nominal
   */
  float gamma;

  /**
   * Correction to the SV time [s]
   */
  float tau;

  /**
   * Equipment delay between L1 and L2 [s]
   */
  float d_tau;

  /**
   * Position of the SV at tb in PZ-90.02 coordinates system [m]
   */
  double pos[3];

  /**
   * Velocity vector of the SV at tb in PZ-90.02 coordinates system [m/s]
   */
  double vel[3];

  /**
   * Acceleration vector of the SV at tb in PZ-90.02 coordinates sys [m/s^2]
   */
  float acc[3];

  /**
   * Frequency slot. FCN+8 (that is [1..14]). 0 or 0xFF for invalid
   */
  u8 fcn;

  /**
   * Issue of data. Equal to the 7 bits of the immediate data word t_b
   */
  u8 iod;
} sbp_msg_ephemeris_glo_t;

/**
 * Get encoded size of an instance of sbp_msg_ephemeris_glo_t
 *
 * @param msg sbp_msg_ephemeris_glo_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_msg_ephemeris_glo_t(
    const sbp_msg_ephemeris_glo_t *msg);

/**
 * Encode an instance of sbp_msg_ephemeris_glo_t to wire representation
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
 * @param msg Instance of sbp_msg_ephemeris_glo_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_msg_ephemeris_glo_t(uint8_t *buf, uint8_t len,
                                      uint8_t *n_written,
                                      const sbp_msg_ephemeris_glo_t *msg);

/**
 * Decode an instance of sbp_msg_ephemeris_glo_t from wire representation
 *
 * This function decodes the wire representation of a sbp_msg_ephemeris_glo_t
 * message to the given instance. The caller must specify the length of the
 * buffer in the \p len parameter. If non-null the number of bytes read from the
 * buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_msg_ephemeris_glo_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_msg_ephemeris_glo_t(const uint8_t *buf, uint8_t len,
                                      uint8_t *n_read,
                                      sbp_msg_ephemeris_glo_t *msg);
/**
 * Send an instance of sbp_msg_ephemeris_glo_t with the given write function
 *
 * An equivalent of #sbp_send_message which operates specifically on
 * sbp_msg_ephemeris_glo_t
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
s8 sbp_send_sbp_msg_ephemeris_glo_t(struct sbp_state *s, u16 sender_id,
                                    const sbp_msg_ephemeris_glo_t *msg,
                                    s32 (*write)(u8 *buff, u32 n,
                                                 void *context));

/**
 * Compare two instances of sbp_msg_ephemeris_glo_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_ephemeris_glo_t instance
 * @param b sbp_msg_ephemeris_glo_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_msg_ephemeris_glo_t(const sbp_msg_ephemeris_glo_t *a,
                                    const sbp_msg_ephemeris_glo_t *b);

/*
 *
 *
 *
 ******************************************************************************
 *
 * SBP_MSG_EPHEMERIS_DEP_D
 *
 *****************************************************************************/
/** Satellite broadcast ephemeris
 *
 * The ephemeris message returns a set of satellite orbit parameters that is
 * used to calculate GPS satellite position, velocity, and clock offset. Please
 * see the Navstar GPS Space Segment/Navigation user interfaces (ICD-GPS-200,
 * Table 20-III) for more details.
 */
typedef struct {
  /**
   * Group delay differential between L1 and L2 [s]
   */
  double tgd;

  /**
   * Amplitude of the sine harmonic correction term to the orbit radius [m]
   */
  double c_rs;

  /**
   * Amplitude of the cosine harmonic correction term to the orbit radius [m]
   */
  double c_rc;

  /**
   * Amplitude of the cosine harmonic correction term to the argument of
   * latitude [rad]
   */
  double c_uc;

  /**
   * Amplitude of the sine harmonic correction term to the argument of latitude
   * [rad]
   */
  double c_us;

  /**
   * Amplitude of the cosine harmonic correction term to the angle of
   * inclination [rad]
   */
  double c_ic;

  /**
   * Amplitude of the sine harmonic correction term to the angle of inclination
   * [rad]
   */
  double c_is;

  /**
   * Mean motion difference [rad/s]
   */
  double dn;

  /**
   * Mean anomaly at reference time [rad]
   */
  double m0;

  /**
   * Eccentricity of satellite orbit
   */
  double ecc;

  /**
   * Square root of the semi-major axis of orbit [m^(1/2)]
   */
  double sqrta;

  /**
   * Longitude of ascending node of orbit plane at weekly epoch [rad]
   */
  double omega0;

  /**
   * Rate of right ascension [rad/s]
   */
  double omegadot;

  /**
   * Argument of perigee [rad]
   */
  double w;

  /**
   * Inclination [rad]
   */
  double inc;

  /**
   * Inclination first derivative [rad/s]
   */
  double inc_dot;

  /**
   * Polynomial clock correction coefficient (clock bias) [s]
   */
  double af0;

  /**
   * Polynomial clock correction coefficient (clock drift) [s/s]
   */
  double af1;

  /**
   * Polynomial clock correction coefficient (rate of clock drift) [s/s^2]
   */
  double af2;

  /**
   * Time of week [s]
   */
  double toe_tow;

  /**
   * Week number [week]
   */
  u16 toe_wn;

  /**
   * Clock reference time of week [s]
   */
  double toc_tow;

  /**
   * Clock reference week number [week]
   */
  u16 toc_wn;

  /**
   * Is valid?
   */
  u8 valid;

  /**
   * Satellite is healthy?
   */
  u8 healthy;

  /**
   * GNSS signal identifier
   */
  sbp_gnss_signal_dep_t sid;

  /**
   * Issue of ephemeris data
   */
  u8 iode;

  /**
   * Issue of clock data
   */
  u16 iodc;

  /**
   * Reserved field
   */
  u32 reserved;
} sbp_msg_ephemeris_dep_d_t;

/**
 * Get encoded size of an instance of sbp_msg_ephemeris_dep_d_t
 *
 * @param msg sbp_msg_ephemeris_dep_d_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_msg_ephemeris_dep_d_t(
    const sbp_msg_ephemeris_dep_d_t *msg);

/**
 * Encode an instance of sbp_msg_ephemeris_dep_d_t to wire representation
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
 * @param msg Instance of sbp_msg_ephemeris_dep_d_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_msg_ephemeris_dep_d_t(uint8_t *buf, uint8_t len,
                                        uint8_t *n_written,
                                        const sbp_msg_ephemeris_dep_d_t *msg);

/**
 * Decode an instance of sbp_msg_ephemeris_dep_d_t from wire representation
 *
 * This function decodes the wire representation of a sbp_msg_ephemeris_dep_d_t
 * message to the given instance. The caller must specify the length of the
 * buffer in the \p len parameter. If non-null the number of bytes read from the
 * buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_msg_ephemeris_dep_d_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_msg_ephemeris_dep_d_t(const uint8_t *buf, uint8_t len,
                                        uint8_t *n_read,
                                        sbp_msg_ephemeris_dep_d_t *msg);
/**
 * Send an instance of sbp_msg_ephemeris_dep_d_t with the given write function
 *
 * An equivalent of #sbp_send_message which operates specifically on
 * sbp_msg_ephemeris_dep_d_t
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
s8 sbp_send_sbp_msg_ephemeris_dep_d_t(struct sbp_state *s, u16 sender_id,
                                      const sbp_msg_ephemeris_dep_d_t *msg,
                                      s32 (*write)(u8 *buff, u32 n,
                                                   void *context));

/**
 * Compare two instances of sbp_msg_ephemeris_dep_d_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_ephemeris_dep_d_t instance
 * @param b sbp_msg_ephemeris_dep_d_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_msg_ephemeris_dep_d_t(const sbp_msg_ephemeris_dep_d_t *a,
                                      const sbp_msg_ephemeris_dep_d_t *b);

/*
 *
 *
 *
 ******************************************************************************
 *
 * SBP_MSG_EPHEMERIS_DEP_A
 *
 *****************************************************************************/
/** Deprecated
 *
 * Deprecated.
 */
typedef struct {
  /**
   * Group delay differential between L1 and L2 [s]
   */
  double tgd;

  /**
   * Amplitude of the sine harmonic correction term to the orbit radius [m]
   */
  double c_rs;

  /**
   * Amplitude of the cosine harmonic correction term to the orbit radius [m]
   */
  double c_rc;

  /**
   * Amplitude of the cosine harmonic correction term to the argument of
   * latitude [rad]
   */
  double c_uc;

  /**
   * Amplitude of the sine harmonic correction term to the argument of latitude
   * [rad]
   */
  double c_us;

  /**
   * Amplitude of the cosine harmonic correction term to the angle of
   * inclination [rad]
   */
  double c_ic;

  /**
   * Amplitude of the sine harmonic correction term to the angle of inclination
   * [rad]
   */
  double c_is;

  /**
   * Mean motion difference [rad/s]
   */
  double dn;

  /**
   * Mean anomaly at reference time [rad]
   */
  double m0;

  /**
   * Eccentricity of satellite orbit
   */
  double ecc;

  /**
   * Square root of the semi-major axis of orbit [m^(1/2)]
   */
  double sqrta;

  /**
   * Longitude of ascending node of orbit plane at weekly epoch [rad]
   */
  double omega0;

  /**
   * Rate of right ascension [rad/s]
   */
  double omegadot;

  /**
   * Argument of perigee [rad]
   */
  double w;

  /**
   * Inclination [rad]
   */
  double inc;

  /**
   * Inclination first derivative [rad/s]
   */
  double inc_dot;

  /**
   * Polynomial clock correction coefficient (clock bias) [s]
   */
  double af0;

  /**
   * Polynomial clock correction coefficient (clock drift) [s/s]
   */
  double af1;

  /**
   * Polynomial clock correction coefficient (rate of clock drift) [s/s^2]
   */
  double af2;

  /**
   * Time of week [s]
   */
  double toe_tow;

  /**
   * Week number [week]
   */
  u16 toe_wn;

  /**
   * Clock reference time of week [s]
   */
  double toc_tow;

  /**
   * Clock reference week number [week]
   */
  u16 toc_wn;

  /**
   * Is valid?
   */
  u8 valid;

  /**
   * Satellite is healthy?
   */
  u8 healthy;

  /**
   * PRN being tracked
   */
  u8 prn;
} sbp_msg_ephemeris_dep_a_t;

/**
 * Get encoded size of an instance of sbp_msg_ephemeris_dep_a_t
 *
 * @param msg sbp_msg_ephemeris_dep_a_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_msg_ephemeris_dep_a_t(
    const sbp_msg_ephemeris_dep_a_t *msg);

/**
 * Encode an instance of sbp_msg_ephemeris_dep_a_t to wire representation
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
 * @param msg Instance of sbp_msg_ephemeris_dep_a_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_msg_ephemeris_dep_a_t(uint8_t *buf, uint8_t len,
                                        uint8_t *n_written,
                                        const sbp_msg_ephemeris_dep_a_t *msg);

/**
 * Decode an instance of sbp_msg_ephemeris_dep_a_t from wire representation
 *
 * This function decodes the wire representation of a sbp_msg_ephemeris_dep_a_t
 * message to the given instance. The caller must specify the length of the
 * buffer in the \p len parameter. If non-null the number of bytes read from the
 * buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_msg_ephemeris_dep_a_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_msg_ephemeris_dep_a_t(const uint8_t *buf, uint8_t len,
                                        uint8_t *n_read,
                                        sbp_msg_ephemeris_dep_a_t *msg);
/**
 * Send an instance of sbp_msg_ephemeris_dep_a_t with the given write function
 *
 * An equivalent of #sbp_send_message which operates specifically on
 * sbp_msg_ephemeris_dep_a_t
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
s8 sbp_send_sbp_msg_ephemeris_dep_a_t(struct sbp_state *s, u16 sender_id,
                                      const sbp_msg_ephemeris_dep_a_t *msg,
                                      s32 (*write)(u8 *buff, u32 n,
                                                   void *context));

/**
 * Compare two instances of sbp_msg_ephemeris_dep_a_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_ephemeris_dep_a_t instance
 * @param b sbp_msg_ephemeris_dep_a_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_msg_ephemeris_dep_a_t(const sbp_msg_ephemeris_dep_a_t *a,
                                      const sbp_msg_ephemeris_dep_a_t *b);

/*
 *
 *
 *
 ******************************************************************************
 *
 * SBP_MSG_EPHEMERIS_DEP_B
 *
 *****************************************************************************/
/** Deprecated
 *
 * Deprecated.
 */
typedef struct {
  /**
   * Group delay differential between L1 and L2 [s]
   */
  double tgd;

  /**
   * Amplitude of the sine harmonic correction term to the orbit radius [m]
   */
  double c_rs;

  /**
   * Amplitude of the cosine harmonic correction term to the orbit radius [m]
   */
  double c_rc;

  /**
   * Amplitude of the cosine harmonic correction term to the argument of
   * latitude [rad]
   */
  double c_uc;

  /**
   * Amplitude of the sine harmonic correction term to the argument of latitude
   * [rad]
   */
  double c_us;

  /**
   * Amplitude of the cosine harmonic correction term to the angle of
   * inclination [rad]
   */
  double c_ic;

  /**
   * Amplitude of the sine harmonic correction term to the angle of inclination
   * [rad]
   */
  double c_is;

  /**
   * Mean motion difference [rad/s]
   */
  double dn;

  /**
   * Mean anomaly at reference time [rad]
   */
  double m0;

  /**
   * Eccentricity of satellite orbit
   */
  double ecc;

  /**
   * Square root of the semi-major axis of orbit [m^(1/2)]
   */
  double sqrta;

  /**
   * Longitude of ascending node of orbit plane at weekly epoch [rad]
   */
  double omega0;

  /**
   * Rate of right ascension [rad/s]
   */
  double omegadot;

  /**
   * Argument of perigee [rad]
   */
  double w;

  /**
   * Inclination [rad]
   */
  double inc;

  /**
   * Inclination first derivative [rad/s]
   */
  double inc_dot;

  /**
   * Polynomial clock correction coefficient (clock bias) [s]
   */
  double af0;

  /**
   * Polynomial clock correction coefficient (clock drift) [s/s]
   */
  double af1;

  /**
   * Polynomial clock correction coefficient (rate of clock drift) [s/s^2]
   */
  double af2;

  /**
   * Time of week [s]
   */
  double toe_tow;

  /**
   * Week number [week]
   */
  u16 toe_wn;

  /**
   * Clock reference time of week [s]
   */
  double toc_tow;

  /**
   * Clock reference week number [week]
   */
  u16 toc_wn;

  /**
   * Is valid?
   */
  u8 valid;

  /**
   * Satellite is healthy?
   */
  u8 healthy;

  /**
   * PRN being tracked
   */
  u8 prn;

  /**
   * Issue of ephemeris data
   */
  u8 iode;
} sbp_msg_ephemeris_dep_b_t;

/**
 * Get encoded size of an instance of sbp_msg_ephemeris_dep_b_t
 *
 * @param msg sbp_msg_ephemeris_dep_b_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_msg_ephemeris_dep_b_t(
    const sbp_msg_ephemeris_dep_b_t *msg);

/**
 * Encode an instance of sbp_msg_ephemeris_dep_b_t to wire representation
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
 * @param msg Instance of sbp_msg_ephemeris_dep_b_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_msg_ephemeris_dep_b_t(uint8_t *buf, uint8_t len,
                                        uint8_t *n_written,
                                        const sbp_msg_ephemeris_dep_b_t *msg);

/**
 * Decode an instance of sbp_msg_ephemeris_dep_b_t from wire representation
 *
 * This function decodes the wire representation of a sbp_msg_ephemeris_dep_b_t
 * message to the given instance. The caller must specify the length of the
 * buffer in the \p len parameter. If non-null the number of bytes read from the
 * buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_msg_ephemeris_dep_b_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_msg_ephemeris_dep_b_t(const uint8_t *buf, uint8_t len,
                                        uint8_t *n_read,
                                        sbp_msg_ephemeris_dep_b_t *msg);
/**
 * Send an instance of sbp_msg_ephemeris_dep_b_t with the given write function
 *
 * An equivalent of #sbp_send_message which operates specifically on
 * sbp_msg_ephemeris_dep_b_t
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
s8 sbp_send_sbp_msg_ephemeris_dep_b_t(struct sbp_state *s, u16 sender_id,
                                      const sbp_msg_ephemeris_dep_b_t *msg,
                                      s32 (*write)(u8 *buff, u32 n,
                                                   void *context));

/**
 * Compare two instances of sbp_msg_ephemeris_dep_b_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_ephemeris_dep_b_t instance
 * @param b sbp_msg_ephemeris_dep_b_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_msg_ephemeris_dep_b_t(const sbp_msg_ephemeris_dep_b_t *a,
                                      const sbp_msg_ephemeris_dep_b_t *b);

/*
 *
 *
 *
 ******************************************************************************
 *
 * SBP_MSG_EPHEMERIS_DEP_C
 *
 *****************************************************************************/
/** Satellite broadcast ephemeris
 *
 * The ephemeris message returns a set of satellite orbit parameters that is
 * used to calculate GPS satellite position, velocity, and clock offset. Please
 * see the Navstar GPS Space Segment/Navigation user interfaces (ICD-GPS-200,
 * Table 20-III) for more details.
 */
typedef struct {
  /**
   * Group delay differential between L1 and L2 [s]
   */
  double tgd;

  /**
   * Amplitude of the sine harmonic correction term to the orbit radius [m]
   */
  double c_rs;

  /**
   * Amplitude of the cosine harmonic correction term to the orbit radius [m]
   */
  double c_rc;

  /**
   * Amplitude of the cosine harmonic correction term to the argument of
   * latitude [rad]
   */
  double c_uc;

  /**
   * Amplitude of the sine harmonic correction term to the argument of latitude
   * [rad]
   */
  double c_us;

  /**
   * Amplitude of the cosine harmonic correction term to the angle of
   * inclination [rad]
   */
  double c_ic;

  /**
   * Amplitude of the sine harmonic correction term to the angle of inclination
   * [rad]
   */
  double c_is;

  /**
   * Mean motion difference [rad/s]
   */
  double dn;

  /**
   * Mean anomaly at reference time [rad]
   */
  double m0;

  /**
   * Eccentricity of satellite orbit
   */
  double ecc;

  /**
   * Square root of the semi-major axis of orbit [m^(1/2)]
   */
  double sqrta;

  /**
   * Longitude of ascending node of orbit plane at weekly epoch [rad]
   */
  double omega0;

  /**
   * Rate of right ascension [rad/s]
   */
  double omegadot;

  /**
   * Argument of perigee [rad]
   */
  double w;

  /**
   * Inclination [rad]
   */
  double inc;

  /**
   * Inclination first derivative [rad/s]
   */
  double inc_dot;

  /**
   * Polynomial clock correction coefficient (clock bias) [s]
   */
  double af0;

  /**
   * Polynomial clock correction coefficient (clock drift) [s/s]
   */
  double af1;

  /**
   * Polynomial clock correction coefficient (rate of clock drift) [s/s^2]
   */
  double af2;

  /**
   * Time of week [s]
   */
  double toe_tow;

  /**
   * Week number [week]
   */
  u16 toe_wn;

  /**
   * Clock reference time of week [s]
   */
  double toc_tow;

  /**
   * Clock reference week number [week]
   */
  u16 toc_wn;

  /**
   * Is valid?
   */
  u8 valid;

  /**
   * Satellite is healthy?
   */
  u8 healthy;

  /**
   * GNSS signal identifier
   */
  sbp_gnss_signal_dep_t sid;

  /**
   * Issue of ephemeris data
   */
  u8 iode;

  /**
   * Issue of clock data
   */
  u16 iodc;

  /**
   * Reserved field
   */
  u32 reserved;
} sbp_msg_ephemeris_dep_c_t;

/**
 * Get encoded size of an instance of sbp_msg_ephemeris_dep_c_t
 *
 * @param msg sbp_msg_ephemeris_dep_c_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_msg_ephemeris_dep_c_t(
    const sbp_msg_ephemeris_dep_c_t *msg);

/**
 * Encode an instance of sbp_msg_ephemeris_dep_c_t to wire representation
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
 * @param msg Instance of sbp_msg_ephemeris_dep_c_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_msg_ephemeris_dep_c_t(uint8_t *buf, uint8_t len,
                                        uint8_t *n_written,
                                        const sbp_msg_ephemeris_dep_c_t *msg);

/**
 * Decode an instance of sbp_msg_ephemeris_dep_c_t from wire representation
 *
 * This function decodes the wire representation of a sbp_msg_ephemeris_dep_c_t
 * message to the given instance. The caller must specify the length of the
 * buffer in the \p len parameter. If non-null the number of bytes read from the
 * buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_msg_ephemeris_dep_c_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_msg_ephemeris_dep_c_t(const uint8_t *buf, uint8_t len,
                                        uint8_t *n_read,
                                        sbp_msg_ephemeris_dep_c_t *msg);
/**
 * Send an instance of sbp_msg_ephemeris_dep_c_t with the given write function
 *
 * An equivalent of #sbp_send_message which operates specifically on
 * sbp_msg_ephemeris_dep_c_t
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
s8 sbp_send_sbp_msg_ephemeris_dep_c_t(struct sbp_state *s, u16 sender_id,
                                      const sbp_msg_ephemeris_dep_c_t *msg,
                                      s32 (*write)(u8 *buff, u32 n,
                                                   void *context));

/**
 * Compare two instances of sbp_msg_ephemeris_dep_c_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_ephemeris_dep_c_t instance
 * @param b sbp_msg_ephemeris_dep_c_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_msg_ephemeris_dep_c_t(const sbp_msg_ephemeris_dep_c_t *a,
                                      const sbp_msg_ephemeris_dep_c_t *b);

/*
 *
 *
 *
 ******************************************************************************
 *
 * SBP_OBSERVATIONHEADERDEP
 *
 *****************************************************************************/
/** Header for observation message
 *
 * Header of a GPS observation message.
 */
typedef struct {
  /**
   * GPS time of this observation
   */
  sbp_gps_time_dep_t t;

  /**
   * Total number of observations. First nibble is the size of the sequence (n),
   * second nibble is the zero-indexed counter (ith packet of n)
   */
  u8 n_obs;
} sbp_observation_header_dep_t;

/**
 * Get encoded size of an instance of sbp_observation_header_dep_t
 *
 * @param msg sbp_observation_header_dep_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_observation_header_dep_t(
    const sbp_observation_header_dep_t *msg);

/**
 * Encode an instance of sbp_observation_header_dep_t to wire representation
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
 * @param msg Instance of sbp_observation_header_dep_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_observation_header_dep_t(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_observation_header_dep_t *msg);

/**
 * Decode an instance of sbp_observation_header_dep_t from wire representation
 *
 * This function decodes the wire representation of a
 * sbp_observation_header_dep_t message to the given instance. The caller must
 * specify the length of the buffer in the \p len parameter. If non-null the
 * number of bytes read from the buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_observation_header_dep_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_observation_header_dep_t(const uint8_t *buf, uint8_t len,
                                           uint8_t *n_read,
                                           sbp_observation_header_dep_t *msg);

/**
 * Compare two instances of sbp_observation_header_dep_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_observation_header_dep_t instance
 * @param b sbp_observation_header_dep_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_observation_header_dep_t(const sbp_observation_header_dep_t *a,
                                         const sbp_observation_header_dep_t *b);

/*
 *
 *
 *
 ******************************************************************************
 *
 * SBP_CARRIERPHASEDEPA
 *
 *****************************************************************************/
/** GPS carrier phase measurement
 *
 * Carrier phase measurement in cycles represented as a 40-bit fixed point
 * number with Q32.8 layout, i.e. 32-bits of whole cycles and 8-bits of
 * fractional cycles. This has the opposite sign convention than a typical GPS
 * receiver and the phase has the opposite sign as the pseudorange.
 */
typedef struct {
  /**
   * Carrier phase whole cycles [cycles]
   */
  s32 i;

  /**
   * Carrier phase fractional part [cycles / 256]
   */
  u8 f;
} sbp_carrier_phase_dep_a_t;

/**
 * Get encoded size of an instance of sbp_carrier_phase_dep_a_t
 *
 * @param msg sbp_carrier_phase_dep_a_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_carrier_phase_dep_a_t(
    const sbp_carrier_phase_dep_a_t *msg);

/**
 * Encode an instance of sbp_carrier_phase_dep_a_t to wire representation
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
 * @param msg Instance of sbp_carrier_phase_dep_a_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_carrier_phase_dep_a_t(uint8_t *buf, uint8_t len,
                                        uint8_t *n_written,
                                        const sbp_carrier_phase_dep_a_t *msg);

/**
 * Decode an instance of sbp_carrier_phase_dep_a_t from wire representation
 *
 * This function decodes the wire representation of a sbp_carrier_phase_dep_a_t
 * message to the given instance. The caller must specify the length of the
 * buffer in the \p len parameter. If non-null the number of bytes read from the
 * buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_carrier_phase_dep_a_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_carrier_phase_dep_a_t(const uint8_t *buf, uint8_t len,
                                        uint8_t *n_read,
                                        sbp_carrier_phase_dep_a_t *msg);

/**
 * Compare two instances of sbp_carrier_phase_dep_a_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_carrier_phase_dep_a_t instance
 * @param b sbp_carrier_phase_dep_a_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_carrier_phase_dep_a_t(const sbp_carrier_phase_dep_a_t *a,
                                      const sbp_carrier_phase_dep_a_t *b);

/*
 *
 *
 *
 ******************************************************************************
 *
 * SBP_PACKEDOBSCONTENTDEPA
 *
 *****************************************************************************/
/** Deprecated
 *
 * Deprecated.
 */
typedef struct {
  /**
   * Pseudorange observation [cm]
   */
  u32 P;

  /**
   * Carrier phase observation with opposite sign from typical convention
   */
  sbp_carrier_phase_dep_a_t L;

  /**
   * Carrier-to-Noise density [dB Hz / 4]
   */
  u8 cn0;

  /**
   * Lock indicator. This value changes whenever a satellite signal has lost and
   * regained lock, indicating that the carrier phase ambiguity may have
   * changed.
   */
  u16 lock;

  /**
   * PRN-1 identifier of the satellite signal
   */
  u8 prn;
} sbp_packed_obs_content_dep_a_t;

/**
 * Get encoded size of an instance of sbp_packed_obs_content_dep_a_t
 *
 * @param msg sbp_packed_obs_content_dep_a_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_packed_obs_content_dep_a_t(
    const sbp_packed_obs_content_dep_a_t *msg);

/**
 * Encode an instance of sbp_packed_obs_content_dep_a_t to wire representation
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
 * @param msg Instance of sbp_packed_obs_content_dep_a_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_packed_obs_content_dep_a_t(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_packed_obs_content_dep_a_t *msg);

/**
 * Decode an instance of sbp_packed_obs_content_dep_a_t from wire representation
 *
 * This function decodes the wire representation of a
 * sbp_packed_obs_content_dep_a_t message to the given instance. The caller must
 * specify the length of the buffer in the \p len parameter. If non-null the
 * number of bytes read from the buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_packed_obs_content_dep_a_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_packed_obs_content_dep_a_t(
    const uint8_t *buf, uint8_t len, uint8_t *n_read,
    sbp_packed_obs_content_dep_a_t *msg);

/**
 * Compare two instances of sbp_packed_obs_content_dep_a_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_packed_obs_content_dep_a_t instance
 * @param b sbp_packed_obs_content_dep_a_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_packed_obs_content_dep_a_t(
    const sbp_packed_obs_content_dep_a_t *a,
    const sbp_packed_obs_content_dep_a_t *b);

/*
 *
 *
 *
 ******************************************************************************
 *
 * SBP_PACKEDOBSCONTENTDEPB
 *
 *****************************************************************************/
/** GPS observations for a particular satellite signal
 *
 * Pseudorange and carrier phase observation for a satellite being tracked.
 * Pseudoranges are referenced to a nominal pseudorange.
 */
typedef struct {
  /**
   * Pseudorange observation [cm]
   */
  u32 P;

  /**
   * Carrier phase observation with opposite sign from typical convention.
   */
  sbp_carrier_phase_dep_a_t L;

  /**
   * Carrier-to-Noise density [dB Hz / 4]
   */
  u8 cn0;

  /**
   * Lock indicator. This value changes whenever a satellite signal has lost and
   * regained lock, indicating that the carrier phase ambiguity may have
   * changed.
   */
  u16 lock;

  /**
   * GNSS signal identifier
   */
  sbp_gnss_signal_dep_t sid;
} sbp_packed_obs_content_dep_b_t;

/**
 * Get encoded size of an instance of sbp_packed_obs_content_dep_b_t
 *
 * @param msg sbp_packed_obs_content_dep_b_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_packed_obs_content_dep_b_t(
    const sbp_packed_obs_content_dep_b_t *msg);

/**
 * Encode an instance of sbp_packed_obs_content_dep_b_t to wire representation
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
 * @param msg Instance of sbp_packed_obs_content_dep_b_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_packed_obs_content_dep_b_t(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_packed_obs_content_dep_b_t *msg);

/**
 * Decode an instance of sbp_packed_obs_content_dep_b_t from wire representation
 *
 * This function decodes the wire representation of a
 * sbp_packed_obs_content_dep_b_t message to the given instance. The caller must
 * specify the length of the buffer in the \p len parameter. If non-null the
 * number of bytes read from the buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_packed_obs_content_dep_b_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_packed_obs_content_dep_b_t(
    const uint8_t *buf, uint8_t len, uint8_t *n_read,
    sbp_packed_obs_content_dep_b_t *msg);

/**
 * Compare two instances of sbp_packed_obs_content_dep_b_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_packed_obs_content_dep_b_t instance
 * @param b sbp_packed_obs_content_dep_b_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_packed_obs_content_dep_b_t(
    const sbp_packed_obs_content_dep_b_t *a,
    const sbp_packed_obs_content_dep_b_t *b);

/*
 *
 *
 *
 ******************************************************************************
 *
 * SBP_PACKEDOBSCONTENTDEPC
 *
 *****************************************************************************/
/** GPS observations for a particular satellite signal
 *
 * Pseudorange and carrier phase observation for a satellite being tracked. The
 * observations are be interoperable with 3rd party receivers and conform with
 * typical RTCMv3 GNSS observations.
 */
typedef struct {
  /**
   * Pseudorange observation [2 cm]
   */
  u32 P;

  /**
   * Carrier phase observation with typical sign convention. [cycles]
   */
  sbp_carrier_phase_t L;

  /**
   * Carrier-to-Noise density [dB Hz / 4]
   */
  u8 cn0;

  /**
   * Lock indicator. This value changes whenever a satellite signal has lost and
   * regained lock, indicating that the carrier phase ambiguity may have
   * changed.
   */
  u16 lock;

  /**
   * GNSS signal identifier
   */
  sbp_gnss_signal_dep_t sid;
} sbp_packed_obs_content_dep_c_t;

/**
 * Get encoded size of an instance of sbp_packed_obs_content_dep_c_t
 *
 * @param msg sbp_packed_obs_content_dep_c_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_packed_obs_content_dep_c_t(
    const sbp_packed_obs_content_dep_c_t *msg);

/**
 * Encode an instance of sbp_packed_obs_content_dep_c_t to wire representation
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
 * @param msg Instance of sbp_packed_obs_content_dep_c_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_packed_obs_content_dep_c_t(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_packed_obs_content_dep_c_t *msg);

/**
 * Decode an instance of sbp_packed_obs_content_dep_c_t from wire representation
 *
 * This function decodes the wire representation of a
 * sbp_packed_obs_content_dep_c_t message to the given instance. The caller must
 * specify the length of the buffer in the \p len parameter. If non-null the
 * number of bytes read from the buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_packed_obs_content_dep_c_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_packed_obs_content_dep_c_t(
    const uint8_t *buf, uint8_t len, uint8_t *n_read,
    sbp_packed_obs_content_dep_c_t *msg);

/**
 * Compare two instances of sbp_packed_obs_content_dep_c_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_packed_obs_content_dep_c_t instance
 * @param b sbp_packed_obs_content_dep_c_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_packed_obs_content_dep_c_t(
    const sbp_packed_obs_content_dep_c_t *a,
    const sbp_packed_obs_content_dep_c_t *b);

/*
 *
 *
 *
 ******************************************************************************
 *
 * SBP_MSG_OBS_DEP_A
 *
 *****************************************************************************/
/** Deprecated
 *
 * Deprecated.
 */
typedef struct {
  /**
   * Header of a GPS observation message
   */
  sbp_observation_header_dep_t header;

  /**
   * Pseudorange and carrier phase observation for a satellite being tracked.
   */
  sbp_packed_obs_content_dep_a_t obs[19];
  /**
   * Number of elements in obs
   *
   * When sending a message fill in this field with the number elements set in
   * obs before calling an appropriate libsbp send function
   *
   * When receiving a message query this field for the number of elements in
   * obs. The value of any elements beyond the index specified in this field is
   * undefined
   */
  u8 n_obs;
} sbp_msg_obs_dep_a_t;

/**
 * Get encoded size of an instance of sbp_msg_obs_dep_a_t
 *
 * @param msg sbp_msg_obs_dep_a_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_msg_obs_dep_a_t(const sbp_msg_obs_dep_a_t *msg);

/**
 * Encode an instance of sbp_msg_obs_dep_a_t to wire representation
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
 * @param msg Instance of sbp_msg_obs_dep_a_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_msg_obs_dep_a_t(uint8_t *buf, uint8_t len, uint8_t *n_written,
                                  const sbp_msg_obs_dep_a_t *msg);

/**
 * Decode an instance of sbp_msg_obs_dep_a_t from wire representation
 *
 * This function decodes the wire representation of a sbp_msg_obs_dep_a_t
 * message to the given instance. The caller must specify the length of the
 * buffer in the \p len parameter. If non-null the number of bytes read from the
 * buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_msg_obs_dep_a_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_msg_obs_dep_a_t(const uint8_t *buf, uint8_t len,
                                  uint8_t *n_read, sbp_msg_obs_dep_a_t *msg);
/**
 * Send an instance of sbp_msg_obs_dep_a_t with the given write function
 *
 * An equivalent of #sbp_send_message which operates specifically on
 * sbp_msg_obs_dep_a_t
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
s8 sbp_send_sbp_msg_obs_dep_a_t(struct sbp_state *s, u16 sender_id,
                                const sbp_msg_obs_dep_a_t *msg,
                                s32 (*write)(u8 *buff, u32 n, void *context));

/**
 * Compare two instances of sbp_msg_obs_dep_a_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_obs_dep_a_t instance
 * @param b sbp_msg_obs_dep_a_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_msg_obs_dep_a_t(const sbp_msg_obs_dep_a_t *a,
                                const sbp_msg_obs_dep_a_t *b);

/*
 *
 *
 *
 ******************************************************************************
 *
 * SBP_MSG_OBS_DEP_B
 *
 *****************************************************************************/
/** Deprecated
 *
 * This observation message has been deprecated in favor of observations that
 * are more interoperable. This message should be used for observations
 * referenced to a nominal pseudorange which are not interoperable with most 3rd
 * party GNSS receievers or typical RTCMv3 observations.
 */
typedef struct {
  /**
   * Header of a GPS observation message
   */
  sbp_observation_header_dep_t header;

  /**
   * Pseudorange and carrier phase observation for a satellite being tracked.
   */
  sbp_packed_obs_content_dep_b_t obs[15];
  /**
   * Number of elements in obs
   *
   * When sending a message fill in this field with the number elements set in
   * obs before calling an appropriate libsbp send function
   *
   * When receiving a message query this field for the number of elements in
   * obs. The value of any elements beyond the index specified in this field is
   * undefined
   */
  u8 n_obs;
} sbp_msg_obs_dep_b_t;

/**
 * Get encoded size of an instance of sbp_msg_obs_dep_b_t
 *
 * @param msg sbp_msg_obs_dep_b_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_msg_obs_dep_b_t(const sbp_msg_obs_dep_b_t *msg);

/**
 * Encode an instance of sbp_msg_obs_dep_b_t to wire representation
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
 * @param msg Instance of sbp_msg_obs_dep_b_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_msg_obs_dep_b_t(uint8_t *buf, uint8_t len, uint8_t *n_written,
                                  const sbp_msg_obs_dep_b_t *msg);

/**
 * Decode an instance of sbp_msg_obs_dep_b_t from wire representation
 *
 * This function decodes the wire representation of a sbp_msg_obs_dep_b_t
 * message to the given instance. The caller must specify the length of the
 * buffer in the \p len parameter. If non-null the number of bytes read from the
 * buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_msg_obs_dep_b_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_msg_obs_dep_b_t(const uint8_t *buf, uint8_t len,
                                  uint8_t *n_read, sbp_msg_obs_dep_b_t *msg);
/**
 * Send an instance of sbp_msg_obs_dep_b_t with the given write function
 *
 * An equivalent of #sbp_send_message which operates specifically on
 * sbp_msg_obs_dep_b_t
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
s8 sbp_send_sbp_msg_obs_dep_b_t(struct sbp_state *s, u16 sender_id,
                                const sbp_msg_obs_dep_b_t *msg,
                                s32 (*write)(u8 *buff, u32 n, void *context));

/**
 * Compare two instances of sbp_msg_obs_dep_b_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_obs_dep_b_t instance
 * @param b sbp_msg_obs_dep_b_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_msg_obs_dep_b_t(const sbp_msg_obs_dep_b_t *a,
                                const sbp_msg_obs_dep_b_t *b);

/*
 *
 *
 *
 ******************************************************************************
 *
 * SBP_MSG_OBS_DEP_C
 *
 *****************************************************************************/
/** Deprecated
 *
 * The GPS observations message reports all the raw pseudorange and carrier
 * phase observations for the satellites being tracked by the device. Carrier
 * phase observation here is represented as a 40-bit fixed point number with
 * Q32.8 layout (i.e. 32-bits of whole cycles and 8-bits of fractional cycles).
 * The observations are interoperable with 3rd party receivers and conform with
 * typical RTCMv3 GNSS observations.
 */
typedef struct {
  /**
   * Header of a GPS observation message
   */
  sbp_observation_header_dep_t header;

  /**
   * Pseudorange and carrier phase observation for a satellite being tracked.
   */
  sbp_packed_obs_content_dep_c_t obs[15];
  /**
   * Number of elements in obs
   *
   * When sending a message fill in this field with the number elements set in
   * obs before calling an appropriate libsbp send function
   *
   * When receiving a message query this field for the number of elements in
   * obs. The value of any elements beyond the index specified in this field is
   * undefined
   */
  u8 n_obs;
} sbp_msg_obs_dep_c_t;

/**
 * Get encoded size of an instance of sbp_msg_obs_dep_c_t
 *
 * @param msg sbp_msg_obs_dep_c_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_msg_obs_dep_c_t(const sbp_msg_obs_dep_c_t *msg);

/**
 * Encode an instance of sbp_msg_obs_dep_c_t to wire representation
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
 * @param msg Instance of sbp_msg_obs_dep_c_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_msg_obs_dep_c_t(uint8_t *buf, uint8_t len, uint8_t *n_written,
                                  const sbp_msg_obs_dep_c_t *msg);

/**
 * Decode an instance of sbp_msg_obs_dep_c_t from wire representation
 *
 * This function decodes the wire representation of a sbp_msg_obs_dep_c_t
 * message to the given instance. The caller must specify the length of the
 * buffer in the \p len parameter. If non-null the number of bytes read from the
 * buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_msg_obs_dep_c_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_msg_obs_dep_c_t(const uint8_t *buf, uint8_t len,
                                  uint8_t *n_read, sbp_msg_obs_dep_c_t *msg);
/**
 * Send an instance of sbp_msg_obs_dep_c_t with the given write function
 *
 * An equivalent of #sbp_send_message which operates specifically on
 * sbp_msg_obs_dep_c_t
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
s8 sbp_send_sbp_msg_obs_dep_c_t(struct sbp_state *s, u16 sender_id,
                                const sbp_msg_obs_dep_c_t *msg,
                                s32 (*write)(u8 *buff, u32 n, void *context));

/**
 * Compare two instances of sbp_msg_obs_dep_c_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_obs_dep_c_t instance
 * @param b sbp_msg_obs_dep_c_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_msg_obs_dep_c_t(const sbp_msg_obs_dep_c_t *a,
                                const sbp_msg_obs_dep_c_t *b);

/*
 *
 *
 *
 ******************************************************************************
 *
 * SBP_MSG_IONO
 *
 *****************************************************************************/
/** Iono corrections
 *
 * The ionospheric parameters which allow the "L1 only" or "L2 only" user to
 * utilize the ionospheric model for computation of the ionospheric delay.
 * Please see ICD-GPS-200 (Chapter 20.3.3.5.1.7) for more details.
 */
typedef struct {
  /**
   * Navigation Message Correction Table Valitidy Time
   */
  sbp_gps_time_sec_t t_nmct;

  double a0;

  double a1;

  double a2;

  double a3;

  double b0;

  double b1;

  double b2;

  double b3;
} sbp_msg_iono_t;

/**
 * Get encoded size of an instance of sbp_msg_iono_t
 *
 * @param msg sbp_msg_iono_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_msg_iono_t(const sbp_msg_iono_t *msg);

/**
 * Encode an instance of sbp_msg_iono_t to wire representation
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
 * @param msg Instance of sbp_msg_iono_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_msg_iono_t(uint8_t *buf, uint8_t len, uint8_t *n_written,
                             const sbp_msg_iono_t *msg);

/**
 * Decode an instance of sbp_msg_iono_t from wire representation
 *
 * This function decodes the wire representation of a sbp_msg_iono_t message to
 * the given instance. The caller must specify the length of the buffer in the
 * \p len parameter. If non-null the number of bytes read from the buffer will
 * be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_msg_iono_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_msg_iono_t(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                             sbp_msg_iono_t *msg);
/**
 * Send an instance of sbp_msg_iono_t with the given write function
 *
 * An equivalent of #sbp_send_message which operates specifically on
 * sbp_msg_iono_t
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
s8 sbp_send_sbp_msg_iono_t(struct sbp_state *s, u16 sender_id,
                           const sbp_msg_iono_t *msg,
                           s32 (*write)(u8 *buff, u32 n, void *context));

/**
 * Compare two instances of sbp_msg_iono_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_iono_t instance
 * @param b sbp_msg_iono_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_msg_iono_t(const sbp_msg_iono_t *a, const sbp_msg_iono_t *b);

/*
 *
 *
 *
 ******************************************************************************
 *
 * SBP_MSG_SV_CONFIGURATION_GPS_DEP
 *
 *****************************************************************************/
/** L2C capability mask
 *
 * Please see ICD-GPS-200 (Chapter 20.3.3.5.1.4) for more details.
 */
typedef struct {
  /**
   * Navigation Message Correction Table Valitidy Time
   */
  sbp_gps_time_sec_t t_nmct;

  /**
   * L2C capability mask, SV32 bit being MSB, SV1 bit being LSB
   */
  u32 l2c_mask;
} sbp_msg_sv_configuration_gps_dep_t;

/**
 * Get encoded size of an instance of sbp_msg_sv_configuration_gps_dep_t
 *
 * @param msg sbp_msg_sv_configuration_gps_dep_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_msg_sv_configuration_gps_dep_t(
    const sbp_msg_sv_configuration_gps_dep_t *msg);

/**
 * Encode an instance of sbp_msg_sv_configuration_gps_dep_t to wire
 * representation
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
 * @param msg Instance of sbp_msg_sv_configuration_gps_dep_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_msg_sv_configuration_gps_dep_t(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_msg_sv_configuration_gps_dep_t *msg);

/**
 * Decode an instance of sbp_msg_sv_configuration_gps_dep_t from wire
 * representation
 *
 * This function decodes the wire representation of a
 * sbp_msg_sv_configuration_gps_dep_t message to the given instance. The caller
 * must specify the length of the buffer in the \p len parameter. If non-null
 * the number of bytes read from the buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_msg_sv_configuration_gps_dep_t
 * instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_msg_sv_configuration_gps_dep_t(
    const uint8_t *buf, uint8_t len, uint8_t *n_read,
    sbp_msg_sv_configuration_gps_dep_t *msg);
/**
 * Send an instance of sbp_msg_sv_configuration_gps_dep_t with the given write
 * function
 *
 * An equivalent of #sbp_send_message which operates specifically on
 * sbp_msg_sv_configuration_gps_dep_t
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
s8 sbp_send_sbp_msg_sv_configuration_gps_dep_t(
    struct sbp_state *s, u16 sender_id,
    const sbp_msg_sv_configuration_gps_dep_t *msg,
    s32 (*write)(u8 *buff, u32 n, void *context));

/**
 * Compare two instances of sbp_msg_sv_configuration_gps_dep_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_sv_configuration_gps_dep_t instance
 * @param b sbp_msg_sv_configuration_gps_dep_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_msg_sv_configuration_gps_dep_t(
    const sbp_msg_sv_configuration_gps_dep_t *a,
    const sbp_msg_sv_configuration_gps_dep_t *b);

/*
 *
 *
 *
 ******************************************************************************
 *
 * SBP_GNSSCAPB
 *
 *****************************************************************************/
typedef struct {
  /**
   * GPS SV active mask
   */
  u64 gps_active;

  /**
   * GPS L2C active mask
   */
  u64 gps_l2c;

  /**
   * GPS L5 active mask
   */
  u64 gps_l5;

  /**
   * GLO active mask
   */
  u32 glo_active;

  /**
   * GLO L2OF active mask
   */
  u32 glo_l2of;

  /**
   * GLO L3 active mask
   */
  u32 glo_l3;

  /**
   * SBAS active mask (PRNs 120..158, AN 7/62.2.2-18/18 Table B-23,
   * https://www.caat.or.th/wp-content/uploads/2018/03/SL-2018.18.E-1.pdf)
   */
  u64 sbas_active;

  /**
   * SBAS L5 active mask (PRNs 120..158, AN 7/62.2.2-18/18 Table B-23,
   * https://www.caat.or.th/wp-content/uploads/2018/03/SL-2018.18.E-1.pdf)
   */
  u64 sbas_l5;

  /**
   * BDS active mask
   */
  u64 bds_active;

  /**
   * BDS D2NAV active mask
   */
  u64 bds_d2nav;

  /**
   * BDS B2 active mask
   */
  u64 bds_b2;

  /**
   * BDS B2A active mask
   */
  u64 bds_b2a;

  /**
   * QZSS active mask
   */
  u32 qzss_active;

  /**
   * GAL active mask
   */
  u64 gal_active;

  /**
   * GAL E5 active mask
   */
  u64 gal_e5;
} sbp_gnss_capb_t;

/**
 * Get encoded size of an instance of sbp_gnss_capb_t
 *
 * @param msg sbp_gnss_capb_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_gnss_capb_t(const sbp_gnss_capb_t *msg);

/**
 * Encode an instance of sbp_gnss_capb_t to wire representation
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
 * @param msg Instance of sbp_gnss_capb_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_gnss_capb_t(uint8_t *buf, uint8_t len, uint8_t *n_written,
                              const sbp_gnss_capb_t *msg);

/**
 * Decode an instance of sbp_gnss_capb_t from wire representation
 *
 * This function decodes the wire representation of a sbp_gnss_capb_t message to
 * the given instance. The caller must specify the length of the buffer in the
 * \p len parameter. If non-null the number of bytes read from the buffer will
 * be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_gnss_capb_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_gnss_capb_t(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                              sbp_gnss_capb_t *msg);

/**
 * Compare two instances of sbp_gnss_capb_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_gnss_capb_t instance
 * @param b sbp_gnss_capb_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_gnss_capb_t(const sbp_gnss_capb_t *a, const sbp_gnss_capb_t *b);

/*
 *
 *
 *
 ******************************************************************************
 *
 * SBP_MSG_GNSS_CAPB
 *
 *****************************************************************************/
typedef struct {
  /**
   * Navigation Message Correction Table Validity Time
   */
  sbp_gps_time_sec_t t_nmct;

  /**
   * GNSS capabilities masks
   */
  sbp_gnss_capb_t gc;
} sbp_msg_gnss_capb_t;

/**
 * Get encoded size of an instance of sbp_msg_gnss_capb_t
 *
 * @param msg sbp_msg_gnss_capb_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_msg_gnss_capb_t(const sbp_msg_gnss_capb_t *msg);

/**
 * Encode an instance of sbp_msg_gnss_capb_t to wire representation
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
 * @param msg Instance of sbp_msg_gnss_capb_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_msg_gnss_capb_t(uint8_t *buf, uint8_t len, uint8_t *n_written,
                                  const sbp_msg_gnss_capb_t *msg);

/**
 * Decode an instance of sbp_msg_gnss_capb_t from wire representation
 *
 * This function decodes the wire representation of a sbp_msg_gnss_capb_t
 * message to the given instance. The caller must specify the length of the
 * buffer in the \p len parameter. If non-null the number of bytes read from the
 * buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_msg_gnss_capb_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_msg_gnss_capb_t(const uint8_t *buf, uint8_t len,
                                  uint8_t *n_read, sbp_msg_gnss_capb_t *msg);
/**
 * Send an instance of sbp_msg_gnss_capb_t with the given write function
 *
 * An equivalent of #sbp_send_message which operates specifically on
 * sbp_msg_gnss_capb_t
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
s8 sbp_send_sbp_msg_gnss_capb_t(struct sbp_state *s, u16 sender_id,
                                const sbp_msg_gnss_capb_t *msg,
                                s32 (*write)(u8 *buff, u32 n, void *context));

/**
 * Compare two instances of sbp_msg_gnss_capb_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_gnss_capb_t instance
 * @param b sbp_msg_gnss_capb_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_msg_gnss_capb_t(const sbp_msg_gnss_capb_t *a,
                                const sbp_msg_gnss_capb_t *b);

/*
 *
 *
 *
 ******************************************************************************
 *
 * SBP_MSG_GROUP_DELAY_DEP_A
 *
 *****************************************************************************/
/** Group Delay
 *
 * Please see ICD-GPS-200 (30.3.3.3.1.1) for more details.
 */
typedef struct {
  /**
   * Data Predict Time of Week
   */
  sbp_gps_time_dep_t t_op;

  /**
   * Satellite number
   */
  u8 prn;

  /**
   * bit-field indicating validity of the values, LSB indicating tgd validity
   * etc. 1 = value is valid, 0 = value is not valid.
   */
  u8 valid;

  s16 tgd;

  s16 isc_l1ca;

  s16 isc_l2c;
} sbp_msg_group_delay_dep_a_t;

/**
 * Get encoded size of an instance of sbp_msg_group_delay_dep_a_t
 *
 * @param msg sbp_msg_group_delay_dep_a_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_msg_group_delay_dep_a_t(
    const sbp_msg_group_delay_dep_a_t *msg);

/**
 * Encode an instance of sbp_msg_group_delay_dep_a_t to wire representation
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
 * @param msg Instance of sbp_msg_group_delay_dep_a_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_msg_group_delay_dep_a_t(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_msg_group_delay_dep_a_t *msg);

/**
 * Decode an instance of sbp_msg_group_delay_dep_a_t from wire representation
 *
 * This function decodes the wire representation of a
 * sbp_msg_group_delay_dep_a_t message to the given instance. The caller must
 * specify the length of the buffer in the \p len parameter. If non-null the
 * number of bytes read from the buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_msg_group_delay_dep_a_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_msg_group_delay_dep_a_t(const uint8_t *buf, uint8_t len,
                                          uint8_t *n_read,
                                          sbp_msg_group_delay_dep_a_t *msg);
/**
 * Send an instance of sbp_msg_group_delay_dep_a_t with the given write function
 *
 * An equivalent of #sbp_send_message which operates specifically on
 * sbp_msg_group_delay_dep_a_t
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
s8 sbp_send_sbp_msg_group_delay_dep_a_t(struct sbp_state *s, u16 sender_id,
                                        const sbp_msg_group_delay_dep_a_t *msg,
                                        s32 (*write)(u8 *buff, u32 n,
                                                     void *context));

/**
 * Compare two instances of sbp_msg_group_delay_dep_a_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_group_delay_dep_a_t instance
 * @param b sbp_msg_group_delay_dep_a_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_msg_group_delay_dep_a_t(const sbp_msg_group_delay_dep_a_t *a,
                                        const sbp_msg_group_delay_dep_a_t *b);

/*
 *
 *
 *
 ******************************************************************************
 *
 * SBP_MSG_GROUP_DELAY_DEP_B
 *
 *****************************************************************************/
/** Group Delay
 *
 * Please see ICD-GPS-200 (30.3.3.3.1.1) for more details.
 */
typedef struct {
  /**
   * Data Predict Time of Week
   */
  sbp_gps_time_sec_t t_op;

  /**
   * GNSS signal identifier
   */
  sbp_gnss_signal_dep_t sid;

  /**
   * bit-field indicating validity of the values, LSB indicating tgd validity
   * etc. 1 = value is valid, 0 = value is not valid.
   */
  u8 valid;

  s16 tgd;

  s16 isc_l1ca;

  s16 isc_l2c;
} sbp_msg_group_delay_dep_b_t;

/**
 * Get encoded size of an instance of sbp_msg_group_delay_dep_b_t
 *
 * @param msg sbp_msg_group_delay_dep_b_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_msg_group_delay_dep_b_t(
    const sbp_msg_group_delay_dep_b_t *msg);

/**
 * Encode an instance of sbp_msg_group_delay_dep_b_t to wire representation
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
 * @param msg Instance of sbp_msg_group_delay_dep_b_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_msg_group_delay_dep_b_t(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_msg_group_delay_dep_b_t *msg);

/**
 * Decode an instance of sbp_msg_group_delay_dep_b_t from wire representation
 *
 * This function decodes the wire representation of a
 * sbp_msg_group_delay_dep_b_t message to the given instance. The caller must
 * specify the length of the buffer in the \p len parameter. If non-null the
 * number of bytes read from the buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_msg_group_delay_dep_b_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_msg_group_delay_dep_b_t(const uint8_t *buf, uint8_t len,
                                          uint8_t *n_read,
                                          sbp_msg_group_delay_dep_b_t *msg);
/**
 * Send an instance of sbp_msg_group_delay_dep_b_t with the given write function
 *
 * An equivalent of #sbp_send_message which operates specifically on
 * sbp_msg_group_delay_dep_b_t
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
s8 sbp_send_sbp_msg_group_delay_dep_b_t(struct sbp_state *s, u16 sender_id,
                                        const sbp_msg_group_delay_dep_b_t *msg,
                                        s32 (*write)(u8 *buff, u32 n,
                                                     void *context));

/**
 * Compare two instances of sbp_msg_group_delay_dep_b_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_group_delay_dep_b_t instance
 * @param b sbp_msg_group_delay_dep_b_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_msg_group_delay_dep_b_t(const sbp_msg_group_delay_dep_b_t *a,
                                        const sbp_msg_group_delay_dep_b_t *b);

/*
 *
 *
 *
 ******************************************************************************
 *
 * SBP_MSG_GROUP_DELAY
 *
 *****************************************************************************/
/** Group Delay
 *
 * Please see ICD-GPS-200 (30.3.3.3.1.1) for more details.
 */
typedef struct {
  /**
   * Data Predict Time of Week
   */
  sbp_gps_time_sec_t t_op;

  /**
   * GNSS signal identifier
   */
  sbp_sbp_gnss_signal_t sid;

  /**
   * bit-field indicating validity of the values, LSB indicating tgd validity
   * etc. 1 = value is valid, 0 = value is not valid.
   */
  u8 valid;

  s16 tgd;

  s16 isc_l1ca;

  s16 isc_l2c;
} sbp_msg_group_delay_t;

/**
 * Get encoded size of an instance of sbp_msg_group_delay_t
 *
 * @param msg sbp_msg_group_delay_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_msg_group_delay_t(const sbp_msg_group_delay_t *msg);

/**
 * Encode an instance of sbp_msg_group_delay_t to wire representation
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
 * @param msg Instance of sbp_msg_group_delay_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_msg_group_delay_t(uint8_t *buf, uint8_t len,
                                    uint8_t *n_written,
                                    const sbp_msg_group_delay_t *msg);

/**
 * Decode an instance of sbp_msg_group_delay_t from wire representation
 *
 * This function decodes the wire representation of a sbp_msg_group_delay_t
 * message to the given instance. The caller must specify the length of the
 * buffer in the \p len parameter. If non-null the number of bytes read from the
 * buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_msg_group_delay_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_msg_group_delay_t(const uint8_t *buf, uint8_t len,
                                    uint8_t *n_read,
                                    sbp_msg_group_delay_t *msg);
/**
 * Send an instance of sbp_msg_group_delay_t with the given write function
 *
 * An equivalent of #sbp_send_message which operates specifically on
 * sbp_msg_group_delay_t
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
s8 sbp_send_sbp_msg_group_delay_t(struct sbp_state *s, u16 sender_id,
                                  const sbp_msg_group_delay_t *msg,
                                  s32 (*write)(u8 *buff, u32 n, void *context));

/**
 * Compare two instances of sbp_msg_group_delay_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_group_delay_t instance
 * @param b sbp_msg_group_delay_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_msg_group_delay_t(const sbp_msg_group_delay_t *a,
                                  const sbp_msg_group_delay_t *b);

/*
 *
 *
 *
 ******************************************************************************
 *
 * SBP_ALMANACCOMMONCONTENT
 *
 *****************************************************************************/
typedef struct {
  /**
   * GNSS signal identifier
   */
  sbp_sbp_gnss_signal_t sid;

  /**
   * Reference time of almanac
   */
  sbp_gps_time_sec_t toa;

  /**
   * User Range Accuracy [m]
   */
  double ura;

  /**
   * Curve fit interval [s]
   */
  u32 fit_interval;

  /**
   * Status of almanac, 1 = valid, 0 = invalid
   */
  u8 valid;

  /**
   * Satellite health status for GPS:
   *   - bits 5-7: NAV data health status. See IS-GPS-200H
   *     Table 20-VII: NAV Data Health Indications.
   *   - bits 0-4: Signal health status. See IS-GPS-200H
   *     Table 20-VIII. Codes for Health of SV Signal
   *     Components.
   * Satellite health status for GLO (see GLO ICD 5.1 table 5.1 for details):
   *   - bit 0: C(n), "unhealthy" flag that is transmitted within
   *     non-immediate data and indicates overall constellation status
   *     at the moment of almanac uploading.
   *     '0' indicates malfunction of n-satellite.
   *     '1' indicates that n-satellite is operational.
   *   - bit 1: Bn(ln), '0' indicates the satellite is operational
   *     and suitable for navigation.
   */
  u8 health_bits;
} sbp_almanac_common_content_t;

/**
 * Get encoded size of an instance of sbp_almanac_common_content_t
 *
 * @param msg sbp_almanac_common_content_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_almanac_common_content_t(
    const sbp_almanac_common_content_t *msg);

/**
 * Encode an instance of sbp_almanac_common_content_t to wire representation
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
 * @param msg Instance of sbp_almanac_common_content_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_almanac_common_content_t(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_almanac_common_content_t *msg);

/**
 * Decode an instance of sbp_almanac_common_content_t from wire representation
 *
 * This function decodes the wire representation of a
 * sbp_almanac_common_content_t message to the given instance. The caller must
 * specify the length of the buffer in the \p len parameter. If non-null the
 * number of bytes read from the buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_almanac_common_content_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_almanac_common_content_t(const uint8_t *buf, uint8_t len,
                                           uint8_t *n_read,
                                           sbp_almanac_common_content_t *msg);

/**
 * Compare two instances of sbp_almanac_common_content_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_almanac_common_content_t instance
 * @param b sbp_almanac_common_content_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_almanac_common_content_t(const sbp_almanac_common_content_t *a,
                                         const sbp_almanac_common_content_t *b);

/*
 *
 *
 *
 ******************************************************************************
 *
 * SBP_ALMANACCOMMONCONTENTDEP
 *
 *****************************************************************************/
typedef struct {
  /**
   * GNSS signal identifier
   */
  sbp_gnss_signal_dep_t sid;

  /**
   * Reference time of almanac
   */
  sbp_gps_time_sec_t toa;

  /**
   * User Range Accuracy [m]
   */
  double ura;

  /**
   * Curve fit interval [s]
   */
  u32 fit_interval;

  /**
   * Status of almanac, 1 = valid, 0 = invalid
   */
  u8 valid;

  /**
   * Satellite health status for GPS:
   *   - bits 5-7: NAV data health status. See IS-GPS-200H
   *     Table 20-VII: NAV Data Health Indications.
   *   - bits 0-4: Signal health status. See IS-GPS-200H
   *     Table 20-VIII. Codes for Health of SV Signal
   *     Components.
   * Satellite health status for GLO (see GLO ICD 5.1 table 5.1 for details):
   *   - bit 0: C(n), "unhealthy" flag that is transmitted within
   *     non-immediate data and indicates overall constellation status
   *     at the moment of almanac uploading.
   *     '0' indicates malfunction of n-satellite.
   *     '1' indicates that n-satellite is operational.
   *   - bit 1: Bn(ln), '0' indicates the satellite is operational
   *     and suitable for navigation.
   */
  u8 health_bits;
} sbp_almanac_common_content_dep_t;

/**
 * Get encoded size of an instance of sbp_almanac_common_content_dep_t
 *
 * @param msg sbp_almanac_common_content_dep_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_almanac_common_content_dep_t(
    const sbp_almanac_common_content_dep_t *msg);

/**
 * Encode an instance of sbp_almanac_common_content_dep_t to wire representation
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
 * @param msg Instance of sbp_almanac_common_content_dep_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_almanac_common_content_dep_t(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_almanac_common_content_dep_t *msg);

/**
 * Decode an instance of sbp_almanac_common_content_dep_t from wire
 * representation
 *
 * This function decodes the wire representation of a
 * sbp_almanac_common_content_dep_t message to the given instance. The caller
 * must specify the length of the buffer in the \p len parameter. If non-null
 * the number of bytes read from the buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_almanac_common_content_dep_t
 * instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_almanac_common_content_dep_t(
    const uint8_t *buf, uint8_t len, uint8_t *n_read,
    sbp_almanac_common_content_dep_t *msg);

/**
 * Compare two instances of sbp_almanac_common_content_dep_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_almanac_common_content_dep_t instance
 * @param b sbp_almanac_common_content_dep_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_almanac_common_content_dep_t(
    const sbp_almanac_common_content_dep_t *a,
    const sbp_almanac_common_content_dep_t *b);

/*
 *
 *
 *
 ******************************************************************************
 *
 * SBP_MSG_ALMANAC_GPS_DEP
 *
 *****************************************************************************/
/** Satellite broadcast ephemeris for GPS
 *
 * The almanac message returns a set of satellite orbit parameters. Almanac data
 * is not very precise and is considered valid for up to several months. Please
 * see the Navstar GPS Space Segment/Navigation user interfaces (ICD-GPS-200,
 * Chapter 20.3.3.5.1.2 Almanac Data) for more details.
 */
typedef struct {
  /**
   * Values common for all almanac types
   */
  sbp_almanac_common_content_dep_t common;

  /**
   * Mean anomaly at reference time [rad]
   */
  double m0;

  /**
   * Eccentricity of satellite orbit
   */
  double ecc;

  /**
   * Square root of the semi-major axis of orbit [m^(1/2)]
   */
  double sqrta;

  /**
   * Longitude of ascending node of orbit plane at weekly epoch [rad]
   */
  double omega0;

  /**
   * Rate of right ascension [rad/s]
   */
  double omegadot;

  /**
   * Argument of perigee [rad]
   */
  double w;

  /**
   * Inclination [rad]
   */
  double inc;

  /**
   * Polynomial clock correction coefficient (clock bias) [s]
   */
  double af0;

  /**
   * Polynomial clock correction coefficient (clock drift) [s/s]
   */
  double af1;
} sbp_msg_almanac_gps_dep_t;

/**
 * Get encoded size of an instance of sbp_msg_almanac_gps_dep_t
 *
 * @param msg sbp_msg_almanac_gps_dep_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_msg_almanac_gps_dep_t(
    const sbp_msg_almanac_gps_dep_t *msg);

/**
 * Encode an instance of sbp_msg_almanac_gps_dep_t to wire representation
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
 * @param msg Instance of sbp_msg_almanac_gps_dep_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_msg_almanac_gps_dep_t(uint8_t *buf, uint8_t len,
                                        uint8_t *n_written,
                                        const sbp_msg_almanac_gps_dep_t *msg);

/**
 * Decode an instance of sbp_msg_almanac_gps_dep_t from wire representation
 *
 * This function decodes the wire representation of a sbp_msg_almanac_gps_dep_t
 * message to the given instance. The caller must specify the length of the
 * buffer in the \p len parameter. If non-null the number of bytes read from the
 * buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_msg_almanac_gps_dep_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_msg_almanac_gps_dep_t(const uint8_t *buf, uint8_t len,
                                        uint8_t *n_read,
                                        sbp_msg_almanac_gps_dep_t *msg);
/**
 * Send an instance of sbp_msg_almanac_gps_dep_t with the given write function
 *
 * An equivalent of #sbp_send_message which operates specifically on
 * sbp_msg_almanac_gps_dep_t
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
s8 sbp_send_sbp_msg_almanac_gps_dep_t(struct sbp_state *s, u16 sender_id,
                                      const sbp_msg_almanac_gps_dep_t *msg,
                                      s32 (*write)(u8 *buff, u32 n,
                                                   void *context));

/**
 * Compare two instances of sbp_msg_almanac_gps_dep_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_almanac_gps_dep_t instance
 * @param b sbp_msg_almanac_gps_dep_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_msg_almanac_gps_dep_t(const sbp_msg_almanac_gps_dep_t *a,
                                      const sbp_msg_almanac_gps_dep_t *b);

/*
 *
 *
 *
 ******************************************************************************
 *
 * SBP_MSG_ALMANAC_GPS
 *
 *****************************************************************************/
/** Satellite broadcast ephemeris for GPS
 *
 * The almanac message returns a set of satellite orbit parameters. Almanac data
 * is not very precise and is considered valid for up to several months. Please
 * see the Navstar GPS Space Segment/Navigation user interfaces (ICD-GPS-200,
 * Chapter 20.3.3.5.1.2 Almanac Data) for more details.
 */
typedef struct {
  /**
   * Values common for all almanac types
   */
  sbp_almanac_common_content_t common;

  /**
   * Mean anomaly at reference time [rad]
   */
  double m0;

  /**
   * Eccentricity of satellite orbit
   */
  double ecc;

  /**
   * Square root of the semi-major axis of orbit [m^(1/2)]
   */
  double sqrta;

  /**
   * Longitude of ascending node of orbit plane at weekly epoch [rad]
   */
  double omega0;

  /**
   * Rate of right ascension [rad/s]
   */
  double omegadot;

  /**
   * Argument of perigee [rad]
   */
  double w;

  /**
   * Inclination [rad]
   */
  double inc;

  /**
   * Polynomial clock correction coefficient (clock bias) [s]
   */
  double af0;

  /**
   * Polynomial clock correction coefficient (clock drift) [s/s]
   */
  double af1;
} sbp_msg_almanac_gps_t;

/**
 * Get encoded size of an instance of sbp_msg_almanac_gps_t
 *
 * @param msg sbp_msg_almanac_gps_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_msg_almanac_gps_t(const sbp_msg_almanac_gps_t *msg);

/**
 * Encode an instance of sbp_msg_almanac_gps_t to wire representation
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
 * @param msg Instance of sbp_msg_almanac_gps_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_msg_almanac_gps_t(uint8_t *buf, uint8_t len,
                                    uint8_t *n_written,
                                    const sbp_msg_almanac_gps_t *msg);

/**
 * Decode an instance of sbp_msg_almanac_gps_t from wire representation
 *
 * This function decodes the wire representation of a sbp_msg_almanac_gps_t
 * message to the given instance. The caller must specify the length of the
 * buffer in the \p len parameter. If non-null the number of bytes read from the
 * buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_msg_almanac_gps_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_msg_almanac_gps_t(const uint8_t *buf, uint8_t len,
                                    uint8_t *n_read,
                                    sbp_msg_almanac_gps_t *msg);
/**
 * Send an instance of sbp_msg_almanac_gps_t with the given write function
 *
 * An equivalent of #sbp_send_message which operates specifically on
 * sbp_msg_almanac_gps_t
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
s8 sbp_send_sbp_msg_almanac_gps_t(struct sbp_state *s, u16 sender_id,
                                  const sbp_msg_almanac_gps_t *msg,
                                  s32 (*write)(u8 *buff, u32 n, void *context));

/**
 * Compare two instances of sbp_msg_almanac_gps_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_almanac_gps_t instance
 * @param b sbp_msg_almanac_gps_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_msg_almanac_gps_t(const sbp_msg_almanac_gps_t *a,
                                  const sbp_msg_almanac_gps_t *b);

/*
 *
 *
 *
 ******************************************************************************
 *
 * SBP_MSG_ALMANAC_GLO_DEP
 *
 *****************************************************************************/
/** Satellite broadcast ephemeris for GLO
 *
 * The almanac message returns a set of satellite orbit parameters. Almanac data
 * is not very precise and is considered valid for up to several months. Please
 * see the GLO ICD 5.1 "Chapter 4.5 Non-immediate information and almanac" for
 * details.
 */
typedef struct {
  /**
   * Values common for all almanac types
   */
  sbp_almanac_common_content_dep_t common;

  /**
   * Longitude of the first ascending node of the orbit in PZ-90.02 coordinate
   * system [rad]
   */
  double lambda_na;

  /**
   * Time of the first ascending node passage [s]
   */
  double t_lambda_na;

  /**
   * Value of inclination at instant of t_lambda [rad]
   */
  double i;

  /**
   * Value of Draconian period at instant of t_lambda [s/orbital period]
   */
  double t;

  /**
   * Rate of change of the Draconian period [s/(orbital period^2)]
   */
  double t_dot;

  /**
   * Eccentricity at instant of t_lambda
   */
  double epsilon;

  /**
   * Argument of perigee at instant of t_lambda [rad]
   */
  double omega;
} sbp_msg_almanac_glo_dep_t;

/**
 * Get encoded size of an instance of sbp_msg_almanac_glo_dep_t
 *
 * @param msg sbp_msg_almanac_glo_dep_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_msg_almanac_glo_dep_t(
    const sbp_msg_almanac_glo_dep_t *msg);

/**
 * Encode an instance of sbp_msg_almanac_glo_dep_t to wire representation
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
 * @param msg Instance of sbp_msg_almanac_glo_dep_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_msg_almanac_glo_dep_t(uint8_t *buf, uint8_t len,
                                        uint8_t *n_written,
                                        const sbp_msg_almanac_glo_dep_t *msg);

/**
 * Decode an instance of sbp_msg_almanac_glo_dep_t from wire representation
 *
 * This function decodes the wire representation of a sbp_msg_almanac_glo_dep_t
 * message to the given instance. The caller must specify the length of the
 * buffer in the \p len parameter. If non-null the number of bytes read from the
 * buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_msg_almanac_glo_dep_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_msg_almanac_glo_dep_t(const uint8_t *buf, uint8_t len,
                                        uint8_t *n_read,
                                        sbp_msg_almanac_glo_dep_t *msg);
/**
 * Send an instance of sbp_msg_almanac_glo_dep_t with the given write function
 *
 * An equivalent of #sbp_send_message which operates specifically on
 * sbp_msg_almanac_glo_dep_t
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
s8 sbp_send_sbp_msg_almanac_glo_dep_t(struct sbp_state *s, u16 sender_id,
                                      const sbp_msg_almanac_glo_dep_t *msg,
                                      s32 (*write)(u8 *buff, u32 n,
                                                   void *context));

/**
 * Compare two instances of sbp_msg_almanac_glo_dep_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_almanac_glo_dep_t instance
 * @param b sbp_msg_almanac_glo_dep_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_msg_almanac_glo_dep_t(const sbp_msg_almanac_glo_dep_t *a,
                                      const sbp_msg_almanac_glo_dep_t *b);

/*
 *
 *
 *
 ******************************************************************************
 *
 * SBP_MSG_ALMANAC_GLO
 *
 *****************************************************************************/
/** Satellite broadcast ephemeris for GLO
 *
 * The almanac message returns a set of satellite orbit parameters. Almanac data
 * is not very precise and is considered valid for up to several months. Please
 * see the GLO ICD 5.1 "Chapter 4.5 Non-immediate information and almanac" for
 * details.
 */
typedef struct {
  /**
   * Values common for all almanac types
   */
  sbp_almanac_common_content_t common;

  /**
   * Longitude of the first ascending node of the orbit in PZ-90.02 coordinate
   * system [rad]
   */
  double lambda_na;

  /**
   * Time of the first ascending node passage [s]
   */
  double t_lambda_na;

  /**
   * Value of inclination at instant of t_lambda [rad]
   */
  double i;

  /**
   * Value of Draconian period at instant of t_lambda [s/orbital period]
   */
  double t;

  /**
   * Rate of change of the Draconian period [s/(orbital period^2)]
   */
  double t_dot;

  /**
   * Eccentricity at instant of t_lambda
   */
  double epsilon;

  /**
   * Argument of perigee at instant of t_lambda [rad]
   */
  double omega;
} sbp_msg_almanac_glo_t;

/**
 * Get encoded size of an instance of sbp_msg_almanac_glo_t
 *
 * @param msg sbp_msg_almanac_glo_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_msg_almanac_glo_t(const sbp_msg_almanac_glo_t *msg);

/**
 * Encode an instance of sbp_msg_almanac_glo_t to wire representation
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
 * @param msg Instance of sbp_msg_almanac_glo_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_msg_almanac_glo_t(uint8_t *buf, uint8_t len,
                                    uint8_t *n_written,
                                    const sbp_msg_almanac_glo_t *msg);

/**
 * Decode an instance of sbp_msg_almanac_glo_t from wire representation
 *
 * This function decodes the wire representation of a sbp_msg_almanac_glo_t
 * message to the given instance. The caller must specify the length of the
 * buffer in the \p len parameter. If non-null the number of bytes read from the
 * buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_msg_almanac_glo_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_msg_almanac_glo_t(const uint8_t *buf, uint8_t len,
                                    uint8_t *n_read,
                                    sbp_msg_almanac_glo_t *msg);
/**
 * Send an instance of sbp_msg_almanac_glo_t with the given write function
 *
 * An equivalent of #sbp_send_message which operates specifically on
 * sbp_msg_almanac_glo_t
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
s8 sbp_send_sbp_msg_almanac_glo_t(struct sbp_state *s, u16 sender_id,
                                  const sbp_msg_almanac_glo_t *msg,
                                  s32 (*write)(u8 *buff, u32 n, void *context));

/**
 * Compare two instances of sbp_msg_almanac_glo_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_almanac_glo_t instance
 * @param b sbp_msg_almanac_glo_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_msg_almanac_glo_t(const sbp_msg_almanac_glo_t *a,
                                  const sbp_msg_almanac_glo_t *b);

/*
 *
 *
 *
 ******************************************************************************
 *
 * SBP_MSG_GLO_BIASES
 *
 *****************************************************************************/
/** GLONASS L1/L2 Code-Phase biases
 *
 * The GLONASS L1/L2 Code-Phase biases allows to perform GPS+GLONASS integer
 * ambiguity resolution for baselines with mixed receiver types (e.g. receiver
 * of different manufacturers).
 */
typedef struct {
  /**
   * GLONASS FDMA signals mask [boolean]
   */
  u8 mask;

  /**
   * GLONASS L1 C/A Code-Phase Bias [m * 0.02]
   */
  s16 l1ca_bias;

  /**
   * GLONASS L1 P Code-Phase Bias [m * 0.02]
   */
  s16 l1p_bias;

  /**
   * GLONASS L2 C/A Code-Phase Bias [m * 0.02]
   */
  s16 l2ca_bias;

  /**
   * GLONASS L2 P Code-Phase Bias [m * 0.02]
   */
  s16 l2p_bias;
} sbp_msg_glo_biases_t;

/**
 * Get encoded size of an instance of sbp_msg_glo_biases_t
 *
 * @param msg sbp_msg_glo_biases_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_msg_glo_biases_t(const sbp_msg_glo_biases_t *msg);

/**
 * Encode an instance of sbp_msg_glo_biases_t to wire representation
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
 * @param msg Instance of sbp_msg_glo_biases_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_msg_glo_biases_t(uint8_t *buf, uint8_t len,
                                   uint8_t *n_written,
                                   const sbp_msg_glo_biases_t *msg);

/**
 * Decode an instance of sbp_msg_glo_biases_t from wire representation
 *
 * This function decodes the wire representation of a sbp_msg_glo_biases_t
 * message to the given instance. The caller must specify the length of the
 * buffer in the \p len parameter. If non-null the number of bytes read from the
 * buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_msg_glo_biases_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_msg_glo_biases_t(const uint8_t *buf, uint8_t len,
                                   uint8_t *n_read, sbp_msg_glo_biases_t *msg);
/**
 * Send an instance of sbp_msg_glo_biases_t with the given write function
 *
 * An equivalent of #sbp_send_message which operates specifically on
 * sbp_msg_glo_biases_t
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
s8 sbp_send_sbp_msg_glo_biases_t(struct sbp_state *s, u16 sender_id,
                                 const sbp_msg_glo_biases_t *msg,
                                 s32 (*write)(u8 *buff, u32 n, void *context));

/**
 * Compare two instances of sbp_msg_glo_biases_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_glo_biases_t instance
 * @param b sbp_msg_glo_biases_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_msg_glo_biases_t(const sbp_msg_glo_biases_t *a,
                                 const sbp_msg_glo_biases_t *b);

/*
 *
 *
 *
 ******************************************************************************
 *
 * SBP_SVAZEL
 *
 *****************************************************************************/
/** Satellite azimuth and elevation
 *
 * Satellite azimuth and elevation.
 */
typedef struct {
  /**
   * GNSS signal identifier
   */
  sbp_sbp_gnss_signal_t sid;

  /**
   * Azimuth angle (range 0..179) [deg * 2]
   */
  u8 az;

  /**
   * Elevation angle (range -90..90) [deg]
   */
  s8 el;
} sbp_sv_az_el_t;

/**
 * Get encoded size of an instance of sbp_sv_az_el_t
 *
 * @param msg sbp_sv_az_el_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_sv_az_el_t(const sbp_sv_az_el_t *msg);

/**
 * Encode an instance of sbp_sv_az_el_t to wire representation
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
 * @param msg Instance of sbp_sv_az_el_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_sv_az_el_t(uint8_t *buf, uint8_t len, uint8_t *n_written,
                             const sbp_sv_az_el_t *msg);

/**
 * Decode an instance of sbp_sv_az_el_t from wire representation
 *
 * This function decodes the wire representation of a sbp_sv_az_el_t message to
 * the given instance. The caller must specify the length of the buffer in the
 * \p len parameter. If non-null the number of bytes read from the buffer will
 * be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_sv_az_el_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_sv_az_el_t(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                             sbp_sv_az_el_t *msg);

/**
 * Compare two instances of sbp_sv_az_el_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_sv_az_el_t instance
 * @param b sbp_sv_az_el_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_sv_az_el_t(const sbp_sv_az_el_t *a, const sbp_sv_az_el_t *b);

/*
 *
 *
 *
 ******************************************************************************
 *
 * SBP_MSG_SV_AZ_EL
 *
 *****************************************************************************/
/** Satellite azimuths and elevations
 *
 * Azimuth and elevation angles of all the visible satellites that the device
 * does have ephemeris or almanac for.
 */
typedef struct {
  /**
   * Azimuth and elevation per satellite
   */
  sbp_sv_az_el_t azel[63];
  /**
   * Number of elements in azel
   *
   * When sending a message fill in this field with the number elements set in
   * azel before calling an appropriate libsbp send function
   *
   * When receiving a message query this field for the number of elements in
   * azel. The value of any elements beyond the index specified in this field is
   * undefined
   */
  u8 n_azel;
} sbp_msg_sv_az_el_t;

/**
 * Get encoded size of an instance of sbp_msg_sv_az_el_t
 *
 * @param msg sbp_msg_sv_az_el_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_msg_sv_az_el_t(const sbp_msg_sv_az_el_t *msg);

/**
 * Encode an instance of sbp_msg_sv_az_el_t to wire representation
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
 * @param msg Instance of sbp_msg_sv_az_el_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_msg_sv_az_el_t(uint8_t *buf, uint8_t len, uint8_t *n_written,
                                 const sbp_msg_sv_az_el_t *msg);

/**
 * Decode an instance of sbp_msg_sv_az_el_t from wire representation
 *
 * This function decodes the wire representation of a sbp_msg_sv_az_el_t message
 * to the given instance. The caller must specify the length of the buffer in
 * the \p len parameter. If non-null the number of bytes read from the buffer
 * will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_msg_sv_az_el_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_msg_sv_az_el_t(const uint8_t *buf, uint8_t len,
                                 uint8_t *n_read, sbp_msg_sv_az_el_t *msg);
/**
 * Send an instance of sbp_msg_sv_az_el_t with the given write function
 *
 * An equivalent of #sbp_send_message which operates specifically on
 * sbp_msg_sv_az_el_t
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
s8 sbp_send_sbp_msg_sv_az_el_t(struct sbp_state *s, u16 sender_id,
                               const sbp_msg_sv_az_el_t *msg,
                               s32 (*write)(u8 *buff, u32 n, void *context));

/**
 * Compare two instances of sbp_msg_sv_az_el_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_sv_az_el_t instance
 * @param b sbp_msg_sv_az_el_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_msg_sv_az_el_t(const sbp_msg_sv_az_el_t *a,
                               const sbp_msg_sv_az_el_t *b);

/*
 *
 *
 *
 ******************************************************************************
 *
 * SBP_MSG_OSR
 *
 *****************************************************************************/
/** OSR corrections
 *
 * The OSR message contains network corrections in an observation-like format.
 */
typedef struct {
  /**
   * Header of a GPS observation message
   */
  sbp_observation_header_t header;

  /**
   * Network correction for a satellite signal.
   */
  sbp_packed_osr_content_t obs[12];
  /**
   * Number of elements in obs
   *
   * When sending a message fill in this field with the number elements set in
   * obs before calling an appropriate libsbp send function
   *
   * When receiving a message query this field for the number of elements in
   * obs. The value of any elements beyond the index specified in this field is
   * undefined
   */
  u8 n_obs;
} sbp_msg_osr_t;

/**
 * Get encoded size of an instance of sbp_msg_osr_t
 *
 * @param msg sbp_msg_osr_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_msg_osr_t(const sbp_msg_osr_t *msg);

/**
 * Encode an instance of sbp_msg_osr_t to wire representation
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
 * @param msg Instance of sbp_msg_osr_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_msg_osr_t(uint8_t *buf, uint8_t len, uint8_t *n_written,
                            const sbp_msg_osr_t *msg);

/**
 * Decode an instance of sbp_msg_osr_t from wire representation
 *
 * This function decodes the wire representation of a sbp_msg_osr_t message to
 * the given instance. The caller must specify the length of the buffer in the
 * \p len parameter. If non-null the number of bytes read from the buffer will
 * be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_msg_osr_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_msg_osr_t(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                            sbp_msg_osr_t *msg);
/**
 * Send an instance of sbp_msg_osr_t with the given write function
 *
 * An equivalent of #sbp_send_message which operates specifically on
 * sbp_msg_osr_t
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
s8 sbp_send_sbp_msg_osr_t(struct sbp_state *s, u16 sender_id,
                          const sbp_msg_osr_t *msg,
                          s32 (*write)(u8 *buff, u32 n, void *context));

/**
 * Compare two instances of sbp_msg_osr_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_osr_t instance
 * @param b sbp_msg_osr_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_msg_osr_t(const sbp_msg_osr_t *a, const sbp_msg_osr_t *b);

#ifdef __cplusplus
}
static inline bool operator==(const sbp_observation_header_t &lhs,
                              const sbp_observation_header_t &rhs) {
  return sbp_cmp_sbp_observation_header_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_observation_header_t &lhs,
                              const sbp_observation_header_t &rhs) {
  return sbp_cmp_sbp_observation_header_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_observation_header_t &lhs,
                             const sbp_observation_header_t &rhs) {
  return sbp_cmp_sbp_observation_header_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_observation_header_t &lhs,
                              const sbp_observation_header_t &rhs) {
  return sbp_cmp_sbp_observation_header_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_observation_header_t &lhs,
                             const sbp_observation_header_t &rhs) {
  return sbp_cmp_sbp_observation_header_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_observation_header_t &lhs,
                              const sbp_observation_header_t &rhs) {
  return sbp_cmp_sbp_observation_header_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_doppler_t &lhs,
                              const sbp_doppler_t &rhs) {
  return sbp_cmp_sbp_doppler_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_doppler_t &lhs,
                              const sbp_doppler_t &rhs) {
  return sbp_cmp_sbp_doppler_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_doppler_t &lhs,
                             const sbp_doppler_t &rhs) {
  return sbp_cmp_sbp_doppler_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_doppler_t &lhs,
                              const sbp_doppler_t &rhs) {
  return sbp_cmp_sbp_doppler_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_doppler_t &lhs,
                             const sbp_doppler_t &rhs) {
  return sbp_cmp_sbp_doppler_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_doppler_t &lhs,
                              const sbp_doppler_t &rhs) {
  return sbp_cmp_sbp_doppler_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_packed_obs_content_t &lhs,
                              const sbp_packed_obs_content_t &rhs) {
  return sbp_cmp_sbp_packed_obs_content_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_packed_obs_content_t &lhs,
                              const sbp_packed_obs_content_t &rhs) {
  return sbp_cmp_sbp_packed_obs_content_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_packed_obs_content_t &lhs,
                             const sbp_packed_obs_content_t &rhs) {
  return sbp_cmp_sbp_packed_obs_content_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_packed_obs_content_t &lhs,
                              const sbp_packed_obs_content_t &rhs) {
  return sbp_cmp_sbp_packed_obs_content_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_packed_obs_content_t &lhs,
                             const sbp_packed_obs_content_t &rhs) {
  return sbp_cmp_sbp_packed_obs_content_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_packed_obs_content_t &lhs,
                              const sbp_packed_obs_content_t &rhs) {
  return sbp_cmp_sbp_packed_obs_content_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_packed_osr_content_t &lhs,
                              const sbp_packed_osr_content_t &rhs) {
  return sbp_cmp_sbp_packed_osr_content_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_packed_osr_content_t &lhs,
                              const sbp_packed_osr_content_t &rhs) {
  return sbp_cmp_sbp_packed_osr_content_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_packed_osr_content_t &lhs,
                             const sbp_packed_osr_content_t &rhs) {
  return sbp_cmp_sbp_packed_osr_content_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_packed_osr_content_t &lhs,
                              const sbp_packed_osr_content_t &rhs) {
  return sbp_cmp_sbp_packed_osr_content_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_packed_osr_content_t &lhs,
                             const sbp_packed_osr_content_t &rhs) {
  return sbp_cmp_sbp_packed_osr_content_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_packed_osr_content_t &lhs,
                              const sbp_packed_osr_content_t &rhs) {
  return sbp_cmp_sbp_packed_osr_content_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_msg_obs_t &lhs,
                              const sbp_msg_obs_t &rhs) {
  return sbp_cmp_sbp_msg_obs_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_msg_obs_t &lhs,
                              const sbp_msg_obs_t &rhs) {
  return sbp_cmp_sbp_msg_obs_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_obs_t &lhs,
                             const sbp_msg_obs_t &rhs) {
  return sbp_cmp_sbp_msg_obs_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_msg_obs_t &lhs,
                              const sbp_msg_obs_t &rhs) {
  return sbp_cmp_sbp_msg_obs_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_obs_t &lhs,
                             const sbp_msg_obs_t &rhs) {
  return sbp_cmp_sbp_msg_obs_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_msg_obs_t &lhs,
                              const sbp_msg_obs_t &rhs) {
  return sbp_cmp_sbp_msg_obs_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_msg_base_pos_llh_t &lhs,
                              const sbp_msg_base_pos_llh_t &rhs) {
  return sbp_cmp_sbp_msg_base_pos_llh_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_msg_base_pos_llh_t &lhs,
                              const sbp_msg_base_pos_llh_t &rhs) {
  return sbp_cmp_sbp_msg_base_pos_llh_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_base_pos_llh_t &lhs,
                             const sbp_msg_base_pos_llh_t &rhs) {
  return sbp_cmp_sbp_msg_base_pos_llh_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_msg_base_pos_llh_t &lhs,
                              const sbp_msg_base_pos_llh_t &rhs) {
  return sbp_cmp_sbp_msg_base_pos_llh_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_base_pos_llh_t &lhs,
                             const sbp_msg_base_pos_llh_t &rhs) {
  return sbp_cmp_sbp_msg_base_pos_llh_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_msg_base_pos_llh_t &lhs,
                              const sbp_msg_base_pos_llh_t &rhs) {
  return sbp_cmp_sbp_msg_base_pos_llh_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_msg_base_pos_ecef_t &lhs,
                              const sbp_msg_base_pos_ecef_t &rhs) {
  return sbp_cmp_sbp_msg_base_pos_ecef_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_msg_base_pos_ecef_t &lhs,
                              const sbp_msg_base_pos_ecef_t &rhs) {
  return sbp_cmp_sbp_msg_base_pos_ecef_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_base_pos_ecef_t &lhs,
                             const sbp_msg_base_pos_ecef_t &rhs) {
  return sbp_cmp_sbp_msg_base_pos_ecef_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_msg_base_pos_ecef_t &lhs,
                              const sbp_msg_base_pos_ecef_t &rhs) {
  return sbp_cmp_sbp_msg_base_pos_ecef_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_base_pos_ecef_t &lhs,
                             const sbp_msg_base_pos_ecef_t &rhs) {
  return sbp_cmp_sbp_msg_base_pos_ecef_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_msg_base_pos_ecef_t &lhs,
                              const sbp_msg_base_pos_ecef_t &rhs) {
  return sbp_cmp_sbp_msg_base_pos_ecef_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_ephemeris_common_content_t &lhs,
                              const sbp_ephemeris_common_content_t &rhs) {
  return sbp_cmp_sbp_ephemeris_common_content_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_ephemeris_common_content_t &lhs,
                              const sbp_ephemeris_common_content_t &rhs) {
  return sbp_cmp_sbp_ephemeris_common_content_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_ephemeris_common_content_t &lhs,
                             const sbp_ephemeris_common_content_t &rhs) {
  return sbp_cmp_sbp_ephemeris_common_content_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_ephemeris_common_content_t &lhs,
                              const sbp_ephemeris_common_content_t &rhs) {
  return sbp_cmp_sbp_ephemeris_common_content_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_ephemeris_common_content_t &lhs,
                             const sbp_ephemeris_common_content_t &rhs) {
  return sbp_cmp_sbp_ephemeris_common_content_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_ephemeris_common_content_t &lhs,
                              const sbp_ephemeris_common_content_t &rhs) {
  return sbp_cmp_sbp_ephemeris_common_content_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_ephemeris_common_content_dep_b_t &lhs,
                              const sbp_ephemeris_common_content_dep_b_t &rhs) {
  return sbp_cmp_sbp_ephemeris_common_content_dep_b_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_ephemeris_common_content_dep_b_t &lhs,
                              const sbp_ephemeris_common_content_dep_b_t &rhs) {
  return sbp_cmp_sbp_ephemeris_common_content_dep_b_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_ephemeris_common_content_dep_b_t &lhs,
                             const sbp_ephemeris_common_content_dep_b_t &rhs) {
  return sbp_cmp_sbp_ephemeris_common_content_dep_b_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_ephemeris_common_content_dep_b_t &lhs,
                              const sbp_ephemeris_common_content_dep_b_t &rhs) {
  return sbp_cmp_sbp_ephemeris_common_content_dep_b_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_ephemeris_common_content_dep_b_t &lhs,
                             const sbp_ephemeris_common_content_dep_b_t &rhs) {
  return sbp_cmp_sbp_ephemeris_common_content_dep_b_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_ephemeris_common_content_dep_b_t &lhs,
                              const sbp_ephemeris_common_content_dep_b_t &rhs) {
  return sbp_cmp_sbp_ephemeris_common_content_dep_b_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_ephemeris_common_content_dep_a_t &lhs,
                              const sbp_ephemeris_common_content_dep_a_t &rhs) {
  return sbp_cmp_sbp_ephemeris_common_content_dep_a_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_ephemeris_common_content_dep_a_t &lhs,
                              const sbp_ephemeris_common_content_dep_a_t &rhs) {
  return sbp_cmp_sbp_ephemeris_common_content_dep_a_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_ephemeris_common_content_dep_a_t &lhs,
                             const sbp_ephemeris_common_content_dep_a_t &rhs) {
  return sbp_cmp_sbp_ephemeris_common_content_dep_a_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_ephemeris_common_content_dep_a_t &lhs,
                              const sbp_ephemeris_common_content_dep_a_t &rhs) {
  return sbp_cmp_sbp_ephemeris_common_content_dep_a_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_ephemeris_common_content_dep_a_t &lhs,
                             const sbp_ephemeris_common_content_dep_a_t &rhs) {
  return sbp_cmp_sbp_ephemeris_common_content_dep_a_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_ephemeris_common_content_dep_a_t &lhs,
                              const sbp_ephemeris_common_content_dep_a_t &rhs) {
  return sbp_cmp_sbp_ephemeris_common_content_dep_a_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_msg_ephemeris_gps_dep_e_t &lhs,
                              const sbp_msg_ephemeris_gps_dep_e_t &rhs) {
  return sbp_cmp_sbp_msg_ephemeris_gps_dep_e_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_msg_ephemeris_gps_dep_e_t &lhs,
                              const sbp_msg_ephemeris_gps_dep_e_t &rhs) {
  return sbp_cmp_sbp_msg_ephemeris_gps_dep_e_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_ephemeris_gps_dep_e_t &lhs,
                             const sbp_msg_ephemeris_gps_dep_e_t &rhs) {
  return sbp_cmp_sbp_msg_ephemeris_gps_dep_e_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_msg_ephemeris_gps_dep_e_t &lhs,
                              const sbp_msg_ephemeris_gps_dep_e_t &rhs) {
  return sbp_cmp_sbp_msg_ephemeris_gps_dep_e_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_ephemeris_gps_dep_e_t &lhs,
                             const sbp_msg_ephemeris_gps_dep_e_t &rhs) {
  return sbp_cmp_sbp_msg_ephemeris_gps_dep_e_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_msg_ephemeris_gps_dep_e_t &lhs,
                              const sbp_msg_ephemeris_gps_dep_e_t &rhs) {
  return sbp_cmp_sbp_msg_ephemeris_gps_dep_e_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_msg_ephemeris_gps_dep_f_t &lhs,
                              const sbp_msg_ephemeris_gps_dep_f_t &rhs) {
  return sbp_cmp_sbp_msg_ephemeris_gps_dep_f_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_msg_ephemeris_gps_dep_f_t &lhs,
                              const sbp_msg_ephemeris_gps_dep_f_t &rhs) {
  return sbp_cmp_sbp_msg_ephemeris_gps_dep_f_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_ephemeris_gps_dep_f_t &lhs,
                             const sbp_msg_ephemeris_gps_dep_f_t &rhs) {
  return sbp_cmp_sbp_msg_ephemeris_gps_dep_f_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_msg_ephemeris_gps_dep_f_t &lhs,
                              const sbp_msg_ephemeris_gps_dep_f_t &rhs) {
  return sbp_cmp_sbp_msg_ephemeris_gps_dep_f_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_ephemeris_gps_dep_f_t &lhs,
                             const sbp_msg_ephemeris_gps_dep_f_t &rhs) {
  return sbp_cmp_sbp_msg_ephemeris_gps_dep_f_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_msg_ephemeris_gps_dep_f_t &lhs,
                              const sbp_msg_ephemeris_gps_dep_f_t &rhs) {
  return sbp_cmp_sbp_msg_ephemeris_gps_dep_f_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_msg_ephemeris_gps_t &lhs,
                              const sbp_msg_ephemeris_gps_t &rhs) {
  return sbp_cmp_sbp_msg_ephemeris_gps_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_msg_ephemeris_gps_t &lhs,
                              const sbp_msg_ephemeris_gps_t &rhs) {
  return sbp_cmp_sbp_msg_ephemeris_gps_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_ephemeris_gps_t &lhs,
                             const sbp_msg_ephemeris_gps_t &rhs) {
  return sbp_cmp_sbp_msg_ephemeris_gps_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_msg_ephemeris_gps_t &lhs,
                              const sbp_msg_ephemeris_gps_t &rhs) {
  return sbp_cmp_sbp_msg_ephemeris_gps_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_ephemeris_gps_t &lhs,
                             const sbp_msg_ephemeris_gps_t &rhs) {
  return sbp_cmp_sbp_msg_ephemeris_gps_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_msg_ephemeris_gps_t &lhs,
                              const sbp_msg_ephemeris_gps_t &rhs) {
  return sbp_cmp_sbp_msg_ephemeris_gps_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_msg_ephemeris_qzss_t &lhs,
                              const sbp_msg_ephemeris_qzss_t &rhs) {
  return sbp_cmp_sbp_msg_ephemeris_qzss_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_msg_ephemeris_qzss_t &lhs,
                              const sbp_msg_ephemeris_qzss_t &rhs) {
  return sbp_cmp_sbp_msg_ephemeris_qzss_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_ephemeris_qzss_t &lhs,
                             const sbp_msg_ephemeris_qzss_t &rhs) {
  return sbp_cmp_sbp_msg_ephemeris_qzss_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_msg_ephemeris_qzss_t &lhs,
                              const sbp_msg_ephemeris_qzss_t &rhs) {
  return sbp_cmp_sbp_msg_ephemeris_qzss_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_ephemeris_qzss_t &lhs,
                             const sbp_msg_ephemeris_qzss_t &rhs) {
  return sbp_cmp_sbp_msg_ephemeris_qzss_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_msg_ephemeris_qzss_t &lhs,
                              const sbp_msg_ephemeris_qzss_t &rhs) {
  return sbp_cmp_sbp_msg_ephemeris_qzss_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_msg_ephemeris_bds_t &lhs,
                              const sbp_msg_ephemeris_bds_t &rhs) {
  return sbp_cmp_sbp_msg_ephemeris_bds_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_msg_ephemeris_bds_t &lhs,
                              const sbp_msg_ephemeris_bds_t &rhs) {
  return sbp_cmp_sbp_msg_ephemeris_bds_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_ephemeris_bds_t &lhs,
                             const sbp_msg_ephemeris_bds_t &rhs) {
  return sbp_cmp_sbp_msg_ephemeris_bds_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_msg_ephemeris_bds_t &lhs,
                              const sbp_msg_ephemeris_bds_t &rhs) {
  return sbp_cmp_sbp_msg_ephemeris_bds_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_ephemeris_bds_t &lhs,
                             const sbp_msg_ephemeris_bds_t &rhs) {
  return sbp_cmp_sbp_msg_ephemeris_bds_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_msg_ephemeris_bds_t &lhs,
                              const sbp_msg_ephemeris_bds_t &rhs) {
  return sbp_cmp_sbp_msg_ephemeris_bds_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_msg_ephemeris_gal_dep_a_t &lhs,
                              const sbp_msg_ephemeris_gal_dep_a_t &rhs) {
  return sbp_cmp_sbp_msg_ephemeris_gal_dep_a_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_msg_ephemeris_gal_dep_a_t &lhs,
                              const sbp_msg_ephemeris_gal_dep_a_t &rhs) {
  return sbp_cmp_sbp_msg_ephemeris_gal_dep_a_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_ephemeris_gal_dep_a_t &lhs,
                             const sbp_msg_ephemeris_gal_dep_a_t &rhs) {
  return sbp_cmp_sbp_msg_ephemeris_gal_dep_a_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_msg_ephemeris_gal_dep_a_t &lhs,
                              const sbp_msg_ephemeris_gal_dep_a_t &rhs) {
  return sbp_cmp_sbp_msg_ephemeris_gal_dep_a_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_ephemeris_gal_dep_a_t &lhs,
                             const sbp_msg_ephemeris_gal_dep_a_t &rhs) {
  return sbp_cmp_sbp_msg_ephemeris_gal_dep_a_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_msg_ephemeris_gal_dep_a_t &lhs,
                              const sbp_msg_ephemeris_gal_dep_a_t &rhs) {
  return sbp_cmp_sbp_msg_ephemeris_gal_dep_a_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_msg_ephemeris_gal_t &lhs,
                              const sbp_msg_ephemeris_gal_t &rhs) {
  return sbp_cmp_sbp_msg_ephemeris_gal_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_msg_ephemeris_gal_t &lhs,
                              const sbp_msg_ephemeris_gal_t &rhs) {
  return sbp_cmp_sbp_msg_ephemeris_gal_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_ephemeris_gal_t &lhs,
                             const sbp_msg_ephemeris_gal_t &rhs) {
  return sbp_cmp_sbp_msg_ephemeris_gal_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_msg_ephemeris_gal_t &lhs,
                              const sbp_msg_ephemeris_gal_t &rhs) {
  return sbp_cmp_sbp_msg_ephemeris_gal_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_ephemeris_gal_t &lhs,
                             const sbp_msg_ephemeris_gal_t &rhs) {
  return sbp_cmp_sbp_msg_ephemeris_gal_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_msg_ephemeris_gal_t &lhs,
                              const sbp_msg_ephemeris_gal_t &rhs) {
  return sbp_cmp_sbp_msg_ephemeris_gal_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_msg_ephemeris_sbas_dep_a_t &lhs,
                              const sbp_msg_ephemeris_sbas_dep_a_t &rhs) {
  return sbp_cmp_sbp_msg_ephemeris_sbas_dep_a_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_msg_ephemeris_sbas_dep_a_t &lhs,
                              const sbp_msg_ephemeris_sbas_dep_a_t &rhs) {
  return sbp_cmp_sbp_msg_ephemeris_sbas_dep_a_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_ephemeris_sbas_dep_a_t &lhs,
                             const sbp_msg_ephemeris_sbas_dep_a_t &rhs) {
  return sbp_cmp_sbp_msg_ephemeris_sbas_dep_a_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_msg_ephemeris_sbas_dep_a_t &lhs,
                              const sbp_msg_ephemeris_sbas_dep_a_t &rhs) {
  return sbp_cmp_sbp_msg_ephemeris_sbas_dep_a_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_ephemeris_sbas_dep_a_t &lhs,
                             const sbp_msg_ephemeris_sbas_dep_a_t &rhs) {
  return sbp_cmp_sbp_msg_ephemeris_sbas_dep_a_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_msg_ephemeris_sbas_dep_a_t &lhs,
                              const sbp_msg_ephemeris_sbas_dep_a_t &rhs) {
  return sbp_cmp_sbp_msg_ephemeris_sbas_dep_a_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_msg_ephemeris_glo_dep_a_t &lhs,
                              const sbp_msg_ephemeris_glo_dep_a_t &rhs) {
  return sbp_cmp_sbp_msg_ephemeris_glo_dep_a_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_msg_ephemeris_glo_dep_a_t &lhs,
                              const sbp_msg_ephemeris_glo_dep_a_t &rhs) {
  return sbp_cmp_sbp_msg_ephemeris_glo_dep_a_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_ephemeris_glo_dep_a_t &lhs,
                             const sbp_msg_ephemeris_glo_dep_a_t &rhs) {
  return sbp_cmp_sbp_msg_ephemeris_glo_dep_a_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_msg_ephemeris_glo_dep_a_t &lhs,
                              const sbp_msg_ephemeris_glo_dep_a_t &rhs) {
  return sbp_cmp_sbp_msg_ephemeris_glo_dep_a_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_ephemeris_glo_dep_a_t &lhs,
                             const sbp_msg_ephemeris_glo_dep_a_t &rhs) {
  return sbp_cmp_sbp_msg_ephemeris_glo_dep_a_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_msg_ephemeris_glo_dep_a_t &lhs,
                              const sbp_msg_ephemeris_glo_dep_a_t &rhs) {
  return sbp_cmp_sbp_msg_ephemeris_glo_dep_a_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_msg_ephemeris_sbas_dep_b_t &lhs,
                              const sbp_msg_ephemeris_sbas_dep_b_t &rhs) {
  return sbp_cmp_sbp_msg_ephemeris_sbas_dep_b_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_msg_ephemeris_sbas_dep_b_t &lhs,
                              const sbp_msg_ephemeris_sbas_dep_b_t &rhs) {
  return sbp_cmp_sbp_msg_ephemeris_sbas_dep_b_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_ephemeris_sbas_dep_b_t &lhs,
                             const sbp_msg_ephemeris_sbas_dep_b_t &rhs) {
  return sbp_cmp_sbp_msg_ephemeris_sbas_dep_b_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_msg_ephemeris_sbas_dep_b_t &lhs,
                              const sbp_msg_ephemeris_sbas_dep_b_t &rhs) {
  return sbp_cmp_sbp_msg_ephemeris_sbas_dep_b_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_ephemeris_sbas_dep_b_t &lhs,
                             const sbp_msg_ephemeris_sbas_dep_b_t &rhs) {
  return sbp_cmp_sbp_msg_ephemeris_sbas_dep_b_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_msg_ephemeris_sbas_dep_b_t &lhs,
                              const sbp_msg_ephemeris_sbas_dep_b_t &rhs) {
  return sbp_cmp_sbp_msg_ephemeris_sbas_dep_b_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_msg_ephemeris_sbas_t &lhs,
                              const sbp_msg_ephemeris_sbas_t &rhs) {
  return sbp_cmp_sbp_msg_ephemeris_sbas_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_msg_ephemeris_sbas_t &lhs,
                              const sbp_msg_ephemeris_sbas_t &rhs) {
  return sbp_cmp_sbp_msg_ephemeris_sbas_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_ephemeris_sbas_t &lhs,
                             const sbp_msg_ephemeris_sbas_t &rhs) {
  return sbp_cmp_sbp_msg_ephemeris_sbas_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_msg_ephemeris_sbas_t &lhs,
                              const sbp_msg_ephemeris_sbas_t &rhs) {
  return sbp_cmp_sbp_msg_ephemeris_sbas_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_ephemeris_sbas_t &lhs,
                             const sbp_msg_ephemeris_sbas_t &rhs) {
  return sbp_cmp_sbp_msg_ephemeris_sbas_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_msg_ephemeris_sbas_t &lhs,
                              const sbp_msg_ephemeris_sbas_t &rhs) {
  return sbp_cmp_sbp_msg_ephemeris_sbas_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_msg_ephemeris_glo_dep_b_t &lhs,
                              const sbp_msg_ephemeris_glo_dep_b_t &rhs) {
  return sbp_cmp_sbp_msg_ephemeris_glo_dep_b_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_msg_ephemeris_glo_dep_b_t &lhs,
                              const sbp_msg_ephemeris_glo_dep_b_t &rhs) {
  return sbp_cmp_sbp_msg_ephemeris_glo_dep_b_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_ephemeris_glo_dep_b_t &lhs,
                             const sbp_msg_ephemeris_glo_dep_b_t &rhs) {
  return sbp_cmp_sbp_msg_ephemeris_glo_dep_b_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_msg_ephemeris_glo_dep_b_t &lhs,
                              const sbp_msg_ephemeris_glo_dep_b_t &rhs) {
  return sbp_cmp_sbp_msg_ephemeris_glo_dep_b_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_ephemeris_glo_dep_b_t &lhs,
                             const sbp_msg_ephemeris_glo_dep_b_t &rhs) {
  return sbp_cmp_sbp_msg_ephemeris_glo_dep_b_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_msg_ephemeris_glo_dep_b_t &lhs,
                              const sbp_msg_ephemeris_glo_dep_b_t &rhs) {
  return sbp_cmp_sbp_msg_ephemeris_glo_dep_b_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_msg_ephemeris_glo_dep_c_t &lhs,
                              const sbp_msg_ephemeris_glo_dep_c_t &rhs) {
  return sbp_cmp_sbp_msg_ephemeris_glo_dep_c_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_msg_ephemeris_glo_dep_c_t &lhs,
                              const sbp_msg_ephemeris_glo_dep_c_t &rhs) {
  return sbp_cmp_sbp_msg_ephemeris_glo_dep_c_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_ephemeris_glo_dep_c_t &lhs,
                             const sbp_msg_ephemeris_glo_dep_c_t &rhs) {
  return sbp_cmp_sbp_msg_ephemeris_glo_dep_c_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_msg_ephemeris_glo_dep_c_t &lhs,
                              const sbp_msg_ephemeris_glo_dep_c_t &rhs) {
  return sbp_cmp_sbp_msg_ephemeris_glo_dep_c_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_ephemeris_glo_dep_c_t &lhs,
                             const sbp_msg_ephemeris_glo_dep_c_t &rhs) {
  return sbp_cmp_sbp_msg_ephemeris_glo_dep_c_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_msg_ephemeris_glo_dep_c_t &lhs,
                              const sbp_msg_ephemeris_glo_dep_c_t &rhs) {
  return sbp_cmp_sbp_msg_ephemeris_glo_dep_c_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_msg_ephemeris_glo_dep_d_t &lhs,
                              const sbp_msg_ephemeris_glo_dep_d_t &rhs) {
  return sbp_cmp_sbp_msg_ephemeris_glo_dep_d_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_msg_ephemeris_glo_dep_d_t &lhs,
                              const sbp_msg_ephemeris_glo_dep_d_t &rhs) {
  return sbp_cmp_sbp_msg_ephemeris_glo_dep_d_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_ephemeris_glo_dep_d_t &lhs,
                             const sbp_msg_ephemeris_glo_dep_d_t &rhs) {
  return sbp_cmp_sbp_msg_ephemeris_glo_dep_d_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_msg_ephemeris_glo_dep_d_t &lhs,
                              const sbp_msg_ephemeris_glo_dep_d_t &rhs) {
  return sbp_cmp_sbp_msg_ephemeris_glo_dep_d_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_ephemeris_glo_dep_d_t &lhs,
                             const sbp_msg_ephemeris_glo_dep_d_t &rhs) {
  return sbp_cmp_sbp_msg_ephemeris_glo_dep_d_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_msg_ephemeris_glo_dep_d_t &lhs,
                              const sbp_msg_ephemeris_glo_dep_d_t &rhs) {
  return sbp_cmp_sbp_msg_ephemeris_glo_dep_d_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_msg_ephemeris_glo_t &lhs,
                              const sbp_msg_ephemeris_glo_t &rhs) {
  return sbp_cmp_sbp_msg_ephemeris_glo_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_msg_ephemeris_glo_t &lhs,
                              const sbp_msg_ephemeris_glo_t &rhs) {
  return sbp_cmp_sbp_msg_ephemeris_glo_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_ephemeris_glo_t &lhs,
                             const sbp_msg_ephemeris_glo_t &rhs) {
  return sbp_cmp_sbp_msg_ephemeris_glo_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_msg_ephemeris_glo_t &lhs,
                              const sbp_msg_ephemeris_glo_t &rhs) {
  return sbp_cmp_sbp_msg_ephemeris_glo_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_ephemeris_glo_t &lhs,
                             const sbp_msg_ephemeris_glo_t &rhs) {
  return sbp_cmp_sbp_msg_ephemeris_glo_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_msg_ephemeris_glo_t &lhs,
                              const sbp_msg_ephemeris_glo_t &rhs) {
  return sbp_cmp_sbp_msg_ephemeris_glo_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_msg_ephemeris_dep_d_t &lhs,
                              const sbp_msg_ephemeris_dep_d_t &rhs) {
  return sbp_cmp_sbp_msg_ephemeris_dep_d_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_msg_ephemeris_dep_d_t &lhs,
                              const sbp_msg_ephemeris_dep_d_t &rhs) {
  return sbp_cmp_sbp_msg_ephemeris_dep_d_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_ephemeris_dep_d_t &lhs,
                             const sbp_msg_ephemeris_dep_d_t &rhs) {
  return sbp_cmp_sbp_msg_ephemeris_dep_d_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_msg_ephemeris_dep_d_t &lhs,
                              const sbp_msg_ephemeris_dep_d_t &rhs) {
  return sbp_cmp_sbp_msg_ephemeris_dep_d_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_ephemeris_dep_d_t &lhs,
                             const sbp_msg_ephemeris_dep_d_t &rhs) {
  return sbp_cmp_sbp_msg_ephemeris_dep_d_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_msg_ephemeris_dep_d_t &lhs,
                              const sbp_msg_ephemeris_dep_d_t &rhs) {
  return sbp_cmp_sbp_msg_ephemeris_dep_d_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_msg_ephemeris_dep_a_t &lhs,
                              const sbp_msg_ephemeris_dep_a_t &rhs) {
  return sbp_cmp_sbp_msg_ephemeris_dep_a_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_msg_ephemeris_dep_a_t &lhs,
                              const sbp_msg_ephemeris_dep_a_t &rhs) {
  return sbp_cmp_sbp_msg_ephemeris_dep_a_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_ephemeris_dep_a_t &lhs,
                             const sbp_msg_ephemeris_dep_a_t &rhs) {
  return sbp_cmp_sbp_msg_ephemeris_dep_a_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_msg_ephemeris_dep_a_t &lhs,
                              const sbp_msg_ephemeris_dep_a_t &rhs) {
  return sbp_cmp_sbp_msg_ephemeris_dep_a_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_ephemeris_dep_a_t &lhs,
                             const sbp_msg_ephemeris_dep_a_t &rhs) {
  return sbp_cmp_sbp_msg_ephemeris_dep_a_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_msg_ephemeris_dep_a_t &lhs,
                              const sbp_msg_ephemeris_dep_a_t &rhs) {
  return sbp_cmp_sbp_msg_ephemeris_dep_a_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_msg_ephemeris_dep_b_t &lhs,
                              const sbp_msg_ephemeris_dep_b_t &rhs) {
  return sbp_cmp_sbp_msg_ephemeris_dep_b_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_msg_ephemeris_dep_b_t &lhs,
                              const sbp_msg_ephemeris_dep_b_t &rhs) {
  return sbp_cmp_sbp_msg_ephemeris_dep_b_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_ephemeris_dep_b_t &lhs,
                             const sbp_msg_ephemeris_dep_b_t &rhs) {
  return sbp_cmp_sbp_msg_ephemeris_dep_b_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_msg_ephemeris_dep_b_t &lhs,
                              const sbp_msg_ephemeris_dep_b_t &rhs) {
  return sbp_cmp_sbp_msg_ephemeris_dep_b_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_ephemeris_dep_b_t &lhs,
                             const sbp_msg_ephemeris_dep_b_t &rhs) {
  return sbp_cmp_sbp_msg_ephemeris_dep_b_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_msg_ephemeris_dep_b_t &lhs,
                              const sbp_msg_ephemeris_dep_b_t &rhs) {
  return sbp_cmp_sbp_msg_ephemeris_dep_b_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_msg_ephemeris_dep_c_t &lhs,
                              const sbp_msg_ephemeris_dep_c_t &rhs) {
  return sbp_cmp_sbp_msg_ephemeris_dep_c_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_msg_ephemeris_dep_c_t &lhs,
                              const sbp_msg_ephemeris_dep_c_t &rhs) {
  return sbp_cmp_sbp_msg_ephemeris_dep_c_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_ephemeris_dep_c_t &lhs,
                             const sbp_msg_ephemeris_dep_c_t &rhs) {
  return sbp_cmp_sbp_msg_ephemeris_dep_c_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_msg_ephemeris_dep_c_t &lhs,
                              const sbp_msg_ephemeris_dep_c_t &rhs) {
  return sbp_cmp_sbp_msg_ephemeris_dep_c_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_ephemeris_dep_c_t &lhs,
                             const sbp_msg_ephemeris_dep_c_t &rhs) {
  return sbp_cmp_sbp_msg_ephemeris_dep_c_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_msg_ephemeris_dep_c_t &lhs,
                              const sbp_msg_ephemeris_dep_c_t &rhs) {
  return sbp_cmp_sbp_msg_ephemeris_dep_c_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_observation_header_dep_t &lhs,
                              const sbp_observation_header_dep_t &rhs) {
  return sbp_cmp_sbp_observation_header_dep_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_observation_header_dep_t &lhs,
                              const sbp_observation_header_dep_t &rhs) {
  return sbp_cmp_sbp_observation_header_dep_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_observation_header_dep_t &lhs,
                             const sbp_observation_header_dep_t &rhs) {
  return sbp_cmp_sbp_observation_header_dep_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_observation_header_dep_t &lhs,
                              const sbp_observation_header_dep_t &rhs) {
  return sbp_cmp_sbp_observation_header_dep_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_observation_header_dep_t &lhs,
                             const sbp_observation_header_dep_t &rhs) {
  return sbp_cmp_sbp_observation_header_dep_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_observation_header_dep_t &lhs,
                              const sbp_observation_header_dep_t &rhs) {
  return sbp_cmp_sbp_observation_header_dep_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_carrier_phase_dep_a_t &lhs,
                              const sbp_carrier_phase_dep_a_t &rhs) {
  return sbp_cmp_sbp_carrier_phase_dep_a_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_carrier_phase_dep_a_t &lhs,
                              const sbp_carrier_phase_dep_a_t &rhs) {
  return sbp_cmp_sbp_carrier_phase_dep_a_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_carrier_phase_dep_a_t &lhs,
                             const sbp_carrier_phase_dep_a_t &rhs) {
  return sbp_cmp_sbp_carrier_phase_dep_a_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_carrier_phase_dep_a_t &lhs,
                              const sbp_carrier_phase_dep_a_t &rhs) {
  return sbp_cmp_sbp_carrier_phase_dep_a_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_carrier_phase_dep_a_t &lhs,
                             const sbp_carrier_phase_dep_a_t &rhs) {
  return sbp_cmp_sbp_carrier_phase_dep_a_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_carrier_phase_dep_a_t &lhs,
                              const sbp_carrier_phase_dep_a_t &rhs) {
  return sbp_cmp_sbp_carrier_phase_dep_a_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_packed_obs_content_dep_a_t &lhs,
                              const sbp_packed_obs_content_dep_a_t &rhs) {
  return sbp_cmp_sbp_packed_obs_content_dep_a_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_packed_obs_content_dep_a_t &lhs,
                              const sbp_packed_obs_content_dep_a_t &rhs) {
  return sbp_cmp_sbp_packed_obs_content_dep_a_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_packed_obs_content_dep_a_t &lhs,
                             const sbp_packed_obs_content_dep_a_t &rhs) {
  return sbp_cmp_sbp_packed_obs_content_dep_a_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_packed_obs_content_dep_a_t &lhs,
                              const sbp_packed_obs_content_dep_a_t &rhs) {
  return sbp_cmp_sbp_packed_obs_content_dep_a_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_packed_obs_content_dep_a_t &lhs,
                             const sbp_packed_obs_content_dep_a_t &rhs) {
  return sbp_cmp_sbp_packed_obs_content_dep_a_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_packed_obs_content_dep_a_t &lhs,
                              const sbp_packed_obs_content_dep_a_t &rhs) {
  return sbp_cmp_sbp_packed_obs_content_dep_a_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_packed_obs_content_dep_b_t &lhs,
                              const sbp_packed_obs_content_dep_b_t &rhs) {
  return sbp_cmp_sbp_packed_obs_content_dep_b_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_packed_obs_content_dep_b_t &lhs,
                              const sbp_packed_obs_content_dep_b_t &rhs) {
  return sbp_cmp_sbp_packed_obs_content_dep_b_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_packed_obs_content_dep_b_t &lhs,
                             const sbp_packed_obs_content_dep_b_t &rhs) {
  return sbp_cmp_sbp_packed_obs_content_dep_b_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_packed_obs_content_dep_b_t &lhs,
                              const sbp_packed_obs_content_dep_b_t &rhs) {
  return sbp_cmp_sbp_packed_obs_content_dep_b_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_packed_obs_content_dep_b_t &lhs,
                             const sbp_packed_obs_content_dep_b_t &rhs) {
  return sbp_cmp_sbp_packed_obs_content_dep_b_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_packed_obs_content_dep_b_t &lhs,
                              const sbp_packed_obs_content_dep_b_t &rhs) {
  return sbp_cmp_sbp_packed_obs_content_dep_b_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_packed_obs_content_dep_c_t &lhs,
                              const sbp_packed_obs_content_dep_c_t &rhs) {
  return sbp_cmp_sbp_packed_obs_content_dep_c_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_packed_obs_content_dep_c_t &lhs,
                              const sbp_packed_obs_content_dep_c_t &rhs) {
  return sbp_cmp_sbp_packed_obs_content_dep_c_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_packed_obs_content_dep_c_t &lhs,
                             const sbp_packed_obs_content_dep_c_t &rhs) {
  return sbp_cmp_sbp_packed_obs_content_dep_c_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_packed_obs_content_dep_c_t &lhs,
                              const sbp_packed_obs_content_dep_c_t &rhs) {
  return sbp_cmp_sbp_packed_obs_content_dep_c_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_packed_obs_content_dep_c_t &lhs,
                             const sbp_packed_obs_content_dep_c_t &rhs) {
  return sbp_cmp_sbp_packed_obs_content_dep_c_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_packed_obs_content_dep_c_t &lhs,
                              const sbp_packed_obs_content_dep_c_t &rhs) {
  return sbp_cmp_sbp_packed_obs_content_dep_c_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_msg_obs_dep_a_t &lhs,
                              const sbp_msg_obs_dep_a_t &rhs) {
  return sbp_cmp_sbp_msg_obs_dep_a_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_msg_obs_dep_a_t &lhs,
                              const sbp_msg_obs_dep_a_t &rhs) {
  return sbp_cmp_sbp_msg_obs_dep_a_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_obs_dep_a_t &lhs,
                             const sbp_msg_obs_dep_a_t &rhs) {
  return sbp_cmp_sbp_msg_obs_dep_a_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_msg_obs_dep_a_t &lhs,
                              const sbp_msg_obs_dep_a_t &rhs) {
  return sbp_cmp_sbp_msg_obs_dep_a_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_obs_dep_a_t &lhs,
                             const sbp_msg_obs_dep_a_t &rhs) {
  return sbp_cmp_sbp_msg_obs_dep_a_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_msg_obs_dep_a_t &lhs,
                              const sbp_msg_obs_dep_a_t &rhs) {
  return sbp_cmp_sbp_msg_obs_dep_a_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_msg_obs_dep_b_t &lhs,
                              const sbp_msg_obs_dep_b_t &rhs) {
  return sbp_cmp_sbp_msg_obs_dep_b_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_msg_obs_dep_b_t &lhs,
                              const sbp_msg_obs_dep_b_t &rhs) {
  return sbp_cmp_sbp_msg_obs_dep_b_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_obs_dep_b_t &lhs,
                             const sbp_msg_obs_dep_b_t &rhs) {
  return sbp_cmp_sbp_msg_obs_dep_b_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_msg_obs_dep_b_t &lhs,
                              const sbp_msg_obs_dep_b_t &rhs) {
  return sbp_cmp_sbp_msg_obs_dep_b_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_obs_dep_b_t &lhs,
                             const sbp_msg_obs_dep_b_t &rhs) {
  return sbp_cmp_sbp_msg_obs_dep_b_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_msg_obs_dep_b_t &lhs,
                              const sbp_msg_obs_dep_b_t &rhs) {
  return sbp_cmp_sbp_msg_obs_dep_b_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_msg_obs_dep_c_t &lhs,
                              const sbp_msg_obs_dep_c_t &rhs) {
  return sbp_cmp_sbp_msg_obs_dep_c_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_msg_obs_dep_c_t &lhs,
                              const sbp_msg_obs_dep_c_t &rhs) {
  return sbp_cmp_sbp_msg_obs_dep_c_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_obs_dep_c_t &lhs,
                             const sbp_msg_obs_dep_c_t &rhs) {
  return sbp_cmp_sbp_msg_obs_dep_c_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_msg_obs_dep_c_t &lhs,
                              const sbp_msg_obs_dep_c_t &rhs) {
  return sbp_cmp_sbp_msg_obs_dep_c_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_obs_dep_c_t &lhs,
                             const sbp_msg_obs_dep_c_t &rhs) {
  return sbp_cmp_sbp_msg_obs_dep_c_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_msg_obs_dep_c_t &lhs,
                              const sbp_msg_obs_dep_c_t &rhs) {
  return sbp_cmp_sbp_msg_obs_dep_c_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_msg_iono_t &lhs,
                              const sbp_msg_iono_t &rhs) {
  return sbp_cmp_sbp_msg_iono_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_msg_iono_t &lhs,
                              const sbp_msg_iono_t &rhs) {
  return sbp_cmp_sbp_msg_iono_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_iono_t &lhs,
                             const sbp_msg_iono_t &rhs) {
  return sbp_cmp_sbp_msg_iono_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_msg_iono_t &lhs,
                              const sbp_msg_iono_t &rhs) {
  return sbp_cmp_sbp_msg_iono_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_iono_t &lhs,
                             const sbp_msg_iono_t &rhs) {
  return sbp_cmp_sbp_msg_iono_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_msg_iono_t &lhs,
                              const sbp_msg_iono_t &rhs) {
  return sbp_cmp_sbp_msg_iono_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_msg_sv_configuration_gps_dep_t &lhs,
                              const sbp_msg_sv_configuration_gps_dep_t &rhs) {
  return sbp_cmp_sbp_msg_sv_configuration_gps_dep_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_msg_sv_configuration_gps_dep_t &lhs,
                              const sbp_msg_sv_configuration_gps_dep_t &rhs) {
  return sbp_cmp_sbp_msg_sv_configuration_gps_dep_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_sv_configuration_gps_dep_t &lhs,
                             const sbp_msg_sv_configuration_gps_dep_t &rhs) {
  return sbp_cmp_sbp_msg_sv_configuration_gps_dep_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_msg_sv_configuration_gps_dep_t &lhs,
                              const sbp_msg_sv_configuration_gps_dep_t &rhs) {
  return sbp_cmp_sbp_msg_sv_configuration_gps_dep_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_sv_configuration_gps_dep_t &lhs,
                             const sbp_msg_sv_configuration_gps_dep_t &rhs) {
  return sbp_cmp_sbp_msg_sv_configuration_gps_dep_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_msg_sv_configuration_gps_dep_t &lhs,
                              const sbp_msg_sv_configuration_gps_dep_t &rhs) {
  return sbp_cmp_sbp_msg_sv_configuration_gps_dep_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_gnss_capb_t &lhs,
                              const sbp_gnss_capb_t &rhs) {
  return sbp_cmp_sbp_gnss_capb_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_gnss_capb_t &lhs,
                              const sbp_gnss_capb_t &rhs) {
  return sbp_cmp_sbp_gnss_capb_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_gnss_capb_t &lhs,
                             const sbp_gnss_capb_t &rhs) {
  return sbp_cmp_sbp_gnss_capb_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_gnss_capb_t &lhs,
                              const sbp_gnss_capb_t &rhs) {
  return sbp_cmp_sbp_gnss_capb_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_gnss_capb_t &lhs,
                             const sbp_gnss_capb_t &rhs) {
  return sbp_cmp_sbp_gnss_capb_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_gnss_capb_t &lhs,
                              const sbp_gnss_capb_t &rhs) {
  return sbp_cmp_sbp_gnss_capb_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_msg_gnss_capb_t &lhs,
                              const sbp_msg_gnss_capb_t &rhs) {
  return sbp_cmp_sbp_msg_gnss_capb_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_msg_gnss_capb_t &lhs,
                              const sbp_msg_gnss_capb_t &rhs) {
  return sbp_cmp_sbp_msg_gnss_capb_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_gnss_capb_t &lhs,
                             const sbp_msg_gnss_capb_t &rhs) {
  return sbp_cmp_sbp_msg_gnss_capb_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_msg_gnss_capb_t &lhs,
                              const sbp_msg_gnss_capb_t &rhs) {
  return sbp_cmp_sbp_msg_gnss_capb_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_gnss_capb_t &lhs,
                             const sbp_msg_gnss_capb_t &rhs) {
  return sbp_cmp_sbp_msg_gnss_capb_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_msg_gnss_capb_t &lhs,
                              const sbp_msg_gnss_capb_t &rhs) {
  return sbp_cmp_sbp_msg_gnss_capb_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_msg_group_delay_dep_a_t &lhs,
                              const sbp_msg_group_delay_dep_a_t &rhs) {
  return sbp_cmp_sbp_msg_group_delay_dep_a_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_msg_group_delay_dep_a_t &lhs,
                              const sbp_msg_group_delay_dep_a_t &rhs) {
  return sbp_cmp_sbp_msg_group_delay_dep_a_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_group_delay_dep_a_t &lhs,
                             const sbp_msg_group_delay_dep_a_t &rhs) {
  return sbp_cmp_sbp_msg_group_delay_dep_a_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_msg_group_delay_dep_a_t &lhs,
                              const sbp_msg_group_delay_dep_a_t &rhs) {
  return sbp_cmp_sbp_msg_group_delay_dep_a_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_group_delay_dep_a_t &lhs,
                             const sbp_msg_group_delay_dep_a_t &rhs) {
  return sbp_cmp_sbp_msg_group_delay_dep_a_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_msg_group_delay_dep_a_t &lhs,
                              const sbp_msg_group_delay_dep_a_t &rhs) {
  return sbp_cmp_sbp_msg_group_delay_dep_a_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_msg_group_delay_dep_b_t &lhs,
                              const sbp_msg_group_delay_dep_b_t &rhs) {
  return sbp_cmp_sbp_msg_group_delay_dep_b_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_msg_group_delay_dep_b_t &lhs,
                              const sbp_msg_group_delay_dep_b_t &rhs) {
  return sbp_cmp_sbp_msg_group_delay_dep_b_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_group_delay_dep_b_t &lhs,
                             const sbp_msg_group_delay_dep_b_t &rhs) {
  return sbp_cmp_sbp_msg_group_delay_dep_b_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_msg_group_delay_dep_b_t &lhs,
                              const sbp_msg_group_delay_dep_b_t &rhs) {
  return sbp_cmp_sbp_msg_group_delay_dep_b_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_group_delay_dep_b_t &lhs,
                             const sbp_msg_group_delay_dep_b_t &rhs) {
  return sbp_cmp_sbp_msg_group_delay_dep_b_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_msg_group_delay_dep_b_t &lhs,
                              const sbp_msg_group_delay_dep_b_t &rhs) {
  return sbp_cmp_sbp_msg_group_delay_dep_b_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_msg_group_delay_t &lhs,
                              const sbp_msg_group_delay_t &rhs) {
  return sbp_cmp_sbp_msg_group_delay_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_msg_group_delay_t &lhs,
                              const sbp_msg_group_delay_t &rhs) {
  return sbp_cmp_sbp_msg_group_delay_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_group_delay_t &lhs,
                             const sbp_msg_group_delay_t &rhs) {
  return sbp_cmp_sbp_msg_group_delay_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_msg_group_delay_t &lhs,
                              const sbp_msg_group_delay_t &rhs) {
  return sbp_cmp_sbp_msg_group_delay_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_group_delay_t &lhs,
                             const sbp_msg_group_delay_t &rhs) {
  return sbp_cmp_sbp_msg_group_delay_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_msg_group_delay_t &lhs,
                              const sbp_msg_group_delay_t &rhs) {
  return sbp_cmp_sbp_msg_group_delay_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_almanac_common_content_t &lhs,
                              const sbp_almanac_common_content_t &rhs) {
  return sbp_cmp_sbp_almanac_common_content_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_almanac_common_content_t &lhs,
                              const sbp_almanac_common_content_t &rhs) {
  return sbp_cmp_sbp_almanac_common_content_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_almanac_common_content_t &lhs,
                             const sbp_almanac_common_content_t &rhs) {
  return sbp_cmp_sbp_almanac_common_content_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_almanac_common_content_t &lhs,
                              const sbp_almanac_common_content_t &rhs) {
  return sbp_cmp_sbp_almanac_common_content_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_almanac_common_content_t &lhs,
                             const sbp_almanac_common_content_t &rhs) {
  return sbp_cmp_sbp_almanac_common_content_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_almanac_common_content_t &lhs,
                              const sbp_almanac_common_content_t &rhs) {
  return sbp_cmp_sbp_almanac_common_content_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_almanac_common_content_dep_t &lhs,
                              const sbp_almanac_common_content_dep_t &rhs) {
  return sbp_cmp_sbp_almanac_common_content_dep_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_almanac_common_content_dep_t &lhs,
                              const sbp_almanac_common_content_dep_t &rhs) {
  return sbp_cmp_sbp_almanac_common_content_dep_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_almanac_common_content_dep_t &lhs,
                             const sbp_almanac_common_content_dep_t &rhs) {
  return sbp_cmp_sbp_almanac_common_content_dep_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_almanac_common_content_dep_t &lhs,
                              const sbp_almanac_common_content_dep_t &rhs) {
  return sbp_cmp_sbp_almanac_common_content_dep_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_almanac_common_content_dep_t &lhs,
                             const sbp_almanac_common_content_dep_t &rhs) {
  return sbp_cmp_sbp_almanac_common_content_dep_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_almanac_common_content_dep_t &lhs,
                              const sbp_almanac_common_content_dep_t &rhs) {
  return sbp_cmp_sbp_almanac_common_content_dep_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_msg_almanac_gps_dep_t &lhs,
                              const sbp_msg_almanac_gps_dep_t &rhs) {
  return sbp_cmp_sbp_msg_almanac_gps_dep_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_msg_almanac_gps_dep_t &lhs,
                              const sbp_msg_almanac_gps_dep_t &rhs) {
  return sbp_cmp_sbp_msg_almanac_gps_dep_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_almanac_gps_dep_t &lhs,
                             const sbp_msg_almanac_gps_dep_t &rhs) {
  return sbp_cmp_sbp_msg_almanac_gps_dep_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_msg_almanac_gps_dep_t &lhs,
                              const sbp_msg_almanac_gps_dep_t &rhs) {
  return sbp_cmp_sbp_msg_almanac_gps_dep_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_almanac_gps_dep_t &lhs,
                             const sbp_msg_almanac_gps_dep_t &rhs) {
  return sbp_cmp_sbp_msg_almanac_gps_dep_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_msg_almanac_gps_dep_t &lhs,
                              const sbp_msg_almanac_gps_dep_t &rhs) {
  return sbp_cmp_sbp_msg_almanac_gps_dep_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_msg_almanac_gps_t &lhs,
                              const sbp_msg_almanac_gps_t &rhs) {
  return sbp_cmp_sbp_msg_almanac_gps_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_msg_almanac_gps_t &lhs,
                              const sbp_msg_almanac_gps_t &rhs) {
  return sbp_cmp_sbp_msg_almanac_gps_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_almanac_gps_t &lhs,
                             const sbp_msg_almanac_gps_t &rhs) {
  return sbp_cmp_sbp_msg_almanac_gps_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_msg_almanac_gps_t &lhs,
                              const sbp_msg_almanac_gps_t &rhs) {
  return sbp_cmp_sbp_msg_almanac_gps_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_almanac_gps_t &lhs,
                             const sbp_msg_almanac_gps_t &rhs) {
  return sbp_cmp_sbp_msg_almanac_gps_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_msg_almanac_gps_t &lhs,
                              const sbp_msg_almanac_gps_t &rhs) {
  return sbp_cmp_sbp_msg_almanac_gps_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_msg_almanac_glo_dep_t &lhs,
                              const sbp_msg_almanac_glo_dep_t &rhs) {
  return sbp_cmp_sbp_msg_almanac_glo_dep_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_msg_almanac_glo_dep_t &lhs,
                              const sbp_msg_almanac_glo_dep_t &rhs) {
  return sbp_cmp_sbp_msg_almanac_glo_dep_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_almanac_glo_dep_t &lhs,
                             const sbp_msg_almanac_glo_dep_t &rhs) {
  return sbp_cmp_sbp_msg_almanac_glo_dep_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_msg_almanac_glo_dep_t &lhs,
                              const sbp_msg_almanac_glo_dep_t &rhs) {
  return sbp_cmp_sbp_msg_almanac_glo_dep_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_almanac_glo_dep_t &lhs,
                             const sbp_msg_almanac_glo_dep_t &rhs) {
  return sbp_cmp_sbp_msg_almanac_glo_dep_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_msg_almanac_glo_dep_t &lhs,
                              const sbp_msg_almanac_glo_dep_t &rhs) {
  return sbp_cmp_sbp_msg_almanac_glo_dep_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_msg_almanac_glo_t &lhs,
                              const sbp_msg_almanac_glo_t &rhs) {
  return sbp_cmp_sbp_msg_almanac_glo_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_msg_almanac_glo_t &lhs,
                              const sbp_msg_almanac_glo_t &rhs) {
  return sbp_cmp_sbp_msg_almanac_glo_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_almanac_glo_t &lhs,
                             const sbp_msg_almanac_glo_t &rhs) {
  return sbp_cmp_sbp_msg_almanac_glo_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_msg_almanac_glo_t &lhs,
                              const sbp_msg_almanac_glo_t &rhs) {
  return sbp_cmp_sbp_msg_almanac_glo_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_almanac_glo_t &lhs,
                             const sbp_msg_almanac_glo_t &rhs) {
  return sbp_cmp_sbp_msg_almanac_glo_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_msg_almanac_glo_t &lhs,
                              const sbp_msg_almanac_glo_t &rhs) {
  return sbp_cmp_sbp_msg_almanac_glo_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_msg_glo_biases_t &lhs,
                              const sbp_msg_glo_biases_t &rhs) {
  return sbp_cmp_sbp_msg_glo_biases_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_msg_glo_biases_t &lhs,
                              const sbp_msg_glo_biases_t &rhs) {
  return sbp_cmp_sbp_msg_glo_biases_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_glo_biases_t &lhs,
                             const sbp_msg_glo_biases_t &rhs) {
  return sbp_cmp_sbp_msg_glo_biases_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_msg_glo_biases_t &lhs,
                              const sbp_msg_glo_biases_t &rhs) {
  return sbp_cmp_sbp_msg_glo_biases_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_glo_biases_t &lhs,
                             const sbp_msg_glo_biases_t &rhs) {
  return sbp_cmp_sbp_msg_glo_biases_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_msg_glo_biases_t &lhs,
                              const sbp_msg_glo_biases_t &rhs) {
  return sbp_cmp_sbp_msg_glo_biases_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_sv_az_el_t &lhs,
                              const sbp_sv_az_el_t &rhs) {
  return sbp_cmp_sbp_sv_az_el_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_sv_az_el_t &lhs,
                              const sbp_sv_az_el_t &rhs) {
  return sbp_cmp_sbp_sv_az_el_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_sv_az_el_t &lhs,
                             const sbp_sv_az_el_t &rhs) {
  return sbp_cmp_sbp_sv_az_el_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_sv_az_el_t &lhs,
                              const sbp_sv_az_el_t &rhs) {
  return sbp_cmp_sbp_sv_az_el_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_sv_az_el_t &lhs,
                             const sbp_sv_az_el_t &rhs) {
  return sbp_cmp_sbp_sv_az_el_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_sv_az_el_t &lhs,
                              const sbp_sv_az_el_t &rhs) {
  return sbp_cmp_sbp_sv_az_el_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_msg_sv_az_el_t &lhs,
                              const sbp_msg_sv_az_el_t &rhs) {
  return sbp_cmp_sbp_msg_sv_az_el_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_msg_sv_az_el_t &lhs,
                              const sbp_msg_sv_az_el_t &rhs) {
  return sbp_cmp_sbp_msg_sv_az_el_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_sv_az_el_t &lhs,
                             const sbp_msg_sv_az_el_t &rhs) {
  return sbp_cmp_sbp_msg_sv_az_el_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_msg_sv_az_el_t &lhs,
                              const sbp_msg_sv_az_el_t &rhs) {
  return sbp_cmp_sbp_msg_sv_az_el_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_sv_az_el_t &lhs,
                             const sbp_msg_sv_az_el_t &rhs) {
  return sbp_cmp_sbp_msg_sv_az_el_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_msg_sv_az_el_t &lhs,
                              const sbp_msg_sv_az_el_t &rhs) {
  return sbp_cmp_sbp_msg_sv_az_el_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_msg_osr_t &lhs,
                              const sbp_msg_osr_t &rhs) {
  return sbp_cmp_sbp_msg_osr_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_msg_osr_t &lhs,
                              const sbp_msg_osr_t &rhs) {
  return sbp_cmp_sbp_msg_osr_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_osr_t &lhs,
                             const sbp_msg_osr_t &rhs) {
  return sbp_cmp_sbp_msg_osr_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_msg_osr_t &lhs,
                              const sbp_msg_osr_t &rhs) {
  return sbp_cmp_sbp_msg_osr_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_osr_t &lhs,
                             const sbp_msg_osr_t &rhs) {
  return sbp_cmp_sbp_msg_osr_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_msg_osr_t &lhs,
                              const sbp_msg_osr_t &rhs) {
  return sbp_cmp_sbp_msg_osr_t(&lhs, &rhs) >= 0;
}

#endif

#endif /* LIBSBP_NEW_OBSERVATION_MESSAGES_H */
