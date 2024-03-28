# Copyright (C) 2015-2023 Swift Navigation Inc.
# Contact: https://support.swiftnav.com
#
# This source is subject to the license found in the file 'LICENSE' which must
# be be distributed together with this source. All other rights reserved.
#
# THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
# EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
# WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
#
# Standardized system messages from Swift Navigation devices.
#
# Automatically generated from spec/yaml/swiftnav/sbp/system.yaml with generate.py.
# Do not modify by hand!

meta:
  id: system
  endian: le
  imports: [  ]

types:

  msg_startup:
    doc: |
      The system start-up message is sent once on system start-up. It notifies
      the host or other attached devices that the system has started and is
      now ready to respond to commands or configuration requests.
    seq:
      - id: cause
        doc: |
          Cause of startup
        type: u1
      - id: startup_type
        doc: |
          Startup type
        type: u1
      - id: reserved
        doc: |
          Reserved
        type: u2
  
  msg_dgnss_status:
    doc: |
      This message provides information about the receipt of Differential
      corrections.  It is expected to be sent with each receipt of a complete
      corrections packet.
    seq:
      - id: flags
        doc: |
          Status flags
        type: u1
      - id: latency
        doc: |
          Latency of observation receipt
        type: u2
      - id: num_signals
        doc: |
          Number of signals from base station
        type: u1
      - id: source
        doc: |
          Corrections source string
        type: str
        encoding: ascii
        size-eos: true
  
  msg_heartbeat:
    doc: |
      The heartbeat message is sent periodically to inform the host or other
      attached devices that the system is running. It is used to monitor
      system malfunctions. It also contains status flags that indicate to the
      host the status of the system and whether it is operating correctly.
      Currently, the expected heartbeat interval is 1 sec.

      The system error flag is used to indicate that an error has occurred in
      the system. To determine the source of the error, the remaining error
      flags should be inspected.
    seq:
      - id: flags
        doc: |
          Status flags
        type: u4
  
  sub_system_report:
    doc: |
      Report the general and specific state of a subsystem.  If the generic
      state is reported as initializing, the specific state should be ignored.
    seq:
      - id: component
        doc: |
          Identity of reporting subsystem
        type: u2
      - id: generic
        doc: |
          Generic form status report
        type: u1
      - id: specific
        doc: |
          Subsystem specific status code
        type: u1
  
  msg_status_report:
    doc: |
      The status report is sent periodically to inform the host or other
      attached devices that the system is running. It is used to monitor
      system malfunctions. It contains status reports that indicate to the
      host the status of each subsystem and whether it is operating correctly.

      Interpretation of the subsystem specific status code is product
      dependent, but if the generic status code is initializing, it should be
      ignored.  Refer to product documentation for details.
    seq:
      - id: reporting_system
        doc: |
          Identity of reporting system
        type: u2
      - id: sbp_version
        doc: |
          SBP protocol version
        type: u2
      - id: sequence
        doc: |
          Increments on each status report sent
        type: u4
      - id: uptime
        doc: |
          Number of seconds since system start-up
        type: u4
      - id: status
        doc: |
          Reported status of individual subsystems
        type: sub_system_report
        repeat: eos
  
  status_journal_item:
    doc: |
      Reports the uptime and the state of a subsystem via generic and specific
      status codes.  If the generic state is reported as initializing, the
      specific state should be ignored.
    seq:
      - id: uptime
        doc: |
          Milliseconds since system startup
        type: u4
      - id: report
        type: sub_system_report
  
  msg_status_journal:
    doc: |
      The status journal message contains past status reports (see
      MSG_STATUS_REPORT) and functions as a error/event storage for telemetry
      purposes.
    seq:
      - id: reporting_system
        doc: |
          Identity of reporting system
        type: u2
      - id: sbp_version
        doc: |
          SBP protocol version
        type: u2
      - id: total_status_reports
        doc: |
          Total number of status reports sent since system startup
        type: u4
      - id: sequence_descriptor
        doc: |
          Index and number of messages in this sequence. First nibble is the
          size of the sequence (n), second nibble is the zero-indexed counter
          (ith packet of n)
        type: u1
      - id: journal
        doc: |
          Status journal
        type: status_journal_item
        repeat: eos
  
  msg_ins_status:
    doc: |
      The INS status message describes the state of the operation and
      initialization of the inertial navigation system.
    seq:
      - id: flags
        doc: |
          Status flags
        type: u4
  
  msg_csac_telemetry:
    doc: |
      The CSAC telemetry message has an implementation defined telemetry
      string from a device. It is not produced or available on general Swift
      Products. It is intended to be a low rate message for status purposes.
    seq:
      - id: id
        doc: |
          Index representing the type of telemetry in use.  It is
          implementation defined.
        type: u1
      - id: telemetry
        doc: |
          Comma separated list of values as defined by the index
        type: str
        encoding: ascii
        size-eos: true
  
  msg_csac_telemetry_labels:
    doc: |
      The CSAC telemetry message provides labels for each member of the string
      produced by MSG_CSAC_TELEMETRY. It should be provided by a device at a
      lower rate than the MSG_CSAC_TELEMETRY.
    seq:
      - id: id
        doc: |
          Index representing the type of telemetry in use.  It is
          implementation defined.
        type: u1
      - id: telemetry_labels
        doc: |
          Comma separated list of telemetry field values
        type: str
        encoding: ascii
        size-eos: true
  
  msg_ins_updates:
    doc: |
      The INS update status message contains information about executed and
      rejected INS updates. This message is expected to be extended in the
      future as new types of measurements are being added.
    seq:
      - id: tow
        doc: |
          GPS Time of Week
        type: u4
      - id: gnsspos
        doc: |
          GNSS position update status flags
        type: u1
      - id: gnssvel
        doc: |
          GNSS velocity update status flags
        type: u1
      - id: wheelticks
        doc: |
          Wheelticks update status flags
        type: u1
      - id: speed
        doc: |
          Wheelticks update status flags
        type: u1
      - id: nhc
        doc: |
          NHC update status flags
        type: u1
      - id: zerovel
        doc: |
          Zero velocity update status flags
        type: u1
  
  msg_gnss_time_offset:
    doc: |
      The GNSS time offset message contains the information that is needed to
      translate messages tagged with a local timestamp (e.g. IMU or wheeltick
      messages) to GNSS time for the sender producing this message.
    seq:
      - id: weeks
        doc: |
          Weeks portion of the time offset
        type: s2
      - id: milliseconds
        doc: |
          Milliseconds portion of the time offset
        type: s4
      - id: microseconds
        doc: |
          Microseconds portion of the time offset
        type: s2
      - id: flags
        doc: |
          Status flags
        type: u1
  
  msg_pps_time:
    doc: |
      The PPS time message contains the value of the sender's local time in
      microseconds at the moment a pulse is detected on the PPS input. This is
      to be used for synchronisation of sensor data sampled with a local
      timestamp (e.g. IMU or wheeltick messages) where GNSS time is unknown to
      the sender.

      The local time used to timestamp the PPS pulse must be generated by the
      same clock which is used to timestamp the IMU/wheel sensor data and
      should follow the same roll-over rules (i.e. it should roll over to zero
      after 604800 seconds). A separate MSG_PPS_TIME message should be sent
      for each source of sensor data which uses local timestamping.  The
      sender ID for each of these MSG_PPS_TIME messages should match the
      sender ID of the respective sensor data.
    seq:
      - id: time
        doc: |
          Local time in microseconds
        type: u8
      - id: flags
        doc: |
          Status flags
        type: u1
  
  msg_sensor_aid_event:
    doc: |
      This diagnostic message contains state and update status information for
      all sensors that are being used by the fusion engine. This message will
      be generated asynchronously to the solution messages and will be emitted
      anytime a sensor update is being processed.
    seq:
      - id: time
        doc: |
          Update timestamp in milliseconds.
        type: u4
      - id: sensor_type
        doc: |
          Sensor type
        type: u1
      - id: sensor_id
        doc: |
          Sensor identifier
        type: u2
      - id: sensor_state
        doc: |
          Reserved for future use
        type: u1
      - id: n_available_meas
        doc: |
          Number of available measurements in this epoch
        type: u1
      - id: n_attempted_meas
        doc: |
          Number of attempted measurements in this epoch
        type: u1
      - id: n_accepted_meas
        doc: |
          Number of accepted measurements in this epoch
        type: u1
      - id: flags
        doc: |
          Reserved for future use
        type: u4
  
  msg_group_meta:
    doc: |
      This leading message lists the time metadata of the Solution Group. It
      also lists the atomic contents (i.e. types of messages included) of the
      Solution Group.
    seq:
      - id: group_id
        doc: |
          Id of the Msgs Group, 0 is Unknown, 1 is Bestpos, 2 is Gnss
        type: u1
      - id: flags
        doc: |
          Status flags (reserved)
        type: u1
      - id: n_group_msgs
        doc: |
          Size of list group_msgs
        type: u1
      - id: group_msgs
        doc: |
          An in-order list of message types included in the Solution Group,
          including GROUP_META itself
        type: u2
        repeat: eos
  