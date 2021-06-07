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
 * Automatically generated from yaml/swiftnav/sbp/gnss.yaml
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

#ifndef LIBSBP_NEW_GNSS_MESSAGES_H
#define LIBSBP_NEW_GNSS_MESSAGES_H

#include <endian.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>

#include <libsbp/common.h>
#include <libsbp/gnss_macros.h>
#include <libsbp/new/string/double_null_terminated.h>
#include <libsbp/new/string/multipart.h>
#include <libsbp/new/string/null_terminated.h>
#include <libsbp/new/string/unterminated.h>

#ifdef __cplusplus
extern "C" {
#endif

struct sbp_state;

/** Represents all the relevant information about the signal
 *
 * Signal identifier containing constellation, band, and satellite identifier.
 */
typedef struct {
  /**
   * Constellation-specific satellite identifier. This field for Glonass can
   * either be (100+FCN) where FCN is in [-7,+6] or the Slot ID in [1,28].
   */
  u8 sat;

  /**
   * Signal constellation, band and code
   */
  u8 code;
} sbp_sbp_gnss_signal_t;

/**
 * Get encoded size of an instance of sbp_sbp_gnss_signal_t
 *
 * @param msg sbp_sbp_gnss_signal_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_sbp_gnss_signal_t(const sbp_sbp_gnss_signal_t *msg);

/**
 * Encode an instance of sbp_sbp_gnss_signal_t to wire representation
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
 * @param msg Instance of sbp_sbp_gnss_signal_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_sbp_gnss_signal_t(uint8_t *buf, uint8_t len,
                                    uint8_t *n_written,
                                    const sbp_sbp_gnss_signal_t *msg);

/**
 * Decode an instance of sbp_sbp_gnss_signal_t from wire representation
 *
 * This function decodes the wire representation of a sbp_sbp_gnss_signal_t
 * message to the given instance. The caller must specify the length of the
 * buffer in the \p len parameter. If non-null the number of bytes read from the
 * buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_sbp_gnss_signal_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_sbp_gnss_signal_t(const uint8_t *buf, uint8_t len,
                                    uint8_t *n_read,
                                    sbp_sbp_gnss_signal_t *msg);

/**
 * Compare two instances of sbp_sbp_gnss_signal_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_sbp_gnss_signal_t instance
 * @param b sbp_sbp_gnss_signal_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_sbp_gnss_signal_t(const sbp_sbp_gnss_signal_t *a,
                                  const sbp_sbp_gnss_signal_t *b);

/** Space vehicle identifier
 *
 * A (Constellation ID, satellite ID) tuple that uniquely identifies a space
 * vehicle.
 */
typedef struct {
  /**
   * ID of the space vehicle within its constellation
   */
  u8 satId;

  /**
   * Constellation ID to which the SV belongs
   */
  u8 constellation;
} sbp_sv_id_t;

/**
 * Get encoded size of an instance of sbp_sv_id_t
 *
 * @param msg sbp_sv_id_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_sv_id_t(const sbp_sv_id_t *msg);

/**
 * Encode an instance of sbp_sv_id_t to wire representation
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
 * @param msg Instance of sbp_sv_id_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_sv_id_t(uint8_t *buf, uint8_t len, uint8_t *n_written,
                          const sbp_sv_id_t *msg);

/**
 * Decode an instance of sbp_sv_id_t from wire representation
 *
 * This function decodes the wire representation of a sbp_sv_id_t message to the
 * given instance. The caller must specify the length of the buffer in the \p
 * len parameter. If non-null the number of bytes read from the buffer will be
 * returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_sv_id_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_sv_id_t(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                          sbp_sv_id_t *msg);

/**
 * Compare two instances of sbp_sv_id_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_sv_id_t instance
 * @param b sbp_sv_id_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_sv_id_t(const sbp_sv_id_t *a, const sbp_sv_id_t *b);

/** Deprecated
 *
 * Deprecated.
 */
typedef struct {
  /**
   * Constellation-specific satellite identifier.
   *
   * Note: unlike GnssSignal, GPS satellites are encoded as (PRN - 1). Other
   * constellations do not have this offset.
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
} sbp_gnss_signal_dep_t;

/**
 * Get encoded size of an instance of sbp_gnss_signal_dep_t
 *
 * @param msg sbp_gnss_signal_dep_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_gnss_signal_dep_t(const sbp_gnss_signal_dep_t *msg);

/**
 * Encode an instance of sbp_gnss_signal_dep_t to wire representation
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
 * @param msg Instance of sbp_gnss_signal_dep_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_gnss_signal_dep_t(uint8_t *buf, uint8_t len,
                                    uint8_t *n_written,
                                    const sbp_gnss_signal_dep_t *msg);

/**
 * Decode an instance of sbp_gnss_signal_dep_t from wire representation
 *
 * This function decodes the wire representation of a sbp_gnss_signal_dep_t
 * message to the given instance. The caller must specify the length of the
 * buffer in the \p len parameter. If non-null the number of bytes read from the
 * buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_gnss_signal_dep_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_gnss_signal_dep_t(const uint8_t *buf, uint8_t len,
                                    uint8_t *n_read,
                                    sbp_gnss_signal_dep_t *msg);

/**
 * Compare two instances of sbp_gnss_signal_dep_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_gnss_signal_dep_t instance
 * @param b sbp_gnss_signal_dep_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_gnss_signal_dep_t(const sbp_gnss_signal_dep_t *a,
                                  const sbp_gnss_signal_dep_t *b);

/** Millisecond-accurate GPS time
 *
 * A wire-appropriate GPS time, defined as the number of milliseconds since
 * beginning of the week on the Saturday/Sunday transition.
 */
typedef struct {
  /**
   * Milliseconds since start of GPS week [ms]
   */
  u32 tow;

  /**
   * GPS week number [week]
   */
  u16 wn;
} sbp_gps_time_dep_t;

/**
 * Get encoded size of an instance of sbp_gps_time_dep_t
 *
 * @param msg sbp_gps_time_dep_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_gps_time_dep_t(const sbp_gps_time_dep_t *msg);

/**
 * Encode an instance of sbp_gps_time_dep_t to wire representation
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
 * @param msg Instance of sbp_gps_time_dep_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_gps_time_dep_t(uint8_t *buf, uint8_t len, uint8_t *n_written,
                                 const sbp_gps_time_dep_t *msg);

/**
 * Decode an instance of sbp_gps_time_dep_t from wire representation
 *
 * This function decodes the wire representation of a sbp_gps_time_dep_t message
 * to the given instance. The caller must specify the length of the buffer in
 * the \p len parameter. If non-null the number of bytes read from the buffer
 * will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_gps_time_dep_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_gps_time_dep_t(const uint8_t *buf, uint8_t len,
                                 uint8_t *n_read, sbp_gps_time_dep_t *msg);

/**
 * Compare two instances of sbp_gps_time_dep_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_gps_time_dep_t instance
 * @param b sbp_gps_time_dep_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_gps_time_dep_t(const sbp_gps_time_dep_t *a,
                               const sbp_gps_time_dep_t *b);

/** Whole second accurate GPS time
 *
 * A GPS time, defined as the number of seconds since beginning of the week on
 * the Saturday/Sunday transition.
 */
typedef struct {
  /**
   * Seconds since start of GPS week [s]
   */
  u32 tow;

  /**
   * GPS week number [week]
   */
  u16 wn;
} sbp_gps_time_sec_t;

/**
 * Get encoded size of an instance of sbp_gps_time_sec_t
 *
 * @param msg sbp_gps_time_sec_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_gps_time_sec_t(const sbp_gps_time_sec_t *msg);

/**
 * Encode an instance of sbp_gps_time_sec_t to wire representation
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
 * @param msg Instance of sbp_gps_time_sec_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_gps_time_sec_t(uint8_t *buf, uint8_t len, uint8_t *n_written,
                                 const sbp_gps_time_sec_t *msg);

/**
 * Decode an instance of sbp_gps_time_sec_t from wire representation
 *
 * This function decodes the wire representation of a sbp_gps_time_sec_t message
 * to the given instance. The caller must specify the length of the buffer in
 * the \p len parameter. If non-null the number of bytes read from the buffer
 * will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_gps_time_sec_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_gps_time_sec_t(const uint8_t *buf, uint8_t len,
                                 uint8_t *n_read, sbp_gps_time_sec_t *msg);

/**
 * Compare two instances of sbp_gps_time_sec_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_gps_time_sec_t instance
 * @param b sbp_gps_time_sec_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_gps_time_sec_t(const sbp_gps_time_sec_t *a,
                               const sbp_gps_time_sec_t *b);

/** Nanosecond-accurate receiver clock time
 *
 * A wire-appropriate receiver clock time, defined as the time since the
 * beginning of the week on the Saturday/Sunday transition. In most cases,
 * observations are epoch aligned so ns field will be 0.
 */
typedef struct {
  /**
   * Milliseconds since start of GPS week [ms]
   */
  u32 tow;

  /**
   * Nanosecond residual of millisecond-rounded TOW (ranges from -500000 to
   * 500000) [ns]
   */
  s32 ns_residual;

  /**
   * GPS week number [week]
   */
  u16 wn;
} sbp_sbp_gps_time_t;

/**
 * Get encoded size of an instance of sbp_sbp_gps_time_t
 *
 * @param msg sbp_sbp_gps_time_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_sbp_gps_time_t(const sbp_sbp_gps_time_t *msg);

/**
 * Encode an instance of sbp_sbp_gps_time_t to wire representation
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
 * @param msg Instance of sbp_sbp_gps_time_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_sbp_gps_time_t(uint8_t *buf, uint8_t len, uint8_t *n_written,
                                 const sbp_sbp_gps_time_t *msg);

/**
 * Decode an instance of sbp_sbp_gps_time_t from wire representation
 *
 * This function decodes the wire representation of a sbp_sbp_gps_time_t message
 * to the given instance. The caller must specify the length of the buffer in
 * the \p len parameter. If non-null the number of bytes read from the buffer
 * will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_sbp_gps_time_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_sbp_gps_time_t(const uint8_t *buf, uint8_t len,
                                 uint8_t *n_read, sbp_sbp_gps_time_t *msg);

/**
 * Compare two instances of sbp_sbp_gps_time_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_sbp_gps_time_t instance
 * @param b sbp_sbp_gps_time_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_sbp_gps_time_t(const sbp_sbp_gps_time_t *a,
                               const sbp_sbp_gps_time_t *b);

/** GNSS carrier phase measurement
 *
 * Carrier phase measurement in cycles represented as a 40-bit fixed point
 * number with Q32.8 layout, i.e. 32-bits of whole cycles and 8-bits of
 * fractional cycles. This phase has the same sign as the pseudorange.
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
} sbp_carrier_phase_t;

/**
 * Get encoded size of an instance of sbp_carrier_phase_t
 *
 * @param msg sbp_carrier_phase_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_carrier_phase_t(const sbp_carrier_phase_t *msg);

/**
 * Encode an instance of sbp_carrier_phase_t to wire representation
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
 * @param msg Instance of sbp_carrier_phase_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_carrier_phase_t(uint8_t *buf, uint8_t len, uint8_t *n_written,
                                  const sbp_carrier_phase_t *msg);

/**
 * Decode an instance of sbp_carrier_phase_t from wire representation
 *
 * This function decodes the wire representation of a sbp_carrier_phase_t
 * message to the given instance. The caller must specify the length of the
 * buffer in the \p len parameter. If non-null the number of bytes read from the
 * buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_carrier_phase_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_carrier_phase_t(const uint8_t *buf, uint8_t len,
                                  uint8_t *n_read, sbp_carrier_phase_t *msg);

/**
 * Compare two instances of sbp_carrier_phase_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_carrier_phase_t instance
 * @param b sbp_carrier_phase_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_carrier_phase_t(const sbp_carrier_phase_t *a,
                                const sbp_carrier_phase_t *b);

#ifdef __cplusplus
}
static inline bool operator==(const sbp_sbp_gnss_signal_t &lhs,
                              const sbp_sbp_gnss_signal_t &rhs) {
  return sbp_cmp_sbp_sbp_gnss_signal_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_sbp_gnss_signal_t &lhs,
                              const sbp_sbp_gnss_signal_t &rhs) {
  return sbp_cmp_sbp_sbp_gnss_signal_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_sbp_gnss_signal_t &lhs,
                             const sbp_sbp_gnss_signal_t &rhs) {
  return sbp_cmp_sbp_sbp_gnss_signal_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_sbp_gnss_signal_t &lhs,
                              const sbp_sbp_gnss_signal_t &rhs) {
  return sbp_cmp_sbp_sbp_gnss_signal_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_sbp_gnss_signal_t &lhs,
                             const sbp_sbp_gnss_signal_t &rhs) {
  return sbp_cmp_sbp_sbp_gnss_signal_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_sbp_gnss_signal_t &lhs,
                              const sbp_sbp_gnss_signal_t &rhs) {
  return sbp_cmp_sbp_sbp_gnss_signal_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_sv_id_t &lhs, const sbp_sv_id_t &rhs) {
  return sbp_cmp_sbp_sv_id_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_sv_id_t &lhs, const sbp_sv_id_t &rhs) {
  return sbp_cmp_sbp_sv_id_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_sv_id_t &lhs, const sbp_sv_id_t &rhs) {
  return sbp_cmp_sbp_sv_id_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_sv_id_t &lhs, const sbp_sv_id_t &rhs) {
  return sbp_cmp_sbp_sv_id_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_sv_id_t &lhs, const sbp_sv_id_t &rhs) {
  return sbp_cmp_sbp_sv_id_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_sv_id_t &lhs, const sbp_sv_id_t &rhs) {
  return sbp_cmp_sbp_sv_id_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_gnss_signal_dep_t &lhs,
                              const sbp_gnss_signal_dep_t &rhs) {
  return sbp_cmp_sbp_gnss_signal_dep_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_gnss_signal_dep_t &lhs,
                              const sbp_gnss_signal_dep_t &rhs) {
  return sbp_cmp_sbp_gnss_signal_dep_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_gnss_signal_dep_t &lhs,
                             const sbp_gnss_signal_dep_t &rhs) {
  return sbp_cmp_sbp_gnss_signal_dep_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_gnss_signal_dep_t &lhs,
                              const sbp_gnss_signal_dep_t &rhs) {
  return sbp_cmp_sbp_gnss_signal_dep_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_gnss_signal_dep_t &lhs,
                             const sbp_gnss_signal_dep_t &rhs) {
  return sbp_cmp_sbp_gnss_signal_dep_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_gnss_signal_dep_t &lhs,
                              const sbp_gnss_signal_dep_t &rhs) {
  return sbp_cmp_sbp_gnss_signal_dep_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_gps_time_dep_t &lhs,
                              const sbp_gps_time_dep_t &rhs) {
  return sbp_cmp_sbp_gps_time_dep_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_gps_time_dep_t &lhs,
                              const sbp_gps_time_dep_t &rhs) {
  return sbp_cmp_sbp_gps_time_dep_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_gps_time_dep_t &lhs,
                             const sbp_gps_time_dep_t &rhs) {
  return sbp_cmp_sbp_gps_time_dep_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_gps_time_dep_t &lhs,
                              const sbp_gps_time_dep_t &rhs) {
  return sbp_cmp_sbp_gps_time_dep_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_gps_time_dep_t &lhs,
                             const sbp_gps_time_dep_t &rhs) {
  return sbp_cmp_sbp_gps_time_dep_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_gps_time_dep_t &lhs,
                              const sbp_gps_time_dep_t &rhs) {
  return sbp_cmp_sbp_gps_time_dep_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_gps_time_sec_t &lhs,
                              const sbp_gps_time_sec_t &rhs) {
  return sbp_cmp_sbp_gps_time_sec_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_gps_time_sec_t &lhs,
                              const sbp_gps_time_sec_t &rhs) {
  return sbp_cmp_sbp_gps_time_sec_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_gps_time_sec_t &lhs,
                             const sbp_gps_time_sec_t &rhs) {
  return sbp_cmp_sbp_gps_time_sec_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_gps_time_sec_t &lhs,
                              const sbp_gps_time_sec_t &rhs) {
  return sbp_cmp_sbp_gps_time_sec_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_gps_time_sec_t &lhs,
                             const sbp_gps_time_sec_t &rhs) {
  return sbp_cmp_sbp_gps_time_sec_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_gps_time_sec_t &lhs,
                              const sbp_gps_time_sec_t &rhs) {
  return sbp_cmp_sbp_gps_time_sec_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_sbp_gps_time_t &lhs,
                              const sbp_sbp_gps_time_t &rhs) {
  return sbp_cmp_sbp_sbp_gps_time_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_sbp_gps_time_t &lhs,
                              const sbp_sbp_gps_time_t &rhs) {
  return sbp_cmp_sbp_sbp_gps_time_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_sbp_gps_time_t &lhs,
                             const sbp_sbp_gps_time_t &rhs) {
  return sbp_cmp_sbp_sbp_gps_time_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_sbp_gps_time_t &lhs,
                              const sbp_sbp_gps_time_t &rhs) {
  return sbp_cmp_sbp_sbp_gps_time_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_sbp_gps_time_t &lhs,
                             const sbp_sbp_gps_time_t &rhs) {
  return sbp_cmp_sbp_sbp_gps_time_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_sbp_gps_time_t &lhs,
                              const sbp_sbp_gps_time_t &rhs) {
  return sbp_cmp_sbp_sbp_gps_time_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_carrier_phase_t &lhs,
                              const sbp_carrier_phase_t &rhs) {
  return sbp_cmp_sbp_carrier_phase_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_carrier_phase_t &lhs,
                              const sbp_carrier_phase_t &rhs) {
  return sbp_cmp_sbp_carrier_phase_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_carrier_phase_t &lhs,
                             const sbp_carrier_phase_t &rhs) {
  return sbp_cmp_sbp_carrier_phase_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_carrier_phase_t &lhs,
                              const sbp_carrier_phase_t &rhs) {
  return sbp_cmp_sbp_carrier_phase_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_carrier_phase_t &lhs,
                             const sbp_carrier_phase_t &rhs) {
  return sbp_cmp_sbp_carrier_phase_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_carrier_phase_t &lhs,
                              const sbp_carrier_phase_t &rhs) {
  return sbp_cmp_sbp_carrier_phase_t(&lhs, &rhs) >= 0;
}

#endif

#endif /* LIBSBP_NEW_GNSS_MESSAGES_H */
