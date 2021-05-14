#ifndef LIBSBP_FILE_IO_PACKERS_H
#define LIBSBP_FILE_IO_PACKERS_H

#ifndef LIBSBP_FILE_IO_MESSAGES_H
#error "Do not include this file directly, include libsbp/unpacked/file_io.h instead"
#endif

#include <stdbool.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>
#include <math.h>

#include <libsbp/common.h>
#include <libsbp/string.h>

static inline size_t sbp_packed_size_sbp_msg_fileio_read_req_t(const sbp_msg_fileio_read_req_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				sizeof( msg->sequence )                                                                          
	  +
				sizeof( msg->offset )                                                                          
	  +
				sizeof( msg->chunk_size )                                                                          
	  +
      sbp_null_terminated_string_packed_len(&msg->filename, 246);
}

static inline bool sbp_pack_sbp_msg_fileio_read_req_t(u8 *buf, size_t len, const sbp_msg_fileio_read_req_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_fileio_read_req_t(msg) > len) { return false; }
  
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->sequence);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->offset);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->chunk_size , 1);
  // NOLINTNEXTLINE
  offset += 1;
        offset += sbp_null_terminated_string_pack(&msg->filename, 246, buf + offset, (uint8_t)(len - offset));
  return true;
}

static inline bool sbp_unpack_sbp_msg_fileio_read_req_t(const u8 *buf, size_t len, sbp_msg_fileio_read_req_t *msg) {
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
  msg->offset = sbp_unpack_u32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->chunk_size, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      offset += sbp_null_terminated_string_unpack(&msg->filename, 246, buf + offset, (uint8_t)(len - offset));
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_fileio_read_resp_t(const sbp_msg_fileio_read_resp_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				sizeof( msg->sequence )                                                                          
	  +
	    (
			  msg->n_contents
			*
        sizeof( msg->contents[0] )
			);
}

static inline bool sbp_pack_sbp_msg_fileio_read_resp_t(u8 *buf, size_t len, const sbp_msg_fileio_read_resp_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_fileio_read_resp_t(msg) > len) { return false; }
  
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->sequence);
  // NOLINTNEXTLINE
  offset += 4;
			for(size_t msgcontents_idx = 0; msgcontents_idx < (size_t)msg->n_contents; msgcontents_idx++)
			{
          
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->contents[msgcontents_idx] , 1);
  // NOLINTNEXTLINE
  offset += 1;
			}
  return true;
}

static inline bool sbp_unpack_sbp_msg_fileio_read_resp_t(const u8 *buf, size_t len, sbp_msg_fileio_read_resp_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
      
  if (offset + 4 > len) { return false; }
  msg->sequence = sbp_unpack_u32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      msg->n_contents = (u8)((len - offset) / 1);

	  for (size_t msgcontents_idx = 0; msgcontents_idx <
				msg->n_contents;
				msgcontents_idx++) 
		{
        
  if (offset + 1 > len) { return false; }
  memcpy(&msg->contents[msgcontents_idx], buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
		}
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_fileio_read_dir_req_t(const sbp_msg_fileio_read_dir_req_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				sizeof( msg->sequence )                                                                          
	  +
				sizeof( msg->offset )                                                                          
	  +
      sbp_null_terminated_string_packed_len(&msg->dirname, 247);
}

static inline bool sbp_pack_sbp_msg_fileio_read_dir_req_t(u8 *buf, size_t len, const sbp_msg_fileio_read_dir_req_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_fileio_read_dir_req_t(msg) > len) { return false; }
  
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->sequence);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->offset);
  // NOLINTNEXTLINE
  offset += 4;
        offset += sbp_null_terminated_string_pack(&msg->dirname, 247, buf + offset, (uint8_t)(len - offset));
  return true;
}

static inline bool sbp_unpack_sbp_msg_fileio_read_dir_req_t(const u8 *buf, size_t len, sbp_msg_fileio_read_dir_req_t *msg) {
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
  msg->offset = sbp_unpack_u32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      offset += sbp_null_terminated_string_unpack(&msg->dirname, 247, buf + offset, (uint8_t)(len - offset));
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_fileio_read_dir_resp_t(const sbp_msg_fileio_read_dir_resp_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				sizeof( msg->sequence )                                                                          
	  +
      sbp_sequence_string_packed_len(&msg->contents, 251, 255);
}

static inline bool sbp_pack_sbp_msg_fileio_read_dir_resp_t(u8 *buf, size_t len, const sbp_msg_fileio_read_dir_resp_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_fileio_read_dir_resp_t(msg) > len) { return false; }
  
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->sequence);
  // NOLINTNEXTLINE
  offset += 4;
        offset += sbp_sequence_string_pack(&msg->contents, 251, 255, buf + offset, (uint8_t)(len - offset));
  return true;
}

static inline bool sbp_unpack_sbp_msg_fileio_read_dir_resp_t(const u8 *buf, size_t len, sbp_msg_fileio_read_dir_resp_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
      
  if (offset + 4 > len) { return false; }
  msg->sequence = sbp_unpack_u32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      offset += sbp_sequence_string_unpack(&msg->contents, 251, 255, buf + offset, (uint8_t)(len - offset));
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_fileio_remove_t(const sbp_msg_fileio_remove_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
      sbp_null_terminated_string_packed_len(&msg->filename, 255);
}

static inline bool sbp_pack_sbp_msg_fileio_remove_t(u8 *buf, size_t len, const sbp_msg_fileio_remove_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_fileio_remove_t(msg) > len) { return false; }
  
        offset += sbp_null_terminated_string_pack(&msg->filename, 255, buf + offset, (uint8_t)(len - offset));
  return true;
}

static inline bool sbp_unpack_sbp_msg_fileio_remove_t(const u8 *buf, size_t len, sbp_msg_fileio_remove_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
      offset += sbp_null_terminated_string_unpack(&msg->filename, 255, buf + offset, (uint8_t)(len - offset));
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_fileio_write_req_t(const sbp_msg_fileio_write_req_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				sizeof( msg->sequence )                                                                          
	  +
				sizeof( msg->offset )                                                                          
	  +
      sbp_null_terminated_string_packed_len(&msg->filename, 247)                                                                          
	  +
	    (
			  msg->n_data
			*
        sizeof( msg->data[0] )
			);
}

static inline bool sbp_pack_sbp_msg_fileio_write_req_t(u8 *buf, size_t len, const sbp_msg_fileio_write_req_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_fileio_write_req_t(msg) > len) { return false; }
  
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->sequence);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->offset);
  // NOLINTNEXTLINE
  offset += 4;
        offset += sbp_null_terminated_string_pack(&msg->filename, 247, buf + offset, (uint8_t)(len - offset));
			for(size_t msgdata_idx = 0; msgdata_idx < (size_t)msg->n_data; msgdata_idx++)
			{
          
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->data[msgdata_idx] , 1);
  // NOLINTNEXTLINE
  offset += 1;
			}
  return true;
}

static inline bool sbp_unpack_sbp_msg_fileio_write_req_t(const u8 *buf, size_t len, sbp_msg_fileio_write_req_t *msg) {
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
  msg->offset = sbp_unpack_u32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      offset += sbp_null_terminated_string_unpack(&msg->filename, 247, buf + offset, (uint8_t)(len - offset));
      msg->n_data = (u8)((len - offset) / 1);

	  for (size_t msgdata_idx = 0; msgdata_idx <
				msg->n_data;
				msgdata_idx++) 
		{
        
  if (offset + 1 > len) { return false; }
  memcpy(&msg->data[msgdata_idx], buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
		}
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_fileio_write_resp_t(const sbp_msg_fileio_write_resp_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				sizeof( msg->sequence );
}

static inline bool sbp_pack_sbp_msg_fileio_write_resp_t(u8 *buf, size_t len, const sbp_msg_fileio_write_resp_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_fileio_write_resp_t(msg) > len) { return false; }
  
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->sequence);
  // NOLINTNEXTLINE
  offset += 4;
  return true;
}

static inline bool sbp_unpack_sbp_msg_fileio_write_resp_t(const u8 *buf, size_t len, sbp_msg_fileio_write_resp_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
      
  if (offset + 4 > len) { return false; }
  msg->sequence = sbp_unpack_u32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_fileio_config_req_t(const sbp_msg_fileio_config_req_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				sizeof( msg->sequence );
}

static inline bool sbp_pack_sbp_msg_fileio_config_req_t(u8 *buf, size_t len, const sbp_msg_fileio_config_req_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_fileio_config_req_t(msg) > len) { return false; }
  
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->sequence);
  // NOLINTNEXTLINE
  offset += 4;
  return true;
}

static inline bool sbp_unpack_sbp_msg_fileio_config_req_t(const u8 *buf, size_t len, sbp_msg_fileio_config_req_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
      
  if (offset + 4 > len) { return false; }
  msg->sequence = sbp_unpack_u32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_fileio_config_resp_t(const sbp_msg_fileio_config_resp_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				sizeof( msg->sequence )                                                                          
	  +
				sizeof( msg->window_size )                                                                          
	  +
				sizeof( msg->batch_size )                                                                          
	  +
				sizeof( msg->fileio_version );
}

static inline bool sbp_pack_sbp_msg_fileio_config_resp_t(u8 *buf, size_t len, const sbp_msg_fileio_config_resp_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_fileio_config_resp_t(msg) > len) { return false; }
  
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->sequence);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->window_size);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->batch_size);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->fileio_version);
  // NOLINTNEXTLINE
  offset += 4;
  return true;
}

static inline bool sbp_unpack_sbp_msg_fileio_config_resp_t(const u8 *buf, size_t len, sbp_msg_fileio_config_resp_t *msg) {
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
  msg->window_size = sbp_unpack_u32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  msg->batch_size = sbp_unpack_u32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  msg->fileio_version = sbp_unpack_u32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
  return true;
}

#endif
