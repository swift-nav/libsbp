#ifndef LIBSBP_LOGGING_PACKERS_H
#define LIBSBP_LOGGING_PACKERS_H

#ifndef LIBSBP_LOGGING_MESSAGES_H
#error "Do not include this file directly, include libsbp/unpacked/logging.h instead"
#endif

#include <stdbool.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>
#include <math.h>

#include <libsbp/common.h>
#include <libsbp/string.h>

static inline size_t sbp_packed_size_sbp_msg_log_t(const sbp_msg_log_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				sizeof( msg->level )                                                                          
	  +
      sbp_unterminated_string_packed_len(&msg->text, 254);
}

static inline bool sbp_pack_sbp_msg_log_t(u8 *buf, size_t len, const sbp_msg_log_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_log_t(msg) > len) { return false; }
  
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->level , 1);
  // NOLINTNEXTLINE
  offset += 1;
        offset += sbp_unterminated_string_pack(&msg->text, 254, buf + offset, (uint8_t)(len - offset));
  return true;
}

static inline bool sbp_unpack_sbp_msg_log_t(const u8 *buf, size_t len, sbp_msg_log_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->level, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      offset += sbp_unterminated_string_unpack(&msg->text, 254, buf + offset, (uint8_t)(len - offset));
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_fwd_t(const sbp_msg_fwd_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				sizeof( msg->source )                                                                          
	  +
				sizeof( msg->protocol )                                                                          
	  +
	    (
			  msg->n_fwd_payload
			*
        sizeof( msg->fwd_payload[0] )
			);
}

static inline bool sbp_pack_sbp_msg_fwd_t(u8 *buf, size_t len, const sbp_msg_fwd_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_fwd_t(msg) > len) { return false; }
  
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->source , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->protocol , 1);
  // NOLINTNEXTLINE
  offset += 1;
			for(size_t msgfwd_payload_idx = 0; msgfwd_payload_idx < (size_t)msg->n_fwd_payload; msgfwd_payload_idx++)
			{
          
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->fwd_payload[msgfwd_payload_idx] , 1);
  // NOLINTNEXTLINE
  offset += 1;
			}
  return true;
}

static inline bool sbp_unpack_sbp_msg_fwd_t(const u8 *buf, size_t len, sbp_msg_fwd_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->source, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->protocol, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      msg->n_fwd_payload = (u8)((len - offset) / 1);

	  for (size_t msgfwd_payload_idx = 0; msgfwd_payload_idx <
				msg->n_fwd_payload;
				msgfwd_payload_idx++) 
		{
        
  if (offset + 1 > len) { return false; }
  memcpy(&msg->fwd_payload[msgfwd_payload_idx], buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
		}
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_print_dep_t(const sbp_msg_print_dep_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
      sbp_unterminated_string_packed_len(&msg->text, 255);
}

static inline bool sbp_pack_sbp_msg_print_dep_t(u8 *buf, size_t len, const sbp_msg_print_dep_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_print_dep_t(msg) > len) { return false; }
  
        offset += sbp_unterminated_string_pack(&msg->text, 255, buf + offset, (uint8_t)(len - offset));
  return true;
}

static inline bool sbp_unpack_sbp_msg_print_dep_t(const u8 *buf, size_t len, sbp_msg_print_dep_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
      offset += sbp_unterminated_string_unpack(&msg->text, 255, buf + offset, (uint8_t)(len - offset));
  return true;
}

#endif
