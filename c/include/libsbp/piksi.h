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

SBP_PACK_START
#ifdef __ghs__
#pragma pack(1)
#endif


/** Legacy message to load satellite almanac (host => Piksi)
 *
 * This is a legacy message for sending and loading a satellite
 * alamanac onto the Piksi's flash memory from the host.
 */
#define SBP_MSG_ALMANAC                 0x0069
 

/** Send GPS time from host (host => Piksi)
 *
 * This message sets up timing functionality using a coarse GPS
 * time estimate sent by the host.
 */
#define SBP_MSG_SET_TIME                0x0068
 

/** Reset the device (host => Piksi)
 *
 * This message from the host resets the Piksi back into the
 * bootloader.
 */
#define SBP_MSG_RESET                   0x00B6
#define SBP_RESET_DEFAULT_SETTINGS_MASK (0x1)
#define SBP_RESET_DEFAULT_SETTINGS_SHIFT (0u)
#define SBP_RESET_DEFAULT_SETTINGS_GET(flags) \
                             (((flags) >> SBP_RESET_DEFAULT_SETTINGS_SHIFT) \
                             & SBP_RESET_DEFAULT_SETTINGS_MASK)
#define SBP_RESET_DEFAULT_SETTINGS_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_RESET_DEFAULT_SETTINGS_MASK)) \
                             << (SBP_RESET_DEFAULT_SETTINGS_SHIFT)));} while(0)
                             

#define SBP_RESET_DEFAULT_SETTINGS_PRESERVE_EXISTING_SETTINGS (0)
#define SBP_RESET_DEFAULT_SETTINGS_RESORE_DEFAULT_SETTINGS (1)

typedef struct SBP_ATTR_PACKED {
  u32 flags;    /**< Reset flags */
} msg_reset_t;
 

/** Reset the device (host => Piksi)
 *
 * This message from the host resets the Piksi back into the
 * bootloader.
 */
#define SBP_MSG_RESET_DEP               0x00B2
 

/** Legacy message for CW interference channel (Piksi => host)
 *
 * This is an unused legacy message for result reporting from the
 * CW interference channel on the SwiftNAP. This message will be
 * removed in a future release.
 */
#define SBP_MSG_CW_RESULTS              0x00C0
 

/** Legacy message for CW interference channel (host => Piksi)
 *
 * This is an unused legacy message from the host for starting
 * the CW interference channel on the SwiftNAP. This message will
 * be removed in a future release.
 */
#define SBP_MSG_CW_START                0x00C1
 

/** Reset IAR filters (host => Piksi)
 *
 * This message resets either the DGNSS Kalman filters or Integer
 * Ambiguity Resolution (IAR) process.
 */
#define SBP_MSG_RESET_FILTERS           0x0022
#define SBP_RESET_FILTERS_FILTER_OR_PROCESS_TO_RESET_MASK (0x3)
#define SBP_RESET_FILTERS_FILTER_OR_PROCESS_TO_RESET_SHIFT (0u)
#define SBP_RESET_FILTERS_FILTER_OR_PROCESS_TO_RESET_GET(flags) \
                             (((flags) >> SBP_RESET_FILTERS_FILTER_OR_PROCESS_TO_RESET_SHIFT) \
                             & SBP_RESET_FILTERS_FILTER_OR_PROCESS_TO_RESET_MASK)
#define SBP_RESET_FILTERS_FILTER_OR_PROCESS_TO_RESET_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_RESET_FILTERS_FILTER_OR_PROCESS_TO_RESET_MASK)) \
                             << (SBP_RESET_FILTERS_FILTER_OR_PROCESS_TO_RESET_SHIFT)));} while(0)
                             

#define SBP_RESET_FILTERS_FILTER_OR_PROCESS_TO_RESET_DGNSS_FILTER (0)
#define SBP_RESET_FILTERS_FILTER_OR_PROCESS_TO_RESET_IAR_PROCESS (1)
#define SBP_RESET_FILTERS_FILTER_OR_PROCESS_TO_RESET_INERTIAL_FILTER (2)

typedef struct SBP_ATTR_PACKED {
  u8 filter;    /**< Filter flags */
} msg_reset_filters_t;
 

/** Deprecated
 *
* Deprecated
 */
#define SBP_MSG_INIT_BASE_DEP           0x0023
 

/** State of an RTOS thread
 *
 * The thread usage message from the device reports real-time
 * operating system (RTOS) thread usage statistics for the named
 * thread. The reported percentage values must be normalized.
 */
#define SBP_MSG_THREAD_STATE            0x0017

typedef struct SBP_ATTR_PACKED {
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

typedef struct SBP_ATTR_PACKED {
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

typedef struct SBP_ATTR_PACKED {
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

typedef struct SBP_ATTR_PACKED {
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
#define SBP_MSG_UART_STATE              0x001D

typedef struct SBP_ATTR_PACKED {
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
#define SBP_MSG_UART_STATE_DEPA         0x0018

typedef struct SBP_ATTR_PACKED {
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
#define SBP_MSG_IAR_STATE               0x0019

typedef struct SBP_ATTR_PACKED {
  u32 num_hyps;    /**< Number of integer ambiguity hypotheses remaining */
} msg_iar_state_t;
 

/** Mask a satellite from use in Piksi subsystems
 *
 * This message allows setting a mask to prevent a particular satellite
 * from being used in various Piksi subsystems.
 */
#define SBP_MSG_MASK_SATELLITE          0x002B
#define SBP_MASK_SATELLITE_TRACKING_CHANNELS_MASK (0x1)
#define SBP_MASK_SATELLITE_TRACKING_CHANNELS_SHIFT (1u)
#define SBP_MASK_SATELLITE_TRACKING_CHANNELS_GET(flags) \
                             (((flags) >> SBP_MASK_SATELLITE_TRACKING_CHANNELS_SHIFT) \
                             & SBP_MASK_SATELLITE_TRACKING_CHANNELS_MASK)
#define SBP_MASK_SATELLITE_TRACKING_CHANNELS_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_MASK_SATELLITE_TRACKING_CHANNELS_MASK)) \
                             << (SBP_MASK_SATELLITE_TRACKING_CHANNELS_SHIFT)));} while(0)
                             

#define SBP_MASK_SATELLITE_TRACKING_CHANNELS_ENABLED (0)
#define SBP_MASK_SATELLITE_TRACKING_CHANNELS_DROP_THIS_PRN_IF_CURRENTLY_TRACKING (1)
#define SBP_MASK_SATELLITE_ACQUISITION_CHANNEL_MASK (0x1)
#define SBP_MASK_SATELLITE_ACQUISITION_CHANNEL_SHIFT (0u)
#define SBP_MASK_SATELLITE_ACQUISITION_CHANNEL_GET(flags) \
                             (((flags) >> SBP_MASK_SATELLITE_ACQUISITION_CHANNEL_SHIFT) \
                             & SBP_MASK_SATELLITE_ACQUISITION_CHANNEL_MASK)
#define SBP_MASK_SATELLITE_ACQUISITION_CHANNEL_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_MASK_SATELLITE_ACQUISITION_CHANNEL_MASK)) \
                             << (SBP_MASK_SATELLITE_ACQUISITION_CHANNEL_SHIFT)));} while(0)
                             

#define SBP_MASK_SATELLITE_ACQUISITION_CHANNEL_ENABLED (0)
#define SBP_MASK_SATELLITE_ACQUISITION_CHANNEL_SKIP_THIS_SATELLITE_ON_FUTURE_ACQUISITIONS (1)

typedef struct SBP_ATTR_PACKED {
  u8 mask;    /**< Mask of systems that should ignore this satellite. */
  sbp_gnss_signal_t sid;     /**< GNSS signal for which the mask is applied */
} msg_mask_satellite_t;
 

/** Deprecated
 *
* Deprecated.
 */
#define SBP_MSG_MASK_SATELLITE_DEP      0x001B
#define SBP_MASK_SATELLITE_DEP_TRACKING_CHANNELS_MASK (0x1)
#define SBP_MASK_SATELLITE_DEP_TRACKING_CHANNELS_SHIFT (1u)
#define SBP_MASK_SATELLITE_DEP_TRACKING_CHANNELS_GET(flags) \
                             (((flags) >> SBP_MASK_SATELLITE_DEP_TRACKING_CHANNELS_SHIFT) \
                             & SBP_MASK_SATELLITE_DEP_TRACKING_CHANNELS_MASK)
#define SBP_MASK_SATELLITE_DEP_TRACKING_CHANNELS_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_MASK_SATELLITE_DEP_TRACKING_CHANNELS_MASK)) \
                             << (SBP_MASK_SATELLITE_DEP_TRACKING_CHANNELS_SHIFT)));} while(0)
                             

#define SBP_MASK_SATELLITE_DEP_TRACKING_CHANNELS_ENABLED (0)
#define SBP_MASK_SATELLITE_DEP_TRACKING_CHANNELS_DROP_THIS_PRN_IF_CURRENTLY_TRACKING (1)
#define SBP_MASK_SATELLITE_DEP_ACQUISITION_CHANNEL_MASK (0x1)
#define SBP_MASK_SATELLITE_DEP_ACQUISITION_CHANNEL_SHIFT (0u)
#define SBP_MASK_SATELLITE_DEP_ACQUISITION_CHANNEL_GET(flags) \
                             (((flags) >> SBP_MASK_SATELLITE_DEP_ACQUISITION_CHANNEL_SHIFT) \
                             & SBP_MASK_SATELLITE_DEP_ACQUISITION_CHANNEL_MASK)
#define SBP_MASK_SATELLITE_DEP_ACQUISITION_CHANNEL_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_MASK_SATELLITE_DEP_ACQUISITION_CHANNEL_MASK)) \
                             << (SBP_MASK_SATELLITE_DEP_ACQUISITION_CHANNEL_SHIFT)));} while(0)
                             

#define SBP_MASK_SATELLITE_DEP_ACQUISITION_CHANNEL_ENABLED (0)
#define SBP_MASK_SATELLITE_DEP_ACQUISITION_CHANNEL_SKIP_THIS_SATELLITE_ON_FUTURE_ACQUISITIONS (1)

typedef struct SBP_ATTR_PACKED {
  u8 mask;    /**< Mask of systems that should ignore this satellite. */
  gnss_signal_dep_t sid;     /**< GNSS signal for which the mask is applied */
} msg_mask_satellite_dep_t;
 

/** Device temperature and voltage levels
 *
 * This message contains temperature and voltage level measurements from the
 * processor's monitoring system and the RF frontend die temperature if
 * available.
 */
#define SBP_MSG_DEVICE_MONITOR          0x00B5

typedef struct SBP_ATTR_PACKED {
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
#define SBP_MSG_COMMAND_REQ             0x00B8

typedef struct SBP_ATTR_PACKED {
  u32 sequence;    /**< Sequence number */
#ifdef SBP_ENABLE_VARIABLE_SIZED_ARRAYS
  char command[0];  /**< Command line to execute */
#endif
} msg_command_req_t;
#define MSG_COMMAND_REQ_T_GET_COMMAND_PTR(msg) (( char *)(msg+1))
#define MSG_COMMAND_REQ_T_GET_COMMAND_CPTR(msg) ((const char *)(msg+1))
 

/** Exit code from executed command (device => host)
 *
 * The response to MSG_COMMAND_REQ with the return code of
 * the command.  A return code of zero indicates success.
 */
#define SBP_MSG_COMMAND_RESP            0x00B9

typedef struct SBP_ATTR_PACKED {
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
#define SBP_MSG_COMMAND_OUTPUT          0x00BC

typedef struct SBP_ATTR_PACKED {
  u32 sequence;    /**< Sequence number */
#ifdef SBP_ENABLE_VARIABLE_SIZED_ARRAYS
  char line[0];     /**< Line of standard output or standard error */
#endif
} msg_command_output_t;
#define MSG_COMMAND_OUTPUT_T_GET_LINE_PTR(msg) (( char *)(msg+1))
#define MSG_COMMAND_OUTPUT_T_GET_LINE_CPTR(msg) ((const char *)(msg+1))
 

/** Request state of Piksi network interfaces
 *
 * Request state of Piksi network interfaces.
 * Output will be sent in MSG_NETWORK_STATE_RESP messages
 */
#define SBP_MSG_NETWORK_STATE_REQ       0x00BA
 

/** State of network interface
 *
 * The state of a network interface on the Piksi.
 * Data is made to reflect output of ifaddrs struct returned by getifaddrs
 * in c.
 */
#define SBP_MSG_NETWORK_STATE_RESP      0x00BB
#define SBP_NETWORK_STATE_RESP_IFF_MULTICAST__SUPPORTS_MULTICAST_MASK (0x1)
#define SBP_NETWORK_STATE_RESP_IFF_MULTICAST__SUPPORTS_MULTICAST_SHIFT (15u)
#define SBP_NETWORK_STATE_RESP_IFF_MULTICAST__SUPPORTS_MULTICAST_GET(flags) \
                             (((flags) >> SBP_NETWORK_STATE_RESP_IFF_MULTICAST__SUPPORTS_MULTICAST_SHIFT) \
                             & SBP_NETWORK_STATE_RESP_IFF_MULTICAST__SUPPORTS_MULTICAST_MASK)
#define SBP_NETWORK_STATE_RESP_IFF_MULTICAST__SUPPORTS_MULTICAST_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_NETWORK_STATE_RESP_IFF_MULTICAST__SUPPORTS_MULTICAST_MASK)) \
                             << (SBP_NETWORK_STATE_RESP_IFF_MULTICAST__SUPPORTS_MULTICAST_SHIFT)));} while(0)
                             

#define SBP_NETWORK_STATE_RESP_IFF_LINK2__PER_LINK_LAYER_DEFINED_BIT_MASK (0x1)
#define SBP_NETWORK_STATE_RESP_IFF_LINK2__PER_LINK_LAYER_DEFINED_BIT_SHIFT (14u)
#define SBP_NETWORK_STATE_RESP_IFF_LINK2__PER_LINK_LAYER_DEFINED_BIT_GET(flags) \
                             (((flags) >> SBP_NETWORK_STATE_RESP_IFF_LINK2__PER_LINK_LAYER_DEFINED_BIT_SHIFT) \
                             & SBP_NETWORK_STATE_RESP_IFF_LINK2__PER_LINK_LAYER_DEFINED_BIT_MASK)
#define SBP_NETWORK_STATE_RESP_IFF_LINK2__PER_LINK_LAYER_DEFINED_BIT_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_NETWORK_STATE_RESP_IFF_LINK2__PER_LINK_LAYER_DEFINED_BIT_MASK)) \
                             << (SBP_NETWORK_STATE_RESP_IFF_LINK2__PER_LINK_LAYER_DEFINED_BIT_SHIFT)));} while(0)
                             

#define SBP_NETWORK_STATE_RESP_IFF_LINK1__PER_LINK_LAYER_DEFINED_BIT_MASK (0x1)
#define SBP_NETWORK_STATE_RESP_IFF_LINK1__PER_LINK_LAYER_DEFINED_BIT_SHIFT (13u)
#define SBP_NETWORK_STATE_RESP_IFF_LINK1__PER_LINK_LAYER_DEFINED_BIT_GET(flags) \
                             (((flags) >> SBP_NETWORK_STATE_RESP_IFF_LINK1__PER_LINK_LAYER_DEFINED_BIT_SHIFT) \
                             & SBP_NETWORK_STATE_RESP_IFF_LINK1__PER_LINK_LAYER_DEFINED_BIT_MASK)
#define SBP_NETWORK_STATE_RESP_IFF_LINK1__PER_LINK_LAYER_DEFINED_BIT_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_NETWORK_STATE_RESP_IFF_LINK1__PER_LINK_LAYER_DEFINED_BIT_MASK)) \
                             << (SBP_NETWORK_STATE_RESP_IFF_LINK1__PER_LINK_LAYER_DEFINED_BIT_SHIFT)));} while(0)
                             

#define SBP_NETWORK_STATE_RESP_IFF_LINK0__PER_LINK_LAYER_DEFINED_BIT_MASK (0x1)
#define SBP_NETWORK_STATE_RESP_IFF_LINK0__PER_LINK_LAYER_DEFINED_BIT_SHIFT (12u)
#define SBP_NETWORK_STATE_RESP_IFF_LINK0__PER_LINK_LAYER_DEFINED_BIT_GET(flags) \
                             (((flags) >> SBP_NETWORK_STATE_RESP_IFF_LINK0__PER_LINK_LAYER_DEFINED_BIT_SHIFT) \
                             & SBP_NETWORK_STATE_RESP_IFF_LINK0__PER_LINK_LAYER_DEFINED_BIT_MASK)
#define SBP_NETWORK_STATE_RESP_IFF_LINK0__PER_LINK_LAYER_DEFINED_BIT_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_NETWORK_STATE_RESP_IFF_LINK0__PER_LINK_LAYER_DEFINED_BIT_MASK)) \
                             << (SBP_NETWORK_STATE_RESP_IFF_LINK0__PER_LINK_LAYER_DEFINED_BIT_SHIFT)));} while(0)
                             

#define SBP_NETWORK_STATE_RESP_IFF_SIMPLEX__CANT_HEAR_OWN_TRANSMISSIONS_MASK (0x1)
#define SBP_NETWORK_STATE_RESP_IFF_SIMPLEX__CANT_HEAR_OWN_TRANSMISSIONS_SHIFT (11u)
#define SBP_NETWORK_STATE_RESP_IFF_SIMPLEX__CANT_HEAR_OWN_TRANSMISSIONS_GET(flags) \
                             (((flags) >> SBP_NETWORK_STATE_RESP_IFF_SIMPLEX__CANT_HEAR_OWN_TRANSMISSIONS_SHIFT) \
                             & SBP_NETWORK_STATE_RESP_IFF_SIMPLEX__CANT_HEAR_OWN_TRANSMISSIONS_MASK)
#define SBP_NETWORK_STATE_RESP_IFF_SIMPLEX__CANT_HEAR_OWN_TRANSMISSIONS_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_NETWORK_STATE_RESP_IFF_SIMPLEX__CANT_HEAR_OWN_TRANSMISSIONS_MASK)) \
                             << (SBP_NETWORK_STATE_RESP_IFF_SIMPLEX__CANT_HEAR_OWN_TRANSMISSIONS_SHIFT)));} while(0)
                             

#define SBP_NETWORK_STATE_RESP_IFF_OACTIVE__TRANSMISSION_IN_PROGRESS_MASK (0x1)
#define SBP_NETWORK_STATE_RESP_IFF_OACTIVE__TRANSMISSION_IN_PROGRESS_SHIFT (10u)
#define SBP_NETWORK_STATE_RESP_IFF_OACTIVE__TRANSMISSION_IN_PROGRESS_GET(flags) \
                             (((flags) >> SBP_NETWORK_STATE_RESP_IFF_OACTIVE__TRANSMISSION_IN_PROGRESS_SHIFT) \
                             & SBP_NETWORK_STATE_RESP_IFF_OACTIVE__TRANSMISSION_IN_PROGRESS_MASK)
#define SBP_NETWORK_STATE_RESP_IFF_OACTIVE__TRANSMISSION_IN_PROGRESS_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_NETWORK_STATE_RESP_IFF_OACTIVE__TRANSMISSION_IN_PROGRESS_MASK)) \
                             << (SBP_NETWORK_STATE_RESP_IFF_OACTIVE__TRANSMISSION_IN_PROGRESS_SHIFT)));} while(0)
                             

#define SBP_NETWORK_STATE_RESP_IFF_ALLMULTI__RECEIVE_ALL_MULTICAST_PACKETS_MASK (0x1)
#define SBP_NETWORK_STATE_RESP_IFF_ALLMULTI__RECEIVE_ALL_MULTICAST_PACKETS_SHIFT (9u)
#define SBP_NETWORK_STATE_RESP_IFF_ALLMULTI__RECEIVE_ALL_MULTICAST_PACKETS_GET(flags) \
                             (((flags) >> SBP_NETWORK_STATE_RESP_IFF_ALLMULTI__RECEIVE_ALL_MULTICAST_PACKETS_SHIFT) \
                             & SBP_NETWORK_STATE_RESP_IFF_ALLMULTI__RECEIVE_ALL_MULTICAST_PACKETS_MASK)
#define SBP_NETWORK_STATE_RESP_IFF_ALLMULTI__RECEIVE_ALL_MULTICAST_PACKETS_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_NETWORK_STATE_RESP_IFF_ALLMULTI__RECEIVE_ALL_MULTICAST_PACKETS_MASK)) \
                             << (SBP_NETWORK_STATE_RESP_IFF_ALLMULTI__RECEIVE_ALL_MULTICAST_PACKETS_SHIFT)));} while(0)
                             

#define SBP_NETWORK_STATE_RESP_IFF_PROMISC__RECEIVE_ALL_PACKETS_MASK (0x1)
#define SBP_NETWORK_STATE_RESP_IFF_PROMISC__RECEIVE_ALL_PACKETS_SHIFT (8u)
#define SBP_NETWORK_STATE_RESP_IFF_PROMISC__RECEIVE_ALL_PACKETS_GET(flags) \
                             (((flags) >> SBP_NETWORK_STATE_RESP_IFF_PROMISC__RECEIVE_ALL_PACKETS_SHIFT) \
                             & SBP_NETWORK_STATE_RESP_IFF_PROMISC__RECEIVE_ALL_PACKETS_MASK)
#define SBP_NETWORK_STATE_RESP_IFF_PROMISC__RECEIVE_ALL_PACKETS_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_NETWORK_STATE_RESP_IFF_PROMISC__RECEIVE_ALL_PACKETS_MASK)) \
                             << (SBP_NETWORK_STATE_RESP_IFF_PROMISC__RECEIVE_ALL_PACKETS_SHIFT)));} while(0)
                             

#define SBP_NETWORK_STATE_RESP_IFF_NOARP__NO_ADDRESS_RESOLUTION_PROTOCOL_MASK (0x1)
#define SBP_NETWORK_STATE_RESP_IFF_NOARP__NO_ADDRESS_RESOLUTION_PROTOCOL_SHIFT (7u)
#define SBP_NETWORK_STATE_RESP_IFF_NOARP__NO_ADDRESS_RESOLUTION_PROTOCOL_GET(flags) \
                             (((flags) >> SBP_NETWORK_STATE_RESP_IFF_NOARP__NO_ADDRESS_RESOLUTION_PROTOCOL_SHIFT) \
                             & SBP_NETWORK_STATE_RESP_IFF_NOARP__NO_ADDRESS_RESOLUTION_PROTOCOL_MASK)
#define SBP_NETWORK_STATE_RESP_IFF_NOARP__NO_ADDRESS_RESOLUTION_PROTOCOL_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_NETWORK_STATE_RESP_IFF_NOARP__NO_ADDRESS_RESOLUTION_PROTOCOL_MASK)) \
                             << (SBP_NETWORK_STATE_RESP_IFF_NOARP__NO_ADDRESS_RESOLUTION_PROTOCOL_SHIFT)));} while(0)
                             

#define SBP_NETWORK_STATE_RESP_IFF_RUNNING__RESOURCES_ALLOCATED_MASK (0x1)
#define SBP_NETWORK_STATE_RESP_IFF_RUNNING__RESOURCES_ALLOCATED_SHIFT (6u)
#define SBP_NETWORK_STATE_RESP_IFF_RUNNING__RESOURCES_ALLOCATED_GET(flags) \
                             (((flags) >> SBP_NETWORK_STATE_RESP_IFF_RUNNING__RESOURCES_ALLOCATED_SHIFT) \
                             & SBP_NETWORK_STATE_RESP_IFF_RUNNING__RESOURCES_ALLOCATED_MASK)
#define SBP_NETWORK_STATE_RESP_IFF_RUNNING__RESOURCES_ALLOCATED_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_NETWORK_STATE_RESP_IFF_RUNNING__RESOURCES_ALLOCATED_MASK)) \
                             << (SBP_NETWORK_STATE_RESP_IFF_RUNNING__RESOURCES_ALLOCATED_SHIFT)));} while(0)
                             

#define SBP_NETWORK_STATE_RESP_IFF_NOTRAILERS__AVOID_USE_OF_TRAILERS_MASK (0x1)
#define SBP_NETWORK_STATE_RESP_IFF_NOTRAILERS__AVOID_USE_OF_TRAILERS_SHIFT (5u)
#define SBP_NETWORK_STATE_RESP_IFF_NOTRAILERS__AVOID_USE_OF_TRAILERS_GET(flags) \
                             (((flags) >> SBP_NETWORK_STATE_RESP_IFF_NOTRAILERS__AVOID_USE_OF_TRAILERS_SHIFT) \
                             & SBP_NETWORK_STATE_RESP_IFF_NOTRAILERS__AVOID_USE_OF_TRAILERS_MASK)
#define SBP_NETWORK_STATE_RESP_IFF_NOTRAILERS__AVOID_USE_OF_TRAILERS_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_NETWORK_STATE_RESP_IFF_NOTRAILERS__AVOID_USE_OF_TRAILERS_MASK)) \
                             << (SBP_NETWORK_STATE_RESP_IFF_NOTRAILERS__AVOID_USE_OF_TRAILERS_SHIFT)));} while(0)
                             

#define SBP_NETWORK_STATE_RESP_IFF_POINTOPOINT__INTERFACE_IS_POINTTOPOINT_LINK_MASK (0x1)
#define SBP_NETWORK_STATE_RESP_IFF_POINTOPOINT__INTERFACE_IS_POINTTOPOINT_LINK_SHIFT (4u)
#define SBP_NETWORK_STATE_RESP_IFF_POINTOPOINT__INTERFACE_IS_POINTTOPOINT_LINK_GET(flags) \
                             (((flags) >> SBP_NETWORK_STATE_RESP_IFF_POINTOPOINT__INTERFACE_IS_POINTTOPOINT_LINK_SHIFT) \
                             & SBP_NETWORK_STATE_RESP_IFF_POINTOPOINT__INTERFACE_IS_POINTTOPOINT_LINK_MASK)
#define SBP_NETWORK_STATE_RESP_IFF_POINTOPOINT__INTERFACE_IS_POINTTOPOINT_LINK_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_NETWORK_STATE_RESP_IFF_POINTOPOINT__INTERFACE_IS_POINTTOPOINT_LINK_MASK)) \
                             << (SBP_NETWORK_STATE_RESP_IFF_POINTOPOINT__INTERFACE_IS_POINTTOPOINT_LINK_SHIFT)));} while(0)
                             

#define SBP_NETWORK_STATE_RESP_IFF_LOOPBACK__IS_A_LOOPBACK_NET_MASK (0x1)
#define SBP_NETWORK_STATE_RESP_IFF_LOOPBACK__IS_A_LOOPBACK_NET_SHIFT (3u)
#define SBP_NETWORK_STATE_RESP_IFF_LOOPBACK__IS_A_LOOPBACK_NET_GET(flags) \
                             (((flags) >> SBP_NETWORK_STATE_RESP_IFF_LOOPBACK__IS_A_LOOPBACK_NET_SHIFT) \
                             & SBP_NETWORK_STATE_RESP_IFF_LOOPBACK__IS_A_LOOPBACK_NET_MASK)
#define SBP_NETWORK_STATE_RESP_IFF_LOOPBACK__IS_A_LOOPBACK_NET_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_NETWORK_STATE_RESP_IFF_LOOPBACK__IS_A_LOOPBACK_NET_MASK)) \
                             << (SBP_NETWORK_STATE_RESP_IFF_LOOPBACK__IS_A_LOOPBACK_NET_SHIFT)));} while(0)
                             

#define SBP_NETWORK_STATE_RESP_IFF_DEBUG__BROADCAST_ADDRESS_VALID_MASK (0x1)
#define SBP_NETWORK_STATE_RESP_IFF_DEBUG__BROADCAST_ADDRESS_VALID_SHIFT (2u)
#define SBP_NETWORK_STATE_RESP_IFF_DEBUG__BROADCAST_ADDRESS_VALID_GET(flags) \
                             (((flags) >> SBP_NETWORK_STATE_RESP_IFF_DEBUG__BROADCAST_ADDRESS_VALID_SHIFT) \
                             & SBP_NETWORK_STATE_RESP_IFF_DEBUG__BROADCAST_ADDRESS_VALID_MASK)
#define SBP_NETWORK_STATE_RESP_IFF_DEBUG__BROADCAST_ADDRESS_VALID_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_NETWORK_STATE_RESP_IFF_DEBUG__BROADCAST_ADDRESS_VALID_MASK)) \
                             << (SBP_NETWORK_STATE_RESP_IFF_DEBUG__BROADCAST_ADDRESS_VALID_SHIFT)));} while(0)
                             

#define SBP_NETWORK_STATE_RESP_IFF_BROADCAST__BROADCAST_ADDRESS_VALID_MASK (0x1)
#define SBP_NETWORK_STATE_RESP_IFF_BROADCAST__BROADCAST_ADDRESS_VALID_SHIFT (1u)
#define SBP_NETWORK_STATE_RESP_IFF_BROADCAST__BROADCAST_ADDRESS_VALID_GET(flags) \
                             (((flags) >> SBP_NETWORK_STATE_RESP_IFF_BROADCAST__BROADCAST_ADDRESS_VALID_SHIFT) \
                             & SBP_NETWORK_STATE_RESP_IFF_BROADCAST__BROADCAST_ADDRESS_VALID_MASK)
#define SBP_NETWORK_STATE_RESP_IFF_BROADCAST__BROADCAST_ADDRESS_VALID_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_NETWORK_STATE_RESP_IFF_BROADCAST__BROADCAST_ADDRESS_VALID_MASK)) \
                             << (SBP_NETWORK_STATE_RESP_IFF_BROADCAST__BROADCAST_ADDRESS_VALID_SHIFT)));} while(0)
                             

#define SBP_NETWORK_STATE_RESP_IFF_UP__INTERFACE_IS_UP_MASK (0x1)
#define SBP_NETWORK_STATE_RESP_IFF_UP__INTERFACE_IS_UP_SHIFT (0u)
#define SBP_NETWORK_STATE_RESP_IFF_UP__INTERFACE_IS_UP_GET(flags) \
                             (((flags) >> SBP_NETWORK_STATE_RESP_IFF_UP__INTERFACE_IS_UP_SHIFT) \
                             & SBP_NETWORK_STATE_RESP_IFF_UP__INTERFACE_IS_UP_MASK)
#define SBP_NETWORK_STATE_RESP_IFF_UP__INTERFACE_IS_UP_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_NETWORK_STATE_RESP_IFF_UP__INTERFACE_IS_UP_MASK)) \
                             << (SBP_NETWORK_STATE_RESP_IFF_UP__INTERFACE_IS_UP_SHIFT)));} while(0)
                             


typedef struct SBP_ATTR_PACKED {
  u8 ipv4_address[4];   /**< IPv4 address (all zero when unavailable) */
  u8 ipv4_mask_size;    /**< IPv4 netmask CIDR notation */
  u8 ipv6_address[16];  /**< IPv6 address (all zero when unavailable) */
  u8 ipv6_mask_size;    /**< IPv6 netmask CIDR notation */
  u32 rx_bytes;          /**< Number of Rx bytes */
  u32 tx_bytes;          /**< Number of Tx bytes */
  char interface_name[16]; /**< Interface Name */
  u32 flags;             /**< Interface flags from SIOCGIFFLAGS */
} msg_network_state_resp_t;
 

/** Bandwidth usage measurement for a single interface.
 *
 * The bandwidth usage for each interface can be reported
 * within this struct and utilize multiple fields to fully
 * specify the type of traffic that is being tracked. As
 * either the interval of collection or the collection time
 * may vary, both a timestamp and period field is provided,
 * though may not necessarily be populated with a value. 
 */

typedef struct SBP_ATTR_PACKED {
  u64 duration;          /**< Duration over which the measurement was collected [ms] */
  u64 total_bytes;       /**< Number of bytes handled in total within period */
  u32 rx_bytes;          /**< Number of bytes transmitted within period */
  u32 tx_bytes;          /**< Number of bytes received within period */
  char interface_name[16]; /**< Interface Name */
} network_usage_t;
 

/** Bandwidth usage reporting message
 *
 * The bandwidth usage, a list of usage by interface. 
 */
#define SBP_MSG_NETWORK_BANDWIDTH_USAGE 0x00BD
#ifdef SBP_ENABLE_VARIABLE_SIZED_ARRAYS

typedef struct SBP_ATTR_PACKED {
  network_usage_t interfaces[0]; /**< Usage measurement array */
} msg_network_bandwidth_usage_t;
#endif
 

/** Cell modem information update message
 *
 * If a cell modem is present on a piksi device, this message
 * will be send periodically to update the host on the status
 * of the modem and its various parameters.
 */
#define SBP_MSG_CELL_MODEM_STATUS       0x00BE

typedef struct SBP_ATTR_PACKED {
  s8 signal_strength;      /**< Received cell signal strength in dBm, zero translates to unknown [dBm] */
  float signal_error_rate;    /**< BER as reported by the modem, zero translates to unknown */
#ifdef SBP_ENABLE_VARIABLE_SIZED_ARRAYS
  u8 reserved[0];          /**< Unspecified data TBD for this schema */
#endif
} msg_cell_modem_status_t;
#define MSG_CELL_MODEM_STATUS_T_GET_RESERVED_PTR(msg) (( u8 *)(msg+1))
#define MSG_CELL_MODEM_STATUS_T_GET_RESERVED_CPTR(msg) ((const u8 *)(msg+1))
 

/** Deprecated
 *
* Deprecated.
 */
#define SBP_MSG_SPECAN_DEP              0x0050

typedef struct SBP_ATTR_PACKED {
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
#ifdef SBP_ENABLE_VARIABLE_SIZED_ARRAYS
  u8 amplitude_value[0]; /**< Amplitude values (in the above units) of points in this packet
 */
#endif
} msg_specan_dep_t;
#define MSG_SPECAN_DEP_T_GET_AMPLITUDE_VALUE_PTR(msg) (( u8 *)(msg+1))
#define MSG_SPECAN_DEP_T_GET_AMPLITUDE_VALUE_CPTR(msg) ((const u8 *)(msg+1))
 

/** Spectrum analyzer
 *
 * Spectrum analyzer packet.
 */
#define SBP_MSG_SPECAN                  0x0051

typedef struct SBP_ATTR_PACKED {
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
#ifdef SBP_ENABLE_VARIABLE_SIZED_ARRAYS
  u8 amplitude_value[0]; /**< Amplitude values (in the above units) of points in this packet
 */
#endif
} msg_specan_t;
#define MSG_SPECAN_T_GET_AMPLITUDE_VALUE_PTR(msg) (( u8 *)(msg+1))
#define MSG_SPECAN_T_GET_AMPLITUDE_VALUE_CPTR(msg) ((const u8 *)(msg+1))
 

/** RF AGC status
 *
 * This message describes the gain of each channel in the receiver frontend. Each 
 * gain is encoded as a non-dimensional percentage relative to the maximum range  
 * possible for the gain stage of the frontend. By convention, each gain array 
 * has 8 entries and the index of the array corresponding to the index of the rf channel 
 * in the frontend. A gain of 127 percent encodes that rf channel is not present in the hardware.
 * A negative value implies an error for the particular gain stage as reported by the frontend.
 */
#define SBP_MSG_FRONT_END_GAIN          0x00BF

typedef struct SBP_ATTR_PACKED {
  s8 rf_gain[8]; /**< RF gain for each frontend channel [percent] */
  s8 if_gain[8]; /**< Intermediate frequency gain for each frontend channel [percent] */
} msg_front_end_gain_t;
 

/** \} */
static inline void static_asserts_for_module_MSG_ALMANAC(void) {
}

static inline void static_asserts_for_module_MSG_SET_TIME(void) {
}

static inline void static_asserts_for_module_MSG_RESET(void) {
#ifdef __cplusplus
static_assert(offsetof(msg_reset_t, flags ) == 0, "Offset of flags in msg_reset_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_reset_t, flags ) == 0, offset_of_flags_in_msg_reset_t_is_incorrect)
#endif
}

static inline void static_asserts_for_module_MSG_RESET_DEP(void) {
}

static inline void static_asserts_for_module_MSG_CW_RESULTS(void) {
}

static inline void static_asserts_for_module_MSG_CW_START(void) {
}

static inline void static_asserts_for_module_MSG_RESET_FILTERS(void) {
#ifdef __cplusplus
static_assert(offsetof(msg_reset_filters_t, filter ) == 0, "Offset of filter in msg_reset_filters_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_reset_filters_t, filter ) == 0, offset_of_filter_in_msg_reset_filters_t_is_incorrect)
#endif
}

static inline void static_asserts_for_module_MSG_INIT_BASE_DEP(void) {
}

static inline void static_asserts_for_module_MSG_THREAD_STATE(void) {
#ifdef __cplusplus
static_assert(offsetof(msg_thread_state_t, name ) == 0, "Offset of name in msg_thread_state_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_thread_state_t, name ) == 0, offset_of_name_in_msg_thread_state_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_thread_state_t, cpu ) == 0 + (sizeof(char) * 20), "Offset of cpu in msg_thread_state_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_thread_state_t, cpu ) == 0 + (sizeof(char) * 20), offset_of_cpu_in_msg_thread_state_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_thread_state_t, stack_free ) == 0 + (sizeof(char) * 20) + sizeof(u16), "Offset of stack_free in msg_thread_state_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_thread_state_t, stack_free ) == 0 + (sizeof(char) * 20) + sizeof(u16), offset_of_stack_free_in_msg_thread_state_t_is_incorrect)
#endif
}

static inline void static_asserts_for_module_UARTChannel(void) {
#ifdef __cplusplus
static_assert(offsetof(uart_channel_t, tx_throughput ) == 0, "Offset of tx_throughput in uart_channel_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(uart_channel_t, tx_throughput ) == 0, offset_of_tx_throughput_in_uart_channel_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(uart_channel_t, rx_throughput ) == 0 + sizeof(float), "Offset of rx_throughput in uart_channel_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(uart_channel_t, rx_throughput ) == 0 + sizeof(float), offset_of_rx_throughput_in_uart_channel_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(uart_channel_t, crc_error_count ) == 0 + sizeof(float) + sizeof(float), "Offset of crc_error_count in uart_channel_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(uart_channel_t, crc_error_count ) == 0 + sizeof(float) + sizeof(float), offset_of_crc_error_count_in_uart_channel_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(uart_channel_t, io_error_count ) == 0 + sizeof(float) + sizeof(float) + sizeof(u16), "Offset of io_error_count in uart_channel_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(uart_channel_t, io_error_count ) == 0 + sizeof(float) + sizeof(float) + sizeof(u16), offset_of_io_error_count_in_uart_channel_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(uart_channel_t, tx_buffer_level ) == 0 + sizeof(float) + sizeof(float) + sizeof(u16) + sizeof(u16), "Offset of tx_buffer_level in uart_channel_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(uart_channel_t, tx_buffer_level ) == 0 + sizeof(float) + sizeof(float) + sizeof(u16) + sizeof(u16), offset_of_tx_buffer_level_in_uart_channel_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(uart_channel_t, rx_buffer_level ) == 0 + sizeof(float) + sizeof(float) + sizeof(u16) + sizeof(u16) + sizeof(u8), "Offset of rx_buffer_level in uart_channel_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(uart_channel_t, rx_buffer_level ) == 0 + sizeof(float) + sizeof(float) + sizeof(u16) + sizeof(u16) + sizeof(u8), offset_of_rx_buffer_level_in_uart_channel_t_is_incorrect)
#endif
}

static inline void static_asserts_for_module_Period(void) {
#ifdef __cplusplus
static_assert(offsetof(period_t, avg ) == 0, "Offset of avg in period_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(period_t, avg ) == 0, offset_of_avg_in_period_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(period_t, pmin ) == 0 + sizeof(s32), "Offset of pmin in period_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(period_t, pmin ) == 0 + sizeof(s32), offset_of_pmin_in_period_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(period_t, pmax ) == 0 + sizeof(s32) + sizeof(s32), "Offset of pmax in period_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(period_t, pmax ) == 0 + sizeof(s32) + sizeof(s32), offset_of_pmax_in_period_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(period_t, current ) == 0 + sizeof(s32) + sizeof(s32) + sizeof(s32), "Offset of current in period_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(period_t, current ) == 0 + sizeof(s32) + sizeof(s32) + sizeof(s32), offset_of_current_in_period_t_is_incorrect)
#endif
}

static inline void static_asserts_for_module_Latency(void) {
#ifdef __cplusplus
static_assert(offsetof(latency_t, avg ) == 0, "Offset of avg in latency_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(latency_t, avg ) == 0, offset_of_avg_in_latency_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(latency_t, lmin ) == 0 + sizeof(s32), "Offset of lmin in latency_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(latency_t, lmin ) == 0 + sizeof(s32), offset_of_lmin_in_latency_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(latency_t, lmax ) == 0 + sizeof(s32) + sizeof(s32), "Offset of lmax in latency_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(latency_t, lmax ) == 0 + sizeof(s32) + sizeof(s32), offset_of_lmax_in_latency_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(latency_t, current ) == 0 + sizeof(s32) + sizeof(s32) + sizeof(s32), "Offset of current in latency_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(latency_t, current ) == 0 + sizeof(s32) + sizeof(s32) + sizeof(s32), offset_of_current_in_latency_t_is_incorrect)
#endif
}

static inline void static_asserts_for_module_MSG_UART_STATE(void) {
#ifdef __cplusplus
static_assert(offsetof(msg_uart_state_t, uart_a ) == 0, "Offset of uart_a in msg_uart_state_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_uart_state_t, uart_a ) == 0, offset_of_uart_a_in_msg_uart_state_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_uart_state_t, uart_b ) == 0 + sizeof(uart_channel_t), "Offset of uart_b in msg_uart_state_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_uart_state_t, uart_b ) == 0 + sizeof(uart_channel_t), offset_of_uart_b_in_msg_uart_state_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_uart_state_t, uart_ftdi ) == 0 + sizeof(uart_channel_t) + sizeof(uart_channel_t), "Offset of uart_ftdi in msg_uart_state_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_uart_state_t, uart_ftdi ) == 0 + sizeof(uart_channel_t) + sizeof(uart_channel_t), offset_of_uart_ftdi_in_msg_uart_state_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_uart_state_t, latency ) == 0 + sizeof(uart_channel_t) + sizeof(uart_channel_t) + sizeof(uart_channel_t), "Offset of latency in msg_uart_state_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_uart_state_t, latency ) == 0 + sizeof(uart_channel_t) + sizeof(uart_channel_t) + sizeof(uart_channel_t), offset_of_latency_in_msg_uart_state_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_uart_state_t, obs_period ) == 0 + sizeof(uart_channel_t) + sizeof(uart_channel_t) + sizeof(uart_channel_t) + sizeof(latency_t), "Offset of obs_period in msg_uart_state_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_uart_state_t, obs_period ) == 0 + sizeof(uart_channel_t) + sizeof(uart_channel_t) + sizeof(uart_channel_t) + sizeof(latency_t), offset_of_obs_period_in_msg_uart_state_t_is_incorrect)
#endif
}

static inline void static_asserts_for_module_MSG_UART_STATE_DEPA(void) {
#ifdef __cplusplus
static_assert(offsetof(msg_uart_state_depa_t, uart_a ) == 0, "Offset of uart_a in msg_uart_state_depa_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_uart_state_depa_t, uart_a ) == 0, offset_of_uart_a_in_msg_uart_state_depa_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_uart_state_depa_t, uart_b ) == 0 + sizeof(uart_channel_t), "Offset of uart_b in msg_uart_state_depa_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_uart_state_depa_t, uart_b ) == 0 + sizeof(uart_channel_t), offset_of_uart_b_in_msg_uart_state_depa_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_uart_state_depa_t, uart_ftdi ) == 0 + sizeof(uart_channel_t) + sizeof(uart_channel_t), "Offset of uart_ftdi in msg_uart_state_depa_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_uart_state_depa_t, uart_ftdi ) == 0 + sizeof(uart_channel_t) + sizeof(uart_channel_t), offset_of_uart_ftdi_in_msg_uart_state_depa_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_uart_state_depa_t, latency ) == 0 + sizeof(uart_channel_t) + sizeof(uart_channel_t) + sizeof(uart_channel_t), "Offset of latency in msg_uart_state_depa_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_uart_state_depa_t, latency ) == 0 + sizeof(uart_channel_t) + sizeof(uart_channel_t) + sizeof(uart_channel_t), offset_of_latency_in_msg_uart_state_depa_t_is_incorrect)
#endif
}

static inline void static_asserts_for_module_MSG_IAR_STATE(void) {
#ifdef __cplusplus
static_assert(offsetof(msg_iar_state_t, num_hyps ) == 0, "Offset of num_hyps in msg_iar_state_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_iar_state_t, num_hyps ) == 0, offset_of_num_hyps_in_msg_iar_state_t_is_incorrect)
#endif
}

static inline void static_asserts_for_module_MSG_MASK_SATELLITE(void) {
#ifdef __cplusplus
static_assert(offsetof(msg_mask_satellite_t, mask ) == 0, "Offset of mask in msg_mask_satellite_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_mask_satellite_t, mask ) == 0, offset_of_mask_in_msg_mask_satellite_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_mask_satellite_t, sid ) == 0 + sizeof(u8), "Offset of sid in msg_mask_satellite_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_mask_satellite_t, sid ) == 0 + sizeof(u8), offset_of_sid_in_msg_mask_satellite_t_is_incorrect)
#endif
}

static inline void static_asserts_for_module_MSG_MASK_SATELLITE_DEP(void) {
#ifdef __cplusplus
static_assert(offsetof(msg_mask_satellite_dep_t, mask ) == 0, "Offset of mask in msg_mask_satellite_dep_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_mask_satellite_dep_t, mask ) == 0, offset_of_mask_in_msg_mask_satellite_dep_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_mask_satellite_dep_t, sid ) == 0 + sizeof(u8), "Offset of sid in msg_mask_satellite_dep_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_mask_satellite_dep_t, sid ) == 0 + sizeof(u8), offset_of_sid_in_msg_mask_satellite_dep_t_is_incorrect)
#endif
}

static inline void static_asserts_for_module_MSG_DEVICE_MONITOR(void) {
#ifdef __cplusplus
static_assert(offsetof(msg_device_monitor_t, dev_vin ) == 0, "Offset of dev_vin in msg_device_monitor_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_device_monitor_t, dev_vin ) == 0, offset_of_dev_vin_in_msg_device_monitor_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_device_monitor_t, cpu_vint ) == 0 + sizeof(s16), "Offset of cpu_vint in msg_device_monitor_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_device_monitor_t, cpu_vint ) == 0 + sizeof(s16), offset_of_cpu_vint_in_msg_device_monitor_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_device_monitor_t, cpu_vaux ) == 0 + sizeof(s16) + sizeof(s16), "Offset of cpu_vaux in msg_device_monitor_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_device_monitor_t, cpu_vaux ) == 0 + sizeof(s16) + sizeof(s16), offset_of_cpu_vaux_in_msg_device_monitor_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_device_monitor_t, cpu_temperature ) == 0 + sizeof(s16) + sizeof(s16) + sizeof(s16), "Offset of cpu_temperature in msg_device_monitor_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_device_monitor_t, cpu_temperature ) == 0 + sizeof(s16) + sizeof(s16) + sizeof(s16), offset_of_cpu_temperature_in_msg_device_monitor_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_device_monitor_t, fe_temperature ) == 0 + sizeof(s16) + sizeof(s16) + sizeof(s16) + sizeof(s16), "Offset of fe_temperature in msg_device_monitor_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_device_monitor_t, fe_temperature ) == 0 + sizeof(s16) + sizeof(s16) + sizeof(s16) + sizeof(s16), offset_of_fe_temperature_in_msg_device_monitor_t_is_incorrect)
#endif
}

static inline void static_asserts_for_module_MSG_COMMAND_REQ(void) {
#ifdef __cplusplus
static_assert(offsetof(msg_command_req_t, sequence ) == 0, "Offset of sequence in msg_command_req_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_command_req_t, sequence ) == 0, offset_of_sequence_in_msg_command_req_t_is_incorrect)
#endif
#ifdef SBP_ENABLE_VARIABLE_SIZED_ARRAYS
#ifdef __cplusplus
static_assert(offsetof(msg_command_req_t, command ) == 0 + sizeof(u32), "Offset of command in msg_command_req_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_command_req_t, command ) == 0 + sizeof(u32), offset_of_command_in_msg_command_req_t_is_incorrect)
#endif
#endif
}

static inline void static_asserts_for_module_MSG_COMMAND_RESP(void) {
#ifdef __cplusplus
static_assert(offsetof(msg_command_resp_t, sequence ) == 0, "Offset of sequence in msg_command_resp_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_command_resp_t, sequence ) == 0, offset_of_sequence_in_msg_command_resp_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_command_resp_t, code ) == 0 + sizeof(u32), "Offset of code in msg_command_resp_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_command_resp_t, code ) == 0 + sizeof(u32), offset_of_code_in_msg_command_resp_t_is_incorrect)
#endif
}

static inline void static_asserts_for_module_MSG_COMMAND_OUTPUT(void) {
#ifdef __cplusplus
static_assert(offsetof(msg_command_output_t, sequence ) == 0, "Offset of sequence in msg_command_output_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_command_output_t, sequence ) == 0, offset_of_sequence_in_msg_command_output_t_is_incorrect)
#endif
#ifdef SBP_ENABLE_VARIABLE_SIZED_ARRAYS
#ifdef __cplusplus
static_assert(offsetof(msg_command_output_t, line ) == 0 + sizeof(u32), "Offset of line in msg_command_output_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_command_output_t, line ) == 0 + sizeof(u32), offset_of_line_in_msg_command_output_t_is_incorrect)
#endif
#endif
}

static inline void static_asserts_for_module_MSG_NETWORK_STATE_REQ(void) {
}

static inline void static_asserts_for_module_MSG_NETWORK_STATE_RESP(void) {
#ifdef __cplusplus
static_assert(offsetof(msg_network_state_resp_t, ipv4_address ) == 0, "Offset of ipv4_address in msg_network_state_resp_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_network_state_resp_t, ipv4_address ) == 0, offset_of_ipv4_address_in_msg_network_state_resp_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_network_state_resp_t, ipv4_mask_size ) == 0 + (sizeof(u8) * 4), "Offset of ipv4_mask_size in msg_network_state_resp_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_network_state_resp_t, ipv4_mask_size ) == 0 + (sizeof(u8) * 4), offset_of_ipv4_mask_size_in_msg_network_state_resp_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_network_state_resp_t, ipv6_address ) == 0 + (sizeof(u8) * 4) + sizeof(u8), "Offset of ipv6_address in msg_network_state_resp_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_network_state_resp_t, ipv6_address ) == 0 + (sizeof(u8) * 4) + sizeof(u8), offset_of_ipv6_address_in_msg_network_state_resp_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_network_state_resp_t, ipv6_mask_size ) == 0 + (sizeof(u8) * 4) + sizeof(u8) + (sizeof(u8) * 16), "Offset of ipv6_mask_size in msg_network_state_resp_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_network_state_resp_t, ipv6_mask_size ) == 0 + (sizeof(u8) * 4) + sizeof(u8) + (sizeof(u8) * 16), offset_of_ipv6_mask_size_in_msg_network_state_resp_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_network_state_resp_t, rx_bytes ) == 0 + (sizeof(u8) * 4) + sizeof(u8) + (sizeof(u8) * 16) + sizeof(u8), "Offset of rx_bytes in msg_network_state_resp_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_network_state_resp_t, rx_bytes ) == 0 + (sizeof(u8) * 4) + sizeof(u8) + (sizeof(u8) * 16) + sizeof(u8), offset_of_rx_bytes_in_msg_network_state_resp_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_network_state_resp_t, tx_bytes ) == 0 + (sizeof(u8) * 4) + sizeof(u8) + (sizeof(u8) * 16) + sizeof(u8) + sizeof(u32), "Offset of tx_bytes in msg_network_state_resp_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_network_state_resp_t, tx_bytes ) == 0 + (sizeof(u8) * 4) + sizeof(u8) + (sizeof(u8) * 16) + sizeof(u8) + sizeof(u32), offset_of_tx_bytes_in_msg_network_state_resp_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_network_state_resp_t, interface_name ) == 0 + (sizeof(u8) * 4) + sizeof(u8) + (sizeof(u8) * 16) + sizeof(u8) + sizeof(u32) + sizeof(u32), "Offset of interface_name in msg_network_state_resp_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_network_state_resp_t, interface_name ) == 0 + (sizeof(u8) * 4) + sizeof(u8) + (sizeof(u8) * 16) + sizeof(u8) + sizeof(u32) + sizeof(u32), offset_of_interface_name_in_msg_network_state_resp_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_network_state_resp_t, flags ) == 0 + (sizeof(u8) * 4) + sizeof(u8) + (sizeof(u8) * 16) + sizeof(u8) + sizeof(u32) + sizeof(u32) + (sizeof(char) * 16), "Offset of flags in msg_network_state_resp_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_network_state_resp_t, flags ) == 0 + (sizeof(u8) * 4) + sizeof(u8) + (sizeof(u8) * 16) + sizeof(u8) + sizeof(u32) + sizeof(u32) + (sizeof(char) * 16), offset_of_flags_in_msg_network_state_resp_t_is_incorrect)
#endif
}

static inline void static_asserts_for_module_NetworkUsage(void) {
#ifdef __cplusplus
static_assert(offsetof(network_usage_t, duration ) == 0, "Offset of duration in network_usage_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(network_usage_t, duration ) == 0, offset_of_duration_in_network_usage_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(network_usage_t, total_bytes ) == 0 + sizeof(u64), "Offset of total_bytes in network_usage_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(network_usage_t, total_bytes ) == 0 + sizeof(u64), offset_of_total_bytes_in_network_usage_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(network_usage_t, rx_bytes ) == 0 + sizeof(u64) + sizeof(u64), "Offset of rx_bytes in network_usage_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(network_usage_t, rx_bytes ) == 0 + sizeof(u64) + sizeof(u64), offset_of_rx_bytes_in_network_usage_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(network_usage_t, tx_bytes ) == 0 + sizeof(u64) + sizeof(u64) + sizeof(u32), "Offset of tx_bytes in network_usage_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(network_usage_t, tx_bytes ) == 0 + sizeof(u64) + sizeof(u64) + sizeof(u32), offset_of_tx_bytes_in_network_usage_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(network_usage_t, interface_name ) == 0 + sizeof(u64) + sizeof(u64) + sizeof(u32) + sizeof(u32), "Offset of interface_name in network_usage_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(network_usage_t, interface_name ) == 0 + sizeof(u64) + sizeof(u64) + sizeof(u32) + sizeof(u32), offset_of_interface_name_in_network_usage_t_is_incorrect)
#endif
}

static inline void static_asserts_for_module_MSG_NETWORK_BANDWIDTH_USAGE(void) {
#ifdef SBP_ENABLE_VARIABLE_SIZED_ARRAYS
#ifdef __cplusplus
static_assert(offsetof(msg_network_bandwidth_usage_t, interfaces ) == 0, "Offset of interfaces in msg_network_bandwidth_usage_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_network_bandwidth_usage_t, interfaces ) == 0, offset_of_interfaces_in_msg_network_bandwidth_usage_t_is_incorrect)
#endif
#endif
}

static inline void static_asserts_for_module_MSG_CELL_MODEM_STATUS(void) {
#ifdef __cplusplus
static_assert(offsetof(msg_cell_modem_status_t, signal_strength ) == 0, "Offset of signal_strength in msg_cell_modem_status_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_cell_modem_status_t, signal_strength ) == 0, offset_of_signal_strength_in_msg_cell_modem_status_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_cell_modem_status_t, signal_error_rate ) == 0 + sizeof(s8), "Offset of signal_error_rate in msg_cell_modem_status_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_cell_modem_status_t, signal_error_rate ) == 0 + sizeof(s8), offset_of_signal_error_rate_in_msg_cell_modem_status_t_is_incorrect)
#endif
#ifdef SBP_ENABLE_VARIABLE_SIZED_ARRAYS
#ifdef __cplusplus
static_assert(offsetof(msg_cell_modem_status_t, reserved ) == 0 + sizeof(s8) + sizeof(float), "Offset of reserved in msg_cell_modem_status_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_cell_modem_status_t, reserved ) == 0 + sizeof(s8) + sizeof(float), offset_of_reserved_in_msg_cell_modem_status_t_is_incorrect)
#endif
#endif
}

static inline void static_asserts_for_module_MSG_SPECAN_DEP(void) {
#ifdef __cplusplus
static_assert(offsetof(msg_specan_dep_t, channel_tag ) == 0, "Offset of channel_tag in msg_specan_dep_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_specan_dep_t, channel_tag ) == 0, offset_of_channel_tag_in_msg_specan_dep_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_specan_dep_t, t ) == 0 + sizeof(u16), "Offset of t in msg_specan_dep_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_specan_dep_t, t ) == 0 + sizeof(u16), offset_of_t_in_msg_specan_dep_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_specan_dep_t, freq_ref ) == 0 + sizeof(u16) + sizeof(gps_time_dep_t), "Offset of freq_ref in msg_specan_dep_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_specan_dep_t, freq_ref ) == 0 + sizeof(u16) + sizeof(gps_time_dep_t), offset_of_freq_ref_in_msg_specan_dep_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_specan_dep_t, freq_step ) == 0 + sizeof(u16) + sizeof(gps_time_dep_t) + sizeof(float), "Offset of freq_step in msg_specan_dep_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_specan_dep_t, freq_step ) == 0 + sizeof(u16) + sizeof(gps_time_dep_t) + sizeof(float), offset_of_freq_step_in_msg_specan_dep_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_specan_dep_t, amplitude_ref ) == 0 + sizeof(u16) + sizeof(gps_time_dep_t) + sizeof(float) + sizeof(float), "Offset of amplitude_ref in msg_specan_dep_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_specan_dep_t, amplitude_ref ) == 0 + sizeof(u16) + sizeof(gps_time_dep_t) + sizeof(float) + sizeof(float), offset_of_amplitude_ref_in_msg_specan_dep_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_specan_dep_t, amplitude_unit ) == 0 + sizeof(u16) + sizeof(gps_time_dep_t) + sizeof(float) + sizeof(float) + sizeof(float), "Offset of amplitude_unit in msg_specan_dep_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_specan_dep_t, amplitude_unit ) == 0 + sizeof(u16) + sizeof(gps_time_dep_t) + sizeof(float) + sizeof(float) + sizeof(float), offset_of_amplitude_unit_in_msg_specan_dep_t_is_incorrect)
#endif
#ifdef SBP_ENABLE_VARIABLE_SIZED_ARRAYS
#ifdef __cplusplus
static_assert(offsetof(msg_specan_dep_t, amplitude_value ) == 0 + sizeof(u16) + sizeof(gps_time_dep_t) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float), "Offset of amplitude_value in msg_specan_dep_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_specan_dep_t, amplitude_value ) == 0 + sizeof(u16) + sizeof(gps_time_dep_t) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float), offset_of_amplitude_value_in_msg_specan_dep_t_is_incorrect)
#endif
#endif
}

static inline void static_asserts_for_module_MSG_SPECAN(void) {
#ifdef __cplusplus
static_assert(offsetof(msg_specan_t, channel_tag ) == 0, "Offset of channel_tag in msg_specan_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_specan_t, channel_tag ) == 0, offset_of_channel_tag_in_msg_specan_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_specan_t, t ) == 0 + sizeof(u16), "Offset of t in msg_specan_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_specan_t, t ) == 0 + sizeof(u16), offset_of_t_in_msg_specan_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_specan_t, freq_ref ) == 0 + sizeof(u16) + sizeof(sbp_gps_time_t), "Offset of freq_ref in msg_specan_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_specan_t, freq_ref ) == 0 + sizeof(u16) + sizeof(sbp_gps_time_t), offset_of_freq_ref_in_msg_specan_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_specan_t, freq_step ) == 0 + sizeof(u16) + sizeof(sbp_gps_time_t) + sizeof(float), "Offset of freq_step in msg_specan_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_specan_t, freq_step ) == 0 + sizeof(u16) + sizeof(sbp_gps_time_t) + sizeof(float), offset_of_freq_step_in_msg_specan_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_specan_t, amplitude_ref ) == 0 + sizeof(u16) + sizeof(sbp_gps_time_t) + sizeof(float) + sizeof(float), "Offset of amplitude_ref in msg_specan_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_specan_t, amplitude_ref ) == 0 + sizeof(u16) + sizeof(sbp_gps_time_t) + sizeof(float) + sizeof(float), offset_of_amplitude_ref_in_msg_specan_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_specan_t, amplitude_unit ) == 0 + sizeof(u16) + sizeof(sbp_gps_time_t) + sizeof(float) + sizeof(float) + sizeof(float), "Offset of amplitude_unit in msg_specan_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_specan_t, amplitude_unit ) == 0 + sizeof(u16) + sizeof(sbp_gps_time_t) + sizeof(float) + sizeof(float) + sizeof(float), offset_of_amplitude_unit_in_msg_specan_t_is_incorrect)
#endif
#ifdef SBP_ENABLE_VARIABLE_SIZED_ARRAYS
#ifdef __cplusplus
static_assert(offsetof(msg_specan_t, amplitude_value ) == 0 + sizeof(u16) + sizeof(sbp_gps_time_t) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float), "Offset of amplitude_value in msg_specan_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_specan_t, amplitude_value ) == 0 + sizeof(u16) + sizeof(sbp_gps_time_t) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float), offset_of_amplitude_value_in_msg_specan_t_is_incorrect)
#endif
#endif
}

static inline void static_asserts_for_module_MSG_FRONT_END_GAIN(void) {
#ifdef __cplusplus
static_assert(offsetof(msg_front_end_gain_t, rf_gain ) == 0, "Offset of rf_gain in msg_front_end_gain_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_front_end_gain_t, rf_gain ) == 0, offset_of_rf_gain_in_msg_front_end_gain_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_front_end_gain_t, if_gain ) == 0 + (sizeof(s8) * 8), "Offset of if_gain in msg_front_end_gain_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_front_end_gain_t, if_gain ) == 0 + (sizeof(s8) * 8), offset_of_if_gain_in_msg_front_end_gain_t_is_incorrect)
#endif
}


#ifdef __ghs__
#pragma pack()
#endif
SBP_PACK_END

#endif /* LIBSBP_PIKSI_MESSAGES_H */
