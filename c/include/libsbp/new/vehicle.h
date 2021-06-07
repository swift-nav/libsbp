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
 * Automatically generated from yaml/swiftnav/sbp/vehicle.yaml
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

#ifndef LIBSBP_NEW_VEHICLE_MESSAGES_H
#define LIBSBP_NEW_VEHICLE_MESSAGES_H

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
#ifndef LIBSBP_LEGACY_VEHICLE_MESSAGES_H
#define SBP_ODOMETRY_VEHICLE_METADATA_MASK (0x3)
#define SBP_ODOMETRY_VEHICLE_METADATA_SHIFT (5u)
#define SBP_ODOMETRY_VEHICLE_METADATA_GET(flags)      \
  (((flags) >> SBP_ODOMETRY_VEHICLE_METADATA_SHIFT) & \
   SBP_ODOMETRY_VEHICLE_METADATA_MASK)
#define SBP_ODOMETRY_VEHICLE_METADATA_SET(flags, val)           \
  do {                                                          \
    ((flags) |= (((val) & (SBP_ODOMETRY_VEHICLE_METADATA_MASK)) \
                 << (SBP_ODOMETRY_VEHICLE_METADATA_SHIFT)));    \
  } while (0)

#define SBP_ODOMETRY_VEHICLE_METADATA_UNAVAILABLE (0)
#define SBP_ODOMETRY_VEHICLE_METADATA_FORWARD (1)
#define SBP_ODOMETRY_VEHICLE_METADATA_REVERSE (2)
#define SBP_ODOMETRY_VEHICLE_METADATA_PARK (3)
#define SBP_ODOMETRY_VELOCITY_SOURCE_MASK (0x3)
#define SBP_ODOMETRY_VELOCITY_SOURCE_SHIFT (3u)
#define SBP_ODOMETRY_VELOCITY_SOURCE_GET(flags)      \
  (((flags) >> SBP_ODOMETRY_VELOCITY_SOURCE_SHIFT) & \
   SBP_ODOMETRY_VELOCITY_SOURCE_MASK)
#define SBP_ODOMETRY_VELOCITY_SOURCE_SET(flags, val)           \
  do {                                                         \
    ((flags) |= (((val) & (SBP_ODOMETRY_VELOCITY_SOURCE_MASK)) \
                 << (SBP_ODOMETRY_VELOCITY_SOURCE_SHIFT)));    \
  } while (0)

#define SBP_ODOMETRY_VELOCITY_SOURCE_SOURCE_0 (0)
#define SBP_ODOMETRY_VELOCITY_SOURCE_SOURCE_1 (1)
#define SBP_ODOMETRY_VELOCITY_SOURCE_SOURCE_2 (2)
#define SBP_ODOMETRY_VELOCITY_SOURCE_SOURCE_3 (3)
#define SBP_ODOMETRY_TIME_SOURCE_MASK (0x7)
#define SBP_ODOMETRY_TIME_SOURCE_SHIFT (0u)
#define SBP_ODOMETRY_TIME_SOURCE_GET(flags) \
  (((flags) >> SBP_ODOMETRY_TIME_SOURCE_SHIFT) & SBP_ODOMETRY_TIME_SOURCE_MASK)
#define SBP_ODOMETRY_TIME_SOURCE_SET(flags, val)           \
  do {                                                     \
    ((flags) |= (((val) & (SBP_ODOMETRY_TIME_SOURCE_MASK)) \
                 << (SBP_ODOMETRY_TIME_SOURCE_SHIFT)));    \
  } while (0)

#define SBP_ODOMETRY_TIME_SOURCE_NONE (0)
#define SBP_ODOMETRY_TIME_SOURCE_GPS_SOLUTION (1)
#define SBP_ODOMETRY_TIME_SOURCE_PROCESSOR_TIME (2)
#endif
/** Vehicle forward (x-axis) velocity
 *
((m.desc|commentify)))
 */
#ifndef LIBSBP_LEGACY_VEHICLE_MESSAGES_H
#define SBP_MSG_ODOMETRY 0x0903
#endif
typedef struct {
  u32 tow;
  s32 velocity;
  u8 flags;
} sbp_msg_odometry_t;

size_t sbp_packed_size_sbp_msg_odometry_t(const sbp_msg_odometry_t *msg);
s8 sbp_encode_sbp_msg_odometry_t(uint8_t *buf, uint8_t len, uint8_t *n_written,
                                 const sbp_msg_odometry_t *msg);
s8 sbp_decode_sbp_msg_odometry_t(const uint8_t *buf, uint8_t len,
                                 uint8_t *n_read, sbp_msg_odometry_t *msg);
s8 sbp_send_sbp_msg_odometry_t(struct sbp_state *s, u16 sender_id,
                               const sbp_msg_odometry_t *msg,
                               s32 (*write)(u8 *buff, u32 n, void *context));

int sbp_cmp_sbp_msg_odometry_t(const sbp_msg_odometry_t *a,
                               const sbp_msg_odometry_t *b);

#ifndef LIBSBP_LEGACY_VEHICLE_MESSAGES_H
#define SBP_WHEELTICK_VEHICLE_METADATA_MASK (0x3)
#define SBP_WHEELTICK_VEHICLE_METADATA_SHIFT (2u)
#define SBP_WHEELTICK_VEHICLE_METADATA_GET(flags)      \
  (((flags) >> SBP_WHEELTICK_VEHICLE_METADATA_SHIFT) & \
   SBP_WHEELTICK_VEHICLE_METADATA_MASK)
#define SBP_WHEELTICK_VEHICLE_METADATA_SET(flags, val)           \
  do {                                                           \
    ((flags) |= (((val) & (SBP_WHEELTICK_VEHICLE_METADATA_MASK)) \
                 << (SBP_WHEELTICK_VEHICLE_METADATA_SHIFT)));    \
  } while (0)

#define SBP_WHEELTICK_VEHICLE_METADATA_UNAVAILABLE (0)
#define SBP_WHEELTICK_VEHICLE_METADATA_FORWARD (1)
#define SBP_WHEELTICK_VEHICLE_METADATA_REVERSE (2)
#define SBP_WHEELTICK_VEHICLE_METADATA_PARK (3)
#define SBP_WHEELTICK_SYNCHRONIZATION_TYPE_MASK (0x3)
#define SBP_WHEELTICK_SYNCHRONIZATION_TYPE_SHIFT (0u)
#define SBP_WHEELTICK_SYNCHRONIZATION_TYPE_GET(flags)      \
  (((flags) >> SBP_WHEELTICK_SYNCHRONIZATION_TYPE_SHIFT) & \
   SBP_WHEELTICK_SYNCHRONIZATION_TYPE_MASK)
#define SBP_WHEELTICK_SYNCHRONIZATION_TYPE_SET(flags, val)           \
  do {                                                               \
    ((flags) |= (((val) & (SBP_WHEELTICK_SYNCHRONIZATION_TYPE_MASK)) \
                 << (SBP_WHEELTICK_SYNCHRONIZATION_TYPE_SHIFT)));    \
  } while (0)

#define SBP_WHEELTICK_SYNCHRONIZATION_TYPE_MICROSECONDS_SINCE_LAST_PPS (0)
#define SBP_WHEELTICK_SYNCHRONIZATION_TYPE_MICROSECONDS_IN_GPS_WEEK (1)
#define SBP_WHEELTICK_SYNCHRONIZATION_TYPE_LOCAL_CPU_TIME_IN_NOMINAL_MICROSECONDS \
  (2)
#endif
/** Accumulated wheeltick count message
 *
((m.desc|commentify)))
 */
#ifndef LIBSBP_LEGACY_VEHICLE_MESSAGES_H
#define SBP_MSG_WHEELTICK 0x0904
#endif
typedef struct {
  u64 time;
  u8 flags;
  u8 source;
  s32 ticks;
} sbp_msg_wheeltick_t;

size_t sbp_packed_size_sbp_msg_wheeltick_t(const sbp_msg_wheeltick_t *msg);
s8 sbp_encode_sbp_msg_wheeltick_t(uint8_t *buf, uint8_t len, uint8_t *n_written,
                                  const sbp_msg_wheeltick_t *msg);
s8 sbp_decode_sbp_msg_wheeltick_t(const uint8_t *buf, uint8_t len,
                                  uint8_t *n_read, sbp_msg_wheeltick_t *msg);
s8 sbp_send_sbp_msg_wheeltick_t(struct sbp_state *s, u16 sender_id,
                                const sbp_msg_wheeltick_t *msg,
                                s32 (*write)(u8 *buff, u32 n, void *context));

int sbp_cmp_sbp_msg_wheeltick_t(const sbp_msg_wheeltick_t *a,
                                const sbp_msg_wheeltick_t *b);

#ifdef __cplusplus
}
static inline bool operator==(const sbp_msg_odometry_t &a,
                              const sbp_msg_odometry_t &b) {
  return sbp_cmp_sbp_msg_odometry_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_odometry_t &a,
                              const sbp_msg_odometry_t &b) {
  return sbp_cmp_sbp_msg_odometry_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_odometry_t &a,
                             const sbp_msg_odometry_t &b) {
  return sbp_cmp_sbp_msg_odometry_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_odometry_t &a,
                              const sbp_msg_odometry_t &b) {
  return sbp_cmp_sbp_msg_odometry_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_odometry_t &a,
                             const sbp_msg_odometry_t &b) {
  return sbp_cmp_sbp_msg_odometry_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_odometry_t &a,
                              const sbp_msg_odometry_t &b) {
  return sbp_cmp_sbp_msg_odometry_t(&a, &b) >= 0;
}
static inline bool operator==(const sbp_msg_wheeltick_t &a,
                              const sbp_msg_wheeltick_t &b) {
  return sbp_cmp_sbp_msg_wheeltick_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_wheeltick_t &a,
                              const sbp_msg_wheeltick_t &b) {
  return sbp_cmp_sbp_msg_wheeltick_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_wheeltick_t &a,
                             const sbp_msg_wheeltick_t &b) {
  return sbp_cmp_sbp_msg_wheeltick_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_wheeltick_t &a,
                              const sbp_msg_wheeltick_t &b) {
  return sbp_cmp_sbp_msg_wheeltick_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_wheeltick_t &a,
                             const sbp_msg_wheeltick_t &b) {
  return sbp_cmp_sbp_msg_wheeltick_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_wheeltick_t &a,
                              const sbp_msg_wheeltick_t &b) {
  return sbp_cmp_sbp_msg_wheeltick_t(&a, &b) >= 0;
}

#endif

#endif /* LIBSBP_NEW_VEHICLE_MESSAGES_H */
