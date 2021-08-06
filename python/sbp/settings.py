#!/usr/bin/env python
# Copyright (C) 2015-2021 Swift Navigation Inc.
# Contact: https://support.swiftnav.com
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
SETTING are used to refer to the two strings that comprise the identifier of
an individual setting.In firmware_version example above, SECTION_SETTING is
the 'system_info', and the SETTING portion is 'firmware_version'.
See the "Software Settings Manual" on support.swiftnav.com for detailed
documentation about all settings and sections available for each Swift
firmware version. Settings manuals are available for each firmware version
at the following link:
https://support.swiftnav.com/support/solutions/articles/44001850753-piksi-multi-specification.
The latest settings document is also available at the following link:
http://swiftnav.com/latest/piksi-multi-settings . See lastly
https://github.com/swift-nav/piksi_tools/blob/master/piksi_tools/settings.py
, the open source python command line utility for reading, writing, and
saving settings in the piksi_tools repository on github as a helpful
reference and example.
"""

import json

import construct

from sbp.msg import SBP, SENDER_ID
from sbp.utils import fmt_repr, exclude_fields, walk_json_dict, containerize

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

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      super( MsgSettingsSave,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.payload = sbp.payload
    else:
      super( MsgSettingsSave, self).__init__()
      self.msg_type = SBP_MSG_SETTINGS_SAVE
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.payload = b""

  def __repr__(self):
    return fmt_repr(self)

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    return MsgSettingsSave.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgSettingsSave(sbp, **d)

 
    
SBP_MSG_SETTINGS_WRITE = 0x00A0
class MsgSettingsWrite(SBP):
  r"""SBP class for message MSG_SETTINGS_WRITE (0x00A0).

  You can have MSG_SETTINGS_WRITE inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  The setting message writes the device configuration for a particular setting
  via A NULL-terminated and NULL-delimited string with contents
  "SECTION_SETTING\0SETTING\0VALUE\0" where the '\0' escape sequence denotes
  the NULL character and where quotation marks are omitted. A device will only
  process to this message when it is received from sender ID 0x42. An example
  string that could be sent to a device is "solution\0soln_freq\010\0".

  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  setting : string
    A NULL-terminated and NULL-delimited string with contents
    "SECTION_SETTING\0SETTING\0VALUE\0"
  sender : int
    Optional sender ID, defaults to SENDER_ID (see sbp/msg.py).

  """
  _parser = construct.Struct(
                   'setting' / construct.GreedyBytes,)
  __slots__ = [
               'setting',
              ]

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      super( MsgSettingsWrite,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.from_binary(sbp.payload)
    else:
      super( MsgSettingsWrite, self).__init__()
      self.msg_type = SBP_MSG_SETTINGS_WRITE
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.setting = kwargs.pop('setting')

  def __repr__(self):
    return fmt_repr(self)

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    return MsgSettingsWrite.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgSettingsWrite(sbp, **d)

 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgSettingsWrite._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgSettingsWrite._parser.build(c)
    return self.pack()

  def into_buffer(self, buf, offset):
    """Produce a framed/packed SBP message into the provided buffer and offset.

    """
    self.payload = containerize(exclude_fields(self))
    self.parser = MsgSettingsWrite._parser
    self.stream_payload.reset(buf, offset)
    return self.pack_into(buf, offset, self._build_payload)

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgSettingsWrite, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    
SBP_MSG_SETTINGS_WRITE_RESP = 0x00AF
class MsgSettingsWriteResp(SBP):
  r"""SBP class for message MSG_SETTINGS_WRITE_RESP (0x00AF).

  You can have MSG_SETTINGS_WRITE_RESP inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  Return the status of a write request with the new value of the setting.  If
  the requested value is rejected, the current value will be returned. The
  string field is a NULL-terminated and NULL-delimited string with contents
  "SECTION_SETTING\0SETTING\0VALUE\0" where the '\0' escape sequence denotes
  the NULL character and where quotation marks are omitted. An example string
  that could be sent from device is "solution\0soln_freq\010\0".

  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  status : int
    Write status
  setting : string
    A NULL-terminated and delimited string with contents
    "SECTION_SETTING\0SETTING\0VALUE\0"
  sender : int
    Optional sender ID, defaults to SENDER_ID (see sbp/msg.py).

  """
  _parser = construct.Struct(
                   'status' / construct.Int8ul,
                   'setting' / construct.GreedyBytes,)
  __slots__ = [
               'status',
               'setting',
              ]

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      super( MsgSettingsWriteResp,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.from_binary(sbp.payload)
    else:
      super( MsgSettingsWriteResp, self).__init__()
      self.msg_type = SBP_MSG_SETTINGS_WRITE_RESP
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.status = kwargs.pop('status')
      self.setting = kwargs.pop('setting')

  def __repr__(self):
    return fmt_repr(self)

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    return MsgSettingsWriteResp.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgSettingsWriteResp(sbp, **d)

 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgSettingsWriteResp._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgSettingsWriteResp._parser.build(c)
    return self.pack()

  def into_buffer(self, buf, offset):
    """Produce a framed/packed SBP message into the provided buffer and offset.

    """
    self.payload = containerize(exclude_fields(self))
    self.parser = MsgSettingsWriteResp._parser
    self.stream_payload.reset(buf, offset)
    return self.pack_into(buf, offset, self._build_payload)

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgSettingsWriteResp, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    
SBP_MSG_SETTINGS_READ_REQ = 0x00A4
class MsgSettingsReadReq(SBP):
  r"""SBP class for message MSG_SETTINGS_READ_REQ (0x00A4).

  You can have MSG_SETTINGS_READ_REQ inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  The setting message that reads the device configuration. The string field is
  a NULL-terminated and NULL-delimited string with contents
  "SECTION_SETTING\0SETTING\0" where the '\0' escape sequence denotes the NULL
  character and where quotation marks are omitted. An example string that
  could be sent to a device is "solution\0soln_freq\0". A device will only
  respond to this message when it is received from sender ID 0x42. A device
  should respond with a MSG_SETTINGS_READ_RESP message (msg_id 0x00A5).

  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  setting : string
    A NULL-terminated and NULL-delimited string with contents
    "SECTION_SETTING\0SETTING\0"
  sender : int
    Optional sender ID, defaults to SENDER_ID (see sbp/msg.py).

  """
  _parser = construct.Struct(
                   'setting' / construct.GreedyBytes,)
  __slots__ = [
               'setting',
              ]

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      super( MsgSettingsReadReq,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.from_binary(sbp.payload)
    else:
      super( MsgSettingsReadReq, self).__init__()
      self.msg_type = SBP_MSG_SETTINGS_READ_REQ
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.setting = kwargs.pop('setting')

  def __repr__(self):
    return fmt_repr(self)

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    return MsgSettingsReadReq.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgSettingsReadReq(sbp, **d)

 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgSettingsReadReq._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgSettingsReadReq._parser.build(c)
    return self.pack()

  def into_buffer(self, buf, offset):
    """Produce a framed/packed SBP message into the provided buffer and offset.

    """
    self.payload = containerize(exclude_fields(self))
    self.parser = MsgSettingsReadReq._parser
    self.stream_payload.reset(buf, offset)
    return self.pack_into(buf, offset, self._build_payload)

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgSettingsReadReq, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    
SBP_MSG_SETTINGS_READ_RESP = 0x00A5
class MsgSettingsReadResp(SBP):
  r"""SBP class for message MSG_SETTINGS_READ_RESP (0x00A5).

  You can have MSG_SETTINGS_READ_RESP inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  The setting message with which the device responds after a
  MSG_SETTING_READ_REQ is sent to device. The string field is a NULL-
  terminated and NULL-delimited string with contents
  "SECTION_SETTING\0SETTING\0VALUE\0" where the '\0' escape sequence denotes
  the NULL character and where quotation marks are omitted. An example string
  that could be sent from device is "solution\0soln_freq\010\0".

  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  setting : string
    A NULL-terminated and NULL-delimited string with contents
    "SECTION_SETTING\0SETTING\0VALUE\0"
  sender : int
    Optional sender ID, defaults to SENDER_ID (see sbp/msg.py).

  """
  _parser = construct.Struct(
                   'setting' / construct.GreedyBytes,)
  __slots__ = [
               'setting',
              ]

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      super( MsgSettingsReadResp,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.from_binary(sbp.payload)
    else:
      super( MsgSettingsReadResp, self).__init__()
      self.msg_type = SBP_MSG_SETTINGS_READ_RESP
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.setting = kwargs.pop('setting')

  def __repr__(self):
    return fmt_repr(self)

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    return MsgSettingsReadResp.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgSettingsReadResp(sbp, **d)

 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgSettingsReadResp._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgSettingsReadResp._parser.build(c)
    return self.pack()

  def into_buffer(self, buf, offset):
    """Produce a framed/packed SBP message into the provided buffer and offset.

    """
    self.payload = containerize(exclude_fields(self))
    self.parser = MsgSettingsReadResp._parser
    self.stream_payload.reset(buf, offset)
    return self.pack_into(buf, offset, self._build_payload)

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgSettingsReadResp, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    
SBP_MSG_SETTINGS_READ_BY_INDEX_REQ = 0x00A2
class MsgSettingsReadByIndexReq(SBP):
  """SBP class for message MSG_SETTINGS_READ_BY_INDEX_REQ (0x00A2).

  You can have MSG_SETTINGS_READ_BY_INDEX_REQ inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  The settings message for iterating through the settings values. A device
  will respond to this message with a "MSG_SETTINGS_READ_BY_INDEX_RESP".

  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  index : int
    An index into the device settings, with values ranging from 0 to
    length(settings).
  sender : int
    Optional sender ID, defaults to SENDER_ID (see sbp/msg.py).

  """
  _parser = construct.Struct(
                   'index' / construct.Int16ul,)
  __slots__ = [
               'index',
              ]

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      super( MsgSettingsReadByIndexReq,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.from_binary(sbp.payload)
    else:
      super( MsgSettingsReadByIndexReq, self).__init__()
      self.msg_type = SBP_MSG_SETTINGS_READ_BY_INDEX_REQ
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.index = kwargs.pop('index')

  def __repr__(self):
    return fmt_repr(self)

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    return MsgSettingsReadByIndexReq.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgSettingsReadByIndexReq(sbp, **d)

 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgSettingsReadByIndexReq._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgSettingsReadByIndexReq._parser.build(c)
    return self.pack()

  def into_buffer(self, buf, offset):
    """Produce a framed/packed SBP message into the provided buffer and offset.

    """
    self.payload = containerize(exclude_fields(self))
    self.parser = MsgSettingsReadByIndexReq._parser
    self.stream_payload.reset(buf, offset)
    return self.pack_into(buf, offset, self._build_payload)

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgSettingsReadByIndexReq, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    
SBP_MSG_SETTINGS_READ_BY_INDEX_RESP = 0x00A7
class MsgSettingsReadByIndexResp(SBP):
  r"""SBP class for message MSG_SETTINGS_READ_BY_INDEX_RESP (0x00A7).

  You can have MSG_SETTINGS_READ_BY_INDEX_RESP inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  The settings message that reports the value of a setting at an index.

  In the string field, it reports NULL-terminated and delimited string with
  contents "SECTION_SETTING\0SETTING\0VALUE\0FORMAT_TYPE\0". where the '\0'
  escape sequence denotes the NULL character and where quotation marks are
  omitted. The FORMAT_TYPE field is optional and denotes possible string
  values of the setting as a hint to the user. If included, the format type
  portion of the string has the format "enum:value1,value2,value3". An example
  string that could be sent from the device is
  "simulator\0enabled\0True\0enum:True,False\0".

  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  index : int
    An index into the device settings, with values ranging from 0 to
    length(settings)
  setting : string
    A NULL-terminated and delimited string with contents
    "SECTION_SETTING\0SETTING\0VALUE\0FORMAT_TYPE\0"
  sender : int
    Optional sender ID, defaults to SENDER_ID (see sbp/msg.py).

  """
  _parser = construct.Struct(
                   'index' / construct.Int16ul,
                   'setting' / construct.GreedyBytes,)
  __slots__ = [
               'index',
               'setting',
              ]

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      super( MsgSettingsReadByIndexResp,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.from_binary(sbp.payload)
    else:
      super( MsgSettingsReadByIndexResp, self).__init__()
      self.msg_type = SBP_MSG_SETTINGS_READ_BY_INDEX_RESP
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.index = kwargs.pop('index')
      self.setting = kwargs.pop('setting')

  def __repr__(self):
    return fmt_repr(self)

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    return MsgSettingsReadByIndexResp.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgSettingsReadByIndexResp(sbp, **d)

 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgSettingsReadByIndexResp._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgSettingsReadByIndexResp._parser.build(c)
    return self.pack()

  def into_buffer(self, buf, offset):
    """Produce a framed/packed SBP message into the provided buffer and offset.

    """
    self.payload = containerize(exclude_fields(self))
    self.parser = MsgSettingsReadByIndexResp._parser
    self.stream_payload.reset(buf, offset)
    return self.pack_into(buf, offset, self._build_payload)

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgSettingsReadByIndexResp, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    
SBP_MSG_SETTINGS_READ_BY_INDEX_DONE = 0x00A6
class MsgSettingsReadByIndexDone(SBP):
  """SBP class for message MSG_SETTINGS_READ_BY_INDEX_DONE (0x00A6).

  You can have MSG_SETTINGS_READ_BY_INDEX_DONE inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  The settings message for indicating end of the settings values.

  """
  __slots__ = []

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      super( MsgSettingsReadByIndexDone,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.payload = sbp.payload
    else:
      super( MsgSettingsReadByIndexDone, self).__init__()
      self.msg_type = SBP_MSG_SETTINGS_READ_BY_INDEX_DONE
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.payload = b""

  def __repr__(self):
    return fmt_repr(self)

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    return MsgSettingsReadByIndexDone.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgSettingsReadByIndexDone(sbp, **d)

 
    
SBP_MSG_SETTINGS_REGISTER = 0x00AE
class MsgSettingsRegister(SBP):
  r"""SBP class for message MSG_SETTINGS_REGISTER (0x00AE).

  You can have MSG_SETTINGS_REGISTER inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  This message registers the presence and default value of a setting with a
  settings daemon.  The host should reply with MSG_SETTINGS_WRITE for this
  setting to set the initial value.

  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  setting : string
    A NULL-terminated and delimited string with contents
    "SECTION_SETTING\0SETTING\0VALUE".
  sender : int
    Optional sender ID, defaults to SENDER_ID (see sbp/msg.py).

  """
  _parser = construct.Struct(
                   'setting' / construct.GreedyBytes,)
  __slots__ = [
               'setting',
              ]

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      super( MsgSettingsRegister,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.from_binary(sbp.payload)
    else:
      super( MsgSettingsRegister, self).__init__()
      self.msg_type = SBP_MSG_SETTINGS_REGISTER
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.setting = kwargs.pop('setting')

  def __repr__(self):
    return fmt_repr(self)

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    return MsgSettingsRegister.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgSettingsRegister(sbp, **d)

 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgSettingsRegister._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgSettingsRegister._parser.build(c)
    return self.pack()

  def into_buffer(self, buf, offset):
    """Produce a framed/packed SBP message into the provided buffer and offset.

    """
    self.payload = containerize(exclude_fields(self))
    self.parser = MsgSettingsRegister._parser
    self.stream_payload.reset(buf, offset)
    return self.pack_into(buf, offset, self._build_payload)

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgSettingsRegister, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    
SBP_MSG_SETTINGS_REGISTER_RESP = 0x01AF
class MsgSettingsRegisterResp(SBP):
  r"""SBP class for message MSG_SETTINGS_REGISTER_RESP (0x01AF).

  You can have MSG_SETTINGS_REGISTER_RESP inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  This message responds to setting registration with the effective value. The
  effective value shall differ from the given default value if setting was
  already registered or is available in the permanent setting storage and had
  a different value.

  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  status : int
    Register status
  setting : string
    A NULL-terminated and delimited string with contents
    "SECTION_SETTING\0SETTING\0VALUE". The meaning of value is defined
    according to the status field.
  sender : int
    Optional sender ID, defaults to SENDER_ID (see sbp/msg.py).

  """
  _parser = construct.Struct(
                   'status' / construct.Int8ul,
                   'setting' / construct.GreedyBytes,)
  __slots__ = [
               'status',
               'setting',
              ]

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      super( MsgSettingsRegisterResp,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.from_binary(sbp.payload)
    else:
      super( MsgSettingsRegisterResp, self).__init__()
      self.msg_type = SBP_MSG_SETTINGS_REGISTER_RESP
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.status = kwargs.pop('status')
      self.setting = kwargs.pop('setting')

  def __repr__(self):
    return fmt_repr(self)

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    return MsgSettingsRegisterResp.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgSettingsRegisterResp(sbp, **d)

 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgSettingsRegisterResp._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgSettingsRegisterResp._parser.build(c)
    return self.pack()

  def into_buffer(self, buf, offset):
    """Produce a framed/packed SBP message into the provided buffer and offset.

    """
    self.payload = containerize(exclude_fields(self))
    self.parser = MsgSettingsRegisterResp._parser
    self.stream_payload.reset(buf, offset)
    return self.pack_into(buf, offset, self._build_payload)

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgSettingsRegisterResp, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    

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