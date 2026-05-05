/*
 * Copyright (C) 2015-2021 Swift Navigation Inc.
 * Contact: https://support.swiftnav.com
 *
 * This source is subject to the license found in the file 'LICENSE' which must
 * be distributed together with this source. All other rights reserved.
 *
 * THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
 * EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
 */

/*****************************************************************************
 * Automatically generated from yaml/swiftnav/sbp/orientation.yaml
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

#ifndef LIBSBP_ORIENTATION_MACROS_H
#define LIBSBP_ORIENTATION_MACROS_H

#define SBP_BASELINE_HEADING_FIX_MODE_MASK (0x7u)
#define SBP_BASELINE_HEADING_FIX_MODE_SHIFT (0u)
#define SBP_BASELINE_HEADING_FIX_MODE_GET(flags)               \
  ((u8)((u8)((flags) >> SBP_BASELINE_HEADING_FIX_MODE_SHIFT) & \
        SBP_BASELINE_HEADING_FIX_MODE_MASK))
#define SBP_BASELINE_HEADING_FIX_MODE_SET(flags, val)                      \
  do {                                                                     \
    (flags) = (u8)((flags & (~(SBP_BASELINE_HEADING_FIX_MODE_MASK          \
                               << SBP_BASELINE_HEADING_FIX_MODE_SHIFT))) | \
                   (((val) & (SBP_BASELINE_HEADING_FIX_MODE_MASK))         \
                    << (SBP_BASELINE_HEADING_FIX_MODE_SHIFT)));            \
  } while (0)

#define SBP_BASELINE_HEADING_FIX_MODE_INVALID (0)
#define SBP_BASELINE_HEADING_FIX_MODE_DIFFERENTIAL_GNSS (2)
#define SBP_BASELINE_HEADING_FIX_MODE_FLOAT_RTK (3)
#define SBP_BASELINE_HEADING_FIX_MODE_FIXED_RTK (4)
/**
 * Encoded length of sbp_msg_baseline_heading_t
 */
#define SBP_MSG_BASELINE_HEADING_ENCODED_LEN 10u

#define SBP_ORIENT_QUAT_INS_NAVIGATION_MODE_MASK (0x7u)
#define SBP_ORIENT_QUAT_INS_NAVIGATION_MODE_SHIFT (0u)
#define SBP_ORIENT_QUAT_INS_NAVIGATION_MODE_GET(flags)               \
  ((u8)((u8)((flags) >> SBP_ORIENT_QUAT_INS_NAVIGATION_MODE_SHIFT) & \
        SBP_ORIENT_QUAT_INS_NAVIGATION_MODE_MASK))
#define SBP_ORIENT_QUAT_INS_NAVIGATION_MODE_SET(flags, val)                \
  do {                                                                     \
    (flags) =                                                              \
        (u8)((flags & (~(SBP_ORIENT_QUAT_INS_NAVIGATION_MODE_MASK          \
                         << SBP_ORIENT_QUAT_INS_NAVIGATION_MODE_SHIFT))) | \
             (((val) & (SBP_ORIENT_QUAT_INS_NAVIGATION_MODE_MASK))         \
              << (SBP_ORIENT_QUAT_INS_NAVIGATION_MODE_SHIFT)));            \
  } while (0)

#define SBP_ORIENT_QUAT_INS_NAVIGATION_MODE_INVALID (0)
#define SBP_ORIENT_QUAT_INS_NAVIGATION_MODE_VALID (1)
/**
 * Encoded length of sbp_msg_orient_quat_t
 */
#define SBP_MSG_ORIENT_QUAT_ENCODED_LEN 37u

#define SBP_ORIENT_EULER_INS_NAVIGATION_MODE_MASK (0x7u)
#define SBP_ORIENT_EULER_INS_NAVIGATION_MODE_SHIFT (0u)
#define SBP_ORIENT_EULER_INS_NAVIGATION_MODE_GET(flags)               \
  ((u8)((u8)((flags) >> SBP_ORIENT_EULER_INS_NAVIGATION_MODE_SHIFT) & \
        SBP_ORIENT_EULER_INS_NAVIGATION_MODE_MASK))
#define SBP_ORIENT_EULER_INS_NAVIGATION_MODE_SET(flags, val)                \
  do {                                                                      \
    (flags) =                                                               \
        (u8)((flags & (~(SBP_ORIENT_EULER_INS_NAVIGATION_MODE_MASK          \
                         << SBP_ORIENT_EULER_INS_NAVIGATION_MODE_SHIFT))) | \
             (((val) & (SBP_ORIENT_EULER_INS_NAVIGATION_MODE_MASK))         \
              << (SBP_ORIENT_EULER_INS_NAVIGATION_MODE_SHIFT)));            \
  } while (0)

#define SBP_ORIENT_EULER_INS_NAVIGATION_MODE_INVALID (0)
#define SBP_ORIENT_EULER_INS_NAVIGATION_MODE_VALID (1)
/**
 * Encoded length of sbp_msg_orient_euler_t
 */
#define SBP_MSG_ORIENT_EULER_ENCODED_LEN 29u

#define SBP_ANGULAR_RATE_INS_NAVIGATION_MODE_MASK (0x7u)
#define SBP_ANGULAR_RATE_INS_NAVIGATION_MODE_SHIFT (0u)
#define SBP_ANGULAR_RATE_INS_NAVIGATION_MODE_GET(flags)               \
  ((u8)((u8)((flags) >> SBP_ANGULAR_RATE_INS_NAVIGATION_MODE_SHIFT) & \
        SBP_ANGULAR_RATE_INS_NAVIGATION_MODE_MASK))
#define SBP_ANGULAR_RATE_INS_NAVIGATION_MODE_SET(flags, val)                \
  do {                                                                      \
    (flags) =                                                               \
        (u8)((flags & (~(SBP_ANGULAR_RATE_INS_NAVIGATION_MODE_MASK          \
                         << SBP_ANGULAR_RATE_INS_NAVIGATION_MODE_SHIFT))) | \
             (((val) & (SBP_ANGULAR_RATE_INS_NAVIGATION_MODE_MASK))         \
              << (SBP_ANGULAR_RATE_INS_NAVIGATION_MODE_SHIFT)));            \
  } while (0)

#define SBP_ANGULAR_RATE_INS_NAVIGATION_MODE_INVALID (0)
#define SBP_ANGULAR_RATE_INS_NAVIGATION_MODE_VALID (1)
/**
 * Encoded length of sbp_msg_angular_rate_t
 */
#define SBP_MSG_ANGULAR_RATE_ENCODED_LEN 17u

#define SBP_ORIENT_QUAT_COV_COVARIANCE_PARAMETERIZATION_MASK (0x3u)
#define SBP_ORIENT_QUAT_COV_COVARIANCE_PARAMETERIZATION_SHIFT (5u)
#define SBP_ORIENT_QUAT_COV_COVARIANCE_PARAMETERIZATION_GET(flags)             \
  ((u8)(                                                                       \
      (u8)((flags) >> SBP_ORIENT_QUAT_COV_COVARIANCE_PARAMETERIZATION_SHIFT) & \
      SBP_ORIENT_QUAT_COV_COVARIANCE_PARAMETERIZATION_MASK))
#define SBP_ORIENT_QUAT_COV_COVARIANCE_PARAMETERIZATION_SET(flags, val)        \
  do {                                                                         \
    (flags) =                                                                  \
        (u8)((flags &                                                          \
              (~(SBP_ORIENT_QUAT_COV_COVARIANCE_PARAMETERIZATION_MASK          \
                 << SBP_ORIENT_QUAT_COV_COVARIANCE_PARAMETERIZATION_SHIFT))) | \
             (((val) & (SBP_ORIENT_QUAT_COV_COVARIANCE_PARAMETERIZATION_MASK)) \
              << (SBP_ORIENT_QUAT_COV_COVARIANCE_PARAMETERIZATION_SHIFT)));    \
  } while (0)

#define SBP_ORIENT_QUAT_COV_COVARIANCE_PARAMETERIZATION_SMALL_ANGLE_ROTATION_ERRORS_ABOUT_THE_AXES_OF_THE_GLOBAL_FRAME_GIVEN_BY_THE_QUATERNION_FRAME_FIELD \
  (0)
#define SBP_ORIENT_QUAT_COV_COVARIANCE_PARAMETERIZATION_SMALL_ANGLE_ROTATION_ERRORS_ABOUT_THE_BODYVEHICLE_FRAME_AXES \
  (1)
#define SBP_ORIENT_QUAT_COV_COVARIANCE_PARAMETERIZATION_ROLLPITCHYAW_EULER_ANGLE_COVARIANCE \
  (2)
#define SBP_ORIENT_QUAT_COV_QUATERNION_REFERENCE_FRAME_MASK (0x3u)
#define SBP_ORIENT_QUAT_COV_QUATERNION_REFERENCE_FRAME_SHIFT (3u)
#define SBP_ORIENT_QUAT_COV_QUATERNION_REFERENCE_FRAME_GET(flags)             \
  ((u8)(                                                                      \
      (u8)((flags) >> SBP_ORIENT_QUAT_COV_QUATERNION_REFERENCE_FRAME_SHIFT) & \
      SBP_ORIENT_QUAT_COV_QUATERNION_REFERENCE_FRAME_MASK))
#define SBP_ORIENT_QUAT_COV_QUATERNION_REFERENCE_FRAME_SET(flags, val)        \
  do {                                                                        \
    (flags) =                                                                 \
        (u8)((flags &                                                         \
              (~(SBP_ORIENT_QUAT_COV_QUATERNION_REFERENCE_FRAME_MASK          \
                 << SBP_ORIENT_QUAT_COV_QUATERNION_REFERENCE_FRAME_SHIFT))) | \
             (((val) & (SBP_ORIENT_QUAT_COV_QUATERNION_REFERENCE_FRAME_MASK)) \
              << (SBP_ORIENT_QUAT_COV_QUATERNION_REFERENCE_FRAME_SHIFT)));    \
  } while (0)

#define SBP_ORIENT_QUAT_COV_QUATERNION_REFERENCE_FRAME_LOCAL_LEVEL_NED (0)
#define SBP_ORIENT_QUAT_COV_QUATERNION_REFERENCE_FRAME_LOCAL_LEVEL_ENU (1)
#define SBP_ORIENT_QUAT_COV_QUATERNION_REFERENCE_FRAME_ECEF (2)
#define SBP_ORIENT_QUAT_COV_INS_NAVIGATION_MODE_MASK (0x7u)
#define SBP_ORIENT_QUAT_COV_INS_NAVIGATION_MODE_SHIFT (0u)
#define SBP_ORIENT_QUAT_COV_INS_NAVIGATION_MODE_GET(flags)               \
  ((u8)((u8)((flags) >> SBP_ORIENT_QUAT_COV_INS_NAVIGATION_MODE_SHIFT) & \
        SBP_ORIENT_QUAT_COV_INS_NAVIGATION_MODE_MASK))
#define SBP_ORIENT_QUAT_COV_INS_NAVIGATION_MODE_SET(flags, val)                \
  do {                                                                         \
    (flags) =                                                                  \
        (u8)((flags & (~(SBP_ORIENT_QUAT_COV_INS_NAVIGATION_MODE_MASK          \
                         << SBP_ORIENT_QUAT_COV_INS_NAVIGATION_MODE_SHIFT))) | \
             (((val) & (SBP_ORIENT_QUAT_COV_INS_NAVIGATION_MODE_MASK))         \
              << (SBP_ORIENT_QUAT_COV_INS_NAVIGATION_MODE_SHIFT)));            \
  } while (0)

#define SBP_ORIENT_QUAT_COV_INS_NAVIGATION_MODE_INVALID (0)
#define SBP_ORIENT_QUAT_COV_INS_NAVIGATION_MODE_VALID (1)
/**
 * Encoded length of sbp_msg_orient_quat_cov_t
 */
#define SBP_MSG_ORIENT_QUAT_COV_ENCODED_LEN 45u

#endif /* LIBSBP_ORIENTATION_MACROS_H */
