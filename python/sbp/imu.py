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
Inertial Measurement Unit (IMU) messages.
"""

import json

import construct

from sbp.msg import SBP, SENDER_ID
from sbp.utils import fmt_repr, exclude_fields, walk_json_dict, containerize

# Automatically generated from piksi/yaml/swiftnav/sbp/imu.yaml with generate.py.
# Please do not hand edit!


SBP_MSG_IMU_RAW = 0x0900
class MsgImuRaw(SBP):
  """SBP class for message MSG_IMU_RAW (0x0900).

  You can have MSG_IMU_RAW inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  Raw data from the Inertial Measurement Unit, containing accelerometer and
  gyroscope readings. The sense of the measurements are to be aligned with the
  indications on the device itself. Measurement units, which are specific to
  the device hardware and settings, are communicated via the MSG_IMU_AUX
  message. If using "time since startup" time tags, the receiving end will
  expect a `MSG_GNSS_TIME_OFFSET` when a PVT fix becomes available to
  synchronise IMU measurements with GNSS. The timestamp must wrap around to
  zero when reaching one week (604800 seconds).

  The time-tagging mode should not change throughout a run.

  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  tow : int
    Milliseconds since reference epoch and time status.
  tow_f : int
    Milliseconds since reference epoch, fractional part
  acc_x : int
    Acceleration in the IMU frame X axis
  acc_y : int
    Acceleration in the IMU frame Y axis
  acc_z : int
    Acceleration in the IMU frame Z axis
  gyr_x : int
    Angular rate around IMU frame X axis
  gyr_y : int
    Angular rate around IMU frame Y axis
  gyr_z : int
    Angular rate around IMU frame Z axis
  sender : int
    Optional sender ID, defaults to SENDER_ID (see sbp/msg.py).

  """
  _parser = construct.Struct(
                   'tow' / construct.Int32ul,
                   'tow_f' / construct.Int8ul,
                   'acc_x' / construct.Int16sl,
                   'acc_y' / construct.Int16sl,
                   'acc_z' / construct.Int16sl,
                   'gyr_x' / construct.Int16sl,
                   'gyr_y' / construct.Int16sl,
                   'gyr_z' / construct.Int16sl,)
  __slots__ = [
               'tow',
               'tow_f',
               'acc_x',
               'acc_y',
               'acc_z',
               'gyr_x',
               'gyr_y',
               'gyr_z',
              ]

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      super( MsgImuRaw,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.from_binary(sbp.payload)
    else:
      super( MsgImuRaw, self).__init__()
      self.msg_type = SBP_MSG_IMU_RAW
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.tow = kwargs.pop('tow')
      self.tow_f = kwargs.pop('tow_f')
      self.acc_x = kwargs.pop('acc_x')
      self.acc_y = kwargs.pop('acc_y')
      self.acc_z = kwargs.pop('acc_z')
      self.gyr_x = kwargs.pop('gyr_x')
      self.gyr_y = kwargs.pop('gyr_y')
      self.gyr_z = kwargs.pop('gyr_z')

  def __repr__(self):
    return fmt_repr(self)

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    return MsgImuRaw.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgImuRaw(sbp, **d)

 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgImuRaw._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgImuRaw._parser.build(c)
    return self.pack()

  def into_buffer(self, buf, offset):
    """Produce a framed/packed SBP message into the provided buffer and offset.

    """
    self.payload = containerize(exclude_fields(self))
    self.parser = MsgImuRaw._parser
    self.stream_payload.reset(buf, offset)
    return self.pack_into(buf, offset, self._build_payload)

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgImuRaw, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    
SBP_MSG_IMU_AUX = 0x0901
class MsgImuAux(SBP):
  """SBP class for message MSG_IMU_AUX (0x0901).

  You can have MSG_IMU_AUX inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  Auxiliary data specific to a particular IMU. The `imu_type` field will
  always be consistent but the rest of the payload is device specific and
  depends on the value of `imu_type`.

  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  imu_type : int
    IMU type
  temp : int
    Raw IMU temperature
  imu_conf : int
    IMU configuration
  sender : int
    Optional sender ID, defaults to SENDER_ID (see sbp/msg.py).

  """
  _parser = construct.Struct(
                   'imu_type' / construct.Int8ul,
                   'temp' / construct.Int16sl,
                   'imu_conf' / construct.Int8ul,)
  __slots__ = [
               'imu_type',
               'temp',
               'imu_conf',
              ]

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      super( MsgImuAux,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.from_binary(sbp.payload)
    else:
      super( MsgImuAux, self).__init__()
      self.msg_type = SBP_MSG_IMU_AUX
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.imu_type = kwargs.pop('imu_type')
      self.temp = kwargs.pop('temp')
      self.imu_conf = kwargs.pop('imu_conf')

  def __repr__(self):
    return fmt_repr(self)

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    return MsgImuAux.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgImuAux(sbp, **d)

 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgImuAux._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgImuAux._parser.build(c)
    return self.pack()

  def into_buffer(self, buf, offset):
    """Produce a framed/packed SBP message into the provided buffer and offset.

    """
    self.payload = containerize(exclude_fields(self))
    self.parser = MsgImuAux._parser
    self.stream_payload.reset(buf, offset)
    return self.pack_into(buf, offset, self._build_payload)

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgImuAux, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    

msg_classes = {
  0x0900: MsgImuRaw,
  0x0901: MsgImuAux,
}