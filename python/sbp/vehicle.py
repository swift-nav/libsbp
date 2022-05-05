#!/usr/bin/env python
# Copyright (C) 2015-2021 Swift Navigation Inc.
# Contact: https://support.swiftnav.com
#
# This source is subject to the license found in the file 'LICENSE' which must
# be be distributed together with this source. All other rights reserved.
#
# THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
# EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
# WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.


"""
Messages from a vehicle.
"""

import json

import construct

from sbp.msg import SBP, SENDER_ID
from sbp.utils import fmt_repr, exclude_fields, walk_json_dict, containerize

# Automatically generated from piksi/yaml/swiftnav/sbp/vehicle.yaml with generate.py.
# Please do not hand edit!


SBP_MSG_ODOMETRY = 0x0903
class MsgOdometry(SBP):
  """SBP class for message MSG_ODOMETRY (0x0903).

  You can have MSG_ODOMETRY inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  Message representing the x component of vehicle velocity in the user frame
  at the odometry reference point(s) specified by the user. The offset for the
  odometry reference point and the definition and origin of the user frame are
  defined through the device settings interface. There are 4 possible user-
  defined sources of this message which are labeled arbitrarily source 0
  through 3. If using "processor time" time tags, the receiving end will
  expect a `MSG_GNSS_TIME_OFFSET` when a PVT fix becomes available to
  synchronise odometry measurements with GNSS. Processor time shall roll over
  to zero after one week.

  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  tow : int
    Time field representing either milliseconds in the GPS Week or local CPU
    time from the producing system in milliseconds.  See the tow_source flag
    for the exact source of this timestamp.
  velocity : int
    The signed forward component of vehicle velocity.
  flags : int
    Status flags
  sender : int
    Optional sender ID, defaults to SENDER_ID (see sbp/msg.py).

  """
  _parser = construct.Struct(
                   'tow' / construct.Int32ul,
                   'velocity' / construct.Int32sl,
                   'flags' / construct.Int8ul,)
  __slots__ = [
               'tow',
               'velocity',
               'flags',
              ]

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      super( MsgOdometry,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.from_binary(sbp.payload)
    else:
      super( MsgOdometry, self).__init__()
      self.msg_type = SBP_MSG_ODOMETRY
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.tow = kwargs.pop('tow')
      self.velocity = kwargs.pop('velocity')
      self.flags = kwargs.pop('flags')

  def __repr__(self):
    return fmt_repr(self)

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    return MsgOdometry.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgOdometry(sbp, **d)

 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgOdometry._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgOdometry._parser.build(c)
    return self.pack()

  def into_buffer(self, buf, offset):
    """Produce a framed/packed SBP message into the provided buffer and offset.

    """
    self.payload = containerize(exclude_fields(self))
    self.parser = MsgOdometry._parser
    self.stream_payload.reset(buf, offset)
    return self.pack_into(buf, offset, self._build_payload)

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgOdometry, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    
SBP_MSG_WHEELTICK = 0x0904
class MsgWheeltick(SBP):
  """SBP class for message MSG_WHEELTICK (0x0904).

  You can have MSG_WHEELTICK inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  Message containing the accumulated distance travelled by a wheel located at
  an odometry reference point defined by the user. The offset for the odometry
  reference point and the definition and origin of the user frame are defined
  through the device settings interface. The source of this message is
  identified by the source field, which is an integer ranging from 0 to 255.
  The timestamp associated with this message should represent the time when
  the accumulated tick count reached the value given by the contents of this
  message as accurately as possible. If using "local CPU time" time tags, the
  receiving end will expect a `MSG_GNSS_TIME_OFFSET` when a PVT fix becomes
  available to synchronise wheeltick measurements with GNSS. Local CPU time
  shall roll over to zero after one week.

  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  time : int
    Time field representing either microseconds since the last PPS,
    microseconds in the GPS Week or local CPU time from the producing system
    in microseconds. See the synch_type field for the exact meaning of this
    timestamp.
  flags : int
    Field indicating the type of timestamp contained in the time field.
  source : int
    ID of the sensor producing this message
  ticks : int
    Free-running counter of the accumulated distance for this sensor. The
    counter should be incrementing if travelling into one direction and
    decrementing when travelling in the opposite direction.
  sender : int
    Optional sender ID, defaults to SENDER_ID (see sbp/msg.py).

  """
  _parser = construct.Struct(
                   'time' / construct.Int64ul,
                   'flags' / construct.Int8ul,
                   'source' / construct.Int8ul,
                   'ticks' / construct.Int32sl,)
  __slots__ = [
               'time',
               'flags',
               'source',
               'ticks',
              ]

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      super( MsgWheeltick,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.from_binary(sbp.payload)
    else:
      super( MsgWheeltick, self).__init__()
      self.msg_type = SBP_MSG_WHEELTICK
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.time = kwargs.pop('time')
      self.flags = kwargs.pop('flags')
      self.source = kwargs.pop('source')
      self.ticks = kwargs.pop('ticks')

  def __repr__(self):
    return fmt_repr(self)

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    return MsgWheeltick.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgWheeltick(sbp, **d)

 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgWheeltick._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgWheeltick._parser.build(c)
    return self.pack()

  def into_buffer(self, buf, offset):
    """Produce a framed/packed SBP message into the provided buffer and offset.

    """
    self.payload = containerize(exclude_fields(self))
    self.parser = MsgWheeltick._parser
    self.stream_payload.reset(buf, offset)
    return self.pack_into(buf, offset, self._build_payload)

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgWheeltick, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    

msg_classes = {
  0x0903: MsgOdometry,
  0x0904: MsgWheeltick,
}