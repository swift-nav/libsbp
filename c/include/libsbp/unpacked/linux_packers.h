#ifndef LIBSBP_LINUX_PACKERS_H
#define LIBSBP_LINUX_PACKERS_H

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
#include <libsbp/unpacked/base.h>
#include <libsbp/string.h>
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_linux_cpu_state_dep_a_t(const sbp_msg_linux_cpu_state_dep_a_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_u8(&msg->index);
  packed_size += sbp_packed_size_u16(&msg->pid);
  packed_size += sbp_packed_size_u8(&msg->pcpu);
  packed_size += ( 15 * sbp_packed_size_char(&msg->tname[0]));
  packed_size += sbp_unterminated_string_packed_len(&msg->cmdline, 236
      );
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_linux_cpu_state_dep_a_t(u8 *buf, size_t len, const sbp_msg_linux_cpu_state_dep_a_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_linux_cpu_state_dep_a_t(msg) > len) { return false; }
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->index);
  offset += sbp_pack_u16(buf + offset, len - offset, &msg->pid);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->pcpu);
  for (uint8_t i = 0; i < 15; i++) 
  {
    offset += sbp_pack_char(buf + offset, len - offset, &msg->tname[i]);
  }
  offset += sbp_unterminated_string_pack(&msg->cmdline, 236,
      buf + offset, (uint8_t)(len - offset));
  return true;
}

static inline bool sbp_unpack_sbp_msg_linux_cpu_state_dep_a_t(const uint8_t *buf, size_t len, sbp_msg_linux_cpu_state_dep_a_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->index);
  offset += sbp_unpack_u16(buf + offset, len - offset, &msg->pid);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->pcpu);
  for (uint8_t i = 0; i < 15; i++)
  {
    offset += sbp_unpack_char(buf + offset, len - offset, &msg->tname[i]);
  }
  offset += sbp_unterminated_string_unpack(&msg->cmdline, 236,
      buf + offset, (uint8_t)(len - offset));
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_linux_mem_state_dep_a_t(const sbp_msg_linux_mem_state_dep_a_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_u8(&msg->index);
  packed_size += sbp_packed_size_u16(&msg->pid);
  packed_size += sbp_packed_size_u8(&msg->pmem);
  packed_size += ( 15 * sbp_packed_size_char(&msg->tname[0]));
  packed_size += sbp_unterminated_string_packed_len(&msg->cmdline, 236
      );
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_linux_mem_state_dep_a_t(u8 *buf, size_t len, const sbp_msg_linux_mem_state_dep_a_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_linux_mem_state_dep_a_t(msg) > len) { return false; }
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->index);
  offset += sbp_pack_u16(buf + offset, len - offset, &msg->pid);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->pmem);
  for (uint8_t i = 0; i < 15; i++) 
  {
    offset += sbp_pack_char(buf + offset, len - offset, &msg->tname[i]);
  }
  offset += sbp_unterminated_string_pack(&msg->cmdline, 236,
      buf + offset, (uint8_t)(len - offset));
  return true;
}

static inline bool sbp_unpack_sbp_msg_linux_mem_state_dep_a_t(const uint8_t *buf, size_t len, sbp_msg_linux_mem_state_dep_a_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->index);
  offset += sbp_unpack_u16(buf + offset, len - offset, &msg->pid);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->pmem);
  for (uint8_t i = 0; i < 15; i++)
  {
    offset += sbp_unpack_char(buf + offset, len - offset, &msg->tname[i]);
  }
  offset += sbp_unterminated_string_unpack(&msg->cmdline, 236,
      buf + offset, (uint8_t)(len - offset));
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_linux_sys_state_dep_a_t(const sbp_msg_linux_sys_state_dep_a_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_u16(&msg->mem_total);
  packed_size += sbp_packed_size_u8(&msg->pcpu);
  packed_size += sbp_packed_size_u8(&msg->pmem);
  packed_size += sbp_packed_size_u16(&msg->procs_starting);
  packed_size += sbp_packed_size_u16(&msg->procs_stopping);
  packed_size += sbp_packed_size_u16(&msg->pid_count);
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_linux_sys_state_dep_a_t(u8 *buf, size_t len, const sbp_msg_linux_sys_state_dep_a_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_linux_sys_state_dep_a_t(msg) > len) { return false; }
  offset += sbp_pack_u16(buf + offset, len - offset, &msg->mem_total);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->pcpu);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->pmem);
  offset += sbp_pack_u16(buf + offset, len - offset, &msg->procs_starting);
  offset += sbp_pack_u16(buf + offset, len - offset, &msg->procs_stopping);
  offset += sbp_pack_u16(buf + offset, len - offset, &msg->pid_count);
  return true;
}

static inline bool sbp_unpack_sbp_msg_linux_sys_state_dep_a_t(const uint8_t *buf, size_t len, sbp_msg_linux_sys_state_dep_a_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_u16(buf + offset, len - offset, &msg->mem_total);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->pcpu);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->pmem);
  offset += sbp_unpack_u16(buf + offset, len - offset, &msg->procs_starting);
  offset += sbp_unpack_u16(buf + offset, len - offset, &msg->procs_stopping);
  offset += sbp_unpack_u16(buf + offset, len - offset, &msg->pid_count);
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_linux_process_socket_counts_t(const sbp_msg_linux_process_socket_counts_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_u8(&msg->index);
  packed_size += sbp_packed_size_u16(&msg->pid);
  packed_size += sbp_packed_size_u16(&msg->socket_count);
  packed_size += sbp_packed_size_u16(&msg->socket_types);
  packed_size += sbp_packed_size_u16(&msg->socket_states);
  packed_size += sbp_unterminated_string_packed_len(&msg->cmdline, 246
      );
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_linux_process_socket_counts_t(u8 *buf, size_t len, const sbp_msg_linux_process_socket_counts_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_linux_process_socket_counts_t(msg) > len) { return false; }
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->index);
  offset += sbp_pack_u16(buf + offset, len - offset, &msg->pid);
  offset += sbp_pack_u16(buf + offset, len - offset, &msg->socket_count);
  offset += sbp_pack_u16(buf + offset, len - offset, &msg->socket_types);
  offset += sbp_pack_u16(buf + offset, len - offset, &msg->socket_states);
  offset += sbp_unterminated_string_pack(&msg->cmdline, 246,
      buf + offset, (uint8_t)(len - offset));
  return true;
}

static inline bool sbp_unpack_sbp_msg_linux_process_socket_counts_t(const uint8_t *buf, size_t len, sbp_msg_linux_process_socket_counts_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->index);
  offset += sbp_unpack_u16(buf + offset, len - offset, &msg->pid);
  offset += sbp_unpack_u16(buf + offset, len - offset, &msg->socket_count);
  offset += sbp_unpack_u16(buf + offset, len - offset, &msg->socket_types);
  offset += sbp_unpack_u16(buf + offset, len - offset, &msg->socket_states);
  offset += sbp_unterminated_string_unpack(&msg->cmdline, 246,
      buf + offset, (uint8_t)(len - offset));
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_linux_process_socket_queues_t(const sbp_msg_linux_process_socket_queues_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_u8(&msg->index);
  packed_size += sbp_packed_size_u16(&msg->pid);
  packed_size += sbp_packed_size_u16(&msg->recv_queued);
  packed_size += sbp_packed_size_u16(&msg->send_queued);
  packed_size += sbp_packed_size_u16(&msg->socket_types);
  packed_size += sbp_packed_size_u16(&msg->socket_states);
  packed_size += ( 64 * sbp_packed_size_char(&msg->address_of_largest[0]));
  packed_size += sbp_unterminated_string_packed_len(&msg->cmdline, 180
      );
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_linux_process_socket_queues_t(u8 *buf, size_t len, const sbp_msg_linux_process_socket_queues_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_linux_process_socket_queues_t(msg) > len) { return false; }
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->index);
  offset += sbp_pack_u16(buf + offset, len - offset, &msg->pid);
  offset += sbp_pack_u16(buf + offset, len - offset, &msg->recv_queued);
  offset += sbp_pack_u16(buf + offset, len - offset, &msg->send_queued);
  offset += sbp_pack_u16(buf + offset, len - offset, &msg->socket_types);
  offset += sbp_pack_u16(buf + offset, len - offset, &msg->socket_states);
  for (uint8_t i = 0; i < 64; i++) 
  {
    offset += sbp_pack_char(buf + offset, len - offset, &msg->address_of_largest[i]);
  }
  offset += sbp_unterminated_string_pack(&msg->cmdline, 180,
      buf + offset, (uint8_t)(len - offset));
  return true;
}

static inline bool sbp_unpack_sbp_msg_linux_process_socket_queues_t(const uint8_t *buf, size_t len, sbp_msg_linux_process_socket_queues_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->index);
  offset += sbp_unpack_u16(buf + offset, len - offset, &msg->pid);
  offset += sbp_unpack_u16(buf + offset, len - offset, &msg->recv_queued);
  offset += sbp_unpack_u16(buf + offset, len - offset, &msg->send_queued);
  offset += sbp_unpack_u16(buf + offset, len - offset, &msg->socket_types);
  offset += sbp_unpack_u16(buf + offset, len - offset, &msg->socket_states);
  for (uint8_t i = 0; i < 64; i++)
  {
    offset += sbp_unpack_char(buf + offset, len - offset, &msg->address_of_largest[i]);
  }
  offset += sbp_unterminated_string_unpack(&msg->cmdline, 180,
      buf + offset, (uint8_t)(len - offset));
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_linux_socket_usage_t(const sbp_msg_linux_socket_usage_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_u32(&msg->avg_queue_depth);
  packed_size += sbp_packed_size_u32(&msg->max_queue_depth);
  packed_size += ( 16 * sbp_packed_size_u16(&msg->socket_state_counts[0]));
  packed_size += ( 16 * sbp_packed_size_u16(&msg->socket_type_counts[0]));
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_linux_socket_usage_t(u8 *buf, size_t len, const sbp_msg_linux_socket_usage_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_linux_socket_usage_t(msg) > len) { return false; }
  offset += sbp_pack_u32(buf + offset, len - offset, &msg->avg_queue_depth);
  offset += sbp_pack_u32(buf + offset, len - offset, &msg->max_queue_depth);
  for (uint8_t i = 0; i < 16; i++) 
  {
    offset += sbp_pack_u16(buf + offset, len - offset, &msg->socket_state_counts[i]);
  }
  for (uint8_t i = 0; i < 16; i++) 
  {
    offset += sbp_pack_u16(buf + offset, len - offset, &msg->socket_type_counts[i]);
  }
  return true;
}

static inline bool sbp_unpack_sbp_msg_linux_socket_usage_t(const uint8_t *buf, size_t len, sbp_msg_linux_socket_usage_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_u32(buf + offset, len - offset, &msg->avg_queue_depth);
  offset += sbp_unpack_u32(buf + offset, len - offset, &msg->max_queue_depth);
  for (uint8_t i = 0; i < 16; i++)
  {
    offset += sbp_unpack_u16(buf + offset, len - offset, &msg->socket_state_counts[i]);
  }
  for (uint8_t i = 0; i < 16; i++)
  {
    offset += sbp_unpack_u16(buf + offset, len - offset, &msg->socket_type_counts[i]);
  }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_linux_process_fd_count_t(const sbp_msg_linux_process_fd_count_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_u8(&msg->index);
  packed_size += sbp_packed_size_u16(&msg->pid);
  packed_size += sbp_packed_size_u16(&msg->fd_count);
  packed_size += sbp_unterminated_string_packed_len(&msg->cmdline, 250
      );
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_linux_process_fd_count_t(u8 *buf, size_t len, const sbp_msg_linux_process_fd_count_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_linux_process_fd_count_t(msg) > len) { return false; }
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->index);
  offset += sbp_pack_u16(buf + offset, len - offset, &msg->pid);
  offset += sbp_pack_u16(buf + offset, len - offset, &msg->fd_count);
  offset += sbp_unterminated_string_pack(&msg->cmdline, 250,
      buf + offset, (uint8_t)(len - offset));
  return true;
}

static inline bool sbp_unpack_sbp_msg_linux_process_fd_count_t(const uint8_t *buf, size_t len, sbp_msg_linux_process_fd_count_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->index);
  offset += sbp_unpack_u16(buf + offset, len - offset, &msg->pid);
  offset += sbp_unpack_u16(buf + offset, len - offset, &msg->fd_count);
  offset += sbp_unterminated_string_unpack(&msg->cmdline, 250,
      buf + offset, (uint8_t)(len - offset));
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_linux_process_fd_summary_t(const sbp_msg_linux_process_fd_summary_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_u32(&msg->sys_fd_count);
  packed_size += sbp_sequence_string_packed_len(&msg->most_opened, 251
      , 0
      );
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_linux_process_fd_summary_t(u8 *buf, size_t len, const sbp_msg_linux_process_fd_summary_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_linux_process_fd_summary_t(msg) > len) { return false; }
  offset += sbp_pack_u32(buf + offset, len - offset, &msg->sys_fd_count);
  offset += sbp_sequence_string_pack(&msg->most_opened, 251,0,
      buf + offset, (uint8_t)(len - offset));
  return true;
}

static inline bool sbp_unpack_sbp_msg_linux_process_fd_summary_t(const uint8_t *buf, size_t len, sbp_msg_linux_process_fd_summary_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_u32(buf + offset, len - offset, &msg->sys_fd_count);
  offset += sbp_sequence_string_unpack(&msg->most_opened, 251,0,
      buf + offset, (uint8_t)(len - offset));
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_linux_cpu_state_t(const sbp_msg_linux_cpu_state_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_u8(&msg->index);
  packed_size += sbp_packed_size_u16(&msg->pid);
  packed_size += sbp_packed_size_u8(&msg->pcpu);
  packed_size += sbp_packed_size_u32(&msg->time);
  packed_size += sbp_packed_size_u8(&msg->flags);
  packed_size += ( 15 * sbp_packed_size_char(&msg->tname[0]));
  packed_size += sbp_unterminated_string_packed_len(&msg->cmdline, 231
      );
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_linux_cpu_state_t(u8 *buf, size_t len, const sbp_msg_linux_cpu_state_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_linux_cpu_state_t(msg) > len) { return false; }
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->index);
  offset += sbp_pack_u16(buf + offset, len - offset, &msg->pid);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->pcpu);
  offset += sbp_pack_u32(buf + offset, len - offset, &msg->time);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->flags);
  for (uint8_t i = 0; i < 15; i++) 
  {
    offset += sbp_pack_char(buf + offset, len - offset, &msg->tname[i]);
  }
  offset += sbp_unterminated_string_pack(&msg->cmdline, 231,
      buf + offset, (uint8_t)(len - offset));
  return true;
}

static inline bool sbp_unpack_sbp_msg_linux_cpu_state_t(const uint8_t *buf, size_t len, sbp_msg_linux_cpu_state_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->index);
  offset += sbp_unpack_u16(buf + offset, len - offset, &msg->pid);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->pcpu);
  offset += sbp_unpack_u32(buf + offset, len - offset, &msg->time);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->flags);
  for (uint8_t i = 0; i < 15; i++)
  {
    offset += sbp_unpack_char(buf + offset, len - offset, &msg->tname[i]);
  }
  offset += sbp_unterminated_string_unpack(&msg->cmdline, 231,
      buf + offset, (uint8_t)(len - offset));
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_linux_mem_state_t(const sbp_msg_linux_mem_state_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_u8(&msg->index);
  packed_size += sbp_packed_size_u16(&msg->pid);
  packed_size += sbp_packed_size_u8(&msg->pmem);
  packed_size += sbp_packed_size_u32(&msg->time);
  packed_size += sbp_packed_size_u8(&msg->flags);
  packed_size += ( 15 * sbp_packed_size_char(&msg->tname[0]));
  packed_size += sbp_unterminated_string_packed_len(&msg->cmdline, 231
      );
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_linux_mem_state_t(u8 *buf, size_t len, const sbp_msg_linux_mem_state_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_linux_mem_state_t(msg) > len) { return false; }
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->index);
  offset += sbp_pack_u16(buf + offset, len - offset, &msg->pid);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->pmem);
  offset += sbp_pack_u32(buf + offset, len - offset, &msg->time);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->flags);
  for (uint8_t i = 0; i < 15; i++) 
  {
    offset += sbp_pack_char(buf + offset, len - offset, &msg->tname[i]);
  }
  offset += sbp_unterminated_string_pack(&msg->cmdline, 231,
      buf + offset, (uint8_t)(len - offset));
  return true;
}

static inline bool sbp_unpack_sbp_msg_linux_mem_state_t(const uint8_t *buf, size_t len, sbp_msg_linux_mem_state_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->index);
  offset += sbp_unpack_u16(buf + offset, len - offset, &msg->pid);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->pmem);
  offset += sbp_unpack_u32(buf + offset, len - offset, &msg->time);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->flags);
  for (uint8_t i = 0; i < 15; i++)
  {
    offset += sbp_unpack_char(buf + offset, len - offset, &msg->tname[i]);
  }
  offset += sbp_unterminated_string_unpack(&msg->cmdline, 231,
      buf + offset, (uint8_t)(len - offset));
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_linux_sys_state_t(const sbp_msg_linux_sys_state_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_u16(&msg->mem_total);
  packed_size += sbp_packed_size_u8(&msg->pcpu);
  packed_size += sbp_packed_size_u8(&msg->pmem);
  packed_size += sbp_packed_size_u16(&msg->procs_starting);
  packed_size += sbp_packed_size_u16(&msg->procs_stopping);
  packed_size += sbp_packed_size_u16(&msg->pid_count);
  packed_size += sbp_packed_size_u32(&msg->time);
  packed_size += sbp_packed_size_u8(&msg->flags);
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_linux_sys_state_t(u8 *buf, size_t len, const sbp_msg_linux_sys_state_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_linux_sys_state_t(msg) > len) { return false; }
  offset += sbp_pack_u16(buf + offset, len - offset, &msg->mem_total);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->pcpu);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->pmem);
  offset += sbp_pack_u16(buf + offset, len - offset, &msg->procs_starting);
  offset += sbp_pack_u16(buf + offset, len - offset, &msg->procs_stopping);
  offset += sbp_pack_u16(buf + offset, len - offset, &msg->pid_count);
  offset += sbp_pack_u32(buf + offset, len - offset, &msg->time);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->flags);
  return true;
}

static inline bool sbp_unpack_sbp_msg_linux_sys_state_t(const uint8_t *buf, size_t len, sbp_msg_linux_sys_state_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_u16(buf + offset, len - offset, &msg->mem_total);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->pcpu);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->pmem);
  offset += sbp_unpack_u16(buf + offset, len - offset, &msg->procs_starting);
  offset += sbp_unpack_u16(buf + offset, len - offset, &msg->procs_stopping);
  offset += sbp_unpack_u16(buf + offset, len - offset, &msg->pid_count);
  offset += sbp_unpack_u32(buf + offset, len - offset, &msg->time);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->flags);
  return true;
}

#endif
