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
Orientation Messages
"""

import json

import construct

from sbp.msg import SBP, SENDER_ID
from sbp.utils import fmt_repr, exclude_fields, walk_json_dict, containerize

# Automatically generated from piksi/yaml/swiftnav/sbp/orientation.yaml with generate.py.
# Please do not hand edit!


SBP_MSG_BASELINE_HEADING = 0x020F
class MsgBaselineHeading(SBP):
  """SBP class for message MSG_BASELINE_HEADING (0x020F).

  You can have MSG_BASELINE_HEADING inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  This message reports the baseline heading pointing from the base station to
  the rover relative to True North. The full GPS time is given by the
  preceding MSG_GPS_TIME with the matching time-of-week (tow). It is intended
  that time-matched RTK mode is used when the base station is moving.

  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  tow : int
    GPS Time of Week
  heading : int
    Heading
  n_sats : int
    Number of satellites used in solution
  flags : int
    Status flags
  sender : int
    Optional sender ID, defaults to SENDER_ID (see sbp/msg.py).

  """
  _parser = construct.Struct(
                   'tow' / construct.Int32ul,
                   'heading' / construct.Int32ul,
                   'n_sats' / construct.Int8ul,
                   'flags' / construct.Int8ul,)
  __slots__ = [
               'tow',
               'heading',
               'n_sats',
               'flags',
              ]

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      super( MsgBaselineHeading,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.from_binary(sbp.payload)
    else:
      super( MsgBaselineHeading, self).__init__()
      self.msg_type = SBP_MSG_BASELINE_HEADING
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.tow = kwargs.pop('tow')
      self.heading = kwargs.pop('heading')
      self.n_sats = kwargs.pop('n_sats')
      self.flags = kwargs.pop('flags')

  def __repr__(self):
    return fmt_repr(self)

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    return MsgBaselineHeading.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgBaselineHeading(sbp, **d)

 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgBaselineHeading._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgBaselineHeading._parser.build(c)
    return self.pack()

  def into_buffer(self, buf, offset):
    """Produce a framed/packed SBP message into the provided buffer and offset.

    """
    self.payload = containerize(exclude_fields(self))
    self.parser = MsgBaselineHeading._parser
    self.stream_payload.reset(buf, offset)
    return self.pack_into(buf, offset, self._build_payload)

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgBaselineHeading, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    
SBP_MSG_ORIENT_QUAT = 0x0220
class MsgOrientQuat(SBP):
  """SBP class for message MSG_ORIENT_QUAT (0x0220).

  You can have MSG_ORIENT_QUAT inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  This message reports the quaternion vector describing the vehicle body
  frame's orientation with respect to a local-level NED frame. The components
  of the vector should sum to a unit vector assuming that the LSB of each
  component as a value of 2^-31. This message will only be available in future
  INS versions of Swift Products and is not produced by Piksi Multi or Duro.

  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  tow : int
    GPS Time of Week
  w : int
    Real component
  x : int
    1st imaginary component
  y : int
    2nd imaginary component
  z : int
    3rd imaginary component
  w_accuracy : float
    Estimated standard deviation of w
  x_accuracy : float
    Estimated standard deviation of x
  y_accuracy : float
    Estimated standard deviation of y
  z_accuracy : float
    Estimated standard deviation of z
  flags : int
    Status flags
  sender : int
    Optional sender ID, defaults to SENDER_ID (see sbp/msg.py).

  """
  _parser = construct.Struct(
                   'tow' / construct.Int32ul,
                   'w' / construct.Int32sl,
                   'x' / construct.Int32sl,
                   'y' / construct.Int32sl,
                   'z' / construct.Int32sl,
                   'w_accuracy' / construct.Float32l,
                   'x_accuracy' / construct.Float32l,
                   'y_accuracy' / construct.Float32l,
                   'z_accuracy' / construct.Float32l,
                   'flags' / construct.Int8ul,)
  __slots__ = [
               'tow',
               'w',
               'x',
               'y',
               'z',
               'w_accuracy',
               'x_accuracy',
               'y_accuracy',
               'z_accuracy',
               'flags',
              ]

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      super( MsgOrientQuat,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.from_binary(sbp.payload)
    else:
      super( MsgOrientQuat, self).__init__()
      self.msg_type = SBP_MSG_ORIENT_QUAT
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.tow = kwargs.pop('tow')
      self.w = kwargs.pop('w')
      self.x = kwargs.pop('x')
      self.y = kwargs.pop('y')
      self.z = kwargs.pop('z')
      self.w_accuracy = kwargs.pop('w_accuracy')
      self.x_accuracy = kwargs.pop('x_accuracy')
      self.y_accuracy = kwargs.pop('y_accuracy')
      self.z_accuracy = kwargs.pop('z_accuracy')
      self.flags = kwargs.pop('flags')

  def __repr__(self):
    return fmt_repr(self)

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    return MsgOrientQuat.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgOrientQuat(sbp, **d)

 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgOrientQuat._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgOrientQuat._parser.build(c)
    return self.pack()

  def into_buffer(self, buf, offset):
    """Produce a framed/packed SBP message into the provided buffer and offset.

    """
    self.payload = containerize(exclude_fields(self))
    self.parser = MsgOrientQuat._parser
    self.stream_payload.reset(buf, offset)
    return self.pack_into(buf, offset, self._build_payload)

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgOrientQuat, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    
SBP_MSG_ORIENT_EULER = 0x0221
class MsgOrientEuler(SBP):
  """SBP class for message MSG_ORIENT_EULER (0x0221).

  You can have MSG_ORIENT_EULER inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  This message reports the yaw, pitch, and roll angles of the vehicle body
  frame. The rotations should applied intrinsically in the order yaw, pitch,
  and roll in order to rotate the from a frame aligned with the local-level
  NED frame to the vehicle body frame.  This message will only be available in
  future INS versions of Swift Products and is not produced by Piksi Multi or
  Duro.

  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  tow : int
    GPS Time of Week
  roll : int
    rotation about the forward axis of the vehicle
  pitch : int
    rotation about the rightward axis of the vehicle
  yaw : int
    rotation about the downward axis of the vehicle
  roll_accuracy : float
    Estimated standard deviation of roll
  pitch_accuracy : float
    Estimated standard deviation of pitch
  yaw_accuracy : float
    Estimated standard deviation of yaw
  flags : int
    Status flags
  sender : int
    Optional sender ID, defaults to SENDER_ID (see sbp/msg.py).

  """
  _parser = construct.Struct(
                   'tow' / construct.Int32ul,
                   'roll' / construct.Int32sl,
                   'pitch' / construct.Int32sl,
                   'yaw' / construct.Int32sl,
                   'roll_accuracy' / construct.Float32l,
                   'pitch_accuracy' / construct.Float32l,
                   'yaw_accuracy' / construct.Float32l,
                   'flags' / construct.Int8ul,)
  __slots__ = [
               'tow',
               'roll',
               'pitch',
               'yaw',
               'roll_accuracy',
               'pitch_accuracy',
               'yaw_accuracy',
               'flags',
              ]

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      super( MsgOrientEuler,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.from_binary(sbp.payload)
    else:
      super( MsgOrientEuler, self).__init__()
      self.msg_type = SBP_MSG_ORIENT_EULER
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.tow = kwargs.pop('tow')
      self.roll = kwargs.pop('roll')
      self.pitch = kwargs.pop('pitch')
      self.yaw = kwargs.pop('yaw')
      self.roll_accuracy = kwargs.pop('roll_accuracy')
      self.pitch_accuracy = kwargs.pop('pitch_accuracy')
      self.yaw_accuracy = kwargs.pop('yaw_accuracy')
      self.flags = kwargs.pop('flags')

  def __repr__(self):
    return fmt_repr(self)

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    return MsgOrientEuler.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgOrientEuler(sbp, **d)

 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgOrientEuler._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgOrientEuler._parser.build(c)
    return self.pack()

  def into_buffer(self, buf, offset):
    """Produce a framed/packed SBP message into the provided buffer and offset.

    """
    self.payload = containerize(exclude_fields(self))
    self.parser = MsgOrientEuler._parser
    self.stream_payload.reset(buf, offset)
    return self.pack_into(buf, offset, self._build_payload)

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgOrientEuler, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    
SBP_MSG_ANGULAR_RATE = 0x0222
class MsgAngularRate(SBP):
  """SBP class for message MSG_ANGULAR_RATE (0x0222).

  You can have MSG_ANGULAR_RATE inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  This message reports the orientation rates in the vehicle body frame. The
  values represent the measurements a strapped down gyroscope would make and
  are not equivalent to the time derivative of the Euler angles. The
  orientation and origin of the user frame is specified via device settings.
  By convention, the vehicle x-axis is expected to be aligned with the forward
  direction, while the vehicle y-axis is expected to be aligned with the right
  direction, and the vehicle z-axis should be aligned with the down direction.
  This message will only be available in future INS versions of Swift Products
  and is not produced by Piksi Multi or Duro.

  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  tow : int
    GPS Time of Week
  x : int
    angular rate about x axis
  y : int
    angular rate about y axis
  z : int
    angular rate about z axis
  flags : int
    Status flags
  sender : int
    Optional sender ID, defaults to SENDER_ID (see sbp/msg.py).

  """
  _parser = construct.Struct(
                   'tow' / construct.Int32ul,
                   'x' / construct.Int32sl,
                   'y' / construct.Int32sl,
                   'z' / construct.Int32sl,
                   'flags' / construct.Int8ul,)
  __slots__ = [
               'tow',
               'x',
               'y',
               'z',
               'flags',
              ]

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      super( MsgAngularRate,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.from_binary(sbp.payload)
    else:
      super( MsgAngularRate, self).__init__()
      self.msg_type = SBP_MSG_ANGULAR_RATE
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.tow = kwargs.pop('tow')
      self.x = kwargs.pop('x')
      self.y = kwargs.pop('y')
      self.z = kwargs.pop('z')
      self.flags = kwargs.pop('flags')

  def __repr__(self):
    return fmt_repr(self)

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    return MsgAngularRate.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgAngularRate(sbp, **d)

 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgAngularRate._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgAngularRate._parser.build(c)
    return self.pack()

  def into_buffer(self, buf, offset):
    """Produce a framed/packed SBP message into the provided buffer and offset.

    """
    self.payload = containerize(exclude_fields(self))
    self.parser = MsgAngularRate._parser
    self.stream_payload.reset(buf, offset)
    return self.pack_into(buf, offset, self._build_payload)

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgAngularRate, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    

msg_classes = {
  0x020F: MsgBaselineHeading,
  0x0220: MsgOrientQuat,
  0x0221: MsgOrientEuler,
  0x0222: MsgAngularRate,
}