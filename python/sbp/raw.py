#!/usr/bin/env python
# Copyright (C) 2015-2018 Swift Navigation Inc.
# Contact: Swift Navigation <dev@swiftnav.com>
#
# This source is subject to the license found in the file 'LICENSE' which must
# be be distributed together with this source. All other rights reserved.
#
# THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
# EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
# WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.


"""
Raw GNSS navigation data
"""

import json

import construct

from sbp.msg import SBP, SENDER_ID
from sbp.utils import fmt_repr, exclude_fields, walk_json_dict, containerize
from sbp.gnss import *

# Automatically generated from piksi/yaml/swiftnav/sbp/raw.yaml with generate.py.
# Please do not hand edit!


SBP_MSG_GPS_L1CA_RAW = 0x7778
class MsgGPSL1CaRaw(SBP):
  """SBP class for message MSG_GPS_L1CA_RAW (0x7778).

  You can have MSG_GPS_L1CA_RAW inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  This message is sent once per 6 seconds per GPS satellite. ME checks the
parity of the data block and sends only blocks that pass the check.


  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  sid : GnssSignal
    GNSS signal identifier.
  tow : int
    GPS time-of-week at the start of the subframe.
  subframe_id : int
    Subframe ID (1-5).
  data : array
    Raw subframe data field of 300 bits (last byte padded with zeros).
  sender : int
    Optional sender ID, defaults to SENDER_ID (see sbp/msg.py).

  """
  _parser = construct.Struct(
                   'sid' / construct.Struct(GnssSignal._parser),
                   'tow' / construct.Int32ul,
                   'subframe_id' / construct.Int8ul,
                   'data' / construct.Array(38, construct.Int8ul),)
  __slots__ = [
               'sid',
               'tow',
               'subframe_id',
               'data',
              ]

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      super( MsgGPSL1CaRaw,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.from_binary(sbp.payload)
    else:
      super( MsgGPSL1CaRaw, self).__init__()
      self.msg_type = SBP_MSG_GPS_L1CA_RAW
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.sid = kwargs.pop('sid')
      self.tow = kwargs.pop('tow')
      self.subframe_id = kwargs.pop('subframe_id')
      self.data = kwargs.pop('data')

  def __repr__(self):
    return fmt_repr(self)

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    return MsgGPSL1CaRaw.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgGPSL1CaRaw(sbp, **d)

 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgGPSL1CaRaw._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgGPSL1CaRaw._parser.build(c)
    return self.pack()

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgGPSL1CaRaw, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    
SBP_MSG_GLO_L1OF_RAW = 0x7779
class MsgGloL1OfRaw(SBP):
  """SBP class for message MSG_GLO_L1OF_RAW (0x7779).

  You can have MSG_GLO_L1OF_RAW inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  This message is sent once per 2 seconds per GLONASS satellite. ME checks the
parity of the data block and sends only blocks that pass the check.


  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  sid : GnssSignal
    GNSS signal identifier.
  tow : int
    GPS time-of-week at the start of the subframe.
  string_number : int
    String number (1-15).
  data : array
    Raw string data field of 85 bits (last byte padded with zeros).
  sender : int
    Optional sender ID, defaults to SENDER_ID (see sbp/msg.py).

  """
  _parser = construct.Struct(
                   'sid' / construct.Struct(GnssSignal._parser),
                   'tow' / construct.Int32ul,
                   'string_number' / construct.Int8ul,
                   'data' / construct.Array(11, construct.Int8ul),)
  __slots__ = [
               'sid',
               'tow',
               'string_number',
               'data',
              ]

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      super( MsgGloL1OfRaw,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.from_binary(sbp.payload)
    else:
      super( MsgGloL1OfRaw, self).__init__()
      self.msg_type = SBP_MSG_GLO_L1OF_RAW
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.sid = kwargs.pop('sid')
      self.tow = kwargs.pop('tow')
      self.string_number = kwargs.pop('string_number')
      self.data = kwargs.pop('data')

  def __repr__(self):
    return fmt_repr(self)

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    return MsgGloL1OfRaw.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgGloL1OfRaw(sbp, **d)

 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgGloL1OfRaw._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgGloL1OfRaw._parser.build(c)
    return self.pack()

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgGloL1OfRaw, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    

msg_classes = {
  0x7778: MsgGPSL1CaRaw,
  0x7779: MsgGloL1OfRaw,
}