#ifndef LIBSBP_TRACKING_PACKERS_H
#define LIBSBP_TRACKING_PACKERS_H

#ifndef LIBSBP_TRACKING_MESSAGES_H
#error "Do not include this file directly, include libsbp/unpacked/tracking.h instead"
#endif

#include <stdbool.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>
#include <math.h>

#include <libsbp/common.h>
#include <libsbp/string.h>

static inline size_t sbp_packed_size_sbp_msg_tracking_state_detailed_dep_a_t(const sbp_msg_tracking_state_detailed_dep_a_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				sizeof( msg->recv_time )                                                                          
	  +
				(                                                          
	0                                                                          
	  +
				sizeof( msg->tot.tow )                                                                          
	  +
				sizeof( msg->tot.ns_residual )                                                                          
	  +
				sizeof( msg->tot.wn ) )                                                                          
	  +
				sizeof( msg->P )                                                                          
	  +
				sizeof( msg->P_std )                                                                          
	  +
				(                                                          
	0                                                                          
	  +
				sizeof( msg->L.i )                                                                          
	  +
				sizeof( msg->L.f ) )                                                                          
	  +
				sizeof( msg->cn0 )                                                                          
	  +
				sizeof( msg->lock )                                                                          
	  +
				(                                                          
	0                                                                          
	  +
				sizeof( msg->sid.sat )                                                                          
	  +
				sizeof( msg->sid.code ) )                                                                          
	  +
				sizeof( msg->doppler )                                                                          
	  +
				sizeof( msg->doppler_std )                                                                          
	  +
				sizeof( msg->uptime )                                                                          
	  +
				sizeof( msg->clock_offset )                                                                          
	  +
				sizeof( msg->clock_drift )                                                                          
	  +
				sizeof( msg->corr_spacing )                                                                          
	  +
				sizeof( msg->acceleration )                                                                          
	  +
				sizeof( msg->sync_flags )                                                                          
	  +
				sizeof( msg->tow_flags )                                                                          
	  +
				sizeof( msg->track_flags )                                                                          
	  +
				sizeof( msg->nav_flags )                                                                          
	  +
				sizeof( msg->pset_flags )                                                                          
	  +
				sizeof( msg->misc_flags );
}

static inline bool sbp_pack_sbp_msg_tracking_state_detailed_dep_a_t(u8 *buf, size_t len, const sbp_msg_tracking_state_detailed_dep_a_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_tracking_state_detailed_dep_a_t(msg) > len) { return false; }
  
        
  if (offset + 8 > len) { return false; }
  sbp_pack_u64(buf + offset, msg->recv_time);
  // NOLINTNEXTLINE
  offset += 8;
				
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->tot.tow);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  sbp_pack_s32(buf + offset, msg->tot.ns_residual);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->tot.wn);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->P);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->P_std);
  // NOLINTNEXTLINE
  offset += 2;
				
        
  if (offset + 4 > len) { return false; }
  sbp_pack_s32(buf + offset, msg->L.i);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->L.f , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->cn0 , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->lock);
  // NOLINTNEXTLINE
  offset += 2;
				
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->sid.sat , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->sid.code , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 4 > len) { return false; }
  sbp_pack_s32(buf + offset, msg->doppler);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->doppler_std);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->uptime);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_s16(buf + offset, msg->clock_offset);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_s16(buf + offset, msg->clock_drift);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->corr_spacing);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->acceleration , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->sync_flags , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->tow_flags , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->track_flags , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->nav_flags , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->pset_flags , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->misc_flags , 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline bool sbp_unpack_sbp_msg_tracking_state_detailed_dep_a_t(const u8 *buf, size_t len, sbp_msg_tracking_state_detailed_dep_a_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
      
  if (offset + 8 > len) { return false; }
  msg->recv_time = sbp_unpack_u64(buf + offset);
  // NOLINTNEXTLINE
  offset += 8;
			
      
  if (offset + 4 > len) { return false; }
  msg->tot.tow = sbp_unpack_u32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  msg->tot.ns_residual = sbp_unpack_s32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 2 > len) { return false; }
  msg->tot.wn = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 4 > len) { return false; }
  msg->P = sbp_unpack_u32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 2 > len) { return false; }
  msg->P_std = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
			
      
  if (offset + 4 > len) { return false; }
  msg->L.i = sbp_unpack_s32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->L.f, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->cn0, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 2 > len) { return false; }
  msg->lock = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
			
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->sid.sat, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->sid.code, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 4 > len) { return false; }
  msg->doppler = sbp_unpack_s32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 2 > len) { return false; }
  msg->doppler_std = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 4 > len) { return false; }
  msg->uptime = sbp_unpack_u32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 2 > len) { return false; }
  msg->clock_offset = sbp_unpack_s16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 2 > len) { return false; }
  msg->clock_drift = sbp_unpack_s16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 2 > len) { return false; }
  msg->corr_spacing = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->acceleration, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->sync_flags, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->tow_flags, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->track_flags, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->nav_flags, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->pset_flags, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->misc_flags, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_tracking_state_detailed_dep_t(const sbp_msg_tracking_state_detailed_dep_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				sizeof( msg->recv_time )                                                                          
	  +
				(                                                          
	0                                                                          
	  +
				sizeof( msg->tot.tow )                                                                          
	  +
				sizeof( msg->tot.wn ) )                                                                          
	  +
				sizeof( msg->P )                                                                          
	  +
				sizeof( msg->P_std )                                                                          
	  +
				(                                                          
	0                                                                          
	  +
				sizeof( msg->L.i )                                                                          
	  +
				sizeof( msg->L.f ) )                                                                          
	  +
				sizeof( msg->cn0 )                                                                          
	  +
				sizeof( msg->lock )                                                                          
	  +
				(                                                          
	0                                                                          
	  +
				sizeof( msg->sid.sat )                                                                          
	  +
				sizeof( msg->sid.code )                                                                          
	  +
				sizeof( msg->sid.reserved ) )                                                                          
	  +
				sizeof( msg->doppler )                                                                          
	  +
				sizeof( msg->doppler_std )                                                                          
	  +
				sizeof( msg->uptime )                                                                          
	  +
				sizeof( msg->clock_offset )                                                                          
	  +
				sizeof( msg->clock_drift )                                                                          
	  +
				sizeof( msg->corr_spacing )                                                                          
	  +
				sizeof( msg->acceleration )                                                                          
	  +
				sizeof( msg->sync_flags )                                                                          
	  +
				sizeof( msg->tow_flags )                                                                          
	  +
				sizeof( msg->track_flags )                                                                          
	  +
				sizeof( msg->nav_flags )                                                                          
	  +
				sizeof( msg->pset_flags )                                                                          
	  +
				sizeof( msg->misc_flags );
}

static inline bool sbp_pack_sbp_msg_tracking_state_detailed_dep_t(u8 *buf, size_t len, const sbp_msg_tracking_state_detailed_dep_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_tracking_state_detailed_dep_t(msg) > len) { return false; }
  
        
  if (offset + 8 > len) { return false; }
  sbp_pack_u64(buf + offset, msg->recv_time);
  // NOLINTNEXTLINE
  offset += 8;
				
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->tot.tow);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->tot.wn);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->P);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->P_std);
  // NOLINTNEXTLINE
  offset += 2;
				
        
  if (offset + 4 > len) { return false; }
  sbp_pack_s32(buf + offset, msg->L.i);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->L.f , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->cn0 , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->lock);
  // NOLINTNEXTLINE
  offset += 2;
				
        
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
        
  if (offset + 4 > len) { return false; }
  sbp_pack_s32(buf + offset, msg->doppler);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->doppler_std);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->uptime);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_s16(buf + offset, msg->clock_offset);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_s16(buf + offset, msg->clock_drift);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->corr_spacing);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->acceleration , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->sync_flags , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->tow_flags , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->track_flags , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->nav_flags , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->pset_flags , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->misc_flags , 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline bool sbp_unpack_sbp_msg_tracking_state_detailed_dep_t(const u8 *buf, size_t len, sbp_msg_tracking_state_detailed_dep_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
      
  if (offset + 8 > len) { return false; }
  msg->recv_time = sbp_unpack_u64(buf + offset);
  // NOLINTNEXTLINE
  offset += 8;
			
      
  if (offset + 4 > len) { return false; }
  msg->tot.tow = sbp_unpack_u32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 2 > len) { return false; }
  msg->tot.wn = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 4 > len) { return false; }
  msg->P = sbp_unpack_u32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 2 > len) { return false; }
  msg->P_std = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
			
      
  if (offset + 4 > len) { return false; }
  msg->L.i = sbp_unpack_s32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->L.f, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->cn0, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 2 > len) { return false; }
  msg->lock = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
			
      
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
      
  if (offset + 4 > len) { return false; }
  msg->doppler = sbp_unpack_s32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 2 > len) { return false; }
  msg->doppler_std = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 4 > len) { return false; }
  msg->uptime = sbp_unpack_u32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 2 > len) { return false; }
  msg->clock_offset = sbp_unpack_s16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 2 > len) { return false; }
  msg->clock_drift = sbp_unpack_s16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 2 > len) { return false; }
  msg->corr_spacing = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->acceleration, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->sync_flags, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->tow_flags, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->track_flags, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->nav_flags, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->pset_flags, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->misc_flags, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline size_t sbp_packed_size_sbp_tracking_channel_state_t(const sbp_tracking_channel_state_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				(                                                          
	0                                                                          
	  +
				sizeof( msg->sid.sat )                                                                          
	  +
				sizeof( msg->sid.code ) )                                                                          
	  +
				sizeof( msg->fcn )                                                                          
	  +
				sizeof( msg->cn0 );
}

static inline bool sbp_pack_sbp_tracking_channel_state_t(u8 *buf, size_t len, const sbp_tracking_channel_state_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_tracking_channel_state_t(msg) > len) { return false; }
  
				
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->sid.sat , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->sid.code , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->fcn , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->cn0 , 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline bool sbp_unpack_sbp_tracking_channel_state_t(const u8 *buf, size_t len, sbp_tracking_channel_state_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
			
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->sid.sat, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->sid.code, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->fcn, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->cn0, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_tracking_state_t(const sbp_msg_tracking_state_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
	    (
			  msg->n_states
			*
				(                                                          
	0                                                                          
	  +
				(                                                          
	0                                                                          
	  +
				sizeof( msg->states[0].sid.sat )                                                                          
	  +
				sizeof( msg->states[0].sid.code ) )                                                                          
	  +
				sizeof( msg->states[0].fcn )                                                                          
	  +
				sizeof( msg->states[0].cn0 ) )
			);
}

static inline bool sbp_pack_sbp_msg_tracking_state_t(u8 *buf, size_t len, const sbp_msg_tracking_state_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_tracking_state_t(msg) > len) { return false; }
  
			for(size_t msgstates_idx = 0; msgstates_idx < (size_t)msg->n_states; msgstates_idx++)
			{
					
				
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->states[msgstates_idx].sid.sat , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->states[msgstates_idx].sid.code , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->states[msgstates_idx].fcn , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->states[msgstates_idx].cn0 , 1);
  // NOLINTNEXTLINE
  offset += 1;
			}
  return true;
}

static inline bool sbp_unpack_sbp_msg_tracking_state_t(const u8 *buf, size_t len, sbp_msg_tracking_state_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
      msg->n_states = (u8)((len - offset) / 4);

	  for (size_t msgstates_idx = 0; msgstates_idx <
				msg->n_states;
				msgstates_idx++) 
		{
				
			
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->states[msgstates_idx].sid.sat, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->states[msgstates_idx].sid.code, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->states[msgstates_idx].fcn, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->states[msgstates_idx].cn0, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
		}
  return true;
}

static inline size_t sbp_packed_size_sbp_measurement_state_t(const sbp_measurement_state_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				(                                                          
	0                                                                          
	  +
				sizeof( msg->mesid.sat )                                                                          
	  +
				sizeof( msg->mesid.code ) )                                                                          
	  +
				sizeof( msg->cn0 );
}

static inline bool sbp_pack_sbp_measurement_state_t(u8 *buf, size_t len, const sbp_measurement_state_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_measurement_state_t(msg) > len) { return false; }
  
				
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->mesid.sat , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->mesid.code , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->cn0 , 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline bool sbp_unpack_sbp_measurement_state_t(const u8 *buf, size_t len, sbp_measurement_state_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
			
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->mesid.sat, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->mesid.code, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->cn0, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_measurement_state_t(const sbp_msg_measurement_state_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
	    (
			  msg->n_states
			*
				(                                                          
	0                                                                          
	  +
				(                                                          
	0                                                                          
	  +
				sizeof( msg->states[0].mesid.sat )                                                                          
	  +
				sizeof( msg->states[0].mesid.code ) )                                                                          
	  +
				sizeof( msg->states[0].cn0 ) )
			);
}

static inline bool sbp_pack_sbp_msg_measurement_state_t(u8 *buf, size_t len, const sbp_msg_measurement_state_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_measurement_state_t(msg) > len) { return false; }
  
			for(size_t msgstates_idx = 0; msgstates_idx < (size_t)msg->n_states; msgstates_idx++)
			{
					
				
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->states[msgstates_idx].mesid.sat , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->states[msgstates_idx].mesid.code , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->states[msgstates_idx].cn0 , 1);
  // NOLINTNEXTLINE
  offset += 1;
			}
  return true;
}

static inline bool sbp_unpack_sbp_msg_measurement_state_t(const u8 *buf, size_t len, sbp_msg_measurement_state_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
      msg->n_states = (u8)((len - offset) / 3);

	  for (size_t msgstates_idx = 0; msgstates_idx <
				msg->n_states;
				msgstates_idx++) 
		{
				
			
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->states[msgstates_idx].mesid.sat, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->states[msgstates_idx].mesid.code, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->states[msgstates_idx].cn0, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
		}
  return true;
}

static inline size_t sbp_packed_size_sbp_tracking_channel_correlation_t(const sbp_tracking_channel_correlation_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				sizeof( msg->I )                                                                          
	  +
				sizeof( msg->Q );
}

static inline bool sbp_pack_sbp_tracking_channel_correlation_t(u8 *buf, size_t len, const sbp_tracking_channel_correlation_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_tracking_channel_correlation_t(msg) > len) { return false; }
  
        
  if (offset + 2 > len) { return false; }
  sbp_pack_s16(buf + offset, msg->I);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_s16(buf + offset, msg->Q);
  // NOLINTNEXTLINE
  offset += 2;
  return true;
}

static inline bool sbp_unpack_sbp_tracking_channel_correlation_t(const u8 *buf, size_t len, sbp_tracking_channel_correlation_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
      
  if (offset + 2 > len) { return false; }
  msg->I = sbp_unpack_s16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 2 > len) { return false; }
  msg->Q = sbp_unpack_s16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_tracking_iq_t(const sbp_msg_tracking_iq_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				sizeof( msg->channel )                                                                          
	  +
				(                                                          
	0                                                                          
	  +
				sizeof( msg->sid.sat )                                                                          
	  +
				sizeof( msg->sid.code ) )                                                                          
	  +
		  ( 3 *
				(                                                          
	0                                                                          
	  +
				sizeof( msg->corrs[0].I )                                                                          
	  +
				sizeof( msg->corrs[0].Q ) )
		);
}

static inline bool sbp_pack_sbp_msg_tracking_iq_t(u8 *buf, size_t len, const sbp_msg_tracking_iq_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_tracking_iq_t(msg) > len) { return false; }
  
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->channel , 1);
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
		  for(size_t msgcorrs_idx = 0; msgcorrs_idx < 3; msgcorrs_idx++)
			{
				
        
  if (offset + 2 > len) { return false; }
  sbp_pack_s16(buf + offset, msg->corrs[msgcorrs_idx].I);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_s16(buf + offset, msg->corrs[msgcorrs_idx].Q);
  // NOLINTNEXTLINE
  offset += 2;
			}
  return true;
}

static inline bool sbp_unpack_sbp_msg_tracking_iq_t(const u8 *buf, size_t len, sbp_msg_tracking_iq_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->channel, buf + offset, 1);
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
		for (size_t msgcorrs_idx = 0; msgcorrs_idx < 3; msgcorrs_idx++)
		{
				
      
  if (offset + 2 > len) { return false; }
  msg->corrs[msgcorrs_idx].I = sbp_unpack_s16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 2 > len) { return false; }
  msg->corrs[msgcorrs_idx].Q = sbp_unpack_s16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
		}
  return true;
}

static inline size_t sbp_packed_size_sbp_tracking_channel_correlation_dep_t(const sbp_tracking_channel_correlation_dep_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				sizeof( msg->I )                                                                          
	  +
				sizeof( msg->Q );
}

static inline bool sbp_pack_sbp_tracking_channel_correlation_dep_t(u8 *buf, size_t len, const sbp_tracking_channel_correlation_dep_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_tracking_channel_correlation_dep_t(msg) > len) { return false; }
  
        
  if (offset + 4 > len) { return false; }
  sbp_pack_s32(buf + offset, msg->I);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  sbp_pack_s32(buf + offset, msg->Q);
  // NOLINTNEXTLINE
  offset += 4;
  return true;
}

static inline bool sbp_unpack_sbp_tracking_channel_correlation_dep_t(const u8 *buf, size_t len, sbp_tracking_channel_correlation_dep_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
      
  if (offset + 4 > len) { return false; }
  msg->I = sbp_unpack_s32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  msg->Q = sbp_unpack_s32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_tracking_iq_dep_b_t(const sbp_msg_tracking_iq_dep_b_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				sizeof( msg->channel )                                                                          
	  +
				(                                                          
	0                                                                          
	  +
				sizeof( msg->sid.sat )                                                                          
	  +
				sizeof( msg->sid.code ) )                                                                          
	  +
		  ( 3 *
				(                                                          
	0                                                                          
	  +
				sizeof( msg->corrs[0].I )                                                                          
	  +
				sizeof( msg->corrs[0].Q ) )
		);
}

static inline bool sbp_pack_sbp_msg_tracking_iq_dep_b_t(u8 *buf, size_t len, const sbp_msg_tracking_iq_dep_b_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_tracking_iq_dep_b_t(msg) > len) { return false; }
  
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->channel , 1);
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
		  for(size_t msgcorrs_idx = 0; msgcorrs_idx < 3; msgcorrs_idx++)
			{
				
        
  if (offset + 4 > len) { return false; }
  sbp_pack_s32(buf + offset, msg->corrs[msgcorrs_idx].I);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  sbp_pack_s32(buf + offset, msg->corrs[msgcorrs_idx].Q);
  // NOLINTNEXTLINE
  offset += 4;
			}
  return true;
}

static inline bool sbp_unpack_sbp_msg_tracking_iq_dep_b_t(const u8 *buf, size_t len, sbp_msg_tracking_iq_dep_b_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->channel, buf + offset, 1);
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
		for (size_t msgcorrs_idx = 0; msgcorrs_idx < 3; msgcorrs_idx++)
		{
				
      
  if (offset + 4 > len) { return false; }
  msg->corrs[msgcorrs_idx].I = sbp_unpack_s32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  msg->corrs[msgcorrs_idx].Q = sbp_unpack_s32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
		}
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_tracking_iq_dep_a_t(const sbp_msg_tracking_iq_dep_a_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				sizeof( msg->channel )                                                                          
	  +
				(                                                          
	0                                                                          
	  +
				sizeof( msg->sid.sat )                                                                          
	  +
				sizeof( msg->sid.code )                                                                          
	  +
				sizeof( msg->sid.reserved ) )                                                                          
	  +
		  ( 3 *
				(                                                          
	0                                                                          
	  +
				sizeof( msg->corrs[0].I )                                                                          
	  +
				sizeof( msg->corrs[0].Q ) )
		);
}

static inline bool sbp_pack_sbp_msg_tracking_iq_dep_a_t(u8 *buf, size_t len, const sbp_msg_tracking_iq_dep_a_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_tracking_iq_dep_a_t(msg) > len) { return false; }
  
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->channel , 1);
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
		  for(size_t msgcorrs_idx = 0; msgcorrs_idx < 3; msgcorrs_idx++)
			{
				
        
  if (offset + 4 > len) { return false; }
  sbp_pack_s32(buf + offset, msg->corrs[msgcorrs_idx].I);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  sbp_pack_s32(buf + offset, msg->corrs[msgcorrs_idx].Q);
  // NOLINTNEXTLINE
  offset += 4;
			}
  return true;
}

static inline bool sbp_unpack_sbp_msg_tracking_iq_dep_a_t(const u8 *buf, size_t len, sbp_msg_tracking_iq_dep_a_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->channel, buf + offset, 1);
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
		for (size_t msgcorrs_idx = 0; msgcorrs_idx < 3; msgcorrs_idx++)
		{
				
      
  if (offset + 4 > len) { return false; }
  msg->corrs[msgcorrs_idx].I = sbp_unpack_s32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  msg->corrs[msgcorrs_idx].Q = sbp_unpack_s32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
		}
  return true;
}

static inline size_t sbp_packed_size_sbp_tracking_channel_state_dep_a_t(const sbp_tracking_channel_state_dep_a_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				sizeof( msg->state )                                                                          
	  +
				sizeof( msg->prn )                                                                          
	  +
				sizeof( msg->cn0 );
}

static inline bool sbp_pack_sbp_tracking_channel_state_dep_a_t(u8 *buf, size_t len, const sbp_tracking_channel_state_dep_a_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_tracking_channel_state_dep_a_t(msg) > len) { return false; }
  
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->state , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->prn , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 4 > len) { return false; }
  memcpy(buf + offset, & msg->cn0 , 4);
  // NOLINTNEXTLINE
  offset += 4;
  return true;
}

static inline bool sbp_unpack_sbp_tracking_channel_state_dep_a_t(const u8 *buf, size_t len, sbp_tracking_channel_state_dep_a_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->state, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->prn, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->cn0, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_tracking_state_dep_a_t(const sbp_msg_tracking_state_dep_a_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
	    (
			  msg->n_states
			*
				(                                                          
	0                                                                          
	  +
				sizeof( msg->states[0].state )                                                                          
	  +
				sizeof( msg->states[0].prn )                                                                          
	  +
				sizeof( msg->states[0].cn0 ) )
			);
}

static inline bool sbp_pack_sbp_msg_tracking_state_dep_a_t(u8 *buf, size_t len, const sbp_msg_tracking_state_dep_a_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_tracking_state_dep_a_t(msg) > len) { return false; }
  
			for(size_t msgstates_idx = 0; msgstates_idx < (size_t)msg->n_states; msgstates_idx++)
			{
					
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->states[msgstates_idx].state , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->states[msgstates_idx].prn , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 4 > len) { return false; }
  memcpy(buf + offset, & msg->states[msgstates_idx].cn0 , 4);
  // NOLINTNEXTLINE
  offset += 4;
			}
  return true;
}

static inline bool sbp_unpack_sbp_msg_tracking_state_dep_a_t(const u8 *buf, size_t len, sbp_msg_tracking_state_dep_a_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
      msg->n_states = (u8)((len - offset) / 6);

	  for (size_t msgstates_idx = 0; msgstates_idx <
				msg->n_states;
				msgstates_idx++) 
		{
				
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->states[msgstates_idx].state, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->states[msgstates_idx].prn, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->states[msgstates_idx].cn0, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;
		}
  return true;
}

static inline size_t sbp_packed_size_sbp_tracking_channel_state_dep_b_t(const sbp_tracking_channel_state_dep_b_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				sizeof( msg->state )                                                                          
	  +
				(                                                          
	0                                                                          
	  +
				sizeof( msg->sid.sat )                                                                          
	  +
				sizeof( msg->sid.code )                                                                          
	  +
				sizeof( msg->sid.reserved ) )                                                                          
	  +
				sizeof( msg->cn0 );
}

static inline bool sbp_pack_sbp_tracking_channel_state_dep_b_t(u8 *buf, size_t len, const sbp_tracking_channel_state_dep_b_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_tracking_channel_state_dep_b_t(msg) > len) { return false; }
  
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->state , 1);
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
        
  if (offset + 4 > len) { return false; }
  memcpy(buf + offset, & msg->cn0 , 4);
  // NOLINTNEXTLINE
  offset += 4;
  return true;
}

static inline bool sbp_unpack_sbp_tracking_channel_state_dep_b_t(const u8 *buf, size_t len, sbp_tracking_channel_state_dep_b_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->state, buf + offset, 1);
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
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->cn0, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_tracking_state_dep_b_t(const sbp_msg_tracking_state_dep_b_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
	    (
			  msg->n_states
			*
				(                                                          
	0                                                                          
	  +
				sizeof( msg->states[0].state )                                                                          
	  +
				(                                                          
	0                                                                          
	  +
				sizeof( msg->states[0].sid.sat )                                                                          
	  +
				sizeof( msg->states[0].sid.code )                                                                          
	  +
				sizeof( msg->states[0].sid.reserved ) )                                                                          
	  +
				sizeof( msg->states[0].cn0 ) )
			);
}

static inline bool sbp_pack_sbp_msg_tracking_state_dep_b_t(u8 *buf, size_t len, const sbp_msg_tracking_state_dep_b_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_tracking_state_dep_b_t(msg) > len) { return false; }
  
			for(size_t msgstates_idx = 0; msgstates_idx < (size_t)msg->n_states; msgstates_idx++)
			{
					
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->states[msgstates_idx].state , 1);
  // NOLINTNEXTLINE
  offset += 1;
				
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->states[msgstates_idx].sid.sat);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->states[msgstates_idx].sid.code , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->states[msgstates_idx].sid.reserved , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 4 > len) { return false; }
  memcpy(buf + offset, & msg->states[msgstates_idx].cn0 , 4);
  // NOLINTNEXTLINE
  offset += 4;
			}
  return true;
}

static inline bool sbp_unpack_sbp_msg_tracking_state_dep_b_t(const u8 *buf, size_t len, sbp_msg_tracking_state_dep_b_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
      msg->n_states = (u8)((len - offset) / 9);

	  for (size_t msgstates_idx = 0; msgstates_idx <
				msg->n_states;
				msgstates_idx++) 
		{
				
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->states[msgstates_idx].state, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
			
      
  if (offset + 2 > len) { return false; }
  msg->states[msgstates_idx].sid.sat = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->states[msgstates_idx].sid.code, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->states[msgstates_idx].sid.reserved, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->states[msgstates_idx].cn0, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;
		}
  return true;
}

#endif
