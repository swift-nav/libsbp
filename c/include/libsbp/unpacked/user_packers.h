#ifndef LIBSBP_USER_PACKERS_H
#define LIBSBP_USER_PACKERS_H

#ifndef LIBSBP_USER_MESSAGES_H
#error "Do not include this file directly, include libsbp/unpacked/user.h instead"
#endif

#include <stdbool.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>
#include <endian.h>
#include <math.h>

#include <libsbp/common.h>
#include <libsbp/string2.h>

static inline size_t sbp_packed_size_sbp_msg_user_data_t(const sbp_msg_user_data_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
	    (
			  msg->contents_count
			*
        sizeof( msg->contents[0] )
			);
}

static inline bool sbp_pack_sbp_msg_user_data_t(u8 *buf, size_t len, const sbp_msg_user_data_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_user_data_t(msg) > len) { return false; }
  
			for(size_t msgcontents_idx = 0; msgcontents_idx < (size_t)msg->contents_count; msgcontents_idx++)
			{
          
  if (offset + 1 > len) { return false; }
  u8 msgcontentsmsgcontents_idx = msg->contents[msgcontents_idx];
  memcpy(buf + offset, & msgcontentsmsgcontents_idx , 1);
  // NOLINTNEXTLINE
  offset += 1;
			}
  return true;
}

static inline bool sbp_unpack_sbp_msg_user_data_t(const u8 *buf, size_t len, sbp_msg_user_data_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
      msg->contents_count = (u8)((len - offset) / 1);

	  for (size_t msgcontents_idx = 0; msgcontents_idx <
				msg->contents_count;
				msgcontents_idx++) 
		{
        
  if (offset + 1 > len) { return false; }
  memcpy(&msg->contents[msgcontents_idx], buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
		}
  return true;
}

#endif
