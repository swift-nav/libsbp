// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

import io.kaitai.struct.ByteBufferKaitaiStream;
import io.kaitai.struct.KaitaiStruct;
import io.kaitai.struct.KaitaiStream;
import java.io.IOException;
import java.util.Map;
import java.util.HashMap;
import java.util.ArrayList;
import java.util.Arrays;

public class Sbp extends KaitaiStruct {
    public static Sbp fromFile(String fileName) throws IOException {
        return new Sbp(new ByteBufferKaitaiStream(fileName));
    }

    public enum MsgIds {
        MSG_PRINT_DEP(16),
        MSG_TRACKING_STATE_DETAILED_DEP(17),
        MSG_TRACKING_STATE_DEP_B(19),
        MSG_ACQ_RESULT_DEP_B(20),
        MSG_ACQ_RESULT_DEP_A(21),
        MSG_TRACKING_STATE_DEP_A(22),
        MSG_THREAD_STATE(23),
        MSG_UART_STATE_DEPA(24),
        MSG_IAR_STATE(25),
        MSG_EPHEMERIS_DEP_A(26),
        MSG_MASK_SATELLITE_DEP(27),
        MSG_TRACKING_IQ_DEP_A(28),
        MSG_UART_STATE(29),
        MSG_ACQ_SV_PROFILE_DEP(30),
        MSG_ACQ_RESULT_DEP_C(31),
        MSG_TRACKING_STATE_DETAILED_DEP_A(33),
        MSG_RESET_FILTERS(34),
        MSG_INIT_BASE_DEP(35),
        MSG_MASK_SATELLITE(43),
        MSG_TRACKING_IQ_DEP_B(44),
        MSG_TRACKING_IQ(45),
        MSG_ACQ_SV_PROFILE(46),
        MSG_ACQ_RESULT(47),
        MSG_TRACKING_STATE(65),
        MSG_OBS_DEP_B(67),
        MSG_BASE_POS_LLH(68),
        MSG_OBS_DEP_A(69),
        MSG_EPHEMERIS_DEP_B(70),
        MSG_EPHEMERIS_DEP_C(71),
        MSG_BASE_POS_ECEF(72),
        MSG_OBS_DEP_C(73),
        MSG_OBS(74),
        MSG_SPECAN_DEP(80),
        MSG_SPECAN(81),
        MSG_MEASUREMENT_STATE(97),
        MSG_SET_TIME(104),
        MSG_ALMANAC(105),
        MSG_ALMANAC_GPS_DEP(112),
        MSG_ALMANAC_GLO_DEP(113),
        MSG_ALMANAC_GPS(114),
        MSG_ALMANAC_GLO(115),
        MSG_GLO_BIASES(117),
        MSG_EPHEMERIS_DEP_D(128),
        MSG_EPHEMERIS_GPS_DEP_E(129),
        MSG_EPHEMERIS_SBAS_DEP_A(130),
        MSG_EPHEMERIS_GLO_DEP_A(131),
        MSG_EPHEMERIS_SBAS_DEP_B(132),
        MSG_EPHEMERIS_GLO_DEP_B(133),
        MSG_EPHEMERIS_GPS_DEP_F(134),
        MSG_EPHEMERIS_GLO_DEP_C(135),
        MSG_EPHEMERIS_GLO_DEP_D(136),
        MSG_EPHEMERIS_BDS(137),
        MSG_EPHEMERIS_GPS(138),
        MSG_EPHEMERIS_GLO(139),
        MSG_EPHEMERIS_SBAS(140),
        MSG_EPHEMERIS_GAL(141),
        MSG_EPHEMERIS_QZSS(142),
        MSG_IONO(144),
        MSG_SV_CONFIGURATION_GPS_DEP(145),
        MSG_GROUP_DELAY_DEP_A(146),
        MSG_GROUP_DELAY_DEP_B(147),
        MSG_GROUP_DELAY(148),
        MSG_EPHEMERIS_GAL_DEP_A(149),
        MSG_GNSS_CAPB(150),
        MSG_SV_AZ_EL(151),
        MSG_SETTINGS_WRITE(160),
        MSG_SETTINGS_SAVE(161),
        MSG_SETTINGS_READ_BY_INDEX_REQ(162),
        MSG_FILEIO_READ_RESP(163),
        MSG_SETTINGS_READ_REQ(164),
        MSG_SETTINGS_READ_RESP(165),
        MSG_SETTINGS_READ_BY_INDEX_DONE(166),
        MSG_SETTINGS_READ_BY_INDEX_RESP(167),
        MSG_FILEIO_READ_REQ(168),
        MSG_FILEIO_READ_DIR_REQ(169),
        MSG_FILEIO_READ_DIR_RESP(170),
        MSG_FILEIO_WRITE_RESP(171),
        MSG_FILEIO_REMOVE(172),
        MSG_FILEIO_WRITE_REQ(173),
        MSG_SETTINGS_REGISTER(174),
        MSG_SETTINGS_WRITE_RESP(175),
        MSG_BOOTLOADER_HANDSHAKE_DEP_A(176),
        MSG_BOOTLOADER_JUMP_TO_APP(177),
        MSG_RESET_DEP(178),
        MSG_BOOTLOADER_HANDSHAKE_REQ(179),
        MSG_BOOTLOADER_HANDSHAKE_RESP(180),
        MSG_DEVICE_MONITOR(181),
        MSG_RESET(182),
        MSG_COMMAND_REQ(184),
        MSG_COMMAND_RESP(185),
        MSG_NETWORK_STATE_REQ(186),
        MSG_NETWORK_STATE_RESP(187),
        MSG_COMMAND_OUTPUT(188),
        MSG_NETWORK_BANDWIDTH_USAGE(189),
        MSG_CELL_MODEM_STATUS(190),
        MSG_FRONT_END_GAIN(191),
        MSG_CW_RESULTS(192),
        MSG_CW_START(193),
        MSG_NAP_DEVICE_DNA_RESP(221),
        MSG_NAP_DEVICE_DNA_REQ(222),
        MSG_FLASH_DONE(224),
        MSG_FLASH_READ_RESP(225),
        MSG_FLASH_ERASE(226),
        MSG_STM_FLASH_LOCK_SECTOR(227),
        MSG_STM_FLASH_UNLOCK_SECTOR(228),
        MSG_STM_UNIQUE_ID_RESP(229),
        MSG_FLASH_PROGRAM(230),
        MSG_FLASH_READ_REQ(231),
        MSG_STM_UNIQUE_ID_REQ(232),
        MSG_M25_FLASH_WRITE_STATUS(243),
        MSG_GPS_TIME_DEP_A(256),
        MSG_EXT_EVENT(257),
        MSG_GPS_TIME(258),
        MSG_UTC_TIME(259),
        MSG_GPS_TIME_GNSS(260),
        MSG_UTC_TIME_GNSS(261),
        MSG_TEL_SV(288),
        MSG_SETTINGS_REGISTER_RESP(431),
        MSG_POS_ECEF_DEP_A(512),
        MSG_POS_LLH_DEP_A(513),
        MSG_BASELINE_ECEF_DEP_A(514),
        MSG_BASELINE_NED_DEP_A(515),
        MSG_VEL_ECEF_DEP_A(516),
        MSG_VEL_NED_DEP_A(517),
        MSG_DOPS_DEP_A(518),
        MSG_BASELINE_HEADING_DEP_A(519),
        MSG_DOPS(520),
        MSG_POS_ECEF(521),
        MSG_POS_LLH(522),
        MSG_BASELINE_ECEF(523),
        MSG_BASELINE_NED(524),
        MSG_VEL_ECEF(525),
        MSG_VEL_NED(526),
        MSG_BASELINE_HEADING(527),
        MSG_AGE_CORRECTIONS(528),
        MSG_POS_LLH_COV(529),
        MSG_VEL_NED_COV(530),
        MSG_VEL_BODY(531),
        MSG_POS_ECEF_COV(532),
        MSG_VEL_ECEF_COV(533),
        MSG_PROTECTION_LEVEL_DEP_A(534),
        MSG_PROTECTION_LEVEL(535),
        MSG_POS_LLH_ACC(536),
        MSG_VEL_COG(540),
        MSG_ORIENT_QUAT(544),
        MSG_ORIENT_EULER(545),
        MSG_ANGULAR_RATE(546),
        MSG_POS_ECEF_GNSS(553),
        MSG_POS_LLH_GNSS(554),
        MSG_VEL_ECEF_GNSS(557),
        MSG_VEL_NED_GNSS(558),
        MSG_POS_LLH_COV_GNSS(561),
        MSG_VEL_NED_COV_GNSS(562),
        MSG_POS_ECEF_COV_GNSS(564),
        MSG_VEL_ECEF_COV_GNSS(565),
        MSG_UTC_LEAP_SECOND(570),
        MSG_REFERENCE_FRAME_PARAM(580),
        MSG_POSE_RELATIVE(581),
        MSG_NDB_EVENT(1024),
        MSG_LOG(1025),
        MSG_FWD(1026),
        MSG_SSR_ORBIT_CLOCK_DEP_A(1500),
        MSG_SSR_ORBIT_CLOCK(1501),
        MSG_SSR_ORBIT_CLOCK_BOUNDS(1502),
        MSG_SSR_ORBIT_CLOCK_BOUNDS_DEGRADATION(1503),
        MSG_SSR_CODE_BIASES(1505),
        MSG_SSR_PHASE_BIASES(1510),
        MSG_SSR_STEC_CORRECTION_DEP_A(1515),
        MSG_SSR_CODE_PHASE_BIASES_BOUNDS(1516),
        MSG_SSR_GRIDDED_CORRECTION_NO_STD_DEP_A(1520),
        MSG_SSR_GRID_DEFINITION_DEP_A(1525),
        MSG_SSR_TILE_DEFINITION_DEP_A(1526),
        MSG_SSR_TILE_DEFINITION_DEP_B(1527),
        MSG_SSR_TILE_DEFINITION(1528),
        MSG_SSR_GRIDDED_CORRECTION_DEP_A(1530),
        MSG_SSR_STEC_CORRECTION_DEP(1531),
        MSG_SSR_GRIDDED_CORRECTION(1532),
        MSG_SSR_STEC_CORRECTION(1533),
        MSG_SSR_GRIDDED_CORRECTION_BOUNDS(1534),
        MSG_SSR_SATELLITE_APC_DEP(1540),
        MSG_SSR_SATELLITE_APC(1541),
        MSG_OSR(1600),
        MSG_USER_DATA(2048),
        MSG_IMU_RAW(2304),
        MSG_IMU_AUX(2305),
        MSG_MAG_RAW(2306),
        MSG_ODOMETRY(2307),
        MSG_WHEELTICK(2308),
        MSG_SSR_FLAG_HIGH_LEVEL(3001),
        MSG_SSR_FLAG_SATELLITES(3005),
        MSG_SSR_FLAG_TROPO_GRID_POINTS(3011),
        MSG_SSR_FLAG_IONO_GRID_POINTS(3015),
        MSG_SSR_FLAG_IONO_TILE_SAT_LOS(3021),
        MSG_SSR_FLAG_IONO_GRID_POINT_SAT_LOS(3025),
        MSG_ACKNOWLEDGE(3026),
        MSG_ED25519_SIGNATURE_DEP_A(3073),
        MSG_ED25519_CERTIFICATE_DEP(3074),
        MSG_ED25519_SIGNATURE_DEP_B(3075),
        MSG_ECDSA_CERTIFICATE(3076),
        MSG_CERTIFICATE_CHAIN(3077),
        MSG_ECDSA_SIGNATURE(3078),
        MSG_FILEIO_CONFIG_REQ(4097),
        MSG_FILEIO_CONFIG_RESP(4098),
        MSG_SBAS_RAW(30583),
        MSG_LINUX_CPU_STATE_DEP_A(32512),
        MSG_LINUX_MEM_STATE_DEP_A(32513),
        MSG_LINUX_SYS_STATE_DEP_A(32514),
        MSG_LINUX_PROCESS_SOCKET_COUNTS(32515),
        MSG_LINUX_PROCESS_SOCKET_QUEUES(32516),
        MSG_LINUX_SOCKET_USAGE(32517),
        MSG_LINUX_PROCESS_FD_COUNT(32518),
        MSG_LINUX_PROCESS_FD_SUMMARY(32519),
        MSG_LINUX_CPU_STATE(32520),
        MSG_LINUX_MEM_STATE(32521),
        MSG_LINUX_SYS_STATE(32522),
        MSG_STARTUP(65280),
        MSG_DGNSS_STATUS(65282),
        MSG_INS_STATUS(65283),
        MSG_CSAC_TELEMETRY(65284),
        MSG_CSAC_TELEMETRY_LABELS(65285),
        MSG_INS_UPDATES(65286),
        MSG_GNSS_TIME_OFFSET(65287),
        MSG_PPS_TIME(65288),
        MSG_SENSOR_AID_EVENT(65289),
        MSG_GROUP_META(65290),
        MSG_SOLN_META(65294),
        MSG_SOLN_META_DEP_A(65295),
        MSG_STATUS_JOURNAL(65533),
        MSG_STATUS_REPORT(65534),
        MSG_HEARTBEAT(65535);

        private final long id;
        MsgIds(long id) { this.id = id; }
        public long id() { return id; }
        private static final Map<Long, MsgIds> byId = new HashMap<Long, MsgIds>(230);
        static {
            for (MsgIds e : MsgIds.values())
                byId.put(e.id(), e);
        }
        public static MsgIds byId(long id) { return byId.get(id); }
    }

    public Sbp(KaitaiStream _io) {
        this(_io, null, null);
    }

    public Sbp(KaitaiStream _io, KaitaiStruct _parent) {
        this(_io, _parent, null);
    }

    public Sbp(KaitaiStream _io, KaitaiStruct _parent, Sbp _root) {
        super(_io);
        this._parent = _parent;
        this._root = _root == null ? this : _root;
        _read();
    }
    private void _read() {
        this.message = new ArrayList<Message>();
        {
            int i = 0;
            while (!this._io.isEof()) {
                this.message.add(new Message(this._io, this, _root));
                i++;
            }
        }
    }
    public static class Message extends KaitaiStruct {
        public static Message fromFile(String fileName) throws IOException {
            return new Message(new ByteBufferKaitaiStream(fileName));
        }

        public Message(KaitaiStream _io) {
            this(_io, null, null);
        }

        public Message(KaitaiStream _io, Sbp _parent) {
            this(_io, _parent, null);
        }

        public Message(KaitaiStream _io, Sbp _parent, Sbp _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.header = new SbpHeader(this._io, this, _root);
            {
                MsgIds on = header().msgType();
                if (on != null) {
                    switch (header().msgType()) {
                    case MSG_BASELINE_ECEF: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Navigation.MsgBaselineEcef(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_EPHEMERIS_BDS: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Observation.MsgEphemerisBds(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_EPHEMERIS_GLO_DEP_D: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Observation.MsgEphemerisGloDepD(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_SETTINGS_READ_BY_INDEX_REQ: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Settings.MsgSettingsReadByIndexReq(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_SSR_FLAG_HIGH_LEVEL: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Integrity.MsgSsrFlagHighLevel(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_FILEIO_CONFIG_REQ: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new FileIo.MsgFileioConfigReq(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_ODOMETRY: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Vehicle.MsgOdometry(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_SSR_STEC_CORRECTION_DEP: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Ssr.MsgSsrStecCorrectionDep(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_ED25519_SIGNATURE_DEP_B: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Signing.MsgEd25519SignatureDepB(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_STM_UNIQUE_ID_REQ: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Flash.MsgStmUniqueIdReq(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_FRONT_END_GAIN: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Piksi.MsgFrontEndGain(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_BASE_POS_LLH: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Observation.MsgBasePosLlh(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_EPHEMERIS_DEP_A: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Observation.MsgEphemerisDepA(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_SSR_ORBIT_CLOCK: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Ssr.MsgSsrOrbitClock(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_RESET: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Piksi.MsgReset(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_STM_FLASH_LOCK_SECTOR: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Flash.MsgStmFlashLockSector(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_LINUX_PROCESS_FD_SUMMARY: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Linux.MsgLinuxProcessFdSummary(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_STATUS_JOURNAL: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new System.MsgStatusJournal(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_CSAC_TELEMETRY: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new System.MsgCsacTelemetry(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_AGE_CORRECTIONS: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Navigation.MsgAgeCorrections(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_ORIENT_EULER: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Orientation.MsgOrientEuler(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_SSR_SATELLITE_APC_DEP: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Ssr.MsgSsrSatelliteApcDep(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_BASELINE_NED: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Navigation.MsgBaselineNed(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_VEL_ECEF_GNSS: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Navigation.MsgVelEcefGnss(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_MEASUREMENT_STATE: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Tracking.MsgMeasurementState(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_IONO: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Observation.MsgIono(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_BASE_POS_ECEF: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Observation.MsgBasePosEcef(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_FLASH_PROGRAM: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Flash.MsgFlashProgram(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_ACQ_RESULT: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Acquisition.MsgAcqResult(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_PPS_TIME: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new System.MsgPpsTime(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_OBS: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Observation.MsgObs(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_EPHEMERIS_SBAS_DEP_B: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Observation.MsgEphemerisSbasDepB(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_TRACKING_IQ: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Tracking.MsgTrackingIq(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_SSR_FLAG_IONO_TILE_SAT_LOS: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Integrity.MsgSsrFlagIonoTileSatLos(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_TRACKING_STATE_DETAILED_DEP: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Tracking.MsgTrackingStateDetailedDep(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_BOOTLOADER_HANDSHAKE_DEP_A: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Bootload.MsgBootloaderHandshakeDepA(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_UTC_LEAP_SECOND: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Navigation.MsgUtcLeapSecond(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_SSR_GRIDDED_CORRECTION_NO_STD_DEP_A: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Ssr.MsgSsrGriddedCorrectionNoStdDepA(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_BOOTLOADER_HANDSHAKE_RESP: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Bootload.MsgBootloaderHandshakeResp(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_BASELINE_HEADING: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Orientation.MsgBaselineHeading(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_STATUS_REPORT: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new System.MsgStatusReport(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_VEL_NED_COV: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Navigation.MsgVelNedCov(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_SET_TIME: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Piksi.MsgSetTime(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_LINUX_CPU_STATE: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Linux.MsgLinuxCpuState(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_GPS_TIME_DEP_A: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Navigation.MsgGpsTimeDepA(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_EPHEMERIS_SBAS_DEP_A: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Observation.MsgEphemerisSbasDepA(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_ACQ_RESULT_DEP_B: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Acquisition.MsgAcqResultDepB(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_SETTINGS_REGISTER_RESP: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Settings.MsgSettingsRegisterResp(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_EPHEMERIS_GAL: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Observation.MsgEphemerisGal(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_BOOTLOADER_JUMP_TO_APP: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Bootload.MsgBootloaderJumpToApp(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_SSR_PHASE_BIASES: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Ssr.MsgSsrPhaseBiases(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_FILEIO_READ_DIR_RESP: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new FileIo.MsgFileioReadDirResp(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_POS_ECEF_GNSS: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Navigation.MsgPosEcefGnss(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_ALMANAC_GLO_DEP: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Observation.MsgAlmanacGloDep(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_VEL_ECEF_DEP_A: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Navigation.MsgVelEcefDepA(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_THREAD_STATE: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Piksi.MsgThreadState(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_GPS_TIME: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Navigation.MsgGpsTime(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_SSR_CODE_PHASE_BIASES_BOUNDS: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Ssr.MsgSsrCodePhaseBiasesBounds(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_SETTINGS_WRITE_RESP: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Settings.MsgSettingsWriteResp(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_TRACKING_STATE: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Tracking.MsgTrackingState(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_VEL_ECEF: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Navigation.MsgVelEcef(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_EPHEMERIS_GLO_DEP_A: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Observation.MsgEphemerisGloDepA(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_ED25519_CERTIFICATE_DEP: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Signing.MsgEd25519CertificateDep(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_BASELINE_NED_DEP_A: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Navigation.MsgBaselineNedDepA(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_SPECAN_DEP: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Piksi.MsgSpecanDep(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_EPHEMERIS_SBAS: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Observation.MsgEphemerisSbas(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_GROUP_DELAY: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Observation.MsgGroupDelay(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_POS_ECEF: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Navigation.MsgPosEcef(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_ALMANAC: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Piksi.MsgAlmanac(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_SETTINGS_READ_REQ: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Settings.MsgSettingsReadReq(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_SSR_FLAG_TROPO_GRID_POINTS: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Integrity.MsgSsrFlagTropoGridPoints(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_SSR_GRIDDED_CORRECTION_BOUNDS: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Ssr.MsgSsrGriddedCorrectionBounds(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_STM_UNIQUE_ID_RESP: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Flash.MsgStmUniqueIdResp(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_TEL_SV: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Telemetry.MsgTelSv(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_SSR_FLAG_SATELLITES: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Integrity.MsgSsrFlagSatellites(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_IMU_AUX: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Imu.MsgImuAux(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_SSR_GRID_DEFINITION_DEP_A: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Ssr.MsgSsrGridDefinitionDepA(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_POS_LLH_ACC: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Navigation.MsgPosLlhAcc(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_SV_CONFIGURATION_GPS_DEP: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Observation.MsgSvConfigurationGpsDep(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_LINUX_MEM_STATE: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Linux.MsgLinuxMemState(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_LINUX_SYS_STATE: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Linux.MsgLinuxSysState(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_SETTINGS_READ_BY_INDEX_DONE: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Settings.MsgSettingsReadByIndexDone(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_RESET_FILTERS: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Piksi.MsgResetFilters(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_ECDSA_SIGNATURE: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Signing.MsgEcdsaSignature(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_EPHEMERIS_GPS_DEP_E: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Observation.MsgEphemerisGpsDepE(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_M25_FLASH_WRITE_STATUS: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Flash.MsgM25FlashWriteStatus(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_EPHEMERIS_GPS: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Observation.MsgEphemerisGps(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_COMMAND_OUTPUT: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Piksi.MsgCommandOutput(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_SSR_FLAG_IONO_GRID_POINTS: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Integrity.MsgSsrFlagIonoGridPoints(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_VEL_NED_COV_GNSS: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Navigation.MsgVelNedCovGnss(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_NETWORK_STATE_RESP: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Piksi.MsgNetworkStateResp(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_SSR_STEC_CORRECTION_DEP_A: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Ssr.MsgSsrStecCorrectionDepA(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_COMMAND_REQ: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Piksi.MsgCommandReq(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_ACKNOWLEDGE: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Integrity.MsgAcknowledge(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_TRACKING_IQ_DEP_A: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Tracking.MsgTrackingIqDepA(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_EPHEMERIS_GAL_DEP_A: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Observation.MsgEphemerisGalDepA(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_SPECAN: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Piksi.MsgSpecan(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_ACQ_SV_PROFILE_DEP: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Acquisition.MsgAcqSvProfileDep(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_UTC_TIME: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Navigation.MsgUtcTime(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_EPHEMERIS_DEP_D: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Observation.MsgEphemerisDepD(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_LINUX_PROCESS_SOCKET_QUEUES: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Linux.MsgLinuxProcessSocketQueues(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_UTC_TIME_GNSS: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Navigation.MsgUtcTimeGnss(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_NDB_EVENT: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Ndb.MsgNdbEvent(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_BOOTLOADER_HANDSHAKE_REQ: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Bootload.MsgBootloaderHandshakeReq(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_USER_DATA: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new User.MsgUserData(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_SENSOR_AID_EVENT: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new System.MsgSensorAidEvent(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_SSR_ORBIT_CLOCK_BOUNDS: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Ssr.MsgSsrOrbitClockBounds(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_POS_LLH_GNSS: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Navigation.MsgPosLlhGnss(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_INIT_BASE_DEP: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Piksi.MsgInitBaseDep(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_FILEIO_READ_REQ: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new FileIo.MsgFileioReadReq(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_TRACKING_IQ_DEP_B: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Tracking.MsgTrackingIqDepB(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_ACQ_RESULT_DEP_C: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Acquisition.MsgAcqResultDepC(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_COMMAND_RESP: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Piksi.MsgCommandResp(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_FILEIO_REMOVE: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new FileIo.MsgFileioRemove(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_OBS_DEP_C: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Observation.MsgObsDepC(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_SSR_TILE_DEFINITION_DEP_B: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Ssr.MsgSsrTileDefinitionDepB(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_CSAC_TELEMETRY_LABELS: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new System.MsgCsacTelemetryLabels(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_VEL_NED: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Navigation.MsgVelNed(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_SETTINGS_READ_BY_INDEX_RESP: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Settings.MsgSettingsReadByIndexResp(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_EPHEMERIS_QZSS: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Observation.MsgEphemerisQzss(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_SSR_STEC_CORRECTION: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Ssr.MsgSsrStecCorrection(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_BASELINE_ECEF_DEP_A: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Navigation.MsgBaselineEcefDepA(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_INS_UPDATES: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new System.MsgInsUpdates(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_POS_ECEF_COV: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Navigation.MsgPosEcefCov(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_VEL_NED_GNSS: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Navigation.MsgVelNedGnss(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_MASK_SATELLITE: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Piksi.MsgMaskSatellite(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_GROUP_DELAY_DEP_B: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Observation.MsgGroupDelayDepB(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_SSR_ORBIT_CLOCK_BOUNDS_DEGRADATION: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Ssr.MsgSsrOrbitClockBoundsDegradation(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_FLASH_ERASE: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Flash.MsgFlashErase(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_CW_START: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Piksi.MsgCwStart(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_SSR_ORBIT_CLOCK_DEP_A: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Ssr.MsgSsrOrbitClockDepA(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_DOPS: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Navigation.MsgDops(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_NETWORK_BANDWIDTH_USAGE: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Piksi.MsgNetworkBandwidthUsage(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_ECDSA_CERTIFICATE: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Signing.MsgEcdsaCertificate(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_POS_LLH_DEP_A: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Navigation.MsgPosLlhDepA(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_SV_AZ_EL: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Observation.MsgSvAzEl(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_FILEIO_READ_DIR_REQ: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new FileIo.MsgFileioReadDirReq(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_EPHEMERIS_DEP_B: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Observation.MsgEphemerisDepB(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_VEL_ECEF_COV: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Navigation.MsgVelEcefCov(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_DGNSS_STATUS: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new System.MsgDgnssStatus(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_SSR_TILE_DEFINITION_DEP_A: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Ssr.MsgSsrTileDefinitionDepA(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_LOG: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Logging.MsgLog(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_MASK_SATELLITE_DEP: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Piksi.MsgMaskSatelliteDep(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_EXT_EVENT: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new ExtEvents.MsgExtEvent(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_CELL_MODEM_STATUS: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Piksi.MsgCellModemStatus(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_ORIENT_QUAT: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Orientation.MsgOrientQuat(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_HEARTBEAT: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new System.MsgHeartbeat(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_ALMANAC_GPS_DEP: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Observation.MsgAlmanacGpsDep(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_NAP_DEVICE_DNA_REQ: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Bootload.MsgNapDeviceDnaReq(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_ALMANAC_GPS: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Observation.MsgAlmanacGps(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_VEL_ECEF_COV_GNSS: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Navigation.MsgVelEcefCovGnss(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_ED25519_SIGNATURE_DEP_A: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Signing.MsgEd25519SignatureDepA(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_ANGULAR_RATE: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Orientation.MsgAngularRate(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_VEL_BODY: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Navigation.MsgVelBody(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_CERTIFICATE_CHAIN: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Signing.MsgCertificateChain(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_SOLN_META_DEP_A: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new SolutionMeta.MsgSolnMetaDepA(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_SSR_GRIDDED_CORRECTION_DEP_A: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Ssr.MsgSsrGriddedCorrectionDepA(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_EPHEMERIS_GLO_DEP_C: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Observation.MsgEphemerisGloDepC(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_LINUX_PROCESS_FD_COUNT: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Linux.MsgLinuxProcessFdCount(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_FILEIO_READ_RESP: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new FileIo.MsgFileioReadResp(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_LINUX_SYS_STATE_DEP_A: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Linux.MsgLinuxSysStateDepA(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_SBAS_RAW: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Sbas.MsgSbasRaw(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_POS_ECEF_COV_GNSS: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Navigation.MsgPosEcefCovGnss(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_SSR_FLAG_IONO_GRID_POINT_SAT_LOS: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Integrity.MsgSsrFlagIonoGridPointSatLos(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_FILEIO_WRITE_REQ: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new FileIo.MsgFileioWriteReq(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_ACQ_SV_PROFILE: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Acquisition.MsgAcqSvProfile(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_EPHEMERIS_GLO_DEP_B: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Observation.MsgEphemerisGloDepB(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_LINUX_SOCKET_USAGE: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Linux.MsgLinuxSocketUsage(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_NETWORK_STATE_REQ: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Piksi.MsgNetworkStateReq(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_PROTECTION_LEVEL_DEP_A: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Navigation.MsgProtectionLevelDepA(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_IMU_RAW: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Imu.MsgImuRaw(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_RESET_DEP: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Piksi.MsgResetDep(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_MAG_RAW: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Mag.MsgMagRaw(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_STARTUP: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new System.MsgStartup(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_GLO_BIASES: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Observation.MsgGloBiases(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_TRACKING_STATE_DETAILED_DEP_A: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Tracking.MsgTrackingStateDetailedDepA(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_POS_LLH_COV_GNSS: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Navigation.MsgPosLlhCovGnss(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_SETTINGS_WRITE: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Settings.MsgSettingsWrite(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_SETTINGS_SAVE: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Settings.MsgSettingsSave(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_ALMANAC_GLO: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Observation.MsgAlmanacGlo(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_STM_FLASH_UNLOCK_SECTOR: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Flash.MsgStmFlashUnlockSector(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_GPS_TIME_GNSS: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Navigation.MsgGpsTimeGnss(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_FLASH_READ_REQ: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Flash.MsgFlashReadReq(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_EPHEMERIS_GLO: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Observation.MsgEphemerisGlo(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_BASELINE_HEADING_DEP_A: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Navigation.MsgBaselineHeadingDepA(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_SETTINGS_REGISTER: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Settings.MsgSettingsRegister(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_GNSS_CAPB: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Observation.MsgGnssCapb(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_TRACKING_STATE_DEP_B: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Tracking.MsgTrackingStateDepB(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_FWD: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Logging.MsgFwd(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_SOLN_META: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new SolutionMeta.MsgSolnMeta(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_OBS_DEP_A: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Observation.MsgObsDepA(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_DEVICE_MONITOR: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Piksi.MsgDeviceMonitor(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_LINUX_PROCESS_SOCKET_COUNTS: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Linux.MsgLinuxProcessSocketCounts(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_VEL_COG: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Navigation.MsgVelCog(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_PRINT_DEP: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Logging.MsgPrintDep(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_CW_RESULTS: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Piksi.MsgCwResults(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_NAP_DEVICE_DNA_RESP: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Bootload.MsgNapDeviceDnaResp(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_DOPS_DEP_A: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Navigation.MsgDopsDepA(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_POS_ECEF_DEP_A: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Navigation.MsgPosEcefDepA(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_SETTINGS_READ_RESP: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Settings.MsgSettingsReadResp(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_LINUX_MEM_STATE_DEP_A: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Linux.MsgLinuxMemStateDepA(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_EPHEMERIS_DEP_C: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Observation.MsgEphemerisDepC(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_FILEIO_WRITE_RESP: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new FileIo.MsgFileioWriteResp(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_WHEELTICK: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Vehicle.MsgWheeltick(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_UART_STATE_DEPA: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Piksi.MsgUartStateDepa(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_REFERENCE_FRAME_PARAM: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Navigation.MsgReferenceFrameParam(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_POSE_RELATIVE: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Navigation.MsgPoseRelative(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_IAR_STATE: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Piksi.MsgIarState(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_UART_STATE: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Piksi.MsgUartState(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_SSR_TILE_DEFINITION: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Ssr.MsgSsrTileDefinition(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_SSR_SATELLITE_APC: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Ssr.MsgSsrSatelliteApc(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_OSR: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Observation.MsgOsr(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_POS_LLH_COV: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Navigation.MsgPosLlhCov(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_GROUP_DELAY_DEP_A: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Observation.MsgGroupDelayDepA(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_PROTECTION_LEVEL: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Navigation.MsgProtectionLevel(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_OBS_DEP_B: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Observation.MsgObsDepB(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_POS_LLH: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Navigation.MsgPosLlh(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_FLASH_DONE: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Flash.MsgFlashDone(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_ACQ_RESULT_DEP_A: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Acquisition.MsgAcqResultDepA(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_SSR_CODE_BIASES: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Ssr.MsgSsrCodeBiases(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_SSR_GRIDDED_CORRECTION: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Ssr.MsgSsrGriddedCorrection(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_GROUP_META: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new System.MsgGroupMeta(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_FILEIO_CONFIG_RESP: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new FileIo.MsgFileioConfigResp(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_VEL_NED_DEP_A: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Navigation.MsgVelNedDepA(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_GNSS_TIME_OFFSET: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new System.MsgGnssTimeOffset(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_TRACKING_STATE_DEP_A: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Tracking.MsgTrackingStateDepA(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_INS_STATUS: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new System.MsgInsStatus(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_EPHEMERIS_GPS_DEP_F: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Observation.MsgEphemerisGpsDepF(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_LINUX_CPU_STATE_DEP_A: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Linux.MsgLinuxCpuStateDepA(_io__raw_payload, this, _root);
                        break;
                    }
                    case MSG_FLASH_READ_RESP: {
                        this._raw_payload = this._io.readBytes(header().length());
                        KaitaiStream _io__raw_payload = new ByteBufferKaitaiStream(_raw_payload);
                        this.payload = new Flash.MsgFlashReadResp(_io__raw_payload, this, _root);
                        break;
                    }
                    default: {
                        this.payload = this._io.readBytes(header().length());
                        break;
                    }
                    }
                } else {
                    this.payload = this._io.readBytes(header().length());
                }
            }
            this.crc = this._io.readU2le();
        }
        private SbpHeader header;
        private Object payload;
        private int crc;
        private Sbp _root;
        private Sbp _parent;
        private byte[] _raw_payload;
        public SbpHeader header() { return header; }
        public Object payload() { return payload; }
        public int crc() { return crc; }
        public Sbp _root() { return _root; }
        public Sbp _parent() { return _parent; }
        public byte[] _raw_payload() { return _raw_payload; }
    }
    public static class SbpHeader extends KaitaiStruct {
        public static SbpHeader fromFile(String fileName) throws IOException {
            return new SbpHeader(new ByteBufferKaitaiStream(fileName));
        }

        public SbpHeader(KaitaiStream _io) {
            this(_io, null, null);
        }

        public SbpHeader(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public SbpHeader(KaitaiStream _io, Sbp.Message _parent, Sbp _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.preamble = this._io.readBytes(1);
            if (!(Arrays.equals(preamble(), new byte[] { 85 }))) {
                throw new KaitaiStream.ValidationNotEqualError(new byte[] { 85 }, preamble(), _io(), "/types/sbp_header/seq/0");
            }
            this.msgType = Sbp.MsgIds.byId(this._io.readU2le());
            this.sender = this._io.readU2le();
            this.length = this._io.readU1();
        }
        private byte[] preamble;
        private MsgIds msgType;
        private int sender;
        private int length;
        private Sbp _root;
        private Sbp.Message _parent;
        public byte[] preamble() { return preamble; }
        public MsgIds msgType() { return msgType; }
        public int sender() { return sender; }
        public int length() { return length; }
        public Sbp _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }
    private ArrayList<Message> message;
    private Sbp _root;
    private KaitaiStruct _parent;
    public ArrayList<Message> message() { return message; }
    public Sbp _root() { return _root; }
    public KaitaiStruct _parent() { return _parent; }
}
