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
Messages reserved for use by the user.

"""

from construct import *
import json
from sbp.msg import SBP, SENDER_ID
from sbp.utils import fmt_repr, exclude_fields, walk_json_dict, containerize, greedy_string

# Automatically generated from piksi/yaml/swiftnav/sbp/user.yaml with generate.py.
# Please do not hand edit!


SBP_MSG_USER_DATA = 0x0800
class MsgUserData(SBP):
  """SBP class for message MSG_USER_DATA (0x0800).

  You can have MSG_USER_DATA inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  This message can contain any application specific user data up to a
maximum length of 255 bytes per message.


  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  contents : array
    User data payload
  sender : int
    Optional sender ID, defaults to SENDER_ID (see sbp/msg.py).

  """
  _parser = Struct("MsgUserData",
                   OptionalGreedyRange(ULInt8('contents')),)
  __slots__ = [
               'contents',
              ]

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      super( MsgUserData,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.from_binary(sbp.payload)
    else:
      super( MsgUserData, self).__init__()
      self.msg_type = SBP_MSG_USER_DATA
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.contents = kwargs.pop('contents')

  def __repr__(self):
    return fmt_repr(self)

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    return MsgUserData.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgUserData(sbp, **d)

 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgUserData._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgUserData._parser.build(c)
    return self.pack()

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgUserData, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    

msg_classes = {
  0x0800: MsgUserData,
}