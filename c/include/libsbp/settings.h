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
 * with generate.py at 2015-04-10 12:07:06.198589. Please do not hand edit!
 *****************************************************************************/

/** \defgroup settings Settings
 *
 *  * Messages for reading and writing the Piksi's device settings. These
 * are in the implementation-defined range (0x0000-0x00FF), and
 * intended for internal-use only. Please see the accompanying
 * description of settings configurations for more details. Note that
 * some of these messages taking a request from a host and a response
 * from the Piksi share the same message type ID.
 * \{ */

#ifndef LIBSBP_SETTINGS_MESSAGES_H
#define LIBSBP_SETTINGS_MESSAGES_H

#include "common.h"


/** Read/write Piksi configuration settings (Host <=> Piksi).
 *
 * The setting message reads and writes the Piksi's configuration.
 */
#define SBP_MSG_SETTINGS               0x00A0
typedef struct __attribute__((packed)) {
  char* setting;    /**< A NULL delimited (and terminated) string, with the A
NULL-terminated and delimited string with contents
[SECTION_SETTING, SETTING, VALUE] on writes or a series of
such strings on reads.
 */
} msg_settings_t;


/** Save settings to flash (Host => Piksi)
 *
 * The save settings message persists the Piksi's current settings
 * configuration to its onboard flash memory file system.
 */
#define SBP_MSG_SETTINGS_SAVE          0x00A1


/** Read setting by direct index (Host <=> Piksi)
 *
 * The settings message for iterating through the settings
 * values. It will read the setting at an index, returning a
 * NULL-terminated and delimited string with contents
 * [SECTION_SETTING, SETTING, VALUE].
 */
#define SBP_MSG_SETTINGS_READ_BY_INDEX 0x00A2
typedef struct __attribute__((packed)) {
  u16 index;    /**< An index into the Piksi settings, with values ranging from
0 to length(settings)
 */
} msg_settings_read_by_index_t;


/** \} */

#endif /* LIBSBP_SETTINGS_MESSAGES_H */