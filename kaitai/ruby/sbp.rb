# This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

require 'kaitai/struct/struct'

unless Gem::Version.new(Kaitai::Struct::VERSION) >= Gem::Version.new('0.9')
  raise "Incompatible Kaitai Struct Ruby API: 0.9 or later is required, but you have #{Kaitai::Struct::VERSION}"
end

class Sbp < Kaitai::Struct::Struct

  MSG_IDS = {
    16 => :msg_ids_msg_print_dep,
    17 => :msg_ids_msg_tracking_state_detailed_dep,
    19 => :msg_ids_msg_tracking_state_dep_b,
    20 => :msg_ids_msg_acq_result_dep_b,
    21 => :msg_ids_msg_acq_result_dep_a,
    22 => :msg_ids_msg_tracking_state_dep_a,
    23 => :msg_ids_msg_thread_state,
    24 => :msg_ids_msg_uart_state_depa,
    25 => :msg_ids_msg_iar_state,
    26 => :msg_ids_msg_ephemeris_dep_a,
    27 => :msg_ids_msg_mask_satellite_dep,
    28 => :msg_ids_msg_tracking_iq_dep_a,
    29 => :msg_ids_msg_uart_state,
    30 => :msg_ids_msg_acq_sv_profile_dep,
    31 => :msg_ids_msg_acq_result_dep_c,
    33 => :msg_ids_msg_tracking_state_detailed_dep_a,
    34 => :msg_ids_msg_reset_filters,
    35 => :msg_ids_msg_init_base_dep,
    43 => :msg_ids_msg_mask_satellite,
    44 => :msg_ids_msg_tracking_iq_dep_b,
    45 => :msg_ids_msg_tracking_iq,
    46 => :msg_ids_msg_acq_sv_profile,
    47 => :msg_ids_msg_acq_result,
    65 => :msg_ids_msg_tracking_state,
    67 => :msg_ids_msg_obs_dep_b,
    68 => :msg_ids_msg_base_pos_llh,
    69 => :msg_ids_msg_obs_dep_a,
    70 => :msg_ids_msg_ephemeris_dep_b,
    71 => :msg_ids_msg_ephemeris_dep_c,
    72 => :msg_ids_msg_base_pos_ecef,
    73 => :msg_ids_msg_obs_dep_c,
    74 => :msg_ids_msg_obs,
    80 => :msg_ids_msg_specan_dep,
    81 => :msg_ids_msg_specan,
    97 => :msg_ids_msg_measurement_state,
    104 => :msg_ids_msg_set_time,
    105 => :msg_ids_msg_almanac,
    112 => :msg_ids_msg_almanac_gps_dep,
    113 => :msg_ids_msg_almanac_glo_dep,
    114 => :msg_ids_msg_almanac_gps,
    115 => :msg_ids_msg_almanac_glo,
    117 => :msg_ids_msg_glo_biases,
    128 => :msg_ids_msg_ephemeris_dep_d,
    129 => :msg_ids_msg_ephemeris_gps_dep_e,
    130 => :msg_ids_msg_ephemeris_sbas_dep_a,
    131 => :msg_ids_msg_ephemeris_glo_dep_a,
    132 => :msg_ids_msg_ephemeris_sbas_dep_b,
    133 => :msg_ids_msg_ephemeris_glo_dep_b,
    134 => :msg_ids_msg_ephemeris_gps_dep_f,
    135 => :msg_ids_msg_ephemeris_glo_dep_c,
    136 => :msg_ids_msg_ephemeris_glo_dep_d,
    137 => :msg_ids_msg_ephemeris_bds,
    138 => :msg_ids_msg_ephemeris_gps,
    139 => :msg_ids_msg_ephemeris_glo,
    140 => :msg_ids_msg_ephemeris_sbas,
    141 => :msg_ids_msg_ephemeris_gal,
    142 => :msg_ids_msg_ephemeris_qzss,
    144 => :msg_ids_msg_iono,
    145 => :msg_ids_msg_sv_configuration_gps_dep,
    146 => :msg_ids_msg_group_delay_dep_a,
    147 => :msg_ids_msg_group_delay_dep_b,
    148 => :msg_ids_msg_group_delay,
    149 => :msg_ids_msg_ephemeris_gal_dep_a,
    150 => :msg_ids_msg_gnss_capb,
    151 => :msg_ids_msg_sv_az_el,
    160 => :msg_ids_msg_settings_write,
    161 => :msg_ids_msg_settings_save,
    162 => :msg_ids_msg_settings_read_by_index_req,
    163 => :msg_ids_msg_fileio_read_resp,
    164 => :msg_ids_msg_settings_read_req,
    165 => :msg_ids_msg_settings_read_resp,
    166 => :msg_ids_msg_settings_read_by_index_done,
    167 => :msg_ids_msg_settings_read_by_index_resp,
    168 => :msg_ids_msg_fileio_read_req,
    169 => :msg_ids_msg_fileio_read_dir_req,
    170 => :msg_ids_msg_fileio_read_dir_resp,
    171 => :msg_ids_msg_fileio_write_resp,
    172 => :msg_ids_msg_fileio_remove,
    173 => :msg_ids_msg_fileio_write_req,
    174 => :msg_ids_msg_settings_register,
    175 => :msg_ids_msg_settings_write_resp,
    176 => :msg_ids_msg_bootloader_handshake_dep_a,
    177 => :msg_ids_msg_bootloader_jump_to_app,
    178 => :msg_ids_msg_reset_dep,
    179 => :msg_ids_msg_bootloader_handshake_req,
    180 => :msg_ids_msg_bootloader_handshake_resp,
    181 => :msg_ids_msg_device_monitor,
    182 => :msg_ids_msg_reset,
    184 => :msg_ids_msg_command_req,
    185 => :msg_ids_msg_command_resp,
    186 => :msg_ids_msg_network_state_req,
    187 => :msg_ids_msg_network_state_resp,
    188 => :msg_ids_msg_command_output,
    189 => :msg_ids_msg_network_bandwidth_usage,
    190 => :msg_ids_msg_cell_modem_status,
    191 => :msg_ids_msg_front_end_gain,
    192 => :msg_ids_msg_cw_results,
    193 => :msg_ids_msg_cw_start,
    221 => :msg_ids_msg_nap_device_dna_resp,
    222 => :msg_ids_msg_nap_device_dna_req,
    224 => :msg_ids_msg_flash_done,
    225 => :msg_ids_msg_flash_read_resp,
    226 => :msg_ids_msg_flash_erase,
    227 => :msg_ids_msg_stm_flash_lock_sector,
    228 => :msg_ids_msg_stm_flash_unlock_sector,
    229 => :msg_ids_msg_stm_unique_id_resp,
    230 => :msg_ids_msg_flash_program,
    231 => :msg_ids_msg_flash_read_req,
    232 => :msg_ids_msg_stm_unique_id_req,
    243 => :msg_ids_msg_m25_flash_write_status,
    256 => :msg_ids_msg_gps_time_dep_a,
    257 => :msg_ids_msg_ext_event,
    258 => :msg_ids_msg_gps_time,
    259 => :msg_ids_msg_utc_time,
    260 => :msg_ids_msg_gps_time_gnss,
    261 => :msg_ids_msg_utc_time_gnss,
    288 => :msg_ids_msg_tel_sv,
    431 => :msg_ids_msg_settings_register_resp,
    512 => :msg_ids_msg_pos_ecef_dep_a,
    513 => :msg_ids_msg_pos_llh_dep_a,
    514 => :msg_ids_msg_baseline_ecef_dep_a,
    515 => :msg_ids_msg_baseline_ned_dep_a,
    516 => :msg_ids_msg_vel_ecef_dep_a,
    517 => :msg_ids_msg_vel_ned_dep_a,
    518 => :msg_ids_msg_dops_dep_a,
    519 => :msg_ids_msg_baseline_heading_dep_a,
    520 => :msg_ids_msg_dops,
    521 => :msg_ids_msg_pos_ecef,
    522 => :msg_ids_msg_pos_llh,
    523 => :msg_ids_msg_baseline_ecef,
    524 => :msg_ids_msg_baseline_ned,
    525 => :msg_ids_msg_vel_ecef,
    526 => :msg_ids_msg_vel_ned,
    527 => :msg_ids_msg_baseline_heading,
    528 => :msg_ids_msg_age_corrections,
    529 => :msg_ids_msg_pos_llh_cov,
    530 => :msg_ids_msg_vel_ned_cov,
    531 => :msg_ids_msg_vel_body,
    532 => :msg_ids_msg_pos_ecef_cov,
    533 => :msg_ids_msg_vel_ecef_cov,
    534 => :msg_ids_msg_protection_level_dep_a,
    535 => :msg_ids_msg_protection_level,
    536 => :msg_ids_msg_pos_llh_acc,
    540 => :msg_ids_msg_vel_cog,
    544 => :msg_ids_msg_orient_quat,
    545 => :msg_ids_msg_orient_euler,
    546 => :msg_ids_msg_angular_rate,
    553 => :msg_ids_msg_pos_ecef_gnss,
    554 => :msg_ids_msg_pos_llh_gnss,
    557 => :msg_ids_msg_vel_ecef_gnss,
    558 => :msg_ids_msg_vel_ned_gnss,
    561 => :msg_ids_msg_pos_llh_cov_gnss,
    562 => :msg_ids_msg_vel_ned_cov_gnss,
    564 => :msg_ids_msg_pos_ecef_cov_gnss,
    565 => :msg_ids_msg_vel_ecef_cov_gnss,
    570 => :msg_ids_msg_utc_leap_second,
    580 => :msg_ids_msg_reference_frame_param,
    581 => :msg_ids_msg_pose_relative,
    1024 => :msg_ids_msg_ndb_event,
    1025 => :msg_ids_msg_log,
    1026 => :msg_ids_msg_fwd,
    1500 => :msg_ids_msg_ssr_orbit_clock_dep_a,
    1501 => :msg_ids_msg_ssr_orbit_clock,
    1502 => :msg_ids_msg_ssr_orbit_clock_bounds,
    1503 => :msg_ids_msg_ssr_orbit_clock_bounds_degradation,
    1505 => :msg_ids_msg_ssr_code_biases,
    1510 => :msg_ids_msg_ssr_phase_biases,
    1515 => :msg_ids_msg_ssr_stec_correction_dep_a,
    1516 => :msg_ids_msg_ssr_code_phase_biases_bounds,
    1520 => :msg_ids_msg_ssr_gridded_correction_no_std_dep_a,
    1525 => :msg_ids_msg_ssr_grid_definition_dep_a,
    1526 => :msg_ids_msg_ssr_tile_definition_dep_a,
    1527 => :msg_ids_msg_ssr_tile_definition_dep_b,
    1528 => :msg_ids_msg_ssr_tile_definition,
    1530 => :msg_ids_msg_ssr_gridded_correction_dep_a,
    1531 => :msg_ids_msg_ssr_stec_correction_dep,
    1532 => :msg_ids_msg_ssr_gridded_correction,
    1533 => :msg_ids_msg_ssr_stec_correction,
    1534 => :msg_ids_msg_ssr_gridded_correction_bounds,
    1540 => :msg_ids_msg_ssr_satellite_apc_dep,
    1541 => :msg_ids_msg_ssr_satellite_apc,
    1600 => :msg_ids_msg_osr,
    2048 => :msg_ids_msg_user_data,
    2304 => :msg_ids_msg_imu_raw,
    2305 => :msg_ids_msg_imu_aux,
    2306 => :msg_ids_msg_mag_raw,
    2307 => :msg_ids_msg_odometry,
    2308 => :msg_ids_msg_wheeltick,
    3001 => :msg_ids_msg_ssr_flag_high_level,
    3005 => :msg_ids_msg_ssr_flag_satellites,
    3011 => :msg_ids_msg_ssr_flag_tropo_grid_points,
    3015 => :msg_ids_msg_ssr_flag_iono_grid_points,
    3021 => :msg_ids_msg_ssr_flag_iono_tile_sat_los,
    3025 => :msg_ids_msg_ssr_flag_iono_grid_point_sat_los,
    3026 => :msg_ids_msg_acknowledge,
    3073 => :msg_ids_msg_ed25519_signature_dep_a,
    3074 => :msg_ids_msg_ed25519_certificate_dep,
    3075 => :msg_ids_msg_ed25519_signature_dep_b,
    3076 => :msg_ids_msg_ecdsa_certificate,
    3077 => :msg_ids_msg_certificate_chain,
    3078 => :msg_ids_msg_ecdsa_signature,
    4097 => :msg_ids_msg_fileio_config_req,
    4098 => :msg_ids_msg_fileio_config_resp,
    30583 => :msg_ids_msg_sbas_raw,
    32512 => :msg_ids_msg_linux_cpu_state_dep_a,
    32513 => :msg_ids_msg_linux_mem_state_dep_a,
    32514 => :msg_ids_msg_linux_sys_state_dep_a,
    32515 => :msg_ids_msg_linux_process_socket_counts,
    32516 => :msg_ids_msg_linux_process_socket_queues,
    32517 => :msg_ids_msg_linux_socket_usage,
    32518 => :msg_ids_msg_linux_process_fd_count,
    32519 => :msg_ids_msg_linux_process_fd_summary,
    32520 => :msg_ids_msg_linux_cpu_state,
    32521 => :msg_ids_msg_linux_mem_state,
    32522 => :msg_ids_msg_linux_sys_state,
    65280 => :msg_ids_msg_startup,
    65282 => :msg_ids_msg_dgnss_status,
    65283 => :msg_ids_msg_ins_status,
    65284 => :msg_ids_msg_csac_telemetry,
    65285 => :msg_ids_msg_csac_telemetry_labels,
    65286 => :msg_ids_msg_ins_updates,
    65287 => :msg_ids_msg_gnss_time_offset,
    65288 => :msg_ids_msg_pps_time,
    65289 => :msg_ids_msg_sensor_aid_event,
    65290 => :msg_ids_msg_group_meta,
    65294 => :msg_ids_msg_soln_meta,
    65295 => :msg_ids_msg_soln_meta_dep_a,
    65533 => :msg_ids_msg_status_journal,
    65534 => :msg_ids_msg_status_report,
    65535 => :msg_ids_msg_heartbeat,
  }
  I__MSG_IDS = MSG_IDS.invert
  def initialize(_io, _parent = nil, _root = self)
    super(_io, _parent, _root)
    _read
  end

  def _read
    @message = []
    i = 0
    while not @_io.eof?
      @message << Message.new(@_io, self, @_root)
      i += 1
    end
    self
  end
  class Message < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @header = SbpHeader.new(@_io, self, @_root)
      case header.msg_type
      when :msg_ids_msg_baseline_ecef
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Navigation::MsgBaselineEcef.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_ephemeris_bds
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Observation::MsgEphemerisBds.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_ephemeris_glo_dep_d
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Observation::MsgEphemerisGloDepD.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_settings_read_by_index_req
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Settings::MsgSettingsReadByIndexReq.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_ssr_flag_high_level
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Integrity::MsgSsrFlagHighLevel.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_fileio_config_req
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = FileIo::MsgFileioConfigReq.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_odometry
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Vehicle::MsgOdometry.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_ssr_stec_correction_dep
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Ssr::MsgSsrStecCorrectionDep.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_ed25519_signature_dep_b
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Signing::MsgEd25519SignatureDepB.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_stm_unique_id_req
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Flash::MsgStmUniqueIdReq.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_front_end_gain
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Piksi::MsgFrontEndGain.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_base_pos_llh
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Observation::MsgBasePosLlh.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_ephemeris_dep_a
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Observation::MsgEphemerisDepA.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_ssr_orbit_clock
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Ssr::MsgSsrOrbitClock.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_reset
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Piksi::MsgReset.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_stm_flash_lock_sector
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Flash::MsgStmFlashLockSector.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_linux_process_fd_summary
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Linux::MsgLinuxProcessFdSummary.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_status_journal
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = System::MsgStatusJournal.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_csac_telemetry
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = System::MsgCsacTelemetry.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_age_corrections
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Navigation::MsgAgeCorrections.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_orient_euler
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Orientation::MsgOrientEuler.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_ssr_satellite_apc_dep
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Ssr::MsgSsrSatelliteApcDep.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_baseline_ned
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Navigation::MsgBaselineNed.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_vel_ecef_gnss
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Navigation::MsgVelEcefGnss.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_measurement_state
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Tracking::MsgMeasurementState.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_iono
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Observation::MsgIono.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_base_pos_ecef
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Observation::MsgBasePosEcef.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_flash_program
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Flash::MsgFlashProgram.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_acq_result
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Acquisition::MsgAcqResult.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_pps_time
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = System::MsgPpsTime.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_obs
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Observation::MsgObs.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_ephemeris_sbas_dep_b
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Observation::MsgEphemerisSbasDepB.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_tracking_iq
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Tracking::MsgTrackingIq.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_ssr_flag_iono_tile_sat_los
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Integrity::MsgSsrFlagIonoTileSatLos.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_tracking_state_detailed_dep
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Tracking::MsgTrackingStateDetailedDep.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_bootloader_handshake_dep_a
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Bootload::MsgBootloaderHandshakeDepA.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_utc_leap_second
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Navigation::MsgUtcLeapSecond.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_ssr_gridded_correction_no_std_dep_a
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Ssr::MsgSsrGriddedCorrectionNoStdDepA.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_bootloader_handshake_resp
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Bootload::MsgBootloaderHandshakeResp.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_baseline_heading
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Orientation::MsgBaselineHeading.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_status_report
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = System::MsgStatusReport.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_vel_ned_cov
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Navigation::MsgVelNedCov.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_set_time
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Piksi::MsgSetTime.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_linux_cpu_state
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Linux::MsgLinuxCpuState.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_gps_time_dep_a
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Navigation::MsgGpsTimeDepA.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_ephemeris_sbas_dep_a
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Observation::MsgEphemerisSbasDepA.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_acq_result_dep_b
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Acquisition::MsgAcqResultDepB.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_settings_register_resp
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Settings::MsgSettingsRegisterResp.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_ephemeris_gal
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Observation::MsgEphemerisGal.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_bootloader_jump_to_app
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Bootload::MsgBootloaderJumpToApp.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_ssr_phase_biases
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Ssr::MsgSsrPhaseBiases.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_fileio_read_dir_resp
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = FileIo::MsgFileioReadDirResp.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_pos_ecef_gnss
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Navigation::MsgPosEcefGnss.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_almanac_glo_dep
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Observation::MsgAlmanacGloDep.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_vel_ecef_dep_a
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Navigation::MsgVelEcefDepA.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_thread_state
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Piksi::MsgThreadState.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_gps_time
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Navigation::MsgGpsTime.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_ssr_code_phase_biases_bounds
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Ssr::MsgSsrCodePhaseBiasesBounds.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_settings_write_resp
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Settings::MsgSettingsWriteResp.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_tracking_state
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Tracking::MsgTrackingState.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_vel_ecef
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Navigation::MsgVelEcef.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_ephemeris_glo_dep_a
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Observation::MsgEphemerisGloDepA.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_ed25519_certificate_dep
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Signing::MsgEd25519CertificateDep.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_baseline_ned_dep_a
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Navigation::MsgBaselineNedDepA.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_specan_dep
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Piksi::MsgSpecanDep.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_ephemeris_sbas
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Observation::MsgEphemerisSbas.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_group_delay
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Observation::MsgGroupDelay.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_pos_ecef
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Navigation::MsgPosEcef.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_almanac
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Piksi::MsgAlmanac.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_settings_read_req
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Settings::MsgSettingsReadReq.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_ssr_flag_tropo_grid_points
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Integrity::MsgSsrFlagTropoGridPoints.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_ssr_gridded_correction_bounds
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Ssr::MsgSsrGriddedCorrectionBounds.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_stm_unique_id_resp
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Flash::MsgStmUniqueIdResp.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_tel_sv
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Telemetry::MsgTelSv.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_ssr_flag_satellites
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Integrity::MsgSsrFlagSatellites.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_imu_aux
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Imu::MsgImuAux.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_ssr_grid_definition_dep_a
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Ssr::MsgSsrGridDefinitionDepA.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_pos_llh_acc
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Navigation::MsgPosLlhAcc.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_sv_configuration_gps_dep
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Observation::MsgSvConfigurationGpsDep.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_linux_mem_state
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Linux::MsgLinuxMemState.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_linux_sys_state
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Linux::MsgLinuxSysState.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_settings_read_by_index_done
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Settings::MsgSettingsReadByIndexDone.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_reset_filters
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Piksi::MsgResetFilters.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_ecdsa_signature
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Signing::MsgEcdsaSignature.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_ephemeris_gps_dep_e
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Observation::MsgEphemerisGpsDepE.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_m25_flash_write_status
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Flash::MsgM25FlashWriteStatus.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_ephemeris_gps
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Observation::MsgEphemerisGps.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_command_output
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Piksi::MsgCommandOutput.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_ssr_flag_iono_grid_points
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Integrity::MsgSsrFlagIonoGridPoints.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_vel_ned_cov_gnss
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Navigation::MsgVelNedCovGnss.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_network_state_resp
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Piksi::MsgNetworkStateResp.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_ssr_stec_correction_dep_a
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Ssr::MsgSsrStecCorrectionDepA.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_command_req
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Piksi::MsgCommandReq.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_acknowledge
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Integrity::MsgAcknowledge.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_tracking_iq_dep_a
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Tracking::MsgTrackingIqDepA.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_ephemeris_gal_dep_a
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Observation::MsgEphemerisGalDepA.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_specan
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Piksi::MsgSpecan.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_acq_sv_profile_dep
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Acquisition::MsgAcqSvProfileDep.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_utc_time
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Navigation::MsgUtcTime.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_ephemeris_dep_d
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Observation::MsgEphemerisDepD.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_linux_process_socket_queues
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Linux::MsgLinuxProcessSocketQueues.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_utc_time_gnss
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Navigation::MsgUtcTimeGnss.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_ndb_event
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Ndb::MsgNdbEvent.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_bootloader_handshake_req
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Bootload::MsgBootloaderHandshakeReq.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_user_data
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = User::MsgUserData.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_sensor_aid_event
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = System::MsgSensorAidEvent.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_ssr_orbit_clock_bounds
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Ssr::MsgSsrOrbitClockBounds.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_pos_llh_gnss
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Navigation::MsgPosLlhGnss.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_init_base_dep
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Piksi::MsgInitBaseDep.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_fileio_read_req
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = FileIo::MsgFileioReadReq.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_tracking_iq_dep_b
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Tracking::MsgTrackingIqDepB.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_acq_result_dep_c
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Acquisition::MsgAcqResultDepC.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_command_resp
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Piksi::MsgCommandResp.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_fileio_remove
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = FileIo::MsgFileioRemove.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_obs_dep_c
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Observation::MsgObsDepC.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_ssr_tile_definition_dep_b
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Ssr::MsgSsrTileDefinitionDepB.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_csac_telemetry_labels
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = System::MsgCsacTelemetryLabels.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_vel_ned
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Navigation::MsgVelNed.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_settings_read_by_index_resp
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Settings::MsgSettingsReadByIndexResp.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_ephemeris_qzss
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Observation::MsgEphemerisQzss.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_ssr_stec_correction
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Ssr::MsgSsrStecCorrection.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_baseline_ecef_dep_a
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Navigation::MsgBaselineEcefDepA.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_ins_updates
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = System::MsgInsUpdates.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_pos_ecef_cov
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Navigation::MsgPosEcefCov.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_vel_ned_gnss
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Navigation::MsgVelNedGnss.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_mask_satellite
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Piksi::MsgMaskSatellite.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_group_delay_dep_b
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Observation::MsgGroupDelayDepB.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_ssr_orbit_clock_bounds_degradation
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Ssr::MsgSsrOrbitClockBoundsDegradation.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_flash_erase
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Flash::MsgFlashErase.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_cw_start
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Piksi::MsgCwStart.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_ssr_orbit_clock_dep_a
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Ssr::MsgSsrOrbitClockDepA.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_dops
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Navigation::MsgDops.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_network_bandwidth_usage
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Piksi::MsgNetworkBandwidthUsage.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_ecdsa_certificate
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Signing::MsgEcdsaCertificate.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_pos_llh_dep_a
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Navigation::MsgPosLlhDepA.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_sv_az_el
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Observation::MsgSvAzEl.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_fileio_read_dir_req
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = FileIo::MsgFileioReadDirReq.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_ephemeris_dep_b
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Observation::MsgEphemerisDepB.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_vel_ecef_cov
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Navigation::MsgVelEcefCov.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_dgnss_status
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = System::MsgDgnssStatus.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_ssr_tile_definition_dep_a
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Ssr::MsgSsrTileDefinitionDepA.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_log
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Logging::MsgLog.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_mask_satellite_dep
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Piksi::MsgMaskSatelliteDep.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_ext_event
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = ExtEvents::MsgExtEvent.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_cell_modem_status
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Piksi::MsgCellModemStatus.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_orient_quat
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Orientation::MsgOrientQuat.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_heartbeat
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = System::MsgHeartbeat.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_almanac_gps_dep
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Observation::MsgAlmanacGpsDep.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_nap_device_dna_req
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Bootload::MsgNapDeviceDnaReq.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_almanac_gps
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Observation::MsgAlmanacGps.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_vel_ecef_cov_gnss
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Navigation::MsgVelEcefCovGnss.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_ed25519_signature_dep_a
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Signing::MsgEd25519SignatureDepA.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_angular_rate
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Orientation::MsgAngularRate.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_vel_body
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Navigation::MsgVelBody.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_certificate_chain
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Signing::MsgCertificateChain.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_soln_meta_dep_a
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = SolutionMeta::MsgSolnMetaDepA.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_ssr_gridded_correction_dep_a
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Ssr::MsgSsrGriddedCorrectionDepA.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_ephemeris_glo_dep_c
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Observation::MsgEphemerisGloDepC.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_linux_process_fd_count
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Linux::MsgLinuxProcessFdCount.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_fileio_read_resp
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = FileIo::MsgFileioReadResp.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_linux_sys_state_dep_a
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Linux::MsgLinuxSysStateDepA.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_sbas_raw
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Sbas::MsgSbasRaw.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_pos_ecef_cov_gnss
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Navigation::MsgPosEcefCovGnss.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_ssr_flag_iono_grid_point_sat_los
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Integrity::MsgSsrFlagIonoGridPointSatLos.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_fileio_write_req
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = FileIo::MsgFileioWriteReq.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_acq_sv_profile
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Acquisition::MsgAcqSvProfile.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_ephemeris_glo_dep_b
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Observation::MsgEphemerisGloDepB.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_linux_socket_usage
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Linux::MsgLinuxSocketUsage.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_network_state_req
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Piksi::MsgNetworkStateReq.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_protection_level_dep_a
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Navigation::MsgProtectionLevelDepA.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_imu_raw
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Imu::MsgImuRaw.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_reset_dep
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Piksi::MsgResetDep.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_mag_raw
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Mag::MsgMagRaw.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_startup
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = System::MsgStartup.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_glo_biases
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Observation::MsgGloBiases.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_tracking_state_detailed_dep_a
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Tracking::MsgTrackingStateDetailedDepA.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_pos_llh_cov_gnss
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Navigation::MsgPosLlhCovGnss.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_settings_write
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Settings::MsgSettingsWrite.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_settings_save
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Settings::MsgSettingsSave.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_almanac_glo
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Observation::MsgAlmanacGlo.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_stm_flash_unlock_sector
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Flash::MsgStmFlashUnlockSector.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_gps_time_gnss
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Navigation::MsgGpsTimeGnss.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_flash_read_req
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Flash::MsgFlashReadReq.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_ephemeris_glo
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Observation::MsgEphemerisGlo.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_baseline_heading_dep_a
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Navigation::MsgBaselineHeadingDepA.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_settings_register
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Settings::MsgSettingsRegister.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_gnss_capb
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Observation::MsgGnssCapb.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_tracking_state_dep_b
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Tracking::MsgTrackingStateDepB.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_fwd
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Logging::MsgFwd.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_soln_meta
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = SolutionMeta::MsgSolnMeta.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_obs_dep_a
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Observation::MsgObsDepA.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_device_monitor
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Piksi::MsgDeviceMonitor.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_linux_process_socket_counts
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Linux::MsgLinuxProcessSocketCounts.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_vel_cog
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Navigation::MsgVelCog.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_print_dep
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Logging::MsgPrintDep.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_cw_results
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Piksi::MsgCwResults.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_nap_device_dna_resp
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Bootload::MsgNapDeviceDnaResp.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_dops_dep_a
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Navigation::MsgDopsDepA.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_pos_ecef_dep_a
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Navigation::MsgPosEcefDepA.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_settings_read_resp
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Settings::MsgSettingsReadResp.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_linux_mem_state_dep_a
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Linux::MsgLinuxMemStateDepA.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_ephemeris_dep_c
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Observation::MsgEphemerisDepC.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_fileio_write_resp
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = FileIo::MsgFileioWriteResp.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_wheeltick
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Vehicle::MsgWheeltick.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_uart_state_depa
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Piksi::MsgUartStateDepa.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_reference_frame_param
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Navigation::MsgReferenceFrameParam.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_pose_relative
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Navigation::MsgPoseRelative.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_iar_state
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Piksi::MsgIarState.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_uart_state
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Piksi::MsgUartState.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_ssr_tile_definition
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Ssr::MsgSsrTileDefinition.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_ssr_satellite_apc
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Ssr::MsgSsrSatelliteApc.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_osr
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Observation::MsgOsr.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_pos_llh_cov
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Navigation::MsgPosLlhCov.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_group_delay_dep_a
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Observation::MsgGroupDelayDepA.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_protection_level
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Navigation::MsgProtectionLevel.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_obs_dep_b
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Observation::MsgObsDepB.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_pos_llh
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Navigation::MsgPosLlh.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_flash_done
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Flash::MsgFlashDone.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_acq_result_dep_a
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Acquisition::MsgAcqResultDepA.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_ssr_code_biases
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Ssr::MsgSsrCodeBiases.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_ssr_gridded_correction
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Ssr::MsgSsrGriddedCorrection.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_group_meta
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = System::MsgGroupMeta.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_fileio_config_resp
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = FileIo::MsgFileioConfigResp.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_vel_ned_dep_a
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Navigation::MsgVelNedDepA.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_gnss_time_offset
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = System::MsgGnssTimeOffset.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_tracking_state_dep_a
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Tracking::MsgTrackingStateDepA.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_ins_status
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = System::MsgInsStatus.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_ephemeris_gps_dep_f
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Observation::MsgEphemerisGpsDepF.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_linux_cpu_state_dep_a
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Linux::MsgLinuxCpuStateDepA.new(_io__raw_payload, self, @_root)
      when :msg_ids_msg_flash_read_resp
        @_raw_payload = @_io.read_bytes(header.length)
        _io__raw_payload = Kaitai::Struct::Stream.new(@_raw_payload)
        @payload = Flash::MsgFlashReadResp.new(_io__raw_payload, self, @_root)
      else
        @payload = @_io.read_bytes(header.length)
      end
      @crc = @_io.read_u2le
      self
    end
    attr_reader :header
    attr_reader :payload
    attr_reader :crc
    attr_reader :_raw_payload
  end
  class SbpHeader < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @preamble = @_io.read_bytes(1)
      raise Kaitai::Struct::ValidationNotEqualError.new([85].pack('C*'), preamble, _io, "/types/sbp_header/seq/0") if not preamble == [85].pack('C*')
      @msg_type = Kaitai::Struct::Stream::resolve_enum(Sbp::MSG_IDS, @_io.read_u2le)
      @sender = @_io.read_u2le
      @length = @_io.read_u1
      self
    end
    attr_reader :preamble
    attr_reader :msg_type
    attr_reader :sender
    attr_reader :length
  end
  attr_reader :message
end
