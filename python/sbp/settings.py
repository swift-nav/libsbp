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

from construct import *
from sbp import SBP
from sbp.utils import fmt_repr
import six

# Automatically generated from piksi/yaml/swiftnav/sbp/settings.yaml
# with generate.py at 2015-04-06 23:40:11.129530. Please do not hand edit!


SBP_MSG_SETTINGS = 0x00A0
class MsgSettings(SBP):
  """SBP class for message MSG_SETTINGS (0x00A0).
  
  The setting message reads and writes the Piksi's configuration.


  Parameters
  ----------
  setting : string
    A NULL delimited (and terminated) string, with a single
"<setting section>\0<setting>\0<value>\0" on writes or a
series of "<setting section>\0<setting>\0<value>\0" on
reads.


  """
  _parser = Struct("MsgSettings",
                   CString('setting', six.b('\n')),)

  def __init__(self, sbp):
    self.__dict__.update(sbp.__dict__)
    self.from_binary(sbp.payload)

  def __repr__(self):
    return fmt_repr(self)
 
  def from_binary(self, d):
    p = MsgSettings._parser.parse(d)
    self.__dict__.update(dict(p.viewitems()))

  def to_binary(self):
    return MsgSettings.build(self.__dict__)
    
SBP_MSG_SETTINGS_SAVE = 0x00A1
class MsgSettingsSave(SBP):
  """SBP class for message MSG_SETTINGS_SAVE (0x00A1).
  
  The save settings message persists the Piksi's current settings
configuration to its onboard flash memory file system.


  """

  def __init__(self, sbp):
    self.__dict__.update(sbp.__dict__)
    self.payload = sbp.payload

  def __repr__(self):
    return fmt_repr(self)
 
    
SBP_MSG_SETTINGS_READ_BY_INDEX = 0x00A2
class MsgSettingsReadByIndex(SBP):
  """SBP class for message MSG_SETTINGS_READ_BY_INDEX (0x00A2).
  
  The settings message for iterating through the settings
values. It will read the setting at an index, returning
"<setting section>\0<setting>\0<value>\0" from the Piksi.


  Parameters
  ----------
  index : int
    An index into the Piksi settings, with values ranging from
0 to length(settings).


  """
  _parser = Struct("MsgSettingsReadByIndex",
                   ULInt16('index'),)

  def __init__(self, sbp):
    self.__dict__.update(sbp.__dict__)
    self.from_binary(sbp.payload)

  def __repr__(self):
    return fmt_repr(self)
 
  def from_binary(self, d):
    p = MsgSettingsReadByIndex._parser.parse(d)
    self.__dict__.update(dict(p.viewitems()))

  def to_binary(self):
    return MsgSettingsReadByIndex.build(self.__dict__)
    

msg_classes = {
  0x00A0: MsgSettings,
  0x00A1: MsgSettingsSave,
  0x00A2: MsgSettingsReadByIndex,
}