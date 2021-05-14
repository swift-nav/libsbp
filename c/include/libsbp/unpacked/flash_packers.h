#ifndef LIBSBP_FLASH_PACKERS_H
#define LIBSBP_FLASH_PACKERS_H

#ifndef LIBSBP_FLASH_MESSAGES_H
#error "Do not include this file directly, include libsbp/unpacked/flash.h instead"
#endif

#include <stdbool.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>
#include <math.h>

#include <libsbp/common.h>
#include <libsbp/string.h>

static inline size_t sbp_packed_size_sbp_msg_flash_program_t(const sbp_msg_flash_program_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				sizeof( msg->target )                                                                          
	  +
		  ( 3 *
        sizeof( msg->addr_start[0] )
		)                                                                          
	  +
				sizeof( msg->addr_len )                                                                          
	  +
	    (
	      msg->addr_len
			*
        sizeof( msg->data[0] )
			);
}

static inline bool sbp_pack_sbp_msg_flash_program_t(u8 *buf, size_t len, const sbp_msg_flash_program_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_flash_program_t(msg) > len) { return false; }
  
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->target , 1);
  // NOLINTNEXTLINE
  offset += 1;
		  for(size_t msgaddr_start_idx = 0; msgaddr_start_idx < 3; msgaddr_start_idx++)
			{
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->addr_start[msgaddr_start_idx] , 1);
  // NOLINTNEXTLINE
  offset += 1;
			}
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->addr_len , 1);
  // NOLINTNEXTLINE
  offset += 1;
			for(size_t msgdata_idx = 0; msgdata_idx < (size_t)msg->addr_len; msgdata_idx++)
			{
          
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->data[msgdata_idx] , 1);
  // NOLINTNEXTLINE
  offset += 1;
			}
  return true;
}

static inline bool sbp_unpack_sbp_msg_flash_program_t(const u8 *buf, size_t len, sbp_msg_flash_program_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->target, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
		for (size_t msgaddr_start_idx = 0; msgaddr_start_idx < 3; msgaddr_start_idx++)
		{
        
  if (offset + 1 > len) { return false; }
  memcpy(&msg->addr_start[msgaddr_start_idx], buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
		}
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->addr_len, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

	  for (size_t msgdata_idx = 0; msgdata_idx <
				msg->addr_len;
				msgdata_idx++) 
		{
        
  if (offset + 1 > len) { return false; }
  memcpy(&msg->data[msgdata_idx], buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
		}
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_flash_done_t(const sbp_msg_flash_done_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				sizeof( msg->response );
}

static inline bool sbp_pack_sbp_msg_flash_done_t(u8 *buf, size_t len, const sbp_msg_flash_done_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_flash_done_t(msg) > len) { return false; }
  
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->response , 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline bool sbp_unpack_sbp_msg_flash_done_t(const u8 *buf, size_t len, sbp_msg_flash_done_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->response, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_flash_read_req_t(const sbp_msg_flash_read_req_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				sizeof( msg->target )                                                                          
	  +
		  ( 3 *
        sizeof( msg->addr_start[0] )
		)                                                                          
	  +
				sizeof( msg->addr_len );
}

static inline bool sbp_pack_sbp_msg_flash_read_req_t(u8 *buf, size_t len, const sbp_msg_flash_read_req_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_flash_read_req_t(msg) > len) { return false; }
  
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->target , 1);
  // NOLINTNEXTLINE
  offset += 1;
		  for(size_t msgaddr_start_idx = 0; msgaddr_start_idx < 3; msgaddr_start_idx++)
			{
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->addr_start[msgaddr_start_idx] , 1);
  // NOLINTNEXTLINE
  offset += 1;
			}
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->addr_len , 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline bool sbp_unpack_sbp_msg_flash_read_req_t(const u8 *buf, size_t len, sbp_msg_flash_read_req_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->target, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
		for (size_t msgaddr_start_idx = 0; msgaddr_start_idx < 3; msgaddr_start_idx++)
		{
        
  if (offset + 1 > len) { return false; }
  memcpy(&msg->addr_start[msgaddr_start_idx], buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
		}
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->addr_len, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_flash_read_resp_t(const sbp_msg_flash_read_resp_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				sizeof( msg->target )                                                                          
	  +
		  ( 3 *
        sizeof( msg->addr_start[0] )
		)                                                                          
	  +
				sizeof( msg->addr_len );
}

static inline bool sbp_pack_sbp_msg_flash_read_resp_t(u8 *buf, size_t len, const sbp_msg_flash_read_resp_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_flash_read_resp_t(msg) > len) { return false; }
  
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->target , 1);
  // NOLINTNEXTLINE
  offset += 1;
		  for(size_t msgaddr_start_idx = 0; msgaddr_start_idx < 3; msgaddr_start_idx++)
			{
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->addr_start[msgaddr_start_idx] , 1);
  // NOLINTNEXTLINE
  offset += 1;
			}
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->addr_len , 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline bool sbp_unpack_sbp_msg_flash_read_resp_t(const u8 *buf, size_t len, sbp_msg_flash_read_resp_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->target, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
		for (size_t msgaddr_start_idx = 0; msgaddr_start_idx < 3; msgaddr_start_idx++)
		{
        
  if (offset + 1 > len) { return false; }
  memcpy(&msg->addr_start[msgaddr_start_idx], buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
		}
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->addr_len, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_flash_erase_t(const sbp_msg_flash_erase_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				sizeof( msg->target )                                                                          
	  +
				sizeof( msg->sector_num );
}

static inline bool sbp_pack_sbp_msg_flash_erase_t(u8 *buf, size_t len, const sbp_msg_flash_erase_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_flash_erase_t(msg) > len) { return false; }
  
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->target , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->sector_num);
  // NOLINTNEXTLINE
  offset += 4;
  return true;
}

static inline bool sbp_unpack_sbp_msg_flash_erase_t(const u8 *buf, size_t len, sbp_msg_flash_erase_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->target, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 4 > len) { return false; }
  msg->sector_num = sbp_unpack_u32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_stm_flash_lock_sector_t(const sbp_msg_stm_flash_lock_sector_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				sizeof( msg->sector );
}

static inline bool sbp_pack_sbp_msg_stm_flash_lock_sector_t(u8 *buf, size_t len, const sbp_msg_stm_flash_lock_sector_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_stm_flash_lock_sector_t(msg) > len) { return false; }
  
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->sector);
  // NOLINTNEXTLINE
  offset += 4;
  return true;
}

static inline bool sbp_unpack_sbp_msg_stm_flash_lock_sector_t(const u8 *buf, size_t len, sbp_msg_stm_flash_lock_sector_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
      
  if (offset + 4 > len) { return false; }
  msg->sector = sbp_unpack_u32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_stm_flash_unlock_sector_t(const sbp_msg_stm_flash_unlock_sector_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				sizeof( msg->sector );
}

static inline bool sbp_pack_sbp_msg_stm_flash_unlock_sector_t(u8 *buf, size_t len, const sbp_msg_stm_flash_unlock_sector_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_stm_flash_unlock_sector_t(msg) > len) { return false; }
  
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->sector);
  // NOLINTNEXTLINE
  offset += 4;
  return true;
}

static inline bool sbp_unpack_sbp_msg_stm_flash_unlock_sector_t(const u8 *buf, size_t len, sbp_msg_stm_flash_unlock_sector_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
      
  if (offset + 4 > len) { return false; }
  msg->sector = sbp_unpack_u32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_stm_unique_id_req_t(const sbp_msg_stm_unique_id_req_t *msg) {                                
	(void)msg;
  return                                                          
	0;
}

static inline bool sbp_pack_sbp_msg_stm_unique_id_req_t(u8 *buf, size_t len, const sbp_msg_stm_unique_id_req_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_stm_unique_id_req_t(msg) > len) { return false; }
  
  return true;
}

static inline bool sbp_unpack_sbp_msg_stm_unique_id_req_t(const u8 *buf, size_t len, sbp_msg_stm_unique_id_req_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_stm_unique_id_resp_t(const sbp_msg_stm_unique_id_resp_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
		  ( 12 *
        sizeof( msg->stm_id[0] )
		);
}

static inline bool sbp_pack_sbp_msg_stm_unique_id_resp_t(u8 *buf, size_t len, const sbp_msg_stm_unique_id_resp_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_stm_unique_id_resp_t(msg) > len) { return false; }
  
		  for(size_t msgstm_id_idx = 0; msgstm_id_idx < 12; msgstm_id_idx++)
			{
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->stm_id[msgstm_id_idx] , 1);
  // NOLINTNEXTLINE
  offset += 1;
			}
  return true;
}

static inline bool sbp_unpack_sbp_msg_stm_unique_id_resp_t(const u8 *buf, size_t len, sbp_msg_stm_unique_id_resp_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
		for (size_t msgstm_id_idx = 0; msgstm_id_idx < 12; msgstm_id_idx++)
		{
        
  if (offset + 1 > len) { return false; }
  memcpy(&msg->stm_id[msgstm_id_idx], buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
		}
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_m25_flash_write_status_t(const sbp_msg_m25_flash_write_status_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
		  ( 1 *
        sizeof( msg->status[0] )
		);
}

static inline bool sbp_pack_sbp_msg_m25_flash_write_status_t(u8 *buf, size_t len, const sbp_msg_m25_flash_write_status_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_m25_flash_write_status_t(msg) > len) { return false; }
  
		  for(size_t msgstatus_idx = 0; msgstatus_idx < 1; msgstatus_idx++)
			{
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->status[msgstatus_idx] , 1);
  // NOLINTNEXTLINE
  offset += 1;
			}
  return true;
}

static inline bool sbp_unpack_sbp_msg_m25_flash_write_status_t(const u8 *buf, size_t len, sbp_msg_m25_flash_write_status_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
		for (size_t msgstatus_idx = 0; msgstatus_idx < 1; msgstatus_idx++)
		{
        
  if (offset + 1 > len) { return false; }
  memcpy(&msg->status[msgstatus_idx], buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
		}
  return true;
}

#endif
