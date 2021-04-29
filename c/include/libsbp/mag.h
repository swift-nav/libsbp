#ifndef LIBSBP_MAG_MESSAGES_H
#define LIBSBP_MAG_MESSAGES_H

#include <stdbool.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>
#include <endian.h>

#include <libsbp/common.h>
  /** Raw magnetometer data
   *
 * Raw data from the magnetometer.
   */
#define SBP_MSG_MAG_RAW 0x0902

typedef struct {
  
  /**
 * Milliseconds since start of GPS week. If the high bit is set, the
 * time is unknown or invalid.[ms]
   */
    u32
  tow
  ;
  /**
 * Milliseconds since start of GPS week, fractional part[ms / 256]
   */
    u8
  tow_f
  ;
  /**
* Magnetic field in the body frame X axis[microteslas]
   */
    s16
  mag_x
  ;
  /**
* Magnetic field in the body frame Y axis[microteslas]
   */
    s16
  mag_y
  ;
  /**
* Magnetic field in the body frame Z axis[microteslas]
   */
    s16
  mag_z
  ;
} sbp_msg_mag_raw_t;

static inline size_t sbp_packed_size_sbp_msg_mag_raw_t(const sbp_msg_mag_raw_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				sizeof( msg->tow )                                                                          
	  +
				sizeof( msg->tow_f )                                                                          
	  +
				sizeof( msg->mag_x )                                                                          
	  +
				sizeof( msg->mag_y )                                                                          
	  +
				sizeof( msg->mag_z );
}

static inline bool sbp_pack_sbp_msg_mag_raw_t(u8 *buf, size_t len, const sbp_msg_mag_raw_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_mag_raw_t(msg) > len) { return false; }
  
        
  if (offset + 4 > len) { return false; }
  u32 msgtow = htole32( msg->tow );
  memcpy(buf + offset, & msgtow , 4);
  offset += 4;
        
  if (offset + 1 > len) { return false; }
  u8 msgtow_f = msg->tow_f;
  memcpy(buf + offset, & msgtow_f , 1);
  offset += 1;
        
  if (offset + 2 > len) { return false; }
  u16 msgmag_x = htole16( *(const u16*)&msg->mag_x );
  memcpy(buf + offset, & msgmag_x , 2);
  offset += 2;
        
  if (offset + 2 > len) { return false; }
  u16 msgmag_y = htole16( *(const u16*)&msg->mag_y );
  memcpy(buf + offset, & msgmag_y , 2);
  offset += 2;
        
  if (offset + 2 > len) { return false; }
  u16 msgmag_z = htole16( *(const u16*)&msg->mag_z );
  memcpy(buf + offset, & msgmag_z , 2);
  offset += 2;
  return true;
}

static inline bool sbp_unpack_sbp_msg_mag_raw_t(const u8 *buf, size_t len, sbp_msg_mag_raw_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->tow, buf + offset, 4);
  msg->tow = le32toh( msg->tow );
  offset += 4;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->tow_f, buf + offset, 1);
  offset += 1;
      
  if (offset + 2 > len) { return false; }
  memcpy(&msg->mag_x, buf + offset, 2);
  u16 msgmag_x = *(const u16*)&msg->mag_x;
  msgmag_x = le16toh( msgmag_x );
  msg->mag_x = *(const s16*)&msgmag_x;
  offset += 2;
      
  if (offset + 2 > len) { return false; }
  memcpy(&msg->mag_y, buf + offset, 2);
  u16 msgmag_y = *(const u16*)&msg->mag_y;
  msgmag_y = le16toh( msgmag_y );
  msg->mag_y = *(const s16*)&msgmag_y;
  offset += 2;
      
  if (offset + 2 > len) { return false; }
  memcpy(&msg->mag_z, buf + offset, 2);
  u16 msgmag_z = *(const u16*)&msg->mag_z;
  msgmag_z = le16toh( msgmag_z );
  msg->mag_z = *(const s16*)&msgmag_z;
  offset += 2;
  return true;
}


#endif /* LIBSBP_MAG_MESSAGES_H */