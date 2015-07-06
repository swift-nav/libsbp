#!/usr/bin/env python
# Copyright (C) 2015 Swift Navigation Inc.
# Contact: Fergus Noble <fergus@swiftnav.com>
#
# This source is subject to the license found in the file 'LICENSE' which must
# be be distributed together with this source. All other rights reserved.
#
# THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
# EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
# WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.


"""
Messages for reading and writing the device's device settings.

These are in the implementation-defined range (0x0000-0x00FF). Note
that some of these messages share the same message type ID for both
the host request and the device response. See the accompanying
document for descriptions of settings configurations and examples:
https://github.com/swift-nav/piksi\_firmware/blob/master/docs/settings.pdf

"""

from construct import *
import json
from sbp.msg import SBP, SENDER_ID
from sbp.utils import fmt_repr, exclude_fields, walk_json_dict, containerize
import six

# Automatically generated from piksi/yaml/swiftnav/sbp/settings.yaml with generate.py.
# Please do not hand edit!


SBP_MSG_SETTINGS_SAVE = 0x00A1
class MsgSettingsSave(SBP):
  """SBP class for message MSG_SETTINGS_SAVE (0x00A1).

  You can have MSG_SETTINGS_SAVE inherent its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  The save settings message persists the device's current settings
configuration to its onboard flash memory file system.


  """

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      self.__dict__.update(sbp.__dict__)
      self.payload = sbp.payload
    else:
      super( MsgSettingsSave, self).__init__()
      self.msg_type = SBP_MSG_SETTINGS_SAVE
      self.sender = kwargs.pop('sender', SENDER_ID)

  def __repr__(self):
    return fmt_repr(self)
 
    
SBP_MSG_SETTINGS_WRITE = 0x00A0
class MsgSettingsWrite(SBP):
  """SBP class for message MSG_SETTINGS_WRITE (0x00A0).

  You can have MSG_SETTINGS_WRITE inherent its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  The setting message writes the device's configuration.

  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  setting : string
    A NULL-terminated and delimited string with contents
[SECTION_SETTING, SETTING, VALUE].

  sender : int
    Optional sender ID, defaults to SENDER_ID (see sbp/msg.py).

  """
  _parser = Struct("MsgSettingsWrite",
                   CString('setting', six.b('\n')),)

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      self.__dict__.update(sbp.__dict__)
      self.from_binary(sbp.payload)
    else:
      super( MsgSettingsWrite, self).__init__()
      self.msg_type = SBP_MSG_SETTINGS_WRITE
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.setting = kwargs.pop('setting')

  def __repr__(self):
    return fmt_repr(self)
 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgSettingsWrite._parser.parse(d)
    self.__dict__.update(dict(p.viewitems()))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgSettingsWrite._parser.build(c)
    return self.pack()

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    sbp = SBP.from_json_dict(d)
    return MsgSettingsWrite(sbp)

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgSettingsWrite, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    
SBP_MSG_SETTINGS_READ_REQUEST = 0x00A4
class MsgSettingsReadRequest(SBP):
  """SBP class for message MSG_SETTINGS_READ_REQUEST (0x00A4).

  You can have MSG_SETTINGS_READ_REQUEST inherent its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  The setting message reads the device's configuration.

  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  setting : string
    A NULL-terminated and delimited string with contents
[SECTION_SETTING, SETTING].

  sender : int
    Optional sender ID, defaults to SENDER_ID (see sbp/msg.py).

  """
  _parser = Struct("MsgSettingsReadRequest",
                   CString('setting', six.b('\n')),)

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      self.__dict__.update(sbp.__dict__)
      self.from_binary(sbp.payload)
    else:
      super( MsgSettingsReadRequest, self).__init__()
      self.msg_type = SBP_MSG_SETTINGS_READ_REQUEST
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.setting = kwargs.pop('setting')

  def __repr__(self):
    return fmt_repr(self)
 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgSettingsReadRequest._parser.parse(d)
    self.__dict__.update(dict(p.viewitems()))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgSettingsReadRequest._parser.build(c)
    return self.pack()

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    sbp = SBP.from_json_dict(d)
    return MsgSettingsReadRequest(sbp)

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgSettingsReadRequest, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    
SBP_MSG_SETTINGS_READ_RESPONSE = 0x00A5
class MsgSettingsReadResponse(SBP):
  """SBP class for message MSG_SETTINGS_READ_RESPONSE (0x00A5).

  You can have MSG_SETTINGS_READ_RESPONSE inherent its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  The setting message reads the device's configuration.

  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  setting : string
    A NULL-terminated and delimited string with contents
[SECTION_SETTING, SETTING, VALUE].

  sender : int
    Optional sender ID, defaults to SENDER_ID (see sbp/msg.py).

  """
  _parser = Struct("MsgSettingsReadResponse",
                   CString('setting', six.b('\n')),)

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      self.__dict__.update(sbp.__dict__)
      self.from_binary(sbp.payload)
    else:
      super( MsgSettingsReadResponse, self).__init__()
      self.msg_type = SBP_MSG_SETTINGS_READ_RESPONSE
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.setting = kwargs.pop('setting')

  def __repr__(self):
    return fmt_repr(self)
 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgSettingsReadResponse._parser.parse(d)
    self.__dict__.update(dict(p.viewitems()))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgSettingsReadResponse._parser.build(c)
    return self.pack()

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    sbp = SBP.from_json_dict(d)
    return MsgSettingsReadResponse(sbp)

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgSettingsReadResponse, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    
SBP_MSG_SETTINGS_READ_BY_INDEX_REQUEST = 0x00A2
class MsgSettingsReadByIndexRequest(SBP):
  """SBP class for message MSG_SETTINGS_READ_BY_INDEX_REQUEST (0x00A2).

  You can have MSG_SETTINGS_READ_BY_INDEX_REQUEST inherent its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  The settings message for iterating through the settings
values. It will read the setting at an index, returning a
NULL-terminated and delimited string with contents
[SECTION_SETTING, SETTING, VALUE].


  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  index : int
    An index into the device settings, with values ranging from
0 to length(settings)

  sender : int
    Optional sender ID, defaults to SENDER_ID (see sbp/msg.py).

  """
  _parser = Struct("MsgSettingsReadByIndexRequest",
                   ULInt16('index'),)

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      self.__dict__.update(sbp.__dict__)
      self.from_binary(sbp.payload)
    else:
      super( MsgSettingsReadByIndexRequest, self).__init__()
      self.msg_type = SBP_MSG_SETTINGS_READ_BY_INDEX_REQUEST
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.index = kwargs.pop('index')

  def __repr__(self):
    return fmt_repr(self)
 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgSettingsReadByIndexRequest._parser.parse(d)
    self.__dict__.update(dict(p.viewitems()))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgSettingsReadByIndexRequest._parser.build(c)
    return self.pack()

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    sbp = SBP.from_json_dict(d)
    return MsgSettingsReadByIndexRequest(sbp)

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgSettingsReadByIndexRequest, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    
SBP_MSG_SETTINGS_READ_BY_INDEX_RESPONSE = 0x00A7
class MsgSettingsReadByIndexResponse(SBP):
  """SBP class for message MSG_SETTINGS_READ_BY_INDEX_RESPONSE (0x00A7).

  You can have MSG_SETTINGS_READ_BY_INDEX_RESPONSE inherent its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  The settings message for iterating through the settings
values. It will read the setting at an index, returning a
NULL-terminated and delimited string with contents
[SECTION_SETTING, SETTING, VALUE].


  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  index : int
    An index into the device settings, with values ranging from
0 to length(settings)

  setting : string
    A NULL-terminated and delimited string with contents
[SECTION_SETTING, SETTING, VALUE].

  sender : int
    Optional sender ID, defaults to SENDER_ID (see sbp/msg.py).

  """
  _parser = Struct("MsgSettingsReadByIndexResponse",
                   ULInt16('index'),
                   CString('setting', six.b('\n')),)

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      self.__dict__.update(sbp.__dict__)
      self.from_binary(sbp.payload)
    else:
      super( MsgSettingsReadByIndexResponse, self).__init__()
      self.msg_type = SBP_MSG_SETTINGS_READ_BY_INDEX_RESPONSE
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.index = kwargs.pop('index')
      self.setting = kwargs.pop('setting')

  def __repr__(self):
    return fmt_repr(self)
 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgSettingsReadByIndexResponse._parser.parse(d)
    self.__dict__.update(dict(p.viewitems()))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgSettingsReadByIndexResponse._parser.build(c)
    return self.pack()

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    sbp = SBP.from_json_dict(d)
    return MsgSettingsReadByIndexResponse(sbp)

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgSettingsReadByIndexResponse, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    
SBP_MSG_SETTINGS_READ_BY_INDEX_DONE = 0x00A6
class MsgSettingsReadByIndexDone(SBP):
  """SBP class for message MSG_SETTINGS_READ_BY_INDEX_DONE (0x00A6).

  You can have MSG_SETTINGS_READ_BY_INDEX_DONE inherent its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  The settings message for indicating end of the settings values.


  """

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      self.__dict__.update(sbp.__dict__)
      self.payload = sbp.payload
    else:
      super( MsgSettingsReadByIndexDone, self).__init__()
      self.msg_type = SBP_MSG_SETTINGS_READ_BY_INDEX_DONE
      self.sender = kwargs.pop('sender', SENDER_ID)

  def __repr__(self):
    return fmt_repr(self)
 
    

msg_classes = {
  0x00A1: MsgSettingsSave,
  0x00A0: MsgSettingsWrite,
  0x00A4: MsgSettingsReadRequest,
  0x00A5: MsgSettingsReadResponse,
  0x00A2: MsgSettingsReadByIndexRequest,
  0x00A7: MsgSettingsReadByIndexResponse,
  0x00A6: MsgSettingsReadByIndexDone,
}