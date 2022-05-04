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
Precise State Space Representation (SSR) corrections format
"""

import json

import construct

from sbp.msg import SBP, SENDER_ID
from sbp.utils import fmt_repr, exclude_fields, walk_json_dict, containerize
from sbp.gnss import GPSTimeSec, GnssSignal, SvId

# Automatically generated from piksi/yaml/swiftnav/sbp/ssr.yaml with generate.py.
# Please do not hand edit!


class CodeBiasesContent(object):
  """CodeBiasesContent.
  
  Code biases are to be added to pseudorange. The corrections conform with
  RTCMv3 MT 1059 / 1065.
  
  Parameters
  ----------
  code : int
    Signal encoded following RTCM specifications (DF380, DF381, DF382 and
    DF467).
  value : int
    Code bias value

  """
  _parser = construct.Struct(
                     'code' / construct.Int8ul,
                     'value' / construct.Int16sl,)
  __slots__ = [
               'code',
               'value',
              ]

  def __init__(self, payload=None, **kwargs):
    if payload:
      self.from_binary(payload)
    else:
      self.code = kwargs.pop('code')
      self.value = kwargs.pop('value')

  def __repr__(self):
    return fmt_repr(self)
  
  def from_binary(self, d):
    p = CodeBiasesContent._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))
    
class PhaseBiasesContent(object):
  """PhaseBiasesContent.
  
  Phase biases are to be added to carrier phase measurements.
  
  Parameters
  ----------
  code : int
    Signal encoded following RTCM specifications (DF380, DF381, DF382 and
    DF467)
  integer_indicator : int
    Indicator for integer property
  widelane_integer_indicator : int
    Indicator for two groups of Wide-Lane(s) integer property
  discontinuity_counter : int
    Signal phase discontinuity counter. Increased for every discontinuity in
    phase.
  bias : int
    Phase bias for specified signal

  """
  _parser = construct.Struct(
                     'code' / construct.Int8ul,
                     'integer_indicator' / construct.Int8ul,
                     'widelane_integer_indicator' / construct.Int8ul,
                     'discontinuity_counter' / construct.Int8ul,
                     'bias' / construct.Int32sl,)
  __slots__ = [
               'code',
               'integer_indicator',
               'widelane_integer_indicator',
               'discontinuity_counter',
               'bias',
              ]

  def __init__(self, payload=None, **kwargs):
    if payload:
      self.from_binary(payload)
    else:
      self.code = kwargs.pop('code')
      self.integer_indicator = kwargs.pop('integer_indicator')
      self.widelane_integer_indicator = kwargs.pop('widelane_integer_indicator')
      self.discontinuity_counter = kwargs.pop('discontinuity_counter')
      self.bias = kwargs.pop('bias')

  def __repr__(self):
    return fmt_repr(self)
  
  def from_binary(self, d):
    p = PhaseBiasesContent._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))
    
class STECHeader(object):
  """STECHeader.
  
  A full set of STEC information will likely span multiple SBP messages, since
  SBP message a limited to 255 bytes.  The header is used to tie multiple SBP
  messages into a sequence.
  
  Parameters
  ----------
  tile_set_id : int
    Unique identifier of the tile set this tile belongs to.
  tile_id : int
    Unique identifier of this tile in the tile set.
  time : GPSTimeSec
    GNSS reference time of the correction
  num_msgs : int
    Number of messages in the dataset
  seq_num : int
    Position of this message in the dataset
  update_interval : int
    Update interval between consecutive corrections. Encoded following RTCM
    DF391 specification.
  iod_atmo : int
    IOD of the SSR atmospheric correction

  """
  _parser = construct.Struct(
                     'tile_set_id' / construct.Int16ul,
                     'tile_id' / construct.Int16ul,
                     'time' / GPSTimeSec._parser,
                     'num_msgs' / construct.Int8ul,
                     'seq_num' / construct.Int8ul,
                     'update_interval' / construct.Int8ul,
                     'iod_atmo' / construct.Int8ul,)
  __slots__ = [
               'tile_set_id',
               'tile_id',
               'time',
               'num_msgs',
               'seq_num',
               'update_interval',
               'iod_atmo',
              ]

  def __init__(self, payload=None, **kwargs):
    if payload:
      self.from_binary(payload)
    else:
      self.tile_set_id = kwargs.pop('tile_set_id')
      self.tile_id = kwargs.pop('tile_id')
      self.time = kwargs.pop('time')
      self.num_msgs = kwargs.pop('num_msgs')
      self.seq_num = kwargs.pop('seq_num')
      self.update_interval = kwargs.pop('update_interval')
      self.iod_atmo = kwargs.pop('iod_atmo')

  def __repr__(self):
    return fmt_repr(self)
  
  def from_binary(self, d):
    p = STECHeader._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))
    
class GriddedCorrectionHeader(object):
  """GriddedCorrectionHeader.
  
  The LPP message contains nested variable length arrays which are not
  supported in SBP, so each grid point will be identified by the index.
  
  Parameters
  ----------
  tile_set_id : int
    Unique identifier of the tile set this tile belongs to.
  tile_id : int
    Unique identifier of this tile in the tile set.
  time : GPSTimeSec
    GNSS reference time of the correction
  num_msgs : int
    Number of messages in the dataset
  seq_num : int
    Position of this message in the dataset
  update_interval : int
    Update interval between consecutive corrections. Encoded following RTCM
    DF391 specification.
  iod_atmo : int
    IOD of the SSR atmospheric correction
  tropo_quality_indicator : int
    Quality of the troposphere data. Encoded following RTCM DF389
    specification in units of m.

  """
  _parser = construct.Struct(
                     'tile_set_id' / construct.Int16ul,
                     'tile_id' / construct.Int16ul,
                     'time' / GPSTimeSec._parser,
                     'num_msgs' / construct.Int16ul,
                     'seq_num' / construct.Int16ul,
                     'update_interval' / construct.Int8ul,
                     'iod_atmo' / construct.Int8ul,
                     'tropo_quality_indicator' / construct.Int8ul,)
  __slots__ = [
               'tile_set_id',
               'tile_id',
               'time',
               'num_msgs',
               'seq_num',
               'update_interval',
               'iod_atmo',
               'tropo_quality_indicator',
              ]

  def __init__(self, payload=None, **kwargs):
    if payload:
      self.from_binary(payload)
    else:
      self.tile_set_id = kwargs.pop('tile_set_id')
      self.tile_id = kwargs.pop('tile_id')
      self.time = kwargs.pop('time')
      self.num_msgs = kwargs.pop('num_msgs')
      self.seq_num = kwargs.pop('seq_num')
      self.update_interval = kwargs.pop('update_interval')
      self.iod_atmo = kwargs.pop('iod_atmo')
      self.tropo_quality_indicator = kwargs.pop('tropo_quality_indicator')

  def __repr__(self):
    return fmt_repr(self)
  
  def from_binary(self, d):
    p = GriddedCorrectionHeader._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))
    
class STECSatElement(object):
  """STECSatElement.
  
  STEC polynomial for the given satellite.
  
  Parameters
  ----------
  sv_id : SvId
    Unique space vehicle identifier
  stec_quality_indicator : int
    Quality of the STEC data. Encoded following RTCM DF389 specification but
    in units of TECU instead of m.
  stec_coeff : array
    Coefficients of the STEC polynomial in the order of C00, C01, C10, C11

  """
  _parser = construct.Struct(
                     'sv_id' / SvId._parser,
                     'stec_quality_indicator' / construct.Int8ul,
                     'stec_coeff' / construct.Array(4, construct.Int16sl),)
  __slots__ = [
               'sv_id',
               'stec_quality_indicator',
               'stec_coeff',
              ]

  def __init__(self, payload=None, **kwargs):
    if payload:
      self.from_binary(payload)
    else:
      self.sv_id = kwargs.pop('sv_id')
      self.stec_quality_indicator = kwargs.pop('stec_quality_indicator')
      self.stec_coeff = kwargs.pop('stec_coeff')

  def __repr__(self):
    return fmt_repr(self)
  
  def from_binary(self, d):
    p = STECSatElement._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))
    
class TroposphericDelayCorrectionNoStd(object):
  """TroposphericDelayCorrectionNoStd.
  
  Troposphere vertical delays at the grid point.
  
  Parameters
  ----------
  hydro : int
    Hydrostatic vertical delay
  wet : int
    Wet vertical delay

  """
  _parser = construct.Struct(
                     'hydro' / construct.Int16sl,
                     'wet' / construct.Int8sl,)
  __slots__ = [
               'hydro',
               'wet',
              ]

  def __init__(self, payload=None, **kwargs):
    if payload:
      self.from_binary(payload)
    else:
      self.hydro = kwargs.pop('hydro')
      self.wet = kwargs.pop('wet')

  def __repr__(self):
    return fmt_repr(self)
  
  def from_binary(self, d):
    p = TroposphericDelayCorrectionNoStd._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))
    
class TroposphericDelayCorrection(object):
  """TroposphericDelayCorrection.
  
  Troposphere vertical delays (mean and standard deviation) at the grid point.
  
  Parameters
  ----------
  hydro : int
    Hydrostatic vertical delay
  wet : int
    Wet vertical delay
  stddev : int
    stddev

  """
  _parser = construct.Struct(
                     'hydro' / construct.Int16sl,
                     'wet' / construct.Int8sl,
                     'stddev' / construct.Int8ul,)
  __slots__ = [
               'hydro',
               'wet',
               'stddev',
              ]

  def __init__(self, payload=None, **kwargs):
    if payload:
      self.from_binary(payload)
    else:
      self.hydro = kwargs.pop('hydro')
      self.wet = kwargs.pop('wet')
      self.stddev = kwargs.pop('stddev')

  def __repr__(self):
    return fmt_repr(self)
  
  def from_binary(self, d):
    p = TroposphericDelayCorrection._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))
    
class STECResidualNoStd(object):
  """STECResidualNoStd.
  
  STEC residual for the given satellite at the grid point.
  
  Parameters
  ----------
  sv_id : SvId
    space vehicle identifier
  residual : int
    STEC residual

  """
  _parser = construct.Struct(
                     'sv_id' / SvId._parser,
                     'residual' / construct.Int16sl,)
  __slots__ = [
               'sv_id',
               'residual',
              ]

  def __init__(self, payload=None, **kwargs):
    if payload:
      self.from_binary(payload)
    else:
      self.sv_id = kwargs.pop('sv_id')
      self.residual = kwargs.pop('residual')

  def __repr__(self):
    return fmt_repr(self)
  
  def from_binary(self, d):
    p = STECResidualNoStd._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))
    
class STECResidual(object):
  """STECResidual.
  
  STEC residual (mean and standard deviation) for the given satellite at the
  grid point.
  
  Parameters
  ----------
  sv_id : SvId
    space vehicle identifier
  residual : int
    STEC residual
  stddev : int
    stddev

  """
  _parser = construct.Struct(
                     'sv_id' / SvId._parser,
                     'residual' / construct.Int16sl,
                     'stddev' / construct.Int8ul,)
  __slots__ = [
               'sv_id',
               'residual',
               'stddev',
              ]

  def __init__(self, payload=None, **kwargs):
    if payload:
      self.from_binary(payload)
    else:
      self.sv_id = kwargs.pop('sv_id')
      self.residual = kwargs.pop('residual')
      self.stddev = kwargs.pop('stddev')

  def __repr__(self):
    return fmt_repr(self)
  
  def from_binary(self, d):
    p = STECResidual._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))
    
class SatelliteAPC(object):
  """SatelliteAPC.
  
  Contains phase center offset and elevation variation corrections for one
  signal on a satellite.
  
  Parameters
  ----------
  sid : GnssSignal
    GNSS signal identifier (16 bit)
  sat_info : int
    Additional satellite information
  svn : int
    Satellite Code, as defined by IGS. Typically the space vehicle number.
  pco : array
    Mean phase center offset, X Y and Z axes. See IGS ANTEX file format
    description for coordinate system definition.
  pcv : array
    Elevation dependent phase center variations. First element is 0 degrees
    separation from the Z axis, subsequent elements represent elevation
    variations in 1 degree increments.

  """
  _parser = construct.Struct(
                     'sid' / GnssSignal._parser,
                     'sat_info' / construct.Int8ul,
                     'svn' / construct.Int16ul,
                     'pco' / construct.Array(3, construct.Int16sl),
                     'pcv' / construct.Array(21, construct.Int8sl),)
  __slots__ = [
               'sid',
               'sat_info',
               'svn',
               'pco',
               'pcv',
              ]

  def __init__(self, payload=None, **kwargs):
    if payload:
      self.from_binary(payload)
    else:
      self.sid = kwargs.pop('sid')
      self.sat_info = kwargs.pop('sat_info')
      self.svn = kwargs.pop('svn')
      self.pco = kwargs.pop('pco')
      self.pcv = kwargs.pop('pcv')

  def __repr__(self):
    return fmt_repr(self)
  
  def from_binary(self, d):
    p = SatelliteAPC._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))
    
class STECHeaderDepA(object):
  """STECHeaderDepA.
  
  A full set of STEC information will likely span multiple SBP messages, since
  SBP message a limited to 255 bytes.  The header is used to tie multiple SBP
  messages into a sequence.
  
  Parameters
  ----------
  time : GPSTimeSec
    GNSS reference time of the correction
  num_msgs : int
    Number of messages in the dataset
  seq_num : int
    Position of this message in the dataset
  update_interval : int
    Update interval between consecutive corrections. Encoded following RTCM
    DF391 specification.
  iod_atmo : int
    IOD of the SSR atmospheric correction

  """
  _parser = construct.Struct(
                     'time' / GPSTimeSec._parser,
                     'num_msgs' / construct.Int8ul,
                     'seq_num' / construct.Int8ul,
                     'update_interval' / construct.Int8ul,
                     'iod_atmo' / construct.Int8ul,)
  __slots__ = [
               'time',
               'num_msgs',
               'seq_num',
               'update_interval',
               'iod_atmo',
              ]

  def __init__(self, payload=None, **kwargs):
    if payload:
      self.from_binary(payload)
    else:
      self.time = kwargs.pop('time')
      self.num_msgs = kwargs.pop('num_msgs')
      self.seq_num = kwargs.pop('seq_num')
      self.update_interval = kwargs.pop('update_interval')
      self.iod_atmo = kwargs.pop('iod_atmo')

  def __repr__(self):
    return fmt_repr(self)
  
  def from_binary(self, d):
    p = STECHeaderDepA._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))
    
class GriddedCorrectionHeaderDepA(object):
  """GriddedCorrectionHeaderDepA.
  
  The 3GPP message contains nested variable length arrays which are not
  supported in SBP, so each grid point will be identified by the index.
  
  Parameters
  ----------
  time : GPSTimeSec
    GNSS reference time of the correction
  num_msgs : int
    Number of messages in the dataset
  seq_num : int
    Position of this message in the dataset
  update_interval : int
    Update interval between consecutive corrections. Encoded following RTCM
    DF391 specification.
  iod_atmo : int
    IOD of the SSR atmospheric correction
  tropo_quality_indicator : int
    Quality of the troposphere data. Encoded following RTCM DF389
    specification in units of m.

  """
  _parser = construct.Struct(
                     'time' / GPSTimeSec._parser,
                     'num_msgs' / construct.Int16ul,
                     'seq_num' / construct.Int16ul,
                     'update_interval' / construct.Int8ul,
                     'iod_atmo' / construct.Int8ul,
                     'tropo_quality_indicator' / construct.Int8ul,)
  __slots__ = [
               'time',
               'num_msgs',
               'seq_num',
               'update_interval',
               'iod_atmo',
               'tropo_quality_indicator',
              ]

  def __init__(self, payload=None, **kwargs):
    if payload:
      self.from_binary(payload)
    else:
      self.time = kwargs.pop('time')
      self.num_msgs = kwargs.pop('num_msgs')
      self.seq_num = kwargs.pop('seq_num')
      self.update_interval = kwargs.pop('update_interval')
      self.iod_atmo = kwargs.pop('iod_atmo')
      self.tropo_quality_indicator = kwargs.pop('tropo_quality_indicator')

  def __repr__(self):
    return fmt_repr(self)
  
  def from_binary(self, d):
    p = GriddedCorrectionHeaderDepA._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))
    
class GridDefinitionHeaderDepA(object):
  """GridDefinitionHeaderDepA.
  
  Defines the grid for MSG_SSR_GRIDDED_CORRECTION messages. Also includes an
  RLE encoded validity list.
  
  Parameters
  ----------
  region_size_inverse : int
    region_size (deg) = 10 / region_size_inverse 0 is an invalid value.
  area_width : int
    grid height (deg) = grid width (deg) = area_width / region_size 0 is an
    invalid value.
  lat_nw_corner_enc : int
    North-West corner latitude (deg) = region_size * lat_nw_corner_enc - 90
  lon_nw_corner_enc : int
    North-West corner longitude (deg) = region_size * lon_nw_corner_enc - 180
  num_msgs : int
    Number of messages in the dataset
  seq_num : int
    Position of this message in the dataset

  """
  _parser = construct.Struct(
                     'region_size_inverse' / construct.Int8ul,
                     'area_width' / construct.Int16ul,
                     'lat_nw_corner_enc' / construct.Int16ul,
                     'lon_nw_corner_enc' / construct.Int16ul,
                     'num_msgs' / construct.Int8ul,
                     'seq_num' / construct.Int8ul,)
  __slots__ = [
               'region_size_inverse',
               'area_width',
               'lat_nw_corner_enc',
               'lon_nw_corner_enc',
               'num_msgs',
               'seq_num',
              ]

  def __init__(self, payload=None, **kwargs):
    if payload:
      self.from_binary(payload)
    else:
      self.region_size_inverse = kwargs.pop('region_size_inverse')
      self.area_width = kwargs.pop('area_width')
      self.lat_nw_corner_enc = kwargs.pop('lat_nw_corner_enc')
      self.lon_nw_corner_enc = kwargs.pop('lon_nw_corner_enc')
      self.num_msgs = kwargs.pop('num_msgs')
      self.seq_num = kwargs.pop('seq_num')

  def __repr__(self):
    return fmt_repr(self)
  
  def from_binary(self, d):
    p = GridDefinitionHeaderDepA._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))
    
SBP_MSG_SSR_ORBIT_CLOCK = 0x05DD
class MsgSsrOrbitClock(SBP):
  """SBP class for message MSG_SSR_ORBIT_CLOCK (0x05DD).

  You can have MSG_SSR_ORBIT_CLOCK inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  The precise orbit and clock correction message is to be applied as a delta
  correction to broadcast ephemeris and is an equivalent to the 1060 /1066
  RTCM message types.

  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  time : GPSTimeSec
    GNSS reference time of the correction
  sid : GnssSignal
    GNSS signal identifier (16 bit)
  update_interval : int
    Update interval between consecutive corrections. Encoded following RTCM
    DF391 specification.
  iod_ssr : int
    IOD of the SSR correction. A change of Issue Of Data SSR is used to
    indicate a change in the SSR generating configuration
  iod : int
    Issue of broadcast ephemeris data or IODCRC (Beidou)
  radial : int
    Orbit radial delta correction
  along : int
    Orbit along delta correction
  cross : int
    Orbit along delta correction
  dot_radial : int
    Velocity of orbit radial delta correction
  dot_along : int
    Velocity of orbit along delta correction
  dot_cross : int
    Velocity of orbit cross delta correction
  c0 : int
    C0 polynomial coefficient for correction of broadcast satellite clock
  c1 : int
    C1 polynomial coefficient for correction of broadcast satellite clock
  c2 : int
    C2 polynomial coefficient for correction of broadcast satellite clock
  sender : int
    Optional sender ID, defaults to SENDER_ID (see sbp/msg.py).

  """
  _parser = construct.Struct(
                   'time' / GPSTimeSec._parser,
                   'sid' / GnssSignal._parser,
                   'update_interval' / construct.Int8ul,
                   'iod_ssr' / construct.Int8ul,
                   'iod' / construct.Int32ul,
                   'radial' / construct.Int32sl,
                   'along' / construct.Int32sl,
                   'cross' / construct.Int32sl,
                   'dot_radial' / construct.Int32sl,
                   'dot_along' / construct.Int32sl,
                   'dot_cross' / construct.Int32sl,
                   'c0' / construct.Int32sl,
                   'c1' / construct.Int32sl,
                   'c2' / construct.Int32sl,)
  __slots__ = [
               'time',
               'sid',
               'update_interval',
               'iod_ssr',
               'iod',
               'radial',
               'along',
               'cross',
               'dot_radial',
               'dot_along',
               'dot_cross',
               'c0',
               'c1',
               'c2',
              ]

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      super( MsgSsrOrbitClock,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.from_binary(sbp.payload)
    else:
      super( MsgSsrOrbitClock, self).__init__()
      self.msg_type = SBP_MSG_SSR_ORBIT_CLOCK
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.time = kwargs.pop('time')
      self.sid = kwargs.pop('sid')
      self.update_interval = kwargs.pop('update_interval')
      self.iod_ssr = kwargs.pop('iod_ssr')
      self.iod = kwargs.pop('iod')
      self.radial = kwargs.pop('radial')
      self.along = kwargs.pop('along')
      self.cross = kwargs.pop('cross')
      self.dot_radial = kwargs.pop('dot_radial')
      self.dot_along = kwargs.pop('dot_along')
      self.dot_cross = kwargs.pop('dot_cross')
      self.c0 = kwargs.pop('c0')
      self.c1 = kwargs.pop('c1')
      self.c2 = kwargs.pop('c2')

  def __repr__(self):
    return fmt_repr(self)

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    return MsgSsrOrbitClock.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgSsrOrbitClock(sbp, **d)

 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgSsrOrbitClock._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgSsrOrbitClock._parser.build(c)
    return self.pack()

  def into_buffer(self, buf, offset):
    """Produce a framed/packed SBP message into the provided buffer and offset.

    """
    self.payload = containerize(exclude_fields(self))
    self.parser = MsgSsrOrbitClock._parser
    self.stream_payload.reset(buf, offset)
    return self.pack_into(buf, offset, self._build_payload)

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgSsrOrbitClock, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    
SBP_MSG_SSR_CODE_BIASES = 0x05E1
class MsgSsrCodeBiases(SBP):
  """SBP class for message MSG_SSR_CODE_BIASES (0x05E1).

  You can have MSG_SSR_CODE_BIASES inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  The precise code biases message is to be added to the pseudorange of the
  corresponding signal to get corrected pseudorange. It is an equivalent to
  the 1059 / 1065 RTCM message types.

  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  time : GPSTimeSec
    GNSS reference time of the correction
  sid : GnssSignal
    GNSS signal identifier (16 bit)
  update_interval : int
    Update interval between consecutive corrections. Encoded following RTCM
    DF391 specification.
  iod_ssr : int
    IOD of the SSR correction. A change of Issue Of Data SSR is used to
    indicate a change in the SSR generating configuration
  biases : array
    Code biases for the different satellite signals
  sender : int
    Optional sender ID, defaults to SENDER_ID (see sbp/msg.py).

  """
  _parser = construct.Struct(
                   'time' / GPSTimeSec._parser,
                   'sid' / GnssSignal._parser,
                   'update_interval' / construct.Int8ul,
                   'iod_ssr' / construct.Int8ul,
                   'biases' / construct.GreedyRange(CodeBiasesContent._parser),)
  __slots__ = [
               'time',
               'sid',
               'update_interval',
               'iod_ssr',
               'biases',
              ]

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      super( MsgSsrCodeBiases,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.from_binary(sbp.payload)
    else:
      super( MsgSsrCodeBiases, self).__init__()
      self.msg_type = SBP_MSG_SSR_CODE_BIASES
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.time = kwargs.pop('time')
      self.sid = kwargs.pop('sid')
      self.update_interval = kwargs.pop('update_interval')
      self.iod_ssr = kwargs.pop('iod_ssr')
      self.biases = kwargs.pop('biases')

  def __repr__(self):
    return fmt_repr(self)

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    return MsgSsrCodeBiases.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgSsrCodeBiases(sbp, **d)

 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgSsrCodeBiases._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgSsrCodeBiases._parser.build(c)
    return self.pack()

  def into_buffer(self, buf, offset):
    """Produce a framed/packed SBP message into the provided buffer and offset.

    """
    self.payload = containerize(exclude_fields(self))
    self.parser = MsgSsrCodeBiases._parser
    self.stream_payload.reset(buf, offset)
    return self.pack_into(buf, offset, self._build_payload)

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgSsrCodeBiases, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    
SBP_MSG_SSR_PHASE_BIASES = 0x05E6
class MsgSsrPhaseBiases(SBP):
  """SBP class for message MSG_SSR_PHASE_BIASES (0x05E6).

  You can have MSG_SSR_PHASE_BIASES inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  The precise phase biases message contains the biases to be added to the
  carrier phase of the corresponding signal to get corrected carrier phase
  measurement, as well as the satellite yaw angle to be applied to compute the
  phase wind-up correction. It is typically an equivalent to the 1265 RTCM
  message types.

  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  time : GPSTimeSec
    GNSS reference time of the correction
  sid : GnssSignal
    GNSS signal identifier (16 bit)
  update_interval : int
    Update interval between consecutive corrections. Encoded following RTCM
    DF391 specification.
  iod_ssr : int
    IOD of the SSR correction. A change of Issue Of Data SSR is used to
    indicate a change in the SSR generating configuration
  dispersive_bias : int
    Indicator for the dispersive phase biases property.
  mw_consistency : int
    Consistency indicator for Melbourne-Wubbena linear combinations
  yaw : int
    Satellite yaw angle
  yaw_rate : int
    Satellite yaw angle rate
  biases : array
    Phase biases corrections for a satellite being tracked.
  sender : int
    Optional sender ID, defaults to SENDER_ID (see sbp/msg.py).

  """
  _parser = construct.Struct(
                   'time' / GPSTimeSec._parser,
                   'sid' / GnssSignal._parser,
                   'update_interval' / construct.Int8ul,
                   'iod_ssr' / construct.Int8ul,
                   'dispersive_bias' / construct.Int8ul,
                   'mw_consistency' / construct.Int8ul,
                   'yaw' / construct.Int16ul,
                   'yaw_rate' / construct.Int8sl,
                   'biases' / construct.GreedyRange(PhaseBiasesContent._parser),)
  __slots__ = [
               'time',
               'sid',
               'update_interval',
               'iod_ssr',
               'dispersive_bias',
               'mw_consistency',
               'yaw',
               'yaw_rate',
               'biases',
              ]

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      super( MsgSsrPhaseBiases,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.from_binary(sbp.payload)
    else:
      super( MsgSsrPhaseBiases, self).__init__()
      self.msg_type = SBP_MSG_SSR_PHASE_BIASES
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.time = kwargs.pop('time')
      self.sid = kwargs.pop('sid')
      self.update_interval = kwargs.pop('update_interval')
      self.iod_ssr = kwargs.pop('iod_ssr')
      self.dispersive_bias = kwargs.pop('dispersive_bias')
      self.mw_consistency = kwargs.pop('mw_consistency')
      self.yaw = kwargs.pop('yaw')
      self.yaw_rate = kwargs.pop('yaw_rate')
      self.biases = kwargs.pop('biases')

  def __repr__(self):
    return fmt_repr(self)

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    return MsgSsrPhaseBiases.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgSsrPhaseBiases(sbp, **d)

 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgSsrPhaseBiases._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgSsrPhaseBiases._parser.build(c)
    return self.pack()

  def into_buffer(self, buf, offset):
    """Produce a framed/packed SBP message into the provided buffer and offset.

    """
    self.payload = containerize(exclude_fields(self))
    self.parser = MsgSsrPhaseBiases._parser
    self.stream_payload.reset(buf, offset)
    return self.pack_into(buf, offset, self._build_payload)

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgSsrPhaseBiases, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    
SBP_MSG_SSR_STEC_CORRECTION_DEP = 0x05FB
class MsgSsrStecCorrectionDep(SBP):
  """SBP class for message MSG_SSR_STEC_CORRECTION_DEP (0x05FB).

  You can have MSG_SSR_STEC_CORRECTION_DEP inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  The Slant Total Electron Content per space vehicle, given as polynomial
  approximation for a given tile. This should be combined with the
  MSG_SSR_GRIDDED_CORRECTION message to get the state space representation of
  the atmospheric delay.

  It is typically equivalent to the QZSS CLAS Sub Type 8 messages.

  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  header : STECHeader
    Header of a STEC polynomial coefficient message.
  stec_sat_list : array
    Array of STEC polynomial coefficients for each space vehicle.
  sender : int
    Optional sender ID, defaults to SENDER_ID (see sbp/msg.py).

  """
  _parser = construct.Struct(
                   'header' / STECHeader._parser,
                   'stec_sat_list' / construct.GreedyRange(STECSatElement._parser),)
  __slots__ = [
               'header',
               'stec_sat_list',
              ]

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      super( MsgSsrStecCorrectionDep,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.from_binary(sbp.payload)
    else:
      super( MsgSsrStecCorrectionDep, self).__init__()
      self.msg_type = SBP_MSG_SSR_STEC_CORRECTION_DEP
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.header = kwargs.pop('header')
      self.stec_sat_list = kwargs.pop('stec_sat_list')

  def __repr__(self):
    return fmt_repr(self)

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    return MsgSsrStecCorrectionDep.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgSsrStecCorrectionDep(sbp, **d)

 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgSsrStecCorrectionDep._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgSsrStecCorrectionDep._parser.build(c)
    return self.pack()

  def into_buffer(self, buf, offset):
    """Produce a framed/packed SBP message into the provided buffer and offset.

    """
    self.payload = containerize(exclude_fields(self))
    self.parser = MsgSsrStecCorrectionDep._parser
    self.stream_payload.reset(buf, offset)
    return self.pack_into(buf, offset, self._build_payload)

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgSsrStecCorrectionDep, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    
SBP_MSG_SSR_STEC_CORRECTION = 0x05FD
class MsgSsrStecCorrection(SBP):
  """SBP class for message MSG_SSR_STEC_CORRECTION (0x05FD).

  You can have MSG_SSR_STEC_CORRECTION inherit its fields directly
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
      super( MsgSsrStecCorrection,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.from_binary(sbp.payload)
    else:
      super( MsgSsrStecCorrection, self).__init__()
      self.msg_type = SBP_MSG_SSR_STEC_CORRECTION
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.stub = kwargs.pop('stub')

  def __repr__(self):
    return fmt_repr(self)

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    return MsgSsrStecCorrection.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgSsrStecCorrection(sbp, **d)

 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgSsrStecCorrection._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgSsrStecCorrection._parser.build(c)
    return self.pack()

  def into_buffer(self, buf, offset):
    """Produce a framed/packed SBP message into the provided buffer and offset.

    """
    self.payload = containerize(exclude_fields(self))
    self.parser = MsgSsrStecCorrection._parser
    self.stream_payload.reset(buf, offset)
    return self.pack_into(buf, offset, self._build_payload)

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgSsrStecCorrection, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    
SBP_MSG_SSR_GRIDDED_CORRECTION = 0x05FC
class MsgSsrGriddedCorrection(SBP):
  """SBP class for message MSG_SSR_GRIDDED_CORRECTION (0x05FC).

  You can have MSG_SSR_GRIDDED_CORRECTION inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  STEC residuals are per space vehicle, troposphere is not.

  It is typically equivalent to the QZSS CLAS Sub Type 9 messages.

  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  header : GriddedCorrectionHeader
    Header of a gridded correction message
  index : int
    Index of the grid point.
  tropo_delay_correction : TroposphericDelayCorrection
    Wet and hydrostatic vertical delays (mean, stddev).
  stec_residuals : array
    STEC residuals for each satellite (mean, stddev).
  sender : int
    Optional sender ID, defaults to SENDER_ID (see sbp/msg.py).

  """
  _parser = construct.Struct(
                   'header' / GriddedCorrectionHeader._parser,
                   'index' / construct.Int16ul,
                   'tropo_delay_correction' / TroposphericDelayCorrection._parser,
                   'stec_residuals' / construct.GreedyRange(STECResidual._parser),)
  __slots__ = [
               'header',
               'index',
               'tropo_delay_correction',
               'stec_residuals',
              ]

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      super( MsgSsrGriddedCorrection,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.from_binary(sbp.payload)
    else:
      super( MsgSsrGriddedCorrection, self).__init__()
      self.msg_type = SBP_MSG_SSR_GRIDDED_CORRECTION
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.header = kwargs.pop('header')
      self.index = kwargs.pop('index')
      self.tropo_delay_correction = kwargs.pop('tropo_delay_correction')
      self.stec_residuals = kwargs.pop('stec_residuals')

  def __repr__(self):
    return fmt_repr(self)

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    return MsgSsrGriddedCorrection.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgSsrGriddedCorrection(sbp, **d)

 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgSsrGriddedCorrection._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgSsrGriddedCorrection._parser.build(c)
    return self.pack()

  def into_buffer(self, buf, offset):
    """Produce a framed/packed SBP message into the provided buffer and offset.

    """
    self.payload = containerize(exclude_fields(self))
    self.parser = MsgSsrGriddedCorrection._parser
    self.stream_payload.reset(buf, offset)
    return self.pack_into(buf, offset, self._build_payload)

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgSsrGriddedCorrection, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    
SBP_MSG_SSR_GRIDDED_CORRECTION_BOUNDS = 0x05FE
class MsgSsrGriddedCorrectionBounds(SBP):
  """SBP class for message MSG_SSR_GRIDDED_CORRECTION_BOUNDS (0x05FE).

  You can have MSG_SSR_GRIDDED_CORRECTION_BOUNDS inherit its fields directly
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
      super( MsgSsrGriddedCorrectionBounds,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.from_binary(sbp.payload)
    else:
      super( MsgSsrGriddedCorrectionBounds, self).__init__()
      self.msg_type = SBP_MSG_SSR_GRIDDED_CORRECTION_BOUNDS
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.stub = kwargs.pop('stub')

  def __repr__(self):
    return fmt_repr(self)

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    return MsgSsrGriddedCorrectionBounds.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgSsrGriddedCorrectionBounds(sbp, **d)

 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgSsrGriddedCorrectionBounds._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgSsrGriddedCorrectionBounds._parser.build(c)
    return self.pack()

  def into_buffer(self, buf, offset):
    """Produce a framed/packed SBP message into the provided buffer and offset.

    """
    self.payload = containerize(exclude_fields(self))
    self.parser = MsgSsrGriddedCorrectionBounds._parser
    self.stream_payload.reset(buf, offset)
    return self.pack_into(buf, offset, self._build_payload)

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgSsrGriddedCorrectionBounds, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    
SBP_MSG_SSR_TILE_DEFINITION_DEP = 0x05F6
class MsgSsrTileDefinitionDep(SBP):
  """SBP class for message MSG_SSR_TILE_DEFINITION_DEP (0x05F6).

  You can have MSG_SSR_TILE_DEFINITION_DEP inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  Provides the correction point coordinates for the atmospheric correction
  values in the MSG_SSR_STEC_CORRECTION_DEP and MSG_SSR_GRIDDED_CORRECTION
  messages.

  Based on ETSI TS 137 355 V16.1.0 (LTE Positioning Protocol) information
  element GNSS-SSR-CorrectionPoints. SBP only supports gridded arrays of
  correction points, not lists of points.

  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  tile_set_id : int
    Unique identifier of the tile set this tile belongs to.
  tile_id : int
    Unique identifier of this tile in the tile set.
    See GNSS-SSR-ArrayOfCorrectionPoints field correctionPointSetID.
  corner_nw_lat : int
    North-West corner correction point latitude.

    The relation between the latitude X in the range [-90, 90] and the coded
    number N is:

    N = floor((X / 90) * 2^14)

    See GNSS-SSR-ArrayOfCorrectionPoints field referencePointLatitude.
  corner_nw_lon : int
    North-West corner correction point longitude.

    The relation between the longitude X in the range [-180, 180] and the
    coded number N is:

    N = floor((X / 180) * 2^15)

    See GNSS-SSR-ArrayOfCorrectionPoints field referencePointLongitude.
  spacing_lat : int
    Spacing of the correction points in the latitude direction.

    See GNSS-SSR-ArrayOfCorrectionPoints field stepOfLatitude.
  spacing_lon : int
    Spacing of the correction points in the longitude direction.

    See GNSS-SSR-ArrayOfCorrectionPoints field stepOfLongitude.
  rows : int
    Number of steps in the latitude direction.

    See GNSS-SSR-ArrayOfCorrectionPoints field numberOfStepsLatitude.
  cols : int
    Number of steps in the longitude direction.

    See GNSS-SSR-ArrayOfCorrectionPoints field numberOfStepsLongitude.
  bitmask : int
    Specifies the availability of correction data at the correction points in
    the array.

    If a specific bit is enabled (set to 1), the correction is not available.
    Only the first rows * cols bits are used, the remainder are set to 0. If
    there are more then 64 correction points the remaining corrections are
    always available.

    Starting with the northwest corner of the array (top left on a north
    oriented map) the correction points are enumerated with row precedence -
    first row west to east, second row west to east, until last row west to
    east - ending with the southeast corner of the array.

    See GNSS-SSR-ArrayOfCorrectionPoints field bitmaskOfGrids but note the
    definition of the bits is inverted.
  sender : int
    Optional sender ID, defaults to SENDER_ID (see sbp/msg.py).

  """
  _parser = construct.Struct(
                   'tile_set_id' / construct.Int16ul,
                   'tile_id' / construct.Int16ul,
                   'corner_nw_lat' / construct.Int16sl,
                   'corner_nw_lon' / construct.Int16sl,
                   'spacing_lat' / construct.Int16ul,
                   'spacing_lon' / construct.Int16ul,
                   'rows' / construct.Int16ul,
                   'cols' / construct.Int16ul,
                   'bitmask' / construct.Int64ul,)
  __slots__ = [
               'tile_set_id',
               'tile_id',
               'corner_nw_lat',
               'corner_nw_lon',
               'spacing_lat',
               'spacing_lon',
               'rows',
               'cols',
               'bitmask',
              ]

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      super( MsgSsrTileDefinitionDep,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.from_binary(sbp.payload)
    else:
      super( MsgSsrTileDefinitionDep, self).__init__()
      self.msg_type = SBP_MSG_SSR_TILE_DEFINITION_DEP
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.tile_set_id = kwargs.pop('tile_set_id')
      self.tile_id = kwargs.pop('tile_id')
      self.corner_nw_lat = kwargs.pop('corner_nw_lat')
      self.corner_nw_lon = kwargs.pop('corner_nw_lon')
      self.spacing_lat = kwargs.pop('spacing_lat')
      self.spacing_lon = kwargs.pop('spacing_lon')
      self.rows = kwargs.pop('rows')
      self.cols = kwargs.pop('cols')
      self.bitmask = kwargs.pop('bitmask')

  def __repr__(self):
    return fmt_repr(self)

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    return MsgSsrTileDefinitionDep.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgSsrTileDefinitionDep(sbp, **d)

 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgSsrTileDefinitionDep._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgSsrTileDefinitionDep._parser.build(c)
    return self.pack()

  def into_buffer(self, buf, offset):
    """Produce a framed/packed SBP message into the provided buffer and offset.

    """
    self.payload = containerize(exclude_fields(self))
    self.parser = MsgSsrTileDefinitionDep._parser
    self.stream_payload.reset(buf, offset)
    return self.pack_into(buf, offset, self._build_payload)

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgSsrTileDefinitionDep, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    
SBP_MSG_SSR_TILE_DEFINITION = 0x05F7
class MsgSsrTileDefinition(SBP):
  """SBP class for message MSG_SSR_TILE_DEFINITION (0x05F7).

  You can have MSG_SSR_TILE_DEFINITION inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  Provides the correction point coordinates for the atmospheric correction
  values in the MSG_SSR_STEC_CORRECTION and MSG_SSR_GRIDDED_CORRECTION
  messages.

  Based on ETSI TS 137 355 V16.1.0 (LTE Positioning Protocol) information
  element GNSS-SSR-CorrectionPoints. SBP only supports gridded arrays of
  correction points, not lists of points.

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
      super( MsgSsrTileDefinition,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.from_binary(sbp.payload)
    else:
      super( MsgSsrTileDefinition, self).__init__()
      self.msg_type = SBP_MSG_SSR_TILE_DEFINITION
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.stub = kwargs.pop('stub')

  def __repr__(self):
    return fmt_repr(self)

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    return MsgSsrTileDefinition.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgSsrTileDefinition(sbp, **d)

 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgSsrTileDefinition._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgSsrTileDefinition._parser.build(c)
    return self.pack()

  def into_buffer(self, buf, offset):
    """Produce a framed/packed SBP message into the provided buffer and offset.

    """
    self.payload = containerize(exclude_fields(self))
    self.parser = MsgSsrTileDefinition._parser
    self.stream_payload.reset(buf, offset)
    return self.pack_into(buf, offset, self._build_payload)

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgSsrTileDefinition, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    
SBP_MSG_SSR_SATELLITE_APC = 0x0604
class MsgSsrSatelliteApc(SBP):
  """SBP class for message MSG_SSR_SATELLITE_APC (0x0604).

  You can have MSG_SSR_SATELLITE_APC inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  

  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  apc : array
    Satellite antenna phase center corrections
  sender : int
    Optional sender ID, defaults to SENDER_ID (see sbp/msg.py).

  """
  _parser = construct.Struct(
                   'apc' / construct.GreedyRange(SatelliteAPC._parser),)
  __slots__ = [
               'apc',
              ]

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      super( MsgSsrSatelliteApc,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.from_binary(sbp.payload)
    else:
      super( MsgSsrSatelliteApc, self).__init__()
      self.msg_type = SBP_MSG_SSR_SATELLITE_APC
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.apc = kwargs.pop('apc')

  def __repr__(self):
    return fmt_repr(self)

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    return MsgSsrSatelliteApc.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgSsrSatelliteApc(sbp, **d)

 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgSsrSatelliteApc._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgSsrSatelliteApc._parser.build(c)
    return self.pack()

  def into_buffer(self, buf, offset):
    """Produce a framed/packed SBP message into the provided buffer and offset.

    """
    self.payload = containerize(exclude_fields(self))
    self.parser = MsgSsrSatelliteApc._parser
    self.stream_payload.reset(buf, offset)
    return self.pack_into(buf, offset, self._build_payload)

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgSsrSatelliteApc, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    
SBP_MSG_SSR_ORBIT_CLOCK_DEP_A = 0x05DC
class MsgSsrOrbitClockDepA(SBP):
  """SBP class for message MSG_SSR_ORBIT_CLOCK_DEP_A (0x05DC).

  You can have MSG_SSR_ORBIT_CLOCK_DEP_A inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  

  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  time : GPSTimeSec
    GNSS reference time of the correction
  sid : GnssSignal
    GNSS signal identifier (16 bit)
  update_interval : int
    Update interval between consecutive corrections. Encoded following RTCM
    DF391 specification.
  iod_ssr : int
    IOD of the SSR correction. A change of Issue Of Data SSR is used to
    indicate a change in the SSR generating configuration
  iod : int
    Issue of broadcast ephemeris data
  radial : int
    Orbit radial delta correction
  along : int
    Orbit along delta correction
  cross : int
    Orbit along delta correction
  dot_radial : int
    Velocity of orbit radial delta correction
  dot_along : int
    Velocity of orbit along delta correction
  dot_cross : int
    Velocity of orbit cross delta correction
  c0 : int
    C0 polynomial coefficient for correction of broadcast satellite clock
  c1 : int
    C1 polynomial coefficient for correction of broadcast satellite clock
  c2 : int
    C2 polynomial coefficient for correction of broadcast satellite clock
  sender : int
    Optional sender ID, defaults to SENDER_ID (see sbp/msg.py).

  """
  _parser = construct.Struct(
                   'time' / GPSTimeSec._parser,
                   'sid' / GnssSignal._parser,
                   'update_interval' / construct.Int8ul,
                   'iod_ssr' / construct.Int8ul,
                   'iod' / construct.Int8ul,
                   'radial' / construct.Int32sl,
                   'along' / construct.Int32sl,
                   'cross' / construct.Int32sl,
                   'dot_radial' / construct.Int32sl,
                   'dot_along' / construct.Int32sl,
                   'dot_cross' / construct.Int32sl,
                   'c0' / construct.Int32sl,
                   'c1' / construct.Int32sl,
                   'c2' / construct.Int32sl,)
  __slots__ = [
               'time',
               'sid',
               'update_interval',
               'iod_ssr',
               'iod',
               'radial',
               'along',
               'cross',
               'dot_radial',
               'dot_along',
               'dot_cross',
               'c0',
               'c1',
               'c2',
              ]

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      super( MsgSsrOrbitClockDepA,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.from_binary(sbp.payload)
    else:
      super( MsgSsrOrbitClockDepA, self).__init__()
      self.msg_type = SBP_MSG_SSR_ORBIT_CLOCK_DEP_A
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.time = kwargs.pop('time')
      self.sid = kwargs.pop('sid')
      self.update_interval = kwargs.pop('update_interval')
      self.iod_ssr = kwargs.pop('iod_ssr')
      self.iod = kwargs.pop('iod')
      self.radial = kwargs.pop('radial')
      self.along = kwargs.pop('along')
      self.cross = kwargs.pop('cross')
      self.dot_radial = kwargs.pop('dot_radial')
      self.dot_along = kwargs.pop('dot_along')
      self.dot_cross = kwargs.pop('dot_cross')
      self.c0 = kwargs.pop('c0')
      self.c1 = kwargs.pop('c1')
      self.c2 = kwargs.pop('c2')

  def __repr__(self):
    return fmt_repr(self)

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    return MsgSsrOrbitClockDepA.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgSsrOrbitClockDepA(sbp, **d)

 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgSsrOrbitClockDepA._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgSsrOrbitClockDepA._parser.build(c)
    return self.pack()

  def into_buffer(self, buf, offset):
    """Produce a framed/packed SBP message into the provided buffer and offset.

    """
    self.payload = containerize(exclude_fields(self))
    self.parser = MsgSsrOrbitClockDepA._parser
    self.stream_payload.reset(buf, offset)
    return self.pack_into(buf, offset, self._build_payload)

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgSsrOrbitClockDepA, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    
SBP_MSG_SSR_STEC_CORRECTION_DEP_A = 0x05EB
class MsgSsrStecCorrectionDepA(SBP):
  """SBP class for message MSG_SSR_STEC_CORRECTION_DEP_A (0x05EB).

  You can have MSG_SSR_STEC_CORRECTION_DEP_A inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  

  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  header : STECHeaderDepA
    Header of a STEC message
  stec_sat_list : array
    Array of STEC information for each space vehicle
  sender : int
    Optional sender ID, defaults to SENDER_ID (see sbp/msg.py).

  """
  _parser = construct.Struct(
                   'header' / STECHeaderDepA._parser,
                   'stec_sat_list' / construct.GreedyRange(STECSatElement._parser),)
  __slots__ = [
               'header',
               'stec_sat_list',
              ]

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      super( MsgSsrStecCorrectionDepA,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.from_binary(sbp.payload)
    else:
      super( MsgSsrStecCorrectionDepA, self).__init__()
      self.msg_type = SBP_MSG_SSR_STEC_CORRECTION_DEP_A
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.header = kwargs.pop('header')
      self.stec_sat_list = kwargs.pop('stec_sat_list')

  def __repr__(self):
    return fmt_repr(self)

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    return MsgSsrStecCorrectionDepA.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgSsrStecCorrectionDepA(sbp, **d)

 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgSsrStecCorrectionDepA._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgSsrStecCorrectionDepA._parser.build(c)
    return self.pack()

  def into_buffer(self, buf, offset):
    """Produce a framed/packed SBP message into the provided buffer and offset.

    """
    self.payload = containerize(exclude_fields(self))
    self.parser = MsgSsrStecCorrectionDepA._parser
    self.stream_payload.reset(buf, offset)
    return self.pack_into(buf, offset, self._build_payload)

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgSsrStecCorrectionDepA, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    
SBP_MSG_SSR_GRIDDED_CORRECTION_NO_STD_DEP_A = 0x05F0
class MsgSsrGriddedCorrectionNoStdDepA(SBP):
  """SBP class for message MSG_SSR_GRIDDED_CORRECTION_NO_STD_DEP_A (0x05F0).

  You can have MSG_SSR_GRIDDED_CORRECTION_NO_STD_DEP_A inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  

  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  header : GriddedCorrectionHeaderDepA
    Header of a Gridded Correction message
  index : int
    Index of the grid point
  tropo_delay_correction : TroposphericDelayCorrectionNoStd
    Wet and hydrostatic vertical delays
  stec_residuals : array
    STEC residuals for each satellite
  sender : int
    Optional sender ID, defaults to SENDER_ID (see sbp/msg.py).

  """
  _parser = construct.Struct(
                   'header' / GriddedCorrectionHeaderDepA._parser,
                   'index' / construct.Int16ul,
                   'tropo_delay_correction' / TroposphericDelayCorrectionNoStd._parser,
                   'stec_residuals' / construct.GreedyRange(STECResidualNoStd._parser),)
  __slots__ = [
               'header',
               'index',
               'tropo_delay_correction',
               'stec_residuals',
              ]

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      super( MsgSsrGriddedCorrectionNoStdDepA,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.from_binary(sbp.payload)
    else:
      super( MsgSsrGriddedCorrectionNoStdDepA, self).__init__()
      self.msg_type = SBP_MSG_SSR_GRIDDED_CORRECTION_NO_STD_DEP_A
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.header = kwargs.pop('header')
      self.index = kwargs.pop('index')
      self.tropo_delay_correction = kwargs.pop('tropo_delay_correction')
      self.stec_residuals = kwargs.pop('stec_residuals')

  def __repr__(self):
    return fmt_repr(self)

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    return MsgSsrGriddedCorrectionNoStdDepA.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgSsrGriddedCorrectionNoStdDepA(sbp, **d)

 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgSsrGriddedCorrectionNoStdDepA._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgSsrGriddedCorrectionNoStdDepA._parser.build(c)
    return self.pack()

  def into_buffer(self, buf, offset):
    """Produce a framed/packed SBP message into the provided buffer and offset.

    """
    self.payload = containerize(exclude_fields(self))
    self.parser = MsgSsrGriddedCorrectionNoStdDepA._parser
    self.stream_payload.reset(buf, offset)
    return self.pack_into(buf, offset, self._build_payload)

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgSsrGriddedCorrectionNoStdDepA, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    
SBP_MSG_SSR_GRIDDED_CORRECTION_DEP_A = 0x05FA
class MsgSsrGriddedCorrectionDepA(SBP):
  """SBP class for message MSG_SSR_GRIDDED_CORRECTION_DEP_A (0x05FA).

  You can have MSG_SSR_GRIDDED_CORRECTION_DEP_A inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  

  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  header : GriddedCorrectionHeaderDepA
    Header of a Gridded Correction message
  index : int
    Index of the grid point
  tropo_delay_correction : TroposphericDelayCorrection
    Wet and hydrostatic vertical delays (mean, stddev)
  stec_residuals : array
    STEC residuals for each satellite (mean, stddev)
  sender : int
    Optional sender ID, defaults to SENDER_ID (see sbp/msg.py).

  """
  _parser = construct.Struct(
                   'header' / GriddedCorrectionHeaderDepA._parser,
                   'index' / construct.Int16ul,
                   'tropo_delay_correction' / TroposphericDelayCorrection._parser,
                   'stec_residuals' / construct.GreedyRange(STECResidual._parser),)
  __slots__ = [
               'header',
               'index',
               'tropo_delay_correction',
               'stec_residuals',
              ]

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      super( MsgSsrGriddedCorrectionDepA,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.from_binary(sbp.payload)
    else:
      super( MsgSsrGriddedCorrectionDepA, self).__init__()
      self.msg_type = SBP_MSG_SSR_GRIDDED_CORRECTION_DEP_A
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.header = kwargs.pop('header')
      self.index = kwargs.pop('index')
      self.tropo_delay_correction = kwargs.pop('tropo_delay_correction')
      self.stec_residuals = kwargs.pop('stec_residuals')

  def __repr__(self):
    return fmt_repr(self)

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    return MsgSsrGriddedCorrectionDepA.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgSsrGriddedCorrectionDepA(sbp, **d)

 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgSsrGriddedCorrectionDepA._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgSsrGriddedCorrectionDepA._parser.build(c)
    return self.pack()

  def into_buffer(self, buf, offset):
    """Produce a framed/packed SBP message into the provided buffer and offset.

    """
    self.payload = containerize(exclude_fields(self))
    self.parser = MsgSsrGriddedCorrectionDepA._parser
    self.stream_payload.reset(buf, offset)
    return self.pack_into(buf, offset, self._build_payload)

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgSsrGriddedCorrectionDepA, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    
SBP_MSG_SSR_GRID_DEFINITION_DEP_A = 0x05F5
class MsgSsrGridDefinitionDepA(SBP):
  """SBP class for message MSG_SSR_GRID_DEFINITION_DEP_A (0x05F5).

  You can have MSG_SSR_GRID_DEFINITION_DEP_A inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  

  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  header : GridDefinitionHeaderDepA
    Header of a Gridded Correction message
  rle_list : array
    Run Length Encode list of quadrants that contain valid data. The spec
    describes the encoding scheme in detail, but essentially the index of the
    quadrants that contain transitions between valid and invalid (and vice
    versa) are encoded as u8 integers.
  sender : int
    Optional sender ID, defaults to SENDER_ID (see sbp/msg.py).

  """
  _parser = construct.Struct(
                   'header' / GridDefinitionHeaderDepA._parser,
                   'rle_list' / construct.GreedyRange(construct.Int8ul),)
  __slots__ = [
               'header',
               'rle_list',
              ]

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      super( MsgSsrGridDefinitionDepA,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.from_binary(sbp.payload)
    else:
      super( MsgSsrGridDefinitionDepA, self).__init__()
      self.msg_type = SBP_MSG_SSR_GRID_DEFINITION_DEP_A
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.header = kwargs.pop('header')
      self.rle_list = kwargs.pop('rle_list')

  def __repr__(self):
    return fmt_repr(self)

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    return MsgSsrGridDefinitionDepA.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgSsrGridDefinitionDepA(sbp, **d)

 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgSsrGridDefinitionDepA._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgSsrGridDefinitionDepA._parser.build(c)
    return self.pack()

  def into_buffer(self, buf, offset):
    """Produce a framed/packed SBP message into the provided buffer and offset.

    """
    self.payload = containerize(exclude_fields(self))
    self.parser = MsgSsrGridDefinitionDepA._parser
    self.stream_payload.reset(buf, offset)
    return self.pack_into(buf, offset, self._build_payload)

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgSsrGridDefinitionDepA, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    
SBP_MSG_SSR_ORBIT_CLOCK_BOUNDS = 0x05DE
class MsgSsrOrbitClockBounds(SBP):
  """SBP class for message MSG_SSR_ORBIT_CLOCK_BOUNDS (0x05DE).

  You can have MSG_SSR_ORBIT_CLOCK_BOUNDS inherit its fields directly
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
      super( MsgSsrOrbitClockBounds,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.from_binary(sbp.payload)
    else:
      super( MsgSsrOrbitClockBounds, self).__init__()
      self.msg_type = SBP_MSG_SSR_ORBIT_CLOCK_BOUNDS
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.stub = kwargs.pop('stub')

  def __repr__(self):
    return fmt_repr(self)

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    return MsgSsrOrbitClockBounds.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgSsrOrbitClockBounds(sbp, **d)

 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgSsrOrbitClockBounds._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgSsrOrbitClockBounds._parser.build(c)
    return self.pack()

  def into_buffer(self, buf, offset):
    """Produce a framed/packed SBP message into the provided buffer and offset.

    """
    self.payload = containerize(exclude_fields(self))
    self.parser = MsgSsrOrbitClockBounds._parser
    self.stream_payload.reset(buf, offset)
    return self.pack_into(buf, offset, self._build_payload)

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgSsrOrbitClockBounds, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    
SBP_MSG_SSR_CODE_PHASE_BIASES_BOUNDS = 0x05EC
class MsgSsrCodePhaseBiasesBounds(SBP):
  """SBP class for message MSG_SSR_CODE_PHASE_BIASES_BOUNDS (0x05EC).

  You can have MSG_SSR_CODE_PHASE_BIASES_BOUNDS inherit its fields directly
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
      super( MsgSsrCodePhaseBiasesBounds,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.from_binary(sbp.payload)
    else:
      super( MsgSsrCodePhaseBiasesBounds, self).__init__()
      self.msg_type = SBP_MSG_SSR_CODE_PHASE_BIASES_BOUNDS
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.stub = kwargs.pop('stub')

  def __repr__(self):
    return fmt_repr(self)

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    return MsgSsrCodePhaseBiasesBounds.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgSsrCodePhaseBiasesBounds(sbp, **d)

 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgSsrCodePhaseBiasesBounds._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgSsrCodePhaseBiasesBounds._parser.build(c)
    return self.pack()

  def into_buffer(self, buf, offset):
    """Produce a framed/packed SBP message into the provided buffer and offset.

    """
    self.payload = containerize(exclude_fields(self))
    self.parser = MsgSsrCodePhaseBiasesBounds._parser
    self.stream_payload.reset(buf, offset)
    return self.pack_into(buf, offset, self._build_payload)

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgSsrCodePhaseBiasesBounds, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    
SBP_MSG_SSR_ORBIT_CLOCK_BOUNDS_DEGRADATION = 0x05DF
class MsgSsrOrbitClockBoundsDegradation(SBP):
  """SBP class for message MSG_SSR_ORBIT_CLOCK_BOUNDS_DEGRADATION (0x05DF).

  You can have MSG_SSR_ORBIT_CLOCK_BOUNDS_DEGRADATION inherit its fields directly
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
      super( MsgSsrOrbitClockBoundsDegradation,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.from_binary(sbp.payload)
    else:
      super( MsgSsrOrbitClockBoundsDegradation, self).__init__()
      self.msg_type = SBP_MSG_SSR_ORBIT_CLOCK_BOUNDS_DEGRADATION
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.stub = kwargs.pop('stub')

  def __repr__(self):
    return fmt_repr(self)

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    return MsgSsrOrbitClockBoundsDegradation.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgSsrOrbitClockBoundsDegradation(sbp, **d)

 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgSsrOrbitClockBoundsDegradation._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgSsrOrbitClockBoundsDegradation._parser.build(c)
    return self.pack()

  def into_buffer(self, buf, offset):
    """Produce a framed/packed SBP message into the provided buffer and offset.

    """
    self.payload = containerize(exclude_fields(self))
    self.parser = MsgSsrOrbitClockBoundsDegradation._parser
    self.stream_payload.reset(buf, offset)
    return self.pack_into(buf, offset, self._build_payload)

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgSsrOrbitClockBoundsDegradation, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    

msg_classes = {
  0x05DD: MsgSsrOrbitClock,
  0x05E1: MsgSsrCodeBiases,
  0x05E6: MsgSsrPhaseBiases,
  0x05FB: MsgSsrStecCorrectionDep,
  0x05FD: MsgSsrStecCorrection,
  0x05FC: MsgSsrGriddedCorrection,
  0x05FE: MsgSsrGriddedCorrectionBounds,
  0x05F6: MsgSsrTileDefinitionDep,
  0x05F7: MsgSsrTileDefinition,
  0x0604: MsgSsrSatelliteApc,
  0x05DC: MsgSsrOrbitClockDepA,
  0x05EB: MsgSsrStecCorrectionDepA,
  0x05F0: MsgSsrGriddedCorrectionNoStdDepA,
  0x05FA: MsgSsrGriddedCorrectionDepA,
  0x05F5: MsgSsrGridDefinitionDepA,
  0x05DE: MsgSsrOrbitClockBounds,
  0x05EC: MsgSsrCodePhaseBiasesBounds,
  0x05DF: MsgSsrOrbitClockBoundsDegradation,
}