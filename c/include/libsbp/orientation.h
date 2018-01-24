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
 * Automatically generated from yaml/swiftnav/sbp/orientation.yaml
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

/** \defgroup orientation Orientation
 *
 * * Orientation Messages
 * \{ */

#ifndef LIBSBP_ORIENTATION_MESSAGES_H
#define LIBSBP_ORIENTATION_MESSAGES_H

#include "common.h"


/** Heading relative to True North
 *
 * This message reports the baseline heading pointing from the base station
 * to the rover relative to True North. The full GPS time is given by the
 * preceding MSG_GPS_TIME with the matching time-of-week (tow). It is intended
 * that time-matched RTK mode is used when the base station is moving.
 */
#define SBP_MSG_BASELINE_HEADING 0x020F
typedef struct __attribute__((packed)) {
  u32 tow;        /**< GPS Time of Week [ms] */
  u32 heading;    /**< Heading [mdeg] */
  u8 n_sats;     /**< Number of satellites used in solution */
  u8 flags;      /**< Status flags */
} msg_baseline_heading_t;


/** Quaternion 4 component vector
 *
 * This message reports the quaternion vector describing the vehicle body frame's orientation
 * with respect to a local-level NED frame. The components of the vector should sum to a unit
 * vector assuming that the LSB of each component as a value of 2^-31. 
 */
#define SBP_MSG_ORIENT_QUAT      0x0220
typedef struct __attribute__((packed)) {
  u32 tow;      /**< GPS Time of Week [ms] */
  s32 w;        /**< Real component [2^-31] */
  s32 x;        /**< 1st imaginary component [2^-31] */
  s32 y;        /**< 2nd imaginary component [2^-31] */
  s32 z;        /**< 3rd imaginary component [2^-31] */
  float acc_w;    /**< Estimated standard deviation of w [N/A] */
  float acc_x;    /**< Estimated standard deviation of x [N/A] */
  float acc_y;    /**< Estimated standard deviation of y [N/A] */
  float acc_z;    /**< Estimated standard deviation of z [N/A] */
  u8 flags;    /**< Status flags */
} msg_orient_quat_t;


/** Euler angles
 *
 * This message reports the yaw, pitch, and roll angles of the vehicle body frame.
 * The rotations should applied intrinsically in the order yaw, pitch, and roll 
 * in order to rotate the from a frame aligned with the local-level NED frame 
 * to the vehicle body frame.
 */
#define SBP_MSG_ORIENT_EULER     0x0221
typedef struct __attribute__((packed)) {
  u32 tow;          /**< GPS Time of Week [ms] */
  s32 roll;         /**< rotation about the forward axis of the vehicle [microdegrees] */
  s32 pitch;        /**< rotation about the rightward axis of the vehicle [microdegrees] */
  s32 yaw;          /**< rotation about the downward axis of the vehicle [microdegrees] */
  float var_roll;     /**< Estimated standard deviation of roll [degrees] */
  float var_pitch;    /**< Estimated standard deviation of pitch [degrees] */
  float var_yaw;      /**< Estimated standard deviation of yaw [degrees] */
  u8 flags;        /**< Status flags */
} msg_orient_euler_t;


/** Vehicle Body Frame instantaneous angular rates
 *
 * This message reports the orientation rates in the vehicle body frame. 
 * The values represent the measurements a strapped down gyroscope would 
 * make and are not equivalent to the time derivative of the Euler angles.
 * The orientation and origin of the user frame is specified via device settings.
 * By convention, the vehicle x-axis is expected to be aligned with the forward
 * direction, while the vehicle y-axis is expected to be aligned with the right
 * direction, and the vehicle z-axis should be aligned with the down direction.
 */
#define SBP_MSG_ANGULAR_RATE     0x0222
typedef struct __attribute__((packed)) {
  u32 tow;      /**< GPS Time of Week [ms] */
  s32 x;        /**< angular rate about x axis [microdegrees/s] */
  s32 y;        /**< angular rate about y axis [microdegrees/s] */
  s32 z;        /**< angular rate about z axis [microdegrees/s] */
  u8 flags;    /**< Status flags */
} msg_angular_rate_t;


/** \} */

#endif /* LIBSBP_ORIENTATION_MESSAGES_H */