# Copyright (C) 2015-2023 Swift Navigation Inc.
# Contact: https://support.swiftnav.com
#
# This source is subject to the license found in the file 'LICENSE' which must
# be be distributed together with this source. All other rights reserved.
#
# THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
# EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
# WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
#
# Messages reporting accurately-timestamped external events, e.g. camera shutter
# time.
#
# Automatically generated from spec/yaml/swiftnav/sbp/ext_events.yaml with generate.py.
# Do not modify by hand!

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
  