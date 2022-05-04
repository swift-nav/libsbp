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
Integrity flag messages
"""

import json

import construct

from sbp.msg import SBP, SENDER_ID
from sbp.utils import fmt_repr, exclude_fields, walk_json_dict, containerize

# Automatically generated from piksi/yaml/swiftnav/sbp/integrity.yaml with generate.py.
# Please do not hand edit!


SBP_MSG_SSR_FLAG_HIGH_LEVEL = 0x0BB9
class MsgSsrFlagHighLevel(SBP):
  """SBP class for message MSG_SSR_FLAG_HIGH_LEVEL (0x0BB9).

  You can have MSG_SSR_FLAG_HIGH_LEVEL inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  

  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  stub : array
  sender : int
    Optional sender ID, defaults to SENDER_ID (see sbp/msg.py).

  """
  _parser = construct.Struct(
                   'stub' / construct.GreedyRange(construct.Int8ul),)
  __slots__ = [
               'stub',
              ]

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      super( MsgSsrFlagHighLevel,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.from_binary(sbp.payload)
    else:
      super( MsgSsrFlagHighLevel, self).__init__()
      self.msg_type = SBP_MSG_SSR_FLAG_HIGH_LEVEL
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.stub = kwargs.pop('stub')

  def __repr__(self):
    return fmt_repr(self)

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    return MsgSsrFlagHighLevel.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgSsrFlagHighLevel(sbp, **d)

 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgSsrFlagHighLevel._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgSsrFlagHighLevel._parser.build(c)
    return self.pack()

  def into_buffer(self, buf, offset):
    """Produce a framed/packed SBP message into the provided buffer and offset.

    """
    self.payload = containerize(exclude_fields(self))
    self.parser = MsgSsrFlagHighLevel._parser
    self.stream_payload.reset(buf, offset)
    return self.pack_into(buf, offset, self._build_payload)

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgSsrFlagHighLevel, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    
SBP_MSG_SSR_FLAG_SATELLITES = 0x0BBD
class MsgSsrFlagSatellites(SBP):
  """SBP class for message MSG_SSR_FLAG_SATELLITES (0x0BBD).

  You can have MSG_SSR_FLAG_SATELLITES inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  

  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  stub : array
  sender : int
    Optional sender ID, defaults to SENDER_ID (see sbp/msg.py).

  """
  _parser = construct.Struct(
                   'stub' / construct.GreedyRange(construct.Int8ul),)
  __slots__ = [
               'stub',
              ]

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      super( MsgSsrFlagSatellites,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.from_binary(sbp.payload)
    else:
      super( MsgSsrFlagSatellites, self).__init__()
      self.msg_type = SBP_MSG_SSR_FLAG_SATELLITES
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.stub = kwargs.pop('stub')

  def __repr__(self):
    return fmt_repr(self)

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    return MsgSsrFlagSatellites.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgSsrFlagSatellites(sbp, **d)

 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgSsrFlagSatellites._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgSsrFlagSatellites._parser.build(c)
    return self.pack()

  def into_buffer(self, buf, offset):
    """Produce a framed/packed SBP message into the provided buffer and offset.

    """
    self.payload = containerize(exclude_fields(self))
    self.parser = MsgSsrFlagSatellites._parser
    self.stream_payload.reset(buf, offset)
    return self.pack_into(buf, offset, self._build_payload)

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgSsrFlagSatellites, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    
SBP_MSG_SSR_FLAG_TROPO_GRID_POINTS = 0x0BC3
class MsgSsrFlagTropoGridPoints(SBP):
  """SBP class for message MSG_SSR_FLAG_TROPO_GRID_POINTS (0x0BC3).

  You can have MSG_SSR_FLAG_TROPO_GRID_POINTS inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  

  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  stub : array
  sender : int
    Optional sender ID, defaults to SENDER_ID (see sbp/msg.py).

  """
  _parser = construct.Struct(
                   'stub' / construct.GreedyRange(construct.Int8ul),)
  __slots__ = [
               'stub',
              ]

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      super( MsgSsrFlagTropoGridPoints,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.from_binary(sbp.payload)
    else:
      super( MsgSsrFlagTropoGridPoints, self).__init__()
      self.msg_type = SBP_MSG_SSR_FLAG_TROPO_GRID_POINTS
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.stub = kwargs.pop('stub')

  def __repr__(self):
    return fmt_repr(self)

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    return MsgSsrFlagTropoGridPoints.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgSsrFlagTropoGridPoints(sbp, **d)

 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgSsrFlagTropoGridPoints._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgSsrFlagTropoGridPoints._parser.build(c)
    return self.pack()

  def into_buffer(self, buf, offset):
    """Produce a framed/packed SBP message into the provided buffer and offset.

    """
    self.payload = containerize(exclude_fields(self))
    self.parser = MsgSsrFlagTropoGridPoints._parser
    self.stream_payload.reset(buf, offset)
    return self.pack_into(buf, offset, self._build_payload)

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgSsrFlagTropoGridPoints, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    
SBP_MSG_SSR_FLAG_IONO_GRID_POINTS = 0x0BC7
class MsgSsrFlagIonoGridPoints(SBP):
  """SBP class for message MSG_SSR_FLAG_IONO_GRID_POINTS (0x0BC7).

  You can have MSG_SSR_FLAG_IONO_GRID_POINTS inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  

  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  stub : array
  sender : int
    Optional sender ID, defaults to SENDER_ID (see sbp/msg.py).

  """
  _parser = construct.Struct(
                   'stub' / construct.GreedyRange(construct.Int8ul),)
  __slots__ = [
               'stub',
              ]

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      super( MsgSsrFlagIonoGridPoints,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.from_binary(sbp.payload)
    else:
      super( MsgSsrFlagIonoGridPoints, self).__init__()
      self.msg_type = SBP_MSG_SSR_FLAG_IONO_GRID_POINTS
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.stub = kwargs.pop('stub')

  def __repr__(self):
    return fmt_repr(self)

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    return MsgSsrFlagIonoGridPoints.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgSsrFlagIonoGridPoints(sbp, **d)

 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgSsrFlagIonoGridPoints._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgSsrFlagIonoGridPoints._parser.build(c)
    return self.pack()

  def into_buffer(self, buf, offset):
    """Produce a framed/packed SBP message into the provided buffer and offset.

    """
    self.payload = containerize(exclude_fields(self))
    self.parser = MsgSsrFlagIonoGridPoints._parser
    self.stream_payload.reset(buf, offset)
    return self.pack_into(buf, offset, self._build_payload)

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgSsrFlagIonoGridPoints, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    
SBP_MSG_SSR_FLAG_IONO_TILE_SAT_LOS = 0x0BCD
class MsgSsrFlagIonoTileSatLos(SBP):
  """SBP class for message MSG_SSR_FLAG_IONO_TILE_SAT_LOS (0x0BCD).

  You can have MSG_SSR_FLAG_IONO_TILE_SAT_LOS inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  

  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  stub : array
  sender : int
    Optional sender ID, defaults to SENDER_ID (see sbp/msg.py).

  """
  _parser = construct.Struct(
                   'stub' / construct.GreedyRange(construct.Int8ul),)
  __slots__ = [
               'stub',
              ]

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      super( MsgSsrFlagIonoTileSatLos,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.from_binary(sbp.payload)
    else:
      super( MsgSsrFlagIonoTileSatLos, self).__init__()
      self.msg_type = SBP_MSG_SSR_FLAG_IONO_TILE_SAT_LOS
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.stub = kwargs.pop('stub')

  def __repr__(self):
    return fmt_repr(self)

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    return MsgSsrFlagIonoTileSatLos.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgSsrFlagIonoTileSatLos(sbp, **d)

 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgSsrFlagIonoTileSatLos._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgSsrFlagIonoTileSatLos._parser.build(c)
    return self.pack()

  def into_buffer(self, buf, offset):
    """Produce a framed/packed SBP message into the provided buffer and offset.

    """
    self.payload = containerize(exclude_fields(self))
    self.parser = MsgSsrFlagIonoTileSatLos._parser
    self.stream_payload.reset(buf, offset)
    return self.pack_into(buf, offset, self._build_payload)

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgSsrFlagIonoTileSatLos, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    
SBP_MSG_SSR_FLAG_IONO_GRID_POINT_SAT_LOS = 0x0BD1
class MsgSsrFlagIonoGridPointSatLos(SBP):
  """SBP class for message MSG_SSR_FLAG_IONO_GRID_POINT_SAT_LOS (0x0BD1).

  You can have MSG_SSR_FLAG_IONO_GRID_POINT_SAT_LOS inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  

  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  stub : array
  sender : int
    Optional sender ID, defaults to SENDER_ID (see sbp/msg.py).

  """
  _parser = construct.Struct(
                   'stub' / construct.GreedyRange(construct.Int8ul),)
  __slots__ = [
               'stub',
              ]

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      super( MsgSsrFlagIonoGridPointSatLos,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.from_binary(sbp.payload)
    else:
      super( MsgSsrFlagIonoGridPointSatLos, self).__init__()
      self.msg_type = SBP_MSG_SSR_FLAG_IONO_GRID_POINT_SAT_LOS
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.stub = kwargs.pop('stub')

  def __repr__(self):
    return fmt_repr(self)

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    return MsgSsrFlagIonoGridPointSatLos.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgSsrFlagIonoGridPointSatLos(sbp, **d)

 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgSsrFlagIonoGridPointSatLos._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgSsrFlagIonoGridPointSatLos._parser.build(c)
    return self.pack()

  def into_buffer(self, buf, offset):
    """Produce a framed/packed SBP message into the provided buffer and offset.

    """
    self.payload = containerize(exclude_fields(self))
    self.parser = MsgSsrFlagIonoGridPointSatLos._parser
    self.stream_payload.reset(buf, offset)
    return self.pack_into(buf, offset, self._build_payload)

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgSsrFlagIonoGridPointSatLos, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    

msg_classes = {
  0x0BB9: MsgSsrFlagHighLevel,
  0x0BBD: MsgSsrFlagSatellites,
  0x0BC3: MsgSsrFlagTropoGridPoints,
  0x0BC7: MsgSsrFlagIonoGridPoints,
  0x0BCD: MsgSsrFlagIonoTileSatLos,
  0x0BD1: MsgSsrFlagIonoGridPointSatLos,
}