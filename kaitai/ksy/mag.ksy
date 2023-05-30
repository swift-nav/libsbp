# Magnetometer (mag) messages.

# Automatically generated from spec/yaml/swiftnav/sbp/mag.yaml with generate.py.
# Please do not hand edit!

meta:
  id: mag
  endian: le
  imports: [  ]

types:

  msg_mag_raw:
    doc: |
      Raw data from the magnetometer.
    seq:
      - id: tow
        doc: |
          Milliseconds since start of GPS week. If the high bit is set, the
          time is unknown or invalid.
        type: u4
      - id: tow_f
        doc: |
          Milliseconds since start of GPS week, fractional part
        type: u1
      - id: mag_x
        doc: |
          Magnetic field in the body frame X axis
        type: s2
      - id: mag_y
        doc: |
          Magnetic field in the body frame Y axis
        type: s2
      - id: mag_z
        doc: |
          Magnetic field in the body frame Z axis
        type: s2
  