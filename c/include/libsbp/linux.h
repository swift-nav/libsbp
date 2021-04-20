#ifndef LIBSBP_LINUX_MESSAGES_H
#define LIBSBP_LINUX_MESSAGES_H

#include <endian.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>

#include <libsbp/common.h>
/** List CPU state on the system. DEPRECATED.
 *
 * This message indicates the process state of the top 10 heaviest
 * consumers of CPU on the system.
 */
#define SBP_MSG_LINUX_CPU_STATE_DEP_A 0x7F00

typedef struct {
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
   * Unused
   */
  u8 n_tname;
  /**
   * the command line (as much as it fits in the remaining packet)
   */
  char cmdline[236];
  /**
   * Unused
   */
  u8 n_cmdline;
} sbp_msg_linux_cpu_state_dep_a_t;

static inline size_t sbp_packed_size_sbp_msg_linux_cpu_state_dep_a_t(
    const sbp_msg_linux_cpu_state_dep_a_t *msg) {
  (void)msg;
  return 0 + sizeof(msg->index) + sizeof(msg->pid) + sizeof(msg->pcpu) + 15 +
         (strlen(msg->cmdline) + 1);
}

static inline bool sbp_pack_sbp_msg_linux_cpu_state_dep_a_t(
    u8 *buf, size_t len, const sbp_msg_linux_cpu_state_dep_a_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_linux_cpu_state_dep_a_t(msg) > len) {
    return false;
  }

  if (offset + 1 > len) {
    return false;
  }
  u8 msgindex = msg->index;
  memcpy(buf + offset, &msgindex, 1);
  offset += 1;

  if (offset + 2 > len) {
    return false;
  }
  u16 msgpid = msg->pid;
  msgpid = htole16(msgpid);
  memcpy(buf + offset, &msgpid, 2);
  offset += 2;

  if (offset + 1 > len) {
    return false;
  }
  u8 msgpcpu = msg->pcpu;
  memcpy(buf + offset, &msgpcpu, 1);
  offset += 1;
  memcpy(buf + offset, msg->tname, sizeof(msg->tname));
  offset += sizeof(msg->tname);
  strcpy((char *)(buf + offset), msg->cmdline);
  offset += strlen(msg->cmdline) + 1;
  return true;
}

static inline bool sbp_unpack_sbp_msg_linux_cpu_state_dep_a_t(
    const u8 *buf, size_t len, sbp_msg_linux_cpu_state_dep_a_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->index, buf + offset, 1);
  offset += 1;

  if (offset + 2 > len) {
    return false;
  }
  memcpy(&msg->pid, buf + offset, 2);
  msg->pid = le16toh(msg->pid);
  offset += 2;

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->pcpu, buf + offset, 1);
  offset += 1;
  memcpy(msg->tname, buf + offset, sizeof(msg->tname));
  offset += sizeof(msg->tname);
  strcpy(msg->cmdline, (const char *)buf + offset);
  offset += strlen(msg->cmdline) + 1;
  return true;
}
/** List memory state on the system. DEPRECATED.
 *
 * This message indicates the process state of the top 10 heaviest
 * consumers of memory on the system.
 */
#define SBP_MSG_LINUX_MEM_STATE_DEP_A 0x7F01

typedef struct {
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
   * Unused
   */
  u8 n_tname;
  /**
   * the command line (as much as it fits in the remaining packet)
   */
  char cmdline[236];
  /**
   * Unused
   */
  u8 n_cmdline;
} sbp_msg_linux_mem_state_dep_a_t;

static inline size_t sbp_packed_size_sbp_msg_linux_mem_state_dep_a_t(
    const sbp_msg_linux_mem_state_dep_a_t *msg) {
  (void)msg;
  return 0 + sizeof(msg->index) + sizeof(msg->pid) + sizeof(msg->pmem) + 15 +
         (strlen(msg->cmdline) + 1);
}

static inline bool sbp_pack_sbp_msg_linux_mem_state_dep_a_t(
    u8 *buf, size_t len, const sbp_msg_linux_mem_state_dep_a_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_linux_mem_state_dep_a_t(msg) > len) {
    return false;
  }

  if (offset + 1 > len) {
    return false;
  }
  u8 msgindex = msg->index;
  memcpy(buf + offset, &msgindex, 1);
  offset += 1;

  if (offset + 2 > len) {
    return false;
  }
  u16 msgpid = msg->pid;
  msgpid = htole16(msgpid);
  memcpy(buf + offset, &msgpid, 2);
  offset += 2;

  if (offset + 1 > len) {
    return false;
  }
  u8 msgpmem = msg->pmem;
  memcpy(buf + offset, &msgpmem, 1);
  offset += 1;
  memcpy(buf + offset, msg->tname, sizeof(msg->tname));
  offset += sizeof(msg->tname);
  strcpy((char *)(buf + offset), msg->cmdline);
  offset += strlen(msg->cmdline) + 1;
  return true;
}

static inline bool sbp_unpack_sbp_msg_linux_mem_state_dep_a_t(
    const u8 *buf, size_t len, sbp_msg_linux_mem_state_dep_a_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->index, buf + offset, 1);
  offset += 1;

  if (offset + 2 > len) {
    return false;
  }
  memcpy(&msg->pid, buf + offset, 2);
  msg->pid = le16toh(msg->pid);
  offset += 2;

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->pmem, buf + offset, 1);
  offset += 1;
  memcpy(msg->tname, buf + offset, sizeof(msg->tname));
  offset += sizeof(msg->tname);
  strcpy(msg->cmdline, (const char *)buf + offset);
  offset += strlen(msg->cmdline) + 1;
  return true;
}
/** CPU, Memory and Process Starts/Stops. DEPRECATED.
 *
 * This presents a summary of CPU and memory utilization.
 */
#define SBP_MSG_LINUX_SYS_STATE_DEP_A 0x7F02

typedef struct {
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
} sbp_msg_linux_sys_state_dep_a_t;

static inline size_t sbp_packed_size_sbp_msg_linux_sys_state_dep_a_t(
    const sbp_msg_linux_sys_state_dep_a_t *msg) {
  (void)msg;
  return 0 + sizeof(msg->mem_total) + sizeof(msg->pcpu) + sizeof(msg->pmem) +
         sizeof(msg->procs_starting) + sizeof(msg->procs_stopping) +
         sizeof(msg->pid_count);
}

static inline bool sbp_pack_sbp_msg_linux_sys_state_dep_a_t(
    u8 *buf, size_t len, const sbp_msg_linux_sys_state_dep_a_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_linux_sys_state_dep_a_t(msg) > len) {
    return false;
  }

  if (offset + 2 > len) {
    return false;
  }
  u16 msgmem_total = msg->mem_total;
  msgmem_total = htole16(msgmem_total);
  memcpy(buf + offset, &msgmem_total, 2);
  offset += 2;

  if (offset + 1 > len) {
    return false;
  }
  u8 msgpcpu = msg->pcpu;
  memcpy(buf + offset, &msgpcpu, 1);
  offset += 1;

  if (offset + 1 > len) {
    return false;
  }
  u8 msgpmem = msg->pmem;
  memcpy(buf + offset, &msgpmem, 1);
  offset += 1;

  if (offset + 2 > len) {
    return false;
  }
  u16 msgprocs_starting = msg->procs_starting;
  msgprocs_starting = htole16(msgprocs_starting);
  memcpy(buf + offset, &msgprocs_starting, 2);
  offset += 2;

  if (offset + 2 > len) {
    return false;
  }
  u16 msgprocs_stopping = msg->procs_stopping;
  msgprocs_stopping = htole16(msgprocs_stopping);
  memcpy(buf + offset, &msgprocs_stopping, 2);
  offset += 2;

  if (offset + 2 > len) {
    return false;
  }
  u16 msgpid_count = msg->pid_count;
  msgpid_count = htole16(msgpid_count);
  memcpy(buf + offset, &msgpid_count, 2);
  offset += 2;
  return true;
}

static inline bool sbp_unpack_sbp_msg_linux_sys_state_dep_a_t(
    const u8 *buf, size_t len, sbp_msg_linux_sys_state_dep_a_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  if (offset + 2 > len) {
    return false;
  }
  memcpy(&msg->mem_total, buf + offset, 2);
  msg->mem_total = le16toh(msg->mem_total);
  offset += 2;

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->pcpu, buf + offset, 1);
  offset += 1;

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->pmem, buf + offset, 1);
  offset += 1;

  if (offset + 2 > len) {
    return false;
  }
  memcpy(&msg->procs_starting, buf + offset, 2);
  msg->procs_starting = le16toh(msg->procs_starting);
  offset += 2;

  if (offset + 2 > len) {
    return false;
  }
  memcpy(&msg->procs_stopping, buf + offset, 2);
  msg->procs_stopping = le16toh(msg->procs_stopping);
  offset += 2;

  if (offset + 2 > len) {
    return false;
  }
  memcpy(&msg->pid_count, buf + offset, 2);
  msg->pid_count = le16toh(msg->pid_count);
  offset += 2;
  return true;
}
/** A list of processes with high socket counts
 *
 * Top 10 list of processes with high socket counts.
 */
#define SBP_MSG_LINUX_PROCESS_SOCKET_COUNTS 0x7F03

typedef struct {
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
   *   0x1 (tcp), 0x2 (udp), 0x4 (unix stream), 0x8 (unix dgram), 0x10
   * (netlink), and 0x8000 (unknown)
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
  char cmdline[246];
  /**
   * Unused
   */
  u8 n_cmdline;
} sbp_msg_linux_process_socket_counts_t;

static inline size_t sbp_packed_size_sbp_msg_linux_process_socket_counts_t(
    const sbp_msg_linux_process_socket_counts_t *msg) {
  (void)msg;
  return 0 + sizeof(msg->index) + sizeof(msg->pid) + sizeof(msg->socket_count) +
         sizeof(msg->socket_types) + sizeof(msg->socket_states) +
         (strlen(msg->cmdline) + 1);
}

static inline bool sbp_pack_sbp_msg_linux_process_socket_counts_t(
    u8 *buf, size_t len, const sbp_msg_linux_process_socket_counts_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_linux_process_socket_counts_t(msg) > len) {
    return false;
  }

  if (offset + 1 > len) {
    return false;
  }
  u8 msgindex = msg->index;
  memcpy(buf + offset, &msgindex, 1);
  offset += 1;

  if (offset + 2 > len) {
    return false;
  }
  u16 msgpid = msg->pid;
  msgpid = htole16(msgpid);
  memcpy(buf + offset, &msgpid, 2);
  offset += 2;

  if (offset + 2 > len) {
    return false;
  }
  u16 msgsocket_count = msg->socket_count;
  msgsocket_count = htole16(msgsocket_count);
  memcpy(buf + offset, &msgsocket_count, 2);
  offset += 2;

  if (offset + 2 > len) {
    return false;
  }
  u16 msgsocket_types = msg->socket_types;
  msgsocket_types = htole16(msgsocket_types);
  memcpy(buf + offset, &msgsocket_types, 2);
  offset += 2;

  if (offset + 2 > len) {
    return false;
  }
  u16 msgsocket_states = msg->socket_states;
  msgsocket_states = htole16(msgsocket_states);
  memcpy(buf + offset, &msgsocket_states, 2);
  offset += 2;
  strcpy((char *)(buf + offset), msg->cmdline);
  offset += strlen(msg->cmdline) + 1;
  return true;
}

static inline bool sbp_unpack_sbp_msg_linux_process_socket_counts_t(
    const u8 *buf, size_t len, sbp_msg_linux_process_socket_counts_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->index, buf + offset, 1);
  offset += 1;

  if (offset + 2 > len) {
    return false;
  }
  memcpy(&msg->pid, buf + offset, 2);
  msg->pid = le16toh(msg->pid);
  offset += 2;

  if (offset + 2 > len) {
    return false;
  }
  memcpy(&msg->socket_count, buf + offset, 2);
  msg->socket_count = le16toh(msg->socket_count);
  offset += 2;

  if (offset + 2 > len) {
    return false;
  }
  memcpy(&msg->socket_types, buf + offset, 2);
  msg->socket_types = le16toh(msg->socket_types);
  offset += 2;

  if (offset + 2 > len) {
    return false;
  }
  memcpy(&msg->socket_states, buf + offset, 2);
  msg->socket_states = le16toh(msg->socket_states);
  offset += 2;
  strcpy(msg->cmdline, (const char *)buf + offset);
  offset += strlen(msg->cmdline) + 1;
  return true;
}
/** A list of processes with deep socket queues
 *
 * Top 10 list of sockets with deep queues.
 */
#define SBP_MSG_LINUX_PROCESS_SOCKET_QUEUES 0x7F04

typedef struct {
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
   *   0x1 (tcp), 0x2 (udp), 0x4 (unix stream), 0x8 (unix dgram), 0x10
   * (netlink), and 0x8000 (unknown)
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
   * Address of the largest queue, remote or local depending on the
   * directionality of the connection.
   */
  char address_of_largest[64];
  /**
   * Unused
   */
  u8 n_address_of_largest;
  /**
   * the command line of the process in question
   */
  char cmdline[180];
  /**
   * Unused
   */
  u8 n_cmdline;
} sbp_msg_linux_process_socket_queues_t;

static inline size_t sbp_packed_size_sbp_msg_linux_process_socket_queues_t(
    const sbp_msg_linux_process_socket_queues_t *msg) {
  (void)msg;
  return 0 + sizeof(msg->index) + sizeof(msg->pid) + sizeof(msg->recv_queued) +
         sizeof(msg->send_queued) + sizeof(msg->socket_types) +
         sizeof(msg->socket_states) + 64 + (strlen(msg->cmdline) + 1);
}

static inline bool sbp_pack_sbp_msg_linux_process_socket_queues_t(
    u8 *buf, size_t len, const sbp_msg_linux_process_socket_queues_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_linux_process_socket_queues_t(msg) > len) {
    return false;
  }

  if (offset + 1 > len) {
    return false;
  }
  u8 msgindex = msg->index;
  memcpy(buf + offset, &msgindex, 1);
  offset += 1;

  if (offset + 2 > len) {
    return false;
  }
  u16 msgpid = msg->pid;
  msgpid = htole16(msgpid);
  memcpy(buf + offset, &msgpid, 2);
  offset += 2;

  if (offset + 2 > len) {
    return false;
  }
  u16 msgrecv_queued = msg->recv_queued;
  msgrecv_queued = htole16(msgrecv_queued);
  memcpy(buf + offset, &msgrecv_queued, 2);
  offset += 2;

  if (offset + 2 > len) {
    return false;
  }
  u16 msgsend_queued = msg->send_queued;
  msgsend_queued = htole16(msgsend_queued);
  memcpy(buf + offset, &msgsend_queued, 2);
  offset += 2;

  if (offset + 2 > len) {
    return false;
  }
  u16 msgsocket_types = msg->socket_types;
  msgsocket_types = htole16(msgsocket_types);
  memcpy(buf + offset, &msgsocket_types, 2);
  offset += 2;

  if (offset + 2 > len) {
    return false;
  }
  u16 msgsocket_states = msg->socket_states;
  msgsocket_states = htole16(msgsocket_states);
  memcpy(buf + offset, &msgsocket_states, 2);
  offset += 2;
  memcpy(buf + offset, msg->address_of_largest,
         sizeof(msg->address_of_largest));
  offset += sizeof(msg->address_of_largest);
  strcpy((char *)(buf + offset), msg->cmdline);
  offset += strlen(msg->cmdline) + 1;
  return true;
}

static inline bool sbp_unpack_sbp_msg_linux_process_socket_queues_t(
    const u8 *buf, size_t len, sbp_msg_linux_process_socket_queues_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->index, buf + offset, 1);
  offset += 1;

  if (offset + 2 > len) {
    return false;
  }
  memcpy(&msg->pid, buf + offset, 2);
  msg->pid = le16toh(msg->pid);
  offset += 2;

  if (offset + 2 > len) {
    return false;
  }
  memcpy(&msg->recv_queued, buf + offset, 2);
  msg->recv_queued = le16toh(msg->recv_queued);
  offset += 2;

  if (offset + 2 > len) {
    return false;
  }
  memcpy(&msg->send_queued, buf + offset, 2);
  msg->send_queued = le16toh(msg->send_queued);
  offset += 2;

  if (offset + 2 > len) {
    return false;
  }
  memcpy(&msg->socket_types, buf + offset, 2);
  msg->socket_types = le16toh(msg->socket_types);
  offset += 2;

  if (offset + 2 > len) {
    return false;
  }
  memcpy(&msg->socket_states, buf + offset, 2);
  msg->socket_states = le16toh(msg->socket_states);
  offset += 2;
  memcpy(msg->address_of_largest, buf + offset,
         sizeof(msg->address_of_largest));
  offset += sizeof(msg->address_of_largest);
  strcpy(msg->cmdline, (const char *)buf + offset);
  offset += strlen(msg->cmdline) + 1;
  return true;
}
/** Summary of socket usage across the system
 *
 * Summaries the socket usage across the system.
 */
#define SBP_MSG_LINUX_SOCKET_USAGE 0x7F05

typedef struct {
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
   * Unused
   */
  u8 n_socket_state_counts;
  /**
   * A count for each socket type reported in the `socket_types_reported` field,
   * the first entry corresponds to the first enabled bit in `types_reported`.
   */
  u16 socket_type_counts[16];
  /**
   * Unused
   */
  u8 n_socket_type_counts;
} sbp_msg_linux_socket_usage_t;

static inline size_t sbp_packed_size_sbp_msg_linux_socket_usage_t(
    const sbp_msg_linux_socket_usage_t *msg) {
  (void)msg;
  return 0 + sizeof(msg->avg_queue_depth) + sizeof(msg->max_queue_depth) +
         (16 * sizeof(msg->socket_state_counts)) +
         (16 * sizeof(msg->socket_type_counts));
}

static inline bool sbp_pack_sbp_msg_linux_socket_usage_t(
    u8 *buf, size_t len, const sbp_msg_linux_socket_usage_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_linux_socket_usage_t(msg) > len) {
    return false;
  }

  if (offset + 4 > len) {
    return false;
  }
  u32 msgavg_queue_depth = msg->avg_queue_depth;
  msgavg_queue_depth = htole32(msgavg_queue_depth);
  memcpy(buf + offset, &msgavg_queue_depth, 4);
  offset += 4;

  if (offset + 4 > len) {
    return false;
  }
  u32 msgmax_queue_depth = msg->max_queue_depth;
  msgmax_queue_depth = htole32(msgmax_queue_depth);
  memcpy(buf + offset, &msgmax_queue_depth, 4);
  offset += 4;
  for (size_t msgsocket_state_counts_idx = 0; msgsocket_state_counts_idx < 16;
       msgsocket_state_counts_idx++) {
    if (offset + 2 > len) {
      return false;
    }
    u16 msgsocket_state_countsmsgsocket_state_counts_idx =
        msg->socket_state_counts[msgsocket_state_counts_idx];
    msgsocket_state_countsmsgsocket_state_counts_idx =
        htole16(msgsocket_state_countsmsgsocket_state_counts_idx);
    memcpy(buf + offset, &msgsocket_state_countsmsgsocket_state_counts_idx, 2);
    offset += 2;
  }
  for (size_t msgsocket_type_counts_idx = 0; msgsocket_type_counts_idx < 16;
       msgsocket_type_counts_idx++) {
    if (offset + 2 > len) {
      return false;
    }
    u16 msgsocket_type_countsmsgsocket_type_counts_idx =
        msg->socket_type_counts[msgsocket_type_counts_idx];
    msgsocket_type_countsmsgsocket_type_counts_idx =
        htole16(msgsocket_type_countsmsgsocket_type_counts_idx);
    memcpy(buf + offset, &msgsocket_type_countsmsgsocket_type_counts_idx, 2);
    offset += 2;
  }
  return true;
}

static inline bool sbp_unpack_sbp_msg_linux_socket_usage_t(
    const u8 *buf, size_t len, sbp_msg_linux_socket_usage_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  if (offset + 4 > len) {
    return false;
  }
  memcpy(&msg->avg_queue_depth, buf + offset, 4);
  msg->avg_queue_depth = le32toh(msg->avg_queue_depth);
  offset += 4;

  if (offset + 4 > len) {
    return false;
  }
  memcpy(&msg->max_queue_depth, buf + offset, 4);
  msg->max_queue_depth = le32toh(msg->max_queue_depth);
  offset += 4;
  for (size_t msgsocket_state_counts_idx = 0; msgsocket_state_counts_idx < 16;
       msgsocket_state_counts_idx++) {
    if (offset + 2 > len) {
      return false;
    }
    memcpy(&msg->socket_state_counts[msgsocket_state_counts_idx], buf + offset,
           2);
    msg->socket_state_counts[msgsocket_state_counts_idx] =
        le16toh(msg->socket_state_counts[msgsocket_state_counts_idx]);
    offset += 2;
  }
  for (size_t msgsocket_type_counts_idx = 0; msgsocket_type_counts_idx < 16;
       msgsocket_type_counts_idx++) {
    if (offset + 2 > len) {
      return false;
    }
    memcpy(&msg->socket_type_counts[msgsocket_type_counts_idx], buf + offset,
           2);
    msg->socket_type_counts[msgsocket_type_counts_idx] =
        le16toh(msg->socket_type_counts[msgsocket_type_counts_idx]);
    offset += 2;
  }
  return true;
}
/** Summary of processes with large amounts of open file descriptors
 *
 * Top 10 list of processes with a large number of open file descriptors.
 */
#define SBP_MSG_LINUX_PROCESS_FD_COUNT 0x7F06

typedef struct {
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
  char cmdline[250];
  /**
   * Unused
   */
  u8 n_cmdline;
} sbp_msg_linux_process_fd_count_t;

static inline size_t sbp_packed_size_sbp_msg_linux_process_fd_count_t(
    const sbp_msg_linux_process_fd_count_t *msg) {
  (void)msg;
  return 0 + sizeof(msg->index) + sizeof(msg->pid) + sizeof(msg->fd_count) +
         (strlen(msg->cmdline) + 1);
}

static inline bool sbp_pack_sbp_msg_linux_process_fd_count_t(
    u8 *buf, size_t len, const sbp_msg_linux_process_fd_count_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_linux_process_fd_count_t(msg) > len) {
    return false;
  }

  if (offset + 1 > len) {
    return false;
  }
  u8 msgindex = msg->index;
  memcpy(buf + offset, &msgindex, 1);
  offset += 1;

  if (offset + 2 > len) {
    return false;
  }
  u16 msgpid = msg->pid;
  msgpid = htole16(msgpid);
  memcpy(buf + offset, &msgpid, 2);
  offset += 2;

  if (offset + 2 > len) {
    return false;
  }
  u16 msgfd_count = msg->fd_count;
  msgfd_count = htole16(msgfd_count);
  memcpy(buf + offset, &msgfd_count, 2);
  offset += 2;
  strcpy((char *)(buf + offset), msg->cmdline);
  offset += strlen(msg->cmdline) + 1;
  return true;
}

static inline bool sbp_unpack_sbp_msg_linux_process_fd_count_t(
    const u8 *buf, size_t len, sbp_msg_linux_process_fd_count_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->index, buf + offset, 1);
  offset += 1;

  if (offset + 2 > len) {
    return false;
  }
  memcpy(&msg->pid, buf + offset, 2);
  msg->pid = le16toh(msg->pid);
  offset += 2;

  if (offset + 2 > len) {
    return false;
  }
  memcpy(&msg->fd_count, buf + offset, 2);
  msg->fd_count = le16toh(msg->fd_count);
  offset += 2;
  strcpy(msg->cmdline, (const char *)buf + offset);
  offset += strlen(msg->cmdline) + 1;
  return true;
}
/** Summary of open file descriptors on the system
 *
 * Summary of open file descriptors on the system.
 */
#define SBP_MSG_LINUX_PROCESS_FD_SUMMARY 0x7F07

typedef struct {
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
  char most_opened[251];
  /**
   * Unused
   */
  u8 n_most_opened;
} sbp_msg_linux_process_fd_summary_t;

static inline size_t sbp_packed_size_sbp_msg_linux_process_fd_summary_t(
    const sbp_msg_linux_process_fd_summary_t *msg) {
  (void)msg;
  return 0 + sizeof(msg->sys_fd_count) + (strlen(msg->most_opened) + 1);
}

static inline bool sbp_pack_sbp_msg_linux_process_fd_summary_t(
    u8 *buf, size_t len, const sbp_msg_linux_process_fd_summary_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_linux_process_fd_summary_t(msg) > len) {
    return false;
  }

  if (offset + 4 > len) {
    return false;
  }
  u32 msgsys_fd_count = msg->sys_fd_count;
  msgsys_fd_count = htole32(msgsys_fd_count);
  memcpy(buf + offset, &msgsys_fd_count, 4);
  offset += 4;
  strcpy((char *)(buf + offset), msg->most_opened);
  offset += strlen(msg->most_opened) + 1;
  return true;
}

static inline bool sbp_unpack_sbp_msg_linux_process_fd_summary_t(
    const u8 *buf, size_t len, sbp_msg_linux_process_fd_summary_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  if (offset + 4 > len) {
    return false;
  }
  memcpy(&msg->sys_fd_count, buf + offset, 4);
  msg->sys_fd_count = le32toh(msg->sys_fd_count);
  offset += 4;
  strcpy(msg->most_opened, (const char *)buf + offset);
  offset += strlen(msg->most_opened) + 1;
  return true;
}
/** List CPU state on the system
 *
 * This message indicates the process state of the top 10 heaviest
 * consumers of CPU on the system, including a timestamp.
 */
#define SBP_MSG_LINUX_CPU_STATE 0x7F08

#define SBP_LINUX_CPU_STATE_FLAGS_TIMESTAMP_TYPE_MASK (0x7)
#define SBP_LINUX_CPU_STATE_FLAGS_TIMESTAMP_TYPE_SHIFT (0u)
#define SBP_LINUX_CPU_STATE_FLAGS_TIMESTAMP_TYPE_GET(flags)      \
  (((flags) >> SBP_LINUX_CPU_STATE_FLAGS_TIMESTAMP_TYPE_SHIFT) & \
   SBP_LINUX_CPU_STATE_FLAGS_TIMESTAMP_TYPE_MASK)
#define SBP_LINUX_CPU_STATE_FLAGS_TIMESTAMP_TYPE_SET(flags, val)           \
  do {                                                                     \
    ((flags) |= (((val) & (SBP_LINUX_CPU_STATE_FLAGS_TIMESTAMP_TYPE_MASK)) \
                 << (SBP_LINUX_CPU_STATE_FLAGS_TIMESTAMP_TYPE_SHIFT)));    \
  } while (0)

#define SBP_LINUX_CPU_STATE_FLAGS_TIMESTAMP_TYPE_SYSTEM_TIME_IN_SECONDS (0)
#define SBP_LINUX_CPU_STATE_FLAGS_TIMESTAMP_TYPE_GPS_TOW_IN_MILLISECONDS (1)
typedef struct {
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
   * Unused
   */
  u8 n_tname;
  /**
   * the command line (as much as it fits in the remaining packet)
   */
  char cmdline[231];
  /**
   * Unused
   */
  u8 n_cmdline;
} sbp_msg_linux_cpu_state_t;

static inline size_t sbp_packed_size_sbp_msg_linux_cpu_state_t(
    const sbp_msg_linux_cpu_state_t *msg) {
  (void)msg;
  return 0 + sizeof(msg->index) + sizeof(msg->pid) + sizeof(msg->pcpu) +
         sizeof(msg->time) + sizeof(msg->flags) + 15 +
         (strlen(msg->cmdline) + 1);
}

static inline bool sbp_pack_sbp_msg_linux_cpu_state_t(
    u8 *buf, size_t len, const sbp_msg_linux_cpu_state_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_linux_cpu_state_t(msg) > len) {
    return false;
  }

  if (offset + 1 > len) {
    return false;
  }
  u8 msgindex = msg->index;
  memcpy(buf + offset, &msgindex, 1);
  offset += 1;

  if (offset + 2 > len) {
    return false;
  }
  u16 msgpid = msg->pid;
  msgpid = htole16(msgpid);
  memcpy(buf + offset, &msgpid, 2);
  offset += 2;

  if (offset + 1 > len) {
    return false;
  }
  u8 msgpcpu = msg->pcpu;
  memcpy(buf + offset, &msgpcpu, 1);
  offset += 1;

  if (offset + 4 > len) {
    return false;
  }
  u32 msgtime = msg->time;
  msgtime = htole32(msgtime);
  memcpy(buf + offset, &msgtime, 4);
  offset += 4;

  if (offset + 1 > len) {
    return false;
  }
  u8 msgflags = msg->flags;
  memcpy(buf + offset, &msgflags, 1);
  offset += 1;
  memcpy(buf + offset, msg->tname, sizeof(msg->tname));
  offset += sizeof(msg->tname);
  strcpy((char *)(buf + offset), msg->cmdline);
  offset += strlen(msg->cmdline) + 1;
  return true;
}

static inline bool sbp_unpack_sbp_msg_linux_cpu_state_t(
    const u8 *buf, size_t len, sbp_msg_linux_cpu_state_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->index, buf + offset, 1);
  offset += 1;

  if (offset + 2 > len) {
    return false;
  }
  memcpy(&msg->pid, buf + offset, 2);
  msg->pid = le16toh(msg->pid);
  offset += 2;

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->pcpu, buf + offset, 1);
  offset += 1;

  if (offset + 4 > len) {
    return false;
  }
  memcpy(&msg->time, buf + offset, 4);
  msg->time = le32toh(msg->time);
  offset += 4;

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->flags, buf + offset, 1);
  offset += 1;
  memcpy(msg->tname, buf + offset, sizeof(msg->tname));
  offset += sizeof(msg->tname);
  strcpy(msg->cmdline, (const char *)buf + offset);
  offset += strlen(msg->cmdline) + 1;
  return true;
}
/** List memory state on the system
 *
 * This message indicates the process state of the top 10 heaviest
 * consumers of memory on the system, including a timestamp.
 */
#define SBP_MSG_LINUX_MEM_STATE 0x7F09

#define SBP_LINUX_MEM_STATE_FLAGS_TIMESTAMP_TYPE_MASK (0x7)
#define SBP_LINUX_MEM_STATE_FLAGS_TIMESTAMP_TYPE_SHIFT (0u)
#define SBP_LINUX_MEM_STATE_FLAGS_TIMESTAMP_TYPE_GET(flags)      \
  (((flags) >> SBP_LINUX_MEM_STATE_FLAGS_TIMESTAMP_TYPE_SHIFT) & \
   SBP_LINUX_MEM_STATE_FLAGS_TIMESTAMP_TYPE_MASK)
#define SBP_LINUX_MEM_STATE_FLAGS_TIMESTAMP_TYPE_SET(flags, val)           \
  do {                                                                     \
    ((flags) |= (((val) & (SBP_LINUX_MEM_STATE_FLAGS_TIMESTAMP_TYPE_MASK)) \
                 << (SBP_LINUX_MEM_STATE_FLAGS_TIMESTAMP_TYPE_SHIFT)));    \
  } while (0)

#define SBP_LINUX_MEM_STATE_FLAGS_TIMESTAMP_TYPE_SYSTEM_TIME_IN_SECONDS (0)
#define SBP_LINUX_MEM_STATE_FLAGS_TIMESTAMP_TYPE_GPS_TOW_IN_MILLISECONDS (1)
typedef struct {
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
   * Unused
   */
  u8 n_tname;
  /**
   * the command line (as much as it fits in the remaining packet)
   */
  char cmdline[231];
  /**
   * Unused
   */
  u8 n_cmdline;
} sbp_msg_linux_mem_state_t;

static inline size_t sbp_packed_size_sbp_msg_linux_mem_state_t(
    const sbp_msg_linux_mem_state_t *msg) {
  (void)msg;
  return 0 + sizeof(msg->index) + sizeof(msg->pid) + sizeof(msg->pmem) +
         sizeof(msg->time) + sizeof(msg->flags) + 15 +
         (strlen(msg->cmdline) + 1);
}

static inline bool sbp_pack_sbp_msg_linux_mem_state_t(
    u8 *buf, size_t len, const sbp_msg_linux_mem_state_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_linux_mem_state_t(msg) > len) {
    return false;
  }

  if (offset + 1 > len) {
    return false;
  }
  u8 msgindex = msg->index;
  memcpy(buf + offset, &msgindex, 1);
  offset += 1;

  if (offset + 2 > len) {
    return false;
  }
  u16 msgpid = msg->pid;
  msgpid = htole16(msgpid);
  memcpy(buf + offset, &msgpid, 2);
  offset += 2;

  if (offset + 1 > len) {
    return false;
  }
  u8 msgpmem = msg->pmem;
  memcpy(buf + offset, &msgpmem, 1);
  offset += 1;

  if (offset + 4 > len) {
    return false;
  }
  u32 msgtime = msg->time;
  msgtime = htole32(msgtime);
  memcpy(buf + offset, &msgtime, 4);
  offset += 4;

  if (offset + 1 > len) {
    return false;
  }
  u8 msgflags = msg->flags;
  memcpy(buf + offset, &msgflags, 1);
  offset += 1;
  memcpy(buf + offset, msg->tname, sizeof(msg->tname));
  offset += sizeof(msg->tname);
  strcpy((char *)(buf + offset), msg->cmdline);
  offset += strlen(msg->cmdline) + 1;
  return true;
}

static inline bool sbp_unpack_sbp_msg_linux_mem_state_t(
    const u8 *buf, size_t len, sbp_msg_linux_mem_state_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->index, buf + offset, 1);
  offset += 1;

  if (offset + 2 > len) {
    return false;
  }
  memcpy(&msg->pid, buf + offset, 2);
  msg->pid = le16toh(msg->pid);
  offset += 2;

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->pmem, buf + offset, 1);
  offset += 1;

  if (offset + 4 > len) {
    return false;
  }
  memcpy(&msg->time, buf + offset, 4);
  msg->time = le32toh(msg->time);
  offset += 4;

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->flags, buf + offset, 1);
  offset += 1;
  memcpy(msg->tname, buf + offset, sizeof(msg->tname));
  offset += sizeof(msg->tname);
  strcpy(msg->cmdline, (const char *)buf + offset);
  offset += strlen(msg->cmdline) + 1;
  return true;
}
/** CPU, Memory and Process Starts/Stops.
 *
 * This presents a summary of CPU and memory utilization, including a timestamp.
 */
#define SBP_MSG_LINUX_SYS_STATE 0x7F0A

#define SBP_LINUX_SYS_STATE_FLAGS_TIMESTAMP_TYPE_MASK (0x7)
#define SBP_LINUX_SYS_STATE_FLAGS_TIMESTAMP_TYPE_SHIFT (0u)
#define SBP_LINUX_SYS_STATE_FLAGS_TIMESTAMP_TYPE_GET(flags)      \
  (((flags) >> SBP_LINUX_SYS_STATE_FLAGS_TIMESTAMP_TYPE_SHIFT) & \
   SBP_LINUX_SYS_STATE_FLAGS_TIMESTAMP_TYPE_MASK)
#define SBP_LINUX_SYS_STATE_FLAGS_TIMESTAMP_TYPE_SET(flags, val)           \
  do {                                                                     \
    ((flags) |= (((val) & (SBP_LINUX_SYS_STATE_FLAGS_TIMESTAMP_TYPE_MASK)) \
                 << (SBP_LINUX_SYS_STATE_FLAGS_TIMESTAMP_TYPE_SHIFT)));    \
  } while (0)

#define SBP_LINUX_SYS_STATE_FLAGS_TIMESTAMP_TYPE_SYSTEM_TIME_IN_SECONDS (0)
#define SBP_LINUX_SYS_STATE_FLAGS_TIMESTAMP_TYPE_GPS_TOW_IN_MILLISECONDS (1)
typedef struct {
  /**
   * total system memory, in MiB
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
  /**
   * timestamp of message, refer to flags field for how to interpret
   */
  u32 time;
  /**
   * flags
   */
  u8 flags;
} sbp_msg_linux_sys_state_t;

static inline size_t sbp_packed_size_sbp_msg_linux_sys_state_t(
    const sbp_msg_linux_sys_state_t *msg) {
  (void)msg;
  return 0 + sizeof(msg->mem_total) + sizeof(msg->pcpu) + sizeof(msg->pmem) +
         sizeof(msg->procs_starting) + sizeof(msg->procs_stopping) +
         sizeof(msg->pid_count) + sizeof(msg->time) + sizeof(msg->flags);
}

static inline bool sbp_pack_sbp_msg_linux_sys_state_t(
    u8 *buf, size_t len, const sbp_msg_linux_sys_state_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_linux_sys_state_t(msg) > len) {
    return false;
  }

  if (offset + 2 > len) {
    return false;
  }
  u16 msgmem_total = msg->mem_total;
  msgmem_total = htole16(msgmem_total);
  memcpy(buf + offset, &msgmem_total, 2);
  offset += 2;

  if (offset + 1 > len) {
    return false;
  }
  u8 msgpcpu = msg->pcpu;
  memcpy(buf + offset, &msgpcpu, 1);
  offset += 1;

  if (offset + 1 > len) {
    return false;
  }
  u8 msgpmem = msg->pmem;
  memcpy(buf + offset, &msgpmem, 1);
  offset += 1;

  if (offset + 2 > len) {
    return false;
  }
  u16 msgprocs_starting = msg->procs_starting;
  msgprocs_starting = htole16(msgprocs_starting);
  memcpy(buf + offset, &msgprocs_starting, 2);
  offset += 2;

  if (offset + 2 > len) {
    return false;
  }
  u16 msgprocs_stopping = msg->procs_stopping;
  msgprocs_stopping = htole16(msgprocs_stopping);
  memcpy(buf + offset, &msgprocs_stopping, 2);
  offset += 2;

  if (offset + 2 > len) {
    return false;
  }
  u16 msgpid_count = msg->pid_count;
  msgpid_count = htole16(msgpid_count);
  memcpy(buf + offset, &msgpid_count, 2);
  offset += 2;

  if (offset + 4 > len) {
    return false;
  }
  u32 msgtime = msg->time;
  msgtime = htole32(msgtime);
  memcpy(buf + offset, &msgtime, 4);
  offset += 4;

  if (offset + 1 > len) {
    return false;
  }
  u8 msgflags = msg->flags;
  memcpy(buf + offset, &msgflags, 1);
  offset += 1;
  return true;
}

static inline bool sbp_unpack_sbp_msg_linux_sys_state_t(
    const u8 *buf, size_t len, sbp_msg_linux_sys_state_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  if (offset + 2 > len) {
    return false;
  }
  memcpy(&msg->mem_total, buf + offset, 2);
  msg->mem_total = le16toh(msg->mem_total);
  offset += 2;

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->pcpu, buf + offset, 1);
  offset += 1;

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->pmem, buf + offset, 1);
  offset += 1;

  if (offset + 2 > len) {
    return false;
  }
  memcpy(&msg->procs_starting, buf + offset, 2);
  msg->procs_starting = le16toh(msg->procs_starting);
  offset += 2;

  if (offset + 2 > len) {
    return false;
  }
  memcpy(&msg->procs_stopping, buf + offset, 2);
  msg->procs_stopping = le16toh(msg->procs_stopping);
  offset += 2;

  if (offset + 2 > len) {
    return false;
  }
  memcpy(&msg->pid_count, buf + offset, 2);
  msg->pid_count = le16toh(msg->pid_count);
  offset += 2;

  if (offset + 4 > len) {
    return false;
  }
  memcpy(&msg->time, buf + offset, 4);
  msg->time = le32toh(msg->time);
  offset += 4;

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->flags, buf + offset, 1);
  offset += 1;
  return true;
}

#endif /* LIBSBP_LINUX_MESSAGES_H */