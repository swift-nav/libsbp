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
from sbp.gnss import GPSTimeSec, SvId

# Automatically generated from piksi/yaml/swiftnav/sbp/integrity.yaml with generate.py.
# Please do not hand edit!


class IntegritySSRHeader(object):
  """IntegritySSRHeader.
  
  
  Parameters
  ----------
  obs_time : GPSTimeSec
    GNSS reference time of the observation used to generate the flag.
  num_msgs : int
    Number of messages in the dataset
  seq_num : int
    Position of this message in the dataset
  ssr_sol_id : int
    SSR Solution ID.
  tile_set_id : int
    Unique identifier of the set this tile belongs to.
  tile_id : int
    Unique identifier of this tile in the tile set.
  chain_id : int
    Chain and type of flag.

  """
  _parser = construct.Struct(
                     'obs_time' / GPSTimeSec._parser,
                     'num_msgs' / construct.Int8ul,
                     'seq_num' / construct.Int8ul,
                     'ssr_sol_id' / construct.Int8ul,
                     'tile_set_id' / construct.Int16ul,
                     'tile_id' / construct.Int16ul,
                     'chain_id' / construct.Int8ul,)
  __slots__ = [
               'obs_time',
               'num_msgs',
               'seq_num',
               'ssr_sol_id',
               'tile_set_id',
               'tile_id',
               'chain_id',
              ]

  def __init__(self, payload=None, **kwargs):
    if payload:
      self.from_binary(payload)
    else:
      self.obs_time = kwargs.pop('obs_time')
      self.num_msgs = kwargs.pop('num_msgs')
      self.seq_num = kwargs.pop('seq_num')
      self.ssr_sol_id = kwargs.pop('ssr_sol_id')
      self.tile_set_id = kwargs.pop('tile_set_id')
      self.tile_id = kwargs.pop('tile_id')
      self.chain_id = kwargs.pop('chain_id')

  def __repr__(self):
    return fmt_repr(self)
  
  def from_binary(self, d):
    p = IntegritySSRHeader._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))
    
SBP_MSG_SSR_FLAG_HIGH_LEVEL = 0x0BB9
class MsgSsrFlagHighLevel(SBP):
  """SBP class for message MSG_SSR_FLAG_HIGH_LEVEL (0x0BB9).

  You can have MSG_SSR_FLAG_HIGH_LEVEL inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  Integrity monitoring flags for multiple aggregated elements. An element
  could be a satellite, SSR grid point, or SSR tile. A group of aggregated
  elements being monitored for integrity could refer to:

  - Satellites in a particular {GPS, GAL, BDS} constellation.

  - Satellites in the line-of-sight of a particular SSR tile.

  - Satellites in the line-of-sight of a particular SSR grid point.

  The integrity usage for a group of aggregated elements varies according to
  the integrity flag of the satellites comprising that group.

  SSR_INTEGRITY_USAGE_NOMINAL: All satellites received passed the integrity
  check and have flag INTEGRITY_FLAG_OK.

  SSR_INTEGRITY_USAGE_WARNING: A limited number of elements in the group
  failed the integrity check. Refer to more granular integrity messages for
  details on the specific failing elements.

  SSR_INTEGRITY_USAGE_ALERT: Most elements in the group failed the integrity
  check, do not use for positioning.

  SSR_INTEGRITY_USAGE_NOT_MONITORED: Unable to verify the integrity flag of
  elements in the group.

  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  obs_time : GPSTimeSec
    GNSS reference time of the observation used to generate the flag.
  corr_time : GPSTimeSec
    GNSS reference time of the correction associated to the flag.
  ssr_sol_id : int
    SSR Solution ID.
  tile_set_id : int
    Unique identifier of the set this tile belongs to.
  tile_id : int
    Unique identifier of this tile in the tile set.
  chain_id : int
    Chain and type of flag.
  use_gps_sat : int
    Use GPS satellites.
  use_gal_sat : int
    Use GAL satellites.
  use_bds_sat : int
    Use BDS satellites.
  reserved : array
    Reserved
  use_tropo_grid_points : int
    Use tropo grid points.
  use_iono_grid_points : int
    Use iono grid points.
  use_iono_tile_sat_los : int
    Use iono tile satellite LoS.
  use_iono_grid_point_sat_los : int
    Use iono grid point satellite LoS.
  sender : int
    Optional sender ID, defaults to SENDER_ID (see sbp/msg.py).

  """
  _parser = construct.Struct(
                   'obs_time' / GPSTimeSec._parser,
                   'corr_time' / GPSTimeSec._parser,
                   'ssr_sol_id' / construct.Int8ul,
                   'tile_set_id' / construct.Int16ul,
                   'tile_id' / construct.Int16ul,
                   'chain_id' / construct.Int8ul,
                   'use_gps_sat' / construct.Int8ul,
                   'use_gal_sat' / construct.Int8ul,
                   'use_bds_sat' / construct.Int8ul,
                   'reserved' / construct.Array(6, construct.Int8ul),
                   'use_tropo_grid_points' / construct.Int8ul,
                   'use_iono_grid_points' / construct.Int8ul,
                   'use_iono_tile_sat_los' / construct.Int8ul,
                   'use_iono_grid_point_sat_los' / construct.Int8ul,)
  __slots__ = [
               'obs_time',
               'corr_time',
               'ssr_sol_id',
               'tile_set_id',
               'tile_id',
               'chain_id',
               'use_gps_sat',
               'use_gal_sat',
               'use_bds_sat',
               'reserved',
               'use_tropo_grid_points',
               'use_iono_grid_points',
               'use_iono_tile_sat_los',
               'use_iono_grid_point_sat_los',
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
      self.obs_time = kwargs.pop('obs_time')
      self.corr_time = kwargs.pop('corr_time')
      self.ssr_sol_id = kwargs.pop('ssr_sol_id')
      self.tile_set_id = kwargs.pop('tile_set_id')
      self.tile_id = kwargs.pop('tile_id')
      self.chain_id = kwargs.pop('chain_id')
      self.use_gps_sat = kwargs.pop('use_gps_sat')
      self.use_gal_sat = kwargs.pop('use_gal_sat')
      self.use_bds_sat = kwargs.pop('use_bds_sat')
      self.reserved = kwargs.pop('reserved')
      self.use_tropo_grid_points = kwargs.pop('use_tropo_grid_points')
      self.use_iono_grid_points = kwargs.pop('use_iono_grid_points')
      self.use_iono_tile_sat_los = kwargs.pop('use_iono_tile_sat_los')
      self.use_iono_grid_point_sat_los = kwargs.pop('use_iono_grid_point_sat_los')

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

  def friendly_name(self):
    """Produces friendly human-readable name for this message

    """
    return "SSR FLAG HIGH LEVEL"

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
  obs_time : GPSTimeSec
    GNSS reference time of the observation used to generate the flag.
  num_msgs : int
    Number of messages in the dataset
  seq_num : int
    Position of this message in the dataset
  ssr_sol_id : int
    SSR Solution ID.
  chain_id : int
    Chain and type of flag.
  const_id : int
    Constellation ID.
  n_faulty_sats : int
    Number of faulty satellites.
  faulty_sats : array
    List of faulty satellites.
  sender : int
    Optional sender ID, defaults to SENDER_ID (see sbp/msg.py).

  """
  _parser = construct.Struct(
                   'obs_time' / GPSTimeSec._parser,
                   'num_msgs' / construct.Int8ul,
                   'seq_num' / construct.Int8ul,
                   'ssr_sol_id' / construct.Int8ul,
                   'chain_id' / construct.Int8ul,
                   'const_id' / construct.Int8ul,
                   'n_faulty_sats' / construct.Int8ul,
                   'faulty_sats' / construct.GreedyRange(construct.Int8ul),)
  __slots__ = [
               'obs_time',
               'num_msgs',
               'seq_num',
               'ssr_sol_id',
               'chain_id',
               'const_id',
               'n_faulty_sats',
               'faulty_sats',
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
      self.obs_time = kwargs.pop('obs_time')
      self.num_msgs = kwargs.pop('num_msgs')
      self.seq_num = kwargs.pop('seq_num')
      self.ssr_sol_id = kwargs.pop('ssr_sol_id')
      self.chain_id = kwargs.pop('chain_id')
      self.const_id = kwargs.pop('const_id')
      self.n_faulty_sats = kwargs.pop('n_faulty_sats')
      self.faulty_sats = kwargs.pop('faulty_sats')

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

  def friendly_name(self):
    """Produces friendly human-readable name for this message

    """
    return "SSR FLAG SATELLITES"

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
  header : IntegritySSRHeader
    Header of an integrity message.
  n_faulty_points : int
    Number of faulty grid points.
  faulty_points : array
    List of faulty grid points.
  sender : int
    Optional sender ID, defaults to SENDER_ID (see sbp/msg.py).

  """
  _parser = construct.Struct(
                   'header' / IntegritySSRHeader._parser,
                   'n_faulty_points' / construct.Int8ul,
                   'faulty_points' / construct.GreedyRange(construct.Int16ul),)
  __slots__ = [
               'header',
               'n_faulty_points',
               'faulty_points',
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
      self.header = kwargs.pop('header')
      self.n_faulty_points = kwargs.pop('n_faulty_points')
      self.faulty_points = kwargs.pop('faulty_points')

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

  def friendly_name(self):
    """Produces friendly human-readable name for this message

    """
    return "SSR FLAG TROPO GRID POINTS"

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
  header : IntegritySSRHeader
    Header of an integrity message.
  n_faulty_points : int
    Number of faulty grid points.
  faulty_points : array
    List of faulty grid points.
  sender : int
    Optional sender ID, defaults to SENDER_ID (see sbp/msg.py).

  """
  _parser = construct.Struct(
                   'header' / IntegritySSRHeader._parser,
                   'n_faulty_points' / construct.Int8ul,
                   'faulty_points' / construct.GreedyRange(construct.Int16ul),)
  __slots__ = [
               'header',
               'n_faulty_points',
               'faulty_points',
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
      self.header = kwargs.pop('header')
      self.n_faulty_points = kwargs.pop('n_faulty_points')
      self.faulty_points = kwargs.pop('faulty_points')

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

  def friendly_name(self):
    """Produces friendly human-readable name for this message

    """
    return "SSR FLAG IONO GRID POINTS"

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
  header : IntegritySSRHeader
    Header of an integrity message.
  n_faulty_los : int
    Number of faulty LOS.
  faulty_los : array
    List of faulty LOS
  sender : int
    Optional sender ID, defaults to SENDER_ID (see sbp/msg.py).

  """
  _parser = construct.Struct(
                   'header' / IntegritySSRHeader._parser,
                   'n_faulty_los' / construct.Int8ul,
                   'faulty_los' / construct.GreedyRange(SvId._parser),)
  __slots__ = [
               'header',
               'n_faulty_los',
               'faulty_los',
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
      self.header = kwargs.pop('header')
      self.n_faulty_los = kwargs.pop('n_faulty_los')
      self.faulty_los = kwargs.pop('faulty_los')

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

  def friendly_name(self):
    """Produces friendly human-readable name for this message

    """
    return "SSR FLAG IONO TILE SAT LOS"

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
  header : IntegritySSRHeader
    Header of an integrity message.
  grid_point_id : int
    Index of the grid point.
  n_faulty_los : int
    Number of faulty LOS.
  faulty_los : array
    List of faulty LOS
  sender : int
    Optional sender ID, defaults to SENDER_ID (see sbp/msg.py).

  """
  _parser = construct.Struct(
                   'header' / IntegritySSRHeader._parser,
                   'grid_point_id' / construct.Int16ul,
                   'n_faulty_los' / construct.Int8ul,
                   'faulty_los' / construct.GreedyRange(SvId._parser),)
  __slots__ = [
               'header',
               'grid_point_id',
               'n_faulty_los',
               'faulty_los',
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
      self.header = kwargs.pop('header')
      self.grid_point_id = kwargs.pop('grid_point_id')
      self.n_faulty_los = kwargs.pop('n_faulty_los')
      self.faulty_los = kwargs.pop('faulty_los')

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

  def friendly_name(self):
    """Produces friendly human-readable name for this message

    """
    return "SSR FLAG IONO GRID POINT SAT LOS"

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
    
SBP_MSG_ACKNOWLEDGE = 0x0BD2
class MsgAcknowledge(SBP):
  """SBP class for message MSG_ACKNOWLEDGE (0x0BD2).

  You can have MSG_ACKNOWLEDGE inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  

  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  request_id : int
    Echo of the request ID field from the corresponding CRA message, or 255 if
    no request ID was provided.
  area_id : int
    Echo of the Area ID field from the corresponding CRA message.
  response_code : int
    Reported status of the request.
  correction_mask_on_demand : int
    Contains the message group(s) that will be sent in response from the
    corresponding CRA correction mask. An echo of the correction mask field
    from the corresponding CRA message.
  correction_mask_stream : int
    For future expansion. Always set to 0.
  solution_id : int
    The solution ID of the instance providing the corrections.
  sender : int
    Optional sender ID, defaults to SENDER_ID (see sbp/msg.py).

  """
  _parser = construct.Struct(
                   'request_id' / construct.Int8ul,
                   'area_id' / construct.Int32ul,
                   'response_code' / construct.Int8ul,
                   'correction_mask_on_demand' / construct.Int16ul,
                   'correction_mask_stream' / construct.Int16ul,
                   'solution_id' / construct.Int8ul,)
  __slots__ = [
               'request_id',
               'area_id',
               'response_code',
               'correction_mask_on_demand',
               'correction_mask_stream',
               'solution_id',
              ]

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      super( MsgAcknowledge,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.from_binary(sbp.payload)
    else:
      super( MsgAcknowledge, self).__init__()
      self.msg_type = SBP_MSG_ACKNOWLEDGE
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.request_id = kwargs.pop('request_id')
      self.area_id = kwargs.pop('area_id')
      self.response_code = kwargs.pop('response_code')
      self.correction_mask_on_demand = kwargs.pop('correction_mask_on_demand')
      self.correction_mask_stream = kwargs.pop('correction_mask_stream')
      self.solution_id = kwargs.pop('solution_id')

  def __repr__(self):
    return fmt_repr(self)

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    return MsgAcknowledge.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgAcknowledge(sbp, **d)

 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgAcknowledge._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgAcknowledge._parser.build(c)
    return self.pack()

  def friendly_name(self):
    """Produces friendly human-readable name for this message

    """
    return "ACKNOWLEDGE"

  def into_buffer(self, buf, offset):
    """Produce a framed/packed SBP message into the provided buffer and offset.

    """
    self.payload = containerize(exclude_fields(self))
    self.parser = MsgAcknowledge._parser
    self.stream_payload.reset(buf, offset)
    return self.pack_into(buf, offset, self._build_payload)

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgAcknowledge, self).to_json_dict()
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
  0x0BD2: MsgAcknowledge,
}