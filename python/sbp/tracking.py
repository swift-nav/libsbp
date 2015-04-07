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

# Automatically generated from piksi/yaml/swiftnav/sbp/tracking.yaml
# with generate.py at 2015-04-06 23:40:11.135754. Please do not hand edit!


class TrackingChannelState(object):
  """TrackingChannelState.
  
  Tracking channel state for a specific satellite PRN and measured
signal power.

  
  Parameters
  ----------
  state : int
    Status of tracking channel.
  prn : int
    PRN being tracked.
  cn0 : float
    Carrier-to-noise density

  """
  _parser = Embedded(Struct("TrackingChannelState",
                     ULInt8('state'),
                     ULInt8('prn'),
                     LFloat32('cn0'),))

  def __init__(self, payload):
    self.from_binary(payload)

  def __repr__(self):
    return fmt_repr(self)
  
  def from_binary(self, d):
    p = TrackingChannelState._parser.parse(d)
    self.__dict__.update(dict(p.viewitems()))

  def to_binary(self):
    return TrackingChannelState.build(self.__dict__)
    
SBP_MSG_TRACKING_STATE = 0x0016
class MsgTrackingState(SBP):
  """SBP class for message MSG_TRACKING_STATE (0x0016).
  
  The tracking message returns a variable-length array of tracking
channel states. It reports status and code/carrier phase signal
power measurements for all tracked satellites.


  Parameters
  ----------
  states : array
    Satellite tracking channel state.

  """
  _parser = Struct("MsgTrackingState",
                   OptionalGreedyRange(Struct('states', TrackingChannelState._parser)),)

  def __init__(self, sbp):
    self.__dict__.update(sbp.__dict__)
    self.from_binary(sbp.payload)

  def __repr__(self):
    return fmt_repr(self)
 
  def from_binary(self, d):
    p = MsgTrackingState._parser.parse(d)
    self.__dict__.update(dict(p.viewitems()))

  def to_binary(self):
    return MsgTrackingState.build(self.__dict__)
    
SBP_MSG_EPHEMERIS = 0x001A
class MsgEphemeris(SBP):
  """SBP class for message MSG_EPHEMERIS (0x001A).
  
  The ephemeris message returns a set of satellite orbit
parameters that is used to calculate GPS satellite position,
velocity, and clock offset (WGS84). Please see the Navstar GPS
Space Segment/Navigation user interfaces (ICD-GPS-200, Table
20-III) for more details
(http://www.navcen.uscg.gov/pubs/gps/icd200/icd200cw1234.pdf).


  Parameters
  ----------
  tgd : double
    Group delay differential between L1 and L2 (?)
  crs : double
    Amplitude of the sine harmonic correction term to the orbit radius
  crc : double
    Amplitude of the cosine harmonic correction term to the orbit radius
  cuc : double
    Amplitude of the cosine harmonic correction term to the argument of latitude
  cus : double
    Amplitude of the sine harmonic correction term to the argument of latitude
  cic : double
    Amplitude of the cosine harmonic correction term to the angle of inclination
  cis : double
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

  """
  _parser = Struct("MsgEphemeris",
                   LFloat64('tgd'),
                   LFloat64('crs'),
                   LFloat64('crc'),
                   LFloat64('cuc'),
                   LFloat64('cus'),
                   LFloat64('cic'),
                   LFloat64('cis'),
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

  def __init__(self, sbp):
    self.__dict__.update(sbp.__dict__)
    self.from_binary(sbp.payload)

  def __repr__(self):
    return fmt_repr(self)
 
  def from_binary(self, d):
    p = MsgEphemeris._parser.parse(d)
    self.__dict__.update(dict(p.viewitems()))

  def to_binary(self):
    return MsgEphemeris.build(self.__dict__)
    

msg_classes = {
  0x0016: MsgTrackingState,
  0x001A: MsgEphemeris,
}