/*
 * Copyright (C) 2015-2021 Swift Navigation Inc.
 * Contact: https://support.swiftnav.com
 *
 * This source is subject to the license found in the file 'LICENSE' which must
 * be distributed together with this source. All other rights reserved.
 *
 * THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
 * EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
 */

/*****************************************************************************
 * Automatically generated from yaml/swiftnav/sbp/flash.yaml
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

#ifndef LIBSBP_FLASH_MSG_STM_UNIQUE_ID_REQ_H
#define LIBSBP_FLASH_MSG_STM_UNIQUE_ID_REQ_H

#include <math.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>

#include <libsbp/common.h>
#include <libsbp/flash_macros.h>
#include <libsbp/string/sbp_string.h>

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
 *
 * SBP_MSG_STM_UNIQUE_ID_REQ
 *
 *****************************************************************************/
/** Read device's hard-coded unique ID request (host => device)

 *
* This message reads the device's hard-coded unique ID. The host requests the ID
by sending a MSG_STM_UNIQUE_ID_REQ. The device responds with a
MSG_STM_UNIQUE_ID_RESP with the 12-byte unique ID in the payload.
 */
typedef struct {
  /**
   * Do not use this field, it exists only to prevent illegal C syntax. Any
   * value written to this field will be ignored
   */
  char DO_NOT_USE_dummy_field_to_prevent_empty_struct;
} sbp_msg_stm_unique_id_req_t;

/**
 * Get encoded size of an instance of sbp_msg_stm_unique_id_req_t
 *
 * @param msg sbp_msg_stm_unique_id_req_t instance
 * @return Length of on-wire representation
 */
static inline size_t sbp_msg_stm_unique_id_req_encoded_len(
    const sbp_msg_stm_unique_id_req_t *msg) {
  (void)msg;
  return SBP_MSG_STM_UNIQUE_ID_REQ_ENCODED_LEN;
}

/**
 * Encode an instance of sbp_msg_stm_unique_id_req_t to wire representation
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
 * @param msg Instance of sbp_msg_stm_unique_id_req_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
SBP_EXPORT s8
sbp_msg_stm_unique_id_req_encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                                 const sbp_msg_stm_unique_id_req_t *msg);

/**
 * Decode an instance of sbp_msg_stm_unique_id_req_t from wire representation
 *
 * This function decodes the wire representation of a
 * sbp_msg_stm_unique_id_req_t message to the given instance. The caller must
 * specify the length of the buffer in the \p len parameter. If non-null the
 * number of bytes read from the buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_msg_stm_unique_id_req_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
SBP_EXPORT s8 sbp_msg_stm_unique_id_req_decode(
    const uint8_t *buf, uint8_t len, uint8_t *n_read,
    sbp_msg_stm_unique_id_req_t *msg);
/**
 * Send an instance of sbp_msg_stm_unique_id_req_t with the given write function
 *
 * An equivalent of #sbp_message_send which operates specifically on
 * sbp_msg_stm_unique_id_req_t
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
SBP_EXPORT s8 sbp_msg_stm_unique_id_req_send(
    sbp_state_t *s, u16 sender_id, const sbp_msg_stm_unique_id_req_t *msg,
    sbp_write_fn_t write);

/**
 * Compare two instances of sbp_msg_stm_unique_id_req_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_stm_unique_id_req_t instance
 * @param b sbp_msg_stm_unique_id_req_t instance
 * @return 0, <0, >0
 */
SBP_EXPORT int sbp_msg_stm_unique_id_req_cmp(
    const sbp_msg_stm_unique_id_req_t *a, const sbp_msg_stm_unique_id_req_t *b);

#ifdef __cplusplus
}

static inline bool operator==(const sbp_msg_stm_unique_id_req_t &lhs,
                              const sbp_msg_stm_unique_id_req_t &rhs) {
  return sbp_msg_stm_unique_id_req_cmp(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_msg_stm_unique_id_req_t &lhs,
                              const sbp_msg_stm_unique_id_req_t &rhs) {
  return sbp_msg_stm_unique_id_req_cmp(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_stm_unique_id_req_t &lhs,
                             const sbp_msg_stm_unique_id_req_t &rhs) {
  return sbp_msg_stm_unique_id_req_cmp(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_msg_stm_unique_id_req_t &lhs,
                              const sbp_msg_stm_unique_id_req_t &rhs) {
  return sbp_msg_stm_unique_id_req_cmp(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_stm_unique_id_req_t &lhs,
                             const sbp_msg_stm_unique_id_req_t &rhs) {
  return sbp_msg_stm_unique_id_req_cmp(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_msg_stm_unique_id_req_t &lhs,
                              const sbp_msg_stm_unique_id_req_t &rhs) {
  return sbp_msg_stm_unique_id_req_cmp(&lhs, &rhs) >= 0;
}

#endif  // ifdef __cplusplus

#endif /* LIBSBP_FLASH_MSG_STM_UNIQUE_ID_REQ_H */
