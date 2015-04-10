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
Messages reporting accurately-timestamped external events,
e.g. camera shutter time

"""

from construct import *
from sbp import SBP
from sbp.utils import fmt_repr
import six

# Automatically generated from piksi/yaml/swiftnav/sbp/ext_events.yaml
# with generate.py at 2015-04-10 11:45:33.011582. Please do not hand edit!


SBP_MSG_EXT_EVENT = 0x0300
class MsgExtEvent(SBP):
  """SBP class for message MSG_EXT_EVENT (0x0300).
  
  Reports detection of an external event, the GPS time it occurred,
which pin it was and whether it was rising or falling.


  Parameters
  ----------
  wn : int
    GPS week number
  tow : int
    GPS Time of Week rounded to the nearest ms
  ns : int
    Nanosecond remainder of rounded tow
  flags : int
    Flags
  pin : int
    Pin number.  0..9 = DEBUG0..9.

  """
  _parser = Struct("MsgExtEvent",
                   ULInt16('wn'),
                   ULInt32('tow'),
                   SLInt32('ns'),
                   ULInt8('flags'),
                   ULInt8('pin'),)

  def __init__(self, sbp):
    self.__dict__.update(sbp.__dict__)
    self.from_binary(sbp.payload)

  def __repr__(self):
    return fmt_repr(self)
 
  def from_binary(self, d):
    p = MsgExtEvent._parser.parse(d)
    self.__dict__.update(dict(p.viewitems()))

  def to_binary(self):
    return MsgExtEvent.build(self.__dict__)
    

msg_classes = {
  0x0300: MsgExtEvent,
}