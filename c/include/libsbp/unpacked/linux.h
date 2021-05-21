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
#include <libsbp/unpacked/string/double_null_terminated.h>
#include <libsbp/unpacked/string/unterminated.h>
#include <libsbp/unpacked/string/null_terminated.h>
#include <libsbp/unpacked/string/binary.h>

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
  void sbp_msg_linux_cpu_state_dep_a_t_cmdline_init(sbp_unterminated_string_t *s);
  bool sbp_msg_linux_cpu_state_dep_a_t_cmdline_valid(const sbp_unterminated_string_t *s);
  int sbp_msg_linux_cpu_state_dep_a_t_cmdline_strcmp(const sbp_unterminated_string_t *a, const sbp_unterminated_string_t *b);
  uint8_t sbp_msg_linux_cpu_state_dep_a_t_cmdline_packed_len(const sbp_unterminated_string_t *s);
  uint8_t sbp_msg_linux_cpu_state_dep_a_t_cmdline_space_remaining(const sbp_unterminated_string_t *s);
  bool sbp_msg_linux_cpu_state_dep_a_t_cmdline_set(sbp_unterminated_string_t *s, const char *new_str);
  bool sbp_msg_linux_cpu_state_dep_a_t_cmdline_printf(sbp_unterminated_string_t *s, const char *fmt, ...) SBP_ATTR_FORMAT(2,3);
  bool sbp_msg_linux_cpu_state_dep_a_t_cmdline_vprintf(sbp_unterminated_string_t *s, const char *fmt, va_list ap);
  bool sbp_msg_linux_cpu_state_dep_a_t_cmdline_append_printf(sbp_unterminated_string_t *s, const char *fmt, ...) SBP_ATTR_FORMAT(2,3);
  bool sbp_msg_linux_cpu_state_dep_a_t_cmdline_append_vprintf(sbp_unterminated_string_t *s, const char *fmt, va_list ap);
  const char *sbp_msg_linux_cpu_state_dep_a_t_cmdline_get(const sbp_unterminated_string_t *s);

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
  void sbp_msg_linux_mem_state_dep_a_t_cmdline_init(sbp_unterminated_string_t *s);
  bool sbp_msg_linux_mem_state_dep_a_t_cmdline_valid(const sbp_unterminated_string_t *s);
  int sbp_msg_linux_mem_state_dep_a_t_cmdline_strcmp(const sbp_unterminated_string_t *a, const sbp_unterminated_string_t *b);
  uint8_t sbp_msg_linux_mem_state_dep_a_t_cmdline_packed_len(const sbp_unterminated_string_t *s);
  uint8_t sbp_msg_linux_mem_state_dep_a_t_cmdline_space_remaining(const sbp_unterminated_string_t *s);
  bool sbp_msg_linux_mem_state_dep_a_t_cmdline_set(sbp_unterminated_string_t *s, const char *new_str);
  bool sbp_msg_linux_mem_state_dep_a_t_cmdline_printf(sbp_unterminated_string_t *s, const char *fmt, ...) SBP_ATTR_FORMAT(2,3);
  bool sbp_msg_linux_mem_state_dep_a_t_cmdline_vprintf(sbp_unterminated_string_t *s, const char *fmt, va_list ap);
  bool sbp_msg_linux_mem_state_dep_a_t_cmdline_append_printf(sbp_unterminated_string_t *s, const char *fmt, ...) SBP_ATTR_FORMAT(2,3);
  bool sbp_msg_linux_mem_state_dep_a_t_cmdline_append_vprintf(sbp_unterminated_string_t *s, const char *fmt, va_list ap);
  const char *sbp_msg_linux_mem_state_dep_a_t_cmdline_get(const sbp_unterminated_string_t *s);

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
  void sbp_msg_linux_process_socket_counts_t_cmdline_init(sbp_unterminated_string_t *s);
  bool sbp_msg_linux_process_socket_counts_t_cmdline_valid(const sbp_unterminated_string_t *s);
  int sbp_msg_linux_process_socket_counts_t_cmdline_strcmp(const sbp_unterminated_string_t *a, const sbp_unterminated_string_t *b);
  uint8_t sbp_msg_linux_process_socket_counts_t_cmdline_packed_len(const sbp_unterminated_string_t *s);
  uint8_t sbp_msg_linux_process_socket_counts_t_cmdline_space_remaining(const sbp_unterminated_string_t *s);
  bool sbp_msg_linux_process_socket_counts_t_cmdline_set(sbp_unterminated_string_t *s, const char *new_str);
  bool sbp_msg_linux_process_socket_counts_t_cmdline_printf(sbp_unterminated_string_t *s, const char *fmt, ...) SBP_ATTR_FORMAT(2,3);
  bool sbp_msg_linux_process_socket_counts_t_cmdline_vprintf(sbp_unterminated_string_t *s, const char *fmt, va_list ap);
  bool sbp_msg_linux_process_socket_counts_t_cmdline_append_printf(sbp_unterminated_string_t *s, const char *fmt, ...) SBP_ATTR_FORMAT(2,3);
  bool sbp_msg_linux_process_socket_counts_t_cmdline_append_vprintf(sbp_unterminated_string_t *s, const char *fmt, va_list ap);
  const char *sbp_msg_linux_process_socket_counts_t_cmdline_get(const sbp_unterminated_string_t *s);

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
  void sbp_msg_linux_process_socket_queues_t_cmdline_init(sbp_unterminated_string_t *s);
  bool sbp_msg_linux_process_socket_queues_t_cmdline_valid(const sbp_unterminated_string_t *s);
  int sbp_msg_linux_process_socket_queues_t_cmdline_strcmp(const sbp_unterminated_string_t *a, const sbp_unterminated_string_t *b);
  uint8_t sbp_msg_linux_process_socket_queues_t_cmdline_packed_len(const sbp_unterminated_string_t *s);
  uint8_t sbp_msg_linux_process_socket_queues_t_cmdline_space_remaining(const sbp_unterminated_string_t *s);
  bool sbp_msg_linux_process_socket_queues_t_cmdline_set(sbp_unterminated_string_t *s, const char *new_str);
  bool sbp_msg_linux_process_socket_queues_t_cmdline_printf(sbp_unterminated_string_t *s, const char *fmt, ...) SBP_ATTR_FORMAT(2,3);
  bool sbp_msg_linux_process_socket_queues_t_cmdline_vprintf(sbp_unterminated_string_t *s, const char *fmt, va_list ap);
  bool sbp_msg_linux_process_socket_queues_t_cmdline_append_printf(sbp_unterminated_string_t *s, const char *fmt, ...) SBP_ATTR_FORMAT(2,3);
  bool sbp_msg_linux_process_socket_queues_t_cmdline_append_vprintf(sbp_unterminated_string_t *s, const char *fmt, va_list ap);
  const char *sbp_msg_linux_process_socket_queues_t_cmdline_get(const sbp_unterminated_string_t *s);

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
  void sbp_msg_linux_process_fd_count_t_cmdline_init(sbp_unterminated_string_t *s);
  bool sbp_msg_linux_process_fd_count_t_cmdline_valid(const sbp_unterminated_string_t *s);
  int sbp_msg_linux_process_fd_count_t_cmdline_strcmp(const sbp_unterminated_string_t *a, const sbp_unterminated_string_t *b);
  uint8_t sbp_msg_linux_process_fd_count_t_cmdline_packed_len(const sbp_unterminated_string_t *s);
  uint8_t sbp_msg_linux_process_fd_count_t_cmdline_space_remaining(const sbp_unterminated_string_t *s);
  bool sbp_msg_linux_process_fd_count_t_cmdline_set(sbp_unterminated_string_t *s, const char *new_str);
  bool sbp_msg_linux_process_fd_count_t_cmdline_printf(sbp_unterminated_string_t *s, const char *fmt, ...) SBP_ATTR_FORMAT(2,3);
  bool sbp_msg_linux_process_fd_count_t_cmdline_vprintf(sbp_unterminated_string_t *s, const char *fmt, va_list ap);
  bool sbp_msg_linux_process_fd_count_t_cmdline_append_printf(sbp_unterminated_string_t *s, const char *fmt, ...) SBP_ATTR_FORMAT(2,3);
  bool sbp_msg_linux_process_fd_count_t_cmdline_append_vprintf(sbp_unterminated_string_t *s, const char *fmt, va_list ap);
  const char *sbp_msg_linux_process_fd_count_t_cmdline_get(const sbp_unterminated_string_t *s);

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
  sbp_double_null_terminated_string_t most_opened;
} sbp_msg_linux_process_fd_summary_t;
  void sbp_msg_linux_process_fd_summary_t_most_opened_init(sbp_double_null_terminated_string_t *s);
  bool sbp_msg_linux_process_fd_summary_t_most_opened_valid(const sbp_double_null_terminated_string_t *s);
  int sbp_msg_linux_process_fd_summary_t_most_opened_strcmp(const sbp_double_null_terminated_string_t *a, const sbp_double_null_terminated_string_t *b);
  uint8_t sbp_msg_linux_process_fd_summary_t_most_opened_packed_len(const sbp_double_null_terminated_string_t *s);
  uint8_t sbp_msg_linux_process_fd_summary_t_most_opened_space_remaining(const sbp_double_null_terminated_string_t *s);
  uint8_t sbp_msg_linux_process_fd_summary_t_most_opened_count_sections(const sbp_double_null_terminated_string_t *s);
  bool sbp_msg_linux_process_fd_summary_t_most_opened_add_section(sbp_double_null_terminated_string_t *s, const char *new_str);
  bool sbp_msg_linux_process_fd_summary_t_most_opened_add_section_printf(sbp_double_null_terminated_string_t *s, const char *fmt, ...) SBP_ATTR_FORMAT(2,3);
  bool sbp_msg_linux_process_fd_summary_t_most_opened_add_section_vprintf(sbp_double_null_terminated_string_t *s, const char *fmt, va_list ap);
  bool sbp_msg_linux_process_fd_summary_t_most_opened_append(sbp_double_null_terminated_string_t *s, const char *str);
  bool sbp_msg_linux_process_fd_summary_t_most_opened_append_printf(sbp_double_null_terminated_string_t *s, const char *fmt, ...) SBP_ATTR_FORMAT(2,3);
  bool sbp_msg_linux_process_fd_summary_t_most_opened_append_vprintf(sbp_double_null_terminated_string_t *s, const char *fmt, va_list ap);
  const char *sbp_msg_linux_process_fd_summary_t_most_opened_get_section(sbp_double_null_terminated_string_t *s, uint8_t section);
  uint8_t sbp_msg_linux_process_fd_summary_t_most_opened_section_strlen(sbp_double_null_terminated_string_t *s, uint8_t section);

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
  void sbp_msg_linux_cpu_state_t_cmdline_init(sbp_unterminated_string_t *s);
  bool sbp_msg_linux_cpu_state_t_cmdline_valid(const sbp_unterminated_string_t *s);
  int sbp_msg_linux_cpu_state_t_cmdline_strcmp(const sbp_unterminated_string_t *a, const sbp_unterminated_string_t *b);
  uint8_t sbp_msg_linux_cpu_state_t_cmdline_packed_len(const sbp_unterminated_string_t *s);
  uint8_t sbp_msg_linux_cpu_state_t_cmdline_space_remaining(const sbp_unterminated_string_t *s);
  bool sbp_msg_linux_cpu_state_t_cmdline_set(sbp_unterminated_string_t *s, const char *new_str);
  bool sbp_msg_linux_cpu_state_t_cmdline_printf(sbp_unterminated_string_t *s, const char *fmt, ...) SBP_ATTR_FORMAT(2,3);
  bool sbp_msg_linux_cpu_state_t_cmdline_vprintf(sbp_unterminated_string_t *s, const char *fmt, va_list ap);
  bool sbp_msg_linux_cpu_state_t_cmdline_append_printf(sbp_unterminated_string_t *s, const char *fmt, ...) SBP_ATTR_FORMAT(2,3);
  bool sbp_msg_linux_cpu_state_t_cmdline_append_vprintf(sbp_unterminated_string_t *s, const char *fmt, va_list ap);
  const char *sbp_msg_linux_cpu_state_t_cmdline_get(const sbp_unterminated_string_t *s);

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
  void sbp_msg_linux_mem_state_t_cmdline_init(sbp_unterminated_string_t *s);
  bool sbp_msg_linux_mem_state_t_cmdline_valid(const sbp_unterminated_string_t *s);
  int sbp_msg_linux_mem_state_t_cmdline_strcmp(const sbp_unterminated_string_t *a, const sbp_unterminated_string_t *b);
  uint8_t sbp_msg_linux_mem_state_t_cmdline_packed_len(const sbp_unterminated_string_t *s);
  uint8_t sbp_msg_linux_mem_state_t_cmdline_space_remaining(const sbp_unterminated_string_t *s);
  bool sbp_msg_linux_mem_state_t_cmdline_set(sbp_unterminated_string_t *s, const char *new_str);
  bool sbp_msg_linux_mem_state_t_cmdline_printf(sbp_unterminated_string_t *s, const char *fmt, ...) SBP_ATTR_FORMAT(2,3);
  bool sbp_msg_linux_mem_state_t_cmdline_vprintf(sbp_unterminated_string_t *s, const char *fmt, va_list ap);
  bool sbp_msg_linux_mem_state_t_cmdline_append_printf(sbp_unterminated_string_t *s, const char *fmt, ...) SBP_ATTR_FORMAT(2,3);
  bool sbp_msg_linux_mem_state_t_cmdline_append_vprintf(sbp_unterminated_string_t *s, const char *fmt, va_list ap);
  const char *sbp_msg_linux_mem_state_t_cmdline_get(const sbp_unterminated_string_t *s);

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
