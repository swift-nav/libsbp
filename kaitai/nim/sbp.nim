import kaitai_struct_nim_runtime
import options
import acquisition
import bootload
import ext_events
import file_io
import flash
import gnss
import imu
import integrity
import linux
import logging
import mag
import navigation
import ndb
import observation
import orientation
import piksi
import sbas
import settings
import signing
import solution_meta
import ssr
import system
import telemetry
import tracking
import user
import vehicle

type
  Sbp* = ref object of KaitaiStruct
    `message`*: seq[Sbp_Message]
    `parent`*: KaitaiStruct
  Sbp_MsgIds* = enum
    msg_print_dep = 16
    msg_tracking_state_detailed_dep = 17
    msg_tracking_state_dep_b = 19
    msg_acq_result_dep_b = 20
    msg_acq_result_dep_a = 21
    msg_tracking_state_dep_a = 22
    msg_thread_state = 23
    msg_uart_state_depa = 24
    msg_iar_state = 25
    msg_ephemeris_dep_a = 26
    msg_mask_satellite_dep = 27
    msg_tracking_iq_dep_a = 28
    msg_uart_state = 29
    msg_acq_sv_profile_dep = 30
    msg_acq_result_dep_c = 31
    msg_tracking_state_detailed_dep_a = 33
    msg_reset_filters = 34
    msg_init_base_dep = 35
    msg_mask_satellite = 43
    msg_tracking_iq_dep_b = 44
    msg_tracking_iq = 45
    msg_acq_sv_profile = 46
    msg_acq_result = 47
    msg_tracking_state = 65
    msg_obs_dep_b = 67
    msg_base_pos_llh = 68
    msg_obs_dep_a = 69
    msg_ephemeris_dep_b = 70
    msg_ephemeris_dep_c = 71
    msg_base_pos_ecef = 72
    msg_obs_dep_c = 73
    msg_obs = 74
    msg_specan_dep = 80
    msg_specan = 81
    msg_measurement_state = 97
    msg_set_time = 104
    msg_almanac = 105
    msg_almanac_gps_dep = 112
    msg_almanac_glo_dep = 113
    msg_almanac_gps = 114
    msg_almanac_glo = 115
    msg_glo_biases = 117
    msg_ephemeris_dep_d = 128
    msg_ephemeris_gps_dep_e = 129
    msg_ephemeris_sbas_dep_a = 130
    msg_ephemeris_glo_dep_a = 131
    msg_ephemeris_sbas_dep_b = 132
    msg_ephemeris_glo_dep_b = 133
    msg_ephemeris_gps_dep_f = 134
    msg_ephemeris_glo_dep_c = 135
    msg_ephemeris_glo_dep_d = 136
    msg_ephemeris_bds = 137
    msg_ephemeris_gps = 138
    msg_ephemeris_glo = 139
    msg_ephemeris_sbas = 140
    msg_ephemeris_gal = 141
    msg_ephemeris_qzss = 142
    msg_iono = 144
    msg_sv_configuration_gps_dep = 145
    msg_group_delay_dep_a = 146
    msg_group_delay_dep_b = 147
    msg_group_delay = 148
    msg_ephemeris_gal_dep_a = 149
    msg_gnss_capb = 150
    msg_sv_az_el = 151
    msg_settings_write = 160
    msg_settings_save = 161
    msg_settings_read_by_index_req = 162
    msg_fileio_read_resp = 163
    msg_settings_read_req = 164
    msg_settings_read_resp = 165
    msg_settings_read_by_index_done = 166
    msg_settings_read_by_index_resp = 167
    msg_fileio_read_req = 168
    msg_fileio_read_dir_req = 169
    msg_fileio_read_dir_resp = 170
    msg_fileio_write_resp = 171
    msg_fileio_remove = 172
    msg_fileio_write_req = 173
    msg_settings_register = 174
    msg_settings_write_resp = 175
    msg_bootloader_handshake_dep_a = 176
    msg_bootloader_jump_to_app = 177
    msg_reset_dep = 178
    msg_bootloader_handshake_req = 179
    msg_bootloader_handshake_resp = 180
    msg_device_monitor = 181
    msg_reset = 182
    msg_command_req = 184
    msg_command_resp = 185
    msg_network_state_req = 186
    msg_network_state_resp = 187
    msg_command_output = 188
    msg_network_bandwidth_usage = 189
    msg_cell_modem_status = 190
    msg_front_end_gain = 191
    msg_cw_results = 192
    msg_cw_start = 193
    msg_nap_device_dna_resp = 221
    msg_nap_device_dna_req = 222
    msg_flash_done = 224
    msg_flash_read_resp = 225
    msg_flash_erase = 226
    msg_stm_flash_lock_sector = 227
    msg_stm_flash_unlock_sector = 228
    msg_stm_unique_id_resp = 229
    msg_flash_program = 230
    msg_flash_read_req = 231
    msg_stm_unique_id_req = 232
    msg_m25_flash_write_status = 243
    msg_gps_time_dep_a = 256
    msg_ext_event = 257
    msg_gps_time = 258
    msg_utc_time = 259
    msg_gps_time_gnss = 260
    msg_utc_time_gnss = 261
    msg_tel_sv = 288
    msg_settings_register_resp = 431
    msg_pos_ecef_dep_a = 512
    msg_pos_llh_dep_a = 513
    msg_baseline_ecef_dep_a = 514
    msg_baseline_ned_dep_a = 515
    msg_vel_ecef_dep_a = 516
    msg_vel_ned_dep_a = 517
    msg_dops_dep_a = 518
    msg_baseline_heading_dep_a = 519
    msg_dops = 520
    msg_pos_ecef = 521
    msg_pos_llh = 522
    msg_baseline_ecef = 523
    msg_baseline_ned = 524
    msg_vel_ecef = 525
    msg_vel_ned = 526
    msg_baseline_heading = 527
    msg_age_corrections = 528
    msg_pos_llh_cov = 529
    msg_vel_ned_cov = 530
    msg_vel_body = 531
    msg_pos_ecef_cov = 532
    msg_vel_ecef_cov = 533
    msg_protection_level_dep_a = 534
    msg_protection_level = 535
    msg_pos_llh_acc = 536
    msg_vel_cog = 540
    msg_orient_quat = 544
    msg_orient_euler = 545
    msg_angular_rate = 546
    msg_pos_ecef_gnss = 553
    msg_pos_llh_gnss = 554
    msg_vel_ecef_gnss = 557
    msg_vel_ned_gnss = 558
    msg_pos_llh_cov_gnss = 561
    msg_vel_ned_cov_gnss = 562
    msg_pos_ecef_cov_gnss = 564
    msg_vel_ecef_cov_gnss = 565
    msg_utc_leap_second = 570
    msg_reference_frame_param = 580
    msg_pose_relative = 581
    msg_ndb_event = 1024
    msg_log = 1025
    msg_fwd = 1026
    msg_ssr_orbit_clock_dep_a = 1500
    msg_ssr_orbit_clock = 1501
    msg_ssr_orbit_clock_bounds = 1502
    msg_ssr_orbit_clock_bounds_degradation = 1503
    msg_ssr_code_biases = 1505
    msg_ssr_phase_biases = 1510
    msg_ssr_stec_correction_dep_a = 1515
    msg_ssr_code_phase_biases_bounds = 1516
    msg_ssr_gridded_correction_no_std_dep_a = 1520
    msg_ssr_grid_definition_dep_a = 1525
    msg_ssr_tile_definition_dep_a = 1526
    msg_ssr_tile_definition_dep_b = 1527
    msg_ssr_tile_definition = 1528
    msg_ssr_gridded_correction_dep_a = 1530
    msg_ssr_stec_correction_dep = 1531
    msg_ssr_gridded_correction = 1532
    msg_ssr_stec_correction = 1533
    msg_ssr_gridded_correction_bounds = 1534
    msg_ssr_satellite_apc_dep = 1540
    msg_ssr_satellite_apc = 1541
    msg_osr = 1600
    msg_user_data = 2048
    msg_imu_raw = 2304
    msg_imu_aux = 2305
    msg_mag_raw = 2306
    msg_odometry = 2307
    msg_wheeltick = 2308
    msg_ssr_flag_high_level = 3001
    msg_ssr_flag_satellites = 3005
    msg_ssr_flag_tropo_grid_points = 3011
    msg_ssr_flag_iono_grid_points = 3015
    msg_ssr_flag_iono_tile_sat_los = 3021
    msg_ssr_flag_iono_grid_point_sat_los = 3025
    msg_acknowledge = 3026
    msg_ed25519_signature_dep_a = 3073
    msg_ed25519_certificate_dep = 3074
    msg_ed25519_signature_dep_b = 3075
    msg_ecdsa_certificate = 3076
    msg_certificate_chain = 3077
    msg_ecdsa_signature = 3078
    msg_fileio_config_req = 4097
    msg_fileio_config_resp = 4098
    msg_sbas_raw = 30583
    msg_linux_cpu_state_dep_a = 32512
    msg_linux_mem_state_dep_a = 32513
    msg_linux_sys_state_dep_a = 32514
    msg_linux_process_socket_counts = 32515
    msg_linux_process_socket_queues = 32516
    msg_linux_socket_usage = 32517
    msg_linux_process_fd_count = 32518
    msg_linux_process_fd_summary = 32519
    msg_linux_cpu_state = 32520
    msg_linux_mem_state = 32521
    msg_linux_sys_state = 32522
    msg_startup = 65280
    msg_dgnss_status = 65282
    msg_ins_status = 65283
    msg_csac_telemetry = 65284
    msg_csac_telemetry_labels = 65285
    msg_ins_updates = 65286
    msg_gnss_time_offset = 65287
    msg_pps_time = 65288
    msg_sensor_aid_event = 65289
    msg_group_meta = 65290
    msg_soln_meta = 65294
    msg_soln_meta_dep_a = 65295
    msg_status_journal = 65533
    msg_status_report = 65534
    msg_heartbeat = 65535
  Sbp_Message* = ref object of KaitaiStruct
    `header`*: Sbp_SbpHeader
    `payload`*: KaitaiStruct
    `crc`*: uint16
    `parent`*: Sbp
    `rawPayload`*: seq[byte]
  Sbp_SbpHeader* = ref object of KaitaiStruct
    `preamble`*: seq[byte]
    `msgType`*: Sbp_MsgIds
    `sender`*: uint16
    `length`*: uint8
    `parent`*: Sbp_Message

proc read*(_: typedesc[Sbp], io: KaitaiStream, root: KaitaiStruct, parent: KaitaiStruct): Sbp
proc read*(_: typedesc[Sbp_Message], io: KaitaiStream, root: KaitaiStruct, parent: Sbp): Sbp_Message
proc read*(_: typedesc[Sbp_SbpHeader], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Sbp_SbpHeader


proc read*(_: typedesc[Sbp], io: KaitaiStream, root: KaitaiStruct, parent: KaitaiStruct): Sbp =
  template this: untyped = result
  this = new(Sbp)
  let root = if root == nil: cast[Sbp](this) else: cast[Sbp](root)
  this.io = io
  this.root = root
  this.parent = parent

  block:
    var i: int
    while not this.io.isEof:
      let it = Sbp_Message.read(this.io, this.root, this)
      this.message.add(it)
      inc i

proc fromFile*(_: typedesc[Sbp], filename: string): Sbp =
  Sbp.read(newKaitaiFileStream(filename), nil, nil)

proc read*(_: typedesc[Sbp_Message], io: KaitaiStream, root: KaitaiStruct, parent: Sbp): Sbp_Message =
  template this: untyped = result
  this = new(Sbp_Message)
  let root = if root == nil: cast[Sbp](this) else: cast[Sbp](root)
  this.io = io
  this.root = root
  this.parent = parent

  let headerExpr = Sbp_SbpHeader.read(this.io, this.root, this)
  this.header = headerExpr
  block:
    let on = this.header.msgType
    if on == sbp.msg_baseline_ecef:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Navigation_MsgBaselineEcef.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_ephemeris_bds:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Observation_MsgEphemerisBds.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_ephemeris_glo_dep_d:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Observation_MsgEphemerisGloDepD.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_settings_read_by_index_req:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Settings_MsgSettingsReadByIndexReq.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_ssr_flag_high_level:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Integrity_MsgSsrFlagHighLevel.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_fileio_config_req:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = FileIo_MsgFileioConfigReq.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_odometry:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Vehicle_MsgOdometry.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_ssr_stec_correction_dep:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Ssr_MsgSsrStecCorrectionDep.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_ed25519_signature_dep_b:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Signing_MsgEd25519SignatureDepB.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_stm_unique_id_req:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Flash_MsgStmUniqueIdReq.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_front_end_gain:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Piksi_MsgFrontEndGain.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_base_pos_llh:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Observation_MsgBasePosLlh.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_ephemeris_dep_a:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Observation_MsgEphemerisDepA.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_ssr_orbit_clock:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Ssr_MsgSsrOrbitClock.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_reset:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Piksi_MsgReset.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_stm_flash_lock_sector:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Flash_MsgStmFlashLockSector.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_linux_process_fd_summary:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Linux_MsgLinuxProcessFdSummary.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_status_journal:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = System_MsgStatusJournal.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_csac_telemetry:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = System_MsgCsacTelemetry.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_age_corrections:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Navigation_MsgAgeCorrections.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_orient_euler:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Orientation_MsgOrientEuler.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_ssr_satellite_apc_dep:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Ssr_MsgSsrSatelliteApcDep.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_baseline_ned:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Navigation_MsgBaselineNed.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_vel_ecef_gnss:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Navigation_MsgVelEcefGnss.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_measurement_state:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Tracking_MsgMeasurementState.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_iono:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Observation_MsgIono.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_base_pos_ecef:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Observation_MsgBasePosEcef.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_flash_program:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Flash_MsgFlashProgram.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_acq_result:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Acquisition_MsgAcqResult.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_pps_time:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = System_MsgPpsTime.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_obs:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Observation_MsgObs.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_ephemeris_sbas_dep_b:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Observation_MsgEphemerisSbasDepB.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_tracking_iq:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Tracking_MsgTrackingIq.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_ssr_flag_iono_tile_sat_los:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Integrity_MsgSsrFlagIonoTileSatLos.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_tracking_state_detailed_dep:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Tracking_MsgTrackingStateDetailedDep.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_bootloader_handshake_dep_a:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Bootload_MsgBootloaderHandshakeDepA.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_utc_leap_second:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Navigation_MsgUtcLeapSecond.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_ssr_gridded_correction_no_std_dep_a:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Ssr_MsgSsrGriddedCorrectionNoStdDepA.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_bootloader_handshake_resp:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Bootload_MsgBootloaderHandshakeResp.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_baseline_heading:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Orientation_MsgBaselineHeading.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_status_report:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = System_MsgStatusReport.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_vel_ned_cov:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Navigation_MsgVelNedCov.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_set_time:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Piksi_MsgSetTime.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_linux_cpu_state:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Linux_MsgLinuxCpuState.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_gps_time_dep_a:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Navigation_MsgGpsTimeDepA.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_ephemeris_sbas_dep_a:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Observation_MsgEphemerisSbasDepA.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_acq_result_dep_b:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Acquisition_MsgAcqResultDepB.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_settings_register_resp:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Settings_MsgSettingsRegisterResp.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_ephemeris_gal:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Observation_MsgEphemerisGal.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_bootloader_jump_to_app:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Bootload_MsgBootloaderJumpToApp.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_ssr_phase_biases:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Ssr_MsgSsrPhaseBiases.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_fileio_read_dir_resp:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = FileIo_MsgFileioReadDirResp.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_pos_ecef_gnss:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Navigation_MsgPosEcefGnss.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_almanac_glo_dep:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Observation_MsgAlmanacGloDep.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_vel_ecef_dep_a:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Navigation_MsgVelEcefDepA.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_thread_state:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Piksi_MsgThreadState.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_gps_time:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Navigation_MsgGpsTime.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_ssr_code_phase_biases_bounds:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Ssr_MsgSsrCodePhaseBiasesBounds.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_settings_write_resp:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Settings_MsgSettingsWriteResp.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_tracking_state:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Tracking_MsgTrackingState.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_vel_ecef:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Navigation_MsgVelEcef.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_ephemeris_glo_dep_a:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Observation_MsgEphemerisGloDepA.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_ed25519_certificate_dep:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Signing_MsgEd25519CertificateDep.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_baseline_ned_dep_a:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Navigation_MsgBaselineNedDepA.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_specan_dep:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Piksi_MsgSpecanDep.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_ephemeris_sbas:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Observation_MsgEphemerisSbas.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_group_delay:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Observation_MsgGroupDelay.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_pos_ecef:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Navigation_MsgPosEcef.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_almanac:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Piksi_MsgAlmanac.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_settings_read_req:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Settings_MsgSettingsReadReq.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_ssr_flag_tropo_grid_points:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Integrity_MsgSsrFlagTropoGridPoints.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_ssr_gridded_correction_bounds:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Ssr_MsgSsrGriddedCorrectionBounds.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_stm_unique_id_resp:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Flash_MsgStmUniqueIdResp.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_tel_sv:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Telemetry_MsgTelSv.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_ssr_flag_satellites:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Integrity_MsgSsrFlagSatellites.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_imu_aux:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Imu_MsgImuAux.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_ssr_grid_definition_dep_a:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Ssr_MsgSsrGridDefinitionDepA.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_pos_llh_acc:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Navigation_MsgPosLlhAcc.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_sv_configuration_gps_dep:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Observation_MsgSvConfigurationGpsDep.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_linux_mem_state:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Linux_MsgLinuxMemState.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_linux_sys_state:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Linux_MsgLinuxSysState.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_settings_read_by_index_done:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Settings_MsgSettingsReadByIndexDone.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_reset_filters:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Piksi_MsgResetFilters.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_ecdsa_signature:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Signing_MsgEcdsaSignature.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_ephemeris_gps_dep_e:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Observation_MsgEphemerisGpsDepE.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_m25_flash_write_status:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Flash_MsgM25FlashWriteStatus.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_ephemeris_gps:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Observation_MsgEphemerisGps.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_command_output:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Piksi_MsgCommandOutput.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_ssr_flag_iono_grid_points:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Integrity_MsgSsrFlagIonoGridPoints.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_vel_ned_cov_gnss:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Navigation_MsgVelNedCovGnss.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_network_state_resp:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Piksi_MsgNetworkStateResp.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_ssr_stec_correction_dep_a:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Ssr_MsgSsrStecCorrectionDepA.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_command_req:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Piksi_MsgCommandReq.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_acknowledge:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Integrity_MsgAcknowledge.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_tracking_iq_dep_a:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Tracking_MsgTrackingIqDepA.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_ephemeris_gal_dep_a:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Observation_MsgEphemerisGalDepA.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_specan:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Piksi_MsgSpecan.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_acq_sv_profile_dep:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Acquisition_MsgAcqSvProfileDep.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_utc_time:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Navigation_MsgUtcTime.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_ephemeris_dep_d:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Observation_MsgEphemerisDepD.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_linux_process_socket_queues:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Linux_MsgLinuxProcessSocketQueues.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_utc_time_gnss:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Navigation_MsgUtcTimeGnss.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_ndb_event:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Ndb_MsgNdbEvent.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_bootloader_handshake_req:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Bootload_MsgBootloaderHandshakeReq.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_user_data:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = User_MsgUserData.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_sensor_aid_event:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = System_MsgSensorAidEvent.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_ssr_orbit_clock_bounds:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Ssr_MsgSsrOrbitClockBounds.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_pos_llh_gnss:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Navigation_MsgPosLlhGnss.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_init_base_dep:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Piksi_MsgInitBaseDep.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_fileio_read_req:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = FileIo_MsgFileioReadReq.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_tracking_iq_dep_b:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Tracking_MsgTrackingIqDepB.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_acq_result_dep_c:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Acquisition_MsgAcqResultDepC.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_command_resp:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Piksi_MsgCommandResp.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_fileio_remove:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = FileIo_MsgFileioRemove.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_obs_dep_c:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Observation_MsgObsDepC.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_ssr_tile_definition_dep_b:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Ssr_MsgSsrTileDefinitionDepB.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_csac_telemetry_labels:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = System_MsgCsacTelemetryLabels.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_vel_ned:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Navigation_MsgVelNed.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_settings_read_by_index_resp:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Settings_MsgSettingsReadByIndexResp.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_ephemeris_qzss:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Observation_MsgEphemerisQzss.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_ssr_stec_correction:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Ssr_MsgSsrStecCorrection.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_baseline_ecef_dep_a:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Navigation_MsgBaselineEcefDepA.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_ins_updates:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = System_MsgInsUpdates.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_pos_ecef_cov:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Navigation_MsgPosEcefCov.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_vel_ned_gnss:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Navigation_MsgVelNedGnss.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_mask_satellite:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Piksi_MsgMaskSatellite.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_group_delay_dep_b:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Observation_MsgGroupDelayDepB.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_ssr_orbit_clock_bounds_degradation:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Ssr_MsgSsrOrbitClockBoundsDegradation.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_flash_erase:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Flash_MsgFlashErase.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_cw_start:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Piksi_MsgCwStart.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_ssr_orbit_clock_dep_a:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Ssr_MsgSsrOrbitClockDepA.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_dops:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Navigation_MsgDops.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_network_bandwidth_usage:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Piksi_MsgNetworkBandwidthUsage.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_ecdsa_certificate:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Signing_MsgEcdsaCertificate.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_pos_llh_dep_a:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Navigation_MsgPosLlhDepA.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_sv_az_el:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Observation_MsgSvAzEl.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_fileio_read_dir_req:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = FileIo_MsgFileioReadDirReq.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_ephemeris_dep_b:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Observation_MsgEphemerisDepB.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_vel_ecef_cov:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Navigation_MsgVelEcefCov.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_dgnss_status:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = System_MsgDgnssStatus.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_ssr_tile_definition_dep_a:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Ssr_MsgSsrTileDefinitionDepA.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_log:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Logging_MsgLog.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_mask_satellite_dep:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Piksi_MsgMaskSatelliteDep.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_ext_event:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = ExtEvents_MsgExtEvent.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_cell_modem_status:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Piksi_MsgCellModemStatus.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_orient_quat:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Orientation_MsgOrientQuat.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_heartbeat:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = System_MsgHeartbeat.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_almanac_gps_dep:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Observation_MsgAlmanacGpsDep.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_nap_device_dna_req:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Bootload_MsgNapDeviceDnaReq.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_almanac_gps:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Observation_MsgAlmanacGps.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_vel_ecef_cov_gnss:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Navigation_MsgVelEcefCovGnss.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_ed25519_signature_dep_a:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Signing_MsgEd25519SignatureDepA.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_angular_rate:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Orientation_MsgAngularRate.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_vel_body:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Navigation_MsgVelBody.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_certificate_chain:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Signing_MsgCertificateChain.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_soln_meta_dep_a:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = SolutionMeta_MsgSolnMetaDepA.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_ssr_gridded_correction_dep_a:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Ssr_MsgSsrGriddedCorrectionDepA.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_ephemeris_glo_dep_c:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Observation_MsgEphemerisGloDepC.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_linux_process_fd_count:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Linux_MsgLinuxProcessFdCount.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_fileio_read_resp:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = FileIo_MsgFileioReadResp.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_linux_sys_state_dep_a:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Linux_MsgLinuxSysStateDepA.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_sbas_raw:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Sbas_MsgSbasRaw.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_pos_ecef_cov_gnss:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Navigation_MsgPosEcefCovGnss.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_ssr_flag_iono_grid_point_sat_los:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Integrity_MsgSsrFlagIonoGridPointSatLos.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_fileio_write_req:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = FileIo_MsgFileioWriteReq.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_acq_sv_profile:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Acquisition_MsgAcqSvProfile.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_ephemeris_glo_dep_b:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Observation_MsgEphemerisGloDepB.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_linux_socket_usage:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Linux_MsgLinuxSocketUsage.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_network_state_req:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Piksi_MsgNetworkStateReq.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_protection_level_dep_a:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Navigation_MsgProtectionLevelDepA.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_imu_raw:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Imu_MsgImuRaw.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_reset_dep:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Piksi_MsgResetDep.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_mag_raw:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Mag_MsgMagRaw.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_startup:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = System_MsgStartup.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_glo_biases:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Observation_MsgGloBiases.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_tracking_state_detailed_dep_a:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Tracking_MsgTrackingStateDetailedDepA.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_pos_llh_cov_gnss:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Navigation_MsgPosLlhCovGnss.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_settings_write:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Settings_MsgSettingsWrite.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_settings_save:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Settings_MsgSettingsSave.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_almanac_glo:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Observation_MsgAlmanacGlo.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_stm_flash_unlock_sector:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Flash_MsgStmFlashUnlockSector.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_gps_time_gnss:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Navigation_MsgGpsTimeGnss.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_flash_read_req:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Flash_MsgFlashReadReq.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_ephemeris_glo:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Observation_MsgEphemerisGlo.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_baseline_heading_dep_a:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Navigation_MsgBaselineHeadingDepA.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_settings_register:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Settings_MsgSettingsRegister.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_gnss_capb:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Observation_MsgGnssCapb.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_tracking_state_dep_b:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Tracking_MsgTrackingStateDepB.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_fwd:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Logging_MsgFwd.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_soln_meta:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = SolutionMeta_MsgSolnMeta.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_obs_dep_a:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Observation_MsgObsDepA.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_device_monitor:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Piksi_MsgDeviceMonitor.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_linux_process_socket_counts:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Linux_MsgLinuxProcessSocketCounts.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_vel_cog:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Navigation_MsgVelCog.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_print_dep:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Logging_MsgPrintDep.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_cw_results:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Piksi_MsgCwResults.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_nap_device_dna_resp:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Bootload_MsgNapDeviceDnaResp.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_dops_dep_a:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Navigation_MsgDopsDepA.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_pos_ecef_dep_a:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Navigation_MsgPosEcefDepA.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_settings_read_resp:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Settings_MsgSettingsReadResp.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_linux_mem_state_dep_a:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Linux_MsgLinuxMemStateDepA.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_ephemeris_dep_c:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Observation_MsgEphemerisDepC.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_fileio_write_resp:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = FileIo_MsgFileioWriteResp.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_wheeltick:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Vehicle_MsgWheeltick.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_uart_state_depa:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Piksi_MsgUartStateDepa.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_reference_frame_param:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Navigation_MsgReferenceFrameParam.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_pose_relative:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Navigation_MsgPoseRelative.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_iar_state:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Piksi_MsgIarState.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_uart_state:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Piksi_MsgUartState.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_ssr_tile_definition:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Ssr_MsgSsrTileDefinition.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_ssr_satellite_apc:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Ssr_MsgSsrSatelliteApc.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_osr:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Observation_MsgOsr.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_pos_llh_cov:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Navigation_MsgPosLlhCov.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_group_delay_dep_a:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Observation_MsgGroupDelayDepA.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_protection_level:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Navigation_MsgProtectionLevel.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_obs_dep_b:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Observation_MsgObsDepB.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_pos_llh:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Navigation_MsgPosLlh.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_flash_done:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Flash_MsgFlashDone.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_acq_result_dep_a:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Acquisition_MsgAcqResultDepA.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_ssr_code_biases:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Ssr_MsgSsrCodeBiases.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_ssr_gridded_correction:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Ssr_MsgSsrGriddedCorrection.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_group_meta:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = System_MsgGroupMeta.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_fileio_config_resp:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = FileIo_MsgFileioConfigResp.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_vel_ned_dep_a:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Navigation_MsgVelNedDepA.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_gnss_time_offset:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = System_MsgGnssTimeOffset.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_tracking_state_dep_a:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Tracking_MsgTrackingStateDepA.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_ins_status:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = System_MsgInsStatus.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_ephemeris_gps_dep_f:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Observation_MsgEphemerisGpsDepF.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_linux_cpu_state_dep_a:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Linux_MsgLinuxCpuStateDepA.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    elif on == sbp.msg_flash_read_resp:
      let rawPayloadExpr = this.io.readBytes(int(this.header.length))
      this.rawPayload = rawPayloadExpr
      let rawPayloadIo = newKaitaiStream(rawPayloadExpr)
      let payloadExpr = Flash_MsgFlashReadResp.read(rawPayloadIo, this.root, this)
      this.payload = payloadExpr
    else:
      let payloadExpr = this.io.readBytes(int(this.header.length))
      this.payload = payloadExpr
  let crcExpr = this.io.readU2le()
  this.crc = crcExpr

proc fromFile*(_: typedesc[Sbp_Message], filename: string): Sbp_Message =
  Sbp_Message.read(newKaitaiFileStream(filename), nil, nil)

proc read*(_: typedesc[Sbp_SbpHeader], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Sbp_SbpHeader =
  template this: untyped = result
  this = new(Sbp_SbpHeader)
  let root = if root == nil: cast[Sbp](this) else: cast[Sbp](root)
  this.io = io
  this.root = root
  this.parent = parent

  let preambleExpr = this.io.readBytes(int(1))
  this.preamble = preambleExpr
  let msgTypeExpr = Sbp_MsgIds(this.io.readU2le())
  this.msgType = msgTypeExpr
  let senderExpr = this.io.readU2le()
  this.sender = senderExpr
  let lengthExpr = this.io.readU1()
  this.length = lengthExpr

proc fromFile*(_: typedesc[Sbp_SbpHeader], filename: string): Sbp_SbpHeader =
  Sbp_SbpHeader.read(newKaitaiFileStream(filename), nil, nil)

