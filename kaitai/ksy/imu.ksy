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
# Inertial Measurement Unit (IMU) messages.
#
# Automatically generated from spec/yaml/swiftnav/sbp/imu.yaml with generate.py.
# Do not modify by hand!

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
      receiving end will expect either a MSG_GNSS_TIME_OFFSET or MSG_PPS_TIME
      to establish the relationship between IMU time and GNSS time.
      Regardless of the timestamping mode, the timestamp is required to roll
      over to zero when reaching one week (604800 seconds, or 604800000
      milliseconds).
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
  
  msg_imu_comp:
    doc: |
      Data from the Inertial Measurement Unit, containing accelerometer and
      gyroscope readings compensated for estimated errors and constant
      physical effects. The output is valid for inertially referenced center
      of navigation (IMU body frame) represented in vehicle body frame.
    seq:
      - id: time
        doc: |
          Microseconds since reference epoch
        type: u8
      - id: flags
        doc: |
          Contains the applied compensation parameters and time
          synchronization mode
        type: u2
      - id: acc_comp_x
        doc: |
          Compensated acceleration X axis
        type: s4
      - id: acc_comp_y
        doc: |
          Compensated acceleration Y axis
        type: s4
      - id: acc_comp_z
        doc: |
          Compensated acceleration Z axis
        type: s4
      - id: gyr_comp_x
        doc: |
          Compensated angular rate X axis
        type: s4
      - id: gyr_comp_y
        doc: |
          Compensated angular rate Y axis
        type: s4
      - id: gyr_comp_z
        doc: |
          Compensated angular rate Z axis
        type: s4
  