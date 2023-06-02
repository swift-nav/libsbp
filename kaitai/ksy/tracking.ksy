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
# Satellite code and carrier-phase tracking messages from the device.
#
# Automatically generated from spec/yaml/swiftnav/sbp/tracking.yaml with generate.py.
# Do not modify by hand!

meta:
  id: tracking
  endian: le
  imports: [ gnss ]

types:

  msg_tracking_state_detailed_dep_a:
    doc: |
      The tracking message returns a set tracking channel parameters for a
      single tracking channel useful for debugging issues.
    seq:
      - id: recv_time
        doc: |
          Receiver clock time.
        type: u8
      - id: tot
        doc: |
          Time of transmission of signal from satellite. TOW only valid when
          TOW status is decoded or propagated. WN only valid when week number
          valid flag is set.
        type: gnss::gps_time
      - id: p
        doc: |
          Pseudorange observation. Valid only when pseudorange valid flag is
          set.
        type: u4
      - id: p_std
        doc: |
          Pseudorange observation standard deviation. Valid only when
          pseudorange valid flag is set.
        type: u2
      - id: l
        doc: |
          Carrier phase observation with typical sign convention. Valid only
          when PLL pessimistic lock is achieved.
        type: gnss::carrier_phase
      - id: cn0
        doc: |
          Carrier-to-Noise density
        type: u1
      - id: lock
        doc: |
          Lock time. It is encoded according to DF402 from the RTCM 10403.2
          Amendment 2 specification. Valid values range from 0 to 15.
        type: u2
      - id: sid
        doc: |
          GNSS signal identifier.
        type: gnss::gnss_signal
      - id: doppler
        doc: |
          Carrier Doppler frequency.
        type: s4
      - id: doppler_std
        doc: |
          Carrier Doppler frequency standard deviation.
        type: u2
      - id: uptime
        doc: |
          Number of seconds of continuous tracking. Specifies how much time
          signal is in continuous track.
        type: u4
      - id: clock_offset
        doc: |
          TCXO clock offset. Valid only when valid clock valid flag is set.
        type: s2
      - id: clock_drift
        doc: |
          TCXO clock drift. Valid only when valid clock valid flag is set.
        type: s2
      - id: corr_spacing
        doc: |
          Early-Prompt (EP) and Prompt-Late (PL) correlators spacing.
        type: u2
      - id: acceleration
        doc: |
          Acceleration. Valid only when acceleration valid flag is set.
        type: s1
      - id: sync_flags
        doc: |
          Synchronization status flags.
        type: u1
      - id: tow_flags
        doc: |
          TOW status flags.
        type: u1
      - id: track_flags
        doc: |
          Tracking loop status flags.
        type: u1
      - id: nav_flags
        doc: |
          Navigation data status flags.
        type: u1
      - id: pset_flags
        doc: |
          Parameters sets flags.
        type: u1
      - id: misc_flags
        doc: |
          Miscellaneous flags.
        type: u1
  
  msg_tracking_state_detailed_dep:
    doc: |
      Deprecated.
    seq:
      - id: recv_time
        doc: |
          Receiver clock time.
        type: u8
      - id: tot
        doc: |
          Time of transmission of signal from satellite. TOW only valid when
          TOW status is decoded or propagated. WN only valid when week number
          valid flag is set.
        type: gnss::gps_time_dep
      - id: p
        doc: |
          Pseudorange observation. Valid only when pseudorange valid flag is
          set.
        type: u4
      - id: p_std
        doc: |
          Pseudorange observation standard deviation. Valid only when
          pseudorange valid flag is set.
        type: u2
      - id: l
        doc: |
          Carrier phase observation with typical sign convention. Valid only
          when PLL pessimistic lock is achieved.
        type: gnss::carrier_phase
      - id: cn0
        doc: |
          Carrier-to-Noise density
        type: u1
      - id: lock
        doc: |
          Lock time. It is encoded according to DF402 from the RTCM 10403.2
          Amendment 2 specification. Valid values range from 0 to 15.
        type: u2
      - id: sid
        doc: |
          GNSS signal identifier.
        type: gnss::gnss_signal_dep
      - id: doppler
        doc: |
          Carrier Doppler frequency.
        type: s4
      - id: doppler_std
        doc: |
          Carrier Doppler frequency standard deviation.
        type: u2
      - id: uptime
        doc: |
          Number of seconds of continuous tracking. Specifies how much time
          signal is in continuous track.
        type: u4
      - id: clock_offset
        doc: |
          TCXO clock offset. Valid only when valid clock valid flag is set.
        type: s2
      - id: clock_drift
        doc: |
          TCXO clock drift. Valid only when valid clock valid flag is set.
        type: s2
      - id: corr_spacing
        doc: |
          Early-Prompt (EP) and Prompt-Late (PL) correlators spacing.
        type: u2
      - id: acceleration
        doc: |
          Acceleration. Valid only when acceleration valid flag is set.
        type: s1
      - id: sync_flags
        doc: |
          Synchronization status flags.
        type: u1
      - id: tow_flags
        doc: |
          TOW status flags.
        type: u1
      - id: track_flags
        doc: |
          Tracking loop status flags.
        type: u1
      - id: nav_flags
        doc: |
          Navigation data status flags.
        type: u1
      - id: pset_flags
        doc: |
          Parameters sets flags.
        type: u1
      - id: misc_flags
        doc: |
          Miscellaneous flags.
        type: u1
  
  tracking_channel_state:
    doc: |
      Tracking channel state for a specific satellite signal and measured
      signal power.
    seq:
      - id: sid
        doc: |
          GNSS signal being tracked
        type: gnss::gnss_signal
      - id: fcn
        doc: |
          Frequency channel number (GLONASS only)
        type: u1
      - id: cn0
        doc: |
          Carrier-to-Noise density.  Zero implies invalid cn0.
        type: u1
  
  msg_tracking_state:
    doc: |
      The tracking message returns a variable-length array of tracking channel
      states. It reports status and carrier-to-noise density measurements for
      all tracked satellites.
    seq:
      - id: states
        doc: |
          Signal tracking channel state
        type: tracking_channel_state
        repeat: eos
  
  measurement_state:
    doc: |
      Measurement Engine tracking channel state for a specific satellite
      signal and measured signal power. The mesid field for Glonass can either
      carry the FCN as 100 + FCN where FCN is in [-7, +6] or the Slot ID (from
      1 to 28).
    seq:
      - id: mesid
        doc: |
          Measurement Engine GNSS signal being tracked (carries either Glonass
          FCN or SLOT)
        type: gnss::gnss_signal
      - id: cn0
        doc: |
          Carrier-to-Noise density.  Zero implies invalid cn0.
        type: u1
  
  msg_measurement_state:
    doc: |
      The tracking message returns a variable-length array of tracking channel
      states. It reports status and carrier-to-noise density measurements for
      all tracked satellites.
    seq:
      - id: states
        doc: |
          ME signal tracking channel state
        type: measurement_state
        repeat: eos
  
  tracking_channel_correlation:
    doc: |
      Structure containing in-phase and quadrature correlation components.
    seq:
      - id: i
        doc: |
          In-phase correlation
        type: s2
      - id: q
        doc: |
          Quadrature correlation
        type: s2
  
  msg_tracking_iq:
    doc: |
      When enabled, a tracking channel can output the correlations at each
      update interval.
    seq:
      - id: channel
        doc: |
          Tracking channel of origin
        type: u1
      - id: sid
        doc: |
          GNSS signal identifier
        type: gnss::gnss_signal
      - id: corrs
        doc: |
          Early, Prompt and Late correlations
        type: u8
        repeat: expr
        repeat-expr: 3
  
  tracking_channel_correlation_dep:
    doc: |
      Structure containing in-phase and quadrature correlation components.
    seq:
      - id: i
        doc: |
          In-phase correlation
        type: s4
      - id: q
        doc: |
          Quadrature correlation
        type: s4
  
  msg_tracking_iq_dep_b:
    doc: |
      Deprecated.
    seq:
      - id: channel
        doc: |
          Tracking channel of origin
        type: u1
      - id: sid
        doc: |
          GNSS signal identifier
        type: gnss::gnss_signal
      - id: corrs
        doc: |
          Early, Prompt and Late correlations
        type: u8
        repeat: expr
        repeat-expr: 3
  
  msg_tracking_iq_dep_a:
    doc: |
      Deprecated.
    seq:
      - id: channel
        doc: |
          Tracking channel of origin
        type: u1
      - id: sid
        doc: |
          GNSS signal identifier
        type: gnss::gnss_signal_dep
      - id: corrs
        doc: |
          Early, Prompt and Late correlations
        type: u8
        repeat: expr
        repeat-expr: 3
  
  tracking_channel_state_dep_a:
    doc: |
      Deprecated.
    seq:
      - id: state
        doc: |
          Status of tracking channel
        type: u1
      - id: prn
        doc: |
          PRN-1 being tracked
        type: u1
      - id: cn0
        doc: |
          Carrier-to-noise density
        type: f4
  
  msg_tracking_state_dep_a:
    doc: |
      Deprecated.
    seq:
      - id: states
        doc: |
          Satellite tracking channel state
        type: tracking_channel_state_dep_a
        repeat: eos
  
  tracking_channel_state_dep_b:
    doc: |
      Deprecated.
    seq:
      - id: state
        doc: |
          Status of tracking channel
        type: u1
      - id: sid
        doc: |
          GNSS signal being tracked
        type: gnss::gnss_signal_dep
      - id: cn0
        doc: |
          Carrier-to-noise density
        type: f4
  
  msg_tracking_state_dep_b:
    doc: |
      Deprecated.
    seq:
      - id: states
        doc: |
          Signal tracking channel state
        type: tracking_channel_state_dep_b
        repeat: eos
  