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
from sbp.msg import SBP
from sbp.utils import fmt_repr, exclude_fields, walk_json_dict, containerize
import six

# Automatically generated from piksi/yaml/swiftnav/sbp/settings.yaml with generate.py.
# Please do not hand edit!


SBP_MSG_SETTINGS = 0x00A0
class MsgSettings(SBP):
  """SBP class for message MSG_SETTINGS (0x00A0).

  You can have MSG_SETTINGS inherent its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  The setting message reads and writes the device's configuration.


  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  setting : string
    A NULL-terminated and delimited string with contents
[SECTION_SETTING, SETTING, VALUE] on writes or a series of
such strings on reads.

  sender : int
    Optional sender ID, defaults to 0

  """
  _parser = Struct("MsgSettings",
                   CString('setting', six.b('\n')),)

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      self.__dict__.update(sbp.__dict__)
      self.from_binary(sbp.payload)
    else:
      super( MsgSettings, self).__init__()
      self.msg_type = SBP_MSG_SETTINGS
      self.sender = kwargs.pop('sender', 0)
      self.setting = kwargs.pop('setting')

  def __repr__(self):
    return fmt_repr(self)
 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgSettings._parser.parse(d)
    self.__dict__.update(dict(p.viewitems()))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgSettings._parser.build(c)
    return self.pack()

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    sbp = SBP.from_json_dict(d)
    return MsgSettings(sbp)

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgSettings, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    
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
      self.sender = kwargs.pop('sender', 0)

  def __repr__(self):
    return fmt_repr(self)
 
    
SBP_MSG_SETTINGS_READ_BY_INDEX = 0x00A2
class MsgSettingsReadByIndex(SBP):
  """SBP class for message MSG_SETTINGS_READ_BY_INDEX (0x00A2).

  You can have MSG_SETTINGS_READ_BY_INDEX inherent its fields directly
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
    Optional sender ID, defaults to 0

  """
  _parser = Struct("MsgSettingsReadByIndex",
                   ULInt16('index'),)

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      self.__dict__.update(sbp.__dict__)
      self.from_binary(sbp.payload)
    else:
      super( MsgSettingsReadByIndex, self).__init__()
      self.msg_type = SBP_MSG_SETTINGS_READ_BY_INDEX
      self.sender = kwargs.pop('sender', 0)
      self.index = kwargs.pop('index')

  def __repr__(self):
    return fmt_repr(self)
 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgSettingsReadByIndex._parser.parse(d)
    self.__dict__.update(dict(p.viewitems()))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgSettingsReadByIndex._parser.build(c)
    return self.pack()

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    sbp = SBP.from_json_dict(d)
    return MsgSettingsReadByIndex(sbp)

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgSettingsReadByIndex, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    

msg_classes = {
  0x00A0: MsgSettings,
  0x00A1: MsgSettingsSave,
  0x00A2: MsgSettingsReadByIndex,
}