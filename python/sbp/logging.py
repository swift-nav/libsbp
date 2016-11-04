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
Logging and debugging messages from the device.

"""

from construct import *
import json
from sbp.msg import SBP, SENDER_ID
from sbp.utils import fmt_repr, exclude_fields, walk_json_dict, containerize, greedy_string

# Automatically generated from piksi/yaml/swiftnav/sbp/logging.yaml with generate.py.
# Please do not hand edit!


SBP_MSG_LOG = 0x0401
class MsgLog(SBP):
  """SBP class for message MSG_LOG (0x0401).

  You can have MSG_LOG inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  This message contains a human-readable payload string from the
device containing errors, warnings and informational messages at
ERROR, WARNING, DEBUG, INFO logging levels.


  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  level : int
    Logging level
  text : string
    Human-readable string
  sender : int
    Optional sender ID, defaults to SENDER_ID (see sbp/msg.py).

  """
  _parser = Struct("MsgLog",
                   ULInt8('level'),
                   greedy_string('text'),)
  __slots__ = [
               'level',
               'text',
              ]

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      super( MsgLog,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.from_binary(sbp.payload)
    else:
      super( MsgLog, self).__init__()
      self.msg_type = SBP_MSG_LOG
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.level = kwargs.pop('level')
      self.text = kwargs.pop('text')

  def __repr__(self):
    return fmt_repr(self)

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    return MsgLog.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgLog(sbp, **d)

 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgLog._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgLog._parser.build(c)
    return self.pack()

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgLog, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    
SBP_MSG_FWD = 0x0402
class MsgFwd(SBP):
  """SBP class for message MSG_FWD (0x0402).

  You can have MSG_FWD inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  This message provides the ability to forward messages over SBP.  This may take the form
of wrapping up SBP messages received by Piksi for logging purposes or wrapping 
another protocol with SBP.

The source identifier indicates from what interface a forwarded stream derived.
The protocol identifier identifies what the expected protocol the forwarded msg contains.
Protocol 0 represents SBP and the remaining values are implementation defined.


  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  source : int
    source identifier
  protocol : int
    protocol identifier
  fwd_payload : string
    variable length wrapped binary message
  sender : int
    Optional sender ID, defaults to SENDER_ID (see sbp/msg.py).

  """
  _parser = Struct("MsgFwd",
                   ULInt8('source'),
                   ULInt8('protocol'),
                   greedy_string('fwd_payload'),)
  __slots__ = [
               'source',
               'protocol',
               'fwd_payload',
              ]

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      super( MsgFwd,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.from_binary(sbp.payload)
    else:
      super( MsgFwd, self).__init__()
      self.msg_type = SBP_MSG_FWD
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.source = kwargs.pop('source')
      self.protocol = kwargs.pop('protocol')
      self.fwd_payload = kwargs.pop('fwd_payload')

  def __repr__(self):
    return fmt_repr(self)

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    return MsgFwd.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgFwd(sbp, **d)

 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgFwd._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgFwd._parser.build(c)
    return self.pack()

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgFwd, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    
SBP_MSG_TWEET = 0x0012
class MsgTweet(SBP):
  """SBP class for message MSG_TWEET (0x0012).

  You can have MSG_TWEET inherit its fields directly
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
    Optional sender ID, defaults to SENDER_ID (see sbp/msg.py).

  """
  _parser = Struct("MsgTweet",
                   String('tweet', 140),)
  __slots__ = [
               'tweet',
              ]

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      super( MsgTweet,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.from_binary(sbp.payload)
    else:
      super( MsgTweet, self).__init__()
      self.msg_type = SBP_MSG_TWEET
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.tweet = kwargs.pop('tweet')

  def __repr__(self):
    return fmt_repr(self)

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    return MsgTweet.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgTweet(sbp, **d)

 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgTweet._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgTweet._parser.build(c)
    return self.pack()

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgTweet, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    
SBP_MSG_PRINT_DEP = 0x0010
class MsgPrintDep(SBP):
  """SBP class for message MSG_PRINT_DEP (0x0010).

  You can have MSG_PRINT_DEP inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  Deprecated.

  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  text : string
    Human-readable string
  sender : int
    Optional sender ID, defaults to SENDER_ID (see sbp/msg.py).

  """
  _parser = Struct("MsgPrintDep",
                   greedy_string('text'),)
  __slots__ = [
               'text',
              ]

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      super( MsgPrintDep,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.from_binary(sbp.payload)
    else:
      super( MsgPrintDep, self).__init__()
      self.msg_type = SBP_MSG_PRINT_DEP
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.text = kwargs.pop('text')

  def __repr__(self):
    return fmt_repr(self)

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    return MsgPrintDep.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgPrintDep(sbp, **d)

 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgPrintDep._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgPrintDep._parser.build(c)
    return self.pack()

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgPrintDep, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    

msg_classes = {
  0x0401: MsgLog,
  0x0402: MsgFwd,
  0x0012: MsgTweet,
  0x0010: MsgPrintDep,
}