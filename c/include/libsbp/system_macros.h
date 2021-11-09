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
 * Automatically generated from yaml/swiftnav/sbp/system.yaml
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

#ifndef LIBSBP_SYSTEM_MACROS_H
#define LIBSBP_SYSTEM_MACROS_H

#define SBP_MSG_STARTUP 0xFF00
#define SBP_STARTUP_CAUSE_OF_STARTUP_MASK (0x1ff)
#define SBP_STARTUP_CAUSE_OF_STARTUP_SHIFT (0u)
#define SBP_STARTUP_CAUSE_OF_STARTUP_GET(flags)           \
  ((u8)(((flags) >> SBP_STARTUP_CAUSE_OF_STARTUP_SHIFT) & \
        SBP_STARTUP_CAUSE_OF_STARTUP_MASK))
#define SBP_STARTUP_CAUSE_OF_STARTUP_SET(flags, val)                        \
  do {                                                                      \
    (flags) = (u8)((flags) | (((val) & (SBP_STARTUP_CAUSE_OF_STARTUP_MASK)) \
                              << (SBP_STARTUP_CAUSE_OF_STARTUP_SHIFT)));    \
  } while (0)

#define SBP_STARTUP_CAUSE_OF_STARTUP_POWER_ON (0)
#define SBP_STARTUP_CAUSE_OF_STARTUP_SOFTWARE_RESET (1)
#define SBP_STARTUP_CAUSE_OF_STARTUP_WATCHDOG_RESET (2)
#define SBP_STARTUP__MASK (0x1ff)
#define SBP_STARTUP__SHIFT (0u)
#define SBP_STARTUP__GET(flags) \
  ((u8)(((flags) >> SBP_STARTUP__SHIFT) & SBP_STARTUP__MASK))
#define SBP_STARTUP__SET(flags, val)                                         \
  do {                                                                       \
    (flags) = (u8)((flags) |                                                 \
                   (((val) & (SBP_STARTUP__MASK)) << (SBP_STARTUP__SHIFT))); \
  } while (0)

#define SBP_STARTUP_COLD_START (0)
#define SBP_STARTUP_WARM_START (1)
#define SBP_STARTUP_WARM_START (1)
#define SBP_STARTUP_HOT_START (2)
#define SBP_STARTUP_HOT_START (2)
/**
 * Encoded length of sbp_msg_startup_t (V4 API) and
 * msg_startup_t (legacy API)
 */
#define SBP_MSG_STARTUP_ENCODED_LEN 4u

#define SBP_MSG_DGNSS_STATUS 0xFF02
#define SBP_DGNSS_STATUS_DIFFERENTIAL_TYPE_MASK (0xf)
#define SBP_DGNSS_STATUS_DIFFERENTIAL_TYPE_SHIFT (0u)
#define SBP_DGNSS_STATUS_DIFFERENTIAL_TYPE_GET(flags)           \
  ((u8)(((flags) >> SBP_DGNSS_STATUS_DIFFERENTIAL_TYPE_SHIFT) & \
        SBP_DGNSS_STATUS_DIFFERENTIAL_TYPE_MASK))
#define SBP_DGNSS_STATUS_DIFFERENTIAL_TYPE_SET(flags, val)                  \
  do {                                                                      \
    (flags) =                                                               \
        (u8)((flags) | (((val) & (SBP_DGNSS_STATUS_DIFFERENTIAL_TYPE_MASK)) \
                        << (SBP_DGNSS_STATUS_DIFFERENTIAL_TYPE_SHIFT)));    \
  } while (0)

#define SBP_DGNSS_STATUS_DIFFERENTIAL_TYPE_INVALID (0)
#define SBP_DGNSS_STATUS_DIFFERENTIAL_TYPE_CODE_DIFFERENCE (1)
#define SBP_DGNSS_STATUS_DIFFERENTIAL_TYPE_RTK (2)
/**
 * The maximum number of items that can be stored in
 * sbp_msg_dgnss_status_t::source (V4 API) or msg_dgnss_status_t::source (legacy
 * API) before the maximum SBP message size is exceeded
 */
#define SBP_MSG_DGNSS_STATUS_SOURCE_MAX 251u

/**
 * Encoded length of sbp_msg_dgnss_status_t (V4 API) and
 * msg_dgnss_status_t (legacy API)
 *
 * This type is not fixed size and an instance of this message may be longer
 * than the value indicated by this symbol. Users of the V4 API should call
 * #sbp_msg_dgnss_status_encoded_len to determine the actual size of an instance
 * of this message. Users of the legacy API are required to track the encoded
 * message length when interacting with the legacy type.
 *
 * See the documentation for libsbp for more details regarding the message
 * structure and its variable length component(s)
 */
#define SBP_MSG_DGNSS_STATUS_ENCODED_OVERHEAD 4u

#define SBP_MSG_HEARTBEAT 0xFFFF
#define SBP_HEARTBEAT_EXTERNAL_ANTENNA_PRESENT_MASK (0x1)
#define SBP_HEARTBEAT_EXTERNAL_ANTENNA_PRESENT_SHIFT (31u)
#define SBP_HEARTBEAT_EXTERNAL_ANTENNA_PRESENT_GET(flags)            \
  ((u32)(((flags) >> SBP_HEARTBEAT_EXTERNAL_ANTENNA_PRESENT_SHIFT) & \
         SBP_HEARTBEAT_EXTERNAL_ANTENNA_PRESENT_MASK))
#define SBP_HEARTBEAT_EXTERNAL_ANTENNA_PRESENT_SET(flags, val)               \
  do {                                                                       \
    (flags) = (u32)((flags) |                                                \
                    (((val) & (SBP_HEARTBEAT_EXTERNAL_ANTENNA_PRESENT_MASK)) \
                     << (SBP_HEARTBEAT_EXTERNAL_ANTENNA_PRESENT_SHIFT)));    \
  } while (0)

#define SBP_HEARTBEAT_EXTERNAL_ANTENNA_PRESENT_NO_EXTERNAL_ANTENNA_DETECTED (0)
#define SBP_HEARTBEAT_EXTERNAL_ANTENNA_PRESENT_EXTERNAL_ANTENNA_IS_PRESENT (1)
#define SBP_HEARTBEAT_EXTERNAL_ANTENNA_SHORT_MASK (0x1)
#define SBP_HEARTBEAT_EXTERNAL_ANTENNA_SHORT_SHIFT (30u)
#define SBP_HEARTBEAT_EXTERNAL_ANTENNA_SHORT_GET(flags)            \
  ((u32)(((flags) >> SBP_HEARTBEAT_EXTERNAL_ANTENNA_SHORT_SHIFT) & \
         SBP_HEARTBEAT_EXTERNAL_ANTENNA_SHORT_MASK))
#define SBP_HEARTBEAT_EXTERNAL_ANTENNA_SHORT_SET(flags, val)                   \
  do {                                                                         \
    (flags) =                                                                  \
        (u32)((flags) | (((val) & (SBP_HEARTBEAT_EXTERNAL_ANTENNA_SHORT_MASK)) \
                         << (SBP_HEARTBEAT_EXTERNAL_ANTENNA_SHORT_SHIFT)));    \
  } while (0)

#define SBP_HEARTBEAT_EXTERNAL_ANTENNA_SHORT_NO_SHORT_DETECTED (0)
#define SBP_HEARTBEAT_EXTERNAL_ANTENNA_SHORT_SHORT_DETECTED (1)
#define SBP_HEARTBEAT_SBP_MAJOR_PROTOCOL_VERSION_NUMBER_MASK (0xff)
#define SBP_HEARTBEAT_SBP_MAJOR_PROTOCOL_VERSION_NUMBER_SHIFT (16u)
#define SBP_HEARTBEAT_SBP_MAJOR_PROTOCOL_VERSION_NUMBER_GET(flags)            \
  ((u32)(((flags) >> SBP_HEARTBEAT_SBP_MAJOR_PROTOCOL_VERSION_NUMBER_SHIFT) & \
         SBP_HEARTBEAT_SBP_MAJOR_PROTOCOL_VERSION_NUMBER_MASK))
#define SBP_HEARTBEAT_SBP_MAJOR_PROTOCOL_VERSION_NUMBER_SET(flags, val)   \
  do {                                                                    \
    (flags) = (u32)(                                                      \
        (flags) |                                                         \
        (((val) & (SBP_HEARTBEAT_SBP_MAJOR_PROTOCOL_VERSION_NUMBER_MASK)) \
         << (SBP_HEARTBEAT_SBP_MAJOR_PROTOCOL_VERSION_NUMBER_SHIFT)));    \
  } while (0)

#define SBP_HEARTBEAT_SBP_MINOR_PROTOCOL_VERSION_NUMBER_MASK (0xff)
#define SBP_HEARTBEAT_SBP_MINOR_PROTOCOL_VERSION_NUMBER_SHIFT (8u)
#define SBP_HEARTBEAT_SBP_MINOR_PROTOCOL_VERSION_NUMBER_GET(flags)            \
  ((u32)(((flags) >> SBP_HEARTBEAT_SBP_MINOR_PROTOCOL_VERSION_NUMBER_SHIFT) & \
         SBP_HEARTBEAT_SBP_MINOR_PROTOCOL_VERSION_NUMBER_MASK))
#define SBP_HEARTBEAT_SBP_MINOR_PROTOCOL_VERSION_NUMBER_SET(flags, val)   \
  do {                                                                    \
    (flags) = (u32)(                                                      \
        (flags) |                                                         \
        (((val) & (SBP_HEARTBEAT_SBP_MINOR_PROTOCOL_VERSION_NUMBER_MASK)) \
         << (SBP_HEARTBEAT_SBP_MINOR_PROTOCOL_VERSION_NUMBER_SHIFT)));    \
  } while (0)

#define SBP_HEARTBEAT_SWIFTNAP_ERROR_MASK (0x1)
#define SBP_HEARTBEAT_SWIFTNAP_ERROR_SHIFT (2u)
#define SBP_HEARTBEAT_SWIFTNAP_ERROR_GET(flags)            \
  ((u32)(((flags) >> SBP_HEARTBEAT_SWIFTNAP_ERROR_SHIFT) & \
         SBP_HEARTBEAT_SWIFTNAP_ERROR_MASK))
#define SBP_HEARTBEAT_SWIFTNAP_ERROR_SET(flags, val)                         \
  do {                                                                       \
    (flags) = (u32)((flags) | (((val) & (SBP_HEARTBEAT_SWIFTNAP_ERROR_MASK)) \
                               << (SBP_HEARTBEAT_SWIFTNAP_ERROR_SHIFT)));    \
  } while (0)

#define SBP_HEARTBEAT_SWIFTNAP_ERROR_SYSTEM_HEALTHY (0)
#define SBP_HEARTBEAT_SWIFTNAP_ERROR_AN_ERROR_HAS_OCCURRED_IN_THE_SWIFTNAP (1)
#define SBP_HEARTBEAT_IO_ERROR_MASK (0x1)
#define SBP_HEARTBEAT_IO_ERROR_SHIFT (1u)
#define SBP_HEARTBEAT_IO_ERROR_GET(flags)            \
  ((u32)(((flags) >> SBP_HEARTBEAT_IO_ERROR_SHIFT) & \
         SBP_HEARTBEAT_IO_ERROR_MASK))
#define SBP_HEARTBEAT_IO_ERROR_SET(flags, val)                         \
  do {                                                                 \
    (flags) = (u32)((flags) | (((val) & (SBP_HEARTBEAT_IO_ERROR_MASK)) \
                               << (SBP_HEARTBEAT_IO_ERROR_SHIFT)));    \
  } while (0)

#define SBP_HEARTBEAT_IO_ERROR_SYSTEM_HEALTHY (0)
#define SBP_HEARTBEAT_IO_ERROR_AN_IO_ERROR_HAS_OCCURRED (1)
#define SBP_HEARTBEAT_SYSTEM_ERROR_FLAG_MASK (0x1)
#define SBP_HEARTBEAT_SYSTEM_ERROR_FLAG_SHIFT (0u)
#define SBP_HEARTBEAT_SYSTEM_ERROR_FLAG_GET(flags)            \
  ((u32)(((flags) >> SBP_HEARTBEAT_SYSTEM_ERROR_FLAG_SHIFT) & \
         SBP_HEARTBEAT_SYSTEM_ERROR_FLAG_MASK))
#define SBP_HEARTBEAT_SYSTEM_ERROR_FLAG_SET(flags, val)                   \
  do {                                                                    \
    (flags) =                                                             \
        (u32)((flags) | (((val) & (SBP_HEARTBEAT_SYSTEM_ERROR_FLAG_MASK)) \
                         << (SBP_HEARTBEAT_SYSTEM_ERROR_FLAG_SHIFT)));    \
  } while (0)

#define SBP_HEARTBEAT_SYSTEM_ERROR_FLAG_SYSTEM_HEALTHY (0)
#define SBP_HEARTBEAT_SYSTEM_ERROR_FLAG_AN_ERROR_HAS_OCCURRED (1)
/**
 * Encoded length of sbp_msg_heartbeat_t (V4 API) and
 * msg_heartbeat_t (legacy API)
 */
#define SBP_MSG_HEARTBEAT_ENCODED_LEN 4u

#define SBP_SUBSYSTEMREPORT_SUBSYSTEM_MASK (0xffff)
#define SBP_SUBSYSTEMREPORT_SUBSYSTEM_SHIFT (0u)
#define SBP_SUBSYSTEMREPORT_SUBSYSTEM_GET(flags)            \
  ((u16)(((flags) >> SBP_SUBSYSTEMREPORT_SUBSYSTEM_SHIFT) & \
         SBP_SUBSYSTEMREPORT_SUBSYSTEM_MASK))
#define SBP_SUBSYSTEMREPORT_SUBSYSTEM_SET(flags, val)                         \
  do {                                                                        \
    (flags) = (u16)((flags) | (((val) & (SBP_SUBSYSTEMREPORT_SUBSYSTEM_MASK)) \
                               << (SBP_SUBSYSTEMREPORT_SUBSYSTEM_SHIFT)));    \
  } while (0)

#define SBP_SUBSYSTEMREPORT_SUBSYSTEM_PRIMARY_GNSS_ANTENNA (0)
#define SBP_SUBSYSTEMREPORT_SUBSYSTEM_MEASUREMENT_ENGINE (1)
#define SBP_SUBSYSTEMREPORT_SUBSYSTEM_CORRECTIONS_CLIENT (2)
#define SBP_SUBSYSTEMREPORT_SUBSYSTEM_DIFFERENTIAL_GNSS_ENGINE (3)
#define SBP_SUBSYSTEMREPORT_SUBSYSTEM_CAN (4)
#define SBP_SUBSYSTEMREPORT_SUBSYSTEM_WHEEL_ODOMETRY (5)
#define SBP_SUBSYSTEMREPORT_SUBSYSTEM_SENSOR_FUSION_ENGINE (6)
#define SBP_SUBSYSTEMREPORT_GENERIC_MASK (0xff)
#define SBP_SUBSYSTEMREPORT_GENERIC_SHIFT (0u)
#define SBP_SUBSYSTEMREPORT_GENERIC_GET(flags)           \
  ((u8)(((flags) >> SBP_SUBSYSTEMREPORT_GENERIC_SHIFT) & \
        SBP_SUBSYSTEMREPORT_GENERIC_MASK))
#define SBP_SUBSYSTEMREPORT_GENERIC_SET(flags, val)                        \
  do {                                                                     \
    (flags) = (u8)((flags) | (((val) & (SBP_SUBSYSTEMREPORT_GENERIC_MASK)) \
                              << (SBP_SUBSYSTEMREPORT_GENERIC_SHIFT)));    \
  } while (0)

#define SBP_SUBSYSTEMREPORT_GENERIC_OKNOMINAL (0)
#define SBP_SUBSYSTEMREPORT_GENERIC_INITIALIZING (1)
#define SBP_SUBSYSTEMREPORT_GENERIC_UNKNOWN (2)
#define SBP_SUBSYSTEMREPORT_GENERIC_DEGRADED (3)
#define SBP_SUBSYSTEMREPORT_GENERIC_UNUSABLE (4)
/**
 * Encoded length of sbp_sub_system_report_t (V4 API) and
 * sub_system_report_t (legacy API)
 */
#define SBP_SUB_SYSTEM_REPORT_ENCODED_LEN 4u

#define SBP_MSG_STATUS_REPORT 0xFFFE
#define SBP_STATUS_REPORT_SYSTEM_MASK (0xffff)
#define SBP_STATUS_REPORT_SYSTEM_SHIFT (0u)
#define SBP_STATUS_REPORT_SYSTEM_GET(flags)            \
  ((u16)(((flags) >> SBP_STATUS_REPORT_SYSTEM_SHIFT) & \
         SBP_STATUS_REPORT_SYSTEM_MASK))
#define SBP_STATUS_REPORT_SYSTEM_SET(flags, val)                         \
  do {                                                                   \
    (flags) = (u16)((flags) | (((val) & (SBP_STATUS_REPORT_SYSTEM_MASK)) \
                               << (SBP_STATUS_REPORT_SYSTEM_SHIFT)));    \
  } while (0)

#define SBP_STATUS_REPORT_SYSTEM_STARLING (0)
#define SBP_STATUS_REPORT_SYSTEM_PRECISION_GNSS_MODULE (1)
#define SBP_STATUS_REPORT_SBP_MAJOR_PROTOCOL_VERSION_NUMBER_MASK (0x1ff)
#define SBP_STATUS_REPORT_SBP_MAJOR_PROTOCOL_VERSION_NUMBER_SHIFT (8u)
#define SBP_STATUS_REPORT_SBP_MAJOR_PROTOCOL_VERSION_NUMBER_GET(flags)         \
  ((u16)(                                                                      \
      ((flags) >> SBP_STATUS_REPORT_SBP_MAJOR_PROTOCOL_VERSION_NUMBER_SHIFT) & \
      SBP_STATUS_REPORT_SBP_MAJOR_PROTOCOL_VERSION_NUMBER_MASK))
#define SBP_STATUS_REPORT_SBP_MAJOR_PROTOCOL_VERSION_NUMBER_SET(flags, val)   \
  do {                                                                        \
    (flags) = (u16)(                                                          \
        (flags) |                                                             \
        (((val) & (SBP_STATUS_REPORT_SBP_MAJOR_PROTOCOL_VERSION_NUMBER_MASK)) \
         << (SBP_STATUS_REPORT_SBP_MAJOR_PROTOCOL_VERSION_NUMBER_SHIFT)));    \
  } while (0)

#define SBP_STATUS_REPORT_SBP_MINOR_PROTOCOL_VERSION_NUMBER_MASK (0xff)
#define SBP_STATUS_REPORT_SBP_MINOR_PROTOCOL_VERSION_NUMBER_SHIFT (0u)
#define SBP_STATUS_REPORT_SBP_MINOR_PROTOCOL_VERSION_NUMBER_GET(flags)         \
  ((u16)(                                                                      \
      ((flags) >> SBP_STATUS_REPORT_SBP_MINOR_PROTOCOL_VERSION_NUMBER_SHIFT) & \
      SBP_STATUS_REPORT_SBP_MINOR_PROTOCOL_VERSION_NUMBER_MASK))
#define SBP_STATUS_REPORT_SBP_MINOR_PROTOCOL_VERSION_NUMBER_SET(flags, val)   \
  do {                                                                        \
    (flags) = (u16)(                                                          \
        (flags) |                                                             \
        (((val) & (SBP_STATUS_REPORT_SBP_MINOR_PROTOCOL_VERSION_NUMBER_MASK)) \
         << (SBP_STATUS_REPORT_SBP_MINOR_PROTOCOL_VERSION_NUMBER_SHIFT)));    \
  } while (0)

/**
 * The maximum number of items that can be stored in
 * sbp_msg_status_report_t::status (V4 API) or msg_status_report_t::status
 * (legacy API) before the maximum SBP message size is exceeded
 */
#define SBP_MSG_STATUS_REPORT_STATUS_MAX 60u

/**
 * Encoded length of sbp_msg_status_report_t (V4 API) and
 * msg_status_report_t (legacy API)
 *
 * This type is not fixed size and an instance of this message may be longer
 * than the value indicated by this symbol. Users of the V4 API should call
 * #sbp_msg_status_report_encoded_len to determine the actual size of an
 * instance of this message. Users of the legacy API are required to track the
 * encoded message length when interacting with the legacy type.
 *
 * See the documentation for libsbp for more details regarding the message
 * structure and its variable length component(s)
 */
#define SBP_MSG_STATUS_REPORT_ENCODED_OVERHEAD 12u

#define SBP_MSG_INS_STATUS 0xFF03
#define SBP_INS_STATUS_INS_TYPE_MASK (0x7)
#define SBP_INS_STATUS_INS_TYPE_SHIFT (29u)
#define SBP_INS_STATUS_INS_TYPE_GET(flags)            \
  ((u32)(((flags) >> SBP_INS_STATUS_INS_TYPE_SHIFT) & \
         SBP_INS_STATUS_INS_TYPE_MASK))
#define SBP_INS_STATUS_INS_TYPE_SET(flags, val)                         \
  do {                                                                  \
    (flags) = (u32)((flags) | (((val) & (SBP_INS_STATUS_INS_TYPE_MASK)) \
                               << (SBP_INS_STATUS_INS_TYPE_SHIFT)));    \
  } while (0)

#define SBP_INS_STATUS_INS_TYPE_SMOOTHPOSE_LOOSELY_COUPLED (0)
#define SBP_INS_STATUS_INS_TYPE_STARLING (1)
#define SBP_INS_STATUS_MOTION_STATE_MASK (0x7)
#define SBP_INS_STATUS_MOTION_STATE_SHIFT (11u)
#define SBP_INS_STATUS_MOTION_STATE_GET(flags)            \
  ((u32)(((flags) >> SBP_INS_STATUS_MOTION_STATE_SHIFT) & \
         SBP_INS_STATUS_MOTION_STATE_MASK))
#define SBP_INS_STATUS_MOTION_STATE_SET(flags, val)                         \
  do {                                                                      \
    (flags) = (u32)((flags) | (((val) & (SBP_INS_STATUS_MOTION_STATE_MASK)) \
                               << (SBP_INS_STATUS_MOTION_STATE_SHIFT)));    \
  } while (0)

#define SBP_INS_STATUS_MOTION_STATE_UNKNOWN_OR_INIT (0)
#define SBP_INS_STATUS_MOTION_STATE_ARBITRARY_MOTION (1)
#define SBP_INS_STATUS_MOTION_STATE_STRAIGHT_MOTION (2)
#define SBP_INS_STATUS_MOTION_STATE_STATIONARY (3)
#define SBP_INS_STATUS_ODOMETRY_SYNCH_MASK (0x1)
#define SBP_INS_STATUS_ODOMETRY_SYNCH_SHIFT (10u)
#define SBP_INS_STATUS_ODOMETRY_SYNCH_GET(flags)            \
  ((u32)(((flags) >> SBP_INS_STATUS_ODOMETRY_SYNCH_SHIFT) & \
         SBP_INS_STATUS_ODOMETRY_SYNCH_MASK))
#define SBP_INS_STATUS_ODOMETRY_SYNCH_SET(flags, val)                         \
  do {                                                                        \
    (flags) = (u32)((flags) | (((val) & (SBP_INS_STATUS_ODOMETRY_SYNCH_MASK)) \
                               << (SBP_INS_STATUS_ODOMETRY_SYNCH_SHIFT)));    \
  } while (0)

#define SBP_INS_STATUS_ODOMETRY_SYNCH_ODOMETRY_TIMESTAMP_NOMINAL (0)
#define SBP_INS_STATUS_ODOMETRY_SYNCH_ODOMETRY_TIMESTAMP_OUT_OF_BOUNDS (1)
#define SBP_INS_STATUS_ODOMETRY_STATUS_MASK (0x3)
#define SBP_INS_STATUS_ODOMETRY_STATUS_SHIFT (8u)
#define SBP_INS_STATUS_ODOMETRY_STATUS_GET(flags)            \
  ((u32)(((flags) >> SBP_INS_STATUS_ODOMETRY_STATUS_SHIFT) & \
         SBP_INS_STATUS_ODOMETRY_STATUS_MASK))
#define SBP_INS_STATUS_ODOMETRY_STATUS_SET(flags, val)                         \
  do {                                                                         \
    (flags) = (u32)((flags) | (((val) & (SBP_INS_STATUS_ODOMETRY_STATUS_MASK)) \
                               << (SBP_INS_STATUS_ODOMETRY_STATUS_SHIFT)));    \
  } while (0)

#define SBP_INS_STATUS_ODOMETRY_STATUS_NO_ODOMETRY (0)
#define SBP_INS_STATUS_ODOMETRY_STATUS_ODOMETRY_RECEIVED_WITHIN_LAST_SECOND (1)
#define SBP_INS_STATUS_ODOMETRY_STATUS_ODOMETRY_NOT_RECEIVED_WITHIN_LAST_SECOND \
  (2)
#define SBP_INS_STATUS_INS_ERROR_MASK (0xf)
#define SBP_INS_STATUS_INS_ERROR_SHIFT (4u)
#define SBP_INS_STATUS_INS_ERROR_GET(flags)            \
  ((u32)(((flags) >> SBP_INS_STATUS_INS_ERROR_SHIFT) & \
         SBP_INS_STATUS_INS_ERROR_MASK))
#define SBP_INS_STATUS_INS_ERROR_SET(flags, val)                         \
  do {                                                                   \
    (flags) = (u32)((flags) | (((val) & (SBP_INS_STATUS_INS_ERROR_MASK)) \
                               << (SBP_INS_STATUS_INS_ERROR_SHIFT)));    \
  } while (0)

#define SBP_INS_STATUS_INS_ERROR_IMU_DATA_ERROR (1)
#define SBP_INS_STATUS_INS_ERROR_INS_LICENSE_ERROR (2)
#define SBP_INS_STATUS_INS_ERROR_IMU_CALIBRATION_DATA_ERROR (3)
#define SBP_INS_STATUS_GNSS_FIX_MASK (0x1)
#define SBP_INS_STATUS_GNSS_FIX_SHIFT (3u)
#define SBP_INS_STATUS_GNSS_FIX_GET(flags)            \
  ((u32)(((flags) >> SBP_INS_STATUS_GNSS_FIX_SHIFT) & \
         SBP_INS_STATUS_GNSS_FIX_MASK))
#define SBP_INS_STATUS_GNSS_FIX_SET(flags, val)                         \
  do {                                                                  \
    (flags) = (u32)((flags) | (((val) & (SBP_INS_STATUS_GNSS_FIX_MASK)) \
                               << (SBP_INS_STATUS_GNSS_FIX_SHIFT)));    \
  } while (0)

#define SBP_INS_STATUS_GNSS_FIX_NO_GNSS_FIX_AVAILABLE (0)
#define SBP_INS_STATUS_GNSS_FIX_GNSS_FIX (1)
#define SBP_INS_STATUS_MODE_MASK (0x7)
#define SBP_INS_STATUS_MODE_SHIFT (0u)
#define SBP_INS_STATUS_MODE_GET(flags) \
  ((u32)(((flags) >> SBP_INS_STATUS_MODE_SHIFT) & SBP_INS_STATUS_MODE_MASK))
#define SBP_INS_STATUS_MODE_SET(flags, val)                         \
  do {                                                              \
    (flags) = (u32)((flags) | (((val) & (SBP_INS_STATUS_MODE_MASK)) \
                               << (SBP_INS_STATUS_MODE_SHIFT)));    \
  } while (0)

#define SBP_INS_STATUS_MODE_AWAITING_INITIALIZATION (0)
#define SBP_INS_STATUS_MODE_DYNAMICALLY_ALIGNING (1)
#define SBP_INS_STATUS_MODE_READY (2)
#define SBP_INS_STATUS_MODE_GNSS_OUTAGE_EXCEEDS_MAX_DURATION (3)
#define SBP_INS_STATUS_MODE_FASTSTART_SEEDING (4)
#define SBP_INS_STATUS_MODE_FASTSTART_VALIDATING (5)
#define SBP_INS_STATUS_MODE_VALIDATING_UNSAFE_FAST_START_SEED (6)
/**
 * Encoded length of sbp_msg_ins_status_t (V4 API) and
 * msg_ins_status_t (legacy API)
 */
#define SBP_MSG_INS_STATUS_ENCODED_LEN 4u

#define SBP_MSG_CSAC_TELEMETRY 0xFF04
/**
 * The maximum number of items that can be stored in
 * sbp_msg_csac_telemetry_t::telemetry (V4 API) or
 * msg_csac_telemetry_t::telemetry (legacy API) before the maximum SBP message
 * size is exceeded
 */
#define SBP_MSG_CSAC_TELEMETRY_TELEMETRY_MAX 254u

/**
 * Encoded length of sbp_msg_csac_telemetry_t (V4 API) and
 * msg_csac_telemetry_t (legacy API)
 *
 * This type is not fixed size and an instance of this message may be longer
 * than the value indicated by this symbol. Users of the V4 API should call
 * #sbp_msg_csac_telemetry_encoded_len to determine the actual size of an
 * instance of this message. Users of the legacy API are required to track the
 * encoded message length when interacting with the legacy type.
 *
 * See the documentation for libsbp for more details regarding the message
 * structure and its variable length component(s)
 */
#define SBP_MSG_CSAC_TELEMETRY_ENCODED_OVERHEAD 1u

#define SBP_MSG_CSAC_TELEMETRY_LABELS 0xFF05
/**
 * The maximum number of items that can be stored in
 * sbp_msg_csac_telemetry_labels_t::telemetry_labels (V4 API) or
 * msg_csac_telemetry_labels_t::telemetry_labels (legacy API) before the maximum
 * SBP message size is exceeded
 */
#define SBP_MSG_CSAC_TELEMETRY_LABELS_TELEMETRY_LABELS_MAX 254u

/**
 * Encoded length of sbp_msg_csac_telemetry_labels_t (V4 API) and
 * msg_csac_telemetry_labels_t (legacy API)
 *
 * This type is not fixed size and an instance of this message may be longer
 * than the value indicated by this symbol. Users of the V4 API should call
 * #sbp_msg_csac_telemetry_labels_encoded_len to determine the actual size of an
 * instance of this message. Users of the legacy API are required to track the
 * encoded message length when interacting with the legacy type.
 *
 * See the documentation for libsbp for more details regarding the message
 * structure and its variable length component(s)
 */
#define SBP_MSG_CSAC_TELEMETRY_LABELS_ENCODED_OVERHEAD 1u

#define SBP_MSG_INS_UPDATES 0xFF06
#define SBP_INS_UPDATES_NUMBER_OF_ATTEMPTED_GNSS_POSITION_UPDATES_SINCE_LAST_MESSAGE_MASK \
  (0xf)
#define SBP_INS_UPDATES_NUMBER_OF_ATTEMPTED_GNSS_POSITION_UPDATES_SINCE_LAST_MESSAGE_SHIFT \
  (4u)
#define SBP_INS_UPDATES_NUMBER_OF_ATTEMPTED_GNSS_POSITION_UPDATES_SINCE_LAST_MESSAGE_GET(    \
    flags)                                                                                   \
  ((u8)(                                                                                     \
      ((flags) >>                                                                            \
       SBP_INS_UPDATES_NUMBER_OF_ATTEMPTED_GNSS_POSITION_UPDATES_SINCE_LAST_MESSAGE_SHIFT) & \
      SBP_INS_UPDATES_NUMBER_OF_ATTEMPTED_GNSS_POSITION_UPDATES_SINCE_LAST_MESSAGE_MASK))
#define SBP_INS_UPDATES_NUMBER_OF_ATTEMPTED_GNSS_POSITION_UPDATES_SINCE_LAST_MESSAGE_SET(           \
    flags, val)                                                                                     \
  do {                                                                                              \
    (flags) = (u8)(                                                                                 \
        (flags) |                                                                                   \
        (((val) &                                                                                   \
          (SBP_INS_UPDATES_NUMBER_OF_ATTEMPTED_GNSS_POSITION_UPDATES_SINCE_LAST_MESSAGE_MASK))      \
         << (SBP_INS_UPDATES_NUMBER_OF_ATTEMPTED_GNSS_POSITION_UPDATES_SINCE_LAST_MESSAGE_SHIFT))); \
  } while (0)

#define SBP_INS_UPDATES_NUMBER_OF_REJECTED_GNSS_POSITION_UPDATES_SINCE_LAST_MESSAGE_MASK \
  (0xf)
#define SBP_INS_UPDATES_NUMBER_OF_REJECTED_GNSS_POSITION_UPDATES_SINCE_LAST_MESSAGE_SHIFT \
  (0u)
#define SBP_INS_UPDATES_NUMBER_OF_REJECTED_GNSS_POSITION_UPDATES_SINCE_LAST_MESSAGE_GET(    \
    flags)                                                                                  \
  ((u8)(                                                                                    \
      ((flags) >>                                                                           \
       SBP_INS_UPDATES_NUMBER_OF_REJECTED_GNSS_POSITION_UPDATES_SINCE_LAST_MESSAGE_SHIFT) & \
      SBP_INS_UPDATES_NUMBER_OF_REJECTED_GNSS_POSITION_UPDATES_SINCE_LAST_MESSAGE_MASK))
#define SBP_INS_UPDATES_NUMBER_OF_REJECTED_GNSS_POSITION_UPDATES_SINCE_LAST_MESSAGE_SET(           \
    flags, val)                                                                                    \
  do {                                                                                             \
    (flags) = (u8)(                                                                                \
        (flags) |                                                                                  \
        (((val) &                                                                                  \
          (SBP_INS_UPDATES_NUMBER_OF_REJECTED_GNSS_POSITION_UPDATES_SINCE_LAST_MESSAGE_MASK))      \
         << (SBP_INS_UPDATES_NUMBER_OF_REJECTED_GNSS_POSITION_UPDATES_SINCE_LAST_MESSAGE_SHIFT))); \
  } while (0)

#define SBP_INS_UPDATES_NUMBER_OF_ATTEMPTED_GNSS_VELOCITY_UPDATES_SINCE_LAST_MESSAGE_MASK \
  (0xf)
#define SBP_INS_UPDATES_NUMBER_OF_ATTEMPTED_GNSS_VELOCITY_UPDATES_SINCE_LAST_MESSAGE_SHIFT \
  (4u)
#define SBP_INS_UPDATES_NUMBER_OF_ATTEMPTED_GNSS_VELOCITY_UPDATES_SINCE_LAST_MESSAGE_GET(    \
    flags)                                                                                   \
  ((u8)(                                                                                     \
      ((flags) >>                                                                            \
       SBP_INS_UPDATES_NUMBER_OF_ATTEMPTED_GNSS_VELOCITY_UPDATES_SINCE_LAST_MESSAGE_SHIFT) & \
      SBP_INS_UPDATES_NUMBER_OF_ATTEMPTED_GNSS_VELOCITY_UPDATES_SINCE_LAST_MESSAGE_MASK))
#define SBP_INS_UPDATES_NUMBER_OF_ATTEMPTED_GNSS_VELOCITY_UPDATES_SINCE_LAST_MESSAGE_SET(           \
    flags, val)                                                                                     \
  do {                                                                                              \
    (flags) = (u8)(                                                                                 \
        (flags) |                                                                                   \
        (((val) &                                                                                   \
          (SBP_INS_UPDATES_NUMBER_OF_ATTEMPTED_GNSS_VELOCITY_UPDATES_SINCE_LAST_MESSAGE_MASK))      \
         << (SBP_INS_UPDATES_NUMBER_OF_ATTEMPTED_GNSS_VELOCITY_UPDATES_SINCE_LAST_MESSAGE_SHIFT))); \
  } while (0)

#define SBP_INS_UPDATES_NUMBER_OF_REJECTED_GNSS_VELOCITY_UPDATES_SINCE_LAST_MESSAGE_MASK \
  (0xf)
#define SBP_INS_UPDATES_NUMBER_OF_REJECTED_GNSS_VELOCITY_UPDATES_SINCE_LAST_MESSAGE_SHIFT \
  (0u)
#define SBP_INS_UPDATES_NUMBER_OF_REJECTED_GNSS_VELOCITY_UPDATES_SINCE_LAST_MESSAGE_GET(    \
    flags)                                                                                  \
  ((u8)(                                                                                    \
      ((flags) >>                                                                           \
       SBP_INS_UPDATES_NUMBER_OF_REJECTED_GNSS_VELOCITY_UPDATES_SINCE_LAST_MESSAGE_SHIFT) & \
      SBP_INS_UPDATES_NUMBER_OF_REJECTED_GNSS_VELOCITY_UPDATES_SINCE_LAST_MESSAGE_MASK))
#define SBP_INS_UPDATES_NUMBER_OF_REJECTED_GNSS_VELOCITY_UPDATES_SINCE_LAST_MESSAGE_SET(           \
    flags, val)                                                                                    \
  do {                                                                                             \
    (flags) = (u8)(                                                                                \
        (flags) |                                                                                  \
        (((val) &                                                                                  \
          (SBP_INS_UPDATES_NUMBER_OF_REJECTED_GNSS_VELOCITY_UPDATES_SINCE_LAST_MESSAGE_MASK))      \
         << (SBP_INS_UPDATES_NUMBER_OF_REJECTED_GNSS_VELOCITY_UPDATES_SINCE_LAST_MESSAGE_SHIFT))); \
  } while (0)

#define SBP_INS_UPDATES_NUMBER_OF_ATTEMPTED_WHEELTICK_UPDATES_SINCE_LAST_MESSAGE_MASK \
  (0xf)
#define SBP_INS_UPDATES_NUMBER_OF_ATTEMPTED_WHEELTICK_UPDATES_SINCE_LAST_MESSAGE_SHIFT \
  (4u)
#define SBP_INS_UPDATES_NUMBER_OF_ATTEMPTED_WHEELTICK_UPDATES_SINCE_LAST_MESSAGE_GET(    \
    flags)                                                                               \
  ((u8)(                                                                                 \
      ((flags) >>                                                                        \
       SBP_INS_UPDATES_NUMBER_OF_ATTEMPTED_WHEELTICK_UPDATES_SINCE_LAST_MESSAGE_SHIFT) & \
      SBP_INS_UPDATES_NUMBER_OF_ATTEMPTED_WHEELTICK_UPDATES_SINCE_LAST_MESSAGE_MASK))
#define SBP_INS_UPDATES_NUMBER_OF_ATTEMPTED_WHEELTICK_UPDATES_SINCE_LAST_MESSAGE_SET(           \
    flags, val)                                                                                 \
  do {                                                                                          \
    (flags) = (u8)(                                                                             \
        (flags) |                                                                               \
        (((val) &                                                                               \
          (SBP_INS_UPDATES_NUMBER_OF_ATTEMPTED_WHEELTICK_UPDATES_SINCE_LAST_MESSAGE_MASK))      \
         << (SBP_INS_UPDATES_NUMBER_OF_ATTEMPTED_WHEELTICK_UPDATES_SINCE_LAST_MESSAGE_SHIFT))); \
  } while (0)

#define SBP_INS_UPDATES_NUMBER_OF_REJECTED_WHEELTICK_UPDATES_SINCE_LAST_MESSAGE_MASK \
  (0xf)
#define SBP_INS_UPDATES_NUMBER_OF_REJECTED_WHEELTICK_UPDATES_SINCE_LAST_MESSAGE_SHIFT \
  (0u)
#define SBP_INS_UPDATES_NUMBER_OF_REJECTED_WHEELTICK_UPDATES_SINCE_LAST_MESSAGE_GET(    \
    flags)                                                                              \
  ((u8)(                                                                                \
      ((flags) >>                                                                       \
       SBP_INS_UPDATES_NUMBER_OF_REJECTED_WHEELTICK_UPDATES_SINCE_LAST_MESSAGE_SHIFT) & \
      SBP_INS_UPDATES_NUMBER_OF_REJECTED_WHEELTICK_UPDATES_SINCE_LAST_MESSAGE_MASK))
#define SBP_INS_UPDATES_NUMBER_OF_REJECTED_WHEELTICK_UPDATES_SINCE_LAST_MESSAGE_SET(           \
    flags, val)                                                                                \
  do {                                                                                         \
    (flags) = (u8)(                                                                            \
        (flags) |                                                                              \
        (((val) &                                                                              \
          (SBP_INS_UPDATES_NUMBER_OF_REJECTED_WHEELTICK_UPDATES_SINCE_LAST_MESSAGE_MASK))      \
         << (SBP_INS_UPDATES_NUMBER_OF_REJECTED_WHEELTICK_UPDATES_SINCE_LAST_MESSAGE_SHIFT))); \
  } while (0)

#define SBP_INS_UPDATES_NUMBER_OF_ATTEMPTED_SPEED_UPDATES_SINCE_LAST_MESSAGE_MASK \
  (0xf)
#define SBP_INS_UPDATES_NUMBER_OF_ATTEMPTED_SPEED_UPDATES_SINCE_LAST_MESSAGE_SHIFT \
  (4u)
#define SBP_INS_UPDATES_NUMBER_OF_ATTEMPTED_SPEED_UPDATES_SINCE_LAST_MESSAGE_GET(    \
    flags)                                                                           \
  ((u8)(                                                                             \
      ((flags) >>                                                                    \
       SBP_INS_UPDATES_NUMBER_OF_ATTEMPTED_SPEED_UPDATES_SINCE_LAST_MESSAGE_SHIFT) & \
      SBP_INS_UPDATES_NUMBER_OF_ATTEMPTED_SPEED_UPDATES_SINCE_LAST_MESSAGE_MASK))
#define SBP_INS_UPDATES_NUMBER_OF_ATTEMPTED_SPEED_UPDATES_SINCE_LAST_MESSAGE_SET(           \
    flags, val)                                                                             \
  do {                                                                                      \
    (flags) = (u8)(                                                                         \
        (flags) |                                                                           \
        (((val) &                                                                           \
          (SBP_INS_UPDATES_NUMBER_OF_ATTEMPTED_SPEED_UPDATES_SINCE_LAST_MESSAGE_MASK))      \
         << (SBP_INS_UPDATES_NUMBER_OF_ATTEMPTED_SPEED_UPDATES_SINCE_LAST_MESSAGE_SHIFT))); \
  } while (0)

#define SBP_INS_UPDATES_NUMBER_OF_REJECTED_SPEED_UPDATES_SINCE_LAST_MESSAGE_MASK \
  (0xf)
#define SBP_INS_UPDATES_NUMBER_OF_REJECTED_SPEED_UPDATES_SINCE_LAST_MESSAGE_SHIFT \
  (0u)
#define SBP_INS_UPDATES_NUMBER_OF_REJECTED_SPEED_UPDATES_SINCE_LAST_MESSAGE_GET(    \
    flags)                                                                          \
  ((u8)(                                                                            \
      ((flags) >>                                                                   \
       SBP_INS_UPDATES_NUMBER_OF_REJECTED_SPEED_UPDATES_SINCE_LAST_MESSAGE_SHIFT) & \
      SBP_INS_UPDATES_NUMBER_OF_REJECTED_SPEED_UPDATES_SINCE_LAST_MESSAGE_MASK))
#define SBP_INS_UPDATES_NUMBER_OF_REJECTED_SPEED_UPDATES_SINCE_LAST_MESSAGE_SET(           \
    flags, val)                                                                            \
  do {                                                                                     \
    (flags) = (u8)(                                                                        \
        (flags) |                                                                          \
        (((val) &                                                                          \
          (SBP_INS_UPDATES_NUMBER_OF_REJECTED_SPEED_UPDATES_SINCE_LAST_MESSAGE_MASK))      \
         << (SBP_INS_UPDATES_NUMBER_OF_REJECTED_SPEED_UPDATES_SINCE_LAST_MESSAGE_SHIFT))); \
  } while (0)

#define SBP_INS_UPDATES_NUMBER_OF_ATTEMPTED_NHC_UPDATES_SINCE_LAST_MESSAGE_MASK \
  (0xf)
#define SBP_INS_UPDATES_NUMBER_OF_ATTEMPTED_NHC_UPDATES_SINCE_LAST_MESSAGE_SHIFT \
  (4u)
#define SBP_INS_UPDATES_NUMBER_OF_ATTEMPTED_NHC_UPDATES_SINCE_LAST_MESSAGE_GET(    \
    flags)                                                                         \
  ((u8)(                                                                           \
      ((flags) >>                                                                  \
       SBP_INS_UPDATES_NUMBER_OF_ATTEMPTED_NHC_UPDATES_SINCE_LAST_MESSAGE_SHIFT) & \
      SBP_INS_UPDATES_NUMBER_OF_ATTEMPTED_NHC_UPDATES_SINCE_LAST_MESSAGE_MASK))
#define SBP_INS_UPDATES_NUMBER_OF_ATTEMPTED_NHC_UPDATES_SINCE_LAST_MESSAGE_SET(           \
    flags, val)                                                                           \
  do {                                                                                    \
    (flags) = (u8)(                                                                       \
        (flags) |                                                                         \
        (((val) &                                                                         \
          (SBP_INS_UPDATES_NUMBER_OF_ATTEMPTED_NHC_UPDATES_SINCE_LAST_MESSAGE_MASK))      \
         << (SBP_INS_UPDATES_NUMBER_OF_ATTEMPTED_NHC_UPDATES_SINCE_LAST_MESSAGE_SHIFT))); \
  } while (0)

#define SBP_INS_UPDATES_NUMBER_OF_REJECTED_NHC_UPDATES_SINCE_LAST_MESSAGE_MASK \
  (0xf)
#define SBP_INS_UPDATES_NUMBER_OF_REJECTED_NHC_UPDATES_SINCE_LAST_MESSAGE_SHIFT \
  (0u)
#define SBP_INS_UPDATES_NUMBER_OF_REJECTED_NHC_UPDATES_SINCE_LAST_MESSAGE_GET(    \
    flags)                                                                        \
  ((u8)(                                                                          \
      ((flags) >>                                                                 \
       SBP_INS_UPDATES_NUMBER_OF_REJECTED_NHC_UPDATES_SINCE_LAST_MESSAGE_SHIFT) & \
      SBP_INS_UPDATES_NUMBER_OF_REJECTED_NHC_UPDATES_SINCE_LAST_MESSAGE_MASK))
#define SBP_INS_UPDATES_NUMBER_OF_REJECTED_NHC_UPDATES_SINCE_LAST_MESSAGE_SET(           \
    flags, val)                                                                          \
  do {                                                                                   \
    (flags) = (u8)(                                                                      \
        (flags) |                                                                        \
        (((val) &                                                                        \
          (SBP_INS_UPDATES_NUMBER_OF_REJECTED_NHC_UPDATES_SINCE_LAST_MESSAGE_MASK))      \
         << (SBP_INS_UPDATES_NUMBER_OF_REJECTED_NHC_UPDATES_SINCE_LAST_MESSAGE_SHIFT))); \
  } while (0)

#define SBP_INS_UPDATES_NUMBER_OF_ATTEMPTED_ZERO_VELOCITY_UPDATES_SINCE_LAST_MESSAGE_MASK \
  (0xf)
#define SBP_INS_UPDATES_NUMBER_OF_ATTEMPTED_ZERO_VELOCITY_UPDATES_SINCE_LAST_MESSAGE_SHIFT \
  (4u)
#define SBP_INS_UPDATES_NUMBER_OF_ATTEMPTED_ZERO_VELOCITY_UPDATES_SINCE_LAST_MESSAGE_GET(    \
    flags)                                                                                   \
  ((u8)(                                                                                     \
      ((flags) >>                                                                            \
       SBP_INS_UPDATES_NUMBER_OF_ATTEMPTED_ZERO_VELOCITY_UPDATES_SINCE_LAST_MESSAGE_SHIFT) & \
      SBP_INS_UPDATES_NUMBER_OF_ATTEMPTED_ZERO_VELOCITY_UPDATES_SINCE_LAST_MESSAGE_MASK))
#define SBP_INS_UPDATES_NUMBER_OF_ATTEMPTED_ZERO_VELOCITY_UPDATES_SINCE_LAST_MESSAGE_SET(           \
    flags, val)                                                                                     \
  do {                                                                                              \
    (flags) = (u8)(                                                                                 \
        (flags) |                                                                                   \
        (((val) &                                                                                   \
          (SBP_INS_UPDATES_NUMBER_OF_ATTEMPTED_ZERO_VELOCITY_UPDATES_SINCE_LAST_MESSAGE_MASK))      \
         << (SBP_INS_UPDATES_NUMBER_OF_ATTEMPTED_ZERO_VELOCITY_UPDATES_SINCE_LAST_MESSAGE_SHIFT))); \
  } while (0)

#define SBP_INS_UPDATES_NUMBER_OF_REJECTED_ZERO_VELOCITY_UPDATES_SINCE_LAST_MESSAGE_MASK \
  (0xf)
#define SBP_INS_UPDATES_NUMBER_OF_REJECTED_ZERO_VELOCITY_UPDATES_SINCE_LAST_MESSAGE_SHIFT \
  (0u)
#define SBP_INS_UPDATES_NUMBER_OF_REJECTED_ZERO_VELOCITY_UPDATES_SINCE_LAST_MESSAGE_GET(    \
    flags)                                                                                  \
  ((u8)(                                                                                    \
      ((flags) >>                                                                           \
       SBP_INS_UPDATES_NUMBER_OF_REJECTED_ZERO_VELOCITY_UPDATES_SINCE_LAST_MESSAGE_SHIFT) & \
      SBP_INS_UPDATES_NUMBER_OF_REJECTED_ZERO_VELOCITY_UPDATES_SINCE_LAST_MESSAGE_MASK))
#define SBP_INS_UPDATES_NUMBER_OF_REJECTED_ZERO_VELOCITY_UPDATES_SINCE_LAST_MESSAGE_SET(           \
    flags, val)                                                                                    \
  do {                                                                                             \
    (flags) = (u8)(                                                                                \
        (flags) |                                                                                  \
        (((val) &                                                                                  \
          (SBP_INS_UPDATES_NUMBER_OF_REJECTED_ZERO_VELOCITY_UPDATES_SINCE_LAST_MESSAGE_MASK))      \
         << (SBP_INS_UPDATES_NUMBER_OF_REJECTED_ZERO_VELOCITY_UPDATES_SINCE_LAST_MESSAGE_SHIFT))); \
  } while (0)

/**
 * Encoded length of sbp_msg_ins_updates_t (V4 API) and
 * msg_ins_updates_t (legacy API)
 */
#define SBP_MSG_INS_UPDATES_ENCODED_LEN 10u

#define SBP_MSG_GNSS_TIME_OFFSET 0xFF07
/**
 * Encoded length of sbp_msg_gnss_time_offset_t (V4 API) and
 * msg_gnss_time_offset_t (legacy API)
 */
#define SBP_MSG_GNSS_TIME_OFFSET_ENCODED_LEN 9u

#define SBP_MSG_PPS_TIME 0xFF08
#define SBP_PPS_TIME_RESERVED_SET_TO_ZERO_MASK (0x3f)
#define SBP_PPS_TIME_RESERVED_SET_TO_ZERO_SHIFT (2u)
#define SBP_PPS_TIME_RESERVED_SET_TO_ZERO_GET(flags)           \
  ((u8)(((flags) >> SBP_PPS_TIME_RESERVED_SET_TO_ZERO_SHIFT) & \
        SBP_PPS_TIME_RESERVED_SET_TO_ZERO_MASK))
#define SBP_PPS_TIME_RESERVED_SET_TO_ZERO_SET(flags, val)                  \
  do {                                                                     \
    (flags) =                                                              \
        (u8)((flags) | (((val) & (SBP_PPS_TIME_RESERVED_SET_TO_ZERO_MASK)) \
                        << (SBP_PPS_TIME_RESERVED_SET_TO_ZERO_SHIFT)));    \
  } while (0)

#define SBP_PPS_TIME_TIME_UNCERTAINTY_MASK (0x3)
#define SBP_PPS_TIME_TIME_UNCERTAINTY_SHIFT (0u)
#define SBP_PPS_TIME_TIME_UNCERTAINTY_GET(flags)           \
  ((u8)(((flags) >> SBP_PPS_TIME_TIME_UNCERTAINTY_SHIFT) & \
        SBP_PPS_TIME_TIME_UNCERTAINTY_MASK))
#define SBP_PPS_TIME_TIME_UNCERTAINTY_SET(flags, val)                        \
  do {                                                                       \
    (flags) = (u8)((flags) | (((val) & (SBP_PPS_TIME_TIME_UNCERTAINTY_MASK)) \
                              << (SBP_PPS_TIME_TIME_UNCERTAINTY_SHIFT)));    \
  } while (0)

#define SBP_PPS_TIME_TIME_UNCERTAINTY_UNKNOWN (0)
#define SBP_PPS_TIME_TIME_UNCERTAINTY_UNKNOWN (0)
#define SBP_PPS_TIME_TIME_UNCERTAINTY__10_MILLISECONDS (1)
#define SBP_PPS_TIME_TIME_UNCERTAINTY_10_MILLISECONDS (1)
#define SBP_PPS_TIME_TIME_UNCERTAINTY__10_MICROSECONDS (2)
#define SBP_PPS_TIME_TIME_UNCERTAINTY_10_MICROSECONDS (2)
#define SBP_PPS_TIME_TIME_UNCERTAINTY__1_MICROSECONDS (3)
#define SBP_PPS_TIME_TIME_UNCERTAINTY_1_MICROSECONDS (3)
/**
 * Encoded length of sbp_msg_pps_time_t (V4 API) and
 * msg_pps_time_t (legacy API)
 */
#define SBP_MSG_PPS_TIME_ENCODED_LEN 9u

#define SBP_MSG_GROUP_META 0xFF0A
#define SBP_GROUP_META_SOLUTION_GROUP_TYPE_MASK (0x3)
#define SBP_GROUP_META_SOLUTION_GROUP_TYPE_SHIFT (0u)
#define SBP_GROUP_META_SOLUTION_GROUP_TYPE_GET(flags)           \
  ((u8)(((flags) >> SBP_GROUP_META_SOLUTION_GROUP_TYPE_SHIFT) & \
        SBP_GROUP_META_SOLUTION_GROUP_TYPE_MASK))
#define SBP_GROUP_META_SOLUTION_GROUP_TYPE_SET(flags, val)                  \
  do {                                                                      \
    (flags) =                                                               \
        (u8)((flags) | (((val) & (SBP_GROUP_META_SOLUTION_GROUP_TYPE_MASK)) \
                        << (SBP_GROUP_META_SOLUTION_GROUP_TYPE_SHIFT)));    \
  } while (0)

#define SBP_GROUP_META_SOLUTION_GROUP_TYPE_NONE (0)
#define SBP_GROUP_META_SOLUTION_GROUP_TYPE_GNSS_ONLY (1)
#define SBP_GROUP_META_SOLUTION_GROUP_TYPE_GNSSINS (2)
/**
 * The maximum number of items that can be stored in
 * sbp_msg_group_meta_t::group_msgs (V4 API) or msg_group_meta_t::group_msgs
 * (legacy API) before the maximum SBP message size is exceeded
 */
#define SBP_MSG_GROUP_META_GROUP_MSGS_MAX 126u

/**
 * Encoded length of sbp_msg_group_meta_t (V4 API) and
 * msg_group_meta_t (legacy API)
 *
 * This type is not fixed size and an instance of this message may be longer
 * than the value indicated by this symbol. Users of the V4 API should call
 * #sbp_msg_group_meta_encoded_len to determine the actual size of an instance
 * of this message. Users of the legacy API are required to track the encoded
 * message length when interacting with the legacy type.
 *
 * See the documentation for libsbp for more details regarding the message
 * structure and its variable length component(s)
 */
#define SBP_MSG_GROUP_META_ENCODED_OVERHEAD 3u

#endif /* LIBSBP_SYSTEM_MACROS_H */
