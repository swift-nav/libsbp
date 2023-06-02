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
    m_message = new std::vector<sbp_message_t*>();
    {
        int i = 0;
        while (!m__io->is_eof()) {
            m_message->push_back(new sbp_message_t(m__io, this, m__root));
            i++;
        }
    }
}

sbp_t::~sbp_t() {
    _clean_up();
}

void sbp_t::_clean_up() {
    if (m_message) {
        for (std::vector<sbp_message_t*>::iterator it = m_message->begin(); it != m_message->end(); ++it) {
            delete *it;
        }
        delete m_message; m_message = 0;
    }
}

sbp_t::sbp_message_t::sbp_message_t(kaitai::kstream* p__io, sbp_t* p__parent, sbp_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m__io__raw_payload = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void sbp_t::sbp_message_t::_read() {
    m_preamble = m__io->read_bytes(1);
    if (!(preamble() == std::string("\x55", 1))) {
        throw kaitai::validation_not_equal_error<std::string>(std::string("\x55", 1), preamble(), _io(), std::string("/types/sbp_message/seq/0"));
    }
    m_msg_type = m__io->read_u2le();
    m_sender = m__io->read_u2le();
    m_length = m__io->read_u1();
    n_payload = true;
    switch (msg_type()) {
    case 525: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new navigation_t::msg_vel_ecef_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 141: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new observation_t::msg_ephemeris_gal_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 243: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new flash_t::msg_m25_flash_write_status_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 2048: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new user_t::msg_user_data_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 3079: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new signing_t::msg_ecdsa_signature_dep_b_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 184: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new piksi_t::msg_command_req_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 105: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new piksi_t::msg_almanac_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 142: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new observation_t::msg_ephemeris_qzss_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 112: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new observation_t::msg_almanac_gps_dep_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 177: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new bootload_t::msg_bootloader_jump_to_app_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 163: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new file_io_t::msg_fileio_read_resp_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 257: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new ext_events_t::msg_ext_event_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 4097: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new file_io_t::msg_fileio_config_req_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 17: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new tracking_t::msg_tracking_state_detailed_dep_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 260: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new navigation_t::msg_gps_time_gnss_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 1525: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new ssr_t::msg_ssr_grid_definition_dep_a_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 131: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new observation_t::msg_ephemeris_glo_dep_a_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 167: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new settings_t::msg_settings_read_by_index_resp_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 146: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new observation_t::msg_group_delay_dep_a_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 47: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new acquisition_t::msg_acq_result_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 136: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new observation_t::msg_ephemeris_glo_dep_d_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 73: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new observation_t::msg_obs_dep_c_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 65283: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new system_t::msg_ins_status_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 32513: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new linux_t::msg_linux_mem_state_dep_a_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 545: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new orientation_t::msg_orient_euler_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 65534: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new system_t::msg_status_report_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 533: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new navigation_t::msg_vel_ecef_cov_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 513: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new navigation_t::msg_pos_llh_dep_a_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 46: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new acquisition_t::msg_acq_sv_profile_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 81: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new piksi_t::msg_specan_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 169: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new file_io_t::msg_fileio_read_dir_req_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 162: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new settings_t::msg_settings_read_by_index_req_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 546: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new orientation_t::msg_angular_rate_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 531: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new navigation_t::msg_vel_body_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 224: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new flash_t::msg_flash_done_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 24: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new piksi_t::msg_uart_state_depa_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 230: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new flash_t::msg_flash_program_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 65285: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new system_t::msg_csac_telemetry_labels_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 35: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new piksi_t::msg_init_base_dep_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 1528: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new ssr_t::msg_ssr_tile_definition_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 519: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new navigation_t::msg_baseline_heading_dep_a_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 20: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new acquisition_t::msg_acq_result_dep_b_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 570: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new navigation_t::msg_utc_leap_second_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 32520: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new linux_t::msg_linux_cpu_state_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 1505: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new ssr_t::msg_ssr_code_biases_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 113: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new observation_t::msg_almanac_glo_dep_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 1515: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new ssr_t::msg_ssr_stec_correction_dep_a_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 558: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new navigation_t::msg_vel_ned_gnss_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 530: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new navigation_t::msg_vel_ned_cov_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 288: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new telemetry_t::msg_tel_sv_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 1026: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new logging_t::msg_fwd_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 65286: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new system_t::msg_ins_updates_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 65284: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new system_t::msg_csac_telemetry_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 191: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new piksi_t::msg_front_end_gain_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 520: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new navigation_t::msg_dops_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 27: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new piksi_t::msg_mask_satellite_dep_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 1516: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new ssr_t::msg_ssr_code_phase_biases_bounds_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 150: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new observation_t::msg_gnss_capb_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 97: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new tracking_t::msg_measurement_state_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 529: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new navigation_t::msg_pos_llh_cov_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 431: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new settings_t::msg_settings_register_resp_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 65533: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new system_t::msg_status_journal_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 145: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new observation_t::msg_sv_configuration_gps_dep_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 32522: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new linux_t::msg_linux_sys_state_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 3076: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new signing_t::msg_ecdsa_certificate_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 144: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new observation_t::msg_iono_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 65294: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new solution_meta_t::msg_soln_meta_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 532: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new navigation_t::msg_pos_ecef_cov_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 45: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new tracking_t::msg_tracking_iq_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 561: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new navigation_t::msg_pos_llh_cov_gnss_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 1502: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new ssr_t::msg_ssr_orbit_clock_bounds_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 149: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new observation_t::msg_ephemeris_gal_dep_a_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 115: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new observation_t::msg_almanac_glo_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 32512: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new linux_t::msg_linux_cpu_state_dep_a_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 32521: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new linux_t::msg_linux_mem_state_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 522: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new navigation_t::msg_pos_llh_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 104: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new piksi_t::msg_set_time_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 32519: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new linux_t::msg_linux_process_fd_summary_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 4098: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new file_io_t::msg_fileio_config_resp_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 32517: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new linux_t::msg_linux_socket_usage_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 2306: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new mag_t::msg_mag_raw_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 67: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new observation_t::msg_obs_dep_b_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 69: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new observation_t::msg_obs_dep_a_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 512: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new navigation_t::msg_pos_ecef_dep_a_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 137: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new observation_t::msg_ephemeris_bds_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 65288: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new system_t::msg_pps_time_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 3074: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new signing_t::msg_ed25519_certificate_dep_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 562: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new navigation_t::msg_vel_ned_cov_gnss_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 580: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new navigation_t::msg_reference_frame_param_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 524: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new navigation_t::msg_baseline_ned_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 161: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new settings_t::msg_settings_save_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 138: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new observation_t::msg_ephemeris_gps_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 544: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new orientation_t::msg_orient_quat_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 192: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new piksi_t::msg_cw_results_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 165: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new settings_t::msg_settings_read_resp_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 33: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new tracking_t::msg_tracking_state_detailed_dep_a_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 1527: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new ssr_t::msg_ssr_tile_definition_dep_b_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 65535: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new system_t::msg_heartbeat_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 3081: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new signing_t::msg_certificate_chain_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 514: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new navigation_t::msg_baseline_ecef_dep_a_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 185: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new piksi_t::msg_command_resp_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 180: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new bootload_t::msg_bootloader_handshake_resp_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 19: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new tracking_t::msg_tracking_state_dep_b_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 3015: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new integrity_t::msg_ssr_flag_iono_grid_points_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 186: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new piksi_t::msg_network_state_req_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 32518: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new linux_t::msg_linux_process_fd_count_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 1530: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new ssr_t::msg_ssr_gridded_correction_dep_a_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 1541: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new ssr_t::msg_ssr_satellite_apc_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 30583: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new sbas_t::msg_sbas_raw_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 23: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new piksi_t::msg_thread_state_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 221: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new bootload_t::msg_nap_device_dna_resp_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 227: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new flash_t::msg_stm_flash_lock_sector_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 188: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new piksi_t::msg_command_output_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 65282: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new system_t::msg_dgnss_status_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 178: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new piksi_t::msg_reset_dep_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 1533: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new ssr_t::msg_ssr_stec_correction_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 3011: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new integrity_t::msg_ssr_flag_tropo_grid_points_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 3005: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new integrity_t::msg_ssr_flag_satellites_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 160: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new settings_t::msg_settings_write_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 540: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new navigation_t::msg_vel_cog_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 174: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new settings_t::msg_settings_register_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 176: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new bootload_t::msg_bootloader_handshake_dep_a_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 1024: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new ndb_t::msg_ndb_event_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 166: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new settings_t::msg_settings_read_by_index_done_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 114: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new observation_t::msg_almanac_gps_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 564: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new navigation_t::msg_pos_ecef_cov_gnss_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 259: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new navigation_t::msg_utc_time_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 181: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new piksi_t::msg_device_monitor_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 521: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new navigation_t::msg_pos_ecef_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 2307: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new vehicle_t::msg_odometry_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 148: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new observation_t::msg_group_delay_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 117: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new observation_t::msg_glo_biases_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 3025: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new integrity_t::msg_ssr_flag_iono_grid_point_sat_los_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 65: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new tracking_t::msg_tracking_state_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 1534: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new ssr_t::msg_ssr_gridded_correction_bounds_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 44: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new tracking_t::msg_tracking_iq_dep_b_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 3073: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new signing_t::msg_ed25519_signature_dep_a_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 231: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new flash_t::msg_flash_read_req_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 140: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new observation_t::msg_ephemeris_sbas_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 226: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new flash_t::msg_flash_erase_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 515: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new navigation_t::msg_baseline_ned_dep_a_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 2308: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new vehicle_t::msg_wheeltick_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 535: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new navigation_t::msg_protection_level_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 179: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new bootload_t::msg_bootloader_handshake_req_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 172: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new file_io_t::msg_fileio_remove_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 130: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new observation_t::msg_ephemeris_sbas_dep_a_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 187: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new piksi_t::msg_network_state_resp_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 1501: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new ssr_t::msg_ssr_orbit_clock_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 21: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new acquisition_t::msg_acq_result_dep_a_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 1500: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new ssr_t::msg_ssr_orbit_clock_dep_a_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 225: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new flash_t::msg_flash_read_resp_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 534: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new navigation_t::msg_protection_level_dep_a_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 232: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new flash_t::msg_stm_unique_id_req_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 2304: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new imu_t::msg_imu_raw_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 229: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new flash_t::msg_stm_unique_id_resp_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 32515: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new linux_t::msg_linux_process_socket_counts_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 65295: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new solution_meta_t::msg_soln_meta_dep_a_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 3075: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new signing_t::msg_ed25519_signature_dep_b_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 258: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new navigation_t::msg_gps_time_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 32516: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new linux_t::msg_linux_process_socket_queues_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 170: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new file_io_t::msg_fileio_read_dir_resp_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 256: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new navigation_t::msg_gps_time_dep_a_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 32514: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new linux_t::msg_linux_sys_state_dep_a_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 518: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new navigation_t::msg_dops_dep_a_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 553: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new navigation_t::msg_pos_ecef_gnss_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 517: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new navigation_t::msg_vel_ned_dep_a_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 164: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new settings_t::msg_settings_read_req_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 182: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new piksi_t::msg_reset_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 189: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new piksi_t::msg_network_bandwidth_usage_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 72: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new observation_t::msg_base_pos_ecef_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 71: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new observation_t::msg_ephemeris_dep_c_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 1025: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new logging_t::msg_log_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 168: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new file_io_t::msg_fileio_read_req_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 581: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new navigation_t::msg_pose_relative_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 171: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new file_io_t::msg_fileio_write_resp_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 70: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new observation_t::msg_ephemeris_dep_b_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 28: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new tracking_t::msg_tracking_iq_dep_a_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 193: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new piksi_t::msg_cw_start_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 133: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new observation_t::msg_ephemeris_glo_dep_b_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 129: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new observation_t::msg_ephemeris_gps_dep_e_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 74: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new observation_t::msg_obs_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 3080: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new signing_t::msg_ecdsa_signature_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 151: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new observation_t::msg_sv_az_el_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 16: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new logging_t::msg_print_dep_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 147: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new observation_t::msg_group_delay_dep_b_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 527: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new orientation_t::msg_baseline_heading_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 134: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new observation_t::msg_ephemeris_gps_dep_f_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 3078: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new signing_t::msg_ecdsa_signature_dep_a_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 80: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new piksi_t::msg_specan_dep_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 68: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new observation_t::msg_base_pos_llh_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 1532: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new ssr_t::msg_ssr_gridded_correction_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 1503: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new ssr_t::msg_ssr_orbit_clock_bounds_degradation_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 516: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new navigation_t::msg_vel_ecef_dep_a_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 26: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new observation_t::msg_ephemeris_dep_a_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 139: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new observation_t::msg_ephemeris_glo_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 65280: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new system_t::msg_startup_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 31: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new acquisition_t::msg_acq_result_dep_c_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 565: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new navigation_t::msg_vel_ecef_cov_gnss_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 135: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new observation_t::msg_ephemeris_glo_dep_c_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 3026: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new integrity_t::msg_acknowledge_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 34: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new piksi_t::msg_reset_filters_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 1600: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new observation_t::msg_osr_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 536: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new navigation_t::msg_pos_llh_acc_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 65287: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new system_t::msg_gnss_time_offset_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 1526: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new ssr_t::msg_ssr_tile_definition_dep_a_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 1540: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new ssr_t::msg_ssr_satellite_apc_dep_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 29: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new piksi_t::msg_uart_state_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 132: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new observation_t::msg_ephemeris_sbas_dep_b_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 1510: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new ssr_t::msg_ssr_phase_biases_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 65290: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new system_t::msg_group_meta_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 175: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new settings_t::msg_settings_write_resp_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 557: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new navigation_t::msg_vel_ecef_gnss_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 526: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new navigation_t::msg_vel_ned_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 1520: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new ssr_t::msg_ssr_gridded_correction_no_std_dep_a_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 2305: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new imu_t::msg_imu_aux_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 190: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new piksi_t::msg_cell_modem_status_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 1531: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new ssr_t::msg_ssr_stec_correction_dep_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 528: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new navigation_t::msg_age_corrections_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 3077: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new signing_t::msg_certificate_chain_dep_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 25: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new piksi_t::msg_iar_state_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 43: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new piksi_t::msg_mask_satellite_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 228: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new flash_t::msg_stm_flash_unlock_sector_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 523: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new navigation_t::msg_baseline_ecef_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 554: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new navigation_t::msg_pos_llh_gnss_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 65289: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new system_t::msg_sensor_aid_event_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 22: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new tracking_t::msg_tracking_state_dep_a_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 3001: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new integrity_t::msg_ssr_flag_high_level_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 30: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new acquisition_t::msg_acq_sv_profile_dep_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 261: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new navigation_t::msg_utc_time_gnss_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 3021: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new integrity_t::msg_ssr_flag_iono_tile_sat_los_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 173: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new file_io_t::msg_fileio_write_req_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 128: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new observation_t::msg_ephemeris_dep_d_t(m__io__raw_payload, this, m__root);
        break;
    }
    case 222: {
        n_payload = false;
        m__raw_payload = m__io->read_bytes(length());
        m__io__raw_payload = new kaitai::kstream(m__raw_payload);
        m_payload = new bootload_t::msg_nap_device_dna_req_t(m__io__raw_payload, this, m__root);
        break;
    }
    default: {
        m__raw_payload = m__io->read_bytes(length());
        break;
    }
    }
    m_crc = m__io->read_u2le();
}

sbp_t::sbp_message_t::~sbp_message_t() {
    _clean_up();
}

void sbp_t::sbp_message_t::_clean_up() {
    if (!n_payload) {
        if (m__io__raw_payload) {
            delete m__io__raw_payload; m__io__raw_payload = 0;
        }
        if (m_payload) {
            delete m_payload; m_payload = 0;
        }
    }
}
