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
# System health, configuration, and diagnostic messages specific to the Piksi L1
# receiver, including a variety of legacy messages that may no longer be used.
#
# Automatically generated from spec/yaml/swiftnav/sbp/piksi.yaml with generate.py.
# Do not modify by hand!

meta:
  id: piksi
  endian: le
  imports: [ gnss ]

types:

  msg_almanac:
    doc: |
      This is a legacy message for sending and loading a satellite alamanac
      onto the Piksi's flash memory from the host.
    seq: []
  
  msg_set_time:
    doc: |
      This message sets up timing functionality using a coarse GPS time
      estimate sent by the host.
    seq: []
  
  msg_reset:
    doc: |
      This message from the host resets the Piksi back into the bootloader.
    seq:
      - id: flags
        doc: |
          Reset flags
        type: u4
  
  msg_reset_dep:
    doc: |
      Deprecated.
    seq: []
  
  msg_cw_results:
    doc: |
      This is an unused legacy message for result reporting from the CW
      interference channel on the SwiftNAP. This message will be removed in a
      future release.
    seq: []
  
  msg_cw_start:
    doc: |
      This is an unused legacy message from the host for starting the CW
      interference channel on the SwiftNAP. This message will be removed in a
      future release.
    seq: []
  
  msg_reset_filters:
    doc: |
      This message resets either the DGNSS Kalman filters or Integer Ambiguity
      Resolution (IAR) process.
    seq:
      - id: filter
        doc: |
          Filter flags
        type: u1
  
  msg_init_base_dep:
    doc: |
      Deprecated.
    seq: []
  
  msg_thread_state:
    doc: |
      The thread usage message from the device reports real-time operating
      system (RTOS) thread usage statistics for the named thread. The reported
      percentage values must be normalized.
    seq:
      - id: name
        doc: |
          Thread name (NULL terminated)
        type: str
        encoding: ascii
        size: 20
      - id: cpu
        doc: |
          Percentage cpu use for this thread. Values range from 0 - 1000 and
          needs to be renormalized to 100
        type: u2
      - id: stack_free
        doc: |
          Free stack space for this thread
        type: u4
  
  uart_channel:
    doc: |
      Throughput, utilization, and error counts on the RX/TX buffers of this
      UART channel. The reported percentage values must be normalized.
    seq:
      - id: tx_throughput
        doc: |
          UART transmit throughput
        type: f4
      - id: rx_throughput
        doc: |
          UART receive throughput
        type: f4
      - id: crc_error_count
        doc: |
          UART CRC error count
        type: u2
      - id: io_error_count
        doc: |
          UART IO error count
        type: u2
      - id: tx_buffer_level
        doc: |
          UART transmit buffer percentage utilization (ranges from 0 to 255)
        type: u1
      - id: rx_buffer_level
        doc: |
          UART receive buffer percentage utilization (ranges from 0 to 255)
        type: u1
  
  period:
    doc: |
      Statistics on the period of observations received from the base station.
      As complete observation sets are received, their time of reception is
      compared with the prior set''s time of reception. This measurement
      provides a proxy for link quality as incomplete or missing sets will
      increase the period.  Long periods can cause momentary RTK solution
      outages.
    seq:
      - id: avg
        doc: |
          Average period
        type: s4
      - id: pmin
        doc: |
          Minimum period
        type: s4
      - id: pmax
        doc: |
          Maximum period
        type: s4
      - id: current
        doc: |
          Smoothed estimate of the current period
        type: s4
  
  latency:
    doc: |
      Statistics on the latency of observations received from the base
      station. As observation packets are received their GPS time is compared
      to the current GPS time calculated locally by the receiver to give a
      precise measurement of the end-to-end communication latency in the
      system.
    seq:
      - id: avg
        doc: |
          Average latency
        type: s4
      - id: lmin
        doc: |
          Minimum latency
        type: s4
      - id: lmax
        doc: |
          Maximum latency
        type: s4
      - id: current
        doc: |
          Smoothed estimate of the current latency
        type: s4
  
  msg_uart_state:
    doc: |
      The UART message reports data latency and throughput of the UART
      channels providing SBP I/O. On the default Piksi configuration, UARTs A
      and B are used for telemetry radios, but can also be host access ports
      for embedded hosts, or other interfaces in future. The reported
      percentage values must be normalized. Observations latency and period
      can be used to assess the health of the differential corrections link.
      Latency provides the timeliness of received base observations while the
      period indicates their likelihood of transmission.
    seq:
      - id: uart_a
        doc: |
          State of UART A
        type: uart_channel
      - id: uart_b
        doc: |
          State of UART B
        type: uart_channel
      - id: uart_ftdi
        doc: |
          State of UART FTDI (USB logger)
        type: uart_channel
      - id: latency
        doc: |
          UART communication latency
        type: latency
      - id: obs_period
        doc: |
          Observation receipt period
        type: period
  
  msg_uart_state_depa:
    doc: |
      Deprecated.
    seq:
      - id: uart_a
        doc: |
          State of UART A
        type: uart_channel
      - id: uart_b
        doc: |
          State of UART B
        type: uart_channel
      - id: uart_ftdi
        doc: |
          State of UART FTDI (USB logger)
        type: uart_channel
      - id: latency
        doc: |
          UART communication latency
        type: latency
  
  msg_iar_state:
    doc: |
      This message reports the state of the Integer Ambiguity Resolution (IAR)
      process, which resolves unknown integer ambiguities from double-
      differenced carrier-phase measurements from satellite observations.
    seq:
      - id: num_hyps
        doc: |
          Number of integer ambiguity hypotheses remaining
        type: u4
  
  msg_mask_satellite:
    doc: |
      This message allows setting a mask to prevent a particular satellite
      from being used in various Piksi subsystems.
    seq:
      - id: mask
        doc: |
          Mask of systems that should ignore this satellite.
        type: u1
      - id: sid
        doc: |
          GNSS signal for which the mask is applied
        type: gnss::gnss_signal
  
  msg_mask_satellite_dep:
    doc: |
      Deprecated.
    seq:
      - id: mask
        doc: |
          Mask of systems that should ignore this satellite.
        type: u1
      - id: sid
        doc: |
          GNSS signal for which the mask is applied
        type: gnss::gnss_signal_dep
  
  msg_device_monitor:
    doc: |
      This message contains temperature and voltage level measurements from
      the processor's monitoring system and the RF frontend die temperature if
      available.
    seq:
      - id: dev_vin
        doc: |
          Device V_in
        type: s2
      - id: cpu_vint
        doc: |
          Processor V_int
        type: s2
      - id: cpu_vaux
        doc: |
          Processor V_aux
        type: s2
      - id: cpu_temperature
        doc: |
          Processor temperature
        type: s2
      - id: fe_temperature
        doc: |
          Frontend temperature (if available)
        type: s2
  
  msg_command_req:
    doc: |
      Request the recipient to execute an command. Output will be sent in
      MSG_LOG messages, and the exit code will be returned with
      MSG_COMMAND_RESP.
    seq:
      - id: sequence
        doc: |
          Sequence number
        type: u4
      - id: command
        doc: |
          Command line to execute
        type: str
        encoding: ascii
        size-eos: true
  
  msg_command_resp:
    doc: |
      The response to MSG_COMMAND_REQ with the return code of the command.  A
      return code of zero indicates success.
    seq:
      - id: sequence
        doc: |
          Sequence number
        type: u4
      - id: code
        doc: |
          Exit code
        type: s4
  
  msg_command_output:
    doc: |
      Returns the standard output and standard error of the command requested
      by MSG_COMMAND_REQ. The sequence number can be used to filter for
      filtering the correct command.
    seq:
      - id: sequence
        doc: |
          Sequence number
        type: u4
      - id: line
        doc: |
          Line of standard output or standard error
        type: str
        encoding: ascii
        size-eos: true
  
  msg_network_state_req:
    doc: |
      Request state of Piksi network interfaces. Output will be sent in
      MSG_NETWORK_STATE_RESP messages.
    seq: []
  
  msg_network_state_resp:
    doc: |
      The state of a network interface on the Piksi. Data is made to reflect
      output of ifaddrs struct returned by getifaddrs in c.
    seq:
      - id: ipv4_address
        doc: |
          IPv4 address (all zero when unavailable)
        type: u1
        repeat: expr
        repeat-expr: 4
      - id: ipv4_mask_size
        doc: |
          IPv4 netmask CIDR notation
        type: u1
      - id: ipv6_address
        doc: |
          IPv6 address (all zero when unavailable)
        type: u1
        repeat: expr
        repeat-expr: 16
      - id: ipv6_mask_size
        doc: |
          IPv6 netmask CIDR notation
        type: u1
      - id: rx_bytes
        doc: |
          Number of Rx bytes
        type: u4
      - id: tx_bytes
        doc: |
          Number of Tx bytes
        type: u4
      - id: interface_name
        doc: |
          Interface Name
        type: str
        encoding: ascii
        size: 16
      - id: flags
        doc: |
          Interface flags from SIOCGIFFLAGS
        type: u4
  
  network_usage:
    doc: |
      The bandwidth usage for each interface can be reported within this
      struct and utilize multiple fields to fully specify the type of traffic
      that is being tracked. As either the interval of collection or the
      collection time may vary, both a timestamp and period field is provided,
      though may not necessarily be populated with a value.
    seq:
      - id: duration
        doc: |
          Duration over which the measurement was collected
        type: u8
      - id: total_bytes
        doc: |
          Number of bytes handled in total within period
        type: u8
      - id: rx_bytes
        doc: |
          Number of bytes transmitted within period
        type: u4
      - id: tx_bytes
        doc: |
          Number of bytes received within period
        type: u4
      - id: interface_name
        doc: |
          Interface Name
        type: str
        encoding: ascii
        size: 16
  
  msg_network_bandwidth_usage:
    doc: |
      The bandwidth usage, a list of usage by interface.
    seq:
      - id: interfaces
        doc: |
          Usage measurement array
        type: network_usage
        repeat: eos
  
  msg_cell_modem_status:
    doc: |
      If a cell modem is present on a piksi device, this message will be send
      periodically to update the host on the status of the modem and its
      various parameters.
    seq:
      - id: signal_strength
        doc: |
          Received cell signal strength in dBm, zero translates to unknown
        type: s1
      - id: signal_error_rate
        doc: |
          BER as reported by the modem, zero translates to unknown
        type: f4
      - id: reserved
        doc: |
          Unspecified data TBD for this schema
        type: u1
        repeat: eos
  
  msg_specan_dep:
    doc: |
      Deprecated.
    seq:
      - id: channel_tag
        doc: |
          Channel ID
        type: u2
      - id: t
        doc: |
          Receiver time of this observation
        type: gnss::gps_time_dep
      - id: freq_ref
        doc: |
          Reference frequency of this packet
        type: f4
      - id: freq_step
        doc: |
          Frequency step of points in this packet
        type: f4
      - id: amplitude_ref
        doc: |
          Reference amplitude of this packet
        type: f4
      - id: amplitude_unit
        doc: |
          Amplitude unit value of points in this packet
        type: f4
      - id: amplitude_value
        doc: |
          Amplitude values (in the above units) of points in this packet
        type: u1
        repeat: eos
  
  msg_specan:
    doc: |
      Spectrum analyzer packet.
    seq:
      - id: channel_tag
        doc: |
          Channel ID
        type: u2
      - id: t
        doc: |
          Receiver time of this observation
        type: gnss::gps_time
      - id: freq_ref
        doc: |
          Reference frequency of this packet
        type: f4
      - id: freq_step
        doc: |
          Frequency step of points in this packet
        type: f4
      - id: amplitude_ref
        doc: |
          Reference amplitude of this packet
        type: f4
      - id: amplitude_unit
        doc: |
          Amplitude unit value of points in this packet
        type: f4
      - id: amplitude_value
        doc: |
          Amplitude values (in the above units) of points in this packet
        type: u1
        repeat: eos
  
  msg_front_end_gain:
    doc: |
      This message describes the gain of each channel in the receiver
      frontend. Each gain is encoded as a non-dimensional percentage relative
      to the maximum range possible for the gain stage of the frontend. By
      convention, each gain array has 8 entries and the index of the array
      corresponding to the index of the rf channel in the frontend. A gain of
      127 percent encodes that rf channel is not present in the hardware. A
      negative value implies an error for the particular gain stage as
      reported by the frontend.
    seq:
      - id: rf_gain
        doc: |
          RF gain for each frontend channel
        type: s1
        repeat: expr
        repeat-expr: 8
      - id: if_gain
        doc: |
          Intermediate frequency gain for each frontend channel
        type: s1
        repeat: expr
        repeat-expr: 8
  