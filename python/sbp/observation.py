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

from construct import *
from sbp import SBP
from sbp.utils import fmt_repr
import six

# Automatically generated from piksi/yaml/swiftnav/sbp/observation.yaml
# with generate.py at 2015-04-06 23:40:11.079832. Please do not hand edit!


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

  def __init__(self, payload):
    self.from_binary(payload)

  def __repr__(self):
    return fmt_repr(self)
  
  def from_binary(self, d):
    p = ObsGPSTime._parser.parse(d)
    self.__dict__.update(dict(p.viewitems()))

  def to_binary(self):
    return ObsGPSTime.build(self.__dict__)
    
class CarrierPhase(object):
  """CarrierPhase.
  
  Carrier phase measurement in cycles represented as a 40-bit
fixed point number with Q32.8 layout, i.e. 32-bits of whole
cycles and 8-bits of fractional cycles.

  
  Parameters
  ----------
  i : int
    Carrier phase whole cycles.
  f : int
    Carrier phase fractional part.

  """
  _parser = Embedded(Struct("CarrierPhase",
                     SLInt32('i'),
                     ULInt8('f'),))

  def __init__(self, payload):
    self.from_binary(payload)

  def __repr__(self):
    return fmt_repr(self)
  
  def from_binary(self, d):
    p = CarrierPhase._parser.parse(d)
    self.__dict__.update(dict(p.viewitems()))

  def to_binary(self):
    return CarrierPhase.build(self.__dict__)
    
class ObservationHeader(object):
  """ObservationHeader.
  
  Header of a GPS observation message.
  
  Parameters
  ----------
  t : ObsGPSTime
    GPS time of this observation.
  n_obs : int
    Total number of observations. First nibble is the size
of the sequence (n), second nibble is the zero-indexed
counter (ith packet of n)


  """
  _parser = Embedded(Struct("ObservationHeader",
                     Struct('t', ObsGPSTime._parser),
                     ULInt8('n_obs'),))

  def __init__(self, payload):
    self.from_binary(payload)

  def __repr__(self):
    return fmt_repr(self)
  
  def from_binary(self, d):
    p = ObservationHeader._parser.parse(d)
    self.__dict__.update(dict(p.viewitems()))

  def to_binary(self):
    return ObservationHeader.build(self.__dict__)
    
class PackedObsContent(object):
  """PackedObsContent.
  
  Pseudorange and carrier phase observation for a satellite being
tracked.

  
  Parameters
  ----------
  P : int
    Pseudorange observation.
  L : CarrierPhase
    Carrier phase observation.
  cn0 : int
    Carrier-to-Noise density
  lock : int
    Lock indicator. This value changes whenever a satellite
signal has lost and regained lock, indicating that the
carrier phase ambiguity may have changed. There is no
significance to the value of the lock indicator.

  prn : int
    PRN identifier of the satellite signal

  """
  _parser = Embedded(Struct("PackedObsContent",
                     ULInt32('P'),
                     Struct('L', CarrierPhase._parser),
                     ULInt8('cn0'),
                     ULInt16('lock'),
                     ULInt8('prn'),))

  def __init__(self, payload):
    self.from_binary(payload)

  def __repr__(self):
    return fmt_repr(self)
  
  def from_binary(self, d):
    p = PackedObsContent._parser.parse(d)
    self.__dict__.update(dict(p.viewitems()))

  def to_binary(self):
    return PackedObsContent.build(self.__dict__)
    
SBP_MSG_OBS = 0x0045
class MsgObs(SBP):
  """SBP class for message MSG_OBS (0x0045).
  
  The GPS observations message reports all the pseudo range and
carrier phase observations for the satellites being tracked by
the Piksi.


  Parameters
  ----------
  header : ObservationHeader
    Header of a GPS observation message
  obs : array
    Pseudorange and carrier phase observation for a
satellite being tracked.


  """
  _parser = Struct("MsgObs",
                   Struct('header', ObservationHeader._parser),
                   OptionalGreedyRange(Struct('obs', PackedObsContent._parser)),)

  def __init__(self, sbp):
    self.__dict__.update(sbp.__dict__)
    self.from_binary(sbp.payload)

  def __repr__(self):
    return fmt_repr(self)
 
  def from_binary(self, d):
    p = MsgObs._parser.parse(d)
    self.__dict__.update(dict(p.viewitems()))

  def to_binary(self):
    return MsgObs.build(self.__dict__)
    
SBP_MSG_BASE_POS = 0x0044
class MsgBasePos(SBP):
  """SBP class for message MSG_BASE_POS (0x0044).
  
  This may be the position as reported by the base station itself or the
position obtained from doing a single point solution using the base
station observations.


  Parameters
  ----------
  lat : double
    Latitude
  lon : double
    Longitude
  height : double
    Height

  """
  _parser = Struct("MsgBasePos",
                   LFloat64('lat'),
                   LFloat64('lon'),
                   LFloat64('height'),)

  def __init__(self, sbp):
    self.__dict__.update(sbp.__dict__)
    self.from_binary(sbp.payload)

  def __repr__(self):
    return fmt_repr(self)
 
  def from_binary(self, d):
    p = MsgBasePos._parser.parse(d)
    self.__dict__.update(dict(p.viewitems()))

  def to_binary(self):
    return MsgBasePos.build(self.__dict__)
    

msg_classes = {
  0x0045: MsgObs,
  0x0044: MsgBasePos,
}