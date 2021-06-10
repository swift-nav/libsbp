/*
 * Copyright (C) 2015-2021 Swift Navigation Inc.
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
 * Automatically generated from yaml/swiftnav/sbp/linux.yaml
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

#ifndef LIBSBP_LINUX_MACROS_H
#define LIBSBP_LINUX_MACROS_H

#define SBP_MSG_LINUX_CPU_STATE_DEP_A 0x7F00
#define SBP_MSG_LINUX_MEM_STATE_DEP_A 0x7F01
#define SBP_MSG_LINUX_SYS_STATE_DEP_A 0x7F02
#define SBP_MSG_LINUX_PROCESS_SOCKET_COUNTS 0x7F03
#define SBP_MSG_LINUX_PROCESS_SOCKET_QUEUES 0x7F04
#define SBP_MSG_LINUX_SOCKET_USAGE 0x7F05
#define SBP_MSG_LINUX_PROCESS_FD_COUNT 0x7F06
#define SBP_MSG_LINUX_PROCESS_FD_SUMMARY 0x7F07
#define SBP_MSG_LINUX_CPU_STATE 0x7F08
#define SBP_LINUX_CPU_STATE_TIMESTAMP_TYPE_MASK (0x7)
#define SBP_LINUX_CPU_STATE_TIMESTAMP_TYPE_SHIFT (0u)
#define SBP_LINUX_CPU_STATE_TIMESTAMP_TYPE_GET(flags)      \
  (((flags) >> SBP_LINUX_CPU_STATE_TIMESTAMP_TYPE_SHIFT) & \
   SBP_LINUX_CPU_STATE_TIMESTAMP_TYPE_MASK)
#define SBP_LINUX_CPU_STATE_TIMESTAMP_TYPE_SET(flags, val)           \
  do {                                                               \
    ((flags) |= (((val) & (SBP_LINUX_CPU_STATE_TIMESTAMP_TYPE_MASK)) \
                 << (SBP_LINUX_CPU_STATE_TIMESTAMP_TYPE_SHIFT)));    \
  } while (0)

#define SBP_LINUX_CPU_STATE_TIMESTAMP_TYPE_SYSTEM_TIME_IN_SECONDS (0)
#define SBP_LINUX_CPU_STATE_TIMESTAMP_TYPE_GPS_TOW_IN_MILLISECONDS (1)
#define SBP_MSG_LINUX_MEM_STATE 0x7F09
#define SBP_LINUX_MEM_STATE_TIMESTAMP_TYPE_MASK (0x7)
#define SBP_LINUX_MEM_STATE_TIMESTAMP_TYPE_SHIFT (0u)
#define SBP_LINUX_MEM_STATE_TIMESTAMP_TYPE_GET(flags)      \
  (((flags) >> SBP_LINUX_MEM_STATE_TIMESTAMP_TYPE_SHIFT) & \
   SBP_LINUX_MEM_STATE_TIMESTAMP_TYPE_MASK)
#define SBP_LINUX_MEM_STATE_TIMESTAMP_TYPE_SET(flags, val)           \
  do {                                                               \
    ((flags) |= (((val) & (SBP_LINUX_MEM_STATE_TIMESTAMP_TYPE_MASK)) \
                 << (SBP_LINUX_MEM_STATE_TIMESTAMP_TYPE_SHIFT)));    \
  } while (0)

#define SBP_LINUX_MEM_STATE_TIMESTAMP_TYPE_SYSTEM_TIME_IN_SECONDS (0)
#define SBP_LINUX_MEM_STATE_TIMESTAMP_TYPE_GPS_TOW_IN_MILLISECONDS (1)
#define SBP_MSG_LINUX_SYS_STATE 0x7F0A
#define SBP_LINUX_SYS_STATE_TIMESTAMP_TYPE_MASK (0x7)
#define SBP_LINUX_SYS_STATE_TIMESTAMP_TYPE_SHIFT (0u)
#define SBP_LINUX_SYS_STATE_TIMESTAMP_TYPE_GET(flags)      \
  (((flags) >> SBP_LINUX_SYS_STATE_TIMESTAMP_TYPE_SHIFT) & \
   SBP_LINUX_SYS_STATE_TIMESTAMP_TYPE_MASK)
#define SBP_LINUX_SYS_STATE_TIMESTAMP_TYPE_SET(flags, val)           \
  do {                                                               \
    ((flags) |= (((val) & (SBP_LINUX_SYS_STATE_TIMESTAMP_TYPE_MASK)) \
                 << (SBP_LINUX_SYS_STATE_TIMESTAMP_TYPE_SHIFT)));    \
  } while (0)

#define SBP_LINUX_SYS_STATE_TIMESTAMP_TYPE_SYSTEM_TIME_IN_SECONDS (0)
#define SBP_LINUX_SYS_STATE_TIMESTAMP_TYPE_GPS_TOW_IN_MILLISECONDS (1)

#endif
