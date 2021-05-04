#ifndef LIBSBP_LINUX_OPERATORS_H
#define LIBSBP_LINUX_OPERATORS_H

#include <endian.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>

#include <libsbp/common.h>
#include <libsbp/unpacked/linux.h>
#ifdef __cplusplus
static inline bool operator==(const sbp_msg_linux_cpu_state_dep_a_t &a, const sbp_msg_linux_cpu_state_dep_a_t &b)
{
  (void)a;
  (void)b;

  if (a.index != b.index)
  {
    return false;
  }

  if (a.pid != b.pid)
  {
    return false;
  }

  if (a.pcpu != b.pcpu)
  {
    return false;
  }
  for (size_t tname_idx = 0; tname_idx < 15; tname_idx++)
  {

    if (a.tname[tname_idx] != b.tname[tname_idx])
    {
      return false;
    }
  }
  if (sbp_strcmp(a.cmdline, b.cmdline, "none") != 0)
  {
    return false;
  }

  return true;
}

static inline bool operator!=(const sbp_msg_linux_cpu_state_dep_a_t &a, const sbp_msg_linux_cpu_state_dep_a_t &b)
{
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator==(const sbp_msg_linux_mem_state_dep_a_t &a, const sbp_msg_linux_mem_state_dep_a_t &b)
{
  (void)a;
  (void)b;

  if (a.index != b.index)
  {
    return false;
  }

  if (a.pid != b.pid)
  {
    return false;
  }

  if (a.pmem != b.pmem)
  {
    return false;
  }
  for (size_t tname_idx = 0; tname_idx < 15; tname_idx++)
  {

    if (a.tname[tname_idx] != b.tname[tname_idx])
    {
      return false;
    }
  }
  if (sbp_strcmp(a.cmdline, b.cmdline, "none") != 0)
  {
    return false;
  }

  return true;
}

static inline bool operator!=(const sbp_msg_linux_mem_state_dep_a_t &a, const sbp_msg_linux_mem_state_dep_a_t &b)
{
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator==(const sbp_msg_linux_sys_state_dep_a_t &a, const sbp_msg_linux_sys_state_dep_a_t &b)
{
  (void)a;
  (void)b;

  if (a.mem_total != b.mem_total)
  {
    return false;
  }

  if (a.pcpu != b.pcpu)
  {
    return false;
  }

  if (a.pmem != b.pmem)
  {
    return false;
  }

  if (a.procs_starting != b.procs_starting)
  {
    return false;
  }

  if (a.procs_stopping != b.procs_stopping)
  {
    return false;
  }

  if (a.pid_count != b.pid_count)
  {
    return false;
  }

  return true;
}

static inline bool operator!=(const sbp_msg_linux_sys_state_dep_a_t &a, const sbp_msg_linux_sys_state_dep_a_t &b)
{
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator==(const sbp_msg_linux_process_socket_counts_t &a,
                              const sbp_msg_linux_process_socket_counts_t &b)
{
  (void)a;
  (void)b;

  if (a.index != b.index)
  {
    return false;
  }

  if (a.pid != b.pid)
  {
    return false;
  }

  if (a.socket_count != b.socket_count)
  {
    return false;
  }

  if (a.socket_types != b.socket_types)
  {
    return false;
  }

  if (a.socket_states != b.socket_states)
  {
    return false;
  }
  if (sbp_strcmp(a.cmdline, b.cmdline, "none") != 0)
  {
    return false;
  }

  return true;
}

static inline bool operator!=(const sbp_msg_linux_process_socket_counts_t &a,
                              const sbp_msg_linux_process_socket_counts_t &b)
{
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator==(const sbp_msg_linux_process_socket_queues_t &a,
                              const sbp_msg_linux_process_socket_queues_t &b)
{
  (void)a;
  (void)b;

  if (a.index != b.index)
  {
    return false;
  }

  if (a.pid != b.pid)
  {
    return false;
  }

  if (a.recv_queued != b.recv_queued)
  {
    return false;
  }

  if (a.send_queued != b.send_queued)
  {
    return false;
  }

  if (a.socket_types != b.socket_types)
  {
    return false;
  }

  if (a.socket_states != b.socket_states)
  {
    return false;
  }
  for (size_t address_of_largest_idx = 0; address_of_largest_idx < 64; address_of_largest_idx++)
  {

    if (a.address_of_largest[address_of_largest_idx] != b.address_of_largest[address_of_largest_idx])
    {
      return false;
    }
  }
  if (sbp_strcmp(a.cmdline, b.cmdline, "none") != 0)
  {
    return false;
  }

  return true;
}

static inline bool operator!=(const sbp_msg_linux_process_socket_queues_t &a,
                              const sbp_msg_linux_process_socket_queues_t &b)
{
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator==(const sbp_msg_linux_socket_usage_t &a, const sbp_msg_linux_socket_usage_t &b)
{
  (void)a;
  (void)b;

  if (a.avg_queue_depth != b.avg_queue_depth)
  {
    return false;
  }

  if (a.max_queue_depth != b.max_queue_depth)
  {
    return false;
  }
  for (size_t socket_state_counts_idx = 0; socket_state_counts_idx < 16; socket_state_counts_idx++)
  {

    if (a.socket_state_counts[socket_state_counts_idx] != b.socket_state_counts[socket_state_counts_idx])
    {
      return false;
    }
  }
  for (size_t socket_type_counts_idx = 0; socket_type_counts_idx < 16; socket_type_counts_idx++)
  {

    if (a.socket_type_counts[socket_type_counts_idx] != b.socket_type_counts[socket_type_counts_idx])
    {
      return false;
    }
  }

  return true;
}

static inline bool operator!=(const sbp_msg_linux_socket_usage_t &a, const sbp_msg_linux_socket_usage_t &b)
{
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator==(const sbp_msg_linux_process_fd_count_t &a, const sbp_msg_linux_process_fd_count_t &b)
{
  (void)a;
  (void)b;

  if (a.index != b.index)
  {
    return false;
  }

  if (a.pid != b.pid)
  {
    return false;
  }

  if (a.fd_count != b.fd_count)
  {
    return false;
  }
  if (sbp_strcmp(a.cmdline, b.cmdline, "none") != 0)
  {
    return false;
  }

  return true;
}

static inline bool operator!=(const sbp_msg_linux_process_fd_count_t &a, const sbp_msg_linux_process_fd_count_t &b)
{
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator==(const sbp_msg_linux_process_fd_summary_t &a, const sbp_msg_linux_process_fd_summary_t &b)
{
  (void)a;
  (void)b;

  if (a.sys_fd_count != b.sys_fd_count)
  {
    return false;
  }
  if (sbp_strcmp(a.most_opened, b.most_opened, "2-nul") != 0)
  {
    return false;
  }

  return true;
}

static inline bool operator!=(const sbp_msg_linux_process_fd_summary_t &a, const sbp_msg_linux_process_fd_summary_t &b)
{
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator==(const sbp_msg_linux_cpu_state_t &a, const sbp_msg_linux_cpu_state_t &b)
{
  (void)a;
  (void)b;

  if (a.index != b.index)
  {
    return false;
  }

  if (a.pid != b.pid)
  {
    return false;
  }

  if (a.pcpu != b.pcpu)
  {
    return false;
  }

  if (a.time != b.time)
  {
    return false;
  }

  if (a.flags != b.flags)
  {
    return false;
  }
  for (size_t tname_idx = 0; tname_idx < 15; tname_idx++)
  {

    if (a.tname[tname_idx] != b.tname[tname_idx])
    {
      return false;
    }
  }
  if (sbp_strcmp(a.cmdline, b.cmdline, "none") != 0)
  {
    return false;
  }

  return true;
}

static inline bool operator!=(const sbp_msg_linux_cpu_state_t &a, const sbp_msg_linux_cpu_state_t &b)
{
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator==(const sbp_msg_linux_mem_state_t &a, const sbp_msg_linux_mem_state_t &b)
{
  (void)a;
  (void)b;

  if (a.index != b.index)
  {
    return false;
  }

  if (a.pid != b.pid)
  {
    return false;
  }

  if (a.pmem != b.pmem)
  {
    return false;
  }

  if (a.time != b.time)
  {
    return false;
  }

  if (a.flags != b.flags)
  {
    return false;
  }
  for (size_t tname_idx = 0; tname_idx < 15; tname_idx++)
  {

    if (a.tname[tname_idx] != b.tname[tname_idx])
    {
      return false;
    }
  }
  if (sbp_strcmp(a.cmdline, b.cmdline, "none") != 0)
  {
    return false;
  }

  return true;
}

static inline bool operator!=(const sbp_msg_linux_mem_state_t &a, const sbp_msg_linux_mem_state_t &b)
{
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator==(const sbp_msg_linux_sys_state_t &a, const sbp_msg_linux_sys_state_t &b)
{
  (void)a;
  (void)b;

  if (a.mem_total != b.mem_total)
  {
    return false;
  }

  if (a.pcpu != b.pcpu)
  {
    return false;
  }

  if (a.pmem != b.pmem)
  {
    return false;
  }

  if (a.procs_starting != b.procs_starting)
  {
    return false;
  }

  if (a.procs_stopping != b.procs_stopping)
  {
    return false;
  }

  if (a.pid_count != b.pid_count)
  {
    return false;
  }

  if (a.time != b.time)
  {
    return false;
  }

  if (a.flags != b.flags)
  {
    return false;
  }

  return true;
}

static inline bool operator!=(const sbp_msg_linux_sys_state_t &a, const sbp_msg_linux_sys_state_t &b)
{
  return !(a == b);
}
#endif

#endif