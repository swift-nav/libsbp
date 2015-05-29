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
Deprecated SBP messages.
"""

from construct import *
import json
from sbp import SBP
from sbp.utils import fmt_repr, exclude_fields, walk_json_dict, containerize
import six

# Automatically generated from piksi/yaml/swiftnav/sbp/deprecated.yaml with generate.py.
# Please do not hand edit!


SBP_MSG_BOOTLOADER_HANDSHAKE_DEPRECATED = 0x00B0
class MsgBootloaderHandshakeDeprecated(SBP):
  """SBP class for message MSG_BOOTLOADER_HANDSHAKE_DEPRECATED (0x00B0).

  You can have MSG_BOOTLOADER_HANDSHAKE_DEPRECATED inherent its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  Deprecated.

  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  handshake : array
    Version number string (not NULL terminated)
  sender : int
    Optional sender ID, defaults to 0

  """
  _parser = Struct("MsgBootloaderHandshakeDeprecated",
                   OptionalGreedyRange(ULInt8('handshake')),)

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      self.__dict__.update(sbp.__dict__)
      self.from_binary(sbp.payload)
    else:
      super( MsgBootloaderHandshakeDeprecated, self).__init__()
      self.msg_type = SBP_MSG_BOOTLOADER_HANDSHAKE_DEPRECATED
      self.sender = kwargs.pop('sender', 0)
      self.handshake = kwargs.pop('handshake')

  def __repr__(self):
    return fmt_repr(self)
 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgBootloaderHandshakeDeprecated._parser.parse(d)
    self.__dict__.update(dict(p.viewitems()))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgBootloaderHandshakeDeprecated._parser.build(c)
    return self.pack()

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    sbp = SBP.from_json_dict(d)
    return MsgBootloaderHandshakeDeprecated(sbp)

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgBootloaderHandshakeDeprecated, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    
SBP_MSG_NAP_DEVICE_DNA_DEPRECATED = 0x00DD
class MsgNapDeviceDnaDeprecated(SBP):
  """SBP class for message MSG_NAP_DEVICE_DNA_DEPRECATED (0x00DD).

  You can have MSG_NAP_DEVICE_DNA_DEPRECATED inherent its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  Deprecated.

  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  dna : array
    57-bit SwiftNAP FPGA Device ID. Remaining bits are padded
on the right.

  sender : int
    Optional sender ID, defaults to 0

  """
  _parser = Struct("MsgNapDeviceDnaDeprecated",
                   Struct('dna', Array(8, ULInt8('dna'))),)

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      self.__dict__.update(sbp.__dict__)
      self.from_binary(sbp.payload)
    else:
      super( MsgNapDeviceDnaDeprecated, self).__init__()
      self.msg_type = SBP_MSG_NAP_DEVICE_DNA_DEPRECATED
      self.sender = kwargs.pop('sender', 0)
      self.dna = kwargs.pop('dna')

  def __repr__(self):
    return fmt_repr(self)
 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgNapDeviceDnaDeprecated._parser.parse(d)
    self.__dict__.update(dict(p.viewitems()))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgNapDeviceDnaDeprecated._parser.build(c)
    return self.pack()

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    sbp = SBP.from_json_dict(d)
    return MsgNapDeviceDnaDeprecated(sbp)

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgNapDeviceDnaDeprecated, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    
SBP_MSG_FLASH_PROGRAM_DEPRECATED = 0x00E0
class MsgFlashProgramDeprecated(SBP):
  """SBP class for message MSG_FLASH_PROGRAM_DEPRECATED (0x00E0).

  You can have MSG_FLASH_PROGRAM_DEPRECATED inherent its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  Deprecated.

  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  target : int
    Target flags
  addr_start : array
    Starting address offset to program
  addr_len : int
    Length of set of addresses to program, counting up from
starting address

  data : array
    Data to program addresses with, with length N=addr_len
  sender : int
    Optional sender ID, defaults to 0

  """
  _parser = Struct("MsgFlashProgramDeprecated",
                   ULInt8('target'),
                   Struct('addr_start', Array(3, ULInt8('addr_start'))),
                   ULInt8('addr_len'),
                   OptionalGreedyRange(ULInt8('data')),)

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      self.__dict__.update(sbp.__dict__)
      self.from_binary(sbp.payload)
    else:
      super( MsgFlashProgramDeprecated, self).__init__()
      self.msg_type = SBP_MSG_FLASH_PROGRAM_DEPRECATED
      self.sender = kwargs.pop('sender', 0)
      self.target = kwargs.pop('target')
      self.addr_start = kwargs.pop('addr_start')
      self.addr_len = kwargs.pop('addr_len')
      self.data = kwargs.pop('data')

  def __repr__(self):
    return fmt_repr(self)
 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgFlashProgramDeprecated._parser.parse(d)
    self.__dict__.update(dict(p.viewitems()))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgFlashProgramDeprecated._parser.build(c)
    return self.pack()

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    sbp = SBP.from_json_dict(d)
    return MsgFlashProgramDeprecated(sbp)

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgFlashProgramDeprecated, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    
SBP_MSG_FLASH_READ_DEPRECATED = 0x00E1
class MsgFlashReadDeprecated(SBP):
  """SBP class for message MSG_FLASH_READ_DEPRECATED (0x00E1).

  You can have MSG_FLASH_READ_DEPRECATED inherent its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  Deprecated.

  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  target : int
    Target flags
  addr_start : array
    Starting address offset to read from
  addr_len : int
    Length of set of addresses to read, counting up from
starting address

  sender : int
    Optional sender ID, defaults to 0

  """
  _parser = Struct("MsgFlashReadDeprecated",
                   ULInt8('target'),
                   Struct('addr_start', Array(3, ULInt8('addr_start'))),
                   ULInt8('addr_len'),)

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      self.__dict__.update(sbp.__dict__)
      self.from_binary(sbp.payload)
    else:
      super( MsgFlashReadDeprecated, self).__init__()
      self.msg_type = SBP_MSG_FLASH_READ_DEPRECATED
      self.sender = kwargs.pop('sender', 0)
      self.target = kwargs.pop('target')
      self.addr_start = kwargs.pop('addr_start')
      self.addr_len = kwargs.pop('addr_len')

  def __repr__(self):
    return fmt_repr(self)
 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgFlashReadDeprecated._parser.parse(d)
    self.__dict__.update(dict(p.viewitems()))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgFlashReadDeprecated._parser.build(c)
    return self.pack()

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    sbp = SBP.from_json_dict(d)
    return MsgFlashReadDeprecated(sbp)

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgFlashReadDeprecated, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    
SBP_MSG_STM_UNIQUE_ID_DEPRECATED = 0x00E5
class MsgStmUniqueIdDeprecated(SBP):
  """SBP class for message MSG_STM_UNIQUE_ID_DEPRECATED (0x00E5).

  You can have MSG_STM_UNIQUE_ID_DEPRECATED inherent its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  Deprecated.

  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  stm_id : array
    Device unique ID
  sender : int
    Optional sender ID, defaults to 0

  """
  _parser = Struct("MsgStmUniqueIdDeprecated",
                   Struct('stm_id', Array(12, ULInt8('stm_id'))),)

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      self.__dict__.update(sbp.__dict__)
      self.from_binary(sbp.payload)
    else:
      super( MsgStmUniqueIdDeprecated, self).__init__()
      self.msg_type = SBP_MSG_STM_UNIQUE_ID_DEPRECATED
      self.sender = kwargs.pop('sender', 0)
      self.stm_id = kwargs.pop('stm_id')

  def __repr__(self):
    return fmt_repr(self)
 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgStmUniqueIdDeprecated._parser.parse(d)
    self.__dict__.update(dict(p.viewitems()))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgStmUniqueIdDeprecated._parser.build(c)
    return self.pack()

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    sbp = SBP.from_json_dict(d)
    return MsgStmUniqueIdDeprecated(sbp)

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgStmUniqueIdDeprecated, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    
SBP_MSG_EPHEMERIS_DEPRECATED = 0x001A
class MsgEphemerisDeprecated(SBP):
  """SBP class for message MSG_EPHEMERIS_DEPRECATED (0x001A).

  You can have MSG_EPHEMERIS_DEPRECATED inherent its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  Deprecated.

  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  tgd : double
    Group delay differential between L1 and L2
  c_rs : double
    Amplitude of the sine harmonic correction term to the orbit radius
  c_rc : double
    Amplitude of the cosine harmonic correction term to the orbit radius
  c_uc : double
    Amplitude of the cosine harmonic correction term to the argument of latitude
  c_us : double
    Amplitude of the sine harmonic correction term to the argument of latitude
  c_ic : double
    Amplitude of the cosine harmonic correction term to the angle of inclination
  c_is : double
    Amplitude of the sine harmonic correction term to the angle of inclination
  dn : double
    Mean motion difference
  m0 : double
    Mean anomaly at reference time
  ecc : double
    Eccentricity of satellite orbit
  sqrta : double
    Square root of the semi-major axis of orbit
  omega0 : double
    Longitude of ascending node of orbit plane at weekly epoch
  omegadot : double
    Rate of right ascension
  w : double
    Argument of perigee
  inc : double
    Inclination
  inc_dot : double
    Inclination first derivative
  af0 : double
    Polynomial clock correction coefficient (clock bias)
  af1 : double
    Polynomial clock correction coefficient (clock drift)
  af2 : double
    Polynomial clock correction coefficient (rate of clock drift)
  toe_tow : double
    Time of week
  toe_wn : int
    Week number
  toc_tow : double
    Clock reference time of week
  toc_wn : int
    Clock reference week number
  valid : int
    Is valid?
  healthy : int
    Satellite is healthy?
  prn : int
    PRN being tracked
  sender : int
    Optional sender ID, defaults to 0

  """
  _parser = Struct("MsgEphemerisDeprecated",
                   LFloat64('tgd'),
                   LFloat64('c_rs'),
                   LFloat64('c_rc'),
                   LFloat64('c_uc'),
                   LFloat64('c_us'),
                   LFloat64('c_ic'),
                   LFloat64('c_is'),
                   LFloat64('dn'),
                   LFloat64('m0'),
                   LFloat64('ecc'),
                   LFloat64('sqrta'),
                   LFloat64('omega0'),
                   LFloat64('omegadot'),
                   LFloat64('w'),
                   LFloat64('inc'),
                   LFloat64('inc_dot'),
                   LFloat64('af0'),
                   LFloat64('af1'),
                   LFloat64('af2'),
                   LFloat64('toe_tow'),
                   ULInt16('toe_wn'),
                   LFloat64('toc_tow'),
                   ULInt16('toc_wn'),
                   ULInt8('valid'),
                   ULInt8('healthy'),
                   ULInt8('prn'),)

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      self.__dict__.update(sbp.__dict__)
      self.from_binary(sbp.payload)
    else:
      super( MsgEphemerisDeprecated, self).__init__()
      self.msg_type = SBP_MSG_EPHEMERIS_DEPRECATED
      self.sender = kwargs.pop('sender', 0)
      self.tgd = kwargs.pop('tgd')
      self.c_rs = kwargs.pop('c_rs')
      self.c_rc = kwargs.pop('c_rc')
      self.c_uc = kwargs.pop('c_uc')
      self.c_us = kwargs.pop('c_us')
      self.c_ic = kwargs.pop('c_ic')
      self.c_is = kwargs.pop('c_is')
      self.dn = kwargs.pop('dn')
      self.m0 = kwargs.pop('m0')
      self.ecc = kwargs.pop('ecc')
      self.sqrta = kwargs.pop('sqrta')
      self.omega0 = kwargs.pop('omega0')
      self.omegadot = kwargs.pop('omegadot')
      self.w = kwargs.pop('w')
      self.inc = kwargs.pop('inc')
      self.inc_dot = kwargs.pop('inc_dot')
      self.af0 = kwargs.pop('af0')
      self.af1 = kwargs.pop('af1')
      self.af2 = kwargs.pop('af2')
      self.toe_tow = kwargs.pop('toe_tow')
      self.toe_wn = kwargs.pop('toe_wn')
      self.toc_tow = kwargs.pop('toc_tow')
      self.toc_wn = kwargs.pop('toc_wn')
      self.valid = kwargs.pop('valid')
      self.healthy = kwargs.pop('healthy')
      self.prn = kwargs.pop('prn')

  def __repr__(self):
    return fmt_repr(self)
 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgEphemerisDeprecated._parser.parse(d)
    self.__dict__.update(dict(p.viewitems()))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgEphemerisDeprecated._parser.build(c)
    return self.pack()

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    sbp = SBP.from_json_dict(d)
    return MsgEphemerisDeprecated(sbp)

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgEphemerisDeprecated, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    

msg_classes = {
  0x00B0: MsgBootloaderHandshakeDeprecated,
  0x00DD: MsgNapDeviceDnaDeprecated,
  0x00E0: MsgFlashProgramDeprecated,
  0x00E1: MsgFlashReadDeprecated,
  0x00E5: MsgStmUniqueIdDeprecated,
  0x001A: MsgEphemerisDeprecated,
}