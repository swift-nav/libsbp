# Messages reporting accurately-timestamped external events, e.g. camera shutter
# time.

# Automatically generated from spec/yaml/swiftnav/sbp/ext_events.yaml with generate.py.
# Please do not hand edit!

meta:
  id: ext_events
  endian: le
  imports: [  ]

types:

  msg_ext_event:
    doc: |
      Reports detection of an external event, the GPS time it occurred, which
      pin it was and whether it was rising or falling.
    seq:
      - id: wn
        doc: |
          GPS week number
        type: u2
      - id: tow
        doc: |
          GPS time of week rounded to the nearest millisecond
        type: u4
      - id: ns_residual
        doc: |
          Nanosecond residual of millisecond-rounded TOW (ranges from -500000
          to 500000)
        type: s4
      - id: flags
        doc: |
          Flags
        type: u1
      - id: pin
        doc: |
          Pin number.  0..9 = DEBUG0..9.
        type: u1
  