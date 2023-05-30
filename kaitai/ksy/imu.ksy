# Inertial Measurement Unit (IMU) messages.

# Automatically generated from spec/yaml/swiftnav/sbp/imu.yaml with generate.py.
# Please do not hand edit!

meta:
  id: imu
  endian: le
  imports: [  ]

types:

  msg_imu_raw:
    doc: |
      Raw data from the Inertial Measurement Unit, containing accelerometer
      and gyroscope readings. The sense of the measurements are to be aligned
      with the indications on the device itself. Measurement units, which are
      specific to the device hardware and settings, are communicated via the
      MSG_IMU_AUX message. If using "time since startup" time tags, the
      receiving end will expect a `MSG_GNSS_TIME_OFFSET` when a PVT fix
      becomes available to synchronise IMU measurements with GNSS. The
      timestamp must wrap around to zero when reaching one week (604800
      seconds).

      The time-tagging mode should not change throughout a run.
    seq:
      - id: tow
        doc: |
          Milliseconds since reference epoch and time status.
        type: u4
      - id: tow_f
        doc: |
          Milliseconds since reference epoch, fractional part
        type: u1
      - id: acc_x
        doc: |
          Acceleration in the IMU frame X axis
        type: s2
      - id: acc_y
        doc: |
          Acceleration in the IMU frame Y axis
        type: s2
      - id: acc_z
        doc: |
          Acceleration in the IMU frame Z axis
        type: s2
      - id: gyr_x
        doc: |
          Angular rate around IMU frame X axis
        type: s2
      - id: gyr_y
        doc: |
          Angular rate around IMU frame Y axis
        type: s2
      - id: gyr_z
        doc: |
          Angular rate around IMU frame Z axis
        type: s2
  
  msg_imu_aux:
    doc: |
      Auxiliary data specific to a particular IMU. The `imu_type` field will
      always be consistent but the rest of the payload is device specific and
      depends on the value of `imu_type`.
    seq:
      - id: imu_type
        doc: |
          IMU type
        type: u1
      - id: temp
        doc: |
          Raw IMU temperature
        type: s2
      - id: imu_conf
        doc: |
          IMU configuration
        type: u1
  