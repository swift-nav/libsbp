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
# Messages for logging NDB events.
#
# Automatically generated from spec/yaml/swiftnav/sbp/ndb.yaml with generate.py.
# Do not modify by hand!

meta:
  id: ndb
  endian: le
  imports: [ gnss ]

types:

  msg_ndb_event:
    doc: |
      This message is sent out when an object is stored into NDB. If needed
      message could also be sent out when fetching an object from NDB.
    seq:
      - id: recv_time
        doc: |
          HW time in milliseconds.
        type: u8
      - id: event
        doc: |
          Event type.
        type: u1
      - id: object_type
        doc: |
          Event object type.
        type: u1
      - id: result
        doc: |
          Event result.
        type: u1
      - id: data_source
        doc: |
          Data source for STORE event, reserved for other events.
        type: u1
      - id: object_sid
        doc: |
          GNSS signal identifier, If object_type is Ephemeris OR Almanac, sid
          indicates for which signal the object belongs to. Reserved in other
          cases.
        type: gnss::gnss_signal
      - id: src_sid
        doc: |
          GNSS signal identifier, If object_type is Almanac, Almanac WN, Iono
          OR L2C capabilities AND data_source is NDB_DS_RECEIVER sid indicates
          from which SV data was decoded. Reserved in other cases.
        type: gnss::gnss_signal
      - id: original_sender
        doc: |
          A unique identifier of the sending hardware. For v1.0, set to the 2
          least significant bytes of the device serial number, valid only if
          data_source is NDB_DS_SBP. Reserved in case of other data_source.
        type: u2
  