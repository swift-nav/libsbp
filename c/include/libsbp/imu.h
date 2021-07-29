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
 * Automatically generated from yaml/swiftnav/sbp/imu.yaml
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

/** \defgroup imu Imu
 *
 * Inertial Measurement Unit (IMU) messages.
 * \{ */

#ifndef LIBSBP_IMU_MESSAGES_H
#define LIBSBP_IMU_MESSAGES_H

#include "common.h"

SBP_PACK_START

/** Raw IMU data
 *
 * Raw data from the Inertial Measurement Unit, containing accelerometer and
 * gyroscope readings. The sense of the measurements are to be aligned with
 * the indications on the device itself. Measurement units, which are specific
 * to the device hardware and settings, are communicated via the MSG_IMU_AUX
 * message. If using "time since startup" time tags, the receiving end will
 * expect a `MSG_GNSS_TIME_OFFSET` when a PVT fix becomes available to
 * synchronise IMU measurements with GNSS. The timestamp must wrap around to
 * zero when reaching one week (604800 seconds).
 *
 * The time-tagging mode should not change throughout a run.
 */
#define SBP_MSG_IMU_RAW 0x0900
#define SBP_IMU_RAW_TIME_STATUS_MASK (0x3)
#define SBP_IMU_RAW_TIME_STATUS_SHIFT (30u)
#define SBP_IMU_RAW_TIME_STATUS_GET(flags) \
  (((flags) >> SBP_IMU_RAW_TIME_STATUS_SHIFT) & SBP_IMU_RAW_TIME_STATUS_MASK)
#define SBP_IMU_RAW_TIME_STATUS_SET(flags, val)           \
  do {                                                    \
    ((flags) |= (((val) & (SBP_IMU_RAW_TIME_STATUS_MASK)) \
                 << (SBP_IMU_RAW_TIME_STATUS_SHIFT)));    \
  } while (0)

#define SBP_IMU_RAW_TIME_STATUS_REFERENCE_EPOCH_IS_START_OF_CURRENT_GPS_WEEK (0)
#define SBP_IMU_RAW_TIME_STATUS_REFERENCE_EPOCH_IS_TIME_OF_SYSTEM_STARTUP (1)
#define SBP_IMU_RAW_TIME_STATUS_REFERENCE_EPOCH_IS_UNKNOWN (2)
#define SBP_IMU_RAW_TIME_STATUS_REFERENCE_EPOCH_IS_LAST_PPS (3)
#define SBP_IMU_RAW_TIME_SINCE_REFERENCE_EPOCH_IN_MILLISECONDS_MASK (0x3fffffff)
#define SBP_IMU_RAW_TIME_SINCE_REFERENCE_EPOCH_IN_MILLISECONDS_SHIFT (0u)
#define SBP_IMU_RAW_TIME_SINCE_REFERENCE_EPOCH_IN_MILLISECONDS_GET(flags)      \
  (((flags) >> SBP_IMU_RAW_TIME_SINCE_REFERENCE_EPOCH_IN_MILLISECONDS_SHIFT) & \
   SBP_IMU_RAW_TIME_SINCE_REFERENCE_EPOCH_IN_MILLISECONDS_MASK)
#define SBP_IMU_RAW_TIME_SINCE_REFERENCE_EPOCH_IN_MILLISECONDS_SET(flags, val) \
  do {                                                                         \
    ((flags) |=                                                                \
     (((val) & (SBP_IMU_RAW_TIME_SINCE_REFERENCE_EPOCH_IN_MILLISECONDS_MASK))  \
      << (SBP_IMU_RAW_TIME_SINCE_REFERENCE_EPOCH_IN_MILLISECONDS_SHIFT)));     \
  } while (0)

typedef struct SBP_ATTR_PACKED {
  u32 tow;   /**< Milliseconds since reference epoch and time status. */
  u8 tow_f;  /**< Milliseconds since reference epoch, fractional part [ms / 256]
              */
  s16 acc_x; /**< Acceleration in the IMU frame X axis */
  s16 acc_y; /**< Acceleration in the IMU frame Y axis */
  s16 acc_z; /**< Acceleration in the IMU frame Z axis */
  s16 gyr_x; /**< Angular rate around IMU frame X axis */
  s16 gyr_y; /**< Angular rate around IMU frame Y axis */
  s16 gyr_z; /**< Angular rate around IMU frame Z axis */
} msg_imu_raw_t;

/** Auxiliary IMU data
 *
 * Auxiliary data specific to a particular IMU. The `imu_type` field will
 * always be consistent but the rest of the payload is device specific and
 * depends on the value of `imu_type`.
 */
#define SBP_MSG_IMU_AUX 0x0901
#define SBP_IMU_AUX_IMU_TYPE_MASK (0xff)
#define SBP_IMU_AUX_IMU_TYPE_SHIFT (0u)
#define SBP_IMU_AUX_IMU_TYPE_GET(flags) \
  (((flags) >> SBP_IMU_AUX_IMU_TYPE_SHIFT) & SBP_IMU_AUX_IMU_TYPE_MASK)
#define SBP_IMU_AUX_IMU_TYPE_SET(flags, val)                                   \
  do {                                                                         \
    ((flags) |=                                                                \
     (((val) & (SBP_IMU_AUX_IMU_TYPE_MASK)) << (SBP_IMU_AUX_IMU_TYPE_SHIFT))); \
  } while (0)

#define SBP_IMU_AUX_IMU_TYPE_BOSCH_BMI160 (0)
#define SBP_IMU_AUX_IMU_TYPE_ST_MICROELECTRONICS_ASM330LLH (1)
#define SBP_IMU_AUX_GYROSCOPE_RANGE_MASK (0xf)
#define SBP_IMU_AUX_GYROSCOPE_RANGE_SHIFT (4u)
#define SBP_IMU_AUX_GYROSCOPE_RANGE_GET(flags)      \
  (((flags) >> SBP_IMU_AUX_GYROSCOPE_RANGE_SHIFT) & \
   SBP_IMU_AUX_GYROSCOPE_RANGE_MASK)
#define SBP_IMU_AUX_GYROSCOPE_RANGE_SET(flags, val)           \
  do {                                                        \
    ((flags) |= (((val) & (SBP_IMU_AUX_GYROSCOPE_RANGE_MASK)) \
                 << (SBP_IMU_AUX_GYROSCOPE_RANGE_SHIFT)));    \
  } while (0)

#define SBP_IMU_AUX_GYROSCOPE_RANGE__2000_DEG__S (0)
#define SBP_IMU_AUX_GYROSCOPE_RANGE_2000_DEG_S (0)
#define SBP_IMU_AUX_GYROSCOPE_RANGE__1000_DEG__S (1)
#define SBP_IMU_AUX_GYROSCOPE_RANGE_1000_DEG_S (1)
#define SBP_IMU_AUX_GYROSCOPE_RANGE__500_DEG__S (2)
#define SBP_IMU_AUX_GYROSCOPE_RANGE_500_DEG_S (2)
#define SBP_IMU_AUX_GYROSCOPE_RANGE__250_DEG__S (3)
#define SBP_IMU_AUX_GYROSCOPE_RANGE_250_DEG_S (3)
#define SBP_IMU_AUX_GYROSCOPE_RANGE__125_DEG__S (4)
#define SBP_IMU_AUX_GYROSCOPE_RANGE_125_DEG_S (4)
#define SBP_IMU_AUX_ACCELEROMETER_RANGE_MASK (0xf)
#define SBP_IMU_AUX_ACCELEROMETER_RANGE_SHIFT (0u)
#define SBP_IMU_AUX_ACCELEROMETER_RANGE_GET(flags)      \
  (((flags) >> SBP_IMU_AUX_ACCELEROMETER_RANGE_SHIFT) & \
   SBP_IMU_AUX_ACCELEROMETER_RANGE_MASK)
#define SBP_IMU_AUX_ACCELEROMETER_RANGE_SET(flags, val)           \
  do {                                                            \
    ((flags) |= (((val) & (SBP_IMU_AUX_ACCELEROMETER_RANGE_MASK)) \
                 << (SBP_IMU_AUX_ACCELEROMETER_RANGE_SHIFT)));    \
  } while (0)

#define SBP_IMU_AUX_ACCELEROMETER_RANGE__2G (0)
#define SBP_IMU_AUX_ACCELEROMETER_RANGE_2G (0)
#define SBP_IMU_AUX_ACCELEROMETER_RANGE__4G (1)
#define SBP_IMU_AUX_ACCELEROMETER_RANGE_4G (1)
#define SBP_IMU_AUX_ACCELEROMETER_RANGE__8G (2)
#define SBP_IMU_AUX_ACCELEROMETER_RANGE_8G (2)
#define SBP_IMU_AUX_ACCELEROMETER_RANGE__16G (3)
#define SBP_IMU_AUX_ACCELEROMETER_RANGE_16G (3)

typedef struct SBP_ATTR_PACKED {
  u8 imu_type; /**< IMU type */
  s16 temp;    /**< Raw IMU temperature */
  u8 imu_conf; /**< IMU configuration */
} msg_imu_aux_t;

/** \} */

SBP_PACK_END

#endif /* LIBSBP_IMU_MESSAGES_H */