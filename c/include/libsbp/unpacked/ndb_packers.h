#ifndef LIBSBP_NDB_PACKERS_H
#define LIBSBP_NDB_PACKERS_H

#ifndef LIBSBP_NDB_MESSAGES_H
#error "Do not include this file directly, include libsbp/unpacked/ndb.h instead"
#endif

#include <stdbool.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>
#include <math.h>

#include <libsbp/common.h>
#include <libsbp/string.h>

static inline size_t sbp_packed_size_sbp_msg_ndb_event_t(const sbp_msg_ndb_event_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				sizeof( msg->recv_time )                                                                          
	  +
				sizeof( msg->event )                                                                          
	  +
				sizeof( msg->object_type )                                                                          
	  +
				sizeof( msg->result )                                                                          
	  +
				sizeof( msg->data_source )                                                                          
	  +
				(                                                          
	0                                                                          
	  +
				sizeof( msg->object_sid.sat )                                                                          
	  +
				sizeof( msg->object_sid.code ) )                                                                          
	  +
				(                                                          
	0                                                                          
	  +
				sizeof( msg->src_sid.sat )                                                                          
	  +
				sizeof( msg->src_sid.code ) )                                                                          
	  +
				sizeof( msg->original_sender );
}

static inline bool sbp_pack_sbp_msg_ndb_event_t(u8 *buf, size_t len, const sbp_msg_ndb_event_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_ndb_event_t(msg) > len) { return false; }
  
        
  if (offset + 8 > len) { return false; }
  sbp_pack_u64(buf + offset, msg->recv_time);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->event , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->object_type , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->result , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->data_source , 1);
  // NOLINTNEXTLINE
  offset += 1;
				
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->object_sid.sat , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->object_sid.code , 1);
  // NOLINTNEXTLINE
  offset += 1;
				
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->src_sid.sat , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->src_sid.code , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->original_sender);
  // NOLINTNEXTLINE
  offset += 2;
  return true;
}

static inline bool sbp_unpack_sbp_msg_ndb_event_t(const u8 *buf, size_t len, sbp_msg_ndb_event_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
      
  if (offset + 8 > len) { return false; }
  msg->recv_time = sbp_unpack_u64(buf + offset);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->event, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->object_type, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->result, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->data_source, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
			
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->object_sid.sat, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->object_sid.code, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
			
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->src_sid.sat, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->src_sid.code, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 2 > len) { return false; }
  msg->original_sender = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
  return true;
}

#endif
