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
 * Automatically generated from yaml/swiftnav/sbp/piksi.yaml
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

/** \defgroup piksi Piksi
 *
 *  * System health, configuration, and diagnostic messages specific to
 * the Piksi L1 receiver, including a variety of legacy messages that
 * may no longer be used.
 * \{ */

#ifndef LIBSBP_PIKSI_MESSAGES_H
#define LIBSBP_PIKSI_MESSAGES_H

#include "common.h"
#include "gnss.h"


/** Legacy message to load satellite almanac (host => Piksi)
 *
 * This is a legacy message for sending and loading a satellite
 * alamanac onto the Piksi's flash memory from the host.
 */
#define SBP_MSG_ALMANAC            0x0069


/** Send GPS time from host (host => Piksi)
 *
 * This message sets up timing functionality using a coarse GPS
 * time estimate sent by the host.
 */
#define SBP_MSG_SET_TIME           0x0068


/** Reset the device (host => Piksi)
 *
 * This message from the host resets the Piksi back into the
 * bootloader.
 */
#define SBP_MSG_RESET              0x00B6
typedef struct __attribute__((packed)) {
  u32 flags;    /**< Reset flags */
} msg_reset_t;


/** Reset the device (host => Piksi)
 *
 * This message from the host resets the Piksi back into the
 * bootloader.
 */
#define SBP_MSG_RESET_DEP          0x00B2


/** Legacy message for CW interference channel (Piksi => host)
 *
 * This is an unused legacy message for result reporting from the
 * CW interference channel on the SwiftNAP. This message will be
 * removed in a future release.
 */
#define SBP_MSG_CW_RESULTS         0x00C0


/** Legacy message for CW interference channel (host => Piksi)
 *
 * This is an unused legacy message from the host for starting
 * the CW interference channel on the SwiftNAP. This message will
 * be removed in a future release.
 */
#define SBP_MSG_CW_START           0x00C1


/** Reset IAR filters (host => Piksi)
 *
 * This message resets either the DGNSS Kalman filters or Integer
 * Ambiguity Resolution (IAR) process.
 */
#define SBP_MSG_RESET_FILTERS      0x0022
typedef struct __attribute__((packed)) {
  u8 filter;    /**< Filter flags */
} msg_reset_filters_t;


/** Initialize IAR from known baseline (host => device)
 *
 * This message initializes the integer ambiguity resolution (IAR)
 * process on the Piksi to use an assumed baseline position between
 * the base station and rover receivers. Warns via MSG_PRINT if
 * there aren't a shared minimum number (4) of satellite
 * observations between the two.
 */
#define SBP_MSG_INIT_BASE          0x0023


/** State of an RTOS thread
 *
 * The thread usage message from the device reports real-time
 * operating system (RTOS) thread usage statistics for the named
 * thread. The reported percentage values must be normalized.
 */
#define SBP_MSG_THREAD_STATE       0x0017
typedef struct __attribute__((packed)) {
  char name[20];      /**< Thread name (NULL terminated) */
  u16 cpu;           /**< Percentage cpu use for this thread. Values range from 0
- 1000 and needs to be renormalized to 100
 */
  u32 stack_free;    /**< Free stack space for this thread [bytes] */
} msg_thread_state_t;


/** State of the UART channel
 *
 * Throughput, utilization, and error counts on the RX/TX buffers
 * of this UART channel. The reported percentage values must
 * be normalized.
 */
typedef struct __attribute__((packed)) {
  float tx_throughput;      /**< UART transmit throughput [kB/s] */
  float rx_throughput;      /**< UART receive throughput [kB/s] */
  u16 crc_error_count;    /**< UART CRC error count */
  u16 io_error_count;     /**< UART IO error count */
  u8 tx_buffer_level;    /**< UART transmit buffer percentage utilization (ranges from
0 to 255)
 */
  u8 rx_buffer_level;    /**< UART receive buffer percentage utilization (ranges from
0 to 255)
 */
} uart_channel_t;


/** base station observation message receipt period
 *
 * Statistics on the period of observations received from the base
 * station. As complete observation sets are received, their time
 * of reception is compared with the prior set''s time of reception.
 * This measurement provides a proxy for link quality as incomplete
 * or missing sets will increase the period.  Long periods
 * can cause momentary RTK solution outages.
 */
typedef struct __attribute__((packed)) {
  s32 avg;        /**< Average period [ms] */
  s32 pmin;       /**< Minimum period [ms] */
  s32 pmax;       /**< Maximum period [ms] */
  s32 current;    /**< Smoothed estimate of the current period [ms] */
} period_t;


/** Receiver-to-base station latency
 *
 * Statistics on the latency of observations received from the base
 * station. As observation packets are received their GPS time is
 * compared to the current GPS time calculated locally by the
 * receiver to give a precise measurement of the end-to-end
 * communication latency in the system.
 */
typedef struct __attribute__((packed)) {
  s32 avg;        /**< Average latency [ms] */
  s32 lmin;       /**< Minimum latency [ms] */
  s32 lmax;       /**< Maximum latency [ms] */
  s32 current;    /**< Smoothed estimate of the current latency [ms] */
} latency_t;


/** State of the UART channels
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
#define SBP_MSG_UART_STATE         0x001D
typedef struct __attribute__((packed)) {
  uart_channel_t uart_a;        /**< State of UART A */
  uart_channel_t uart_b;        /**< State of UART B */
  uart_channel_t uart_ftdi;     /**< State of UART FTDI (USB logger) */
  latency_t latency;       /**< UART communication latency */
  period_t obs_period;    /**< Observation receipt period */
} msg_uart_state_t;


/** Deprecated
 *
* Deprecated
 */
#define SBP_MSG_UART_STATE_DEPA    0x0018
typedef struct __attribute__((packed)) {
  uart_channel_t uart_a;       /**< State of UART A */
  uart_channel_t uart_b;       /**< State of UART B */
  uart_channel_t uart_ftdi;    /**< State of UART FTDI (USB logger) */
  latency_t latency;      /**< UART communication latency */
} msg_uart_state_depa_t;


/** State of the Integer Ambiguity Resolution (IAR) process
 *
 * This message reports the state of the Integer Ambiguity
 * Resolution (IAR) process, which resolves unknown integer
 * ambiguities from double-differenced carrier-phase measurements
 * from satellite observations.
 */
#define SBP_MSG_IAR_STATE          0x0019
typedef struct __attribute__((packed)) {
  u32 num_hyps;    /**< Number of integer ambiguity hypotheses remaining */
} msg_iar_state_t;


/** Mask a satellite from use in Piksi subsystems
 *
 * This message allows setting a mask to prevent a particular satellite
 * from being used in various Piksi subsystems.
 */
#define SBP_MSG_MASK_SATELLITE     0x002B
typedef struct __attribute__((packed)) {
  u8 mask;    /**< Mask of systems that should ignore this satellite. */
  sbp_gnss_signal_t sid;     /**< GNSS signal for which the mask is applied */
} msg_mask_satellite_t;


/** Deprecated
 *
* Deprecated.
 */
#define SBP_MSG_MASK_SATELLITE_DEP 0x001B
typedef struct __attribute__((packed)) {
  u8 mask;    /**< Mask of systems that should ignore this satellite. */
  gnss_signal_dep_t sid;     /**< GNSS signal for which the mask is applied */
} msg_mask_satellite_dep_t;


/** Device temperature and voltage levels
 *
 * This message contains temperature and voltage level measurements from the
 * processor's monitoring system and the RF frontend die temperature if
 * available.
 */
#define SBP_MSG_DEVICE_MONITOR     0x00B5
typedef struct __attribute__((packed)) {
  s16 dev_vin;            /**< Device V_in [V / 1000] */
  s16 cpu_vint;           /**< Processor V_int [V / 1000] */
  s16 cpu_vaux;           /**< Processor V_aux [V / 1000] */
  s16 cpu_temperature;    /**< Processor temperature [degrees C / 100] */
  s16 fe_temperature;     /**< Frontend temperature (if available) [degrees C / 100] */
} msg_device_monitor_t;


/** Execute a command (host => device)
 *
 * Request the recipient to execute an command.
 * Output will be sent in MSG_LOG messages, and the exit
 * code will be returned with MSG_COMMAND_RESP.
 */
#define SBP_MSG_COMMAND_REQ        0x00B8
typedef struct __attribute__((packed)) {
  u32 sequence;    /**< Sequence number */
  char command[0];  /**< Command line to execute */
} msg_command_req_t;


/** Exit code from executed command (device => host)
 *
 * The response to MSG_COMMAND_REQ with the return code of
 * the command.  A return code of zero indicates success.
 */
#define SBP_MSG_COMMAND_RESP       0x00B9
typedef struct __attribute__((packed)) {
  u32 sequence;    /**< Sequence number */
  s32 code;        /**< Exit code */
} msg_command_resp_t;


/** Command output
 *
 * Returns the standard output and standard error of the
 * command requested by MSG_COMMAND_REQ.
 * The sequence number can be used to filter for filtering
 * the correct command.
 */
#define SBP_MSG_COMMAND_OUTPUT     0x00BC
typedef struct __attribute__((packed)) {
  u32 sequence;    /**< Sequence number */
  char line[0];     /**< Line of standard output or standard error */
} msg_command_output_t;


/** Request state of Piksi network interfaces
 *
 * Request state of Piksi network interfaces.
 * Output will be sent in MSG_NETWORK_STATE_RESP messages
 */
#define SBP_MSG_NETWORK_STATE_REQ  0x00BA


/** State of network interface
 *
 * The state of a network interface on the Piksi.
 * Data is made to reflect output of ifaddrs struct returned by getifaddrs
 * in c.
 */
#define SBP_MSG_NETWORK_STATE_RESP 0x00BB
typedef struct __attribute__((packed)) {
  u8 ipv4_address[4];   /**< IPv4 address (all zero when unavailable) */
  u8 ipv4_mask_size;    /**< IPv4 netmask CIDR notation */
  u8 ipv6_address[16];  /**< IPv6 address (all zero when unavailable) */
  u8 ipv6_mask_size;    /**< IPv6 netmask CIDR notation */
  u32 rx_bytes;          /**< Number of Rx bytes */
  u32 tx_bytes;          /**< Number of Tx bytes */
  char interface_name[16]; /**< Interface Name */
  u32 flags;             /**< Interface flags from SIOCGIFFLAGS */
} msg_network_state_resp_t;


/** Deprecated
 *
* Deprecated.
 */
#define SBP_MSG_SPECAN_DEP         0x0050
typedef struct __attribute__((packed)) {
  u16 channel_tag;        /**< Channel ID */
  gps_time_dep_t t;                  /**< Receiver time of this observation */
  float freq_ref;           /**< Reference frequency of this packet
 [MHz] */
  float freq_step;          /**< Frequency step of points in this packet
 [MHz] */
  float amplitude_ref;      /**< Reference amplitude of this packet
 [dB] */
  float amplitude_unit;     /**< Amplitude unit value of points in this packet
 [dB] */
  u8 amplitude_value[0]; /**< Amplitude values (in the above units) of points in this packet
 */
} msg_specan_dep_t;


/** Spectrum analyzer
 *
 * Spectrum analyzer packet.
 */
#define SBP_MSG_SPECAN             0x0051
typedef struct __attribute__((packed)) {
  u16 channel_tag;        /**< Channel ID */
  sbp_gps_time_t t;                  /**< Receiver time of this observation */
  float freq_ref;           /**< Reference frequency of this packet
 [MHz] */
  float freq_step;          /**< Frequency step of points in this packet
 [MHz] */
  float amplitude_ref;      /**< Reference amplitude of this packet
 [dB] */
  float amplitude_unit;     /**< Amplitude unit value of points in this packet
 [dB] */
  u8 amplitude_value[0]; /**< Amplitude values (in the above units) of points in this packet
 */
} msg_specan_t;


/** \} */

#endif /* LIBSBP_PIKSI_MESSAGES_H */