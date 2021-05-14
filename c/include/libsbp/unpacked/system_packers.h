#ifndef LIBSBP_SYSTEM_PACKERS_H
#define LIBSBP_SYSTEM_PACKERS_H

#ifndef LIBSBP_SYSTEM_MESSAGES_H
#error "Do not include this file directly, include libsbp/unpacked/system.h instead"
#endif

#include <stdbool.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>
#include <math.h>

#include <libsbp/common.h>
#include <libsbp/string.h>

static inline size_t sbp_packed_size_sbp_msg_startup_t(const sbp_msg_startup_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				sizeof( msg->cause )                                                                          
	  +
				sizeof( msg->startup_type )                                                                          
	  +
				sizeof( msg->reserved );
}

static inline bool sbp_pack_sbp_msg_startup_t(u8 *buf, size_t len, const sbp_msg_startup_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_startup_t(msg) > len) { return false; }
  
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->cause , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->startup_type , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->reserved);
  // NOLINTNEXTLINE
  offset += 2;
  return true;
}

static inline bool sbp_unpack_sbp_msg_startup_t(const u8 *buf, size_t len, sbp_msg_startup_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->cause, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->startup_type, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 2 > len) { return false; }
  msg->reserved = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_dgnss_status_t(const sbp_msg_dgnss_status_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				sizeof( msg->flags )                                                                          
	  +
				sizeof( msg->latency )                                                                          
	  +
				sizeof( msg->num_signals )                                                                          
	  +
      sbp_unterminated_string_packed_len(&msg->source, 251);
}

static inline bool sbp_pack_sbp_msg_dgnss_status_t(u8 *buf, size_t len, const sbp_msg_dgnss_status_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_dgnss_status_t(msg) > len) { return false; }
  
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->flags , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->latency);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->num_signals , 1);
  // NOLINTNEXTLINE
  offset += 1;
        offset += sbp_unterminated_string_pack(&msg->source, 251, buf + offset, (uint8_t)(len - offset));
  return true;
}

static inline bool sbp_unpack_sbp_msg_dgnss_status_t(const u8 *buf, size_t len, sbp_msg_dgnss_status_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->flags, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 2 > len) { return false; }
  msg->latency = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->num_signals, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      offset += sbp_unterminated_string_unpack(&msg->source, 251, buf + offset, (uint8_t)(len - offset));
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_heartbeat_t(const sbp_msg_heartbeat_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				sizeof( msg->flags );
}

static inline bool sbp_pack_sbp_msg_heartbeat_t(u8 *buf, size_t len, const sbp_msg_heartbeat_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_heartbeat_t(msg) > len) { return false; }
  
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->flags);
  // NOLINTNEXTLINE
  offset += 4;
  return true;
}

static inline bool sbp_unpack_sbp_msg_heartbeat_t(const u8 *buf, size_t len, sbp_msg_heartbeat_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
      
  if (offset + 4 > len) { return false; }
  msg->flags = sbp_unpack_u32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
  return true;
}

static inline size_t sbp_packed_size_sbp_sub_system_report_t(const sbp_sub_system_report_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				sizeof( msg->component )                                                                          
	  +
				sizeof( msg->generic )                                                                          
	  +
				sizeof( msg->specific );
}

static inline bool sbp_pack_sbp_sub_system_report_t(u8 *buf, size_t len, const sbp_sub_system_report_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_sub_system_report_t(msg) > len) { return false; }
  
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->component);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->generic , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->specific , 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline bool sbp_unpack_sbp_sub_system_report_t(const u8 *buf, size_t len, sbp_sub_system_report_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
      
  if (offset + 2 > len) { return false; }
  msg->component = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->generic, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->specific, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_status_report_t(const sbp_msg_status_report_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				sizeof( msg->reporting_system )                                                                          
	  +
				sizeof( msg->sbp_version )                                                                          
	  +
				sizeof( msg->sequence )                                                                          
	  +
				sizeof( msg->uptime )                                                                          
	  +
	    (
			  msg->n_status
			*
				(                                                          
	0                                                                          
	  +
				sizeof( msg->status[0].component )                                                                          
	  +
				sizeof( msg->status[0].generic )                                                                          
	  +
				sizeof( msg->status[0].specific ) )
			);
}

static inline bool sbp_pack_sbp_msg_status_report_t(u8 *buf, size_t len, const sbp_msg_status_report_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_status_report_t(msg) > len) { return false; }
  
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->reporting_system);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->sbp_version);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->sequence);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->uptime);
  // NOLINTNEXTLINE
  offset += 4;
			for(size_t msgstatus_idx = 0; msgstatus_idx < (size_t)msg->n_status; msgstatus_idx++)
			{
					
        
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->status[msgstatus_idx].component);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->status[msgstatus_idx].generic , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->status[msgstatus_idx].specific , 1);
  // NOLINTNEXTLINE
  offset += 1;
			}
  return true;
}

static inline bool sbp_unpack_sbp_msg_status_report_t(const u8 *buf, size_t len, sbp_msg_status_report_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
      
  if (offset + 2 > len) { return false; }
  msg->reporting_system = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 2 > len) { return false; }
  msg->sbp_version = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 4 > len) { return false; }
  msg->sequence = sbp_unpack_u32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  msg->uptime = sbp_unpack_u32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      msg->n_status = (u8)((len - offset) / 4);

	  for (size_t msgstatus_idx = 0; msgstatus_idx <
				msg->n_status;
				msgstatus_idx++) 
		{
				
      
  if (offset + 2 > len) { return false; }
  msg->status[msgstatus_idx].component = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->status[msgstatus_idx].generic, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->status[msgstatus_idx].specific, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
		}
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_ins_status_t(const sbp_msg_ins_status_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				sizeof( msg->flags );
}

static inline bool sbp_pack_sbp_msg_ins_status_t(u8 *buf, size_t len, const sbp_msg_ins_status_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_ins_status_t(msg) > len) { return false; }
  
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->flags);
  // NOLINTNEXTLINE
  offset += 4;
  return true;
}

static inline bool sbp_unpack_sbp_msg_ins_status_t(const u8 *buf, size_t len, sbp_msg_ins_status_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
      
  if (offset + 4 > len) { return false; }
  msg->flags = sbp_unpack_u32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_csac_telemetry_t(const sbp_msg_csac_telemetry_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				sizeof( msg->id )                                                                          
	  +
      sbp_unterminated_string_packed_len(&msg->telemetry, 254);
}

static inline bool sbp_pack_sbp_msg_csac_telemetry_t(u8 *buf, size_t len, const sbp_msg_csac_telemetry_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_csac_telemetry_t(msg) > len) { return false; }
  
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->id , 1);
  // NOLINTNEXTLINE
  offset += 1;
        offset += sbp_unterminated_string_pack(&msg->telemetry, 254, buf + offset, (uint8_t)(len - offset));
  return true;
}

static inline bool sbp_unpack_sbp_msg_csac_telemetry_t(const u8 *buf, size_t len, sbp_msg_csac_telemetry_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->id, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      offset += sbp_unterminated_string_unpack(&msg->telemetry, 254, buf + offset, (uint8_t)(len - offset));
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_csac_telemetry_labels_t(const sbp_msg_csac_telemetry_labels_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				sizeof( msg->id )                                                                          
	  +
      sbp_unterminated_string_packed_len(&msg->telemetry_labels, 254);
}

static inline bool sbp_pack_sbp_msg_csac_telemetry_labels_t(u8 *buf, size_t len, const sbp_msg_csac_telemetry_labels_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_csac_telemetry_labels_t(msg) > len) { return false; }
  
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->id , 1);
  // NOLINTNEXTLINE
  offset += 1;
        offset += sbp_unterminated_string_pack(&msg->telemetry_labels, 254, buf + offset, (uint8_t)(len - offset));
  return true;
}

static inline bool sbp_unpack_sbp_msg_csac_telemetry_labels_t(const u8 *buf, size_t len, sbp_msg_csac_telemetry_labels_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->id, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      offset += sbp_unterminated_string_unpack(&msg->telemetry_labels, 254, buf + offset, (uint8_t)(len - offset));
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_ins_updates_t(const sbp_msg_ins_updates_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				sizeof( msg->tow )                                                                          
	  +
				sizeof( msg->gnsspos )                                                                          
	  +
				sizeof( msg->gnssvel )                                                                          
	  +
				sizeof( msg->wheelticks )                                                                          
	  +
				sizeof( msg->speed )                                                                          
	  +
				sizeof( msg->nhc )                                                                          
	  +
				sizeof( msg->zerovel );
}

static inline bool sbp_pack_sbp_msg_ins_updates_t(u8 *buf, size_t len, const sbp_msg_ins_updates_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_ins_updates_t(msg) > len) { return false; }
  
        
  if (offset + 4 > len) { return false; }
  sbp_pack_u32(buf + offset, msg->tow);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->gnsspos , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->gnssvel , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->wheelticks , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->speed , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->nhc , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->zerovel , 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline bool sbp_unpack_sbp_msg_ins_updates_t(const u8 *buf, size_t len, sbp_msg_ins_updates_t *msg) {
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
  memcpy(&msg->gnsspos, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->gnssvel, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->wheelticks, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->speed, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->nhc, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->zerovel, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_gnss_time_offset_t(const sbp_msg_gnss_time_offset_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				sizeof( msg->weeks )                                                                          
	  +
				sizeof( msg->milliseconds )                                                                          
	  +
				sizeof( msg->microseconds )                                                                          
	  +
				sizeof( msg->flags );
}

static inline bool sbp_pack_sbp_msg_gnss_time_offset_t(u8 *buf, size_t len, const sbp_msg_gnss_time_offset_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_gnss_time_offset_t(msg) > len) { return false; }
  
        
  if (offset + 2 > len) { return false; }
  sbp_pack_s16(buf + offset, msg->weeks);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 4 > len) { return false; }
  sbp_pack_s32(buf + offset, msg->milliseconds);
  // NOLINTNEXTLINE
  offset += 4;
        
  if (offset + 2 > len) { return false; }
  sbp_pack_s16(buf + offset, msg->microseconds);
  // NOLINTNEXTLINE
  offset += 2;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->flags , 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline bool sbp_unpack_sbp_msg_gnss_time_offset_t(const u8 *buf, size_t len, sbp_msg_gnss_time_offset_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
      
  if (offset + 2 > len) { return false; }
  msg->weeks = sbp_unpack_s16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 4 > len) { return false; }
  msg->milliseconds = sbp_unpack_s32(buf + offset);
  // NOLINTNEXTLINE
  offset += 4;
      
  if (offset + 2 > len) { return false; }
  msg->microseconds = sbp_unpack_s16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->flags, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_pps_time_t(const sbp_msg_pps_time_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				sizeof( msg->time )                                                                          
	  +
				sizeof( msg->flags );
}

static inline bool sbp_pack_sbp_msg_pps_time_t(u8 *buf, size_t len, const sbp_msg_pps_time_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_pps_time_t(msg) > len) { return false; }
  
        
  if (offset + 8 > len) { return false; }
  sbp_pack_u64(buf + offset, msg->time);
  // NOLINTNEXTLINE
  offset += 8;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->flags , 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline bool sbp_unpack_sbp_msg_pps_time_t(const u8 *buf, size_t len, sbp_msg_pps_time_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
      
  if (offset + 8 > len) { return false; }
  msg->time = sbp_unpack_u64(buf + offset);
  // NOLINTNEXTLINE
  offset += 8;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->flags, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_group_meta_t(const sbp_msg_group_meta_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				sizeof( msg->group_id )                                                                          
	  +
				sizeof( msg->flags )                                                                          
	  +
				sizeof( msg->n_group_msgs )                                                                          
	  +
	    (
	      msg->n_group_msgs
			*
        sizeof( msg->group_msgs[0] )
			);
}

static inline bool sbp_pack_sbp_msg_group_meta_t(u8 *buf, size_t len, const sbp_msg_group_meta_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_group_meta_t(msg) > len) { return false; }
  
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->group_id , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->flags , 1);
  // NOLINTNEXTLINE
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  memcpy(buf + offset, & msg->n_group_msgs , 1);
  // NOLINTNEXTLINE
  offset += 1;
			for(size_t msggroup_msgs_idx = 0; msggroup_msgs_idx < (size_t)msg->n_group_msgs; msggroup_msgs_idx++)
			{
          
  if (offset + 2 > len) { return false; }
  sbp_pack_u16(buf + offset, msg->group_msgs[msggroup_msgs_idx]);
  // NOLINTNEXTLINE
  offset += 2;
			}
  return true;
}

static inline bool sbp_unpack_sbp_msg_group_meta_t(const u8 *buf, size_t len, sbp_msg_group_meta_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->group_id, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->flags, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->n_group_msgs, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

	  for (size_t msggroup_msgs_idx = 0; msggroup_msgs_idx <
				msg->n_group_msgs;
				msggroup_msgs_idx++) 
		{
        
  if (offset + 2 > len) { return false; }
  msg->group_msgs[msggroup_msgs_idx] = sbp_unpack_u16(buf + offset);
  // NOLINTNEXTLINE
  offset += 2;
		}
  return true;
}

#endif
