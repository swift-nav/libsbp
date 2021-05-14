#ifndef LIBSBP_OBSERVATION_PACKERS_H
#define LIBSBP_OBSERVATION_PACKERS_H

#ifndef LIBSBP_OBSERVATION_MESSAGES_H
#error "Do not include this file directly, include libsbp/unpacked/observation.h instead"
#endif

#include <stdbool.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>
#include <math.h>

#include <libsbp/common.h>
#include <libsbp/string.h>

static inline size_t sbp_packed_size_sbp_observation_header_t(const sbp_observation_header_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
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
				sizeof( msg->n_obs );
}

static inline bool sbp_pack_sbp_observation_header_t(u8 *buf, size_t len, const sbp_observation_header_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_observation_header_t(msg) > len) { return false; }
  
				
        
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
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->n_obs , 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline bool sbp_unpack_sbp_observation_header_t(const u8 *buf, size_t len, sbp_observation_header_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
			
      
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
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->n_obs, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline size_t sbp_packed_size_sbp_doppler_t(const sbp_doppler_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				sizeof( msg->i )                                                                          
	  +
				sizeof( msg->f );
}

static inline bool sbp_pack_sbp_doppler_t(u8 *buf, size_t len, const sbp_doppler_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_doppler_t(msg) > len) { return false; }
  
        
  if (offset + 2 > len) { return false; }
  sbp_pack_s16(buf + offset, msg->i);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->f , 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline bool sbp_unpack_sbp_doppler_t(const u8 *buf, size_t len, sbp_doppler_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
      
  if (offset + 2 > len) { return false; }
  msg->i = sbp_unpack_s16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->f, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline size_t sbp_packed_size_sbp_packed_obs_content_t(const sbp_packed_obs_content_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				sizeof( msg->P )                                                                          
	  +
				(                                                          
	0                                                                          
	  +
				sizeof( msg->L.i )                                                                          
	  +
				sizeof( msg->L.f ) )                                                                          
	  +
				(                                                          
	0                                                                          
	  +
				sizeof( msg->D.i )                                                                          
	  +
				sizeof( msg->D.f ) )                                                                          
	  +
				sizeof( msg->cn0 )                                                                          
	  +
				sizeof( msg->lock )                                                                          
	  +
				sizeof( msg->flags )                                                                          
	  +
				(                                                          
	0                                                                          
	  +
				sizeof( msg->sid.sat )                                                                          
	  +
				sizeof( msg->sid.code ) );
}

static inline bool sbp_pack_sbp_packed_obs_content_t(u8 *buf, size_t len, const sbp_packed_obs_content_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_packed_obs_content_t(msg) > len) { return false; }
  
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->P);
  // NOLINTNEXTLINE
  offset += 4;
				
        
  if (offset + 4 > len) { return false; }
  sbp_pack_s32(buf + offset, msg->L.i);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->L.f , 1);
  // NOLINTNEXTLINE
  offset += 1;
				
        
  if (offset + 2 > len) { return false; }
  sbp_pack_s16(buf + offset, msg->D.i);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->D.f , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->cn0 , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->lock , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->flags , 1);
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

static inline bool sbp_unpack_sbp_packed_obs_content_t(const u8 *buf, size_t len, sbp_packed_obs_content_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
      
  if (offset + 4 > len) { return false; }
  msg->P = sbp_unpack_u32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
			
      
  if (offset + 4 > len) { return false; }
  msg->L.i = sbp_unpack_s32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->L.f, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
			
      
  if (offset + 2 > len) { return false; }
  msg->D.i = sbp_unpack_s16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->D.f, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->cn0, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->lock, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->flags, buf + offset, 1);
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

static inline size_t sbp_packed_size_sbp_packed_osr_content_t(const sbp_packed_osr_content_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				sizeof( msg->P )                                                                          
	  +
				(                                                          
	0                                                                          
	  +
				sizeof( msg->L.i )                                                                          
	  +
				sizeof( msg->L.f ) )                                                                          
	  +
				sizeof( msg->lock )                                                                          
	  +
				sizeof( msg->flags )                                                                          
	  +
				(                                                          
	0                                                                          
	  +
				sizeof( msg->sid.sat )                                                                          
	  +
				sizeof( msg->sid.code ) )                                                                          
	  +
				sizeof( msg->iono_std )                                                                          
	  +
				sizeof( msg->tropo_std )                                                                          
	  +
				sizeof( msg->range_std );
}

static inline bool sbp_pack_sbp_packed_osr_content_t(u8 *buf, size_t len, const sbp_packed_osr_content_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_packed_osr_content_t(msg) > len) { return false; }
  
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->P);
  // NOLINTNEXTLINE
  offset += 4;
				
        
  if (offset + 4 > len) { return false; }
  sbp_pack_s32(buf + offset, msg->L.i);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->L.f , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->lock , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->flags , 1);
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
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->iono_std);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->tropo_std);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->range_std);
  // NOLINTNEXTLINE
  offset += 2;
  return true;
}

static inline bool sbp_unpack_sbp_packed_osr_content_t(const u8 *buf, size_t len, sbp_packed_osr_content_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
      
  if (offset + 4 > len) { return false; }
  msg->P = sbp_unpack_u32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
			
      
  if (offset + 4 > len) { return false; }
  msg->L.i = sbp_unpack_s32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->L.f, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->lock, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->flags, buf + offset, 1);
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
      
  if (offset + 2 > len) { return false; }
  msg->iono_std = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 2 > len) { return false; }
  msg->tropo_std = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 2 > len) { return false; }
  msg->range_std = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_obs_t(const sbp_msg_obs_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				(                                                          
	0                                                                          
	  +
				(                                                          
	0                                                                          
	  +
				sizeof( msg->header.t.tow )                                                                          
	  +
				sizeof( msg->header.t.ns_residual )                                                                          
	  +
				sizeof( msg->header.t.wn ) )                                                                          
	  +
				sizeof( msg->header.n_obs ) )                                                                          
	  +
	    (
			  msg->n_obs
			*
				(                                                          
	0                                                                          
	  +
				sizeof( msg->obs[0].P )                                                                          
	  +
				(                                                          
	0                                                                          
	  +
				sizeof( msg->obs[0].L.i )                                                                          
	  +
				sizeof( msg->obs[0].L.f ) )                                                                          
	  +
				(                                                          
	0                                                                          
	  +
				sizeof( msg->obs[0].D.i )                                                                          
	  +
				sizeof( msg->obs[0].D.f ) )                                                                          
	  +
				sizeof( msg->obs[0].cn0 )                                                                          
	  +
				sizeof( msg->obs[0].lock )                                                                          
	  +
				sizeof( msg->obs[0].flags )                                                                          
	  +
				(                                                          
	0                                                                          
	  +
				sizeof( msg->obs[0].sid.sat )                                                                          
	  +
				sizeof( msg->obs[0].sid.code ) ) )
			);
}

static inline bool sbp_pack_sbp_msg_obs_t(u8 *buf, size_t len, const sbp_msg_obs_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_obs_t(msg) > len) { return false; }
  
				
				
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->header.t.tow);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  sbp_pack_s32(buf + offset, msg->header.t.ns_residual);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->header.t.wn);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->header.n_obs , 1);
  // NOLINTNEXTLINE
  offset += 1;
			for(size_t msgobs_idx = 0; msgobs_idx < (size_t)msg->n_obs; msgobs_idx++)
			{
					
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->obs[msgobs_idx].P);
  // NOLINTNEXTLINE
  offset += 4;
				
        
  if (offset + 4 > len) { return false; }
  sbp_pack_s32(buf + offset, msg->obs[msgobs_idx].L.i);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->obs[msgobs_idx].L.f , 1);
  // NOLINTNEXTLINE
  offset += 1;
				
        
  if (offset + 2 > len) { return false; }
  sbp_pack_s16(buf + offset, msg->obs[msgobs_idx].D.i);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->obs[msgobs_idx].D.f , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->obs[msgobs_idx].cn0 , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->obs[msgobs_idx].lock , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->obs[msgobs_idx].flags , 1);
  // NOLINTNEXTLINE
  offset += 1;
				
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->obs[msgobs_idx].sid.sat , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->obs[msgobs_idx].sid.code , 1);
  // NOLINTNEXTLINE
  offset += 1;
			}
  return true;
}

static inline bool sbp_unpack_sbp_msg_obs_t(const u8 *buf, size_t len, sbp_msg_obs_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
			
			
      
  if (offset + 4 > len) { return false; }
  msg->header.t.tow = sbp_unpack_u32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  msg->header.t.ns_residual = sbp_unpack_s32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 2 > len) { return false; }
  msg->header.t.wn = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->header.n_obs, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      msg->n_obs = (u8)((len - offset) / 17);

	  for (size_t msgobs_idx = 0; msgobs_idx <
				msg->n_obs;
				msgobs_idx++) 
		{
				
      
  if (offset + 4 > len) { return false; }
  msg->obs[msgobs_idx].P = sbp_unpack_u32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
			
      
  if (offset + 4 > len) { return false; }
  msg->obs[msgobs_idx].L.i = sbp_unpack_s32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->obs[msgobs_idx].L.f, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
			
      
  if (offset + 2 > len) { return false; }
  msg->obs[msgobs_idx].D.i = sbp_unpack_s16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->obs[msgobs_idx].D.f, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->obs[msgobs_idx].cn0, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->obs[msgobs_idx].lock, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->obs[msgobs_idx].flags, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
			
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->obs[msgobs_idx].sid.sat, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->obs[msgobs_idx].sid.code, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
		}
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_base_pos_llh_t(const sbp_msg_base_pos_llh_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				sizeof( msg->lat )                                                                          
	  +
				sizeof( msg->lon )                                                                          
	  +
				sizeof( msg->height );
}

static inline bool sbp_pack_sbp_msg_base_pos_llh_t(u8 *buf, size_t len, const sbp_msg_base_pos_llh_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_base_pos_llh_t(msg) > len) { return false; }
  
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->lat , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->lon , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->height , 8);
  // NOLINTNEXTLINE
  offset += 8;
  return true;
}

static inline bool sbp_unpack_sbp_msg_base_pos_llh_t(const u8 *buf, size_t len, sbp_msg_base_pos_llh_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->lat, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->lon, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->height, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_base_pos_ecef_t(const sbp_msg_base_pos_ecef_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				sizeof( msg->x )                                                                          
	  +
				sizeof( msg->y )                                                                          
	  +
				sizeof( msg->z );
}

static inline bool sbp_pack_sbp_msg_base_pos_ecef_t(u8 *buf, size_t len, const sbp_msg_base_pos_ecef_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_base_pos_ecef_t(msg) > len) { return false; }
  
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->x , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->y , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->z , 8);
  // NOLINTNEXTLINE
  offset += 8;
  return true;
}

static inline bool sbp_unpack_sbp_msg_base_pos_ecef_t(const u8 *buf, size_t len, sbp_msg_base_pos_ecef_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->x, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->y, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->z, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
  return true;
}

static inline size_t sbp_packed_size_sbp_ephemeris_common_content_t(const sbp_ephemeris_common_content_t *msg) {                                
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
				(                                                          
	0                                                                          
	  +
				sizeof( msg->toe.tow )                                                                          
	  +
				sizeof( msg->toe.wn ) )                                                                          
	  +
				sizeof( msg->ura )                                                                          
	  +
				sizeof( msg->fit_interval )                                                                          
	  +
				sizeof( msg->valid )                                                                          
	  +
				sizeof( msg->health_bits );
}

static inline bool sbp_pack_sbp_ephemeris_common_content_t(u8 *buf, size_t len, const sbp_ephemeris_common_content_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_ephemeris_common_content_t(msg) > len) { return false; }
  
				
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->sid.sat , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->sid.code , 1);
  // NOLINTNEXTLINE
  offset += 1;
				
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->toe.tow);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->toe.wn);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 4 > len) { return false; }
  memcpy(buf + offset, & msg->ura , 4);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->fit_interval);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->valid , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->health_bits , 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline bool sbp_unpack_sbp_ephemeris_common_content_t(const u8 *buf, size_t len, sbp_ephemeris_common_content_t *msg) {
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
			
      
  if (offset + 4 > len) { return false; }
  msg->toe.tow = sbp_unpack_u32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 2 > len) { return false; }
  msg->toe.wn = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->ura, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  msg->fit_interval = sbp_unpack_u32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->valid, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->health_bits, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline size_t sbp_packed_size_sbp_ephemeris_common_content_dep_b_t(const sbp_ephemeris_common_content_dep_b_t *msg) {                                
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
				(                                                          
	0                                                                          
	  +
				sizeof( msg->toe.tow )                                                                          
	  +
				sizeof( msg->toe.wn ) )                                                                          
	  +
				sizeof( msg->ura )                                                                          
	  +
				sizeof( msg->fit_interval )                                                                          
	  +
				sizeof( msg->valid )                                                                          
	  +
				sizeof( msg->health_bits );
}

static inline bool sbp_pack_sbp_ephemeris_common_content_dep_b_t(u8 *buf, size_t len, const sbp_ephemeris_common_content_dep_b_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_ephemeris_common_content_dep_b_t(msg) > len) { return false; }
  
				
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->sid.sat , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->sid.code , 1);
  // NOLINTNEXTLINE
  offset += 1;
				
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->toe.tow);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->toe.wn);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->ura , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->fit_interval);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->valid , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->health_bits , 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline bool sbp_unpack_sbp_ephemeris_common_content_dep_b_t(const u8 *buf, size_t len, sbp_ephemeris_common_content_dep_b_t *msg) {
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
			
      
  if (offset + 4 > len) { return false; }
  msg->toe.tow = sbp_unpack_u32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 2 > len) { return false; }
  msg->toe.wn = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->ura, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 4 > len) { return false; }
  msg->fit_interval = sbp_unpack_u32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->valid, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->health_bits, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline size_t sbp_packed_size_sbp_ephemeris_common_content_dep_a_t(const sbp_ephemeris_common_content_dep_a_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
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
				(                                                          
	0                                                                          
	  +
				sizeof( msg->toe.tow )                                                                          
	  +
				sizeof( msg->toe.wn ) )                                                                          
	  +
				sizeof( msg->ura )                                                                          
	  +
				sizeof( msg->fit_interval )                                                                          
	  +
				sizeof( msg->valid )                                                                          
	  +
				sizeof( msg->health_bits );
}

static inline bool sbp_pack_sbp_ephemeris_common_content_dep_a_t(u8 *buf, size_t len, const sbp_ephemeris_common_content_dep_a_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_ephemeris_common_content_dep_a_t(msg) > len) { return false; }
  
				
        
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
  sbp_pack_u32(buf + offset, msg->toe.tow);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->toe.wn);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->ura , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->fit_interval);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->valid , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->health_bits , 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline bool sbp_unpack_sbp_ephemeris_common_content_dep_a_t(const u8 *buf, size_t len, sbp_ephemeris_common_content_dep_a_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
			
      
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
  msg->toe.tow = sbp_unpack_u32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 2 > len) { return false; }
  msg->toe.wn = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->ura, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 4 > len) { return false; }
  msg->fit_interval = sbp_unpack_u32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->valid, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->health_bits, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_ephemeris_gps_dep_e_t(const sbp_msg_ephemeris_gps_dep_e_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				(                                                          
	0                                                                          
	  +
				(                                                          
	0                                                                          
	  +
				sizeof( msg->common.sid.sat )                                                                          
	  +
				sizeof( msg->common.sid.code )                                                                          
	  +
				sizeof( msg->common.sid.reserved ) )                                                                          
	  +
				(                                                          
	0                                                                          
	  +
				sizeof( msg->common.toe.tow )                                                                          
	  +
				sizeof( msg->common.toe.wn ) )                                                                          
	  +
				sizeof( msg->common.ura )                                                                          
	  +
				sizeof( msg->common.fit_interval )                                                                          
	  +
				sizeof( msg->common.valid )                                                                          
	  +
				sizeof( msg->common.health_bits ) )                                                                          
	  +
				sizeof( msg->tgd )                                                                          
	  +
				sizeof( msg->c_rs )                                                                          
	  +
				sizeof( msg->c_rc )                                                                          
	  +
				sizeof( msg->c_uc )                                                                          
	  +
				sizeof( msg->c_us )                                                                          
	  +
				sizeof( msg->c_ic )                                                                          
	  +
				sizeof( msg->c_is )                                                                          
	  +
				sizeof( msg->dn )                                                                          
	  +
				sizeof( msg->m0 )                                                                          
	  +
				sizeof( msg->ecc )                                                                          
	  +
				sizeof( msg->sqrta )                                                                          
	  +
				sizeof( msg->omega0 )                                                                          
	  +
				sizeof( msg->omegadot )                                                                          
	  +
				sizeof( msg->w )                                                                          
	  +
				sizeof( msg->inc )                                                                          
	  +
				sizeof( msg->inc_dot )                                                                          
	  +
				sizeof( msg->af0 )                                                                          
	  +
				sizeof( msg->af1 )                                                                          
	  +
				sizeof( msg->af2 )                                                                          
	  +
				(                                                          
	0                                                                          
	  +
				sizeof( msg->toc.tow )                                                                          
	  +
				sizeof( msg->toc.wn ) )                                                                          
	  +
				sizeof( msg->iode )                                                                          
	  +
				sizeof( msg->iodc );
}

static inline bool sbp_pack_sbp_msg_ephemeris_gps_dep_e_t(u8 *buf, size_t len, const sbp_msg_ephemeris_gps_dep_e_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_ephemeris_gps_dep_e_t(msg) > len) { return false; }
  
				
				
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->common.sid.sat);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->common.sid.code , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->common.sid.reserved , 1);
  // NOLINTNEXTLINE
  offset += 1;
				
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->common.toe.tow);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->common.toe.wn);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->common.ura , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->common.fit_interval);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->common.valid , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->common.health_bits , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->tgd , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->c_rs , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->c_rc , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->c_uc , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->c_us , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->c_ic , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->c_is , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->dn , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->m0 , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->ecc , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->sqrta , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->omega0 , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->omegadot , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->w , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->inc , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->inc_dot , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->af0 , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->af1 , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->af2 , 8);
  // NOLINTNEXTLINE
  offset += 8;
				
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->toc.tow);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->toc.wn);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->iode , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->iodc);
  // NOLINTNEXTLINE
  offset += 2;
  return true;
}

static inline bool sbp_unpack_sbp_msg_ephemeris_gps_dep_e_t(const u8 *buf, size_t len, sbp_msg_ephemeris_gps_dep_e_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
			
			
      
  if (offset + 2 > len) { return false; }
  msg->common.sid.sat = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->common.sid.code, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->common.sid.reserved, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
			
      
  if (offset + 4 > len) { return false; }
  msg->common.toe.tow = sbp_unpack_u32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 2 > len) { return false; }
  msg->common.toe.wn = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->common.ura, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 4 > len) { return false; }
  msg->common.fit_interval = sbp_unpack_u32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->common.valid, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->common.health_bits, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->tgd, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->c_rs, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->c_rc, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->c_uc, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->c_us, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->c_ic, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->c_is, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->dn, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->m0, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->ecc, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->sqrta, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->omega0, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->omegadot, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->w, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->inc, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->inc_dot, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->af0, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->af1, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->af2, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
			
      
  if (offset + 4 > len) { return false; }
  msg->toc.tow = sbp_unpack_u32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 2 > len) { return false; }
  msg->toc.wn = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->iode, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 2 > len) { return false; }
  msg->iodc = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_ephemeris_gps_dep_f_t(const sbp_msg_ephemeris_gps_dep_f_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				(                                                          
	0                                                                          
	  +
				(                                                          
	0                                                                          
	  +
				sizeof( msg->common.sid.sat )                                                                          
	  +
				sizeof( msg->common.sid.code ) )                                                                          
	  +
				(                                                          
	0                                                                          
	  +
				sizeof( msg->common.toe.tow )                                                                          
	  +
				sizeof( msg->common.toe.wn ) )                                                                          
	  +
				sizeof( msg->common.ura )                                                                          
	  +
				sizeof( msg->common.fit_interval )                                                                          
	  +
				sizeof( msg->common.valid )                                                                          
	  +
				sizeof( msg->common.health_bits ) )                                                                          
	  +
				sizeof( msg->tgd )                                                                          
	  +
				sizeof( msg->c_rs )                                                                          
	  +
				sizeof( msg->c_rc )                                                                          
	  +
				sizeof( msg->c_uc )                                                                          
	  +
				sizeof( msg->c_us )                                                                          
	  +
				sizeof( msg->c_ic )                                                                          
	  +
				sizeof( msg->c_is )                                                                          
	  +
				sizeof( msg->dn )                                                                          
	  +
				sizeof( msg->m0 )                                                                          
	  +
				sizeof( msg->ecc )                                                                          
	  +
				sizeof( msg->sqrta )                                                                          
	  +
				sizeof( msg->omega0 )                                                                          
	  +
				sizeof( msg->omegadot )                                                                          
	  +
				sizeof( msg->w )                                                                          
	  +
				sizeof( msg->inc )                                                                          
	  +
				sizeof( msg->inc_dot )                                                                          
	  +
				sizeof( msg->af0 )                                                                          
	  +
				sizeof( msg->af1 )                                                                          
	  +
				sizeof( msg->af2 )                                                                          
	  +
				(                                                          
	0                                                                          
	  +
				sizeof( msg->toc.tow )                                                                          
	  +
				sizeof( msg->toc.wn ) )                                                                          
	  +
				sizeof( msg->iode )                                                                          
	  +
				sizeof( msg->iodc );
}

static inline bool sbp_pack_sbp_msg_ephemeris_gps_dep_f_t(u8 *buf, size_t len, const sbp_msg_ephemeris_gps_dep_f_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_ephemeris_gps_dep_f_t(msg) > len) { return false; }
  
				
				
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->common.sid.sat , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->common.sid.code , 1);
  // NOLINTNEXTLINE
  offset += 1;
				
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->common.toe.tow);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->common.toe.wn);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->common.ura , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->common.fit_interval);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->common.valid , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->common.health_bits , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->tgd , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->c_rs , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->c_rc , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->c_uc , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->c_us , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->c_ic , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->c_is , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->dn , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->m0 , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->ecc , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->sqrta , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->omega0 , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->omegadot , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->w , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->inc , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->inc_dot , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->af0 , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->af1 , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->af2 , 8);
  // NOLINTNEXTLINE
  offset += 8;
				
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->toc.tow);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->toc.wn);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->iode , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->iodc);
  // NOLINTNEXTLINE
  offset += 2;
  return true;
}

static inline bool sbp_unpack_sbp_msg_ephemeris_gps_dep_f_t(const u8 *buf, size_t len, sbp_msg_ephemeris_gps_dep_f_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
			
			
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->common.sid.sat, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->common.sid.code, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
			
      
  if (offset + 4 > len) { return false; }
  msg->common.toe.tow = sbp_unpack_u32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 2 > len) { return false; }
  msg->common.toe.wn = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->common.ura, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 4 > len) { return false; }
  msg->common.fit_interval = sbp_unpack_u32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->common.valid, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->common.health_bits, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->tgd, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->c_rs, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->c_rc, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->c_uc, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->c_us, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->c_ic, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->c_is, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->dn, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->m0, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->ecc, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->sqrta, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->omega0, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->omegadot, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->w, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->inc, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->inc_dot, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->af0, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->af1, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->af2, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
			
      
  if (offset + 4 > len) { return false; }
  msg->toc.tow = sbp_unpack_u32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 2 > len) { return false; }
  msg->toc.wn = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->iode, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 2 > len) { return false; }
  msg->iodc = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_ephemeris_gps_t(const sbp_msg_ephemeris_gps_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				(                                                          
	0                                                                          
	  +
				(                                                          
	0                                                                          
	  +
				sizeof( msg->common.sid.sat )                                                                          
	  +
				sizeof( msg->common.sid.code ) )                                                                          
	  +
				(                                                          
	0                                                                          
	  +
				sizeof( msg->common.toe.tow )                                                                          
	  +
				sizeof( msg->common.toe.wn ) )                                                                          
	  +
				sizeof( msg->common.ura )                                                                          
	  +
				sizeof( msg->common.fit_interval )                                                                          
	  +
				sizeof( msg->common.valid )                                                                          
	  +
				sizeof( msg->common.health_bits ) )                                                                          
	  +
				sizeof( msg->tgd )                                                                          
	  +
				sizeof( msg->c_rs )                                                                          
	  +
				sizeof( msg->c_rc )                                                                          
	  +
				sizeof( msg->c_uc )                                                                          
	  +
				sizeof( msg->c_us )                                                                          
	  +
				sizeof( msg->c_ic )                                                                          
	  +
				sizeof( msg->c_is )                                                                          
	  +
				sizeof( msg->dn )                                                                          
	  +
				sizeof( msg->m0 )                                                                          
	  +
				sizeof( msg->ecc )                                                                          
	  +
				sizeof( msg->sqrta )                                                                          
	  +
				sizeof( msg->omega0 )                                                                          
	  +
				sizeof( msg->omegadot )                                                                          
	  +
				sizeof( msg->w )                                                                          
	  +
				sizeof( msg->inc )                                                                          
	  +
				sizeof( msg->inc_dot )                                                                          
	  +
				sizeof( msg->af0 )                                                                          
	  +
				sizeof( msg->af1 )                                                                          
	  +
				sizeof( msg->af2 )                                                                          
	  +
				(                                                          
	0                                                                          
	  +
				sizeof( msg->toc.tow )                                                                          
	  +
				sizeof( msg->toc.wn ) )                                                                          
	  +
				sizeof( msg->iode )                                                                          
	  +
				sizeof( msg->iodc );
}

static inline bool sbp_pack_sbp_msg_ephemeris_gps_t(u8 *buf, size_t len, const sbp_msg_ephemeris_gps_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_ephemeris_gps_t(msg) > len) { return false; }
  
				
				
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->common.sid.sat , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->common.sid.code , 1);
  // NOLINTNEXTLINE
  offset += 1;
				
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->common.toe.tow);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->common.toe.wn);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 4 > len) { return false; }
  memcpy(buf + offset, & msg->common.ura , 4);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->common.fit_interval);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->common.valid , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->common.health_bits , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 4 > len) { return false; }
  memcpy(buf + offset, & msg->tgd , 4);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  memcpy(buf + offset, & msg->c_rs , 4);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  memcpy(buf + offset, & msg->c_rc , 4);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  memcpy(buf + offset, & msg->c_uc , 4);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  memcpy(buf + offset, & msg->c_us , 4);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  memcpy(buf + offset, & msg->c_ic , 4);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  memcpy(buf + offset, & msg->c_is , 4);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->dn , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->m0 , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->ecc , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->sqrta , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->omega0 , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->omegadot , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->w , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->inc , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->inc_dot , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 4 > len) { return false; }
  memcpy(buf + offset, & msg->af0 , 4);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  memcpy(buf + offset, & msg->af1 , 4);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  memcpy(buf + offset, & msg->af2 , 4);
  // NOLINTNEXTLINE
  offset += 4;
				
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->toc.tow);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->toc.wn);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->iode , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->iodc);
  // NOLINTNEXTLINE
  offset += 2;
  return true;
}

static inline bool sbp_unpack_sbp_msg_ephemeris_gps_t(const u8 *buf, size_t len, sbp_msg_ephemeris_gps_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
			
			
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->common.sid.sat, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->common.sid.code, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
			
      
  if (offset + 4 > len) { return false; }
  msg->common.toe.tow = sbp_unpack_u32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 2 > len) { return false; }
  msg->common.toe.wn = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->common.ura, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  msg->common.fit_interval = sbp_unpack_u32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->common.valid, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->common.health_bits, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->tgd, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->c_rs, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->c_rc, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->c_uc, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->c_us, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->c_ic, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->c_is, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->dn, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->m0, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->ecc, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->sqrta, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->omega0, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->omegadot, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->w, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->inc, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->inc_dot, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->af0, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->af1, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->af2, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;
			
      
  if (offset + 4 > len) { return false; }
  msg->toc.tow = sbp_unpack_u32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 2 > len) { return false; }
  msg->toc.wn = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->iode, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 2 > len) { return false; }
  msg->iodc = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_ephemeris_qzss_t(const sbp_msg_ephemeris_qzss_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				(                                                          
	0                                                                          
	  +
				(                                                          
	0                                                                          
	  +
				sizeof( msg->common.sid.sat )                                                                          
	  +
				sizeof( msg->common.sid.code ) )                                                                          
	  +
				(                                                          
	0                                                                          
	  +
				sizeof( msg->common.toe.tow )                                                                          
	  +
				sizeof( msg->common.toe.wn ) )                                                                          
	  +
				sizeof( msg->common.ura )                                                                          
	  +
				sizeof( msg->common.fit_interval )                                                                          
	  +
				sizeof( msg->common.valid )                                                                          
	  +
				sizeof( msg->common.health_bits ) )                                                                          
	  +
				sizeof( msg->tgd )                                                                          
	  +
				sizeof( msg->c_rs )                                                                          
	  +
				sizeof( msg->c_rc )                                                                          
	  +
				sizeof( msg->c_uc )                                                                          
	  +
				sizeof( msg->c_us )                                                                          
	  +
				sizeof( msg->c_ic )                                                                          
	  +
				sizeof( msg->c_is )                                                                          
	  +
				sizeof( msg->dn )                                                                          
	  +
				sizeof( msg->m0 )                                                                          
	  +
				sizeof( msg->ecc )                                                                          
	  +
				sizeof( msg->sqrta )                                                                          
	  +
				sizeof( msg->omega0 )                                                                          
	  +
				sizeof( msg->omegadot )                                                                          
	  +
				sizeof( msg->w )                                                                          
	  +
				sizeof( msg->inc )                                                                          
	  +
				sizeof( msg->inc_dot )                                                                          
	  +
				sizeof( msg->af0 )                                                                          
	  +
				sizeof( msg->af1 )                                                                          
	  +
				sizeof( msg->af2 )                                                                          
	  +
				(                                                          
	0                                                                          
	  +
				sizeof( msg->toc.tow )                                                                          
	  +
				sizeof( msg->toc.wn ) )                                                                          
	  +
				sizeof( msg->iode )                                                                          
	  +
				sizeof( msg->iodc );
}

static inline bool sbp_pack_sbp_msg_ephemeris_qzss_t(u8 *buf, size_t len, const sbp_msg_ephemeris_qzss_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_ephemeris_qzss_t(msg) > len) { return false; }
  
				
				
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->common.sid.sat , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->common.sid.code , 1);
  // NOLINTNEXTLINE
  offset += 1;
				
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->common.toe.tow);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->common.toe.wn);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 4 > len) { return false; }
  memcpy(buf + offset, & msg->common.ura , 4);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->common.fit_interval);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->common.valid , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->common.health_bits , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 4 > len) { return false; }
  memcpy(buf + offset, & msg->tgd , 4);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  memcpy(buf + offset, & msg->c_rs , 4);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  memcpy(buf + offset, & msg->c_rc , 4);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  memcpy(buf + offset, & msg->c_uc , 4);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  memcpy(buf + offset, & msg->c_us , 4);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  memcpy(buf + offset, & msg->c_ic , 4);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  memcpy(buf + offset, & msg->c_is , 4);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->dn , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->m0 , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->ecc , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->sqrta , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->omega0 , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->omegadot , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->w , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->inc , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->inc_dot , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 4 > len) { return false; }
  memcpy(buf + offset, & msg->af0 , 4);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  memcpy(buf + offset, & msg->af1 , 4);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  memcpy(buf + offset, & msg->af2 , 4);
  // NOLINTNEXTLINE
  offset += 4;
				
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->toc.tow);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->toc.wn);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->iode , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->iodc);
  // NOLINTNEXTLINE
  offset += 2;
  return true;
}

static inline bool sbp_unpack_sbp_msg_ephemeris_qzss_t(const u8 *buf, size_t len, sbp_msg_ephemeris_qzss_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
			
			
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->common.sid.sat, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->common.sid.code, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
			
      
  if (offset + 4 > len) { return false; }
  msg->common.toe.tow = sbp_unpack_u32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 2 > len) { return false; }
  msg->common.toe.wn = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->common.ura, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  msg->common.fit_interval = sbp_unpack_u32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->common.valid, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->common.health_bits, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->tgd, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->c_rs, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->c_rc, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->c_uc, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->c_us, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->c_ic, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->c_is, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->dn, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->m0, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->ecc, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->sqrta, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->omega0, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->omegadot, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->w, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->inc, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->inc_dot, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->af0, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->af1, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->af2, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;
			
      
  if (offset + 4 > len) { return false; }
  msg->toc.tow = sbp_unpack_u32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 2 > len) { return false; }
  msg->toc.wn = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->iode, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 2 > len) { return false; }
  msg->iodc = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_ephemeris_bds_t(const sbp_msg_ephemeris_bds_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				(                                                          
	0                                                                          
	  +
				(                                                          
	0                                                                          
	  +
				sizeof( msg->common.sid.sat )                                                                          
	  +
				sizeof( msg->common.sid.code ) )                                                                          
	  +
				(                                                          
	0                                                                          
	  +
				sizeof( msg->common.toe.tow )                                                                          
	  +
				sizeof( msg->common.toe.wn ) )                                                                          
	  +
				sizeof( msg->common.ura )                                                                          
	  +
				sizeof( msg->common.fit_interval )                                                                          
	  +
				sizeof( msg->common.valid )                                                                          
	  +
				sizeof( msg->common.health_bits ) )                                                                          
	  +
				sizeof( msg->tgd1 )                                                                          
	  +
				sizeof( msg->tgd2 )                                                                          
	  +
				sizeof( msg->c_rs )                                                                          
	  +
				sizeof( msg->c_rc )                                                                          
	  +
				sizeof( msg->c_uc )                                                                          
	  +
				sizeof( msg->c_us )                                                                          
	  +
				sizeof( msg->c_ic )                                                                          
	  +
				sizeof( msg->c_is )                                                                          
	  +
				sizeof( msg->dn )                                                                          
	  +
				sizeof( msg->m0 )                                                                          
	  +
				sizeof( msg->ecc )                                                                          
	  +
				sizeof( msg->sqrta )                                                                          
	  +
				sizeof( msg->omega0 )                                                                          
	  +
				sizeof( msg->omegadot )                                                                          
	  +
				sizeof( msg->w )                                                                          
	  +
				sizeof( msg->inc )                                                                          
	  +
				sizeof( msg->inc_dot )                                                                          
	  +
				sizeof( msg->af0 )                                                                          
	  +
				sizeof( msg->af1 )                                                                          
	  +
				sizeof( msg->af2 )                                                                          
	  +
				(                                                          
	0                                                                          
	  +
				sizeof( msg->toc.tow )                                                                          
	  +
				sizeof( msg->toc.wn ) )                                                                          
	  +
				sizeof( msg->iode )                                                                          
	  +
				sizeof( msg->iodc );
}

static inline bool sbp_pack_sbp_msg_ephemeris_bds_t(u8 *buf, size_t len, const sbp_msg_ephemeris_bds_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_ephemeris_bds_t(msg) > len) { return false; }
  
				
				
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->common.sid.sat , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->common.sid.code , 1);
  // NOLINTNEXTLINE
  offset += 1;
				
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->common.toe.tow);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->common.toe.wn);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 4 > len) { return false; }
  memcpy(buf + offset, & msg->common.ura , 4);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->common.fit_interval);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->common.valid , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->common.health_bits , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 4 > len) { return false; }
  memcpy(buf + offset, & msg->tgd1 , 4);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  memcpy(buf + offset, & msg->tgd2 , 4);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  memcpy(buf + offset, & msg->c_rs , 4);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  memcpy(buf + offset, & msg->c_rc , 4);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  memcpy(buf + offset, & msg->c_uc , 4);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  memcpy(buf + offset, & msg->c_us , 4);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  memcpy(buf + offset, & msg->c_ic , 4);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  memcpy(buf + offset, & msg->c_is , 4);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->dn , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->m0 , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->ecc , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->sqrta , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->omega0 , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->omegadot , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->w , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->inc , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->inc_dot , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->af0 , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 4 > len) { return false; }
  memcpy(buf + offset, & msg->af1 , 4);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  memcpy(buf + offset, & msg->af2 , 4);
  // NOLINTNEXTLINE
  offset += 4;
				
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->toc.tow);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->toc.wn);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->iode , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->iodc);
  // NOLINTNEXTLINE
  offset += 2;
  return true;
}

static inline bool sbp_unpack_sbp_msg_ephemeris_bds_t(const u8 *buf, size_t len, sbp_msg_ephemeris_bds_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
			
			
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->common.sid.sat, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->common.sid.code, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
			
      
  if (offset + 4 > len) { return false; }
  msg->common.toe.tow = sbp_unpack_u32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 2 > len) { return false; }
  msg->common.toe.wn = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->common.ura, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  msg->common.fit_interval = sbp_unpack_u32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->common.valid, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->common.health_bits, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->tgd1, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->tgd2, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->c_rs, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->c_rc, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->c_uc, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->c_us, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->c_ic, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->c_is, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->dn, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->m0, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->ecc, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->sqrta, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->omega0, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->omegadot, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->w, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->inc, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->inc_dot, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->af0, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->af1, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->af2, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;
			
      
  if (offset + 4 > len) { return false; }
  msg->toc.tow = sbp_unpack_u32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 2 > len) { return false; }
  msg->toc.wn = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->iode, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 2 > len) { return false; }
  msg->iodc = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_ephemeris_gal_dep_a_t(const sbp_msg_ephemeris_gal_dep_a_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				(                                                          
	0                                                                          
	  +
				(                                                          
	0                                                                          
	  +
				sizeof( msg->common.sid.sat )                                                                          
	  +
				sizeof( msg->common.sid.code ) )                                                                          
	  +
				(                                                          
	0                                                                          
	  +
				sizeof( msg->common.toe.tow )                                                                          
	  +
				sizeof( msg->common.toe.wn ) )                                                                          
	  +
				sizeof( msg->common.ura )                                                                          
	  +
				sizeof( msg->common.fit_interval )                                                                          
	  +
				sizeof( msg->common.valid )                                                                          
	  +
				sizeof( msg->common.health_bits ) )                                                                          
	  +
				sizeof( msg->bgd_e1e5a )                                                                          
	  +
				sizeof( msg->bgd_e1e5b )                                                                          
	  +
				sizeof( msg->c_rs )                                                                          
	  +
				sizeof( msg->c_rc )                                                                          
	  +
				sizeof( msg->c_uc )                                                                          
	  +
				sizeof( msg->c_us )                                                                          
	  +
				sizeof( msg->c_ic )                                                                          
	  +
				sizeof( msg->c_is )                                                                          
	  +
				sizeof( msg->dn )                                                                          
	  +
				sizeof( msg->m0 )                                                                          
	  +
				sizeof( msg->ecc )                                                                          
	  +
				sizeof( msg->sqrta )                                                                          
	  +
				sizeof( msg->omega0 )                                                                          
	  +
				sizeof( msg->omegadot )                                                                          
	  +
				sizeof( msg->w )                                                                          
	  +
				sizeof( msg->inc )                                                                          
	  +
				sizeof( msg->inc_dot )                                                                          
	  +
				sizeof( msg->af0 )                                                                          
	  +
				sizeof( msg->af1 )                                                                          
	  +
				sizeof( msg->af2 )                                                                          
	  +
				(                                                          
	0                                                                          
	  +
				sizeof( msg->toc.tow )                                                                          
	  +
				sizeof( msg->toc.wn ) )                                                                          
	  +
				sizeof( msg->iode )                                                                          
	  +
				sizeof( msg->iodc );
}

static inline bool sbp_pack_sbp_msg_ephemeris_gal_dep_a_t(u8 *buf, size_t len, const sbp_msg_ephemeris_gal_dep_a_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_ephemeris_gal_dep_a_t(msg) > len) { return false; }
  
				
				
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->common.sid.sat , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->common.sid.code , 1);
  // NOLINTNEXTLINE
  offset += 1;
				
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->common.toe.tow);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->common.toe.wn);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 4 > len) { return false; }
  memcpy(buf + offset, & msg->common.ura , 4);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->common.fit_interval);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->common.valid , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->common.health_bits , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 4 > len) { return false; }
  memcpy(buf + offset, & msg->bgd_e1e5a , 4);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  memcpy(buf + offset, & msg->bgd_e1e5b , 4);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  memcpy(buf + offset, & msg->c_rs , 4);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  memcpy(buf + offset, & msg->c_rc , 4);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  memcpy(buf + offset, & msg->c_uc , 4);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  memcpy(buf + offset, & msg->c_us , 4);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  memcpy(buf + offset, & msg->c_ic , 4);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  memcpy(buf + offset, & msg->c_is , 4);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->dn , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->m0 , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->ecc , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->sqrta , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->omega0 , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->omegadot , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->w , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->inc , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->inc_dot , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->af0 , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->af1 , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 4 > len) { return false; }
  memcpy(buf + offset, & msg->af2 , 4);
  // NOLINTNEXTLINE
  offset += 4;
				
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->toc.tow);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->toc.wn);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->iode);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->iodc);
  // NOLINTNEXTLINE
  offset += 2;
  return true;
}

static inline bool sbp_unpack_sbp_msg_ephemeris_gal_dep_a_t(const u8 *buf, size_t len, sbp_msg_ephemeris_gal_dep_a_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
			
			
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->common.sid.sat, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->common.sid.code, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
			
      
  if (offset + 4 > len) { return false; }
  msg->common.toe.tow = sbp_unpack_u32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 2 > len) { return false; }
  msg->common.toe.wn = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->common.ura, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  msg->common.fit_interval = sbp_unpack_u32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->common.valid, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->common.health_bits, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->bgd_e1e5a, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->bgd_e1e5b, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->c_rs, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->c_rc, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->c_uc, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->c_us, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->c_ic, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->c_is, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->dn, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->m0, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->ecc, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->sqrta, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->omega0, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->omegadot, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->w, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->inc, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->inc_dot, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->af0, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->af1, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->af2, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;
			
      
  if (offset + 4 > len) { return false; }
  msg->toc.tow = sbp_unpack_u32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 2 > len) { return false; }
  msg->toc.wn = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 2 > len) { return false; }
  msg->iode = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 2 > len) { return false; }
  msg->iodc = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_ephemeris_gal_t(const sbp_msg_ephemeris_gal_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				(                                                          
	0                                                                          
	  +
				(                                                          
	0                                                                          
	  +
				sizeof( msg->common.sid.sat )                                                                          
	  +
				sizeof( msg->common.sid.code ) )                                                                          
	  +
				(                                                          
	0                                                                          
	  +
				sizeof( msg->common.toe.tow )                                                                          
	  +
				sizeof( msg->common.toe.wn ) )                                                                          
	  +
				sizeof( msg->common.ura )                                                                          
	  +
				sizeof( msg->common.fit_interval )                                                                          
	  +
				sizeof( msg->common.valid )                                                                          
	  +
				sizeof( msg->common.health_bits ) )                                                                          
	  +
				sizeof( msg->bgd_e1e5a )                                                                          
	  +
				sizeof( msg->bgd_e1e5b )                                                                          
	  +
				sizeof( msg->c_rs )                                                                          
	  +
				sizeof( msg->c_rc )                                                                          
	  +
				sizeof( msg->c_uc )                                                                          
	  +
				sizeof( msg->c_us )                                                                          
	  +
				sizeof( msg->c_ic )                                                                          
	  +
				sizeof( msg->c_is )                                                                          
	  +
				sizeof( msg->dn )                                                                          
	  +
				sizeof( msg->m0 )                                                                          
	  +
				sizeof( msg->ecc )                                                                          
	  +
				sizeof( msg->sqrta )                                                                          
	  +
				sizeof( msg->omega0 )                                                                          
	  +
				sizeof( msg->omegadot )                                                                          
	  +
				sizeof( msg->w )                                                                          
	  +
				sizeof( msg->inc )                                                                          
	  +
				sizeof( msg->inc_dot )                                                                          
	  +
				sizeof( msg->af0 )                                                                          
	  +
				sizeof( msg->af1 )                                                                          
	  +
				sizeof( msg->af2 )                                                                          
	  +
				(                                                          
	0                                                                          
	  +
				sizeof( msg->toc.tow )                                                                          
	  +
				sizeof( msg->toc.wn ) )                                                                          
	  +
				sizeof( msg->iode )                                                                          
	  +
				sizeof( msg->iodc )                                                                          
	  +
				sizeof( msg->source );
}

static inline bool sbp_pack_sbp_msg_ephemeris_gal_t(u8 *buf, size_t len, const sbp_msg_ephemeris_gal_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_ephemeris_gal_t(msg) > len) { return false; }
  
				
				
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->common.sid.sat , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->common.sid.code , 1);
  // NOLINTNEXTLINE
  offset += 1;
				
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->common.toe.tow);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->common.toe.wn);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 4 > len) { return false; }
  memcpy(buf + offset, & msg->common.ura , 4);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->common.fit_interval);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->common.valid , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->common.health_bits , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 4 > len) { return false; }
  memcpy(buf + offset, & msg->bgd_e1e5a , 4);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  memcpy(buf + offset, & msg->bgd_e1e5b , 4);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  memcpy(buf + offset, & msg->c_rs , 4);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  memcpy(buf + offset, & msg->c_rc , 4);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  memcpy(buf + offset, & msg->c_uc , 4);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  memcpy(buf + offset, & msg->c_us , 4);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  memcpy(buf + offset, & msg->c_ic , 4);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  memcpy(buf + offset, & msg->c_is , 4);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->dn , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->m0 , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->ecc , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->sqrta , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->omega0 , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->omegadot , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->w , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->inc , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->inc_dot , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->af0 , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->af1 , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 4 > len) { return false; }
  memcpy(buf + offset, & msg->af2 , 4);
  // NOLINTNEXTLINE
  offset += 4;
				
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->toc.tow);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->toc.wn);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->iode);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->iodc);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->source , 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline bool sbp_unpack_sbp_msg_ephemeris_gal_t(const u8 *buf, size_t len, sbp_msg_ephemeris_gal_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
			
			
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->common.sid.sat, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->common.sid.code, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
			
      
  if (offset + 4 > len) { return false; }
  msg->common.toe.tow = sbp_unpack_u32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 2 > len) { return false; }
  msg->common.toe.wn = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->common.ura, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  msg->common.fit_interval = sbp_unpack_u32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->common.valid, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->common.health_bits, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->bgd_e1e5a, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->bgd_e1e5b, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->c_rs, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->c_rc, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->c_uc, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->c_us, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->c_ic, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->c_is, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->dn, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->m0, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->ecc, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->sqrta, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->omega0, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->omegadot, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->w, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->inc, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->inc_dot, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->af0, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->af1, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->af2, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;
			
      
  if (offset + 4 > len) { return false; }
  msg->toc.tow = sbp_unpack_u32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 2 > len) { return false; }
  msg->toc.wn = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 2 > len) { return false; }
  msg->iode = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 2 > len) { return false; }
  msg->iodc = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->source, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_ephemeris_sbas_dep_a_t(const sbp_msg_ephemeris_sbas_dep_a_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				(                                                          
	0                                                                          
	  +
				(                                                          
	0                                                                          
	  +
				sizeof( msg->common.sid.sat )                                                                          
	  +
				sizeof( msg->common.sid.code )                                                                          
	  +
				sizeof( msg->common.sid.reserved ) )                                                                          
	  +
				(                                                          
	0                                                                          
	  +
				sizeof( msg->common.toe.tow )                                                                          
	  +
				sizeof( msg->common.toe.wn ) )                                                                          
	  +
				sizeof( msg->common.ura )                                                                          
	  +
				sizeof( msg->common.fit_interval )                                                                          
	  +
				sizeof( msg->common.valid )                                                                          
	  +
				sizeof( msg->common.health_bits ) )                                                                          
	  +
		  ( 3 *
        sizeof( msg->pos[0] )
		)                                                                          
	  +
		  ( 3 *
        sizeof( msg->vel[0] )
		)                                                                          
	  +
		  ( 3 *
        sizeof( msg->acc[0] )
		)                                                                          
	  +
				sizeof( msg->a_gf0 )                                                                          
	  +
				sizeof( msg->a_gf1 );
}

static inline bool sbp_pack_sbp_msg_ephemeris_sbas_dep_a_t(u8 *buf, size_t len, const sbp_msg_ephemeris_sbas_dep_a_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_ephemeris_sbas_dep_a_t(msg) > len) { return false; }
  
				
				
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->common.sid.sat);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->common.sid.code , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->common.sid.reserved , 1);
  // NOLINTNEXTLINE
  offset += 1;
				
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->common.toe.tow);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->common.toe.wn);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->common.ura , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->common.fit_interval);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->common.valid , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->common.health_bits , 1);
  // NOLINTNEXTLINE
  offset += 1;
		  for(size_t msgpos_idx = 0; msgpos_idx < 3; msgpos_idx++)
			{
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->pos[msgpos_idx] , 8);
  // NOLINTNEXTLINE
  offset += 8;
			}
		  for(size_t msgvel_idx = 0; msgvel_idx < 3; msgvel_idx++)
			{
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->vel[msgvel_idx] , 8);
  // NOLINTNEXTLINE
  offset += 8;
			}
		  for(size_t msgacc_idx = 0; msgacc_idx < 3; msgacc_idx++)
			{
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->acc[msgacc_idx] , 8);
  // NOLINTNEXTLINE
  offset += 8;
			}
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->a_gf0 , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->a_gf1 , 8);
  // NOLINTNEXTLINE
  offset += 8;
  return true;
}

static inline bool sbp_unpack_sbp_msg_ephemeris_sbas_dep_a_t(const u8 *buf, size_t len, sbp_msg_ephemeris_sbas_dep_a_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
			
			
      
  if (offset + 2 > len) { return false; }
  msg->common.sid.sat = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->common.sid.code, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->common.sid.reserved, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
			
      
  if (offset + 4 > len) { return false; }
  msg->common.toe.tow = sbp_unpack_u32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 2 > len) { return false; }
  msg->common.toe.wn = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->common.ura, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 4 > len) { return false; }
  msg->common.fit_interval = sbp_unpack_u32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->common.valid, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->common.health_bits, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
		for (size_t msgpos_idx = 0; msgpos_idx < 3; msgpos_idx++)
		{
        
  if (offset + 8 > len) { return false; }
  memcpy(&msg->pos[msgpos_idx], buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
		}
		for (size_t msgvel_idx = 0; msgvel_idx < 3; msgvel_idx++)
		{
        
  if (offset + 8 > len) { return false; }
  memcpy(&msg->vel[msgvel_idx], buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
		}
		for (size_t msgacc_idx = 0; msgacc_idx < 3; msgacc_idx++)
		{
        
  if (offset + 8 > len) { return false; }
  memcpy(&msg->acc[msgacc_idx], buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
		}
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->a_gf0, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->a_gf1, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_ephemeris_glo_dep_a_t(const sbp_msg_ephemeris_glo_dep_a_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				(                                                          
	0                                                                          
	  +
				(                                                          
	0                                                                          
	  +
				sizeof( msg->common.sid.sat )                                                                          
	  +
				sizeof( msg->common.sid.code )                                                                          
	  +
				sizeof( msg->common.sid.reserved ) )                                                                          
	  +
				(                                                          
	0                                                                          
	  +
				sizeof( msg->common.toe.tow )                                                                          
	  +
				sizeof( msg->common.toe.wn ) )                                                                          
	  +
				sizeof( msg->common.ura )                                                                          
	  +
				sizeof( msg->common.fit_interval )                                                                          
	  +
				sizeof( msg->common.valid )                                                                          
	  +
				sizeof( msg->common.health_bits ) )                                                                          
	  +
				sizeof( msg->gamma )                                                                          
	  +
				sizeof( msg->tau )                                                                          
	  +
		  ( 3 *
        sizeof( msg->pos[0] )
		)                                                                          
	  +
		  ( 3 *
        sizeof( msg->vel[0] )
		)                                                                          
	  +
		  ( 3 *
        sizeof( msg->acc[0] )
		);
}

static inline bool sbp_pack_sbp_msg_ephemeris_glo_dep_a_t(u8 *buf, size_t len, const sbp_msg_ephemeris_glo_dep_a_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_ephemeris_glo_dep_a_t(msg) > len) { return false; }
  
				
				
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->common.sid.sat);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->common.sid.code , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->common.sid.reserved , 1);
  // NOLINTNEXTLINE
  offset += 1;
				
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->common.toe.tow);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->common.toe.wn);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->common.ura , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->common.fit_interval);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->common.valid , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->common.health_bits , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->gamma , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->tau , 8);
  // NOLINTNEXTLINE
  offset += 8;
		  for(size_t msgpos_idx = 0; msgpos_idx < 3; msgpos_idx++)
			{
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->pos[msgpos_idx] , 8);
  // NOLINTNEXTLINE
  offset += 8;
			}
		  for(size_t msgvel_idx = 0; msgvel_idx < 3; msgvel_idx++)
			{
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->vel[msgvel_idx] , 8);
  // NOLINTNEXTLINE
  offset += 8;
			}
		  for(size_t msgacc_idx = 0; msgacc_idx < 3; msgacc_idx++)
			{
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->acc[msgacc_idx] , 8);
  // NOLINTNEXTLINE
  offset += 8;
			}
  return true;
}

static inline bool sbp_unpack_sbp_msg_ephemeris_glo_dep_a_t(const u8 *buf, size_t len, sbp_msg_ephemeris_glo_dep_a_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
			
			
      
  if (offset + 2 > len) { return false; }
  msg->common.sid.sat = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->common.sid.code, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->common.sid.reserved, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
			
      
  if (offset + 4 > len) { return false; }
  msg->common.toe.tow = sbp_unpack_u32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 2 > len) { return false; }
  msg->common.toe.wn = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->common.ura, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 4 > len) { return false; }
  msg->common.fit_interval = sbp_unpack_u32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->common.valid, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->common.health_bits, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->gamma, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->tau, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
		for (size_t msgpos_idx = 0; msgpos_idx < 3; msgpos_idx++)
		{
        
  if (offset + 8 > len) { return false; }
  memcpy(&msg->pos[msgpos_idx], buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
		}
		for (size_t msgvel_idx = 0; msgvel_idx < 3; msgvel_idx++)
		{
        
  if (offset + 8 > len) { return false; }
  memcpy(&msg->vel[msgvel_idx], buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
		}
		for (size_t msgacc_idx = 0; msgacc_idx < 3; msgacc_idx++)
		{
        
  if (offset + 8 > len) { return false; }
  memcpy(&msg->acc[msgacc_idx], buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
		}
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_ephemeris_sbas_dep_b_t(const sbp_msg_ephemeris_sbas_dep_b_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				(                                                          
	0                                                                          
	  +
				(                                                          
	0                                                                          
	  +
				sizeof( msg->common.sid.sat )                                                                          
	  +
				sizeof( msg->common.sid.code ) )                                                                          
	  +
				(                                                          
	0                                                                          
	  +
				sizeof( msg->common.toe.tow )                                                                          
	  +
				sizeof( msg->common.toe.wn ) )                                                                          
	  +
				sizeof( msg->common.ura )                                                                          
	  +
				sizeof( msg->common.fit_interval )                                                                          
	  +
				sizeof( msg->common.valid )                                                                          
	  +
				sizeof( msg->common.health_bits ) )                                                                          
	  +
		  ( 3 *
        sizeof( msg->pos[0] )
		)                                                                          
	  +
		  ( 3 *
        sizeof( msg->vel[0] )
		)                                                                          
	  +
		  ( 3 *
        sizeof( msg->acc[0] )
		)                                                                          
	  +
				sizeof( msg->a_gf0 )                                                                          
	  +
				sizeof( msg->a_gf1 );
}

static inline bool sbp_pack_sbp_msg_ephemeris_sbas_dep_b_t(u8 *buf, size_t len, const sbp_msg_ephemeris_sbas_dep_b_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_ephemeris_sbas_dep_b_t(msg) > len) { return false; }
  
				
				
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->common.sid.sat , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->common.sid.code , 1);
  // NOLINTNEXTLINE
  offset += 1;
				
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->common.toe.tow);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->common.toe.wn);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->common.ura , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->common.fit_interval);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->common.valid , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->common.health_bits , 1);
  // NOLINTNEXTLINE
  offset += 1;
		  for(size_t msgpos_idx = 0; msgpos_idx < 3; msgpos_idx++)
			{
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->pos[msgpos_idx] , 8);
  // NOLINTNEXTLINE
  offset += 8;
			}
		  for(size_t msgvel_idx = 0; msgvel_idx < 3; msgvel_idx++)
			{
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->vel[msgvel_idx] , 8);
  // NOLINTNEXTLINE
  offset += 8;
			}
		  for(size_t msgacc_idx = 0; msgacc_idx < 3; msgacc_idx++)
			{
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->acc[msgacc_idx] , 8);
  // NOLINTNEXTLINE
  offset += 8;
			}
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->a_gf0 , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->a_gf1 , 8);
  // NOLINTNEXTLINE
  offset += 8;
  return true;
}

static inline bool sbp_unpack_sbp_msg_ephemeris_sbas_dep_b_t(const u8 *buf, size_t len, sbp_msg_ephemeris_sbas_dep_b_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
			
			
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->common.sid.sat, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->common.sid.code, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
			
      
  if (offset + 4 > len) { return false; }
  msg->common.toe.tow = sbp_unpack_u32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 2 > len) { return false; }
  msg->common.toe.wn = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->common.ura, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 4 > len) { return false; }
  msg->common.fit_interval = sbp_unpack_u32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->common.valid, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->common.health_bits, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
		for (size_t msgpos_idx = 0; msgpos_idx < 3; msgpos_idx++)
		{
        
  if (offset + 8 > len) { return false; }
  memcpy(&msg->pos[msgpos_idx], buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
		}
		for (size_t msgvel_idx = 0; msgvel_idx < 3; msgvel_idx++)
		{
        
  if (offset + 8 > len) { return false; }
  memcpy(&msg->vel[msgvel_idx], buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
		}
		for (size_t msgacc_idx = 0; msgacc_idx < 3; msgacc_idx++)
		{
        
  if (offset + 8 > len) { return false; }
  memcpy(&msg->acc[msgacc_idx], buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
		}
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->a_gf0, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->a_gf1, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_ephemeris_sbas_t(const sbp_msg_ephemeris_sbas_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				(                                                          
	0                                                                          
	  +
				(                                                          
	0                                                                          
	  +
				sizeof( msg->common.sid.sat )                                                                          
	  +
				sizeof( msg->common.sid.code ) )                                                                          
	  +
				(                                                          
	0                                                                          
	  +
				sizeof( msg->common.toe.tow )                                                                          
	  +
				sizeof( msg->common.toe.wn ) )                                                                          
	  +
				sizeof( msg->common.ura )                                                                          
	  +
				sizeof( msg->common.fit_interval )                                                                          
	  +
				sizeof( msg->common.valid )                                                                          
	  +
				sizeof( msg->common.health_bits ) )                                                                          
	  +
		  ( 3 *
        sizeof( msg->pos[0] )
		)                                                                          
	  +
		  ( 3 *
        sizeof( msg->vel[0] )
		)                                                                          
	  +
		  ( 3 *
        sizeof( msg->acc[0] )
		)                                                                          
	  +
				sizeof( msg->a_gf0 )                                                                          
	  +
				sizeof( msg->a_gf1 );
}

static inline bool sbp_pack_sbp_msg_ephemeris_sbas_t(u8 *buf, size_t len, const sbp_msg_ephemeris_sbas_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_ephemeris_sbas_t(msg) > len) { return false; }
  
				
				
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->common.sid.sat , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->common.sid.code , 1);
  // NOLINTNEXTLINE
  offset += 1;
				
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->common.toe.tow);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->common.toe.wn);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 4 > len) { return false; }
  memcpy(buf + offset, & msg->common.ura , 4);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->common.fit_interval);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->common.valid , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->common.health_bits , 1);
  // NOLINTNEXTLINE
  offset += 1;
		  for(size_t msgpos_idx = 0; msgpos_idx < 3; msgpos_idx++)
			{
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->pos[msgpos_idx] , 8);
  // NOLINTNEXTLINE
  offset += 8;
			}
		  for(size_t msgvel_idx = 0; msgvel_idx < 3; msgvel_idx++)
			{
        
  if (offset + 4 > len) { return false; }
  memcpy(buf + offset, & msg->vel[msgvel_idx] , 4);
  // NOLINTNEXTLINE
  offset += 4;
			}
		  for(size_t msgacc_idx = 0; msgacc_idx < 3; msgacc_idx++)
			{
        
  if (offset + 4 > len) { return false; }
  memcpy(buf + offset, & msg->acc[msgacc_idx] , 4);
  // NOLINTNEXTLINE
  offset += 4;
			}
        
  if (offset + 4 > len) { return false; }
  memcpy(buf + offset, & msg->a_gf0 , 4);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  memcpy(buf + offset, & msg->a_gf1 , 4);
  // NOLINTNEXTLINE
  offset += 4;
  return true;
}

static inline bool sbp_unpack_sbp_msg_ephemeris_sbas_t(const u8 *buf, size_t len, sbp_msg_ephemeris_sbas_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
			
			
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->common.sid.sat, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->common.sid.code, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
			
      
  if (offset + 4 > len) { return false; }
  msg->common.toe.tow = sbp_unpack_u32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 2 > len) { return false; }
  msg->common.toe.wn = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->common.ura, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  msg->common.fit_interval = sbp_unpack_u32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->common.valid, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->common.health_bits, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
		for (size_t msgpos_idx = 0; msgpos_idx < 3; msgpos_idx++)
		{
        
  if (offset + 8 > len) { return false; }
  memcpy(&msg->pos[msgpos_idx], buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
		}
		for (size_t msgvel_idx = 0; msgvel_idx < 3; msgvel_idx++)
		{
        
  if (offset + 4 > len) { return false; }
  memcpy(&msg->vel[msgvel_idx], buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;
		}
		for (size_t msgacc_idx = 0; msgacc_idx < 3; msgacc_idx++)
		{
        
  if (offset + 4 > len) { return false; }
  memcpy(&msg->acc[msgacc_idx], buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;
		}
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->a_gf0, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->a_gf1, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_ephemeris_glo_dep_b_t(const sbp_msg_ephemeris_glo_dep_b_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				(                                                          
	0                                                                          
	  +
				(                                                          
	0                                                                          
	  +
				sizeof( msg->common.sid.sat )                                                                          
	  +
				sizeof( msg->common.sid.code ) )                                                                          
	  +
				(                                                          
	0                                                                          
	  +
				sizeof( msg->common.toe.tow )                                                                          
	  +
				sizeof( msg->common.toe.wn ) )                                                                          
	  +
				sizeof( msg->common.ura )                                                                          
	  +
				sizeof( msg->common.fit_interval )                                                                          
	  +
				sizeof( msg->common.valid )                                                                          
	  +
				sizeof( msg->common.health_bits ) )                                                                          
	  +
				sizeof( msg->gamma )                                                                          
	  +
				sizeof( msg->tau )                                                                          
	  +
		  ( 3 *
        sizeof( msg->pos[0] )
		)                                                                          
	  +
		  ( 3 *
        sizeof( msg->vel[0] )
		)                                                                          
	  +
		  ( 3 *
        sizeof( msg->acc[0] )
		);
}

static inline bool sbp_pack_sbp_msg_ephemeris_glo_dep_b_t(u8 *buf, size_t len, const sbp_msg_ephemeris_glo_dep_b_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_ephemeris_glo_dep_b_t(msg) > len) { return false; }
  
				
				
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->common.sid.sat , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->common.sid.code , 1);
  // NOLINTNEXTLINE
  offset += 1;
				
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->common.toe.tow);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->common.toe.wn);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->common.ura , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->common.fit_interval);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->common.valid , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->common.health_bits , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->gamma , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->tau , 8);
  // NOLINTNEXTLINE
  offset += 8;
		  for(size_t msgpos_idx = 0; msgpos_idx < 3; msgpos_idx++)
			{
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->pos[msgpos_idx] , 8);
  // NOLINTNEXTLINE
  offset += 8;
			}
		  for(size_t msgvel_idx = 0; msgvel_idx < 3; msgvel_idx++)
			{
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->vel[msgvel_idx] , 8);
  // NOLINTNEXTLINE
  offset += 8;
			}
		  for(size_t msgacc_idx = 0; msgacc_idx < 3; msgacc_idx++)
			{
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->acc[msgacc_idx] , 8);
  // NOLINTNEXTLINE
  offset += 8;
			}
  return true;
}

static inline bool sbp_unpack_sbp_msg_ephemeris_glo_dep_b_t(const u8 *buf, size_t len, sbp_msg_ephemeris_glo_dep_b_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
			
			
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->common.sid.sat, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->common.sid.code, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
			
      
  if (offset + 4 > len) { return false; }
  msg->common.toe.tow = sbp_unpack_u32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 2 > len) { return false; }
  msg->common.toe.wn = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->common.ura, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 4 > len) { return false; }
  msg->common.fit_interval = sbp_unpack_u32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->common.valid, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->common.health_bits, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->gamma, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->tau, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
		for (size_t msgpos_idx = 0; msgpos_idx < 3; msgpos_idx++)
		{
        
  if (offset + 8 > len) { return false; }
  memcpy(&msg->pos[msgpos_idx], buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
		}
		for (size_t msgvel_idx = 0; msgvel_idx < 3; msgvel_idx++)
		{
        
  if (offset + 8 > len) { return false; }
  memcpy(&msg->vel[msgvel_idx], buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
		}
		for (size_t msgacc_idx = 0; msgacc_idx < 3; msgacc_idx++)
		{
        
  if (offset + 8 > len) { return false; }
  memcpy(&msg->acc[msgacc_idx], buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
		}
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_ephemeris_glo_dep_c_t(const sbp_msg_ephemeris_glo_dep_c_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				(                                                          
	0                                                                          
	  +
				(                                                          
	0                                                                          
	  +
				sizeof( msg->common.sid.sat )                                                                          
	  +
				sizeof( msg->common.sid.code ) )                                                                          
	  +
				(                                                          
	0                                                                          
	  +
				sizeof( msg->common.toe.tow )                                                                          
	  +
				sizeof( msg->common.toe.wn ) )                                                                          
	  +
				sizeof( msg->common.ura )                                                                          
	  +
				sizeof( msg->common.fit_interval )                                                                          
	  +
				sizeof( msg->common.valid )                                                                          
	  +
				sizeof( msg->common.health_bits ) )                                                                          
	  +
				sizeof( msg->gamma )                                                                          
	  +
				sizeof( msg->tau )                                                                          
	  +
				sizeof( msg->d_tau )                                                                          
	  +
		  ( 3 *
        sizeof( msg->pos[0] )
		)                                                                          
	  +
		  ( 3 *
        sizeof( msg->vel[0] )
		)                                                                          
	  +
		  ( 3 *
        sizeof( msg->acc[0] )
		)                                                                          
	  +
				sizeof( msg->fcn );
}

static inline bool sbp_pack_sbp_msg_ephemeris_glo_dep_c_t(u8 *buf, size_t len, const sbp_msg_ephemeris_glo_dep_c_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_ephemeris_glo_dep_c_t(msg) > len) { return false; }
  
				
				
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->common.sid.sat , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->common.sid.code , 1);
  // NOLINTNEXTLINE
  offset += 1;
				
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->common.toe.tow);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->common.toe.wn);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->common.ura , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->common.fit_interval);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->common.valid , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->common.health_bits , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->gamma , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->tau , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->d_tau , 8);
  // NOLINTNEXTLINE
  offset += 8;
		  for(size_t msgpos_idx = 0; msgpos_idx < 3; msgpos_idx++)
			{
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->pos[msgpos_idx] , 8);
  // NOLINTNEXTLINE
  offset += 8;
			}
		  for(size_t msgvel_idx = 0; msgvel_idx < 3; msgvel_idx++)
			{
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->vel[msgvel_idx] , 8);
  // NOLINTNEXTLINE
  offset += 8;
			}
		  for(size_t msgacc_idx = 0; msgacc_idx < 3; msgacc_idx++)
			{
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->acc[msgacc_idx] , 8);
  // NOLINTNEXTLINE
  offset += 8;
			}
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->fcn , 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline bool sbp_unpack_sbp_msg_ephemeris_glo_dep_c_t(const u8 *buf, size_t len, sbp_msg_ephemeris_glo_dep_c_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
			
			
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->common.sid.sat, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->common.sid.code, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
			
      
  if (offset + 4 > len) { return false; }
  msg->common.toe.tow = sbp_unpack_u32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 2 > len) { return false; }
  msg->common.toe.wn = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->common.ura, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 4 > len) { return false; }
  msg->common.fit_interval = sbp_unpack_u32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->common.valid, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->common.health_bits, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->gamma, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->tau, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->d_tau, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
		for (size_t msgpos_idx = 0; msgpos_idx < 3; msgpos_idx++)
		{
        
  if (offset + 8 > len) { return false; }
  memcpy(&msg->pos[msgpos_idx], buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
		}
		for (size_t msgvel_idx = 0; msgvel_idx < 3; msgvel_idx++)
		{
        
  if (offset + 8 > len) { return false; }
  memcpy(&msg->vel[msgvel_idx], buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
		}
		for (size_t msgacc_idx = 0; msgacc_idx < 3; msgacc_idx++)
		{
        
  if (offset + 8 > len) { return false; }
  memcpy(&msg->acc[msgacc_idx], buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
		}
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->fcn, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_ephemeris_glo_dep_d_t(const sbp_msg_ephemeris_glo_dep_d_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				(                                                          
	0                                                                          
	  +
				(                                                          
	0                                                                          
	  +
				sizeof( msg->common.sid.sat )                                                                          
	  +
				sizeof( msg->common.sid.code ) )                                                                          
	  +
				(                                                          
	0                                                                          
	  +
				sizeof( msg->common.toe.tow )                                                                          
	  +
				sizeof( msg->common.toe.wn ) )                                                                          
	  +
				sizeof( msg->common.ura )                                                                          
	  +
				sizeof( msg->common.fit_interval )                                                                          
	  +
				sizeof( msg->common.valid )                                                                          
	  +
				sizeof( msg->common.health_bits ) )                                                                          
	  +
				sizeof( msg->gamma )                                                                          
	  +
				sizeof( msg->tau )                                                                          
	  +
				sizeof( msg->d_tau )                                                                          
	  +
		  ( 3 *
        sizeof( msg->pos[0] )
		)                                                                          
	  +
		  ( 3 *
        sizeof( msg->vel[0] )
		)                                                                          
	  +
		  ( 3 *
        sizeof( msg->acc[0] )
		)                                                                          
	  +
				sizeof( msg->fcn )                                                                          
	  +
				sizeof( msg->iod );
}

static inline bool sbp_pack_sbp_msg_ephemeris_glo_dep_d_t(u8 *buf, size_t len, const sbp_msg_ephemeris_glo_dep_d_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_ephemeris_glo_dep_d_t(msg) > len) { return false; }
  
				
				
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->common.sid.sat , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->common.sid.code , 1);
  // NOLINTNEXTLINE
  offset += 1;
				
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->common.toe.tow);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->common.toe.wn);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->common.ura , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->common.fit_interval);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->common.valid , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->common.health_bits , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->gamma , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->tau , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->d_tau , 8);
  // NOLINTNEXTLINE
  offset += 8;
		  for(size_t msgpos_idx = 0; msgpos_idx < 3; msgpos_idx++)
			{
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->pos[msgpos_idx] , 8);
  // NOLINTNEXTLINE
  offset += 8;
			}
		  for(size_t msgvel_idx = 0; msgvel_idx < 3; msgvel_idx++)
			{
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->vel[msgvel_idx] , 8);
  // NOLINTNEXTLINE
  offset += 8;
			}
		  for(size_t msgacc_idx = 0; msgacc_idx < 3; msgacc_idx++)
			{
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->acc[msgacc_idx] , 8);
  // NOLINTNEXTLINE
  offset += 8;
			}
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->fcn , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->iod , 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline bool sbp_unpack_sbp_msg_ephemeris_glo_dep_d_t(const u8 *buf, size_t len, sbp_msg_ephemeris_glo_dep_d_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
			
			
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->common.sid.sat, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->common.sid.code, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
			
      
  if (offset + 4 > len) { return false; }
  msg->common.toe.tow = sbp_unpack_u32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 2 > len) { return false; }
  msg->common.toe.wn = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->common.ura, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 4 > len) { return false; }
  msg->common.fit_interval = sbp_unpack_u32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->common.valid, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->common.health_bits, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->gamma, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->tau, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->d_tau, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
		for (size_t msgpos_idx = 0; msgpos_idx < 3; msgpos_idx++)
		{
        
  if (offset + 8 > len) { return false; }
  memcpy(&msg->pos[msgpos_idx], buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
		}
		for (size_t msgvel_idx = 0; msgvel_idx < 3; msgvel_idx++)
		{
        
  if (offset + 8 > len) { return false; }
  memcpy(&msg->vel[msgvel_idx], buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
		}
		for (size_t msgacc_idx = 0; msgacc_idx < 3; msgacc_idx++)
		{
        
  if (offset + 8 > len) { return false; }
  memcpy(&msg->acc[msgacc_idx], buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
		}
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->fcn, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->iod, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_ephemeris_glo_t(const sbp_msg_ephemeris_glo_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				(                                                          
	0                                                                          
	  +
				(                                                          
	0                                                                          
	  +
				sizeof( msg->common.sid.sat )                                                                          
	  +
				sizeof( msg->common.sid.code ) )                                                                          
	  +
				(                                                          
	0                                                                          
	  +
				sizeof( msg->common.toe.tow )                                                                          
	  +
				sizeof( msg->common.toe.wn ) )                                                                          
	  +
				sizeof( msg->common.ura )                                                                          
	  +
				sizeof( msg->common.fit_interval )                                                                          
	  +
				sizeof( msg->common.valid )                                                                          
	  +
				sizeof( msg->common.health_bits ) )                                                                          
	  +
				sizeof( msg->gamma )                                                                          
	  +
				sizeof( msg->tau )                                                                          
	  +
				sizeof( msg->d_tau )                                                                          
	  +
		  ( 3 *
        sizeof( msg->pos[0] )
		)                                                                          
	  +
		  ( 3 *
        sizeof( msg->vel[0] )
		)                                                                          
	  +
		  ( 3 *
        sizeof( msg->acc[0] )
		)                                                                          
	  +
				sizeof( msg->fcn )                                                                          
	  +
				sizeof( msg->iod );
}

static inline bool sbp_pack_sbp_msg_ephemeris_glo_t(u8 *buf, size_t len, const sbp_msg_ephemeris_glo_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_ephemeris_glo_t(msg) > len) { return false; }
  
				
				
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->common.sid.sat , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->common.sid.code , 1);
  // NOLINTNEXTLINE
  offset += 1;
				
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->common.toe.tow);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->common.toe.wn);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 4 > len) { return false; }
  memcpy(buf + offset, & msg->common.ura , 4);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->common.fit_interval);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->common.valid , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->common.health_bits , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 4 > len) { return false; }
  memcpy(buf + offset, & msg->gamma , 4);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  memcpy(buf + offset, & msg->tau , 4);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  memcpy(buf + offset, & msg->d_tau , 4);
  // NOLINTNEXTLINE
  offset += 4;
		  for(size_t msgpos_idx = 0; msgpos_idx < 3; msgpos_idx++)
			{
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->pos[msgpos_idx] , 8);
  // NOLINTNEXTLINE
  offset += 8;
			}
		  for(size_t msgvel_idx = 0; msgvel_idx < 3; msgvel_idx++)
			{
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->vel[msgvel_idx] , 8);
  // NOLINTNEXTLINE
  offset += 8;
			}
		  for(size_t msgacc_idx = 0; msgacc_idx < 3; msgacc_idx++)
			{
        
  if (offset + 4 > len) { return false; }
  memcpy(buf + offset, & msg->acc[msgacc_idx] , 4);
  // NOLINTNEXTLINE
  offset += 4;
			}
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->fcn , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->iod , 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline bool sbp_unpack_sbp_msg_ephemeris_glo_t(const u8 *buf, size_t len, sbp_msg_ephemeris_glo_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
			
			
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->common.sid.sat, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->common.sid.code, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
			
      
  if (offset + 4 > len) { return false; }
  msg->common.toe.tow = sbp_unpack_u32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 2 > len) { return false; }
  msg->common.toe.wn = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->common.ura, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  msg->common.fit_interval = sbp_unpack_u32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->common.valid, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->common.health_bits, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->gamma, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->tau, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->d_tau, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;
		for (size_t msgpos_idx = 0; msgpos_idx < 3; msgpos_idx++)
		{
        
  if (offset + 8 > len) { return false; }
  memcpy(&msg->pos[msgpos_idx], buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
		}
		for (size_t msgvel_idx = 0; msgvel_idx < 3; msgvel_idx++)
		{
        
  if (offset + 8 > len) { return false; }
  memcpy(&msg->vel[msgvel_idx], buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
		}
		for (size_t msgacc_idx = 0; msgacc_idx < 3; msgacc_idx++)
		{
        
  if (offset + 4 > len) { return false; }
  memcpy(&msg->acc[msgacc_idx], buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;
		}
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->fcn, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->iod, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_ephemeris_dep_d_t(const sbp_msg_ephemeris_dep_d_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				sizeof( msg->tgd )                                                                          
	  +
				sizeof( msg->c_rs )                                                                          
	  +
				sizeof( msg->c_rc )                                                                          
	  +
				sizeof( msg->c_uc )                                                                          
	  +
				sizeof( msg->c_us )                                                                          
	  +
				sizeof( msg->c_ic )                                                                          
	  +
				sizeof( msg->c_is )                                                                          
	  +
				sizeof( msg->dn )                                                                          
	  +
				sizeof( msg->m0 )                                                                          
	  +
				sizeof( msg->ecc )                                                                          
	  +
				sizeof( msg->sqrta )                                                                          
	  +
				sizeof( msg->omega0 )                                                                          
	  +
				sizeof( msg->omegadot )                                                                          
	  +
				sizeof( msg->w )                                                                          
	  +
				sizeof( msg->inc )                                                                          
	  +
				sizeof( msg->inc_dot )                                                                          
	  +
				sizeof( msg->af0 )                                                                          
	  +
				sizeof( msg->af1 )                                                                          
	  +
				sizeof( msg->af2 )                                                                          
	  +
				sizeof( msg->toe_tow )                                                                          
	  +
				sizeof( msg->toe_wn )                                                                          
	  +
				sizeof( msg->toc_tow )                                                                          
	  +
				sizeof( msg->toc_wn )                                                                          
	  +
				sizeof( msg->valid )                                                                          
	  +
				sizeof( msg->healthy )                                                                          
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
				sizeof( msg->iode )                                                                          
	  +
				sizeof( msg->iodc )                                                                          
	  +
				sizeof( msg->reserved );
}

static inline bool sbp_pack_sbp_msg_ephemeris_dep_d_t(u8 *buf, size_t len, const sbp_msg_ephemeris_dep_d_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_ephemeris_dep_d_t(msg) > len) { return false; }
  
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->tgd , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->c_rs , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->c_rc , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->c_uc , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->c_us , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->c_ic , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->c_is , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->dn , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->m0 , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->ecc , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->sqrta , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->omega0 , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->omegadot , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->w , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->inc , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->inc_dot , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->af0 , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->af1 , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->af2 , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->toe_tow , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->toe_wn);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->toc_tow , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->toc_wn);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->valid , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->healthy , 1);
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
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->iode , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->iodc);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->reserved);
  // NOLINTNEXTLINE
  offset += 4;
  return true;
}

static inline bool sbp_unpack_sbp_msg_ephemeris_dep_d_t(const u8 *buf, size_t len, sbp_msg_ephemeris_dep_d_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->tgd, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->c_rs, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->c_rc, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->c_uc, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->c_us, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->c_ic, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->c_is, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->dn, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->m0, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->ecc, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->sqrta, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->omega0, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->omegadot, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->w, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->inc, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->inc_dot, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->af0, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->af1, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->af2, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->toe_tow, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 2 > len) { return false; }
  msg->toe_wn = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->toc_tow, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 2 > len) { return false; }
  msg->toc_wn = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->valid, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->healthy, buf + offset, 1);
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
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->iode, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 2 > len) { return false; }
  msg->iodc = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 4 > len) { return false; }
  msg->reserved = sbp_unpack_u32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_ephemeris_dep_a_t(const sbp_msg_ephemeris_dep_a_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				sizeof( msg->tgd )                                                                          
	  +
				sizeof( msg->c_rs )                                                                          
	  +
				sizeof( msg->c_rc )                                                                          
	  +
				sizeof( msg->c_uc )                                                                          
	  +
				sizeof( msg->c_us )                                                                          
	  +
				sizeof( msg->c_ic )                                                                          
	  +
				sizeof( msg->c_is )                                                                          
	  +
				sizeof( msg->dn )                                                                          
	  +
				sizeof( msg->m0 )                                                                          
	  +
				sizeof( msg->ecc )                                                                          
	  +
				sizeof( msg->sqrta )                                                                          
	  +
				sizeof( msg->omega0 )                                                                          
	  +
				sizeof( msg->omegadot )                                                                          
	  +
				sizeof( msg->w )                                                                          
	  +
				sizeof( msg->inc )                                                                          
	  +
				sizeof( msg->inc_dot )                                                                          
	  +
				sizeof( msg->af0 )                                                                          
	  +
				sizeof( msg->af1 )                                                                          
	  +
				sizeof( msg->af2 )                                                                          
	  +
				sizeof( msg->toe_tow )                                                                          
	  +
				sizeof( msg->toe_wn )                                                                          
	  +
				sizeof( msg->toc_tow )                                                                          
	  +
				sizeof( msg->toc_wn )                                                                          
	  +
				sizeof( msg->valid )                                                                          
	  +
				sizeof( msg->healthy )                                                                          
	  +
				sizeof( msg->prn );
}

static inline bool sbp_pack_sbp_msg_ephemeris_dep_a_t(u8 *buf, size_t len, const sbp_msg_ephemeris_dep_a_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_ephemeris_dep_a_t(msg) > len) { return false; }
  
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->tgd , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->c_rs , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->c_rc , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->c_uc , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->c_us , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->c_ic , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->c_is , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->dn , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->m0 , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->ecc , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->sqrta , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->omega0 , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->omegadot , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->w , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->inc , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->inc_dot , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->af0 , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->af1 , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->af2 , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->toe_tow , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->toe_wn);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->toc_tow , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->toc_wn);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->valid , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->healthy , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->prn , 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline bool sbp_unpack_sbp_msg_ephemeris_dep_a_t(const u8 *buf, size_t len, sbp_msg_ephemeris_dep_a_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->tgd, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->c_rs, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->c_rc, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->c_uc, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->c_us, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->c_ic, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->c_is, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->dn, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->m0, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->ecc, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->sqrta, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->omega0, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->omegadot, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->w, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->inc, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->inc_dot, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->af0, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->af1, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->af2, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->toe_tow, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 2 > len) { return false; }
  msg->toe_wn = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->toc_tow, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 2 > len) { return false; }
  msg->toc_wn = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->valid, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->healthy, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->prn, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_ephemeris_dep_b_t(const sbp_msg_ephemeris_dep_b_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				sizeof( msg->tgd )                                                                          
	  +
				sizeof( msg->c_rs )                                                                          
	  +
				sizeof( msg->c_rc )                                                                          
	  +
				sizeof( msg->c_uc )                                                                          
	  +
				sizeof( msg->c_us )                                                                          
	  +
				sizeof( msg->c_ic )                                                                          
	  +
				sizeof( msg->c_is )                                                                          
	  +
				sizeof( msg->dn )                                                                          
	  +
				sizeof( msg->m0 )                                                                          
	  +
				sizeof( msg->ecc )                                                                          
	  +
				sizeof( msg->sqrta )                                                                          
	  +
				sizeof( msg->omega0 )                                                                          
	  +
				sizeof( msg->omegadot )                                                                          
	  +
				sizeof( msg->w )                                                                          
	  +
				sizeof( msg->inc )                                                                          
	  +
				sizeof( msg->inc_dot )                                                                          
	  +
				sizeof( msg->af0 )                                                                          
	  +
				sizeof( msg->af1 )                                                                          
	  +
				sizeof( msg->af2 )                                                                          
	  +
				sizeof( msg->toe_tow )                                                                          
	  +
				sizeof( msg->toe_wn )                                                                          
	  +
				sizeof( msg->toc_tow )                                                                          
	  +
				sizeof( msg->toc_wn )                                                                          
	  +
				sizeof( msg->valid )                                                                          
	  +
				sizeof( msg->healthy )                                                                          
	  +
				sizeof( msg->prn )                                                                          
	  +
				sizeof( msg->iode );
}

static inline bool sbp_pack_sbp_msg_ephemeris_dep_b_t(u8 *buf, size_t len, const sbp_msg_ephemeris_dep_b_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_ephemeris_dep_b_t(msg) > len) { return false; }
  
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->tgd , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->c_rs , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->c_rc , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->c_uc , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->c_us , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->c_ic , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->c_is , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->dn , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->m0 , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->ecc , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->sqrta , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->omega0 , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->omegadot , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->w , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->inc , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->inc_dot , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->af0 , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->af1 , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->af2 , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->toe_tow , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->toe_wn);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->toc_tow , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->toc_wn);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->valid , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->healthy , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->prn , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->iode , 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline bool sbp_unpack_sbp_msg_ephemeris_dep_b_t(const u8 *buf, size_t len, sbp_msg_ephemeris_dep_b_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->tgd, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->c_rs, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->c_rc, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->c_uc, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->c_us, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->c_ic, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->c_is, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->dn, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->m0, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->ecc, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->sqrta, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->omega0, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->omegadot, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->w, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->inc, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->inc_dot, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->af0, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->af1, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->af2, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->toe_tow, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 2 > len) { return false; }
  msg->toe_wn = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->toc_tow, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 2 > len) { return false; }
  msg->toc_wn = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->valid, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->healthy, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->prn, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->iode, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_ephemeris_dep_c_t(const sbp_msg_ephemeris_dep_c_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				sizeof( msg->tgd )                                                                          
	  +
				sizeof( msg->c_rs )                                                                          
	  +
				sizeof( msg->c_rc )                                                                          
	  +
				sizeof( msg->c_uc )                                                                          
	  +
				sizeof( msg->c_us )                                                                          
	  +
				sizeof( msg->c_ic )                                                                          
	  +
				sizeof( msg->c_is )                                                                          
	  +
				sizeof( msg->dn )                                                                          
	  +
				sizeof( msg->m0 )                                                                          
	  +
				sizeof( msg->ecc )                                                                          
	  +
				sizeof( msg->sqrta )                                                                          
	  +
				sizeof( msg->omega0 )                                                                          
	  +
				sizeof( msg->omegadot )                                                                          
	  +
				sizeof( msg->w )                                                                          
	  +
				sizeof( msg->inc )                                                                          
	  +
				sizeof( msg->inc_dot )                                                                          
	  +
				sizeof( msg->af0 )                                                                          
	  +
				sizeof( msg->af1 )                                                                          
	  +
				sizeof( msg->af2 )                                                                          
	  +
				sizeof( msg->toe_tow )                                                                          
	  +
				sizeof( msg->toe_wn )                                                                          
	  +
				sizeof( msg->toc_tow )                                                                          
	  +
				sizeof( msg->toc_wn )                                                                          
	  +
				sizeof( msg->valid )                                                                          
	  +
				sizeof( msg->healthy )                                                                          
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
				sizeof( msg->iode )                                                                          
	  +
				sizeof( msg->iodc )                                                                          
	  +
				sizeof( msg->reserved );
}

static inline bool sbp_pack_sbp_msg_ephemeris_dep_c_t(u8 *buf, size_t len, const sbp_msg_ephemeris_dep_c_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_ephemeris_dep_c_t(msg) > len) { return false; }
  
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->tgd , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->c_rs , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->c_rc , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->c_uc , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->c_us , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->c_ic , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->c_is , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->dn , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->m0 , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->ecc , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->sqrta , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->omega0 , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->omegadot , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->w , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->inc , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->inc_dot , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->af0 , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->af1 , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->af2 , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->toe_tow , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->toe_wn);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->toc_tow , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->toc_wn);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->valid , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->healthy , 1);
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
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->iode , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->iodc);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->reserved);
  // NOLINTNEXTLINE
  offset += 4;
  return true;
}

static inline bool sbp_unpack_sbp_msg_ephemeris_dep_c_t(const u8 *buf, size_t len, sbp_msg_ephemeris_dep_c_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->tgd, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->c_rs, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->c_rc, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->c_uc, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->c_us, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->c_ic, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->c_is, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->dn, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->m0, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->ecc, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->sqrta, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->omega0, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->omegadot, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->w, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->inc, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->inc_dot, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->af0, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->af1, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->af2, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->toe_tow, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 2 > len) { return false; }
  msg->toe_wn = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->toc_tow, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 2 > len) { return false; }
  msg->toc_wn = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->valid, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->healthy, buf + offset, 1);
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
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->iode, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 2 > len) { return false; }
  msg->iodc = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 4 > len) { return false; }
  msg->reserved = sbp_unpack_u32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
  return true;
}

static inline size_t sbp_packed_size_sbp_observation_header_dep_t(const sbp_observation_header_dep_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				(                                                          
	0                                                                          
	  +
				sizeof( msg->t.tow )                                                                          
	  +
				sizeof( msg->t.wn ) )                                                                          
	  +
				sizeof( msg->n_obs );
}

static inline bool sbp_pack_sbp_observation_header_dep_t(u8 *buf, size_t len, const sbp_observation_header_dep_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_observation_header_dep_t(msg) > len) { return false; }
  
				
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->t.tow);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->t.wn);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->n_obs , 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline bool sbp_unpack_sbp_observation_header_dep_t(const u8 *buf, size_t len, sbp_observation_header_dep_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
			
      
  if (offset + 4 > len) { return false; }
  msg->t.tow = sbp_unpack_u32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 2 > len) { return false; }
  msg->t.wn = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->n_obs, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline size_t sbp_packed_size_sbp_carrier_phase_dep_a_t(const sbp_carrier_phase_dep_a_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				sizeof( msg->i )                                                                          
	  +
				sizeof( msg->f );
}

static inline bool sbp_pack_sbp_carrier_phase_dep_a_t(u8 *buf, size_t len, const sbp_carrier_phase_dep_a_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_carrier_phase_dep_a_t(msg) > len) { return false; }
  
        
  if (offset + 4 > len) { return false; }
  sbp_pack_s32(buf + offset, msg->i);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->f , 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline bool sbp_unpack_sbp_carrier_phase_dep_a_t(const u8 *buf, size_t len, sbp_carrier_phase_dep_a_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
      
  if (offset + 4 > len) { return false; }
  msg->i = sbp_unpack_s32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->f, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline size_t sbp_packed_size_sbp_packed_obs_content_dep_a_t(const sbp_packed_obs_content_dep_a_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				sizeof( msg->P )                                                                          
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
				sizeof( msg->prn );
}

static inline bool sbp_pack_sbp_packed_obs_content_dep_a_t(u8 *buf, size_t len, const sbp_packed_obs_content_dep_a_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_packed_obs_content_dep_a_t(msg) > len) { return false; }
  
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->P);
  // NOLINTNEXTLINE
  offset += 4;
				
        
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
  memcpy(buf + offset, & msg->prn , 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline bool sbp_unpack_sbp_packed_obs_content_dep_a_t(const u8 *buf, size_t len, sbp_packed_obs_content_dep_a_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
      
  if (offset + 4 > len) { return false; }
  msg->P = sbp_unpack_u32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
			
      
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
  memcpy(&msg->prn, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline size_t sbp_packed_size_sbp_packed_obs_content_dep_b_t(const sbp_packed_obs_content_dep_b_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				sizeof( msg->P )                                                                          
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
				sizeof( msg->sid.reserved ) );
}

static inline bool sbp_pack_sbp_packed_obs_content_dep_b_t(u8 *buf, size_t len, const sbp_packed_obs_content_dep_b_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_packed_obs_content_dep_b_t(msg) > len) { return false; }
  
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->P);
  // NOLINTNEXTLINE
  offset += 4;
				
        
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
  return true;
}

static inline bool sbp_unpack_sbp_packed_obs_content_dep_b_t(const u8 *buf, size_t len, sbp_packed_obs_content_dep_b_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
      
  if (offset + 4 > len) { return false; }
  msg->P = sbp_unpack_u32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
			
      
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
  return true;
}

static inline size_t sbp_packed_size_sbp_packed_obs_content_dep_c_t(const sbp_packed_obs_content_dep_c_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				sizeof( msg->P )                                                                          
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
				sizeof( msg->sid.reserved ) );
}

static inline bool sbp_pack_sbp_packed_obs_content_dep_c_t(u8 *buf, size_t len, const sbp_packed_obs_content_dep_c_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_packed_obs_content_dep_c_t(msg) > len) { return false; }
  
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->P);
  // NOLINTNEXTLINE
  offset += 4;
				
        
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
  return true;
}

static inline bool sbp_unpack_sbp_packed_obs_content_dep_c_t(const u8 *buf, size_t len, sbp_packed_obs_content_dep_c_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
      
  if (offset + 4 > len) { return false; }
  msg->P = sbp_unpack_u32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
			
      
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
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_obs_dep_a_t(const sbp_msg_obs_dep_a_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				(                                                          
	0                                                                          
	  +
				(                                                          
	0                                                                          
	  +
				sizeof( msg->header.t.tow )                                                                          
	  +
				sizeof( msg->header.t.wn ) )                                                                          
	  +
				sizeof( msg->header.n_obs ) )                                                                          
	  +
	    (
			  msg->n_obs
			*
				(                                                          
	0                                                                          
	  +
				sizeof( msg->obs[0].P )                                                                          
	  +
				(                                                          
	0                                                                          
	  +
				sizeof( msg->obs[0].L.i )                                                                          
	  +
				sizeof( msg->obs[0].L.f ) )                                                                          
	  +
				sizeof( msg->obs[0].cn0 )                                                                          
	  +
				sizeof( msg->obs[0].lock )                                                                          
	  +
				sizeof( msg->obs[0].prn ) )
			);
}

static inline bool sbp_pack_sbp_msg_obs_dep_a_t(u8 *buf, size_t len, const sbp_msg_obs_dep_a_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_obs_dep_a_t(msg) > len) { return false; }
  
				
				
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->header.t.tow);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->header.t.wn);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->header.n_obs , 1);
  // NOLINTNEXTLINE
  offset += 1;
			for(size_t msgobs_idx = 0; msgobs_idx < (size_t)msg->n_obs; msgobs_idx++)
			{
					
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->obs[msgobs_idx].P);
  // NOLINTNEXTLINE
  offset += 4;
				
        
  if (offset + 4 > len) { return false; }
  sbp_pack_s32(buf + offset, msg->obs[msgobs_idx].L.i);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->obs[msgobs_idx].L.f , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->obs[msgobs_idx].cn0 , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->obs[msgobs_idx].lock);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->obs[msgobs_idx].prn , 1);
  // NOLINTNEXTLINE
  offset += 1;
			}
  return true;
}

static inline bool sbp_unpack_sbp_msg_obs_dep_a_t(const u8 *buf, size_t len, sbp_msg_obs_dep_a_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
			
			
      
  if (offset + 4 > len) { return false; }
  msg->header.t.tow = sbp_unpack_u32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 2 > len) { return false; }
  msg->header.t.wn = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->header.n_obs, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      msg->n_obs = (u8)((len - offset) / 13);

	  for (size_t msgobs_idx = 0; msgobs_idx <
				msg->n_obs;
				msgobs_idx++) 
		{
				
      
  if (offset + 4 > len) { return false; }
  msg->obs[msgobs_idx].P = sbp_unpack_u32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
			
      
  if (offset + 4 > len) { return false; }
  msg->obs[msgobs_idx].L.i = sbp_unpack_s32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->obs[msgobs_idx].L.f, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->obs[msgobs_idx].cn0, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 2 > len) { return false; }
  msg->obs[msgobs_idx].lock = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->obs[msgobs_idx].prn, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
		}
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_obs_dep_b_t(const sbp_msg_obs_dep_b_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				(                                                          
	0                                                                          
	  +
				(                                                          
	0                                                                          
	  +
				sizeof( msg->header.t.tow )                                                                          
	  +
				sizeof( msg->header.t.wn ) )                                                                          
	  +
				sizeof( msg->header.n_obs ) )                                                                          
	  +
	    (
			  msg->n_obs
			*
				(                                                          
	0                                                                          
	  +
				sizeof( msg->obs[0].P )                                                                          
	  +
				(                                                          
	0                                                                          
	  +
				sizeof( msg->obs[0].L.i )                                                                          
	  +
				sizeof( msg->obs[0].L.f ) )                                                                          
	  +
				sizeof( msg->obs[0].cn0 )                                                                          
	  +
				sizeof( msg->obs[0].lock )                                                                          
	  +
				(                                                          
	0                                                                          
	  +
				sizeof( msg->obs[0].sid.sat )                                                                          
	  +
				sizeof( msg->obs[0].sid.code )                                                                          
	  +
				sizeof( msg->obs[0].sid.reserved ) ) )
			);
}

static inline bool sbp_pack_sbp_msg_obs_dep_b_t(u8 *buf, size_t len, const sbp_msg_obs_dep_b_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_obs_dep_b_t(msg) > len) { return false; }
  
				
				
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->header.t.tow);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->header.t.wn);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->header.n_obs , 1);
  // NOLINTNEXTLINE
  offset += 1;
			for(size_t msgobs_idx = 0; msgobs_idx < (size_t)msg->n_obs; msgobs_idx++)
			{
					
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->obs[msgobs_idx].P);
  // NOLINTNEXTLINE
  offset += 4;
				
        
  if (offset + 4 > len) { return false; }
  sbp_pack_s32(buf + offset, msg->obs[msgobs_idx].L.i);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->obs[msgobs_idx].L.f , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->obs[msgobs_idx].cn0 , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->obs[msgobs_idx].lock);
  // NOLINTNEXTLINE
  offset += 2;
				
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->obs[msgobs_idx].sid.sat);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->obs[msgobs_idx].sid.code , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->obs[msgobs_idx].sid.reserved , 1);
  // NOLINTNEXTLINE
  offset += 1;
			}
  return true;
}

static inline bool sbp_unpack_sbp_msg_obs_dep_b_t(const u8 *buf, size_t len, sbp_msg_obs_dep_b_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
			
			
      
  if (offset + 4 > len) { return false; }
  msg->header.t.tow = sbp_unpack_u32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 2 > len) { return false; }
  msg->header.t.wn = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->header.n_obs, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      msg->n_obs = (u8)((len - offset) / 16);

	  for (size_t msgobs_idx = 0; msgobs_idx <
				msg->n_obs;
				msgobs_idx++) 
		{
				
      
  if (offset + 4 > len) { return false; }
  msg->obs[msgobs_idx].P = sbp_unpack_u32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
			
      
  if (offset + 4 > len) { return false; }
  msg->obs[msgobs_idx].L.i = sbp_unpack_s32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->obs[msgobs_idx].L.f, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->obs[msgobs_idx].cn0, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 2 > len) { return false; }
  msg->obs[msgobs_idx].lock = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
			
      
  if (offset + 2 > len) { return false; }
  msg->obs[msgobs_idx].sid.sat = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->obs[msgobs_idx].sid.code, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->obs[msgobs_idx].sid.reserved, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
		}
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_obs_dep_c_t(const sbp_msg_obs_dep_c_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				(                                                          
	0                                                                          
	  +
				(                                                          
	0                                                                          
	  +
				sizeof( msg->header.t.tow )                                                                          
	  +
				sizeof( msg->header.t.wn ) )                                                                          
	  +
				sizeof( msg->header.n_obs ) )                                                                          
	  +
	    (
			  msg->n_obs
			*
				(                                                          
	0                                                                          
	  +
				sizeof( msg->obs[0].P )                                                                          
	  +
				(                                                          
	0                                                                          
	  +
				sizeof( msg->obs[0].L.i )                                                                          
	  +
				sizeof( msg->obs[0].L.f ) )                                                                          
	  +
				sizeof( msg->obs[0].cn0 )                                                                          
	  +
				sizeof( msg->obs[0].lock )                                                                          
	  +
				(                                                          
	0                                                                          
	  +
				sizeof( msg->obs[0].sid.sat )                                                                          
	  +
				sizeof( msg->obs[0].sid.code )                                                                          
	  +
				sizeof( msg->obs[0].sid.reserved ) ) )
			);
}

static inline bool sbp_pack_sbp_msg_obs_dep_c_t(u8 *buf, size_t len, const sbp_msg_obs_dep_c_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_obs_dep_c_t(msg) > len) { return false; }
  
				
				
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->header.t.tow);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->header.t.wn);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->header.n_obs , 1);
  // NOLINTNEXTLINE
  offset += 1;
			for(size_t msgobs_idx = 0; msgobs_idx < (size_t)msg->n_obs; msgobs_idx++)
			{
					
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->obs[msgobs_idx].P);
  // NOLINTNEXTLINE
  offset += 4;
				
        
  if (offset + 4 > len) { return false; }
  sbp_pack_s32(buf + offset, msg->obs[msgobs_idx].L.i);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->obs[msgobs_idx].L.f , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->obs[msgobs_idx].cn0 , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->obs[msgobs_idx].lock);
  // NOLINTNEXTLINE
  offset += 2;
				
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->obs[msgobs_idx].sid.sat);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->obs[msgobs_idx].sid.code , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->obs[msgobs_idx].sid.reserved , 1);
  // NOLINTNEXTLINE
  offset += 1;
			}
  return true;
}

static inline bool sbp_unpack_sbp_msg_obs_dep_c_t(const u8 *buf, size_t len, sbp_msg_obs_dep_c_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
			
			
      
  if (offset + 4 > len) { return false; }
  msg->header.t.tow = sbp_unpack_u32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 2 > len) { return false; }
  msg->header.t.wn = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->header.n_obs, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      msg->n_obs = (u8)((len - offset) / 16);

	  for (size_t msgobs_idx = 0; msgobs_idx <
				msg->n_obs;
				msgobs_idx++) 
		{
				
      
  if (offset + 4 > len) { return false; }
  msg->obs[msgobs_idx].P = sbp_unpack_u32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
			
      
  if (offset + 4 > len) { return false; }
  msg->obs[msgobs_idx].L.i = sbp_unpack_s32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->obs[msgobs_idx].L.f, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->obs[msgobs_idx].cn0, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 2 > len) { return false; }
  msg->obs[msgobs_idx].lock = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
			
      
  if (offset + 2 > len) { return false; }
  msg->obs[msgobs_idx].sid.sat = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->obs[msgobs_idx].sid.code, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->obs[msgobs_idx].sid.reserved, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
		}
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_iono_t(const sbp_msg_iono_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				(                                                          
	0                                                                          
	  +
				sizeof( msg->t_nmct.tow )                                                                          
	  +
				sizeof( msg->t_nmct.wn ) )                                                                          
	  +
				sizeof( msg->a0 )                                                                          
	  +
				sizeof( msg->a1 )                                                                          
	  +
				sizeof( msg->a2 )                                                                          
	  +
				sizeof( msg->a3 )                                                                          
	  +
				sizeof( msg->b0 )                                                                          
	  +
				sizeof( msg->b1 )                                                                          
	  +
				sizeof( msg->b2 )                                                                          
	  +
				sizeof( msg->b3 );
}

static inline bool sbp_pack_sbp_msg_iono_t(u8 *buf, size_t len, const sbp_msg_iono_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_iono_t(msg) > len) { return false; }
  
				
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->t_nmct.tow);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->t_nmct.wn);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->a0 , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->a1 , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->a2 , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->a3 , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->b0 , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->b1 , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->b2 , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->b3 , 8);
  // NOLINTNEXTLINE
  offset += 8;
  return true;
}

static inline bool sbp_unpack_sbp_msg_iono_t(const u8 *buf, size_t len, sbp_msg_iono_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
			
      
  if (offset + 4 > len) { return false; }
  msg->t_nmct.tow = sbp_unpack_u32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 2 > len) { return false; }
  msg->t_nmct.wn = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->a0, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->a1, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->a2, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->a3, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->b0, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->b1, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->b2, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->b3, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_sv_configuration_gps_dep_t(const sbp_msg_sv_configuration_gps_dep_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				(                                                          
	0                                                                          
	  +
				sizeof( msg->t_nmct.tow )                                                                          
	  +
				sizeof( msg->t_nmct.wn ) )                                                                          
	  +
				sizeof( msg->l2c_mask );
}

static inline bool sbp_pack_sbp_msg_sv_configuration_gps_dep_t(u8 *buf, size_t len, const sbp_msg_sv_configuration_gps_dep_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_sv_configuration_gps_dep_t(msg) > len) { return false; }
  
				
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->t_nmct.tow);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->t_nmct.wn);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->l2c_mask);
  // NOLINTNEXTLINE
  offset += 4;
  return true;
}

static inline bool sbp_unpack_sbp_msg_sv_configuration_gps_dep_t(const u8 *buf, size_t len, sbp_msg_sv_configuration_gps_dep_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
			
      
  if (offset + 4 > len) { return false; }
  msg->t_nmct.tow = sbp_unpack_u32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 2 > len) { return false; }
  msg->t_nmct.wn = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 4 > len) { return false; }
  msg->l2c_mask = sbp_unpack_u32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
  return true;
}

static inline size_t sbp_packed_size_sbp_gnss_capb_t(const sbp_gnss_capb_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				sizeof( msg->gps_active )                                                                          
	  +
				sizeof( msg->gps_l2c )                                                                          
	  +
				sizeof( msg->gps_l5 )                                                                          
	  +
				sizeof( msg->glo_active )                                                                          
	  +
				sizeof( msg->glo_l2of )                                                                          
	  +
				sizeof( msg->glo_l3 )                                                                          
	  +
				sizeof( msg->sbas_active )                                                                          
	  +
				sizeof( msg->sbas_l5 )                                                                          
	  +
				sizeof( msg->bds_active )                                                                          
	  +
				sizeof( msg->bds_d2nav )                                                                          
	  +
				sizeof( msg->bds_b2 )                                                                          
	  +
				sizeof( msg->bds_b2a )                                                                          
	  +
				sizeof( msg->qzss_active )                                                                          
	  +
				sizeof( msg->gal_active )                                                                          
	  +
				sizeof( msg->gal_e5 );
}

static inline bool sbp_pack_sbp_gnss_capb_t(u8 *buf, size_t len, const sbp_gnss_capb_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_gnss_capb_t(msg) > len) { return false; }
  
        
  if (offset + 8 > len) { return false; }
  sbp_pack_u64(buf + offset, msg->gps_active);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  sbp_pack_u64(buf + offset, msg->gps_l2c);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  sbp_pack_u64(buf + offset, msg->gps_l5);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->glo_active);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->glo_l2of);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->glo_l3);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 8 > len) { return false; }
  sbp_pack_u64(buf + offset, msg->sbas_active);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  sbp_pack_u64(buf + offset, msg->sbas_l5);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  sbp_pack_u64(buf + offset, msg->bds_active);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  sbp_pack_u64(buf + offset, msg->bds_d2nav);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  sbp_pack_u64(buf + offset, msg->bds_b2);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  sbp_pack_u64(buf + offset, msg->bds_b2a);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->qzss_active);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 8 > len) { return false; }
  sbp_pack_u64(buf + offset, msg->gal_active);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  sbp_pack_u64(buf + offset, msg->gal_e5);
  // NOLINTNEXTLINE
  offset += 8;
  return true;
}

static inline bool sbp_unpack_sbp_gnss_capb_t(const u8 *buf, size_t len, sbp_gnss_capb_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
      
  if (offset + 8 > len) { return false; }
  msg->gps_active = sbp_unpack_u64(buf + offset);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  msg->gps_l2c = sbp_unpack_u64(buf + offset);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  msg->gps_l5 = sbp_unpack_u64(buf + offset);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 4 > len) { return false; }
  msg->glo_active = sbp_unpack_u32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  msg->glo_l2of = sbp_unpack_u32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  msg->glo_l3 = sbp_unpack_u32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 8 > len) { return false; }
  msg->sbas_active = sbp_unpack_u64(buf + offset);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  msg->sbas_l5 = sbp_unpack_u64(buf + offset);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  msg->bds_active = sbp_unpack_u64(buf + offset);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  msg->bds_d2nav = sbp_unpack_u64(buf + offset);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  msg->bds_b2 = sbp_unpack_u64(buf + offset);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  msg->bds_b2a = sbp_unpack_u64(buf + offset);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 4 > len) { return false; }
  msg->qzss_active = sbp_unpack_u32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 8 > len) { return false; }
  msg->gal_active = sbp_unpack_u64(buf + offset);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  msg->gal_e5 = sbp_unpack_u64(buf + offset);
  // NOLINTNEXTLINE
  offset += 8;
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_gnss_capb_t(const sbp_msg_gnss_capb_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				(                                                          
	0                                                                          
	  +
				sizeof( msg->t_nmct.tow )                                                                          
	  +
				sizeof( msg->t_nmct.wn ) )                                                                          
	  +
				(                                                          
	0                                                                          
	  +
				sizeof( msg->gc.gps_active )                                                                          
	  +
				sizeof( msg->gc.gps_l2c )                                                                          
	  +
				sizeof( msg->gc.gps_l5 )                                                                          
	  +
				sizeof( msg->gc.glo_active )                                                                          
	  +
				sizeof( msg->gc.glo_l2of )                                                                          
	  +
				sizeof( msg->gc.glo_l3 )                                                                          
	  +
				sizeof( msg->gc.sbas_active )                                                                          
	  +
				sizeof( msg->gc.sbas_l5 )                                                                          
	  +
				sizeof( msg->gc.bds_active )                                                                          
	  +
				sizeof( msg->gc.bds_d2nav )                                                                          
	  +
				sizeof( msg->gc.bds_b2 )                                                                          
	  +
				sizeof( msg->gc.bds_b2a )                                                                          
	  +
				sizeof( msg->gc.qzss_active )                                                                          
	  +
				sizeof( msg->gc.gal_active )                                                                          
	  +
				sizeof( msg->gc.gal_e5 ) );
}

static inline bool sbp_pack_sbp_msg_gnss_capb_t(u8 *buf, size_t len, const sbp_msg_gnss_capb_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_gnss_capb_t(msg) > len) { return false; }
  
				
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->t_nmct.tow);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->t_nmct.wn);
  // NOLINTNEXTLINE
  offset += 2;
				
        
  if (offset + 8 > len) { return false; }
  sbp_pack_u64(buf + offset, msg->gc.gps_active);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  sbp_pack_u64(buf + offset, msg->gc.gps_l2c);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  sbp_pack_u64(buf + offset, msg->gc.gps_l5);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->gc.glo_active);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->gc.glo_l2of);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->gc.glo_l3);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 8 > len) { return false; }
  sbp_pack_u64(buf + offset, msg->gc.sbas_active);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  sbp_pack_u64(buf + offset, msg->gc.sbas_l5);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  sbp_pack_u64(buf + offset, msg->gc.bds_active);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  sbp_pack_u64(buf + offset, msg->gc.bds_d2nav);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  sbp_pack_u64(buf + offset, msg->gc.bds_b2);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  sbp_pack_u64(buf + offset, msg->gc.bds_b2a);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->gc.qzss_active);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 8 > len) { return false; }
  sbp_pack_u64(buf + offset, msg->gc.gal_active);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  sbp_pack_u64(buf + offset, msg->gc.gal_e5);
  // NOLINTNEXTLINE
  offset += 8;
  return true;
}

static inline bool sbp_unpack_sbp_msg_gnss_capb_t(const u8 *buf, size_t len, sbp_msg_gnss_capb_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
			
      
  if (offset + 4 > len) { return false; }
  msg->t_nmct.tow = sbp_unpack_u32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 2 > len) { return false; }
  msg->t_nmct.wn = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
			
      
  if (offset + 8 > len) { return false; }
  msg->gc.gps_active = sbp_unpack_u64(buf + offset);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  msg->gc.gps_l2c = sbp_unpack_u64(buf + offset);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  msg->gc.gps_l5 = sbp_unpack_u64(buf + offset);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 4 > len) { return false; }
  msg->gc.glo_active = sbp_unpack_u32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  msg->gc.glo_l2of = sbp_unpack_u32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  msg->gc.glo_l3 = sbp_unpack_u32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 8 > len) { return false; }
  msg->gc.sbas_active = sbp_unpack_u64(buf + offset);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  msg->gc.sbas_l5 = sbp_unpack_u64(buf + offset);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  msg->gc.bds_active = sbp_unpack_u64(buf + offset);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  msg->gc.bds_d2nav = sbp_unpack_u64(buf + offset);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  msg->gc.bds_b2 = sbp_unpack_u64(buf + offset);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  msg->gc.bds_b2a = sbp_unpack_u64(buf + offset);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 4 > len) { return false; }
  msg->gc.qzss_active = sbp_unpack_u32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 8 > len) { return false; }
  msg->gc.gal_active = sbp_unpack_u64(buf + offset);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  msg->gc.gal_e5 = sbp_unpack_u64(buf + offset);
  // NOLINTNEXTLINE
  offset += 8;
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_group_delay_dep_a_t(const sbp_msg_group_delay_dep_a_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				(                                                          
	0                                                                          
	  +
				sizeof( msg->t_op.tow )                                                                          
	  +
				sizeof( msg->t_op.wn ) )                                                                          
	  +
				sizeof( msg->prn )                                                                          
	  +
				sizeof( msg->valid )                                                                          
	  +
				sizeof( msg->tgd )                                                                          
	  +
				sizeof( msg->isc_l1ca )                                                                          
	  +
				sizeof( msg->isc_l2c );
}

static inline bool sbp_pack_sbp_msg_group_delay_dep_a_t(u8 *buf, size_t len, const sbp_msg_group_delay_dep_a_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_group_delay_dep_a_t(msg) > len) { return false; }
  
				
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->t_op.tow);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->t_op.wn);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->prn , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->valid , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_s16(buf + offset, msg->tgd);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_s16(buf + offset, msg->isc_l1ca);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_s16(buf + offset, msg->isc_l2c);
  // NOLINTNEXTLINE
  offset += 2;
  return true;
}

static inline bool sbp_unpack_sbp_msg_group_delay_dep_a_t(const u8 *buf, size_t len, sbp_msg_group_delay_dep_a_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
			
      
  if (offset + 4 > len) { return false; }
  msg->t_op.tow = sbp_unpack_u32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 2 > len) { return false; }
  msg->t_op.wn = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->prn, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->valid, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 2 > len) { return false; }
  msg->tgd = sbp_unpack_s16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 2 > len) { return false; }
  msg->isc_l1ca = sbp_unpack_s16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 2 > len) { return false; }
  msg->isc_l2c = sbp_unpack_s16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_group_delay_dep_b_t(const sbp_msg_group_delay_dep_b_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				(                                                          
	0                                                                          
	  +
				sizeof( msg->t_op.tow )                                                                          
	  +
				sizeof( msg->t_op.wn ) )                                                                          
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
				sizeof( msg->valid )                                                                          
	  +
				sizeof( msg->tgd )                                                                          
	  +
				sizeof( msg->isc_l1ca )                                                                          
	  +
				sizeof( msg->isc_l2c );
}

static inline bool sbp_pack_sbp_msg_group_delay_dep_b_t(u8 *buf, size_t len, const sbp_msg_group_delay_dep_b_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_group_delay_dep_b_t(msg) > len) { return false; }
  
				
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->t_op.tow);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->t_op.wn);
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
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->valid , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_s16(buf + offset, msg->tgd);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_s16(buf + offset, msg->isc_l1ca);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_s16(buf + offset, msg->isc_l2c);
  // NOLINTNEXTLINE
  offset += 2;
  return true;
}

static inline bool sbp_unpack_sbp_msg_group_delay_dep_b_t(const u8 *buf, size_t len, sbp_msg_group_delay_dep_b_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
			
      
  if (offset + 4 > len) { return false; }
  msg->t_op.tow = sbp_unpack_u32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 2 > len) { return false; }
  msg->t_op.wn = sbp_unpack_u16(buf + offset);
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
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->valid, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 2 > len) { return false; }
  msg->tgd = sbp_unpack_s16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 2 > len) { return false; }
  msg->isc_l1ca = sbp_unpack_s16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 2 > len) { return false; }
  msg->isc_l2c = sbp_unpack_s16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_group_delay_t(const sbp_msg_group_delay_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				(                                                          
	0                                                                          
	  +
				sizeof( msg->t_op.tow )                                                                          
	  +
				sizeof( msg->t_op.wn ) )                                                                          
	  +
				(                                                          
	0                                                                          
	  +
				sizeof( msg->sid.sat )                                                                          
	  +
				sizeof( msg->sid.code ) )                                                                          
	  +
				sizeof( msg->valid )                                                                          
	  +
				sizeof( msg->tgd )                                                                          
	  +
				sizeof( msg->isc_l1ca )                                                                          
	  +
				sizeof( msg->isc_l2c );
}

static inline bool sbp_pack_sbp_msg_group_delay_t(u8 *buf, size_t len, const sbp_msg_group_delay_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_group_delay_t(msg) > len) { return false; }
  
				
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->t_op.tow);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->t_op.wn);
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
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->valid , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_s16(buf + offset, msg->tgd);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_s16(buf + offset, msg->isc_l1ca);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_s16(buf + offset, msg->isc_l2c);
  // NOLINTNEXTLINE
  offset += 2;
  return true;
}

static inline bool sbp_unpack_sbp_msg_group_delay_t(const u8 *buf, size_t len, sbp_msg_group_delay_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
			
      
  if (offset + 4 > len) { return false; }
  msg->t_op.tow = sbp_unpack_u32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 2 > len) { return false; }
  msg->t_op.wn = sbp_unpack_u16(buf + offset);
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
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->valid, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 2 > len) { return false; }
  msg->tgd = sbp_unpack_s16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 2 > len) { return false; }
  msg->isc_l1ca = sbp_unpack_s16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 2 > len) { return false; }
  msg->isc_l2c = sbp_unpack_s16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
  return true;
}

static inline size_t sbp_packed_size_sbp_almanac_common_content_t(const sbp_almanac_common_content_t *msg) {                                
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
				(                                                          
	0                                                                          
	  +
				sizeof( msg->toa.tow )                                                                          
	  +
				sizeof( msg->toa.wn ) )                                                                          
	  +
				sizeof( msg->ura )                                                                          
	  +
				sizeof( msg->fit_interval )                                                                          
	  +
				sizeof( msg->valid )                                                                          
	  +
				sizeof( msg->health_bits );
}

static inline bool sbp_pack_sbp_almanac_common_content_t(u8 *buf, size_t len, const sbp_almanac_common_content_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_almanac_common_content_t(msg) > len) { return false; }
  
				
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->sid.sat , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->sid.code , 1);
  // NOLINTNEXTLINE
  offset += 1;
				
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->toa.tow);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->toa.wn);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->ura , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->fit_interval);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->valid , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->health_bits , 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline bool sbp_unpack_sbp_almanac_common_content_t(const u8 *buf, size_t len, sbp_almanac_common_content_t *msg) {
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
			
      
  if (offset + 4 > len) { return false; }
  msg->toa.tow = sbp_unpack_u32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 2 > len) { return false; }
  msg->toa.wn = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->ura, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 4 > len) { return false; }
  msg->fit_interval = sbp_unpack_u32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->valid, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->health_bits, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline size_t sbp_packed_size_sbp_almanac_common_content_dep_t(const sbp_almanac_common_content_dep_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
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
				(                                                          
	0                                                                          
	  +
				sizeof( msg->toa.tow )                                                                          
	  +
				sizeof( msg->toa.wn ) )                                                                          
	  +
				sizeof( msg->ura )                                                                          
	  +
				sizeof( msg->fit_interval )                                                                          
	  +
				sizeof( msg->valid )                                                                          
	  +
				sizeof( msg->health_bits );
}

static inline bool sbp_pack_sbp_almanac_common_content_dep_t(u8 *buf, size_t len, const sbp_almanac_common_content_dep_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_almanac_common_content_dep_t(msg) > len) { return false; }
  
				
        
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
  sbp_pack_u32(buf + offset, msg->toa.tow);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->toa.wn);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->ura , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->fit_interval);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->valid , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->health_bits , 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline bool sbp_unpack_sbp_almanac_common_content_dep_t(const u8 *buf, size_t len, sbp_almanac_common_content_dep_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
			
      
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
  msg->toa.tow = sbp_unpack_u32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 2 > len) { return false; }
  msg->toa.wn = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->ura, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 4 > len) { return false; }
  msg->fit_interval = sbp_unpack_u32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->valid, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->health_bits, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_almanac_gps_dep_t(const sbp_msg_almanac_gps_dep_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				(                                                          
	0                                                                          
	  +
				(                                                          
	0                                                                          
	  +
				sizeof( msg->common.sid.sat )                                                                          
	  +
				sizeof( msg->common.sid.code )                                                                          
	  +
				sizeof( msg->common.sid.reserved ) )                                                                          
	  +
				(                                                          
	0                                                                          
	  +
				sizeof( msg->common.toa.tow )                                                                          
	  +
				sizeof( msg->common.toa.wn ) )                                                                          
	  +
				sizeof( msg->common.ura )                                                                          
	  +
				sizeof( msg->common.fit_interval )                                                                          
	  +
				sizeof( msg->common.valid )                                                                          
	  +
				sizeof( msg->common.health_bits ) )                                                                          
	  +
				sizeof( msg->m0 )                                                                          
	  +
				sizeof( msg->ecc )                                                                          
	  +
				sizeof( msg->sqrta )                                                                          
	  +
				sizeof( msg->omega0 )                                                                          
	  +
				sizeof( msg->omegadot )                                                                          
	  +
				sizeof( msg->w )                                                                          
	  +
				sizeof( msg->inc )                                                                          
	  +
				sizeof( msg->af0 )                                                                          
	  +
				sizeof( msg->af1 );
}

static inline bool sbp_pack_sbp_msg_almanac_gps_dep_t(u8 *buf, size_t len, const sbp_msg_almanac_gps_dep_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_almanac_gps_dep_t(msg) > len) { return false; }
  
				
				
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->common.sid.sat);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->common.sid.code , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->common.sid.reserved , 1);
  // NOLINTNEXTLINE
  offset += 1;
				
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->common.toa.tow);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->common.toa.wn);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->common.ura , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->common.fit_interval);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->common.valid , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->common.health_bits , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->m0 , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->ecc , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->sqrta , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->omega0 , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->omegadot , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->w , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->inc , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->af0 , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->af1 , 8);
  // NOLINTNEXTLINE
  offset += 8;
  return true;
}

static inline bool sbp_unpack_sbp_msg_almanac_gps_dep_t(const u8 *buf, size_t len, sbp_msg_almanac_gps_dep_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
			
			
      
  if (offset + 2 > len) { return false; }
  msg->common.sid.sat = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->common.sid.code, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->common.sid.reserved, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
			
      
  if (offset + 4 > len) { return false; }
  msg->common.toa.tow = sbp_unpack_u32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 2 > len) { return false; }
  msg->common.toa.wn = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->common.ura, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 4 > len) { return false; }
  msg->common.fit_interval = sbp_unpack_u32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->common.valid, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->common.health_bits, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->m0, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->ecc, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->sqrta, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->omega0, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->omegadot, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->w, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->inc, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->af0, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->af1, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_almanac_gps_t(const sbp_msg_almanac_gps_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				(                                                          
	0                                                                          
	  +
				(                                                          
	0                                                                          
	  +
				sizeof( msg->common.sid.sat )                                                                          
	  +
				sizeof( msg->common.sid.code ) )                                                                          
	  +
				(                                                          
	0                                                                          
	  +
				sizeof( msg->common.toa.tow )                                                                          
	  +
				sizeof( msg->common.toa.wn ) )                                                                          
	  +
				sizeof( msg->common.ura )                                                                          
	  +
				sizeof( msg->common.fit_interval )                                                                          
	  +
				sizeof( msg->common.valid )                                                                          
	  +
				sizeof( msg->common.health_bits ) )                                                                          
	  +
				sizeof( msg->m0 )                                                                          
	  +
				sizeof( msg->ecc )                                                                          
	  +
				sizeof( msg->sqrta )                                                                          
	  +
				sizeof( msg->omega0 )                                                                          
	  +
				sizeof( msg->omegadot )                                                                          
	  +
				sizeof( msg->w )                                                                          
	  +
				sizeof( msg->inc )                                                                          
	  +
				sizeof( msg->af0 )                                                                          
	  +
				sizeof( msg->af1 );
}

static inline bool sbp_pack_sbp_msg_almanac_gps_t(u8 *buf, size_t len, const sbp_msg_almanac_gps_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_almanac_gps_t(msg) > len) { return false; }
  
				
				
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->common.sid.sat , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->common.sid.code , 1);
  // NOLINTNEXTLINE
  offset += 1;
				
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->common.toa.tow);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->common.toa.wn);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->common.ura , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->common.fit_interval);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->common.valid , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->common.health_bits , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->m0 , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->ecc , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->sqrta , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->omega0 , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->omegadot , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->w , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->inc , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->af0 , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->af1 , 8);
  // NOLINTNEXTLINE
  offset += 8;
  return true;
}

static inline bool sbp_unpack_sbp_msg_almanac_gps_t(const u8 *buf, size_t len, sbp_msg_almanac_gps_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
			
			
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->common.sid.sat, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->common.sid.code, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
			
      
  if (offset + 4 > len) { return false; }
  msg->common.toa.tow = sbp_unpack_u32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 2 > len) { return false; }
  msg->common.toa.wn = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->common.ura, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 4 > len) { return false; }
  msg->common.fit_interval = sbp_unpack_u32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->common.valid, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->common.health_bits, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->m0, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->ecc, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->sqrta, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->omega0, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->omegadot, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->w, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->inc, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->af0, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->af1, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_almanac_glo_dep_t(const sbp_msg_almanac_glo_dep_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				(                                                          
	0                                                                          
	  +
				(                                                          
	0                                                                          
	  +
				sizeof( msg->common.sid.sat )                                                                          
	  +
				sizeof( msg->common.sid.code )                                                                          
	  +
				sizeof( msg->common.sid.reserved ) )                                                                          
	  +
				(                                                          
	0                                                                          
	  +
				sizeof( msg->common.toa.tow )                                                                          
	  +
				sizeof( msg->common.toa.wn ) )                                                                          
	  +
				sizeof( msg->common.ura )                                                                          
	  +
				sizeof( msg->common.fit_interval )                                                                          
	  +
				sizeof( msg->common.valid )                                                                          
	  +
				sizeof( msg->common.health_bits ) )                                                                          
	  +
				sizeof( msg->lambda_na )                                                                          
	  +
				sizeof( msg->t_lambda_na )                                                                          
	  +
				sizeof( msg->i )                                                                          
	  +
				sizeof( msg->t )                                                                          
	  +
				sizeof( msg->t_dot )                                                                          
	  +
				sizeof( msg->epsilon )                                                                          
	  +
				sizeof( msg->omega );
}

static inline bool sbp_pack_sbp_msg_almanac_glo_dep_t(u8 *buf, size_t len, const sbp_msg_almanac_glo_dep_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_almanac_glo_dep_t(msg) > len) { return false; }
  
				
				
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->common.sid.sat);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->common.sid.code , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->common.sid.reserved , 1);
  // NOLINTNEXTLINE
  offset += 1;
				
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->common.toa.tow);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->common.toa.wn);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->common.ura , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->common.fit_interval);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->common.valid , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->common.health_bits , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->lambda_na , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->t_lambda_na , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->i , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->t , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->t_dot , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->epsilon , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->omega , 8);
  // NOLINTNEXTLINE
  offset += 8;
  return true;
}

static inline bool sbp_unpack_sbp_msg_almanac_glo_dep_t(const u8 *buf, size_t len, sbp_msg_almanac_glo_dep_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
			
			
      
  if (offset + 2 > len) { return false; }
  msg->common.sid.sat = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->common.sid.code, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->common.sid.reserved, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
			
      
  if (offset + 4 > len) { return false; }
  msg->common.toa.tow = sbp_unpack_u32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 2 > len) { return false; }
  msg->common.toa.wn = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->common.ura, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 4 > len) { return false; }
  msg->common.fit_interval = sbp_unpack_u32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->common.valid, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->common.health_bits, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->lambda_na, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->t_lambda_na, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->i, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->t, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->t_dot, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->epsilon, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->omega, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_almanac_glo_t(const sbp_msg_almanac_glo_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				(                                                          
	0                                                                          
	  +
				(                                                          
	0                                                                          
	  +
				sizeof( msg->common.sid.sat )                                                                          
	  +
				sizeof( msg->common.sid.code ) )                                                                          
	  +
				(                                                          
	0                                                                          
	  +
				sizeof( msg->common.toa.tow )                                                                          
	  +
				sizeof( msg->common.toa.wn ) )                                                                          
	  +
				sizeof( msg->common.ura )                                                                          
	  +
				sizeof( msg->common.fit_interval )                                                                          
	  +
				sizeof( msg->common.valid )                                                                          
	  +
				sizeof( msg->common.health_bits ) )                                                                          
	  +
				sizeof( msg->lambda_na )                                                                          
	  +
				sizeof( msg->t_lambda_na )                                                                          
	  +
				sizeof( msg->i )                                                                          
	  +
				sizeof( msg->t )                                                                          
	  +
				sizeof( msg->t_dot )                                                                          
	  +
				sizeof( msg->epsilon )                                                                          
	  +
				sizeof( msg->omega );
}

static inline bool sbp_pack_sbp_msg_almanac_glo_t(u8 *buf, size_t len, const sbp_msg_almanac_glo_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_almanac_glo_t(msg) > len) { return false; }
  
				
				
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->common.sid.sat , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->common.sid.code , 1);
  // NOLINTNEXTLINE
  offset += 1;
				
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->common.toa.tow);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->common.toa.wn);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->common.ura , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->common.fit_interval);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->common.valid , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->common.health_bits , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->lambda_na , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->t_lambda_na , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->i , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->t , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->t_dot , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->epsilon , 8);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  memcpy(buf + offset, & msg->omega , 8);
  // NOLINTNEXTLINE
  offset += 8;
  return true;
}

static inline bool sbp_unpack_sbp_msg_almanac_glo_t(const u8 *buf, size_t len, sbp_msg_almanac_glo_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
			
			
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->common.sid.sat, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->common.sid.code, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
			
      
  if (offset + 4 > len) { return false; }
  msg->common.toa.tow = sbp_unpack_u32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 2 > len) { return false; }
  msg->common.toa.wn = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->common.ura, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 4 > len) { return false; }
  msg->common.fit_interval = sbp_unpack_u32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->common.valid, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->common.health_bits, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->lambda_na, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->t_lambda_na, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->i, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->t, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->t_dot, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->epsilon, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->omega, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_glo_biases_t(const sbp_msg_glo_biases_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				sizeof( msg->mask )                                                                          
	  +
				sizeof( msg->l1ca_bias )                                                                          
	  +
				sizeof( msg->l1p_bias )                                                                          
	  +
				sizeof( msg->l2ca_bias )                                                                          
	  +
				sizeof( msg->l2p_bias );
}

static inline bool sbp_pack_sbp_msg_glo_biases_t(u8 *buf, size_t len, const sbp_msg_glo_biases_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_glo_biases_t(msg) > len) { return false; }
  
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->mask , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_s16(buf + offset, msg->l1ca_bias);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_s16(buf + offset, msg->l1p_bias);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_s16(buf + offset, msg->l2ca_bias);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_s16(buf + offset, msg->l2p_bias);
  // NOLINTNEXTLINE
  offset += 2;
  return true;
}

static inline bool sbp_unpack_sbp_msg_glo_biases_t(const u8 *buf, size_t len, sbp_msg_glo_biases_t *msg) {
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
  msg->l1ca_bias = sbp_unpack_s16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 2 > len) { return false; }
  msg->l1p_bias = sbp_unpack_s16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 2 > len) { return false; }
  msg->l2ca_bias = sbp_unpack_s16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 2 > len) { return false; }
  msg->l2p_bias = sbp_unpack_s16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
  return true;
}

static inline size_t sbp_packed_size_sbp_sv_az_el_t(const sbp_sv_az_el_t *msg) {                                
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
				sizeof( msg->az )                                                                          
	  +
				sizeof( msg->el );
}

static inline bool sbp_pack_sbp_sv_az_el_t(u8 *buf, size_t len, const sbp_sv_az_el_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_sv_az_el_t(msg) > len) { return false; }
  
				
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->sid.sat , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->sid.code , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->az , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->el , 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline bool sbp_unpack_sbp_sv_az_el_t(const u8 *buf, size_t len, sbp_sv_az_el_t *msg) {
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
  memcpy(&msg->az, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->el, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_sv_az_el_t(const sbp_msg_sv_az_el_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
	    (
			  msg->n_azel
			*
				(                                                          
	0                                                                          
	  +
				(                                                          
	0                                                                          
	  +
				sizeof( msg->azel[0].sid.sat )                                                                          
	  +
				sizeof( msg->azel[0].sid.code ) )                                                                          
	  +
				sizeof( msg->azel[0].az )                                                                          
	  +
				sizeof( msg->azel[0].el ) )
			);
}

static inline bool sbp_pack_sbp_msg_sv_az_el_t(u8 *buf, size_t len, const sbp_msg_sv_az_el_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_sv_az_el_t(msg) > len) { return false; }
  
			for(size_t msgazel_idx = 0; msgazel_idx < (size_t)msg->n_azel; msgazel_idx++)
			{
					
				
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->azel[msgazel_idx].sid.sat , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->azel[msgazel_idx].sid.code , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->azel[msgazel_idx].az , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->azel[msgazel_idx].el , 1);
  // NOLINTNEXTLINE
  offset += 1;
			}
  return true;
}

static inline bool sbp_unpack_sbp_msg_sv_az_el_t(const u8 *buf, size_t len, sbp_msg_sv_az_el_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
      msg->n_azel = (u8)((len - offset) / 4);

	  for (size_t msgazel_idx = 0; msgazel_idx <
				msg->n_azel;
				msgazel_idx++) 
		{
				
			
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->azel[msgazel_idx].sid.sat, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->azel[msgazel_idx].sid.code, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->azel[msgazel_idx].az, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->azel[msgazel_idx].el, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
		}
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_osr_t(const sbp_msg_osr_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				(                                                          
	0                                                                          
	  +
				(                                                          
	0                                                                          
	  +
				sizeof( msg->header.t.tow )                                                                          
	  +
				sizeof( msg->header.t.ns_residual )                                                                          
	  +
				sizeof( msg->header.t.wn ) )                                                                          
	  +
				sizeof( msg->header.n_obs ) )                                                                          
	  +
	    (
			  msg->n_obs
			*
				(                                                          
	0                                                                          
	  +
				sizeof( msg->obs[0].P )                                                                          
	  +
				(                                                          
	0                                                                          
	  +
				sizeof( msg->obs[0].L.i )                                                                          
	  +
				sizeof( msg->obs[0].L.f ) )                                                                          
	  +
				sizeof( msg->obs[0].lock )                                                                          
	  +
				sizeof( msg->obs[0].flags )                                                                          
	  +
				(                                                          
	0                                                                          
	  +
				sizeof( msg->obs[0].sid.sat )                                                                          
	  +
				sizeof( msg->obs[0].sid.code ) )                                                                          
	  +
				sizeof( msg->obs[0].iono_std )                                                                          
	  +
				sizeof( msg->obs[0].tropo_std )                                                                          
	  +
				sizeof( msg->obs[0].range_std ) )
			);
}

static inline bool sbp_pack_sbp_msg_osr_t(u8 *buf, size_t len, const sbp_msg_osr_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_osr_t(msg) > len) { return false; }
  
				
				
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->header.t.tow);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  sbp_pack_s32(buf + offset, msg->header.t.ns_residual);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->header.t.wn);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->header.n_obs , 1);
  // NOLINTNEXTLINE
  offset += 1;
			for(size_t msgobs_idx = 0; msgobs_idx < (size_t)msg->n_obs; msgobs_idx++)
			{
					
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->obs[msgobs_idx].P);
  // NOLINTNEXTLINE
  offset += 4;
				
        
  if (offset + 4 > len) { return false; }
  sbp_pack_s32(buf + offset, msg->obs[msgobs_idx].L.i);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->obs[msgobs_idx].L.f , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->obs[msgobs_idx].lock , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->obs[msgobs_idx].flags , 1);
  // NOLINTNEXTLINE
  offset += 1;
				
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->obs[msgobs_idx].sid.sat , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->obs[msgobs_idx].sid.code , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->obs[msgobs_idx].iono_std);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->obs[msgobs_idx].tropo_std);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->obs[msgobs_idx].range_std);
  // NOLINTNEXTLINE
  offset += 2;
			}
  return true;
}

static inline bool sbp_unpack_sbp_msg_osr_t(const u8 *buf, size_t len, sbp_msg_osr_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
			
			
      
  if (offset + 4 > len) { return false; }
  msg->header.t.tow = sbp_unpack_u32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  msg->header.t.ns_residual = sbp_unpack_s32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 2 > len) { return false; }
  msg->header.t.wn = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->header.n_obs, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      msg->n_obs = (u8)((len - offset) / 19);

	  for (size_t msgobs_idx = 0; msgobs_idx <
				msg->n_obs;
				msgobs_idx++) 
		{
				
      
  if (offset + 4 > len) { return false; }
  msg->obs[msgobs_idx].P = sbp_unpack_u32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
			
      
  if (offset + 4 > len) { return false; }
  msg->obs[msgobs_idx].L.i = sbp_unpack_s32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->obs[msgobs_idx].L.f, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->obs[msgobs_idx].lock, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->obs[msgobs_idx].flags, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
			
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->obs[msgobs_idx].sid.sat, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->obs[msgobs_idx].sid.code, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 2 > len) { return false; }
  msg->obs[msgobs_idx].iono_std = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 2 > len) { return false; }
  msg->obs[msgobs_idx].tropo_std = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 2 > len) { return false; }
  msg->obs[msgobs_idx].range_std = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
		}
  return true;
}

#endif
