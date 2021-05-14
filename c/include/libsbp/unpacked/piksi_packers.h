#ifndef LIBSBP_PIKSI_PACKERS_H
#define LIBSBP_PIKSI_PACKERS_H

#ifndef LIBSBP_PIKSI_MESSAGES_H
#error "Do not include this file directly, include libsbp/unpacked/piksi.h instead"
#endif

#include <stdbool.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>
#include <math.h>

#include <libsbp/common.h>
#include <libsbp/string.h>

static inline size_t sbp_packed_size_sbp_msg_almanac_t(const sbp_msg_almanac_t *msg) {                                
	(void)msg;
  return                                                          
	0;
}

static inline bool sbp_pack_sbp_msg_almanac_t(u8 *buf, size_t len, const sbp_msg_almanac_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_almanac_t(msg) > len) { return false; }
  
  return true;
}

static inline bool sbp_unpack_sbp_msg_almanac_t(const u8 *buf, size_t len, sbp_msg_almanac_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_set_time_t(const sbp_msg_set_time_t *msg) {                                
	(void)msg;
  return                                                          
	0;
}

static inline bool sbp_pack_sbp_msg_set_time_t(u8 *buf, size_t len, const sbp_msg_set_time_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_set_time_t(msg) > len) { return false; }
  
  return true;
}

static inline bool sbp_unpack_sbp_msg_set_time_t(const u8 *buf, size_t len, sbp_msg_set_time_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_reset_t(const sbp_msg_reset_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				sizeof( msg->flags );
}

static inline bool sbp_pack_sbp_msg_reset_t(u8 *buf, size_t len, const sbp_msg_reset_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_reset_t(msg) > len) { return false; }
  
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->flags);
  // NOLINTNEXTLINE
  offset += 4;
  return true;
}

static inline bool sbp_unpack_sbp_msg_reset_t(const u8 *buf, size_t len, sbp_msg_reset_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
      
  if (offset + 4 > len) { return false; }
  msg->flags = sbp_unpack_u32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_reset_dep_t(const sbp_msg_reset_dep_t *msg) {                                
	(void)msg;
  return                                                          
	0;
}

static inline bool sbp_pack_sbp_msg_reset_dep_t(u8 *buf, size_t len, const sbp_msg_reset_dep_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_reset_dep_t(msg) > len) { return false; }
  
  return true;
}

static inline bool sbp_unpack_sbp_msg_reset_dep_t(const u8 *buf, size_t len, sbp_msg_reset_dep_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_cw_results_t(const sbp_msg_cw_results_t *msg) {                                
	(void)msg;
  return                                                          
	0;
}

static inline bool sbp_pack_sbp_msg_cw_results_t(u8 *buf, size_t len, const sbp_msg_cw_results_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_cw_results_t(msg) > len) { return false; }
  
  return true;
}

static inline bool sbp_unpack_sbp_msg_cw_results_t(const u8 *buf, size_t len, sbp_msg_cw_results_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_cw_start_t(const sbp_msg_cw_start_t *msg) {                                
	(void)msg;
  return                                                          
	0;
}

static inline bool sbp_pack_sbp_msg_cw_start_t(u8 *buf, size_t len, const sbp_msg_cw_start_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_cw_start_t(msg) > len) { return false; }
  
  return true;
}

static inline bool sbp_unpack_sbp_msg_cw_start_t(const u8 *buf, size_t len, sbp_msg_cw_start_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_reset_filters_t(const sbp_msg_reset_filters_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				sizeof( msg->filter );
}

static inline bool sbp_pack_sbp_msg_reset_filters_t(u8 *buf, size_t len, const sbp_msg_reset_filters_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_reset_filters_t(msg) > len) { return false; }
  
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->filter , 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline bool sbp_unpack_sbp_msg_reset_filters_t(const u8 *buf, size_t len, sbp_msg_reset_filters_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->filter, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_init_base_dep_t(const sbp_msg_init_base_dep_t *msg) {                                
	(void)msg;
  return                                                          
	0;
}

static inline bool sbp_pack_sbp_msg_init_base_dep_t(u8 *buf, size_t len, const sbp_msg_init_base_dep_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_init_base_dep_t(msg) > len) { return false; }
  
  return true;
}

static inline bool sbp_unpack_sbp_msg_init_base_dep_t(const u8 *buf, size_t len, sbp_msg_init_base_dep_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_thread_state_t(const sbp_msg_thread_state_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
		  ( 20 *
        sizeof( msg->name[0] )
		)                                                                          
	  +
				sizeof( msg->cpu )                                                                          
	  +
				sizeof( msg->stack_free );
}

static inline bool sbp_pack_sbp_msg_thread_state_t(u8 *buf, size_t len, const sbp_msg_thread_state_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_thread_state_t(msg) > len) { return false; }
  
		  for(size_t msgname_idx = 0; msgname_idx < 20; msgname_idx++)
			{
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->name[msgname_idx] , 1);
  // NOLINTNEXTLINE
  offset += 1;
			}
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->cpu);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->stack_free);
  // NOLINTNEXTLINE
  offset += 4;
  return true;
}

static inline bool sbp_unpack_sbp_msg_thread_state_t(const u8 *buf, size_t len, sbp_msg_thread_state_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
		for (size_t msgname_idx = 0; msgname_idx < 20; msgname_idx++)
		{
        
  if (offset + 1 > len) { return false; }
  memcpy(&msg->name[msgname_idx], buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
		}
      
  if (offset + 2 > len) { return false; }
  msg->cpu = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 4 > len) { return false; }
  msg->stack_free = sbp_unpack_u32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
  return true;
}

static inline size_t sbp_packed_size_sbp_uart_channel_t(const sbp_uart_channel_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				sizeof( msg->tx_throughput )                                                                          
	  +
				sizeof( msg->rx_throughput )                                                                          
	  +
				sizeof( msg->crc_error_count )                                                                          
	  +
				sizeof( msg->io_error_count )                                                                          
	  +
				sizeof( msg->tx_buffer_level )                                                                          
	  +
				sizeof( msg->rx_buffer_level );
}

static inline bool sbp_pack_sbp_uart_channel_t(u8 *buf, size_t len, const sbp_uart_channel_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_uart_channel_t(msg) > len) { return false; }
  
        
  if (offset + 4 > len) { return false; }
  memcpy(buf + offset, & msg->tx_throughput , 4);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  memcpy(buf + offset, & msg->rx_throughput , 4);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->crc_error_count);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->io_error_count);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->tx_buffer_level , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->rx_buffer_level , 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline bool sbp_unpack_sbp_uart_channel_t(const u8 *buf, size_t len, sbp_uart_channel_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->tx_throughput, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->rx_throughput, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 2 > len) { return false; }
  msg->crc_error_count = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 2 > len) { return false; }
  msg->io_error_count = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->tx_buffer_level, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->rx_buffer_level, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline size_t sbp_packed_size_sbp_period_t(const sbp_period_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				sizeof( msg->avg )                                                                          
	  +
				sizeof( msg->pmin )                                                                          
	  +
				sizeof( msg->pmax )                                                                          
	  +
				sizeof( msg->current );
}

static inline bool sbp_pack_sbp_period_t(u8 *buf, size_t len, const sbp_period_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_period_t(msg) > len) { return false; }
  
        
  if (offset + 4 > len) { return false; }
  sbp_pack_s32(buf + offset, msg->avg);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  sbp_pack_s32(buf + offset, msg->pmin);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  sbp_pack_s32(buf + offset, msg->pmax);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  sbp_pack_s32(buf + offset, msg->current);
  // NOLINTNEXTLINE
  offset += 4;
  return true;
}

static inline bool sbp_unpack_sbp_period_t(const u8 *buf, size_t len, sbp_period_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
      
  if (offset + 4 > len) { return false; }
  msg->avg = sbp_unpack_s32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  msg->pmin = sbp_unpack_s32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  msg->pmax = sbp_unpack_s32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  msg->current = sbp_unpack_s32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
  return true;
}

static inline size_t sbp_packed_size_sbp_latency_t(const sbp_latency_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				sizeof( msg->avg )                                                                          
	  +
				sizeof( msg->lmin )                                                                          
	  +
				sizeof( msg->lmax )                                                                          
	  +
				sizeof( msg->current );
}

static inline bool sbp_pack_sbp_latency_t(u8 *buf, size_t len, const sbp_latency_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_latency_t(msg) > len) { return false; }
  
        
  if (offset + 4 > len) { return false; }
  sbp_pack_s32(buf + offset, msg->avg);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  sbp_pack_s32(buf + offset, msg->lmin);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  sbp_pack_s32(buf + offset, msg->lmax);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  sbp_pack_s32(buf + offset, msg->current);
  // NOLINTNEXTLINE
  offset += 4;
  return true;
}

static inline bool sbp_unpack_sbp_latency_t(const u8 *buf, size_t len, sbp_latency_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
      
  if (offset + 4 > len) { return false; }
  msg->avg = sbp_unpack_s32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  msg->lmin = sbp_unpack_s32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  msg->lmax = sbp_unpack_s32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  msg->current = sbp_unpack_s32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_uart_state_t(const sbp_msg_uart_state_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				(                                                          
	0                                                                          
	  +
				sizeof( msg->uart_a.tx_throughput )                                                                          
	  +
				sizeof( msg->uart_a.rx_throughput )                                                                          
	  +
				sizeof( msg->uart_a.crc_error_count )                                                                          
	  +
				sizeof( msg->uart_a.io_error_count )                                                                          
	  +
				sizeof( msg->uart_a.tx_buffer_level )                                                                          
	  +
				sizeof( msg->uart_a.rx_buffer_level ) )                                                                          
	  +
				(                                                          
	0                                                                          
	  +
				sizeof( msg->uart_b.tx_throughput )                                                                          
	  +
				sizeof( msg->uart_b.rx_throughput )                                                                          
	  +
				sizeof( msg->uart_b.crc_error_count )                                                                          
	  +
				sizeof( msg->uart_b.io_error_count )                                                                          
	  +
				sizeof( msg->uart_b.tx_buffer_level )                                                                          
	  +
				sizeof( msg->uart_b.rx_buffer_level ) )                                                                          
	  +
				(                                                          
	0                                                                          
	  +
				sizeof( msg->uart_ftdi.tx_throughput )                                                                          
	  +
				sizeof( msg->uart_ftdi.rx_throughput )                                                                          
	  +
				sizeof( msg->uart_ftdi.crc_error_count )                                                                          
	  +
				sizeof( msg->uart_ftdi.io_error_count )                                                                          
	  +
				sizeof( msg->uart_ftdi.tx_buffer_level )                                                                          
	  +
				sizeof( msg->uart_ftdi.rx_buffer_level ) )                                                                          
	  +
				(                                                          
	0                                                                          
	  +
				sizeof( msg->latency.avg )                                                                          
	  +
				sizeof( msg->latency.lmin )                                                                          
	  +
				sizeof( msg->latency.lmax )                                                                          
	  +
				sizeof( msg->latency.current ) )                                                                          
	  +
				(                                                          
	0                                                                          
	  +
				sizeof( msg->obs_period.avg )                                                                          
	  +
				sizeof( msg->obs_period.pmin )                                                                          
	  +
				sizeof( msg->obs_period.pmax )                                                                          
	  +
				sizeof( msg->obs_period.current ) );
}

static inline bool sbp_pack_sbp_msg_uart_state_t(u8 *buf, size_t len, const sbp_msg_uart_state_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_uart_state_t(msg) > len) { return false; }
  
				
        
  if (offset + 4 > len) { return false; }
  memcpy(buf + offset, & msg->uart_a.tx_throughput , 4);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  memcpy(buf + offset, & msg->uart_a.rx_throughput , 4);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->uart_a.crc_error_count);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->uart_a.io_error_count);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->uart_a.tx_buffer_level , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->uart_a.rx_buffer_level , 1);
  // NOLINTNEXTLINE
  offset += 1;
				
        
  if (offset + 4 > len) { return false; }
  memcpy(buf + offset, & msg->uart_b.tx_throughput , 4);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  memcpy(buf + offset, & msg->uart_b.rx_throughput , 4);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->uart_b.crc_error_count);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->uart_b.io_error_count);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->uart_b.tx_buffer_level , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->uart_b.rx_buffer_level , 1);
  // NOLINTNEXTLINE
  offset += 1;
				
        
  if (offset + 4 > len) { return false; }
  memcpy(buf + offset, & msg->uart_ftdi.tx_throughput , 4);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  memcpy(buf + offset, & msg->uart_ftdi.rx_throughput , 4);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->uart_ftdi.crc_error_count);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->uart_ftdi.io_error_count);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->uart_ftdi.tx_buffer_level , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->uart_ftdi.rx_buffer_level , 1);
  // NOLINTNEXTLINE
  offset += 1;
				
        
  if (offset + 4 > len) { return false; }
  sbp_pack_s32(buf + offset, msg->latency.avg);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  sbp_pack_s32(buf + offset, msg->latency.lmin);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  sbp_pack_s32(buf + offset, msg->latency.lmax);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  sbp_pack_s32(buf + offset, msg->latency.current);
  // NOLINTNEXTLINE
  offset += 4;
				
        
  if (offset + 4 > len) { return false; }
  sbp_pack_s32(buf + offset, msg->obs_period.avg);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  sbp_pack_s32(buf + offset, msg->obs_period.pmin);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  sbp_pack_s32(buf + offset, msg->obs_period.pmax);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  sbp_pack_s32(buf + offset, msg->obs_period.current);
  // NOLINTNEXTLINE
  offset += 4;
  return true;
}

static inline bool sbp_unpack_sbp_msg_uart_state_t(const u8 *buf, size_t len, sbp_msg_uart_state_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
			
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->uart_a.tx_throughput, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->uart_a.rx_throughput, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 2 > len) { return false; }
  msg->uart_a.crc_error_count = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 2 > len) { return false; }
  msg->uart_a.io_error_count = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->uart_a.tx_buffer_level, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->uart_a.rx_buffer_level, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
			
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->uart_b.tx_throughput, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->uart_b.rx_throughput, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 2 > len) { return false; }
  msg->uart_b.crc_error_count = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 2 > len) { return false; }
  msg->uart_b.io_error_count = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->uart_b.tx_buffer_level, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->uart_b.rx_buffer_level, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
			
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->uart_ftdi.tx_throughput, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->uart_ftdi.rx_throughput, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 2 > len) { return false; }
  msg->uart_ftdi.crc_error_count = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 2 > len) { return false; }
  msg->uart_ftdi.io_error_count = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->uart_ftdi.tx_buffer_level, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->uart_ftdi.rx_buffer_level, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
			
      
  if (offset + 4 > len) { return false; }
  msg->latency.avg = sbp_unpack_s32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  msg->latency.lmin = sbp_unpack_s32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  msg->latency.lmax = sbp_unpack_s32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  msg->latency.current = sbp_unpack_s32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
			
      
  if (offset + 4 > len) { return false; }
  msg->obs_period.avg = sbp_unpack_s32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  msg->obs_period.pmin = sbp_unpack_s32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  msg->obs_period.pmax = sbp_unpack_s32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  msg->obs_period.current = sbp_unpack_s32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_uart_state_depa_t(const sbp_msg_uart_state_depa_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				(                                                          
	0                                                                          
	  +
				sizeof( msg->uart_a.tx_throughput )                                                                          
	  +
				sizeof( msg->uart_a.rx_throughput )                                                                          
	  +
				sizeof( msg->uart_a.crc_error_count )                                                                          
	  +
				sizeof( msg->uart_a.io_error_count )                                                                          
	  +
				sizeof( msg->uart_a.tx_buffer_level )                                                                          
	  +
				sizeof( msg->uart_a.rx_buffer_level ) )                                                                          
	  +
				(                                                          
	0                                                                          
	  +
				sizeof( msg->uart_b.tx_throughput )                                                                          
	  +
				sizeof( msg->uart_b.rx_throughput )                                                                          
	  +
				sizeof( msg->uart_b.crc_error_count )                                                                          
	  +
				sizeof( msg->uart_b.io_error_count )                                                                          
	  +
				sizeof( msg->uart_b.tx_buffer_level )                                                                          
	  +
				sizeof( msg->uart_b.rx_buffer_level ) )                                                                          
	  +
				(                                                          
	0                                                                          
	  +
				sizeof( msg->uart_ftdi.tx_throughput )                                                                          
	  +
				sizeof( msg->uart_ftdi.rx_throughput )                                                                          
	  +
				sizeof( msg->uart_ftdi.crc_error_count )                                                                          
	  +
				sizeof( msg->uart_ftdi.io_error_count )                                                                          
	  +
				sizeof( msg->uart_ftdi.tx_buffer_level )                                                                          
	  +
				sizeof( msg->uart_ftdi.rx_buffer_level ) )                                                                          
	  +
				(                                                          
	0                                                                          
	  +
				sizeof( msg->latency.avg )                                                                          
	  +
				sizeof( msg->latency.lmin )                                                                          
	  +
				sizeof( msg->latency.lmax )                                                                          
	  +
				sizeof( msg->latency.current ) );
}

static inline bool sbp_pack_sbp_msg_uart_state_depa_t(u8 *buf, size_t len, const sbp_msg_uart_state_depa_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_uart_state_depa_t(msg) > len) { return false; }
  
				
        
  if (offset + 4 > len) { return false; }
  memcpy(buf + offset, & msg->uart_a.tx_throughput , 4);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  memcpy(buf + offset, & msg->uart_a.rx_throughput , 4);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->uart_a.crc_error_count);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->uart_a.io_error_count);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->uart_a.tx_buffer_level , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->uart_a.rx_buffer_level , 1);
  // NOLINTNEXTLINE
  offset += 1;
				
        
  if (offset + 4 > len) { return false; }
  memcpy(buf + offset, & msg->uart_b.tx_throughput , 4);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  memcpy(buf + offset, & msg->uart_b.rx_throughput , 4);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->uart_b.crc_error_count);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->uart_b.io_error_count);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->uart_b.tx_buffer_level , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->uart_b.rx_buffer_level , 1);
  // NOLINTNEXTLINE
  offset += 1;
				
        
  if (offset + 4 > len) { return false; }
  memcpy(buf + offset, & msg->uart_ftdi.tx_throughput , 4);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  memcpy(buf + offset, & msg->uart_ftdi.rx_throughput , 4);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->uart_ftdi.crc_error_count);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->uart_ftdi.io_error_count);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->uart_ftdi.tx_buffer_level , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->uart_ftdi.rx_buffer_level , 1);
  // NOLINTNEXTLINE
  offset += 1;
				
        
  if (offset + 4 > len) { return false; }
  sbp_pack_s32(buf + offset, msg->latency.avg);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  sbp_pack_s32(buf + offset, msg->latency.lmin);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  sbp_pack_s32(buf + offset, msg->latency.lmax);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  sbp_pack_s32(buf + offset, msg->latency.current);
  // NOLINTNEXTLINE
  offset += 4;
  return true;
}

static inline bool sbp_unpack_sbp_msg_uart_state_depa_t(const u8 *buf, size_t len, sbp_msg_uart_state_depa_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
			
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->uart_a.tx_throughput, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->uart_a.rx_throughput, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 2 > len) { return false; }
  msg->uart_a.crc_error_count = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 2 > len) { return false; }
  msg->uart_a.io_error_count = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->uart_a.tx_buffer_level, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->uart_a.rx_buffer_level, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
			
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->uart_b.tx_throughput, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->uart_b.rx_throughput, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 2 > len) { return false; }
  msg->uart_b.crc_error_count = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 2 > len) { return false; }
  msg->uart_b.io_error_count = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->uart_b.tx_buffer_level, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->uart_b.rx_buffer_level, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
			
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->uart_ftdi.tx_throughput, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->uart_ftdi.rx_throughput, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 2 > len) { return false; }
  msg->uart_ftdi.crc_error_count = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 2 > len) { return false; }
  msg->uart_ftdi.io_error_count = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->uart_ftdi.tx_buffer_level, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->uart_ftdi.rx_buffer_level, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
			
      
  if (offset + 4 > len) { return false; }
  msg->latency.avg = sbp_unpack_s32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  msg->latency.lmin = sbp_unpack_s32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  msg->latency.lmax = sbp_unpack_s32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  msg->latency.current = sbp_unpack_s32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_iar_state_t(const sbp_msg_iar_state_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				sizeof( msg->num_hyps );
}

static inline bool sbp_pack_sbp_msg_iar_state_t(u8 *buf, size_t len, const sbp_msg_iar_state_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_iar_state_t(msg) > len) { return false; }
  
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->num_hyps);
  // NOLINTNEXTLINE
  offset += 4;
  return true;
}

static inline bool sbp_unpack_sbp_msg_iar_state_t(const u8 *buf, size_t len, sbp_msg_iar_state_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
      
  if (offset + 4 > len) { return false; }
  msg->num_hyps = sbp_unpack_u32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_mask_satellite_t(const sbp_msg_mask_satellite_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				sizeof( msg->mask )                                                                          
	  +
				(                                                          
	0                                                                          
	  +
				sizeof( msg->sid.sat )                                                                          
	  +
				sizeof( msg->sid.code ) );
}

static inline bool sbp_pack_sbp_msg_mask_satellite_t(u8 *buf, size_t len, const sbp_msg_mask_satellite_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_mask_satellite_t(msg) > len) { return false; }
  
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->mask , 1);
  // NOLINTNEXTLINE
  offset += 1;
				
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->sid.sat , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->sid.code , 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline bool sbp_unpack_sbp_msg_mask_satellite_t(const u8 *buf, size_t len, sbp_msg_mask_satellite_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->mask, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
			
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->sid.sat, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->sid.code, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_mask_satellite_dep_t(const sbp_msg_mask_satellite_dep_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				sizeof( msg->mask )                                                                          
	  +
				(                                                          
	0                                                                          
	  +
				sizeof( msg->sid.sat )                                                                          
	  +
				sizeof( msg->sid.code )                                                                          
	  +
				sizeof( msg->sid.reserved ) );
}

static inline bool sbp_pack_sbp_msg_mask_satellite_dep_t(u8 *buf, size_t len, const sbp_msg_mask_satellite_dep_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_mask_satellite_dep_t(msg) > len) { return false; }
  
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->mask , 1);
  // NOLINTNEXTLINE
  offset += 1;
				
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->sid.sat);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->sid.code , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->sid.reserved , 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline bool sbp_unpack_sbp_msg_mask_satellite_dep_t(const u8 *buf, size_t len, sbp_msg_mask_satellite_dep_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->mask, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
			
      
  if (offset + 2 > len) { return false; }
  msg->sid.sat = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->sid.code, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->sid.reserved, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_device_monitor_t(const sbp_msg_device_monitor_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				sizeof( msg->dev_vin )                                                                          
	  +
				sizeof( msg->cpu_vint )                                                                          
	  +
				sizeof( msg->cpu_vaux )                                                                          
	  +
				sizeof( msg->cpu_temperature )                                                                          
	  +
				sizeof( msg->fe_temperature );
}

static inline bool sbp_pack_sbp_msg_device_monitor_t(u8 *buf, size_t len, const sbp_msg_device_monitor_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_device_monitor_t(msg) > len) { return false; }
  
        
  if (offset + 2 > len) { return false; }
  sbp_pack_s16(buf + offset, msg->dev_vin);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_s16(buf + offset, msg->cpu_vint);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_s16(buf + offset, msg->cpu_vaux);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_s16(buf + offset, msg->cpu_temperature);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_s16(buf + offset, msg->fe_temperature);
  // NOLINTNEXTLINE
  offset += 2;
  return true;
}

static inline bool sbp_unpack_sbp_msg_device_monitor_t(const u8 *buf, size_t len, sbp_msg_device_monitor_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
      
  if (offset + 2 > len) { return false; }
  msg->dev_vin = sbp_unpack_s16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 2 > len) { return false; }
  msg->cpu_vint = sbp_unpack_s16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 2 > len) { return false; }
  msg->cpu_vaux = sbp_unpack_s16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 2 > len) { return false; }
  msg->cpu_temperature = sbp_unpack_s16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 2 > len) { return false; }
  msg->fe_temperature = sbp_unpack_s16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_command_req_t(const sbp_msg_command_req_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				sizeof( msg->sequence )                                                                          
	  +
      sbp_null_terminated_string_packed_len(&msg->command, 251);
}

static inline bool sbp_pack_sbp_msg_command_req_t(u8 *buf, size_t len, const sbp_msg_command_req_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_command_req_t(msg) > len) { return false; }
  
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->sequence);
  // NOLINTNEXTLINE
  offset += 4;
        offset += sbp_null_terminated_string_pack(&msg->command, 251, buf + offset, (uint8_t)(len - offset));
  return true;
}

static inline bool sbp_unpack_sbp_msg_command_req_t(const u8 *buf, size_t len, sbp_msg_command_req_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
      
  if (offset + 4 > len) { return false; }
  msg->sequence = sbp_unpack_u32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      offset += sbp_null_terminated_string_unpack(&msg->command, 251, buf + offset, (uint8_t)(len - offset));
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_command_resp_t(const sbp_msg_command_resp_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				sizeof( msg->sequence )                                                                          
	  +
				sizeof( msg->code );
}

static inline bool sbp_pack_sbp_msg_command_resp_t(u8 *buf, size_t len, const sbp_msg_command_resp_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_command_resp_t(msg) > len) { return false; }
  
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->sequence);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  sbp_pack_s32(buf + offset, msg->code);
  // NOLINTNEXTLINE
  offset += 4;
  return true;
}

static inline bool sbp_unpack_sbp_msg_command_resp_t(const u8 *buf, size_t len, sbp_msg_command_resp_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
      
  if (offset + 4 > len) { return false; }
  msg->sequence = sbp_unpack_u32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  msg->code = sbp_unpack_s32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_command_output_t(const sbp_msg_command_output_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				sizeof( msg->sequence )                                                                          
	  +
      sbp_unterminated_string_packed_len(&msg->line, 251);
}

static inline bool sbp_pack_sbp_msg_command_output_t(u8 *buf, size_t len, const sbp_msg_command_output_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_command_output_t(msg) > len) { return false; }
  
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->sequence);
  // NOLINTNEXTLINE
  offset += 4;
        offset += sbp_unterminated_string_pack(&msg->line, 251, buf + offset, (uint8_t)(len - offset));
  return true;
}

static inline bool sbp_unpack_sbp_msg_command_output_t(const u8 *buf, size_t len, sbp_msg_command_output_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
      
  if (offset + 4 > len) { return false; }
  msg->sequence = sbp_unpack_u32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      offset += sbp_unterminated_string_unpack(&msg->line, 251, buf + offset, (uint8_t)(len - offset));
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_network_state_req_t(const sbp_msg_network_state_req_t *msg) {                                
	(void)msg;
  return                                                          
	0;
}

static inline bool sbp_pack_sbp_msg_network_state_req_t(u8 *buf, size_t len, const sbp_msg_network_state_req_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_network_state_req_t(msg) > len) { return false; }
  
  return true;
}

static inline bool sbp_unpack_sbp_msg_network_state_req_t(const u8 *buf, size_t len, sbp_msg_network_state_req_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_network_state_resp_t(const sbp_msg_network_state_resp_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
		  ( 4 *
        sizeof( msg->ipv4_address[0] )
		)                                                                          
	  +
				sizeof( msg->ipv4_mask_size )                                                                          
	  +
		  ( 16 *
        sizeof( msg->ipv6_address[0] )
		)                                                                          
	  +
				sizeof( msg->ipv6_mask_size )                                                                          
	  +
				sizeof( msg->rx_bytes )                                                                          
	  +
				sizeof( msg->tx_bytes )                                                                          
	  +
		  ( 16 *
        sizeof( msg->interface_name[0] )
		)                                                                          
	  +
				sizeof( msg->flags );
}

static inline bool sbp_pack_sbp_msg_network_state_resp_t(u8 *buf, size_t len, const sbp_msg_network_state_resp_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_network_state_resp_t(msg) > len) { return false; }
  
		  for(size_t msgipv4_address_idx = 0; msgipv4_address_idx < 4; msgipv4_address_idx++)
			{
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->ipv4_address[msgipv4_address_idx] , 1);
  // NOLINTNEXTLINE
  offset += 1;
			}
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->ipv4_mask_size , 1);
  // NOLINTNEXTLINE
  offset += 1;
		  for(size_t msgipv6_address_idx = 0; msgipv6_address_idx < 16; msgipv6_address_idx++)
			{
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->ipv6_address[msgipv6_address_idx] , 1);
  // NOLINTNEXTLINE
  offset += 1;
			}
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->ipv6_mask_size , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->rx_bytes);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->tx_bytes);
  // NOLINTNEXTLINE
  offset += 4;
		  for(size_t msginterface_name_idx = 0; msginterface_name_idx < 16; msginterface_name_idx++)
			{
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->interface_name[msginterface_name_idx] , 1);
  // NOLINTNEXTLINE
  offset += 1;
			}
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->flags);
  // NOLINTNEXTLINE
  offset += 4;
  return true;
}

static inline bool sbp_unpack_sbp_msg_network_state_resp_t(const u8 *buf, size_t len, sbp_msg_network_state_resp_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
		for (size_t msgipv4_address_idx = 0; msgipv4_address_idx < 4; msgipv4_address_idx++)
		{
        
  if (offset + 1 > len) { return false; }
  memcpy(&msg->ipv4_address[msgipv4_address_idx], buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
		}
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->ipv4_mask_size, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
		for (size_t msgipv6_address_idx = 0; msgipv6_address_idx < 16; msgipv6_address_idx++)
		{
        
  if (offset + 1 > len) { return false; }
  memcpy(&msg->ipv6_address[msgipv6_address_idx], buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
		}
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->ipv6_mask_size, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 4 > len) { return false; }
  msg->rx_bytes = sbp_unpack_u32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  msg->tx_bytes = sbp_unpack_u32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
		for (size_t msginterface_name_idx = 0; msginterface_name_idx < 16; msginterface_name_idx++)
		{
        
  if (offset + 1 > len) { return false; }
  memcpy(&msg->interface_name[msginterface_name_idx], buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
		}
      
  if (offset + 4 > len) { return false; }
  msg->flags = sbp_unpack_u32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
  return true;
}

static inline size_t sbp_packed_size_sbp_network_usage_t(const sbp_network_usage_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				sizeof( msg->duration )                                                                          
	  +
				sizeof( msg->total_bytes )                                                                          
	  +
				sizeof( msg->rx_bytes )                                                                          
	  +
				sizeof( msg->tx_bytes )                                                                          
	  +
		  ( 16 *
        sizeof( msg->interface_name[0] )
		);
}

static inline bool sbp_pack_sbp_network_usage_t(u8 *buf, size_t len, const sbp_network_usage_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_network_usage_t(msg) > len) { return false; }
  
        
  if (offset + 8 > len) { return false; }
  sbp_pack_u64(buf + offset, msg->duration);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  sbp_pack_u64(buf + offset, msg->total_bytes);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->rx_bytes);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->tx_bytes);
  // NOLINTNEXTLINE
  offset += 4;
		  for(size_t msginterface_name_idx = 0; msginterface_name_idx < 16; msginterface_name_idx++)
			{
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->interface_name[msginterface_name_idx] , 1);
  // NOLINTNEXTLINE
  offset += 1;
			}
  return true;
}

static inline bool sbp_unpack_sbp_network_usage_t(const u8 *buf, size_t len, sbp_network_usage_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
      
  if (offset + 8 > len) { return false; }
  msg->duration = sbp_unpack_u64(buf + offset);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  msg->total_bytes = sbp_unpack_u64(buf + offset);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 4 > len) { return false; }
  msg->rx_bytes = sbp_unpack_u32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  msg->tx_bytes = sbp_unpack_u32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
		for (size_t msginterface_name_idx = 0; msginterface_name_idx < 16; msginterface_name_idx++)
		{
        
  if (offset + 1 > len) { return false; }
  memcpy(&msg->interface_name[msginterface_name_idx], buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
		}
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_network_bandwidth_usage_t(const sbp_msg_network_bandwidth_usage_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
	    (
			  msg->n_interfaces
			*
				(                                                          
	0                                                                          
	  +
				sizeof( msg->interfaces[0].duration )                                                                          
	  +
				sizeof( msg->interfaces[0].total_bytes )                                                                          
	  +
				sizeof( msg->interfaces[0].rx_bytes )                                                                          
	  +
				sizeof( msg->interfaces[0].tx_bytes )                                                                          
	  +
		  ( 16 *
        sizeof( msg->interfaces[0].interface_name[0] )
		) )
			);
}

static inline bool sbp_pack_sbp_msg_network_bandwidth_usage_t(u8 *buf, size_t len, const sbp_msg_network_bandwidth_usage_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_network_bandwidth_usage_t(msg) > len) { return false; }
  
			for(size_t msginterfaces_idx = 0; msginterfaces_idx < (size_t)msg->n_interfaces; msginterfaces_idx++)
			{
					
        
  if (offset + 8 > len) { return false; }
  sbp_pack_u64(buf + offset, msg->interfaces[msginterfaces_idx].duration);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  sbp_pack_u64(buf + offset, msg->interfaces[msginterfaces_idx].total_bytes);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->interfaces[msginterfaces_idx].rx_bytes);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->interfaces[msginterfaces_idx].tx_bytes);
  // NOLINTNEXTLINE
  offset += 4;
		  for(size_t msginterfacesmsginterfaces_idxinterface_name_idx = 0; msginterfacesmsginterfaces_idxinterface_name_idx < 16; msginterfacesmsginterfaces_idxinterface_name_idx++)
			{
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->interfaces[msginterfaces_idx].interface_name[msginterfacesmsginterfaces_idxinterface_name_idx] , 1);
  // NOLINTNEXTLINE
  offset += 1;
			}
			}
  return true;
}

static inline bool sbp_unpack_sbp_msg_network_bandwidth_usage_t(const u8 *buf, size_t len, sbp_msg_network_bandwidth_usage_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
      msg->n_interfaces = (u8)((len - offset) / 40);

	  for (size_t msginterfaces_idx = 0; msginterfaces_idx <
				msg->n_interfaces;
				msginterfaces_idx++) 
		{
				
      
  if (offset + 8 > len) { return false; }
  msg->interfaces[msginterfaces_idx].duration = sbp_unpack_u64(buf + offset);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  msg->interfaces[msginterfaces_idx].total_bytes = sbp_unpack_u64(buf + offset);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 4 > len) { return false; }
  msg->interfaces[msginterfaces_idx].rx_bytes = sbp_unpack_u32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  msg->interfaces[msginterfaces_idx].tx_bytes = sbp_unpack_u32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
		for (size_t msginterfacesmsginterfaces_idxinterface_name_idx = 0; msginterfacesmsginterfaces_idxinterface_name_idx < 16; msginterfacesmsginterfaces_idxinterface_name_idx++)
		{
        
  if (offset + 1 > len) { return false; }
  memcpy(&msg->interfaces[msginterfaces_idx].interface_name[msginterfacesmsginterfaces_idxinterface_name_idx], buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
		}
		}
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_cell_modem_status_t(const sbp_msg_cell_modem_status_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				sizeof( msg->signal_strength )                                                                          
	  +
				sizeof( msg->signal_error_rate )                                                                          
	  +
	    (
			  msg->n_reserved
			*
        sizeof( msg->reserved[0] )
			);
}

static inline bool sbp_pack_sbp_msg_cell_modem_status_t(u8 *buf, size_t len, const sbp_msg_cell_modem_status_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_cell_modem_status_t(msg) > len) { return false; }
  
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->signal_strength , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 4 > len) { return false; }
  memcpy(buf + offset, & msg->signal_error_rate , 4);
  // NOLINTNEXTLINE
  offset += 4;
			for(size_t msgreserved_idx = 0; msgreserved_idx < (size_t)msg->n_reserved; msgreserved_idx++)
			{
          
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->reserved[msgreserved_idx] , 1);
  // NOLINTNEXTLINE
  offset += 1;
			}
  return true;
}

static inline bool sbp_unpack_sbp_msg_cell_modem_status_t(const u8 *buf, size_t len, sbp_msg_cell_modem_status_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->signal_strength, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->signal_error_rate, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;
      msg->n_reserved = (u8)((len - offset) / 1);

	  for (size_t msgreserved_idx = 0; msgreserved_idx <
				msg->n_reserved;
				msgreserved_idx++) 
		{
        
  if (offset + 1 > len) { return false; }
  memcpy(&msg->reserved[msgreserved_idx], buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
		}
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_specan_dep_t(const sbp_msg_specan_dep_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				sizeof( msg->channel_tag )                                                                          
	  +
				(                                                          
	0                                                                          
	  +
				sizeof( msg->t.tow )                                                                          
	  +
				sizeof( msg->t.wn ) )                                                                          
	  +
				sizeof( msg->freq_ref )                                                                          
	  +
				sizeof( msg->freq_step )                                                                          
	  +
				sizeof( msg->amplitude_ref )                                                                          
	  +
				sizeof( msg->amplitude_unit )                                                                          
	  +
	    (
			  msg->n_amplitude_value
			*
        sizeof( msg->amplitude_value[0] )
			);
}

static inline bool sbp_pack_sbp_msg_specan_dep_t(u8 *buf, size_t len, const sbp_msg_specan_dep_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_specan_dep_t(msg) > len) { return false; }
  
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->channel_tag);
  // NOLINTNEXTLINE
  offset += 2;
				
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->t.tow);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->t.wn);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 4 > len) { return false; }
  memcpy(buf + offset, & msg->freq_ref , 4);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  memcpy(buf + offset, & msg->freq_step , 4);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  memcpy(buf + offset, & msg->amplitude_ref , 4);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  memcpy(buf + offset, & msg->amplitude_unit , 4);
  // NOLINTNEXTLINE
  offset += 4;
			for(size_t msgamplitude_value_idx = 0; msgamplitude_value_idx < (size_t)msg->n_amplitude_value; msgamplitude_value_idx++)
			{
          
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->amplitude_value[msgamplitude_value_idx] , 1);
  // NOLINTNEXTLINE
  offset += 1;
			}
  return true;
}

static inline bool sbp_unpack_sbp_msg_specan_dep_t(const u8 *buf, size_t len, sbp_msg_specan_dep_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
      
  if (offset + 2 > len) { return false; }
  msg->channel_tag = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
			
      
  if (offset + 4 > len) { return false; }
  msg->t.tow = sbp_unpack_u32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 2 > len) { return false; }
  msg->t.wn = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->freq_ref, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->freq_step, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->amplitude_ref, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->amplitude_unit, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;
      msg->n_amplitude_value = (u8)((len - offset) / 1);

	  for (size_t msgamplitude_value_idx = 0; msgamplitude_value_idx <
				msg->n_amplitude_value;
				msgamplitude_value_idx++) 
		{
        
  if (offset + 1 > len) { return false; }
  memcpy(&msg->amplitude_value[msgamplitude_value_idx], buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
		}
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_specan_t(const sbp_msg_specan_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				sizeof( msg->channel_tag )                                                                          
	  +
				(                                                          
	0                                                                          
	  +
				sizeof( msg->t.tow )                                                                          
	  +
				sizeof( msg->t.ns_residual )                                                                          
	  +
				sizeof( msg->t.wn ) )                                                                          
	  +
				sizeof( msg->freq_ref )                                                                          
	  +
				sizeof( msg->freq_step )                                                                          
	  +
				sizeof( msg->amplitude_ref )                                                                          
	  +
				sizeof( msg->amplitude_unit )                                                                          
	  +
	    (
			  msg->n_amplitude_value
			*
        sizeof( msg->amplitude_value[0] )
			);
}

static inline bool sbp_pack_sbp_msg_specan_t(u8 *buf, size_t len, const sbp_msg_specan_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_specan_t(msg) > len) { return false; }
  
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->channel_tag);
  // NOLINTNEXTLINE
  offset += 2;
				
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->t.tow);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  sbp_pack_s32(buf + offset, msg->t.ns_residual);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->t.wn);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 4 > len) { return false; }
  memcpy(buf + offset, & msg->freq_ref , 4);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  memcpy(buf + offset, & msg->freq_step , 4);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  memcpy(buf + offset, & msg->amplitude_ref , 4);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  memcpy(buf + offset, & msg->amplitude_unit , 4);
  // NOLINTNEXTLINE
  offset += 4;
			for(size_t msgamplitude_value_idx = 0; msgamplitude_value_idx < (size_t)msg->n_amplitude_value; msgamplitude_value_idx++)
			{
          
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->amplitude_value[msgamplitude_value_idx] , 1);
  // NOLINTNEXTLINE
  offset += 1;
			}
  return true;
}

static inline bool sbp_unpack_sbp_msg_specan_t(const u8 *buf, size_t len, sbp_msg_specan_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
      
  if (offset + 2 > len) { return false; }
  msg->channel_tag = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
			
      
  if (offset + 4 > len) { return false; }
  msg->t.tow = sbp_unpack_u32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  msg->t.ns_residual = sbp_unpack_s32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 2 > len) { return false; }
  msg->t.wn = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->freq_ref, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->freq_step, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->amplitude_ref, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->amplitude_unit, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;
      msg->n_amplitude_value = (u8)((len - offset) / 1);

	  for (size_t msgamplitude_value_idx = 0; msgamplitude_value_idx <
				msg->n_amplitude_value;
				msgamplitude_value_idx++) 
		{
        
  if (offset + 1 > len) { return false; }
  memcpy(&msg->amplitude_value[msgamplitude_value_idx], buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
		}
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_front_end_gain_t(const sbp_msg_front_end_gain_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
		  ( 8 *
        sizeof( msg->rf_gain[0] )
		)                                                                          
	  +
		  ( 8 *
        sizeof( msg->if_gain[0] )
		);
}

static inline bool sbp_pack_sbp_msg_front_end_gain_t(u8 *buf, size_t len, const sbp_msg_front_end_gain_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_front_end_gain_t(msg) > len) { return false; }
  
		  for(size_t msgrf_gain_idx = 0; msgrf_gain_idx < 8; msgrf_gain_idx++)
			{
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->rf_gain[msgrf_gain_idx] , 1);
  // NOLINTNEXTLINE
  offset += 1;
			}
		  for(size_t msgif_gain_idx = 0; msgif_gain_idx < 8; msgif_gain_idx++)
			{
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->if_gain[msgif_gain_idx] , 1);
  // NOLINTNEXTLINE
  offset += 1;
			}
  return true;
}

static inline bool sbp_unpack_sbp_msg_front_end_gain_t(const u8 *buf, size_t len, sbp_msg_front_end_gain_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
		for (size_t msgrf_gain_idx = 0; msgrf_gain_idx < 8; msgrf_gain_idx++)
		{
        
  if (offset + 1 > len) { return false; }
  memcpy(&msg->rf_gain[msgrf_gain_idx], buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
		}
		for (size_t msgif_gain_idx = 0; msgif_gain_idx < 8; msgif_gain_idx++)
		{
        
  if (offset + 1 > len) { return false; }
  memcpy(&msg->if_gain[msgif_gain_idx], buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
		}
  return true;
}

#endif
