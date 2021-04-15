/*
 * Copyright (C) 2021 Swift Navigation Inc.
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

#ifndef LIBSBP_CPP_IMU_MESSAGES_H
#define LIBSBP_CPP_IMU_MESSAGES_H

#include <cstddef>
#include <libsbp/common.h>
#include <libsbp/sbp.h>

namespace sbp {
  
  /**
   * Raw IMU data
   *
   * Raw data from the Inertial Measurement Unit, containing accelerometer and
   * gyroscope readings. The sense of the measurements are to be aligned with 
   * the indications on the device itself. Measurement units, which are specific to the
   * device hardware and settings, are communicated via the MSG_IMU_AUX message.
   * If using "time since startup" time tags, the receiving end will expect a
   * `MSG_GNSS_TIME_OFFSET` when a PVT fix becomes available to synchronise IMU measurements
   * with GNSS. The timestamp must wrap around to zero when reaching one week (604800 seconds).
   * 
   * The time-tagging mode should not change throughout a run.
   */
  constexpr u16 MSG_IMU_RAW = 0x0900;

  
  struct SBP_ATTR_PACKED MsgImuRaw {
    u32 tow /** Milliseconds since reference epoch and time status.
 */
    u8 tow_f /** Milliseconds since reference epoch, fractional part
 [ms / 256] */
    s16 acc_x /** Acceleration in the IMU frame X axis */
    s16 acc_y /** Acceleration in the IMU frame Y axis */
    s16 acc_z /** Acceleration in the IMU frame Z axis */
    s16 gyr_x /** Angular rate around IMU frame X axis */
    s16 gyr_y /** Angular rate around IMU frame Y axis */
    s16 gyr_z /** Angular rate around IMU frame Z axis */
  };

  
  /**
   * Auxiliary IMU data
   *
   * Auxiliary data specific to a particular IMU. The `imu_type` field will
   * always be consistent but the rest of the payload is device specific and
   * depends on the value of `imu_type`.
   */
  constexpr u16 MSG_IMU_AUX = 0x0901;

  
  struct SBP_ATTR_PACKED MsgImuAux {
    u8 imu_type /** IMU type */
    s16 temp /** Raw IMU temperature */
    u8 imu_conf /** IMU configuration */
  };

  

}  // namespace sbp

#endif /* LIBSBP_CPP_IMU_MESSAGES_H */