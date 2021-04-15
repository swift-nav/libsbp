/*
 * Copyright (C) 2021 Swift Navigation Inc.
 * Contact: https://support.swiftnav.com
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

#ifndef LIBSBP_CPP_SETTINGS_MESSAGES_H
#define LIBSBP_CPP_SETTINGS_MESSAGES_H

#include <cstddef>
#include <libsbp/common.h>
#include <libsbp/sbp.h>

namespace sbp {
  
  /**
   * Save settings to flash (host => device)
   *
   * The save settings message persists the device's current settings
   * configuration to its onboard flash memory file system.
   */
  constexpr u16 MSG_SETTINGS_SAVE = 0x00A1;

  
  /**
   * Write device configuration settings (host => device)
   *
   * The setting message writes the device configuration for a particular
   * setting via A NULL-terminated and NULL-delimited string with contents
   * "SECTION_SETTING\0SETTING\0VALUE\0" where the '\0' escape sequence denotes 
   * the NULL character and where quotation marks are omitted. A device will
   * only process to this message when it is received from sender ID 0x42.
   * An example string that could be sent to a device is
   * "solution\0soln_freq\010\0".
   */
  constexpr u16 MSG_SETTINGS_WRITE = 0x00A0;

  template<size_t SETTING_COUNT = (SBP_MAX_PAYLOAD_LEN - 0) / sizeof(char)>
  struct SBP_ATTR_PACKED MsgSettingsWrite {
    char setting[SETTING_COUNT]; /** A NULL-terminated and NULL-delimited string with contents
"SECTION_SETTING\0SETTING\0VALUE\0"
 */
  };

  
  /**
   * Acknowledgement with status of MSG_SETTINGS_WRITE
   *
   * Return the status of a write request with the new value of the
   * setting.  If the requested value is rejected, the current value
   * will be returned. The string field is a NULL-terminated and NULL-delimited
   * string with contents "SECTION_SETTING\0SETTING\0VALUE\0" where the '\0'
   * escape sequence denotes the NULL character and where quotation marks
   * are omitted. An example string that could be sent from device is
   * "solution\0soln_freq\010\0".
   */
  constexpr u16 MSG_SETTINGS_WRITE_RESP = 0x00AF;

  template<size_t SETTING_COUNT = (SBP_MAX_PAYLOAD_LEN - sizeof(u8) + 0) / sizeof(char)>
  struct SBP_ATTR_PACKED MsgSettingsWriteResp {
    u8 status /** Write status */
    char setting[SETTING_COUNT]; /** A NULL-terminated and delimited string with contents
"SECTION_SETTING\0SETTING\0VALUE\0" 
 */
  };

  
  /**
   * Read device configuration settings (host => device)
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
  constexpr u16 MSG_SETTINGS_READ_REQ = 0x00A4;

  template<size_t SETTING_COUNT = (SBP_MAX_PAYLOAD_LEN - 0) / sizeof(char)>
  struct SBP_ATTR_PACKED MsgSettingsReadReq {
    char setting[SETTING_COUNT]; /** A NULL-terminated and NULL-delimited string with contents
"SECTION_SETTING\0SETTING\0"
 */
  };

  
  /**
   * Read device configuration settings (host <= device)
   *
   * The setting message wich which the device responds after a
   * MSG_SETTING_READ_REQ is sent to device. The string field is a
   * NULL-terminated and NULL-delimited string with contents
   * "SECTION_SETTING\0SETTING\0VALUE\0" where the '\0' escape sequence
   * denotes the NULL character and where quotation marks are omitted. An
   * example string that could be sent from device is
   * "solution\0soln_freq\010\0".
   */
  constexpr u16 MSG_SETTINGS_READ_RESP = 0x00A5;

  template<size_t SETTING_COUNT = (SBP_MAX_PAYLOAD_LEN - 0) / sizeof(char)>
  struct SBP_ATTR_PACKED MsgSettingsReadResp {
    char setting[SETTING_COUNT]; /** A NULL-terminated and NULL-delimited string with contents
"SECTION_SETTING\0SETTING\0VALUE\0"
 
 */
  };

  
  /**
   * Read setting by direct index (host => device)
   *
   * The settings message for iterating through the settings
   * values. A device will respond to this message with a 
   * "MSG_SETTINGS_READ_BY_INDEX_RESP".
   */
  constexpr u16 MSG_SETTINGS_READ_BY_INDEX_REQ = 0x00A2;

  
  struct SBP_ATTR_PACKED MsgSettingsReadByIndexReq {
    u16 index /** An index into the device settings, with values ranging from
0 to length(settings)
 */
  };

  
  /**
   * Read setting by direct index (host <= device)
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
  constexpr u16 MSG_SETTINGS_READ_BY_INDEX_RESP = 0x00A7;

  template<size_t SETTING_COUNT = (SBP_MAX_PAYLOAD_LEN - sizeof(u16) + 0) / sizeof(char)>
  struct SBP_ATTR_PACKED MsgSettingsReadByIndexResp {
    u16 index /** An index into the device settings, with values ranging from
0 to length(settings)
 */
    char setting[SETTING_COUNT]; /** A NULL-terminated and delimited string with contents
"SECTION_SETTING\0SETTING\0VALUE\0FORMAT_TYPE\0"
 */
  };

  
  /**
   * Finished reading settings (host <= device)
   *
   * The settings message for indicating end of the settings values.
   */
  constexpr u16 MSG_SETTINGS_READ_BY_INDEX_DONE = 0x00A6;

  
  /**
   * Register setting and default value (device => host)
   *
   * This message registers the presence and default value of a setting
   * with a settings daemon.  The host should reply with MSG_SETTINGS_WRITE
   * for this setting to set the initial value.
   */
  constexpr u16 MSG_SETTINGS_REGISTER = 0x00AE;

  template<size_t SETTING_COUNT = (SBP_MAX_PAYLOAD_LEN - 0) / sizeof(char)>
  struct SBP_ATTR_PACKED MsgSettingsRegister {
    char setting[SETTING_COUNT]; /** A NULL-terminated and delimited string with contents
"SECTION_SETTING\0SETTING\0VALUE".
 */
  };

  
  /**
   * Register setting and default value (device <= host)
   *
   * This message responds to setting registration with the effective value.
   * The effective value shall differ from the given default value if setting
   * was already registered or is available in the permanent setting storage
   * and had a different value.
   */
  constexpr u16 MSG_SETTINGS_REGISTER_RESP = 0x01AF;

  template<size_t SETTING_COUNT = (SBP_MAX_PAYLOAD_LEN - sizeof(u8) + 0) / sizeof(char)>
  struct SBP_ATTR_PACKED MsgSettingsRegisterResp {
    u8 status /** Register status */
    char setting[SETTING_COUNT]; /** A NULL-terminated and delimited string with contents
"SECTION_SETTING\0SETTING\0VALUE". The meaning of value is defined
according to the status field.
 */
  };

  

}  // namespace sbp

#endif /* LIBSBP_CPP_SETTINGS_MESSAGES_H */