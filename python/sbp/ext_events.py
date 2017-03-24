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
Messages reporting accurately-timestamped external events,
e.g. camera shutter time.

"""

from construct import *
import json
from sbp.msg import SBP, SENDER_ID
from sbp.utils import fmt_repr, exclude_fields, walk_json_dict, containerize, greedy_string

# Automatically generated from piksi/yaml/swiftnav/sbp/ext_events.yaml with generate.py.
# Please do not hand edit!


SBP_MSG_EXT_EVENT = 0x0101
class MsgExtEvent(SBP):
  """SBP class for message MSG_EXT_EVENT (0x0101).

  You can have MSG_EXT_EVENT inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  Reports detection of an external event, the GPS time it occurred,
which pin it was and whether it was rising or falling.


  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  wn : int
    GPS week number
  tow : int
    GPS time of week rounded to the nearest millisecond
  ns_residual : int
    Nanosecond residual of millisecond-rounded TOW (ranges
from -500000 to 500000)

  flags : int
    Flags
  pin : int
    Pin number.  0..9 = DEBUG0..9.
  sender : int
    Optional sender ID, defaults to SENDER_ID (see sbp/msg.py).

  """
  _parser = Struct("MsgExtEvent",
                   ULInt16('wn'),
                   ULInt32('tow'),
                   SLInt32('ns_residual'),
                   ULInt8('flags'),
                   ULInt8('pin'),)
  __slots__ = [
               'wn',
               'tow',
               'ns_residual',
               'flags',
               'pin',
              ]

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      super( MsgExtEvent,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.from_binary(sbp.payload)
    else:
      super( MsgExtEvent, self).__init__()
      self.msg_type = SBP_MSG_EXT_EVENT
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.wn = kwargs.pop('wn')
      self.tow = kwargs.pop('tow')
      self.ns_residual = kwargs.pop('ns_residual')
      self.flags = kwargs.pop('flags')
      self.pin = kwargs.pop('pin')

  def __repr__(self):
    return fmt_repr(self)

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    return MsgExtEvent.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgExtEvent(sbp, **d)

 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgExtEvent._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgExtEvent._parser.build(c)
    return self.pack()

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgExtEvent, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    

msg_classes = {
  0x0101: MsgExtEvent,
}