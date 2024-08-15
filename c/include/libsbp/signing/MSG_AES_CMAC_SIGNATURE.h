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
 * Automatically generated from yaml/swiftnav/sbp/signing.yaml
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

#ifndef LIBSBP_SIGNING_MSG_AES_CMAC_SIGNATURE_H
#define LIBSBP_SIGNING_MSG_AES_CMAC_SIGNATURE_H

#include <math.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>

#include <libsbp/common.h>
#include <libsbp/signing_macros.h>
#include <libsbp/string/sbp_string.h>

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
 *
 * SBP_MSG_AES_CMAC_SIGNATURE
 *
 *****************************************************************************/
/** AES-CMAC 128 digital signature
 *
 * Digital signature using AES-CMAC 128 algorithm used for data integrity.
 */
typedef struct {
  /**
   * Signature message counter. Zero indexed and incremented with each signature
   * message.  The counter will not increment if this message was in response to
   * an on demand request.  The counter will roll over after 256 messages. Upon
   * connection, the value of the counter may not initially be zero.
   */
  u8 stream_counter;

  /**
   * On demand message counter. Zero indexed and incremented with each signature
   * message sent in response to an on demand message. The counter will roll
   * over after 256 messages.  Upon connection, the value of the counter may not
   * initially be zero.
   */
  u8 on_demand_counter;

  /**
   * The last 4 bytes of the certificate's SHA-1 fingerprint
   */
  u8 certificate_id[SBP_MSG_AES_CMAC_SIGNATURE_CERTIFICATE_ID_MAX];

  /**
   * Signature (CMAC tag value)
   */
  u8 signature[SBP_MSG_AES_CMAC_SIGNATURE_SIGNATURE_MAX];

  /**
   * Describes the format of the 'signed messages' field below.
   */
  u8 flags;

  /**
   * CRCs of the messages covered by this signature.  For Skylark, which
   * delivers SBP messages wrapped in Swift's proprietary RTCM message, these
   * are the 24-bit CRCs from the RTCM message framing. For SBP only streams,
   * this will be 16-bit CRCs from the SBP framing.  See the `flags` field to
   * determine the type of CRCs covered.
   */
  u8 signed_messages[SBP_MSG_AES_CMAC_SIGNATURE_SIGNED_MESSAGES_MAX];
  /**
   * Number of elements in signed_messages
   *
   * When sending a message fill in this field with the number elements set in
   * signed_messages before calling an appropriate libsbp send function
   *
   * When receiving a message query this field for the number of elements in
   * signed_messages. The value of any elements beyond the index specified in
   * this field is undefined
   */
  u8 n_signed_messages;
} sbp_msg_aes_cmac_signature_t;

/**
 * Get encoded size of an instance of sbp_msg_aes_cmac_signature_t
 *
 * @param msg sbp_msg_aes_cmac_signature_t instance
 * @return Length of on-wire representation
 */
static inline size_t sbp_msg_aes_cmac_signature_encoded_len(
    const sbp_msg_aes_cmac_signature_t *msg) {
  return SBP_MSG_AES_CMAC_SIGNATURE_ENCODED_OVERHEAD +
         (msg->n_signed_messages * SBP_ENCODED_LEN_U8);
}

/**
 * Encode an instance of sbp_msg_aes_cmac_signature_t to wire representation
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
 * @param msg Instance of sbp_msg_aes_cmac_signature_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
SBP_EXPORT s8
sbp_msg_aes_cmac_signature_encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                                  const sbp_msg_aes_cmac_signature_t *msg);

/**
 * Decode an instance of sbp_msg_aes_cmac_signature_t from wire representation
 *
 * This function decodes the wire representation of a
 * sbp_msg_aes_cmac_signature_t message to the given instance. The caller must
 * specify the length of the buffer in the \p len parameter. If non-null the
 * number of bytes read from the buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_msg_aes_cmac_signature_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
SBP_EXPORT s8 sbp_msg_aes_cmac_signature_decode(
    const uint8_t *buf, uint8_t len, uint8_t *n_read,
    sbp_msg_aes_cmac_signature_t *msg);
/**
 * Send an instance of sbp_msg_aes_cmac_signature_t with the given write
 * function
 *
 * An equivalent of #sbp_message_send which operates specifically on
 * sbp_msg_aes_cmac_signature_t
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
SBP_EXPORT s8 sbp_msg_aes_cmac_signature_send(
    sbp_state_t *s, u16 sender_id, const sbp_msg_aes_cmac_signature_t *msg,
    sbp_write_fn_t write);

/**
 * Compare two instances of sbp_msg_aes_cmac_signature_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_aes_cmac_signature_t instance
 * @param b sbp_msg_aes_cmac_signature_t instance
 * @return 0, <0, >0
 */
SBP_EXPORT int sbp_msg_aes_cmac_signature_cmp(
    const sbp_msg_aes_cmac_signature_t *a,
    const sbp_msg_aes_cmac_signature_t *b);

#ifdef __cplusplus
}

static inline bool operator==(const sbp_msg_aes_cmac_signature_t &lhs,
                              const sbp_msg_aes_cmac_signature_t &rhs) {
  return sbp_msg_aes_cmac_signature_cmp(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_msg_aes_cmac_signature_t &lhs,
                              const sbp_msg_aes_cmac_signature_t &rhs) {
  return sbp_msg_aes_cmac_signature_cmp(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_aes_cmac_signature_t &lhs,
                             const sbp_msg_aes_cmac_signature_t &rhs) {
  return sbp_msg_aes_cmac_signature_cmp(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_msg_aes_cmac_signature_t &lhs,
                              const sbp_msg_aes_cmac_signature_t &rhs) {
  return sbp_msg_aes_cmac_signature_cmp(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_aes_cmac_signature_t &lhs,
                             const sbp_msg_aes_cmac_signature_t &rhs) {
  return sbp_msg_aes_cmac_signature_cmp(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_msg_aes_cmac_signature_t &lhs,
                              const sbp_msg_aes_cmac_signature_t &rhs) {
  return sbp_msg_aes_cmac_signature_cmp(&lhs, &rhs) >= 0;
}

#endif  // ifdef __cplusplus

#endif /* LIBSBP_SIGNING_MSG_AES_CMAC_SIGNATURE_H */
