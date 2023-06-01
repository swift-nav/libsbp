// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

#include "sbp.h"
#include "kaitai/exceptions.h"

sbp_t::sbp_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent, sbp_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = this;
    m_message = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void sbp_t::_read() {
    m_message = new std::vector<message_t*>();
    {
        int i = 0;
        while (!m__io->is_eof()) {
            m_message->push_back(new message_t(m__io, this, m__root));
            i++;
        }
    }
}

sbp_t::~sbp_t() {
    _clean_up();
}

void sbp_t::_clean_up() {
    if (m_message) {
        for (std::vector<message_t*>::iterator it = m_message->begin(); it != m_message->end(); ++it) {
            delete *it;
        }
        delete m_message; m_message = 0;
    }
}

sbp_t::message_t::message_t(kaitai::kstream* p__io, sbp_t* p__parent, sbp_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_header = 0;
    m__io__raw_payload = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void sbp_t::message_t::_read() {
    m_header = new sbp_header_t(m__io, this, m__root);
    n_payload = true;
    switch (header()->msg_type()) {
    case sbp_t::MSG_IDS_MSG_BASELINE_ECEF: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new navigation_t::msg_baseline_ecef_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_EPHEMERIS_BDS: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new observation_t::msg_ephemeris_bds_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_EPHEMERIS_GLO_DEP_D: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new observation_t::msg_ephemeris_glo_dep_d_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_ECDSA_SIGNATURE_DEP_B: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new signing_t::msg_ecdsa_signature_dep_b_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_SETTINGS_READ_BY_INDEX_REQ: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new settings_t::msg_settings_read_by_index_req_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_SSR_FLAG_HIGH_LEVEL: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new integrity_t::msg_ssr_flag_high_level_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_FILEIO_CONFIG_REQ: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new file_io_t::msg_fileio_config_req_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_ODOMETRY: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new vehicle_t::msg_odometry_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_SSR_STEC_CORRECTION_DEP: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new ssr_t::msg_ssr_stec_correction_dep_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_ED25519_SIGNATURE_DEP_B: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new signing_t::msg_ed25519_signature_dep_b_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_STM_UNIQUE_ID_REQ: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new flash_t::msg_stm_unique_id_req_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_FRONT_END_GAIN: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new piksi_t::msg_front_end_gain_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_BASE_POS_LLH: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new observation_t::msg_base_pos_llh_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_EPHEMERIS_DEP_A: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new observation_t::msg_ephemeris_dep_a_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_SSR_ORBIT_CLOCK: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new ssr_t::msg_ssr_orbit_clock_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_RESET: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new piksi_t::msg_reset_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_STM_FLASH_LOCK_SECTOR: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new flash_t::msg_stm_flash_lock_sector_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_LINUX_PROCESS_FD_SUMMARY: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new linux_t::msg_linux_process_fd_summary_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_STATUS_JOURNAL: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new system_t::msg_status_journal_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_CSAC_TELEMETRY: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new system_t::msg_csac_telemetry_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_AGE_CORRECTIONS: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new navigation_t::msg_age_corrections_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_ORIENT_EULER: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new orientation_t::msg_orient_euler_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_SSR_SATELLITE_APC_DEP: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new ssr_t::msg_ssr_satellite_apc_dep_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_BASELINE_NED: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new navigation_t::msg_baseline_ned_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_VEL_ECEF_GNSS: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new navigation_t::msg_vel_ecef_gnss_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_MEASUREMENT_STATE: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new tracking_t::msg_measurement_state_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_IONO: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new observation_t::msg_iono_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_BASE_POS_ECEF: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new observation_t::msg_base_pos_ecef_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_FLASH_PROGRAM: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new flash_t::msg_flash_program_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_ACQ_RESULT: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new acquisition_t::msg_acq_result_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_PPS_TIME: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new system_t::msg_pps_time_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_OBS: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new observation_t::msg_obs_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_EPHEMERIS_SBAS_DEP_B: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new observation_t::msg_ephemeris_sbas_dep_b_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_TRACKING_IQ: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new tracking_t::msg_tracking_iq_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_SSR_FLAG_IONO_TILE_SAT_LOS: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new integrity_t::msg_ssr_flag_iono_tile_sat_los_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_TRACKING_STATE_DETAILED_DEP: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new tracking_t::msg_tracking_state_detailed_dep_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_BOOTLOADER_HANDSHAKE_DEP_A: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new bootload_t::msg_bootloader_handshake_dep_a_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_UTC_LEAP_SECOND: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new navigation_t::msg_utc_leap_second_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_SSR_GRIDDED_CORRECTION_NO_STD_DEP_A: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new ssr_t::msg_ssr_gridded_correction_no_std_dep_a_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_BOOTLOADER_HANDSHAKE_RESP: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new bootload_t::msg_bootloader_handshake_resp_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_BASELINE_HEADING: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new orientation_t::msg_baseline_heading_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_STATUS_REPORT: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new system_t::msg_status_report_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_VEL_NED_COV: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new navigation_t::msg_vel_ned_cov_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_SET_TIME: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new piksi_t::msg_set_time_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_LINUX_CPU_STATE: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new linux_t::msg_linux_cpu_state_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_GPS_TIME_DEP_A: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new navigation_t::msg_gps_time_dep_a_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_EPHEMERIS_SBAS_DEP_A: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new observation_t::msg_ephemeris_sbas_dep_a_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_ACQ_RESULT_DEP_B: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new acquisition_t::msg_acq_result_dep_b_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_SETTINGS_REGISTER_RESP: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new settings_t::msg_settings_register_resp_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_ECDSA_SIGNATURE_DEP_A: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new signing_t::msg_ecdsa_signature_dep_a_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_EPHEMERIS_GAL: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new observation_t::msg_ephemeris_gal_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_BOOTLOADER_JUMP_TO_APP: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new bootload_t::msg_bootloader_jump_to_app_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_SSR_PHASE_BIASES: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new ssr_t::msg_ssr_phase_biases_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_FILEIO_READ_DIR_RESP: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new file_io_t::msg_fileio_read_dir_resp_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_POS_ECEF_GNSS: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new navigation_t::msg_pos_ecef_gnss_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_ALMANAC_GLO_DEP: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new observation_t::msg_almanac_glo_dep_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_VEL_ECEF_DEP_A: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new navigation_t::msg_vel_ecef_dep_a_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_THREAD_STATE: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new piksi_t::msg_thread_state_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_GPS_TIME: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new navigation_t::msg_gps_time_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_SSR_CODE_PHASE_BIASES_BOUNDS: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new ssr_t::msg_ssr_code_phase_biases_bounds_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_SETTINGS_WRITE_RESP: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new settings_t::msg_settings_write_resp_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_TRACKING_STATE: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new tracking_t::msg_tracking_state_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_VEL_ECEF: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new navigation_t::msg_vel_ecef_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_EPHEMERIS_GLO_DEP_A: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new observation_t::msg_ephemeris_glo_dep_a_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_ED25519_CERTIFICATE_DEP: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new signing_t::msg_ed25519_certificate_dep_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_BASELINE_NED_DEP_A: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new navigation_t::msg_baseline_ned_dep_a_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_SPECAN_DEP: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new piksi_t::msg_specan_dep_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_EPHEMERIS_SBAS: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new observation_t::msg_ephemeris_sbas_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_GROUP_DELAY: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new observation_t::msg_group_delay_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_POS_ECEF: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new navigation_t::msg_pos_ecef_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_ALMANAC: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new piksi_t::msg_almanac_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_SETTINGS_READ_REQ: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new settings_t::msg_settings_read_req_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_SSR_FLAG_TROPO_GRID_POINTS: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new integrity_t::msg_ssr_flag_tropo_grid_points_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_SSR_GRIDDED_CORRECTION_BOUNDS: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new ssr_t::msg_ssr_gridded_correction_bounds_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_STM_UNIQUE_ID_RESP: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new flash_t::msg_stm_unique_id_resp_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_TEL_SV: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new telemetry_t::msg_tel_sv_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_SSR_FLAG_SATELLITES: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new integrity_t::msg_ssr_flag_satellites_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_IMU_AUX: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new imu_t::msg_imu_aux_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_SSR_GRID_DEFINITION_DEP_A: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new ssr_t::msg_ssr_grid_definition_dep_a_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_POS_LLH_ACC: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new navigation_t::msg_pos_llh_acc_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_SV_CONFIGURATION_GPS_DEP: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new observation_t::msg_sv_configuration_gps_dep_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_LINUX_MEM_STATE: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new linux_t::msg_linux_mem_state_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_LINUX_SYS_STATE: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new linux_t::msg_linux_sys_state_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_SETTINGS_READ_BY_INDEX_DONE: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new settings_t::msg_settings_read_by_index_done_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_RESET_FILTERS: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new piksi_t::msg_reset_filters_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_ECDSA_SIGNATURE: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new signing_t::msg_ecdsa_signature_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_EPHEMERIS_GPS_DEP_E: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new observation_t::msg_ephemeris_gps_dep_e_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_M25_FLASH_WRITE_STATUS: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new flash_t::msg_m25_flash_write_status_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_EPHEMERIS_GPS: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new observation_t::msg_ephemeris_gps_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_COMMAND_OUTPUT: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new piksi_t::msg_command_output_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_SSR_FLAG_IONO_GRID_POINTS: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new integrity_t::msg_ssr_flag_iono_grid_points_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_VEL_NED_COV_GNSS: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new navigation_t::msg_vel_ned_cov_gnss_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_NETWORK_STATE_RESP: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new piksi_t::msg_network_state_resp_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_SSR_STEC_CORRECTION_DEP_A: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new ssr_t::msg_ssr_stec_correction_dep_a_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_COMMAND_REQ: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new piksi_t::msg_command_req_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_ACKNOWLEDGE: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new integrity_t::msg_acknowledge_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_TRACKING_IQ_DEP_A: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new tracking_t::msg_tracking_iq_dep_a_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_EPHEMERIS_GAL_DEP_A: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new observation_t::msg_ephemeris_gal_dep_a_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_SPECAN: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new piksi_t::msg_specan_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_ACQ_SV_PROFILE_DEP: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new acquisition_t::msg_acq_sv_profile_dep_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_UTC_TIME: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new navigation_t::msg_utc_time_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_EPHEMERIS_DEP_D: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new observation_t::msg_ephemeris_dep_d_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_LINUX_PROCESS_SOCKET_QUEUES: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new linux_t::msg_linux_process_socket_queues_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_UTC_TIME_GNSS: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new navigation_t::msg_utc_time_gnss_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_NDB_EVENT: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new ndb_t::msg_ndb_event_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_BOOTLOADER_HANDSHAKE_REQ: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new bootload_t::msg_bootloader_handshake_req_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_USER_DATA: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new user_t::msg_user_data_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_SENSOR_AID_EVENT: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new system_t::msg_sensor_aid_event_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_SSR_ORBIT_CLOCK_BOUNDS: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new ssr_t::msg_ssr_orbit_clock_bounds_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_POS_LLH_GNSS: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new navigation_t::msg_pos_llh_gnss_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_INIT_BASE_DEP: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new piksi_t::msg_init_base_dep_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_FILEIO_READ_REQ: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new file_io_t::msg_fileio_read_req_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_TRACKING_IQ_DEP_B: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new tracking_t::msg_tracking_iq_dep_b_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_ACQ_RESULT_DEP_C: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new acquisition_t::msg_acq_result_dep_c_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_COMMAND_RESP: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new piksi_t::msg_command_resp_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_FILEIO_REMOVE: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new file_io_t::msg_fileio_remove_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_OBS_DEP_C: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new observation_t::msg_obs_dep_c_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_SSR_TILE_DEFINITION_DEP_B: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new ssr_t::msg_ssr_tile_definition_dep_b_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_CSAC_TELEMETRY_LABELS: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new system_t::msg_csac_telemetry_labels_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_VEL_NED: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new navigation_t::msg_vel_ned_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_SETTINGS_READ_BY_INDEX_RESP: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new settings_t::msg_settings_read_by_index_resp_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_EPHEMERIS_QZSS: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new observation_t::msg_ephemeris_qzss_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_SSR_STEC_CORRECTION: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new ssr_t::msg_ssr_stec_correction_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_BASELINE_ECEF_DEP_A: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new navigation_t::msg_baseline_ecef_dep_a_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_INS_UPDATES: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new system_t::msg_ins_updates_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_POS_ECEF_COV: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new navigation_t::msg_pos_ecef_cov_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_VEL_NED_GNSS: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new navigation_t::msg_vel_ned_gnss_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_MASK_SATELLITE: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new piksi_t::msg_mask_satellite_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_GROUP_DELAY_DEP_B: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new observation_t::msg_group_delay_dep_b_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_SSR_ORBIT_CLOCK_BOUNDS_DEGRADATION: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new ssr_t::msg_ssr_orbit_clock_bounds_degradation_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_FLASH_ERASE: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new flash_t::msg_flash_erase_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_CW_START: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new piksi_t::msg_cw_start_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_SSR_ORBIT_CLOCK_DEP_A: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new ssr_t::msg_ssr_orbit_clock_dep_a_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_DOPS: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new navigation_t::msg_dops_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_NETWORK_BANDWIDTH_USAGE: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new piksi_t::msg_network_bandwidth_usage_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_ECDSA_CERTIFICATE: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new signing_t::msg_ecdsa_certificate_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_POS_LLH_DEP_A: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new navigation_t::msg_pos_llh_dep_a_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_SV_AZ_EL: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new observation_t::msg_sv_az_el_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_FILEIO_READ_DIR_REQ: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new file_io_t::msg_fileio_read_dir_req_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_EPHEMERIS_DEP_B: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new observation_t::msg_ephemeris_dep_b_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_VEL_ECEF_COV: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new navigation_t::msg_vel_ecef_cov_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_DGNSS_STATUS: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new system_t::msg_dgnss_status_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_SSR_TILE_DEFINITION_DEP_A: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new ssr_t::msg_ssr_tile_definition_dep_a_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_LOG: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new logging_t::msg_log_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_MASK_SATELLITE_DEP: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new piksi_t::msg_mask_satellite_dep_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_EXT_EVENT: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new ext_events_t::msg_ext_event_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_CELL_MODEM_STATUS: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new piksi_t::msg_cell_modem_status_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_ORIENT_QUAT: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new orientation_t::msg_orient_quat_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_HEARTBEAT: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new system_t::msg_heartbeat_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_ALMANAC_GPS_DEP: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new observation_t::msg_almanac_gps_dep_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_NAP_DEVICE_DNA_REQ: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new bootload_t::msg_nap_device_dna_req_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_ALMANAC_GPS: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new observation_t::msg_almanac_gps_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_VEL_ECEF_COV_GNSS: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new navigation_t::msg_vel_ecef_cov_gnss_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_ED25519_SIGNATURE_DEP_A: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new signing_t::msg_ed25519_signature_dep_a_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_ANGULAR_RATE: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new orientation_t::msg_angular_rate_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_VEL_BODY: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new navigation_t::msg_vel_body_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_CERTIFICATE_CHAIN: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new signing_t::msg_certificate_chain_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_SOLN_META_DEP_A: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new solution_meta_t::msg_soln_meta_dep_a_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_SSR_GRIDDED_CORRECTION_DEP_A: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new ssr_t::msg_ssr_gridded_correction_dep_a_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_EPHEMERIS_GLO_DEP_C: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new observation_t::msg_ephemeris_glo_dep_c_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_LINUX_PROCESS_FD_COUNT: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new linux_t::msg_linux_process_fd_count_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_FILEIO_READ_RESP: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new file_io_t::msg_fileio_read_resp_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_LINUX_SYS_STATE_DEP_A: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new linux_t::msg_linux_sys_state_dep_a_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_SBAS_RAW: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new sbas_t::msg_sbas_raw_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_POS_ECEF_COV_GNSS: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new navigation_t::msg_pos_ecef_cov_gnss_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_SSR_FLAG_IONO_GRID_POINT_SAT_LOS: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new integrity_t::msg_ssr_flag_iono_grid_point_sat_los_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_FILEIO_WRITE_REQ: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new file_io_t::msg_fileio_write_req_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_ACQ_SV_PROFILE: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new acquisition_t::msg_acq_sv_profile_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_EPHEMERIS_GLO_DEP_B: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new observation_t::msg_ephemeris_glo_dep_b_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_LINUX_SOCKET_USAGE: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new linux_t::msg_linux_socket_usage_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_NETWORK_STATE_REQ: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new piksi_t::msg_network_state_req_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_PROTECTION_LEVEL_DEP_A: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new navigation_t::msg_protection_level_dep_a_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_IMU_RAW: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new imu_t::msg_imu_raw_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_RESET_DEP: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new piksi_t::msg_reset_dep_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_MAG_RAW: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new mag_t::msg_mag_raw_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_STARTUP: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new system_t::msg_startup_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_GLO_BIASES: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new observation_t::msg_glo_biases_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_TRACKING_STATE_DETAILED_DEP_A: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new tracking_t::msg_tracking_state_detailed_dep_a_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_POS_LLH_COV_GNSS: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new navigation_t::msg_pos_llh_cov_gnss_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_SETTINGS_WRITE: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new settings_t::msg_settings_write_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_SETTINGS_SAVE: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new settings_t::msg_settings_save_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_ALMANAC_GLO: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new observation_t::msg_almanac_glo_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_STM_FLASH_UNLOCK_SECTOR: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new flash_t::msg_stm_flash_unlock_sector_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_GPS_TIME_GNSS: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new navigation_t::msg_gps_time_gnss_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_FLASH_READ_REQ: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new flash_t::msg_flash_read_req_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_EPHEMERIS_GLO: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new observation_t::msg_ephemeris_glo_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_BASELINE_HEADING_DEP_A: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new navigation_t::msg_baseline_heading_dep_a_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_SETTINGS_REGISTER: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new settings_t::msg_settings_register_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_GNSS_CAPB: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new observation_t::msg_gnss_capb_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_TRACKING_STATE_DEP_B: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new tracking_t::msg_tracking_state_dep_b_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_FWD: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new logging_t::msg_fwd_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_SOLN_META: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new solution_meta_t::msg_soln_meta_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_OBS_DEP_A: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new observation_t::msg_obs_dep_a_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_DEVICE_MONITOR: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new piksi_t::msg_device_monitor_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_LINUX_PROCESS_SOCKET_COUNTS: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new linux_t::msg_linux_process_socket_counts_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_VEL_COG: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new navigation_t::msg_vel_cog_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_PRINT_DEP: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new logging_t::msg_print_dep_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_CW_RESULTS: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new piksi_t::msg_cw_results_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_NAP_DEVICE_DNA_RESP: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new bootload_t::msg_nap_device_dna_resp_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_DOPS_DEP_A: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new navigation_t::msg_dops_dep_a_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_POS_ECEF_DEP_A: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new navigation_t::msg_pos_ecef_dep_a_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_SETTINGS_READ_RESP: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new settings_t::msg_settings_read_resp_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_LINUX_MEM_STATE_DEP_A: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new linux_t::msg_linux_mem_state_dep_a_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_EPHEMERIS_DEP_C: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new observation_t::msg_ephemeris_dep_c_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_FILEIO_WRITE_RESP: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new file_io_t::msg_fileio_write_resp_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_WHEELTICK: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new vehicle_t::msg_wheeltick_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_UART_STATE_DEPA: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new piksi_t::msg_uart_state_depa_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_REFERENCE_FRAME_PARAM: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new navigation_t::msg_reference_frame_param_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_POSE_RELATIVE: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new navigation_t::msg_pose_relative_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_IAR_STATE: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new piksi_t::msg_iar_state_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_UART_STATE: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new piksi_t::msg_uart_state_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_SSR_TILE_DEFINITION: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new ssr_t::msg_ssr_tile_definition_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_SSR_SATELLITE_APC: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new ssr_t::msg_ssr_satellite_apc_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_OSR: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new observation_t::msg_osr_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_POS_LLH_COV: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new navigation_t::msg_pos_llh_cov_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_GROUP_DELAY_DEP_A: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new observation_t::msg_group_delay_dep_a_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_PROTECTION_LEVEL: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new navigation_t::msg_protection_level_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_OBS_DEP_B: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new observation_t::msg_obs_dep_b_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_POS_LLH: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new navigation_t::msg_pos_llh_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_FLASH_DONE: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new flash_t::msg_flash_done_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_ACQ_RESULT_DEP_A: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new acquisition_t::msg_acq_result_dep_a_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_SSR_CODE_BIASES: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new ssr_t::msg_ssr_code_biases_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_CERTIFICATE_CHAIN_DEP: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new signing_t::msg_certificate_chain_dep_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_SSR_GRIDDED_CORRECTION: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new ssr_t::msg_ssr_gridded_correction_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_GROUP_META: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new system_t::msg_group_meta_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_FILEIO_CONFIG_RESP: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new file_io_t::msg_fileio_config_resp_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_VEL_NED_DEP_A: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new navigation_t::msg_vel_ned_dep_a_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_GNSS_TIME_OFFSET: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new system_t::msg_gnss_time_offset_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_TRACKING_STATE_DEP_A: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new tracking_t::msg_tracking_state_dep_a_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_INS_STATUS: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new system_t::msg_ins_status_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_EPHEMERIS_GPS_DEP_F: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new observation_t::msg_ephemeris_gps_dep_f_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_LINUX_CPU_STATE_DEP_A: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new linux_t::msg_linux_cpu_state_dep_a_t(m__io__raw_payload, this, m__root);
        break;
    }
    case sbp_t::MSG_IDS_MSG_FLASH_READ_RESP: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(header()->length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new flash_t::msg_flash_read_resp_t(m__io__raw_payload, this, m__root);
        break;
    }
    default: {
        m__raw_payload = m__io->read_bytes(header()->length());
        break;
    }
    }
    m_crc = m__io->read_u2le();
}

sbp_t::message_t::~message_t() {
    _clean_up();
}

void sbp_t::message_t::_clean_up() {
    if (m_header) {
        delete m_header; m_header = 0;
    }
    if (!n_payload) {
        if (m__io__raw_payload) {
            delete m__io__raw_payload; m__io__raw_payload = 0;
        }
        if (m_payload) {
            delete m_payload; m_payload = 0;
        }
    }
}

sbp_t::sbp_header_t::sbp_header_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent, sbp_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void sbp_t::sbp_header_t::_read() {
    m_preamble = m__io->read_bytes(1);
    if (!(preamble() == std::string("\x55", 1))) {
        throw kaitai::validation_not_equal_error<std::string>(std::string("\x55", 1), preamble(), _io(), std::string("/types/sbp_header/seq/0"));
    }
    m_msg_type = static_cast<sbp_t::msg_ids_t>(m__io->read_u2le());
    m_sender = m__io->read_u2le();
    m_length = m__io->read_u1();
}

sbp_t::sbp_header_t::~sbp_header_t() {
    _clean_up();
}

void sbp_t::sbp_header_t::_clean_up() {
}
