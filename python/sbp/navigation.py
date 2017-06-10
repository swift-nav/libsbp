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
Geodetic navigation messages reporting GPS time, position, velocity,
and baseline position solutions. For position solutions, these
messages define several different position solutions: single-point
(SPP), RTK, and pseudo-absolute position solutions.

The SPP is the standalone, absolute GPS position solution using only
a single receiver. The RTK solution is the differential GPS
solution, which can use either a fixed/integer or floating carrier
phase ambiguity. The pseudo-absolute position solution uses a
user-provided, well-surveyed base station position (if available)
and the RTK solution in tandem.

"""

from construct import *
import json
from sbp.msg import SBP, SENDER_ID
from sbp.utils import fmt_repr, exclude_fields, walk_json_dict, containerize, greedy_string

# Automatically generated from piksi/yaml/swiftnav/sbp/navigation.yaml with generate.py.
# Please do not hand edit!


SBP_MSG_GPS_TIME = 0x0102
class MsgGPSTime(SBP):
  """SBP class for message MSG_GPS_TIME (0x0102).

  You can have MSG_GPS_TIME inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  This message reports the GPS time, representing the time since
the GPS epoch began on midnight January 6, 1980 UTC. GPS time
counts the weeks and seconds of the week. The weeks begin at the
Saturday/Sunday transition. GPS week 0 began at the beginning of
the GPS time scale.

Within each week number, the GPS time of the week is between
between 0 and 604800 seconds (=60*60*24*7). Note that GPS time
does not accumulate leap seconds, and as of now, has a small
offset from UTC. In a message stream, this message precedes a
set of other navigation messages referenced to the same time
(but lacking the ns field) and indicates a more precise time of
these messages.


  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  wn : int
    GPS week number
  tow : int
    GPS time of week rounded to the nearest millisecond
  ns_residual : int
    Nanosecond residual of millisecond-rounded TOW (ranges
from -500000 to 500000)

  flags : int
    Status flags (reserved)
  sender : int
    Optional sender ID, defaults to SENDER_ID (see sbp/msg.py).

  """
  _parser = Struct("MsgGPSTime",
                   ULInt16('wn'),
                   ULInt32('tow'),
                   SLInt32('ns_residual'),
                   ULInt8('flags'),)
  __slots__ = [
               'wn',
               'tow',
               'ns_residual',
               'flags',
              ]

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      super( MsgGPSTime,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.from_binary(sbp.payload)
    else:
      super( MsgGPSTime, self).__init__()
      self.msg_type = SBP_MSG_GPS_TIME
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.wn = kwargs.pop('wn')
      self.tow = kwargs.pop('tow')
      self.ns_residual = kwargs.pop('ns_residual')
      self.flags = kwargs.pop('flags')

  def __repr__(self):
    return fmt_repr(self)

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    return MsgGPSTime.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgGPSTime(sbp, **d)

 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgGPSTime._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgGPSTime._parser.build(c)
    return self.pack()

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgGPSTime, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    
SBP_MSG_UTC_TIME = 0x0103
class MsgUtcTime(SBP):
  """SBP class for message MSG_UTC_TIME (0x0103).

  You can have MSG_UTC_TIME inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  This message reports the Universal Coordinated Time (UTC).  Note the flags
which indicate the source of the UTC offset value and source of the time fix.


  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  flags : int
    Indicates source and time validity
  tow : int
    GPS time of week rounded to the nearest millisecond
  year : int
    Year
  month : int
    Month (range 1 .. 12)
  day : int
    days in the month (range 1-31)
  hours : int
    hours of day (range 0-23)
  minutes : int
    minutes of hour (range 0-59)
  seconds : int
    seconds of minute (range 0-60) rounded down
  ns : int
    nanoseconds of second (range 0-999999999)
  sender : int
    Optional sender ID, defaults to SENDER_ID (see sbp/msg.py).

  """
  _parser = Struct("MsgUtcTime",
                   ULInt8('flags'),
                   ULInt32('tow'),
                   ULInt16('year'),
                   ULInt8('month'),
                   ULInt8('day'),
                   ULInt8('hours'),
                   ULInt8('minutes'),
                   ULInt8('seconds'),
                   ULInt32('ns'),)
  __slots__ = [
               'flags',
               'tow',
               'year',
               'month',
               'day',
               'hours',
               'minutes',
               'seconds',
               'ns',
              ]

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      super( MsgUtcTime,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.from_binary(sbp.payload)
    else:
      super( MsgUtcTime, self).__init__()
      self.msg_type = SBP_MSG_UTC_TIME
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.flags = kwargs.pop('flags')
      self.tow = kwargs.pop('tow')
      self.year = kwargs.pop('year')
      self.month = kwargs.pop('month')
      self.day = kwargs.pop('day')
      self.hours = kwargs.pop('hours')
      self.minutes = kwargs.pop('minutes')
      self.seconds = kwargs.pop('seconds')
      self.ns = kwargs.pop('ns')

  def __repr__(self):
    return fmt_repr(self)

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    return MsgUtcTime.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgUtcTime(sbp, **d)

 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgUtcTime._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgUtcTime._parser.build(c)
    return self.pack()

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgUtcTime, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    
SBP_MSG_DOPS = 0x0208
class MsgDops(SBP):
  """SBP class for message MSG_DOPS (0x0208).

  You can have MSG_DOPS inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  This dilution of precision (DOP) message describes the effect of
navigation satellite geometry on positional measurement
precision.  The flags field indicated whether the DOP reported
corresponds to differential or SPP solution.


  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  tow : int
    GPS Time of Week
  gdop : int
    Geometric Dilution of Precision
  pdop : int
    Position Dilution of Precision
  tdop : int
    Time Dilution of Precision
  hdop : int
    Horizontal Dilution of Precision
  vdop : int
    Vertical Dilution of Precision
  flags : int
    Indicates the position solution with which the DOPS message corresponds
  sender : int
    Optional sender ID, defaults to SENDER_ID (see sbp/msg.py).

  """
  _parser = Struct("MsgDops",
                   ULInt32('tow'),
                   ULInt16('gdop'),
                   ULInt16('pdop'),
                   ULInt16('tdop'),
                   ULInt16('hdop'),
                   ULInt16('vdop'),
                   ULInt8('flags'),)
  __slots__ = [
               'tow',
               'gdop',
               'pdop',
               'tdop',
               'hdop',
               'vdop',
               'flags',
              ]

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      super( MsgDops,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.from_binary(sbp.payload)
    else:
      super( MsgDops, self).__init__()
      self.msg_type = SBP_MSG_DOPS
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.tow = kwargs.pop('tow')
      self.gdop = kwargs.pop('gdop')
      self.pdop = kwargs.pop('pdop')
      self.tdop = kwargs.pop('tdop')
      self.hdop = kwargs.pop('hdop')
      self.vdop = kwargs.pop('vdop')
      self.flags = kwargs.pop('flags')

  def __repr__(self):
    return fmt_repr(self)

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    return MsgDops.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgDops(sbp, **d)

 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgDops._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgDops._parser.build(c)
    return self.pack()

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgDops, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    
SBP_MSG_POS_ECEF = 0x0209
class MsgPosECEF(SBP):
  """SBP class for message MSG_POS_ECEF (0x0209).

  You can have MSG_POS_ECEF inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  The position solution message reports absolute Earth Centered
Earth Fixed (ECEF) coordinates and the status (single point vs
pseudo-absolute RTK) of the position solution. If the rover
receiver knows the surveyed position of the base station and has
an RTK solution, this reports a pseudo-absolute position
solution using the base station position and the rover's RTK
baseline vector. The full GPS time is given by the preceding
MSG_GPS_TIME with the matching time-of-week (tow).


  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  tow : int
    GPS Time of Week
  x : double
    ECEF X coordinate
  y : double
    ECEF Y coordinate
  z : double
    ECEF Z coordinate
  accuracy : int
    Position accuracy estimate.
  n_sats : int
    Number of satellites used in solution
  flags : int
    Status flags
  sender : int
    Optional sender ID, defaults to SENDER_ID (see sbp/msg.py).

  """
  _parser = Struct("MsgPosECEF",
                   ULInt32('tow'),
                   LFloat64('x'),
                   LFloat64('y'),
                   LFloat64('z'),
                   ULInt16('accuracy'),
                   ULInt8('n_sats'),
                   ULInt8('flags'),)
  __slots__ = [
               'tow',
               'x',
               'y',
               'z',
               'accuracy',
               'n_sats',
               'flags',
              ]

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      super( MsgPosECEF,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.from_binary(sbp.payload)
    else:
      super( MsgPosECEF, self).__init__()
      self.msg_type = SBP_MSG_POS_ECEF
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.tow = kwargs.pop('tow')
      self.x = kwargs.pop('x')
      self.y = kwargs.pop('y')
      self.z = kwargs.pop('z')
      self.accuracy = kwargs.pop('accuracy')
      self.n_sats = kwargs.pop('n_sats')
      self.flags = kwargs.pop('flags')

  def __repr__(self):
    return fmt_repr(self)

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    return MsgPosECEF.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgPosECEF(sbp, **d)

 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgPosECEF._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgPosECEF._parser.build(c)
    return self.pack()

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgPosECEF, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    
SBP_MSG_POS_LLH = 0x020A
class MsgPosLLH(SBP):
  """SBP class for message MSG_POS_LLH (0x020A).

  You can have MSG_POS_LLH inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  This position solution message reports the absolute geodetic
coordinates and the status (single point vs pseudo-absolute RTK)
of the position solution. If the rover receiver knows the
surveyed position of the base station and has an RTK solution,
this reports a pseudo-absolute position solution using the base
station position and the rover's RTK baseline vector. The full
GPS time is given by the preceding MSG_GPS_TIME with the
matching time-of-week (tow).


  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  tow : int
    GPS Time of Week
  lat : double
    Latitude
  lon : double
    Longitude
  height : double
    Height above WGS84 ellipsoid
  h_accuracy : int
    Horizontal position accuracy estimate.
  v_accuracy : int
    Vertical position accuracy estimate.
  n_sats : int
    Number of satellites used in solution.
  flags : int
    Status flags
  sender : int
    Optional sender ID, defaults to SENDER_ID (see sbp/msg.py).

  """
  _parser = Struct("MsgPosLLH",
                   ULInt32('tow'),
                   LFloat64('lat'),
                   LFloat64('lon'),
                   LFloat64('height'),
                   ULInt16('h_accuracy'),
                   ULInt16('v_accuracy'),
                   ULInt8('n_sats'),
                   ULInt8('flags'),)
  __slots__ = [
               'tow',
               'lat',
               'lon',
               'height',
               'h_accuracy',
               'v_accuracy',
               'n_sats',
               'flags',
              ]

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      super( MsgPosLLH,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.from_binary(sbp.payload)
    else:
      super( MsgPosLLH, self).__init__()
      self.msg_type = SBP_MSG_POS_LLH
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.tow = kwargs.pop('tow')
      self.lat = kwargs.pop('lat')
      self.lon = kwargs.pop('lon')
      self.height = kwargs.pop('height')
      self.h_accuracy = kwargs.pop('h_accuracy')
      self.v_accuracy = kwargs.pop('v_accuracy')
      self.n_sats = kwargs.pop('n_sats')
      self.flags = kwargs.pop('flags')

  def __repr__(self):
    return fmt_repr(self)

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    return MsgPosLLH.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgPosLLH(sbp, **d)

 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgPosLLH._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgPosLLH._parser.build(c)
    return self.pack()

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgPosLLH, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    
SBP_MSG_BASELINE_ECEF = 0x020B
class MsgBaselineECEF(SBP):
  """SBP class for message MSG_BASELINE_ECEF (0x020B).

  You can have MSG_BASELINE_ECEF inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  This message reports the baseline solution in Earth Centered
Earth Fixed (ECEF) coordinates. This baseline is the relative
vector distance from the base station to the rover receiver. The
full GPS time is given by the preceding MSG_GPS_TIME with the
matching time-of-week (tow).


  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  tow : int
    GPS Time of Week
  x : int
    Baseline ECEF X coordinate
  y : int
    Baseline ECEF Y coordinate
  z : int
    Baseline ECEF Z coordinate
  accuracy : int
    Position accuracy estimate
  n_sats : int
    Number of satellites used in solution
  flags : int
    Status flags
  sender : int
    Optional sender ID, defaults to SENDER_ID (see sbp/msg.py).

  """
  _parser = Struct("MsgBaselineECEF",
                   ULInt32('tow'),
                   SLInt32('x'),
                   SLInt32('y'),
                   SLInt32('z'),
                   ULInt16('accuracy'),
                   ULInt8('n_sats'),
                   ULInt8('flags'),)
  __slots__ = [
               'tow',
               'x',
               'y',
               'z',
               'accuracy',
               'n_sats',
               'flags',
              ]

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      super( MsgBaselineECEF,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.from_binary(sbp.payload)
    else:
      super( MsgBaselineECEF, self).__init__()
      self.msg_type = SBP_MSG_BASELINE_ECEF
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.tow = kwargs.pop('tow')
      self.x = kwargs.pop('x')
      self.y = kwargs.pop('y')
      self.z = kwargs.pop('z')
      self.accuracy = kwargs.pop('accuracy')
      self.n_sats = kwargs.pop('n_sats')
      self.flags = kwargs.pop('flags')

  def __repr__(self):
    return fmt_repr(self)

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    return MsgBaselineECEF.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgBaselineECEF(sbp, **d)

 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgBaselineECEF._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgBaselineECEF._parser.build(c)
    return self.pack()

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgBaselineECEF, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    
SBP_MSG_BASELINE_NED = 0x020C
class MsgBaselineNED(SBP):
  """SBP class for message MSG_BASELINE_NED (0x020C).

  You can have MSG_BASELINE_NED inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  This message reports the baseline solution in North East Down
(NED) coordinates. This baseline is the relative vector distance
from the base station to the rover receiver, and NED coordinate
system is defined at the local WGS84 tangent plane centered at the
base station position.  The full GPS time is given by the
preceding MSG_GPS_TIME with the matching time-of-week (tow).


  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  tow : int
    GPS Time of Week
  n : int
    Baseline North coordinate
  e : int
    Baseline East coordinate
  d : int
    Baseline Down coordinate
  h_accuracy : int
    Horizontal position accuracy estimate
  v_accuracy : int
    Vertical position accuracy estimate
  n_sats : int
    Number of satellites used in solution
  flags : int
    Status flags
  sender : int
    Optional sender ID, defaults to SENDER_ID (see sbp/msg.py).

  """
  _parser = Struct("MsgBaselineNED",
                   ULInt32('tow'),
                   SLInt32('n'),
                   SLInt32('e'),
                   SLInt32('d'),
                   ULInt16('h_accuracy'),
                   ULInt16('v_accuracy'),
                   ULInt8('n_sats'),
                   ULInt8('flags'),)
  __slots__ = [
               'tow',
               'n',
               'e',
               'd',
               'h_accuracy',
               'v_accuracy',
               'n_sats',
               'flags',
              ]

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      super( MsgBaselineNED,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.from_binary(sbp.payload)
    else:
      super( MsgBaselineNED, self).__init__()
      self.msg_type = SBP_MSG_BASELINE_NED
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.tow = kwargs.pop('tow')
      self.n = kwargs.pop('n')
      self.e = kwargs.pop('e')
      self.d = kwargs.pop('d')
      self.h_accuracy = kwargs.pop('h_accuracy')
      self.v_accuracy = kwargs.pop('v_accuracy')
      self.n_sats = kwargs.pop('n_sats')
      self.flags = kwargs.pop('flags')

  def __repr__(self):
    return fmt_repr(self)

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    return MsgBaselineNED.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgBaselineNED(sbp, **d)

 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgBaselineNED._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgBaselineNED._parser.build(c)
    return self.pack()

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgBaselineNED, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    
SBP_MSG_VEL_ECEF = 0x020D
class MsgVelECEF(SBP):
  """SBP class for message MSG_VEL_ECEF (0x020D).

  You can have MSG_VEL_ECEF inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  This message reports the velocity in Earth Centered Earth Fixed
(ECEF) coordinates. The full GPS time is given by the preceding
MSG_GPS_TIME with the matching time-of-week (tow).


  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  tow : int
    GPS Time of Week
  x : int
    Velocity ECEF X coordinate
  y : int
    Velocity ECEF Y coordinate
  z : int
    Velocity ECEF Z coordinate
  accuracy : int
    Velocity accuracy estimate

  n_sats : int
    Number of satellites used in solution
  flags : int
    Status flags
  sender : int
    Optional sender ID, defaults to SENDER_ID (see sbp/msg.py).

  """
  _parser = Struct("MsgVelECEF",
                   ULInt32('tow'),
                   SLInt32('x'),
                   SLInt32('y'),
                   SLInt32('z'),
                   ULInt16('accuracy'),
                   ULInt8('n_sats'),
                   ULInt8('flags'),)
  __slots__ = [
               'tow',
               'x',
               'y',
               'z',
               'accuracy',
               'n_sats',
               'flags',
              ]

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      super( MsgVelECEF,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.from_binary(sbp.payload)
    else:
      super( MsgVelECEF, self).__init__()
      self.msg_type = SBP_MSG_VEL_ECEF
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.tow = kwargs.pop('tow')
      self.x = kwargs.pop('x')
      self.y = kwargs.pop('y')
      self.z = kwargs.pop('z')
      self.accuracy = kwargs.pop('accuracy')
      self.n_sats = kwargs.pop('n_sats')
      self.flags = kwargs.pop('flags')

  def __repr__(self):
    return fmt_repr(self)

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    return MsgVelECEF.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgVelECEF(sbp, **d)

 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgVelECEF._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgVelECEF._parser.build(c)
    return self.pack()

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgVelECEF, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    
SBP_MSG_VEL_NED = 0x020E
class MsgVelNED(SBP):
  """SBP class for message MSG_VEL_NED (0x020E).

  You can have MSG_VEL_NED inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  This message reports the velocity in local North East Down (NED)
coordinates. The NED coordinate system is defined as the local WGS84
tangent plane centered at the current position. The full GPS time is
given by the preceding MSG_GPS_TIME with the matching time-of-week (tow).


  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  tow : int
    GPS Time of Week
  n : int
    Velocity North coordinate
  e : int
    Velocity East coordinate
  d : int
    Velocity Down coordinate
  h_accuracy : int
    Horizontal velocity accuracy estimate

  v_accuracy : int
    Vertical velocity accuracy estimate

  n_sats : int
    Number of satellites used in solution
  flags : int
    Status flags
  sender : int
    Optional sender ID, defaults to SENDER_ID (see sbp/msg.py).

  """
  _parser = Struct("MsgVelNED",
                   ULInt32('tow'),
                   SLInt32('n'),
                   SLInt32('e'),
                   SLInt32('d'),
                   ULInt16('h_accuracy'),
                   ULInt16('v_accuracy'),
                   ULInt8('n_sats'),
                   ULInt8('flags'),)
  __slots__ = [
               'tow',
               'n',
               'e',
               'd',
               'h_accuracy',
               'v_accuracy',
               'n_sats',
               'flags',
              ]

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      super( MsgVelNED,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.from_binary(sbp.payload)
    else:
      super( MsgVelNED, self).__init__()
      self.msg_type = SBP_MSG_VEL_NED
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.tow = kwargs.pop('tow')
      self.n = kwargs.pop('n')
      self.e = kwargs.pop('e')
      self.d = kwargs.pop('d')
      self.h_accuracy = kwargs.pop('h_accuracy')
      self.v_accuracy = kwargs.pop('v_accuracy')
      self.n_sats = kwargs.pop('n_sats')
      self.flags = kwargs.pop('flags')

  def __repr__(self):
    return fmt_repr(self)

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    return MsgVelNED.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgVelNED(sbp, **d)

 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgVelNED._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgVelNED._parser.build(c)
    return self.pack()

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgVelNED, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    
SBP_MSG_BASELINE_HEADING = 0x020F
class MsgBaselineHeading(SBP):
  """SBP class for message MSG_BASELINE_HEADING (0x020F).

  You can have MSG_BASELINE_HEADING inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  This message reports the baseline heading pointing from the base station
to the rover relative to True North. The full GPS time is given by the
preceding MSG_GPS_TIME with the matching time-of-week (tow). It is intended
that time-matched RTK mode is used when the base station is moving.


  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  tow : int
    GPS Time of Week
  heading : int
    Heading
  n_sats : int
    Number of satellites used in solution
  flags : int
    Status flags
  sender : int
    Optional sender ID, defaults to SENDER_ID (see sbp/msg.py).

  """
  _parser = Struct("MsgBaselineHeading",
                   ULInt32('tow'),
                   ULInt32('heading'),
                   ULInt8('n_sats'),
                   ULInt8('flags'),)
  __slots__ = [
               'tow',
               'heading',
               'n_sats',
               'flags',
              ]

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      super( MsgBaselineHeading,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.from_binary(sbp.payload)
    else:
      super( MsgBaselineHeading, self).__init__()
      self.msg_type = SBP_MSG_BASELINE_HEADING
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.tow = kwargs.pop('tow')
      self.heading = kwargs.pop('heading')
      self.n_sats = kwargs.pop('n_sats')
      self.flags = kwargs.pop('flags')

  def __repr__(self):
    return fmt_repr(self)

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    return MsgBaselineHeading.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgBaselineHeading(sbp, **d)

 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgBaselineHeading._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgBaselineHeading._parser.build(c)
    return self.pack()

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgBaselineHeading, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    
SBP_MSG_AGE_CORRECTIONS = 0x0210
class MsgAgeCorrections(SBP):
  """SBP class for message MSG_AGE_CORRECTIONS (0x0210).

  You can have MSG_AGE_CORRECTIONS inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  This message reports the Age of the corrections used for the current
Differential solution


  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  tow : int
    GPS Time of Week
  age : int
    Age of the corrections (0xFFFF indicates invalid)
  sender : int
    Optional sender ID, defaults to SENDER_ID (see sbp/msg.py).

  """
  _parser = Struct("MsgAgeCorrections",
                   ULInt32('tow'),
                   ULInt16('age'),)
  __slots__ = [
               'tow',
               'age',
              ]

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      super( MsgAgeCorrections,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.from_binary(sbp.payload)
    else:
      super( MsgAgeCorrections, self).__init__()
      self.msg_type = SBP_MSG_AGE_CORRECTIONS
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.tow = kwargs.pop('tow')
      self.age = kwargs.pop('age')

  def __repr__(self):
    return fmt_repr(self)

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    return MsgAgeCorrections.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgAgeCorrections(sbp, **d)

 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgAgeCorrections._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgAgeCorrections._parser.build(c)
    return self.pack()

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgAgeCorrections, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    
SBP_MSG_GPS_TIME_DEP_A = 0x0100
class MsgGPSTimeDepA(SBP):
  """SBP class for message MSG_GPS_TIME_DEP_A (0x0100).

  You can have MSG_GPS_TIME_DEP_A inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  This message reports the GPS time, representing the time since
the GPS epoch began on midnight January 6, 1980 UTC. GPS time
counts the weeks and seconds of the week. The weeks begin at the
Saturday/Sunday transition. GPS week 0 began at the beginning of
the GPS time scale.

Within each week number, the GPS time of the week is between
between 0 and 604800 seconds (=60*60*24*7). Note that GPS time
does not accumulate leap seconds, and as of now, has a small
offset from UTC. In a message stream, this message precedes a
set of other navigation messages referenced to the same time
(but lacking the ns field) and indicates a more precise time of
these messages.


  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  wn : int
    GPS week number
  tow : int
    GPS time of week rounded to the nearest millisecond
  ns_residual : int
    Nanosecond residual of millisecond-rounded TOW (ranges
from -500000 to 500000)

  flags : int
    Status flags (reserved)
  sender : int
    Optional sender ID, defaults to SENDER_ID (see sbp/msg.py).

  """
  _parser = Struct("MsgGPSTimeDepA",
                   ULInt16('wn'),
                   ULInt32('tow'),
                   SLInt32('ns_residual'),
                   ULInt8('flags'),)
  __slots__ = [
               'wn',
               'tow',
               'ns_residual',
               'flags',
              ]

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      super( MsgGPSTimeDepA,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.from_binary(sbp.payload)
    else:
      super( MsgGPSTimeDepA, self).__init__()
      self.msg_type = SBP_MSG_GPS_TIME_DEP_A
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.wn = kwargs.pop('wn')
      self.tow = kwargs.pop('tow')
      self.ns_residual = kwargs.pop('ns_residual')
      self.flags = kwargs.pop('flags')

  def __repr__(self):
    return fmt_repr(self)

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    return MsgGPSTimeDepA.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgGPSTimeDepA(sbp, **d)

 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgGPSTimeDepA._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgGPSTimeDepA._parser.build(c)
    return self.pack()

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgGPSTimeDepA, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    
SBP_MSG_DOPS_DEP_A = 0x0206
class MsgDopsDepA(SBP):
  """SBP class for message MSG_DOPS_DEP_A (0x0206).

  You can have MSG_DOPS_DEP_A inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  This dilution of precision (DOP) message describes the effect of
navigation satellite geometry on positional measurement
precision.


  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  tow : int
    GPS Time of Week
  gdop : int
    Geometric Dilution of Precision
  pdop : int
    Position Dilution of Precision
  tdop : int
    Time Dilution of Precision
  hdop : int
    Horizontal Dilution of Precision
  vdop : int
    Vertical Dilution of Precision
  sender : int
    Optional sender ID, defaults to SENDER_ID (see sbp/msg.py).

  """
  _parser = Struct("MsgDopsDepA",
                   ULInt32('tow'),
                   ULInt16('gdop'),
                   ULInt16('pdop'),
                   ULInt16('tdop'),
                   ULInt16('hdop'),
                   ULInt16('vdop'),)
  __slots__ = [
               'tow',
               'gdop',
               'pdop',
               'tdop',
               'hdop',
               'vdop',
              ]

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      super( MsgDopsDepA,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.from_binary(sbp.payload)
    else:
      super( MsgDopsDepA, self).__init__()
      self.msg_type = SBP_MSG_DOPS_DEP_A
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.tow = kwargs.pop('tow')
      self.gdop = kwargs.pop('gdop')
      self.pdop = kwargs.pop('pdop')
      self.tdop = kwargs.pop('tdop')
      self.hdop = kwargs.pop('hdop')
      self.vdop = kwargs.pop('vdop')

  def __repr__(self):
    return fmt_repr(self)

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    return MsgDopsDepA.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgDopsDepA(sbp, **d)

 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgDopsDepA._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgDopsDepA._parser.build(c)
    return self.pack()

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgDopsDepA, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    
SBP_MSG_POS_ECEF_DEP_A = 0x0200
class MsgPosECEFDepA(SBP):
  """SBP class for message MSG_POS_ECEF_DEP_A (0x0200).

  You can have MSG_POS_ECEF_DEP_A inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  The position solution message reports absolute Earth Centered
Earth Fixed (ECEF) coordinates and the status (single point vs
pseudo-absolute RTK) of the position solution. If the rover
receiver knows the surveyed position of the base station and has
an RTK solution, this reports a pseudo-absolute position
solution using the base station position and the rover's RTK
baseline vector. The full GPS time is given by the preceding
MSG_GPS_TIME with the matching time-of-week (tow).


  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  tow : int
    GPS Time of Week
  x : double
    ECEF X coordinate
  y : double
    ECEF Y coordinate
  z : double
    ECEF Z coordinate
  accuracy : int
    Position accuracy estimate (not implemented). Defaults
to 0.

  n_sats : int
    Number of satellites used in solution
  flags : int
    Status flags
  sender : int
    Optional sender ID, defaults to SENDER_ID (see sbp/msg.py).

  """
  _parser = Struct("MsgPosECEFDepA",
                   ULInt32('tow'),
                   LFloat64('x'),
                   LFloat64('y'),
                   LFloat64('z'),
                   ULInt16('accuracy'),
                   ULInt8('n_sats'),
                   ULInt8('flags'),)
  __slots__ = [
               'tow',
               'x',
               'y',
               'z',
               'accuracy',
               'n_sats',
               'flags',
              ]

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      super( MsgPosECEFDepA,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.from_binary(sbp.payload)
    else:
      super( MsgPosECEFDepA, self).__init__()
      self.msg_type = SBP_MSG_POS_ECEF_DEP_A
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.tow = kwargs.pop('tow')
      self.x = kwargs.pop('x')
      self.y = kwargs.pop('y')
      self.z = kwargs.pop('z')
      self.accuracy = kwargs.pop('accuracy')
      self.n_sats = kwargs.pop('n_sats')
      self.flags = kwargs.pop('flags')

  def __repr__(self):
    return fmt_repr(self)

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    return MsgPosECEFDepA.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgPosECEFDepA(sbp, **d)

 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgPosECEFDepA._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgPosECEFDepA._parser.build(c)
    return self.pack()

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgPosECEFDepA, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    
SBP_MSG_POS_LLH_DEP_A = 0x0201
class MsgPosLLHDepA(SBP):
  """SBP class for message MSG_POS_LLH_DEP_A (0x0201).

  You can have MSG_POS_LLH_DEP_A inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  This position solution message reports the absolute geodetic
coordinates and the status (single point vs pseudo-absolute RTK)
of the position solution. If the rover receiver knows the
surveyed position of the base station and has an RTK solution,
this reports a pseudo-absolute position solution using the base
station position and the rover's RTK baseline vector. The full
GPS time is given by the preceding MSG_GPS_TIME with the
matching time-of-week (tow).


  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  tow : int
    GPS Time of Week
  lat : double
    Latitude
  lon : double
    Longitude
  height : double
    Height
  h_accuracy : int
    Horizontal position accuracy estimate (not
implemented). Defaults to 0.

  v_accuracy : int
    Vertical position accuracy estimate (not
implemented). Defaults to 0.

  n_sats : int
    Number of satellites used in solution.
  flags : int
    Status flags
  sender : int
    Optional sender ID, defaults to SENDER_ID (see sbp/msg.py).

  """
  _parser = Struct("MsgPosLLHDepA",
                   ULInt32('tow'),
                   LFloat64('lat'),
                   LFloat64('lon'),
                   LFloat64('height'),
                   ULInt16('h_accuracy'),
                   ULInt16('v_accuracy'),
                   ULInt8('n_sats'),
                   ULInt8('flags'),)
  __slots__ = [
               'tow',
               'lat',
               'lon',
               'height',
               'h_accuracy',
               'v_accuracy',
               'n_sats',
               'flags',
              ]

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      super( MsgPosLLHDepA,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.from_binary(sbp.payload)
    else:
      super( MsgPosLLHDepA, self).__init__()
      self.msg_type = SBP_MSG_POS_LLH_DEP_A
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.tow = kwargs.pop('tow')
      self.lat = kwargs.pop('lat')
      self.lon = kwargs.pop('lon')
      self.height = kwargs.pop('height')
      self.h_accuracy = kwargs.pop('h_accuracy')
      self.v_accuracy = kwargs.pop('v_accuracy')
      self.n_sats = kwargs.pop('n_sats')
      self.flags = kwargs.pop('flags')

  def __repr__(self):
    return fmt_repr(self)

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    return MsgPosLLHDepA.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgPosLLHDepA(sbp, **d)

 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgPosLLHDepA._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgPosLLHDepA._parser.build(c)
    return self.pack()

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgPosLLHDepA, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    
SBP_MSG_BASELINE_ECEF_DEP_A = 0x0202
class MsgBaselineECEFDepA(SBP):
  """SBP class for message MSG_BASELINE_ECEF_DEP_A (0x0202).

  You can have MSG_BASELINE_ECEF_DEP_A inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  This message reports the baseline solution in Earth Centered
Earth Fixed (ECEF) coordinates. This baseline is the relative
vector distance from the base station to the rover receiver. The
full GPS time is given by the preceding MSG_GPS_TIME with the
matching time-of-week (tow).


  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  tow : int
    GPS Time of Week
  x : int
    Baseline ECEF X coordinate
  y : int
    Baseline ECEF Y coordinate
  z : int
    Baseline ECEF Z coordinate
  accuracy : int
    Position accuracy estimate

  n_sats : int
    Number of satellites used in solution
  flags : int
    Status flags
  sender : int
    Optional sender ID, defaults to SENDER_ID (see sbp/msg.py).

  """
  _parser = Struct("MsgBaselineECEFDepA",
                   ULInt32('tow'),
                   SLInt32('x'),
                   SLInt32('y'),
                   SLInt32('z'),
                   ULInt16('accuracy'),
                   ULInt8('n_sats'),
                   ULInt8('flags'),)
  __slots__ = [
               'tow',
               'x',
               'y',
               'z',
               'accuracy',
               'n_sats',
               'flags',
              ]

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      super( MsgBaselineECEFDepA,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.from_binary(sbp.payload)
    else:
      super( MsgBaselineECEFDepA, self).__init__()
      self.msg_type = SBP_MSG_BASELINE_ECEF_DEP_A
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.tow = kwargs.pop('tow')
      self.x = kwargs.pop('x')
      self.y = kwargs.pop('y')
      self.z = kwargs.pop('z')
      self.accuracy = kwargs.pop('accuracy')
      self.n_sats = kwargs.pop('n_sats')
      self.flags = kwargs.pop('flags')

  def __repr__(self):
    return fmt_repr(self)

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    return MsgBaselineECEFDepA.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgBaselineECEFDepA(sbp, **d)

 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgBaselineECEFDepA._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgBaselineECEFDepA._parser.build(c)
    return self.pack()

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgBaselineECEFDepA, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    
SBP_MSG_BASELINE_NED_DEP_A = 0x0203
class MsgBaselineNEDDepA(SBP):
  """SBP class for message MSG_BASELINE_NED_DEP_A (0x0203).

  You can have MSG_BASELINE_NED_DEP_A inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  This message reports the baseline solution in North East Down
(NED) coordinates. This baseline is the relative vector distance
from the base station to the rover receiver, and NED coordinate
system is defined at the local WGS84 tangent plane centered at the
base station position.  The full GPS time is given by the
preceding MSG_GPS_TIME with the matching time-of-week (tow).


  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  tow : int
    GPS Time of Week
  n : int
    Baseline North coordinate
  e : int
    Baseline East coordinate
  d : int
    Baseline Down coordinate
  h_accuracy : int
    Horizontal position accuracy estimate (not
implemented). Defaults to 0.

  v_accuracy : int
    Vertical position accuracy estimate (not
implemented). Defaults to 0.

  n_sats : int
    Number of satellites used in solution
  flags : int
    Status flags
  sender : int
    Optional sender ID, defaults to SENDER_ID (see sbp/msg.py).

  """
  _parser = Struct("MsgBaselineNEDDepA",
                   ULInt32('tow'),
                   SLInt32('n'),
                   SLInt32('e'),
                   SLInt32('d'),
                   ULInt16('h_accuracy'),
                   ULInt16('v_accuracy'),
                   ULInt8('n_sats'),
                   ULInt8('flags'),)
  __slots__ = [
               'tow',
               'n',
               'e',
               'd',
               'h_accuracy',
               'v_accuracy',
               'n_sats',
               'flags',
              ]

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      super( MsgBaselineNEDDepA,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.from_binary(sbp.payload)
    else:
      super( MsgBaselineNEDDepA, self).__init__()
      self.msg_type = SBP_MSG_BASELINE_NED_DEP_A
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.tow = kwargs.pop('tow')
      self.n = kwargs.pop('n')
      self.e = kwargs.pop('e')
      self.d = kwargs.pop('d')
      self.h_accuracy = kwargs.pop('h_accuracy')
      self.v_accuracy = kwargs.pop('v_accuracy')
      self.n_sats = kwargs.pop('n_sats')
      self.flags = kwargs.pop('flags')

  def __repr__(self):
    return fmt_repr(self)

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    return MsgBaselineNEDDepA.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgBaselineNEDDepA(sbp, **d)

 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgBaselineNEDDepA._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgBaselineNEDDepA._parser.build(c)
    return self.pack()

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgBaselineNEDDepA, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    
SBP_MSG_VEL_ECEF_DEP_A = 0x0204
class MsgVelECEFDepA(SBP):
  """SBP class for message MSG_VEL_ECEF_DEP_A (0x0204).

  You can have MSG_VEL_ECEF_DEP_A inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  This message reports the velocity in Earth Centered Earth Fixed
(ECEF) coordinates. The full GPS time is given by the preceding
MSG_GPS_TIME with the matching time-of-week (tow).


  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  tow : int
    GPS Time of Week
  x : int
    Velocity ECEF X coordinate
  y : int
    Velocity ECEF Y coordinate
  z : int
    Velocity ECEF Z coordinate
  accuracy : int
    Velocity accuracy estimate (not implemented). Defaults
to 0.

  n_sats : int
    Number of satellites used in solution
  flags : int
    Status flags (reserved)
  sender : int
    Optional sender ID, defaults to SENDER_ID (see sbp/msg.py).

  """
  _parser = Struct("MsgVelECEFDepA",
                   ULInt32('tow'),
                   SLInt32('x'),
                   SLInt32('y'),
                   SLInt32('z'),
                   ULInt16('accuracy'),
                   ULInt8('n_sats'),
                   ULInt8('flags'),)
  __slots__ = [
               'tow',
               'x',
               'y',
               'z',
               'accuracy',
               'n_sats',
               'flags',
              ]

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      super( MsgVelECEFDepA,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.from_binary(sbp.payload)
    else:
      super( MsgVelECEFDepA, self).__init__()
      self.msg_type = SBP_MSG_VEL_ECEF_DEP_A
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.tow = kwargs.pop('tow')
      self.x = kwargs.pop('x')
      self.y = kwargs.pop('y')
      self.z = kwargs.pop('z')
      self.accuracy = kwargs.pop('accuracy')
      self.n_sats = kwargs.pop('n_sats')
      self.flags = kwargs.pop('flags')

  def __repr__(self):
    return fmt_repr(self)

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    return MsgVelECEFDepA.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgVelECEFDepA(sbp, **d)

 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgVelECEFDepA._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgVelECEFDepA._parser.build(c)
    return self.pack()

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgVelECEFDepA, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    
SBP_MSG_VEL_NED_DEP_A = 0x0205
class MsgVelNEDDepA(SBP):
  """SBP class for message MSG_VEL_NED_DEP_A (0x0205).

  You can have MSG_VEL_NED_DEP_A inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  This message reports the velocity in local North East Down (NED)
coordinates. The NED coordinate system is defined as the local WGS84
tangent plane centered at the current position. The full GPS time is
given by the preceding MSG_GPS_TIME with the matching time-of-week (tow).


  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  tow : int
    GPS Time of Week
  n : int
    Velocity North coordinate
  e : int
    Velocity East coordinate
  d : int
    Velocity Down coordinate
  h_accuracy : int
    Horizontal velocity accuracy estimate (not
implemented). Defaults to 0.

  v_accuracy : int
    Vertical velocity accuracy estimate (not
implemented). Defaults to 0.

  n_sats : int
    Number of satellites used in solution
  flags : int
    Status flags (reserved)
  sender : int
    Optional sender ID, defaults to SENDER_ID (see sbp/msg.py).

  """
  _parser = Struct("MsgVelNEDDepA",
                   ULInt32('tow'),
                   SLInt32('n'),
                   SLInt32('e'),
                   SLInt32('d'),
                   ULInt16('h_accuracy'),
                   ULInt16('v_accuracy'),
                   ULInt8('n_sats'),
                   ULInt8('flags'),)
  __slots__ = [
               'tow',
               'n',
               'e',
               'd',
               'h_accuracy',
               'v_accuracy',
               'n_sats',
               'flags',
              ]

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      super( MsgVelNEDDepA,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.from_binary(sbp.payload)
    else:
      super( MsgVelNEDDepA, self).__init__()
      self.msg_type = SBP_MSG_VEL_NED_DEP_A
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.tow = kwargs.pop('tow')
      self.n = kwargs.pop('n')
      self.e = kwargs.pop('e')
      self.d = kwargs.pop('d')
      self.h_accuracy = kwargs.pop('h_accuracy')
      self.v_accuracy = kwargs.pop('v_accuracy')
      self.n_sats = kwargs.pop('n_sats')
      self.flags = kwargs.pop('flags')

  def __repr__(self):
    return fmt_repr(self)

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    return MsgVelNEDDepA.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgVelNEDDepA(sbp, **d)

 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgVelNEDDepA._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgVelNEDDepA._parser.build(c)
    return self.pack()

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgVelNEDDepA, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    
SBP_MSG_BASELINE_HEADING_DEP_A = 0x0207
class MsgBaselineHeadingDepA(SBP):
  """SBP class for message MSG_BASELINE_HEADING_DEP_A (0x0207).

  You can have MSG_BASELINE_HEADING_DEP_A inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  This message reports the baseline heading pointing from the base station
to the rover relative to True North. The full GPS time is given by the
preceding MSG_GPS_TIME with the matching time-of-week (tow).


  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  tow : int
    GPS Time of Week
  heading : int
    Heading
  n_sats : int
    Number of satellites used in solution
  flags : int
    Status flags
  sender : int
    Optional sender ID, defaults to SENDER_ID (see sbp/msg.py).

  """
  _parser = Struct("MsgBaselineHeadingDepA",
                   ULInt32('tow'),
                   ULInt32('heading'),
                   ULInt8('n_sats'),
                   ULInt8('flags'),)
  __slots__ = [
               'tow',
               'heading',
               'n_sats',
               'flags',
              ]

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      super( MsgBaselineHeadingDepA,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.from_binary(sbp.payload)
    else:
      super( MsgBaselineHeadingDepA, self).__init__()
      self.msg_type = SBP_MSG_BASELINE_HEADING_DEP_A
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.tow = kwargs.pop('tow')
      self.heading = kwargs.pop('heading')
      self.n_sats = kwargs.pop('n_sats')
      self.flags = kwargs.pop('flags')

  def __repr__(self):
    return fmt_repr(self)

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    return MsgBaselineHeadingDepA.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgBaselineHeadingDepA(sbp, **d)

 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgBaselineHeadingDepA._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgBaselineHeadingDepA._parser.build(c)
    return self.pack()

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgBaselineHeadingDepA, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    

msg_classes = {
  0x0102: MsgGPSTime,
  0x0103: MsgUtcTime,
  0x0208: MsgDops,
  0x0209: MsgPosECEF,
  0x020A: MsgPosLLH,
  0x020B: MsgBaselineECEF,
  0x020C: MsgBaselineNED,
  0x020D: MsgVelECEF,
  0x020E: MsgVelNED,
  0x020F: MsgBaselineHeading,
  0x0210: MsgAgeCorrections,
  0x0100: MsgGPSTimeDepA,
  0x0206: MsgDopsDepA,
  0x0200: MsgPosECEFDepA,
  0x0201: MsgPosLLHDepA,
  0x0202: MsgBaselineECEFDepA,
  0x0203: MsgBaselineNEDDepA,
  0x0204: MsgVelECEFDepA,
  0x0205: MsgVelNEDDepA,
  0x0207: MsgBaselineHeadingDepA,
}