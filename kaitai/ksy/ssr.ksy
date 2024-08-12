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
# Precise State Space Representation (SSR) corrections format
#
# Automatically generated from spec/yaml/swiftnav/sbp/ssr.yaml with generate.py.
# Do not modify by hand!

meta:
  id: ssr
  endian: le
  imports: [ gnss ]

types:

  code_biases_content:
    doc: |
      Code biases are to be added to pseudorange. The corrections conform with
      RTCMv3 MT 1059 / 1065.
    seq:
      - id: code
        doc: |
          Signal encoded following RTCM specifications (DF380, DF381, DF382
          and DF467).
        type: u1
      - id: value
        doc: |
          Code bias value
        type: s2
  
  phase_biases_content:
    doc: |
      Phase biases are to be added to carrier phase measurements.
    seq:
      - id: code
        doc: |
          Signal encoded following RTCM specifications (DF380, DF381, DF382
          and DF467)
        type: u1
      - id: integer_indicator
        doc: |
          Indicator for integer property
        type: u1
      - id: widelane_integer_indicator
        doc: |
          Indicator for two groups of Wide-Lane(s) integer property
        type: u1
      - id: discontinuity_counter
        doc: |
          Signal phase discontinuity counter. Increased for every
          discontinuity in phase.
        type: u1
      - id: bias
        doc: |
          Phase bias for specified signal
        type: s4
  
  stec_header:
    doc: |
      A full set of STEC information will likely span multiple SBP messages,
      since SBP message a limited to 255 bytes.  The header is used to tie
      multiple SBP messages into a sequence.
    seq:
      - id: tile_set_id
        doc: |
          Unique identifier of the tile set this tile belongs to.
        type: u2
      - id: tile_id
        doc: |
          Unique identifier of this tile in the tile set.
        type: u2
      - id: time
        doc: |
          GNSS reference time of the correction
        type: gnss::gps_time_sec
      - id: num_msgs
        doc: |
          Number of messages in the dataset
        type: u1
      - id: seq_num
        doc: |
          Position of this message in the dataset
        type: u1
      - id: update_interval
        doc: |
          Update interval between consecutive corrections. Encoded following
          RTCM DF391 specification.
        type: u1
      - id: iod_atmo
        doc: |
          IOD of the SSR atmospheric correction
        type: u1
  
  gridded_correction_header:
    doc: |
      The LPP message contains nested variable length arrays which are not
      supported in SBP, so each grid point will be identified by the index.
    seq:
      - id: tile_set_id
        doc: |
          Unique identifier of the tile set this tile belongs to.
        type: u2
      - id: tile_id
        doc: |
          Unique identifier of this tile in the tile set.
        type: u2
      - id: time
        doc: |
          GNSS reference time of the correction
        type: gnss::gps_time_sec
      - id: num_msgs
        doc: |
          Number of messages in the dataset
        type: u2
      - id: seq_num
        doc: |
          Position of this message in the dataset
        type: u2
      - id: update_interval
        doc: |
          Update interval between consecutive corrections. Encoded following
          RTCM DF391 specification.
        type: u1
      - id: iod_atmo
        doc: |
          IOD of the SSR atmospheric correction
        type: u1
      - id: tropo_quality_indicator
        doc: |
          Quality of the troposphere data. Encoded following RTCM DF389
          specification in units of m.
        type: u1
  
  stec_sat_element:
    doc: |
      STEC polynomial for the given satellite.
    seq:
      - id: sv_id
        doc: |
          Unique space vehicle identifier
        type: gnss::sv_id
      - id: stec_quality_indicator
        doc: |
          Quality of the STEC data. Encoded following RTCM DF389 specification
          but in units of TECU instead of m.
        type: u1
      - id: stec_coeff
        doc: |
          Coefficients of the STEC polynomial in the order of C00, C01, C10,
          C11. C00 = 0.05 TECU, C01/C10 = 0.02 TECU/deg, C11 0.02 TECU/deg^2
        type: s2
        repeat: expr
        repeat-expr: 4
  
  tropospheric_delay_correction_no_std:
    doc: |
      Troposphere vertical delays at the grid point.
    seq:
      - id: hydro
        doc: |
          Hydrostatic vertical delay
        type: s2
      - id: wet
        doc: |
          Wet vertical delay
        type: s1
  
  tropospheric_delay_correction:
    doc: |
      Troposphere vertical delays (mean and standard deviation) at the grid
      point.
    seq:
      - id: hydro
        doc: |
          Hydrostatic vertical delay. Add 2.3 m to get actual value.
        type: s2
      - id: wet
        doc: |
          Wet vertical delay. Add 0.252 m to get actual value.
        type: s1
      - id: stddev
        doc: |
          Modified DF389. class 3 MSB, value 5 LSB. stddev = (3^class * (1 +
          value/16) - 1)
        type: u1
  
  stec_residual_no_std:
    doc: |
      STEC residual for the given satellite at the grid point.
    seq:
      - id: sv_id
        doc: |
          space vehicle identifier
        type: gnss::sv_id
      - id: residual
        doc: |
          STEC residual
        type: s2
  
  stec_residual:
    doc: |
      STEC residual (mean and standard deviation) for the given satellite at
      the grid point.
    seq:
      - id: sv_id
        doc: |
          space vehicle identifier
        type: gnss::sv_id
      - id: residual
        doc: |
          STEC residual
        type: s2
      - id: stddev
        doc: |
          Modified DF389. class 3 MSB, value 5 LSB. stddev = (3^class * (1 +
          value/16) - 1) * 10
        type: u1
  
  msg_ssr_orbit_clock:
    doc: |
      The precise orbit and clock correction message is to be applied as a
      delta correction to broadcast ephemeris and is an equivalent to the 1060
      /1066 RTCM message types.
    seq:
      - id: time
        doc: |
          GNSS reference time of the correction
        type: gnss::gps_time_sec
      - id: sid
        doc: |
          GNSS signal identifier (16 bit)
        type: gnss::gnss_signal
      - id: update_interval
        doc: |
          Update interval between consecutive corrections. Encoded following
          RTCM DF391 specification.
        type: u1
      - id: iod_ssr
        doc: |
          IOD of the SSR correction. A change of Issue Of Data SSR is used to
          indicate a change in the SSR generating configuration
        type: u1
      - id: iod
        doc: |
          Issue of broadcast ephemeris data or IODCRC (Beidou)
        type: u4
      - id: radial
        doc: |
          Orbit radial delta correction
        type: s4
      - id: along
        doc: |
          Orbit along delta correction
        type: s4
      - id: cross
        doc: |
          Orbit along delta correction
        type: s4
      - id: dot_radial
        doc: |
          Velocity of orbit radial delta correction
        type: s4
      - id: dot_along
        doc: |
          Velocity of orbit along delta correction
        type: s4
      - id: dot_cross
        doc: |
          Velocity of orbit cross delta correction
        type: s4
      - id: c0
        doc: |
          C0 polynomial coefficient for correction of broadcast satellite
          clock
        type: s4
      - id: c1
        doc: |
          C1 polynomial coefficient for correction of broadcast satellite
          clock
        type: s4
      - id: c2
        doc: |
          C2 polynomial coefficient for correction of broadcast satellite
          clock
        type: s4
  
  msg_ssr_code_biases:
    doc: |
      The precise code biases message is to be added to the pseudorange of the
      corresponding signal to get corrected pseudorange. It is an equivalent
      to the 1059 / 1065 RTCM message types.
    seq:
      - id: time
        doc: |
          GNSS reference time of the correction
        type: gnss::gps_time_sec
      - id: sid
        doc: |
          GNSS signal identifier (16 bit)
        type: gnss::gnss_signal
      - id: update_interval
        doc: |
          Update interval between consecutive corrections. Encoded following
          RTCM DF391 specification.
        type: u1
      - id: iod_ssr
        doc: |
          IOD of the SSR correction. A change of Issue Of Data SSR is used to
          indicate a change in the SSR generating configuration
        type: u1
      - id: biases
        doc: |
          Code biases for the different satellite signals
        type: code_biases_content
        repeat: eos
  
  msg_ssr_phase_biases:
    doc: |
      The precise phase biases message contains the biases to be added to the
      carrier phase of the corresponding signal to get corrected carrier phase
      measurement, as well as the satellite yaw angle to be applied to compute
      the phase wind-up correction. It is typically an equivalent to the 1265
      RTCM message types.
    seq:
      - id: time
        doc: |
          GNSS reference time of the correction
        type: gnss::gps_time_sec
      - id: sid
        doc: |
          GNSS signal identifier (16 bit)
        type: gnss::gnss_signal
      - id: update_interval
        doc: |
          Update interval between consecutive corrections. Encoded following
          RTCM DF391 specification.
        type: u1
      - id: iod_ssr
        doc: |
          IOD of the SSR correction. A change of Issue Of Data SSR is used to
          indicate a change in the SSR generating configuration
        type: u1
      - id: dispersive_bias
        doc: |
          Indicator for the dispersive phase biases property.
        type: u1
      - id: mw_consistency
        doc: |
          Consistency indicator for Melbourne-Wubbena linear combinations
        type: u1
      - id: yaw
        doc: |
          Satellite yaw angle
        type: u2
      - id: yaw_rate
        doc: |
          Satellite yaw angle rate
        type: s1
      - id: biases
        doc: |
          Phase biases corrections for a satellite being tracked.
        type: phase_biases_content
        repeat: eos
  
  msg_ssr_stec_correction_dep:
    doc: |
      Deprecated.
    seq:
      - id: header
        doc: |
          Header of a STEC polynomial coefficient message.
        type: stec_header
      - id: stec_sat_list
        doc: |
          Array of STEC polynomial coefficients for each space vehicle.
        type: stec_sat_element
        repeat: eos
  
  bounds_header:
    seq:
      - id: time
        doc: |
          GNSS reference time of the bound
        type: gnss::gps_time_sec
      - id: num_msgs
        doc: |
          Number of messages in the dataset
        type: u1
      - id: seq_num
        doc: |
          Position of this message in the dataset
        type: u1
      - id: update_interval
        doc: |
          Update interval between consecutive bounds. Similar to RTCM DF391.
        type: u1
      - id: sol_id
        doc: |
          SSR Solution ID.
        type: u1
  
  msg_ssr_stec_correction:
    seq:
      - id: header
        doc: |
          Header of a STEC correction with bounds message.
        type: bounds_header
      - id: ssr_iod_atmo
        doc: |
          IOD of the SSR atmospheric correction
        type: u1
      - id: tile_set_id
        doc: |
          Tile set ID
        type: u2
      - id: tile_id
        doc: |
          Tile ID
        type: u2
      - id: n_sats
        doc: |
          Number of satellites.
        type: u1
      - id: stec_sat_list
        doc: |
          Array of STEC polynomial coefficients for each space vehicle.
        type: stec_sat_element
        repeat: eos
  
  msg_ssr_gridded_correction:
    doc: |
      STEC residuals are per space vehicle, troposphere is not.

      It is typically equivalent to the QZSS CLAS Sub Type 9 messages.
    seq:
      - id: header
        doc: |
          Header of a gridded correction message
        type: gridded_correction_header
      - id: index
        doc: |
          Index of the grid point.
        type: u2
      - id: tropo_delay_correction
        doc: |
          Wet and hydrostatic vertical delays (mean, stddev).
        type: tropospheric_delay_correction
      - id: stec_residuals
        doc: |
          STEC residuals for each satellite (mean, stddev).
        type: stec_residual
        repeat: eos
  
  stec_sat_element_integrity:
    doc: |
      STEC polynomial and bounds for the given satellite.
    seq:
      - id: stec_residual
        doc: |
          STEC residuals (mean, stddev)
        type: stec_residual
      - id: stec_bound_mu
        doc: |
          Error Bound Mean. See Note 1.
        type: u1
      - id: stec_bound_sig
        doc: |
          Error Bound StDev. See Note 1.
        type: u1
      - id: stec_bound_mu_dot
        doc: |
          Error Bound Mean First derivative.
        type: u1
      - id: stec_bound_sig_dot
        doc: |
          Error Bound StDev First derivative.
        type: u1
  
  msg_ssr_gridded_correction_bounds:
    doc: |
      Note 1: Range: 0-17.5 m. i<= 200, mean = 0.01i; 200<i<=230,
      mean=2+0.1(i-200); i>230, mean=5+0.5(i-230).
    seq:
      - id: header
        doc: |
          Header of a bounds message.
        type: bounds_header
      - id: ssr_iod_atmo
        doc: |
          IOD of the correction.
        type: u1
      - id: tile_set_id
        doc: |
          Set this tile belongs to.
        type: u2
      - id: tile_id
        doc: |
          Unique identifier of this tile in the tile set.
        type: u2
      - id: tropo_qi
        doc: |
          Tropo Quality Indicator. Similar to RTCM DF389.
        type: u1
      - id: grid_point_id
        doc: |
          Index of the Grid Point.
        type: u2
      - id: tropo_delay_correction
        doc: |
          Tropospheric delay at grid point.
        type: tropospheric_delay_correction
      - id: tropo_v_hydro_bound_mu
        doc: |
          Vertical Hydrostatic Error Bound Mean.
        type: u1
      - id: tropo_v_hydro_bound_sig
        doc: |
          Vertical Hydrostatic Error Bound StDev.
        type: u1
      - id: tropo_v_wet_bound_mu
        doc: |
          Vertical Wet Error Bound Mean.
        type: u1
      - id: tropo_v_wet_bound_sig
        doc: |
          Vertical Wet Error Bound StDev.
        type: u1
      - id: n_sats
        doc: |
          Number of satellites.
        type: u1
      - id: stec_sat_list
        doc: |
          Array of STEC polynomial coefficients and its bounds for each space
          vehicle.
        type: stec_sat_element_integrity
        repeat: eos
  
  msg_ssr_tile_definition_dep_a:
    doc: |
      Deprecated.
    seq:
      - id: tile_set_id
        doc: |
          Unique identifier of the tile set this tile belongs to.
        type: u2
      - id: tile_id
        doc: |
          Unique identifier of this tile in the tile set.
          See GNSS-SSR-ArrayOfCorrectionPoints field correctionPointSetID.
        type: u2
      - id: corner_nw_lat
        doc: |
          North-West corner correction point latitude.

          The relation between the latitude X in the range [-90, 90] and the
          coded number N is:

          N = floor((X / 90) * 2^14)

          See GNSS-SSR-ArrayOfCorrectionPoints field referencePointLatitude.
        type: s2
      - id: corner_nw_lon
        doc: |
          North-West corner correction point longitude.

          The relation between the longitude X in the range [-180, 180] and
          the coded number N is:

          N = floor((X / 180) * 2^15)

          See GNSS-SSR-ArrayOfCorrectionPoints field referencePointLongitude.
        type: s2
      - id: spacing_lat
        doc: |
          Spacing of the correction points in the latitude direction.

          See GNSS-SSR-ArrayOfCorrectionPoints field stepOfLatitude.
        type: u2
      - id: spacing_lon
        doc: |
          Spacing of the correction points in the longitude direction.

          See GNSS-SSR-ArrayOfCorrectionPoints field stepOfLongitude.
        type: u2
      - id: rows
        doc: |
          Number of steps in the latitude direction.

          See GNSS-SSR-ArrayOfCorrectionPoints field numberOfStepsLatitude.
        type: u2
      - id: cols
        doc: |
          Number of steps in the longitude direction.

          See GNSS-SSR-ArrayOfCorrectionPoints field numberOfStepsLongitude.
        type: u2
      - id: bitmask
        doc: |
          Specifies the availability of correction data at the correction
          points in the array.

          If a specific bit is enabled (set to 1), the correction is not
          available. Only the first rows * cols bits are used, the remainder
          are set to 0. If there are more then 64 correction points the
          remaining corrections are always available.

          Starting with the northwest corner of the array (top left on a north
          oriented map) the correction points are enumerated with row
          precedence - first row west to east, second row west to east, until
          last row west to east - ending with the southeast corner of the
          array.

          See GNSS-SSR-ArrayOfCorrectionPoints field bitmaskOfGrids but note
          the definition of the bits is inverted.
        type: u8
  
  msg_ssr_tile_definition_dep_b:
    doc: |
      Deprecated.
    seq:
      - id: ssr_sol_id
        doc: |
          SSR Solution ID.
        type: u1
      - id: tile_set_id
        doc: |
          Unique identifier of the tile set this tile belongs to.
        type: u2
      - id: tile_id
        doc: |
          Unique identifier of this tile in the tile set.
          See GNSS-SSR-ArrayOfCorrectionPoints field correctionPointSetID.
        type: u2
      - id: corner_nw_lat
        doc: |
          North-West corner correction point latitude.

          The relation between the latitude X in the range [-90, 90] and the
          coded number N is:

          N = floor((X / 90) * 2^14)

          See GNSS-SSR-ArrayOfCorrectionPoints field referencePointLatitude.
        type: s2
      - id: corner_nw_lon
        doc: |
          North-West corner correction point longitude.

          The relation between the longitude X in the range [-180, 180] and
          the coded number N is:

          N = floor((X / 180) * 2^15)

          See GNSS-SSR-ArrayOfCorrectionPoints field referencePointLongitude.
        type: s2
      - id: spacing_lat
        doc: |
          Spacing of the correction points in the latitude direction.

          See GNSS-SSR-ArrayOfCorrectionPoints field stepOfLatitude.
        type: u2
      - id: spacing_lon
        doc: |
          Spacing of the correction points in the longitude direction.

          See GNSS-SSR-ArrayOfCorrectionPoints field stepOfLongitude.
        type: u2
      - id: rows
        doc: |
          Number of steps in the latitude direction.

          See GNSS-SSR-ArrayOfCorrectionPoints field numberOfStepsLatitude.
        type: u2
      - id: cols
        doc: |
          Number of steps in the longitude direction.

          See GNSS-SSR-ArrayOfCorrectionPoints field numberOfStepsLongitude.
        type: u2
      - id: bitmask
        doc: |
          Specifies the availability of correction data at the correction
          points in the array.

          If a specific bit is enabled (set to 1), the correction is not
          available. Only the first rows * cols bits are used, the remainder
          are set to 0. If there are more then 64 correction points the
          remaining corrections are always available.

          Starting with the northwest corner of the array (top left on a north
          oriented map) the correction points are enumerated with row
          precedence - first row west to east, second row west to east, until
          last row west to east - ending with the southeast corner of the
          array.

          See GNSS-SSR-ArrayOfCorrectionPoints field bitmaskOfGrids but note
          the definition of the bits is inverted.
        type: u8
  
  msg_ssr_tile_definition:
    doc: |
      Provides the correction point coordinates for the atmospheric correction
      values in the MSG_SSR_STEC_CORRECTION and MSG_SSR_GRIDDED_CORRECTION
      messages.

      Based on ETSI TS 137 355 V16.1.0 (LTE Positioning Protocol) information
      element GNSS-SSR-CorrectionPoints. SBP only supports gridded arrays of
      correction points, not lists of points.
    seq:
      - id: time
        doc: |
          GNSS reference time of the correction
        type: gnss::gps_time_sec
      - id: update_interval
        doc: |
          Update interval between consecutive corrections. Encoded following
          RTCM DF391 specification.
        type: u1
      - id: sol_id
        doc: |
          SSR Solution ID. Similar to RTCM DF415.
        type: u1
      - id: iod_atmo
        doc: |
          IOD of the SSR atmospheric correction.
        type: u1
      - id: tile_set_id
        doc: |
          Unique identifier of the tile set this tile belongs to.
        type: u2
      - id: tile_id
        doc: |
          Unique identifier of this tile in the tile set.
          See GNSS-SSR-ArrayOfCorrectionPoints field correctionPointSetID.
        type: u2
      - id: corner_nw_lat
        doc: |
          North-West corner correction point latitude.

          The relation between the latitude X in the range [-90, 90] and the
          coded number N is:  N = floor((X / 90) * 2^14)

          See GNSS-SSR-ArrayOfCorrectionPoints field referencePointLatitude.
        type: s2
      - id: corner_nw_lon
        doc: |
          North-West corner correction point longitude.

          The relation between the longitude X in the range [-180, 180] and
          the coded number N is: N = floor((X / 180) * 2^15)

          See GNSS-SSR-ArrayOfCorrectionPoints field referencePointLongitude.
        type: s2
      - id: spacing_lat
        doc: |
          Spacing of the correction points in the latitude direction.

          See GNSS-SSR-ArrayOfCorrectionPoints field stepOfLatitude.
        type: u2
      - id: spacing_lon
        doc: |
          Spacing of the correction points in the longitude direction.

          See GNSS-SSR-ArrayOfCorrectionPoints field stepOfLongitude.
        type: u2
      - id: rows
        doc: |
          Number of steps in the latitude direction.

          See GNSS-SSR-ArrayOfCorrectionPoints field numberOfStepsLatitude.
        type: u2
      - id: cols
        doc: |
          Number of steps in the longitude direction.

          See GNSS-SSR-ArrayOfCorrectionPoints field numberOfStepsLongitude.
        type: u2
      - id: bitmask
        doc: |
          Specifies the absence of correction data at the correction points in
          the array (grid).

          Only the first rows * cols bits are used, and if a specific bit is
          enabled (set to 1), the correction is not available. If there are
          more than 64 correction points the remaining corrections are always
          available.

          The correction points are packed by rows, starting with the
          northwest corner of the array (top-left on a north oriented map),
          with each row spanning west to east, ending with the southeast
          corner of the array.

          See GNSS-SSR-ArrayOfCorrectionPoints field bitmaskOfGrids but note
          the definition of the bits is inverted.
        type: u8
  
  satellite_apc:
    doc: |
      Contains phase center offset and elevation variation corrections for one
      signal on a satellite.
    seq:
      - id: sid
        doc: |
          GNSS signal identifier (16 bit)
        type: gnss::gnss_signal
      - id: sat_info
        doc: |
          Additional satellite information
        type: u1
      - id: svn
        doc: |
          Satellite Code, as defined by IGS. Typically the space vehicle
          number.
        type: u2
      - id: pco
        doc: |
          Mean phase center offset, X Y and Z axes. See IGS ANTEX file format
          description for coordinate system definition.
        type: s2
        repeat: expr
        repeat-expr: 3
      - id: pcv
        doc: |
          Elevation dependent phase center variations. First element is 0
          degrees separation from the Z axis, subsequent elements represent
          elevation variations in 1 degree increments.
        type: s1
        repeat: expr
        repeat-expr: 21
  
  msg_ssr_satellite_apc_dep:
    doc: |
      Deprecated.
    seq:
      - id: apc
        doc: |
          Satellite antenna phase center corrections
        type: satellite_apc
        repeat: eos
  
  msg_ssr_satellite_apc:
    seq:
      - id: time
        doc: |
          GNSS reference time of the correction
        type: gnss::gps_time_sec
      - id: update_interval
        doc: |
          Update interval between consecutive corrections. Encoded following
          RTCM DF391 specification.
        type: u1
      - id: sol_id
        doc: |
          SSR Solution ID. Similar to RTCM DF415.
        type: u1
      - id: iod_ssr
        doc: |
          IOD of the SSR correction. A change of Issue Of Data SSR is used to
          indicate a change in the SSR generating configuration
        type: u1
      - id: apc
        doc: |
          Satellite antenna phase center corrections
        type: satellite_apc
        repeat: eos
  
  msg_ssr_orbit_clock_dep_a:
    doc: |
      Deprecated.
    seq:
      - id: time
        doc: |
          GNSS reference time of the correction
        type: gnss::gps_time_sec
      - id: sid
        doc: |
          GNSS signal identifier (16 bit)
        type: gnss::gnss_signal
      - id: update_interval
        doc: |
          Update interval between consecutive corrections. Encoded following
          RTCM DF391 specification.
        type: u1
      - id: iod_ssr
        doc: |
          IOD of the SSR correction. A change of Issue Of Data SSR is used to
          indicate a change in the SSR generating configuration
        type: u1
      - id: iod
        doc: |
          Issue of broadcast ephemeris data
        type: u1
      - id: radial
        doc: |
          Orbit radial delta correction
        type: s4
      - id: along
        doc: |
          Orbit along delta correction
        type: s4
      - id: cross
        doc: |
          Orbit along delta correction
        type: s4
      - id: dot_radial
        doc: |
          Velocity of orbit radial delta correction
        type: s4
      - id: dot_along
        doc: |
          Velocity of orbit along delta correction
        type: s4
      - id: dot_cross
        doc: |
          Velocity of orbit cross delta correction
        type: s4
      - id: c0
        doc: |
          C0 polynomial coefficient for correction of broadcast satellite
          clock
        type: s4
      - id: c1
        doc: |
          C1 polynomial coefficient for correction of broadcast satellite
          clock
        type: s4
      - id: c2
        doc: |
          C2 polynomial coefficient for correction of broadcast satellite
          clock
        type: s4
  
  stec_header_dep_a:
    doc: |
      A full set of STEC information will likely span multiple SBP messages,
      since SBP message a limited to 255 bytes.  The header is used to tie
      multiple SBP messages into a sequence.
    seq:
      - id: time
        doc: |
          GNSS reference time of the correction
        type: gnss::gps_time_sec
      - id: num_msgs
        doc: |
          Number of messages in the dataset
        type: u1
      - id: seq_num
        doc: |
          Position of this message in the dataset
        type: u1
      - id: update_interval
        doc: |
          Update interval between consecutive corrections. Encoded following
          RTCM DF391 specification.
        type: u1
      - id: iod_atmo
        doc: |
          IOD of the SSR atmospheric correction
        type: u1
  
  gridded_correction_header_dep_a:
    doc: |
      The 3GPP message contains nested variable length arrays which are not
      supported in SBP, so each grid point will be identified by the index.
    seq:
      - id: time
        doc: |
          GNSS reference time of the correction
        type: gnss::gps_time_sec
      - id: num_msgs
        doc: |
          Number of messages in the dataset
        type: u2
      - id: seq_num
        doc: |
          Position of this message in the dataset
        type: u2
      - id: update_interval
        doc: |
          Update interval between consecutive corrections. Encoded following
          RTCM DF391 specification.
        type: u1
      - id: iod_atmo
        doc: |
          IOD of the SSR atmospheric correction
        type: u1
      - id: tropo_quality_indicator
        doc: |
          Quality of the troposphere data. Encoded following RTCM DF389
          specification in units of m.
        type: u1
  
  grid_definition_header_dep_a:
    doc: |
      Defines the grid for MSG_SSR_GRIDDED_CORRECTION messages. Also includes
      an RLE encoded validity list.
    seq:
      - id: region_size_inverse
        doc: |
          region_size (deg) = 10 / region_size_inverse 0 is an invalid value.
        type: u1
      - id: area_width
        doc: |
          grid height (deg) = grid width (deg) = area_width / region_size 0 is
          an invalid value.
        type: u2
      - id: lat_nw_corner_enc
        doc: |
          North-West corner latitude (deg) = region_size * lat_nw_corner_enc -
          90
        type: u2
      - id: lon_nw_corner_enc
        doc: |
          North-West corner longitude (deg) = region_size * lon_nw_corner_enc
          - 180
        type: u2
      - id: num_msgs
        doc: |
          Number of messages in the dataset
        type: u1
      - id: seq_num
        doc: |
          Position of this message in the dataset
        type: u1
  
  msg_ssr_stec_correction_dep_a:
    doc: |
      Deprecated.
    seq:
      - id: header
        doc: |
          Header of a STEC message
        type: stec_header_dep_a
      - id: stec_sat_list
        doc: |
          Array of STEC information for each space vehicle
        type: stec_sat_element
        repeat: eos
  
  msg_ssr_gridded_correction_no_std_dep_a:
    doc: |
      Deprecated.
    seq:
      - id: header
        doc: |
          Header of a Gridded Correction message
        type: gridded_correction_header_dep_a
      - id: index
        doc: |
          Index of the grid point
        type: u2
      - id: tropo_delay_correction
        doc: |
          Wet and hydrostatic vertical delays
        type: tropospheric_delay_correction_no_std
      - id: stec_residuals
        doc: |
          STEC residuals for each satellite
        type: stec_residual_no_std
        repeat: eos
  
  msg_ssr_gridded_correction_dep_a:
    doc: |
      Deprecated.
    seq:
      - id: header
        doc: |
          Header of a Gridded Correction message
        type: gridded_correction_header_dep_a
      - id: index
        doc: |
          Index of the grid point
        type: u2
      - id: tropo_delay_correction
        doc: |
          Wet and hydrostatic vertical delays (mean, stddev)
        type: tropospheric_delay_correction
      - id: stec_residuals
        doc: |
          STEC residuals for each satellite (mean, stddev)
        type: stec_residual
        repeat: eos
  
  msg_ssr_grid_definition_dep_a:
    doc: |
      Deprecated.
    seq:
      - id: header
        doc: |
          Header of a Gridded Correction message
        type: grid_definition_header_dep_a
      - id: rle_list
        doc: |
          Run Length Encode list of quadrants that contain valid data. The
          spec describes the encoding scheme in detail, but essentially the
          index of the quadrants that contain transitions between valid and
          invalid (and vice versa) are encoded as u8 integers.
        type: u1
        repeat: eos
  
  orbit_clock_bound:
    doc: |
      Orbit and clock bound.
    seq:
      - id: sat_id
        doc: |
          Satellite ID. Similar to either RTCM DF068 (GPS), DF252 (Galileo),
          or DF488 (BDS) depending on the constellation.
        type: u1
      - id: orb_radial_bound_mu
        doc: |
          Mean Radial. See Note 1.
        type: u1
      - id: orb_along_bound_mu
        doc: |
          Mean Along-Track. See Note 1.
        type: u1
      - id: orb_cross_bound_mu
        doc: |
          Mean Cross-Track. See Note 1.
        type: u1
      - id: orb_radial_bound_sig
        doc: |
          Standard Deviation Radial. See Note 2.
        type: u1
      - id: orb_along_bound_sig
        doc: |
          Standard Deviation Along-Track. See Note 2.
        type: u1
      - id: orb_cross_bound_sig
        doc: |
          Standard Deviation Cross-Track. See Note 2.
        type: u1
      - id: clock_bound_mu
        doc: |
          Clock Bound Mean. See Note 1.
        type: u1
      - id: clock_bound_sig
        doc: |
          Clock Bound Standard Deviation. See Note 2.
        type: u1
  
  msg_ssr_orbit_clock_bounds:
    doc: |
      Note 1: Range: 0-17.5 m. i<=200, mean=0.01i; 200<i<=230,
      mean=2+0.1(i-200); i>230, mean=5+0.5(i-230).

      Note 2: Range: 0-17.5 m. i<=200, std=0.01i; 200<i<=230, std=2+0.1(i-200)
      i>230, std=5+0.5(i-230).
    seq:
      - id: header
        doc: |
          Header of a bounds message.
        type: bounds_header
      - id: ssr_iod
        doc: |
          IOD of the SSR bound.
        type: u1
      - id: const_id
        doc: |
          Constellation ID to which the SVs belong.
        type: u1
      - id: n_sats
        doc: |
          Number of satellites.
        type: u1
      - id: orbit_clock_bounds
        doc: |
          Orbit and Clock Bounds per Satellite
        type: orbit_clock_bound
        repeat: eos
  
  code_phase_biases_sat_sig:
    seq:
      - id: sat_id
        doc: |
          Satellite ID. Similar to either RTCM DF068 (GPS), DF252 (Galileo),
          or DF488 (BDS) depending on the constellation.
        type: u1
      - id: signal_id
        doc: |
          Signal and Tracking Mode Identifier. Similar to either RTCM DF380
          (GPS), DF382 (Galileo) or DF467 (BDS) depending on the
          constellation.
        type: u1
      - id: code_bias_bound_mu
        doc: |
          Code Bias Mean. Range: 0-1.275 m
        type: u1
      - id: code_bias_bound_sig
        doc: |
          Code Bias Standard Deviation. Range: 0-1.275 m
        type: u1
      - id: phase_bias_bound_mu
        doc: |
          Phase Bias Mean. Range: 0-1.275 m
        type: u1
      - id: phase_bias_bound_sig
        doc: |
          Phase Bias Standard Deviation. Range: 0-1.275 m
        type: u1
  
  msg_ssr_code_phase_biases_bounds:
    seq:
      - id: header
        doc: |
          Header of a bounds message.
        type: bounds_header
      - id: ssr_iod
        doc: |
          IOD of the SSR bound.
        type: u1
      - id: const_id
        doc: |
          Constellation ID to which the SVs belong.
        type: u1
      - id: n_sats_signals
        doc: |
          Number of satellite-signal couples.
        type: u1
      - id: satellites_signals
        doc: |
          Code and Phase Biases Bounds per Satellite-Signal couple.
        type: code_phase_biases_sat_sig
        repeat: eos
  
  orbit_clock_bound_degradation:
    doc: |
      Orbit and clock bound degradation.
    seq:
      - id: orb_radial_bound_mu_dot
        doc: |
          Orbit Bound Mean Radial First derivative. Range: 0-0.255 m/s
        type: u1
      - id: orb_along_bound_mu_dot
        doc: |
          Orbit Bound Mean Along-Track First derivative. Range: 0-0.255 m/s
        type: u1
      - id: orb_cross_bound_mu_dot
        doc: |
          Orbit Bound Mean Cross-Track First derivative. Range: 0-0.255 m/s
        type: u1
      - id: orb_radial_bound_sig_dot
        doc: |
          Orbit Bound Standard Deviation Radial First derivative. Range:
          0-0.255 m/s
        type: u1
      - id: orb_along_bound_sig_dot
        doc: |
          Orbit Bound Standard Deviation Along-Track First derivative. Range:
          0-0.255 m/s
        type: u1
      - id: orb_cross_bound_sig_dot
        doc: |
          Orbit Bound Standard Deviation Cross-Track First derivative. Range:
          0-0.255 m/s
        type: u1
      - id: clock_bound_mu_dot
        doc: |
          Clock Bound Mean First derivative. Range: 0-0.255 m/s
        type: u1
      - id: clock_bound_sig_dot
        doc: |
          Clock Bound Standard Deviation First derivative. Range: 0-0.255 m/s
        type: u1
  
  msg_ssr_orbit_clock_bounds_degradation:
    seq:
      - id: header
        doc: |
          Header of a bounds message.
        type: bounds_header
      - id: ssr_iod
        doc: |
          IOD of the SSR bound degradation parameter.
        type: u1
      - id: const_id
        doc: |
          Constellation ID to which the SVs belong.
        type: u1
      - id: sat_bitmask
        doc: |
          Satellite Bit Mask. Put 1 for each satellite where the following
          degradation parameters are applicable, 0 otherwise. Encoded
          following RTCM DF394 specification.
        type: u8
      - id: orbit_clock_bounds_degradation
        doc: |
          Orbit and Clock Bounds Degradation Parameters
        type: orbit_clock_bound_degradation
  