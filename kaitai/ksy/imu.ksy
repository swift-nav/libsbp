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
      MSG_IMU_AUX message. If using "time since startup" local time tags, the
      receiving end will expect a `MSG_PPS_TIME` regardless of GNSS fix state.
      This also requires that the MSG_PPS_TIME message be sent prior to any
      IMU RAW messages that are based on the current (as measured at the PPS
      edge) local time timestamps. The local time (as defined in the
      MSG_PPS_TIME message) must wrap around to zero when reaching the extent
      of the u64 "Local time in microseconds" parameter.
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
  