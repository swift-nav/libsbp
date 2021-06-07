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
 * Automatically generated from yaml/swiftnav/sbp/ext_events.yaml
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

#ifndef LIBSBP_NEW_EXT_EVENTS_MESSAGES_H
#define LIBSBP_NEW_EXT_EVENTS_MESSAGES_H

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

#ifdef __cplusplus
extern "C" {
#endif

struct sbp_state;
#ifndef LIBSBP_LEGACY_EXT_EVENTS_MESSAGES_H
#define SBP_EXT_EVENT_TIME_QUALITY_MASK (0x1)
#define SBP_EXT_EVENT_TIME_QUALITY_SHIFT (1u)
#define SBP_EXT_EVENT_TIME_QUALITY_GET(flags)      \
  (((flags) >> SBP_EXT_EVENT_TIME_QUALITY_SHIFT) & \
   SBP_EXT_EVENT_TIME_QUALITY_MASK)
#define SBP_EXT_EVENT_TIME_QUALITY_SET(flags, val)           \
  do {                                                       \
    ((flags) |= (((val) & (SBP_EXT_EVENT_TIME_QUALITY_MASK)) \
                 << (SBP_EXT_EVENT_TIME_QUALITY_SHIFT)));    \
  } while (0)

#define SBP_EXT_EVENT_TIME_QUALITY_UNKNOWN_DONT_HAVE_NAV_SOLUTION (0)
#define SBP_EXT_EVENT_TIME_QUALITY_GOOD (1)
#define SBP_EXT_EVENT_NEW_LEVEL_OF_PIN_MASK (0x1)
#define SBP_EXT_EVENT_NEW_LEVEL_OF_PIN_SHIFT (0u)
#define SBP_EXT_EVENT_NEW_LEVEL_OF_PIN_GET(flags)      \
  (((flags) >> SBP_EXT_EVENT_NEW_LEVEL_OF_PIN_SHIFT) & \
   SBP_EXT_EVENT_NEW_LEVEL_OF_PIN_MASK)
#define SBP_EXT_EVENT_NEW_LEVEL_OF_PIN_SET(flags, val)           \
  do {                                                           \
    ((flags) |= (((val) & (SBP_EXT_EVENT_NEW_LEVEL_OF_PIN_MASK)) \
                 << (SBP_EXT_EVENT_NEW_LEVEL_OF_PIN_SHIFT)));    \
  } while (0)

#define SBP_EXT_EVENT_NEW_LEVEL_OF_PIN_LOW (0)
#define SBP_EXT_EVENT_NEW_LEVEL_OF_PIN_HIGH (1)
#endif
/** Reports timestamped external pin event
 *
((m.desc|commentify)))
 */
#ifndef LIBSBP_LEGACY_EXT_EVENTS_MESSAGES_H
#define SBP_MSG_EXT_EVENT 0x0101
#endif
typedef struct {
  u16 wn;
  u32 tow;
  s32 ns_residual;
  u8 flags;
  u8 pin;
} sbp_msg_ext_event_t;

size_t sbp_packed_size_sbp_msg_ext_event_t(const sbp_msg_ext_event_t *msg);
s8 sbp_encode_sbp_msg_ext_event_t(uint8_t *buf, uint8_t len, uint8_t *n_written,
                                  const sbp_msg_ext_event_t *msg);
s8 sbp_decode_sbp_msg_ext_event_t(const uint8_t *buf, uint8_t len,
                                  uint8_t *n_read, sbp_msg_ext_event_t *msg);
s8 sbp_send_sbp_msg_ext_event_t(struct sbp_state *s, u16 sender_id,
                                const sbp_msg_ext_event_t *msg,
                                s32 (*write)(u8 *buff, u32 n, void *context));

int sbp_cmp_sbp_msg_ext_event_t(const sbp_msg_ext_event_t *a,
                                const sbp_msg_ext_event_t *b);

#ifdef __cplusplus
}
static inline bool operator==(const sbp_msg_ext_event_t &a,
                              const sbp_msg_ext_event_t &b) {
  return sbp_cmp_sbp_msg_ext_event_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_ext_event_t &a,
                              const sbp_msg_ext_event_t &b) {
  return sbp_cmp_sbp_msg_ext_event_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_ext_event_t &a,
                             const sbp_msg_ext_event_t &b) {
  return sbp_cmp_sbp_msg_ext_event_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_ext_event_t &a,
                              const sbp_msg_ext_event_t &b) {
  return sbp_cmp_sbp_msg_ext_event_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_ext_event_t &a,
                             const sbp_msg_ext_event_t &b) {
  return sbp_cmp_sbp_msg_ext_event_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_ext_event_t &a,
                              const sbp_msg_ext_event_t &b) {
  return sbp_cmp_sbp_msg_ext_event_t(&a, &b) >= 0;
}

#endif

#endif /* LIBSBP_NEW_EXT_EVENTS_MESSAGES_H */
