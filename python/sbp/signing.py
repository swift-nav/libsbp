#!/usr/bin/env python
# Copyright (C) 2015-2021 Swift Navigation Inc.
# Contact: https://support.swiftnav.com
#
# This source is subject to the license found in the file 'LICENSE' which must
# be distributed together with this source. All other rights reserved.
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


class UtcTime(object):
  """UtcTime.
  
  
  Parameters
  ----------
  year : int
    Year
  month : int
    Month (range 1 .. 12)
  day : int
    days in the month (range 1-31)
  hours : int
    hours of day (range 0-23)
  minutes : int
    minutes of hour (range 0-59)
  seconds : int
    seconds of minute (range 0-60) rounded down
  ns : int
    nanoseconds of second (range 0-999999999)

  """
  _parser = construct.Struct(
                     'year' / construct.Int16ul,
                     'month' / construct.Int8ul,
                     'day' / construct.Int8ul,
                     'hours' / construct.Int8ul,
                     'minutes' / construct.Int8ul,
                     'seconds' / construct.Int8ul,
                     'ns' / construct.Int32ul,)
  __slots__ = [
               'year',
               'month',
               'day',
               'hours',
               'minutes',
               'seconds',
               'ns',
              ]

  def __init__(self, payload=None, **kwargs):
    if payload:
      self.from_binary(payload)
    else:
      self.year = kwargs.pop('year')
      self.month = kwargs.pop('month')
      self.day = kwargs.pop('day')
      self.hours = kwargs.pop('hours')
      self.minutes = kwargs.pop('minutes')
      self.seconds = kwargs.pop('seconds')
      self.ns = kwargs.pop('ns')

  def __repr__(self):
    return fmt_repr(self)
  
  def from_binary(self, d):
    p = UtcTime._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))
    
class ECDSASignature(object):
  """ECDSASignature.
  
  
  Parameters
  ----------
  len : int
    Number of bytes to use of the signature field.  The DER encoded signature
    has a maximum size of 72 bytes but can vary between 70 and 72 bytes in
    length.
  data : array
    DER encoded ECDSA signature for the messages using SHA-256 as the digest
    algorithm.

  """
  _parser = construct.Struct(
                     'len' / construct.Int8ul,
                     'data' / construct.Array(72, construct.Int8ul),)
  __slots__ = [
               'len',
               'data',
              ]

  def __init__(self, payload=None, **kwargs):
    if payload:
      self.from_binary(payload)
    else:
      self.len = kwargs.pop('len')
      self.data = kwargs.pop('data')

  def __repr__(self):
    return fmt_repr(self)
  
  def from_binary(self, d):
    p = ECDSASignature._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))
    
SBP_MSG_ECDSA_CERTIFICATE = 0x0C04
class MsgEcdsaCertificate(SBP):
  """SBP class for message MSG_ECDSA_CERTIFICATE (0x0C04).

  You can have MSG_ECDSA_CERTIFICATE inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  A DER encoded x.509 ECDSA-256 certificate (using curve secp256r1).

  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  n_msg : int
    Total number messages that make up the certificate. The first nibble (mask
    0xF0 or left shifted by 4 bits) is the size of the sequence (n), second
    nibble (mask 0x0F) is the zero-indexed counter (ith packet of n).
  certificate_id : array
    The last 4 bytes of the certificate's SHA-1 fingerprint
  flags : int
  certificate_bytes : array
    DER encoded x.509 ECDSA certificate bytes
  sender : int
    Optional sender ID, defaults to SENDER_ID (see sbp/msg.py).

  """
  _parser = construct.Struct(
                   'n_msg' / construct.Int8ul,
                   'certificate_id' / construct.Array(4, construct.Int8ul),
                   'flags' / construct.Int8ul,
                   'certificate_bytes' / construct.GreedyRange(construct.Int8ul),)
  __slots__ = [
               'n_msg',
               'certificate_id',
               'flags',
               'certificate_bytes',
              ]

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      super( MsgEcdsaCertificate,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.from_binary(sbp.payload)
    else:
      super( MsgEcdsaCertificate, self).__init__()
      self.msg_type = SBP_MSG_ECDSA_CERTIFICATE
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.n_msg = kwargs.pop('n_msg')
      self.certificate_id = kwargs.pop('certificate_id')
      self.flags = kwargs.pop('flags')
      self.certificate_bytes = kwargs.pop('certificate_bytes')

  def __repr__(self):
    return fmt_repr(self)

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    return MsgEcdsaCertificate.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgEcdsaCertificate(sbp, **d)

 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgEcdsaCertificate._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgEcdsaCertificate._parser.build(c)
    return self.pack()

  def friendly_name(self):
    """Produces friendly human-readable name for this message

    """
    return "ECDSA CERTIFICATE"

  def into_buffer(self, buf, offset):
    """Produce a framed/packed SBP message into the provided buffer and offset.

    """
    self.payload = containerize(exclude_fields(self))
    self.parser = MsgEcdsaCertificate._parser
    self.stream_payload.reset(buf, offset)
    return self.pack_into(buf, offset, self._build_payload)

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgEcdsaCertificate, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    
SBP_MSG_CERTIFICATE_CHAIN = 0x0C09
class MsgCertificateChain(SBP):
  """SBP class for message MSG_CERTIFICATE_CHAIN (0x0C09).

  You can have MSG_CERTIFICATE_CHAIN inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  

  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  root_certificate : array
    SHA-1 fingerprint of the root certificate
  intermediate_certificate : array
    SHA-1 fingerprint of the intermediate certificate
  corrections_certificate : array
    SHA-1 fingerprint of the corrections certificate
  expiration : UtcTime
    The time after which the signature given is no longer valid. Implementors
    should consult a time source (such as GNSS) to check if the current time
    is later than the expiration time, if the condition is true, signatures in
    the stream should not be considered valid.
  signature : ECDSASignature
    Signature (created by the root certificate) over the concatenation of the
    SBP payload bytes preceding this field. That is, the concatenation of
    `root_certificate`, `intermediate_certificate`, `corrections_certificate`
    and `expiration`.  This certificate chain (allow list) can also be
    validated by fetching it from `http(s)://certs.swiftnav.com/chain`.
  sender : int
    Optional sender ID, defaults to SENDER_ID (see sbp/msg.py).

  """
  _parser = construct.Struct(
                   'root_certificate' / construct.Array(20, construct.Int8ul),
                   'intermediate_certificate' / construct.Array(20, construct.Int8ul),
                   'corrections_certificate' / construct.Array(20, construct.Int8ul),
                   'expiration' / UtcTime._parser,
                   'signature' / ECDSASignature._parser,)
  __slots__ = [
               'root_certificate',
               'intermediate_certificate',
               'corrections_certificate',
               'expiration',
               'signature',
              ]

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      super( MsgCertificateChain,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.from_binary(sbp.payload)
    else:
      super( MsgCertificateChain, self).__init__()
      self.msg_type = SBP_MSG_CERTIFICATE_CHAIN
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.root_certificate = kwargs.pop('root_certificate')
      self.intermediate_certificate = kwargs.pop('intermediate_certificate')
      self.corrections_certificate = kwargs.pop('corrections_certificate')
      self.expiration = kwargs.pop('expiration')
      self.signature = kwargs.pop('signature')

  def __repr__(self):
    return fmt_repr(self)

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    return MsgCertificateChain.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgCertificateChain(sbp, **d)

 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgCertificateChain._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgCertificateChain._parser.build(c)
    return self.pack()

  def friendly_name(self):
    """Produces friendly human-readable name for this message

    """
    return "CERTIFICATE CHAIN"

  def into_buffer(self, buf, offset):
    """Produce a framed/packed SBP message into the provided buffer and offset.

    """
    self.payload = containerize(exclude_fields(self))
    self.parser = MsgCertificateChain._parser
    self.stream_payload.reset(buf, offset)
    return self.pack_into(buf, offset, self._build_payload)

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgCertificateChain, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    
SBP_MSG_CERTIFICATE_CHAIN_DEP = 0x0C05
class MsgCertificateChainDep(SBP):
  """SBP class for message MSG_CERTIFICATE_CHAIN_DEP (0x0C05).

  You can have MSG_CERTIFICATE_CHAIN_DEP inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  Deprecated.

  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  root_certificate : array
    SHA-1 fingerprint of the root certificate
  intermediate_certificate : array
    SHA-1 fingerprint of the intermediate certificate
  corrections_certificate : array
    SHA-1 fingerprint of the corrections certificate
  expiration : UtcTime
    The certificate chain comprised of three fingerprints: root certificate,
    intermediate certificate and corrections certificate.
  signature : array
    An ECDSA signature (created by the root certificate) over the
    concatenation of the SBP payload bytes preceding this field. That is, the
    concatenation of `root_certificate`, `intermediate_certificate`,
    `corrections_certificate` and `expiration`.  This certificate chain (allow
    list) can also be validated by fetching it from
    `http(s)://certs.swiftnav.com/chain`.
  sender : int
    Optional sender ID, defaults to SENDER_ID (see sbp/msg.py).

  """
  _parser = construct.Struct(
                   'root_certificate' / construct.Array(20, construct.Int8ul),
                   'intermediate_certificate' / construct.Array(20, construct.Int8ul),
                   'corrections_certificate' / construct.Array(20, construct.Int8ul),
                   'expiration' / UtcTime._parser,
                   'signature' / construct.Array(64, construct.Int8ul),)
  __slots__ = [
               'root_certificate',
               'intermediate_certificate',
               'corrections_certificate',
               'expiration',
               'signature',
              ]

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      super( MsgCertificateChainDep,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.from_binary(sbp.payload)
    else:
      super( MsgCertificateChainDep, self).__init__()
      self.msg_type = SBP_MSG_CERTIFICATE_CHAIN_DEP
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.root_certificate = kwargs.pop('root_certificate')
      self.intermediate_certificate = kwargs.pop('intermediate_certificate')
      self.corrections_certificate = kwargs.pop('corrections_certificate')
      self.expiration = kwargs.pop('expiration')
      self.signature = kwargs.pop('signature')

  def __repr__(self):
    return fmt_repr(self)

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    return MsgCertificateChainDep.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgCertificateChainDep(sbp, **d)

 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgCertificateChainDep._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgCertificateChainDep._parser.build(c)
    return self.pack()

  def friendly_name(self):
    """Produces friendly human-readable name for this message

    """
    return "CERTIFICATE CHAIN DEP"

  def into_buffer(self, buf, offset):
    """Produce a framed/packed SBP message into the provided buffer and offset.

    """
    self.payload = containerize(exclude_fields(self))
    self.parser = MsgCertificateChainDep._parser
    self.stream_payload.reset(buf, offset)
    return self.pack_into(buf, offset, self._build_payload)

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgCertificateChainDep, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    
SBP_MSG_AES_CMAC_SIGNATURE = 0x0C10
class MsgAesCmacSignature(SBP):
  """SBP class for message MSG_AES_CMAC_SIGNATURE (0x0C10).

  You can have MSG_AES_CMAC_SIGNATURE inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  Digital signature using AES-CMAC 128 algorithm used for data integrity.

  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  stream_counter : int
    Signature message counter. Zero indexed and incremented with each
    signature message.  The counter will not increment if this message was in
    response to an on demand request.  The counter will roll over after 256
    messages. Upon connection, the value of the counter may not initially be
    zero.
  on_demand_counter : int
    On demand message counter. Zero indexed and incremented with each
    signature message sent in response to an on demand message. The counter
    will roll over after 256 messages.  Upon connection, the value of the
    counter may not initially be zero.
  certificate_id : array
    The last 4 bytes of the certificate's SHA-1 fingerprint
  signature : array
    Signature (CMAC tag value)
  flags : int
    Describes the format of the 'signed messages' field below.
  signed_messages : array
    CRCs of the messages covered by this signature.  For Skylark, which
    delivers SBP messages wrapped in Swift's proprietary RTCM message, these
    are the 24-bit CRCs from the RTCM message framing. For SBP only streams,
    this will be 16-bit CRCs from the SBP framing.  See the `flags` field to
    determine the type of CRCs covered.
  sender : int
    Optional sender ID, defaults to SENDER_ID (see sbp/msg.py).

  """
  _parser = construct.Struct(
                   'stream_counter' / construct.Int8ul,
                   'on_demand_counter' / construct.Int8ul,
                   'certificate_id' / construct.Array(4, construct.Int8ul),
                   'signature' / construct.Array(16, construct.Int8ul),
                   'flags' / construct.Int8ul,
                   'signed_messages' / construct.GreedyRange(construct.Int8ul),)
  __slots__ = [
               'stream_counter',
               'on_demand_counter',
               'certificate_id',
               'signature',
               'flags',
               'signed_messages',
              ]

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      super( MsgAesCmacSignature,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.from_binary(sbp.payload)
    else:
      super( MsgAesCmacSignature, self).__init__()
      self.msg_type = SBP_MSG_AES_CMAC_SIGNATURE
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.stream_counter = kwargs.pop('stream_counter')
      self.on_demand_counter = kwargs.pop('on_demand_counter')
      self.certificate_id = kwargs.pop('certificate_id')
      self.signature = kwargs.pop('signature')
      self.flags = kwargs.pop('flags')
      self.signed_messages = kwargs.pop('signed_messages')

  def __repr__(self):
    return fmt_repr(self)

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    return MsgAesCmacSignature.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgAesCmacSignature(sbp, **d)

 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgAesCmacSignature._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgAesCmacSignature._parser.build(c)
    return self.pack()

  def friendly_name(self):
    """Produces friendly human-readable name for this message

    """
    return "AES CMAC SIGNATURE"

  def into_buffer(self, buf, offset):
    """Produce a framed/packed SBP message into the provided buffer and offset.

    """
    self.payload = containerize(exclude_fields(self))
    self.parser = MsgAesCmacSignature._parser
    self.stream_payload.reset(buf, offset)
    return self.pack_into(buf, offset, self._build_payload)

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgAesCmacSignature, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    
SBP_MSG_ECDSA_SIGNATURE = 0x0C08
class MsgEcdsaSignature(SBP):
  """SBP class for message MSG_ECDSA_SIGNATURE (0x0C08).

  You can have MSG_ECDSA_SIGNATURE inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  An ECDSA-256 signature using SHA-256 as the message digest algorithm.

  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  flags : int
    Describes the format of the `signed\_messages` field below.
  stream_counter : int
    Signature message counter. Zero indexed and incremented with each
    signature message.  The counter will not increment if this message was in
    response to an on demand request.  The counter will roll over after 256
    messages. Upon connection, the value of the counter may not initially be
    zero.
  on_demand_counter : int
    On demand message counter. Zero indexed and incremented with each
    signature message sent in response to an on demand message. The counter
    will roll over after 256 messages.  Upon connection, the value of the
    counter may not initially be zero.
  certificate_id : array
    The last 4 bytes of the certificate's SHA-1 fingerprint
  signature : ECDSASignature
    Signature over the frames of this message group.
  signed_messages : array
    CRCs of the messages covered by this signature.  For Skylark, which
    delivers SBP messages wrapped in Swift's proprietary RTCM message, these
    are the 24-bit CRCs from the RTCM message framing. For SBP only streams,
    this will be 16-bit CRCs from the SBP framing.  See the `flags` field to
    determine the type of CRCs covered.
  sender : int
    Optional sender ID, defaults to SENDER_ID (see sbp/msg.py).

  """
  _parser = construct.Struct(
                   'flags' / construct.Int8ul,
                   'stream_counter' / construct.Int8ul,
                   'on_demand_counter' / construct.Int8ul,
                   'certificate_id' / construct.Array(4, construct.Int8ul),
                   'signature' / ECDSASignature._parser,
                   'signed_messages' / construct.GreedyRange(construct.Int8ul),)
  __slots__ = [
               'flags',
               'stream_counter',
               'on_demand_counter',
               'certificate_id',
               'signature',
               'signed_messages',
              ]

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      super( MsgEcdsaSignature,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.from_binary(sbp.payload)
    else:
      super( MsgEcdsaSignature, self).__init__()
      self.msg_type = SBP_MSG_ECDSA_SIGNATURE
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.flags = kwargs.pop('flags')
      self.stream_counter = kwargs.pop('stream_counter')
      self.on_demand_counter = kwargs.pop('on_demand_counter')
      self.certificate_id = kwargs.pop('certificate_id')
      self.signature = kwargs.pop('signature')
      self.signed_messages = kwargs.pop('signed_messages')

  def __repr__(self):
    return fmt_repr(self)

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    return MsgEcdsaSignature.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgEcdsaSignature(sbp, **d)

 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgEcdsaSignature._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgEcdsaSignature._parser.build(c)
    return self.pack()

  def friendly_name(self):
    """Produces friendly human-readable name for this message

    """
    return "ECDSA SIGNATURE"

  def into_buffer(self, buf, offset):
    """Produce a framed/packed SBP message into the provided buffer and offset.

    """
    self.payload = containerize(exclude_fields(self))
    self.parser = MsgEcdsaSignature._parser
    self.stream_payload.reset(buf, offset)
    return self.pack_into(buf, offset, self._build_payload)

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgEcdsaSignature, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    
SBP_MSG_ECDSA_SIGNATURE_DEP_B = 0x0C07
class MsgEcdsaSignatureDepB(SBP):
  """SBP class for message MSG_ECDSA_SIGNATURE_DEP_B (0x0C07).

  You can have MSG_ECDSA_SIGNATURE_DEP_B inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  Deprecated.

  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  flags : int
    Describes the format of the `signed\_messages` field below.
  stream_counter : int
    Signature message counter. Zero indexed and incremented with each
    signature message.  The counter will not increment if this message was in
    response to an on demand request.  The counter will roll over after 256
    messages. Upon connection, the value of the counter may not initially be
    zero.
  on_demand_counter : int
    On demand message counter. Zero indexed and incremented with each
    signature message sent in response to an on demand message. The counter
    will roll over after 256 messages.  Upon connection, the value of the
    counter may not initially be zero.
  certificate_id : array
    The last 4 bytes of the certificate's SHA-1 fingerprint
  n_signature_bytes : int
    Number of bytes to use of the signature field.  The DER encoded signature
    has a maximum size of 72 bytes but can vary between 70 and 72 bytes in
    length.
  signature : array
    DER encoded ECDSA signature for the messages using SHA-256 as the digest
    algorithm.
  signed_messages : array
    CRCs of the messages covered by this signature.  For Skylark, which
    delivers SBP messages wrapped in Swift's proprietary RTCM message, these
    are the 24-bit CRCs from the RTCM message framing. For SBP only streams,
    this will be 16-bit CRCs from the SBP framing.  See the `flags` field to
    determine the type of CRCs covered.
  sender : int
    Optional sender ID, defaults to SENDER_ID (see sbp/msg.py).

  """
  _parser = construct.Struct(
                   'flags' / construct.Int8ul,
                   'stream_counter' / construct.Int8ul,
                   'on_demand_counter' / construct.Int8ul,
                   'certificate_id' / construct.Array(4, construct.Int8ul),
                   'n_signature_bytes' / construct.Int8ul,
                   'signature' / construct.Array(72, construct.Int8ul),
                   'signed_messages' / construct.GreedyRange(construct.Int8ul),)
  __slots__ = [
               'flags',
               'stream_counter',
               'on_demand_counter',
               'certificate_id',
               'n_signature_bytes',
               'signature',
               'signed_messages',
              ]

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      super( MsgEcdsaSignatureDepB,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.from_binary(sbp.payload)
    else:
      super( MsgEcdsaSignatureDepB, self).__init__()
      self.msg_type = SBP_MSG_ECDSA_SIGNATURE_DEP_B
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.flags = kwargs.pop('flags')
      self.stream_counter = kwargs.pop('stream_counter')
      self.on_demand_counter = kwargs.pop('on_demand_counter')
      self.certificate_id = kwargs.pop('certificate_id')
      self.n_signature_bytes = kwargs.pop('n_signature_bytes')
      self.signature = kwargs.pop('signature')
      self.signed_messages = kwargs.pop('signed_messages')

  def __repr__(self):
    return fmt_repr(self)

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    return MsgEcdsaSignatureDepB.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgEcdsaSignatureDepB(sbp, **d)

 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgEcdsaSignatureDepB._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgEcdsaSignatureDepB._parser.build(c)
    return self.pack()

  def friendly_name(self):
    """Produces friendly human-readable name for this message

    """
    return "ECDSA SIGNATURE DEP B"

  def into_buffer(self, buf, offset):
    """Produce a framed/packed SBP message into the provided buffer and offset.

    """
    self.payload = containerize(exclude_fields(self))
    self.parser = MsgEcdsaSignatureDepB._parser
    self.stream_payload.reset(buf, offset)
    return self.pack_into(buf, offset, self._build_payload)

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgEcdsaSignatureDepB, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    
SBP_MSG_ECDSA_SIGNATURE_DEP_A = 0x0C06
class MsgEcdsaSignatureDepA(SBP):
  """SBP class for message MSG_ECDSA_SIGNATURE_DEP_A (0x0C06).

  You can have MSG_ECDSA_SIGNATURE_DEP_A inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  Deprecated.

  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  flags : int
    Describes the format of the `signed\_messages` field below.
  stream_counter : int
    Signature message counter. Zero indexed and incremented with each
    signature message.  The counter will not increment if this message was in
    response to an on demand request.  The counter will roll over after 256
    messages. Upon connection, the value of the counter may not initially be
    zero.
  on_demand_counter : int
    On demand message counter. Zero indexed and incremented with each
    signature message sent in response to an on demand message. The counter
    will roll over after 256 messages.  Upon connection, the value of the
    counter may not initially be zero.
  certificate_id : array
    The last 4 bytes of the certificate's SHA-1 fingerprint
  signature : array
    ECDSA signature for the messages using SHA-256 as the digest algorithm.
  signed_messages : array
    CRCs of the messages covered by this signature.  For Skylark, which
    delivers SBP messages wrapped in Swift's proprietary RTCM message, these
    are the 24-bit CRCs from the RTCM message framing. For SBP only streams,
    this will be 16-bit CRCs from the SBP framing.  See the `flags` field to
    determine the type of CRCs covered.
  sender : int
    Optional sender ID, defaults to SENDER_ID (see sbp/msg.py).

  """
  _parser = construct.Struct(
                   'flags' / construct.Int8ul,
                   'stream_counter' / construct.Int8ul,
                   'on_demand_counter' / construct.Int8ul,
                   'certificate_id' / construct.Array(4, construct.Int8ul),
                   'signature' / construct.Array(64, construct.Int8ul),
                   'signed_messages' / construct.GreedyRange(construct.Int8ul),)
  __slots__ = [
               'flags',
               'stream_counter',
               'on_demand_counter',
               'certificate_id',
               'signature',
               'signed_messages',
              ]

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      super( MsgEcdsaSignatureDepA,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.from_binary(sbp.payload)
    else:
      super( MsgEcdsaSignatureDepA, self).__init__()
      self.msg_type = SBP_MSG_ECDSA_SIGNATURE_DEP_A
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.flags = kwargs.pop('flags')
      self.stream_counter = kwargs.pop('stream_counter')
      self.on_demand_counter = kwargs.pop('on_demand_counter')
      self.certificate_id = kwargs.pop('certificate_id')
      self.signature = kwargs.pop('signature')
      self.signed_messages = kwargs.pop('signed_messages')

  def __repr__(self):
    return fmt_repr(self)

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    return MsgEcdsaSignatureDepA.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgEcdsaSignatureDepA(sbp, **d)

 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgEcdsaSignatureDepA._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgEcdsaSignatureDepA._parser.build(c)
    return self.pack()

  def friendly_name(self):
    """Produces friendly human-readable name for this message

    """
    return "ECDSA SIGNATURE DEP A"

  def into_buffer(self, buf, offset):
    """Produce a framed/packed SBP message into the provided buffer and offset.

    """
    self.payload = containerize(exclude_fields(self))
    self.parser = MsgEcdsaSignatureDepA._parser
    self.stream_payload.reset(buf, offset)
    return self.pack_into(buf, offset, self._build_payload)

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgEcdsaSignatureDepA, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    
SBP_MSG_ED25519_CERTIFICATE_DEP = 0x0C02
class MsgEd25519CertificateDep(SBP):
  """SBP class for message MSG_ED25519_CERTIFICATE_DEP (0x0C02).

  You can have MSG_ED25519_CERTIFICATE_DEP inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  Deprecated.

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
      super( MsgEd25519CertificateDep,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.from_binary(sbp.payload)
    else:
      super( MsgEd25519CertificateDep, self).__init__()
      self.msg_type = SBP_MSG_ED25519_CERTIFICATE_DEP
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
    return MsgEd25519CertificateDep.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgEd25519CertificateDep(sbp, **d)

 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgEd25519CertificateDep._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgEd25519CertificateDep._parser.build(c)
    return self.pack()

  def friendly_name(self):
    """Produces friendly human-readable name for this message

    """
    return "ED25519 CERTIFICATE DEP"

  def into_buffer(self, buf, offset):
    """Produce a framed/packed SBP message into the provided buffer and offset.

    """
    self.payload = containerize(exclude_fields(self))
    self.parser = MsgEd25519CertificateDep._parser
    self.stream_payload.reset(buf, offset)
    return self.pack_into(buf, offset, self._build_payload)

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgEd25519CertificateDep, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    
SBP_MSG_ED25519_SIGNATURE_DEP_A = 0x0C01
class MsgEd25519SignatureDepA(SBP):
  """SBP class for message MSG_ED25519_SIGNATURE_DEP_A (0x0C01).

  You can have MSG_ED25519_SIGNATURE_DEP_A inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  Deprecated.

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
      super( MsgEd25519SignatureDepA,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.from_binary(sbp.payload)
    else:
      super( MsgEd25519SignatureDepA, self).__init__()
      self.msg_type = SBP_MSG_ED25519_SIGNATURE_DEP_A
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
    return MsgEd25519SignatureDepA.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgEd25519SignatureDepA(sbp, **d)

 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgEd25519SignatureDepA._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgEd25519SignatureDepA._parser.build(c)
    return self.pack()

  def friendly_name(self):
    """Produces friendly human-readable name for this message

    """
    return "ED25519 SIGNATURE DEP A"

  def into_buffer(self, buf, offset):
    """Produce a framed/packed SBP message into the provided buffer and offset.

    """
    self.payload = containerize(exclude_fields(self))
    self.parser = MsgEd25519SignatureDepA._parser
    self.stream_payload.reset(buf, offset)
    return self.pack_into(buf, offset, self._build_payload)

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgEd25519SignatureDepA, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    
SBP_MSG_ED25519_SIGNATURE_DEP_B = 0x0C03
class MsgEd25519SignatureDepB(SBP):
  """SBP class for message MSG_ED25519_SIGNATURE_DEP_B (0x0C03).

  You can have MSG_ED25519_SIGNATURE_DEP_B inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  Deprecated.

  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  stream_counter : int
    Signature message counter. Zero indexed and incremented with each
    signature message.  The counter will not increment if this message was in
    response to an on demand request.  The counter will roll over after 256
    messages. Upon connection, the value of the counter may not initially be
    zero.
  on_demand_counter : int
    On demand message counter. Zero indexed and incremented with each
    signature message sent in response to an on demand message. The counter
    will roll over after 256 messages.  Upon connection, the value of the
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
      super( MsgEd25519SignatureDepB,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.from_binary(sbp.payload)
    else:
      super( MsgEd25519SignatureDepB, self).__init__()
      self.msg_type = SBP_MSG_ED25519_SIGNATURE_DEP_B
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
    return MsgEd25519SignatureDepB.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgEd25519SignatureDepB(sbp, **d)

 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgEd25519SignatureDepB._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgEd25519SignatureDepB._parser.build(c)
    return self.pack()

  def friendly_name(self):
    """Produces friendly human-readable name for this message

    """
    return "ED25519 SIGNATURE DEP B"

  def into_buffer(self, buf, offset):
    """Produce a framed/packed SBP message into the provided buffer and offset.

    """
    self.payload = containerize(exclude_fields(self))
    self.parser = MsgEd25519SignatureDepB._parser
    self.stream_payload.reset(buf, offset)
    return self.pack_into(buf, offset, self._build_payload)

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgEd25519SignatureDepB, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    

msg_classes = {
  0x0C04: MsgEcdsaCertificate,
  0x0C09: MsgCertificateChain,
  0x0C05: MsgCertificateChainDep,
  0x0C10: MsgAesCmacSignature,
  0x0C08: MsgEcdsaSignature,
  0x0C07: MsgEcdsaSignatureDepB,
  0x0C06: MsgEcdsaSignatureDepA,
  0x0C02: MsgEd25519CertificateDep,
  0x0C01: MsgEd25519SignatureDepA,
  0x0C03: MsgEd25519SignatureDepB,
}