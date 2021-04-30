#ifndef LIBSBP_SETTINGS_MESSAGES_H
#define LIBSBP_SETTINGS_MESSAGES_H

#include <stdbool.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>
#include <endian.h>
#include <math.h>

#include <libsbp/common.h>
  /** Save settings to flash (host => device)
   *
 * The save settings message persists the device's current settings
 * configuration to its onboard flash memory file system.
   */
#define SBP_MSG_SETTINGS_SAVE               0x00A1

typedef struct {
  char dummy_to_avoid_empty_struct___do_not_use;
} sbp_msg_settings_save_t;

static inline size_t sbp_packed_size_sbp_msg_settings_save_t(const sbp_msg_settings_save_t *msg) {                                
	(void)msg;
  return                                                          
	0;
}

static inline bool sbp_pack_sbp_msg_settings_save_t(u8 *buf, size_t len, const sbp_msg_settings_save_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_settings_save_t(msg) > len) { return false; }
  
  return true;
}

static inline bool sbp_unpack_sbp_msg_settings_save_t(const u8 *buf, size_t len, sbp_msg_settings_save_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
  return true;
}

#ifdef __cplusplus
static inline bool operator== ( const sbp_msg_settings_save_t &a, const sbp_msg_settings_save_t &b) {
  (void)a;
  (void)b;
  

  return true;
}

static inline bool operator!=(const sbp_msg_settings_save_t &a, const sbp_msg_settings_save_t &b) {
  return !(a == b);
}
#endif
  /** Write device configuration settings (host => device)
   *
 * The setting message writes the device configuration for a particular
 * setting via A NULL-terminated and NULL-delimited string with contents
 * "SECTION_SETTING\0SETTING\0VALUE\0" where the '\0' escape sequence denotes 
 * the NULL character and where quotation marks are omitted. A device will
 * only process to this message when it is received from sender ID 0x42.
 * An example string that could be sent to a device is
 * "solution\0soln_freq\010\0".
   */
#define SBP_MSG_SETTINGS_WRITE              0x00A0

typedef struct {
  
  /**
 * A NULL-terminated and NULL-delimited string with contents
 * "SECTION_SETTING\0SETTING\0VALUE\0"
   */
    char
  setting
    [255]
  ;
} sbp_msg_settings_write_t;

static inline size_t sbp_packed_size_sbp_msg_settings_write_t(const sbp_msg_settings_write_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
      sbp_strlen( msg->setting, "3-section" );
}

static inline bool sbp_pack_sbp_msg_settings_write_t(u8 *buf, size_t len, const sbp_msg_settings_write_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_settings_write_t(msg) > len) { return false; }
  
      if (offset + sbp_strlen( msg->setting, "3-section") > len) { return false; }
      offset += sbp_pack_string( buf + offset, msg->setting, "3-section");
  return true;
}

static inline bool sbp_unpack_sbp_msg_settings_write_t(const u8 *buf, size_t len, sbp_msg_settings_write_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
    offset += sbp_unpack_string((const char *)buf + offset, len - offset, msg->setting, "3-section");
  return true;
}

#ifdef __cplusplus
static inline bool operator== ( const sbp_msg_settings_write_t &a, const sbp_msg_settings_write_t &b) {
  (void)a;
  (void)b;
  
        if (sbp_strcmp(a.setting, b.setting, "3-section") != 0) { return false; }

  return true;
}

static inline bool operator!=(const sbp_msg_settings_write_t &a, const sbp_msg_settings_write_t &b) {
  return !(a == b);
}
#endif
  /** Acknowledgement with status of MSG_SETTINGS_WRITE
   *
 * Return the status of a write request with the new value of the
 * setting.  If the requested value is rejected, the current value
 * will be returned. The string field is a NULL-terminated and NULL-delimited
 * string with contents "SECTION_SETTING\0SETTING\0VALUE\0" where the '\0'
 * escape sequence denotes the NULL character and where quotation marks
 * are omitted. An example string that could be sent from device is
 * "solution\0soln_freq\010\0".
   */
#define SBP_MSG_SETTINGS_WRITE_RESP         0x00AF

	#define SBP_SETTINGS_WRITE_RESP_STATUS_WRITE_STATUS_MASK (0x3)
#define SBP_SETTINGS_WRITE_RESP_STATUS_WRITE_STATUS_SHIFT (0u)
#define SBP_SETTINGS_WRITE_RESP_STATUS_WRITE_STATUS_GET(flags) \
                             (((flags) >> SBP_SETTINGS_WRITE_RESP_STATUS_WRITE_STATUS_SHIFT) \
                             & SBP_SETTINGS_WRITE_RESP_STATUS_WRITE_STATUS_MASK)
#define SBP_SETTINGS_WRITE_RESP_STATUS_WRITE_STATUS_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_SETTINGS_WRITE_RESP_STATUS_WRITE_STATUS_MASK)) \
                             << (SBP_SETTINGS_WRITE_RESP_STATUS_WRITE_STATUS_SHIFT)));} while(0)
                             

#define SBP_SETTINGS_WRITE_RESP_STATUS_WRITE_STATUS_ACCEPTED_VALUE_UPDATED (0)
#define SBP_SETTINGS_WRITE_RESP_STATUS_WRITE_STATUS_REJECTED_VALUE_UNPARSABLE_OR_OUT_OF_RANGE (1)
#define SBP_SETTINGS_WRITE_RESP_STATUS_WRITE_STATUS_REJECTED_REQUESTED_SETTING_DOES_NOT_EXIST (2)
#define SBP_SETTINGS_WRITE_RESP_STATUS_WRITE_STATUS_REJECTED_SETTING_NAME_COULD_NOT_BE_PARSED (3)
#define SBP_SETTINGS_WRITE_RESP_STATUS_WRITE_STATUS_REJECTED_SETTING_IS_READ_ONLY (4)
#define SBP_SETTINGS_WRITE_RESP_STATUS_WRITE_STATUS_REJECTED_MODIFICATION_IS_TEMPORARILY_DISABLED (5)
#define SBP_SETTINGS_WRITE_RESP_STATUS_WRITE_STATUS_REJECTED_UNSPECIFIED_ERROR (6)
typedef struct {
  
  /**
* Write status
   */
    u8
  status
  ;
  /**
 * A NULL-terminated and delimited string with contents
 * "SECTION_SETTING\0SETTING\0VALUE\0" 
   */
    char
  setting
    [254]
  ;
} sbp_msg_settings_write_resp_t;

static inline size_t sbp_packed_size_sbp_msg_settings_write_resp_t(const sbp_msg_settings_write_resp_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				sizeof( msg->status )                                                                          
	  +
      sbp_strlen( msg->setting, "3-section" );
}

static inline bool sbp_pack_sbp_msg_settings_write_resp_t(u8 *buf, size_t len, const sbp_msg_settings_write_resp_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_settings_write_resp_t(msg) > len) { return false; }
  
        
  if (offset + 1 > len) { return false; }
  u8 msgstatus = msg->status;
  memcpy(buf + offset, & msgstatus , 1);
  offset += 1;
      if (offset + sbp_strlen( msg->setting, "3-section") > len) { return false; }
      offset += sbp_pack_string( buf + offset, msg->setting, "3-section");
  return true;
}

static inline bool sbp_unpack_sbp_msg_settings_write_resp_t(const u8 *buf, size_t len, sbp_msg_settings_write_resp_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->status, buf + offset, 1);
  offset += 1;
    offset += sbp_unpack_string((const char *)buf + offset, len - offset, msg->setting, "3-section");
  return true;
}

#ifdef __cplusplus
static inline bool operator== ( const sbp_msg_settings_write_resp_t &a, const sbp_msg_settings_write_resp_t &b) {
  (void)a;
  (void)b;
  
        
    if (a.status != b.status) { return false; }
        if (sbp_strcmp(a.setting, b.setting, "3-section") != 0) { return false; }

  return true;
}

static inline bool operator!=(const sbp_msg_settings_write_resp_t &a, const sbp_msg_settings_write_resp_t &b) {
  return !(a == b);
}
#endif
  /** Read device configuration settings (host => device)
   *
 * The setting message that reads the device configuration. The string
 * field is a NULL-terminated and NULL-delimited string with contents
 * "SECTION_SETTING\0SETTING\0" where the '\0' escape sequence denotes the
 * NULL character and where quotation marks are omitted. An example
 * string that could be sent to a device is "solution\0soln_freq\0". A
 * device will only respond to this message when it is received from
 * sender ID 0x42. A device should respond with a MSG_SETTINGS_READ_RESP
 * message (msg_id 0x00A5).
   */
#define SBP_MSG_SETTINGS_READ_REQ           0x00A4

typedef struct {
  
  /**
 * A NULL-terminated and NULL-delimited string with contents
 * "SECTION_SETTING\0SETTING\0"
   */
    char
  setting
    [255]
  ;
} sbp_msg_settings_read_req_t;

static inline size_t sbp_packed_size_sbp_msg_settings_read_req_t(const sbp_msg_settings_read_req_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
      sbp_strlen( msg->setting, "2-section" );
}

static inline bool sbp_pack_sbp_msg_settings_read_req_t(u8 *buf, size_t len, const sbp_msg_settings_read_req_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_settings_read_req_t(msg) > len) { return false; }
  
      if (offset + sbp_strlen( msg->setting, "2-section") > len) { return false; }
      offset += sbp_pack_string( buf + offset, msg->setting, "2-section");
  return true;
}

static inline bool sbp_unpack_sbp_msg_settings_read_req_t(const u8 *buf, size_t len, sbp_msg_settings_read_req_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
    offset += sbp_unpack_string((const char *)buf + offset, len - offset, msg->setting, "2-section");
  return true;
}

#ifdef __cplusplus
static inline bool operator== ( const sbp_msg_settings_read_req_t &a, const sbp_msg_settings_read_req_t &b) {
  (void)a;
  (void)b;
  
        if (sbp_strcmp(a.setting, b.setting, "2-section") != 0) { return false; }

  return true;
}

static inline bool operator!=(const sbp_msg_settings_read_req_t &a, const sbp_msg_settings_read_req_t &b) {
  return !(a == b);
}
#endif
  /** Read device configuration settings (host <= device)
   *
 * The setting message wich which the device responds after a
 * MSG_SETTING_READ_REQ is sent to device. The string field is a
 * NULL-terminated and NULL-delimited string with contents
 * "SECTION_SETTING\0SETTING\0VALUE\0" where the '\0' escape sequence
 * denotes the NULL character and where quotation marks are omitted. An
 * example string that could be sent from device is
 * "solution\0soln_freq\010\0".
   */
#define SBP_MSG_SETTINGS_READ_RESP          0x00A5

typedef struct {
  
  /**
 * A NULL-terminated and NULL-delimited string with contents
 * "SECTION_SETTING\0SETTING\0VALUE\0"
 *  
   */
    char
  setting
    [255]
  ;
} sbp_msg_settings_read_resp_t;

static inline size_t sbp_packed_size_sbp_msg_settings_read_resp_t(const sbp_msg_settings_read_resp_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
      sbp_strlen( msg->setting, "3-section" );
}

static inline bool sbp_pack_sbp_msg_settings_read_resp_t(u8 *buf, size_t len, const sbp_msg_settings_read_resp_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_settings_read_resp_t(msg) > len) { return false; }
  
      if (offset + sbp_strlen( msg->setting, "3-section") > len) { return false; }
      offset += sbp_pack_string( buf + offset, msg->setting, "3-section");
  return true;
}

static inline bool sbp_unpack_sbp_msg_settings_read_resp_t(const u8 *buf, size_t len, sbp_msg_settings_read_resp_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
    offset += sbp_unpack_string((const char *)buf + offset, len - offset, msg->setting, "3-section");
  return true;
}

#ifdef __cplusplus
static inline bool operator== ( const sbp_msg_settings_read_resp_t &a, const sbp_msg_settings_read_resp_t &b) {
  (void)a;
  (void)b;
  
        if (sbp_strcmp(a.setting, b.setting, "3-section") != 0) { return false; }

  return true;
}

static inline bool operator!=(const sbp_msg_settings_read_resp_t &a, const sbp_msg_settings_read_resp_t &b) {
  return !(a == b);
}
#endif
  /** Read setting by direct index (host => device)
   *
 * The settings message for iterating through the settings
 * values. A device will respond to this message with a 
 * "MSG_SETTINGS_READ_BY_INDEX_RESP".
   */
#define SBP_MSG_SETTINGS_READ_BY_INDEX_REQ  0x00A2

typedef struct {
  
  /**
 * An index into the device settings, with values ranging from
 * 0 to length(settings)
   */
    u16
  index
  ;
} sbp_msg_settings_read_by_index_req_t;

static inline size_t sbp_packed_size_sbp_msg_settings_read_by_index_req_t(const sbp_msg_settings_read_by_index_req_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				sizeof( msg->index );
}

static inline bool sbp_pack_sbp_msg_settings_read_by_index_req_t(u8 *buf, size_t len, const sbp_msg_settings_read_by_index_req_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_settings_read_by_index_req_t(msg) > len) { return false; }
  
        
  if (offset + 2 > len) { return false; }
  u16 msgindex = htole16( msg->index );
  memcpy(buf + offset, & msgindex , 2);
  offset += 2;
  return true;
}

static inline bool sbp_unpack_sbp_msg_settings_read_by_index_req_t(const u8 *buf, size_t len, sbp_msg_settings_read_by_index_req_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
      
  if (offset + 2 > len) { return false; }
  memcpy(&msg->index, buf + offset, 2);
  msg->index = le16toh( msg->index );
  offset += 2;
  return true;
}

#ifdef __cplusplus
static inline bool operator== ( const sbp_msg_settings_read_by_index_req_t &a, const sbp_msg_settings_read_by_index_req_t &b) {
  (void)a;
  (void)b;
  
        
    if (a.index != b.index) { return false; }

  return true;
}

static inline bool operator!=(const sbp_msg_settings_read_by_index_req_t &a, const sbp_msg_settings_read_by_index_req_t &b) {
  return !(a == b);
}
#endif
  /** Read setting by direct index (host <= device)
   *
 * The settings message that reports the value of a setting at an index.
 * 
 * In the string field, it reports NULL-terminated and delimited string
 * with contents "SECTION_SETTING\0SETTING\0VALUE\0FORMAT_TYPE\0". where
 * the '\0' escape sequence denotes the NULL character and where quotation
 * marks are omitted. The FORMAT_TYPE field is optional and denotes
 * possible string values of the setting as a hint to the user. If
 * included, the format type portion of the string has the format
 * "enum:value1,value2,value3". An example string that could be sent from
 * the device is "simulator\0enabled\0True\0enum:True,False\0"
   */
#define SBP_MSG_SETTINGS_READ_BY_INDEX_RESP 0x00A7

typedef struct {
  
  /**
 * An index into the device settings, with values ranging from
 * 0 to length(settings)
   */
    u16
  index
  ;
  /**
 * A NULL-terminated and delimited string with contents
 * "SECTION_SETTING\0SETTING\0VALUE\0FORMAT_TYPE\0"
   */
    char
  setting
    [253]
  ;
} sbp_msg_settings_read_by_index_resp_t;

static inline size_t sbp_packed_size_sbp_msg_settings_read_by_index_resp_t(const sbp_msg_settings_read_by_index_resp_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				sizeof( msg->index )                                                                          
	  +
      sbp_strlen( msg->setting, "3-4-section" );
}

static inline bool sbp_pack_sbp_msg_settings_read_by_index_resp_t(u8 *buf, size_t len, const sbp_msg_settings_read_by_index_resp_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_settings_read_by_index_resp_t(msg) > len) { return false; }
  
        
  if (offset + 2 > len) { return false; }
  u16 msgindex = htole16( msg->index );
  memcpy(buf + offset, & msgindex , 2);
  offset += 2;
      if (offset + sbp_strlen( msg->setting, "3-4-section") > len) { return false; }
      offset += sbp_pack_string( buf + offset, msg->setting, "3-4-section");
  return true;
}

static inline bool sbp_unpack_sbp_msg_settings_read_by_index_resp_t(const u8 *buf, size_t len, sbp_msg_settings_read_by_index_resp_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
      
  if (offset + 2 > len) { return false; }
  memcpy(&msg->index, buf + offset, 2);
  msg->index = le16toh( msg->index );
  offset += 2;
    offset += sbp_unpack_string((const char *)buf + offset, len - offset, msg->setting, "3-4-section");
  return true;
}

#ifdef __cplusplus
static inline bool operator== ( const sbp_msg_settings_read_by_index_resp_t &a, const sbp_msg_settings_read_by_index_resp_t &b) {
  (void)a;
  (void)b;
  
        
    if (a.index != b.index) { return false; }
        if (sbp_strcmp(a.setting, b.setting, "3-4-section") != 0) { return false; }

  return true;
}

static inline bool operator!=(const sbp_msg_settings_read_by_index_resp_t &a, const sbp_msg_settings_read_by_index_resp_t &b) {
  return !(a == b);
}
#endif
  /** Finished reading settings (host <= device)
   *
 * The settings message for indicating end of the settings values.
   */
#define SBP_MSG_SETTINGS_READ_BY_INDEX_DONE 0x00A6

typedef struct {
  char dummy_to_avoid_empty_struct___do_not_use;
} sbp_msg_settings_read_by_index_done_t;

static inline size_t sbp_packed_size_sbp_msg_settings_read_by_index_done_t(const sbp_msg_settings_read_by_index_done_t *msg) {                                
	(void)msg;
  return                                                          
	0;
}

static inline bool sbp_pack_sbp_msg_settings_read_by_index_done_t(u8 *buf, size_t len, const sbp_msg_settings_read_by_index_done_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_settings_read_by_index_done_t(msg) > len) { return false; }
  
  return true;
}

static inline bool sbp_unpack_sbp_msg_settings_read_by_index_done_t(const u8 *buf, size_t len, sbp_msg_settings_read_by_index_done_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
  return true;
}

#ifdef __cplusplus
static inline bool operator== ( const sbp_msg_settings_read_by_index_done_t &a, const sbp_msg_settings_read_by_index_done_t &b) {
  (void)a;
  (void)b;
  

  return true;
}

static inline bool operator!=(const sbp_msg_settings_read_by_index_done_t &a, const sbp_msg_settings_read_by_index_done_t &b) {
  return !(a == b);
}
#endif
  /** Register setting and default value (device => host)
   *
 * This message registers the presence and default value of a setting
 * with a settings daemon.  The host should reply with MSG_SETTINGS_WRITE
 * for this setting to set the initial value.
   */
#define SBP_MSG_SETTINGS_REGISTER           0x00AE

typedef struct {
  
  /**
 * A NULL-terminated and delimited string with contents
 * "SECTION_SETTING\0SETTING\0VALUE".
   */
    char
  setting
    [255]
  ;
} sbp_msg_settings_register_t;

static inline size_t sbp_packed_size_sbp_msg_settings_register_t(const sbp_msg_settings_register_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
      sbp_strlen( msg->setting, "3-section" );
}

static inline bool sbp_pack_sbp_msg_settings_register_t(u8 *buf, size_t len, const sbp_msg_settings_register_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_settings_register_t(msg) > len) { return false; }
  
      if (offset + sbp_strlen( msg->setting, "3-section") > len) { return false; }
      offset += sbp_pack_string( buf + offset, msg->setting, "3-section");
  return true;
}

static inline bool sbp_unpack_sbp_msg_settings_register_t(const u8 *buf, size_t len, sbp_msg_settings_register_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
    offset += sbp_unpack_string((const char *)buf + offset, len - offset, msg->setting, "3-section");
  return true;
}

#ifdef __cplusplus
static inline bool operator== ( const sbp_msg_settings_register_t &a, const sbp_msg_settings_register_t &b) {
  (void)a;
  (void)b;
  
        if (sbp_strcmp(a.setting, b.setting, "3-section") != 0) { return false; }

  return true;
}

static inline bool operator!=(const sbp_msg_settings_register_t &a, const sbp_msg_settings_register_t &b) {
  return !(a == b);
}
#endif
  /** Register setting and default value (device <= host)
   *
 * This message responds to setting registration with the effective value.
 * The effective value shall differ from the given default value if setting
 * was already registered or is available in the permanent setting storage
 * and had a different value.
   */
#define SBP_MSG_SETTINGS_REGISTER_RESP      0x01AF

	#define SBP_SETTINGS_REGISTER_RESP_STATUS_REGISTER_STATUS_MASK (0x3)
#define SBP_SETTINGS_REGISTER_RESP_STATUS_REGISTER_STATUS_SHIFT (0u)
#define SBP_SETTINGS_REGISTER_RESP_STATUS_REGISTER_STATUS_GET(flags) \
                             (((flags) >> SBP_SETTINGS_REGISTER_RESP_STATUS_REGISTER_STATUS_SHIFT) \
                             & SBP_SETTINGS_REGISTER_RESP_STATUS_REGISTER_STATUS_MASK)
#define SBP_SETTINGS_REGISTER_RESP_STATUS_REGISTER_STATUS_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_SETTINGS_REGISTER_RESP_STATUS_REGISTER_STATUS_MASK)) \
                             << (SBP_SETTINGS_REGISTER_RESP_STATUS_REGISTER_STATUS_SHIFT)));} while(0)
                             

#define SBP_SETTINGS_REGISTER_RESP_STATUS_REGISTER_STATUS_ACCEPTED_REQUESTED_DEFAULT_VALUE_RETURNED (0)
#define SBP_SETTINGS_REGISTER_RESP_STATUS_REGISTER_STATUS_ACCEPTED_SETTING_FOUND_IN_PERMANENT_STORAGE_VALUE_FROM_STORAGE_RETURNED (1)
#define SBP_SETTINGS_REGISTER_RESP_STATUS_REGISTER_STATUS_REJECTED_SETTING_ALREADY_REGISTERED_VALUE_FROM_MEMORY_RETURNED (2)
#define SBP_SETTINGS_REGISTER_RESP_STATUS_REGISTER_STATUS_REJECTED_MALFORMED_MESSAGE (3)
typedef struct {
  
  /**
* Register status
   */
    u8
  status
  ;
  /**
 * A NULL-terminated and delimited string with contents
 * "SECTION_SETTING\0SETTING\0VALUE". The meaning of value is defined
 * according to the status field.
   */
    char
  setting
    [254]
  ;
} sbp_msg_settings_register_resp_t;

static inline size_t sbp_packed_size_sbp_msg_settings_register_resp_t(const sbp_msg_settings_register_resp_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				sizeof( msg->status )                                                                          
	  +
      sbp_strlen( msg->setting, "3-section" );
}

static inline bool sbp_pack_sbp_msg_settings_register_resp_t(u8 *buf, size_t len, const sbp_msg_settings_register_resp_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_settings_register_resp_t(msg) > len) { return false; }
  
        
  if (offset + 1 > len) { return false; }
  u8 msgstatus = msg->status;
  memcpy(buf + offset, & msgstatus , 1);
  offset += 1;
      if (offset + sbp_strlen( msg->setting, "3-section") > len) { return false; }
      offset += sbp_pack_string( buf + offset, msg->setting, "3-section");
  return true;
}

static inline bool sbp_unpack_sbp_msg_settings_register_resp_t(const u8 *buf, size_t len, sbp_msg_settings_register_resp_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->status, buf + offset, 1);
  offset += 1;
    offset += sbp_unpack_string((const char *)buf + offset, len - offset, msg->setting, "3-section");
  return true;
}

#ifdef __cplusplus
static inline bool operator== ( const sbp_msg_settings_register_resp_t &a, const sbp_msg_settings_register_resp_t &b) {
  (void)a;
  (void)b;
  
        
    if (a.status != b.status) { return false; }
        if (sbp_strcmp(a.setting, b.setting, "3-section") != 0) { return false; }

  return true;
}

static inline bool operator!=(const sbp_msg_settings_register_resp_t &a, const sbp_msg_settings_register_resp_t &b) {
  return !(a == b);
}
#endif


#endif /* LIBSBP_SETTINGS_MESSAGES_H */