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
Precise State Space Representation (SSR) corrections format
"""

import json

import construct

from sbp.msg import SBP, SENDER_ID
from sbp.utils import fmt_repr, exclude_fields, walk_json_dict, containerize
from sbp.gnss import *

# Automatically generated from piksi/yaml/swiftnav/sbp/ssr.yaml with generate.py.
# Please do not hand edit!


class CodeBiasesContent(object):
  """CodeBiasesContent.
  
  Code biases are to be added to pseudorange.
The corrections conform with typical RTCMv3 MT1059 and 1065.

  
  Parameters
  ----------
  code : int
    Signal constellation, band and code
  value : int
    Code bias value

  """
  _parser = construct.Embedded(construct.Struct(
                     'code' / construct.Int8ul,
                     'value' / construct.Int16sl,))
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

  def to_binary(self):
    d = dict([(k, getattr(obj, k)) for k in self.__slots__])
    return CodeBiasesContent.build(d)
    
class PhaseBiasesContent(object):
  """PhaseBiasesContent.
  
  Phase biases are to be added to carrier phase measurements.
The corrections conform with typical RTCMv3 MT1059 and 1065.

  
  Parameters
  ----------
  code : int
    Signal constellation, band and code
  integer_indicator : int
    Indicator for integer property
  widelane_integer_indicator : int
    Indicator for two groups of Wide-Lane(s) integer property
  discontinuity_counter : int
    Signal phase discontinuity counter.
Increased for every discontinuity in phase.

  bias : int
    Phase bias for specified signal

  """
  _parser = construct.Embedded(construct.Struct(
                     'code' / construct.Int8ul,
                     'integer_indicator' / construct.Int8ul,
                     'widelane_integer_indicator' / construct.Int8ul,
                     'discontinuity_counter' / construct.Int8ul,
                     'bias' / construct.Int32sl,))
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

  def to_binary(self):
    d = dict([(k, getattr(obj, k)) for k in self.__slots__])
    return PhaseBiasesContent.build(d)
    
class STECHeader(object):
  """STECHeader.
  
  A full set of STEC information will likely span multiple SBP
messages, since SBP message a limited to 255 bytes.  The header
is used to tie multiple SBP messages into a sequence.

  
  Parameters
  ----------
  time : GPSTimeSec
    GNSS reference time of the correction
  num_msgs : int
    Number of messages in the dataset
  seq_num : int
    Position of this message in the dataset
  update_interval : int
    Update interval between consecutive corrections. Encoded
following RTCM DF391 specification.

  iod_atmo : int
    IOD of the SSR atmospheric correction


  """
  _parser = construct.Embedded(construct.Struct(
                     'time' / construct.Struct(GPSTimeSec._parser),
                     'num_msgs' / construct.Int8ul,
                     'seq_num' / construct.Int8ul,
                     'update_interval' / construct.Int8ul,
                     'iod_atmo' / construct.Int8ul,))
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
    p = STECHeader._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    d = dict([(k, getattr(obj, k)) for k in self.__slots__])
    return STECHeader.build(d)
    
class GriddedCorrectionHeader(object):
  """GriddedCorrectionHeader.
  
  The 3GPP message contains nested variable length arrays
which are not suppported in SBP, so each grid point will
be identified by the index.

  
  Parameters
  ----------
  time : GPSTimeSec
    GNSS reference time of the correction
  num_msgs : int
    Number of messages in the dataset
  seq_num : int
    Position of this message in the dataset
  update_interval : int
    Update interval between consecutive corrections. Encoded
following RTCM DF391 specification.

  iod_atmo : int
    IOD of the SSR atmospheric correction

  tropo_quality_indicator : int
    Quality of the troposphere data. Encoded following RTCM DF389
specifcation in units of m.


  """
  _parser = construct.Embedded(construct.Struct(
                     'time' / construct.Struct(GPSTimeSec._parser),
                     'num_msgs' / construct.Int16ul,
                     'seq_num' / construct.Int16ul,
                     'update_interval' / construct.Int8ul,
                     'iod_atmo' / construct.Int8ul,
                     'tropo_quality_indicator' / construct.Int8ul,))
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
    p = GriddedCorrectionHeader._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    d = dict([(k, getattr(obj, k)) for k in self.__slots__])
    return GriddedCorrectionHeader.build(d)
    
class STECSatElement(object):
  """STECSatElement.
  
  STEC polynomial for the given satellite.
  
  Parameters
  ----------
  sv_id : SvId
    Unique space vehicle identifier
  stec_quality_indicator : int
    Quality of the STEC data. Encoded following RTCM DF389 specifcation
but in units of TECU instead of m.

  stec_coeff : array
    Coefficents of the STEC polynomial in the order of C00, C01, C10, C11


  """
  _parser = construct.Embedded(construct.Struct(
                     'sv_id' / construct.Struct(SvId._parser),
                     'stec_quality_indicator' / construct.Int8ul,
                     'stec_coeff' / construct.Array(4, construct.Int16sl),))
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

  def to_binary(self):
    d = dict([(k, getattr(obj, k)) for k in self.__slots__])
    return STECSatElement.build(d)
    
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
  _parser = construct.Embedded(construct.Struct(
                     'hydro' / construct.Int16sl,
                     'wet' / construct.Int8sl,))
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

  def to_binary(self):
    d = dict([(k, getattr(obj, k)) for k in self.__slots__])
    return TroposphericDelayCorrectionNoStd.build(d)
    
class TroposphericDelayCorrection(object):
  """TroposphericDelayCorrection.
  
  Troposphere vertical delays (mean and standard deviation) at the grid
point.

  
  Parameters
  ----------
  hydro : int
    Hydrostatic vertical delay
  wet : int
    Wet vertical delay
  stddev : int
    stddev

  """
  _parser = construct.Embedded(construct.Struct(
                     'hydro' / construct.Int16sl,
                     'wet' / construct.Int8sl,
                     'stddev' / construct.Int8ul,))
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

  def to_binary(self):
    d = dict([(k, getattr(obj, k)) for k in self.__slots__])
    return TroposphericDelayCorrection.build(d)
    
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
  _parser = construct.Embedded(construct.Struct(
                     'sv_id' / construct.Struct(SvId._parser),
                     'residual' / construct.Int16sl,))
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

  def to_binary(self):
    d = dict([(k, getattr(obj, k)) for k in self.__slots__])
    return STECResidualNoStd.build(d)
    
class STECResidual(object):
  """STECResidual.
  
  STEC residual (mean and standard deviation) for the given satellite
at the grid point,

  
  Parameters
  ----------
  sv_id : SvId
    space vehicle identifier
  residual : int
    STEC residual
  stddev : int
    stddev

  """
  _parser = construct.Embedded(construct.Struct(
                     'sv_id' / construct.Struct(SvId._parser),
                     'residual' / construct.Int16sl,
                     'stddev' / construct.Int8ul,))
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

  def to_binary(self):
    d = dict([(k, getattr(obj, k)) for k in self.__slots__])
    return STECResidual.build(d)
    
class GridElementNoStd(object):
  """GridElementNoStd.
  
  Contains one tropo delay, plus STEC residuals for each satellite at the
grid point.

  
  Parameters
  ----------
  index : int
    Index of the grid point
  tropo_delay_correction : TroposphericDelayCorrectionNoStd
    Wet and hydrostatic vertical delays
  stec_residuals : array
    STEC residuals for each satellite

  """
  _parser = construct.Embedded(construct.Struct(
                     'index' / construct.Int16ul,
                     'tropo_delay_correction' / construct.Struct(TroposphericDelayCorrectionNoStd._parser),
                     construct.GreedyRange('stec_residuals' / construct.Struct(STECResidualNoStd._parser)),))
  __slots__ = [
               'index',
               'tropo_delay_correction',
               'stec_residuals',
              ]

  def __init__(self, payload=None, **kwargs):
    if payload:
      self.from_binary(payload)
    else:
      self.index = kwargs.pop('index')
      self.tropo_delay_correction = kwargs.pop('tropo_delay_correction')
      self.stec_residuals = kwargs.pop('stec_residuals')

  def __repr__(self):
    return fmt_repr(self)
  
  def from_binary(self, d):
    p = GridElementNoStd._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    d = dict([(k, getattr(obj, k)) for k in self.__slots__])
    return GridElementNoStd.build(d)
    
class GridElement(object):
  """GridElement.
  
  Contains one tropo delay (mean and stddev), plus STEC residuals (mean and
stddev) for each satellite at the grid point.

  
  Parameters
  ----------
  index : int
    Index of the grid point
  tropo_delay_correction : TroposphericDelayCorrection
    Wet and hydrostatic vertical delays (mean, stddev)
  stec_residuals : array
    STEC residuals for each satellite (mean, stddev)

  """
  _parser = construct.Embedded(construct.Struct(
                     'index' / construct.Int16ul,
                     'tropo_delay_correction' / construct.Struct(TroposphericDelayCorrection._parser),
                     construct.GreedyRange('stec_residuals' / construct.Struct(STECResidual._parser)),))
  __slots__ = [
               'index',
               'tropo_delay_correction',
               'stec_residuals',
              ]

  def __init__(self, payload=None, **kwargs):
    if payload:
      self.from_binary(payload)
    else:
      self.index = kwargs.pop('index')
      self.tropo_delay_correction = kwargs.pop('tropo_delay_correction')
      self.stec_residuals = kwargs.pop('stec_residuals')

  def __repr__(self):
    return fmt_repr(self)
  
  def from_binary(self, d):
    p = GridElement._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    d = dict([(k, getattr(obj, k)) for k in self.__slots__])
    return GridElement.build(d)
    
class GridDefinitionHeader(object):
  """GridDefinitionHeader.
  
  Defines the grid for MSG_SSR_GRIDDED_CORRECTION messages.
Also includes an RLE encoded validity list.

  
  Parameters
  ----------
  region_size_inverse : int
    region_size (deg) = 10 / region_size_inverse
0 is an invalid value.

  area_width : int
    grid height (deg) = grid idth (deg) = area_width / region_size
0 is an invalid value.

  lat_nw_corner_enc : int
    North-West corner latitdue (deg) = region_size * lat_nw_corner_enc - 90
  lon_nw_corner_enc : int
    North-West corner longtitude (deg) = region_size * lon_nw_corner_enc - 180
  num_msgs : int
    Number of messages in the dataset
  seq_num : int
    Postion of this message in the dataset

  """
  _parser = construct.Embedded(construct.Struct(
                     'region_size_inverse' / construct.Int8ul,
                     'area_width' / construct.Int16ul,
                     'lat_nw_corner_enc' / construct.Int16ul,
                     'lon_nw_corner_enc' / construct.Int16ul,
                     'num_msgs' / construct.Int8ul,
                     'seq_num' / construct.Int8ul,))
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
    p = GridDefinitionHeader._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    d = dict([(k, getattr(obj, k)) for k in self.__slots__])
    return GridDefinitionHeader.build(d)
    
SBP_MSG_SSR_ORBIT_CLOCK = 0x05DD
class MsgSsrOrbitClock(SBP):
  """SBP class for message MSG_SSR_ORBIT_CLOCK (0x05DD).

  You can have MSG_SSR_ORBIT_CLOCK inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  The precise orbit and clock correction message is
to be applied as a delta correction to broadcast
ephemeris and is typically an equivalent to the 1060
and 1066 RTCM message types


  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  time : GPSTimeSec
    GNSS reference time of the correction
  sid : GnssSignal
    GNSS signal identifier (16 bit)
  update_interval : int
    Update interval between consecutive corrections. Encoded
following RTCM DF391 specification.

  iod_ssr : int
    IOD of the SSR correction. A change of Issue Of Data
SSR is used to indicate a change in the SSR
generating configuration

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
                   'time' / construct.Struct(GPSTimeSec._parser),
                   'sid' / construct.Struct(GnssSignal._parser),
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
    
SBP_MSG_SSR_ORBIT_CLOCK_DEP_A = 0x05DC
class MsgSsrOrbitClockDepA(SBP):
  """SBP class for message MSG_SSR_ORBIT_CLOCK_DEP_A (0x05DC).

  You can have MSG_SSR_ORBIT_CLOCK_DEP_A inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  The precise orbit and clock correction message is
to be applied as a delta correction to broadcast
ephemeris and is typically an equivalent to the 1060
and 1066 RTCM message types


  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  time : GPSTimeSec
    GNSS reference time of the correction
  sid : GnssSignal
    GNSS signal identifier (16 bit)
  update_interval : int
    Update interval between consecutive corrections. Encoded
following RTCM DF391 specification.

  iod_ssr : int
    IOD of the SSR correction. A change of Issue Of Data
SSR is used to indicate a change in the SSR
generating configuration

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
                   'time' / construct.Struct(GPSTimeSec._parser),
                   'sid' / construct.Struct(GnssSignal._parser),
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
    
SBP_MSG_SSR_CODE_BIASES = 0x05E1
class MsgSsrCodeBiases(SBP):
  """SBP class for message MSG_SSR_CODE_BIASES (0x05E1).

  You can have MSG_SSR_CODE_BIASES inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  The precise code biases message is to be added
to the pseudorange of the corresponding signal
to get corrected pseudorange. It is typically
an equivalent to the 1059 and 1065 RTCM message types


  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  time : GPSTimeSec
    GNSS reference time of the correction
  sid : GnssSignal
    GNSS signal identifier (16 bit)
  update_interval : int
    Update interval between consecutive corrections. Encoded
following RTCM DF391 specification.

  iod_ssr : int
    IOD of the SSR correction. A change of Issue Of Data
SSR is used to indicate a change in the SSR
generating configuration

  biases : array
    Code biases for the different satellite signals
  sender : int
    Optional sender ID, defaults to SENDER_ID (see sbp/msg.py).

  """
  _parser = construct.Struct(
                   'time' / construct.Struct(GPSTimeSec._parser),
                   'sid' / construct.Struct(GnssSignal._parser),
                   'update_interval' / construct.Int8ul,
                   'iod_ssr' / construct.Int8ul,
                   construct.GreedyRange('biases' / construct.Struct(CodeBiasesContent._parser)),)
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

  
  The precise phase biases message contains the biases
to be added to the carrier phase of the corresponding
signal to get corrected carrier phase measurement, as
well as the satellite yaw angle to be applied to compute
the phase wind-up correction.
It is typically an equivalent to the 1265 RTCM message types


  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  time : GPSTimeSec
    GNSS reference time of the correction
  sid : GnssSignal
    GNSS signal identifier (16 bit)
  update_interval : int
    Update interval between consecutive corrections. Encoded
following RTCM DF391 specification.

  iod_ssr : int
    IOD of the SSR correction. A change of Issue Of Data
SSR is used to indicate a change in the SSR
generating configuration

  dispersive_bias : int
    Indicator for the dispersive phase biases property.

  mw_consistency : int
    Consistency indicator for Melbourne-Wubbena linear combinations

  yaw : int
    Satellite yaw angle
  yaw_rate : int
    Satellite yaw angle rate
  biases : array
    Phase biases corrections for a
satellite being tracked.

  sender : int
    Optional sender ID, defaults to SENDER_ID (see sbp/msg.py).

  """
  _parser = construct.Struct(
                   'time' / construct.Struct(GPSTimeSec._parser),
                   'sid' / construct.Struct(GnssSignal._parser),
                   'update_interval' / construct.Int8ul,
                   'iod_ssr' / construct.Int8ul,
                   'dispersive_bias' / construct.Int8ul,
                   'mw_consistency' / construct.Int8ul,
                   'yaw' / construct.Int16ul,
                   'yaw_rate' / construct.Int8sl,
                   construct.GreedyRange('biases' / construct.Struct(PhaseBiasesContent._parser)),)
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
    
SBP_MSG_SSR_STEC_CORRECTION = 0x05EB
class MsgSsrStecCorrection(SBP):
  """SBP class for message MSG_SSR_STEC_CORRECTION (0x05EB).

  You can have MSG_SSR_STEC_CORRECTION inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  The STEC per space vehicle, given as polynomial approximation for
a given grid.  This should be combined with MSG_SSR_GRIDDED_CORRECTION
message to get the state space representation of the atmospheric
delay. It is typically equivalent to the QZSS CLAS Sub Type 8 messages


  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  header : STECHeader
    Header of a STEC message
  stec_sat_list : array
    Array of STEC information for each space vehicle
  sender : int
    Optional sender ID, defaults to SENDER_ID (see sbp/msg.py).

  """
  _parser = construct.Struct(
                   'header' / construct.Struct(STECHeader._parser),
                   construct.GreedyRange('stec_sat_list' / construct.Struct(STECSatElement._parser)),)
  __slots__ = [
               'header',
               'stec_sat_list',
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
      self.header = kwargs.pop('header')
      self.stec_sat_list = kwargs.pop('stec_sat_list')

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
    
SBP_MSG_SSR_GRIDDED_CORRECTION_NO_STD = 0x05F0
class MsgSsrGriddedCorrectionNoStd(SBP):
  """SBP class for message MSG_SSR_GRIDDED_CORRECTION_NO_STD (0x05F0).

  You can have MSG_SSR_GRIDDED_CORRECTION_NO_STD inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  This message was deprecated when variances (stddev)
were added.


  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  header : GriddedCorrectionHeader
    Header of a Gridded Correction message
  element : GridElementNoStd
    Tropo and STEC residuals for the given grid point
  sender : int
    Optional sender ID, defaults to SENDER_ID (see sbp/msg.py).

  """
  _parser = construct.Struct(
                   'header' / construct.Struct(GriddedCorrectionHeader._parser),
                   'element' / construct.Struct(GridElementNoStd._parser),)
  __slots__ = [
               'header',
               'element',
              ]

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      super( MsgSsrGriddedCorrectionNoStd,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.from_binary(sbp.payload)
    else:
      super( MsgSsrGriddedCorrectionNoStd, self).__init__()
      self.msg_type = SBP_MSG_SSR_GRIDDED_CORRECTION_NO_STD
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.header = kwargs.pop('header')
      self.element = kwargs.pop('element')

  def __repr__(self):
    return fmt_repr(self)

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    return MsgSsrGriddedCorrectionNoStd.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgSsrGriddedCorrectionNoStd(sbp, **d)

 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgSsrGriddedCorrectionNoStd._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgSsrGriddedCorrectionNoStd._parser.build(c)
    return self.pack()

  def into_buffer(self, buf, offset):
    """Produce a framed/packed SBP message into the provided buffer and offset.

    """
    self.payload = containerize(exclude_fields(self))
    self.parser = MsgSsrGriddedCorrectionNoStd._parser
    self.stream_payload.reset(buf, offset)
    return self.pack_into(buf, offset, self._build_payload)

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgSsrGriddedCorrectionNoStd, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    
SBP_MSG_SSR_GRIDDED_CORRECTION = 0x05FA
class MsgSsrGriddedCorrection(SBP):
  """SBP class for message MSG_SSR_GRIDDED_CORRECTION (0x05FA).

  You can have MSG_SSR_GRIDDED_CORRECTION inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  STEC residuals are per space vehicle, tropo is not.
It is typically equivalent to the QZSS CLAS Sub Type 9 messages


  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  header : GriddedCorrectionHeader
    Header of a Gridded Correction message
  element : GridElement
    Tropo and STEC residuals for the given grid point (mean
and standard deviation)

  sender : int
    Optional sender ID, defaults to SENDER_ID (see sbp/msg.py).

  """
  _parser = construct.Struct(
                   'header' / construct.Struct(GriddedCorrectionHeader._parser),
                   'element' / construct.Struct(GridElement._parser),)
  __slots__ = [
               'header',
               'element',
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
      self.element = kwargs.pop('element')

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
    
SBP_MSG_SSR_GRID_DEFINITION = 0x05F5
class MsgSsrGridDefinition(SBP):
  """SBP class for message MSG_SSR_GRID_DEFINITION (0x05F5).

  You can have MSG_SSR_GRID_DEFINITION inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  Based on the 3GPP proposal R2-1906781 which is in turn based on
OMA-LPPe-ValidityArea from OMA-TS-LPPe-V2_0-20141202-C


  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  header : GridDefinitionHeader
    Header of a Gridded Correction message
  rle_list : array
    Run Length Encode list of quadrants that contain valid data.
The spec describes the encoding scheme in detail, but
essentially the index of the quadrants that contain transitions between
valid and invalid (and vice versa) are encoded as u8 integers.

  sender : int
    Optional sender ID, defaults to SENDER_ID (see sbp/msg.py).

  """
  _parser = construct.Struct(
                   'header' / construct.Struct(GridDefinitionHeader._parser),
                   construct.GreedyRange('rle_list' / construct.Int8ul),)
  __slots__ = [
               'header',
               'rle_list',
              ]

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      super( MsgSsrGridDefinition,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.from_binary(sbp.payload)
    else:
      super( MsgSsrGridDefinition, self).__init__()
      self.msg_type = SBP_MSG_SSR_GRID_DEFINITION
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
    return MsgSsrGridDefinition.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgSsrGridDefinition(sbp, **d)

 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgSsrGridDefinition._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgSsrGridDefinition._parser.build(c)
    return self.pack()

  def into_buffer(self, buf, offset):
    """Produce a framed/packed SBP message into the provided buffer and offset.

    """
    self.payload = containerize(exclude_fields(self))
    self.parser = MsgSsrGridDefinition._parser
    self.stream_payload.reset(buf, offset)
    return self.pack_into(buf, offset, self._build_payload)

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgSsrGridDefinition, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    

msg_classes = {
  0x05DD: MsgSsrOrbitClock,
  0x05DC: MsgSsrOrbitClockDepA,
  0x05E1: MsgSsrCodeBiases,
  0x05E6: MsgSsrPhaseBiases,
  0x05EB: MsgSsrStecCorrection,
  0x05F0: MsgSsrGriddedCorrectionNoStd,
  0x05FA: MsgSsrGriddedCorrection,
  0x05F5: MsgSsrGridDefinition,
}