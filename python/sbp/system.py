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
Standardized system messages from Swift Navigation devices.
"""

import json

import construct

from sbp.msg import SBP, SENDER_ID
from sbp.utils import fmt_repr, exclude_fields, walk_json_dict, containerize

# Automatically generated from piksi/yaml/swiftnav/sbp/system.yaml with generate.py.
# Please do not hand edit!


class SubSystemReport(object):
  """SubSystemReport.
  
  Report the general and specific state of a subsystem.  If the generic state
  is reported as initializing, the specific state should be ignored.
  
  Parameters
  ----------
  component : int
    Identity of reporting subsystem
  generic : int
    Generic form status report
  specific : int
    Subsystem specific status code

  """
  _parser = construct.Struct(
                     'component' / construct.Int16ul,
                     'generic' / construct.Int8ul,
                     'specific' / construct.Int8ul,)
  __slots__ = [
               'component',
               'generic',
               'specific',
              ]

  def __init__(self, payload=None, **kwargs):
    if payload:
      self.from_binary(payload)
    else:
      self.component = kwargs.pop('component')
      self.generic = kwargs.pop('generic')
      self.specific = kwargs.pop('specific')

  def __repr__(self):
    return fmt_repr(self)
  
  def from_binary(self, d):
    p = SubSystemReport._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))
    
class StatusJournalItem(object):
  """StatusJournalItem.
  
  Reports the uptime and the state of a subsystem via generic and specific
  status codes.  If the generic state is reported as initializing, the
  specific state should be ignored.
  
  Parameters
  ----------
  uptime : int
    Milliseconds since system startup
  report : SubSystemReport

  """
  _parser = construct.Struct(
                     'uptime' / construct.Int32ul,
                     'report' / SubSystemReport._parser,)
  __slots__ = [
               'uptime',
               'report',
              ]

  def __init__(self, payload=None, **kwargs):
    if payload:
      self.from_binary(payload)
    else:
      self.uptime = kwargs.pop('uptime')
      self.report = kwargs.pop('report')

  def __repr__(self):
    return fmt_repr(self)
  
  def from_binary(self, d):
    p = StatusJournalItem._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))
    
SBP_MSG_STARTUP = 0xFF00
class MsgStartup(SBP):
  """SBP class for message MSG_STARTUP (0xFF00).

  You can have MSG_STARTUP inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  The system start-up message is sent once on system start-up. It notifies the
  host or other attached devices that the system has started and is now ready
  to respond to commands or configuration requests.

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

  
  The heartbeat message is sent periodically to inform the host or other
  attached devices that the system is running. It is used to monitor system
  malfunctions. It also contains status flags that indicate to the host the
  status of the system and whether it is operating correctly. Currently, the
  expected heartbeat interval is 1 sec.

  The system error flag is used to indicate that an error has occurred in the
  system. To determine the source of the error, the remaining error flags
  should be inspected.

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
    
SBP_MSG_STATUS_REPORT = 0xFFFE
class MsgStatusReport(SBP):
  """SBP class for message MSG_STATUS_REPORT (0xFFFE).

  You can have MSG_STATUS_REPORT inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  The status report is sent periodically to inform the host or other attached
  devices that the system is running. It is used to monitor system
  malfunctions. It contains status reports that indicate to the host the
  status of each subsystem and whether it is operating correctly.

  Interpretation of the subsystem specific status code is product dependent,
  but if the generic status code is initializing, it should be ignored.  Refer
  to product documentation for details.

  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  reporting_system : int
    Identity of reporting system
  sbp_version : int
    SBP protocol version
  sequence : int
    Increments on each status report sent
  uptime : int
    Number of seconds since system start-up
  status : array
    Reported status of individual subsystems
  sender : int
    Optional sender ID, defaults to SENDER_ID (see sbp/msg.py).

  """
  _parser = construct.Struct(
                   'reporting_system' / construct.Int16ul,
                   'sbp_version' / construct.Int16ul,
                   'sequence' / construct.Int32ul,
                   'uptime' / construct.Int32ul,
                   'status' / construct.GreedyRange(SubSystemReport._parser),)
  __slots__ = [
               'reporting_system',
               'sbp_version',
               'sequence',
               'uptime',
               'status',
              ]

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      super( MsgStatusReport,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.from_binary(sbp.payload)
    else:
      super( MsgStatusReport, self).__init__()
      self.msg_type = SBP_MSG_STATUS_REPORT
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.reporting_system = kwargs.pop('reporting_system')
      self.sbp_version = kwargs.pop('sbp_version')
      self.sequence = kwargs.pop('sequence')
      self.uptime = kwargs.pop('uptime')
      self.status = kwargs.pop('status')

  def __repr__(self):
    return fmt_repr(self)

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    return MsgStatusReport.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgStatusReport(sbp, **d)

 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgStatusReport._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgStatusReport._parser.build(c)
    return self.pack()

  def into_buffer(self, buf, offset):
    """Produce a framed/packed SBP message into the provided buffer and offset.

    """
    self.payload = containerize(exclude_fields(self))
    self.parser = MsgStatusReport._parser
    self.stream_payload.reset(buf, offset)
    return self.pack_into(buf, offset, self._build_payload)

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgStatusReport, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    
SBP_MSG_STATUS_JOURNAL = 0xFFFD
class MsgStatusJournal(SBP):
  """SBP class for message MSG_STATUS_JOURNAL (0xFFFD).

  You can have MSG_STATUS_JOURNAL inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  The status journal message contains past status reports (see
  MSG_STATUS_REPORT) and functions as a error/event storage for telemetry
  purposes.

  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  reporting_system : int
    Identity of reporting system
  sbp_version : int
    SBP protocol version
  total_status_reports : int
    Total number of status reports sent since system startup
  sequence_descriptor : int
    Index and number of messages in this sequence. First nibble is the size of
    the sequence (n), second nibble is the zero-indexed counter (ith packet of
    n)
  journal : array
    Status journal
  sender : int
    Optional sender ID, defaults to SENDER_ID (see sbp/msg.py).

  """
  _parser = construct.Struct(
                   'reporting_system' / construct.Int16ul,
                   'sbp_version' / construct.Int16ul,
                   'total_status_reports' / construct.Int32ul,
                   'sequence_descriptor' / construct.Int8ul,
                   'journal' / construct.GreedyRange(StatusJournalItem._parser),)
  __slots__ = [
               'reporting_system',
               'sbp_version',
               'total_status_reports',
               'sequence_descriptor',
               'journal',
              ]

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      super( MsgStatusJournal,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.from_binary(sbp.payload)
    else:
      super( MsgStatusJournal, self).__init__()
      self.msg_type = SBP_MSG_STATUS_JOURNAL
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.reporting_system = kwargs.pop('reporting_system')
      self.sbp_version = kwargs.pop('sbp_version')
      self.total_status_reports = kwargs.pop('total_status_reports')
      self.sequence_descriptor = kwargs.pop('sequence_descriptor')
      self.journal = kwargs.pop('journal')

  def __repr__(self):
    return fmt_repr(self)

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    return MsgStatusJournal.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgStatusJournal(sbp, **d)

 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgStatusJournal._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgStatusJournal._parser.build(c)
    return self.pack()

  def into_buffer(self, buf, offset):
    """Produce a framed/packed SBP message into the provided buffer and offset.

    """
    self.payload = containerize(exclude_fields(self))
    self.parser = MsgStatusJournal._parser
    self.stream_payload.reset(buf, offset)
    return self.pack_into(buf, offset, self._build_payload)

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgStatusJournal, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    
SBP_MSG_INS_STATUS = 0xFF03
class MsgInsStatus(SBP):
  """SBP class for message MSG_INS_STATUS (0xFF03).

  You can have MSG_INS_STATUS inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  The INS status message describes the state of the operation and
  initialization of the inertial navigation system.

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
  from a device. It is not produced or available on general Swift Products. It
  is intended to be a low rate message for status purposes.

  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  id : int
    Index representing the type of telemetry in use.  It is implementation
    defined.
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
    Index representing the type of telemetry in use.  It is implementation
    defined.
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

  
  The INS update status message contains information about executed and
  rejected INS updates. This message is expected to be extended in the future
  as new types of measurements are being added.

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
    
SBP_MSG_GNSS_TIME_OFFSET = 0xFF07
class MsgGnssTimeOffset(SBP):
  """SBP class for message MSG_GNSS_TIME_OFFSET (0xFF07).

  You can have MSG_GNSS_TIME_OFFSET inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  The GNSS time offset message contains the information that is needed to
  translate messages tagged with a local timestamp (e.g. IMU or wheeltick
  messages) to GNSS time for the sender producing this message.

  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  weeks : int
    Weeks portion of the time offset
  milliseconds : int
    Milliseconds portion of the time offset
  microseconds : int
    Microseconds portion of the time offset
  flags : int
    Status flags (reserved)
  sender : int
    Optional sender ID, defaults to SENDER_ID (see sbp/msg.py).

  """
  _parser = construct.Struct(
                   'weeks' / construct.Int16sl,
                   'milliseconds' / construct.Int32sl,
                   'microseconds' / construct.Int16sl,
                   'flags' / construct.Int8ul,)
  __slots__ = [
               'weeks',
               'milliseconds',
               'microseconds',
               'flags',
              ]

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      super( MsgGnssTimeOffset,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.from_binary(sbp.payload)
    else:
      super( MsgGnssTimeOffset, self).__init__()
      self.msg_type = SBP_MSG_GNSS_TIME_OFFSET
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.weeks = kwargs.pop('weeks')
      self.milliseconds = kwargs.pop('milliseconds')
      self.microseconds = kwargs.pop('microseconds')
      self.flags = kwargs.pop('flags')

  def __repr__(self):
    return fmt_repr(self)

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    return MsgGnssTimeOffset.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgGnssTimeOffset(sbp, **d)

 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgGnssTimeOffset._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgGnssTimeOffset._parser.build(c)
    return self.pack()

  def into_buffer(self, buf, offset):
    """Produce a framed/packed SBP message into the provided buffer and offset.

    """
    self.payload = containerize(exclude_fields(self))
    self.parser = MsgGnssTimeOffset._parser
    self.stream_payload.reset(buf, offset)
    return self.pack_into(buf, offset, self._build_payload)

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgGnssTimeOffset, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    
SBP_MSG_PPS_TIME = 0xFF08
class MsgPpsTime(SBP):
  """SBP class for message MSG_PPS_TIME (0xFF08).

  You can have MSG_PPS_TIME inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  The PPS time message contains the value of the sender's local time in
  microseconds at the moment a pulse is detected on the PPS input. This is to
  be used for syncronisation of sensor data sampled with a local timestamp
  (e.g. IMU or wheeltick messages) where GNSS time is unknown to the sender.

  The local time used to timestamp the PPS pulse must be generated by the same
  clock which is used to timestamp the IMU/wheel sensor data and should follow
  the same roll-over rules.  A separate MSG_PPS_TIME message should be sent
  for each source of sensor data which uses PPS-relative timestamping.  The
  sender ID for each of these MSG_PPS_TIME messages should match the sender ID
  of the respective sensor data.

  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  time : int
    Local time in microseconds
  flags : int
    Status flags
  sender : int
    Optional sender ID, defaults to SENDER_ID (see sbp/msg.py).

  """
  _parser = construct.Struct(
                   'time' / construct.Int64ul,
                   'flags' / construct.Int8ul,)
  __slots__ = [
               'time',
               'flags',
              ]

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      super( MsgPpsTime,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.from_binary(sbp.payload)
    else:
      super( MsgPpsTime, self).__init__()
      self.msg_type = SBP_MSG_PPS_TIME
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.time = kwargs.pop('time')
      self.flags = kwargs.pop('flags')

  def __repr__(self):
    return fmt_repr(self)

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    return MsgPpsTime.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgPpsTime(sbp, **d)

 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgPpsTime._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgPpsTime._parser.build(c)
    return self.pack()

  def into_buffer(self, buf, offset):
    """Produce a framed/packed SBP message into the provided buffer and offset.

    """
    self.payload = containerize(exclude_fields(self))
    self.parser = MsgPpsTime._parser
    self.stream_payload.reset(buf, offset)
    return self.pack_into(buf, offset, self._build_payload)

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgPpsTime, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    
SBP_MSG_SENSOR_AID_EVENT = 0xFF09
class MsgSensorAidEvent(SBP):
  """SBP class for message MSG_SENSOR_AID_EVENT (0xFF09).

  You can have MSG_SENSOR_AID_EVENT inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  This diagnostic message contains state and update status information for all
  sensors that are being used by the fusion engine. This message will be
  generated asynchronously to the solution messages and will be emitted
  anytime a sensor update is being processed.

  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  time : int
    Update timestamp in milliseconds.
  sensor_type : int
    Sensor type
  sensor_id : int
    Sensor identifier
  sensor_state : int
    Reserved for future use
  n_available_meas : int
    Number of available measurements in this epoch
  n_attempted_meas : int
    Number of attempted measurements in this epoch
  n_accepted_meas : int
    Number of accepted measurements in this epoch
  flags : int
    Reserved for future use
  sender : int
    Optional sender ID, defaults to SENDER_ID (see sbp/msg.py).

  """
  _parser = construct.Struct(
                   'time' / construct.Int32ul,
                   'sensor_type' / construct.Int8ul,
                   'sensor_id' / construct.Int16ul,
                   'sensor_state' / construct.Int8ul,
                   'n_available_meas' / construct.Int8ul,
                   'n_attempted_meas' / construct.Int8ul,
                   'n_accepted_meas' / construct.Int8ul,
                   'flags' / construct.Int32ul,)
  __slots__ = [
               'time',
               'sensor_type',
               'sensor_id',
               'sensor_state',
               'n_available_meas',
               'n_attempted_meas',
               'n_accepted_meas',
               'flags',
              ]

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      super( MsgSensorAidEvent,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.from_binary(sbp.payload)
    else:
      super( MsgSensorAidEvent, self).__init__()
      self.msg_type = SBP_MSG_SENSOR_AID_EVENT
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.time = kwargs.pop('time')
      self.sensor_type = kwargs.pop('sensor_type')
      self.sensor_id = kwargs.pop('sensor_id')
      self.sensor_state = kwargs.pop('sensor_state')
      self.n_available_meas = kwargs.pop('n_available_meas')
      self.n_attempted_meas = kwargs.pop('n_attempted_meas')
      self.n_accepted_meas = kwargs.pop('n_accepted_meas')
      self.flags = kwargs.pop('flags')

  def __repr__(self):
    return fmt_repr(self)

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    return MsgSensorAidEvent.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgSensorAidEvent(sbp, **d)

 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgSensorAidEvent._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgSensorAidEvent._parser.build(c)
    return self.pack()

  def into_buffer(self, buf, offset):
    """Produce a framed/packed SBP message into the provided buffer and offset.

    """
    self.payload = containerize(exclude_fields(self))
    self.parser = MsgSensorAidEvent._parser
    self.stream_payload.reset(buf, offset)
    return self.pack_into(buf, offset, self._build_payload)

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgSensorAidEvent, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    
SBP_MSG_GROUP_META = 0xFF0A
class MsgGroupMeta(SBP):
  """SBP class for message MSG_GROUP_META (0xFF0A).

  You can have MSG_GROUP_META inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  This leading message lists the time metadata of the Solution Group. It also
  lists the atomic contents (i.e. types of messages included) of the Solution
  Group.

  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  group_id : int
    Id of the Msgs Group, 0 is Unknown, 1 is Bestpos, 2 is Gnss
  flags : int
    Status flags (reserved)
  n_group_msgs : int
    Size of list group_msgs
  group_msgs : array
    An in-order list of message types included in the Solution Group,
    including GROUP_META itself
  sender : int
    Optional sender ID, defaults to SENDER_ID (see sbp/msg.py).

  """
  _parser = construct.Struct(
                   'group_id' / construct.Int8ul,
                   'flags' / construct.Int8ul,
                   'n_group_msgs' / construct.Int8ul,
                   'group_msgs' / construct.GreedyRange(construct.Int16ul),)
  __slots__ = [
               'group_id',
               'flags',
               'n_group_msgs',
               'group_msgs',
              ]

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      super( MsgGroupMeta,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.from_binary(sbp.payload)
    else:
      super( MsgGroupMeta, self).__init__()
      self.msg_type = SBP_MSG_GROUP_META
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.group_id = kwargs.pop('group_id')
      self.flags = kwargs.pop('flags')
      self.n_group_msgs = kwargs.pop('n_group_msgs')
      self.group_msgs = kwargs.pop('group_msgs')

  def __repr__(self):
    return fmt_repr(self)

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    return MsgGroupMeta.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgGroupMeta(sbp, **d)

 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgGroupMeta._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgGroupMeta._parser.build(c)
    return self.pack()

  def into_buffer(self, buf, offset):
    """Produce a framed/packed SBP message into the provided buffer and offset.

    """
    self.payload = containerize(exclude_fields(self))
    self.parser = MsgGroupMeta._parser
    self.stream_payload.reset(buf, offset)
    return self.pack_into(buf, offset, self._build_payload)

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgGroupMeta, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    

msg_classes = {
  0xFF00: MsgStartup,
  0xFF02: MsgDgnssStatus,
  0xFFFF: MsgHeartbeat,
  0xFFFE: MsgStatusReport,
  0xFFFD: MsgStatusJournal,
  0xFF03: MsgInsStatus,
  0xFF04: MsgCsacTelemetry,
  0xFF05: MsgCsacTelemetryLabels,
  0xFF06: MsgInsUpdates,
  0xFF07: MsgGnssTimeOffset,
  0xFF08: MsgPpsTime,
  0xFF09: MsgSensorAidEvent,
  0xFF0A: MsgGroupMeta,
}