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
Various structs shared between modules
"""

from construct import *
import json
from sbp.msg import SBP, SENDER_ID, TYPES_NP, TYPES_KEYS_NP
from sbp.utils import fmt_repr, exclude_fields, walk_json_dict, containerize,\
                      greedy_string
import numpy as np
import traceback

# Automatically generated from piksi/yaml/swiftnav/sbp/gnss.yaml with generate.py.
# Please do not hand edit!


class GnssSignal16(object):
  """GnssSignal16.
  
  Signal identifier containing constellation, band, and satellite identifier

  
  Parameters
  ----------
  sat : int
    Constellation-specific satellite identifier
  code : int
    Signal constellation, band and code

  """
  _parser = Embedded(Struct("GnssSignal16",
                     ULInt8('sat'),
                     ULInt8('code'),))
  __slots__ = [
               'sat',
               'code',
              ]
  _fields = [
             ( 'u8', 'sat' ),
             ( 'u8', 'code' ),
            ]

  def __repr__(self):
    return fmt_repr(self)

  def __getitem__(self, item):
    return getattr(self, item)

  
  def from_binary(self, d, offset=0):
    size = 0
    for t, s in GnssSignal16._fields:
      if t in TYPES_KEYS_NP:
        a = np.ndarray(1, TYPES_NP[t], d, size + offset)
        size += a.itemsize
        setattr(self, s, a.item())
      else:
        o = globals()[t]()
        size += o.from_binary(d, size + offset)
        setattr(self, s, o)
    return size

  def to_binary(self):
    d = dict([(k, getattr(obj, k)) for k in self.__slots__])
    return GnssSignal16.build(d)
    
class GnssSignal(object):
  """GnssSignal.
  
  Signal identifier containing constellation, band, and satellite identifier

  
  Parameters
  ----------
  sat : int
    Constellation-specific satellite identifier.

Note: unlike GnssSignal16, GPS satellites are encoded as
(PRN - 1). Other constellations do not have this offset.

  code : int
    Signal constellation, band and code
  reserved : int
    Reserved

  """
  _parser = Embedded(Struct("GnssSignal",
                     ULInt16('sat'),
                     ULInt8('code'),
                     ULInt8('reserved'),))
  __slots__ = [
               'sat',
               'code',
               'reserved',
              ]
  _fields = [
             ( 'u16', 'sat' ),
             ( 'u8', 'code' ),
             ( 'u8', 'reserved' ),
            ]

  def __repr__(self):
    return fmt_repr(self)

  def __getitem__(self, item):
    return getattr(self, item)

  
  def from_binary(self, d, offset=0):
    size = 0
    for t, s in GnssSignal._fields:
      if t in TYPES_KEYS_NP:
        a = np.ndarray(1, TYPES_NP[t], d, size + offset)
        size += a.itemsize
        setattr(self, s, a.item())
      else:
        o = globals()[t]()
        size += o.from_binary(d, size + offset)
        setattr(self, s, o)
    return size

  def to_binary(self):
    d = dict([(k, getattr(obj, k)) for k in self.__slots__])
    return GnssSignal.build(d)
    
class GPSTime(object):
  """GPSTime.
  
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
  _parser = Embedded(Struct("GPSTime",
                     ULInt32('tow'),
                     ULInt16('wn'),))
  __slots__ = [
               'tow',
               'wn',
              ]
  _fields = [
             ( 'u32', 'tow' ),
             ( 'u16', 'wn' ),
            ]

  def __repr__(self):
    return fmt_repr(self)

  def __getitem__(self, item):
    return getattr(self, item)

  
  def from_binary(self, d, offset=0):
    size = 0
    for t, s in GPSTime._fields:
      if t in TYPES_KEYS_NP:
        a = np.ndarray(1, TYPES_NP[t], d, size + offset)
        size += a.itemsize
        setattr(self, s, a.item())
      else:
        o = globals()[t]()
        size += o.from_binary(d, size + offset)
        setattr(self, s, o)
    return size

  def to_binary(self):
    d = dict([(k, getattr(obj, k)) for k in self.__slots__])
    return GPSTime.build(d)
    
class GPSTimeSec(object):
  """GPSTimeSec.
  
  A GPS time, defined as the number of
seconds since beginning of the week on the Saturday/Sunday
transition.

  
  Parameters
  ----------
  tow : int
    Seconds since start of GPS week
  wn : int
    GPS week number

  """
  _parser = Embedded(Struct("GPSTimeSec",
                     ULInt32('tow'),
                     ULInt16('wn'),))
  __slots__ = [
               'tow',
               'wn',
              ]
  _fields = [
             ( 'u32', 'tow' ),
             ( 'u16', 'wn' ),
            ]

  def __repr__(self):
    return fmt_repr(self)

  def __getitem__(self, item):
    return getattr(self, item)

  
  def from_binary(self, d, offset=0):
    size = 0
    for t, s in GPSTimeSec._fields:
      if t in TYPES_KEYS_NP:
        a = np.ndarray(1, TYPES_NP[t], d, size + offset)
        size += a.itemsize
        setattr(self, s, a.item())
      else:
        o = globals()[t]()
        size += o.from_binary(d, size + offset)
        setattr(self, s, o)
    return size

  def to_binary(self):
    d = dict([(k, getattr(obj, k)) for k in self.__slots__])
    return GPSTimeSec.build(d)
    
class GPSTimeNano(object):
  """GPSTimeNano.
  
  A wire-appropriate receiver clock time, defined as the time
since the beginning of the week on the Saturday/Sunday
transition. In most cases, observations are epoch aligned
so ns field will be 0.

  
  Parameters
  ----------
  tow : int
    Milliseconds since start of GPS week
  ns_residual : int
    Nanosecond residual of millisecond-rounded TOW (ranges
from -500000 to 500000)

  wn : int
    GPS week number

  """
  _parser = Embedded(Struct("GPSTimeNano",
                     ULInt32('tow'),
                     SLInt32('ns_residual'),
                     ULInt16('wn'),))
  __slots__ = [
               'tow',
               'ns_residual',
               'wn',
              ]
  _fields = [
             ( 'u32', 'tow' ),
             ( 's32', 'ns_residual' ),
             ( 'u16', 'wn' ),
            ]

  def __repr__(self):
    return fmt_repr(self)

  def __getitem__(self, item):
    return getattr(self, item)

  
  def from_binary(self, d, offset=0):
    size = 0
    for t, s in GPSTimeNano._fields:
      if t in TYPES_KEYS_NP:
        a = np.ndarray(1, TYPES_NP[t], d, size + offset)
        size += a.itemsize
        setattr(self, s, a.item())
      else:
        o = globals()[t]()
        size += o.from_binary(d, size + offset)
        setattr(self, s, o)
    return size

  def to_binary(self):
    d = dict([(k, getattr(obj, k)) for k in self.__slots__])
    return GPSTimeNano.build(d)
    
class CarrierPhase(object):
  """CarrierPhase.
  
  Carrier phase measurement in cycles represented as a 40-bit
fixed point number with Q32.8 layout, i.e. 32-bits of whole
cycles and 8-bits of fractional cycles. This phase has the
same sign as the pseudorange.

  
  Parameters
  ----------
  i : int
    Carrier phase whole cycles
  f : int
    Carrier phase fractional part

  """
  _parser = Embedded(Struct("CarrierPhase",
                     SLInt32('i'),
                     ULInt8('f'),))
  __slots__ = [
               'i',
               'f',
              ]
  _fields = [
             ( 's32', 'i' ),
             ( 'u8', 'f' ),
            ]

  def __repr__(self):
    return fmt_repr(self)

  def __getitem__(self, item):
    return getattr(self, item)

  
  def from_binary(self, d, offset=0):
    size = 0
    for t, s in CarrierPhase._fields:
      if t in TYPES_KEYS_NP:
        a = np.ndarray(1, TYPES_NP[t], d, size + offset)
        size += a.itemsize
        setattr(self, s, a.item())
      else:
        o = globals()[t]()
        size += o.from_binary(d, size + offset)
        setattr(self, s, o)
    return size

  def to_binary(self):
    d = dict([(k, getattr(obj, k)) for k in self.__slots__])
    return CarrierPhase.build(d)
    

msg_classes = {
}