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
 * Automatically generated 
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

#ifndef NEW_MESSAGES_UNION_H
#define NEW_MESSAGES_UNION_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

((*- for i in include *))
#include <libsbp/new/(((i)))>
((*- endfor *))

#ifdef __cplusplus
  extern "C" {
#endif

struct sbp_state;

typedef union {
((*- for m in msgs *))
  (((m|convert_unpacked))) (((m|convert_unpacked_union)));
((*- endfor *))
} sbp_msg_t;

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

