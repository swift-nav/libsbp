# Various structs shared between modules

# Automatically generated from spec/yaml/swiftnav/sbp/gnss.yaml with generate.py.
# Please do not hand edit!

meta:
  id: gnss
  endian: le
  imports: [  ]

types:

  gnss_signal:
    doc: |
      Signal identifier containing constellation, band, and satellite
      identifier.
    seq:
      - id: sat
        doc: |
          Constellation-specific satellite id. For GLO can either be (100+FCN)
          where FCN is in [-7,+6] or the Slot ID in [1,28].
        type: u1
      - id: code
        doc: |
          Signal constellation, band and code
        type: u1
  
  sv_id:
    doc: |
      A (Constellation ID, satellite ID) tuple that uniquely identifies a
      space vehicle.
    seq:
      - id: sat_id
        doc: |
          Constellation-specific satellite id. For GLO can either be (100+FCN)
          where FCN is in [-7,+6] or the Slot ID in [1,28].
        type: u1
      - id: constellation
        doc: |
          Constellation ID to which the SV belongs
        type: u1
  
  gnss_signal_dep:
    doc: |
      Deprecated.
    seq:
      - id: sat
        doc: |
          Constellation-specific satellite identifier.

          Note: unlike GnssSignal, GPS satellites are encoded as (PRN - 1).
          Other constellations do not have this offset.
        type: u2
      - id: code
        doc: |
          Signal constellation, band and code
        type: u1
      - id: reserved
        doc: |
          Reserved
        type: u1
  
  gps_time_dep:
    doc: |
      A wire-appropriate GPS time, defined as the number of milliseconds since
      beginning of the week on the Saturday/Sunday transition.
    seq:
      - id: tow
        doc: |
          Milliseconds since start of GPS week
        type: u4
      - id: wn
        doc: |
          GPS week number
        type: u2
  
  gps_time_sec:
    doc: |
      A GPS time, defined as the number of seconds since beginning of the week
      on the Saturday/Sunday transition.
    seq:
      - id: tow
        doc: |
          Seconds since start of GPS week
        type: u4
      - id: wn
        doc: |
          GPS week number
        type: u2
  
  gps_time:
    doc: |
      A wire-appropriate receiver clock time, defined as the time since the
      beginning of the week on the Saturday/Sunday transition. In most cases,
      observations are epoch aligned so ns field will be 0.
    seq:
      - id: tow
        doc: |
          Milliseconds since start of GPS week
        type: u4
      - id: ns_residual
        doc: |
          Nanosecond residual of millisecond-rounded TOW (ranges from -500000
          to 500000)
        type: s4
      - id: wn
        doc: |
          GPS week number
        type: u2
  
  carrier_phase:
    doc: |
      Carrier phase measurement in cycles represented as a 40-bit fixed point
      number with Q32.8 layout, i.e. 32-bits of whole cycles and 8-bits of
      fractional cycles. This phase has the same sign as the pseudorange.
    seq:
      - id: i
        doc: |
          Carrier phase whole cycles
        type: s4
      - id: f
        doc: |
          Carrier phase fractional part
        type: u1
  