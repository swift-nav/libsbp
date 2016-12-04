/*
 * Copyright (C) 2015 Swift Navigation Inc.
 * Contact: Fergus Noble <fergus@swift-nav.com>
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
 * * Inertial Measurement Unit (IMU) messages.
 * \{ */

#ifndef LIBSBP_IMU_MESSAGES_H
#define LIBSBP_IMU_MESSAGES_H

#include "common.h"


/** Raw IMU data
 *
 * Raw data from the Inertial Measurement Unit, containing accelerometer and
 * gyroscope readings.
 */
#define SBP_MSG_IMU_RAW 0x0900
typedef struct __attribute__((packed)) {
  u32 tow;      /**< Milliseconds since start of GPS week. If the high bit is set, the
time is unknown or invalid.
 [ms] */
  u8 tow_f;    /**< Milliseconds since start of GPS week, fractional part
 [ms / 256] */
  s16 acc_x;    /**< Acceleration in the body frame X axis */
  s16 acc_y;    /**< Acceleration in the body frame Y axis */
  s16 acc_z;    /**< Acceleration in the body frame Z axis */
  s16 gyr_x;    /**< Angular rate around the body frame X axis */
  s16 gyr_y;    /**< Angular rate around the body frame Y axis */
  s16 gyr_z;    /**< Angular rate around the body frame Z axis */
} msg_imu_raw_t;


/** \} */

#endif /* LIBSBP_IMU_MESSAGES_H */