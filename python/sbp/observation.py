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
Satellite observation messages from the device.
"""

import json

import construct

from sbp.msg import SBP, SENDER_ID
from sbp.utils import fmt_repr, exclude_fields, walk_json_dict, containerize
from sbp.gnss import *

# Automatically generated from piksi/yaml/swiftnav/sbp/observation.yaml with generate.py.
# Please do not hand edit!


class ObservationHeader(object):
  """ObservationHeader.
  
  Header of a GNSS observation message.
  
  Parameters
  ----------
  t : GPSTime
    GNSS time of this observation
  n_obs : int
    Total number of observations. First nibble is the size
of the sequence (n), second nibble is the zero-indexed
counter (ith packet of n)


  """
  _parser = construct.Embedded(construct.Struct(
                     't' / construct.Struct(GPSTime._parser),
                     'n_obs' / construct.Int8ul,))
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
  _parser = construct.Embedded(construct.Struct(
                     'i' / construct.Int16sl,
                     'f' / construct.Int8ul,))
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

  sid : GnssSignal
    GNSS signal identifier (16 bit)

  """
  _parser = construct.Embedded(construct.Struct(
                     'P' / construct.Int32ul,
                     'L' / construct.Struct(CarrierPhase._parser),
                     'D' / construct.Struct(Doppler._parser),
                     'cn0' / construct.Int8ul,
                     'lock' / construct.Int8ul,
                     'flags' / construct.Int8ul,
                     'sid' / construct.Struct(GnssSignal._parser),))
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
  sid : GnssSignal
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
  _parser = construct.Embedded(construct.Struct(
                     'sid' / construct.Struct(GnssSignal._parser),
                     'toe' / construct.Struct(GPSTimeSec._parser),
                     'ura' / construct.Float64l,
                     'fit_interval' / construct.Int32ul,
                     'valid' / construct.Int8ul,
                     'health_bits' / construct.Int8ul,))
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
  sid : GnssSignalDep
    GNSS signal identifier
  toe : GPSTimeDep
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
  _parser = construct.Embedded(construct.Struct(
                     'sid' / construct.Struct(GnssSignalDep._parser),
                     'toe' / construct.Struct(GPSTimeDep._parser),
                     'ura' / construct.Float64l,
                     'fit_interval' / construct.Int32ul,
                     'valid' / construct.Int8ul,
                     'health_bits' / construct.Int8ul,))
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
  t : GPSTimeDep
    GPS time of this observation
  n_obs : int
    Total number of observations. First nibble is the size
of the sequence (n), second nibble is the zero-indexed
counter (ith packet of n)


  """
  _parser = construct.Embedded(construct.Struct(
                     't' / construct.Struct(GPSTimeDep._parser),
                     'n_obs' / construct.Int8ul,))
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
  _parser = construct.Embedded(construct.Struct(
                     'i' / construct.Int32sl,
                     'f' / construct.Int8ul,))
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
  _parser = construct.Embedded(construct.Struct(
                     'P' / construct.Int32ul,
                     'L' / construct.Struct(CarrierPhaseDepA._parser),
                     'cn0' / construct.Int8ul,
                     'lock' / construct.Int16ul,
                     'prn' / construct.Int8ul,))
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

  sid : GnssSignalDep
    GNSS signal identifier

  """
  _parser = construct.Embedded(construct.Struct(
                     'P' / construct.Int32ul,
                     'L' / construct.Struct(CarrierPhaseDepA._parser),
                     'cn0' / construct.Int8ul,
                     'lock' / construct.Int16ul,
                     'sid' / construct.Struct(GnssSignalDep._parser),))
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

  sid : GnssSignalDep
    GNSS signal identifier

  """
  _parser = construct.Embedded(construct.Struct(
                     'P' / construct.Int32ul,
                     'L' / construct.Struct(CarrierPhase._parser),
                     'cn0' / construct.Int8ul,
                     'lock' / construct.Int16ul,
                     'sid' / construct.Struct(GnssSignalDep._parser),))
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
  _parser = construct.Embedded(construct.Struct(
                     'sid' / construct.Struct(GnssSignal._parser),
                     'toa' / construct.Struct(GPSTimeSec._parser),
                     'ura' / construct.Float64l,
                     'fit_interval' / construct.Int32ul,
                     'valid' / construct.Int8ul,
                     'health_bits' / construct.Int8ul,))
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
    
class AlmanacCommonContentDep(object):
  """AlmanacCommonContentDep.
  
  
  Parameters
  ----------
  sid : GnssSignalDep
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
  _parser = construct.Embedded(construct.Struct(
                     'sid' / construct.Struct(GnssSignalDep._parser),
                     'toa' / construct.Struct(GPSTimeSec._parser),
                     'ura' / construct.Float64l,
                     'fit_interval' / construct.Int32ul,
                     'valid' / construct.Int8ul,
                     'health_bits' / construct.Int8ul,))
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
    p = AlmanacCommonContentDep._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    d = dict([(k, getattr(obj, k)) for k in self.__slots__])
    return AlmanacCommonContentDep.build(d)
    
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
  _parser = construct.Struct(
                   'header' / construct.Struct(ObservationHeader._parser),
                   construct.GreedyRange('obs' / construct.Struct(PackedObsContent._parser)),)
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
  _parser = construct.Struct(
                   'lat' / construct.Float64l,
                   'lon' / construct.Float64l,
                   'height' / construct.Float64l,)
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
  _parser = construct.Struct(
                   'x' / construct.Float64l,
                   'y' / construct.Float64l,
                   'z' / construct.Float64l,)
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
  toc : GPSTimeDep
    Clock reference
  iode : int
    Issue of ephemeris data
  iodc : int
    Issue of clock data
  sender : int
    Optional sender ID, defaults to SENDER_ID (see sbp/msg.py).

  """
  _parser = construct.Struct(
                   'common' / construct.Struct(EphemerisCommonContentDepA._parser),
                   'tgd' / construct.Float64l,
                   'c_rs' / construct.Float64l,
                   'c_rc' / construct.Float64l,
                   'c_uc' / construct.Float64l,
                   'c_us' / construct.Float64l,
                   'c_ic' / construct.Float64l,
                   'c_is' / construct.Float64l,
                   'dn' / construct.Float64l,
                   'm0' / construct.Float64l,
                   'ecc' / construct.Float64l,
                   'sqrta' / construct.Float64l,
                   'omega0' / construct.Float64l,
                   'omegadot' / construct.Float64l,
                   'w' / construct.Float64l,
                   'inc' / construct.Float64l,
                   'inc_dot' / construct.Float64l,
                   'af0' / construct.Float64l,
                   'af1' / construct.Float64l,
                   'af2' / construct.Float64l,
                   'toc' / construct.Struct(GPSTimeDep._parser),
                   'iode' / construct.Int8ul,
                   'iodc' / construct.Int16ul,)
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
  _parser = construct.Struct(
                   'common' / construct.Struct(EphemerisCommonContent._parser),
                   'tgd' / construct.Float64l,
                   'c_rs' / construct.Float64l,
                   'c_rc' / construct.Float64l,
                   'c_uc' / construct.Float64l,
                   'c_us' / construct.Float64l,
                   'c_ic' / construct.Float64l,
                   'c_is' / construct.Float64l,
                   'dn' / construct.Float64l,
                   'm0' / construct.Float64l,
                   'ecc' / construct.Float64l,
                   'sqrta' / construct.Float64l,
                   'omega0' / construct.Float64l,
                   'omegadot' / construct.Float64l,
                   'w' / construct.Float64l,
                   'inc' / construct.Float64l,
                   'inc_dot' / construct.Float64l,
                   'af0' / construct.Float64l,
                   'af1' / construct.Float64l,
                   'af2' / construct.Float64l,
                   'toc' / construct.Struct(GPSTimeSec._parser),
                   'iode' / construct.Int8ul,
                   'iodc' / construct.Int16ul,)
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
  _parser = construct.Struct(
                   'common' / construct.Struct(EphemerisCommonContentDepA._parser),
                   'pos' / construct.Array(3, construct.Float64l),
                   'vel' / construct.Array(3, construct.Float64l),
                   'acc' / construct.Array(3, construct.Float64l),
                   'a_gf0' / construct.Float64l,
                   'a_gf1' / construct.Float64l,)
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
  _parser = construct.Struct(
                   'common' / construct.Struct(EphemerisCommonContentDepA._parser),
                   'gamma' / construct.Float64l,
                   'tau' / construct.Float64l,
                   'pos' / construct.Array(3, construct.Float64l),
                   'vel' / construct.Array(3, construct.Float64l),
                   'acc' / construct.Array(3, construct.Float64l),)
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
  _parser = construct.Struct(
                   'common' / construct.Struct(EphemerisCommonContent._parser),
                   'pos' / construct.Array(3, construct.Float64l),
                   'vel' / construct.Array(3, construct.Float64l),
                   'acc' / construct.Array(3, construct.Float64l),
                   'a_gf0' / construct.Float64l,
                   'a_gf1' / construct.Float64l,)
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
  _parser = construct.Struct(
                   'common' / construct.Struct(EphemerisCommonContent._parser),
                   'gamma' / construct.Float64l,
                   'tau' / construct.Float64l,
                   'pos' / construct.Array(3, construct.Float64l),
                   'vel' / construct.Array(3, construct.Float64l),
                   'acc' / construct.Array(3, construct.Float64l),)
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
    
SBP_MSG_EPHEMERIS_GLO_DEP_C = 0x0087
class MsgEphemerisGloDepC(SBP):
  """SBP class for message MSG_EPHEMERIS_GLO_DEP_C (0x0087).

  You can have MSG_EPHEMERIS_GLO_DEP_C inherit its fields directly
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
  _parser = construct.Struct(
                   'common' / construct.Struct(EphemerisCommonContent._parser),
                   'gamma' / construct.Float64l,
                   'tau' / construct.Float64l,
                   'd_tau' / construct.Float64l,
                   'pos' / construct.Array(3, construct.Float64l),
                   'vel' / construct.Array(3, construct.Float64l),
                   'acc' / construct.Array(3, construct.Float64l),
                   'fcn' / construct.Int8ul,)
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
      super( MsgEphemerisGloDepC,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.from_binary(sbp.payload)
    else:
      super( MsgEphemerisGloDepC, self).__init__()
      self.msg_type = SBP_MSG_EPHEMERIS_GLO_DEP_C
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
    return MsgEphemerisGloDepC.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgEphemerisGloDepC(sbp, **d)

 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgEphemerisGloDepC._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgEphemerisGloDepC._parser.build(c)
    return self.pack()

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgEphemerisGloDepC, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    
SBP_MSG_EPHEMERIS_GLO = 0x0088
class MsgEphemerisGlo(SBP):
  """SBP class for message MSG_EPHEMERIS_GLO (0x0088).

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
  iod : int
    Issue of ephemeris data
  sender : int
    Optional sender ID, defaults to SENDER_ID (see sbp/msg.py).

  """
  _parser = construct.Struct(
                   'common' / construct.Struct(EphemerisCommonContent._parser),
                   'gamma' / construct.Float64l,
                   'tau' / construct.Float64l,
                   'd_tau' / construct.Float64l,
                   'pos' / construct.Array(3, construct.Float64l),
                   'vel' / construct.Array(3, construct.Float64l),
                   'acc' / construct.Array(3, construct.Float64l),
                   'fcn' / construct.Int8ul,
                   'iod' / construct.Int8ul,)
  __slots__ = [
               'common',
               'gamma',
               'tau',
               'd_tau',
               'pos',
               'vel',
               'acc',
               'fcn',
               'iod',
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
      self.iod = kwargs.pop('iod')

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
  sid : GnssSignalDep
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
  _parser = construct.Struct(
                   'tgd' / construct.Float64l,
                   'c_rs' / construct.Float64l,
                   'c_rc' / construct.Float64l,
                   'c_uc' / construct.Float64l,
                   'c_us' / construct.Float64l,
                   'c_ic' / construct.Float64l,
                   'c_is' / construct.Float64l,
                   'dn' / construct.Float64l,
                   'm0' / construct.Float64l,
                   'ecc' / construct.Float64l,
                   'sqrta' / construct.Float64l,
                   'omega0' / construct.Float64l,
                   'omegadot' / construct.Float64l,
                   'w' / construct.Float64l,
                   'inc' / construct.Float64l,
                   'inc_dot' / construct.Float64l,
                   'af0' / construct.Float64l,
                   'af1' / construct.Float64l,
                   'af2' / construct.Float64l,
                   'toe_tow' / construct.Float64l,
                   'toe_wn' / construct.Int16ul,
                   'toc_tow' / construct.Float64l,
                   'toc_wn' / construct.Int16ul,
                   'valid' / construct.Int8ul,
                   'healthy' / construct.Int8ul,
                   'sid' / construct.Struct(GnssSignalDep._parser),
                   'iode' / construct.Int8ul,
                   'iodc' / construct.Int16ul,
                   'reserved' / construct.Int32ul,)
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
  _parser = construct.Struct(
                   'tgd' / construct.Float64l,
                   'c_rs' / construct.Float64l,
                   'c_rc' / construct.Float64l,
                   'c_uc' / construct.Float64l,
                   'c_us' / construct.Float64l,
                   'c_ic' / construct.Float64l,
                   'c_is' / construct.Float64l,
                   'dn' / construct.Float64l,
                   'm0' / construct.Float64l,
                   'ecc' / construct.Float64l,
                   'sqrta' / construct.Float64l,
                   'omega0' / construct.Float64l,
                   'omegadot' / construct.Float64l,
                   'w' / construct.Float64l,
                   'inc' / construct.Float64l,
                   'inc_dot' / construct.Float64l,
                   'af0' / construct.Float64l,
                   'af1' / construct.Float64l,
                   'af2' / construct.Float64l,
                   'toe_tow' / construct.Float64l,
                   'toe_wn' / construct.Int16ul,
                   'toc_tow' / construct.Float64l,
                   'toc_wn' / construct.Int16ul,
                   'valid' / construct.Int8ul,
                   'healthy' / construct.Int8ul,
                   'prn' / construct.Int8ul,)
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
  _parser = construct.Struct(
                   'tgd' / construct.Float64l,
                   'c_rs' / construct.Float64l,
                   'c_rc' / construct.Float64l,
                   'c_uc' / construct.Float64l,
                   'c_us' / construct.Float64l,
                   'c_ic' / construct.Float64l,
                   'c_is' / construct.Float64l,
                   'dn' / construct.Float64l,
                   'm0' / construct.Float64l,
                   'ecc' / construct.Float64l,
                   'sqrta' / construct.Float64l,
                   'omega0' / construct.Float64l,
                   'omegadot' / construct.Float64l,
                   'w' / construct.Float64l,
                   'inc' / construct.Float64l,
                   'inc_dot' / construct.Float64l,
                   'af0' / construct.Float64l,
                   'af1' / construct.Float64l,
                   'af2' / construct.Float64l,
                   'toe_tow' / construct.Float64l,
                   'toe_wn' / construct.Int16ul,
                   'toc_tow' / construct.Float64l,
                   'toc_wn' / construct.Int16ul,
                   'valid' / construct.Int8ul,
                   'healthy' / construct.Int8ul,
                   'prn' / construct.Int8ul,
                   'iode' / construct.Int8ul,)
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
  sid : GnssSignalDep
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
  _parser = construct.Struct(
                   'tgd' / construct.Float64l,
                   'c_rs' / construct.Float64l,
                   'c_rc' / construct.Float64l,
                   'c_uc' / construct.Float64l,
                   'c_us' / construct.Float64l,
                   'c_ic' / construct.Float64l,
                   'c_is' / construct.Float64l,
                   'dn' / construct.Float64l,
                   'm0' / construct.Float64l,
                   'ecc' / construct.Float64l,
                   'sqrta' / construct.Float64l,
                   'omega0' / construct.Float64l,
                   'omegadot' / construct.Float64l,
                   'w' / construct.Float64l,
                   'inc' / construct.Float64l,
                   'inc_dot' / construct.Float64l,
                   'af0' / construct.Float64l,
                   'af1' / construct.Float64l,
                   'af2' / construct.Float64l,
                   'toe_tow' / construct.Float64l,
                   'toe_wn' / construct.Int16ul,
                   'toc_tow' / construct.Float64l,
                   'toc_wn' / construct.Int16ul,
                   'valid' / construct.Int8ul,
                   'healthy' / construct.Int8ul,
                   'sid' / construct.Struct(GnssSignalDep._parser),
                   'iode' / construct.Int8ul,
                   'iodc' / construct.Int16ul,
                   'reserved' / construct.Int32ul,)
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
  _parser = construct.Struct(
                   'header' / construct.Struct(ObservationHeaderDep._parser),
                   construct.GreedyRange('obs' / construct.Struct(PackedObsContentDepA._parser)),)
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
  _parser = construct.Struct(
                   'header' / construct.Struct(ObservationHeaderDep._parser),
                   construct.GreedyRange('obs' / construct.Struct(PackedObsContentDepB._parser)),)
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
  _parser = construct.Struct(
                   'header' / construct.Struct(ObservationHeaderDep._parser),
                   construct.GreedyRange('obs' / construct.Struct(PackedObsContentDepC._parser)),)
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
  _parser = construct.Struct(
                   't_nmct' / construct.Struct(GPSTimeSec._parser),
                   'a0' / construct.Float64l,
                   'a1' / construct.Float64l,
                   'a2' / construct.Float64l,
                   'a3' / construct.Float64l,
                   'b0' / construct.Float64l,
                   'b1' / construct.Float64l,
                   'b2' / construct.Float64l,
                   'b3' / construct.Float64l,)
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
  _parser = construct.Struct(
                   't_nmct' / construct.Struct(GPSTimeSec._parser),
                   'l2c_mask' / construct.Int32ul,)
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
  t_op : GPSTimeDep
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
  _parser = construct.Struct(
                   't_op' / construct.Struct(GPSTimeDep._parser),
                   'prn' / construct.Int8ul,
                   'valid' / construct.Int8ul,
                   'tgd' / construct.Int16sl,
                   'isc_l1ca' / construct.Int16sl,
                   'isc_l2c' / construct.Int16sl,)
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
    
SBP_MSG_GROUP_DELAY_DEP_B = 0x0093
class MsgGroupDelayDepB(SBP):
  """SBP class for message MSG_GROUP_DELAY_DEP_B (0x0093).

  You can have MSG_GROUP_DELAY_DEP_B inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  Please see ICD-GPS-200 (30.3.3.3.1.1) for more details.

  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  t_op : GPSTimeSec
    Data Predict Time of Week
  sid : GnssSignalDep
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
  _parser = construct.Struct(
                   't_op' / construct.Struct(GPSTimeSec._parser),
                   'sid' / construct.Struct(GnssSignalDep._parser),
                   'valid' / construct.Int8ul,
                   'tgd' / construct.Int16sl,
                   'isc_l1ca' / construct.Int16sl,
                   'isc_l2c' / construct.Int16sl,)
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
      super( MsgGroupDelayDepB,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.from_binary(sbp.payload)
    else:
      super( MsgGroupDelayDepB, self).__init__()
      self.msg_type = SBP_MSG_GROUP_DELAY_DEP_B
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
    return MsgGroupDelayDepB.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgGroupDelayDepB(sbp, **d)

 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgGroupDelayDepB._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgGroupDelayDepB._parser.build(c)
    return self.pack()

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgGroupDelayDepB, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    
SBP_MSG_GROUP_DELAY = 0x0094
class MsgGroupDelay(SBP):
  """SBP class for message MSG_GROUP_DELAY (0x0094).

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
  _parser = construct.Struct(
                   't_op' / construct.Struct(GPSTimeSec._parser),
                   'sid' / construct.Struct(GnssSignal._parser),
                   'valid' / construct.Int8ul,
                   'tgd' / construct.Int16sl,
                   'isc_l1ca' / construct.Int16sl,
                   'isc_l2c' / construct.Int16sl,)
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
    
SBP_MSG_ALMANAC_GPS_DEP = 0x0070
class MsgAlmanacGPSDep(SBP):
  """SBP class for message MSG_ALMANAC_GPS_DEP (0x0070).

  You can have MSG_ALMANAC_GPS_DEP inherit its fields directly
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
  common : AlmanacCommonContentDep
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
  _parser = construct.Struct(
                   'common' / construct.Struct(AlmanacCommonContentDep._parser),
                   'm0' / construct.Float64l,
                   'ecc' / construct.Float64l,
                   'sqrta' / construct.Float64l,
                   'omega0' / construct.Float64l,
                   'omegadot' / construct.Float64l,
                   'w' / construct.Float64l,
                   'inc' / construct.Float64l,
                   'af0' / construct.Float64l,
                   'af1' / construct.Float64l,)
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
      super( MsgAlmanacGPSDep,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.from_binary(sbp.payload)
    else:
      super( MsgAlmanacGPSDep, self).__init__()
      self.msg_type = SBP_MSG_ALMANAC_GPS_DEP
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
    return MsgAlmanacGPSDep.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgAlmanacGPSDep(sbp, **d)

 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgAlmanacGPSDep._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgAlmanacGPSDep._parser.build(c)
    return self.pack()

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgAlmanacGPSDep, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    
SBP_MSG_ALMANAC_GPS = 0x0072
class MsgAlmanacGPS(SBP):
  """SBP class for message MSG_ALMANAC_GPS (0x0072).

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
  _parser = construct.Struct(
                   'common' / construct.Struct(AlmanacCommonContent._parser),
                   'm0' / construct.Float64l,
                   'ecc' / construct.Float64l,
                   'sqrta' / construct.Float64l,
                   'omega0' / construct.Float64l,
                   'omegadot' / construct.Float64l,
                   'w' / construct.Float64l,
                   'inc' / construct.Float64l,
                   'af0' / construct.Float64l,
                   'af1' / construct.Float64l,)
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
    
SBP_MSG_ALMANAC_GLO_DEP = 0x0071
class MsgAlmanacGloDep(SBP):
  """SBP class for message MSG_ALMANAC_GLO_DEP (0x0071).

  You can have MSG_ALMANAC_GLO_DEP inherit its fields directly
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
  common : AlmanacCommonContentDep
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
  _parser = construct.Struct(
                   'common' / construct.Struct(AlmanacCommonContentDep._parser),
                   'lambda_na' / construct.Float64l,
                   't_lambda_na' / construct.Float64l,
                   'i' / construct.Float64l,
                   't' / construct.Float64l,
                   't_dot' / construct.Float64l,
                   'epsilon' / construct.Float64l,
                   'omega' / construct.Float64l,)
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
      super( MsgAlmanacGloDep,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.from_binary(sbp.payload)
    else:
      super( MsgAlmanacGloDep, self).__init__()
      self.msg_type = SBP_MSG_ALMANAC_GLO_DEP
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
    return MsgAlmanacGloDep.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgAlmanacGloDep(sbp, **d)

 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgAlmanacGloDep._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgAlmanacGloDep._parser.build(c)
    return self.pack()

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgAlmanacGloDep, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    
SBP_MSG_ALMANAC_GLO = 0x0073
class MsgAlmanacGlo(SBP):
  """SBP class for message MSG_ALMANAC_GLO (0x0073).

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
  _parser = construct.Struct(
                   'common' / construct.Struct(AlmanacCommonContent._parser),
                   'lambda_na' / construct.Float64l,
                   't_lambda_na' / construct.Float64l,
                   'i' / construct.Float64l,
                   't' / construct.Float64l,
                   't_dot' / construct.Float64l,
                   'epsilon' / construct.Float64l,
                   'omega' / construct.Float64l,)
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
    
SBP_MSG_GLO_BIASES = 0x0075
class MsgGloBiases(SBP):
  """SBP class for message MSG_GLO_BIASES (0x0075).

  You can have MSG_GLO_BIASES inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  The GLONASS L1/L2 Code-Phase biases allows to perform 
GPS+GLONASS integer ambiguity resolution for baselines
with mixed receiver types (e.g. receiver of different
manufacturers)


  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  mask : int
    GLONASS FDMA signals mask
  l1ca_bias : int
    GLONASS L1 C/A Code-Phase Bias
  l1p_bias : int
    GLONASS L1 P Code-Phase Bias
  l2ca_bias : int
    GLONASS L2 C/A Code-Phase Bias
  l2p_bias : int
    GLONASS L2 P Code-Phase Bias
  sender : int
    Optional sender ID, defaults to SENDER_ID (see sbp/msg.py).

  """
  _parser = construct.Struct(
                   'mask' / construct.Int8ul,
                   'l1ca_bias' / construct.Int16sl,
                   'l1p_bias' / construct.Int16sl,
                   'l2ca_bias' / construct.Int16sl,
                   'l2p_bias' / construct.Int16sl,)
  __slots__ = [
               'mask',
               'l1ca_bias',
               'l1p_bias',
               'l2ca_bias',
               'l2p_bias',
              ]

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      super( MsgGloBiases,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.from_binary(sbp.payload)
    else:
      super( MsgGloBiases, self).__init__()
      self.msg_type = SBP_MSG_GLO_BIASES
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.mask = kwargs.pop('mask')
      self.l1ca_bias = kwargs.pop('l1ca_bias')
      self.l1p_bias = kwargs.pop('l1p_bias')
      self.l2ca_bias = kwargs.pop('l2ca_bias')
      self.l2p_bias = kwargs.pop('l2p_bias')

  def __repr__(self):
    return fmt_repr(self)

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    return MsgGloBiases.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgGloBiases(sbp, **d)

 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgGloBiases._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgGloBiases._parser.build(c)
    return self.pack()

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgGloBiases, self).to_json_dict()
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
  0x0087: MsgEphemerisGloDepC,
  0x0088: MsgEphemerisGlo,
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
  0x0093: MsgGroupDelayDepB,
  0x0094: MsgGroupDelay,
  0x0070: MsgAlmanacGPSDep,
  0x0072: MsgAlmanacGPS,
  0x0071: MsgAlmanacGloDep,
  0x0073: MsgAlmanacGlo,
  0x0075: MsgGloBiases,
}