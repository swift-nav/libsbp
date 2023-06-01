# Kaitai Struct definition file for Swift Binary Protocol 4.15.1-alpha

# Automatically generated with generate.py.
# Please do not hand edit!

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
    type: message
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
  
    3001: msg_ssr_flag_high_level
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
  message:
    seq:
      - id: header
        type: sbp_header
      - id: payload
        size: header.length
        type:
          switch-on: header.msg_type
          cases:

  
            'msg_ids::msg_acq_result': acquisition::msg_acq_result
            'msg_ids::msg_acq_result_dep_c': acquisition::msg_acq_result_dep_c
            'msg_ids::msg_acq_result_dep_b': acquisition::msg_acq_result_dep_b
            'msg_ids::msg_acq_result_dep_a': acquisition::msg_acq_result_dep_a
            'msg_ids::msg_acq_sv_profile': acquisition::msg_acq_sv_profile
            'msg_ids::msg_acq_sv_profile_dep': acquisition::msg_acq_sv_profile_dep
  
            'msg_ids::msg_bootloader_handshake_req': bootload::msg_bootloader_handshake_req
            'msg_ids::msg_bootloader_handshake_resp': bootload::msg_bootloader_handshake_resp
            'msg_ids::msg_bootloader_jump_to_app': bootload::msg_bootloader_jump_to_app
            'msg_ids::msg_nap_device_dna_req': bootload::msg_nap_device_dna_req
            'msg_ids::msg_nap_device_dna_resp': bootload::msg_nap_device_dna_resp
            'msg_ids::msg_bootloader_handshake_dep_a': bootload::msg_bootloader_handshake_dep_a
  
            'msg_ids::msg_ext_event': ext_events::msg_ext_event
  
            'msg_ids::msg_fileio_read_req': file_io::msg_fileio_read_req
            'msg_ids::msg_fileio_read_resp': file_io::msg_fileio_read_resp
            'msg_ids::msg_fileio_read_dir_req': file_io::msg_fileio_read_dir_req
            'msg_ids::msg_fileio_read_dir_resp': file_io::msg_fileio_read_dir_resp
            'msg_ids::msg_fileio_remove': file_io::msg_fileio_remove
            'msg_ids::msg_fileio_write_req': file_io::msg_fileio_write_req
            'msg_ids::msg_fileio_write_resp': file_io::msg_fileio_write_resp
            'msg_ids::msg_fileio_config_req': file_io::msg_fileio_config_req
            'msg_ids::msg_fileio_config_resp': file_io::msg_fileio_config_resp
  
            'msg_ids::msg_flash_program': flash::msg_flash_program
            'msg_ids::msg_flash_done': flash::msg_flash_done
            'msg_ids::msg_flash_read_req': flash::msg_flash_read_req
            'msg_ids::msg_flash_read_resp': flash::msg_flash_read_resp
            'msg_ids::msg_flash_erase': flash::msg_flash_erase
            'msg_ids::msg_stm_flash_lock_sector': flash::msg_stm_flash_lock_sector
            'msg_ids::msg_stm_flash_unlock_sector': flash::msg_stm_flash_unlock_sector
            'msg_ids::msg_stm_unique_id_req': flash::msg_stm_unique_id_req
            'msg_ids::msg_stm_unique_id_resp': flash::msg_stm_unique_id_resp
            'msg_ids::msg_m25_flash_write_status': flash::msg_m25_flash_write_status
  
  
            'msg_ids::msg_imu_raw': imu::msg_imu_raw
            'msg_ids::msg_imu_aux': imu::msg_imu_aux
  
            'msg_ids::msg_ssr_flag_high_level': integrity::msg_ssr_flag_high_level
            'msg_ids::msg_ssr_flag_satellites': integrity::msg_ssr_flag_satellites
            'msg_ids::msg_ssr_flag_tropo_grid_points': integrity::msg_ssr_flag_tropo_grid_points
            'msg_ids::msg_ssr_flag_iono_grid_points': integrity::msg_ssr_flag_iono_grid_points
            'msg_ids::msg_ssr_flag_iono_tile_sat_los': integrity::msg_ssr_flag_iono_tile_sat_los
            'msg_ids::msg_ssr_flag_iono_grid_point_sat_los': integrity::msg_ssr_flag_iono_grid_point_sat_los
            'msg_ids::msg_acknowledge': integrity::msg_acknowledge
  
            'msg_ids::msg_linux_cpu_state_dep_a': linux::msg_linux_cpu_state_dep_a
            'msg_ids::msg_linux_mem_state_dep_a': linux::msg_linux_mem_state_dep_a
            'msg_ids::msg_linux_sys_state_dep_a': linux::msg_linux_sys_state_dep_a
            'msg_ids::msg_linux_process_socket_counts': linux::msg_linux_process_socket_counts
            'msg_ids::msg_linux_process_socket_queues': linux::msg_linux_process_socket_queues
            'msg_ids::msg_linux_socket_usage': linux::msg_linux_socket_usage
            'msg_ids::msg_linux_process_fd_count': linux::msg_linux_process_fd_count
            'msg_ids::msg_linux_process_fd_summary': linux::msg_linux_process_fd_summary
            'msg_ids::msg_linux_cpu_state': linux::msg_linux_cpu_state
            'msg_ids::msg_linux_mem_state': linux::msg_linux_mem_state
            'msg_ids::msg_linux_sys_state': linux::msg_linux_sys_state
  
            'msg_ids::msg_log': logging::msg_log
            'msg_ids::msg_fwd': logging::msg_fwd
            'msg_ids::msg_print_dep': logging::msg_print_dep
  
            'msg_ids::msg_mag_raw': mag::msg_mag_raw
  
            'msg_ids::msg_gps_time': navigation::msg_gps_time
            'msg_ids::msg_gps_time_gnss': navigation::msg_gps_time_gnss
            'msg_ids::msg_utc_time': navigation::msg_utc_time
            'msg_ids::msg_utc_time_gnss': navigation::msg_utc_time_gnss
            'msg_ids::msg_dops': navigation::msg_dops
            'msg_ids::msg_pos_ecef': navigation::msg_pos_ecef
            'msg_ids::msg_pos_ecef_cov': navigation::msg_pos_ecef_cov
            'msg_ids::msg_pos_llh': navigation::msg_pos_llh
            'msg_ids::msg_pos_llh_cov': navigation::msg_pos_llh_cov
            'msg_ids::msg_pos_llh_acc': navigation::msg_pos_llh_acc
            'msg_ids::msg_baseline_ecef': navigation::msg_baseline_ecef
            'msg_ids::msg_baseline_ned': navigation::msg_baseline_ned
            'msg_ids::msg_vel_ecef': navigation::msg_vel_ecef
            'msg_ids::msg_vel_ecef_cov': navigation::msg_vel_ecef_cov
            'msg_ids::msg_vel_ned': navigation::msg_vel_ned
            'msg_ids::msg_vel_ned_cov': navigation::msg_vel_ned_cov
            'msg_ids::msg_pos_ecef_gnss': navigation::msg_pos_ecef_gnss
            'msg_ids::msg_pos_ecef_cov_gnss': navigation::msg_pos_ecef_cov_gnss
            'msg_ids::msg_pos_llh_gnss': navigation::msg_pos_llh_gnss
            'msg_ids::msg_pos_llh_cov_gnss': navigation::msg_pos_llh_cov_gnss
            'msg_ids::msg_vel_ecef_gnss': navigation::msg_vel_ecef_gnss
            'msg_ids::msg_vel_ecef_cov_gnss': navigation::msg_vel_ecef_cov_gnss
            'msg_ids::msg_vel_ned_gnss': navigation::msg_vel_ned_gnss
            'msg_ids::msg_vel_ned_cov_gnss': navigation::msg_vel_ned_cov_gnss
            'msg_ids::msg_vel_body': navigation::msg_vel_body
            'msg_ids::msg_vel_cog': navigation::msg_vel_cog
            'msg_ids::msg_age_corrections': navigation::msg_age_corrections
            'msg_ids::msg_gps_time_dep_a': navigation::msg_gps_time_dep_a
            'msg_ids::msg_dops_dep_a': navigation::msg_dops_dep_a
            'msg_ids::msg_pos_ecef_dep_a': navigation::msg_pos_ecef_dep_a
            'msg_ids::msg_pos_llh_dep_a': navigation::msg_pos_llh_dep_a
            'msg_ids::msg_baseline_ecef_dep_a': navigation::msg_baseline_ecef_dep_a
            'msg_ids::msg_baseline_ned_dep_a': navigation::msg_baseline_ned_dep_a
            'msg_ids::msg_vel_ecef_dep_a': navigation::msg_vel_ecef_dep_a
            'msg_ids::msg_vel_ned_dep_a': navigation::msg_vel_ned_dep_a
            'msg_ids::msg_baseline_heading_dep_a': navigation::msg_baseline_heading_dep_a
            'msg_ids::msg_protection_level_dep_a': navigation::msg_protection_level_dep_a
            'msg_ids::msg_protection_level': navigation::msg_protection_level
            'msg_ids::msg_utc_leap_second': navigation::msg_utc_leap_second
            'msg_ids::msg_reference_frame_param': navigation::msg_reference_frame_param
            'msg_ids::msg_pose_relative': navigation::msg_pose_relative
  
            'msg_ids::msg_ndb_event': ndb::msg_ndb_event
  
            'msg_ids::msg_obs': observation::msg_obs
            'msg_ids::msg_base_pos_llh': observation::msg_base_pos_llh
            'msg_ids::msg_base_pos_ecef': observation::msg_base_pos_ecef
            'msg_ids::msg_ephemeris_gps_dep_e': observation::msg_ephemeris_gps_dep_e
            'msg_ids::msg_ephemeris_gps_dep_f': observation::msg_ephemeris_gps_dep_f
            'msg_ids::msg_ephemeris_gps': observation::msg_ephemeris_gps
            'msg_ids::msg_ephemeris_qzss': observation::msg_ephemeris_qzss
            'msg_ids::msg_ephemeris_bds': observation::msg_ephemeris_bds
            'msg_ids::msg_ephemeris_gal_dep_a': observation::msg_ephemeris_gal_dep_a
            'msg_ids::msg_ephemeris_gal': observation::msg_ephemeris_gal
            'msg_ids::msg_ephemeris_sbas_dep_a': observation::msg_ephemeris_sbas_dep_a
            'msg_ids::msg_ephemeris_glo_dep_a': observation::msg_ephemeris_glo_dep_a
            'msg_ids::msg_ephemeris_sbas_dep_b': observation::msg_ephemeris_sbas_dep_b
            'msg_ids::msg_ephemeris_sbas': observation::msg_ephemeris_sbas
            'msg_ids::msg_ephemeris_glo_dep_b': observation::msg_ephemeris_glo_dep_b
            'msg_ids::msg_ephemeris_glo_dep_c': observation::msg_ephemeris_glo_dep_c
            'msg_ids::msg_ephemeris_glo_dep_d': observation::msg_ephemeris_glo_dep_d
            'msg_ids::msg_ephemeris_glo': observation::msg_ephemeris_glo
            'msg_ids::msg_ephemeris_dep_d': observation::msg_ephemeris_dep_d
            'msg_ids::msg_ephemeris_dep_a': observation::msg_ephemeris_dep_a
            'msg_ids::msg_ephemeris_dep_b': observation::msg_ephemeris_dep_b
            'msg_ids::msg_ephemeris_dep_c': observation::msg_ephemeris_dep_c
            'msg_ids::msg_obs_dep_a': observation::msg_obs_dep_a
            'msg_ids::msg_obs_dep_b': observation::msg_obs_dep_b
            'msg_ids::msg_obs_dep_c': observation::msg_obs_dep_c
            'msg_ids::msg_iono': observation::msg_iono
            'msg_ids::msg_sv_configuration_gps_dep': observation::msg_sv_configuration_gps_dep
            'msg_ids::msg_gnss_capb': observation::msg_gnss_capb
            'msg_ids::msg_group_delay_dep_a': observation::msg_group_delay_dep_a
            'msg_ids::msg_group_delay_dep_b': observation::msg_group_delay_dep_b
            'msg_ids::msg_group_delay': observation::msg_group_delay
            'msg_ids::msg_almanac_gps_dep': observation::msg_almanac_gps_dep
            'msg_ids::msg_almanac_gps': observation::msg_almanac_gps
            'msg_ids::msg_almanac_glo_dep': observation::msg_almanac_glo_dep
            'msg_ids::msg_almanac_glo': observation::msg_almanac_glo
            'msg_ids::msg_glo_biases': observation::msg_glo_biases
            'msg_ids::msg_sv_az_el': observation::msg_sv_az_el
            'msg_ids::msg_osr': observation::msg_osr
  
            'msg_ids::msg_baseline_heading': orientation::msg_baseline_heading
            'msg_ids::msg_orient_quat': orientation::msg_orient_quat
            'msg_ids::msg_orient_euler': orientation::msg_orient_euler
            'msg_ids::msg_angular_rate': orientation::msg_angular_rate
  
            'msg_ids::msg_almanac': piksi::msg_almanac
            'msg_ids::msg_set_time': piksi::msg_set_time
            'msg_ids::msg_reset': piksi::msg_reset
            'msg_ids::msg_reset_dep': piksi::msg_reset_dep
            'msg_ids::msg_cw_results': piksi::msg_cw_results
            'msg_ids::msg_cw_start': piksi::msg_cw_start
            'msg_ids::msg_reset_filters': piksi::msg_reset_filters
            'msg_ids::msg_init_base_dep': piksi::msg_init_base_dep
            'msg_ids::msg_thread_state': piksi::msg_thread_state
            'msg_ids::msg_uart_state': piksi::msg_uart_state
            'msg_ids::msg_uart_state_depa': piksi::msg_uart_state_depa
            'msg_ids::msg_iar_state': piksi::msg_iar_state
            'msg_ids::msg_mask_satellite': piksi::msg_mask_satellite
            'msg_ids::msg_mask_satellite_dep': piksi::msg_mask_satellite_dep
            'msg_ids::msg_device_monitor': piksi::msg_device_monitor
            'msg_ids::msg_command_req': piksi::msg_command_req
            'msg_ids::msg_command_resp': piksi::msg_command_resp
            'msg_ids::msg_command_output': piksi::msg_command_output
            'msg_ids::msg_network_state_req': piksi::msg_network_state_req
            'msg_ids::msg_network_state_resp': piksi::msg_network_state_resp
            'msg_ids::msg_network_bandwidth_usage': piksi::msg_network_bandwidth_usage
            'msg_ids::msg_cell_modem_status': piksi::msg_cell_modem_status
            'msg_ids::msg_specan_dep': piksi::msg_specan_dep
            'msg_ids::msg_specan': piksi::msg_specan
            'msg_ids::msg_front_end_gain': piksi::msg_front_end_gain
  
            'msg_ids::msg_sbas_raw': sbas::msg_sbas_raw
  
            'msg_ids::msg_settings_save': settings::msg_settings_save
            'msg_ids::msg_settings_write': settings::msg_settings_write
            'msg_ids::msg_settings_write_resp': settings::msg_settings_write_resp
            'msg_ids::msg_settings_read_req': settings::msg_settings_read_req
            'msg_ids::msg_settings_read_resp': settings::msg_settings_read_resp
            'msg_ids::msg_settings_read_by_index_req': settings::msg_settings_read_by_index_req
            'msg_ids::msg_settings_read_by_index_resp': settings::msg_settings_read_by_index_resp
            'msg_ids::msg_settings_read_by_index_done': settings::msg_settings_read_by_index_done
            'msg_ids::msg_settings_register': settings::msg_settings_register
            'msg_ids::msg_settings_register_resp': settings::msg_settings_register_resp
  
            'msg_ids::msg_ecdsa_certificate': signing::msg_ecdsa_certificate
            'msg_ids::msg_certificate_chain': signing::msg_certificate_chain
            'msg_ids::msg_certificate_chain_dep': signing::msg_certificate_chain_dep
            'msg_ids::msg_ecdsa_signature': signing::msg_ecdsa_signature
            'msg_ids::msg_ecdsa_signature_dep_b': signing::msg_ecdsa_signature_dep_b
            'msg_ids::msg_ecdsa_signature_dep_a': signing::msg_ecdsa_signature_dep_a
            'msg_ids::msg_ed25519_certificate_dep': signing::msg_ed25519_certificate_dep
            'msg_ids::msg_ed25519_signature_dep_a': signing::msg_ed25519_signature_dep_a
            'msg_ids::msg_ed25519_signature_dep_b': signing::msg_ed25519_signature_dep_b
  
            'msg_ids::msg_soln_meta_dep_a': solution_meta::msg_soln_meta_dep_a
            'msg_ids::msg_soln_meta': solution_meta::msg_soln_meta
  
            'msg_ids::msg_ssr_orbit_clock': ssr::msg_ssr_orbit_clock
            'msg_ids::msg_ssr_code_biases': ssr::msg_ssr_code_biases
            'msg_ids::msg_ssr_phase_biases': ssr::msg_ssr_phase_biases
            'msg_ids::msg_ssr_stec_correction_dep': ssr::msg_ssr_stec_correction_dep
            'msg_ids::msg_ssr_stec_correction': ssr::msg_ssr_stec_correction
            'msg_ids::msg_ssr_gridded_correction': ssr::msg_ssr_gridded_correction
            'msg_ids::msg_ssr_gridded_correction_bounds': ssr::msg_ssr_gridded_correction_bounds
            'msg_ids::msg_ssr_tile_definition_dep_a': ssr::msg_ssr_tile_definition_dep_a
            'msg_ids::msg_ssr_tile_definition_dep_b': ssr::msg_ssr_tile_definition_dep_b
            'msg_ids::msg_ssr_tile_definition': ssr::msg_ssr_tile_definition
            'msg_ids::msg_ssr_satellite_apc_dep': ssr::msg_ssr_satellite_apc_dep
            'msg_ids::msg_ssr_satellite_apc': ssr::msg_ssr_satellite_apc
            'msg_ids::msg_ssr_orbit_clock_dep_a': ssr::msg_ssr_orbit_clock_dep_a
            'msg_ids::msg_ssr_stec_correction_dep_a': ssr::msg_ssr_stec_correction_dep_a
            'msg_ids::msg_ssr_gridded_correction_no_std_dep_a': ssr::msg_ssr_gridded_correction_no_std_dep_a
            'msg_ids::msg_ssr_gridded_correction_dep_a': ssr::msg_ssr_gridded_correction_dep_a
            'msg_ids::msg_ssr_grid_definition_dep_a': ssr::msg_ssr_grid_definition_dep_a
            'msg_ids::msg_ssr_orbit_clock_bounds': ssr::msg_ssr_orbit_clock_bounds
            'msg_ids::msg_ssr_code_phase_biases_bounds': ssr::msg_ssr_code_phase_biases_bounds
            'msg_ids::msg_ssr_orbit_clock_bounds_degradation': ssr::msg_ssr_orbit_clock_bounds_degradation
  
            'msg_ids::msg_startup': system::msg_startup
            'msg_ids::msg_dgnss_status': system::msg_dgnss_status
            'msg_ids::msg_heartbeat': system::msg_heartbeat
            'msg_ids::msg_status_report': system::msg_status_report
            'msg_ids::msg_status_journal': system::msg_status_journal
            'msg_ids::msg_ins_status': system::msg_ins_status
            'msg_ids::msg_csac_telemetry': system::msg_csac_telemetry
            'msg_ids::msg_csac_telemetry_labels': system::msg_csac_telemetry_labels
            'msg_ids::msg_ins_updates': system::msg_ins_updates
            'msg_ids::msg_gnss_time_offset': system::msg_gnss_time_offset
            'msg_ids::msg_pps_time': system::msg_pps_time
            'msg_ids::msg_sensor_aid_event': system::msg_sensor_aid_event
            'msg_ids::msg_group_meta': system::msg_group_meta
  
            'msg_ids::msg_tel_sv': telemetry::msg_tel_sv
  
            'msg_ids::msg_tracking_state_detailed_dep_a': tracking::msg_tracking_state_detailed_dep_a
            'msg_ids::msg_tracking_state_detailed_dep': tracking::msg_tracking_state_detailed_dep
            'msg_ids::msg_tracking_state': tracking::msg_tracking_state
            'msg_ids::msg_measurement_state': tracking::msg_measurement_state
            'msg_ids::msg_tracking_iq': tracking::msg_tracking_iq
            'msg_ids::msg_tracking_iq_dep_b': tracking::msg_tracking_iq_dep_b
            'msg_ids::msg_tracking_iq_dep_a': tracking::msg_tracking_iq_dep_a
            'msg_ids::msg_tracking_state_dep_a': tracking::msg_tracking_state_dep_a
            'msg_ids::msg_tracking_state_dep_b': tracking::msg_tracking_state_dep_b
  
            'msg_ids::msg_user_data': user::msg_user_data
  
            'msg_ids::msg_odometry': vehicle::msg_odometry
            'msg_ids::msg_wheeltick': vehicle::msg_wheeltick
      - id: crc
        type: u2
  sbp_header:
    seq:
      - id: preamble
        contents: [0x55]
      - id: msg_type
        type: u2
        enum: msg_ids
      - id: sender
        type: u2
      - id: length
        type: u1
