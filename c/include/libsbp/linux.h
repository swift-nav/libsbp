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
#ifdef __ghs__
#pragma pack(1)
#endif


/** List CPU state on the system. DEPRECATED.
 *
 * This message indicates the process state of the top 10 heaviest
 * consumers of CPU on the system.
 */
#define SBP_MSG_LINUX_CPU_STATE_DEP_A       0x7F00

typedef struct SBP_ATTR_PACKED {
  u8 index;      /**< sequence of this status message, values from 0-9 */
  u16 pid;        /**< the PID of the process */
  u8 pcpu;       /**< percent of cpu used, expressed as a fraction of 256 */
  char tname[15];  /**< fixed length string representing the thread name */
#ifdef SBP_ENABLE_VARIABLE_SIZED_ARRAYS
  char cmdline[0]; /**< the command line (as much as it fits in the remaining packet) */
#endif
} msg_linux_cpu_state_dep_a_t;
#define MSG_LINUX_CPU_STATE_DEP_A_T_GET_CMDLINE_PTR(msg) (( char *)(msg+1))
#define MSG_LINUX_CPU_STATE_DEP_A_T_GET_CMDLINE_CPTR(msg) ((const char *)(msg+1))
 

/** List memory state on the system. DEPRECATED.
 *
 * This message indicates the process state of the top 10 heaviest
 * consumers of memory on the system.
 */
#define SBP_MSG_LINUX_MEM_STATE_DEP_A       0x7F01

typedef struct SBP_ATTR_PACKED {
  u8 index;      /**< sequence of this status message, values from 0-9 */
  u16 pid;        /**< the PID of the process */
  u8 pmem;       /**< percent of memory used, expressed as a fraction of 256 */
  char tname[15];  /**< fixed length string representing the thread name */
#ifdef SBP_ENABLE_VARIABLE_SIZED_ARRAYS
  char cmdline[0]; /**< the command line (as much as it fits in the remaining packet) */
#endif
} msg_linux_mem_state_dep_a_t;
#define MSG_LINUX_MEM_STATE_DEP_A_T_GET_CMDLINE_PTR(msg) (( char *)(msg+1))
#define MSG_LINUX_MEM_STATE_DEP_A_T_GET_CMDLINE_CPTR(msg) ((const char *)(msg+1))
 

/** CPU, Memory and Process Starts/Stops. DEPRECATED.
 *
 * This presents a summary of CPU and memory utilization.
 */
#define SBP_MSG_LINUX_SYS_STATE_DEP_A       0x7F02

typedef struct SBP_ATTR_PACKED {
  u16 mem_total;         /**< total system memory */
  u8 pcpu;              /**< percent of total cpu currently utilized */
  u8 pmem;              /**< percent of total memory currently utilized */
  u16 procs_starting;    /**< number of processes that started during collection phase */
  u16 procs_stopping;    /**< number of processes that stopped during collection phase */
  u16 pid_count;         /**< the count of processes on the system */
} msg_linux_sys_state_dep_a_t;
 

/** A list of processes with high socket counts
 *
 * Top 10 list of processes with high socket counts.
 */
#define SBP_MSG_LINUX_PROCESS_SOCKET_COUNTS 0x7F03

typedef struct SBP_ATTR_PACKED {
  u8 index;            /**< sequence of this status message, values from 0-9 */
  u16 pid;              /**< the PID of the process in question */
  u16 socket_count;     /**< the number of sockets the process is using */
  u16 socket_types;     /**< A bitfield indicating the socket types used:
  0x1 (tcp), 0x2 (udp), 0x4 (unix stream), 0x8 (unix dgram), 0x10 (netlink),
  and 0x8000 (unknown)
 */
  u16 socket_states;    /**< A bitfield indicating the socket states:
  0x1 (established), 0x2 (syn-sent), 0x4 (syn-recv), 0x8 (fin-wait-1),
  0x10 (fin-wait-2), 0x20 (time-wait), 0x40 (closed), 0x80 (close-wait),
  0x100 (last-ack), 0x200 (listen), 0x400 (closing), 0x800 (unconnected),
  and 0x8000 (unknown)
 */
#ifdef SBP_ENABLE_VARIABLE_SIZED_ARRAYS
  char cmdline[0];       /**< the command line of the process in question */
#endif
} msg_linux_process_socket_counts_t;
#define MSG_LINUX_PROCESS_SOCKET_COUNTS_T_GET_CMDLINE_PTR(msg) (( char *)(msg+1))
#define MSG_LINUX_PROCESS_SOCKET_COUNTS_T_GET_CMDLINE_CPTR(msg) ((const char *)(msg+1))
 

/** A list of processes with deep socket queues
 *
 * Top 10 list of sockets with deep queues.
 */
#define SBP_MSG_LINUX_PROCESS_SOCKET_QUEUES 0x7F04

typedef struct SBP_ATTR_PACKED {
  u8 index;                 /**< sequence of this status message, values from 0-9 */
  u16 pid;                   /**< the PID of the process in question */
  u16 recv_queued;           /**< the total amount of receive data queued for this process */
  u16 send_queued;           /**< the total amount of send data queued for this process */
  u16 socket_types;          /**< A bitfield indicating the socket types used:
  0x1 (tcp), 0x2 (udp), 0x4 (unix stream), 0x8 (unix dgram), 0x10 (netlink),
  and 0x8000 (unknown)
 */
  u16 socket_states;         /**< A bitfield indicating the socket states:
  0x1 (established), 0x2 (syn-sent), 0x4 (syn-recv), 0x8 (fin-wait-1),
  0x10 (fin-wait-2), 0x20 (time-wait), 0x40 (closed), 0x80 (close-wait),
  0x100 (last-ack), 0x200 (listen), 0x400 (closing), 0x800 (unconnected),
  and 0x8000 (unknown)
 */
  char address_of_largest[64]; /**< Address of the largest queue, remote or local depending on the directionality
of the connection.
 */
#ifdef SBP_ENABLE_VARIABLE_SIZED_ARRAYS
  char cmdline[0];            /**< the command line of the process in question */
#endif
} msg_linux_process_socket_queues_t;
#define MSG_LINUX_PROCESS_SOCKET_QUEUES_T_GET_CMDLINE_PTR(msg) (( char *)(msg+1))
#define MSG_LINUX_PROCESS_SOCKET_QUEUES_T_GET_CMDLINE_CPTR(msg) ((const char *)(msg+1))
 

/** Summary of socket usage across the system
 *
 * Summaries the socket usage across the system.
 */
#define SBP_MSG_LINUX_SOCKET_USAGE          0x7F05

typedef struct SBP_ATTR_PACKED {
  u32 avg_queue_depth;        /**< average socket queue depths across all sockets on the system */
  u32 max_queue_depth;        /**< the max queue depth seen within the reporting period */
  u16 socket_state_counts[16]; /**< A count for each socket type reported in the `socket_types_reported` field,
the first entry corresponds to the first enabled bit in `types_reported`.
 */
  u16 socket_type_counts[16]; /**< A count for each socket type reported in the `socket_types_reported` field,
the first entry corresponds to the first enabled bit in `types_reported`.
 */
} msg_linux_socket_usage_t;
 

/** Summary of processes with large amounts of open file descriptors
 *
 * Top 10 list of processes with a large number of open file descriptors.
 */
#define SBP_MSG_LINUX_PROCESS_FD_COUNT      0x7F06

typedef struct SBP_ATTR_PACKED {
  u8 index;       /**< sequence of this status message, values from 0-9 */
  u16 pid;         /**< the PID of the process in question */
  u16 fd_count;    /**< a count of the number of file descriptors opened by the process */
#ifdef SBP_ENABLE_VARIABLE_SIZED_ARRAYS
  char cmdline[0];  /**< the command line of the process in question */
#endif
} msg_linux_process_fd_count_t;
#define MSG_LINUX_PROCESS_FD_COUNT_T_GET_CMDLINE_PTR(msg) (( char *)(msg+1))
#define MSG_LINUX_PROCESS_FD_COUNT_T_GET_CMDLINE_CPTR(msg) ((const char *)(msg+1))
 

/** Summary of open file descriptors on the system
 *
 * Summary of open file descriptors on the system.
 */
#define SBP_MSG_LINUX_PROCESS_FD_SUMMARY    0x7F07

typedef struct SBP_ATTR_PACKED {
  u32 sys_fd_count;    /**< count of total FDs open on the system */
#ifdef SBP_ENABLE_VARIABLE_SIZED_ARRAYS
  char most_opened[0];  /**< A null delimited list of strings which alternates between
a string representation of the process count and the file
name whose count it being reported.  That is, in C string
syntax "32\0/var/log/syslog\012\0/tmp/foo\0" with the end
of the list being 2 NULL terminators in a row.
 */
#endif
} msg_linux_process_fd_summary_t;
#define MSG_LINUX_PROCESS_FD_SUMMARY_T_GET_MOST_OPENED_PTR(msg) (( char *)(msg+1))
#define MSG_LINUX_PROCESS_FD_SUMMARY_T_GET_MOST_OPENED_CPTR(msg) ((const char *)(msg+1))
 

/** List CPU state on the system
 *
 * This message indicates the process state of the top 10 heaviest
 * consumers of CPU on the system, including a timestamp.
 */
#define SBP_MSG_LINUX_CPU_STATE             0x7F08
#define SBP_LINUX_CPU_STATE_TIMESTAMP_TYPE_MASK (0x7)
#define SBP_LINUX_CPU_STATE_TIMESTAMP_TYPE_SHIFT (0u)
#define SBP_LINUX_CPU_STATE_TIMESTAMP_TYPE_GET(flags) \
                             (((flags) >> SBP_LINUX_CPU_STATE_TIMESTAMP_TYPE_SHIFT) \
                             & SBP_LINUX_CPU_STATE_TIMESTAMP_TYPE_MASK)
#define SBP_LINUX_CPU_STATE_TIMESTAMP_TYPE_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_LINUX_CPU_STATE_TIMESTAMP_TYPE_MASK)) \
                             << (SBP_LINUX_CPU_STATE_TIMESTAMP_TYPE_SHIFT)));} while(0)
                             

#define SBP_LINUX_CPU_STATE_TIMESTAMP_TYPE_SYSTEM_TIME_IN_SECONDS (0)
#define SBP_LINUX_CPU_STATE_TIMESTAMP_TYPE_GPS_TOW_IN_MILLISECONDS (1)

typedef struct SBP_ATTR_PACKED {
  u8 index;      /**< sequence of this status message, values from 0-9 */
  u16 pid;        /**< the PID of the process */
  u8 pcpu;       /**< percent of cpu used, expressed as a fraction of 256 */
  u32 time;       /**< timestamp of message, refer to flags field for how to interpret */
  u8 flags;      /**< flags */
  char tname[15];  /**< fixed length string representing the thread name */
#ifdef SBP_ENABLE_VARIABLE_SIZED_ARRAYS
  char cmdline[0]; /**< the command line (as much as it fits in the remaining packet) */
#endif
} msg_linux_cpu_state_t;
#define MSG_LINUX_CPU_STATE_T_GET_CMDLINE_PTR(msg) (( char *)(msg+1))
#define MSG_LINUX_CPU_STATE_T_GET_CMDLINE_CPTR(msg) ((const char *)(msg+1))
 

/** List memory state on the system
 *
 * This message indicates the process state of the top 10 heaviest
 * consumers of memory on the system, including a timestamp.
 */
#define SBP_MSG_LINUX_MEM_STATE             0x7F09
#define SBP_LINUX_MEM_STATE_TIMESTAMP_TYPE_MASK (0x7)
#define SBP_LINUX_MEM_STATE_TIMESTAMP_TYPE_SHIFT (0u)
#define SBP_LINUX_MEM_STATE_TIMESTAMP_TYPE_GET(flags) \
                             (((flags) >> SBP_LINUX_MEM_STATE_TIMESTAMP_TYPE_SHIFT) \
                             & SBP_LINUX_MEM_STATE_TIMESTAMP_TYPE_MASK)
#define SBP_LINUX_MEM_STATE_TIMESTAMP_TYPE_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_LINUX_MEM_STATE_TIMESTAMP_TYPE_MASK)) \
                             << (SBP_LINUX_MEM_STATE_TIMESTAMP_TYPE_SHIFT)));} while(0)
                             

#define SBP_LINUX_MEM_STATE_TIMESTAMP_TYPE_SYSTEM_TIME_IN_SECONDS (0)
#define SBP_LINUX_MEM_STATE_TIMESTAMP_TYPE_GPS_TOW_IN_MILLISECONDS (1)

typedef struct SBP_ATTR_PACKED {
  u8 index;      /**< sequence of this status message, values from 0-9 */
  u16 pid;        /**< the PID of the process */
  u8 pmem;       /**< percent of memory used, expressed as a fraction of 256 */
  u32 time;       /**< timestamp of message, refer to flags field for how to interpret */
  u8 flags;      /**< flags */
  char tname[15];  /**< fixed length string representing the thread name */
#ifdef SBP_ENABLE_VARIABLE_SIZED_ARRAYS
  char cmdline[0]; /**< the command line (as much as it fits in the remaining packet) */
#endif
} msg_linux_mem_state_t;
#define MSG_LINUX_MEM_STATE_T_GET_CMDLINE_PTR(msg) (( char *)(msg+1))
#define MSG_LINUX_MEM_STATE_T_GET_CMDLINE_CPTR(msg) ((const char *)(msg+1))
 

/** CPU, Memory and Process Starts/Stops.
 *
 * This presents a summary of CPU and memory utilization, including a timestamp.
 */
#define SBP_MSG_LINUX_SYS_STATE             0x7F0A
#define SBP_LINUX_SYS_STATE_TIMESTAMP_TYPE_MASK (0x7)
#define SBP_LINUX_SYS_STATE_TIMESTAMP_TYPE_SHIFT (0u)
#define SBP_LINUX_SYS_STATE_TIMESTAMP_TYPE_GET(flags) \
                             (((flags) >> SBP_LINUX_SYS_STATE_TIMESTAMP_TYPE_SHIFT) \
                             & SBP_LINUX_SYS_STATE_TIMESTAMP_TYPE_MASK)
#define SBP_LINUX_SYS_STATE_TIMESTAMP_TYPE_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_LINUX_SYS_STATE_TIMESTAMP_TYPE_MASK)) \
                             << (SBP_LINUX_SYS_STATE_TIMESTAMP_TYPE_SHIFT)));} while(0)
                             

#define SBP_LINUX_SYS_STATE_TIMESTAMP_TYPE_SYSTEM_TIME_IN_SECONDS (0)
#define SBP_LINUX_SYS_STATE_TIMESTAMP_TYPE_GPS_TOW_IN_MILLISECONDS (1)

typedef struct SBP_ATTR_PACKED {
  u16 mem_total;         /**< total system memory */
  u8 pcpu;              /**< percent of total cpu currently utilized */
  u8 pmem;              /**< percent of total memory currently utilized */
  u16 procs_starting;    /**< number of processes that started during collection phase */
  u16 procs_stopping;    /**< number of processes that stopped during collection phase */
  u16 pid_count;         /**< the count of processes on the system */
  u32 time;              /**< timestamp of message, refer to flags field for how to interpret */
  u8 flags;             /**< flags */
} msg_linux_sys_state_t;
 

/** \} */
static inline void static_asserts_for_module_MSG_LINUX_CPU_STATE_DEP_A(void) {
#ifdef __cplusplus
static_assert(offsetof(msg_linux_cpu_state_dep_a_t, index ) == 0, "Offset of index in msg_linux_cpu_state_dep_a_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_linux_cpu_state_dep_a_t, index ) == 0, offset_of_index_in_msg_linux_cpu_state_dep_a_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_linux_cpu_state_dep_a_t, pid ) == 0 + sizeof(u8), "Offset of pid in msg_linux_cpu_state_dep_a_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_linux_cpu_state_dep_a_t, pid ) == 0 + sizeof(u8), offset_of_pid_in_msg_linux_cpu_state_dep_a_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_linux_cpu_state_dep_a_t, pcpu ) == 0 + sizeof(u8) + sizeof(u16), "Offset of pcpu in msg_linux_cpu_state_dep_a_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_linux_cpu_state_dep_a_t, pcpu ) == 0 + sizeof(u8) + sizeof(u16), offset_of_pcpu_in_msg_linux_cpu_state_dep_a_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_linux_cpu_state_dep_a_t, tname ) == 0 + sizeof(u8) + sizeof(u16) + sizeof(u8), "Offset of tname in msg_linux_cpu_state_dep_a_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_linux_cpu_state_dep_a_t, tname ) == 0 + sizeof(u8) + sizeof(u16) + sizeof(u8), offset_of_tname_in_msg_linux_cpu_state_dep_a_t_is_incorrect)
#endif
#ifdef SBP_ENABLE_VARIABLE_SIZED_ARRAYS
#ifdef __cplusplus
static_assert(offsetof(msg_linux_cpu_state_dep_a_t, cmdline ) == 0 + sizeof(u8) + sizeof(u16) + sizeof(u8) + (sizeof(char) * 15), "Offset of cmdline in msg_linux_cpu_state_dep_a_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_linux_cpu_state_dep_a_t, cmdline ) == 0 + sizeof(u8) + sizeof(u16) + sizeof(u8) + (sizeof(char) * 15), offset_of_cmdline_in_msg_linux_cpu_state_dep_a_t_is_incorrect)
#endif
#endif
}

static inline void static_asserts_for_module_MSG_LINUX_MEM_STATE_DEP_A(void) {
#ifdef __cplusplus
static_assert(offsetof(msg_linux_mem_state_dep_a_t, index ) == 0, "Offset of index in msg_linux_mem_state_dep_a_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_linux_mem_state_dep_a_t, index ) == 0, offset_of_index_in_msg_linux_mem_state_dep_a_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_linux_mem_state_dep_a_t, pid ) == 0 + sizeof(u8), "Offset of pid in msg_linux_mem_state_dep_a_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_linux_mem_state_dep_a_t, pid ) == 0 + sizeof(u8), offset_of_pid_in_msg_linux_mem_state_dep_a_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_linux_mem_state_dep_a_t, pmem ) == 0 + sizeof(u8) + sizeof(u16), "Offset of pmem in msg_linux_mem_state_dep_a_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_linux_mem_state_dep_a_t, pmem ) == 0 + sizeof(u8) + sizeof(u16), offset_of_pmem_in_msg_linux_mem_state_dep_a_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_linux_mem_state_dep_a_t, tname ) == 0 + sizeof(u8) + sizeof(u16) + sizeof(u8), "Offset of tname in msg_linux_mem_state_dep_a_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_linux_mem_state_dep_a_t, tname ) == 0 + sizeof(u8) + sizeof(u16) + sizeof(u8), offset_of_tname_in_msg_linux_mem_state_dep_a_t_is_incorrect)
#endif
#ifdef SBP_ENABLE_VARIABLE_SIZED_ARRAYS
#ifdef __cplusplus
static_assert(offsetof(msg_linux_mem_state_dep_a_t, cmdline ) == 0 + sizeof(u8) + sizeof(u16) + sizeof(u8) + (sizeof(char) * 15), "Offset of cmdline in msg_linux_mem_state_dep_a_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_linux_mem_state_dep_a_t, cmdline ) == 0 + sizeof(u8) + sizeof(u16) + sizeof(u8) + (sizeof(char) * 15), offset_of_cmdline_in_msg_linux_mem_state_dep_a_t_is_incorrect)
#endif
#endif
}

static inline void static_asserts_for_module_MSG_LINUX_SYS_STATE_DEP_A(void) {
#ifdef __cplusplus
static_assert(offsetof(msg_linux_sys_state_dep_a_t, mem_total ) == 0, "Offset of mem_total in msg_linux_sys_state_dep_a_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_linux_sys_state_dep_a_t, mem_total ) == 0, offset_of_mem_total_in_msg_linux_sys_state_dep_a_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_linux_sys_state_dep_a_t, pcpu ) == 0 + sizeof(u16), "Offset of pcpu in msg_linux_sys_state_dep_a_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_linux_sys_state_dep_a_t, pcpu ) == 0 + sizeof(u16), offset_of_pcpu_in_msg_linux_sys_state_dep_a_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_linux_sys_state_dep_a_t, pmem ) == 0 + sizeof(u16) + sizeof(u8), "Offset of pmem in msg_linux_sys_state_dep_a_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_linux_sys_state_dep_a_t, pmem ) == 0 + sizeof(u16) + sizeof(u8), offset_of_pmem_in_msg_linux_sys_state_dep_a_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_linux_sys_state_dep_a_t, procs_starting ) == 0 + sizeof(u16) + sizeof(u8) + sizeof(u8), "Offset of procs_starting in msg_linux_sys_state_dep_a_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_linux_sys_state_dep_a_t, procs_starting ) == 0 + sizeof(u16) + sizeof(u8) + sizeof(u8), offset_of_procs_starting_in_msg_linux_sys_state_dep_a_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_linux_sys_state_dep_a_t, procs_stopping ) == 0 + sizeof(u16) + sizeof(u8) + sizeof(u8) + sizeof(u16), "Offset of procs_stopping in msg_linux_sys_state_dep_a_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_linux_sys_state_dep_a_t, procs_stopping ) == 0 + sizeof(u16) + sizeof(u8) + sizeof(u8) + sizeof(u16), offset_of_procs_stopping_in_msg_linux_sys_state_dep_a_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_linux_sys_state_dep_a_t, pid_count ) == 0 + sizeof(u16) + sizeof(u8) + sizeof(u8) + sizeof(u16) + sizeof(u16), "Offset of pid_count in msg_linux_sys_state_dep_a_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_linux_sys_state_dep_a_t, pid_count ) == 0 + sizeof(u16) + sizeof(u8) + sizeof(u8) + sizeof(u16) + sizeof(u16), offset_of_pid_count_in_msg_linux_sys_state_dep_a_t_is_incorrect)
#endif
}

static inline void static_asserts_for_module_MSG_LINUX_PROCESS_SOCKET_COUNTS(void) {
#ifdef __cplusplus
static_assert(offsetof(msg_linux_process_socket_counts_t, index ) == 0, "Offset of index in msg_linux_process_socket_counts_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_linux_process_socket_counts_t, index ) == 0, offset_of_index_in_msg_linux_process_socket_counts_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_linux_process_socket_counts_t, pid ) == 0 + sizeof(u8), "Offset of pid in msg_linux_process_socket_counts_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_linux_process_socket_counts_t, pid ) == 0 + sizeof(u8), offset_of_pid_in_msg_linux_process_socket_counts_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_linux_process_socket_counts_t, socket_count ) == 0 + sizeof(u8) + sizeof(u16), "Offset of socket_count in msg_linux_process_socket_counts_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_linux_process_socket_counts_t, socket_count ) == 0 + sizeof(u8) + sizeof(u16), offset_of_socket_count_in_msg_linux_process_socket_counts_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_linux_process_socket_counts_t, socket_types ) == 0 + sizeof(u8) + sizeof(u16) + sizeof(u16), "Offset of socket_types in msg_linux_process_socket_counts_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_linux_process_socket_counts_t, socket_types ) == 0 + sizeof(u8) + sizeof(u16) + sizeof(u16), offset_of_socket_types_in_msg_linux_process_socket_counts_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_linux_process_socket_counts_t, socket_states ) == 0 + sizeof(u8) + sizeof(u16) + sizeof(u16) + sizeof(u16), "Offset of socket_states in msg_linux_process_socket_counts_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_linux_process_socket_counts_t, socket_states ) == 0 + sizeof(u8) + sizeof(u16) + sizeof(u16) + sizeof(u16), offset_of_socket_states_in_msg_linux_process_socket_counts_t_is_incorrect)
#endif
#ifdef SBP_ENABLE_VARIABLE_SIZED_ARRAYS
#ifdef __cplusplus
static_assert(offsetof(msg_linux_process_socket_counts_t, cmdline ) == 0 + sizeof(u8) + sizeof(u16) + sizeof(u16) + sizeof(u16) + sizeof(u16), "Offset of cmdline in msg_linux_process_socket_counts_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_linux_process_socket_counts_t, cmdline ) == 0 + sizeof(u8) + sizeof(u16) + sizeof(u16) + sizeof(u16) + sizeof(u16), offset_of_cmdline_in_msg_linux_process_socket_counts_t_is_incorrect)
#endif
#endif
}

static inline void static_asserts_for_module_MSG_LINUX_PROCESS_SOCKET_QUEUES(void) {
#ifdef __cplusplus
static_assert(offsetof(msg_linux_process_socket_queues_t, index ) == 0, "Offset of index in msg_linux_process_socket_queues_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_linux_process_socket_queues_t, index ) == 0, offset_of_index_in_msg_linux_process_socket_queues_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_linux_process_socket_queues_t, pid ) == 0 + sizeof(u8), "Offset of pid in msg_linux_process_socket_queues_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_linux_process_socket_queues_t, pid ) == 0 + sizeof(u8), offset_of_pid_in_msg_linux_process_socket_queues_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_linux_process_socket_queues_t, recv_queued ) == 0 + sizeof(u8) + sizeof(u16), "Offset of recv_queued in msg_linux_process_socket_queues_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_linux_process_socket_queues_t, recv_queued ) == 0 + sizeof(u8) + sizeof(u16), offset_of_recv_queued_in_msg_linux_process_socket_queues_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_linux_process_socket_queues_t, send_queued ) == 0 + sizeof(u8) + sizeof(u16) + sizeof(u16), "Offset of send_queued in msg_linux_process_socket_queues_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_linux_process_socket_queues_t, send_queued ) == 0 + sizeof(u8) + sizeof(u16) + sizeof(u16), offset_of_send_queued_in_msg_linux_process_socket_queues_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_linux_process_socket_queues_t, socket_types ) == 0 + sizeof(u8) + sizeof(u16) + sizeof(u16) + sizeof(u16), "Offset of socket_types in msg_linux_process_socket_queues_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_linux_process_socket_queues_t, socket_types ) == 0 + sizeof(u8) + sizeof(u16) + sizeof(u16) + sizeof(u16), offset_of_socket_types_in_msg_linux_process_socket_queues_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_linux_process_socket_queues_t, socket_states ) == 0 + sizeof(u8) + sizeof(u16) + sizeof(u16) + sizeof(u16) + sizeof(u16), "Offset of socket_states in msg_linux_process_socket_queues_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_linux_process_socket_queues_t, socket_states ) == 0 + sizeof(u8) + sizeof(u16) + sizeof(u16) + sizeof(u16) + sizeof(u16), offset_of_socket_states_in_msg_linux_process_socket_queues_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_linux_process_socket_queues_t, address_of_largest ) == 0 + sizeof(u8) + sizeof(u16) + sizeof(u16) + sizeof(u16) + sizeof(u16) + sizeof(u16), "Offset of address_of_largest in msg_linux_process_socket_queues_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_linux_process_socket_queues_t, address_of_largest ) == 0 + sizeof(u8) + sizeof(u16) + sizeof(u16) + sizeof(u16) + sizeof(u16) + sizeof(u16), offset_of_address_of_largest_in_msg_linux_process_socket_queues_t_is_incorrect)
#endif
#ifdef SBP_ENABLE_VARIABLE_SIZED_ARRAYS
#ifdef __cplusplus
static_assert(offsetof(msg_linux_process_socket_queues_t, cmdline ) == 0 + sizeof(u8) + sizeof(u16) + sizeof(u16) + sizeof(u16) + sizeof(u16) + sizeof(u16) + (sizeof(char) * 64), "Offset of cmdline in msg_linux_process_socket_queues_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_linux_process_socket_queues_t, cmdline ) == 0 + sizeof(u8) + sizeof(u16) + sizeof(u16) + sizeof(u16) + sizeof(u16) + sizeof(u16) + (sizeof(char) * 64), offset_of_cmdline_in_msg_linux_process_socket_queues_t_is_incorrect)
#endif
#endif
}

static inline void static_asserts_for_module_MSG_LINUX_SOCKET_USAGE(void) {
#ifdef __cplusplus
static_assert(offsetof(msg_linux_socket_usage_t, avg_queue_depth ) == 0, "Offset of avg_queue_depth in msg_linux_socket_usage_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_linux_socket_usage_t, avg_queue_depth ) == 0, offset_of_avg_queue_depth_in_msg_linux_socket_usage_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_linux_socket_usage_t, max_queue_depth ) == 0 + sizeof(u32), "Offset of max_queue_depth in msg_linux_socket_usage_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_linux_socket_usage_t, max_queue_depth ) == 0 + sizeof(u32), offset_of_max_queue_depth_in_msg_linux_socket_usage_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_linux_socket_usage_t, socket_state_counts ) == 0 + sizeof(u32) + sizeof(u32), "Offset of socket_state_counts in msg_linux_socket_usage_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_linux_socket_usage_t, socket_state_counts ) == 0 + sizeof(u32) + sizeof(u32), offset_of_socket_state_counts_in_msg_linux_socket_usage_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_linux_socket_usage_t, socket_type_counts ) == 0 + sizeof(u32) + sizeof(u32) + (sizeof(u16) * 16), "Offset of socket_type_counts in msg_linux_socket_usage_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_linux_socket_usage_t, socket_type_counts ) == 0 + sizeof(u32) + sizeof(u32) + (sizeof(u16) * 16), offset_of_socket_type_counts_in_msg_linux_socket_usage_t_is_incorrect)
#endif
}

static inline void static_asserts_for_module_MSG_LINUX_PROCESS_FD_COUNT(void) {
#ifdef __cplusplus
static_assert(offsetof(msg_linux_process_fd_count_t, index ) == 0, "Offset of index in msg_linux_process_fd_count_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_linux_process_fd_count_t, index ) == 0, offset_of_index_in_msg_linux_process_fd_count_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_linux_process_fd_count_t, pid ) == 0 + sizeof(u8), "Offset of pid in msg_linux_process_fd_count_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_linux_process_fd_count_t, pid ) == 0 + sizeof(u8), offset_of_pid_in_msg_linux_process_fd_count_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_linux_process_fd_count_t, fd_count ) == 0 + sizeof(u8) + sizeof(u16), "Offset of fd_count in msg_linux_process_fd_count_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_linux_process_fd_count_t, fd_count ) == 0 + sizeof(u8) + sizeof(u16), offset_of_fd_count_in_msg_linux_process_fd_count_t_is_incorrect)
#endif
#ifdef SBP_ENABLE_VARIABLE_SIZED_ARRAYS
#ifdef __cplusplus
static_assert(offsetof(msg_linux_process_fd_count_t, cmdline ) == 0 + sizeof(u8) + sizeof(u16) + sizeof(u16), "Offset of cmdline in msg_linux_process_fd_count_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_linux_process_fd_count_t, cmdline ) == 0 + sizeof(u8) + sizeof(u16) + sizeof(u16), offset_of_cmdline_in_msg_linux_process_fd_count_t_is_incorrect)
#endif
#endif
}

static inline void static_asserts_for_module_MSG_LINUX_PROCESS_FD_SUMMARY(void) {
#ifdef __cplusplus
static_assert(offsetof(msg_linux_process_fd_summary_t, sys_fd_count ) == 0, "Offset of sys_fd_count in msg_linux_process_fd_summary_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_linux_process_fd_summary_t, sys_fd_count ) == 0, offset_of_sys_fd_count_in_msg_linux_process_fd_summary_t_is_incorrect)
#endif
#ifdef SBP_ENABLE_VARIABLE_SIZED_ARRAYS
#ifdef __cplusplus
static_assert(offsetof(msg_linux_process_fd_summary_t, most_opened ) == 0 + sizeof(u32), "Offset of most_opened in msg_linux_process_fd_summary_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_linux_process_fd_summary_t, most_opened ) == 0 + sizeof(u32), offset_of_most_opened_in_msg_linux_process_fd_summary_t_is_incorrect)
#endif
#endif
}

static inline void static_asserts_for_module_MSG_LINUX_CPU_STATE(void) {
#ifdef __cplusplus
static_assert(offsetof(msg_linux_cpu_state_t, index ) == 0, "Offset of index in msg_linux_cpu_state_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_linux_cpu_state_t, index ) == 0, offset_of_index_in_msg_linux_cpu_state_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_linux_cpu_state_t, pid ) == 0 + sizeof(u8), "Offset of pid in msg_linux_cpu_state_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_linux_cpu_state_t, pid ) == 0 + sizeof(u8), offset_of_pid_in_msg_linux_cpu_state_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_linux_cpu_state_t, pcpu ) == 0 + sizeof(u8) + sizeof(u16), "Offset of pcpu in msg_linux_cpu_state_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_linux_cpu_state_t, pcpu ) == 0 + sizeof(u8) + sizeof(u16), offset_of_pcpu_in_msg_linux_cpu_state_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_linux_cpu_state_t, time ) == 0 + sizeof(u8) + sizeof(u16) + sizeof(u8), "Offset of time in msg_linux_cpu_state_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_linux_cpu_state_t, time ) == 0 + sizeof(u8) + sizeof(u16) + sizeof(u8), offset_of_time_in_msg_linux_cpu_state_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_linux_cpu_state_t, flags ) == 0 + sizeof(u8) + sizeof(u16) + sizeof(u8) + sizeof(u32), "Offset of flags in msg_linux_cpu_state_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_linux_cpu_state_t, flags ) == 0 + sizeof(u8) + sizeof(u16) + sizeof(u8) + sizeof(u32), offset_of_flags_in_msg_linux_cpu_state_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_linux_cpu_state_t, tname ) == 0 + sizeof(u8) + sizeof(u16) + sizeof(u8) + sizeof(u32) + sizeof(u8), "Offset of tname in msg_linux_cpu_state_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_linux_cpu_state_t, tname ) == 0 + sizeof(u8) + sizeof(u16) + sizeof(u8) + sizeof(u32) + sizeof(u8), offset_of_tname_in_msg_linux_cpu_state_t_is_incorrect)
#endif
#ifdef SBP_ENABLE_VARIABLE_SIZED_ARRAYS
#ifdef __cplusplus
static_assert(offsetof(msg_linux_cpu_state_t, cmdline ) == 0 + sizeof(u8) + sizeof(u16) + sizeof(u8) + sizeof(u32) + sizeof(u8) + (sizeof(char) * 15), "Offset of cmdline in msg_linux_cpu_state_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_linux_cpu_state_t, cmdline ) == 0 + sizeof(u8) + sizeof(u16) + sizeof(u8) + sizeof(u32) + sizeof(u8) + (sizeof(char) * 15), offset_of_cmdline_in_msg_linux_cpu_state_t_is_incorrect)
#endif
#endif
}

static inline void static_asserts_for_module_MSG_LINUX_MEM_STATE(void) {
#ifdef __cplusplus
static_assert(offsetof(msg_linux_mem_state_t, index ) == 0, "Offset of index in msg_linux_mem_state_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_linux_mem_state_t, index ) == 0, offset_of_index_in_msg_linux_mem_state_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_linux_mem_state_t, pid ) == 0 + sizeof(u8), "Offset of pid in msg_linux_mem_state_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_linux_mem_state_t, pid ) == 0 + sizeof(u8), offset_of_pid_in_msg_linux_mem_state_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_linux_mem_state_t, pmem ) == 0 + sizeof(u8) + sizeof(u16), "Offset of pmem in msg_linux_mem_state_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_linux_mem_state_t, pmem ) == 0 + sizeof(u8) + sizeof(u16), offset_of_pmem_in_msg_linux_mem_state_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_linux_mem_state_t, time ) == 0 + sizeof(u8) + sizeof(u16) + sizeof(u8), "Offset of time in msg_linux_mem_state_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_linux_mem_state_t, time ) == 0 + sizeof(u8) + sizeof(u16) + sizeof(u8), offset_of_time_in_msg_linux_mem_state_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_linux_mem_state_t, flags ) == 0 + sizeof(u8) + sizeof(u16) + sizeof(u8) + sizeof(u32), "Offset of flags in msg_linux_mem_state_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_linux_mem_state_t, flags ) == 0 + sizeof(u8) + sizeof(u16) + sizeof(u8) + sizeof(u32), offset_of_flags_in_msg_linux_mem_state_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_linux_mem_state_t, tname ) == 0 + sizeof(u8) + sizeof(u16) + sizeof(u8) + sizeof(u32) + sizeof(u8), "Offset of tname in msg_linux_mem_state_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_linux_mem_state_t, tname ) == 0 + sizeof(u8) + sizeof(u16) + sizeof(u8) + sizeof(u32) + sizeof(u8), offset_of_tname_in_msg_linux_mem_state_t_is_incorrect)
#endif
#ifdef SBP_ENABLE_VARIABLE_SIZED_ARRAYS
#ifdef __cplusplus
static_assert(offsetof(msg_linux_mem_state_t, cmdline ) == 0 + sizeof(u8) + sizeof(u16) + sizeof(u8) + sizeof(u32) + sizeof(u8) + (sizeof(char) * 15), "Offset of cmdline in msg_linux_mem_state_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_linux_mem_state_t, cmdline ) == 0 + sizeof(u8) + sizeof(u16) + sizeof(u8) + sizeof(u32) + sizeof(u8) + (sizeof(char) * 15), offset_of_cmdline_in_msg_linux_mem_state_t_is_incorrect)
#endif
#endif
}

static inline void static_asserts_for_module_MSG_LINUX_SYS_STATE(void) {
#ifdef __cplusplus
static_assert(offsetof(msg_linux_sys_state_t, mem_total ) == 0, "Offset of mem_total in msg_linux_sys_state_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_linux_sys_state_t, mem_total ) == 0, offset_of_mem_total_in_msg_linux_sys_state_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_linux_sys_state_t, pcpu ) == 0 + sizeof(u16), "Offset of pcpu in msg_linux_sys_state_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_linux_sys_state_t, pcpu ) == 0 + sizeof(u16), offset_of_pcpu_in_msg_linux_sys_state_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_linux_sys_state_t, pmem ) == 0 + sizeof(u16) + sizeof(u8), "Offset of pmem in msg_linux_sys_state_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_linux_sys_state_t, pmem ) == 0 + sizeof(u16) + sizeof(u8), offset_of_pmem_in_msg_linux_sys_state_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_linux_sys_state_t, procs_starting ) == 0 + sizeof(u16) + sizeof(u8) + sizeof(u8), "Offset of procs_starting in msg_linux_sys_state_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_linux_sys_state_t, procs_starting ) == 0 + sizeof(u16) + sizeof(u8) + sizeof(u8), offset_of_procs_starting_in_msg_linux_sys_state_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_linux_sys_state_t, procs_stopping ) == 0 + sizeof(u16) + sizeof(u8) + sizeof(u8) + sizeof(u16), "Offset of procs_stopping in msg_linux_sys_state_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_linux_sys_state_t, procs_stopping ) == 0 + sizeof(u16) + sizeof(u8) + sizeof(u8) + sizeof(u16), offset_of_procs_stopping_in_msg_linux_sys_state_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_linux_sys_state_t, pid_count ) == 0 + sizeof(u16) + sizeof(u8) + sizeof(u8) + sizeof(u16) + sizeof(u16), "Offset of pid_count in msg_linux_sys_state_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_linux_sys_state_t, pid_count ) == 0 + sizeof(u16) + sizeof(u8) + sizeof(u8) + sizeof(u16) + sizeof(u16), offset_of_pid_count_in_msg_linux_sys_state_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_linux_sys_state_t, time ) == 0 + sizeof(u16) + sizeof(u8) + sizeof(u8) + sizeof(u16) + sizeof(u16) + sizeof(u16), "Offset of time in msg_linux_sys_state_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_linux_sys_state_t, time ) == 0 + sizeof(u16) + sizeof(u8) + sizeof(u8) + sizeof(u16) + sizeof(u16) + sizeof(u16), offset_of_time_in_msg_linux_sys_state_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_linux_sys_state_t, flags ) == 0 + sizeof(u16) + sizeof(u8) + sizeof(u8) + sizeof(u16) + sizeof(u16) + sizeof(u16) + sizeof(u32), "Offset of flags in msg_linux_sys_state_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_linux_sys_state_t, flags ) == 0 + sizeof(u16) + sizeof(u8) + sizeof(u8) + sizeof(u16) + sizeof(u16) + sizeof(u16) + sizeof(u32), offset_of_flags_in_msg_linux_sys_state_t_is_incorrect)
#endif
}


#ifdef __ghs__
#pragma pack()
#endif
SBP_PACK_END

#endif /* LIBSBP_LINUX_MESSAGES_H */
