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

#include <libsbp/v4/sbp_msg.h>


s8 sbp_message_encode(uint8_t *buf, uint8_t len, uint8_t *n_written, sbp_msg_type_t msg_type, const sbp_msg_t *msg) {
  switch(msg_type) {
((*- for m in real_messages *))
    case (((m.v4_msg_type))):
      return (((m.public_encode_fn)))(buf, len, n_written, &msg->(((m.union_member_name))));
((*- endfor *))
    case SbpMsgAll:
      break;
    default:
      break;
  }
  return -1;
}

s8 sbp_message_decode(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_type_t msg_type, sbp_msg_t *msg) {
  switch(msg_type) {
((*- for m in real_messages *))
    case (((m.v4_msg_type))):
      return (((m.public_decode_fn)))(buf, len, n_read, &msg->(((m.union_member_name))));
((*- endfor *))
    case SbpMsgAll:
      break;
    default:
      break;
  }
  return -1;
}

size_t sbp_message_encoded_len(sbp_msg_type_t msg_type, const sbp_msg_t *msg) {
  switch(msg_type) {
((*- for m in real_messages *))
    case (((m.v4_msg_type))):
      return (((m.encoded_len_fn)))(&msg->(((m.union_member_name))));
((*- endfor *))
    case SbpMsgAll:
      break;
    default:
      break;
  }
  return 0;
}

int sbp_message_cmp(sbp_msg_type_t msg_type, const sbp_msg_t *a, const sbp_msg_t *b) {
  switch(msg_type) {
    ((*- for m in real_messages *))
    case (((m.v4_msg_type))):
      return (((m.cmp_fn)))(&a->(((m.union_member_name))), &b->(((m.union_member_name))));
    ((*- endfor *))
    case SbpMsgAll:
      break;
    default:
      break;
  }
  return 0;
}

