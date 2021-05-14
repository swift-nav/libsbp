#ifndef LIBSBP_VEHICLE_PACKERS_H
#define LIBSBP_VEHICLE_PACKERS_H

#ifndef LIBSBP_VEHICLE_MESSAGES_H
#error "Do not include this file directly, include libsbp/unpacked/vehicle.h instead"
#endif

#include <stdbool.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>
#include <math.h>

#include <libsbp/common.h>
#include <libsbp/string.h>

static inline size_t sbp_packed_size_sbp_msg_odometry_t(const sbp_msg_odometry_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				sizeof( msg->tow )                                                                          
	  +
				sizeof( msg->velocity )                                                                          
	  +
				sizeof( msg->flags );
}

static inline bool sbp_pack_sbp_msg_odometry_t(u8 *buf, size_t len, const sbp_msg_odometry_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_odometry_t(msg) > len) { return false; }
  
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->tow);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  sbp_pack_s32(buf + offset, msg->velocity);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->flags , 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline bool sbp_unpack_sbp_msg_odometry_t(const u8 *buf, size_t len, sbp_msg_odometry_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
      
  if (offset + 4 > len) { return false; }
  msg->tow = sbp_unpack_u32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  msg->velocity = sbp_unpack_s32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->flags, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_wheeltick_t(const sbp_msg_wheeltick_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				sizeof( msg->time )                                                                          
	  +
				sizeof( msg->flags )                                                                          
	  +
				sizeof( msg->source )                                                                          
	  +
				sizeof( msg->ticks );
}

static inline bool sbp_pack_sbp_msg_wheeltick_t(u8 *buf, size_t len, const sbp_msg_wheeltick_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_wheeltick_t(msg) > len) { return false; }
  
        
  if (offset + 8 > len) { return false; }
  sbp_pack_u64(buf + offset, msg->time);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->flags , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->source , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 4 > len) { return false; }
  sbp_pack_s32(buf + offset, msg->ticks);
  // NOLINTNEXTLINE
  offset += 4;
  return true;
}

static inline bool sbp_unpack_sbp_msg_wheeltick_t(const u8 *buf, size_t len, sbp_msg_wheeltick_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
      
  if (offset + 8 > len) { return false; }
  msg->time = sbp_unpack_u64(buf + offset);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->flags, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->source, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 4 > len) { return false; }
  msg->ticks = sbp_unpack_s32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
  return true;
}

#endif
