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
 * Automatically generated from yaml/swiftnav/sbp/orientation.yaml
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

#ifndef LIBSBP_NEW_ORIENTATION_MESSAGES_H
#define LIBSBP_NEW_ORIENTATION_MESSAGES_H

#include <endian.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>

#include <libsbp/common.h>
#include <libsbp/new/string/double_null_terminated.h>
#include <libsbp/new/string/multipart.h>
#include <libsbp/new/string/null_terminated.h>
#include <libsbp/new/string/unterminated.h>
#include <libsbp/orientation_macros.h>

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
 * SBP_MSG_BASELINE_HEADING
 *
 *****************************************************************************/
/** Heading relative to True North
 *
 * This message reports the baseline heading pointing from the base station to
 * the rover relative to True North. The full GPS time is given by the preceding
 * MSG_GPS_TIME with the matching time-of-week (tow). It is intended that
 * time-matched RTK mode is used when the base station is moving.
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
} sbp_msg_baseline_heading_t;

/**
 * Get encoded size of an instance of sbp_msg_baseline_heading_t
 *
 * @param msg sbp_msg_baseline_heading_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_msg_baseline_heading_t(
    const sbp_msg_baseline_heading_t *msg);

/**
 * Encode an instance of sbp_msg_baseline_heading_t to wire representation
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
 * @param msg Instance of sbp_msg_baseline_heading_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_msg_baseline_heading_t(uint8_t *buf, uint8_t len,
                                         uint8_t *n_written,
                                         const sbp_msg_baseline_heading_t *msg);

/**
 * Decode an instance of sbp_msg_baseline_heading_t from wire representation
 *
 * This function decodes the wire representation of a sbp_msg_baseline_heading_t
 * message to the given instance. The caller must specify the length of the
 * buffer in the \p len parameter. If non-null the number of bytes read from the
 * buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_msg_baseline_heading_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_msg_baseline_heading_t(const uint8_t *buf, uint8_t len,
                                         uint8_t *n_read,
                                         sbp_msg_baseline_heading_t *msg);
/**
 * Send an instance of sbp_msg_baseline_heading_t with the given write function
 *
 * An equivalent of #sbp_send_message which operates specifically on
 * sbp_msg_baseline_heading_t
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
s8 sbp_send_sbp_msg_baseline_heading_t(struct sbp_state *s, u16 sender_id,
                                       const sbp_msg_baseline_heading_t *msg,
                                       s32 (*write)(u8 *buff, u32 n,
                                                    void *context));

/**
 * Compare two instances of sbp_msg_baseline_heading_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_baseline_heading_t instance
 * @param b sbp_msg_baseline_heading_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_msg_baseline_heading_t(const sbp_msg_baseline_heading_t *a,
                                       const sbp_msg_baseline_heading_t *b);

/*
 *
 *
 *
 ******************************************************************************
 *
 * SBP_MSG_ORIENT_QUAT
 *
 *****************************************************************************/
/** Quaternion 4 component vector
 *
 * This message reports the quaternion vector describing the vehicle body
 * frame's orientation with respect to a local-level NED frame. The components
 * of the vector should sum to a unit vector assuming that the LSB of each
 * component as a value of 2^-31. This message will only be available in future
 * INS versions of Swift Products and is not produced by Piksi Multi or Duro.
 */
typedef struct {
  /**
   * GPS Time of Week [ms]
   */
  u32 tow;

  /**
   * Real component [2^-31]
   */
  s32 w;

  /**
   * 1st imaginary component [2^-31]
   */
  s32 x;

  /**
   * 2nd imaginary component [2^-31]
   */
  s32 y;

  /**
   * 3rd imaginary component [2^-31]
   */
  s32 z;

  /**
   * Estimated standard deviation of w [N/A]
   */
  float w_accuracy;

  /**
   * Estimated standard deviation of x [N/A]
   */
  float x_accuracy;

  /**
   * Estimated standard deviation of y [N/A]
   */
  float y_accuracy;

  /**
   * Estimated standard deviation of z [N/A]
   */
  float z_accuracy;

  /**
   * Status flags
   */
  u8 flags;
} sbp_msg_orient_quat_t;

/**
 * Get encoded size of an instance of sbp_msg_orient_quat_t
 *
 * @param msg sbp_msg_orient_quat_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_msg_orient_quat_t(const sbp_msg_orient_quat_t *msg);

/**
 * Encode an instance of sbp_msg_orient_quat_t to wire representation
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
 * @param msg Instance of sbp_msg_orient_quat_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_msg_orient_quat_t(uint8_t *buf, uint8_t len,
                                    uint8_t *n_written,
                                    const sbp_msg_orient_quat_t *msg);

/**
 * Decode an instance of sbp_msg_orient_quat_t from wire representation
 *
 * This function decodes the wire representation of a sbp_msg_orient_quat_t
 * message to the given instance. The caller must specify the length of the
 * buffer in the \p len parameter. If non-null the number of bytes read from the
 * buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_msg_orient_quat_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_msg_orient_quat_t(const uint8_t *buf, uint8_t len,
                                    uint8_t *n_read,
                                    sbp_msg_orient_quat_t *msg);
/**
 * Send an instance of sbp_msg_orient_quat_t with the given write function
 *
 * An equivalent of #sbp_send_message which operates specifically on
 * sbp_msg_orient_quat_t
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
s8 sbp_send_sbp_msg_orient_quat_t(struct sbp_state *s, u16 sender_id,
                                  const sbp_msg_orient_quat_t *msg,
                                  s32 (*write)(u8 *buff, u32 n, void *context));

/**
 * Compare two instances of sbp_msg_orient_quat_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_orient_quat_t instance
 * @param b sbp_msg_orient_quat_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_msg_orient_quat_t(const sbp_msg_orient_quat_t *a,
                                  const sbp_msg_orient_quat_t *b);

/*
 *
 *
 *
 ******************************************************************************
 *
 * SBP_MSG_ORIENT_EULER
 *
 *****************************************************************************/
/** Euler angles
 *
 * This message reports the yaw, pitch, and roll angles of the vehicle body
 * frame. The rotations should applied intrinsically in the order yaw, pitch,
 * and roll in order to rotate the from a frame aligned with the local-level NED
 * frame to the vehicle body frame.  This message will only be available in
 * future INS versions of Swift Products and is not produced by Piksi Multi or
 * Duro.
 */
typedef struct {
  /**
   * GPS Time of Week [ms]
   */
  u32 tow;

  /**
   * rotation about the forward axis of the vehicle [microdegrees]
   */
  s32 roll;

  /**
   * rotation about the rightward axis of the vehicle [microdegrees]
   */
  s32 pitch;

  /**
   * rotation about the downward axis of the vehicle [microdegrees]
   */
  s32 yaw;

  /**
   * Estimated standard deviation of roll [degrees]
   */
  float roll_accuracy;

  /**
   * Estimated standard deviation of pitch [degrees]
   */
  float pitch_accuracy;

  /**
   * Estimated standard deviation of yaw [degrees]
   */
  float yaw_accuracy;

  /**
   * Status flags
   */
  u8 flags;
} sbp_msg_orient_euler_t;

/**
 * Get encoded size of an instance of sbp_msg_orient_euler_t
 *
 * @param msg sbp_msg_orient_euler_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_msg_orient_euler_t(
    const sbp_msg_orient_euler_t *msg);

/**
 * Encode an instance of sbp_msg_orient_euler_t to wire representation
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
 * @param msg Instance of sbp_msg_orient_euler_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_msg_orient_euler_t(uint8_t *buf, uint8_t len,
                                     uint8_t *n_written,
                                     const sbp_msg_orient_euler_t *msg);

/**
 * Decode an instance of sbp_msg_orient_euler_t from wire representation
 *
 * This function decodes the wire representation of a sbp_msg_orient_euler_t
 * message to the given instance. The caller must specify the length of the
 * buffer in the \p len parameter. If non-null the number of bytes read from the
 * buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_msg_orient_euler_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_msg_orient_euler_t(const uint8_t *buf, uint8_t len,
                                     uint8_t *n_read,
                                     sbp_msg_orient_euler_t *msg);
/**
 * Send an instance of sbp_msg_orient_euler_t with the given write function
 *
 * An equivalent of #sbp_send_message which operates specifically on
 * sbp_msg_orient_euler_t
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
s8 sbp_send_sbp_msg_orient_euler_t(struct sbp_state *s, u16 sender_id,
                                   const sbp_msg_orient_euler_t *msg,
                                   s32 (*write)(u8 *buff, u32 n,
                                                void *context));

/**
 * Compare two instances of sbp_msg_orient_euler_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_orient_euler_t instance
 * @param b sbp_msg_orient_euler_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_msg_orient_euler_t(const sbp_msg_orient_euler_t *a,
                                   const sbp_msg_orient_euler_t *b);

/*
 *
 *
 *
 ******************************************************************************
 *
 * SBP_MSG_ANGULAR_RATE
 *
 *****************************************************************************/
/** Vehicle Body Frame instantaneous angular rates
 *
 * This message reports the orientation rates in the vehicle body frame. The
 * values represent the measurements a strapped down gyroscope would make and
 * are not equivalent to the time derivative of the Euler angles. The
 * orientation and origin of the user frame is specified via device settings. By
 * convention, the vehicle x-axis is expected to be aligned with the forward
 * direction, while the vehicle y-axis is expected to be aligned with the right
 * direction, and the vehicle z-axis should be aligned with the down direction.
 * This message will only be available in future INS versions of Swift Products
 * and is not produced by Piksi Multi or Duro.
 */
typedef struct {
  /**
   * GPS Time of Week [ms]
   */
  u32 tow;

  /**
   * angular rate about x axis [microdegrees/s]
   */
  s32 x;

  /**
   * angular rate about y axis [microdegrees/s]
   */
  s32 y;

  /**
   * angular rate about z axis [microdegrees/s]
   */
  s32 z;

  /**
   * Status flags
   */
  u8 flags;
} sbp_msg_angular_rate_t;

/**
 * Get encoded size of an instance of sbp_msg_angular_rate_t
 *
 * @param msg sbp_msg_angular_rate_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_msg_angular_rate_t(
    const sbp_msg_angular_rate_t *msg);

/**
 * Encode an instance of sbp_msg_angular_rate_t to wire representation
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
 * @param msg Instance of sbp_msg_angular_rate_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_msg_angular_rate_t(uint8_t *buf, uint8_t len,
                                     uint8_t *n_written,
                                     const sbp_msg_angular_rate_t *msg);

/**
 * Decode an instance of sbp_msg_angular_rate_t from wire representation
 *
 * This function decodes the wire representation of a sbp_msg_angular_rate_t
 * message to the given instance. The caller must specify the length of the
 * buffer in the \p len parameter. If non-null the number of bytes read from the
 * buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_msg_angular_rate_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_msg_angular_rate_t(const uint8_t *buf, uint8_t len,
                                     uint8_t *n_read,
                                     sbp_msg_angular_rate_t *msg);
/**
 * Send an instance of sbp_msg_angular_rate_t with the given write function
 *
 * An equivalent of #sbp_send_message which operates specifically on
 * sbp_msg_angular_rate_t
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
s8 sbp_send_sbp_msg_angular_rate_t(struct sbp_state *s, u16 sender_id,
                                   const sbp_msg_angular_rate_t *msg,
                                   s32 (*write)(u8 *buff, u32 n,
                                                void *context));

/**
 * Compare two instances of sbp_msg_angular_rate_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_angular_rate_t instance
 * @param b sbp_msg_angular_rate_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_msg_angular_rate_t(const sbp_msg_angular_rate_t *a,
                                   const sbp_msg_angular_rate_t *b);

#ifdef __cplusplus
}
static inline bool operator==(const sbp_msg_baseline_heading_t &lhs,
                              const sbp_msg_baseline_heading_t &rhs) {
  return sbp_cmp_sbp_msg_baseline_heading_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_msg_baseline_heading_t &lhs,
                              const sbp_msg_baseline_heading_t &rhs) {
  return sbp_cmp_sbp_msg_baseline_heading_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_baseline_heading_t &lhs,
                             const sbp_msg_baseline_heading_t &rhs) {
  return sbp_cmp_sbp_msg_baseline_heading_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_msg_baseline_heading_t &lhs,
                              const sbp_msg_baseline_heading_t &rhs) {
  return sbp_cmp_sbp_msg_baseline_heading_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_baseline_heading_t &lhs,
                             const sbp_msg_baseline_heading_t &rhs) {
  return sbp_cmp_sbp_msg_baseline_heading_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_msg_baseline_heading_t &lhs,
                              const sbp_msg_baseline_heading_t &rhs) {
  return sbp_cmp_sbp_msg_baseline_heading_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_msg_orient_quat_t &lhs,
                              const sbp_msg_orient_quat_t &rhs) {
  return sbp_cmp_sbp_msg_orient_quat_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_msg_orient_quat_t &lhs,
                              const sbp_msg_orient_quat_t &rhs) {
  return sbp_cmp_sbp_msg_orient_quat_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_orient_quat_t &lhs,
                             const sbp_msg_orient_quat_t &rhs) {
  return sbp_cmp_sbp_msg_orient_quat_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_msg_orient_quat_t &lhs,
                              const sbp_msg_orient_quat_t &rhs) {
  return sbp_cmp_sbp_msg_orient_quat_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_orient_quat_t &lhs,
                             const sbp_msg_orient_quat_t &rhs) {
  return sbp_cmp_sbp_msg_orient_quat_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_msg_orient_quat_t &lhs,
                              const sbp_msg_orient_quat_t &rhs) {
  return sbp_cmp_sbp_msg_orient_quat_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_msg_orient_euler_t &lhs,
                              const sbp_msg_orient_euler_t &rhs) {
  return sbp_cmp_sbp_msg_orient_euler_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_msg_orient_euler_t &lhs,
                              const sbp_msg_orient_euler_t &rhs) {
  return sbp_cmp_sbp_msg_orient_euler_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_orient_euler_t &lhs,
                             const sbp_msg_orient_euler_t &rhs) {
  return sbp_cmp_sbp_msg_orient_euler_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_msg_orient_euler_t &lhs,
                              const sbp_msg_orient_euler_t &rhs) {
  return sbp_cmp_sbp_msg_orient_euler_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_orient_euler_t &lhs,
                             const sbp_msg_orient_euler_t &rhs) {
  return sbp_cmp_sbp_msg_orient_euler_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_msg_orient_euler_t &lhs,
                              const sbp_msg_orient_euler_t &rhs) {
  return sbp_cmp_sbp_msg_orient_euler_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_msg_angular_rate_t &lhs,
                              const sbp_msg_angular_rate_t &rhs) {
  return sbp_cmp_sbp_msg_angular_rate_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_msg_angular_rate_t &lhs,
                              const sbp_msg_angular_rate_t &rhs) {
  return sbp_cmp_sbp_msg_angular_rate_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_angular_rate_t &lhs,
                             const sbp_msg_angular_rate_t &rhs) {
  return sbp_cmp_sbp_msg_angular_rate_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_msg_angular_rate_t &lhs,
                              const sbp_msg_angular_rate_t &rhs) {
  return sbp_cmp_sbp_msg_angular_rate_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_angular_rate_t &lhs,
                             const sbp_msg_angular_rate_t &rhs) {
  return sbp_cmp_sbp_msg_angular_rate_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_msg_angular_rate_t &lhs,
                              const sbp_msg_angular_rate_t &rhs) {
  return sbp_cmp_sbp_msg_angular_rate_t(&lhs, &rhs) >= 0;
}

#endif

#endif /* LIBSBP_NEW_ORIENTATION_MESSAGES_H */
