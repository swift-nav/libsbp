/*
 * Copyright (C) 2021 Swift Navigation Inc.
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

#ifndef LIBSBP_CPP_SYSTEM_MESSAGES_H
#define LIBSBP_CPP_SYSTEM_MESSAGES_H

#include <cstddef>
#include <libsbp/common.h>
#include <libsbp/sbp.h>

namespace sbp {
  
  /**
   * System start-up message
   *
   * The system start-up message is sent once on system
   * start-up. It notifies the host or other attached devices that
   * the system has started and is now ready to respond to commands
   * or configuration requests.
   */
  
  struct SBP_ATTR_PACKED MsgStartup {
    u8 cause; /** Cause of startup */
    u8 startup_type; /** Startup type */
    u16 reserved; /** Reserved */
  };
  
  /**
   * Status of received corrections
   *
   * This message provides information about the receipt of Differential
   * corrections.  It is expected to be sent with each receipt of a complete
   * corrections packet.
   */
  template<size_t SOURCE_COUNT = (SBP_MAX_PAYLOAD_LEN - (sizeof(u8) + sizeof(u16) + sizeof(u8) + 0)) / sizeof(char)>
  struct SBP_ATTR_PACKED MsgDgnssStatus {
    static constexpr size_t kSourceCount = SOURCE_COUNT;
    u8 flags; /** Status flags */
    u16 latency; /** Latency of observation receipt [deci-seconds] */
    u8 num_signals; /** Number of signals from base station */
    char source[SOURCE_COUNT]; /** Corrections source string */
  };
  
  /**
   * System heartbeat message
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
  
  struct SBP_ATTR_PACKED MsgHeartbeat {
    u32 flags; /** Status flags */
  };
  
  /**
   * Sub-system Status report
   *
   * Report the general and specific state of a sub-system.  If the generic
   * state is reported as initializing, the specific state should be ignored.
   */
  
  struct SBP_ATTR_PACKED SubSystemReport {
    u16 component; /** Identity of reporting subsystem */
    u8 generic; /** Generic form status report */
    u8 specific; /** Subsystem specific status code */
  };
  
  /**
   * Status report message
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
  template<size_t STATUS_COUNT = (SBP_MAX_PAYLOAD_LEN - (sizeof(u16) + sizeof(u16) + sizeof(u32) + sizeof(u32) + 0)) / sizeof(SubSystemReport)>
  struct SBP_ATTR_PACKED MsgStatusReport {
    static constexpr size_t kStatusCount = STATUS_COUNT;
    u16 reporting_system; /** Identity of reporting system */
    u16 sbp_version; /** SBP protocol version */
    u32 sequence; /** Increments on each status report sent */
    u32 uptime; /** Number of seconds since system start-up */
    SubSystemReport status[STATUS_COUNT]; /** Reported status of individual subsystems */
  };
  
  /**
   * Inertial Navigation System status message
   *
   * The INS status message describes the state of the operation
   * and initialization of the inertial navigation system. 
   */
  
  struct SBP_ATTR_PACKED MsgInsStatus {
    u32 flags; /** Status flags */
  };
  
  /**
   * Experimental telemetry message
   *
   * The CSAC telemetry message has an implementation defined telemetry string
   * from a device. It is not produced or available on general Swift Products.
   * It is intended to be a low rate message for status purposes.
   */
  template<size_t TELEMETRY_COUNT = (SBP_MAX_PAYLOAD_LEN - (sizeof(u8) + 0)) / sizeof(char)>
  struct SBP_ATTR_PACKED MsgCsacTelemetry {
    static constexpr size_t kTelemetryCount = TELEMETRY_COUNT;
    u8 id; /** Index representing the type of telemetry in use.  It is implemention defined. */
    char telemetry[TELEMETRY_COUNT]; /** Comma separated list of values as defined by the index */
  };
  
  /**
   * Experimental telemetry message labels
   *
   * The CSAC telemetry message provides labels for each member of the string
   * produced by MSG_CSAC_TELEMETRY. It should be provided by a device at a lower
   * rate than the MSG_CSAC_TELEMETRY.
   */
  template<size_t TELEMETRY_LABELS_COUNT = (SBP_MAX_PAYLOAD_LEN - (sizeof(u8) + 0)) / sizeof(char)>
  struct SBP_ATTR_PACKED MsgCsacTelemetryLabels {
    static constexpr size_t kTelemetryLabelsCount = TELEMETRY_LABELS_COUNT;
    u8 id; /** Index representing the type of telemetry in use.  It is implemention defined. */
    char telemetry_labels[TELEMETRY_LABELS_COUNT]; /** Comma separated list of telemetry field values */
  };
  
  /**
   * Inertial Navigation System update status message
   *
   * The INS update status message contains informations about executed and rejected INS updates.
   * This message is expected to be extended in the future as new types of measurements are being added.
   */
  
  struct SBP_ATTR_PACKED MsgInsUpdates {
    u32 tow; /** GPS Time of Week [ms] */
    u8 gnsspos; /** GNSS position update status flags */
    u8 gnssvel; /** GNSS velocity update status flags */
    u8 wheelticks; /** Wheelticks update status flags */
    u8 speed; /** Wheelticks update status flags */
    u8 nhc; /** NHC update status flags */
    u8 zerovel; /** Zero velocity update status flags */
  };
  
  /**
   * Offset of the local time with respect to GNSS time
   *
   * The GNSS time offset message contains the information that is needed to translate messages
   * tagged with a local timestamp (e.g. IMU or wheeltick messages) to GNSS time for the sender
   * producing this message.
   */
  
  struct SBP_ATTR_PACKED MsgGnssTimeOffset {
    s16 weeks; /** Weeks portion of the time offset [weeks] */
    s32 milliseconds; /** Milliseconds portion of the time offset [ms] */
    s16 microseconds; /** Microseconds portion of the time offset [microseconds] */
    u8 flags; /** Status flags (reserved) */
  };
  
  /**
   * Solution Group Metadata
   *
   * This leading message lists the time metadata of the Solution Group.
   * It also lists the atomic contents (i.e. types of messages included) of the Solution Group.
   */
  template<size_t GROUP_MSGS_COUNT = (SBP_MAX_PAYLOAD_LEN - (sizeof(u8) + sizeof(u8) + sizeof(u8) + 0)) / sizeof(u16)>
  struct SBP_ATTR_PACKED MsgGroupMeta {
    static constexpr size_t kGroupMsgsCount = GROUP_MSGS_COUNT;
    u8 group_id; /** Id of the Msgs Group, 0 is Unknown, 1 is Bestpos, 2 is Gnss */
    u8 flags; /** Status flags (reserved) */
    u8 n_group_msgs; /** Size of list group_msgs */
    u16 group_msgs[GROUP_MSGS_COUNT]; /** An inorder list of message types included in the Solution Group,
including GROUP_META itself
 */
  };
  

}  // namespace sbp

#endif /* LIBSBP_CPP_SYSTEM_MESSAGES_H */