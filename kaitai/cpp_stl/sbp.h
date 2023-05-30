#ifndef SBP_H_
#define SBP_H_

// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

#include "kaitai/kaitaistruct.h"
#include <stdint.h>
#include <vector>

#if KAITAI_STRUCT_VERSION < 9000L
#error "Incompatible Kaitai Struct C++/STL API: version 0.9 or later is required"
#endif

class sbp_t : public kaitai::kstruct {

public:
    class message_t;
    class sbp_header_t;

    enum msg_ids_t {
        MSG_IDS_MSG_PRINT_DEP = 16,
        MSG_IDS_MSG_TRACKING_STATE_DETAILED_DEP = 17,
        MSG_IDS_MSG_TRACKING_STATE_DEP_B = 19,
        MSG_IDS_MSG_ACQ_RESULT_DEP_B = 20,
        MSG_IDS_MSG_ACQ_RESULT_DEP_A = 21,
        MSG_IDS_MSG_TRACKING_STATE_DEP_A = 22,
        MSG_IDS_MSG_THREAD_STATE = 23,
        MSG_IDS_MSG_UART_STATE_DEPA = 24,
        MSG_IDS_MSG_IAR_STATE = 25,
        MSG_IDS_MSG_EPHEMERIS_DEP_A = 26,
        MSG_IDS_MSG_MASK_SATELLITE_DEP = 27,
        MSG_IDS_MSG_TRACKING_IQ_DEP_A = 28,
        MSG_IDS_MSG_UART_STATE = 29,
        MSG_IDS_MSG_ACQ_SV_PROFILE_DEP = 30,
        MSG_IDS_MSG_ACQ_RESULT_DEP_C = 31,
        MSG_IDS_MSG_TRACKING_STATE_DETAILED_DEP_A = 33,
        MSG_IDS_MSG_RESET_FILTERS = 34,
        MSG_IDS_MSG_INIT_BASE_DEP = 35,
        MSG_IDS_MSG_MASK_SATELLITE = 43,
        MSG_IDS_MSG_TRACKING_IQ_DEP_B = 44,
        MSG_IDS_MSG_TRACKING_IQ = 45,
        MSG_IDS_MSG_ACQ_SV_PROFILE = 46,
        MSG_IDS_MSG_ACQ_RESULT = 47,
        MSG_IDS_MSG_TRACKING_STATE = 65,
        MSG_IDS_MSG_OBS_DEP_B = 67,
        MSG_IDS_MSG_BASE_POS_LLH = 68,
        MSG_IDS_MSG_OBS_DEP_A = 69,
        MSG_IDS_MSG_EPHEMERIS_DEP_B = 70,
        MSG_IDS_MSG_EPHEMERIS_DEP_C = 71,
        MSG_IDS_MSG_BASE_POS_ECEF = 72,
        MSG_IDS_MSG_OBS_DEP_C = 73,
        MSG_IDS_MSG_OBS = 74,
        MSG_IDS_MSG_SPECAN_DEP = 80,
        MSG_IDS_MSG_SPECAN = 81,
        MSG_IDS_MSG_MEASUREMENT_STATE = 97,
        MSG_IDS_MSG_SET_TIME = 104,
        MSG_IDS_MSG_ALMANAC = 105,
        MSG_IDS_MSG_ALMANAC_GPS_DEP = 112,
        MSG_IDS_MSG_ALMANAC_GLO_DEP = 113,
        MSG_IDS_MSG_ALMANAC_GPS = 114,
        MSG_IDS_MSG_ALMANAC_GLO = 115,
        MSG_IDS_MSG_GLO_BIASES = 117,
        MSG_IDS_MSG_EPHEMERIS_DEP_D = 128,
        MSG_IDS_MSG_EPHEMERIS_GPS_DEP_E = 129,
        MSG_IDS_MSG_EPHEMERIS_SBAS_DEP_A = 130,
        MSG_IDS_MSG_EPHEMERIS_GLO_DEP_A = 131,
        MSG_IDS_MSG_EPHEMERIS_SBAS_DEP_B = 132,
        MSG_IDS_MSG_EPHEMERIS_GLO_DEP_B = 133,
        MSG_IDS_MSG_EPHEMERIS_GPS_DEP_F = 134,
        MSG_IDS_MSG_EPHEMERIS_GLO_DEP_C = 135,
        MSG_IDS_MSG_EPHEMERIS_GLO_DEP_D = 136,
        MSG_IDS_MSG_EPHEMERIS_BDS = 137,
        MSG_IDS_MSG_EPHEMERIS_GPS = 138,
        MSG_IDS_MSG_EPHEMERIS_GLO = 139,
        MSG_IDS_MSG_EPHEMERIS_SBAS = 140,
        MSG_IDS_MSG_EPHEMERIS_GAL = 141,
        MSG_IDS_MSG_EPHEMERIS_QZSS = 142,
        MSG_IDS_MSG_IONO = 144,
        MSG_IDS_MSG_SV_CONFIGURATION_GPS_DEP = 145,
        MSG_IDS_MSG_GROUP_DELAY_DEP_A = 146,
        MSG_IDS_MSG_GROUP_DELAY_DEP_B = 147,
        MSG_IDS_MSG_GROUP_DELAY = 148,
        MSG_IDS_MSG_EPHEMERIS_GAL_DEP_A = 149,
        MSG_IDS_MSG_GNSS_CAPB = 150,
        MSG_IDS_MSG_SV_AZ_EL = 151,
        MSG_IDS_MSG_SETTINGS_WRITE = 160,
        MSG_IDS_MSG_SETTINGS_SAVE = 161,
        MSG_IDS_MSG_SETTINGS_READ_BY_INDEX_REQ = 162,
        MSG_IDS_MSG_FILEIO_READ_RESP = 163,
        MSG_IDS_MSG_SETTINGS_READ_REQ = 164,
        MSG_IDS_MSG_SETTINGS_READ_RESP = 165,
        MSG_IDS_MSG_SETTINGS_READ_BY_INDEX_DONE = 166,
        MSG_IDS_MSG_SETTINGS_READ_BY_INDEX_RESP = 167,
        MSG_IDS_MSG_FILEIO_READ_REQ = 168,
        MSG_IDS_MSG_FILEIO_READ_DIR_REQ = 169,
        MSG_IDS_MSG_FILEIO_READ_DIR_RESP = 170,
        MSG_IDS_MSG_FILEIO_WRITE_RESP = 171,
        MSG_IDS_MSG_FILEIO_REMOVE = 172,
        MSG_IDS_MSG_FILEIO_WRITE_REQ = 173,
        MSG_IDS_MSG_SETTINGS_REGISTER = 174,
        MSG_IDS_MSG_SETTINGS_WRITE_RESP = 175,
        MSG_IDS_MSG_BOOTLOADER_HANDSHAKE_DEP_A = 176,
        MSG_IDS_MSG_BOOTLOADER_JUMP_TO_APP = 177,
        MSG_IDS_MSG_RESET_DEP = 178,
        MSG_IDS_MSG_BOOTLOADER_HANDSHAKE_REQ = 179,
        MSG_IDS_MSG_BOOTLOADER_HANDSHAKE_RESP = 180,
        MSG_IDS_MSG_DEVICE_MONITOR = 181,
        MSG_IDS_MSG_RESET = 182,
        MSG_IDS_MSG_COMMAND_REQ = 184,
        MSG_IDS_MSG_COMMAND_RESP = 185,
        MSG_IDS_MSG_NETWORK_STATE_REQ = 186,
        MSG_IDS_MSG_NETWORK_STATE_RESP = 187,
        MSG_IDS_MSG_COMMAND_OUTPUT = 188,
        MSG_IDS_MSG_NETWORK_BANDWIDTH_USAGE = 189,
        MSG_IDS_MSG_CELL_MODEM_STATUS = 190,
        MSG_IDS_MSG_FRONT_END_GAIN = 191,
        MSG_IDS_MSG_CW_RESULTS = 192,
        MSG_IDS_MSG_CW_START = 193,
        MSG_IDS_MSG_NAP_DEVICE_DNA_RESP = 221,
        MSG_IDS_MSG_NAP_DEVICE_DNA_REQ = 222,
        MSG_IDS_MSG_FLASH_DONE = 224,
        MSG_IDS_MSG_FLASH_READ_RESP = 225,
        MSG_IDS_MSG_FLASH_ERASE = 226,
        MSG_IDS_MSG_STM_FLASH_LOCK_SECTOR = 227,
        MSG_IDS_MSG_STM_FLASH_UNLOCK_SECTOR = 228,
        MSG_IDS_MSG_STM_UNIQUE_ID_RESP = 229,
        MSG_IDS_MSG_FLASH_PROGRAM = 230,
        MSG_IDS_MSG_FLASH_READ_REQ = 231,
        MSG_IDS_MSG_STM_UNIQUE_ID_REQ = 232,
        MSG_IDS_MSG_M25_FLASH_WRITE_STATUS = 243,
        MSG_IDS_MSG_GPS_TIME_DEP_A = 256,
        MSG_IDS_MSG_EXT_EVENT = 257,
        MSG_IDS_MSG_GPS_TIME = 258,
        MSG_IDS_MSG_UTC_TIME = 259,
        MSG_IDS_MSG_GPS_TIME_GNSS = 260,
        MSG_IDS_MSG_UTC_TIME_GNSS = 261,
        MSG_IDS_MSG_TEL_SV = 288,
        MSG_IDS_MSG_SETTINGS_REGISTER_RESP = 431,
        MSG_IDS_MSG_POS_ECEF_DEP_A = 512,
        MSG_IDS_MSG_POS_LLH_DEP_A = 513,
        MSG_IDS_MSG_BASELINE_ECEF_DEP_A = 514,
        MSG_IDS_MSG_BASELINE_NED_DEP_A = 515,
        MSG_IDS_MSG_VEL_ECEF_DEP_A = 516,
        MSG_IDS_MSG_VEL_NED_DEP_A = 517,
        MSG_IDS_MSG_DOPS_DEP_A = 518,
        MSG_IDS_MSG_BASELINE_HEADING_DEP_A = 519,
        MSG_IDS_MSG_DOPS = 520,
        MSG_IDS_MSG_POS_ECEF = 521,
        MSG_IDS_MSG_POS_LLH = 522,
        MSG_IDS_MSG_BASELINE_ECEF = 523,
        MSG_IDS_MSG_BASELINE_NED = 524,
        MSG_IDS_MSG_VEL_ECEF = 525,
        MSG_IDS_MSG_VEL_NED = 526,
        MSG_IDS_MSG_BASELINE_HEADING = 527,
        MSG_IDS_MSG_AGE_CORRECTIONS = 528,
        MSG_IDS_MSG_POS_LLH_COV = 529,
        MSG_IDS_MSG_VEL_NED_COV = 530,
        MSG_IDS_MSG_VEL_BODY = 531,
        MSG_IDS_MSG_POS_ECEF_COV = 532,
        MSG_IDS_MSG_VEL_ECEF_COV = 533,
        MSG_IDS_MSG_PROTECTION_LEVEL_DEP_A = 534,
        MSG_IDS_MSG_PROTECTION_LEVEL = 535,
        MSG_IDS_MSG_POS_LLH_ACC = 536,
        MSG_IDS_MSG_VEL_COG = 540,
        MSG_IDS_MSG_ORIENT_QUAT = 544,
        MSG_IDS_MSG_ORIENT_EULER = 545,
        MSG_IDS_MSG_ANGULAR_RATE = 546,
        MSG_IDS_MSG_POS_ECEF_GNSS = 553,
        MSG_IDS_MSG_POS_LLH_GNSS = 554,
        MSG_IDS_MSG_VEL_ECEF_GNSS = 557,
        MSG_IDS_MSG_VEL_NED_GNSS = 558,
        MSG_IDS_MSG_POS_LLH_COV_GNSS = 561,
        MSG_IDS_MSG_VEL_NED_COV_GNSS = 562,
        MSG_IDS_MSG_POS_ECEF_COV_GNSS = 564,
        MSG_IDS_MSG_VEL_ECEF_COV_GNSS = 565,
        MSG_IDS_MSG_UTC_LEAP_SECOND = 570,
        MSG_IDS_MSG_REFERENCE_FRAME_PARAM = 580,
        MSG_IDS_MSG_POSE_RELATIVE = 581,
        MSG_IDS_MSG_NDB_EVENT = 1024,
        MSG_IDS_MSG_LOG = 1025,
        MSG_IDS_MSG_FWD = 1026,
        MSG_IDS_MSG_SSR_ORBIT_CLOCK_DEP_A = 1500,
        MSG_IDS_MSG_SSR_ORBIT_CLOCK = 1501,
        MSG_IDS_MSG_SSR_ORBIT_CLOCK_BOUNDS = 1502,
        MSG_IDS_MSG_SSR_ORBIT_CLOCK_BOUNDS_DEGRADATION = 1503,
        MSG_IDS_MSG_SSR_CODE_BIASES = 1505,
        MSG_IDS_MSG_SSR_PHASE_BIASES = 1510,
        MSG_IDS_MSG_SSR_STEC_CORRECTION_DEP_A = 1515,
        MSG_IDS_MSG_SSR_CODE_PHASE_BIASES_BOUNDS = 1516,
        MSG_IDS_MSG_SSR_GRIDDED_CORRECTION_NO_STD_DEP_A = 1520,
        MSG_IDS_MSG_SSR_GRID_DEFINITION_DEP_A = 1525,
        MSG_IDS_MSG_SSR_TILE_DEFINITION_DEP_A = 1526,
        MSG_IDS_MSG_SSR_TILE_DEFINITION_DEP_B = 1527,
        MSG_IDS_MSG_SSR_TILE_DEFINITION = 1528,
        MSG_IDS_MSG_SSR_GRIDDED_CORRECTION_DEP_A = 1530,
        MSG_IDS_MSG_SSR_STEC_CORRECTION_DEP = 1531,
        MSG_IDS_MSG_SSR_GRIDDED_CORRECTION = 1532,
        MSG_IDS_MSG_SSR_STEC_CORRECTION = 1533,
        MSG_IDS_MSG_SSR_GRIDDED_CORRECTION_BOUNDS = 1534,
        MSG_IDS_MSG_SSR_SATELLITE_APC_DEP = 1540,
        MSG_IDS_MSG_SSR_SATELLITE_APC = 1541,
        MSG_IDS_MSG_OSR = 1600,
        MSG_IDS_MSG_USER_DATA = 2048,
        MSG_IDS_MSG_IMU_RAW = 2304,
        MSG_IDS_MSG_IMU_AUX = 2305,
        MSG_IDS_MSG_MAG_RAW = 2306,
        MSG_IDS_MSG_ODOMETRY = 2307,
        MSG_IDS_MSG_WHEELTICK = 2308,
        MSG_IDS_MSG_SSR_FLAG_HIGH_LEVEL = 3001,
        MSG_IDS_MSG_SSR_FLAG_SATELLITES = 3005,
        MSG_IDS_MSG_SSR_FLAG_TROPO_GRID_POINTS = 3011,
        MSG_IDS_MSG_SSR_FLAG_IONO_GRID_POINTS = 3015,
        MSG_IDS_MSG_SSR_FLAG_IONO_TILE_SAT_LOS = 3021,
        MSG_IDS_MSG_SSR_FLAG_IONO_GRID_POINT_SAT_LOS = 3025,
        MSG_IDS_MSG_ACKNOWLEDGE = 3026,
        MSG_IDS_MSG_ED25519_SIGNATURE_DEP_A = 3073,
        MSG_IDS_MSG_ED25519_CERTIFICATE_DEP = 3074,
        MSG_IDS_MSG_ED25519_SIGNATURE_DEP_B = 3075,
        MSG_IDS_MSG_ECDSA_CERTIFICATE = 3076,
        MSG_IDS_MSG_CERTIFICATE_CHAIN = 3077,
        MSG_IDS_MSG_ECDSA_SIGNATURE = 3078,
        MSG_IDS_MSG_FILEIO_CONFIG_REQ = 4097,
        MSG_IDS_MSG_FILEIO_CONFIG_RESP = 4098,
        MSG_IDS_MSG_SBAS_RAW = 30583,
        MSG_IDS_MSG_LINUX_CPU_STATE_DEP_A = 32512,
        MSG_IDS_MSG_LINUX_MEM_STATE_DEP_A = 32513,
        MSG_IDS_MSG_LINUX_SYS_STATE_DEP_A = 32514,
        MSG_IDS_MSG_LINUX_PROCESS_SOCKET_COUNTS = 32515,
        MSG_IDS_MSG_LINUX_PROCESS_SOCKET_QUEUES = 32516,
        MSG_IDS_MSG_LINUX_SOCKET_USAGE = 32517,
        MSG_IDS_MSG_LINUX_PROCESS_FD_COUNT = 32518,
        MSG_IDS_MSG_LINUX_PROCESS_FD_SUMMARY = 32519,
        MSG_IDS_MSG_LINUX_CPU_STATE = 32520,
        MSG_IDS_MSG_LINUX_MEM_STATE = 32521,
        MSG_IDS_MSG_LINUX_SYS_STATE = 32522,
        MSG_IDS_MSG_STARTUP = 65280,
        MSG_IDS_MSG_DGNSS_STATUS = 65282,
        MSG_IDS_MSG_INS_STATUS = 65283,
        MSG_IDS_MSG_CSAC_TELEMETRY = 65284,
        MSG_IDS_MSG_CSAC_TELEMETRY_LABELS = 65285,
        MSG_IDS_MSG_INS_UPDATES = 65286,
        MSG_IDS_MSG_GNSS_TIME_OFFSET = 65287,
        MSG_IDS_MSG_PPS_TIME = 65288,
        MSG_IDS_MSG_SENSOR_AID_EVENT = 65289,
        MSG_IDS_MSG_GROUP_META = 65290,
        MSG_IDS_MSG_SOLN_META = 65294,
        MSG_IDS_MSG_SOLN_META_DEP_A = 65295,
        MSG_IDS_MSG_STATUS_JOURNAL = 65533,
        MSG_IDS_MSG_STATUS_REPORT = 65534,
        MSG_IDS_MSG_HEARTBEAT = 65535
    };

    sbp_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent = 0, sbp_t* p__root = 0);

private:
    void _read();
    void _clean_up();

public:
    ~sbp_t();

    class message_t : public kaitai::kstruct {

    public:

        message_t(kaitai::kstream* p__io, sbp_t* p__parent = 0, sbp_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~message_t();

    private:
        sbp_header_t* m_header;
        kaitai::kstruct* m_payload;
        bool n_payload;

    public:
        bool _is_null_payload() { payload(); return n_payload; };

    private:
        uint16_t m_crc;
        sbp_t* m__root;
        sbp_t* m__parent;
        std::string m__raw_payload;
        kaitai::kstream* m__io__raw_payload;

    public:
        sbp_header_t* header() const { return m_header; }
        kaitai::kstruct* payload() const { return m_payload; }
        uint16_t crc() const { return m_crc; }
        sbp_t* _root() const { return m__root; }
        sbp_t* _parent() const { return m__parent; }
        std::string _raw_payload() const { return m__raw_payload; }
        kaitai::kstream* _io__raw_payload() const { return m__io__raw_payload; }
    };

    class sbp_header_t : public kaitai::kstruct {

    public:

        sbp_header_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent = 0, sbp_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~sbp_header_t();

    private:
        std::string m_preamble;
        msg_ids_t m_msg_type;
        uint16_t m_sender;
        uint8_t m_length;
        sbp_t* m__root;
        sbp_t::message_t* m__parent;

    public:
        std::string preamble() const { return m_preamble; }
        msg_ids_t msg_type() const { return m_msg_type; }
        uint16_t sender() const { return m_sender; }
        uint8_t length() const { return m_length; }
        sbp_t* _root() const { return m__root; }
        sbp_t::message_t* _parent() const { return m__parent; }
    };

private:
    std::vector<message_t*>* m_message;
    sbp_t* m__root;
    kaitai::kstruct* m__parent;

public:
    std::vector<message_t*>* message() const { return m_message; }
    sbp_t* _root() const { return m__root; }
    kaitai::kstruct* _parent() const { return m__parent; }
};

#endif  // SBP_H_
