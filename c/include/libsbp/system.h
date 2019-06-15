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


/** \} */

SBP_PACK_END

#endif /* LIBSBP_SYSTEM_MESSAGES_H */