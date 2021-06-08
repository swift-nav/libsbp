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
 * Automatically generated from yaml/swiftnav/sbp/ndb.yaml
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

#ifndef LIBSBP_NEW_NDB_MESSAGES_H
#define LIBSBP_NEW_NDB_MESSAGES_H

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
#ifndef LIBSBP_LEGACY_NDB_MESSAGES_H
#define SBP_NDB_EVENT_EVENT_TYPE_MASK (0x3)
#define SBP_NDB_EVENT_EVENT_TYPE_SHIFT (0u)
#define SBP_NDB_EVENT_EVENT_TYPE_GET(flags) \
  (((flags) >> SBP_NDB_EVENT_EVENT_TYPE_SHIFT) & SBP_NDB_EVENT_EVENT_TYPE_MASK)
#define SBP_NDB_EVENT_EVENT_TYPE_SET(flags, val)           \
  do {                                                     \
    ((flags) |= (((val) & (SBP_NDB_EVENT_EVENT_TYPE_MASK)) \
                 << (SBP_NDB_EVENT_EVENT_TYPE_SHIFT)));    \
  } while (0)

#define SBP_NDB_EVENT_EVENT_TYPE_UNKNOWN (0)
#define SBP_NDB_EVENT_EVENT_TYPE_STORE (1)
#define SBP_NDB_EVENT_EVENT_TYPE_FETCH (2)
#define SBP_NDB_EVENT_EVENT_TYPE_ERASE (3)
#endif
#ifndef LIBSBP_LEGACY_NDB_MESSAGES_H
#define SBP_NDB_EVENT_EVENT_OBJECT_TYPE_MASK (0x7)
#define SBP_NDB_EVENT_EVENT_OBJECT_TYPE_SHIFT (0u)
#define SBP_NDB_EVENT_EVENT_OBJECT_TYPE_GET(flags)      \
  (((flags) >> SBP_NDB_EVENT_EVENT_OBJECT_TYPE_SHIFT) & \
   SBP_NDB_EVENT_EVENT_OBJECT_TYPE_MASK)
#define SBP_NDB_EVENT_EVENT_OBJECT_TYPE_SET(flags, val)           \
  do {                                                            \
    ((flags) |= (((val) & (SBP_NDB_EVENT_EVENT_OBJECT_TYPE_MASK)) \
                 << (SBP_NDB_EVENT_EVENT_OBJECT_TYPE_SHIFT)));    \
  } while (0)

#define SBP_NDB_EVENT_EVENT_OBJECT_TYPE_UNKNOWN (0)
#define SBP_NDB_EVENT_EVENT_OBJECT_TYPE_EPHEMERIS (1)
#define SBP_NDB_EVENT_EVENT_OBJECT_TYPE_ALMANAC (2)
#define SBP_NDB_EVENT_EVENT_OBJECT_TYPE_ALMANAC_WN (3)
#define SBP_NDB_EVENT_EVENT_OBJECT_TYPE_IONO (4)
#define SBP_NDB_EVENT_EVENT_OBJECT_TYPE_L2C_CAP (5)
#define SBP_NDB_EVENT_EVENT_OBJECT_TYPE_LGF (6)
#endif
#ifndef LIBSBP_LEGACY_NDB_MESSAGES_H
#define SBP_NDB_EVENT_EVENT_RESULT_MASK (0xf)
#define SBP_NDB_EVENT_EVENT_RESULT_SHIFT (0u)
#define SBP_NDB_EVENT_EVENT_RESULT_GET(flags)      \
  (((flags) >> SBP_NDB_EVENT_EVENT_RESULT_SHIFT) & \
   SBP_NDB_EVENT_EVENT_RESULT_MASK)
#define SBP_NDB_EVENT_EVENT_RESULT_SET(flags, val)           \
  do {                                                       \
    ((flags) |= (((val) & (SBP_NDB_EVENT_EVENT_RESULT_MASK)) \
                 << (SBP_NDB_EVENT_EVENT_RESULT_SHIFT)));    \
  } while (0)

#define SBP_NDB_EVENT_EVENT_RESULT_NDB_ERR_NONE (0)
#define SBP_NDB_EVENT_EVENT_RESULT_NDB_ERR_MISSING_IE (1)
#define SBP_NDB_EVENT_EVENT_RESULT_NDB_ERR_UNSUPPORTED (2)
#define SBP_NDB_EVENT_EVENT_RESULT_NDB_ERR_FILE_IO (3)
#define SBP_NDB_EVENT_EVENT_RESULT_NDB_ERR_INIT_DONE (4)
#define SBP_NDB_EVENT_EVENT_RESULT_NDB_ERR_BAD_PARAM (5)
#define SBP_NDB_EVENT_EVENT_RESULT_NDB_ERR_UNRELIABLE_DATA (6)
#define SBP_NDB_EVENT_EVENT_RESULT_NDB_ERR_ALGORITHM_ERROR (7)
#define SBP_NDB_EVENT_EVENT_RESULT_NDB_ERR_NO_DATA (8)
#define SBP_NDB_EVENT_EVENT_RESULT_NDB_ERR_NO_CHANGE (9)
#define SBP_NDB_EVENT_EVENT_RESULT_NDB_ERR_OLDER_DATA (10)
#endif
#ifndef LIBSBP_LEGACY_NDB_MESSAGES_H
#define SBP_NDB_EVENT_DATA_SOURCE_MASK (0x3)
#define SBP_NDB_EVENT_DATA_SOURCE_SHIFT (0u)
#define SBP_NDB_EVENT_DATA_SOURCE_GET(flags)      \
  (((flags) >> SBP_NDB_EVENT_DATA_SOURCE_SHIFT) & \
   SBP_NDB_EVENT_DATA_SOURCE_MASK)
#define SBP_NDB_EVENT_DATA_SOURCE_SET(flags, val)           \
  do {                                                      \
    ((flags) |= (((val) & (SBP_NDB_EVENT_DATA_SOURCE_MASK)) \
                 << (SBP_NDB_EVENT_DATA_SOURCE_SHIFT)));    \
  } while (0)

#define SBP_NDB_EVENT_DATA_SOURCE_NDB_DS_UNDEFINED (0)
#define SBP_NDB_EVENT_DATA_SOURCE_NDB_DS_INIT (1)
#define SBP_NDB_EVENT_DATA_SOURCE_NDB_DS_RECEIVER (2)
#define SBP_NDB_EVENT_DATA_SOURCE_NDB_DS_SBP (3)
#endif
/** Navigation DataBase Event
 *
((m.desc|commentify)))
 */
#ifndef LIBSBP_LEGACY_NDB_MESSAGES_H
#define SBP_MSG_NDB_EVENT 0x0400
#endif
typedef struct {
  u64 recv_time;
  u8 event;
  u8 object_type;
  u8 result;
  u8 data_source;
  sbp_sbp_gnss_signal_t object_sid;
  sbp_sbp_gnss_signal_t src_sid;
  u16 original_sender;
} sbp_msg_ndb_event_t;

size_t sbp_packed_size_sbp_msg_ndb_event_t(const sbp_msg_ndb_event_t *msg);
s8 sbp_encode_sbp_msg_ndb_event_t(uint8_t *buf, uint8_t len, uint8_t *n_written,
                                  const sbp_msg_ndb_event_t *msg);
s8 sbp_decode_sbp_msg_ndb_event_t(const uint8_t *buf, uint8_t len,
                                  uint8_t *n_read, sbp_msg_ndb_event_t *msg);
s8 sbp_send_sbp_msg_ndb_event_t(struct sbp_state *s, u16 sender_id,
                                const sbp_msg_ndb_event_t *msg,
                                s32 (*write)(u8 *buff, u32 n, void *context));

int sbp_cmp_sbp_msg_ndb_event_t(const sbp_msg_ndb_event_t *a,
                                const sbp_msg_ndb_event_t *b);

#ifdef __cplusplus
}
static inline bool operator==(const sbp_msg_ndb_event_t &a,
                              const sbp_msg_ndb_event_t &b) {
  return sbp_cmp_sbp_msg_ndb_event_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_ndb_event_t &a,
                              const sbp_msg_ndb_event_t &b) {
  return sbp_cmp_sbp_msg_ndb_event_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_ndb_event_t &a,
                             const sbp_msg_ndb_event_t &b) {
  return sbp_cmp_sbp_msg_ndb_event_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_ndb_event_t &a,
                              const sbp_msg_ndb_event_t &b) {
  return sbp_cmp_sbp_msg_ndb_event_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_ndb_event_t &a,
                             const sbp_msg_ndb_event_t &b) {
  return sbp_cmp_sbp_msg_ndb_event_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_ndb_event_t &a,
                              const sbp_msg_ndb_event_t &b) {
  return sbp_cmp_sbp_msg_ndb_event_t(&a, &b) >= 0;
}

#endif

#endif /* LIBSBP_NEW_NDB_MESSAGES_H */
