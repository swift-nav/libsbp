#ifndef LIBSBP_ACQUISITION_PACKERS_H
#define LIBSBP_ACQUISITION_PACKERS_H

#ifndef LIBSBP_ACQUISITION_MESSAGES_H
#error "Do not include this file directly, include libsbp/unpacked/acquisition.h instead"
#endif

#include <stdbool.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>
#include <math.h>

#include <libsbp/common.h>
#include <libsbp/string.h>

static inline size_t sbp_packed_size_sbp_msg_acq_result_t(const sbp_msg_acq_result_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				sizeof( msg->cn0 )                                                                          
	  +
				sizeof( msg->cp )                                                                          
	  +
				sizeof( msg->cf )                                                                          
	  +
				(                                                          
	0                                                                          
	  +
				sizeof( msg->sid.sat )                                                                          
	  +
				sizeof( msg->sid.code ) );
}

static inline bool sbp_pack_sbp_msg_acq_result_t(u8 *buf, size_t len, const sbp_msg_acq_result_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_acq_result_t(msg) > len) { return false; }
  
        
  if (offset + 4 > len) { return false; }
  memcpy(buf + offset, & msg->cn0 , 4);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  memcpy(buf + offset, & msg->cp , 4);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  memcpy(buf + offset, & msg->cf , 4);
  // NOLINTNEXTLINE
  offset += 4;
				
        
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

static inline bool sbp_unpack_sbp_msg_acq_result_t(const u8 *buf, size_t len, sbp_msg_acq_result_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->cn0, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->cp, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->cf, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;
			
      
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

static inline size_t sbp_packed_size_sbp_msg_acq_result_dep_c_t(const sbp_msg_acq_result_dep_c_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				sizeof( msg->cn0 )                                                                          
	  +
				sizeof( msg->cp )                                                                          
	  +
				sizeof( msg->cf )                                                                          
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

static inline bool sbp_pack_sbp_msg_acq_result_dep_c_t(u8 *buf, size_t len, const sbp_msg_acq_result_dep_c_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_acq_result_dep_c_t(msg) > len) { return false; }
  
        
  if (offset + 4 > len) { return false; }
  memcpy(buf + offset, & msg->cn0 , 4);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  memcpy(buf + offset, & msg->cp , 4);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  memcpy(buf + offset, & msg->cf , 4);
  // NOLINTNEXTLINE
  offset += 4;
				
        
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

static inline bool sbp_unpack_sbp_msg_acq_result_dep_c_t(const u8 *buf, size_t len, sbp_msg_acq_result_dep_c_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->cn0, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->cp, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->cf, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;
			
      
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

static inline size_t sbp_packed_size_sbp_msg_acq_result_dep_b_t(const sbp_msg_acq_result_dep_b_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				sizeof( msg->snr )                                                                          
	  +
				sizeof( msg->cp )                                                                          
	  +
				sizeof( msg->cf )                                                                          
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

static inline bool sbp_pack_sbp_msg_acq_result_dep_b_t(u8 *buf, size_t len, const sbp_msg_acq_result_dep_b_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_acq_result_dep_b_t(msg) > len) { return false; }
  
        
  if (offset + 4 > len) { return false; }
  memcpy(buf + offset, & msg->snr , 4);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  memcpy(buf + offset, & msg->cp , 4);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  memcpy(buf + offset, & msg->cf , 4);
  // NOLINTNEXTLINE
  offset += 4;
				
        
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

static inline bool sbp_unpack_sbp_msg_acq_result_dep_b_t(const u8 *buf, size_t len, sbp_msg_acq_result_dep_b_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->snr, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->cp, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->cf, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;
			
      
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

static inline size_t sbp_packed_size_sbp_msg_acq_result_dep_a_t(const sbp_msg_acq_result_dep_a_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				sizeof( msg->snr )                                                                          
	  +
				sizeof( msg->cp )                                                                          
	  +
				sizeof( msg->cf )                                                                          
	  +
				sizeof( msg->prn );
}

static inline bool sbp_pack_sbp_msg_acq_result_dep_a_t(u8 *buf, size_t len, const sbp_msg_acq_result_dep_a_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_acq_result_dep_a_t(msg) > len) { return false; }
  
        
  if (offset + 4 > len) { return false; }
  memcpy(buf + offset, & msg->snr , 4);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  memcpy(buf + offset, & msg->cp , 4);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  memcpy(buf + offset, & msg->cf , 4);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->prn , 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline bool sbp_unpack_sbp_msg_acq_result_dep_a_t(const u8 *buf, size_t len, sbp_msg_acq_result_dep_a_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->snr, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->cp, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->cf, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->prn, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline size_t sbp_packed_size_sbp_acq_sv_profile_t(const sbp_acq_sv_profile_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				sizeof( msg->job_type )                                                                          
	  +
				sizeof( msg->status )                                                                          
	  +
				sizeof( msg->cn0 )                                                                          
	  +
				sizeof( msg->int_time )                                                                          
	  +
				(                                                          
	0                                                                          
	  +
				sizeof( msg->sid.sat )                                                                          
	  +
				sizeof( msg->sid.code ) )                                                                          
	  +
				sizeof( msg->bin_width )                                                                          
	  +
				sizeof( msg->timestamp )                                                                          
	  +
				sizeof( msg->time_spent )                                                                          
	  +
				sizeof( msg->cf_min )                                                                          
	  +
				sizeof( msg->cf_max )                                                                          
	  +
				sizeof( msg->cf )                                                                          
	  +
				sizeof( msg->cp );
}

static inline bool sbp_pack_sbp_acq_sv_profile_t(u8 *buf, size_t len, const sbp_acq_sv_profile_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_acq_sv_profile_t(msg) > len) { return false; }
  
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->job_type , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->status , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->cn0);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->int_time , 1);
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
  sbp_pack_u16(buf + offset, msg->bin_width);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->timestamp);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->time_spent);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  sbp_pack_s32(buf + offset, msg->cf_min);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  sbp_pack_s32(buf + offset, msg->cf_max);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  sbp_pack_s32(buf + offset, msg->cf);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->cp);
  // NOLINTNEXTLINE
  offset += 4;
  return true;
}

static inline bool sbp_unpack_sbp_acq_sv_profile_t(const u8 *buf, size_t len, sbp_acq_sv_profile_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->job_type, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->status, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 2 > len) { return false; }
  msg->cn0 = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->int_time, buf + offset, 1);
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
  msg->bin_width = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 4 > len) { return false; }
  msg->timestamp = sbp_unpack_u32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  msg->time_spent = sbp_unpack_u32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  msg->cf_min = sbp_unpack_s32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  msg->cf_max = sbp_unpack_s32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  msg->cf = sbp_unpack_s32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  msg->cp = sbp_unpack_u32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
  return true;
}

static inline size_t sbp_packed_size_sbp_acq_sv_profile_dep_t(const sbp_acq_sv_profile_dep_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				sizeof( msg->job_type )                                                                          
	  +
				sizeof( msg->status )                                                                          
	  +
				sizeof( msg->cn0 )                                                                          
	  +
				sizeof( msg->int_time )                                                                          
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
				sizeof( msg->bin_width )                                                                          
	  +
				sizeof( msg->timestamp )                                                                          
	  +
				sizeof( msg->time_spent )                                                                          
	  +
				sizeof( msg->cf_min )                                                                          
	  +
				sizeof( msg->cf_max )                                                                          
	  +
				sizeof( msg->cf )                                                                          
	  +
				sizeof( msg->cp );
}

static inline bool sbp_pack_sbp_acq_sv_profile_dep_t(u8 *buf, size_t len, const sbp_acq_sv_profile_dep_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_acq_sv_profile_dep_t(msg) > len) { return false; }
  
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->job_type , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->status , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->cn0);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->int_time , 1);
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
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->bin_width);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->timestamp);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->time_spent);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  sbp_pack_s32(buf + offset, msg->cf_min);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  sbp_pack_s32(buf + offset, msg->cf_max);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  sbp_pack_s32(buf + offset, msg->cf);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->cp);
  // NOLINTNEXTLINE
  offset += 4;
  return true;
}

static inline bool sbp_unpack_sbp_acq_sv_profile_dep_t(const u8 *buf, size_t len, sbp_acq_sv_profile_dep_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->job_type, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->status, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 2 > len) { return false; }
  msg->cn0 = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->int_time, buf + offset, 1);
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
      
  if (offset + 2 > len) { return false; }
  msg->bin_width = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 4 > len) { return false; }
  msg->timestamp = sbp_unpack_u32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  msg->time_spent = sbp_unpack_u32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  msg->cf_min = sbp_unpack_s32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  msg->cf_max = sbp_unpack_s32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  msg->cf = sbp_unpack_s32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  msg->cp = sbp_unpack_u32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_acq_sv_profile_t(const sbp_msg_acq_sv_profile_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
	    (
			  msg->n_acq_sv_profile
			*
				(                                                          
	0                                                                          
	  +
				sizeof( msg->acq_sv_profile[0].job_type )                                                                          
	  +
				sizeof( msg->acq_sv_profile[0].status )                                                                          
	  +
				sizeof( msg->acq_sv_profile[0].cn0 )                                                                          
	  +
				sizeof( msg->acq_sv_profile[0].int_time )                                                                          
	  +
				(                                                          
	0                                                                          
	  +
				sizeof( msg->acq_sv_profile[0].sid.sat )                                                                          
	  +
				sizeof( msg->acq_sv_profile[0].sid.code ) )                                                                          
	  +
				sizeof( msg->acq_sv_profile[0].bin_width )                                                                          
	  +
				sizeof( msg->acq_sv_profile[0].timestamp )                                                                          
	  +
				sizeof( msg->acq_sv_profile[0].time_spent )                                                                          
	  +
				sizeof( msg->acq_sv_profile[0].cf_min )                                                                          
	  +
				sizeof( msg->acq_sv_profile[0].cf_max )                                                                          
	  +
				sizeof( msg->acq_sv_profile[0].cf )                                                                          
	  +
				sizeof( msg->acq_sv_profile[0].cp ) )
			);
}

static inline bool sbp_pack_sbp_msg_acq_sv_profile_t(u8 *buf, size_t len, const sbp_msg_acq_sv_profile_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_acq_sv_profile_t(msg) > len) { return false; }
  
			for(size_t msgacq_sv_profile_idx = 0; msgacq_sv_profile_idx < (size_t)msg->n_acq_sv_profile; msgacq_sv_profile_idx++)
			{
					
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->acq_sv_profile[msgacq_sv_profile_idx].job_type , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->acq_sv_profile[msgacq_sv_profile_idx].status , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->acq_sv_profile[msgacq_sv_profile_idx].cn0);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->acq_sv_profile[msgacq_sv_profile_idx].int_time , 1);
  // NOLINTNEXTLINE
  offset += 1;
				
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->acq_sv_profile[msgacq_sv_profile_idx].sid.sat , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->acq_sv_profile[msgacq_sv_profile_idx].sid.code , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->acq_sv_profile[msgacq_sv_profile_idx].bin_width);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->acq_sv_profile[msgacq_sv_profile_idx].timestamp);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->acq_sv_profile[msgacq_sv_profile_idx].time_spent);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  sbp_pack_s32(buf + offset, msg->acq_sv_profile[msgacq_sv_profile_idx].cf_min);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  sbp_pack_s32(buf + offset, msg->acq_sv_profile[msgacq_sv_profile_idx].cf_max);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  sbp_pack_s32(buf + offset, msg->acq_sv_profile[msgacq_sv_profile_idx].cf);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->acq_sv_profile[msgacq_sv_profile_idx].cp);
  // NOLINTNEXTLINE
  offset += 4;
			}
  return true;
}

static inline bool sbp_unpack_sbp_msg_acq_sv_profile_t(const u8 *buf, size_t len, sbp_msg_acq_sv_profile_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
      msg->n_acq_sv_profile = (u8)((len - offset) / 33);

	  for (size_t msgacq_sv_profile_idx = 0; msgacq_sv_profile_idx <
				msg->n_acq_sv_profile;
				msgacq_sv_profile_idx++) 
		{
				
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->acq_sv_profile[msgacq_sv_profile_idx].job_type, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->acq_sv_profile[msgacq_sv_profile_idx].status, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 2 > len) { return false; }
  msg->acq_sv_profile[msgacq_sv_profile_idx].cn0 = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->acq_sv_profile[msgacq_sv_profile_idx].int_time, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
			
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->acq_sv_profile[msgacq_sv_profile_idx].sid.sat, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->acq_sv_profile[msgacq_sv_profile_idx].sid.code, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 2 > len) { return false; }
  msg->acq_sv_profile[msgacq_sv_profile_idx].bin_width = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 4 > len) { return false; }
  msg->acq_sv_profile[msgacq_sv_profile_idx].timestamp = sbp_unpack_u32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  msg->acq_sv_profile[msgacq_sv_profile_idx].time_spent = sbp_unpack_u32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  msg->acq_sv_profile[msgacq_sv_profile_idx].cf_min = sbp_unpack_s32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  msg->acq_sv_profile[msgacq_sv_profile_idx].cf_max = sbp_unpack_s32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  msg->acq_sv_profile[msgacq_sv_profile_idx].cf = sbp_unpack_s32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  msg->acq_sv_profile[msgacq_sv_profile_idx].cp = sbp_unpack_u32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
		}
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_acq_sv_profile_dep_t(const sbp_msg_acq_sv_profile_dep_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
	    (
			  msg->n_acq_sv_profile
			*
				(                                                          
	0                                                                          
	  +
				sizeof( msg->acq_sv_profile[0].job_type )                                                                          
	  +
				sizeof( msg->acq_sv_profile[0].status )                                                                          
	  +
				sizeof( msg->acq_sv_profile[0].cn0 )                                                                          
	  +
				sizeof( msg->acq_sv_profile[0].int_time )                                                                          
	  +
				(                                                          
	0                                                                          
	  +
				sizeof( msg->acq_sv_profile[0].sid.sat )                                                                          
	  +
				sizeof( msg->acq_sv_profile[0].sid.code )                                                                          
	  +
				sizeof( msg->acq_sv_profile[0].sid.reserved ) )                                                                          
	  +
				sizeof( msg->acq_sv_profile[0].bin_width )                                                                          
	  +
				sizeof( msg->acq_sv_profile[0].timestamp )                                                                          
	  +
				sizeof( msg->acq_sv_profile[0].time_spent )                                                                          
	  +
				sizeof( msg->acq_sv_profile[0].cf_min )                                                                          
	  +
				sizeof( msg->acq_sv_profile[0].cf_max )                                                                          
	  +
				sizeof( msg->acq_sv_profile[0].cf )                                                                          
	  +
				sizeof( msg->acq_sv_profile[0].cp ) )
			);
}

static inline bool sbp_pack_sbp_msg_acq_sv_profile_dep_t(u8 *buf, size_t len, const sbp_msg_acq_sv_profile_dep_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_acq_sv_profile_dep_t(msg) > len) { return false; }
  
			for(size_t msgacq_sv_profile_idx = 0; msgacq_sv_profile_idx < (size_t)msg->n_acq_sv_profile; msgacq_sv_profile_idx++)
			{
					
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->acq_sv_profile[msgacq_sv_profile_idx].job_type , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->acq_sv_profile[msgacq_sv_profile_idx].status , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->acq_sv_profile[msgacq_sv_profile_idx].cn0);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->acq_sv_profile[msgacq_sv_profile_idx].int_time , 1);
  // NOLINTNEXTLINE
  offset += 1;
				
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->acq_sv_profile[msgacq_sv_profile_idx].sid.sat);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->acq_sv_profile[msgacq_sv_profile_idx].sid.code , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->acq_sv_profile[msgacq_sv_profile_idx].sid.reserved , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->acq_sv_profile[msgacq_sv_profile_idx].bin_width);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->acq_sv_profile[msgacq_sv_profile_idx].timestamp);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->acq_sv_profile[msgacq_sv_profile_idx].time_spent);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  sbp_pack_s32(buf + offset, msg->acq_sv_profile[msgacq_sv_profile_idx].cf_min);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  sbp_pack_s32(buf + offset, msg->acq_sv_profile[msgacq_sv_profile_idx].cf_max);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  sbp_pack_s32(buf + offset, msg->acq_sv_profile[msgacq_sv_profile_idx].cf);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->acq_sv_profile[msgacq_sv_profile_idx].cp);
  // NOLINTNEXTLINE
  offset += 4;
			}
  return true;
}

static inline bool sbp_unpack_sbp_msg_acq_sv_profile_dep_t(const u8 *buf, size_t len, sbp_msg_acq_sv_profile_dep_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
      msg->n_acq_sv_profile = (u8)((len - offset) / 35);

	  for (size_t msgacq_sv_profile_idx = 0; msgacq_sv_profile_idx <
				msg->n_acq_sv_profile;
				msgacq_sv_profile_idx++) 
		{
				
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->acq_sv_profile[msgacq_sv_profile_idx].job_type, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->acq_sv_profile[msgacq_sv_profile_idx].status, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 2 > len) { return false; }
  msg->acq_sv_profile[msgacq_sv_profile_idx].cn0 = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->acq_sv_profile[msgacq_sv_profile_idx].int_time, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
			
      
  if (offset + 2 > len) { return false; }
  msg->acq_sv_profile[msgacq_sv_profile_idx].sid.sat = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->acq_sv_profile[msgacq_sv_profile_idx].sid.code, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->acq_sv_profile[msgacq_sv_profile_idx].sid.reserved, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 2 > len) { return false; }
  msg->acq_sv_profile[msgacq_sv_profile_idx].bin_width = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 4 > len) { return false; }
  msg->acq_sv_profile[msgacq_sv_profile_idx].timestamp = sbp_unpack_u32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  msg->acq_sv_profile[msgacq_sv_profile_idx].time_spent = sbp_unpack_u32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  msg->acq_sv_profile[msgacq_sv_profile_idx].cf_min = sbp_unpack_s32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  msg->acq_sv_profile[msgacq_sv_profile_idx].cf_max = sbp_unpack_s32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  msg->acq_sv_profile[msgacq_sv_profile_idx].cf = sbp_unpack_s32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  msg->acq_sv_profile[msgacq_sv_profile_idx].cp = sbp_unpack_u32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
		}
  return true;
}

#endif
