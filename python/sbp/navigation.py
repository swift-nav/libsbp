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
Geodetic navigation messages reporting GPS time, single-point
position, and RTK baseline position solutions.

"""

from construct import *
import json
from sbp import SBP
from sbp.utils import fmt_repr, exclude_fields, walk_json_dict
import six

# Automatically generated from piksi/yaml/swiftnav/sbp/navigation.yaml
# with generate.py at 2015-04-14 12:12:06.978883. Please do not hand edit!


SBP_MSG_GPS_TIME = 0x0100
class MsgGPSTime(SBP):
  """SBP class for message MSG_GPS_TIME (0x0100).

  You can have MSG_GPS_TIME inherent its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  This message reports the GPS time, an integer time scale
beginning at January 6, 1980 midnight. GPS time counts the weeks
and seconds of the week. The weeks begin at the Saturday/Sunday
transition. GPS week 0 began at the beginning of the GPS time
scale. Within each week number, the GPS time of the week is
between between 0 and 604800 seconds (=60*60*24*7).


  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  wn : int
    GPS week number
  tow : int
    GPS time of week rounded to the nearest ms
  ns : int
    Nanosecond remainder of rounded tow
  flags : int
    Status flags (reserved)

  """
  _parser = Struct("MsgGPSTime",
                   ULInt16('wn'),
                   ULInt32('tow'),
                   SLInt32('ns'),
                   ULInt8('flags'),)

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      self.__dict__.update(sbp.__dict__)
      self.from_binary(sbp.payload)
    else:
      self.wn = kwargs.pop('wn')
      self.tow = kwargs.pop('tow')
      self.ns = kwargs.pop('ns')
      self.flags = kwargs.pop('flags')

  def __repr__(self):
    return fmt_repr(self)
 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgGPSTime._parser.parse(d)
    self.__dict__.update(dict(p.viewitems()))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = Container(**exclude_fields(self))
    self.payload = MsgGPSTime._parser.build(c)
    return self.pack()

  def to_json(self):
    """Produce a JSON-encoded SBP message.

    """
    d = super( MsgGPSTime, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return json.dumps(d)

  @staticmethod
  def from_json(data):
    """Given a JSON-encoded message, build an object.

    """
    d = json.loads(data)
    sbp = SBP.from_json_dict(d)
    return MsgGPSTime(sbp)
    
SBP_MSG_DOPS = 0x0206
class MsgDops(SBP):
  """SBP class for message MSG_DOPS (0x0206).

  You can have MSG_DOPS inherent its fields directly
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

  """
  _parser = Struct("MsgDops",
                   ULInt32('tow'),
                   ULInt16('gdop'),
                   ULInt16('pdop'),
                   ULInt16('tdop'),
                   ULInt16('hdop'),
                   ULInt16('vdop'),)

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      self.__dict__.update(sbp.__dict__)
      self.from_binary(sbp.payload)
    else:
      self.tow = kwargs.pop('tow')
      self.gdop = kwargs.pop('gdop')
      self.pdop = kwargs.pop('pdop')
      self.tdop = kwargs.pop('tdop')
      self.hdop = kwargs.pop('hdop')
      self.vdop = kwargs.pop('vdop')

  def __repr__(self):
    return fmt_repr(self)
 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgDops._parser.parse(d)
    self.__dict__.update(dict(p.viewitems()))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = Container(**exclude_fields(self))
    self.payload = MsgDops._parser.build(c)
    return self.pack()

  def to_json(self):
    """Produce a JSON-encoded SBP message.

    """
    d = super( MsgDops, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return json.dumps(d)

  @staticmethod
  def from_json(data):
    """Given a JSON-encoded message, build an object.

    """
    d = json.loads(data)
    sbp = SBP.from_json_dict(d)
    return MsgDops(sbp)
    
SBP_MSG_POS_ECEF = 0x0200
class MsgPosECEF(SBP):
  """SBP class for message MSG_POS_ECEF (0x0200).

  You can have MSG_POS_ECEF inherent its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  The single-point position solution message reports absolute
Earth Centered Earth Fixed (ECEF) coordinates and the status
(single point absolute vs RTK) of the position solution. If the
rover receiver knows surveyed position of the base station and
has an RTK solution, this reports a pseudo-absolute position
solution using the base station position and the rover's RTK
baseline vector.


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
    Position accuracy estimate
  n_sats : int
    Number of satellites used in solution
  flags : int
    Status flags

  """
  _parser = Struct("MsgPosECEF",
                   ULInt32('tow'),
                   LFloat64('x'),
                   LFloat64('y'),
                   LFloat64('z'),
                   ULInt16('accuracy'),
                   ULInt8('n_sats'),
                   ULInt8('flags'),)

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      self.__dict__.update(sbp.__dict__)
      self.from_binary(sbp.payload)
    else:
      self.tow = kwargs.pop('tow')
      self.x = kwargs.pop('x')
      self.y = kwargs.pop('y')
      self.z = kwargs.pop('z')
      self.accuracy = kwargs.pop('accuracy')
      self.n_sats = kwargs.pop('n_sats')
      self.flags = kwargs.pop('flags')

  def __repr__(self):
    return fmt_repr(self)
 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgPosECEF._parser.parse(d)
    self.__dict__.update(dict(p.viewitems()))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = Container(**exclude_fields(self))
    self.payload = MsgPosECEF._parser.build(c)
    return self.pack()

  def to_json(self):
    """Produce a JSON-encoded SBP message.

    """
    d = super( MsgPosECEF, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return json.dumps(d)

  @staticmethod
  def from_json(data):
    """Given a JSON-encoded message, build an object.

    """
    d = json.loads(data)
    sbp = SBP.from_json_dict(d)
    return MsgPosECEF(sbp)
    
SBP_MSG_POS_LLH = 0x0201
class MsgPosLLH(SBP):
  """SBP class for message MSG_POS_LLH (0x0201).

  You can have MSG_POS_LLH inherent its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  This single-point position solution message reports the absolute
geodetic coordinates and the status (single point absolute vs
RTK) of the position solution. If the rover receiver knows the
surveyed position of the base station and has an RTK solution,
this reports a pseudo-absolute position solution using the base
station position and the rover's RTK baseline vector.


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
    Horizontal position accuracy estimate
  v_accuracy : int
    Vertical position accuracy estimate
  n_sats : int
    Number of satellites used in solution
  flags : int
    Status flags

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

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      self.__dict__.update(sbp.__dict__)
      self.from_binary(sbp.payload)
    else:
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
 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgPosLLH._parser.parse(d)
    self.__dict__.update(dict(p.viewitems()))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = Container(**exclude_fields(self))
    self.payload = MsgPosLLH._parser.build(c)
    return self.pack()

  def to_json(self):
    """Produce a JSON-encoded SBP message.

    """
    d = super( MsgPosLLH, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return json.dumps(d)

  @staticmethod
  def from_json(data):
    """Given a JSON-encoded message, build an object.

    """
    d = json.loads(data)
    sbp = SBP.from_json_dict(d)
    return MsgPosLLH(sbp)
    
SBP_MSG_BASELINE_ECEF = 0x0202
class MsgBaselineECEF(SBP):
  """SBP class for message MSG_BASELINE_ECEF (0x0202).

  You can have MSG_BASELINE_ECEF inherent its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  This message reports the baseline position solution in Earth
Centered Earth Fixed (ECEF) coordinates.


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

  """
  _parser = Struct("MsgBaselineECEF",
                   ULInt32('tow'),
                   SLInt32('x'),
                   SLInt32('y'),
                   SLInt32('z'),
                   ULInt16('accuracy'),
                   ULInt8('n_sats'),
                   ULInt8('flags'),)

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      self.__dict__.update(sbp.__dict__)
      self.from_binary(sbp.payload)
    else:
      self.tow = kwargs.pop('tow')
      self.x = kwargs.pop('x')
      self.y = kwargs.pop('y')
      self.z = kwargs.pop('z')
      self.accuracy = kwargs.pop('accuracy')
      self.n_sats = kwargs.pop('n_sats')
      self.flags = kwargs.pop('flags')

  def __repr__(self):
    return fmt_repr(self)
 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgBaselineECEF._parser.parse(d)
    self.__dict__.update(dict(p.viewitems()))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = Container(**exclude_fields(self))
    self.payload = MsgBaselineECEF._parser.build(c)
    return self.pack()

  def to_json(self):
    """Produce a JSON-encoded SBP message.

    """
    d = super( MsgBaselineECEF, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return json.dumps(d)

  @staticmethod
  def from_json(data):
    """Given a JSON-encoded message, build an object.

    """
    d = json.loads(data)
    sbp = SBP.from_json_dict(d)
    return MsgBaselineECEF(sbp)
    
SBP_MSG_BASELINE_NED = 0x0203
class MsgBaselineNED(SBP):
  """SBP class for message MSG_BASELINE_NED (0x0203).

  You can have MSG_BASELINE_NED inherent its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  This message reports the baseline position solution in North
East Down (NED) coordinates.


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

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      self.__dict__.update(sbp.__dict__)
      self.from_binary(sbp.payload)
    else:
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
 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgBaselineNED._parser.parse(d)
    self.__dict__.update(dict(p.viewitems()))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = Container(**exclude_fields(self))
    self.payload = MsgBaselineNED._parser.build(c)
    return self.pack()

  def to_json(self):
    """Produce a JSON-encoded SBP message.

    """
    d = super( MsgBaselineNED, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return json.dumps(d)

  @staticmethod
  def from_json(data):
    """Given a JSON-encoded message, build an object.

    """
    d = json.loads(data)
    sbp = SBP.from_json_dict(d)
    return MsgBaselineNED(sbp)
    
SBP_MSG_VEL_ECEF = 0x0204
class MsgVelECEF(SBP):
  """SBP class for message MSG_VEL_ECEF (0x0204).

  You can have MSG_VEL_ECEF inherent its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  This message reports the velocity in Earth Centered Earth Fixed
(ECEF) coordinates.


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
    Status flags (reserved)

  """
  _parser = Struct("MsgVelECEF",
                   ULInt32('tow'),
                   SLInt32('x'),
                   SLInt32('y'),
                   SLInt32('z'),
                   ULInt16('accuracy'),
                   ULInt8('n_sats'),
                   ULInt8('flags'),)

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      self.__dict__.update(sbp.__dict__)
      self.from_binary(sbp.payload)
    else:
      self.tow = kwargs.pop('tow')
      self.x = kwargs.pop('x')
      self.y = kwargs.pop('y')
      self.z = kwargs.pop('z')
      self.accuracy = kwargs.pop('accuracy')
      self.n_sats = kwargs.pop('n_sats')
      self.flags = kwargs.pop('flags')

  def __repr__(self):
    return fmt_repr(self)
 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgVelECEF._parser.parse(d)
    self.__dict__.update(dict(p.viewitems()))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = Container(**exclude_fields(self))
    self.payload = MsgVelECEF._parser.build(c)
    return self.pack()

  def to_json(self):
    """Produce a JSON-encoded SBP message.

    """
    d = super( MsgVelECEF, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return json.dumps(d)

  @staticmethod
  def from_json(data):
    """Given a JSON-encoded message, build an object.

    """
    d = json.loads(data)
    sbp = SBP.from_json_dict(d)
    return MsgVelECEF(sbp)
    
SBP_MSG_VEL_NED = 0x0205
class MsgVelNED(SBP):
  """SBP class for message MSG_VEL_NED (0x0205).

  You can have MSG_VEL_NED inherent its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  This message reports the velocity in local North East Down (NED)
coordinates.


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
    Status flags (reserved)

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

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      self.__dict__.update(sbp.__dict__)
      self.from_binary(sbp.payload)
    else:
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
 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgVelNED._parser.parse(d)
    self.__dict__.update(dict(p.viewitems()))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = Container(**exclude_fields(self))
    self.payload = MsgVelNED._parser.build(c)
    return self.pack()

  def to_json(self):
    """Produce a JSON-encoded SBP message.

    """
    d = super( MsgVelNED, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return json.dumps(d)

  @staticmethod
  def from_json(data):
    """Given a JSON-encoded message, build an object.

    """
    d = json.loads(data)
    sbp = SBP.from_json_dict(d)
    return MsgVelNED(sbp)
    

msg_classes = {
  0x0100: MsgGPSTime,
  0x0206: MsgDops,
  0x0200: MsgPosECEF,
  0x0201: MsgPosLLH,
  0x0202: MsgBaselineECEF,
  0x0203: MsgBaselineNED,
  0x0204: MsgVelECEF,
  0x0205: MsgVelNED,
}