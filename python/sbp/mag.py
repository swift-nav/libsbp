#!/usr/bin/env python
# Copyright (C) 2015-2018 Swift Navigation Inc.
# Contact: Swift Navigation <dev@swiftnav.com>
#
# This source is subject to the license found in the file 'LICENSE' which must
# be be distributed together with this source. All other rights reserved.
#
# THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
# EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
# WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.


"""
Magnetometer (mag) messages.
"""

import json

import construct

from sbp.msg import SBP, SENDER_ID
from sbp.utils import fmt_repr, exclude_fields, walk_json_dict, containerize

# Automatically generated from piksi/yaml/swiftnav/sbp/mag.yaml with generate.py.
# Please do not hand edit!


SBP_MSG_MAG_RAW = 0x0902
class MsgMagRaw(SBP):
  """SBP class for message MSG_MAG_RAW (0x0902).

  You can have MSG_MAG_RAW inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  Raw data from the magnetometer.


  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  tow : int
    Milliseconds since start of GPS week. If the high bit is set, the
time is unknown or invalid.

  tow_f : int
    Milliseconds since start of GPS week, fractional part

  mag_x : int
    Magnetic field in the body frame X axis
  mag_y : int
    Magnetic field in the body frame Y axis
  mag_z : int
    Magnetic field in the body frame Z axis
  sender : int
    Optional sender ID, defaults to SENDER_ID (see sbp/msg.py).

  """
  _parser = construct.Struct(
                   'tow' / construct.Int32ul,
                   'tow_f' / construct.Int8ul,
                   'mag_x' / construct.Int16sl,
                   'mag_y' / construct.Int16sl,
                   'mag_z' / construct.Int16sl,)
  __slots__ = [
               'tow',
               'tow_f',
               'mag_x',
               'mag_y',
               'mag_z',
              ]

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      super( MsgMagRaw,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.from_binary(sbp.payload)
    else:
      super( MsgMagRaw, self).__init__()
      self.msg_type = SBP_MSG_MAG_RAW
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.tow = kwargs.pop('tow')
      self.tow_f = kwargs.pop('tow_f')
      self.mag_x = kwargs.pop('mag_x')
      self.mag_y = kwargs.pop('mag_y')
      self.mag_z = kwargs.pop('mag_z')

  def __repr__(self):
    return fmt_repr(self)

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    return MsgMagRaw.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgMagRaw(sbp, **d)

 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgMagRaw._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgMagRaw._parser.build(c)
    return self.pack()

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgMagRaw, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    

msg_classes = {
  0x0902: MsgMagRaw,
}