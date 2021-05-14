#ifndef LIBSBP_EXT_EVENTS_PACKERS_H
#define LIBSBP_EXT_EVENTS_PACKERS_H

#ifndef LIBSBP_EXT_EVENTS_MESSAGES_H
#error "Do not include this file directly, include libsbp/unpacked/ext_events.h instead"
#endif

#include <stdbool.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>
#include <math.h>

#include <libsbp/common.h>
#include <libsbp/string.h>

static inline size_t sbp_packed_size_sbp_msg_ext_event_t(const sbp_msg_ext_event_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				sizeof( msg->wn )                                                                          
	  +
				sizeof( msg->tow )                                                                          
	  +
				sizeof( msg->ns_residual )                                                                          
	  +
				sizeof( msg->flags )                                                                          
	  +
				sizeof( msg->pin );
}

static inline bool sbp_pack_sbp_msg_ext_event_t(u8 *buf, size_t len, const sbp_msg_ext_event_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_ext_event_t(msg) > len) { return false; }
  
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->wn);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->tow);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  sbp_pack_s32(buf + offset, msg->ns_residual);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->flags , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->pin , 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline bool sbp_unpack_sbp_msg_ext_event_t(const u8 *buf, size_t len, sbp_msg_ext_event_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
      
  if (offset + 2 > len) { return false; }
  msg->wn = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 4 > len) { return false; }
  msg->tow = sbp_unpack_u32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  msg->ns_residual = sbp_unpack_s32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->flags, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->pin, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

#endif
