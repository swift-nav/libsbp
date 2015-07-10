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
Satellite observation messages from the device.
"""

from construct import *
import json
from sbp.msg import SBP, SENDER_ID
from sbp.utils import fmt_repr, exclude_fields, walk_json_dict, containerize, greedy_string

# Automatically generated from piksi/yaml/swiftnav/sbp/observation.yaml with generate.py.
# Please do not hand edit!


class ObsGPSTime(object):
  """ObsGPSTime.
  
  A wire-appropriate GPS time, defined as the number of
milliseconds since beginning of the week on the Saturday/Sunday
transition.

  
  Parameters
  ----------
  tow : int
    Milliseconds since start of GPS week
  wn : int
    GPS week number

  """
  _parser = Embedded(Struct("ObsGPSTime",
                     ULInt32('tow'),
                     ULInt16('wn'),))
  __slots__ = [
               'tow',
               'wn',
              ]

  def __init__(self, payload=None, **kwargs):
    if payload:
      self.from_binary(payload)
    else:
      self.tow = kwargs.pop('tow')
      self.wn = kwargs.pop('wn')

  def __repr__(self):
    return fmt_repr(self)
  
  def from_binary(self, d):
    p = ObsGPSTime._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    d = dict([(k, getattr(obj, k)) for k in self.__slots__])
    return ObsGPSTime.build(d)
    
class CarrierPhase(object):
  """CarrierPhase.
  
  Carrier phase measurement in cycles represented as a 40-bit
fixed point number with Q32.8 layout, i.e. 32-bits of whole
cycles and 8-bits of fractional cycles.

  
  Parameters
  ----------
  i : int
    Carrier phase whole cycles
  f : int
    Carrier phase fractional part

  """
  _parser = Embedded(Struct("CarrierPhase",
                     SLInt32('i'),
                     ULInt8('f'),))
  __slots__ = [
               'i',
               'f',
              ]

  def __init__(self, payload=None, **kwargs):
    if payload:
      self.from_binary(payload)
    else:
      self.i = kwargs.pop('i')
      self.f = kwargs.pop('f')

  def __repr__(self):
    return fmt_repr(self)
  
  def from_binary(self, d):
    p = CarrierPhase._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    d = dict([(k, getattr(obj, k)) for k in self.__slots__])
    return CarrierPhase.build(d)
    
class ObservationHeader(object):
  """ObservationHeader.
  
  Header of a GPS observation message.
  
  Parameters
  ----------
  t : ObsGPSTime
    GPS time of this observation
  n_obs : int
    Total number of observations. First nibble is the size
of the sequence (n), second nibble is the zero-indexed
counter (ith packet of n)


  """
  _parser = Embedded(Struct("ObservationHeader",
                     Struct('t', ObsGPSTime._parser),
                     ULInt8('n_obs'),))
  __slots__ = [
               't',
               'n_obs',
              ]

  def __init__(self, payload=None, **kwargs):
    if payload:
      self.from_binary(payload)
    else:
      self.t = kwargs.pop('t')
      self.n_obs = kwargs.pop('n_obs')

  def __repr__(self):
    return fmt_repr(self)
  
  def from_binary(self, d):
    p = ObservationHeader._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    d = dict([(k, getattr(obj, k)) for k in self.__slots__])
    return ObservationHeader.build(d)
    
class PackedObsContent(object):
  """PackedObsContent.
  
  Pseudorange and carrier phase observation for a satellite being
tracked.

  
  Parameters
  ----------
  P : int
    Pseudorange observation
  L : CarrierPhase
    Carrier phase observation
  cn0 : int
    Carrier-to-Noise density
  lock : int
    Lock indicator. This value changes whenever a satellite
signal has lost and regained lock, indicating that the
carrier phase ambiguity may have changed.

  sid : int
    Signal identifier of the satellite signal - values 0x00
through 0x1F represent GPS PRNs 1 through 32 respectively
(PRN-1 notation); other values reserved for future use.


  """
  _parser = Embedded(Struct("PackedObsContent",
                     ULInt32('P'),
                     Struct('L', CarrierPhase._parser),
                     ULInt8('cn0'),
                     ULInt16('lock'),
                     ULInt32('sid'),))
  __slots__ = [
               'P',
               'L',
               'cn0',
               'lock',
               'sid',
              ]

  def __init__(self, payload=None, **kwargs):
    if payload:
      self.from_binary(payload)
    else:
      self.P = kwargs.pop('P')
      self.L = kwargs.pop('L')
      self.cn0 = kwargs.pop('cn0')
      self.lock = kwargs.pop('lock')
      self.sid = kwargs.pop('sid')

  def __repr__(self):
    return fmt_repr(self)
  
  def from_binary(self, d):
    p = PackedObsContent._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    d = dict([(k, getattr(obj, k)) for k in self.__slots__])
    return PackedObsContent.build(d)
    
class PackedObsContentDepA(object):
  """PackedObsContentDepA.
  
  Deprecated.
  
  Parameters
  ----------
  P : int
    Pseudorange observation
  L : CarrierPhase
    Carrier phase observation
  cn0 : int
    Carrier-to-Noise density
  lock : int
    Lock indicator. This value changes whenever a satellite
signal has lost and regained lock, indicating that the
carrier phase ambiguity may have changed.

  prn : int
    PRN-1 identifier of the satellite signal

  """
  _parser = Embedded(Struct("PackedObsContentDepA",
                     ULInt32('P'),
                     Struct('L', CarrierPhase._parser),
                     ULInt8('cn0'),
                     ULInt16('lock'),
                     ULInt8('prn'),))
  __slots__ = [
               'P',
               'L',
               'cn0',
               'lock',
               'prn',
              ]

  def __init__(self, payload=None, **kwargs):
    if payload:
      self.from_binary(payload)
    else:
      self.P = kwargs.pop('P')
      self.L = kwargs.pop('L')
      self.cn0 = kwargs.pop('cn0')
      self.lock = kwargs.pop('lock')
      self.prn = kwargs.pop('prn')

  def __repr__(self):
    return fmt_repr(self)
  
  def from_binary(self, d):
    p = PackedObsContentDepA._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    d = dict([(k, getattr(obj, k)) for k in self.__slots__])
    return PackedObsContentDepA.build(d)
    
SBP_MSG_OBS = 0x0043
class MsgObs(SBP):
  """SBP class for message MSG_OBS (0x0043).

  You can have MSG_OBS inherent its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  The GPS observations message reports all the raw pseudorange and
carrier phase observations for the satellites being tracked by
the device. Carrier phase observation here is represented as a
40-bit fixed point number with Q32.8 layout (i.e. 32-bits of
whole cycles and 8-bits of fractional cycles).


  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  header : ObservationHeader
    Header of a GPS observation message
  obs : array
    Pseudorange and carrier phase observation for a
satellite being tracked.

  sender : int
    Optional sender ID, defaults to SENDER_ID (see sbp/msg.py).

  """
  _parser = Struct("MsgObs",
                   Struct('header', ObservationHeader._parser),
                   OptionalGreedyRange(Struct('obs', PackedObsContent._parser)),)
  __slots__ = [
               'header',
               'obs',
              ]

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      super( MsgObs,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.from_binary(sbp.payload)
    else:
      super( MsgObs, self).__init__()
      self.msg_type = SBP_MSG_OBS
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.header = kwargs.pop('header')
      self.obs = kwargs.pop('obs')

  def __repr__(self):
    return fmt_repr(self)
 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgObs._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgObs._parser.build(c)
    return self.pack()

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    sbp = SBP.from_json_dict(d)
    return MsgObs(sbp)

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgObs, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    
SBP_MSG_BASE_POS = 0x0044
class MsgBasePos(SBP):
  """SBP class for message MSG_BASE_POS (0x0044).

  You can have MSG_BASE_POS inherent its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  The base station position message is the position reported by
the base station itself. It is used for pseudo-absolute RTK
positioning, and is required to be a high-accuracy surveyed
location of the base station. Any error here will result in an
error in the pseudo-absolute position output.


  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  lat : double
    Latitude
  lon : double
    Longitude
  height : double
    Height
  sender : int
    Optional sender ID, defaults to SENDER_ID (see sbp/msg.py).

  """
  _parser = Struct("MsgBasePos",
                   LFloat64('lat'),
                   LFloat64('lon'),
                   LFloat64('height'),)
  __slots__ = [
               'lat',
               'lon',
               'height',
              ]

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      super( MsgBasePos,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.from_binary(sbp.payload)
    else:
      super( MsgBasePos, self).__init__()
      self.msg_type = SBP_MSG_BASE_POS
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.lat = kwargs.pop('lat')
      self.lon = kwargs.pop('lon')
      self.height = kwargs.pop('height')

  def __repr__(self):
    return fmt_repr(self)
 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgBasePos._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgBasePos._parser.build(c)
    return self.pack()

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    sbp = SBP.from_json_dict(d)
    return MsgBasePos(sbp)

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgBasePos, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    
SBP_MSG_EPHEMERIS = 0x0047
class MsgEphemeris(SBP):
  """SBP class for message MSG_EPHEMERIS (0x0047).

  You can have MSG_EPHEMERIS inherent its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  The ephemeris message returns a set of satellite orbit
parameters that is used to calculate GPS satellite position,
velocity, and clock offset. Please see the Navstar GPS
Space Segment/Navigation user interfaces (ICD-GPS-200, Table
20-III) for more details.


  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  tgd : double
    Group delay differential between L1 and L2
  c_rs : double
    Amplitude of the sine harmonic correction term to the orbit radius
  c_rc : double
    Amplitude of the cosine harmonic correction term to the orbit radius
  c_uc : double
    Amplitude of the cosine harmonic correction term to the argument of latitude
  c_us : double
    Amplitude of the sine harmonic correction term to the argument of latitude
  c_ic : double
    Amplitude of the cosine harmonic correction term to the angle of inclination
  c_is : double
    Amplitude of the sine harmonic correction term to the angle of inclination
  dn : double
    Mean motion difference
  m0 : double
    Mean anomaly at reference time
  ecc : double
    Eccentricity of satellite orbit
  sqrta : double
    Square root of the semi-major axis of orbit
  omega0 : double
    Longitude of ascending node of orbit plane at weekly epoch
  omegadot : double
    Rate of right ascension
  w : double
    Argument of perigee
  inc : double
    Inclination
  inc_dot : double
    Inclination first derivative
  af0 : double
    Polynomial clock correction coefficient (clock bias)
  af1 : double
    Polynomial clock correction coefficient (clock drift)
  af2 : double
    Polynomial clock correction coefficient (rate of clock drift)
  toe_tow : double
    Time of week
  toe_wn : int
    Week number
  toc_tow : double
    Clock reference time of week
  toc_wn : int
    Clock reference week number
  valid : int
    Is valid?
  healthy : int
    Satellite is healthy?
  sid : int
    Signal identifier being tracked - values 0x00 through 0x1F represent
GPS PRNs 1 through 32 respectively (PRN-1 notation); other values
reserved for future use

  iode : int
    Issue of ephemeris data
  iodc : int
    Issue of clock data
  reserved : int
    Reserved field
  sender : int
    Optional sender ID, defaults to SENDER_ID (see sbp/msg.py).

  """
  _parser = Struct("MsgEphemeris",
                   LFloat64('tgd'),
                   LFloat64('c_rs'),
                   LFloat64('c_rc'),
                   LFloat64('c_uc'),
                   LFloat64('c_us'),
                   LFloat64('c_ic'),
                   LFloat64('c_is'),
                   LFloat64('dn'),
                   LFloat64('m0'),
                   LFloat64('ecc'),
                   LFloat64('sqrta'),
                   LFloat64('omega0'),
                   LFloat64('omegadot'),
                   LFloat64('w'),
                   LFloat64('inc'),
                   LFloat64('inc_dot'),
                   LFloat64('af0'),
                   LFloat64('af1'),
                   LFloat64('af2'),
                   LFloat64('toe_tow'),
                   ULInt16('toe_wn'),
                   LFloat64('toc_tow'),
                   ULInt16('toc_wn'),
                   ULInt8('valid'),
                   ULInt8('healthy'),
                   ULInt32('sid'),
                   ULInt8('iode'),
                   ULInt16('iodc'),
                   ULInt32('reserved'),)
  __slots__ = [
               'tgd',
               'c_rs',
               'c_rc',
               'c_uc',
               'c_us',
               'c_ic',
               'c_is',
               'dn',
               'm0',
               'ecc',
               'sqrta',
               'omega0',
               'omegadot',
               'w',
               'inc',
               'inc_dot',
               'af0',
               'af1',
               'af2',
               'toe_tow',
               'toe_wn',
               'toc_tow',
               'toc_wn',
               'valid',
               'healthy',
               'sid',
               'iode',
               'iodc',
               'reserved',
              ]

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      super( MsgEphemeris,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.from_binary(sbp.payload)
    else:
      super( MsgEphemeris, self).__init__()
      self.msg_type = SBP_MSG_EPHEMERIS
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.tgd = kwargs.pop('tgd')
      self.c_rs = kwargs.pop('c_rs')
      self.c_rc = kwargs.pop('c_rc')
      self.c_uc = kwargs.pop('c_uc')
      self.c_us = kwargs.pop('c_us')
      self.c_ic = kwargs.pop('c_ic')
      self.c_is = kwargs.pop('c_is')
      self.dn = kwargs.pop('dn')
      self.m0 = kwargs.pop('m0')
      self.ecc = kwargs.pop('ecc')
      self.sqrta = kwargs.pop('sqrta')
      self.omega0 = kwargs.pop('omega0')
      self.omegadot = kwargs.pop('omegadot')
      self.w = kwargs.pop('w')
      self.inc = kwargs.pop('inc')
      self.inc_dot = kwargs.pop('inc_dot')
      self.af0 = kwargs.pop('af0')
      self.af1 = kwargs.pop('af1')
      self.af2 = kwargs.pop('af2')
      self.toe_tow = kwargs.pop('toe_tow')
      self.toe_wn = kwargs.pop('toe_wn')
      self.toc_tow = kwargs.pop('toc_tow')
      self.toc_wn = kwargs.pop('toc_wn')
      self.valid = kwargs.pop('valid')
      self.healthy = kwargs.pop('healthy')
      self.sid = kwargs.pop('sid')
      self.iode = kwargs.pop('iode')
      self.iodc = kwargs.pop('iodc')
      self.reserved = kwargs.pop('reserved')

  def __repr__(self):
    return fmt_repr(self)
 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgEphemeris._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgEphemeris._parser.build(c)
    return self.pack()

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    sbp = SBP.from_json_dict(d)
    return MsgEphemeris(sbp)

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgEphemeris, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    
SBP_MSG_EPHEMERIS_DEP_A = 0x001A
class MsgEphemerisDepA(SBP):
  """SBP class for message MSG_EPHEMERIS_DEP_A (0x001A).

  You can have MSG_EPHEMERIS_DEP_A inherent its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  Deprecated.

  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  tgd : double
    Group delay differential between L1 and L2
  c_rs : double
    Amplitude of the sine harmonic correction term to the orbit radius
  c_rc : double
    Amplitude of the cosine harmonic correction term to the orbit radius
  c_uc : double
    Amplitude of the cosine harmonic correction term to the argument of latitude
  c_us : double
    Amplitude of the sine harmonic correction term to the argument of latitude
  c_ic : double
    Amplitude of the cosine harmonic correction term to the angle of inclination
  c_is : double
    Amplitude of the sine harmonic correction term to the angle of inclination
  dn : double
    Mean motion difference
  m0 : double
    Mean anomaly at reference time
  ecc : double
    Eccentricity of satellite orbit
  sqrta : double
    Square root of the semi-major axis of orbit
  omega0 : double
    Longitude of ascending node of orbit plane at weekly epoch
  omegadot : double
    Rate of right ascension
  w : double
    Argument of perigee
  inc : double
    Inclination
  inc_dot : double
    Inclination first derivative
  af0 : double
    Polynomial clock correction coefficient (clock bias)
  af1 : double
    Polynomial clock correction coefficient (clock drift)
  af2 : double
    Polynomial clock correction coefficient (rate of clock drift)
  toe_tow : double
    Time of week
  toe_wn : int
    Week number
  toc_tow : double
    Clock reference time of week
  toc_wn : int
    Clock reference week number
  valid : int
    Is valid?
  healthy : int
    Satellite is healthy?
  prn : int
    PRN being tracked
  sender : int
    Optional sender ID, defaults to SENDER_ID (see sbp/msg.py).

  """
  _parser = Struct("MsgEphemerisDepA",
                   LFloat64('tgd'),
                   LFloat64('c_rs'),
                   LFloat64('c_rc'),
                   LFloat64('c_uc'),
                   LFloat64('c_us'),
                   LFloat64('c_ic'),
                   LFloat64('c_is'),
                   LFloat64('dn'),
                   LFloat64('m0'),
                   LFloat64('ecc'),
                   LFloat64('sqrta'),
                   LFloat64('omega0'),
                   LFloat64('omegadot'),
                   LFloat64('w'),
                   LFloat64('inc'),
                   LFloat64('inc_dot'),
                   LFloat64('af0'),
                   LFloat64('af1'),
                   LFloat64('af2'),
                   LFloat64('toe_tow'),
                   ULInt16('toe_wn'),
                   LFloat64('toc_tow'),
                   ULInt16('toc_wn'),
                   ULInt8('valid'),
                   ULInt8('healthy'),
                   ULInt8('prn'),)
  __slots__ = [
               'tgd',
               'c_rs',
               'c_rc',
               'c_uc',
               'c_us',
               'c_ic',
               'c_is',
               'dn',
               'm0',
               'ecc',
               'sqrta',
               'omega0',
               'omegadot',
               'w',
               'inc',
               'inc_dot',
               'af0',
               'af1',
               'af2',
               'toe_tow',
               'toe_wn',
               'toc_tow',
               'toc_wn',
               'valid',
               'healthy',
               'prn',
              ]

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      super( MsgEphemerisDepA,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.from_binary(sbp.payload)
    else:
      super( MsgEphemerisDepA, self).__init__()
      self.msg_type = SBP_MSG_EPHEMERIS_DEP_A
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.tgd = kwargs.pop('tgd')
      self.c_rs = kwargs.pop('c_rs')
      self.c_rc = kwargs.pop('c_rc')
      self.c_uc = kwargs.pop('c_uc')
      self.c_us = kwargs.pop('c_us')
      self.c_ic = kwargs.pop('c_ic')
      self.c_is = kwargs.pop('c_is')
      self.dn = kwargs.pop('dn')
      self.m0 = kwargs.pop('m0')
      self.ecc = kwargs.pop('ecc')
      self.sqrta = kwargs.pop('sqrta')
      self.omega0 = kwargs.pop('omega0')
      self.omegadot = kwargs.pop('omegadot')
      self.w = kwargs.pop('w')
      self.inc = kwargs.pop('inc')
      self.inc_dot = kwargs.pop('inc_dot')
      self.af0 = kwargs.pop('af0')
      self.af1 = kwargs.pop('af1')
      self.af2 = kwargs.pop('af2')
      self.toe_tow = kwargs.pop('toe_tow')
      self.toe_wn = kwargs.pop('toe_wn')
      self.toc_tow = kwargs.pop('toc_tow')
      self.toc_wn = kwargs.pop('toc_wn')
      self.valid = kwargs.pop('valid')
      self.healthy = kwargs.pop('healthy')
      self.prn = kwargs.pop('prn')

  def __repr__(self):
    return fmt_repr(self)
 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgEphemerisDepA._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgEphemerisDepA._parser.build(c)
    return self.pack()

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    sbp = SBP.from_json_dict(d)
    return MsgEphemerisDepA(sbp)

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgEphemerisDepA, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    
SBP_MSG_EPHEMERIS_DEP_B = 0x0046
class MsgEphemerisDepB(SBP):
  """SBP class for message MSG_EPHEMERIS_DEP_B (0x0046).

  You can have MSG_EPHEMERIS_DEP_B inherent its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  Deprecated.

  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  tgd : double
    Group delay differential between L1 and L2
  c_rs : double
    Amplitude of the sine harmonic correction term to the orbit radius
  c_rc : double
    Amplitude of the cosine harmonic correction term to the orbit radius
  c_uc : double
    Amplitude of the cosine harmonic correction term to the argument of latitude
  c_us : double
    Amplitude of the sine harmonic correction term to the argument of latitude
  c_ic : double
    Amplitude of the cosine harmonic correction term to the angle of inclination
  c_is : double
    Amplitude of the sine harmonic correction term to the angle of inclination
  dn : double
    Mean motion difference
  m0 : double
    Mean anomaly at reference time
  ecc : double
    Eccentricity of satellite orbit
  sqrta : double
    Square root of the semi-major axis of orbit
  omega0 : double
    Longitude of ascending node of orbit plane at weekly epoch
  omegadot : double
    Rate of right ascension
  w : double
    Argument of perigee
  inc : double
    Inclination
  inc_dot : double
    Inclination first derivative
  af0 : double
    Polynomial clock correction coefficient (clock bias)
  af1 : double
    Polynomial clock correction coefficient (clock drift)
  af2 : double
    Polynomial clock correction coefficient (rate of clock drift)
  toe_tow : double
    Time of week
  toe_wn : int
    Week number
  toc_tow : double
    Clock reference time of week
  toc_wn : int
    Clock reference week number
  valid : int
    Is valid?
  healthy : int
    Satellite is healthy?
  prn : int
    PRN being tracked
  iode : int
    Issue of ephemeris data
  sender : int
    Optional sender ID, defaults to SENDER_ID (see sbp/msg.py).

  """
  _parser = Struct("MsgEphemerisDepB",
                   LFloat64('tgd'),
                   LFloat64('c_rs'),
                   LFloat64('c_rc'),
                   LFloat64('c_uc'),
                   LFloat64('c_us'),
                   LFloat64('c_ic'),
                   LFloat64('c_is'),
                   LFloat64('dn'),
                   LFloat64('m0'),
                   LFloat64('ecc'),
                   LFloat64('sqrta'),
                   LFloat64('omega0'),
                   LFloat64('omegadot'),
                   LFloat64('w'),
                   LFloat64('inc'),
                   LFloat64('inc_dot'),
                   LFloat64('af0'),
                   LFloat64('af1'),
                   LFloat64('af2'),
                   LFloat64('toe_tow'),
                   ULInt16('toe_wn'),
                   LFloat64('toc_tow'),
                   ULInt16('toc_wn'),
                   ULInt8('valid'),
                   ULInt8('healthy'),
                   ULInt8('prn'),
                   ULInt8('iode'),)
  __slots__ = [
               'tgd',
               'c_rs',
               'c_rc',
               'c_uc',
               'c_us',
               'c_ic',
               'c_is',
               'dn',
               'm0',
               'ecc',
               'sqrta',
               'omega0',
               'omegadot',
               'w',
               'inc',
               'inc_dot',
               'af0',
               'af1',
               'af2',
               'toe_tow',
               'toe_wn',
               'toc_tow',
               'toc_wn',
               'valid',
               'healthy',
               'prn',
               'iode',
              ]

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      super( MsgEphemerisDepB,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.from_binary(sbp.payload)
    else:
      super( MsgEphemerisDepB, self).__init__()
      self.msg_type = SBP_MSG_EPHEMERIS_DEP_B
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.tgd = kwargs.pop('tgd')
      self.c_rs = kwargs.pop('c_rs')
      self.c_rc = kwargs.pop('c_rc')
      self.c_uc = kwargs.pop('c_uc')
      self.c_us = kwargs.pop('c_us')
      self.c_ic = kwargs.pop('c_ic')
      self.c_is = kwargs.pop('c_is')
      self.dn = kwargs.pop('dn')
      self.m0 = kwargs.pop('m0')
      self.ecc = kwargs.pop('ecc')
      self.sqrta = kwargs.pop('sqrta')
      self.omega0 = kwargs.pop('omega0')
      self.omegadot = kwargs.pop('omegadot')
      self.w = kwargs.pop('w')
      self.inc = kwargs.pop('inc')
      self.inc_dot = kwargs.pop('inc_dot')
      self.af0 = kwargs.pop('af0')
      self.af1 = kwargs.pop('af1')
      self.af2 = kwargs.pop('af2')
      self.toe_tow = kwargs.pop('toe_tow')
      self.toe_wn = kwargs.pop('toe_wn')
      self.toc_tow = kwargs.pop('toc_tow')
      self.toc_wn = kwargs.pop('toc_wn')
      self.valid = kwargs.pop('valid')
      self.healthy = kwargs.pop('healthy')
      self.prn = kwargs.pop('prn')
      self.iode = kwargs.pop('iode')

  def __repr__(self):
    return fmt_repr(self)
 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgEphemerisDepB._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgEphemerisDepB._parser.build(c)
    return self.pack()

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    sbp = SBP.from_json_dict(d)
    return MsgEphemerisDepB(sbp)

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgEphemerisDepB, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    
SBP_MSG_OBS_DEP_A = 0x0045
class MsgObsDepA(SBP):
  """SBP class for message MSG_OBS_DEP_A (0x0045).

  You can have MSG_OBS_DEP_A inherent its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  Deprecated.

  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  header : ObservationHeader
    Header of a GPS observation message
  obs : array
    Pseudorange and carrier phase observation for a
satellite being tracked.

  sender : int
    Optional sender ID, defaults to SENDER_ID (see sbp/msg.py).

  """
  _parser = Struct("MsgObsDepA",
                   Struct('header', ObservationHeader._parser),
                   OptionalGreedyRange(Struct('obs', PackedObsContentDepA._parser)),)
  __slots__ = [
               'header',
               'obs',
              ]

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      super( MsgObsDepA,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.from_binary(sbp.payload)
    else:
      super( MsgObsDepA, self).__init__()
      self.msg_type = SBP_MSG_OBS_DEP_A
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.header = kwargs.pop('header')
      self.obs = kwargs.pop('obs')

  def __repr__(self):
    return fmt_repr(self)
 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgObsDepA._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgObsDepA._parser.build(c)
    return self.pack()

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    sbp = SBP.from_json_dict(d)
    return MsgObsDepA(sbp)

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgObsDepA, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    

msg_classes = {
  0x0043: MsgObs,
  0x0044: MsgBasePos,
  0x0047: MsgEphemeris,
  0x001A: MsgEphemerisDepA,
  0x0046: MsgEphemerisDepB,
  0x0045: MsgObsDepA,
}