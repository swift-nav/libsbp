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
  sid : int
    Signal identifier being tracked - values 0x00 through 0x1F
represent GPS PRNs 1 through 32 respectively (PRN-1 notation);
other values reserved for future use

  cn0 : float
    Carrier-to-noise density

  """
  _parser = Embedded(Struct("TrackingChannelState",
                     ULInt8('state'),
                     ULInt32('sid'),
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
    
SBP_MSG_TRACKING_STATE = 0x0013
class MsgTrackingState(SBP):
  """SBP class for message MSG_TRACKING_STATE (0x0013).

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
    
SBP_MSG_TRACKING_IQ = 0x001C
class MsgTrackingIq(SBP):
  """SBP class for message MSG_TRACKING_IQ (0x001C).

  You can have MSG_TRACKING_IQ inherent its fields directly
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
  sid : int
    Signal identifier being tracked - values 0x00 through 0x1F
represent GPS PRNs 1 through 32 respectively (PRN-1 notation);
other values reserved for future use

  corrs : array
    Early, Prompt and Late correlations
  sender : int
    Optional sender ID, defaults to SENDER_ID (see sbp/msg.py).

  """
  _parser = Struct("MsgTrackingIq",
                   ULInt8('channel'),
                   ULInt32('sid'),
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

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    sbp = SBP.from_json_dict(d)
    return MsgTrackingIq(sbp)

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgTrackingIq, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    
SBP_MSG_TRACKING_STATE_DEP_A = 0x0016
class MsgTrackingStateDepA(SBP):
  """SBP class for message MSG_TRACKING_STATE_DEP_A (0x0016).

  You can have MSG_TRACKING_STATE_DEP_A inherent its fields directly
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

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    sbp = SBP.from_json_dict(d)
    return MsgTrackingStateDepA(sbp)

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgTrackingStateDepA, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    

msg_classes = {
  0x0013: MsgTrackingState,
  0x001C: MsgTrackingIq,
  0x0016: MsgTrackingStateDepA,
}