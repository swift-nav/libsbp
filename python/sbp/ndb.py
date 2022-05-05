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
Messages for logging NDB events.
"""

import json

import construct

from sbp.msg import SBP, SENDER_ID
from sbp.utils import fmt_repr, exclude_fields, walk_json_dict, containerize
from sbp.gnss import GnssSignal

# Automatically generated from piksi/yaml/swiftnav/sbp/ndb.yaml with generate.py.
# Please do not hand edit!


SBP_MSG_NDB_EVENT = 0x0400
class MsgNdbEvent(SBP):
  """SBP class for message MSG_NDB_EVENT (0x0400).

  You can have MSG_NDB_EVENT inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  This message is sent out when an object is stored into NDB. If needed
  message could also be sent out when fetching an object from NDB.

  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  recv_time : int
    HW time in milliseconds.
  event : int
    Event type.
  object_type : int
    Event object type.
  result : int
    Event result.
  data_source : int
    Data source for STORE event, reserved for other events.
  object_sid : GnssSignal
    GNSS signal identifier, If object_type is Ephemeris OR Almanac, sid
    indicates for which signal the object belongs to. Reserved in other cases.
  src_sid : GnssSignal
    GNSS signal identifier, If object_type is Almanac, Almanac WN, Iono OR L2C
    capabilities AND data_source is NDB_DS_RECEIVER sid indicates from which
    SV data was decoded. Reserved in other cases.
  original_sender : int
    A unique identifier of the sending hardware. For v1.0, set to the 2 least
    significant bytes of the device serial number, valid only if data_source
    is NDB_DS_SBP. Reserved in case of other data_source.
  sender : int
    Optional sender ID, defaults to SENDER_ID (see sbp/msg.py).

  """
  _parser = construct.Struct(
                   'recv_time' / construct.Int64ul,
                   'event' / construct.Int8ul,
                   'object_type' / construct.Int8ul,
                   'result' / construct.Int8ul,
                   'data_source' / construct.Int8ul,
                   'object_sid' / GnssSignal._parser,
                   'src_sid' / GnssSignal._parser,
                   'original_sender' / construct.Int16ul,)
  __slots__ = [
               'recv_time',
               'event',
               'object_type',
               'result',
               'data_source',
               'object_sid',
               'src_sid',
               'original_sender',
              ]

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      super( MsgNdbEvent,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.from_binary(sbp.payload)
    else:
      super( MsgNdbEvent, self).__init__()
      self.msg_type = SBP_MSG_NDB_EVENT
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.recv_time = kwargs.pop('recv_time')
      self.event = kwargs.pop('event')
      self.object_type = kwargs.pop('object_type')
      self.result = kwargs.pop('result')
      self.data_source = kwargs.pop('data_source')
      self.object_sid = kwargs.pop('object_sid')
      self.src_sid = kwargs.pop('src_sid')
      self.original_sender = kwargs.pop('original_sender')

  def __repr__(self):
    return fmt_repr(self)

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    return MsgNdbEvent.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgNdbEvent(sbp, **d)

 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgNdbEvent._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgNdbEvent._parser.build(c)
    return self.pack()

  def into_buffer(self, buf, offset):
    """Produce a framed/packed SBP message into the provided buffer and offset.

    """
    self.payload = containerize(exclude_fields(self))
    self.parser = MsgNdbEvent._parser
    self.stream_payload.reset(buf, offset)
    return self.pack_into(buf, offset, self._build_payload)

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgNdbEvent, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    

msg_classes = {
  0x0400: MsgNdbEvent,
}