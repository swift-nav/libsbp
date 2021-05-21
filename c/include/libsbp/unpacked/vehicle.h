#ifndef LIBSBP_VEHICLE_MESSAGES_H
#define LIBSBP_VEHICLE_MESSAGES_H

#include <stdbool.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>
#include <endian.h>
#include <math.h>

#include <libsbp/common.h>
#include <libsbp/unpacked/string/multipart.h>
#include <libsbp/unpacked/string/sequence.h>
#include <libsbp/unpacked/string/unterminated.h>
#include <libsbp/unpacked/string/null_terminated.h>
#include <libsbp/unpacked/string/binary.h>

#ifdef __cplusplus
  extern "C" {
#endif
#define SBP_ODOMETRY_VEHICLE_METADATA_MASK (0x3)
#define SBP_ODOMETRY_VEHICLE_METADATA_SHIFT (5u)
#define SBP_ODOMETRY_VEHICLE_METADATA_GET(flags) \
                             (((flags) >> SBP_ODOMETRY_VEHICLE_METADATA_SHIFT) \
                             & SBP_ODOMETRY_VEHICLE_METADATA_MASK)
#define SBP_ODOMETRY_VEHICLE_METADATA_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_ODOMETRY_VEHICLE_METADATA_MASK)) \
                             << (SBP_ODOMETRY_VEHICLE_METADATA_SHIFT)));} while(0)
                             

#define SBP_ODOMETRY_VEHICLE_METADATA_UNAVAILABLE (0)
#define SBP_ODOMETRY_VEHICLE_METADATA_FORWARD (1)
#define SBP_ODOMETRY_VEHICLE_METADATA_REVERSE (2)
#define SBP_ODOMETRY_VEHICLE_METADATA_PARK (3)
#define SBP_ODOMETRY_VELOCITY_SOURCE_MASK (0x3)
#define SBP_ODOMETRY_VELOCITY_SOURCE_SHIFT (3u)
#define SBP_ODOMETRY_VELOCITY_SOURCE_GET(flags) \
                             (((flags) >> SBP_ODOMETRY_VELOCITY_SOURCE_SHIFT) \
                             & SBP_ODOMETRY_VELOCITY_SOURCE_MASK)
#define SBP_ODOMETRY_VELOCITY_SOURCE_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_ODOMETRY_VELOCITY_SOURCE_MASK)) \
                             << (SBP_ODOMETRY_VELOCITY_SOURCE_SHIFT)));} while(0)
                             

#define SBP_ODOMETRY_VELOCITY_SOURCE_SOURCE_0 (0)
#define SBP_ODOMETRY_VELOCITY_SOURCE_SOURCE_1 (1)
#define SBP_ODOMETRY_VELOCITY_SOURCE_SOURCE_2 (2)
#define SBP_ODOMETRY_VELOCITY_SOURCE_SOURCE_3 (3)
#define SBP_ODOMETRY_TIME_SOURCE_MASK (0x7)
#define SBP_ODOMETRY_TIME_SOURCE_SHIFT (0u)
#define SBP_ODOMETRY_TIME_SOURCE_GET(flags) \
                             (((flags) >> SBP_ODOMETRY_TIME_SOURCE_SHIFT) \
                             & SBP_ODOMETRY_TIME_SOURCE_MASK)
#define SBP_ODOMETRY_TIME_SOURCE_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_ODOMETRY_TIME_SOURCE_MASK)) \
                             << (SBP_ODOMETRY_TIME_SOURCE_SHIFT)));} while(0)
                             

#define SBP_ODOMETRY_TIME_SOURCE_NONE (0)
#define SBP_ODOMETRY_TIME_SOURCE_GPS_SOLUTION (1)
#define SBP_ODOMETRY_TIME_SOURCE_PROCESSOR_TIME (2)
/** Vehicle forward (x-axis) velocity
 *
((m.desc|commentify)))
 */
#define SBP_MSG_ODOMETRY  0x0903
typedef struct {
  u32 tow;
  s32 velocity;
  u8 flags;
} sbp_msg_odometry_t;

size_t sbp_packed_size_sbp_msg_odometry_t(const sbp_msg_odometry_t *msg);
s8 sbp_pack_sbp_msg_odometry_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_odometry_t *msg);
s8 sbp_unpack_sbp_msg_odometry_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_odometry_t *msg);

int sbp_cmp_sbp_msg_odometry_t(const sbp_msg_odometry_t *a, const sbp_msg_odometry_t *b);


#define SBP_WHEELTICK_VEHICLE_METADATA_MASK (0x3)
#define SBP_WHEELTICK_VEHICLE_METADATA_SHIFT (2u)
#define SBP_WHEELTICK_VEHICLE_METADATA_GET(flags) \
                             (((flags) >> SBP_WHEELTICK_VEHICLE_METADATA_SHIFT) \
                             & SBP_WHEELTICK_VEHICLE_METADATA_MASK)
#define SBP_WHEELTICK_VEHICLE_METADATA_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_WHEELTICK_VEHICLE_METADATA_MASK)) \
                             << (SBP_WHEELTICK_VEHICLE_METADATA_SHIFT)));} while(0)
                             

#define SBP_WHEELTICK_VEHICLE_METADATA_UNAVAILABLE (0)
#define SBP_WHEELTICK_VEHICLE_METADATA_FORWARD (1)
#define SBP_WHEELTICK_VEHICLE_METADATA_REVERSE (2)
#define SBP_WHEELTICK_VEHICLE_METADATA_PARK (3)
#define SBP_WHEELTICK_SYNCHRONIZATION_TYPE_MASK (0x3)
#define SBP_WHEELTICK_SYNCHRONIZATION_TYPE_SHIFT (0u)
#define SBP_WHEELTICK_SYNCHRONIZATION_TYPE_GET(flags) \
                             (((flags) >> SBP_WHEELTICK_SYNCHRONIZATION_TYPE_SHIFT) \
                             & SBP_WHEELTICK_SYNCHRONIZATION_TYPE_MASK)
#define SBP_WHEELTICK_SYNCHRONIZATION_TYPE_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_WHEELTICK_SYNCHRONIZATION_TYPE_MASK)) \
                             << (SBP_WHEELTICK_SYNCHRONIZATION_TYPE_SHIFT)));} while(0)
                             

#define SBP_WHEELTICK_SYNCHRONIZATION_TYPE_MICROSECONDS_SINCE_LAST_PPS (0)
#define SBP_WHEELTICK_SYNCHRONIZATION_TYPE_MICROSECONDS_IN_GPS_WEEK (1)
#define SBP_WHEELTICK_SYNCHRONIZATION_TYPE_LOCAL_CPU_TIME_IN_NOMINAL_MICROSECONDS (2)
/** Accumulated wheeltick count message
 *
((m.desc|commentify)))
 */
#define SBP_MSG_WHEELTICK 0x0904
typedef struct {
  u64 time;
  u8 flags;
  u8 source;
  s32 ticks;
} sbp_msg_wheeltick_t;

size_t sbp_packed_size_sbp_msg_wheeltick_t(const sbp_msg_wheeltick_t *msg);
s8 sbp_pack_sbp_msg_wheeltick_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_wheeltick_t *msg);
s8 sbp_unpack_sbp_msg_wheeltick_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_wheeltick_t *msg);

int sbp_cmp_sbp_msg_wheeltick_t(const sbp_msg_wheeltick_t *a, const sbp_msg_wheeltick_t *b);



#ifdef __cplusplus
  }
static inline bool operator==(const sbp_msg_odometry_t &a, const sbp_msg_odometry_t &b) {
  return sbp_cmp_sbp_msg_odometry_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_odometry_t &a, const sbp_msg_odometry_t &b) {
  return sbp_cmp_sbp_msg_odometry_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_odometry_t &a, const sbp_msg_odometry_t &b) {
  return sbp_cmp_sbp_msg_odometry_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_odometry_t &a, const sbp_msg_odometry_t &b) {
  return sbp_cmp_sbp_msg_odometry_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_odometry_t &a, const sbp_msg_odometry_t &b) {
  return sbp_cmp_sbp_msg_odometry_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_odometry_t &a, const sbp_msg_odometry_t &b) {
  return sbp_cmp_sbp_msg_odometry_t(&a, &b) >= 0;
}
static inline bool operator==(const sbp_msg_wheeltick_t &a, const sbp_msg_wheeltick_t &b) {
  return sbp_cmp_sbp_msg_wheeltick_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_wheeltick_t &a, const sbp_msg_wheeltick_t &b) {
  return sbp_cmp_sbp_msg_wheeltick_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_wheeltick_t &a, const sbp_msg_wheeltick_t &b) {
  return sbp_cmp_sbp_msg_wheeltick_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_wheeltick_t &a, const sbp_msg_wheeltick_t &b) {
  return sbp_cmp_sbp_msg_wheeltick_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_wheeltick_t &a, const sbp_msg_wheeltick_t &b) {
  return sbp_cmp_sbp_msg_wheeltick_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_wheeltick_t &a, const sbp_msg_wheeltick_t &b) {
  return sbp_cmp_sbp_msg_wheeltick_t(&a, &b) >= 0;
}

#endif

#endif /* LIBSBP_VEHICLE_MESSAGES_H */
