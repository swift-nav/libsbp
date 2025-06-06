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
# SBAS data
#
# Automatically generated from spec/yaml/swiftnav/sbp/sbas.yaml with generate.py.
# Do not modify by hand!

meta:
  id: sbas
  endian: le
  imports: [ gnss ]

types:

  msg_sbas_raw:
    doc: |
      This message is sent once per second per SBAS satellite. ME checks the
      parity of the data block and sends only blocks that pass the check.
    seq:
      - id: sid
        doc: |
          GNSS signal identifier.
        type: gnss::gnss_signal
      - id: tow
        doc: |
          GPS time-of-week at the start of the data block.
        type: u4
      - id: message_type
        doc: |
          SBAS message type (0-63)
        type: u1
      - id: data
        doc: |
          Raw SBAS data field of 212 bits (last byte padded with zeros).
        type: u1
        repeat: expr
        repeat-expr: 27
  
