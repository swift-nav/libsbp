#ifndef LIBSBP_MAG_PACKERS_H
#define LIBSBP_MAG_PACKERS_H

#ifndef LIBSBP_MAG_MESSAGES_H
#error "Do not include this file directly, include libsbp/unpacked/mag.h instead"
#endif

#include <stdbool.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>
#include <endian.h>
#include <math.h>

#include <libsbp/common.h>
#include <libsbp/string.h>

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
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 1 > len) { return false; }
  u8 msgtow_f = msg->tow_f;
  memcpy(buf + offset, & msgtow_f , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 2 > len) { return false; }
  u16 msgmag_x = htole16( *(const u16*)&msg->mag_x );
  memcpy(buf + offset, & msgmag_x , 2);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 2 > len) { return false; }
  u16 msgmag_y = htole16( *(const u16*)&msg->mag_y );
  memcpy(buf + offset, & msgmag_y , 2);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 2 > len) { return false; }
  u16 msgmag_z = htole16( *(const u16*)&msg->mag_z );
  memcpy(buf + offset, & msgmag_z , 2);
  // NOLINTNEXTLINE
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
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->tow_f, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 2 > len) { return false; }
  memcpy(&msg->mag_x, buf + offset, 2);
  u16 msgmag_x = *(const u16*)&msg->mag_x;
  msgmag_x = le16toh( msgmag_x );
  msg->mag_x = *(const s16*)&msgmag_x;
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 2 > len) { return false; }
  memcpy(&msg->mag_y, buf + offset, 2);
  u16 msgmag_y = *(const u16*)&msg->mag_y;
  msgmag_y = le16toh( msgmag_y );
  msg->mag_y = *(const s16*)&msgmag_y;
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 2 > len) { return false; }
  memcpy(&msg->mag_z, buf + offset, 2);
  u16 msgmag_z = *(const u16*)&msg->mag_z;
  msgmag_z = le16toh( msgmag_z );
  msg->mag_z = *(const s16*)&msgmag_z;
  // NOLINTNEXTLINE
  offset += 2;
  return true;
}

#endif
