// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

#include "observation.h"

observation_t::observation_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent, observation_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = this;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void observation_t::_read() {
}

observation_t::~observation_t() {
    _clean_up();
}

void observation_t::_clean_up() {
}

observation_t::msg_sv_az_el_t::msg_sv_az_el_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent, observation_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_azel = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void observation_t::msg_sv_az_el_t::_read() {
    m_azel = new std::vector<sv_az_el_t*>();
    {
        int i = 0;
        while (!m__io->is_eof()) {
            m_azel->push_back(new sv_az_el_t(m__io, this, m__root));
            i++;
        }
    }
}

observation_t::msg_sv_az_el_t::~msg_sv_az_el_t() {
    _clean_up();
}

void observation_t::msg_sv_az_el_t::_clean_up() {
    if (m_azel) {
        for (std::vector<sv_az_el_t*>::iterator it = m_azel->begin(); it != m_azel->end(); ++it) {
            delete *it;
        }
        delete m_azel; m_azel = 0;
    }
}

observation_t::gnss_capb_t::gnss_capb_t(kaitai::kstream* p__io, observation_t::msg_gnss_capb_t* p__parent, observation_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void observation_t::gnss_capb_t::_read() {
    m_gps_active = m__io->read_u8le();
    m_gps_l2c = m__io->read_u8le();
    m_gps_l5 = m__io->read_u8le();
    m_glo_active = m__io->read_u4le();
    m_glo_l2of = m__io->read_u4le();
    m_glo_l3 = m__io->read_u4le();
    m_sbas_active = m__io->read_u8le();
    m_sbas_l5 = m__io->read_u8le();
    m_bds_active = m__io->read_u8le();
    m_bds_d2nav = m__io->read_u8le();
    m_bds_b2 = m__io->read_u8le();
    m_bds_b2a = m__io->read_u8le();
    m_qzss_active = m__io->read_u4le();
    m_gal_active = m__io->read_u8le();
    m_gal_e5 = m__io->read_u8le();
}

observation_t::gnss_capb_t::~gnss_capb_t() {
    _clean_up();
}

void observation_t::gnss_capb_t::_clean_up() {
}

observation_t::msg_group_delay_dep_b_t::msg_group_delay_dep_b_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent, observation_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_t_op = 0;
    m_sid = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void observation_t::msg_group_delay_dep_b_t::_read() {
    m_t_op = new gnss_t::gps_time_sec_t(m__io, this, m__root);
    m_sid = new gnss_t::gnss_signal_dep_t(m__io, this, m__root);
    m_valid = m__io->read_u1();
    m_tgd = m__io->read_s2le();
    m_isc_l1ca = m__io->read_s2le();
    m_isc_l2c = m__io->read_s2le();
}

observation_t::msg_group_delay_dep_b_t::~msg_group_delay_dep_b_t() {
    _clean_up();
}

void observation_t::msg_group_delay_dep_b_t::_clean_up() {
    if (m_t_op) {
        delete m_t_op; m_t_op = 0;
    }
    if (m_sid) {
        delete m_sid; m_sid = 0;
    }
}

observation_t::observation_header_dep_t::observation_header_dep_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent, observation_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_t = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void observation_t::observation_header_dep_t::_read() {
    m_t = new gnss_t::gps_time_dep_t(m__io, this, m__root);
    m_n_obs = m__io->read_u1();
}

observation_t::observation_header_dep_t::~observation_header_dep_t() {
    _clean_up();
}

void observation_t::observation_header_dep_t::_clean_up() {
    if (m_t) {
        delete m_t; m_t = 0;
    }
}

observation_t::almanac_common_content_dep_t::almanac_common_content_dep_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent, observation_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_sid = 0;
    m_toa = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void observation_t::almanac_common_content_dep_t::_read() {
    m_sid = new gnss_t::gnss_signal_dep_t(m__io, this, m__root);
    m_toa = new gnss_t::gps_time_sec_t(m__io, this, m__root);
    m_ura = m__io->read_f8le();
    m_fit_interval = m__io->read_u4le();
    m_valid = m__io->read_u1();
    m_health_bits = m__io->read_u1();
}

observation_t::almanac_common_content_dep_t::~almanac_common_content_dep_t() {
    _clean_up();
}

void observation_t::almanac_common_content_dep_t::_clean_up() {
    if (m_sid) {
        delete m_sid; m_sid = 0;
    }
    if (m_toa) {
        delete m_toa; m_toa = 0;
    }
}

observation_t::ephemeris_common_content_dep_a_t::ephemeris_common_content_dep_a_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent, observation_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_sid = 0;
    m_toe = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void observation_t::ephemeris_common_content_dep_a_t::_read() {
    m_sid = new gnss_t::gnss_signal_dep_t(m__io, this, m__root);
    m_toe = new gnss_t::gps_time_dep_t(m__io, this, m__root);
    m_ura = m__io->read_f8le();
    m_fit_interval = m__io->read_u4le();
    m_valid = m__io->read_u1();
    m_health_bits = m__io->read_u1();
}

observation_t::ephemeris_common_content_dep_a_t::~ephemeris_common_content_dep_a_t() {
    _clean_up();
}

void observation_t::ephemeris_common_content_dep_a_t::_clean_up() {
    if (m_sid) {
        delete m_sid; m_sid = 0;
    }
    if (m_toe) {
        delete m_toe; m_toe = 0;
    }
}

observation_t::ephemeris_common_content_t::ephemeris_common_content_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent, observation_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_sid = 0;
    m_toe = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void observation_t::ephemeris_common_content_t::_read() {
    m_sid = new gnss_t::gnss_signal_t(m__io, this, m__root);
    m_toe = new gnss_t::gps_time_sec_t(m__io, this, m__root);
    m_ura = m__io->read_f4le();
    m_fit_interval = m__io->read_u4le();
    m_valid = m__io->read_u1();
    m_health_bits = m__io->read_u1();
}

observation_t::ephemeris_common_content_t::~ephemeris_common_content_t() {
    _clean_up();
}

void observation_t::ephemeris_common_content_t::_clean_up() {
    if (m_sid) {
        delete m_sid; m_sid = 0;
    }
    if (m_toe) {
        delete m_toe; m_toe = 0;
    }
}

observation_t::packed_obs_content_dep_c_t::packed_obs_content_dep_c_t(kaitai::kstream* p__io, observation_t::msg_obs_dep_c_t* p__parent, observation_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_l = 0;
    m_sid = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void observation_t::packed_obs_content_dep_c_t::_read() {
    m_p = m__io->read_u4le();
    m_l = new gnss_t::carrier_phase_t(m__io, this, m__root);
    m_cn0 = m__io->read_u1();
    m_lock = m__io->read_u2le();
    m_sid = new gnss_t::gnss_signal_dep_t(m__io, this, m__root);
}

observation_t::packed_obs_content_dep_c_t::~packed_obs_content_dep_c_t() {
    _clean_up();
}

void observation_t::packed_obs_content_dep_c_t::_clean_up() {
    if (m_l) {
        delete m_l; m_l = 0;
    }
    if (m_sid) {
        delete m_sid; m_sid = 0;
    }
}

observation_t::msg_ephemeris_glo_dep_d_t::msg_ephemeris_glo_dep_d_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent, observation_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_common = 0;
    m_pos = 0;
    m_vel = 0;
    m_acc = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void observation_t::msg_ephemeris_glo_dep_d_t::_read() {
    m_common = new ephemeris_common_content_dep_b_t(m__io, this, m__root);
    m_gamma = m__io->read_f8le();
    m_tau = m__io->read_f8le();
    m_d_tau = m__io->read_f8le();
    m_pos = new std::vector<double>();
    const int l_pos = 3;
    for (int i = 0; i < l_pos; i++) {
        m_pos->push_back(m__io->read_f8le());
    }
    m_vel = new std::vector<double>();
    const int l_vel = 3;
    for (int i = 0; i < l_vel; i++) {
        m_vel->push_back(m__io->read_f8le());
    }
    m_acc = new std::vector<double>();
    const int l_acc = 3;
    for (int i = 0; i < l_acc; i++) {
        m_acc->push_back(m__io->read_f8le());
    }
    m_fcn = m__io->read_u1();
    m_iod = m__io->read_u1();
}

observation_t::msg_ephemeris_glo_dep_d_t::~msg_ephemeris_glo_dep_d_t() {
    _clean_up();
}

void observation_t::msg_ephemeris_glo_dep_d_t::_clean_up() {
    if (m_common) {
        delete m_common; m_common = 0;
    }
    if (m_pos) {
        delete m_pos; m_pos = 0;
    }
    if (m_vel) {
        delete m_vel; m_vel = 0;
    }
    if (m_acc) {
        delete m_acc; m_acc = 0;
    }
}

observation_t::msg_obs_dep_a_t::msg_obs_dep_a_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent, observation_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_header = 0;
    m_obs = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void observation_t::msg_obs_dep_a_t::_read() {
    m_header = new observation_header_dep_t(m__io, this, m__root);
    m_obs = new std::vector<packed_obs_content_dep_a_t*>();
    {
        int i = 0;
        while (!m__io->is_eof()) {
            m_obs->push_back(new packed_obs_content_dep_a_t(m__io, this, m__root));
            i++;
        }
    }
}

observation_t::msg_obs_dep_a_t::~msg_obs_dep_a_t() {
    _clean_up();
}

void observation_t::msg_obs_dep_a_t::_clean_up() {
    if (m_header) {
        delete m_header; m_header = 0;
    }
    if (m_obs) {
        for (std::vector<packed_obs_content_dep_a_t*>::iterator it = m_obs->begin(); it != m_obs->end(); ++it) {
            delete *it;
        }
        delete m_obs; m_obs = 0;
    }
}

observation_t::msg_ephemeris_dep_b_t::msg_ephemeris_dep_b_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent, observation_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void observation_t::msg_ephemeris_dep_b_t::_read() {
    m_tgd = m__io->read_f8le();
    m_c_rs = m__io->read_f8le();
    m_c_rc = m__io->read_f8le();
    m_c_uc = m__io->read_f8le();
    m_c_us = m__io->read_f8le();
    m_c_ic = m__io->read_f8le();
    m_c_is = m__io->read_f8le();
    m_dn = m__io->read_f8le();
    m_m0 = m__io->read_f8le();
    m_ecc = m__io->read_f8le();
    m_sqrta = m__io->read_f8le();
    m_omega0 = m__io->read_f8le();
    m_omegadot = m__io->read_f8le();
    m_w = m__io->read_f8le();
    m_inc = m__io->read_f8le();
    m_inc_dot = m__io->read_f8le();
    m_af0 = m__io->read_f8le();
    m_af1 = m__io->read_f8le();
    m_af2 = m__io->read_f8le();
    m_toe_tow = m__io->read_f8le();
    m_toe_wn = m__io->read_u2le();
    m_toc_tow = m__io->read_f8le();
    m_toc_wn = m__io->read_u2le();
    m_valid = m__io->read_u1();
    m_healthy = m__io->read_u1();
    m_prn = m__io->read_u1();
    m_iode = m__io->read_u1();
}

observation_t::msg_ephemeris_dep_b_t::~msg_ephemeris_dep_b_t() {
    _clean_up();
}

void observation_t::msg_ephemeris_dep_b_t::_clean_up() {
}

observation_t::msg_obs_t::msg_obs_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent, observation_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_header = 0;
    m_obs = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void observation_t::msg_obs_t::_read() {
    m_header = new observation_header_t(m__io, this, m__root);
    m_obs = new std::vector<packed_obs_content_t*>();
    {
        int i = 0;
        while (!m__io->is_eof()) {
            m_obs->push_back(new packed_obs_content_t(m__io, this, m__root));
            i++;
        }
    }
}

observation_t::msg_obs_t::~msg_obs_t() {
    _clean_up();
}

void observation_t::msg_obs_t::_clean_up() {
    if (m_header) {
        delete m_header; m_header = 0;
    }
    if (m_obs) {
        for (std::vector<packed_obs_content_t*>::iterator it = m_obs->begin(); it != m_obs->end(); ++it) {
            delete *it;
        }
        delete m_obs; m_obs = 0;
    }
}

observation_t::doppler_t::doppler_t(kaitai::kstream* p__io, observation_t::packed_obs_content_t* p__parent, observation_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void observation_t::doppler_t::_read() {
    m_i = m__io->read_s2le();
    m_f = m__io->read_u1();
}

observation_t::doppler_t::~doppler_t() {
    _clean_up();
}

void observation_t::doppler_t::_clean_up() {
}

observation_t::msg_almanac_glo_dep_t::msg_almanac_glo_dep_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent, observation_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_common = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void observation_t::msg_almanac_glo_dep_t::_read() {
    m_common = new almanac_common_content_dep_t(m__io, this, m__root);
    m_lambda_na = m__io->read_f8le();
    m_t_lambda_na = m__io->read_f8le();
    m_i = m__io->read_f8le();
    m_t = m__io->read_f8le();
    m_t_dot = m__io->read_f8le();
    m_epsilon = m__io->read_f8le();
    m_omega = m__io->read_f8le();
}

observation_t::msg_almanac_glo_dep_t::~msg_almanac_glo_dep_t() {
    _clean_up();
}

void observation_t::msg_almanac_glo_dep_t::_clean_up() {
    if (m_common) {
        delete m_common; m_common = 0;
    }
}

observation_t::msg_almanac_gps_dep_t::msg_almanac_gps_dep_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent, observation_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_common = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void observation_t::msg_almanac_gps_dep_t::_read() {
    m_common = new almanac_common_content_dep_t(m__io, this, m__root);
    m_m0 = m__io->read_f8le();
    m_ecc = m__io->read_f8le();
    m_sqrta = m__io->read_f8le();
    m_omega0 = m__io->read_f8le();
    m_omegadot = m__io->read_f8le();
    m_w = m__io->read_f8le();
    m_inc = m__io->read_f8le();
    m_af0 = m__io->read_f8le();
    m_af1 = m__io->read_f8le();
}

observation_t::msg_almanac_gps_dep_t::~msg_almanac_gps_dep_t() {
    _clean_up();
}

void observation_t::msg_almanac_gps_dep_t::_clean_up() {
    if (m_common) {
        delete m_common; m_common = 0;
    }
}

observation_t::sv_az_el_t::sv_az_el_t(kaitai::kstream* p__io, observation_t::msg_sv_az_el_t* p__parent, observation_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_sid = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void observation_t::sv_az_el_t::_read() {
    m_sid = new gnss_t::gnss_signal_t(m__io, this, m__root);
    m_az = m__io->read_u1();
    m_el = m__io->read_s1();
}

observation_t::sv_az_el_t::~sv_az_el_t() {
    _clean_up();
}

void observation_t::sv_az_el_t::_clean_up() {
    if (m_sid) {
        delete m_sid; m_sid = 0;
    }
}

observation_t::msg_glo_biases_t::msg_glo_biases_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent, observation_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void observation_t::msg_glo_biases_t::_read() {
    m_mask = m__io->read_u1();
    m_l1ca_bias = m__io->read_s2le();
    m_l1p_bias = m__io->read_s2le();
    m_l2ca_bias = m__io->read_s2le();
    m_l2p_bias = m__io->read_s2le();
}

observation_t::msg_glo_biases_t::~msg_glo_biases_t() {
    _clean_up();
}

void observation_t::msg_glo_biases_t::_clean_up() {
}

observation_t::msg_ephemeris_sbas_dep_b_t::msg_ephemeris_sbas_dep_b_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent, observation_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_common = 0;
    m_pos = 0;
    m_vel = 0;
    m_acc = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void observation_t::msg_ephemeris_sbas_dep_b_t::_read() {
    m_common = new ephemeris_common_content_dep_b_t(m__io, this, m__root);
    m_pos = new std::vector<double>();
    const int l_pos = 3;
    for (int i = 0; i < l_pos; i++) {
        m_pos->push_back(m__io->read_f8le());
    }
    m_vel = new std::vector<double>();
    const int l_vel = 3;
    for (int i = 0; i < l_vel; i++) {
        m_vel->push_back(m__io->read_f8le());
    }
    m_acc = new std::vector<double>();
    const int l_acc = 3;
    for (int i = 0; i < l_acc; i++) {
        m_acc->push_back(m__io->read_f8le());
    }
    m_a_gf0 = m__io->read_f8le();
    m_a_gf1 = m__io->read_f8le();
}

observation_t::msg_ephemeris_sbas_dep_b_t::~msg_ephemeris_sbas_dep_b_t() {
    _clean_up();
}

void observation_t::msg_ephemeris_sbas_dep_b_t::_clean_up() {
    if (m_common) {
        delete m_common; m_common = 0;
    }
    if (m_pos) {
        delete m_pos; m_pos = 0;
    }
    if (m_vel) {
        delete m_vel; m_vel = 0;
    }
    if (m_acc) {
        delete m_acc; m_acc = 0;
    }
}

observation_t::msg_ephemeris_gps_dep_e_t::msg_ephemeris_gps_dep_e_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent, observation_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_common = 0;
    m_toc = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void observation_t::msg_ephemeris_gps_dep_e_t::_read() {
    m_common = new ephemeris_common_content_dep_a_t(m__io, this, m__root);
    m_tgd = m__io->read_f8le();
    m_c_rs = m__io->read_f8le();
    m_c_rc = m__io->read_f8le();
    m_c_uc = m__io->read_f8le();
    m_c_us = m__io->read_f8le();
    m_c_ic = m__io->read_f8le();
    m_c_is = m__io->read_f8le();
    m_dn = m__io->read_f8le();
    m_m0 = m__io->read_f8le();
    m_ecc = m__io->read_f8le();
    m_sqrta = m__io->read_f8le();
    m_omega0 = m__io->read_f8le();
    m_omegadot = m__io->read_f8le();
    m_w = m__io->read_f8le();
    m_inc = m__io->read_f8le();
    m_inc_dot = m__io->read_f8le();
    m_af0 = m__io->read_f8le();
    m_af1 = m__io->read_f8le();
    m_af2 = m__io->read_f8le();
    m_toc = new gnss_t::gps_time_dep_t(m__io, this, m__root);
    m_iode = m__io->read_u1();
    m_iodc = m__io->read_u2le();
}

observation_t::msg_ephemeris_gps_dep_e_t::~msg_ephemeris_gps_dep_e_t() {
    _clean_up();
}

void observation_t::msg_ephemeris_gps_dep_e_t::_clean_up() {
    if (m_common) {
        delete m_common; m_common = 0;
    }
    if (m_toc) {
        delete m_toc; m_toc = 0;
    }
}

observation_t::msg_gnss_capb_t::msg_gnss_capb_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent, observation_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_t_nmct = 0;
    m_gc = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void observation_t::msg_gnss_capb_t::_read() {
    m_t_nmct = new gnss_t::gps_time_sec_t(m__io, this, m__root);
    m_gc = new gnss_capb_t(m__io, this, m__root);
}

observation_t::msg_gnss_capb_t::~msg_gnss_capb_t() {
    _clean_up();
}

void observation_t::msg_gnss_capb_t::_clean_up() {
    if (m_t_nmct) {
        delete m_t_nmct; m_t_nmct = 0;
    }
    if (m_gc) {
        delete m_gc; m_gc = 0;
    }
}

observation_t::msg_almanac_gps_t::msg_almanac_gps_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent, observation_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_common = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void observation_t::msg_almanac_gps_t::_read() {
    m_common = new almanac_common_content_t(m__io, this, m__root);
    m_m0 = m__io->read_f8le();
    m_ecc = m__io->read_f8le();
    m_sqrta = m__io->read_f8le();
    m_omega0 = m__io->read_f8le();
    m_omegadot = m__io->read_f8le();
    m_w = m__io->read_f8le();
    m_inc = m__io->read_f8le();
    m_af0 = m__io->read_f8le();
    m_af1 = m__io->read_f8le();
}

observation_t::msg_almanac_gps_t::~msg_almanac_gps_t() {
    _clean_up();
}

void observation_t::msg_almanac_gps_t::_clean_up() {
    if (m_common) {
        delete m_common; m_common = 0;
    }
}

observation_t::msg_ephemeris_qzss_t::msg_ephemeris_qzss_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent, observation_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_common = 0;
    m_toc = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void observation_t::msg_ephemeris_qzss_t::_read() {
    m_common = new ephemeris_common_content_t(m__io, this, m__root);
    m_tgd = m__io->read_f4le();
    m_c_rs = m__io->read_f4le();
    m_c_rc = m__io->read_f4le();
    m_c_uc = m__io->read_f4le();
    m_c_us = m__io->read_f4le();
    m_c_ic = m__io->read_f4le();
    m_c_is = m__io->read_f4le();
    m_dn = m__io->read_f8le();
    m_m0 = m__io->read_f8le();
    m_ecc = m__io->read_f8le();
    m_sqrta = m__io->read_f8le();
    m_omega0 = m__io->read_f8le();
    m_omegadot = m__io->read_f8le();
    m_w = m__io->read_f8le();
    m_inc = m__io->read_f8le();
    m_inc_dot = m__io->read_f8le();
    m_af0 = m__io->read_f4le();
    m_af1 = m__io->read_f4le();
    m_af2 = m__io->read_f4le();
    m_toc = new gnss_t::gps_time_sec_t(m__io, this, m__root);
    m_iode = m__io->read_u1();
    m_iodc = m__io->read_u2le();
}

observation_t::msg_ephemeris_qzss_t::~msg_ephemeris_qzss_t() {
    _clean_up();
}

void observation_t::msg_ephemeris_qzss_t::_clean_up() {
    if (m_common) {
        delete m_common; m_common = 0;
    }
    if (m_toc) {
        delete m_toc; m_toc = 0;
    }
}

observation_t::msg_group_delay_dep_a_t::msg_group_delay_dep_a_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent, observation_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_t_op = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void observation_t::msg_group_delay_dep_a_t::_read() {
    m_t_op = new gnss_t::gps_time_dep_t(m__io, this, m__root);
    m_prn = m__io->read_u1();
    m_valid = m__io->read_u1();
    m_tgd = m__io->read_s2le();
    m_isc_l1ca = m__io->read_s2le();
    m_isc_l2c = m__io->read_s2le();
}

observation_t::msg_group_delay_dep_a_t::~msg_group_delay_dep_a_t() {
    _clean_up();
}

void observation_t::msg_group_delay_dep_a_t::_clean_up() {
    if (m_t_op) {
        delete m_t_op; m_t_op = 0;
    }
}

observation_t::msg_ephemeris_dep_c_t::msg_ephemeris_dep_c_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent, observation_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_sid = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void observation_t::msg_ephemeris_dep_c_t::_read() {
    m_tgd = m__io->read_f8le();
    m_c_rs = m__io->read_f8le();
    m_c_rc = m__io->read_f8le();
    m_c_uc = m__io->read_f8le();
    m_c_us = m__io->read_f8le();
    m_c_ic = m__io->read_f8le();
    m_c_is = m__io->read_f8le();
    m_dn = m__io->read_f8le();
    m_m0 = m__io->read_f8le();
    m_ecc = m__io->read_f8le();
    m_sqrta = m__io->read_f8le();
    m_omega0 = m__io->read_f8le();
    m_omegadot = m__io->read_f8le();
    m_w = m__io->read_f8le();
    m_inc = m__io->read_f8le();
    m_inc_dot = m__io->read_f8le();
    m_af0 = m__io->read_f8le();
    m_af1 = m__io->read_f8le();
    m_af2 = m__io->read_f8le();
    m_toe_tow = m__io->read_f8le();
    m_toe_wn = m__io->read_u2le();
    m_toc_tow = m__io->read_f8le();
    m_toc_wn = m__io->read_u2le();
    m_valid = m__io->read_u1();
    m_healthy = m__io->read_u1();
    m_sid = new gnss_t::gnss_signal_dep_t(m__io, this, m__root);
    m_iode = m__io->read_u1();
    m_iodc = m__io->read_u2le();
    m_reserved = m__io->read_u4le();
}

observation_t::msg_ephemeris_dep_c_t::~msg_ephemeris_dep_c_t() {
    _clean_up();
}

void observation_t::msg_ephemeris_dep_c_t::_clean_up() {
    if (m_sid) {
        delete m_sid; m_sid = 0;
    }
}

observation_t::carrier_phase_dep_a_t::carrier_phase_dep_a_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent, observation_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void observation_t::carrier_phase_dep_a_t::_read() {
    m_i = m__io->read_s4le();
    m_f = m__io->read_u1();
}

observation_t::carrier_phase_dep_a_t::~carrier_phase_dep_a_t() {
    _clean_up();
}

void observation_t::carrier_phase_dep_a_t::_clean_up() {
}

observation_t::msg_ephemeris_gal_t::msg_ephemeris_gal_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent, observation_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_common = 0;
    m_toc = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void observation_t::msg_ephemeris_gal_t::_read() {
    m_common = new ephemeris_common_content_t(m__io, this, m__root);
    m_bgd_e1e5a = m__io->read_f4le();
    m_bgd_e1e5b = m__io->read_f4le();
    m_c_rs = m__io->read_f4le();
    m_c_rc = m__io->read_f4le();
    m_c_uc = m__io->read_f4le();
    m_c_us = m__io->read_f4le();
    m_c_ic = m__io->read_f4le();
    m_c_is = m__io->read_f4le();
    m_dn = m__io->read_f8le();
    m_m0 = m__io->read_f8le();
    m_ecc = m__io->read_f8le();
    m_sqrta = m__io->read_f8le();
    m_omega0 = m__io->read_f8le();
    m_omegadot = m__io->read_f8le();
    m_w = m__io->read_f8le();
    m_inc = m__io->read_f8le();
    m_inc_dot = m__io->read_f8le();
    m_af0 = m__io->read_f8le();
    m_af1 = m__io->read_f8le();
    m_af2 = m__io->read_f4le();
    m_toc = new gnss_t::gps_time_sec_t(m__io, this, m__root);
    m_iode = m__io->read_u2le();
    m_iodc = m__io->read_u2le();
    m_source = m__io->read_u1();
}

observation_t::msg_ephemeris_gal_t::~msg_ephemeris_gal_t() {
    _clean_up();
}

void observation_t::msg_ephemeris_gal_t::_clean_up() {
    if (m_common) {
        delete m_common; m_common = 0;
    }
    if (m_toc) {
        delete m_toc; m_toc = 0;
    }
}

observation_t::packed_osr_content_t::packed_osr_content_t(kaitai::kstream* p__io, observation_t::msg_osr_t* p__parent, observation_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_l = 0;
    m_sid = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void observation_t::packed_osr_content_t::_read() {
    m_p = m__io->read_u4le();
    m_l = new gnss_t::carrier_phase_t(m__io, this, m__root);
    m_lock = m__io->read_u1();
    m_flags = m__io->read_u1();
    m_sid = new gnss_t::gnss_signal_t(m__io, this, m__root);
    m_iono_std = m__io->read_u2le();
    m_tropo_std = m__io->read_u2le();
    m_range_std = m__io->read_u2le();
}

observation_t::packed_osr_content_t::~packed_osr_content_t() {
    _clean_up();
}

void observation_t::packed_osr_content_t::_clean_up() {
    if (m_l) {
        delete m_l; m_l = 0;
    }
    if (m_sid) {
        delete m_sid; m_sid = 0;
    }
}

observation_t::msg_ephemeris_bds_t::msg_ephemeris_bds_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent, observation_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_common = 0;
    m_toc = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void observation_t::msg_ephemeris_bds_t::_read() {
    m_common = new ephemeris_common_content_t(m__io, this, m__root);
    m_tgd1 = m__io->read_f4le();
    m_tgd2 = m__io->read_f4le();
    m_c_rs = m__io->read_f4le();
    m_c_rc = m__io->read_f4le();
    m_c_uc = m__io->read_f4le();
    m_c_us = m__io->read_f4le();
    m_c_ic = m__io->read_f4le();
    m_c_is = m__io->read_f4le();
    m_dn = m__io->read_f8le();
    m_m0 = m__io->read_f8le();
    m_ecc = m__io->read_f8le();
    m_sqrta = m__io->read_f8le();
    m_omega0 = m__io->read_f8le();
    m_omegadot = m__io->read_f8le();
    m_w = m__io->read_f8le();
    m_inc = m__io->read_f8le();
    m_inc_dot = m__io->read_f8le();
    m_af0 = m__io->read_f8le();
    m_af1 = m__io->read_f4le();
    m_af2 = m__io->read_f4le();
    m_toc = new gnss_t::gps_time_sec_t(m__io, this, m__root);
    m_iode = m__io->read_u1();
    m_iodc = m__io->read_u2le();
}

observation_t::msg_ephemeris_bds_t::~msg_ephemeris_bds_t() {
    _clean_up();
}

void observation_t::msg_ephemeris_bds_t::_clean_up() {
    if (m_common) {
        delete m_common; m_common = 0;
    }
    if (m_toc) {
        delete m_toc; m_toc = 0;
    }
}

observation_t::msg_ephemeris_gps_dep_f_t::msg_ephemeris_gps_dep_f_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent, observation_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_common = 0;
    m_toc = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void observation_t::msg_ephemeris_gps_dep_f_t::_read() {
    m_common = new ephemeris_common_content_dep_b_t(m__io, this, m__root);
    m_tgd = m__io->read_f8le();
    m_c_rs = m__io->read_f8le();
    m_c_rc = m__io->read_f8le();
    m_c_uc = m__io->read_f8le();
    m_c_us = m__io->read_f8le();
    m_c_ic = m__io->read_f8le();
    m_c_is = m__io->read_f8le();
    m_dn = m__io->read_f8le();
    m_m0 = m__io->read_f8le();
    m_ecc = m__io->read_f8le();
    m_sqrta = m__io->read_f8le();
    m_omega0 = m__io->read_f8le();
    m_omegadot = m__io->read_f8le();
    m_w = m__io->read_f8le();
    m_inc = m__io->read_f8le();
    m_inc_dot = m__io->read_f8le();
    m_af0 = m__io->read_f8le();
    m_af1 = m__io->read_f8le();
    m_af2 = m__io->read_f8le();
    m_toc = new gnss_t::gps_time_sec_t(m__io, this, m__root);
    m_iode = m__io->read_u1();
    m_iodc = m__io->read_u2le();
}

observation_t::msg_ephemeris_gps_dep_f_t::~msg_ephemeris_gps_dep_f_t() {
    _clean_up();
}

void observation_t::msg_ephemeris_gps_dep_f_t::_clean_up() {
    if (m_common) {
        delete m_common; m_common = 0;
    }
    if (m_toc) {
        delete m_toc; m_toc = 0;
    }
}

observation_t::observation_header_t::observation_header_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent, observation_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_t = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void observation_t::observation_header_t::_read() {
    m_t = new gnss_t::gps_time_t(m__io, this, m__root);
    m_n_obs = m__io->read_u1();
}

observation_t::observation_header_t::~observation_header_t() {
    _clean_up();
}

void observation_t::observation_header_t::_clean_up() {
    if (m_t) {
        delete m_t; m_t = 0;
    }
}

observation_t::msg_ephemeris_sbas_dep_a_t::msg_ephemeris_sbas_dep_a_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent, observation_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_common = 0;
    m_pos = 0;
    m_vel = 0;
    m_acc = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void observation_t::msg_ephemeris_sbas_dep_a_t::_read() {
    m_common = new ephemeris_common_content_dep_a_t(m__io, this, m__root);
    m_pos = new std::vector<double>();
    const int l_pos = 3;
    for (int i = 0; i < l_pos; i++) {
        m_pos->push_back(m__io->read_f8le());
    }
    m_vel = new std::vector<double>();
    const int l_vel = 3;
    for (int i = 0; i < l_vel; i++) {
        m_vel->push_back(m__io->read_f8le());
    }
    m_acc = new std::vector<double>();
    const int l_acc = 3;
    for (int i = 0; i < l_acc; i++) {
        m_acc->push_back(m__io->read_f8le());
    }
    m_a_gf0 = m__io->read_f8le();
    m_a_gf1 = m__io->read_f8le();
}

observation_t::msg_ephemeris_sbas_dep_a_t::~msg_ephemeris_sbas_dep_a_t() {
    _clean_up();
}

void observation_t::msg_ephemeris_sbas_dep_a_t::_clean_up() {
    if (m_common) {
        delete m_common; m_common = 0;
    }
    if (m_pos) {
        delete m_pos; m_pos = 0;
    }
    if (m_vel) {
        delete m_vel; m_vel = 0;
    }
    if (m_acc) {
        delete m_acc; m_acc = 0;
    }
}

observation_t::packed_obs_content_t::packed_obs_content_t(kaitai::kstream* p__io, observation_t::msg_obs_t* p__parent, observation_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_l = 0;
    m_d = 0;
    m_sid = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void observation_t::packed_obs_content_t::_read() {
    m_p = m__io->read_u4le();
    m_l = new gnss_t::carrier_phase_t(m__io, this, m__root);
    m_d = new doppler_t(m__io, this, m__root);
    m_cn0 = m__io->read_u1();
    m_lock = m__io->read_u1();
    m_flags = m__io->read_u1();
    m_sid = new gnss_t::gnss_signal_t(m__io, this, m__root);
}

observation_t::packed_obs_content_t::~packed_obs_content_t() {
    _clean_up();
}

void observation_t::packed_obs_content_t::_clean_up() {
    if (m_l) {
        delete m_l; m_l = 0;
    }
    if (m_d) {
        delete m_d; m_d = 0;
    }
    if (m_sid) {
        delete m_sid; m_sid = 0;
    }
}

observation_t::msg_base_pos_ecef_t::msg_base_pos_ecef_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent, observation_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void observation_t::msg_base_pos_ecef_t::_read() {
    m_x = m__io->read_f8le();
    m_y = m__io->read_f8le();
    m_z = m__io->read_f8le();
}

observation_t::msg_base_pos_ecef_t::~msg_base_pos_ecef_t() {
    _clean_up();
}

void observation_t::msg_base_pos_ecef_t::_clean_up() {
}

observation_t::msg_ephemeris_glo_dep_a_t::msg_ephemeris_glo_dep_a_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent, observation_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_common = 0;
    m_pos = 0;
    m_vel = 0;
    m_acc = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void observation_t::msg_ephemeris_glo_dep_a_t::_read() {
    m_common = new ephemeris_common_content_dep_a_t(m__io, this, m__root);
    m_gamma = m__io->read_f8le();
    m_tau = m__io->read_f8le();
    m_pos = new std::vector<double>();
    const int l_pos = 3;
    for (int i = 0; i < l_pos; i++) {
        m_pos->push_back(m__io->read_f8le());
    }
    m_vel = new std::vector<double>();
    const int l_vel = 3;
    for (int i = 0; i < l_vel; i++) {
        m_vel->push_back(m__io->read_f8le());
    }
    m_acc = new std::vector<double>();
    const int l_acc = 3;
    for (int i = 0; i < l_acc; i++) {
        m_acc->push_back(m__io->read_f8le());
    }
}

observation_t::msg_ephemeris_glo_dep_a_t::~msg_ephemeris_glo_dep_a_t() {
    _clean_up();
}

void observation_t::msg_ephemeris_glo_dep_a_t::_clean_up() {
    if (m_common) {
        delete m_common; m_common = 0;
    }
    if (m_pos) {
        delete m_pos; m_pos = 0;
    }
    if (m_vel) {
        delete m_vel; m_vel = 0;
    }
    if (m_acc) {
        delete m_acc; m_acc = 0;
    }
}

observation_t::msg_group_delay_t::msg_group_delay_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent, observation_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_t_op = 0;
    m_sid = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void observation_t::msg_group_delay_t::_read() {
    m_t_op = new gnss_t::gps_time_sec_t(m__io, this, m__root);
    m_sid = new gnss_t::gnss_signal_t(m__io, this, m__root);
    m_valid = m__io->read_u1();
    m_tgd = m__io->read_s2le();
    m_isc_l1ca = m__io->read_s2le();
    m_isc_l2c = m__io->read_s2le();
}

observation_t::msg_group_delay_t::~msg_group_delay_t() {
    _clean_up();
}

void observation_t::msg_group_delay_t::_clean_up() {
    if (m_t_op) {
        delete m_t_op; m_t_op = 0;
    }
    if (m_sid) {
        delete m_sid; m_sid = 0;
    }
}

observation_t::msg_almanac_glo_t::msg_almanac_glo_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent, observation_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_common = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void observation_t::msg_almanac_glo_t::_read() {
    m_common = new almanac_common_content_t(m__io, this, m__root);
    m_lambda_na = m__io->read_f8le();
    m_t_lambda_na = m__io->read_f8le();
    m_i = m__io->read_f8le();
    m_t = m__io->read_f8le();
    m_t_dot = m__io->read_f8le();
    m_epsilon = m__io->read_f8le();
    m_omega = m__io->read_f8le();
}

observation_t::msg_almanac_glo_t::~msg_almanac_glo_t() {
    _clean_up();
}

void observation_t::msg_almanac_glo_t::_clean_up() {
    if (m_common) {
        delete m_common; m_common = 0;
    }
}

observation_t::msg_ephemeris_gal_dep_a_t::msg_ephemeris_gal_dep_a_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent, observation_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_common = 0;
    m_toc = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void observation_t::msg_ephemeris_gal_dep_a_t::_read() {
    m_common = new ephemeris_common_content_t(m__io, this, m__root);
    m_bgd_e1e5a = m__io->read_f4le();
    m_bgd_e1e5b = m__io->read_f4le();
    m_c_rs = m__io->read_f4le();
    m_c_rc = m__io->read_f4le();
    m_c_uc = m__io->read_f4le();
    m_c_us = m__io->read_f4le();
    m_c_ic = m__io->read_f4le();
    m_c_is = m__io->read_f4le();
    m_dn = m__io->read_f8le();
    m_m0 = m__io->read_f8le();
    m_ecc = m__io->read_f8le();
    m_sqrta = m__io->read_f8le();
    m_omega0 = m__io->read_f8le();
    m_omegadot = m__io->read_f8le();
    m_w = m__io->read_f8le();
    m_inc = m__io->read_f8le();
    m_inc_dot = m__io->read_f8le();
    m_af0 = m__io->read_f8le();
    m_af1 = m__io->read_f8le();
    m_af2 = m__io->read_f4le();
    m_toc = new gnss_t::gps_time_sec_t(m__io, this, m__root);
    m_iode = m__io->read_u2le();
    m_iodc = m__io->read_u2le();
}

observation_t::msg_ephemeris_gal_dep_a_t::~msg_ephemeris_gal_dep_a_t() {
    _clean_up();
}

void observation_t::msg_ephemeris_gal_dep_a_t::_clean_up() {
    if (m_common) {
        delete m_common; m_common = 0;
    }
    if (m_toc) {
        delete m_toc; m_toc = 0;
    }
}

observation_t::msg_obs_dep_b_t::msg_obs_dep_b_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent, observation_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_header = 0;
    m_obs = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void observation_t::msg_obs_dep_b_t::_read() {
    m_header = new observation_header_dep_t(m__io, this, m__root);
    m_obs = new std::vector<packed_obs_content_dep_b_t*>();
    {
        int i = 0;
        while (!m__io->is_eof()) {
            m_obs->push_back(new packed_obs_content_dep_b_t(m__io, this, m__root));
            i++;
        }
    }
}

observation_t::msg_obs_dep_b_t::~msg_obs_dep_b_t() {
    _clean_up();
}

void observation_t::msg_obs_dep_b_t::_clean_up() {
    if (m_header) {
        delete m_header; m_header = 0;
    }
    if (m_obs) {
        for (std::vector<packed_obs_content_dep_b_t*>::iterator it = m_obs->begin(); it != m_obs->end(); ++it) {
            delete *it;
        }
        delete m_obs; m_obs = 0;
    }
}

observation_t::packed_obs_content_dep_a_t::packed_obs_content_dep_a_t(kaitai::kstream* p__io, observation_t::msg_obs_dep_a_t* p__parent, observation_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_l = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void observation_t::packed_obs_content_dep_a_t::_read() {
    m_p = m__io->read_u4le();
    m_l = new carrier_phase_dep_a_t(m__io, this, m__root);
    m_cn0 = m__io->read_u1();
    m_lock = m__io->read_u2le();
    m_prn = m__io->read_u1();
}

observation_t::packed_obs_content_dep_a_t::~packed_obs_content_dep_a_t() {
    _clean_up();
}

void observation_t::packed_obs_content_dep_a_t::_clean_up() {
    if (m_l) {
        delete m_l; m_l = 0;
    }
}

observation_t::msg_ephemeris_glo_t::msg_ephemeris_glo_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent, observation_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_common = 0;
    m_pos = 0;
    m_vel = 0;
    m_acc = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void observation_t::msg_ephemeris_glo_t::_read() {
    m_common = new ephemeris_common_content_t(m__io, this, m__root);
    m_gamma = m__io->read_f4le();
    m_tau = m__io->read_f4le();
    m_d_tau = m__io->read_f4le();
    m_pos = new std::vector<double>();
    const int l_pos = 3;
    for (int i = 0; i < l_pos; i++) {
        m_pos->push_back(m__io->read_f8le());
    }
    m_vel = new std::vector<double>();
    const int l_vel = 3;
    for (int i = 0; i < l_vel; i++) {
        m_vel->push_back(m__io->read_f8le());
    }
    m_acc = new std::vector<float>();
    const int l_acc = 3;
    for (int i = 0; i < l_acc; i++) {
        m_acc->push_back(m__io->read_f4le());
    }
    m_fcn = m__io->read_u1();
    m_iod = m__io->read_u1();
}

observation_t::msg_ephemeris_glo_t::~msg_ephemeris_glo_t() {
    _clean_up();
}

void observation_t::msg_ephemeris_glo_t::_clean_up() {
    if (m_common) {
        delete m_common; m_common = 0;
    }
    if (m_pos) {
        delete m_pos; m_pos = 0;
    }
    if (m_vel) {
        delete m_vel; m_vel = 0;
    }
    if (m_acc) {
        delete m_acc; m_acc = 0;
    }
}

observation_t::msg_iono_t::msg_iono_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent, observation_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_t_nmct = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void observation_t::msg_iono_t::_read() {
    m_t_nmct = new gnss_t::gps_time_sec_t(m__io, this, m__root);
    m_a0 = m__io->read_f8le();
    m_a1 = m__io->read_f8le();
    m_a2 = m__io->read_f8le();
    m_a3 = m__io->read_f8le();
    m_b0 = m__io->read_f8le();
    m_b1 = m__io->read_f8le();
    m_b2 = m__io->read_f8le();
    m_b3 = m__io->read_f8le();
}

observation_t::msg_iono_t::~msg_iono_t() {
    _clean_up();
}

void observation_t::msg_iono_t::_clean_up() {
    if (m_t_nmct) {
        delete m_t_nmct; m_t_nmct = 0;
    }
}

observation_t::msg_ephemeris_dep_d_t::msg_ephemeris_dep_d_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent, observation_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_sid = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void observation_t::msg_ephemeris_dep_d_t::_read() {
    m_tgd = m__io->read_f8le();
    m_c_rs = m__io->read_f8le();
    m_c_rc = m__io->read_f8le();
    m_c_uc = m__io->read_f8le();
    m_c_us = m__io->read_f8le();
    m_c_ic = m__io->read_f8le();
    m_c_is = m__io->read_f8le();
    m_dn = m__io->read_f8le();
    m_m0 = m__io->read_f8le();
    m_ecc = m__io->read_f8le();
    m_sqrta = m__io->read_f8le();
    m_omega0 = m__io->read_f8le();
    m_omegadot = m__io->read_f8le();
    m_w = m__io->read_f8le();
    m_inc = m__io->read_f8le();
    m_inc_dot = m__io->read_f8le();
    m_af0 = m__io->read_f8le();
    m_af1 = m__io->read_f8le();
    m_af2 = m__io->read_f8le();
    m_toe_tow = m__io->read_f8le();
    m_toe_wn = m__io->read_u2le();
    m_toc_tow = m__io->read_f8le();
    m_toc_wn = m__io->read_u2le();
    m_valid = m__io->read_u1();
    m_healthy = m__io->read_u1();
    m_sid = new gnss_t::gnss_signal_dep_t(m__io, this, m__root);
    m_iode = m__io->read_u1();
    m_iodc = m__io->read_u2le();
    m_reserved = m__io->read_u4le();
}

observation_t::msg_ephemeris_dep_d_t::~msg_ephemeris_dep_d_t() {
    _clean_up();
}

void observation_t::msg_ephemeris_dep_d_t::_clean_up() {
    if (m_sid) {
        delete m_sid; m_sid = 0;
    }
}

observation_t::msg_ephemeris_gps_t::msg_ephemeris_gps_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent, observation_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_common = 0;
    m_toc = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void observation_t::msg_ephemeris_gps_t::_read() {
    m_common = new ephemeris_common_content_t(m__io, this, m__root);
    m_tgd = m__io->read_f4le();
    m_c_rs = m__io->read_f4le();
    m_c_rc = m__io->read_f4le();
    m_c_uc = m__io->read_f4le();
    m_c_us = m__io->read_f4le();
    m_c_ic = m__io->read_f4le();
    m_c_is = m__io->read_f4le();
    m_dn = m__io->read_f8le();
    m_m0 = m__io->read_f8le();
    m_ecc = m__io->read_f8le();
    m_sqrta = m__io->read_f8le();
    m_omega0 = m__io->read_f8le();
    m_omegadot = m__io->read_f8le();
    m_w = m__io->read_f8le();
    m_inc = m__io->read_f8le();
    m_inc_dot = m__io->read_f8le();
    m_af0 = m__io->read_f4le();
    m_af1 = m__io->read_f4le();
    m_af2 = m__io->read_f4le();
    m_toc = new gnss_t::gps_time_sec_t(m__io, this, m__root);
    m_iode = m__io->read_u1();
    m_iodc = m__io->read_u2le();
}

observation_t::msg_ephemeris_gps_t::~msg_ephemeris_gps_t() {
    _clean_up();
}

void observation_t::msg_ephemeris_gps_t::_clean_up() {
    if (m_common) {
        delete m_common; m_common = 0;
    }
    if (m_toc) {
        delete m_toc; m_toc = 0;
    }
}

observation_t::msg_base_pos_llh_t::msg_base_pos_llh_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent, observation_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void observation_t::msg_base_pos_llh_t::_read() {
    m_lat = m__io->read_f8le();
    m_lon = m__io->read_f8le();
    m_height = m__io->read_f8le();
}

observation_t::msg_base_pos_llh_t::~msg_base_pos_llh_t() {
    _clean_up();
}

void observation_t::msg_base_pos_llh_t::_clean_up() {
}

observation_t::almanac_common_content_t::almanac_common_content_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent, observation_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_sid = 0;
    m_toa = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void observation_t::almanac_common_content_t::_read() {
    m_sid = new gnss_t::gnss_signal_t(m__io, this, m__root);
    m_toa = new gnss_t::gps_time_sec_t(m__io, this, m__root);
    m_ura = m__io->read_f8le();
    m_fit_interval = m__io->read_u4le();
    m_valid = m__io->read_u1();
    m_health_bits = m__io->read_u1();
}

observation_t::almanac_common_content_t::~almanac_common_content_t() {
    _clean_up();
}

void observation_t::almanac_common_content_t::_clean_up() {
    if (m_sid) {
        delete m_sid; m_sid = 0;
    }
    if (m_toa) {
        delete m_toa; m_toa = 0;
    }
}

observation_t::msg_osr_t::msg_osr_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent, observation_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_header = 0;
    m_obs = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void observation_t::msg_osr_t::_read() {
    m_header = new observation_header_t(m__io, this, m__root);
    m_obs = new std::vector<packed_osr_content_t*>();
    {
        int i = 0;
        while (!m__io->is_eof()) {
            m_obs->push_back(new packed_osr_content_t(m__io, this, m__root));
            i++;
        }
    }
}

observation_t::msg_osr_t::~msg_osr_t() {
    _clean_up();
}

void observation_t::msg_osr_t::_clean_up() {
    if (m_header) {
        delete m_header; m_header = 0;
    }
    if (m_obs) {
        for (std::vector<packed_osr_content_t*>::iterator it = m_obs->begin(); it != m_obs->end(); ++it) {
            delete *it;
        }
        delete m_obs; m_obs = 0;
    }
}

observation_t::msg_ephemeris_glo_dep_c_t::msg_ephemeris_glo_dep_c_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent, observation_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_common = 0;
    m_pos = 0;
    m_vel = 0;
    m_acc = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void observation_t::msg_ephemeris_glo_dep_c_t::_read() {
    m_common = new ephemeris_common_content_dep_b_t(m__io, this, m__root);
    m_gamma = m__io->read_f8le();
    m_tau = m__io->read_f8le();
    m_d_tau = m__io->read_f8le();
    m_pos = new std::vector<double>();
    const int l_pos = 3;
    for (int i = 0; i < l_pos; i++) {
        m_pos->push_back(m__io->read_f8le());
    }
    m_vel = new std::vector<double>();
    const int l_vel = 3;
    for (int i = 0; i < l_vel; i++) {
        m_vel->push_back(m__io->read_f8le());
    }
    m_acc = new std::vector<double>();
    const int l_acc = 3;
    for (int i = 0; i < l_acc; i++) {
        m_acc->push_back(m__io->read_f8le());
    }
    m_fcn = m__io->read_u1();
}

observation_t::msg_ephemeris_glo_dep_c_t::~msg_ephemeris_glo_dep_c_t() {
    _clean_up();
}

void observation_t::msg_ephemeris_glo_dep_c_t::_clean_up() {
    if (m_common) {
        delete m_common; m_common = 0;
    }
    if (m_pos) {
        delete m_pos; m_pos = 0;
    }
    if (m_vel) {
        delete m_vel; m_vel = 0;
    }
    if (m_acc) {
        delete m_acc; m_acc = 0;
    }
}

observation_t::msg_ephemeris_glo_dep_b_t::msg_ephemeris_glo_dep_b_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent, observation_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_common = 0;
    m_pos = 0;
    m_vel = 0;
    m_acc = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void observation_t::msg_ephemeris_glo_dep_b_t::_read() {
    m_common = new ephemeris_common_content_dep_b_t(m__io, this, m__root);
    m_gamma = m__io->read_f8le();
    m_tau = m__io->read_f8le();
    m_pos = new std::vector<double>();
    const int l_pos = 3;
    for (int i = 0; i < l_pos; i++) {
        m_pos->push_back(m__io->read_f8le());
    }
    m_vel = new std::vector<double>();
    const int l_vel = 3;
    for (int i = 0; i < l_vel; i++) {
        m_vel->push_back(m__io->read_f8le());
    }
    m_acc = new std::vector<double>();
    const int l_acc = 3;
    for (int i = 0; i < l_acc; i++) {
        m_acc->push_back(m__io->read_f8le());
    }
}

observation_t::msg_ephemeris_glo_dep_b_t::~msg_ephemeris_glo_dep_b_t() {
    _clean_up();
}

void observation_t::msg_ephemeris_glo_dep_b_t::_clean_up() {
    if (m_common) {
        delete m_common; m_common = 0;
    }
    if (m_pos) {
        delete m_pos; m_pos = 0;
    }
    if (m_vel) {
        delete m_vel; m_vel = 0;
    }
    if (m_acc) {
        delete m_acc; m_acc = 0;
    }
}

observation_t::msg_sv_configuration_gps_dep_t::msg_sv_configuration_gps_dep_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent, observation_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_t_nmct = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void observation_t::msg_sv_configuration_gps_dep_t::_read() {
    m_t_nmct = new gnss_t::gps_time_sec_t(m__io, this, m__root);
    m_l2c_mask = m__io->read_u4le();
}

observation_t::msg_sv_configuration_gps_dep_t::~msg_sv_configuration_gps_dep_t() {
    _clean_up();
}

void observation_t::msg_sv_configuration_gps_dep_t::_clean_up() {
    if (m_t_nmct) {
        delete m_t_nmct; m_t_nmct = 0;
    }
}

observation_t::msg_ephemeris_sbas_t::msg_ephemeris_sbas_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent, observation_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_common = 0;
    m_pos = 0;
    m_vel = 0;
    m_acc = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void observation_t::msg_ephemeris_sbas_t::_read() {
    m_common = new ephemeris_common_content_t(m__io, this, m__root);
    m_pos = new std::vector<double>();
    const int l_pos = 3;
    for (int i = 0; i < l_pos; i++) {
        m_pos->push_back(m__io->read_f8le());
    }
    m_vel = new std::vector<float>();
    const int l_vel = 3;
    for (int i = 0; i < l_vel; i++) {
        m_vel->push_back(m__io->read_f4le());
    }
    m_acc = new std::vector<float>();
    const int l_acc = 3;
    for (int i = 0; i < l_acc; i++) {
        m_acc->push_back(m__io->read_f4le());
    }
    m_a_gf0 = m__io->read_f4le();
    m_a_gf1 = m__io->read_f4le();
}

observation_t::msg_ephemeris_sbas_t::~msg_ephemeris_sbas_t() {
    _clean_up();
}

void observation_t::msg_ephemeris_sbas_t::_clean_up() {
    if (m_common) {
        delete m_common; m_common = 0;
    }
    if (m_pos) {
        delete m_pos; m_pos = 0;
    }
    if (m_vel) {
        delete m_vel; m_vel = 0;
    }
    if (m_acc) {
        delete m_acc; m_acc = 0;
    }
}

observation_t::packed_obs_content_dep_b_t::packed_obs_content_dep_b_t(kaitai::kstream* p__io, observation_t::msg_obs_dep_b_t* p__parent, observation_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_l = 0;
    m_sid = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void observation_t::packed_obs_content_dep_b_t::_read() {
    m_p = m__io->read_u4le();
    m_l = new carrier_phase_dep_a_t(m__io, this, m__root);
    m_cn0 = m__io->read_u1();
    m_lock = m__io->read_u2le();
    m_sid = new gnss_t::gnss_signal_dep_t(m__io, this, m__root);
}

observation_t::packed_obs_content_dep_b_t::~packed_obs_content_dep_b_t() {
    _clean_up();
}

void observation_t::packed_obs_content_dep_b_t::_clean_up() {
    if (m_l) {
        delete m_l; m_l = 0;
    }
    if (m_sid) {
        delete m_sid; m_sid = 0;
    }
}

observation_t::msg_obs_dep_c_t::msg_obs_dep_c_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent, observation_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_header = 0;
    m_obs = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void observation_t::msg_obs_dep_c_t::_read() {
    m_header = new observation_header_dep_t(m__io, this, m__root);
    m_obs = new std::vector<packed_obs_content_dep_c_t*>();
    {
        int i = 0;
        while (!m__io->is_eof()) {
            m_obs->push_back(new packed_obs_content_dep_c_t(m__io, this, m__root));
            i++;
        }
    }
}

observation_t::msg_obs_dep_c_t::~msg_obs_dep_c_t() {
    _clean_up();
}

void observation_t::msg_obs_dep_c_t::_clean_up() {
    if (m_header) {
        delete m_header; m_header = 0;
    }
    if (m_obs) {
        for (std::vector<packed_obs_content_dep_c_t*>::iterator it = m_obs->begin(); it != m_obs->end(); ++it) {
            delete *it;
        }
        delete m_obs; m_obs = 0;
    }
}

observation_t::msg_ephemeris_dep_a_t::msg_ephemeris_dep_a_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent, observation_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void observation_t::msg_ephemeris_dep_a_t::_read() {
    m_tgd = m__io->read_f8le();
    m_c_rs = m__io->read_f8le();
    m_c_rc = m__io->read_f8le();
    m_c_uc = m__io->read_f8le();
    m_c_us = m__io->read_f8le();
    m_c_ic = m__io->read_f8le();
    m_c_is = m__io->read_f8le();
    m_dn = m__io->read_f8le();
    m_m0 = m__io->read_f8le();
    m_ecc = m__io->read_f8le();
    m_sqrta = m__io->read_f8le();
    m_omega0 = m__io->read_f8le();
    m_omegadot = m__io->read_f8le();
    m_w = m__io->read_f8le();
    m_inc = m__io->read_f8le();
    m_inc_dot = m__io->read_f8le();
    m_af0 = m__io->read_f8le();
    m_af1 = m__io->read_f8le();
    m_af2 = m__io->read_f8le();
    m_toe_tow = m__io->read_f8le();
    m_toe_wn = m__io->read_u2le();
    m_toc_tow = m__io->read_f8le();
    m_toc_wn = m__io->read_u2le();
    m_valid = m__io->read_u1();
    m_healthy = m__io->read_u1();
    m_prn = m__io->read_u1();
}

observation_t::msg_ephemeris_dep_a_t::~msg_ephemeris_dep_a_t() {
    _clean_up();
}

void observation_t::msg_ephemeris_dep_a_t::_clean_up() {
}

observation_t::ephemeris_common_content_dep_b_t::ephemeris_common_content_dep_b_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent, observation_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_sid = 0;
    m_toe = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void observation_t::ephemeris_common_content_dep_b_t::_read() {
    m_sid = new gnss_t::gnss_signal_t(m__io, this, m__root);
    m_toe = new gnss_t::gps_time_sec_t(m__io, this, m__root);
    m_ura = m__io->read_f8le();
    m_fit_interval = m__io->read_u4le();
    m_valid = m__io->read_u1();
    m_health_bits = m__io->read_u1();
}

observation_t::ephemeris_common_content_dep_b_t::~ephemeris_common_content_dep_b_t() {
    _clean_up();
}

void observation_t::ephemeris_common_content_dep_b_t::_clean_up() {
    if (m_sid) {
        delete m_sid; m_sid = 0;
    }
    if (m_toe) {
        delete m_toe; m_toe = 0;
    }
}
