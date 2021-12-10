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
 * Automatically generated from yaml/swiftnav/sbp/vehicle.yaml
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

#ifndef LIBSBP_VEHICLE_MACROS_H
#define LIBSBP_VEHICLE_MACROS_H

#define SBP_MSG_ODOMETRY 0x0903
#define SBP_ODOMETRY_VEHICLE_METADATA_MASK (0x3)
#define SBP_ODOMETRY_VEHICLE_METADATA_SHIFT (5u)
#define SBP_ODOMETRY_VEHICLE_METADATA_GET(flags)           \
  ((u8)(((flags) >> SBP_ODOMETRY_VEHICLE_METADATA_SHIFT) & \
        SBP_ODOMETRY_VEHICLE_METADATA_MASK))
#define SBP_ODOMETRY_VEHICLE_METADATA_SET(flags, val)                        \
  do {                                                                       \
    (flags) = (u8)((flags) | (((val) & (SBP_ODOMETRY_VEHICLE_METADATA_MASK)) \
                              << (SBP_ODOMETRY_VEHICLE_METADATA_SHIFT)));    \
  } while (0)

#define SBP_ODOMETRY_VEHICLE_METADATA_UNAVAILABLE (0)
#define SBP_ODOMETRY_VEHICLE_METADATA_FORWARD (1)
#define SBP_ODOMETRY_VEHICLE_METADATA_REVERSE (2)
#define SBP_ODOMETRY_VEHICLE_METADATA_PARK (3)
#define SBP_ODOMETRY_VELOCITY_SOURCE_MASK (0x3)
#define SBP_ODOMETRY_VELOCITY_SOURCE_SHIFT (3u)
#define SBP_ODOMETRY_VELOCITY_SOURCE_GET(flags)           \
  ((u8)(((flags) >> SBP_ODOMETRY_VELOCITY_SOURCE_SHIFT) & \
        SBP_ODOMETRY_VELOCITY_SOURCE_MASK))
#define SBP_ODOMETRY_VELOCITY_SOURCE_SET(flags, val)                        \
  do {                                                                      \
    (flags) = (u8)((flags) | (((val) & (SBP_ODOMETRY_VELOCITY_SOURCE_MASK)) \
                              << (SBP_ODOMETRY_VELOCITY_SOURCE_SHIFT)));    \
  } while (0)

#define SBP_ODOMETRY_VELOCITY_SOURCE_SOURCE_0 (0)
#define SBP_ODOMETRY_VELOCITY_SOURCE_SOURCE_1 (1)
#define SBP_ODOMETRY_VELOCITY_SOURCE_SOURCE_2 (2)
#define SBP_ODOMETRY_VELOCITY_SOURCE_SOURCE_3 (3)
#define SBP_ODOMETRY_TIME_SOURCE_MASK (0x7)
#define SBP_ODOMETRY_TIME_SOURCE_SHIFT (0u)
#define SBP_ODOMETRY_TIME_SOURCE_GET(flags)           \
  ((u8)(((flags) >> SBP_ODOMETRY_TIME_SOURCE_SHIFT) & \
        SBP_ODOMETRY_TIME_SOURCE_MASK))
#define SBP_ODOMETRY_TIME_SOURCE_SET(flags, val)                        \
  do {                                                                  \
    (flags) = (u8)((flags) | (((val) & (SBP_ODOMETRY_TIME_SOURCE_MASK)) \
                              << (SBP_ODOMETRY_TIME_SOURCE_SHIFT)));    \
  } while (0)

#define SBP_ODOMETRY_TIME_SOURCE_NONE (0)
#define SBP_ODOMETRY_TIME_SOURCE_GPS_SOLUTION (1)
#define SBP_ODOMETRY_TIME_SOURCE_PROCESSOR_TIME (2)
/**
 * Encoded length of sbp_msg_odometry_t (V4 API) and
 * msg_odometry_t (legacy API)
 */
#define SBP_MSG_ODOMETRY_ENCODED_LEN 9u

#define SBP_MSG_WHEELTICK 0x0904
#define SBP_WHEELTICK_VEHICLE_METADATA_MASK (0x3)
#define SBP_WHEELTICK_VEHICLE_METADATA_SHIFT (2u)
#define SBP_WHEELTICK_VEHICLE_METADATA_GET(flags)           \
  ((u8)(((flags) >> SBP_WHEELTICK_VEHICLE_METADATA_SHIFT) & \
        SBP_WHEELTICK_VEHICLE_METADATA_MASK))
#define SBP_WHEELTICK_VEHICLE_METADATA_SET(flags, val)                        \
  do {                                                                        \
    (flags) = (u8)((flags) | (((val) & (SBP_WHEELTICK_VEHICLE_METADATA_MASK)) \
                              << (SBP_WHEELTICK_VEHICLE_METADATA_SHIFT)));    \
  } while (0)

#define SBP_WHEELTICK_VEHICLE_METADATA_UNAVAILABLE (0)
#define SBP_WHEELTICK_VEHICLE_METADATA_FORWARD (1)
#define SBP_WHEELTICK_VEHICLE_METADATA_REVERSE (2)
#define SBP_WHEELTICK_VEHICLE_METADATA_PARK (3)
#define SBP_WHEELTICK_SYNCHRONIZATION_TYPE_MASK (0x3)
#define SBP_WHEELTICK_SYNCHRONIZATION_TYPE_SHIFT (0u)
#define SBP_WHEELTICK_SYNCHRONIZATION_TYPE_GET(flags)           \
  ((u8)(((flags) >> SBP_WHEELTICK_SYNCHRONIZATION_TYPE_SHIFT) & \
        SBP_WHEELTICK_SYNCHRONIZATION_TYPE_MASK))
#define SBP_WHEELTICK_SYNCHRONIZATION_TYPE_SET(flags, val)                  \
  do {                                                                      \
    (flags) =                                                               \
        (u8)((flags) | (((val) & (SBP_WHEELTICK_SYNCHRONIZATION_TYPE_MASK)) \
                        << (SBP_WHEELTICK_SYNCHRONIZATION_TYPE_SHIFT)));    \
  } while (0)

#define SBP_WHEELTICK_SYNCHRONIZATION_TYPE_MICROSECONDS_SINCE_LAST_PPS (0)
#define SBP_WHEELTICK_SYNCHRONIZATION_TYPE_MICROSECONDS_IN_GPS_WEEK (1)
#define SBP_WHEELTICK_SYNCHRONIZATION_TYPE_LOCAL_CPU_TIME_IN_NOMINAL_MICROSECONDS \
  (2)
/**
 * Encoded length of sbp_msg_wheeltick_t (V4 API) and
 * msg_wheeltick_t (legacy API)
 */
#define SBP_MSG_WHEELTICK_ENCODED_LEN 14u

#endif /* LIBSBP_VEHICLE_MACROS_H */
