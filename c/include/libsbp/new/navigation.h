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
 * Automatically generated from yaml/swiftnav/sbp/navigation.yaml
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

#ifndef LIBSBP_NEW_NAVIGATION_MESSAGES_H
#define LIBSBP_NEW_NAVIGATION_MESSAGES_H

#include <endian.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>

#include <libsbp/common.h>
#include <libsbp/navigation_macros.h>
#include <libsbp/new/string/double_null_terminated.h>
#include <libsbp/new/string/multipart.h>
#include <libsbp/new/string/null_terminated.h>
#include <libsbp/new/string/unterminated.h>

#ifdef __cplusplus
extern "C" {
#endif

struct sbp_state;

/** GPS Time
 *
 * This message reports the GPS time, representing the time since the GPS epoch
 * began on midnight January 6, 1980 UTC. GPS time counts the weeks and seconds
 * of the week. The weeks begin at the Saturday/Sunday transition. GPS week 0
 * began at the beginning of the GPS time scale.
 *
 */
typedef struct {
  /**
   * GPS week number [weeks]
   */
  u16 wn;

  /**
   * GPS time of week rounded to the nearest millisecond [ms]
   */
  u32 tow;

  /**
   * Nanosecond residual of millisecond-rounded TOW (ranges from -500000 to
   * 500000) [ns]
   */
  s32 ns_residual;

  /**
   * Status flags (reserved)
   */
  u8 flags;
} sbp_msg_gps_time_t;

/**
 * Get encoded size of an instance of sbp_msg_gps_time_t
 *
 * @param msg sbp_msg_gps_time_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_msg_gps_time_t(const sbp_msg_gps_time_t *msg);

/**
 * Encode an instance of sbp_msg_gps_time_t to wire representation
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
 * @param msg Instance of sbp_msg_gps_time_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_msg_gps_time_t(uint8_t *buf, uint8_t len, uint8_t *n_written,
                                 const sbp_msg_gps_time_t *msg);

/**
 * Decode an instance of sbp_msg_gps_time_t from wire representation
 *
 * This function decodes the wire representation of a sbp_msg_gps_time_t message
 * to the given instance. The caller must specify the length of the buffer in
 * the \p len parameter. If non-null the number of bytes read from the buffer
 * will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_msg_gps_time_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_msg_gps_time_t(const uint8_t *buf, uint8_t len,
                                 uint8_t *n_read, sbp_msg_gps_time_t *msg);
/**
 * Send an instance of sbp_msg_gps_time_t with the given write function
 *
 * An equivalent of #sbp_send_message which operates specifically on
 * sbp_msg_gps_time_t
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
s8 sbp_send_sbp_msg_gps_time_t(struct sbp_state *s, u16 sender_id,
                               const sbp_msg_gps_time_t *msg,
                               s32 (*write)(u8 *buff, u32 n, void *context));

/**
 * Compare two instances of sbp_msg_gps_time_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_gps_time_t instance
 * @param b sbp_msg_gps_time_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_msg_gps_time_t(const sbp_msg_gps_time_t *a,
                               const sbp_msg_gps_time_t *b);

/** GPS Time
 *
 * This message reports the GPS time, representing the time since the GPS epoch
 * began on midnight January 6, 1980 UTC. GPS time counts the weeks and seconds
 * of the week. The weeks begin at the Saturday/Sunday transition. GPS week 0
 * began at the beginning of the GPS time scale.
 *
 */
typedef struct {
  /**
   * GPS week number [weeks]
   */
  u16 wn;

  /**
   * GPS time of week rounded to the nearest millisecond [ms]
   */
  u32 tow;

  /**
   * Nanosecond residual of millisecond-rounded TOW (ranges from -500000 to
   * 500000) [ns]
   */
  s32 ns_residual;

  /**
   * Status flags (reserved)
   */
  u8 flags;
} sbp_msg_gps_time_gnss_t;

/**
 * Get encoded size of an instance of sbp_msg_gps_time_gnss_t
 *
 * @param msg sbp_msg_gps_time_gnss_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_msg_gps_time_gnss_t(
    const sbp_msg_gps_time_gnss_t *msg);

/**
 * Encode an instance of sbp_msg_gps_time_gnss_t to wire representation
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
 * @param msg Instance of sbp_msg_gps_time_gnss_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_msg_gps_time_gnss_t(uint8_t *buf, uint8_t len,
                                      uint8_t *n_written,
                                      const sbp_msg_gps_time_gnss_t *msg);

/**
 * Decode an instance of sbp_msg_gps_time_gnss_t from wire representation
 *
 * This function decodes the wire representation of a sbp_msg_gps_time_gnss_t
 * message to the given instance. The caller must specify the length of the
 * buffer in the \p len parameter. If non-null the number of bytes read from the
 * buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_msg_gps_time_gnss_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_msg_gps_time_gnss_t(const uint8_t *buf, uint8_t len,
                                      uint8_t *n_read,
                                      sbp_msg_gps_time_gnss_t *msg);
/**
 * Send an instance of sbp_msg_gps_time_gnss_t with the given write function
 *
 * An equivalent of #sbp_send_message which operates specifically on
 * sbp_msg_gps_time_gnss_t
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
s8 sbp_send_sbp_msg_gps_time_gnss_t(struct sbp_state *s, u16 sender_id,
                                    const sbp_msg_gps_time_gnss_t *msg,
                                    s32 (*write)(u8 *buff, u32 n,
                                                 void *context));

/**
 * Compare two instances of sbp_msg_gps_time_gnss_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_gps_time_gnss_t instance
 * @param b sbp_msg_gps_time_gnss_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_msg_gps_time_gnss_t(const sbp_msg_gps_time_gnss_t *a,
                                    const sbp_msg_gps_time_gnss_t *b);

/** UTC Time
 *
 * This message reports the Universal Coordinated Time (UTC).  Note the flags
 * which indicate the source of the UTC offset value and source of the time fix.
 */
typedef struct {
  /**
   * Indicates source and time validity
   */
  u8 flags;

  /**
   * GPS time of week rounded to the nearest millisecond [ms]
   */
  u32 tow;

  /**
   * Year [year]
   */
  u16 year;

  /**
   * Month (range 1 .. 12) [months]
   */
  u8 month;

  /**
   * days in the month (range 1-31) [day]
   */
  u8 day;

  /**
   * hours of day (range 0-23) [hours]
   */
  u8 hours;

  /**
   * minutes of hour (range 0-59) [minutes]
   */
  u8 minutes;

  /**
   * seconds of minute (range 0-60) rounded down [seconds]
   */
  u8 seconds;

  /**
   * nanoseconds of second (range 0-999999999) [nanoseconds]
   */
  u32 ns;
} sbp_msg_utc_time_t;

/**
 * Get encoded size of an instance of sbp_msg_utc_time_t
 *
 * @param msg sbp_msg_utc_time_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_msg_utc_time_t(const sbp_msg_utc_time_t *msg);

/**
 * Encode an instance of sbp_msg_utc_time_t to wire representation
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
 * @param msg Instance of sbp_msg_utc_time_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_msg_utc_time_t(uint8_t *buf, uint8_t len, uint8_t *n_written,
                                 const sbp_msg_utc_time_t *msg);

/**
 * Decode an instance of sbp_msg_utc_time_t from wire representation
 *
 * This function decodes the wire representation of a sbp_msg_utc_time_t message
 * to the given instance. The caller must specify the length of the buffer in
 * the \p len parameter. If non-null the number of bytes read from the buffer
 * will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_msg_utc_time_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_msg_utc_time_t(const uint8_t *buf, uint8_t len,
                                 uint8_t *n_read, sbp_msg_utc_time_t *msg);
/**
 * Send an instance of sbp_msg_utc_time_t with the given write function
 *
 * An equivalent of #sbp_send_message which operates specifically on
 * sbp_msg_utc_time_t
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
s8 sbp_send_sbp_msg_utc_time_t(struct sbp_state *s, u16 sender_id,
                               const sbp_msg_utc_time_t *msg,
                               s32 (*write)(u8 *buff, u32 n, void *context));

/**
 * Compare two instances of sbp_msg_utc_time_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_utc_time_t instance
 * @param b sbp_msg_utc_time_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_msg_utc_time_t(const sbp_msg_utc_time_t *a,
                               const sbp_msg_utc_time_t *b);

/** UTC Time
 *
 * This message reports the Universal Coordinated Time (UTC).  Note the flags
 * which indicate the source of the UTC offset value and source of the time fix.
 */
typedef struct {
  /**
   * Indicates source and time validity
   */
  u8 flags;

  /**
   * GPS time of week rounded to the nearest millisecond [ms]
   */
  u32 tow;

  /**
   * Year [year]
   */
  u16 year;

  /**
   * Month (range 1 .. 12) [months]
   */
  u8 month;

  /**
   * days in the month (range 1-31) [day]
   */
  u8 day;

  /**
   * hours of day (range 0-23) [hours]
   */
  u8 hours;

  /**
   * minutes of hour (range 0-59) [minutes]
   */
  u8 minutes;

  /**
   * seconds of minute (range 0-60) rounded down [seconds]
   */
  u8 seconds;

  /**
   * nanoseconds of second (range 0-999999999) [nanoseconds]
   */
  u32 ns;
} sbp_msg_utc_time_gnss_t;

/**
 * Get encoded size of an instance of sbp_msg_utc_time_gnss_t
 *
 * @param msg sbp_msg_utc_time_gnss_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_msg_utc_time_gnss_t(
    const sbp_msg_utc_time_gnss_t *msg);

/**
 * Encode an instance of sbp_msg_utc_time_gnss_t to wire representation
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
 * @param msg Instance of sbp_msg_utc_time_gnss_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_msg_utc_time_gnss_t(uint8_t *buf, uint8_t len,
                                      uint8_t *n_written,
                                      const sbp_msg_utc_time_gnss_t *msg);

/**
 * Decode an instance of sbp_msg_utc_time_gnss_t from wire representation
 *
 * This function decodes the wire representation of a sbp_msg_utc_time_gnss_t
 * message to the given instance. The caller must specify the length of the
 * buffer in the \p len parameter. If non-null the number of bytes read from the
 * buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_msg_utc_time_gnss_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_msg_utc_time_gnss_t(const uint8_t *buf, uint8_t len,
                                      uint8_t *n_read,
                                      sbp_msg_utc_time_gnss_t *msg);
/**
 * Send an instance of sbp_msg_utc_time_gnss_t with the given write function
 *
 * An equivalent of #sbp_send_message which operates specifically on
 * sbp_msg_utc_time_gnss_t
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
s8 sbp_send_sbp_msg_utc_time_gnss_t(struct sbp_state *s, u16 sender_id,
                                    const sbp_msg_utc_time_gnss_t *msg,
                                    s32 (*write)(u8 *buff, u32 n,
                                                 void *context));

/**
 * Compare two instances of sbp_msg_utc_time_gnss_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_utc_time_gnss_t instance
 * @param b sbp_msg_utc_time_gnss_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_msg_utc_time_gnss_t(const sbp_msg_utc_time_gnss_t *a,
                                    const sbp_msg_utc_time_gnss_t *b);

/** Dilution of Precision
 *
 * This dilution of precision (DOP) message describes the effect of navigation
 * satellite geometry on positional measurement precision.  The flags field
 * indicated whether the DOP reported corresponds to differential or SPP
 * solution.
 */
typedef struct {
  /**
   * GPS Time of Week [ms]
   */
  u32 tow;

  /**
   * Geometric Dilution of Precision [0.01]
   */
  u16 gdop;

  /**
   * Position Dilution of Precision [0.01]
   */
  u16 pdop;

  /**
   * Time Dilution of Precision [0.01]
   */
  u16 tdop;

  /**
   * Horizontal Dilution of Precision [0.01]
   */
  u16 hdop;

  /**
   * Vertical Dilution of Precision [0.01]
   */
  u16 vdop;

  /**
   * Indicates the position solution with which the DOPS message corresponds
   */
  u8 flags;
} sbp_msg_dops_t;

/**
 * Get encoded size of an instance of sbp_msg_dops_t
 *
 * @param msg sbp_msg_dops_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_msg_dops_t(const sbp_msg_dops_t *msg);

/**
 * Encode an instance of sbp_msg_dops_t to wire representation
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
 * @param msg Instance of sbp_msg_dops_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_msg_dops_t(uint8_t *buf, uint8_t len, uint8_t *n_written,
                             const sbp_msg_dops_t *msg);

/**
 * Decode an instance of sbp_msg_dops_t from wire representation
 *
 * This function decodes the wire representation of a sbp_msg_dops_t message to
 * the given instance. The caller must specify the length of the buffer in the
 * \p len parameter. If non-null the number of bytes read from the buffer will
 * be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_msg_dops_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_msg_dops_t(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                             sbp_msg_dops_t *msg);
/**
 * Send an instance of sbp_msg_dops_t with the given write function
 *
 * An equivalent of #sbp_send_message which operates specifically on
 * sbp_msg_dops_t
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
s8 sbp_send_sbp_msg_dops_t(struct sbp_state *s, u16 sender_id,
                           const sbp_msg_dops_t *msg,
                           s32 (*write)(u8 *buff, u32 n, void *context));

/**
 * Compare two instances of sbp_msg_dops_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_dops_t instance
 * @param b sbp_msg_dops_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_msg_dops_t(const sbp_msg_dops_t *a, const sbp_msg_dops_t *b);

/** Single-point position in ECEF
 *
 * The position solution message reports absolute Earth Centered Earth Fixed
 * (ECEF) coordinates and the status (single point vs pseudo-absolute RTK) of
 * the position solution. If the rover receiver knows the surveyed position of
 * the base station and has an RTK solution, this reports a pseudo-absolute
 * position solution using the base station position and the rover's RTK
 * baseline vector. The full GPS time is given by the preceding MSG_GPS_TIME
 * with the matching time-of-week (tow).
 */
typedef struct {
  /**
   * GPS Time of Week [ms]
   */
  u32 tow;

  /**
   * ECEF X coordinate [m]
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

  /**
   * Position estimated standard deviation [mm]
   */
  u16 accuracy;

  /**
   * Number of satellites used in solution
   */
  u8 n_sats;

  /**
   * Status flags
   */
  u8 flags;
} sbp_msg_pos_ecef_t;

/**
 * Get encoded size of an instance of sbp_msg_pos_ecef_t
 *
 * @param msg sbp_msg_pos_ecef_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_msg_pos_ecef_t(const sbp_msg_pos_ecef_t *msg);

/**
 * Encode an instance of sbp_msg_pos_ecef_t to wire representation
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
 * @param msg Instance of sbp_msg_pos_ecef_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_msg_pos_ecef_t(uint8_t *buf, uint8_t len, uint8_t *n_written,
                                 const sbp_msg_pos_ecef_t *msg);

/**
 * Decode an instance of sbp_msg_pos_ecef_t from wire representation
 *
 * This function decodes the wire representation of a sbp_msg_pos_ecef_t message
 * to the given instance. The caller must specify the length of the buffer in
 * the \p len parameter. If non-null the number of bytes read from the buffer
 * will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_msg_pos_ecef_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_msg_pos_ecef_t(const uint8_t *buf, uint8_t len,
                                 uint8_t *n_read, sbp_msg_pos_ecef_t *msg);
/**
 * Send an instance of sbp_msg_pos_ecef_t with the given write function
 *
 * An equivalent of #sbp_send_message which operates specifically on
 * sbp_msg_pos_ecef_t
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
s8 sbp_send_sbp_msg_pos_ecef_t(struct sbp_state *s, u16 sender_id,
                               const sbp_msg_pos_ecef_t *msg,
                               s32 (*write)(u8 *buff, u32 n, void *context));

/**
 * Compare two instances of sbp_msg_pos_ecef_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_pos_ecef_t instance
 * @param b sbp_msg_pos_ecef_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_msg_pos_ecef_t(const sbp_msg_pos_ecef_t *a,
                               const sbp_msg_pos_ecef_t *b);

/** Single-point position in ECEF
 *
 * The position solution message reports absolute Earth Centered Earth Fixed
 * (ECEF) coordinates and the status (single point vs pseudo-absolute RTK) of
 * the position solution. The message also reports the upper triangular portion
 * of the 3x3 covariance matrix. If the receiver knows the surveyed position of
 * the base station and has an RTK solution, this reports a pseudo-absolute
 * position solution using the base station position and the rover's RTK
 * baseline vector. The full GPS time is given by the preceding MSG_GPS_TIME
 * with the matching time-of-week (tow).
 */
typedef struct {
  /**
   * GPS Time of Week [ms]
   */
  u32 tow;

  /**
   * ECEF X coordinate [m]
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

  /**
   * Estimated variance of x [m^2]
   */
  float cov_x_x;

  /**
   * Estimated covariance of x and y [m^2]
   */
  float cov_x_y;

  /**
   * Estimated covariance of x and z [m^2]
   */
  float cov_x_z;

  /**
   * Estimated variance of y [m^2]
   */
  float cov_y_y;

  /**
   * Estimated covariance of y and z [m^2]
   */
  float cov_y_z;

  /**
   * Estimated variance of z [m^2]
   */
  float cov_z_z;

  /**
   * Number of satellites used in solution
   */
  u8 n_sats;

  /**
   * Status flags
   */
  u8 flags;
} sbp_msg_pos_ecef_cov_t;

/**
 * Get encoded size of an instance of sbp_msg_pos_ecef_cov_t
 *
 * @param msg sbp_msg_pos_ecef_cov_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_msg_pos_ecef_cov_t(
    const sbp_msg_pos_ecef_cov_t *msg);

/**
 * Encode an instance of sbp_msg_pos_ecef_cov_t to wire representation
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
 * @param msg Instance of sbp_msg_pos_ecef_cov_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_msg_pos_ecef_cov_t(uint8_t *buf, uint8_t len,
                                     uint8_t *n_written,
                                     const sbp_msg_pos_ecef_cov_t *msg);

/**
 * Decode an instance of sbp_msg_pos_ecef_cov_t from wire representation
 *
 * This function decodes the wire representation of a sbp_msg_pos_ecef_cov_t
 * message to the given instance. The caller must specify the length of the
 * buffer in the \p len parameter. If non-null the number of bytes read from the
 * buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_msg_pos_ecef_cov_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_msg_pos_ecef_cov_t(const uint8_t *buf, uint8_t len,
                                     uint8_t *n_read,
                                     sbp_msg_pos_ecef_cov_t *msg);
/**
 * Send an instance of sbp_msg_pos_ecef_cov_t with the given write function
 *
 * An equivalent of #sbp_send_message which operates specifically on
 * sbp_msg_pos_ecef_cov_t
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
s8 sbp_send_sbp_msg_pos_ecef_cov_t(struct sbp_state *s, u16 sender_id,
                                   const sbp_msg_pos_ecef_cov_t *msg,
                                   s32 (*write)(u8 *buff, u32 n,
                                                void *context));

/**
 * Compare two instances of sbp_msg_pos_ecef_cov_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_pos_ecef_cov_t instance
 * @param b sbp_msg_pos_ecef_cov_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_msg_pos_ecef_cov_t(const sbp_msg_pos_ecef_cov_t *a,
                                   const sbp_msg_pos_ecef_cov_t *b);

/** Geodetic Position
 *
 * This position solution message reports the absolute geodetic coordinates and
 * the status (single point vs pseudo-absolute RTK) of the position solution. If
 * the rover receiver knows the surveyed position of the base station and has an
 * RTK solution, this reports a pseudo-absolute position solution using the base
 * station position and the rover's RTK baseline vector. The full GPS time is
 * given by the preceding MSG_GPS_TIME with the matching time-of-week (tow).
 */
typedef struct {
  /**
   * GPS Time of Week [ms]
   */
  u32 tow;

  /**
   * Latitude [deg]
   */
  double lat;

  /**
   * Longitude [deg]
   */
  double lon;

  /**
   * Height above WGS84 ellipsoid [m]
   */
  double height;

  /**
   * Horizontal position estimated standard deviation [mm]
   */
  u16 h_accuracy;

  /**
   * Vertical position estimated standard deviation [mm]
   */
  u16 v_accuracy;

  /**
   * Number of satellites used in solution.
   */
  u8 n_sats;

  /**
   * Status flags
   */
  u8 flags;
} sbp_msg_pos_llh_t;

/**
 * Get encoded size of an instance of sbp_msg_pos_llh_t
 *
 * @param msg sbp_msg_pos_llh_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_msg_pos_llh_t(const sbp_msg_pos_llh_t *msg);

/**
 * Encode an instance of sbp_msg_pos_llh_t to wire representation
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
 * @param msg Instance of sbp_msg_pos_llh_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_msg_pos_llh_t(uint8_t *buf, uint8_t len, uint8_t *n_written,
                                const sbp_msg_pos_llh_t *msg);

/**
 * Decode an instance of sbp_msg_pos_llh_t from wire representation
 *
 * This function decodes the wire representation of a sbp_msg_pos_llh_t message
 * to the given instance. The caller must specify the length of the buffer in
 * the \p len parameter. If non-null the number of bytes read from the buffer
 * will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_msg_pos_llh_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_msg_pos_llh_t(const uint8_t *buf, uint8_t len,
                                uint8_t *n_read, sbp_msg_pos_llh_t *msg);
/**
 * Send an instance of sbp_msg_pos_llh_t with the given write function
 *
 * An equivalent of #sbp_send_message which operates specifically on
 * sbp_msg_pos_llh_t
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
s8 sbp_send_sbp_msg_pos_llh_t(struct sbp_state *s, u16 sender_id,
                              const sbp_msg_pos_llh_t *msg,
                              s32 (*write)(u8 *buff, u32 n, void *context));

/**
 * Compare two instances of sbp_msg_pos_llh_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_pos_llh_t instance
 * @param b sbp_msg_pos_llh_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_msg_pos_llh_t(const sbp_msg_pos_llh_t *a,
                              const sbp_msg_pos_llh_t *b);

/** Geodetic Position
 *
 * This position solution message reports the absolute geodetic coordinates and
 * the status (single point vs pseudo-absolute RTK) of the position solution as
 * well as the upper triangle of the 3x3 covariance matrix.  The position
 * information and Fix Mode flags should follow the MSG_POS_LLH message.  Since
 * the covariance matrix is computed in the local-level North, East, Down frame,
 * the covariance terms follow with that convention. Thus, covariances are
 * reported against the "downward" measurement and care should be taken with the
 * sign convention.
 */
typedef struct {
  /**
   * GPS Time of Week [ms]
   */
  u32 tow;

  /**
   * Latitude [deg]
   */
  double lat;

  /**
   * Longitude [deg]
   */
  double lon;

  /**
   * Height above WGS84 ellipsoid [m]
   */
  double height;

  /**
   * Estimated variance of northing [m^2]
   */
  float cov_n_n;

  /**
   * Covariance of northing and easting [m^2]
   */
  float cov_n_e;

  /**
   * Covariance of northing and downward measurement [m^2]
   */
  float cov_n_d;

  /**
   * Estimated variance of easting [m^2]
   */
  float cov_e_e;

  /**
   * Covariance of easting and downward measurement [m^2]
   */
  float cov_e_d;

  /**
   * Estimated variance of downward measurement [m^2]
   */
  float cov_d_d;

  /**
   * Number of satellites used in solution.
   */
  u8 n_sats;

  /**
   * Status flags
   */
  u8 flags;
} sbp_msg_pos_llh_cov_t;

/**
 * Get encoded size of an instance of sbp_msg_pos_llh_cov_t
 *
 * @param msg sbp_msg_pos_llh_cov_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_msg_pos_llh_cov_t(const sbp_msg_pos_llh_cov_t *msg);

/**
 * Encode an instance of sbp_msg_pos_llh_cov_t to wire representation
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
 * @param msg Instance of sbp_msg_pos_llh_cov_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_msg_pos_llh_cov_t(uint8_t *buf, uint8_t len,
                                    uint8_t *n_written,
                                    const sbp_msg_pos_llh_cov_t *msg);

/**
 * Decode an instance of sbp_msg_pos_llh_cov_t from wire representation
 *
 * This function decodes the wire representation of a sbp_msg_pos_llh_cov_t
 * message to the given instance. The caller must specify the length of the
 * buffer in the \p len parameter. If non-null the number of bytes read from the
 * buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_msg_pos_llh_cov_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_msg_pos_llh_cov_t(const uint8_t *buf, uint8_t len,
                                    uint8_t *n_read,
                                    sbp_msg_pos_llh_cov_t *msg);
/**
 * Send an instance of sbp_msg_pos_llh_cov_t with the given write function
 *
 * An equivalent of #sbp_send_message which operates specifically on
 * sbp_msg_pos_llh_cov_t
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
s8 sbp_send_sbp_msg_pos_llh_cov_t(struct sbp_state *s, u16 sender_id,
                                  const sbp_msg_pos_llh_cov_t *msg,
                                  s32 (*write)(u8 *buff, u32 n, void *context));

/**
 * Compare two instances of sbp_msg_pos_llh_cov_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_pos_llh_cov_t instance
 * @param b sbp_msg_pos_llh_cov_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_msg_pos_llh_cov_t(const sbp_msg_pos_llh_cov_t *a,
                                  const sbp_msg_pos_llh_cov_t *b);

/** Baseline Position in ECEF
 *
 * This message reports the baseline solution in Earth Centered Earth Fixed
 * (ECEF) coordinates. This baseline is the relative vector distance from the
 * base station to the rover receiver. The full GPS time is given by the
 * preceding MSG_GPS_TIME with the matching time-of-week (tow).
 */
typedef struct {
  /**
   * GPS Time of Week [ms]
   */
  u32 tow;

  /**
   * Baseline ECEF X coordinate [mm]
   */
  s32 x;

  /**
   * Baseline ECEF Y coordinate [mm]
   */
  s32 y;

  /**
   * Baseline ECEF Z coordinate [mm]
   */
  s32 z;

  /**
   * Position estimated standard deviation [mm]
   */
  u16 accuracy;

  /**
   * Number of satellites used in solution
   */
  u8 n_sats;

  /**
   * Status flags
   */
  u8 flags;
} sbp_msg_baseline_ecef_t;

/**
 * Get encoded size of an instance of sbp_msg_baseline_ecef_t
 *
 * @param msg sbp_msg_baseline_ecef_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_msg_baseline_ecef_t(
    const sbp_msg_baseline_ecef_t *msg);

/**
 * Encode an instance of sbp_msg_baseline_ecef_t to wire representation
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
 * @param msg Instance of sbp_msg_baseline_ecef_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_msg_baseline_ecef_t(uint8_t *buf, uint8_t len,
                                      uint8_t *n_written,
                                      const sbp_msg_baseline_ecef_t *msg);

/**
 * Decode an instance of sbp_msg_baseline_ecef_t from wire representation
 *
 * This function decodes the wire representation of a sbp_msg_baseline_ecef_t
 * message to the given instance. The caller must specify the length of the
 * buffer in the \p len parameter. If non-null the number of bytes read from the
 * buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_msg_baseline_ecef_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_msg_baseline_ecef_t(const uint8_t *buf, uint8_t len,
                                      uint8_t *n_read,
                                      sbp_msg_baseline_ecef_t *msg);
/**
 * Send an instance of sbp_msg_baseline_ecef_t with the given write function
 *
 * An equivalent of #sbp_send_message which operates specifically on
 * sbp_msg_baseline_ecef_t
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
s8 sbp_send_sbp_msg_baseline_ecef_t(struct sbp_state *s, u16 sender_id,
                                    const sbp_msg_baseline_ecef_t *msg,
                                    s32 (*write)(u8 *buff, u32 n,
                                                 void *context));

/**
 * Compare two instances of sbp_msg_baseline_ecef_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_baseline_ecef_t instance
 * @param b sbp_msg_baseline_ecef_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_msg_baseline_ecef_t(const sbp_msg_baseline_ecef_t *a,
                                    const sbp_msg_baseline_ecef_t *b);

/** Baseline in NED
 *
 * This message reports the baseline solution in North East Down (NED)
 * coordinates. This baseline is the relative vector distance from the base
 * station to the rover receiver, and NED coordinate system is defined at the
 * local WGS84 tangent plane centered at the base station position.  The full
 * GPS time is given by the preceding MSG_GPS_TIME with the matching
 * time-of-week (tow).
 */
typedef struct {
  /**
   * GPS Time of Week [ms]
   */
  u32 tow;

  /**
   * Baseline North coordinate [mm]
   */
  s32 n;

  /**
   * Baseline East coordinate [mm]
   */
  s32 e;

  /**
   * Baseline Down coordinate [mm]
   */
  s32 d;

  /**
   * Horizontal position estimated standard deviation [mm]
   */
  u16 h_accuracy;

  /**
   * Vertical position estimated standard deviation [mm]
   */
  u16 v_accuracy;

  /**
   * Number of satellites used in solution
   */
  u8 n_sats;

  /**
   * Status flags
   */
  u8 flags;
} sbp_msg_baseline_ned_t;

/**
 * Get encoded size of an instance of sbp_msg_baseline_ned_t
 *
 * @param msg sbp_msg_baseline_ned_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_msg_baseline_ned_t(
    const sbp_msg_baseline_ned_t *msg);

/**
 * Encode an instance of sbp_msg_baseline_ned_t to wire representation
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
 * @param msg Instance of sbp_msg_baseline_ned_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_msg_baseline_ned_t(uint8_t *buf, uint8_t len,
                                     uint8_t *n_written,
                                     const sbp_msg_baseline_ned_t *msg);

/**
 * Decode an instance of sbp_msg_baseline_ned_t from wire representation
 *
 * This function decodes the wire representation of a sbp_msg_baseline_ned_t
 * message to the given instance. The caller must specify the length of the
 * buffer in the \p len parameter. If non-null the number of bytes read from the
 * buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_msg_baseline_ned_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_msg_baseline_ned_t(const uint8_t *buf, uint8_t len,
                                     uint8_t *n_read,
                                     sbp_msg_baseline_ned_t *msg);
/**
 * Send an instance of sbp_msg_baseline_ned_t with the given write function
 *
 * An equivalent of #sbp_send_message which operates specifically on
 * sbp_msg_baseline_ned_t
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
s8 sbp_send_sbp_msg_baseline_ned_t(struct sbp_state *s, u16 sender_id,
                                   const sbp_msg_baseline_ned_t *msg,
                                   s32 (*write)(u8 *buff, u32 n,
                                                void *context));

/**
 * Compare two instances of sbp_msg_baseline_ned_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_baseline_ned_t instance
 * @param b sbp_msg_baseline_ned_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_msg_baseline_ned_t(const sbp_msg_baseline_ned_t *a,
                                   const sbp_msg_baseline_ned_t *b);

/** Velocity in ECEF
 *
 * This message reports the velocity in Earth Centered Earth Fixed (ECEF)
 * coordinates. The full GPS time is given by the preceding MSG_GPS_TIME with
 * the matching time-of-week (tow).
 */
typedef struct {
  /**
   * GPS Time of Week [ms]
   */
  u32 tow;

  /**
   * Velocity ECEF X coordinate [mm/s]
   */
  s32 x;

  /**
   * Velocity ECEF Y coordinate [mm/s]
   */
  s32 y;

  /**
   * Velocity ECEF Z coordinate [mm/s]
   */
  s32 z;

  /**
   * Velocity estimated standard deviation [mm/s]
   */
  u16 accuracy;

  /**
   * Number of satellites used in solution
   */
  u8 n_sats;

  /**
   * Status flags
   */
  u8 flags;
} sbp_msg_vel_ecef_t;

/**
 * Get encoded size of an instance of sbp_msg_vel_ecef_t
 *
 * @param msg sbp_msg_vel_ecef_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_msg_vel_ecef_t(const sbp_msg_vel_ecef_t *msg);

/**
 * Encode an instance of sbp_msg_vel_ecef_t to wire representation
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
 * @param msg Instance of sbp_msg_vel_ecef_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_msg_vel_ecef_t(uint8_t *buf, uint8_t len, uint8_t *n_written,
                                 const sbp_msg_vel_ecef_t *msg);

/**
 * Decode an instance of sbp_msg_vel_ecef_t from wire representation
 *
 * This function decodes the wire representation of a sbp_msg_vel_ecef_t message
 * to the given instance. The caller must specify the length of the buffer in
 * the \p len parameter. If non-null the number of bytes read from the buffer
 * will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_msg_vel_ecef_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_msg_vel_ecef_t(const uint8_t *buf, uint8_t len,
                                 uint8_t *n_read, sbp_msg_vel_ecef_t *msg);
/**
 * Send an instance of sbp_msg_vel_ecef_t with the given write function
 *
 * An equivalent of #sbp_send_message which operates specifically on
 * sbp_msg_vel_ecef_t
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
s8 sbp_send_sbp_msg_vel_ecef_t(struct sbp_state *s, u16 sender_id,
                               const sbp_msg_vel_ecef_t *msg,
                               s32 (*write)(u8 *buff, u32 n, void *context));

/**
 * Compare two instances of sbp_msg_vel_ecef_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_vel_ecef_t instance
 * @param b sbp_msg_vel_ecef_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_msg_vel_ecef_t(const sbp_msg_vel_ecef_t *a,
                               const sbp_msg_vel_ecef_t *b);

/** Velocity in ECEF
 *
 * This message reports the velocity in Earth Centered Earth Fixed (ECEF)
 * coordinates. The full GPS time is given by the preceding MSG_GPS_TIME with
 * the matching time-of-week (tow).
 */
typedef struct {
  /**
   * GPS Time of Week [ms]
   */
  u32 tow;

  /**
   * Velocity ECEF X coordinate [mm/s]
   */
  s32 x;

  /**
   * Velocity ECEF Y coordinate [mm/s]
   */
  s32 y;

  /**
   * Velocity ECEF Z coordinate [mm/s]
   */
  s32 z;

  /**
   * Estimated variance of x [m^2/s^2]
   */
  float cov_x_x;

  /**
   * Estimated covariance of x and y [m^2/s^2]
   */
  float cov_x_y;

  /**
   * Estimated covariance of x and z [m^2/s^2]
   */
  float cov_x_z;

  /**
   * Estimated variance of y [m^2/s^2]
   */
  float cov_y_y;

  /**
   * Estimated covariance of y and z [m^2/s^2]
   */
  float cov_y_z;

  /**
   * Estimated variance of z [m^2/s^2]
   */
  float cov_z_z;

  /**
   * Number of satellites used in solution
   */
  u8 n_sats;

  /**
   * Status flags
   */
  u8 flags;
} sbp_msg_vel_ecef_cov_t;

/**
 * Get encoded size of an instance of sbp_msg_vel_ecef_cov_t
 *
 * @param msg sbp_msg_vel_ecef_cov_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_msg_vel_ecef_cov_t(
    const sbp_msg_vel_ecef_cov_t *msg);

/**
 * Encode an instance of sbp_msg_vel_ecef_cov_t to wire representation
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
 * @param msg Instance of sbp_msg_vel_ecef_cov_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_msg_vel_ecef_cov_t(uint8_t *buf, uint8_t len,
                                     uint8_t *n_written,
                                     const sbp_msg_vel_ecef_cov_t *msg);

/**
 * Decode an instance of sbp_msg_vel_ecef_cov_t from wire representation
 *
 * This function decodes the wire representation of a sbp_msg_vel_ecef_cov_t
 * message to the given instance. The caller must specify the length of the
 * buffer in the \p len parameter. If non-null the number of bytes read from the
 * buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_msg_vel_ecef_cov_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_msg_vel_ecef_cov_t(const uint8_t *buf, uint8_t len,
                                     uint8_t *n_read,
                                     sbp_msg_vel_ecef_cov_t *msg);
/**
 * Send an instance of sbp_msg_vel_ecef_cov_t with the given write function
 *
 * An equivalent of #sbp_send_message which operates specifically on
 * sbp_msg_vel_ecef_cov_t
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
s8 sbp_send_sbp_msg_vel_ecef_cov_t(struct sbp_state *s, u16 sender_id,
                                   const sbp_msg_vel_ecef_cov_t *msg,
                                   s32 (*write)(u8 *buff, u32 n,
                                                void *context));

/**
 * Compare two instances of sbp_msg_vel_ecef_cov_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_vel_ecef_cov_t instance
 * @param b sbp_msg_vel_ecef_cov_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_msg_vel_ecef_cov_t(const sbp_msg_vel_ecef_cov_t *a,
                                   const sbp_msg_vel_ecef_cov_t *b);

/** Velocity in NED
 *
 * This message reports the velocity in local North East Down (NED) coordinates.
 * The NED coordinate system is defined as the local WGS84 tangent plane
 * centered at the current position. The full GPS time is given by the preceding
 * MSG_GPS_TIME with the matching time-of-week (tow).
 */
typedef struct {
  /**
   * GPS Time of Week [ms]
   */
  u32 tow;

  /**
   * Velocity North coordinate [mm/s]
   */
  s32 n;

  /**
   * Velocity East coordinate [mm/s]
   */
  s32 e;

  /**
   * Velocity Down coordinate [mm/s]
   */
  s32 d;

  /**
   * Horizontal velocity estimated standard deviation [mm/s]
   */
  u16 h_accuracy;

  /**
   * Vertical velocity estimated standard deviation [mm/s]
   */
  u16 v_accuracy;

  /**
   * Number of satellites used in solution
   */
  u8 n_sats;

  /**
   * Status flags
   */
  u8 flags;
} sbp_msg_vel_ned_t;

/**
 * Get encoded size of an instance of sbp_msg_vel_ned_t
 *
 * @param msg sbp_msg_vel_ned_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_msg_vel_ned_t(const sbp_msg_vel_ned_t *msg);

/**
 * Encode an instance of sbp_msg_vel_ned_t to wire representation
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
 * @param msg Instance of sbp_msg_vel_ned_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_msg_vel_ned_t(uint8_t *buf, uint8_t len, uint8_t *n_written,
                                const sbp_msg_vel_ned_t *msg);

/**
 * Decode an instance of sbp_msg_vel_ned_t from wire representation
 *
 * This function decodes the wire representation of a sbp_msg_vel_ned_t message
 * to the given instance. The caller must specify the length of the buffer in
 * the \p len parameter. If non-null the number of bytes read from the buffer
 * will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_msg_vel_ned_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_msg_vel_ned_t(const uint8_t *buf, uint8_t len,
                                uint8_t *n_read, sbp_msg_vel_ned_t *msg);
/**
 * Send an instance of sbp_msg_vel_ned_t with the given write function
 *
 * An equivalent of #sbp_send_message which operates specifically on
 * sbp_msg_vel_ned_t
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
s8 sbp_send_sbp_msg_vel_ned_t(struct sbp_state *s, u16 sender_id,
                              const sbp_msg_vel_ned_t *msg,
                              s32 (*write)(u8 *buff, u32 n, void *context));

/**
 * Compare two instances of sbp_msg_vel_ned_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_vel_ned_t instance
 * @param b sbp_msg_vel_ned_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_msg_vel_ned_t(const sbp_msg_vel_ned_t *a,
                              const sbp_msg_vel_ned_t *b);

/** Velocity in NED
 *
 * This message reports the velocity in local North East Down (NED) coordinates.
 * The NED coordinate system is defined as the local WGS84 tangent plane
 * centered at the current position. The full GPS time is given by the preceding
 * MSG_GPS_TIME with the matching time-of-week (tow). This message is similar to
 * the MSG_VEL_NED, but it includes the upper triangular portion of the 3x3
 * covariance matrix.
 */
typedef struct {
  /**
   * GPS Time of Week [ms]
   */
  u32 tow;

  /**
   * Velocity North coordinate [mm/s]
   */
  s32 n;

  /**
   * Velocity East coordinate [mm/s]
   */
  s32 e;

  /**
   * Velocity Down coordinate [mm/s]
   */
  s32 d;

  /**
   * Estimated variance of northward measurement [m^2]
   */
  float cov_n_n;

  /**
   * Covariance of northward and eastward measurement [m^2]
   */
  float cov_n_e;

  /**
   * Covariance of northward and downward measurement [m^2]
   */
  float cov_n_d;

  /**
   * Estimated variance of eastward measurement [m^2]
   */
  float cov_e_e;

  /**
   * Covariance of eastward and downward measurement [m^2]
   */
  float cov_e_d;

  /**
   * Estimated variance of downward measurement [m^2]
   */
  float cov_d_d;

  /**
   * Number of satellites used in solution
   */
  u8 n_sats;

  /**
   * Status flags
   */
  u8 flags;
} sbp_msg_vel_ned_cov_t;

/**
 * Get encoded size of an instance of sbp_msg_vel_ned_cov_t
 *
 * @param msg sbp_msg_vel_ned_cov_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_msg_vel_ned_cov_t(const sbp_msg_vel_ned_cov_t *msg);

/**
 * Encode an instance of sbp_msg_vel_ned_cov_t to wire representation
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
 * @param msg Instance of sbp_msg_vel_ned_cov_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_msg_vel_ned_cov_t(uint8_t *buf, uint8_t len,
                                    uint8_t *n_written,
                                    const sbp_msg_vel_ned_cov_t *msg);

/**
 * Decode an instance of sbp_msg_vel_ned_cov_t from wire representation
 *
 * This function decodes the wire representation of a sbp_msg_vel_ned_cov_t
 * message to the given instance. The caller must specify the length of the
 * buffer in the \p len parameter. If non-null the number of bytes read from the
 * buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_msg_vel_ned_cov_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_msg_vel_ned_cov_t(const uint8_t *buf, uint8_t len,
                                    uint8_t *n_read,
                                    sbp_msg_vel_ned_cov_t *msg);
/**
 * Send an instance of sbp_msg_vel_ned_cov_t with the given write function
 *
 * An equivalent of #sbp_send_message which operates specifically on
 * sbp_msg_vel_ned_cov_t
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
s8 sbp_send_sbp_msg_vel_ned_cov_t(struct sbp_state *s, u16 sender_id,
                                  const sbp_msg_vel_ned_cov_t *msg,
                                  s32 (*write)(u8 *buff, u32 n, void *context));

/**
 * Compare two instances of sbp_msg_vel_ned_cov_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_vel_ned_cov_t instance
 * @param b sbp_msg_vel_ned_cov_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_msg_vel_ned_cov_t(const sbp_msg_vel_ned_cov_t *a,
                                  const sbp_msg_vel_ned_cov_t *b);

/** GNSS-only Position in ECEF
 *
 * The position solution message reports absolute Earth Centered Earth Fixed
 * (ECEF) coordinates and the status (single point vs pseudo-absolute RTK) of
 * the position solution. If the rover receiver knows the surveyed position of
 * the base station and has an RTK solution, this reports a pseudo-absolute
 * position solution using the base station position and the rover's RTK
 * baseline vector. The full GPS time is given by the preceding MSG_GPS_TIME
 * with the matching time-of-week (tow).
 */
typedef struct {
  /**
   * GPS Time of Week [ms]
   */
  u32 tow;

  /**
   * ECEF X coordinate [m]
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

  /**
   * Position estimated standard deviation [mm]
   */
  u16 accuracy;

  /**
   * Number of satellites used in solution
   */
  u8 n_sats;

  /**
   * Status flags
   */
  u8 flags;
} sbp_msg_pos_ecef_gnss_t;

/**
 * Get encoded size of an instance of sbp_msg_pos_ecef_gnss_t
 *
 * @param msg sbp_msg_pos_ecef_gnss_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_msg_pos_ecef_gnss_t(
    const sbp_msg_pos_ecef_gnss_t *msg);

/**
 * Encode an instance of sbp_msg_pos_ecef_gnss_t to wire representation
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
 * @param msg Instance of sbp_msg_pos_ecef_gnss_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_msg_pos_ecef_gnss_t(uint8_t *buf, uint8_t len,
                                      uint8_t *n_written,
                                      const sbp_msg_pos_ecef_gnss_t *msg);

/**
 * Decode an instance of sbp_msg_pos_ecef_gnss_t from wire representation
 *
 * This function decodes the wire representation of a sbp_msg_pos_ecef_gnss_t
 * message to the given instance. The caller must specify the length of the
 * buffer in the \p len parameter. If non-null the number of bytes read from the
 * buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_msg_pos_ecef_gnss_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_msg_pos_ecef_gnss_t(const uint8_t *buf, uint8_t len,
                                      uint8_t *n_read,
                                      sbp_msg_pos_ecef_gnss_t *msg);
/**
 * Send an instance of sbp_msg_pos_ecef_gnss_t with the given write function
 *
 * An equivalent of #sbp_send_message which operates specifically on
 * sbp_msg_pos_ecef_gnss_t
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
s8 sbp_send_sbp_msg_pos_ecef_gnss_t(struct sbp_state *s, u16 sender_id,
                                    const sbp_msg_pos_ecef_gnss_t *msg,
                                    s32 (*write)(u8 *buff, u32 n,
                                                 void *context));

/**
 * Compare two instances of sbp_msg_pos_ecef_gnss_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_pos_ecef_gnss_t instance
 * @param b sbp_msg_pos_ecef_gnss_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_msg_pos_ecef_gnss_t(const sbp_msg_pos_ecef_gnss_t *a,
                                    const sbp_msg_pos_ecef_gnss_t *b);

/** GNSS-only Position in ECEF
 *
 * The position solution message reports absolute Earth Centered Earth Fixed
 * (ECEF) coordinates and the status (single point vs pseudo-absolute RTK) of
 * the position solution. The message also reports the upper triangular portion
 * of the 3x3 covariance matrix. If the receiver knows the surveyed position of
 * the base station and has an RTK solution, this reports a pseudo-absolute
 * position solution using the base station position and the rover's RTK
 * baseline vector. The full GPS time is given by the preceding MSG_GPS_TIME
 * with the matching time-of-week (tow).
 */
typedef struct {
  /**
   * GPS Time of Week [ms]
   */
  u32 tow;

  /**
   * ECEF X coordinate [m]
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

  /**
   * Estimated variance of x [m^2]
   */
  float cov_x_x;

  /**
   * Estimated covariance of x and y [m^2]
   */
  float cov_x_y;

  /**
   * Estimated covariance of x and z [m^2]
   */
  float cov_x_z;

  /**
   * Estimated variance of y [m^2]
   */
  float cov_y_y;

  /**
   * Estimated covariance of y and z [m^2]
   */
  float cov_y_z;

  /**
   * Estimated variance of z [m^2]
   */
  float cov_z_z;

  /**
   * Number of satellites used in solution
   */
  u8 n_sats;

  /**
   * Status flags
   */
  u8 flags;
} sbp_msg_pos_ecef_cov_gnss_t;

/**
 * Get encoded size of an instance of sbp_msg_pos_ecef_cov_gnss_t
 *
 * @param msg sbp_msg_pos_ecef_cov_gnss_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_msg_pos_ecef_cov_gnss_t(
    const sbp_msg_pos_ecef_cov_gnss_t *msg);

/**
 * Encode an instance of sbp_msg_pos_ecef_cov_gnss_t to wire representation
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
 * @param msg Instance of sbp_msg_pos_ecef_cov_gnss_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_msg_pos_ecef_cov_gnss_t(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_msg_pos_ecef_cov_gnss_t *msg);

/**
 * Decode an instance of sbp_msg_pos_ecef_cov_gnss_t from wire representation
 *
 * This function decodes the wire representation of a
 * sbp_msg_pos_ecef_cov_gnss_t message to the given instance. The caller must
 * specify the length of the buffer in the \p len parameter. If non-null the
 * number of bytes read from the buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_msg_pos_ecef_cov_gnss_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_msg_pos_ecef_cov_gnss_t(const uint8_t *buf, uint8_t len,
                                          uint8_t *n_read,
                                          sbp_msg_pos_ecef_cov_gnss_t *msg);
/**
 * Send an instance of sbp_msg_pos_ecef_cov_gnss_t with the given write function
 *
 * An equivalent of #sbp_send_message which operates specifically on
 * sbp_msg_pos_ecef_cov_gnss_t
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
s8 sbp_send_sbp_msg_pos_ecef_cov_gnss_t(struct sbp_state *s, u16 sender_id,
                                        const sbp_msg_pos_ecef_cov_gnss_t *msg,
                                        s32 (*write)(u8 *buff, u32 n,
                                                     void *context));

/**
 * Compare two instances of sbp_msg_pos_ecef_cov_gnss_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_pos_ecef_cov_gnss_t instance
 * @param b sbp_msg_pos_ecef_cov_gnss_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_msg_pos_ecef_cov_gnss_t(const sbp_msg_pos_ecef_cov_gnss_t *a,
                                        const sbp_msg_pos_ecef_cov_gnss_t *b);

/** GNSS-only Geodetic Position
 *
 * This position solution message reports the absolute geodetic coordinates and
 * the status (single point vs pseudo-absolute RTK) of the position solution. If
 * the rover receiver knows the surveyed position of the base station and has an
 * RTK solution, this reports a pseudo-absolute position solution using the base
 * station position and the rover's RTK baseline vector. The full GPS time is
 * given by the preceding MSG_GPS_TIME with the matching time-of-week (tow).
 */
typedef struct {
  /**
   * GPS Time of Week [ms]
   */
  u32 tow;

  /**
   * Latitude [deg]
   */
  double lat;

  /**
   * Longitude [deg]
   */
  double lon;

  /**
   * Height above WGS84 ellipsoid [m]
   */
  double height;

  /**
   * Horizontal position estimated standard deviation [mm]
   */
  u16 h_accuracy;

  /**
   * Vertical position estimated standard deviation [mm]
   */
  u16 v_accuracy;

  /**
   * Number of satellites used in solution.
   */
  u8 n_sats;

  /**
   * Status flags
   */
  u8 flags;
} sbp_msg_pos_llh_gnss_t;

/**
 * Get encoded size of an instance of sbp_msg_pos_llh_gnss_t
 *
 * @param msg sbp_msg_pos_llh_gnss_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_msg_pos_llh_gnss_t(
    const sbp_msg_pos_llh_gnss_t *msg);

/**
 * Encode an instance of sbp_msg_pos_llh_gnss_t to wire representation
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
 * @param msg Instance of sbp_msg_pos_llh_gnss_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_msg_pos_llh_gnss_t(uint8_t *buf, uint8_t len,
                                     uint8_t *n_written,
                                     const sbp_msg_pos_llh_gnss_t *msg);

/**
 * Decode an instance of sbp_msg_pos_llh_gnss_t from wire representation
 *
 * This function decodes the wire representation of a sbp_msg_pos_llh_gnss_t
 * message to the given instance. The caller must specify the length of the
 * buffer in the \p len parameter. If non-null the number of bytes read from the
 * buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_msg_pos_llh_gnss_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_msg_pos_llh_gnss_t(const uint8_t *buf, uint8_t len,
                                     uint8_t *n_read,
                                     sbp_msg_pos_llh_gnss_t *msg);
/**
 * Send an instance of sbp_msg_pos_llh_gnss_t with the given write function
 *
 * An equivalent of #sbp_send_message which operates specifically on
 * sbp_msg_pos_llh_gnss_t
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
s8 sbp_send_sbp_msg_pos_llh_gnss_t(struct sbp_state *s, u16 sender_id,
                                   const sbp_msg_pos_llh_gnss_t *msg,
                                   s32 (*write)(u8 *buff, u32 n,
                                                void *context));

/**
 * Compare two instances of sbp_msg_pos_llh_gnss_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_pos_llh_gnss_t instance
 * @param b sbp_msg_pos_llh_gnss_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_msg_pos_llh_gnss_t(const sbp_msg_pos_llh_gnss_t *a,
                                   const sbp_msg_pos_llh_gnss_t *b);

/** GNSS-only Geodetic Position
 *
 * This position solution message reports the absolute geodetic coordinates and
 * the status (single point vs pseudo-absolute RTK) of the position solution as
 * well as the upper triangle of the 3x3 covariance matrix.  The position
 * information and Fix Mode flags should follow the MSG_POS_LLH message.  Since
 * the covariance matrix is computed in the local-level North, East, Down frame,
 * the covariance terms follow with that convention. Thus, covariances are
 * reported against the "downward" measurement and care should be taken with the
 * sign convention.
 */
typedef struct {
  /**
   * GPS Time of Week [ms]
   */
  u32 tow;

  /**
   * Latitude [deg]
   */
  double lat;

  /**
   * Longitude [deg]
   */
  double lon;

  /**
   * Height above WGS84 ellipsoid [m]
   */
  double height;

  /**
   * Estimated variance of northing [m^2]
   */
  float cov_n_n;

  /**
   * Covariance of northing and easting [m^2]
   */
  float cov_n_e;

  /**
   * Covariance of northing and downward measurement [m^2]
   */
  float cov_n_d;

  /**
   * Estimated variance of easting [m^2]
   */
  float cov_e_e;

  /**
   * Covariance of easting and downward measurement [m^2]
   */
  float cov_e_d;

  /**
   * Estimated variance of downward measurement [m^2]
   */
  float cov_d_d;

  /**
   * Number of satellites used in solution.
   */
  u8 n_sats;

  /**
   * Status flags
   */
  u8 flags;
} sbp_msg_pos_llh_cov_gnss_t;

/**
 * Get encoded size of an instance of sbp_msg_pos_llh_cov_gnss_t
 *
 * @param msg sbp_msg_pos_llh_cov_gnss_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_msg_pos_llh_cov_gnss_t(
    const sbp_msg_pos_llh_cov_gnss_t *msg);

/**
 * Encode an instance of sbp_msg_pos_llh_cov_gnss_t to wire representation
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
 * @param msg Instance of sbp_msg_pos_llh_cov_gnss_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_msg_pos_llh_cov_gnss_t(uint8_t *buf, uint8_t len,
                                         uint8_t *n_written,
                                         const sbp_msg_pos_llh_cov_gnss_t *msg);

/**
 * Decode an instance of sbp_msg_pos_llh_cov_gnss_t from wire representation
 *
 * This function decodes the wire representation of a sbp_msg_pos_llh_cov_gnss_t
 * message to the given instance. The caller must specify the length of the
 * buffer in the \p len parameter. If non-null the number of bytes read from the
 * buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_msg_pos_llh_cov_gnss_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_msg_pos_llh_cov_gnss_t(const uint8_t *buf, uint8_t len,
                                         uint8_t *n_read,
                                         sbp_msg_pos_llh_cov_gnss_t *msg);
/**
 * Send an instance of sbp_msg_pos_llh_cov_gnss_t with the given write function
 *
 * An equivalent of #sbp_send_message which operates specifically on
 * sbp_msg_pos_llh_cov_gnss_t
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
s8 sbp_send_sbp_msg_pos_llh_cov_gnss_t(struct sbp_state *s, u16 sender_id,
                                       const sbp_msg_pos_llh_cov_gnss_t *msg,
                                       s32 (*write)(u8 *buff, u32 n,
                                                    void *context));

/**
 * Compare two instances of sbp_msg_pos_llh_cov_gnss_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_pos_llh_cov_gnss_t instance
 * @param b sbp_msg_pos_llh_cov_gnss_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_msg_pos_llh_cov_gnss_t(const sbp_msg_pos_llh_cov_gnss_t *a,
                                       const sbp_msg_pos_llh_cov_gnss_t *b);

/** GNSS-only Velocity in ECEF
 *
 * This message reports the velocity in Earth Centered Earth Fixed (ECEF)
 * coordinates. The full GPS time is given by the preceding MSG_GPS_TIME with
 * the matching time-of-week (tow).
 */
typedef struct {
  /**
   * GPS Time of Week [ms]
   */
  u32 tow;

  /**
   * Velocity ECEF X coordinate [mm/s]
   */
  s32 x;

  /**
   * Velocity ECEF Y coordinate [mm/s]
   */
  s32 y;

  /**
   * Velocity ECEF Z coordinate [mm/s]
   */
  s32 z;

  /**
   * Velocity estimated standard deviation [mm/s]
   */
  u16 accuracy;

  /**
   * Number of satellites used in solution
   */
  u8 n_sats;

  /**
   * Status flags
   */
  u8 flags;
} sbp_msg_vel_ecef_gnss_t;

/**
 * Get encoded size of an instance of sbp_msg_vel_ecef_gnss_t
 *
 * @param msg sbp_msg_vel_ecef_gnss_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_msg_vel_ecef_gnss_t(
    const sbp_msg_vel_ecef_gnss_t *msg);

/**
 * Encode an instance of sbp_msg_vel_ecef_gnss_t to wire representation
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
 * @param msg Instance of sbp_msg_vel_ecef_gnss_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_msg_vel_ecef_gnss_t(uint8_t *buf, uint8_t len,
                                      uint8_t *n_written,
                                      const sbp_msg_vel_ecef_gnss_t *msg);

/**
 * Decode an instance of sbp_msg_vel_ecef_gnss_t from wire representation
 *
 * This function decodes the wire representation of a sbp_msg_vel_ecef_gnss_t
 * message to the given instance. The caller must specify the length of the
 * buffer in the \p len parameter. If non-null the number of bytes read from the
 * buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_msg_vel_ecef_gnss_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_msg_vel_ecef_gnss_t(const uint8_t *buf, uint8_t len,
                                      uint8_t *n_read,
                                      sbp_msg_vel_ecef_gnss_t *msg);
/**
 * Send an instance of sbp_msg_vel_ecef_gnss_t with the given write function
 *
 * An equivalent of #sbp_send_message which operates specifically on
 * sbp_msg_vel_ecef_gnss_t
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
s8 sbp_send_sbp_msg_vel_ecef_gnss_t(struct sbp_state *s, u16 sender_id,
                                    const sbp_msg_vel_ecef_gnss_t *msg,
                                    s32 (*write)(u8 *buff, u32 n,
                                                 void *context));

/**
 * Compare two instances of sbp_msg_vel_ecef_gnss_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_vel_ecef_gnss_t instance
 * @param b sbp_msg_vel_ecef_gnss_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_msg_vel_ecef_gnss_t(const sbp_msg_vel_ecef_gnss_t *a,
                                    const sbp_msg_vel_ecef_gnss_t *b);

/** GNSS-only Velocity in ECEF
 *
 * This message reports the velocity in Earth Centered Earth Fixed (ECEF)
 * coordinates. The full GPS time is given by the preceding MSG_GPS_TIME with
 * the matching time-of-week (tow).
 */
typedef struct {
  /**
   * GPS Time of Week [ms]
   */
  u32 tow;

  /**
   * Velocity ECEF X coordinate [mm/s]
   */
  s32 x;

  /**
   * Velocity ECEF Y coordinate [mm/s]
   */
  s32 y;

  /**
   * Velocity ECEF Z coordinate [mm/s]
   */
  s32 z;

  /**
   * Estimated variance of x [m^2/s^2]
   */
  float cov_x_x;

  /**
   * Estimated covariance of x and y [m^2/s^2]
   */
  float cov_x_y;

  /**
   * Estimated covariance of x and z [m^2/s^2]
   */
  float cov_x_z;

  /**
   * Estimated variance of y [m^2/s^2]
   */
  float cov_y_y;

  /**
   * Estimated covariance of y and z [m^2/s^2]
   */
  float cov_y_z;

  /**
   * Estimated variance of z [m^2/s^2]
   */
  float cov_z_z;

  /**
   * Number of satellites used in solution
   */
  u8 n_sats;

  /**
   * Status flags
   */
  u8 flags;
} sbp_msg_vel_ecef_cov_gnss_t;

/**
 * Get encoded size of an instance of sbp_msg_vel_ecef_cov_gnss_t
 *
 * @param msg sbp_msg_vel_ecef_cov_gnss_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_msg_vel_ecef_cov_gnss_t(
    const sbp_msg_vel_ecef_cov_gnss_t *msg);

/**
 * Encode an instance of sbp_msg_vel_ecef_cov_gnss_t to wire representation
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
 * @param msg Instance of sbp_msg_vel_ecef_cov_gnss_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_msg_vel_ecef_cov_gnss_t(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_msg_vel_ecef_cov_gnss_t *msg);

/**
 * Decode an instance of sbp_msg_vel_ecef_cov_gnss_t from wire representation
 *
 * This function decodes the wire representation of a
 * sbp_msg_vel_ecef_cov_gnss_t message to the given instance. The caller must
 * specify the length of the buffer in the \p len parameter. If non-null the
 * number of bytes read from the buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_msg_vel_ecef_cov_gnss_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_msg_vel_ecef_cov_gnss_t(const uint8_t *buf, uint8_t len,
                                          uint8_t *n_read,
                                          sbp_msg_vel_ecef_cov_gnss_t *msg);
/**
 * Send an instance of sbp_msg_vel_ecef_cov_gnss_t with the given write function
 *
 * An equivalent of #sbp_send_message which operates specifically on
 * sbp_msg_vel_ecef_cov_gnss_t
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
s8 sbp_send_sbp_msg_vel_ecef_cov_gnss_t(struct sbp_state *s, u16 sender_id,
                                        const sbp_msg_vel_ecef_cov_gnss_t *msg,
                                        s32 (*write)(u8 *buff, u32 n,
                                                     void *context));

/**
 * Compare two instances of sbp_msg_vel_ecef_cov_gnss_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_vel_ecef_cov_gnss_t instance
 * @param b sbp_msg_vel_ecef_cov_gnss_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_msg_vel_ecef_cov_gnss_t(const sbp_msg_vel_ecef_cov_gnss_t *a,
                                        const sbp_msg_vel_ecef_cov_gnss_t *b);

/** GNSS-only Velocity in NED
 *
 * This message reports the velocity in local North East Down (NED) coordinates.
 * The NED coordinate system is defined as the local WGS84 tangent plane
 * centered at the current position. The full GPS time is given by the preceding
 * MSG_GPS_TIME with the matching time-of-week (tow).
 */
typedef struct {
  /**
   * GPS Time of Week [ms]
   */
  u32 tow;

  /**
   * Velocity North coordinate [mm/s]
   */
  s32 n;

  /**
   * Velocity East coordinate [mm/s]
   */
  s32 e;

  /**
   * Velocity Down coordinate [mm/s]
   */
  s32 d;

  /**
   * Horizontal velocity estimated standard deviation [mm/s]
   */
  u16 h_accuracy;

  /**
   * Vertical velocity estimated standard deviation [mm/s]
   */
  u16 v_accuracy;

  /**
   * Number of satellites used in solution
   */
  u8 n_sats;

  /**
   * Status flags
   */
  u8 flags;
} sbp_msg_vel_ned_gnss_t;

/**
 * Get encoded size of an instance of sbp_msg_vel_ned_gnss_t
 *
 * @param msg sbp_msg_vel_ned_gnss_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_msg_vel_ned_gnss_t(
    const sbp_msg_vel_ned_gnss_t *msg);

/**
 * Encode an instance of sbp_msg_vel_ned_gnss_t to wire representation
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
 * @param msg Instance of sbp_msg_vel_ned_gnss_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_msg_vel_ned_gnss_t(uint8_t *buf, uint8_t len,
                                     uint8_t *n_written,
                                     const sbp_msg_vel_ned_gnss_t *msg);

/**
 * Decode an instance of sbp_msg_vel_ned_gnss_t from wire representation
 *
 * This function decodes the wire representation of a sbp_msg_vel_ned_gnss_t
 * message to the given instance. The caller must specify the length of the
 * buffer in the \p len parameter. If non-null the number of bytes read from the
 * buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_msg_vel_ned_gnss_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_msg_vel_ned_gnss_t(const uint8_t *buf, uint8_t len,
                                     uint8_t *n_read,
                                     sbp_msg_vel_ned_gnss_t *msg);
/**
 * Send an instance of sbp_msg_vel_ned_gnss_t with the given write function
 *
 * An equivalent of #sbp_send_message which operates specifically on
 * sbp_msg_vel_ned_gnss_t
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
s8 sbp_send_sbp_msg_vel_ned_gnss_t(struct sbp_state *s, u16 sender_id,
                                   const sbp_msg_vel_ned_gnss_t *msg,
                                   s32 (*write)(u8 *buff, u32 n,
                                                void *context));

/**
 * Compare two instances of sbp_msg_vel_ned_gnss_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_vel_ned_gnss_t instance
 * @param b sbp_msg_vel_ned_gnss_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_msg_vel_ned_gnss_t(const sbp_msg_vel_ned_gnss_t *a,
                                   const sbp_msg_vel_ned_gnss_t *b);

/** GNSS-only Velocity in NED
 *
 * This message reports the velocity in local North East Down (NED) coordinates.
 * The NED coordinate system is defined as the local WGS84 tangent plane
 * centered at the current position. The full GPS time is given by the preceding
 * MSG_GPS_TIME with the matching time-of-week (tow). This message is similar to
 * the MSG_VEL_NED, but it includes the upper triangular portion of the 3x3
 * covariance matrix.
 */
typedef struct {
  /**
   * GPS Time of Week [ms]
   */
  u32 tow;

  /**
   * Velocity North coordinate [mm/s]
   */
  s32 n;

  /**
   * Velocity East coordinate [mm/s]
   */
  s32 e;

  /**
   * Velocity Down coordinate [mm/s]
   */
  s32 d;

  /**
   * Estimated variance of northward measurement [m^2]
   */
  float cov_n_n;

  /**
   * Covariance of northward and eastward measurement [m^2]
   */
  float cov_n_e;

  /**
   * Covariance of northward and downward measurement [m^2]
   */
  float cov_n_d;

  /**
   * Estimated variance of eastward measurement [m^2]
   */
  float cov_e_e;

  /**
   * Covariance of eastward and downward measurement [m^2]
   */
  float cov_e_d;

  /**
   * Estimated variance of downward measurement [m^2]
   */
  float cov_d_d;

  /**
   * Number of satellites used in solution
   */
  u8 n_sats;

  /**
   * Status flags
   */
  u8 flags;
} sbp_msg_vel_ned_cov_gnss_t;

/**
 * Get encoded size of an instance of sbp_msg_vel_ned_cov_gnss_t
 *
 * @param msg sbp_msg_vel_ned_cov_gnss_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_msg_vel_ned_cov_gnss_t(
    const sbp_msg_vel_ned_cov_gnss_t *msg);

/**
 * Encode an instance of sbp_msg_vel_ned_cov_gnss_t to wire representation
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
 * @param msg Instance of sbp_msg_vel_ned_cov_gnss_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_msg_vel_ned_cov_gnss_t(uint8_t *buf, uint8_t len,
                                         uint8_t *n_written,
                                         const sbp_msg_vel_ned_cov_gnss_t *msg);

/**
 * Decode an instance of sbp_msg_vel_ned_cov_gnss_t from wire representation
 *
 * This function decodes the wire representation of a sbp_msg_vel_ned_cov_gnss_t
 * message to the given instance. The caller must specify the length of the
 * buffer in the \p len parameter. If non-null the number of bytes read from the
 * buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_msg_vel_ned_cov_gnss_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_msg_vel_ned_cov_gnss_t(const uint8_t *buf, uint8_t len,
                                         uint8_t *n_read,
                                         sbp_msg_vel_ned_cov_gnss_t *msg);
/**
 * Send an instance of sbp_msg_vel_ned_cov_gnss_t with the given write function
 *
 * An equivalent of #sbp_send_message which operates specifically on
 * sbp_msg_vel_ned_cov_gnss_t
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
s8 sbp_send_sbp_msg_vel_ned_cov_gnss_t(struct sbp_state *s, u16 sender_id,
                                       const sbp_msg_vel_ned_cov_gnss_t *msg,
                                       s32 (*write)(u8 *buff, u32 n,
                                                    void *context));

/**
 * Compare two instances of sbp_msg_vel_ned_cov_gnss_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_vel_ned_cov_gnss_t instance
 * @param b sbp_msg_vel_ned_cov_gnss_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_msg_vel_ned_cov_gnss_t(const sbp_msg_vel_ned_cov_gnss_t *a,
                                       const sbp_msg_vel_ned_cov_gnss_t *b);

/** Velocity in User Frame
 *
 * This message reports the velocity in the Vehicle Body Frame. By convention,
 * the x-axis should point out the nose of the vehicle and represent the forward
 * direction, while as the y-axis should point out the right hand side of the
 * vehicle. Since this is a right handed system, z should point out the bottom
 * of the vehicle. The orientation and origin of the Vehicle Body Frame are
 * specified via the device settings. The full GPS time is given by the
 * preceding MSG_GPS_TIME with the matching time-of-week (tow). This message is
 * only produced by inertial versions of Swift products and is not available
 * from Piksi Multi or Duro.
 */
typedef struct {
  /**
   * GPS Time of Week [ms]
   */
  u32 tow;

  /**
   * Velocity in x direction [mm/s]
   */
  s32 x;

  /**
   * Velocity in y direction [mm/s]
   */
  s32 y;

  /**
   * Velocity in z direction [mm/s]
   */
  s32 z;

  /**
   * Estimated variance of x [m^2]
   */
  float cov_x_x;

  /**
   * Covariance of x and y [m^2]
   */
  float cov_x_y;

  /**
   * Covariance of x and z [m^2]
   */
  float cov_x_z;

  /**
   * Estimated variance of y [m^2]
   */
  float cov_y_y;

  /**
   * Covariance of y and z [m^2]
   */
  float cov_y_z;

  /**
   * Estimated variance of z [m^2]
   */
  float cov_z_z;

  /**
   * Number of satellites used in solution
   */
  u8 n_sats;

  /**
   * Status flags
   */
  u8 flags;
} sbp_msg_vel_body_t;

/**
 * Get encoded size of an instance of sbp_msg_vel_body_t
 *
 * @param msg sbp_msg_vel_body_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_msg_vel_body_t(const sbp_msg_vel_body_t *msg);

/**
 * Encode an instance of sbp_msg_vel_body_t to wire representation
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
 * @param msg Instance of sbp_msg_vel_body_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_msg_vel_body_t(uint8_t *buf, uint8_t len, uint8_t *n_written,
                                 const sbp_msg_vel_body_t *msg);

/**
 * Decode an instance of sbp_msg_vel_body_t from wire representation
 *
 * This function decodes the wire representation of a sbp_msg_vel_body_t message
 * to the given instance. The caller must specify the length of the buffer in
 * the \p len parameter. If non-null the number of bytes read from the buffer
 * will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_msg_vel_body_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_msg_vel_body_t(const uint8_t *buf, uint8_t len,
                                 uint8_t *n_read, sbp_msg_vel_body_t *msg);
/**
 * Send an instance of sbp_msg_vel_body_t with the given write function
 *
 * An equivalent of #sbp_send_message which operates specifically on
 * sbp_msg_vel_body_t
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
s8 sbp_send_sbp_msg_vel_body_t(struct sbp_state *s, u16 sender_id,
                               const sbp_msg_vel_body_t *msg,
                               s32 (*write)(u8 *buff, u32 n, void *context));

/**
 * Compare two instances of sbp_msg_vel_body_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_vel_body_t instance
 * @param b sbp_msg_vel_body_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_msg_vel_body_t(const sbp_msg_vel_body_t *a,
                               const sbp_msg_vel_body_t *b);

/** Age of corrections
 *
 * This message reports the Age of the corrections used for the current
 * Differential solution.
 */
typedef struct {
  /**
   * GPS Time of Week [ms]
   */
  u32 tow;

  /**
   * Age of the corrections (0xFFFF indicates invalid) [deciseconds]
   */
  u16 age;
} sbp_msg_age_corrections_t;

/**
 * Get encoded size of an instance of sbp_msg_age_corrections_t
 *
 * @param msg sbp_msg_age_corrections_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_msg_age_corrections_t(
    const sbp_msg_age_corrections_t *msg);

/**
 * Encode an instance of sbp_msg_age_corrections_t to wire representation
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
 * @param msg Instance of sbp_msg_age_corrections_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_msg_age_corrections_t(uint8_t *buf, uint8_t len,
                                        uint8_t *n_written,
                                        const sbp_msg_age_corrections_t *msg);

/**
 * Decode an instance of sbp_msg_age_corrections_t from wire representation
 *
 * This function decodes the wire representation of a sbp_msg_age_corrections_t
 * message to the given instance. The caller must specify the length of the
 * buffer in the \p len parameter. If non-null the number of bytes read from the
 * buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_msg_age_corrections_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_msg_age_corrections_t(const uint8_t *buf, uint8_t len,
                                        uint8_t *n_read,
                                        sbp_msg_age_corrections_t *msg);
/**
 * Send an instance of sbp_msg_age_corrections_t with the given write function
 *
 * An equivalent of #sbp_send_message which operates specifically on
 * sbp_msg_age_corrections_t
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
s8 sbp_send_sbp_msg_age_corrections_t(struct sbp_state *s, u16 sender_id,
                                      const sbp_msg_age_corrections_t *msg,
                                      s32 (*write)(u8 *buff, u32 n,
                                                   void *context));

/**
 * Compare two instances of sbp_msg_age_corrections_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_age_corrections_t instance
 * @param b sbp_msg_age_corrections_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_msg_age_corrections_t(const sbp_msg_age_corrections_t *a,
                                      const sbp_msg_age_corrections_t *b);

/** GPS Time (v1.0)
 *
 * This message reports the GPS time, representing the time since the GPS epoch
 * began on midnight January 6, 1980 UTC. GPS time counts the weeks and seconds
 * of the week. The weeks begin at the Saturday/Sunday transition. GPS week 0
 * began at the beginning of the GPS time scale.
 *
 */
typedef struct {
  /**
   * GPS week number [weeks]
   */
  u16 wn;

  /**
   * GPS time of week rounded to the nearest millisecond [ms]
   */
  u32 tow;

  /**
   * Nanosecond residual of millisecond-rounded TOW (ranges from -500000 to
   * 500000) [ns]
   */
  s32 ns_residual;

  /**
   * Status flags (reserved)
   */
  u8 flags;
} sbp_msg_gps_time_dep_a_t;

/**
 * Get encoded size of an instance of sbp_msg_gps_time_dep_a_t
 *
 * @param msg sbp_msg_gps_time_dep_a_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_msg_gps_time_dep_a_t(
    const sbp_msg_gps_time_dep_a_t *msg);

/**
 * Encode an instance of sbp_msg_gps_time_dep_a_t to wire representation
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
 * @param msg Instance of sbp_msg_gps_time_dep_a_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_msg_gps_time_dep_a_t(uint8_t *buf, uint8_t len,
                                       uint8_t *n_written,
                                       const sbp_msg_gps_time_dep_a_t *msg);

/**
 * Decode an instance of sbp_msg_gps_time_dep_a_t from wire representation
 *
 * This function decodes the wire representation of a sbp_msg_gps_time_dep_a_t
 * message to the given instance. The caller must specify the length of the
 * buffer in the \p len parameter. If non-null the number of bytes read from the
 * buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_msg_gps_time_dep_a_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_msg_gps_time_dep_a_t(const uint8_t *buf, uint8_t len,
                                       uint8_t *n_read,
                                       sbp_msg_gps_time_dep_a_t *msg);
/**
 * Send an instance of sbp_msg_gps_time_dep_a_t with the given write function
 *
 * An equivalent of #sbp_send_message which operates specifically on
 * sbp_msg_gps_time_dep_a_t
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
s8 sbp_send_sbp_msg_gps_time_dep_a_t(struct sbp_state *s, u16 sender_id,
                                     const sbp_msg_gps_time_dep_a_t *msg,
                                     s32 (*write)(u8 *buff, u32 n,
                                                  void *context));

/**
 * Compare two instances of sbp_msg_gps_time_dep_a_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_gps_time_dep_a_t instance
 * @param b sbp_msg_gps_time_dep_a_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_msg_gps_time_dep_a_t(const sbp_msg_gps_time_dep_a_t *a,
                                     const sbp_msg_gps_time_dep_a_t *b);

/** Dilution of Precision
 *
 * This dilution of precision (DOP) message describes the effect of navigation
 * satellite geometry on positional measurement precision.
 */
typedef struct {
  /**
   * GPS Time of Week [ms]
   */
  u32 tow;

  /**
   * Geometric Dilution of Precision [0.01]
   */
  u16 gdop;

  /**
   * Position Dilution of Precision [0.01]
   */
  u16 pdop;

  /**
   * Time Dilution of Precision [0.01]
   */
  u16 tdop;

  /**
   * Horizontal Dilution of Precision [0.01]
   */
  u16 hdop;

  /**
   * Vertical Dilution of Precision [0.01]
   */
  u16 vdop;
} sbp_msg_dops_dep_a_t;

/**
 * Get encoded size of an instance of sbp_msg_dops_dep_a_t
 *
 * @param msg sbp_msg_dops_dep_a_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_msg_dops_dep_a_t(const sbp_msg_dops_dep_a_t *msg);

/**
 * Encode an instance of sbp_msg_dops_dep_a_t to wire representation
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
 * @param msg Instance of sbp_msg_dops_dep_a_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_msg_dops_dep_a_t(uint8_t *buf, uint8_t len,
                                   uint8_t *n_written,
                                   const sbp_msg_dops_dep_a_t *msg);

/**
 * Decode an instance of sbp_msg_dops_dep_a_t from wire representation
 *
 * This function decodes the wire representation of a sbp_msg_dops_dep_a_t
 * message to the given instance. The caller must specify the length of the
 * buffer in the \p len parameter. If non-null the number of bytes read from the
 * buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_msg_dops_dep_a_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_msg_dops_dep_a_t(const uint8_t *buf, uint8_t len,
                                   uint8_t *n_read, sbp_msg_dops_dep_a_t *msg);
/**
 * Send an instance of sbp_msg_dops_dep_a_t with the given write function
 *
 * An equivalent of #sbp_send_message which operates specifically on
 * sbp_msg_dops_dep_a_t
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
s8 sbp_send_sbp_msg_dops_dep_a_t(struct sbp_state *s, u16 sender_id,
                                 const sbp_msg_dops_dep_a_t *msg,
                                 s32 (*write)(u8 *buff, u32 n, void *context));

/**
 * Compare two instances of sbp_msg_dops_dep_a_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_dops_dep_a_t instance
 * @param b sbp_msg_dops_dep_a_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_msg_dops_dep_a_t(const sbp_msg_dops_dep_a_t *a,
                                 const sbp_msg_dops_dep_a_t *b);

/** Single-point position in ECEF
 *
 * The position solution message reports absolute Earth Centered Earth Fixed
 * (ECEF) coordinates and the status (single point vs pseudo-absolute RTK) of
 * the position solution. If the rover receiver knows the surveyed position of
 * the base station and has an RTK solution, this reports a pseudo-absolute
 * position solution using the base station position and the rover's RTK
 * baseline vector. The full GPS time is given by the preceding MSG_GPS_TIME
 * with the matching time-of-week (tow).
 */
typedef struct {
  /**
   * GPS Time of Week [ms]
   */
  u32 tow;

  /**
   * ECEF X coordinate [m]
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

  /**
   * Position accuracy estimate (not implemented). Defaults to 0. [mm]
   */
  u16 accuracy;

  /**
   * Number of satellites used in solution
   */
  u8 n_sats;

  /**
   * Status flags
   */
  u8 flags;
} sbp_msg_pos_ecef_dep_a_t;

/**
 * Get encoded size of an instance of sbp_msg_pos_ecef_dep_a_t
 *
 * @param msg sbp_msg_pos_ecef_dep_a_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_msg_pos_ecef_dep_a_t(
    const sbp_msg_pos_ecef_dep_a_t *msg);

/**
 * Encode an instance of sbp_msg_pos_ecef_dep_a_t to wire representation
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
 * @param msg Instance of sbp_msg_pos_ecef_dep_a_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_msg_pos_ecef_dep_a_t(uint8_t *buf, uint8_t len,
                                       uint8_t *n_written,
                                       const sbp_msg_pos_ecef_dep_a_t *msg);

/**
 * Decode an instance of sbp_msg_pos_ecef_dep_a_t from wire representation
 *
 * This function decodes the wire representation of a sbp_msg_pos_ecef_dep_a_t
 * message to the given instance. The caller must specify the length of the
 * buffer in the \p len parameter. If non-null the number of bytes read from the
 * buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_msg_pos_ecef_dep_a_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_msg_pos_ecef_dep_a_t(const uint8_t *buf, uint8_t len,
                                       uint8_t *n_read,
                                       sbp_msg_pos_ecef_dep_a_t *msg);
/**
 * Send an instance of sbp_msg_pos_ecef_dep_a_t with the given write function
 *
 * An equivalent of #sbp_send_message which operates specifically on
 * sbp_msg_pos_ecef_dep_a_t
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
s8 sbp_send_sbp_msg_pos_ecef_dep_a_t(struct sbp_state *s, u16 sender_id,
                                     const sbp_msg_pos_ecef_dep_a_t *msg,
                                     s32 (*write)(u8 *buff, u32 n,
                                                  void *context));

/**
 * Compare two instances of sbp_msg_pos_ecef_dep_a_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_pos_ecef_dep_a_t instance
 * @param b sbp_msg_pos_ecef_dep_a_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_msg_pos_ecef_dep_a_t(const sbp_msg_pos_ecef_dep_a_t *a,
                                     const sbp_msg_pos_ecef_dep_a_t *b);

/** Geodetic Position
 *
 * This position solution message reports the absolute geodetic coordinates and
 * the status (single point vs pseudo-absolute RTK) of the position solution. If
 * the rover receiver knows the surveyed position of the base station and has an
 * RTK solution, this reports a pseudo-absolute position solution using the base
 * station position and the rover's RTK baseline vector. The full GPS time is
 * given by the preceding MSG_GPS_TIME with the matching time-of-week (tow).
 */
typedef struct {
  /**
   * GPS Time of Week [ms]
   */
  u32 tow;

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

  /**
   * Horizontal position accuracy estimate (not implemented). Defaults to 0.
   * [mm]
   */
  u16 h_accuracy;

  /**
   * Vertical position accuracy estimate (not implemented). Defaults to 0. [mm]
   */
  u16 v_accuracy;

  /**
   * Number of satellites used in solution.
   */
  u8 n_sats;

  /**
   * Status flags
   */
  u8 flags;
} sbp_msg_pos_llh_dep_a_t;

/**
 * Get encoded size of an instance of sbp_msg_pos_llh_dep_a_t
 *
 * @param msg sbp_msg_pos_llh_dep_a_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_msg_pos_llh_dep_a_t(
    const sbp_msg_pos_llh_dep_a_t *msg);

/**
 * Encode an instance of sbp_msg_pos_llh_dep_a_t to wire representation
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
 * @param msg Instance of sbp_msg_pos_llh_dep_a_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_msg_pos_llh_dep_a_t(uint8_t *buf, uint8_t len,
                                      uint8_t *n_written,
                                      const sbp_msg_pos_llh_dep_a_t *msg);

/**
 * Decode an instance of sbp_msg_pos_llh_dep_a_t from wire representation
 *
 * This function decodes the wire representation of a sbp_msg_pos_llh_dep_a_t
 * message to the given instance. The caller must specify the length of the
 * buffer in the \p len parameter. If non-null the number of bytes read from the
 * buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_msg_pos_llh_dep_a_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_msg_pos_llh_dep_a_t(const uint8_t *buf, uint8_t len,
                                      uint8_t *n_read,
                                      sbp_msg_pos_llh_dep_a_t *msg);
/**
 * Send an instance of sbp_msg_pos_llh_dep_a_t with the given write function
 *
 * An equivalent of #sbp_send_message which operates specifically on
 * sbp_msg_pos_llh_dep_a_t
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
s8 sbp_send_sbp_msg_pos_llh_dep_a_t(struct sbp_state *s, u16 sender_id,
                                    const sbp_msg_pos_llh_dep_a_t *msg,
                                    s32 (*write)(u8 *buff, u32 n,
                                                 void *context));

/**
 * Compare two instances of sbp_msg_pos_llh_dep_a_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_pos_llh_dep_a_t instance
 * @param b sbp_msg_pos_llh_dep_a_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_msg_pos_llh_dep_a_t(const sbp_msg_pos_llh_dep_a_t *a,
                                    const sbp_msg_pos_llh_dep_a_t *b);

/** Baseline Position in ECEF
 *
 * This message reports the baseline solution in Earth Centered Earth Fixed
 * (ECEF) coordinates. This baseline is the relative vector distance from the
 * base station to the rover receiver. The full GPS time is given by the
 * preceding MSG_GPS_TIME with the matching time-of-week (tow).
 */
typedef struct {
  /**
   * GPS Time of Week [ms]
   */
  u32 tow;

  /**
   * Baseline ECEF X coordinate [mm]
   */
  s32 x;

  /**
   * Baseline ECEF Y coordinate [mm]
   */
  s32 y;

  /**
   * Baseline ECEF Z coordinate [mm]
   */
  s32 z;

  /**
   * Position accuracy estimate [mm]
   */
  u16 accuracy;

  /**
   * Number of satellites used in solution
   */
  u8 n_sats;

  /**
   * Status flags
   */
  u8 flags;
} sbp_msg_baseline_ecef_dep_a_t;

/**
 * Get encoded size of an instance of sbp_msg_baseline_ecef_dep_a_t
 *
 * @param msg sbp_msg_baseline_ecef_dep_a_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_msg_baseline_ecef_dep_a_t(
    const sbp_msg_baseline_ecef_dep_a_t *msg);

/**
 * Encode an instance of sbp_msg_baseline_ecef_dep_a_t to wire representation
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
 * @param msg Instance of sbp_msg_baseline_ecef_dep_a_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_msg_baseline_ecef_dep_a_t(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_msg_baseline_ecef_dep_a_t *msg);

/**
 * Decode an instance of sbp_msg_baseline_ecef_dep_a_t from wire representation
 *
 * This function decodes the wire representation of a
 * sbp_msg_baseline_ecef_dep_a_t message to the given instance. The caller must
 * specify the length of the buffer in the \p len parameter. If non-null the
 * number of bytes read from the buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_msg_baseline_ecef_dep_a_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_msg_baseline_ecef_dep_a_t(const uint8_t *buf, uint8_t len,
                                            uint8_t *n_read,
                                            sbp_msg_baseline_ecef_dep_a_t *msg);
/**
 * Send an instance of sbp_msg_baseline_ecef_dep_a_t with the given write
 * function
 *
 * An equivalent of #sbp_send_message which operates specifically on
 * sbp_msg_baseline_ecef_dep_a_t
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
s8 sbp_send_sbp_msg_baseline_ecef_dep_a_t(
    struct sbp_state *s, u16 sender_id,
    const sbp_msg_baseline_ecef_dep_a_t *msg,
    s32 (*write)(u8 *buff, u32 n, void *context));

/**
 * Compare two instances of sbp_msg_baseline_ecef_dep_a_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_baseline_ecef_dep_a_t instance
 * @param b sbp_msg_baseline_ecef_dep_a_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_msg_baseline_ecef_dep_a_t(
    const sbp_msg_baseline_ecef_dep_a_t *a,
    const sbp_msg_baseline_ecef_dep_a_t *b);

/** Baseline in NED
 *
 * This message reports the baseline solution in North East Down (NED)
 * coordinates. This baseline is the relative vector distance from the base
 * station to the rover receiver, and NED coordinate system is defined at the
 * local WGS84 tangent plane centered at the base station position.  The full
 * GPS time is given by the preceding MSG_GPS_TIME with the matching
 * time-of-week (tow).
 */
typedef struct {
  /**
   * GPS Time of Week [ms]
   */
  u32 tow;

  /**
   * Baseline North coordinate [mm]
   */
  s32 n;

  /**
   * Baseline East coordinate [mm]
   */
  s32 e;

  /**
   * Baseline Down coordinate [mm]
   */
  s32 d;

  /**
   * Horizontal position accuracy estimate (not implemented). Defaults to 0.
   * [mm]
   */
  u16 h_accuracy;

  /**
   * Vertical position accuracy estimate (not implemented). Defaults to 0. [mm]
   */
  u16 v_accuracy;

  /**
   * Number of satellites used in solution
   */
  u8 n_sats;

  /**
   * Status flags
   */
  u8 flags;
} sbp_msg_baseline_ned_dep_a_t;

/**
 * Get encoded size of an instance of sbp_msg_baseline_ned_dep_a_t
 *
 * @param msg sbp_msg_baseline_ned_dep_a_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_msg_baseline_ned_dep_a_t(
    const sbp_msg_baseline_ned_dep_a_t *msg);

/**
 * Encode an instance of sbp_msg_baseline_ned_dep_a_t to wire representation
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
 * @param msg Instance of sbp_msg_baseline_ned_dep_a_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_msg_baseline_ned_dep_a_t(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_msg_baseline_ned_dep_a_t *msg);

/**
 * Decode an instance of sbp_msg_baseline_ned_dep_a_t from wire representation
 *
 * This function decodes the wire representation of a
 * sbp_msg_baseline_ned_dep_a_t message to the given instance. The caller must
 * specify the length of the buffer in the \p len parameter. If non-null the
 * number of bytes read from the buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_msg_baseline_ned_dep_a_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_msg_baseline_ned_dep_a_t(const uint8_t *buf, uint8_t len,
                                           uint8_t *n_read,
                                           sbp_msg_baseline_ned_dep_a_t *msg);
/**
 * Send an instance of sbp_msg_baseline_ned_dep_a_t with the given write
 * function
 *
 * An equivalent of #sbp_send_message which operates specifically on
 * sbp_msg_baseline_ned_dep_a_t
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
s8 sbp_send_sbp_msg_baseline_ned_dep_a_t(
    struct sbp_state *s, u16 sender_id, const sbp_msg_baseline_ned_dep_a_t *msg,
    s32 (*write)(u8 *buff, u32 n, void *context));

/**
 * Compare two instances of sbp_msg_baseline_ned_dep_a_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_baseline_ned_dep_a_t instance
 * @param b sbp_msg_baseline_ned_dep_a_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_msg_baseline_ned_dep_a_t(const sbp_msg_baseline_ned_dep_a_t *a,
                                         const sbp_msg_baseline_ned_dep_a_t *b);

/** Velocity in ECEF
 *
 * This message reports the velocity in Earth Centered Earth Fixed (ECEF)
 * coordinates. The full GPS time is given by the preceding MSG_GPS_TIME with
 * the matching time-of-week (tow).
 */
typedef struct {
  /**
   * GPS Time of Week [ms]
   */
  u32 tow;

  /**
   * Velocity ECEF X coordinate [mm/s]
   */
  s32 x;

  /**
   * Velocity ECEF Y coordinate [mm/s]
   */
  s32 y;

  /**
   * Velocity ECEF Z coordinate [mm/s]
   */
  s32 z;

  /**
   * Velocity accuracy estimate (not implemented). Defaults to 0. [mm/s]
   */
  u16 accuracy;

  /**
   * Number of satellites used in solution
   */
  u8 n_sats;

  /**
   * Status flags (reserved)
   */
  u8 flags;
} sbp_msg_vel_ecef_dep_a_t;

/**
 * Get encoded size of an instance of sbp_msg_vel_ecef_dep_a_t
 *
 * @param msg sbp_msg_vel_ecef_dep_a_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_msg_vel_ecef_dep_a_t(
    const sbp_msg_vel_ecef_dep_a_t *msg);

/**
 * Encode an instance of sbp_msg_vel_ecef_dep_a_t to wire representation
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
 * @param msg Instance of sbp_msg_vel_ecef_dep_a_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_msg_vel_ecef_dep_a_t(uint8_t *buf, uint8_t len,
                                       uint8_t *n_written,
                                       const sbp_msg_vel_ecef_dep_a_t *msg);

/**
 * Decode an instance of sbp_msg_vel_ecef_dep_a_t from wire representation
 *
 * This function decodes the wire representation of a sbp_msg_vel_ecef_dep_a_t
 * message to the given instance. The caller must specify the length of the
 * buffer in the \p len parameter. If non-null the number of bytes read from the
 * buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_msg_vel_ecef_dep_a_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_msg_vel_ecef_dep_a_t(const uint8_t *buf, uint8_t len,
                                       uint8_t *n_read,
                                       sbp_msg_vel_ecef_dep_a_t *msg);
/**
 * Send an instance of sbp_msg_vel_ecef_dep_a_t with the given write function
 *
 * An equivalent of #sbp_send_message which operates specifically on
 * sbp_msg_vel_ecef_dep_a_t
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
s8 sbp_send_sbp_msg_vel_ecef_dep_a_t(struct sbp_state *s, u16 sender_id,
                                     const sbp_msg_vel_ecef_dep_a_t *msg,
                                     s32 (*write)(u8 *buff, u32 n,
                                                  void *context));

/**
 * Compare two instances of sbp_msg_vel_ecef_dep_a_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_vel_ecef_dep_a_t instance
 * @param b sbp_msg_vel_ecef_dep_a_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_msg_vel_ecef_dep_a_t(const sbp_msg_vel_ecef_dep_a_t *a,
                                     const sbp_msg_vel_ecef_dep_a_t *b);

/** Velocity in NED
 *
 * This message reports the velocity in local North East Down (NED) coordinates.
 * The NED coordinate system is defined as the local WGS84 tangent plane
 * centered at the current position. The full GPS time is given by the preceding
 * MSG_GPS_TIME with the matching time-of-week (tow).
 */
typedef struct {
  /**
   * GPS Time of Week [ms]
   */
  u32 tow;

  /**
   * Velocity North coordinate [mm/s]
   */
  s32 n;

  /**
   * Velocity East coordinate [mm/s]
   */
  s32 e;

  /**
   * Velocity Down coordinate [mm/s]
   */
  s32 d;

  /**
   * Horizontal velocity accuracy estimate (not implemented). Defaults to 0.
   * [mm/s]
   */
  u16 h_accuracy;

  /**
   * Vertical velocity accuracy estimate (not implemented). Defaults to 0.
   * [mm/s]
   */
  u16 v_accuracy;

  /**
   * Number of satellites used in solution
   */
  u8 n_sats;

  /**
   * Status flags (reserved)
   */
  u8 flags;
} sbp_msg_vel_ned_dep_a_t;

/**
 * Get encoded size of an instance of sbp_msg_vel_ned_dep_a_t
 *
 * @param msg sbp_msg_vel_ned_dep_a_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_msg_vel_ned_dep_a_t(
    const sbp_msg_vel_ned_dep_a_t *msg);

/**
 * Encode an instance of sbp_msg_vel_ned_dep_a_t to wire representation
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
 * @param msg Instance of sbp_msg_vel_ned_dep_a_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_msg_vel_ned_dep_a_t(uint8_t *buf, uint8_t len,
                                      uint8_t *n_written,
                                      const sbp_msg_vel_ned_dep_a_t *msg);

/**
 * Decode an instance of sbp_msg_vel_ned_dep_a_t from wire representation
 *
 * This function decodes the wire representation of a sbp_msg_vel_ned_dep_a_t
 * message to the given instance. The caller must specify the length of the
 * buffer in the \p len parameter. If non-null the number of bytes read from the
 * buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_msg_vel_ned_dep_a_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_msg_vel_ned_dep_a_t(const uint8_t *buf, uint8_t len,
                                      uint8_t *n_read,
                                      sbp_msg_vel_ned_dep_a_t *msg);
/**
 * Send an instance of sbp_msg_vel_ned_dep_a_t with the given write function
 *
 * An equivalent of #sbp_send_message which operates specifically on
 * sbp_msg_vel_ned_dep_a_t
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
s8 sbp_send_sbp_msg_vel_ned_dep_a_t(struct sbp_state *s, u16 sender_id,
                                    const sbp_msg_vel_ned_dep_a_t *msg,
                                    s32 (*write)(u8 *buff, u32 n,
                                                 void *context));

/**
 * Compare two instances of sbp_msg_vel_ned_dep_a_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_vel_ned_dep_a_t instance
 * @param b sbp_msg_vel_ned_dep_a_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_msg_vel_ned_dep_a_t(const sbp_msg_vel_ned_dep_a_t *a,
                                    const sbp_msg_vel_ned_dep_a_t *b);

/** Heading relative to True North
 *
 * This message reports the baseline heading pointing from the base station to
 * the rover relative to True North. The full GPS time is given by the preceding
 * MSG_GPS_TIME with the matching time-of-week (tow).
 */
typedef struct {
  /**
   * GPS Time of Week [ms]
   */
  u32 tow;

  /**
   * Heading [mdeg]
   */
  u32 heading;

  /**
   * Number of satellites used in solution
   */
  u8 n_sats;

  /**
   * Status flags
   */
  u8 flags;
} sbp_msg_baseline_heading_dep_a_t;

/**
 * Get encoded size of an instance of sbp_msg_baseline_heading_dep_a_t
 *
 * @param msg sbp_msg_baseline_heading_dep_a_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_msg_baseline_heading_dep_a_t(
    const sbp_msg_baseline_heading_dep_a_t *msg);

/**
 * Encode an instance of sbp_msg_baseline_heading_dep_a_t to wire representation
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
 * @param msg Instance of sbp_msg_baseline_heading_dep_a_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_msg_baseline_heading_dep_a_t(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_msg_baseline_heading_dep_a_t *msg);

/**
 * Decode an instance of sbp_msg_baseline_heading_dep_a_t from wire
 * representation
 *
 * This function decodes the wire representation of a
 * sbp_msg_baseline_heading_dep_a_t message to the given instance. The caller
 * must specify the length of the buffer in the \p len parameter. If non-null
 * the number of bytes read from the buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_msg_baseline_heading_dep_a_t
 * instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_msg_baseline_heading_dep_a_t(
    const uint8_t *buf, uint8_t len, uint8_t *n_read,
    sbp_msg_baseline_heading_dep_a_t *msg);
/**
 * Send an instance of sbp_msg_baseline_heading_dep_a_t with the given write
 * function
 *
 * An equivalent of #sbp_send_message which operates specifically on
 * sbp_msg_baseline_heading_dep_a_t
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
s8 sbp_send_sbp_msg_baseline_heading_dep_a_t(
    struct sbp_state *s, u16 sender_id,
    const sbp_msg_baseline_heading_dep_a_t *msg,
    s32 (*write)(u8 *buff, u32 n, void *context));

/**
 * Compare two instances of sbp_msg_baseline_heading_dep_a_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_baseline_heading_dep_a_t instance
 * @param b sbp_msg_baseline_heading_dep_a_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_msg_baseline_heading_dep_a_t(
    const sbp_msg_baseline_heading_dep_a_t *a,
    const sbp_msg_baseline_heading_dep_a_t *b);

/** Computed Position and Protection Level
 *
 * This message reports the local vertical and horizontal protection levels
 * associated with a given LLH position solution. The full GPS time is given by
 * the preceding MSG_GPS_TIME with the matching time-of-week (tow).
 */
typedef struct {
  /**
   * GPS Time of Week [ms]
   */
  u32 tow;

  /**
   * Vertical protection level [cm]
   */
  u16 vpl;

  /**
   * Horizontal protection level [cm]
   */
  u16 hpl;

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

  /**
   * Status flags
   */
  u8 flags;
} sbp_msg_protection_level_dep_a_t;

/**
 * Get encoded size of an instance of sbp_msg_protection_level_dep_a_t
 *
 * @param msg sbp_msg_protection_level_dep_a_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_msg_protection_level_dep_a_t(
    const sbp_msg_protection_level_dep_a_t *msg);

/**
 * Encode an instance of sbp_msg_protection_level_dep_a_t to wire representation
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
 * @param msg Instance of sbp_msg_protection_level_dep_a_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_msg_protection_level_dep_a_t(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_msg_protection_level_dep_a_t *msg);

/**
 * Decode an instance of sbp_msg_protection_level_dep_a_t from wire
 * representation
 *
 * This function decodes the wire representation of a
 * sbp_msg_protection_level_dep_a_t message to the given instance. The caller
 * must specify the length of the buffer in the \p len parameter. If non-null
 * the number of bytes read from the buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_msg_protection_level_dep_a_t
 * instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_msg_protection_level_dep_a_t(
    const uint8_t *buf, uint8_t len, uint8_t *n_read,
    sbp_msg_protection_level_dep_a_t *msg);
/**
 * Send an instance of sbp_msg_protection_level_dep_a_t with the given write
 * function
 *
 * An equivalent of #sbp_send_message which operates specifically on
 * sbp_msg_protection_level_dep_a_t
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
s8 sbp_send_sbp_msg_protection_level_dep_a_t(
    struct sbp_state *s, u16 sender_id,
    const sbp_msg_protection_level_dep_a_t *msg,
    s32 (*write)(u8 *buff, u32 n, void *context));

/**
 * Compare two instances of sbp_msg_protection_level_dep_a_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_protection_level_dep_a_t instance
 * @param b sbp_msg_protection_level_dep_a_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_msg_protection_level_dep_a_t(
    const sbp_msg_protection_level_dep_a_t *a,
    const sbp_msg_protection_level_dep_a_t *b);

/** Computed state and Protection Levels
 *
 * This message reports the protection levels associated to the given state
 * estimate. The full GPS time is given by the preceding MSG_GPS_TIME with the
 * matching time-of-week (tow).
 */
typedef struct {
  /**
   * GPS Time of Week [ms]
   */
  u32 tow;

  /**
   * GPS week number [weeks]
   */
  s16 wn;

  /**
   * Horizontal protection level [cm]
   */
  u16 hpl;

  /**
   * Vertical protection level [cm]
   */
  u16 vpl;

  /**
   * Along-track position error protection level [cm]
   */
  u16 atpl;

  /**
   * Cross-track position error protection level [cm]
   */
  u16 ctpl;

  /**
   * Protection level for the error vector between estimated and true
   * along/cross track velocity vector [mm/s]
   */
  u16 hvpl;

  /**
   * Protection level for the velocity in vehicle upright direction (different
   * from vertical direction if on a slope) [mm/s]
   */
  u16 vvpl;

  /**
   * Heading orientation protection level [mdeg]
   */
  u16 hopl;

  /**
   * Pitch orientation protection level [mdeg]
   */
  u16 popl;

  /**
   * Roll orientation protection level [mdeg]
   */
  u16 ropl;

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

  /**
   * Velocity in vehicle x direction [mm/s]
   */
  s32 v_x;

  /**
   * Velocity in vehicle y direction [mm/s]
   */
  s32 v_y;

  /**
   * Velocity in vehicle z direction [mm/s]
   */
  s32 v_z;

  /**
   * Roll angle [udeg]
   */
  s32 roll;

  /**
   * Pitch angle [udeg]
   */
  s32 pitch;

  /**
   * Heading angle [udeg]
   */
  s32 heading;

  /**
   * Status flags
   */
  u32 flags;
} sbp_msg_protection_level_t;

/**
 * Get encoded size of an instance of sbp_msg_protection_level_t
 *
 * @param msg sbp_msg_protection_level_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_msg_protection_level_t(
    const sbp_msg_protection_level_t *msg);

/**
 * Encode an instance of sbp_msg_protection_level_t to wire representation
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
 * @param msg Instance of sbp_msg_protection_level_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_msg_protection_level_t(uint8_t *buf, uint8_t len,
                                         uint8_t *n_written,
                                         const sbp_msg_protection_level_t *msg);

/**
 * Decode an instance of sbp_msg_protection_level_t from wire representation
 *
 * This function decodes the wire representation of a sbp_msg_protection_level_t
 * message to the given instance. The caller must specify the length of the
 * buffer in the \p len parameter. If non-null the number of bytes read from the
 * buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_msg_protection_level_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_msg_protection_level_t(const uint8_t *buf, uint8_t len,
                                         uint8_t *n_read,
                                         sbp_msg_protection_level_t *msg);
/**
 * Send an instance of sbp_msg_protection_level_t with the given write function
 *
 * An equivalent of #sbp_send_message which operates specifically on
 * sbp_msg_protection_level_t
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
s8 sbp_send_sbp_msg_protection_level_t(struct sbp_state *s, u16 sender_id,
                                       const sbp_msg_protection_level_t *msg,
                                       s32 (*write)(u8 *buff, u32 n,
                                                    void *context));

/**
 * Compare two instances of sbp_msg_protection_level_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_protection_level_t instance
 * @param b sbp_msg_protection_level_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_msg_protection_level_t(const sbp_msg_protection_level_t *a,
                                       const sbp_msg_protection_level_t *b);

#ifdef __cplusplus
}
static inline bool operator==(const sbp_msg_gps_time_t &lhs,
                              const sbp_msg_gps_time_t &rhs) {
  return sbp_cmp_sbp_msg_gps_time_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_msg_gps_time_t &lhs,
                              const sbp_msg_gps_time_t &rhs) {
  return sbp_cmp_sbp_msg_gps_time_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_gps_time_t &lhs,
                             const sbp_msg_gps_time_t &rhs) {
  return sbp_cmp_sbp_msg_gps_time_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_msg_gps_time_t &lhs,
                              const sbp_msg_gps_time_t &rhs) {
  return sbp_cmp_sbp_msg_gps_time_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_gps_time_t &lhs,
                             const sbp_msg_gps_time_t &rhs) {
  return sbp_cmp_sbp_msg_gps_time_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_msg_gps_time_t &lhs,
                              const sbp_msg_gps_time_t &rhs) {
  return sbp_cmp_sbp_msg_gps_time_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_msg_gps_time_gnss_t &lhs,
                              const sbp_msg_gps_time_gnss_t &rhs) {
  return sbp_cmp_sbp_msg_gps_time_gnss_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_msg_gps_time_gnss_t &lhs,
                              const sbp_msg_gps_time_gnss_t &rhs) {
  return sbp_cmp_sbp_msg_gps_time_gnss_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_gps_time_gnss_t &lhs,
                             const sbp_msg_gps_time_gnss_t &rhs) {
  return sbp_cmp_sbp_msg_gps_time_gnss_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_msg_gps_time_gnss_t &lhs,
                              const sbp_msg_gps_time_gnss_t &rhs) {
  return sbp_cmp_sbp_msg_gps_time_gnss_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_gps_time_gnss_t &lhs,
                             const sbp_msg_gps_time_gnss_t &rhs) {
  return sbp_cmp_sbp_msg_gps_time_gnss_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_msg_gps_time_gnss_t &lhs,
                              const sbp_msg_gps_time_gnss_t &rhs) {
  return sbp_cmp_sbp_msg_gps_time_gnss_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_msg_utc_time_t &lhs,
                              const sbp_msg_utc_time_t &rhs) {
  return sbp_cmp_sbp_msg_utc_time_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_msg_utc_time_t &lhs,
                              const sbp_msg_utc_time_t &rhs) {
  return sbp_cmp_sbp_msg_utc_time_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_utc_time_t &lhs,
                             const sbp_msg_utc_time_t &rhs) {
  return sbp_cmp_sbp_msg_utc_time_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_msg_utc_time_t &lhs,
                              const sbp_msg_utc_time_t &rhs) {
  return sbp_cmp_sbp_msg_utc_time_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_utc_time_t &lhs,
                             const sbp_msg_utc_time_t &rhs) {
  return sbp_cmp_sbp_msg_utc_time_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_msg_utc_time_t &lhs,
                              const sbp_msg_utc_time_t &rhs) {
  return sbp_cmp_sbp_msg_utc_time_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_msg_utc_time_gnss_t &lhs,
                              const sbp_msg_utc_time_gnss_t &rhs) {
  return sbp_cmp_sbp_msg_utc_time_gnss_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_msg_utc_time_gnss_t &lhs,
                              const sbp_msg_utc_time_gnss_t &rhs) {
  return sbp_cmp_sbp_msg_utc_time_gnss_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_utc_time_gnss_t &lhs,
                             const sbp_msg_utc_time_gnss_t &rhs) {
  return sbp_cmp_sbp_msg_utc_time_gnss_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_msg_utc_time_gnss_t &lhs,
                              const sbp_msg_utc_time_gnss_t &rhs) {
  return sbp_cmp_sbp_msg_utc_time_gnss_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_utc_time_gnss_t &lhs,
                             const sbp_msg_utc_time_gnss_t &rhs) {
  return sbp_cmp_sbp_msg_utc_time_gnss_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_msg_utc_time_gnss_t &lhs,
                              const sbp_msg_utc_time_gnss_t &rhs) {
  return sbp_cmp_sbp_msg_utc_time_gnss_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_msg_dops_t &lhs,
                              const sbp_msg_dops_t &rhs) {
  return sbp_cmp_sbp_msg_dops_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_msg_dops_t &lhs,
                              const sbp_msg_dops_t &rhs) {
  return sbp_cmp_sbp_msg_dops_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_dops_t &lhs,
                             const sbp_msg_dops_t &rhs) {
  return sbp_cmp_sbp_msg_dops_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_msg_dops_t &lhs,
                              const sbp_msg_dops_t &rhs) {
  return sbp_cmp_sbp_msg_dops_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_dops_t &lhs,
                             const sbp_msg_dops_t &rhs) {
  return sbp_cmp_sbp_msg_dops_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_msg_dops_t &lhs,
                              const sbp_msg_dops_t &rhs) {
  return sbp_cmp_sbp_msg_dops_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_msg_pos_ecef_t &lhs,
                              const sbp_msg_pos_ecef_t &rhs) {
  return sbp_cmp_sbp_msg_pos_ecef_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_msg_pos_ecef_t &lhs,
                              const sbp_msg_pos_ecef_t &rhs) {
  return sbp_cmp_sbp_msg_pos_ecef_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_pos_ecef_t &lhs,
                             const sbp_msg_pos_ecef_t &rhs) {
  return sbp_cmp_sbp_msg_pos_ecef_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_msg_pos_ecef_t &lhs,
                              const sbp_msg_pos_ecef_t &rhs) {
  return sbp_cmp_sbp_msg_pos_ecef_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_pos_ecef_t &lhs,
                             const sbp_msg_pos_ecef_t &rhs) {
  return sbp_cmp_sbp_msg_pos_ecef_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_msg_pos_ecef_t &lhs,
                              const sbp_msg_pos_ecef_t &rhs) {
  return sbp_cmp_sbp_msg_pos_ecef_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_msg_pos_ecef_cov_t &lhs,
                              const sbp_msg_pos_ecef_cov_t &rhs) {
  return sbp_cmp_sbp_msg_pos_ecef_cov_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_msg_pos_ecef_cov_t &lhs,
                              const sbp_msg_pos_ecef_cov_t &rhs) {
  return sbp_cmp_sbp_msg_pos_ecef_cov_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_pos_ecef_cov_t &lhs,
                             const sbp_msg_pos_ecef_cov_t &rhs) {
  return sbp_cmp_sbp_msg_pos_ecef_cov_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_msg_pos_ecef_cov_t &lhs,
                              const sbp_msg_pos_ecef_cov_t &rhs) {
  return sbp_cmp_sbp_msg_pos_ecef_cov_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_pos_ecef_cov_t &lhs,
                             const sbp_msg_pos_ecef_cov_t &rhs) {
  return sbp_cmp_sbp_msg_pos_ecef_cov_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_msg_pos_ecef_cov_t &lhs,
                              const sbp_msg_pos_ecef_cov_t &rhs) {
  return sbp_cmp_sbp_msg_pos_ecef_cov_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_msg_pos_llh_t &lhs,
                              const sbp_msg_pos_llh_t &rhs) {
  return sbp_cmp_sbp_msg_pos_llh_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_msg_pos_llh_t &lhs,
                              const sbp_msg_pos_llh_t &rhs) {
  return sbp_cmp_sbp_msg_pos_llh_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_pos_llh_t &lhs,
                             const sbp_msg_pos_llh_t &rhs) {
  return sbp_cmp_sbp_msg_pos_llh_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_msg_pos_llh_t &lhs,
                              const sbp_msg_pos_llh_t &rhs) {
  return sbp_cmp_sbp_msg_pos_llh_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_pos_llh_t &lhs,
                             const sbp_msg_pos_llh_t &rhs) {
  return sbp_cmp_sbp_msg_pos_llh_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_msg_pos_llh_t &lhs,
                              const sbp_msg_pos_llh_t &rhs) {
  return sbp_cmp_sbp_msg_pos_llh_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_msg_pos_llh_cov_t &lhs,
                              const sbp_msg_pos_llh_cov_t &rhs) {
  return sbp_cmp_sbp_msg_pos_llh_cov_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_msg_pos_llh_cov_t &lhs,
                              const sbp_msg_pos_llh_cov_t &rhs) {
  return sbp_cmp_sbp_msg_pos_llh_cov_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_pos_llh_cov_t &lhs,
                             const sbp_msg_pos_llh_cov_t &rhs) {
  return sbp_cmp_sbp_msg_pos_llh_cov_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_msg_pos_llh_cov_t &lhs,
                              const sbp_msg_pos_llh_cov_t &rhs) {
  return sbp_cmp_sbp_msg_pos_llh_cov_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_pos_llh_cov_t &lhs,
                             const sbp_msg_pos_llh_cov_t &rhs) {
  return sbp_cmp_sbp_msg_pos_llh_cov_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_msg_pos_llh_cov_t &lhs,
                              const sbp_msg_pos_llh_cov_t &rhs) {
  return sbp_cmp_sbp_msg_pos_llh_cov_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_msg_baseline_ecef_t &lhs,
                              const sbp_msg_baseline_ecef_t &rhs) {
  return sbp_cmp_sbp_msg_baseline_ecef_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_msg_baseline_ecef_t &lhs,
                              const sbp_msg_baseline_ecef_t &rhs) {
  return sbp_cmp_sbp_msg_baseline_ecef_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_baseline_ecef_t &lhs,
                             const sbp_msg_baseline_ecef_t &rhs) {
  return sbp_cmp_sbp_msg_baseline_ecef_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_msg_baseline_ecef_t &lhs,
                              const sbp_msg_baseline_ecef_t &rhs) {
  return sbp_cmp_sbp_msg_baseline_ecef_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_baseline_ecef_t &lhs,
                             const sbp_msg_baseline_ecef_t &rhs) {
  return sbp_cmp_sbp_msg_baseline_ecef_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_msg_baseline_ecef_t &lhs,
                              const sbp_msg_baseline_ecef_t &rhs) {
  return sbp_cmp_sbp_msg_baseline_ecef_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_msg_baseline_ned_t &lhs,
                              const sbp_msg_baseline_ned_t &rhs) {
  return sbp_cmp_sbp_msg_baseline_ned_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_msg_baseline_ned_t &lhs,
                              const sbp_msg_baseline_ned_t &rhs) {
  return sbp_cmp_sbp_msg_baseline_ned_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_baseline_ned_t &lhs,
                             const sbp_msg_baseline_ned_t &rhs) {
  return sbp_cmp_sbp_msg_baseline_ned_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_msg_baseline_ned_t &lhs,
                              const sbp_msg_baseline_ned_t &rhs) {
  return sbp_cmp_sbp_msg_baseline_ned_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_baseline_ned_t &lhs,
                             const sbp_msg_baseline_ned_t &rhs) {
  return sbp_cmp_sbp_msg_baseline_ned_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_msg_baseline_ned_t &lhs,
                              const sbp_msg_baseline_ned_t &rhs) {
  return sbp_cmp_sbp_msg_baseline_ned_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_msg_vel_ecef_t &lhs,
                              const sbp_msg_vel_ecef_t &rhs) {
  return sbp_cmp_sbp_msg_vel_ecef_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_msg_vel_ecef_t &lhs,
                              const sbp_msg_vel_ecef_t &rhs) {
  return sbp_cmp_sbp_msg_vel_ecef_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_vel_ecef_t &lhs,
                             const sbp_msg_vel_ecef_t &rhs) {
  return sbp_cmp_sbp_msg_vel_ecef_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_msg_vel_ecef_t &lhs,
                              const sbp_msg_vel_ecef_t &rhs) {
  return sbp_cmp_sbp_msg_vel_ecef_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_vel_ecef_t &lhs,
                             const sbp_msg_vel_ecef_t &rhs) {
  return sbp_cmp_sbp_msg_vel_ecef_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_msg_vel_ecef_t &lhs,
                              const sbp_msg_vel_ecef_t &rhs) {
  return sbp_cmp_sbp_msg_vel_ecef_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_msg_vel_ecef_cov_t &lhs,
                              const sbp_msg_vel_ecef_cov_t &rhs) {
  return sbp_cmp_sbp_msg_vel_ecef_cov_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_msg_vel_ecef_cov_t &lhs,
                              const sbp_msg_vel_ecef_cov_t &rhs) {
  return sbp_cmp_sbp_msg_vel_ecef_cov_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_vel_ecef_cov_t &lhs,
                             const sbp_msg_vel_ecef_cov_t &rhs) {
  return sbp_cmp_sbp_msg_vel_ecef_cov_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_msg_vel_ecef_cov_t &lhs,
                              const sbp_msg_vel_ecef_cov_t &rhs) {
  return sbp_cmp_sbp_msg_vel_ecef_cov_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_vel_ecef_cov_t &lhs,
                             const sbp_msg_vel_ecef_cov_t &rhs) {
  return sbp_cmp_sbp_msg_vel_ecef_cov_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_msg_vel_ecef_cov_t &lhs,
                              const sbp_msg_vel_ecef_cov_t &rhs) {
  return sbp_cmp_sbp_msg_vel_ecef_cov_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_msg_vel_ned_t &lhs,
                              const sbp_msg_vel_ned_t &rhs) {
  return sbp_cmp_sbp_msg_vel_ned_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_msg_vel_ned_t &lhs,
                              const sbp_msg_vel_ned_t &rhs) {
  return sbp_cmp_sbp_msg_vel_ned_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_vel_ned_t &lhs,
                             const sbp_msg_vel_ned_t &rhs) {
  return sbp_cmp_sbp_msg_vel_ned_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_msg_vel_ned_t &lhs,
                              const sbp_msg_vel_ned_t &rhs) {
  return sbp_cmp_sbp_msg_vel_ned_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_vel_ned_t &lhs,
                             const sbp_msg_vel_ned_t &rhs) {
  return sbp_cmp_sbp_msg_vel_ned_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_msg_vel_ned_t &lhs,
                              const sbp_msg_vel_ned_t &rhs) {
  return sbp_cmp_sbp_msg_vel_ned_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_msg_vel_ned_cov_t &lhs,
                              const sbp_msg_vel_ned_cov_t &rhs) {
  return sbp_cmp_sbp_msg_vel_ned_cov_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_msg_vel_ned_cov_t &lhs,
                              const sbp_msg_vel_ned_cov_t &rhs) {
  return sbp_cmp_sbp_msg_vel_ned_cov_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_vel_ned_cov_t &lhs,
                             const sbp_msg_vel_ned_cov_t &rhs) {
  return sbp_cmp_sbp_msg_vel_ned_cov_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_msg_vel_ned_cov_t &lhs,
                              const sbp_msg_vel_ned_cov_t &rhs) {
  return sbp_cmp_sbp_msg_vel_ned_cov_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_vel_ned_cov_t &lhs,
                             const sbp_msg_vel_ned_cov_t &rhs) {
  return sbp_cmp_sbp_msg_vel_ned_cov_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_msg_vel_ned_cov_t &lhs,
                              const sbp_msg_vel_ned_cov_t &rhs) {
  return sbp_cmp_sbp_msg_vel_ned_cov_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_msg_pos_ecef_gnss_t &lhs,
                              const sbp_msg_pos_ecef_gnss_t &rhs) {
  return sbp_cmp_sbp_msg_pos_ecef_gnss_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_msg_pos_ecef_gnss_t &lhs,
                              const sbp_msg_pos_ecef_gnss_t &rhs) {
  return sbp_cmp_sbp_msg_pos_ecef_gnss_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_pos_ecef_gnss_t &lhs,
                             const sbp_msg_pos_ecef_gnss_t &rhs) {
  return sbp_cmp_sbp_msg_pos_ecef_gnss_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_msg_pos_ecef_gnss_t &lhs,
                              const sbp_msg_pos_ecef_gnss_t &rhs) {
  return sbp_cmp_sbp_msg_pos_ecef_gnss_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_pos_ecef_gnss_t &lhs,
                             const sbp_msg_pos_ecef_gnss_t &rhs) {
  return sbp_cmp_sbp_msg_pos_ecef_gnss_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_msg_pos_ecef_gnss_t &lhs,
                              const sbp_msg_pos_ecef_gnss_t &rhs) {
  return sbp_cmp_sbp_msg_pos_ecef_gnss_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_msg_pos_ecef_cov_gnss_t &lhs,
                              const sbp_msg_pos_ecef_cov_gnss_t &rhs) {
  return sbp_cmp_sbp_msg_pos_ecef_cov_gnss_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_msg_pos_ecef_cov_gnss_t &lhs,
                              const sbp_msg_pos_ecef_cov_gnss_t &rhs) {
  return sbp_cmp_sbp_msg_pos_ecef_cov_gnss_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_pos_ecef_cov_gnss_t &lhs,
                             const sbp_msg_pos_ecef_cov_gnss_t &rhs) {
  return sbp_cmp_sbp_msg_pos_ecef_cov_gnss_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_msg_pos_ecef_cov_gnss_t &lhs,
                              const sbp_msg_pos_ecef_cov_gnss_t &rhs) {
  return sbp_cmp_sbp_msg_pos_ecef_cov_gnss_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_pos_ecef_cov_gnss_t &lhs,
                             const sbp_msg_pos_ecef_cov_gnss_t &rhs) {
  return sbp_cmp_sbp_msg_pos_ecef_cov_gnss_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_msg_pos_ecef_cov_gnss_t &lhs,
                              const sbp_msg_pos_ecef_cov_gnss_t &rhs) {
  return sbp_cmp_sbp_msg_pos_ecef_cov_gnss_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_msg_pos_llh_gnss_t &lhs,
                              const sbp_msg_pos_llh_gnss_t &rhs) {
  return sbp_cmp_sbp_msg_pos_llh_gnss_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_msg_pos_llh_gnss_t &lhs,
                              const sbp_msg_pos_llh_gnss_t &rhs) {
  return sbp_cmp_sbp_msg_pos_llh_gnss_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_pos_llh_gnss_t &lhs,
                             const sbp_msg_pos_llh_gnss_t &rhs) {
  return sbp_cmp_sbp_msg_pos_llh_gnss_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_msg_pos_llh_gnss_t &lhs,
                              const sbp_msg_pos_llh_gnss_t &rhs) {
  return sbp_cmp_sbp_msg_pos_llh_gnss_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_pos_llh_gnss_t &lhs,
                             const sbp_msg_pos_llh_gnss_t &rhs) {
  return sbp_cmp_sbp_msg_pos_llh_gnss_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_msg_pos_llh_gnss_t &lhs,
                              const sbp_msg_pos_llh_gnss_t &rhs) {
  return sbp_cmp_sbp_msg_pos_llh_gnss_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_msg_pos_llh_cov_gnss_t &lhs,
                              const sbp_msg_pos_llh_cov_gnss_t &rhs) {
  return sbp_cmp_sbp_msg_pos_llh_cov_gnss_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_msg_pos_llh_cov_gnss_t &lhs,
                              const sbp_msg_pos_llh_cov_gnss_t &rhs) {
  return sbp_cmp_sbp_msg_pos_llh_cov_gnss_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_pos_llh_cov_gnss_t &lhs,
                             const sbp_msg_pos_llh_cov_gnss_t &rhs) {
  return sbp_cmp_sbp_msg_pos_llh_cov_gnss_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_msg_pos_llh_cov_gnss_t &lhs,
                              const sbp_msg_pos_llh_cov_gnss_t &rhs) {
  return sbp_cmp_sbp_msg_pos_llh_cov_gnss_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_pos_llh_cov_gnss_t &lhs,
                             const sbp_msg_pos_llh_cov_gnss_t &rhs) {
  return sbp_cmp_sbp_msg_pos_llh_cov_gnss_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_msg_pos_llh_cov_gnss_t &lhs,
                              const sbp_msg_pos_llh_cov_gnss_t &rhs) {
  return sbp_cmp_sbp_msg_pos_llh_cov_gnss_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_msg_vel_ecef_gnss_t &lhs,
                              const sbp_msg_vel_ecef_gnss_t &rhs) {
  return sbp_cmp_sbp_msg_vel_ecef_gnss_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_msg_vel_ecef_gnss_t &lhs,
                              const sbp_msg_vel_ecef_gnss_t &rhs) {
  return sbp_cmp_sbp_msg_vel_ecef_gnss_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_vel_ecef_gnss_t &lhs,
                             const sbp_msg_vel_ecef_gnss_t &rhs) {
  return sbp_cmp_sbp_msg_vel_ecef_gnss_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_msg_vel_ecef_gnss_t &lhs,
                              const sbp_msg_vel_ecef_gnss_t &rhs) {
  return sbp_cmp_sbp_msg_vel_ecef_gnss_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_vel_ecef_gnss_t &lhs,
                             const sbp_msg_vel_ecef_gnss_t &rhs) {
  return sbp_cmp_sbp_msg_vel_ecef_gnss_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_msg_vel_ecef_gnss_t &lhs,
                              const sbp_msg_vel_ecef_gnss_t &rhs) {
  return sbp_cmp_sbp_msg_vel_ecef_gnss_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_msg_vel_ecef_cov_gnss_t &lhs,
                              const sbp_msg_vel_ecef_cov_gnss_t &rhs) {
  return sbp_cmp_sbp_msg_vel_ecef_cov_gnss_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_msg_vel_ecef_cov_gnss_t &lhs,
                              const sbp_msg_vel_ecef_cov_gnss_t &rhs) {
  return sbp_cmp_sbp_msg_vel_ecef_cov_gnss_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_vel_ecef_cov_gnss_t &lhs,
                             const sbp_msg_vel_ecef_cov_gnss_t &rhs) {
  return sbp_cmp_sbp_msg_vel_ecef_cov_gnss_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_msg_vel_ecef_cov_gnss_t &lhs,
                              const sbp_msg_vel_ecef_cov_gnss_t &rhs) {
  return sbp_cmp_sbp_msg_vel_ecef_cov_gnss_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_vel_ecef_cov_gnss_t &lhs,
                             const sbp_msg_vel_ecef_cov_gnss_t &rhs) {
  return sbp_cmp_sbp_msg_vel_ecef_cov_gnss_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_msg_vel_ecef_cov_gnss_t &lhs,
                              const sbp_msg_vel_ecef_cov_gnss_t &rhs) {
  return sbp_cmp_sbp_msg_vel_ecef_cov_gnss_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_msg_vel_ned_gnss_t &lhs,
                              const sbp_msg_vel_ned_gnss_t &rhs) {
  return sbp_cmp_sbp_msg_vel_ned_gnss_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_msg_vel_ned_gnss_t &lhs,
                              const sbp_msg_vel_ned_gnss_t &rhs) {
  return sbp_cmp_sbp_msg_vel_ned_gnss_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_vel_ned_gnss_t &lhs,
                             const sbp_msg_vel_ned_gnss_t &rhs) {
  return sbp_cmp_sbp_msg_vel_ned_gnss_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_msg_vel_ned_gnss_t &lhs,
                              const sbp_msg_vel_ned_gnss_t &rhs) {
  return sbp_cmp_sbp_msg_vel_ned_gnss_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_vel_ned_gnss_t &lhs,
                             const sbp_msg_vel_ned_gnss_t &rhs) {
  return sbp_cmp_sbp_msg_vel_ned_gnss_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_msg_vel_ned_gnss_t &lhs,
                              const sbp_msg_vel_ned_gnss_t &rhs) {
  return sbp_cmp_sbp_msg_vel_ned_gnss_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_msg_vel_ned_cov_gnss_t &lhs,
                              const sbp_msg_vel_ned_cov_gnss_t &rhs) {
  return sbp_cmp_sbp_msg_vel_ned_cov_gnss_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_msg_vel_ned_cov_gnss_t &lhs,
                              const sbp_msg_vel_ned_cov_gnss_t &rhs) {
  return sbp_cmp_sbp_msg_vel_ned_cov_gnss_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_vel_ned_cov_gnss_t &lhs,
                             const sbp_msg_vel_ned_cov_gnss_t &rhs) {
  return sbp_cmp_sbp_msg_vel_ned_cov_gnss_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_msg_vel_ned_cov_gnss_t &lhs,
                              const sbp_msg_vel_ned_cov_gnss_t &rhs) {
  return sbp_cmp_sbp_msg_vel_ned_cov_gnss_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_vel_ned_cov_gnss_t &lhs,
                             const sbp_msg_vel_ned_cov_gnss_t &rhs) {
  return sbp_cmp_sbp_msg_vel_ned_cov_gnss_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_msg_vel_ned_cov_gnss_t &lhs,
                              const sbp_msg_vel_ned_cov_gnss_t &rhs) {
  return sbp_cmp_sbp_msg_vel_ned_cov_gnss_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_msg_vel_body_t &lhs,
                              const sbp_msg_vel_body_t &rhs) {
  return sbp_cmp_sbp_msg_vel_body_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_msg_vel_body_t &lhs,
                              const sbp_msg_vel_body_t &rhs) {
  return sbp_cmp_sbp_msg_vel_body_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_vel_body_t &lhs,
                             const sbp_msg_vel_body_t &rhs) {
  return sbp_cmp_sbp_msg_vel_body_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_msg_vel_body_t &lhs,
                              const sbp_msg_vel_body_t &rhs) {
  return sbp_cmp_sbp_msg_vel_body_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_vel_body_t &lhs,
                             const sbp_msg_vel_body_t &rhs) {
  return sbp_cmp_sbp_msg_vel_body_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_msg_vel_body_t &lhs,
                              const sbp_msg_vel_body_t &rhs) {
  return sbp_cmp_sbp_msg_vel_body_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_msg_age_corrections_t &lhs,
                              const sbp_msg_age_corrections_t &rhs) {
  return sbp_cmp_sbp_msg_age_corrections_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_msg_age_corrections_t &lhs,
                              const sbp_msg_age_corrections_t &rhs) {
  return sbp_cmp_sbp_msg_age_corrections_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_age_corrections_t &lhs,
                             const sbp_msg_age_corrections_t &rhs) {
  return sbp_cmp_sbp_msg_age_corrections_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_msg_age_corrections_t &lhs,
                              const sbp_msg_age_corrections_t &rhs) {
  return sbp_cmp_sbp_msg_age_corrections_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_age_corrections_t &lhs,
                             const sbp_msg_age_corrections_t &rhs) {
  return sbp_cmp_sbp_msg_age_corrections_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_msg_age_corrections_t &lhs,
                              const sbp_msg_age_corrections_t &rhs) {
  return sbp_cmp_sbp_msg_age_corrections_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_msg_gps_time_dep_a_t &lhs,
                              const sbp_msg_gps_time_dep_a_t &rhs) {
  return sbp_cmp_sbp_msg_gps_time_dep_a_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_msg_gps_time_dep_a_t &lhs,
                              const sbp_msg_gps_time_dep_a_t &rhs) {
  return sbp_cmp_sbp_msg_gps_time_dep_a_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_gps_time_dep_a_t &lhs,
                             const sbp_msg_gps_time_dep_a_t &rhs) {
  return sbp_cmp_sbp_msg_gps_time_dep_a_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_msg_gps_time_dep_a_t &lhs,
                              const sbp_msg_gps_time_dep_a_t &rhs) {
  return sbp_cmp_sbp_msg_gps_time_dep_a_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_gps_time_dep_a_t &lhs,
                             const sbp_msg_gps_time_dep_a_t &rhs) {
  return sbp_cmp_sbp_msg_gps_time_dep_a_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_msg_gps_time_dep_a_t &lhs,
                              const sbp_msg_gps_time_dep_a_t &rhs) {
  return sbp_cmp_sbp_msg_gps_time_dep_a_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_msg_dops_dep_a_t &lhs,
                              const sbp_msg_dops_dep_a_t &rhs) {
  return sbp_cmp_sbp_msg_dops_dep_a_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_msg_dops_dep_a_t &lhs,
                              const sbp_msg_dops_dep_a_t &rhs) {
  return sbp_cmp_sbp_msg_dops_dep_a_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_dops_dep_a_t &lhs,
                             const sbp_msg_dops_dep_a_t &rhs) {
  return sbp_cmp_sbp_msg_dops_dep_a_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_msg_dops_dep_a_t &lhs,
                              const sbp_msg_dops_dep_a_t &rhs) {
  return sbp_cmp_sbp_msg_dops_dep_a_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_dops_dep_a_t &lhs,
                             const sbp_msg_dops_dep_a_t &rhs) {
  return sbp_cmp_sbp_msg_dops_dep_a_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_msg_dops_dep_a_t &lhs,
                              const sbp_msg_dops_dep_a_t &rhs) {
  return sbp_cmp_sbp_msg_dops_dep_a_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_msg_pos_ecef_dep_a_t &lhs,
                              const sbp_msg_pos_ecef_dep_a_t &rhs) {
  return sbp_cmp_sbp_msg_pos_ecef_dep_a_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_msg_pos_ecef_dep_a_t &lhs,
                              const sbp_msg_pos_ecef_dep_a_t &rhs) {
  return sbp_cmp_sbp_msg_pos_ecef_dep_a_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_pos_ecef_dep_a_t &lhs,
                             const sbp_msg_pos_ecef_dep_a_t &rhs) {
  return sbp_cmp_sbp_msg_pos_ecef_dep_a_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_msg_pos_ecef_dep_a_t &lhs,
                              const sbp_msg_pos_ecef_dep_a_t &rhs) {
  return sbp_cmp_sbp_msg_pos_ecef_dep_a_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_pos_ecef_dep_a_t &lhs,
                             const sbp_msg_pos_ecef_dep_a_t &rhs) {
  return sbp_cmp_sbp_msg_pos_ecef_dep_a_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_msg_pos_ecef_dep_a_t &lhs,
                              const sbp_msg_pos_ecef_dep_a_t &rhs) {
  return sbp_cmp_sbp_msg_pos_ecef_dep_a_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_msg_pos_llh_dep_a_t &lhs,
                              const sbp_msg_pos_llh_dep_a_t &rhs) {
  return sbp_cmp_sbp_msg_pos_llh_dep_a_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_msg_pos_llh_dep_a_t &lhs,
                              const sbp_msg_pos_llh_dep_a_t &rhs) {
  return sbp_cmp_sbp_msg_pos_llh_dep_a_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_pos_llh_dep_a_t &lhs,
                             const sbp_msg_pos_llh_dep_a_t &rhs) {
  return sbp_cmp_sbp_msg_pos_llh_dep_a_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_msg_pos_llh_dep_a_t &lhs,
                              const sbp_msg_pos_llh_dep_a_t &rhs) {
  return sbp_cmp_sbp_msg_pos_llh_dep_a_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_pos_llh_dep_a_t &lhs,
                             const sbp_msg_pos_llh_dep_a_t &rhs) {
  return sbp_cmp_sbp_msg_pos_llh_dep_a_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_msg_pos_llh_dep_a_t &lhs,
                              const sbp_msg_pos_llh_dep_a_t &rhs) {
  return sbp_cmp_sbp_msg_pos_llh_dep_a_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_msg_baseline_ecef_dep_a_t &lhs,
                              const sbp_msg_baseline_ecef_dep_a_t &rhs) {
  return sbp_cmp_sbp_msg_baseline_ecef_dep_a_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_msg_baseline_ecef_dep_a_t &lhs,
                              const sbp_msg_baseline_ecef_dep_a_t &rhs) {
  return sbp_cmp_sbp_msg_baseline_ecef_dep_a_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_baseline_ecef_dep_a_t &lhs,
                             const sbp_msg_baseline_ecef_dep_a_t &rhs) {
  return sbp_cmp_sbp_msg_baseline_ecef_dep_a_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_msg_baseline_ecef_dep_a_t &lhs,
                              const sbp_msg_baseline_ecef_dep_a_t &rhs) {
  return sbp_cmp_sbp_msg_baseline_ecef_dep_a_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_baseline_ecef_dep_a_t &lhs,
                             const sbp_msg_baseline_ecef_dep_a_t &rhs) {
  return sbp_cmp_sbp_msg_baseline_ecef_dep_a_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_msg_baseline_ecef_dep_a_t &lhs,
                              const sbp_msg_baseline_ecef_dep_a_t &rhs) {
  return sbp_cmp_sbp_msg_baseline_ecef_dep_a_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_msg_baseline_ned_dep_a_t &lhs,
                              const sbp_msg_baseline_ned_dep_a_t &rhs) {
  return sbp_cmp_sbp_msg_baseline_ned_dep_a_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_msg_baseline_ned_dep_a_t &lhs,
                              const sbp_msg_baseline_ned_dep_a_t &rhs) {
  return sbp_cmp_sbp_msg_baseline_ned_dep_a_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_baseline_ned_dep_a_t &lhs,
                             const sbp_msg_baseline_ned_dep_a_t &rhs) {
  return sbp_cmp_sbp_msg_baseline_ned_dep_a_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_msg_baseline_ned_dep_a_t &lhs,
                              const sbp_msg_baseline_ned_dep_a_t &rhs) {
  return sbp_cmp_sbp_msg_baseline_ned_dep_a_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_baseline_ned_dep_a_t &lhs,
                             const sbp_msg_baseline_ned_dep_a_t &rhs) {
  return sbp_cmp_sbp_msg_baseline_ned_dep_a_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_msg_baseline_ned_dep_a_t &lhs,
                              const sbp_msg_baseline_ned_dep_a_t &rhs) {
  return sbp_cmp_sbp_msg_baseline_ned_dep_a_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_msg_vel_ecef_dep_a_t &lhs,
                              const sbp_msg_vel_ecef_dep_a_t &rhs) {
  return sbp_cmp_sbp_msg_vel_ecef_dep_a_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_msg_vel_ecef_dep_a_t &lhs,
                              const sbp_msg_vel_ecef_dep_a_t &rhs) {
  return sbp_cmp_sbp_msg_vel_ecef_dep_a_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_vel_ecef_dep_a_t &lhs,
                             const sbp_msg_vel_ecef_dep_a_t &rhs) {
  return sbp_cmp_sbp_msg_vel_ecef_dep_a_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_msg_vel_ecef_dep_a_t &lhs,
                              const sbp_msg_vel_ecef_dep_a_t &rhs) {
  return sbp_cmp_sbp_msg_vel_ecef_dep_a_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_vel_ecef_dep_a_t &lhs,
                             const sbp_msg_vel_ecef_dep_a_t &rhs) {
  return sbp_cmp_sbp_msg_vel_ecef_dep_a_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_msg_vel_ecef_dep_a_t &lhs,
                              const sbp_msg_vel_ecef_dep_a_t &rhs) {
  return sbp_cmp_sbp_msg_vel_ecef_dep_a_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_msg_vel_ned_dep_a_t &lhs,
                              const sbp_msg_vel_ned_dep_a_t &rhs) {
  return sbp_cmp_sbp_msg_vel_ned_dep_a_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_msg_vel_ned_dep_a_t &lhs,
                              const sbp_msg_vel_ned_dep_a_t &rhs) {
  return sbp_cmp_sbp_msg_vel_ned_dep_a_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_vel_ned_dep_a_t &lhs,
                             const sbp_msg_vel_ned_dep_a_t &rhs) {
  return sbp_cmp_sbp_msg_vel_ned_dep_a_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_msg_vel_ned_dep_a_t &lhs,
                              const sbp_msg_vel_ned_dep_a_t &rhs) {
  return sbp_cmp_sbp_msg_vel_ned_dep_a_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_vel_ned_dep_a_t &lhs,
                             const sbp_msg_vel_ned_dep_a_t &rhs) {
  return sbp_cmp_sbp_msg_vel_ned_dep_a_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_msg_vel_ned_dep_a_t &lhs,
                              const sbp_msg_vel_ned_dep_a_t &rhs) {
  return sbp_cmp_sbp_msg_vel_ned_dep_a_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_msg_baseline_heading_dep_a_t &lhs,
                              const sbp_msg_baseline_heading_dep_a_t &rhs) {
  return sbp_cmp_sbp_msg_baseline_heading_dep_a_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_msg_baseline_heading_dep_a_t &lhs,
                              const sbp_msg_baseline_heading_dep_a_t &rhs) {
  return sbp_cmp_sbp_msg_baseline_heading_dep_a_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_baseline_heading_dep_a_t &lhs,
                             const sbp_msg_baseline_heading_dep_a_t &rhs) {
  return sbp_cmp_sbp_msg_baseline_heading_dep_a_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_msg_baseline_heading_dep_a_t &lhs,
                              const sbp_msg_baseline_heading_dep_a_t &rhs) {
  return sbp_cmp_sbp_msg_baseline_heading_dep_a_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_baseline_heading_dep_a_t &lhs,
                             const sbp_msg_baseline_heading_dep_a_t &rhs) {
  return sbp_cmp_sbp_msg_baseline_heading_dep_a_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_msg_baseline_heading_dep_a_t &lhs,
                              const sbp_msg_baseline_heading_dep_a_t &rhs) {
  return sbp_cmp_sbp_msg_baseline_heading_dep_a_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_msg_protection_level_dep_a_t &lhs,
                              const sbp_msg_protection_level_dep_a_t &rhs) {
  return sbp_cmp_sbp_msg_protection_level_dep_a_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_msg_protection_level_dep_a_t &lhs,
                              const sbp_msg_protection_level_dep_a_t &rhs) {
  return sbp_cmp_sbp_msg_protection_level_dep_a_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_protection_level_dep_a_t &lhs,
                             const sbp_msg_protection_level_dep_a_t &rhs) {
  return sbp_cmp_sbp_msg_protection_level_dep_a_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_msg_protection_level_dep_a_t &lhs,
                              const sbp_msg_protection_level_dep_a_t &rhs) {
  return sbp_cmp_sbp_msg_protection_level_dep_a_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_protection_level_dep_a_t &lhs,
                             const sbp_msg_protection_level_dep_a_t &rhs) {
  return sbp_cmp_sbp_msg_protection_level_dep_a_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_msg_protection_level_dep_a_t &lhs,
                              const sbp_msg_protection_level_dep_a_t &rhs) {
  return sbp_cmp_sbp_msg_protection_level_dep_a_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_msg_protection_level_t &lhs,
                              const sbp_msg_protection_level_t &rhs) {
  return sbp_cmp_sbp_msg_protection_level_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_msg_protection_level_t &lhs,
                              const sbp_msg_protection_level_t &rhs) {
  return sbp_cmp_sbp_msg_protection_level_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_protection_level_t &lhs,
                             const sbp_msg_protection_level_t &rhs) {
  return sbp_cmp_sbp_msg_protection_level_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_msg_protection_level_t &lhs,
                              const sbp_msg_protection_level_t &rhs) {
  return sbp_cmp_sbp_msg_protection_level_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_protection_level_t &lhs,
                             const sbp_msg_protection_level_t &rhs) {
  return sbp_cmp_sbp_msg_protection_level_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_msg_protection_level_t &lhs,
                              const sbp_msg_protection_level_t &rhs) {
  return sbp_cmp_sbp_msg_protection_level_t(&lhs, &rhs) >= 0;
}

#endif

#endif /* LIBSBP_NEW_NAVIGATION_MESSAGES_H */
