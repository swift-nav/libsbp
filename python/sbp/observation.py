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
from sbp.gnss import *

# Automatically generated from piksi/yaml/swiftnav/sbp/observation.yaml with generate.py.
# Please do not hand edit!


class ObservationHeader(object):
  """ObservationHeader.
  
  Header of a GNSS observation message.
  
  Parameters
  ----------
  t : GPSTimeNano
    GNSS time of this observation
  n_obs : int
    Total number of observations. First nibble is the size
of the sequence (n), second nibble is the zero-indexed
counter (ith packet of n)


  """
  _parser = Embedded(Struct("ObservationHeader",
                     Struct('t', GPSTimeNano._parser),
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
    
class Doppler(object):
  """Doppler.
  
  Doppler measurement in Hz represented as a 24-bit
fixed point number with Q16.8 layout, i.e. 16-bits of whole
doppler and 8-bits of fractional doppler. This doppler is defined
as positive for approaching satellites.

  
  Parameters
  ----------
  i : int
    Doppler whole Hz
  f : int
    Doppler fractional part

  """
  _parser = Embedded(Struct("Doppler",
                     SLInt16('i'),
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
    p = Doppler._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    d = dict([(k, getattr(obj, k)) for k in self.__slots__])
    return Doppler.build(d)
    
class PackedObsContent(object):
  """PackedObsContent.
  
  Pseudorange and carrier phase observation for a satellite being
tracked. The observations are interoperable with 3rd party
receivers and conform with typical RTCMv3 GNSS observations.

  
  Parameters
  ----------
  P : int
    Pseudorange observation
  L : CarrierPhase
    Carrier phase observation with typical sign convention.
  D : Doppler
    Doppler observation with typical sign convention.
  cn0 : int
    Carrier-to-Noise density.  Zero implies invalid cn0.
  lock : int
    Lock timer. This value gives an indication of the time
for which a signal has maintained continuous phase lock.
Whenever a signal has lost and regained lock, this
value is reset to zero. It is encoded according to DF402 from
the RTCM 10403.2 Amendment 2 specification.  Valid values range
from 0 to 15 and the most significant nibble is reserved for future use.

  flags : int
    Measurement status flags. A bit field of flags providing the
status of this observation.  If this field is 0 it means only the Cn0
estimate for the signal is valid.

  sid : GnssSignal16
    GNSS signal identifier (16 bit)

  """
  _parser = Embedded(Struct("PackedObsContent",
                     ULInt32('P'),
                     Struct('L', CarrierPhase._parser),
                     Struct('D', Doppler._parser),
                     ULInt8('cn0'),
                     ULInt8('lock'),
                     ULInt8('flags'),
                     Struct('sid', GnssSignal16._parser),))
  __slots__ = [
               'P',
               'L',
               'D',
               'cn0',
               'lock',
               'flags',
               'sid',
              ]

  def __init__(self, payload=None, **kwargs):
    if payload:
      self.from_binary(payload)
    else:
      self.P = kwargs.pop('P')
      self.L = kwargs.pop('L')
      self.D = kwargs.pop('D')
      self.cn0 = kwargs.pop('cn0')
      self.lock = kwargs.pop('lock')
      self.flags = kwargs.pop('flags')
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
    
class EphemerisCommonContent(object):
  """EphemerisCommonContent.
  
  
  Parameters
  ----------
  sid : GnssSignal16
    GNSS signal identifier (16 bit)
  toe : GPSTimeSec
    Time of Ephemerides
  ura : double
    User Range Accuracy
  fit_interval : int
    Curve fit interval
  valid : int
    Status of ephemeris, 1 = valid, 0 = invalid
  health_bits : int
    Satellite health status.
GPS: ICD-GPS-200, chapter 20.3.3.3.1.4
SBAS: 0 = valid, non-zero = invalid
GLO: 0 = valid, non-zero = invalid


  """
  _parser = Embedded(Struct("EphemerisCommonContent",
                     Struct('sid', GnssSignal16._parser),
                     Struct('toe', GPSTimeSec._parser),
                     LFloat64('ura'),
                     ULInt32('fit_interval'),
                     ULInt8('valid'),
                     ULInt8('health_bits'),))
  __slots__ = [
               'sid',
               'toe',
               'ura',
               'fit_interval',
               'valid',
               'health_bits',
              ]

  def __init__(self, payload=None, **kwargs):
    if payload:
      self.from_binary(payload)
    else:
      self.sid = kwargs.pop('sid')
      self.toe = kwargs.pop('toe')
      self.ura = kwargs.pop('ura')
      self.fit_interval = kwargs.pop('fit_interval')
      self.valid = kwargs.pop('valid')
      self.health_bits = kwargs.pop('health_bits')

  def __repr__(self):
    return fmt_repr(self)
  
  def from_binary(self, d):
    p = EphemerisCommonContent._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    d = dict([(k, getattr(obj, k)) for k in self.__slots__])
    return EphemerisCommonContent.build(d)
    
class EphemerisCommonContentDepA(object):
  """EphemerisCommonContentDepA.
  
  
  Parameters
  ----------
  sid : GnssSignal
    GNSS signal identifier
  toe : GPSTime
    Time of Ephemerides
  ura : double
    User Range Accuracy
  fit_interval : int
    Curve fit interval
  valid : int
    Status of ephemeris, 1 = valid, 0 = invalid
  health_bits : int
    Satellite health status.
GPS: ICD-GPS-200, chapter 20.3.3.3.1.4
SBAS: 0 = valid, non-zero = invalid
GLO: 0 = valid, non-zero = invalid


  """
  _parser = Embedded(Struct("EphemerisCommonContentDepA",
                     Struct('sid', GnssSignal._parser),
                     Struct('toe', GPSTime._parser),
                     LFloat64('ura'),
                     ULInt32('fit_interval'),
                     ULInt8('valid'),
                     ULInt8('health_bits'),))
  __slots__ = [
               'sid',
               'toe',
               'ura',
               'fit_interval',
               'valid',
               'health_bits',
              ]

  def __init__(self, payload=None, **kwargs):
    if payload:
      self.from_binary(payload)
    else:
      self.sid = kwargs.pop('sid')
      self.toe = kwargs.pop('toe')
      self.ura = kwargs.pop('ura')
      self.fit_interval = kwargs.pop('fit_interval')
      self.valid = kwargs.pop('valid')
      self.health_bits = kwargs.pop('health_bits')

  def __repr__(self):
    return fmt_repr(self)
  
  def from_binary(self, d):
    p = EphemerisCommonContentDepA._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    d = dict([(k, getattr(obj, k)) for k in self.__slots__])
    return EphemerisCommonContentDepA.build(d)
    
class ObservationHeaderDep(object):
  """ObservationHeaderDep.
  
  Header of a GPS observation message.
  
  Parameters
  ----------
  t : GPSTime
    GPS time of this observation
  n_obs : int
    Total number of observations. First nibble is the size
of the sequence (n), second nibble is the zero-indexed
counter (ith packet of n)


  """
  _parser = Embedded(Struct("ObservationHeaderDep",
                     Struct('t', GPSTime._parser),
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
    p = ObservationHeaderDep._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    d = dict([(k, getattr(obj, k)) for k in self.__slots__])
    return ObservationHeaderDep.build(d)
    
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
    
class PackedObsContentDepC(object):
  """PackedObsContentDepC.
  
  Pseudorange and carrier phase observation for a satellite being
tracked. The observations are be interoperable with 3rd party
receivers and conform with typical RTCMv3 GNSS observations.

  
  Parameters
  ----------
  P : int
    Pseudorange observation
  L : CarrierPhase
    Carrier phase observation with typical sign convention.
  cn0 : int
    Carrier-to-Noise density
  lock : int
    Lock indicator. This value changes whenever a satellite
signal has lost and regained lock, indicating that the
carrier phase ambiguity may have changed.

  sid : GnssSignal
    GNSS signal identifier

  """
  _parser = Embedded(Struct("PackedObsContentDepC",
                     ULInt32('P'),
                     Struct('L', CarrierPhase._parser),
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
    p = PackedObsContentDepC._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    d = dict([(k, getattr(obj, k)) for k in self.__slots__])
    return PackedObsContentDepC.build(d)
    
class AlmanacCommonContent(object):
  """AlmanacCommonContent.
  
  
  Parameters
  ----------
  sid : GnssSignal
    GNSS signal identifier
  toa : GPSTimeSec
    Reference time of almanac
  ura : double
    User Range Accuracy
  fit_interval : int
    Curve fit interval
  valid : int
    Status of almanac, 1 = valid, 0 = invalid
  health_bits : int
    Satellite health status for GPS:
  - bits 5-7: NAV data health status. See IS-GPS-200H
    Table 20-VII: NAV Data Health Indications.
  - bits 0-4: Signal health status. See IS-GPS-200H
    Table 20-VIII. Codes for Health of SV Signal
    Components.
Satellite health status for GLO:
  See GLO ICD 5.1 table 5.1 for details
  - bit 0: C(n), "unhealthy" flag that is transmitted within
    non-immediate data and indicates overall constellation status
    at the moment of almanac uploading.
    '0' indicates malfunction of n-satellite.
    '1' indicates that n-satellite is operational.
  - bit 1: Bn(ln), '0' indicates the satellite is operational
    and suitable for navigation.


  """
  _parser = Embedded(Struct("AlmanacCommonContent",
                     Struct('sid', GnssSignal._parser),
                     Struct('toa', GPSTimeSec._parser),
                     LFloat64('ura'),
                     ULInt32('fit_interval'),
                     ULInt8('valid'),
                     ULInt8('health_bits'),))
  __slots__ = [
               'sid',
               'toa',
               'ura',
               'fit_interval',
               'valid',
               'health_bits',
              ]

  def __init__(self, payload=None, **kwargs):
    if payload:
      self.from_binary(payload)
    else:
      self.sid = kwargs.pop('sid')
      self.toa = kwargs.pop('toa')
      self.ura = kwargs.pop('ura')
      self.fit_interval = kwargs.pop('fit_interval')
      self.valid = kwargs.pop('valid')
      self.health_bits = kwargs.pop('health_bits')

  def __repr__(self):
    return fmt_repr(self)
  
  def from_binary(self, d):
    p = AlmanacCommonContent._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    d = dict([(k, getattr(obj, k)) for k in self.__slots__])
    return AlmanacCommonContent.build(d)
    
SBP_MSG_OBS = 0x004A
class MsgObs(SBP):
  """SBP class for message MSG_OBS (0x004A).

  You can have MSG_OBS inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  The GPS observations message reports all the raw pseudorange and
carrier phase observations for the satellites being tracked by
the device. Carrier phase observation here is represented as a
40-bit fixed point number with Q32.8 layout (i.e. 32-bits of
whole cycles and 8-bits of fractional cycles). The observations
are be interoperable with 3rd party receivers and conform
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
    
SBP_MSG_EPHEMERIS_GPS_DEP_E = 0x0081
class MsgEphemerisGPSDepE(SBP):
  """SBP class for message MSG_EPHEMERIS_GPS_DEP_E (0x0081).

  You can have MSG_EPHEMERIS_GPS_DEP_E inherit its fields directly
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
  common : EphemerisCommonContentDepA
    Values common for all ephemeris types
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
  toc : GPSTime
    Clock reference
  iode : int
    Issue of ephemeris data
  iodc : int
    Issue of clock data
  sender : int
    Optional sender ID, defaults to SENDER_ID (see sbp/msg.py).

  """
  _parser = Struct("MsgEphemerisGPSDepE",
                   Struct('common', EphemerisCommonContentDepA._parser),
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
                   Struct('toc', GPSTime._parser),
                   ULInt8('iode'),
                   ULInt16('iodc'),)
  __slots__ = [
               'common',
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
               'toc',
               'iode',
               'iodc',
              ]

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      super( MsgEphemerisGPSDepE,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.from_binary(sbp.payload)
    else:
      super( MsgEphemerisGPSDepE, self).__init__()
      self.msg_type = SBP_MSG_EPHEMERIS_GPS_DEP_E
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.common = kwargs.pop('common')
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
      self.toc = kwargs.pop('toc')
      self.iode = kwargs.pop('iode')
      self.iodc = kwargs.pop('iodc')

  def __repr__(self):
    return fmt_repr(self)

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    return MsgEphemerisGPSDepE.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgEphemerisGPSDepE(sbp, **d)

 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgEphemerisGPSDepE._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgEphemerisGPSDepE._parser.build(c)
    return self.pack()

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgEphemerisGPSDepE, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    
SBP_MSG_EPHEMERIS_GPS = 0x0086
class MsgEphemerisGPS(SBP):
  """SBP class for message MSG_EPHEMERIS_GPS (0x0086).

  You can have MSG_EPHEMERIS_GPS inherit its fields directly
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
  common : EphemerisCommonContent
    Values common for all ephemeris types
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
  toc : GPSTimeSec
    Clock reference
  iode : int
    Issue of ephemeris data
  iodc : int
    Issue of clock data
  sender : int
    Optional sender ID, defaults to SENDER_ID (see sbp/msg.py).

  """
  _parser = Struct("MsgEphemerisGPS",
                   Struct('common', EphemerisCommonContent._parser),
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
                   Struct('toc', GPSTimeSec._parser),
                   ULInt8('iode'),
                   ULInt16('iodc'),)
  __slots__ = [
               'common',
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
               'toc',
               'iode',
               'iodc',
              ]

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      super( MsgEphemerisGPS,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.from_binary(sbp.payload)
    else:
      super( MsgEphemerisGPS, self).__init__()
      self.msg_type = SBP_MSG_EPHEMERIS_GPS
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.common = kwargs.pop('common')
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
      self.toc = kwargs.pop('toc')
      self.iode = kwargs.pop('iode')
      self.iodc = kwargs.pop('iodc')

  def __repr__(self):
    return fmt_repr(self)

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    return MsgEphemerisGPS.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgEphemerisGPS(sbp, **d)

 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgEphemerisGPS._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgEphemerisGPS._parser.build(c)
    return self.pack()

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgEphemerisGPS, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    
SBP_MSG_EPHEMERIS_SBAS_DEP_A = 0x0082
class MsgEphemerisSbasDepA(SBP):
  """SBP class for message MSG_EPHEMERIS_SBAS_DEP_A (0x0082).

  You can have MSG_EPHEMERIS_SBAS_DEP_A inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  

  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  common : EphemerisCommonContentDepA
    Values common for all ephemeris types
  pos : array
    Position of the GEO at time toe
  vel : array
    Velocity of the GEO at time toe
  acc : array
    Acceleration of the GEO at time toe
  a_gf0 : double
    Time offset of the GEO clock w.r.t. SBAS Network Time
  a_gf1 : double
    Drift of the GEO clock w.r.t. SBAS Network Time
  sender : int
    Optional sender ID, defaults to SENDER_ID (see sbp/msg.py).

  """
  _parser = Struct("MsgEphemerisSbasDepA",
                   Struct('common', EphemerisCommonContentDepA._parser),
                   Struct('pos', Array(3, LFloat64('pos'))),
                   Struct('vel', Array(3, LFloat64('vel'))),
                   Struct('acc', Array(3, LFloat64('acc'))),
                   LFloat64('a_gf0'),
                   LFloat64('a_gf1'),)
  __slots__ = [
               'common',
               'pos',
               'vel',
               'acc',
               'a_gf0',
               'a_gf1',
              ]

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      super( MsgEphemerisSbasDepA,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.from_binary(sbp.payload)
    else:
      super( MsgEphemerisSbasDepA, self).__init__()
      self.msg_type = SBP_MSG_EPHEMERIS_SBAS_DEP_A
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.common = kwargs.pop('common')
      self.pos = kwargs.pop('pos')
      self.vel = kwargs.pop('vel')
      self.acc = kwargs.pop('acc')
      self.a_gf0 = kwargs.pop('a_gf0')
      self.a_gf1 = kwargs.pop('a_gf1')

  def __repr__(self):
    return fmt_repr(self)

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    return MsgEphemerisSbasDepA.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgEphemerisSbasDepA(sbp, **d)

 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgEphemerisSbasDepA._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgEphemerisSbasDepA._parser.build(c)
    return self.pack()

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgEphemerisSbasDepA, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    
SBP_MSG_EPHEMERIS_GLO_DEP_A = 0x0083
class MsgEphemerisGloDepA(SBP):
  """SBP class for message MSG_EPHEMERIS_GLO_DEP_A (0x0083).

  You can have MSG_EPHEMERIS_GLO_DEP_A inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  The ephemeris message returns a set of satellite orbit
parameters that is used to calculate GLO satellite position,
velocity, and clock offset. Please see the GLO ICD 5.1 "Table 4.5
Characteristics of words of immediate information (ephemeris parameters)"
for more details.


  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  common : EphemerisCommonContentDepA
    Values common for all ephemeris types
  gamma : double
    Relative deviation of predicted carrier frequency from nominal
  tau : double
    Correction to the SV time
  pos : array
    Position of the SV at tb in PZ-90.02 coordinates system
  vel : array
    Velocity vector of the SV at tb in PZ-90.02 coordinates system
  acc : array
    Acceleration vector of the SV at tb in PZ-90.02 coordinates sys
  sender : int
    Optional sender ID, defaults to SENDER_ID (see sbp/msg.py).

  """
  _parser = Struct("MsgEphemerisGloDepA",
                   Struct('common', EphemerisCommonContentDepA._parser),
                   LFloat64('gamma'),
                   LFloat64('tau'),
                   Struct('pos', Array(3, LFloat64('pos'))),
                   Struct('vel', Array(3, LFloat64('vel'))),
                   Struct('acc', Array(3, LFloat64('acc'))),)
  __slots__ = [
               'common',
               'gamma',
               'tau',
               'pos',
               'vel',
               'acc',
              ]

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      super( MsgEphemerisGloDepA,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.from_binary(sbp.payload)
    else:
      super( MsgEphemerisGloDepA, self).__init__()
      self.msg_type = SBP_MSG_EPHEMERIS_GLO_DEP_A
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.common = kwargs.pop('common')
      self.gamma = kwargs.pop('gamma')
      self.tau = kwargs.pop('tau')
      self.pos = kwargs.pop('pos')
      self.vel = kwargs.pop('vel')
      self.acc = kwargs.pop('acc')

  def __repr__(self):
    return fmt_repr(self)

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    return MsgEphemerisGloDepA.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgEphemerisGloDepA(sbp, **d)

 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgEphemerisGloDepA._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgEphemerisGloDepA._parser.build(c)
    return self.pack()

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgEphemerisGloDepA, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    
SBP_MSG_EPHEMERIS_SBAS = 0x0084
class MsgEphemerisSbas(SBP):
  """SBP class for message MSG_EPHEMERIS_SBAS (0x0084).

  You can have MSG_EPHEMERIS_SBAS inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  

  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  common : EphemerisCommonContent
    Values common for all ephemeris types
  pos : array
    Position of the GEO at time toe
  vel : array
    Velocity of the GEO at time toe
  acc : array
    Acceleration of the GEO at time toe
  a_gf0 : double
    Time offset of the GEO clock w.r.t. SBAS Network Time
  a_gf1 : double
    Drift of the GEO clock w.r.t. SBAS Network Time
  sender : int
    Optional sender ID, defaults to SENDER_ID (see sbp/msg.py).

  """
  _parser = Struct("MsgEphemerisSbas",
                   Struct('common', EphemerisCommonContent._parser),
                   Struct('pos', Array(3, LFloat64('pos'))),
                   Struct('vel', Array(3, LFloat64('vel'))),
                   Struct('acc', Array(3, LFloat64('acc'))),
                   LFloat64('a_gf0'),
                   LFloat64('a_gf1'),)
  __slots__ = [
               'common',
               'pos',
               'vel',
               'acc',
               'a_gf0',
               'a_gf1',
              ]

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      super( MsgEphemerisSbas,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.from_binary(sbp.payload)
    else:
      super( MsgEphemerisSbas, self).__init__()
      self.msg_type = SBP_MSG_EPHEMERIS_SBAS
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.common = kwargs.pop('common')
      self.pos = kwargs.pop('pos')
      self.vel = kwargs.pop('vel')
      self.acc = kwargs.pop('acc')
      self.a_gf0 = kwargs.pop('a_gf0')
      self.a_gf1 = kwargs.pop('a_gf1')

  def __repr__(self):
    return fmt_repr(self)

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    return MsgEphemerisSbas.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgEphemerisSbas(sbp, **d)

 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgEphemerisSbas._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgEphemerisSbas._parser.build(c)
    return self.pack()

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgEphemerisSbas, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    
SBP_MSG_EPHEMERIS_GLO_DEP_B = 0x0085
class MsgEphemerisGloDepB(SBP):
  """SBP class for message MSG_EPHEMERIS_GLO_DEP_B (0x0085).

  You can have MSG_EPHEMERIS_GLO_DEP_B inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  The ephemeris message returns a set of satellite orbit
parameters that is used to calculate GLO satellite position,
velocity, and clock offset. Please see the GLO ICD 5.1 "Table 4.5
Characteristics of words of immediate information (ephemeris parameters)"
for more details.


  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  common : EphemerisCommonContent
    Values common for all ephemeris types
  gamma : double
    Relative deviation of predicted carrier frequency from nominal
  tau : double
    Correction to the SV time
  pos : array
    Position of the SV at tb in PZ-90.02 coordinates system
  vel : array
    Velocity vector of the SV at tb in PZ-90.02 coordinates system
  acc : array
    Acceleration vector of the SV at tb in PZ-90.02 coordinates sys
  sender : int
    Optional sender ID, defaults to SENDER_ID (see sbp/msg.py).

  """
  _parser = Struct("MsgEphemerisGloDepB",
                   Struct('common', EphemerisCommonContent._parser),
                   LFloat64('gamma'),
                   LFloat64('tau'),
                   Struct('pos', Array(3, LFloat64('pos'))),
                   Struct('vel', Array(3, LFloat64('vel'))),
                   Struct('acc', Array(3, LFloat64('acc'))),)
  __slots__ = [
               'common',
               'gamma',
               'tau',
               'pos',
               'vel',
               'acc',
              ]

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      super( MsgEphemerisGloDepB,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.from_binary(sbp.payload)
    else:
      super( MsgEphemerisGloDepB, self).__init__()
      self.msg_type = SBP_MSG_EPHEMERIS_GLO_DEP_B
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.common = kwargs.pop('common')
      self.gamma = kwargs.pop('gamma')
      self.tau = kwargs.pop('tau')
      self.pos = kwargs.pop('pos')
      self.vel = kwargs.pop('vel')
      self.acc = kwargs.pop('acc')

  def __repr__(self):
    return fmt_repr(self)

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    return MsgEphemerisGloDepB.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgEphemerisGloDepB(sbp, **d)

 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgEphemerisGloDepB._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgEphemerisGloDepB._parser.build(c)
    return self.pack()

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgEphemerisGloDepB, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    
SBP_MSG_EPHEMERIS_GLO = 0x0087
class MsgEphemerisGlo(SBP):
  """SBP class for message MSG_EPHEMERIS_GLO (0x0087).

  You can have MSG_EPHEMERIS_GLO inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  The ephemeris message returns a set of satellite orbit
parameters that is used to calculate GLO satellite position,
velocity, and clock offset. Please see the GLO ICD 5.1 "Table 4.5
Characteristics of words of immediate information (ephemeris parameters)"
for more details.


  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  common : EphemerisCommonContent
    Values common for all ephemeris types
  gamma : double
    Relative deviation of predicted carrier frequency from nominal
  tau : double
    Correction to the SV time
  d_tau : double
    Equipment delay between L1 and L2
  pos : array
    Position of the SV at tb in PZ-90.02 coordinates system
  vel : array
    Velocity vector of the SV at tb in PZ-90.02 coordinates system
  acc : array
    Acceleration vector of the SV at tb in PZ-90.02 coordinates sys
  fcn : int
    Frequency slot. FCN+8 (that is [1..14]). 0 or 0xFF for invalid
  sender : int
    Optional sender ID, defaults to SENDER_ID (see sbp/msg.py).

  """
  _parser = Struct("MsgEphemerisGlo",
                   Struct('common', EphemerisCommonContent._parser),
                   LFloat64('gamma'),
                   LFloat64('tau'),
                   LFloat64('d_tau'),
                   Struct('pos', Array(3, LFloat64('pos'))),
                   Struct('vel', Array(3, LFloat64('vel'))),
                   Struct('acc', Array(3, LFloat64('acc'))),
                   ULInt8('fcn'),)
  __slots__ = [
               'common',
               'gamma',
               'tau',
               'd_tau',
               'pos',
               'vel',
               'acc',
               'fcn',
              ]

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      super( MsgEphemerisGlo,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.from_binary(sbp.payload)
    else:
      super( MsgEphemerisGlo, self).__init__()
      self.msg_type = SBP_MSG_EPHEMERIS_GLO
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.common = kwargs.pop('common')
      self.gamma = kwargs.pop('gamma')
      self.tau = kwargs.pop('tau')
      self.d_tau = kwargs.pop('d_tau')
      self.pos = kwargs.pop('pos')
      self.vel = kwargs.pop('vel')
      self.acc = kwargs.pop('acc')
      self.fcn = kwargs.pop('fcn')

  def __repr__(self):
    return fmt_repr(self)

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    return MsgEphemerisGlo.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgEphemerisGlo(sbp, **d)

 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgEphemerisGlo._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgEphemerisGlo._parser.build(c)
    return self.pack()

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgEphemerisGlo, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    
SBP_MSG_EPHEMERIS_DEP_D = 0x0080
class MsgEphemerisDepD(SBP):
  """SBP class for message MSG_EPHEMERIS_DEP_D (0x0080).

  You can have MSG_EPHEMERIS_DEP_D inherit its fields directly
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
  _parser = Struct("MsgEphemerisDepD",
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
      super( MsgEphemerisDepD,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.from_binary(sbp.payload)
    else:
      super( MsgEphemerisDepD, self).__init__()
      self.msg_type = SBP_MSG_EPHEMERIS_DEP_D
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
    return MsgEphemerisDepD.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgEphemerisDepD(sbp, **d)

 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgEphemerisDepD._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgEphemerisDepD._parser.build(c)
    return self.pack()

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgEphemerisDepD, self).to_json_dict()
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
    
SBP_MSG_EPHEMERIS_DEP_C = 0x0047
class MsgEphemerisDepC(SBP):
  """SBP class for message MSG_EPHEMERIS_DEP_C (0x0047).

  You can have MSG_EPHEMERIS_DEP_C inherit its fields directly
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
  header : ObservationHeaderDep
    Header of a GPS observation message
  obs : array
    Pseudorange and carrier phase observation for a
satellite being tracked.

  sender : int
    Optional sender ID, defaults to SENDER_ID (see sbp/msg.py).

  """
  _parser = Struct("MsgObsDepA",
                   Struct('header', ObservationHeaderDep._parser),
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
  header : ObservationHeaderDep
    Header of a GPS observation message
  obs : array
    Pseudorange and carrier phase observation for a
satellite being tracked.

  sender : int
    Optional sender ID, defaults to SENDER_ID (see sbp/msg.py).

  """
  _parser = Struct("MsgObsDepB",
                   Struct('header', ObservationHeaderDep._parser),
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
    
SBP_MSG_OBS_DEP_C = 0x0049
class MsgObsDepC(SBP):
  """SBP class for message MSG_OBS_DEP_C (0x0049).

  You can have MSG_OBS_DEP_C inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  The GPS observations message reports all the raw pseudorange and
carrier phase observations for the satellites being tracked by
the device. Carrier phase observation here is represented as a
40-bit fixed point number with Q32.8 layout (i.e. 32-bits of
whole cycles and 8-bits of fractional cycles). The observations
are interoperable with 3rd party receivers and conform
with typical RTCMv3 GNSS observations.


  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  header : ObservationHeaderDep
    Header of a GPS observation message
  obs : array
    Pseudorange and carrier phase observation for a
satellite being tracked.

  sender : int
    Optional sender ID, defaults to SENDER_ID (see sbp/msg.py).

  """
  _parser = Struct("MsgObsDepC",
                   Struct('header', ObservationHeaderDep._parser),
                   OptionalGreedyRange(Struct('obs', PackedObsContentDepC._parser)),)
  __slots__ = [
               'header',
               'obs',
              ]

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      super( MsgObsDepC,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.from_binary(sbp.payload)
    else:
      super( MsgObsDepC, self).__init__()
      self.msg_type = SBP_MSG_OBS_DEP_C
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
    return MsgObsDepC.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgObsDepC(sbp, **d)

 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgObsDepC._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgObsDepC._parser.build(c)
    return self.pack()

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgObsDepC, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    
SBP_MSG_IONO = 0x0090
class MsgIono(SBP):
  """SBP class for message MSG_IONO (0x0090).

  You can have MSG_IONO inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  The ionospheric parameters which allow the "L1 only" or "L2 only" user to
utilize the ionospheric model for computation of the ionospheric delay.
Please see ICD-GPS-200 (Chapter 20.3.3.5.1.7) for more details.


  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  t_nmct : GPSTimeSec
    Navigation Message Correction Table Valitidy Time
  a0 : double
  a1 : double
  a2 : double
  a3 : double
  b0 : double
  b1 : double
  b2 : double
  b3 : double
  sender : int
    Optional sender ID, defaults to SENDER_ID (see sbp/msg.py).

  """
  _parser = Struct("MsgIono",
                   Struct('t_nmct', GPSTimeSec._parser),
                   LFloat64('a0'),
                   LFloat64('a1'),
                   LFloat64('a2'),
                   LFloat64('a3'),
                   LFloat64('b0'),
                   LFloat64('b1'),
                   LFloat64('b2'),
                   LFloat64('b3'),)
  __slots__ = [
               't_nmct',
               'a0',
               'a1',
               'a2',
               'a3',
               'b0',
               'b1',
               'b2',
               'b3',
              ]

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      super( MsgIono,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.from_binary(sbp.payload)
    else:
      super( MsgIono, self).__init__()
      self.msg_type = SBP_MSG_IONO
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.t_nmct = kwargs.pop('t_nmct')
      self.a0 = kwargs.pop('a0')
      self.a1 = kwargs.pop('a1')
      self.a2 = kwargs.pop('a2')
      self.a3 = kwargs.pop('a3')
      self.b0 = kwargs.pop('b0')
      self.b1 = kwargs.pop('b1')
      self.b2 = kwargs.pop('b2')
      self.b3 = kwargs.pop('b3')

  def __repr__(self):
    return fmt_repr(self)

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    return MsgIono.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgIono(sbp, **d)

 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgIono._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgIono._parser.build(c)
    return self.pack()

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgIono, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    
SBP_MSG_SV_CONFIGURATION_GPS = 0x0091
class MsgSvConfigurationGPS(SBP):
  """SBP class for message MSG_SV_CONFIGURATION_GPS (0x0091).

  You can have MSG_SV_CONFIGURATION_GPS inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  Please see ICD-GPS-200 (Chapter 20.3.3.5.1.4) for more details.


  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  t_nmct : GPSTimeSec
    Navigation Message Correction Table Valitidy Time
  l2c_mask : int
    L2C capability mask, SV32 bit being MSB, SV1 bit being LSB
  sender : int
    Optional sender ID, defaults to SENDER_ID (see sbp/msg.py).

  """
  _parser = Struct("MsgSvConfigurationGPS",
                   Struct('t_nmct', GPSTimeSec._parser),
                   ULInt32('l2c_mask'),)
  __slots__ = [
               't_nmct',
               'l2c_mask',
              ]

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      super( MsgSvConfigurationGPS,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.from_binary(sbp.payload)
    else:
      super( MsgSvConfigurationGPS, self).__init__()
      self.msg_type = SBP_MSG_SV_CONFIGURATION_GPS
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.t_nmct = kwargs.pop('t_nmct')
      self.l2c_mask = kwargs.pop('l2c_mask')

  def __repr__(self):
    return fmt_repr(self)

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    return MsgSvConfigurationGPS.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgSvConfigurationGPS(sbp, **d)

 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgSvConfigurationGPS._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgSvConfigurationGPS._parser.build(c)
    return self.pack()

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgSvConfigurationGPS, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    
SBP_MSG_GROUP_DELAY_DEP_A = 0x0092
class MsgGroupDelayDepA(SBP):
  """SBP class for message MSG_GROUP_DELAY_DEP_A (0x0092).

  You can have MSG_GROUP_DELAY_DEP_A inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  Please see ICD-GPS-200 (30.3.3.3.1.1) for more details.

  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  t_op : GPSTime
    Data Predict Time of Week
  prn : int
    Satellite number
  valid : int
    bit-field indicating validity of the values,
LSB indicating tgd validity etc.
1 = value is valid, 0 = value is not valid.

  tgd : int
  isc_l1ca : int
  isc_l2c : int
  sender : int
    Optional sender ID, defaults to SENDER_ID (see sbp/msg.py).

  """
  _parser = Struct("MsgGroupDelayDepA",
                   Struct('t_op', GPSTime._parser),
                   ULInt8('prn'),
                   ULInt8('valid'),
                   SLInt16('tgd'),
                   SLInt16('isc_l1ca'),
                   SLInt16('isc_l2c'),)
  __slots__ = [
               't_op',
               'prn',
               'valid',
               'tgd',
               'isc_l1ca',
               'isc_l2c',
              ]

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      super( MsgGroupDelayDepA,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.from_binary(sbp.payload)
    else:
      super( MsgGroupDelayDepA, self).__init__()
      self.msg_type = SBP_MSG_GROUP_DELAY_DEP_A
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.t_op = kwargs.pop('t_op')
      self.prn = kwargs.pop('prn')
      self.valid = kwargs.pop('valid')
      self.tgd = kwargs.pop('tgd')
      self.isc_l1ca = kwargs.pop('isc_l1ca')
      self.isc_l2c = kwargs.pop('isc_l2c')

  def __repr__(self):
    return fmt_repr(self)

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    return MsgGroupDelayDepA.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgGroupDelayDepA(sbp, **d)

 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgGroupDelayDepA._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgGroupDelayDepA._parser.build(c)
    return self.pack()

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgGroupDelayDepA, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    
SBP_MSG_GROUP_DELAY = 0x0093
class MsgGroupDelay(SBP):
  """SBP class for message MSG_GROUP_DELAY (0x0093).

  You can have MSG_GROUP_DELAY inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  Please see ICD-GPS-200 (30.3.3.3.1.1) for more details.

  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  t_op : GPSTimeSec
    Data Predict Time of Week
  sid : GnssSignal
    GNSS signal identifier
  valid : int
    bit-field indicating validity of the values,
LSB indicating tgd validity etc.
1 = value is valid, 0 = value is not valid.

  tgd : int
  isc_l1ca : int
  isc_l2c : int
  sender : int
    Optional sender ID, defaults to SENDER_ID (see sbp/msg.py).

  """
  _parser = Struct("MsgGroupDelay",
                   Struct('t_op', GPSTimeSec._parser),
                   Struct('sid', GnssSignal._parser),
                   ULInt8('valid'),
                   SLInt16('tgd'),
                   SLInt16('isc_l1ca'),
                   SLInt16('isc_l2c'),)
  __slots__ = [
               't_op',
               'sid',
               'valid',
               'tgd',
               'isc_l1ca',
               'isc_l2c',
              ]

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      super( MsgGroupDelay,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.from_binary(sbp.payload)
    else:
      super( MsgGroupDelay, self).__init__()
      self.msg_type = SBP_MSG_GROUP_DELAY
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.t_op = kwargs.pop('t_op')
      self.sid = kwargs.pop('sid')
      self.valid = kwargs.pop('valid')
      self.tgd = kwargs.pop('tgd')
      self.isc_l1ca = kwargs.pop('isc_l1ca')
      self.isc_l2c = kwargs.pop('isc_l2c')

  def __repr__(self):
    return fmt_repr(self)

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    return MsgGroupDelay.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgGroupDelay(sbp, **d)

 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgGroupDelay._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgGroupDelay._parser.build(c)
    return self.pack()

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgGroupDelay, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    
SBP_MSG_ALMANAC_GPS = 0x0070
class MsgAlmanacGPS(SBP):
  """SBP class for message MSG_ALMANAC_GPS (0x0070).

  You can have MSG_ALMANAC_GPS inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  The almanac message returns a set of satellite orbit parameters. Almanac
data is not very precise and is considered valid for up to several months.
Please see the Navstar GPS Space Segment/Navigation user interfaces
(ICD-GPS-200, Chapter 20.3.3.5.1.2 Almanac Data) for more details.


  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  common : AlmanacCommonContent
    Values common for all almanac types
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
  af0 : double
    Polynomial clock correction coefficient (clock bias)
  af1 : double
    Polynomial clock correction coefficient (clock drift)
  sender : int
    Optional sender ID, defaults to SENDER_ID (see sbp/msg.py).

  """
  _parser = Struct("MsgAlmanacGPS",
                   Struct('common', AlmanacCommonContent._parser),
                   LFloat64('m0'),
                   LFloat64('ecc'),
                   LFloat64('sqrta'),
                   LFloat64('omega0'),
                   LFloat64('omegadot'),
                   LFloat64('w'),
                   LFloat64('inc'),
                   LFloat64('af0'),
                   LFloat64('af1'),)
  __slots__ = [
               'common',
               'm0',
               'ecc',
               'sqrta',
               'omega0',
               'omegadot',
               'w',
               'inc',
               'af0',
               'af1',
              ]

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      super( MsgAlmanacGPS,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.from_binary(sbp.payload)
    else:
      super( MsgAlmanacGPS, self).__init__()
      self.msg_type = SBP_MSG_ALMANAC_GPS
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.common = kwargs.pop('common')
      self.m0 = kwargs.pop('m0')
      self.ecc = kwargs.pop('ecc')
      self.sqrta = kwargs.pop('sqrta')
      self.omega0 = kwargs.pop('omega0')
      self.omegadot = kwargs.pop('omegadot')
      self.w = kwargs.pop('w')
      self.inc = kwargs.pop('inc')
      self.af0 = kwargs.pop('af0')
      self.af1 = kwargs.pop('af1')

  def __repr__(self):
    return fmt_repr(self)

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    return MsgAlmanacGPS.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgAlmanacGPS(sbp, **d)

 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgAlmanacGPS._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgAlmanacGPS._parser.build(c)
    return self.pack()

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgAlmanacGPS, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    
SBP_MSG_ALMANAC_GLO = 0x0071
class MsgAlmanacGlo(SBP):
  """SBP class for message MSG_ALMANAC_GLO (0x0071).

  You can have MSG_ALMANAC_GLO inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  The almanac message returns a set of satellite orbit parameters. Almanac
data is not very precise and is considered valid for up to several months.
Please see the GLO ICD 5.1 "Chapter 4.5 Non-immediate information and
almanac" for details.


  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  common : AlmanacCommonContent
    Values common for all almanac types
  lambda_na : double
    Longitude of the first ascending node of the orbit in PZ-90.02
coordinate system

  t_lambda_na : double
    Time of the first ascending node passage
  i : double
    Value of inclination at instant of t_lambda
  t : double
    Value of Draconian period at instant of t_lambda
  t_dot : double
    Rate of change of the Draconian period
  epsilon : double
    Eccentricity at instant of t_lambda
  omega : double
    Argument of perigee at instant of t_lambda
  sender : int
    Optional sender ID, defaults to SENDER_ID (see sbp/msg.py).

  """
  _parser = Struct("MsgAlmanacGlo",
                   Struct('common', AlmanacCommonContent._parser),
                   LFloat64('lambda_na'),
                   LFloat64('t_lambda_na'),
                   LFloat64('i'),
                   LFloat64('t'),
                   LFloat64('t_dot'),
                   LFloat64('epsilon'),
                   LFloat64('omega'),)
  __slots__ = [
               'common',
               'lambda_na',
               't_lambda_na',
               'i',
               't',
               't_dot',
               'epsilon',
               'omega',
              ]

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      super( MsgAlmanacGlo,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.from_binary(sbp.payload)
    else:
      super( MsgAlmanacGlo, self).__init__()
      self.msg_type = SBP_MSG_ALMANAC_GLO
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.common = kwargs.pop('common')
      self.lambda_na = kwargs.pop('lambda_na')
      self.t_lambda_na = kwargs.pop('t_lambda_na')
      self.i = kwargs.pop('i')
      self.t = kwargs.pop('t')
      self.t_dot = kwargs.pop('t_dot')
      self.epsilon = kwargs.pop('epsilon')
      self.omega = kwargs.pop('omega')

  def __repr__(self):
    return fmt_repr(self)

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    return MsgAlmanacGlo.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgAlmanacGlo(sbp, **d)

 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgAlmanacGlo._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgAlmanacGlo._parser.build(c)
    return self.pack()

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgAlmanacGlo, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    
SBP_MSG_FCNS_GLO = 0x0072
class MsgFcnsGlo(SBP):
  """SBP class for message MSG_FCNS_GLO (0x0072).

  You can have MSG_FCNS_GLO inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  The message reports mapping information regarding GLONASS SV orbital and
frequency slots.
Mapped as follow:
index (SV orbital slot)  fcns[index]
0                        0xFF
1                        FCN for SV orbital slot 1
...                      ...
28                       FCN for SV orbital slot 28
29                       0xFF
30                       0xFF
31                       0xFF


  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  wn : int
    GPS Week number
  tow_ms : int
    GPS Time of week
  fcns : array
    GLONASS fequency number per orbital slot
  sender : int
    Optional sender ID, defaults to SENDER_ID (see sbp/msg.py).

  """
  _parser = Struct("MsgFcnsGlo",
                   ULInt16('wn'),
                   ULInt32('tow_ms'),
                   Struct('fcns', Array(32, ULInt8('fcns'))),)
  __slots__ = [
               'wn',
               'tow_ms',
               'fcns',
              ]

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      super( MsgFcnsGlo,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.from_binary(sbp.payload)
    else:
      super( MsgFcnsGlo, self).__init__()
      self.msg_type = SBP_MSG_FCNS_GLO
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.wn = kwargs.pop('wn')
      self.tow_ms = kwargs.pop('tow_ms')
      self.fcns = kwargs.pop('fcns')

  def __repr__(self):
    return fmt_repr(self)

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    return MsgFcnsGlo.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgFcnsGlo(sbp, **d)

 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgFcnsGlo._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgFcnsGlo._parser.build(c)
    return self.pack()

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgFcnsGlo, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    

msg_classes = {
  0x004A: MsgObs,
  0x0044: MsgBasePosLLH,
  0x0048: MsgBasePosECEF,
  0x0081: MsgEphemerisGPSDepE,
  0x0086: MsgEphemerisGPS,
  0x0082: MsgEphemerisSbasDepA,
  0x0083: MsgEphemerisGloDepA,
  0x0084: MsgEphemerisSbas,
  0x0085: MsgEphemerisGloDepB,
  0x0087: MsgEphemerisGlo,
  0x0080: MsgEphemerisDepD,
  0x001A: MsgEphemerisDepA,
  0x0046: MsgEphemerisDepB,
  0x0047: MsgEphemerisDepC,
  0x0045: MsgObsDepA,
  0x0043: MsgObsDepB,
  0x0049: MsgObsDepC,
  0x0090: MsgIono,
  0x0091: MsgSvConfigurationGPS,
  0x0092: MsgGroupDelayDepA,
  0x0093: MsgGroupDelay,
  0x0070: MsgAlmanacGPS,
  0x0071: MsgAlmanacGlo,
  0x0072: MsgFcnsGlo,
}