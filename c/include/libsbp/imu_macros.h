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
 * Automatically generated from yaml/swiftnav/sbp/imu.yaml
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

#ifndef LIBSBP_IMU_MACROS_H
#define LIBSBP_IMU_MACROS_H

#define SBP_IMU_RAW_TIME_STATUS_MASK (0x3u)
#define SBP_IMU_RAW_TIME_STATUS_SHIFT (30u)
#define SBP_IMU_RAW_TIME_STATUS_GET(flags)                 \
  ((u32)((u32)((flags) >> SBP_IMU_RAW_TIME_STATUS_SHIFT) & \
         SBP_IMU_RAW_TIME_STATUS_MASK))
#define SBP_IMU_RAW_TIME_STATUS_SET(flags, val)                       \
  do {                                                                \
    (flags) = (u32)((flags & (~(SBP_IMU_RAW_TIME_STATUS_MASK          \
                                << SBP_IMU_RAW_TIME_STATUS_SHIFT))) | \
                    (((val) & (SBP_IMU_RAW_TIME_STATUS_MASK))         \
                     << (SBP_IMU_RAW_TIME_STATUS_SHIFT)));            \
  } while (0)

#define SBP_IMU_RAW_TIME_STATUS_REFERENCE_EPOCH_IS_START_OF_CURRENT_GPS_WEEK (0)
#define SBP_IMU_RAW_TIME_STATUS_REFERENCE_EPOCH_IS_TIME_OF_SYSTEM_STARTUP (1)
#define SBP_IMU_RAW_TIME_STATUS_REFERENCE_EPOCH_IS_UNKNOWN (2)
#define SBP_IMU_RAW_TIME_STATUS_REFERENCE_EPOCH_IS_LAST_PPS (3)
#define SBP_IMU_RAW_TIME_SINCE_REFERENCE_EPOCH_IN_MILLISECONDS_MASK \
  (0x3fffffffu)
#define SBP_IMU_RAW_TIME_SINCE_REFERENCE_EPOCH_IN_MILLISECONDS_SHIFT (0u)
#define SBP_IMU_RAW_TIME_SINCE_REFERENCE_EPOCH_IN_MILLISECONDS_GET(flags)      \
  ((u32)((u32)((flags) >>                                                      \
               SBP_IMU_RAW_TIME_SINCE_REFERENCE_EPOCH_IN_MILLISECONDS_SHIFT) & \
         SBP_IMU_RAW_TIME_SINCE_REFERENCE_EPOCH_IN_MILLISECONDS_MASK))
#define SBP_IMU_RAW_TIME_SINCE_REFERENCE_EPOCH_IN_MILLISECONDS_SET(flags, val)   \
  do {                                                                           \
    (flags) = (u32)(                                                             \
        (flags &                                                                 \
         (~(SBP_IMU_RAW_TIME_SINCE_REFERENCE_EPOCH_IN_MILLISECONDS_MASK          \
            << SBP_IMU_RAW_TIME_SINCE_REFERENCE_EPOCH_IN_MILLISECONDS_SHIFT))) | \
        (((val) &                                                                \
          (SBP_IMU_RAW_TIME_SINCE_REFERENCE_EPOCH_IN_MILLISECONDS_MASK))         \
         << (SBP_IMU_RAW_TIME_SINCE_REFERENCE_EPOCH_IN_MILLISECONDS_SHIFT)));    \
  } while (0)

/**
 * Encoded length of sbp_msg_imu_raw_t
 */
#define SBP_MSG_IMU_RAW_ENCODED_LEN 17u

#define SBP_IMU_AUX_IMU_TYPE_MASK (0xffu)
#define SBP_IMU_AUX_IMU_TYPE_SHIFT (0u)
#define SBP_IMU_AUX_IMU_TYPE_GET(flags)               \
  ((u8)((u8)((flags) >> SBP_IMU_AUX_IMU_TYPE_SHIFT) & \
        SBP_IMU_AUX_IMU_TYPE_MASK))
#define SBP_IMU_AUX_IMU_TYPE_SET(flags, val)                      \
  do {                                                            \
    (flags) = (u8)((flags & (~(SBP_IMU_AUX_IMU_TYPE_MASK          \
                               << SBP_IMU_AUX_IMU_TYPE_SHIFT))) | \
                   (((val) & (SBP_IMU_AUX_IMU_TYPE_MASK))         \
                    << (SBP_IMU_AUX_IMU_TYPE_SHIFT)));            \
  } while (0)

#define SBP_IMU_AUX_IMU_TYPE_BOSCH_BMI160 (0)
#define SBP_IMU_AUX_IMU_TYPE_ST_MICROELECTRONICS_ASM330LLH (1)
#define SBP_IMU_AUX_IMU_TYPE_TDK_ICM_42670 (3)
#define SBP_IMU_AUX_IMU_TYPE_MURATA_SCHA634_D03 (4)
#define SBP_IMU_AUX_IMU_TYPE_TDK_IAM_20680HP (5)
#define SBP_IMU_AUX_GYROSCOPE_RANGE_MASK (0xfu)
#define SBP_IMU_AUX_GYROSCOPE_RANGE_SHIFT (4u)
#define SBP_IMU_AUX_GYROSCOPE_RANGE_GET(flags)               \
  ((u8)((u8)((flags) >> SBP_IMU_AUX_GYROSCOPE_RANGE_SHIFT) & \
        SBP_IMU_AUX_GYROSCOPE_RANGE_MASK))
#define SBP_IMU_AUX_GYROSCOPE_RANGE_SET(flags, val)                      \
  do {                                                                   \
    (flags) = (u8)((flags & (~(SBP_IMU_AUX_GYROSCOPE_RANGE_MASK          \
                               << SBP_IMU_AUX_GYROSCOPE_RANGE_SHIFT))) | \
                   (((val) & (SBP_IMU_AUX_GYROSCOPE_RANGE_MASK))         \
                    << (SBP_IMU_AUX_GYROSCOPE_RANGE_SHIFT)));            \
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
#define SBP_IMU_AUX_GYROSCOPE_RANGE__300_DEG__S (5)
#define SBP_IMU_AUX_GYROSCOPE_RANGE_300_DEG_S (5)
#define SBP_IMU_AUX_ACCELEROMETER_RANGE_MASK (0xfu)
#define SBP_IMU_AUX_ACCELEROMETER_RANGE_SHIFT (0u)
#define SBP_IMU_AUX_ACCELEROMETER_RANGE_GET(flags)               \
  ((u8)((u8)((flags) >> SBP_IMU_AUX_ACCELEROMETER_RANGE_SHIFT) & \
        SBP_IMU_AUX_ACCELEROMETER_RANGE_MASK))
#define SBP_IMU_AUX_ACCELEROMETER_RANGE_SET(flags, val)                      \
  do {                                                                       \
    (flags) = (u8)((flags & (~(SBP_IMU_AUX_ACCELEROMETER_RANGE_MASK          \
                               << SBP_IMU_AUX_ACCELEROMETER_RANGE_SHIFT))) | \
                   (((val) & (SBP_IMU_AUX_ACCELEROMETER_RANGE_MASK))         \
                    << (SBP_IMU_AUX_ACCELEROMETER_RANGE_SHIFT)));            \
  } while (0)

#define SBP_IMU_AUX_ACCELEROMETER_RANGE__2G (0)
#define SBP_IMU_AUX_ACCELEROMETER_RANGE_2G (0)
#define SBP_IMU_AUX_ACCELEROMETER_RANGE__4G (1)
#define SBP_IMU_AUX_ACCELEROMETER_RANGE_4G (1)
#define SBP_IMU_AUX_ACCELEROMETER_RANGE__8G (2)
#define SBP_IMU_AUX_ACCELEROMETER_RANGE_8G (2)
#define SBP_IMU_AUX_ACCELEROMETER_RANGE__16G (3)
#define SBP_IMU_AUX_ACCELEROMETER_RANGE_16G (3)
#define SBP_IMU_AUX_ACCELEROMETER_RANGE__6G (4)
#define SBP_IMU_AUX_ACCELEROMETER_RANGE_6G (4)
/**
 * Encoded length of sbp_msg_imu_aux_t
 */
#define SBP_MSG_IMU_AUX_ENCODED_LEN 4u

#define SBP_IMU_COMP_GYROSCOPEERRORSCOMPENSATED_MASK (0x1u)
#define SBP_IMU_COMP_GYROSCOPEERRORSCOMPENSATED_SHIFT (6u)
#define SBP_IMU_COMP_GYROSCOPEERRORSCOMPENSATED_GET(flags)                 \
  ((u16)((u16)((flags) >> SBP_IMU_COMP_GYROSCOPEERRORSCOMPENSATED_SHIFT) & \
         SBP_IMU_COMP_GYROSCOPEERRORSCOMPENSATED_MASK))
#define SBP_IMU_COMP_GYROSCOPEERRORSCOMPENSATED_SET(flags, val)           \
  do {                                                                    \
    (flags) = (u16)(                                                      \
        (flags & (~(SBP_IMU_COMP_GYROSCOPEERRORSCOMPENSATED_MASK          \
                    << SBP_IMU_COMP_GYROSCOPEERRORSCOMPENSATED_SHIFT))) | \
        (((val) & (SBP_IMU_COMP_GYROSCOPEERRORSCOMPENSATED_MASK))         \
         << (SBP_IMU_COMP_GYROSCOPEERRORSCOMPENSATED_SHIFT)));            \
  } while (0)

#define SBP_IMU_COMP_ACCELEROMETERERRORSCOMPENSATED_MASK (0x1u)
#define SBP_IMU_COMP_ACCELEROMETERERRORSCOMPENSATED_SHIFT (5u)
#define SBP_IMU_COMP_ACCELEROMETERERRORSCOMPENSATED_GET(flags)                 \
  ((u16)((u16)((flags) >> SBP_IMU_COMP_ACCELEROMETERERRORSCOMPENSATED_SHIFT) & \
         SBP_IMU_COMP_ACCELEROMETERERRORSCOMPENSATED_MASK))
#define SBP_IMU_COMP_ACCELEROMETERERRORSCOMPENSATED_SET(flags, val)           \
  do {                                                                        \
    (flags) = (u16)(                                                          \
        (flags & (~(SBP_IMU_COMP_ACCELEROMETERERRORSCOMPENSATED_MASK          \
                    << SBP_IMU_COMP_ACCELEROMETERERRORSCOMPENSATED_SHIFT))) | \
        (((val) & (SBP_IMU_COMP_ACCELEROMETERERRORSCOMPENSATED_MASK))         \
         << (SBP_IMU_COMP_ACCELEROMETERERRORSCOMPENSATED_SHIFT)));            \
  } while (0)

#define SBP_IMU_COMP_CORIOLISEFFECTCOMPENSATED_MASK (0x1u)
#define SBP_IMU_COMP_CORIOLISEFFECTCOMPENSATED_SHIFT (4u)
#define SBP_IMU_COMP_CORIOLISEFFECTCOMPENSATED_GET(flags)                 \
  ((u16)((u16)((flags) >> SBP_IMU_COMP_CORIOLISEFFECTCOMPENSATED_SHIFT) & \
         SBP_IMU_COMP_CORIOLISEFFECTCOMPENSATED_MASK))
#define SBP_IMU_COMP_CORIOLISEFFECTCOMPENSATED_SET(flags, val)                 \
  do {                                                                         \
    (flags) =                                                                  \
        (u16)((flags & (~(SBP_IMU_COMP_CORIOLISEFFECTCOMPENSATED_MASK          \
                          << SBP_IMU_COMP_CORIOLISEFFECTCOMPENSATED_SHIFT))) | \
              (((val) & (SBP_IMU_COMP_CORIOLISEFFECTCOMPENSATED_MASK))         \
               << (SBP_IMU_COMP_CORIOLISEFFECTCOMPENSATED_SHIFT)));            \
  } while (0)

#define SBP_IMU_COMP_EARTHRORATIONRATECOMPENSATED_MASK (0x1u)
#define SBP_IMU_COMP_EARTHRORATIONRATECOMPENSATED_SHIFT (3u)
#define SBP_IMU_COMP_EARTHRORATIONRATECOMPENSATED_GET(flags)                 \
  ((u16)((u16)((flags) >> SBP_IMU_COMP_EARTHRORATIONRATECOMPENSATED_SHIFT) & \
         SBP_IMU_COMP_EARTHRORATIONRATECOMPENSATED_MASK))
#define SBP_IMU_COMP_EARTHRORATIONRATECOMPENSATED_SET(flags, val)           \
  do {                                                                      \
    (flags) = (u16)(                                                        \
        (flags & (~(SBP_IMU_COMP_EARTHRORATIONRATECOMPENSATED_MASK          \
                    << SBP_IMU_COMP_EARTHRORATIONRATECOMPENSATED_SHIFT))) | \
        (((val) & (SBP_IMU_COMP_EARTHRORATIONRATECOMPENSATED_MASK))         \
         << (SBP_IMU_COMP_EARTHRORATIONRATECOMPENSATED_SHIFT)));            \
  } while (0)

#define SBP_IMU_COMP_EARTHGRAVITYCOMPENSATED_MASK (0x1u)
#define SBP_IMU_COMP_EARTHGRAVITYCOMPENSATED_SHIFT (2u)
#define SBP_IMU_COMP_EARTHGRAVITYCOMPENSATED_GET(flags)                 \
  ((u16)((u16)((flags) >> SBP_IMU_COMP_EARTHGRAVITYCOMPENSATED_SHIFT) & \
         SBP_IMU_COMP_EARTHGRAVITYCOMPENSATED_MASK))
#define SBP_IMU_COMP_EARTHGRAVITYCOMPENSATED_SET(flags, val)                 \
  do {                                                                       \
    (flags) =                                                                \
        (u16)((flags & (~(SBP_IMU_COMP_EARTHGRAVITYCOMPENSATED_MASK          \
                          << SBP_IMU_COMP_EARTHGRAVITYCOMPENSATED_SHIFT))) | \
              (((val) & (SBP_IMU_COMP_EARTHGRAVITYCOMPENSATED_MASK))         \
               << (SBP_IMU_COMP_EARTHGRAVITYCOMPENSATED_SHIFT)));            \
  } while (0)

#define SBP_IMU_COMP_TIME_STATUS_MASK (0x3u)
#define SBP_IMU_COMP_TIME_STATUS_SHIFT (0u)
#define SBP_IMU_COMP_TIME_STATUS_GET(flags)                 \
  ((u16)((u16)((flags) >> SBP_IMU_COMP_TIME_STATUS_SHIFT) & \
         SBP_IMU_COMP_TIME_STATUS_MASK))
#define SBP_IMU_COMP_TIME_STATUS_SET(flags, val)                       \
  do {                                                                 \
    (flags) = (u16)((flags & (~(SBP_IMU_COMP_TIME_STATUS_MASK          \
                                << SBP_IMU_COMP_TIME_STATUS_SHIFT))) | \
                    (((val) & (SBP_IMU_COMP_TIME_STATUS_MASK))         \
                     << (SBP_IMU_COMP_TIME_STATUS_SHIFT)));            \
  } while (0)

#define SBP_IMU_COMP_TIME_STATUS_REFERENCE_EPOCH_IS_START_OF_CURRENT_GPS_WEEK \
  (0)
#define SBP_IMU_COMP_TIME_STATUS_REFERENCE_EPOCH_IS_TIME_OF_SYSTEM_STARTUP (1)
#define SBP_IMU_COMP_TIME_STATUS_REFERENCE_EPOCH_IS_UNKNOWN (2)
#define SBP_IMU_COMP_TIME_STATUS_REFERENCE_EPOCH_IS_LAST_PPS (3)
/**
 * Encoded length of sbp_msg_imu_comp_t
 */
#define SBP_MSG_IMU_COMP_ENCODED_LEN 34u

#endif /* LIBSBP_IMU_MACROS_H */
