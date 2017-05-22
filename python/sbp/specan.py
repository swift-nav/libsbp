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
Spectrum analyzer and related interference messages
"""

from construct import *
import json
from sbp.msg import SBP, SENDER_ID
from sbp.utils import fmt_repr, exclude_fields, walk_json_dict, containerize, greedy_string
from sbp.gnss import *

# Automatically generated from piksi/yaml/swiftnav/sbp/specan.yaml with generate.py.
# Please do not hand edit!


SBP_MSG_SPECAN = 0x0050
class MsgSpecan(SBP):
  """SBP class for message MSG_SPECAN (0x0050).

  You can have MSG_SPECAN inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  Spectrum analyzer packet.


  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  t : GPSTime
    Receiver time of this observation
  freq_ref : float
    Reference frequency of this packet

  freq_step : float
    Frequency step of points in this packet

  amplitude_ref : float
    Reference amplitude of this packet

  amplitude_unit : float
    Amplitude unit value of points in this packet

  amplitude_value : array
    Amplitude values (in the above units) of points in this packet

  sender : int
    Optional sender ID, defaults to SENDER_ID (see sbp/msg.py).

  """
  _parser = Struct("MsgSpecan",
                   Struct('t', GPSTime._parser),
                   LFloat32('freq_ref'),
                   LFloat32('freq_step'),
                   LFloat32('amplitude_ref'),
                   LFloat32('amplitude_unit'),
                   OptionalGreedyRange(ULInt8('amplitude_value')),)
  __slots__ = [
               't',
               'freq_ref',
               'freq_step',
               'amplitude_ref',
               'amplitude_unit',
               'amplitude_value',
              ]

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      super( MsgSpecan,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.from_binary(sbp.payload)
    else:
      super( MsgSpecan, self).__init__()
      self.msg_type = SBP_MSG_SPECAN
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.t = kwargs.pop('t')
      self.freq_ref = kwargs.pop('freq_ref')
      self.freq_step = kwargs.pop('freq_step')
      self.amplitude_ref = kwargs.pop('amplitude_ref')
      self.amplitude_unit = kwargs.pop('amplitude_unit')
      self.amplitude_value = kwargs.pop('amplitude_value')

  def __repr__(self):
    return fmt_repr(self)

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    return MsgSpecan.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgSpecan(sbp, **d)

 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgSpecan._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgSpecan._parser.build(c)
    return self.pack()

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgSpecan, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    

msg_classes = {
  0x0050: MsgSpecan,
}