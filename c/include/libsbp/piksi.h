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
 * Automatically generated from piksi/yaml/
 * with generate.py at 2015-03-21 14:15:30.539781. Please do not hand edit!
 *****************************************************************************/

#ifndef LIBSBP_PIKSI_MESSAGES_H
#define LIBSBP_PIKSI_MESSAGES_H

#include "common.h"
#include "lib.h"


/** None
 
 */
#define SBP_MSG_PRINT                   0x0010


/** None
 
 */
#define SBP_MSG_DEBUG_VAR               0x0011


/** None
 
 */
#define SBP_MSG_ALMANAC                 0x0069


/** None
 
 */
#define SBP_MSG_SET_TIME                0x0068


/** None
 
 */
#define SBP_MSG_BOOTLOADER_HANDSHAKE    0x00B0


/** None
 
 */
#define SBP_MSG_BOOTLOADER_JUMP_TO_APP  0x00B1


/** None
 
 */
#define SBP_MSG_RESET                   0x00B2


/** None
 
 */
#define SBP_MSG_CW_RESULTS              0x00C0


/** None
 
 */
#define SBP_MSG_CW_START                0x00C1


/** None
 
 */
#define SBP_MSG_NAP_DEVICE_DNA          0x00DD


/** None
 
 */
#define SBP_MSG_FLASH_PROGRAM           0x00E0


/** None
 
 */
#define SBP_MSG_FLASH_DONE              0x00E0


/** None
 
 */
#define SBP_MSG_FLASH_READ              0x00E1


/** None
 
 */
#define SBP_MSG_FLASH_ERASE             0x00E2


/** None
 
 */
#define SBP_MSG_STM_FLASH_LOCK_SECTOR   0x00E3


/** None
 
 */
#define SBP_MSG_STM_FLASH_UNLOCK_SECTOR 0x00E4


/** None
 
 */
#define SBP_MSG_STM_UNIQUE_ID           0x00E5


/** None
 
 */
#define SBP_MSG_M25_FLASH_WRITE_STATUS  0x00F3


/** None
 
 */
#define SBP_MSG_RESET_FILTERS           0x0022


/** None
 
 */
#define SBP_MSG_INIT_BASE               0x0023


/** None
 
 */
#define SBP_MSG_SETTINGS                0x00A0


/** None
 
 */
#define SBP_MSG_SETTINGS_SAVE           0x00A1


/** None
 
 */
#define SBP_MSG_SETTINGS_READ_BY_INDEX  0x00A2


/** None
 
 */
#define SBP_MSG_FILEIO_READ             0x00A8


/** None
 
 */
#define SBP_MSG_FILEIO_READ_DIR         0x00A9


/** None
 
 */
#define SBP_MSG_FILEIO_REMOVE           0x00AC


/** None
 
 */
#define SBP_MSG_FILEIO_WRITE            0x00AD


/** None
 
 */
#define SBP_MSG_THREAD_STATE            0x0017
typedef struct __attribute__((packed)) {
  char name[20];          /**< Thread name */
  u16 cpu;           /**< cpu */
  u32 stack_free;    /**< Free stack space for this thread. [kB] */
} msg_thread_state_t;


/** None
 
 */
typedef struct __attribute__((packed)) {
  float tx_throughput;      /**< UART transmit throughput. [kB/s] */
  float rx_throughput;      /**< UART receive throughput. [kB/s] */
  u16 crc_error_count;    /**< UART CRC error count. */
  u16 io_error_count;     /**< UART IO error count. */
  u8 tx_buffer_level;    /**< UART transmit usage percentage. [Utilization % /255] */
  u8 rx_buffer_level;    /**< UART receive usage percentage. [Utilization % /255] */
} uart_channel_t;


/** None
 
 */
#define SBP_MSG_UART_STATE              0x0018
typedef struct __attribute__((packed)) {
  uart_channel_t uarts0;     /**< State of UART0. */
  uart_channel_t uarts1;     /**< State of UART1. */
  uart_channel_t uarts2;     /**< State of UART2. */
  latency_t latency;    /**< UART communication latency. */
} msg_uart_state_t;


/** None
 
 */
#define SBP_MSG_IAR_STATE               0x0019
typedef struct __attribute__((packed)) {
  u32 num_hyps;    /**< Number of integer ambiguity hypotheses remaining. */
} msg_iar_state_t;


#endif /* LIBSBP_PIKSI_MESSAGES_H */