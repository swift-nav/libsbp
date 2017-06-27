#!/usr/bin/env python
# Copyright (C) 2011-2014 Swift Navigation Inc.
# Contact: Fergus Noble <fergus@swiftnav.com>
#
# This source is subject to the license found in the file 'LICENSE' which must
# be be distributed together with this source. All other rights reserved.
#
# THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
# EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
# WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.

import base64
import copy
import json
import struct

import construct

SBP_PREAMBLE = 0x55

# Default sender ID. Intended for messages sent from the host to the
# device.
SENDER_ID = 0x42

crc16_tab = [0x0000,0x1021,0x2042,0x3063,0x4084,0x50a5,0x60c6,0x70e7,
             0x8108,0x9129,0xa14a,0xb16b,0xc18c,0xd1ad,0xe1ce,0xf1ef,
             0x1231,0x0210,0x3273,0x2252,0x52b5,0x4294,0x72f7,0x62d6,
             0x9339,0x8318,0xb37b,0xa35a,0xd3bd,0xc39c,0xf3ff,0xe3de,
             0x2462,0x3443,0x0420,0x1401,0x64e6,0x74c7,0x44a4,0x5485,
             0xa56a,0xb54b,0x8528,0x9509,0xe5ee,0xf5cf,0xc5ac,0xd58d,
             0x3653,0x2672,0x1611,0x0630,0x76d7,0x66f6,0x5695,0x46b4,
             0xb75b,0xa77a,0x9719,0x8738,0xf7df,0xe7fe,0xd79d,0xc7bc,
             0x48c4,0x58e5,0x6886,0x78a7,0x0840,0x1861,0x2802,0x3823,
             0xc9cc,0xd9ed,0xe98e,0xf9af,0x8948,0x9969,0xa90a,0xb92b,
             0x5af5,0x4ad4,0x7ab7,0x6a96,0x1a71,0x0a50,0x3a33,0x2a12,
             0xdbfd,0xcbdc,0xfbbf,0xeb9e,0x9b79,0x8b58,0xbb3b,0xab1a,
             0x6ca6,0x7c87,0x4ce4,0x5cc5,0x2c22,0x3c03,0x0c60,0x1c41,
             0xedae,0xfd8f,0xcdec,0xddcd,0xad2a,0xbd0b,0x8d68,0x9d49,
             0x7e97,0x6eb6,0x5ed5,0x4ef4,0x3e13,0x2e32,0x1e51,0x0e70,
             0xff9f,0xefbe,0xdfdd,0xcffc,0xbf1b,0xaf3a,0x9f59,0x8f78,
             0x9188,0x81a9,0xb1ca,0xa1eb,0xd10c,0xc12d,0xf14e,0xe16f,
             0x1080,0x00a1,0x30c2,0x20e3,0x5004,0x4025,0x7046,0x6067,
             0x83b9,0x9398,0xa3fb,0xb3da,0xc33d,0xd31c,0xe37f,0xf35e,
             0x02b1,0x1290,0x22f3,0x32d2,0x4235,0x5214,0x6277,0x7256,
             0xb5ea,0xa5cb,0x95a8,0x8589,0xf56e,0xe54f,0xd52c,0xc50d,
             0x34e2,0x24c3,0x14a0,0x0481,0x7466,0x6447,0x5424,0x4405,
             0xa7db,0xb7fa,0x8799,0x97b8,0xe75f,0xf77e,0xc71d,0xd73c,
             0x26d3,0x36f2,0x0691,0x16b0,0x6657,0x7676,0x4615,0x5634,
             0xd94c,0xc96d,0xf90e,0xe92f,0x99c8,0x89e9,0xb98a,0xa9ab,
             0x5844,0x4865,0x7806,0x6827,0x18c0,0x08e1,0x3882,0x28a3,
             0xcb7d,0xdb5c,0xeb3f,0xfb1e,0x8bf9,0x9bd8,0xabbb,0xbb9a,
             0x4a75,0x5a54,0x6a37,0x7a16,0x0af1,0x1ad0,0x2ab3,0x3a92,
             0xfd2e,0xed0f,0xdd6c,0xcd4d,0xbdaa,0xad8b,0x9de8,0x8dc9,
             0x7c26,0x6c07,0x5c64,0x4c45,0x3ca2,0x2c83,0x1ce0,0x0cc1,
             0xef1f,0xff3e,0xcf5d,0xdf7c,0xaf9b,0xbfba,0x8fd9,0x9ff8,
             0x6e17,0x7e36,0x4e55,0x5e74,0x2e93,0x3eb2,0x0ed1,0x1ef0]

def crc16(s, crc=0):
  """CRC16 implementation acording to CCITT standards.

  """
  for ch in s:
    crc = ((crc<<8)&0xFFFF) ^ crc16_tab[ ((crc>>8)&0xFF) ^ (ord(ch)&0xFF) ]
    crc &= 0xFFFF
  return crc

class SBP(object):
  """Swift Binary Protocol container.

  """

  # _parser = Struct("SBP",
  _parser = construct.Struct(
                   'preamble'/construct.Int8ul,
                   'msg_type'/construct.Int16ul,
                   'sender'/construct.Int16ul,
                   'length'/construct.Int8ul,
                   'payload'/construct.Bytes(lambda ctx: ctx.length),
                   'crc'/construct.Int16ul,)
  __slots__ = ['preamble',
               'msg_type',
               'sender',
               'length',
               'payload',
               'crc']

  def __init__(self, msg_type=None, sender=SENDER_ID,
               length=None, payload=None, crc=None):
    self.preamble = SBP_PREAMBLE
    self.msg_type = msg_type
    self.sender = sender
    self.length = length
    self.payload = payload
    self.crc = crc

  def __eq__(self, other):
    try:
      if self is other:
        return True
      elif not isinstance(self, type(other)):
        return False
      elif self.__slots__ != other.__slots__:
        return False
      else:
        return all(getattr(self, s) == getattr(other, s) for s in self.__slots__)
    except AttributeError:
      return False

  def __update(self):
    raise NotImplementedError("Internal update used by children.")

  def _get_framed(self):
    """Returns the framed message and updates the CRC.

    """
    self.length = len(self.payload)
    framed_msg = struct.pack('<BHHB',
                             self.preamble,
                             self.msg_type,
                             self.sender,
                             self.length)
    framed_msg += self.payload
    self.crc = crc16(framed_msg[1:], 0)
    framed_msg += struct.pack('<H', self.crc)
    return framed_msg

  def pack(self):
    """Pack to framed binary message.

    """
    return self._get_framed()

  @staticmethod
  def unpack(d):
    """Unpack and return a framed binary message.

    """
    p = SBP._parser.parse(d)
    assert p.preamble == SBP_PREAMBLE, "Invalid preamble 0x%x." % p.preamble
    return SBP(p.msg_type, p.sender, p.length, p.payload, p.crc)

  def copy(self):
    return copy.deepcopy(self)

  def __repr__(self):
    p = (self.preamble, self.msg_type, self.sender, self.length,
         repr(self.payload), self.crc)
    fmt = "<SBP (preamble=0x%X, msg_type=0x%X, sender=%s, length=%d, payload=%s, crc=0x%X)>"
    return fmt % p

  def to_binary(self):
    ret = struct.pack("<BHHB", SBP_PREAMBLE,
                      self.msg_type, self.sender, len(self.payload))
    ret += self.payload
    crc = crc16(ret[1:])
    ret += struct.pack("<H", crc)
    return ret

  def to_json(self):
    """Produce a JSON-encoded SBP message.

    """
    d = self.to_json_dict()
    return json.dumps(d)

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded message, build an object.

    """
    d = json.loads(s)
    sbp = SBP.from_json_dict(d)
    return sbp

  @staticmethod
  def from_json_dict(d):
    sbp = SBP()
    sbp.msg_type = d.pop('msg_type')
    sbp.sender = d.pop('sender')
    sbp.length = d.pop('length')
    sbp.payload = base64.standard_b64decode(d.pop('payload'))
    sbp.crc = d.pop('crc')
    return sbp

  def to_json_dict(self):
    return {'preamble': self.preamble,
            'msg_type': self.msg_type,
            'sender': self.sender,
            'length': self.length,
            'payload': base64.standard_b64encode(self.payload),
            'crc': self.crc}
