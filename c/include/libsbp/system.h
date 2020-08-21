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


/** System start-up message
 *
 * The system start-up message is sent once on system
 * start-up. It notifies the host or other attached devices that
 * the system has started and is now ready to respond to commands
 * or configuration requests.
 */
#define SBP_MSG_STARTUP               0xFF00
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
typedef struct SBP_ATTR_PACKED {
  u8 flags;          /**< Status flags */
  u16 latency;        /**< Latency of observation receipt [deci-seconds] */
  u8 num_signals;    /**< Number of signals from base station */
  char source[0];      /**< Corrections source string */
} msg_dgnss_status_t;


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
typedef struct SBP_ATTR_PACKED {
  u32 flags;    /**< Status flags */
} msg_heartbeat_t;


/** Inertial Navigation System status message
 *
 * The INS status message describes the state of the operation
 * and initialization of the inertial navigation system. 
 */
#define SBP_MSG_INS_STATUS            0xFF03
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
  char telemetry[0]; /**< Comma separated list of values as defined by the index */
} msg_csac_telemetry_t;


/** Experimental telemetry message labels
 *
 * The CSAC telemetry message provides labels for each member of the string
 * produced by MSG_CSAC_TELEMETRY. It should be provided by a device at a lower
 * rate than the MSG_CSAC_TELEMETRY.
 */
#define SBP_MSG_CSAC_TELEMETRY_LABELS 0xFF05
typedef struct SBP_ATTR_PACKED {
  u8 id;                  /**< Index representing the type of telemetry in use.  It is implemention defined. */
  char telemetry_labels[0]; /**< Comma separated list of telemetry field values */
} msg_csac_telemetry_labels_t;


/** Inertial Navigation System update status message
 *
 * The INS update status message contains informations about executed and rejected INS updates.
 * This message is expected to be extended in the future as new types of measurements are being added.
 */
#define SBP_MSG_INS_UPDATES           0xFF06
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
typedef struct SBP_ATTR_PACKED {
  u8 group_id;        /**< Id of the Msgs Group, 0 is Unknown, 1 is Bestpos, 2 is Gnss */
  u16 wn;              /**< GPS Week Number or zero if Reference epoch is not GPS [weeks] */
  u32 tom;             /**< Time of Measurement in Milliseconds since reference epoch [ms] */
  s32 ns_residual;     /**< Nanosecond residual of millisecond-rounded TOM (ranges
from -500000 to 500000)
 [ns] */
  u8 flags;           /**< Status flags (reserved) */
  u8 n_group_msgs;    /**< Size of list group_msgs */
  u16 group_msgs[0];   /**< An inorder list of message types included in the Solution Group,
including GROUP_META itself
 */
} msg_group_meta_t;


/** \} */

SBP_PACK_END

#endif /* LIBSBP_SYSTEM_MESSAGES_H */