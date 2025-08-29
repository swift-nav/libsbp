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
# Kaitai Struct definition file for Swift Binary Protocol 6.2.3-alpha
#
# Automatically generated with generate.py.  Do not hand edit!

meta:
  id: sbp
  file-extension: sbp
  endian: le
  imports:

  - acquisition
  - bootload
  - ext_events
  - file_io
  - flash
  - gnss
  - imu
  - integrity
  - linux
  - logging
  - mag
  - navigation
  - ndb
  - observation
  - orientation
  - piksi
  - profiling
  - sbas
  - settings
  - signing
  - solution_meta
  - ssr
  - system
  - telemetry
  - tracking
  - user
  - vehicle

seq:
  - id: message
    type: sbp_message
    repeat: eos

enums:
  msg_ids:

  
    47: msg_acq_result
    31: msg_acq_result_dep_c
    20: msg_acq_result_dep_b
    21: msg_acq_result_dep_a
    46: msg_acq_sv_profile
    30: msg_acq_sv_profile_dep
  
    179: msg_bootloader_handshake_req
    180: msg_bootloader_handshake_resp
    177: msg_bootloader_jump_to_app
    222: msg_nap_device_dna_req
    221: msg_nap_device_dna_resp
    176: msg_bootloader_handshake_dep_a
  
    257: msg_ext_event
  
    168: msg_fileio_read_req
    163: msg_fileio_read_resp
    169: msg_fileio_read_dir_req
    170: msg_fileio_read_dir_resp
    172: msg_fileio_remove
    173: msg_fileio_write_req
    171: msg_fileio_write_resp
    4097: msg_fileio_config_req
    4098: msg_fileio_config_resp
  
    230: msg_flash_program
    224: msg_flash_done
    231: msg_flash_read_req
    225: msg_flash_read_resp
    226: msg_flash_erase
    227: msg_stm_flash_lock_sector
    228: msg_stm_flash_unlock_sector
    232: msg_stm_unique_id_req
    229: msg_stm_unique_id_resp
    243: msg_m25_flash_write_status
  
  
    2304: msg_imu_raw
    2305: msg_imu_aux
    2309: msg_imu_comp
  
    3001: msg_ssr_flag_high_level_dep_a
    3002: msg_ssr_flag_high_level
    3005: msg_ssr_flag_satellites
    3011: msg_ssr_flag_tropo_grid_points
    3015: msg_ssr_flag_iono_grid_points
    3021: msg_ssr_flag_iono_tile_sat_los
    3025: msg_ssr_flag_iono_grid_point_sat_los
    3026: msg_acknowledge
  
    32512: msg_linux_cpu_state_dep_a
    32513: msg_linux_mem_state_dep_a
    32514: msg_linux_sys_state_dep_a
    32515: msg_linux_process_socket_counts
    32516: msg_linux_process_socket_queues
    32517: msg_linux_socket_usage
    32518: msg_linux_process_fd_count
    32519: msg_linux_process_fd_summary
    32520: msg_linux_cpu_state
    32521: msg_linux_mem_state
    32522: msg_linux_sys_state
  
    1025: msg_log
    1026: msg_fwd
    16: msg_print_dep
  
    2306: msg_mag_raw
  
    258: msg_gps_time
    260: msg_gps_time_gnss
    259: msg_utc_time
    261: msg_utc_time_gnss
    520: msg_dops
    521: msg_pos_ecef
    532: msg_pos_ecef_cov
    522: msg_pos_llh
    529: msg_pos_llh_cov
    536: msg_pos_llh_acc
    523: msg_baseline_ecef
    524: msg_baseline_ned
    525: msg_vel_ecef
    533: msg_vel_ecef_cov
    526: msg_vel_ned
    530: msg_vel_ned_cov
    553: msg_pos_ecef_gnss
    564: msg_pos_ecef_cov_gnss
    554: msg_pos_llh_gnss
    561: msg_pos_llh_cov_gnss
    557: msg_vel_ecef_gnss
    565: msg_vel_ecef_cov_gnss
    558: msg_vel_ned_gnss
    562: msg_vel_ned_cov_gnss
    531: msg_vel_body
    540: msg_vel_cog
    528: msg_age_corrections
    256: msg_gps_time_dep_a
    518: msg_dops_dep_a
    512: msg_pos_ecef_dep_a
    513: msg_pos_llh_dep_a
    514: msg_baseline_ecef_dep_a
    515: msg_baseline_ned_dep_a
    516: msg_vel_ecef_dep_a
    517: msg_vel_ned_dep_a
    519: msg_baseline_heading_dep_a
    534: msg_protection_level_dep_a
    535: msg_protection_level
    570: msg_utc_leap_second
    580: msg_reference_frame_param
    581: msg_pose_relative
  
    1024: msg_ndb_event
  
    74: msg_obs
    68: msg_base_pos_llh
    72: msg_base_pos_ecef
    129: msg_ephemeris_gps_dep_e
    134: msg_ephemeris_gps_dep_f
    138: msg_ephemeris_gps
    142: msg_ephemeris_qzss
    137: msg_ephemeris_bds
    149: msg_ephemeris_gal_dep_a
    141: msg_ephemeris_gal
    130: msg_ephemeris_sbas_dep_a
    131: msg_ephemeris_glo_dep_a
    132: msg_ephemeris_sbas_dep_b
    140: msg_ephemeris_sbas
    133: msg_ephemeris_glo_dep_b
    135: msg_ephemeris_glo_dep_c
    136: msg_ephemeris_glo_dep_d
    139: msg_ephemeris_glo
    128: msg_ephemeris_dep_d
    26: msg_ephemeris_dep_a
    70: msg_ephemeris_dep_b
    71: msg_ephemeris_dep_c
    69: msg_obs_dep_a
    67: msg_obs_dep_b
    73: msg_obs_dep_c
    144: msg_iono
    145: msg_sv_configuration_gps_dep
    150: msg_gnss_capb
    146: msg_group_delay_dep_a
    147: msg_group_delay_dep_b
    148: msg_group_delay
    112: msg_almanac_gps_dep
    114: msg_almanac_gps
    113: msg_almanac_glo_dep
    115: msg_almanac_glo
    117: msg_glo_biases
    151: msg_sv_az_el
    1600: msg_osr
  
    527: msg_baseline_heading
    544: msg_orient_quat
    545: msg_orient_euler
    546: msg_angular_rate
  
    105: msg_almanac
    104: msg_set_time
    182: msg_reset
    178: msg_reset_dep
    192: msg_cw_results
    193: msg_cw_start
    34: msg_reset_filters
    35: msg_init_base_dep
    23: msg_thread_state
    29: msg_uart_state
    24: msg_uart_state_depa
    25: msg_iar_state
    43: msg_mask_satellite
    27: msg_mask_satellite_dep
    181: msg_device_monitor
    184: msg_command_req
    185: msg_command_resp
    188: msg_command_output
    186: msg_network_state_req
    187: msg_network_state_resp
    189: msg_network_bandwidth_usage
    190: msg_cell_modem_status
    80: msg_specan_dep
    81: msg_specan
    191: msg_front_end_gain
  
    52992: msg_measurement_point
    52993: msg_profiling_system_info
    52994: msg_profiling_thread_info
    52995: msg_profiling_resource_counter
  
    30583: msg_sbas_raw
  
    161: msg_settings_save
    160: msg_settings_write
    175: msg_settings_write_resp
    164: msg_settings_read_req
    165: msg_settings_read_resp
    162: msg_settings_read_by_index_req
    167: msg_settings_read_by_index_resp
    166: msg_settings_read_by_index_done
    174: msg_settings_register
    431: msg_settings_register_resp
  
    3076: msg_ecdsa_certificate
    3081: msg_certificate_chain
    3077: msg_certificate_chain_dep
    3088: msg_aes_cmac_signature
    3080: msg_ecdsa_signature
    3079: msg_ecdsa_signature_dep_b
    3078: msg_ecdsa_signature_dep_a
    3074: msg_ed25519_certificate_dep
    3073: msg_ed25519_signature_dep_a
    3075: msg_ed25519_signature_dep_b
  
    65295: msg_soln_meta_dep_a
    65294: msg_soln_meta
  
    1501: msg_ssr_orbit_clock
    1505: msg_ssr_code_biases
    1510: msg_ssr_phase_biases
    1531: msg_ssr_stec_correction_dep
    1533: msg_ssr_stec_correction
    1532: msg_ssr_gridded_correction
    1534: msg_ssr_gridded_correction_bounds
    1526: msg_ssr_tile_definition_dep_a
    1527: msg_ssr_tile_definition_dep_b
    1528: msg_ssr_tile_definition
    1540: msg_ssr_satellite_apc_dep
    1541: msg_ssr_satellite_apc
    1500: msg_ssr_orbit_clock_dep_a
    1515: msg_ssr_stec_correction_dep_a
    1520: msg_ssr_gridded_correction_no_std_dep_a
    1530: msg_ssr_gridded_correction_dep_a
    1525: msg_ssr_grid_definition_dep_a
    1502: msg_ssr_orbit_clock_bounds
    1516: msg_ssr_code_phase_biases_bounds
    1503: msg_ssr_orbit_clock_bounds_degradation
  
    65280: msg_startup
    65282: msg_dgnss_status
    65535: msg_heartbeat
    65534: msg_status_report
    65533: msg_status_journal
    65283: msg_ins_status
    65284: msg_csac_telemetry
    65285: msg_csac_telemetry_labels
    65286: msg_ins_updates
    65287: msg_gnss_time_offset
    65288: msg_pps_time
    65289: msg_sensor_aid_event
    65290: msg_group_meta
  
    288: msg_tel_sv
  
    33: msg_tracking_state_detailed_dep_a
    17: msg_tracking_state_detailed_dep
    65: msg_tracking_state
    97: msg_measurement_state
    45: msg_tracking_iq
    44: msg_tracking_iq_dep_b
    28: msg_tracking_iq_dep_a
    22: msg_tracking_state_dep_a
    19: msg_tracking_state_dep_b
  
    2048: msg_user_data
  
    2307: msg_odometry
    2308: msg_wheeltick

types:
  sbp_message:
    seq:
      - id: preamble
        contents: [0x55]
      - id: msg_type
        type: u2
      - id: sender
        type: u2
      - id: length
        type: u1
      - id: payload
        size: length
        type:
          switch-on: msg_type
          cases:

  
            47: acquisition::msg_acq_result
            31: acquisition::msg_acq_result_dep_c
            20: acquisition::msg_acq_result_dep_b
            21: acquisition::msg_acq_result_dep_a
            46: acquisition::msg_acq_sv_profile
            30: acquisition::msg_acq_sv_profile_dep
  
            179: bootload::msg_bootloader_handshake_req
            180: bootload::msg_bootloader_handshake_resp
            177: bootload::msg_bootloader_jump_to_app
            222: bootload::msg_nap_device_dna_req
            221: bootload::msg_nap_device_dna_resp
            176: bootload::msg_bootloader_handshake_dep_a
  
            257: ext_events::msg_ext_event
  
            168: file_io::msg_fileio_read_req
            163: file_io::msg_fileio_read_resp
            169: file_io::msg_fileio_read_dir_req
            170: file_io::msg_fileio_read_dir_resp
            172: file_io::msg_fileio_remove
            173: file_io::msg_fileio_write_req
            171: file_io::msg_fileio_write_resp
            4097: file_io::msg_fileio_config_req
            4098: file_io::msg_fileio_config_resp
  
            230: flash::msg_flash_program
            224: flash::msg_flash_done
            231: flash::msg_flash_read_req
            225: flash::msg_flash_read_resp
            226: flash::msg_flash_erase
            227: flash::msg_stm_flash_lock_sector
            228: flash::msg_stm_flash_unlock_sector
            232: flash::msg_stm_unique_id_req
            229: flash::msg_stm_unique_id_resp
            243: flash::msg_m25_flash_write_status
  
  
            2304: imu::msg_imu_raw
            2305: imu::msg_imu_aux
            2309: imu::msg_imu_comp
  
            3001: integrity::msg_ssr_flag_high_level_dep_a
            3002: integrity::msg_ssr_flag_high_level
            3005: integrity::msg_ssr_flag_satellites
            3011: integrity::msg_ssr_flag_tropo_grid_points
            3015: integrity::msg_ssr_flag_iono_grid_points
            3021: integrity::msg_ssr_flag_iono_tile_sat_los
            3025: integrity::msg_ssr_flag_iono_grid_point_sat_los
            3026: integrity::msg_acknowledge
  
            32512: linux::msg_linux_cpu_state_dep_a
            32513: linux::msg_linux_mem_state_dep_a
            32514: linux::msg_linux_sys_state_dep_a
            32515: linux::msg_linux_process_socket_counts
            32516: linux::msg_linux_process_socket_queues
            32517: linux::msg_linux_socket_usage
            32518: linux::msg_linux_process_fd_count
            32519: linux::msg_linux_process_fd_summary
            32520: linux::msg_linux_cpu_state
            32521: linux::msg_linux_mem_state
            32522: linux::msg_linux_sys_state
  
            1025: logging::msg_log
            1026: logging::msg_fwd
            16: logging::msg_print_dep
  
            2306: mag::msg_mag_raw
  
            258: navigation::msg_gps_time
            260: navigation::msg_gps_time_gnss
            259: navigation::msg_utc_time
            261: navigation::msg_utc_time_gnss
            520: navigation::msg_dops
            521: navigation::msg_pos_ecef
            532: navigation::msg_pos_ecef_cov
            522: navigation::msg_pos_llh
            529: navigation::msg_pos_llh_cov
            536: navigation::msg_pos_llh_acc
            523: navigation::msg_baseline_ecef
            524: navigation::msg_baseline_ned
            525: navigation::msg_vel_ecef
            533: navigation::msg_vel_ecef_cov
            526: navigation::msg_vel_ned
            530: navigation::msg_vel_ned_cov
            553: navigation::msg_pos_ecef_gnss
            564: navigation::msg_pos_ecef_cov_gnss
            554: navigation::msg_pos_llh_gnss
            561: navigation::msg_pos_llh_cov_gnss
            557: navigation::msg_vel_ecef_gnss
            565: navigation::msg_vel_ecef_cov_gnss
            558: navigation::msg_vel_ned_gnss
            562: navigation::msg_vel_ned_cov_gnss
            531: navigation::msg_vel_body
            540: navigation::msg_vel_cog
            528: navigation::msg_age_corrections
            256: navigation::msg_gps_time_dep_a
            518: navigation::msg_dops_dep_a
            512: navigation::msg_pos_ecef_dep_a
            513: navigation::msg_pos_llh_dep_a
            514: navigation::msg_baseline_ecef_dep_a
            515: navigation::msg_baseline_ned_dep_a
            516: navigation::msg_vel_ecef_dep_a
            517: navigation::msg_vel_ned_dep_a
            519: navigation::msg_baseline_heading_dep_a
            534: navigation::msg_protection_level_dep_a
            535: navigation::msg_protection_level
            570: navigation::msg_utc_leap_second
            580: navigation::msg_reference_frame_param
            581: navigation::msg_pose_relative
  
            1024: ndb::msg_ndb_event
  
            74: observation::msg_obs
            68: observation::msg_base_pos_llh
            72: observation::msg_base_pos_ecef
            129: observation::msg_ephemeris_gps_dep_e
            134: observation::msg_ephemeris_gps_dep_f
            138: observation::msg_ephemeris_gps
            142: observation::msg_ephemeris_qzss
            137: observation::msg_ephemeris_bds
            149: observation::msg_ephemeris_gal_dep_a
            141: observation::msg_ephemeris_gal
            130: observation::msg_ephemeris_sbas_dep_a
            131: observation::msg_ephemeris_glo_dep_a
            132: observation::msg_ephemeris_sbas_dep_b
            140: observation::msg_ephemeris_sbas
            133: observation::msg_ephemeris_glo_dep_b
            135: observation::msg_ephemeris_glo_dep_c
            136: observation::msg_ephemeris_glo_dep_d
            139: observation::msg_ephemeris_glo
            128: observation::msg_ephemeris_dep_d
            26: observation::msg_ephemeris_dep_a
            70: observation::msg_ephemeris_dep_b
            71: observation::msg_ephemeris_dep_c
            69: observation::msg_obs_dep_a
            67: observation::msg_obs_dep_b
            73: observation::msg_obs_dep_c
            144: observation::msg_iono
            145: observation::msg_sv_configuration_gps_dep
            150: observation::msg_gnss_capb
            146: observation::msg_group_delay_dep_a
            147: observation::msg_group_delay_dep_b
            148: observation::msg_group_delay
            112: observation::msg_almanac_gps_dep
            114: observation::msg_almanac_gps
            113: observation::msg_almanac_glo_dep
            115: observation::msg_almanac_glo
            117: observation::msg_glo_biases
            151: observation::msg_sv_az_el
            1600: observation::msg_osr
  
            527: orientation::msg_baseline_heading
            544: orientation::msg_orient_quat
            545: orientation::msg_orient_euler
            546: orientation::msg_angular_rate
  
            105: piksi::msg_almanac
            104: piksi::msg_set_time
            182: piksi::msg_reset
            178: piksi::msg_reset_dep
            192: piksi::msg_cw_results
            193: piksi::msg_cw_start
            34: piksi::msg_reset_filters
            35: piksi::msg_init_base_dep
            23: piksi::msg_thread_state
            29: piksi::msg_uart_state
            24: piksi::msg_uart_state_depa
            25: piksi::msg_iar_state
            43: piksi::msg_mask_satellite
            27: piksi::msg_mask_satellite_dep
            181: piksi::msg_device_monitor
            184: piksi::msg_command_req
            185: piksi::msg_command_resp
            188: piksi::msg_command_output
            186: piksi::msg_network_state_req
            187: piksi::msg_network_state_resp
            189: piksi::msg_network_bandwidth_usage
            190: piksi::msg_cell_modem_status
            80: piksi::msg_specan_dep
            81: piksi::msg_specan
            191: piksi::msg_front_end_gain
  
            52992: profiling::msg_measurement_point
            52993: profiling::msg_profiling_system_info
            52994: profiling::msg_profiling_thread_info
            52995: profiling::msg_profiling_resource_counter
  
            30583: sbas::msg_sbas_raw
  
            161: settings::msg_settings_save
            160: settings::msg_settings_write
            175: settings::msg_settings_write_resp
            164: settings::msg_settings_read_req
            165: settings::msg_settings_read_resp
            162: settings::msg_settings_read_by_index_req
            167: settings::msg_settings_read_by_index_resp
            166: settings::msg_settings_read_by_index_done
            174: settings::msg_settings_register
            431: settings::msg_settings_register_resp
  
            3076: signing::msg_ecdsa_certificate
            3081: signing::msg_certificate_chain
            3077: signing::msg_certificate_chain_dep
            3088: signing::msg_aes_cmac_signature
            3080: signing::msg_ecdsa_signature
            3079: signing::msg_ecdsa_signature_dep_b
            3078: signing::msg_ecdsa_signature_dep_a
            3074: signing::msg_ed25519_certificate_dep
            3073: signing::msg_ed25519_signature_dep_a
            3075: signing::msg_ed25519_signature_dep_b
  
            65295: solution_meta::msg_soln_meta_dep_a
            65294: solution_meta::msg_soln_meta
  
            1501: ssr::msg_ssr_orbit_clock
            1505: ssr::msg_ssr_code_biases
            1510: ssr::msg_ssr_phase_biases
            1531: ssr::msg_ssr_stec_correction_dep
            1533: ssr::msg_ssr_stec_correction
            1532: ssr::msg_ssr_gridded_correction
            1534: ssr::msg_ssr_gridded_correction_bounds
            1526: ssr::msg_ssr_tile_definition_dep_a
            1527: ssr::msg_ssr_tile_definition_dep_b
            1528: ssr::msg_ssr_tile_definition
            1540: ssr::msg_ssr_satellite_apc_dep
            1541: ssr::msg_ssr_satellite_apc
            1500: ssr::msg_ssr_orbit_clock_dep_a
            1515: ssr::msg_ssr_stec_correction_dep_a
            1520: ssr::msg_ssr_gridded_correction_no_std_dep_a
            1530: ssr::msg_ssr_gridded_correction_dep_a
            1525: ssr::msg_ssr_grid_definition_dep_a
            1502: ssr::msg_ssr_orbit_clock_bounds
            1516: ssr::msg_ssr_code_phase_biases_bounds
            1503: ssr::msg_ssr_orbit_clock_bounds_degradation
  
            65280: system::msg_startup
            65282: system::msg_dgnss_status
            65535: system::msg_heartbeat
            65534: system::msg_status_report
            65533: system::msg_status_journal
            65283: system::msg_ins_status
            65284: system::msg_csac_telemetry
            65285: system::msg_csac_telemetry_labels
            65286: system::msg_ins_updates
            65287: system::msg_gnss_time_offset
            65288: system::msg_pps_time
            65289: system::msg_sensor_aid_event
            65290: system::msg_group_meta
  
            288: telemetry::msg_tel_sv
  
            33: tracking::msg_tracking_state_detailed_dep_a
            17: tracking::msg_tracking_state_detailed_dep
            65: tracking::msg_tracking_state
            97: tracking::msg_measurement_state
            45: tracking::msg_tracking_iq
            44: tracking::msg_tracking_iq_dep_b
            28: tracking::msg_tracking_iq_dep_a
            22: tracking::msg_tracking_state_dep_a
            19: tracking::msg_tracking_state_dep_b
  
            2048: user::msg_user_data
  
            2307: vehicle::msg_odometry
            2308: vehicle::msg_wheeltick
      - id: crc
        type: u2
