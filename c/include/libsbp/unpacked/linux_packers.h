#ifndef LIBSBP_LINUX_PACKERS_H
#define LIBSBP_LINUX_PACKERS_H

#include <endian.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>

#include <libsbp/common.h>
#include <libsbp/string2.h>
//#include <libsbp/unpacked/linux.h>

static inline size_t sbp_packed_size_sbp_msg_linux_cpu_state_dep_a_t(const sbp_msg_linux_cpu_state_dep_a_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->index) + sizeof(msg->pid) + sizeof(msg->pcpu) + (15 * sizeof(msg->tname[0])) +
         sbp_unterminated_string_packed_len(&msg->cmdline, 236);
}

static inline bool
sbp_pack_sbp_msg_linux_cpu_state_dep_a_t(u8 *buf, size_t len, const sbp_msg_linux_cpu_state_dep_a_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_linux_cpu_state_dep_a_t(msg) > len)
  {
    return false;
  }

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgindex = msg->index;
  memcpy(buf + offset, &msgindex, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgpid = htole16(msg->pid);
  memcpy(buf + offset, &msgpid, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgpcpu = msg->pcpu;
  memcpy(buf + offset, &msgpcpu, 1);
  // NOLINTNEXTLINE
  offset += 1;
  for (size_t msgtname_idx = 0; msgtname_idx < 15; msgtname_idx++)
  {

    if (offset + 1 > len)
    {
      return false;
    }
    char msgtnamemsgtname_idx = msg->tname[msgtname_idx];
    memcpy(buf + offset, &msgtnamemsgtname_idx, 1);
    // NOLINTNEXTLINE
    offset += 1;
  }
  offset += sbp_unterminated_string_pack(&msg->cmdline, 236, buf + offset, (uint8_t)(len - offset));
  return true;
}

static inline bool
sbp_unpack_sbp_msg_linux_cpu_state_dep_a_t(const u8 *buf, size_t len, sbp_msg_linux_cpu_state_dep_a_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->index, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->pid, buf + offset, 2);
  msg->pid = le16toh(msg->pid);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->pcpu, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
  for (size_t msgtname_idx = 0; msgtname_idx < 15; msgtname_idx++)
  {

    if (offset + 1 > len)
    {
      return false;
    }
    memcpy(&msg->tname[msgtname_idx], buf + offset, 1);
    // NOLINTNEXTLINE
    offset += 1;
  }
  offset += sbp_unterminated_string_unpack(&msg->cmdline, 236, buf + offset, (uint8_t)(len - offset));
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_linux_mem_state_dep_a_t(const sbp_msg_linux_mem_state_dep_a_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->index) + sizeof(msg->pid) + sizeof(msg->pmem) + (15 * sizeof(msg->tname[0])) +
         sbp_unterminated_string_packed_len(&msg->cmdline, 236);
}

static inline bool
sbp_pack_sbp_msg_linux_mem_state_dep_a_t(u8 *buf, size_t len, const sbp_msg_linux_mem_state_dep_a_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_linux_mem_state_dep_a_t(msg) > len)
  {
    return false;
  }

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgindex = msg->index;
  memcpy(buf + offset, &msgindex, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgpid = htole16(msg->pid);
  memcpy(buf + offset, &msgpid, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgpmem = msg->pmem;
  memcpy(buf + offset, &msgpmem, 1);
  // NOLINTNEXTLINE
  offset += 1;
  for (size_t msgtname_idx = 0; msgtname_idx < 15; msgtname_idx++)
  {

    if (offset + 1 > len)
    {
      return false;
    }
    char msgtnamemsgtname_idx = msg->tname[msgtname_idx];
    memcpy(buf + offset, &msgtnamemsgtname_idx, 1);
    // NOLINTNEXTLINE
    offset += 1;
  }
  offset += sbp_unterminated_string_pack(&msg->cmdline, 236, buf + offset, (uint8_t)(len - offset));
  return true;
}

static inline bool
sbp_unpack_sbp_msg_linux_mem_state_dep_a_t(const u8 *buf, size_t len, sbp_msg_linux_mem_state_dep_a_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->index, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->pid, buf + offset, 2);
  msg->pid = le16toh(msg->pid);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->pmem, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
  for (size_t msgtname_idx = 0; msgtname_idx < 15; msgtname_idx++)
  {

    if (offset + 1 > len)
    {
      return false;
    }
    memcpy(&msg->tname[msgtname_idx], buf + offset, 1);
    // NOLINTNEXTLINE
    offset += 1;
  }
  offset += sbp_unterminated_string_unpack(&msg->cmdline, 236, buf + offset, (uint8_t)(len - offset));
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_linux_sys_state_dep_a_t(const sbp_msg_linux_sys_state_dep_a_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->mem_total) + sizeof(msg->pcpu) + sizeof(msg->pmem) + sizeof(msg->procs_starting) +
         sizeof(msg->procs_stopping) + sizeof(msg->pid_count);
}

static inline bool
sbp_pack_sbp_msg_linux_sys_state_dep_a_t(u8 *buf, size_t len, const sbp_msg_linux_sys_state_dep_a_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_linux_sys_state_dep_a_t(msg) > len)
  {
    return false;
  }

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgmem_total = htole16(msg->mem_total);
  memcpy(buf + offset, &msgmem_total, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgpcpu = msg->pcpu;
  memcpy(buf + offset, &msgpcpu, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgpmem = msg->pmem;
  memcpy(buf + offset, &msgpmem, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgprocs_starting = htole16(msg->procs_starting);
  memcpy(buf + offset, &msgprocs_starting, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgprocs_stopping = htole16(msg->procs_stopping);
  memcpy(buf + offset, &msgprocs_stopping, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgpid_count = htole16(msg->pid_count);
  memcpy(buf + offset, &msgpid_count, 2);
  // NOLINTNEXTLINE
  offset += 2;
  return true;
}

static inline bool
sbp_unpack_sbp_msg_linux_sys_state_dep_a_t(const u8 *buf, size_t len, sbp_msg_linux_sys_state_dep_a_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->mem_total, buf + offset, 2);
  msg->mem_total = le16toh(msg->mem_total);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->pcpu, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->pmem, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->procs_starting, buf + offset, 2);
  msg->procs_starting = le16toh(msg->procs_starting);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->procs_stopping, buf + offset, 2);
  msg->procs_stopping = le16toh(msg->procs_stopping);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->pid_count, buf + offset, 2);
  msg->pid_count = le16toh(msg->pid_count);
  // NOLINTNEXTLINE
  offset += 2;
  return true;
}

static inline size_t
sbp_packed_size_sbp_msg_linux_process_socket_counts_t(const sbp_msg_linux_process_socket_counts_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->index) + sizeof(msg->pid) + sizeof(msg->socket_count) + sizeof(msg->socket_types) +
         sizeof(msg->socket_states) + sbp_unterminated_string_packed_len(&msg->cmdline, 246);
}

static inline bool
sbp_pack_sbp_msg_linux_process_socket_counts_t(u8 *buf, size_t len, const sbp_msg_linux_process_socket_counts_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_linux_process_socket_counts_t(msg) > len)
  {
    return false;
  }

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgindex = msg->index;
  memcpy(buf + offset, &msgindex, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgpid = htole16(msg->pid);
  memcpy(buf + offset, &msgpid, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgsocket_count = htole16(msg->socket_count);
  memcpy(buf + offset, &msgsocket_count, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgsocket_types = htole16(msg->socket_types);
  memcpy(buf + offset, &msgsocket_types, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgsocket_states = htole16(msg->socket_states);
  memcpy(buf + offset, &msgsocket_states, 2);
  // NOLINTNEXTLINE
  offset += 2;
  offset += sbp_unterminated_string_pack(&msg->cmdline, 246, buf + offset, (uint8_t)(len - offset));
  return true;
}

static inline bool
sbp_unpack_sbp_msg_linux_process_socket_counts_t(const u8 *buf, size_t len, sbp_msg_linux_process_socket_counts_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->index, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->pid, buf + offset, 2);
  msg->pid = le16toh(msg->pid);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->socket_count, buf + offset, 2);
  msg->socket_count = le16toh(msg->socket_count);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->socket_types, buf + offset, 2);
  msg->socket_types = le16toh(msg->socket_types);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->socket_states, buf + offset, 2);
  msg->socket_states = le16toh(msg->socket_states);
  // NOLINTNEXTLINE
  offset += 2;
  offset += sbp_unterminated_string_unpack(&msg->cmdline, 246, buf + offset, (uint8_t)(len - offset));
  return true;
}

static inline size_t
sbp_packed_size_sbp_msg_linux_process_socket_queues_t(const sbp_msg_linux_process_socket_queues_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->index) + sizeof(msg->pid) + sizeof(msg->recv_queued) + sizeof(msg->send_queued) +
         sizeof(msg->socket_types) + sizeof(msg->socket_states) + (64 * sizeof(msg->address_of_largest[0])) +
         sbp_unterminated_string_packed_len(&msg->cmdline, 180);
}

static inline bool
sbp_pack_sbp_msg_linux_process_socket_queues_t(u8 *buf, size_t len, const sbp_msg_linux_process_socket_queues_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_linux_process_socket_queues_t(msg) > len)
  {
    return false;
  }

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgindex = msg->index;
  memcpy(buf + offset, &msgindex, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgpid = htole16(msg->pid);
  memcpy(buf + offset, &msgpid, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgrecv_queued = htole16(msg->recv_queued);
  memcpy(buf + offset, &msgrecv_queued, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgsend_queued = htole16(msg->send_queued);
  memcpy(buf + offset, &msgsend_queued, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgsocket_types = htole16(msg->socket_types);
  memcpy(buf + offset, &msgsocket_types, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgsocket_states = htole16(msg->socket_states);
  memcpy(buf + offset, &msgsocket_states, 2);
  // NOLINTNEXTLINE
  offset += 2;
  for (size_t msgaddress_of_largest_idx = 0; msgaddress_of_largest_idx < 64; msgaddress_of_largest_idx++)
  {

    if (offset + 1 > len)
    {
      return false;
    }
    char msgaddress_of_largestmsgaddress_of_largest_idx = msg->address_of_largest[msgaddress_of_largest_idx];
    memcpy(buf + offset, &msgaddress_of_largestmsgaddress_of_largest_idx, 1);
    // NOLINTNEXTLINE
    offset += 1;
  }
  offset += sbp_unterminated_string_pack(&msg->cmdline, 180, buf + offset, (uint8_t)(len - offset));
  return true;
}

static inline bool
sbp_unpack_sbp_msg_linux_process_socket_queues_t(const u8 *buf, size_t len, sbp_msg_linux_process_socket_queues_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->index, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->pid, buf + offset, 2);
  msg->pid = le16toh(msg->pid);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->recv_queued, buf + offset, 2);
  msg->recv_queued = le16toh(msg->recv_queued);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->send_queued, buf + offset, 2);
  msg->send_queued = le16toh(msg->send_queued);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->socket_types, buf + offset, 2);
  msg->socket_types = le16toh(msg->socket_types);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->socket_states, buf + offset, 2);
  msg->socket_states = le16toh(msg->socket_states);
  // NOLINTNEXTLINE
  offset += 2;
  for (size_t msgaddress_of_largest_idx = 0; msgaddress_of_largest_idx < 64; msgaddress_of_largest_idx++)
  {

    if (offset + 1 > len)
    {
      return false;
    }
    memcpy(&msg->address_of_largest[msgaddress_of_largest_idx], buf + offset, 1);
    // NOLINTNEXTLINE
    offset += 1;
  }
  offset += sbp_unterminated_string_unpack(&msg->cmdline, 180, buf + offset, (uint8_t)(len - offset));
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_linux_socket_usage_t(const sbp_msg_linux_socket_usage_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->avg_queue_depth) + sizeof(msg->max_queue_depth) + (16 * sizeof(msg->socket_state_counts[0])) +
         (16 * sizeof(msg->socket_type_counts[0]));
}

static inline bool sbp_pack_sbp_msg_linux_socket_usage_t(u8 *buf, size_t len, const sbp_msg_linux_socket_usage_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_linux_socket_usage_t(msg) > len)
  {
    return false;
  }

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgavg_queue_depth = htole32(msg->avg_queue_depth);
  memcpy(buf + offset, &msgavg_queue_depth, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgmax_queue_depth = htole32(msg->max_queue_depth);
  memcpy(buf + offset, &msgmax_queue_depth, 4);
  // NOLINTNEXTLINE
  offset += 4;
  for (size_t msgsocket_state_counts_idx = 0; msgsocket_state_counts_idx < 16; msgsocket_state_counts_idx++)
  {

    if (offset + 2 > len)
    {
      return false;
    }
    u16 msgsocket_state_countsmsgsocket_state_counts_idx =
        htole16(msg->socket_state_counts[msgsocket_state_counts_idx]);
    memcpy(buf + offset, &msgsocket_state_countsmsgsocket_state_counts_idx, 2);
    // NOLINTNEXTLINE
    offset += 2;
  }
  for (size_t msgsocket_type_counts_idx = 0; msgsocket_type_counts_idx < 16; msgsocket_type_counts_idx++)
  {

    if (offset + 2 > len)
    {
      return false;
    }
    u16 msgsocket_type_countsmsgsocket_type_counts_idx = htole16(msg->socket_type_counts[msgsocket_type_counts_idx]);
    memcpy(buf + offset, &msgsocket_type_countsmsgsocket_type_counts_idx, 2);
    // NOLINTNEXTLINE
    offset += 2;
  }
  return true;
}

static inline bool sbp_unpack_sbp_msg_linux_socket_usage_t(const u8 *buf, size_t len, sbp_msg_linux_socket_usage_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->avg_queue_depth, buf + offset, 4);
  msg->avg_queue_depth = le32toh(msg->avg_queue_depth);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->max_queue_depth, buf + offset, 4);
  msg->max_queue_depth = le32toh(msg->max_queue_depth);
  // NOLINTNEXTLINE
  offset += 4;
  for (size_t msgsocket_state_counts_idx = 0; msgsocket_state_counts_idx < 16; msgsocket_state_counts_idx++)
  {

    if (offset + 2 > len)
    {
      return false;
    }
    memcpy(&msg->socket_state_counts[msgsocket_state_counts_idx], buf + offset, 2);
    msg->socket_state_counts[msgsocket_state_counts_idx] =
        le16toh(msg->socket_state_counts[msgsocket_state_counts_idx]);
    // NOLINTNEXTLINE
    offset += 2;
  }
  for (size_t msgsocket_type_counts_idx = 0; msgsocket_type_counts_idx < 16; msgsocket_type_counts_idx++)
  {

    if (offset + 2 > len)
    {
      return false;
    }
    memcpy(&msg->socket_type_counts[msgsocket_type_counts_idx], buf + offset, 2);
    msg->socket_type_counts[msgsocket_type_counts_idx] = le16toh(msg->socket_type_counts[msgsocket_type_counts_idx]);
    // NOLINTNEXTLINE
    offset += 2;
  }
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_linux_process_fd_count_t(const sbp_msg_linux_process_fd_count_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->index) + sizeof(msg->pid) + sizeof(msg->fd_count) +
         sbp_unterminated_string_packed_len(&msg->cmdline, 250);
}

static inline bool
sbp_pack_sbp_msg_linux_process_fd_count_t(u8 *buf, size_t len, const sbp_msg_linux_process_fd_count_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_linux_process_fd_count_t(msg) > len)
  {
    return false;
  }

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgindex = msg->index;
  memcpy(buf + offset, &msgindex, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgpid = htole16(msg->pid);
  memcpy(buf + offset, &msgpid, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgfd_count = htole16(msg->fd_count);
  memcpy(buf + offset, &msgfd_count, 2);
  // NOLINTNEXTLINE
  offset += 2;
  offset += sbp_unterminated_string_pack(&msg->cmdline, 250, buf + offset, (uint8_t)(len - offset));
  return true;
}

static inline bool
sbp_unpack_sbp_msg_linux_process_fd_count_t(const u8 *buf, size_t len, sbp_msg_linux_process_fd_count_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->index, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->pid, buf + offset, 2);
  msg->pid = le16toh(msg->pid);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->fd_count, buf + offset, 2);
  msg->fd_count = le16toh(msg->fd_count);
  // NOLINTNEXTLINE
  offset += 2;
  offset += sbp_unterminated_string_unpack(&msg->cmdline, 250, buf + offset, (uint8_t)(len - offset));
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_linux_process_fd_summary_t(const sbp_msg_linux_process_fd_summary_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->sys_fd_count) + sbp_sequence_string_packed_len(&msg->most_opened, 251, 0);
}

static inline bool
sbp_pack_sbp_msg_linux_process_fd_summary_t(u8 *buf, size_t len, const sbp_msg_linux_process_fd_summary_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_linux_process_fd_summary_t(msg) > len)
  {
    return false;
  }

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgsys_fd_count = htole32(msg->sys_fd_count);
  memcpy(buf + offset, &msgsys_fd_count, 4);
  // NOLINTNEXTLINE
  offset += 4;
  offset += sbp_sequence_string_pack(&msg->most_opened, 251, 0, buf + offset, (uint8_t)(len - offset));
  return true;
}

static inline bool
sbp_unpack_sbp_msg_linux_process_fd_summary_t(const u8 *buf, size_t len, sbp_msg_linux_process_fd_summary_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->sys_fd_count, buf + offset, 4);
  msg->sys_fd_count = le32toh(msg->sys_fd_count);
  // NOLINTNEXTLINE
  offset += 4;
  offset += sbp_sequence_string_unpack(&msg->most_opened, 251, 0, buf + offset, (uint8_t)(len - offset));
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_linux_cpu_state_t(const sbp_msg_linux_cpu_state_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->index) + sizeof(msg->pid) + sizeof(msg->pcpu) + sizeof(msg->time) + sizeof(msg->flags) +
         (15 * sizeof(msg->tname[0])) + sbp_unterminated_string_packed_len(&msg->cmdline, 231);
}

static inline bool sbp_pack_sbp_msg_linux_cpu_state_t(u8 *buf, size_t len, const sbp_msg_linux_cpu_state_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_linux_cpu_state_t(msg) > len)
  {
    return false;
  }

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgindex = msg->index;
  memcpy(buf + offset, &msgindex, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgpid = htole16(msg->pid);
  memcpy(buf + offset, &msgpid, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgpcpu = msg->pcpu;
  memcpy(buf + offset, &msgpcpu, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgtime = htole32(msg->time);
  memcpy(buf + offset, &msgtime, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgflags = msg->flags;
  memcpy(buf + offset, &msgflags, 1);
  // NOLINTNEXTLINE
  offset += 1;
  for (size_t msgtname_idx = 0; msgtname_idx < 15; msgtname_idx++)
  {

    if (offset + 1 > len)
    {
      return false;
    }
    char msgtnamemsgtname_idx = msg->tname[msgtname_idx];
    memcpy(buf + offset, &msgtnamemsgtname_idx, 1);
    // NOLINTNEXTLINE
    offset += 1;
  }
  offset += sbp_unterminated_string_pack(&msg->cmdline, 231, buf + offset, (uint8_t)(len - offset));
  return true;
}

static inline bool sbp_unpack_sbp_msg_linux_cpu_state_t(const u8 *buf, size_t len, sbp_msg_linux_cpu_state_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->index, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->pid, buf + offset, 2);
  msg->pid = le16toh(msg->pid);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->pcpu, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->time, buf + offset, 4);
  msg->time = le32toh(msg->time);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->flags, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
  for (size_t msgtname_idx = 0; msgtname_idx < 15; msgtname_idx++)
  {

    if (offset + 1 > len)
    {
      return false;
    }
    memcpy(&msg->tname[msgtname_idx], buf + offset, 1);
    // NOLINTNEXTLINE
    offset += 1;
  }
  offset += sbp_unterminated_string_unpack(&msg->cmdline, 231, buf + offset, (uint8_t)(len - offset));
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_linux_mem_state_t(const sbp_msg_linux_mem_state_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->index) + sizeof(msg->pid) + sizeof(msg->pmem) + sizeof(msg->time) + sizeof(msg->flags) +
         (15 * sizeof(msg->tname[0])) + sbp_unterminated_string_packed_len(&msg->cmdline, 231);
}

static inline bool sbp_pack_sbp_msg_linux_mem_state_t(u8 *buf, size_t len, const sbp_msg_linux_mem_state_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_linux_mem_state_t(msg) > len)
  {
    return false;
  }

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgindex = msg->index;
  memcpy(buf + offset, &msgindex, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgpid = htole16(msg->pid);
  memcpy(buf + offset, &msgpid, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgpmem = msg->pmem;
  memcpy(buf + offset, &msgpmem, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgtime = htole32(msg->time);
  memcpy(buf + offset, &msgtime, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgflags = msg->flags;
  memcpy(buf + offset, &msgflags, 1);
  // NOLINTNEXTLINE
  offset += 1;
  for (size_t msgtname_idx = 0; msgtname_idx < 15; msgtname_idx++)
  {

    if (offset + 1 > len)
    {
      return false;
    }
    char msgtnamemsgtname_idx = msg->tname[msgtname_idx];
    memcpy(buf + offset, &msgtnamemsgtname_idx, 1);
    // NOLINTNEXTLINE
    offset += 1;
  }
  offset += sbp_unterminated_string_pack(&msg->cmdline, 231, buf + offset, (uint8_t)(len - offset));
  return true;
}

static inline bool sbp_unpack_sbp_msg_linux_mem_state_t(const u8 *buf, size_t len, sbp_msg_linux_mem_state_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->index, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->pid, buf + offset, 2);
  msg->pid = le16toh(msg->pid);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->pmem, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->time, buf + offset, 4);
  msg->time = le32toh(msg->time);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->flags, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
  for (size_t msgtname_idx = 0; msgtname_idx < 15; msgtname_idx++)
  {

    if (offset + 1 > len)
    {
      return false;
    }
    memcpy(&msg->tname[msgtname_idx], buf + offset, 1);
    // NOLINTNEXTLINE
    offset += 1;
  }
  offset += sbp_unterminated_string_unpack(&msg->cmdline, 231, buf + offset, (uint8_t)(len - offset));
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_linux_sys_state_t(const sbp_msg_linux_sys_state_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->mem_total) + sizeof(msg->pcpu) + sizeof(msg->pmem) + sizeof(msg->procs_starting) +
         sizeof(msg->procs_stopping) + sizeof(msg->pid_count) + sizeof(msg->time) + sizeof(msg->flags);
}

static inline bool sbp_pack_sbp_msg_linux_sys_state_t(u8 *buf, size_t len, const sbp_msg_linux_sys_state_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_linux_sys_state_t(msg) > len)
  {
    return false;
  }

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgmem_total = htole16(msg->mem_total);
  memcpy(buf + offset, &msgmem_total, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgpcpu = msg->pcpu;
  memcpy(buf + offset, &msgpcpu, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgpmem = msg->pmem;
  memcpy(buf + offset, &msgpmem, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgprocs_starting = htole16(msg->procs_starting);
  memcpy(buf + offset, &msgprocs_starting, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgprocs_stopping = htole16(msg->procs_stopping);
  memcpy(buf + offset, &msgprocs_stopping, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgpid_count = htole16(msg->pid_count);
  memcpy(buf + offset, &msgpid_count, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgtime = htole32(msg->time);
  memcpy(buf + offset, &msgtime, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgflags = msg->flags;
  memcpy(buf + offset, &msgflags, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline bool sbp_unpack_sbp_msg_linux_sys_state_t(const u8 *buf, size_t len, sbp_msg_linux_sys_state_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->mem_total, buf + offset, 2);
  msg->mem_total = le16toh(msg->mem_total);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->pcpu, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->pmem, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->procs_starting, buf + offset, 2);
  msg->procs_starting = le16toh(msg->procs_starting);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->procs_stopping, buf + offset, 2);
  msg->procs_stopping = le16toh(msg->procs_stopping);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->pid_count, buf + offset, 2);
  msg->pid_count = le16toh(msg->pid_count);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->time, buf + offset, 4);
  msg->time = le32toh(msg->time);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->flags, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

#endif
