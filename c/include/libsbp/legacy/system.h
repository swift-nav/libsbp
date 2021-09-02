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

/** \defgroup system System
 *
 * Standardized system messages from Swift Navigation devices.
 * \{ */

#ifndef LIBSBP_LEGACY_SYSTEM_MESSAGES_H
#define LIBSBP_LEGACY_SYSTEM_MESSAGES_H

#include <libsbp/common.h>

#include <libsbp/system_macros.h>

SBP_PACK_START

/** System start-up message
 *
 * The system start-up message is sent once on system start-up. It notifies
 * the host or other attached devices that the system has started and is now
 * ready to respond to commands or configuration requests.
 */

typedef struct SBP_ATTR_PACKED {
  u8 cause;        /**< Cause of startup */
  u8 startup_type; /**< Startup type */
  u16 reserved;    /**< Reserved */
} msg_startup_t;

/** Status of received corrections
 *
 * This message provides information about the receipt of Differential
 * corrections.  It is expected to be sent with each receipt of a complete
 * corrections packet.
 */

typedef struct SBP_ATTR_PACKED {
  u8 flags;       /**< Status flags */
  u16 latency;    /**< Latency of observation receipt [deci-seconds] */
  u8 num_signals; /**< Number of signals from base station */
  char source[0]; /**< Corrections source string */
} msg_dgnss_status_t;

/** System heartbeat message
 *
 * The heartbeat message is sent periodically to inform the host or other
 * attached devices that the system is running. It is used to monitor system
 * malfunctions. It also contains status flags that indicate to the host the
 * status of the system and whether it is operating correctly. Currently, the
 * expected heartbeat interval is 1 sec.
 *
 * The system error flag is used to indicate that an error has occurred in the
 * system. To determine the source of the error, the remaining error flags
 * should be inspected.
 */

typedef struct SBP_ATTR_PACKED {
  u32 flags; /**< Status flags */
} msg_heartbeat_t;

/** Sub-system Status report
 *
 * Report the general and specific state of a sub-system.  If the generic
 * state is reported as initializing, the specific state should be ignored.
 */

typedef struct SBP_ATTR_PACKED {
  u16 component; /**< Identity of reporting subsystem */
  u8 generic;    /**< Generic form status report */
  u8 specific;   /**< Subsystem specific status code */
} sub_system_report_t;

/** Status report message
 *
 * The status report is sent periodically to inform the host or other attached
 * devices that the system is running. It is used to monitor system
 * malfunctions. It contains status reports that indicate to the host the
 * status of each sub-system and whether it is operating correctly.
 *
 * Interpretation of the subsystem specific status code is product dependent,
 * but if the generic status code is initializing, it should be ignored.
 * Refer to product documentation for details.
 */

typedef struct SBP_ATTR_PACKED {
  u16 reporting_system;          /**< Identity of reporting system */
  u16 sbp_version;               /**< SBP protocol version */
  u32 sequence;                  /**< Increments on each status report sent */
  u32 uptime;                    /**< Number of seconds since system start-up */
  sub_system_report_t status[0]; /**< Reported status of individual
                                      subsystems */
} msg_status_report_t;

/** Inertial Navigation System status message
 *
 * The INS status message describes the state of the operation and
 * initialization of the inertial navigation system.
 */

typedef struct SBP_ATTR_PACKED {
  u32 flags; /**< Status flags */
} msg_ins_status_t;

/** Experimental telemetry message
 *
 * The CSAC telemetry message has an implementation defined telemetry string
 * from a device. It is not produced or available on general Swift Products.
 * It is intended to be a low rate message for status purposes.
 */

typedef struct SBP_ATTR_PACKED {
  u8 id;             /**< Index representing the type of telemetry in use.  It
                          is implementation defined. */
  char telemetry[0]; /**< Comma separated list of values as defined by the
                          index */
} msg_csac_telemetry_t;

/** Experimental telemetry message labels
 *
 * The CSAC telemetry message provides labels for each member of the string
 * produced by MSG_CSAC_TELEMETRY. It should be provided by a device at a
 * lower rate than the MSG_CSAC_TELEMETRY.
 */

typedef struct SBP_ATTR_PACKED {
  u8 id;                    /**< Index representing the type of telemetry in
                                 use.  It is implementation defined. */
  char telemetry_labels[0]; /**< Comma separated list of telemetry field
                                 values */
} msg_csac_telemetry_labels_t;

/** Inertial Navigation System update status message
 *
 * The INS update status message contains information about executed and
 * rejected INS updates. This message is expected to be extended in the future
 * as new types of measurements are being added.
 */

typedef struct SBP_ATTR_PACKED {
  u32 tow;       /**< GPS Time of Week [ms] */
  u8 gnsspos;    /**< GNSS position update status flags */
  u8 gnssvel;    /**< GNSS velocity update status flags */
  u8 wheelticks; /**< Wheelticks update status flags */
  u8 speed;      /**< Wheelticks update status flags */
  u8 nhc;        /**< NHC update status flags */
  u8 zerovel;    /**< Zero velocity update status flags */
} msg_ins_updates_t;

/** Offset of the local time with respect to GNSS time
 *
 * The GNSS time offset message contains the information that is needed to
 * translate messages tagged with a local timestamp (e.g. IMU or wheeltick
 * messages) to GNSS time for the sender producing this message.
 */

typedef struct SBP_ATTR_PACKED {
  s16 weeks;        /**< Weeks portion of the time offset [weeks] */
  s32 milliseconds; /**< Milliseconds portion of the time offset [ms] */
  s16 microseconds; /**< Microseconds portion of the time offset [microseconds]
                     */
  u8 flags;         /**< Status flags (reserved) */
} msg_gnss_time_offset_t;

/** Local time at detection of PPS pulse
 *
 * The PPS time message contains the value of the sender's local time in
 * microseconds at the moment a pulse is detected on the PPS input. This is to
 * be used for syncronisation of sensor data sampled with a local timestamp
 * (e.g. IMU or wheeltick messages) where GNSS time is unknown to the sender.
 *
 * The local time used to timestamp the PPS pulse must be generated by the
 * same clock which is used to timestamp the IMU/wheel sensor data and should
 * follow the same roll-over rules.  A separate MSG_PPS_TIME message should be
 * sent for each source of sensor data which uses PPS-relative timestamping.
 * The sender ID for each of these MSG_PPS_TIME messages should match the
 * sender ID of the respective sensor data.
 */

typedef struct SBP_ATTR_PACKED {
  u64 time; /**< Local time in microseconds [microseconds] */
  u8 flags; /**< Status flags */
} msg_pps_time_t;

/** Solution Group Metadata
 *
 * This leading message lists the time metadata of the Solution Group. It also
 * lists the atomic contents (i.e. types of messages included) of the Solution
 * Group.
 */

typedef struct SBP_ATTR_PACKED {
  u8 group_id;       /**< Id of the Msgs Group, 0 is Unknown, 1 is Bestpos, 2
                          is Gnss */
  u8 flags;          /**< Status flags (reserved) */
  u8 n_group_msgs;   /**< Size of list group_msgs */
  u16 group_msgs[0]; /**< An in-order list of message types included in the
                          Solution Group, including GROUP_META itself */
} msg_group_meta_t;

/** \} */

SBP_PACK_END

#endif /* LIBSBP_LEGACY_SYSTEM_MESSAGES_H */