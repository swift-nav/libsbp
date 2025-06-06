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
# Messages from a vehicle.
#
# Automatically generated from spec/yaml/swiftnav/sbp/vehicle.yaml with generate.py.
# Do not modify by hand!

meta:
  id: vehicle
  endian: le
  imports: [  ]

types:

  msg_odometry:
    doc: |
      Message representing the x component of vehicle velocity in the user
      frame at the odometry reference point(s) specified by the user. The
      offset for the odometry reference point and the definition and origin of
      the user frame are defined through the device settings interface. There
      are 4 possible user-defined sources of this message which are labeled
      arbitrarily source 0 through 3.
      If using "processor time" time tags, the receiving end will expect
      either  `MSG_GNSS_TIME_OFFSET` or `MSG_PPS_TIME` to sync incoming
      odometry data to GNSS time.  Processor time shall roll over to zero
      after one week.
    seq:
      - id: tow
        doc: |
          Time field representing either milliseconds in the GPS Week or local
          CPU time from the producing system in milliseconds.  See the
          tow_source flag for the exact source of this timestamp.
        type: u4
      - id: velocity
        doc: |
          The signed forward component of vehicle velocity.
        type: s4
      - id: flags
        doc: |
          Status flags
        type: u1
  
  msg_wheeltick:
    doc: |
      Message containing the accumulated distance travelled by a wheel located
      at an odometry reference point defined by the user. The offset for the
      odometry reference point and the definition and origin of the user frame
      are defined through the device settings interface. The source of this
      message is identified by the source field, which is an integer ranging
      from 0 to 255. The timestamp associated with this message should
      represent the time when the accumulated tick count reached the value
      given by the contents of this message as accurately as possible. If
      using "local CPU time" time tags, the receiving end will also expect
      either `MSG_GNSS_TIME_OFFSET` or `MSG_PPS_TIME` to sync incoming
      wheeltick data to GNSS time.
      Local CPU time shall roll over to zero after one week.
    seq:
      - id: time
        doc: |
          Time field representing either microseconds since the last PPS,
          microseconds in the GPS Week or local CPU time from the producing
          system in microseconds. See the synch_type field for the exact
          meaning of this timestamp.
        type: u8
      - id: flags
        doc: |
          Field indicating the type of timestamp contained in the time field.
        type: u1
      - id: source
        doc: |
          ID of the sensor producing this message
        type: u1
      - id: ticks
        doc: |
          Free-running counter of the accumulated distance for this sensor.
          The counter should be incrementing if travelling into one direction
          and decrementing when travelling in the opposite direction.
        type: s4
  
