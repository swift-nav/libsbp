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
Struct to represent the signal(constellation, band, PRN).
"""

from construct import *
import json
from sbp.msg import SBP, SENDER_ID
from sbp.utils import fmt_repr, exclude_fields, walk_json_dict, containerize, greedy_string

# Automatically generated from piksi/yaml/swiftnav/sbp/signal.yaml with generate.py.
# Please do not hand edit!


class sbp_signal(object):
  """sbp_signal.
  
  Signal identifier containing constellation, band, and PRN.

  
  Parameters
  ----------
  constellation : int
    Constellation from which the sattelite belongs to.
  band : int
    Band of the satellite.
  prn : int
    PRN of the satellite.

  """
  _parser = Embedded(Struct("sbp_signal",
                     ULInt8('constellation'),
                     ULInt8('band'),
                     ULInt16('prn'),))
  __slots__ = [
               'constellation',
               'band',
               'prn',
              ]

  def __init__(self, payload=None, **kwargs):
    if payload:
      self.from_binary(payload)
    else:
      self.constellation = kwargs.pop('constellation')
      self.band = kwargs.pop('band')
      self.prn = kwargs.pop('prn')

  def __repr__(self):
    return fmt_repr(self)
  
  def from_binary(self, d):
    p = sbp_signal._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    d = dict([(k, getattr(obj, k)) for k in self.__slots__])
    return sbp_signal.build(d)
    

msg_classes = {
}