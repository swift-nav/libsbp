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

# Automatically generated from piksi/yaml/swiftnav/sbp/lib.yaml
# with generate.py at 2015-03-16 14:37:11.232476. Please do not hand edit!


class Latency(object):
  """Latency.
  
  Statistics on the latency of observations received from the base
station. As observation packets are received their GPS time is
compared to the current GPS time calculated locally by the
receiver to give a precise measurement of the end-to-end
communication latency in the system.

  
  Parameters
  ----------
  avg : int
    Average latency.
  lmin : int
    Minimum latency.
  lmax : int
    Maximum latency.
  current : int
    Smoothed estimate of the current latency.

  """
  _parser = Struct("Latency",
                   SLInt32('avg'),
                   SLInt32('lmin'),
                   SLInt32('lmax'),
                   SLInt32('current'),)

  def __init__(self, payload):
    self.from_binary(payload)

  def __repr__(self):
    return fmt_repr(self)
  
  def from_binary(self, d):
    p = Latency._parser.parse(d)
    self.__dict__.update(dict(p.viewitems()))

  def to_binary(self):
    return Latency.build(self.__dict__)
    
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
  _parser = Struct("CarrierPhase",
                   ULInt32('i'),
                   ULInt8('f'),)

  def __init__(self, payload):
    self.from_binary(payload)

  def __repr__(self):
    return fmt_repr(self)
  
  def from_binary(self, d):
    p = CarrierPhase._parser.parse(d)
    self.__dict__.update(dict(p.viewitems()))

  def to_binary(self):
    return CarrierPhase.build(self.__dict__)
    

msg_classes = {
}

def sbp_decode(t, d):
  return msg_classes[t](d)