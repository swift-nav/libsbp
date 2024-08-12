# Copyright (C) 2015-2023 Swift Navigation Inc.
# Contact: https://support.swiftnav.com
#
# This source is subject to the license found in the file 'LICENSE' which must
# be distributed together with this source. All other rights reserved.
#
# THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
# EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
# WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
#
# Messages for reading, writing, and discovering device settings. Settings with a
# "string" field have multiple values in this field delimited with a null
# character (the c style null terminator).  For instance, when querying the
# 'firmware_version' setting in the 'system_info' section, the following array of
# characters needs to be sent for the string field in MSG_SETTINGS_READ:
# "system_info\0firmware_version\0", where the delimiting null characters are
# specified with the escape sequence '\0' and all quotation marks should be
# omitted.  In the message descriptions below, the generic strings SECTION_SETTING
# and SETTING are used to refer to the two strings that comprise the identifier of
# an individual setting.In firmware_version example above, SECTION_SETTING is the
# 'system_info', and the SETTING portion is 'firmware_version'. See the "Software
# Settings Manual" on support.swiftnav.com for detailed documentation about all
# settings and sections available for each Swift firmware version. Settings
# manuals are available for each firmware version at the following link:
# https://support.swiftnav.com/support/solutions/articles/44001850753-piksi-multi-
# specification. The latest settings document is also available at the following
# link: http://swiftnav.com/latest/piksi-multi-settings . See lastly
# https://github.com/swift-nav/piksi_tools/blob/master/piksi_tools/settings.py ,
# the open source python command line utility for reading, writing, and saving
# settings in the piksi_tools repository on github as a helpful reference and
# example.
#
# Automatically generated from spec/yaml/swiftnav/sbp/settings.yaml with generate.py.
# Do not modify by hand!

meta:
  id: settings
  endian: le
  imports: [  ]

types:

  msg_settings_save:
    doc: |
      The save settings message persists the device's current settings
      configuration to its onboard flash memory file system.
    seq: []
  
  msg_settings_write:
    doc: |
      The setting message writes the device configuration for a particular
      setting via A NULL-terminated and NULL-delimited string with contents
      "SECTION_SETTING\0SETTING\0VALUE\0" where the '\0' escape sequence
      denotes the NULL character and where quotation marks are omitted. A
      device will only process to this message when it is received from sender
      ID 0x42. An example string that could be sent to a device is
      "solution\0soln_freq\010\0".
    seq:
      - id: setting
        doc: |
          A NULL-terminated and NULL-delimited string with contents
          "SECTION_SETTING\0SETTING\0VALUE\0"
        type: str
        encoding: ascii
        size-eos: true
  
  msg_settings_write_resp:
    doc: |
      Return the status of a write request with the new value of the setting.
      If the requested value is rejected, the current value will be returned.
      The string field is a NULL-terminated and NULL-delimited string with
      contents "SECTION_SETTING\0SETTING\0VALUE\0" where the '\0' escape
      sequence denotes the NULL character and where quotation marks are
      omitted. An example string that could be sent from device is
      "solution\0soln_freq\010\0".
    seq:
      - id: status
        doc: |
          Write status
        type: u1
      - id: setting
        doc: |
          A NULL-terminated and delimited string with contents
          "SECTION_SETTING\0SETTING\0VALUE\0"
        type: str
        encoding: ascii
        size-eos: true
  
  msg_settings_read_req:
    doc: |
      The setting message that reads the device configuration. The string
      field is a NULL-terminated and NULL-delimited string with contents
      "SECTION_SETTING\0SETTING\0" where the '\0' escape sequence denotes the
      NULL character and where quotation marks are omitted. An example string
      that could be sent to a device is "solution\0soln_freq\0". A device will
      only respond to this message when it is received from sender ID 0x42. A
      device should respond with a MSG_SETTINGS_READ_RESP message (msg_id
      0x00A5).
    seq:
      - id: setting
        doc: |
          A NULL-terminated and NULL-delimited string with contents
          "SECTION_SETTING\0SETTING\0"
        type: str
        encoding: ascii
        size-eos: true
  
  msg_settings_read_resp:
    doc: |
      The setting message with which the device responds after a
      MSG_SETTING_READ_REQ is sent to device. The string field is a NULL-
      terminated and NULL-delimited string with contents
      "SECTION_SETTING\0SETTING\0VALUE\0" where the '\0' escape sequence
      denotes the NULL character and where quotation marks are omitted. An
      example string that could be sent from device is
      "solution\0soln_freq\010\0".
    seq:
      - id: setting
        doc: |
          A NULL-terminated and NULL-delimited string with contents
          "SECTION_SETTING\0SETTING\0VALUE\0"
        type: str
        encoding: ascii
        size-eos: true
  
  msg_settings_read_by_index_req:
    doc: |
      The settings message for iterating through the settings values. A device
      will respond to this message with a "MSG_SETTINGS_READ_BY_INDEX_RESP".
    seq:
      - id: index
        doc: |
          An index into the device settings, with values ranging from 0 to
          length(settings).
        type: u2
  
  msg_settings_read_by_index_resp:
    doc: |
      The settings message that reports the value of a setting at an index.

      In the string field, it reports NULL-terminated and delimited string
      with contents "SECTION_SETTING\0SETTING\0VALUE\0FORMAT_TYPE\0". where
      the '\0' escape sequence denotes the NULL character and where quotation
      marks are omitted. The FORMAT_TYPE field is optional and denotes
      possible string values of the setting as a hint to the user. If
      included, the format type portion of the string has the format
      "enum:value1,value2,value3". An example string that could be sent from
      the device is "simulator\0enabled\0True\0enum:True,False\0".
    seq:
      - id: index
        doc: |
          An index into the device settings, with values ranging from 0 to
          length(settings)
        type: u2
      - id: setting
        doc: |
          A NULL-terminated and delimited string with contents
          "SECTION_SETTING\0SETTING\0VALUE\0FORMAT_TYPE\0"
        type: str
        encoding: ascii
        size-eos: true
  
  msg_settings_read_by_index_done:
    doc: |
      The settings message for indicating end of the settings values.
    seq: []
  
  msg_settings_register:
    doc: |
      This message registers the presence and default value of a setting with
      a settings daemon.  The host should reply with MSG_SETTINGS_WRITE for
      this setting to set the initial value.
    seq:
      - id: setting
        doc: |
          A NULL-terminated and delimited string with contents
          "SECTION_SETTING\0SETTING\0VALUE".
        type: str
        encoding: ascii
        size-eos: true
  
  msg_settings_register_resp:
    doc: |
      This message responds to setting registration with the effective value.
      The effective value shall differ from the given default value if setting
      was already registered or is available in the permanent setting storage
      and had a different value.
    seq:
      - id: status
        doc: |
          Register status
        type: u1
      - id: setting
        doc: |
          A NULL-terminated and delimited string with contents
          "SECTION_SETTING\0SETTING\0VALUE". The meaning of value is defined
          according to the status field.
        type: str
        encoding: ascii
        size-eos: true
  