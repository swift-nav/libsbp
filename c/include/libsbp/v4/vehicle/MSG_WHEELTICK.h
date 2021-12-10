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
 * Automatically generated from yaml/swiftnav/sbp/vehicle.yaml
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

#ifndef LIBSBP_V4_VEHICLE_MSG_WHEELTICK_H
#define LIBSBP_V4_VEHICLE_MSG_WHEELTICK_H

#include <math.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>

#include <libsbp/common.h>
#include <libsbp/v4/string/sbp_string.h>
#include <libsbp/vehicle_macros.h>

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
 *
 * SBP_MSG_WHEELTICK
 *
 *****************************************************************************/
/** Accumulated wheeltick count message
 *
 * Message containing the accumulated distance travelled by a wheel located at
 * an odometry reference point defined by the user. The offset for the odometry
 * reference point and the definition and origin of the user frame are defined
 * through the device settings interface. The source of this message is
 * identified by the source field, which is an integer ranging from 0 to 255.
 * The timestamp associated with this message should represent the time when the
 * accumulated tick count reached the value given by the contents of this
 * message as accurately as possible. If using "local CPU time" time tags, the
 * receiving end will expect a `MSG_GNSS_TIME_OFFSET` when a PVT fix becomes
 * available to synchronise wheeltick measurements with GNSS. Local CPU time
 * shall roll over to zero after one week.
 */
typedef struct {
  /**
   * Time field representing either microseconds since the last PPS,
   * microseconds in the GPS Week or local CPU time from the producing system in
   * microseconds. See the synch_type field for the exact meaning of this
   * timestamp. [us]
   */
  u64 time;

  /**
   * Field indicating the type of timestamp contained in the time field.
   */
  u8 flags;

  /**
   * ID of the sensor producing this message
   */
  u8 source;

  /**
   * Free-running counter of the accumulated distance for this sensor. The
   * counter should be incrementing if travelling into one direction and
   * decrementing when travelling in the opposite direction. [arbitrary distance
   * units]
   */
  s32 ticks;
} sbp_msg_wheeltick_t;

/**
 * Get encoded size of an instance of sbp_msg_wheeltick_t
 *
 * @param msg sbp_msg_wheeltick_t instance
 * @return Length of on-wire representation
 */
static inline size_t sbp_msg_wheeltick_encoded_len(
    const sbp_msg_wheeltick_t *msg) {
  (void)msg;
  return SBP_MSG_WHEELTICK_ENCODED_LEN;
}

/**
 * Encode an instance of sbp_msg_wheeltick_t to wire representation
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
 * @param msg Instance of sbp_msg_wheeltick_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
SBP_EXPORT s8 sbp_msg_wheeltick_encode(uint8_t *buf, uint8_t len,
                                       uint8_t *n_written,
                                       const sbp_msg_wheeltick_t *msg);

/**
 * Decode an instance of sbp_msg_wheeltick_t from wire representation
 *
 * This function decodes the wire representation of a sbp_msg_wheeltick_t
 * message to the given instance. The caller must specify the length of the
 * buffer in the \p len parameter. If non-null the number of bytes read from the
 * buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_msg_wheeltick_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
SBP_EXPORT s8 sbp_msg_wheeltick_decode(const uint8_t *buf, uint8_t len,
                                       uint8_t *n_read,
                                       sbp_msg_wheeltick_t *msg);
/**
 * Send an instance of sbp_msg_wheeltick_t with the given write function
 *
 * An equivalent of #sbp_message_send which operates specifically on
 * sbp_msg_wheeltick_t
 *
 * The given message will be encoded to wire representation and passed in to the
 * given write function callback. The write callback will be called several
 * times for each invocation of this function.
 *
 * @param s SBP state
 * @param sender_id SBP sender id
 * @param msg Message to send
 * @param write Write function
 * @return SBP_OK on success, or other libsbp error code
 */
SBP_EXPORT s8 sbp_msg_wheeltick_send(sbp_state_t *s, u16 sender_id,
                                     const sbp_msg_wheeltick_t *msg,
                                     sbp_write_fn_t write);

/**
 * Compare two instances of sbp_msg_wheeltick_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_wheeltick_t instance
 * @param b sbp_msg_wheeltick_t instance
 * @return 0, <0, >0
 */
SBP_EXPORT int sbp_msg_wheeltick_cmp(const sbp_msg_wheeltick_t *a,
                                     const sbp_msg_wheeltick_t *b);

#ifdef __cplusplus
}

static inline bool operator==(const sbp_msg_wheeltick_t &lhs,
                              const sbp_msg_wheeltick_t &rhs) {
  return sbp_msg_wheeltick_cmp(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_msg_wheeltick_t &lhs,
                              const sbp_msg_wheeltick_t &rhs) {
  return sbp_msg_wheeltick_cmp(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_wheeltick_t &lhs,
                             const sbp_msg_wheeltick_t &rhs) {
  return sbp_msg_wheeltick_cmp(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_msg_wheeltick_t &lhs,
                              const sbp_msg_wheeltick_t &rhs) {
  return sbp_msg_wheeltick_cmp(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_wheeltick_t &lhs,
                             const sbp_msg_wheeltick_t &rhs) {
  return sbp_msg_wheeltick_cmp(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_msg_wheeltick_t &lhs,
                              const sbp_msg_wheeltick_t &rhs) {
  return sbp_msg_wheeltick_cmp(&lhs, &rhs) >= 0;
}

#endif  // ifdef __cplusplus

#endif /* LIBSBP_V4_VEHICLE_MSG_WHEELTICK_H */
