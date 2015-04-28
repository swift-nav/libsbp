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
Satellite code and carrier-phase tracking messages from the device.

"""

from construct import *
import json
from sbp import SBP
from sbp.utils import fmt_repr, exclude_fields, walk_json_dict, containerize
import six

# Automatically generated from piksi/yaml/swiftnav/sbp/tracking.yaml with generate.py.
# Please do not hand edit!


class TrackingChannelState(object):
  """TrackingChannelState.
  
  Tracking channel state for a specific satellite PRN and measured
signal power.

  
  Parameters
  ----------
  state : int
    Status of tracking channel
  prn : int
    PRN-1 being tracked
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

  You can have MSG_TRACKING_STATE inherent its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  The tracking message returns a variable-length array of tracking
channel states. It reports status and snr power measurements for
all tracked satellites.


  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  states : array
    Satellite tracking channel state
  sender : int
    Optional sender ID, defaults to 0

  """
  _parser = Struct("MsgTrackingState",
                   OptionalGreedyRange(Struct('states', TrackingChannelState._parser)),)

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      self.__dict__.update(sbp.__dict__)
      self.from_binary(sbp.payload)
    else:
      super( MsgTrackingState, self).__init__()
      self.msg_type = SBP_MSG_TRACKING_STATE
      self.sender = kwargs.pop('sender', 0)
      self.states = kwargs.pop('states')

  def __repr__(self):
    return fmt_repr(self)
 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgTrackingState._parser.parse(d)
    self.__dict__.update(dict(p.viewitems()))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgTrackingState._parser.build(c)
    return self.pack()

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    sbp = SBP.from_json_dict(d)
    return MsgTrackingState(sbp)

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgTrackingState, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    
SBP_MSG_EPHEMERIS_OLD = 0x001A
class MsgEphemerisOld(SBP):
  """SBP class for message MSG_EPHEMERIS_OLD (0x001A).

  You can have MSG_EPHEMERIS_OLD inherent its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  Deprecated, use MSG_EPHEMERIS (0x0046).


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
    Optional sender ID, defaults to 0

  """
  _parser = Struct("MsgEphemerisOld",
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

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      self.__dict__.update(sbp.__dict__)
      self.from_binary(sbp.payload)
    else:
      super( MsgEphemerisOld, self).__init__()
      self.msg_type = SBP_MSG_EPHEMERIS_OLD
      self.sender = kwargs.pop('sender', 0)
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
    p = MsgEphemerisOld._parser.parse(d)
    self.__dict__.update(dict(p.viewitems()))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgEphemerisOld._parser.build(c)
    return self.pack()

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    sbp = SBP.from_json_dict(d)
    return MsgEphemerisOld(sbp)

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgEphemerisOld, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    

msg_classes = {
  0x0016: MsgTrackingState,
  0x001A: MsgEphemerisOld,
}