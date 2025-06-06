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
# Standardized Metadata messages for Fuzed Solution from Swift Navigation devices.
#
# Automatically generated from spec/yaml/swiftnav/sbp/solution_meta.yaml with generate.py.
# Do not modify by hand!

meta:
  id: solution_meta
  endian: le
  imports: [  ]

types:

  solution_input_type:
    doc: |
      Metadata describing which sensors were involved in the solution. The
      structure is fixed no matter what the actual sensor type is. The
      sensor_type field tells you which sensor we are talking about. It also
      tells you whether the sensor data was actually used or not. The flags
      field, always a u8, contains the sensor-specific data. The content of
      flags, for each sensor type, is described in the relevant structures in
      this section.
    seq:
      - id: sensor_type
        doc: |
          The type of sensor
        type: u1
      - id: flags
        doc: |
          Refer to each InputType description
        type: u1
  
  msg_soln_meta_dep_a:
    doc: |
      Deprecated.
    seq:
      - id: pdop
        doc: |
          Position Dilution of Precision as per last available DOPS from PVT
          engine (0xFFFF indicates invalid)
        type: u2
      - id: hdop
        doc: |
          Horizontal Dilution of Precision as per last available DOPS from PVT
          engine (0xFFFF indicates invalid)
        type: u2
      - id: vdop
        doc: |
          Vertical Dilution of Precision as per last available DOPS from PVT
          engine (0xFFFF indicates invalid)
        type: u2
      - id: n_sats
        doc: |
          Number of satellites as per last available solution from PVT engine
        type: u1
      - id: age_corrections
        doc: |
          Age of corrections as per last available AGE_CORRECTIONS from PVT
          engine (0xFFFF indicates invalid)
        type: u2
      - id: alignment_status
        doc: |
          State of alignment and the status and receipt of the alignment
          inputs
        type: u1
      - id: last_used_gnss_pos_tow
        doc: |
          Tow of last-used GNSS position measurement
        type: u4
      - id: last_used_gnss_vel_tow
        doc: |
          Tow of last-used GNSS velocity measurement
        type: u4
      - id: sol_in
        doc: |
          Array of Metadata describing the sensors potentially involved in the
          solution. Each element in the array represents a single sensor type
          and consists of flags containing (meta)data pertaining to that
          specific single sensor. Refer to each (XX)InputType descriptor in
          the present doc.
        type: solution_input_type
        repeat: eos
  
  msg_soln_meta:
    doc: |
      This message contains all metadata about the sensors received and/or
      used in computing the sensorfusion solution. It focuses primarily, but
      not only, on GNSS metadata. Regarding the age of the last received valid
      GNSS solution, the highest two bits are time status, indicating whether
      age gnss can or can not be used to retrieve time of measurement (noted
      TOM, also known as time of validity) If it can, subtract 'age gnss' from
      'tow' in navigation messages to get TOM. Can be used before alignment is
      complete in the Fusion Engine, when output solution is the last received
      valid GNSS solution and its tow is not a TOM.
    seq:
      - id: tow
        doc: |
          GPS time of week rounded to the nearest millisecond
        type: u4
      - id: pdop
        doc: |
          Position Dilution of Precision as per last available DOPS from PVT
          engine (0xFFFF indicates invalid)
        type: u2
      - id: hdop
        doc: |
          Horizontal Dilution of Precision as per last available DOPS from PVT
          engine (0xFFFF indicates invalid)
        type: u2
      - id: vdop
        doc: |
          Vertical Dilution of Precision as per last available DOPS from PVT
          engine (0xFFFF indicates invalid)
        type: u2
      - id: age_corrections
        doc: |
          Age of corrections as per last available AGE_CORRECTIONS from PVT
          engine (0xFFFF indicates invalid)
        type: u2
      - id: age_gnss
        doc: |
          Age and Time Status of the last received valid GNSS solution.
        type: u4
      - id: sol_in
        doc: |
          Array of Metadata describing the sensors potentially involved in the
          solution. Each element in the array represents a single sensor type
          and consists of flags containing (meta)data pertaining to that
          specific single sensor. Refer to each (XX)InputType descriptor in
          the present doc.
        type: solution_input_type
        repeat: eos
  
  gnss_input_type:
    doc: |
      Metadata around the GNSS sensors involved in the fuzed solution.
      Accessible through sol_in[N].flags in a MSG_SOLN_META.
    seq:
      - id: flags
        doc: |
          flags that store all relevant info specific to this sensor type.
        type: u1
  
  imu_input_type:
    doc: |
      Metadata around the IMU sensors involved in the fuzed solution.
      Accessible through sol_in[N].flags in a MSG_SOLN_META.
    seq:
      - id: flags
        doc: |
          Instrument time, grade, and architecture for a sensor.
        type: u1
  
  odo_input_type:
    doc: |
      Metadata around the Odometry sensors involved in the fuzed solution.
      Accessible through sol_in[N].flags in a MSG_SOLN_META.
    seq:
      - id: flags
        doc: |
          Instrument ODO rate, grade, and quality.
        type: u1
  
