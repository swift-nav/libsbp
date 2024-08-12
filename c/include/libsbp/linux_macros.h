/*
 * Copyright (C) 2015-2021 Swift Navigation Inc.
 * Contact: https://support.swiftnav.com
 *
 * This source is subject to the license found in the file 'LICENSE' which must
 * be distributed together with this source. All other rights reserved.
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

/**
 * The maximum number of items that can be stored in
 * sbp_msg_linux_cpu_state_dep_a_t::tname before the maximum SBP message size is
 * exceeded
 */
#define SBP_MSG_LINUX_CPU_STATE_DEP_A_TNAME_MAX 15u

/**
 * The maximum number of items that can be stored in
 * sbp_msg_linux_cpu_state_dep_a_t::cmdline before the maximum SBP message size
 * is exceeded
 */
#define SBP_MSG_LINUX_CPU_STATE_DEP_A_CMDLINE_MAX 236u

/**
 * Encoded length of sbp_msg_linux_cpu_state_dep_a_t
 *
 * This type is not fixed size and an instance of this message may be longer
 * than the value indicated by this symbol. Users call
 * #sbp_msg_linux_cpu_state_dep_a_encoded_len to determine the actual size of an
 * instance of this message.
 *
 * See the documentation for libsbp for more details regarding the message
 * structure and its variable length component(s)
 */
#define SBP_MSG_LINUX_CPU_STATE_DEP_A_ENCODED_OVERHEAD 19u

/**
 * The maximum number of items that can be stored in
 * sbp_msg_linux_mem_state_dep_a_t::tname before the maximum SBP message size is
 * exceeded
 */
#define SBP_MSG_LINUX_MEM_STATE_DEP_A_TNAME_MAX 15u

/**
 * The maximum number of items that can be stored in
 * sbp_msg_linux_mem_state_dep_a_t::cmdline before the maximum SBP message size
 * is exceeded
 */
#define SBP_MSG_LINUX_MEM_STATE_DEP_A_CMDLINE_MAX 236u

/**
 * Encoded length of sbp_msg_linux_mem_state_dep_a_t
 *
 * This type is not fixed size and an instance of this message may be longer
 * than the value indicated by this symbol. Users call
 * #sbp_msg_linux_mem_state_dep_a_encoded_len to determine the actual size of an
 * instance of this message.
 *
 * See the documentation for libsbp for more details regarding the message
 * structure and its variable length component(s)
 */
#define SBP_MSG_LINUX_MEM_STATE_DEP_A_ENCODED_OVERHEAD 19u

/**
 * Encoded length of sbp_msg_linux_sys_state_dep_a_t
 */
#define SBP_MSG_LINUX_SYS_STATE_DEP_A_ENCODED_LEN 10u

/**
 * The maximum number of items that can be stored in
 * sbp_msg_linux_process_socket_counts_t::cmdline before the maximum SBP message
 * size is exceeded
 */
#define SBP_MSG_LINUX_PROCESS_SOCKET_COUNTS_CMDLINE_MAX 246u

/**
 * Encoded length of sbp_msg_linux_process_socket_counts_t
 *
 * This type is not fixed size and an instance of this message may be longer
 * than the value indicated by this symbol. Users call
 * #sbp_msg_linux_process_socket_counts_encoded_len to determine the actual size
 * of an instance of this message.
 *
 * See the documentation for libsbp for more details regarding the message
 * structure and its variable length component(s)
 */
#define SBP_MSG_LINUX_PROCESS_SOCKET_COUNTS_ENCODED_OVERHEAD 9u

/**
 * The maximum number of items that can be stored in
 * sbp_msg_linux_process_socket_queues_t::address_of_largest before the maximum
 * SBP message size is exceeded
 */
#define SBP_MSG_LINUX_PROCESS_SOCKET_QUEUES_ADDRESS_OF_LARGEST_MAX 64u

/**
 * The maximum number of items that can be stored in
 * sbp_msg_linux_process_socket_queues_t::cmdline before the maximum SBP message
 * size is exceeded
 */
#define SBP_MSG_LINUX_PROCESS_SOCKET_QUEUES_CMDLINE_MAX 180u

/**
 * Encoded length of sbp_msg_linux_process_socket_queues_t
 *
 * This type is not fixed size and an instance of this message may be longer
 * than the value indicated by this symbol. Users call
 * #sbp_msg_linux_process_socket_queues_encoded_len to determine the actual size
 * of an instance of this message.
 *
 * See the documentation for libsbp for more details regarding the message
 * structure and its variable length component(s)
 */
#define SBP_MSG_LINUX_PROCESS_SOCKET_QUEUES_ENCODED_OVERHEAD 75u

/**
 * The maximum number of items that can be stored in
 * sbp_msg_linux_socket_usage_t::socket_state_counts before the maximum SBP
 * message size is exceeded
 */
#define SBP_MSG_LINUX_SOCKET_USAGE_SOCKET_STATE_COUNTS_MAX 16u

/**
 * The maximum number of items that can be stored in
 * sbp_msg_linux_socket_usage_t::socket_type_counts before the maximum SBP
 * message size is exceeded
 */
#define SBP_MSG_LINUX_SOCKET_USAGE_SOCKET_TYPE_COUNTS_MAX 16u

/**
 * Encoded length of sbp_msg_linux_socket_usage_t
 */
#define SBP_MSG_LINUX_SOCKET_USAGE_ENCODED_LEN 72u

/**
 * The maximum number of items that can be stored in
 * sbp_msg_linux_process_fd_count_t::cmdline before the maximum SBP message size
 * is exceeded
 */
#define SBP_MSG_LINUX_PROCESS_FD_COUNT_CMDLINE_MAX 250u

/**
 * Encoded length of sbp_msg_linux_process_fd_count_t
 *
 * This type is not fixed size and an instance of this message may be longer
 * than the value indicated by this symbol. Users call
 * #sbp_msg_linux_process_fd_count_encoded_len to determine the actual size of
 * an instance of this message.
 *
 * See the documentation for libsbp for more details regarding the message
 * structure and its variable length component(s)
 */
#define SBP_MSG_LINUX_PROCESS_FD_COUNT_ENCODED_OVERHEAD 5u

/**
 * The maximum number of items that can be stored in
 * sbp_msg_linux_process_fd_summary_t::most_opened before the maximum SBP
 * message size is exceeded
 */
#define SBP_MSG_LINUX_PROCESS_FD_SUMMARY_MOST_OPENED_MAX 251u

/**
 * Encoded length of sbp_msg_linux_process_fd_summary_t
 *
 * This type is not fixed size and an instance of this message may be longer
 * than the value indicated by this symbol. Users call
 * #sbp_msg_linux_process_fd_summary_encoded_len to determine the actual size of
 * an instance of this message.
 *
 * See the documentation for libsbp for more details regarding the message
 * structure and its variable length component(s)
 */
#define SBP_MSG_LINUX_PROCESS_FD_SUMMARY_ENCODED_OVERHEAD 4u

#define SBP_LINUX_CPU_STATE_TIMESTAMP_TYPE_MASK (0x7u)
#define SBP_LINUX_CPU_STATE_TIMESTAMP_TYPE_SHIFT (0u)
#define SBP_LINUX_CPU_STATE_TIMESTAMP_TYPE_GET(flags)               \
  ((u8)((u8)((flags) >> SBP_LINUX_CPU_STATE_TIMESTAMP_TYPE_SHIFT) & \
        SBP_LINUX_CPU_STATE_TIMESTAMP_TYPE_MASK))
#define SBP_LINUX_CPU_STATE_TIMESTAMP_TYPE_SET(flags, val)                \
  do {                                                                    \
    (flags) =                                                             \
        (u8)((flags & (~(SBP_LINUX_CPU_STATE_TIMESTAMP_TYPE_MASK          \
                         << SBP_LINUX_CPU_STATE_TIMESTAMP_TYPE_SHIFT))) | \
             (((val) & (SBP_LINUX_CPU_STATE_TIMESTAMP_TYPE_MASK))         \
              << (SBP_LINUX_CPU_STATE_TIMESTAMP_TYPE_SHIFT)));            \
  } while (0)

#define SBP_LINUX_CPU_STATE_TIMESTAMP_TYPE_SYSTEM_TIME_IN_SECONDS (0)
#define SBP_LINUX_CPU_STATE_TIMESTAMP_TYPE_GPS_TOW_IN_MILLISECONDS (1)
/**
 * The maximum number of items that can be stored in
 * sbp_msg_linux_cpu_state_t::tname before the maximum SBP message size is
 * exceeded
 */
#define SBP_MSG_LINUX_CPU_STATE_TNAME_MAX 15u

/**
 * The maximum number of items that can be stored in
 * sbp_msg_linux_cpu_state_t::cmdline before the maximum SBP message size is
 * exceeded
 */
#define SBP_MSG_LINUX_CPU_STATE_CMDLINE_MAX 231u

/**
 * Encoded length of sbp_msg_linux_cpu_state_t
 *
 * This type is not fixed size and an instance of this message may be longer
 * than the value indicated by this symbol. Users call
 * #sbp_msg_linux_cpu_state_encoded_len to determine the actual size of an
 * instance of this message.
 *
 * See the documentation for libsbp for more details regarding the message
 * structure and its variable length component(s)
 */
#define SBP_MSG_LINUX_CPU_STATE_ENCODED_OVERHEAD 24u

#define SBP_LINUX_MEM_STATE_TIMESTAMP_TYPE_MASK (0x7u)
#define SBP_LINUX_MEM_STATE_TIMESTAMP_TYPE_SHIFT (0u)
#define SBP_LINUX_MEM_STATE_TIMESTAMP_TYPE_GET(flags)               \
  ((u8)((u8)((flags) >> SBP_LINUX_MEM_STATE_TIMESTAMP_TYPE_SHIFT) & \
        SBP_LINUX_MEM_STATE_TIMESTAMP_TYPE_MASK))
#define SBP_LINUX_MEM_STATE_TIMESTAMP_TYPE_SET(flags, val)                \
  do {                                                                    \
    (flags) =                                                             \
        (u8)((flags & (~(SBP_LINUX_MEM_STATE_TIMESTAMP_TYPE_MASK          \
                         << SBP_LINUX_MEM_STATE_TIMESTAMP_TYPE_SHIFT))) | \
             (((val) & (SBP_LINUX_MEM_STATE_TIMESTAMP_TYPE_MASK))         \
              << (SBP_LINUX_MEM_STATE_TIMESTAMP_TYPE_SHIFT)));            \
  } while (0)

#define SBP_LINUX_MEM_STATE_TIMESTAMP_TYPE_SYSTEM_TIME_IN_SECONDS (0)
#define SBP_LINUX_MEM_STATE_TIMESTAMP_TYPE_GPS_TOW_IN_MILLISECONDS (1)
/**
 * The maximum number of items that can be stored in
 * sbp_msg_linux_mem_state_t::tname before the maximum SBP message size is
 * exceeded
 */
#define SBP_MSG_LINUX_MEM_STATE_TNAME_MAX 15u

/**
 * The maximum number of items that can be stored in
 * sbp_msg_linux_mem_state_t::cmdline before the maximum SBP message size is
 * exceeded
 */
#define SBP_MSG_LINUX_MEM_STATE_CMDLINE_MAX 231u

/**
 * Encoded length of sbp_msg_linux_mem_state_t
 *
 * This type is not fixed size and an instance of this message may be longer
 * than the value indicated by this symbol. Users call
 * #sbp_msg_linux_mem_state_encoded_len to determine the actual size of an
 * instance of this message.
 *
 * See the documentation for libsbp for more details regarding the message
 * structure and its variable length component(s)
 */
#define SBP_MSG_LINUX_MEM_STATE_ENCODED_OVERHEAD 24u

#define SBP_LINUX_SYS_STATE_TIMESTAMP_TYPE_MASK (0x7u)
#define SBP_LINUX_SYS_STATE_TIMESTAMP_TYPE_SHIFT (0u)
#define SBP_LINUX_SYS_STATE_TIMESTAMP_TYPE_GET(flags)               \
  ((u8)((u8)((flags) >> SBP_LINUX_SYS_STATE_TIMESTAMP_TYPE_SHIFT) & \
        SBP_LINUX_SYS_STATE_TIMESTAMP_TYPE_MASK))
#define SBP_LINUX_SYS_STATE_TIMESTAMP_TYPE_SET(flags, val)                \
  do {                                                                    \
    (flags) =                                                             \
        (u8)((flags & (~(SBP_LINUX_SYS_STATE_TIMESTAMP_TYPE_MASK          \
                         << SBP_LINUX_SYS_STATE_TIMESTAMP_TYPE_SHIFT))) | \
             (((val) & (SBP_LINUX_SYS_STATE_TIMESTAMP_TYPE_MASK))         \
              << (SBP_LINUX_SYS_STATE_TIMESTAMP_TYPE_SHIFT)));            \
  } while (0)

#define SBP_LINUX_SYS_STATE_TIMESTAMP_TYPE_SYSTEM_TIME_IN_SECONDS (0)
#define SBP_LINUX_SYS_STATE_TIMESTAMP_TYPE_GPS_TOW_IN_MILLISECONDS (1)
/**
 * Encoded length of sbp_msg_linux_sys_state_t
 */
#define SBP_MSG_LINUX_SYS_STATE_ENCODED_LEN 15u

#endif /* LIBSBP_LINUX_MACROS_H */
