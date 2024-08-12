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
# Logging and debugging messages from the device.
#
# Automatically generated from spec/yaml/swiftnav/sbp/logging.yaml with generate.py.
# Do not modify by hand!

meta:
  id: logging
  endian: le
  imports: [  ]

types:

  msg_log:
    doc: |
      This message contains a human-readable payload string from the device
      containing errors, warnings and informational messages at ERROR,
      WARNING, DEBUG, INFO logging levels.
    seq:
      - id: level
        doc: |
          Logging level
        type: u1
      - id: text
        doc: |
          Human-readable string
        type: str
        encoding: ascii
        size-eos: true
  
  msg_fwd:
    doc: |
      This message provides the ability to forward messages over SBP.  This
      may take the form of wrapping up SBP messages received by Piksi for
      logging purposes or wrapping another protocol with SBP.

      The source identifier indicates from what interface a forwarded stream
      derived. The protocol identifier identifies what the expected protocol
      the forwarded msg contains. Protocol 0 represents SBP and the remaining
      values are implementation defined.
    seq:
      - id: source
        doc: |
          source identifier
        type: u1
      - id: protocol
        doc: |
          protocol identifier
        type: u1
      - id: fwd_payload
        doc: |
          variable length wrapped binary message
        type: u1
        repeat: eos
  
  msg_print_dep:
    doc: |
      Deprecated.
    seq:
      - id: text
        doc: |
          Human-readable string
        type: str
        encoding: ascii
        size-eos: true
  