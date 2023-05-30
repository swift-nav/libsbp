# Messages relating to signatures

# Automatically generated from spec/yaml/swiftnav/sbp/signing.yaml with generate.py.
# Please do not hand edit!

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
  