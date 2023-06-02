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
# Telemetry messages reported by Starling engine. The messages include various
# byproducts of state estimation and other logic across Starling and are aimed at
# efficient issue diagnostics.
#
# Automatically generated from spec/yaml/swiftnav/sbp/telemetry.yaml with generate.py.
# Do not modify by hand!

meta:
  id: telemetry
  endian: le
  imports: [ gnss ]

types:

  telemetry_sv:
    seq:
      - id: az
        doc: |
          Azimuth angle (range 0..179)
        type: u1
      - id: el
        doc: |
          Elevation angle (range -90..90)
        type: s1
      - id: availability_flags
        doc: |
          Observation availability at filter update
        type: u1
      - id: pseudorange_residual
        doc: |
          Pseudorange observation residual
        type: s2
      - id: phase_residual
        doc: |
          Carrier-phase or carrier-phase-derived observation residual
        type: s2
      - id: outlier_flags
        doc: |
          Reports if observation is marked as an outlier and is excluded from
          the update
        type: u1
      - id: ephemeris_flags
        doc: |
          Ephemeris metadata
        type: u1
      - id: correction_flags
        doc: |
          Reserved
        type: u1
      - id: sid
        doc: |
          GNSS signal identifier (16 bit)
        type: gnss::gnss_signal
  
  msg_tel_sv:
    doc: |
      This message includes telemetry pertinent to satellite signals available
      to Starling.
    seq:
      - id: wn
        doc: |
          GPS week number
        type: u2
      - id: tow
        doc: |
          GPS Time of Week
        type: u4
      - id: n_obs
        doc: |
          Total number of observations. First nibble is the size of the
          sequence (n), second nibble is the zero-indexed counter (ith packet
          of n)
        type: u1
      - id: origin_flags
        doc: |
          Flags to identify the filter type from which the telemetry is
          reported from
        type: u1
      - id: sv_tel
        doc: |
          Array of per-signal telemetry entries
        type: telemetry_sv
        repeat: eos
  