<?php
// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

namespace {
    class Sbp extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Kaitai\Struct\Struct $_parent = null, \Sbp $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_message = [];
            $i = 0;
            while (!$this->_io->isEof()) {
                $this->_m_message[] = new \Sbp\Message($this->_io, $this, $this->_root);
                $i++;
            }
        }
        protected $_m_message;
        public function message() { return $this->_m_message; }
    }
}

namespace Sbp {
    class Message extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp $_parent = null, \Sbp $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_header = new \Sbp\SbpHeader($this->_io, $this, $this->_root);
            switch ($this->header()->msgType()) {
                case \Sbp\MsgIds::MSG_BASELINE_ECEF:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Navigation\MsgBaselineEcef($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_EPHEMERIS_BDS:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Observation\MsgEphemerisBds($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_EPHEMERIS_GLO_DEP_D:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Observation\MsgEphemerisGloDepD($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_SETTINGS_READ_BY_INDEX_REQ:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Settings\MsgSettingsReadByIndexReq($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_SSR_FLAG_HIGH_LEVEL:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Integrity\MsgSsrFlagHighLevel($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_FILEIO_CONFIG_REQ:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \FileIo\MsgFileioConfigReq($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_ODOMETRY:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Vehicle\MsgOdometry($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_SSR_STEC_CORRECTION_DEP:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Ssr\MsgSsrStecCorrectionDep($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_ED25519_SIGNATURE_DEP_B:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Signing\MsgEd25519SignatureDepB($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_STM_UNIQUE_ID_REQ:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Flash\MsgStmUniqueIdReq($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_FRONT_END_GAIN:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Piksi\MsgFrontEndGain($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_BASE_POS_LLH:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Observation\MsgBasePosLlh($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_EPHEMERIS_DEP_A:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Observation\MsgEphemerisDepA($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_SSR_ORBIT_CLOCK:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Ssr\MsgSsrOrbitClock($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_RESET:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Piksi\MsgReset($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_STM_FLASH_LOCK_SECTOR:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Flash\MsgStmFlashLockSector($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_LINUX_PROCESS_FD_SUMMARY:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Linux\MsgLinuxProcessFdSummary($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_STATUS_JOURNAL:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \System\MsgStatusJournal($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_CSAC_TELEMETRY:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \System\MsgCsacTelemetry($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_AGE_CORRECTIONS:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Navigation\MsgAgeCorrections($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_ORIENT_EULER:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Orientation\MsgOrientEuler($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_SSR_SATELLITE_APC_DEP:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Ssr\MsgSsrSatelliteApcDep($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_BASELINE_NED:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Navigation\MsgBaselineNed($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_VEL_ECEF_GNSS:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Navigation\MsgVelEcefGnss($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_MEASUREMENT_STATE:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Tracking\MsgMeasurementState($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_IONO:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Observation\MsgIono($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_BASE_POS_ECEF:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Observation\MsgBasePosEcef($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_FLASH_PROGRAM:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Flash\MsgFlashProgram($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_ACQ_RESULT:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Acquisition\MsgAcqResult($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_PPS_TIME:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \System\MsgPpsTime($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_OBS:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Observation\MsgObs($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_EPHEMERIS_SBAS_DEP_B:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Observation\MsgEphemerisSbasDepB($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_TRACKING_IQ:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Tracking\MsgTrackingIq($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_SSR_FLAG_IONO_TILE_SAT_LOS:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Integrity\MsgSsrFlagIonoTileSatLos($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_TRACKING_STATE_DETAILED_DEP:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Tracking\MsgTrackingStateDetailedDep($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_BOOTLOADER_HANDSHAKE_DEP_A:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Bootload\MsgBootloaderHandshakeDepA($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_UTC_LEAP_SECOND:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Navigation\MsgUtcLeapSecond($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_SSR_GRIDDED_CORRECTION_NO_STD_DEP_A:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Ssr\MsgSsrGriddedCorrectionNoStdDepA($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_BOOTLOADER_HANDSHAKE_RESP:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Bootload\MsgBootloaderHandshakeResp($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_BASELINE_HEADING:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Orientation\MsgBaselineHeading($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_STATUS_REPORT:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \System\MsgStatusReport($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_VEL_NED_COV:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Navigation\MsgVelNedCov($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_SET_TIME:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Piksi\MsgSetTime($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_LINUX_CPU_STATE:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Linux\MsgLinuxCpuState($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_GPS_TIME_DEP_A:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Navigation\MsgGpsTimeDepA($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_EPHEMERIS_SBAS_DEP_A:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Observation\MsgEphemerisSbasDepA($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_ACQ_RESULT_DEP_B:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Acquisition\MsgAcqResultDepB($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_SETTINGS_REGISTER_RESP:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Settings\MsgSettingsRegisterResp($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_EPHEMERIS_GAL:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Observation\MsgEphemerisGal($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_BOOTLOADER_JUMP_TO_APP:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Bootload\MsgBootloaderJumpToApp($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_SSR_PHASE_BIASES:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Ssr\MsgSsrPhaseBiases($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_FILEIO_READ_DIR_RESP:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \FileIo\MsgFileioReadDirResp($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_POS_ECEF_GNSS:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Navigation\MsgPosEcefGnss($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_ALMANAC_GLO_DEP:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Observation\MsgAlmanacGloDep($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_VEL_ECEF_DEP_A:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Navigation\MsgVelEcefDepA($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_THREAD_STATE:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Piksi\MsgThreadState($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_GPS_TIME:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Navigation\MsgGpsTime($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_SSR_CODE_PHASE_BIASES_BOUNDS:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Ssr\MsgSsrCodePhaseBiasesBounds($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_SETTINGS_WRITE_RESP:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Settings\MsgSettingsWriteResp($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_TRACKING_STATE:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Tracking\MsgTrackingState($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_VEL_ECEF:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Navigation\MsgVelEcef($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_EPHEMERIS_GLO_DEP_A:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Observation\MsgEphemerisGloDepA($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_ED25519_CERTIFICATE_DEP:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Signing\MsgEd25519CertificateDep($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_BASELINE_NED_DEP_A:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Navigation\MsgBaselineNedDepA($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_SPECAN_DEP:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Piksi\MsgSpecanDep($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_EPHEMERIS_SBAS:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Observation\MsgEphemerisSbas($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_GROUP_DELAY:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Observation\MsgGroupDelay($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_POS_ECEF:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Navigation\MsgPosEcef($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_ALMANAC:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Piksi\MsgAlmanac($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_SETTINGS_READ_REQ:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Settings\MsgSettingsReadReq($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_SSR_FLAG_TROPO_GRID_POINTS:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Integrity\MsgSsrFlagTropoGridPoints($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_SSR_GRIDDED_CORRECTION_BOUNDS:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Ssr\MsgSsrGriddedCorrectionBounds($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_STM_UNIQUE_ID_RESP:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Flash\MsgStmUniqueIdResp($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_TEL_SV:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Telemetry\MsgTelSv($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_SSR_FLAG_SATELLITES:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Integrity\MsgSsrFlagSatellites($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_IMU_AUX:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Imu\MsgImuAux($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_SSR_GRID_DEFINITION_DEP_A:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Ssr\MsgSsrGridDefinitionDepA($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_POS_LLH_ACC:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Navigation\MsgPosLlhAcc($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_SV_CONFIGURATION_GPS_DEP:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Observation\MsgSvConfigurationGpsDep($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_LINUX_MEM_STATE:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Linux\MsgLinuxMemState($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_LINUX_SYS_STATE:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Linux\MsgLinuxSysState($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_SETTINGS_READ_BY_INDEX_DONE:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Settings\MsgSettingsReadByIndexDone($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_RESET_FILTERS:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Piksi\MsgResetFilters($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_ECDSA_SIGNATURE:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Signing\MsgEcdsaSignature($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_EPHEMERIS_GPS_DEP_E:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Observation\MsgEphemerisGpsDepE($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_M25_FLASH_WRITE_STATUS:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Flash\MsgM25FlashWriteStatus($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_EPHEMERIS_GPS:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Observation\MsgEphemerisGps($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_COMMAND_OUTPUT:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Piksi\MsgCommandOutput($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_SSR_FLAG_IONO_GRID_POINTS:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Integrity\MsgSsrFlagIonoGridPoints($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_VEL_NED_COV_GNSS:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Navigation\MsgVelNedCovGnss($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_NETWORK_STATE_RESP:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Piksi\MsgNetworkStateResp($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_SSR_STEC_CORRECTION_DEP_A:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Ssr\MsgSsrStecCorrectionDepA($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_COMMAND_REQ:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Piksi\MsgCommandReq($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_ACKNOWLEDGE:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Integrity\MsgAcknowledge($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_TRACKING_IQ_DEP_A:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Tracking\MsgTrackingIqDepA($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_EPHEMERIS_GAL_DEP_A:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Observation\MsgEphemerisGalDepA($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_SPECAN:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Piksi\MsgSpecan($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_ACQ_SV_PROFILE_DEP:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Acquisition\MsgAcqSvProfileDep($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_UTC_TIME:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Navigation\MsgUtcTime($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_EPHEMERIS_DEP_D:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Observation\MsgEphemerisDepD($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_LINUX_PROCESS_SOCKET_QUEUES:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Linux\MsgLinuxProcessSocketQueues($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_UTC_TIME_GNSS:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Navigation\MsgUtcTimeGnss($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_NDB_EVENT:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Ndb\MsgNdbEvent($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_BOOTLOADER_HANDSHAKE_REQ:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Bootload\MsgBootloaderHandshakeReq($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_USER_DATA:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \User\MsgUserData($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_SENSOR_AID_EVENT:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \System\MsgSensorAidEvent($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_SSR_ORBIT_CLOCK_BOUNDS:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Ssr\MsgSsrOrbitClockBounds($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_POS_LLH_GNSS:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Navigation\MsgPosLlhGnss($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_INIT_BASE_DEP:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Piksi\MsgInitBaseDep($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_FILEIO_READ_REQ:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \FileIo\MsgFileioReadReq($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_TRACKING_IQ_DEP_B:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Tracking\MsgTrackingIqDepB($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_ACQ_RESULT_DEP_C:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Acquisition\MsgAcqResultDepC($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_COMMAND_RESP:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Piksi\MsgCommandResp($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_FILEIO_REMOVE:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \FileIo\MsgFileioRemove($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_OBS_DEP_C:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Observation\MsgObsDepC($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_SSR_TILE_DEFINITION_DEP_B:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Ssr\MsgSsrTileDefinitionDepB($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_CSAC_TELEMETRY_LABELS:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \System\MsgCsacTelemetryLabels($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_VEL_NED:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Navigation\MsgVelNed($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_SETTINGS_READ_BY_INDEX_RESP:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Settings\MsgSettingsReadByIndexResp($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_EPHEMERIS_QZSS:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Observation\MsgEphemerisQzss($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_SSR_STEC_CORRECTION:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Ssr\MsgSsrStecCorrection($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_BASELINE_ECEF_DEP_A:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Navigation\MsgBaselineEcefDepA($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_INS_UPDATES:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \System\MsgInsUpdates($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_POS_ECEF_COV:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Navigation\MsgPosEcefCov($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_VEL_NED_GNSS:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Navigation\MsgVelNedGnss($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_MASK_SATELLITE:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Piksi\MsgMaskSatellite($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_GROUP_DELAY_DEP_B:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Observation\MsgGroupDelayDepB($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_SSR_ORBIT_CLOCK_BOUNDS_DEGRADATION:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Ssr\MsgSsrOrbitClockBoundsDegradation($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_FLASH_ERASE:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Flash\MsgFlashErase($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_CW_START:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Piksi\MsgCwStart($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_SSR_ORBIT_CLOCK_DEP_A:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Ssr\MsgSsrOrbitClockDepA($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_DOPS:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Navigation\MsgDops($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_NETWORK_BANDWIDTH_USAGE:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Piksi\MsgNetworkBandwidthUsage($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_ECDSA_CERTIFICATE:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Signing\MsgEcdsaCertificate($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_POS_LLH_DEP_A:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Navigation\MsgPosLlhDepA($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_SV_AZ_EL:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Observation\MsgSvAzEl($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_FILEIO_READ_DIR_REQ:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \FileIo\MsgFileioReadDirReq($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_EPHEMERIS_DEP_B:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Observation\MsgEphemerisDepB($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_VEL_ECEF_COV:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Navigation\MsgVelEcefCov($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_DGNSS_STATUS:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \System\MsgDgnssStatus($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_SSR_TILE_DEFINITION_DEP_A:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Ssr\MsgSsrTileDefinitionDepA($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_LOG:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Logging\MsgLog($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_MASK_SATELLITE_DEP:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Piksi\MsgMaskSatelliteDep($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_EXT_EVENT:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \ExtEvents\MsgExtEvent($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_CELL_MODEM_STATUS:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Piksi\MsgCellModemStatus($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_ORIENT_QUAT:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Orientation\MsgOrientQuat($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_HEARTBEAT:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \System\MsgHeartbeat($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_ALMANAC_GPS_DEP:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Observation\MsgAlmanacGpsDep($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_NAP_DEVICE_DNA_REQ:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Bootload\MsgNapDeviceDnaReq($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_ALMANAC_GPS:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Observation\MsgAlmanacGps($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_VEL_ECEF_COV_GNSS:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Navigation\MsgVelEcefCovGnss($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_ED25519_SIGNATURE_DEP_A:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Signing\MsgEd25519SignatureDepA($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_ANGULAR_RATE:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Orientation\MsgAngularRate($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_VEL_BODY:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Navigation\MsgVelBody($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_CERTIFICATE_CHAIN:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Signing\MsgCertificateChain($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_SOLN_META_DEP_A:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \SolutionMeta\MsgSolnMetaDepA($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_SSR_GRIDDED_CORRECTION_DEP_A:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Ssr\MsgSsrGriddedCorrectionDepA($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_EPHEMERIS_GLO_DEP_C:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Observation\MsgEphemerisGloDepC($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_LINUX_PROCESS_FD_COUNT:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Linux\MsgLinuxProcessFdCount($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_FILEIO_READ_RESP:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \FileIo\MsgFileioReadResp($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_LINUX_SYS_STATE_DEP_A:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Linux\MsgLinuxSysStateDepA($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_SBAS_RAW:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Sbas\MsgSbasRaw($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_POS_ECEF_COV_GNSS:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Navigation\MsgPosEcefCovGnss($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_SSR_FLAG_IONO_GRID_POINT_SAT_LOS:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Integrity\MsgSsrFlagIonoGridPointSatLos($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_FILEIO_WRITE_REQ:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \FileIo\MsgFileioWriteReq($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_ACQ_SV_PROFILE:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Acquisition\MsgAcqSvProfile($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_EPHEMERIS_GLO_DEP_B:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Observation\MsgEphemerisGloDepB($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_LINUX_SOCKET_USAGE:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Linux\MsgLinuxSocketUsage($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_NETWORK_STATE_REQ:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Piksi\MsgNetworkStateReq($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_PROTECTION_LEVEL_DEP_A:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Navigation\MsgProtectionLevelDepA($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_IMU_RAW:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Imu\MsgImuRaw($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_RESET_DEP:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Piksi\MsgResetDep($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_MAG_RAW:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Mag\MsgMagRaw($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_STARTUP:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \System\MsgStartup($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_GLO_BIASES:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Observation\MsgGloBiases($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_TRACKING_STATE_DETAILED_DEP_A:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Tracking\MsgTrackingStateDetailedDepA($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_POS_LLH_COV_GNSS:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Navigation\MsgPosLlhCovGnss($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_SETTINGS_WRITE:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Settings\MsgSettingsWrite($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_SETTINGS_SAVE:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Settings\MsgSettingsSave($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_ALMANAC_GLO:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Observation\MsgAlmanacGlo($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_STM_FLASH_UNLOCK_SECTOR:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Flash\MsgStmFlashUnlockSector($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_GPS_TIME_GNSS:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Navigation\MsgGpsTimeGnss($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_FLASH_READ_REQ:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Flash\MsgFlashReadReq($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_EPHEMERIS_GLO:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Observation\MsgEphemerisGlo($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_BASELINE_HEADING_DEP_A:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Navigation\MsgBaselineHeadingDepA($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_SETTINGS_REGISTER:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Settings\MsgSettingsRegister($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_GNSS_CAPB:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Observation\MsgGnssCapb($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_TRACKING_STATE_DEP_B:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Tracking\MsgTrackingStateDepB($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_FWD:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Logging\MsgFwd($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_SOLN_META:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \SolutionMeta\MsgSolnMeta($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_OBS_DEP_A:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Observation\MsgObsDepA($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_DEVICE_MONITOR:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Piksi\MsgDeviceMonitor($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_LINUX_PROCESS_SOCKET_COUNTS:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Linux\MsgLinuxProcessSocketCounts($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_VEL_COG:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Navigation\MsgVelCog($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_PRINT_DEP:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Logging\MsgPrintDep($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_CW_RESULTS:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Piksi\MsgCwResults($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_NAP_DEVICE_DNA_RESP:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Bootload\MsgNapDeviceDnaResp($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_DOPS_DEP_A:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Navigation\MsgDopsDepA($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_POS_ECEF_DEP_A:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Navigation\MsgPosEcefDepA($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_SETTINGS_READ_RESP:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Settings\MsgSettingsReadResp($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_LINUX_MEM_STATE_DEP_A:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Linux\MsgLinuxMemStateDepA($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_EPHEMERIS_DEP_C:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Observation\MsgEphemerisDepC($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_FILEIO_WRITE_RESP:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \FileIo\MsgFileioWriteResp($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_WHEELTICK:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Vehicle\MsgWheeltick($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_UART_STATE_DEPA:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Piksi\MsgUartStateDepa($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_REFERENCE_FRAME_PARAM:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Navigation\MsgReferenceFrameParam($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_POSE_RELATIVE:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Navigation\MsgPoseRelative($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_IAR_STATE:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Piksi\MsgIarState($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_UART_STATE:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Piksi\MsgUartState($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_SSR_TILE_DEFINITION:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Ssr\MsgSsrTileDefinition($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_SSR_SATELLITE_APC:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Ssr\MsgSsrSatelliteApc($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_OSR:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Observation\MsgOsr($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_POS_LLH_COV:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Navigation\MsgPosLlhCov($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_GROUP_DELAY_DEP_A:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Observation\MsgGroupDelayDepA($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_PROTECTION_LEVEL:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Navigation\MsgProtectionLevel($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_OBS_DEP_B:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Observation\MsgObsDepB($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_POS_LLH:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Navigation\MsgPosLlh($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_FLASH_DONE:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Flash\MsgFlashDone($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_ACQ_RESULT_DEP_A:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Acquisition\MsgAcqResultDepA($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_SSR_CODE_BIASES:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Ssr\MsgSsrCodeBiases($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_SSR_GRIDDED_CORRECTION:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Ssr\MsgSsrGriddedCorrection($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_GROUP_META:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \System\MsgGroupMeta($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_FILEIO_CONFIG_RESP:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \FileIo\MsgFileioConfigResp($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_VEL_NED_DEP_A:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Navigation\MsgVelNedDepA($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_GNSS_TIME_OFFSET:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \System\MsgGnssTimeOffset($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_TRACKING_STATE_DEP_A:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Tracking\MsgTrackingStateDepA($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_INS_STATUS:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \System\MsgInsStatus($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_EPHEMERIS_GPS_DEP_F:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Observation\MsgEphemerisGpsDepF($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_LINUX_CPU_STATE_DEP_A:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Linux\MsgLinuxCpuStateDepA($_io__raw_payload, $this, $this->_root);
                    break;
                case \Sbp\MsgIds::MSG_FLASH_READ_RESP:
                    $this->_m__raw_payload = $this->_io->readBytes($this->header()->length());
                    $_io__raw_payload = new \Kaitai\Struct\Stream($this->_m__raw_payload);
                    $this->_m_payload = new \Flash\MsgFlashReadResp($_io__raw_payload, $this, $this->_root);
                    break;
                default:
                    $this->_m_payload = $this->_io->readBytes($this->header()->length());
                    break;
            }
            $this->_m_crc = $this->_io->readU2le();
        }
        protected $_m_header;
        protected $_m_payload;
        protected $_m_crc;
        protected $_m__raw_payload;
        public function header() { return $this->_m_header; }
        public function payload() { return $this->_m_payload; }
        public function crc() { return $this->_m_crc; }
        public function _raw_payload() { return $this->_m__raw_payload; }
    }
}

namespace Sbp {
    class SbpHeader extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Sbp $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_preamble = $this->_io->readBytes(1);
            if (!($this->preamble() == "\x55")) {
                throw new \Kaitai\Struct\Error\ValidationNotEqualError("\x55", $this->preamble(), $this->_io(), "/types/sbp_header/seq/0");
            }
            $this->_m_msgType = $this->_io->readU2le();
            $this->_m_sender = $this->_io->readU2le();
            $this->_m_length = $this->_io->readU1();
        }
        protected $_m_preamble;
        protected $_m_msgType;
        protected $_m_sender;
        protected $_m_length;
        public function preamble() { return $this->_m_preamble; }
        public function msgType() { return $this->_m_msgType; }
        public function sender() { return $this->_m_sender; }
        public function length() { return $this->_m_length; }
    }
}

namespace Sbp {
    class MsgIds {
        const MSG_PRINT_DEP = 16;
        const MSG_TRACKING_STATE_DETAILED_DEP = 17;
        const MSG_TRACKING_STATE_DEP_B = 19;
        const MSG_ACQ_RESULT_DEP_B = 20;
        const MSG_ACQ_RESULT_DEP_A = 21;
        const MSG_TRACKING_STATE_DEP_A = 22;
        const MSG_THREAD_STATE = 23;
        const MSG_UART_STATE_DEPA = 24;
        const MSG_IAR_STATE = 25;
        const MSG_EPHEMERIS_DEP_A = 26;
        const MSG_MASK_SATELLITE_DEP = 27;
        const MSG_TRACKING_IQ_DEP_A = 28;
        const MSG_UART_STATE = 29;
        const MSG_ACQ_SV_PROFILE_DEP = 30;
        const MSG_ACQ_RESULT_DEP_C = 31;
        const MSG_TRACKING_STATE_DETAILED_DEP_A = 33;
        const MSG_RESET_FILTERS = 34;
        const MSG_INIT_BASE_DEP = 35;
        const MSG_MASK_SATELLITE = 43;
        const MSG_TRACKING_IQ_DEP_B = 44;
        const MSG_TRACKING_IQ = 45;
        const MSG_ACQ_SV_PROFILE = 46;
        const MSG_ACQ_RESULT = 47;
        const MSG_TRACKING_STATE = 65;
        const MSG_OBS_DEP_B = 67;
        const MSG_BASE_POS_LLH = 68;
        const MSG_OBS_DEP_A = 69;
        const MSG_EPHEMERIS_DEP_B = 70;
        const MSG_EPHEMERIS_DEP_C = 71;
        const MSG_BASE_POS_ECEF = 72;
        const MSG_OBS_DEP_C = 73;
        const MSG_OBS = 74;
        const MSG_SPECAN_DEP = 80;
        const MSG_SPECAN = 81;
        const MSG_MEASUREMENT_STATE = 97;
        const MSG_SET_TIME = 104;
        const MSG_ALMANAC = 105;
        const MSG_ALMANAC_GPS_DEP = 112;
        const MSG_ALMANAC_GLO_DEP = 113;
        const MSG_ALMANAC_GPS = 114;
        const MSG_ALMANAC_GLO = 115;
        const MSG_GLO_BIASES = 117;
        const MSG_EPHEMERIS_DEP_D = 128;
        const MSG_EPHEMERIS_GPS_DEP_E = 129;
        const MSG_EPHEMERIS_SBAS_DEP_A = 130;
        const MSG_EPHEMERIS_GLO_DEP_A = 131;
        const MSG_EPHEMERIS_SBAS_DEP_B = 132;
        const MSG_EPHEMERIS_GLO_DEP_B = 133;
        const MSG_EPHEMERIS_GPS_DEP_F = 134;
        const MSG_EPHEMERIS_GLO_DEP_C = 135;
        const MSG_EPHEMERIS_GLO_DEP_D = 136;
        const MSG_EPHEMERIS_BDS = 137;
        const MSG_EPHEMERIS_GPS = 138;
        const MSG_EPHEMERIS_GLO = 139;
        const MSG_EPHEMERIS_SBAS = 140;
        const MSG_EPHEMERIS_GAL = 141;
        const MSG_EPHEMERIS_QZSS = 142;
        const MSG_IONO = 144;
        const MSG_SV_CONFIGURATION_GPS_DEP = 145;
        const MSG_GROUP_DELAY_DEP_A = 146;
        const MSG_GROUP_DELAY_DEP_B = 147;
        const MSG_GROUP_DELAY = 148;
        const MSG_EPHEMERIS_GAL_DEP_A = 149;
        const MSG_GNSS_CAPB = 150;
        const MSG_SV_AZ_EL = 151;
        const MSG_SETTINGS_WRITE = 160;
        const MSG_SETTINGS_SAVE = 161;
        const MSG_SETTINGS_READ_BY_INDEX_REQ = 162;
        const MSG_FILEIO_READ_RESP = 163;
        const MSG_SETTINGS_READ_REQ = 164;
        const MSG_SETTINGS_READ_RESP = 165;
        const MSG_SETTINGS_READ_BY_INDEX_DONE = 166;
        const MSG_SETTINGS_READ_BY_INDEX_RESP = 167;
        const MSG_FILEIO_READ_REQ = 168;
        const MSG_FILEIO_READ_DIR_REQ = 169;
        const MSG_FILEIO_READ_DIR_RESP = 170;
        const MSG_FILEIO_WRITE_RESP = 171;
        const MSG_FILEIO_REMOVE = 172;
        const MSG_FILEIO_WRITE_REQ = 173;
        const MSG_SETTINGS_REGISTER = 174;
        const MSG_SETTINGS_WRITE_RESP = 175;
        const MSG_BOOTLOADER_HANDSHAKE_DEP_A = 176;
        const MSG_BOOTLOADER_JUMP_TO_APP = 177;
        const MSG_RESET_DEP = 178;
        const MSG_BOOTLOADER_HANDSHAKE_REQ = 179;
        const MSG_BOOTLOADER_HANDSHAKE_RESP = 180;
        const MSG_DEVICE_MONITOR = 181;
        const MSG_RESET = 182;
        const MSG_COMMAND_REQ = 184;
        const MSG_COMMAND_RESP = 185;
        const MSG_NETWORK_STATE_REQ = 186;
        const MSG_NETWORK_STATE_RESP = 187;
        const MSG_COMMAND_OUTPUT = 188;
        const MSG_NETWORK_BANDWIDTH_USAGE = 189;
        const MSG_CELL_MODEM_STATUS = 190;
        const MSG_FRONT_END_GAIN = 191;
        const MSG_CW_RESULTS = 192;
        const MSG_CW_START = 193;
        const MSG_NAP_DEVICE_DNA_RESP = 221;
        const MSG_NAP_DEVICE_DNA_REQ = 222;
        const MSG_FLASH_DONE = 224;
        const MSG_FLASH_READ_RESP = 225;
        const MSG_FLASH_ERASE = 226;
        const MSG_STM_FLASH_LOCK_SECTOR = 227;
        const MSG_STM_FLASH_UNLOCK_SECTOR = 228;
        const MSG_STM_UNIQUE_ID_RESP = 229;
        const MSG_FLASH_PROGRAM = 230;
        const MSG_FLASH_READ_REQ = 231;
        const MSG_STM_UNIQUE_ID_REQ = 232;
        const MSG_M25_FLASH_WRITE_STATUS = 243;
        const MSG_GPS_TIME_DEP_A = 256;
        const MSG_EXT_EVENT = 257;
        const MSG_GPS_TIME = 258;
        const MSG_UTC_TIME = 259;
        const MSG_GPS_TIME_GNSS = 260;
        const MSG_UTC_TIME_GNSS = 261;
        const MSG_TEL_SV = 288;
        const MSG_SETTINGS_REGISTER_RESP = 431;
        const MSG_POS_ECEF_DEP_A = 512;
        const MSG_POS_LLH_DEP_A = 513;
        const MSG_BASELINE_ECEF_DEP_A = 514;
        const MSG_BASELINE_NED_DEP_A = 515;
        const MSG_VEL_ECEF_DEP_A = 516;
        const MSG_VEL_NED_DEP_A = 517;
        const MSG_DOPS_DEP_A = 518;
        const MSG_BASELINE_HEADING_DEP_A = 519;
        const MSG_DOPS = 520;
        const MSG_POS_ECEF = 521;
        const MSG_POS_LLH = 522;
        const MSG_BASELINE_ECEF = 523;
        const MSG_BASELINE_NED = 524;
        const MSG_VEL_ECEF = 525;
        const MSG_VEL_NED = 526;
        const MSG_BASELINE_HEADING = 527;
        const MSG_AGE_CORRECTIONS = 528;
        const MSG_POS_LLH_COV = 529;
        const MSG_VEL_NED_COV = 530;
        const MSG_VEL_BODY = 531;
        const MSG_POS_ECEF_COV = 532;
        const MSG_VEL_ECEF_COV = 533;
        const MSG_PROTECTION_LEVEL_DEP_A = 534;
        const MSG_PROTECTION_LEVEL = 535;
        const MSG_POS_LLH_ACC = 536;
        const MSG_VEL_COG = 540;
        const MSG_ORIENT_QUAT = 544;
        const MSG_ORIENT_EULER = 545;
        const MSG_ANGULAR_RATE = 546;
        const MSG_POS_ECEF_GNSS = 553;
        const MSG_POS_LLH_GNSS = 554;
        const MSG_VEL_ECEF_GNSS = 557;
        const MSG_VEL_NED_GNSS = 558;
        const MSG_POS_LLH_COV_GNSS = 561;
        const MSG_VEL_NED_COV_GNSS = 562;
        const MSG_POS_ECEF_COV_GNSS = 564;
        const MSG_VEL_ECEF_COV_GNSS = 565;
        const MSG_UTC_LEAP_SECOND = 570;
        const MSG_REFERENCE_FRAME_PARAM = 580;
        const MSG_POSE_RELATIVE = 581;
        const MSG_NDB_EVENT = 1024;
        const MSG_LOG = 1025;
        const MSG_FWD = 1026;
        const MSG_SSR_ORBIT_CLOCK_DEP_A = 1500;
        const MSG_SSR_ORBIT_CLOCK = 1501;
        const MSG_SSR_ORBIT_CLOCK_BOUNDS = 1502;
        const MSG_SSR_ORBIT_CLOCK_BOUNDS_DEGRADATION = 1503;
        const MSG_SSR_CODE_BIASES = 1505;
        const MSG_SSR_PHASE_BIASES = 1510;
        const MSG_SSR_STEC_CORRECTION_DEP_A = 1515;
        const MSG_SSR_CODE_PHASE_BIASES_BOUNDS = 1516;
        const MSG_SSR_GRIDDED_CORRECTION_NO_STD_DEP_A = 1520;
        const MSG_SSR_GRID_DEFINITION_DEP_A = 1525;
        const MSG_SSR_TILE_DEFINITION_DEP_A = 1526;
        const MSG_SSR_TILE_DEFINITION_DEP_B = 1527;
        const MSG_SSR_TILE_DEFINITION = 1528;
        const MSG_SSR_GRIDDED_CORRECTION_DEP_A = 1530;
        const MSG_SSR_STEC_CORRECTION_DEP = 1531;
        const MSG_SSR_GRIDDED_CORRECTION = 1532;
        const MSG_SSR_STEC_CORRECTION = 1533;
        const MSG_SSR_GRIDDED_CORRECTION_BOUNDS = 1534;
        const MSG_SSR_SATELLITE_APC_DEP = 1540;
        const MSG_SSR_SATELLITE_APC = 1541;
        const MSG_OSR = 1600;
        const MSG_USER_DATA = 2048;
        const MSG_IMU_RAW = 2304;
        const MSG_IMU_AUX = 2305;
        const MSG_MAG_RAW = 2306;
        const MSG_ODOMETRY = 2307;
        const MSG_WHEELTICK = 2308;
        const MSG_SSR_FLAG_HIGH_LEVEL = 3001;
        const MSG_SSR_FLAG_SATELLITES = 3005;
        const MSG_SSR_FLAG_TROPO_GRID_POINTS = 3011;
        const MSG_SSR_FLAG_IONO_GRID_POINTS = 3015;
        const MSG_SSR_FLAG_IONO_TILE_SAT_LOS = 3021;
        const MSG_SSR_FLAG_IONO_GRID_POINT_SAT_LOS = 3025;
        const MSG_ACKNOWLEDGE = 3026;
        const MSG_ED25519_SIGNATURE_DEP_A = 3073;
        const MSG_ED25519_CERTIFICATE_DEP = 3074;
        const MSG_ED25519_SIGNATURE_DEP_B = 3075;
        const MSG_ECDSA_CERTIFICATE = 3076;
        const MSG_CERTIFICATE_CHAIN = 3077;
        const MSG_ECDSA_SIGNATURE = 3078;
        const MSG_FILEIO_CONFIG_REQ = 4097;
        const MSG_FILEIO_CONFIG_RESP = 4098;
        const MSG_SBAS_RAW = 30583;
        const MSG_LINUX_CPU_STATE_DEP_A = 32512;
        const MSG_LINUX_MEM_STATE_DEP_A = 32513;
        const MSG_LINUX_SYS_STATE_DEP_A = 32514;
        const MSG_LINUX_PROCESS_SOCKET_COUNTS = 32515;
        const MSG_LINUX_PROCESS_SOCKET_QUEUES = 32516;
        const MSG_LINUX_SOCKET_USAGE = 32517;
        const MSG_LINUX_PROCESS_FD_COUNT = 32518;
        const MSG_LINUX_PROCESS_FD_SUMMARY = 32519;
        const MSG_LINUX_CPU_STATE = 32520;
        const MSG_LINUX_MEM_STATE = 32521;
        const MSG_LINUX_SYS_STATE = 32522;
        const MSG_STARTUP = 65280;
        const MSG_DGNSS_STATUS = 65282;
        const MSG_INS_STATUS = 65283;
        const MSG_CSAC_TELEMETRY = 65284;
        const MSG_CSAC_TELEMETRY_LABELS = 65285;
        const MSG_INS_UPDATES = 65286;
        const MSG_GNSS_TIME_OFFSET = 65287;
        const MSG_PPS_TIME = 65288;
        const MSG_SENSOR_AID_EVENT = 65289;
        const MSG_GROUP_META = 65290;
        const MSG_SOLN_META = 65294;
        const MSG_SOLN_META_DEP_A = 65295;
        const MSG_STATUS_JOURNAL = 65533;
        const MSG_STATUS_REPORT = 65534;
        const MSG_HEARTBEAT = 65535;
    }
}
