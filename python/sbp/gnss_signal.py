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
Struct to represent a signal (constellation, band, satellite identifier)
"""

from construct import *
import json
from sbp.msg import SBP, SENDER_ID
from sbp.utils import fmt_repr, exclude_fields, walk_json_dict, containerize, greedy_string

# Automatically generated from piksi/yaml/swiftnav/sbp/gnss_signal.yaml with generate.py.
# Please do not hand edit!


class GnssSignal(object):
  """GnssSignal.
  
  Signal identifier containing constellation, band, and satellite identifier

  
  Parameters
  ----------
  sat : int
    Constellation-specific satellite identifier
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

  def __init__(self, payload=None, **kwargs):
    if payload:
      self.from_binary(payload)
    else:
      self.sat = kwargs.pop('sat')
      self.code = kwargs.pop('code')
      self.reserved = kwargs.pop('reserved')

  def __repr__(self):
    return fmt_repr(self)
  
  def from_binary(self, d):
    p = GnssSignal._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    d = dict([(k, getattr(obj, k)) for k in self.__slots__])
    return GnssSignal.build(d)
    

msg_classes = {
}