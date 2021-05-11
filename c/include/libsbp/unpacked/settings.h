#ifndef LIBSBP_SETTINGS_MESSAGES_H
#define LIBSBP_SETTINGS_MESSAGES_H

#include <endian.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>

#include <libsbp/common.h>
#include <libsbp/string2.h>
/** Save settings to flash (host => device)
 *
 * The save settings message persists the device's current settings
 * configuration to its onboard flash memory file system.
 */
#define SBP_MSG_SETTINGS_SAVE 0x00A1

typedef struct
{
  char dummy_to_avoid_empty_struct___do_not_use;
} sbp_msg_settings_save_t;

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
#define SBP_MSG_SETTINGS_WRITE 0x00A0

typedef struct
{

  /**
   * A NULL-terminated and NULL-delimited string with contents
   * "SECTION_SETTING\0SETTING\0VALUE\0"
   */
  sbp_multipart_string_t setting;
} sbp_msg_settings_write_t;

#define sbp_msg_settings_write_t_setting_init(f) , sbp_multipart_string_init(f, 255, 3, 3)
#define sbp_msg_settings_write_t_setting_packed_len(f) sbp_multipart_string_packed_len(f, 255, 3, 3)
#define sbp_msg_settings_write_t_setting_append(f, s) sbp_multipart_string_append(f, s, 255, 3, 3)
#define sbp_msg_settings_write_t_setting_append_printf(f, ...) \
  sbp_multipart_string_append_printf(s, 255, 3, 3, __VA_ARGS__)
#define sbp_msg_settings_write_t_setting_count_sections(f) sbp_multipart_string_count_sections(f, 255, 3, 3)
#define sbp_msg_settings_write_t_setting_get_section(f, s) sbp_multipart_string_get_section(f, s, 255, 3, 3)
#define sbp_msg_settings_write_t_setting_section_len(f, s) sbp_multipart_string_section_len(f, s, 255, 3, 3)
#define sbp_msg_settings_write_t_setting_space_remaining(f) sbp_multipart_string_space_remaining(f, 255, 3, 3)
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
#define SBP_MSG_SETTINGS_WRITE_RESP 0x00AF

#define SBP_SETTINGS_WRITE_RESP_STATUS_WRITE_STATUS_MASK (0x3)
#define SBP_SETTINGS_WRITE_RESP_STATUS_WRITE_STATUS_SHIFT (0u)
#define SBP_SETTINGS_WRITE_RESP_STATUS_WRITE_STATUS_GET(flags) \
  (((flags) >> SBP_SETTINGS_WRITE_RESP_STATUS_WRITE_STATUS_SHIFT) & SBP_SETTINGS_WRITE_RESP_STATUS_WRITE_STATUS_MASK)
#define SBP_SETTINGS_WRITE_RESP_STATUS_WRITE_STATUS_SET(flags, val) \
  do \
  { \
    ((flags) |= (((val) & (SBP_SETTINGS_WRITE_RESP_STATUS_WRITE_STATUS_MASK)) \
                 << (SBP_SETTINGS_WRITE_RESP_STATUS_WRITE_STATUS_SHIFT))); \
  } while (0)

#define SBP_SETTINGS_WRITE_RESP_STATUS_WRITE_STATUS_ACCEPTED_VALUE_UPDATED (0)
#define SBP_SETTINGS_WRITE_RESP_STATUS_WRITE_STATUS_REJECTED_VALUE_UNPARSABLE_OR_OUT_OF_RANGE (1)
#define SBP_SETTINGS_WRITE_RESP_STATUS_WRITE_STATUS_REJECTED_REQUESTED_SETTING_DOES_NOT_EXIST (2)
#define SBP_SETTINGS_WRITE_RESP_STATUS_WRITE_STATUS_REJECTED_SETTING_NAME_COULD_NOT_BE_PARSED (3)
#define SBP_SETTINGS_WRITE_RESP_STATUS_WRITE_STATUS_REJECTED_SETTING_IS_READ_ONLY (4)
#define SBP_SETTINGS_WRITE_RESP_STATUS_WRITE_STATUS_REJECTED_MODIFICATION_IS_TEMPORARILY_DISABLED (5)
#define SBP_SETTINGS_WRITE_RESP_STATUS_WRITE_STATUS_REJECTED_UNSPECIFIED_ERROR (6)
typedef struct
{

  /**
   * Write status
   */
  u8 status;
  /**
   * A NULL-terminated and delimited string with contents
   * "SECTION_SETTING\0SETTING\0VALUE\0"
   */
  sbp_multipart_string_t setting;
} sbp_msg_settings_write_resp_t;

#define sbp_msg_settings_write_resp_t_setting_init(f) , sbp_multipart_string_init(f, 254, 3, 3)
#define sbp_msg_settings_write_resp_t_setting_packed_len(f) sbp_multipart_string_packed_len(f, 254, 3, 3)
#define sbp_msg_settings_write_resp_t_setting_append(f, s) sbp_multipart_string_append(f, s, 254, 3, 3)
#define sbp_msg_settings_write_resp_t_setting_append_printf(f, ...) \
  sbp_multipart_string_append_printf(s, 254, 3, 3, __VA_ARGS__)
#define sbp_msg_settings_write_resp_t_setting_count_sections(f) sbp_multipart_string_count_sections(f, 254, 3, 3)
#define sbp_msg_settings_write_resp_t_setting_get_section(f, s) sbp_multipart_string_get_section(f, s, 254, 3, 3)
#define sbp_msg_settings_write_resp_t_setting_section_len(f, s) sbp_multipart_string_section_len(f, s, 254, 3, 3)
#define sbp_msg_settings_write_resp_t_setting_space_remaining(f) sbp_multipart_string_space_remaining(f, 254, 3, 3)
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
#define SBP_MSG_SETTINGS_READ_REQ 0x00A4

typedef struct
{

  /**
   * A NULL-terminated and NULL-delimited string with contents
   * "SECTION_SETTING\0SETTING\0"
   */
  sbp_multipart_string_t setting;
} sbp_msg_settings_read_req_t;

#define sbp_msg_settings_read_req_t_setting_init(f) , sbp_multipart_string_init(f, 255, 2, 2)
#define sbp_msg_settings_read_req_t_setting_packed_len(f) sbp_multipart_string_packed_len(f, 255, 2, 2)
#define sbp_msg_settings_read_req_t_setting_append(f, s) sbp_multipart_string_append(f, s, 255, 2, 2)
#define sbp_msg_settings_read_req_t_setting_append_printf(f, ...) \
  sbp_multipart_string_append_printf(s, 255, 2, 2, __VA_ARGS__)
#define sbp_msg_settings_read_req_t_setting_count_sections(f) sbp_multipart_string_count_sections(f, 255, 2, 2)
#define sbp_msg_settings_read_req_t_setting_get_section(f, s) sbp_multipart_string_get_section(f, s, 255, 2, 2)
#define sbp_msg_settings_read_req_t_setting_section_len(f, s) sbp_multipart_string_section_len(f, s, 255, 2, 2)
#define sbp_msg_settings_read_req_t_setting_space_remaining(f) sbp_multipart_string_space_remaining(f, 255, 2, 2)
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
#define SBP_MSG_SETTINGS_READ_RESP 0x00A5

typedef struct
{

  /**
   * A NULL-terminated and NULL-delimited string with contents
   * "SECTION_SETTING\0SETTING\0VALUE\0"
   *
   */
  sbp_multipart_string_t setting;
} sbp_msg_settings_read_resp_t;

#define sbp_msg_settings_read_resp_t_setting_init(f) , sbp_multipart_string_init(f, 255, 3, 3)
#define sbp_msg_settings_read_resp_t_setting_packed_len(f) sbp_multipart_string_packed_len(f, 255, 3, 3)
#define sbp_msg_settings_read_resp_t_setting_append(f, s) sbp_multipart_string_append(f, s, 255, 3, 3)
#define sbp_msg_settings_read_resp_t_setting_append_printf(f, ...) \
  sbp_multipart_string_append_printf(s, 255, 3, 3, __VA_ARGS__)
#define sbp_msg_settings_read_resp_t_setting_count_sections(f) sbp_multipart_string_count_sections(f, 255, 3, 3)
#define sbp_msg_settings_read_resp_t_setting_get_section(f, s) sbp_multipart_string_get_section(f, s, 255, 3, 3)
#define sbp_msg_settings_read_resp_t_setting_section_len(f, s) sbp_multipart_string_section_len(f, s, 255, 3, 3)
#define sbp_msg_settings_read_resp_t_setting_space_remaining(f) sbp_multipart_string_space_remaining(f, 255, 3, 3)
/** Read setting by direct index (host => device)
 *
 * The settings message for iterating through the settings
 * values. A device will respond to this message with a
 * "MSG_SETTINGS_READ_BY_INDEX_RESP".
 */
#define SBP_MSG_SETTINGS_READ_BY_INDEX_REQ 0x00A2

typedef struct
{

  /**
   * An index into the device settings, with values ranging from
   * 0 to length(settings)
   */
  u16 index;
} sbp_msg_settings_read_by_index_req_t;

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

typedef struct
{

  /**
   * An index into the device settings, with values ranging from
   * 0 to length(settings)
   */
  u16 index;
  /**
   * A NULL-terminated and delimited string with contents
   * "SECTION_SETTING\0SETTING\0VALUE\0FORMAT_TYPE\0"
   */
  sbp_multipart_string_t setting;
} sbp_msg_settings_read_by_index_resp_t;

#define sbp_msg_settings_read_by_index_resp_t_setting_init(f) , sbp_multipart_string_init(f, 253, 3, 4)
#define sbp_msg_settings_read_by_index_resp_t_setting_packed_len(f) sbp_multipart_string_packed_len(f, 253, 3, 4)
#define sbp_msg_settings_read_by_index_resp_t_setting_append(f, s) sbp_multipart_string_append(f, s, 253, 3, 4)
#define sbp_msg_settings_read_by_index_resp_t_setting_append_printf(f, ...) \
  sbp_multipart_string_append_printf(s, 253, 3, 4, __VA_ARGS__)
#define sbp_msg_settings_read_by_index_resp_t_setting_count_sections(f) \
  sbp_multipart_string_count_sections(f, 253, 3, 4)
#define sbp_msg_settings_read_by_index_resp_t_setting_get_section(f, s) \
  sbp_multipart_string_get_section(f, s, 253, 3, 4)
#define sbp_msg_settings_read_by_index_resp_t_setting_section_len(f, s) \
  sbp_multipart_string_section_len(f, s, 253, 3, 4)
#define sbp_msg_settings_read_by_index_resp_t_setting_space_remaining(f) \
  sbp_multipart_string_space_remaining(f, 253, 3, 4)
/** Finished reading settings (host <= device)
 *
 * The settings message for indicating end of the settings values.
 */
#define SBP_MSG_SETTINGS_READ_BY_INDEX_DONE 0x00A6

typedef struct
{
  char dummy_to_avoid_empty_struct___do_not_use;
} sbp_msg_settings_read_by_index_done_t;

/** Register setting and default value (device => host)
 *
 * This message registers the presence and default value of a setting
 * with a settings daemon.  The host should reply with MSG_SETTINGS_WRITE
 * for this setting to set the initial value.
 */
#define SBP_MSG_SETTINGS_REGISTER 0x00AE

typedef struct
{

  /**
   * A NULL-terminated and delimited string with contents
   * "SECTION_SETTING\0SETTING\0VALUE".
   */
  sbp_multipart_string_t setting;
} sbp_msg_settings_register_t;

#define sbp_msg_settings_register_t_setting_init(f) , sbp_multipart_string_init(f, 255, 3, 3)
#define sbp_msg_settings_register_t_setting_packed_len(f) sbp_multipart_string_packed_len(f, 255, 3, 3)
#define sbp_msg_settings_register_t_setting_append(f, s) sbp_multipart_string_append(f, s, 255, 3, 3)
#define sbp_msg_settings_register_t_setting_append_printf(f, ...) \
  sbp_multipart_string_append_printf(s, 255, 3, 3, __VA_ARGS__)
#define sbp_msg_settings_register_t_setting_count_sections(f) sbp_multipart_string_count_sections(f, 255, 3, 3)
#define sbp_msg_settings_register_t_setting_get_section(f, s) sbp_multipart_string_get_section(f, s, 255, 3, 3)
#define sbp_msg_settings_register_t_setting_section_len(f, s) sbp_multipart_string_section_len(f, s, 255, 3, 3)
#define sbp_msg_settings_register_t_setting_space_remaining(f) sbp_multipart_string_space_remaining(f, 255, 3, 3)
/** Register setting and default value (device <= host)
 *
 * This message responds to setting registration with the effective value.
 * The effective value shall differ from the given default value if setting
 * was already registered or is available in the permanent setting storage
 * and had a different value.
 */
#define SBP_MSG_SETTINGS_REGISTER_RESP 0x01AF

#define SBP_SETTINGS_REGISTER_RESP_STATUS_REGISTER_STATUS_MASK (0x3)
#define SBP_SETTINGS_REGISTER_RESP_STATUS_REGISTER_STATUS_SHIFT (0u)
#define SBP_SETTINGS_REGISTER_RESP_STATUS_REGISTER_STATUS_GET(flags) \
  (((flags) >> SBP_SETTINGS_REGISTER_RESP_STATUS_REGISTER_STATUS_SHIFT) & \
   SBP_SETTINGS_REGISTER_RESP_STATUS_REGISTER_STATUS_MASK)
#define SBP_SETTINGS_REGISTER_RESP_STATUS_REGISTER_STATUS_SET(flags, val) \
  do \
  { \
    ((flags) |= (((val) & (SBP_SETTINGS_REGISTER_RESP_STATUS_REGISTER_STATUS_MASK)) \
                 << (SBP_SETTINGS_REGISTER_RESP_STATUS_REGISTER_STATUS_SHIFT))); \
  } while (0)

#define SBP_SETTINGS_REGISTER_RESP_STATUS_REGISTER_STATUS_ACCEPTED_REQUESTED_DEFAULT_VALUE_RETURNED (0)
#define SBP_SETTINGS_REGISTER_RESP_STATUS_REGISTER_STATUS_ACCEPTED_SETTING_FOUND_IN_PERMANENT_STORAGE_VALUE_FROM_STORAGE_RETURNED \
  (1)
#define SBP_SETTINGS_REGISTER_RESP_STATUS_REGISTER_STATUS_REJECTED_SETTING_ALREADY_REGISTERED_VALUE_FROM_MEMORY_RETURNED \
  (2)
#define SBP_SETTINGS_REGISTER_RESP_STATUS_REGISTER_STATUS_REJECTED_MALFORMED_MESSAGE (3)
typedef struct
{

  /**
   * Register status
   */
  u8 status;
  /**
   * A NULL-terminated and delimited string with contents
   * "SECTION_SETTING\0SETTING\0VALUE". The meaning of value is defined
   * according to the status field.
   */
  sbp_multipart_string_t setting;
} sbp_msg_settings_register_resp_t;

#define sbp_msg_settings_register_resp_t_setting_init(f) , sbp_multipart_string_init(f, 254, 3, 3)
#define sbp_msg_settings_register_resp_t_setting_packed_len(f) sbp_multipart_string_packed_len(f, 254, 3, 3)
#define sbp_msg_settings_register_resp_t_setting_append(f, s) sbp_multipart_string_append(f, s, 254, 3, 3)
#define sbp_msg_settings_register_resp_t_setting_append_printf(f, ...) \
  sbp_multipart_string_append_printf(s, 254, 3, 3, __VA_ARGS__)
#define sbp_msg_settings_register_resp_t_setting_count_sections(f) sbp_multipart_string_count_sections(f, 254, 3, 3)
#define sbp_msg_settings_register_resp_t_setting_get_section(f, s) sbp_multipart_string_get_section(f, s, 254, 3, 3)
#define sbp_msg_settings_register_resp_t_setting_section_len(f, s) sbp_multipart_string_section_len(f, s, 254, 3, 3)
#define sbp_msg_settings_register_resp_t_setting_space_remaining(f) sbp_multipart_string_space_remaining(f, 254, 3, 3)

#include <libsbp/unpacked/settings_operators.h>
#include <libsbp/unpacked/settings_packers.h>

#endif /* LIBSBP_SETTINGS_MESSAGES_H */
