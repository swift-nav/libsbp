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
# Integrity flag messages
#
# Automatically generated from spec/yaml/swiftnav/sbp/integrity.yaml with generate.py.
# Do not modify by hand!

meta:
  id: integrity
  endian: le
  imports: [ gnss ]

types:

  integrity_ssr_header:
    seq:
      - id: obs_time
        doc: |
          GNSS reference time of the observation used to generate the flag.
        type: gnss::gps_time_sec
      - id: num_msgs
        doc: |
          Number of messages in the dataset
        type: u1
      - id: seq_num
        doc: |
          Position of this message in the dataset
        type: u1
      - id: ssr_sol_id
        doc: |
          SSR Solution ID.
        type: u1
      - id: tile_set_id
        doc: |
          Unique identifier of the set this tile belongs to.
        type: u2
      - id: tile_id
        doc: |
          Unique identifier of this tile in the tile set.
        type: u2
      - id: chain_id
        doc: |
          Chain and type of flag.
        type: u1
  
  msg_ssr_flag_high_level:
    doc: |
      Integrity monitoring flags for multiple aggregated elements. An element
      could be a satellite, SSR grid point, or SSR tile. A group of aggregated
      elements being monitored for integrity could refer to:

      - Satellites in a particular {GPS, GAL, BDS} constellation.

      - Satellites in the line-of-sight of a particular SSR tile.

      - Satellites in the line-of-sight of a particular SSR grid point.

      The integrity usage for a group of aggregated elements varies according
      to the integrity flag of the satellites comprising that group.

      SSR_INTEGRITY_USAGE_NOMINAL: All satellites received passed the
      integrity check and have flag INTEGRITY_FLAG_OK.

      SSR_INTEGRITY_USAGE_WARNING: A limited number of elements in the group
      failed the integrity check. Refer to more granular integrity messages
      for details on the specific failing elements.

      SSR_INTEGRITY_USAGE_ALERT: Most elements in the group failed the
      integrity check, do not use for positioning.

      SSR_INTEGRITY_USAGE_NOT_MONITORED: Unable to verify the integrity flag
      of elements in the group.
    seq:
      - id: obs_time
        doc: |
          GNSS reference time of the observation used to generate the flag.
        type: gnss::gps_time_sec
      - id: corr_time
        doc: |
          GNSS reference time of the correction associated to the flag.
        type: gnss::gps_time_sec
      - id: ssr_sol_id
        doc: |
          SSR Solution ID.
        type: u1
      - id: tile_set_id
        doc: |
          Unique identifier of the set this tile belongs to.
        type: u2
      - id: tile_id
        doc: |
          Unique identifier of this tile in the tile set.
        type: u2
      - id: chain_id
        doc: |
          Chain and type of flag.
        type: u1
      - id: use_gps_sat
        doc: |
          Use GPS satellites.
        type: u1
      - id: use_gal_sat
        doc: |
          Use GAL satellites.
        type: u1
      - id: use_bds_sat
        doc: |
          Use BDS satellites.
        type: u1
      - id: reserved
        doc: |
          Reserved
        type: u1
        repeat: expr
        repeat-expr: 6
      - id: use_tropo_grid_points
        doc: |
          Use tropo grid points.
        type: u1
      - id: use_iono_grid_points
        doc: |
          Use iono grid points.
        type: u1
      - id: use_iono_tile_sat_los
        doc: |
          Use iono tile satellite LoS.
        type: u1
      - id: use_iono_grid_point_sat_los
        doc: |
          Use iono grid point satellite LoS.
        type: u1
  
  msg_ssr_flag_satellites:
    seq:
      - id: obs_time
        doc: |
          GNSS reference time of the observation used to generate the flag.
        type: gnss::gps_time_sec
      - id: num_msgs
        doc: |
          Number of messages in the dataset
        type: u1
      - id: seq_num
        doc: |
          Position of this message in the dataset
        type: u1
      - id: ssr_sol_id
        doc: |
          SSR Solution ID.
        type: u1
      - id: chain_id
        doc: |
          Chain and type of flag.
        type: u1
      - id: const_id
        doc: |
          Constellation ID.
        type: u1
      - id: n_faulty_sats
        doc: |
          Number of faulty satellites.
        type: u1
      - id: faulty_sats
        doc: |
          List of faulty satellites.
        type: u1
        repeat: eos
  
  msg_ssr_flag_tropo_grid_points:
    seq:
      - id: header
        doc: |
          Header of an integrity message.
        type: integrity_ssr_header
      - id: n_faulty_points
        doc: |
          Number of faulty grid points.
        type: u1
      - id: faulty_points
        doc: |
          List of faulty grid points.
        type: u2
        repeat: eos
  
  msg_ssr_flag_iono_grid_points:
    seq:
      - id: header
        doc: |
          Header of an integrity message.
        type: integrity_ssr_header
      - id: n_faulty_points
        doc: |
          Number of faulty grid points.
        type: u1
      - id: faulty_points
        doc: |
          List of faulty grid points.
        type: u2
        repeat: eos
  
  msg_ssr_flag_iono_tile_sat_los:
    seq:
      - id: header
        doc: |
          Header of an integrity message.
        type: integrity_ssr_header
      - id: n_faulty_los
        doc: |
          Number of faulty LOS.
        type: u1
      - id: faulty_los
        doc: |
          List of faulty LOS
        type: gnss::sv_id
        repeat: eos
  
  msg_ssr_flag_iono_grid_point_sat_los:
    seq:
      - id: header
        doc: |
          Header of an integrity message.
        type: integrity_ssr_header
      - id: grid_point_id
        doc: |
          Index of the grid point.
        type: u2
      - id: n_faulty_los
        doc: |
          Number of faulty LOS.
        type: u1
      - id: faulty_los
        doc: |
          List of faulty LOS
        type: gnss::sv_id
        repeat: eos
  
  msg_acknowledge:
    seq:
      - id: request_id
        doc: |
          Echo of the request ID field from the corresponding CRA message, or
          255 if no request ID was provided.
        type: u1
      - id: area_id
        doc: |
          Echo of the Area ID field from the corresponding CRA message.
        type: u4
      - id: response_code
        doc: |
          Reported status of the request.
        type: u1
      - id: correction_mask_on_demand
        doc: |
          Contains the message group(s) that will be sent in response from the
          corresponding CRA correction mask. An echo of the correction mask
          field from the corresponding CRA message.
        type: u2
      - id: correction_mask_stream
        doc: |
          For future expansion. Always set to 0.
        type: u2
      - id: solution_id
        doc: |
          The solution ID of the instance providing the corrections.
        type: u1
  