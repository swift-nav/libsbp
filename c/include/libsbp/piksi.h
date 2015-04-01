/*
 * Copyright (C) 2015 Swift Navigation Inc.
 * Contact: Fergus Noble <fergus@swift-nav.com>
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
 * with generate.py at 2015-04-02 12:08:48.499356. Please do not hand edit!
 *****************************************************************************/

#ifndef LIBSBP_PIKSI_MESSAGES_H
#define LIBSBP_PIKSI_MESSAGES_H

#include "common.h"


/** Legacy message to load satellite almanac (Host => Piksi).
 *
 * This is a legacy message for sending and loading a satellite
 * alamanac onto the Piksi's flash memory from the host.
 */
#define SBP_MSG_ALMANAC       0x0069


/** Send GPS time from host (Host => Piksi).
 *
 * This message sets up timing functionality using a coarse GPS
 * time estimate sent by the host.
 */
#define SBP_MSG_SET_TIME      0x0068


/** Reset the device (Host => Piksi).
 *
 * This message from the host resets the Piksi back into the
 * bootloader. It ensures that all outstanding memory accesses
 * including buffered writes are completed before reset begins.
 */
#define SBP_MSG_RESET         0x00B2


/** Legacy message for CW interference channel (Piksi => Host).
 *
 * This is an unused legacy message for result reporting from the
 * CW interference channel on the SwiftNAP. This message will be
 * removed in a future release.
 */
#define SBP_MSG_CW_RESULTS    0x00C0


/** Legacy message for CW interference channel (Host => Piksi).
 *
 * This is an unused legacy message from those host for starting
 * the CW interference channel on the SwiftNAP. This message will
 * be removed in a future release.
 */
#define SBP_MSG_CW_START      0x00C1


/** Reset IAR filters (Host => Piksi)
 *
 * This message resets either the DGNSS Kalman filters or Integer
 * Ambiguity Resolution (IAR) process.
 */
#define SBP_MSG_RESET_FILTERS 0x0022
typedef struct __attribute__((packed)) {
  u8 filter;    /**< Filter flags */
} msg_reset_filters_t;


/** Initialize IAR from known baseline (Host => Piksi).
 *
 * This message initializes the Integer Ambiguity Resolution (IAR)
 * process on the Piksi to use an assumed baseline position between
 * the base station and rover receivers. Warns via MsgPrint if
 * there aren't a shared minimum number (4) of satellite
 * observations between the two.
 */
#define SBP_MSG_INIT_BASE     0x0023


/** State of a CPU/RTOS thread.
 *
 * The thread usage message from the Piksi reports RTOS thread
 * usage statistics for the named thread. The reported values
 * require renormalization.
 */
#define SBP_MSG_THREAD_STATE  0x0017
typedef struct __attribute__((packed)) {
  char name[20];      /**< Thread name (NULL terminated) */
  u16 cpu;           /**< Percentage cpu use for this thread. Ranges from 0 - 1000
and needs to be renormalized to 100.
 [Utilization percentage /1000.] */
  u32 stack_free;    /**< Free stack space for this thread. [kB] */
} msg_thread_state_t;


/** State of the UART channel.
 *
 * Throughput, utilization, and error counts on the RX/TX buffers
 * of this UART channel. Values require renormalization.
 */
typedef struct __attribute__((packed)) {
  float tx_throughput;      /**< UART transmit throughput. [kB/s] */
  float rx_throughput;      /**< UART receive throughput. [kB/s] */
  u16 crc_error_count;    /**< UART CRC error count. */
  u16 io_error_count;     /**< UART IO error count. */
  u8 tx_buffer_level;    /**< UART transmit buffer percentage utilization. Ranges from
0 - 255 and needs to be renormalized to 100.
 [Utilization /255] */
  u8 rx_buffer_level;    /**< UART receive buffer percentage utilization. Ranges from
0 - 255 and needs to be renormalized to 100.
 [Utilization /255] */
} uart_channel_t;


/** Receiver-to-base station latency.
 *
 * Statistics on the latency of observations received from the base
 * station. As observation packets are received their GPS time is
 * compared to the current GPS time calculated locally by the
 * receiver to give a precise measurement of the end-to-end
 * communication latency in the system.
 */
typedef struct __attribute__((packed)) {
  s32 avg;        /**< Average latency. [ms] */
  s32 lmin;       /**< Minimum latency. [ms] */
  s32 lmax;       /**< Maximum latency. [ms] */
  s32 current;    /**< Smoothed estimate of the current latency. [ms] */
} latency_t;


/** State of the UART channels.
 *
 * The UART message reports data latency and throughput of the UART
 * channels providing SBP I/O. On the default Piksi configuration,
 * UARTs A and B are used for telemetry radios, but can also be be
 * host access ports for embedded hosts, or other interfaces in
 * future.
 */
#define SBP_MSG_UART_STATE    0x0018
typedef struct __attribute__((packed)) {
  uart_channel_t uart_a;       /**< State of UART A */
  uart_channel_t uart_b;       /**< State of UART B */
  uart_channel_t uart_ftdi;    /**< State of UART FTDI (USB logger) */
  latency_t latency;      /**< UART communication latency */
} msg_uart_state_t;


/** State of the Integer Ambiguity Resolution (IAR) process.
 *
 * This message reports the state of the Integer Ambiguity
 * Resolution (IAR) process, which resolves unknown integer
 * ambiguities from double-differenced carrier-phase measurements
 * from satellite observations.
 */
#define SBP_MSG_IAR_STATE     0x0019
typedef struct __attribute__((packed)) {
  u32 num_hyps;    /**< Number of integer ambiguity hypotheses remaining. */
} msg_iar_state_t;


#endif /* LIBSBP_PIKSI_MESSAGES_H */