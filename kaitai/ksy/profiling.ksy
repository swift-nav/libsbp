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
# Standardized profiling messages from Swift Navigation devices.
#
# Automatically generated from spec/yaml/swiftnav/sbp/profiling.yaml with generate.py.
# Do not modify by hand!

meta:
  id: profiling
  endian: le
  imports: [  ]

types:

  msg_measurement_point:
    doc: |
      Tracks execution time of certain code paths in specially built products.
      This message should only be expected and processed on the direction of
      Swift's engineering teams.
    seq:
      - id: total_time
        doc: |
          Total time spent in measurement point (microseconds)
        type: u4
      - id: num_executions
        doc: |
          Number of times measurement point has executed
        type: u2
      - id: min
        doc: |
          Minimum execution time (microseconds)
        type: u4
      - id: max
        doc: |
          Maximum execution time (microseconds)
        type: u4
      - id: return_addr
        doc: |
          Return address
        type: u8
      - id: id
        doc: |
          Unique ID
        type: u8
      - id: slice_time
        doc: |
          CPU slice time (milliseconds)
        type: u8
      - id: line
        doc: |
          Line number
        type: u2
      - id: func
        doc: |
          Function name
        type: str
        encoding: ascii
        size-eos: true
  