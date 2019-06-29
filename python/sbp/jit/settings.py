#!/usr/bin/env python
# Copyright (C) 2015-2018 Swift Navigation Inc.
# Contact: Swift Navigation <dev@swiftnav.com>
#
# This source is subject to the license found in the file 'LICENSE' which must
# be be distributed together with this source. All other rights reserved.
#
# THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
# EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
# WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.


"""

Messages for reading, writing, and discovering device settings. Settings
with a "string" field have multiple values in this field delimited with a
null character (the c style null terminator).  For instance, when querying
the 'firmware_version' setting in the 'system_info' section, the following
array of characters needs to be sent for the string field in
MSG_SETTINGS_READ: "system_info\0firmware_version\0", where the delimiting 
null characters are specified with the escape sequence '\0' and all
quotation marks should be omitted. 


In the message descriptions below, the generic strings SECTION_SETTING and
SETTING are used to refer to the two strings that comprise the identifier
of an individual setting.In firmware_version example above, SECTION_SETTING
is the 'system_info', and the SETTING portion is 'firmware_version'. 

See the "Software Settings Manual" on support.swiftnav.com for detailed
documentation about all settings and sections available for each Swift
firmware version. Settings manuals are available for each firmware version
at the following link: https://support.swiftnav.com/customer/en/portal/articles/2628580-piksi-multi-specifications#settings.
The latest settings document is also available at the following link: 
http://swiftnav.com/latest/piksi-multi-settings .
See lastly https://github.com/swift-nav/piksi_tools/blob/master/piksi_tools/settings.py , 
the open source python command line utility for reading, writing, and
saving settings in the piksi_tools repository on github as a helpful
reference and example.

"""

import json

import numpy as np

from sbp.jit.msg import SBP, SENDER_ID
from sbp.jit.msg import get_u8, get_u16, get_u32, get_u64
from sbp.jit.msg import get_s8, get_s16, get_s32, get_s64
from sbp.jit.msg import get_f32, get_f64, judicious_round
from sbp.jit.msg import get_string, get_fixed_string, get_setting
from sbp.jit.msg import get_array, get_fixed_array

# Automatically generated from piksi/yaml/swiftnav/sbp/settings.yaml with generate.py.
# Please do not hand edit!
SBP_MSG_SETTINGS_SAVE = 0x00A1
class MsgSettingsSave(SBP):
  """SBP class for message MSG_SETTINGS_SAVE (0x00A1).

  You can have MSG_SETTINGS_SAVE inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  The save settings message persists the device's current settings
configuration to its onboard flash memory file system.


  """
  __slots__ = []
  def _unpack_members(self, buf, offset, length):
    return {}, offset, length

  def _payload_size(self):
    return 0
  
SBP_MSG_SETTINGS_WRITE = 0x00A0
class MsgSettingsWrite(SBP):
  """SBP class for message MSG_SETTINGS_WRITE (0x00A0).

  You can have MSG_SETTINGS_WRITE inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  The setting message writes the device configuration for a particular
setting via A NULL-terminated and NULL-delimited string with contents
"SECTION_SETTING\0SETTING\0VALUE\0" where the '\0' escape sequence denotes 
the NULL character and where quotation marks are omitted. A device will
only process to this message when it is received from sender ID 0x42.
An example string that could be sent to a device is
"solution\0soln_freq\010\0".


  """
  __slots__ = ['setting',
               ]
  @classmethod
  def parse_members(cls, buf, offset, length):
    ret = {}
    (__setting, offset, length) = get_setting(buf, offset, length)
    ret['setting'] = __setting
    return ret, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.setting = res['setting']
    return res, off, length

  @classmethod
  def _payload_size(self):
    ret = 0
    # setting: string
    ret += 247
    return ret
  
SBP_MSG_SETTINGS_WRITE_RESP = 0x00AF
class MsgSettingsWriteResp(SBP):
  """SBP class for message MSG_SETTINGS_WRITE_RESP (0x00AF).

  You can have MSG_SETTINGS_WRITE_RESP inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  Return the status of a write request with the new value of the
setting.  If the requested value is rejected, the current value
will be returned. The string field is a NULL-terminated and NULL-delimited
string with contents "SECTION_SETTING\0SETTING\0VALUE\0" where the '\0'
escape sequence denotes the NULL character and where quotation marks
are omitted. An example string that could be sent from device is
"solution\0soln_freq\010\0".


  """
  __slots__ = ['status',
               'setting',
               ]
  @classmethod
  def parse_members(cls, buf, offset, length):
    ret = {}
    (__status, offset, length) = get_u8(buf, offset, length)
    ret['status'] = __status
    (__setting, offset, length) = get_setting(buf, offset, length)
    ret['setting'] = __setting
    return ret, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.status = res['status']
    self.setting = res['setting']
    return res, off, length

  @classmethod
  def _payload_size(self):
    ret = 0
    # status: u8
    ret += 1
    # setting: string
    ret += 247
    return ret
  
SBP_MSG_SETTINGS_READ_REQ = 0x00A4
class MsgSettingsReadReq(SBP):
  """SBP class for message MSG_SETTINGS_READ_REQ (0x00A4).

  You can have MSG_SETTINGS_READ_REQ inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  The setting message that reads the device configuration. The string
field is a NULL-terminated and NULL-delimited string with contents
"SECTION_SETTING\0SETTING\0" where the '\0' escape sequence denotes the
NULL character and where quotation marks are omitted. An example
string that could be sent to a device is "solution\0soln_freq\0". A
device will only respond to this message when it is received from
sender ID 0x42. A device should respond with a MSG_SETTINGS_READ_RESP
message (msg_id 0x00A5).


  """
  __slots__ = ['setting',
               ]
  @classmethod
  def parse_members(cls, buf, offset, length):
    ret = {}
    (__setting, offset, length) = get_setting(buf, offset, length)
    ret['setting'] = __setting
    return ret, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.setting = res['setting']
    return res, off, length

  @classmethod
  def _payload_size(self):
    ret = 0
    # setting: string
    ret += 247
    return ret
  
SBP_MSG_SETTINGS_READ_RESP = 0x00A5
class MsgSettingsReadResp(SBP):
  """SBP class for message MSG_SETTINGS_READ_RESP (0x00A5).

  You can have MSG_SETTINGS_READ_RESP inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  The setting message wich which the device responds after a
MSG_SETTING_READ_REQ is sent to device. The string field is a
NULL-terminated and NULL-delimited string with contents
"SECTION_SETTING\0SETTING\0VALUE\0" where the '\0' escape sequence
denotes the NULL character and where quotation marks are omitted. An
example string that could be sent from device is
"solution\0soln_freq\010\0".


  """
  __slots__ = ['setting',
               ]
  @classmethod
  def parse_members(cls, buf, offset, length):
    ret = {}
    (__setting, offset, length) = get_setting(buf, offset, length)
    ret['setting'] = __setting
    return ret, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.setting = res['setting']
    return res, off, length

  @classmethod
  def _payload_size(self):
    ret = 0
    # setting: string
    ret += 247
    return ret
  
SBP_MSG_SETTINGS_READ_BY_INDEX_REQ = 0x00A2
class MsgSettingsReadByIndexReq(SBP):
  """SBP class for message MSG_SETTINGS_READ_BY_INDEX_REQ (0x00A2).

  You can have MSG_SETTINGS_READ_BY_INDEX_REQ inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  The settings message for iterating through the settings
values. A device will respond to this message with a 
"MSG_SETTINGS_READ_BY_INDEX_RESP".


  """
  __slots__ = ['index',
               ]
  @classmethod
  def parse_members(cls, buf, offset, length):
    ret = {}
    (__index, offset, length) = get_u16(buf, offset, length)
    ret['index'] = __index
    return ret, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.index = res['index']
    return res, off, length

  @classmethod
  def _payload_size(self):
    ret = 0
    # index: u16
    ret += 2
    return ret
  
SBP_MSG_SETTINGS_READ_BY_INDEX_RESP = 0x00A7
class MsgSettingsReadByIndexResp(SBP):
  """SBP class for message MSG_SETTINGS_READ_BY_INDEX_RESP (0x00A7).

  You can have MSG_SETTINGS_READ_BY_INDEX_RESP inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  The settings message that reports the value of a setting at an index.

In the string field, it reports NULL-terminated and delimited string
with contents "SECTION_SETTING\0SETTING\0VALUE\0FORMAT_TYPE\0". where
the '\0' escape sequence denotes the NULL character and where quotation
marks are omitted. The FORMAT_TYPE field is optional and denotes
possible string values of the setting as a hint to the user. If
included, the format type portion of the string has the format
"enum:value1,value2,value3". An example string that could be sent from
the device is "simulator\0enabled\0True\0enum:True,False\0"


  """
  __slots__ = ['index',
               'setting',
               ]
  @classmethod
  def parse_members(cls, buf, offset, length):
    ret = {}
    (__index, offset, length) = get_u16(buf, offset, length)
    ret['index'] = __index
    (__setting, offset, length) = get_setting(buf, offset, length)
    ret['setting'] = __setting
    return ret, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.index = res['index']
    self.setting = res['setting']
    return res, off, length

  @classmethod
  def _payload_size(self):
    ret = 0
    # index: u16
    ret += 2
    # setting: string
    ret += 247
    return ret
  
SBP_MSG_SETTINGS_READ_BY_INDEX_DONE = 0x00A6
class MsgSettingsReadByIndexDone(SBP):
  """SBP class for message MSG_SETTINGS_READ_BY_INDEX_DONE (0x00A6).

  You can have MSG_SETTINGS_READ_BY_INDEX_DONE inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  The settings message for indicating end of the settings values.


  """
  __slots__ = []
  def _unpack_members(self, buf, offset, length):
    return {}, offset, length

  def _payload_size(self):
    return 0
  
SBP_MSG_SETTINGS_REGISTER = 0x00AE
class MsgSettingsRegister(SBP):
  """SBP class for message MSG_SETTINGS_REGISTER (0x00AE).

  You can have MSG_SETTINGS_REGISTER inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  This message registers the presence and default value of a setting
with a settings daemon.  The host should reply with MSG_SETTINGS_WRITE
for this setting to set the initial value.


  """
  __slots__ = ['setting',
               ]
  @classmethod
  def parse_members(cls, buf, offset, length):
    ret = {}
    (__setting, offset, length) = get_setting(buf, offset, length)
    ret['setting'] = __setting
    return ret, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.setting = res['setting']
    return res, off, length

  @classmethod
  def _payload_size(self):
    ret = 0
    # setting: string
    ret += 247
    return ret
  
SBP_MSG_SETTINGS_REGISTER_RESP = 0x01AF
class MsgSettingsRegisterResp(SBP):
  """SBP class for message MSG_SETTINGS_REGISTER_RESP (0x01AF).

  You can have MSG_SETTINGS_REGISTER_RESP inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  This message responds to setting registration with the effective value.
The effective value shall differ from the given default value if setting
was already registered or is available in the permanent setting storage
and had a different value.


  """
  __slots__ = ['status',
               'setting',
               ]
  @classmethod
  def parse_members(cls, buf, offset, length):
    ret = {}
    (__status, offset, length) = get_u8(buf, offset, length)
    ret['status'] = __status
    (__setting, offset, length) = get_setting(buf, offset, length)
    ret['setting'] = __setting
    return ret, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.status = res['status']
    self.setting = res['setting']
    return res, off, length

  @classmethod
  def _payload_size(self):
    ret = 0
    # status: u8
    ret += 1
    # setting: string
    ret += 247
    return ret
  

msg_classes = {
  0x00A1: MsgSettingsSave,
  0x00A0: MsgSettingsWrite,
  0x00AF: MsgSettingsWriteResp,
  0x00A4: MsgSettingsReadReq,
  0x00A5: MsgSettingsReadResp,
  0x00A2: MsgSettingsReadByIndexReq,
  0x00A7: MsgSettingsReadByIndexResp,
  0x00A6: MsgSettingsReadByIndexDone,
  0x00AE: MsgSettingsRegister,
  0x01AF: MsgSettingsRegisterResp,
}