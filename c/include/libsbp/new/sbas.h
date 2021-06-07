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
 * Automatically generated from yaml/swiftnav/sbp/sbas.yaml
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

#ifndef LIBSBP_NEW_SBAS_MESSAGES_H
#define LIBSBP_NEW_SBAS_MESSAGES_H

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

#ifdef __cplusplus
extern "C" {
#endif

struct sbp_state;
/** Raw SBAS data
 *
((m.desc|commentify)))
 */
#ifndef LIBSBP_LEGACY_SBAS_MESSAGES_H
#define SBP_MSG_SBAS_RAW 0x7777
#endif
typedef struct {
  sbp_sbp_gnss_signal_t sid;
  u32 tow;
  u8 message_type;
  u8 data[27];
} sbp_msg_sbas_raw_t;

size_t sbp_packed_size_sbp_msg_sbas_raw_t(const sbp_msg_sbas_raw_t *msg);
s8 sbp_encode_sbp_msg_sbas_raw_t(uint8_t *buf, uint8_t len, uint8_t *n_written,
                                 const sbp_msg_sbas_raw_t *msg);
s8 sbp_decode_sbp_msg_sbas_raw_t(const uint8_t *buf, uint8_t len,
                                 uint8_t *n_read, sbp_msg_sbas_raw_t *msg);
s8 sbp_send_sbp_msg_sbas_raw_t(struct sbp_state *s, u16 sender_id,
                               const sbp_msg_sbas_raw_t *msg,
                               s32 (*write)(u8 *buff, u32 n, void *context));

int sbp_cmp_sbp_msg_sbas_raw_t(const sbp_msg_sbas_raw_t *a,
                               const sbp_msg_sbas_raw_t *b);

#ifdef __cplusplus
}
static inline bool operator==(const sbp_msg_sbas_raw_t &a,
                              const sbp_msg_sbas_raw_t &b) {
  return sbp_cmp_sbp_msg_sbas_raw_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_sbas_raw_t &a,
                              const sbp_msg_sbas_raw_t &b) {
  return sbp_cmp_sbp_msg_sbas_raw_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_sbas_raw_t &a,
                             const sbp_msg_sbas_raw_t &b) {
  return sbp_cmp_sbp_msg_sbas_raw_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_sbas_raw_t &a,
                              const sbp_msg_sbas_raw_t &b) {
  return sbp_cmp_sbp_msg_sbas_raw_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_sbas_raw_t &a,
                             const sbp_msg_sbas_raw_t &b) {
  return sbp_cmp_sbp_msg_sbas_raw_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_sbas_raw_t &a,
                              const sbp_msg_sbas_raw_t &b) {
  return sbp_cmp_sbp_msg_sbas_raw_t(&a, &b) >= 0;
}

#endif

#endif /* LIBSBP_NEW_SBAS_MESSAGES_H */
