# This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

use strict;
use warnings;
use IO::KaitaiStruct 0.009_000;

########################################################################
package Sbp;

our @ISA = 'IO::KaitaiStruct::Struct';

sub from_file {
    my ($class, $filename) = @_;
    my $fd;

    open($fd, '<', $filename) or return undef;
    binmode($fd);
    return new($class, IO::KaitaiStruct::Stream->new($fd));
}

our $MSG_IDS_MSG_PRINT_DEP = 16;
our $MSG_IDS_MSG_TRACKING_STATE_DETAILED_DEP = 17;
our $MSG_IDS_MSG_TRACKING_STATE_DEP_B = 19;
our $MSG_IDS_MSG_ACQ_RESULT_DEP_B = 20;
our $MSG_IDS_MSG_ACQ_RESULT_DEP_A = 21;
our $MSG_IDS_MSG_TRACKING_STATE_DEP_A = 22;
our $MSG_IDS_MSG_THREAD_STATE = 23;
our $MSG_IDS_MSG_UART_STATE_DEPA = 24;
our $MSG_IDS_MSG_IAR_STATE = 25;
our $MSG_IDS_MSG_EPHEMERIS_DEP_A = 26;
our $MSG_IDS_MSG_MASK_SATELLITE_DEP = 27;
our $MSG_IDS_MSG_TRACKING_IQ_DEP_A = 28;
our $MSG_IDS_MSG_UART_STATE = 29;
our $MSG_IDS_MSG_ACQ_SV_PROFILE_DEP = 30;
our $MSG_IDS_MSG_ACQ_RESULT_DEP_C = 31;
our $MSG_IDS_MSG_TRACKING_STATE_DETAILED_DEP_A = 33;
our $MSG_IDS_MSG_RESET_FILTERS = 34;
our $MSG_IDS_MSG_INIT_BASE_DEP = 35;
our $MSG_IDS_MSG_MASK_SATELLITE = 43;
our $MSG_IDS_MSG_TRACKING_IQ_DEP_B = 44;
our $MSG_IDS_MSG_TRACKING_IQ = 45;
our $MSG_IDS_MSG_ACQ_SV_PROFILE = 46;
our $MSG_IDS_MSG_ACQ_RESULT = 47;
our $MSG_IDS_MSG_TRACKING_STATE = 65;
our $MSG_IDS_MSG_OBS_DEP_B = 67;
our $MSG_IDS_MSG_BASE_POS_LLH = 68;
our $MSG_IDS_MSG_OBS_DEP_A = 69;
our $MSG_IDS_MSG_EPHEMERIS_DEP_B = 70;
our $MSG_IDS_MSG_EPHEMERIS_DEP_C = 71;
our $MSG_IDS_MSG_BASE_POS_ECEF = 72;
our $MSG_IDS_MSG_OBS_DEP_C = 73;
our $MSG_IDS_MSG_OBS = 74;
our $MSG_IDS_MSG_SPECAN_DEP = 80;
our $MSG_IDS_MSG_SPECAN = 81;
our $MSG_IDS_MSG_MEASUREMENT_STATE = 97;
our $MSG_IDS_MSG_SET_TIME = 104;
our $MSG_IDS_MSG_ALMANAC = 105;
our $MSG_IDS_MSG_ALMANAC_GPS_DEP = 112;
our $MSG_IDS_MSG_ALMANAC_GLO_DEP = 113;
our $MSG_IDS_MSG_ALMANAC_GPS = 114;
our $MSG_IDS_MSG_ALMANAC_GLO = 115;
our $MSG_IDS_MSG_GLO_BIASES = 117;
our $MSG_IDS_MSG_EPHEMERIS_DEP_D = 128;
our $MSG_IDS_MSG_EPHEMERIS_GPS_DEP_E = 129;
our $MSG_IDS_MSG_EPHEMERIS_SBAS_DEP_A = 130;
our $MSG_IDS_MSG_EPHEMERIS_GLO_DEP_A = 131;
our $MSG_IDS_MSG_EPHEMERIS_SBAS_DEP_B = 132;
our $MSG_IDS_MSG_EPHEMERIS_GLO_DEP_B = 133;
our $MSG_IDS_MSG_EPHEMERIS_GPS_DEP_F = 134;
our $MSG_IDS_MSG_EPHEMERIS_GLO_DEP_C = 135;
our $MSG_IDS_MSG_EPHEMERIS_GLO_DEP_D = 136;
our $MSG_IDS_MSG_EPHEMERIS_BDS = 137;
our $MSG_IDS_MSG_EPHEMERIS_GPS = 138;
our $MSG_IDS_MSG_EPHEMERIS_GLO = 139;
our $MSG_IDS_MSG_EPHEMERIS_SBAS = 140;
our $MSG_IDS_MSG_EPHEMERIS_GAL = 141;
our $MSG_IDS_MSG_EPHEMERIS_QZSS = 142;
our $MSG_IDS_MSG_IONO = 144;
our $MSG_IDS_MSG_SV_CONFIGURATION_GPS_DEP = 145;
our $MSG_IDS_MSG_GROUP_DELAY_DEP_A = 146;
our $MSG_IDS_MSG_GROUP_DELAY_DEP_B = 147;
our $MSG_IDS_MSG_GROUP_DELAY = 148;
our $MSG_IDS_MSG_EPHEMERIS_GAL_DEP_A = 149;
our $MSG_IDS_MSG_GNSS_CAPB = 150;
our $MSG_IDS_MSG_SV_AZ_EL = 151;
our $MSG_IDS_MSG_SETTINGS_WRITE = 160;
our $MSG_IDS_MSG_SETTINGS_SAVE = 161;
our $MSG_IDS_MSG_SETTINGS_READ_BY_INDEX_REQ = 162;
our $MSG_IDS_MSG_FILEIO_READ_RESP = 163;
our $MSG_IDS_MSG_SETTINGS_READ_REQ = 164;
our $MSG_IDS_MSG_SETTINGS_READ_RESP = 165;
our $MSG_IDS_MSG_SETTINGS_READ_BY_INDEX_DONE = 166;
our $MSG_IDS_MSG_SETTINGS_READ_BY_INDEX_RESP = 167;
our $MSG_IDS_MSG_FILEIO_READ_REQ = 168;
our $MSG_IDS_MSG_FILEIO_READ_DIR_REQ = 169;
our $MSG_IDS_MSG_FILEIO_READ_DIR_RESP = 170;
our $MSG_IDS_MSG_FILEIO_WRITE_RESP = 171;
our $MSG_IDS_MSG_FILEIO_REMOVE = 172;
our $MSG_IDS_MSG_FILEIO_WRITE_REQ = 173;
our $MSG_IDS_MSG_SETTINGS_REGISTER = 174;
our $MSG_IDS_MSG_SETTINGS_WRITE_RESP = 175;
our $MSG_IDS_MSG_BOOTLOADER_HANDSHAKE_DEP_A = 176;
our $MSG_IDS_MSG_BOOTLOADER_JUMP_TO_APP = 177;
our $MSG_IDS_MSG_RESET_DEP = 178;
our $MSG_IDS_MSG_BOOTLOADER_HANDSHAKE_REQ = 179;
our $MSG_IDS_MSG_BOOTLOADER_HANDSHAKE_RESP = 180;
our $MSG_IDS_MSG_DEVICE_MONITOR = 181;
our $MSG_IDS_MSG_RESET = 182;
our $MSG_IDS_MSG_COMMAND_REQ = 184;
our $MSG_IDS_MSG_COMMAND_RESP = 185;
our $MSG_IDS_MSG_NETWORK_STATE_REQ = 186;
our $MSG_IDS_MSG_NETWORK_STATE_RESP = 187;
our $MSG_IDS_MSG_COMMAND_OUTPUT = 188;
our $MSG_IDS_MSG_NETWORK_BANDWIDTH_USAGE = 189;
our $MSG_IDS_MSG_CELL_MODEM_STATUS = 190;
our $MSG_IDS_MSG_FRONT_END_GAIN = 191;
our $MSG_IDS_MSG_CW_RESULTS = 192;
our $MSG_IDS_MSG_CW_START = 193;
our $MSG_IDS_MSG_NAP_DEVICE_DNA_RESP = 221;
our $MSG_IDS_MSG_NAP_DEVICE_DNA_REQ = 222;
our $MSG_IDS_MSG_FLASH_DONE = 224;
our $MSG_IDS_MSG_FLASH_READ_RESP = 225;
our $MSG_IDS_MSG_FLASH_ERASE = 226;
our $MSG_IDS_MSG_STM_FLASH_LOCK_SECTOR = 227;
our $MSG_IDS_MSG_STM_FLASH_UNLOCK_SECTOR = 228;
our $MSG_IDS_MSG_STM_UNIQUE_ID_RESP = 229;
our $MSG_IDS_MSG_FLASH_PROGRAM = 230;
our $MSG_IDS_MSG_FLASH_READ_REQ = 231;
our $MSG_IDS_MSG_STM_UNIQUE_ID_REQ = 232;
our $MSG_IDS_MSG_M25_FLASH_WRITE_STATUS = 243;
our $MSG_IDS_MSG_GPS_TIME_DEP_A = 256;
our $MSG_IDS_MSG_EXT_EVENT = 257;
our $MSG_IDS_MSG_GPS_TIME = 258;
our $MSG_IDS_MSG_UTC_TIME = 259;
our $MSG_IDS_MSG_GPS_TIME_GNSS = 260;
our $MSG_IDS_MSG_UTC_TIME_GNSS = 261;
our $MSG_IDS_MSG_TEL_SV = 288;
our $MSG_IDS_MSG_SETTINGS_REGISTER_RESP = 431;
our $MSG_IDS_MSG_POS_ECEF_DEP_A = 512;
our $MSG_IDS_MSG_POS_LLH_DEP_A = 513;
our $MSG_IDS_MSG_BASELINE_ECEF_DEP_A = 514;
our $MSG_IDS_MSG_BASELINE_NED_DEP_A = 515;
our $MSG_IDS_MSG_VEL_ECEF_DEP_A = 516;
our $MSG_IDS_MSG_VEL_NED_DEP_A = 517;
our $MSG_IDS_MSG_DOPS_DEP_A = 518;
our $MSG_IDS_MSG_BASELINE_HEADING_DEP_A = 519;
our $MSG_IDS_MSG_DOPS = 520;
our $MSG_IDS_MSG_POS_ECEF = 521;
our $MSG_IDS_MSG_POS_LLH = 522;
our $MSG_IDS_MSG_BASELINE_ECEF = 523;
our $MSG_IDS_MSG_BASELINE_NED = 524;
our $MSG_IDS_MSG_VEL_ECEF = 525;
our $MSG_IDS_MSG_VEL_NED = 526;
our $MSG_IDS_MSG_BASELINE_HEADING = 527;
our $MSG_IDS_MSG_AGE_CORRECTIONS = 528;
our $MSG_IDS_MSG_POS_LLH_COV = 529;
our $MSG_IDS_MSG_VEL_NED_COV = 530;
our $MSG_IDS_MSG_VEL_BODY = 531;
our $MSG_IDS_MSG_POS_ECEF_COV = 532;
our $MSG_IDS_MSG_VEL_ECEF_COV = 533;
our $MSG_IDS_MSG_PROTECTION_LEVEL_DEP_A = 534;
our $MSG_IDS_MSG_PROTECTION_LEVEL = 535;
our $MSG_IDS_MSG_POS_LLH_ACC = 536;
our $MSG_IDS_MSG_VEL_COG = 540;
our $MSG_IDS_MSG_ORIENT_QUAT = 544;
our $MSG_IDS_MSG_ORIENT_EULER = 545;
our $MSG_IDS_MSG_ANGULAR_RATE = 546;
our $MSG_IDS_MSG_POS_ECEF_GNSS = 553;
our $MSG_IDS_MSG_POS_LLH_GNSS = 554;
our $MSG_IDS_MSG_VEL_ECEF_GNSS = 557;
our $MSG_IDS_MSG_VEL_NED_GNSS = 558;
our $MSG_IDS_MSG_POS_LLH_COV_GNSS = 561;
our $MSG_IDS_MSG_VEL_NED_COV_GNSS = 562;
our $MSG_IDS_MSG_POS_ECEF_COV_GNSS = 564;
our $MSG_IDS_MSG_VEL_ECEF_COV_GNSS = 565;
our $MSG_IDS_MSG_UTC_LEAP_SECOND = 570;
our $MSG_IDS_MSG_REFERENCE_FRAME_PARAM = 580;
our $MSG_IDS_MSG_POSE_RELATIVE = 581;
our $MSG_IDS_MSG_NDB_EVENT = 1024;
our $MSG_IDS_MSG_LOG = 1025;
our $MSG_IDS_MSG_FWD = 1026;
our $MSG_IDS_MSG_SSR_ORBIT_CLOCK_DEP_A = 1500;
our $MSG_IDS_MSG_SSR_ORBIT_CLOCK = 1501;
our $MSG_IDS_MSG_SSR_ORBIT_CLOCK_BOUNDS = 1502;
our $MSG_IDS_MSG_SSR_ORBIT_CLOCK_BOUNDS_DEGRADATION = 1503;
our $MSG_IDS_MSG_SSR_CODE_BIASES = 1505;
our $MSG_IDS_MSG_SSR_PHASE_BIASES = 1510;
our $MSG_IDS_MSG_SSR_STEC_CORRECTION_DEP_A = 1515;
our $MSG_IDS_MSG_SSR_CODE_PHASE_BIASES_BOUNDS = 1516;
our $MSG_IDS_MSG_SSR_GRIDDED_CORRECTION_NO_STD_DEP_A = 1520;
our $MSG_IDS_MSG_SSR_GRID_DEFINITION_DEP_A = 1525;
our $MSG_IDS_MSG_SSR_TILE_DEFINITION_DEP_A = 1526;
our $MSG_IDS_MSG_SSR_TILE_DEFINITION_DEP_B = 1527;
our $MSG_IDS_MSG_SSR_TILE_DEFINITION = 1528;
our $MSG_IDS_MSG_SSR_GRIDDED_CORRECTION_DEP_A = 1530;
our $MSG_IDS_MSG_SSR_STEC_CORRECTION_DEP = 1531;
our $MSG_IDS_MSG_SSR_GRIDDED_CORRECTION = 1532;
our $MSG_IDS_MSG_SSR_STEC_CORRECTION = 1533;
our $MSG_IDS_MSG_SSR_GRIDDED_CORRECTION_BOUNDS = 1534;
our $MSG_IDS_MSG_SSR_SATELLITE_APC_DEP = 1540;
our $MSG_IDS_MSG_SSR_SATELLITE_APC = 1541;
our $MSG_IDS_MSG_OSR = 1600;
our $MSG_IDS_MSG_USER_DATA = 2048;
our $MSG_IDS_MSG_IMU_RAW = 2304;
our $MSG_IDS_MSG_IMU_AUX = 2305;
our $MSG_IDS_MSG_MAG_RAW = 2306;
our $MSG_IDS_MSG_ODOMETRY = 2307;
our $MSG_IDS_MSG_WHEELTICK = 2308;
our $MSG_IDS_MSG_SSR_FLAG_HIGH_LEVEL = 3001;
our $MSG_IDS_MSG_SSR_FLAG_SATELLITES = 3005;
our $MSG_IDS_MSG_SSR_FLAG_TROPO_GRID_POINTS = 3011;
our $MSG_IDS_MSG_SSR_FLAG_IONO_GRID_POINTS = 3015;
our $MSG_IDS_MSG_SSR_FLAG_IONO_TILE_SAT_LOS = 3021;
our $MSG_IDS_MSG_SSR_FLAG_IONO_GRID_POINT_SAT_LOS = 3025;
our $MSG_IDS_MSG_ACKNOWLEDGE = 3026;
our $MSG_IDS_MSG_ED25519_SIGNATURE_DEP_A = 3073;
our $MSG_IDS_MSG_ED25519_CERTIFICATE_DEP = 3074;
our $MSG_IDS_MSG_ED25519_SIGNATURE_DEP_B = 3075;
our $MSG_IDS_MSG_ECDSA_CERTIFICATE = 3076;
our $MSG_IDS_MSG_CERTIFICATE_CHAIN_DEP = 3077;
our $MSG_IDS_MSG_ECDSA_SIGNATURE_DEP_A = 3078;
our $MSG_IDS_MSG_ECDSA_SIGNATURE_DEP_B = 3079;
our $MSG_IDS_MSG_ECDSA_SIGNATURE = 3080;
our $MSG_IDS_MSG_CERTIFICATE_CHAIN = 3081;
our $MSG_IDS_MSG_FILEIO_CONFIG_REQ = 4097;
our $MSG_IDS_MSG_FILEIO_CONFIG_RESP = 4098;
our $MSG_IDS_MSG_SBAS_RAW = 30583;
our $MSG_IDS_MSG_LINUX_CPU_STATE_DEP_A = 32512;
our $MSG_IDS_MSG_LINUX_MEM_STATE_DEP_A = 32513;
our $MSG_IDS_MSG_LINUX_SYS_STATE_DEP_A = 32514;
our $MSG_IDS_MSG_LINUX_PROCESS_SOCKET_COUNTS = 32515;
our $MSG_IDS_MSG_LINUX_PROCESS_SOCKET_QUEUES = 32516;
our $MSG_IDS_MSG_LINUX_SOCKET_USAGE = 32517;
our $MSG_IDS_MSG_LINUX_PROCESS_FD_COUNT = 32518;
our $MSG_IDS_MSG_LINUX_PROCESS_FD_SUMMARY = 32519;
our $MSG_IDS_MSG_LINUX_CPU_STATE = 32520;
our $MSG_IDS_MSG_LINUX_MEM_STATE = 32521;
our $MSG_IDS_MSG_LINUX_SYS_STATE = 32522;
our $MSG_IDS_MSG_STARTUP = 65280;
our $MSG_IDS_MSG_DGNSS_STATUS = 65282;
our $MSG_IDS_MSG_INS_STATUS = 65283;
our $MSG_IDS_MSG_CSAC_TELEMETRY = 65284;
our $MSG_IDS_MSG_CSAC_TELEMETRY_LABELS = 65285;
our $MSG_IDS_MSG_INS_UPDATES = 65286;
our $MSG_IDS_MSG_GNSS_TIME_OFFSET = 65287;
our $MSG_IDS_MSG_PPS_TIME = 65288;
our $MSG_IDS_MSG_SENSOR_AID_EVENT = 65289;
our $MSG_IDS_MSG_GROUP_META = 65290;
our $MSG_IDS_MSG_SOLN_META = 65294;
our $MSG_IDS_MSG_SOLN_META_DEP_A = 65295;
our $MSG_IDS_MSG_STATUS_JOURNAL = 65533;
our $MSG_IDS_MSG_STATUS_REPORT = 65534;
our $MSG_IDS_MSG_HEARTBEAT = 65535;

sub new {
    my ($class, $_io, $_parent, $_root) = @_;
    my $self = IO::KaitaiStruct::Struct->new($_io);

    bless $self, $class;
    $self->{_parent} = $_parent;
    $self->{_root} = $_root || $self;;

    $self->_read();

    return $self;
}

sub _read {
    my ($self) = @_;

    $self->{message} = ();
    while (!$self->{_io}->is_eof()) {
        push @{$self->{message}}, Sbp::Message->new($self->{_io}, $self, $self->{_root});
    }
}

sub message {
    my ($self) = @_;
    return $self->{message};
}

########################################################################
package Sbp::Message;

our @ISA = 'IO::KaitaiStruct::Struct';

sub from_file {
    my ($class, $filename) = @_;
    my $fd;

    open($fd, '<', $filename) or return undef;
    binmode($fd);
    return new($class, IO::KaitaiStruct::Stream->new($fd));
}

sub new {
    my ($class, $_io, $_parent, $_root) = @_;
    my $self = IO::KaitaiStruct::Struct->new($_io);

    bless $self, $class;
    $self->{_parent} = $_parent;
    $self->{_root} = $_root || $self;;

    $self->_read();

    return $self;
}

sub _read {
    my ($self) = @_;

    $self->{header} = Sbp::SbpHeader->new($self->{_io}, $self, $self->{_root});
    my $_on = $self->header()->msg_type();
    if ($_on == $Sbp::MSG_IDS_MSG_BASELINE_ECEF) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Navigation::MsgBaselineEcef->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_EPHEMERIS_BDS) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Observation::MsgEphemerisBds->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_EPHEMERIS_GLO_DEP_D) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Observation::MsgEphemerisGloDepD->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_ECDSA_SIGNATURE_DEP_B) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Signing::MsgEcdsaSignatureDepB->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_SETTINGS_READ_BY_INDEX_REQ) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Settings::MsgSettingsReadByIndexReq->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_SSR_FLAG_HIGH_LEVEL) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Integrity::MsgSsrFlagHighLevel->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_FILEIO_CONFIG_REQ) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = FileIo::MsgFileioConfigReq->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_ODOMETRY) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Vehicle::MsgOdometry->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_SSR_STEC_CORRECTION_DEP) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Ssr::MsgSsrStecCorrectionDep->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_ED25519_SIGNATURE_DEP_B) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Signing::MsgEd25519SignatureDepB->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_STM_UNIQUE_ID_REQ) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Flash::MsgStmUniqueIdReq->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_FRONT_END_GAIN) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Piksi::MsgFrontEndGain->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_BASE_POS_LLH) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Observation::MsgBasePosLlh->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_EPHEMERIS_DEP_A) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Observation::MsgEphemerisDepA->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_SSR_ORBIT_CLOCK) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Ssr::MsgSsrOrbitClock->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_RESET) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Piksi::MsgReset->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_STM_FLASH_LOCK_SECTOR) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Flash::MsgStmFlashLockSector->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_LINUX_PROCESS_FD_SUMMARY) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Linux::MsgLinuxProcessFdSummary->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_STATUS_JOURNAL) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = System::MsgStatusJournal->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_CSAC_TELEMETRY) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = System::MsgCsacTelemetry->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_AGE_CORRECTIONS) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Navigation::MsgAgeCorrections->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_ORIENT_EULER) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Orientation::MsgOrientEuler->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_SSR_SATELLITE_APC_DEP) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Ssr::MsgSsrSatelliteApcDep->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_BASELINE_NED) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Navigation::MsgBaselineNed->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_VEL_ECEF_GNSS) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Navigation::MsgVelEcefGnss->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_MEASUREMENT_STATE) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Tracking::MsgMeasurementState->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_IONO) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Observation::MsgIono->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_BASE_POS_ECEF) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Observation::MsgBasePosEcef->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_FLASH_PROGRAM) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Flash::MsgFlashProgram->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_ACQ_RESULT) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Acquisition::MsgAcqResult->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_PPS_TIME) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = System::MsgPpsTime->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_OBS) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Observation::MsgObs->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_EPHEMERIS_SBAS_DEP_B) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Observation::MsgEphemerisSbasDepB->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_TRACKING_IQ) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Tracking::MsgTrackingIq->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_SSR_FLAG_IONO_TILE_SAT_LOS) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Integrity::MsgSsrFlagIonoTileSatLos->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_TRACKING_STATE_DETAILED_DEP) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Tracking::MsgTrackingStateDetailedDep->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_BOOTLOADER_HANDSHAKE_DEP_A) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Bootload::MsgBootloaderHandshakeDepA->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_UTC_LEAP_SECOND) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Navigation::MsgUtcLeapSecond->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_SSR_GRIDDED_CORRECTION_NO_STD_DEP_A) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Ssr::MsgSsrGriddedCorrectionNoStdDepA->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_BOOTLOADER_HANDSHAKE_RESP) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Bootload::MsgBootloaderHandshakeResp->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_BASELINE_HEADING) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Orientation::MsgBaselineHeading->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_STATUS_REPORT) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = System::MsgStatusReport->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_VEL_NED_COV) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Navigation::MsgVelNedCov->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_SET_TIME) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Piksi::MsgSetTime->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_LINUX_CPU_STATE) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Linux::MsgLinuxCpuState->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_GPS_TIME_DEP_A) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Navigation::MsgGpsTimeDepA->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_EPHEMERIS_SBAS_DEP_A) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Observation::MsgEphemerisSbasDepA->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_ACQ_RESULT_DEP_B) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Acquisition::MsgAcqResultDepB->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_SETTINGS_REGISTER_RESP) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Settings::MsgSettingsRegisterResp->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_ECDSA_SIGNATURE_DEP_A) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Signing::MsgEcdsaSignatureDepA->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_EPHEMERIS_GAL) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Observation::MsgEphemerisGal->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_BOOTLOADER_JUMP_TO_APP) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Bootload::MsgBootloaderJumpToApp->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_SSR_PHASE_BIASES) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Ssr::MsgSsrPhaseBiases->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_FILEIO_READ_DIR_RESP) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = FileIo::MsgFileioReadDirResp->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_POS_ECEF_GNSS) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Navigation::MsgPosEcefGnss->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_ALMANAC_GLO_DEP) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Observation::MsgAlmanacGloDep->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_VEL_ECEF_DEP_A) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Navigation::MsgVelEcefDepA->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_THREAD_STATE) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Piksi::MsgThreadState->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_GPS_TIME) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Navigation::MsgGpsTime->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_SSR_CODE_PHASE_BIASES_BOUNDS) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Ssr::MsgSsrCodePhaseBiasesBounds->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_SETTINGS_WRITE_RESP) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Settings::MsgSettingsWriteResp->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_TRACKING_STATE) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Tracking::MsgTrackingState->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_VEL_ECEF) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Navigation::MsgVelEcef->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_EPHEMERIS_GLO_DEP_A) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Observation::MsgEphemerisGloDepA->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_ED25519_CERTIFICATE_DEP) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Signing::MsgEd25519CertificateDep->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_BASELINE_NED_DEP_A) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Navigation::MsgBaselineNedDepA->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_SPECAN_DEP) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Piksi::MsgSpecanDep->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_EPHEMERIS_SBAS) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Observation::MsgEphemerisSbas->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_GROUP_DELAY) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Observation::MsgGroupDelay->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_POS_ECEF) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Navigation::MsgPosEcef->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_ALMANAC) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Piksi::MsgAlmanac->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_SETTINGS_READ_REQ) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Settings::MsgSettingsReadReq->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_SSR_FLAG_TROPO_GRID_POINTS) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Integrity::MsgSsrFlagTropoGridPoints->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_SSR_GRIDDED_CORRECTION_BOUNDS) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Ssr::MsgSsrGriddedCorrectionBounds->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_STM_UNIQUE_ID_RESP) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Flash::MsgStmUniqueIdResp->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_TEL_SV) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Telemetry::MsgTelSv->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_SSR_FLAG_SATELLITES) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Integrity::MsgSsrFlagSatellites->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_IMU_AUX) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Imu::MsgImuAux->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_SSR_GRID_DEFINITION_DEP_A) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Ssr::MsgSsrGridDefinitionDepA->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_POS_LLH_ACC) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Navigation::MsgPosLlhAcc->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_SV_CONFIGURATION_GPS_DEP) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Observation::MsgSvConfigurationGpsDep->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_LINUX_MEM_STATE) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Linux::MsgLinuxMemState->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_LINUX_SYS_STATE) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Linux::MsgLinuxSysState->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_SETTINGS_READ_BY_INDEX_DONE) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Settings::MsgSettingsReadByIndexDone->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_RESET_FILTERS) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Piksi::MsgResetFilters->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_ECDSA_SIGNATURE) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Signing::MsgEcdsaSignature->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_EPHEMERIS_GPS_DEP_E) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Observation::MsgEphemerisGpsDepE->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_M25_FLASH_WRITE_STATUS) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Flash::MsgM25FlashWriteStatus->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_EPHEMERIS_GPS) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Observation::MsgEphemerisGps->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_COMMAND_OUTPUT) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Piksi::MsgCommandOutput->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_SSR_FLAG_IONO_GRID_POINTS) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Integrity::MsgSsrFlagIonoGridPoints->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_VEL_NED_COV_GNSS) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Navigation::MsgVelNedCovGnss->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_NETWORK_STATE_RESP) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Piksi::MsgNetworkStateResp->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_SSR_STEC_CORRECTION_DEP_A) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Ssr::MsgSsrStecCorrectionDepA->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_COMMAND_REQ) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Piksi::MsgCommandReq->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_ACKNOWLEDGE) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Integrity::MsgAcknowledge->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_TRACKING_IQ_DEP_A) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Tracking::MsgTrackingIqDepA->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_EPHEMERIS_GAL_DEP_A) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Observation::MsgEphemerisGalDepA->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_SPECAN) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Piksi::MsgSpecan->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_ACQ_SV_PROFILE_DEP) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Acquisition::MsgAcqSvProfileDep->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_UTC_TIME) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Navigation::MsgUtcTime->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_EPHEMERIS_DEP_D) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Observation::MsgEphemerisDepD->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_LINUX_PROCESS_SOCKET_QUEUES) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Linux::MsgLinuxProcessSocketQueues->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_UTC_TIME_GNSS) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Navigation::MsgUtcTimeGnss->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_NDB_EVENT) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Ndb::MsgNdbEvent->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_BOOTLOADER_HANDSHAKE_REQ) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Bootload::MsgBootloaderHandshakeReq->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_USER_DATA) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = User::MsgUserData->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_SENSOR_AID_EVENT) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = System::MsgSensorAidEvent->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_SSR_ORBIT_CLOCK_BOUNDS) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Ssr::MsgSsrOrbitClockBounds->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_POS_LLH_GNSS) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Navigation::MsgPosLlhGnss->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_INIT_BASE_DEP) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Piksi::MsgInitBaseDep->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_FILEIO_READ_REQ) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = FileIo::MsgFileioReadReq->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_TRACKING_IQ_DEP_B) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Tracking::MsgTrackingIqDepB->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_ACQ_RESULT_DEP_C) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Acquisition::MsgAcqResultDepC->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_COMMAND_RESP) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Piksi::MsgCommandResp->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_FILEIO_REMOVE) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = FileIo::MsgFileioRemove->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_OBS_DEP_C) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Observation::MsgObsDepC->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_SSR_TILE_DEFINITION_DEP_B) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Ssr::MsgSsrTileDefinitionDepB->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_CSAC_TELEMETRY_LABELS) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = System::MsgCsacTelemetryLabels->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_VEL_NED) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Navigation::MsgVelNed->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_SETTINGS_READ_BY_INDEX_RESP) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Settings::MsgSettingsReadByIndexResp->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_EPHEMERIS_QZSS) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Observation::MsgEphemerisQzss->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_SSR_STEC_CORRECTION) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Ssr::MsgSsrStecCorrection->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_BASELINE_ECEF_DEP_A) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Navigation::MsgBaselineEcefDepA->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_INS_UPDATES) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = System::MsgInsUpdates->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_POS_ECEF_COV) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Navigation::MsgPosEcefCov->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_VEL_NED_GNSS) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Navigation::MsgVelNedGnss->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_MASK_SATELLITE) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Piksi::MsgMaskSatellite->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_GROUP_DELAY_DEP_B) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Observation::MsgGroupDelayDepB->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_SSR_ORBIT_CLOCK_BOUNDS_DEGRADATION) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Ssr::MsgSsrOrbitClockBoundsDegradation->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_FLASH_ERASE) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Flash::MsgFlashErase->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_CW_START) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Piksi::MsgCwStart->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_SSR_ORBIT_CLOCK_DEP_A) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Ssr::MsgSsrOrbitClockDepA->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_DOPS) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Navigation::MsgDops->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_NETWORK_BANDWIDTH_USAGE) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Piksi::MsgNetworkBandwidthUsage->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_ECDSA_CERTIFICATE) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Signing::MsgEcdsaCertificate->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_POS_LLH_DEP_A) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Navigation::MsgPosLlhDepA->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_SV_AZ_EL) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Observation::MsgSvAzEl->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_FILEIO_READ_DIR_REQ) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = FileIo::MsgFileioReadDirReq->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_EPHEMERIS_DEP_B) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Observation::MsgEphemerisDepB->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_VEL_ECEF_COV) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Navigation::MsgVelEcefCov->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_DGNSS_STATUS) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = System::MsgDgnssStatus->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_SSR_TILE_DEFINITION_DEP_A) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Ssr::MsgSsrTileDefinitionDepA->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_LOG) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Logging::MsgLog->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_MASK_SATELLITE_DEP) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Piksi::MsgMaskSatelliteDep->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_EXT_EVENT) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = ExtEvents::MsgExtEvent->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_CELL_MODEM_STATUS) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Piksi::MsgCellModemStatus->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_ORIENT_QUAT) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Orientation::MsgOrientQuat->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_HEARTBEAT) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = System::MsgHeartbeat->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_ALMANAC_GPS_DEP) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Observation::MsgAlmanacGpsDep->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_NAP_DEVICE_DNA_REQ) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Bootload::MsgNapDeviceDnaReq->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_ALMANAC_GPS) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Observation::MsgAlmanacGps->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_VEL_ECEF_COV_GNSS) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Navigation::MsgVelEcefCovGnss->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_ED25519_SIGNATURE_DEP_A) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Signing::MsgEd25519SignatureDepA->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_ANGULAR_RATE) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Orientation::MsgAngularRate->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_VEL_BODY) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Navigation::MsgVelBody->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_CERTIFICATE_CHAIN) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Signing::MsgCertificateChain->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_SOLN_META_DEP_A) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = SolutionMeta::MsgSolnMetaDepA->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_SSR_GRIDDED_CORRECTION_DEP_A) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Ssr::MsgSsrGriddedCorrectionDepA->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_EPHEMERIS_GLO_DEP_C) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Observation::MsgEphemerisGloDepC->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_LINUX_PROCESS_FD_COUNT) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Linux::MsgLinuxProcessFdCount->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_FILEIO_READ_RESP) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = FileIo::MsgFileioReadResp->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_LINUX_SYS_STATE_DEP_A) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Linux::MsgLinuxSysStateDepA->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_SBAS_RAW) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Sbas::MsgSbasRaw->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_POS_ECEF_COV_GNSS) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Navigation::MsgPosEcefCovGnss->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_SSR_FLAG_IONO_GRID_POINT_SAT_LOS) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Integrity::MsgSsrFlagIonoGridPointSatLos->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_FILEIO_WRITE_REQ) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = FileIo::MsgFileioWriteReq->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_ACQ_SV_PROFILE) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Acquisition::MsgAcqSvProfile->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_EPHEMERIS_GLO_DEP_B) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Observation::MsgEphemerisGloDepB->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_LINUX_SOCKET_USAGE) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Linux::MsgLinuxSocketUsage->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_NETWORK_STATE_REQ) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Piksi::MsgNetworkStateReq->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_PROTECTION_LEVEL_DEP_A) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Navigation::MsgProtectionLevelDepA->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_IMU_RAW) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Imu::MsgImuRaw->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_RESET_DEP) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Piksi::MsgResetDep->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_MAG_RAW) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Mag::MsgMagRaw->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_STARTUP) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = System::MsgStartup->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_GLO_BIASES) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Observation::MsgGloBiases->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_TRACKING_STATE_DETAILED_DEP_A) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Tracking::MsgTrackingStateDetailedDepA->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_POS_LLH_COV_GNSS) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Navigation::MsgPosLlhCovGnss->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_SETTINGS_WRITE) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Settings::MsgSettingsWrite->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_SETTINGS_SAVE) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Settings::MsgSettingsSave->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_ALMANAC_GLO) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Observation::MsgAlmanacGlo->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_STM_FLASH_UNLOCK_SECTOR) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Flash::MsgStmFlashUnlockSector->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_GPS_TIME_GNSS) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Navigation::MsgGpsTimeGnss->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_FLASH_READ_REQ) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Flash::MsgFlashReadReq->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_EPHEMERIS_GLO) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Observation::MsgEphemerisGlo->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_BASELINE_HEADING_DEP_A) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Navigation::MsgBaselineHeadingDepA->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_SETTINGS_REGISTER) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Settings::MsgSettingsRegister->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_GNSS_CAPB) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Observation::MsgGnssCapb->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_TRACKING_STATE_DEP_B) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Tracking::MsgTrackingStateDepB->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_FWD) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Logging::MsgFwd->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_SOLN_META) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = SolutionMeta::MsgSolnMeta->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_OBS_DEP_A) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Observation::MsgObsDepA->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_DEVICE_MONITOR) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Piksi::MsgDeviceMonitor->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_LINUX_PROCESS_SOCKET_COUNTS) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Linux::MsgLinuxProcessSocketCounts->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_VEL_COG) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Navigation::MsgVelCog->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_PRINT_DEP) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Logging::MsgPrintDep->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_CW_RESULTS) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Piksi::MsgCwResults->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_NAP_DEVICE_DNA_RESP) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Bootload::MsgNapDeviceDnaResp->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_DOPS_DEP_A) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Navigation::MsgDopsDepA->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_POS_ECEF_DEP_A) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Navigation::MsgPosEcefDepA->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_SETTINGS_READ_RESP) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Settings::MsgSettingsReadResp->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_LINUX_MEM_STATE_DEP_A) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Linux::MsgLinuxMemStateDepA->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_EPHEMERIS_DEP_C) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Observation::MsgEphemerisDepC->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_FILEIO_WRITE_RESP) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = FileIo::MsgFileioWriteResp->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_WHEELTICK) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Vehicle::MsgWheeltick->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_UART_STATE_DEPA) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Piksi::MsgUartStateDepa->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_REFERENCE_FRAME_PARAM) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Navigation::MsgReferenceFrameParam->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_POSE_RELATIVE) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Navigation::MsgPoseRelative->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_IAR_STATE) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Piksi::MsgIarState->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_UART_STATE) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Piksi::MsgUartState->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_SSR_TILE_DEFINITION) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Ssr::MsgSsrTileDefinition->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_SSR_SATELLITE_APC) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Ssr::MsgSsrSatelliteApc->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_OSR) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Observation::MsgOsr->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_POS_LLH_COV) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Navigation::MsgPosLlhCov->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_GROUP_DELAY_DEP_A) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Observation::MsgGroupDelayDepA->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_PROTECTION_LEVEL) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Navigation::MsgProtectionLevel->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_OBS_DEP_B) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Observation::MsgObsDepB->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_POS_LLH) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Navigation::MsgPosLlh->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_FLASH_DONE) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Flash::MsgFlashDone->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_ACQ_RESULT_DEP_A) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Acquisition::MsgAcqResultDepA->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_SSR_CODE_BIASES) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Ssr::MsgSsrCodeBiases->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_CERTIFICATE_CHAIN_DEP) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Signing::MsgCertificateChainDep->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_SSR_GRIDDED_CORRECTION) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Ssr::MsgSsrGriddedCorrection->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_GROUP_META) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = System::MsgGroupMeta->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_FILEIO_CONFIG_RESP) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = FileIo::MsgFileioConfigResp->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_VEL_NED_DEP_A) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Navigation::MsgVelNedDepA->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_GNSS_TIME_OFFSET) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = System::MsgGnssTimeOffset->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_TRACKING_STATE_DEP_A) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Tracking::MsgTrackingStateDepA->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_INS_STATUS) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = System::MsgInsStatus->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_EPHEMERIS_GPS_DEP_F) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Observation::MsgEphemerisGpsDepF->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_LINUX_CPU_STATE_DEP_A) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Linux::MsgLinuxCpuStateDepA->new($io__raw_payload, $self, $self->{_root});
    }
    elsif ($_on == $Sbp::MSG_IDS_MSG_FLASH_READ_RESP) {
        $self->{_raw_payload} = $self->{_io}->read_bytes($self->header()->length());
        my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
        $self->{payload} = Flash::MsgFlashReadResp->new($io__raw_payload, $self, $self->{_root});
    }
    else {
        $self->{payload} = $self->{_io}->read_bytes($self->header()->length());
    }
    $self->{crc} = $self->{_io}->read_u2le();
}

sub header {
    my ($self) = @_;
    return $self->{header};
}

sub payload {
    my ($self) = @_;
    return $self->{payload};
}

sub crc {
    my ($self) = @_;
    return $self->{crc};
}

sub _raw_payload {
    my ($self) = @_;
    return $self->{_raw_payload};
}

########################################################################
package Sbp::SbpHeader;

our @ISA = 'IO::KaitaiStruct::Struct';

sub from_file {
    my ($class, $filename) = @_;
    my $fd;

    open($fd, '<', $filename) or return undef;
    binmode($fd);
    return new($class, IO::KaitaiStruct::Stream->new($fd));
}

sub new {
    my ($class, $_io, $_parent, $_root) = @_;
    my $self = IO::KaitaiStruct::Struct->new($_io);

    bless $self, $class;
    $self->{_parent} = $_parent;
    $self->{_root} = $_root || $self;;

    $self->_read();

    return $self;
}

sub _read {
    my ($self) = @_;

    $self->{preamble} = $self->{_io}->read_bytes(1);
    $self->{msg_type} = $self->{_io}->read_u2le();
    $self->{sender} = $self->{_io}->read_u2le();
    $self->{length} = $self->{_io}->read_u1();
}

sub preamble {
    my ($self) = @_;
    return $self->{preamble};
}

sub msg_type {
    my ($self) = @_;
    return $self->{msg_type};
}

sub sender {
    my ($self) = @_;
    return $self->{sender};
}

sub length {
    my ($self) = @_;
    return $self->{length};
}

1;
