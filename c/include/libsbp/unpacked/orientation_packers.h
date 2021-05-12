#ifndef LIBSBP_ORIENTATION_PACKERS_H
#define LIBSBP_ORIENTATION_PACKERS_H

#ifndef LIBSBP_ORIENTATION_MESSAGES_H
#error "Do not include this file directly, include libsbp/unpacked/orientation.h instead"
#endif

#include <stdbool.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>
#include <endian.h>
#include <math.h>

#include <libsbp/common.h>
#include <libsbp/string2.h>

static inline size_t sbp_packed_size_sbp_msg_baseline_heading_t(const sbp_msg_baseline_heading_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				sizeof( msg->tow )                                                                          
	  +
				sizeof( msg->heading )                                                                          
	  +
				sizeof( msg->n_sats )                                                                          
	  +
				sizeof( msg->flags );
}

static inline bool sbp_pack_sbp_msg_baseline_heading_t(u8 *buf, size_t len, const sbp_msg_baseline_heading_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_baseline_heading_t(msg) > len) { return false; }
  
        
  if (offset + 4 > len) { return false; }
  u32 msgtow = htole32( msg->tow );
  memcpy(buf + offset, & msgtow , 4);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  u32 msgheading = htole32( msg->heading );
  memcpy(buf + offset, & msgheading , 4);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 1 > len) { return false; }
  u8 msgn_sats = msg->n_sats;
  memcpy(buf + offset, & msgn_sats , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  u8 msgflags = msg->flags;
  memcpy(buf + offset, & msgflags , 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline bool sbp_unpack_sbp_msg_baseline_heading_t(const u8 *buf, size_t len, sbp_msg_baseline_heading_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->tow, buf + offset, 4);
  msg->tow = le32toh( msg->tow );
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->heading, buf + offset, 4);
  msg->heading = le32toh( msg->heading );
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->n_sats, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->flags, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_orient_quat_t(const sbp_msg_orient_quat_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				sizeof( msg->tow )                                                                          
	  +
				sizeof( msg->w )                                                                          
	  +
				sizeof( msg->x )                                                                          
	  +
				sizeof( msg->y )                                                                          
	  +
				sizeof( msg->z )                                                                          
	  +
				sizeof( msg->w_accuracy )                                                                          
	  +
				sizeof( msg->x_accuracy )                                                                          
	  +
				sizeof( msg->y_accuracy )                                                                          
	  +
				sizeof( msg->z_accuracy )                                                                          
	  +
				sizeof( msg->flags );
}

static inline bool sbp_pack_sbp_msg_orient_quat_t(u8 *buf, size_t len, const sbp_msg_orient_quat_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_orient_quat_t(msg) > len) { return false; }
  
        
  if (offset + 4 > len) { return false; }
  u32 msgtow = htole32( msg->tow );
  memcpy(buf + offset, & msgtow , 4);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  u32 msgw = htole32( *(const u32*)&msg->w );
  memcpy(buf + offset, & msgw , 4);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  u32 msgx = htole32( *(const u32*)&msg->x );
  memcpy(buf + offset, & msgx , 4);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  u32 msgy = htole32( *(const u32*)&msg->y );
  memcpy(buf + offset, & msgy , 4);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  u32 msgz = htole32( *(const u32*)&msg->z );
  memcpy(buf + offset, & msgz , 4);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  float msgw_accuracy = msg->w_accuracy;
  memcpy(buf + offset, & msgw_accuracy , 4);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  float msgx_accuracy = msg->x_accuracy;
  memcpy(buf + offset, & msgx_accuracy , 4);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  float msgy_accuracy = msg->y_accuracy;
  memcpy(buf + offset, & msgy_accuracy , 4);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  float msgz_accuracy = msg->z_accuracy;
  memcpy(buf + offset, & msgz_accuracy , 4);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 1 > len) { return false; }
  u8 msgflags = msg->flags;
  memcpy(buf + offset, & msgflags , 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline bool sbp_unpack_sbp_msg_orient_quat_t(const u8 *buf, size_t len, sbp_msg_orient_quat_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->tow, buf + offset, 4);
  msg->tow = le32toh( msg->tow );
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->w, buf + offset, 4);
  u32 msgw = *(const u32*)&msg->w;
  msgw = le32toh( msgw );
  msg->w = *(const s32*)&msgw;
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->x, buf + offset, 4);
  u32 msgx = *(const u32*)&msg->x;
  msgx = le32toh( msgx );
  msg->x = *(const s32*)&msgx;
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->y, buf + offset, 4);
  u32 msgy = *(const u32*)&msg->y;
  msgy = le32toh( msgy );
  msg->y = *(const s32*)&msgy;
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->z, buf + offset, 4);
  u32 msgz = *(const u32*)&msg->z;
  msgz = le32toh( msgz );
  msg->z = *(const s32*)&msgz;
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->w_accuracy, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->x_accuracy, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->y_accuracy, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->z_accuracy, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->flags, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_orient_euler_t(const sbp_msg_orient_euler_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				sizeof( msg->tow )                                                                          
	  +
				sizeof( msg->roll )                                                                          
	  +
				sizeof( msg->pitch )                                                                          
	  +
				sizeof( msg->yaw )                                                                          
	  +
				sizeof( msg->roll_accuracy )                                                                          
	  +
				sizeof( msg->pitch_accuracy )                                                                          
	  +
				sizeof( msg->yaw_accuracy )                                                                          
	  +
				sizeof( msg->flags );
}

static inline bool sbp_pack_sbp_msg_orient_euler_t(u8 *buf, size_t len, const sbp_msg_orient_euler_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_orient_euler_t(msg) > len) { return false; }
  
        
  if (offset + 4 > len) { return false; }
  u32 msgtow = htole32( msg->tow );
  memcpy(buf + offset, & msgtow , 4);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  u32 msgroll = htole32( *(const u32*)&msg->roll );
  memcpy(buf + offset, & msgroll , 4);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  u32 msgpitch = htole32( *(const u32*)&msg->pitch );
  memcpy(buf + offset, & msgpitch , 4);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  u32 msgyaw = htole32( *(const u32*)&msg->yaw );
  memcpy(buf + offset, & msgyaw , 4);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  float msgroll_accuracy = msg->roll_accuracy;
  memcpy(buf + offset, & msgroll_accuracy , 4);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  float msgpitch_accuracy = msg->pitch_accuracy;
  memcpy(buf + offset, & msgpitch_accuracy , 4);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  float msgyaw_accuracy = msg->yaw_accuracy;
  memcpy(buf + offset, & msgyaw_accuracy , 4);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 1 > len) { return false; }
  u8 msgflags = msg->flags;
  memcpy(buf + offset, & msgflags , 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline bool sbp_unpack_sbp_msg_orient_euler_t(const u8 *buf, size_t len, sbp_msg_orient_euler_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->tow, buf + offset, 4);
  msg->tow = le32toh( msg->tow );
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->roll, buf + offset, 4);
  u32 msgroll = *(const u32*)&msg->roll;
  msgroll = le32toh( msgroll );
  msg->roll = *(const s32*)&msgroll;
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->pitch, buf + offset, 4);
  u32 msgpitch = *(const u32*)&msg->pitch;
  msgpitch = le32toh( msgpitch );
  msg->pitch = *(const s32*)&msgpitch;
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->yaw, buf + offset, 4);
  u32 msgyaw = *(const u32*)&msg->yaw;
  msgyaw = le32toh( msgyaw );
  msg->yaw = *(const s32*)&msgyaw;
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->roll_accuracy, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->pitch_accuracy, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->yaw_accuracy, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->flags, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_angular_rate_t(const sbp_msg_angular_rate_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				sizeof( msg->tow )                                                                          
	  +
				sizeof( msg->x )                                                                          
	  +
				sizeof( msg->y )                                                                          
	  +
				sizeof( msg->z )                                                                          
	  +
				sizeof( msg->flags );
}

static inline bool sbp_pack_sbp_msg_angular_rate_t(u8 *buf, size_t len, const sbp_msg_angular_rate_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_angular_rate_t(msg) > len) { return false; }
  
        
  if (offset + 4 > len) { return false; }
  u32 msgtow = htole32( msg->tow );
  memcpy(buf + offset, & msgtow , 4);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  u32 msgx = htole32( *(const u32*)&msg->x );
  memcpy(buf + offset, & msgx , 4);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  u32 msgy = htole32( *(const u32*)&msg->y );
  memcpy(buf + offset, & msgy , 4);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  u32 msgz = htole32( *(const u32*)&msg->z );
  memcpy(buf + offset, & msgz , 4);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 1 > len) { return false; }
  u8 msgflags = msg->flags;
  memcpy(buf + offset, & msgflags , 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline bool sbp_unpack_sbp_msg_angular_rate_t(const u8 *buf, size_t len, sbp_msg_angular_rate_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->tow, buf + offset, 4);
  msg->tow = le32toh( msg->tow );
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->x, buf + offset, 4);
  u32 msgx = *(const u32*)&msg->x;
  msgx = le32toh( msgx );
  msg->x = *(const s32*)&msgx;
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->y, buf + offset, 4);
  u32 msgy = *(const u32*)&msg->y;
  msgy = le32toh( msgy );
  msg->y = *(const s32*)&msgy;
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->z, buf + offset, 4);
  u32 msgz = *(const u32*)&msg->z;
  msgz = le32toh( msgz );
  msg->z = *(const s32*)&msgz;
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->flags, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

#endif
