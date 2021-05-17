#ifndef LIBSBP_LINUX_OPERATORS_H
#define LIBSBP_LINUX_OPERATORS_H

#ifndef LIBSBP_LINUX_MESSAGES_H
#error "Do not include this file directly, include libsbp/unpacked/linux.h instead"
#endif

#include <stdbool.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>
#include <endian.h>
#include <math.h>

#include <libsbp/common.h>
#include <libsbp/unpacked/string/unterminated.h>
#include <libsbp/unpacked/string/multipart.h>
#include <libsbp/unpacked/string/sequence.h>
#include <libsbp/unpacked/string/null_terminated.h>
#include <libsbp/unpacked/base.h>
static inline int sbp_cmp_sbp_msg_linux_cpu_state_dep_a_t(const sbp_msg_linux_cpu_state_dep_a_t *a, const sbp_msg_linux_cpu_state_dep_a_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u8(&a->index, &b->index);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->pid, &b->pid);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->pcpu, &b->pcpu);
  if (ret != 0) { return ret; }
  
  for (uint8_t i = 0; i < 15 && ret == 0; i++)
  {
    ret = sbp_cmp_char(&a->tname[i], &b->tname[i]);
  }
  if (ret != 0) { return ret; }
  
  ret = sbp_unterminated_string_strcmp(&a->cmdline, &b->cmdline, 236
    );
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
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
#endif
static inline int sbp_cmp_sbp_msg_linux_mem_state_dep_a_t(const sbp_msg_linux_mem_state_dep_a_t *a, const sbp_msg_linux_mem_state_dep_a_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u8(&a->index, &b->index);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->pid, &b->pid);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->pmem, &b->pmem);
  if (ret != 0) { return ret; }
  
  for (uint8_t i = 0; i < 15 && ret == 0; i++)
  {
    ret = sbp_cmp_char(&a->tname[i], &b->tname[i]);
  }
  if (ret != 0) { return ret; }
  
  ret = sbp_unterminated_string_strcmp(&a->cmdline, &b->cmdline, 236
    );
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
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
#endif
static inline int sbp_cmp_sbp_msg_linux_sys_state_dep_a_t(const sbp_msg_linux_sys_state_dep_a_t *a, const sbp_msg_linux_sys_state_dep_a_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u16(&a->mem_total, &b->mem_total);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->pcpu, &b->pcpu);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->pmem, &b->pmem);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->procs_starting, &b->procs_starting);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->procs_stopping, &b->procs_stopping);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->pid_count, &b->pid_count);
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
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
#endif
static inline int sbp_cmp_sbp_msg_linux_process_socket_counts_t(const sbp_msg_linux_process_socket_counts_t *a, const sbp_msg_linux_process_socket_counts_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u8(&a->index, &b->index);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->pid, &b->pid);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->socket_count, &b->socket_count);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->socket_types, &b->socket_types);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->socket_states, &b->socket_states);
  if (ret != 0) { return ret; }
  
  ret = sbp_unterminated_string_strcmp(&a->cmdline, &b->cmdline, 246
    );
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
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
#endif
static inline int sbp_cmp_sbp_msg_linux_process_socket_queues_t(const sbp_msg_linux_process_socket_queues_t *a, const sbp_msg_linux_process_socket_queues_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u8(&a->index, &b->index);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->pid, &b->pid);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->recv_queued, &b->recv_queued);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->send_queued, &b->send_queued);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->socket_types, &b->socket_types);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->socket_states, &b->socket_states);
  if (ret != 0) { return ret; }
  
  for (uint8_t i = 0; i < 64 && ret == 0; i++)
  {
    ret = sbp_cmp_char(&a->address_of_largest[i], &b->address_of_largest[i]);
  }
  if (ret != 0) { return ret; }
  
  ret = sbp_unterminated_string_strcmp(&a->cmdline, &b->cmdline, 180
    );
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
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
#endif
static inline int sbp_cmp_sbp_msg_linux_socket_usage_t(const sbp_msg_linux_socket_usage_t *a, const sbp_msg_linux_socket_usage_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u32(&a->avg_queue_depth, &b->avg_queue_depth);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u32(&a->max_queue_depth, &b->max_queue_depth);
  if (ret != 0) { return ret; }
  
  for (uint8_t i = 0; i < 16 && ret == 0; i++)
  {
    ret = sbp_cmp_u16(&a->socket_state_counts[i], &b->socket_state_counts[i]);
  }
  if (ret != 0) { return ret; }
  
  for (uint8_t i = 0; i < 16 && ret == 0; i++)
  {
    ret = sbp_cmp_u16(&a->socket_type_counts[i], &b->socket_type_counts[i]);
  }
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
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
#endif
static inline int sbp_cmp_sbp_msg_linux_process_fd_count_t(const sbp_msg_linux_process_fd_count_t *a, const sbp_msg_linux_process_fd_count_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u8(&a->index, &b->index);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->pid, &b->pid);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->fd_count, &b->fd_count);
  if (ret != 0) { return ret; }
  
  ret = sbp_unterminated_string_strcmp(&a->cmdline, &b->cmdline, 250
    );
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
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
#endif
static inline int sbp_cmp_sbp_msg_linux_process_fd_summary_t(const sbp_msg_linux_process_fd_summary_t *a, const sbp_msg_linux_process_fd_summary_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u32(&a->sys_fd_count, &b->sys_fd_count);
  if (ret != 0) { return ret; }
  
  ret = sbp_sequence_string_strcmp(&a->most_opened, &b->most_opened, 251,0
    );
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
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
#endif
static inline int sbp_cmp_sbp_msg_linux_cpu_state_t(const sbp_msg_linux_cpu_state_t *a, const sbp_msg_linux_cpu_state_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u8(&a->index, &b->index);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->pid, &b->pid);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->pcpu, &b->pcpu);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u32(&a->time, &b->time);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->flags, &b->flags);
  if (ret != 0) { return ret; }
  
  for (uint8_t i = 0; i < 15 && ret == 0; i++)
  {
    ret = sbp_cmp_char(&a->tname[i], &b->tname[i]);
  }
  if (ret != 0) { return ret; }
  
  ret = sbp_unterminated_string_strcmp(&a->cmdline, &b->cmdline, 231
    );
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
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
#endif
static inline int sbp_cmp_sbp_msg_linux_mem_state_t(const sbp_msg_linux_mem_state_t *a, const sbp_msg_linux_mem_state_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u8(&a->index, &b->index);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->pid, &b->pid);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->pmem, &b->pmem);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u32(&a->time, &b->time);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->flags, &b->flags);
  if (ret != 0) { return ret; }
  
  for (uint8_t i = 0; i < 15 && ret == 0; i++)
  {
    ret = sbp_cmp_char(&a->tname[i], &b->tname[i]);
  }
  if (ret != 0) { return ret; }
  
  ret = sbp_unterminated_string_strcmp(&a->cmdline, &b->cmdline, 231
    );
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
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
#endif
static inline int sbp_cmp_sbp_msg_linux_sys_state_t(const sbp_msg_linux_sys_state_t *a, const sbp_msg_linux_sys_state_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u16(&a->mem_total, &b->mem_total);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->pcpu, &b->pcpu);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->pmem, &b->pmem);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->procs_starting, &b->procs_starting);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->procs_stopping, &b->procs_stopping);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->pid_count, &b->pid_count);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u32(&a->time, &b->time);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->flags, &b->flags);
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
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

#endif
