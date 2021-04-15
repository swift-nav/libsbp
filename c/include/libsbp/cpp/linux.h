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
 * Automatically generated from yaml/swiftnav/sbp/linux.yaml
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

#ifndef LIBSBP_CPP_LINUX_MESSAGES_H
#define LIBSBP_CPP_LINUX_MESSAGES_H

#include <cstddef>
#include <libsbp/common.h>
#include <libsbp/sbp.h>

namespace sbp {
  
  /**
   * List CPU state on the system. DEPRECATED.
   *
   * This message indicates the process state of the top 10 heaviest
   * consumers of CPU on the system.
   */
  constexpr u16 MSG_LINUX_CPU_STATE_DEP_A = 0x7F00;

  template<size_t CMDLINE_COUNT = (SBP_MAX_PAYLOAD_LEN - sizeof(u8) + sizeof(u16) + sizeof(u8) + sizeof(char) + 0) / sizeof(char)>
  struct SBP_ATTR_PACKED MsgLinuxCpuStateDepA {
    u8 index /** sequence of this status message, values from 0-9 */
    u16 pid /** the PID of the process */
    u8 pcpu /** percent of cpu used, expressed as a fraction of 256 */
    char tname[15]; /** fixed length string representing the thread name */
    char cmdline[CMDLINE_COUNT]; /** the command line (as much as it fits in the remaining packet) */
  };

  
  /**
   * List memory state on the system. DEPRECATED.
   *
   * This message indicates the process state of the top 10 heaviest
   * consumers of memory on the system.
   */
  constexpr u16 MSG_LINUX_MEM_STATE_DEP_A = 0x7F01;

  template<size_t CMDLINE_COUNT = (SBP_MAX_PAYLOAD_LEN - sizeof(u8) + sizeof(u16) + sizeof(u8) + sizeof(char) + 0) / sizeof(char)>
  struct SBP_ATTR_PACKED MsgLinuxMemStateDepA {
    u8 index /** sequence of this status message, values from 0-9 */
    u16 pid /** the PID of the process */
    u8 pmem /** percent of memory used, expressed as a fraction of 256 */
    char tname[15]; /** fixed length string representing the thread name */
    char cmdline[CMDLINE_COUNT]; /** the command line (as much as it fits in the remaining packet) */
  };

  
  /**
   * CPU, Memory and Process Starts/Stops. DEPRECATED.
   *
   * This presents a summary of CPU and memory utilization.
   */
  constexpr u16 MSG_LINUX_SYS_STATE_DEP_A = 0x7F02;

  
  struct SBP_ATTR_PACKED MsgLinuxSysStateDepA {
    u16 mem_total /** total system memory */
    u8 pcpu /** percent of total cpu currently utilized */
    u8 pmem /** percent of total memory currently utilized */
    u16 procs_starting /** number of processes that started during collection phase */
    u16 procs_stopping /** number of processes that stopped during collection phase */
    u16 pid_count /** the count of processes on the system */
  };

  
  /**
   * A list of processes with high socket counts
   *
   * Top 10 list of processes with high socket counts.
   */
  constexpr u16 MSG_LINUX_PROCESS_SOCKET_COUNTS = 0x7F03;

  template<size_t CMDLINE_COUNT = (SBP_MAX_PAYLOAD_LEN - sizeof(u8) + sizeof(u16) + sizeof(u16) + sizeof(u16) + sizeof(u16) + 0) / sizeof(char)>
  struct SBP_ATTR_PACKED MsgLinuxProcessSocketCounts {
    u8 index /** sequence of this status message, values from 0-9 */
    u16 pid /** the PID of the process in question */
    u16 socket_count /** the number of sockets the process is using */
    u16 socket_types /** A bitfield indicating the socket types used:
  0x1 (tcp), 0x2 (udp), 0x4 (unix stream), 0x8 (unix dgram), 0x10 (netlink),
  and 0x8000 (unknown)
 */
    u16 socket_states /** A bitfield indicating the socket states:
  0x1 (established), 0x2 (syn-sent), 0x4 (syn-recv), 0x8 (fin-wait-1),
  0x10 (fin-wait-2), 0x20 (time-wait), 0x40 (closed), 0x80 (close-wait),
  0x100 (last-ack), 0x200 (listen), 0x400 (closing), 0x800 (unconnected),
  and 0x8000 (unknown)
 */
    char cmdline[CMDLINE_COUNT]; /** the command line of the process in question */
  };

  
  /**
   * A list of processes with deep socket queues
   *
   * Top 10 list of sockets with deep queues.
   */
  constexpr u16 MSG_LINUX_PROCESS_SOCKET_QUEUES = 0x7F04;

  template<size_t CMDLINE_COUNT = (SBP_MAX_PAYLOAD_LEN - sizeof(u8) + sizeof(u16) + sizeof(u16) + sizeof(u16) + sizeof(u16) + sizeof(u16) + sizeof(char) + 0) / sizeof(char)>
  struct SBP_ATTR_PACKED MsgLinuxProcessSocketQueues {
    u8 index /** sequence of this status message, values from 0-9 */
    u16 pid /** the PID of the process in question */
    u16 recv_queued /** the total amount of receive data queued for this process */
    u16 send_queued /** the total amount of send data queued for this process */
    u16 socket_types /** A bitfield indicating the socket types used:
  0x1 (tcp), 0x2 (udp), 0x4 (unix stream), 0x8 (unix dgram), 0x10 (netlink),
  and 0x8000 (unknown)
 */
    u16 socket_states /** A bitfield indicating the socket states:
  0x1 (established), 0x2 (syn-sent), 0x4 (syn-recv), 0x8 (fin-wait-1),
  0x10 (fin-wait-2), 0x20 (time-wait), 0x40 (closed), 0x80 (close-wait),
  0x100 (last-ack), 0x200 (listen), 0x400 (closing), 0x800 (unconnected),
  and 0x8000 (unknown)
 */
    char address_of_largest[64]; /** Address of the largest queue, remote or local depending on the directionality
of the connection.
 */
    char cmdline[CMDLINE_COUNT]; /** the command line of the process in question */
  };

  
  /**
   * Summary of socket usage across the system
   *
   * Summaries the socket usage across the system.
   */
  constexpr u16 MSG_LINUX_SOCKET_USAGE = 0x7F05;

  
  struct SBP_ATTR_PACKED MsgLinuxSocketUsage {
    u32 avg_queue_depth /** average socket queue depths across all sockets on the system */
    u32 max_queue_depth /** the max queue depth seen within the reporting period */
    u16 socket_state_counts[16]; /** A count for each socket type reported in the `socket_types_reported` field,
the first entry corresponds to the first enabled bit in `types_reported`.
 */
    u16 socket_type_counts[16]; /** A count for each socket type reported in the `socket_types_reported` field,
the first entry corresponds to the first enabled bit in `types_reported`.
 */
  };

  
  /**
   * Summary of processes with large amounts of open file descriptors
   *
   * Top 10 list of processes with a large number of open file descriptors.
   */
  constexpr u16 MSG_LINUX_PROCESS_FD_COUNT = 0x7F06;

  template<size_t CMDLINE_COUNT = (SBP_MAX_PAYLOAD_LEN - sizeof(u8) + sizeof(u16) + sizeof(u16) + 0) / sizeof(char)>
  struct SBP_ATTR_PACKED MsgLinuxProcessFdCount {
    u8 index /** sequence of this status message, values from 0-9 */
    u16 pid /** the PID of the process in question */
    u16 fd_count /** a count of the number of file descriptors opened by the process */
    char cmdline[CMDLINE_COUNT]; /** the command line of the process in question */
  };

  
  /**
   * Summary of open file descriptors on the system
   *
   * Summary of open file descriptors on the system.
   */
  constexpr u16 MSG_LINUX_PROCESS_FD_SUMMARY = 0x7F07;

  template<size_t MOST_OPENED_COUNT = (SBP_MAX_PAYLOAD_LEN - sizeof(u32) + 0) / sizeof(char)>
  struct SBP_ATTR_PACKED MsgLinuxProcessFdSummary {
    u32 sys_fd_count /** count of total FDs open on the system */
    char most_opened[MOST_OPENED_COUNT]; /** A null delimited list of strings which alternates between
a string representation of the process count and the file
name whose count it being reported.  That is, in C string
syntax "32\0/var/log/syslog\012\0/tmp/foo\0" with the end
of the list being 2 NULL terminators in a row.
 */
  };

  
  /**
   * List CPU state on the system
   *
   * This message indicates the process state of the top 10 heaviest
   * consumers of CPU on the system, including a timestamp.
   */
  constexpr u16 MSG_LINUX_CPU_STATE = 0x7F08;

  template<size_t CMDLINE_COUNT = (SBP_MAX_PAYLOAD_LEN - sizeof(u8) + sizeof(u16) + sizeof(u8) + sizeof(u32) + sizeof(u8) + sizeof(char) + 0) / sizeof(char)>
  struct SBP_ATTR_PACKED MsgLinuxCpuState {
    u8 index /** sequence of this status message, values from 0-9 */
    u16 pid /** the PID of the process */
    u8 pcpu /** percent of cpu used, expressed as a fraction of 256 */
    u32 time /** timestamp of message, refer to flags field for how to interpret */
    u8 flags /** flags */
    char tname[15]; /** fixed length string representing the thread name */
    char cmdline[CMDLINE_COUNT]; /** the command line (as much as it fits in the remaining packet) */
  };

  
  /**
   * List memory state on the system
   *
   * This message indicates the process state of the top 10 heaviest
   * consumers of memory on the system, including a timestamp.
   */
  constexpr u16 MSG_LINUX_MEM_STATE = 0x7F09;

  template<size_t CMDLINE_COUNT = (SBP_MAX_PAYLOAD_LEN - sizeof(u8) + sizeof(u16) + sizeof(u8) + sizeof(u32) + sizeof(u8) + sizeof(char) + 0) / sizeof(char)>
  struct SBP_ATTR_PACKED MsgLinuxMemState {
    u8 index /** sequence of this status message, values from 0-9 */
    u16 pid /** the PID of the process */
    u8 pmem /** percent of memory used, expressed as a fraction of 256 */
    u32 time /** timestamp of message, refer to flags field for how to interpret */
    u8 flags /** flags */
    char tname[15]; /** fixed length string representing the thread name */
    char cmdline[CMDLINE_COUNT]; /** the command line (as much as it fits in the remaining packet) */
  };

  
  /**
   * CPU, Memory and Process Starts/Stops.
   *
   * This presents a summary of CPU and memory utilization, including a timestamp.
   */
  constexpr u16 MSG_LINUX_SYS_STATE = 0x7F0A;

  
  struct SBP_ATTR_PACKED MsgLinuxSysState {
    u16 mem_total /** total system memory, in MiB */
    u8 pcpu /** percent of total cpu currently utilized */
    u8 pmem /** percent of total memory currently utilized */
    u16 procs_starting /** number of processes that started during collection phase */
    u16 procs_stopping /** number of processes that stopped during collection phase */
    u16 pid_count /** the count of processes on the system */
    u32 time /** timestamp of message, refer to flags field for how to interpret */
    u8 flags /** flags */
  };

  

}  // namespace sbp

#endif /* LIBSBP_CPP_LINUX_MESSAGES_H */