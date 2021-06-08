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
 * Automatically generated from yaml/swiftnav/sbp/ssr.yaml
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

#ifndef LIBSBP_NEW_SSR_MESSAGES_H
#define LIBSBP_NEW_SSR_MESSAGES_H

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
#include <libsbp/ssr_macros.h>

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
 * SBP_CODEBIASESCONTENT
 *
 *****************************************************************************/
/** SSR code biases corrections for a particular satellite
 *
 * Code biases are to be added to pseudorange. The corrections conform with
 * RTCMv3 MT 1059 / 1065.
 */
typedef struct {
  /**
   * Signal encoded following RTCM specifications (DF380, DF381, DF382 and
   * DF467).
   */
  u8 code;

  /**
   * Code bias value [0.01 m]
   */
  s16 value;
} sbp_code_biases_content_t;

/**
 * Get encoded size of an instance of sbp_code_biases_content_t
 *
 * @param msg sbp_code_biases_content_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_code_biases_content_t(
    const sbp_code_biases_content_t *msg);

/**
 * Encode an instance of sbp_code_biases_content_t to wire representation
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
 * @param msg Instance of sbp_code_biases_content_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_code_biases_content_t(uint8_t *buf, uint8_t len,
                                        uint8_t *n_written,
                                        const sbp_code_biases_content_t *msg);

/**
 * Decode an instance of sbp_code_biases_content_t from wire representation
 *
 * This function decodes the wire representation of a sbp_code_biases_content_t
 * message to the given instance. The caller must specify the length of the
 * buffer in the \p len parameter. If non-null the number of bytes read from the
 * buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_code_biases_content_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_code_biases_content_t(const uint8_t *buf, uint8_t len,
                                        uint8_t *n_read,
                                        sbp_code_biases_content_t *msg);

/**
 * Compare two instances of sbp_code_biases_content_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_code_biases_content_t instance
 * @param b sbp_code_biases_content_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_code_biases_content_t(const sbp_code_biases_content_t *a,
                                      const sbp_code_biases_content_t *b);

/*
 *
 *
 *
 ******************************************************************************
 *
 * SBP_PHASEBIASESCONTENT
 *
 *****************************************************************************/
/** SSR phase biases corrections for a particular satellite
 *
 * Phase biases are to be added to carrier phase measurements.
 */
typedef struct {
  /**
   * Signal encoded following RTCM specifications (DF380, DF381, DF382 and
   * DF467)
   */
  u8 code;

  /**
   * Indicator for integer property
   */
  u8 integer_indicator;

  /**
   * Indicator for two groups of Wide-Lane(s) integer property
   */
  u8 widelane_integer_indicator;

  /**
   * Signal phase discontinuity counter. Increased for every discontinuity in
   * phase.
   */
  u8 discontinuity_counter;

  /**
   * Phase bias for specified signal [0.1 mm]
   */
  s32 bias;
} sbp_phase_biases_content_t;

/**
 * Get encoded size of an instance of sbp_phase_biases_content_t
 *
 * @param msg sbp_phase_biases_content_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_phase_biases_content_t(
    const sbp_phase_biases_content_t *msg);

/**
 * Encode an instance of sbp_phase_biases_content_t to wire representation
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
 * @param msg Instance of sbp_phase_biases_content_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_phase_biases_content_t(uint8_t *buf, uint8_t len,
                                         uint8_t *n_written,
                                         const sbp_phase_biases_content_t *msg);

/**
 * Decode an instance of sbp_phase_biases_content_t from wire representation
 *
 * This function decodes the wire representation of a sbp_phase_biases_content_t
 * message to the given instance. The caller must specify the length of the
 * buffer in the \p len parameter. If non-null the number of bytes read from the
 * buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_phase_biases_content_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_phase_biases_content_t(const uint8_t *buf, uint8_t len,
                                         uint8_t *n_read,
                                         sbp_phase_biases_content_t *msg);

/**
 * Compare two instances of sbp_phase_biases_content_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_phase_biases_content_t instance
 * @param b sbp_phase_biases_content_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_phase_biases_content_t(const sbp_phase_biases_content_t *a,
                                       const sbp_phase_biases_content_t *b);

/*
 *
 *
 *
 ******************************************************************************
 *
 * SBP_STECHEADER
 *
 *****************************************************************************/
/** Header for the MSG_SSR_STEC_CORRECTION message
 *
 * A full set of STEC information will likely span multiple SBP messages, since
 * SBP message a limited to 255 bytes.  The header is used to tie multiple SBP
 * messages into a sequence.
 */
typedef struct {
  /**
   * Unique identifier of the tile set this tile belongs to.
   */
  u16 tile_set_id;

  /**
   * Unique identifier of this tile in the tile set.
   */
  u16 tile_id;

  /**
   * GNSS reference time of the correction
   */
  sbp_gps_time_sec_t time;

  /**
   * Number of messages in the dataset
   */
  u8 num_msgs;

  /**
   * Position of this message in the dataset
   */
  u8 seq_num;

  /**
   * Update interval between consecutive corrections. Encoded following RTCM
   * DF391 specification.
   */
  u8 update_interval;

  /**
   * IOD of the SSR atmospheric correction
   */
  u8 iod_atmo;
} sbp_stec_header_t;

/**
 * Get encoded size of an instance of sbp_stec_header_t
 *
 * @param msg sbp_stec_header_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_stec_header_t(const sbp_stec_header_t *msg);

/**
 * Encode an instance of sbp_stec_header_t to wire representation
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
 * @param msg Instance of sbp_stec_header_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_stec_header_t(uint8_t *buf, uint8_t len, uint8_t *n_written,
                                const sbp_stec_header_t *msg);

/**
 * Decode an instance of sbp_stec_header_t from wire representation
 *
 * This function decodes the wire representation of a sbp_stec_header_t message
 * to the given instance. The caller must specify the length of the buffer in
 * the \p len parameter. If non-null the number of bytes read from the buffer
 * will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_stec_header_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_stec_header_t(const uint8_t *buf, uint8_t len,
                                uint8_t *n_read, sbp_stec_header_t *msg);

/**
 * Compare two instances of sbp_stec_header_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_stec_header_t instance
 * @param b sbp_stec_header_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_stec_header_t(const sbp_stec_header_t *a,
                              const sbp_stec_header_t *b);

/*
 *
 *
 *
 ******************************************************************************
 *
 * SBP_GRIDDEDCORRECTIONHEADER
 *
 *****************************************************************************/
/** Header for the MSG_SSR_GRIDDED_CORRECTION message
 *
 * The LPP message contains nested variable length arrays which are not
 * suppported in SBP, so each grid point will be identified by the index.
 */
typedef struct {
  /**
   * Unique identifier of the tile set this tile belongs to.
   */
  u16 tile_set_id;

  /**
   * Unique identifier of this tile in the tile set.
   */
  u16 tile_id;

  /**
   * GNSS reference time of the correction
   */
  sbp_gps_time_sec_t time;

  /**
   * Number of messages in the dataset
   */
  u16 num_msgs;

  /**
   * Position of this message in the dataset
   */
  u16 seq_num;

  /**
   * Update interval between consecutive corrections. Encoded following RTCM
   * DF391 specification.
   */
  u8 update_interval;

  /**
   * IOD of the SSR atmospheric correction
   */
  u8 iod_atmo;

  /**
   * Quality of the troposphere data. Encoded following RTCM DF389 specification
   * in units of m.
   */
  u8 tropo_quality_indicator;
} sbp_gridded_correction_header_t;

/**
 * Get encoded size of an instance of sbp_gridded_correction_header_t
 *
 * @param msg sbp_gridded_correction_header_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_gridded_correction_header_t(
    const sbp_gridded_correction_header_t *msg);

/**
 * Encode an instance of sbp_gridded_correction_header_t to wire representation
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
 * @param msg Instance of sbp_gridded_correction_header_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_gridded_correction_header_t(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_gridded_correction_header_t *msg);

/**
 * Decode an instance of sbp_gridded_correction_header_t from wire
 * representation
 *
 * This function decodes the wire representation of a
 * sbp_gridded_correction_header_t message to the given instance. The caller
 * must specify the length of the buffer in the \p len parameter. If non-null
 * the number of bytes read from the buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_gridded_correction_header_t
 * instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_gridded_correction_header_t(
    const uint8_t *buf, uint8_t len, uint8_t *n_read,
    sbp_gridded_correction_header_t *msg);

/**
 * Compare two instances of sbp_gridded_correction_header_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_gridded_correction_header_t instance
 * @param b sbp_gridded_correction_header_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_gridded_correction_header_t(
    const sbp_gridded_correction_header_t *a,
    const sbp_gridded_correction_header_t *b);

/*
 *
 *
 *
 ******************************************************************************
 *
 * SBP_STECSATELEMENT
 *
 *****************************************************************************/
/** None
 *
 * STEC polynomial for the given satellite.
 */
typedef struct {
  /**
   * Unique space vehicle identifier
   */
  sbp_sv_id_t sv_id;

  /**
   * Quality of the STEC data. Encoded following RTCM DF389 specification but in
   * units of TECU instead of m.
   */
  u8 stec_quality_indicator;

  /**
   * Coefficents of the STEC polynomial in the order of C00, C01, C10, C11 [C00
   * = 0.05 TECU, C01/C10 = 0.02 TECU/deg, C11 0.02 TECU/deg^2]
   */
  s16 stec_coeff[4];
} sbp_stec_sat_element_t;

/**
 * Get encoded size of an instance of sbp_stec_sat_element_t
 *
 * @param msg sbp_stec_sat_element_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_stec_sat_element_t(
    const sbp_stec_sat_element_t *msg);

/**
 * Encode an instance of sbp_stec_sat_element_t to wire representation
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
 * @param msg Instance of sbp_stec_sat_element_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_stec_sat_element_t(uint8_t *buf, uint8_t len,
                                     uint8_t *n_written,
                                     const sbp_stec_sat_element_t *msg);

/**
 * Decode an instance of sbp_stec_sat_element_t from wire representation
 *
 * This function decodes the wire representation of a sbp_stec_sat_element_t
 * message to the given instance. The caller must specify the length of the
 * buffer in the \p len parameter. If non-null the number of bytes read from the
 * buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_stec_sat_element_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_stec_sat_element_t(const uint8_t *buf, uint8_t len,
                                     uint8_t *n_read,
                                     sbp_stec_sat_element_t *msg);

/**
 * Compare two instances of sbp_stec_sat_element_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_stec_sat_element_t instance
 * @param b sbp_stec_sat_element_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_stec_sat_element_t(const sbp_stec_sat_element_t *a,
                                   const sbp_stec_sat_element_t *b);

/*
 *
 *
 *
 ******************************************************************************
 *
 * SBP_TROPOSPHERICDELAYCORRECTIONNOSTD
 *
 *****************************************************************************/
/** None
 *
 * Troposphere vertical delays at the grid point.
 */
typedef struct {
  /**
   * Hydrostatic vertical delay [4 mm (add 2.3 m to get actual vertical hydro
   * delay)]
   */
  s16 hydro;

  /**
   * Wet vertical delay [4 mm (add 0.252 m to get actual vertical wet delay)]
   */
  s8 wet;
} sbp_tropospheric_delay_correction_no_std_t;

/**
 * Get encoded size of an instance of sbp_tropospheric_delay_correction_no_std_t
 *
 * @param msg sbp_tropospheric_delay_correction_no_std_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_tropospheric_delay_correction_no_std_t(
    const sbp_tropospheric_delay_correction_no_std_t *msg);

/**
 * Encode an instance of sbp_tropospheric_delay_correction_no_std_t to wire
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
 * @param msg Instance of sbp_tropospheric_delay_correction_no_std_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_tropospheric_delay_correction_no_std_t(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_tropospheric_delay_correction_no_std_t *msg);

/**
 * Decode an instance of sbp_tropospheric_delay_correction_no_std_t from wire
 * representation
 *
 * This function decodes the wire representation of a
 * sbp_tropospheric_delay_correction_no_std_t message to the given instance. The
 * caller must specify the length of the buffer in the \p len parameter. If
 * non-null the number of bytes read from the buffer will be returned in \p
 * n_read.
 *
 * @param buf Wire representation of the
 * sbp_tropospheric_delay_correction_no_std_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_tropospheric_delay_correction_no_std_t(
    const uint8_t *buf, uint8_t len, uint8_t *n_read,
    sbp_tropospheric_delay_correction_no_std_t *msg);

/**
 * Compare two instances of sbp_tropospheric_delay_correction_no_std_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_tropospheric_delay_correction_no_std_t instance
 * @param b sbp_tropospheric_delay_correction_no_std_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_tropospheric_delay_correction_no_std_t(
    const sbp_tropospheric_delay_correction_no_std_t *a,
    const sbp_tropospheric_delay_correction_no_std_t *b);

/*
 *
 *
 *
 ******************************************************************************
 *
 * SBP_TROPOSPHERICDELAYCORRECTION
 *
 *****************************************************************************/
/** None
 *
 * Troposphere vertical delays (mean and standard deviation) at the grid point.
 */
typedef struct {
  /**
   * Hydrostatic vertical delay [4 mm (add 2.3 m to get actual vertical hydro
   * delay)]
   */
  s16 hydro;

  /**
   * Wet vertical delay [4 mm (add 0.252 m to get actual vertical wet delay)]
   */
  s8 wet;

  /**
* stddev [modified DF389 scale; class is upper 3 bits, value is lower 5 stddev
<= (3^class * (1 + value/16) - 1) mm
]
   */
  u8 stddev;
} sbp_tropospheric_delay_correction_t;

/**
 * Get encoded size of an instance of sbp_tropospheric_delay_correction_t
 *
 * @param msg sbp_tropospheric_delay_correction_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_tropospheric_delay_correction_t(
    const sbp_tropospheric_delay_correction_t *msg);

/**
 * Encode an instance of sbp_tropospheric_delay_correction_t to wire
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
 * @param msg Instance of sbp_tropospheric_delay_correction_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_tropospheric_delay_correction_t(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_tropospheric_delay_correction_t *msg);

/**
 * Decode an instance of sbp_tropospheric_delay_correction_t from wire
 * representation
 *
 * This function decodes the wire representation of a
 * sbp_tropospheric_delay_correction_t message to the given instance. The caller
 * must specify the length of the buffer in the \p len parameter. If non-null
 * the number of bytes read from the buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_tropospheric_delay_correction_t
 * instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_tropospheric_delay_correction_t(
    const uint8_t *buf, uint8_t len, uint8_t *n_read,
    sbp_tropospheric_delay_correction_t *msg);

/**
 * Compare two instances of sbp_tropospheric_delay_correction_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_tropospheric_delay_correction_t instance
 * @param b sbp_tropospheric_delay_correction_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_tropospheric_delay_correction_t(
    const sbp_tropospheric_delay_correction_t *a,
    const sbp_tropospheric_delay_correction_t *b);

/*
 *
 *
 *
 ******************************************************************************
 *
 * SBP_STECRESIDUALNOSTD
 *
 *****************************************************************************/
/** None
 *
 * STEC residual for the given satellite at the grid point.
 */
typedef struct {
  /**
   * space vehicle identifier
   */
  sbp_sv_id_t sv_id;

  /**
   * STEC residual [0.04 TECU]
   */
  s16 residual;
} sbp_stec_residual_no_std_t;

/**
 * Get encoded size of an instance of sbp_stec_residual_no_std_t
 *
 * @param msg sbp_stec_residual_no_std_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_stec_residual_no_std_t(
    const sbp_stec_residual_no_std_t *msg);

/**
 * Encode an instance of sbp_stec_residual_no_std_t to wire representation
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
 * @param msg Instance of sbp_stec_residual_no_std_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_stec_residual_no_std_t(uint8_t *buf, uint8_t len,
                                         uint8_t *n_written,
                                         const sbp_stec_residual_no_std_t *msg);

/**
 * Decode an instance of sbp_stec_residual_no_std_t from wire representation
 *
 * This function decodes the wire representation of a sbp_stec_residual_no_std_t
 * message to the given instance. The caller must specify the length of the
 * buffer in the \p len parameter. If non-null the number of bytes read from the
 * buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_stec_residual_no_std_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_stec_residual_no_std_t(const uint8_t *buf, uint8_t len,
                                         uint8_t *n_read,
                                         sbp_stec_residual_no_std_t *msg);

/**
 * Compare two instances of sbp_stec_residual_no_std_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_stec_residual_no_std_t instance
 * @param b sbp_stec_residual_no_std_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_stec_residual_no_std_t(const sbp_stec_residual_no_std_t *a,
                                       const sbp_stec_residual_no_std_t *b);

/*
 *
 *
 *
 ******************************************************************************
 *
 * SBP_STECRESIDUAL
 *
 *****************************************************************************/
/** None
 *
 * STEC residual (mean and standard deviation) for the given satellite at the
 * grid point.
 */
typedef struct {
  /**
   * space vehicle identifier
   */
  sbp_sv_id_t sv_id;

  /**
   * STEC residual [0.04 TECU]
   */
  s16 residual;

  /**
* stddev [modified DF389 scale; class is upper 3 bits, value is lower 5 stddev
<= (3^class * (1 + value/16) - 1) * 10 TECU
]
   */
  u8 stddev;
} sbp_stec_residual_t;

/**
 * Get encoded size of an instance of sbp_stec_residual_t
 *
 * @param msg sbp_stec_residual_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_stec_residual_t(const sbp_stec_residual_t *msg);

/**
 * Encode an instance of sbp_stec_residual_t to wire representation
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
 * @param msg Instance of sbp_stec_residual_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_stec_residual_t(uint8_t *buf, uint8_t len, uint8_t *n_written,
                                  const sbp_stec_residual_t *msg);

/**
 * Decode an instance of sbp_stec_residual_t from wire representation
 *
 * This function decodes the wire representation of a sbp_stec_residual_t
 * message to the given instance. The caller must specify the length of the
 * buffer in the \p len parameter. If non-null the number of bytes read from the
 * buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_stec_residual_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_stec_residual_t(const uint8_t *buf, uint8_t len,
                                  uint8_t *n_read, sbp_stec_residual_t *msg);

/**
 * Compare two instances of sbp_stec_residual_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_stec_residual_t instance
 * @param b sbp_stec_residual_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_stec_residual_t(const sbp_stec_residual_t *a,
                                const sbp_stec_residual_t *b);

/*
 *
 *
 *
 ******************************************************************************
 *
 * SBP_MSG_SSR_ORBIT_CLOCK
 *
 *****************************************************************************/
/** Precise orbit and clock correction
 *
 * The precise orbit and clock correction message is to be applied as a delta
 * correction to broadcast ephemeris and is an equivalent to the 1060 /1066 RTCM
 * message types.
 */
typedef struct {
  /**
   * GNSS reference time of the correction
   */
  sbp_gps_time_sec_t time;

  /**
   * GNSS signal identifier (16 bit)
   */
  sbp_sbp_gnss_signal_t sid;

  /**
   * Update interval between consecutive corrections. Encoded following RTCM
   * DF391 specification.
   */
  u8 update_interval;

  /**
   * IOD of the SSR correction. A change of Issue Of Data SSR is used to
   * indicate a change in the SSR generating configuration
   */
  u8 iod_ssr;

  /**
   * Issue of broadcast ephemeris data or IODCRC (Beidou)
   */
  u32 iod;

  /**
   * Orbit radial delta correction [0.1 mm]
   */
  s32 radial;

  /**
   * Orbit along delta correction [0.4 mm]
   */
  s32 along;

  /**
   * Orbit along delta correction [0.4 mm]
   */
  s32 cross;

  /**
   * Velocity of orbit radial delta correction [0.001 mm/s]
   */
  s32 dot_radial;

  /**
   * Velocity of orbit along delta correction [0.004 mm/s]
   */
  s32 dot_along;

  /**
   * Velocity of orbit cross delta correction [0.004 mm/s]
   */
  s32 dot_cross;

  /**
   * C0 polynomial coefficient for correction of broadcast satellite clock [0.1
   * mm]
   */
  s32 c0;

  /**
   * C1 polynomial coefficient for correction of broadcast satellite clock
   * [0.001 mm/s]
   */
  s32 c1;

  /**
   * C2 polynomial coefficient for correction of broadcast satellite clock
   * [0.00002 mm/s^-2]
   */
  s32 c2;
} sbp_msg_ssr_orbit_clock_t;

/**
 * Get encoded size of an instance of sbp_msg_ssr_orbit_clock_t
 *
 * @param msg sbp_msg_ssr_orbit_clock_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_msg_ssr_orbit_clock_t(
    const sbp_msg_ssr_orbit_clock_t *msg);

/**
 * Encode an instance of sbp_msg_ssr_orbit_clock_t to wire representation
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
 * @param msg Instance of sbp_msg_ssr_orbit_clock_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_msg_ssr_orbit_clock_t(uint8_t *buf, uint8_t len,
                                        uint8_t *n_written,
                                        const sbp_msg_ssr_orbit_clock_t *msg);

/**
 * Decode an instance of sbp_msg_ssr_orbit_clock_t from wire representation
 *
 * This function decodes the wire representation of a sbp_msg_ssr_orbit_clock_t
 * message to the given instance. The caller must specify the length of the
 * buffer in the \p len parameter. If non-null the number of bytes read from the
 * buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_msg_ssr_orbit_clock_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_msg_ssr_orbit_clock_t(const uint8_t *buf, uint8_t len,
                                        uint8_t *n_read,
                                        sbp_msg_ssr_orbit_clock_t *msg);
/**
 * Send an instance of sbp_msg_ssr_orbit_clock_t with the given write function
 *
 * An equivalent of #sbp_send_message which operates specifically on
 * sbp_msg_ssr_orbit_clock_t
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
s8 sbp_send_sbp_msg_ssr_orbit_clock_t(struct sbp_state *s, u16 sender_id,
                                      const sbp_msg_ssr_orbit_clock_t *msg,
                                      s32 (*write)(u8 *buff, u32 n,
                                                   void *context));

/**
 * Compare two instances of sbp_msg_ssr_orbit_clock_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_ssr_orbit_clock_t instance
 * @param b sbp_msg_ssr_orbit_clock_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_msg_ssr_orbit_clock_t(const sbp_msg_ssr_orbit_clock_t *a,
                                      const sbp_msg_ssr_orbit_clock_t *b);

/*
 *
 *
 *
 ******************************************************************************
 *
 * SBP_MSG_SSR_CODE_BIASES
 *
 *****************************************************************************/
/** Precise code biases correction
 *
 * The precise code biases message is to be added to the pseudorange of the
 * corresponding signal to get corrected pseudorange. It is an equivalent to the
 * 1059 / 1065 RTCM message types.
 */
typedef struct {
  /**
   * GNSS reference time of the correction
   */
  sbp_gps_time_sec_t time;

  /**
   * GNSS signal identifier (16 bit)
   */
  sbp_sbp_gnss_signal_t sid;

  /**
   * Update interval between consecutive corrections. Encoded following RTCM
   * DF391 specification.
   */
  u8 update_interval;

  /**
   * IOD of the SSR correction. A change of Issue Of Data SSR is used to
   * indicate a change in the SSR generating configuration
   */
  u8 iod_ssr;

  /**
   * Code biases for the different satellite signals
   */
  sbp_code_biases_content_t biases[81];
  /**
   * Number of elements in biases
   *
   * When sending a message fill in this field with the number elements set in
   * biases before calling an appropriate libsbp send function
   *
   * When receiving a message query this field for the number of elements in
   * biases. The value of any elements beyond the index specified in this field
   * is undefined
   */
  u8 n_biases;
} sbp_msg_ssr_code_biases_t;

/**
 * Get encoded size of an instance of sbp_msg_ssr_code_biases_t
 *
 * @param msg sbp_msg_ssr_code_biases_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_msg_ssr_code_biases_t(
    const sbp_msg_ssr_code_biases_t *msg);

/**
 * Encode an instance of sbp_msg_ssr_code_biases_t to wire representation
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
 * @param msg Instance of sbp_msg_ssr_code_biases_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_msg_ssr_code_biases_t(uint8_t *buf, uint8_t len,
                                        uint8_t *n_written,
                                        const sbp_msg_ssr_code_biases_t *msg);

/**
 * Decode an instance of sbp_msg_ssr_code_biases_t from wire representation
 *
 * This function decodes the wire representation of a sbp_msg_ssr_code_biases_t
 * message to the given instance. The caller must specify the length of the
 * buffer in the \p len parameter. If non-null the number of bytes read from the
 * buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_msg_ssr_code_biases_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_msg_ssr_code_biases_t(const uint8_t *buf, uint8_t len,
                                        uint8_t *n_read,
                                        sbp_msg_ssr_code_biases_t *msg);
/**
 * Send an instance of sbp_msg_ssr_code_biases_t with the given write function
 *
 * An equivalent of #sbp_send_message which operates specifically on
 * sbp_msg_ssr_code_biases_t
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
s8 sbp_send_sbp_msg_ssr_code_biases_t(struct sbp_state *s, u16 sender_id,
                                      const sbp_msg_ssr_code_biases_t *msg,
                                      s32 (*write)(u8 *buff, u32 n,
                                                   void *context));

/**
 * Compare two instances of sbp_msg_ssr_code_biases_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_ssr_code_biases_t instance
 * @param b sbp_msg_ssr_code_biases_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_msg_ssr_code_biases_t(const sbp_msg_ssr_code_biases_t *a,
                                      const sbp_msg_ssr_code_biases_t *b);

/*
 *
 *
 *
 ******************************************************************************
 *
 * SBP_MSG_SSR_PHASE_BIASES
 *
 *****************************************************************************/
/** Precise phase biases correction
 *
 * The precise phase biases message contains the biases to be added to the
 * carrier phase of the corresponding signal to get corrected carrier phase
 * measurement, as well as the satellite yaw angle to be applied to compute the
 * phase wind-up correction. It is typically an equivalent to the 1265 RTCM
 * message types.
 */
typedef struct {
  /**
   * GNSS reference time of the correction
   */
  sbp_gps_time_sec_t time;

  /**
   * GNSS signal identifier (16 bit)
   */
  sbp_sbp_gnss_signal_t sid;

  /**
   * Update interval between consecutive corrections. Encoded following RTCM
   * DF391 specification.
   */
  u8 update_interval;

  /**
   * IOD of the SSR correction. A change of Issue Of Data SSR is used to
   * indicate a change in the SSR generating configuration
   */
  u8 iod_ssr;

  /**
   * Indicator for the dispersive phase biases property.
   */
  u8 dispersive_bias;

  /**
   * Consistency indicator for Melbourne-Wubbena linear combinations
   */
  u8 mw_consistency;

  /**
   * Satellite yaw angle [1 / 256 semi-circle]
   */
  u16 yaw;

  /**
   * Satellite yaw angle rate [1 / 8192 semi-circle / s]
   */
  s8 yaw_rate;

  /**
   * Phase biases corrections for a satellite being tracked.
   */
  sbp_phase_biases_content_t biases[30];
  /**
   * Number of elements in biases
   *
   * When sending a message fill in this field with the number elements set in
   * biases before calling an appropriate libsbp send function
   *
   * When receiving a message query this field for the number of elements in
   * biases. The value of any elements beyond the index specified in this field
   * is undefined
   */
  u8 n_biases;
} sbp_msg_ssr_phase_biases_t;

/**
 * Get encoded size of an instance of sbp_msg_ssr_phase_biases_t
 *
 * @param msg sbp_msg_ssr_phase_biases_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_msg_ssr_phase_biases_t(
    const sbp_msg_ssr_phase_biases_t *msg);

/**
 * Encode an instance of sbp_msg_ssr_phase_biases_t to wire representation
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
 * @param msg Instance of sbp_msg_ssr_phase_biases_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_msg_ssr_phase_biases_t(uint8_t *buf, uint8_t len,
                                         uint8_t *n_written,
                                         const sbp_msg_ssr_phase_biases_t *msg);

/**
 * Decode an instance of sbp_msg_ssr_phase_biases_t from wire representation
 *
 * This function decodes the wire representation of a sbp_msg_ssr_phase_biases_t
 * message to the given instance. The caller must specify the length of the
 * buffer in the \p len parameter. If non-null the number of bytes read from the
 * buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_msg_ssr_phase_biases_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_msg_ssr_phase_biases_t(const uint8_t *buf, uint8_t len,
                                         uint8_t *n_read,
                                         sbp_msg_ssr_phase_biases_t *msg);
/**
 * Send an instance of sbp_msg_ssr_phase_biases_t with the given write function
 *
 * An equivalent of #sbp_send_message which operates specifically on
 * sbp_msg_ssr_phase_biases_t
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
s8 sbp_send_sbp_msg_ssr_phase_biases_t(struct sbp_state *s, u16 sender_id,
                                       const sbp_msg_ssr_phase_biases_t *msg,
                                       s32 (*write)(u8 *buff, u32 n,
                                                    void *context));

/**
 * Compare two instances of sbp_msg_ssr_phase_biases_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_ssr_phase_biases_t instance
 * @param b sbp_msg_ssr_phase_biases_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_msg_ssr_phase_biases_t(const sbp_msg_ssr_phase_biases_t *a,
                                       const sbp_msg_ssr_phase_biases_t *b);

/*
 *
 *
 *
 ******************************************************************************
 *
 * SBP_MSG_SSR_STEC_CORRECTION
 *
 *****************************************************************************/
/** STEC correction polynomial coeffcients
 *
 * The Slant Total Electron Content per space vehicle, given as polynomial
 * approximation for a given tile. This should be combined with the
 * MSG_SSR_GRIDDED_CORRECTION message to get the state space representation of
 * the atmospheric delay.
 *
 */
typedef struct {
  /**
   * Header of a STEC polynomial coeffcient message.
   */
  sbp_stec_header_t header;

  /**
   * Array of STEC polynomial coeffcients for each space vehicle.
   */
  sbp_stec_sat_element_t stec_sat_list[21];
  /**
   * Number of elements in stec_sat_list
   *
   * When sending a message fill in this field with the number elements set in
   * stec_sat_list before calling an appropriate libsbp send function
   *
   * When receiving a message query this field for the number of elements in
   * stec_sat_list. The value of any elements beyond the index specified in this
   * field is undefined
   */
  u8 n_stec_sat_list;
} sbp_msg_ssr_stec_correction_t;

/**
 * Get encoded size of an instance of sbp_msg_ssr_stec_correction_t
 *
 * @param msg sbp_msg_ssr_stec_correction_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_msg_ssr_stec_correction_t(
    const sbp_msg_ssr_stec_correction_t *msg);

/**
 * Encode an instance of sbp_msg_ssr_stec_correction_t to wire representation
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
 * @param msg Instance of sbp_msg_ssr_stec_correction_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_msg_ssr_stec_correction_t(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_msg_ssr_stec_correction_t *msg);

/**
 * Decode an instance of sbp_msg_ssr_stec_correction_t from wire representation
 *
 * This function decodes the wire representation of a
 * sbp_msg_ssr_stec_correction_t message to the given instance. The caller must
 * specify the length of the buffer in the \p len parameter. If non-null the
 * number of bytes read from the buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_msg_ssr_stec_correction_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_msg_ssr_stec_correction_t(const uint8_t *buf, uint8_t len,
                                            uint8_t *n_read,
                                            sbp_msg_ssr_stec_correction_t *msg);
/**
 * Send an instance of sbp_msg_ssr_stec_correction_t with the given write
 * function
 *
 * An equivalent of #sbp_send_message which operates specifically on
 * sbp_msg_ssr_stec_correction_t
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
s8 sbp_send_sbp_msg_ssr_stec_correction_t(
    struct sbp_state *s, u16 sender_id,
    const sbp_msg_ssr_stec_correction_t *msg,
    s32 (*write)(u8 *buff, u32 n, void *context));

/**
 * Compare two instances of sbp_msg_ssr_stec_correction_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_ssr_stec_correction_t instance
 * @param b sbp_msg_ssr_stec_correction_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_msg_ssr_stec_correction_t(
    const sbp_msg_ssr_stec_correction_t *a,
    const sbp_msg_ssr_stec_correction_t *b);

/*
 *
 *
 *
 ******************************************************************************
 *
 * SBP_MSG_SSR_GRIDDED_CORRECTION
 *
 *****************************************************************************/
/** Gridded troposphere and STEC correction residuals
 *
 * STEC residuals are per space vehicle, troposphere is not.
 *
 */
typedef struct {
  /**
   * Header of a gridded correction message
   */
  sbp_gridded_correction_header_t header;

  /**
   * Index of the grid point.
   */
  u16 index;

  /**
   * Wet and hydrostatic vertical delays (mean, stddev).
   */
  sbp_tropospheric_delay_correction_t tropo_delay_correction;

  /**
   * STEC residuals for each satellite (mean, stddev).
   */
  sbp_stec_residual_t stec_residuals[46];
  /**
   * Number of elements in stec_residuals
   *
   * When sending a message fill in this field with the number elements set in
   * stec_residuals before calling an appropriate libsbp send function
   *
   * When receiving a message query this field for the number of elements in
   * stec_residuals. The value of any elements beyond the index specified in
   * this field is undefined
   */
  u8 n_stec_residuals;
} sbp_msg_ssr_gridded_correction_t;

/**
 * Get encoded size of an instance of sbp_msg_ssr_gridded_correction_t
 *
 * @param msg sbp_msg_ssr_gridded_correction_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_msg_ssr_gridded_correction_t(
    const sbp_msg_ssr_gridded_correction_t *msg);

/**
 * Encode an instance of sbp_msg_ssr_gridded_correction_t to wire representation
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
 * @param msg Instance of sbp_msg_ssr_gridded_correction_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_msg_ssr_gridded_correction_t(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_msg_ssr_gridded_correction_t *msg);

/**
 * Decode an instance of sbp_msg_ssr_gridded_correction_t from wire
 * representation
 *
 * This function decodes the wire representation of a
 * sbp_msg_ssr_gridded_correction_t message to the given instance. The caller
 * must specify the length of the buffer in the \p len parameter. If non-null
 * the number of bytes read from the buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_msg_ssr_gridded_correction_t
 * instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_msg_ssr_gridded_correction_t(
    const uint8_t *buf, uint8_t len, uint8_t *n_read,
    sbp_msg_ssr_gridded_correction_t *msg);
/**
 * Send an instance of sbp_msg_ssr_gridded_correction_t with the given write
 * function
 *
 * An equivalent of #sbp_send_message which operates specifically on
 * sbp_msg_ssr_gridded_correction_t
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
s8 sbp_send_sbp_msg_ssr_gridded_correction_t(
    struct sbp_state *s, u16 sender_id,
    const sbp_msg_ssr_gridded_correction_t *msg,
    s32 (*write)(u8 *buff, u32 n, void *context));

/**
 * Compare two instances of sbp_msg_ssr_gridded_correction_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_ssr_gridded_correction_t instance
 * @param b sbp_msg_ssr_gridded_correction_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_msg_ssr_gridded_correction_t(
    const sbp_msg_ssr_gridded_correction_t *a,
    const sbp_msg_ssr_gridded_correction_t *b);

/*
 *
 *
 *
 ******************************************************************************
 *
 * SBP_MSG_SSR_TILE_DEFINITION
 *
 *****************************************************************************/
/** Definition of a SSR atmospheric correction tile.

 *
 * Provides the correction point coordinates for the atmospheric correction
 values in the MSG_SSR_STEC_CORRECTION and MSG_SSR_GRIDDED_CORRECTION messages.
 *
 */
typedef struct {
  /**
   * Unique identifier of the tile set this tile belongs to.
   */
  u16 tile_set_id;

  /**
   * Unique identifier of this tile in the tile set.
   * See GNSS-SSR-ArrayOfCorrectionPoints field correctionPointSetID.
   */
  u16 tile_id;

  /**
   * North-West corner correction point latitude.
   *
   * The relation between the latitude X in the range [-90, 90] and the coded
   * number N is:
   *
   * N = floor((X / 90) * 2^14)
   *
   * See GNSS-SSR-ArrayOfCorrectionPoints field referencePointLatitude. [encoded
   * degrees]
   */
  s16 corner_nw_lat;

  /**
   * North-West corner correction point longitude.
   *
   * The relation between the longitude X in the range [-180, 180] and the coded
   * number N is:
   *
   * N = floor((X / 180) * 2^15)
   *
   * See GNSS-SSR-ArrayOfCorrectionPoints field referencePointLongitude.
   * [encoded degrees]
   */
  s16 corner_nw_lon;

  /**
   * Spacing of the correction points in the latitude direction.
   *
   * See GNSS-SSR-ArrayOfCorrectionPoints field stepOfLatitude. [0.01 degrees]
   */
  u16 spacing_lat;

  /**
   * Spacing of the correction points in the longitude direction.
   *
   * See GNSS-SSR-ArrayOfCorrectionPoints field stepOfLongitude. [0.01 degrees]
   */
  u16 spacing_lon;

  /**
   * Number of steps in the latitude direction.
   *
   * See GNSS-SSR-ArrayOfCorrectionPoints field numberOfStepsLatitude.
   */
  u16 rows;

  /**
   * Number of steps in the longitude direction.
   *
   * See GNSS-SSR-ArrayOfCorrectionPoints field numberOfStepsLongitude.
   */
  u16 cols;

  /**
   * Specifies the availability of correction data at the correction points in
   * the array.
   *
   * If a specific bit is enabled (set to 1), the correction is not available.
   * Only the first rows * cols bits are used, the remainder are set to 0. If
   * there are more then 64 correction points the remaining corrections are
   * always available.
   *
   * Starting with the northwest corner of the array (top left on a north
   * oriented map) the correction points are enumerated with row precedence -
   * first row west to east, second row west to east, until last row west to
   * east - ending with the southeast corner of the array.
   *
   * See GNSS-SSR-ArrayOfCorrectionPoints field bitmaskOfGrids but note the
   * definition of the bits is inverted.
   */
  u64 bitmask;
} sbp_msg_ssr_tile_definition_t;

/**
 * Get encoded size of an instance of sbp_msg_ssr_tile_definition_t
 *
 * @param msg sbp_msg_ssr_tile_definition_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_msg_ssr_tile_definition_t(
    const sbp_msg_ssr_tile_definition_t *msg);

/**
 * Encode an instance of sbp_msg_ssr_tile_definition_t to wire representation
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
 * @param msg Instance of sbp_msg_ssr_tile_definition_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_msg_ssr_tile_definition_t(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_msg_ssr_tile_definition_t *msg);

/**
 * Decode an instance of sbp_msg_ssr_tile_definition_t from wire representation
 *
 * This function decodes the wire representation of a
 * sbp_msg_ssr_tile_definition_t message to the given instance. The caller must
 * specify the length of the buffer in the \p len parameter. If non-null the
 * number of bytes read from the buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_msg_ssr_tile_definition_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_msg_ssr_tile_definition_t(const uint8_t *buf, uint8_t len,
                                            uint8_t *n_read,
                                            sbp_msg_ssr_tile_definition_t *msg);
/**
 * Send an instance of sbp_msg_ssr_tile_definition_t with the given write
 * function
 *
 * An equivalent of #sbp_send_message which operates specifically on
 * sbp_msg_ssr_tile_definition_t
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
s8 sbp_send_sbp_msg_ssr_tile_definition_t(
    struct sbp_state *s, u16 sender_id,
    const sbp_msg_ssr_tile_definition_t *msg,
    s32 (*write)(u8 *buff, u32 n, void *context));

/**
 * Compare two instances of sbp_msg_ssr_tile_definition_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_ssr_tile_definition_t instance
 * @param b sbp_msg_ssr_tile_definition_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_msg_ssr_tile_definition_t(
    const sbp_msg_ssr_tile_definition_t *a,
    const sbp_msg_ssr_tile_definition_t *b);

/*
 *
 *
 *
 ******************************************************************************
 *
 * SBP_SATELLITEAPC
 *
 *****************************************************************************/
/** Antenna phase center correction
 *
 * Contains phase center offset and elevation variation corrections for one
 * signal on a satellite.
 */
typedef struct {
  /**
   * GNSS signal identifier (16 bit)
   */
  sbp_sbp_gnss_signal_t sid;

  /**
   * Additional satellite information
   */
  u8 sat_info;

  /**
   * Satellite Code, as defined by IGS. Typically the space vehicle number.
   */
  u16 svn;

  /**
   * Mean phase center offset, X Y and Z axises. See IGS ANTEX file format
   * description for coordinate system definition. [1 mm]
   */
  s16 pco[3];

  /**
   * Elevation dependent phase center variations. First element is 0 degrees
   * separation from the Z axis, subsequent elements represent elevation
   * variations in 1 degree increments. [1 mm]
   */
  s8 pcv[21];
} sbp_satellite_apc_t;

/**
 * Get encoded size of an instance of sbp_satellite_apc_t
 *
 * @param msg sbp_satellite_apc_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_satellite_apc_t(const sbp_satellite_apc_t *msg);

/**
 * Encode an instance of sbp_satellite_apc_t to wire representation
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
 * @param msg Instance of sbp_satellite_apc_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_satellite_apc_t(uint8_t *buf, uint8_t len, uint8_t *n_written,
                                  const sbp_satellite_apc_t *msg);

/**
 * Decode an instance of sbp_satellite_apc_t from wire representation
 *
 * This function decodes the wire representation of a sbp_satellite_apc_t
 * message to the given instance. The caller must specify the length of the
 * buffer in the \p len parameter. If non-null the number of bytes read from the
 * buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_satellite_apc_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_satellite_apc_t(const uint8_t *buf, uint8_t len,
                                  uint8_t *n_read, sbp_satellite_apc_t *msg);

/**
 * Compare two instances of sbp_satellite_apc_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_satellite_apc_t instance
 * @param b sbp_satellite_apc_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_satellite_apc_t(const sbp_satellite_apc_t *a,
                                const sbp_satellite_apc_t *b);

/*
 *
 *
 *
 ******************************************************************************
 *
 * SBP_MSG_SSR_SATELLITE_APC
 *
 *****************************************************************************/
typedef struct {
  /**
   * Satellite antenna phase center corrections
   */
  sbp_satellite_apc_t apc[7];
  /**
   * Number of elements in apc
   *
   * When sending a message fill in this field with the number elements set in
   * apc before calling an appropriate libsbp send function
   *
   * When receiving a message query this field for the number of elements in
   * apc. The value of any elements beyond the index specified in this field is
   * undefined
   */
  u8 n_apc;
} sbp_msg_ssr_satellite_apc_t;

/**
 * Get encoded size of an instance of sbp_msg_ssr_satellite_apc_t
 *
 * @param msg sbp_msg_ssr_satellite_apc_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_msg_ssr_satellite_apc_t(
    const sbp_msg_ssr_satellite_apc_t *msg);

/**
 * Encode an instance of sbp_msg_ssr_satellite_apc_t to wire representation
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
 * @param msg Instance of sbp_msg_ssr_satellite_apc_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_msg_ssr_satellite_apc_t(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_msg_ssr_satellite_apc_t *msg);

/**
 * Decode an instance of sbp_msg_ssr_satellite_apc_t from wire representation
 *
 * This function decodes the wire representation of a
 * sbp_msg_ssr_satellite_apc_t message to the given instance. The caller must
 * specify the length of the buffer in the \p len parameter. If non-null the
 * number of bytes read from the buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_msg_ssr_satellite_apc_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_msg_ssr_satellite_apc_t(const uint8_t *buf, uint8_t len,
                                          uint8_t *n_read,
                                          sbp_msg_ssr_satellite_apc_t *msg);
/**
 * Send an instance of sbp_msg_ssr_satellite_apc_t with the given write function
 *
 * An equivalent of #sbp_send_message which operates specifically on
 * sbp_msg_ssr_satellite_apc_t
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
s8 sbp_send_sbp_msg_ssr_satellite_apc_t(struct sbp_state *s, u16 sender_id,
                                        const sbp_msg_ssr_satellite_apc_t *msg,
                                        s32 (*write)(u8 *buff, u32 n,
                                                     void *context));

/**
 * Compare two instances of sbp_msg_ssr_satellite_apc_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_ssr_satellite_apc_t instance
 * @param b sbp_msg_ssr_satellite_apc_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_msg_ssr_satellite_apc_t(const sbp_msg_ssr_satellite_apc_t *a,
                                        const sbp_msg_ssr_satellite_apc_t *b);

/*
 *
 *
 *
 ******************************************************************************
 *
 * SBP_MSG_SSR_ORBIT_CLOCK_DEP_A
 *
 *****************************************************************************/
typedef struct {
  /**
   * GNSS reference time of the correction
   */
  sbp_gps_time_sec_t time;

  /**
   * GNSS signal identifier (16 bit)
   */
  sbp_sbp_gnss_signal_t sid;

  /**
   * Update interval between consecutive corrections. Encoded following RTCM
   * DF391 specification.
   */
  u8 update_interval;

  /**
   * IOD of the SSR correction. A change of Issue Of Data SSR is used to
   * indicate a change in the SSR generating configuration
   */
  u8 iod_ssr;

  /**
   * Issue of broadcast ephemeris data
   */
  u8 iod;

  /**
   * Orbit radial delta correction [0.1 mm]
   */
  s32 radial;

  /**
   * Orbit along delta correction [0.4 mm]
   */
  s32 along;

  /**
   * Orbit along delta correction [0.4 mm]
   */
  s32 cross;

  /**
   * Velocity of orbit radial delta correction [0.001 mm/s]
   */
  s32 dot_radial;

  /**
   * Velocity of orbit along delta correction [0.004 mm/s]
   */
  s32 dot_along;

  /**
   * Velocity of orbit cross delta correction [0.004 mm/s]
   */
  s32 dot_cross;

  /**
   * C0 polynomial coefficient for correction of broadcast satellite clock [0.1
   * mm]
   */
  s32 c0;

  /**
   * C1 polynomial coefficient for correction of broadcast satellite clock
   * [0.001 mm/s]
   */
  s32 c1;

  /**
   * C2 polynomial coefficient for correction of broadcast satellite clock
   * [0.00002 mm/s^-2]
   */
  s32 c2;
} sbp_msg_ssr_orbit_clock_dep_a_t;

/**
 * Get encoded size of an instance of sbp_msg_ssr_orbit_clock_dep_a_t
 *
 * @param msg sbp_msg_ssr_orbit_clock_dep_a_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_msg_ssr_orbit_clock_dep_a_t(
    const sbp_msg_ssr_orbit_clock_dep_a_t *msg);

/**
 * Encode an instance of sbp_msg_ssr_orbit_clock_dep_a_t to wire representation
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
 * @param msg Instance of sbp_msg_ssr_orbit_clock_dep_a_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_msg_ssr_orbit_clock_dep_a_t(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_msg_ssr_orbit_clock_dep_a_t *msg);

/**
 * Decode an instance of sbp_msg_ssr_orbit_clock_dep_a_t from wire
 * representation
 *
 * This function decodes the wire representation of a
 * sbp_msg_ssr_orbit_clock_dep_a_t message to the given instance. The caller
 * must specify the length of the buffer in the \p len parameter. If non-null
 * the number of bytes read from the buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_msg_ssr_orbit_clock_dep_a_t
 * instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_msg_ssr_orbit_clock_dep_a_t(
    const uint8_t *buf, uint8_t len, uint8_t *n_read,
    sbp_msg_ssr_orbit_clock_dep_a_t *msg);
/**
 * Send an instance of sbp_msg_ssr_orbit_clock_dep_a_t with the given write
 * function
 *
 * An equivalent of #sbp_send_message which operates specifically on
 * sbp_msg_ssr_orbit_clock_dep_a_t
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
s8 sbp_send_sbp_msg_ssr_orbit_clock_dep_a_t(
    struct sbp_state *s, u16 sender_id,
    const sbp_msg_ssr_orbit_clock_dep_a_t *msg,
    s32 (*write)(u8 *buff, u32 n, void *context));

/**
 * Compare two instances of sbp_msg_ssr_orbit_clock_dep_a_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_ssr_orbit_clock_dep_a_t instance
 * @param b sbp_msg_ssr_orbit_clock_dep_a_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_msg_ssr_orbit_clock_dep_a_t(
    const sbp_msg_ssr_orbit_clock_dep_a_t *a,
    const sbp_msg_ssr_orbit_clock_dep_a_t *b);

/*
 *
 *
 *
 ******************************************************************************
 *
 * SBP_STECHEADERDEPA
 *
 *****************************************************************************/
/** Header for MSG_SSR_STEC_CORRECTION_DEP message
 *
 * A full set of STEC information will likely span multiple SBP messages, since
 * SBP message a limited to 255 bytes.  The header is used to tie multiple SBP
 * messages into a sequence.
 */
typedef struct {
  /**
   * GNSS reference time of the correction
   */
  sbp_gps_time_sec_t time;

  /**
   * Number of messages in the dataset
   */
  u8 num_msgs;

  /**
   * Position of this message in the dataset
   */
  u8 seq_num;

  /**
   * Update interval between consecutive corrections. Encoded following RTCM
   * DF391 specification.
   */
  u8 update_interval;

  /**
   * IOD of the SSR atmospheric correction
   */
  u8 iod_atmo;
} sbp_stec_header_dep_a_t;

/**
 * Get encoded size of an instance of sbp_stec_header_dep_a_t
 *
 * @param msg sbp_stec_header_dep_a_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_stec_header_dep_a_t(
    const sbp_stec_header_dep_a_t *msg);

/**
 * Encode an instance of sbp_stec_header_dep_a_t to wire representation
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
 * @param msg Instance of sbp_stec_header_dep_a_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_stec_header_dep_a_t(uint8_t *buf, uint8_t len,
                                      uint8_t *n_written,
                                      const sbp_stec_header_dep_a_t *msg);

/**
 * Decode an instance of sbp_stec_header_dep_a_t from wire representation
 *
 * This function decodes the wire representation of a sbp_stec_header_dep_a_t
 * message to the given instance. The caller must specify the length of the
 * buffer in the \p len parameter. If non-null the number of bytes read from the
 * buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_stec_header_dep_a_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_stec_header_dep_a_t(const uint8_t *buf, uint8_t len,
                                      uint8_t *n_read,
                                      sbp_stec_header_dep_a_t *msg);

/**
 * Compare two instances of sbp_stec_header_dep_a_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_stec_header_dep_a_t instance
 * @param b sbp_stec_header_dep_a_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_stec_header_dep_a_t(const sbp_stec_header_dep_a_t *a,
                                    const sbp_stec_header_dep_a_t *b);

/*
 *
 *
 *
 ******************************************************************************
 *
 * SBP_GRIDDEDCORRECTIONHEADERDEPA
 *
 *****************************************************************************/
/** Header for MSG_SSR_GRIDDED_CORRECTION_DEP
 *
 * The 3GPP message contains nested variable length arrays which are not
 * suppported in SBP, so each grid point will be identified by the index.
 */
typedef struct {
  /**
   * GNSS reference time of the correction
   */
  sbp_gps_time_sec_t time;

  /**
   * Number of messages in the dataset
   */
  u16 num_msgs;

  /**
   * Position of this message in the dataset
   */
  u16 seq_num;

  /**
   * Update interval between consecutive corrections. Encoded following RTCM
   * DF391 specification.
   */
  u8 update_interval;

  /**
   * IOD of the SSR atmospheric correction
   */
  u8 iod_atmo;

  /**
   * Quality of the troposphere data. Encoded following RTCM DF389 specifcation
   * in units of m.
   */
  u8 tropo_quality_indicator;
} sbp_gridded_correction_header_dep_a_t;

/**
 * Get encoded size of an instance of sbp_gridded_correction_header_dep_a_t
 *
 * @param msg sbp_gridded_correction_header_dep_a_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_gridded_correction_header_dep_a_t(
    const sbp_gridded_correction_header_dep_a_t *msg);

/**
 * Encode an instance of sbp_gridded_correction_header_dep_a_t to wire
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
 * @param msg Instance of sbp_gridded_correction_header_dep_a_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_gridded_correction_header_dep_a_t(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_gridded_correction_header_dep_a_t *msg);

/**
 * Decode an instance of sbp_gridded_correction_header_dep_a_t from wire
 * representation
 *
 * This function decodes the wire representation of a
 * sbp_gridded_correction_header_dep_a_t message to the given instance. The
 * caller must specify the length of the buffer in the \p len parameter. If
 * non-null the number of bytes read from the buffer will be returned in \p
 * n_read.
 *
 * @param buf Wire representation of the sbp_gridded_correction_header_dep_a_t
 * instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_gridded_correction_header_dep_a_t(
    const uint8_t *buf, uint8_t len, uint8_t *n_read,
    sbp_gridded_correction_header_dep_a_t *msg);

/**
 * Compare two instances of sbp_gridded_correction_header_dep_a_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_gridded_correction_header_dep_a_t instance
 * @param b sbp_gridded_correction_header_dep_a_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_gridded_correction_header_dep_a_t(
    const sbp_gridded_correction_header_dep_a_t *a,
    const sbp_gridded_correction_header_dep_a_t *b);

/*
 *
 *
 *
 ******************************************************************************
 *
 * SBP_GRIDDEFINITIONHEADERDEPA
 *
 *****************************************************************************/
/** Defines the grid for MSG_SSR_GRIDDED_CORRECTION messages
 *
 * Defines the grid for MSG_SSR_GRIDDED_CORRECTION messages. Also includes an
 * RLE encoded validity list.
 */
typedef struct {
  /**
   * region_size (deg) = 10 / region_size_inverse 0 is an invalid value.
   * [inverse degrees]
   */
  u8 region_size_inverse;

  /**
   * grid height (deg) = grid width (deg) = area_width / region_size 0 is an
   * invalid value.
   */
  u16 area_width;

  /**
   * North-West corner latitude (deg) = region_size * lat_nw_corner_enc - 90
   */
  u16 lat_nw_corner_enc;

  /**
   * North-West corner longitude (deg) = region_size * lon_nw_corner_enc - 180
   */
  u16 lon_nw_corner_enc;

  /**
   * Number of messages in the dataset
   */
  u8 num_msgs;

  /**
   * Postion of this message in the dataset
   */
  u8 seq_num;
} sbp_grid_definition_header_dep_a_t;

/**
 * Get encoded size of an instance of sbp_grid_definition_header_dep_a_t
 *
 * @param msg sbp_grid_definition_header_dep_a_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_grid_definition_header_dep_a_t(
    const sbp_grid_definition_header_dep_a_t *msg);

/**
 * Encode an instance of sbp_grid_definition_header_dep_a_t to wire
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
 * @param msg Instance of sbp_grid_definition_header_dep_a_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_grid_definition_header_dep_a_t(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_grid_definition_header_dep_a_t *msg);

/**
 * Decode an instance of sbp_grid_definition_header_dep_a_t from wire
 * representation
 *
 * This function decodes the wire representation of a
 * sbp_grid_definition_header_dep_a_t message to the given instance. The caller
 * must specify the length of the buffer in the \p len parameter. If non-null
 * the number of bytes read from the buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_grid_definition_header_dep_a_t
 * instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_grid_definition_header_dep_a_t(
    const uint8_t *buf, uint8_t len, uint8_t *n_read,
    sbp_grid_definition_header_dep_a_t *msg);

/**
 * Compare two instances of sbp_grid_definition_header_dep_a_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_grid_definition_header_dep_a_t instance
 * @param b sbp_grid_definition_header_dep_a_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_grid_definition_header_dep_a_t(
    const sbp_grid_definition_header_dep_a_t *a,
    const sbp_grid_definition_header_dep_a_t *b);

/*
 *
 *
 *
 ******************************************************************************
 *
 * SBP_MSG_SSR_STEC_CORRECTION_DEP_A
 *
 *****************************************************************************/
typedef struct {
  /**
   * Header of a STEC message
   */
  sbp_stec_header_dep_a_t header;

  /**
   * Array of STEC information for each space vehicle
   */
  sbp_stec_sat_element_t stec_sat_list[22];
  /**
   * Number of elements in stec_sat_list
   *
   * When sending a message fill in this field with the number elements set in
   * stec_sat_list before calling an appropriate libsbp send function
   *
   * When receiving a message query this field for the number of elements in
   * stec_sat_list. The value of any elements beyond the index specified in this
   * field is undefined
   */
  u8 n_stec_sat_list;
} sbp_msg_ssr_stec_correction_dep_a_t;

/**
 * Get encoded size of an instance of sbp_msg_ssr_stec_correction_dep_a_t
 *
 * @param msg sbp_msg_ssr_stec_correction_dep_a_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_msg_ssr_stec_correction_dep_a_t(
    const sbp_msg_ssr_stec_correction_dep_a_t *msg);

/**
 * Encode an instance of sbp_msg_ssr_stec_correction_dep_a_t to wire
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
 * @param msg Instance of sbp_msg_ssr_stec_correction_dep_a_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_msg_ssr_stec_correction_dep_a_t(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_msg_ssr_stec_correction_dep_a_t *msg);

/**
 * Decode an instance of sbp_msg_ssr_stec_correction_dep_a_t from wire
 * representation
 *
 * This function decodes the wire representation of a
 * sbp_msg_ssr_stec_correction_dep_a_t message to the given instance. The caller
 * must specify the length of the buffer in the \p len parameter. If non-null
 * the number of bytes read from the buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_msg_ssr_stec_correction_dep_a_t
 * instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_msg_ssr_stec_correction_dep_a_t(
    const uint8_t *buf, uint8_t len, uint8_t *n_read,
    sbp_msg_ssr_stec_correction_dep_a_t *msg);
/**
 * Send an instance of sbp_msg_ssr_stec_correction_dep_a_t with the given write
 * function
 *
 * An equivalent of #sbp_send_message which operates specifically on
 * sbp_msg_ssr_stec_correction_dep_a_t
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
s8 sbp_send_sbp_msg_ssr_stec_correction_dep_a_t(
    struct sbp_state *s, u16 sender_id,
    const sbp_msg_ssr_stec_correction_dep_a_t *msg,
    s32 (*write)(u8 *buff, u32 n, void *context));

/**
 * Compare two instances of sbp_msg_ssr_stec_correction_dep_a_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_ssr_stec_correction_dep_a_t instance
 * @param b sbp_msg_ssr_stec_correction_dep_a_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_msg_ssr_stec_correction_dep_a_t(
    const sbp_msg_ssr_stec_correction_dep_a_t *a,
    const sbp_msg_ssr_stec_correction_dep_a_t *b);

/*
 *
 *
 *
 ******************************************************************************
 *
 * SBP_MSG_SSR_GRIDDED_CORRECTION_NO_STD_DEP_A
 *
 *****************************************************************************/
typedef struct {
  /**
   * Header of a Gridded Correction message
   */
  sbp_gridded_correction_header_dep_a_t header;

  /**
   * Index of the grid point
   */
  u16 index;

  /**
   * Wet and hydrostatic vertical delays
   */
  sbp_tropospheric_delay_correction_no_std_t tropo_delay_correction;

  /**
   * STEC residuals for each satellite
   */
  sbp_stec_residual_no_std_t stec_residuals[59];
  /**
   * Number of elements in stec_residuals
   *
   * When sending a message fill in this field with the number elements set in
   * stec_residuals before calling an appropriate libsbp send function
   *
   * When receiving a message query this field for the number of elements in
   * stec_residuals. The value of any elements beyond the index specified in
   * this field is undefined
   */
  u8 n_stec_residuals;
} sbp_msg_ssr_gridded_correction_no_std_dep_a_t;

/**
 * Get encoded size of an instance of
 * sbp_msg_ssr_gridded_correction_no_std_dep_a_t
 *
 * @param msg sbp_msg_ssr_gridded_correction_no_std_dep_a_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_msg_ssr_gridded_correction_no_std_dep_a_t(
    const sbp_msg_ssr_gridded_correction_no_std_dep_a_t *msg);

/**
 * Encode an instance of sbp_msg_ssr_gridded_correction_no_std_dep_a_t to wire
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
 * @param msg Instance of sbp_msg_ssr_gridded_correction_no_std_dep_a_t to
 * encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_msg_ssr_gridded_correction_no_std_dep_a_t(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_msg_ssr_gridded_correction_no_std_dep_a_t *msg);

/**
 * Decode an instance of sbp_msg_ssr_gridded_correction_no_std_dep_a_t from wire
 * representation
 *
 * This function decodes the wire representation of a
 * sbp_msg_ssr_gridded_correction_no_std_dep_a_t message to the given instance.
 * The caller must specify the length of the buffer in the \p len parameter. If
 * non-null the number of bytes read from the buffer will be returned in \p
 * n_read.
 *
 * @param buf Wire representation of the
 * sbp_msg_ssr_gridded_correction_no_std_dep_a_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_msg_ssr_gridded_correction_no_std_dep_a_t(
    const uint8_t *buf, uint8_t len, uint8_t *n_read,
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t *msg);
/**
 * Send an instance of sbp_msg_ssr_gridded_correction_no_std_dep_a_t with the
 * given write function
 *
 * An equivalent of #sbp_send_message which operates specifically on
 * sbp_msg_ssr_gridded_correction_no_std_dep_a_t
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
s8 sbp_send_sbp_msg_ssr_gridded_correction_no_std_dep_a_t(
    struct sbp_state *s, u16 sender_id,
    const sbp_msg_ssr_gridded_correction_no_std_dep_a_t *msg,
    s32 (*write)(u8 *buff, u32 n, void *context));

/**
 * Compare two instances of sbp_msg_ssr_gridded_correction_no_std_dep_a_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_ssr_gridded_correction_no_std_dep_a_t instance
 * @param b sbp_msg_ssr_gridded_correction_no_std_dep_a_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_msg_ssr_gridded_correction_no_std_dep_a_t(
    const sbp_msg_ssr_gridded_correction_no_std_dep_a_t *a,
    const sbp_msg_ssr_gridded_correction_no_std_dep_a_t *b);

/*
 *
 *
 *
 ******************************************************************************
 *
 * SBP_MSG_SSR_GRIDDED_CORRECTION_DEP_A
 *
 *****************************************************************************/
typedef struct {
  /**
   * Header of a Gridded Correction message
   */
  sbp_gridded_correction_header_dep_a_t header;

  /**
   * Index of the grid point
   */
  u16 index;

  /**
   * Wet and hydrostatic vertical delays (mean, stddev)
   */
  sbp_tropospheric_delay_correction_t tropo_delay_correction;

  /**
   * STEC residuals for each satellite (mean, stddev)
   */
  sbp_stec_residual_t stec_residuals[47];
  /**
   * Number of elements in stec_residuals
   *
   * When sending a message fill in this field with the number elements set in
   * stec_residuals before calling an appropriate libsbp send function
   *
   * When receiving a message query this field for the number of elements in
   * stec_residuals. The value of any elements beyond the index specified in
   * this field is undefined
   */
  u8 n_stec_residuals;
} sbp_msg_ssr_gridded_correction_dep_a_t;

/**
 * Get encoded size of an instance of sbp_msg_ssr_gridded_correction_dep_a_t
 *
 * @param msg sbp_msg_ssr_gridded_correction_dep_a_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_msg_ssr_gridded_correction_dep_a_t(
    const sbp_msg_ssr_gridded_correction_dep_a_t *msg);

/**
 * Encode an instance of sbp_msg_ssr_gridded_correction_dep_a_t to wire
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
 * @param msg Instance of sbp_msg_ssr_gridded_correction_dep_a_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_msg_ssr_gridded_correction_dep_a_t(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_msg_ssr_gridded_correction_dep_a_t *msg);

/**
 * Decode an instance of sbp_msg_ssr_gridded_correction_dep_a_t from wire
 * representation
 *
 * This function decodes the wire representation of a
 * sbp_msg_ssr_gridded_correction_dep_a_t message to the given instance. The
 * caller must specify the length of the buffer in the \p len parameter. If
 * non-null the number of bytes read from the buffer will be returned in \p
 * n_read.
 *
 * @param buf Wire representation of the sbp_msg_ssr_gridded_correction_dep_a_t
 * instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_msg_ssr_gridded_correction_dep_a_t(
    const uint8_t *buf, uint8_t len, uint8_t *n_read,
    sbp_msg_ssr_gridded_correction_dep_a_t *msg);
/**
 * Send an instance of sbp_msg_ssr_gridded_correction_dep_a_t with the given
 * write function
 *
 * An equivalent of #sbp_send_message which operates specifically on
 * sbp_msg_ssr_gridded_correction_dep_a_t
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
s8 sbp_send_sbp_msg_ssr_gridded_correction_dep_a_t(
    struct sbp_state *s, u16 sender_id,
    const sbp_msg_ssr_gridded_correction_dep_a_t *msg,
    s32 (*write)(u8 *buff, u32 n, void *context));

/**
 * Compare two instances of sbp_msg_ssr_gridded_correction_dep_a_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_ssr_gridded_correction_dep_a_t instance
 * @param b sbp_msg_ssr_gridded_correction_dep_a_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_msg_ssr_gridded_correction_dep_a_t(
    const sbp_msg_ssr_gridded_correction_dep_a_t *a,
    const sbp_msg_ssr_gridded_correction_dep_a_t *b);

/*
 *
 *
 *
 ******************************************************************************
 *
 * SBP_MSG_SSR_GRID_DEFINITION_DEP_A
 *
 *****************************************************************************/
typedef struct {
  /**
   * Header of a Gridded Correction message
   */
  sbp_grid_definition_header_dep_a_t header;

  /**
   * Run Length Encode list of quadrants that contain valid data. The spec
   * describes the encoding scheme in detail, but essentially the index of the
   * quadrants that contain transitions between valid and invalid (and vice
   * versa) are encoded as u8 integers.
   */
  u8 rle_list[246];
  /**
   * Number of elements in rle_list
   *
   * When sending a message fill in this field with the number elements set in
   * rle_list before calling an appropriate libsbp send function
   *
   * When receiving a message query this field for the number of elements in
   * rle_list. The value of any elements beyond the index specified in this
   * field is undefined
   */
  u8 n_rle_list;
} sbp_msg_ssr_grid_definition_dep_a_t;

/**
 * Get encoded size of an instance of sbp_msg_ssr_grid_definition_dep_a_t
 *
 * @param msg sbp_msg_ssr_grid_definition_dep_a_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_msg_ssr_grid_definition_dep_a_t(
    const sbp_msg_ssr_grid_definition_dep_a_t *msg);

/**
 * Encode an instance of sbp_msg_ssr_grid_definition_dep_a_t to wire
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
 * @param msg Instance of sbp_msg_ssr_grid_definition_dep_a_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_msg_ssr_grid_definition_dep_a_t(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_msg_ssr_grid_definition_dep_a_t *msg);

/**
 * Decode an instance of sbp_msg_ssr_grid_definition_dep_a_t from wire
 * representation
 *
 * This function decodes the wire representation of a
 * sbp_msg_ssr_grid_definition_dep_a_t message to the given instance. The caller
 * must specify the length of the buffer in the \p len parameter. If non-null
 * the number of bytes read from the buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_msg_ssr_grid_definition_dep_a_t
 * instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_msg_ssr_grid_definition_dep_a_t(
    const uint8_t *buf, uint8_t len, uint8_t *n_read,
    sbp_msg_ssr_grid_definition_dep_a_t *msg);
/**
 * Send an instance of sbp_msg_ssr_grid_definition_dep_a_t with the given write
 * function
 *
 * An equivalent of #sbp_send_message which operates specifically on
 * sbp_msg_ssr_grid_definition_dep_a_t
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
s8 sbp_send_sbp_msg_ssr_grid_definition_dep_a_t(
    struct sbp_state *s, u16 sender_id,
    const sbp_msg_ssr_grid_definition_dep_a_t *msg,
    s32 (*write)(u8 *buff, u32 n, void *context));

/**
 * Compare two instances of sbp_msg_ssr_grid_definition_dep_a_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_ssr_grid_definition_dep_a_t instance
 * @param b sbp_msg_ssr_grid_definition_dep_a_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_msg_ssr_grid_definition_dep_a_t(
    const sbp_msg_ssr_grid_definition_dep_a_t *a,
    const sbp_msg_ssr_grid_definition_dep_a_t *b);

#ifdef __cplusplus
}
static inline bool operator==(const sbp_code_biases_content_t &lhs,
                              const sbp_code_biases_content_t &rhs) {
  return sbp_cmp_sbp_code_biases_content_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_code_biases_content_t &lhs,
                              const sbp_code_biases_content_t &rhs) {
  return sbp_cmp_sbp_code_biases_content_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_code_biases_content_t &lhs,
                             const sbp_code_biases_content_t &rhs) {
  return sbp_cmp_sbp_code_biases_content_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_code_biases_content_t &lhs,
                              const sbp_code_biases_content_t &rhs) {
  return sbp_cmp_sbp_code_biases_content_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_code_biases_content_t &lhs,
                             const sbp_code_biases_content_t &rhs) {
  return sbp_cmp_sbp_code_biases_content_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_code_biases_content_t &lhs,
                              const sbp_code_biases_content_t &rhs) {
  return sbp_cmp_sbp_code_biases_content_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_phase_biases_content_t &lhs,
                              const sbp_phase_biases_content_t &rhs) {
  return sbp_cmp_sbp_phase_biases_content_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_phase_biases_content_t &lhs,
                              const sbp_phase_biases_content_t &rhs) {
  return sbp_cmp_sbp_phase_biases_content_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_phase_biases_content_t &lhs,
                             const sbp_phase_biases_content_t &rhs) {
  return sbp_cmp_sbp_phase_biases_content_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_phase_biases_content_t &lhs,
                              const sbp_phase_biases_content_t &rhs) {
  return sbp_cmp_sbp_phase_biases_content_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_phase_biases_content_t &lhs,
                             const sbp_phase_biases_content_t &rhs) {
  return sbp_cmp_sbp_phase_biases_content_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_phase_biases_content_t &lhs,
                              const sbp_phase_biases_content_t &rhs) {
  return sbp_cmp_sbp_phase_biases_content_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_stec_header_t &lhs,
                              const sbp_stec_header_t &rhs) {
  return sbp_cmp_sbp_stec_header_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_stec_header_t &lhs,
                              const sbp_stec_header_t &rhs) {
  return sbp_cmp_sbp_stec_header_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_stec_header_t &lhs,
                             const sbp_stec_header_t &rhs) {
  return sbp_cmp_sbp_stec_header_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_stec_header_t &lhs,
                              const sbp_stec_header_t &rhs) {
  return sbp_cmp_sbp_stec_header_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_stec_header_t &lhs,
                             const sbp_stec_header_t &rhs) {
  return sbp_cmp_sbp_stec_header_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_stec_header_t &lhs,
                              const sbp_stec_header_t &rhs) {
  return sbp_cmp_sbp_stec_header_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_gridded_correction_header_t &lhs,
                              const sbp_gridded_correction_header_t &rhs) {
  return sbp_cmp_sbp_gridded_correction_header_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_gridded_correction_header_t &lhs,
                              const sbp_gridded_correction_header_t &rhs) {
  return sbp_cmp_sbp_gridded_correction_header_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_gridded_correction_header_t &lhs,
                             const sbp_gridded_correction_header_t &rhs) {
  return sbp_cmp_sbp_gridded_correction_header_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_gridded_correction_header_t &lhs,
                              const sbp_gridded_correction_header_t &rhs) {
  return sbp_cmp_sbp_gridded_correction_header_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_gridded_correction_header_t &lhs,
                             const sbp_gridded_correction_header_t &rhs) {
  return sbp_cmp_sbp_gridded_correction_header_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_gridded_correction_header_t &lhs,
                              const sbp_gridded_correction_header_t &rhs) {
  return sbp_cmp_sbp_gridded_correction_header_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_stec_sat_element_t &lhs,
                              const sbp_stec_sat_element_t &rhs) {
  return sbp_cmp_sbp_stec_sat_element_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_stec_sat_element_t &lhs,
                              const sbp_stec_sat_element_t &rhs) {
  return sbp_cmp_sbp_stec_sat_element_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_stec_sat_element_t &lhs,
                             const sbp_stec_sat_element_t &rhs) {
  return sbp_cmp_sbp_stec_sat_element_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_stec_sat_element_t &lhs,
                              const sbp_stec_sat_element_t &rhs) {
  return sbp_cmp_sbp_stec_sat_element_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_stec_sat_element_t &lhs,
                             const sbp_stec_sat_element_t &rhs) {
  return sbp_cmp_sbp_stec_sat_element_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_stec_sat_element_t &lhs,
                              const sbp_stec_sat_element_t &rhs) {
  return sbp_cmp_sbp_stec_sat_element_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(
    const sbp_tropospheric_delay_correction_no_std_t &lhs,
    const sbp_tropospheric_delay_correction_no_std_t &rhs) {
  return sbp_cmp_sbp_tropospheric_delay_correction_no_std_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(
    const sbp_tropospheric_delay_correction_no_std_t &lhs,
    const sbp_tropospheric_delay_correction_no_std_t &rhs) {
  return sbp_cmp_sbp_tropospheric_delay_correction_no_std_t(&lhs, &rhs) != 0;
}

static inline bool operator<(
    const sbp_tropospheric_delay_correction_no_std_t &lhs,
    const sbp_tropospheric_delay_correction_no_std_t &rhs) {
  return sbp_cmp_sbp_tropospheric_delay_correction_no_std_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(
    const sbp_tropospheric_delay_correction_no_std_t &lhs,
    const sbp_tropospheric_delay_correction_no_std_t &rhs) {
  return sbp_cmp_sbp_tropospheric_delay_correction_no_std_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(
    const sbp_tropospheric_delay_correction_no_std_t &lhs,
    const sbp_tropospheric_delay_correction_no_std_t &rhs) {
  return sbp_cmp_sbp_tropospheric_delay_correction_no_std_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(
    const sbp_tropospheric_delay_correction_no_std_t &lhs,
    const sbp_tropospheric_delay_correction_no_std_t &rhs) {
  return sbp_cmp_sbp_tropospheric_delay_correction_no_std_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_tropospheric_delay_correction_t &lhs,
                              const sbp_tropospheric_delay_correction_t &rhs) {
  return sbp_cmp_sbp_tropospheric_delay_correction_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_tropospheric_delay_correction_t &lhs,
                              const sbp_tropospheric_delay_correction_t &rhs) {
  return sbp_cmp_sbp_tropospheric_delay_correction_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_tropospheric_delay_correction_t &lhs,
                             const sbp_tropospheric_delay_correction_t &rhs) {
  return sbp_cmp_sbp_tropospheric_delay_correction_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_tropospheric_delay_correction_t &lhs,
                              const sbp_tropospheric_delay_correction_t &rhs) {
  return sbp_cmp_sbp_tropospheric_delay_correction_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_tropospheric_delay_correction_t &lhs,
                             const sbp_tropospheric_delay_correction_t &rhs) {
  return sbp_cmp_sbp_tropospheric_delay_correction_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_tropospheric_delay_correction_t &lhs,
                              const sbp_tropospheric_delay_correction_t &rhs) {
  return sbp_cmp_sbp_tropospheric_delay_correction_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_stec_residual_no_std_t &lhs,
                              const sbp_stec_residual_no_std_t &rhs) {
  return sbp_cmp_sbp_stec_residual_no_std_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_stec_residual_no_std_t &lhs,
                              const sbp_stec_residual_no_std_t &rhs) {
  return sbp_cmp_sbp_stec_residual_no_std_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_stec_residual_no_std_t &lhs,
                             const sbp_stec_residual_no_std_t &rhs) {
  return sbp_cmp_sbp_stec_residual_no_std_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_stec_residual_no_std_t &lhs,
                              const sbp_stec_residual_no_std_t &rhs) {
  return sbp_cmp_sbp_stec_residual_no_std_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_stec_residual_no_std_t &lhs,
                             const sbp_stec_residual_no_std_t &rhs) {
  return sbp_cmp_sbp_stec_residual_no_std_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_stec_residual_no_std_t &lhs,
                              const sbp_stec_residual_no_std_t &rhs) {
  return sbp_cmp_sbp_stec_residual_no_std_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_stec_residual_t &lhs,
                              const sbp_stec_residual_t &rhs) {
  return sbp_cmp_sbp_stec_residual_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_stec_residual_t &lhs,
                              const sbp_stec_residual_t &rhs) {
  return sbp_cmp_sbp_stec_residual_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_stec_residual_t &lhs,
                             const sbp_stec_residual_t &rhs) {
  return sbp_cmp_sbp_stec_residual_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_stec_residual_t &lhs,
                              const sbp_stec_residual_t &rhs) {
  return sbp_cmp_sbp_stec_residual_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_stec_residual_t &lhs,
                             const sbp_stec_residual_t &rhs) {
  return sbp_cmp_sbp_stec_residual_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_stec_residual_t &lhs,
                              const sbp_stec_residual_t &rhs) {
  return sbp_cmp_sbp_stec_residual_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_msg_ssr_orbit_clock_t &lhs,
                              const sbp_msg_ssr_orbit_clock_t &rhs) {
  return sbp_cmp_sbp_msg_ssr_orbit_clock_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_msg_ssr_orbit_clock_t &lhs,
                              const sbp_msg_ssr_orbit_clock_t &rhs) {
  return sbp_cmp_sbp_msg_ssr_orbit_clock_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_ssr_orbit_clock_t &lhs,
                             const sbp_msg_ssr_orbit_clock_t &rhs) {
  return sbp_cmp_sbp_msg_ssr_orbit_clock_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_msg_ssr_orbit_clock_t &lhs,
                              const sbp_msg_ssr_orbit_clock_t &rhs) {
  return sbp_cmp_sbp_msg_ssr_orbit_clock_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_ssr_orbit_clock_t &lhs,
                             const sbp_msg_ssr_orbit_clock_t &rhs) {
  return sbp_cmp_sbp_msg_ssr_orbit_clock_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_msg_ssr_orbit_clock_t &lhs,
                              const sbp_msg_ssr_orbit_clock_t &rhs) {
  return sbp_cmp_sbp_msg_ssr_orbit_clock_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_msg_ssr_code_biases_t &lhs,
                              const sbp_msg_ssr_code_biases_t &rhs) {
  return sbp_cmp_sbp_msg_ssr_code_biases_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_msg_ssr_code_biases_t &lhs,
                              const sbp_msg_ssr_code_biases_t &rhs) {
  return sbp_cmp_sbp_msg_ssr_code_biases_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_ssr_code_biases_t &lhs,
                             const sbp_msg_ssr_code_biases_t &rhs) {
  return sbp_cmp_sbp_msg_ssr_code_biases_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_msg_ssr_code_biases_t &lhs,
                              const sbp_msg_ssr_code_biases_t &rhs) {
  return sbp_cmp_sbp_msg_ssr_code_biases_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_ssr_code_biases_t &lhs,
                             const sbp_msg_ssr_code_biases_t &rhs) {
  return sbp_cmp_sbp_msg_ssr_code_biases_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_msg_ssr_code_biases_t &lhs,
                              const sbp_msg_ssr_code_biases_t &rhs) {
  return sbp_cmp_sbp_msg_ssr_code_biases_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_msg_ssr_phase_biases_t &lhs,
                              const sbp_msg_ssr_phase_biases_t &rhs) {
  return sbp_cmp_sbp_msg_ssr_phase_biases_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_msg_ssr_phase_biases_t &lhs,
                              const sbp_msg_ssr_phase_biases_t &rhs) {
  return sbp_cmp_sbp_msg_ssr_phase_biases_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_ssr_phase_biases_t &lhs,
                             const sbp_msg_ssr_phase_biases_t &rhs) {
  return sbp_cmp_sbp_msg_ssr_phase_biases_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_msg_ssr_phase_biases_t &lhs,
                              const sbp_msg_ssr_phase_biases_t &rhs) {
  return sbp_cmp_sbp_msg_ssr_phase_biases_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_ssr_phase_biases_t &lhs,
                             const sbp_msg_ssr_phase_biases_t &rhs) {
  return sbp_cmp_sbp_msg_ssr_phase_biases_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_msg_ssr_phase_biases_t &lhs,
                              const sbp_msg_ssr_phase_biases_t &rhs) {
  return sbp_cmp_sbp_msg_ssr_phase_biases_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_msg_ssr_stec_correction_t &lhs,
                              const sbp_msg_ssr_stec_correction_t &rhs) {
  return sbp_cmp_sbp_msg_ssr_stec_correction_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_msg_ssr_stec_correction_t &lhs,
                              const sbp_msg_ssr_stec_correction_t &rhs) {
  return sbp_cmp_sbp_msg_ssr_stec_correction_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_ssr_stec_correction_t &lhs,
                             const sbp_msg_ssr_stec_correction_t &rhs) {
  return sbp_cmp_sbp_msg_ssr_stec_correction_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_msg_ssr_stec_correction_t &lhs,
                              const sbp_msg_ssr_stec_correction_t &rhs) {
  return sbp_cmp_sbp_msg_ssr_stec_correction_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_ssr_stec_correction_t &lhs,
                             const sbp_msg_ssr_stec_correction_t &rhs) {
  return sbp_cmp_sbp_msg_ssr_stec_correction_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_msg_ssr_stec_correction_t &lhs,
                              const sbp_msg_ssr_stec_correction_t &rhs) {
  return sbp_cmp_sbp_msg_ssr_stec_correction_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_msg_ssr_gridded_correction_t &lhs,
                              const sbp_msg_ssr_gridded_correction_t &rhs) {
  return sbp_cmp_sbp_msg_ssr_gridded_correction_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_msg_ssr_gridded_correction_t &lhs,
                              const sbp_msg_ssr_gridded_correction_t &rhs) {
  return sbp_cmp_sbp_msg_ssr_gridded_correction_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_ssr_gridded_correction_t &lhs,
                             const sbp_msg_ssr_gridded_correction_t &rhs) {
  return sbp_cmp_sbp_msg_ssr_gridded_correction_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_msg_ssr_gridded_correction_t &lhs,
                              const sbp_msg_ssr_gridded_correction_t &rhs) {
  return sbp_cmp_sbp_msg_ssr_gridded_correction_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_ssr_gridded_correction_t &lhs,
                             const sbp_msg_ssr_gridded_correction_t &rhs) {
  return sbp_cmp_sbp_msg_ssr_gridded_correction_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_msg_ssr_gridded_correction_t &lhs,
                              const sbp_msg_ssr_gridded_correction_t &rhs) {
  return sbp_cmp_sbp_msg_ssr_gridded_correction_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_msg_ssr_tile_definition_t &lhs,
                              const sbp_msg_ssr_tile_definition_t &rhs) {
  return sbp_cmp_sbp_msg_ssr_tile_definition_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_msg_ssr_tile_definition_t &lhs,
                              const sbp_msg_ssr_tile_definition_t &rhs) {
  return sbp_cmp_sbp_msg_ssr_tile_definition_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_ssr_tile_definition_t &lhs,
                             const sbp_msg_ssr_tile_definition_t &rhs) {
  return sbp_cmp_sbp_msg_ssr_tile_definition_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_msg_ssr_tile_definition_t &lhs,
                              const sbp_msg_ssr_tile_definition_t &rhs) {
  return sbp_cmp_sbp_msg_ssr_tile_definition_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_ssr_tile_definition_t &lhs,
                             const sbp_msg_ssr_tile_definition_t &rhs) {
  return sbp_cmp_sbp_msg_ssr_tile_definition_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_msg_ssr_tile_definition_t &lhs,
                              const sbp_msg_ssr_tile_definition_t &rhs) {
  return sbp_cmp_sbp_msg_ssr_tile_definition_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_satellite_apc_t &lhs,
                              const sbp_satellite_apc_t &rhs) {
  return sbp_cmp_sbp_satellite_apc_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_satellite_apc_t &lhs,
                              const sbp_satellite_apc_t &rhs) {
  return sbp_cmp_sbp_satellite_apc_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_satellite_apc_t &lhs,
                             const sbp_satellite_apc_t &rhs) {
  return sbp_cmp_sbp_satellite_apc_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_satellite_apc_t &lhs,
                              const sbp_satellite_apc_t &rhs) {
  return sbp_cmp_sbp_satellite_apc_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_satellite_apc_t &lhs,
                             const sbp_satellite_apc_t &rhs) {
  return sbp_cmp_sbp_satellite_apc_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_satellite_apc_t &lhs,
                              const sbp_satellite_apc_t &rhs) {
  return sbp_cmp_sbp_satellite_apc_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_msg_ssr_satellite_apc_t &lhs,
                              const sbp_msg_ssr_satellite_apc_t &rhs) {
  return sbp_cmp_sbp_msg_ssr_satellite_apc_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_msg_ssr_satellite_apc_t &lhs,
                              const sbp_msg_ssr_satellite_apc_t &rhs) {
  return sbp_cmp_sbp_msg_ssr_satellite_apc_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_ssr_satellite_apc_t &lhs,
                             const sbp_msg_ssr_satellite_apc_t &rhs) {
  return sbp_cmp_sbp_msg_ssr_satellite_apc_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_msg_ssr_satellite_apc_t &lhs,
                              const sbp_msg_ssr_satellite_apc_t &rhs) {
  return sbp_cmp_sbp_msg_ssr_satellite_apc_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_ssr_satellite_apc_t &lhs,
                             const sbp_msg_ssr_satellite_apc_t &rhs) {
  return sbp_cmp_sbp_msg_ssr_satellite_apc_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_msg_ssr_satellite_apc_t &lhs,
                              const sbp_msg_ssr_satellite_apc_t &rhs) {
  return sbp_cmp_sbp_msg_ssr_satellite_apc_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_msg_ssr_orbit_clock_dep_a_t &lhs,
                              const sbp_msg_ssr_orbit_clock_dep_a_t &rhs) {
  return sbp_cmp_sbp_msg_ssr_orbit_clock_dep_a_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_msg_ssr_orbit_clock_dep_a_t &lhs,
                              const sbp_msg_ssr_orbit_clock_dep_a_t &rhs) {
  return sbp_cmp_sbp_msg_ssr_orbit_clock_dep_a_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_ssr_orbit_clock_dep_a_t &lhs,
                             const sbp_msg_ssr_orbit_clock_dep_a_t &rhs) {
  return sbp_cmp_sbp_msg_ssr_orbit_clock_dep_a_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_msg_ssr_orbit_clock_dep_a_t &lhs,
                              const sbp_msg_ssr_orbit_clock_dep_a_t &rhs) {
  return sbp_cmp_sbp_msg_ssr_orbit_clock_dep_a_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_ssr_orbit_clock_dep_a_t &lhs,
                             const sbp_msg_ssr_orbit_clock_dep_a_t &rhs) {
  return sbp_cmp_sbp_msg_ssr_orbit_clock_dep_a_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_msg_ssr_orbit_clock_dep_a_t &lhs,
                              const sbp_msg_ssr_orbit_clock_dep_a_t &rhs) {
  return sbp_cmp_sbp_msg_ssr_orbit_clock_dep_a_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_stec_header_dep_a_t &lhs,
                              const sbp_stec_header_dep_a_t &rhs) {
  return sbp_cmp_sbp_stec_header_dep_a_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_stec_header_dep_a_t &lhs,
                              const sbp_stec_header_dep_a_t &rhs) {
  return sbp_cmp_sbp_stec_header_dep_a_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_stec_header_dep_a_t &lhs,
                             const sbp_stec_header_dep_a_t &rhs) {
  return sbp_cmp_sbp_stec_header_dep_a_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_stec_header_dep_a_t &lhs,
                              const sbp_stec_header_dep_a_t &rhs) {
  return sbp_cmp_sbp_stec_header_dep_a_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_stec_header_dep_a_t &lhs,
                             const sbp_stec_header_dep_a_t &rhs) {
  return sbp_cmp_sbp_stec_header_dep_a_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_stec_header_dep_a_t &lhs,
                              const sbp_stec_header_dep_a_t &rhs) {
  return sbp_cmp_sbp_stec_header_dep_a_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(
    const sbp_gridded_correction_header_dep_a_t &lhs,
    const sbp_gridded_correction_header_dep_a_t &rhs) {
  return sbp_cmp_sbp_gridded_correction_header_dep_a_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(
    const sbp_gridded_correction_header_dep_a_t &lhs,
    const sbp_gridded_correction_header_dep_a_t &rhs) {
  return sbp_cmp_sbp_gridded_correction_header_dep_a_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_gridded_correction_header_dep_a_t &lhs,
                             const sbp_gridded_correction_header_dep_a_t &rhs) {
  return sbp_cmp_sbp_gridded_correction_header_dep_a_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(
    const sbp_gridded_correction_header_dep_a_t &lhs,
    const sbp_gridded_correction_header_dep_a_t &rhs) {
  return sbp_cmp_sbp_gridded_correction_header_dep_a_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_gridded_correction_header_dep_a_t &lhs,
                             const sbp_gridded_correction_header_dep_a_t &rhs) {
  return sbp_cmp_sbp_gridded_correction_header_dep_a_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(
    const sbp_gridded_correction_header_dep_a_t &lhs,
    const sbp_gridded_correction_header_dep_a_t &rhs) {
  return sbp_cmp_sbp_gridded_correction_header_dep_a_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_grid_definition_header_dep_a_t &lhs,
                              const sbp_grid_definition_header_dep_a_t &rhs) {
  return sbp_cmp_sbp_grid_definition_header_dep_a_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_grid_definition_header_dep_a_t &lhs,
                              const sbp_grid_definition_header_dep_a_t &rhs) {
  return sbp_cmp_sbp_grid_definition_header_dep_a_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_grid_definition_header_dep_a_t &lhs,
                             const sbp_grid_definition_header_dep_a_t &rhs) {
  return sbp_cmp_sbp_grid_definition_header_dep_a_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_grid_definition_header_dep_a_t &lhs,
                              const sbp_grid_definition_header_dep_a_t &rhs) {
  return sbp_cmp_sbp_grid_definition_header_dep_a_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_grid_definition_header_dep_a_t &lhs,
                             const sbp_grid_definition_header_dep_a_t &rhs) {
  return sbp_cmp_sbp_grid_definition_header_dep_a_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_grid_definition_header_dep_a_t &lhs,
                              const sbp_grid_definition_header_dep_a_t &rhs) {
  return sbp_cmp_sbp_grid_definition_header_dep_a_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_msg_ssr_stec_correction_dep_a_t &lhs,
                              const sbp_msg_ssr_stec_correction_dep_a_t &rhs) {
  return sbp_cmp_sbp_msg_ssr_stec_correction_dep_a_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_msg_ssr_stec_correction_dep_a_t &lhs,
                              const sbp_msg_ssr_stec_correction_dep_a_t &rhs) {
  return sbp_cmp_sbp_msg_ssr_stec_correction_dep_a_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_ssr_stec_correction_dep_a_t &lhs,
                             const sbp_msg_ssr_stec_correction_dep_a_t &rhs) {
  return sbp_cmp_sbp_msg_ssr_stec_correction_dep_a_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_msg_ssr_stec_correction_dep_a_t &lhs,
                              const sbp_msg_ssr_stec_correction_dep_a_t &rhs) {
  return sbp_cmp_sbp_msg_ssr_stec_correction_dep_a_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_ssr_stec_correction_dep_a_t &lhs,
                             const sbp_msg_ssr_stec_correction_dep_a_t &rhs) {
  return sbp_cmp_sbp_msg_ssr_stec_correction_dep_a_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_msg_ssr_stec_correction_dep_a_t &lhs,
                              const sbp_msg_ssr_stec_correction_dep_a_t &rhs) {
  return sbp_cmp_sbp_msg_ssr_stec_correction_dep_a_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(
    const sbp_msg_ssr_gridded_correction_no_std_dep_a_t &lhs,
    const sbp_msg_ssr_gridded_correction_no_std_dep_a_t &rhs) {
  return sbp_cmp_sbp_msg_ssr_gridded_correction_no_std_dep_a_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(
    const sbp_msg_ssr_gridded_correction_no_std_dep_a_t &lhs,
    const sbp_msg_ssr_gridded_correction_no_std_dep_a_t &rhs) {
  return sbp_cmp_sbp_msg_ssr_gridded_correction_no_std_dep_a_t(&lhs, &rhs) != 0;
}

static inline bool operator<(
    const sbp_msg_ssr_gridded_correction_no_std_dep_a_t &lhs,
    const sbp_msg_ssr_gridded_correction_no_std_dep_a_t &rhs) {
  return sbp_cmp_sbp_msg_ssr_gridded_correction_no_std_dep_a_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(
    const sbp_msg_ssr_gridded_correction_no_std_dep_a_t &lhs,
    const sbp_msg_ssr_gridded_correction_no_std_dep_a_t &rhs) {
  return sbp_cmp_sbp_msg_ssr_gridded_correction_no_std_dep_a_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(
    const sbp_msg_ssr_gridded_correction_no_std_dep_a_t &lhs,
    const sbp_msg_ssr_gridded_correction_no_std_dep_a_t &rhs) {
  return sbp_cmp_sbp_msg_ssr_gridded_correction_no_std_dep_a_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(
    const sbp_msg_ssr_gridded_correction_no_std_dep_a_t &lhs,
    const sbp_msg_ssr_gridded_correction_no_std_dep_a_t &rhs) {
  return sbp_cmp_sbp_msg_ssr_gridded_correction_no_std_dep_a_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(
    const sbp_msg_ssr_gridded_correction_dep_a_t &lhs,
    const sbp_msg_ssr_gridded_correction_dep_a_t &rhs) {
  return sbp_cmp_sbp_msg_ssr_gridded_correction_dep_a_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(
    const sbp_msg_ssr_gridded_correction_dep_a_t &lhs,
    const sbp_msg_ssr_gridded_correction_dep_a_t &rhs) {
  return sbp_cmp_sbp_msg_ssr_gridded_correction_dep_a_t(&lhs, &rhs) != 0;
}

static inline bool operator<(
    const sbp_msg_ssr_gridded_correction_dep_a_t &lhs,
    const sbp_msg_ssr_gridded_correction_dep_a_t &rhs) {
  return sbp_cmp_sbp_msg_ssr_gridded_correction_dep_a_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(
    const sbp_msg_ssr_gridded_correction_dep_a_t &lhs,
    const sbp_msg_ssr_gridded_correction_dep_a_t &rhs) {
  return sbp_cmp_sbp_msg_ssr_gridded_correction_dep_a_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(
    const sbp_msg_ssr_gridded_correction_dep_a_t &lhs,
    const sbp_msg_ssr_gridded_correction_dep_a_t &rhs) {
  return sbp_cmp_sbp_msg_ssr_gridded_correction_dep_a_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(
    const sbp_msg_ssr_gridded_correction_dep_a_t &lhs,
    const sbp_msg_ssr_gridded_correction_dep_a_t &rhs) {
  return sbp_cmp_sbp_msg_ssr_gridded_correction_dep_a_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_msg_ssr_grid_definition_dep_a_t &lhs,
                              const sbp_msg_ssr_grid_definition_dep_a_t &rhs) {
  return sbp_cmp_sbp_msg_ssr_grid_definition_dep_a_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_msg_ssr_grid_definition_dep_a_t &lhs,
                              const sbp_msg_ssr_grid_definition_dep_a_t &rhs) {
  return sbp_cmp_sbp_msg_ssr_grid_definition_dep_a_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_ssr_grid_definition_dep_a_t &lhs,
                             const sbp_msg_ssr_grid_definition_dep_a_t &rhs) {
  return sbp_cmp_sbp_msg_ssr_grid_definition_dep_a_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_msg_ssr_grid_definition_dep_a_t &lhs,
                              const sbp_msg_ssr_grid_definition_dep_a_t &rhs) {
  return sbp_cmp_sbp_msg_ssr_grid_definition_dep_a_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_ssr_grid_definition_dep_a_t &lhs,
                             const sbp_msg_ssr_grid_definition_dep_a_t &rhs) {
  return sbp_cmp_sbp_msg_ssr_grid_definition_dep_a_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_msg_ssr_grid_definition_dep_a_t &lhs,
                              const sbp_msg_ssr_grid_definition_dep_a_t &rhs) {
  return sbp_cmp_sbp_msg_ssr_grid_definition_dep_a_t(&lhs, &rhs) >= 0;
}

#endif

#endif /* LIBSBP_NEW_SSR_MESSAGES_H */
