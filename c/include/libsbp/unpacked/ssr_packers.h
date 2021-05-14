#ifndef LIBSBP_SSR_PACKERS_H
#define LIBSBP_SSR_PACKERS_H

#ifndef LIBSBP_SSR_MESSAGES_H
#error "Do not include this file directly, include libsbp/unpacked/ssr.h instead"
#endif

#include <stdbool.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>
#include <math.h>

#include <libsbp/common.h>
#include <libsbp/string.h>

static inline size_t sbp_packed_size_sbp_code_biases_content_t(const sbp_code_biases_content_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				sizeof( msg->code )                                                                          
	  +
				sizeof( msg->value );
}

static inline bool sbp_pack_sbp_code_biases_content_t(u8 *buf, size_t len, const sbp_code_biases_content_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_code_biases_content_t(msg) > len) { return false; }
  
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->code , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_s16(buf + offset, msg->value);
  // NOLINTNEXTLINE
  offset += 2;
  return true;
}

static inline bool sbp_unpack_sbp_code_biases_content_t(const u8 *buf, size_t len, sbp_code_biases_content_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->code, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 2 > len) { return false; }
  msg->value = sbp_unpack_s16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
  return true;
}

static inline size_t sbp_packed_size_sbp_phase_biases_content_t(const sbp_phase_biases_content_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				sizeof( msg->code )                                                                          
	  +
				sizeof( msg->integer_indicator )                                                                          
	  +
				sizeof( msg->widelane_integer_indicator )                                                                          
	  +
				sizeof( msg->discontinuity_counter )                                                                          
	  +
				sizeof( msg->bias );
}

static inline bool sbp_pack_sbp_phase_biases_content_t(u8 *buf, size_t len, const sbp_phase_biases_content_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_phase_biases_content_t(msg) > len) { return false; }
  
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->code , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->integer_indicator , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->widelane_integer_indicator , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->discontinuity_counter , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 4 > len) { return false; }
  sbp_pack_s32(buf + offset, msg->bias);
  // NOLINTNEXTLINE
  offset += 4;
  return true;
}

static inline bool sbp_unpack_sbp_phase_biases_content_t(const u8 *buf, size_t len, sbp_phase_biases_content_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->code, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->integer_indicator, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->widelane_integer_indicator, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->discontinuity_counter, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 4 > len) { return false; }
  msg->bias = sbp_unpack_s32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
  return true;
}

static inline size_t sbp_packed_size_sbp_stec_header_t(const sbp_stec_header_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				sizeof( msg->tile_set_id )                                                                          
	  +
				sizeof( msg->tile_id )                                                                          
	  +
				(                                                          
	0                                                                          
	  +
				sizeof( msg->time.tow )                                                                          
	  +
				sizeof( msg->time.wn ) )                                                                          
	  +
				sizeof( msg->num_msgs )                                                                          
	  +
				sizeof( msg->seq_num )                                                                          
	  +
				sizeof( msg->update_interval )                                                                          
	  +
				sizeof( msg->iod_atmo );
}

static inline bool sbp_pack_sbp_stec_header_t(u8 *buf, size_t len, const sbp_stec_header_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_stec_header_t(msg) > len) { return false; }
  
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->tile_set_id);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->tile_id);
  // NOLINTNEXTLINE
  offset += 2;
				
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->time.tow);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->time.wn);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->num_msgs , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->seq_num , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->update_interval , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->iod_atmo , 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline bool sbp_unpack_sbp_stec_header_t(const u8 *buf, size_t len, sbp_stec_header_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
      
  if (offset + 2 > len) { return false; }
  msg->tile_set_id = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 2 > len) { return false; }
  msg->tile_id = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
			
      
  if (offset + 4 > len) { return false; }
  msg->time.tow = sbp_unpack_u32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 2 > len) { return false; }
  msg->time.wn = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->num_msgs, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->seq_num, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->update_interval, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->iod_atmo, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline size_t sbp_packed_size_sbp_gridded_correction_header_t(const sbp_gridded_correction_header_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				sizeof( msg->tile_set_id )                                                                          
	  +
				sizeof( msg->tile_id )                                                                          
	  +
				(                                                          
	0                                                                          
	  +
				sizeof( msg->time.tow )                                                                          
	  +
				sizeof( msg->time.wn ) )                                                                          
	  +
				sizeof( msg->num_msgs )                                                                          
	  +
				sizeof( msg->seq_num )                                                                          
	  +
				sizeof( msg->update_interval )                                                                          
	  +
				sizeof( msg->iod_atmo )                                                                          
	  +
				sizeof( msg->tropo_quality_indicator );
}

static inline bool sbp_pack_sbp_gridded_correction_header_t(u8 *buf, size_t len, const sbp_gridded_correction_header_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_gridded_correction_header_t(msg) > len) { return false; }
  
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->tile_set_id);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->tile_id);
  // NOLINTNEXTLINE
  offset += 2;
				
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->time.tow);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->time.wn);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->num_msgs);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->seq_num);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->update_interval , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->iod_atmo , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->tropo_quality_indicator , 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline bool sbp_unpack_sbp_gridded_correction_header_t(const u8 *buf, size_t len, sbp_gridded_correction_header_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
      
  if (offset + 2 > len) { return false; }
  msg->tile_set_id = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 2 > len) { return false; }
  msg->tile_id = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
			
      
  if (offset + 4 > len) { return false; }
  msg->time.tow = sbp_unpack_u32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 2 > len) { return false; }
  msg->time.wn = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 2 > len) { return false; }
  msg->num_msgs = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 2 > len) { return false; }
  msg->seq_num = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->update_interval, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->iod_atmo, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->tropo_quality_indicator, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline size_t sbp_packed_size_sbp_stec_sat_element_t(const sbp_stec_sat_element_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				(                                                          
	0                                                                          
	  +
				sizeof( msg->sv_id.satId )                                                                          
	  +
				sizeof( msg->sv_id.constellation ) )                                                                          
	  +
				sizeof( msg->stec_quality_indicator )                                                                          
	  +
		  ( 4 *
        sizeof( msg->stec_coeff[0] )
		);
}

static inline bool sbp_pack_sbp_stec_sat_element_t(u8 *buf, size_t len, const sbp_stec_sat_element_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_stec_sat_element_t(msg) > len) { return false; }
  
				
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->sv_id.satId , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->sv_id.constellation , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->stec_quality_indicator , 1);
  // NOLINTNEXTLINE
  offset += 1;
		  for(size_t msgstec_coeff_idx = 0; msgstec_coeff_idx < 4; msgstec_coeff_idx++)
			{
        
  if (offset + 2 > len) { return false; }
  sbp_pack_s16(buf + offset, msg->stec_coeff[msgstec_coeff_idx]);
  // NOLINTNEXTLINE
  offset += 2;
			}
  return true;
}

static inline bool sbp_unpack_sbp_stec_sat_element_t(const u8 *buf, size_t len, sbp_stec_sat_element_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
			
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->sv_id.satId, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->sv_id.constellation, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->stec_quality_indicator, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
		for (size_t msgstec_coeff_idx = 0; msgstec_coeff_idx < 4; msgstec_coeff_idx++)
		{
        
  if (offset + 2 > len) { return false; }
  msg->stec_coeff[msgstec_coeff_idx] = sbp_unpack_s16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
		}
  return true;
}

static inline size_t sbp_packed_size_sbp_tropospheric_delay_correction_no_std_t(const sbp_tropospheric_delay_correction_no_std_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				sizeof( msg->hydro )                                                                          
	  +
				sizeof( msg->wet );
}

static inline bool sbp_pack_sbp_tropospheric_delay_correction_no_std_t(u8 *buf, size_t len, const sbp_tropospheric_delay_correction_no_std_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_tropospheric_delay_correction_no_std_t(msg) > len) { return false; }
  
        
  if (offset + 2 > len) { return false; }
  sbp_pack_s16(buf + offset, msg->hydro);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->wet , 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline bool sbp_unpack_sbp_tropospheric_delay_correction_no_std_t(const u8 *buf, size_t len, sbp_tropospheric_delay_correction_no_std_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
      
  if (offset + 2 > len) { return false; }
  msg->hydro = sbp_unpack_s16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->wet, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline size_t sbp_packed_size_sbp_tropospheric_delay_correction_t(const sbp_tropospheric_delay_correction_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				sizeof( msg->hydro )                                                                          
	  +
				sizeof( msg->wet )                                                                          
	  +
				sizeof( msg->stddev );
}

static inline bool sbp_pack_sbp_tropospheric_delay_correction_t(u8 *buf, size_t len, const sbp_tropospheric_delay_correction_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_tropospheric_delay_correction_t(msg) > len) { return false; }
  
        
  if (offset + 2 > len) { return false; }
  sbp_pack_s16(buf + offset, msg->hydro);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->wet , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->stddev , 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline bool sbp_unpack_sbp_tropospheric_delay_correction_t(const u8 *buf, size_t len, sbp_tropospheric_delay_correction_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
      
  if (offset + 2 > len) { return false; }
  msg->hydro = sbp_unpack_s16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->wet, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->stddev, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline size_t sbp_packed_size_sbp_stec_residual_no_std_t(const sbp_stec_residual_no_std_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				(                                                          
	0                                                                          
	  +
				sizeof( msg->sv_id.satId )                                                                          
	  +
				sizeof( msg->sv_id.constellation ) )                                                                          
	  +
				sizeof( msg->residual );
}

static inline bool sbp_pack_sbp_stec_residual_no_std_t(u8 *buf, size_t len, const sbp_stec_residual_no_std_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_stec_residual_no_std_t(msg) > len) { return false; }
  
				
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->sv_id.satId , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->sv_id.constellation , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_s16(buf + offset, msg->residual);
  // NOLINTNEXTLINE
  offset += 2;
  return true;
}

static inline bool sbp_unpack_sbp_stec_residual_no_std_t(const u8 *buf, size_t len, sbp_stec_residual_no_std_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
			
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->sv_id.satId, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->sv_id.constellation, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 2 > len) { return false; }
  msg->residual = sbp_unpack_s16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
  return true;
}

static inline size_t sbp_packed_size_sbp_stec_residual_t(const sbp_stec_residual_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				(                                                          
	0                                                                          
	  +
				sizeof( msg->sv_id.satId )                                                                          
	  +
				sizeof( msg->sv_id.constellation ) )                                                                          
	  +
				sizeof( msg->residual )                                                                          
	  +
				sizeof( msg->stddev );
}

static inline bool sbp_pack_sbp_stec_residual_t(u8 *buf, size_t len, const sbp_stec_residual_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_stec_residual_t(msg) > len) { return false; }
  
				
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->sv_id.satId , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->sv_id.constellation , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_s16(buf + offset, msg->residual);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->stddev , 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline bool sbp_unpack_sbp_stec_residual_t(const u8 *buf, size_t len, sbp_stec_residual_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
			
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->sv_id.satId, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->sv_id.constellation, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 2 > len) { return false; }
  msg->residual = sbp_unpack_s16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->stddev, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline size_t sbp_packed_size_sbp_grid_element_no_std_t(const sbp_grid_element_no_std_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				sizeof( msg->index )                                                                          
	  +
				(                                                          
	0                                                                          
	  +
				sizeof( msg->tropo_delay_correction.hydro )                                                                          
	  +
				sizeof( msg->tropo_delay_correction.wet ) )                                                                          
	  +
	    (
			  msg->n_stec_residuals
			*
				(                                                          
	0                                                                          
	  +
				(                                                          
	0                                                                          
	  +
				sizeof( msg->stec_residuals[0].sv_id.satId )                                                                          
	  +
				sizeof( msg->stec_residuals[0].sv_id.constellation ) )                                                                          
	  +
				sizeof( msg->stec_residuals[0].residual ) )
			);
}

static inline bool sbp_pack_sbp_grid_element_no_std_t(u8 *buf, size_t len, const sbp_grid_element_no_std_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_grid_element_no_std_t(msg) > len) { return false; }
  
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->index);
  // NOLINTNEXTLINE
  offset += 2;
				
        
  if (offset + 2 > len) { return false; }
  sbp_pack_s16(buf + offset, msg->tropo_delay_correction.hydro);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->tropo_delay_correction.wet , 1);
  // NOLINTNEXTLINE
  offset += 1;
			for(size_t msgstec_residuals_idx = 0; msgstec_residuals_idx < (size_t)msg->n_stec_residuals; msgstec_residuals_idx++)
			{
					
				
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->stec_residuals[msgstec_residuals_idx].sv_id.satId , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->stec_residuals[msgstec_residuals_idx].sv_id.constellation , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_s16(buf + offset, msg->stec_residuals[msgstec_residuals_idx].residual);
  // NOLINTNEXTLINE
  offset += 2;
			}
  return true;
}

static inline bool sbp_unpack_sbp_grid_element_no_std_t(const u8 *buf, size_t len, sbp_grid_element_no_std_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
      
  if (offset + 2 > len) { return false; }
  msg->index = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
			
      
  if (offset + 2 > len) { return false; }
  msg->tropo_delay_correction.hydro = sbp_unpack_s16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->tropo_delay_correction.wet, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      msg->n_stec_residuals = (u8)((len - offset) / 4);

	  for (size_t msgstec_residuals_idx = 0; msgstec_residuals_idx <
				msg->n_stec_residuals;
				msgstec_residuals_idx++) 
		{
				
			
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->stec_residuals[msgstec_residuals_idx].sv_id.satId, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->stec_residuals[msgstec_residuals_idx].sv_id.constellation, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 2 > len) { return false; }
  msg->stec_residuals[msgstec_residuals_idx].residual = sbp_unpack_s16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
		}
  return true;
}

static inline size_t sbp_packed_size_sbp_grid_element_t(const sbp_grid_element_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				sizeof( msg->index )                                                                          
	  +
				(                                                          
	0                                                                          
	  +
				sizeof( msg->tropo_delay_correction.hydro )                                                                          
	  +
				sizeof( msg->tropo_delay_correction.wet )                                                                          
	  +
				sizeof( msg->tropo_delay_correction.stddev ) )                                                                          
	  +
	    (
			  msg->n_stec_residuals
			*
				(                                                          
	0                                                                          
	  +
				(                                                          
	0                                                                          
	  +
				sizeof( msg->stec_residuals[0].sv_id.satId )                                                                          
	  +
				sizeof( msg->stec_residuals[0].sv_id.constellation ) )                                                                          
	  +
				sizeof( msg->stec_residuals[0].residual )                                                                          
	  +
				sizeof( msg->stec_residuals[0].stddev ) )
			);
}

static inline bool sbp_pack_sbp_grid_element_t(u8 *buf, size_t len, const sbp_grid_element_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_grid_element_t(msg) > len) { return false; }
  
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->index);
  // NOLINTNEXTLINE
  offset += 2;
				
        
  if (offset + 2 > len) { return false; }
  sbp_pack_s16(buf + offset, msg->tropo_delay_correction.hydro);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->tropo_delay_correction.wet , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->tropo_delay_correction.stddev , 1);
  // NOLINTNEXTLINE
  offset += 1;
			for(size_t msgstec_residuals_idx = 0; msgstec_residuals_idx < (size_t)msg->n_stec_residuals; msgstec_residuals_idx++)
			{
					
				
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->stec_residuals[msgstec_residuals_idx].sv_id.satId , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->stec_residuals[msgstec_residuals_idx].sv_id.constellation , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_s16(buf + offset, msg->stec_residuals[msgstec_residuals_idx].residual);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->stec_residuals[msgstec_residuals_idx].stddev , 1);
  // NOLINTNEXTLINE
  offset += 1;
			}
  return true;
}

static inline bool sbp_unpack_sbp_grid_element_t(const u8 *buf, size_t len, sbp_grid_element_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
      
  if (offset + 2 > len) { return false; }
  msg->index = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
			
      
  if (offset + 2 > len) { return false; }
  msg->tropo_delay_correction.hydro = sbp_unpack_s16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->tropo_delay_correction.wet, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->tropo_delay_correction.stddev, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      msg->n_stec_residuals = (u8)((len - offset) / 5);

	  for (size_t msgstec_residuals_idx = 0; msgstec_residuals_idx <
				msg->n_stec_residuals;
				msgstec_residuals_idx++) 
		{
				
			
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->stec_residuals[msgstec_residuals_idx].sv_id.satId, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->stec_residuals[msgstec_residuals_idx].sv_id.constellation, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 2 > len) { return false; }
  msg->stec_residuals[msgstec_residuals_idx].residual = sbp_unpack_s16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->stec_residuals[msgstec_residuals_idx].stddev, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
		}
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_ssr_orbit_clock_t(const sbp_msg_ssr_orbit_clock_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				(                                                          
	0                                                                          
	  +
				sizeof( msg->time.tow )                                                                          
	  +
				sizeof( msg->time.wn ) )                                                                          
	  +
				(                                                          
	0                                                                          
	  +
				sizeof( msg->sid.sat )                                                                          
	  +
				sizeof( msg->sid.code ) )                                                                          
	  +
				sizeof( msg->update_interval )                                                                          
	  +
				sizeof( msg->iod_ssr )                                                                          
	  +
				sizeof( msg->iod )                                                                          
	  +
				sizeof( msg->radial )                                                                          
	  +
				sizeof( msg->along )                                                                          
	  +
				sizeof( msg->cross )                                                                          
	  +
				sizeof( msg->dot_radial )                                                                          
	  +
				sizeof( msg->dot_along )                                                                          
	  +
				sizeof( msg->dot_cross )                                                                          
	  +
				sizeof( msg->c0 )                                                                          
	  +
				sizeof( msg->c1 )                                                                          
	  +
				sizeof( msg->c2 );
}

static inline bool sbp_pack_sbp_msg_ssr_orbit_clock_t(u8 *buf, size_t len, const sbp_msg_ssr_orbit_clock_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_ssr_orbit_clock_t(msg) > len) { return false; }
  
				
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->time.tow);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->time.wn);
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
  memcpy(buf + offset, & msg->update_interval , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->iod_ssr , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->iod);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  sbp_pack_s32(buf + offset, msg->radial);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  sbp_pack_s32(buf + offset, msg->along);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  sbp_pack_s32(buf + offset, msg->cross);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  sbp_pack_s32(buf + offset, msg->dot_radial);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  sbp_pack_s32(buf + offset, msg->dot_along);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  sbp_pack_s32(buf + offset, msg->dot_cross);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  sbp_pack_s32(buf + offset, msg->c0);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  sbp_pack_s32(buf + offset, msg->c1);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  sbp_pack_s32(buf + offset, msg->c2);
  // NOLINTNEXTLINE
  offset += 4;
  return true;
}

static inline bool sbp_unpack_sbp_msg_ssr_orbit_clock_t(const u8 *buf, size_t len, sbp_msg_ssr_orbit_clock_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
			
      
  if (offset + 4 > len) { return false; }
  msg->time.tow = sbp_unpack_u32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 2 > len) { return false; }
  msg->time.wn = sbp_unpack_u16(buf + offset);
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
  memcpy(&msg->update_interval, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->iod_ssr, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 4 > len) { return false; }
  msg->iod = sbp_unpack_u32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  msg->radial = sbp_unpack_s32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  msg->along = sbp_unpack_s32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  msg->cross = sbp_unpack_s32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  msg->dot_radial = sbp_unpack_s32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  msg->dot_along = sbp_unpack_s32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  msg->dot_cross = sbp_unpack_s32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  msg->c0 = sbp_unpack_s32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  msg->c1 = sbp_unpack_s32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  msg->c2 = sbp_unpack_s32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_ssr_code_biases_t(const sbp_msg_ssr_code_biases_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				(                                                          
	0                                                                          
	  +
				sizeof( msg->time.tow )                                                                          
	  +
				sizeof( msg->time.wn ) )                                                                          
	  +
				(                                                          
	0                                                                          
	  +
				sizeof( msg->sid.sat )                                                                          
	  +
				sizeof( msg->sid.code ) )                                                                          
	  +
				sizeof( msg->update_interval )                                                                          
	  +
				sizeof( msg->iod_ssr )                                                                          
	  +
	    (
			  msg->n_biases
			*
				(                                                          
	0                                                                          
	  +
				sizeof( msg->biases[0].code )                                                                          
	  +
				sizeof( msg->biases[0].value ) )
			);
}

static inline bool sbp_pack_sbp_msg_ssr_code_biases_t(u8 *buf, size_t len, const sbp_msg_ssr_code_biases_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_ssr_code_biases_t(msg) > len) { return false; }
  
				
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->time.tow);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->time.wn);
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
  memcpy(buf + offset, & msg->update_interval , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->iod_ssr , 1);
  // NOLINTNEXTLINE
  offset += 1;
			for(size_t msgbiases_idx = 0; msgbiases_idx < (size_t)msg->n_biases; msgbiases_idx++)
			{
					
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->biases[msgbiases_idx].code , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_s16(buf + offset, msg->biases[msgbiases_idx].value);
  // NOLINTNEXTLINE
  offset += 2;
			}
  return true;
}

static inline bool sbp_unpack_sbp_msg_ssr_code_biases_t(const u8 *buf, size_t len, sbp_msg_ssr_code_biases_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
			
      
  if (offset + 4 > len) { return false; }
  msg->time.tow = sbp_unpack_u32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 2 > len) { return false; }
  msg->time.wn = sbp_unpack_u16(buf + offset);
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
  memcpy(&msg->update_interval, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->iod_ssr, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      msg->n_biases = (u8)((len - offset) / 3);

	  for (size_t msgbiases_idx = 0; msgbiases_idx <
				msg->n_biases;
				msgbiases_idx++) 
		{
				
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->biases[msgbiases_idx].code, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 2 > len) { return false; }
  msg->biases[msgbiases_idx].value = sbp_unpack_s16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
		}
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_ssr_phase_biases_t(const sbp_msg_ssr_phase_biases_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				(                                                          
	0                                                                          
	  +
				sizeof( msg->time.tow )                                                                          
	  +
				sizeof( msg->time.wn ) )                                                                          
	  +
				(                                                          
	0                                                                          
	  +
				sizeof( msg->sid.sat )                                                                          
	  +
				sizeof( msg->sid.code ) )                                                                          
	  +
				sizeof( msg->update_interval )                                                                          
	  +
				sizeof( msg->iod_ssr )                                                                          
	  +
				sizeof( msg->dispersive_bias )                                                                          
	  +
				sizeof( msg->mw_consistency )                                                                          
	  +
				sizeof( msg->yaw )                                                                          
	  +
				sizeof( msg->yaw_rate )                                                                          
	  +
	    (
			  msg->n_biases
			*
				(                                                          
	0                                                                          
	  +
				sizeof( msg->biases[0].code )                                                                          
	  +
				sizeof( msg->biases[0].integer_indicator )                                                                          
	  +
				sizeof( msg->biases[0].widelane_integer_indicator )                                                                          
	  +
				sizeof( msg->biases[0].discontinuity_counter )                                                                          
	  +
				sizeof( msg->biases[0].bias ) )
			);
}

static inline bool sbp_pack_sbp_msg_ssr_phase_biases_t(u8 *buf, size_t len, const sbp_msg_ssr_phase_biases_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_ssr_phase_biases_t(msg) > len) { return false; }
  
				
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->time.tow);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->time.wn);
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
  memcpy(buf + offset, & msg->update_interval , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->iod_ssr , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->dispersive_bias , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->mw_consistency , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->yaw);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->yaw_rate , 1);
  // NOLINTNEXTLINE
  offset += 1;
			for(size_t msgbiases_idx = 0; msgbiases_idx < (size_t)msg->n_biases; msgbiases_idx++)
			{
					
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->biases[msgbiases_idx].code , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->biases[msgbiases_idx].integer_indicator , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->biases[msgbiases_idx].widelane_integer_indicator , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->biases[msgbiases_idx].discontinuity_counter , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 4 > len) { return false; }
  sbp_pack_s32(buf + offset, msg->biases[msgbiases_idx].bias);
  // NOLINTNEXTLINE
  offset += 4;
			}
  return true;
}

static inline bool sbp_unpack_sbp_msg_ssr_phase_biases_t(const u8 *buf, size_t len, sbp_msg_ssr_phase_biases_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
			
      
  if (offset + 4 > len) { return false; }
  msg->time.tow = sbp_unpack_u32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 2 > len) { return false; }
  msg->time.wn = sbp_unpack_u16(buf + offset);
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
  memcpy(&msg->update_interval, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->iod_ssr, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->dispersive_bias, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->mw_consistency, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 2 > len) { return false; }
  msg->yaw = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->yaw_rate, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      msg->n_biases = (u8)((len - offset) / 8);

	  for (size_t msgbiases_idx = 0; msgbiases_idx <
				msg->n_biases;
				msgbiases_idx++) 
		{
				
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->biases[msgbiases_idx].code, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->biases[msgbiases_idx].integer_indicator, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->biases[msgbiases_idx].widelane_integer_indicator, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->biases[msgbiases_idx].discontinuity_counter, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 4 > len) { return false; }
  msg->biases[msgbiases_idx].bias = sbp_unpack_s32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
		}
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_ssr_stec_correction_t(const sbp_msg_ssr_stec_correction_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				(                                                          
	0                                                                          
	  +
				sizeof( msg->header.tile_set_id )                                                                          
	  +
				sizeof( msg->header.tile_id )                                                                          
	  +
				(                                                          
	0                                                                          
	  +
				sizeof( msg->header.time.tow )                                                                          
	  +
				sizeof( msg->header.time.wn ) )                                                                          
	  +
				sizeof( msg->header.num_msgs )                                                                          
	  +
				sizeof( msg->header.seq_num )                                                                          
	  +
				sizeof( msg->header.update_interval )                                                                          
	  +
				sizeof( msg->header.iod_atmo ) )                                                                          
	  +
	    (
			  msg->n_stec_sat_list
			*
				(                                                          
	0                                                                          
	  +
				(                                                          
	0                                                                          
	  +
				sizeof( msg->stec_sat_list[0].sv_id.satId )                                                                          
	  +
				sizeof( msg->stec_sat_list[0].sv_id.constellation ) )                                                                          
	  +
				sizeof( msg->stec_sat_list[0].stec_quality_indicator )                                                                          
	  +
		  ( 4 *
        sizeof( msg->stec_sat_list[0].stec_coeff[0] )
		) )
			);
}

static inline bool sbp_pack_sbp_msg_ssr_stec_correction_t(u8 *buf, size_t len, const sbp_msg_ssr_stec_correction_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_ssr_stec_correction_t(msg) > len) { return false; }
  
				
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->header.tile_set_id);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->header.tile_id);
  // NOLINTNEXTLINE
  offset += 2;
				
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->header.time.tow);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->header.time.wn);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->header.num_msgs , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->header.seq_num , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->header.update_interval , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->header.iod_atmo , 1);
  // NOLINTNEXTLINE
  offset += 1;
			for(size_t msgstec_sat_list_idx = 0; msgstec_sat_list_idx < (size_t)msg->n_stec_sat_list; msgstec_sat_list_idx++)
			{
					
				
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->stec_sat_list[msgstec_sat_list_idx].sv_id.satId , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->stec_sat_list[msgstec_sat_list_idx].sv_id.constellation , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->stec_sat_list[msgstec_sat_list_idx].stec_quality_indicator , 1);
  // NOLINTNEXTLINE
  offset += 1;
		  for(size_t msgstec_sat_listmsgstec_sat_list_idxstec_coeff_idx = 0; msgstec_sat_listmsgstec_sat_list_idxstec_coeff_idx < 4; msgstec_sat_listmsgstec_sat_list_idxstec_coeff_idx++)
			{
        
  if (offset + 2 > len) { return false; }
  sbp_pack_s16(buf + offset, msg->stec_sat_list[msgstec_sat_list_idx].stec_coeff[msgstec_sat_listmsgstec_sat_list_idxstec_coeff_idx]);
  // NOLINTNEXTLINE
  offset += 2;
			}
			}
  return true;
}

static inline bool sbp_unpack_sbp_msg_ssr_stec_correction_t(const u8 *buf, size_t len, sbp_msg_ssr_stec_correction_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
			
      
  if (offset + 2 > len) { return false; }
  msg->header.tile_set_id = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 2 > len) { return false; }
  msg->header.tile_id = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
			
      
  if (offset + 4 > len) { return false; }
  msg->header.time.tow = sbp_unpack_u32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 2 > len) { return false; }
  msg->header.time.wn = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->header.num_msgs, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->header.seq_num, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->header.update_interval, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->header.iod_atmo, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      msg->n_stec_sat_list = (u8)((len - offset) / 11);

	  for (size_t msgstec_sat_list_idx = 0; msgstec_sat_list_idx <
				msg->n_stec_sat_list;
				msgstec_sat_list_idx++) 
		{
				
			
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->stec_sat_list[msgstec_sat_list_idx].sv_id.satId, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->stec_sat_list[msgstec_sat_list_idx].sv_id.constellation, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->stec_sat_list[msgstec_sat_list_idx].stec_quality_indicator, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
		for (size_t msgstec_sat_listmsgstec_sat_list_idxstec_coeff_idx = 0; msgstec_sat_listmsgstec_sat_list_idxstec_coeff_idx < 4; msgstec_sat_listmsgstec_sat_list_idxstec_coeff_idx++)
		{
        
  if (offset + 2 > len) { return false; }
  msg->stec_sat_list[msgstec_sat_list_idx].stec_coeff[msgstec_sat_listmsgstec_sat_list_idxstec_coeff_idx] = sbp_unpack_s16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
		}
		}
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_ssr_gridded_correction_t(const sbp_msg_ssr_gridded_correction_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				(                                                          
	0                                                                          
	  +
				sizeof( msg->header.tile_set_id )                                                                          
	  +
				sizeof( msg->header.tile_id )                                                                          
	  +
				(                                                          
	0                                                                          
	  +
				sizeof( msg->header.time.tow )                                                                          
	  +
				sizeof( msg->header.time.wn ) )                                                                          
	  +
				sizeof( msg->header.num_msgs )                                                                          
	  +
				sizeof( msg->header.seq_num )                                                                          
	  +
				sizeof( msg->header.update_interval )                                                                          
	  +
				sizeof( msg->header.iod_atmo )                                                                          
	  +
				sizeof( msg->header.tropo_quality_indicator ) )                                                                          
	  +
				(                                                          
	0                                                                          
	  +
				sizeof( msg->element.index )                                                                          
	  +
				(                                                          
	0                                                                          
	  +
				sizeof( msg->element.tropo_delay_correction.hydro )                                                                          
	  +
				sizeof( msg->element.tropo_delay_correction.wet )                                                                          
	  +
				sizeof( msg->element.tropo_delay_correction.stddev ) )                                                                          
	  +
	    (
			  msg->element.n_stec_residuals
			*
				(                                                          
	0                                                                          
	  +
				(                                                          
	0                                                                          
	  +
				sizeof( msg->element.stec_residuals[0].sv_id.satId )                                                                          
	  +
				sizeof( msg->element.stec_residuals[0].sv_id.constellation ) )                                                                          
	  +
				sizeof( msg->element.stec_residuals[0].residual )                                                                          
	  +
				sizeof( msg->element.stec_residuals[0].stddev ) )
			) );
}

static inline bool sbp_pack_sbp_msg_ssr_gridded_correction_t(u8 *buf, size_t len, const sbp_msg_ssr_gridded_correction_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_ssr_gridded_correction_t(msg) > len) { return false; }
  
				
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->header.tile_set_id);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->header.tile_id);
  // NOLINTNEXTLINE
  offset += 2;
				
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->header.time.tow);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->header.time.wn);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->header.num_msgs);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->header.seq_num);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->header.update_interval , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->header.iod_atmo , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->header.tropo_quality_indicator , 1);
  // NOLINTNEXTLINE
  offset += 1;
				
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->element.index);
  // NOLINTNEXTLINE
  offset += 2;
				
        
  if (offset + 2 > len) { return false; }
  sbp_pack_s16(buf + offset, msg->element.tropo_delay_correction.hydro);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->element.tropo_delay_correction.wet , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->element.tropo_delay_correction.stddev , 1);
  // NOLINTNEXTLINE
  offset += 1;
			for(size_t msgelementstec_residuals_idx = 0; msgelementstec_residuals_idx < (size_t)msg->element.n_stec_residuals; msgelementstec_residuals_idx++)
			{
					
				
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->element.stec_residuals[msgelementstec_residuals_idx].sv_id.satId , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->element.stec_residuals[msgelementstec_residuals_idx].sv_id.constellation , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_s16(buf + offset, msg->element.stec_residuals[msgelementstec_residuals_idx].residual);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->element.stec_residuals[msgelementstec_residuals_idx].stddev , 1);
  // NOLINTNEXTLINE
  offset += 1;
			}
  return true;
}

static inline bool sbp_unpack_sbp_msg_ssr_gridded_correction_t(const u8 *buf, size_t len, sbp_msg_ssr_gridded_correction_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
			
      
  if (offset + 2 > len) { return false; }
  msg->header.tile_set_id = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 2 > len) { return false; }
  msg->header.tile_id = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
			
      
  if (offset + 4 > len) { return false; }
  msg->header.time.tow = sbp_unpack_u32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 2 > len) { return false; }
  msg->header.time.wn = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 2 > len) { return false; }
  msg->header.num_msgs = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 2 > len) { return false; }
  msg->header.seq_num = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->header.update_interval, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->header.iod_atmo, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->header.tropo_quality_indicator, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
			
      
  if (offset + 2 > len) { return false; }
  msg->element.index = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
			
      
  if (offset + 2 > len) { return false; }
  msg->element.tropo_delay_correction.hydro = sbp_unpack_s16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->element.tropo_delay_correction.wet, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->element.tropo_delay_correction.stddev, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      msg->element.n_stec_residuals = (u8)((len - offset) / 5);

	  for (size_t msgelementstec_residuals_idx = 0; msgelementstec_residuals_idx <
				msg->element.n_stec_residuals;
				msgelementstec_residuals_idx++) 
		{
				
			
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->element.stec_residuals[msgelementstec_residuals_idx].sv_id.satId, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->element.stec_residuals[msgelementstec_residuals_idx].sv_id.constellation, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 2 > len) { return false; }
  msg->element.stec_residuals[msgelementstec_residuals_idx].residual = sbp_unpack_s16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->element.stec_residuals[msgelementstec_residuals_idx].stddev, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
		}
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_ssr_tile_definition_t(const sbp_msg_ssr_tile_definition_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				sizeof( msg->tile_set_id )                                                                          
	  +
				sizeof( msg->tile_id )                                                                          
	  +
				sizeof( msg->corner_nw_lat )                                                                          
	  +
				sizeof( msg->corner_nw_lon )                                                                          
	  +
				sizeof( msg->spacing_lat )                                                                          
	  +
				sizeof( msg->spacing_lon )                                                                          
	  +
				sizeof( msg->rows )                                                                          
	  +
				sizeof( msg->cols )                                                                          
	  +
				sizeof( msg->bitmask );
}

static inline bool sbp_pack_sbp_msg_ssr_tile_definition_t(u8 *buf, size_t len, const sbp_msg_ssr_tile_definition_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_ssr_tile_definition_t(msg) > len) { return false; }
  
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->tile_set_id);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->tile_id);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_s16(buf + offset, msg->corner_nw_lat);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_s16(buf + offset, msg->corner_nw_lon);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->spacing_lat);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->spacing_lon);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->rows);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->cols);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 8 > len) { return false; }
  sbp_pack_u64(buf + offset, msg->bitmask);
  // NOLINTNEXTLINE
  offset += 8;
  return true;
}

static inline bool sbp_unpack_sbp_msg_ssr_tile_definition_t(const u8 *buf, size_t len, sbp_msg_ssr_tile_definition_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
      
  if (offset + 2 > len) { return false; }
  msg->tile_set_id = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 2 > len) { return false; }
  msg->tile_id = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 2 > len) { return false; }
  msg->corner_nw_lat = sbp_unpack_s16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 2 > len) { return false; }
  msg->corner_nw_lon = sbp_unpack_s16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 2 > len) { return false; }
  msg->spacing_lat = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 2 > len) { return false; }
  msg->spacing_lon = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 2 > len) { return false; }
  msg->rows = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 2 > len) { return false; }
  msg->cols = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 8 > len) { return false; }
  msg->bitmask = sbp_unpack_u64(buf + offset);
  // NOLINTNEXTLINE
  offset += 8;
  return true;
}

static inline size_t sbp_packed_size_sbp_satellite_apc_t(const sbp_satellite_apc_t *msg) {                                
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
				sizeof( msg->sat_info )                                                                          
	  +
				sizeof( msg->svn )                                                                          
	  +
		  ( 3 *
        sizeof( msg->pco[0] )
		)                                                                          
	  +
		  ( 21 *
        sizeof( msg->pcv[0] )
		);
}

static inline bool sbp_pack_sbp_satellite_apc_t(u8 *buf, size_t len, const sbp_satellite_apc_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_satellite_apc_t(msg) > len) { return false; }
  
				
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->sid.sat , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->sid.code , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->sat_info , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->svn);
  // NOLINTNEXTLINE
  offset += 2;
		  for(size_t msgpco_idx = 0; msgpco_idx < 3; msgpco_idx++)
			{
        
  if (offset + 2 > len) { return false; }
  sbp_pack_s16(buf + offset, msg->pco[msgpco_idx]);
  // NOLINTNEXTLINE
  offset += 2;
			}
		  for(size_t msgpcv_idx = 0; msgpcv_idx < 21; msgpcv_idx++)
			{
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->pcv[msgpcv_idx] , 1);
  // NOLINTNEXTLINE
  offset += 1;
			}
  return true;
}

static inline bool sbp_unpack_sbp_satellite_apc_t(const u8 *buf, size_t len, sbp_satellite_apc_t *msg) {
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
  memcpy(&msg->sat_info, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 2 > len) { return false; }
  msg->svn = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
		for (size_t msgpco_idx = 0; msgpco_idx < 3; msgpco_idx++)
		{
        
  if (offset + 2 > len) { return false; }
  msg->pco[msgpco_idx] = sbp_unpack_s16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
		}
		for (size_t msgpcv_idx = 0; msgpcv_idx < 21; msgpcv_idx++)
		{
        
  if (offset + 1 > len) { return false; }
  memcpy(&msg->pcv[msgpcv_idx], buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
		}
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_ssr_satellite_apc_t(const sbp_msg_ssr_satellite_apc_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
	    (
			  msg->n_apc
			*
				(                                                          
	0                                                                          
	  +
				(                                                          
	0                                                                          
	  +
				sizeof( msg->apc[0].sid.sat )                                                                          
	  +
				sizeof( msg->apc[0].sid.code ) )                                                                          
	  +
				sizeof( msg->apc[0].sat_info )                                                                          
	  +
				sizeof( msg->apc[0].svn )                                                                          
	  +
		  ( 3 *
        sizeof( msg->apc[0].pco[0] )
		)                                                                          
	  +
		  ( 21 *
        sizeof( msg->apc[0].pcv[0] )
		) )
			);
}

static inline bool sbp_pack_sbp_msg_ssr_satellite_apc_t(u8 *buf, size_t len, const sbp_msg_ssr_satellite_apc_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_ssr_satellite_apc_t(msg) > len) { return false; }
  
			for(size_t msgapc_idx = 0; msgapc_idx < (size_t)msg->n_apc; msgapc_idx++)
			{
					
				
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->apc[msgapc_idx].sid.sat , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->apc[msgapc_idx].sid.code , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->apc[msgapc_idx].sat_info , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->apc[msgapc_idx].svn);
  // NOLINTNEXTLINE
  offset += 2;
		  for(size_t msgapcmsgapc_idxpco_idx = 0; msgapcmsgapc_idxpco_idx < 3; msgapcmsgapc_idxpco_idx++)
			{
        
  if (offset + 2 > len) { return false; }
  sbp_pack_s16(buf + offset, msg->apc[msgapc_idx].pco[msgapcmsgapc_idxpco_idx]);
  // NOLINTNEXTLINE
  offset += 2;
			}
		  for(size_t msgapcmsgapc_idxpcv_idx = 0; msgapcmsgapc_idxpcv_idx < 21; msgapcmsgapc_idxpcv_idx++)
			{
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->apc[msgapc_idx].pcv[msgapcmsgapc_idxpcv_idx] , 1);
  // NOLINTNEXTLINE
  offset += 1;
			}
			}
  return true;
}

static inline bool sbp_unpack_sbp_msg_ssr_satellite_apc_t(const u8 *buf, size_t len, sbp_msg_ssr_satellite_apc_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
      msg->n_apc = (u8)((len - offset) / 32);

	  for (size_t msgapc_idx = 0; msgapc_idx <
				msg->n_apc;
				msgapc_idx++) 
		{
				
			
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->apc[msgapc_idx].sid.sat, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->apc[msgapc_idx].sid.code, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->apc[msgapc_idx].sat_info, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 2 > len) { return false; }
  msg->apc[msgapc_idx].svn = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
		for (size_t msgapcmsgapc_idxpco_idx = 0; msgapcmsgapc_idxpco_idx < 3; msgapcmsgapc_idxpco_idx++)
		{
        
  if (offset + 2 > len) { return false; }
  msg->apc[msgapc_idx].pco[msgapcmsgapc_idxpco_idx] = sbp_unpack_s16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
		}
		for (size_t msgapcmsgapc_idxpcv_idx = 0; msgapcmsgapc_idxpcv_idx < 21; msgapcmsgapc_idxpcv_idx++)
		{
        
  if (offset + 1 > len) { return false; }
  memcpy(&msg->apc[msgapc_idx].pcv[msgapcmsgapc_idxpcv_idx], buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
		}
		}
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_ssr_orbit_clock_dep_a_t(const sbp_msg_ssr_orbit_clock_dep_a_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				(                                                          
	0                                                                          
	  +
				sizeof( msg->time.tow )                                                                          
	  +
				sizeof( msg->time.wn ) )                                                                          
	  +
				(                                                          
	0                                                                          
	  +
				sizeof( msg->sid.sat )                                                                          
	  +
				sizeof( msg->sid.code ) )                                                                          
	  +
				sizeof( msg->update_interval )                                                                          
	  +
				sizeof( msg->iod_ssr )                                                                          
	  +
				sizeof( msg->iod )                                                                          
	  +
				sizeof( msg->radial )                                                                          
	  +
				sizeof( msg->along )                                                                          
	  +
				sizeof( msg->cross )                                                                          
	  +
				sizeof( msg->dot_radial )                                                                          
	  +
				sizeof( msg->dot_along )                                                                          
	  +
				sizeof( msg->dot_cross )                                                                          
	  +
				sizeof( msg->c0 )                                                                          
	  +
				sizeof( msg->c1 )                                                                          
	  +
				sizeof( msg->c2 );
}

static inline bool sbp_pack_sbp_msg_ssr_orbit_clock_dep_a_t(u8 *buf, size_t len, const sbp_msg_ssr_orbit_clock_dep_a_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_ssr_orbit_clock_dep_a_t(msg) > len) { return false; }
  
				
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->time.tow);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->time.wn);
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
  memcpy(buf + offset, & msg->update_interval , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->iod_ssr , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->iod , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 4 > len) { return false; }
  sbp_pack_s32(buf + offset, msg->radial);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  sbp_pack_s32(buf + offset, msg->along);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  sbp_pack_s32(buf + offset, msg->cross);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  sbp_pack_s32(buf + offset, msg->dot_radial);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  sbp_pack_s32(buf + offset, msg->dot_along);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  sbp_pack_s32(buf + offset, msg->dot_cross);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  sbp_pack_s32(buf + offset, msg->c0);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  sbp_pack_s32(buf + offset, msg->c1);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  sbp_pack_s32(buf + offset, msg->c2);
  // NOLINTNEXTLINE
  offset += 4;
  return true;
}

static inline bool sbp_unpack_sbp_msg_ssr_orbit_clock_dep_a_t(const u8 *buf, size_t len, sbp_msg_ssr_orbit_clock_dep_a_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
			
      
  if (offset + 4 > len) { return false; }
  msg->time.tow = sbp_unpack_u32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 2 > len) { return false; }
  msg->time.wn = sbp_unpack_u16(buf + offset);
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
  memcpy(&msg->update_interval, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->iod_ssr, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->iod, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 4 > len) { return false; }
  msg->radial = sbp_unpack_s32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  msg->along = sbp_unpack_s32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  msg->cross = sbp_unpack_s32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  msg->dot_radial = sbp_unpack_s32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  msg->dot_along = sbp_unpack_s32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  msg->dot_cross = sbp_unpack_s32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  msg->c0 = sbp_unpack_s32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  msg->c1 = sbp_unpack_s32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  msg->c2 = sbp_unpack_s32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
  return true;
}

static inline size_t sbp_packed_size_sbp_stec_header_dep_a_t(const sbp_stec_header_dep_a_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				(                                                          
	0                                                                          
	  +
				sizeof( msg->time.tow )                                                                          
	  +
				sizeof( msg->time.wn ) )                                                                          
	  +
				sizeof( msg->num_msgs )                                                                          
	  +
				sizeof( msg->seq_num )                                                                          
	  +
				sizeof( msg->update_interval )                                                                          
	  +
				sizeof( msg->iod_atmo );
}

static inline bool sbp_pack_sbp_stec_header_dep_a_t(u8 *buf, size_t len, const sbp_stec_header_dep_a_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_stec_header_dep_a_t(msg) > len) { return false; }
  
				
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->time.tow);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->time.wn);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->num_msgs , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->seq_num , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->update_interval , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->iod_atmo , 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline bool sbp_unpack_sbp_stec_header_dep_a_t(const u8 *buf, size_t len, sbp_stec_header_dep_a_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
			
      
  if (offset + 4 > len) { return false; }
  msg->time.tow = sbp_unpack_u32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 2 > len) { return false; }
  msg->time.wn = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->num_msgs, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->seq_num, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->update_interval, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->iod_atmo, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline size_t sbp_packed_size_sbp_gridded_correction_header_dep_a_t(const sbp_gridded_correction_header_dep_a_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				(                                                          
	0                                                                          
	  +
				sizeof( msg->time.tow )                                                                          
	  +
				sizeof( msg->time.wn ) )                                                                          
	  +
				sizeof( msg->num_msgs )                                                                          
	  +
				sizeof( msg->seq_num )                                                                          
	  +
				sizeof( msg->update_interval )                                                                          
	  +
				sizeof( msg->iod_atmo )                                                                          
	  +
				sizeof( msg->tropo_quality_indicator );
}

static inline bool sbp_pack_sbp_gridded_correction_header_dep_a_t(u8 *buf, size_t len, const sbp_gridded_correction_header_dep_a_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_gridded_correction_header_dep_a_t(msg) > len) { return false; }
  
				
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->time.tow);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->time.wn);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->num_msgs);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->seq_num);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->update_interval , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->iod_atmo , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->tropo_quality_indicator , 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline bool sbp_unpack_sbp_gridded_correction_header_dep_a_t(const u8 *buf, size_t len, sbp_gridded_correction_header_dep_a_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
			
      
  if (offset + 4 > len) { return false; }
  msg->time.tow = sbp_unpack_u32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 2 > len) { return false; }
  msg->time.wn = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 2 > len) { return false; }
  msg->num_msgs = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 2 > len) { return false; }
  msg->seq_num = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->update_interval, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->iod_atmo, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->tropo_quality_indicator, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline size_t sbp_packed_size_sbp_grid_definition_header_dep_a_t(const sbp_grid_definition_header_dep_a_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				sizeof( msg->region_size_inverse )                                                                          
	  +
				sizeof( msg->area_width )                                                                          
	  +
				sizeof( msg->lat_nw_corner_enc )                                                                          
	  +
				sizeof( msg->lon_nw_corner_enc )                                                                          
	  +
				sizeof( msg->num_msgs )                                                                          
	  +
				sizeof( msg->seq_num );
}

static inline bool sbp_pack_sbp_grid_definition_header_dep_a_t(u8 *buf, size_t len, const sbp_grid_definition_header_dep_a_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_grid_definition_header_dep_a_t(msg) > len) { return false; }
  
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->region_size_inverse , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->area_width);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->lat_nw_corner_enc);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->lon_nw_corner_enc);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->num_msgs , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->seq_num , 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline bool sbp_unpack_sbp_grid_definition_header_dep_a_t(const u8 *buf, size_t len, sbp_grid_definition_header_dep_a_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->region_size_inverse, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 2 > len) { return false; }
  msg->area_width = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 2 > len) { return false; }
  msg->lat_nw_corner_enc = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 2 > len) { return false; }
  msg->lon_nw_corner_enc = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->num_msgs, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->seq_num, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_ssr_stec_correction_dep_a_t(const sbp_msg_ssr_stec_correction_dep_a_t *msg) {                                
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
				sizeof( msg->header.time.tow )                                                                          
	  +
				sizeof( msg->header.time.wn ) )                                                                          
	  +
				sizeof( msg->header.num_msgs )                                                                          
	  +
				sizeof( msg->header.seq_num )                                                                          
	  +
				sizeof( msg->header.update_interval )                                                                          
	  +
				sizeof( msg->header.iod_atmo ) )                                                                          
	  +
	    (
			  msg->n_stec_sat_list
			*
				(                                                          
	0                                                                          
	  +
				(                                                          
	0                                                                          
	  +
				sizeof( msg->stec_sat_list[0].sv_id.satId )                                                                          
	  +
				sizeof( msg->stec_sat_list[0].sv_id.constellation ) )                                                                          
	  +
				sizeof( msg->stec_sat_list[0].stec_quality_indicator )                                                                          
	  +
		  ( 4 *
        sizeof( msg->stec_sat_list[0].stec_coeff[0] )
		) )
			);
}

static inline bool sbp_pack_sbp_msg_ssr_stec_correction_dep_a_t(u8 *buf, size_t len, const sbp_msg_ssr_stec_correction_dep_a_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_ssr_stec_correction_dep_a_t(msg) > len) { return false; }
  
				
				
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->header.time.tow);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->header.time.wn);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->header.num_msgs , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->header.seq_num , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->header.update_interval , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->header.iod_atmo , 1);
  // NOLINTNEXTLINE
  offset += 1;
			for(size_t msgstec_sat_list_idx = 0; msgstec_sat_list_idx < (size_t)msg->n_stec_sat_list; msgstec_sat_list_idx++)
			{
					
				
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->stec_sat_list[msgstec_sat_list_idx].sv_id.satId , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->stec_sat_list[msgstec_sat_list_idx].sv_id.constellation , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->stec_sat_list[msgstec_sat_list_idx].stec_quality_indicator , 1);
  // NOLINTNEXTLINE
  offset += 1;
		  for(size_t msgstec_sat_listmsgstec_sat_list_idxstec_coeff_idx = 0; msgstec_sat_listmsgstec_sat_list_idxstec_coeff_idx < 4; msgstec_sat_listmsgstec_sat_list_idxstec_coeff_idx++)
			{
        
  if (offset + 2 > len) { return false; }
  sbp_pack_s16(buf + offset, msg->stec_sat_list[msgstec_sat_list_idx].stec_coeff[msgstec_sat_listmsgstec_sat_list_idxstec_coeff_idx]);
  // NOLINTNEXTLINE
  offset += 2;
			}
			}
  return true;
}

static inline bool sbp_unpack_sbp_msg_ssr_stec_correction_dep_a_t(const u8 *buf, size_t len, sbp_msg_ssr_stec_correction_dep_a_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
			
			
      
  if (offset + 4 > len) { return false; }
  msg->header.time.tow = sbp_unpack_u32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 2 > len) { return false; }
  msg->header.time.wn = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->header.num_msgs, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->header.seq_num, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->header.update_interval, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->header.iod_atmo, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      msg->n_stec_sat_list = (u8)((len - offset) / 11);

	  for (size_t msgstec_sat_list_idx = 0; msgstec_sat_list_idx <
				msg->n_stec_sat_list;
				msgstec_sat_list_idx++) 
		{
				
			
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->stec_sat_list[msgstec_sat_list_idx].sv_id.satId, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->stec_sat_list[msgstec_sat_list_idx].sv_id.constellation, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->stec_sat_list[msgstec_sat_list_idx].stec_quality_indicator, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
		for (size_t msgstec_sat_listmsgstec_sat_list_idxstec_coeff_idx = 0; msgstec_sat_listmsgstec_sat_list_idxstec_coeff_idx < 4; msgstec_sat_listmsgstec_sat_list_idxstec_coeff_idx++)
		{
        
  if (offset + 2 > len) { return false; }
  msg->stec_sat_list[msgstec_sat_list_idx].stec_coeff[msgstec_sat_listmsgstec_sat_list_idxstec_coeff_idx] = sbp_unpack_s16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
		}
		}
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_ssr_gridded_correction_no_std_dep_a_t(const sbp_msg_ssr_gridded_correction_no_std_dep_a_t *msg) {                                
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
				sizeof( msg->header.time.tow )                                                                          
	  +
				sizeof( msg->header.time.wn ) )                                                                          
	  +
				sizeof( msg->header.num_msgs )                                                                          
	  +
				sizeof( msg->header.seq_num )                                                                          
	  +
				sizeof( msg->header.update_interval )                                                                          
	  +
				sizeof( msg->header.iod_atmo )                                                                          
	  +
				sizeof( msg->header.tropo_quality_indicator ) )                                                                          
	  +
				(                                                          
	0                                                                          
	  +
				sizeof( msg->element.index )                                                                          
	  +
				(                                                          
	0                                                                          
	  +
				sizeof( msg->element.tropo_delay_correction.hydro )                                                                          
	  +
				sizeof( msg->element.tropo_delay_correction.wet ) )                                                                          
	  +
	    (
			  msg->element.n_stec_residuals
			*
				(                                                          
	0                                                                          
	  +
				(                                                          
	0                                                                          
	  +
				sizeof( msg->element.stec_residuals[0].sv_id.satId )                                                                          
	  +
				sizeof( msg->element.stec_residuals[0].sv_id.constellation ) )                                                                          
	  +
				sizeof( msg->element.stec_residuals[0].residual ) )
			) );
}

static inline bool sbp_pack_sbp_msg_ssr_gridded_correction_no_std_dep_a_t(u8 *buf, size_t len, const sbp_msg_ssr_gridded_correction_no_std_dep_a_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_ssr_gridded_correction_no_std_dep_a_t(msg) > len) { return false; }
  
				
				
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->header.time.tow);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->header.time.wn);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->header.num_msgs);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->header.seq_num);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->header.update_interval , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->header.iod_atmo , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->header.tropo_quality_indicator , 1);
  // NOLINTNEXTLINE
  offset += 1;
				
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->element.index);
  // NOLINTNEXTLINE
  offset += 2;
				
        
  if (offset + 2 > len) { return false; }
  sbp_pack_s16(buf + offset, msg->element.tropo_delay_correction.hydro);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->element.tropo_delay_correction.wet , 1);
  // NOLINTNEXTLINE
  offset += 1;
			for(size_t msgelementstec_residuals_idx = 0; msgelementstec_residuals_idx < (size_t)msg->element.n_stec_residuals; msgelementstec_residuals_idx++)
			{
					
				
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->element.stec_residuals[msgelementstec_residuals_idx].sv_id.satId , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->element.stec_residuals[msgelementstec_residuals_idx].sv_id.constellation , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_s16(buf + offset, msg->element.stec_residuals[msgelementstec_residuals_idx].residual);
  // NOLINTNEXTLINE
  offset += 2;
			}
  return true;
}

static inline bool sbp_unpack_sbp_msg_ssr_gridded_correction_no_std_dep_a_t(const u8 *buf, size_t len, sbp_msg_ssr_gridded_correction_no_std_dep_a_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
			
			
      
  if (offset + 4 > len) { return false; }
  msg->header.time.tow = sbp_unpack_u32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 2 > len) { return false; }
  msg->header.time.wn = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 2 > len) { return false; }
  msg->header.num_msgs = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 2 > len) { return false; }
  msg->header.seq_num = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->header.update_interval, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->header.iod_atmo, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->header.tropo_quality_indicator, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
			
      
  if (offset + 2 > len) { return false; }
  msg->element.index = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
			
      
  if (offset + 2 > len) { return false; }
  msg->element.tropo_delay_correction.hydro = sbp_unpack_s16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->element.tropo_delay_correction.wet, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      msg->element.n_stec_residuals = (u8)((len - offset) / 4);

	  for (size_t msgelementstec_residuals_idx = 0; msgelementstec_residuals_idx <
				msg->element.n_stec_residuals;
				msgelementstec_residuals_idx++) 
		{
				
			
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->element.stec_residuals[msgelementstec_residuals_idx].sv_id.satId, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->element.stec_residuals[msgelementstec_residuals_idx].sv_id.constellation, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 2 > len) { return false; }
  msg->element.stec_residuals[msgelementstec_residuals_idx].residual = sbp_unpack_s16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
		}
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_ssr_gridded_correction_dep_a_t(const sbp_msg_ssr_gridded_correction_dep_a_t *msg) {                                
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
				sizeof( msg->header.time.tow )                                                                          
	  +
				sizeof( msg->header.time.wn ) )                                                                          
	  +
				sizeof( msg->header.num_msgs )                                                                          
	  +
				sizeof( msg->header.seq_num )                                                                          
	  +
				sizeof( msg->header.update_interval )                                                                          
	  +
				sizeof( msg->header.iod_atmo )                                                                          
	  +
				sizeof( msg->header.tropo_quality_indicator ) )                                                                          
	  +
				(                                                          
	0                                                                          
	  +
				sizeof( msg->element.index )                                                                          
	  +
				(                                                          
	0                                                                          
	  +
				sizeof( msg->element.tropo_delay_correction.hydro )                                                                          
	  +
				sizeof( msg->element.tropo_delay_correction.wet )                                                                          
	  +
				sizeof( msg->element.tropo_delay_correction.stddev ) )                                                                          
	  +
	    (
			  msg->element.n_stec_residuals
			*
				(                                                          
	0                                                                          
	  +
				(                                                          
	0                                                                          
	  +
				sizeof( msg->element.stec_residuals[0].sv_id.satId )                                                                          
	  +
				sizeof( msg->element.stec_residuals[0].sv_id.constellation ) )                                                                          
	  +
				sizeof( msg->element.stec_residuals[0].residual )                                                                          
	  +
				sizeof( msg->element.stec_residuals[0].stddev ) )
			) );
}

static inline bool sbp_pack_sbp_msg_ssr_gridded_correction_dep_a_t(u8 *buf, size_t len, const sbp_msg_ssr_gridded_correction_dep_a_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_ssr_gridded_correction_dep_a_t(msg) > len) { return false; }
  
				
				
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->header.time.tow);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->header.time.wn);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->header.num_msgs);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->header.seq_num);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->header.update_interval , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->header.iod_atmo , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->header.tropo_quality_indicator , 1);
  // NOLINTNEXTLINE
  offset += 1;
				
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->element.index);
  // NOLINTNEXTLINE
  offset += 2;
				
        
  if (offset + 2 > len) { return false; }
  sbp_pack_s16(buf + offset, msg->element.tropo_delay_correction.hydro);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->element.tropo_delay_correction.wet , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->element.tropo_delay_correction.stddev , 1);
  // NOLINTNEXTLINE
  offset += 1;
			for(size_t msgelementstec_residuals_idx = 0; msgelementstec_residuals_idx < (size_t)msg->element.n_stec_residuals; msgelementstec_residuals_idx++)
			{
					
				
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->element.stec_residuals[msgelementstec_residuals_idx].sv_id.satId , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->element.stec_residuals[msgelementstec_residuals_idx].sv_id.constellation , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_s16(buf + offset, msg->element.stec_residuals[msgelementstec_residuals_idx].residual);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->element.stec_residuals[msgelementstec_residuals_idx].stddev , 1);
  // NOLINTNEXTLINE
  offset += 1;
			}
  return true;
}

static inline bool sbp_unpack_sbp_msg_ssr_gridded_correction_dep_a_t(const u8 *buf, size_t len, sbp_msg_ssr_gridded_correction_dep_a_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
			
			
      
  if (offset + 4 > len) { return false; }
  msg->header.time.tow = sbp_unpack_u32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 2 > len) { return false; }
  msg->header.time.wn = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 2 > len) { return false; }
  msg->header.num_msgs = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 2 > len) { return false; }
  msg->header.seq_num = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->header.update_interval, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->header.iod_atmo, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->header.tropo_quality_indicator, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
			
      
  if (offset + 2 > len) { return false; }
  msg->element.index = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
			
      
  if (offset + 2 > len) { return false; }
  msg->element.tropo_delay_correction.hydro = sbp_unpack_s16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->element.tropo_delay_correction.wet, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->element.tropo_delay_correction.stddev, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      msg->element.n_stec_residuals = (u8)((len - offset) / 5);

	  for (size_t msgelementstec_residuals_idx = 0; msgelementstec_residuals_idx <
				msg->element.n_stec_residuals;
				msgelementstec_residuals_idx++) 
		{
				
			
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->element.stec_residuals[msgelementstec_residuals_idx].sv_id.satId, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->element.stec_residuals[msgelementstec_residuals_idx].sv_id.constellation, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 2 > len) { return false; }
  msg->element.stec_residuals[msgelementstec_residuals_idx].residual = sbp_unpack_s16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->element.stec_residuals[msgelementstec_residuals_idx].stddev, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
		}
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_ssr_grid_definition_dep_a_t(const sbp_msg_ssr_grid_definition_dep_a_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				(                                                          
	0                                                                          
	  +
				sizeof( msg->header.region_size_inverse )                                                                          
	  +
				sizeof( msg->header.area_width )                                                                          
	  +
				sizeof( msg->header.lat_nw_corner_enc )                                                                          
	  +
				sizeof( msg->header.lon_nw_corner_enc )                                                                          
	  +
				sizeof( msg->header.num_msgs )                                                                          
	  +
				sizeof( msg->header.seq_num ) )                                                                          
	  +
	    (
			  msg->n_rle_list
			*
        sizeof( msg->rle_list[0] )
			);
}

static inline bool sbp_pack_sbp_msg_ssr_grid_definition_dep_a_t(u8 *buf, size_t len, const sbp_msg_ssr_grid_definition_dep_a_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_ssr_grid_definition_dep_a_t(msg) > len) { return false; }
  
				
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->header.region_size_inverse , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->header.area_width);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->header.lat_nw_corner_enc);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->header.lon_nw_corner_enc);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->header.num_msgs , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->header.seq_num , 1);
  // NOLINTNEXTLINE
  offset += 1;
			for(size_t msgrle_list_idx = 0; msgrle_list_idx < (size_t)msg->n_rle_list; msgrle_list_idx++)
			{
          
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->rle_list[msgrle_list_idx] , 1);
  // NOLINTNEXTLINE
  offset += 1;
			}
  return true;
}

static inline bool sbp_unpack_sbp_msg_ssr_grid_definition_dep_a_t(const u8 *buf, size_t len, sbp_msg_ssr_grid_definition_dep_a_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
			
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->header.region_size_inverse, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 2 > len) { return false; }
  msg->header.area_width = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 2 > len) { return false; }
  msg->header.lat_nw_corner_enc = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 2 > len) { return false; }
  msg->header.lon_nw_corner_enc = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->header.num_msgs, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->header.seq_num, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      msg->n_rle_list = (u8)((len - offset) / 1);

	  for (size_t msgrle_list_idx = 0; msgrle_list_idx <
				msg->n_rle_list;
				msgrle_list_idx++) 
		{
        
  if (offset + 1 > len) { return false; }
  memcpy(&msg->rle_list[msgrle_list_idx], buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
		}
  return true;
}

#endif
