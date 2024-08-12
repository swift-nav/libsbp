# Copyright (C) 2015-2023 Swift Navigation Inc.
# Contact: https://support.swiftnav.com
#
# This source is subject to the license found in the file 'LICENSE' which must
# be distributed together with this source. All other rights reserved.
#
# THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
# EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
# WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
#
# Messages relating to signatures
#
# Automatically generated from spec/yaml/swiftnav/sbp/signing.yaml with generate.py.
# Do not modify by hand!

meta:
  id: signing
  endian: le
  imports: [  ]

types:

  utc_time:
    seq:
      - id: year
        doc: |
          Year
        type: u2
      - id: month
        doc: |
          Month (range 1 .. 12)
        type: u1
      - id: day
        doc: |
          days in the month (range 1-31)
        type: u1
      - id: hours
        doc: |
          hours of day (range 0-23)
        type: u1
      - id: minutes
        doc: |
          minutes of hour (range 0-59)
        type: u1
      - id: seconds
        doc: |
          seconds of minute (range 0-60) rounded down
        type: u1
      - id: ns
        doc: |
          nanoseconds of second (range 0-999999999)
        type: u4
  
  ecdsa_signature:
    seq:
      - id: len
        doc: |
          Number of bytes to use of the signature field.  The DER encoded
          signature has a maximum size of 72 bytes but can vary between 70 and
          72 bytes in length.
        type: u1
      - id: data
        doc: |
          DER encoded ECDSA signature for the messages using SHA-256 as the
          digest algorithm.
        type: u1
        repeat: expr
        repeat-expr: 72
  
  msg_ecdsa_certificate:
    doc: |
      A DER encoded x.509 ECDSA-256 certificate (using curve secp256r1).
    seq:
      - id: n_msg
        doc: |
          Total number messages that make up the certificate. The first nibble
          (mask 0xF0 or left shifted by 4 bits) is the size of the sequence
          (n), second nibble (mask 0x0F) is the zero-indexed counter (ith
          packet of n).
        type: u1
      - id: certificate_id
        doc: |
          The last 4 bytes of the certificate's SHA-1 fingerprint
        type: u1
        repeat: expr
        repeat-expr: 4
      - id: flags
        type: u1
      - id: certificate_bytes
        doc: |
          DER encoded x.509 ECDSA certificate bytes
        type: u1
        repeat: eos
  
  msg_certificate_chain:
    seq:
      - id: root_certificate
        doc: |
          SHA-1 fingerprint of the root certificate
        type: u1
        repeat: expr
        repeat-expr: 20
      - id: intermediate_certificate
        doc: |
          SHA-1 fingerprint of the intermediate certificate
        type: u1
        repeat: expr
        repeat-expr: 20
      - id: corrections_certificate
        doc: |
          SHA-1 fingerprint of the corrections certificate
        type: u1
        repeat: expr
        repeat-expr: 20
      - id: expiration
        doc: |
          The time after which the signature given is no longer valid.
          Implementors should consult a time source (such as GNSS) to check if
          the current time is later than the expiration time, if the condition
          is true, signatures in the stream should not be considered valid.
        type: utc_time
      - id: signature
        doc: |
          Signature (created by the root certificate) over the concatenation
          of the SBP payload bytes preceding this field. That is, the
          concatenation of `root_certificate`, `intermediate_certificate`,
          `corrections_certificate` and `expiration`.  This certificate chain
          (allow list) can also be validated by fetching it from
          `http(s)://certs.swiftnav.com/chain`.
        type: ecdsa_signature
  
  msg_certificate_chain_dep:
    doc: |
      Deprecated.
    seq:
      - id: root_certificate
        doc: |
          SHA-1 fingerprint of the root certificate
        type: u1
        repeat: expr
        repeat-expr: 20
      - id: intermediate_certificate
        doc: |
          SHA-1 fingerprint of the intermediate certificate
        type: u1
        repeat: expr
        repeat-expr: 20
      - id: corrections_certificate
        doc: |
          SHA-1 fingerprint of the corrections certificate
        type: u1
        repeat: expr
        repeat-expr: 20
      - id: expiration
        doc: |
          The certificate chain comprised of three fingerprints: root
          certificate, intermediate certificate and corrections certificate.
        type: utc_time
      - id: signature
        doc: |
          An ECDSA signature (created by the root certificate) over the
          concatenation of the SBP payload bytes preceding this field. That
          is, the concatenation of `root_certificate`,
          `intermediate_certificate`, `corrections_certificate` and
          `expiration`.  This certificate chain (allow list) can also be
          validated by fetching it from `http(s)://certs.swiftnav.com/chain`.
        type: u1
        repeat: expr
        repeat-expr: 64
  
  msg_ecdsa_signature:
    doc: |
      An ECDSA-256 signature using SHA-256 as the message digest algorithm.
    seq:
      - id: flags
        doc: |
          Describes the format of the `signed\_messages` field below.
        type: u1
      - id: stream_counter
        doc: |
          Signature message counter. Zero indexed and incremented with each
          signature message.  The counter will not increment if this message
          was in response to an on demand request.  The counter will roll over
          after 256 messages. Upon connection, the value of the counter may
          not initially be zero.
        type: u1
      - id: on_demand_counter
        doc: |
          On demand message counter. Zero indexed and incremented with each
          signature message sent in response to an on demand message. The
          counter will roll over after 256 messages.  Upon connection, the
          value of the counter may not initially be zero.
        type: u1
      - id: certificate_id
        doc: |
          The last 4 bytes of the certificate's SHA-1 fingerprint
        type: u1
        repeat: expr
        repeat-expr: 4
      - id: signature
        doc: |
          Signature over the frames of this message group.
        type: ecdsa_signature
      - id: signed_messages
        doc: |
          CRCs of the messages covered by this signature.  For Skylark, which
          delivers SBP messages wrapped in Swift's proprietary RTCM message,
          these are the 24-bit CRCs from the RTCM message framing. For SBP
          only streams, this will be 16-bit CRCs from the SBP framing.  See
          the `flags` field to determine the type of CRCs covered.
        type: u1
        repeat: eos
  
  msg_ecdsa_signature_dep_b:
    doc: |
      Deprecated.
    seq:
      - id: flags
        doc: |
          Describes the format of the `signed\_messages` field below.
        type: u1
      - id: stream_counter
        doc: |
          Signature message counter. Zero indexed and incremented with each
          signature message.  The counter will not increment if this message
          was in response to an on demand request.  The counter will roll over
          after 256 messages. Upon connection, the value of the counter may
          not initially be zero.
        type: u1
      - id: on_demand_counter
        doc: |
          On demand message counter. Zero indexed and incremented with each
          signature message sent in response to an on demand message. The
          counter will roll over after 256 messages.  Upon connection, the
          value of the counter may not initially be zero.
        type: u1
      - id: certificate_id
        doc: |
          The last 4 bytes of the certificate's SHA-1 fingerprint
        type: u1
        repeat: expr
        repeat-expr: 4
      - id: n_signature_bytes
        doc: |
          Number of bytes to use of the signature field.  The DER encoded
          signature has a maximum size of 72 bytes but can vary between 70 and
          72 bytes in length.
        type: u1
      - id: signature
        doc: |
          DER encoded ECDSA signature for the messages using SHA-256 as the
          digest algorithm.
        type: u1
        repeat: expr
        repeat-expr: 72
      - id: signed_messages
        doc: |
          CRCs of the messages covered by this signature.  For Skylark, which
          delivers SBP messages wrapped in Swift's proprietary RTCM message,
          these are the 24-bit CRCs from the RTCM message framing. For SBP
          only streams, this will be 16-bit CRCs from the SBP framing.  See
          the `flags` field to determine the type of CRCs covered.
        type: u1
        repeat: eos
  
  msg_ecdsa_signature_dep_a:
    doc: |
      Deprecated.
    seq:
      - id: flags
        doc: |
          Describes the format of the `signed\_messages` field below.
        type: u1
      - id: stream_counter
        doc: |
          Signature message counter. Zero indexed and incremented with each
          signature message.  The counter will not increment if this message
          was in response to an on demand request.  The counter will roll over
          after 256 messages. Upon connection, the value of the counter may
          not initially be zero.
        type: u1
      - id: on_demand_counter
        doc: |
          On demand message counter. Zero indexed and incremented with each
          signature message sent in response to an on demand message. The
          counter will roll over after 256 messages.  Upon connection, the
          value of the counter may not initially be zero.
        type: u1
      - id: certificate_id
        doc: |
          The last 4 bytes of the certificate's SHA-1 fingerprint
        type: u1
        repeat: expr
        repeat-expr: 4
      - id: signature
        doc: |
          ECDSA signature for the messages using SHA-256 as the digest
          algorithm.
        type: u1
        repeat: expr
        repeat-expr: 64
      - id: signed_messages
        doc: |
          CRCs of the messages covered by this signature.  For Skylark, which
          delivers SBP messages wrapped in Swift's proprietary RTCM message,
          these are the 24-bit CRCs from the RTCM message framing. For SBP
          only streams, this will be 16-bit CRCs from the SBP framing.  See
          the `flags` field to determine the type of CRCs covered.
        type: u1
        repeat: eos
  
  msg_ed25519_certificate_dep:
    doc: |
      Deprecated.
    seq:
      - id: n_msg
        doc: |
          Total number messages that make up the certificate. First nibble is
          the size of the sequence (n), second nibble is the zero-indexed
          counter (ith packet of n)
        type: u1
      - id: fingerprint
        doc: |
          SHA-1 fingerprint of the associated certificate.
        type: u1
        repeat: expr
        repeat-expr: 20
      - id: certificate_bytes
        doc: |
          ED25519 certificate bytes.
        type: u1
        repeat: eos
  
  msg_ed25519_signature_dep_a:
    doc: |
      Deprecated.
    seq:
      - id: signature
        doc: |
          ED25519 signature for messages.
        type: u1
        repeat: expr
        repeat-expr: 64
      - id: fingerprint
        doc: |
          SHA-1 fingerprint of the associated certificate.
        type: u1
        repeat: expr
        repeat-expr: 20
      - id: signed_messages
        doc: |
          CRCs of signed messages.
        type: u4
        repeat: eos
  
  msg_ed25519_signature_dep_b:
    doc: |
      Deprecated.
    seq:
      - id: stream_counter
        doc: |
          Signature message counter. Zero indexed and incremented with each
          signature message.  The counter will not increment if this message
          was in response to an on demand request.  The counter will roll over
          after 256 messages. Upon connection, the value of the counter may
          not initially be zero.
        type: u1
      - id: on_demand_counter
        doc: |
          On demand message counter. Zero indexed and incremented with each
          signature message sent in response to an on demand message. The
          counter will roll over after 256 messages.  Upon connection, the
          value of the counter may not initially be zero.
        type: u1
      - id: signature
        doc: |
          ED25519 signature for messages.
        type: u1
        repeat: expr
        repeat-expr: 64
      - id: fingerprint
        doc: |
          SHA-1 fingerprint of the associated certificate.
        type: u1
        repeat: expr
        repeat-expr: 20
      - id: signed_messages
        doc: |
          CRCs of signed messages.
        type: u4
        repeat: eos
  