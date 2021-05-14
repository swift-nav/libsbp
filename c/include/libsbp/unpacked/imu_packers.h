#ifndef LIBSBP_IMU_PACKERS_H
#define LIBSBP_IMU_PACKERS_H

#ifndef LIBSBP_IMU_MESSAGES_H
#error "Do not include this file directly, include libsbp/unpacked/imu.h instead"
#endif

#include <stdbool.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>
#include <math.h>

#include <libsbp/common.h>
#include <libsbp/string.h>

static inline size_t sbp_packed_size_sbp_msg_imu_raw_t(const sbp_msg_imu_raw_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				sizeof( msg->tow )                                                                          
	  +
				sizeof( msg->tow_f )                                                                          
	  +
				sizeof( msg->acc_x )                                                                          
	  +
				sizeof( msg->acc_y )                                                                          
	  +
				sizeof( msg->acc_z )                                                                          
	  +
				sizeof( msg->gyr_x )                                                                          
	  +
				sizeof( msg->gyr_y )                                                                          
	  +
				sizeof( msg->gyr_z );
}

static inline bool sbp_pack_sbp_msg_imu_raw_t(u8 *buf, size_t len, const sbp_msg_imu_raw_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_imu_raw_t(msg) > len) { return false; }
  
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->tow);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->tow_f , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_s16(buf + offset, msg->acc_x);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_s16(buf + offset, msg->acc_y);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_s16(buf + offset, msg->acc_z);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_s16(buf + offset, msg->gyr_x);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_s16(buf + offset, msg->gyr_y);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_s16(buf + offset, msg->gyr_z);
  // NOLINTNEXTLINE
  offset += 2;
  return true;
}

static inline bool sbp_unpack_sbp_msg_imu_raw_t(const u8 *buf, size_t len, sbp_msg_imu_raw_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
      
  if (offset + 4 > len) { return false; }
  msg->tow = sbp_unpack_u32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->tow_f, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 2 > len) { return false; }
  msg->acc_x = sbp_unpack_s16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 2 > len) { return false; }
  msg->acc_y = sbp_unpack_s16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 2 > len) { return false; }
  msg->acc_z = sbp_unpack_s16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 2 > len) { return false; }
  msg->gyr_x = sbp_unpack_s16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 2 > len) { return false; }
  msg->gyr_y = sbp_unpack_s16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 2 > len) { return false; }
  msg->gyr_z = sbp_unpack_s16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_imu_aux_t(const sbp_msg_imu_aux_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				sizeof( msg->imu_type )                                                                          
	  +
				sizeof( msg->temp )                                                                          
	  +
				sizeof( msg->imu_conf );
}

static inline bool sbp_pack_sbp_msg_imu_aux_t(u8 *buf, size_t len, const sbp_msg_imu_aux_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_imu_aux_t(msg) > len) { return false; }
  
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->imu_type , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_s16(buf + offset, msg->temp);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->imu_conf , 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline bool sbp_unpack_sbp_msg_imu_aux_t(const u8 *buf, size_t len, sbp_msg_imu_aux_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->imu_type, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 2 > len) { return false; }
  msg->temp = sbp_unpack_s16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->imu_conf, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

#endif
