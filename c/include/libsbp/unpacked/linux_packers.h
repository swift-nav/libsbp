#ifndef LIBSBP_LINUX_PACKERS_H
#define LIBSBP_LINUX_PACKERS_H

#ifndef LIBSBP_LINUX_MESSAGES_H
#error "Do not include this file directly, include libsbp/unpacked/linux.h instead"
#endif

#include <stdbool.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>
#include <math.h>

#include <libsbp/common.h>
#include <libsbp/string.h>

static inline size_t sbp_packed_size_sbp_msg_linux_cpu_state_dep_a_t(const sbp_msg_linux_cpu_state_dep_a_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				sizeof( msg->index )                                                                          
	  +
				sizeof( msg->pid )                                                                          
	  +
				sizeof( msg->pcpu )                                                                          
	  +
		  ( 15 *
        sizeof( msg->tname[0] )
		)                                                                          
	  +
      sbp_unterminated_string_packed_len(&msg->cmdline, 236);
}

static inline bool sbp_pack_sbp_msg_linux_cpu_state_dep_a_t(u8 *buf, size_t len, const sbp_msg_linux_cpu_state_dep_a_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_linux_cpu_state_dep_a_t(msg) > len) { return false; }
  
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->index , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->pid);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->pcpu , 1);
  // NOLINTNEXTLINE
  offset += 1;
		  for(size_t msgtname_idx = 0; msgtname_idx < 15; msgtname_idx++)
			{
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->tname[msgtname_idx] , 1);
  // NOLINTNEXTLINE
  offset += 1;
			}
        offset += sbp_unterminated_string_pack(&msg->cmdline, 236, buf + offset, (uint8_t)(len - offset));
  return true;
}

static inline bool sbp_unpack_sbp_msg_linux_cpu_state_dep_a_t(const u8 *buf, size_t len, sbp_msg_linux_cpu_state_dep_a_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->index, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 2 > len) { return false; }
  msg->pid = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->pcpu, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
		for (size_t msgtname_idx = 0; msgtname_idx < 15; msgtname_idx++)
		{
        
  if (offset + 1 > len) { return false; }
  memcpy(&msg->tname[msgtname_idx], buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
		}
      offset += sbp_unterminated_string_unpack(&msg->cmdline, 236, buf + offset, (uint8_t)(len - offset));
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_linux_mem_state_dep_a_t(const sbp_msg_linux_mem_state_dep_a_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				sizeof( msg->index )                                                                          
	  +
				sizeof( msg->pid )                                                                          
	  +
				sizeof( msg->pmem )                                                                          
	  +
		  ( 15 *
        sizeof( msg->tname[0] )
		)                                                                          
	  +
      sbp_unterminated_string_packed_len(&msg->cmdline, 236);
}

static inline bool sbp_pack_sbp_msg_linux_mem_state_dep_a_t(u8 *buf, size_t len, const sbp_msg_linux_mem_state_dep_a_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_linux_mem_state_dep_a_t(msg) > len) { return false; }
  
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->index , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->pid);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->pmem , 1);
  // NOLINTNEXTLINE
  offset += 1;
		  for(size_t msgtname_idx = 0; msgtname_idx < 15; msgtname_idx++)
			{
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->tname[msgtname_idx] , 1);
  // NOLINTNEXTLINE
  offset += 1;
			}
        offset += sbp_unterminated_string_pack(&msg->cmdline, 236, buf + offset, (uint8_t)(len - offset));
  return true;
}

static inline bool sbp_unpack_sbp_msg_linux_mem_state_dep_a_t(const u8 *buf, size_t len, sbp_msg_linux_mem_state_dep_a_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->index, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 2 > len) { return false; }
  msg->pid = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->pmem, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
		for (size_t msgtname_idx = 0; msgtname_idx < 15; msgtname_idx++)
		{
        
  if (offset + 1 > len) { return false; }
  memcpy(&msg->tname[msgtname_idx], buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
		}
      offset += sbp_unterminated_string_unpack(&msg->cmdline, 236, buf + offset, (uint8_t)(len - offset));
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_linux_sys_state_dep_a_t(const sbp_msg_linux_sys_state_dep_a_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				sizeof( msg->mem_total )                                                                          
	  +
				sizeof( msg->pcpu )                                                                          
	  +
				sizeof( msg->pmem )                                                                          
	  +
				sizeof( msg->procs_starting )                                                                          
	  +
				sizeof( msg->procs_stopping )                                                                          
	  +
				sizeof( msg->pid_count );
}

static inline bool sbp_pack_sbp_msg_linux_sys_state_dep_a_t(u8 *buf, size_t len, const sbp_msg_linux_sys_state_dep_a_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_linux_sys_state_dep_a_t(msg) > len) { return false; }
  
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->mem_total);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->pcpu , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->pmem , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->procs_starting);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->procs_stopping);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->pid_count);
  // NOLINTNEXTLINE
  offset += 2;
  return true;
}

static inline bool sbp_unpack_sbp_msg_linux_sys_state_dep_a_t(const u8 *buf, size_t len, sbp_msg_linux_sys_state_dep_a_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
      
  if (offset + 2 > len) { return false; }
  msg->mem_total = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->pcpu, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->pmem, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 2 > len) { return false; }
  msg->procs_starting = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 2 > len) { return false; }
  msg->procs_stopping = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 2 > len) { return false; }
  msg->pid_count = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_linux_process_socket_counts_t(const sbp_msg_linux_process_socket_counts_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				sizeof( msg->index )                                                                          
	  +
				sizeof( msg->pid )                                                                          
	  +
				sizeof( msg->socket_count )                                                                          
	  +
				sizeof( msg->socket_types )                                                                          
	  +
				sizeof( msg->socket_states )                                                                          
	  +
      sbp_unterminated_string_packed_len(&msg->cmdline, 246);
}

static inline bool sbp_pack_sbp_msg_linux_process_socket_counts_t(u8 *buf, size_t len, const sbp_msg_linux_process_socket_counts_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_linux_process_socket_counts_t(msg) > len) { return false; }
  
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->index , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->pid);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->socket_count);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->socket_types);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->socket_states);
  // NOLINTNEXTLINE
  offset += 2;
        offset += sbp_unterminated_string_pack(&msg->cmdline, 246, buf + offset, (uint8_t)(len - offset));
  return true;
}

static inline bool sbp_unpack_sbp_msg_linux_process_socket_counts_t(const u8 *buf, size_t len, sbp_msg_linux_process_socket_counts_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->index, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 2 > len) { return false; }
  msg->pid = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 2 > len) { return false; }
  msg->socket_count = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 2 > len) { return false; }
  msg->socket_types = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 2 > len) { return false; }
  msg->socket_states = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      offset += sbp_unterminated_string_unpack(&msg->cmdline, 246, buf + offset, (uint8_t)(len - offset));
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_linux_process_socket_queues_t(const sbp_msg_linux_process_socket_queues_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				sizeof( msg->index )                                                                          
	  +
				sizeof( msg->pid )                                                                          
	  +
				sizeof( msg->recv_queued )                                                                          
	  +
				sizeof( msg->send_queued )                                                                          
	  +
				sizeof( msg->socket_types )                                                                          
	  +
				sizeof( msg->socket_states )                                                                          
	  +
		  ( 64 *
        sizeof( msg->address_of_largest[0] )
		)                                                                          
	  +
      sbp_unterminated_string_packed_len(&msg->cmdline, 180);
}

static inline bool sbp_pack_sbp_msg_linux_process_socket_queues_t(u8 *buf, size_t len, const sbp_msg_linux_process_socket_queues_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_linux_process_socket_queues_t(msg) > len) { return false; }
  
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->index , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->pid);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->recv_queued);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->send_queued);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->socket_types);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->socket_states);
  // NOLINTNEXTLINE
  offset += 2;
		  for(size_t msgaddress_of_largest_idx = 0; msgaddress_of_largest_idx < 64; msgaddress_of_largest_idx++)
			{
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->address_of_largest[msgaddress_of_largest_idx] , 1);
  // NOLINTNEXTLINE
  offset += 1;
			}
        offset += sbp_unterminated_string_pack(&msg->cmdline, 180, buf + offset, (uint8_t)(len - offset));
  return true;
}

static inline bool sbp_unpack_sbp_msg_linux_process_socket_queues_t(const u8 *buf, size_t len, sbp_msg_linux_process_socket_queues_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->index, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 2 > len) { return false; }
  msg->pid = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 2 > len) { return false; }
  msg->recv_queued = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 2 > len) { return false; }
  msg->send_queued = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 2 > len) { return false; }
  msg->socket_types = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 2 > len) { return false; }
  msg->socket_states = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
		for (size_t msgaddress_of_largest_idx = 0; msgaddress_of_largest_idx < 64; msgaddress_of_largest_idx++)
		{
        
  if (offset + 1 > len) { return false; }
  memcpy(&msg->address_of_largest[msgaddress_of_largest_idx], buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
		}
      offset += sbp_unterminated_string_unpack(&msg->cmdline, 180, buf + offset, (uint8_t)(len - offset));
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_linux_socket_usage_t(const sbp_msg_linux_socket_usage_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				sizeof( msg->avg_queue_depth )                                                                          
	  +
				sizeof( msg->max_queue_depth )                                                                          
	  +
		  ( 16 *
        sizeof( msg->socket_state_counts[0] )
		)                                                                          
	  +
		  ( 16 *
        sizeof( msg->socket_type_counts[0] )
		);
}

static inline bool sbp_pack_sbp_msg_linux_socket_usage_t(u8 *buf, size_t len, const sbp_msg_linux_socket_usage_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_linux_socket_usage_t(msg) > len) { return false; }
  
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->avg_queue_depth);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->max_queue_depth);
  // NOLINTNEXTLINE
  offset += 4;
		  for(size_t msgsocket_state_counts_idx = 0; msgsocket_state_counts_idx < 16; msgsocket_state_counts_idx++)
			{
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->socket_state_counts[msgsocket_state_counts_idx]);
  // NOLINTNEXTLINE
  offset += 2;
			}
		  for(size_t msgsocket_type_counts_idx = 0; msgsocket_type_counts_idx < 16; msgsocket_type_counts_idx++)
			{
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->socket_type_counts[msgsocket_type_counts_idx]);
  // NOLINTNEXTLINE
  offset += 2;
			}
  return true;
}

static inline bool sbp_unpack_sbp_msg_linux_socket_usage_t(const u8 *buf, size_t len, sbp_msg_linux_socket_usage_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
      
  if (offset + 4 > len) { return false; }
  msg->avg_queue_depth = sbp_unpack_u32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  msg->max_queue_depth = sbp_unpack_u32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
		for (size_t msgsocket_state_counts_idx = 0; msgsocket_state_counts_idx < 16; msgsocket_state_counts_idx++)
		{
        
  if (offset + 2 > len) { return false; }
  msg->socket_state_counts[msgsocket_state_counts_idx] = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
		}
		for (size_t msgsocket_type_counts_idx = 0; msgsocket_type_counts_idx < 16; msgsocket_type_counts_idx++)
		{
        
  if (offset + 2 > len) { return false; }
  msg->socket_type_counts[msgsocket_type_counts_idx] = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
		}
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_linux_process_fd_count_t(const sbp_msg_linux_process_fd_count_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				sizeof( msg->index )                                                                          
	  +
				sizeof( msg->pid )                                                                          
	  +
				sizeof( msg->fd_count )                                                                          
	  +
      sbp_unterminated_string_packed_len(&msg->cmdline, 250);
}

static inline bool sbp_pack_sbp_msg_linux_process_fd_count_t(u8 *buf, size_t len, const sbp_msg_linux_process_fd_count_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_linux_process_fd_count_t(msg) > len) { return false; }
  
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->index , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->pid);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->fd_count);
  // NOLINTNEXTLINE
  offset += 2;
        offset += sbp_unterminated_string_pack(&msg->cmdline, 250, buf + offset, (uint8_t)(len - offset));
  return true;
}

static inline bool sbp_unpack_sbp_msg_linux_process_fd_count_t(const u8 *buf, size_t len, sbp_msg_linux_process_fd_count_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->index, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 2 > len) { return false; }
  msg->pid = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 2 > len) { return false; }
  msg->fd_count = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      offset += sbp_unterminated_string_unpack(&msg->cmdline, 250, buf + offset, (uint8_t)(len - offset));
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_linux_process_fd_summary_t(const sbp_msg_linux_process_fd_summary_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				sizeof( msg->sys_fd_count )                                                                          
	  +
      sbp_sequence_string_packed_len(&msg->most_opened, 251, 0);
}

static inline bool sbp_pack_sbp_msg_linux_process_fd_summary_t(u8 *buf, size_t len, const sbp_msg_linux_process_fd_summary_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_linux_process_fd_summary_t(msg) > len) { return false; }
  
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->sys_fd_count);
  // NOLINTNEXTLINE
  offset += 4;
        offset += sbp_sequence_string_pack(&msg->most_opened, 251, 0, buf + offset, (uint8_t)(len - offset));
  return true;
}

static inline bool sbp_unpack_sbp_msg_linux_process_fd_summary_t(const u8 *buf, size_t len, sbp_msg_linux_process_fd_summary_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
      
  if (offset + 4 > len) { return false; }
  msg->sys_fd_count = sbp_unpack_u32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      offset += sbp_sequence_string_unpack(&msg->most_opened, 251, 0, buf + offset, (uint8_t)(len - offset));
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_linux_cpu_state_t(const sbp_msg_linux_cpu_state_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				sizeof( msg->index )                                                                          
	  +
				sizeof( msg->pid )                                                                          
	  +
				sizeof( msg->pcpu )                                                                          
	  +
				sizeof( msg->time )                                                                          
	  +
				sizeof( msg->flags )                                                                          
	  +
		  ( 15 *
        sizeof( msg->tname[0] )
		)                                                                          
	  +
      sbp_unterminated_string_packed_len(&msg->cmdline, 231);
}

static inline bool sbp_pack_sbp_msg_linux_cpu_state_t(u8 *buf, size_t len, const sbp_msg_linux_cpu_state_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_linux_cpu_state_t(msg) > len) { return false; }
  
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->index , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->pid);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->pcpu , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->time);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->flags , 1);
  // NOLINTNEXTLINE
  offset += 1;
		  for(size_t msgtname_idx = 0; msgtname_idx < 15; msgtname_idx++)
			{
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->tname[msgtname_idx] , 1);
  // NOLINTNEXTLINE
  offset += 1;
			}
        offset += sbp_unterminated_string_pack(&msg->cmdline, 231, buf + offset, (uint8_t)(len - offset));
  return true;
}

static inline bool sbp_unpack_sbp_msg_linux_cpu_state_t(const u8 *buf, size_t len, sbp_msg_linux_cpu_state_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->index, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 2 > len) { return false; }
  msg->pid = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->pcpu, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 4 > len) { return false; }
  msg->time = sbp_unpack_u32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->flags, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
		for (size_t msgtname_idx = 0; msgtname_idx < 15; msgtname_idx++)
		{
        
  if (offset + 1 > len) { return false; }
  memcpy(&msg->tname[msgtname_idx], buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
		}
      offset += sbp_unterminated_string_unpack(&msg->cmdline, 231, buf + offset, (uint8_t)(len - offset));
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_linux_mem_state_t(const sbp_msg_linux_mem_state_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				sizeof( msg->index )                                                                          
	  +
				sizeof( msg->pid )                                                                          
	  +
				sizeof( msg->pmem )                                                                          
	  +
				sizeof( msg->time )                                                                          
	  +
				sizeof( msg->flags )                                                                          
	  +
		  ( 15 *
        sizeof( msg->tname[0] )
		)                                                                          
	  +
      sbp_unterminated_string_packed_len(&msg->cmdline, 231);
}

static inline bool sbp_pack_sbp_msg_linux_mem_state_t(u8 *buf, size_t len, const sbp_msg_linux_mem_state_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_linux_mem_state_t(msg) > len) { return false; }
  
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->index , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->pid);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->pmem , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->time);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->flags , 1);
  // NOLINTNEXTLINE
  offset += 1;
		  for(size_t msgtname_idx = 0; msgtname_idx < 15; msgtname_idx++)
			{
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->tname[msgtname_idx] , 1);
  // NOLINTNEXTLINE
  offset += 1;
			}
        offset += sbp_unterminated_string_pack(&msg->cmdline, 231, buf + offset, (uint8_t)(len - offset));
  return true;
}

static inline bool sbp_unpack_sbp_msg_linux_mem_state_t(const u8 *buf, size_t len, sbp_msg_linux_mem_state_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->index, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 2 > len) { return false; }
  msg->pid = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->pmem, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 4 > len) { return false; }
  msg->time = sbp_unpack_u32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->flags, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
		for (size_t msgtname_idx = 0; msgtname_idx < 15; msgtname_idx++)
		{
        
  if (offset + 1 > len) { return false; }
  memcpy(&msg->tname[msgtname_idx], buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
		}
      offset += sbp_unterminated_string_unpack(&msg->cmdline, 231, buf + offset, (uint8_t)(len - offset));
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_linux_sys_state_t(const sbp_msg_linux_sys_state_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				sizeof( msg->mem_total )                                                                          
	  +
				sizeof( msg->pcpu )                                                                          
	  +
				sizeof( msg->pmem )                                                                          
	  +
				sizeof( msg->procs_starting )                                                                          
	  +
				sizeof( msg->procs_stopping )                                                                          
	  +
				sizeof( msg->pid_count )                                                                          
	  +
				sizeof( msg->time )                                                                          
	  +
				sizeof( msg->flags );
}

static inline bool sbp_pack_sbp_msg_linux_sys_state_t(u8 *buf, size_t len, const sbp_msg_linux_sys_state_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_linux_sys_state_t(msg) > len) { return false; }
  
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->mem_total);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->pcpu , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->pmem , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->procs_starting);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->procs_stopping);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->pid_count);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->time);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->flags , 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline bool sbp_unpack_sbp_msg_linux_sys_state_t(const u8 *buf, size_t len, sbp_msg_linux_sys_state_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
      
  if (offset + 2 > len) { return false; }
  msg->mem_total = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->pcpu, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->pmem, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 2 > len) { return false; }
  msg->procs_starting = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 2 > len) { return false; }
  msg->procs_stopping = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 2 > len) { return false; }
  msg->pid_count = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 4 > len) { return false; }
  msg->time = sbp_unpack_u32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->flags, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

#endif
