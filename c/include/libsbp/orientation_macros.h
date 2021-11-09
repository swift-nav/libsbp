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
 * Automatically generated from yaml/swiftnav/sbp/orientation.yaml
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

#ifndef LIBSBP_ORIENTATION_MACROS_H
#define LIBSBP_ORIENTATION_MACROS_H

#define SBP_MSG_BASELINE_HEADING 0x020F
#define SBP_BASELINE_HEADING_FIX_MODE_MASK (0x7)
#define SBP_BASELINE_HEADING_FIX_MODE_SHIFT (0u)
#define SBP_BASELINE_HEADING_FIX_MODE_GET(flags)           \
  ((u8)(((flags) >> SBP_BASELINE_HEADING_FIX_MODE_SHIFT) & \
        SBP_BASELINE_HEADING_FIX_MODE_MASK))
#define SBP_BASELINE_HEADING_FIX_MODE_SET(flags, val)                        \
  do {                                                                       \
    (flags) = (u8)((flags) | (((val) & (SBP_BASELINE_HEADING_FIX_MODE_MASK)) \
                              << (SBP_BASELINE_HEADING_FIX_MODE_SHIFT)));    \
  } while (0)

#define SBP_BASELINE_HEADING_FIX_MODE_INVALID (0)
#define SBP_BASELINE_HEADING_FIX_MODE_DIFFERENTIAL_GNSS (2)
#define SBP_BASELINE_HEADING_FIX_MODE_FLOAT_RTK (3)
#define SBP_BASELINE_HEADING_FIX_MODE_FIXED_RTK (4)
/**
 * Encoded length of sbp_msg_baseline_heading_t (V4 API) and
 * msg_baseline_heading_t (legacy API)
 */
#define SBP_MSG_BASELINE_HEADING_ENCODED_LEN 10u

#define SBP_MSG_ORIENT_QUAT 0x0220
#define SBP_ORIENT_QUAT_INS_NAVIGATION_MODE_MASK (0x7)
#define SBP_ORIENT_QUAT_INS_NAVIGATION_MODE_SHIFT (0u)
#define SBP_ORIENT_QUAT_INS_NAVIGATION_MODE_GET(flags)           \
  ((u8)(((flags) >> SBP_ORIENT_QUAT_INS_NAVIGATION_MODE_SHIFT) & \
        SBP_ORIENT_QUAT_INS_NAVIGATION_MODE_MASK))
#define SBP_ORIENT_QUAT_INS_NAVIGATION_MODE_SET(flags, val)                  \
  do {                                                                       \
    (flags) =                                                                \
        (u8)((flags) | (((val) & (SBP_ORIENT_QUAT_INS_NAVIGATION_MODE_MASK)) \
                        << (SBP_ORIENT_QUAT_INS_NAVIGATION_MODE_SHIFT)));    \
  } while (0)

#define SBP_ORIENT_QUAT_INS_NAVIGATION_MODE_INVALID (0)
#define SBP_ORIENT_QUAT_INS_NAVIGATION_MODE_VALID (1)
/**
 * Encoded length of sbp_msg_orient_quat_t (V4 API) and
 * msg_orient_quat_t (legacy API)
 */
#define SBP_MSG_ORIENT_QUAT_ENCODED_LEN 37u

#define SBP_MSG_ORIENT_EULER 0x0221
#define SBP_ORIENT_EULER_INS_NAVIGATION_MODE_MASK (0x7)
#define SBP_ORIENT_EULER_INS_NAVIGATION_MODE_SHIFT (0u)
#define SBP_ORIENT_EULER_INS_NAVIGATION_MODE_GET(flags)           \
  ((u8)(((flags) >> SBP_ORIENT_EULER_INS_NAVIGATION_MODE_SHIFT) & \
        SBP_ORIENT_EULER_INS_NAVIGATION_MODE_MASK))
#define SBP_ORIENT_EULER_INS_NAVIGATION_MODE_SET(flags, val)                  \
  do {                                                                        \
    (flags) =                                                                 \
        (u8)((flags) | (((val) & (SBP_ORIENT_EULER_INS_NAVIGATION_MODE_MASK)) \
                        << (SBP_ORIENT_EULER_INS_NAVIGATION_MODE_SHIFT)));    \
  } while (0)

#define SBP_ORIENT_EULER_INS_NAVIGATION_MODE_INVALID (0)
#define SBP_ORIENT_EULER_INS_NAVIGATION_MODE_VALID (1)
/**
 * Encoded length of sbp_msg_orient_euler_t (V4 API) and
 * msg_orient_euler_t (legacy API)
 */
#define SBP_MSG_ORIENT_EULER_ENCODED_LEN 29u

#define SBP_MSG_ANGULAR_RATE 0x0222
#define SBP_ANGULAR_RATE_INS_NAVIGATION_MODE_MASK (0x7)
#define SBP_ANGULAR_RATE_INS_NAVIGATION_MODE_SHIFT (0u)
#define SBP_ANGULAR_RATE_INS_NAVIGATION_MODE_GET(flags)           \
  ((u8)(((flags) >> SBP_ANGULAR_RATE_INS_NAVIGATION_MODE_SHIFT) & \
        SBP_ANGULAR_RATE_INS_NAVIGATION_MODE_MASK))
#define SBP_ANGULAR_RATE_INS_NAVIGATION_MODE_SET(flags, val)                  \
  do {                                                                        \
    (flags) =                                                                 \
        (u8)((flags) | (((val) & (SBP_ANGULAR_RATE_INS_NAVIGATION_MODE_MASK)) \
                        << (SBP_ANGULAR_RATE_INS_NAVIGATION_MODE_SHIFT)));    \
  } while (0)

#define SBP_ANGULAR_RATE_INS_NAVIGATION_MODE_INVALID (0)
#define SBP_ANGULAR_RATE_INS_NAVIGATION_MODE_VALID (1)
/**
 * Encoded length of sbp_msg_angular_rate_t (V4 API) and
 * msg_angular_rate_t (legacy API)
 */
#define SBP_MSG_ANGULAR_RATE_ENCODED_LEN 17u

#endif /* LIBSBP_ORIENTATION_MACROS_H */
