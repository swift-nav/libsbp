/*
 * Copyright (C) 2015-2018 Swift Navigation Inc.
 * Contact: Swift Navigation <dev@swiftnav.com>
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
 * gyroscope readings. The sense of the measurements are to be aligned with 
 * the indications on the device itself.
 */
#define SBP_MSG_IMU_RAW 0x0900
typedef struct __attribute__((packed)) {
  u32 tow;      /**< Milliseconds since start of GPS week. If the high bit is set, the
time is unknown or invalid.
 [ms] */
  u8 tow_f;    /**< Milliseconds since start of GPS week, fractional part
 [ms / 256] */
  s16 acc_x;    /**< Acceleration in the IMU frame X axis */
  s16 acc_y;    /**< Acceleration in the IMU frame Y axis */
  s16 acc_z;    /**< Acceleration in the IMU frame Z axis */
  s16 gyr_x;    /**< Angular rate around IMU frame X axis */
  s16 gyr_y;    /**< Angular rate around IMU frame Y axis */
  s16 gyr_z;    /**< Angular rate around IMU frame Z axis */
} msg_imu_raw_t;


/** Auxiliary IMU data
 *
 * Auxiliary data specific to a particular IMU. The `imu_type` field will
 * always be consistent but the rest of the payload is device specific and
 * depends on the value of `imu_type`.
 */
#define SBP_MSG_IMU_AUX 0x0901
typedef struct __attribute__((packed)) {
  u8 imu_type;    /**< IMU type */
  s16 temp;        /**< Raw IMU temperature */
  u8 imu_conf;    /**< IMU configuration */
} msg_imu_aux_t;


/** \} */

#endif /* LIBSBP_IMU_MESSAGES_H */