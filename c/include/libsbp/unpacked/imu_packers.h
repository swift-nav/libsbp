#ifndef LIBSBP_IMU_PACKERS_H
#define LIBSBP_IMU_PACKERS_H

#ifndef LIBSBP_IMU_MESSAGES_H
#error "Do not include this file directly, include libsbp/unpacked/imu.h instead"
#endif

#include <stdbool.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>
#include <endian.h>
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
  u32 msgtow = htole32( msg->tow );
  memcpy(buf + offset, & msgtow , 4);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 1 > len) { return false; }
  u8 msgtow_f = msg->tow_f;
  memcpy(buf + offset, & msgtow_f , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 2 > len) { return false; }
  u16 msgacc_x = htole16( *(const u16*)&msg->acc_x );
  memcpy(buf + offset, & msgacc_x , 2);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 2 > len) { return false; }
  u16 msgacc_y = htole16( *(const u16*)&msg->acc_y );
  memcpy(buf + offset, & msgacc_y , 2);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 2 > len) { return false; }
  u16 msgacc_z = htole16( *(const u16*)&msg->acc_z );
  memcpy(buf + offset, & msgacc_z , 2);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 2 > len) { return false; }
  u16 msggyr_x = htole16( *(const u16*)&msg->gyr_x );
  memcpy(buf + offset, & msggyr_x , 2);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 2 > len) { return false; }
  u16 msggyr_y = htole16( *(const u16*)&msg->gyr_y );
  memcpy(buf + offset, & msggyr_y , 2);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 2 > len) { return false; }
  u16 msggyr_z = htole16( *(const u16*)&msg->gyr_z );
  memcpy(buf + offset, & msggyr_z , 2);
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
  memcpy(&msg->tow, buf + offset, 4);
  msg->tow = le32toh( msg->tow );
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->tow_f, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 2 > len) { return false; }
  memcpy(&msg->acc_x, buf + offset, 2);
  u16 msgacc_x = *(const u16*)&msg->acc_x;
  msgacc_x = le16toh( msgacc_x );
  msg->acc_x = *(const s16*)&msgacc_x;
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 2 > len) { return false; }
  memcpy(&msg->acc_y, buf + offset, 2);
  u16 msgacc_y = *(const u16*)&msg->acc_y;
  msgacc_y = le16toh( msgacc_y );
  msg->acc_y = *(const s16*)&msgacc_y;
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 2 > len) { return false; }
  memcpy(&msg->acc_z, buf + offset, 2);
  u16 msgacc_z = *(const u16*)&msg->acc_z;
  msgacc_z = le16toh( msgacc_z );
  msg->acc_z = *(const s16*)&msgacc_z;
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 2 > len) { return false; }
  memcpy(&msg->gyr_x, buf + offset, 2);
  u16 msggyr_x = *(const u16*)&msg->gyr_x;
  msggyr_x = le16toh( msggyr_x );
  msg->gyr_x = *(const s16*)&msggyr_x;
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 2 > len) { return false; }
  memcpy(&msg->gyr_y, buf + offset, 2);
  u16 msggyr_y = *(const u16*)&msg->gyr_y;
  msggyr_y = le16toh( msggyr_y );
  msg->gyr_y = *(const s16*)&msggyr_y;
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 2 > len) { return false; }
  memcpy(&msg->gyr_z, buf + offset, 2);
  u16 msggyr_z = *(const u16*)&msg->gyr_z;
  msggyr_z = le16toh( msggyr_z );
  msg->gyr_z = *(const s16*)&msggyr_z;
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
  u8 msgimu_type = msg->imu_type;
  memcpy(buf + offset, & msgimu_type , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 2 > len) { return false; }
  u16 msgtemp = htole16( *(const u16*)&msg->temp );
  memcpy(buf + offset, & msgtemp , 2);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 1 > len) { return false; }
  u8 msgimu_conf = msg->imu_conf;
  memcpy(buf + offset, & msgimu_conf , 1);
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
  memcpy(&msg->temp, buf + offset, 2);
  u16 msgtemp = *(const u16*)&msg->temp;
  msgtemp = le16toh( msgtemp );
  msg->temp = *(const s16*)&msgtemp;
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->imu_conf, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

#endif
