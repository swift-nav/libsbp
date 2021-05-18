#ifndef LIBSBP_LINUX_MESSAGES_H
#define LIBSBP_LINUX_MESSAGES_H

#include <stdbool.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>
#include <endian.h>
#include <math.h>

#include <libsbp/common.h>
#include <libsbp/unpacked/string/multipart.h>
#include <libsbp/unpacked/string/sequence.h>
#include <libsbp/unpacked/string/unterminated.h>
#include <libsbp/unpacked/string/null_terminated.h>

#ifdef __cplusplus
  extern "C" {
#endif
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
#define sbp_msg_linux_cpu_state_dep_a_t_cmdline_init(f) sbp_unterminated_string_init(f, 236)
#define sbp_msg_linux_cpu_state_dep_a_t_cmdline_valid(f) sbp_unterminated_string_valid(f, 236)
#define sbp_msg_linux_cpu_state_dep_a_t_cmdline_set(f,s) sbp_unterminated_string_set(f,s,236)
#define sbp_msg_linux_cpu_state_dep_a_t_cmdline_printf(f,...) sbp_unterminated_string_printf(f,236,__VA_ARGS__)
#define sbp_msg_linux_cpu_state_dep_a_t_cmdline_vprintf(f,fmt,ap) sbp_unterminated_string_vprintf(f,236,fmt,ap)
#define sbp_msg_linux_cpu_state_dep_a_t_cmdline_packed_len(f) sbp_unterminated_string_packed_len(f,236)
#define sbp_msg_linux_cpu_state_dep_a_t_cmdline_get(f) sbp_unterminated_string_get(f,236)
#define sbp_msg_linux_cpu_state_dep_a_t_cmdline_len(f) ( sbp_msg_linux_cpu_state_dep_a_t_cmdline_packed_len(f))
#define sbp_msg_linux_cpu_state_dep_a_t_cmdline_strcmp(a,b) sbp_unterminated_string_strcmp(a,b,236)

size_t sbp_packed_size_sbp_msg_linux_cpu_state_dep_a_t(const sbp_msg_linux_cpu_state_dep_a_t *msg);
s8 sbp_pack_sbp_msg_linux_cpu_state_dep_a_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_linux_cpu_state_dep_a_t *msg);
s8 sbp_unpack_sbp_msg_linux_cpu_state_dep_a_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_linux_cpu_state_dep_a_t *msg);

int sbp_cmp_sbp_msg_linux_cpu_state_dep_a_t(const sbp_msg_linux_cpu_state_dep_a_t *a, const sbp_msg_linux_cpu_state_dep_a_t *b);


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
#define sbp_msg_linux_mem_state_dep_a_t_cmdline_init(f) sbp_unterminated_string_init(f, 236)
#define sbp_msg_linux_mem_state_dep_a_t_cmdline_valid(f) sbp_unterminated_string_valid(f, 236)
#define sbp_msg_linux_mem_state_dep_a_t_cmdline_set(f,s) sbp_unterminated_string_set(f,s,236)
#define sbp_msg_linux_mem_state_dep_a_t_cmdline_printf(f,...) sbp_unterminated_string_printf(f,236,__VA_ARGS__)
#define sbp_msg_linux_mem_state_dep_a_t_cmdline_vprintf(f,fmt,ap) sbp_unterminated_string_vprintf(f,236,fmt,ap)
#define sbp_msg_linux_mem_state_dep_a_t_cmdline_packed_len(f) sbp_unterminated_string_packed_len(f,236)
#define sbp_msg_linux_mem_state_dep_a_t_cmdline_get(f) sbp_unterminated_string_get(f,236)
#define sbp_msg_linux_mem_state_dep_a_t_cmdline_len(f) ( sbp_msg_linux_mem_state_dep_a_t_cmdline_packed_len(f))
#define sbp_msg_linux_mem_state_dep_a_t_cmdline_strcmp(a,b) sbp_unterminated_string_strcmp(a,b,236)

size_t sbp_packed_size_sbp_msg_linux_mem_state_dep_a_t(const sbp_msg_linux_mem_state_dep_a_t *msg);
s8 sbp_pack_sbp_msg_linux_mem_state_dep_a_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_linux_mem_state_dep_a_t *msg);
s8 sbp_unpack_sbp_msg_linux_mem_state_dep_a_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_linux_mem_state_dep_a_t *msg);

int sbp_cmp_sbp_msg_linux_mem_state_dep_a_t(const sbp_msg_linux_mem_state_dep_a_t *a, const sbp_msg_linux_mem_state_dep_a_t *b);


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

size_t sbp_packed_size_sbp_msg_linux_sys_state_dep_a_t(const sbp_msg_linux_sys_state_dep_a_t *msg);
s8 sbp_pack_sbp_msg_linux_sys_state_dep_a_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_linux_sys_state_dep_a_t *msg);
s8 sbp_unpack_sbp_msg_linux_sys_state_dep_a_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_linux_sys_state_dep_a_t *msg);

int sbp_cmp_sbp_msg_linux_sys_state_dep_a_t(const sbp_msg_linux_sys_state_dep_a_t *a, const sbp_msg_linux_sys_state_dep_a_t *b);


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
#define sbp_msg_linux_process_socket_counts_t_cmdline_init(f) sbp_unterminated_string_init(f, 246)
#define sbp_msg_linux_process_socket_counts_t_cmdline_valid(f) sbp_unterminated_string_valid(f, 246)
#define sbp_msg_linux_process_socket_counts_t_cmdline_set(f,s) sbp_unterminated_string_set(f,s,246)
#define sbp_msg_linux_process_socket_counts_t_cmdline_printf(f,...) sbp_unterminated_string_printf(f,246,__VA_ARGS__)
#define sbp_msg_linux_process_socket_counts_t_cmdline_vprintf(f,fmt,ap) sbp_unterminated_string_vprintf(f,246,fmt,ap)
#define sbp_msg_linux_process_socket_counts_t_cmdline_packed_len(f) sbp_unterminated_string_packed_len(f,246)
#define sbp_msg_linux_process_socket_counts_t_cmdline_get(f) sbp_unterminated_string_get(f,246)
#define sbp_msg_linux_process_socket_counts_t_cmdline_len(f) ( sbp_msg_linux_process_socket_counts_t_cmdline_packed_len(f))
#define sbp_msg_linux_process_socket_counts_t_cmdline_strcmp(a,b) sbp_unterminated_string_strcmp(a,b,246)

size_t sbp_packed_size_sbp_msg_linux_process_socket_counts_t(const sbp_msg_linux_process_socket_counts_t *msg);
s8 sbp_pack_sbp_msg_linux_process_socket_counts_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_linux_process_socket_counts_t *msg);
s8 sbp_unpack_sbp_msg_linux_process_socket_counts_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_linux_process_socket_counts_t *msg);

int sbp_cmp_sbp_msg_linux_process_socket_counts_t(const sbp_msg_linux_process_socket_counts_t *a, const sbp_msg_linux_process_socket_counts_t *b);


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
#define sbp_msg_linux_process_socket_queues_t_cmdline_init(f) sbp_unterminated_string_init(f, 180)
#define sbp_msg_linux_process_socket_queues_t_cmdline_valid(f) sbp_unterminated_string_valid(f, 180)
#define sbp_msg_linux_process_socket_queues_t_cmdline_set(f,s) sbp_unterminated_string_set(f,s,180)
#define sbp_msg_linux_process_socket_queues_t_cmdline_printf(f,...) sbp_unterminated_string_printf(f,180,__VA_ARGS__)
#define sbp_msg_linux_process_socket_queues_t_cmdline_vprintf(f,fmt,ap) sbp_unterminated_string_vprintf(f,180,fmt,ap)
#define sbp_msg_linux_process_socket_queues_t_cmdline_packed_len(f) sbp_unterminated_string_packed_len(f,180)
#define sbp_msg_linux_process_socket_queues_t_cmdline_get(f) sbp_unterminated_string_get(f,180)
#define sbp_msg_linux_process_socket_queues_t_cmdline_len(f) ( sbp_msg_linux_process_socket_queues_t_cmdline_packed_len(f))
#define sbp_msg_linux_process_socket_queues_t_cmdline_strcmp(a,b) sbp_unterminated_string_strcmp(a,b,180)

size_t sbp_packed_size_sbp_msg_linux_process_socket_queues_t(const sbp_msg_linux_process_socket_queues_t *msg);
s8 sbp_pack_sbp_msg_linux_process_socket_queues_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_linux_process_socket_queues_t *msg);
s8 sbp_unpack_sbp_msg_linux_process_socket_queues_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_linux_process_socket_queues_t *msg);

int sbp_cmp_sbp_msg_linux_process_socket_queues_t(const sbp_msg_linux_process_socket_queues_t *a, const sbp_msg_linux_process_socket_queues_t *b);


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

size_t sbp_packed_size_sbp_msg_linux_socket_usage_t(const sbp_msg_linux_socket_usage_t *msg);
s8 sbp_pack_sbp_msg_linux_socket_usage_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_linux_socket_usage_t *msg);
s8 sbp_unpack_sbp_msg_linux_socket_usage_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_linux_socket_usage_t *msg);

int sbp_cmp_sbp_msg_linux_socket_usage_t(const sbp_msg_linux_socket_usage_t *a, const sbp_msg_linux_socket_usage_t *b);


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
#define sbp_msg_linux_process_fd_count_t_cmdline_init(f) sbp_unterminated_string_init(f, 250)
#define sbp_msg_linux_process_fd_count_t_cmdline_valid(f) sbp_unterminated_string_valid(f, 250)
#define sbp_msg_linux_process_fd_count_t_cmdline_set(f,s) sbp_unterminated_string_set(f,s,250)
#define sbp_msg_linux_process_fd_count_t_cmdline_printf(f,...) sbp_unterminated_string_printf(f,250,__VA_ARGS__)
#define sbp_msg_linux_process_fd_count_t_cmdline_vprintf(f,fmt,ap) sbp_unterminated_string_vprintf(f,250,fmt,ap)
#define sbp_msg_linux_process_fd_count_t_cmdline_packed_len(f) sbp_unterminated_string_packed_len(f,250)
#define sbp_msg_linux_process_fd_count_t_cmdline_get(f) sbp_unterminated_string_get(f,250)
#define sbp_msg_linux_process_fd_count_t_cmdline_len(f) ( sbp_msg_linux_process_fd_count_t_cmdline_packed_len(f))
#define sbp_msg_linux_process_fd_count_t_cmdline_strcmp(a,b) sbp_unterminated_string_strcmp(a,b,250)

size_t sbp_packed_size_sbp_msg_linux_process_fd_count_t(const sbp_msg_linux_process_fd_count_t *msg);
s8 sbp_pack_sbp_msg_linux_process_fd_count_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_linux_process_fd_count_t *msg);
s8 sbp_unpack_sbp_msg_linux_process_fd_count_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_linux_process_fd_count_t *msg);

int sbp_cmp_sbp_msg_linux_process_fd_count_t(const sbp_msg_linux_process_fd_count_t *a, const sbp_msg_linux_process_fd_count_t *b);


/** Summary of open file descriptors on the system
 *
((m.desc|commentify)))
 */
#define SBP_MSG_LINUX_PROCESS_FD_SUMMARY    0x7F07
typedef struct {
  u32 sys_fd_count;
  sbp_sequence_string_t most_opened;
} sbp_msg_linux_process_fd_summary_t;
#define sbp_msg_linux_process_fd_summary_t_most_opened_init(f) sbp_sequence_string_init(f, 251, 0)
#define sbp_msg_linux_process_fd_summary_t_most_opened_valid(f) sbp_sequence_string_valid(f, 251, 0)
#define sbp_msg_linux_process_fd_summary_t_most_opened_packed_len(f) sbp_sequence_string_packed_len(f, 251, 0)
#define sbp_msg_linux_process_fd_summary_t_most_opened_append(f,s) sbp_sequence_string_append(f, s, 251, 0)
#define sbp_msg_linux_process_fd_summary_t_most_opened_append_printf(f, ...) sbp_sequence_string_append_printf(s, 251, 0, __VA_ARGS__)
#define sbp_msg_linux_process_fd_summary_t_most_opened_append_vprintf(f, fmt,ap) sbp_sequence_string_append_vprintf(s, 251, 0, fmt, ap)
#define sbp_msg_linux_process_fd_summary_t_most_opened_count_sections(f) sbp_sequence_string_count_sections(f, 251, 0)
#define sbp_msg_linux_process_fd_summary_t_most_opened_get_section(f,s) sbp_sequence_string_get_section(f,s,251, 0)
#define sbp_msg_linux_process_fd_summary_t_most_opened_section_len(f,s) sbp_sequence_string_section_len(f,s,251, 0)
#define sbp_msg_linux_process_fd_summary_t_most_opened_space_remaining(f) sbp_sequence_string_space_remaining(f,251, 0)
#define sbp_msg_linux_process_fd_summary_t_most_opened_strcmp(a,b) sbp_sequence_string_strcmp(a,b,251, 0)

size_t sbp_packed_size_sbp_msg_linux_process_fd_summary_t(const sbp_msg_linux_process_fd_summary_t *msg);
s8 sbp_pack_sbp_msg_linux_process_fd_summary_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_linux_process_fd_summary_t *msg);
s8 sbp_unpack_sbp_msg_linux_process_fd_summary_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_linux_process_fd_summary_t *msg);

int sbp_cmp_sbp_msg_linux_process_fd_summary_t(const sbp_msg_linux_process_fd_summary_t *a, const sbp_msg_linux_process_fd_summary_t *b);


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
#define sbp_msg_linux_cpu_state_t_cmdline_init(f) sbp_unterminated_string_init(f, 231)
#define sbp_msg_linux_cpu_state_t_cmdline_valid(f) sbp_unterminated_string_valid(f, 231)
#define sbp_msg_linux_cpu_state_t_cmdline_set(f,s) sbp_unterminated_string_set(f,s,231)
#define sbp_msg_linux_cpu_state_t_cmdline_printf(f,...) sbp_unterminated_string_printf(f,231,__VA_ARGS__)
#define sbp_msg_linux_cpu_state_t_cmdline_vprintf(f,fmt,ap) sbp_unterminated_string_vprintf(f,231,fmt,ap)
#define sbp_msg_linux_cpu_state_t_cmdline_packed_len(f) sbp_unterminated_string_packed_len(f,231)
#define sbp_msg_linux_cpu_state_t_cmdline_get(f) sbp_unterminated_string_get(f,231)
#define sbp_msg_linux_cpu_state_t_cmdline_len(f) ( sbp_msg_linux_cpu_state_t_cmdline_packed_len(f))
#define sbp_msg_linux_cpu_state_t_cmdline_strcmp(a,b) sbp_unterminated_string_strcmp(a,b,231)

size_t sbp_packed_size_sbp_msg_linux_cpu_state_t(const sbp_msg_linux_cpu_state_t *msg);
s8 sbp_pack_sbp_msg_linux_cpu_state_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_linux_cpu_state_t *msg);
s8 sbp_unpack_sbp_msg_linux_cpu_state_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_linux_cpu_state_t *msg);

int sbp_cmp_sbp_msg_linux_cpu_state_t(const sbp_msg_linux_cpu_state_t *a, const sbp_msg_linux_cpu_state_t *b);


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
#define sbp_msg_linux_mem_state_t_cmdline_init(f) sbp_unterminated_string_init(f, 231)
#define sbp_msg_linux_mem_state_t_cmdline_valid(f) sbp_unterminated_string_valid(f, 231)
#define sbp_msg_linux_mem_state_t_cmdline_set(f,s) sbp_unterminated_string_set(f,s,231)
#define sbp_msg_linux_mem_state_t_cmdline_printf(f,...) sbp_unterminated_string_printf(f,231,__VA_ARGS__)
#define sbp_msg_linux_mem_state_t_cmdline_vprintf(f,fmt,ap) sbp_unterminated_string_vprintf(f,231,fmt,ap)
#define sbp_msg_linux_mem_state_t_cmdline_packed_len(f) sbp_unterminated_string_packed_len(f,231)
#define sbp_msg_linux_mem_state_t_cmdline_get(f) sbp_unterminated_string_get(f,231)
#define sbp_msg_linux_mem_state_t_cmdline_len(f) ( sbp_msg_linux_mem_state_t_cmdline_packed_len(f))
#define sbp_msg_linux_mem_state_t_cmdline_strcmp(a,b) sbp_unterminated_string_strcmp(a,b,231)

size_t sbp_packed_size_sbp_msg_linux_mem_state_t(const sbp_msg_linux_mem_state_t *msg);
s8 sbp_pack_sbp_msg_linux_mem_state_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_linux_mem_state_t *msg);
s8 sbp_unpack_sbp_msg_linux_mem_state_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_linux_mem_state_t *msg);

int sbp_cmp_sbp_msg_linux_mem_state_t(const sbp_msg_linux_mem_state_t *a, const sbp_msg_linux_mem_state_t *b);


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

size_t sbp_packed_size_sbp_msg_linux_sys_state_t(const sbp_msg_linux_sys_state_t *msg);
s8 sbp_pack_sbp_msg_linux_sys_state_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_linux_sys_state_t *msg);
s8 sbp_unpack_sbp_msg_linux_sys_state_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_linux_sys_state_t *msg);

int sbp_cmp_sbp_msg_linux_sys_state_t(const sbp_msg_linux_sys_state_t *a, const sbp_msg_linux_sys_state_t *b);



#ifdef __cplusplus
  }
static inline bool operator==(const sbp_msg_linux_cpu_state_dep_a_t &a, const sbp_msg_linux_cpu_state_dep_a_t &b) {
  return sbp_cmp_sbp_msg_linux_cpu_state_dep_a_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_linux_cpu_state_dep_a_t &a, const sbp_msg_linux_cpu_state_dep_a_t &b) {
  return sbp_cmp_sbp_msg_linux_cpu_state_dep_a_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_linux_cpu_state_dep_a_t &a, const sbp_msg_linux_cpu_state_dep_a_t &b) {
  return sbp_cmp_sbp_msg_linux_cpu_state_dep_a_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_linux_cpu_state_dep_a_t &a, const sbp_msg_linux_cpu_state_dep_a_t &b) {
  return sbp_cmp_sbp_msg_linux_cpu_state_dep_a_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_linux_cpu_state_dep_a_t &a, const sbp_msg_linux_cpu_state_dep_a_t &b) {
  return sbp_cmp_sbp_msg_linux_cpu_state_dep_a_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_linux_cpu_state_dep_a_t &a, const sbp_msg_linux_cpu_state_dep_a_t &b) {
  return sbp_cmp_sbp_msg_linux_cpu_state_dep_a_t(&a, &b) >= 0;
}
static inline bool operator==(const sbp_msg_linux_mem_state_dep_a_t &a, const sbp_msg_linux_mem_state_dep_a_t &b) {
  return sbp_cmp_sbp_msg_linux_mem_state_dep_a_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_linux_mem_state_dep_a_t &a, const sbp_msg_linux_mem_state_dep_a_t &b) {
  return sbp_cmp_sbp_msg_linux_mem_state_dep_a_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_linux_mem_state_dep_a_t &a, const sbp_msg_linux_mem_state_dep_a_t &b) {
  return sbp_cmp_sbp_msg_linux_mem_state_dep_a_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_linux_mem_state_dep_a_t &a, const sbp_msg_linux_mem_state_dep_a_t &b) {
  return sbp_cmp_sbp_msg_linux_mem_state_dep_a_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_linux_mem_state_dep_a_t &a, const sbp_msg_linux_mem_state_dep_a_t &b) {
  return sbp_cmp_sbp_msg_linux_mem_state_dep_a_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_linux_mem_state_dep_a_t &a, const sbp_msg_linux_mem_state_dep_a_t &b) {
  return sbp_cmp_sbp_msg_linux_mem_state_dep_a_t(&a, &b) >= 0;
}
static inline bool operator==(const sbp_msg_linux_sys_state_dep_a_t &a, const sbp_msg_linux_sys_state_dep_a_t &b) {
  return sbp_cmp_sbp_msg_linux_sys_state_dep_a_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_linux_sys_state_dep_a_t &a, const sbp_msg_linux_sys_state_dep_a_t &b) {
  return sbp_cmp_sbp_msg_linux_sys_state_dep_a_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_linux_sys_state_dep_a_t &a, const sbp_msg_linux_sys_state_dep_a_t &b) {
  return sbp_cmp_sbp_msg_linux_sys_state_dep_a_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_linux_sys_state_dep_a_t &a, const sbp_msg_linux_sys_state_dep_a_t &b) {
  return sbp_cmp_sbp_msg_linux_sys_state_dep_a_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_linux_sys_state_dep_a_t &a, const sbp_msg_linux_sys_state_dep_a_t &b) {
  return sbp_cmp_sbp_msg_linux_sys_state_dep_a_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_linux_sys_state_dep_a_t &a, const sbp_msg_linux_sys_state_dep_a_t &b) {
  return sbp_cmp_sbp_msg_linux_sys_state_dep_a_t(&a, &b) >= 0;
}
static inline bool operator==(const sbp_msg_linux_process_socket_counts_t &a, const sbp_msg_linux_process_socket_counts_t &b) {
  return sbp_cmp_sbp_msg_linux_process_socket_counts_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_linux_process_socket_counts_t &a, const sbp_msg_linux_process_socket_counts_t &b) {
  return sbp_cmp_sbp_msg_linux_process_socket_counts_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_linux_process_socket_counts_t &a, const sbp_msg_linux_process_socket_counts_t &b) {
  return sbp_cmp_sbp_msg_linux_process_socket_counts_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_linux_process_socket_counts_t &a, const sbp_msg_linux_process_socket_counts_t &b) {
  return sbp_cmp_sbp_msg_linux_process_socket_counts_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_linux_process_socket_counts_t &a, const sbp_msg_linux_process_socket_counts_t &b) {
  return sbp_cmp_sbp_msg_linux_process_socket_counts_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_linux_process_socket_counts_t &a, const sbp_msg_linux_process_socket_counts_t &b) {
  return sbp_cmp_sbp_msg_linux_process_socket_counts_t(&a, &b) >= 0;
}
static inline bool operator==(const sbp_msg_linux_process_socket_queues_t &a, const sbp_msg_linux_process_socket_queues_t &b) {
  return sbp_cmp_sbp_msg_linux_process_socket_queues_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_linux_process_socket_queues_t &a, const sbp_msg_linux_process_socket_queues_t &b) {
  return sbp_cmp_sbp_msg_linux_process_socket_queues_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_linux_process_socket_queues_t &a, const sbp_msg_linux_process_socket_queues_t &b) {
  return sbp_cmp_sbp_msg_linux_process_socket_queues_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_linux_process_socket_queues_t &a, const sbp_msg_linux_process_socket_queues_t &b) {
  return sbp_cmp_sbp_msg_linux_process_socket_queues_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_linux_process_socket_queues_t &a, const sbp_msg_linux_process_socket_queues_t &b) {
  return sbp_cmp_sbp_msg_linux_process_socket_queues_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_linux_process_socket_queues_t &a, const sbp_msg_linux_process_socket_queues_t &b) {
  return sbp_cmp_sbp_msg_linux_process_socket_queues_t(&a, &b) >= 0;
}
static inline bool operator==(const sbp_msg_linux_socket_usage_t &a, const sbp_msg_linux_socket_usage_t &b) {
  return sbp_cmp_sbp_msg_linux_socket_usage_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_linux_socket_usage_t &a, const sbp_msg_linux_socket_usage_t &b) {
  return sbp_cmp_sbp_msg_linux_socket_usage_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_linux_socket_usage_t &a, const sbp_msg_linux_socket_usage_t &b) {
  return sbp_cmp_sbp_msg_linux_socket_usage_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_linux_socket_usage_t &a, const sbp_msg_linux_socket_usage_t &b) {
  return sbp_cmp_sbp_msg_linux_socket_usage_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_linux_socket_usage_t &a, const sbp_msg_linux_socket_usage_t &b) {
  return sbp_cmp_sbp_msg_linux_socket_usage_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_linux_socket_usage_t &a, const sbp_msg_linux_socket_usage_t &b) {
  return sbp_cmp_sbp_msg_linux_socket_usage_t(&a, &b) >= 0;
}
static inline bool operator==(const sbp_msg_linux_process_fd_count_t &a, const sbp_msg_linux_process_fd_count_t &b) {
  return sbp_cmp_sbp_msg_linux_process_fd_count_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_linux_process_fd_count_t &a, const sbp_msg_linux_process_fd_count_t &b) {
  return sbp_cmp_sbp_msg_linux_process_fd_count_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_linux_process_fd_count_t &a, const sbp_msg_linux_process_fd_count_t &b) {
  return sbp_cmp_sbp_msg_linux_process_fd_count_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_linux_process_fd_count_t &a, const sbp_msg_linux_process_fd_count_t &b) {
  return sbp_cmp_sbp_msg_linux_process_fd_count_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_linux_process_fd_count_t &a, const sbp_msg_linux_process_fd_count_t &b) {
  return sbp_cmp_sbp_msg_linux_process_fd_count_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_linux_process_fd_count_t &a, const sbp_msg_linux_process_fd_count_t &b) {
  return sbp_cmp_sbp_msg_linux_process_fd_count_t(&a, &b) >= 0;
}
static inline bool operator==(const sbp_msg_linux_process_fd_summary_t &a, const sbp_msg_linux_process_fd_summary_t &b) {
  return sbp_cmp_sbp_msg_linux_process_fd_summary_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_linux_process_fd_summary_t &a, const sbp_msg_linux_process_fd_summary_t &b) {
  return sbp_cmp_sbp_msg_linux_process_fd_summary_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_linux_process_fd_summary_t &a, const sbp_msg_linux_process_fd_summary_t &b) {
  return sbp_cmp_sbp_msg_linux_process_fd_summary_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_linux_process_fd_summary_t &a, const sbp_msg_linux_process_fd_summary_t &b) {
  return sbp_cmp_sbp_msg_linux_process_fd_summary_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_linux_process_fd_summary_t &a, const sbp_msg_linux_process_fd_summary_t &b) {
  return sbp_cmp_sbp_msg_linux_process_fd_summary_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_linux_process_fd_summary_t &a, const sbp_msg_linux_process_fd_summary_t &b) {
  return sbp_cmp_sbp_msg_linux_process_fd_summary_t(&a, &b) >= 0;
}
static inline bool operator==(const sbp_msg_linux_cpu_state_t &a, const sbp_msg_linux_cpu_state_t &b) {
  return sbp_cmp_sbp_msg_linux_cpu_state_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_linux_cpu_state_t &a, const sbp_msg_linux_cpu_state_t &b) {
  return sbp_cmp_sbp_msg_linux_cpu_state_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_linux_cpu_state_t &a, const sbp_msg_linux_cpu_state_t &b) {
  return sbp_cmp_sbp_msg_linux_cpu_state_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_linux_cpu_state_t &a, const sbp_msg_linux_cpu_state_t &b) {
  return sbp_cmp_sbp_msg_linux_cpu_state_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_linux_cpu_state_t &a, const sbp_msg_linux_cpu_state_t &b) {
  return sbp_cmp_sbp_msg_linux_cpu_state_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_linux_cpu_state_t &a, const sbp_msg_linux_cpu_state_t &b) {
  return sbp_cmp_sbp_msg_linux_cpu_state_t(&a, &b) >= 0;
}
static inline bool operator==(const sbp_msg_linux_mem_state_t &a, const sbp_msg_linux_mem_state_t &b) {
  return sbp_cmp_sbp_msg_linux_mem_state_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_linux_mem_state_t &a, const sbp_msg_linux_mem_state_t &b) {
  return sbp_cmp_sbp_msg_linux_mem_state_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_linux_mem_state_t &a, const sbp_msg_linux_mem_state_t &b) {
  return sbp_cmp_sbp_msg_linux_mem_state_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_linux_mem_state_t &a, const sbp_msg_linux_mem_state_t &b) {
  return sbp_cmp_sbp_msg_linux_mem_state_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_linux_mem_state_t &a, const sbp_msg_linux_mem_state_t &b) {
  return sbp_cmp_sbp_msg_linux_mem_state_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_linux_mem_state_t &a, const sbp_msg_linux_mem_state_t &b) {
  return sbp_cmp_sbp_msg_linux_mem_state_t(&a, &b) >= 0;
}
static inline bool operator==(const sbp_msg_linux_sys_state_t &a, const sbp_msg_linux_sys_state_t &b) {
  return sbp_cmp_sbp_msg_linux_sys_state_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_linux_sys_state_t &a, const sbp_msg_linux_sys_state_t &b) {
  return sbp_cmp_sbp_msg_linux_sys_state_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_linux_sys_state_t &a, const sbp_msg_linux_sys_state_t &b) {
  return sbp_cmp_sbp_msg_linux_sys_state_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_linux_sys_state_t &a, const sbp_msg_linux_sys_state_t &b) {
  return sbp_cmp_sbp_msg_linux_sys_state_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_linux_sys_state_t &a, const sbp_msg_linux_sys_state_t &b) {
  return sbp_cmp_sbp_msg_linux_sys_state_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_linux_sys_state_t &a, const sbp_msg_linux_sys_state_t &b) {
  return sbp_cmp_sbp_msg_linux_sys_state_t(&a, &b) >= 0;
}

#endif

#endif /* LIBSBP_LINUX_MESSAGES_H */
