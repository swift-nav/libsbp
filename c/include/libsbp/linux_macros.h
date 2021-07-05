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
/**
 * Encoded length of sbp_msg_linux_cpu_state_dep_a_t (V4 API) and
 * msg_linux_cpu_state_dep_a_t (legacy API)
 *
 * This type is not fixed size and an instance of this message may be longer
 * than the value indicated by this symbol. Users of the V4 API should call
 * #sbp_msg_linux_cpu_state_dep_a_encoded_len to determine the actual size of an
 * instance of this message. Users of the legacy API are required to track the
 * encoded message length when interacting with the legacy type.
 *
 * See the documentation for libsbp for more details regarding the message
 * structure and its variable length component(s)
 */
#define SBP_MSG_LINUX_CPU_STATE_DEP_A_ENCODED_OVERHEAD 19u

#define SBP_MSG_LINUX_MEM_STATE_DEP_A 0x7F01
/**
 * Encoded length of sbp_msg_linux_mem_state_dep_a_t (V4 API) and
 * msg_linux_mem_state_dep_a_t (legacy API)
 *
 * This type is not fixed size and an instance of this message may be longer
 * than the value indicated by this symbol. Users of the V4 API should call
 * #sbp_msg_linux_mem_state_dep_a_encoded_len to determine the actual size of an
 * instance of this message. Users of the legacy API are required to track the
 * encoded message length when interacting with the legacy type.
 *
 * See the documentation for libsbp for more details regarding the message
 * structure and its variable length component(s)
 */
#define SBP_MSG_LINUX_MEM_STATE_DEP_A_ENCODED_OVERHEAD 19u

#define SBP_MSG_LINUX_SYS_STATE_DEP_A 0x7F02
/**
 * Encoded length of sbp_msg_linux_sys_state_dep_a_t (V4 API) and
 * msg_linux_sys_state_dep_a_t (legacy API)
 */
#define SBP_MSG_LINUX_SYS_STATE_DEP_A_ENCODED_LEN 10u

#define SBP_MSG_LINUX_PROCESS_SOCKET_COUNTS 0x7F03
/**
 * Encoded length of sbp_msg_linux_process_socket_counts_t (V4 API) and
 * msg_linux_process_socket_counts_t (legacy API)
 *
 * This type is not fixed size and an instance of this message may be longer
 * than the value indicated by this symbol. Users of the V4 API should call
 * #sbp_msg_linux_process_socket_counts_encoded_len to determine the actual size
 * of an instance of this message. Users of the legacy API are required to track
 * the encoded message length when interacting with the legacy type.
 *
 * See the documentation for libsbp for more details regarding the message
 * structure and its variable length component(s)
 */
#define SBP_MSG_LINUX_PROCESS_SOCKET_COUNTS_ENCODED_OVERHEAD 9u

#define SBP_MSG_LINUX_PROCESS_SOCKET_QUEUES 0x7F04
/**
 * Encoded length of sbp_msg_linux_process_socket_queues_t (V4 API) and
 * msg_linux_process_socket_queues_t (legacy API)
 *
 * This type is not fixed size and an instance of this message may be longer
 * than the value indicated by this symbol. Users of the V4 API should call
 * #sbp_msg_linux_process_socket_queues_encoded_len to determine the actual size
 * of an instance of this message. Users of the legacy API are required to track
 * the encoded message length when interacting with the legacy type.
 *
 * See the documentation for libsbp for more details regarding the message
 * structure and its variable length component(s)
 */
#define SBP_MSG_LINUX_PROCESS_SOCKET_QUEUES_ENCODED_OVERHEAD 75u

#define SBP_MSG_LINUX_SOCKET_USAGE 0x7F05
/**
 * Encoded length of sbp_msg_linux_socket_usage_t (V4 API) and
 * msg_linux_socket_usage_t (legacy API)
 */
#define SBP_MSG_LINUX_SOCKET_USAGE_ENCODED_LEN 72u

#define SBP_MSG_LINUX_PROCESS_FD_COUNT 0x7F06
/**
 * Encoded length of sbp_msg_linux_process_fd_count_t (V4 API) and
 * msg_linux_process_fd_count_t (legacy API)
 *
 * This type is not fixed size and an instance of this message may be longer
 * than the value indicated by this symbol. Users of the V4 API should call
 * #sbp_msg_linux_process_fd_count_encoded_len to determine the actual size of
 * an instance of this message. Users of the legacy API are required to track
 * the encoded message length when interacting with the legacy type.
 *
 * See the documentation for libsbp for more details regarding the message
 * structure and its variable length component(s)
 */
#define SBP_MSG_LINUX_PROCESS_FD_COUNT_ENCODED_OVERHEAD 5u

#define SBP_MSG_LINUX_PROCESS_FD_SUMMARY 0x7F07
/**
 * Encoded length of sbp_msg_linux_process_fd_summary_t (V4 API) and
 * msg_linux_process_fd_summary_t (legacy API)
 *
 * This type is not fixed size and an instance of this message may be longer
 * than the value indicated by this symbol. Users of the V4 API should call
 * #sbp_msg_linux_process_fd_summary_encoded_len to determine the actual size of
 * an instance of this message. Users of the legacy API are required to track
 * the encoded message length when interacting with the legacy type.
 *
 * See the documentation for libsbp for more details regarding the message
 * structure and its variable length component(s)
 */
#define SBP_MSG_LINUX_PROCESS_FD_SUMMARY_ENCODED_OVERHEAD 4u

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
/**
 * Encoded length of sbp_msg_linux_cpu_state_t (V4 API) and
 * msg_linux_cpu_state_t (legacy API)
 *
 * This type is not fixed size and an instance of this message may be longer
 * than the value indicated by this symbol. Users of the V4 API should call
 * #sbp_msg_linux_cpu_state_encoded_len to determine the actual size of an
 * instance of this message. Users of the legacy API are required to track the
 * encoded message length when interacting with the legacy type.
 *
 * See the documentation for libsbp for more details regarding the message
 * structure and its variable length component(s)
 */
#define SBP_MSG_LINUX_CPU_STATE_ENCODED_OVERHEAD 24u

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
/**
 * Encoded length of sbp_msg_linux_mem_state_t (V4 API) and
 * msg_linux_mem_state_t (legacy API)
 *
 * This type is not fixed size and an instance of this message may be longer
 * than the value indicated by this symbol. Users of the V4 API should call
 * #sbp_msg_linux_mem_state_encoded_len to determine the actual size of an
 * instance of this message. Users of the legacy API are required to track the
 * encoded message length when interacting with the legacy type.
 *
 * See the documentation for libsbp for more details regarding the message
 * structure and its variable length component(s)
 */
#define SBP_MSG_LINUX_MEM_STATE_ENCODED_OVERHEAD 24u

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
/**
 * Encoded length of sbp_msg_linux_sys_state_t (V4 API) and
 * msg_linux_sys_state_t (legacy API)
 */
#define SBP_MSG_LINUX_SYS_STATE_ENCODED_LEN 15u

#endif /* LIBSBP_LINUX_MACROS_H */
