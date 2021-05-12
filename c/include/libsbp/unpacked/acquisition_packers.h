#ifndef LIBSBP_ACQUISITION_PACKERS_H
#define LIBSBP_ACQUISITION_PACKERS_H

#ifndef LIBSBP_ACQUISITION_MESSAGES_H
#error "Do not include this file directly, include libsbp/unpacked/acquisition.h instead"
#endif

#include <stdbool.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>
#include <endian.h>
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
  float msgcn0 = msg->cn0;
  memcpy(buf + offset, & msgcn0 , 4);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  float msgcp = msg->cp;
  memcpy(buf + offset, & msgcp , 4);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  float msgcf = msg->cf;
  memcpy(buf + offset, & msgcf , 4);
  // NOLINTNEXTLINE
  offset += 4;
				
        
  if (offset + 1 > len) { return false; }
  u8 msgsidsat = msg->sid.sat;
  memcpy(buf + offset, & msgsidsat , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  u8 msgsidcode = msg->sid.code;
  memcpy(buf + offset, & msgsidcode , 1);
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
  float msgcn0 = msg->cn0;
  memcpy(buf + offset, & msgcn0 , 4);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  float msgcp = msg->cp;
  memcpy(buf + offset, & msgcp , 4);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  float msgcf = msg->cf;
  memcpy(buf + offset, & msgcf , 4);
  // NOLINTNEXTLINE
  offset += 4;
				
        
  if (offset + 2 > len) { return false; }
  u16 msgsidsat = htole16( msg->sid.sat );
  memcpy(buf + offset, & msgsidsat , 2);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 1 > len) { return false; }
  u8 msgsidcode = msg->sid.code;
  memcpy(buf + offset, & msgsidcode , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  u8 msgsidreserved = msg->sid.reserved;
  memcpy(buf + offset, & msgsidreserved , 1);
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
  memcpy(&msg->sid.sat, buf + offset, 2);
  msg->sid.sat = le16toh( msg->sid.sat );
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
  float msgsnr = msg->snr;
  memcpy(buf + offset, & msgsnr , 4);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  float msgcp = msg->cp;
  memcpy(buf + offset, & msgcp , 4);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  float msgcf = msg->cf;
  memcpy(buf + offset, & msgcf , 4);
  // NOLINTNEXTLINE
  offset += 4;
				
        
  if (offset + 2 > len) { return false; }
  u16 msgsidsat = htole16( msg->sid.sat );
  memcpy(buf + offset, & msgsidsat , 2);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 1 > len) { return false; }
  u8 msgsidcode = msg->sid.code;
  memcpy(buf + offset, & msgsidcode , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  u8 msgsidreserved = msg->sid.reserved;
  memcpy(buf + offset, & msgsidreserved , 1);
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
  memcpy(&msg->sid.sat, buf + offset, 2);
  msg->sid.sat = le16toh( msg->sid.sat );
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
  float msgsnr = msg->snr;
  memcpy(buf + offset, & msgsnr , 4);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  float msgcp = msg->cp;
  memcpy(buf + offset, & msgcp , 4);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  float msgcf = msg->cf;
  memcpy(buf + offset, & msgcf , 4);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 1 > len) { return false; }
  u8 msgprn = msg->prn;
  memcpy(buf + offset, & msgprn , 1);
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
  u8 msgjob_type = msg->job_type;
  memcpy(buf + offset, & msgjob_type , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  u8 msgstatus = msg->status;
  memcpy(buf + offset, & msgstatus , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 2 > len) { return false; }
  u16 msgcn0 = htole16( msg->cn0 );
  memcpy(buf + offset, & msgcn0 , 2);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 1 > len) { return false; }
  u8 msgint_time = msg->int_time;
  memcpy(buf + offset, & msgint_time , 1);
  // NOLINTNEXTLINE
  offset += 1;
				
        
  if (offset + 1 > len) { return false; }
  u8 msgsidsat = msg->sid.sat;
  memcpy(buf + offset, & msgsidsat , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  u8 msgsidcode = msg->sid.code;
  memcpy(buf + offset, & msgsidcode , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 2 > len) { return false; }
  u16 msgbin_width = htole16( msg->bin_width );
  memcpy(buf + offset, & msgbin_width , 2);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 4 > len) { return false; }
  u32 msgtimestamp = htole32( msg->timestamp );
  memcpy(buf + offset, & msgtimestamp , 4);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  u32 msgtime_spent = htole32( msg->time_spent );
  memcpy(buf + offset, & msgtime_spent , 4);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  u32 msgcf_min = htole32( *(const u32*)&msg->cf_min );
  memcpy(buf + offset, & msgcf_min , 4);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  u32 msgcf_max = htole32( *(const u32*)&msg->cf_max );
  memcpy(buf + offset, & msgcf_max , 4);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  u32 msgcf = htole32( *(const u32*)&msg->cf );
  memcpy(buf + offset, & msgcf , 4);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  u32 msgcp = htole32( msg->cp );
  memcpy(buf + offset, & msgcp , 4);
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
  memcpy(&msg->cn0, buf + offset, 2);
  msg->cn0 = le16toh( msg->cn0 );
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
  memcpy(&msg->bin_width, buf + offset, 2);
  msg->bin_width = le16toh( msg->bin_width );
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->timestamp, buf + offset, 4);
  msg->timestamp = le32toh( msg->timestamp );
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->time_spent, buf + offset, 4);
  msg->time_spent = le32toh( msg->time_spent );
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->cf_min, buf + offset, 4);
  u32 msgcf_min = *(const u32*)&msg->cf_min;
  msgcf_min = le32toh( msgcf_min );
  msg->cf_min = *(const s32*)&msgcf_min;
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->cf_max, buf + offset, 4);
  u32 msgcf_max = *(const u32*)&msg->cf_max;
  msgcf_max = le32toh( msgcf_max );
  msg->cf_max = *(const s32*)&msgcf_max;
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->cf, buf + offset, 4);
  u32 msgcf = *(const u32*)&msg->cf;
  msgcf = le32toh( msgcf );
  msg->cf = *(const s32*)&msgcf;
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->cp, buf + offset, 4);
  msg->cp = le32toh( msg->cp );
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
  u8 msgjob_type = msg->job_type;
  memcpy(buf + offset, & msgjob_type , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  u8 msgstatus = msg->status;
  memcpy(buf + offset, & msgstatus , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 2 > len) { return false; }
  u16 msgcn0 = htole16( msg->cn0 );
  memcpy(buf + offset, & msgcn0 , 2);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 1 > len) { return false; }
  u8 msgint_time = msg->int_time;
  memcpy(buf + offset, & msgint_time , 1);
  // NOLINTNEXTLINE
  offset += 1;
				
        
  if (offset + 2 > len) { return false; }
  u16 msgsidsat = htole16( msg->sid.sat );
  memcpy(buf + offset, & msgsidsat , 2);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 1 > len) { return false; }
  u8 msgsidcode = msg->sid.code;
  memcpy(buf + offset, & msgsidcode , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  u8 msgsidreserved = msg->sid.reserved;
  memcpy(buf + offset, & msgsidreserved , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 2 > len) { return false; }
  u16 msgbin_width = htole16( msg->bin_width );
  memcpy(buf + offset, & msgbin_width , 2);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 4 > len) { return false; }
  u32 msgtimestamp = htole32( msg->timestamp );
  memcpy(buf + offset, & msgtimestamp , 4);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  u32 msgtime_spent = htole32( msg->time_spent );
  memcpy(buf + offset, & msgtime_spent , 4);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  u32 msgcf_min = htole32( *(const u32*)&msg->cf_min );
  memcpy(buf + offset, & msgcf_min , 4);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  u32 msgcf_max = htole32( *(const u32*)&msg->cf_max );
  memcpy(buf + offset, & msgcf_max , 4);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  u32 msgcf = htole32( *(const u32*)&msg->cf );
  memcpy(buf + offset, & msgcf , 4);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  u32 msgcp = htole32( msg->cp );
  memcpy(buf + offset, & msgcp , 4);
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
  memcpy(&msg->cn0, buf + offset, 2);
  msg->cn0 = le16toh( msg->cn0 );
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->int_time, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
			
      
  if (offset + 2 > len) { return false; }
  memcpy(&msg->sid.sat, buf + offset, 2);
  msg->sid.sat = le16toh( msg->sid.sat );
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
  memcpy(&msg->bin_width, buf + offset, 2);
  msg->bin_width = le16toh( msg->bin_width );
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->timestamp, buf + offset, 4);
  msg->timestamp = le32toh( msg->timestamp );
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->time_spent, buf + offset, 4);
  msg->time_spent = le32toh( msg->time_spent );
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->cf_min, buf + offset, 4);
  u32 msgcf_min = *(const u32*)&msg->cf_min;
  msgcf_min = le32toh( msgcf_min );
  msg->cf_min = *(const s32*)&msgcf_min;
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->cf_max, buf + offset, 4);
  u32 msgcf_max = *(const u32*)&msg->cf_max;
  msgcf_max = le32toh( msgcf_max );
  msg->cf_max = *(const s32*)&msgcf_max;
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->cf, buf + offset, 4);
  u32 msgcf = *(const u32*)&msg->cf;
  msgcf = le32toh( msgcf );
  msg->cf = *(const s32*)&msgcf;
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->cp, buf + offset, 4);
  msg->cp = le32toh( msg->cp );
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
  u8 msgacq_sv_profilemsgacq_sv_profile_idxjob_type = msg->acq_sv_profile[msgacq_sv_profile_idx].job_type;
  memcpy(buf + offset, & msgacq_sv_profilemsgacq_sv_profile_idxjob_type , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  u8 msgacq_sv_profilemsgacq_sv_profile_idxstatus = msg->acq_sv_profile[msgacq_sv_profile_idx].status;
  memcpy(buf + offset, & msgacq_sv_profilemsgacq_sv_profile_idxstatus , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 2 > len) { return false; }
  u16 msgacq_sv_profilemsgacq_sv_profile_idxcn0 = htole16( msg->acq_sv_profile[msgacq_sv_profile_idx].cn0 );
  memcpy(buf + offset, & msgacq_sv_profilemsgacq_sv_profile_idxcn0 , 2);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 1 > len) { return false; }
  u8 msgacq_sv_profilemsgacq_sv_profile_idxint_time = msg->acq_sv_profile[msgacq_sv_profile_idx].int_time;
  memcpy(buf + offset, & msgacq_sv_profilemsgacq_sv_profile_idxint_time , 1);
  // NOLINTNEXTLINE
  offset += 1;
				
        
  if (offset + 1 > len) { return false; }
  u8 msgacq_sv_profilemsgacq_sv_profile_idxsidsat = msg->acq_sv_profile[msgacq_sv_profile_idx].sid.sat;
  memcpy(buf + offset, & msgacq_sv_profilemsgacq_sv_profile_idxsidsat , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  u8 msgacq_sv_profilemsgacq_sv_profile_idxsidcode = msg->acq_sv_profile[msgacq_sv_profile_idx].sid.code;
  memcpy(buf + offset, & msgacq_sv_profilemsgacq_sv_profile_idxsidcode , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 2 > len) { return false; }
  u16 msgacq_sv_profilemsgacq_sv_profile_idxbin_width = htole16( msg->acq_sv_profile[msgacq_sv_profile_idx].bin_width );
  memcpy(buf + offset, & msgacq_sv_profilemsgacq_sv_profile_idxbin_width , 2);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 4 > len) { return false; }
  u32 msgacq_sv_profilemsgacq_sv_profile_idxtimestamp = htole32( msg->acq_sv_profile[msgacq_sv_profile_idx].timestamp );
  memcpy(buf + offset, & msgacq_sv_profilemsgacq_sv_profile_idxtimestamp , 4);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  u32 msgacq_sv_profilemsgacq_sv_profile_idxtime_spent = htole32( msg->acq_sv_profile[msgacq_sv_profile_idx].time_spent );
  memcpy(buf + offset, & msgacq_sv_profilemsgacq_sv_profile_idxtime_spent , 4);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  u32 msgacq_sv_profilemsgacq_sv_profile_idxcf_min = htole32( *(const u32*)&msg->acq_sv_profile[msgacq_sv_profile_idx].cf_min );
  memcpy(buf + offset, & msgacq_sv_profilemsgacq_sv_profile_idxcf_min , 4);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  u32 msgacq_sv_profilemsgacq_sv_profile_idxcf_max = htole32( *(const u32*)&msg->acq_sv_profile[msgacq_sv_profile_idx].cf_max );
  memcpy(buf + offset, & msgacq_sv_profilemsgacq_sv_profile_idxcf_max , 4);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  u32 msgacq_sv_profilemsgacq_sv_profile_idxcf = htole32( *(const u32*)&msg->acq_sv_profile[msgacq_sv_profile_idx].cf );
  memcpy(buf + offset, & msgacq_sv_profilemsgacq_sv_profile_idxcf , 4);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  u32 msgacq_sv_profilemsgacq_sv_profile_idxcp = htole32( msg->acq_sv_profile[msgacq_sv_profile_idx].cp );
  memcpy(buf + offset, & msgacq_sv_profilemsgacq_sv_profile_idxcp , 4);
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
  memcpy(&msg->acq_sv_profile[msgacq_sv_profile_idx].cn0, buf + offset, 2);
  msg->acq_sv_profile[msgacq_sv_profile_idx].cn0 = le16toh( msg->acq_sv_profile[msgacq_sv_profile_idx].cn0 );
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
  memcpy(&msg->acq_sv_profile[msgacq_sv_profile_idx].bin_width, buf + offset, 2);
  msg->acq_sv_profile[msgacq_sv_profile_idx].bin_width = le16toh( msg->acq_sv_profile[msgacq_sv_profile_idx].bin_width );
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->acq_sv_profile[msgacq_sv_profile_idx].timestamp, buf + offset, 4);
  msg->acq_sv_profile[msgacq_sv_profile_idx].timestamp = le32toh( msg->acq_sv_profile[msgacq_sv_profile_idx].timestamp );
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->acq_sv_profile[msgacq_sv_profile_idx].time_spent, buf + offset, 4);
  msg->acq_sv_profile[msgacq_sv_profile_idx].time_spent = le32toh( msg->acq_sv_profile[msgacq_sv_profile_idx].time_spent );
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->acq_sv_profile[msgacq_sv_profile_idx].cf_min, buf + offset, 4);
  u32 msgacq_sv_profilemsgacq_sv_profile_idxcf_min = *(const u32*)&msg->acq_sv_profile[msgacq_sv_profile_idx].cf_min;
  msgacq_sv_profilemsgacq_sv_profile_idxcf_min = le32toh( msgacq_sv_profilemsgacq_sv_profile_idxcf_min );
  msg->acq_sv_profile[msgacq_sv_profile_idx].cf_min = *(const s32*)&msgacq_sv_profilemsgacq_sv_profile_idxcf_min;
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->acq_sv_profile[msgacq_sv_profile_idx].cf_max, buf + offset, 4);
  u32 msgacq_sv_profilemsgacq_sv_profile_idxcf_max = *(const u32*)&msg->acq_sv_profile[msgacq_sv_profile_idx].cf_max;
  msgacq_sv_profilemsgacq_sv_profile_idxcf_max = le32toh( msgacq_sv_profilemsgacq_sv_profile_idxcf_max );
  msg->acq_sv_profile[msgacq_sv_profile_idx].cf_max = *(const s32*)&msgacq_sv_profilemsgacq_sv_profile_idxcf_max;
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->acq_sv_profile[msgacq_sv_profile_idx].cf, buf + offset, 4);
  u32 msgacq_sv_profilemsgacq_sv_profile_idxcf = *(const u32*)&msg->acq_sv_profile[msgacq_sv_profile_idx].cf;
  msgacq_sv_profilemsgacq_sv_profile_idxcf = le32toh( msgacq_sv_profilemsgacq_sv_profile_idxcf );
  msg->acq_sv_profile[msgacq_sv_profile_idx].cf = *(const s32*)&msgacq_sv_profilemsgacq_sv_profile_idxcf;
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->acq_sv_profile[msgacq_sv_profile_idx].cp, buf + offset, 4);
  msg->acq_sv_profile[msgacq_sv_profile_idx].cp = le32toh( msg->acq_sv_profile[msgacq_sv_profile_idx].cp );
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
  u8 msgacq_sv_profilemsgacq_sv_profile_idxjob_type = msg->acq_sv_profile[msgacq_sv_profile_idx].job_type;
  memcpy(buf + offset, & msgacq_sv_profilemsgacq_sv_profile_idxjob_type , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  u8 msgacq_sv_profilemsgacq_sv_profile_idxstatus = msg->acq_sv_profile[msgacq_sv_profile_idx].status;
  memcpy(buf + offset, & msgacq_sv_profilemsgacq_sv_profile_idxstatus , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 2 > len) { return false; }
  u16 msgacq_sv_profilemsgacq_sv_profile_idxcn0 = htole16( msg->acq_sv_profile[msgacq_sv_profile_idx].cn0 );
  memcpy(buf + offset, & msgacq_sv_profilemsgacq_sv_profile_idxcn0 , 2);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 1 > len) { return false; }
  u8 msgacq_sv_profilemsgacq_sv_profile_idxint_time = msg->acq_sv_profile[msgacq_sv_profile_idx].int_time;
  memcpy(buf + offset, & msgacq_sv_profilemsgacq_sv_profile_idxint_time , 1);
  // NOLINTNEXTLINE
  offset += 1;
				
        
  if (offset + 2 > len) { return false; }
  u16 msgacq_sv_profilemsgacq_sv_profile_idxsidsat = htole16( msg->acq_sv_profile[msgacq_sv_profile_idx].sid.sat );
  memcpy(buf + offset, & msgacq_sv_profilemsgacq_sv_profile_idxsidsat , 2);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 1 > len) { return false; }
  u8 msgacq_sv_profilemsgacq_sv_profile_idxsidcode = msg->acq_sv_profile[msgacq_sv_profile_idx].sid.code;
  memcpy(buf + offset, & msgacq_sv_profilemsgacq_sv_profile_idxsidcode , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  u8 msgacq_sv_profilemsgacq_sv_profile_idxsidreserved = msg->acq_sv_profile[msgacq_sv_profile_idx].sid.reserved;
  memcpy(buf + offset, & msgacq_sv_profilemsgacq_sv_profile_idxsidreserved , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 2 > len) { return false; }
  u16 msgacq_sv_profilemsgacq_sv_profile_idxbin_width = htole16( msg->acq_sv_profile[msgacq_sv_profile_idx].bin_width );
  memcpy(buf + offset, & msgacq_sv_profilemsgacq_sv_profile_idxbin_width , 2);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 4 > len) { return false; }
  u32 msgacq_sv_profilemsgacq_sv_profile_idxtimestamp = htole32( msg->acq_sv_profile[msgacq_sv_profile_idx].timestamp );
  memcpy(buf + offset, & msgacq_sv_profilemsgacq_sv_profile_idxtimestamp , 4);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  u32 msgacq_sv_profilemsgacq_sv_profile_idxtime_spent = htole32( msg->acq_sv_profile[msgacq_sv_profile_idx].time_spent );
  memcpy(buf + offset, & msgacq_sv_profilemsgacq_sv_profile_idxtime_spent , 4);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  u32 msgacq_sv_profilemsgacq_sv_profile_idxcf_min = htole32( *(const u32*)&msg->acq_sv_profile[msgacq_sv_profile_idx].cf_min );
  memcpy(buf + offset, & msgacq_sv_profilemsgacq_sv_profile_idxcf_min , 4);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  u32 msgacq_sv_profilemsgacq_sv_profile_idxcf_max = htole32( *(const u32*)&msg->acq_sv_profile[msgacq_sv_profile_idx].cf_max );
  memcpy(buf + offset, & msgacq_sv_profilemsgacq_sv_profile_idxcf_max , 4);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  u32 msgacq_sv_profilemsgacq_sv_profile_idxcf = htole32( *(const u32*)&msg->acq_sv_profile[msgacq_sv_profile_idx].cf );
  memcpy(buf + offset, & msgacq_sv_profilemsgacq_sv_profile_idxcf , 4);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  u32 msgacq_sv_profilemsgacq_sv_profile_idxcp = htole32( msg->acq_sv_profile[msgacq_sv_profile_idx].cp );
  memcpy(buf + offset, & msgacq_sv_profilemsgacq_sv_profile_idxcp , 4);
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
  memcpy(&msg->acq_sv_profile[msgacq_sv_profile_idx].cn0, buf + offset, 2);
  msg->acq_sv_profile[msgacq_sv_profile_idx].cn0 = le16toh( msg->acq_sv_profile[msgacq_sv_profile_idx].cn0 );
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->acq_sv_profile[msgacq_sv_profile_idx].int_time, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
			
      
  if (offset + 2 > len) { return false; }
  memcpy(&msg->acq_sv_profile[msgacq_sv_profile_idx].sid.sat, buf + offset, 2);
  msg->acq_sv_profile[msgacq_sv_profile_idx].sid.sat = le16toh( msg->acq_sv_profile[msgacq_sv_profile_idx].sid.sat );
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
  memcpy(&msg->acq_sv_profile[msgacq_sv_profile_idx].bin_width, buf + offset, 2);
  msg->acq_sv_profile[msgacq_sv_profile_idx].bin_width = le16toh( msg->acq_sv_profile[msgacq_sv_profile_idx].bin_width );
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->acq_sv_profile[msgacq_sv_profile_idx].timestamp, buf + offset, 4);
  msg->acq_sv_profile[msgacq_sv_profile_idx].timestamp = le32toh( msg->acq_sv_profile[msgacq_sv_profile_idx].timestamp );
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->acq_sv_profile[msgacq_sv_profile_idx].time_spent, buf + offset, 4);
  msg->acq_sv_profile[msgacq_sv_profile_idx].time_spent = le32toh( msg->acq_sv_profile[msgacq_sv_profile_idx].time_spent );
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->acq_sv_profile[msgacq_sv_profile_idx].cf_min, buf + offset, 4);
  u32 msgacq_sv_profilemsgacq_sv_profile_idxcf_min = *(const u32*)&msg->acq_sv_profile[msgacq_sv_profile_idx].cf_min;
  msgacq_sv_profilemsgacq_sv_profile_idxcf_min = le32toh( msgacq_sv_profilemsgacq_sv_profile_idxcf_min );
  msg->acq_sv_profile[msgacq_sv_profile_idx].cf_min = *(const s32*)&msgacq_sv_profilemsgacq_sv_profile_idxcf_min;
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->acq_sv_profile[msgacq_sv_profile_idx].cf_max, buf + offset, 4);
  u32 msgacq_sv_profilemsgacq_sv_profile_idxcf_max = *(const u32*)&msg->acq_sv_profile[msgacq_sv_profile_idx].cf_max;
  msgacq_sv_profilemsgacq_sv_profile_idxcf_max = le32toh( msgacq_sv_profilemsgacq_sv_profile_idxcf_max );
  msg->acq_sv_profile[msgacq_sv_profile_idx].cf_max = *(const s32*)&msgacq_sv_profilemsgacq_sv_profile_idxcf_max;
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->acq_sv_profile[msgacq_sv_profile_idx].cf, buf + offset, 4);
  u32 msgacq_sv_profilemsgacq_sv_profile_idxcf = *(const u32*)&msg->acq_sv_profile[msgacq_sv_profile_idx].cf;
  msgacq_sv_profilemsgacq_sv_profile_idxcf = le32toh( msgacq_sv_profilemsgacq_sv_profile_idxcf );
  msg->acq_sv_profile[msgacq_sv_profile_idx].cf = *(const s32*)&msgacq_sv_profilemsgacq_sv_profile_idxcf;
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->acq_sv_profile[msgacq_sv_profile_idx].cp, buf + offset, 4);
  msg->acq_sv_profile[msgacq_sv_profile_idx].cp = le32toh( msg->acq_sv_profile[msgacq_sv_profile_idx].cp );
  // NOLINTNEXTLINE
  offset += 4;
		}
  return true;
}

#endif
