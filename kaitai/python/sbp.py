from .acquisition import *
from .bootload import *
from .ext_events import *
from .file_io import *
from .flash import *
from .gnss import *
from .imu import *
from .integrity import *
from .linux import *
from .logging import *
from .mag import *
from .navigation import *
from .ndb import *
from .observation import *
from .orientation import *
from .piksi import *
from .sbas import *
from .settings import *
from .signing import *
from .solution_meta import *
from .ssr import *
from .system import *
from .telemetry import *
from .tracking import *
from .user import *
from .vehicle import *
# This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

import kaitaistruct
from kaitaistruct import KaitaiStruct, KaitaiStream, BytesIO
from enum import Enum


if getattr(kaitaistruct, 'API_VERSION', (0, 9)) < (0, 9):
    raise Exception("Incompatible Kaitai Struct Python API: 0.9 or later is required, but you have %s" % (kaitaistruct.__version__))

class Sbp(KaitaiStruct):

    class MsgIds(Enum):
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
        msg_certificate_chain_dep = 3077
        msg_ecdsa_signature_dep_a = 3078
        msg_ecdsa_signature_dep_b = 3079
        msg_ecdsa_signature = 3080
        msg_certificate_chain = 3081
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
    def __init__(self, _io, _parent=None, _root=None):
        self._io = _io
        self._parent = _parent
        self._root = _root if _root else self
        self._read()

    def _read(self):
        self.message = []
        i = 0
        while not self._io.is_eof():
            self.message.append(Sbp.Message(self._io, self, self._root))
            i += 1


    class Message(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.header = Sbp.SbpHeader(self._io, self, self._root)
            _on = self.header.msg_type
            if _on == Sbp.MsgIds.msg_baseline_ecef:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Navigation.MsgBaselineEcef(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_ephemeris_bds:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Observation.MsgEphemerisBds(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_ephemeris_glo_dep_d:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Observation.MsgEphemerisGloDepD(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_ecdsa_signature_dep_b:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Signing.MsgEcdsaSignatureDepB(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_settings_read_by_index_req:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Settings.MsgSettingsReadByIndexReq(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_ssr_flag_high_level:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Integrity.MsgSsrFlagHighLevel(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_fileio_config_req:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = FileIo.MsgFileioConfigReq(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_odometry:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Vehicle.MsgOdometry(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_ssr_stec_correction_dep:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Ssr.MsgSsrStecCorrectionDep(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_ed25519_signature_dep_b:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Signing.MsgEd25519SignatureDepB(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_stm_unique_id_req:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Flash.MsgStmUniqueIdReq(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_front_end_gain:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Piksi.MsgFrontEndGain(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_base_pos_llh:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Observation.MsgBasePosLlh(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_ephemeris_dep_a:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Observation.MsgEphemerisDepA(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_ssr_orbit_clock:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Ssr.MsgSsrOrbitClock(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_reset:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Piksi.MsgReset(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_stm_flash_lock_sector:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Flash.MsgStmFlashLockSector(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_linux_process_fd_summary:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Linux.MsgLinuxProcessFdSummary(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_status_journal:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = System.MsgStatusJournal(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_csac_telemetry:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = System.MsgCsacTelemetry(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_age_corrections:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Navigation.MsgAgeCorrections(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_orient_euler:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Orientation.MsgOrientEuler(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_ssr_satellite_apc_dep:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Ssr.MsgSsrSatelliteApcDep(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_baseline_ned:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Navigation.MsgBaselineNed(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_vel_ecef_gnss:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Navigation.MsgVelEcefGnss(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_measurement_state:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Tracking.MsgMeasurementState(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_iono:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Observation.MsgIono(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_base_pos_ecef:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Observation.MsgBasePosEcef(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_flash_program:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Flash.MsgFlashProgram(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_acq_result:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Acquisition.MsgAcqResult(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_pps_time:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = System.MsgPpsTime(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_obs:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Observation.MsgObs(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_ephemeris_sbas_dep_b:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Observation.MsgEphemerisSbasDepB(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_tracking_iq:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Tracking.MsgTrackingIq(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_ssr_flag_iono_tile_sat_los:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Integrity.MsgSsrFlagIonoTileSatLos(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_tracking_state_detailed_dep:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Tracking.MsgTrackingStateDetailedDep(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_bootloader_handshake_dep_a:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Bootload.MsgBootloaderHandshakeDepA(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_utc_leap_second:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Navigation.MsgUtcLeapSecond(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_ssr_gridded_correction_no_std_dep_a:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Ssr.MsgSsrGriddedCorrectionNoStdDepA(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_bootloader_handshake_resp:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Bootload.MsgBootloaderHandshakeResp(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_baseline_heading:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Orientation.MsgBaselineHeading(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_status_report:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = System.MsgStatusReport(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_vel_ned_cov:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Navigation.MsgVelNedCov(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_set_time:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Piksi.MsgSetTime(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_linux_cpu_state:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Linux.MsgLinuxCpuState(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_gps_time_dep_a:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Navigation.MsgGpsTimeDepA(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_ephemeris_sbas_dep_a:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Observation.MsgEphemerisSbasDepA(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_acq_result_dep_b:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Acquisition.MsgAcqResultDepB(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_settings_register_resp:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Settings.MsgSettingsRegisterResp(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_ecdsa_signature_dep_a:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Signing.MsgEcdsaSignatureDepA(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_ephemeris_gal:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Observation.MsgEphemerisGal(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_bootloader_jump_to_app:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Bootload.MsgBootloaderJumpToApp(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_ssr_phase_biases:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Ssr.MsgSsrPhaseBiases(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_fileio_read_dir_resp:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = FileIo.MsgFileioReadDirResp(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_pos_ecef_gnss:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Navigation.MsgPosEcefGnss(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_almanac_glo_dep:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Observation.MsgAlmanacGloDep(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_vel_ecef_dep_a:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Navigation.MsgVelEcefDepA(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_thread_state:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Piksi.MsgThreadState(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_gps_time:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Navigation.MsgGpsTime(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_ssr_code_phase_biases_bounds:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Ssr.MsgSsrCodePhaseBiasesBounds(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_settings_write_resp:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Settings.MsgSettingsWriteResp(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_tracking_state:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Tracking.MsgTrackingState(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_vel_ecef:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Navigation.MsgVelEcef(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_ephemeris_glo_dep_a:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Observation.MsgEphemerisGloDepA(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_ed25519_certificate_dep:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Signing.MsgEd25519CertificateDep(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_baseline_ned_dep_a:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Navigation.MsgBaselineNedDepA(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_specan_dep:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Piksi.MsgSpecanDep(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_ephemeris_sbas:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Observation.MsgEphemerisSbas(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_group_delay:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Observation.MsgGroupDelay(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_pos_ecef:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Navigation.MsgPosEcef(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_almanac:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Piksi.MsgAlmanac(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_settings_read_req:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Settings.MsgSettingsReadReq(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_ssr_flag_tropo_grid_points:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Integrity.MsgSsrFlagTropoGridPoints(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_ssr_gridded_correction_bounds:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Ssr.MsgSsrGriddedCorrectionBounds(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_stm_unique_id_resp:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Flash.MsgStmUniqueIdResp(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_tel_sv:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Telemetry.MsgTelSv(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_ssr_flag_satellites:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Integrity.MsgSsrFlagSatellites(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_imu_aux:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Imu.MsgImuAux(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_ssr_grid_definition_dep_a:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Ssr.MsgSsrGridDefinitionDepA(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_pos_llh_acc:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Navigation.MsgPosLlhAcc(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_sv_configuration_gps_dep:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Observation.MsgSvConfigurationGpsDep(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_linux_mem_state:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Linux.MsgLinuxMemState(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_linux_sys_state:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Linux.MsgLinuxSysState(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_settings_read_by_index_done:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Settings.MsgSettingsReadByIndexDone(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_reset_filters:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Piksi.MsgResetFilters(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_ecdsa_signature:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Signing.MsgEcdsaSignature(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_ephemeris_gps_dep_e:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Observation.MsgEphemerisGpsDepE(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_m25_flash_write_status:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Flash.MsgM25FlashWriteStatus(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_ephemeris_gps:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Observation.MsgEphemerisGps(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_command_output:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Piksi.MsgCommandOutput(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_ssr_flag_iono_grid_points:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Integrity.MsgSsrFlagIonoGridPoints(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_vel_ned_cov_gnss:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Navigation.MsgVelNedCovGnss(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_network_state_resp:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Piksi.MsgNetworkStateResp(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_ssr_stec_correction_dep_a:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Ssr.MsgSsrStecCorrectionDepA(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_command_req:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Piksi.MsgCommandReq(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_acknowledge:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Integrity.MsgAcknowledge(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_tracking_iq_dep_a:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Tracking.MsgTrackingIqDepA(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_ephemeris_gal_dep_a:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Observation.MsgEphemerisGalDepA(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_specan:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Piksi.MsgSpecan(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_acq_sv_profile_dep:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Acquisition.MsgAcqSvProfileDep(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_utc_time:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Navigation.MsgUtcTime(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_ephemeris_dep_d:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Observation.MsgEphemerisDepD(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_linux_process_socket_queues:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Linux.MsgLinuxProcessSocketQueues(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_utc_time_gnss:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Navigation.MsgUtcTimeGnss(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_ndb_event:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Ndb.MsgNdbEvent(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_bootloader_handshake_req:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Bootload.MsgBootloaderHandshakeReq(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_user_data:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = User.MsgUserData(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_sensor_aid_event:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = System.MsgSensorAidEvent(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_ssr_orbit_clock_bounds:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Ssr.MsgSsrOrbitClockBounds(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_pos_llh_gnss:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Navigation.MsgPosLlhGnss(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_init_base_dep:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Piksi.MsgInitBaseDep(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_fileio_read_req:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = FileIo.MsgFileioReadReq(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_tracking_iq_dep_b:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Tracking.MsgTrackingIqDepB(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_acq_result_dep_c:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Acquisition.MsgAcqResultDepC(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_command_resp:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Piksi.MsgCommandResp(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_fileio_remove:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = FileIo.MsgFileioRemove(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_obs_dep_c:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Observation.MsgObsDepC(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_ssr_tile_definition_dep_b:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Ssr.MsgSsrTileDefinitionDepB(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_csac_telemetry_labels:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = System.MsgCsacTelemetryLabels(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_vel_ned:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Navigation.MsgVelNed(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_settings_read_by_index_resp:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Settings.MsgSettingsReadByIndexResp(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_ephemeris_qzss:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Observation.MsgEphemerisQzss(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_ssr_stec_correction:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Ssr.MsgSsrStecCorrection(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_baseline_ecef_dep_a:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Navigation.MsgBaselineEcefDepA(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_ins_updates:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = System.MsgInsUpdates(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_pos_ecef_cov:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Navigation.MsgPosEcefCov(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_vel_ned_gnss:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Navigation.MsgVelNedGnss(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_mask_satellite:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Piksi.MsgMaskSatellite(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_group_delay_dep_b:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Observation.MsgGroupDelayDepB(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_ssr_orbit_clock_bounds_degradation:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Ssr.MsgSsrOrbitClockBoundsDegradation(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_flash_erase:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Flash.MsgFlashErase(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_cw_start:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Piksi.MsgCwStart(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_ssr_orbit_clock_dep_a:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Ssr.MsgSsrOrbitClockDepA(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_dops:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Navigation.MsgDops(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_network_bandwidth_usage:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Piksi.MsgNetworkBandwidthUsage(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_ecdsa_certificate:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Signing.MsgEcdsaCertificate(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_pos_llh_dep_a:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Navigation.MsgPosLlhDepA(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_sv_az_el:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Observation.MsgSvAzEl(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_fileio_read_dir_req:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = FileIo.MsgFileioReadDirReq(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_ephemeris_dep_b:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Observation.MsgEphemerisDepB(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_vel_ecef_cov:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Navigation.MsgVelEcefCov(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_dgnss_status:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = System.MsgDgnssStatus(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_ssr_tile_definition_dep_a:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Ssr.MsgSsrTileDefinitionDepA(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_log:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Logging.MsgLog(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_mask_satellite_dep:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Piksi.MsgMaskSatelliteDep(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_ext_event:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = ExtEvents.MsgExtEvent(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_cell_modem_status:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Piksi.MsgCellModemStatus(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_orient_quat:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Orientation.MsgOrientQuat(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_heartbeat:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = System.MsgHeartbeat(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_almanac_gps_dep:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Observation.MsgAlmanacGpsDep(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_nap_device_dna_req:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Bootload.MsgNapDeviceDnaReq(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_almanac_gps:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Observation.MsgAlmanacGps(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_vel_ecef_cov_gnss:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Navigation.MsgVelEcefCovGnss(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_ed25519_signature_dep_a:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Signing.MsgEd25519SignatureDepA(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_angular_rate:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Orientation.MsgAngularRate(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_vel_body:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Navigation.MsgVelBody(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_certificate_chain:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Signing.MsgCertificateChain(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_soln_meta_dep_a:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = SolutionMeta.MsgSolnMetaDepA(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_ssr_gridded_correction_dep_a:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Ssr.MsgSsrGriddedCorrectionDepA(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_ephemeris_glo_dep_c:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Observation.MsgEphemerisGloDepC(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_linux_process_fd_count:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Linux.MsgLinuxProcessFdCount(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_fileio_read_resp:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = FileIo.MsgFileioReadResp(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_linux_sys_state_dep_a:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Linux.MsgLinuxSysStateDepA(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_sbas_raw:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Sbas.MsgSbasRaw(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_pos_ecef_cov_gnss:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Navigation.MsgPosEcefCovGnss(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_ssr_flag_iono_grid_point_sat_los:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Integrity.MsgSsrFlagIonoGridPointSatLos(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_fileio_write_req:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = FileIo.MsgFileioWriteReq(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_acq_sv_profile:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Acquisition.MsgAcqSvProfile(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_ephemeris_glo_dep_b:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Observation.MsgEphemerisGloDepB(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_linux_socket_usage:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Linux.MsgLinuxSocketUsage(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_network_state_req:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Piksi.MsgNetworkStateReq(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_protection_level_dep_a:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Navigation.MsgProtectionLevelDepA(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_imu_raw:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Imu.MsgImuRaw(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_reset_dep:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Piksi.MsgResetDep(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_mag_raw:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Mag.MsgMagRaw(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_startup:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = System.MsgStartup(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_glo_biases:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Observation.MsgGloBiases(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_tracking_state_detailed_dep_a:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Tracking.MsgTrackingStateDetailedDepA(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_pos_llh_cov_gnss:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Navigation.MsgPosLlhCovGnss(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_settings_write:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Settings.MsgSettingsWrite(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_settings_save:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Settings.MsgSettingsSave(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_almanac_glo:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Observation.MsgAlmanacGlo(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_stm_flash_unlock_sector:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Flash.MsgStmFlashUnlockSector(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_gps_time_gnss:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Navigation.MsgGpsTimeGnss(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_flash_read_req:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Flash.MsgFlashReadReq(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_ephemeris_glo:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Observation.MsgEphemerisGlo(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_baseline_heading_dep_a:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Navigation.MsgBaselineHeadingDepA(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_settings_register:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Settings.MsgSettingsRegister(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_gnss_capb:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Observation.MsgGnssCapb(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_tracking_state_dep_b:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Tracking.MsgTrackingStateDepB(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_fwd:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Logging.MsgFwd(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_soln_meta:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = SolutionMeta.MsgSolnMeta(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_obs_dep_a:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Observation.MsgObsDepA(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_device_monitor:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Piksi.MsgDeviceMonitor(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_linux_process_socket_counts:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Linux.MsgLinuxProcessSocketCounts(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_vel_cog:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Navigation.MsgVelCog(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_print_dep:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Logging.MsgPrintDep(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_cw_results:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Piksi.MsgCwResults(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_nap_device_dna_resp:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Bootload.MsgNapDeviceDnaResp(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_dops_dep_a:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Navigation.MsgDopsDepA(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_pos_ecef_dep_a:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Navigation.MsgPosEcefDepA(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_settings_read_resp:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Settings.MsgSettingsReadResp(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_linux_mem_state_dep_a:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Linux.MsgLinuxMemStateDepA(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_ephemeris_dep_c:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Observation.MsgEphemerisDepC(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_fileio_write_resp:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = FileIo.MsgFileioWriteResp(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_wheeltick:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Vehicle.MsgWheeltick(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_uart_state_depa:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Piksi.MsgUartStateDepa(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_reference_frame_param:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Navigation.MsgReferenceFrameParam(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_pose_relative:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Navigation.MsgPoseRelative(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_iar_state:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Piksi.MsgIarState(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_uart_state:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Piksi.MsgUartState(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_ssr_tile_definition:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Ssr.MsgSsrTileDefinition(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_ssr_satellite_apc:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Ssr.MsgSsrSatelliteApc(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_osr:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Observation.MsgOsr(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_pos_llh_cov:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Navigation.MsgPosLlhCov(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_group_delay_dep_a:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Observation.MsgGroupDelayDepA(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_protection_level:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Navigation.MsgProtectionLevel(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_obs_dep_b:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Observation.MsgObsDepB(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_pos_llh:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Navigation.MsgPosLlh(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_flash_done:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Flash.MsgFlashDone(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_acq_result_dep_a:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Acquisition.MsgAcqResultDepA(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_ssr_code_biases:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Ssr.MsgSsrCodeBiases(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_certificate_chain_dep:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Signing.MsgCertificateChainDep(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_ssr_gridded_correction:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Ssr.MsgSsrGriddedCorrection(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_group_meta:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = System.MsgGroupMeta(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_fileio_config_resp:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = FileIo.MsgFileioConfigResp(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_vel_ned_dep_a:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Navigation.MsgVelNedDepA(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_gnss_time_offset:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = System.MsgGnssTimeOffset(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_tracking_state_dep_a:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Tracking.MsgTrackingStateDepA(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_ins_status:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = System.MsgInsStatus(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_ephemeris_gps_dep_f:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Observation.MsgEphemerisGpsDepF(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_linux_cpu_state_dep_a:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Linux.MsgLinuxCpuStateDepA(_io__raw_payload, self, self._root)
            elif _on == Sbp.MsgIds.msg_flash_read_resp:
                self._raw_payload = self._io.read_bytes(self.header.length)
                _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
                self.payload = Flash.MsgFlashReadResp(_io__raw_payload, self, self._root)
            else:
                self.payload = self._io.read_bytes(self.header.length)
            self.crc = self._io.read_u2le()


    class SbpHeader(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.preamble = self._io.read_bytes(1)
            if not self.preamble == b"\x55":
                raise kaitaistruct.ValidationNotEqualError(b"\x55", self.preamble, self._io, u"/types/sbp_header/seq/0")
            self.msg_type = KaitaiStream.resolve_enum(Sbp.MsgIds, self._io.read_u2le())
            self.sender = self._io.read_u2le()
            self.length = self._io.read_u1()



