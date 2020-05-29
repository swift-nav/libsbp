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
Standardized system messages from Swift Navigation devices.
"""

import json

import construct

from sbp.msg import SBP, SENDER_ID
from sbp.utils import fmt_repr, exclude_fields, walk_json_dict, containerize

# Automatically generated from piksi/yaml/swiftnav/sbp/system.yaml with generate.py.
# Please do not hand edit!


SBP_MSG_STARTUP = 0xFF00
class MsgStartup(SBP):
  """SBP class for message MSG_STARTUP (0xFF00).

  You can have MSG_STARTUP inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  The system start-up message is sent once on system
start-up. It notifies the host or other attached devices that
the system has started and is now ready to respond to commands
or configuration requests.


  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  cause : int
    Cause of startup
  startup_type : int
    Startup type
  reserved : int
    Reserved
  sender : int
    Optional sender ID, defaults to SENDER_ID (see sbp/msg.py).

  """
  _parser = construct.Struct(
                   'cause' / construct.Int8ul,
                   'startup_type' / construct.Int8ul,
                   'reserved' / construct.Int16ul,)
  __slots__ = [
               'cause',
               'startup_type',
               'reserved',
              ]

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      super( MsgStartup,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.from_binary(sbp.payload)
    else:
      super( MsgStartup, self).__init__()
      self.msg_type = SBP_MSG_STARTUP
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.cause = kwargs.pop('cause')
      self.startup_type = kwargs.pop('startup_type')
      self.reserved = kwargs.pop('reserved')

  def __repr__(self):
    return fmt_repr(self)

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    return MsgStartup.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgStartup(sbp, **d)

 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgStartup._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgStartup._parser.build(c)
    return self.pack()

  def into_buffer(self, buf, offset):
    """Produce a framed/packed SBP message into the provided buffer and offset.

    """
    self.payload = containerize(exclude_fields(self))
    self.parser = MsgStartup._parser
    self.stream_payload.reset(buf, offset)
    return self.pack_into(buf, offset, self._build_payload)

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgStartup, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    
SBP_MSG_DGNSS_STATUS = 0xFF02
class MsgDgnssStatus(SBP):
  """SBP class for message MSG_DGNSS_STATUS (0xFF02).

  You can have MSG_DGNSS_STATUS inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  This message provides information about the receipt of Differential
corrections.  It is expected to be sent with each receipt of a complete
corrections packet.


  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  flags : int
    Status flags
  latency : int
    Latency of observation receipt
  num_signals : int
    Number of signals from base station
  source : string
    Corrections source string
  sender : int
    Optional sender ID, defaults to SENDER_ID (see sbp/msg.py).

  """
  _parser = construct.Struct(
                   'flags' / construct.Int8ul,
                   'latency' / construct.Int16ul,
                   'num_signals' / construct.Int8ul,
                   'source' / construct.GreedyBytes,)
  __slots__ = [
               'flags',
               'latency',
               'num_signals',
               'source',
              ]

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      super( MsgDgnssStatus,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.from_binary(sbp.payload)
    else:
      super( MsgDgnssStatus, self).__init__()
      self.msg_type = SBP_MSG_DGNSS_STATUS
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.flags = kwargs.pop('flags')
      self.latency = kwargs.pop('latency')
      self.num_signals = kwargs.pop('num_signals')
      self.source = kwargs.pop('source')

  def __repr__(self):
    return fmt_repr(self)

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    return MsgDgnssStatus.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgDgnssStatus(sbp, **d)

 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgDgnssStatus._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgDgnssStatus._parser.build(c)
    return self.pack()

  def into_buffer(self, buf, offset):
    """Produce a framed/packed SBP message into the provided buffer and offset.

    """
    self.payload = containerize(exclude_fields(self))
    self.parser = MsgDgnssStatus._parser
    self.stream_payload.reset(buf, offset)
    return self.pack_into(buf, offset, self._build_payload)

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgDgnssStatus, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    
SBP_MSG_HEARTBEAT = 0xFFFF
class MsgHeartbeat(SBP):
  """SBP class for message MSG_HEARTBEAT (0xFFFF).

  You can have MSG_HEARTBEAT inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  The heartbeat message is sent periodically to inform the host
or other attached devices that the system is running. It is
used to monitor system malfunctions. It also contains status
flags that indicate to the host the status of the system and
whether it is operating correctly. Currently, the expected
heartbeat interval is 1 sec.

The system error flag is used to indicate that an error has
occurred in the system. To determine the source of the error,
the remaining error flags should be inspected.


  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  flags : int
    Status flags
  sender : int
    Optional sender ID, defaults to SENDER_ID (see sbp/msg.py).

  """
  _parser = construct.Struct(
                   'flags' / construct.Int32ul,)
  __slots__ = [
               'flags',
              ]

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      super( MsgHeartbeat,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.from_binary(sbp.payload)
    else:
      super( MsgHeartbeat, self).__init__()
      self.msg_type = SBP_MSG_HEARTBEAT
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.flags = kwargs.pop('flags')

  def __repr__(self):
    return fmt_repr(self)

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    return MsgHeartbeat.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgHeartbeat(sbp, **d)

 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgHeartbeat._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgHeartbeat._parser.build(c)
    return self.pack()

  def into_buffer(self, buf, offset):
    """Produce a framed/packed SBP message into the provided buffer and offset.

    """
    self.payload = containerize(exclude_fields(self))
    self.parser = MsgHeartbeat._parser
    self.stream_payload.reset(buf, offset)
    return self.pack_into(buf, offset, self._build_payload)

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgHeartbeat, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    
SBP_MSG_INS_STATUS = 0xFF03
class MsgInsStatus(SBP):
  """SBP class for message MSG_INS_STATUS (0xFF03).

  You can have MSG_INS_STATUS inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  The INS status message describes the state of the operation
and initialization of the inertial navigation system. 


  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  flags : int
    Status flags
  sender : int
    Optional sender ID, defaults to SENDER_ID (see sbp/msg.py).

  """
  _parser = construct.Struct(
                   'flags' / construct.Int32ul,)
  __slots__ = [
               'flags',
              ]

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      super( MsgInsStatus,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.from_binary(sbp.payload)
    else:
      super( MsgInsStatus, self).__init__()
      self.msg_type = SBP_MSG_INS_STATUS
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.flags = kwargs.pop('flags')

  def __repr__(self):
    return fmt_repr(self)

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    return MsgInsStatus.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgInsStatus(sbp, **d)

 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgInsStatus._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgInsStatus._parser.build(c)
    return self.pack()

  def into_buffer(self, buf, offset):
    """Produce a framed/packed SBP message into the provided buffer and offset.

    """
    self.payload = containerize(exclude_fields(self))
    self.parser = MsgInsStatus._parser
    self.stream_payload.reset(buf, offset)
    return self.pack_into(buf, offset, self._build_payload)

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgInsStatus, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    
SBP_MSG_CSAC_TELEMETRY = 0xFF04
class MsgCsacTelemetry(SBP):
  """SBP class for message MSG_CSAC_TELEMETRY (0xFF04).

  You can have MSG_CSAC_TELEMETRY inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  The CSAC telemetry message has an implementation defined telemetry string
from a device. It is not produced or available on general Swift Products.
It is intended to be a low rate message for status purposes.


  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  id : int
    Index representing the type of telemetry in use.  It is implemention defined.
  telemetry : string
    Comma separated list of values as defined by the index
  sender : int
    Optional sender ID, defaults to SENDER_ID (see sbp/msg.py).

  """
  _parser = construct.Struct(
                   'id' / construct.Int8ul,
                   'telemetry' / construct.GreedyBytes,)
  __slots__ = [
               'id',
               'telemetry',
              ]

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      super( MsgCsacTelemetry,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.from_binary(sbp.payload)
    else:
      super( MsgCsacTelemetry, self).__init__()
      self.msg_type = SBP_MSG_CSAC_TELEMETRY
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.id = kwargs.pop('id')
      self.telemetry = kwargs.pop('telemetry')

  def __repr__(self):
    return fmt_repr(self)

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    return MsgCsacTelemetry.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgCsacTelemetry(sbp, **d)

 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgCsacTelemetry._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgCsacTelemetry._parser.build(c)
    return self.pack()

  def into_buffer(self, buf, offset):
    """Produce a framed/packed SBP message into the provided buffer and offset.

    """
    self.payload = containerize(exclude_fields(self))
    self.parser = MsgCsacTelemetry._parser
    self.stream_payload.reset(buf, offset)
    return self.pack_into(buf, offset, self._build_payload)

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgCsacTelemetry, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    
SBP_MSG_CSAC_TELEMETRY_LABELS = 0xFF05
class MsgCsacTelemetryLabels(SBP):
  """SBP class for message MSG_CSAC_TELEMETRY_LABELS (0xFF05).

  You can have MSG_CSAC_TELEMETRY_LABELS inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  The CSAC telemetry message provides labels for each member of the string
produced by MSG_CSAC_TELEMETRY. It should be provided by a device at a lower
rate than the MSG_CSAC_TELEMETRY.


  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  id : int
    Index representing the type of telemetry in use.  It is implemention defined.
  telemetry_labels : string
    Comma separated list of telemetry field values
  sender : int
    Optional sender ID, defaults to SENDER_ID (see sbp/msg.py).

  """
  _parser = construct.Struct(
                   'id' / construct.Int8ul,
                   'telemetry_labels' / construct.GreedyBytes,)
  __slots__ = [
               'id',
               'telemetry_labels',
              ]

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      super( MsgCsacTelemetryLabels,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.from_binary(sbp.payload)
    else:
      super( MsgCsacTelemetryLabels, self).__init__()
      self.msg_type = SBP_MSG_CSAC_TELEMETRY_LABELS
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.id = kwargs.pop('id')
      self.telemetry_labels = kwargs.pop('telemetry_labels')

  def __repr__(self):
    return fmt_repr(self)

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    return MsgCsacTelemetryLabels.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgCsacTelemetryLabels(sbp, **d)

 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgCsacTelemetryLabels._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgCsacTelemetryLabels._parser.build(c)
    return self.pack()

  def into_buffer(self, buf, offset):
    """Produce a framed/packed SBP message into the provided buffer and offset.

    """
    self.payload = containerize(exclude_fields(self))
    self.parser = MsgCsacTelemetryLabels._parser
    self.stream_payload.reset(buf, offset)
    return self.pack_into(buf, offset, self._build_payload)

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgCsacTelemetryLabels, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    
SBP_MSG_INS_UPDATES = 0xFF06
class MsgInsUpdates(SBP):
  """SBP class for message MSG_INS_UPDATES (0xFF06).

  You can have MSG_INS_UPDATES inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  The INS update status message contains informations about executed and rejected INS updates.
This message is expected to be extended in the future as new types of measurements are being added.


  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  tow : int
    GPS Time of Week
  gnsspos : int
    GNSS position update status flags
  gnssvel : int
    GNSS velocity update status flags
  wheelticks : int
    Wheelticks update status flags
  speed : int
    Wheelticks update status flags
  nhc : int
    NHC update status flags
  zerovel : int
    Zero velocity update status flags
  sender : int
    Optional sender ID, defaults to SENDER_ID (see sbp/msg.py).

  """
  _parser = construct.Struct(
                   'tow' / construct.Int32ul,
                   'gnsspos' / construct.Int8ul,
                   'gnssvel' / construct.Int8ul,
                   'wheelticks' / construct.Int8ul,
                   'speed' / construct.Int8ul,
                   'nhc' / construct.Int8ul,
                   'zerovel' / construct.Int8ul,)
  __slots__ = [
               'tow',
               'gnsspos',
               'gnssvel',
               'wheelticks',
               'speed',
               'nhc',
               'zerovel',
              ]

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      super( MsgInsUpdates,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.from_binary(sbp.payload)
    else:
      super( MsgInsUpdates, self).__init__()
      self.msg_type = SBP_MSG_INS_UPDATES
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.tow = kwargs.pop('tow')
      self.gnsspos = kwargs.pop('gnsspos')
      self.gnssvel = kwargs.pop('gnssvel')
      self.wheelticks = kwargs.pop('wheelticks')
      self.speed = kwargs.pop('speed')
      self.nhc = kwargs.pop('nhc')
      self.zerovel = kwargs.pop('zerovel')

  def __repr__(self):
    return fmt_repr(self)

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    return MsgInsUpdates.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgInsUpdates(sbp, **d)

 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgInsUpdates._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgInsUpdates._parser.build(c)
    return self.pack()

  def into_buffer(self, buf, offset):
    """Produce a framed/packed SBP message into the provided buffer and offset.

    """
    self.payload = containerize(exclude_fields(self))
    self.parser = MsgInsUpdates._parser
    self.stream_payload.reset(buf, offset)
    return self.pack_into(buf, offset, self._build_payload)

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgInsUpdates, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    

msg_classes = {
  0xFF00: MsgStartup,
  0xFF02: MsgDgnssStatus,
  0xFFFF: MsgHeartbeat,
  0xFF03: MsgInsStatus,
  0xFF04: MsgCsacTelemetry,
  0xFF05: MsgCsacTelemetryLabels,
  0xFF06: MsgInsUpdates,
}