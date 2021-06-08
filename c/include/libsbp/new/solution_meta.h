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
 * Automatically generated from yaml/swiftnav/sbp/solution_meta.yaml
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

#ifndef LIBSBP_NEW_SOLUTION_META_MESSAGES_H
#define LIBSBP_NEW_SOLUTION_META_MESSAGES_H

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
#ifndef LIBSBP_LEGACY_SOLUTION_META_MESSAGES_H
#define SBP_SOLUTIONINPUTTYPE_SENSOR_USAGE_MASK (0x3)
#define SBP_SOLUTIONINPUTTYPE_SENSOR_USAGE_SHIFT (3u)
#define SBP_SOLUTIONINPUTTYPE_SENSOR_USAGE_GET(flags)      \
  (((flags) >> SBP_SOLUTIONINPUTTYPE_SENSOR_USAGE_SHIFT) & \
   SBP_SOLUTIONINPUTTYPE_SENSOR_USAGE_MASK)
#define SBP_SOLUTIONINPUTTYPE_SENSOR_USAGE_SET(flags, val)           \
  do {                                                               \
    ((flags) |= (((val) & (SBP_SOLUTIONINPUTTYPE_SENSOR_USAGE_MASK)) \
                 << (SBP_SOLUTIONINPUTTYPE_SENSOR_USAGE_SHIFT)));    \
  } while (0)

#define SBP_SOLUTIONINPUTTYPE_SENSOR_USAGE_UNKNOWN (0)
#define SBP_SOLUTIONINPUTTYPE_SENSOR_USAGE_RECEIVED_AND_USED (1)
#define SBP_SOLUTIONINPUTTYPE_SENSOR_USAGE_RECEIVED_BUT_NOT_USED (2)
#define SBP_SOLUTIONINPUTTYPE_SENSOR_TYPE_MASK (0x7)
#define SBP_SOLUTIONINPUTTYPE_SENSOR_TYPE_SHIFT (0u)
#define SBP_SOLUTIONINPUTTYPE_SENSOR_TYPE_GET(flags)      \
  (((flags) >> SBP_SOLUTIONINPUTTYPE_SENSOR_TYPE_SHIFT) & \
   SBP_SOLUTIONINPUTTYPE_SENSOR_TYPE_MASK)
#define SBP_SOLUTIONINPUTTYPE_SENSOR_TYPE_SET(flags, val)           \
  do {                                                              \
    ((flags) |= (((val) & (SBP_SOLUTIONINPUTTYPE_SENSOR_TYPE_MASK)) \
                 << (SBP_SOLUTIONINPUTTYPE_SENSOR_TYPE_SHIFT)));    \
  } while (0)

#define SBP_SOLUTIONINPUTTYPE_SENSOR_TYPE_INVALID (0)
#define SBP_SOLUTIONINPUTTYPE_SENSOR_TYPE_GNSS_POSITION (1)
#define SBP_SOLUTIONINPUTTYPE_SENSOR_TYPE_GNSS_VELOCITY_DISPLACEMENT (2)
#define SBP_SOLUTIONINPUTTYPE_SENSOR_TYPE_GNSS_VELOCITY_DOPPLER (3)
#define SBP_SOLUTIONINPUTTYPE_SENSOR_TYPE_ODOMETRY_TICKS (4)
#define SBP_SOLUTIONINPUTTYPE_SENSOR_TYPE_ODOMETRY_SPEED (5)
#define SBP_SOLUTIONINPUTTYPE_SENSOR_TYPE_IMU_SENSOR (6)
#endif
/** Flags for a given solution input type
 *
((m.desc|commentify)))
 */
typedef struct {
  u8 sensor_type;
  u8 flags;
} sbp_solution_input_type_t;

size_t sbp_packed_size_sbp_solution_input_type_t(
    const sbp_solution_input_type_t *msg);
s8 sbp_encode_sbp_solution_input_type_t(uint8_t *buf, uint8_t len,
                                        uint8_t *n_written,
                                        const sbp_solution_input_type_t *msg);
s8 sbp_decode_sbp_solution_input_type_t(const uint8_t *buf, uint8_t len,
                                        uint8_t *n_read,
                                        sbp_solution_input_type_t *msg);

int sbp_cmp_sbp_solution_input_type_t(const sbp_solution_input_type_t *a,
                                      const sbp_solution_input_type_t *b);

#ifndef LIBSBP_LEGACY_SOLUTION_META_MESSAGES_H
#define SBP_SOLN_META_DEP_A_ALIGNMENT_STATUS_MASK (0x7)
#define SBP_SOLN_META_DEP_A_ALIGNMENT_STATUS_SHIFT (0u)
#define SBP_SOLN_META_DEP_A_ALIGNMENT_STATUS_GET(flags)      \
  (((flags) >> SBP_SOLN_META_DEP_A_ALIGNMENT_STATUS_SHIFT) & \
   SBP_SOLN_META_DEP_A_ALIGNMENT_STATUS_MASK)
#define SBP_SOLN_META_DEP_A_ALIGNMENT_STATUS_SET(flags, val)           \
  do {                                                                 \
    ((flags) |= (((val) & (SBP_SOLN_META_DEP_A_ALIGNMENT_STATUS_MASK)) \
                 << (SBP_SOLN_META_DEP_A_ALIGNMENT_STATUS_SHIFT)));    \
  } while (0)

#define SBP_SOLN_META_DEP_A_ALIGNMENT_STATUS_UNKNOWN_REASON_OR_ALREADY_ALIGNED \
  (0)
#define SBP_SOLN_META_DEP_A_ALIGNMENT_STATUS_SEED_VALUES_LOADED_AND_ALIGNMENT_IN_PROGRESS \
  (1)
#define SBP_SOLN_META_DEP_A_ALIGNMENT_STATUS_NO_SEED_VALUES_AND_ALIGNMENT_IN_PROGRESS \
  (2)
#define SBP_SOLN_META_DEP_A_ALIGNMENT_STATUS_SEED_VALUES_LOADED_BUT_NO_GNSS_MEASUREMENTS \
  (3)
#define SBP_SOLN_META_DEP_A_ALIGNMENT_STATUS_NO_SEED_VALUES_NOR_GNSS_MEASUREMENTS \
  (4)
#endif
/** Deprecated
 *
((m.desc|commentify)))
 */
#ifndef LIBSBP_LEGACY_SOLUTION_META_MESSAGES_H
#define SBP_MSG_SOLN_META_DEP_A 0xFF0F
#endif
typedef struct {
  u16 pdop;
  u16 hdop;
  u16 vdop;
  u8 n_sats;
  u16 age_corrections;
  u8 alignment_status;
  u32 last_used_gnss_pos_tow;
  u32 last_used_gnss_vel_tow;
  sbp_solution_input_type_t sol_in[118];
  u8 n_sol_in;
} sbp_msg_soln_meta_dep_a_t;

size_t sbp_packed_size_sbp_msg_soln_meta_dep_a_t(
    const sbp_msg_soln_meta_dep_a_t *msg);
s8 sbp_encode_sbp_msg_soln_meta_dep_a_t(uint8_t *buf, uint8_t len,
                                        uint8_t *n_written,
                                        const sbp_msg_soln_meta_dep_a_t *msg);
s8 sbp_decode_sbp_msg_soln_meta_dep_a_t(const uint8_t *buf, uint8_t len,
                                        uint8_t *n_read,
                                        sbp_msg_soln_meta_dep_a_t *msg);
s8 sbp_send_sbp_msg_soln_meta_dep_a_t(struct sbp_state *s, u16 sender_id,
                                      const sbp_msg_soln_meta_dep_a_t *msg,
                                      s32 (*write)(u8 *buff, u32 n,
                                                   void *context));

int sbp_cmp_sbp_msg_soln_meta_dep_a_t(const sbp_msg_soln_meta_dep_a_t *a,
                                      const sbp_msg_soln_meta_dep_a_t *b);

#ifndef LIBSBP_LEGACY_SOLUTION_META_MESSAGES_H
#define SBP_SOLN_META_TIME_STATUS_MASK (0x3)
#define SBP_SOLN_META_TIME_STATUS_SHIFT (30u)
#define SBP_SOLN_META_TIME_STATUS_GET(flags)      \
  (((flags) >> SBP_SOLN_META_TIME_STATUS_SHIFT) & \
   SBP_SOLN_META_TIME_STATUS_MASK)
#define SBP_SOLN_META_TIME_STATUS_SET(flags, val)           \
  do {                                                      \
    ((flags) |= (((val) & (SBP_SOLN_META_TIME_STATUS_MASK)) \
                 << (SBP_SOLN_META_TIME_STATUS_SHIFT)));    \
  } while (0)

#define SBP_SOLN_META_TIME_STATUS_AGE_CAN_NOT_BE_USED_TO_RETRIEVE_TOM (0)
#define SBP_SOLN_META_TIME_STATUS_AGE_CAN_BE_USED_TO_RETRIEVE_TOM (1)
#define SBP_SOLN_META_AGE_OF_THE_LAST_RECEIVED_VALID_GNSS_SOLUTION_MASK \
  (0x3fffffff)
#define SBP_SOLN_META_AGE_OF_THE_LAST_RECEIVED_VALID_GNSS_SOLUTION_SHIFT (0u)
#define SBP_SOLN_META_AGE_OF_THE_LAST_RECEIVED_VALID_GNSS_SOLUTION_GET(flags) \
  (((flags) >>                                                                \
    SBP_SOLN_META_AGE_OF_THE_LAST_RECEIVED_VALID_GNSS_SOLUTION_SHIFT) &       \
   SBP_SOLN_META_AGE_OF_THE_LAST_RECEIVED_VALID_GNSS_SOLUTION_MASK)
#define SBP_SOLN_META_AGE_OF_THE_LAST_RECEIVED_VALID_GNSS_SOLUTION_SET(flags,  \
                                                                       val)    \
  do {                                                                         \
    ((flags) |=                                                                \
     (((val) &                                                                 \
       (SBP_SOLN_META_AGE_OF_THE_LAST_RECEIVED_VALID_GNSS_SOLUTION_MASK))      \
      << (SBP_SOLN_META_AGE_OF_THE_LAST_RECEIVED_VALID_GNSS_SOLUTION_SHIFT))); \
  } while (0)

#endif
/** Solution Sensors Metadata
 *
((m.desc|commentify)))
 */
#ifndef LIBSBP_LEGACY_SOLUTION_META_MESSAGES_H
#define SBP_MSG_SOLN_META 0xFF0E
#endif
typedef struct {
  u32 tow;
  u16 pdop;
  u16 hdop;
  u16 vdop;
  u16 age_corrections;
  u32 age_gnss;
  sbp_solution_input_type_t sol_in[119];
  u8 n_sol_in;
} sbp_msg_soln_meta_t;

size_t sbp_packed_size_sbp_msg_soln_meta_t(const sbp_msg_soln_meta_t *msg);
s8 sbp_encode_sbp_msg_soln_meta_t(uint8_t *buf, uint8_t len, uint8_t *n_written,
                                  const sbp_msg_soln_meta_t *msg);
s8 sbp_decode_sbp_msg_soln_meta_t(const uint8_t *buf, uint8_t len,
                                  uint8_t *n_read, sbp_msg_soln_meta_t *msg);
s8 sbp_send_sbp_msg_soln_meta_t(struct sbp_state *s, u16 sender_id,
                                const sbp_msg_soln_meta_t *msg,
                                s32 (*write)(u8 *buff, u32 n, void *context));

int sbp_cmp_sbp_msg_soln_meta_t(const sbp_msg_soln_meta_t *a,
                                const sbp_msg_soln_meta_t *b);

#ifndef LIBSBP_LEGACY_SOLUTION_META_MESSAGES_H
#define SBP_GNSSINPUTTYPE_TYPE_OF_GNSS_MEASUREMENT_MASK (0x3)
#define SBP_GNSSINPUTTYPE_TYPE_OF_GNSS_MEASUREMENT_SHIFT (0u)
#define SBP_GNSSINPUTTYPE_TYPE_OF_GNSS_MEASUREMENT_GET(flags)      \
  (((flags) >> SBP_GNSSINPUTTYPE_TYPE_OF_GNSS_MEASUREMENT_SHIFT) & \
   SBP_GNSSINPUTTYPE_TYPE_OF_GNSS_MEASUREMENT_MASK)
#define SBP_GNSSINPUTTYPE_TYPE_OF_GNSS_MEASUREMENT_SET(flags, val)           \
  do {                                                                       \
    ((flags) |= (((val) & (SBP_GNSSINPUTTYPE_TYPE_OF_GNSS_MEASUREMENT_MASK)) \
                 << (SBP_GNSSINPUTTYPE_TYPE_OF_GNSS_MEASUREMENT_SHIFT)));    \
  } while (0)

#define SBP_GNSSINPUTTYPE_TYPE_OF_GNSS_MEASUREMENT_GNSS_POSITION (0)
#define SBP_GNSSINPUTTYPE_TYPE_OF_GNSS_MEASUREMENT_GNSS_VELOCITY_DOPPLER (1)
#define SBP_GNSSINPUTTYPE_TYPE_OF_GNSS_MEASUREMENT_GNSS_VELOCITY_DISPLACEMENT \
  (2)
#endif
/** Instruments the physical type of GNSS sensor input to the fuzed solution
 *
((m.desc|commentify)))
 */
typedef struct {
  u8 flags;
} sbp_gnss_input_type_t;

size_t sbp_packed_size_sbp_gnss_input_type_t(const sbp_gnss_input_type_t *msg);
s8 sbp_encode_sbp_gnss_input_type_t(uint8_t *buf, uint8_t len,
                                    uint8_t *n_written,
                                    const sbp_gnss_input_type_t *msg);
s8 sbp_decode_sbp_gnss_input_type_t(const uint8_t *buf, uint8_t len,
                                    uint8_t *n_read,
                                    sbp_gnss_input_type_t *msg);

int sbp_cmp_sbp_gnss_input_type_t(const sbp_gnss_input_type_t *a,
                                  const sbp_gnss_input_type_t *b);

#ifndef LIBSBP_LEGACY_SOLUTION_META_MESSAGES_H
#define SBP_IMUINPUTTYPE_TIME_STATUS_MASK (0x3)
#define SBP_IMUINPUTTYPE_TIME_STATUS_SHIFT (4u)
#define SBP_IMUINPUTTYPE_TIME_STATUS_GET(flags)      \
  (((flags) >> SBP_IMUINPUTTYPE_TIME_STATUS_SHIFT) & \
   SBP_IMUINPUTTYPE_TIME_STATUS_MASK)
#define SBP_IMUINPUTTYPE_TIME_STATUS_SET(flags, val)           \
  do {                                                         \
    ((flags) |= (((val) & (SBP_IMUINPUTTYPE_TIME_STATUS_MASK)) \
                 << (SBP_IMUINPUTTYPE_TIME_STATUS_SHIFT)));    \
  } while (0)

#define SBP_IMUINPUTTYPE_TIME_STATUS_REFERENCE_EPOCH_IS_START_OF_CURRENT_GPS_WEEK \
  (0)
#define SBP_IMUINPUTTYPE_TIME_STATUS_REFERENCE_EPOCH_IS_TIME_OF_SYSTEM_STARTUP \
  (1)
#define SBP_IMUINPUTTYPE_TIME_STATUS_REFERENCE_EPOCH_IS_UNKNOWN (2)
#define SBP_IMUINPUTTYPE_TIME_STATUS_REFERENCE_EPOCH_IS_LAST_PPS (3)
#define SBP_IMUINPUTTYPE_IMU_GRADE_MASK (0x3)
#define SBP_IMUINPUTTYPE_IMU_GRADE_SHIFT (2u)
#define SBP_IMUINPUTTYPE_IMU_GRADE_GET(flags)      \
  (((flags) >> SBP_IMUINPUTTYPE_IMU_GRADE_SHIFT) & \
   SBP_IMUINPUTTYPE_IMU_GRADE_MASK)
#define SBP_IMUINPUTTYPE_IMU_GRADE_SET(flags, val)           \
  do {                                                       \
    ((flags) |= (((val) & (SBP_IMUINPUTTYPE_IMU_GRADE_MASK)) \
                 << (SBP_IMUINPUTTYPE_IMU_GRADE_SHIFT)));    \
  } while (0)

#define SBP_IMUINPUTTYPE_IMU_GRADE_CONSUMER_GRADE (0)
#define SBP_IMUINPUTTYPE_IMU_GRADE_TACTICAL_GRADE (1)
#define SBP_IMUINPUTTYPE_IMU_GRADE_INTERMEDIATE_GRADE (2)
#define SBP_IMUINPUTTYPE_IMU_GRADE_SUPERIOR_GRADE (3)
#define SBP_IMUINPUTTYPE_IMU_ARCHITECTURE_MASK (0x3)
#define SBP_IMUINPUTTYPE_IMU_ARCHITECTURE_SHIFT (0u)
#define SBP_IMUINPUTTYPE_IMU_ARCHITECTURE_GET(flags)      \
  (((flags) >> SBP_IMUINPUTTYPE_IMU_ARCHITECTURE_SHIFT) & \
   SBP_IMUINPUTTYPE_IMU_ARCHITECTURE_MASK)
#define SBP_IMUINPUTTYPE_IMU_ARCHITECTURE_SET(flags, val)           \
  do {                                                              \
    ((flags) |= (((val) & (SBP_IMUINPUTTYPE_IMU_ARCHITECTURE_MASK)) \
                 << (SBP_IMUINPUTTYPE_IMU_ARCHITECTURE_SHIFT)));    \
  } while (0)

#define SBP_IMUINPUTTYPE_IMU_ARCHITECTURE_6_AXIS_MEMS (0)
#define SBP_IMUINPUTTYPE_IMU_ARCHITECTURE_OTHER_TYPE (1)
#endif
/** Provides detail about the IMU sensor, its timestamping mode, and its quality
for input to the fuzed solution

 *
((m.desc|commentify)))
 */
typedef struct {
  u8 flags;
} sbp_imu_input_type_t;

size_t sbp_packed_size_sbp_imu_input_type_t(const sbp_imu_input_type_t *msg);
s8 sbp_encode_sbp_imu_input_type_t(uint8_t *buf, uint8_t len,
                                   uint8_t *n_written,
                                   const sbp_imu_input_type_t *msg);
s8 sbp_decode_sbp_imu_input_type_t(const uint8_t *buf, uint8_t len,
                                   uint8_t *n_read, sbp_imu_input_type_t *msg);

int sbp_cmp_sbp_imu_input_type_t(const sbp_imu_input_type_t *a,
                                 const sbp_imu_input_type_t *b);

#ifndef LIBSBP_LEGACY_SOLUTION_META_MESSAGES_H
#define SBP_ODOINPUTTYPE_RATE_MASK (0x3)
#define SBP_ODOINPUTTYPE_RATE_SHIFT (4u)
#define SBP_ODOINPUTTYPE_RATE_GET(flags) \
  (((flags) >> SBP_ODOINPUTTYPE_RATE_SHIFT) & SBP_ODOINPUTTYPE_RATE_MASK)
#define SBP_ODOINPUTTYPE_RATE_SET(flags, val)           \
  do {                                                  \
    ((flags) |= (((val) & (SBP_ODOINPUTTYPE_RATE_MASK)) \
                 << (SBP_ODOINPUTTYPE_RATE_SHIFT)));    \
  } while (0)

#define SBP_ODOINPUTTYPE_RATE_FIXED_INCOMING_RATE (0)
#define SBP_ODOINPUTTYPE_RATE_TRIGGERED_BY_MINIMUM_DISTANCE_OR_SPEED (1)
#define SBP_ODOINPUTTYPE_ODOMETER_GRADE_MASK (0x3)
#define SBP_ODOINPUTTYPE_ODOMETER_GRADE_SHIFT (2u)
#define SBP_ODOINPUTTYPE_ODOMETER_GRADE_GET(flags)      \
  (((flags) >> SBP_ODOINPUTTYPE_ODOMETER_GRADE_SHIFT) & \
   SBP_ODOINPUTTYPE_ODOMETER_GRADE_MASK)
#define SBP_ODOINPUTTYPE_ODOMETER_GRADE_SET(flags, val)           \
  do {                                                            \
    ((flags) |= (((val) & (SBP_ODOINPUTTYPE_ODOMETER_GRADE_MASK)) \
                 << (SBP_ODOINPUTTYPE_ODOMETER_GRADE_SHIFT)));    \
  } while (0)

#define SBP_ODOINPUTTYPE_ODOMETER_GRADE_LOW_GRADE (0)
#define SBP_ODOINPUTTYPE_ODOMETER_GRADE_MEDIUM_GRADE (1)
#define SBP_ODOINPUTTYPE_ODOMETER_GRADE_SUPERIOR_GRADE (2)
#define SBP_ODOINPUTTYPE_ODOMETER_CLASS_MASK (0x3)
#define SBP_ODOINPUTTYPE_ODOMETER_CLASS_SHIFT (0u)
#define SBP_ODOINPUTTYPE_ODOMETER_CLASS_GET(flags)      \
  (((flags) >> SBP_ODOINPUTTYPE_ODOMETER_CLASS_SHIFT) & \
   SBP_ODOINPUTTYPE_ODOMETER_CLASS_MASK)
#define SBP_ODOINPUTTYPE_ODOMETER_CLASS_SET(flags, val)           \
  do {                                                            \
    ((flags) |= (((val) & (SBP_ODOINPUTTYPE_ODOMETER_CLASS_MASK)) \
                 << (SBP_ODOINPUTTYPE_ODOMETER_CLASS_SHIFT)));    \
  } while (0)

#define SBP_ODOINPUTTYPE_ODOMETER_CLASS_SINGLE_OR_AVERAGED_TICKS (0)
#define SBP_ODOINPUTTYPE_ODOMETER_CLASS_SINGLE_OR_AVERAGED_SPEED (1)
#define SBP_ODOINPUTTYPE_ODOMETER_CLASS_MULTI_DIMENSIONAL_TICKS (2)
#define SBP_ODOINPUTTYPE_ODOMETER_CLASS_MULTI_DIMENSIONAL_SPEED (3)
#endif
/** Provides detail about the Odometry sensor, its timestamping mode, and its
quality for input to the fuzed solution

 *
((m.desc|commentify)))
 */
typedef struct {
  u8 flags;
} sbp_odo_input_type_t;

size_t sbp_packed_size_sbp_odo_input_type_t(const sbp_odo_input_type_t *msg);
s8 sbp_encode_sbp_odo_input_type_t(uint8_t *buf, uint8_t len,
                                   uint8_t *n_written,
                                   const sbp_odo_input_type_t *msg);
s8 sbp_decode_sbp_odo_input_type_t(const uint8_t *buf, uint8_t len,
                                   uint8_t *n_read, sbp_odo_input_type_t *msg);

int sbp_cmp_sbp_odo_input_type_t(const sbp_odo_input_type_t *a,
                                 const sbp_odo_input_type_t *b);

#ifdef __cplusplus
}
static inline bool operator==(const sbp_solution_input_type_t &a,
                              const sbp_solution_input_type_t &b) {
  return sbp_cmp_sbp_solution_input_type_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_solution_input_type_t &a,
                              const sbp_solution_input_type_t &b) {
  return sbp_cmp_sbp_solution_input_type_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_solution_input_type_t &a,
                             const sbp_solution_input_type_t &b) {
  return sbp_cmp_sbp_solution_input_type_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_solution_input_type_t &a,
                              const sbp_solution_input_type_t &b) {
  return sbp_cmp_sbp_solution_input_type_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_solution_input_type_t &a,
                             const sbp_solution_input_type_t &b) {
  return sbp_cmp_sbp_solution_input_type_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_solution_input_type_t &a,
                              const sbp_solution_input_type_t &b) {
  return sbp_cmp_sbp_solution_input_type_t(&a, &b) >= 0;
}
static inline bool operator==(const sbp_msg_soln_meta_dep_a_t &a,
                              const sbp_msg_soln_meta_dep_a_t &b) {
  return sbp_cmp_sbp_msg_soln_meta_dep_a_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_soln_meta_dep_a_t &a,
                              const sbp_msg_soln_meta_dep_a_t &b) {
  return sbp_cmp_sbp_msg_soln_meta_dep_a_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_soln_meta_dep_a_t &a,
                             const sbp_msg_soln_meta_dep_a_t &b) {
  return sbp_cmp_sbp_msg_soln_meta_dep_a_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_soln_meta_dep_a_t &a,
                              const sbp_msg_soln_meta_dep_a_t &b) {
  return sbp_cmp_sbp_msg_soln_meta_dep_a_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_soln_meta_dep_a_t &a,
                             const sbp_msg_soln_meta_dep_a_t &b) {
  return sbp_cmp_sbp_msg_soln_meta_dep_a_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_soln_meta_dep_a_t &a,
                              const sbp_msg_soln_meta_dep_a_t &b) {
  return sbp_cmp_sbp_msg_soln_meta_dep_a_t(&a, &b) >= 0;
}
static inline bool operator==(const sbp_msg_soln_meta_t &a,
                              const sbp_msg_soln_meta_t &b) {
  return sbp_cmp_sbp_msg_soln_meta_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_soln_meta_t &a,
                              const sbp_msg_soln_meta_t &b) {
  return sbp_cmp_sbp_msg_soln_meta_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_soln_meta_t &a,
                             const sbp_msg_soln_meta_t &b) {
  return sbp_cmp_sbp_msg_soln_meta_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_soln_meta_t &a,
                              const sbp_msg_soln_meta_t &b) {
  return sbp_cmp_sbp_msg_soln_meta_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_soln_meta_t &a,
                             const sbp_msg_soln_meta_t &b) {
  return sbp_cmp_sbp_msg_soln_meta_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_soln_meta_t &a,
                              const sbp_msg_soln_meta_t &b) {
  return sbp_cmp_sbp_msg_soln_meta_t(&a, &b) >= 0;
}
static inline bool operator==(const sbp_gnss_input_type_t &a,
                              const sbp_gnss_input_type_t &b) {
  return sbp_cmp_sbp_gnss_input_type_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_gnss_input_type_t &a,
                              const sbp_gnss_input_type_t &b) {
  return sbp_cmp_sbp_gnss_input_type_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_gnss_input_type_t &a,
                             const sbp_gnss_input_type_t &b) {
  return sbp_cmp_sbp_gnss_input_type_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_gnss_input_type_t &a,
                              const sbp_gnss_input_type_t &b) {
  return sbp_cmp_sbp_gnss_input_type_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_gnss_input_type_t &a,
                             const sbp_gnss_input_type_t &b) {
  return sbp_cmp_sbp_gnss_input_type_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_gnss_input_type_t &a,
                              const sbp_gnss_input_type_t &b) {
  return sbp_cmp_sbp_gnss_input_type_t(&a, &b) >= 0;
}
static inline bool operator==(const sbp_imu_input_type_t &a,
                              const sbp_imu_input_type_t &b) {
  return sbp_cmp_sbp_imu_input_type_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_imu_input_type_t &a,
                              const sbp_imu_input_type_t &b) {
  return sbp_cmp_sbp_imu_input_type_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_imu_input_type_t &a,
                             const sbp_imu_input_type_t &b) {
  return sbp_cmp_sbp_imu_input_type_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_imu_input_type_t &a,
                              const sbp_imu_input_type_t &b) {
  return sbp_cmp_sbp_imu_input_type_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_imu_input_type_t &a,
                             const sbp_imu_input_type_t &b) {
  return sbp_cmp_sbp_imu_input_type_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_imu_input_type_t &a,
                              const sbp_imu_input_type_t &b) {
  return sbp_cmp_sbp_imu_input_type_t(&a, &b) >= 0;
}
static inline bool operator==(const sbp_odo_input_type_t &a,
                              const sbp_odo_input_type_t &b) {
  return sbp_cmp_sbp_odo_input_type_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_odo_input_type_t &a,
                              const sbp_odo_input_type_t &b) {
  return sbp_cmp_sbp_odo_input_type_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_odo_input_type_t &a,
                             const sbp_odo_input_type_t &b) {
  return sbp_cmp_sbp_odo_input_type_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_odo_input_type_t &a,
                              const sbp_odo_input_type_t &b) {
  return sbp_cmp_sbp_odo_input_type_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_odo_input_type_t &a,
                             const sbp_odo_input_type_t &b) {
  return sbp_cmp_sbp_odo_input_type_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_odo_input_type_t &a,
                              const sbp_odo_input_type_t &b) {
  return sbp_cmp_sbp_odo_input_type_t(&a, &b) >= 0;
}

#endif

#endif /* LIBSBP_NEW_SOLUTION_META_MESSAGES_H */
