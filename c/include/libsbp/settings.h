/*
 * Copyright (C) 2015 Swift Navigation Inc.
 * Contact: Fergus Noble <fergus@swift-nav.com>
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
 * These are in the implementation-defined range (0x0000-0x00FF). Note
 * that some of these messages share the same message type ID for both
 * the host request and the device response. See the accompanying
 * document for descriptions of settings configurations and examples:
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
* The setting message writes the device's configuration.
 */
#define SBP_MSG_SETTINGS_WRITE              0x00A0
typedef struct __attribute__((packed)) {
  char setting[0]; /**< A NULL-terminated and delimited string with contents
[SECTION_SETTING, SETTING, VALUE].
 */
} msg_settings_write_t;


/** Read device configuration settings (host => device)
 *
* The setting message reads the device's configuration.
 */
#define SBP_MSG_SETTINGS_READ_REQ           0x00A4
typedef struct __attribute__((packed)) {
  char setting[0]; /**< A NULL-terminated and delimited string with contents
[SECTION_SETTING, SETTING].
 */
} msg_settings_read_req_t;


/** Read device configuration settings (host <= device)
 *
* The setting message reads the device's configuration.
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
 * [SECTION_SETTING, SETTING, VALUE].
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


/** \} */

#endif /* LIBSBP_SETTINGS_MESSAGES_H */