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
 * Automatically generated from yaml/swiftnav/sbp/system.yaml
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

/** \defgroup system System
 *
 * * Standardized system messages from Swift Navigation devices.
 * \{ */

#ifndef LIBSBP_SYSTEM_MESSAGES_H
#define LIBSBP_SYSTEM_MESSAGES_H

#include "common.h"

SBP_PACK_START
#ifdef __ghs__
#pragma pack(1)
#endif


/** System start-up message
 *
 * The system start-up message is sent once on system
 * start-up. It notifies the host or other attached devices that
 * the system has started and is now ready to respond to commands
 * or configuration requests.
 */
#define SBP_MSG_STARTUP               0xFF00
#define SBP_STARTUP_CAUSE_OF_STARTUP_MASK (0x1ff)
#define SBP_STARTUP_CAUSE_OF_STARTUP_SHIFT (0u)
#define SBP_STARTUP_CAUSE_OF_STARTUP_GET(flags) \
                             (((flags) >> SBP_STARTUP_CAUSE_OF_STARTUP_SHIFT) \
                             & SBP_STARTUP_CAUSE_OF_STARTUP_MASK)
#define SBP_STARTUP_CAUSE_OF_STARTUP_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_STARTUP_CAUSE_OF_STARTUP_MASK)) \
                             << (SBP_STARTUP_CAUSE_OF_STARTUP_SHIFT)));} while(0)
                             

#define SBP_STARTUP_CAUSE_OF_STARTUP_POWER_ON (0)
#define SBP_STARTUP_CAUSE_OF_STARTUP_SOFTWARE_RESET (1)
#define SBP_STARTUP_CAUSE_OF_STARTUP_WATCHDOG_RESET (2)
#define SBP_STARTUP__MASK (0x1ff)
#define SBP_STARTUP__SHIFT (0u)
#define SBP_STARTUP__GET(flags) \
                             (((flags) >> SBP_STARTUP__SHIFT) \
                             & SBP_STARTUP__MASK)
#define SBP_STARTUP__SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_STARTUP__MASK)) \
                             << (SBP_STARTUP__SHIFT)));} while(0)
                             

#define SBP_STARTUP__COLD_START (0)
#define SBP_STARTUP__WARM_START (1)
#define SBP_STARTUP__HOT_START (2)

typedef struct SBP_ATTR_PACKED {
  u8 cause;           /**< Cause of startup */
  u8 startup_type;    /**< Startup type */
  u16 reserved;        /**< Reserved */
} msg_startup_t;
 

/** Status of received corrections
 *
 * This message provides information about the receipt of Differential
 * corrections.  It is expected to be sent with each receipt of a complete
 * corrections packet.
 */
#define SBP_MSG_DGNSS_STATUS          0xFF02
#define SBP_DGNSS_STATUS_DIFFERENTIAL_TYPE_MASK (0xf)
#define SBP_DGNSS_STATUS_DIFFERENTIAL_TYPE_SHIFT (0u)
#define SBP_DGNSS_STATUS_DIFFERENTIAL_TYPE_GET(flags) \
                             (((flags) >> SBP_DGNSS_STATUS_DIFFERENTIAL_TYPE_SHIFT) \
                             & SBP_DGNSS_STATUS_DIFFERENTIAL_TYPE_MASK)
#define SBP_DGNSS_STATUS_DIFFERENTIAL_TYPE_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_DGNSS_STATUS_DIFFERENTIAL_TYPE_MASK)) \
                             << (SBP_DGNSS_STATUS_DIFFERENTIAL_TYPE_SHIFT)));} while(0)
                             

#define SBP_DGNSS_STATUS_DIFFERENTIAL_TYPE_INVALID (0)
#define SBP_DGNSS_STATUS_DIFFERENTIAL_TYPE_CODE_DIFFERENCE (1)
#define SBP_DGNSS_STATUS_DIFFERENTIAL_TYPE_RTK (2)

typedef struct SBP_ATTR_PACKED {
  u8 flags;          /**< Status flags */
  u16 latency;        /**< Latency of observation receipt [deci-seconds] */
  u8 num_signals;    /**< Number of signals from base station */
#ifdef SBP_ENABLE_VARIABLE_SIZED_ARRAYS
  char source[0];      /**< Corrections source string */
#endif
} msg_dgnss_status_t;
#define MSG_DGNSS_STATUS_T_GET_SOURCE_PTR(msg) (( char *)(msg+1))
#define MSG_DGNSS_STATUS_T_GET_SOURCE_CPTR(msg) ((const char *)(msg+1))
 

/** System heartbeat message
 *
 * The heartbeat message is sent periodically to inform the host
 * or other attached devices that the system is running. It is
 * used to monitor system malfunctions. It also contains status
 * flags that indicate to the host the status of the system and
 * whether it is operating correctly. Currently, the expected
 * heartbeat interval is 1 sec.
 * 
 * The system error flag is used to indicate that an error has
 * occurred in the system. To determine the source of the error,
 * the remaining error flags should be inspected.
 */
#define SBP_MSG_HEARTBEAT             0xFFFF
#define SBP_HEARTBEAT_EXTERNAL_ANTENNA_PRESENT_MASK (0x1)
#define SBP_HEARTBEAT_EXTERNAL_ANTENNA_PRESENT_SHIFT (31u)
#define SBP_HEARTBEAT_EXTERNAL_ANTENNA_PRESENT_GET(flags) \
                             (((flags) >> SBP_HEARTBEAT_EXTERNAL_ANTENNA_PRESENT_SHIFT) \
                             & SBP_HEARTBEAT_EXTERNAL_ANTENNA_PRESENT_MASK)
#define SBP_HEARTBEAT_EXTERNAL_ANTENNA_PRESENT_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_HEARTBEAT_EXTERNAL_ANTENNA_PRESENT_MASK)) \
                             << (SBP_HEARTBEAT_EXTERNAL_ANTENNA_PRESENT_SHIFT)));} while(0)
                             

#define SBP_HEARTBEAT_EXTERNAL_ANTENNA_PRESENT_NO_EXTERNAL_ANTENNA_DETECTED (0)
#define SBP_HEARTBEAT_EXTERNAL_ANTENNA_PRESENT_EXTERNAL_ANTENNA_IS_PRESENT (1)
#define SBP_HEARTBEAT_EXTERNAL_ANTENNA_SHORT_MASK (0x1)
#define SBP_HEARTBEAT_EXTERNAL_ANTENNA_SHORT_SHIFT (30u)
#define SBP_HEARTBEAT_EXTERNAL_ANTENNA_SHORT_GET(flags) \
                             (((flags) >> SBP_HEARTBEAT_EXTERNAL_ANTENNA_SHORT_SHIFT) \
                             & SBP_HEARTBEAT_EXTERNAL_ANTENNA_SHORT_MASK)
#define SBP_HEARTBEAT_EXTERNAL_ANTENNA_SHORT_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_HEARTBEAT_EXTERNAL_ANTENNA_SHORT_MASK)) \
                             << (SBP_HEARTBEAT_EXTERNAL_ANTENNA_SHORT_SHIFT)));} while(0)
                             

#define SBP_HEARTBEAT_EXTERNAL_ANTENNA_SHORT_NO_SHORT_DETECTED (0)
#define SBP_HEARTBEAT_EXTERNAL_ANTENNA_SHORT_SHORT_DETECTED (1)
#define SBP_HEARTBEAT_SBP_MAJOR_PROTOCOL_VERSION_NUMBER_MASK (0xff)
#define SBP_HEARTBEAT_SBP_MAJOR_PROTOCOL_VERSION_NUMBER_SHIFT (16u)
#define SBP_HEARTBEAT_SBP_MAJOR_PROTOCOL_VERSION_NUMBER_GET(flags) \
                             (((flags) >> SBP_HEARTBEAT_SBP_MAJOR_PROTOCOL_VERSION_NUMBER_SHIFT) \
                             & SBP_HEARTBEAT_SBP_MAJOR_PROTOCOL_VERSION_NUMBER_MASK)
#define SBP_HEARTBEAT_SBP_MAJOR_PROTOCOL_VERSION_NUMBER_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_HEARTBEAT_SBP_MAJOR_PROTOCOL_VERSION_NUMBER_MASK)) \
                             << (SBP_HEARTBEAT_SBP_MAJOR_PROTOCOL_VERSION_NUMBER_SHIFT)));} while(0)
                             

#define SBP_HEARTBEAT_SBP_MINOR_PROTOCOL_VERSION_NUMBER_MASK (0xff)
#define SBP_HEARTBEAT_SBP_MINOR_PROTOCOL_VERSION_NUMBER_SHIFT (8u)
#define SBP_HEARTBEAT_SBP_MINOR_PROTOCOL_VERSION_NUMBER_GET(flags) \
                             (((flags) >> SBP_HEARTBEAT_SBP_MINOR_PROTOCOL_VERSION_NUMBER_SHIFT) \
                             & SBP_HEARTBEAT_SBP_MINOR_PROTOCOL_VERSION_NUMBER_MASK)
#define SBP_HEARTBEAT_SBP_MINOR_PROTOCOL_VERSION_NUMBER_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_HEARTBEAT_SBP_MINOR_PROTOCOL_VERSION_NUMBER_MASK)) \
                             << (SBP_HEARTBEAT_SBP_MINOR_PROTOCOL_VERSION_NUMBER_SHIFT)));} while(0)
                             

#define SBP_HEARTBEAT_SWIFTNAP_ERROR_MASK (0x1)
#define SBP_HEARTBEAT_SWIFTNAP_ERROR_SHIFT (2u)
#define SBP_HEARTBEAT_SWIFTNAP_ERROR_GET(flags) \
                             (((flags) >> SBP_HEARTBEAT_SWIFTNAP_ERROR_SHIFT) \
                             & SBP_HEARTBEAT_SWIFTNAP_ERROR_MASK)
#define SBP_HEARTBEAT_SWIFTNAP_ERROR_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_HEARTBEAT_SWIFTNAP_ERROR_MASK)) \
                             << (SBP_HEARTBEAT_SWIFTNAP_ERROR_SHIFT)));} while(0)
                             

#define SBP_HEARTBEAT_SWIFTNAP_ERROR_SYSTEM_HEALTHY (0)
#define SBP_HEARTBEAT_SWIFTNAP_ERROR_AN_ERROR_HAS_OCCURRED_IN_THE_SWIFTNAP (1)
#define SBP_HEARTBEAT_IO_ERROR_MASK (0x1)
#define SBP_HEARTBEAT_IO_ERROR_SHIFT (1u)
#define SBP_HEARTBEAT_IO_ERROR_GET(flags) \
                             (((flags) >> SBP_HEARTBEAT_IO_ERROR_SHIFT) \
                             & SBP_HEARTBEAT_IO_ERROR_MASK)
#define SBP_HEARTBEAT_IO_ERROR_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_HEARTBEAT_IO_ERROR_MASK)) \
                             << (SBP_HEARTBEAT_IO_ERROR_SHIFT)));} while(0)
                             

#define SBP_HEARTBEAT_IO_ERROR_SYSTEM_HEALTHY (0)
#define SBP_HEARTBEAT_IO_ERROR_AN_IO_ERROR_HAS_OCCURRED (1)
#define SBP_HEARTBEAT_SYSTEM_ERROR_FLAG_MASK (0x1)
#define SBP_HEARTBEAT_SYSTEM_ERROR_FLAG_SHIFT (0u)
#define SBP_HEARTBEAT_SYSTEM_ERROR_FLAG_GET(flags) \
                             (((flags) >> SBP_HEARTBEAT_SYSTEM_ERROR_FLAG_SHIFT) \
                             & SBP_HEARTBEAT_SYSTEM_ERROR_FLAG_MASK)
#define SBP_HEARTBEAT_SYSTEM_ERROR_FLAG_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_HEARTBEAT_SYSTEM_ERROR_FLAG_MASK)) \
                             << (SBP_HEARTBEAT_SYSTEM_ERROR_FLAG_SHIFT)));} while(0)
                             

#define SBP_HEARTBEAT_SYSTEM_ERROR_FLAG_SYSTEM_HEALTHY (0)
#define SBP_HEARTBEAT_SYSTEM_ERROR_FLAG_AN_ERROR_HAS_OCCURRED (1)

typedef struct SBP_ATTR_PACKED {
  u32 flags;    /**< Status flags */
} msg_heartbeat_t;
 

/** Sub-system Status report
 *
 * Report the general and specific state of a sub-system.  If the generic
 * state is reported as initializing, the specific state should be ignored.
 */
#define SBP_SUBSYSTEMREPORT_SUBSYSTEM_MASK (0xffff)
#define SBP_SUBSYSTEMREPORT_SUBSYSTEM_SHIFT (0u)
#define SBP_SUBSYSTEMREPORT_SUBSYSTEM_GET(flags) \
                             (((flags) >> SBP_SUBSYSTEMREPORT_SUBSYSTEM_SHIFT) \
                             & SBP_SUBSYSTEMREPORT_SUBSYSTEM_MASK)
#define SBP_SUBSYSTEMREPORT_SUBSYSTEM_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_SUBSYSTEMREPORT_SUBSYSTEM_MASK)) \
                             << (SBP_SUBSYSTEMREPORT_SUBSYSTEM_SHIFT)));} while(0)
                             

#define SBP_SUBSYSTEMREPORT_SUBSYSTEM_PRIMARY_GNSS_ANTENNA (0)
#define SBP_SUBSYSTEMREPORT_SUBSYSTEM_MEASUREMENT_ENGINE (1)
#define SBP_SUBSYSTEMREPORT_SUBSYSTEM_CORRECTIONS_CLIENT (2)
#define SBP_SUBSYSTEMREPORT_SUBSYSTEM_DIFFERENTIAL_GNSS_ENGINE (3)
#define SBP_SUBSYSTEMREPORT_SUBSYSTEM_CAN (4)
#define SBP_SUBSYSTEMREPORT_SUBSYSTEM_WHEEL_ODOMETRY (5)
#define SBP_SUBSYSTEMREPORT_SUBSYSTEM_SENSOR_FUSION_ENGINE (6)
#define SBP_SUBSYSTEMREPORT_GENERIC_MASK (0xff)
#define SBP_SUBSYSTEMREPORT_GENERIC_SHIFT (0u)
#define SBP_SUBSYSTEMREPORT_GENERIC_GET(flags) \
                             (((flags) >> SBP_SUBSYSTEMREPORT_GENERIC_SHIFT) \
                             & SBP_SUBSYSTEMREPORT_GENERIC_MASK)
#define SBP_SUBSYSTEMREPORT_GENERIC_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_SUBSYSTEMREPORT_GENERIC_MASK)) \
                             << (SBP_SUBSYSTEMREPORT_GENERIC_SHIFT)));} while(0)
                             

#define SBP_SUBSYSTEMREPORT_GENERIC_OKNOMINAL (0)
#define SBP_SUBSYSTEMREPORT_GENERIC_INITIALIZING (1)
#define SBP_SUBSYSTEMREPORT_GENERIC_UNKNOWN (2)
#define SBP_SUBSYSTEMREPORT_GENERIC_DEGRADED (3)
#define SBP_SUBSYSTEMREPORT_GENERIC_UNUSABLE (4)

typedef struct SBP_ATTR_PACKED {
  u16 component;    /**< Identity of reporting subsystem */
  u8 generic;      /**< Generic form status report */
  u8 specific;     /**< Subsystem specific status code */
} sub_system_report_t;
 

/** Status report message
 *
 * The status report is sent periodically to inform the host
 * or other attached devices that the system is running. It is
 * used to monitor system malfunctions. It contains status
 * reports that indicate to the host the status of each sub-system and
 * whether it is operating correctly.
 * 
 * Interpretation of the subsystem specific status code is product
 * dependent, but if the generic status code is initializing, it should
 * be ignored.  Refer to product documentation for details.
 */
#define SBP_MSG_STATUS_REPORT         0xFFFE
#define SBP_STATUS_REPORT_SYSTEM_MASK (0xffff)
#define SBP_STATUS_REPORT_SYSTEM_SHIFT (0u)
#define SBP_STATUS_REPORT_SYSTEM_GET(flags) \
                             (((flags) >> SBP_STATUS_REPORT_SYSTEM_SHIFT) \
                             & SBP_STATUS_REPORT_SYSTEM_MASK)
#define SBP_STATUS_REPORT_SYSTEM_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_STATUS_REPORT_SYSTEM_MASK)) \
                             << (SBP_STATUS_REPORT_SYSTEM_SHIFT)));} while(0)
                             

#define SBP_STATUS_REPORT_SYSTEM_STARLING (0)
#define SBP_STATUS_REPORT_SYSTEM_PRECISION_GNSS_MODULE (1)
#define SBP_STATUS_REPORT_SBP_MAJOR_PROTOCOL_VERSION_NUMBER_MASK (0x1ff)
#define SBP_STATUS_REPORT_SBP_MAJOR_PROTOCOL_VERSION_NUMBER_SHIFT (8u)
#define SBP_STATUS_REPORT_SBP_MAJOR_PROTOCOL_VERSION_NUMBER_GET(flags) \
                             (((flags) >> SBP_STATUS_REPORT_SBP_MAJOR_PROTOCOL_VERSION_NUMBER_SHIFT) \
                             & SBP_STATUS_REPORT_SBP_MAJOR_PROTOCOL_VERSION_NUMBER_MASK)
#define SBP_STATUS_REPORT_SBP_MAJOR_PROTOCOL_VERSION_NUMBER_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_STATUS_REPORT_SBP_MAJOR_PROTOCOL_VERSION_NUMBER_MASK)) \
                             << (SBP_STATUS_REPORT_SBP_MAJOR_PROTOCOL_VERSION_NUMBER_SHIFT)));} while(0)
                             

#define SBP_STATUS_REPORT_SBP_MINOR_PROTOCOL_VERSION_NUMBER_MASK (0xff)
#define SBP_STATUS_REPORT_SBP_MINOR_PROTOCOL_VERSION_NUMBER_SHIFT (0u)
#define SBP_STATUS_REPORT_SBP_MINOR_PROTOCOL_VERSION_NUMBER_GET(flags) \
                             (((flags) >> SBP_STATUS_REPORT_SBP_MINOR_PROTOCOL_VERSION_NUMBER_SHIFT) \
                             & SBP_STATUS_REPORT_SBP_MINOR_PROTOCOL_VERSION_NUMBER_MASK)
#define SBP_STATUS_REPORT_SBP_MINOR_PROTOCOL_VERSION_NUMBER_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_STATUS_REPORT_SBP_MINOR_PROTOCOL_VERSION_NUMBER_MASK)) \
                             << (SBP_STATUS_REPORT_SBP_MINOR_PROTOCOL_VERSION_NUMBER_SHIFT)));} while(0)
                             


typedef struct SBP_ATTR_PACKED {
  u16 reporting_system;    /**< Identity of reporting system */
  u16 sbp_version;         /**< SBP protocol version */
  u32 sequence;            /**< Increments on each status report sent */
  u32 uptime;              /**< Number of seconds since system start-up */
#ifdef SBP_ENABLE_VARIABLE_SIZED_ARRAYS
  sub_system_report_t status[0];           /**< Reported status of individual subsystems */
#endif
} msg_status_report_t;
#define MSG_STATUS_REPORT_T_GET_STATUS_PTR(msg) (( sub_system_report_t *)(msg+1))
#define MSG_STATUS_REPORT_T_GET_STATUS_CPTR(msg) ((const sub_system_report_t *)(msg+1))
 

/** Inertial Navigation System status message
 *
 * The INS status message describes the state of the operation
 * and initialization of the inertial navigation system. 
 */
#define SBP_MSG_INS_STATUS            0xFF03
#define SBP_INS_STATUS_INS_TYPE_MASK (0x7)
#define SBP_INS_STATUS_INS_TYPE_SHIFT (29u)
#define SBP_INS_STATUS_INS_TYPE_GET(flags) \
                             (((flags) >> SBP_INS_STATUS_INS_TYPE_SHIFT) \
                             & SBP_INS_STATUS_INS_TYPE_MASK)
#define SBP_INS_STATUS_INS_TYPE_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_INS_STATUS_INS_TYPE_MASK)) \
                             << (SBP_INS_STATUS_INS_TYPE_SHIFT)));} while(0)
                             

#define SBP_INS_STATUS_INS_TYPE_SMOOTHPOSE_LOOSELY_COUPLED (0)
#define SBP_INS_STATUS_INS_TYPE_STARLING (1)
#define SBP_INS_STATUS_MOTION_STATE_MASK (0x7)
#define SBP_INS_STATUS_MOTION_STATE_SHIFT (11u)
#define SBP_INS_STATUS_MOTION_STATE_GET(flags) \
                             (((flags) >> SBP_INS_STATUS_MOTION_STATE_SHIFT) \
                             & SBP_INS_STATUS_MOTION_STATE_MASK)
#define SBP_INS_STATUS_MOTION_STATE_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_INS_STATUS_MOTION_STATE_MASK)) \
                             << (SBP_INS_STATUS_MOTION_STATE_SHIFT)));} while(0)
                             

#define SBP_INS_STATUS_MOTION_STATE_UNKNOWN_OR_INIT (0)
#define SBP_INS_STATUS_MOTION_STATE_ARBITRARY_MOTION (1)
#define SBP_INS_STATUS_MOTION_STATE_STRAIGHT_MOTION (2)
#define SBP_INS_STATUS_MOTION_STATE_STATIONARY (3)
#define SBP_INS_STATUS_ODOMETRY_SYNCH_MASK (0x1)
#define SBP_INS_STATUS_ODOMETRY_SYNCH_SHIFT (10u)
#define SBP_INS_STATUS_ODOMETRY_SYNCH_GET(flags) \
                             (((flags) >> SBP_INS_STATUS_ODOMETRY_SYNCH_SHIFT) \
                             & SBP_INS_STATUS_ODOMETRY_SYNCH_MASK)
#define SBP_INS_STATUS_ODOMETRY_SYNCH_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_INS_STATUS_ODOMETRY_SYNCH_MASK)) \
                             << (SBP_INS_STATUS_ODOMETRY_SYNCH_SHIFT)));} while(0)
                             

#define SBP_INS_STATUS_ODOMETRY_SYNCH_ODOMETRY_TIMESTAMP_NOMINAL (0)
#define SBP_INS_STATUS_ODOMETRY_SYNCH_ODOMETRY_TIMESTAMP_OUT_OF_BOUNDS (1)
#define SBP_INS_STATUS_ODOMETRY_STATUS_MASK (0x3)
#define SBP_INS_STATUS_ODOMETRY_STATUS_SHIFT (8u)
#define SBP_INS_STATUS_ODOMETRY_STATUS_GET(flags) \
                             (((flags) >> SBP_INS_STATUS_ODOMETRY_STATUS_SHIFT) \
                             & SBP_INS_STATUS_ODOMETRY_STATUS_MASK)
#define SBP_INS_STATUS_ODOMETRY_STATUS_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_INS_STATUS_ODOMETRY_STATUS_MASK)) \
                             << (SBP_INS_STATUS_ODOMETRY_STATUS_SHIFT)));} while(0)
                             

#define SBP_INS_STATUS_ODOMETRY_STATUS_NO_ODOMETRY (0)
#define SBP_INS_STATUS_ODOMETRY_STATUS_ODOMETRY_RECEIVED_WITHIN_LAST_SECOND (1)
#define SBP_INS_STATUS_ODOMETRY_STATUS_ODOMETRY_NOT_RECEIVED_WITHIN_LAST_SECOND (2)
#define SBP_INS_STATUS_INS_ERROR_MASK (0xf)
#define SBP_INS_STATUS_INS_ERROR_SHIFT (4u)
#define SBP_INS_STATUS_INS_ERROR_GET(flags) \
                             (((flags) >> SBP_INS_STATUS_INS_ERROR_SHIFT) \
                             & SBP_INS_STATUS_INS_ERROR_MASK)
#define SBP_INS_STATUS_INS_ERROR_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_INS_STATUS_INS_ERROR_MASK)) \
                             << (SBP_INS_STATUS_INS_ERROR_SHIFT)));} while(0)
                             

#define SBP_INS_STATUS_INS_ERROR_IMU_DATA_ERROR (1)
#define SBP_INS_STATUS_INS_ERROR_INS_LICENSE_ERROR (2)
#define SBP_INS_STATUS_INS_ERROR_IMU_CALIBRATION_DATA_ERROR (3)
#define SBP_INS_STATUS_GNSS_FIX_MASK (0x1)
#define SBP_INS_STATUS_GNSS_FIX_SHIFT (3u)
#define SBP_INS_STATUS_GNSS_FIX_GET(flags) \
                             (((flags) >> SBP_INS_STATUS_GNSS_FIX_SHIFT) \
                             & SBP_INS_STATUS_GNSS_FIX_MASK)
#define SBP_INS_STATUS_GNSS_FIX_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_INS_STATUS_GNSS_FIX_MASK)) \
                             << (SBP_INS_STATUS_GNSS_FIX_SHIFT)));} while(0)
                             

#define SBP_INS_STATUS_GNSS_FIX_NO_GNSS_FIX_AVAILABLE (0)
#define SBP_INS_STATUS_GNSS_FIX_GNSS_FIX (1)
#define SBP_INS_STATUS_MODE_MASK (0x7)
#define SBP_INS_STATUS_MODE_SHIFT (0u)
#define SBP_INS_STATUS_MODE_GET(flags) \
                             (((flags) >> SBP_INS_STATUS_MODE_SHIFT) \
                             & SBP_INS_STATUS_MODE_MASK)
#define SBP_INS_STATUS_MODE_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_INS_STATUS_MODE_MASK)) \
                             << (SBP_INS_STATUS_MODE_SHIFT)));} while(0)
                             

#define SBP_INS_STATUS_MODE_AWAITING_INITIALIZATION (0)
#define SBP_INS_STATUS_MODE_DYNAMICALLY_ALIGNING (1)
#define SBP_INS_STATUS_MODE_READY (2)
#define SBP_INS_STATUS_MODE_GNSS_OUTAGE_EXCEEDS_MAX_DURATION (3)
#define SBP_INS_STATUS_MODE_FASTSTART_SEEDING (4)
#define SBP_INS_STATUS_MODE_FASTSTART_VALIDATING (5)
#define SBP_INS_STATUS_MODE_VALIDATING_UNSAFE_FAST_START_SEED (6)

typedef struct SBP_ATTR_PACKED {
  u32 flags;    /**< Status flags */
} msg_ins_status_t;
 

/** Experimental telemetry message
 *
 * The CSAC telemetry message has an implementation defined telemetry string
 * from a device. It is not produced or available on general Swift Products.
 * It is intended to be a low rate message for status purposes.
 */
#define SBP_MSG_CSAC_TELEMETRY        0xFF04

typedef struct SBP_ATTR_PACKED {
  u8 id;           /**< Index representing the type of telemetry in use.  It is implemention defined. */
#ifdef SBP_ENABLE_VARIABLE_SIZED_ARRAYS
  char telemetry[0]; /**< Comma separated list of values as defined by the index */
#endif
} msg_csac_telemetry_t;
#define MSG_CSAC_TELEMETRY_T_GET_TELEMETRY_PTR(msg) (( char *)(msg+1))
#define MSG_CSAC_TELEMETRY_T_GET_TELEMETRY_CPTR(msg) ((const char *)(msg+1))
 

/** Experimental telemetry message labels
 *
 * The CSAC telemetry message provides labels for each member of the string
 * produced by MSG_CSAC_TELEMETRY. It should be provided by a device at a lower
 * rate than the MSG_CSAC_TELEMETRY.
 */
#define SBP_MSG_CSAC_TELEMETRY_LABELS 0xFF05

typedef struct SBP_ATTR_PACKED {
  u8 id;                  /**< Index representing the type of telemetry in use.  It is implemention defined. */
#ifdef SBP_ENABLE_VARIABLE_SIZED_ARRAYS
  char telemetry_labels[0]; /**< Comma separated list of telemetry field values */
#endif
} msg_csac_telemetry_labels_t;
#define MSG_CSAC_TELEMETRY_LABELS_T_GET_TELEMETRY_LABELS_PTR(msg) (( char *)(msg+1))
#define MSG_CSAC_TELEMETRY_LABELS_T_GET_TELEMETRY_LABELS_CPTR(msg) ((const char *)(msg+1))
 

/** Inertial Navigation System update status message
 *
 * The INS update status message contains informations about executed and rejected INS updates.
 * This message is expected to be extended in the future as new types of measurements are being added.
 */
#define SBP_MSG_INS_UPDATES           0xFF06
#define SBP_INS_UPDATES_NUMBER_OF_ATTEMPTED_GNSS_POSITION_UPDATES_SINCE_LAST_MESSAGE_MASK (0xf)
#define SBP_INS_UPDATES_NUMBER_OF_ATTEMPTED_GNSS_POSITION_UPDATES_SINCE_LAST_MESSAGE_SHIFT (4u)
#define SBP_INS_UPDATES_NUMBER_OF_ATTEMPTED_GNSS_POSITION_UPDATES_SINCE_LAST_MESSAGE_GET(flags) \
                             (((flags) >> SBP_INS_UPDATES_NUMBER_OF_ATTEMPTED_GNSS_POSITION_UPDATES_SINCE_LAST_MESSAGE_SHIFT) \
                             & SBP_INS_UPDATES_NUMBER_OF_ATTEMPTED_GNSS_POSITION_UPDATES_SINCE_LAST_MESSAGE_MASK)
#define SBP_INS_UPDATES_NUMBER_OF_ATTEMPTED_GNSS_POSITION_UPDATES_SINCE_LAST_MESSAGE_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_INS_UPDATES_NUMBER_OF_ATTEMPTED_GNSS_POSITION_UPDATES_SINCE_LAST_MESSAGE_MASK)) \
                             << (SBP_INS_UPDATES_NUMBER_OF_ATTEMPTED_GNSS_POSITION_UPDATES_SINCE_LAST_MESSAGE_SHIFT)));} while(0)
                             

#define SBP_INS_UPDATES_NUMBER_OF_REJECTED_GNSS_POSITION_UPDATES_SINCE_LAST_MESSAGE_MASK (0xf)
#define SBP_INS_UPDATES_NUMBER_OF_REJECTED_GNSS_POSITION_UPDATES_SINCE_LAST_MESSAGE_SHIFT (0u)
#define SBP_INS_UPDATES_NUMBER_OF_REJECTED_GNSS_POSITION_UPDATES_SINCE_LAST_MESSAGE_GET(flags) \
                             (((flags) >> SBP_INS_UPDATES_NUMBER_OF_REJECTED_GNSS_POSITION_UPDATES_SINCE_LAST_MESSAGE_SHIFT) \
                             & SBP_INS_UPDATES_NUMBER_OF_REJECTED_GNSS_POSITION_UPDATES_SINCE_LAST_MESSAGE_MASK)
#define SBP_INS_UPDATES_NUMBER_OF_REJECTED_GNSS_POSITION_UPDATES_SINCE_LAST_MESSAGE_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_INS_UPDATES_NUMBER_OF_REJECTED_GNSS_POSITION_UPDATES_SINCE_LAST_MESSAGE_MASK)) \
                             << (SBP_INS_UPDATES_NUMBER_OF_REJECTED_GNSS_POSITION_UPDATES_SINCE_LAST_MESSAGE_SHIFT)));} while(0)
                             

#define SBP_INS_UPDATES_NUMBER_OF_ATTEMPTED_GNSS_VELOCITY_UPDATES_SINCE_LAST_MESSAGE_MASK (0xf)
#define SBP_INS_UPDATES_NUMBER_OF_ATTEMPTED_GNSS_VELOCITY_UPDATES_SINCE_LAST_MESSAGE_SHIFT (4u)
#define SBP_INS_UPDATES_NUMBER_OF_ATTEMPTED_GNSS_VELOCITY_UPDATES_SINCE_LAST_MESSAGE_GET(flags) \
                             (((flags) >> SBP_INS_UPDATES_NUMBER_OF_ATTEMPTED_GNSS_VELOCITY_UPDATES_SINCE_LAST_MESSAGE_SHIFT) \
                             & SBP_INS_UPDATES_NUMBER_OF_ATTEMPTED_GNSS_VELOCITY_UPDATES_SINCE_LAST_MESSAGE_MASK)
#define SBP_INS_UPDATES_NUMBER_OF_ATTEMPTED_GNSS_VELOCITY_UPDATES_SINCE_LAST_MESSAGE_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_INS_UPDATES_NUMBER_OF_ATTEMPTED_GNSS_VELOCITY_UPDATES_SINCE_LAST_MESSAGE_MASK)) \
                             << (SBP_INS_UPDATES_NUMBER_OF_ATTEMPTED_GNSS_VELOCITY_UPDATES_SINCE_LAST_MESSAGE_SHIFT)));} while(0)
                             

#define SBP_INS_UPDATES_NUMBER_OF_REJECTED_GNSS_VELOCITY_UPDATES_SINCE_LAST_MESSAGE_MASK (0xf)
#define SBP_INS_UPDATES_NUMBER_OF_REJECTED_GNSS_VELOCITY_UPDATES_SINCE_LAST_MESSAGE_SHIFT (0u)
#define SBP_INS_UPDATES_NUMBER_OF_REJECTED_GNSS_VELOCITY_UPDATES_SINCE_LAST_MESSAGE_GET(flags) \
                             (((flags) >> SBP_INS_UPDATES_NUMBER_OF_REJECTED_GNSS_VELOCITY_UPDATES_SINCE_LAST_MESSAGE_SHIFT) \
                             & SBP_INS_UPDATES_NUMBER_OF_REJECTED_GNSS_VELOCITY_UPDATES_SINCE_LAST_MESSAGE_MASK)
#define SBP_INS_UPDATES_NUMBER_OF_REJECTED_GNSS_VELOCITY_UPDATES_SINCE_LAST_MESSAGE_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_INS_UPDATES_NUMBER_OF_REJECTED_GNSS_VELOCITY_UPDATES_SINCE_LAST_MESSAGE_MASK)) \
                             << (SBP_INS_UPDATES_NUMBER_OF_REJECTED_GNSS_VELOCITY_UPDATES_SINCE_LAST_MESSAGE_SHIFT)));} while(0)
                             

#define SBP_INS_UPDATES_NUMBER_OF_ATTEMPTED_WHEELTICK_UPDATES_SINCE_LAST_MESSAGE_MASK (0xf)
#define SBP_INS_UPDATES_NUMBER_OF_ATTEMPTED_WHEELTICK_UPDATES_SINCE_LAST_MESSAGE_SHIFT (4u)
#define SBP_INS_UPDATES_NUMBER_OF_ATTEMPTED_WHEELTICK_UPDATES_SINCE_LAST_MESSAGE_GET(flags) \
                             (((flags) >> SBP_INS_UPDATES_NUMBER_OF_ATTEMPTED_WHEELTICK_UPDATES_SINCE_LAST_MESSAGE_SHIFT) \
                             & SBP_INS_UPDATES_NUMBER_OF_ATTEMPTED_WHEELTICK_UPDATES_SINCE_LAST_MESSAGE_MASK)
#define SBP_INS_UPDATES_NUMBER_OF_ATTEMPTED_WHEELTICK_UPDATES_SINCE_LAST_MESSAGE_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_INS_UPDATES_NUMBER_OF_ATTEMPTED_WHEELTICK_UPDATES_SINCE_LAST_MESSAGE_MASK)) \
                             << (SBP_INS_UPDATES_NUMBER_OF_ATTEMPTED_WHEELTICK_UPDATES_SINCE_LAST_MESSAGE_SHIFT)));} while(0)
                             

#define SBP_INS_UPDATES_NUMBER_OF_REJECTED_WHEELTICK_UPDATES_SINCE_LAST_MESSAGE_MASK (0xf)
#define SBP_INS_UPDATES_NUMBER_OF_REJECTED_WHEELTICK_UPDATES_SINCE_LAST_MESSAGE_SHIFT (0u)
#define SBP_INS_UPDATES_NUMBER_OF_REJECTED_WHEELTICK_UPDATES_SINCE_LAST_MESSAGE_GET(flags) \
                             (((flags) >> SBP_INS_UPDATES_NUMBER_OF_REJECTED_WHEELTICK_UPDATES_SINCE_LAST_MESSAGE_SHIFT) \
                             & SBP_INS_UPDATES_NUMBER_OF_REJECTED_WHEELTICK_UPDATES_SINCE_LAST_MESSAGE_MASK)
#define SBP_INS_UPDATES_NUMBER_OF_REJECTED_WHEELTICK_UPDATES_SINCE_LAST_MESSAGE_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_INS_UPDATES_NUMBER_OF_REJECTED_WHEELTICK_UPDATES_SINCE_LAST_MESSAGE_MASK)) \
                             << (SBP_INS_UPDATES_NUMBER_OF_REJECTED_WHEELTICK_UPDATES_SINCE_LAST_MESSAGE_SHIFT)));} while(0)
                             

#define SBP_INS_UPDATES_NUMBER_OF_ATTEMPTED_SPEED_UPDATES_SINCE_LAST_MESSAGE_MASK (0xf)
#define SBP_INS_UPDATES_NUMBER_OF_ATTEMPTED_SPEED_UPDATES_SINCE_LAST_MESSAGE_SHIFT (4u)
#define SBP_INS_UPDATES_NUMBER_OF_ATTEMPTED_SPEED_UPDATES_SINCE_LAST_MESSAGE_GET(flags) \
                             (((flags) >> SBP_INS_UPDATES_NUMBER_OF_ATTEMPTED_SPEED_UPDATES_SINCE_LAST_MESSAGE_SHIFT) \
                             & SBP_INS_UPDATES_NUMBER_OF_ATTEMPTED_SPEED_UPDATES_SINCE_LAST_MESSAGE_MASK)
#define SBP_INS_UPDATES_NUMBER_OF_ATTEMPTED_SPEED_UPDATES_SINCE_LAST_MESSAGE_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_INS_UPDATES_NUMBER_OF_ATTEMPTED_SPEED_UPDATES_SINCE_LAST_MESSAGE_MASK)) \
                             << (SBP_INS_UPDATES_NUMBER_OF_ATTEMPTED_SPEED_UPDATES_SINCE_LAST_MESSAGE_SHIFT)));} while(0)
                             

#define SBP_INS_UPDATES_NUMBER_OF_REJECTED_SPEED_UPDATES_SINCE_LAST_MESSAGE_MASK (0xf)
#define SBP_INS_UPDATES_NUMBER_OF_REJECTED_SPEED_UPDATES_SINCE_LAST_MESSAGE_SHIFT (0u)
#define SBP_INS_UPDATES_NUMBER_OF_REJECTED_SPEED_UPDATES_SINCE_LAST_MESSAGE_GET(flags) \
                             (((flags) >> SBP_INS_UPDATES_NUMBER_OF_REJECTED_SPEED_UPDATES_SINCE_LAST_MESSAGE_SHIFT) \
                             & SBP_INS_UPDATES_NUMBER_OF_REJECTED_SPEED_UPDATES_SINCE_LAST_MESSAGE_MASK)
#define SBP_INS_UPDATES_NUMBER_OF_REJECTED_SPEED_UPDATES_SINCE_LAST_MESSAGE_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_INS_UPDATES_NUMBER_OF_REJECTED_SPEED_UPDATES_SINCE_LAST_MESSAGE_MASK)) \
                             << (SBP_INS_UPDATES_NUMBER_OF_REJECTED_SPEED_UPDATES_SINCE_LAST_MESSAGE_SHIFT)));} while(0)
                             

#define SBP_INS_UPDATES_NUMBER_OF_ATTEMPTED_NHC_UPDATES_SINCE_LAST_MESSAGE_MASK (0xf)
#define SBP_INS_UPDATES_NUMBER_OF_ATTEMPTED_NHC_UPDATES_SINCE_LAST_MESSAGE_SHIFT (4u)
#define SBP_INS_UPDATES_NUMBER_OF_ATTEMPTED_NHC_UPDATES_SINCE_LAST_MESSAGE_GET(flags) \
                             (((flags) >> SBP_INS_UPDATES_NUMBER_OF_ATTEMPTED_NHC_UPDATES_SINCE_LAST_MESSAGE_SHIFT) \
                             & SBP_INS_UPDATES_NUMBER_OF_ATTEMPTED_NHC_UPDATES_SINCE_LAST_MESSAGE_MASK)
#define SBP_INS_UPDATES_NUMBER_OF_ATTEMPTED_NHC_UPDATES_SINCE_LAST_MESSAGE_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_INS_UPDATES_NUMBER_OF_ATTEMPTED_NHC_UPDATES_SINCE_LAST_MESSAGE_MASK)) \
                             << (SBP_INS_UPDATES_NUMBER_OF_ATTEMPTED_NHC_UPDATES_SINCE_LAST_MESSAGE_SHIFT)));} while(0)
                             

#define SBP_INS_UPDATES_NUMBER_OF_REJECTED_NHC_UPDATES_SINCE_LAST_MESSAGE_MASK (0xf)
#define SBP_INS_UPDATES_NUMBER_OF_REJECTED_NHC_UPDATES_SINCE_LAST_MESSAGE_SHIFT (0u)
#define SBP_INS_UPDATES_NUMBER_OF_REJECTED_NHC_UPDATES_SINCE_LAST_MESSAGE_GET(flags) \
                             (((flags) >> SBP_INS_UPDATES_NUMBER_OF_REJECTED_NHC_UPDATES_SINCE_LAST_MESSAGE_SHIFT) \
                             & SBP_INS_UPDATES_NUMBER_OF_REJECTED_NHC_UPDATES_SINCE_LAST_MESSAGE_MASK)
#define SBP_INS_UPDATES_NUMBER_OF_REJECTED_NHC_UPDATES_SINCE_LAST_MESSAGE_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_INS_UPDATES_NUMBER_OF_REJECTED_NHC_UPDATES_SINCE_LAST_MESSAGE_MASK)) \
                             << (SBP_INS_UPDATES_NUMBER_OF_REJECTED_NHC_UPDATES_SINCE_LAST_MESSAGE_SHIFT)));} while(0)
                             

#define SBP_INS_UPDATES_NUMBER_OF_ATTEMPTED_ZERO_VELOCITY_UPDATES_SINCE_LAST_MESSAGE_MASK (0xf)
#define SBP_INS_UPDATES_NUMBER_OF_ATTEMPTED_ZERO_VELOCITY_UPDATES_SINCE_LAST_MESSAGE_SHIFT (4u)
#define SBP_INS_UPDATES_NUMBER_OF_ATTEMPTED_ZERO_VELOCITY_UPDATES_SINCE_LAST_MESSAGE_GET(flags) \
                             (((flags) >> SBP_INS_UPDATES_NUMBER_OF_ATTEMPTED_ZERO_VELOCITY_UPDATES_SINCE_LAST_MESSAGE_SHIFT) \
                             & SBP_INS_UPDATES_NUMBER_OF_ATTEMPTED_ZERO_VELOCITY_UPDATES_SINCE_LAST_MESSAGE_MASK)
#define SBP_INS_UPDATES_NUMBER_OF_ATTEMPTED_ZERO_VELOCITY_UPDATES_SINCE_LAST_MESSAGE_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_INS_UPDATES_NUMBER_OF_ATTEMPTED_ZERO_VELOCITY_UPDATES_SINCE_LAST_MESSAGE_MASK)) \
                             << (SBP_INS_UPDATES_NUMBER_OF_ATTEMPTED_ZERO_VELOCITY_UPDATES_SINCE_LAST_MESSAGE_SHIFT)));} while(0)
                             

#define SBP_INS_UPDATES_NUMBER_OF_REJECTED_ZERO_VELOCITY_UPDATES_SINCE_LAST_MESSAGE_MASK (0xf)
#define SBP_INS_UPDATES_NUMBER_OF_REJECTED_ZERO_VELOCITY_UPDATES_SINCE_LAST_MESSAGE_SHIFT (0u)
#define SBP_INS_UPDATES_NUMBER_OF_REJECTED_ZERO_VELOCITY_UPDATES_SINCE_LAST_MESSAGE_GET(flags) \
                             (((flags) >> SBP_INS_UPDATES_NUMBER_OF_REJECTED_ZERO_VELOCITY_UPDATES_SINCE_LAST_MESSAGE_SHIFT) \
                             & SBP_INS_UPDATES_NUMBER_OF_REJECTED_ZERO_VELOCITY_UPDATES_SINCE_LAST_MESSAGE_MASK)
#define SBP_INS_UPDATES_NUMBER_OF_REJECTED_ZERO_VELOCITY_UPDATES_SINCE_LAST_MESSAGE_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_INS_UPDATES_NUMBER_OF_REJECTED_ZERO_VELOCITY_UPDATES_SINCE_LAST_MESSAGE_MASK)) \
                             << (SBP_INS_UPDATES_NUMBER_OF_REJECTED_ZERO_VELOCITY_UPDATES_SINCE_LAST_MESSAGE_SHIFT)));} while(0)
                             


typedef struct SBP_ATTR_PACKED {
  u32 tow;           /**< GPS Time of Week [ms] */
  u8 gnsspos;       /**< GNSS position update status flags */
  u8 gnssvel;       /**< GNSS velocity update status flags */
  u8 wheelticks;    /**< Wheelticks update status flags */
  u8 speed;         /**< Wheelticks update status flags */
  u8 nhc;           /**< NHC update status flags */
  u8 zerovel;       /**< Zero velocity update status flags */
} msg_ins_updates_t;
 

/** Offset of the local time with respect to GNSS time
 *
 * The GNSS time offset message contains the information that is needed to translate messages
 * tagged with a local timestamp (e.g. IMU or wheeltick messages) to GNSS time for the sender
 * producing this message.
 */
#define SBP_MSG_GNSS_TIME_OFFSET      0xFF07

typedef struct SBP_ATTR_PACKED {
  s16 weeks;           /**< Weeks portion of the time offset [weeks] */
  s32 milliseconds;    /**< Milliseconds portion of the time offset [ms] */
  s16 microseconds;    /**< Microseconds portion of the time offset [microseconds] */
  u8 flags;           /**< Status flags (reserved) */
} msg_gnss_time_offset_t;
 

/** Solution Group Metadata
 *
 * This leading message lists the time metadata of the Solution Group.
 * It also lists the atomic contents (i.e. types of messages included) of the Solution Group.
 */
#define SBP_MSG_GROUP_META            0xFF0A
#define SBP_GROUP_META_SOLUTION_GROUP_TYPE_MASK (0x3)
#define SBP_GROUP_META_SOLUTION_GROUP_TYPE_SHIFT (0u)
#define SBP_GROUP_META_SOLUTION_GROUP_TYPE_GET(flags) \
                             (((flags) >> SBP_GROUP_META_SOLUTION_GROUP_TYPE_SHIFT) \
                             & SBP_GROUP_META_SOLUTION_GROUP_TYPE_MASK)
#define SBP_GROUP_META_SOLUTION_GROUP_TYPE_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_GROUP_META_SOLUTION_GROUP_TYPE_MASK)) \
                             << (SBP_GROUP_META_SOLUTION_GROUP_TYPE_SHIFT)));} while(0)
                             

#define SBP_GROUP_META_SOLUTION_GROUP_TYPE_NONE (0)
#define SBP_GROUP_META_SOLUTION_GROUP_TYPE_GNSS_ONLY (1)
#define SBP_GROUP_META_SOLUTION_GROUP_TYPE_GNSSINS (2)

typedef struct SBP_ATTR_PACKED {
  u8 group_id;        /**< Id of the Msgs Group, 0 is Unknown, 1 is Bestpos, 2 is Gnss */
  u8 flags;           /**< Status flags (reserved) */
  u8 n_group_msgs;    /**< Size of list group_msgs */
#ifdef SBP_ENABLE_VARIABLE_SIZED_ARRAYS
  u16 group_msgs[0];   /**< An inorder list of message types included in the Solution Group,
including GROUP_META itself
 */
#endif
} msg_group_meta_t;
#define MSG_GROUP_META_T_GET_GROUP_MSGS_PTR(msg) (( u16 *)(msg+1))
#define MSG_GROUP_META_T_GET_GROUP_MSGS_CPTR(msg) ((const u16 *)(msg+1))
 

/** \} */
static inline void static_asserts_for_module_MSG_STARTUP(void) {
#ifdef __cplusplus
static_assert(offsetof(msg_startup_t, cause ) == 0, "Offset of cause in msg_startup_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_startup_t, cause ) == 0, offset_of_cause_in_msg_startup_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_startup_t, startup_type ) == 0 + sizeof(u8), "Offset of startup_type in msg_startup_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_startup_t, startup_type ) == 0 + sizeof(u8), offset_of_startup_type_in_msg_startup_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_startup_t, reserved ) == 0 + sizeof(u8) + sizeof(u8), "Offset of reserved in msg_startup_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_startup_t, reserved ) == 0 + sizeof(u8) + sizeof(u8), offset_of_reserved_in_msg_startup_t_is_incorrect)
#endif
}

static inline void static_asserts_for_module_MSG_DGNSS_STATUS(void) {
#ifdef __cplusplus
static_assert(offsetof(msg_dgnss_status_t, flags ) == 0, "Offset of flags in msg_dgnss_status_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_dgnss_status_t, flags ) == 0, offset_of_flags_in_msg_dgnss_status_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_dgnss_status_t, latency ) == 0 + sizeof(u8), "Offset of latency in msg_dgnss_status_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_dgnss_status_t, latency ) == 0 + sizeof(u8), offset_of_latency_in_msg_dgnss_status_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_dgnss_status_t, num_signals ) == 0 + sizeof(u8) + sizeof(u16), "Offset of num_signals in msg_dgnss_status_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_dgnss_status_t, num_signals ) == 0 + sizeof(u8) + sizeof(u16), offset_of_num_signals_in_msg_dgnss_status_t_is_incorrect)
#endif
#ifdef SBP_ENABLE_VARIABLE_SIZED_ARRAYS
#ifdef __cplusplus
static_assert(offsetof(msg_dgnss_status_t, source ) == 0 + sizeof(u8) + sizeof(u16) + sizeof(u8), "Offset of source in msg_dgnss_status_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_dgnss_status_t, source ) == 0 + sizeof(u8) + sizeof(u16) + sizeof(u8), offset_of_source_in_msg_dgnss_status_t_is_incorrect)
#endif
#endif
}

static inline void static_asserts_for_module_MSG_HEARTBEAT(void) {
#ifdef __cplusplus
static_assert(offsetof(msg_heartbeat_t, flags ) == 0, "Offset of flags in msg_heartbeat_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_heartbeat_t, flags ) == 0, offset_of_flags_in_msg_heartbeat_t_is_incorrect)
#endif
}

static inline void static_asserts_for_module_SubSystemReport(void) {
#ifdef __cplusplus
static_assert(offsetof(sub_system_report_t, component ) == 0, "Offset of component in sub_system_report_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(sub_system_report_t, component ) == 0, offset_of_component_in_sub_system_report_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(sub_system_report_t, generic ) == 0 + sizeof(u16), "Offset of generic in sub_system_report_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(sub_system_report_t, generic ) == 0 + sizeof(u16), offset_of_generic_in_sub_system_report_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(sub_system_report_t, specific ) == 0 + sizeof(u16) + sizeof(u8), "Offset of specific in sub_system_report_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(sub_system_report_t, specific ) == 0 + sizeof(u16) + sizeof(u8), offset_of_specific_in_sub_system_report_t_is_incorrect)
#endif
}

static inline void static_asserts_for_module_MSG_STATUS_REPORT(void) {
#ifdef __cplusplus
static_assert(offsetof(msg_status_report_t, reporting_system ) == 0, "Offset of reporting_system in msg_status_report_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_status_report_t, reporting_system ) == 0, offset_of_reporting_system_in_msg_status_report_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_status_report_t, sbp_version ) == 0 + sizeof(u16), "Offset of sbp_version in msg_status_report_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_status_report_t, sbp_version ) == 0 + sizeof(u16), offset_of_sbp_version_in_msg_status_report_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_status_report_t, sequence ) == 0 + sizeof(u16) + sizeof(u16), "Offset of sequence in msg_status_report_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_status_report_t, sequence ) == 0 + sizeof(u16) + sizeof(u16), offset_of_sequence_in_msg_status_report_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_status_report_t, uptime ) == 0 + sizeof(u16) + sizeof(u16) + sizeof(u32), "Offset of uptime in msg_status_report_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_status_report_t, uptime ) == 0 + sizeof(u16) + sizeof(u16) + sizeof(u32), offset_of_uptime_in_msg_status_report_t_is_incorrect)
#endif
#ifdef SBP_ENABLE_VARIABLE_SIZED_ARRAYS
#ifdef __cplusplus
static_assert(offsetof(msg_status_report_t, status ) == 0 + sizeof(u16) + sizeof(u16) + sizeof(u32) + sizeof(u32), "Offset of status in msg_status_report_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_status_report_t, status ) == 0 + sizeof(u16) + sizeof(u16) + sizeof(u32) + sizeof(u32), offset_of_status_in_msg_status_report_t_is_incorrect)
#endif
#endif
}

static inline void static_asserts_for_module_MSG_INS_STATUS(void) {
#ifdef __cplusplus
static_assert(offsetof(msg_ins_status_t, flags ) == 0, "Offset of flags in msg_ins_status_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ins_status_t, flags ) == 0, offset_of_flags_in_msg_ins_status_t_is_incorrect)
#endif
}

static inline void static_asserts_for_module_MSG_CSAC_TELEMETRY(void) {
#ifdef __cplusplus
static_assert(offsetof(msg_csac_telemetry_t, id ) == 0, "Offset of id in msg_csac_telemetry_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_csac_telemetry_t, id ) == 0, offset_of_id_in_msg_csac_telemetry_t_is_incorrect)
#endif
#ifdef SBP_ENABLE_VARIABLE_SIZED_ARRAYS
#ifdef __cplusplus
static_assert(offsetof(msg_csac_telemetry_t, telemetry ) == 0 + sizeof(u8), "Offset of telemetry in msg_csac_telemetry_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_csac_telemetry_t, telemetry ) == 0 + sizeof(u8), offset_of_telemetry_in_msg_csac_telemetry_t_is_incorrect)
#endif
#endif
}

static inline void static_asserts_for_module_MSG_CSAC_TELEMETRY_LABELS(void) {
#ifdef __cplusplus
static_assert(offsetof(msg_csac_telemetry_labels_t, id ) == 0, "Offset of id in msg_csac_telemetry_labels_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_csac_telemetry_labels_t, id ) == 0, offset_of_id_in_msg_csac_telemetry_labels_t_is_incorrect)
#endif
#ifdef SBP_ENABLE_VARIABLE_SIZED_ARRAYS
#ifdef __cplusplus
static_assert(offsetof(msg_csac_telemetry_labels_t, telemetry_labels ) == 0 + sizeof(u8), "Offset of telemetry_labels in msg_csac_telemetry_labels_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_csac_telemetry_labels_t, telemetry_labels ) == 0 + sizeof(u8), offset_of_telemetry_labels_in_msg_csac_telemetry_labels_t_is_incorrect)
#endif
#endif
}

static inline void static_asserts_for_module_MSG_INS_UPDATES(void) {
#ifdef __cplusplus
static_assert(offsetof(msg_ins_updates_t, tow ) == 0, "Offset of tow in msg_ins_updates_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ins_updates_t, tow ) == 0, offset_of_tow_in_msg_ins_updates_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_ins_updates_t, gnsspos ) == 0 + sizeof(u32), "Offset of gnsspos in msg_ins_updates_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ins_updates_t, gnsspos ) == 0 + sizeof(u32), offset_of_gnsspos_in_msg_ins_updates_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_ins_updates_t, gnssvel ) == 0 + sizeof(u32) + sizeof(u8), "Offset of gnssvel in msg_ins_updates_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ins_updates_t, gnssvel ) == 0 + sizeof(u32) + sizeof(u8), offset_of_gnssvel_in_msg_ins_updates_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_ins_updates_t, wheelticks ) == 0 + sizeof(u32) + sizeof(u8) + sizeof(u8), "Offset of wheelticks in msg_ins_updates_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ins_updates_t, wheelticks ) == 0 + sizeof(u32) + sizeof(u8) + sizeof(u8), offset_of_wheelticks_in_msg_ins_updates_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_ins_updates_t, speed ) == 0 + sizeof(u32) + sizeof(u8) + sizeof(u8) + sizeof(u8), "Offset of speed in msg_ins_updates_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ins_updates_t, speed ) == 0 + sizeof(u32) + sizeof(u8) + sizeof(u8) + sizeof(u8), offset_of_speed_in_msg_ins_updates_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_ins_updates_t, nhc ) == 0 + sizeof(u32) + sizeof(u8) + sizeof(u8) + sizeof(u8) + sizeof(u8), "Offset of nhc in msg_ins_updates_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ins_updates_t, nhc ) == 0 + sizeof(u32) + sizeof(u8) + sizeof(u8) + sizeof(u8) + sizeof(u8), offset_of_nhc_in_msg_ins_updates_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_ins_updates_t, zerovel ) == 0 + sizeof(u32) + sizeof(u8) + sizeof(u8) + sizeof(u8) + sizeof(u8) + sizeof(u8), "Offset of zerovel in msg_ins_updates_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ins_updates_t, zerovel ) == 0 + sizeof(u32) + sizeof(u8) + sizeof(u8) + sizeof(u8) + sizeof(u8) + sizeof(u8), offset_of_zerovel_in_msg_ins_updates_t_is_incorrect)
#endif
}

static inline void static_asserts_for_module_MSG_GNSS_TIME_OFFSET(void) {
#ifdef __cplusplus
static_assert(offsetof(msg_gnss_time_offset_t, weeks ) == 0, "Offset of weeks in msg_gnss_time_offset_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_gnss_time_offset_t, weeks ) == 0, offset_of_weeks_in_msg_gnss_time_offset_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_gnss_time_offset_t, milliseconds ) == 0 + sizeof(s16), "Offset of milliseconds in msg_gnss_time_offset_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_gnss_time_offset_t, milliseconds ) == 0 + sizeof(s16), offset_of_milliseconds_in_msg_gnss_time_offset_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_gnss_time_offset_t, microseconds ) == 0 + sizeof(s16) + sizeof(s32), "Offset of microseconds in msg_gnss_time_offset_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_gnss_time_offset_t, microseconds ) == 0 + sizeof(s16) + sizeof(s32), offset_of_microseconds_in_msg_gnss_time_offset_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_gnss_time_offset_t, flags ) == 0 + sizeof(s16) + sizeof(s32) + sizeof(s16), "Offset of flags in msg_gnss_time_offset_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_gnss_time_offset_t, flags ) == 0 + sizeof(s16) + sizeof(s32) + sizeof(s16), offset_of_flags_in_msg_gnss_time_offset_t_is_incorrect)
#endif
}

static inline void static_asserts_for_module_MSG_GROUP_META(void) {
#ifdef __cplusplus
static_assert(offsetof(msg_group_meta_t, group_id ) == 0, "Offset of group_id in msg_group_meta_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_group_meta_t, group_id ) == 0, offset_of_group_id_in_msg_group_meta_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_group_meta_t, flags ) == 0 + sizeof(u8), "Offset of flags in msg_group_meta_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_group_meta_t, flags ) == 0 + sizeof(u8), offset_of_flags_in_msg_group_meta_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_group_meta_t, n_group_msgs ) == 0 + sizeof(u8) + sizeof(u8), "Offset of n_group_msgs in msg_group_meta_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_group_meta_t, n_group_msgs ) == 0 + sizeof(u8) + sizeof(u8), offset_of_n_group_msgs_in_msg_group_meta_t_is_incorrect)
#endif
#ifdef SBP_ENABLE_VARIABLE_SIZED_ARRAYS
#ifdef __cplusplus
static_assert(offsetof(msg_group_meta_t, group_msgs ) == 0 + sizeof(u8) + sizeof(u8) + sizeof(u8), "Offset of group_msgs in msg_group_meta_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_group_meta_t, group_msgs ) == 0 + sizeof(u8) + sizeof(u8) + sizeof(u8), offset_of_group_msgs_in_msg_group_meta_t_is_incorrect)
#endif
#endif
}


#ifdef __ghs__
#pragma pack()
#endif
SBP_PACK_END

#endif /* LIBSBP_SYSTEM_MESSAGES_H */
