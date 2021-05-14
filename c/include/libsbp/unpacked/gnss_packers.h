#ifndef LIBSBP_GNSS_PACKERS_H
#define LIBSBP_GNSS_PACKERS_H

#ifndef LIBSBP_GNSS_MESSAGES_H
#error "Do not include this file directly, include libsbp/unpacked/gnss.h instead"
#endif

#include <stdbool.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>
#include <math.h>

#include <libsbp/common.h>
#include <libsbp/string.h>

static inline size_t sbp_packed_size_sbp_sbp_gnss_signal_t(const sbp_sbp_gnss_signal_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				sizeof( msg->sat )                                                                          
	  +
				sizeof( msg->code );
}

static inline bool sbp_pack_sbp_sbp_gnss_signal_t(u8 *buf, size_t len, const sbp_sbp_gnss_signal_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_sbp_gnss_signal_t(msg) > len) { return false; }
  
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->sat , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->code , 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline bool sbp_unpack_sbp_sbp_gnss_signal_t(const u8 *buf, size_t len, sbp_sbp_gnss_signal_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->sat, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->code, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline size_t sbp_packed_size_sbp_sv_id_t(const sbp_sv_id_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				sizeof( msg->satId )                                                                          
	  +
				sizeof( msg->constellation );
}

static inline bool sbp_pack_sbp_sv_id_t(u8 *buf, size_t len, const sbp_sv_id_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_sv_id_t(msg) > len) { return false; }
  
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->satId , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->constellation , 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline bool sbp_unpack_sbp_sv_id_t(const u8 *buf, size_t len, sbp_sv_id_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->satId, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->constellation, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline size_t sbp_packed_size_sbp_gnss_signal_dep_t(const sbp_gnss_signal_dep_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				sizeof( msg->sat )                                                                          
	  +
				sizeof( msg->code )                                                                          
	  +
				sizeof( msg->reserved );
}

static inline bool sbp_pack_sbp_gnss_signal_dep_t(u8 *buf, size_t len, const sbp_gnss_signal_dep_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_gnss_signal_dep_t(msg) > len) { return false; }
  
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->sat);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->code , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->reserved , 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline bool sbp_unpack_sbp_gnss_signal_dep_t(const u8 *buf, size_t len, sbp_gnss_signal_dep_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
      
  if (offset + 2 > len) { return false; }
  msg->sat = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->code, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->reserved, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline size_t sbp_packed_size_sbp_gps_time_dep_t(const sbp_gps_time_dep_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				sizeof( msg->tow )                                                                          
	  +
				sizeof( msg->wn );
}

static inline bool sbp_pack_sbp_gps_time_dep_t(u8 *buf, size_t len, const sbp_gps_time_dep_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_gps_time_dep_t(msg) > len) { return false; }
  
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->tow);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->wn);
  // NOLINTNEXTLINE
  offset += 2;
  return true;
}

static inline bool sbp_unpack_sbp_gps_time_dep_t(const u8 *buf, size_t len, sbp_gps_time_dep_t *msg) {
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
  msg->wn = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
  return true;
}

static inline size_t sbp_packed_size_sbp_gps_time_sec_t(const sbp_gps_time_sec_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				sizeof( msg->tow )                                                                          
	  +
				sizeof( msg->wn );
}

static inline bool sbp_pack_sbp_gps_time_sec_t(u8 *buf, size_t len, const sbp_gps_time_sec_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_gps_time_sec_t(msg) > len) { return false; }
  
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->tow);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->wn);
  // NOLINTNEXTLINE
  offset += 2;
  return true;
}

static inline bool sbp_unpack_sbp_gps_time_sec_t(const u8 *buf, size_t len, sbp_gps_time_sec_t *msg) {
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
  msg->wn = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
  return true;
}

static inline size_t sbp_packed_size_sbp_sbp_gps_time_t(const sbp_sbp_gps_time_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				sizeof( msg->tow )                                                                          
	  +
				sizeof( msg->ns_residual )                                                                          
	  +
				sizeof( msg->wn );
}

static inline bool sbp_pack_sbp_sbp_gps_time_t(u8 *buf, size_t len, const sbp_sbp_gps_time_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_sbp_gps_time_t(msg) > len) { return false; }
  
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->tow);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  sbp_pack_s32(buf + offset, msg->ns_residual);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->wn);
  // NOLINTNEXTLINE
  offset += 2;
  return true;
}

static inline bool sbp_unpack_sbp_sbp_gps_time_t(const u8 *buf, size_t len, sbp_sbp_gps_time_t *msg) {
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
  msg->ns_residual = sbp_unpack_s32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 2 > len) { return false; }
  msg->wn = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
  return true;
}

static inline size_t sbp_packed_size_sbp_carrier_phase_t(const sbp_carrier_phase_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				sizeof( msg->i )                                                                          
	  +
				sizeof( msg->f );
}

static inline bool sbp_pack_sbp_carrier_phase_t(u8 *buf, size_t len, const sbp_carrier_phase_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_carrier_phase_t(msg) > len) { return false; }
  
        
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

static inline bool sbp_unpack_sbp_carrier_phase_t(const u8 *buf, size_t len, sbp_carrier_phase_t *msg) {
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

#endif
