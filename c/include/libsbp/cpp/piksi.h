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
 * Automatically generated from yaml/swiftnav/sbp/piksi.yaml
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

#ifndef LIBSBP_CPP_PIKSI_MESSAGES_H
#define LIBSBP_CPP_PIKSI_MESSAGES_H

#include <cstddef>
#include <libsbp/common.h>
#include <libsbp/sbp.h>
#include <libsbp/cpp/gnss.h>

namespace sbp {
  
  /**
   * Legacy message to load satellite almanac (host => Piksi)
   *
   * This is a legacy message for sending and loading a satellite
   * alamanac onto the Piksi's flash memory from the host.
   */
  
  /**
   * Send GPS time from host (host => Piksi)
   *
   * This message sets up timing functionality using a coarse GPS
   * time estimate sent by the host.
   */
  
  /**
   * Reset the device (host => Piksi)
   *
   * This message from the host resets the Piksi back into the
   * bootloader.
   */
  
  struct SBP_ATTR_PACKED MsgReset {
    u32 flags; /** Reset flags */
  };
  
  /**
   * Reset the device (host => Piksi)
   *
   * This message from the host resets the Piksi back into the
   * bootloader.
   */
  
  /**
   * Legacy message for CW interference channel (Piksi => host)
   *
   * This is an unused legacy message for result reporting from the
   * CW interference channel on the SwiftNAP. This message will be
   * removed in a future release.
   */
  
  /**
   * Legacy message for CW interference channel (host => Piksi)
   *
   * This is an unused legacy message from the host for starting
   * the CW interference channel on the SwiftNAP. This message will
   * be removed in a future release.
   */
  
  /**
   * Reset IAR filters (host => Piksi)
   *
   * This message resets either the DGNSS Kalman filters or Integer
   * Ambiguity Resolution (IAR) process.
   */
  
  struct SBP_ATTR_PACKED MsgResetFilters {
    u8 filter; /** Filter flags */
  };
  
  /**
   * Deprecated
   *
   * Deprecated
   */
  
  /**
   * State of an RTOS thread
   *
   * The thread usage message from the device reports real-time
   * operating system (RTOS) thread usage statistics for the named
   * thread. The reported percentage values must be normalized.
   */
  
  struct SBP_ATTR_PACKED MsgThreadState {
    char name[20]; /** Thread name (NULL terminated) */
    u16 cpu; /** Percentage cpu use for this thread. Values range from 0
- 1000 and needs to be renormalized to 100
 */
    u32 stack_free; /** Free stack space for this thread [bytes] */
  };
  
  /**
   * State of the UART channel
   *
   * Throughput, utilization, and error counts on the RX/TX buffers
   * of this UART channel. The reported percentage values must
   * be normalized.
   */
  
  struct SBP_ATTR_PACKED UARTChannel {
    float tx_throughput; /** UART transmit throughput [kB/s] */
    float rx_throughput; /** UART receive throughput [kB/s] */
    u16 crc_error_count; /** UART CRC error count */
    u16 io_error_count; /** UART IO error count */
    u8 tx_buffer_level; /** UART transmit buffer percentage utilization (ranges from
0 to 255)
 */
    u8 rx_buffer_level; /** UART receive buffer percentage utilization (ranges from
0 to 255)
 */
  };
  
  /**
   * base station observation message receipt period
   *
   * Statistics on the period of observations received from the base
   * station. As complete observation sets are received, their time
   * of reception is compared with the prior set''s time of reception.
   * This measurement provides a proxy for link quality as incomplete
   * or missing sets will increase the period.  Long periods
   * can cause momentary RTK solution outages.
   */
  
  struct SBP_ATTR_PACKED Period {
    s32 avg; /** Average period [ms] */
    s32 pmin; /** Minimum period [ms] */
    s32 pmax; /** Maximum period [ms] */
    s32 current; /** Smoothed estimate of the current period [ms] */
  };
  
  /**
   * Receiver-to-base station latency
   *
   * Statistics on the latency of observations received from the base
   * station. As observation packets are received their GPS time is
   * compared to the current GPS time calculated locally by the
   * receiver to give a precise measurement of the end-to-end
   * communication latency in the system.
   */
  
  struct SBP_ATTR_PACKED Latency {
    s32 avg; /** Average latency [ms] */
    s32 lmin; /** Minimum latency [ms] */
    s32 lmax; /** Maximum latency [ms] */
    s32 current; /** Smoothed estimate of the current latency [ms] */
  };
  
  /**
   * State of the UART channels
   *
   * The UART message reports data latency and throughput of the UART
   * channels providing SBP I/O. On the default Piksi configuration,
   * UARTs A and B are used for telemetry radios, but can also be
   * host access ports for embedded hosts, or other interfaces in
   * future. The reported percentage values must be normalized.
   * Observations latency and period can be used to assess the
   * health of the differential corrections link. Latency provides
   * the timeliness of received base observations while the
   * period indicates their likelihood of transmission.
   */
  
  struct SBP_ATTR_PACKED MsgUartState {
    UARTChannel uart_a; /** State of UART A */
    UARTChannel uart_b; /** State of UART B */
    UARTChannel uart_ftdi; /** State of UART FTDI (USB logger) */
    Latency latency; /** UART communication latency */
    Period obs_period; /** Observation receipt period */
  };
  
  /**
   * Deprecated
   *
   * Deprecated
   */
  
  struct SBP_ATTR_PACKED MsgUartStateDepa {
    UARTChannel uart_a; /** State of UART A */
    UARTChannel uart_b; /** State of UART B */
    UARTChannel uart_ftdi; /** State of UART FTDI (USB logger) */
    Latency latency; /** UART communication latency */
  };
  
  /**
   * State of the Integer Ambiguity Resolution (IAR) process
   *
   * This message reports the state of the Integer Ambiguity
   * Resolution (IAR) process, which resolves unknown integer
   * ambiguities from double-differenced carrier-phase measurements
   * from satellite observations.
   */
  
  struct SBP_ATTR_PACKED MsgIarState {
    u32 num_hyps; /** Number of integer ambiguity hypotheses remaining */
  };
  
  /**
   * Mask a satellite from use in Piksi subsystems
   *
   * This message allows setting a mask to prevent a particular satellite
   * from being used in various Piksi subsystems.
   */
  
  struct SBP_ATTR_PACKED MsgMaskSatellite {
    u8 mask; /** Mask of systems that should ignore this satellite. */
    GnssSignal sid; /** GNSS signal for which the mask is applied */
  };
  
  /**
   * Deprecated
   *
   * Deprecated.
   */
  
  struct SBP_ATTR_PACKED MsgMaskSatelliteDep {
    u8 mask; /** Mask of systems that should ignore this satellite. */
    GnssSignalDep sid; /** GNSS signal for which the mask is applied */
  };
  
  /**
   * Device temperature and voltage levels
   *
   * This message contains temperature and voltage level measurements from the
   * processor's monitoring system and the RF frontend die temperature if
   * available.
   */
  
  struct SBP_ATTR_PACKED MsgDeviceMonitor {
    s16 dev_vin; /** Device V_in [V / 1000] */
    s16 cpu_vint; /** Processor V_int [V / 1000] */
    s16 cpu_vaux; /** Processor V_aux [V / 1000] */
    s16 cpu_temperature; /** Processor temperature [degrees C / 100] */
    s16 fe_temperature; /** Frontend temperature (if available) [degrees C / 100] */
  };
  
  /**
   * Execute a command (host => device)
   *
   * Request the recipient to execute an command.
   * Output will be sent in MSG_LOG messages, and the exit
   * code will be returned with MSG_COMMAND_RESP.
   */
  template<size_t COMMAND_COUNT = (SBP_MAX_PAYLOAD_LEN - (sizeof(u32) + 0)) / sizeof(char)>
  struct SBP_ATTR_PACKED MsgCommandReq {
    u32 sequence; /** Sequence number */
    char command[COMMAND_COUNT]; /** Command line to execute */
  };
  
  /**
   * Exit code from executed command (device => host)
   *
   * The response to MSG_COMMAND_REQ with the return code of
   * the command.  A return code of zero indicates success.
   */
  
  struct SBP_ATTR_PACKED MsgCommandResp {
    u32 sequence; /** Sequence number */
    s32 code; /** Exit code */
  };
  
  /**
   * Command output
   *
   * Returns the standard output and standard error of the
   * command requested by MSG_COMMAND_REQ.
   * The sequence number can be used to filter for filtering
   * the correct command.
   */
  template<size_t LINE_COUNT = (SBP_MAX_PAYLOAD_LEN - (sizeof(u32) + 0)) / sizeof(char)>
  struct SBP_ATTR_PACKED MsgCommandOutput {
    u32 sequence; /** Sequence number */
    char line[LINE_COUNT]; /** Line of standard output or standard error */
  };
  
  /**
   * Request state of Piksi network interfaces
   *
   * Request state of Piksi network interfaces.
   * Output will be sent in MSG_NETWORK_STATE_RESP messages
   */
  
  /**
   * State of network interface
   *
   * The state of a network interface on the Piksi.
   * Data is made to reflect output of ifaddrs struct returned by getifaddrs
   * in c.
   */
  
  struct SBP_ATTR_PACKED MsgNetworkStateResp {
    u8 ipv4_address[4]; /** IPv4 address (all zero when unavailable) */
    u8 ipv4_mask_size; /** IPv4 netmask CIDR notation */
    u8 ipv6_address[16]; /** IPv6 address (all zero when unavailable) */
    u8 ipv6_mask_size; /** IPv6 netmask CIDR notation */
    u32 rx_bytes; /** Number of Rx bytes */
    u32 tx_bytes; /** Number of Tx bytes */
    char interface_name[16]; /** Interface Name */
    u32 flags; /** Interface flags from SIOCGIFFLAGS */
  };
  
  /**
   * Bandwidth usage measurement for a single interface.
   *
   * The bandwidth usage for each interface can be reported
   * within this struct and utilize multiple fields to fully
   * specify the type of traffic that is being tracked. As
   * either the interval of collection or the collection time
   * may vary, both a timestamp and period field is provided,
   * though may not necessarily be populated with a value. 
   */
  
  struct SBP_ATTR_PACKED NetworkUsage {
    u64 duration; /** Duration over which the measurement was collected [ms] */
    u64 total_bytes; /** Number of bytes handled in total within period */
    u32 rx_bytes; /** Number of bytes transmitted within period */
    u32 tx_bytes; /** Number of bytes received within period */
    char interface_name[16]; /** Interface Name */
  };
  
  /**
   * Bandwidth usage reporting message
   *
   * The bandwidth usage, a list of usage by interface. 
   */
  template<size_t INTERFACES_COUNT = (SBP_MAX_PAYLOAD_LEN - (0)) / sizeof(NetworkUsage)>
  struct SBP_ATTR_PACKED MsgNetworkBandwidthUsage {
    NetworkUsage interfaces[INTERFACES_COUNT]; /** Usage measurement array */
  };
  
  /**
   * Cell modem information update message
   *
   * If a cell modem is present on a piksi device, this message
   * will be send periodically to update the host on the status
   * of the modem and its various parameters.
   */
  template<size_t RESERVED_COUNT = (SBP_MAX_PAYLOAD_LEN - (sizeof(s8) + sizeof(float) + 0)) / sizeof(u8)>
  struct SBP_ATTR_PACKED MsgCellModemStatus {
    s8 signal_strength; /** Received cell signal strength in dBm, zero translates to unknown [dBm] */
    float signal_error_rate; /** BER as reported by the modem, zero translates to unknown */
    u8 reserved[RESERVED_COUNT]; /** Unspecified data TBD for this schema */
  };
  
  /**
   * Deprecated
   *
   * Deprecated.
   */
  template<size_t AMPLITUDE_VALUE_COUNT = (SBP_MAX_PAYLOAD_LEN - (sizeof(u16) + sizeof(GPSTimeDep) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + 0)) / sizeof(u8)>
  struct SBP_ATTR_PACKED MsgSpecanDep {
    u16 channel_tag; /** Channel ID */
    GPSTimeDep t; /** Receiver time of this observation */
    float freq_ref; /** Reference frequency of this packet
 [MHz] */
    float freq_step; /** Frequency step of points in this packet
 [MHz] */
    float amplitude_ref; /** Reference amplitude of this packet
 [dB] */
    float amplitude_unit; /** Amplitude unit value of points in this packet
 [dB] */
    u8 amplitude_value[AMPLITUDE_VALUE_COUNT]; /** Amplitude values (in the above units) of points in this packet
 */
  };
  
  /**
   * Spectrum analyzer
   *
   * Spectrum analyzer packet.
   */
  template<size_t AMPLITUDE_VALUE_COUNT = (SBP_MAX_PAYLOAD_LEN - (sizeof(u16) + sizeof(GPSTime) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + 0)) / sizeof(u8)>
  struct SBP_ATTR_PACKED MsgSpecan {
    u16 channel_tag; /** Channel ID */
    GPSTime t; /** Receiver time of this observation */
    float freq_ref; /** Reference frequency of this packet
 [MHz] */
    float freq_step; /** Frequency step of points in this packet
 [MHz] */
    float amplitude_ref; /** Reference amplitude of this packet
 [dB] */
    float amplitude_unit; /** Amplitude unit value of points in this packet
 [dB] */
    u8 amplitude_value[AMPLITUDE_VALUE_COUNT]; /** Amplitude values (in the above units) of points in this packet
 */
  };
  
  /**
   * RF AGC status
   *
   * This message describes the gain of each channel in the receiver frontend. Each 
   * gain is encoded as a non-dimensional percentage relative to the maximum range  
   * possible for the gain stage of the frontend. By convention, each gain array 
   * has 8 entries and the index of the array corresponding to the index of the rf channel 
   * in the frontend. A gain of 127 percent encodes that rf channel is not present in the hardware.
   * A negative value implies an error for the particular gain stage as reported by the frontend.
   */
  
  struct SBP_ATTR_PACKED MsgFrontEndGain {
    s8 rf_gain[8]; /** RF gain for each frontend channel [percent] */
    s8 if_gain[8]; /** Intermediate frequency gain for each frontend channel [percent] */
  };
  

}  // namespace sbp

#endif /* LIBSBP_CPP_PIKSI_MESSAGES_H */