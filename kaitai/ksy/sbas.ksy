# SBAS data

# Automatically generated from spec/yaml/swiftnav/sbp/sbas.yaml with generate.py.
# Please do not hand edit!

meta:
  id: sbas
  endian: le
  imports: [ gnss ]

types:

  msg_sbas_raw:
    doc: |
      This message is sent once per second per SBAS satellite. ME checks the
      parity of the data block and sends only blocks that pass the check.
    seq:
      - id: sid
        doc: |
          GNSS signal identifier.
        type: gnss::gnss_signal
      - id: tow
        doc: |
          GPS time-of-week at the start of the data block.
        type: u4
      - id: message_type
        doc: |
          SBAS message type (0-63)
        type: u1
      - id: data
        doc: |
          Raw SBAS data field of 212 bits (last byte padded with zeros).
        type: u1
        repeat: expr
        repeat-expr: 27
  