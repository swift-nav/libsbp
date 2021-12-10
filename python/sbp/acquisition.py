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
Satellite acquisition messages from the device.
"""

import json

import construct

from sbp.msg import SBP, SENDER_ID
from sbp.utils import fmt_repr, exclude_fields, walk_json_dict, containerize
from sbp.gnss import GnssSignal, GnssSignalDep

# Automatically generated from piksi/yaml/swiftnav/sbp/acquisition.yaml with generate.py.
# Please do not hand edit!


class AcqSvProfile(object):
  """AcqSvProfile.
  
  Profile for a specific SV for debugging purposes. The message describes SV
  profile during acquisition time. The message is used to debug and measure
  the performance.
  
  Parameters
  ----------
  job_type : int
    SV search job type (deep, fallback, etc)
  status : int
    Acquisition status 1 is Success, 0 is Failure
  cn0 : int
    CN0 value. Only valid if status is '1'
  int_time : int
    Acquisition integration time
  sid : GnssSignal
    GNSS signal for which acquisition was attempted
  bin_width : int
    Acq frequency bin width
  timestamp : int
    Timestamp of the job complete event
  time_spent : int
    Time spent to search for sid.code
  cf_min : int
    Doppler range lowest frequency
  cf_max : int
    Doppler range highest frequency
  cf : int
    Doppler value of detected peak. Only valid if status is '1'
  cp : int
    Codephase of detected peak. Only valid if status is '1'

  """
  _parser = construct.Struct(
                     'job_type' / construct.Int8ul,
                     'status' / construct.Int8ul,
                     'cn0' / construct.Int16ul,
                     'int_time' / construct.Int8ul,
                     'sid' / GnssSignal._parser,
                     'bin_width' / construct.Int16ul,
                     'timestamp' / construct.Int32ul,
                     'time_spent' / construct.Int32ul,
                     'cf_min' / construct.Int32sl,
                     'cf_max' / construct.Int32sl,
                     'cf' / construct.Int32sl,
                     'cp' / construct.Int32ul,)
  __slots__ = [
               'job_type',
               'status',
               'cn0',
               'int_time',
               'sid',
               'bin_width',
               'timestamp',
               'time_spent',
               'cf_min',
               'cf_max',
               'cf',
               'cp',
              ]

  def __init__(self, payload=None, **kwargs):
    if payload:
      self.from_binary(payload)
    else:
      self.job_type = kwargs.pop('job_type')
      self.status = kwargs.pop('status')
      self.cn0 = kwargs.pop('cn0')
      self.int_time = kwargs.pop('int_time')
      self.sid = kwargs.pop('sid')
      self.bin_width = kwargs.pop('bin_width')
      self.timestamp = kwargs.pop('timestamp')
      self.time_spent = kwargs.pop('time_spent')
      self.cf_min = kwargs.pop('cf_min')
      self.cf_max = kwargs.pop('cf_max')
      self.cf = kwargs.pop('cf')
      self.cp = kwargs.pop('cp')

  def __repr__(self):
    return fmt_repr(self)
  
  def from_binary(self, d):
    p = AcqSvProfile._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))
    
class AcqSvProfileDep(object):
  """AcqSvProfileDep.
  
  Deprecated.
  
  Parameters
  ----------
  job_type : int
    SV search job type (deep, fallback, etc)
  status : int
    Acquisition status 1 is Success, 0 is Failure
  cn0 : int
    CN0 value. Only valid if status is '1'
  int_time : int
    Acquisition integration time
  sid : GnssSignalDep
    GNSS signal for which acquisition was attempted
  bin_width : int
    Acq frequency bin width
  timestamp : int
    Timestamp of the job complete event
  time_spent : int
    Time spent to search for sid.code
  cf_min : int
    Doppler range lowest frequency
  cf_max : int
    Doppler range highest frequency
  cf : int
    Doppler value of detected peak. Only valid if status is '1'
  cp : int
    Codephase of detected peak. Only valid if status is '1'

  """
  _parser = construct.Struct(
                     'job_type' / construct.Int8ul,
                     'status' / construct.Int8ul,
                     'cn0' / construct.Int16ul,
                     'int_time' / construct.Int8ul,
                     'sid' / GnssSignalDep._parser,
                     'bin_width' / construct.Int16ul,
                     'timestamp' / construct.Int32ul,
                     'time_spent' / construct.Int32ul,
                     'cf_min' / construct.Int32sl,
                     'cf_max' / construct.Int32sl,
                     'cf' / construct.Int32sl,
                     'cp' / construct.Int32ul,)
  __slots__ = [
               'job_type',
               'status',
               'cn0',
               'int_time',
               'sid',
               'bin_width',
               'timestamp',
               'time_spent',
               'cf_min',
               'cf_max',
               'cf',
               'cp',
              ]

  def __init__(self, payload=None, **kwargs):
    if payload:
      self.from_binary(payload)
    else:
      self.job_type = kwargs.pop('job_type')
      self.status = kwargs.pop('status')
      self.cn0 = kwargs.pop('cn0')
      self.int_time = kwargs.pop('int_time')
      self.sid = kwargs.pop('sid')
      self.bin_width = kwargs.pop('bin_width')
      self.timestamp = kwargs.pop('timestamp')
      self.time_spent = kwargs.pop('time_spent')
      self.cf_min = kwargs.pop('cf_min')
      self.cf_max = kwargs.pop('cf_max')
      self.cf = kwargs.pop('cf')
      self.cp = kwargs.pop('cp')

  def __repr__(self):
    return fmt_repr(self)
  
  def from_binary(self, d):
    p = AcqSvProfileDep._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))
    
SBP_MSG_ACQ_RESULT = 0x002F
class MsgAcqResult(SBP):
  """SBP class for message MSG_ACQ_RESULT (0x002F).

  You can have MSG_ACQ_RESULT inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  This message describes the results from an attempted GPS signal acquisition
  search for a satellite PRN over a code phase/carrier frequency range. It
  contains the parameters of the point in the acquisition search space with
  the best carrier-to-noise (CN/0) ratio.

  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  cn0 : float
    CN/0 of best point
  cp : float
    Code phase of best point
  cf : float
    Carrier frequency of best point
  sid : GnssSignal
    GNSS signal for which acquisition was attempted
  sender : int
    Optional sender ID, defaults to SENDER_ID (see sbp/msg.py).

  """
  _parser = construct.Struct(
                   'cn0' / construct.Float32l,
                   'cp' / construct.Float32l,
                   'cf' / construct.Float32l,
                   'sid' / GnssSignal._parser,)
  __slots__ = [
               'cn0',
               'cp',
               'cf',
               'sid',
              ]

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      super( MsgAcqResult,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.from_binary(sbp.payload)
    else:
      super( MsgAcqResult, self).__init__()
      self.msg_type = SBP_MSG_ACQ_RESULT
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.cn0 = kwargs.pop('cn0')
      self.cp = kwargs.pop('cp')
      self.cf = kwargs.pop('cf')
      self.sid = kwargs.pop('sid')

  def __repr__(self):
    return fmt_repr(self)

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    return MsgAcqResult.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgAcqResult(sbp, **d)

 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgAcqResult._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgAcqResult._parser.build(c)
    return self.pack()

  def into_buffer(self, buf, offset):
    """Produce a framed/packed SBP message into the provided buffer and offset.

    """
    self.payload = containerize(exclude_fields(self))
    self.parser = MsgAcqResult._parser
    self.stream_payload.reset(buf, offset)
    return self.pack_into(buf, offset, self._build_payload)

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgAcqResult, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    
SBP_MSG_ACQ_RESULT_DEP_C = 0x001F
class MsgAcqResultDepC(SBP):
  """SBP class for message MSG_ACQ_RESULT_DEP_C (0x001F).

  You can have MSG_ACQ_RESULT_DEP_C inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  Deprecated.

  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  cn0 : float
    CN/0 of best point
  cp : float
    Code phase of best point
  cf : float
    Carrier frequency of best point
  sid : GnssSignalDep
    GNSS signal for which acquisition was attempted
  sender : int
    Optional sender ID, defaults to SENDER_ID (see sbp/msg.py).

  """
  _parser = construct.Struct(
                   'cn0' / construct.Float32l,
                   'cp' / construct.Float32l,
                   'cf' / construct.Float32l,
                   'sid' / GnssSignalDep._parser,)
  __slots__ = [
               'cn0',
               'cp',
               'cf',
               'sid',
              ]

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      super( MsgAcqResultDepC,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.from_binary(sbp.payload)
    else:
      super( MsgAcqResultDepC, self).__init__()
      self.msg_type = SBP_MSG_ACQ_RESULT_DEP_C
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.cn0 = kwargs.pop('cn0')
      self.cp = kwargs.pop('cp')
      self.cf = kwargs.pop('cf')
      self.sid = kwargs.pop('sid')

  def __repr__(self):
    return fmt_repr(self)

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    return MsgAcqResultDepC.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgAcqResultDepC(sbp, **d)

 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgAcqResultDepC._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgAcqResultDepC._parser.build(c)
    return self.pack()

  def into_buffer(self, buf, offset):
    """Produce a framed/packed SBP message into the provided buffer and offset.

    """
    self.payload = containerize(exclude_fields(self))
    self.parser = MsgAcqResultDepC._parser
    self.stream_payload.reset(buf, offset)
    return self.pack_into(buf, offset, self._build_payload)

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgAcqResultDepC, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    
SBP_MSG_ACQ_RESULT_DEP_B = 0x0014
class MsgAcqResultDepB(SBP):
  """SBP class for message MSG_ACQ_RESULT_DEP_B (0x0014).

  You can have MSG_ACQ_RESULT_DEP_B inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  Deprecated.

  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  snr : float
    SNR of best point. Currently in arbitrary SNR points, but will be in units
    of dB Hz in a later revision of this message.
  cp : float
    Code phase of best point
  cf : float
    Carrier frequency of best point
  sid : GnssSignalDep
    GNSS signal for which acquisition was attempted
  sender : int
    Optional sender ID, defaults to SENDER_ID (see sbp/msg.py).

  """
  _parser = construct.Struct(
                   'snr' / construct.Float32l,
                   'cp' / construct.Float32l,
                   'cf' / construct.Float32l,
                   'sid' / GnssSignalDep._parser,)
  __slots__ = [
               'snr',
               'cp',
               'cf',
               'sid',
              ]

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      super( MsgAcqResultDepB,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.from_binary(sbp.payload)
    else:
      super( MsgAcqResultDepB, self).__init__()
      self.msg_type = SBP_MSG_ACQ_RESULT_DEP_B
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.snr = kwargs.pop('snr')
      self.cp = kwargs.pop('cp')
      self.cf = kwargs.pop('cf')
      self.sid = kwargs.pop('sid')

  def __repr__(self):
    return fmt_repr(self)

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    return MsgAcqResultDepB.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgAcqResultDepB(sbp, **d)

 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgAcqResultDepB._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgAcqResultDepB._parser.build(c)
    return self.pack()

  def into_buffer(self, buf, offset):
    """Produce a framed/packed SBP message into the provided buffer and offset.

    """
    self.payload = containerize(exclude_fields(self))
    self.parser = MsgAcqResultDepB._parser
    self.stream_payload.reset(buf, offset)
    return self.pack_into(buf, offset, self._build_payload)

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgAcqResultDepB, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    
SBP_MSG_ACQ_RESULT_DEP_A = 0x0015
class MsgAcqResultDepA(SBP):
  """SBP class for message MSG_ACQ_RESULT_DEP_A (0x0015).

  You can have MSG_ACQ_RESULT_DEP_A inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  Deprecated.

  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  snr : float
    SNR of best point. Currently dimensionless, but will have units of dB Hz
    in the revision of this message.
  cp : float
    Code phase of best point
  cf : float
    Carrier frequency of best point
  prn : int
    PRN-1 identifier of the satellite signal for which acquisition was
    attempted
  sender : int
    Optional sender ID, defaults to SENDER_ID (see sbp/msg.py).

  """
  _parser = construct.Struct(
                   'snr' / construct.Float32l,
                   'cp' / construct.Float32l,
                   'cf' / construct.Float32l,
                   'prn' / construct.Int8ul,)
  __slots__ = [
               'snr',
               'cp',
               'cf',
               'prn',
              ]

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      super( MsgAcqResultDepA,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.from_binary(sbp.payload)
    else:
      super( MsgAcqResultDepA, self).__init__()
      self.msg_type = SBP_MSG_ACQ_RESULT_DEP_A
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.snr = kwargs.pop('snr')
      self.cp = kwargs.pop('cp')
      self.cf = kwargs.pop('cf')
      self.prn = kwargs.pop('prn')

  def __repr__(self):
    return fmt_repr(self)

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    return MsgAcqResultDepA.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgAcqResultDepA(sbp, **d)

 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgAcqResultDepA._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgAcqResultDepA._parser.build(c)
    return self.pack()

  def into_buffer(self, buf, offset):
    """Produce a framed/packed SBP message into the provided buffer and offset.

    """
    self.payload = containerize(exclude_fields(self))
    self.parser = MsgAcqResultDepA._parser
    self.stream_payload.reset(buf, offset)
    return self.pack_into(buf, offset, self._build_payload)

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgAcqResultDepA, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    
SBP_MSG_ACQ_SV_PROFILE = 0x002E
class MsgAcqSvProfile(SBP):
  """SBP class for message MSG_ACQ_SV_PROFILE (0x002E).

  You can have MSG_ACQ_SV_PROFILE inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  The message describes all SV profiles during acquisition time. The message
  is used to debug and measure the performance.

  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  acq_sv_profile : array
    SV profiles during acquisition time
  sender : int
    Optional sender ID, defaults to SENDER_ID (see sbp/msg.py).

  """
  _parser = construct.Struct(
                   'acq_sv_profile' / construct.GreedyRange(AcqSvProfile._parser),)
  __slots__ = [
               'acq_sv_profile',
              ]

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      super( MsgAcqSvProfile,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.from_binary(sbp.payload)
    else:
      super( MsgAcqSvProfile, self).__init__()
      self.msg_type = SBP_MSG_ACQ_SV_PROFILE
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.acq_sv_profile = kwargs.pop('acq_sv_profile')

  def __repr__(self):
    return fmt_repr(self)

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    return MsgAcqSvProfile.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgAcqSvProfile(sbp, **d)

 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgAcqSvProfile._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgAcqSvProfile._parser.build(c)
    return self.pack()

  def into_buffer(self, buf, offset):
    """Produce a framed/packed SBP message into the provided buffer and offset.

    """
    self.payload = containerize(exclude_fields(self))
    self.parser = MsgAcqSvProfile._parser
    self.stream_payload.reset(buf, offset)
    return self.pack_into(buf, offset, self._build_payload)

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgAcqSvProfile, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    
SBP_MSG_ACQ_SV_PROFILE_DEP = 0x001E
class MsgAcqSvProfileDep(SBP):
  """SBP class for message MSG_ACQ_SV_PROFILE_DEP (0x001E).

  You can have MSG_ACQ_SV_PROFILE_DEP inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  Deprecated.

  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  acq_sv_profile : array
    SV profiles during acquisition time
  sender : int
    Optional sender ID, defaults to SENDER_ID (see sbp/msg.py).

  """
  _parser = construct.Struct(
                   'acq_sv_profile' / construct.GreedyRange(AcqSvProfileDep._parser),)
  __slots__ = [
               'acq_sv_profile',
              ]

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      super( MsgAcqSvProfileDep,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.from_binary(sbp.payload)
    else:
      super( MsgAcqSvProfileDep, self).__init__()
      self.msg_type = SBP_MSG_ACQ_SV_PROFILE_DEP
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.acq_sv_profile = kwargs.pop('acq_sv_profile')

  def __repr__(self):
    return fmt_repr(self)

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    return MsgAcqSvProfileDep.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgAcqSvProfileDep(sbp, **d)

 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgAcqSvProfileDep._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgAcqSvProfileDep._parser.build(c)
    return self.pack()

  def into_buffer(self, buf, offset):
    """Produce a framed/packed SBP message into the provided buffer and offset.

    """
    self.payload = containerize(exclude_fields(self))
    self.parser = MsgAcqSvProfileDep._parser
    self.stream_payload.reset(buf, offset)
    return self.pack_into(buf, offset, self._build_payload)

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgAcqSvProfileDep, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    

msg_classes = {
  0x002F: MsgAcqResult,
  0x001F: MsgAcqResultDepC,
  0x0014: MsgAcqResultDepB,
  0x0015: MsgAcqResultDepA,
  0x002E: MsgAcqSvProfile,
  0x001E: MsgAcqSvProfileDep,
}