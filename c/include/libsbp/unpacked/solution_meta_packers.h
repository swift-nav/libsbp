#ifndef LIBSBP_SOLUTION_META_PACKERS_H
#define LIBSBP_SOLUTION_META_PACKERS_H

#ifndef LIBSBP_SOLUTION_META_MESSAGES_H
#error "Do not include this file directly, include libsbp/unpacked/solution_meta.h instead"
#endif

#include <stdbool.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>
#include <math.h>

#include <libsbp/common.h>
#include <libsbp/string.h>

static inline size_t sbp_packed_size_sbp_solution_input_type_t(const sbp_solution_input_type_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				sizeof( msg->sensor_type )                                                                          
	  +
				sizeof( msg->flags );
}

static inline bool sbp_pack_sbp_solution_input_type_t(u8 *buf, size_t len, const sbp_solution_input_type_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_solution_input_type_t(msg) > len) { return false; }
  
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->sensor_type , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->flags , 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline bool sbp_unpack_sbp_solution_input_type_t(const u8 *buf, size_t len, sbp_solution_input_type_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->sensor_type, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->flags, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_soln_meta_dep_a_t(const sbp_msg_soln_meta_dep_a_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				sizeof( msg->pdop )                                                                          
	  +
				sizeof( msg->hdop )                                                                          
	  +
				sizeof( msg->vdop )                                                                          
	  +
				sizeof( msg->n_sats )                                                                          
	  +
				sizeof( msg->age_corrections )                                                                          
	  +
				sizeof( msg->alignment_status )                                                                          
	  +
				sizeof( msg->last_used_gnss_pos_tow )                                                                          
	  +
				sizeof( msg->last_used_gnss_vel_tow )                                                                          
	  +
	    (
			  msg->n_sol_in
			*
				(                                                          
	0                                                                          
	  +
				sizeof( msg->sol_in[0].sensor_type )                                                                          
	  +
				sizeof( msg->sol_in[0].flags ) )
			);
}

static inline bool sbp_pack_sbp_msg_soln_meta_dep_a_t(u8 *buf, size_t len, const sbp_msg_soln_meta_dep_a_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_soln_meta_dep_a_t(msg) > len) { return false; }
  
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->pdop);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->hdop);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->vdop);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->n_sats , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->age_corrections);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->alignment_status , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->last_used_gnss_pos_tow);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->last_used_gnss_vel_tow);
  // NOLINTNEXTLINE
  offset += 4;
			for(size_t msgsol_in_idx = 0; msgsol_in_idx < (size_t)msg->n_sol_in; msgsol_in_idx++)
			{
					
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->sol_in[msgsol_in_idx].sensor_type , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->sol_in[msgsol_in_idx].flags , 1);
  // NOLINTNEXTLINE
  offset += 1;
			}
  return true;
}

static inline bool sbp_unpack_sbp_msg_soln_meta_dep_a_t(const u8 *buf, size_t len, sbp_msg_soln_meta_dep_a_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
      
  if (offset + 2 > len) { return false; }
  msg->pdop = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 2 > len) { return false; }
  msg->hdop = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 2 > len) { return false; }
  msg->vdop = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->n_sats, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 2 > len) { return false; }
  msg->age_corrections = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->alignment_status, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 4 > len) { return false; }
  msg->last_used_gnss_pos_tow = sbp_unpack_u32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  msg->last_used_gnss_vel_tow = sbp_unpack_u32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      msg->n_sol_in = (u8)((len - offset) / 2);

	  for (size_t msgsol_in_idx = 0; msgsol_in_idx <
				msg->n_sol_in;
				msgsol_in_idx++) 
		{
				
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->sol_in[msgsol_in_idx].sensor_type, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->sol_in[msgsol_in_idx].flags, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
		}
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_soln_meta_t(const sbp_msg_soln_meta_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				sizeof( msg->tow )                                                                          
	  +
				sizeof( msg->pdop )                                                                          
	  +
				sizeof( msg->hdop )                                                                          
	  +
				sizeof( msg->vdop )                                                                          
	  +
				sizeof( msg->age_corrections )                                                                          
	  +
				sizeof( msg->age_gnss )                                                                          
	  +
	    (
			  msg->n_sol_in
			*
				(                                                          
	0                                                                          
	  +
				sizeof( msg->sol_in[0].sensor_type )                                                                          
	  +
				sizeof( msg->sol_in[0].flags ) )
			);
}

static inline bool sbp_pack_sbp_msg_soln_meta_t(u8 *buf, size_t len, const sbp_msg_soln_meta_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_soln_meta_t(msg) > len) { return false; }
  
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->tow);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->pdop);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->hdop);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->vdop);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->age_corrections);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->age_gnss);
  // NOLINTNEXTLINE
  offset += 4;
			for(size_t msgsol_in_idx = 0; msgsol_in_idx < (size_t)msg->n_sol_in; msgsol_in_idx++)
			{
					
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->sol_in[msgsol_in_idx].sensor_type , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->sol_in[msgsol_in_idx].flags , 1);
  // NOLINTNEXTLINE
  offset += 1;
			}
  return true;
}

static inline bool sbp_unpack_sbp_msg_soln_meta_t(const u8 *buf, size_t len, sbp_msg_soln_meta_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
      
  if (offset + 4 > len) { return false; }
  msg->tow = sbp_unpack_u32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 2 > len) { return false; }
  msg->pdop = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 2 > len) { return false; }
  msg->hdop = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 2 > len) { return false; }
  msg->vdop = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 2 > len) { return false; }
  msg->age_corrections = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 4 > len) { return false; }
  msg->age_gnss = sbp_unpack_u32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      msg->n_sol_in = (u8)((len - offset) / 2);

	  for (size_t msgsol_in_idx = 0; msgsol_in_idx <
				msg->n_sol_in;
				msgsol_in_idx++) 
		{
				
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->sol_in[msgsol_in_idx].sensor_type, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->sol_in[msgsol_in_idx].flags, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
		}
  return true;
}

static inline size_t sbp_packed_size_sbp_gnss_input_type_t(const sbp_gnss_input_type_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				sizeof( msg->flags );
}

static inline bool sbp_pack_sbp_gnss_input_type_t(u8 *buf, size_t len, const sbp_gnss_input_type_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_gnss_input_type_t(msg) > len) { return false; }
  
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->flags , 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline bool sbp_unpack_sbp_gnss_input_type_t(const u8 *buf, size_t len, sbp_gnss_input_type_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->flags, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline size_t sbp_packed_size_sbp_imu_input_type_t(const sbp_imu_input_type_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				sizeof( msg->flags );
}

static inline bool sbp_pack_sbp_imu_input_type_t(u8 *buf, size_t len, const sbp_imu_input_type_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_imu_input_type_t(msg) > len) { return false; }
  
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->flags , 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline bool sbp_unpack_sbp_imu_input_type_t(const u8 *buf, size_t len, sbp_imu_input_type_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->flags, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline size_t sbp_packed_size_sbp_odo_input_type_t(const sbp_odo_input_type_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				sizeof( msg->flags );
}

static inline bool sbp_pack_sbp_odo_input_type_t(u8 *buf, size_t len, const sbp_odo_input_type_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_odo_input_type_t(msg) > len) { return false; }
  
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->flags , 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline bool sbp_unpack_sbp_odo_input_type_t(const u8 *buf, size_t len, sbp_odo_input_type_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->flags, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

#endif
