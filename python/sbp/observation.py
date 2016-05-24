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
from sbp.gnss_signal import *

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
tracked. The observations should be interoperable with 3rd party 
receivers and conform with typical RTCMv3 GNSS observations. 

  
  Parameters
  ----------
  P : int
    Pseudorange observation
  L : int
    Phase Range minus pseudorange. Phaserange can be reconstructed
by adding pseudorange to this value. This follows the convention
from DF0012 or the DF042 field from the RTCM 10403.2 Ammendment 2
specification.  Importantly, this assumes the phaserange has the 
same sign as the pseudorange.

  cn0 : int
    Carrier-to-Noise density
  lock : int
    Lock indicator. This value gives an indication of the time
for which a satellite has maintained continuous phase lock.
Whenever a satellite signal has lost and regained lock, this 
value is reset to zero. It is encoded according to DF402 from
the RTCM 10403.2 Amendment 2 specification.  Given a lock time (t)
in milliseconds, the field value (n) is given by floor(log_2(t) - 4) 
when t is greater than 32 ms or 0 if (t) is less than 32 ms. 
Conversely, given the field, n,  the lower range of possible  lock times
is given by 2 ^ (n + 4) ms and the upper range is given by 2 ^ (n + 5) ms
provided n is not 0.  If n is 0 the lower range is given to be 0 ms.

  sid : GnssSignal
    GNSS signal identifier

  """
  _parser = Embedded(Struct("PackedObsContent",
                     ULInt32('P'),
                     SLInt32('L'),
                     ULInt8('cn0'),
                     ULInt8('lock'),
                     Struct('sid', GnssSignal._parser),))
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
    
class CarrierPhaseDepA(object):
  """CarrierPhaseDepA.
  
  Carrier phase measurement in cycles represented as a 40-bit
fixed point number with Q32.8 layout, i.e. 32-bits of whole
cycles and 8-bits of fractional cycles. This has the opposite
sign convention than a typical GPS receiver and the phase has
the opposite sign as the pseudorange.

  
  Parameters
  ----------
  i : int
    Carrier phase whole cycles
  f : int
    Carrier phase fractional part

  """
  _parser = Embedded(Struct("CarrierPhaseDepA",
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
    p = CarrierPhaseDepA._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    d = dict([(k, getattr(obj, k)) for k in self.__slots__])
    return CarrierPhaseDepA.build(d)
    
class PackedObsContentDepA(object):
  """PackedObsContentDepA.
  
  Deprecated.
  
  Parameters
  ----------
  P : int
    Pseudorange observation
  L : CarrierPhaseDepA
    Carrier phase observation with opposite sign from typical convention
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
                     Struct('L', CarrierPhaseDepA._parser),
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
    
class PackedObsContentDepB(object):
  """PackedObsContentDepB.
  
  Pseudorange and carrier phase observation for a satellite being
tracked.  Pseudoranges are referenced to a nominal pseudorange.

  
  Parameters
  ----------
  P : int
    Pseudorange observation
  L : CarrierPhaseDepA
    Carrier phase observation with opposite sign from typical convention.
  cn0 : int
    Carrier-to-Noise density
  lock : int
    Lock indicator. This value changes whenever a satellite
signal has lost and regained lock, indicating that the
carrier phase ambiguity may have changed.

  sid : GnssSignal
    GNSS signal identifier

  """
  _parser = Embedded(Struct("PackedObsContentDepB",
                     ULInt32('P'),
                     Struct('L', CarrierPhaseDepA._parser),
                     ULInt8('cn0'),
                     ULInt16('lock'),
                     Struct('sid', GnssSignal._parser),))
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
    p = PackedObsContentDepB._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    d = dict([(k, getattr(obj, k)) for k in self.__slots__])
    return PackedObsContentDepB.build(d)
    
SBP_MSG_OBS = 0x0049
class MsgObs(SBP):
  """SBP class for message MSG_OBS (0x0049).

  You can have MSG_OBS inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  The GPS observations message reports all the raw pseudorange and
carrier phase observations for the satellites being tracked by
the device. Carrier phase observation here is phaserange - pseudorange.
The observations should be interoperable with 3rd party receivers and conform 
with typical RTCMv3 GNSS observations. 


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

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    return MsgObs.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgObs(sbp, **d)

 
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

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgObs, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    
SBP_MSG_BASE_POS_LLH = 0x0044
class MsgBasePosLLH(SBP):
  """SBP class for message MSG_BASE_POS_LLH (0x0044).

  You can have MSG_BASE_POS_LLH inherit its fields directly
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
  _parser = Struct("MsgBasePosLLH",
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
      super( MsgBasePosLLH,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.from_binary(sbp.payload)
    else:
      super( MsgBasePosLLH, self).__init__()
      self.msg_type = SBP_MSG_BASE_POS_LLH
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.lat = kwargs.pop('lat')
      self.lon = kwargs.pop('lon')
      self.height = kwargs.pop('height')

  def __repr__(self):
    return fmt_repr(self)

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    return MsgBasePosLLH.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgBasePosLLH(sbp, **d)

 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgBasePosLLH._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgBasePosLLH._parser.build(c)
    return self.pack()

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgBasePosLLH, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    
SBP_MSG_BASE_POS_ECEF = 0x0048
class MsgBasePosECEF(SBP):
  """SBP class for message MSG_BASE_POS_ECEF (0x0048).

  You can have MSG_BASE_POS_ECEF inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  The base station position message is the position reported by
the base station itself in absolute Earth Centered Earth Fixed
coordinates. It is used for pseudo-absolute RTK positioning, and
is required to be a high-accuracy surveyed location of the base
station. Any error here will result in an error in the
pseudo-absolute position output.


  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  x : double
    ECEF X coodinate
  y : double
    ECEF Y coordinate
  z : double
    ECEF Z coordinate
  sender : int
    Optional sender ID, defaults to SENDER_ID (see sbp/msg.py).

  """
  _parser = Struct("MsgBasePosECEF",
                   LFloat64('x'),
                   LFloat64('y'),
                   LFloat64('z'),)
  __slots__ = [
               'x',
               'y',
               'z',
              ]

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      super( MsgBasePosECEF,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.from_binary(sbp.payload)
    else:
      super( MsgBasePosECEF, self).__init__()
      self.msg_type = SBP_MSG_BASE_POS_ECEF
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.x = kwargs.pop('x')
      self.y = kwargs.pop('y')
      self.z = kwargs.pop('z')

  def __repr__(self):
    return fmt_repr(self)

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    return MsgBasePosECEF.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgBasePosECEF(sbp, **d)

 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgBasePosECEF._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgBasePosECEF._parser.build(c)
    return self.pack()

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgBasePosECEF, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    
SBP_MSG_EPHEMERIS = 0x0080
class MsgEphemeris(SBP):
  """SBP class for message MSG_EPHEMERIS (0x0080).

  You can have MSG_EPHEMERIS inherit its fields directly
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
  sid : GnssSignal
    GNSS signal identifier
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
                   Struct('sid', GnssSignal._parser),
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

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    return MsgEphemeris.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgEphemeris(sbp, **d)

 
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

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgEphemeris, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    
SBP_MSG_EPHEMERIS_DEP_A = 0x001A
class MsgEphemerisDepA(SBP):
  """SBP class for message MSG_EPHEMERIS_DEP_A (0x001A).

  You can have MSG_EPHEMERIS_DEP_A inherit its fields directly
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

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    return MsgEphemerisDepA.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgEphemerisDepA(sbp, **d)

 
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

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgEphemerisDepA, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    
SBP_MSG_EPHEMERIS_DEP_B = 0x0046
class MsgEphemerisDepB(SBP):
  """SBP class for message MSG_EPHEMERIS_DEP_B (0x0046).

  You can have MSG_EPHEMERIS_DEP_B inherit its fields directly
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

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    return MsgEphemerisDepB.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgEphemerisDepB(sbp, **d)

 
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

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgEphemerisDepB, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    
SBP_MSG_OBS_DEP_A = 0x0045
class MsgObsDepA(SBP):
  """SBP class for message MSG_OBS_DEP_A (0x0045).

  You can have MSG_OBS_DEP_A inherit its fields directly
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

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    return MsgObsDepA.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgObsDepA(sbp, **d)

 
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

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgObsDepA, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    
SBP_MSG_OBS_DEP_B = 0x0043
class MsgObsDepB(SBP):
  """SBP class for message MSG_OBS_DEP_B (0x0043).

  You can have MSG_OBS_DEP_B inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  This observation message has been deprecated in favor of 
observations that are more interoperable. This message
should be used for observations referenced to 
a nominal pseudorange which are not interoperable with
most 3rd party GNSS receievers or typical RTCMv3 
observations.


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
  _parser = Struct("MsgObsDepB",
                   Struct('header', ObservationHeader._parser),
                   OptionalGreedyRange(Struct('obs', PackedObsContentDepB._parser)),)
  __slots__ = [
               'header',
               'obs',
              ]

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      super( MsgObsDepB,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.from_binary(sbp.payload)
    else:
      super( MsgObsDepB, self).__init__()
      self.msg_type = SBP_MSG_OBS_DEP_B
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.header = kwargs.pop('header')
      self.obs = kwargs.pop('obs')

  def __repr__(self):
    return fmt_repr(self)

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    return MsgObsDepB.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgObsDepB(sbp, **d)

 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgObsDepB._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgObsDepB._parser.build(c)
    return self.pack()

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgObsDepB, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    
SBP_MSG_EPHEMERIS_DEP_C = 0x0047
class MsgEphemerisDepC(SBP):
  """SBP class for message MSG_EPHEMERIS_DEP_C (0x0047).

  You can have MSG_EPHEMERIS_DEP_C inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  This ephemeris message has been deprecated to allow the ephemerides
to be masked separately from GNSS observations.
The ephemeris message returns a set of satellite orbits
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
  sid : GnssSignal
    GNSS signal identifier
  iode : int
    Issue of ephemeris data
  iodc : int
    Issue of clock data
  reserved : int
    Reserved field
  sender : int
    Optional sender ID, defaults to SENDER_ID (see sbp/msg.py).

  """
  _parser = Struct("MsgEphemerisDepC",
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
                   Struct('sid', GnssSignal._parser),
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
      super( MsgEphemerisDepC,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.from_binary(sbp.payload)
    else:
      super( MsgEphemerisDepC, self).__init__()
      self.msg_type = SBP_MSG_EPHEMERIS_DEP_C
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

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    return MsgEphemerisDepC.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgEphemerisDepC(sbp, **d)

 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgEphemerisDepC._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgEphemerisDepC._parser.build(c)
    return self.pack()

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgEphemerisDepC, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    

msg_classes = {
  0x0049: MsgObs,
  0x0044: MsgBasePosLLH,
  0x0048: MsgBasePosECEF,
  0x0080: MsgEphemeris,
  0x001A: MsgEphemerisDepA,
  0x0046: MsgEphemerisDepB,
  0x0045: MsgObsDepA,
  0x0043: MsgObsDepB,
  0x0047: MsgEphemerisDepC,
}