#ifndef LIBSBP_NAVIGATION_PACKERS_H
#define LIBSBP_NAVIGATION_PACKERS_H

#ifndef LIBSBP_NAVIGATION_MESSAGES_H
#error "Do not include this file directly, include libsbp/unpacked/navigation.h instead"
#endif

#include <stdbool.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>
#include <math.h>

#include <libsbp/common.h>
#include <libsbp/string.h>

static inline size_t sbp_packed_size_sbp_msg_gps_time_t(const sbp_msg_gps_time_t *msg) {                                
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
				sizeof( msg->flags );
}

static inline bool sbp_pack_sbp_msg_gps_time_t(u8 *buf, size_t len, const sbp_msg_gps_time_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_gps_time_t(msg) > len) { return false; }
  
        
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
  return true;
}

static inline bool sbp_unpack_sbp_msg_gps_time_t(const u8 *buf, size_t len, sbp_msg_gps_time_t *msg) {
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
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_gps_time_gnss_t(const sbp_msg_gps_time_gnss_t *msg) {                                
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
				sizeof( msg->flags );
}

static inline bool sbp_pack_sbp_msg_gps_time_gnss_t(u8 *buf, size_t len, const sbp_msg_gps_time_gnss_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_gps_time_gnss_t(msg) > len) { return false; }
  
        
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
  return true;
}

static inline bool sbp_unpack_sbp_msg_gps_time_gnss_t(const u8 *buf, size_t len, sbp_msg_gps_time_gnss_t *msg) {
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
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_utc_time_t(const sbp_msg_utc_time_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				sizeof( msg->flags )                                                                          
	  +
				sizeof( msg->tow )                                                                          
	  +
				sizeof( msg->year )                                                                          
	  +
				sizeof( msg->month )                                                                          
	  +
				sizeof( msg->day )                                                                          
	  +
				sizeof( msg->hours )                                                                          
	  +
				sizeof( msg->minutes )                                                                          
	  +
				sizeof( msg->seconds )                                                                          
	  +
				sizeof( msg->ns );
}

static inline bool sbp_pack_sbp_msg_utc_time_t(u8 *buf, size_t len, const sbp_msg_utc_time_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_utc_time_t(msg) > len) { return false; }
  
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->flags , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->tow);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->year);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->month , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->day , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->hours , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->minutes , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->seconds , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->ns);
  // NOLINTNEXTLINE
  offset += 4;
  return true;
}

static inline bool sbp_unpack_sbp_msg_utc_time_t(const u8 *buf, size_t len, sbp_msg_utc_time_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->flags, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 4 > len) { return false; }
  msg->tow = sbp_unpack_u32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 2 > len) { return false; }
  msg->year = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->month, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->day, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->hours, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->minutes, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->seconds, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 4 > len) { return false; }
  msg->ns = sbp_unpack_u32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_utc_time_gnss_t(const sbp_msg_utc_time_gnss_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				sizeof( msg->flags )                                                                          
	  +
				sizeof( msg->tow )                                                                          
	  +
				sizeof( msg->year )                                                                          
	  +
				sizeof( msg->month )                                                                          
	  +
				sizeof( msg->day )                                                                          
	  +
				sizeof( msg->hours )                                                                          
	  +
				sizeof( msg->minutes )                                                                          
	  +
				sizeof( msg->seconds )                                                                          
	  +
				sizeof( msg->ns );
}

static inline bool sbp_pack_sbp_msg_utc_time_gnss_t(u8 *buf, size_t len, const sbp_msg_utc_time_gnss_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_utc_time_gnss_t(msg) > len) { return false; }
  
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->flags , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->tow);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->year);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->month , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->day , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->hours , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->minutes , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->seconds , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->ns);
  // NOLINTNEXTLINE
  offset += 4;
  return true;
}

static inline bool sbp_unpack_sbp_msg_utc_time_gnss_t(const u8 *buf, size_t len, sbp_msg_utc_time_gnss_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->flags, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 4 > len) { return false; }
  msg->tow = sbp_unpack_u32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 2 > len) { return false; }
  msg->year = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->month, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->day, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->hours, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->minutes, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->seconds, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 4 > len) { return false; }
  msg->ns = sbp_unpack_u32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_dops_t(const sbp_msg_dops_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				sizeof( msg->tow )                                                                          
	  +
				sizeof( msg->gdop )                                                                          
	  +
				sizeof( msg->pdop )                                                                          
	  +
				sizeof( msg->tdop )                                                                          
	  +
				sizeof( msg->hdop )                                                                          
	  +
				sizeof( msg->vdop )                                                                          
	  +
				sizeof( msg->flags );
}

static inline bool sbp_pack_sbp_msg_dops_t(u8 *buf, size_t len, const sbp_msg_dops_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_dops_t(msg) > len) { return false; }
  
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->tow);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->gdop);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->pdop);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->tdop);
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
  memcpy(buf + offset, & msg->flags , 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline bool sbp_unpack_sbp_msg_dops_t(const u8 *buf, size_t len, sbp_msg_dops_t *msg) {
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
  msg->gdop = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 2 > len) { return false; }
  msg->pdop = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 2 > len) { return false; }
  msg->tdop = sbp_unpack_u16(buf + offset);
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
  memcpy(&msg->flags, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_pos_ecef_t(const sbp_msg_pos_ecef_t *msg) {                                
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
				sizeof( msg->accuracy )                                                                          
	  +
				sizeof( msg->n_sats )                                                                          
	  +
				sizeof( msg->flags );
}

static inline bool sbp_pack_sbp_msg_pos_ecef_t(u8 *buf, size_t len, const sbp_msg_pos_ecef_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_pos_ecef_t(msg) > len) { return false; }
  
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->tow);
  // NOLINTNEXTLINE
  offset += 4;
        
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
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->accuracy);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->n_sats , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->flags , 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline bool sbp_unpack_sbp_msg_pos_ecef_t(const u8 *buf, size_t len, sbp_msg_pos_ecef_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
      
  if (offset + 4 > len) { return false; }
  msg->tow = sbp_unpack_u32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
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
      
  if (offset + 2 > len) { return false; }
  msg->accuracy = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
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

static inline size_t sbp_packed_size_sbp_msg_pos_ecef_cov_t(const sbp_msg_pos_ecef_cov_t *msg) {                                
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
				sizeof( msg->cov_x_x )                                                                          
	  +
				sizeof( msg->cov_x_y )                                                                          
	  +
				sizeof( msg->cov_x_z )                                                                          
	  +
				sizeof( msg->cov_y_y )                                                                          
	  +
				sizeof( msg->cov_y_z )                                                                          
	  +
				sizeof( msg->cov_z_z )                                                                          
	  +
				sizeof( msg->n_sats )                                                                          
	  +
				sizeof( msg->flags );
}

static inline bool sbp_pack_sbp_msg_pos_ecef_cov_t(u8 *buf, size_t len, const sbp_msg_pos_ecef_cov_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_pos_ecef_cov_t(msg) > len) { return false; }
  
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->tow);
  // NOLINTNEXTLINE
  offset += 4;
        
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
        
  if (offset + 4 > len) { return false; }
  memcpy(buf + offset, & msg->cov_x_x , 4);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  memcpy(buf + offset, & msg->cov_x_y , 4);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  memcpy(buf + offset, & msg->cov_x_z , 4);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  memcpy(buf + offset, & msg->cov_y_y , 4);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  memcpy(buf + offset, & msg->cov_y_z , 4);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  memcpy(buf + offset, & msg->cov_z_z , 4);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->n_sats , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->flags , 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline bool sbp_unpack_sbp_msg_pos_ecef_cov_t(const u8 *buf, size_t len, sbp_msg_pos_ecef_cov_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
      
  if (offset + 4 > len) { return false; }
  msg->tow = sbp_unpack_u32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
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
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->cov_x_x, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->cov_x_y, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->cov_x_z, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->cov_y_y, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->cov_y_z, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->cov_z_z, buf + offset, 4);
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

static inline size_t sbp_packed_size_sbp_msg_pos_llh_t(const sbp_msg_pos_llh_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				sizeof( msg->tow )                                                                          
	  +
				sizeof( msg->lat )                                                                          
	  +
				sizeof( msg->lon )                                                                          
	  +
				sizeof( msg->height )                                                                          
	  +
				sizeof( msg->h_accuracy )                                                                          
	  +
				sizeof( msg->v_accuracy )                                                                          
	  +
				sizeof( msg->n_sats )                                                                          
	  +
				sizeof( msg->flags );
}

static inline bool sbp_pack_sbp_msg_pos_llh_t(u8 *buf, size_t len, const sbp_msg_pos_llh_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_pos_llh_t(msg) > len) { return false; }
  
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->tow);
  // NOLINTNEXTLINE
  offset += 4;
        
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
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->h_accuracy);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->v_accuracy);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->n_sats , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->flags , 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline bool sbp_unpack_sbp_msg_pos_llh_t(const u8 *buf, size_t len, sbp_msg_pos_llh_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
      
  if (offset + 4 > len) { return false; }
  msg->tow = sbp_unpack_u32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
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
      
  if (offset + 2 > len) { return false; }
  msg->h_accuracy = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 2 > len) { return false; }
  msg->v_accuracy = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
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

static inline size_t sbp_packed_size_sbp_msg_pos_llh_cov_t(const sbp_msg_pos_llh_cov_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				sizeof( msg->tow )                                                                          
	  +
				sizeof( msg->lat )                                                                          
	  +
				sizeof( msg->lon )                                                                          
	  +
				sizeof( msg->height )                                                                          
	  +
				sizeof( msg->cov_n_n )                                                                          
	  +
				sizeof( msg->cov_n_e )                                                                          
	  +
				sizeof( msg->cov_n_d )                                                                          
	  +
				sizeof( msg->cov_e_e )                                                                          
	  +
				sizeof( msg->cov_e_d )                                                                          
	  +
				sizeof( msg->cov_d_d )                                                                          
	  +
				sizeof( msg->n_sats )                                                                          
	  +
				sizeof( msg->flags );
}

static inline bool sbp_pack_sbp_msg_pos_llh_cov_t(u8 *buf, size_t len, const sbp_msg_pos_llh_cov_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_pos_llh_cov_t(msg) > len) { return false; }
  
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->tow);
  // NOLINTNEXTLINE
  offset += 4;
        
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
        
  if (offset + 4 > len) { return false; }
  memcpy(buf + offset, & msg->cov_n_n , 4);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  memcpy(buf + offset, & msg->cov_n_e , 4);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  memcpy(buf + offset, & msg->cov_n_d , 4);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  memcpy(buf + offset, & msg->cov_e_e , 4);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  memcpy(buf + offset, & msg->cov_e_d , 4);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  memcpy(buf + offset, & msg->cov_d_d , 4);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->n_sats , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->flags , 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline bool sbp_unpack_sbp_msg_pos_llh_cov_t(const u8 *buf, size_t len, sbp_msg_pos_llh_cov_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
      
  if (offset + 4 > len) { return false; }
  msg->tow = sbp_unpack_u32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
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
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->cov_n_n, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->cov_n_e, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->cov_n_d, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->cov_e_e, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->cov_e_d, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->cov_d_d, buf + offset, 4);
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

static inline size_t sbp_packed_size_sbp_msg_baseline_ecef_t(const sbp_msg_baseline_ecef_t *msg) {                                
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
				sizeof( msg->accuracy )                                                                          
	  +
				sizeof( msg->n_sats )                                                                          
	  +
				sizeof( msg->flags );
}

static inline bool sbp_pack_sbp_msg_baseline_ecef_t(u8 *buf, size_t len, const sbp_msg_baseline_ecef_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_baseline_ecef_t(msg) > len) { return false; }
  
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->tow);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  sbp_pack_s32(buf + offset, msg->x);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  sbp_pack_s32(buf + offset, msg->y);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  sbp_pack_s32(buf + offset, msg->z);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->accuracy);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->n_sats , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->flags , 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline bool sbp_unpack_sbp_msg_baseline_ecef_t(const u8 *buf, size_t len, sbp_msg_baseline_ecef_t *msg) {
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
  msg->x = sbp_unpack_s32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  msg->y = sbp_unpack_s32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  msg->z = sbp_unpack_s32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 2 > len) { return false; }
  msg->accuracy = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
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

static inline size_t sbp_packed_size_sbp_msg_baseline_ned_t(const sbp_msg_baseline_ned_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				sizeof( msg->tow )                                                                          
	  +
				sizeof( msg->n )                                                                          
	  +
				sizeof( msg->e )                                                                          
	  +
				sizeof( msg->d )                                                                          
	  +
				sizeof( msg->h_accuracy )                                                                          
	  +
				sizeof( msg->v_accuracy )                                                                          
	  +
				sizeof( msg->n_sats )                                                                          
	  +
				sizeof( msg->flags );
}

static inline bool sbp_pack_sbp_msg_baseline_ned_t(u8 *buf, size_t len, const sbp_msg_baseline_ned_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_baseline_ned_t(msg) > len) { return false; }
  
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->tow);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  sbp_pack_s32(buf + offset, msg->n);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  sbp_pack_s32(buf + offset, msg->e);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  sbp_pack_s32(buf + offset, msg->d);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->h_accuracy);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->v_accuracy);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->n_sats , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->flags , 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline bool sbp_unpack_sbp_msg_baseline_ned_t(const u8 *buf, size_t len, sbp_msg_baseline_ned_t *msg) {
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
  msg->n = sbp_unpack_s32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  msg->e = sbp_unpack_s32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  msg->d = sbp_unpack_s32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 2 > len) { return false; }
  msg->h_accuracy = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 2 > len) { return false; }
  msg->v_accuracy = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
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

static inline size_t sbp_packed_size_sbp_msg_vel_ecef_t(const sbp_msg_vel_ecef_t *msg) {                                
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
				sizeof( msg->accuracy )                                                                          
	  +
				sizeof( msg->n_sats )                                                                          
	  +
				sizeof( msg->flags );
}

static inline bool sbp_pack_sbp_msg_vel_ecef_t(u8 *buf, size_t len, const sbp_msg_vel_ecef_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_vel_ecef_t(msg) > len) { return false; }
  
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->tow);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  sbp_pack_s32(buf + offset, msg->x);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  sbp_pack_s32(buf + offset, msg->y);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  sbp_pack_s32(buf + offset, msg->z);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->accuracy);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->n_sats , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->flags , 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline bool sbp_unpack_sbp_msg_vel_ecef_t(const u8 *buf, size_t len, sbp_msg_vel_ecef_t *msg) {
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
  msg->x = sbp_unpack_s32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  msg->y = sbp_unpack_s32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  msg->z = sbp_unpack_s32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 2 > len) { return false; }
  msg->accuracy = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
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

static inline size_t sbp_packed_size_sbp_msg_vel_ecef_cov_t(const sbp_msg_vel_ecef_cov_t *msg) {                                
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
				sizeof( msg->cov_x_x )                                                                          
	  +
				sizeof( msg->cov_x_y )                                                                          
	  +
				sizeof( msg->cov_x_z )                                                                          
	  +
				sizeof( msg->cov_y_y )                                                                          
	  +
				sizeof( msg->cov_y_z )                                                                          
	  +
				sizeof( msg->cov_z_z )                                                                          
	  +
				sizeof( msg->n_sats )                                                                          
	  +
				sizeof( msg->flags );
}

static inline bool sbp_pack_sbp_msg_vel_ecef_cov_t(u8 *buf, size_t len, const sbp_msg_vel_ecef_cov_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_vel_ecef_cov_t(msg) > len) { return false; }
  
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->tow);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  sbp_pack_s32(buf + offset, msg->x);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  sbp_pack_s32(buf + offset, msg->y);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  sbp_pack_s32(buf + offset, msg->z);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  memcpy(buf + offset, & msg->cov_x_x , 4);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  memcpy(buf + offset, & msg->cov_x_y , 4);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  memcpy(buf + offset, & msg->cov_x_z , 4);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  memcpy(buf + offset, & msg->cov_y_y , 4);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  memcpy(buf + offset, & msg->cov_y_z , 4);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  memcpy(buf + offset, & msg->cov_z_z , 4);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->n_sats , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->flags , 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline bool sbp_unpack_sbp_msg_vel_ecef_cov_t(const u8 *buf, size_t len, sbp_msg_vel_ecef_cov_t *msg) {
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
  msg->x = sbp_unpack_s32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  msg->y = sbp_unpack_s32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  msg->z = sbp_unpack_s32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->cov_x_x, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->cov_x_y, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->cov_x_z, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->cov_y_y, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->cov_y_z, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->cov_z_z, buf + offset, 4);
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

static inline size_t sbp_packed_size_sbp_msg_vel_ned_t(const sbp_msg_vel_ned_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				sizeof( msg->tow )                                                                          
	  +
				sizeof( msg->n )                                                                          
	  +
				sizeof( msg->e )                                                                          
	  +
				sizeof( msg->d )                                                                          
	  +
				sizeof( msg->h_accuracy )                                                                          
	  +
				sizeof( msg->v_accuracy )                                                                          
	  +
				sizeof( msg->n_sats )                                                                          
	  +
				sizeof( msg->flags );
}

static inline bool sbp_pack_sbp_msg_vel_ned_t(u8 *buf, size_t len, const sbp_msg_vel_ned_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_vel_ned_t(msg) > len) { return false; }
  
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->tow);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  sbp_pack_s32(buf + offset, msg->n);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  sbp_pack_s32(buf + offset, msg->e);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  sbp_pack_s32(buf + offset, msg->d);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->h_accuracy);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->v_accuracy);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->n_sats , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->flags , 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline bool sbp_unpack_sbp_msg_vel_ned_t(const u8 *buf, size_t len, sbp_msg_vel_ned_t *msg) {
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
  msg->n = sbp_unpack_s32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  msg->e = sbp_unpack_s32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  msg->d = sbp_unpack_s32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 2 > len) { return false; }
  msg->h_accuracy = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 2 > len) { return false; }
  msg->v_accuracy = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
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

static inline size_t sbp_packed_size_sbp_msg_vel_ned_cov_t(const sbp_msg_vel_ned_cov_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				sizeof( msg->tow )                                                                          
	  +
				sizeof( msg->n )                                                                          
	  +
				sizeof( msg->e )                                                                          
	  +
				sizeof( msg->d )                                                                          
	  +
				sizeof( msg->cov_n_n )                                                                          
	  +
				sizeof( msg->cov_n_e )                                                                          
	  +
				sizeof( msg->cov_n_d )                                                                          
	  +
				sizeof( msg->cov_e_e )                                                                          
	  +
				sizeof( msg->cov_e_d )                                                                          
	  +
				sizeof( msg->cov_d_d )                                                                          
	  +
				sizeof( msg->n_sats )                                                                          
	  +
				sizeof( msg->flags );
}

static inline bool sbp_pack_sbp_msg_vel_ned_cov_t(u8 *buf, size_t len, const sbp_msg_vel_ned_cov_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_vel_ned_cov_t(msg) > len) { return false; }
  
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->tow);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  sbp_pack_s32(buf + offset, msg->n);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  sbp_pack_s32(buf + offset, msg->e);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  sbp_pack_s32(buf + offset, msg->d);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  memcpy(buf + offset, & msg->cov_n_n , 4);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  memcpy(buf + offset, & msg->cov_n_e , 4);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  memcpy(buf + offset, & msg->cov_n_d , 4);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  memcpy(buf + offset, & msg->cov_e_e , 4);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  memcpy(buf + offset, & msg->cov_e_d , 4);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  memcpy(buf + offset, & msg->cov_d_d , 4);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->n_sats , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->flags , 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline bool sbp_unpack_sbp_msg_vel_ned_cov_t(const u8 *buf, size_t len, sbp_msg_vel_ned_cov_t *msg) {
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
  msg->n = sbp_unpack_s32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  msg->e = sbp_unpack_s32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  msg->d = sbp_unpack_s32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->cov_n_n, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->cov_n_e, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->cov_n_d, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->cov_e_e, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->cov_e_d, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->cov_d_d, buf + offset, 4);
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

static inline size_t sbp_packed_size_sbp_msg_pos_ecef_gnss_t(const sbp_msg_pos_ecef_gnss_t *msg) {                                
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
				sizeof( msg->accuracy )                                                                          
	  +
				sizeof( msg->n_sats )                                                                          
	  +
				sizeof( msg->flags );
}

static inline bool sbp_pack_sbp_msg_pos_ecef_gnss_t(u8 *buf, size_t len, const sbp_msg_pos_ecef_gnss_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_pos_ecef_gnss_t(msg) > len) { return false; }
  
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->tow);
  // NOLINTNEXTLINE
  offset += 4;
        
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
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->accuracy);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->n_sats , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->flags , 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline bool sbp_unpack_sbp_msg_pos_ecef_gnss_t(const u8 *buf, size_t len, sbp_msg_pos_ecef_gnss_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
      
  if (offset + 4 > len) { return false; }
  msg->tow = sbp_unpack_u32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
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
      
  if (offset + 2 > len) { return false; }
  msg->accuracy = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
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

static inline size_t sbp_packed_size_sbp_msg_pos_ecef_cov_gnss_t(const sbp_msg_pos_ecef_cov_gnss_t *msg) {                                
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
				sizeof( msg->cov_x_x )                                                                          
	  +
				sizeof( msg->cov_x_y )                                                                          
	  +
				sizeof( msg->cov_x_z )                                                                          
	  +
				sizeof( msg->cov_y_y )                                                                          
	  +
				sizeof( msg->cov_y_z )                                                                          
	  +
				sizeof( msg->cov_z_z )                                                                          
	  +
				sizeof( msg->n_sats )                                                                          
	  +
				sizeof( msg->flags );
}

static inline bool sbp_pack_sbp_msg_pos_ecef_cov_gnss_t(u8 *buf, size_t len, const sbp_msg_pos_ecef_cov_gnss_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_pos_ecef_cov_gnss_t(msg) > len) { return false; }
  
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->tow);
  // NOLINTNEXTLINE
  offset += 4;
        
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
        
  if (offset + 4 > len) { return false; }
  memcpy(buf + offset, & msg->cov_x_x , 4);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  memcpy(buf + offset, & msg->cov_x_y , 4);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  memcpy(buf + offset, & msg->cov_x_z , 4);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  memcpy(buf + offset, & msg->cov_y_y , 4);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  memcpy(buf + offset, & msg->cov_y_z , 4);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  memcpy(buf + offset, & msg->cov_z_z , 4);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->n_sats , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->flags , 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline bool sbp_unpack_sbp_msg_pos_ecef_cov_gnss_t(const u8 *buf, size_t len, sbp_msg_pos_ecef_cov_gnss_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
      
  if (offset + 4 > len) { return false; }
  msg->tow = sbp_unpack_u32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
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
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->cov_x_x, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->cov_x_y, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->cov_x_z, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->cov_y_y, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->cov_y_z, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->cov_z_z, buf + offset, 4);
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

static inline size_t sbp_packed_size_sbp_msg_pos_llh_gnss_t(const sbp_msg_pos_llh_gnss_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				sizeof( msg->tow )                                                                          
	  +
				sizeof( msg->lat )                                                                          
	  +
				sizeof( msg->lon )                                                                          
	  +
				sizeof( msg->height )                                                                          
	  +
				sizeof( msg->h_accuracy )                                                                          
	  +
				sizeof( msg->v_accuracy )                                                                          
	  +
				sizeof( msg->n_sats )                                                                          
	  +
				sizeof( msg->flags );
}

static inline bool sbp_pack_sbp_msg_pos_llh_gnss_t(u8 *buf, size_t len, const sbp_msg_pos_llh_gnss_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_pos_llh_gnss_t(msg) > len) { return false; }
  
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->tow);
  // NOLINTNEXTLINE
  offset += 4;
        
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
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->h_accuracy);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->v_accuracy);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->n_sats , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->flags , 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline bool sbp_unpack_sbp_msg_pos_llh_gnss_t(const u8 *buf, size_t len, sbp_msg_pos_llh_gnss_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
      
  if (offset + 4 > len) { return false; }
  msg->tow = sbp_unpack_u32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
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
      
  if (offset + 2 > len) { return false; }
  msg->h_accuracy = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 2 > len) { return false; }
  msg->v_accuracy = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
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

static inline size_t sbp_packed_size_sbp_msg_pos_llh_cov_gnss_t(const sbp_msg_pos_llh_cov_gnss_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				sizeof( msg->tow )                                                                          
	  +
				sizeof( msg->lat )                                                                          
	  +
				sizeof( msg->lon )                                                                          
	  +
				sizeof( msg->height )                                                                          
	  +
				sizeof( msg->cov_n_n )                                                                          
	  +
				sizeof( msg->cov_n_e )                                                                          
	  +
				sizeof( msg->cov_n_d )                                                                          
	  +
				sizeof( msg->cov_e_e )                                                                          
	  +
				sizeof( msg->cov_e_d )                                                                          
	  +
				sizeof( msg->cov_d_d )                                                                          
	  +
				sizeof( msg->n_sats )                                                                          
	  +
				sizeof( msg->flags );
}

static inline bool sbp_pack_sbp_msg_pos_llh_cov_gnss_t(u8 *buf, size_t len, const sbp_msg_pos_llh_cov_gnss_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_pos_llh_cov_gnss_t(msg) > len) { return false; }
  
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->tow);
  // NOLINTNEXTLINE
  offset += 4;
        
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
        
  if (offset + 4 > len) { return false; }
  memcpy(buf + offset, & msg->cov_n_n , 4);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  memcpy(buf + offset, & msg->cov_n_e , 4);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  memcpy(buf + offset, & msg->cov_n_d , 4);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  memcpy(buf + offset, & msg->cov_e_e , 4);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  memcpy(buf + offset, & msg->cov_e_d , 4);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  memcpy(buf + offset, & msg->cov_d_d , 4);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->n_sats , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->flags , 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline bool sbp_unpack_sbp_msg_pos_llh_cov_gnss_t(const u8 *buf, size_t len, sbp_msg_pos_llh_cov_gnss_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
      
  if (offset + 4 > len) { return false; }
  msg->tow = sbp_unpack_u32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
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
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->cov_n_n, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->cov_n_e, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->cov_n_d, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->cov_e_e, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->cov_e_d, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->cov_d_d, buf + offset, 4);
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

static inline size_t sbp_packed_size_sbp_msg_vel_ecef_gnss_t(const sbp_msg_vel_ecef_gnss_t *msg) {                                
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
				sizeof( msg->accuracy )                                                                          
	  +
				sizeof( msg->n_sats )                                                                          
	  +
				sizeof( msg->flags );
}

static inline bool sbp_pack_sbp_msg_vel_ecef_gnss_t(u8 *buf, size_t len, const sbp_msg_vel_ecef_gnss_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_vel_ecef_gnss_t(msg) > len) { return false; }
  
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->tow);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  sbp_pack_s32(buf + offset, msg->x);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  sbp_pack_s32(buf + offset, msg->y);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  sbp_pack_s32(buf + offset, msg->z);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->accuracy);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->n_sats , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->flags , 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline bool sbp_unpack_sbp_msg_vel_ecef_gnss_t(const u8 *buf, size_t len, sbp_msg_vel_ecef_gnss_t *msg) {
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
  msg->x = sbp_unpack_s32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  msg->y = sbp_unpack_s32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  msg->z = sbp_unpack_s32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 2 > len) { return false; }
  msg->accuracy = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
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

static inline size_t sbp_packed_size_sbp_msg_vel_ecef_cov_gnss_t(const sbp_msg_vel_ecef_cov_gnss_t *msg) {                                
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
				sizeof( msg->cov_x_x )                                                                          
	  +
				sizeof( msg->cov_x_y )                                                                          
	  +
				sizeof( msg->cov_x_z )                                                                          
	  +
				sizeof( msg->cov_y_y )                                                                          
	  +
				sizeof( msg->cov_y_z )                                                                          
	  +
				sizeof( msg->cov_z_z )                                                                          
	  +
				sizeof( msg->n_sats )                                                                          
	  +
				sizeof( msg->flags );
}

static inline bool sbp_pack_sbp_msg_vel_ecef_cov_gnss_t(u8 *buf, size_t len, const sbp_msg_vel_ecef_cov_gnss_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_vel_ecef_cov_gnss_t(msg) > len) { return false; }
  
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->tow);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  sbp_pack_s32(buf + offset, msg->x);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  sbp_pack_s32(buf + offset, msg->y);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  sbp_pack_s32(buf + offset, msg->z);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  memcpy(buf + offset, & msg->cov_x_x , 4);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  memcpy(buf + offset, & msg->cov_x_y , 4);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  memcpy(buf + offset, & msg->cov_x_z , 4);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  memcpy(buf + offset, & msg->cov_y_y , 4);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  memcpy(buf + offset, & msg->cov_y_z , 4);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  memcpy(buf + offset, & msg->cov_z_z , 4);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->n_sats , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->flags , 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline bool sbp_unpack_sbp_msg_vel_ecef_cov_gnss_t(const u8 *buf, size_t len, sbp_msg_vel_ecef_cov_gnss_t *msg) {
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
  msg->x = sbp_unpack_s32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  msg->y = sbp_unpack_s32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  msg->z = sbp_unpack_s32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->cov_x_x, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->cov_x_y, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->cov_x_z, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->cov_y_y, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->cov_y_z, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->cov_z_z, buf + offset, 4);
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

static inline size_t sbp_packed_size_sbp_msg_vel_ned_gnss_t(const sbp_msg_vel_ned_gnss_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				sizeof( msg->tow )                                                                          
	  +
				sizeof( msg->n )                                                                          
	  +
				sizeof( msg->e )                                                                          
	  +
				sizeof( msg->d )                                                                          
	  +
				sizeof( msg->h_accuracy )                                                                          
	  +
				sizeof( msg->v_accuracy )                                                                          
	  +
				sizeof( msg->n_sats )                                                                          
	  +
				sizeof( msg->flags );
}

static inline bool sbp_pack_sbp_msg_vel_ned_gnss_t(u8 *buf, size_t len, const sbp_msg_vel_ned_gnss_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_vel_ned_gnss_t(msg) > len) { return false; }
  
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->tow);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  sbp_pack_s32(buf + offset, msg->n);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  sbp_pack_s32(buf + offset, msg->e);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  sbp_pack_s32(buf + offset, msg->d);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->h_accuracy);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->v_accuracy);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->n_sats , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->flags , 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline bool sbp_unpack_sbp_msg_vel_ned_gnss_t(const u8 *buf, size_t len, sbp_msg_vel_ned_gnss_t *msg) {
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
  msg->n = sbp_unpack_s32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  msg->e = sbp_unpack_s32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  msg->d = sbp_unpack_s32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 2 > len) { return false; }
  msg->h_accuracy = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 2 > len) { return false; }
  msg->v_accuracy = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
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

static inline size_t sbp_packed_size_sbp_msg_vel_ned_cov_gnss_t(const sbp_msg_vel_ned_cov_gnss_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				sizeof( msg->tow )                                                                          
	  +
				sizeof( msg->n )                                                                          
	  +
				sizeof( msg->e )                                                                          
	  +
				sizeof( msg->d )                                                                          
	  +
				sizeof( msg->cov_n_n )                                                                          
	  +
				sizeof( msg->cov_n_e )                                                                          
	  +
				sizeof( msg->cov_n_d )                                                                          
	  +
				sizeof( msg->cov_e_e )                                                                          
	  +
				sizeof( msg->cov_e_d )                                                                          
	  +
				sizeof( msg->cov_d_d )                                                                          
	  +
				sizeof( msg->n_sats )                                                                          
	  +
				sizeof( msg->flags );
}

static inline bool sbp_pack_sbp_msg_vel_ned_cov_gnss_t(u8 *buf, size_t len, const sbp_msg_vel_ned_cov_gnss_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_vel_ned_cov_gnss_t(msg) > len) { return false; }
  
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->tow);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  sbp_pack_s32(buf + offset, msg->n);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  sbp_pack_s32(buf + offset, msg->e);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  sbp_pack_s32(buf + offset, msg->d);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  memcpy(buf + offset, & msg->cov_n_n , 4);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  memcpy(buf + offset, & msg->cov_n_e , 4);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  memcpy(buf + offset, & msg->cov_n_d , 4);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  memcpy(buf + offset, & msg->cov_e_e , 4);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  memcpy(buf + offset, & msg->cov_e_d , 4);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  memcpy(buf + offset, & msg->cov_d_d , 4);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->n_sats , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->flags , 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline bool sbp_unpack_sbp_msg_vel_ned_cov_gnss_t(const u8 *buf, size_t len, sbp_msg_vel_ned_cov_gnss_t *msg) {
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
  msg->n = sbp_unpack_s32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  msg->e = sbp_unpack_s32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  msg->d = sbp_unpack_s32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->cov_n_n, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->cov_n_e, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->cov_n_d, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->cov_e_e, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->cov_e_d, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->cov_d_d, buf + offset, 4);
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

static inline size_t sbp_packed_size_sbp_msg_vel_body_t(const sbp_msg_vel_body_t *msg) {                                
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
				sizeof( msg->cov_x_x )                                                                          
	  +
				sizeof( msg->cov_x_y )                                                                          
	  +
				sizeof( msg->cov_x_z )                                                                          
	  +
				sizeof( msg->cov_y_y )                                                                          
	  +
				sizeof( msg->cov_y_z )                                                                          
	  +
				sizeof( msg->cov_z_z )                                                                          
	  +
				sizeof( msg->n_sats )                                                                          
	  +
				sizeof( msg->flags );
}

static inline bool sbp_pack_sbp_msg_vel_body_t(u8 *buf, size_t len, const sbp_msg_vel_body_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_vel_body_t(msg) > len) { return false; }
  
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->tow);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  sbp_pack_s32(buf + offset, msg->x);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  sbp_pack_s32(buf + offset, msg->y);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  sbp_pack_s32(buf + offset, msg->z);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  memcpy(buf + offset, & msg->cov_x_x , 4);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  memcpy(buf + offset, & msg->cov_x_y , 4);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  memcpy(buf + offset, & msg->cov_x_z , 4);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  memcpy(buf + offset, & msg->cov_y_y , 4);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  memcpy(buf + offset, & msg->cov_y_z , 4);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  memcpy(buf + offset, & msg->cov_z_z , 4);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->n_sats , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->flags , 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline bool sbp_unpack_sbp_msg_vel_body_t(const u8 *buf, size_t len, sbp_msg_vel_body_t *msg) {
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
  msg->x = sbp_unpack_s32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  msg->y = sbp_unpack_s32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  msg->z = sbp_unpack_s32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->cov_x_x, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->cov_x_y, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->cov_x_z, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->cov_y_y, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->cov_y_z, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->cov_z_z, buf + offset, 4);
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

static inline size_t sbp_packed_size_sbp_msg_age_corrections_t(const sbp_msg_age_corrections_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				sizeof( msg->tow )                                                                          
	  +
				sizeof( msg->age );
}

static inline bool sbp_pack_sbp_msg_age_corrections_t(u8 *buf, size_t len, const sbp_msg_age_corrections_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_age_corrections_t(msg) > len) { return false; }
  
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->tow);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->age);
  // NOLINTNEXTLINE
  offset += 2;
  return true;
}

static inline bool sbp_unpack_sbp_msg_age_corrections_t(const u8 *buf, size_t len, sbp_msg_age_corrections_t *msg) {
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
  msg->age = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_gps_time_dep_a_t(const sbp_msg_gps_time_dep_a_t *msg) {                                
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
				sizeof( msg->flags );
}

static inline bool sbp_pack_sbp_msg_gps_time_dep_a_t(u8 *buf, size_t len, const sbp_msg_gps_time_dep_a_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_gps_time_dep_a_t(msg) > len) { return false; }
  
        
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
  return true;
}

static inline bool sbp_unpack_sbp_msg_gps_time_dep_a_t(const u8 *buf, size_t len, sbp_msg_gps_time_dep_a_t *msg) {
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
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_dops_dep_a_t(const sbp_msg_dops_dep_a_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				sizeof( msg->tow )                                                                          
	  +
				sizeof( msg->gdop )                                                                          
	  +
				sizeof( msg->pdop )                                                                          
	  +
				sizeof( msg->tdop )                                                                          
	  +
				sizeof( msg->hdop )                                                                          
	  +
				sizeof( msg->vdop );
}

static inline bool sbp_pack_sbp_msg_dops_dep_a_t(u8 *buf, size_t len, const sbp_msg_dops_dep_a_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_dops_dep_a_t(msg) > len) { return false; }
  
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->tow);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->gdop);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->pdop);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->tdop);
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
  return true;
}

static inline bool sbp_unpack_sbp_msg_dops_dep_a_t(const u8 *buf, size_t len, sbp_msg_dops_dep_a_t *msg) {
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
  msg->gdop = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 2 > len) { return false; }
  msg->pdop = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 2 > len) { return false; }
  msg->tdop = sbp_unpack_u16(buf + offset);
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
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_pos_ecef_dep_a_t(const sbp_msg_pos_ecef_dep_a_t *msg) {                                
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
				sizeof( msg->accuracy )                                                                          
	  +
				sizeof( msg->n_sats )                                                                          
	  +
				sizeof( msg->flags );
}

static inline bool sbp_pack_sbp_msg_pos_ecef_dep_a_t(u8 *buf, size_t len, const sbp_msg_pos_ecef_dep_a_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_pos_ecef_dep_a_t(msg) > len) { return false; }
  
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->tow);
  // NOLINTNEXTLINE
  offset += 4;
        
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
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->accuracy);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->n_sats , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->flags , 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline bool sbp_unpack_sbp_msg_pos_ecef_dep_a_t(const u8 *buf, size_t len, sbp_msg_pos_ecef_dep_a_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
      
  if (offset + 4 > len) { return false; }
  msg->tow = sbp_unpack_u32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
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
      
  if (offset + 2 > len) { return false; }
  msg->accuracy = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
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

static inline size_t sbp_packed_size_sbp_msg_pos_llh_dep_a_t(const sbp_msg_pos_llh_dep_a_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				sizeof( msg->tow )                                                                          
	  +
				sizeof( msg->lat )                                                                          
	  +
				sizeof( msg->lon )                                                                          
	  +
				sizeof( msg->height )                                                                          
	  +
				sizeof( msg->h_accuracy )                                                                          
	  +
				sizeof( msg->v_accuracy )                                                                          
	  +
				sizeof( msg->n_sats )                                                                          
	  +
				sizeof( msg->flags );
}

static inline bool sbp_pack_sbp_msg_pos_llh_dep_a_t(u8 *buf, size_t len, const sbp_msg_pos_llh_dep_a_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_pos_llh_dep_a_t(msg) > len) { return false; }
  
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->tow);
  // NOLINTNEXTLINE
  offset += 4;
        
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
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->h_accuracy);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->v_accuracy);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->n_sats , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->flags , 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline bool sbp_unpack_sbp_msg_pos_llh_dep_a_t(const u8 *buf, size_t len, sbp_msg_pos_llh_dep_a_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
      
  if (offset + 4 > len) { return false; }
  msg->tow = sbp_unpack_u32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
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
      
  if (offset + 2 > len) { return false; }
  msg->h_accuracy = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 2 > len) { return false; }
  msg->v_accuracy = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
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

static inline size_t sbp_packed_size_sbp_msg_baseline_ecef_dep_a_t(const sbp_msg_baseline_ecef_dep_a_t *msg) {                                
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
				sizeof( msg->accuracy )                                                                          
	  +
				sizeof( msg->n_sats )                                                                          
	  +
				sizeof( msg->flags );
}

static inline bool sbp_pack_sbp_msg_baseline_ecef_dep_a_t(u8 *buf, size_t len, const sbp_msg_baseline_ecef_dep_a_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_baseline_ecef_dep_a_t(msg) > len) { return false; }
  
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->tow);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  sbp_pack_s32(buf + offset, msg->x);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  sbp_pack_s32(buf + offset, msg->y);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  sbp_pack_s32(buf + offset, msg->z);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->accuracy);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->n_sats , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->flags , 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline bool sbp_unpack_sbp_msg_baseline_ecef_dep_a_t(const u8 *buf, size_t len, sbp_msg_baseline_ecef_dep_a_t *msg) {
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
  msg->x = sbp_unpack_s32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  msg->y = sbp_unpack_s32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  msg->z = sbp_unpack_s32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 2 > len) { return false; }
  msg->accuracy = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
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

static inline size_t sbp_packed_size_sbp_msg_baseline_ned_dep_a_t(const sbp_msg_baseline_ned_dep_a_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				sizeof( msg->tow )                                                                          
	  +
				sizeof( msg->n )                                                                          
	  +
				sizeof( msg->e )                                                                          
	  +
				sizeof( msg->d )                                                                          
	  +
				sizeof( msg->h_accuracy )                                                                          
	  +
				sizeof( msg->v_accuracy )                                                                          
	  +
				sizeof( msg->n_sats )                                                                          
	  +
				sizeof( msg->flags );
}

static inline bool sbp_pack_sbp_msg_baseline_ned_dep_a_t(u8 *buf, size_t len, const sbp_msg_baseline_ned_dep_a_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_baseline_ned_dep_a_t(msg) > len) { return false; }
  
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->tow);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  sbp_pack_s32(buf + offset, msg->n);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  sbp_pack_s32(buf + offset, msg->e);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  sbp_pack_s32(buf + offset, msg->d);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->h_accuracy);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->v_accuracy);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->n_sats , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->flags , 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline bool sbp_unpack_sbp_msg_baseline_ned_dep_a_t(const u8 *buf, size_t len, sbp_msg_baseline_ned_dep_a_t *msg) {
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
  msg->n = sbp_unpack_s32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  msg->e = sbp_unpack_s32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  msg->d = sbp_unpack_s32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 2 > len) { return false; }
  msg->h_accuracy = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 2 > len) { return false; }
  msg->v_accuracy = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
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

static inline size_t sbp_packed_size_sbp_msg_vel_ecef_dep_a_t(const sbp_msg_vel_ecef_dep_a_t *msg) {                                
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
				sizeof( msg->accuracy )                                                                          
	  +
				sizeof( msg->n_sats )                                                                          
	  +
				sizeof( msg->flags );
}

static inline bool sbp_pack_sbp_msg_vel_ecef_dep_a_t(u8 *buf, size_t len, const sbp_msg_vel_ecef_dep_a_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_vel_ecef_dep_a_t(msg) > len) { return false; }
  
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->tow);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  sbp_pack_s32(buf + offset, msg->x);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  sbp_pack_s32(buf + offset, msg->y);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  sbp_pack_s32(buf + offset, msg->z);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->accuracy);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->n_sats , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->flags , 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline bool sbp_unpack_sbp_msg_vel_ecef_dep_a_t(const u8 *buf, size_t len, sbp_msg_vel_ecef_dep_a_t *msg) {
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
  msg->x = sbp_unpack_s32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  msg->y = sbp_unpack_s32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  msg->z = sbp_unpack_s32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 2 > len) { return false; }
  msg->accuracy = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
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

static inline size_t sbp_packed_size_sbp_msg_vel_ned_dep_a_t(const sbp_msg_vel_ned_dep_a_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				sizeof( msg->tow )                                                                          
	  +
				sizeof( msg->n )                                                                          
	  +
				sizeof( msg->e )                                                                          
	  +
				sizeof( msg->d )                                                                          
	  +
				sizeof( msg->h_accuracy )                                                                          
	  +
				sizeof( msg->v_accuracy )                                                                          
	  +
				sizeof( msg->n_sats )                                                                          
	  +
				sizeof( msg->flags );
}

static inline bool sbp_pack_sbp_msg_vel_ned_dep_a_t(u8 *buf, size_t len, const sbp_msg_vel_ned_dep_a_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_vel_ned_dep_a_t(msg) > len) { return false; }
  
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->tow);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  sbp_pack_s32(buf + offset, msg->n);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  sbp_pack_s32(buf + offset, msg->e);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  sbp_pack_s32(buf + offset, msg->d);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->h_accuracy);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->v_accuracy);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->n_sats , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->flags , 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline bool sbp_unpack_sbp_msg_vel_ned_dep_a_t(const u8 *buf, size_t len, sbp_msg_vel_ned_dep_a_t *msg) {
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
  msg->n = sbp_unpack_s32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  msg->e = sbp_unpack_s32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  msg->d = sbp_unpack_s32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 2 > len) { return false; }
  msg->h_accuracy = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 2 > len) { return false; }
  msg->v_accuracy = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
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

static inline size_t sbp_packed_size_sbp_msg_baseline_heading_dep_a_t(const sbp_msg_baseline_heading_dep_a_t *msg) {                                
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

static inline bool sbp_pack_sbp_msg_baseline_heading_dep_a_t(u8 *buf, size_t len, const sbp_msg_baseline_heading_dep_a_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_baseline_heading_dep_a_t(msg) > len) { return false; }
  
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->tow);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->heading);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->n_sats , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->flags , 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline bool sbp_unpack_sbp_msg_baseline_heading_dep_a_t(const u8 *buf, size_t len, sbp_msg_baseline_heading_dep_a_t *msg) {
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
  msg->heading = sbp_unpack_u32(buf + offset);
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

static inline size_t sbp_packed_size_sbp_msg_protection_level_dep_a_t(const sbp_msg_protection_level_dep_a_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				sizeof( msg->tow )                                                                          
	  +
				sizeof( msg->vpl )                                                                          
	  +
				sizeof( msg->hpl )                                                                          
	  +
				sizeof( msg->lat )                                                                          
	  +
				sizeof( msg->lon )                                                                          
	  +
				sizeof( msg->height )                                                                          
	  +
				sizeof( msg->flags );
}

static inline bool sbp_pack_sbp_msg_protection_level_dep_a_t(u8 *buf, size_t len, const sbp_msg_protection_level_dep_a_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_protection_level_dep_a_t(msg) > len) { return false; }
  
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->tow);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->vpl);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->hpl);
  // NOLINTNEXTLINE
  offset += 2;
        
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
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->flags , 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline bool sbp_unpack_sbp_msg_protection_level_dep_a_t(const u8 *buf, size_t len, sbp_msg_protection_level_dep_a_t *msg) {
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
  msg->vpl = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 2 > len) { return false; }
  msg->hpl = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
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
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->flags, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_protection_level_t(const sbp_msg_protection_level_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				sizeof( msg->tow )                                                                          
	  +
				sizeof( msg->wn )                                                                          
	  +
				sizeof( msg->hpl )                                                                          
	  +
				sizeof( msg->vpl )                                                                          
	  +
				sizeof( msg->atpl )                                                                          
	  +
				sizeof( msg->ctpl )                                                                          
	  +
				sizeof( msg->hvpl )                                                                          
	  +
				sizeof( msg->vvpl )                                                                          
	  +
				sizeof( msg->hopl )                                                                          
	  +
				sizeof( msg->popl )                                                                          
	  +
				sizeof( msg->ropl )                                                                          
	  +
				sizeof( msg->lat )                                                                          
	  +
				sizeof( msg->lon )                                                                          
	  +
				sizeof( msg->height )                                                                          
	  +
				sizeof( msg->v_x )                                                                          
	  +
				sizeof( msg->v_y )                                                                          
	  +
				sizeof( msg->v_z )                                                                          
	  +
				sizeof( msg->roll )                                                                          
	  +
				sizeof( msg->pitch )                                                                          
	  +
				sizeof( msg->heading )                                                                          
	  +
				sizeof( msg->flags );
}

static inline bool sbp_pack_sbp_msg_protection_level_t(u8 *buf, size_t len, const sbp_msg_protection_level_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_protection_level_t(msg) > len) { return false; }
  
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->tow);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_s16(buf + offset, msg->wn);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->hpl);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->vpl);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->atpl);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->ctpl);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->hvpl);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->vvpl);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->hopl);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->popl);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->ropl);
  // NOLINTNEXTLINE
  offset += 2;
        
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
        
  if (offset + 4 > len) { return false; }
  sbp_pack_s32(buf + offset, msg->v_x);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  sbp_pack_s32(buf + offset, msg->v_y);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  sbp_pack_s32(buf + offset, msg->v_z);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  sbp_pack_s32(buf + offset, msg->roll);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  sbp_pack_s32(buf + offset, msg->pitch);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  sbp_pack_s32(buf + offset, msg->heading);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->flags);
  // NOLINTNEXTLINE
  offset += 4;
  return true;
}

static inline bool sbp_unpack_sbp_msg_protection_level_t(const u8 *buf, size_t len, sbp_msg_protection_level_t *msg) {
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
  msg->wn = sbp_unpack_s16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 2 > len) { return false; }
  msg->hpl = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 2 > len) { return false; }
  msg->vpl = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 2 > len) { return false; }
  msg->atpl = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 2 > len) { return false; }
  msg->ctpl = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 2 > len) { return false; }
  msg->hvpl = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 2 > len) { return false; }
  msg->vvpl = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 2 > len) { return false; }
  msg->hopl = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 2 > len) { return false; }
  msg->popl = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 2 > len) { return false; }
  msg->ropl = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
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
      
  if (offset + 4 > len) { return false; }
  msg->v_x = sbp_unpack_s32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  msg->v_y = sbp_unpack_s32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  msg->v_z = sbp_unpack_s32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  msg->roll = sbp_unpack_s32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  msg->pitch = sbp_unpack_s32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  msg->heading = sbp_unpack_s32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  msg->flags = sbp_unpack_u32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
  return true;
}

#endif
