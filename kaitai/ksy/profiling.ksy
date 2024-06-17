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
  
  msg_profiling_system_info:
    doc: |
      Contains basic information about system resource usage. System is
      defined in terms of the source of this message and may vary from  sender
      to sender. Refer to product documentation to understand the exact scope
      and meaning of this message.
    seq:
      - id: total_cpu_time
        doc: |
          Total cpu time in microseconds consumed by this system
        type: u8
      - id: age
        doc: |
          Age of the producing system in microseconds
        type: u8
      - id: n_threads
        doc: |
          Number of threads being tracked by this system
        type: u1
      - id: heap_usage
        doc: |
          Number of bytes allocated on the heap
        type: u4
  
  msg_profiling_thread_info:
    doc: |
      Contains profiling information related to a single thread being tracked
      by the producing system. Refer to product documentation to understand
      the exact scope and meaning of this message.
    seq:
      - id: total_cpu_time
        doc: |
          Total cpu time in microseconds consumed by this thread
        type: u8
      - id: age
        doc: |
          Age of the thread in microseconds
        type: u8
      - id: state
        doc: |
          Thread state
        type: u1
      - id: stack_size
        doc: |
          Stack size in bytes
        type: u4
      - id: stack_usage
        doc: |
          Stack highwater usage in bytes
        type: u4
      - id: name
        doc: |
          Thread name
        type: str
        encoding: ascii
        size-eos: true
  
  resource_bucket:
    doc: |
      Information about allocation of various resources grouped by buckets.
      Refer to product documentation to understand the meaning and values in
      this message.
    seq:
      - id: name
        doc: |
          Bucket name
        type: str
        encoding: ascii
        size: 21
      - id: thread
        doc: |
          Number of threads
        type: u1
      - id: mutex
        doc: |
          Number of mutexes
        type: u1
      - id: cv
        doc: |
          Number of condition variables
        type: u1
      - id: io
        doc: |
          Number of IO handles
        type: u1
      - id: heap_bytes_alloc
        doc: |
          Number of bytes allocated on the heap
        type: u4
      - id: heap_bytes_free
        doc: |
          Number of bytes freed on the heap
        type: u4
      - id: io_write
        doc: |
          Number of bytes written to IO handles
        type: u4
      - id: io_read
        doc: |
          Number of bytes read from IO handles
        type: u4
  
  msg_profiling_resource_counter:
    doc: |
      Information about resource buckets. Refer to product documentation to
      understand the meaning and values in this message.
    seq:
      - id: seq_no
        doc: |
          Message number in complete sequence
        type: u1
      - id: seq_len
        doc: |
          Length of message sequence
        type: u1
      - id: buckets
        doc: |
          List of resource buckets
        type: resource_bucket
        repeat: eos
  