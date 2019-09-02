/*
 * Copyright (C) 2015-2018 Swift Navigation Inc.
 * Contact: Swift Navigation <dev@swiftnav.com>
 *
 * This source is subject to the license found in the file 'LICENSE' which must
 * be be distributed together with this source. All other rights reserved.
 *
 * THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
 * EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
 */

/*****************************************************************************
 * Automatically generated from yaml/swiftnav/sbp/settings.yaml
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

/** \defgroup settings Settings
 *
 *  * 
 * Messages for reading, writing, and discovering device settings. Settings
 * with a "string" field have multiple values in this field delimited with a
 * null character (the c style null terminator).  For instance, when querying
 * the 'firmware_version' setting in the 'system_info' section, the following
 * array of characters needs to be sent for the string field in
 * MSG_SETTINGS_READ: "system_info\0firmware_version\0", where the delimiting 
 * null characters are specified with the escape sequence '\0' and all
 * quotation marks should be omitted. 
 * 
 * 
 * In the message descriptions below, the generic strings SECTION_SETTING and
 * SETTING are used to refer to the two strings that comprise the identifier
 * of an individual setting.In firmware_version example above, SECTION_SETTING
 * is the 'system_info', and the SETTING portion is 'firmware_version'. 
 * 
 * See the "Software Settings Manual" on support.swiftnav.com for detailed
 * documentation about all settings and sections available for each Swift
 * firmware version. Settings manuals are available for each firmware version
 * at the following link: [Piksi Multi Specifications](https://support.swiftnav.com/customer/en/portal/articles/2628580-piksi-multi-specifications#settings).
 * The latest settings document is also available at the following link: 
 * [Latest settings document](http://swiftnav.com/latest/piksi-multi-settings) .
 * See lastly [settings.py](https://github.com/swift-nav/piksi_tools/blob/master/piksi_tools/settings.py) , 
 * the open source python command line utility for reading, writing, and
 * saving settings in the piksi_tools repository on github as a helpful
 * reference and example.
 * \{ */

#ifndef LIBSBP_SETTINGS_MESSAGES_H
#define LIBSBP_SETTINGS_MESSAGES_H

#include "common.h"

SBP_PACK_START


/** Save settings to flash (host => device)
 *
 * The save settings message persists the device's current settings
 * configuration to its onboard flash memory file system.
 */
#define SBP_MSG_SETTINGS_SAVE               0x00A1


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
typedef struct SBP_ATTR_PACKED {
  char setting[0]; /**< A NULL-terminated and NULL-delimited string with contents
"SECTION_SETTING\0SETTING\0VALUE\0"
 */
} msg_settings_write_t;


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
typedef struct SBP_ATTR_PACKED {
  u8 status;     /**< Write status */
  char setting[0]; /**< A NULL-terminated and delimited string with contents
"SECTION_SETTING\0SETTING\0VALUE\0" 
 */
} msg_settings_write_resp_t;


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
typedef struct SBP_ATTR_PACKED {
  char setting[0]; /**< A NULL-terminated and NULL-delimited string with contents
"SECTION_SETTING\0SETTING\0"
 */
} msg_settings_read_req_t;


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
typedef struct SBP_ATTR_PACKED {
  char setting[0]; /**< A NULL-terminated and NULL-delimited string with contents
"SECTION_SETTING\0SETTING\0VALUE\0"
 
 */
} msg_settings_read_resp_t;


/** Read setting by direct index (host => device)
 *
 * The settings message for iterating through the settings
 * values. A device will respond to this message with a 
 * "MSG_SETTINGS_READ_BY_INDEX_RESP".
 */
#define SBP_MSG_SETTINGS_READ_BY_INDEX_REQ  0x00A2
typedef struct SBP_ATTR_PACKED {
  u16 index;    /**< An index into the device settings, with values ranging from
0 to length(settings)
 */
} msg_settings_read_by_index_req_t;


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
typedef struct SBP_ATTR_PACKED {
  u16 index;      /**< An index into the device settings, with values ranging from
0 to length(settings)
 */
  char setting[0]; /**< A NULL-terminated and delimited string with contents
"SECTION_SETTING\0SETTING\0VALUE\0FORMAT_TYPE\0"
 */
} msg_settings_read_by_index_resp_t;


/** Finished reading settings (host <= device)
 *
 * The settings message for indicating end of the settings values.
 */
#define SBP_MSG_SETTINGS_READ_BY_INDEX_DONE 0x00A6


/** Register setting and default value (device => host)
 *
 * This message registers the presence and default value of a setting
 * with a settings daemon.  The host should reply with MSG_SETTINGS_WRITE
 * for this setting to set the initial value.
 */
#define SBP_MSG_SETTINGS_REGISTER           0x00AE
typedef struct SBP_ATTR_PACKED {
  char setting[0]; /**< A NULL-terminated and delimited string with contents
"SECTION_SETTING\0SETTING\0VALUE".
 */
} msg_settings_register_t;


/** Register setting and default value (device <= host)
 *
 * This message responds to setting registration with the effective value.
 * The effective value shall differ from the given default value if setting
 * was already registered or is available in the permanent setting storage
 * and had a different value.
 */
#define SBP_MSG_SETTINGS_REGISTER_RESP      0x01AF
typedef struct SBP_ATTR_PACKED {
  u8 status;     /**< Register status */
  char setting[0]; /**< A NULL-terminated and delimited string with contents
"SECTION_SETTING\0SETTING\0VALUE". The meaning of value is defined
according to the status field.
 */
} msg_settings_register_resp_t;


/** \} */

SBP_PACK_END

#endif /* LIBSBP_SETTINGS_MESSAGES_H */