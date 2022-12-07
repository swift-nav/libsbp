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
Messages relating to signatures
"""

import json

import construct

from sbp.msg import SBP, SENDER_ID
from sbp.utils import fmt_repr, exclude_fields, walk_json_dict, containerize

# Automatically generated from piksi/yaml/swiftnav/sbp/signing.yaml with generate.py.
# Please do not hand edit!


SBP_MSG_ED25519_SIGNATURE_DEP = 0x0C01
class MsgEd25519SignatureDep(SBP):
  """SBP class for message MSG_ED25519_SIGNATURE_DEP (0x0C01).

  You can have MSG_ED25519_SIGNATURE_DEP inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  

  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  signature : array
    ED25519 signature for messages.
  fingerprint : array
    SHA-1 fingerprint of the associated certificate.
  signed_messages : array
    CRCs of signed messages.
  sender : int
    Optional sender ID, defaults to SENDER_ID (see sbp/msg.py).

  """
  _parser = construct.Struct(
                   'signature' / construct.Array(64, construct.Int8ul),
                   'fingerprint' / construct.Array(20, construct.Int8ul),
                   'signed_messages' / construct.GreedyRange(construct.Int32ul),)
  __slots__ = [
               'signature',
               'fingerprint',
               'signed_messages',
              ]

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      super( MsgEd25519SignatureDep,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.from_binary(sbp.payload)
    else:
      super( MsgEd25519SignatureDep, self).__init__()
      self.msg_type = SBP_MSG_ED25519_SIGNATURE_DEP
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.signature = kwargs.pop('signature')
      self.fingerprint = kwargs.pop('fingerprint')
      self.signed_messages = kwargs.pop('signed_messages')

  def __repr__(self):
    return fmt_repr(self)

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    return MsgEd25519SignatureDep.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgEd25519SignatureDep(sbp, **d)

 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgEd25519SignatureDep._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgEd25519SignatureDep._parser.build(c)
    return self.pack()

  def friendly_name(self):
    """Produces friendly human-readable name for this message

    """
    return "ED25519 SIGNATURE DEP"

  def into_buffer(self, buf, offset):
    """Produce a framed/packed SBP message into the provided buffer and offset.

    """
    self.payload = containerize(exclude_fields(self))
    self.parser = MsgEd25519SignatureDep._parser
    self.stream_payload.reset(buf, offset)
    return self.pack_into(buf, offset, self._build_payload)

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgEd25519SignatureDep, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    
SBP_MSG_ED25519_CERTIFICATE = 0x0C02
class MsgEd25519Certificate(SBP):
  """SBP class for message MSG_ED25519_CERTIFICATE (0x0C02).

  You can have MSG_ED25519_CERTIFICATE inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  

  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  n_msg : int
    Total number messages that make up the certificate. First nibble is the
    size of the sequence (n), second nibble is the zero-indexed counter (ith
    packet of n)
  fingerprint : array
    SHA-1 fingerprint of the associated certificate.
  certificate_bytes : array
    ED25519 certificate bytes.
  sender : int
    Optional sender ID, defaults to SENDER_ID (see sbp/msg.py).

  """
  _parser = construct.Struct(
                   'n_msg' / construct.Int8ul,
                   'fingerprint' / construct.Array(20, construct.Int8ul),
                   'certificate_bytes' / construct.GreedyRange(construct.Int8ul),)
  __slots__ = [
               'n_msg',
               'fingerprint',
               'certificate_bytes',
              ]

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      super( MsgEd25519Certificate,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.from_binary(sbp.payload)
    else:
      super( MsgEd25519Certificate, self).__init__()
      self.msg_type = SBP_MSG_ED25519_CERTIFICATE
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.n_msg = kwargs.pop('n_msg')
      self.fingerprint = kwargs.pop('fingerprint')
      self.certificate_bytes = kwargs.pop('certificate_bytes')

  def __repr__(self):
    return fmt_repr(self)

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    return MsgEd25519Certificate.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgEd25519Certificate(sbp, **d)

 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgEd25519Certificate._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgEd25519Certificate._parser.build(c)
    return self.pack()

  def friendly_name(self):
    """Produces friendly human-readable name for this message

    """
    return "ED25519 CERTIFICATE"

  def into_buffer(self, buf, offset):
    """Produce a framed/packed SBP message into the provided buffer and offset.

    """
    self.payload = containerize(exclude_fields(self))
    self.parser = MsgEd25519Certificate._parser
    self.stream_payload.reset(buf, offset)
    return self.pack_into(buf, offset, self._build_payload)

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgEd25519Certificate, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    
SBP_MSG_ED25519_SIGNATURE = 0x0C03
class MsgEd25519Signature(SBP):
  """SBP class for message MSG_ED25519_SIGNATURE (0x0C03).

  You can have MSG_ED25519_SIGNATURE inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  

  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  stream_counter : int
    Signature message counter. Zero indexed and incremented with each
    signature message. The counter will not increment if this message was in
    response to an on demand request. The counter will roll over after 256
    messages. Upon connection, the value of the counter may not initially be
    zero.
  on_demand_counter : int
    On demand message counter. Zero indexed and incremented with each
    signature message sent in response to an on demand message. The counter
    will roll over after 256 messages. Upon connection, the value of the
    counter may not initially be zero.
  signature : array
    ED25519 signature for messages.
  fingerprint : array
    SHA-1 fingerprint of the associated certificate.
  signed_messages : array
    CRCs of signed messages.
  sender : int
    Optional sender ID, defaults to SENDER_ID (see sbp/msg.py).

  """
  _parser = construct.Struct(
                   'stream_counter' / construct.Int8ul,
                   'on_demand_counter' / construct.Int8ul,
                   'signature' / construct.Array(64, construct.Int8ul),
                   'fingerprint' / construct.Array(20, construct.Int8ul),
                   'signed_messages' / construct.GreedyRange(construct.Int32ul),)
  __slots__ = [
               'stream_counter',
               'on_demand_counter',
               'signature',
               'fingerprint',
               'signed_messages',
              ]

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      super( MsgEd25519Signature,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.from_binary(sbp.payload)
    else:
      super( MsgEd25519Signature, self).__init__()
      self.msg_type = SBP_MSG_ED25519_SIGNATURE
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.stream_counter = kwargs.pop('stream_counter')
      self.on_demand_counter = kwargs.pop('on_demand_counter')
      self.signature = kwargs.pop('signature')
      self.fingerprint = kwargs.pop('fingerprint')
      self.signed_messages = kwargs.pop('signed_messages')

  def __repr__(self):
    return fmt_repr(self)

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    return MsgEd25519Signature.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgEd25519Signature(sbp, **d)

 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgEd25519Signature._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgEd25519Signature._parser.build(c)
    return self.pack()

  def friendly_name(self):
    """Produces friendly human-readable name for this message

    """
    return "ED25519 SIGNATURE"

  def into_buffer(self, buf, offset):
    """Produce a framed/packed SBP message into the provided buffer and offset.

    """
    self.payload = containerize(exclude_fields(self))
    self.parser = MsgEd25519Signature._parser
    self.stream_payload.reset(buf, offset)
    return self.pack_into(buf, offset, self._build_payload)

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgEd25519Signature, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    

msg_classes = {
  0x0C01: MsgEd25519SignatureDep,
  0x0C02: MsgEd25519Certificate,
  0x0C03: MsgEd25519Signature,
}