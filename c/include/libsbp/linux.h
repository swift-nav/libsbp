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
 * Automatically generated from yaml/swiftnav/sbp/linux.yaml
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

/** \defgroup linux Linux
 *
 *  * Linux state monitoring.
 * \{ */

#ifndef LIBSBP_LINUX_MESSAGES_H
#define LIBSBP_LINUX_MESSAGES_H

#include "common.h"

SBP_PACK_START


/** List CPU state on the system
 *
 * This message indicates the process state of the top 10 heaviest
 * consumers of CPU on the system.
 */
#define SBP_MSG_LINUX_CPU_STATE 0x7F00
typedef struct SBP_ATTR_PACKED {
  u8 index;      /**< sequence of this status message, values from 0-9 */
  u16 pid;        /**< the PID of the process */
  u8 pcpu;       /**< percent of cpu used, expressed as a fraction of 256 */
  char tname[15];  /**< fixed length string representing the thread name */
  char cmdline[0]; /**< the command line (as much as it fits in the remaining packet) */
} msg_linux_cpu_state_t;


/** List CPU state on the system
 *
 * This message indicates the process state of the top 10 heaviest
 * consumers of memory on the system.
 */
#define SBP_MSG_LINUX_MEM_STATE 0x7F01
typedef struct SBP_ATTR_PACKED {
  u8 index;      /**< sequence of this status message, values from 0-9 */
  u16 pid;        /**< the PID of the process */
  u8 pcpu;       /**< percent of memory used, expressed as a fraction of 256 */
  char tname[15];  /**< fixed length string representing the thread name */
  char cmdline[0]; /**< the command line (as much as it fits in the remaining packet) */
} msg_linux_mem_state_t;


/** \} */

SBP_PACK_END

#endif /* LIBSBP_LINUX_MESSAGES_H */