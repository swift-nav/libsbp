-- This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild
--
-- This file is compatible with Lua 5.3

local class = require("class")
require("kaitaistruct")
local enum = require("enum")
local stringstream = require("string_stream")

Sbp = class.class(KaitaiStruct)

Sbp.MsgIds = enum.Enum {
  msg_print_dep = 16,
  msg_tracking_state_detailed_dep = 17,
  msg_tracking_state_dep_b = 19,
  msg_acq_result_dep_b = 20,
  msg_acq_result_dep_a = 21,
  msg_tracking_state_dep_a = 22,
  msg_thread_state = 23,
  msg_uart_state_depa = 24,
  msg_iar_state = 25,
  msg_ephemeris_dep_a = 26,
  msg_mask_satellite_dep = 27,
  msg_tracking_iq_dep_a = 28,
  msg_uart_state = 29,
  msg_acq_sv_profile_dep = 30,
  msg_acq_result_dep_c = 31,
  msg_tracking_state_detailed_dep_a = 33,
  msg_reset_filters = 34,
  msg_init_base_dep = 35,
  msg_mask_satellite = 43,
  msg_tracking_iq_dep_b = 44,
  msg_tracking_iq = 45,
  msg_acq_sv_profile = 46,
  msg_acq_result = 47,
  msg_tracking_state = 65,
  msg_obs_dep_b = 67,
  msg_base_pos_llh = 68,
  msg_obs_dep_a = 69,
  msg_ephemeris_dep_b = 70,
  msg_ephemeris_dep_c = 71,
  msg_base_pos_ecef = 72,
  msg_obs_dep_c = 73,
  msg_obs = 74,
  msg_specan_dep = 80,
  msg_specan = 81,
  msg_measurement_state = 97,
  msg_set_time = 104,
  msg_almanac = 105,
  msg_almanac_gps_dep = 112,
  msg_almanac_glo_dep = 113,
  msg_almanac_gps = 114,
  msg_almanac_glo = 115,
  msg_glo_biases = 117,
  msg_ephemeris_dep_d = 128,
  msg_ephemeris_gps_dep_e = 129,
  msg_ephemeris_sbas_dep_a = 130,
  msg_ephemeris_glo_dep_a = 131,
  msg_ephemeris_sbas_dep_b = 132,
  msg_ephemeris_glo_dep_b = 133,
  msg_ephemeris_gps_dep_f = 134,
  msg_ephemeris_glo_dep_c = 135,
  msg_ephemeris_glo_dep_d = 136,
  msg_ephemeris_bds = 137,
  msg_ephemeris_gps = 138,
  msg_ephemeris_glo = 139,
  msg_ephemeris_sbas = 140,
  msg_ephemeris_gal = 141,
  msg_ephemeris_qzss = 142,
  msg_iono = 144,
  msg_sv_configuration_gps_dep = 145,
  msg_group_delay_dep_a = 146,
  msg_group_delay_dep_b = 147,
  msg_group_delay = 148,
  msg_ephemeris_gal_dep_a = 149,
  msg_gnss_capb = 150,
  msg_sv_az_el = 151,
  msg_settings_write = 160,
  msg_settings_save = 161,
  msg_settings_read_by_index_req = 162,
  msg_fileio_read_resp = 163,
  msg_settings_read_req = 164,
  msg_settings_read_resp = 165,
  msg_settings_read_by_index_done = 166,
  msg_settings_read_by_index_resp = 167,
  msg_fileio_read_req = 168,
  msg_fileio_read_dir_req = 169,
  msg_fileio_read_dir_resp = 170,
  msg_fileio_write_resp = 171,
  msg_fileio_remove = 172,
  msg_fileio_write_req = 173,
  msg_settings_register = 174,
  msg_settings_write_resp = 175,
  msg_bootloader_handshake_dep_a = 176,
  msg_bootloader_jump_to_app = 177,
  msg_reset_dep = 178,
  msg_bootloader_handshake_req = 179,
  msg_bootloader_handshake_resp = 180,
  msg_device_monitor = 181,
  msg_reset = 182,
  msg_command_req = 184,
  msg_command_resp = 185,
  msg_network_state_req = 186,
  msg_network_state_resp = 187,
  msg_command_output = 188,
  msg_network_bandwidth_usage = 189,
  msg_cell_modem_status = 190,
  msg_front_end_gain = 191,
  msg_cw_results = 192,
  msg_cw_start = 193,
  msg_nap_device_dna_resp = 221,
  msg_nap_device_dna_req = 222,
  msg_flash_done = 224,
  msg_flash_read_resp = 225,
  msg_flash_erase = 226,
  msg_stm_flash_lock_sector = 227,
  msg_stm_flash_unlock_sector = 228,
  msg_stm_unique_id_resp = 229,
  msg_flash_program = 230,
  msg_flash_read_req = 231,
  msg_stm_unique_id_req = 232,
  msg_m25_flash_write_status = 243,
  msg_gps_time_dep_a = 256,
  msg_ext_event = 257,
  msg_gps_time = 258,
  msg_utc_time = 259,
  msg_gps_time_gnss = 260,
  msg_utc_time_gnss = 261,
  msg_tel_sv = 288,
  msg_settings_register_resp = 431,
  msg_pos_ecef_dep_a = 512,
  msg_pos_llh_dep_a = 513,
  msg_baseline_ecef_dep_a = 514,
  msg_baseline_ned_dep_a = 515,
  msg_vel_ecef_dep_a = 516,
  msg_vel_ned_dep_a = 517,
  msg_dops_dep_a = 518,
  msg_baseline_heading_dep_a = 519,
  msg_dops = 520,
  msg_pos_ecef = 521,
  msg_pos_llh = 522,
  msg_baseline_ecef = 523,
  msg_baseline_ned = 524,
  msg_vel_ecef = 525,
  msg_vel_ned = 526,
  msg_baseline_heading = 527,
  msg_age_corrections = 528,
  msg_pos_llh_cov = 529,
  msg_vel_ned_cov = 530,
  msg_vel_body = 531,
  msg_pos_ecef_cov = 532,
  msg_vel_ecef_cov = 533,
  msg_protection_level_dep_a = 534,
  msg_protection_level = 535,
  msg_pos_llh_acc = 536,
  msg_vel_cog = 540,
  msg_orient_quat = 544,
  msg_orient_euler = 545,
  msg_angular_rate = 546,
  msg_pos_ecef_gnss = 553,
  msg_pos_llh_gnss = 554,
  msg_vel_ecef_gnss = 557,
  msg_vel_ned_gnss = 558,
  msg_pos_llh_cov_gnss = 561,
  msg_vel_ned_cov_gnss = 562,
  msg_pos_ecef_cov_gnss = 564,
  msg_vel_ecef_cov_gnss = 565,
  msg_utc_leap_second = 570,
  msg_reference_frame_param = 580,
  msg_pose_relative = 581,
  msg_ndb_event = 1024,
  msg_log = 1025,
  msg_fwd = 1026,
  msg_ssr_orbit_clock_dep_a = 1500,
  msg_ssr_orbit_clock = 1501,
  msg_ssr_orbit_clock_bounds = 1502,
  msg_ssr_orbit_clock_bounds_degradation = 1503,
  msg_ssr_code_biases = 1505,
  msg_ssr_phase_biases = 1510,
  msg_ssr_stec_correction_dep_a = 1515,
  msg_ssr_code_phase_biases_bounds = 1516,
  msg_ssr_gridded_correction_no_std_dep_a = 1520,
  msg_ssr_grid_definition_dep_a = 1525,
  msg_ssr_tile_definition_dep_a = 1526,
  msg_ssr_tile_definition_dep_b = 1527,
  msg_ssr_tile_definition = 1528,
  msg_ssr_gridded_correction_dep_a = 1530,
  msg_ssr_stec_correction_dep = 1531,
  msg_ssr_gridded_correction = 1532,
  msg_ssr_stec_correction = 1533,
  msg_ssr_gridded_correction_bounds = 1534,
  msg_ssr_satellite_apc_dep = 1540,
  msg_ssr_satellite_apc = 1541,
  msg_osr = 1600,
  msg_user_data = 2048,
  msg_imu_raw = 2304,
  msg_imu_aux = 2305,
  msg_mag_raw = 2306,
  msg_odometry = 2307,
  msg_wheeltick = 2308,
  msg_ssr_flag_high_level = 3001,
  msg_ssr_flag_satellites = 3005,
  msg_ssr_flag_tropo_grid_points = 3011,
  msg_ssr_flag_iono_grid_points = 3015,
  msg_ssr_flag_iono_tile_sat_los = 3021,
  msg_ssr_flag_iono_grid_point_sat_los = 3025,
  msg_acknowledge = 3026,
  msg_ed25519_signature_dep_a = 3073,
  msg_ed25519_certificate_dep = 3074,
  msg_ed25519_signature_dep_b = 3075,
  msg_ecdsa_certificate = 3076,
  msg_certificate_chain_dep = 3077,
  msg_ecdsa_signature_dep_a = 3078,
  msg_ecdsa_signature_dep_b = 3079,
  msg_ecdsa_signature = 3080,
  msg_certificate_chain = 3081,
  msg_fileio_config_req = 4097,
  msg_fileio_config_resp = 4098,
  msg_sbas_raw = 30583,
  msg_linux_cpu_state_dep_a = 32512,
  msg_linux_mem_state_dep_a = 32513,
  msg_linux_sys_state_dep_a = 32514,
  msg_linux_process_socket_counts = 32515,
  msg_linux_process_socket_queues = 32516,
  msg_linux_socket_usage = 32517,
  msg_linux_process_fd_count = 32518,
  msg_linux_process_fd_summary = 32519,
  msg_linux_cpu_state = 32520,
  msg_linux_mem_state = 32521,
  msg_linux_sys_state = 32522,
  msg_startup = 65280,
  msg_dgnss_status = 65282,
  msg_ins_status = 65283,
  msg_csac_telemetry = 65284,
  msg_csac_telemetry_labels = 65285,
  msg_ins_updates = 65286,
  msg_gnss_time_offset = 65287,
  msg_pps_time = 65288,
  msg_sensor_aid_event = 65289,
  msg_group_meta = 65290,
  msg_soln_meta = 65294,
  msg_soln_meta_dep_a = 65295,
  msg_status_journal = 65533,
  msg_status_report = 65534,
  msg_heartbeat = 65535,
}

function Sbp:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Sbp:_read()
  self.message = {}
  local i = 0
  while not self._io:is_eof() do
    self.message[i + 1] = Sbp.Message(self._io, self, self._root)
    i = i + 1
  end
end


Sbp.Message = class.class(KaitaiStruct)

function Sbp.Message:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Sbp.Message:_read()
  self.header = Sbp.SbpHeader(self._io, self, self._root)
  local _on = self.header.msg_type
  if _on == 525 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Navigation.MsgVelEcef(_io, self, self._root)
  elseif _on == 141 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Observation.MsgEphemerisGal(_io, self, self._root)
  elseif _on == 243 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Flash.MsgM25FlashWriteStatus(_io, self, self._root)
  elseif _on == 2048 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = User.MsgUserData(_io, self, self._root)
  elseif _on == 3079 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Signing.MsgEcdsaSignatureDepB(_io, self, self._root)
  elseif _on == 184 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Piksi.MsgCommandReq(_io, self, self._root)
  elseif _on == 105 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Piksi.MsgAlmanac(_io, self, self._root)
  elseif _on == 142 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Observation.MsgEphemerisQzss(_io, self, self._root)
  elseif _on == 112 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Observation.MsgAlmanacGpsDep(_io, self, self._root)
  elseif _on == 177 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Bootload.MsgBootloaderJumpToApp(_io, self, self._root)
  elseif _on == 163 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = FileIo.MsgFileioReadResp(_io, self, self._root)
  elseif _on == 257 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = ExtEvents.MsgExtEvent(_io, self, self._root)
  elseif _on == 4097 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = FileIo.MsgFileioConfigReq(_io, self, self._root)
  elseif _on == 17 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Tracking.MsgTrackingStateDetailedDep(_io, self, self._root)
  elseif _on == 260 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Navigation.MsgGpsTimeGnss(_io, self, self._root)
  elseif _on == 1525 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Ssr.MsgSsrGridDefinitionDepA(_io, self, self._root)
  elseif _on == 131 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Observation.MsgEphemerisGloDepA(_io, self, self._root)
  elseif _on == 167 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Settings.MsgSettingsReadByIndexResp(_io, self, self._root)
  elseif _on == 146 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Observation.MsgGroupDelayDepA(_io, self, self._root)
  elseif _on == 47 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Acquisition.MsgAcqResult(_io, self, self._root)
  elseif _on == 136 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Observation.MsgEphemerisGloDepD(_io, self, self._root)
  elseif _on == 73 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Observation.MsgObsDepC(_io, self, self._root)
  elseif _on == 65283 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = System.MsgInsStatus(_io, self, self._root)
  elseif _on == 32513 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Linux.MsgLinuxMemStateDepA(_io, self, self._root)
  elseif _on == 545 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Orientation.MsgOrientEuler(_io, self, self._root)
  elseif _on == 65534 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = System.MsgStatusReport(_io, self, self._root)
  elseif _on == 533 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Navigation.MsgVelEcefCov(_io, self, self._root)
  elseif _on == 513 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Navigation.MsgPosLlhDepA(_io, self, self._root)
  elseif _on == 46 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Acquisition.MsgAcqSvProfile(_io, self, self._root)
  elseif _on == 81 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Piksi.MsgSpecan(_io, self, self._root)
  elseif _on == 169 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = FileIo.MsgFileioReadDirReq(_io, self, self._root)
  elseif _on == 162 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Settings.MsgSettingsReadByIndexReq(_io, self, self._root)
  elseif _on == 546 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Orientation.MsgAngularRate(_io, self, self._root)
  elseif _on == 531 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Navigation.MsgVelBody(_io, self, self._root)
  elseif _on == 224 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Flash.MsgFlashDone(_io, self, self._root)
  elseif _on == 24 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Piksi.MsgUartStateDepa(_io, self, self._root)
  elseif _on == 230 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Flash.MsgFlashProgram(_io, self, self._root)
  elseif _on == 65285 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = System.MsgCsacTelemetryLabels(_io, self, self._root)
  elseif _on == 35 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Piksi.MsgInitBaseDep(_io, self, self._root)
  elseif _on == 1528 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Ssr.MsgSsrTileDefinition(_io, self, self._root)
  elseif _on == 519 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Navigation.MsgBaselineHeadingDepA(_io, self, self._root)
  elseif _on == 20 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Acquisition.MsgAcqResultDepB(_io, self, self._root)
  elseif _on == 570 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Navigation.MsgUtcLeapSecond(_io, self, self._root)
  elseif _on == 32520 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Linux.MsgLinuxCpuState(_io, self, self._root)
  elseif _on == 1505 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Ssr.MsgSsrCodeBiases(_io, self, self._root)
  elseif _on == 113 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Observation.MsgAlmanacGloDep(_io, self, self._root)
  elseif _on == 1515 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Ssr.MsgSsrStecCorrectionDepA(_io, self, self._root)
  elseif _on == 558 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Navigation.MsgVelNedGnss(_io, self, self._root)
  elseif _on == 530 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Navigation.MsgVelNedCov(_io, self, self._root)
  elseif _on == 288 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Telemetry.MsgTelSv(_io, self, self._root)
  elseif _on == 1026 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Logging.MsgFwd(_io, self, self._root)
  elseif _on == 65286 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = System.MsgInsUpdates(_io, self, self._root)
  elseif _on == 65284 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = System.MsgCsacTelemetry(_io, self, self._root)
  elseif _on == 191 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Piksi.MsgFrontEndGain(_io, self, self._root)
  elseif _on == 520 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Navigation.MsgDops(_io, self, self._root)
  elseif _on == 27 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Piksi.MsgMaskSatelliteDep(_io, self, self._root)
  elseif _on == 1516 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Ssr.MsgSsrCodePhaseBiasesBounds(_io, self, self._root)
  elseif _on == 150 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Observation.MsgGnssCapb(_io, self, self._root)
  elseif _on == 97 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Tracking.MsgMeasurementState(_io, self, self._root)
  elseif _on == 529 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Navigation.MsgPosLlhCov(_io, self, self._root)
  elseif _on == 431 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Settings.MsgSettingsRegisterResp(_io, self, self._root)
  elseif _on == 65533 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = System.MsgStatusJournal(_io, self, self._root)
  elseif _on == 145 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Observation.MsgSvConfigurationGpsDep(_io, self, self._root)
  elseif _on == 32522 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Linux.MsgLinuxSysState(_io, self, self._root)
  elseif _on == 3076 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Signing.MsgEcdsaCertificate(_io, self, self._root)
  elseif _on == 144 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Observation.MsgIono(_io, self, self._root)
  elseif _on == 65294 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = SolutionMeta.MsgSolnMeta(_io, self, self._root)
  elseif _on == 532 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Navigation.MsgPosEcefCov(_io, self, self._root)
  elseif _on == 45 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Tracking.MsgTrackingIq(_io, self, self._root)
  elseif _on == 561 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Navigation.MsgPosLlhCovGnss(_io, self, self._root)
  elseif _on == 1502 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Ssr.MsgSsrOrbitClockBounds(_io, self, self._root)
  elseif _on == 149 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Observation.MsgEphemerisGalDepA(_io, self, self._root)
  elseif _on == 115 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Observation.MsgAlmanacGlo(_io, self, self._root)
  elseif _on == 32512 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Linux.MsgLinuxCpuStateDepA(_io, self, self._root)
  elseif _on == 32521 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Linux.MsgLinuxMemState(_io, self, self._root)
  elseif _on == 522 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Navigation.MsgPosLlh(_io, self, self._root)
  elseif _on == 104 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Piksi.MsgSetTime(_io, self, self._root)
  elseif _on == 32519 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Linux.MsgLinuxProcessFdSummary(_io, self, self._root)
  elseif _on == 4098 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = FileIo.MsgFileioConfigResp(_io, self, self._root)
  elseif _on == 32517 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Linux.MsgLinuxSocketUsage(_io, self, self._root)
  elseif _on == 2306 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Mag.MsgMagRaw(_io, self, self._root)
  elseif _on == 67 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Observation.MsgObsDepB(_io, self, self._root)
  elseif _on == 69 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Observation.MsgObsDepA(_io, self, self._root)
  elseif _on == 512 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Navigation.MsgPosEcefDepA(_io, self, self._root)
  elseif _on == 137 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Observation.MsgEphemerisBds(_io, self, self._root)
  elseif _on == 65288 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = System.MsgPpsTime(_io, self, self._root)
  elseif _on == 3074 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Signing.MsgEd25519CertificateDep(_io, self, self._root)
  elseif _on == 562 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Navigation.MsgVelNedCovGnss(_io, self, self._root)
  elseif _on == 580 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Navigation.MsgReferenceFrameParam(_io, self, self._root)
  elseif _on == 524 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Navigation.MsgBaselineNed(_io, self, self._root)
  elseif _on == 161 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Settings.MsgSettingsSave(_io, self, self._root)
  elseif _on == 138 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Observation.MsgEphemerisGps(_io, self, self._root)
  elseif _on == 544 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Orientation.MsgOrientQuat(_io, self, self._root)
  elseif _on == 192 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Piksi.MsgCwResults(_io, self, self._root)
  elseif _on == 165 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Settings.MsgSettingsReadResp(_io, self, self._root)
  elseif _on == 33 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Tracking.MsgTrackingStateDetailedDepA(_io, self, self._root)
  elseif _on == 1527 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Ssr.MsgSsrTileDefinitionDepB(_io, self, self._root)
  elseif _on == 65535 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = System.MsgHeartbeat(_io, self, self._root)
  elseif _on == 3081 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Signing.MsgCertificateChain(_io, self, self._root)
  elseif _on == 514 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Navigation.MsgBaselineEcefDepA(_io, self, self._root)
  elseif _on == 185 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Piksi.MsgCommandResp(_io, self, self._root)
  elseif _on == 180 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Bootload.MsgBootloaderHandshakeResp(_io, self, self._root)
  elseif _on == 19 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Tracking.MsgTrackingStateDepB(_io, self, self._root)
  elseif _on == 3015 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Integrity.MsgSsrFlagIonoGridPoints(_io, self, self._root)
  elseif _on == 186 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Piksi.MsgNetworkStateReq(_io, self, self._root)
  elseif _on == 32518 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Linux.MsgLinuxProcessFdCount(_io, self, self._root)
  elseif _on == 1530 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Ssr.MsgSsrGriddedCorrectionDepA(_io, self, self._root)
  elseif _on == 1541 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Ssr.MsgSsrSatelliteApc(_io, self, self._root)
  elseif _on == 30583 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Sbas.MsgSbasRaw(_io, self, self._root)
  elseif _on == 23 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Piksi.MsgThreadState(_io, self, self._root)
  elseif _on == 221 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Bootload.MsgNapDeviceDnaResp(_io, self, self._root)
  elseif _on == 227 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Flash.MsgStmFlashLockSector(_io, self, self._root)
  elseif _on == 188 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Piksi.MsgCommandOutput(_io, self, self._root)
  elseif _on == 65282 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = System.MsgDgnssStatus(_io, self, self._root)
  elseif _on == 178 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Piksi.MsgResetDep(_io, self, self._root)
  elseif _on == 1533 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Ssr.MsgSsrStecCorrection(_io, self, self._root)
  elseif _on == 3011 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Integrity.MsgSsrFlagTropoGridPoints(_io, self, self._root)
  elseif _on == 3005 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Integrity.MsgSsrFlagSatellites(_io, self, self._root)
  elseif _on == 160 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Settings.MsgSettingsWrite(_io, self, self._root)
  elseif _on == 540 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Navigation.MsgVelCog(_io, self, self._root)
  elseif _on == 174 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Settings.MsgSettingsRegister(_io, self, self._root)
  elseif _on == 176 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Bootload.MsgBootloaderHandshakeDepA(_io, self, self._root)
  elseif _on == 1024 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Ndb.MsgNdbEvent(_io, self, self._root)
  elseif _on == 166 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Settings.MsgSettingsReadByIndexDone(_io, self, self._root)
  elseif _on == 114 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Observation.MsgAlmanacGps(_io, self, self._root)
  elseif _on == 564 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Navigation.MsgPosEcefCovGnss(_io, self, self._root)
  elseif _on == 259 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Navigation.MsgUtcTime(_io, self, self._root)
  elseif _on == 181 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Piksi.MsgDeviceMonitor(_io, self, self._root)
  elseif _on == 521 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Navigation.MsgPosEcef(_io, self, self._root)
  elseif _on == 2307 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Vehicle.MsgOdometry(_io, self, self._root)
  elseif _on == 148 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Observation.MsgGroupDelay(_io, self, self._root)
  elseif _on == 117 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Observation.MsgGloBiases(_io, self, self._root)
  elseif _on == 3025 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Integrity.MsgSsrFlagIonoGridPointSatLos(_io, self, self._root)
  elseif _on == 65 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Tracking.MsgTrackingState(_io, self, self._root)
  elseif _on == 1534 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Ssr.MsgSsrGriddedCorrectionBounds(_io, self, self._root)
  elseif _on == 44 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Tracking.MsgTrackingIqDepB(_io, self, self._root)
  elseif _on == 3073 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Signing.MsgEd25519SignatureDepA(_io, self, self._root)
  elseif _on == 231 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Flash.MsgFlashReadReq(_io, self, self._root)
  elseif _on == 140 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Observation.MsgEphemerisSbas(_io, self, self._root)
  elseif _on == 226 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Flash.MsgFlashErase(_io, self, self._root)
  elseif _on == 515 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Navigation.MsgBaselineNedDepA(_io, self, self._root)
  elseif _on == 2308 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Vehicle.MsgWheeltick(_io, self, self._root)
  elseif _on == 535 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Navigation.MsgProtectionLevel(_io, self, self._root)
  elseif _on == 179 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Bootload.MsgBootloaderHandshakeReq(_io, self, self._root)
  elseif _on == 172 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = FileIo.MsgFileioRemove(_io, self, self._root)
  elseif _on == 130 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Observation.MsgEphemerisSbasDepA(_io, self, self._root)
  elseif _on == 187 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Piksi.MsgNetworkStateResp(_io, self, self._root)
  elseif _on == 1501 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Ssr.MsgSsrOrbitClock(_io, self, self._root)
  elseif _on == 21 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Acquisition.MsgAcqResultDepA(_io, self, self._root)
  elseif _on == 1500 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Ssr.MsgSsrOrbitClockDepA(_io, self, self._root)
  elseif _on == 225 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Flash.MsgFlashReadResp(_io, self, self._root)
  elseif _on == 534 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Navigation.MsgProtectionLevelDepA(_io, self, self._root)
  elseif _on == 232 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Flash.MsgStmUniqueIdReq(_io, self, self._root)
  elseif _on == 2304 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Imu.MsgImuRaw(_io, self, self._root)
  elseif _on == 229 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Flash.MsgStmUniqueIdResp(_io, self, self._root)
  elseif _on == 32515 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Linux.MsgLinuxProcessSocketCounts(_io, self, self._root)
  elseif _on == 65295 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = SolutionMeta.MsgSolnMetaDepA(_io, self, self._root)
  elseif _on == 3075 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Signing.MsgEd25519SignatureDepB(_io, self, self._root)
  elseif _on == 258 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Navigation.MsgGpsTime(_io, self, self._root)
  elseif _on == 32516 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Linux.MsgLinuxProcessSocketQueues(_io, self, self._root)
  elseif _on == 170 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = FileIo.MsgFileioReadDirResp(_io, self, self._root)
  elseif _on == 256 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Navigation.MsgGpsTimeDepA(_io, self, self._root)
  elseif _on == 32514 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Linux.MsgLinuxSysStateDepA(_io, self, self._root)
  elseif _on == 518 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Navigation.MsgDopsDepA(_io, self, self._root)
  elseif _on == 553 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Navigation.MsgPosEcefGnss(_io, self, self._root)
  elseif _on == 517 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Navigation.MsgVelNedDepA(_io, self, self._root)
  elseif _on == 164 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Settings.MsgSettingsReadReq(_io, self, self._root)
  elseif _on == 182 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Piksi.MsgReset(_io, self, self._root)
  elseif _on == 189 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Piksi.MsgNetworkBandwidthUsage(_io, self, self._root)
  elseif _on == 72 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Observation.MsgBasePosEcef(_io, self, self._root)
  elseif _on == 71 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Observation.MsgEphemerisDepC(_io, self, self._root)
  elseif _on == 1025 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Logging.MsgLog(_io, self, self._root)
  elseif _on == 168 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = FileIo.MsgFileioReadReq(_io, self, self._root)
  elseif _on == 581 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Navigation.MsgPoseRelative(_io, self, self._root)
  elseif _on == 171 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = FileIo.MsgFileioWriteResp(_io, self, self._root)
  elseif _on == 70 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Observation.MsgEphemerisDepB(_io, self, self._root)
  elseif _on == 28 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Tracking.MsgTrackingIqDepA(_io, self, self._root)
  elseif _on == 193 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Piksi.MsgCwStart(_io, self, self._root)
  elseif _on == 133 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Observation.MsgEphemerisGloDepB(_io, self, self._root)
  elseif _on == 129 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Observation.MsgEphemerisGpsDepE(_io, self, self._root)
  elseif _on == 74 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Observation.MsgObs(_io, self, self._root)
  elseif _on == 3080 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Signing.MsgEcdsaSignature(_io, self, self._root)
  elseif _on == 151 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Observation.MsgSvAzEl(_io, self, self._root)
  elseif _on == 16 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Logging.MsgPrintDep(_io, self, self._root)
  elseif _on == 147 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Observation.MsgGroupDelayDepB(_io, self, self._root)
  elseif _on == 527 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Orientation.MsgBaselineHeading(_io, self, self._root)
  elseif _on == 134 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Observation.MsgEphemerisGpsDepF(_io, self, self._root)
  elseif _on == 3078 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Signing.MsgEcdsaSignatureDepA(_io, self, self._root)
  elseif _on == 80 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Piksi.MsgSpecanDep(_io, self, self._root)
  elseif _on == 68 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Observation.MsgBasePosLlh(_io, self, self._root)
  elseif _on == 1532 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Ssr.MsgSsrGriddedCorrection(_io, self, self._root)
  elseif _on == 1503 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Ssr.MsgSsrOrbitClockBoundsDegradation(_io, self, self._root)
  elseif _on == 516 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Navigation.MsgVelEcefDepA(_io, self, self._root)
  elseif _on == 26 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Observation.MsgEphemerisDepA(_io, self, self._root)
  elseif _on == 139 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Observation.MsgEphemerisGlo(_io, self, self._root)
  elseif _on == 65280 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = System.MsgStartup(_io, self, self._root)
  elseif _on == 31 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Acquisition.MsgAcqResultDepC(_io, self, self._root)
  elseif _on == 565 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Navigation.MsgVelEcefCovGnss(_io, self, self._root)
  elseif _on == 135 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Observation.MsgEphemerisGloDepC(_io, self, self._root)
  elseif _on == 3026 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Integrity.MsgAcknowledge(_io, self, self._root)
  elseif _on == 34 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Piksi.MsgResetFilters(_io, self, self._root)
  elseif _on == 1600 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Observation.MsgOsr(_io, self, self._root)
  elseif _on == 536 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Navigation.MsgPosLlhAcc(_io, self, self._root)
  elseif _on == 65287 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = System.MsgGnssTimeOffset(_io, self, self._root)
  elseif _on == 1526 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Ssr.MsgSsrTileDefinitionDepA(_io, self, self._root)
  elseif _on == 1540 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Ssr.MsgSsrSatelliteApcDep(_io, self, self._root)
  elseif _on == 29 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Piksi.MsgUartState(_io, self, self._root)
  elseif _on == 132 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Observation.MsgEphemerisSbasDepB(_io, self, self._root)
  elseif _on == 1510 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Ssr.MsgSsrPhaseBiases(_io, self, self._root)
  elseif _on == 65290 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = System.MsgGroupMeta(_io, self, self._root)
  elseif _on == 175 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Settings.MsgSettingsWriteResp(_io, self, self._root)
  elseif _on == 557 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Navigation.MsgVelEcefGnss(_io, self, self._root)
  elseif _on == 526 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Navigation.MsgVelNed(_io, self, self._root)
  elseif _on == 1520 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Ssr.MsgSsrGriddedCorrectionNoStdDepA(_io, self, self._root)
  elseif _on == 2305 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Imu.MsgImuAux(_io, self, self._root)
  elseif _on == 190 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Piksi.MsgCellModemStatus(_io, self, self._root)
  elseif _on == 1531 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Ssr.MsgSsrStecCorrectionDep(_io, self, self._root)
  elseif _on == 528 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Navigation.MsgAgeCorrections(_io, self, self._root)
  elseif _on == 3077 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Signing.MsgCertificateChainDep(_io, self, self._root)
  elseif _on == 25 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Piksi.MsgIarState(_io, self, self._root)
  elseif _on == 43 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Piksi.MsgMaskSatellite(_io, self, self._root)
  elseif _on == 228 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Flash.MsgStmFlashUnlockSector(_io, self, self._root)
  elseif _on == 523 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Navigation.MsgBaselineEcef(_io, self, self._root)
  elseif _on == 554 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Navigation.MsgPosLlhGnss(_io, self, self._root)
  elseif _on == 65289 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = System.MsgSensorAidEvent(_io, self, self._root)
  elseif _on == 22 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Tracking.MsgTrackingStateDepA(_io, self, self._root)
  elseif _on == 3001 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Integrity.MsgSsrFlagHighLevel(_io, self, self._root)
  elseif _on == 30 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Acquisition.MsgAcqSvProfileDep(_io, self, self._root)
  elseif _on == 261 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Navigation.MsgUtcTimeGnss(_io, self, self._root)
  elseif _on == 3021 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Integrity.MsgSsrFlagIonoTileSatLos(_io, self, self._root)
  elseif _on == 173 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = FileIo.MsgFileioWriteReq(_io, self, self._root)
  elseif _on == 128 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Observation.MsgEphemerisDepD(_io, self, self._root)
  elseif _on == 222 then
    self._raw_payload = self._io:read_bytes(self.header.length)
    local _io = KaitaiStream(stringstream(self._raw_payload))
    self.payload = Bootload.MsgNapDeviceDnaReq(_io, self, self._root)
  else
    self.payload = self._io:read_bytes(self.header.length)
  end
  self.crc = self._io:read_u2le()
end


Sbp.SbpHeader = class.class(KaitaiStruct)

function Sbp.SbpHeader:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Sbp.SbpHeader:_read()
  self.preamble = self._io:read_bytes(1)
  if not(self.preamble == "\085") then
    error("not equal, expected " ..  "\085" .. ", but got " .. self.preamble)
  end
  self.msg_type = self._io:read_u2le()
  self.sender = self._io:read_u2le()
  self.length = self._io:read_u1()
end


