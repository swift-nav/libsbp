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
from sbp.msg import SBP, SENDER_ID
from sbp.utils import fmt_repr, exclude_fields, walk_json_dict, containerize, greedy_string
from sbp.gnss import *

# Automatically generated from piksi/yaml/swiftnav/sbp/tracking.yaml with generate.py.
# Please do not hand edit!


class TrackingChannelState(object):
  """TrackingChannelState.
  
  Tracking channel state for a specific satellite signal and
measured signal power.

  
  Parameters
  ----------
  sid : GnssSignal16
    GNSS signal being tracked
  fcn : int
    Frequency channel number (GLONASS only)
  cn0 : int
    Carrier-to-Noise density.  Zero implies invalid cn0.

  """
  _parser = Embedded(Struct("TrackingChannelState",
                     Struct('sid', GnssSignal16._parser),
                     ULInt8('fcn'),
                     ULInt8('cn0'),))
  __slots__ = [
               'sid',
               'fcn',
               'cn0',
              ]

  def __init__(self, payload=None, **kwargs):
    if payload:
      self.from_binary(payload)
    else:
      self.sid = kwargs.pop('sid')
      self.fcn = kwargs.pop('fcn')
      self.cn0 = kwargs.pop('cn0')

  def __repr__(self):
    return fmt_repr(self)
  
  def from_binary(self, d):
    p = TrackingChannelState._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    d = dict([(k, getattr(obj, k)) for k in self.__slots__])
    return TrackingChannelState.build(d)
    
class TrackingChannelCorrelation(object):
  """TrackingChannelCorrelation.
  
  Structure containing in-phase and quadrature correlation components.

  
  Parameters
  ----------
  I : int
    In-phase correlation
  Q : int
    Quadrature correlation

  """
  _parser = Embedded(Struct("TrackingChannelCorrelation",
                     SLInt32('I'),
                     SLInt32('Q'),))
  __slots__ = [
               'I',
               'Q',
              ]

  def __init__(self, payload=None, **kwargs):
    if payload:
      self.from_binary(payload)
    else:
      self.I = kwargs.pop('I')
      self.Q = kwargs.pop('Q')

  def __repr__(self):
    return fmt_repr(self)
  
  def from_binary(self, d):
    p = TrackingChannelCorrelation._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    d = dict([(k, getattr(obj, k)) for k in self.__slots__])
    return TrackingChannelCorrelation.build(d)
    
class TrackingChannelStateDepA(object):
  """TrackingChannelStateDepA.
  
  Deprecated.
  
  Parameters
  ----------
  state : int
    Status of tracking channel
  prn : int
    PRN-1 being tracked
  cn0 : float
    Carrier-to-noise density

  """
  _parser = Embedded(Struct("TrackingChannelStateDepA",
                     ULInt8('state'),
                     ULInt8('prn'),
                     LFloat32('cn0'),))
  __slots__ = [
               'state',
               'prn',
               'cn0',
              ]

  def __init__(self, payload=None, **kwargs):
    if payload:
      self.from_binary(payload)
    else:
      self.state = kwargs.pop('state')
      self.prn = kwargs.pop('prn')
      self.cn0 = kwargs.pop('cn0')

  def __repr__(self):
    return fmt_repr(self)
  
  def from_binary(self, d):
    p = TrackingChannelStateDepA._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    d = dict([(k, getattr(obj, k)) for k in self.__slots__])
    return TrackingChannelStateDepA.build(d)
    
class TrackingChannelStateDepB(object):
  """TrackingChannelStateDepB.
  
  Deprecated.
  
  Parameters
  ----------
  state : int
    Status of tracking channel
  sid : GnssSignal
    GNSS signal being tracked
  cn0 : float
    Carrier-to-noise density

  """
  _parser = Embedded(Struct("TrackingChannelStateDepB",
                     ULInt8('state'),
                     Struct('sid', GnssSignal._parser),
                     LFloat32('cn0'),))
  __slots__ = [
               'state',
               'sid',
               'cn0',
              ]

  def __init__(self, payload=None, **kwargs):
    if payload:
      self.from_binary(payload)
    else:
      self.state = kwargs.pop('state')
      self.sid = kwargs.pop('sid')
      self.cn0 = kwargs.pop('cn0')

  def __repr__(self):
    return fmt_repr(self)
  
  def from_binary(self, d):
    p = TrackingChannelStateDepB._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    d = dict([(k, getattr(obj, k)) for k in self.__slots__])
    return TrackingChannelStateDepB.build(d)
    
SBP_MSG_TRACKING_STATE_DETAILED = 0x0011
class MsgTrackingStateDetailed(SBP):
  """SBP class for message MSG_TRACKING_STATE_DETAILED (0x0011).

  You can have MSG_TRACKING_STATE_DETAILED inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  The tracking message returns a set tracking channel parameters for a
single tracking channel useful for debugging issues.


  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  recv_time : int
    Receiver clock time.
  tot : GPSTime
    Time of transmission of signal from satellite. TOW only valid when
TOW status is decoded or propagated. WN only valid when week
number valid flag is set.

  P : int
    Pseudorange observation. Valid only when pseudorange valid flag is
set.

  P_std : int
    Pseudorange observation standard deviation. Valid only when
pseudorange valid flag is set.

  L : CarrierPhase
    Carrier phase observation with typical sign convention. Valid only
when PLL pessimistic lock is achieved.

  cn0 : int
    Carrier-to-Noise density
  lock : int
    Lock time. It is encoded according to DF402 from the RTCM 10403.2
Amendment 2 specification. Valid values range from 0 to 15.

  sid : GnssSignal
    GNSS signal identifier.
  doppler : int
    Carrier Doppler frequency.
  doppler_std : int
    Carrier Doppler frequency standard deviation.
  uptime : int
    Number of seconds of continuous tracking. Specifies how much time
signal is in continuous track.

  clock_offset : int
    TCXO clock offset. Valid only when valid clock valid flag is set.

  clock_drift : int
    TCXO clock drift. Valid only when valid clock valid flag is set.

  corr_spacing : int
    Early-Prompt (EP) and Prompt-Late (PL) correlators spacing.
  acceleration : int
    Acceleration. Valid only when acceleration valid flag is set.
  sync_flags : int
    Synchronization status flags.
  tow_flags : int
    TOW status flags.
  track_flags : int
    Tracking loop status flags.
  nav_flags : int
    Navigation data status flags.
  pset_flags : int
    Parameters sets flags.
  misc_flags : int
    Miscellaneous flags.
  sender : int
    Optional sender ID, defaults to SENDER_ID (see sbp/msg.py).

  """
  _parser = Struct("MsgTrackingStateDetailed",
                   ULInt64('recv_time'),
                   Struct('tot', GPSTime._parser),
                   ULInt32('P'),
                   ULInt16('P_std'),
                   Struct('L', CarrierPhase._parser),
                   ULInt8('cn0'),
                   ULInt16('lock'),
                   Struct('sid', GnssSignal._parser),
                   SLInt32('doppler'),
                   ULInt16('doppler_std'),
                   ULInt32('uptime'),
                   SLInt16('clock_offset'),
                   SLInt16('clock_drift'),
                   ULInt16('corr_spacing'),
                   SLInt8('acceleration'),
                   ULInt8('sync_flags'),
                   ULInt8('tow_flags'),
                   ULInt8('track_flags'),
                   ULInt8('nav_flags'),
                   ULInt8('pset_flags'),
                   ULInt8('misc_flags'),)
  __slots__ = [
               'recv_time',
               'tot',
               'P',
               'P_std',
               'L',
               'cn0',
               'lock',
               'sid',
               'doppler',
               'doppler_std',
               'uptime',
               'clock_offset',
               'clock_drift',
               'corr_spacing',
               'acceleration',
               'sync_flags',
               'tow_flags',
               'track_flags',
               'nav_flags',
               'pset_flags',
               'misc_flags',
              ]

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      super( MsgTrackingStateDetailed,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.from_binary(sbp.payload)
    else:
      super( MsgTrackingStateDetailed, self).__init__()
      self.msg_type = SBP_MSG_TRACKING_STATE_DETAILED
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.recv_time = kwargs.pop('recv_time')
      self.tot = kwargs.pop('tot')
      self.P = kwargs.pop('P')
      self.P_std = kwargs.pop('P_std')
      self.L = kwargs.pop('L')
      self.cn0 = kwargs.pop('cn0')
      self.lock = kwargs.pop('lock')
      self.sid = kwargs.pop('sid')
      self.doppler = kwargs.pop('doppler')
      self.doppler_std = kwargs.pop('doppler_std')
      self.uptime = kwargs.pop('uptime')
      self.clock_offset = kwargs.pop('clock_offset')
      self.clock_drift = kwargs.pop('clock_drift')
      self.corr_spacing = kwargs.pop('corr_spacing')
      self.acceleration = kwargs.pop('acceleration')
      self.sync_flags = kwargs.pop('sync_flags')
      self.tow_flags = kwargs.pop('tow_flags')
      self.track_flags = kwargs.pop('track_flags')
      self.nav_flags = kwargs.pop('nav_flags')
      self.pset_flags = kwargs.pop('pset_flags')
      self.misc_flags = kwargs.pop('misc_flags')

  def __repr__(self):
    return fmt_repr(self)

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    return MsgTrackingStateDetailed.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgTrackingStateDetailed(sbp, **d)

 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgTrackingStateDetailed._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgTrackingStateDetailed._parser.build(c)
    return self.pack()

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgTrackingStateDetailed, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    
SBP_MSG_TRACKING_STATE = 0x0041
class MsgTrackingState(SBP):
  """SBP class for message MSG_TRACKING_STATE (0x0041).

  You can have MSG_TRACKING_STATE inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  The tracking message returns a variable-length array of tracking
channel states. It reports status and carrier-to-noise density
measurements for all tracked satellites.


  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  states : array
    Signal tracking channel state
  sender : int
    Optional sender ID, defaults to SENDER_ID (see sbp/msg.py).

  """
  _parser = Struct("MsgTrackingState",
                   OptionalGreedyRange(Struct('states', TrackingChannelState._parser)),)
  __slots__ = [
               'states',
              ]

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      super( MsgTrackingState,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.from_binary(sbp.payload)
    else:
      super( MsgTrackingState, self).__init__()
      self.msg_type = SBP_MSG_TRACKING_STATE
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.states = kwargs.pop('states')

  def __repr__(self):
    return fmt_repr(self)

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    return MsgTrackingState.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgTrackingState(sbp, **d)

 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgTrackingState._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgTrackingState._parser.build(c)
    return self.pack()

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgTrackingState, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    
SBP_MSG_TRACKING_IQ = 0x001C
class MsgTrackingIq(SBP):
  """SBP class for message MSG_TRACKING_IQ (0x001C).

  You can have MSG_TRACKING_IQ inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  When enabled, a tracking channel can output the correlations at each
update interval.


  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  channel : int
    Tracking channel of origin
  sid : GnssSignal
    GNSS signal identifier
  corrs : array
    Early, Prompt and Late correlations
  sender : int
    Optional sender ID, defaults to SENDER_ID (see sbp/msg.py).

  """
  _parser = Struct("MsgTrackingIq",
                   ULInt8('channel'),
                   Struct('sid', GnssSignal._parser),
                   Struct('corrs', Array(3, Struct('corrs', TrackingChannelCorrelation._parser))),)
  __slots__ = [
               'channel',
               'sid',
               'corrs',
              ]

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      super( MsgTrackingIq,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.from_binary(sbp.payload)
    else:
      super( MsgTrackingIq, self).__init__()
      self.msg_type = SBP_MSG_TRACKING_IQ
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.channel = kwargs.pop('channel')
      self.sid = kwargs.pop('sid')
      self.corrs = kwargs.pop('corrs')

  def __repr__(self):
    return fmt_repr(self)

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    return MsgTrackingIq.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgTrackingIq(sbp, **d)

 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgTrackingIq._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgTrackingIq._parser.build(c)
    return self.pack()

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgTrackingIq, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    
SBP_MSG_TRACKING_STATE_DEP_A = 0x0016
class MsgTrackingStateDepA(SBP):
  """SBP class for message MSG_TRACKING_STATE_DEP_A (0x0016).

  You can have MSG_TRACKING_STATE_DEP_A inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  Deprecated.

  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  states : array
    Satellite tracking channel state
  sender : int
    Optional sender ID, defaults to SENDER_ID (see sbp/msg.py).

  """
  _parser = Struct("MsgTrackingStateDepA",
                   OptionalGreedyRange(Struct('states', TrackingChannelStateDepA._parser)),)
  __slots__ = [
               'states',
              ]

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      super( MsgTrackingStateDepA,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.from_binary(sbp.payload)
    else:
      super( MsgTrackingStateDepA, self).__init__()
      self.msg_type = SBP_MSG_TRACKING_STATE_DEP_A
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.states = kwargs.pop('states')

  def __repr__(self):
    return fmt_repr(self)

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    return MsgTrackingStateDepA.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgTrackingStateDepA(sbp, **d)

 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgTrackingStateDepA._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgTrackingStateDepA._parser.build(c)
    return self.pack()

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgTrackingStateDepA, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    
SBP_MSG_TRACKING_STATE_DEP_B = 0x0013
class MsgTrackingStateDepB(SBP):
  """SBP class for message MSG_TRACKING_STATE_DEP_B (0x0013).

  You can have MSG_TRACKING_STATE_DEP_B inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  Deprecated.

  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  states : array
    Signal tracking channel state
  sender : int
    Optional sender ID, defaults to SENDER_ID (see sbp/msg.py).

  """
  _parser = Struct("MsgTrackingStateDepB",
                   OptionalGreedyRange(Struct('states', TrackingChannelStateDepB._parser)),)
  __slots__ = [
               'states',
              ]

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      super( MsgTrackingStateDepB,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.from_binary(sbp.payload)
    else:
      super( MsgTrackingStateDepB, self).__init__()
      self.msg_type = SBP_MSG_TRACKING_STATE_DEP_B
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.states = kwargs.pop('states')

  def __repr__(self):
    return fmt_repr(self)

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    return MsgTrackingStateDepB.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgTrackingStateDepB(sbp, **d)

 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgTrackingStateDepB._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgTrackingStateDepB._parser.build(c)
    return self.pack()

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgTrackingStateDepB, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    

msg_classes = {
  0x0011: MsgTrackingStateDetailed,
  0x0041: MsgTrackingState,
  0x001C: MsgTrackingIq,
  0x0016: MsgTrackingStateDepA,
  0x0013: MsgTrackingStateDepB,
}