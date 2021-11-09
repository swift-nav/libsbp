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
 * Automatically generated from yaml/swiftnav/sbp/solution_meta.yaml
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

#ifndef LIBSBP_SOLUTION_META_MACROS_H
#define LIBSBP_SOLUTION_META_MACROS_H

#define SBP_SOLUTIONINPUTTYPE_SENSOR_USAGE_MASK (0x3)
#define SBP_SOLUTIONINPUTTYPE_SENSOR_USAGE_SHIFT (3u)
#define SBP_SOLUTIONINPUTTYPE_SENSOR_USAGE_GET(flags)           \
  ((u8)(((flags) >> SBP_SOLUTIONINPUTTYPE_SENSOR_USAGE_SHIFT) & \
        SBP_SOLUTIONINPUTTYPE_SENSOR_USAGE_MASK))
#define SBP_SOLUTIONINPUTTYPE_SENSOR_USAGE_SET(flags, val)                  \
  do {                                                                      \
    (flags) =                                                               \
        (u8)((flags) | (((val) & (SBP_SOLUTIONINPUTTYPE_SENSOR_USAGE_MASK)) \
                        << (SBP_SOLUTIONINPUTTYPE_SENSOR_USAGE_SHIFT)));    \
  } while (0)

#define SBP_SOLUTIONINPUTTYPE_SENSOR_USAGE_UNKNOWN (0)
#define SBP_SOLUTIONINPUTTYPE_SENSOR_USAGE_RECEIVED_AND_USED (1)
#define SBP_SOLUTIONINPUTTYPE_SENSOR_USAGE_RECEIVED_BUT_NOT_USED (2)
#define SBP_SOLUTIONINPUTTYPE_SENSOR_TYPE_MASK (0x7)
#define SBP_SOLUTIONINPUTTYPE_SENSOR_TYPE_SHIFT (0u)
#define SBP_SOLUTIONINPUTTYPE_SENSOR_TYPE_GET(flags)           \
  ((u8)(((flags) >> SBP_SOLUTIONINPUTTYPE_SENSOR_TYPE_SHIFT) & \
        SBP_SOLUTIONINPUTTYPE_SENSOR_TYPE_MASK))
#define SBP_SOLUTIONINPUTTYPE_SENSOR_TYPE_SET(flags, val)                  \
  do {                                                                     \
    (flags) =                                                              \
        (u8)((flags) | (((val) & (SBP_SOLUTIONINPUTTYPE_SENSOR_TYPE_MASK)) \
                        << (SBP_SOLUTIONINPUTTYPE_SENSOR_TYPE_SHIFT)));    \
  } while (0)

#define SBP_SOLUTIONINPUTTYPE_SENSOR_TYPE_INVALID (0)
#define SBP_SOLUTIONINPUTTYPE_SENSOR_TYPE_GNSS_POSITION (1)
#define SBP_SOLUTIONINPUTTYPE_SENSOR_TYPE_GNSS_VELOCITY_DISPLACEMENT (2)
#define SBP_SOLUTIONINPUTTYPE_SENSOR_TYPE_GNSS_VELOCITY_DOPPLER (3)
#define SBP_SOLUTIONINPUTTYPE_SENSOR_TYPE_ODOMETRY_TICKS (4)
#define SBP_SOLUTIONINPUTTYPE_SENSOR_TYPE_ODOMETRY_SPEED (5)
#define SBP_SOLUTIONINPUTTYPE_SENSOR_TYPE_IMU_SENSOR (6)
/**
 * Encoded length of sbp_solution_input_type_t (V4 API) and
 * solution_input_type_t (legacy API)
 */
#define SBP_SOLUTION_INPUT_TYPE_ENCODED_LEN 2u

#define SBP_MSG_SOLN_META_DEP_A 0xFF0F
#define SBP_SOLN_META_DEP_A_ALIGNMENT_STATUS_MASK (0x7)
#define SBP_SOLN_META_DEP_A_ALIGNMENT_STATUS_SHIFT (0u)
#define SBP_SOLN_META_DEP_A_ALIGNMENT_STATUS_GET(flags)           \
  ((u8)(((flags) >> SBP_SOLN_META_DEP_A_ALIGNMENT_STATUS_SHIFT) & \
        SBP_SOLN_META_DEP_A_ALIGNMENT_STATUS_MASK))
#define SBP_SOLN_META_DEP_A_ALIGNMENT_STATUS_SET(flags, val)                  \
  do {                                                                        \
    (flags) =                                                                 \
        (u8)((flags) | (((val) & (SBP_SOLN_META_DEP_A_ALIGNMENT_STATUS_MASK)) \
                        << (SBP_SOLN_META_DEP_A_ALIGNMENT_STATUS_SHIFT)));    \
  } while (0)

#define SBP_SOLN_META_DEP_A_ALIGNMENT_STATUS_UNKNOWN_REASON_OR_ALREADY_ALIGNED \
  (0)
#define SBP_SOLN_META_DEP_A_ALIGNMENT_STATUS_SEED_VALUES_LOADED_AND_ALIGNMENT_IN_PROGRESS \
  (1)
#define SBP_SOLN_META_DEP_A_ALIGNMENT_STATUS_NO_SEED_VALUES_AND_ALIGNMENT_IN_PROGRESS \
  (2)
#define SBP_SOLN_META_DEP_A_ALIGNMENT_STATUS_SEED_VALUES_LOADED_BUT_NO_GNSS_MEASUREMENTS \
  (3)
#define SBP_SOLN_META_DEP_A_ALIGNMENT_STATUS_NO_SEED_VALUES_NOR_GNSS_MEASUREMENTS \
  (4)
/**
 * The maximum number of items that can be stored in
 * sbp_msg_soln_meta_dep_a_t::sol_in (V4 API) or msg_soln_meta_dep_a_t::sol_in
 * (legacy API) before the maximum SBP message size is exceeded
 */
#define SBP_MSG_SOLN_META_DEP_A_SOL_IN_MAX 118u

/**
 * Encoded length of sbp_msg_soln_meta_dep_a_t (V4 API) and
 * msg_soln_meta_dep_a_t (legacy API)
 *
 * This type is not fixed size and an instance of this message may be longer
 * than the value indicated by this symbol. Users of the V4 API should call
 * #sbp_msg_soln_meta_dep_a_encoded_len to determine the actual size of an
 * instance of this message. Users of the legacy API are required to track the
 * encoded message length when interacting with the legacy type.
 *
 * See the documentation for libsbp for more details regarding the message
 * structure and its variable length component(s)
 */
#define SBP_MSG_SOLN_META_DEP_A_ENCODED_OVERHEAD 18u

#define SBP_MSG_SOLN_META 0xFF0E
#define SBP_SOLN_META_TIME_STATUS_MASK (0x3)
#define SBP_SOLN_META_TIME_STATUS_SHIFT (30u)
#define SBP_SOLN_META_TIME_STATUS_GET(flags)            \
  ((u32)(((flags) >> SBP_SOLN_META_TIME_STATUS_SHIFT) & \
         SBP_SOLN_META_TIME_STATUS_MASK))
#define SBP_SOLN_META_TIME_STATUS_SET(flags, val)                         \
  do {                                                                    \
    (flags) = (u32)((flags) | (((val) & (SBP_SOLN_META_TIME_STATUS_MASK)) \
                               << (SBP_SOLN_META_TIME_STATUS_SHIFT)));    \
  } while (0)

#define SBP_SOLN_META_TIME_STATUS_AGE_CAN_NOT_BE_USED_TO_RETRIEVE_TOM (0)
#define SBP_SOLN_META_TIME_STATUS_AGE_CAN_BE_USED_TO_RETRIEVE_TOM (1)
#define SBP_SOLN_META_AGE_OF_THE_LAST_RECEIVED_VALID_GNSS_SOLUTION_MASK \
  (0x3fffffff)
#define SBP_SOLN_META_AGE_OF_THE_LAST_RECEIVED_VALID_GNSS_SOLUTION_SHIFT (0u)
#define SBP_SOLN_META_AGE_OF_THE_LAST_RECEIVED_VALID_GNSS_SOLUTION_GET(flags) \
  ((u32)(((flags) >>                                                          \
          SBP_SOLN_META_AGE_OF_THE_LAST_RECEIVED_VALID_GNSS_SOLUTION_SHIFT) & \
         SBP_SOLN_META_AGE_OF_THE_LAST_RECEIVED_VALID_GNSS_SOLUTION_MASK))
#define SBP_SOLN_META_AGE_OF_THE_LAST_RECEIVED_VALID_GNSS_SOLUTION_SET(flags,     \
                                                                       val)       \
  do {                                                                            \
    (flags) = (u32)(                                                              \
        (flags) |                                                                 \
        (((val) &                                                                 \
          (SBP_SOLN_META_AGE_OF_THE_LAST_RECEIVED_VALID_GNSS_SOLUTION_MASK))      \
         << (SBP_SOLN_META_AGE_OF_THE_LAST_RECEIVED_VALID_GNSS_SOLUTION_SHIFT))); \
  } while (0)

/**
 * The maximum number of items that can be stored in sbp_msg_soln_meta_t::sol_in
 * (V4 API) or msg_soln_meta_t::sol_in (legacy API) before the maximum SBP
 * message size is exceeded
 */
#define SBP_MSG_SOLN_META_SOL_IN_MAX 119u

/**
 * Encoded length of sbp_msg_soln_meta_t (V4 API) and
 * msg_soln_meta_t (legacy API)
 *
 * This type is not fixed size and an instance of this message may be longer
 * than the value indicated by this symbol. Users of the V4 API should call
 * #sbp_msg_soln_meta_encoded_len to determine the actual size of an instance
 * of this message. Users of the legacy API are required to track the encoded
 * message length when interacting with the legacy type.
 *
 * See the documentation for libsbp for more details regarding the message
 * structure and its variable length component(s)
 */
#define SBP_MSG_SOLN_META_ENCODED_OVERHEAD 16u

#define SBP_GNSSINPUTTYPE_TYPE_OF_GNSS_MEASUREMENT_MASK (0x3)
#define SBP_GNSSINPUTTYPE_TYPE_OF_GNSS_MEASUREMENT_SHIFT (0u)
#define SBP_GNSSINPUTTYPE_TYPE_OF_GNSS_MEASUREMENT_GET(flags)           \
  ((u8)(((flags) >> SBP_GNSSINPUTTYPE_TYPE_OF_GNSS_MEASUREMENT_SHIFT) & \
        SBP_GNSSINPUTTYPE_TYPE_OF_GNSS_MEASUREMENT_MASK))
#define SBP_GNSSINPUTTYPE_TYPE_OF_GNSS_MEASUREMENT_SET(flags, val)             \
  do {                                                                         \
    (flags) = (u8)(                                                            \
        (flags) | (((val) & (SBP_GNSSINPUTTYPE_TYPE_OF_GNSS_MEASUREMENT_MASK)) \
                   << (SBP_GNSSINPUTTYPE_TYPE_OF_GNSS_MEASUREMENT_SHIFT)));    \
  } while (0)

#define SBP_GNSSINPUTTYPE_TYPE_OF_GNSS_MEASUREMENT_GNSS_POSITION (0)
#define SBP_GNSSINPUTTYPE_TYPE_OF_GNSS_MEASUREMENT_GNSS_VELOCITY_DOPPLER (1)
#define SBP_GNSSINPUTTYPE_TYPE_OF_GNSS_MEASUREMENT_GNSS_VELOCITY_DISPLACEMENT \
  (2)
/**
 * Encoded length of sbp_gnss_input_type_t (V4 API) and
 * gnss_input_type_t (legacy API)
 */
#define SBP_GNSS_INPUT_TYPE_ENCODED_LEN 1u

#define SBP_IMUINPUTTYPE_TIME_STATUS_MASK (0x3)
#define SBP_IMUINPUTTYPE_TIME_STATUS_SHIFT (4u)
#define SBP_IMUINPUTTYPE_TIME_STATUS_GET(flags)           \
  ((u8)(((flags) >> SBP_IMUINPUTTYPE_TIME_STATUS_SHIFT) & \
        SBP_IMUINPUTTYPE_TIME_STATUS_MASK))
#define SBP_IMUINPUTTYPE_TIME_STATUS_SET(flags, val)                        \
  do {                                                                      \
    (flags) = (u8)((flags) | (((val) & (SBP_IMUINPUTTYPE_TIME_STATUS_MASK)) \
                              << (SBP_IMUINPUTTYPE_TIME_STATUS_SHIFT)));    \
  } while (0)

#define SBP_IMUINPUTTYPE_TIME_STATUS_REFERENCE_EPOCH_IS_START_OF_CURRENT_GPS_WEEK \
  (0)
#define SBP_IMUINPUTTYPE_TIME_STATUS_REFERENCE_EPOCH_IS_TIME_OF_SYSTEM_STARTUP \
  (1)
#define SBP_IMUINPUTTYPE_TIME_STATUS_REFERENCE_EPOCH_IS_UNKNOWN (2)
#define SBP_IMUINPUTTYPE_TIME_STATUS_REFERENCE_EPOCH_IS_LAST_PPS (3)
#define SBP_IMUINPUTTYPE_IMU_GRADE_MASK (0x3)
#define SBP_IMUINPUTTYPE_IMU_GRADE_SHIFT (2u)
#define SBP_IMUINPUTTYPE_IMU_GRADE_GET(flags)           \
  ((u8)(((flags) >> SBP_IMUINPUTTYPE_IMU_GRADE_SHIFT) & \
        SBP_IMUINPUTTYPE_IMU_GRADE_MASK))
#define SBP_IMUINPUTTYPE_IMU_GRADE_SET(flags, val)                        \
  do {                                                                    \
    (flags) = (u8)((flags) | (((val) & (SBP_IMUINPUTTYPE_IMU_GRADE_MASK)) \
                              << (SBP_IMUINPUTTYPE_IMU_GRADE_SHIFT)));    \
  } while (0)

#define SBP_IMUINPUTTYPE_IMU_GRADE_CONSUMER_GRADE (0)
#define SBP_IMUINPUTTYPE_IMU_GRADE_TACTICAL_GRADE (1)
#define SBP_IMUINPUTTYPE_IMU_GRADE_INTERMEDIATE_GRADE (2)
#define SBP_IMUINPUTTYPE_IMU_GRADE_SUPERIOR_GRADE (3)
#define SBP_IMUINPUTTYPE_IMU_ARCHITECTURE_MASK (0x3)
#define SBP_IMUINPUTTYPE_IMU_ARCHITECTURE_SHIFT (0u)
#define SBP_IMUINPUTTYPE_IMU_ARCHITECTURE_GET(flags)           \
  ((u8)(((flags) >> SBP_IMUINPUTTYPE_IMU_ARCHITECTURE_SHIFT) & \
        SBP_IMUINPUTTYPE_IMU_ARCHITECTURE_MASK))
#define SBP_IMUINPUTTYPE_IMU_ARCHITECTURE_SET(flags, val)                  \
  do {                                                                     \
    (flags) =                                                              \
        (u8)((flags) | (((val) & (SBP_IMUINPUTTYPE_IMU_ARCHITECTURE_MASK)) \
                        << (SBP_IMUINPUTTYPE_IMU_ARCHITECTURE_SHIFT)));    \
  } while (0)

#define SBP_IMUINPUTTYPE_IMU_ARCHITECTURE_6_AXIS_MEMS (0)
#define SBP_IMUINPUTTYPE_IMU_ARCHITECTURE_OTHER_TYPE (1)
/**
 * Encoded length of sbp_imu_input_type_t (V4 API) and
 * imu_input_type_t (legacy API)
 */
#define SBP_IMU_INPUT_TYPE_ENCODED_LEN 1u

#define SBP_ODOINPUTTYPE_RATE_MASK (0x3)
#define SBP_ODOINPUTTYPE_RATE_SHIFT (4u)
#define SBP_ODOINPUTTYPE_RATE_GET(flags) \
  ((u8)(((flags) >> SBP_ODOINPUTTYPE_RATE_SHIFT) & SBP_ODOINPUTTYPE_RATE_MASK))
#define SBP_ODOINPUTTYPE_RATE_SET(flags, val)                        \
  do {                                                               \
    (flags) = (u8)((flags) | (((val) & (SBP_ODOINPUTTYPE_RATE_MASK)) \
                              << (SBP_ODOINPUTTYPE_RATE_SHIFT)));    \
  } while (0)

#define SBP_ODOINPUTTYPE_RATE_FIXED_INCOMING_RATE (0)
#define SBP_ODOINPUTTYPE_RATE_TRIGGERED_BY_MINIMUM_DISTANCE_OR_SPEED (1)
#define SBP_ODOINPUTTYPE_ODOMETER_GRADE_MASK (0x3)
#define SBP_ODOINPUTTYPE_ODOMETER_GRADE_SHIFT (2u)
#define SBP_ODOINPUTTYPE_ODOMETER_GRADE_GET(flags)           \
  ((u8)(((flags) >> SBP_ODOINPUTTYPE_ODOMETER_GRADE_SHIFT) & \
        SBP_ODOINPUTTYPE_ODOMETER_GRADE_MASK))
#define SBP_ODOINPUTTYPE_ODOMETER_GRADE_SET(flags, val)                        \
  do {                                                                         \
    (flags) = (u8)((flags) | (((val) & (SBP_ODOINPUTTYPE_ODOMETER_GRADE_MASK)) \
                              << (SBP_ODOINPUTTYPE_ODOMETER_GRADE_SHIFT)));    \
  } while (0)

#define SBP_ODOINPUTTYPE_ODOMETER_GRADE_LOW_GRADE (0)
#define SBP_ODOINPUTTYPE_ODOMETER_GRADE_MEDIUM_GRADE (1)
#define SBP_ODOINPUTTYPE_ODOMETER_GRADE_SUPERIOR_GRADE (2)
#define SBP_ODOINPUTTYPE_ODOMETER_CLASS_MASK (0x3)
#define SBP_ODOINPUTTYPE_ODOMETER_CLASS_SHIFT (0u)
#define SBP_ODOINPUTTYPE_ODOMETER_CLASS_GET(flags)           \
  ((u8)(((flags) >> SBP_ODOINPUTTYPE_ODOMETER_CLASS_SHIFT) & \
        SBP_ODOINPUTTYPE_ODOMETER_CLASS_MASK))
#define SBP_ODOINPUTTYPE_ODOMETER_CLASS_SET(flags, val)                        \
  do {                                                                         \
    (flags) = (u8)((flags) | (((val) & (SBP_ODOINPUTTYPE_ODOMETER_CLASS_MASK)) \
                              << (SBP_ODOINPUTTYPE_ODOMETER_CLASS_SHIFT)));    \
  } while (0)

#define SBP_ODOINPUTTYPE_ODOMETER_CLASS_SINGLE_OR_AVERAGED_TICKS (0)
#define SBP_ODOINPUTTYPE_ODOMETER_CLASS_SINGLE_OR_AVERAGED_SPEED (1)
#define SBP_ODOINPUTTYPE_ODOMETER_CLASS_MULTI_DIMENSIONAL_TICKS (2)
#define SBP_ODOINPUTTYPE_ODOMETER_CLASS_MULTI_DIMENSIONAL_SPEED (3)
/**
 * Encoded length of sbp_odo_input_type_t (V4 API) and
 * odo_input_type_t (legacy API)
 */
#define SBP_ODO_INPUT_TYPE_ENCODED_LEN 1u

#endif /* LIBSBP_SOLUTION_META_MACROS_H */
