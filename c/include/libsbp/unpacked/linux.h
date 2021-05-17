#ifndef LIBSBP_LINUX_MESSAGES_H
#define LIBSBP_LINUX_MESSAGES_H

#include <stdbool.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>
#include <endian.h>
#include <math.h>

#include <libsbp/common.h>
#include <libsbp/string.h>
/** List CPU state on the system. DEPRECATED.
 *
((m.desc|commentify)))
 */
#define SBP_MSG_LINUX_CPU_STATE_DEP_A       0x7F00
typedef struct {
  u8 index;
  u16 pid;
  u8 pcpu;
  char tname[15];
  sbp_unterminated_string_t cmdline;
} sbp_msg_linux_cpu_state_dep_a_t;


/** List memory state on the system. DEPRECATED.
 *
((m.desc|commentify)))
 */
#define SBP_MSG_LINUX_MEM_STATE_DEP_A       0x7F01
typedef struct {
  u8 index;
  u16 pid;
  u8 pmem;
  char tname[15];
  sbp_unterminated_string_t cmdline;
} sbp_msg_linux_mem_state_dep_a_t;


/** CPU, Memory and Process Starts/Stops. DEPRECATED.
 *
((m.desc|commentify)))
 */
#define SBP_MSG_LINUX_SYS_STATE_DEP_A       0x7F02
typedef struct {
  u16 mem_total;
  u8 pcpu;
  u8 pmem;
  u16 procs_starting;
  u16 procs_stopping;
  u16 pid_count;
} sbp_msg_linux_sys_state_dep_a_t;


/** A list of processes with high socket counts
 *
((m.desc|commentify)))
 */
#define SBP_MSG_LINUX_PROCESS_SOCKET_COUNTS 0x7F03
typedef struct {
  u8 index;
  u16 pid;
  u16 socket_count;
  u16 socket_types;
  u16 socket_states;
  sbp_unterminated_string_t cmdline;
} sbp_msg_linux_process_socket_counts_t;


/** A list of processes with deep socket queues
 *
((m.desc|commentify)))
 */
#define SBP_MSG_LINUX_PROCESS_SOCKET_QUEUES 0x7F04
typedef struct {
  u8 index;
  u16 pid;
  u16 recv_queued;
  u16 send_queued;
  u16 socket_types;
  u16 socket_states;
  char address_of_largest[64];
  sbp_unterminated_string_t cmdline;
} sbp_msg_linux_process_socket_queues_t;


/** Summary of socket usage across the system
 *
((m.desc|commentify)))
 */
#define SBP_MSG_LINUX_SOCKET_USAGE          0x7F05
typedef struct {
  u32 avg_queue_depth;
  u32 max_queue_depth;
  u16 socket_state_counts[16];
  u16 socket_type_counts[16];
} sbp_msg_linux_socket_usage_t;


/** Summary of processes with large amounts of open file descriptors
 *
((m.desc|commentify)))
 */
#define SBP_MSG_LINUX_PROCESS_FD_COUNT      0x7F06
typedef struct {
  u8 index;
  u16 pid;
  u16 fd_count;
  sbp_unterminated_string_t cmdline;
} sbp_msg_linux_process_fd_count_t;


/** Summary of open file descriptors on the system
 *
((m.desc|commentify)))
 */
#define SBP_MSG_LINUX_PROCESS_FD_SUMMARY    0x7F07
typedef struct {
  u32 sys_fd_count;
  sbp_sequence_string_t most_opened;
} sbp_msg_linux_process_fd_summary_t;


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
((m.desc|commentify)))
 */
#define SBP_MSG_LINUX_CPU_STATE             0x7F08
typedef struct {
  u8 index;
  u16 pid;
  u8 pcpu;
  u32 time;
  u8 flags;
  char tname[15];
  sbp_unterminated_string_t cmdline;
} sbp_msg_linux_cpu_state_t;


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
((m.desc|commentify)))
 */
#define SBP_MSG_LINUX_MEM_STATE             0x7F09
typedef struct {
  u8 index;
  u16 pid;
  u8 pmem;
  u32 time;
  u8 flags;
  char tname[15];
  sbp_unterminated_string_t cmdline;
} sbp_msg_linux_mem_state_t;


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
((m.desc|commentify)))
 */
#define SBP_MSG_LINUX_SYS_STATE             0x7F0A
typedef struct {
  u16 mem_total;
  u8 pcpu;
  u8 pmem;
  u16 procs_starting;
  u16 procs_stopping;
  u16 pid_count;
  u32 time;
  u8 flags;
} sbp_msg_linux_sys_state_t;



#include <libsbp/unpacked/linux_operators.h>
#include <libsbp/unpacked/linux_packers.h>

#endif /* LIBSBP_LINUX_MESSAGES_H */
