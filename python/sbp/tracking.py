#!/usr/bin/env python
# Copyright (C) 2015-2021 Swift Navigation Inc.
# Contact: https://support.swiftnav.com
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

import json

import construct

from sbp.msg import SBP, SENDER_ID
from sbp.utils import fmt_repr, exclude_fields, walk_json_dict, containerize
from sbp.gnss import CarrierPhase, GPSTime, GPSTimeDep, GnssSignal, GnssSignalDep

# Automatically generated from piksi/yaml/swiftnav/sbp/tracking.yaml with generate.py.
# Please do not hand edit!


class TrackingChannelState(object):
  """TrackingChannelState.
  
  Tracking channel state for a specific satellite signal and measured signal
  power.
  
  Parameters
  ----------
  sid : GnssSignal
    GNSS signal being tracked
  fcn : int
    Frequency channel number (GLONASS only)
  cn0 : int
    Carrier-to-Noise density.  Zero implies invalid cn0.

  """
  _parser = construct.Struct(
                     'sid' / GnssSignal._parser,
                     'fcn' / construct.Int8ul,
                     'cn0' / construct.Int8ul,)
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
    
class MeasurementState(object):
  """MeasurementState.
  
  Measurement Engine tracking channel state for a specific satellite signal
  and measured signal power. The mesid field for Glonass can either carry the
  FCN as 100 + FCN where FCN is in [-7, +6] or the Slot ID (from 1 to 28).
  
  Parameters
  ----------
  mesid : GnssSignal
    Measurement Engine GNSS signal being tracked (carries either Glonass FCN
    or SLOT)
  cn0 : int
    Carrier-to-Noise density.  Zero implies invalid cn0.

  """
  _parser = construct.Struct(
                     'mesid' / GnssSignal._parser,
                     'cn0' / construct.Int8ul,)
  __slots__ = [
               'mesid',
               'cn0',
              ]

  def __init__(self, payload=None, **kwargs):
    if payload:
      self.from_binary(payload)
    else:
      self.mesid = kwargs.pop('mesid')
      self.cn0 = kwargs.pop('cn0')

  def __repr__(self):
    return fmt_repr(self)
  
  def from_binary(self, d):
    p = MeasurementState._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))
    
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
  _parser = construct.Struct(
                     'I' / construct.Int16sl,
                     'Q' / construct.Int16sl,)
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
    
class TrackingChannelCorrelationDep(object):
  """TrackingChannelCorrelationDep.
  
  Structure containing in-phase and quadrature correlation components.
  
  Parameters
  ----------
  I : int
    In-phase correlation
  Q : int
    Quadrature correlation

  """
  _parser = construct.Struct(
                     'I' / construct.Int32sl,
                     'Q' / construct.Int32sl,)
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
    p = TrackingChannelCorrelationDep._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))
    
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
  _parser = construct.Struct(
                     'state' / construct.Int8ul,
                     'prn' / construct.Int8ul,
                     'cn0' / construct.Float32l,)
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
    
class TrackingChannelStateDepB(object):
  """TrackingChannelStateDepB.
  
  Deprecated.
  
  Parameters
  ----------
  state : int
    Status of tracking channel
  sid : GnssSignalDep
    GNSS signal being tracked
  cn0 : float
    Carrier-to-noise density

  """
  _parser = construct.Struct(
                     'state' / construct.Int8ul,
                     'sid' / GnssSignalDep._parser,
                     'cn0' / construct.Float32l,)
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
    
SBP_MSG_TRACKING_STATE_DETAILED_DEP_A = 0x0021
class MsgTrackingStateDetailedDepA(SBP):
  """SBP class for message MSG_TRACKING_STATE_DETAILED_DEP_A (0x0021).

  You can have MSG_TRACKING_STATE_DETAILED_DEP_A inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  The tracking message returns a set tracking channel parameters for a single
  tracking channel useful for debugging issues.

  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  recv_time : int
    Receiver clock time.
  tot : GPSTime
    Time of transmission of signal from satellite. TOW only valid when TOW
    status is decoded or propagated. WN only valid when week number valid flag
    is set.
  P : int
    Pseudorange observation. Valid only when pseudorange valid flag is set.
  P_std : int
    Pseudorange observation standard deviation. Valid only when pseudorange
    valid flag is set.
  L : CarrierPhase
    Carrier phase observation with typical sign convention. Valid only when
    PLL pessimistic lock is achieved.
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
    Number of seconds of continuous tracking. Specifies how much time signal
    is in continuous track.
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
  _parser = construct.Struct(
                   'recv_time' / construct.Int64ul,
                   'tot' / GPSTime._parser,
                   'P' / construct.Int32ul,
                   'P_std' / construct.Int16ul,
                   'L' / CarrierPhase._parser,
                   'cn0' / construct.Int8ul,
                   'lock' / construct.Int16ul,
                   'sid' / GnssSignal._parser,
                   'doppler' / construct.Int32sl,
                   'doppler_std' / construct.Int16ul,
                   'uptime' / construct.Int32ul,
                   'clock_offset' / construct.Int16sl,
                   'clock_drift' / construct.Int16sl,
                   'corr_spacing' / construct.Int16ul,
                   'acceleration' / construct.Int8sl,
                   'sync_flags' / construct.Int8ul,
                   'tow_flags' / construct.Int8ul,
                   'track_flags' / construct.Int8ul,
                   'nav_flags' / construct.Int8ul,
                   'pset_flags' / construct.Int8ul,
                   'misc_flags' / construct.Int8ul,)
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
      super( MsgTrackingStateDetailedDepA,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.from_binary(sbp.payload)
    else:
      super( MsgTrackingStateDetailedDepA, self).__init__()
      self.msg_type = SBP_MSG_TRACKING_STATE_DETAILED_DEP_A
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
    return MsgTrackingStateDetailedDepA.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgTrackingStateDetailedDepA(sbp, **d)

 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgTrackingStateDetailedDepA._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgTrackingStateDetailedDepA._parser.build(c)
    return self.pack()

  def into_buffer(self, buf, offset):
    """Produce a framed/packed SBP message into the provided buffer and offset.

    """
    self.payload = containerize(exclude_fields(self))
    self.parser = MsgTrackingStateDetailedDepA._parser
    self.stream_payload.reset(buf, offset)
    return self.pack_into(buf, offset, self._build_payload)

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgTrackingStateDetailedDepA, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    
SBP_MSG_TRACKING_STATE_DETAILED_DEP = 0x0011
class MsgTrackingStateDetailedDep(SBP):
  """SBP class for message MSG_TRACKING_STATE_DETAILED_DEP (0x0011).

  You can have MSG_TRACKING_STATE_DETAILED_DEP inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  Deprecated.

  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  recv_time : int
    Receiver clock time.
  tot : GPSTimeDep
    Time of transmission of signal from satellite. TOW only valid when TOW
    status is decoded or propagated. WN only valid when week number valid flag
    is set.
  P : int
    Pseudorange observation. Valid only when pseudorange valid flag is set.
  P_std : int
    Pseudorange observation standard deviation. Valid only when pseudorange
    valid flag is set.
  L : CarrierPhase
    Carrier phase observation with typical sign convention. Valid only when
    PLL pessimistic lock is achieved.
  cn0 : int
    Carrier-to-Noise density
  lock : int
    Lock time. It is encoded according to DF402 from the RTCM 10403.2
    Amendment 2 specification. Valid values range from 0 to 15.
  sid : GnssSignalDep
    GNSS signal identifier.
  doppler : int
    Carrier Doppler frequency.
  doppler_std : int
    Carrier Doppler frequency standard deviation.
  uptime : int
    Number of seconds of continuous tracking. Specifies how much time signal
    is in continuous track.
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
  _parser = construct.Struct(
                   'recv_time' / construct.Int64ul,
                   'tot' / GPSTimeDep._parser,
                   'P' / construct.Int32ul,
                   'P_std' / construct.Int16ul,
                   'L' / CarrierPhase._parser,
                   'cn0' / construct.Int8ul,
                   'lock' / construct.Int16ul,
                   'sid' / GnssSignalDep._parser,
                   'doppler' / construct.Int32sl,
                   'doppler_std' / construct.Int16ul,
                   'uptime' / construct.Int32ul,
                   'clock_offset' / construct.Int16sl,
                   'clock_drift' / construct.Int16sl,
                   'corr_spacing' / construct.Int16ul,
                   'acceleration' / construct.Int8sl,
                   'sync_flags' / construct.Int8ul,
                   'tow_flags' / construct.Int8ul,
                   'track_flags' / construct.Int8ul,
                   'nav_flags' / construct.Int8ul,
                   'pset_flags' / construct.Int8ul,
                   'misc_flags' / construct.Int8ul,)
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
      super( MsgTrackingStateDetailedDep,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.from_binary(sbp.payload)
    else:
      super( MsgTrackingStateDetailedDep, self).__init__()
      self.msg_type = SBP_MSG_TRACKING_STATE_DETAILED_DEP
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
    return MsgTrackingStateDetailedDep.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgTrackingStateDetailedDep(sbp, **d)

 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgTrackingStateDetailedDep._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgTrackingStateDetailedDep._parser.build(c)
    return self.pack()

  def into_buffer(self, buf, offset):
    """Produce a framed/packed SBP message into the provided buffer and offset.

    """
    self.payload = containerize(exclude_fields(self))
    self.parser = MsgTrackingStateDetailedDep._parser
    self.stream_payload.reset(buf, offset)
    return self.pack_into(buf, offset, self._build_payload)

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgTrackingStateDetailedDep, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    
SBP_MSG_TRACKING_STATE = 0x0041
class MsgTrackingState(SBP):
  """SBP class for message MSG_TRACKING_STATE (0x0041).

  You can have MSG_TRACKING_STATE inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  The tracking message returns a variable-length array of tracking channel
  states. It reports status and carrier-to-noise density measurements for all
  tracked satellites.

  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  states : array
    Signal tracking channel state
  sender : int
    Optional sender ID, defaults to SENDER_ID (see sbp/msg.py).

  """
  _parser = construct.Struct(
                   'states' / construct.GreedyRange(TrackingChannelState._parser),)
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

  def into_buffer(self, buf, offset):
    """Produce a framed/packed SBP message into the provided buffer and offset.

    """
    self.payload = containerize(exclude_fields(self))
    self.parser = MsgTrackingState._parser
    self.stream_payload.reset(buf, offset)
    return self.pack_into(buf, offset, self._build_payload)

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgTrackingState, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    
SBP_MSG_MEASUREMENT_STATE = 0x0061
class MsgMeasurementState(SBP):
  """SBP class for message MSG_MEASUREMENT_STATE (0x0061).

  You can have MSG_MEASUREMENT_STATE inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  The tracking message returns a variable-length array of tracking channel
  states. It reports status and carrier-to-noise density measurements for all
  tracked satellites.

  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  states : array
    ME signal tracking channel state
  sender : int
    Optional sender ID, defaults to SENDER_ID (see sbp/msg.py).

  """
  _parser = construct.Struct(
                   'states' / construct.GreedyRange(MeasurementState._parser),)
  __slots__ = [
               'states',
              ]

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      super( MsgMeasurementState,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.from_binary(sbp.payload)
    else:
      super( MsgMeasurementState, self).__init__()
      self.msg_type = SBP_MSG_MEASUREMENT_STATE
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.states = kwargs.pop('states')

  def __repr__(self):
    return fmt_repr(self)

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    return MsgMeasurementState.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgMeasurementState(sbp, **d)

 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgMeasurementState._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgMeasurementState._parser.build(c)
    return self.pack()

  def into_buffer(self, buf, offset):
    """Produce a framed/packed SBP message into the provided buffer and offset.

    """
    self.payload = containerize(exclude_fields(self))
    self.parser = MsgMeasurementState._parser
    self.stream_payload.reset(buf, offset)
    return self.pack_into(buf, offset, self._build_payload)

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgMeasurementState, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    
SBP_MSG_TRACKING_IQ = 0x002D
class MsgTrackingIq(SBP):
  """SBP class for message MSG_TRACKING_IQ (0x002D).

  You can have MSG_TRACKING_IQ inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  When enabled, a tracking channel can output the correlations at each update
  interval.

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
  _parser = construct.Struct(
                   'channel' / construct.Int8ul,
                   'sid' / GnssSignal._parser,
                   'corrs' / construct.Array(3, construct.Byte),)
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

  def into_buffer(self, buf, offset):
    """Produce a framed/packed SBP message into the provided buffer and offset.

    """
    self.payload = containerize(exclude_fields(self))
    self.parser = MsgTrackingIq._parser
    self.stream_payload.reset(buf, offset)
    return self.pack_into(buf, offset, self._build_payload)

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgTrackingIq, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    
SBP_MSG_TRACKING_IQ_DEP_B = 0x002C
class MsgTrackingIqDepB(SBP):
  """SBP class for message MSG_TRACKING_IQ_DEP_B (0x002C).

  You can have MSG_TRACKING_IQ_DEP_B inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  When enabled, a tracking channel can output the correlations at each update
  interval.

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
  _parser = construct.Struct(
                   'channel' / construct.Int8ul,
                   'sid' / GnssSignal._parser,
                   'corrs' / construct.Array(3, construct.Byte),)
  __slots__ = [
               'channel',
               'sid',
               'corrs',
              ]

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      super( MsgTrackingIqDepB,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.from_binary(sbp.payload)
    else:
      super( MsgTrackingIqDepB, self).__init__()
      self.msg_type = SBP_MSG_TRACKING_IQ_DEP_B
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
    return MsgTrackingIqDepB.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgTrackingIqDepB(sbp, **d)

 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgTrackingIqDepB._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgTrackingIqDepB._parser.build(c)
    return self.pack()

  def into_buffer(self, buf, offset):
    """Produce a framed/packed SBP message into the provided buffer and offset.

    """
    self.payload = containerize(exclude_fields(self))
    self.parser = MsgTrackingIqDepB._parser
    self.stream_payload.reset(buf, offset)
    return self.pack_into(buf, offset, self._build_payload)

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgTrackingIqDepB, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    
SBP_MSG_TRACKING_IQ_DEP_A = 0x001C
class MsgTrackingIqDepA(SBP):
  """SBP class for message MSG_TRACKING_IQ_DEP_A (0x001C).

  You can have MSG_TRACKING_IQ_DEP_A inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  Deprecated.

  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  channel : int
    Tracking channel of origin
  sid : GnssSignalDep
    GNSS signal identifier
  corrs : array
    Early, Prompt and Late correlations
  sender : int
    Optional sender ID, defaults to SENDER_ID (see sbp/msg.py).

  """
  _parser = construct.Struct(
                   'channel' / construct.Int8ul,
                   'sid' / GnssSignalDep._parser,
                   'corrs' / construct.Array(3, construct.Byte),)
  __slots__ = [
               'channel',
               'sid',
               'corrs',
              ]

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      super( MsgTrackingIqDepA,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.from_binary(sbp.payload)
    else:
      super( MsgTrackingIqDepA, self).__init__()
      self.msg_type = SBP_MSG_TRACKING_IQ_DEP_A
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
    return MsgTrackingIqDepA.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgTrackingIqDepA(sbp, **d)

 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgTrackingIqDepA._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgTrackingIqDepA._parser.build(c)
    return self.pack()

  def into_buffer(self, buf, offset):
    """Produce a framed/packed SBP message into the provided buffer and offset.

    """
    self.payload = containerize(exclude_fields(self))
    self.parser = MsgTrackingIqDepA._parser
    self.stream_payload.reset(buf, offset)
    return self.pack_into(buf, offset, self._build_payload)

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgTrackingIqDepA, self).to_json_dict()
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
  _parser = construct.Struct(
                   'states' / construct.GreedyRange(TrackingChannelStateDepA._parser),)
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

  def into_buffer(self, buf, offset):
    """Produce a framed/packed SBP message into the provided buffer and offset.

    """
    self.payload = containerize(exclude_fields(self))
    self.parser = MsgTrackingStateDepA._parser
    self.stream_payload.reset(buf, offset)
    return self.pack_into(buf, offset, self._build_payload)

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
  _parser = construct.Struct(
                   'states' / construct.GreedyRange(TrackingChannelStateDepB._parser),)
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

  def into_buffer(self, buf, offset):
    """Produce a framed/packed SBP message into the provided buffer and offset.

    """
    self.payload = containerize(exclude_fields(self))
    self.parser = MsgTrackingStateDepB._parser
    self.stream_payload.reset(buf, offset)
    return self.pack_into(buf, offset, self._build_payload)

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgTrackingStateDepB, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    

msg_classes = {
  0x0021: MsgTrackingStateDetailedDepA,
  0x0011: MsgTrackingStateDetailedDep,
  0x0041: MsgTrackingState,
  0x0061: MsgMeasurementState,
  0x002D: MsgTrackingIq,
  0x002C: MsgTrackingIqDepB,
  0x001C: MsgTrackingIqDepA,
  0x0016: MsgTrackingStateDepA,
  0x0013: MsgTrackingStateDepB,
}