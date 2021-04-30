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

#ifndef LIBSBP_PACKED_LINUX_MESSAGES_H
#define LIBSBP_PACKED_LINUX_MESSAGES_H

#include <libsbp/common.h>

SBP_PACK_START


/** List CPU state on the system. DEPRECATED.
 *
 * This message indicates the process state of the top 10 heaviest
 * consumers of CPU on the system.
 */
#define SBP_MSG_LINUX_CPU_STATE_DEP_A       0x7F00
typedef struct SBP_ATTR_PACKED {
  
  /** 
   * sequence of this status message, values from 0-9 
   */
  u8 index;     
  
  /** 
   * the PID of the process 
   */
  u16 pid;       
  
  /** 
   * percent of cpu used, expressed as a fraction of 256 
   */
  u8 pcpu;      
  
  /** 
   * fixed length string representing the thread name 
   */
  char tname[15]; 
  
  /** 
   * the command line (as much as it fits in the remaining packet) 
   */
  char cmdline[0];
  
} msg_linux_cpu_state_dep_a_t;


/** List memory state on the system. DEPRECATED.
 *
 * This message indicates the process state of the top 10 heaviest
 * consumers of memory on the system.
 */
#define SBP_MSG_LINUX_MEM_STATE_DEP_A       0x7F01
typedef struct SBP_ATTR_PACKED {
  
  /** 
   * sequence of this status message, values from 0-9 
   */
  u8 index;     
  
  /** 
   * the PID of the process 
   */
  u16 pid;       
  
  /** 
   * percent of memory used, expressed as a fraction of 256 
   */
  u8 pmem;      
  
  /** 
   * fixed length string representing the thread name 
   */
  char tname[15]; 
  
  /** 
   * the command line (as much as it fits in the remaining packet) 
   */
  char cmdline[0];
  
} msg_linux_mem_state_dep_a_t;


/** CPU, Memory and Process Starts/Stops. DEPRECATED.
 *
 * This presents a summary of CPU and memory utilization.
 */
#define SBP_MSG_LINUX_SYS_STATE_DEP_A       0x7F02
typedef struct SBP_ATTR_PACKED {
  
  /** 
   * total system memory 
   */
  u16 mem_total;        
  
  /** 
   * percent of total cpu currently utilized 
   */
  u8 pcpu;             
  
  /** 
   * percent of total memory currently utilized 
   */
  u8 pmem;             
  
  /** 
   * number of processes that started during collection phase 
   */
  u16 procs_starting;   
  
  /** 
   * number of processes that stopped during collection phase 
   */
  u16 procs_stopping;   
  
  /** 
   * the count of processes on the system 
   */
  u16 pid_count;        
  
} msg_linux_sys_state_dep_a_t;


/** A list of processes with high socket counts
 *
 * Top 10 list of processes with high socket counts.
 */
#define SBP_MSG_LINUX_PROCESS_SOCKET_COUNTS 0x7F03
typedef struct SBP_ATTR_PACKED {
  
  /** 
   * sequence of this status message, values from 0-9 
   */
  u8 index;           
  
  /** 
   * the PID of the process in question 
   */
  u16 pid;             
  
  /** 
   * the number of sockets the process is using 
   */
  u16 socket_count;    
  
  /** 
    * A bitfield indicating the socket types used:
 *   0x1 (tcp), 0x2 (udp), 0x4 (unix stream), 0x8 (unix dgram), 0x10 (netlink),
 *   and 0x8000 (unknown) 
   */
  u16 socket_types;    
  
  /** 
    * A bitfield indicating the socket states:
 *   0x1 (established), 0x2 (syn-sent), 0x4 (syn-recv), 0x8 (fin-wait-1),
 *   0x10 (fin-wait-2), 0x20 (time-wait), 0x40 (closed), 0x80 (close-wait),
 *   0x100 (last-ack), 0x200 (listen), 0x400 (closing), 0x800 (unconnected),
 *   and 0x8000 (unknown) 
   */
  u16 socket_states;   
  
  /** 
   * the command line of the process in question 
   */
  char cmdline[0];      
  
} msg_linux_process_socket_counts_t;


/** A list of processes with deep socket queues
 *
 * Top 10 list of sockets with deep queues.
 */
#define SBP_MSG_LINUX_PROCESS_SOCKET_QUEUES 0x7F04
typedef struct SBP_ATTR_PACKED {
  
  /** 
   * sequence of this status message, values from 0-9 
   */
  u8 index;                
  
  /** 
   * the PID of the process in question 
   */
  u16 pid;                  
  
  /** 
   * the total amount of receive data queued for this process 
   */
  u16 recv_queued;          
  
  /** 
   * the total amount of send data queued for this process 
   */
  u16 send_queued;          
  
  /** 
    * A bitfield indicating the socket types used:
 *   0x1 (tcp), 0x2 (udp), 0x4 (unix stream), 0x8 (unix dgram), 0x10 (netlink),
 *   and 0x8000 (unknown) 
   */
  u16 socket_types;         
  
  /** 
    * A bitfield indicating the socket states:
 *   0x1 (established), 0x2 (syn-sent), 0x4 (syn-recv), 0x8 (fin-wait-1),
 *   0x10 (fin-wait-2), 0x20 (time-wait), 0x40 (closed), 0x80 (close-wait),
 *   0x100 (last-ack), 0x200 (listen), 0x400 (closing), 0x800 (unconnected),
 *   and 0x8000 (unknown) 
   */
  u16 socket_states;        
  
  /** 
    * Address of the largest queue, remote or local depending on the directionality
 * of the connection. 
   */
  char address_of_largest[64];
  
  /** 
   * the command line of the process in question 
   */
  char cmdline[0];           
  
} msg_linux_process_socket_queues_t;


/** Summary of socket usage across the system
 *
 * Summaries the socket usage across the system.
 */
#define SBP_MSG_LINUX_SOCKET_USAGE          0x7F05
typedef struct SBP_ATTR_PACKED {
  
  /** 
   * average socket queue depths across all sockets on the system 
   */
  u32 avg_queue_depth;       
  
  /** 
   * the max queue depth seen within the reporting period 
   */
  u32 max_queue_depth;       
  
  /** 
    * A count for each socket type reported in the `socket_types_reported` field,
 * the first entry corresponds to the first enabled bit in `types_reported`. 
   */
  u16 socket_state_counts[16];
  
  /** 
    * A count for each socket type reported in the `socket_types_reported` field,
 * the first entry corresponds to the first enabled bit in `types_reported`. 
   */
  u16 socket_type_counts[16];
  
} msg_linux_socket_usage_t;


/** Summary of processes with large amounts of open file descriptors
 *
 * Top 10 list of processes with a large number of open file descriptors.
 */
#define SBP_MSG_LINUX_PROCESS_FD_COUNT      0x7F06
typedef struct SBP_ATTR_PACKED {
  
  /** 
   * sequence of this status message, values from 0-9 
   */
  u8 index;      
  
  /** 
   * the PID of the process in question 
   */
  u16 pid;        
  
  /** 
   * a count of the number of file descriptors opened by the process 
   */
  u16 fd_count;   
  
  /** 
   * the command line of the process in question 
   */
  char cmdline[0]; 
  
} msg_linux_process_fd_count_t;


/** Summary of open file descriptors on the system
 *
 * Summary of open file descriptors on the system.
 */
#define SBP_MSG_LINUX_PROCESS_FD_SUMMARY    0x7F07
typedef struct SBP_ATTR_PACKED {
  
  /** 
   * count of total FDs open on the system 
   */
  u32 sys_fd_count;   
  
  /** 
    * A null delimited list of strings which alternates between
 * a string representation of the process count and the file
 * name whose count it being reported.  That is, in C string
 * syntax "32\0/var/log/syslog\012\0/tmp/foo\0" with the end
 * of the list being 2 NULL terminators in a row. 
   */
  char most_opened[0]; 
  
} msg_linux_process_fd_summary_t;


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
/** List CPU state on the system
 *
 * This message indicates the process state of the top 10 heaviest
 * consumers of CPU on the system, including a timestamp.
 */
#define SBP_MSG_LINUX_CPU_STATE             0x7F08
typedef struct SBP_ATTR_PACKED {
  
  /** 
   * sequence of this status message, values from 0-9 
   */
  u8 index;     
  
  /** 
   * the PID of the process 
   */
  u16 pid;       
  
  /** 
   * percent of CPU used, expressed as a fraction of 256 
   */
  u8 pcpu;      
  
  /** 
   * timestamp of message, refer to flags field for how to interpret 
   */
  u32 time;      
  
  /** 
   * flags 
   */
  u8 flags;     
  
  /** 
   * fixed length string representing the thread name 
   */
  char tname[15]; 
  
  /** 
   * the command line (as much as it fits in the remaining packet) 
   */
  char cmdline[0];
  
} msg_linux_cpu_state_t;


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
/** List memory state on the system
 *
 * This message indicates the process state of the top 10 heaviest
 * consumers of memory on the system, including a timestamp.
 */
#define SBP_MSG_LINUX_MEM_STATE             0x7F09
typedef struct SBP_ATTR_PACKED {
  
  /** 
   * sequence of this status message, values from 0-9 
   */
  u8 index;     
  
  /** 
   * the PID of the process 
   */
  u16 pid;       
  
  /** 
   * percent of memory used, expressed as a fraction of 256 
   */
  u8 pmem;      
  
  /** 
   * timestamp of message, refer to flags field for how to interpret 
   */
  u32 time;      
  
  /** 
   * flags 
   */
  u8 flags;     
  
  /** 
   * fixed length string representing the thread name 
   */
  char tname[15]; 
  
  /** 
   * the command line (as much as it fits in the remaining packet) 
   */
  char cmdline[0];
  
} msg_linux_mem_state_t;


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
/** CPU, Memory and Process Starts/Stops.
 *
 * This presents a summary of CPU and memory utilization, including a timestamp.
 */
#define SBP_MSG_LINUX_SYS_STATE             0x7F0A
typedef struct SBP_ATTR_PACKED {
  
  /** 
   * total system memory, in MiB 
   */
  u16 mem_total;        
  
  /** 
   * percent of CPU used, expressed as a fraction of 256 
   */
  u8 pcpu;             
  
  /** 
   * percent of memory used, expressed as a fraction of 256 
   */
  u8 pmem;             
  
  /** 
   * number of processes that started during collection phase 
   */
  u16 procs_starting;   
  
  /** 
   * number of processes that stopped during collection phase 
   */
  u16 procs_stopping;   
  
  /** 
   * the count of processes on the system 
   */
  u16 pid_count;        
  
  /** 
   * timestamp of message, refer to flags field for how to interpret 
   */
  u32 time;             
  
  /** 
   * flags 
   */
  u8 flags;            
  
} msg_linux_sys_state_t;


/** \} */

SBP_PACK_END

#endif /* LIBSBP_LINUX_MESSAGES_H */