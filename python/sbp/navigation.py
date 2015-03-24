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

# Automatically generated from piksi/yaml/swiftnav/sbp/navigation.yaml
# with generate.py at 2015-03-23 14:30:01.617263. Please do not hand edit!


SBP_MSG_GPS_TIME = 0x0100
class MsgGPSTime(SBP):
  """SBP class for message MSG_GPS_TIME (0x0100).
  
  GPS Time.


  Parameters
  ----------
  wn : int
    GPS week number
  tow : int
    GPS Time of Week rounded to the nearest ms
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

  def __init__(self, sbp):
    self.__dict__.update(sbp.__dict__)
    self.from_binary(sbp.payload)

  def __repr__(self):
    return fmt_repr(self)
 
  def from_binary(self, d):
    p = MsgGPSTime._parser.parse(d)
    self.__dict__.update(dict(p.viewitems()))

  def to_binary(self):
    return MsgGPSTime.build(self.__dict__)
    
SBP_MSG_DOPS = 0x0206
class MsgDops(SBP):
  """SBP class for message MSG_DOPS (0x0206).
  
  Dilution of Precision.


  Parameters
  ----------
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

  def __init__(self, sbp):
    self.__dict__.update(sbp.__dict__)
    self.from_binary(sbp.payload)

  def __repr__(self):
    return fmt_repr(self)
 
  def from_binary(self, d):
    p = MsgDops._parser.parse(d)
    self.__dict__.update(dict(p.viewitems()))

  def to_binary(self):
    return MsgDops.build(self.__dict__)
    
SBP_MSG_POS_ECEF = 0x0200
class MsgPosECEF(SBP):
  """SBP class for message MSG_POS_ECEF (0x0200).
  
  Position solution in absolute Earth Centered Earth Fixed (ECEF)
coordinates.


  Parameters
  ----------
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

  def __init__(self, sbp):
    self.__dict__.update(sbp.__dict__)
    self.from_binary(sbp.payload)

  def __repr__(self):
    return fmt_repr(self)
 
  def from_binary(self, d):
    p = MsgPosECEF._parser.parse(d)
    self.__dict__.update(dict(p.viewitems()))

  def to_binary(self):
    return MsgPosECEF.build(self.__dict__)
    
SBP_MSG_POS_LLH = 0x0201
class MsgPosLLH(SBP):
  """SBP class for message MSG_POS_LLH (0x0201).
  
  Geodetic position solution.


  Parameters
  ----------
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

  def __init__(self, sbp):
    self.__dict__.update(sbp.__dict__)
    self.from_binary(sbp.payload)

  def __repr__(self):
    return fmt_repr(self)
 
  def from_binary(self, d):
    p = MsgPosLLH._parser.parse(d)
    self.__dict__.update(dict(p.viewitems()))

  def to_binary(self):
    return MsgPosLLH.build(self.__dict__)
    
SBP_MSG_BASELINE_ECEF = 0x0202
class MsgBaselineECEF(SBP):
  """SBP class for message MSG_BASELINE_ECEF (0x0202).
  
  Baseline in Earth Centered Earth Fixed (ECEF) coordinates.


  Parameters
  ----------
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

  def __init__(self, sbp):
    self.__dict__.update(sbp.__dict__)
    self.from_binary(sbp.payload)

  def __repr__(self):
    return fmt_repr(self)
 
  def from_binary(self, d):
    p = MsgBaselineECEF._parser.parse(d)
    self.__dict__.update(dict(p.viewitems()))

  def to_binary(self):
    return MsgBaselineECEF.build(self.__dict__)
    
SBP_MSG_BASELINE_NED = 0x0203
class MsgBaselineNED(SBP):
  """SBP class for message MSG_BASELINE_NED (0x0203).
  
  Baseline in local North East Down (NED) coordinates.


  Parameters
  ----------
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

  def __init__(self, sbp):
    self.__dict__.update(sbp.__dict__)
    self.from_binary(sbp.payload)

  def __repr__(self):
    return fmt_repr(self)
 
  def from_binary(self, d):
    p = MsgBaselineNED._parser.parse(d)
    self.__dict__.update(dict(p.viewitems()))

  def to_binary(self):
    return MsgBaselineNED.build(self.__dict__)
    
SBP_MSG_VEL_ECEF = 0x0204
class MsgVelECEF(SBP):
  """SBP class for message MSG_VEL_ECEF (0x0204).
  
  Velocity in Earth Centered Earth Fixed (ECEF) coordinates.


  Parameters
  ----------
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

  def __init__(self, sbp):
    self.__dict__.update(sbp.__dict__)
    self.from_binary(sbp.payload)

  def __repr__(self):
    return fmt_repr(self)
 
  def from_binary(self, d):
    p = MsgVelECEF._parser.parse(d)
    self.__dict__.update(dict(p.viewitems()))

  def to_binary(self):
    return MsgVelECEF.build(self.__dict__)
    
SBP_MSG_VEL_NED = 0x0205
class MsgVelNED(SBP):
  """SBP class for message MSG_VEL_NED (0x0205).
  
  Velocity in local North East Down (NED) coordinates.


  Parameters
  ----------
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

  def __init__(self, sbp):
    self.__dict__.update(sbp.__dict__)
    self.from_binary(sbp.payload)

  def __repr__(self):
    return fmt_repr(self)
 
  def from_binary(self, d):
    p = MsgVelNED._parser.parse(d)
    self.__dict__.update(dict(p.viewitems()))

  def to_binary(self):
    return MsgVelNED.build(self.__dict__)
    

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

def sbp_decode(t, d):
  return msg_classes[t](d)