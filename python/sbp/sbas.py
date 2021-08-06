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
SBAS data
"""

import json

import construct

from sbp.msg import SBP, SENDER_ID
from sbp.utils import fmt_repr, exclude_fields, walk_json_dict, containerize
from sbp.gnss import GnssSignal

# Automatically generated from piksi/yaml/swiftnav/sbp/sbas.yaml with generate.py.
# Please do not hand edit!


SBP_MSG_SBAS_RAW = 0x7777
class MsgSbasRaw(SBP):
  """SBP class for message MSG_SBAS_RAW (0x7777).

  You can have MSG_SBAS_RAW inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  This message is sent once per second per SBAS satellite. ME checks the
  parity of the data block and sends only blocks that pass the check.

  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  sid : GnssSignal
    GNSS signal identifier.
  tow : int
    GPS time-of-week at the start of the data block.
  message_type : int
    SBAS message type (0-63)
  data : array
    Raw SBAS data field of 212 bits (last byte padded with zeros).
  sender : int
    Optional sender ID, defaults to SENDER_ID (see sbp/msg.py).

  """
  _parser = construct.Struct(
                   'sid' / GnssSignal._parser,
                   'tow' / construct.Int32ul,
                   'message_type' / construct.Int8ul,
                   'data' / construct.Array(27, construct.Int8ul),)
  __slots__ = [
               'sid',
               'tow',
               'message_type',
               'data',
              ]

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      super( MsgSbasRaw,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.from_binary(sbp.payload)
    else:
      super( MsgSbasRaw, self).__init__()
      self.msg_type = SBP_MSG_SBAS_RAW
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.sid = kwargs.pop('sid')
      self.tow = kwargs.pop('tow')
      self.message_type = kwargs.pop('message_type')
      self.data = kwargs.pop('data')

  def __repr__(self):
    return fmt_repr(self)

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    return MsgSbasRaw.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgSbasRaw(sbp, **d)

 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgSbasRaw._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgSbasRaw._parser.build(c)
    return self.pack()

  def into_buffer(self, buf, offset):
    """Produce a framed/packed SBP message into the provided buffer and offset.

    """
    self.payload = containerize(exclude_fields(self))
    self.parser = MsgSbasRaw._parser
    self.stream_payload.reset(buf, offset)
    return self.pack_into(buf, offset, self._build_payload)

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgSbasRaw, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    

msg_classes = {
  0x7777: MsgSbasRaw,
}