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

SBP_PACK_START


/** Heading relative to True North
 *
 * This message reports the baseline heading pointing from the base station
 * to the rover relative to True North. The full GPS time is given by the
 * preceding MSG_GPS_TIME with the matching time-of-week (tow). It is intended
 * that time-matched RTK mode is used when the base station is moving.
 */
#define SBP_MSG_BASELINE_HEADING 0x020F
#define SBP_BASELINE_HEADING_FIX_MODE_MASK (0x7)
#define SBP_BASELINE_HEADING_FIX_MODE_SHIFT (0u)
#define SBP_BASELINE_HEADING_FIX_MODE_GET(flags) \
                             (((flags) >> SBP_BASELINE_HEADING_FIX_MODE_SHIFT) \
                             & SBP_BASELINE_HEADING_FIX_MODE_MASK)
#define SBP_BASELINE_HEADING_FIX_MODE_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_BASELINE_HEADING_FIX_MODE_MASK)) \
                             << (SBP_BASELINE_HEADING_FIX_MODE_SHIFT)));} while(0)
                             

#define SBP_BASELINE_HEADING_FIX_MODE_INVALID (0)
#define SBP_BASELINE_HEADING_FIX_MODE_DIFFERENTIAL_GNSS (2)
#define SBP_BASELINE_HEADING_FIX_MODE_FLOAT_RTK (3)
#define SBP_BASELINE_HEADING_FIX_MODE_FIXED_RTK (4)

typedef struct SBP_ATTR_PACKED {
  u32 tow;        /**< GPS Time of Week [ms] */
  u32 heading;    /**< Heading [mdeg] */
  u8 n_sats;     /**< Number of satellites used in solution */
  u8 flags;      /**< Status flags */
} msg_baseline_heading_t;
 

/** Quaternion 4 component vector
 *
 * This message reports the quaternion vector describing the vehicle body frame's orientation
 * with respect to a local-level NED frame. The components of the vector should sum to a unit
 * vector assuming that the LSB of each component as a value of 2^-31. This message will only
 * be available in future INS versions of Swift Products and is not produced by Piksi Multi 
 * or Duro.
 */
#define SBP_MSG_ORIENT_QUAT      0x0220
#define SBP_ORIENT_QUAT_INS_NAVIGATION_MODE_MASK (0x7)
#define SBP_ORIENT_QUAT_INS_NAVIGATION_MODE_SHIFT (0u)
#define SBP_ORIENT_QUAT_INS_NAVIGATION_MODE_GET(flags) \
                             (((flags) >> SBP_ORIENT_QUAT_INS_NAVIGATION_MODE_SHIFT) \
                             & SBP_ORIENT_QUAT_INS_NAVIGATION_MODE_MASK)
#define SBP_ORIENT_QUAT_INS_NAVIGATION_MODE_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_ORIENT_QUAT_INS_NAVIGATION_MODE_MASK)) \
                             << (SBP_ORIENT_QUAT_INS_NAVIGATION_MODE_SHIFT)));} while(0)
                             

#define SBP_ORIENT_QUAT_INS_NAVIGATION_MODE_INVALID (0)
#define SBP_ORIENT_QUAT_INS_NAVIGATION_MODE_VALID (1)

typedef struct SBP_ATTR_PACKED {
  u32 tow;           /**< GPS Time of Week [ms] */
  s32 w;             /**< Real component [2^-31] */
  s32 x;             /**< 1st imaginary component [2^-31] */
  s32 y;             /**< 2nd imaginary component [2^-31] */
  s32 z;             /**< 3rd imaginary component [2^-31] */
  float w_accuracy;    /**< Estimated standard deviation of w [N/A] */
  float x_accuracy;    /**< Estimated standard deviation of x [N/A] */
  float y_accuracy;    /**< Estimated standard deviation of y [N/A] */
  float z_accuracy;    /**< Estimated standard deviation of z [N/A] */
  u8 flags;         /**< Status flags */
} msg_orient_quat_t;
 

/** Euler angles
 *
 * This message reports the yaw, pitch, and roll angles of the vehicle body frame.
 * The rotations should applied intrinsically in the order yaw, pitch, and roll 
 * in order to rotate the from a frame aligned with the local-level NED frame 
 * to the vehicle body frame.  This message will only be available in future 
 * INS versions of Swift Products and is not produced by Piksi Multi or Duro.
 */
#define SBP_MSG_ORIENT_EULER     0x0221
#define SBP_ORIENT_EULER_INS_NAVIGATION_MODE_MASK (0x7)
#define SBP_ORIENT_EULER_INS_NAVIGATION_MODE_SHIFT (0u)
#define SBP_ORIENT_EULER_INS_NAVIGATION_MODE_GET(flags) \
                             (((flags) >> SBP_ORIENT_EULER_INS_NAVIGATION_MODE_SHIFT) \
                             & SBP_ORIENT_EULER_INS_NAVIGATION_MODE_MASK)
#define SBP_ORIENT_EULER_INS_NAVIGATION_MODE_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_ORIENT_EULER_INS_NAVIGATION_MODE_MASK)) \
                             << (SBP_ORIENT_EULER_INS_NAVIGATION_MODE_SHIFT)));} while(0)
                             

#define SBP_ORIENT_EULER_INS_NAVIGATION_MODE_INVALID (0)
#define SBP_ORIENT_EULER_INS_NAVIGATION_MODE_VALID (1)

typedef struct SBP_ATTR_PACKED {
  u32 tow;               /**< GPS Time of Week [ms] */
  s32 roll;              /**< rotation about the forward axis of the vehicle [microdegrees] */
  s32 pitch;             /**< rotation about the rightward axis of the vehicle [microdegrees] */
  s32 yaw;               /**< rotation about the downward axis of the vehicle [microdegrees] */
  float roll_accuracy;     /**< Estimated standard deviation of roll [degrees] */
  float pitch_accuracy;    /**< Estimated standard deviation of pitch [degrees] */
  float yaw_accuracy;      /**< Estimated standard deviation of yaw [degrees] */
  u8 flags;             /**< Status flags */
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
 * This message will only be available in future INS versions of Swift Products 
 * and is not produced by Piksi Multi or Duro.
 */
#define SBP_MSG_ANGULAR_RATE     0x0222
#define SBP_ANGULAR_RATE_INS_NAVIGATION_MODE_MASK (0x7)
#define SBP_ANGULAR_RATE_INS_NAVIGATION_MODE_SHIFT (0u)
#define SBP_ANGULAR_RATE_INS_NAVIGATION_MODE_GET(flags) \
                             (((flags) >> SBP_ANGULAR_RATE_INS_NAVIGATION_MODE_SHIFT) \
                             & SBP_ANGULAR_RATE_INS_NAVIGATION_MODE_MASK)
#define SBP_ANGULAR_RATE_INS_NAVIGATION_MODE_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_ANGULAR_RATE_INS_NAVIGATION_MODE_MASK)) \
                             << (SBP_ANGULAR_RATE_INS_NAVIGATION_MODE_SHIFT)));} while(0)
                             

#define SBP_ANGULAR_RATE_INS_NAVIGATION_MODE_INVALID (0)
#define SBP_ANGULAR_RATE_INS_NAVIGATION_MODE_VALID (1)

typedef struct SBP_ATTR_PACKED {
  u32 tow;      /**< GPS Time of Week [ms] */
  s32 x;        /**< angular rate about x axis [microdegrees/s] */
  s32 y;        /**< angular rate about y axis [microdegrees/s] */
  s32 z;        /**< angular rate about z axis [microdegrees/s] */
  u8 flags;    /**< Status flags */
} msg_angular_rate_t;
 

/** \} */
static inline void static_asserts_for_module_MSG_BASELINE_HEADING(void) {
#ifdef __cplusplus
static_assert(offsetof(msg_baseline_heading_t, tow ) == 0, "Offset of tow in msg_baseline_heading_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_baseline_heading_t, tow ) == 0, offset_of_tow_in_msg_baseline_heading_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_baseline_heading_t, heading ) == 0 + sizeof(u32), "Offset of heading in msg_baseline_heading_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_baseline_heading_t, heading ) == 0 + sizeof(u32), offset_of_heading_in_msg_baseline_heading_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_baseline_heading_t, n_sats ) == 0 + sizeof(u32) + sizeof(u32), "Offset of n_sats in msg_baseline_heading_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_baseline_heading_t, n_sats ) == 0 + sizeof(u32) + sizeof(u32), offset_of_n_sats_in_msg_baseline_heading_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_baseline_heading_t, flags ) == 0 + sizeof(u32) + sizeof(u32) + sizeof(u8), "Offset of flags in msg_baseline_heading_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_baseline_heading_t, flags ) == 0 + sizeof(u32) + sizeof(u32) + sizeof(u8), offset_of_flags_in_msg_baseline_heading_t_is_incorrect)
#endif
}

static inline void static_asserts_for_module_MSG_ORIENT_QUAT(void) {
#ifdef __cplusplus
static_assert(offsetof(msg_orient_quat_t, tow ) == 0, "Offset of tow in msg_orient_quat_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_orient_quat_t, tow ) == 0, offset_of_tow_in_msg_orient_quat_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_orient_quat_t, w ) == 0 + sizeof(u32), "Offset of w in msg_orient_quat_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_orient_quat_t, w ) == 0 + sizeof(u32), offset_of_w_in_msg_orient_quat_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_orient_quat_t, x ) == 0 + sizeof(u32) + sizeof(s32), "Offset of x in msg_orient_quat_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_orient_quat_t, x ) == 0 + sizeof(u32) + sizeof(s32), offset_of_x_in_msg_orient_quat_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_orient_quat_t, y ) == 0 + sizeof(u32) + sizeof(s32) + sizeof(s32), "Offset of y in msg_orient_quat_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_orient_quat_t, y ) == 0 + sizeof(u32) + sizeof(s32) + sizeof(s32), offset_of_y_in_msg_orient_quat_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_orient_quat_t, z ) == 0 + sizeof(u32) + sizeof(s32) + sizeof(s32) + sizeof(s32), "Offset of z in msg_orient_quat_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_orient_quat_t, z ) == 0 + sizeof(u32) + sizeof(s32) + sizeof(s32) + sizeof(s32), offset_of_z_in_msg_orient_quat_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_orient_quat_t, w_accuracy ) == 0 + sizeof(u32) + sizeof(s32) + sizeof(s32) + sizeof(s32) + sizeof(s32), "Offset of w_accuracy in msg_orient_quat_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_orient_quat_t, w_accuracy ) == 0 + sizeof(u32) + sizeof(s32) + sizeof(s32) + sizeof(s32) + sizeof(s32), offset_of_w_accuracy_in_msg_orient_quat_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_orient_quat_t, x_accuracy ) == 0 + sizeof(u32) + sizeof(s32) + sizeof(s32) + sizeof(s32) + sizeof(s32) + sizeof(float), "Offset of x_accuracy in msg_orient_quat_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_orient_quat_t, x_accuracy ) == 0 + sizeof(u32) + sizeof(s32) + sizeof(s32) + sizeof(s32) + sizeof(s32) + sizeof(float), offset_of_x_accuracy_in_msg_orient_quat_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_orient_quat_t, y_accuracy ) == 0 + sizeof(u32) + sizeof(s32) + sizeof(s32) + sizeof(s32) + sizeof(s32) + sizeof(float) + sizeof(float), "Offset of y_accuracy in msg_orient_quat_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_orient_quat_t, y_accuracy ) == 0 + sizeof(u32) + sizeof(s32) + sizeof(s32) + sizeof(s32) + sizeof(s32) + sizeof(float) + sizeof(float), offset_of_y_accuracy_in_msg_orient_quat_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_orient_quat_t, z_accuracy ) == 0 + sizeof(u32) + sizeof(s32) + sizeof(s32) + sizeof(s32) + sizeof(s32) + sizeof(float) + sizeof(float) + sizeof(float), "Offset of z_accuracy in msg_orient_quat_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_orient_quat_t, z_accuracy ) == 0 + sizeof(u32) + sizeof(s32) + sizeof(s32) + sizeof(s32) + sizeof(s32) + sizeof(float) + sizeof(float) + sizeof(float), offset_of_z_accuracy_in_msg_orient_quat_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_orient_quat_t, flags ) == 0 + sizeof(u32) + sizeof(s32) + sizeof(s32) + sizeof(s32) + sizeof(s32) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float), "Offset of flags in msg_orient_quat_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_orient_quat_t, flags ) == 0 + sizeof(u32) + sizeof(s32) + sizeof(s32) + sizeof(s32) + sizeof(s32) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float), offset_of_flags_in_msg_orient_quat_t_is_incorrect)
#endif
}

static inline void static_asserts_for_module_MSG_ORIENT_EULER(void) {
#ifdef __cplusplus
static_assert(offsetof(msg_orient_euler_t, tow ) == 0, "Offset of tow in msg_orient_euler_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_orient_euler_t, tow ) == 0, offset_of_tow_in_msg_orient_euler_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_orient_euler_t, roll ) == 0 + sizeof(u32), "Offset of roll in msg_orient_euler_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_orient_euler_t, roll ) == 0 + sizeof(u32), offset_of_roll_in_msg_orient_euler_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_orient_euler_t, pitch ) == 0 + sizeof(u32) + sizeof(s32), "Offset of pitch in msg_orient_euler_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_orient_euler_t, pitch ) == 0 + sizeof(u32) + sizeof(s32), offset_of_pitch_in_msg_orient_euler_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_orient_euler_t, yaw ) == 0 + sizeof(u32) + sizeof(s32) + sizeof(s32), "Offset of yaw in msg_orient_euler_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_orient_euler_t, yaw ) == 0 + sizeof(u32) + sizeof(s32) + sizeof(s32), offset_of_yaw_in_msg_orient_euler_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_orient_euler_t, roll_accuracy ) == 0 + sizeof(u32) + sizeof(s32) + sizeof(s32) + sizeof(s32), "Offset of roll_accuracy in msg_orient_euler_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_orient_euler_t, roll_accuracy ) == 0 + sizeof(u32) + sizeof(s32) + sizeof(s32) + sizeof(s32), offset_of_roll_accuracy_in_msg_orient_euler_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_orient_euler_t, pitch_accuracy ) == 0 + sizeof(u32) + sizeof(s32) + sizeof(s32) + sizeof(s32) + sizeof(float), "Offset of pitch_accuracy in msg_orient_euler_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_orient_euler_t, pitch_accuracy ) == 0 + sizeof(u32) + sizeof(s32) + sizeof(s32) + sizeof(s32) + sizeof(float), offset_of_pitch_accuracy_in_msg_orient_euler_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_orient_euler_t, yaw_accuracy ) == 0 + sizeof(u32) + sizeof(s32) + sizeof(s32) + sizeof(s32) + sizeof(float) + sizeof(float), "Offset of yaw_accuracy in msg_orient_euler_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_orient_euler_t, yaw_accuracy ) == 0 + sizeof(u32) + sizeof(s32) + sizeof(s32) + sizeof(s32) + sizeof(float) + sizeof(float), offset_of_yaw_accuracy_in_msg_orient_euler_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_orient_euler_t, flags ) == 0 + sizeof(u32) + sizeof(s32) + sizeof(s32) + sizeof(s32) + sizeof(float) + sizeof(float) + sizeof(float), "Offset of flags in msg_orient_euler_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_orient_euler_t, flags ) == 0 + sizeof(u32) + sizeof(s32) + sizeof(s32) + sizeof(s32) + sizeof(float) + sizeof(float) + sizeof(float), offset_of_flags_in_msg_orient_euler_t_is_incorrect)
#endif
}

static inline void static_asserts_for_module_MSG_ANGULAR_RATE(void) {
#ifdef __cplusplus
static_assert(offsetof(msg_angular_rate_t, tow ) == 0, "Offset of tow in msg_angular_rate_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_angular_rate_t, tow ) == 0, offset_of_tow_in_msg_angular_rate_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_angular_rate_t, x ) == 0 + sizeof(u32), "Offset of x in msg_angular_rate_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_angular_rate_t, x ) == 0 + sizeof(u32), offset_of_x_in_msg_angular_rate_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_angular_rate_t, y ) == 0 + sizeof(u32) + sizeof(s32), "Offset of y in msg_angular_rate_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_angular_rate_t, y ) == 0 + sizeof(u32) + sizeof(s32), offset_of_y_in_msg_angular_rate_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_angular_rate_t, z ) == 0 + sizeof(u32) + sizeof(s32) + sizeof(s32), "Offset of z in msg_angular_rate_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_angular_rate_t, z ) == 0 + sizeof(u32) + sizeof(s32) + sizeof(s32), offset_of_z_in_msg_angular_rate_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_angular_rate_t, flags ) == 0 + sizeof(u32) + sizeof(s32) + sizeof(s32) + sizeof(s32), "Offset of flags in msg_angular_rate_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_angular_rate_t, flags ) == 0 + sizeof(u32) + sizeof(s32) + sizeof(s32) + sizeof(s32), offset_of_flags_in_msg_angular_rate_t_is_incorrect)
#endif
}


SBP_PACK_END

#endif /* LIBSBP_ORIENTATION_MESSAGES_H */
