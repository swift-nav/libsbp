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
 * Automatically generated 
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

#ifndef NEW_MESSAGES_UNION_H
#define NEW_MESSAGES_UNION_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

((*- for i in include *))
#include <libsbp/v4/(((i)))>
((*- endfor *))

#ifdef __cplusplus
  extern "C" {
#endif


 /*
 * Used to hold an individual sbp_msg struct so that the message can be used in
 * all general purpose functions within this file.
 */
typedef union {
((*- for m in msgs *))
  (((m|convert_unpacked))) (((m|convert_unpacked_union)));
((*- endfor *))
} sbp_msg_t;


/** Encodes a SBP message to the SBP wire format, writing it to the given buffer.
 *
 * \param buf         Buffer to write the resulting encoded data to
 * \param len         The amount of bytes available in buf
 * \param n_written   (out) Number of bytes written to buf
 * \param msg_type    SBP message type
 * \param msg         SBP message to encode
 * \return `SBP_ENCODE_ERROR` (-7) if message was unable to be encoded
 *         `SBP_OK` (0) if the message was successfully encoded and written to buf
 *         callback
 */
static inline s8 sbp_encode_msg(uint8_t *buf, uint8_t len, uint8_t *n_written, uint16_t msg_type, const sbp_msg_t *msg) {
  switch(msg_type) {
((*- for m in msgs *))
    case SBP_(((m))):
      return sbp_encode_(((m|convert_unpacked)))(buf, len, n_written, &msg->(((m|convert_unpacked_union))));
((*- endfor *))
    default:
      break;
  }
  return -1;
}

/** Decodes a SBP message from the SBP encoded wire format.
 *
 * \param buf         Buffer containing the encoded SBP message
 * \param len         Number of bytes in buf
 * \param n_read      (out) The number of bytes read when decoding
 * \param msg_type    SBP message type to decode to
 * \param msg         SBP message struct to fill in the details of
 * \return `SBP_DECODE_ERROR` (-8) if message was unable to be decoded
 *         `SBP_OK` (0) if the message was successfully decoded
 *         callback
 */
static inline s8 sbp_decode_msg(const uint8_t *buf, uint8_t len, uint8_t *n_read, uint16_t msg_type, sbp_msg_t *msg) {
  switch(msg_type) {
((*- for m in msgs *))
    case SBP_(((m))):
      return sbp_decode_(((m|convert_unpacked)))(buf, len, n_read, &msg->(((m|convert_unpacked_union))));
((*- endfor *))
    default:
      break;
  }
  return -1;
}

/** Returns the wire format size in bytes of a given SBP message.
 *
 * \param msg_type    SBP message type
 * \param msg         SBP message
 * \return            The Number of bytes that the given message would be on the wire
 */
static inline size_t sbp_packed_size(uint16_t msg_type, const sbp_msg_t *msg) {
  switch(msg_type) {
((*- for m in msgs *))
    case SBP_(((m))):
      return sbp_packed_size_(((m|convert_unpacked)))(&msg->(((m|convert_unpacked_union))));
((*- endfor *))
    default:
      break;
  }
  return 0;
}

/** Compares two SBP messages of equal type.
 *
 * \param msg_type    SBP message type
 * \param a           The first message to compare
 * \param b           The second message to compare
 * \return            0 if the two messages have equal fields
 *                    1 if, on the first non-equal field, a.field > b.field
 *                    -1 if, on the first non-equal field, a.field < b.field
 */
static inline int sbp_msg_cmp(uint16_t msg_type, const sbp_msg_t *a, const sbp_msg_t *b) {
  switch(msg_type) {
    ((*- for m in msgs *))
    case SBP_(((m))):
      return sbp_cmp_(((m|convert_unpacked)))(&a->(((m|convert_unpacked_union))), &b->(((m|convert_unpacked_union))));
    ((*- endfor *))
    default:
      break;
  }
  return 0;
}

#ifdef __cplusplus
}
#endif

#endif

