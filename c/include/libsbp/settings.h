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
 *  * Messages for reading and writing the device's device settings.
 * 
 * Note that some of these messages share the same message type ID for both the
 * host request and the device response. See the accompanying document for
 * descriptions of settings configurations and examples:
 * 
 * https://github.com/swift-nav/piksi\_firmware/blob/master/docs/settings.pdf
 * \{ */

#ifndef LIBSBP_SETTINGS_MESSAGES_H
#define LIBSBP_SETTINGS_MESSAGES_H

#include "common.h"


/** Save settings to flash (host => device)
 *
 * The save settings message persists the device's current settings
 * configuration to its onboard flash memory file system.
 */
#define SBP_MSG_SETTINGS_SAVE               0x00A1


/** Write device configuration settings (host => device)
 *
* The setting message writes the device configuration.
 */
#define SBP_MSG_SETTINGS_WRITE              0x00A0
typedef struct __attribute__((packed)) {
  char setting[0]; /**< A NULL-terminated and delimited string with contents
[SECTION_SETTING, SETTING, VALUE]. A device will only
process to this message when it is received from sender ID
0x42.
 */
} msg_settings_write_t;


/** Acknowledgement with status of MSG_SETTINGS_WRITE
 *
 * Return the status of a write request with the new value of the
 * setting.  If the requested value is rejected, the current value
 * will be returned.
 */
#define SBP_MSG_SETTINGS_WRITE_RESP         0x00AF
typedef struct __attribute__((packed)) {
  u8 status;     /**< Write status */
  char setting[0]; /**< A NULL-terminated and delimited string with contents
[SECTION_SETTING, SETTING, VALUE].
 */
} msg_settings_write_resp_t;


/** Read device configuration settings (host => device)
 *
* The setting message reads the device configuration.
 */
#define SBP_MSG_SETTINGS_READ_REQ           0x00A4
typedef struct __attribute__((packed)) {
  char setting[0]; /**< A NULL-terminated and delimited string with contents
[SECTION_SETTING, SETTING]. A device will only respond to
this message when it is received from sender ID 0x42.
 */
} msg_settings_read_req_t;


/** Read device configuration settings (host <= device)
 *
* The setting message reads the device configuration.
 */
#define SBP_MSG_SETTINGS_READ_RESP          0x00A5
typedef struct __attribute__((packed)) {
  char setting[0]; /**< A NULL-terminated and delimited string with contents
[SECTION_SETTING, SETTING, VALUE].
 */
} msg_settings_read_resp_t;


/** Read setting by direct index (host => device)
 *
 * The settings message for iterating through the settings
 * values. It will read the setting at an index, returning a
 * NULL-terminated and delimited string with contents
 * [SECTION_SETTING, SETTING, VALUE]. A device will only respond to
 * this message when it is received from sender ID 0x42.
 */
#define SBP_MSG_SETTINGS_READ_BY_INDEX_REQ  0x00A2
typedef struct __attribute__((packed)) {
  u16 index;    /**< An index into the device settings, with values ranging from
0 to length(settings)
 */
} msg_settings_read_by_index_req_t;


/** Read setting by direct index (host <= device)
 *
 * The settings message for iterating through the settings
 * values. It will read the setting at an index, returning a
 * NULL-terminated and delimited string with contents
 * [SECTION_SETTING, SETTING, VALUE].
 */
#define SBP_MSG_SETTINGS_READ_BY_INDEX_RESP 0x00A7
typedef struct __attribute__((packed)) {
  u16 index;      /**< An index into the device settings, with values ranging from
0 to length(settings)
 */
  char setting[0]; /**< A NULL-terminated and delimited string with contents
[SECTION_SETTING, SETTING, VALUE].
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
typedef struct __attribute__((packed)) {
  char setting[0]; /**< A NULL-terminated and delimited string with contents
[SECTION_SETTING, SETTING, VALUE].
 */
} msg_settings_register_t;


/** \} */

#endif /* LIBSBP_SETTINGS_MESSAGES_H */