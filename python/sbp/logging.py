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
Logging and debugging messages from the device. These are in the
implementation-defined range (0x0000-0x00FF).

"""

from construct import *
import json
from sbp.msg import SBP
from sbp.utils import fmt_repr, exclude_fields, walk_json_dict, containerize
import six

# Automatically generated from piksi/yaml/swiftnav/sbp/logging.yaml with generate.py.
# Please do not hand edit!


SBP_MSG_PRINT = 0x0010
class MsgPrint(SBP):
  """SBP class for message MSG_PRINT (0x0010).

  You can have MSG_PRINT inherent its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  This message contains a human-readable payload string from the
device containing errors, warnings and informational messages at
ERROR, WARNING, DEBUG, INFO logging levels.


  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  text : string
    Human-readable string
  sender : int
    Optional sender ID, defaults to 0

  """
  _parser = Struct("MsgPrint",
                   CString('text', six.b('\n')),)

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      self.__dict__.update(sbp.__dict__)
      self.from_binary(sbp.payload)
    else:
      super( MsgPrint, self).__init__()
      self.msg_type = SBP_MSG_PRINT
      self.sender = kwargs.pop('sender', 0)
      self.text = kwargs.pop('text')

  def __repr__(self):
    return fmt_repr(self)
 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgPrint._parser.parse(d)
    self.__dict__.update(dict(p.viewitems()))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgPrint._parser.build(c)
    return self.pack()

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    sbp = SBP.from_json_dict(d)
    return MsgPrint(sbp)

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgPrint, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    
SBP_MSG_DEBUG_VAR = 0x0011
class MsgDebugVar(SBP):
  """SBP class for message MSG_DEBUG_VAR (0x0011).

  You can have MSG_DEBUG_VAR inherent its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  This is an unused legacy message for tracing variable values
within the device firmware and streaming those back to the host.


  """

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      self.__dict__.update(sbp.__dict__)
      self.payload = sbp.payload
    else:
      super( MsgDebugVar, self).__init__()
      self.msg_type = SBP_MSG_DEBUG_VAR
      self.sender = kwargs.pop('sender', 0)

  def __repr__(self):
    return fmt_repr(self)
 
    
SBP_MSG_TWEET = 0x0012
class MsgTweet(SBP):
  """SBP class for message MSG_TWEET (0x0012).

  You can have MSG_TWEET inherent its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  All the news fit to tweet.

  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  tweet : string
    Human-readable string
  sender : int
    Optional sender ID, defaults to 0

  """
  _parser = Struct("MsgTweet",
                   String('tweet', 140),)

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      self.__dict__.update(sbp.__dict__)
      self.from_binary(sbp.payload)
    else:
      super( MsgTweet, self).__init__()
      self.msg_type = SBP_MSG_TWEET
      self.sender = kwargs.pop('sender', 0)
      self.tweet = kwargs.pop('tweet')

  def __repr__(self):
    return fmt_repr(self)
 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgTweet._parser.parse(d)
    self.__dict__.update(dict(p.viewitems()))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgTweet._parser.build(c)
    return self.pack()

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    sbp = SBP.from_json_dict(d)
    return MsgTweet(sbp)

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgTweet, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    

msg_classes = {
  0x0010: MsgPrint,
  0x0011: MsgDebugVar,
  0x0012: MsgTweet,
}