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
Standardized system messages from Swift Navigation devices.
"""

from construct import *
import json
from sbp import SBP
from sbp.utils import fmt_repr, exclude_fields, walk_json_dict
import six

# Automatically generated from piksi/yaml/swiftnav/sbp/system.yaml
# with generate.py at 2015-04-14 12:12:07.028810. Please do not hand edit!


SBP_MSG_STARTUP = 0xFF00
class MsgStartup(SBP):
  """SBP class for message MSG_STARTUP (0xFF00).

  You can have MSG_STARTUP inherent its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  The system start-up message is sent once on system
start-up. It is intended to be used to notify the host or
other attached devices that the system has started and is now
ready to respond to commands or configuration requests.


  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  reserved : int
    Reserved

  """
  _parser = Struct("MsgStartup",
                   ULInt32('reserved'),)

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      self.__dict__.update(sbp.__dict__)
      self.from_binary(sbp.payload)
    else:
      self.reserved = kwargs.pop('reserved')

  def __repr__(self):
    return fmt_repr(self)
 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgStartup._parser.parse(d)
    self.__dict__.update(dict(p.viewitems()))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = Container(**exclude_fields(self))
    self.payload = MsgStartup._parser.build(c)
    return self.pack()

  def to_json(self):
    """Produce a JSON-encoded SBP message.

    """
    d = super( MsgStartup, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return json.dumps(d)

  @staticmethod
  def from_json(data):
    """Given a JSON-encoded message, build an object.

    """
    d = json.loads(data)
    sbp = SBP.from_json_dict(d)
    return MsgStartup(sbp)
    
SBP_MSG_HEARTBEAT = 0xFFFF
class MsgHeartbeat(SBP):
  """SBP class for message MSG_HEARTBEAT (0xFFFF).

  You can have MSG_HEARTBEAT inherent its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  The heartbeat message is sent periodically to inform the host
or other attached devices that the system is running. It is
intended to be used to monitor for system malfunctions and
also contains status flags that indicate to the host the
status of the system and if it is operating correctly.

The system error flag is used to indicate that an error has
occurred in the system. To determine the source of the error
the remaining error flags should be inspected.


  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  flags : int
    Status flags

  """
  _parser = Struct("MsgHeartbeat",
                   ULInt32('flags'),)

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      self.__dict__.update(sbp.__dict__)
      self.from_binary(sbp.payload)
    else:
      self.flags = kwargs.pop('flags')

  def __repr__(self):
    return fmt_repr(self)
 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgHeartbeat._parser.parse(d)
    self.__dict__.update(dict(p.viewitems()))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = Container(**exclude_fields(self))
    self.payload = MsgHeartbeat._parser.build(c)
    return self.pack()

  def to_json(self):
    """Produce a JSON-encoded SBP message.

    """
    d = super( MsgHeartbeat, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return json.dumps(d)

  @staticmethod
  def from_json(data):
    """Given a JSON-encoded message, build an object.

    """
    d = json.loads(data)
    sbp = SBP.from_json_dict(d)
    return MsgHeartbeat(sbp)
    

msg_classes = {
  0xFF00: MsgStartup,
  0xFFFF: MsgHeartbeat,
}